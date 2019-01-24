// Auto-generated file. Do not edit!

class Versioned : public BaseClass<Versioned, fb::IVersioned>
{
friend class BaseClass<Versioned, fb::IVersioned>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Versioned>::PropertyDescriptor>& properties);

private:
};


class ReferenceCounted : public BaseClass<ReferenceCounted, fb::IReferenceCounted>
{
friend class BaseClass<ReferenceCounted, fb::IReferenceCounted>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<ReferenceCounted>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&ReferenceCounted::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&ReferenceCounted::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Disposable : public BaseClass<Disposable, fb::IDisposable>
{
friend class BaseClass<Disposable, fb::IDisposable>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Disposable>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> disposeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value disposeFinish(const Napi::Env env, void* ret);

	Napi::Value disposeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			disposeStart(true, info),
			&Disposable::disposeFinish);
	}

	Napi::Value disposeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = disposeStart(false, info)();
			return disposeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Status : public BaseClass<Status, fb::IStatus>
{
friend class BaseClass<Status, fb::IStatus>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Status>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> disposeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value disposeFinish(const Napi::Env env, void* ret);

	Napi::Value disposeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			disposeStart(true, info),
			&Status::disposeFinish);
	}

	Napi::Value disposeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = disposeStart(false, info)();
			return disposeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> initStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value initFinish(const Napi::Env env, void* ret);

	Napi::Value initAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			initStart(true, info),
			&Status::initFinish);
	}

	Napi::Value initSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = initStart(false, info)();
			return initFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned> getStateStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getStateFinish(const Napi::Env env, unsigned ret);

	Napi::Value getStateAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getStateStart(true, info),
			&Status::getStateFinish);
	}

	Napi::Value getStateSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getStateStart(false, info)();
			return getStateFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IStatus*> cloneStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value cloneFinish(const Napi::Env env, fb::IStatus* ret);

	Napi::Value cloneAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IStatus*>::Run(info.Env(),
			cloneStart(true, info),
			&Status::cloneFinish);
	}

	Napi::Value cloneSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = cloneStart(false, info)();
			return cloneFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Master : public BaseClass<Master, fb::IMaster>
{
friend class BaseClass<Master, fb::IMaster>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Master>::PropertyDescriptor>& properties);

private:
	static MethodStart<fb::IStatus*> getStatusStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getStatusFinish(const Napi::Env env, fb::IStatus* ret);

	Napi::Value getStatusAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IStatus*>::Run(info.Env(),
			getStatusStart(true, info),
			&Master::getStatusFinish);
	}

	Napi::Value getStatusSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getStatusStart(false, info)();
			return getStatusFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IProvider*> getDispatcherStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getDispatcherFinish(const Napi::Env env, fb::IProvider* ret);

	Napi::Value getDispatcherAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IProvider*>::Run(info.Env(),
			getDispatcherStart(true, info),
			&Master::getDispatcherFinish);
	}

	Napi::Value getDispatcherSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getDispatcherStart(false, info)();
			return getDispatcherFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IPluginManager*> getPluginManagerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getPluginManagerFinish(const Napi::Env env, fb::IPluginManager* ret);

	Napi::Value getPluginManagerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IPluginManager*>::Run(info.Env(),
			getPluginManagerStart(true, info),
			&Master::getPluginManagerFinish);
	}

	Napi::Value getPluginManagerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getPluginManagerStart(false, info)();
			return getPluginManagerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ITimerControl*> getTimerControlStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getTimerControlFinish(const Napi::Env env, fb::ITimerControl* ret);

	Napi::Value getTimerControlAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ITimerControl*>::Run(info.Env(),
			getTimerControlStart(true, info),
			&Master::getTimerControlFinish);
	}

	Napi::Value getTimerControlSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getTimerControlStart(false, info)();
			return getTimerControlFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IDtc*> getDtcStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getDtcFinish(const Napi::Env env, fb::IDtc* ret);

	Napi::Value getDtcAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IDtc*>::Run(info.Env(),
			getDtcStart(true, info),
			&Master::getDtcFinish);
	}

	Napi::Value getDtcSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getDtcStart(false, info)();
			return getDtcFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IAttachment*> registerAttachmentStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value registerAttachmentFinish(const Napi::Env env, fb::IAttachment* ret);

	Napi::Value registerAttachmentAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IAttachment*>::Run(info.Env(),
			registerAttachmentStart(true, info),
			&Master::registerAttachmentFinish);
	}

	Napi::Value registerAttachmentSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = registerAttachmentStart(false, info)();
			return registerAttachmentFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ITransaction*> registerTransactionStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value registerTransactionFinish(const Napi::Env env, fb::ITransaction* ret);

	Napi::Value registerTransactionAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ITransaction*>::Run(info.Env(),
			registerTransactionStart(true, info),
			&Master::registerTransactionFinish);
	}

	Napi::Value registerTransactionSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = registerTransactionStart(false, info)();
			return registerTransactionFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IMetadataBuilder*> getMetadataBuilderStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getMetadataBuilderFinish(const Napi::Env env, fb::IMetadataBuilder* ret);

	Napi::Value getMetadataBuilderAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IMetadataBuilder*>::Run(info.Env(),
			getMetadataBuilderStart(true, info),
			&Master::getMetadataBuilderFinish);
	}

	Napi::Value getMetadataBuilderSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getMetadataBuilderStart(false, info)();
			return getMetadataBuilderFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> serverModeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value serverModeFinish(const Napi::Env env, int ret);

	Napi::Value serverModeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			serverModeStart(true, info),
			&Master::serverModeFinish);
	}

	Napi::Value serverModeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = serverModeStart(false, info)();
			return serverModeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IUtil*> getUtilInterfaceStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getUtilInterfaceFinish(const Napi::Env env, fb::IUtil* ret);

	Napi::Value getUtilInterfaceAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IUtil*>::Run(info.Env(),
			getUtilInterfaceStart(true, info),
			&Master::getUtilInterfaceFinish);
	}

	Napi::Value getUtilInterfaceSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getUtilInterfaceStart(false, info)();
			return getUtilInterfaceFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IConfigManager*> getConfigManagerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getConfigManagerFinish(const Napi::Env env, fb::IConfigManager* ret);

	Napi::Value getConfigManagerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IConfigManager*>::Run(info.Env(),
			getConfigManagerStart(true, info),
			&Master::getConfigManagerFinish);
	}

	Napi::Value getConfigManagerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getConfigManagerStart(false, info)();
			return getConfigManagerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<FB_BOOLEAN> getProcessExitingStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getProcessExitingFinish(const Napi::Env env, FB_BOOLEAN ret);

	Napi::Value getProcessExitingAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<FB_BOOLEAN>::Run(info.Env(),
			getProcessExitingStart(true, info),
			&Master::getProcessExitingFinish);
	}

	Napi::Value getProcessExitingSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getProcessExitingStart(false, info)();
			return getProcessExitingFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class PluginBase : public BaseClass<PluginBase, fb::IPluginBase>
{
friend class BaseClass<PluginBase, fb::IPluginBase>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<PluginBase>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&PluginBase::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&PluginBase::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setOwnerFinish(const Napi::Env env, void* ret);

	Napi::Value setOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setOwnerStart(true, info),
			&PluginBase::setOwnerFinish);
	}

	Napi::Value setOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setOwnerStart(false, info)();
			return setOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IReferenceCounted*> getOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret);

	Napi::Value getOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IReferenceCounted*>::Run(info.Env(),
			getOwnerStart(true, info),
			&PluginBase::getOwnerFinish);
	}

	Napi::Value getOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getOwnerStart(false, info)();
			return getOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class PluginSet : public BaseClass<PluginSet, fb::IPluginSet>
{
friend class BaseClass<PluginSet, fb::IPluginSet>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<PluginSet>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&PluginSet::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&PluginSet::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getNameFinish(const Napi::Env env, std::string ret);

	Napi::Value getNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getNameStart(true, info),
			&PluginSet::getNameFinish);
	}

	Napi::Value getNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getNameStart(false, info)();
			return getNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getModuleNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getModuleNameFinish(const Napi::Env env, std::string ret);

	Napi::Value getModuleNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getModuleNameStart(true, info),
			&PluginSet::getModuleNameFinish);
	}

	Napi::Value getModuleNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getModuleNameStart(false, info)();
			return getModuleNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IPluginBase*> getPluginStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getPluginFinish(const Napi::Env env, fb::IPluginBase* ret);

	Napi::Value getPluginAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IPluginBase*>::Run(info.Env(),
			getPluginStart(true, info),
			&PluginSet::getPluginFinish);
	}

	Napi::Value getPluginSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getPluginStart(false, info)();
			return getPluginFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> nextStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value nextFinish(const Napi::Env env, void* ret);

	Napi::Value nextAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			nextStart(true, info),
			&PluginSet::nextFinish);
	}

	Napi::Value nextSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = nextStart(false, info)();
			return nextFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setFinish(const Napi::Env env, void* ret);

	Napi::Value setAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setStart(true, info),
			&PluginSet::setFinish);
	}

	Napi::Value setSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setStart(false, info)();
			return setFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class ConfigEntry : public BaseClass<ConfigEntry, fb::IConfigEntry>
{
friend class BaseClass<ConfigEntry, fb::IConfigEntry>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<ConfigEntry>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&ConfigEntry::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&ConfigEntry::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getNameFinish(const Napi::Env env, std::string ret);

	Napi::Value getNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getNameStart(true, info),
			&ConfigEntry::getNameFinish);
	}

	Napi::Value getNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getNameStart(false, info)();
			return getNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getValueStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getValueFinish(const Napi::Env env, std::string ret);

	Napi::Value getValueAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getValueStart(true, info),
			&ConfigEntry::getValueFinish);
	}

	Napi::Value getValueSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getValueStart(false, info)();
			return getValueFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int64_t> getIntValueStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getIntValueFinish(const Napi::Env env, int64_t ret);

	Napi::Value getIntValueAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int64_t>::Run(info.Env(),
			getIntValueStart(true, info),
			&ConfigEntry::getIntValueFinish);
	}

	Napi::Value getIntValueSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getIntValueStart(false, info)();
			return getIntValueFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<FB_BOOLEAN> getBoolValueStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getBoolValueFinish(const Napi::Env env, FB_BOOLEAN ret);

	Napi::Value getBoolValueAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<FB_BOOLEAN>::Run(info.Env(),
			getBoolValueStart(true, info),
			&ConfigEntry::getBoolValueFinish);
	}

	Napi::Value getBoolValueSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getBoolValueStart(false, info)();
			return getBoolValueFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IConfig*> getSubConfigStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getSubConfigFinish(const Napi::Env env, fb::IConfig* ret);

	Napi::Value getSubConfigAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IConfig*>::Run(info.Env(),
			getSubConfigStart(true, info),
			&ConfigEntry::getSubConfigFinish);
	}

	Napi::Value getSubConfigSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getSubConfigStart(false, info)();
			return getSubConfigFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Config : public BaseClass<Config, fb::IConfig>
{
friend class BaseClass<Config, fb::IConfig>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Config>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&Config::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&Config::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IConfigEntry*> findStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value findFinish(const Napi::Env env, fb::IConfigEntry* ret);

	Napi::Value findAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IConfigEntry*>::Run(info.Env(),
			findStart(true, info),
			&Config::findFinish);
	}

	Napi::Value findSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = findStart(false, info)();
			return findFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IConfigEntry*> findValueStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value findValueFinish(const Napi::Env env, fb::IConfigEntry* ret);

	Napi::Value findValueAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IConfigEntry*>::Run(info.Env(),
			findValueStart(true, info),
			&Config::findValueFinish);
	}

	Napi::Value findValueSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = findValueStart(false, info)();
			return findValueFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IConfigEntry*> findPosStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value findPosFinish(const Napi::Env env, fb::IConfigEntry* ret);

	Napi::Value findPosAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IConfigEntry*>::Run(info.Env(),
			findPosStart(true, info),
			&Config::findPosFinish);
	}

	Napi::Value findPosSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = findPosStart(false, info)();
			return findPosFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class FirebirdConf : public BaseClass<FirebirdConf, fb::IFirebirdConf>
{
friend class BaseClass<FirebirdConf, fb::IFirebirdConf>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<FirebirdConf>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&FirebirdConf::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&FirebirdConf::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned> getKeyStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getKeyFinish(const Napi::Env env, unsigned ret);

	Napi::Value getKeyAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getKeyStart(true, info),
			&FirebirdConf::getKeyFinish);
	}

	Napi::Value getKeySync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getKeyStart(false, info)();
			return getKeyFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int64_t> asIntegerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value asIntegerFinish(const Napi::Env env, int64_t ret);

	Napi::Value asIntegerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int64_t>::Run(info.Env(),
			asIntegerStart(true, info),
			&FirebirdConf::asIntegerFinish);
	}

	Napi::Value asIntegerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = asIntegerStart(false, info)();
			return asIntegerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> asStringStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value asStringFinish(const Napi::Env env, std::string ret);

	Napi::Value asStringAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			asStringStart(true, info),
			&FirebirdConf::asStringFinish);
	}

	Napi::Value asStringSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = asStringStart(false, info)();
			return asStringFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<FB_BOOLEAN> asBooleanStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value asBooleanFinish(const Napi::Env env, FB_BOOLEAN ret);

	Napi::Value asBooleanAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<FB_BOOLEAN>::Run(info.Env(),
			asBooleanStart(true, info),
			&FirebirdConf::asBooleanFinish);
	}

	Napi::Value asBooleanSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = asBooleanStart(false, info)();
			return asBooleanFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class PluginConfig : public BaseClass<PluginConfig, fb::IPluginConfig>
{
friend class BaseClass<PluginConfig, fb::IPluginConfig>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<PluginConfig>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&PluginConfig::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&PluginConfig::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getConfigFileNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getConfigFileNameFinish(const Napi::Env env, std::string ret);

	Napi::Value getConfigFileNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getConfigFileNameStart(true, info),
			&PluginConfig::getConfigFileNameFinish);
	}

	Napi::Value getConfigFileNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getConfigFileNameStart(false, info)();
			return getConfigFileNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IConfig*> getDefaultConfigStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getDefaultConfigFinish(const Napi::Env env, fb::IConfig* ret);

	Napi::Value getDefaultConfigAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IConfig*>::Run(info.Env(),
			getDefaultConfigStart(true, info),
			&PluginConfig::getDefaultConfigFinish);
	}

	Napi::Value getDefaultConfigSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getDefaultConfigStart(false, info)();
			return getDefaultConfigFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IFirebirdConf*> getFirebirdConfStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getFirebirdConfFinish(const Napi::Env env, fb::IFirebirdConf* ret);

	Napi::Value getFirebirdConfAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IFirebirdConf*>::Run(info.Env(),
			getFirebirdConfStart(true, info),
			&PluginConfig::getFirebirdConfFinish);
	}

	Napi::Value getFirebirdConfSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getFirebirdConfStart(false, info)();
			return getFirebirdConfFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setReleaseDelayStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setReleaseDelayFinish(const Napi::Env env, void* ret);

	Napi::Value setReleaseDelayAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setReleaseDelayStart(true, info),
			&PluginConfig::setReleaseDelayFinish);
	}

	Napi::Value setReleaseDelaySync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setReleaseDelayStart(false, info)();
			return setReleaseDelayFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class PluginFactory : public BaseClass<PluginFactory, fb::IPluginFactory>
{
friend class BaseClass<PluginFactory, fb::IPluginFactory>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<PluginFactory>::PropertyDescriptor>& properties);

private:
	static MethodStart<fb::IPluginBase*> createPluginStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value createPluginFinish(const Napi::Env env, fb::IPluginBase* ret);

	Napi::Value createPluginAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IPluginBase*>::Run(info.Env(),
			createPluginStart(true, info),
			&PluginFactory::createPluginFinish);
	}

	Napi::Value createPluginSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = createPluginStart(false, info)();
			return createPluginFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class PluginModule : public BaseClass<PluginModule, fb::IPluginModule>
{
friend class BaseClass<PluginModule, fb::IPluginModule>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<PluginModule>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> doCleanStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value doCleanFinish(const Napi::Env env, void* ret);

	Napi::Value doCleanAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			doCleanStart(true, info),
			&PluginModule::doCleanFinish);
	}

	Napi::Value doCleanSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = doCleanStart(false, info)();
			return doCleanFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class PluginManager : public BaseClass<PluginManager, fb::IPluginManager>
{
friend class BaseClass<PluginManager, fb::IPluginManager>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<PluginManager>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> registerPluginFactoryStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value registerPluginFactoryFinish(const Napi::Env env, void* ret);

	Napi::Value registerPluginFactoryAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			registerPluginFactoryStart(true, info),
			&PluginManager::registerPluginFactoryFinish);
	}

	Napi::Value registerPluginFactorySync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = registerPluginFactoryStart(false, info)();
			return registerPluginFactoryFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> registerModuleStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value registerModuleFinish(const Napi::Env env, void* ret);

	Napi::Value registerModuleAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			registerModuleStart(true, info),
			&PluginManager::registerModuleFinish);
	}

	Napi::Value registerModuleSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = registerModuleStart(false, info)();
			return registerModuleFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> unregisterModuleStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value unregisterModuleFinish(const Napi::Env env, void* ret);

	Napi::Value unregisterModuleAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			unregisterModuleStart(true, info),
			&PluginManager::unregisterModuleFinish);
	}

	Napi::Value unregisterModuleSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = unregisterModuleStart(false, info)();
			return unregisterModuleFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IPluginSet*> getPluginsStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getPluginsFinish(const Napi::Env env, fb::IPluginSet* ret);

	Napi::Value getPluginsAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IPluginSet*>::Run(info.Env(),
			getPluginsStart(true, info),
			&PluginManager::getPluginsFinish);
	}

	Napi::Value getPluginsSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getPluginsStart(false, info)();
			return getPluginsFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IConfig*> getConfigStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getConfigFinish(const Napi::Env env, fb::IConfig* ret);

	Napi::Value getConfigAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IConfig*>::Run(info.Env(),
			getConfigStart(true, info),
			&PluginManager::getConfigFinish);
	}

	Napi::Value getConfigSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getConfigStart(false, info)();
			return getConfigFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> releasePluginStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releasePluginFinish(const Napi::Env env, void* ret);

	Napi::Value releasePluginAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			releasePluginStart(true, info),
			&PluginManager::releasePluginFinish);
	}

	Napi::Value releasePluginSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releasePluginStart(false, info)();
			return releasePluginFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class CryptKey : public BaseClass<CryptKey, fb::ICryptKey>
{
friend class BaseClass<CryptKey, fb::ICryptKey>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<CryptKey>::PropertyDescriptor>& properties);

private:
};


class ConfigManager : public BaseClass<ConfigManager, fb::IConfigManager>
{
friend class BaseClass<ConfigManager, fb::IConfigManager>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<ConfigManager>::PropertyDescriptor>& properties);

private:
	static MethodStart<std::string> getDirectoryStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getDirectoryFinish(const Napi::Env env, std::string ret);

	Napi::Value getDirectoryAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getDirectoryStart(true, info),
			&ConfigManager::getDirectoryFinish);
	}

	Napi::Value getDirectorySync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getDirectoryStart(false, info)();
			return getDirectoryFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IFirebirdConf*> getFirebirdConfStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getFirebirdConfFinish(const Napi::Env env, fb::IFirebirdConf* ret);

	Napi::Value getFirebirdConfAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IFirebirdConf*>::Run(info.Env(),
			getFirebirdConfStart(true, info),
			&ConfigManager::getFirebirdConfFinish);
	}

	Napi::Value getFirebirdConfSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getFirebirdConfStart(false, info)();
			return getFirebirdConfFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IFirebirdConf*> getDatabaseConfStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getDatabaseConfFinish(const Napi::Env env, fb::IFirebirdConf* ret);

	Napi::Value getDatabaseConfAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IFirebirdConf*>::Run(info.Env(),
			getDatabaseConfStart(true, info),
			&ConfigManager::getDatabaseConfFinish);
	}

	Napi::Value getDatabaseConfSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getDatabaseConfStart(false, info)();
			return getDatabaseConfFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IConfig*> getPluginConfigStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getPluginConfigFinish(const Napi::Env env, fb::IConfig* ret);

	Napi::Value getPluginConfigAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IConfig*>::Run(info.Env(),
			getPluginConfigStart(true, info),
			&ConfigManager::getPluginConfigFinish);
	}

	Napi::Value getPluginConfigSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getPluginConfigStart(false, info)();
			return getPluginConfigFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getInstallDirectoryStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getInstallDirectoryFinish(const Napi::Env env, std::string ret);

	Napi::Value getInstallDirectoryAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getInstallDirectoryStart(true, info),
			&ConfigManager::getInstallDirectoryFinish);
	}

	Napi::Value getInstallDirectorySync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getInstallDirectoryStart(false, info)();
			return getInstallDirectoryFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getRootDirectoryStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getRootDirectoryFinish(const Napi::Env env, std::string ret);

	Napi::Value getRootDirectoryAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getRootDirectoryStart(true, info),
			&ConfigManager::getRootDirectoryFinish);
	}

	Napi::Value getRootDirectorySync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getRootDirectoryStart(false, info)();
			return getRootDirectoryFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class EventCallback : public BaseClass<EventCallback, fb::IEventCallback>
{
friend class BaseClass<EventCallback, fb::IEventCallback>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<EventCallback>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&EventCallback::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&EventCallback::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> eventCallbackFunctionStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value eventCallbackFunctionFinish(const Napi::Env env, void* ret);

	Napi::Value eventCallbackFunctionAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			eventCallbackFunctionStart(true, info),
			&EventCallback::eventCallbackFunctionFinish);
	}

	Napi::Value eventCallbackFunctionSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = eventCallbackFunctionStart(false, info)();
			return eventCallbackFunctionFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Blob : public BaseClass<Blob, fb::IBlob>
{
friend class BaseClass<Blob, fb::IBlob>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Blob>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&Blob::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&Blob::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> getInfoStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getInfoFinish(const Napi::Env env, void* ret);

	Napi::Value getInfoAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			getInfoStart(true, info),
			&Blob::getInfoFinish);
	}

	Napi::Value getInfoSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getInfoStart(false, info)();
			return getInfoFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> getSegmentStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getSegmentFinish(const Napi::Env env, int ret);

	Napi::Value getSegmentAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			getSegmentStart(true, info),
			&Blob::getSegmentFinish);
	}

	Napi::Value getSegmentSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getSegmentStart(false, info)();
			return getSegmentFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> putSegmentStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value putSegmentFinish(const Napi::Env env, void* ret);

	Napi::Value putSegmentAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			putSegmentStart(true, info),
			&Blob::putSegmentFinish);
	}

	Napi::Value putSegmentSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = putSegmentStart(false, info)();
			return putSegmentFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> cancelStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value cancelFinish(const Napi::Env env, void* ret);

	Napi::Value cancelAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			cancelStart(true, info),
			&Blob::cancelFinish);
	}

	Napi::Value cancelSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = cancelStart(false, info)();
			return cancelFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> closeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value closeFinish(const Napi::Env env, void* ret);

	Napi::Value closeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			closeStart(true, info),
			&Blob::closeFinish);
	}

	Napi::Value closeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = closeStart(false, info)();
			return closeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> seekStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value seekFinish(const Napi::Env env, int ret);

	Napi::Value seekAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			seekStart(true, info),
			&Blob::seekFinish);
	}

	Napi::Value seekSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = seekStart(false, info)();
			return seekFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Transaction : public BaseClass<Transaction, fb::ITransaction>
{
friend class BaseClass<Transaction, fb::ITransaction>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Transaction>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&Transaction::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&Transaction::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> getInfoStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getInfoFinish(const Napi::Env env, void* ret);

	Napi::Value getInfoAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			getInfoStart(true, info),
			&Transaction::getInfoFinish);
	}

	Napi::Value getInfoSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getInfoStart(false, info)();
			return getInfoFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> prepareStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value prepareFinish(const Napi::Env env, void* ret);

	Napi::Value prepareAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			prepareStart(true, info),
			&Transaction::prepareFinish);
	}

	Napi::Value prepareSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = prepareStart(false, info)();
			return prepareFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> commitStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value commitFinish(const Napi::Env env, void* ret);

	Napi::Value commitAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			commitStart(true, info),
			&Transaction::commitFinish);
	}

	Napi::Value commitSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = commitStart(false, info)();
			return commitFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> commitRetainingStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value commitRetainingFinish(const Napi::Env env, void* ret);

	Napi::Value commitRetainingAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			commitRetainingStart(true, info),
			&Transaction::commitRetainingFinish);
	}

	Napi::Value commitRetainingSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = commitRetainingStart(false, info)();
			return commitRetainingFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> rollbackStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value rollbackFinish(const Napi::Env env, void* ret);

	Napi::Value rollbackAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			rollbackStart(true, info),
			&Transaction::rollbackFinish);
	}

	Napi::Value rollbackSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = rollbackStart(false, info)();
			return rollbackFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> rollbackRetainingStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value rollbackRetainingFinish(const Napi::Env env, void* ret);

	Napi::Value rollbackRetainingAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			rollbackRetainingStart(true, info),
			&Transaction::rollbackRetainingFinish);
	}

	Napi::Value rollbackRetainingSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = rollbackRetainingStart(false, info)();
			return rollbackRetainingFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> disconnectStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value disconnectFinish(const Napi::Env env, void* ret);

	Napi::Value disconnectAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			disconnectStart(true, info),
			&Transaction::disconnectFinish);
	}

	Napi::Value disconnectSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = disconnectStart(false, info)();
			return disconnectFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ITransaction*> joinStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value joinFinish(const Napi::Env env, fb::ITransaction* ret);

	Napi::Value joinAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ITransaction*>::Run(info.Env(),
			joinStart(true, info),
			&Transaction::joinFinish);
	}

	Napi::Value joinSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = joinStart(false, info)();
			return joinFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ITransaction*> validateStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value validateFinish(const Napi::Env env, fb::ITransaction* ret);

	Napi::Value validateAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ITransaction*>::Run(info.Env(),
			validateStart(true, info),
			&Transaction::validateFinish);
	}

	Napi::Value validateSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = validateStart(false, info)();
			return validateFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ITransaction*> enterDtcStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value enterDtcFinish(const Napi::Env env, fb::ITransaction* ret);

	Napi::Value enterDtcAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ITransaction*>::Run(info.Env(),
			enterDtcStart(true, info),
			&Transaction::enterDtcFinish);
	}

	Napi::Value enterDtcSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = enterDtcStart(false, info)();
			return enterDtcFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class MessageMetadata : public BaseClass<MessageMetadata, fb::IMessageMetadata>
{
friend class BaseClass<MessageMetadata, fb::IMessageMetadata>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<MessageMetadata>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&MessageMetadata::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&MessageMetadata::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned> getCountStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getCountFinish(const Napi::Env env, unsigned ret);

	Napi::Value getCountAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getCountStart(true, info),
			&MessageMetadata::getCountFinish);
	}

	Napi::Value getCountSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getCountStart(false, info)();
			return getCountFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getFieldStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getFieldFinish(const Napi::Env env, std::string ret);

	Napi::Value getFieldAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getFieldStart(true, info),
			&MessageMetadata::getFieldFinish);
	}

	Napi::Value getFieldSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getFieldStart(false, info)();
			return getFieldFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getRelationStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getRelationFinish(const Napi::Env env, std::string ret);

	Napi::Value getRelationAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getRelationStart(true, info),
			&MessageMetadata::getRelationFinish);
	}

	Napi::Value getRelationSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getRelationStart(false, info)();
			return getRelationFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getOwnerFinish(const Napi::Env env, std::string ret);

	Napi::Value getOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getOwnerStart(true, info),
			&MessageMetadata::getOwnerFinish);
	}

	Napi::Value getOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getOwnerStart(false, info)();
			return getOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getAliasStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getAliasFinish(const Napi::Env env, std::string ret);

	Napi::Value getAliasAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getAliasStart(true, info),
			&MessageMetadata::getAliasFinish);
	}

	Napi::Value getAliasSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getAliasStart(false, info)();
			return getAliasFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned> getTypeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getTypeFinish(const Napi::Env env, unsigned ret);

	Napi::Value getTypeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getTypeStart(true, info),
			&MessageMetadata::getTypeFinish);
	}

	Napi::Value getTypeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getTypeStart(false, info)();
			return getTypeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<FB_BOOLEAN> isNullableStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value isNullableFinish(const Napi::Env env, FB_BOOLEAN ret);

	Napi::Value isNullableAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<FB_BOOLEAN>::Run(info.Env(),
			isNullableStart(true, info),
			&MessageMetadata::isNullableFinish);
	}

	Napi::Value isNullableSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = isNullableStart(false, info)();
			return isNullableFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> getSubTypeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getSubTypeFinish(const Napi::Env env, int ret);

	Napi::Value getSubTypeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			getSubTypeStart(true, info),
			&MessageMetadata::getSubTypeFinish);
	}

	Napi::Value getSubTypeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getSubTypeStart(false, info)();
			return getSubTypeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned> getLengthStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getLengthFinish(const Napi::Env env, unsigned ret);

	Napi::Value getLengthAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getLengthStart(true, info),
			&MessageMetadata::getLengthFinish);
	}

	Napi::Value getLengthSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getLengthStart(false, info)();
			return getLengthFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> getScaleStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getScaleFinish(const Napi::Env env, int ret);

	Napi::Value getScaleAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			getScaleStart(true, info),
			&MessageMetadata::getScaleFinish);
	}

	Napi::Value getScaleSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getScaleStart(false, info)();
			return getScaleFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned> getCharSetStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getCharSetFinish(const Napi::Env env, unsigned ret);

	Napi::Value getCharSetAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getCharSetStart(true, info),
			&MessageMetadata::getCharSetFinish);
	}

	Napi::Value getCharSetSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getCharSetStart(false, info)();
			return getCharSetFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned> getOffsetStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getOffsetFinish(const Napi::Env env, unsigned ret);

	Napi::Value getOffsetAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getOffsetStart(true, info),
			&MessageMetadata::getOffsetFinish);
	}

	Napi::Value getOffsetSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getOffsetStart(false, info)();
			return getOffsetFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned> getNullOffsetStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getNullOffsetFinish(const Napi::Env env, unsigned ret);

	Napi::Value getNullOffsetAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getNullOffsetStart(true, info),
			&MessageMetadata::getNullOffsetFinish);
	}

	Napi::Value getNullOffsetSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getNullOffsetStart(false, info)();
			return getNullOffsetFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IMetadataBuilder*> getBuilderStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getBuilderFinish(const Napi::Env env, fb::IMetadataBuilder* ret);

	Napi::Value getBuilderAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IMetadataBuilder*>::Run(info.Env(),
			getBuilderStart(true, info),
			&MessageMetadata::getBuilderFinish);
	}

	Napi::Value getBuilderSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getBuilderStart(false, info)();
			return getBuilderFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned> getMessageLengthStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getMessageLengthFinish(const Napi::Env env, unsigned ret);

	Napi::Value getMessageLengthAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getMessageLengthStart(true, info),
			&MessageMetadata::getMessageLengthFinish);
	}

	Napi::Value getMessageLengthSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getMessageLengthStart(false, info)();
			return getMessageLengthFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class MetadataBuilder : public BaseClass<MetadataBuilder, fb::IMetadataBuilder>
{
friend class BaseClass<MetadataBuilder, fb::IMetadataBuilder>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<MetadataBuilder>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&MetadataBuilder::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&MetadataBuilder::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setTypeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setTypeFinish(const Napi::Env env, void* ret);

	Napi::Value setTypeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setTypeStart(true, info),
			&MetadataBuilder::setTypeFinish);
	}

	Napi::Value setTypeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setTypeStart(false, info)();
			return setTypeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setSubTypeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setSubTypeFinish(const Napi::Env env, void* ret);

	Napi::Value setSubTypeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setSubTypeStart(true, info),
			&MetadataBuilder::setSubTypeFinish);
	}

	Napi::Value setSubTypeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setSubTypeStart(false, info)();
			return setSubTypeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setLengthStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setLengthFinish(const Napi::Env env, void* ret);

	Napi::Value setLengthAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setLengthStart(true, info),
			&MetadataBuilder::setLengthFinish);
	}

	Napi::Value setLengthSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setLengthStart(false, info)();
			return setLengthFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setCharSetStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setCharSetFinish(const Napi::Env env, void* ret);

	Napi::Value setCharSetAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setCharSetStart(true, info),
			&MetadataBuilder::setCharSetFinish);
	}

	Napi::Value setCharSetSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setCharSetStart(false, info)();
			return setCharSetFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setScaleStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setScaleFinish(const Napi::Env env, void* ret);

	Napi::Value setScaleAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setScaleStart(true, info),
			&MetadataBuilder::setScaleFinish);
	}

	Napi::Value setScaleSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setScaleStart(false, info)();
			return setScaleFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> truncateStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value truncateFinish(const Napi::Env env, void* ret);

	Napi::Value truncateAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			truncateStart(true, info),
			&MetadataBuilder::truncateFinish);
	}

	Napi::Value truncateSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = truncateStart(false, info)();
			return truncateFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> moveNameToIndexStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value moveNameToIndexFinish(const Napi::Env env, void* ret);

	Napi::Value moveNameToIndexAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			moveNameToIndexStart(true, info),
			&MetadataBuilder::moveNameToIndexFinish);
	}

	Napi::Value moveNameToIndexSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = moveNameToIndexStart(false, info)();
			return moveNameToIndexFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> removeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value removeFinish(const Napi::Env env, void* ret);

	Napi::Value removeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			removeStart(true, info),
			&MetadataBuilder::removeFinish);
	}

	Napi::Value removeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = removeStart(false, info)();
			return removeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned> addFieldStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addFieldFinish(const Napi::Env env, unsigned ret);

	Napi::Value addFieldAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			addFieldStart(true, info),
			&MetadataBuilder::addFieldFinish);
	}

	Napi::Value addFieldSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addFieldStart(false, info)();
			return addFieldFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IMessageMetadata*> getMetadataStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getMetadataFinish(const Napi::Env env, fb::IMessageMetadata* ret);

	Napi::Value getMetadataAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IMessageMetadata*>::Run(info.Env(),
			getMetadataStart(true, info),
			&MetadataBuilder::getMetadataFinish);
	}

	Napi::Value getMetadataSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getMetadataStart(false, info)();
			return getMetadataFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class ResultSet : public BaseClass<ResultSet, fb::IResultSet>
{
friend class BaseClass<ResultSet, fb::IResultSet>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<ResultSet>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&ResultSet::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&ResultSet::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> fetchNextStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value fetchNextFinish(const Napi::Env env, int ret);

	Napi::Value fetchNextAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			fetchNextStart(true, info),
			&ResultSet::fetchNextFinish);
	}

	Napi::Value fetchNextSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = fetchNextStart(false, info)();
			return fetchNextFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> fetchPriorStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value fetchPriorFinish(const Napi::Env env, int ret);

	Napi::Value fetchPriorAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			fetchPriorStart(true, info),
			&ResultSet::fetchPriorFinish);
	}

	Napi::Value fetchPriorSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = fetchPriorStart(false, info)();
			return fetchPriorFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> fetchFirstStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value fetchFirstFinish(const Napi::Env env, int ret);

	Napi::Value fetchFirstAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			fetchFirstStart(true, info),
			&ResultSet::fetchFirstFinish);
	}

	Napi::Value fetchFirstSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = fetchFirstStart(false, info)();
			return fetchFirstFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> fetchLastStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value fetchLastFinish(const Napi::Env env, int ret);

	Napi::Value fetchLastAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			fetchLastStart(true, info),
			&ResultSet::fetchLastFinish);
	}

	Napi::Value fetchLastSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = fetchLastStart(false, info)();
			return fetchLastFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> fetchAbsoluteStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value fetchAbsoluteFinish(const Napi::Env env, int ret);

	Napi::Value fetchAbsoluteAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			fetchAbsoluteStart(true, info),
			&ResultSet::fetchAbsoluteFinish);
	}

	Napi::Value fetchAbsoluteSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = fetchAbsoluteStart(false, info)();
			return fetchAbsoluteFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> fetchRelativeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value fetchRelativeFinish(const Napi::Env env, int ret);

	Napi::Value fetchRelativeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			fetchRelativeStart(true, info),
			&ResultSet::fetchRelativeFinish);
	}

	Napi::Value fetchRelativeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = fetchRelativeStart(false, info)();
			return fetchRelativeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<FB_BOOLEAN> isEofStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value isEofFinish(const Napi::Env env, FB_BOOLEAN ret);

	Napi::Value isEofAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<FB_BOOLEAN>::Run(info.Env(),
			isEofStart(true, info),
			&ResultSet::isEofFinish);
	}

	Napi::Value isEofSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = isEofStart(false, info)();
			return isEofFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<FB_BOOLEAN> isBofStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value isBofFinish(const Napi::Env env, FB_BOOLEAN ret);

	Napi::Value isBofAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<FB_BOOLEAN>::Run(info.Env(),
			isBofStart(true, info),
			&ResultSet::isBofFinish);
	}

	Napi::Value isBofSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = isBofStart(false, info)();
			return isBofFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IMessageMetadata*> getMetadataStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getMetadataFinish(const Napi::Env env, fb::IMessageMetadata* ret);

	Napi::Value getMetadataAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IMessageMetadata*>::Run(info.Env(),
			getMetadataStart(true, info),
			&ResultSet::getMetadataFinish);
	}

	Napi::Value getMetadataSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getMetadataStart(false, info)();
			return getMetadataFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> closeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value closeFinish(const Napi::Env env, void* ret);

	Napi::Value closeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			closeStart(true, info),
			&ResultSet::closeFinish);
	}

	Napi::Value closeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = closeStart(false, info)();
			return closeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setDelayedOutputFormatStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setDelayedOutputFormatFinish(const Napi::Env env, void* ret);

	Napi::Value setDelayedOutputFormatAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setDelayedOutputFormatStart(true, info),
			&ResultSet::setDelayedOutputFormatFinish);
	}

	Napi::Value setDelayedOutputFormatSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setDelayedOutputFormatStart(false, info)();
			return setDelayedOutputFormatFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Statement : public BaseClass<Statement, fb::IStatement>
{
friend class BaseClass<Statement, fb::IStatement>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Statement>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&Statement::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&Statement::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> getInfoStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getInfoFinish(const Napi::Env env, void* ret);

	Napi::Value getInfoAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			getInfoStart(true, info),
			&Statement::getInfoFinish);
	}

	Napi::Value getInfoSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getInfoStart(false, info)();
			return getInfoFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned> getTypeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getTypeFinish(const Napi::Env env, unsigned ret);

	Napi::Value getTypeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getTypeStart(true, info),
			&Statement::getTypeFinish);
	}

	Napi::Value getTypeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getTypeStart(false, info)();
			return getTypeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getPlanStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getPlanFinish(const Napi::Env env, std::string ret);

	Napi::Value getPlanAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getPlanStart(true, info),
			&Statement::getPlanFinish);
	}

	Napi::Value getPlanSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getPlanStart(false, info)();
			return getPlanFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<uint64_t> getAffectedRecordsStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getAffectedRecordsFinish(const Napi::Env env, uint64_t ret);

	Napi::Value getAffectedRecordsAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<uint64_t>::Run(info.Env(),
			getAffectedRecordsStart(true, info),
			&Statement::getAffectedRecordsFinish);
	}

	Napi::Value getAffectedRecordsSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getAffectedRecordsStart(false, info)();
			return getAffectedRecordsFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IMessageMetadata*> getInputMetadataStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getInputMetadataFinish(const Napi::Env env, fb::IMessageMetadata* ret);

	Napi::Value getInputMetadataAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IMessageMetadata*>::Run(info.Env(),
			getInputMetadataStart(true, info),
			&Statement::getInputMetadataFinish);
	}

	Napi::Value getInputMetadataSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getInputMetadataStart(false, info)();
			return getInputMetadataFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IMessageMetadata*> getOutputMetadataStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getOutputMetadataFinish(const Napi::Env env, fb::IMessageMetadata* ret);

	Napi::Value getOutputMetadataAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IMessageMetadata*>::Run(info.Env(),
			getOutputMetadataStart(true, info),
			&Statement::getOutputMetadataFinish);
	}

	Napi::Value getOutputMetadataSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getOutputMetadataStart(false, info)();
			return getOutputMetadataFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ITransaction*> executeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value executeFinish(const Napi::Env env, fb::ITransaction* ret);

	Napi::Value executeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ITransaction*>::Run(info.Env(),
			executeStart(true, info),
			&Statement::executeFinish);
	}

	Napi::Value executeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = executeStart(false, info)();
			return executeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IResultSet*> openCursorStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value openCursorFinish(const Napi::Env env, fb::IResultSet* ret);

	Napi::Value openCursorAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IResultSet*>::Run(info.Env(),
			openCursorStart(true, info),
			&Statement::openCursorFinish);
	}

	Napi::Value openCursorSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = openCursorStart(false, info)();
			return openCursorFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setCursorNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setCursorNameFinish(const Napi::Env env, void* ret);

	Napi::Value setCursorNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setCursorNameStart(true, info),
			&Statement::setCursorNameFinish);
	}

	Napi::Value setCursorNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setCursorNameStart(false, info)();
			return setCursorNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> freeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value freeFinish(const Napi::Env env, void* ret);

	Napi::Value freeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			freeStart(true, info),
			&Statement::freeFinish);
	}

	Napi::Value freeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = freeStart(false, info)();
			return freeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned> getFlagsStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getFlagsFinish(const Napi::Env env, unsigned ret);

	Napi::Value getFlagsAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getFlagsStart(true, info),
			&Statement::getFlagsFinish);
	}

	Napi::Value getFlagsSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getFlagsStart(false, info)();
			return getFlagsFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Request : public BaseClass<Request, fb::IRequest>
{
friend class BaseClass<Request, fb::IRequest>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Request>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&Request::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&Request::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> receiveStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value receiveFinish(const Napi::Env env, void* ret);

	Napi::Value receiveAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			receiveStart(true, info),
			&Request::receiveFinish);
	}

	Napi::Value receiveSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = receiveStart(false, info)();
			return receiveFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> sendStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value sendFinish(const Napi::Env env, void* ret);

	Napi::Value sendAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			sendStart(true, info),
			&Request::sendFinish);
	}

	Napi::Value sendSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = sendStart(false, info)();
			return sendFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> getInfoStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getInfoFinish(const Napi::Env env, void* ret);

	Napi::Value getInfoAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			getInfoStart(true, info),
			&Request::getInfoFinish);
	}

	Napi::Value getInfoSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getInfoStart(false, info)();
			return getInfoFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> startStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value startFinish(const Napi::Env env, void* ret);

	Napi::Value startAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			startStart(true, info),
			&Request::startFinish);
	}

	Napi::Value startSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = startStart(false, info)();
			return startFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> startAndSendStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value startAndSendFinish(const Napi::Env env, void* ret);

	Napi::Value startAndSendAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			startAndSendStart(true, info),
			&Request::startAndSendFinish);
	}

	Napi::Value startAndSendSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = startAndSendStart(false, info)();
			return startAndSendFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> unwindStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value unwindFinish(const Napi::Env env, void* ret);

	Napi::Value unwindAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			unwindStart(true, info),
			&Request::unwindFinish);
	}

	Napi::Value unwindSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = unwindStart(false, info)();
			return unwindFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> freeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value freeFinish(const Napi::Env env, void* ret);

	Napi::Value freeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			freeStart(true, info),
			&Request::freeFinish);
	}

	Napi::Value freeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = freeStart(false, info)();
			return freeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Events : public BaseClass<Events, fb::IEvents>
{
friend class BaseClass<Events, fb::IEvents>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Events>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&Events::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&Events::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> cancelStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value cancelFinish(const Napi::Env env, void* ret);

	Napi::Value cancelAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			cancelStart(true, info),
			&Events::cancelFinish);
	}

	Napi::Value cancelSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = cancelStart(false, info)();
			return cancelFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Attachment : public BaseClass<Attachment, fb::IAttachment>
{
friend class BaseClass<Attachment, fb::IAttachment>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Attachment>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&Attachment::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&Attachment::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> getInfoStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getInfoFinish(const Napi::Env env, void* ret);

	Napi::Value getInfoAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			getInfoStart(true, info),
			&Attachment::getInfoFinish);
	}

	Napi::Value getInfoSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getInfoStart(false, info)();
			return getInfoFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ITransaction*> startTransactionStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value startTransactionFinish(const Napi::Env env, fb::ITransaction* ret);

	Napi::Value startTransactionAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ITransaction*>::Run(info.Env(),
			startTransactionStart(true, info),
			&Attachment::startTransactionFinish);
	}

	Napi::Value startTransactionSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = startTransactionStart(false, info)();
			return startTransactionFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ITransaction*> reconnectTransactionStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value reconnectTransactionFinish(const Napi::Env env, fb::ITransaction* ret);

	Napi::Value reconnectTransactionAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ITransaction*>::Run(info.Env(),
			reconnectTransactionStart(true, info),
			&Attachment::reconnectTransactionFinish);
	}

	Napi::Value reconnectTransactionSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = reconnectTransactionStart(false, info)();
			return reconnectTransactionFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IRequest*> compileRequestStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value compileRequestFinish(const Napi::Env env, fb::IRequest* ret);

	Napi::Value compileRequestAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IRequest*>::Run(info.Env(),
			compileRequestStart(true, info),
			&Attachment::compileRequestFinish);
	}

	Napi::Value compileRequestSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = compileRequestStart(false, info)();
			return compileRequestFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> transactRequestStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value transactRequestFinish(const Napi::Env env, void* ret);

	Napi::Value transactRequestAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			transactRequestStart(true, info),
			&Attachment::transactRequestFinish);
	}

	Napi::Value transactRequestSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = transactRequestStart(false, info)();
			return transactRequestFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IBlob*> createBlobStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value createBlobFinish(const Napi::Env env, fb::IBlob* ret);

	Napi::Value createBlobAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IBlob*>::Run(info.Env(),
			createBlobStart(true, info),
			&Attachment::createBlobFinish);
	}

	Napi::Value createBlobSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = createBlobStart(false, info)();
			return createBlobFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IBlob*> openBlobStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value openBlobFinish(const Napi::Env env, fb::IBlob* ret);

	Napi::Value openBlobAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IBlob*>::Run(info.Env(),
			openBlobStart(true, info),
			&Attachment::openBlobFinish);
	}

	Napi::Value openBlobSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = openBlobStart(false, info)();
			return openBlobFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> executeDynStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value executeDynFinish(const Napi::Env env, void* ret);

	Napi::Value executeDynAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			executeDynStart(true, info),
			&Attachment::executeDynFinish);
	}

	Napi::Value executeDynSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = executeDynStart(false, info)();
			return executeDynFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IStatement*> prepareStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value prepareFinish(const Napi::Env env, fb::IStatement* ret);

	Napi::Value prepareAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IStatement*>::Run(info.Env(),
			prepareStart(true, info),
			&Attachment::prepareFinish);
	}

	Napi::Value prepareSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = prepareStart(false, info)();
			return prepareFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ITransaction*> executeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value executeFinish(const Napi::Env env, fb::ITransaction* ret);

	Napi::Value executeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ITransaction*>::Run(info.Env(),
			executeStart(true, info),
			&Attachment::executeFinish);
	}

	Napi::Value executeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = executeStart(false, info)();
			return executeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IResultSet*> openCursorStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value openCursorFinish(const Napi::Env env, fb::IResultSet* ret);

	Napi::Value openCursorAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IResultSet*>::Run(info.Env(),
			openCursorStart(true, info),
			&Attachment::openCursorFinish);
	}

	Napi::Value openCursorSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = openCursorStart(false, info)();
			return openCursorFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IEvents*> queEventsStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value queEventsFinish(const Napi::Env env, fb::IEvents* ret);

	Napi::Value queEventsAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IEvents*>::Run(info.Env(),
			queEventsStart(true, info),
			&Attachment::queEventsFinish);
	}

	Napi::Value queEventsSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = queEventsStart(false, info)();
			return queEventsFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> cancelOperationStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value cancelOperationFinish(const Napi::Env env, void* ret);

	Napi::Value cancelOperationAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			cancelOperationStart(true, info),
			&Attachment::cancelOperationFinish);
	}

	Napi::Value cancelOperationSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = cancelOperationStart(false, info)();
			return cancelOperationFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> pingStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value pingFinish(const Napi::Env env, void* ret);

	Napi::Value pingAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			pingStart(true, info),
			&Attachment::pingFinish);
	}

	Napi::Value pingSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = pingStart(false, info)();
			return pingFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> detachStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value detachFinish(const Napi::Env env, void* ret);

	Napi::Value detachAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			detachStart(true, info),
			&Attachment::detachFinish);
	}

	Napi::Value detachSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = detachStart(false, info)();
			return detachFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> dropDatabaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value dropDatabaseFinish(const Napi::Env env, void* ret);

	Napi::Value dropDatabaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			dropDatabaseStart(true, info),
			&Attachment::dropDatabaseFinish);
	}

	Napi::Value dropDatabaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = dropDatabaseStart(false, info)();
			return dropDatabaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Service : public BaseClass<Service, fb::IService>
{
friend class BaseClass<Service, fb::IService>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Service>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&Service::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&Service::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> detachStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value detachFinish(const Napi::Env env, void* ret);

	Napi::Value detachAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			detachStart(true, info),
			&Service::detachFinish);
	}

	Napi::Value detachSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = detachStart(false, info)();
			return detachFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> queryStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value queryFinish(const Napi::Env env, void* ret);

	Napi::Value queryAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			queryStart(true, info),
			&Service::queryFinish);
	}

	Napi::Value querySync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = queryStart(false, info)();
			return queryFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> startStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value startFinish(const Napi::Env env, void* ret);

	Napi::Value startAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			startStart(true, info),
			&Service::startFinish);
	}

	Napi::Value startSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = startStart(false, info)();
			return startFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Provider : public BaseClass<Provider, fb::IProvider>
{
friend class BaseClass<Provider, fb::IProvider>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Provider>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&Provider::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&Provider::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setOwnerFinish(const Napi::Env env, void* ret);

	Napi::Value setOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setOwnerStart(true, info),
			&Provider::setOwnerFinish);
	}

	Napi::Value setOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setOwnerStart(false, info)();
			return setOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IReferenceCounted*> getOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret);

	Napi::Value getOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IReferenceCounted*>::Run(info.Env(),
			getOwnerStart(true, info),
			&Provider::getOwnerFinish);
	}

	Napi::Value getOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getOwnerStart(false, info)();
			return getOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IAttachment*> attachDatabaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value attachDatabaseFinish(const Napi::Env env, fb::IAttachment* ret);

	Napi::Value attachDatabaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IAttachment*>::Run(info.Env(),
			attachDatabaseStart(true, info),
			&Provider::attachDatabaseFinish);
	}

	Napi::Value attachDatabaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = attachDatabaseStart(false, info)();
			return attachDatabaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IAttachment*> createDatabaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value createDatabaseFinish(const Napi::Env env, fb::IAttachment* ret);

	Napi::Value createDatabaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IAttachment*>::Run(info.Env(),
			createDatabaseStart(true, info),
			&Provider::createDatabaseFinish);
	}

	Napi::Value createDatabaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = createDatabaseStart(false, info)();
			return createDatabaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IService*> attachServiceManagerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value attachServiceManagerFinish(const Napi::Env env, fb::IService* ret);

	Napi::Value attachServiceManagerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IService*>::Run(info.Env(),
			attachServiceManagerStart(true, info),
			&Provider::attachServiceManagerFinish);
	}

	Napi::Value attachServiceManagerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = attachServiceManagerStart(false, info)();
			return attachServiceManagerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> shutdownStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value shutdownFinish(const Napi::Env env, void* ret);

	Napi::Value shutdownAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			shutdownStart(true, info),
			&Provider::shutdownFinish);
	}

	Napi::Value shutdownSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = shutdownStart(false, info)();
			return shutdownFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setDbCryptCallbackStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setDbCryptCallbackFinish(const Napi::Env env, void* ret);

	Napi::Value setDbCryptCallbackAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setDbCryptCallbackStart(true, info),
			&Provider::setDbCryptCallbackFinish);
	}

	Napi::Value setDbCryptCallbackSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setDbCryptCallbackStart(false, info)();
			return setDbCryptCallbackFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class DtcStart : public BaseClass<DtcStart, fb::IDtcStart>
{
friend class BaseClass<DtcStart, fb::IDtcStart>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<DtcStart>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> disposeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value disposeFinish(const Napi::Env env, void* ret);

	Napi::Value disposeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			disposeStart(true, info),
			&DtcStart::disposeFinish);
	}

	Napi::Value disposeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = disposeStart(false, info)();
			return disposeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> addAttachmentStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addAttachmentFinish(const Napi::Env env, void* ret);

	Napi::Value addAttachmentAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addAttachmentStart(true, info),
			&DtcStart::addAttachmentFinish);
	}

	Napi::Value addAttachmentSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addAttachmentStart(false, info)();
			return addAttachmentFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> addWithTpbStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addWithTpbFinish(const Napi::Env env, void* ret);

	Napi::Value addWithTpbAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addWithTpbStart(true, info),
			&DtcStart::addWithTpbFinish);
	}

	Napi::Value addWithTpbSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addWithTpbStart(false, info)();
			return addWithTpbFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ITransaction*> startStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value startFinish(const Napi::Env env, fb::ITransaction* ret);

	Napi::Value startAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ITransaction*>::Run(info.Env(),
			startStart(true, info),
			&DtcStart::startFinish);
	}

	Napi::Value startSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = startStart(false, info)();
			return startFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Dtc : public BaseClass<Dtc, fb::IDtc>
{
friend class BaseClass<Dtc, fb::IDtc>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Dtc>::PropertyDescriptor>& properties);

