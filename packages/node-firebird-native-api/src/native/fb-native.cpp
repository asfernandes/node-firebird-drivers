#include <atomic>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>
#include <napi.h>

#include "./classes.h"
#include "./cloop-gen.h"

#ifdef _WIN32
#include <windows.h>
#undef interface
#else
#include <dlfcn.h>
#endif

using std::atomic;
using std::function;
using std::lock_guard;
using std::mutex;
using std::string;
using std::unique_ptr;
using std::unordered_map;
using std::vector;

#ifdef _WIN32
typedef HMODULE Handle;
#else
typedef void* Handle;
#endif


//----------------------------------------------------------------------------


static Napi::Value getMaster(const Napi::CallbackInfo& info);
static Napi::Boolean disposeMaster(const Napi::CallbackInfo& info);
static Napi::Object initAll(Napi::Env env, Napi::Object exports);


//----------------------------------------------------------------------------


static unordered_map<Master*, Handle> masterHandles;
static unordered_map<Handle, unsigned> handleCounters;


//----------------------------------------------------------------------------


string formatStatus(fb::IStatus* status)
{
	// Ugly hack. We get a random client, not necessarily the client that created the status object.

	auto i = masterHandles.begin();

	if (i == masterHandles.end())
	{
		assert(false);
		return "Cannot format Firebird error. No client is loaded.";
	}

	char buffer[2048];
	string str(buffer, i->first->interface->getUtilInterface()->formatStatus(buffer, sizeof(buffer), status));

	return buffer;
}


void rethrowException(const Napi::Env env)
{
	try
	{
		throw;
	}
	catch (const fb::FbException& e)
	{
		throw Napi::Error::New(env, formatStatus(e.getStatus()).c_str());
	}
	catch (...)
	{
		throw;
	}

	assert(false);
}


static Napi::Value getMaster(const Napi::CallbackInfo& info)
{
	typedef fb::IMaster* (*Func)();

	const char* const MASTER_FUNCTION = "fb_get_master_interface";
	auto str = info[0].ToString().Utf8Value();
	fb::IMaster* master = nullptr;
	string errorMessage;

#ifdef _WIN32
	HMODULE handle = LoadLibrary(str.c_str());

	if (handle)
	{
		Func func = (Func) GetProcAddress(handle, MASTER_FUNCTION);

		if (func)
		{
			master = func();
			if (!master)
			{
				FreeLibrary(handle);
				errorMessage = "Cannot get Firebird client's master interface.";
			}
		}
		else
		{
			FreeLibrary(handle);
			errorMessage = string("Cannot find Firebird client's master function: '") + MASTER_FUNCTION + "'.";
		}
	}
	else
		errorMessage = string("Cannot load Firebird client library: '") + str + "'.";
#else
	void* handle = dlopen(str.c_str(), RTLD_NOW);

	if (handle)
	{
		Func func = (Func) dlsym(handle, MASTER_FUNCTION);

		if (func)
		{
			master = func();
			if (!master)
			{
				dlclose(handle);
				errorMessage = "Cannot get Firebird client's master interface.";
			}
		}
		else
		{
			dlclose(handle);
			errorMessage = string("Cannot find Firebird client's master function: '") + MASTER_FUNCTION + "'.";
		}
	}
	else
	{
		const char* errorMsg = dlerror();

		errorMessage = string("Cannot load Firebird client library: '") + str + "'.";

		if (errorMsg)
			errorMessage += string("\n- ") + errorMsg;
	}
#endif

	if (!errorMessage.empty())
		throw Napi::Error::New(info.Env(), errorMessage.c_str());

	assert(master);

	Napi::Object instance = Master::NewInstance(info.Env(), master);

	Master* obj = Napi::ObjectWrap<Master>::Unwrap(instance);
	masterHandles[obj] = handle;

	auto handleCounter = handleCounters.find(handle);

	if (handleCounter != handleCounters.end())
		++handleCounter->second;
	else
		handleCounters[handle] = 1;

	return instance;
}


static Napi::Boolean disposeMaster(const Napi::CallbackInfo& info)
{
	auto* master = Master::CheckedUnwrap(info.Env(), info[0], "master argument", false);
	auto i = masterHandles.find(master);

	if (i != masterHandles.end())
	{
		auto handleCounter = handleCounters.find(i->second);

		if (handleCounter == handleCounters.end())
			assert(false);
		else
		{
			if (--handleCounter->second == 0)
			{
				auto* status = master->interface->getStatus();
				try
				{
					fb::ThrowStatusWrapper statusWrapper(status);
					auto* dispatcher = master->interface->getDispatcher();
					dispatcher->shutdown(&statusWrapper, 0, fb_shutrsn_app_stopped);
				}
				catch (...)
				{
				}

				status->dispose();
			}
		}

#ifdef _WIN32
		FreeLibrary(i->second);
#else
		dlclose(i->second);
#endif

		masterHandles.erase(i);
		return Napi::Boolean::New(info.Env(), true);
	}
	else
		return Napi::Boolean::New(info.Env(), false);
}


