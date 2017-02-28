#ifndef NODE_FB_CLASSES_H
#define NODE_FB_CLASSES_H

#include <string>
#include <nan.h>
#include <firebird/Interface.h>

namespace fb = Firebird;


std::string formatStatus(fb::IStatus* status);


class NodeThrow
{
};


template <typename T>
using MethodStart = std::function<T ()>;


template <typename T>
class PromiseWorker: public Nan::AsyncWorker
{
protected:
	PromiseWorker(const std::function<T ()>& executeLambda,
			const std::function<v8::Local<v8::Value> (T)>& returnLambda)
		: AsyncWorker(nullptr),
		  executeLambda(executeLambda),
		  returnLambda(returnLambda)
	{
	}

public:
	static void Run(const Nan::FunctionCallbackInfo<v8::Value>& info,
		const std::function<T ()>& executeLambda,
		const std::function<v8::Local<v8::Value> (T)> returnLambda)
	{
		Nan::EscapableHandleScope scope;

		auto resolver = v8::Promise::Resolver::New(info.GetIsolate());
		auto worker = new PromiseWorker(executeLambda, returnLambda);

		worker->SaveToPersistent("resolver", resolver);
		Nan::AsyncQueueWorker(worker);

		info.GetReturnValue().Set(scope.Escape(resolver->GetPromise()));
	}

public:
	void Execute() override
	{
		try
		{
			ret = executeLambda();
		}
		catch (const fb::FbException& e)
		{
			error = true;
			errorMsg = formatStatus(e.getStatus());
		}
	}

	void HandleOKCallback() override
	{
		auto res = GetFromPersistent("resolver").template As<v8::Promise::Resolver>();

		if (!error)
			res->Resolve(returnLambda(ret));
		else
			res->Reject(Nan::Error(errorMsg.c_str()));

		v8::Isolate::GetCurrent()->RunMicrotasks();
	}

private:
	T ret = 0;
	std::function<T ()> executeLambda;
	std::function<v8::Local<v8::Value> (T)> returnLambda;
	bool error = false;
	std::string errorMsg;
};


template <typename This, typename Interface>
class BaseClass : public Nan::ObjectWrap
{
public:
	static void Init(v8::Local<v8::Object> exports, const char* name)
	{
		Nan::HandleScope scope;

		className() = name;

		// Prepare constructor template
		v8::Local<v8::String> nameObj = Nan::New(name).ToLocalChecked();
		v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
		tpl->SetClassName(nameObj);
		tpl->InstanceTemplate()->SetInternalFieldCount(1);

		// Prototype
		This::InitPrototype(tpl);

		constructor().Reset(tpl);

		exports->Set(nameObj, tpl->GetFunction());
	}

	static v8::Local<v8::Object> NewInstance(Interface* interface)
	{
		Nan::EscapableHandleScope scope;

		v8::Local<v8::FunctionTemplate> cons = Nan::New<v8::FunctionTemplate>(constructor());
		v8::Local<v8::Object> instance = Nan::NewInstance(Nan::GetFunction(cons).ToLocalChecked()).ToLocalChecked();

		This* obj = ObjectWrap::Unwrap<This>(instance);
		obj->interface = interface;

		return scope.Escape(instance);
	}

	static bool HasInstance(const v8::Local<v8::Value>& object)
	{
		return Nan::New(constructor())->HasInstance(object);
	}

	static This* CheckedUnwrap(v8::Local<v8::Value> object, const char* description,
		bool allowNull = false)
	{
		if (allowNull && (object->IsNull() || object->IsUndefined()))
			return nullptr;

		bool err = object->IsNull() || !object->IsObject();

		if (!err)
		{
			if (Nan::Get(object->ToObject(), Nan::New("cloop").ToLocalChecked()).ToLocal(&object))
				err = !object->IsObject();
			else
				err = true;
		}

		err = err || !Nan::New(constructor())->HasInstance(object);

		if (err)
		{
			std::string msg = std::string(description) + " must be an instance of " +
				className() + " class" + (allowNull ? " or null" : "") + ".";
			Nan::ThrowTypeError(msg.c_str());
			throw NodeThrow();
		}

		return ObjectWrap::Unwrap<This>(object->ToObject());
	}

protected:
	static std::string& className()
	{
		static std::string var;
		return var;
	}