private:
	static MethodStart<fb::ITransaction*> joinStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value joinFinish(const Napi::Env env, fb::ITransaction* ret);

	Napi::Value joinAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ITransaction*>::Run(info.Env(),
			joinStart(true, info),
			&Dtc::joinFinish);
	}

	Napi::Value joinSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = joinStart(false, info)();
			return joinFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IDtcStart*> startBuilderStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value startBuilderFinish(const Napi::Env env, fb::IDtcStart* ret);

	Napi::Value startBuilderAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IDtcStart*>::Run(info.Env(),
			startBuilderStart(true, info),
			&Dtc::startBuilderFinish);
	}

	Napi::Value startBuilderSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = startBuilderStart(false, info)();
			return startBuilderFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Auth : public BaseClass<Auth, fb::IAuth>
{
friend class BaseClass<Auth, fb::IAuth>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Auth>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&Auth::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&Auth::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setOwnerFinish(const Napi::Env env, void* ret);

	Napi::Value setOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setOwnerStart(true, info),
			&Auth::setOwnerFinish);
	}

	Napi::Value setOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setOwnerStart(false, info)();
			return setOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IReferenceCounted*> getOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret);

	Napi::Value getOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IReferenceCounted*>::Run(info.Env(),
			getOwnerStart(true, info),
			&Auth::getOwnerFinish);
	}

	Napi::Value getOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getOwnerStart(false, info)();
			return getOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Writer : public BaseClass<Writer, fb::IWriter>
{
friend class BaseClass<Writer, fb::IWriter>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Writer>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> resetStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value resetFinish(const Napi::Env env, void* ret);

	Napi::Value resetAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			resetStart(true, info),
			&Writer::resetFinish);
	}

	Napi::Value resetSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = resetStart(false, info)();
			return resetFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> addStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addFinish(const Napi::Env env, void* ret);

	Napi::Value addAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addStart(true, info),
			&Writer::addFinish);
	}

	Napi::Value addSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addStart(false, info)();
			return addFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setTypeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setTypeFinish(const Napi::Env env, void* ret);

	Napi::Value setTypeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setTypeStart(true, info),
			&Writer::setTypeFinish);
	}

	Napi::Value setTypeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setTypeStart(false, info)();
			return setTypeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setDbStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setDbFinish(const Napi::Env env, void* ret);

	Napi::Value setDbAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setDbStart(true, info),
			&Writer::setDbFinish);
	}

	Napi::Value setDbSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setDbStart(false, info)();
			return setDbFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class ServerBlock : public BaseClass<ServerBlock, fb::IServerBlock>
{
friend class BaseClass<ServerBlock, fb::IServerBlock>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<ServerBlock>::PropertyDescriptor>& properties);

private:
	static MethodStart<std::string> getLoginStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getLoginFinish(const Napi::Env env, std::string ret);

	Napi::Value getLoginAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getLoginStart(true, info),
			&ServerBlock::getLoginFinish);
	}

	Napi::Value getLoginSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getLoginStart(false, info)();
			return getLoginFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<const unsigned char*> getDataStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getDataFinish(const Napi::Env env, const unsigned char* ret);

	Napi::Value getDataAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<const unsigned char*>::Run(info.Env(),
			getDataStart(true, info),
			&ServerBlock::getDataFinish);
	}

	Napi::Value getDataSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getDataStart(false, info)();
			return getDataFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> putDataStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value putDataFinish(const Napi::Env env, void* ret);

	Napi::Value putDataAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			putDataStart(true, info),
			&ServerBlock::putDataFinish);
	}

	Napi::Value putDataSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = putDataStart(false, info)();
			return putDataFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ICryptKey*> newKeyStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value newKeyFinish(const Napi::Env env, fb::ICryptKey* ret);

	Napi::Value newKeyAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ICryptKey*>::Run(info.Env(),
			newKeyStart(true, info),
			&ServerBlock::newKeyFinish);
	}

	Napi::Value newKeySync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = newKeyStart(false, info)();
			return newKeyFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class ClientBlock : public BaseClass<ClientBlock, fb::IClientBlock>
{
friend class BaseClass<ClientBlock, fb::IClientBlock>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<ClientBlock>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&ClientBlock::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&ClientBlock::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getLoginStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getLoginFinish(const Napi::Env env, std::string ret);

	Napi::Value getLoginAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getLoginStart(true, info),
			&ClientBlock::getLoginFinish);
	}

	Napi::Value getLoginSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getLoginStart(false, info)();
			return getLoginFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getPasswordStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getPasswordFinish(const Napi::Env env, std::string ret);

	Napi::Value getPasswordAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getPasswordStart(true, info),
			&ClientBlock::getPasswordFinish);
	}

	Napi::Value getPasswordSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getPasswordStart(false, info)();
			return getPasswordFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<const unsigned char*> getDataStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getDataFinish(const Napi::Env env, const unsigned char* ret);

	Napi::Value getDataAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<const unsigned char*>::Run(info.Env(),
			getDataStart(true, info),
			&ClientBlock::getDataFinish);
	}

	Napi::Value getDataSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getDataStart(false, info)();
			return getDataFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> putDataStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value putDataFinish(const Napi::Env env, void* ret);

	Napi::Value putDataAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			putDataStart(true, info),
			&ClientBlock::putDataFinish);
	}

	Napi::Value putDataSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = putDataStart(false, info)();
			return putDataFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ICryptKey*> newKeyStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value newKeyFinish(const Napi::Env env, fb::ICryptKey* ret);

	Napi::Value newKeyAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ICryptKey*>::Run(info.Env(),
			newKeyStart(true, info),
			&ClientBlock::newKeyFinish);
	}

	Napi::Value newKeySync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = newKeyStart(false, info)();
			return newKeyFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Server : public BaseClass<Server, fb::IServer>
{
friend class BaseClass<Server, fb::IServer>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Server>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&Server::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&Server::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setOwnerFinish(const Napi::Env env, void* ret);

	Napi::Value setOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setOwnerStart(true, info),
			&Server::setOwnerFinish);
	}

	Napi::Value setOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setOwnerStart(false, info)();
			return setOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IReferenceCounted*> getOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret);

	Napi::Value getOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IReferenceCounted*>::Run(info.Env(),
			getOwnerStart(true, info),
			&Server::getOwnerFinish);
	}

	Napi::Value getOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getOwnerStart(false, info)();
			return getOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> authenticateStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value authenticateFinish(const Napi::Env env, int ret);

	Napi::Value authenticateAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			authenticateStart(true, info),
			&Server::authenticateFinish);
	}

	Napi::Value authenticateSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = authenticateStart(false, info)();
			return authenticateFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Client : public BaseClass<Client, fb::IClient>
{
friend class BaseClass<Client, fb::IClient>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Client>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&Client::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&Client::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setOwnerFinish(const Napi::Env env, void* ret);

	Napi::Value setOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setOwnerStart(true, info),
			&Client::setOwnerFinish);
	}

	Napi::Value setOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setOwnerStart(false, info)();
			return setOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IReferenceCounted*> getOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret);

	Napi::Value getOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IReferenceCounted*>::Run(info.Env(),
			getOwnerStart(true, info),
			&Client::getOwnerFinish);
	}

	Napi::Value getOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getOwnerStart(false, info)();
			return getOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> authenticateStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value authenticateFinish(const Napi::Env env, int ret);

	Napi::Value authenticateAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			authenticateStart(true, info),
			&Client::authenticateFinish);
	}

	Napi::Value authenticateSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = authenticateStart(false, info)();
			return authenticateFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class UserField : public BaseClass<UserField, fb::IUserField>
{
friend class BaseClass<UserField, fb::IUserField>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<UserField>::PropertyDescriptor>& properties);

private:
	static MethodStart<int> enteredStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value enteredFinish(const Napi::Env env, int ret);

	Napi::Value enteredAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			enteredStart(true, info),
			&UserField::enteredFinish);
	}

	Napi::Value enteredSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = enteredStart(false, info)();
			return enteredFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> specifiedStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value specifiedFinish(const Napi::Env env, int ret);

	Napi::Value specifiedAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			specifiedStart(true, info),
			&UserField::specifiedFinish);
	}

	Napi::Value specifiedSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = specifiedStart(false, info)();
			return specifiedFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setEnteredStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setEnteredFinish(const Napi::Env env, void* ret);

	Napi::Value setEnteredAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setEnteredStart(true, info),
			&UserField::setEnteredFinish);
	}

	Napi::Value setEnteredSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setEnteredStart(false, info)();
			return setEnteredFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class CharUserField : public BaseClass<CharUserField, fb::ICharUserField>
{
friend class BaseClass<CharUserField, fb::ICharUserField>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<CharUserField>::PropertyDescriptor>& properties);

private:
	static MethodStart<int> enteredStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value enteredFinish(const Napi::Env env, int ret);

	Napi::Value enteredAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			enteredStart(true, info),
			&CharUserField::enteredFinish);
	}

	Napi::Value enteredSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = enteredStart(false, info)();
			return enteredFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> specifiedStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value specifiedFinish(const Napi::Env env, int ret);

	Napi::Value specifiedAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			specifiedStart(true, info),
			&CharUserField::specifiedFinish);
	}

	Napi::Value specifiedSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = specifiedStart(false, info)();
			return specifiedFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setEnteredStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setEnteredFinish(const Napi::Env env, void* ret);

	Napi::Value setEnteredAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setEnteredStart(true, info),
			&CharUserField::setEnteredFinish);
	}

	Napi::Value setEnteredSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setEnteredStart(false, info)();
			return setEnteredFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getFinish(const Napi::Env env, std::string ret);

	Napi::Value getAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getStart(true, info),
			&CharUserField::getFinish);
	}

	Napi::Value getSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getStart(false, info)();
			return getFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setFinish(const Napi::Env env, void* ret);

	Napi::Value setAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setStart(true, info),
			&CharUserField::setFinish);
	}

	Napi::Value setSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setStart(false, info)();
			return setFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class IntUserField : public BaseClass<IntUserField, fb::IIntUserField>
{
friend class BaseClass<IntUserField, fb::IIntUserField>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<IntUserField>::PropertyDescriptor>& properties);

private:
	static MethodStart<int> enteredStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value enteredFinish(const Napi::Env env, int ret);

	Napi::Value enteredAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			enteredStart(true, info),
			&IntUserField::enteredFinish);
	}

	Napi::Value enteredSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = enteredStart(false, info)();
			return enteredFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> specifiedStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value specifiedFinish(const Napi::Env env, int ret);

	Napi::Value specifiedAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			specifiedStart(true, info),
			&IntUserField::specifiedFinish);
	}

	Napi::Value specifiedSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = specifiedStart(false, info)();
			return specifiedFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setEnteredStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setEnteredFinish(const Napi::Env env, void* ret);

	Napi::Value setEnteredAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setEnteredStart(true, info),
			&IntUserField::setEnteredFinish);
	}

	Napi::Value setEnteredSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setEnteredStart(false, info)();
			return setEnteredFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> getStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getFinish(const Napi::Env env, int ret);

	Napi::Value getAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			getStart(true, info),
			&IntUserField::getFinish);
	}

	Napi::Value getSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getStart(false, info)();
			return getFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setFinish(const Napi::Env env, void* ret);

	Napi::Value setAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setStart(true, info),
			&IntUserField::setFinish);
	}

	Napi::Value setSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setStart(false, info)();
			return setFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class User : public BaseClass<User, fb::IUser>
{
friend class BaseClass<User, fb::IUser>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<User>::PropertyDescriptor>& properties);

private:
	static MethodStart<unsigned> operationStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value operationFinish(const Napi::Env env, unsigned ret);

	Napi::Value operationAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			operationStart(true, info),
			&User::operationFinish);
	}

	Napi::Value operationSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = operationStart(false, info)();
			return operationFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ICharUserField*> userNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value userNameFinish(const Napi::Env env, fb::ICharUserField* ret);

	Napi::Value userNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ICharUserField*>::Run(info.Env(),
			userNameStart(true, info),
			&User::userNameFinish);
	}

	Napi::Value userNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = userNameStart(false, info)();
			return userNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ICharUserField*> passwordStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value passwordFinish(const Napi::Env env, fb::ICharUserField* ret);

	Napi::Value passwordAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ICharUserField*>::Run(info.Env(),
			passwordStart(true, info),
			&User::passwordFinish);
	}

	Napi::Value passwordSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = passwordStart(false, info)();
			return passwordFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ICharUserField*> firstNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value firstNameFinish(const Napi::Env env, fb::ICharUserField* ret);

	Napi::Value firstNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ICharUserField*>::Run(info.Env(),
			firstNameStart(true, info),
			&User::firstNameFinish);
	}

	Napi::Value firstNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = firstNameStart(false, info)();
			return firstNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ICharUserField*> lastNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value lastNameFinish(const Napi::Env env, fb::ICharUserField* ret);

	Napi::Value lastNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ICharUserField*>::Run(info.Env(),
			lastNameStart(true, info),
			&User::lastNameFinish);
	}

	Napi::Value lastNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = lastNameStart(false, info)();
			return lastNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ICharUserField*> middleNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value middleNameFinish(const Napi::Env env, fb::ICharUserField* ret);

	Napi::Value middleNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ICharUserField*>::Run(info.Env(),
			middleNameStart(true, info),
			&User::middleNameFinish);
	}

	Napi::Value middleNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = middleNameStart(false, info)();
			return middleNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ICharUserField*> commentStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value commentFinish(const Napi::Env env, fb::ICharUserField* ret);

	Napi::Value commentAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ICharUserField*>::Run(info.Env(),
			commentStart(true, info),
			&User::commentFinish);
	}

	Napi::Value commentSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = commentStart(false, info)();
			return commentFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ICharUserField*> attributesStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value attributesFinish(const Napi::Env env, fb::ICharUserField* ret);

	Napi::Value attributesAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ICharUserField*>::Run(info.Env(),
			attributesStart(true, info),
			&User::attributesFinish);
	}

	Napi::Value attributesSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = attributesStart(false, info)();
			return attributesFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IIntUserField*> activeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value activeFinish(const Napi::Env env, fb::IIntUserField* ret);

	Napi::Value activeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IIntUserField*>::Run(info.Env(),
			activeStart(true, info),
			&User::activeFinish);
	}

	Napi::Value activeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = activeStart(false, info)();
			return activeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IIntUserField*> adminStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value adminFinish(const Napi::Env env, fb::IIntUserField* ret);

	Napi::Value adminAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IIntUserField*>::Run(info.Env(),
			adminStart(true, info),
			&User::adminFinish);
	}

	Napi::Value adminSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = adminStart(false, info)();
			return adminFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> clearStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value clearFinish(const Napi::Env env, void* ret);

	Napi::Value clearAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			clearStart(true, info),
			&User::clearFinish);
	}

	Napi::Value clearSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = clearStart(false, info)();
			return clearFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class ListUsers : public BaseClass<ListUsers, fb::IListUsers>
{
friend class BaseClass<ListUsers, fb::IListUsers>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<ListUsers>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> listStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value listFinish(const Napi::Env env, void* ret);

	Napi::Value listAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			listStart(true, info),
			&ListUsers::listFinish);
	}

	Napi::Value listSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = listStart(false, info)();
			return listFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class LogonInfo : public BaseClass<LogonInfo, fb::ILogonInfo>
{
friend class BaseClass<LogonInfo, fb::ILogonInfo>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<LogonInfo>::PropertyDescriptor>& properties);

private:
	static MethodStart<std::string> nameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value nameFinish(const Napi::Env env, std::string ret);

	Napi::Value nameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			nameStart(true, info),
			&LogonInfo::nameFinish);
	}

	Napi::Value nameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = nameStart(false, info)();
			return nameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> roleStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value roleFinish(const Napi::Env env, std::string ret);

	Napi::Value roleAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			roleStart(true, info),
			&LogonInfo::roleFinish);
	}

	Napi::Value roleSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = roleStart(false, info)();
			return roleFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> networkProtocolStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value networkProtocolFinish(const Napi::Env env, std::string ret);

	Napi::Value networkProtocolAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			networkProtocolStart(true, info),
			&LogonInfo::networkProtocolFinish);
	}

	Napi::Value networkProtocolSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = networkProtocolStart(false, info)();
			return networkProtocolFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> remoteAddressStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value remoteAddressFinish(const Napi::Env env, std::string ret);

	Napi::Value remoteAddressAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			remoteAddressStart(true, info),
			&LogonInfo::remoteAddressFinish);
	}

	Napi::Value remoteAddressSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = remoteAddressStart(false, info)();
			return remoteAddressFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<const unsigned char*> authBlockStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value authBlockFinish(const Napi::Env env, const unsigned char* ret);

	Napi::Value authBlockAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<const unsigned char*>::Run(info.Env(),
			authBlockStart(true, info),
			&LogonInfo::authBlockFinish);
	}

	Napi::Value authBlockSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = authBlockStart(false, info)();
			return authBlockFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Management : public BaseClass<Management, fb::IManagement>
{
friend class BaseClass<Management, fb::IManagement>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Management>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&Management::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&Management::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setOwnerFinish(const Napi::Env env, void* ret);

	Napi::Value setOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setOwnerStart(true, info),
			&Management::setOwnerFinish);
	}

	Napi::Value setOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setOwnerStart(false, info)();
			return setOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IReferenceCounted*> getOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret);

	Napi::Value getOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IReferenceCounted*>::Run(info.Env(),
			getOwnerStart(true, info),
			&Management::getOwnerFinish);
	}

	Napi::Value getOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getOwnerStart(false, info)();
			return getOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> startStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value startFinish(const Napi::Env env, void* ret);

	Napi::Value startAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			startStart(true, info),
			&Management::startFinish);
	}

	Napi::Value startSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = startStart(false, info)();
			return startFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> executeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value executeFinish(const Napi::Env env, int ret);

	Napi::Value executeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			executeStart(true, info),
			&Management::executeFinish);
	}

	Napi::Value executeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = executeStart(false, info)();
			return executeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> commitStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value commitFinish(const Napi::Env env, void* ret);

	Napi::Value commitAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			commitStart(true, info),
			&Management::commitFinish);
	}

	Napi::Value commitSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = commitStart(false, info)();
			return commitFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> rollbackStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value rollbackFinish(const Napi::Env env, void* ret);

	Napi::Value rollbackAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			rollbackStart(true, info),
			&Management::rollbackFinish);
	}

	Napi::Value rollbackSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = rollbackStart(false, info)();
			return rollbackFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class WireCryptPlugin : public BaseClass<WireCryptPlugin, fb::IWireCryptPlugin>
{
friend class BaseClass<WireCryptPlugin, fb::IWireCryptPlugin>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<WireCryptPlugin>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&WireCryptPlugin::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&WireCryptPlugin::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setOwnerFinish(const Napi::Env env, void* ret);

	Napi::Value setOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setOwnerStart(true, info),
			&WireCryptPlugin::setOwnerFinish);
	}

	Napi::Value setOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setOwnerStart(false, info)();
			return setOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IReferenceCounted*> getOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret);

	Napi::Value getOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IReferenceCounted*>::Run(info.Env(),
			getOwnerStart(true, info),
			&WireCryptPlugin::getOwnerFinish);
	}

	Napi::Value getOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getOwnerStart(false, info)();
			return getOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getKnownTypesStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getKnownTypesFinish(const Napi::Env env, std::string ret);

	Napi::Value getKnownTypesAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getKnownTypesStart(true, info),
			&WireCryptPlugin::getKnownTypesFinish);
	}

	Napi::Value getKnownTypesSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getKnownTypesStart(false, info)();
			return getKnownTypesFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setKeyStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setKeyFinish(const Napi::Env env, void* ret);

	Napi::Value setKeyAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setKeyStart(true, info),
			&WireCryptPlugin::setKeyFinish);
	}

	Napi::Value setKeySync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setKeyStart(false, info)();
			return setKeyFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> encryptStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value encryptFinish(const Napi::Env env, void* ret);

	Napi::Value encryptAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			encryptStart(true, info),
			&WireCryptPlugin::encryptFinish);
	}

	Napi::Value encryptSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = encryptStart(false, info)();
			return encryptFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> decryptStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value decryptFinish(const Napi::Env env, void* ret);

	Napi::Value decryptAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			decryptStart(true, info),
			&WireCryptPlugin::decryptFinish);
	}

	Napi::Value decryptSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = decryptStart(false, info)();
			return decryptFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class CryptKeyCallback : public BaseClass<CryptKeyCallback, fb::ICryptKeyCallback>
{
friend class BaseClass<CryptKeyCallback, fb::ICryptKeyCallback>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<CryptKeyCallback>::PropertyDescriptor>& properties);

