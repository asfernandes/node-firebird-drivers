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


namespace Napi
{
	// Customize N-API AsyncWorker as the original API is very ugly and
	// with slower unused things.
	class CustomAsyncWorker
	{
	protected:
		explicit CustomAsyncWorker(Env env);
		explicit CustomAsyncWorker(Env env, const char* resource_name);

	public:
		// An async worker can be moved but cannot be copied.
		CustomAsyncWorker(const CustomAsyncWorker&) = delete;
		CustomAsyncWorker& operator=(CustomAsyncWorker&) = delete;

		CustomAsyncWorker(CustomAsyncWorker&& other);
		CustomAsyncWorker& operator=(CustomAsyncWorker&& other);

		virtual ~CustomAsyncWorker();

		operator napi_async_work() const
		{
			return _work;
		}

		void Queue();
		void Cancel();

	protected:
		virtual void Execute() = 0;
		virtual void OnOK(Env env) = 0;
		virtual void OnError(Env env, const Error& e) = 0;

		void SetError(const std::string& error);

	private:
		static void OnExecute(napi_env env, void* this_pointer);
		static void OnWorkComplete(napi_env env, napi_status status, void* this_pointer);

		napi_env _env;
		napi_async_work _work;
		std::string _error;
	};

	inline CustomAsyncWorker::CustomAsyncWorker(Env env)
		: CustomAsyncWorker(env, "generic")
	{
	}

	inline CustomAsyncWorker::CustomAsyncWorker(Env env, const char* resource_name)
		: _env(env)
	{
		napi_value resource_id;
		napi_status status = napi_create_string_latin1(
			_env, resource_name, NAPI_AUTO_LENGTH, &resource_id);
		NAPI_THROW_IF_FAILED_VOID(_env, status);

		status = napi_create_async_work(_env, nullptr, resource_id,
			OnExecute, OnWorkComplete, this, &_work);
		NAPI_THROW_IF_FAILED_VOID(_env, status);
	}

	inline CustomAsyncWorker::CustomAsyncWorker(CustomAsyncWorker&& other)
	{
		_env = other._env;
		other._env = nullptr;
		_work = other._work;
		other._work = nullptr;
		_error = std::move(other._error);
	}

	inline CustomAsyncWorker& CustomAsyncWorker::operator=(CustomAsyncWorker&& other)
	{
		_env = other._env;
		other._env = nullptr;
		_work = other._work;
		other._work = nullptr;
		_error = std::move(other._error);
		return *this;
	}

	inline CustomAsyncWorker::~CustomAsyncWorker()
	{
		if (_work != nullptr)
		{
			napi_delete_async_work(_env, _work);
			_work = nullptr;
		}
	}

	inline void CustomAsyncWorker::Queue()
	{
		napi_status status = napi_queue_async_work(_env, _work);
		NAPI_THROW_IF_FAILED_VOID(_env, status);
	}

	inline void CustomAsyncWorker::Cancel()
	{
		napi_status status = napi_cancel_async_work(_env, _work);
		NAPI_THROW_IF_FAILED_VOID(_env, status);
	}

	inline void CustomAsyncWorker::SetError(const std::string& error)
	{
		_error = error;
	}

	inline void CustomAsyncWorker::OnExecute(napi_env /*env*/, void* this_pointer)
	{
		CustomAsyncWorker* self = static_cast<CustomAsyncWorker*>(this_pointer);
#ifdef NAPI_CPP_EXCEPTIONS
		try
		{
			self->Execute();
		}
		catch (const std::exception& e)
		{
			self->SetError(e.what());
		}
#else  // NAPI_CPP_EXCEPTIONS
		self->Execute();
#endif // NAPI_CPP_EXCEPTIONS
	}

	inline void CustomAsyncWorker::OnWorkComplete(
		napi_env env, napi_status status, void* this_pointer)
	{
		CustomAsyncWorker* self = static_cast<CustomAsyncWorker*>(this_pointer);

		if (status != napi_cancelled)
		{
			HandleScope scope(self->_env);

			details::WrapCallback([&] {
				if (self->_error.size() == 0)
					self->OnOK(env);
				else
					self->OnError(env, Error::New(self->_env, self->_error));

				return nullptr;
			});
		}

		delete self;
	}
}


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
class PromiseWorker : public Napi::CustomAsyncWorker
{
protected:
	PromiseWorker(const Napi::Env env,
			MethodStart<T> executeLambda,
			std::function<Napi::Value (const Napi::Env, T)> returnLambda)
		: CustomAsyncWorker(env),
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

	void OnOK(Napi::Env env) override
	{
		if (!error)
			deferred.Resolve(returnLambda(env, ret));
		else
			deferred.Reject(Napi::Error::New(env, errorMsg.c_str()).Value());
	}

	void OnError(Napi::Env env, const Napi::Error& e) override
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


template <typename This, typename Interface>
class BaseClass : public Napi::ObjectWrap<This>
{
public:
	BaseClass(const Napi::CallbackInfo& callbackInfo)
		: Napi::ObjectWrap<This>(callbackInfo)
	{
	}

public:
	static void Init(Napi::Env env, Napi::Object& exports, const char* name)
	{
		Napi::HandleScope scope(env);

		className() = name;

		// Prototype
		std::vector<typename Napi::ObjectWrap<This>::PropertyDescriptor> properties;
		This::InitPrototype(properties);

		Napi::Function function = Napi::ObjectWrap<This>::DefineClass(env, name, properties);

		constructor().Reset(function);
		constructor().SuppressDestruct();

		exports.Set(name, function);
	}

	static Napi::Object NewInstance(const Napi::Env env, Interface* interface)
	{
		Napi::EscapableHandleScope scope(env);

		auto instance = constructor().Value().New({});

		This* obj = Napi::ObjectWrap<This>::Unwrap(instance);
		obj->interface = interface;

		return scope.Escape(instance).ToObject();
	}

	static This* CheckedUnwrap(const Napi::Env env, const Napi::Value& value, const char* description,
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

		return Napi::ObjectWrap<This>::Unwrap(object);
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


template <typename This, template<typename...> class T>
class BaseImpl : public T<This, fb::ThrowStatusWrapper>
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