	static Nan::Persistent<v8::FunctionTemplate>& constructor()
	{
		static Nan::Persistent<v8::FunctionTemplate> var;
		return var;
	}

	template <void (*ptr)(Nan::NAN_METHOD_ARGS_TYPE)>
	static void DefineSyncMethod(v8::Local<v8::FunctionTemplate>& tpl, const char* name)
	{
		void (*wrapper)(Nan::NAN_METHOD_ARGS_TYPE) = [](Nan::NAN_METHOD_ARGS_TYPE info) {
			try
			{
				ptr(info);
			}
			catch (const fb::FbException& e)
			{
				Nan::ThrowError(formatStatus(e.getStatus()).c_str());
			}
			catch (const NodeThrow&)
			{
			}
		};

		SetPrototypeMethod(tpl, name, wrapper);
	}

	template <
		typename T,
		MethodStart<T> (*ptr1)(Nan::NAN_METHOD_ARGS_TYPE),
		v8::Local<v8::Value> (*ptr2)(T)
	>
	static void DefineAsyncMethod(v8::Local<v8::FunctionTemplate>& tpl, const char* name)
	{
		void (*syncWrapper)(Nan::NAN_METHOD_ARGS_TYPE) = [](Nan::NAN_METHOD_ARGS_TYPE info) {
			try
			{
				auto ret = ptr1(info)();
				info.GetReturnValue().Set(ptr2(ret));
			}
			catch (const fb::FbException& e)
			{
				Nan::ThrowError(formatStatus(e.getStatus()).c_str());
			}
			catch (const NodeThrow&)
			{
			}
		};

		SetPrototypeMethod(tpl, (std::string(name) + "Sync").c_str(), syncWrapper);

		void (*asyncWrapper)(Nan::NAN_METHOD_ARGS_TYPE) = [](Nan::NAN_METHOD_ARGS_TYPE info) {
			try
			{
				auto ret = ptr1(info);
				PromiseWorker<T>::Run(info, ret, ptr2);
			}
			catch (const fb::FbException& e)
			{
				Nan::ThrowError(formatStatus(e.getStatus()).c_str());
			}
			catch (const NodeThrow&)
			{
			}
		};

		SetPrototypeMethod(tpl, (std::string(name) + "Async").c_str(), asyncWrapper);
	}

private:
	static NAN_METHOD(New)
	{
		This* obj = new This();
		obj->Wrap(info.This());

		Nan::Set(info.This(), Nan::New("cloop").ToLocalChecked(), info.This());

		info.GetReturnValue().Set(info.This());
	}

public:
	Interface* interface = nullptr;
};


template <typename This, template<typename...> typename T>
class BaseImpl : public T<This, fb::ThrowStatusWrapper>
{
public:
	BaseImpl(v8::Local<v8::Object> localObject)
		: persistentObject(localObject)
	{
	}

protected:
	Nan::Persistent<v8::Object> persistentObject;
};


class Pointer : public BaseClass<Pointer, void>
{
friend class BaseClass;

public:
	static v8::Local<v8::Object> NewInstance(const void* ptr)
	{
		return Pointer::BaseClass::NewInstance(const_cast<void*>(ptr));
	}

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
	{
	}
};


template <typename T>
T* getAddress(v8::Local<v8::Value> from)
{
	T* address = *Nan::TypedArrayContents<T>(from);

	if (!address)
	{
		auto* pointer = Pointer::CheckedUnwrap(from, "pointer argument", true);

		if (pointer)
			address = static_cast<T*>(const_cast<void*>(pointer->interface));
	}

	return address;
}


#endif	// NODE_FB_CLASSES_H