private:
	static MethodStart<unsigned> callbackStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value callbackFinish(const Napi::Env env, unsigned ret);

	Napi::Value callbackAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			callbackStart(true, info),
			&CryptKeyCallback::callbackFinish);
	}

	Napi::Value callbackSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = callbackStart(false, info)();
			return callbackFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class KeyHolderPlugin : public BaseClass<KeyHolderPlugin, fb::IKeyHolderPlugin>
{
friend class BaseClass<KeyHolderPlugin, fb::IKeyHolderPlugin>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<KeyHolderPlugin>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&KeyHolderPlugin::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&KeyHolderPlugin::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setOwnerFinish(const Napi::Env env, void* ret);

	Napi::Value setOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setOwnerStart(true, info),
			&KeyHolderPlugin::setOwnerFinish);
	}

	Napi::Value setOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setOwnerStart(false, info)();
			return setOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IReferenceCounted*> getOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret);

	Napi::Value getOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IReferenceCounted*>::Run(info.Env(),
			getOwnerStart(true, info),
			&KeyHolderPlugin::getOwnerFinish);
	}

	Napi::Value getOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getOwnerStart(false, info)();
			return getOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> keyCallbackStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value keyCallbackFinish(const Napi::Env env, int ret);

	Napi::Value keyCallbackAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			keyCallbackStart(true, info),
			&KeyHolderPlugin::keyCallbackFinish);
	}

	Napi::Value keyCallbackSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = keyCallbackStart(false, info)();
			return keyCallbackFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::ICryptKeyCallback*> keyHandleStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value keyHandleFinish(const Napi::Env env, fb::ICryptKeyCallback* ret);

	Napi::Value keyHandleAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::ICryptKeyCallback*>::Run(info.Env(),
			keyHandleStart(true, info),
			&KeyHolderPlugin::keyHandleFinish);
	}

	Napi::Value keyHandleSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = keyHandleStart(false, info)();
			return keyHandleFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class DbCryptPlugin : public BaseClass<DbCryptPlugin, fb::IDbCryptPlugin>
{
friend class BaseClass<DbCryptPlugin, fb::IDbCryptPlugin>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<DbCryptPlugin>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&DbCryptPlugin::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&DbCryptPlugin::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setOwnerFinish(const Napi::Env env, void* ret);

	Napi::Value setOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setOwnerStart(true, info),
			&DbCryptPlugin::setOwnerFinish);
	}

	Napi::Value setOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setOwnerStart(false, info)();
			return setOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IReferenceCounted*> getOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret);

	Napi::Value getOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IReferenceCounted*>::Run(info.Env(),
			getOwnerStart(true, info),
			&DbCryptPlugin::getOwnerFinish);
	}

	Napi::Value getOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getOwnerStart(false, info)();
			return getOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class ExternalContext : public BaseClass<ExternalContext, fb::IExternalContext>
{
friend class BaseClass<ExternalContext, fb::IExternalContext>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<ExternalContext>::PropertyDescriptor>& properties);

private:
};


class ExternalResultSet : public BaseClass<ExternalResultSet, fb::IExternalResultSet>
{
friend class BaseClass<ExternalResultSet, fb::IExternalResultSet>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<ExternalResultSet>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> disposeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value disposeFinish(const Napi::Env env, void* ret);

	Napi::Value disposeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			disposeStart(true, info),
			&ExternalResultSet::disposeFinish);
	}

	Napi::Value disposeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = disposeStart(false, info)();
			return disposeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<FB_BOOLEAN> fetchStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value fetchFinish(const Napi::Env env, FB_BOOLEAN ret);

	Napi::Value fetchAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<FB_BOOLEAN>::Run(info.Env(),
			fetchStart(true, info),
			&ExternalResultSet::fetchFinish);
	}

	Napi::Value fetchSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = fetchStart(false, info)();
			return fetchFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class ExternalFunction : public BaseClass<ExternalFunction, fb::IExternalFunction>
{
friend class BaseClass<ExternalFunction, fb::IExternalFunction>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<ExternalFunction>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> disposeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value disposeFinish(const Napi::Env env, void* ret);

	Napi::Value disposeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			disposeStart(true, info),
			&ExternalFunction::disposeFinish);
	}

	Napi::Value disposeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = disposeStart(false, info)();
			return disposeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class ExternalProcedure : public BaseClass<ExternalProcedure, fb::IExternalProcedure>
{
friend class BaseClass<ExternalProcedure, fb::IExternalProcedure>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<ExternalProcedure>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> disposeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value disposeFinish(const Napi::Env env, void* ret);

	Napi::Value disposeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			disposeStart(true, info),
			&ExternalProcedure::disposeFinish);
	}

	Napi::Value disposeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = disposeStart(false, info)();
			return disposeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class ExternalTrigger : public BaseClass<ExternalTrigger, fb::IExternalTrigger>
{
friend class BaseClass<ExternalTrigger, fb::IExternalTrigger>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<ExternalTrigger>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> disposeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value disposeFinish(const Napi::Env env, void* ret);

	Napi::Value disposeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			disposeStart(true, info),
			&ExternalTrigger::disposeFinish);
	}

	Napi::Value disposeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = disposeStart(false, info)();
			return disposeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class RoutineMetadata : public BaseClass<RoutineMetadata, fb::IRoutineMetadata>
{
friend class BaseClass<RoutineMetadata, fb::IRoutineMetadata>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<RoutineMetadata>::PropertyDescriptor>& properties);

private:
	static MethodStart<std::string> getPackageStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getPackageFinish(const Napi::Env env, std::string ret);

	Napi::Value getPackageAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getPackageStart(true, info),
			&RoutineMetadata::getPackageFinish);
	}

	Napi::Value getPackageSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getPackageStart(false, info)();
			return getPackageFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getNameFinish(const Napi::Env env, std::string ret);

	Napi::Value getNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getNameStart(true, info),
			&RoutineMetadata::getNameFinish);
	}

	Napi::Value getNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getNameStart(false, info)();
			return getNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getEntryPointStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getEntryPointFinish(const Napi::Env env, std::string ret);

	Napi::Value getEntryPointAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getEntryPointStart(true, info),
			&RoutineMetadata::getEntryPointFinish);
	}

	Napi::Value getEntryPointSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getEntryPointStart(false, info)();
			return getEntryPointFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getBodyStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getBodyFinish(const Napi::Env env, std::string ret);

	Napi::Value getBodyAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getBodyStart(true, info),
			&RoutineMetadata::getBodyFinish);
	}

	Napi::Value getBodySync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getBodyStart(false, info)();
			return getBodyFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IMessageMetadata*> getInputMetadataStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getInputMetadataFinish(const Napi::Env env, fb::IMessageMetadata* ret);

	Napi::Value getInputMetadataAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IMessageMetadata*>::Run(info.Env(),
			getInputMetadataStart(true, info),
			&RoutineMetadata::getInputMetadataFinish);
	}

	Napi::Value getInputMetadataSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getInputMetadataStart(false, info)();
			return getInputMetadataFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IMessageMetadata*> getOutputMetadataStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getOutputMetadataFinish(const Napi::Env env, fb::IMessageMetadata* ret);

	Napi::Value getOutputMetadataAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IMessageMetadata*>::Run(info.Env(),
			getOutputMetadataStart(true, info),
			&RoutineMetadata::getOutputMetadataFinish);
	}

	Napi::Value getOutputMetadataSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getOutputMetadataStart(false, info)();
			return getOutputMetadataFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IMessageMetadata*> getTriggerMetadataStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getTriggerMetadataFinish(const Napi::Env env, fb::IMessageMetadata* ret);

	Napi::Value getTriggerMetadataAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IMessageMetadata*>::Run(info.Env(),
			getTriggerMetadataStart(true, info),
			&RoutineMetadata::getTriggerMetadataFinish);
	}

	Napi::Value getTriggerMetadataSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getTriggerMetadataStart(false, info)();
			return getTriggerMetadataFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getTriggerTableStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getTriggerTableFinish(const Napi::Env env, std::string ret);

	Napi::Value getTriggerTableAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getTriggerTableStart(true, info),
			&RoutineMetadata::getTriggerTableFinish);
	}

	Napi::Value getTriggerTableSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getTriggerTableStart(false, info)();
			return getTriggerTableFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned> getTriggerTypeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getTriggerTypeFinish(const Napi::Env env, unsigned ret);

	Napi::Value getTriggerTypeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getTriggerTypeStart(true, info),
			&RoutineMetadata::getTriggerTypeFinish);
	}

	Napi::Value getTriggerTypeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getTriggerTypeStart(false, info)();
			return getTriggerTypeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class ExternalEngine : public BaseClass<ExternalEngine, fb::IExternalEngine>
{
friend class BaseClass<ExternalEngine, fb::IExternalEngine>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<ExternalEngine>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&ExternalEngine::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&ExternalEngine::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setOwnerFinish(const Napi::Env env, void* ret);

	Napi::Value setOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setOwnerStart(true, info),
			&ExternalEngine::setOwnerFinish);
	}

	Napi::Value setOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setOwnerStart(false, info)();
			return setOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IReferenceCounted*> getOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret);

	Napi::Value getOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IReferenceCounted*>::Run(info.Env(),
			getOwnerStart(true, info),
			&ExternalEngine::getOwnerFinish);
	}

	Napi::Value getOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getOwnerStart(false, info)();
			return getOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Timer : public BaseClass<Timer, fb::ITimer>
{
friend class BaseClass<Timer, fb::ITimer>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Timer>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&Timer::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&Timer::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> handlerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value handlerFinish(const Napi::Env env, void* ret);

	Napi::Value handlerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			handlerStart(true, info),
			&Timer::handlerFinish);
	}

	Napi::Value handlerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = handlerStart(false, info)();
			return handlerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class TimerControl : public BaseClass<TimerControl, fb::ITimerControl>
{
friend class BaseClass<TimerControl, fb::ITimerControl>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TimerControl>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> startStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value startFinish(const Napi::Env env, void* ret);

	Napi::Value startAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			startStart(true, info),
			&TimerControl::startFinish);
	}

	Napi::Value startSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = startStart(false, info)();
			return startFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> stopStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value stopFinish(const Napi::Env env, void* ret);

	Napi::Value stopAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			stopStart(true, info),
			&TimerControl::stopFinish);
	}

	Napi::Value stopSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = stopStart(false, info)();
			return stopFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class VersionCallback : public BaseClass<VersionCallback, fb::IVersionCallback>
{
friend class BaseClass<VersionCallback, fb::IVersionCallback>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<VersionCallback>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> callbackStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value callbackFinish(const Napi::Env env, void* ret);

	Napi::Value callbackAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			callbackStart(true, info),
			&VersionCallback::callbackFinish);
	}

	Napi::Value callbackSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = callbackStart(false, info)();
			return callbackFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class Util : public BaseClass<Util, fb::IUtil>
{
friend class BaseClass<Util, fb::IUtil>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<Util>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> getFbVersionStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getFbVersionFinish(const Napi::Env env, void* ret);

	Napi::Value getFbVersionAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			getFbVersionStart(true, info),
			&Util::getFbVersionFinish);
	}

	Napi::Value getFbVersionSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getFbVersionStart(false, info)();
			return getFbVersionFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IAttachment*> executeCreateDatabaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value executeCreateDatabaseFinish(const Napi::Env env, fb::IAttachment* ret);

	Napi::Value executeCreateDatabaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IAttachment*>::Run(info.Env(),
			executeCreateDatabaseStart(true, info),
			&Util::executeCreateDatabaseFinish);
	}

	Napi::Value executeCreateDatabaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = executeCreateDatabaseStart(false, info)();
			return executeCreateDatabaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> decodeDateStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value decodeDateFinish(const Napi::Env env, void* ret);

	Napi::Value decodeDateAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			decodeDateStart(true, info),
			&Util::decodeDateFinish);
	}

	Napi::Value decodeDateSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = decodeDateStart(false, info)();
			return decodeDateFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> decodeTimeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value decodeTimeFinish(const Napi::Env env, void* ret);

	Napi::Value decodeTimeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			decodeTimeStart(true, info),
			&Util::decodeTimeFinish);
	}

	Napi::Value decodeTimeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = decodeTimeStart(false, info)();
			return decodeTimeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> encodeDateStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value encodeDateFinish(const Napi::Env env, int ret);

	Napi::Value encodeDateAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			encodeDateStart(true, info),
			&Util::encodeDateFinish);
	}

	Napi::Value encodeDateSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = encodeDateStart(false, info)();
			return encodeDateFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> encodeTimeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value encodeTimeFinish(const Napi::Env env, int ret);

	Napi::Value encodeTimeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			encodeTimeStart(true, info),
			&Util::encodeTimeFinish);
	}

	Napi::Value encodeTimeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = encodeTimeStart(false, info)();
			return encodeTimeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned> getClientVersionStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getClientVersionFinish(const Napi::Env env, unsigned ret);

	Napi::Value getClientVersionAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getClientVersionStart(true, info),
			&Util::getClientVersionFinish);
	}

	Napi::Value getClientVersionSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getClientVersionStart(false, info)();
			return getClientVersionFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IXpbBuilder*> getXpbBuilderStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getXpbBuilderFinish(const Napi::Env env, fb::IXpbBuilder* ret);

	Napi::Value getXpbBuilderAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IXpbBuilder*>::Run(info.Env(),
			getXpbBuilderStart(true, info),
			&Util::getXpbBuilderFinish);
	}

	Napi::Value getXpbBuilderSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getXpbBuilderStart(false, info)();
			return getXpbBuilderFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned> setOffsetsStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setOffsetsFinish(const Napi::Env env, unsigned ret);

	Napi::Value setOffsetsAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			setOffsetsStart(true, info),
			&Util::setOffsetsFinish);
	}

	Napi::Value setOffsetsSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setOffsetsStart(false, info)();
			return setOffsetsFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class OffsetsCallback : public BaseClass<OffsetsCallback, fb::IOffsetsCallback>
{
friend class BaseClass<OffsetsCallback, fb::IOffsetsCallback>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<OffsetsCallback>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> setOffsetStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setOffsetFinish(const Napi::Env env, void* ret);

	Napi::Value setOffsetAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setOffsetStart(true, info),
			&OffsetsCallback::setOffsetFinish);
	}

	Napi::Value setOffsetSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setOffsetStart(false, info)();
			return setOffsetFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class XpbBuilder : public BaseClass<XpbBuilder, fb::IXpbBuilder>
{
friend class BaseClass<XpbBuilder, fb::IXpbBuilder>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<XpbBuilder>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> disposeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value disposeFinish(const Napi::Env env, void* ret);

	Napi::Value disposeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			disposeStart(true, info),
			&XpbBuilder::disposeFinish);
	}

	Napi::Value disposeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = disposeStart(false, info)();
			return disposeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> clearStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value clearFinish(const Napi::Env env, void* ret);

	Napi::Value clearAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			clearStart(true, info),
			&XpbBuilder::clearFinish);
	}

	Napi::Value clearSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = clearStart(false, info)();
			return clearFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> removeCurrentStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value removeCurrentFinish(const Napi::Env env, void* ret);

	Napi::Value removeCurrentAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			removeCurrentStart(true, info),
			&XpbBuilder::removeCurrentFinish);
	}

	Napi::Value removeCurrentSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = removeCurrentStart(false, info)();
			return removeCurrentFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> insertIntStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value insertIntFinish(const Napi::Env env, void* ret);

	Napi::Value insertIntAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			insertIntStart(true, info),
			&XpbBuilder::insertIntFinish);
	}

	Napi::Value insertIntSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = insertIntStart(false, info)();
			return insertIntFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> insertBigIntStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value insertBigIntFinish(const Napi::Env env, void* ret);

	Napi::Value insertBigIntAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			insertBigIntStart(true, info),
			&XpbBuilder::insertBigIntFinish);
	}

	Napi::Value insertBigIntSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = insertBigIntStart(false, info)();
			return insertBigIntFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> insertBytesStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value insertBytesFinish(const Napi::Env env, void* ret);

	Napi::Value insertBytesAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			insertBytesStart(true, info),
			&XpbBuilder::insertBytesFinish);
	}

	Napi::Value insertBytesSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = insertBytesStart(false, info)();
			return insertBytesFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> insertStringStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value insertStringFinish(const Napi::Env env, void* ret);

	Napi::Value insertStringAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			insertStringStart(true, info),
			&XpbBuilder::insertStringFinish);
	}

	Napi::Value insertStringSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = insertStringStart(false, info)();
			return insertStringFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> insertTagStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value insertTagFinish(const Napi::Env env, void* ret);

	Napi::Value insertTagAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			insertTagStart(true, info),
			&XpbBuilder::insertTagFinish);
	}

	Napi::Value insertTagSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = insertTagStart(false, info)();
			return insertTagFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<FB_BOOLEAN> isEofStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value isEofFinish(const Napi::Env env, FB_BOOLEAN ret);

	Napi::Value isEofAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<FB_BOOLEAN>::Run(info.Env(),
			isEofStart(true, info),
			&XpbBuilder::isEofFinish);
	}

	Napi::Value isEofSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = isEofStart(false, info)();
			return isEofFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> moveNextStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value moveNextFinish(const Napi::Env env, void* ret);

	Napi::Value moveNextAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			moveNextStart(true, info),
			&XpbBuilder::moveNextFinish);
	}

	Napi::Value moveNextSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = moveNextStart(false, info)();
			return moveNextFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> rewindStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value rewindFinish(const Napi::Env env, void* ret);

	Napi::Value rewindAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			rewindStart(true, info),
			&XpbBuilder::rewindFinish);
	}

	Napi::Value rewindSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = rewindStart(false, info)();
			return rewindFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<FB_BOOLEAN> findFirstStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value findFirstFinish(const Napi::Env env, FB_BOOLEAN ret);

	Napi::Value findFirstAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<FB_BOOLEAN>::Run(info.Env(),
			findFirstStart(true, info),
			&XpbBuilder::findFirstFinish);
	}

	Napi::Value findFirstSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = findFirstStart(false, info)();
			return findFirstFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<FB_BOOLEAN> findNextStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value findNextFinish(const Napi::Env env, FB_BOOLEAN ret);

	Napi::Value findNextAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<FB_BOOLEAN>::Run(info.Env(),
			findNextStart(true, info),
			&XpbBuilder::findNextFinish);
	}

	Napi::Value findNextSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = findNextStart(false, info)();
			return findNextFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned char> getTagStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getTagFinish(const Napi::Env env, unsigned char ret);

	Napi::Value getTagAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned char>::Run(info.Env(),
			getTagStart(true, info),
			&XpbBuilder::getTagFinish);
	}

	Napi::Value getTagSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getTagStart(false, info)();
			return getTagFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned> getLengthStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getLengthFinish(const Napi::Env env, unsigned ret);

	Napi::Value getLengthAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getLengthStart(true, info),
			&XpbBuilder::getLengthFinish);
	}

	Napi::Value getLengthSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getLengthStart(false, info)();
			return getLengthFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> getIntStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getIntFinish(const Napi::Env env, int ret);

	Napi::Value getIntAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			getIntStart(true, info),
			&XpbBuilder::getIntFinish);
	}

	Napi::Value getIntSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getIntStart(false, info)();
			return getIntFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int64_t> getBigIntStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getBigIntFinish(const Napi::Env env, int64_t ret);

	Napi::Value getBigIntAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int64_t>::Run(info.Env(),
			getBigIntStart(true, info),
			&XpbBuilder::getBigIntFinish);
	}

	Napi::Value getBigIntSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getBigIntStart(false, info)();
			return getBigIntFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getStringStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getStringFinish(const Napi::Env env, std::string ret);

	Napi::Value getStringAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getStringStart(true, info),
			&XpbBuilder::getStringFinish);
	}

	Napi::Value getStringSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getStringStart(false, info)();
			return getStringFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<const unsigned char*> getBytesStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getBytesFinish(const Napi::Env env, const unsigned char* ret);

	Napi::Value getBytesAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<const unsigned char*>::Run(info.Env(),
			getBytesStart(true, info),
			&XpbBuilder::getBytesFinish);
	}

	Napi::Value getBytesSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getBytesStart(false, info)();
			return getBytesFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<unsigned> getBufferLengthStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getBufferLengthFinish(const Napi::Env env, unsigned ret);

	Napi::Value getBufferLengthAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getBufferLengthStart(true, info),
			&XpbBuilder::getBufferLengthFinish);
	}

	Napi::Value getBufferLengthSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getBufferLengthStart(false, info)();
			return getBufferLengthFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<const unsigned char*> getBufferStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getBufferFinish(const Napi::Env env, const unsigned char* ret);

	Napi::Value getBufferAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<const unsigned char*>::Run(info.Env(),
			getBufferStart(true, info),
			&XpbBuilder::getBufferFinish);
	}

	Napi::Value getBufferSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getBufferStart(false, info)();
			return getBufferFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class TraceConnection : public BaseClass<TraceConnection, fb::ITraceConnection>
{
friend class BaseClass<TraceConnection, fb::ITraceConnection>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceConnection>::PropertyDescriptor>& properties);

private:
	static MethodStart<unsigned> getKindStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getKindFinish(const Napi::Env env, unsigned ret);

	Napi::Value getKindAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getKindStart(true, info),
			&TraceConnection::getKindFinish);
	}

	Napi::Value getKindSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getKindStart(false, info)();
			return getKindFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> getProcessIDStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getProcessIDFinish(const Napi::Env env, int ret);

	Napi::Value getProcessIDAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			getProcessIDStart(true, info),
			&TraceConnection::getProcessIDFinish);
	}

	Napi::Value getProcessIDSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getProcessIDStart(false, info)();
			return getProcessIDFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getUserNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getUserNameFinish(const Napi::Env env, std::string ret);

	Napi::Value getUserNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getUserNameStart(true, info),
			&TraceConnection::getUserNameFinish);
	}

	Napi::Value getUserNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getUserNameStart(false, info)();
			return getUserNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getRoleNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getRoleNameFinish(const Napi::Env env, std::string ret);

	Napi::Value getRoleNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getRoleNameStart(true, info),
			&TraceConnection::getRoleNameFinish);
	}

	Napi::Value getRoleNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getRoleNameStart(false, info)();
			return getRoleNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getCharSetStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getCharSetFinish(const Napi::Env env, std::string ret);

	Napi::Value getCharSetAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getCharSetStart(true, info),
			&TraceConnection::getCharSetFinish);
	}

	Napi::Value getCharSetSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getCharSetStart(false, info)();
			return getCharSetFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getRemoteProtocolStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getRemoteProtocolFinish(const Napi::Env env, std::string ret);

	Napi::Value getRemoteProtocolAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getRemoteProtocolStart(true, info),
			&TraceConnection::getRemoteProtocolFinish);
	}

	Napi::Value getRemoteProtocolSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getRemoteProtocolStart(false, info)();
			return getRemoteProtocolFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getRemoteAddressStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getRemoteAddressFinish(const Napi::Env env, std::string ret);

	Napi::Value getRemoteAddressAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getRemoteAddressStart(true, info),
			&TraceConnection::getRemoteAddressFinish);
	}

	Napi::Value getRemoteAddressSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getRemoteAddressStart(false, info)();
			return getRemoteAddressFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> getRemoteProcessIDStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getRemoteProcessIDFinish(const Napi::Env env, int ret);

	Napi::Value getRemoteProcessIDAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			getRemoteProcessIDStart(true, info),
			&TraceConnection::getRemoteProcessIDFinish);
	}

	Napi::Value getRemoteProcessIDSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getRemoteProcessIDStart(false, info)();
			return getRemoteProcessIDFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getRemoteProcessNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getRemoteProcessNameFinish(const Napi::Env env, std::string ret);

	Napi::Value getRemoteProcessNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getRemoteProcessNameStart(true, info),
			&TraceConnection::getRemoteProcessNameFinish);
	}

	Napi::Value getRemoteProcessNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getRemoteProcessNameStart(false, info)();
			return getRemoteProcessNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class TraceDatabaseConnection : public BaseClass<TraceDatabaseConnection, fb::ITraceDatabaseConnection>
{
friend class BaseClass<TraceDatabaseConnection, fb::ITraceDatabaseConnection>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceDatabaseConnection>::PropertyDescriptor>& properties);

private:
	static MethodStart<unsigned> getKindStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getKindFinish(const Napi::Env env, unsigned ret);

	Napi::Value getKindAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getKindStart(true, info),
			&TraceDatabaseConnection::getKindFinish);
	}

	Napi::Value getKindSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getKindStart(false, info)();
			return getKindFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> getProcessIDStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getProcessIDFinish(const Napi::Env env, int ret);

	Napi::Value getProcessIDAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			getProcessIDStart(true, info),
			&TraceDatabaseConnection::getProcessIDFinish);
	}

	Napi::Value getProcessIDSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getProcessIDStart(false, info)();
			return getProcessIDFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getUserNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getUserNameFinish(const Napi::Env env, std::string ret);

	Napi::Value getUserNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getUserNameStart(true, info),
			&TraceDatabaseConnection::getUserNameFinish);
	}

	Napi::Value getUserNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getUserNameStart(false, info)();
			return getUserNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getRoleNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getRoleNameFinish(const Napi::Env env, std::string ret);

	Napi::Value getRoleNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getRoleNameStart(true, info),
			&TraceDatabaseConnection::getRoleNameFinish);
	}

	Napi::Value getRoleNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getRoleNameStart(false, info)();
			return getRoleNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getCharSetStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getCharSetFinish(const Napi::Env env, std::string ret);

	Napi::Value getCharSetAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getCharSetStart(true, info),
			&TraceDatabaseConnection::getCharSetFinish);
	}

	Napi::Value getCharSetSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getCharSetStart(false, info)();
			return getCharSetFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getRemoteProtocolStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getRemoteProtocolFinish(const Napi::Env env, std::string ret);

	Napi::Value getRemoteProtocolAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getRemoteProtocolStart(true, info),
			&TraceDatabaseConnection::getRemoteProtocolFinish);
	}

	Napi::Value getRemoteProtocolSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getRemoteProtocolStart(false, info)();
			return getRemoteProtocolFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getRemoteAddressStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getRemoteAddressFinish(const Napi::Env env, std::string ret);

	Napi::Value getRemoteAddressAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getRemoteAddressStart(true, info),
			&TraceDatabaseConnection::getRemoteAddressFinish);
	}

	Napi::Value getRemoteAddressSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getRemoteAddressStart(false, info)();
			return getRemoteAddressFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> getRemoteProcessIDStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getRemoteProcessIDFinish(const Napi::Env env, int ret);

	Napi::Value getRemoteProcessIDAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			getRemoteProcessIDStart(true, info),
			&TraceDatabaseConnection::getRemoteProcessIDFinish);
	}

	Napi::Value getRemoteProcessIDSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getRemoteProcessIDStart(false, info)();
			return getRemoteProcessIDFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getRemoteProcessNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getRemoteProcessNameFinish(const Napi::Env env, std::string ret);

	Napi::Value getRemoteProcessNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getRemoteProcessNameStart(true, info),
			&TraceDatabaseConnection::getRemoteProcessNameFinish);
	}

	Napi::Value getRemoteProcessNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getRemoteProcessNameStart(false, info)();
			return getRemoteProcessNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int64_t> getConnectionIDStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getConnectionIDFinish(const Napi::Env env, int64_t ret);

	Napi::Value getConnectionIDAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int64_t>::Run(info.Env(),
			getConnectionIDStart(true, info),
			&TraceDatabaseConnection::getConnectionIDFinish);
	}

	Napi::Value getConnectionIDSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getConnectionIDStart(false, info)();
			return getConnectionIDFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getDatabaseNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getDatabaseNameFinish(const Napi::Env env, std::string ret);

	Napi::Value getDatabaseNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getDatabaseNameStart(true, info),
			&TraceDatabaseConnection::getDatabaseNameFinish);
	}

	Napi::Value getDatabaseNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getDatabaseNameStart(false, info)();
			return getDatabaseNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class TraceTransaction : public BaseClass<TraceTransaction, fb::ITraceTransaction>
{
friend class BaseClass<TraceTransaction, fb::ITraceTransaction>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceTransaction>::PropertyDescriptor>& properties);

private:
};


class TraceParams : public BaseClass<TraceParams, fb::ITraceParams>
{
friend class BaseClass<TraceParams, fb::ITraceParams>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceParams>::PropertyDescriptor>& properties);

private:
};


class TraceStatement : public BaseClass<TraceStatement, fb::ITraceStatement>
{
friend class BaseClass<TraceStatement, fb::ITraceStatement>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceStatement>::PropertyDescriptor>& properties);

private:
};


class TraceSQLStatement : public BaseClass<TraceSQLStatement, fb::ITraceSQLStatement>
{
friend class BaseClass<TraceSQLStatement, fb::ITraceSQLStatement>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceSQLStatement>::PropertyDescriptor>& properties);

private:
};


class TraceBLRStatement : public BaseClass<TraceBLRStatement, fb::ITraceBLRStatement>
{
friend class BaseClass<TraceBLRStatement, fb::ITraceBLRStatement>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceBLRStatement>::PropertyDescriptor>& properties);

private:
};


class TraceDYNRequest : public BaseClass<TraceDYNRequest, fb::ITraceDYNRequest>
{
friend class BaseClass<TraceDYNRequest, fb::ITraceDYNRequest>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceDYNRequest>::PropertyDescriptor>& properties);

private:
};


class TraceContextVariable : public BaseClass<TraceContextVariable, fb::ITraceContextVariable>
{
friend class BaseClass<TraceContextVariable, fb::ITraceContextVariable>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceContextVariable>::PropertyDescriptor>& properties);

private:
};


class TraceProcedure : public BaseClass<TraceProcedure, fb::ITraceProcedure>
{
friend class BaseClass<TraceProcedure, fb::ITraceProcedure>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceProcedure>::PropertyDescriptor>& properties);

private:
};


class TraceFunction : public BaseClass<TraceFunction, fb::ITraceFunction>
{
friend class BaseClass<TraceFunction, fb::ITraceFunction>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceFunction>::PropertyDescriptor>& properties);

private:
};


class TraceTrigger : public BaseClass<TraceTrigger, fb::ITraceTrigger>
{
friend class BaseClass<TraceTrigger, fb::ITraceTrigger>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceTrigger>::PropertyDescriptor>& properties);

private:
};


class TraceServiceConnection : public BaseClass<TraceServiceConnection, fb::ITraceServiceConnection>
{
friend class BaseClass<TraceServiceConnection, fb::ITraceServiceConnection>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceServiceConnection>::PropertyDescriptor>& properties);

private:
	static MethodStart<unsigned> getKindStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getKindFinish(const Napi::Env env, unsigned ret);

	Napi::Value getKindAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<unsigned>::Run(info.Env(),
			getKindStart(true, info),
			&TraceServiceConnection::getKindFinish);
	}

	Napi::Value getKindSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getKindStart(false, info)();
			return getKindFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> getProcessIDStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getProcessIDFinish(const Napi::Env env, int ret);

	Napi::Value getProcessIDAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			getProcessIDStart(true, info),
			&TraceServiceConnection::getProcessIDFinish);
	}

	Napi::Value getProcessIDSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getProcessIDStart(false, info)();
			return getProcessIDFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getUserNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getUserNameFinish(const Napi::Env env, std::string ret);

	Napi::Value getUserNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getUserNameStart(true, info),
			&TraceServiceConnection::getUserNameFinish);
	}

	Napi::Value getUserNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getUserNameStart(false, info)();
			return getUserNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getRoleNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getRoleNameFinish(const Napi::Env env, std::string ret);

	Napi::Value getRoleNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getRoleNameStart(true, info),
			&TraceServiceConnection::getRoleNameFinish);
	}

	Napi::Value getRoleNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getRoleNameStart(false, info)();
			return getRoleNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getCharSetStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getCharSetFinish(const Napi::Env env, std::string ret);

	Napi::Value getCharSetAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getCharSetStart(true, info),
			&TraceServiceConnection::getCharSetFinish);
	}

	Napi::Value getCharSetSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getCharSetStart(false, info)();
			return getCharSetFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getRemoteProtocolStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getRemoteProtocolFinish(const Napi::Env env, std::string ret);

	Napi::Value getRemoteProtocolAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getRemoteProtocolStart(true, info),
			&TraceServiceConnection::getRemoteProtocolFinish);
	}

	Napi::Value getRemoteProtocolSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getRemoteProtocolStart(false, info)();
			return getRemoteProtocolFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getRemoteAddressStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getRemoteAddressFinish(const Napi::Env env, std::string ret);

	Napi::Value getRemoteAddressAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getRemoteAddressStart(true, info),
			&TraceServiceConnection::getRemoteAddressFinish);
	}

	Napi::Value getRemoteAddressSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getRemoteAddressStart(false, info)();
			return getRemoteAddressFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> getRemoteProcessIDStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getRemoteProcessIDFinish(const Napi::Env env, int ret);

	Napi::Value getRemoteProcessIDAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			getRemoteProcessIDStart(true, info),
			&TraceServiceConnection::getRemoteProcessIDFinish);
	}

	Napi::Value getRemoteProcessIDSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getRemoteProcessIDStart(false, info)();
			return getRemoteProcessIDFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<std::string> getRemoteProcessNameStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getRemoteProcessNameFinish(const Napi::Env env, std::string ret);

	Napi::Value getRemoteProcessNameAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<std::string>::Run(info.Env(),
			getRemoteProcessNameStart(true, info),
			&TraceServiceConnection::getRemoteProcessNameFinish);
	}

	Napi::Value getRemoteProcessNameSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getRemoteProcessNameStart(false, info)();
			return getRemoteProcessNameFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class TraceStatusVector : public BaseClass<TraceStatusVector, fb::ITraceStatusVector>
{
friend class BaseClass<TraceStatusVector, fb::ITraceStatusVector>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceStatusVector>::PropertyDescriptor>& properties);

private:
};


class TraceSweepInfo : public BaseClass<TraceSweepInfo, fb::ITraceSweepInfo>
{
friend class BaseClass<TraceSweepInfo, fb::ITraceSweepInfo>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceSweepInfo>::PropertyDescriptor>& properties);

private:
};


class TraceLogWriter : public BaseClass<TraceLogWriter, fb::ITraceLogWriter>
{
friend class BaseClass<TraceLogWriter, fb::ITraceLogWriter>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceLogWriter>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&TraceLogWriter::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&TraceLogWriter::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class TraceInitInfo : public BaseClass<TraceInitInfo, fb::ITraceInitInfo>
{
friend class BaseClass<TraceInitInfo, fb::ITraceInitInfo>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceInitInfo>::PropertyDescriptor>& properties);

private:
};


class TracePlugin : public BaseClass<TracePlugin, fb::ITracePlugin>
{
friend class BaseClass<TracePlugin, fb::ITracePlugin>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TracePlugin>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&TracePlugin::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&TracePlugin::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class TraceFactory : public BaseClass<TraceFactory, fb::ITraceFactory>
{
friend class BaseClass<TraceFactory, fb::ITraceFactory>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<TraceFactory>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> addRefStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value addRefFinish(const Napi::Env env, void* ret);

	Napi::Value addRefAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			addRefStart(true, info),
			&TraceFactory::addRefFinish);
	}

	Napi::Value addRefSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = addRefStart(false, info)();
			return addRefFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<int> releaseStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value releaseFinish(const Napi::Env env, int ret);

	Napi::Value releaseAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<int>::Run(info.Env(),
			releaseStart(true, info),
			&TraceFactory::releaseFinish);
	}

	Napi::Value releaseSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = releaseStart(false, info)();
			return releaseFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setOwnerFinish(const Napi::Env env, void* ret);

	Napi::Value setOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setOwnerStart(true, info),
			&TraceFactory::setOwnerFinish);
	}

	Napi::Value setOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setOwnerStart(false, info)();
			return setOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IReferenceCounted*> getOwnerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret);

	Napi::Value getOwnerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IReferenceCounted*>::Run(info.Env(),
			getOwnerStart(true, info),
			&TraceFactory::getOwnerFinish);
	}

	Napi::Value getOwnerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getOwnerStart(false, info)();
			return getOwnerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class UdrFunctionFactory : public BaseClass<UdrFunctionFactory, fb::IUdrFunctionFactory>
{
friend class BaseClass<UdrFunctionFactory, fb::IUdrFunctionFactory>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<UdrFunctionFactory>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> disposeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value disposeFinish(const Napi::Env env, void* ret);

	Napi::Value disposeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			disposeStart(true, info),
			&UdrFunctionFactory::disposeFinish);
	}

	Napi::Value disposeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = disposeStart(false, info)();
			return disposeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setupStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setupFinish(const Napi::Env env, void* ret);

	Napi::Value setupAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setupStart(true, info),
			&UdrFunctionFactory::setupFinish);
	}

	Napi::Value setupSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setupStart(false, info)();
			return setupFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IExternalFunction*> newItemStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value newItemFinish(const Napi::Env env, fb::IExternalFunction* ret);

	Napi::Value newItemAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IExternalFunction*>::Run(info.Env(),
			newItemStart(true, info),
			&UdrFunctionFactory::newItemFinish);
	}

	Napi::Value newItemSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = newItemStart(false, info)();
			return newItemFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class UdrProcedureFactory : public BaseClass<UdrProcedureFactory, fb::IUdrProcedureFactory>
{
friend class BaseClass<UdrProcedureFactory, fb::IUdrProcedureFactory>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<UdrProcedureFactory>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> disposeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value disposeFinish(const Napi::Env env, void* ret);

	Napi::Value disposeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			disposeStart(true, info),
			&UdrProcedureFactory::disposeFinish);
	}

	Napi::Value disposeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = disposeStart(false, info)();
			return disposeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setupStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setupFinish(const Napi::Env env, void* ret);

	Napi::Value setupAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setupStart(true, info),
			&UdrProcedureFactory::setupFinish);
	}

	Napi::Value setupSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setupStart(false, info)();
			return setupFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IExternalProcedure*> newItemStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value newItemFinish(const Napi::Env env, fb::IExternalProcedure* ret);

	Napi::Value newItemAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IExternalProcedure*>::Run(info.Env(),
			newItemStart(true, info),
			&UdrProcedureFactory::newItemFinish);
	}

	Napi::Value newItemSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = newItemStart(false, info)();
			return newItemFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class UdrTriggerFactory : public BaseClass<UdrTriggerFactory, fb::IUdrTriggerFactory>
{
friend class BaseClass<UdrTriggerFactory, fb::IUdrTriggerFactory>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<UdrTriggerFactory>::PropertyDescriptor>& properties);

