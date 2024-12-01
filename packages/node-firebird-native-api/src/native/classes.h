#ifndef NODE_FB_CLASSES_H
#define NODE_FB_CLASSES_H

#include <functional>
#include <string>
#include <vector>
#include "./include/firebird/Interface.h"

#ifdef _WIN32
#undef interface
#endif


//----------------------------------------------------------------------------


namespace fb = Firebird;


std::string formatStatus(fb::IStatus* status);

[[noreturn]]
void rethrowException(const Napi::Env env);


class OptString
{
public:
	OptString(const char* s)
		: null(s == nullptr)
	{
		if (s)
			str = s;
	}

public:
	bool isNull() const
	{
		return null;
	}

	const std::string& string() const
	{
		return str;
	}

private:
	std::string str;
	bool null;
};


template <typename T>
using MethodStart = std::function<T ()>;


template <typename T>
class PromiseWorker : public Napi::AsyncWorker
{
protected:
	PromiseWorker(const Napi::Env env,
			MethodStart<T> executeLambda,
			std::function<Napi::Value (const Napi::Env, T)> returnLambda)
		: AsyncWorker(env),
		  executeLambda(executeLambda),
		  returnLambda(returnLambda),
		  deferred(env)
	{
	}

public:
	static Napi::Value Run(const Napi::Env env,
		MethodStart<T> executeLambda,
		std::function<Napi::Value (const Napi::Env, T)> returnLambda)
	{
		Napi::HandleScope scope(env);

		auto worker = new PromiseWorker(env, executeLambda, returnLambda);
		worker->Queue();

		return worker->deferred.Promise();
	}

protected:
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

	void OnOK() override
	{
		if (!error)
			deferred.Resolve(returnLambda(Env(), ret));
		else
			deferred.Reject(Napi::Error::New(Env(), errorMsg.c_str()).Value());
	}

	void OnError(const Napi::Error& e) override
	{
		assert(false);
	}

private:
	T ret = 0;
	MethodStart<T> executeLambda;
	std::function<Napi::Value (const Napi::Env, T)> returnLambda;
	bool error = false;
	std::string errorMsg;
	Napi::Promise::Deferred deferred;
};


template <typename ThisType, typename Interface>
class BaseClass : public Napi::ObjectWrap<ThisType>
{
public:
	using Napi::ObjectWrap<ThisType>::ObjectWrap;

public:
	static void Init(Napi::Env env, Napi::Object& exports, const char* name)
	{
		Napi::HandleScope scope(env);

		className() = name;

		// Prototype
		std::vector<typename Napi::ObjectWrap<ThisType>::PropertyDescriptor> properties;
		ThisType::InitPrototype(properties);

		Napi::Function function = Napi::ObjectWrap<ThisType>::DefineClass(env, name, properties);

		constructor().Reset(function);
		constructor().SuppressDestruct();

		exports.Set(name, function);
	}

	static Napi::Object NewInstance(const Napi::Env env, Interface* interface)
	{
		Napi::EscapableHandleScope scope(env);

		auto instance = constructor().Value().New({});

		ThisType* obj = Napi::ObjectWrap<ThisType>::Unwrap(instance);
		obj->interface = interface;

		return scope.Escape(instance).ToObject();
	}

	static ThisType* CheckedUnwrap(const Napi::Env env, const Napi::Value& value, const char* description,
		bool allowNull = false)
	{
		const auto type = value.Type();

		if (allowNull && (type == napi_null || type == napi_undefined))
			return nullptr;

		bool err = type == napi_null ||
			!(type == napi_object || type == napi_function);	// !IsObject()

		auto object = value.ToObject();

		err = err || !object.InstanceOf(constructor().Value());

		if (err)
		{
			std::string msg = std::string(description) + " must be an instance of " +
				className() + " class" + (allowNull ? " or null" : "") + ".";
			throw Napi::Error::New(env, msg);
		}

		return Napi::ObjectWrap<ThisType>::Unwrap(object);
	}

protected:
	static std::string& className()
	{
		static std::string var;
		return var;
	}

	static Napi::Reference<Napi::Function>& constructor()
	{
		static Napi::Reference<Napi::Function> var;
		return var;
	}

public:
	Interface* interface = nullptr;
};


template <typename ThisType, template<typename...> class T>
class BaseImpl : public T<ThisType, fb::ThrowStatusWrapper>
{
};


class Pointer : public BaseClass<Pointer, void>
{
friend class BaseClass<Pointer, void>;

public:
	using BaseClass::BaseClass;

public:
	static Napi::Object NewInstance(const Napi::Env env, const void* ptr)
	{
		return Pointer::BaseClass::NewInstance(env, const_cast<void*>(ptr));
	}

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Pointer>::PropertyDescriptor>& properties)
	{
	}
};


template <typename T>
T* getAddress(const Napi::Env env, bool async, const Napi::Value& from,
	std::shared_ptr<Napi::Reference<Napi::Value>>& persistent)
{
	const auto type = from.Type();

	if (type == napi_null || type == napi_undefined)
		return nullptr;

	T* address = nullptr;

	if (from.IsTypedArray())
	{
		address = Napi::TypedArrayOf<T>(env, from).Data();

		// Node v13 returns nullptr for empty TypedArray, but we need an address.
		if (!address)
		{
			static double DUMMY = 0;
			address = reinterpret_cast<T*>(&DUMMY);
		}
	}

	if (address)
	{
		if (async)
			persistent = std::make_shared<Napi::Reference<Napi::Value>>(Napi::Persistent(from));
	}
	else
	{
		auto* pointer = Pointer::CheckedUnwrap(env, from, "pointer argument", true);

		if (pointer)
			address = static_cast<T*>(const_cast<void*>(pointer->interface));
	}

	return address;
}


#endif	// NODE_FB_CLASSES_H