//----------------------------------------------------------------------------


namespace
{
	class EventCallbackImpl : public fb::IEventCallbackImpl<EventCallbackImpl, fb::ThrowStatusWrapper>
	{
	public:
		EventCallbackImpl(Napi::Env env, fb::IMaster* master, fb::IAttachment* attachment,
				Napi::Function& callBack)
			: master(master),
			  attachment(attachment)
		{
			napi_status napiStatus = napi_create_threadsafe_function(env, callBack, Napi::Object(),
				Napi::Value::From(env, ""), 0, 1,
				nullptr, nullptr, nullptr, callJs, &ntsf);
			NAPI_THROW_IF_FAILED(env, napiStatus, napi_create_threadsafe_function);
		}

	public:
		void queue(const vector<string>& names)
		{
			vector<uint8_t> epb{1};

			for (const auto& name : names)
			{
				epb.push_back(name.length());
				epb.insert(epb.end(), (const uint8_t*) name.c_str(), (const uint8_t*) name.c_str() + name.length());
				epb.insert(epb.end(), {1, 0, 0, 0});

				map[name] = 1;
			}

			lock_guard<mutex> lockGuard(mtx);

			auto* status = master->getStatus();
			try
			{
				fb::ThrowStatusWrapper statusWrapper(status);
				events = attachment->queEvents(&statusWrapper, this, epb.size(), &epb[0]);
			}
			catch (...)
			{
				status->dispose();
				throw;
			}
			status->dispose();
		}

		void cancel()
		{
			lock_guard<mutex> lockGuard(mtx);

			if (events)
			{
				auto* status = master->getStatus();
				try
				{
					fb::ThrowStatusWrapper statusWrapper(status);
					auto eventsCancelling = events;
					events = nullptr;
					eventsCancelling->cancel(&statusWrapper);
				}
				catch (...)
				{
					status->dispose();
					throw;
				}
				status->dispose();
			}
		}

		void destroy(Napi::Env env)
		{
			auto napiStatus = napi_unref_threadsafe_function(env, ntsf);
			NAPI_THROW_IF_FAILED(env, napiStatus, napi_unref_threadsafe_function);

			release();
		}

	public:
		void addRef() override
		{
			++refCounter;
		}

		int release() override
		{
			assert(refCounter > 0);

			if (--refCounter == 0)
			{
				delete this;
				return 0;
			}
			else
				return 1;
		}

		void eventCallbackFunction(unsigned int length, const ISC_UCHAR* data) override
		{
			assert(refCounter > 0);

			if (!data || length == 0)
				return;

			lock_guard<mutex> lockGuard(mtx);

			if (events)
			{
				auto* status = master->getStatus();
				try
				{
					fb::ThrowStatusWrapper statusWrapper(status);
					events->cancel(&statusWrapper);
					events = nullptr;
					events = attachment->queEvents(&statusWrapper, this, length, data);
				}
				catch (...)
				{
					status->dispose();
					throw;
				}
				status->dispose();

				addRef();
				resultBuffer.clear();
				resultBuffer.insert(resultBuffer.end(), data, data + length);

				auto wrapper = [this](Napi::Env env, Napi::Function jsCallback) {
					handler(env, jsCallback, this);
				};
				auto callbackWrapper = new CallbackWrapper(wrapper);

				auto napiStatus = napi_call_threadsafe_function(ntsf, callbackWrapper, napi_tsfn_blocking);

				if (napiStatus != napi_ok)
				{
					delete callbackWrapper;
					release();
				}
			}
		}

	private:
		using CallbackWrapper = function<void(Napi::Env, Napi::Function)>;

		static void callJs(napi_env env, napi_value jsCallback, void* /*context*/, void* data)
		{
			if (!env && !jsCallback)
				return;

			if (data)
			{
				auto* callbackWrapper = static_cast<CallbackWrapper*>(data);
				(*callbackWrapper)(env, Napi::Function(env, jsCallback));
				delete callbackWrapper;
			}
			else if (jsCallback)
				Napi::Function(env, jsCallback).Call({});
		}