private:
	static MethodStart<void*> disposeStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value disposeFinish(const Napi::Env env, void* ret);

	Napi::Value disposeAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			disposeStart(true, info),
			&UdrTriggerFactory::disposeFinish);
	}

	Napi::Value disposeSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = disposeStart(false, info)();
			return disposeFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> setupStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value setupFinish(const Napi::Env env, void* ret);

	Napi::Value setupAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			setupStart(true, info),
			&UdrTriggerFactory::setupFinish);
	}

	Napi::Value setupSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = setupStart(false, info)();
			return setupFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<fb::IExternalTrigger*> newItemStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value newItemFinish(const Napi::Env env, fb::IExternalTrigger* ret);

	Napi::Value newItemAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IExternalTrigger*>::Run(info.Env(),
			newItemStart(true, info),
			&UdrTriggerFactory::newItemFinish);
	}

	Napi::Value newItemSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = newItemStart(false, info)();
			return newItemFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


class UdrPlugin : public BaseClass<UdrPlugin, fb::IUdrPlugin>
{
friend class BaseClass<UdrPlugin, fb::IUdrPlugin>;

public:
	using BaseClass::BaseClass;

private:
	static void InitPrototype(std::vector<Napi::ObjectWrap<UdrPlugin>::PropertyDescriptor>& properties);

private:
	static MethodStart<fb::IMaster*> getMasterStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value getMasterFinish(const Napi::Env env, fb::IMaster* ret);

	Napi::Value getMasterAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<fb::IMaster*>::Run(info.Env(),
			getMasterStart(true, info),
			&UdrPlugin::getMasterFinish);
	}

	Napi::Value getMasterSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = getMasterStart(false, info)();
			return getMasterFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> registerFunctionStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value registerFunctionFinish(const Napi::Env env, void* ret);

	Napi::Value registerFunctionAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			registerFunctionStart(true, info),
			&UdrPlugin::registerFunctionFinish);
	}

	Napi::Value registerFunctionSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = registerFunctionStart(false, info)();
			return registerFunctionFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> registerProcedureStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value registerProcedureFinish(const Napi::Env env, void* ret);

	Napi::Value registerProcedureAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			registerProcedureStart(true, info),
			&UdrPlugin::registerProcedureFinish);
	}

	Napi::Value registerProcedureSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = registerProcedureStart(false, info)();
			return registerProcedureFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

	static MethodStart<void*> registerTriggerStart(bool async, const Napi::CallbackInfo& info);
	static Napi::Value registerTriggerFinish(const Napi::Env env, void* ret);

	Napi::Value registerTriggerAsync(const Napi::CallbackInfo& info)
	{
		return PromiseWorker<void*>::Run(info.Env(),
			registerTriggerStart(true, info),
			&UdrPlugin::registerTriggerFinish);
	}

	Napi::Value registerTriggerSync(const Napi::CallbackInfo& info)
	{
		try
		{
			auto ret = registerTriggerStart(false, info)();
			return registerTriggerFinish(info.Env(), ret);
		}
		catch (...)
		{
			rethrowException(info.Env());
		}
	}

};


void Versioned::InitPrototype(std::vector<Napi::ObjectWrap<Versioned>::PropertyDescriptor>& properties)
{
}

void ReferenceCounted::InitPrototype(std::vector<Napi::ObjectWrap<ReferenceCounted>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &ReferenceCounted::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &ReferenceCounted::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &ReferenceCounted::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &ReferenceCounted::releaseAsync));
}

MethodStart<void*> ReferenceCounted::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ReferenceCounted>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value ReferenceCounted::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> ReferenceCounted::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ReferenceCounted>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value ReferenceCounted::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

void Disposable::InitPrototype(std::vector<Napi::ObjectWrap<Disposable>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("disposeSync", &Disposable::disposeSync));
	properties.push_back(InstanceMethod("disposeAsync", &Disposable::disposeAsync));
}

MethodStart<void*> Disposable::disposeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Disposable>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

Napi::Value Disposable::disposeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void Status::InitPrototype(std::vector<Napi::ObjectWrap<Status>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("disposeSync", &Status::disposeSync));
	properties.push_back(InstanceMethod("disposeAsync", &Status::disposeAsync));
	properties.push_back(InstanceMethod("initSync", &Status::initSync));
	properties.push_back(InstanceMethod("initAsync", &Status::initAsync));
	properties.push_back(InstanceMethod("getStateSync", &Status::getStateSync));
	properties.push_back(InstanceMethod("getStateAsync", &Status::getStateAsync));
	properties.push_back(InstanceMethod("cloneSync", &Status::cloneSync));
	properties.push_back(InstanceMethod("cloneAsync", &Status::cloneAsync));
}

MethodStart<void*> Status::disposeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Status>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

Napi::Value Status::disposeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Status::initStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Status>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->init();
		return nullptr;
	};
}

Napi::Value Status::initFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<unsigned> Status::getStateStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Status>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getState();
	};
}

Napi::Value Status::getStateFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<fb::IStatus*> Status::cloneStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Status>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->clone();
	};
}

Napi::Value Status::cloneFinish(const Napi::Env env, fb::IStatus* ret)
{
	return Status::NewInstance(env, ret);
}

void Master::InitPrototype(std::vector<Napi::ObjectWrap<Master>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("getStatusSync", &Master::getStatusSync));
	properties.push_back(InstanceMethod("getStatusAsync", &Master::getStatusAsync));
	properties.push_back(InstanceMethod("getDispatcherSync", &Master::getDispatcherSync));
	properties.push_back(InstanceMethod("getDispatcherAsync", &Master::getDispatcherAsync));
	properties.push_back(InstanceMethod("getPluginManagerSync", &Master::getPluginManagerSync));
	properties.push_back(InstanceMethod("getPluginManagerAsync", &Master::getPluginManagerAsync));
	properties.push_back(InstanceMethod("getTimerControlSync", &Master::getTimerControlSync));
	properties.push_back(InstanceMethod("getTimerControlAsync", &Master::getTimerControlAsync));
	properties.push_back(InstanceMethod("getDtcSync", &Master::getDtcSync));
	properties.push_back(InstanceMethod("getDtcAsync", &Master::getDtcAsync));
	properties.push_back(InstanceMethod("registerAttachmentSync", &Master::registerAttachmentSync));
	properties.push_back(InstanceMethod("registerAttachmentAsync", &Master::registerAttachmentAsync));
	properties.push_back(InstanceMethod("registerTransactionSync", &Master::registerTransactionSync));
	properties.push_back(InstanceMethod("registerTransactionAsync", &Master::registerTransactionAsync));
	properties.push_back(InstanceMethod("getMetadataBuilderSync", &Master::getMetadataBuilderSync));
	properties.push_back(InstanceMethod("getMetadataBuilderAsync", &Master::getMetadataBuilderAsync));
	properties.push_back(InstanceMethod("serverModeSync", &Master::serverModeSync));
	properties.push_back(InstanceMethod("serverModeAsync", &Master::serverModeAsync));
	properties.push_back(InstanceMethod("getUtilInterfaceSync", &Master::getUtilInterfaceSync));
	properties.push_back(InstanceMethod("getUtilInterfaceAsync", &Master::getUtilInterfaceAsync));
	properties.push_back(InstanceMethod("getConfigManagerSync", &Master::getConfigManagerSync));
	properties.push_back(InstanceMethod("getConfigManagerAsync", &Master::getConfigManagerAsync));
	properties.push_back(InstanceMethod("getProcessExitingSync", &Master::getProcessExitingSync));
	properties.push_back(InstanceMethod("getProcessExitingAsync", &Master::getProcessExitingAsync));
}

MethodStart<fb::IStatus*> Master::getStatusStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Master>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getStatus();
	};
}

Napi::Value Master::getStatusFinish(const Napi::Env env, fb::IStatus* ret)
{
	return Status::NewInstance(env, ret);
}

MethodStart<fb::IProvider*> Master::getDispatcherStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Master>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getDispatcher();
	};
}

Napi::Value Master::getDispatcherFinish(const Napi::Env env, fb::IProvider* ret)
{
	return Provider::NewInstance(env, ret);
}

MethodStart<fb::IPluginManager*> Master::getPluginManagerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Master>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getPluginManager();
	};
}

Napi::Value Master::getPluginManagerFinish(const Napi::Env env, fb::IPluginManager* ret)
{
	return PluginManager::NewInstance(env, ret);
}

MethodStart<fb::ITimerControl*> Master::getTimerControlStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Master>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getTimerControl();
	};
}

Napi::Value Master::getTimerControlFinish(const Napi::Env env, fb::ITimerControl* ret)
{
	return TimerControl::NewInstance(env, ret);
}

MethodStart<fb::IDtc*> Master::getDtcStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Master>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getDtc();
	};
}

Napi::Value Master::getDtcFinish(const Napi::Env env, fb::IDtc* ret)
{
	return Dtc::NewInstance(env, ret);
}

MethodStart<fb::IAttachment*> Master::registerAttachmentStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Master>::Unwrap(info.This().ToObject());
	auto* provider = Provider::CheckedUnwrap(info.Env(), info[0], "provider argument", true);
	auto* attachment = Attachment::CheckedUnwrap(info.Env(), info[1], "attachment argument", true);

	return [obj, provider, attachment]() {
		return obj->interface->registerAttachment((provider ? provider->interface : nullptr), (attachment ? attachment->interface : nullptr));
	};
}

Napi::Value Master::registerAttachmentFinish(const Napi::Env env, fb::IAttachment* ret)
{
	return Attachment::NewInstance(env, ret);
}

MethodStart<fb::ITransaction*> Master::registerTransactionStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Master>::Unwrap(info.This().ToObject());
	auto* attachment = Attachment::CheckedUnwrap(info.Env(), info[0], "attachment argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info.Env(), info[1], "transaction argument", true);

	return [obj, attachment, transaction]() {
		return obj->interface->registerTransaction((attachment ? attachment->interface : nullptr), (transaction ? transaction->interface : nullptr));
	};
}

Napi::Value Master::registerTransactionFinish(const Napi::Env env, fb::ITransaction* ret)
{
	return Transaction::NewInstance(env, ret);
}

MethodStart<fb::IMetadataBuilder*> Master::getMetadataBuilderStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Master>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned fieldCount = (unsigned) info[1].ToNumber();

	return [obj, status, fieldCount]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getMetadataBuilder(&statusWrapper, fieldCount);
	};
}

Napi::Value Master::getMetadataBuilderFinish(const Napi::Env env, fb::IMetadataBuilder* ret)
{
	return MetadataBuilder::NewInstance(env, ret);
}

MethodStart<int> Master::serverModeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Master>::Unwrap(info.This().ToObject());
	int mode = (int) info[0].ToNumber();

	return [obj, mode]() {
		return obj->interface->serverMode(mode);
	};
}

Napi::Value Master::serverModeFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<fb::IUtil*> Master::getUtilInterfaceStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Master>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getUtilInterface();
	};
}

Napi::Value Master::getUtilInterfaceFinish(const Napi::Env env, fb::IUtil* ret)
{
	return Util::NewInstance(env, ret);
}

MethodStart<fb::IConfigManager*> Master::getConfigManagerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Master>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getConfigManager();
	};
}

Napi::Value Master::getConfigManagerFinish(const Napi::Env env, fb::IConfigManager* ret)
{
	return ConfigManager::NewInstance(env, ret);
}

MethodStart<FB_BOOLEAN> Master::getProcessExitingStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Master>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getProcessExiting();
	};
}

Napi::Value Master::getProcessExitingFinish(const Napi::Env env, FB_BOOLEAN ret)
{
	return Napi::Value::From(env, (bool) ret);
}

void PluginBase::InitPrototype(std::vector<Napi::ObjectWrap<PluginBase>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &PluginBase::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &PluginBase::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &PluginBase::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &PluginBase::releaseAsync));
	properties.push_back(InstanceMethod("setOwnerSync", &PluginBase::setOwnerSync));
	properties.push_back(InstanceMethod("setOwnerAsync", &PluginBase::setOwnerAsync));
	properties.push_back(InstanceMethod("getOwnerSync", &PluginBase::getOwnerSync));
	properties.push_back(InstanceMethod("getOwnerAsync", &PluginBase::getOwnerAsync));
}

MethodStart<void*> PluginBase::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginBase>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value PluginBase::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> PluginBase::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginBase>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value PluginBase::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> PluginBase::setOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginBase>::Unwrap(info.This().ToObject());
	auto* r = ReferenceCounted::CheckedUnwrap(info.Env(), info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

Napi::Value PluginBase::setOwnerFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IReferenceCounted*> PluginBase::getOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginBase>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

Napi::Value PluginBase::getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(env, ret);
}

void PluginSet::InitPrototype(std::vector<Napi::ObjectWrap<PluginSet>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &PluginSet::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &PluginSet::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &PluginSet::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &PluginSet::releaseAsync));
	properties.push_back(InstanceMethod("getNameSync", &PluginSet::getNameSync));
	properties.push_back(InstanceMethod("getNameAsync", &PluginSet::getNameAsync));
	properties.push_back(InstanceMethod("getModuleNameSync", &PluginSet::getModuleNameSync));
	properties.push_back(InstanceMethod("getModuleNameAsync", &PluginSet::getModuleNameAsync));
	properties.push_back(InstanceMethod("getPluginSync", &PluginSet::getPluginSync));
	properties.push_back(InstanceMethod("getPluginAsync", &PluginSet::getPluginAsync));
	properties.push_back(InstanceMethod("nextSync", &PluginSet::nextSync));
	properties.push_back(InstanceMethod("nextAsync", &PluginSet::nextAsync));
	properties.push_back(InstanceMethod("setSync", &PluginSet::setSync));
	properties.push_back(InstanceMethod("setAsync", &PluginSet::setAsync));
}

MethodStart<void*> PluginSet::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginSet>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value PluginSet::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> PluginSet::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginSet>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value PluginSet::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> PluginSet::getNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginSet>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getName();
	};
}

Napi::Value PluginSet::getNameFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> PluginSet::getModuleNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginSet>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getModuleName();
	};
}

Napi::Value PluginSet::getModuleNameFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<fb::IPluginBase*> PluginSet::getPluginStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginSet>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getPlugin(&statusWrapper);
	};
}

Napi::Value PluginSet::getPluginFinish(const Napi::Env env, fb::IPluginBase* ret)
{
	return PluginBase::NewInstance(env, ret);
}

MethodStart<void*> PluginSet::nextStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginSet>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->next(&statusWrapper);
		return nullptr;
	};
}

Napi::Value PluginSet::nextFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> PluginSet::setStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginSet>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string s = info[1].ToString().Utf8Value();

	return [obj, status, s]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->set(&statusWrapper, s.c_str());
		return nullptr;
	};
}

Napi::Value PluginSet::setFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void ConfigEntry::InitPrototype(std::vector<Napi::ObjectWrap<ConfigEntry>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &ConfigEntry::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &ConfigEntry::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &ConfigEntry::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &ConfigEntry::releaseAsync));
	properties.push_back(InstanceMethod("getNameSync", &ConfigEntry::getNameSync));
	properties.push_back(InstanceMethod("getNameAsync", &ConfigEntry::getNameAsync));
	properties.push_back(InstanceMethod("getValueSync", &ConfigEntry::getValueSync));
	properties.push_back(InstanceMethod("getValueAsync", &ConfigEntry::getValueAsync));
	properties.push_back(InstanceMethod("getIntValueSync", &ConfigEntry::getIntValueSync));
	properties.push_back(InstanceMethod("getIntValueAsync", &ConfigEntry::getIntValueAsync));
	properties.push_back(InstanceMethod("getBoolValueSync", &ConfigEntry::getBoolValueSync));
	properties.push_back(InstanceMethod("getBoolValueAsync", &ConfigEntry::getBoolValueAsync));
	properties.push_back(InstanceMethod("getSubConfigSync", &ConfigEntry::getSubConfigSync));
	properties.push_back(InstanceMethod("getSubConfigAsync", &ConfigEntry::getSubConfigAsync));
}

MethodStart<void*> ConfigEntry::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ConfigEntry>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value ConfigEntry::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> ConfigEntry::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ConfigEntry>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value ConfigEntry::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> ConfigEntry::getNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ConfigEntry>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getName();
	};
}

Napi::Value ConfigEntry::getNameFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> ConfigEntry::getValueStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ConfigEntry>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getValue();
	};
}

Napi::Value ConfigEntry::getValueFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int64_t> ConfigEntry::getIntValueStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ConfigEntry>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getIntValue();
	};
}

Napi::Value ConfigEntry::getIntValueFinish(const Napi::Env env, int64_t ret)
{
	return Napi::Value::From(env, (double) ret);
}

MethodStart<FB_BOOLEAN> ConfigEntry::getBoolValueStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ConfigEntry>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getBoolValue();
	};
}

Napi::Value ConfigEntry::getBoolValueFinish(const Napi::Env env, FB_BOOLEAN ret)
{
	return Napi::Value::From(env, (bool) ret);
}

MethodStart<fb::IConfig*> ConfigEntry::getSubConfigStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ConfigEntry>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getSubConfig(&statusWrapper);
	};
}

Napi::Value ConfigEntry::getSubConfigFinish(const Napi::Env env, fb::IConfig* ret)
{
	return Config::NewInstance(env, ret);
}

void Config::InitPrototype(std::vector<Napi::ObjectWrap<Config>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &Config::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &Config::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &Config::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &Config::releaseAsync));
	properties.push_back(InstanceMethod("findSync", &Config::findSync));
	properties.push_back(InstanceMethod("findAsync", &Config::findAsync));
	properties.push_back(InstanceMethod("findValueSync", &Config::findValueSync));
	properties.push_back(InstanceMethod("findValueAsync", &Config::findValueAsync));
	properties.push_back(InstanceMethod("findPosSync", &Config::findPosSync));
	properties.push_back(InstanceMethod("findPosAsync", &Config::findPosAsync));
}

MethodStart<void*> Config::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Config>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value Config::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Config::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Config>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value Config::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<fb::IConfigEntry*> Config::findStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Config>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string name = info[1].ToString().Utf8Value();

	return [obj, status, name]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->find(&statusWrapper, name.c_str());
	};
}

Napi::Value Config::findFinish(const Napi::Env env, fb::IConfigEntry* ret)
{
	return ConfigEntry::NewInstance(env, ret);
}

MethodStart<fb::IConfigEntry*> Config::findValueStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Config>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string name = info[1].ToString().Utf8Value();
	std::string value = info[2].ToString().Utf8Value();

	return [obj, status, name, value]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->findValue(&statusWrapper, name.c_str(), value.c_str());
	};
}

Napi::Value Config::findValueFinish(const Napi::Env env, fb::IConfigEntry* ret)
{
	return ConfigEntry::NewInstance(env, ret);
}

MethodStart<fb::IConfigEntry*> Config::findPosStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Config>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string name = info[1].ToString().Utf8Value();
	unsigned pos = (unsigned) info[2].ToNumber();

	return [obj, status, name, pos]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->findPos(&statusWrapper, name.c_str(), pos);
	};
}

Napi::Value Config::findPosFinish(const Napi::Env env, fb::IConfigEntry* ret)
{
	return ConfigEntry::NewInstance(env, ret);
}

void FirebirdConf::InitPrototype(std::vector<Napi::ObjectWrap<FirebirdConf>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &FirebirdConf::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &FirebirdConf::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &FirebirdConf::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &FirebirdConf::releaseAsync));
	properties.push_back(InstanceMethod("getKeySync", &FirebirdConf::getKeySync));
	properties.push_back(InstanceMethod("getKeyAsync", &FirebirdConf::getKeyAsync));
	properties.push_back(InstanceMethod("asIntegerSync", &FirebirdConf::asIntegerSync));
	properties.push_back(InstanceMethod("asIntegerAsync", &FirebirdConf::asIntegerAsync));
	properties.push_back(InstanceMethod("asStringSync", &FirebirdConf::asStringSync));
	properties.push_back(InstanceMethod("asStringAsync", &FirebirdConf::asStringAsync));
	properties.push_back(InstanceMethod("asBooleanSync", &FirebirdConf::asBooleanSync));
	properties.push_back(InstanceMethod("asBooleanAsync", &FirebirdConf::asBooleanAsync));
}

MethodStart<void*> FirebirdConf::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<FirebirdConf>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value FirebirdConf::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> FirebirdConf::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<FirebirdConf>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value FirebirdConf::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<unsigned> FirebirdConf::getKeyStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<FirebirdConf>::Unwrap(info.This().ToObject());
	std::string name = info[0].ToString().Utf8Value();

	return [obj, name]() {
		return obj->interface->getKey(name.c_str());
	};
}

Napi::Value FirebirdConf::getKeyFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int64_t> FirebirdConf::asIntegerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<FirebirdConf>::Unwrap(info.This().ToObject());
	unsigned key = (unsigned) info[0].ToNumber();

	return [obj, key]() {
		return obj->interface->asInteger(key);
	};
}

Napi::Value FirebirdConf::asIntegerFinish(const Napi::Env env, int64_t ret)
{
	return Napi::Value::From(env, (double) ret);
}

MethodStart<std::string> FirebirdConf::asStringStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<FirebirdConf>::Unwrap(info.This().ToObject());
	unsigned key = (unsigned) info[0].ToNumber();

	return [obj, key]() {
		return obj->interface->asString(key);
	};
}

Napi::Value FirebirdConf::asStringFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<FB_BOOLEAN> FirebirdConf::asBooleanStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<FirebirdConf>::Unwrap(info.This().ToObject());
	unsigned key = (unsigned) info[0].ToNumber();

	return [obj, key]() {
		return obj->interface->asBoolean(key);
	};
}

Napi::Value FirebirdConf::asBooleanFinish(const Napi::Env env, FB_BOOLEAN ret)
{
	return Napi::Value::From(env, (bool) ret);
}

void PluginConfig::InitPrototype(std::vector<Napi::ObjectWrap<PluginConfig>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &PluginConfig::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &PluginConfig::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &PluginConfig::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &PluginConfig::releaseAsync));
	properties.push_back(InstanceMethod("getConfigFileNameSync", &PluginConfig::getConfigFileNameSync));
	properties.push_back(InstanceMethod("getConfigFileNameAsync", &PluginConfig::getConfigFileNameAsync));
	properties.push_back(InstanceMethod("getDefaultConfigSync", &PluginConfig::getDefaultConfigSync));
	properties.push_back(InstanceMethod("getDefaultConfigAsync", &PluginConfig::getDefaultConfigAsync));
	properties.push_back(InstanceMethod("getFirebirdConfSync", &PluginConfig::getFirebirdConfSync));
	properties.push_back(InstanceMethod("getFirebirdConfAsync", &PluginConfig::getFirebirdConfAsync));
	properties.push_back(InstanceMethod("setReleaseDelaySync", &PluginConfig::setReleaseDelaySync));
	properties.push_back(InstanceMethod("setReleaseDelayAsync", &PluginConfig::setReleaseDelayAsync));
}

MethodStart<void*> PluginConfig::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginConfig>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value PluginConfig::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> PluginConfig::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginConfig>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value PluginConfig::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> PluginConfig::getConfigFileNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginConfig>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getConfigFileName();
	};
}

Napi::Value PluginConfig::getConfigFileNameFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<fb::IConfig*> PluginConfig::getDefaultConfigStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginConfig>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getDefaultConfig(&statusWrapper);
	};
}

Napi::Value PluginConfig::getDefaultConfigFinish(const Napi::Env env, fb::IConfig* ret)
{
	return Config::NewInstance(env, ret);
}

MethodStart<fb::IFirebirdConf*> PluginConfig::getFirebirdConfStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginConfig>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getFirebirdConf(&statusWrapper);
	};
}

Napi::Value PluginConfig::getFirebirdConfFinish(const Napi::Env env, fb::IFirebirdConf* ret)
{
	return FirebirdConf::NewInstance(env, ret);
}

MethodStart<void*> PluginConfig::setReleaseDelayStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginConfig>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	uint64_t microSeconds = (uint64_t) info[1].ToNumber().Int64Value();

	return [obj, status, microSeconds]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setReleaseDelay(&statusWrapper, microSeconds);
		return nullptr;
	};
}

Napi::Value PluginConfig::setReleaseDelayFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void PluginFactory::InitPrototype(std::vector<Napi::ObjectWrap<PluginFactory>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("createPluginSync", &PluginFactory::createPluginSync));
	properties.push_back(InstanceMethod("createPluginAsync", &PluginFactory::createPluginAsync));
}

MethodStart<fb::IPluginBase*> PluginFactory::createPluginStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginFactory>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* factoryParameter = PluginConfig::CheckedUnwrap(info.Env(), info[1], "factoryParameter argument", true);

	return [obj, status, factoryParameter]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->createPlugin(&statusWrapper, (factoryParameter ? factoryParameter->interface : nullptr));
	};
}

Napi::Value PluginFactory::createPluginFinish(const Napi::Env env, fb::IPluginBase* ret)
{
	return PluginBase::NewInstance(env, ret);
}

void PluginModule::InitPrototype(std::vector<Napi::ObjectWrap<PluginModule>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("doCleanSync", &PluginModule::doCleanSync));
	properties.push_back(InstanceMethod("doCleanAsync", &PluginModule::doCleanAsync));
}

MethodStart<void*> PluginModule::doCleanStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginModule>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->doClean();
		return nullptr;
	};
}

Napi::Value PluginModule::doCleanFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void PluginManager::InitPrototype(std::vector<Napi::ObjectWrap<PluginManager>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("registerPluginFactorySync", &PluginManager::registerPluginFactorySync));
	properties.push_back(InstanceMethod("registerPluginFactoryAsync", &PluginManager::registerPluginFactoryAsync));
	properties.push_back(InstanceMethod("registerModuleSync", &PluginManager::registerModuleSync));
	properties.push_back(InstanceMethod("registerModuleAsync", &PluginManager::registerModuleAsync));
	properties.push_back(InstanceMethod("unregisterModuleSync", &PluginManager::unregisterModuleSync));
	properties.push_back(InstanceMethod("unregisterModuleAsync", &PluginManager::unregisterModuleAsync));
	properties.push_back(InstanceMethod("getPluginsSync", &PluginManager::getPluginsSync));
	properties.push_back(InstanceMethod("getPluginsAsync", &PluginManager::getPluginsAsync));
	properties.push_back(InstanceMethod("getConfigSync", &PluginManager::getConfigSync));
	properties.push_back(InstanceMethod("getConfigAsync", &PluginManager::getConfigAsync));
	properties.push_back(InstanceMethod("releasePluginSync", &PluginManager::releasePluginSync));
	properties.push_back(InstanceMethod("releasePluginAsync", &PluginManager::releasePluginAsync));
}

MethodStart<void*> PluginManager::registerPluginFactoryStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginManager>::Unwrap(info.This().ToObject());
	unsigned pluginType = (unsigned) info[0].ToNumber();
	std::string defaultName = info[1].ToString().Utf8Value();
	auto* factory = PluginFactory::CheckedUnwrap(info.Env(), info[2], "factory argument", true);

	return [obj, pluginType, defaultName, factory]() {
		obj->interface->registerPluginFactory(pluginType, defaultName.c_str(), (factory ? factory->interface : nullptr));
		return nullptr;
	};
}

Napi::Value PluginManager::registerPluginFactoryFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> PluginManager::registerModuleStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginManager>::Unwrap(info.This().ToObject());
	auto* cleanup = PluginModule::CheckedUnwrap(info.Env(), info[0], "cleanup argument", true);

	return [obj, cleanup]() {
		obj->interface->registerModule((cleanup ? cleanup->interface : nullptr));
		return nullptr;
	};
}

Napi::Value PluginManager::registerModuleFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> PluginManager::unregisterModuleStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginManager>::Unwrap(info.This().ToObject());
	auto* cleanup = PluginModule::CheckedUnwrap(info.Env(), info[0], "cleanup argument", true);

	return [obj, cleanup]() {
		obj->interface->unregisterModule((cleanup ? cleanup->interface : nullptr));
		return nullptr;
	};
}

Napi::Value PluginManager::unregisterModuleFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IPluginSet*> PluginManager::getPluginsStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginManager>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned pluginType = (unsigned) info[1].ToNumber();
	std::string namesList = info[2].ToString().Utf8Value();
	auto* firebirdConf = FirebirdConf::CheckedUnwrap(info.Env(), info[3], "firebirdConf argument", true);

	return [obj, status, pluginType, namesList, firebirdConf]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getPlugins(&statusWrapper, pluginType, namesList.c_str(), (firebirdConf ? firebirdConf->interface : nullptr));
	};
}

Napi::Value PluginManager::getPluginsFinish(const Napi::Env env, fb::IPluginSet* ret)
{
	return PluginSet::NewInstance(env, ret);
}

MethodStart<fb::IConfig*> PluginManager::getConfigStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginManager>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string filename = info[1].ToString().Utf8Value();

	return [obj, status, filename]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getConfig(&statusWrapper, filename.c_str());
	};
}

Napi::Value PluginManager::getConfigFinish(const Napi::Env env, fb::IConfig* ret)
{
	return Config::NewInstance(env, ret);
}

MethodStart<void*> PluginManager::releasePluginStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<PluginManager>::Unwrap(info.This().ToObject());
	auto* plugin = PluginBase::CheckedUnwrap(info.Env(), info[0], "plugin argument", true);

	return [obj, plugin]() {
		obj->interface->releasePlugin((plugin ? plugin->interface : nullptr));
		return nullptr;
	};
}

Napi::Value PluginManager::releasePluginFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void CryptKey::InitPrototype(std::vector<Napi::ObjectWrap<CryptKey>::PropertyDescriptor>& properties)
{
}

void ConfigManager::InitPrototype(std::vector<Napi::ObjectWrap<ConfigManager>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("getDirectorySync", &ConfigManager::getDirectorySync));
	properties.push_back(InstanceMethod("getDirectoryAsync", &ConfigManager::getDirectoryAsync));
	properties.push_back(InstanceMethod("getFirebirdConfSync", &ConfigManager::getFirebirdConfSync));
	properties.push_back(InstanceMethod("getFirebirdConfAsync", &ConfigManager::getFirebirdConfAsync));
	properties.push_back(InstanceMethod("getDatabaseConfSync", &ConfigManager::getDatabaseConfSync));
	properties.push_back(InstanceMethod("getDatabaseConfAsync", &ConfigManager::getDatabaseConfAsync));
	properties.push_back(InstanceMethod("getPluginConfigSync", &ConfigManager::getPluginConfigSync));
	properties.push_back(InstanceMethod("getPluginConfigAsync", &ConfigManager::getPluginConfigAsync));
	properties.push_back(InstanceMethod("getInstallDirectorySync", &ConfigManager::getInstallDirectorySync));
	properties.push_back(InstanceMethod("getInstallDirectoryAsync", &ConfigManager::getInstallDirectoryAsync));
	properties.push_back(InstanceMethod("getRootDirectorySync", &ConfigManager::getRootDirectorySync));
	properties.push_back(InstanceMethod("getRootDirectoryAsync", &ConfigManager::getRootDirectoryAsync));
}

MethodStart<std::string> ConfigManager::getDirectoryStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ConfigManager>::Unwrap(info.This().ToObject());
	unsigned code = (unsigned) info[0].ToNumber();

	return [obj, code]() {
		return obj->interface->getDirectory(code);
	};
}

Napi::Value ConfigManager::getDirectoryFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<fb::IFirebirdConf*> ConfigManager::getFirebirdConfStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ConfigManager>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getFirebirdConf();
	};
}

Napi::Value ConfigManager::getFirebirdConfFinish(const Napi::Env env, fb::IFirebirdConf* ret)
{
	return FirebirdConf::NewInstance(env, ret);
}

MethodStart<fb::IFirebirdConf*> ConfigManager::getDatabaseConfStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ConfigManager>::Unwrap(info.This().ToObject());
	std::string dbName = info[0].ToString().Utf8Value();

	return [obj, dbName]() {
		return obj->interface->getDatabaseConf(dbName.c_str());
	};
}

Napi::Value ConfigManager::getDatabaseConfFinish(const Napi::Env env, fb::IFirebirdConf* ret)
{
	return FirebirdConf::NewInstance(env, ret);
}

MethodStart<fb::IConfig*> ConfigManager::getPluginConfigStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ConfigManager>::Unwrap(info.This().ToObject());
	std::string configuredPlugin = info[0].ToString().Utf8Value();

	return [obj, configuredPlugin]() {
		return obj->interface->getPluginConfig(configuredPlugin.c_str());
	};
}

Napi::Value ConfigManager::getPluginConfigFinish(const Napi::Env env, fb::IConfig* ret)
{
	return Config::NewInstance(env, ret);
}

MethodStart<std::string> ConfigManager::getInstallDirectoryStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ConfigManager>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getInstallDirectory();
	};
}

Napi::Value ConfigManager::getInstallDirectoryFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> ConfigManager::getRootDirectoryStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ConfigManager>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getRootDirectory();
	};
}

Napi::Value ConfigManager::getRootDirectoryFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

void EventCallback::InitPrototype(std::vector<Napi::ObjectWrap<EventCallback>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &EventCallback::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &EventCallback::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &EventCallback::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &EventCallback::releaseAsync));
	properties.push_back(InstanceMethod("eventCallbackFunctionSync", &EventCallback::eventCallbackFunctionSync));
	properties.push_back(InstanceMethod("eventCallbackFunctionAsync", &EventCallback::eventCallbackFunctionAsync));
}

MethodStart<void*> EventCallback::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<EventCallback>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value EventCallback::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> EventCallback::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<EventCallback>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value EventCallback::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> EventCallback::eventCallbackFunctionStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<EventCallback>::Unwrap(info.This().ToObject());
	unsigned length = (unsigned) info[0].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> eventsPersistent;
	auto* events = getAddress<unsigned char>(info.Env(), async, info[1], eventsPersistent);

	return [obj, length, events, eventsPersistent]() {
		obj->interface->eventCallbackFunction(length, events);
		return nullptr;
	};
}

Napi::Value EventCallback::eventCallbackFunctionFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void Blob::InitPrototype(std::vector<Napi::ObjectWrap<Blob>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &Blob::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &Blob::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &Blob::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &Blob::releaseAsync));
	properties.push_back(InstanceMethod("getInfoSync", &Blob::getInfoSync));
	properties.push_back(InstanceMethod("getInfoAsync", &Blob::getInfoAsync));
	properties.push_back(InstanceMethod("getSegmentSync", &Blob::getSegmentSync));
	properties.push_back(InstanceMethod("getSegmentAsync", &Blob::getSegmentAsync));
	properties.push_back(InstanceMethod("putSegmentSync", &Blob::putSegmentSync));
	properties.push_back(InstanceMethod("putSegmentAsync", &Blob::putSegmentAsync));
	properties.push_back(InstanceMethod("cancelSync", &Blob::cancelSync));
	properties.push_back(InstanceMethod("cancelAsync", &Blob::cancelAsync));
	properties.push_back(InstanceMethod("closeSync", &Blob::closeSync));
	properties.push_back(InstanceMethod("closeAsync", &Blob::closeAsync));
	properties.push_back(InstanceMethod("seekSync", &Blob::seekSync));
	properties.push_back(InstanceMethod("seekAsync", &Blob::seekAsync));
}

MethodStart<void*> Blob::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Blob>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value Blob::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Blob::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Blob>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value Blob::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> Blob::getInfoStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Blob>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned itemsLength = (unsigned) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> itemsPersistent;
	auto* items = getAddress<unsigned char>(info.Env(), async, info[2], itemsPersistent);
	unsigned bufferLength = (unsigned) info[3].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> bufferPersistent;
	auto* buffer = getAddress<unsigned char>(info.Env(), async, info[4], bufferPersistent);

	return [obj, status, itemsLength, items, itemsPersistent, bufferLength, buffer, bufferPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->getInfo(&statusWrapper, itemsLength, items, bufferLength, buffer);
		return nullptr;
	};
}

Napi::Value Blob::getInfoFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Blob::getSegmentStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Blob>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned bufferLength = (unsigned) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> bufferPersistent;
	auto* buffer = getAddress<unsigned char>(info.Env(), async, info[2], bufferPersistent);
	std::shared_ptr<Napi::Reference<Napi::Value>> segmentLengthPersistent;
	auto* segmentLength = getAddress<unsigned>(info.Env(), async, info[3], segmentLengthPersistent);

	return [obj, status, bufferLength, buffer, bufferPersistent, segmentLength, segmentLengthPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getSegment(&statusWrapper, bufferLength, buffer, segmentLength);
	};
}

Napi::Value Blob::getSegmentFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> Blob::putSegmentStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Blob>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned length = (unsigned) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> bufferPersistent;
	auto* buffer = getAddress<unsigned char>(info.Env(), async, info[2], bufferPersistent);

	return [obj, status, length, buffer, bufferPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->putSegment(&statusWrapper, length, buffer);
		return nullptr;
	};
}

