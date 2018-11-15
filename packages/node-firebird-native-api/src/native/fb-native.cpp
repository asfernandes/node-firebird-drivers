#include <map>
#include <string>
#include <nan.h>
#include "./classes.h"
#include "./cloop-gen.h"

#ifdef _WIN32
#include <windows.h>
#undef interface
#else
#include <dlfcn.h>
#endif

using std::map;
using std::string;

#ifdef _WIN32
typedef HMODULE Handle;
#else
typedef void* Handle;
#endif

//----------------------------------------------------------------------------


static void getMaster(const Nan::FunctionCallbackInfo<v8::Value>& info);
static void disposeMaster(const Nan::FunctionCallbackInfo<v8::Value>& info);
static void initAll(v8::Local<v8::Object> exports, v8::Local<v8::Object> module);


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


static void getMaster(const Nan::FunctionCallbackInfo<v8::Value>& info)
{
	typedef fb::IMaster* (*Func)();

	const char* const MASTER_FUNCTION = "fb_get_master_interface";
	Nan::Utf8String str(info[0]->ToString());
	fb::IMaster* master = nullptr;
	string errorMessage;

#ifdef _WIN32
	HMODULE handle = LoadLibrary(*str);
	printf("--> str: %s\n", *str); fflush(stdout);
	printf("--> handle: %p\n", (void*) handle); fflush(stdout);

	if (handle)
	{
		Func func = (Func) GetProcAddress(handle, MASTER_FUNCTION);
		printf("--> func: %p\n", (void*) func); fflush(stdout);

		if (func)
		{
			master = func();
			printf("--> master: %p\n", (void*) master); fflush(stdout);
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
		errorMessage = string("Cannot load Firebird client library: '") + *str + "'.";
#else
	void* handle = dlopen(*str, RTLD_NOW);

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
		errorMessage = string("Cannot load Firebird client library: '") + *str + "'.";
#endif

	printf("--> errorMessage: %s\n", errorMessage.c_str()); fflush(stdout);
	if (!errorMessage.empty())
	{
		Nan::ThrowError(errorMessage.c_str());
		return;
	}

	assert(master);

	v8::Local<v8::Object> instance = Master::NewInstance(master);

	Master* obj = Nan::ObjectWrap::Unwrap<Master>(instance);
	masterHandles[obj] = handle;

	auto handleCounter = handleCounters.find(handle);

	if (handleCounter != handleCounters.end())
		++handleCounter->second;
	else
		handleCounters[handle] = 1;

	info.GetReturnValue().Set(instance);
	printf("--> getMaster end\n"); fflush(stdout);
}


static void disposeMaster(const Nan::FunctionCallbackInfo<v8::Value>& info)
{
	auto* master = Master::CheckedUnwrap(info[0], "master argument", false);
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
		info.GetReturnValue().Set(true);
	}
	else
		info.GetReturnValue().Set(false);
}


static void initAll(v8::Local<v8::Object> exports, v8::Local<v8::Object> module)
{
	Nan::HandleScope scope;

	initClasses(exports, module);

	Nan::SetMethod(exports, "getMaster", getMaster);
	Nan::SetMethod(exports, "disposeMaster", disposeMaster);

	Pointer::Init(exports, "Pointer");
}

NODE_MODULE(addon, initAll)
