#include <atomic>
#include <map>
#include <memory>
#include <string>
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
using std::map;
using std::string;
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


static map<Master*, Handle> masterHandles;
static map<Handle, unsigned> handleCounters;


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
		errorMessage = string("Cannot load Firebird client library: '") + str + "'.";
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
	class EventWorker : public Napi::CustomAsyncWorker
	{
	public:
		EventWorker(const Napi::Env env, Napi::Function& callBack)
			: CustomAsyncWorker(env)
		{
			callBackRef.Reset(callBack);
		}

	protected:
		void Execute() override
		{
		}

		void OnOK(Napi::Env env) override
		{
			Napi::HandleScope scope(env);

			auto buffer = Napi::ArrayBuffer::New(env, data.size());
			memcpy(buffer.Data(), &data[0], data.size());
			callBackRef.Call({buffer});
		}

		void OnError(Napi::Env env, const Napi::Error& e) override
		{
		}

	public:
		vector<ISC_UCHAR> data;

	private:
		Napi::FunctionReference callBackRef;
	};

	class EventCallBackImpl : public fb::IEventCallbackImpl<EventCallBackImpl, fb::ThrowStatusWrapper>
	{
	public:
		EventCallBackImpl(Napi::Env env, Napi::Function& callBack)
			: refCounter(0),
			  worker(new EventWorker(env, callBack))
		{
		}

	private:
		~EventCallBackImpl()
		{
		}

	public:
		virtual void addRef()
		{
			++refCounter;
		}

		virtual int release()
		{
			if (--refCounter == 0)
			{
				delete this;
				return 0;
			}
			else
				return 1;
		}

	public:
		void eventCallbackFunction(unsigned int length, const ISC_UCHAR* data)
		{
			auto scheduledWorker = worker.release();
			scheduledWorker->data.clear();
			scheduledWorker->data.insert(scheduledWorker->data.end(), data, data + length);
			scheduledWorker->Queue();
		}

	private:
		atomic<int> refCounter;
		std::unique_ptr<EventWorker> worker;
	};
}

static Napi::Value newEventCallback(const Napi::CallbackInfo& info)
{
	auto callBack = info[0].As<Napi::Function>();

	auto* eventCallback = new EventCallBackImpl(info.Env(), callBack);
	return EventCallback::NewInstance(info.Env(), eventCallback);
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

	Napi::Function newEventCallbackFunction = Napi::Function::New(env, newEventCallback, "newEventCallback");
	exports.Set("newEventCallback", newEventCallbackFunction);

	Pointer::Init(env, exports, "Pointer");

	return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, initAll)