Napi::Value Blob::putSegmentFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Blob::cancelStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Blob>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->cancel(&statusWrapper);
		return nullptr;
	};
}

Napi::Value Blob::cancelFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Blob::closeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Blob>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->close(&statusWrapper);
		return nullptr;
	};
}

Napi::Value Blob::closeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Blob::seekStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Blob>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	int mode = (int) info[1].ToNumber();
	int offset = (int) info[2].ToNumber();

	return [obj, status, mode, offset]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->seek(&statusWrapper, mode, offset);
	};
}

Napi::Value Blob::seekFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

void Transaction::InitPrototype(std::vector<Napi::ObjectWrap<Transaction>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &Transaction::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &Transaction::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &Transaction::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &Transaction::releaseAsync));
	properties.push_back(InstanceMethod("getInfoSync", &Transaction::getInfoSync));
	properties.push_back(InstanceMethod("getInfoAsync", &Transaction::getInfoAsync));
	properties.push_back(InstanceMethod("prepareSync", &Transaction::prepareSync));
	properties.push_back(InstanceMethod("prepareAsync", &Transaction::prepareAsync));
	properties.push_back(InstanceMethod("commitSync", &Transaction::commitSync));
	properties.push_back(InstanceMethod("commitAsync", &Transaction::commitAsync));
	properties.push_back(InstanceMethod("commitRetainingSync", &Transaction::commitRetainingSync));
	properties.push_back(InstanceMethod("commitRetainingAsync", &Transaction::commitRetainingAsync));
	properties.push_back(InstanceMethod("rollbackSync", &Transaction::rollbackSync));
	properties.push_back(InstanceMethod("rollbackAsync", &Transaction::rollbackAsync));
	properties.push_back(InstanceMethod("rollbackRetainingSync", &Transaction::rollbackRetainingSync));
	properties.push_back(InstanceMethod("rollbackRetainingAsync", &Transaction::rollbackRetainingAsync));
	properties.push_back(InstanceMethod("disconnectSync", &Transaction::disconnectSync));
	properties.push_back(InstanceMethod("disconnectAsync", &Transaction::disconnectAsync));
	properties.push_back(InstanceMethod("joinSync", &Transaction::joinSync));
	properties.push_back(InstanceMethod("joinAsync", &Transaction::joinAsync));
	properties.push_back(InstanceMethod("validateSync", &Transaction::validateSync));
	properties.push_back(InstanceMethod("validateAsync", &Transaction::validateAsync));
	properties.push_back(InstanceMethod("enterDtcSync", &Transaction::enterDtcSync));
	properties.push_back(InstanceMethod("enterDtcAsync", &Transaction::enterDtcAsync));
}

MethodStart<void*> Transaction::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Transaction>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value Transaction::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Transaction::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Transaction>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value Transaction::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> Transaction::getInfoStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Transaction>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned itemsLength = (unsigned) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> itemsPersistent;
	auto* items = getAddress<unsigned char>(info.Env(), async, info[2], itemsPersistent);
	unsigned bufferLength = (unsigned) info[3].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> bufferPersistent;
	auto* buffer = getAddress<unsigned char>(info.Env(), async, info[4], bufferPersistent);

	return [obj, status, itemsLength, items, itemsPersistent, bufferLength, buffer, bufferPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->getInfo(&statusWrapper, itemsLength, items, bufferLength, buffer);
		return nullptr;
	};
}

Napi::Value Transaction::getInfoFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Transaction::prepareStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Transaction>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned msgLength = (unsigned) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> messagePersistent;
	auto* message = getAddress<unsigned char>(info.Env(), async, info[2], messagePersistent);

	return [obj, status, msgLength, message, messagePersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->prepare(&statusWrapper, msgLength, message);
		return nullptr;
	};
}

Napi::Value Transaction::prepareFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Transaction::commitStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Transaction>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->commit(&statusWrapper);
		return nullptr;
	};
}

Napi::Value Transaction::commitFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Transaction::commitRetainingStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Transaction>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->commitRetaining(&statusWrapper);
		return nullptr;
	};
}

Napi::Value Transaction::commitRetainingFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Transaction::rollbackStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Transaction>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->rollback(&statusWrapper);
		return nullptr;
	};
}

Napi::Value Transaction::rollbackFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Transaction::rollbackRetainingStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Transaction>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->rollbackRetaining(&statusWrapper);
		return nullptr;
	};
}

Napi::Value Transaction::rollbackRetainingFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Transaction::disconnectStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Transaction>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->disconnect(&statusWrapper);
		return nullptr;
	};
}

Napi::Value Transaction::disconnectFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::ITransaction*> Transaction::joinStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Transaction>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info.Env(), info[1], "transaction argument", true);

	return [obj, status, transaction]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->join(&statusWrapper, (transaction ? transaction->interface : nullptr));
	};
}

Napi::Value Transaction::joinFinish(const Napi::Env env, fb::ITransaction* ret)
{
	return Transaction::NewInstance(env, ret);
}

MethodStart<fb::ITransaction*> Transaction::validateStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Transaction>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* attachment = Attachment::CheckedUnwrap(info.Env(), info[1], "attachment argument", true);

	return [obj, status, attachment]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->validate(&statusWrapper, (attachment ? attachment->interface : nullptr));
	};
}

Napi::Value Transaction::validateFinish(const Napi::Env env, fb::ITransaction* ret)
{
	return Transaction::NewInstance(env, ret);
}

MethodStart<fb::ITransaction*> Transaction::enterDtcStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Transaction>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->enterDtc(&statusWrapper);
	};
}

Napi::Value Transaction::enterDtcFinish(const Napi::Env env, fb::ITransaction* ret)
{
	return Transaction::NewInstance(env, ret);
}

void MessageMetadata::InitPrototype(std::vector<Napi::ObjectWrap<MessageMetadata>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &MessageMetadata::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &MessageMetadata::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &MessageMetadata::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &MessageMetadata::releaseAsync));
	properties.push_back(InstanceMethod("getCountSync", &MessageMetadata::getCountSync));
	properties.push_back(InstanceMethod("getCountAsync", &MessageMetadata::getCountAsync));
	properties.push_back(InstanceMethod("getFieldSync", &MessageMetadata::getFieldSync));
	properties.push_back(InstanceMethod("getFieldAsync", &MessageMetadata::getFieldAsync));
	properties.push_back(InstanceMethod("getRelationSync", &MessageMetadata::getRelationSync));
	properties.push_back(InstanceMethod("getRelationAsync", &MessageMetadata::getRelationAsync));
	properties.push_back(InstanceMethod("getOwnerSync", &MessageMetadata::getOwnerSync));
	properties.push_back(InstanceMethod("getOwnerAsync", &MessageMetadata::getOwnerAsync));
	properties.push_back(InstanceMethod("getAliasSync", &MessageMetadata::getAliasSync));
	properties.push_back(InstanceMethod("getAliasAsync", &MessageMetadata::getAliasAsync));
	properties.push_back(InstanceMethod("getTypeSync", &MessageMetadata::getTypeSync));
	properties.push_back(InstanceMethod("getTypeAsync", &MessageMetadata::getTypeAsync));
	properties.push_back(InstanceMethod("isNullableSync", &MessageMetadata::isNullableSync));
	properties.push_back(InstanceMethod("isNullableAsync", &MessageMetadata::isNullableAsync));
	properties.push_back(InstanceMethod("getSubTypeSync", &MessageMetadata::getSubTypeSync));
	properties.push_back(InstanceMethod("getSubTypeAsync", &MessageMetadata::getSubTypeAsync));
	properties.push_back(InstanceMethod("getLengthSync", &MessageMetadata::getLengthSync));
	properties.push_back(InstanceMethod("getLengthAsync", &MessageMetadata::getLengthAsync));
	properties.push_back(InstanceMethod("getScaleSync", &MessageMetadata::getScaleSync));
	properties.push_back(InstanceMethod("getScaleAsync", &MessageMetadata::getScaleAsync));
	properties.push_back(InstanceMethod("getCharSetSync", &MessageMetadata::getCharSetSync));
	properties.push_back(InstanceMethod("getCharSetAsync", &MessageMetadata::getCharSetAsync));
	properties.push_back(InstanceMethod("getOffsetSync", &MessageMetadata::getOffsetSync));
	properties.push_back(InstanceMethod("getOffsetAsync", &MessageMetadata::getOffsetAsync));
	properties.push_back(InstanceMethod("getNullOffsetSync", &MessageMetadata::getNullOffsetSync));
	properties.push_back(InstanceMethod("getNullOffsetAsync", &MessageMetadata::getNullOffsetAsync));
	properties.push_back(InstanceMethod("getBuilderSync", &MessageMetadata::getBuilderSync));
	properties.push_back(InstanceMethod("getBuilderAsync", &MessageMetadata::getBuilderAsync));
	properties.push_back(InstanceMethod("getMessageLengthSync", &MessageMetadata::getMessageLengthSync));
	properties.push_back(InstanceMethod("getMessageLengthAsync", &MessageMetadata::getMessageLengthAsync));
}

MethodStart<void*> MessageMetadata::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MessageMetadata>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value MessageMetadata::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> MessageMetadata::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MessageMetadata>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value MessageMetadata::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<unsigned> MessageMetadata::getCountStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MessageMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getCount(&statusWrapper);
	};
}

Napi::Value MessageMetadata::getCountFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> MessageMetadata::getFieldStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MessageMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getField(&statusWrapper, index);
	};
}

Napi::Value MessageMetadata::getFieldFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> MessageMetadata::getRelationStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MessageMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getRelation(&statusWrapper, index);
	};
}

Napi::Value MessageMetadata::getRelationFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> MessageMetadata::getOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MessageMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getOwner(&statusWrapper, index);
	};
}

Napi::Value MessageMetadata::getOwnerFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> MessageMetadata::getAliasStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MessageMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getAlias(&statusWrapper, index);
	};
}

Napi::Value MessageMetadata::getAliasFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<unsigned> MessageMetadata::getTypeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MessageMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getType(&statusWrapper, index);
	};
}

Napi::Value MessageMetadata::getTypeFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<FB_BOOLEAN> MessageMetadata::isNullableStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MessageMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->isNullable(&statusWrapper, index);
	};
}

Napi::Value MessageMetadata::isNullableFinish(const Napi::Env env, FB_BOOLEAN ret)
{
	return Napi::Value::From(env, (bool) ret);
}

MethodStart<int> MessageMetadata::getSubTypeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MessageMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getSubType(&statusWrapper, index);
	};
}

Napi::Value MessageMetadata::getSubTypeFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<unsigned> MessageMetadata::getLengthStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MessageMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getLength(&statusWrapper, index);
	};
}

Napi::Value MessageMetadata::getLengthFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> MessageMetadata::getScaleStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MessageMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getScale(&statusWrapper, index);
	};
}

Napi::Value MessageMetadata::getScaleFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<unsigned> MessageMetadata::getCharSetStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MessageMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getCharSet(&statusWrapper, index);
	};
}

Napi::Value MessageMetadata::getCharSetFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<unsigned> MessageMetadata::getOffsetStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MessageMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getOffset(&statusWrapper, index);
	};
}

Napi::Value MessageMetadata::getOffsetFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<unsigned> MessageMetadata::getNullOffsetStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MessageMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getNullOffset(&statusWrapper, index);
	};
}

Napi::Value MessageMetadata::getNullOffsetFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<fb::IMetadataBuilder*> MessageMetadata::getBuilderStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MessageMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getBuilder(&statusWrapper);
	};
}

Napi::Value MessageMetadata::getBuilderFinish(const Napi::Env env, fb::IMetadataBuilder* ret)
{
	return MetadataBuilder::NewInstance(env, ret);
}

MethodStart<unsigned> MessageMetadata::getMessageLengthStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MessageMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getMessageLength(&statusWrapper);
	};
}

Napi::Value MessageMetadata::getMessageLengthFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

void MetadataBuilder::InitPrototype(std::vector<Napi::ObjectWrap<MetadataBuilder>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &MetadataBuilder::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &MetadataBuilder::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &MetadataBuilder::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &MetadataBuilder::releaseAsync));
	properties.push_back(InstanceMethod("setTypeSync", &MetadataBuilder::setTypeSync));
	properties.push_back(InstanceMethod("setTypeAsync", &MetadataBuilder::setTypeAsync));
	properties.push_back(InstanceMethod("setSubTypeSync", &MetadataBuilder::setSubTypeSync));
	properties.push_back(InstanceMethod("setSubTypeAsync", &MetadataBuilder::setSubTypeAsync));
	properties.push_back(InstanceMethod("setLengthSync", &MetadataBuilder::setLengthSync));
	properties.push_back(InstanceMethod("setLengthAsync", &MetadataBuilder::setLengthAsync));
	properties.push_back(InstanceMethod("setCharSetSync", &MetadataBuilder::setCharSetSync));
	properties.push_back(InstanceMethod("setCharSetAsync", &MetadataBuilder::setCharSetAsync));
	properties.push_back(InstanceMethod("setScaleSync", &MetadataBuilder::setScaleSync));
	properties.push_back(InstanceMethod("setScaleAsync", &MetadataBuilder::setScaleAsync));
	properties.push_back(InstanceMethod("truncateSync", &MetadataBuilder::truncateSync));
	properties.push_back(InstanceMethod("truncateAsync", &MetadataBuilder::truncateAsync));
	properties.push_back(InstanceMethod("moveNameToIndexSync", &MetadataBuilder::moveNameToIndexSync));
	properties.push_back(InstanceMethod("moveNameToIndexAsync", &MetadataBuilder::moveNameToIndexAsync));
	properties.push_back(InstanceMethod("removeSync", &MetadataBuilder::removeSync));
	properties.push_back(InstanceMethod("removeAsync", &MetadataBuilder::removeAsync));
	properties.push_back(InstanceMethod("addFieldSync", &MetadataBuilder::addFieldSync));
	properties.push_back(InstanceMethod("addFieldAsync", &MetadataBuilder::addFieldAsync));
	properties.push_back(InstanceMethod("getMetadataSync", &MetadataBuilder::getMetadataSync));
	properties.push_back(InstanceMethod("getMetadataAsync", &MetadataBuilder::getMetadataAsync));
}

MethodStart<void*> MetadataBuilder::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MetadataBuilder>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value MetadataBuilder::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> MetadataBuilder::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MetadataBuilder>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value MetadataBuilder::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> MetadataBuilder::setTypeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MetadataBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();
	unsigned type = (unsigned) info[2].ToNumber();

	return [obj, status, index, type]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setType(&statusWrapper, index, type);
		return nullptr;
	};
}

Napi::Value MetadataBuilder::setTypeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> MetadataBuilder::setSubTypeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MetadataBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();
	int subType = (int) info[2].ToNumber();

	return [obj, status, index, subType]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setSubType(&statusWrapper, index, subType);
		return nullptr;
	};
}

Napi::Value MetadataBuilder::setSubTypeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> MetadataBuilder::setLengthStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MetadataBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();
	unsigned length = (unsigned) info[2].ToNumber();

	return [obj, status, index, length]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setLength(&statusWrapper, index, length);
		return nullptr;
	};
}

Napi::Value MetadataBuilder::setLengthFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> MetadataBuilder::setCharSetStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MetadataBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();
	unsigned charSet = (unsigned) info[2].ToNumber();

	return [obj, status, index, charSet]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setCharSet(&statusWrapper, index, charSet);
		return nullptr;
	};
}

Napi::Value MetadataBuilder::setCharSetFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> MetadataBuilder::setScaleStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MetadataBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();
	unsigned scale = (unsigned) info[2].ToNumber();

	return [obj, status, index, scale]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setScale(&statusWrapper, index, scale);
		return nullptr;
	};
}

Napi::Value MetadataBuilder::setScaleFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> MetadataBuilder::truncateStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MetadataBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned count = (unsigned) info[1].ToNumber();

	return [obj, status, count]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->truncate(&statusWrapper, count);
		return nullptr;
	};
}

Napi::Value MetadataBuilder::truncateFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> MetadataBuilder::moveNameToIndexStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MetadataBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string name = info[1].ToString().Utf8Value();
	unsigned index = (unsigned) info[2].ToNumber();

	return [obj, status, name, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->moveNameToIndex(&statusWrapper, name.c_str(), index);
		return nullptr;
	};
}

Napi::Value MetadataBuilder::moveNameToIndexFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> MetadataBuilder::removeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MetadataBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->remove(&statusWrapper, index);
		return nullptr;
	};
}

Napi::Value MetadataBuilder::removeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<unsigned> MetadataBuilder::addFieldStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MetadataBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->addField(&statusWrapper);
	};
}

Napi::Value MetadataBuilder::addFieldFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<fb::IMessageMetadata*> MetadataBuilder::getMetadataStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<MetadataBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getMetadata(&statusWrapper);
	};
}

Napi::Value MetadataBuilder::getMetadataFinish(const Napi::Env env, fb::IMessageMetadata* ret)
{
	return MessageMetadata::NewInstance(env, ret);
}

void ResultSet::InitPrototype(std::vector<Napi::ObjectWrap<ResultSet>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &ResultSet::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &ResultSet::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &ResultSet::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &ResultSet::releaseAsync));
	properties.push_back(InstanceMethod("fetchNextSync", &ResultSet::fetchNextSync));
	properties.push_back(InstanceMethod("fetchNextAsync", &ResultSet::fetchNextAsync));
	properties.push_back(InstanceMethod("fetchPriorSync", &ResultSet::fetchPriorSync));
	properties.push_back(InstanceMethod("fetchPriorAsync", &ResultSet::fetchPriorAsync));
	properties.push_back(InstanceMethod("fetchFirstSync", &ResultSet::fetchFirstSync));
	properties.push_back(InstanceMethod("fetchFirstAsync", &ResultSet::fetchFirstAsync));
	properties.push_back(InstanceMethod("fetchLastSync", &ResultSet::fetchLastSync));
	properties.push_back(InstanceMethod("fetchLastAsync", &ResultSet::fetchLastAsync));
	properties.push_back(InstanceMethod("fetchAbsoluteSync", &ResultSet::fetchAbsoluteSync));
	properties.push_back(InstanceMethod("fetchAbsoluteAsync", &ResultSet::fetchAbsoluteAsync));
	properties.push_back(InstanceMethod("fetchRelativeSync", &ResultSet::fetchRelativeSync));
	properties.push_back(InstanceMethod("fetchRelativeAsync", &ResultSet::fetchRelativeAsync));
	properties.push_back(InstanceMethod("isEofSync", &ResultSet::isEofSync));
	properties.push_back(InstanceMethod("isEofAsync", &ResultSet::isEofAsync));
	properties.push_back(InstanceMethod("isBofSync", &ResultSet::isBofSync));
	properties.push_back(InstanceMethod("isBofAsync", &ResultSet::isBofAsync));
	properties.push_back(InstanceMethod("getMetadataSync", &ResultSet::getMetadataSync));
	properties.push_back(InstanceMethod("getMetadataAsync", &ResultSet::getMetadataAsync));
	properties.push_back(InstanceMethod("closeSync", &ResultSet::closeSync));
	properties.push_back(InstanceMethod("closeAsync", &ResultSet::closeAsync));
	properties.push_back(InstanceMethod("setDelayedOutputFormatSync", &ResultSet::setDelayedOutputFormatSync));
	properties.push_back(InstanceMethod("setDelayedOutputFormatAsync", &ResultSet::setDelayedOutputFormatAsync));
}

MethodStart<void*> ResultSet::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ResultSet>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value ResultSet::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> ResultSet::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ResultSet>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value ResultSet::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> ResultSet::fetchNextStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ResultSet>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::shared_ptr<Napi::Reference<Napi::Value>> messagePersistent;
	auto* message = getAddress<unsigned char>(info.Env(), async, info[1], messagePersistent);

	return [obj, status, message, messagePersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->fetchNext(&statusWrapper, message);
	};
}

Napi::Value ResultSet::fetchNextFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> ResultSet::fetchPriorStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ResultSet>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::shared_ptr<Napi::Reference<Napi::Value>> messagePersistent;
	auto* message = getAddress<unsigned char>(info.Env(), async, info[1], messagePersistent);

	return [obj, status, message, messagePersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->fetchPrior(&statusWrapper, message);
	};
}

Napi::Value ResultSet::fetchPriorFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> ResultSet::fetchFirstStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ResultSet>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::shared_ptr<Napi::Reference<Napi::Value>> messagePersistent;
	auto* message = getAddress<unsigned char>(info.Env(), async, info[1], messagePersistent);

	return [obj, status, message, messagePersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->fetchFirst(&statusWrapper, message);
	};
}

Napi::Value ResultSet::fetchFirstFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> ResultSet::fetchLastStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ResultSet>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::shared_ptr<Napi::Reference<Napi::Value>> messagePersistent;
	auto* message = getAddress<unsigned char>(info.Env(), async, info[1], messagePersistent);

	return [obj, status, message, messagePersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->fetchLast(&statusWrapper, message);
	};
}

Napi::Value ResultSet::fetchLastFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> ResultSet::fetchAbsoluteStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ResultSet>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	int position = (int) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> messagePersistent;
	auto* message = getAddress<unsigned char>(info.Env(), async, info[2], messagePersistent);

	return [obj, status, position, message, messagePersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->fetchAbsolute(&statusWrapper, position, message);
	};
}

Napi::Value ResultSet::fetchAbsoluteFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> ResultSet::fetchRelativeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ResultSet>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	int offset = (int) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> messagePersistent;
	auto* message = getAddress<unsigned char>(info.Env(), async, info[2], messagePersistent);

	return [obj, status, offset, message, messagePersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->fetchRelative(&statusWrapper, offset, message);
	};
}

Napi::Value ResultSet::fetchRelativeFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<FB_BOOLEAN> ResultSet::isEofStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ResultSet>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->isEof(&statusWrapper);
	};
}

Napi::Value ResultSet::isEofFinish(const Napi::Env env, FB_BOOLEAN ret)
{
	return Napi::Value::From(env, (bool) ret);
}

MethodStart<FB_BOOLEAN> ResultSet::isBofStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ResultSet>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->isBof(&statusWrapper);
	};
}

Napi::Value ResultSet::isBofFinish(const Napi::Env env, FB_BOOLEAN ret)
{
	return Napi::Value::From(env, (bool) ret);
}

MethodStart<fb::IMessageMetadata*> ResultSet::getMetadataStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ResultSet>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getMetadata(&statusWrapper);
	};
}

Napi::Value ResultSet::getMetadataFinish(const Napi::Env env, fb::IMessageMetadata* ret)
{
	return MessageMetadata::NewInstance(env, ret);
}

MethodStart<void*> ResultSet::closeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ResultSet>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->close(&statusWrapper);
		return nullptr;
	};
}

Napi::Value ResultSet::closeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> ResultSet::setDelayedOutputFormatStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ResultSet>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* format = MessageMetadata::CheckedUnwrap(info.Env(), info[1], "format argument", true);

	return [obj, status, format]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setDelayedOutputFormat(&statusWrapper, (format ? format->interface : nullptr));
		return nullptr;
	};
}

Napi::Value ResultSet::setDelayedOutputFormatFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void Statement::InitPrototype(std::vector<Napi::ObjectWrap<Statement>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &Statement::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &Statement::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &Statement::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &Statement::releaseAsync));
	properties.push_back(InstanceMethod("getInfoSync", &Statement::getInfoSync));
	properties.push_back(InstanceMethod("getInfoAsync", &Statement::getInfoAsync));
	properties.push_back(InstanceMethod("getTypeSync", &Statement::getTypeSync));
	properties.push_back(InstanceMethod("getTypeAsync", &Statement::getTypeAsync));
	properties.push_back(InstanceMethod("getPlanSync", &Statement::getPlanSync));
	properties.push_back(InstanceMethod("getPlanAsync", &Statement::getPlanAsync));
	properties.push_back(InstanceMethod("getAffectedRecordsSync", &Statement::getAffectedRecordsSync));
	properties.push_back(InstanceMethod("getAffectedRecordsAsync", &Statement::getAffectedRecordsAsync));
	properties.push_back(InstanceMethod("getInputMetadataSync", &Statement::getInputMetadataSync));
	properties.push_back(InstanceMethod("getInputMetadataAsync", &Statement::getInputMetadataAsync));
	properties.push_back(InstanceMethod("getOutputMetadataSync", &Statement::getOutputMetadataSync));
	properties.push_back(InstanceMethod("getOutputMetadataAsync", &Statement::getOutputMetadataAsync));
	properties.push_back(InstanceMethod("executeSync", &Statement::executeSync));
	properties.push_back(InstanceMethod("executeAsync", &Statement::executeAsync));
	properties.push_back(InstanceMethod("openCursorSync", &Statement::openCursorSync));
	properties.push_back(InstanceMethod("openCursorAsync", &Statement::openCursorAsync));
	properties.push_back(InstanceMethod("setCursorNameSync", &Statement::setCursorNameSync));
	properties.push_back(InstanceMethod("setCursorNameAsync", &Statement::setCursorNameAsync));
	properties.push_back(InstanceMethod("freeSync", &Statement::freeSync));
	properties.push_back(InstanceMethod("freeAsync", &Statement::freeAsync));
	properties.push_back(InstanceMethod("getFlagsSync", &Statement::getFlagsSync));
	properties.push_back(InstanceMethod("getFlagsAsync", &Statement::getFlagsAsync));
}

MethodStart<void*> Statement::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Statement>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value Statement::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Statement::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Statement>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value Statement::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> Statement::getInfoStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Statement>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned itemsLength = (unsigned) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> itemsPersistent;
	auto* items = getAddress<unsigned char>(info.Env(), async, info[2], itemsPersistent);
	unsigned bufferLength = (unsigned) info[3].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> bufferPersistent;
	auto* buffer = getAddress<unsigned char>(info.Env(), async, info[4], bufferPersistent);

	return [obj, status, itemsLength, items, itemsPersistent, bufferLength, buffer, bufferPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->getInfo(&statusWrapper, itemsLength, items, bufferLength, buffer);
		return nullptr;
	};
}

Napi::Value Statement::getInfoFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<unsigned> Statement::getTypeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Statement>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getType(&statusWrapper);
	};
}

Napi::Value Statement::getTypeFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> Statement::getPlanStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Statement>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	bool detailed = info[1].ToBoolean();

	return [obj, status, detailed]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getPlan(&statusWrapper, detailed);
	};
}

Napi::Value Statement::getPlanFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<uint64_t> Statement::getAffectedRecordsStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Statement>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getAffectedRecords(&statusWrapper);
	};
}

Napi::Value Statement::getAffectedRecordsFinish(const Napi::Env env, uint64_t ret)
{
	return Napi::Value::From(env, (double) ret);
}

MethodStart<fb::IMessageMetadata*> Statement::getInputMetadataStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Statement>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getInputMetadata(&statusWrapper);
	};
}

Napi::Value Statement::getInputMetadataFinish(const Napi::Env env, fb::IMessageMetadata* ret)
{
	return MessageMetadata::NewInstance(env, ret);
}

MethodStart<fb::IMessageMetadata*> Statement::getOutputMetadataStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Statement>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getOutputMetadata(&statusWrapper);
	};
}

Napi::Value Statement::getOutputMetadataFinish(const Napi::Env env, fb::IMessageMetadata* ret)
{
	return MessageMetadata::NewInstance(env, ret);
}

MethodStart<fb::ITransaction*> Statement::executeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Statement>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info.Env(), info[1], "transaction argument", true);
	auto* inMetadata = MessageMetadata::CheckedUnwrap(info.Env(), info[2], "inMetadata argument", true);
	std::shared_ptr<Napi::Reference<Napi::Value>> inBufferPersistent;
	auto* inBuffer = getAddress<unsigned char>(info.Env(), async, info[3], inBufferPersistent);
	auto* outMetadata = MessageMetadata::CheckedUnwrap(info.Env(), info[4], "outMetadata argument", true);
	std::shared_ptr<Napi::Reference<Napi::Value>> outBufferPersistent;
	auto* outBuffer = getAddress<unsigned char>(info.Env(), async, info[5], outBufferPersistent);

	return [obj, status, transaction, inMetadata, inBuffer, inBufferPersistent, outMetadata, outBuffer, outBufferPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->execute(&statusWrapper, (transaction ? transaction->interface : nullptr), (inMetadata ? inMetadata->interface : nullptr), inBuffer, (outMetadata ? outMetadata->interface : nullptr), outBuffer);
	};
}

Napi::Value Statement::executeFinish(const Napi::Env env, fb::ITransaction* ret)
{
	return Transaction::NewInstance(env, ret);
}

MethodStart<fb::IResultSet*> Statement::openCursorStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Statement>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info.Env(), info[1], "transaction argument", true);
	auto* inMetadata = MessageMetadata::CheckedUnwrap(info.Env(), info[2], "inMetadata argument", true);
	std::shared_ptr<Napi::Reference<Napi::Value>> inBufferPersistent;
	auto* inBuffer = getAddress<unsigned char>(info.Env(), async, info[3], inBufferPersistent);
	auto* outMetadata = MessageMetadata::CheckedUnwrap(info.Env(), info[4], "outMetadata argument", true);
	unsigned flags = (unsigned) info[5].ToNumber();

	return [obj, status, transaction, inMetadata, inBuffer, inBufferPersistent, outMetadata, flags]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->openCursor(&statusWrapper, (transaction ? transaction->interface : nullptr), (inMetadata ? inMetadata->interface : nullptr), inBuffer, (outMetadata ? outMetadata->interface : nullptr), flags);
	};
}

Napi::Value Statement::openCursorFinish(const Napi::Env env, fb::IResultSet* ret)
{
	return ResultSet::NewInstance(env, ret);
}

MethodStart<void*> Statement::setCursorNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Statement>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string name = info[1].ToString().Utf8Value();

	return [obj, status, name]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setCursorName(&statusWrapper, name.c_str());
		return nullptr;
	};
}

Napi::Value Statement::setCursorNameFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Statement::freeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Statement>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->free(&statusWrapper);
		return nullptr;
	};
}

Napi::Value Statement::freeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<unsigned> Statement::getFlagsStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Statement>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getFlags(&statusWrapper);
	};
}

Napi::Value Statement::getFlagsFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

void Request::InitPrototype(std::vector<Napi::ObjectWrap<Request>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &Request::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &Request::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &Request::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &Request::releaseAsync));
	properties.push_back(InstanceMethod("receiveSync", &Request::receiveSync));
	properties.push_back(InstanceMethod("receiveAsync", &Request::receiveAsync));
	properties.push_back(InstanceMethod("sendSync", &Request::sendSync));
	properties.push_back(InstanceMethod("sendAsync", &Request::sendAsync));
	properties.push_back(InstanceMethod("getInfoSync", &Request::getInfoSync));
	properties.push_back(InstanceMethod("getInfoAsync", &Request::getInfoAsync));
	properties.push_back(InstanceMethod("startSync", &Request::startSync));
	properties.push_back(InstanceMethod("startAsync", &Request::startAsync));
	properties.push_back(InstanceMethod("startAndSendSync", &Request::startAndSendSync));
	properties.push_back(InstanceMethod("startAndSendAsync", &Request::startAndSendAsync));
	properties.push_back(InstanceMethod("unwindSync", &Request::unwindSync));
	properties.push_back(InstanceMethod("unwindAsync", &Request::unwindAsync));
	properties.push_back(InstanceMethod("freeSync", &Request::freeSync));
	properties.push_back(InstanceMethod("freeAsync", &Request::freeAsync));
}

MethodStart<void*> Request::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Request>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value Request::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Request::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Request>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value Request::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> Request::receiveStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Request>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	int level = (int) info[1].ToNumber();
	unsigned msgType = (unsigned) info[2].ToNumber();
	unsigned length = (unsigned) info[3].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> messagePersistent;
	auto* message = getAddress<unsigned char>(info.Env(), async, info[4], messagePersistent);

	return [obj, status, level, msgType, length, message, messagePersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->receive(&statusWrapper, level, msgType, length, message);
		return nullptr;
	};
}

Napi::Value Request::receiveFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Request::sendStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Request>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	int level = (int) info[1].ToNumber();
	unsigned msgType = (unsigned) info[2].ToNumber();
	unsigned length = (unsigned) info[3].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> messagePersistent;
	auto* message = getAddress<unsigned char>(info.Env(), async, info[4], messagePersistent);

	return [obj, status, level, msgType, length, message, messagePersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->send(&statusWrapper, level, msgType, length, message);
		return nullptr;
	};
}

Napi::Value Request::sendFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Request::getInfoStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Request>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	int level = (int) info[1].ToNumber();
	unsigned itemsLength = (unsigned) info[2].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> itemsPersistent;
	auto* items = getAddress<unsigned char>(info.Env(), async, info[3], itemsPersistent);
	unsigned bufferLength = (unsigned) info[4].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> bufferPersistent;
	auto* buffer = getAddress<unsigned char>(info.Env(), async, info[5], bufferPersistent);

	return [obj, status, level, itemsLength, items, itemsPersistent, bufferLength, buffer, bufferPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->getInfo(&statusWrapper, level, itemsLength, items, bufferLength, buffer);
		return nullptr;
	};
}

Napi::Value Request::getInfoFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Request::startStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Request>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* tra = Transaction::CheckedUnwrap(info.Env(), info[1], "tra argument", true);
	int level = (int) info[2].ToNumber();

	return [obj, status, tra, level]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->start(&statusWrapper, (tra ? tra->interface : nullptr), level);
		return nullptr;
	};
}

Napi::Value Request::startFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Request::startAndSendStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Request>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* tra = Transaction::CheckedUnwrap(info.Env(), info[1], "tra argument", true);
	int level = (int) info[2].ToNumber();
	unsigned msgType = (unsigned) info[3].ToNumber();
	unsigned length = (unsigned) info[4].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> messagePersistent;
	auto* message = getAddress<unsigned char>(info.Env(), async, info[5], messagePersistent);

	return [obj, status, tra, level, msgType, length, message, messagePersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->startAndSend(&statusWrapper, (tra ? tra->interface : nullptr), level, msgType, length, message);
		return nullptr;
	};
}

Napi::Value Request::startAndSendFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Request::unwindStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Request>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	int level = (int) info[1].ToNumber();

	return [obj, status, level]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->unwind(&statusWrapper, level);
		return nullptr;
	};
}

Napi::Value Request::unwindFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Request::freeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Request>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->free(&statusWrapper);
		return nullptr;
	};
}

Napi::Value Request::freeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void Events::InitPrototype(std::vector<Napi::ObjectWrap<Events>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &Events::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &Events::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &Events::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &Events::releaseAsync));
	properties.push_back(InstanceMethod("cancelSync", &Events::cancelSync));
	properties.push_back(InstanceMethod("cancelAsync", &Events::cancelAsync));
}

MethodStart<void*> Events::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Events>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value Events::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Events::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Events>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value Events::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> Events::cancelStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Events>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->cancel(&statusWrapper);
		return nullptr;
	};
}

Napi::Value Events::cancelFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void Attachment::InitPrototype(std::vector<Napi::ObjectWrap<Attachment>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &Attachment::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &Attachment::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &Attachment::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &Attachment::releaseAsync));
	properties.push_back(InstanceMethod("getInfoSync", &Attachment::getInfoSync));
	properties.push_back(InstanceMethod("getInfoAsync", &Attachment::getInfoAsync));
	properties.push_back(InstanceMethod("startTransactionSync", &Attachment::startTransactionSync));
	properties.push_back(InstanceMethod("startTransactionAsync", &Attachment::startTransactionAsync));
	properties.push_back(InstanceMethod("reconnectTransactionSync", &Attachment::reconnectTransactionSync));
	properties.push_back(InstanceMethod("reconnectTransactionAsync", &Attachment::reconnectTransactionAsync));
	properties.push_back(InstanceMethod("compileRequestSync", &Attachment::compileRequestSync));
	properties.push_back(InstanceMethod("compileRequestAsync", &Attachment::compileRequestAsync));
	properties.push_back(InstanceMethod("transactRequestSync", &Attachment::transactRequestSync));
	properties.push_back(InstanceMethod("transactRequestAsync", &Attachment::transactRequestAsync));
	properties.push_back(InstanceMethod("createBlobSync", &Attachment::createBlobSync));
	properties.push_back(InstanceMethod("createBlobAsync", &Attachment::createBlobAsync));
	properties.push_back(InstanceMethod("openBlobSync", &Attachment::openBlobSync));
	properties.push_back(InstanceMethod("openBlobAsync", &Attachment::openBlobAsync));
	properties.push_back(InstanceMethod("executeDynSync", &Attachment::executeDynSync));
	properties.push_back(InstanceMethod("executeDynAsync", &Attachment::executeDynAsync));
	properties.push_back(InstanceMethod("prepareSync", &Attachment::prepareSync));
	properties.push_back(InstanceMethod("prepareAsync", &Attachment::prepareAsync));
	properties.push_back(InstanceMethod("executeSync", &Attachment::executeSync));
	properties.push_back(InstanceMethod("executeAsync", &Attachment::executeAsync));
	properties.push_back(InstanceMethod("openCursorSync", &Attachment::openCursorSync));
	properties.push_back(InstanceMethod("openCursorAsync", &Attachment::openCursorAsync));
	properties.push_back(InstanceMethod("queEventsSync", &Attachment::queEventsSync));
	properties.push_back(InstanceMethod("queEventsAsync", &Attachment::queEventsAsync));
	properties.push_back(InstanceMethod("cancelOperationSync", &Attachment::cancelOperationSync));
	properties.push_back(InstanceMethod("cancelOperationAsync", &Attachment::cancelOperationAsync));
	properties.push_back(InstanceMethod("pingSync", &Attachment::pingSync));
	properties.push_back(InstanceMethod("pingAsync", &Attachment::pingAsync));
	properties.push_back(InstanceMethod("detachSync", &Attachment::detachSync));
	properties.push_back(InstanceMethod("detachAsync", &Attachment::detachAsync));
	properties.push_back(InstanceMethod("dropDatabaseSync", &Attachment::dropDatabaseSync));
	properties.push_back(InstanceMethod("dropDatabaseAsync", &Attachment::dropDatabaseAsync));
}