		static void handler(Napi::Env env, Napi::Function jsFunc, EventCallbackImpl* self)
		{
			try
			{
				Napi::HandleScope scope(env);

				auto counters = Napi::Array::New(env);

				{   // scope
					lock_guard<mutex> lockGuard(self->mtx);
					auto index = 0u;

					auto i = self->resultBuffer.cbegin();

					// version
					assert(self->resultBuffer.size() > 0);
					assert(*i == 1);

					++i;

					while (i < self->resultBuffer.end())
					{
						const auto nameLen = *i++;
						const auto name = string((const char*) &i[0], (const char*) &i[nameLen]);
						i += nameLen;
						const auto count = i[0] | (i[1] << 8) | (i[2] << 16) | (i[3] << 24);
						i += 4;

						auto item = Napi::Array::New(env, 2);
						item[0u] = Napi::String::New(env, name.c_str());
						item[1u] = Napi::Number::New(env, count - self->map[name]);
						counters[index++] = item;

						self->map[name] = count;
					}
				}

				jsFunc.Call({counters});
			}
			catch (...)
			{
				self->release();
				throw;
			}

			self->release();
		}

	private:
		fb::IMaster* master;
		fb::IAttachment* attachment;
		fb::IEvents* events = nullptr;
		atomic<int> refCounter{1};
		mutex mtx;
		unordered_map<string, unsigned> map;
		napi_threadsafe_function ntsf;
		vector<ISC_UCHAR> resultBuffer;
	};
}	// namespace


static MethodStart<fb::IEventCallback*> queueEventStart(bool /*async*/, const Napi::CallbackInfo& info)
{
	auto* master = Master::CheckedUnwrap(info.Env(), info[0], "master argument", false);
	auto* attachment = Attachment::CheckedUnwrap(info.Env(), info[1], "attachment argument", false);
	auto names = info[2].As<Napi::Array>();
	auto callBack = info[3].As<Napi::Function>();

	vector<string> namesVector;

	auto namesLen = names.Length();
	for (unsigned i = 0; i < namesLen; ++i)
	{
		Napi::Value name = names[i];
		namesVector.push_back(name.As<Napi::String>().Utf8Value());
	}

	auto* eventCallback = new EventCallbackImpl(info.Env(), master->interface, attachment->interface, callBack);

	return [eventCallback, namesVector]() {
		auto eventCallbackPtr = unique_ptr<EventCallbackImpl>(eventCallback);
		eventCallbackPtr->queue(namesVector);
		return eventCallbackPtr.release();
	};
}

static Napi::Value queueEventFinish(const Napi::Env env, fb::IEventCallback* ret)
{
	return EventCallback::NewInstance(env, ret);
}

static Napi::Value queueEvent(const Napi::CallbackInfo& info)
{
	return PromiseWorker<fb::IEventCallback*>::Run(info.Env(),
		queueEventStart(true, info),
		queueEventFinish);
}


static MethodStart<EventCallbackImpl*> cancelEventStart(bool /*async*/, const Napi::CallbackInfo& info)
{
	auto* eventCallback = EventCallback::CheckedUnwrap(info.Env(), info[0], "eventCallback argument", false);

	return [eventCallback]() {
		auto eventCallbackImpl = static_cast<EventCallbackImpl*>(eventCallback->interface);
		eventCallbackImpl->cancel();
		return eventCallbackImpl;
	};
}

static Napi::Value cancelEventFinish(const Napi::Env env, EventCallbackImpl* ret)
{
	ret->destroy(env);
	return env.Undefined();
}

static Napi::Value cancelEvent(const Napi::CallbackInfo& info)
{
	return PromiseWorker<EventCallbackImpl*>::Run(info.Env(),
		cancelEventStart(true, info),
		cancelEventFinish);
}

//----------------------------------------------------------------------------


static Napi::Object initAll(Napi::Env env, Napi::Object exports)
{
	exports.Set(Napi::String::New(env, "getMaster"), Napi::Function::New(env, getMaster));

	Napi::HandleScope scope(env);

	initClasses(env, exports);

	Napi::Function getMasterFunction = Napi::Function::New(env, getMaster, "getMaster");
	exports.Set("getMaster", getMasterFunction);

	Napi::Function disposeMasterFunction = Napi::Function::New(env, disposeMaster, "disposeMaster");
	exports.Set("disposeMaster", disposeMasterFunction);

	Napi::Function queueEventFunction = Napi::Function::New(env, queueEvent, "queueEvent");
	exports.Set("queueEvent", queueEventFunction);

	Napi::Function cancelEventFunction = Napi::Function::New(env, cancelEvent, "cancelEvent");
	exports.Set("cancelEvent", cancelEventFunction);

	Pointer::Init(env, exports, "Pointer");

	return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, initAll)
