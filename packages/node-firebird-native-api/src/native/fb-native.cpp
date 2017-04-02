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
	Nan::Utf8String str(info[0]->ToString());

#ifdef _WIN32
	HMODULE handle = LoadLibrary(*str);
	if (!handle)
		return;

	typedef fb::IMaster* (*Func)();
	Func func = (Func) GetProcAddress(handle, "fb_get_master_interface");

	if (!func)
	{
		FreeLibrary(handle);
		return;
	}

	fb::IMaster* master = func();
	if (!master)
	{
		FreeLibrary(handle);
		return;
	}
#else
	void* handle = dlopen(*str, RTLD_NOW);
	if (!handle)
		return;

	typedef fb::IMaster* (*Func)();
	Func func = (Func) dlsym(handle, "fb_get_master_interface");

	if (!func)
	{
		dlclose(handle);
		return;
	}

	fb::IMaster* master = func();
	if (!master)
	{
		dlclose(handle);
		return;
	}
#endif

	v8::Local<v8::Object> instance = Master::NewInstance(master);

	Master* obj = Nan::ObjectWrap::Unwrap<Master>(instance);
	masterHandles[obj] = handle;

	info.GetReturnValue().Set(instance);
}


static void disposeMaster(const Nan::FunctionCallbackInfo<v8::Value>& info)
{
	auto* master = Master::CheckedUnwrap(info[0], "master argument", false);
	auto i = masterHandles.find(master);

	if (i != masterHandles.end())
	{
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