MethodStart<void*> Attachment::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value Attachment::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Attachment::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value Attachment::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> Attachment::getInfoStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned itemsLength = (unsigned) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> itemsPersistent;
	auto* items = getAddress<unsigned char>(info.Env(), async, info[2], itemsPersistent);
	unsigned bufferLength = (unsigned) info[3].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> bufferPersistent;
	auto* buffer = getAddress<unsigned char>(info.Env(), async, info[4], bufferPersistent);

	return [obj, status, itemsLength, items, itemsPersistent, bufferLength, buffer, bufferPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->getInfo(&statusWrapper, itemsLength, items, bufferLength, buffer);
		return nullptr;
	};
}

Napi::Value Attachment::getInfoFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::ITransaction*> Attachment::startTransactionStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned tpbLength = (unsigned) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> tpbPersistent;
	auto* tpb = getAddress<unsigned char>(info.Env(), async, info[2], tpbPersistent);

	return [obj, status, tpbLength, tpb, tpbPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->startTransaction(&statusWrapper, tpbLength, tpb);
	};
}

Napi::Value Attachment::startTransactionFinish(const Napi::Env env, fb::ITransaction* ret)
{
	return Transaction::NewInstance(env, ret);
}

MethodStart<fb::ITransaction*> Attachment::reconnectTransactionStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned length = (unsigned) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> idPersistent;
	auto* id = getAddress<unsigned char>(info.Env(), async, info[2], idPersistent);

	return [obj, status, length, id, idPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->reconnectTransaction(&statusWrapper, length, id);
	};
}

Napi::Value Attachment::reconnectTransactionFinish(const Napi::Env env, fb::ITransaction* ret)
{
	return Transaction::NewInstance(env, ret);
}

MethodStart<fb::IRequest*> Attachment::compileRequestStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned blrLength = (unsigned) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> blrPersistent;
	auto* blr = getAddress<unsigned char>(info.Env(), async, info[2], blrPersistent);

	return [obj, status, blrLength, blr, blrPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->compileRequest(&statusWrapper, blrLength, blr);
	};
}

Napi::Value Attachment::compileRequestFinish(const Napi::Env env, fb::IRequest* ret)
{
	return Request::NewInstance(env, ret);
}

MethodStart<void*> Attachment::transactRequestStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info.Env(), info[1], "transaction argument", true);
	unsigned blrLength = (unsigned) info[2].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> blrPersistent;
	auto* blr = getAddress<unsigned char>(info.Env(), async, info[3], blrPersistent);
	unsigned inMsgLength = (unsigned) info[4].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> inMsgPersistent;
	auto* inMsg = getAddress<unsigned char>(info.Env(), async, info[5], inMsgPersistent);
	unsigned outMsgLength = (unsigned) info[6].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> outMsgPersistent;
	auto* outMsg = getAddress<unsigned char>(info.Env(), async, info[7], outMsgPersistent);

	return [obj, status, transaction, blrLength, blr, blrPersistent, inMsgLength, inMsg, inMsgPersistent, outMsgLength, outMsg, outMsgPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->transactRequest(&statusWrapper, (transaction ? transaction->interface : nullptr), blrLength, blr, inMsgLength, inMsg, outMsgLength, outMsg);
		return nullptr;
	};
}

Napi::Value Attachment::transactRequestFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IBlob*> Attachment::createBlobStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info.Env(), info[1], "transaction argument", true);
	std::shared_ptr<Napi::Reference<Napi::Value>> idPersistent;
	auto* id = (ISC_QUAD*) getAddress<unsigned char>(info.Env(), async, info[2], idPersistent);
	unsigned bpbLength = (unsigned) info[3].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> bpbPersistent;
	auto* bpb = getAddress<unsigned char>(info.Env(), async, info[4], bpbPersistent);

	return [obj, status, transaction, id, idPersistent, bpbLength, bpb, bpbPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->createBlob(&statusWrapper, (transaction ? transaction->interface : nullptr), id, bpbLength, bpb);
	};
}

Napi::Value Attachment::createBlobFinish(const Napi::Env env, fb::IBlob* ret)
{
	return Blob::NewInstance(env, ret);
}

MethodStart<fb::IBlob*> Attachment::openBlobStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info.Env(), info[1], "transaction argument", true);
	std::shared_ptr<Napi::Reference<Napi::Value>> idPersistent;
	auto* id = (ISC_QUAD*) getAddress<unsigned char>(info.Env(), async, info[2], idPersistent);
	unsigned bpbLength = (unsigned) info[3].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> bpbPersistent;
	auto* bpb = getAddress<unsigned char>(info.Env(), async, info[4], bpbPersistent);

	return [obj, status, transaction, id, idPersistent, bpbLength, bpb, bpbPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->openBlob(&statusWrapper, (transaction ? transaction->interface : nullptr), id, bpbLength, bpb);
	};
}

Napi::Value Attachment::openBlobFinish(const Napi::Env env, fb::IBlob* ret)
{
	return Blob::NewInstance(env, ret);
}

MethodStart<void*> Attachment::executeDynStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info.Env(), info[1], "transaction argument", true);
	unsigned length = (unsigned) info[2].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> dynPersistent;
	auto* dyn = getAddress<unsigned char>(info.Env(), async, info[3], dynPersistent);

	return [obj, status, transaction, length, dyn, dynPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->executeDyn(&statusWrapper, (transaction ? transaction->interface : nullptr), length, dyn);
		return nullptr;
	};
}

Napi::Value Attachment::executeDynFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IStatement*> Attachment::prepareStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* tra = Transaction::CheckedUnwrap(info.Env(), info[1], "tra argument", true);
	unsigned stmtLength = (unsigned) info[2].ToNumber();
	std::string sqlStmt = info[3].ToString().Utf8Value();
	unsigned dialect = (unsigned) info[4].ToNumber();
	unsigned flags = (unsigned) info[5].ToNumber();

	return [obj, status, tra, stmtLength, sqlStmt, dialect, flags]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->prepare(&statusWrapper, (tra ? tra->interface : nullptr), stmtLength, sqlStmt.c_str(), dialect, flags);
	};
}

Napi::Value Attachment::prepareFinish(const Napi::Env env, fb::IStatement* ret)
{
	return Statement::NewInstance(env, ret);
}

MethodStart<fb::ITransaction*> Attachment::executeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info.Env(), info[1], "transaction argument", true);
	unsigned stmtLength = (unsigned) info[2].ToNumber();
	std::string sqlStmt = info[3].ToString().Utf8Value();
	unsigned dialect = (unsigned) info[4].ToNumber();
	auto* inMetadata = MessageMetadata::CheckedUnwrap(info.Env(), info[5], "inMetadata argument", true);
	std::shared_ptr<Napi::Reference<Napi::Value>> inBufferPersistent;
	auto* inBuffer = getAddress<unsigned char>(info.Env(), async, info[6], inBufferPersistent);
	auto* outMetadata = MessageMetadata::CheckedUnwrap(info.Env(), info[7], "outMetadata argument", true);
	std::shared_ptr<Napi::Reference<Napi::Value>> outBufferPersistent;
	auto* outBuffer = getAddress<unsigned char>(info.Env(), async, info[8], outBufferPersistent);

	return [obj, status, transaction, stmtLength, sqlStmt, dialect, inMetadata, inBuffer, inBufferPersistent, outMetadata, outBuffer, outBufferPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->execute(&statusWrapper, (transaction ? transaction->interface : nullptr), stmtLength, sqlStmt.c_str(), dialect, (inMetadata ? inMetadata->interface : nullptr), inBuffer, (outMetadata ? outMetadata->interface : nullptr), outBuffer);
	};
}

Napi::Value Attachment::executeFinish(const Napi::Env env, fb::ITransaction* ret)
{
	return Transaction::NewInstance(env, ret);
}

MethodStart<fb::IResultSet*> Attachment::openCursorStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info.Env(), info[1], "transaction argument", true);
	unsigned stmtLength = (unsigned) info[2].ToNumber();
	std::string sqlStmt = info[3].ToString().Utf8Value();
	unsigned dialect = (unsigned) info[4].ToNumber();
	auto* inMetadata = MessageMetadata::CheckedUnwrap(info.Env(), info[5], "inMetadata argument", true);
	std::shared_ptr<Napi::Reference<Napi::Value>> inBufferPersistent;
	auto* inBuffer = getAddress<unsigned char>(info.Env(), async, info[6], inBufferPersistent);
	auto* outMetadata = MessageMetadata::CheckedUnwrap(info.Env(), info[7], "outMetadata argument", true);
	std::string cursorName = info[8].ToString().Utf8Value();
	unsigned cursorFlags = (unsigned) info[9].ToNumber();

	return [obj, status, transaction, stmtLength, sqlStmt, dialect, inMetadata, inBuffer, inBufferPersistent, outMetadata, cursorName, cursorFlags]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->openCursor(&statusWrapper, (transaction ? transaction->interface : nullptr), stmtLength, sqlStmt.c_str(), dialect, (inMetadata ? inMetadata->interface : nullptr), inBuffer, (outMetadata ? outMetadata->interface : nullptr), cursorName.c_str(), cursorFlags);
	};
}

Napi::Value Attachment::openCursorFinish(const Napi::Env env, fb::IResultSet* ret)
{
	return ResultSet::NewInstance(env, ret);
}

MethodStart<fb::IEvents*> Attachment::queEventsStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* callback = EventCallback::CheckedUnwrap(info.Env(), info[1], "callback argument", true);
	unsigned length = (unsigned) info[2].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> eventsPersistent;
	auto* events = getAddress<unsigned char>(info.Env(), async, info[3], eventsPersistent);

	return [obj, status, callback, length, events, eventsPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->queEvents(&statusWrapper, (callback ? callback->interface : nullptr), length, events);
	};
}

Napi::Value Attachment::queEventsFinish(const Napi::Env env, fb::IEvents* ret)
{
	return Events::NewInstance(env, ret);
}

MethodStart<void*> Attachment::cancelOperationStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	int option = (int) info[1].ToNumber();

	return [obj, status, option]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->cancelOperation(&statusWrapper, option);
		return nullptr;
	};
}

Napi::Value Attachment::cancelOperationFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Attachment::pingStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->ping(&statusWrapper);
		return nullptr;
	};
}

Napi::Value Attachment::pingFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Attachment::detachStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->detach(&statusWrapper);
		return nullptr;
	};
}

Napi::Value Attachment::detachFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Attachment::dropDatabaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Attachment>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->dropDatabase(&statusWrapper);
		return nullptr;
	};
}

Napi::Value Attachment::dropDatabaseFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void Service::InitPrototype(std::vector<Napi::ObjectWrap<Service>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &Service::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &Service::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &Service::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &Service::releaseAsync));
	properties.push_back(InstanceMethod("detachSync", &Service::detachSync));
	properties.push_back(InstanceMethod("detachAsync", &Service::detachAsync));
	properties.push_back(InstanceMethod("querySync", &Service::querySync));
	properties.push_back(InstanceMethod("queryAsync", &Service::queryAsync));
	properties.push_back(InstanceMethod("startSync", &Service::startSync));
	properties.push_back(InstanceMethod("startAsync", &Service::startAsync));
}

MethodStart<void*> Service::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Service>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value Service::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Service::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Service>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value Service::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> Service::detachStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Service>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->detach(&statusWrapper);
		return nullptr;
	};
}

Napi::Value Service::detachFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Service::queryStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Service>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned sendLength = (unsigned) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> sendItemsPersistent;
	auto* sendItems = getAddress<unsigned char>(info.Env(), async, info[2], sendItemsPersistent);
	unsigned receiveLength = (unsigned) info[3].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> receiveItemsPersistent;
	auto* receiveItems = getAddress<unsigned char>(info.Env(), async, info[4], receiveItemsPersistent);
	unsigned bufferLength = (unsigned) info[5].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> bufferPersistent;
	auto* buffer = getAddress<unsigned char>(info.Env(), async, info[6], bufferPersistent);

	return [obj, status, sendLength, sendItems, sendItemsPersistent, receiveLength, receiveItems, receiveItemsPersistent, bufferLength, buffer, bufferPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->query(&statusWrapper, sendLength, sendItems, receiveLength, receiveItems, bufferLength, buffer);
		return nullptr;
	};
}

Napi::Value Service::queryFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Service::startStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Service>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned spbLength = (unsigned) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> spbPersistent;
	auto* spb = getAddress<unsigned char>(info.Env(), async, info[2], spbPersistent);

	return [obj, status, spbLength, spb, spbPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->start(&statusWrapper, spbLength, spb);
		return nullptr;
	};
}

Napi::Value Service::startFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void Provider::InitPrototype(std::vector<Napi::ObjectWrap<Provider>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &Provider::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &Provider::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &Provider::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &Provider::releaseAsync));
	properties.push_back(InstanceMethod("setOwnerSync", &Provider::setOwnerSync));
	properties.push_back(InstanceMethod("setOwnerAsync", &Provider::setOwnerAsync));
	properties.push_back(InstanceMethod("getOwnerSync", &Provider::getOwnerSync));
	properties.push_back(InstanceMethod("getOwnerAsync", &Provider::getOwnerAsync));
	properties.push_back(InstanceMethod("attachDatabaseSync", &Provider::attachDatabaseSync));
	properties.push_back(InstanceMethod("attachDatabaseAsync", &Provider::attachDatabaseAsync));
	properties.push_back(InstanceMethod("createDatabaseSync", &Provider::createDatabaseSync));
	properties.push_back(InstanceMethod("createDatabaseAsync", &Provider::createDatabaseAsync));
	properties.push_back(InstanceMethod("attachServiceManagerSync", &Provider::attachServiceManagerSync));
	properties.push_back(InstanceMethod("attachServiceManagerAsync", &Provider::attachServiceManagerAsync));
	properties.push_back(InstanceMethod("shutdownSync", &Provider::shutdownSync));
	properties.push_back(InstanceMethod("shutdownAsync", &Provider::shutdownAsync));
	properties.push_back(InstanceMethod("setDbCryptCallbackSync", &Provider::setDbCryptCallbackSync));
	properties.push_back(InstanceMethod("setDbCryptCallbackAsync", &Provider::setDbCryptCallbackAsync));
}

MethodStart<void*> Provider::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Provider>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value Provider::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Provider::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Provider>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value Provider::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> Provider::setOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Provider>::Unwrap(info.This().ToObject());
	auto* r = ReferenceCounted::CheckedUnwrap(info.Env(), info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

Napi::Value Provider::setOwnerFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IReferenceCounted*> Provider::getOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Provider>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

Napi::Value Provider::getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(env, ret);
}

MethodStart<fb::IAttachment*> Provider::attachDatabaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Provider>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string fileName = info[1].ToString().Utf8Value();
	unsigned dpbLength = (unsigned) info[2].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> dpbPersistent;
	auto* dpb = getAddress<unsigned char>(info.Env(), async, info[3], dpbPersistent);

	return [obj, status, fileName, dpbLength, dpb, dpbPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->attachDatabase(&statusWrapper, fileName.c_str(), dpbLength, dpb);
	};
}

Napi::Value Provider::attachDatabaseFinish(const Napi::Env env, fb::IAttachment* ret)
{
	return Attachment::NewInstance(env, ret);
}

MethodStart<fb::IAttachment*> Provider::createDatabaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Provider>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string fileName = info[1].ToString().Utf8Value();
	unsigned dpbLength = (unsigned) info[2].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> dpbPersistent;
	auto* dpb = getAddress<unsigned char>(info.Env(), async, info[3], dpbPersistent);

	return [obj, status, fileName, dpbLength, dpb, dpbPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->createDatabase(&statusWrapper, fileName.c_str(), dpbLength, dpb);
	};
}

Napi::Value Provider::createDatabaseFinish(const Napi::Env env, fb::IAttachment* ret)
{
	return Attachment::NewInstance(env, ret);
}

MethodStart<fb::IService*> Provider::attachServiceManagerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Provider>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string service = info[1].ToString().Utf8Value();
	unsigned spbLength = (unsigned) info[2].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> spbPersistent;
	auto* spb = getAddress<unsigned char>(info.Env(), async, info[3], spbPersistent);

	return [obj, status, service, spbLength, spb, spbPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->attachServiceManager(&statusWrapper, service.c_str(), spbLength, spb);
	};
}

Napi::Value Provider::attachServiceManagerFinish(const Napi::Env env, fb::IService* ret)
{
	return Service::NewInstance(env, ret);
}

MethodStart<void*> Provider::shutdownStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Provider>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned timeout = (unsigned) info[1].ToNumber();
	int reason = (int) info[2].ToNumber();

	return [obj, status, timeout, reason]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->shutdown(&statusWrapper, timeout, reason);
		return nullptr;
	};
}

Napi::Value Provider::shutdownFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Provider::setDbCryptCallbackStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Provider>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* cryptCallback = CryptKeyCallback::CheckedUnwrap(info.Env(), info[1], "cryptCallback argument", true);

	return [obj, status, cryptCallback]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setDbCryptCallback(&statusWrapper, (cryptCallback ? cryptCallback->interface : nullptr));
		return nullptr;
	};
}

Napi::Value Provider::setDbCryptCallbackFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void DtcStart::InitPrototype(std::vector<Napi::ObjectWrap<DtcStart>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("disposeSync", &DtcStart::disposeSync));
	properties.push_back(InstanceMethod("disposeAsync", &DtcStart::disposeAsync));
	properties.push_back(InstanceMethod("addAttachmentSync", &DtcStart::addAttachmentSync));
	properties.push_back(InstanceMethod("addAttachmentAsync", &DtcStart::addAttachmentAsync));
	properties.push_back(InstanceMethod("addWithTpbSync", &DtcStart::addWithTpbSync));
	properties.push_back(InstanceMethod("addWithTpbAsync", &DtcStart::addWithTpbAsync));
	properties.push_back(InstanceMethod("startSync", &DtcStart::startSync));
	properties.push_back(InstanceMethod("startAsync", &DtcStart::startAsync));
}

MethodStart<void*> DtcStart::disposeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<DtcStart>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

Napi::Value DtcStart::disposeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> DtcStart::addAttachmentStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<DtcStart>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* att = Attachment::CheckedUnwrap(info.Env(), info[1], "att argument", true);

	return [obj, status, att]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->addAttachment(&statusWrapper, (att ? att->interface : nullptr));
		return nullptr;
	};
}

Napi::Value DtcStart::addAttachmentFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> DtcStart::addWithTpbStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<DtcStart>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* att = Attachment::CheckedUnwrap(info.Env(), info[1], "att argument", true);
	unsigned length = (unsigned) info[2].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> tpbPersistent;
	auto* tpb = getAddress<unsigned char>(info.Env(), async, info[3], tpbPersistent);

	return [obj, status, att, length, tpb, tpbPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->addWithTpb(&statusWrapper, (att ? att->interface : nullptr), length, tpb);
		return nullptr;
	};
}

Napi::Value DtcStart::addWithTpbFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::ITransaction*> DtcStart::startStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<DtcStart>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->start(&statusWrapper);
	};
}

Napi::Value DtcStart::startFinish(const Napi::Env env, fb::ITransaction* ret)
{
	return Transaction::NewInstance(env, ret);
}

void Dtc::InitPrototype(std::vector<Napi::ObjectWrap<Dtc>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("joinSync", &Dtc::joinSync));
	properties.push_back(InstanceMethod("joinAsync", &Dtc::joinAsync));
	properties.push_back(InstanceMethod("startBuilderSync", &Dtc::startBuilderSync));
	properties.push_back(InstanceMethod("startBuilderAsync", &Dtc::startBuilderAsync));
}

MethodStart<fb::ITransaction*> Dtc::joinStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Dtc>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* one = Transaction::CheckedUnwrap(info.Env(), info[1], "one argument", true);
	auto* two = Transaction::CheckedUnwrap(info.Env(), info[2], "two argument", true);

	return [obj, status, one, two]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->join(&statusWrapper, (one ? one->interface : nullptr), (two ? two->interface : nullptr));
	};
}

Napi::Value Dtc::joinFinish(const Napi::Env env, fb::ITransaction* ret)
{
	return Transaction::NewInstance(env, ret);
}

MethodStart<fb::IDtcStart*> Dtc::startBuilderStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Dtc>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->startBuilder(&statusWrapper);
	};
}

Napi::Value Dtc::startBuilderFinish(const Napi::Env env, fb::IDtcStart* ret)
{
	return DtcStart::NewInstance(env, ret);
}

void Auth::InitPrototype(std::vector<Napi::ObjectWrap<Auth>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &Auth::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &Auth::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &Auth::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &Auth::releaseAsync));
	properties.push_back(InstanceMethod("setOwnerSync", &Auth::setOwnerSync));
	properties.push_back(InstanceMethod("setOwnerAsync", &Auth::setOwnerAsync));
	properties.push_back(InstanceMethod("getOwnerSync", &Auth::getOwnerSync));
	properties.push_back(InstanceMethod("getOwnerAsync", &Auth::getOwnerAsync));
}

MethodStart<void*> Auth::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Auth>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value Auth::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Auth::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Auth>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value Auth::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> Auth::setOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Auth>::Unwrap(info.This().ToObject());
	auto* r = ReferenceCounted::CheckedUnwrap(info.Env(), info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

Napi::Value Auth::setOwnerFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IReferenceCounted*> Auth::getOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Auth>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

Napi::Value Auth::getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(env, ret);
}

void Writer::InitPrototype(std::vector<Napi::ObjectWrap<Writer>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("resetSync", &Writer::resetSync));
	properties.push_back(InstanceMethod("resetAsync", &Writer::resetAsync));
	properties.push_back(InstanceMethod("addSync", &Writer::addSync));
	properties.push_back(InstanceMethod("addAsync", &Writer::addAsync));
	properties.push_back(InstanceMethod("setTypeSync", &Writer::setTypeSync));
	properties.push_back(InstanceMethod("setTypeAsync", &Writer::setTypeAsync));
	properties.push_back(InstanceMethod("setDbSync", &Writer::setDbSync));
	properties.push_back(InstanceMethod("setDbAsync", &Writer::setDbAsync));
}

MethodStart<void*> Writer::resetStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Writer>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->reset();
		return nullptr;
	};
}

Napi::Value Writer::resetFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Writer::addStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Writer>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string name = info[1].ToString().Utf8Value();

	return [obj, status, name]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->add(&statusWrapper, name.c_str());
		return nullptr;
	};
}

Napi::Value Writer::addFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Writer::setTypeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Writer>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string value = info[1].ToString().Utf8Value();

	return [obj, status, value]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setType(&statusWrapper, value.c_str());
		return nullptr;
	};
}

Napi::Value Writer::setTypeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Writer::setDbStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Writer>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string value = info[1].ToString().Utf8Value();

	return [obj, status, value]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setDb(&statusWrapper, value.c_str());
		return nullptr;
	};
}

Napi::Value Writer::setDbFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void ServerBlock::InitPrototype(std::vector<Napi::ObjectWrap<ServerBlock>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("getLoginSync", &ServerBlock::getLoginSync));
	properties.push_back(InstanceMethod("getLoginAsync", &ServerBlock::getLoginAsync));
	properties.push_back(InstanceMethod("getDataSync", &ServerBlock::getDataSync));
	properties.push_back(InstanceMethod("getDataAsync", &ServerBlock::getDataAsync));
	properties.push_back(InstanceMethod("putDataSync", &ServerBlock::putDataSync));
	properties.push_back(InstanceMethod("putDataAsync", &ServerBlock::putDataAsync));
	properties.push_back(InstanceMethod("newKeySync", &ServerBlock::newKeySync));
	properties.push_back(InstanceMethod("newKeyAsync", &ServerBlock::newKeyAsync));
}

MethodStart<std::string> ServerBlock::getLoginStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ServerBlock>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getLogin();
	};
}

Napi::Value ServerBlock::getLoginFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<const unsigned char*> ServerBlock::getDataStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ServerBlock>::Unwrap(info.This().ToObject());
	std::shared_ptr<Napi::Reference<Napi::Value>> lengthPersistent;
	auto* length = getAddress<unsigned>(info.Env(), async, info[0], lengthPersistent);

	return [obj, length, lengthPersistent]() {
		return obj->interface->getData(length);
	};
}

Napi::Value ServerBlock::getDataFinish(const Napi::Env env, const unsigned char* ret)
{
	return Pointer::NewInstance(env, ret);
}

MethodStart<void*> ServerBlock::putDataStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ServerBlock>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned length = (unsigned) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> dataPersistent;
	auto* data = getAddress<unsigned char>(info.Env(), async, info[2], dataPersistent);

	return [obj, status, length, data, dataPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->putData(&statusWrapper, length, data);
		return nullptr;
	};
}

Napi::Value ServerBlock::putDataFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::ICryptKey*> ServerBlock::newKeyStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ServerBlock>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->newKey(&statusWrapper);
	};
}

Napi::Value ServerBlock::newKeyFinish(const Napi::Env env, fb::ICryptKey* ret)
{
	return CryptKey::NewInstance(env, ret);
}

void ClientBlock::InitPrototype(std::vector<Napi::ObjectWrap<ClientBlock>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &ClientBlock::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &ClientBlock::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &ClientBlock::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &ClientBlock::releaseAsync));
	properties.push_back(InstanceMethod("getLoginSync", &ClientBlock::getLoginSync));
	properties.push_back(InstanceMethod("getLoginAsync", &ClientBlock::getLoginAsync));
	properties.push_back(InstanceMethod("getPasswordSync", &ClientBlock::getPasswordSync));
	properties.push_back(InstanceMethod("getPasswordAsync", &ClientBlock::getPasswordAsync));
	properties.push_back(InstanceMethod("getDataSync", &ClientBlock::getDataSync));
	properties.push_back(InstanceMethod("getDataAsync", &ClientBlock::getDataAsync));
	properties.push_back(InstanceMethod("putDataSync", &ClientBlock::putDataSync));
	properties.push_back(InstanceMethod("putDataAsync", &ClientBlock::putDataAsync));
	properties.push_back(InstanceMethod("newKeySync", &ClientBlock::newKeySync));
	properties.push_back(InstanceMethod("newKeyAsync", &ClientBlock::newKeyAsync));
}

MethodStart<void*> ClientBlock::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ClientBlock>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value ClientBlock::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> ClientBlock::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ClientBlock>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value ClientBlock::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> ClientBlock::getLoginStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ClientBlock>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getLogin();
	};
}

Napi::Value ClientBlock::getLoginFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> ClientBlock::getPasswordStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ClientBlock>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getPassword();
	};
}

Napi::Value ClientBlock::getPasswordFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<const unsigned char*> ClientBlock::getDataStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ClientBlock>::Unwrap(info.This().ToObject());
	std::shared_ptr<Napi::Reference<Napi::Value>> lengthPersistent;
	auto* length = getAddress<unsigned>(info.Env(), async, info[0], lengthPersistent);

	return [obj, length, lengthPersistent]() {
		return obj->interface->getData(length);
	};
}

Napi::Value ClientBlock::getDataFinish(const Napi::Env env, const unsigned char* ret)
{
	return Pointer::NewInstance(env, ret);
}

MethodStart<void*> ClientBlock::putDataStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ClientBlock>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned length = (unsigned) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> dataPersistent;
	auto* data = getAddress<unsigned char>(info.Env(), async, info[2], dataPersistent);

	return [obj, status, length, data, dataPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->putData(&statusWrapper, length, data);
		return nullptr;
	};
}

Napi::Value ClientBlock::putDataFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::ICryptKey*> ClientBlock::newKeyStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ClientBlock>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->newKey(&statusWrapper);
	};
}

Napi::Value ClientBlock::newKeyFinish(const Napi::Env env, fb::ICryptKey* ret)
{
	return CryptKey::NewInstance(env, ret);
}

void Server::InitPrototype(std::vector<Napi::ObjectWrap<Server>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &Server::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &Server::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &Server::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &Server::releaseAsync));
	properties.push_back(InstanceMethod("setOwnerSync", &Server::setOwnerSync));
	properties.push_back(InstanceMethod("setOwnerAsync", &Server::setOwnerAsync));
	properties.push_back(InstanceMethod("getOwnerSync", &Server::getOwnerSync));
	properties.push_back(InstanceMethod("getOwnerAsync", &Server::getOwnerAsync));
	properties.push_back(InstanceMethod("authenticateSync", &Server::authenticateSync));
	properties.push_back(InstanceMethod("authenticateAsync", &Server::authenticateAsync));
}

MethodStart<void*> Server::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Server>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value Server::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Server::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Server>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value Server::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> Server::setOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Server>::Unwrap(info.This().ToObject());
	auto* r = ReferenceCounted::CheckedUnwrap(info.Env(), info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

Napi::Value Server::setOwnerFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IReferenceCounted*> Server::getOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Server>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

Napi::Value Server::getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(env, ret);
}

MethodStart<int> Server::authenticateStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Server>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* sBlock = ServerBlock::CheckedUnwrap(info.Env(), info[1], "sBlock argument", true);
	auto* writerInterface = Writer::CheckedUnwrap(info.Env(), info[2], "writerInterface argument", true);

	return [obj, status, sBlock, writerInterface]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->authenticate(&statusWrapper, (sBlock ? sBlock->interface : nullptr), (writerInterface ? writerInterface->interface : nullptr));
	};
}

Napi::Value Server::authenticateFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

void Client::InitPrototype(std::vector<Napi::ObjectWrap<Client>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &Client::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &Client::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &Client::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &Client::releaseAsync));
	properties.push_back(InstanceMethod("setOwnerSync", &Client::setOwnerSync));
	properties.push_back(InstanceMethod("setOwnerAsync", &Client::setOwnerAsync));
	properties.push_back(InstanceMethod("getOwnerSync", &Client::getOwnerSync));
	properties.push_back(InstanceMethod("getOwnerAsync", &Client::getOwnerAsync));
	properties.push_back(InstanceMethod("authenticateSync", &Client::authenticateSync));
	properties.push_back(InstanceMethod("authenticateAsync", &Client::authenticateAsync));
}

MethodStart<void*> Client::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Client>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value Client::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Client::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Client>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value Client::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> Client::setOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Client>::Unwrap(info.This().ToObject());
	auto* r = ReferenceCounted::CheckedUnwrap(info.Env(), info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

Napi::Value Client::setOwnerFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IReferenceCounted*> Client::getOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Client>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

Napi::Value Client::getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(env, ret);
}

MethodStart<int> Client::authenticateStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Client>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* cBlock = ClientBlock::CheckedUnwrap(info.Env(), info[1], "cBlock argument", true);

	return [obj, status, cBlock]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->authenticate(&statusWrapper, (cBlock ? cBlock->interface : nullptr));
	};
}

Napi::Value Client::authenticateFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

void UserField::InitPrototype(std::vector<Napi::ObjectWrap<UserField>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("enteredSync", &UserField::enteredSync));
	properties.push_back(InstanceMethod("enteredAsync", &UserField::enteredAsync));
	properties.push_back(InstanceMethod("specifiedSync", &UserField::specifiedSync));
	properties.push_back(InstanceMethod("specifiedAsync", &UserField::specifiedAsync));
	properties.push_back(InstanceMethod("setEnteredSync", &UserField::setEnteredSync));
	properties.push_back(InstanceMethod("setEnteredAsync", &UserField::setEnteredAsync));
}

MethodStart<int> UserField::enteredStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<UserField>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->entered();
	};
}

Napi::Value UserField::enteredFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> UserField::specifiedStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<UserField>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->specified();
	};
}

Napi::Value UserField::specifiedFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> UserField::setEnteredStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<UserField>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	int newValue = (int) info[1].ToNumber();

	return [obj, status, newValue]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setEntered(&statusWrapper, newValue);
		return nullptr;
	};
}

Napi::Value UserField::setEnteredFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void CharUserField::InitPrototype(std::vector<Napi::ObjectWrap<CharUserField>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("enteredSync", &CharUserField::enteredSync));
	properties.push_back(InstanceMethod("enteredAsync", &CharUserField::enteredAsync));
	properties.push_back(InstanceMethod("specifiedSync", &CharUserField::specifiedSync));
	properties.push_back(InstanceMethod("specifiedAsync", &CharUserField::specifiedAsync));
	properties.push_back(InstanceMethod("setEnteredSync", &CharUserField::setEnteredSync));
	properties.push_back(InstanceMethod("setEnteredAsync", &CharUserField::setEnteredAsync));
	properties.push_back(InstanceMethod("getSync", &CharUserField::getSync));
	properties.push_back(InstanceMethod("getAsync", &CharUserField::getAsync));
	properties.push_back(InstanceMethod("setSync", &CharUserField::setSync));
	properties.push_back(InstanceMethod("setAsync", &CharUserField::setAsync));
}

MethodStart<int> CharUserField::enteredStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<CharUserField>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->entered();
	};
}

Napi::Value CharUserField::enteredFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> CharUserField::specifiedStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<CharUserField>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->specified();
	};
}

Napi::Value CharUserField::specifiedFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> CharUserField::setEnteredStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<CharUserField>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	int newValue = (int) info[1].ToNumber();

	return [obj, status, newValue]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setEntered(&statusWrapper, newValue);
		return nullptr;
	};
}

Napi::Value CharUserField::setEnteredFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<std::string> CharUserField::getStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<CharUserField>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->get();
	};
}

Napi::Value CharUserField::getFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> CharUserField::setStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<CharUserField>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string newValue = info[1].ToString().Utf8Value();

	return [obj, status, newValue]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->set(&statusWrapper, newValue.c_str());
		return nullptr;
	};
}

Napi::Value CharUserField::setFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void IntUserField::InitPrototype(std::vector<Napi::ObjectWrap<IntUserField>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("enteredSync", &IntUserField::enteredSync));
	properties.push_back(InstanceMethod("enteredAsync", &IntUserField::enteredAsync));
	properties.push_back(InstanceMethod("specifiedSync", &IntUserField::specifiedSync));
	properties.push_back(InstanceMethod("specifiedAsync", &IntUserField::specifiedAsync));
	properties.push_back(InstanceMethod("setEnteredSync", &IntUserField::setEnteredSync));
	properties.push_back(InstanceMethod("setEnteredAsync", &IntUserField::setEnteredAsync));
	properties.push_back(InstanceMethod("getSync", &IntUserField::getSync));
	properties.push_back(InstanceMethod("getAsync", &IntUserField::getAsync));
	properties.push_back(InstanceMethod("setSync", &IntUserField::setSync));
	properties.push_back(InstanceMethod("setAsync", &IntUserField::setAsync));
}

MethodStart<int> IntUserField::enteredStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<IntUserField>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->entered();
	};
}

Napi::Value IntUserField::enteredFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> IntUserField::specifiedStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<IntUserField>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->specified();
	};
}

Napi::Value IntUserField::specifiedFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> IntUserField::setEnteredStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<IntUserField>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	int newValue = (int) info[1].ToNumber();

	return [obj, status, newValue]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setEntered(&statusWrapper, newValue);
		return nullptr;
	};
}

Napi::Value IntUserField::setEnteredFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> IntUserField::getStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<IntUserField>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->get();
	};
}

Napi::Value IntUserField::getFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> IntUserField::setStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<IntUserField>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	int newValue = (int) info[1].ToNumber();

	return [obj, status, newValue]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->set(&statusWrapper, newValue);
		return nullptr;
	};
}

Napi::Value IntUserField::setFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void User::InitPrototype(std::vector<Napi::ObjectWrap<User>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("operationSync", &User::operationSync));
	properties.push_back(InstanceMethod("operationAsync", &User::operationAsync));
	properties.push_back(InstanceMethod("userNameSync", &User::userNameSync));
	properties.push_back(InstanceMethod("userNameAsync", &User::userNameAsync));
	properties.push_back(InstanceMethod("passwordSync", &User::passwordSync));
	properties.push_back(InstanceMethod("passwordAsync", &User::passwordAsync));
	properties.push_back(InstanceMethod("firstNameSync", &User::firstNameSync));
	properties.push_back(InstanceMethod("firstNameAsync", &User::firstNameAsync));
	properties.push_back(InstanceMethod("lastNameSync", &User::lastNameSync));
	properties.push_back(InstanceMethod("lastNameAsync", &User::lastNameAsync));
	properties.push_back(InstanceMethod("middleNameSync", &User::middleNameSync));
	properties.push_back(InstanceMethod("middleNameAsync", &User::middleNameAsync));
	properties.push_back(InstanceMethod("commentSync", &User::commentSync));
	properties.push_back(InstanceMethod("commentAsync", &User::commentAsync));
	properties.push_back(InstanceMethod("attributesSync", &User::attributesSync));
	properties.push_back(InstanceMethod("attributesAsync", &User::attributesAsync));
	properties.push_back(InstanceMethod("activeSync", &User::activeSync));
	properties.push_back(InstanceMethod("activeAsync", &User::activeAsync));
	properties.push_back(InstanceMethod("adminSync", &User::adminSync));
	properties.push_back(InstanceMethod("adminAsync", &User::adminAsync));
	properties.push_back(InstanceMethod("clearSync", &User::clearSync));
	properties.push_back(InstanceMethod("clearAsync", &User::clearAsync));
}

MethodStart<unsigned> User::operationStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<User>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->operation();
	};
}

Napi::Value User::operationFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<fb::ICharUserField*> User::userNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<User>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->userName();
	};
}

Napi::Value User::userNameFinish(const Napi::Env env, fb::ICharUserField* ret)
{
	return CharUserField::NewInstance(env, ret);
}

MethodStart<fb::ICharUserField*> User::passwordStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<User>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->password();
	};
}

Napi::Value User::passwordFinish(const Napi::Env env, fb::ICharUserField* ret)
{
	return CharUserField::NewInstance(env, ret);
}

MethodStart<fb::ICharUserField*> User::firstNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<User>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->firstName();
	};
}

Napi::Value User::firstNameFinish(const Napi::Env env, fb::ICharUserField* ret)
{
	return CharUserField::NewInstance(env, ret);
}

MethodStart<fb::ICharUserField*> User::lastNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<User>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->lastName();
	};
}

Napi::Value User::lastNameFinish(const Napi::Env env, fb::ICharUserField* ret)
{
	return CharUserField::NewInstance(env, ret);
}

MethodStart<fb::ICharUserField*> User::middleNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<User>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->middleName();
	};
}

Napi::Value User::middleNameFinish(const Napi::Env env, fb::ICharUserField* ret)
{
	return CharUserField::NewInstance(env, ret);
}

MethodStart<fb::ICharUserField*> User::commentStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<User>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->comment();
	};
}

Napi::Value User::commentFinish(const Napi::Env env, fb::ICharUserField* ret)
{
	return CharUserField::NewInstance(env, ret);
}

MethodStart<fb::ICharUserField*> User::attributesStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<User>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->attributes();
	};
}

Napi::Value User::attributesFinish(const Napi::Env env, fb::ICharUserField* ret)
{
	return CharUserField::NewInstance(env, ret);
}

MethodStart<fb::IIntUserField*> User::activeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<User>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->active();
	};
}

Napi::Value User::activeFinish(const Napi::Env env, fb::IIntUserField* ret)
{
	return IntUserField::NewInstance(env, ret);
}

MethodStart<fb::IIntUserField*> User::adminStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<User>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->admin();
	};
}

Napi::Value User::adminFinish(const Napi::Env env, fb::IIntUserField* ret)
{
	return IntUserField::NewInstance(env, ret);
}

MethodStart<void*> User::clearStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<User>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->clear(&statusWrapper);
		return nullptr;
	};
}

Napi::Value User::clearFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void ListUsers::InitPrototype(std::vector<Napi::ObjectWrap<ListUsers>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("listSync", &ListUsers::listSync));
	properties.push_back(InstanceMethod("listAsync", &ListUsers::listAsync));
}

MethodStart<void*> ListUsers::listStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ListUsers>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* user = User::CheckedUnwrap(info.Env(), info[1], "user argument", true);

	return [obj, status, user]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->list(&statusWrapper, (user ? user->interface : nullptr));
		return nullptr;
	};
}

Napi::Value ListUsers::listFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void LogonInfo::InitPrototype(std::vector<Napi::ObjectWrap<LogonInfo>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("nameSync", &LogonInfo::nameSync));
	properties.push_back(InstanceMethod("nameAsync", &LogonInfo::nameAsync));
	properties.push_back(InstanceMethod("roleSync", &LogonInfo::roleSync));
	properties.push_back(InstanceMethod("roleAsync", &LogonInfo::roleAsync));
	properties.push_back(InstanceMethod("networkProtocolSync", &LogonInfo::networkProtocolSync));
	properties.push_back(InstanceMethod("networkProtocolAsync", &LogonInfo::networkProtocolAsync));
	properties.push_back(InstanceMethod("remoteAddressSync", &LogonInfo::remoteAddressSync));
	properties.push_back(InstanceMethod("remoteAddressAsync", &LogonInfo::remoteAddressAsync));
	properties.push_back(InstanceMethod("authBlockSync", &LogonInfo::authBlockSync));
	properties.push_back(InstanceMethod("authBlockAsync", &LogonInfo::authBlockAsync));
}

MethodStart<std::string> LogonInfo::nameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<LogonInfo>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->name();
	};
}

Napi::Value LogonInfo::nameFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> LogonInfo::roleStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<LogonInfo>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->role();
	};
}

Napi::Value LogonInfo::roleFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> LogonInfo::networkProtocolStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<LogonInfo>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->networkProtocol();
	};
}

Napi::Value LogonInfo::networkProtocolFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> LogonInfo::remoteAddressStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<LogonInfo>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->remoteAddress();
	};
}

Napi::Value LogonInfo::remoteAddressFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<const unsigned char*> LogonInfo::authBlockStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<LogonInfo>::Unwrap(info.This().ToObject());
	std::shared_ptr<Napi::Reference<Napi::Value>> lengthPersistent;
	auto* length = getAddress<unsigned>(info.Env(), async, info[0], lengthPersistent);

	return [obj, length, lengthPersistent]() {
		return obj->interface->authBlock(length);
	};
}

Napi::Value LogonInfo::authBlockFinish(const Napi::Env env, const unsigned char* ret)
{
	return Pointer::NewInstance(env, ret);
}

void Management::InitPrototype(std::vector<Napi::ObjectWrap<Management>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &Management::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &Management::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &Management::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &Management::releaseAsync));
	properties.push_back(InstanceMethod("setOwnerSync", &Management::setOwnerSync));
	properties.push_back(InstanceMethod("setOwnerAsync", &Management::setOwnerAsync));
	properties.push_back(InstanceMethod("getOwnerSync", &Management::getOwnerSync));
	properties.push_back(InstanceMethod("getOwnerAsync", &Management::getOwnerAsync));
	properties.push_back(InstanceMethod("startSync", &Management::startSync));
	properties.push_back(InstanceMethod("startAsync", &Management::startAsync));
	properties.push_back(InstanceMethod("executeSync", &Management::executeSync));
	properties.push_back(InstanceMethod("executeAsync", &Management::executeAsync));
	properties.push_back(InstanceMethod("commitSync", &Management::commitSync));
	properties.push_back(InstanceMethod("commitAsync", &Management::commitAsync));
	properties.push_back(InstanceMethod("rollbackSync", &Management::rollbackSync));
	properties.push_back(InstanceMethod("rollbackAsync", &Management::rollbackAsync));
}

MethodStart<void*> Management::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Management>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value Management::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Management::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Management>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value Management::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> Management::setOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Management>::Unwrap(info.This().ToObject());
	auto* r = ReferenceCounted::CheckedUnwrap(info.Env(), info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

Napi::Value Management::setOwnerFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IReferenceCounted*> Management::getOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Management>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

Napi::Value Management::getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(env, ret);
}

MethodStart<void*> Management::startStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Management>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* logonInfo = LogonInfo::CheckedUnwrap(info.Env(), info[1], "logonInfo argument", true);

	return [obj, status, logonInfo]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->start(&statusWrapper, (logonInfo ? logonInfo->interface : nullptr));
		return nullptr;
	};
}

Napi::Value Management::startFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Management::executeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Management>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* user = User::CheckedUnwrap(info.Env(), info[1], "user argument", true);
	auto* callback = ListUsers::CheckedUnwrap(info.Env(), info[2], "callback argument", true);

	return [obj, status, user, callback]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->execute(&statusWrapper, (user ? user->interface : nullptr), (callback ? callback->interface : nullptr));
	};
}

Napi::Value Management::executeFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> Management::commitStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Management>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->commit(&statusWrapper);
		return nullptr;
	};
}

Napi::Value Management::commitFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Management::rollbackStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Management>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->rollback(&statusWrapper);
		return nullptr;
	};
}

Napi::Value Management::rollbackFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void WireCryptPlugin::InitPrototype(std::vector<Napi::ObjectWrap<WireCryptPlugin>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &WireCryptPlugin::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &WireCryptPlugin::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &WireCryptPlugin::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &WireCryptPlugin::releaseAsync));
	properties.push_back(InstanceMethod("setOwnerSync", &WireCryptPlugin::setOwnerSync));
	properties.push_back(InstanceMethod("setOwnerAsync", &WireCryptPlugin::setOwnerAsync));
	properties.push_back(InstanceMethod("getOwnerSync", &WireCryptPlugin::getOwnerSync));
	properties.push_back(InstanceMethod("getOwnerAsync", &WireCryptPlugin::getOwnerAsync));
	properties.push_back(InstanceMethod("getKnownTypesSync", &WireCryptPlugin::getKnownTypesSync));
	properties.push_back(InstanceMethod("getKnownTypesAsync", &WireCryptPlugin::getKnownTypesAsync));
	properties.push_back(InstanceMethod("setKeySync", &WireCryptPlugin::setKeySync));
	properties.push_back(InstanceMethod("setKeyAsync", &WireCryptPlugin::setKeyAsync));
	properties.push_back(InstanceMethod("encryptSync", &WireCryptPlugin::encryptSync));
	properties.push_back(InstanceMethod("encryptAsync", &WireCryptPlugin::encryptAsync));
	properties.push_back(InstanceMethod("decryptSync", &WireCryptPlugin::decryptSync));
	properties.push_back(InstanceMethod("decryptAsync", &WireCryptPlugin::decryptAsync));
}

MethodStart<void*> WireCryptPlugin::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<WireCryptPlugin>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value WireCryptPlugin::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> WireCryptPlugin::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<WireCryptPlugin>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value WireCryptPlugin::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> WireCryptPlugin::setOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<WireCryptPlugin>::Unwrap(info.This().ToObject());
	auto* r = ReferenceCounted::CheckedUnwrap(info.Env(), info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

Napi::Value WireCryptPlugin::setOwnerFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IReferenceCounted*> WireCryptPlugin::getOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<WireCryptPlugin>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

Napi::Value WireCryptPlugin::getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(env, ret);
}

MethodStart<std::string> WireCryptPlugin::getKnownTypesStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<WireCryptPlugin>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getKnownTypes(&statusWrapper);
	};
}

Napi::Value WireCryptPlugin::getKnownTypesFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> WireCryptPlugin::setKeyStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<WireCryptPlugin>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* key = CryptKey::CheckedUnwrap(info.Env(), info[1], "key argument", true);

	return [obj, status, key]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setKey(&statusWrapper, (key ? key->interface : nullptr));
		return nullptr;
	};
}

Napi::Value WireCryptPlugin::setKeyFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> WireCryptPlugin::encryptStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<WireCryptPlugin>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned length = (unsigned) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> fromPersistent;
	auto* from = getAddress<unsigned char>(info.Env(), async, info[2], fromPersistent);
	std::shared_ptr<Napi::Reference<Napi::Value>> toPersistent;
	auto* to = getAddress<unsigned char>(info.Env(), async, info[3], toPersistent);

	return [obj, status, length, from, fromPersistent, to, toPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->encrypt(&statusWrapper, length, from, to);
		return nullptr;
	};
}

Napi::Value WireCryptPlugin::encryptFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> WireCryptPlugin::decryptStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<WireCryptPlugin>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned length = (unsigned) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> fromPersistent;
	auto* from = getAddress<unsigned char>(info.Env(), async, info[2], fromPersistent);
	std::shared_ptr<Napi::Reference<Napi::Value>> toPersistent;
	auto* to = getAddress<unsigned char>(info.Env(), async, info[3], toPersistent);

	return [obj, status, length, from, fromPersistent, to, toPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->decrypt(&statusWrapper, length, from, to);
		return nullptr;
	};
}

Napi::Value WireCryptPlugin::decryptFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void CryptKeyCallback::InitPrototype(std::vector<Napi::ObjectWrap<CryptKeyCallback>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("callbackSync", &CryptKeyCallback::callbackSync));
	properties.push_back(InstanceMethod("callbackAsync", &CryptKeyCallback::callbackAsync));
}

MethodStart<unsigned> CryptKeyCallback::callbackStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<CryptKeyCallback>::Unwrap(info.This().ToObject());
	unsigned dataLength = (unsigned) info[0].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> dataPersistent;
	auto* data = getAddress<unsigned char>(info.Env(), async, info[1], dataPersistent);
	unsigned bufferLength = (unsigned) info[2].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> bufferPersistent;
	auto* buffer = getAddress<unsigned char>(info.Env(), async, info[3], bufferPersistent);

	return [obj, dataLength, data, dataPersistent, bufferLength, buffer, bufferPersistent]() {
		return obj->interface->callback(dataLength, data, bufferLength, buffer);
	};
}

Napi::Value CryptKeyCallback::callbackFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

void KeyHolderPlugin::InitPrototype(std::vector<Napi::ObjectWrap<KeyHolderPlugin>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &KeyHolderPlugin::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &KeyHolderPlugin::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &KeyHolderPlugin::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &KeyHolderPlugin::releaseAsync));
	properties.push_back(InstanceMethod("setOwnerSync", &KeyHolderPlugin::setOwnerSync));
	properties.push_back(InstanceMethod("setOwnerAsync", &KeyHolderPlugin::setOwnerAsync));
	properties.push_back(InstanceMethod("getOwnerSync", &KeyHolderPlugin::getOwnerSync));
	properties.push_back(InstanceMethod("getOwnerAsync", &KeyHolderPlugin::getOwnerAsync));
	properties.push_back(InstanceMethod("keyCallbackSync", &KeyHolderPlugin::keyCallbackSync));
	properties.push_back(InstanceMethod("keyCallbackAsync", &KeyHolderPlugin::keyCallbackAsync));
	properties.push_back(InstanceMethod("keyHandleSync", &KeyHolderPlugin::keyHandleSync));
	properties.push_back(InstanceMethod("keyHandleAsync", &KeyHolderPlugin::keyHandleAsync));
}

MethodStart<void*> KeyHolderPlugin::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<KeyHolderPlugin>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value KeyHolderPlugin::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> KeyHolderPlugin::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<KeyHolderPlugin>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value KeyHolderPlugin::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> KeyHolderPlugin::setOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<KeyHolderPlugin>::Unwrap(info.This().ToObject());
	auto* r = ReferenceCounted::CheckedUnwrap(info.Env(), info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

Napi::Value KeyHolderPlugin::setOwnerFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IReferenceCounted*> KeyHolderPlugin::getOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<KeyHolderPlugin>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

Napi::Value KeyHolderPlugin::getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(env, ret);
}

MethodStart<int> KeyHolderPlugin::keyCallbackStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<KeyHolderPlugin>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* callback = CryptKeyCallback::CheckedUnwrap(info.Env(), info[1], "callback argument", true);

	return [obj, status, callback]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->keyCallback(&statusWrapper, (callback ? callback->interface : nullptr));
	};
}

Napi::Value KeyHolderPlugin::keyCallbackFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<fb::ICryptKeyCallback*> KeyHolderPlugin::keyHandleStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<KeyHolderPlugin>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string keyName = info[1].ToString().Utf8Value();

	return [obj, status, keyName]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->keyHandle(&statusWrapper, keyName.c_str());
	};
}

Napi::Value KeyHolderPlugin::keyHandleFinish(const Napi::Env env, fb::ICryptKeyCallback* ret)
{
	return CryptKeyCallback::NewInstance(env, ret);
}

void DbCryptPlugin::InitPrototype(std::vector<Napi::ObjectWrap<DbCryptPlugin>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &DbCryptPlugin::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &DbCryptPlugin::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &DbCryptPlugin::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &DbCryptPlugin::releaseAsync));
	properties.push_back(InstanceMethod("setOwnerSync", &DbCryptPlugin::setOwnerSync));
	properties.push_back(InstanceMethod("setOwnerAsync", &DbCryptPlugin::setOwnerAsync));
	properties.push_back(InstanceMethod("getOwnerSync", &DbCryptPlugin::getOwnerSync));
	properties.push_back(InstanceMethod("getOwnerAsync", &DbCryptPlugin::getOwnerAsync));
}

MethodStart<void*> DbCryptPlugin::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<DbCryptPlugin>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value DbCryptPlugin::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> DbCryptPlugin::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<DbCryptPlugin>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value DbCryptPlugin::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> DbCryptPlugin::setOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<DbCryptPlugin>::Unwrap(info.This().ToObject());
	auto* r = ReferenceCounted::CheckedUnwrap(info.Env(), info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

Napi::Value DbCryptPlugin::setOwnerFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IReferenceCounted*> DbCryptPlugin::getOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<DbCryptPlugin>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

Napi::Value DbCryptPlugin::getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(env, ret);
}

void ExternalContext::InitPrototype(std::vector<Napi::ObjectWrap<ExternalContext>::PropertyDescriptor>& properties)
{
}

void ExternalResultSet::InitPrototype(std::vector<Napi::ObjectWrap<ExternalResultSet>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("disposeSync", &ExternalResultSet::disposeSync));
	properties.push_back(InstanceMethod("disposeAsync", &ExternalResultSet::disposeAsync));
	properties.push_back(InstanceMethod("fetchSync", &ExternalResultSet::fetchSync));
	properties.push_back(InstanceMethod("fetchAsync", &ExternalResultSet::fetchAsync));
}

MethodStart<void*> ExternalResultSet::disposeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ExternalResultSet>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

Napi::Value ExternalResultSet::disposeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<FB_BOOLEAN> ExternalResultSet::fetchStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ExternalResultSet>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->fetch(&statusWrapper);
	};
}

Napi::Value ExternalResultSet::fetchFinish(const Napi::Env env, FB_BOOLEAN ret)
{
	return Napi::Value::From(env, (bool) ret);
}

void ExternalFunction::InitPrototype(std::vector<Napi::ObjectWrap<ExternalFunction>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("disposeSync", &ExternalFunction::disposeSync));
	properties.push_back(InstanceMethod("disposeAsync", &ExternalFunction::disposeAsync));
}

MethodStart<void*> ExternalFunction::disposeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ExternalFunction>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

Napi::Value ExternalFunction::disposeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void ExternalProcedure::InitPrototype(std::vector<Napi::ObjectWrap<ExternalProcedure>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("disposeSync", &ExternalProcedure::disposeSync));
	properties.push_back(InstanceMethod("disposeAsync", &ExternalProcedure::disposeAsync));
}

MethodStart<void*> ExternalProcedure::disposeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ExternalProcedure>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

Napi::Value ExternalProcedure::disposeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void ExternalTrigger::InitPrototype(std::vector<Napi::ObjectWrap<ExternalTrigger>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("disposeSync", &ExternalTrigger::disposeSync));
	properties.push_back(InstanceMethod("disposeAsync", &ExternalTrigger::disposeAsync));
}

MethodStart<void*> ExternalTrigger::disposeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ExternalTrigger>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

Napi::Value ExternalTrigger::disposeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void RoutineMetadata::InitPrototype(std::vector<Napi::ObjectWrap<RoutineMetadata>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("getPackageSync", &RoutineMetadata::getPackageSync));
	properties.push_back(InstanceMethod("getPackageAsync", &RoutineMetadata::getPackageAsync));
	properties.push_back(InstanceMethod("getNameSync", &RoutineMetadata::getNameSync));
	properties.push_back(InstanceMethod("getNameAsync", &RoutineMetadata::getNameAsync));
	properties.push_back(InstanceMethod("getEntryPointSync", &RoutineMetadata::getEntryPointSync));
	properties.push_back(InstanceMethod("getEntryPointAsync", &RoutineMetadata::getEntryPointAsync));
	properties.push_back(InstanceMethod("getBodySync", &RoutineMetadata::getBodySync));
	properties.push_back(InstanceMethod("getBodyAsync", &RoutineMetadata::getBodyAsync));
	properties.push_back(InstanceMethod("getInputMetadataSync", &RoutineMetadata::getInputMetadataSync));
	properties.push_back(InstanceMethod("getInputMetadataAsync", &RoutineMetadata::getInputMetadataAsync));
	properties.push_back(InstanceMethod("getOutputMetadataSync", &RoutineMetadata::getOutputMetadataSync));
	properties.push_back(InstanceMethod("getOutputMetadataAsync", &RoutineMetadata::getOutputMetadataAsync));
	properties.push_back(InstanceMethod("getTriggerMetadataSync", &RoutineMetadata::getTriggerMetadataSync));
	properties.push_back(InstanceMethod("getTriggerMetadataAsync", &RoutineMetadata::getTriggerMetadataAsync));
	properties.push_back(InstanceMethod("getTriggerTableSync", &RoutineMetadata::getTriggerTableSync));
	properties.push_back(InstanceMethod("getTriggerTableAsync", &RoutineMetadata::getTriggerTableAsync));
	properties.push_back(InstanceMethod("getTriggerTypeSync", &RoutineMetadata::getTriggerTypeSync));
	properties.push_back(InstanceMethod("getTriggerTypeAsync", &RoutineMetadata::getTriggerTypeAsync));
}

MethodStart<std::string> RoutineMetadata::getPackageStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<RoutineMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getPackage(&statusWrapper);
	};
}

Napi::Value RoutineMetadata::getPackageFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> RoutineMetadata::getNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<RoutineMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getName(&statusWrapper);
	};
}

Napi::Value RoutineMetadata::getNameFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> RoutineMetadata::getEntryPointStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<RoutineMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getEntryPoint(&statusWrapper);
	};
}

Napi::Value RoutineMetadata::getEntryPointFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> RoutineMetadata::getBodyStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<RoutineMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getBody(&statusWrapper);
	};
}

Napi::Value RoutineMetadata::getBodyFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<fb::IMessageMetadata*> RoutineMetadata::getInputMetadataStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<RoutineMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getInputMetadata(&statusWrapper);
	};
}

Napi::Value RoutineMetadata::getInputMetadataFinish(const Napi::Env env, fb::IMessageMetadata* ret)
{
	return MessageMetadata::NewInstance(env, ret);
}

MethodStart<fb::IMessageMetadata*> RoutineMetadata::getOutputMetadataStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<RoutineMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getOutputMetadata(&statusWrapper);
	};
}

Napi::Value RoutineMetadata::getOutputMetadataFinish(const Napi::Env env, fb::IMessageMetadata* ret)
{
	return MessageMetadata::NewInstance(env, ret);
}

MethodStart<fb::IMessageMetadata*> RoutineMetadata::getTriggerMetadataStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<RoutineMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getTriggerMetadata(&statusWrapper);
	};
}

Napi::Value RoutineMetadata::getTriggerMetadataFinish(const Napi::Env env, fb::IMessageMetadata* ret)
{
	return MessageMetadata::NewInstance(env, ret);
}

MethodStart<std::string> RoutineMetadata::getTriggerTableStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<RoutineMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getTriggerTable(&statusWrapper);
	};
}

Napi::Value RoutineMetadata::getTriggerTableFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<unsigned> RoutineMetadata::getTriggerTypeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<RoutineMetadata>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getTriggerType(&statusWrapper);
	};
}

Napi::Value RoutineMetadata::getTriggerTypeFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

void ExternalEngine::InitPrototype(std::vector<Napi::ObjectWrap<ExternalEngine>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &ExternalEngine::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &ExternalEngine::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &ExternalEngine::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &ExternalEngine::releaseAsync));
	properties.push_back(InstanceMethod("setOwnerSync", &ExternalEngine::setOwnerSync));
	properties.push_back(InstanceMethod("setOwnerAsync", &ExternalEngine::setOwnerAsync));
	properties.push_back(InstanceMethod("getOwnerSync", &ExternalEngine::getOwnerSync));
	properties.push_back(InstanceMethod("getOwnerAsync", &ExternalEngine::getOwnerAsync));
}

MethodStart<void*> ExternalEngine::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ExternalEngine>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value ExternalEngine::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> ExternalEngine::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ExternalEngine>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value ExternalEngine::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> ExternalEngine::setOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ExternalEngine>::Unwrap(info.This().ToObject());
	auto* r = ReferenceCounted::CheckedUnwrap(info.Env(), info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

Napi::Value ExternalEngine::setOwnerFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IReferenceCounted*> ExternalEngine::getOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<ExternalEngine>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

Napi::Value ExternalEngine::getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(env, ret);
}

void Timer::InitPrototype(std::vector<Napi::ObjectWrap<Timer>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &Timer::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &Timer::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &Timer::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &Timer::releaseAsync));
	properties.push_back(InstanceMethod("handlerSync", &Timer::handlerSync));
	properties.push_back(InstanceMethod("handlerAsync", &Timer::handlerAsync));
}

MethodStart<void*> Timer::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Timer>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value Timer::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Timer::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Timer>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value Timer::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> Timer::handlerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Timer>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->handler();
		return nullptr;
	};
}

Napi::Value Timer::handlerFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void TimerControl::InitPrototype(std::vector<Napi::ObjectWrap<TimerControl>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("startSync", &TimerControl::startSync));
	properties.push_back(InstanceMethod("startAsync", &TimerControl::startAsync));
	properties.push_back(InstanceMethod("stopSync", &TimerControl::stopSync));
	properties.push_back(InstanceMethod("stopAsync", &TimerControl::stopAsync));
}

MethodStart<void*> TimerControl::startStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TimerControl>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* timer = Timer::CheckedUnwrap(info.Env(), info[1], "timer argument", true);
	uint64_t microSeconds = (uint64_t) info[2].ToNumber().Int64Value();

	return [obj, status, timer, microSeconds]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->start(&statusWrapper, (timer ? timer->interface : nullptr), microSeconds);
		return nullptr;
	};
}

Napi::Value TimerControl::startFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> TimerControl::stopStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TimerControl>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* timer = Timer::CheckedUnwrap(info.Env(), info[1], "timer argument", true);

	return [obj, status, timer]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->stop(&statusWrapper, (timer ? timer->interface : nullptr));
		return nullptr;
	};
}

Napi::Value TimerControl::stopFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void VersionCallback::InitPrototype(std::vector<Napi::ObjectWrap<VersionCallback>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("callbackSync", &VersionCallback::callbackSync));
	properties.push_back(InstanceMethod("callbackAsync", &VersionCallback::callbackAsync));
}

MethodStart<void*> VersionCallback::callbackStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<VersionCallback>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string text = info[1].ToString().Utf8Value();

	return [obj, status, text]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->callback(&statusWrapper, text.c_str());
		return nullptr;
	};
}

Napi::Value VersionCallback::callbackFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void Util::InitPrototype(std::vector<Napi::ObjectWrap<Util>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("getFbVersionSync", &Util::getFbVersionSync));
	properties.push_back(InstanceMethod("getFbVersionAsync", &Util::getFbVersionAsync));
	properties.push_back(InstanceMethod("executeCreateDatabaseSync", &Util::executeCreateDatabaseSync));
	properties.push_back(InstanceMethod("executeCreateDatabaseAsync", &Util::executeCreateDatabaseAsync));
	properties.push_back(InstanceMethod("decodeDateSync", &Util::decodeDateSync));
	properties.push_back(InstanceMethod("decodeDateAsync", &Util::decodeDateAsync));
	properties.push_back(InstanceMethod("decodeTimeSync", &Util::decodeTimeSync));
	properties.push_back(InstanceMethod("decodeTimeAsync", &Util::decodeTimeAsync));
	properties.push_back(InstanceMethod("encodeDateSync", &Util::encodeDateSync));
	properties.push_back(InstanceMethod("encodeDateAsync", &Util::encodeDateAsync));
	properties.push_back(InstanceMethod("encodeTimeSync", &Util::encodeTimeSync));
	properties.push_back(InstanceMethod("encodeTimeAsync", &Util::encodeTimeAsync));
	properties.push_back(InstanceMethod("getClientVersionSync", &Util::getClientVersionSync));
	properties.push_back(InstanceMethod("getClientVersionAsync", &Util::getClientVersionAsync));
	properties.push_back(InstanceMethod("getXpbBuilderSync", &Util::getXpbBuilderSync));
	properties.push_back(InstanceMethod("getXpbBuilderAsync", &Util::getXpbBuilderAsync));
	properties.push_back(InstanceMethod("setOffsetsSync", &Util::setOffsetsSync));
	properties.push_back(InstanceMethod("setOffsetsAsync", &Util::setOffsetsAsync));
}

MethodStart<void*> Util::getFbVersionStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Util>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* att = Attachment::CheckedUnwrap(info.Env(), info[1], "att argument", true);
	auto* callback = VersionCallback::CheckedUnwrap(info.Env(), info[2], "callback argument", true);

	return [obj, status, att, callback]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->getFbVersion(&statusWrapper, (att ? att->interface : nullptr), (callback ? callback->interface : nullptr));
		return nullptr;
	};
}

Napi::Value Util::getFbVersionFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IAttachment*> Util::executeCreateDatabaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Util>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned stmtLength = (unsigned) info[1].ToNumber();
	std::string creatDBstatement = info[2].ToString().Utf8Value();
	unsigned dialect = (unsigned) info[3].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> stmtIsCreateDbPersistent;
	auto* stmtIsCreateDb = getAddress<unsigned char>(info.Env(), async, info[4], stmtIsCreateDbPersistent);

	return [obj, status, stmtLength, creatDBstatement, dialect, stmtIsCreateDb, stmtIsCreateDbPersistent]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->executeCreateDatabase(&statusWrapper, stmtLength, creatDBstatement.c_str(), dialect, stmtIsCreateDb);
	};
}

Napi::Value Util::executeCreateDatabaseFinish(const Napi::Env env, fb::IAttachment* ret)
{
	return Attachment::NewInstance(env, ret);
}

MethodStart<void*> Util::decodeDateStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Util>::Unwrap(info.This().ToObject());
	int date = (int) info[0].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> yearPersistent;
	auto* year = getAddress<unsigned>(info.Env(), async, info[1], yearPersistent);
	std::shared_ptr<Napi::Reference<Napi::Value>> monthPersistent;
	auto* month = getAddress<unsigned>(info.Env(), async, info[2], monthPersistent);
	std::shared_ptr<Napi::Reference<Napi::Value>> dayPersistent;
	auto* day = getAddress<unsigned>(info.Env(), async, info[3], dayPersistent);

	return [obj, date, year, yearPersistent, month, monthPersistent, day, dayPersistent]() {
		obj->interface->decodeDate(date, year, month, day);
		return nullptr;
	};
}

Napi::Value Util::decodeDateFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> Util::decodeTimeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Util>::Unwrap(info.This().ToObject());
	int time = (int) info[0].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> hoursPersistent;
	auto* hours = getAddress<unsigned>(info.Env(), async, info[1], hoursPersistent);
	std::shared_ptr<Napi::Reference<Napi::Value>> minutesPersistent;
	auto* minutes = getAddress<unsigned>(info.Env(), async, info[2], minutesPersistent);
	std::shared_ptr<Napi::Reference<Napi::Value>> secondsPersistent;
	auto* seconds = getAddress<unsigned>(info.Env(), async, info[3], secondsPersistent);
	std::shared_ptr<Napi::Reference<Napi::Value>> fractionsPersistent;
	auto* fractions = getAddress<unsigned>(info.Env(), async, info[4], fractionsPersistent);

	return [obj, time, hours, hoursPersistent, minutes, minutesPersistent, seconds, secondsPersistent, fractions, fractionsPersistent]() {
		obj->interface->decodeTime(time, hours, minutes, seconds, fractions);
		return nullptr;
	};
}

Napi::Value Util::decodeTimeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> Util::encodeDateStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Util>::Unwrap(info.This().ToObject());
	unsigned year = (unsigned) info[0].ToNumber();
	unsigned month = (unsigned) info[1].ToNumber();
	unsigned day = (unsigned) info[2].ToNumber();

	return [obj, year, month, day]() {
		return obj->interface->encodeDate(year, month, day);
	};
}

Napi::Value Util::encodeDateFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> Util::encodeTimeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Util>::Unwrap(info.This().ToObject());
	unsigned hours = (unsigned) info[0].ToNumber();
	unsigned minutes = (unsigned) info[1].ToNumber();
	unsigned seconds = (unsigned) info[2].ToNumber();
	unsigned fractions = (unsigned) info[3].ToNumber();

	return [obj, hours, minutes, seconds, fractions]() {
		return obj->interface->encodeTime(hours, minutes, seconds, fractions);
	};
}

Napi::Value Util::encodeTimeFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<unsigned> Util::getClientVersionStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Util>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getClientVersion();
	};
}

Napi::Value Util::getClientVersionFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<fb::IXpbBuilder*> Util::getXpbBuilderStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Util>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned kind = (unsigned) info[1].ToNumber();
	std::shared_ptr<Napi::Reference<Napi::Value>> bufPersistent;
	auto* buf = getAddress<unsigned char>(info.Env(), async, info[2], bufPersistent);
	unsigned len = (unsigned) info[3].ToNumber();

	return [obj, status, kind, buf, bufPersistent, len]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getXpbBuilder(&statusWrapper, kind, buf, len);
	};
}

Napi::Value Util::getXpbBuilderFinish(const Napi::Env env, fb::IXpbBuilder* ret)
{
	return XpbBuilder::NewInstance(env, ret);
}

MethodStart<unsigned> Util::setOffsetsStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<Util>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* metadata = MessageMetadata::CheckedUnwrap(info.Env(), info[1], "metadata argument", true);
	auto* callback = OffsetsCallback::CheckedUnwrap(info.Env(), info[2], "callback argument", true);

	return [obj, status, metadata, callback]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->setOffsets(&statusWrapper, (metadata ? metadata->interface : nullptr), (callback ? callback->interface : nullptr));
	};
}

Napi::Value Util::setOffsetsFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

void OffsetsCallback::InitPrototype(std::vector<Napi::ObjectWrap<OffsetsCallback>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("setOffsetSync", &OffsetsCallback::setOffsetSync));
	properties.push_back(InstanceMethod("setOffsetAsync", &OffsetsCallback::setOffsetAsync));
}

MethodStart<void*> OffsetsCallback::setOffsetStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<OffsetsCallback>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned index = (unsigned) info[1].ToNumber();
	unsigned offset = (unsigned) info[2].ToNumber();
	unsigned nullOffset = (unsigned) info[3].ToNumber();

	return [obj, status, index, offset, nullOffset]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setOffset(&statusWrapper, index, offset, nullOffset);
		return nullptr;
	};
}

Napi::Value OffsetsCallback::setOffsetFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

void XpbBuilder::InitPrototype(std::vector<Napi::ObjectWrap<XpbBuilder>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("disposeSync", &XpbBuilder::disposeSync));
	properties.push_back(InstanceMethod("disposeAsync", &XpbBuilder::disposeAsync));
	properties.push_back(InstanceMethod("clearSync", &XpbBuilder::clearSync));
	properties.push_back(InstanceMethod("clearAsync", &XpbBuilder::clearAsync));
	properties.push_back(InstanceMethod("removeCurrentSync", &XpbBuilder::removeCurrentSync));
	properties.push_back(InstanceMethod("removeCurrentAsync", &XpbBuilder::removeCurrentAsync));
	properties.push_back(InstanceMethod("insertIntSync", &XpbBuilder::insertIntSync));
	properties.push_back(InstanceMethod("insertIntAsync", &XpbBuilder::insertIntAsync));
	properties.push_back(InstanceMethod("insertBigIntSync", &XpbBuilder::insertBigIntSync));
	properties.push_back(InstanceMethod("insertBigIntAsync", &XpbBuilder::insertBigIntAsync));
	properties.push_back(InstanceMethod("insertBytesSync", &XpbBuilder::insertBytesSync));
	properties.push_back(InstanceMethod("insertBytesAsync", &XpbBuilder::insertBytesAsync));
	properties.push_back(InstanceMethod("insertStringSync", &XpbBuilder::insertStringSync));
	properties.push_back(InstanceMethod("insertStringAsync", &XpbBuilder::insertStringAsync));
	properties.push_back(InstanceMethod("insertTagSync", &XpbBuilder::insertTagSync));
	properties.push_back(InstanceMethod("insertTagAsync", &XpbBuilder::insertTagAsync));
	properties.push_back(InstanceMethod("isEofSync", &XpbBuilder::isEofSync));
	properties.push_back(InstanceMethod("isEofAsync", &XpbBuilder::isEofAsync));
	properties.push_back(InstanceMethod("moveNextSync", &XpbBuilder::moveNextSync));
	properties.push_back(InstanceMethod("moveNextAsync", &XpbBuilder::moveNextAsync));
	properties.push_back(InstanceMethod("rewindSync", &XpbBuilder::rewindSync));
	properties.push_back(InstanceMethod("rewindAsync", &XpbBuilder::rewindAsync));
	properties.push_back(InstanceMethod("findFirstSync", &XpbBuilder::findFirstSync));
	properties.push_back(InstanceMethod("findFirstAsync", &XpbBuilder::findFirstAsync));
	properties.push_back(InstanceMethod("findNextSync", &XpbBuilder::findNextSync));
	properties.push_back(InstanceMethod("findNextAsync", &XpbBuilder::findNextAsync));
	properties.push_back(InstanceMethod("getTagSync", &XpbBuilder::getTagSync));
	properties.push_back(InstanceMethod("getTagAsync", &XpbBuilder::getTagAsync));
	properties.push_back(InstanceMethod("getLengthSync", &XpbBuilder::getLengthSync));
	properties.push_back(InstanceMethod("getLengthAsync", &XpbBuilder::getLengthAsync));
	properties.push_back(InstanceMethod("getIntSync", &XpbBuilder::getIntSync));
	properties.push_back(InstanceMethod("getIntAsync", &XpbBuilder::getIntAsync));
	properties.push_back(InstanceMethod("getBigIntSync", &XpbBuilder::getBigIntSync));
	properties.push_back(InstanceMethod("getBigIntAsync", &XpbBuilder::getBigIntAsync));
	properties.push_back(InstanceMethod("getStringSync", &XpbBuilder::getStringSync));
	properties.push_back(InstanceMethod("getStringAsync", &XpbBuilder::getStringAsync));
	properties.push_back(InstanceMethod("getBytesSync", &XpbBuilder::getBytesSync));
	properties.push_back(InstanceMethod("getBytesAsync", &XpbBuilder::getBytesAsync));
	properties.push_back(InstanceMethod("getBufferLengthSync", &XpbBuilder::getBufferLengthSync));
	properties.push_back(InstanceMethod("getBufferLengthAsync", &XpbBuilder::getBufferLengthAsync));
	properties.push_back(InstanceMethod("getBufferSync", &XpbBuilder::getBufferSync));
	properties.push_back(InstanceMethod("getBufferAsync", &XpbBuilder::getBufferAsync));
}

MethodStart<void*> XpbBuilder::disposeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

Napi::Value XpbBuilder::disposeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> XpbBuilder::clearStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->clear(&statusWrapper);
		return nullptr;
	};
}

Napi::Value XpbBuilder::clearFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> XpbBuilder::removeCurrentStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->removeCurrent(&statusWrapper);
		return nullptr;
	};
}

Napi::Value XpbBuilder::removeCurrentFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> XpbBuilder::insertIntStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned char tag = (unsigned char) info[1].ToNumber().Uint32Value();
	int value = (int) info[2].ToNumber();

	return [obj, status, tag, value]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->insertInt(&statusWrapper, tag, value);
		return nullptr;
	};
}

Napi::Value XpbBuilder::insertIntFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> XpbBuilder::insertBigIntStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned char tag = (unsigned char) info[1].ToNumber().Uint32Value();
	int64_t value = (int64_t) info[2].ToNumber();

	return [obj, status, tag, value]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->insertBigInt(&statusWrapper, tag, value);
		return nullptr;
	};
}

Napi::Value XpbBuilder::insertBigIntFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> XpbBuilder::insertBytesStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned char tag = (unsigned char) info[1].ToNumber().Uint32Value();
	std::shared_ptr<Napi::Reference<Napi::Value>> bytesPersistent;
	auto* bytes = getAddress<unsigned char>(info.Env(), async, info[2], bytesPersistent);
	unsigned length = (unsigned) info[3].ToNumber();

	return [obj, status, tag, bytes, bytesPersistent, length]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->insertBytes(&statusWrapper, tag, bytes, length);
		return nullptr;
	};
}

Napi::Value XpbBuilder::insertBytesFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> XpbBuilder::insertStringStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned char tag = (unsigned char) info[1].ToNumber().Uint32Value();
	std::string str = info[2].ToString().Utf8Value();

	return [obj, status, tag, str]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->insertString(&statusWrapper, tag, str.c_str());
		return nullptr;
	};
}

Napi::Value XpbBuilder::insertStringFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> XpbBuilder::insertTagStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned char tag = (unsigned char) info[1].ToNumber().Uint32Value();

	return [obj, status, tag]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->insertTag(&statusWrapper, tag);
		return nullptr;
	};
}

Napi::Value XpbBuilder::insertTagFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<FB_BOOLEAN> XpbBuilder::isEofStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->isEof(&statusWrapper);
	};
}

Napi::Value XpbBuilder::isEofFinish(const Napi::Env env, FB_BOOLEAN ret)
{
	return Napi::Value::From(env, (bool) ret);
}

MethodStart<void*> XpbBuilder::moveNextStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->moveNext(&statusWrapper);
		return nullptr;
	};
}

Napi::Value XpbBuilder::moveNextFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> XpbBuilder::rewindStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->rewind(&statusWrapper);
		return nullptr;
	};
}

Napi::Value XpbBuilder::rewindFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<FB_BOOLEAN> XpbBuilder::findFirstStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	unsigned char tag = (unsigned char) info[1].ToNumber().Uint32Value();

	return [obj, status, tag]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->findFirst(&statusWrapper, tag);
	};
}

Napi::Value XpbBuilder::findFirstFinish(const Napi::Env env, FB_BOOLEAN ret)
{
	return Napi::Value::From(env, (bool) ret);
}

MethodStart<FB_BOOLEAN> XpbBuilder::findNextStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->findNext(&statusWrapper);
	};
}

Napi::Value XpbBuilder::findNextFinish(const Napi::Env env, FB_BOOLEAN ret)
{
	return Napi::Value::From(env, (bool) ret);
}

MethodStart<unsigned char> XpbBuilder::getTagStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getTag(&statusWrapper);
	};
}

Napi::Value XpbBuilder::getTagFinish(const Napi::Env env, unsigned char ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<unsigned> XpbBuilder::getLengthStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getLength(&statusWrapper);
	};
}

Napi::Value XpbBuilder::getLengthFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> XpbBuilder::getIntStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getInt(&statusWrapper);
	};
}

Napi::Value XpbBuilder::getIntFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int64_t> XpbBuilder::getBigIntStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getBigInt(&statusWrapper);
	};
}

Napi::Value XpbBuilder::getBigIntFinish(const Napi::Env env, int64_t ret)
{
	return Napi::Value::From(env, (double) ret);
}

MethodStart<std::string> XpbBuilder::getStringStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getString(&statusWrapper);
	};
}

Napi::Value XpbBuilder::getStringFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<const unsigned char*> XpbBuilder::getBytesStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getBytes(&statusWrapper);
	};
}

Napi::Value XpbBuilder::getBytesFinish(const Napi::Env env, const unsigned char* ret)
{
	return Pointer::NewInstance(env, ret);
}

MethodStart<unsigned> XpbBuilder::getBufferLengthStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getBufferLength(&statusWrapper);
	};
}

Napi::Value XpbBuilder::getBufferLengthFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<const unsigned char*> XpbBuilder::getBufferStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<XpbBuilder>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getBuffer(&statusWrapper);
	};
}

Napi::Value XpbBuilder::getBufferFinish(const Napi::Env env, const unsigned char* ret)
{
	return Pointer::NewInstance(env, ret);
}

void TraceConnection::InitPrototype(std::vector<Napi::ObjectWrap<TraceConnection>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("getKindSync", &TraceConnection::getKindSync));
	properties.push_back(InstanceMethod("getKindAsync", &TraceConnection::getKindAsync));
	properties.push_back(InstanceMethod("getProcessIDSync", &TraceConnection::getProcessIDSync));
	properties.push_back(InstanceMethod("getProcessIDAsync", &TraceConnection::getProcessIDAsync));
	properties.push_back(InstanceMethod("getUserNameSync", &TraceConnection::getUserNameSync));
	properties.push_back(InstanceMethod("getUserNameAsync", &TraceConnection::getUserNameAsync));
	properties.push_back(InstanceMethod("getRoleNameSync", &TraceConnection::getRoleNameSync));
	properties.push_back(InstanceMethod("getRoleNameAsync", &TraceConnection::getRoleNameAsync));
	properties.push_back(InstanceMethod("getCharSetSync", &TraceConnection::getCharSetSync));
	properties.push_back(InstanceMethod("getCharSetAsync", &TraceConnection::getCharSetAsync));
	properties.push_back(InstanceMethod("getRemoteProtocolSync", &TraceConnection::getRemoteProtocolSync));
	properties.push_back(InstanceMethod("getRemoteProtocolAsync", &TraceConnection::getRemoteProtocolAsync));
	properties.push_back(InstanceMethod("getRemoteAddressSync", &TraceConnection::getRemoteAddressSync));
	properties.push_back(InstanceMethod("getRemoteAddressAsync", &TraceConnection::getRemoteAddressAsync));
	properties.push_back(InstanceMethod("getRemoteProcessIDSync", &TraceConnection::getRemoteProcessIDSync));
	properties.push_back(InstanceMethod("getRemoteProcessIDAsync", &TraceConnection::getRemoteProcessIDAsync));
	properties.push_back(InstanceMethod("getRemoteProcessNameSync", &TraceConnection::getRemoteProcessNameSync));
	properties.push_back(InstanceMethod("getRemoteProcessNameAsync", &TraceConnection::getRemoteProcessNameAsync));
}

MethodStart<unsigned> TraceConnection::getKindStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getKind();
	};
}

Napi::Value TraceConnection::getKindFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> TraceConnection::getProcessIDStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getProcessID();
	};
}

Napi::Value TraceConnection::getProcessIDFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceConnection::getUserNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getUserName();
	};
}

Napi::Value TraceConnection::getUserNameFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceConnection::getRoleNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getRoleName();
	};
}

Napi::Value TraceConnection::getRoleNameFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceConnection::getCharSetStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getCharSet();
	};
}

Napi::Value TraceConnection::getCharSetFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceConnection::getRemoteProtocolStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getRemoteProtocol();
	};
}

Napi::Value TraceConnection::getRemoteProtocolFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceConnection::getRemoteAddressStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getRemoteAddress();
	};
}

Napi::Value TraceConnection::getRemoteAddressFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> TraceConnection::getRemoteProcessIDStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getRemoteProcessID();
	};
}

Napi::Value TraceConnection::getRemoteProcessIDFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceConnection::getRemoteProcessNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getRemoteProcessName();
	};
}

Napi::Value TraceConnection::getRemoteProcessNameFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

void TraceDatabaseConnection::InitPrototype(std::vector<Napi::ObjectWrap<TraceDatabaseConnection>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("getKindSync", &TraceDatabaseConnection::getKindSync));
	properties.push_back(InstanceMethod("getKindAsync", &TraceDatabaseConnection::getKindAsync));
	properties.push_back(InstanceMethod("getProcessIDSync", &TraceDatabaseConnection::getProcessIDSync));
	properties.push_back(InstanceMethod("getProcessIDAsync", &TraceDatabaseConnection::getProcessIDAsync));
	properties.push_back(InstanceMethod("getUserNameSync", &TraceDatabaseConnection::getUserNameSync));
	properties.push_back(InstanceMethod("getUserNameAsync", &TraceDatabaseConnection::getUserNameAsync));
	properties.push_back(InstanceMethod("getRoleNameSync", &TraceDatabaseConnection::getRoleNameSync));
	properties.push_back(InstanceMethod("getRoleNameAsync", &TraceDatabaseConnection::getRoleNameAsync));
	properties.push_back(InstanceMethod("getCharSetSync", &TraceDatabaseConnection::getCharSetSync));
	properties.push_back(InstanceMethod("getCharSetAsync", &TraceDatabaseConnection::getCharSetAsync));
	properties.push_back(InstanceMethod("getRemoteProtocolSync", &TraceDatabaseConnection::getRemoteProtocolSync));
	properties.push_back(InstanceMethod("getRemoteProtocolAsync", &TraceDatabaseConnection::getRemoteProtocolAsync));
	properties.push_back(InstanceMethod("getRemoteAddressSync", &TraceDatabaseConnection::getRemoteAddressSync));
	properties.push_back(InstanceMethod("getRemoteAddressAsync", &TraceDatabaseConnection::getRemoteAddressAsync));
	properties.push_back(InstanceMethod("getRemoteProcessIDSync", &TraceDatabaseConnection::getRemoteProcessIDSync));
	properties.push_back(InstanceMethod("getRemoteProcessIDAsync", &TraceDatabaseConnection::getRemoteProcessIDAsync));
	properties.push_back(InstanceMethod("getRemoteProcessNameSync", &TraceDatabaseConnection::getRemoteProcessNameSync));
	properties.push_back(InstanceMethod("getRemoteProcessNameAsync", &TraceDatabaseConnection::getRemoteProcessNameAsync));
	properties.push_back(InstanceMethod("getConnectionIDSync", &TraceDatabaseConnection::getConnectionIDSync));
	properties.push_back(InstanceMethod("getConnectionIDAsync", &TraceDatabaseConnection::getConnectionIDAsync));
	properties.push_back(InstanceMethod("getDatabaseNameSync", &TraceDatabaseConnection::getDatabaseNameSync));
	properties.push_back(InstanceMethod("getDatabaseNameAsync", &TraceDatabaseConnection::getDatabaseNameAsync));
}

MethodStart<unsigned> TraceDatabaseConnection::getKindStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceDatabaseConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getKind();
	};
}

Napi::Value TraceDatabaseConnection::getKindFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> TraceDatabaseConnection::getProcessIDStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceDatabaseConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getProcessID();
	};
}

Napi::Value TraceDatabaseConnection::getProcessIDFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceDatabaseConnection::getUserNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceDatabaseConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getUserName();
	};
}

Napi::Value TraceDatabaseConnection::getUserNameFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceDatabaseConnection::getRoleNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceDatabaseConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getRoleName();
	};
}

Napi::Value TraceDatabaseConnection::getRoleNameFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceDatabaseConnection::getCharSetStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceDatabaseConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getCharSet();
	};
}

Napi::Value TraceDatabaseConnection::getCharSetFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceDatabaseConnection::getRemoteProtocolStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceDatabaseConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getRemoteProtocol();
	};
}

Napi::Value TraceDatabaseConnection::getRemoteProtocolFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceDatabaseConnection::getRemoteAddressStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceDatabaseConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getRemoteAddress();
	};
}

Napi::Value TraceDatabaseConnection::getRemoteAddressFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> TraceDatabaseConnection::getRemoteProcessIDStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceDatabaseConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getRemoteProcessID();
	};
}

Napi::Value TraceDatabaseConnection::getRemoteProcessIDFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceDatabaseConnection::getRemoteProcessNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceDatabaseConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getRemoteProcessName();
	};
}

Napi::Value TraceDatabaseConnection::getRemoteProcessNameFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int64_t> TraceDatabaseConnection::getConnectionIDStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceDatabaseConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getConnectionID();
	};
}

Napi::Value TraceDatabaseConnection::getConnectionIDFinish(const Napi::Env env, int64_t ret)
{
	return Napi::Value::From(env, (double) ret);
}

MethodStart<std::string> TraceDatabaseConnection::getDatabaseNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceDatabaseConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getDatabaseName();
	};
}

Napi::Value TraceDatabaseConnection::getDatabaseNameFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

void TraceTransaction::InitPrototype(std::vector<Napi::ObjectWrap<TraceTransaction>::PropertyDescriptor>& properties)
{
}

void TraceParams::InitPrototype(std::vector<Napi::ObjectWrap<TraceParams>::PropertyDescriptor>& properties)
{
}

void TraceStatement::InitPrototype(std::vector<Napi::ObjectWrap<TraceStatement>::PropertyDescriptor>& properties)
{
}

void TraceSQLStatement::InitPrototype(std::vector<Napi::ObjectWrap<TraceSQLStatement>::PropertyDescriptor>& properties)
{
}

void TraceBLRStatement::InitPrototype(std::vector<Napi::ObjectWrap<TraceBLRStatement>::PropertyDescriptor>& properties)
{
}

void TraceDYNRequest::InitPrototype(std::vector<Napi::ObjectWrap<TraceDYNRequest>::PropertyDescriptor>& properties)
{
}

void TraceContextVariable::InitPrototype(std::vector<Napi::ObjectWrap<TraceContextVariable>::PropertyDescriptor>& properties)
{
}

void TraceProcedure::InitPrototype(std::vector<Napi::ObjectWrap<TraceProcedure>::PropertyDescriptor>& properties)
{
}

void TraceFunction::InitPrototype(std::vector<Napi::ObjectWrap<TraceFunction>::PropertyDescriptor>& properties)
{
}

void TraceTrigger::InitPrototype(std::vector<Napi::ObjectWrap<TraceTrigger>::PropertyDescriptor>& properties)
{
}

void TraceServiceConnection::InitPrototype(std::vector<Napi::ObjectWrap<TraceServiceConnection>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("getKindSync", &TraceServiceConnection::getKindSync));
	properties.push_back(InstanceMethod("getKindAsync", &TraceServiceConnection::getKindAsync));
	properties.push_back(InstanceMethod("getProcessIDSync", &TraceServiceConnection::getProcessIDSync));
	properties.push_back(InstanceMethod("getProcessIDAsync", &TraceServiceConnection::getProcessIDAsync));
	properties.push_back(InstanceMethod("getUserNameSync", &TraceServiceConnection::getUserNameSync));
	properties.push_back(InstanceMethod("getUserNameAsync", &TraceServiceConnection::getUserNameAsync));
	properties.push_back(InstanceMethod("getRoleNameSync", &TraceServiceConnection::getRoleNameSync));
	properties.push_back(InstanceMethod("getRoleNameAsync", &TraceServiceConnection::getRoleNameAsync));
	properties.push_back(InstanceMethod("getCharSetSync", &TraceServiceConnection::getCharSetSync));
	properties.push_back(InstanceMethod("getCharSetAsync", &TraceServiceConnection::getCharSetAsync));
	properties.push_back(InstanceMethod("getRemoteProtocolSync", &TraceServiceConnection::getRemoteProtocolSync));
	properties.push_back(InstanceMethod("getRemoteProtocolAsync", &TraceServiceConnection::getRemoteProtocolAsync));
	properties.push_back(InstanceMethod("getRemoteAddressSync", &TraceServiceConnection::getRemoteAddressSync));
	properties.push_back(InstanceMethod("getRemoteAddressAsync", &TraceServiceConnection::getRemoteAddressAsync));
	properties.push_back(InstanceMethod("getRemoteProcessIDSync", &TraceServiceConnection::getRemoteProcessIDSync));
	properties.push_back(InstanceMethod("getRemoteProcessIDAsync", &TraceServiceConnection::getRemoteProcessIDAsync));
	properties.push_back(InstanceMethod("getRemoteProcessNameSync", &TraceServiceConnection::getRemoteProcessNameSync));
	properties.push_back(InstanceMethod("getRemoteProcessNameAsync", &TraceServiceConnection::getRemoteProcessNameAsync));
}

MethodStart<unsigned> TraceServiceConnection::getKindStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceServiceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getKind();
	};
}

Napi::Value TraceServiceConnection::getKindFinish(const Napi::Env env, unsigned ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> TraceServiceConnection::getProcessIDStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceServiceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getProcessID();
	};
}

Napi::Value TraceServiceConnection::getProcessIDFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceServiceConnection::getUserNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceServiceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getUserName();
	};
}

Napi::Value TraceServiceConnection::getUserNameFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceServiceConnection::getRoleNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceServiceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getRoleName();
	};
}

Napi::Value TraceServiceConnection::getRoleNameFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceServiceConnection::getCharSetStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceServiceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getCharSet();
	};
}

Napi::Value TraceServiceConnection::getCharSetFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceServiceConnection::getRemoteProtocolStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceServiceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getRemoteProtocol();
	};
}

Napi::Value TraceServiceConnection::getRemoteProtocolFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceServiceConnection::getRemoteAddressStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceServiceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getRemoteAddress();
	};
}

Napi::Value TraceServiceConnection::getRemoteAddressFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<int> TraceServiceConnection::getRemoteProcessIDStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceServiceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getRemoteProcessID();
	};
}

Napi::Value TraceServiceConnection::getRemoteProcessIDFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<std::string> TraceServiceConnection::getRemoteProcessNameStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceServiceConnection>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getRemoteProcessName();
	};
}

Napi::Value TraceServiceConnection::getRemoteProcessNameFinish(const Napi::Env env, std::string ret)
{
	return Napi::Value::From(env, ret);
}

void TraceStatusVector::InitPrototype(std::vector<Napi::ObjectWrap<TraceStatusVector>::PropertyDescriptor>& properties)
{
}

void TraceSweepInfo::InitPrototype(std::vector<Napi::ObjectWrap<TraceSweepInfo>::PropertyDescriptor>& properties)
{
}

void TraceLogWriter::InitPrototype(std::vector<Napi::ObjectWrap<TraceLogWriter>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &TraceLogWriter::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &TraceLogWriter::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &TraceLogWriter::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &TraceLogWriter::releaseAsync));
}

MethodStart<void*> TraceLogWriter::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceLogWriter>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value TraceLogWriter::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> TraceLogWriter::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceLogWriter>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value TraceLogWriter::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

void TraceInitInfo::InitPrototype(std::vector<Napi::ObjectWrap<TraceInitInfo>::PropertyDescriptor>& properties)
{
}

void TracePlugin::InitPrototype(std::vector<Napi::ObjectWrap<TracePlugin>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &TracePlugin::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &TracePlugin::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &TracePlugin::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &TracePlugin::releaseAsync));
}

MethodStart<void*> TracePlugin::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TracePlugin>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value TracePlugin::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> TracePlugin::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TracePlugin>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value TracePlugin::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

void TraceFactory::InitPrototype(std::vector<Napi::ObjectWrap<TraceFactory>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("addRefSync", &TraceFactory::addRefSync));
	properties.push_back(InstanceMethod("addRefAsync", &TraceFactory::addRefAsync));
	properties.push_back(InstanceMethod("releaseSync", &TraceFactory::releaseSync));
	properties.push_back(InstanceMethod("releaseAsync", &TraceFactory::releaseAsync));
	properties.push_back(InstanceMethod("setOwnerSync", &TraceFactory::setOwnerSync));
	properties.push_back(InstanceMethod("setOwnerAsync", &TraceFactory::setOwnerAsync));
	properties.push_back(InstanceMethod("getOwnerSync", &TraceFactory::getOwnerSync));
	properties.push_back(InstanceMethod("getOwnerAsync", &TraceFactory::getOwnerAsync));
}

MethodStart<void*> TraceFactory::addRefStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceFactory>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

Napi::Value TraceFactory::addRefFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<int> TraceFactory::releaseStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceFactory>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->release();
	};
}

Napi::Value TraceFactory::releaseFinish(const Napi::Env env, int ret)
{
	return Napi::Value::From(env, ret);
}

MethodStart<void*> TraceFactory::setOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceFactory>::Unwrap(info.This().ToObject());
	auto* r = ReferenceCounted::CheckedUnwrap(info.Env(), info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

Napi::Value TraceFactory::setOwnerFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IReferenceCounted*> TraceFactory::getOwnerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<TraceFactory>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

Napi::Value TraceFactory::getOwnerFinish(const Napi::Env env, fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(env, ret);
}

void UdrFunctionFactory::InitPrototype(std::vector<Napi::ObjectWrap<UdrFunctionFactory>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("disposeSync", &UdrFunctionFactory::disposeSync));
	properties.push_back(InstanceMethod("disposeAsync", &UdrFunctionFactory::disposeAsync));
	properties.push_back(InstanceMethod("setupSync", &UdrFunctionFactory::setupSync));
	properties.push_back(InstanceMethod("setupAsync", &UdrFunctionFactory::setupAsync));
	properties.push_back(InstanceMethod("newItemSync", &UdrFunctionFactory::newItemSync));
	properties.push_back(InstanceMethod("newItemAsync", &UdrFunctionFactory::newItemAsync));
}

MethodStart<void*> UdrFunctionFactory::disposeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<UdrFunctionFactory>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

Napi::Value UdrFunctionFactory::disposeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> UdrFunctionFactory::setupStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<UdrFunctionFactory>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* context = ExternalContext::CheckedUnwrap(info.Env(), info[1], "context argument", true);
	auto* metadata = RoutineMetadata::CheckedUnwrap(info.Env(), info[2], "metadata argument", true);
	auto* inBuilder = MetadataBuilder::CheckedUnwrap(info.Env(), info[3], "inBuilder argument", true);
	auto* outBuilder = MetadataBuilder::CheckedUnwrap(info.Env(), info[4], "outBuilder argument", true);

	return [obj, status, context, metadata, inBuilder, outBuilder]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setup(&statusWrapper, (context ? context->interface : nullptr), (metadata ? metadata->interface : nullptr), (inBuilder ? inBuilder->interface : nullptr), (outBuilder ? outBuilder->interface : nullptr));
		return nullptr;
	};
}

Napi::Value UdrFunctionFactory::setupFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IExternalFunction*> UdrFunctionFactory::newItemStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<UdrFunctionFactory>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* context = ExternalContext::CheckedUnwrap(info.Env(), info[1], "context argument", true);
	auto* metadata = RoutineMetadata::CheckedUnwrap(info.Env(), info[2], "metadata argument", true);

	return [obj, status, context, metadata]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->newItem(&statusWrapper, (context ? context->interface : nullptr), (metadata ? metadata->interface : nullptr));
	};
}

Napi::Value UdrFunctionFactory::newItemFinish(const Napi::Env env, fb::IExternalFunction* ret)
{
	return ExternalFunction::NewInstance(env, ret);
}

void UdrProcedureFactory::InitPrototype(std::vector<Napi::ObjectWrap<UdrProcedureFactory>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("disposeSync", &UdrProcedureFactory::disposeSync));
	properties.push_back(InstanceMethod("disposeAsync", &UdrProcedureFactory::disposeAsync));
	properties.push_back(InstanceMethod("setupSync", &UdrProcedureFactory::setupSync));
	properties.push_back(InstanceMethod("setupAsync", &UdrProcedureFactory::setupAsync));
	properties.push_back(InstanceMethod("newItemSync", &UdrProcedureFactory::newItemSync));
	properties.push_back(InstanceMethod("newItemAsync", &UdrProcedureFactory::newItemAsync));
}

MethodStart<void*> UdrProcedureFactory::disposeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<UdrProcedureFactory>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

Napi::Value UdrProcedureFactory::disposeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> UdrProcedureFactory::setupStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<UdrProcedureFactory>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* context = ExternalContext::CheckedUnwrap(info.Env(), info[1], "context argument", true);
	auto* metadata = RoutineMetadata::CheckedUnwrap(info.Env(), info[2], "metadata argument", true);
	auto* inBuilder = MetadataBuilder::CheckedUnwrap(info.Env(), info[3], "inBuilder argument", true);
	auto* outBuilder = MetadataBuilder::CheckedUnwrap(info.Env(), info[4], "outBuilder argument", true);

	return [obj, status, context, metadata, inBuilder, outBuilder]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setup(&statusWrapper, (context ? context->interface : nullptr), (metadata ? metadata->interface : nullptr), (inBuilder ? inBuilder->interface : nullptr), (outBuilder ? outBuilder->interface : nullptr));
		return nullptr;
	};
}

Napi::Value UdrProcedureFactory::setupFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IExternalProcedure*> UdrProcedureFactory::newItemStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<UdrProcedureFactory>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* context = ExternalContext::CheckedUnwrap(info.Env(), info[1], "context argument", true);
	auto* metadata = RoutineMetadata::CheckedUnwrap(info.Env(), info[2], "metadata argument", true);

	return [obj, status, context, metadata]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->newItem(&statusWrapper, (context ? context->interface : nullptr), (metadata ? metadata->interface : nullptr));
	};
}

Napi::Value UdrProcedureFactory::newItemFinish(const Napi::Env env, fb::IExternalProcedure* ret)
{
	return ExternalProcedure::NewInstance(env, ret);
}

void UdrTriggerFactory::InitPrototype(std::vector<Napi::ObjectWrap<UdrTriggerFactory>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("disposeSync", &UdrTriggerFactory::disposeSync));
	properties.push_back(InstanceMethod("disposeAsync", &UdrTriggerFactory::disposeAsync));
	properties.push_back(InstanceMethod("setupSync", &UdrTriggerFactory::setupSync));
	properties.push_back(InstanceMethod("setupAsync", &UdrTriggerFactory::setupAsync));
	properties.push_back(InstanceMethod("newItemSync", &UdrTriggerFactory::newItemSync));
	properties.push_back(InstanceMethod("newItemAsync", &UdrTriggerFactory::newItemAsync));
}

MethodStart<void*> UdrTriggerFactory::disposeStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<UdrTriggerFactory>::Unwrap(info.This().ToObject());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

Napi::Value UdrTriggerFactory::disposeFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> UdrTriggerFactory::setupStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<UdrTriggerFactory>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* context = ExternalContext::CheckedUnwrap(info.Env(), info[1], "context argument", true);
	auto* metadata = RoutineMetadata::CheckedUnwrap(info.Env(), info[2], "metadata argument", true);
	auto* fieldsBuilder = MetadataBuilder::CheckedUnwrap(info.Env(), info[3], "fieldsBuilder argument", true);

	return [obj, status, context, metadata, fieldsBuilder]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setup(&statusWrapper, (context ? context->interface : nullptr), (metadata ? metadata->interface : nullptr), (fieldsBuilder ? fieldsBuilder->interface : nullptr));
		return nullptr;
	};
}

Napi::Value UdrTriggerFactory::setupFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<fb::IExternalTrigger*> UdrTriggerFactory::newItemStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<UdrTriggerFactory>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	auto* context = ExternalContext::CheckedUnwrap(info.Env(), info[1], "context argument", true);
	auto* metadata = RoutineMetadata::CheckedUnwrap(info.Env(), info[2], "metadata argument", true);

	return [obj, status, context, metadata]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->newItem(&statusWrapper, (context ? context->interface : nullptr), (metadata ? metadata->interface : nullptr));
	};
}

Napi::Value UdrTriggerFactory::newItemFinish(const Napi::Env env, fb::IExternalTrigger* ret)
{
	return ExternalTrigger::NewInstance(env, ret);
}

void UdrPlugin::InitPrototype(std::vector<Napi::ObjectWrap<UdrPlugin>::PropertyDescriptor>& properties)
{
	properties.push_back(InstanceMethod("getMasterSync", &UdrPlugin::getMasterSync));
	properties.push_back(InstanceMethod("getMasterAsync", &UdrPlugin::getMasterAsync));
	properties.push_back(InstanceMethod("registerFunctionSync", &UdrPlugin::registerFunctionSync));
	properties.push_back(InstanceMethod("registerFunctionAsync", &UdrPlugin::registerFunctionAsync));
	properties.push_back(InstanceMethod("registerProcedureSync", &UdrPlugin::registerProcedureSync));
	properties.push_back(InstanceMethod("registerProcedureAsync", &UdrPlugin::registerProcedureAsync));
	properties.push_back(InstanceMethod("registerTriggerSync", &UdrPlugin::registerTriggerSync));
	properties.push_back(InstanceMethod("registerTriggerAsync", &UdrPlugin::registerTriggerAsync));
}

MethodStart<fb::IMaster*> UdrPlugin::getMasterStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<UdrPlugin>::Unwrap(info.This().ToObject());

	return [obj]() {
		return obj->interface->getMaster();
	};
}

Napi::Value UdrPlugin::getMasterFinish(const Napi::Env env, fb::IMaster* ret)
{
	return Master::NewInstance(env, ret);
}

MethodStart<void*> UdrPlugin::registerFunctionStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<UdrPlugin>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string name = info[1].ToString().Utf8Value();
	auto* factory = UdrFunctionFactory::CheckedUnwrap(info.Env(), info[2], "factory argument", true);

	return [obj, status, name, factory]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->registerFunction(&statusWrapper, name.c_str(), (factory ? factory->interface : nullptr));
		return nullptr;
	};
}

Napi::Value UdrPlugin::registerFunctionFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> UdrPlugin::registerProcedureStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<UdrPlugin>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string name = info[1].ToString().Utf8Value();
	auto* factory = UdrProcedureFactory::CheckedUnwrap(info.Env(), info[2], "factory argument", true);

	return [obj, status, name, factory]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->registerProcedure(&statusWrapper, name.c_str(), (factory ? factory->interface : nullptr));
		return nullptr;
	};
}

Napi::Value UdrPlugin::registerProcedureFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

MethodStart<void*> UdrPlugin::registerTriggerStart(bool async, const Napi::CallbackInfo& info)
{
	auto* obj = ObjectWrap<UdrPlugin>::Unwrap(info.This().ToObject());
	auto* status = Status::CheckedUnwrap(info.Env(), info[0], "status argument", true);
	std::string name = info[1].ToString().Utf8Value();
	auto* factory = UdrTriggerFactory::CheckedUnwrap(info.Env(), info[2], "factory argument", true);

	return [obj, status, name, factory]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->registerTrigger(&statusWrapper, name.c_str(), (factory ? factory->interface : nullptr));
		return nullptr;
	};
}

Napi::Value UdrPlugin::registerTriggerFinish(const Napi::Env env, void* ret)
{
	return env.Undefined();
}

static void initClasses(Napi::Env env, Napi::Object& exports)
{
	Versioned::Init(env, exports, "Versioned");
	ReferenceCounted::Init(env, exports, "ReferenceCounted");
	Disposable::Init(env, exports, "Disposable");
	Status::Init(env, exports, "Status");
	Master::Init(env, exports, "Master");
	PluginBase::Init(env, exports, "PluginBase");
	PluginSet::Init(env, exports, "PluginSet");
	ConfigEntry::Init(env, exports, "ConfigEntry");
	Config::Init(env, exports, "Config");
	FirebirdConf::Init(env, exports, "FirebirdConf");
	PluginConfig::Init(env, exports, "PluginConfig");
	PluginFactory::Init(env, exports, "PluginFactory");
	PluginModule::Init(env, exports, "PluginModule");
	PluginManager::Init(env, exports, "PluginManager");
	CryptKey::Init(env, exports, "CryptKey");
	ConfigManager::Init(env, exports, "ConfigManager");
	EventCallback::Init(env, exports, "EventCallback");
	Blob::Init(env, exports, "Blob");
	Transaction::Init(env, exports, "Transaction");
	MessageMetadata::Init(env, exports, "MessageMetadata");
	MetadataBuilder::Init(env, exports, "MetadataBuilder");
	ResultSet::Init(env, exports, "ResultSet");
	Statement::Init(env, exports, "Statement");
	Request::Init(env, exports, "Request");
	Events::Init(env, exports, "Events");
	Attachment::Init(env, exports, "Attachment");
	Service::Init(env, exports, "Service");
	Provider::Init(env, exports, "Provider");
	DtcStart::Init(env, exports, "DtcStart");
	Dtc::Init(env, exports, "Dtc");
	Auth::Init(env, exports, "Auth");
	Writer::Init(env, exports, "Writer");
	ServerBlock::Init(env, exports, "ServerBlock");
	ClientBlock::Init(env, exports, "ClientBlock");
	Server::Init(env, exports, "Server");
	Client::Init(env, exports, "Client");
	UserField::Init(env, exports, "UserField");
	CharUserField::Init(env, exports, "CharUserField");
	IntUserField::Init(env, exports, "IntUserField");
	User::Init(env, exports, "User");
	ListUsers::Init(env, exports, "ListUsers");
	LogonInfo::Init(env, exports, "LogonInfo");
	Management::Init(env, exports, "Management");
	WireCryptPlugin::Init(env, exports, "WireCryptPlugin");
	CryptKeyCallback::Init(env, exports, "CryptKeyCallback");
	KeyHolderPlugin::Init(env, exports, "KeyHolderPlugin");
	DbCryptPlugin::Init(env, exports, "DbCryptPlugin");
	ExternalContext::Init(env, exports, "ExternalContext");
	ExternalResultSet::Init(env, exports, "ExternalResultSet");
	ExternalFunction::Init(env, exports, "ExternalFunction");
	ExternalProcedure::Init(env, exports, "ExternalProcedure");
	ExternalTrigger::Init(env, exports, "ExternalTrigger");
	RoutineMetadata::Init(env, exports, "RoutineMetadata");
	ExternalEngine::Init(env, exports, "ExternalEngine");
	Timer::Init(env, exports, "Timer");
	TimerControl::Init(env, exports, "TimerControl");
	VersionCallback::Init(env, exports, "VersionCallback");
	Util::Init(env, exports, "Util");
	OffsetsCallback::Init(env, exports, "OffsetsCallback");
	XpbBuilder::Init(env, exports, "XpbBuilder");
	TraceConnection::Init(env, exports, "TraceConnection");
	TraceDatabaseConnection::Init(env, exports, "TraceDatabaseConnection");
	TraceTransaction::Init(env, exports, "TraceTransaction");
	TraceParams::Init(env, exports, "TraceParams");
	TraceStatement::Init(env, exports, "TraceStatement");
	TraceSQLStatement::Init(env, exports, "TraceSQLStatement");
	TraceBLRStatement::Init(env, exports, "TraceBLRStatement");
	TraceDYNRequest::Init(env, exports, "TraceDYNRequest");
	TraceContextVariable::Init(env, exports, "TraceContextVariable");
	TraceProcedure::Init(env, exports, "TraceProcedure");
	TraceFunction::Init(env, exports, "TraceFunction");
	TraceTrigger::Init(env, exports, "TraceTrigger");
	TraceServiceConnection::Init(env, exports, "TraceServiceConnection");
	TraceStatusVector::Init(env, exports, "TraceStatusVector");
	TraceSweepInfo::Init(env, exports, "TraceSweepInfo");
	TraceLogWriter::Init(env, exports, "TraceLogWriter");
	TraceInitInfo::Init(env, exports, "TraceInitInfo");
	TracePlugin::Init(env, exports, "TracePlugin");
	TraceFactory::Init(env, exports, "TraceFactory");
	UdrFunctionFactory::Init(env, exports, "UdrFunctionFactory");
	UdrProcedureFactory::Init(env, exports, "UdrProcedureFactory");
	UdrTriggerFactory::Init(env, exports, "UdrTriggerFactory");
	UdrPlugin::Init(env, exports, "UdrPlugin");
}
