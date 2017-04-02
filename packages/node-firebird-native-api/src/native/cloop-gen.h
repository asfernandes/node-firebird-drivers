// Auto-generated file. Do not edit!

class VersionedImpl : public BaseImpl<VersionedImpl, fb::IVersionedImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Versioned : public BaseClass<Versioned, fb::IVersioned>
{
friend class BaseClass<Versioned, fb::IVersioned>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
};


class ReferenceCountedImpl : public BaseImpl<ReferenceCountedImpl, fb::IReferenceCountedImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class ReferenceCounted : public BaseClass<ReferenceCounted, fb::IReferenceCounted>
{
friend class BaseClass<ReferenceCounted, fb::IReferenceCounted>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
};


class DisposableImpl : public BaseImpl<DisposableImpl, fb::IDisposableImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Disposable : public BaseClass<Disposable, fb::IDisposable>
{
friend class BaseClass<Disposable, fb::IDisposable>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> disposeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> disposeFinish(void* ret);
};


class StatusImpl : public BaseImpl<StatusImpl, fb::IStatusImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Status : public BaseClass<Status, fb::IStatus>
{
friend class BaseClass<Status, fb::IStatus>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> disposeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> disposeFinish(void* ret);
	static MethodStart<void*> initStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> initFinish(void* ret);
	static MethodStart<unsigned> getStateStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getStateFinish(unsigned ret);
	static MethodStart<fb::IStatus*> cloneStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> cloneFinish(fb::IStatus* ret);
};


class MasterImpl : public BaseImpl<MasterImpl, fb::IMasterImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Master : public BaseClass<Master, fb::IMaster>
{
friend class BaseClass<Master, fb::IMaster>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<fb::IStatus*> getStatusStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getStatusFinish(fb::IStatus* ret);
	static MethodStart<fb::IProvider*> getDispatcherStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getDispatcherFinish(fb::IProvider* ret);
	static MethodStart<fb::IPluginManager*> getPluginManagerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getPluginManagerFinish(fb::IPluginManager* ret);
	static MethodStart<fb::ITimerControl*> getTimerControlStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getTimerControlFinish(fb::ITimerControl* ret);
	static MethodStart<fb::IDtc*> getDtcStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getDtcFinish(fb::IDtc* ret);
	static MethodStart<fb::IAttachment*> registerAttachmentStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> registerAttachmentFinish(fb::IAttachment* ret);
	static MethodStart<fb::ITransaction*> registerTransactionStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> registerTransactionFinish(fb::ITransaction* ret);
	static MethodStart<fb::IMetadataBuilder*> getMetadataBuilderStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getMetadataBuilderFinish(fb::IMetadataBuilder* ret);
	static MethodStart<int> serverModeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> serverModeFinish(int ret);
	static MethodStart<fb::IUtil*> getUtilInterfaceStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getUtilInterfaceFinish(fb::IUtil* ret);
	static MethodStart<fb::IConfigManager*> getConfigManagerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getConfigManagerFinish(fb::IConfigManager* ret);
	static MethodStart<FB_BOOLEAN> getProcessExitingStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getProcessExitingFinish(FB_BOOLEAN ret);
};


class PluginBaseImpl : public BaseImpl<PluginBaseImpl, fb::IPluginBaseImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class PluginBase : public BaseClass<PluginBase, fb::IPluginBase>
{
friend class BaseClass<PluginBase, fb::IPluginBase>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setOwnerFinish(void* ret);
	static MethodStart<fb::IReferenceCounted*> getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getOwnerFinish(fb::IReferenceCounted* ret);
};


class PluginSetImpl : public BaseImpl<PluginSetImpl, fb::IPluginSetImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class PluginSet : public BaseClass<PluginSet, fb::IPluginSet>
{
friend class BaseClass<PluginSet, fb::IPluginSet>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<std::string> getNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getNameFinish(std::string ret);
	static MethodStart<std::string> getModuleNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getModuleNameFinish(std::string ret);
	static MethodStart<fb::IPluginBase*> getPluginStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getPluginFinish(fb::IPluginBase* ret);
	static MethodStart<void*> nextStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> nextFinish(void* ret);
	static MethodStart<void*> setStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setFinish(void* ret);
};


class ConfigEntryImpl : public BaseImpl<ConfigEntryImpl, fb::IConfigEntryImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class ConfigEntry : public BaseClass<ConfigEntry, fb::IConfigEntry>
{
friend class BaseClass<ConfigEntry, fb::IConfigEntry>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<std::string> getNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getNameFinish(std::string ret);
	static MethodStart<std::string> getValueStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getValueFinish(std::string ret);
	static MethodStart<int64_t> getIntValueStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getIntValueFinish(int64_t ret);
	static MethodStart<FB_BOOLEAN> getBoolValueStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getBoolValueFinish(FB_BOOLEAN ret);
	static MethodStart<fb::IConfig*> getSubConfigStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getSubConfigFinish(fb::IConfig* ret);
};


class ConfigImpl : public BaseImpl<ConfigImpl, fb::IConfigImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Config : public BaseClass<Config, fb::IConfig>
{
friend class BaseClass<Config, fb::IConfig>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<fb::IConfigEntry*> findStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> findFinish(fb::IConfigEntry* ret);
	static MethodStart<fb::IConfigEntry*> findValueStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> findValueFinish(fb::IConfigEntry* ret);
	static MethodStart<fb::IConfigEntry*> findPosStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> findPosFinish(fb::IConfigEntry* ret);
};


class FirebirdConfImpl : public BaseImpl<FirebirdConfImpl, fb::IFirebirdConfImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class FirebirdConf : public BaseClass<FirebirdConf, fb::IFirebirdConf>
{
friend class BaseClass<FirebirdConf, fb::IFirebirdConf>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<unsigned> getKeyStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getKeyFinish(unsigned ret);
	static MethodStart<int64_t> asIntegerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> asIntegerFinish(int64_t ret);
	static MethodStart<std::string> asStringStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> asStringFinish(std::string ret);
	static MethodStart<FB_BOOLEAN> asBooleanStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> asBooleanFinish(FB_BOOLEAN ret);
};


class PluginConfigImpl : public BaseImpl<PluginConfigImpl, fb::IPluginConfigImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class PluginConfig : public BaseClass<PluginConfig, fb::IPluginConfig>
{
friend class BaseClass<PluginConfig, fb::IPluginConfig>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<std::string> getConfigFileNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getConfigFileNameFinish(std::string ret);
	static MethodStart<fb::IConfig*> getDefaultConfigStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getDefaultConfigFinish(fb::IConfig* ret);
	static MethodStart<fb::IFirebirdConf*> getFirebirdConfStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getFirebirdConfFinish(fb::IFirebirdConf* ret);
	static MethodStart<void*> setReleaseDelayStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setReleaseDelayFinish(void* ret);
};


class PluginFactoryImpl : public BaseImpl<PluginFactoryImpl, fb::IPluginFactoryImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class PluginFactory : public BaseClass<PluginFactory, fb::IPluginFactory>
{
friend class BaseClass<PluginFactory, fb::IPluginFactory>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<fb::IPluginBase*> createPluginStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> createPluginFinish(fb::IPluginBase* ret);
};


class PluginModuleImpl : public BaseImpl<PluginModuleImpl, fb::IPluginModuleImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class PluginModule : public BaseClass<PluginModule, fb::IPluginModule>
{
friend class BaseClass<PluginModule, fb::IPluginModule>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> doCleanStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> doCleanFinish(void* ret);
};


class PluginManagerImpl : public BaseImpl<PluginManagerImpl, fb::IPluginManagerImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class PluginManager : public BaseClass<PluginManager, fb::IPluginManager>
{
friend class BaseClass<PluginManager, fb::IPluginManager>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> registerPluginFactoryStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> registerPluginFactoryFinish(void* ret);
	static MethodStart<void*> registerModuleStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> registerModuleFinish(void* ret);
	static MethodStart<void*> unregisterModuleStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> unregisterModuleFinish(void* ret);
	static MethodStart<fb::IPluginSet*> getPluginsStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getPluginsFinish(fb::IPluginSet* ret);
	static MethodStart<fb::IConfig*> getConfigStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getConfigFinish(fb::IConfig* ret);
	static MethodStart<void*> releasePluginStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releasePluginFinish(void* ret);
};


class CryptKeyImpl : public BaseImpl<CryptKeyImpl, fb::ICryptKeyImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class CryptKey : public BaseClass<CryptKey, fb::ICryptKey>
{
friend class BaseClass<CryptKey, fb::ICryptKey>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
};


class ConfigManagerImpl : public BaseImpl<ConfigManagerImpl, fb::IConfigManagerImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class ConfigManager : public BaseClass<ConfigManager, fb::IConfigManager>
{
friend class BaseClass<ConfigManager, fb::IConfigManager>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<std::string> getDirectoryStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getDirectoryFinish(std::string ret);
	static MethodStart<fb::IFirebirdConf*> getFirebirdConfStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getFirebirdConfFinish(fb::IFirebirdConf* ret);
	static MethodStart<fb::IFirebirdConf*> getDatabaseConfStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getDatabaseConfFinish(fb::IFirebirdConf* ret);
	static MethodStart<fb::IConfig*> getPluginConfigStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getPluginConfigFinish(fb::IConfig* ret);
	static MethodStart<std::string> getInstallDirectoryStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getInstallDirectoryFinish(std::string ret);
	static MethodStart<std::string> getRootDirectoryStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getRootDirectoryFinish(std::string ret);
};


class EventCallbackImpl : public BaseImpl<EventCallbackImpl, fb::IEventCallbackImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class EventCallback : public BaseClass<EventCallback, fb::IEventCallback>
{
friend class BaseClass<EventCallback, fb::IEventCallback>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> eventCallbackFunctionStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> eventCallbackFunctionFinish(void* ret);
};


class BlobImpl : public BaseImpl<BlobImpl, fb::IBlobImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Blob : public BaseClass<Blob, fb::IBlob>
{
friend class BaseClass<Blob, fb::IBlob>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> getInfoStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getInfoFinish(void* ret);
	static MethodStart<int> getSegmentStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getSegmentFinish(int ret);
	static MethodStart<void*> putSegmentStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> putSegmentFinish(void* ret);
	static MethodStart<void*> cancelStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> cancelFinish(void* ret);
	static MethodStart<void*> closeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> closeFinish(void* ret);
	static MethodStart<int> seekStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> seekFinish(int ret);
};


class TransactionImpl : public BaseImpl<TransactionImpl, fb::ITransactionImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Transaction : public BaseClass<Transaction, fb::ITransaction>
{
friend class BaseClass<Transaction, fb::ITransaction>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> getInfoStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getInfoFinish(void* ret);
	static MethodStart<void*> prepareStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> prepareFinish(void* ret);
	static MethodStart<void*> commitStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> commitFinish(void* ret);
	static MethodStart<void*> commitRetainingStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> commitRetainingFinish(void* ret);
	static MethodStart<void*> rollbackStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> rollbackFinish(void* ret);
	static MethodStart<void*> rollbackRetainingStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> rollbackRetainingFinish(void* ret);
	static MethodStart<void*> disconnectStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> disconnectFinish(void* ret);
	static MethodStart<fb::ITransaction*> joinStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> joinFinish(fb::ITransaction* ret);
	static MethodStart<fb::ITransaction*> validateStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> validateFinish(fb::ITransaction* ret);
	static MethodStart<fb::ITransaction*> enterDtcStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> enterDtcFinish(fb::ITransaction* ret);
};


class MessageMetadataImpl : public BaseImpl<MessageMetadataImpl, fb::IMessageMetadataImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class MessageMetadata : public BaseClass<MessageMetadata, fb::IMessageMetadata>
{
friend class BaseClass<MessageMetadata, fb::IMessageMetadata>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<unsigned> getCountStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getCountFinish(unsigned ret);
	static MethodStart<std::string> getFieldStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getFieldFinish(std::string ret);
	static MethodStart<std::string> getRelationStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getRelationFinish(std::string ret);
	static MethodStart<std::string> getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getOwnerFinish(std::string ret);
	static MethodStart<std::string> getAliasStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getAliasFinish(std::string ret);
	static MethodStart<unsigned> getTypeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getTypeFinish(unsigned ret);
	static MethodStart<FB_BOOLEAN> isNullableStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> isNullableFinish(FB_BOOLEAN ret);
	static MethodStart<int> getSubTypeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getSubTypeFinish(int ret);
	static MethodStart<unsigned> getLengthStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getLengthFinish(unsigned ret);
	static MethodStart<int> getScaleStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getScaleFinish(int ret);
	static MethodStart<unsigned> getCharSetStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getCharSetFinish(unsigned ret);
	static MethodStart<unsigned> getOffsetStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getOffsetFinish(unsigned ret);
	static MethodStart<unsigned> getNullOffsetStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getNullOffsetFinish(unsigned ret);
	static MethodStart<fb::IMetadataBuilder*> getBuilderStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getBuilderFinish(fb::IMetadataBuilder* ret);
	static MethodStart<unsigned> getMessageLengthStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getMessageLengthFinish(unsigned ret);
};


class MetadataBuilderImpl : public BaseImpl<MetadataBuilderImpl, fb::IMetadataBuilderImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class MetadataBuilder : public BaseClass<MetadataBuilder, fb::IMetadataBuilder>
{
friend class BaseClass<MetadataBuilder, fb::IMetadataBuilder>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> setTypeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setTypeFinish(void* ret);
	static MethodStart<void*> setSubTypeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setSubTypeFinish(void* ret);
	static MethodStart<void*> setLengthStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setLengthFinish(void* ret);
	static MethodStart<void*> setCharSetStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setCharSetFinish(void* ret);
	static MethodStart<void*> setScaleStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setScaleFinish(void* ret);
	static MethodStart<void*> truncateStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> truncateFinish(void* ret);
	static MethodStart<void*> moveNameToIndexStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> moveNameToIndexFinish(void* ret);
	static MethodStart<void*> removeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> removeFinish(void* ret);
	static MethodStart<unsigned> addFieldStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addFieldFinish(unsigned ret);
	static MethodStart<fb::IMessageMetadata*> getMetadataStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getMetadataFinish(fb::IMessageMetadata* ret);
};


class ResultSetImpl : public BaseImpl<ResultSetImpl, fb::IResultSetImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class ResultSet : public BaseClass<ResultSet, fb::IResultSet>
{
friend class BaseClass<ResultSet, fb::IResultSet>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<int> fetchNextStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> fetchNextFinish(int ret);
	static MethodStart<int> fetchPriorStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> fetchPriorFinish(int ret);
	static MethodStart<int> fetchFirstStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> fetchFirstFinish(int ret);
	static MethodStart<int> fetchLastStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> fetchLastFinish(int ret);
	static MethodStart<int> fetchAbsoluteStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> fetchAbsoluteFinish(int ret);
	static MethodStart<int> fetchRelativeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> fetchRelativeFinish(int ret);
	static MethodStart<FB_BOOLEAN> isEofStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> isEofFinish(FB_BOOLEAN ret);
	static MethodStart<FB_BOOLEAN> isBofStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> isBofFinish(FB_BOOLEAN ret);
	static MethodStart<fb::IMessageMetadata*> getMetadataStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getMetadataFinish(fb::IMessageMetadata* ret);
	static MethodStart<void*> closeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> closeFinish(void* ret);
	static MethodStart<void*> setDelayedOutputFormatStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setDelayedOutputFormatFinish(void* ret);
};


class StatementImpl : public BaseImpl<StatementImpl, fb::IStatementImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Statement : public BaseClass<Statement, fb::IStatement>
{
friend class BaseClass<Statement, fb::IStatement>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> getInfoStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getInfoFinish(void* ret);
	static MethodStart<unsigned> getTypeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getTypeFinish(unsigned ret);
	static MethodStart<std::string> getPlanStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getPlanFinish(std::string ret);
	static MethodStart<uint64_t> getAffectedRecordsStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getAffectedRecordsFinish(uint64_t ret);
	static MethodStart<fb::IMessageMetadata*> getInputMetadataStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getInputMetadataFinish(fb::IMessageMetadata* ret);
	static MethodStart<fb::IMessageMetadata*> getOutputMetadataStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getOutputMetadataFinish(fb::IMessageMetadata* ret);
	static MethodStart<fb::ITransaction*> executeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> executeFinish(fb::ITransaction* ret);
	static MethodStart<fb::IResultSet*> openCursorStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> openCursorFinish(fb::IResultSet* ret);
	static MethodStart<void*> setCursorNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setCursorNameFinish(void* ret);
	static MethodStart<void*> freeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> freeFinish(void* ret);
	static MethodStart<unsigned> getFlagsStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getFlagsFinish(unsigned ret);
};


class RequestImpl : public BaseImpl<RequestImpl, fb::IRequestImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Request : public BaseClass<Request, fb::IRequest>
{
friend class BaseClass<Request, fb::IRequest>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> receiveStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> receiveFinish(void* ret);
	static MethodStart<void*> sendStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> sendFinish(void* ret);
	static MethodStart<void*> getInfoStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getInfoFinish(void* ret);
	static MethodStart<void*> startStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> startFinish(void* ret);
	static MethodStart<void*> startAndSendStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> startAndSendFinish(void* ret);
	static MethodStart<void*> unwindStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> unwindFinish(void* ret);
	static MethodStart<void*> freeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> freeFinish(void* ret);
};


class EventsImpl : public BaseImpl<EventsImpl, fb::IEventsImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Events : public BaseClass<Events, fb::IEvents>
{
friend class BaseClass<Events, fb::IEvents>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> cancelStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> cancelFinish(void* ret);
};


class AttachmentImpl : public BaseImpl<AttachmentImpl, fb::IAttachmentImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Attachment : public BaseClass<Attachment, fb::IAttachment>
{
friend class BaseClass<Attachment, fb::IAttachment>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> getInfoStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getInfoFinish(void* ret);
	static MethodStart<fb::ITransaction*> startTransactionStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> startTransactionFinish(fb::ITransaction* ret);
	static MethodStart<fb::ITransaction*> reconnectTransactionStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> reconnectTransactionFinish(fb::ITransaction* ret);
	static MethodStart<fb::IRequest*> compileRequestStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> compileRequestFinish(fb::IRequest* ret);
	static MethodStart<void*> transactRequestStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> transactRequestFinish(void* ret);
	static MethodStart<void*> executeDynStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> executeDynFinish(void* ret);
	static MethodStart<fb::IStatement*> prepareStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> prepareFinish(fb::IStatement* ret);
	static MethodStart<fb::ITransaction*> executeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> executeFinish(fb::ITransaction* ret);
	static MethodStart<fb::IResultSet*> openCursorStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> openCursorFinish(fb::IResultSet* ret);
	static MethodStart<fb::IEvents*> queEventsStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> queEventsFinish(fb::IEvents* ret);
	static MethodStart<void*> cancelOperationStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> cancelOperationFinish(void* ret);
	static MethodStart<void*> pingStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> pingFinish(void* ret);
	static MethodStart<void*> detachStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> detachFinish(void* ret);
	static MethodStart<void*> dropDatabaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> dropDatabaseFinish(void* ret);
};


class ServiceImpl : public BaseImpl<ServiceImpl, fb::IServiceImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Service : public BaseClass<Service, fb::IService>
{
friend class BaseClass<Service, fb::IService>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> detachStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> detachFinish(void* ret);
	static MethodStart<void*> queryStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> queryFinish(void* ret);
	static MethodStart<void*> startStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> startFinish(void* ret);
};


class ProviderImpl : public BaseImpl<ProviderImpl, fb::IProviderImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Provider : public BaseClass<Provider, fb::IProvider>
{
friend class BaseClass<Provider, fb::IProvider>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setOwnerFinish(void* ret);
	static MethodStart<fb::IReferenceCounted*> getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getOwnerFinish(fb::IReferenceCounted* ret);
	static MethodStart<fb::IAttachment*> attachDatabaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> attachDatabaseFinish(fb::IAttachment* ret);
	static MethodStart<fb::IAttachment*> createDatabaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> createDatabaseFinish(fb::IAttachment* ret);
	static MethodStart<fb::IService*> attachServiceManagerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> attachServiceManagerFinish(fb::IService* ret);
	static MethodStart<void*> shutdownStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> shutdownFinish(void* ret);
	static MethodStart<void*> setDbCryptCallbackStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setDbCryptCallbackFinish(void* ret);
};


class DtcStartImpl : public BaseImpl<DtcStartImpl, fb::IDtcStartImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class DtcStart : public BaseClass<DtcStart, fb::IDtcStart>
{
friend class BaseClass<DtcStart, fb::IDtcStart>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> disposeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> disposeFinish(void* ret);
	static MethodStart<void*> addAttachmentStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addAttachmentFinish(void* ret);
	static MethodStart<void*> addWithTpbStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addWithTpbFinish(void* ret);
	static MethodStart<fb::ITransaction*> startStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> startFinish(fb::ITransaction* ret);
};


class DtcImpl : public BaseImpl<DtcImpl, fb::IDtcImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Dtc : public BaseClass<Dtc, fb::IDtc>
{
friend class BaseClass<Dtc, fb::IDtc>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<fb::ITransaction*> joinStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> joinFinish(fb::ITransaction* ret);
	static MethodStart<fb::IDtcStart*> startBuilderStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> startBuilderFinish(fb::IDtcStart* ret);
};


class AuthImpl : public BaseImpl<AuthImpl, fb::IAuthImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Auth : public BaseClass<Auth, fb::IAuth>
{
friend class BaseClass<Auth, fb::IAuth>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setOwnerFinish(void* ret);
	static MethodStart<fb::IReferenceCounted*> getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getOwnerFinish(fb::IReferenceCounted* ret);
};


class WriterImpl : public BaseImpl<WriterImpl, fb::IWriterImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Writer : public BaseClass<Writer, fb::IWriter>
{
friend class BaseClass<Writer, fb::IWriter>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> resetStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> resetFinish(void* ret);
	static MethodStart<void*> addStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addFinish(void* ret);
	static MethodStart<void*> setTypeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setTypeFinish(void* ret);
	static MethodStart<void*> setDbStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setDbFinish(void* ret);
};


class ServerBlockImpl : public BaseImpl<ServerBlockImpl, fb::IServerBlockImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class ServerBlock : public BaseClass<ServerBlock, fb::IServerBlock>
{
friend class BaseClass<ServerBlock, fb::IServerBlock>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<std::string> getLoginStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getLoginFinish(std::string ret);
	static MethodStart<const unsigned char*> getDataStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getDataFinish(const unsigned char* ret);
	static MethodStart<void*> putDataStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> putDataFinish(void* ret);
	static MethodStart<fb::ICryptKey*> newKeyStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> newKeyFinish(fb::ICryptKey* ret);
};


class ClientBlockImpl : public BaseImpl<ClientBlockImpl, fb::IClientBlockImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class ClientBlock : public BaseClass<ClientBlock, fb::IClientBlock>
{
friend class BaseClass<ClientBlock, fb::IClientBlock>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<std::string> getLoginStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getLoginFinish(std::string ret);
	static MethodStart<std::string> getPasswordStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getPasswordFinish(std::string ret);
	static MethodStart<const unsigned char*> getDataStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getDataFinish(const unsigned char* ret);
	static MethodStart<void*> putDataStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> putDataFinish(void* ret);
	static MethodStart<fb::ICryptKey*> newKeyStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> newKeyFinish(fb::ICryptKey* ret);
};


class ServerImpl : public BaseImpl<ServerImpl, fb::IServerImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Server : public BaseClass<Server, fb::IServer>
{
friend class BaseClass<Server, fb::IServer>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setOwnerFinish(void* ret);
	static MethodStart<fb::IReferenceCounted*> getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getOwnerFinish(fb::IReferenceCounted* ret);
	static MethodStart<int> authenticateStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> authenticateFinish(int ret);
};


class ClientImpl : public BaseImpl<ClientImpl, fb::IClientImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Client : public BaseClass<Client, fb::IClient>
{
friend class BaseClass<Client, fb::IClient>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setOwnerFinish(void* ret);
	static MethodStart<fb::IReferenceCounted*> getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getOwnerFinish(fb::IReferenceCounted* ret);
	static MethodStart<int> authenticateStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> authenticateFinish(int ret);
};


class UserFieldImpl : public BaseImpl<UserFieldImpl, fb::IUserFieldImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class UserField : public BaseClass<UserField, fb::IUserField>
{
friend class BaseClass<UserField, fb::IUserField>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<int> enteredStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> enteredFinish(int ret);
	static MethodStart<int> specifiedStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> specifiedFinish(int ret);
	static MethodStart<void*> setEnteredStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setEnteredFinish(void* ret);
};


class CharUserFieldImpl : public BaseImpl<CharUserFieldImpl, fb::ICharUserFieldImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class CharUserField : public BaseClass<CharUserField, fb::ICharUserField>
{
friend class BaseClass<CharUserField, fb::ICharUserField>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<int> enteredStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> enteredFinish(int ret);
	static MethodStart<int> specifiedStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> specifiedFinish(int ret);
	static MethodStart<void*> setEnteredStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setEnteredFinish(void* ret);
	static MethodStart<std::string> getStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getFinish(std::string ret);
	static MethodStart<void*> setStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setFinish(void* ret);
};


class IntUserFieldImpl : public BaseImpl<IntUserFieldImpl, fb::IIntUserFieldImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class IntUserField : public BaseClass<IntUserField, fb::IIntUserField>
{
friend class BaseClass<IntUserField, fb::IIntUserField>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<int> enteredStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> enteredFinish(int ret);
	static MethodStart<int> specifiedStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> specifiedFinish(int ret);
	static MethodStart<void*> setEnteredStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setEnteredFinish(void* ret);
	static MethodStart<int> getStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getFinish(int ret);
	static MethodStart<void*> setStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setFinish(void* ret);
};


class UserImpl : public BaseImpl<UserImpl, fb::IUserImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class User : public BaseClass<User, fb::IUser>
{
friend class BaseClass<User, fb::IUser>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<unsigned> operationStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> operationFinish(unsigned ret);
	static MethodStart<fb::ICharUserField*> userNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> userNameFinish(fb::ICharUserField* ret);
	static MethodStart<fb::ICharUserField*> passwordStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> passwordFinish(fb::ICharUserField* ret);
	static MethodStart<fb::ICharUserField*> firstNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> firstNameFinish(fb::ICharUserField* ret);
	static MethodStart<fb::ICharUserField*> lastNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> lastNameFinish(fb::ICharUserField* ret);
	static MethodStart<fb::ICharUserField*> middleNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> middleNameFinish(fb::ICharUserField* ret);
	static MethodStart<fb::ICharUserField*> commentStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> commentFinish(fb::ICharUserField* ret);
	static MethodStart<fb::ICharUserField*> attributesStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> attributesFinish(fb::ICharUserField* ret);
	static MethodStart<fb::IIntUserField*> activeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> activeFinish(fb::IIntUserField* ret);
	static MethodStart<fb::IIntUserField*> adminStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> adminFinish(fb::IIntUserField* ret);
	static MethodStart<void*> clearStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> clearFinish(void* ret);
};


class ListUsersImpl : public BaseImpl<ListUsersImpl, fb::IListUsersImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class ListUsers : public BaseClass<ListUsers, fb::IListUsers>
{
friend class BaseClass<ListUsers, fb::IListUsers>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> listStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> listFinish(void* ret);
};


class LogonInfoImpl : public BaseImpl<LogonInfoImpl, fb::ILogonInfoImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class LogonInfo : public BaseClass<LogonInfo, fb::ILogonInfo>
{
friend class BaseClass<LogonInfo, fb::ILogonInfo>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<std::string> nameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> nameFinish(std::string ret);
	static MethodStart<std::string> roleStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> roleFinish(std::string ret);
	static MethodStart<std::string> networkProtocolStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> networkProtocolFinish(std::string ret);
	static MethodStart<std::string> remoteAddressStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> remoteAddressFinish(std::string ret);
	static MethodStart<const unsigned char*> authBlockStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> authBlockFinish(const unsigned char* ret);
};


class ManagementImpl : public BaseImpl<ManagementImpl, fb::IManagementImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Management : public BaseClass<Management, fb::IManagement>
{
friend class BaseClass<Management, fb::IManagement>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setOwnerFinish(void* ret);
	static MethodStart<fb::IReferenceCounted*> getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getOwnerFinish(fb::IReferenceCounted* ret);
	static MethodStart<void*> startStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> startFinish(void* ret);
	static MethodStart<int> executeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> executeFinish(int ret);
	static MethodStart<void*> commitStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> commitFinish(void* ret);
	static MethodStart<void*> rollbackStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> rollbackFinish(void* ret);
};


class WireCryptPluginImpl : public BaseImpl<WireCryptPluginImpl, fb::IWireCryptPluginImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class WireCryptPlugin : public BaseClass<WireCryptPlugin, fb::IWireCryptPlugin>
{
friend class BaseClass<WireCryptPlugin, fb::IWireCryptPlugin>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setOwnerFinish(void* ret);
	static MethodStart<fb::IReferenceCounted*> getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getOwnerFinish(fb::IReferenceCounted* ret);
	static MethodStart<std::string> getKnownTypesStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getKnownTypesFinish(std::string ret);
	static MethodStart<void*> setKeyStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setKeyFinish(void* ret);
	static MethodStart<void*> encryptStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> encryptFinish(void* ret);
	static MethodStart<void*> decryptStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> decryptFinish(void* ret);
};


class CryptKeyCallbackImpl : public BaseImpl<CryptKeyCallbackImpl, fb::ICryptKeyCallbackImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class CryptKeyCallback : public BaseClass<CryptKeyCallback, fb::ICryptKeyCallback>
{
friend class BaseClass<CryptKeyCallback, fb::ICryptKeyCallback>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<unsigned> callbackStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> callbackFinish(unsigned ret);
};


class KeyHolderPluginImpl : public BaseImpl<KeyHolderPluginImpl, fb::IKeyHolderPluginImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class KeyHolderPlugin : public BaseClass<KeyHolderPlugin, fb::IKeyHolderPlugin>
{
friend class BaseClass<KeyHolderPlugin, fb::IKeyHolderPlugin>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setOwnerFinish(void* ret);
	static MethodStart<fb::IReferenceCounted*> getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getOwnerFinish(fb::IReferenceCounted* ret);
	static MethodStart<int> keyCallbackStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> keyCallbackFinish(int ret);
	static MethodStart<fb::ICryptKeyCallback*> keyHandleStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> keyHandleFinish(fb::ICryptKeyCallback* ret);
};


class DbCryptPluginImpl : public BaseImpl<DbCryptPluginImpl, fb::IDbCryptPluginImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class DbCryptPlugin : public BaseClass<DbCryptPlugin, fb::IDbCryptPlugin>
{
friend class BaseClass<DbCryptPlugin, fb::IDbCryptPlugin>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setOwnerFinish(void* ret);
	static MethodStart<fb::IReferenceCounted*> getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getOwnerFinish(fb::IReferenceCounted* ret);
};


class ExternalContextImpl : public BaseImpl<ExternalContextImpl, fb::IExternalContextImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class ExternalContext : public BaseClass<ExternalContext, fb::IExternalContext>
{
friend class BaseClass<ExternalContext, fb::IExternalContext>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
};


class ExternalResultSetImpl : public BaseImpl<ExternalResultSetImpl, fb::IExternalResultSetImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class ExternalResultSet : public BaseClass<ExternalResultSet, fb::IExternalResultSet>
{
friend class BaseClass<ExternalResultSet, fb::IExternalResultSet>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> disposeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> disposeFinish(void* ret);
	static MethodStart<FB_BOOLEAN> fetchStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> fetchFinish(FB_BOOLEAN ret);
};


class ExternalFunctionImpl : public BaseImpl<ExternalFunctionImpl, fb::IExternalFunctionImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class ExternalFunction : public BaseClass<ExternalFunction, fb::IExternalFunction>
{
friend class BaseClass<ExternalFunction, fb::IExternalFunction>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> disposeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> disposeFinish(void* ret);
};


class ExternalProcedureImpl : public BaseImpl<ExternalProcedureImpl, fb::IExternalProcedureImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class ExternalProcedure : public BaseClass<ExternalProcedure, fb::IExternalProcedure>
{
friend class BaseClass<ExternalProcedure, fb::IExternalProcedure>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> disposeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> disposeFinish(void* ret);
};


class ExternalTriggerImpl : public BaseImpl<ExternalTriggerImpl, fb::IExternalTriggerImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class ExternalTrigger : public BaseClass<ExternalTrigger, fb::IExternalTrigger>
{
friend class BaseClass<ExternalTrigger, fb::IExternalTrigger>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> disposeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> disposeFinish(void* ret);
};


class RoutineMetadataImpl : public BaseImpl<RoutineMetadataImpl, fb::IRoutineMetadataImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class RoutineMetadata : public BaseClass<RoutineMetadata, fb::IRoutineMetadata>
{
friend class BaseClass<RoutineMetadata, fb::IRoutineMetadata>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<std::string> getPackageStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getPackageFinish(std::string ret);
	static MethodStart<std::string> getNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getNameFinish(std::string ret);
	static MethodStart<std::string> getEntryPointStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getEntryPointFinish(std::string ret);
	static MethodStart<std::string> getBodyStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getBodyFinish(std::string ret);
	static MethodStart<fb::IMessageMetadata*> getInputMetadataStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getInputMetadataFinish(fb::IMessageMetadata* ret);
	static MethodStart<fb::IMessageMetadata*> getOutputMetadataStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getOutputMetadataFinish(fb::IMessageMetadata* ret);
	static MethodStart<fb::IMessageMetadata*> getTriggerMetadataStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getTriggerMetadataFinish(fb::IMessageMetadata* ret);
	static MethodStart<std::string> getTriggerTableStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getTriggerTableFinish(std::string ret);
	static MethodStart<unsigned> getTriggerTypeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getTriggerTypeFinish(unsigned ret);
};


class ExternalEngineImpl : public BaseImpl<ExternalEngineImpl, fb::IExternalEngineImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class ExternalEngine : public BaseClass<ExternalEngine, fb::IExternalEngine>
{
friend class BaseClass<ExternalEngine, fb::IExternalEngine>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setOwnerFinish(void* ret);
	static MethodStart<fb::IReferenceCounted*> getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getOwnerFinish(fb::IReferenceCounted* ret);
};


class TimerImpl : public BaseImpl<TimerImpl, fb::ITimerImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Timer : public BaseClass<Timer, fb::ITimer>
{
friend class BaseClass<Timer, fb::ITimer>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> handlerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> handlerFinish(void* ret);
};


class TimerControlImpl : public BaseImpl<TimerControlImpl, fb::ITimerControlImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TimerControl : public BaseClass<TimerControl, fb::ITimerControl>
{
friend class BaseClass<TimerControl, fb::ITimerControl>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> startStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> startFinish(void* ret);
	static MethodStart<void*> stopStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> stopFinish(void* ret);
};


class VersionCallbackImpl : public BaseImpl<VersionCallbackImpl, fb::IVersionCallbackImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class VersionCallback : public BaseClass<VersionCallback, fb::IVersionCallback>
{
friend class BaseClass<VersionCallback, fb::IVersionCallback>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> callbackStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> callbackFinish(void* ret);
};


class UtilImpl : public BaseImpl<UtilImpl, fb::IUtilImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class Util : public BaseClass<Util, fb::IUtil>
{
friend class BaseClass<Util, fb::IUtil>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> getFbVersionStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getFbVersionFinish(void* ret);
	static MethodStart<fb::IAttachment*> executeCreateDatabaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> executeCreateDatabaseFinish(fb::IAttachment* ret);
	static MethodStart<void*> decodeDateStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> decodeDateFinish(void* ret);
	static MethodStart<void*> decodeTimeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> decodeTimeFinish(void* ret);
	static MethodStart<int> encodeDateStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> encodeDateFinish(int ret);
	static MethodStart<int> encodeTimeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> encodeTimeFinish(int ret);
	static MethodStart<unsigned> getClientVersionStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getClientVersionFinish(unsigned ret);
	static MethodStart<fb::IXpbBuilder*> getXpbBuilderStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getXpbBuilderFinish(fb::IXpbBuilder* ret);
	static MethodStart<unsigned> setOffsetsStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setOffsetsFinish(unsigned ret);
};


class OffsetsCallbackImpl : public BaseImpl<OffsetsCallbackImpl, fb::IOffsetsCallbackImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class OffsetsCallback : public BaseClass<OffsetsCallback, fb::IOffsetsCallback>
{
friend class BaseClass<OffsetsCallback, fb::IOffsetsCallback>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> setOffsetStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setOffsetFinish(void* ret);
};


class XpbBuilderImpl : public BaseImpl<XpbBuilderImpl, fb::IXpbBuilderImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class XpbBuilder : public BaseClass<XpbBuilder, fb::IXpbBuilder>
{
friend class BaseClass<XpbBuilder, fb::IXpbBuilder>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> disposeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> disposeFinish(void* ret);
	static MethodStart<void*> clearStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> clearFinish(void* ret);
	static MethodStart<void*> removeCurrentStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> removeCurrentFinish(void* ret);
	static MethodStart<void*> insertIntStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> insertIntFinish(void* ret);
	static MethodStart<void*> insertBigIntStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> insertBigIntFinish(void* ret);
	static MethodStart<void*> insertBytesStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> insertBytesFinish(void* ret);
	static MethodStart<void*> insertStringStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> insertStringFinish(void* ret);
	static MethodStart<void*> insertTagStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> insertTagFinish(void* ret);
	static MethodStart<FB_BOOLEAN> isEofStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> isEofFinish(FB_BOOLEAN ret);
	static MethodStart<void*> moveNextStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> moveNextFinish(void* ret);
	static MethodStart<void*> rewindStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> rewindFinish(void* ret);
	static MethodStart<FB_BOOLEAN> findFirstStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> findFirstFinish(FB_BOOLEAN ret);
	static MethodStart<FB_BOOLEAN> findNextStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> findNextFinish(FB_BOOLEAN ret);
	static MethodStart<unsigned char> getTagStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getTagFinish(unsigned char ret);
	static MethodStart<unsigned> getLengthStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getLengthFinish(unsigned ret);
	static MethodStart<int> getIntStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getIntFinish(int ret);
	static MethodStart<int64_t> getBigIntStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getBigIntFinish(int64_t ret);
	static MethodStart<std::string> getStringStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getStringFinish(std::string ret);
	static MethodStart<const unsigned char*> getBytesStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getBytesFinish(const unsigned char* ret);
	static MethodStart<unsigned> getBufferLengthStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getBufferLengthFinish(unsigned ret);
	static MethodStart<const unsigned char*> getBufferStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getBufferFinish(const unsigned char* ret);
};


class TraceConnectionImpl : public BaseImpl<TraceConnectionImpl, fb::ITraceConnectionImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceConnection : public BaseClass<TraceConnection, fb::ITraceConnection>
{
friend class BaseClass<TraceConnection, fb::ITraceConnection>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<unsigned> getKindStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getKindFinish(unsigned ret);
	static MethodStart<int> getProcessIDStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getProcessIDFinish(int ret);
	static MethodStart<std::string> getUserNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getUserNameFinish(std::string ret);
	static MethodStart<std::string> getRoleNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getRoleNameFinish(std::string ret);
	static MethodStart<std::string> getCharSetStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getCharSetFinish(std::string ret);
	static MethodStart<std::string> getRemoteProtocolStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getRemoteProtocolFinish(std::string ret);
	static MethodStart<std::string> getRemoteAddressStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getRemoteAddressFinish(std::string ret);
	static MethodStart<int> getRemoteProcessIDStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getRemoteProcessIDFinish(int ret);
	static MethodStart<std::string> getRemoteProcessNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getRemoteProcessNameFinish(std::string ret);
};


class TraceDatabaseConnectionImpl : public BaseImpl<TraceDatabaseConnectionImpl, fb::ITraceDatabaseConnectionImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceDatabaseConnection : public BaseClass<TraceDatabaseConnection, fb::ITraceDatabaseConnection>
{
friend class BaseClass<TraceDatabaseConnection, fb::ITraceDatabaseConnection>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<unsigned> getKindStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getKindFinish(unsigned ret);
	static MethodStart<int> getProcessIDStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getProcessIDFinish(int ret);
	static MethodStart<std::string> getUserNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getUserNameFinish(std::string ret);
	static MethodStart<std::string> getRoleNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getRoleNameFinish(std::string ret);
	static MethodStart<std::string> getCharSetStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getCharSetFinish(std::string ret);
	static MethodStart<std::string> getRemoteProtocolStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getRemoteProtocolFinish(std::string ret);
	static MethodStart<std::string> getRemoteAddressStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getRemoteAddressFinish(std::string ret);
	static MethodStart<int> getRemoteProcessIDStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getRemoteProcessIDFinish(int ret);
	static MethodStart<std::string> getRemoteProcessNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getRemoteProcessNameFinish(std::string ret);
	static MethodStart<int64_t> getConnectionIDStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getConnectionIDFinish(int64_t ret);
	static MethodStart<std::string> getDatabaseNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getDatabaseNameFinish(std::string ret);
};


class TraceTransactionImpl : public BaseImpl<TraceTransactionImpl, fb::ITraceTransactionImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceTransaction : public BaseClass<TraceTransaction, fb::ITraceTransaction>
{
friend class BaseClass<TraceTransaction, fb::ITraceTransaction>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
};


class TraceParamsImpl : public BaseImpl<TraceParamsImpl, fb::ITraceParamsImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceParams : public BaseClass<TraceParams, fb::ITraceParams>
{
friend class BaseClass<TraceParams, fb::ITraceParams>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
};


class TraceStatementImpl : public BaseImpl<TraceStatementImpl, fb::ITraceStatementImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceStatement : public BaseClass<TraceStatement, fb::ITraceStatement>
{
friend class BaseClass<TraceStatement, fb::ITraceStatement>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
};


class TraceSQLStatementImpl : public BaseImpl<TraceSQLStatementImpl, fb::ITraceSQLStatementImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceSQLStatement : public BaseClass<TraceSQLStatement, fb::ITraceSQLStatement>
{
friend class BaseClass<TraceSQLStatement, fb::ITraceSQLStatement>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
};


class TraceBLRStatementImpl : public BaseImpl<TraceBLRStatementImpl, fb::ITraceBLRStatementImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceBLRStatement : public BaseClass<TraceBLRStatement, fb::ITraceBLRStatement>
{
friend class BaseClass<TraceBLRStatement, fb::ITraceBLRStatement>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
};


class TraceDYNRequestImpl : public BaseImpl<TraceDYNRequestImpl, fb::ITraceDYNRequestImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceDYNRequest : public BaseClass<TraceDYNRequest, fb::ITraceDYNRequest>
{
friend class BaseClass<TraceDYNRequest, fb::ITraceDYNRequest>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
};


class TraceContextVariableImpl : public BaseImpl<TraceContextVariableImpl, fb::ITraceContextVariableImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceContextVariable : public BaseClass<TraceContextVariable, fb::ITraceContextVariable>
{
friend class BaseClass<TraceContextVariable, fb::ITraceContextVariable>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
};


class TraceProcedureImpl : public BaseImpl<TraceProcedureImpl, fb::ITraceProcedureImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceProcedure : public BaseClass<TraceProcedure, fb::ITraceProcedure>
{
friend class BaseClass<TraceProcedure, fb::ITraceProcedure>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
};


class TraceFunctionImpl : public BaseImpl<TraceFunctionImpl, fb::ITraceFunctionImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceFunction : public BaseClass<TraceFunction, fb::ITraceFunction>
{
friend class BaseClass<TraceFunction, fb::ITraceFunction>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
};


class TraceTriggerImpl : public BaseImpl<TraceTriggerImpl, fb::ITraceTriggerImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceTrigger : public BaseClass<TraceTrigger, fb::ITraceTrigger>
{
friend class BaseClass<TraceTrigger, fb::ITraceTrigger>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
};


class TraceServiceConnectionImpl : public BaseImpl<TraceServiceConnectionImpl, fb::ITraceServiceConnectionImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceServiceConnection : public BaseClass<TraceServiceConnection, fb::ITraceServiceConnection>
{
friend class BaseClass<TraceServiceConnection, fb::ITraceServiceConnection>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<unsigned> getKindStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getKindFinish(unsigned ret);
	static MethodStart<int> getProcessIDStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getProcessIDFinish(int ret);
	static MethodStart<std::string> getUserNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getUserNameFinish(std::string ret);
	static MethodStart<std::string> getRoleNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getRoleNameFinish(std::string ret);
	static MethodStart<std::string> getCharSetStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getCharSetFinish(std::string ret);
	static MethodStart<std::string> getRemoteProtocolStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getRemoteProtocolFinish(std::string ret);
	static MethodStart<std::string> getRemoteAddressStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getRemoteAddressFinish(std::string ret);
	static MethodStart<int> getRemoteProcessIDStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getRemoteProcessIDFinish(int ret);
	static MethodStart<std::string> getRemoteProcessNameStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getRemoteProcessNameFinish(std::string ret);
};


class TraceStatusVectorImpl : public BaseImpl<TraceStatusVectorImpl, fb::ITraceStatusVectorImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceStatusVector : public BaseClass<TraceStatusVector, fb::ITraceStatusVector>
{
friend class BaseClass<TraceStatusVector, fb::ITraceStatusVector>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
};


class TraceSweepInfoImpl : public BaseImpl<TraceSweepInfoImpl, fb::ITraceSweepInfoImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceSweepInfo : public BaseClass<TraceSweepInfo, fb::ITraceSweepInfo>
{
friend class BaseClass<TraceSweepInfo, fb::ITraceSweepInfo>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
};


class TraceLogWriterImpl : public BaseImpl<TraceLogWriterImpl, fb::ITraceLogWriterImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceLogWriter : public BaseClass<TraceLogWriter, fb::ITraceLogWriter>
{
friend class BaseClass<TraceLogWriter, fb::ITraceLogWriter>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
};


class TraceInitInfoImpl : public BaseImpl<TraceInitInfoImpl, fb::ITraceInitInfoImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceInitInfo : public BaseClass<TraceInitInfo, fb::ITraceInitInfo>
{
friend class BaseClass<TraceInitInfo, fb::ITraceInitInfo>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
};


class TracePluginImpl : public BaseImpl<TracePluginImpl, fb::ITracePluginImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TracePlugin : public BaseClass<TracePlugin, fb::ITracePlugin>
{
friend class BaseClass<TracePlugin, fb::ITracePlugin>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
};


class TraceFactoryImpl : public BaseImpl<TraceFactoryImpl, fb::ITraceFactoryImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class TraceFactory : public BaseClass<TraceFactory, fb::ITraceFactory>
{
friend class BaseClass<TraceFactory, fb::ITraceFactory>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> addRefStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> addRefFinish(void* ret);
	static MethodStart<int> releaseStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> releaseFinish(int ret);
	static MethodStart<void*> setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setOwnerFinish(void* ret);
	static MethodStart<fb::IReferenceCounted*> getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getOwnerFinish(fb::IReferenceCounted* ret);
};


class UdrFunctionFactoryImpl : public BaseImpl<UdrFunctionFactoryImpl, fb::IUdrFunctionFactoryImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class UdrFunctionFactory : public BaseClass<UdrFunctionFactory, fb::IUdrFunctionFactory>
{
friend class BaseClass<UdrFunctionFactory, fb::IUdrFunctionFactory>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> disposeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> disposeFinish(void* ret);
	static MethodStart<void*> setupStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setupFinish(void* ret);
	static MethodStart<fb::IExternalFunction*> newItemStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> newItemFinish(fb::IExternalFunction* ret);
};


class UdrProcedureFactoryImpl : public BaseImpl<UdrProcedureFactoryImpl, fb::IUdrProcedureFactoryImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class UdrProcedureFactory : public BaseClass<UdrProcedureFactory, fb::IUdrProcedureFactory>
{
friend class BaseClass<UdrProcedureFactory, fb::IUdrProcedureFactory>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> disposeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> disposeFinish(void* ret);
	static MethodStart<void*> setupStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setupFinish(void* ret);
	static MethodStart<fb::IExternalProcedure*> newItemStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> newItemFinish(fb::IExternalProcedure* ret);
};


class UdrTriggerFactoryImpl : public BaseImpl<UdrTriggerFactoryImpl, fb::IUdrTriggerFactoryImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class UdrTriggerFactory : public BaseClass<UdrTriggerFactory, fb::IUdrTriggerFactory>
{
friend class BaseClass<UdrTriggerFactory, fb::IUdrTriggerFactory>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<void*> disposeStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> disposeFinish(void* ret);
	static MethodStart<void*> setupStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> setupFinish(void* ret);
	static MethodStart<fb::IExternalTrigger*> newItemStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> newItemFinish(fb::IExternalTrigger* ret);
};


class UdrPluginImpl : public BaseImpl<UdrPluginImpl, fb::IUdrPluginImpl>
{
public:
	using BaseImpl::BaseImpl;

public:
};

class UdrPlugin : public BaseClass<UdrPlugin, fb::IUdrPlugin>
{
friend class BaseClass<UdrPlugin, fb::IUdrPlugin>;

private:
	static void InitPrototype(v8::Local<v8::FunctionTemplate>& tpl);

private:
	static MethodStart<fb::IMaster*> getMasterStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> getMasterFinish(fb::IMaster* ret);
	static MethodStart<void*> registerFunctionStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> registerFunctionFinish(void* ret);
	static MethodStart<void*> registerProcedureStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> registerProcedureFinish(void* ret);
	static MethodStart<void*> registerTriggerStart(Nan::NAN_METHOD_ARGS_TYPE info);
	static v8::Local<v8::Value> registerTriggerFinish(void* ret);
};


void Versioned::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
}

void ReferenceCounted::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
}

MethodStart<void*> ReferenceCounted::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ReferenceCounted>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> ReferenceCounted::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> ReferenceCounted::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ReferenceCounted>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> ReferenceCounted::releaseFinish(int ret)
{
	return Nan::New(ret);
}

void Disposable::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, disposeStart, disposeFinish>(tpl, "dispose");
}

MethodStart<void*> Disposable::disposeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Disposable>(info.This());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

v8::Local<v8::Value> Disposable::disposeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void Status::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, disposeStart, disposeFinish>(tpl, "dispose");
	DefineAsyncMethod<void*, initStart, initFinish>(tpl, "init");
	DefineAsyncMethod<unsigned, getStateStart, getStateFinish>(tpl, "getState");
	DefineAsyncMethod<fb::IStatus*, cloneStart, cloneFinish>(tpl, "clone");
}

MethodStart<void*> Status::disposeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Status>(info.This());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

v8::Local<v8::Value> Status::disposeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Status::initStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Status>(info.This());

	return [obj]() {
		obj->interface->init();
		return nullptr;
	};
}

v8::Local<v8::Value> Status::initFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<unsigned> Status::getStateStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Status>(info.This());

	return [obj]() {
		return obj->interface->getState();
	};
}

v8::Local<v8::Value> Status::getStateFinish(unsigned ret)
{
	return Nan::New(ret);
}

MethodStart<fb::IStatus*> Status::cloneStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Status>(info.This());

	return [obj]() {
		return obj->interface->clone();
	};
}

v8::Local<v8::Value> Status::cloneFinish(fb::IStatus* ret)
{
	return Status::NewInstance(ret);
}

void Master::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<fb::IStatus*, getStatusStart, getStatusFinish>(tpl, "getStatus");
	DefineAsyncMethod<fb::IProvider*, getDispatcherStart, getDispatcherFinish>(tpl, "getDispatcher");
	DefineAsyncMethod<fb::IPluginManager*, getPluginManagerStart, getPluginManagerFinish>(tpl, "getPluginManager");
	DefineAsyncMethod<fb::ITimerControl*, getTimerControlStart, getTimerControlFinish>(tpl, "getTimerControl");
	DefineAsyncMethod<fb::IDtc*, getDtcStart, getDtcFinish>(tpl, "getDtc");
	DefineAsyncMethod<fb::IAttachment*, registerAttachmentStart, registerAttachmentFinish>(tpl, "registerAttachment");
	DefineAsyncMethod<fb::ITransaction*, registerTransactionStart, registerTransactionFinish>(tpl, "registerTransaction");
	DefineAsyncMethod<fb::IMetadataBuilder*, getMetadataBuilderStart, getMetadataBuilderFinish>(tpl, "getMetadataBuilder");
	DefineAsyncMethod<int, serverModeStart, serverModeFinish>(tpl, "serverMode");
	DefineAsyncMethod<fb::IUtil*, getUtilInterfaceStart, getUtilInterfaceFinish>(tpl, "getUtilInterface");
	DefineAsyncMethod<fb::IConfigManager*, getConfigManagerStart, getConfigManagerFinish>(tpl, "getConfigManager");
	DefineAsyncMethod<FB_BOOLEAN, getProcessExitingStart, getProcessExitingFinish>(tpl, "getProcessExiting");
}

MethodStart<fb::IStatus*> Master::getStatusStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Master>(info.This());

	return [obj]() {
		return obj->interface->getStatus();
	};
}

v8::Local<v8::Value> Master::getStatusFinish(fb::IStatus* ret)
{
	return Status::NewInstance(ret);
}

MethodStart<fb::IProvider*> Master::getDispatcherStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Master>(info.This());

	return [obj]() {
		return obj->interface->getDispatcher();
	};
}

v8::Local<v8::Value> Master::getDispatcherFinish(fb::IProvider* ret)
{
	return Provider::NewInstance(ret);
}

MethodStart<fb::IPluginManager*> Master::getPluginManagerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Master>(info.This());

	return [obj]() {
		return obj->interface->getPluginManager();
	};
}

v8::Local<v8::Value> Master::getPluginManagerFinish(fb::IPluginManager* ret)
{
	return PluginManager::NewInstance(ret);
}

MethodStart<fb::ITimerControl*> Master::getTimerControlStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Master>(info.This());

	return [obj]() {
		return obj->interface->getTimerControl();
	};
}

v8::Local<v8::Value> Master::getTimerControlFinish(fb::ITimerControl* ret)
{
	return TimerControl::NewInstance(ret);
}

MethodStart<fb::IDtc*> Master::getDtcStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Master>(info.This());

	return [obj]() {
		return obj->interface->getDtc();
	};
}

v8::Local<v8::Value> Master::getDtcFinish(fb::IDtc* ret)
{
	return Dtc::NewInstance(ret);
}

MethodStart<fb::IAttachment*> Master::registerAttachmentStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Master>(info.This());
	auto* provider = Provider::CheckedUnwrap(info[0], "provider argument", true);
	auto* attachment = Attachment::CheckedUnwrap(info[1], "attachment argument", true);

	return [obj, provider, attachment]() {
		return obj->interface->registerAttachment((provider ? provider->interface : nullptr), (attachment ? attachment->interface : nullptr));
	};
}

v8::Local<v8::Value> Master::registerAttachmentFinish(fb::IAttachment* ret)
{
	return Attachment::NewInstance(ret);
}

MethodStart<fb::ITransaction*> Master::registerTransactionStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Master>(info.This());
	auto* attachment = Attachment::CheckedUnwrap(info[0], "attachment argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info[1], "transaction argument", true);

	return [obj, attachment, transaction]() {
		return obj->interface->registerTransaction((attachment ? attachment->interface : nullptr), (transaction ? transaction->interface : nullptr));
	};
}

v8::Local<v8::Value> Master::registerTransactionFinish(fb::ITransaction* ret)
{
	return Transaction::NewInstance(ret);
}

MethodStart<fb::IMetadataBuilder*> Master::getMetadataBuilderStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Master>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned fieldCount = info[1]->NumberValue();

	return [obj, status, fieldCount]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getMetadataBuilder(&statusWrapper, fieldCount);
	};
}

v8::Local<v8::Value> Master::getMetadataBuilderFinish(fb::IMetadataBuilder* ret)
{
	return MetadataBuilder::NewInstance(ret);
}

MethodStart<int> Master::serverModeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Master>(info.This());
	int mode = info[0]->NumberValue();

	return [obj, mode]() {
		return obj->interface->serverMode(mode);
	};
}

v8::Local<v8::Value> Master::serverModeFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<fb::IUtil*> Master::getUtilInterfaceStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Master>(info.This());

	return [obj]() {
		return obj->interface->getUtilInterface();
	};
}

v8::Local<v8::Value> Master::getUtilInterfaceFinish(fb::IUtil* ret)
{
	return Util::NewInstance(ret);
}

MethodStart<fb::IConfigManager*> Master::getConfigManagerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Master>(info.This());

	return [obj]() {
		return obj->interface->getConfigManager();
	};
}

v8::Local<v8::Value> Master::getConfigManagerFinish(fb::IConfigManager* ret)
{
	return ConfigManager::NewInstance(ret);
}

MethodStart<FB_BOOLEAN> Master::getProcessExitingStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Master>(info.This());

	return [obj]() {
		return obj->interface->getProcessExiting();
	};
}

v8::Local<v8::Value> Master::getProcessExitingFinish(FB_BOOLEAN ret)
{
	return Nan::New((bool) ret);
}

void PluginBase::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, setOwnerStart, setOwnerFinish>(tpl, "setOwner");
	DefineAsyncMethod<fb::IReferenceCounted*, getOwnerStart, getOwnerFinish>(tpl, "getOwner");
}

MethodStart<void*> PluginBase::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginBase>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> PluginBase::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> PluginBase::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginBase>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> PluginBase::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> PluginBase::setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginBase>(info.This());
	auto* r = ReferenceCounted::CheckedUnwrap(info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> PluginBase::setOwnerFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::IReferenceCounted*> PluginBase::getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginBase>(info.This());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

v8::Local<v8::Value> PluginBase::getOwnerFinish(fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(ret);
}

void PluginSet::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<std::string, getNameStart, getNameFinish>(tpl, "getName");
	DefineAsyncMethod<std::string, getModuleNameStart, getModuleNameFinish>(tpl, "getModuleName");
	DefineAsyncMethod<fb::IPluginBase*, getPluginStart, getPluginFinish>(tpl, "getPlugin");
	DefineAsyncMethod<void*, nextStart, nextFinish>(tpl, "next");
	DefineAsyncMethod<void*, setStart, setFinish>(tpl, "set");
}

MethodStart<void*> PluginSet::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginSet>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> PluginSet::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> PluginSet::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginSet>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> PluginSet::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<std::string> PluginSet::getNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginSet>(info.This());

	return [obj]() {
		return obj->interface->getName();
	};
}

v8::Local<v8::Value> PluginSet::getNameFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> PluginSet::getModuleNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginSet>(info.This());

	return [obj]() {
		return obj->interface->getModuleName();
	};
}

v8::Local<v8::Value> PluginSet::getModuleNameFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<fb::IPluginBase*> PluginSet::getPluginStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginSet>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getPlugin(&statusWrapper);
	};
}

v8::Local<v8::Value> PluginSet::getPluginFinish(fb::IPluginBase* ret)
{
	return PluginBase::NewInstance(ret);
}

MethodStart<void*> PluginSet::nextStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginSet>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->next(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> PluginSet::nextFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> PluginSet::setStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginSet>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string s = *v8::String::Utf8Value(info[1]->ToString());

	return [obj, status, s]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->set(&statusWrapper, s.c_str());
		return nullptr;
	};
}

v8::Local<v8::Value> PluginSet::setFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void ConfigEntry::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<std::string, getNameStart, getNameFinish>(tpl, "getName");
	DefineAsyncMethod<std::string, getValueStart, getValueFinish>(tpl, "getValue");
	DefineAsyncMethod<int64_t, getIntValueStart, getIntValueFinish>(tpl, "getIntValue");
	DefineAsyncMethod<FB_BOOLEAN, getBoolValueStart, getBoolValueFinish>(tpl, "getBoolValue");
	DefineAsyncMethod<fb::IConfig*, getSubConfigStart, getSubConfigFinish>(tpl, "getSubConfig");
}

MethodStart<void*> ConfigEntry::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ConfigEntry>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> ConfigEntry::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> ConfigEntry::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ConfigEntry>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> ConfigEntry::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<std::string> ConfigEntry::getNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ConfigEntry>(info.This());

	return [obj]() {
		return obj->interface->getName();
	};
}

v8::Local<v8::Value> ConfigEntry::getNameFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> ConfigEntry::getValueStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ConfigEntry>(info.This());

	return [obj]() {
		return obj->interface->getValue();
	};
}

v8::Local<v8::Value> ConfigEntry::getValueFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<int64_t> ConfigEntry::getIntValueStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ConfigEntry>(info.This());

	return [obj]() {
		return obj->interface->getIntValue();
	};
}

v8::Local<v8::Value> ConfigEntry::getIntValueFinish(int64_t ret)
{
	return Nan::New((double) ret);
}

MethodStart<FB_BOOLEAN> ConfigEntry::getBoolValueStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ConfigEntry>(info.This());

	return [obj]() {
		return obj->interface->getBoolValue();
	};
}

v8::Local<v8::Value> ConfigEntry::getBoolValueFinish(FB_BOOLEAN ret)
{
	return Nan::New((bool) ret);
}

MethodStart<fb::IConfig*> ConfigEntry::getSubConfigStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ConfigEntry>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getSubConfig(&statusWrapper);
	};
}

v8::Local<v8::Value> ConfigEntry::getSubConfigFinish(fb::IConfig* ret)
{
	return Config::NewInstance(ret);
}

void Config::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<fb::IConfigEntry*, findStart, findFinish>(tpl, "find");
	DefineAsyncMethod<fb::IConfigEntry*, findValueStart, findValueFinish>(tpl, "findValue");
	DefineAsyncMethod<fb::IConfigEntry*, findPosStart, findPosFinish>(tpl, "findPos");
}

MethodStart<void*> Config::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Config>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> Config::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Config::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Config>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> Config::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<fb::IConfigEntry*> Config::findStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Config>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string name = *v8::String::Utf8Value(info[1]->ToString());

	return [obj, status, name]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->find(&statusWrapper, name.c_str());
	};
}

v8::Local<v8::Value> Config::findFinish(fb::IConfigEntry* ret)
{
	return ConfigEntry::NewInstance(ret);
}

MethodStart<fb::IConfigEntry*> Config::findValueStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Config>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string name = *v8::String::Utf8Value(info[1]->ToString());
	std::string value = *v8::String::Utf8Value(info[2]->ToString());

	return [obj, status, name, value]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->findValue(&statusWrapper, name.c_str(), value.c_str());
	};
}

v8::Local<v8::Value> Config::findValueFinish(fb::IConfigEntry* ret)
{
	return ConfigEntry::NewInstance(ret);
}

MethodStart<fb::IConfigEntry*> Config::findPosStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Config>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string name = *v8::String::Utf8Value(info[1]->ToString());
	unsigned pos = info[2]->NumberValue();

	return [obj, status, name, pos]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->findPos(&statusWrapper, name.c_str(), pos);
	};
}

v8::Local<v8::Value> Config::findPosFinish(fb::IConfigEntry* ret)
{
	return ConfigEntry::NewInstance(ret);
}

void FirebirdConf::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<unsigned, getKeyStart, getKeyFinish>(tpl, "getKey");
	DefineAsyncMethod<int64_t, asIntegerStart, asIntegerFinish>(tpl, "asInteger");
	DefineAsyncMethod<std::string, asStringStart, asStringFinish>(tpl, "asString");
	DefineAsyncMethod<FB_BOOLEAN, asBooleanStart, asBooleanFinish>(tpl, "asBoolean");
}

MethodStart<void*> FirebirdConf::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<FirebirdConf>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> FirebirdConf::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> FirebirdConf::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<FirebirdConf>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> FirebirdConf::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<unsigned> FirebirdConf::getKeyStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<FirebirdConf>(info.This());
	std::string name = *v8::String::Utf8Value(info[0]->ToString());

	return [obj, name]() {
		return obj->interface->getKey(name.c_str());
	};
}

v8::Local<v8::Value> FirebirdConf::getKeyFinish(unsigned ret)
{
	return Nan::New(ret);
}

MethodStart<int64_t> FirebirdConf::asIntegerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<FirebirdConf>(info.This());
	unsigned key = info[0]->NumberValue();

	return [obj, key]() {
		return obj->interface->asInteger(key);
	};
}

v8::Local<v8::Value> FirebirdConf::asIntegerFinish(int64_t ret)
{
	return Nan::New((double) ret);
}

MethodStart<std::string> FirebirdConf::asStringStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<FirebirdConf>(info.This());
	unsigned key = info[0]->NumberValue();

	return [obj, key]() {
		return obj->interface->asString(key);
	};
}

v8::Local<v8::Value> FirebirdConf::asStringFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<FB_BOOLEAN> FirebirdConf::asBooleanStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<FirebirdConf>(info.This());
	unsigned key = info[0]->NumberValue();

	return [obj, key]() {
		return obj->interface->asBoolean(key);
	};
}

v8::Local<v8::Value> FirebirdConf::asBooleanFinish(FB_BOOLEAN ret)
{
	return Nan::New((bool) ret);
}

void PluginConfig::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<std::string, getConfigFileNameStart, getConfigFileNameFinish>(tpl, "getConfigFileName");
	DefineAsyncMethod<fb::IConfig*, getDefaultConfigStart, getDefaultConfigFinish>(tpl, "getDefaultConfig");
	DefineAsyncMethod<fb::IFirebirdConf*, getFirebirdConfStart, getFirebirdConfFinish>(tpl, "getFirebirdConf");
	DefineAsyncMethod<void*, setReleaseDelayStart, setReleaseDelayFinish>(tpl, "setReleaseDelay");
}

MethodStart<void*> PluginConfig::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginConfig>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> PluginConfig::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> PluginConfig::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginConfig>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> PluginConfig::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<std::string> PluginConfig::getConfigFileNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginConfig>(info.This());

	return [obj]() {
		return obj->interface->getConfigFileName();
	};
}

v8::Local<v8::Value> PluginConfig::getConfigFileNameFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<fb::IConfig*> PluginConfig::getDefaultConfigStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginConfig>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getDefaultConfig(&statusWrapper);
	};
}

v8::Local<v8::Value> PluginConfig::getDefaultConfigFinish(fb::IConfig* ret)
{
	return Config::NewInstance(ret);
}

MethodStart<fb::IFirebirdConf*> PluginConfig::getFirebirdConfStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginConfig>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getFirebirdConf(&statusWrapper);
	};
}

v8::Local<v8::Value> PluginConfig::getFirebirdConfFinish(fb::IFirebirdConf* ret)
{
	return FirebirdConf::NewInstance(ret);
}

MethodStart<void*> PluginConfig::setReleaseDelayStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginConfig>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	uint64_t microSeconds = info[1]->NumberValue();

	return [obj, status, microSeconds]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setReleaseDelay(&statusWrapper, microSeconds);
		return nullptr;
	};
}

v8::Local<v8::Value> PluginConfig::setReleaseDelayFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void PluginFactory::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<fb::IPluginBase*, createPluginStart, createPluginFinish>(tpl, "createPlugin");
}

MethodStart<fb::IPluginBase*> PluginFactory::createPluginStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginFactory>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* factoryParameter = PluginConfig::CheckedUnwrap(info[1], "factoryParameter argument", true);

	return [obj, status, factoryParameter]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->createPlugin(&statusWrapper, (factoryParameter ? factoryParameter->interface : nullptr));
	};
}

v8::Local<v8::Value> PluginFactory::createPluginFinish(fb::IPluginBase* ret)
{
	return PluginBase::NewInstance(ret);
}

void PluginModule::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, doCleanStart, doCleanFinish>(tpl, "doClean");
}

MethodStart<void*> PluginModule::doCleanStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginModule>(info.This());

	return [obj]() {
		obj->interface->doClean();
		return nullptr;
	};
}

v8::Local<v8::Value> PluginModule::doCleanFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void PluginManager::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, registerPluginFactoryStart, registerPluginFactoryFinish>(tpl, "registerPluginFactory");
	DefineAsyncMethod<void*, registerModuleStart, registerModuleFinish>(tpl, "registerModule");
	DefineAsyncMethod<void*, unregisterModuleStart, unregisterModuleFinish>(tpl, "unregisterModule");
	DefineAsyncMethod<fb::IPluginSet*, getPluginsStart, getPluginsFinish>(tpl, "getPlugins");
	DefineAsyncMethod<fb::IConfig*, getConfigStart, getConfigFinish>(tpl, "getConfig");
	DefineAsyncMethod<void*, releasePluginStart, releasePluginFinish>(tpl, "releasePlugin");
}

MethodStart<void*> PluginManager::registerPluginFactoryStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginManager>(info.This());
	unsigned pluginType = info[0]->NumberValue();
	std::string defaultName = *v8::String::Utf8Value(info[1]->ToString());
	auto* factory = PluginFactory::CheckedUnwrap(info[2], "factory argument", true);

	return [obj, pluginType, defaultName, factory]() {
		obj->interface->registerPluginFactory(pluginType, defaultName.c_str(), (factory ? factory->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> PluginManager::registerPluginFactoryFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> PluginManager::registerModuleStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginManager>(info.This());
	auto* cleanup = PluginModule::CheckedUnwrap(info[0], "cleanup argument", true);

	return [obj, cleanup]() {
		obj->interface->registerModule((cleanup ? cleanup->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> PluginManager::registerModuleFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> PluginManager::unregisterModuleStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginManager>(info.This());
	auto* cleanup = PluginModule::CheckedUnwrap(info[0], "cleanup argument", true);

	return [obj, cleanup]() {
		obj->interface->unregisterModule((cleanup ? cleanup->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> PluginManager::unregisterModuleFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::IPluginSet*> PluginManager::getPluginsStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginManager>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned pluginType = info[1]->NumberValue();
	std::string namesList = *v8::String::Utf8Value(info[2]->ToString());
	auto* firebirdConf = FirebirdConf::CheckedUnwrap(info[3], "firebirdConf argument", true);

	return [obj, status, pluginType, namesList, firebirdConf]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getPlugins(&statusWrapper, pluginType, namesList.c_str(), (firebirdConf ? firebirdConf->interface : nullptr));
	};
}

v8::Local<v8::Value> PluginManager::getPluginsFinish(fb::IPluginSet* ret)
{
	return PluginSet::NewInstance(ret);
}

MethodStart<fb::IConfig*> PluginManager::getConfigStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginManager>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string filename = *v8::String::Utf8Value(info[1]->ToString());

	return [obj, status, filename]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getConfig(&statusWrapper, filename.c_str());
	};
}

v8::Local<v8::Value> PluginManager::getConfigFinish(fb::IConfig* ret)
{
	return Config::NewInstance(ret);
}

MethodStart<void*> PluginManager::releasePluginStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<PluginManager>(info.This());
	auto* plugin = PluginBase::CheckedUnwrap(info[0], "plugin argument", true);

	return [obj, plugin]() {
		obj->interface->releasePlugin((plugin ? plugin->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> PluginManager::releasePluginFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void CryptKey::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
}

void ConfigManager::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<std::string, getDirectoryStart, getDirectoryFinish>(tpl, "getDirectory");
	DefineAsyncMethod<fb::IFirebirdConf*, getFirebirdConfStart, getFirebirdConfFinish>(tpl, "getFirebirdConf");
	DefineAsyncMethod<fb::IFirebirdConf*, getDatabaseConfStart, getDatabaseConfFinish>(tpl, "getDatabaseConf");
	DefineAsyncMethod<fb::IConfig*, getPluginConfigStart, getPluginConfigFinish>(tpl, "getPluginConfig");
	DefineAsyncMethod<std::string, getInstallDirectoryStart, getInstallDirectoryFinish>(tpl, "getInstallDirectory");
	DefineAsyncMethod<std::string, getRootDirectoryStart, getRootDirectoryFinish>(tpl, "getRootDirectory");
}

MethodStart<std::string> ConfigManager::getDirectoryStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ConfigManager>(info.This());
	unsigned code = info[0]->NumberValue();

	return [obj, code]() {
		return obj->interface->getDirectory(code);
	};
}

v8::Local<v8::Value> ConfigManager::getDirectoryFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<fb::IFirebirdConf*> ConfigManager::getFirebirdConfStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ConfigManager>(info.This());

	return [obj]() {
		return obj->interface->getFirebirdConf();
	};
}

v8::Local<v8::Value> ConfigManager::getFirebirdConfFinish(fb::IFirebirdConf* ret)
{
	return FirebirdConf::NewInstance(ret);
}

MethodStart<fb::IFirebirdConf*> ConfigManager::getDatabaseConfStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ConfigManager>(info.This());
	std::string dbName = *v8::String::Utf8Value(info[0]->ToString());

	return [obj, dbName]() {
		return obj->interface->getDatabaseConf(dbName.c_str());
	};
}

v8::Local<v8::Value> ConfigManager::getDatabaseConfFinish(fb::IFirebirdConf* ret)
{
	return FirebirdConf::NewInstance(ret);
}

MethodStart<fb::IConfig*> ConfigManager::getPluginConfigStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ConfigManager>(info.This());
	std::string configuredPlugin = *v8::String::Utf8Value(info[0]->ToString());

	return [obj, configuredPlugin]() {
		return obj->interface->getPluginConfig(configuredPlugin.c_str());
	};
}

v8::Local<v8::Value> ConfigManager::getPluginConfigFinish(fb::IConfig* ret)
{
	return Config::NewInstance(ret);
}

MethodStart<std::string> ConfigManager::getInstallDirectoryStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ConfigManager>(info.This());

	return [obj]() {
		return obj->interface->getInstallDirectory();
	};
}

v8::Local<v8::Value> ConfigManager::getInstallDirectoryFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> ConfigManager::getRootDirectoryStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ConfigManager>(info.This());

	return [obj]() {
		return obj->interface->getRootDirectory();
	};
}

v8::Local<v8::Value> ConfigManager::getRootDirectoryFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

void EventCallback::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, eventCallbackFunctionStart, eventCallbackFunctionFinish>(tpl, "eventCallbackFunction");
}

MethodStart<void*> EventCallback::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<EventCallback>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> EventCallback::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> EventCallback::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<EventCallback>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> EventCallback::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> EventCallback::eventCallbackFunctionStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<EventCallback>(info.This());
	unsigned length = info[0]->NumberValue();
	auto* events = getAddress<unsigned char>(info[1]);

	return [obj, length, events]() {
		obj->interface->eventCallbackFunction(length, events);
		return nullptr;
	};
}

v8::Local<v8::Value> EventCallback::eventCallbackFunctionFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void Blob::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, getInfoStart, getInfoFinish>(tpl, "getInfo");
	DefineAsyncMethod<int, getSegmentStart, getSegmentFinish>(tpl, "getSegment");
	DefineAsyncMethod<void*, putSegmentStart, putSegmentFinish>(tpl, "putSegment");
	DefineAsyncMethod<void*, cancelStart, cancelFinish>(tpl, "cancel");
	DefineAsyncMethod<void*, closeStart, closeFinish>(tpl, "close");
	DefineAsyncMethod<int, seekStart, seekFinish>(tpl, "seek");
}

MethodStart<void*> Blob::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Blob>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> Blob::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Blob::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Blob>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> Blob::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> Blob::getInfoStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Blob>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned itemsLength = info[1]->NumberValue();
	auto* items = getAddress<unsigned char>(info[2]);
	unsigned bufferLength = info[3]->NumberValue();
	auto* buffer = getAddress<unsigned char>(info[4]);

	return [obj, status, itemsLength, items, bufferLength, buffer]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->getInfo(&statusWrapper, itemsLength, items, bufferLength, buffer);
		return nullptr;
	};
}

v8::Local<v8::Value> Blob::getInfoFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Blob::getSegmentStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Blob>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned bufferLength = info[1]->NumberValue();
	auto* buffer = getAddress<unsigned char>(info[2]);
	auto* segmentLength = getAddress<unsigned>(info[3]);

	return [obj, status, bufferLength, buffer, segmentLength]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getSegment(&statusWrapper, bufferLength, buffer, segmentLength);
	};
}

v8::Local<v8::Value> Blob::getSegmentFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> Blob::putSegmentStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Blob>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned length = info[1]->NumberValue();
	auto* buffer = getAddress<unsigned char>(info[2]);

	return [obj, status, length, buffer]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->putSegment(&statusWrapper, length, buffer);
		return nullptr;
	};
}

v8::Local<v8::Value> Blob::putSegmentFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Blob::cancelStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Blob>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->cancel(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> Blob::cancelFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Blob::closeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Blob>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->close(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> Blob::closeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Blob::seekStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Blob>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	int mode = info[1]->NumberValue();
	int offset = info[2]->NumberValue();

	return [obj, status, mode, offset]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->seek(&statusWrapper, mode, offset);
	};
}

v8::Local<v8::Value> Blob::seekFinish(int ret)
{
	return Nan::New(ret);
}

void Transaction::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, getInfoStart, getInfoFinish>(tpl, "getInfo");
	DefineAsyncMethod<void*, prepareStart, prepareFinish>(tpl, "prepare");
	DefineAsyncMethod<void*, commitStart, commitFinish>(tpl, "commit");
	DefineAsyncMethod<void*, commitRetainingStart, commitRetainingFinish>(tpl, "commitRetaining");
	DefineAsyncMethod<void*, rollbackStart, rollbackFinish>(tpl, "rollback");
	DefineAsyncMethod<void*, rollbackRetainingStart, rollbackRetainingFinish>(tpl, "rollbackRetaining");
	DefineAsyncMethod<void*, disconnectStart, disconnectFinish>(tpl, "disconnect");
	DefineAsyncMethod<fb::ITransaction*, joinStart, joinFinish>(tpl, "join");
	DefineAsyncMethod<fb::ITransaction*, validateStart, validateFinish>(tpl, "validate");
	DefineAsyncMethod<fb::ITransaction*, enterDtcStart, enterDtcFinish>(tpl, "enterDtc");
}

MethodStart<void*> Transaction::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Transaction>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> Transaction::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Transaction::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Transaction>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> Transaction::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> Transaction::getInfoStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Transaction>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned itemsLength = info[1]->NumberValue();
	auto* items = getAddress<unsigned char>(info[2]);
	unsigned bufferLength = info[3]->NumberValue();
	auto* buffer = getAddress<unsigned char>(info[4]);

	return [obj, status, itemsLength, items, bufferLength, buffer]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->getInfo(&statusWrapper, itemsLength, items, bufferLength, buffer);
		return nullptr;
	};
}

v8::Local<v8::Value> Transaction::getInfoFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Transaction::prepareStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Transaction>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned msgLength = info[1]->NumberValue();
	auto* message = getAddress<unsigned char>(info[2]);

	return [obj, status, msgLength, message]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->prepare(&statusWrapper, msgLength, message);
		return nullptr;
	};
}

v8::Local<v8::Value> Transaction::prepareFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Transaction::commitStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Transaction>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->commit(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> Transaction::commitFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Transaction::commitRetainingStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Transaction>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->commitRetaining(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> Transaction::commitRetainingFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Transaction::rollbackStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Transaction>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->rollback(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> Transaction::rollbackFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Transaction::rollbackRetainingStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Transaction>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->rollbackRetaining(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> Transaction::rollbackRetainingFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Transaction::disconnectStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Transaction>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->disconnect(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> Transaction::disconnectFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::ITransaction*> Transaction::joinStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Transaction>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info[1], "transaction argument", true);

	return [obj, status, transaction]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->join(&statusWrapper, (transaction ? transaction->interface : nullptr));
	};
}

v8::Local<v8::Value> Transaction::joinFinish(fb::ITransaction* ret)
{
	return Transaction::NewInstance(ret);
}

MethodStart<fb::ITransaction*> Transaction::validateStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Transaction>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* attachment = Attachment::CheckedUnwrap(info[1], "attachment argument", true);

	return [obj, status, attachment]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->validate(&statusWrapper, (attachment ? attachment->interface : nullptr));
	};
}

v8::Local<v8::Value> Transaction::validateFinish(fb::ITransaction* ret)
{
	return Transaction::NewInstance(ret);
}

MethodStart<fb::ITransaction*> Transaction::enterDtcStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Transaction>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->enterDtc(&statusWrapper);
	};
}

v8::Local<v8::Value> Transaction::enterDtcFinish(fb::ITransaction* ret)
{
	return Transaction::NewInstance(ret);
}

void MessageMetadata::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<unsigned, getCountStart, getCountFinish>(tpl, "getCount");
	DefineAsyncMethod<std::string, getFieldStart, getFieldFinish>(tpl, "getField");
	DefineAsyncMethod<std::string, getRelationStart, getRelationFinish>(tpl, "getRelation");
	DefineAsyncMethod<std::string, getOwnerStart, getOwnerFinish>(tpl, "getOwner");
	DefineAsyncMethod<std::string, getAliasStart, getAliasFinish>(tpl, "getAlias");
	DefineAsyncMethod<unsigned, getTypeStart, getTypeFinish>(tpl, "getType");
	DefineAsyncMethod<FB_BOOLEAN, isNullableStart, isNullableFinish>(tpl, "isNullable");
	DefineAsyncMethod<int, getSubTypeStart, getSubTypeFinish>(tpl, "getSubType");
	DefineAsyncMethod<unsigned, getLengthStart, getLengthFinish>(tpl, "getLength");
	DefineAsyncMethod<int, getScaleStart, getScaleFinish>(tpl, "getScale");
	DefineAsyncMethod<unsigned, getCharSetStart, getCharSetFinish>(tpl, "getCharSet");
	DefineAsyncMethod<unsigned, getOffsetStart, getOffsetFinish>(tpl, "getOffset");
	DefineAsyncMethod<unsigned, getNullOffsetStart, getNullOffsetFinish>(tpl, "getNullOffset");
	DefineAsyncMethod<fb::IMetadataBuilder*, getBuilderStart, getBuilderFinish>(tpl, "getBuilder");
	DefineAsyncMethod<unsigned, getMessageLengthStart, getMessageLengthFinish>(tpl, "getMessageLength");
}

MethodStart<void*> MessageMetadata::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MessageMetadata>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> MessageMetadata::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> MessageMetadata::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MessageMetadata>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> MessageMetadata::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<unsigned> MessageMetadata::getCountStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MessageMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getCount(&statusWrapper);
	};
}

v8::Local<v8::Value> MessageMetadata::getCountFinish(unsigned ret)
{
	return Nan::New(ret);
}

MethodStart<std::string> MessageMetadata::getFieldStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MessageMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getField(&statusWrapper, index);
	};
}

v8::Local<v8::Value> MessageMetadata::getFieldFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> MessageMetadata::getRelationStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MessageMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getRelation(&statusWrapper, index);
	};
}

v8::Local<v8::Value> MessageMetadata::getRelationFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> MessageMetadata::getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MessageMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getOwner(&statusWrapper, index);
	};
}

v8::Local<v8::Value> MessageMetadata::getOwnerFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> MessageMetadata::getAliasStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MessageMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getAlias(&statusWrapper, index);
	};
}

v8::Local<v8::Value> MessageMetadata::getAliasFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<unsigned> MessageMetadata::getTypeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MessageMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getType(&statusWrapper, index);
	};
}

v8::Local<v8::Value> MessageMetadata::getTypeFinish(unsigned ret)
{
	return Nan::New(ret);
}

MethodStart<FB_BOOLEAN> MessageMetadata::isNullableStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MessageMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->isNullable(&statusWrapper, index);
	};
}

v8::Local<v8::Value> MessageMetadata::isNullableFinish(FB_BOOLEAN ret)
{
	return Nan::New((bool) ret);
}

MethodStart<int> MessageMetadata::getSubTypeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MessageMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getSubType(&statusWrapper, index);
	};
}

v8::Local<v8::Value> MessageMetadata::getSubTypeFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<unsigned> MessageMetadata::getLengthStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MessageMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getLength(&statusWrapper, index);
	};
}

v8::Local<v8::Value> MessageMetadata::getLengthFinish(unsigned ret)
{
	return Nan::New(ret);
}

MethodStart<int> MessageMetadata::getScaleStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MessageMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getScale(&statusWrapper, index);
	};
}

v8::Local<v8::Value> MessageMetadata::getScaleFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<unsigned> MessageMetadata::getCharSetStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MessageMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getCharSet(&statusWrapper, index);
	};
}

v8::Local<v8::Value> MessageMetadata::getCharSetFinish(unsigned ret)
{
	return Nan::New(ret);
}

MethodStart<unsigned> MessageMetadata::getOffsetStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MessageMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getOffset(&statusWrapper, index);
	};
}

v8::Local<v8::Value> MessageMetadata::getOffsetFinish(unsigned ret)
{
	return Nan::New(ret);
}

MethodStart<unsigned> MessageMetadata::getNullOffsetStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MessageMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getNullOffset(&statusWrapper, index);
	};
}

v8::Local<v8::Value> MessageMetadata::getNullOffsetFinish(unsigned ret)
{
	return Nan::New(ret);
}

MethodStart<fb::IMetadataBuilder*> MessageMetadata::getBuilderStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MessageMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getBuilder(&statusWrapper);
	};
}

v8::Local<v8::Value> MessageMetadata::getBuilderFinish(fb::IMetadataBuilder* ret)
{
	return MetadataBuilder::NewInstance(ret);
}

MethodStart<unsigned> MessageMetadata::getMessageLengthStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MessageMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getMessageLength(&statusWrapper);
	};
}

v8::Local<v8::Value> MessageMetadata::getMessageLengthFinish(unsigned ret)
{
	return Nan::New(ret);
}

void MetadataBuilder::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, setTypeStart, setTypeFinish>(tpl, "setType");
	DefineAsyncMethod<void*, setSubTypeStart, setSubTypeFinish>(tpl, "setSubType");
	DefineAsyncMethod<void*, setLengthStart, setLengthFinish>(tpl, "setLength");
	DefineAsyncMethod<void*, setCharSetStart, setCharSetFinish>(tpl, "setCharSet");
	DefineAsyncMethod<void*, setScaleStart, setScaleFinish>(tpl, "setScale");
	DefineAsyncMethod<void*, truncateStart, truncateFinish>(tpl, "truncate");
	DefineAsyncMethod<void*, moveNameToIndexStart, moveNameToIndexFinish>(tpl, "moveNameToIndex");
	DefineAsyncMethod<void*, removeStart, removeFinish>(tpl, "remove");
	DefineAsyncMethod<unsigned, addFieldStart, addFieldFinish>(tpl, "addField");
	DefineAsyncMethod<fb::IMessageMetadata*, getMetadataStart, getMetadataFinish>(tpl, "getMetadata");
}

MethodStart<void*> MetadataBuilder::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MetadataBuilder>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> MetadataBuilder::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> MetadataBuilder::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MetadataBuilder>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> MetadataBuilder::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> MetadataBuilder::setTypeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MetadataBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();
	unsigned type = info[2]->NumberValue();

	return [obj, status, index, type]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setType(&statusWrapper, index, type);
		return nullptr;
	};
}

v8::Local<v8::Value> MetadataBuilder::setTypeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> MetadataBuilder::setSubTypeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MetadataBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();
	int subType = info[2]->NumberValue();

	return [obj, status, index, subType]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setSubType(&statusWrapper, index, subType);
		return nullptr;
	};
}

v8::Local<v8::Value> MetadataBuilder::setSubTypeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> MetadataBuilder::setLengthStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MetadataBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();
	unsigned length = info[2]->NumberValue();

	return [obj, status, index, length]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setLength(&statusWrapper, index, length);
		return nullptr;
	};
}

v8::Local<v8::Value> MetadataBuilder::setLengthFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> MetadataBuilder::setCharSetStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MetadataBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();
	unsigned charSet = info[2]->NumberValue();

	return [obj, status, index, charSet]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setCharSet(&statusWrapper, index, charSet);
		return nullptr;
	};
}

v8::Local<v8::Value> MetadataBuilder::setCharSetFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> MetadataBuilder::setScaleStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MetadataBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();
	unsigned scale = info[2]->NumberValue();

	return [obj, status, index, scale]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setScale(&statusWrapper, index, scale);
		return nullptr;
	};
}

v8::Local<v8::Value> MetadataBuilder::setScaleFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> MetadataBuilder::truncateStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MetadataBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned count = info[1]->NumberValue();

	return [obj, status, count]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->truncate(&statusWrapper, count);
		return nullptr;
	};
}

v8::Local<v8::Value> MetadataBuilder::truncateFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> MetadataBuilder::moveNameToIndexStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MetadataBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string name = *v8::String::Utf8Value(info[1]->ToString());
	unsigned index = info[2]->NumberValue();

	return [obj, status, name, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->moveNameToIndex(&statusWrapper, name.c_str(), index);
		return nullptr;
	};
}

v8::Local<v8::Value> MetadataBuilder::moveNameToIndexFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> MetadataBuilder::removeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MetadataBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();

	return [obj, status, index]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->remove(&statusWrapper, index);
		return nullptr;
	};
}

v8::Local<v8::Value> MetadataBuilder::removeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<unsigned> MetadataBuilder::addFieldStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MetadataBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->addField(&statusWrapper);
	};
}

v8::Local<v8::Value> MetadataBuilder::addFieldFinish(unsigned ret)
{
	return Nan::New(ret);
}

MethodStart<fb::IMessageMetadata*> MetadataBuilder::getMetadataStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<MetadataBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getMetadata(&statusWrapper);
	};
}

v8::Local<v8::Value> MetadataBuilder::getMetadataFinish(fb::IMessageMetadata* ret)
{
	return MessageMetadata::NewInstance(ret);
}

void ResultSet::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<int, fetchNextStart, fetchNextFinish>(tpl, "fetchNext");
	DefineAsyncMethod<int, fetchPriorStart, fetchPriorFinish>(tpl, "fetchPrior");
	DefineAsyncMethod<int, fetchFirstStart, fetchFirstFinish>(tpl, "fetchFirst");
	DefineAsyncMethod<int, fetchLastStart, fetchLastFinish>(tpl, "fetchLast");
	DefineAsyncMethod<int, fetchAbsoluteStart, fetchAbsoluteFinish>(tpl, "fetchAbsolute");
	DefineAsyncMethod<int, fetchRelativeStart, fetchRelativeFinish>(tpl, "fetchRelative");
	DefineAsyncMethod<FB_BOOLEAN, isEofStart, isEofFinish>(tpl, "isEof");
	DefineAsyncMethod<FB_BOOLEAN, isBofStart, isBofFinish>(tpl, "isBof");
	DefineAsyncMethod<fb::IMessageMetadata*, getMetadataStart, getMetadataFinish>(tpl, "getMetadata");
	DefineAsyncMethod<void*, closeStart, closeFinish>(tpl, "close");
	DefineAsyncMethod<void*, setDelayedOutputFormatStart, setDelayedOutputFormatFinish>(tpl, "setDelayedOutputFormat");
}

MethodStart<void*> ResultSet::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ResultSet>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> ResultSet::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> ResultSet::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ResultSet>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> ResultSet::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<int> ResultSet::fetchNextStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ResultSet>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* message = getAddress<unsigned char>(info[1]);

	return [obj, status, message]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->fetchNext(&statusWrapper, message);
	};
}

v8::Local<v8::Value> ResultSet::fetchNextFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<int> ResultSet::fetchPriorStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ResultSet>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* message = getAddress<unsigned char>(info[1]);

	return [obj, status, message]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->fetchPrior(&statusWrapper, message);
	};
}

v8::Local<v8::Value> ResultSet::fetchPriorFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<int> ResultSet::fetchFirstStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ResultSet>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* message = getAddress<unsigned char>(info[1]);

	return [obj, status, message]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->fetchFirst(&statusWrapper, message);
	};
}

v8::Local<v8::Value> ResultSet::fetchFirstFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<int> ResultSet::fetchLastStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ResultSet>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* message = getAddress<unsigned char>(info[1]);

	return [obj, status, message]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->fetchLast(&statusWrapper, message);
	};
}

v8::Local<v8::Value> ResultSet::fetchLastFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<int> ResultSet::fetchAbsoluteStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ResultSet>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	int position = info[1]->NumberValue();
	auto* message = getAddress<unsigned char>(info[2]);

	return [obj, status, position, message]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->fetchAbsolute(&statusWrapper, position, message);
	};
}

v8::Local<v8::Value> ResultSet::fetchAbsoluteFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<int> ResultSet::fetchRelativeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ResultSet>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	int offset = info[1]->NumberValue();
	auto* message = getAddress<unsigned char>(info[2]);

	return [obj, status, offset, message]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->fetchRelative(&statusWrapper, offset, message);
	};
}

v8::Local<v8::Value> ResultSet::fetchRelativeFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<FB_BOOLEAN> ResultSet::isEofStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ResultSet>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->isEof(&statusWrapper);
	};
}

v8::Local<v8::Value> ResultSet::isEofFinish(FB_BOOLEAN ret)
{
	return Nan::New((bool) ret);
}

MethodStart<FB_BOOLEAN> ResultSet::isBofStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ResultSet>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->isBof(&statusWrapper);
	};
}

v8::Local<v8::Value> ResultSet::isBofFinish(FB_BOOLEAN ret)
{
	return Nan::New((bool) ret);
}

MethodStart<fb::IMessageMetadata*> ResultSet::getMetadataStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ResultSet>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getMetadata(&statusWrapper);
	};
}

v8::Local<v8::Value> ResultSet::getMetadataFinish(fb::IMessageMetadata* ret)
{
	return MessageMetadata::NewInstance(ret);
}

MethodStart<void*> ResultSet::closeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ResultSet>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->close(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> ResultSet::closeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> ResultSet::setDelayedOutputFormatStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ResultSet>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* format = MessageMetadata::CheckedUnwrap(info[1], "format argument", true);

	return [obj, status, format]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setDelayedOutputFormat(&statusWrapper, (format ? format->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> ResultSet::setDelayedOutputFormatFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void Statement::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, getInfoStart, getInfoFinish>(tpl, "getInfo");
	DefineAsyncMethod<unsigned, getTypeStart, getTypeFinish>(tpl, "getType");
	DefineAsyncMethod<std::string, getPlanStart, getPlanFinish>(tpl, "getPlan");
	DefineAsyncMethod<uint64_t, getAffectedRecordsStart, getAffectedRecordsFinish>(tpl, "getAffectedRecords");
	DefineAsyncMethod<fb::IMessageMetadata*, getInputMetadataStart, getInputMetadataFinish>(tpl, "getInputMetadata");
	DefineAsyncMethod<fb::IMessageMetadata*, getOutputMetadataStart, getOutputMetadataFinish>(tpl, "getOutputMetadata");
	DefineAsyncMethod<fb::ITransaction*, executeStart, executeFinish>(tpl, "execute");
	DefineAsyncMethod<fb::IResultSet*, openCursorStart, openCursorFinish>(tpl, "openCursor");
	DefineAsyncMethod<void*, setCursorNameStart, setCursorNameFinish>(tpl, "setCursorName");
	DefineAsyncMethod<void*, freeStart, freeFinish>(tpl, "free");
	DefineAsyncMethod<unsigned, getFlagsStart, getFlagsFinish>(tpl, "getFlags");
}

MethodStart<void*> Statement::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Statement>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> Statement::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Statement::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Statement>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> Statement::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> Statement::getInfoStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Statement>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned itemsLength = info[1]->NumberValue();
	auto* items = getAddress<unsigned char>(info[2]);
	unsigned bufferLength = info[3]->NumberValue();
	auto* buffer = getAddress<unsigned char>(info[4]);

	return [obj, status, itemsLength, items, bufferLength, buffer]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->getInfo(&statusWrapper, itemsLength, items, bufferLength, buffer);
		return nullptr;
	};
}

v8::Local<v8::Value> Statement::getInfoFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<unsigned> Statement::getTypeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Statement>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getType(&statusWrapper);
	};
}

v8::Local<v8::Value> Statement::getTypeFinish(unsigned ret)
{
	return Nan::New(ret);
}

MethodStart<std::string> Statement::getPlanStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Statement>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	bool detailed = info[1]->BooleanValue();

	return [obj, status, detailed]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getPlan(&statusWrapper, detailed);
	};
}

v8::Local<v8::Value> Statement::getPlanFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<uint64_t> Statement::getAffectedRecordsStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Statement>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getAffectedRecords(&statusWrapper);
	};
}

v8::Local<v8::Value> Statement::getAffectedRecordsFinish(uint64_t ret)
{
	return Nan::New((double) ret);
}

MethodStart<fb::IMessageMetadata*> Statement::getInputMetadataStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Statement>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getInputMetadata(&statusWrapper);
	};
}

v8::Local<v8::Value> Statement::getInputMetadataFinish(fb::IMessageMetadata* ret)
{
	return MessageMetadata::NewInstance(ret);
}

MethodStart<fb::IMessageMetadata*> Statement::getOutputMetadataStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Statement>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getOutputMetadata(&statusWrapper);
	};
}

v8::Local<v8::Value> Statement::getOutputMetadataFinish(fb::IMessageMetadata* ret)
{
	return MessageMetadata::NewInstance(ret);
}

MethodStart<fb::ITransaction*> Statement::executeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Statement>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info[1], "transaction argument", true);
	auto* inMetadata = MessageMetadata::CheckedUnwrap(info[2], "inMetadata argument", true);
	auto* inBuffer = getAddress<unsigned char>(info[3]);
	auto* outMetadata = MessageMetadata::CheckedUnwrap(info[4], "outMetadata argument", true);
	auto* outBuffer = getAddress<unsigned char>(info[5]);

	return [obj, status, transaction, inMetadata, inBuffer, outMetadata, outBuffer]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->execute(&statusWrapper, (transaction ? transaction->interface : nullptr), (inMetadata ? inMetadata->interface : nullptr), inBuffer, (outMetadata ? outMetadata->interface : nullptr), outBuffer);
	};
}

v8::Local<v8::Value> Statement::executeFinish(fb::ITransaction* ret)
{
	return Transaction::NewInstance(ret);
}

MethodStart<fb::IResultSet*> Statement::openCursorStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Statement>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info[1], "transaction argument", true);
	auto* inMetadata = MessageMetadata::CheckedUnwrap(info[2], "inMetadata argument", true);
	auto* inBuffer = getAddress<unsigned char>(info[3]);
	auto* outMetadata = MessageMetadata::CheckedUnwrap(info[4], "outMetadata argument", true);
	unsigned flags = info[5]->NumberValue();

	return [obj, status, transaction, inMetadata, inBuffer, outMetadata, flags]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->openCursor(&statusWrapper, (transaction ? transaction->interface : nullptr), (inMetadata ? inMetadata->interface : nullptr), inBuffer, (outMetadata ? outMetadata->interface : nullptr), flags);
	};
}

v8::Local<v8::Value> Statement::openCursorFinish(fb::IResultSet* ret)
{
	return ResultSet::NewInstance(ret);
}

MethodStart<void*> Statement::setCursorNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Statement>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string name = *v8::String::Utf8Value(info[1]->ToString());

	return [obj, status, name]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setCursorName(&statusWrapper, name.c_str());
		return nullptr;
	};
}

v8::Local<v8::Value> Statement::setCursorNameFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Statement::freeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Statement>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->free(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> Statement::freeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<unsigned> Statement::getFlagsStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Statement>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getFlags(&statusWrapper);
	};
}

v8::Local<v8::Value> Statement::getFlagsFinish(unsigned ret)
{
	return Nan::New(ret);
}

void Request::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, receiveStart, receiveFinish>(tpl, "receive");
	DefineAsyncMethod<void*, sendStart, sendFinish>(tpl, "send");
	DefineAsyncMethod<void*, getInfoStart, getInfoFinish>(tpl, "getInfo");
	DefineAsyncMethod<void*, startStart, startFinish>(tpl, "start");
	DefineAsyncMethod<void*, startAndSendStart, startAndSendFinish>(tpl, "startAndSend");
	DefineAsyncMethod<void*, unwindStart, unwindFinish>(tpl, "unwind");
	DefineAsyncMethod<void*, freeStart, freeFinish>(tpl, "free");
}

MethodStart<void*> Request::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Request>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> Request::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Request::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Request>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> Request::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> Request::receiveStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Request>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	int level = info[1]->NumberValue();
	unsigned msgType = info[2]->NumberValue();
	unsigned length = info[3]->NumberValue();
	auto* message = getAddress<unsigned char>(info[4]);

	return [obj, status, level, msgType, length, message]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->receive(&statusWrapper, level, msgType, length, message);
		return nullptr;
	};
}

v8::Local<v8::Value> Request::receiveFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Request::sendStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Request>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	int level = info[1]->NumberValue();
	unsigned msgType = info[2]->NumberValue();
	unsigned length = info[3]->NumberValue();
	auto* message = getAddress<unsigned char>(info[4]);

	return [obj, status, level, msgType, length, message]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->send(&statusWrapper, level, msgType, length, message);
		return nullptr;
	};
}

v8::Local<v8::Value> Request::sendFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Request::getInfoStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Request>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	int level = info[1]->NumberValue();
	unsigned itemsLength = info[2]->NumberValue();
	auto* items = getAddress<unsigned char>(info[3]);
	unsigned bufferLength = info[4]->NumberValue();
	auto* buffer = getAddress<unsigned char>(info[5]);

	return [obj, status, level, itemsLength, items, bufferLength, buffer]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->getInfo(&statusWrapper, level, itemsLength, items, bufferLength, buffer);
		return nullptr;
	};
}

v8::Local<v8::Value> Request::getInfoFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Request::startStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Request>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* tra = Transaction::CheckedUnwrap(info[1], "tra argument", true);
	int level = info[2]->NumberValue();

	return [obj, status, tra, level]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->start(&statusWrapper, (tra ? tra->interface : nullptr), level);
		return nullptr;
	};
}

v8::Local<v8::Value> Request::startFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Request::startAndSendStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Request>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* tra = Transaction::CheckedUnwrap(info[1], "tra argument", true);
	int level = info[2]->NumberValue();
	unsigned msgType = info[3]->NumberValue();
	unsigned length = info[4]->NumberValue();
	auto* message = getAddress<unsigned char>(info[5]);

	return [obj, status, tra, level, msgType, length, message]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->startAndSend(&statusWrapper, (tra ? tra->interface : nullptr), level, msgType, length, message);
		return nullptr;
	};
}

v8::Local<v8::Value> Request::startAndSendFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Request::unwindStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Request>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	int level = info[1]->NumberValue();

	return [obj, status, level]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->unwind(&statusWrapper, level);
		return nullptr;
	};
}

v8::Local<v8::Value> Request::unwindFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Request::freeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Request>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->free(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> Request::freeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void Events::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, cancelStart, cancelFinish>(tpl, "cancel");
}

MethodStart<void*> Events::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Events>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> Events::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Events::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Events>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> Events::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> Events::cancelStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Events>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->cancel(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> Events::cancelFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void Attachment::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, getInfoStart, getInfoFinish>(tpl, "getInfo");
	DefineAsyncMethod<fb::ITransaction*, startTransactionStart, startTransactionFinish>(tpl, "startTransaction");
	DefineAsyncMethod<fb::ITransaction*, reconnectTransactionStart, reconnectTransactionFinish>(tpl, "reconnectTransaction");
	DefineAsyncMethod<fb::IRequest*, compileRequestStart, compileRequestFinish>(tpl, "compileRequest");
	DefineAsyncMethod<void*, transactRequestStart, transactRequestFinish>(tpl, "transactRequest");
	DefineAsyncMethod<void*, executeDynStart, executeDynFinish>(tpl, "executeDyn");
	DefineAsyncMethod<fb::IStatement*, prepareStart, prepareFinish>(tpl, "prepare");
	DefineAsyncMethod<fb::ITransaction*, executeStart, executeFinish>(tpl, "execute");
	DefineAsyncMethod<fb::IResultSet*, openCursorStart, openCursorFinish>(tpl, "openCursor");
	DefineAsyncMethod<fb::IEvents*, queEventsStart, queEventsFinish>(tpl, "queEvents");
	DefineAsyncMethod<void*, cancelOperationStart, cancelOperationFinish>(tpl, "cancelOperation");
	DefineAsyncMethod<void*, pingStart, pingFinish>(tpl, "ping");
	DefineAsyncMethod<void*, detachStart, detachFinish>(tpl, "detach");
	DefineAsyncMethod<void*, dropDatabaseStart, dropDatabaseFinish>(tpl, "dropDatabase");
}

MethodStart<void*> Attachment::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Attachment>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> Attachment::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Attachment::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Attachment>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> Attachment::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> Attachment::getInfoStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Attachment>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned itemsLength = info[1]->NumberValue();
	auto* items = getAddress<unsigned char>(info[2]);
	unsigned bufferLength = info[3]->NumberValue();
	auto* buffer = getAddress<unsigned char>(info[4]);

	return [obj, status, itemsLength, items, bufferLength, buffer]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->getInfo(&statusWrapper, itemsLength, items, bufferLength, buffer);
		return nullptr;
	};
}

v8::Local<v8::Value> Attachment::getInfoFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::ITransaction*> Attachment::startTransactionStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Attachment>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned tpbLength = info[1]->NumberValue();
	auto* tpb = getAddress<unsigned char>(info[2]);

	return [obj, status, tpbLength, tpb]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->startTransaction(&statusWrapper, tpbLength, tpb);
	};
}

v8::Local<v8::Value> Attachment::startTransactionFinish(fb::ITransaction* ret)
{
	return Transaction::NewInstance(ret);
}

MethodStart<fb::ITransaction*> Attachment::reconnectTransactionStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Attachment>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned length = info[1]->NumberValue();
	auto* id = getAddress<unsigned char>(info[2]);

	return [obj, status, length, id]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->reconnectTransaction(&statusWrapper, length, id);
	};
}

v8::Local<v8::Value> Attachment::reconnectTransactionFinish(fb::ITransaction* ret)
{
	return Transaction::NewInstance(ret);
}

MethodStart<fb::IRequest*> Attachment::compileRequestStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Attachment>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned blrLength = info[1]->NumberValue();
	auto* blr = getAddress<unsigned char>(info[2]);

	return [obj, status, blrLength, blr]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->compileRequest(&statusWrapper, blrLength, blr);
	};
}

v8::Local<v8::Value> Attachment::compileRequestFinish(fb::IRequest* ret)
{
	return Request::NewInstance(ret);
}

MethodStart<void*> Attachment::transactRequestStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Attachment>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info[1], "transaction argument", true);
	unsigned blrLength = info[2]->NumberValue();
	auto* blr = getAddress<unsigned char>(info[3]);
	unsigned inMsgLength = info[4]->NumberValue();
	auto* inMsg = getAddress<unsigned char>(info[5]);
	unsigned outMsgLength = info[6]->NumberValue();
	auto* outMsg = getAddress<unsigned char>(info[7]);

	return [obj, status, transaction, blrLength, blr, inMsgLength, inMsg, outMsgLength, outMsg]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->transactRequest(&statusWrapper, (transaction ? transaction->interface : nullptr), blrLength, blr, inMsgLength, inMsg, outMsgLength, outMsg);
		return nullptr;
	};
}

v8::Local<v8::Value> Attachment::transactRequestFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Attachment::executeDynStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Attachment>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info[1], "transaction argument", true);
	unsigned length = info[2]->NumberValue();
	auto* dyn = getAddress<unsigned char>(info[3]);

	return [obj, status, transaction, length, dyn]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->executeDyn(&statusWrapper, (transaction ? transaction->interface : nullptr), length, dyn);
		return nullptr;
	};
}

v8::Local<v8::Value> Attachment::executeDynFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::IStatement*> Attachment::prepareStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Attachment>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* tra = Transaction::CheckedUnwrap(info[1], "tra argument", true);
	unsigned stmtLength = info[2]->NumberValue();
	std::string sqlStmt = *v8::String::Utf8Value(info[3]->ToString());
	unsigned dialect = info[4]->NumberValue();
	unsigned flags = info[5]->NumberValue();

	return [obj, status, tra, stmtLength, sqlStmt, dialect, flags]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->prepare(&statusWrapper, (tra ? tra->interface : nullptr), stmtLength, sqlStmt.c_str(), dialect, flags);
	};
}

v8::Local<v8::Value> Attachment::prepareFinish(fb::IStatement* ret)
{
	return Statement::NewInstance(ret);
}

MethodStart<fb::ITransaction*> Attachment::executeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Attachment>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info[1], "transaction argument", true);
	unsigned stmtLength = info[2]->NumberValue();
	std::string sqlStmt = *v8::String::Utf8Value(info[3]->ToString());
	unsigned dialect = info[4]->NumberValue();
	auto* inMetadata = MessageMetadata::CheckedUnwrap(info[5], "inMetadata argument", true);
	auto* inBuffer = getAddress<unsigned char>(info[6]);
	auto* outMetadata = MessageMetadata::CheckedUnwrap(info[7], "outMetadata argument", true);
	auto* outBuffer = getAddress<unsigned char>(info[8]);

	return [obj, status, transaction, stmtLength, sqlStmt, dialect, inMetadata, inBuffer, outMetadata, outBuffer]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->execute(&statusWrapper, (transaction ? transaction->interface : nullptr), stmtLength, sqlStmt.c_str(), dialect, (inMetadata ? inMetadata->interface : nullptr), inBuffer, (outMetadata ? outMetadata->interface : nullptr), outBuffer);
	};
}

v8::Local<v8::Value> Attachment::executeFinish(fb::ITransaction* ret)
{
	return Transaction::NewInstance(ret);
}

MethodStart<fb::IResultSet*> Attachment::openCursorStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Attachment>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* transaction = Transaction::CheckedUnwrap(info[1], "transaction argument", true);
	unsigned stmtLength = info[2]->NumberValue();
	std::string sqlStmt = *v8::String::Utf8Value(info[3]->ToString());
	unsigned dialect = info[4]->NumberValue();
	auto* inMetadata = MessageMetadata::CheckedUnwrap(info[5], "inMetadata argument", true);
	auto* inBuffer = getAddress<unsigned char>(info[6]);
	auto* outMetadata = MessageMetadata::CheckedUnwrap(info[7], "outMetadata argument", true);
	std::string cursorName = *v8::String::Utf8Value(info[8]->ToString());
	unsigned cursorFlags = info[9]->NumberValue();

	return [obj, status, transaction, stmtLength, sqlStmt, dialect, inMetadata, inBuffer, outMetadata, cursorName, cursorFlags]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->openCursor(&statusWrapper, (transaction ? transaction->interface : nullptr), stmtLength, sqlStmt.c_str(), dialect, (inMetadata ? inMetadata->interface : nullptr), inBuffer, (outMetadata ? outMetadata->interface : nullptr), cursorName.c_str(), cursorFlags);
	};
}

v8::Local<v8::Value> Attachment::openCursorFinish(fb::IResultSet* ret)
{
	return ResultSet::NewInstance(ret);
}

MethodStart<fb::IEvents*> Attachment::queEventsStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Attachment>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* callback = EventCallback::CheckedUnwrap(info[1], "callback argument", true);
	unsigned length = info[2]->NumberValue();
	auto* events = getAddress<unsigned char>(info[3]);

	return [obj, status, callback, length, events]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->queEvents(&statusWrapper, (callback ? callback->interface : nullptr), length, events);
	};
}

v8::Local<v8::Value> Attachment::queEventsFinish(fb::IEvents* ret)
{
	return Events::NewInstance(ret);
}

MethodStart<void*> Attachment::cancelOperationStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Attachment>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	int option = info[1]->NumberValue();

	return [obj, status, option]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->cancelOperation(&statusWrapper, option);
		return nullptr;
	};
}

v8::Local<v8::Value> Attachment::cancelOperationFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Attachment::pingStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Attachment>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->ping(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> Attachment::pingFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Attachment::detachStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Attachment>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->detach(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> Attachment::detachFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Attachment::dropDatabaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Attachment>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->dropDatabase(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> Attachment::dropDatabaseFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void Service::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, detachStart, detachFinish>(tpl, "detach");
	DefineAsyncMethod<void*, queryStart, queryFinish>(tpl, "query");
	DefineAsyncMethod<void*, startStart, startFinish>(tpl, "start");
}

MethodStart<void*> Service::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Service>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> Service::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Service::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Service>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> Service::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> Service::detachStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Service>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->detach(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> Service::detachFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Service::queryStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Service>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned sendLength = info[1]->NumberValue();
	auto* sendItems = getAddress<unsigned char>(info[2]);
	unsigned receiveLength = info[3]->NumberValue();
	auto* receiveItems = getAddress<unsigned char>(info[4]);
	unsigned bufferLength = info[5]->NumberValue();
	auto* buffer = getAddress<unsigned char>(info[6]);

	return [obj, status, sendLength, sendItems, receiveLength, receiveItems, bufferLength, buffer]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->query(&statusWrapper, sendLength, sendItems, receiveLength, receiveItems, bufferLength, buffer);
		return nullptr;
	};
}

v8::Local<v8::Value> Service::queryFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Service::startStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Service>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned spbLength = info[1]->NumberValue();
	auto* spb = getAddress<unsigned char>(info[2]);

	return [obj, status, spbLength, spb]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->start(&statusWrapper, spbLength, spb);
		return nullptr;
	};
}

v8::Local<v8::Value> Service::startFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void Provider::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, setOwnerStart, setOwnerFinish>(tpl, "setOwner");
	DefineAsyncMethod<fb::IReferenceCounted*, getOwnerStart, getOwnerFinish>(tpl, "getOwner");
	DefineAsyncMethod<fb::IAttachment*, attachDatabaseStart, attachDatabaseFinish>(tpl, "attachDatabase");
	DefineAsyncMethod<fb::IAttachment*, createDatabaseStart, createDatabaseFinish>(tpl, "createDatabase");
	DefineAsyncMethod<fb::IService*, attachServiceManagerStart, attachServiceManagerFinish>(tpl, "attachServiceManager");
	DefineAsyncMethod<void*, shutdownStart, shutdownFinish>(tpl, "shutdown");
	DefineAsyncMethod<void*, setDbCryptCallbackStart, setDbCryptCallbackFinish>(tpl, "setDbCryptCallback");
}

MethodStart<void*> Provider::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Provider>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> Provider::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Provider::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Provider>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> Provider::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> Provider::setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Provider>(info.This());
	auto* r = ReferenceCounted::CheckedUnwrap(info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> Provider::setOwnerFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::IReferenceCounted*> Provider::getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Provider>(info.This());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

v8::Local<v8::Value> Provider::getOwnerFinish(fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(ret);
}

MethodStart<fb::IAttachment*> Provider::attachDatabaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Provider>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string fileName = *v8::String::Utf8Value(info[1]->ToString());
	unsigned dpbLength = info[2]->NumberValue();
	auto* dpb = getAddress<unsigned char>(info[3]);

	return [obj, status, fileName, dpbLength, dpb]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->attachDatabase(&statusWrapper, fileName.c_str(), dpbLength, dpb);
	};
}

v8::Local<v8::Value> Provider::attachDatabaseFinish(fb::IAttachment* ret)
{
	return Attachment::NewInstance(ret);
}

MethodStart<fb::IAttachment*> Provider::createDatabaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Provider>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string fileName = *v8::String::Utf8Value(info[1]->ToString());
	unsigned dpbLength = info[2]->NumberValue();
	auto* dpb = getAddress<unsigned char>(info[3]);

	return [obj, status, fileName, dpbLength, dpb]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->createDatabase(&statusWrapper, fileName.c_str(), dpbLength, dpb);
	};
}

v8::Local<v8::Value> Provider::createDatabaseFinish(fb::IAttachment* ret)
{
	return Attachment::NewInstance(ret);
}

MethodStart<fb::IService*> Provider::attachServiceManagerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Provider>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string service = *v8::String::Utf8Value(info[1]->ToString());
	unsigned spbLength = info[2]->NumberValue();
	auto* spb = getAddress<unsigned char>(info[3]);

	return [obj, status, service, spbLength, spb]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->attachServiceManager(&statusWrapper, service.c_str(), spbLength, spb);
	};
}

v8::Local<v8::Value> Provider::attachServiceManagerFinish(fb::IService* ret)
{
	return Service::NewInstance(ret);
}

MethodStart<void*> Provider::shutdownStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Provider>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned timeout = info[1]->NumberValue();
	int reason = info[2]->NumberValue();

	return [obj, status, timeout, reason]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->shutdown(&statusWrapper, timeout, reason);
		return nullptr;
	};
}

v8::Local<v8::Value> Provider::shutdownFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Provider::setDbCryptCallbackStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Provider>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* cryptCallback = CryptKeyCallback::CheckedUnwrap(info[1], "cryptCallback argument", true);

	return [obj, status, cryptCallback]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setDbCryptCallback(&statusWrapper, (cryptCallback ? cryptCallback->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> Provider::setDbCryptCallbackFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void DtcStart::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, disposeStart, disposeFinish>(tpl, "dispose");
	DefineAsyncMethod<void*, addAttachmentStart, addAttachmentFinish>(tpl, "addAttachment");
	DefineAsyncMethod<void*, addWithTpbStart, addWithTpbFinish>(tpl, "addWithTpb");
	DefineAsyncMethod<fb::ITransaction*, startStart, startFinish>(tpl, "start");
}

MethodStart<void*> DtcStart::disposeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<DtcStart>(info.This());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

v8::Local<v8::Value> DtcStart::disposeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> DtcStart::addAttachmentStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<DtcStart>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* att = Attachment::CheckedUnwrap(info[1], "att argument", true);

	return [obj, status, att]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->addAttachment(&statusWrapper, (att ? att->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> DtcStart::addAttachmentFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> DtcStart::addWithTpbStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<DtcStart>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* att = Attachment::CheckedUnwrap(info[1], "att argument", true);
	unsigned length = info[2]->NumberValue();
	auto* tpb = getAddress<unsigned char>(info[3]);

	return [obj, status, att, length, tpb]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->addWithTpb(&statusWrapper, (att ? att->interface : nullptr), length, tpb);
		return nullptr;
	};
}

v8::Local<v8::Value> DtcStart::addWithTpbFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::ITransaction*> DtcStart::startStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<DtcStart>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->start(&statusWrapper);
	};
}

v8::Local<v8::Value> DtcStart::startFinish(fb::ITransaction* ret)
{
	return Transaction::NewInstance(ret);
}

void Dtc::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<fb::ITransaction*, joinStart, joinFinish>(tpl, "join");
	DefineAsyncMethod<fb::IDtcStart*, startBuilderStart, startBuilderFinish>(tpl, "startBuilder");
}

MethodStart<fb::ITransaction*> Dtc::joinStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Dtc>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* one = Transaction::CheckedUnwrap(info[1], "one argument", true);
	auto* two = Transaction::CheckedUnwrap(info[2], "two argument", true);

	return [obj, status, one, two]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->join(&statusWrapper, (one ? one->interface : nullptr), (two ? two->interface : nullptr));
	};
}

v8::Local<v8::Value> Dtc::joinFinish(fb::ITransaction* ret)
{
	return Transaction::NewInstance(ret);
}

MethodStart<fb::IDtcStart*> Dtc::startBuilderStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Dtc>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->startBuilder(&statusWrapper);
	};
}

v8::Local<v8::Value> Dtc::startBuilderFinish(fb::IDtcStart* ret)
{
	return DtcStart::NewInstance(ret);
}

void Auth::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, setOwnerStart, setOwnerFinish>(tpl, "setOwner");
	DefineAsyncMethod<fb::IReferenceCounted*, getOwnerStart, getOwnerFinish>(tpl, "getOwner");
}

MethodStart<void*> Auth::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Auth>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> Auth::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Auth::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Auth>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> Auth::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> Auth::setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Auth>(info.This());
	auto* r = ReferenceCounted::CheckedUnwrap(info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> Auth::setOwnerFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::IReferenceCounted*> Auth::getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Auth>(info.This());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

v8::Local<v8::Value> Auth::getOwnerFinish(fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(ret);
}

void Writer::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, resetStart, resetFinish>(tpl, "reset");
	DefineAsyncMethod<void*, addStart, addFinish>(tpl, "add");
	DefineAsyncMethod<void*, setTypeStart, setTypeFinish>(tpl, "setType");
	DefineAsyncMethod<void*, setDbStart, setDbFinish>(tpl, "setDb");
}

MethodStart<void*> Writer::resetStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Writer>(info.This());

	return [obj]() {
		obj->interface->reset();
		return nullptr;
	};
}

v8::Local<v8::Value> Writer::resetFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Writer::addStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Writer>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string name = *v8::String::Utf8Value(info[1]->ToString());

	return [obj, status, name]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->add(&statusWrapper, name.c_str());
		return nullptr;
	};
}

v8::Local<v8::Value> Writer::addFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Writer::setTypeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Writer>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string value = *v8::String::Utf8Value(info[1]->ToString());

	return [obj, status, value]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setType(&statusWrapper, value.c_str());
		return nullptr;
	};
}

v8::Local<v8::Value> Writer::setTypeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Writer::setDbStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Writer>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string value = *v8::String::Utf8Value(info[1]->ToString());

	return [obj, status, value]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setDb(&statusWrapper, value.c_str());
		return nullptr;
	};
}

v8::Local<v8::Value> Writer::setDbFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void ServerBlock::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<std::string, getLoginStart, getLoginFinish>(tpl, "getLogin");
	DefineAsyncMethod<const unsigned char*, getDataStart, getDataFinish>(tpl, "getData");
	DefineAsyncMethod<void*, putDataStart, putDataFinish>(tpl, "putData");
	DefineAsyncMethod<fb::ICryptKey*, newKeyStart, newKeyFinish>(tpl, "newKey");
}

MethodStart<std::string> ServerBlock::getLoginStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ServerBlock>(info.This());

	return [obj]() {
		return obj->interface->getLogin();
	};
}

v8::Local<v8::Value> ServerBlock::getLoginFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<const unsigned char*> ServerBlock::getDataStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ServerBlock>(info.This());
	auto* length = getAddress<unsigned>(info[0]);

	return [obj, length]() {
		return obj->interface->getData(length);
	};
}

v8::Local<v8::Value> ServerBlock::getDataFinish(const unsigned char* ret)
{
	return Pointer::NewInstance(ret);
}

MethodStart<void*> ServerBlock::putDataStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ServerBlock>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned length = info[1]->NumberValue();
	auto* data = getAddress<unsigned char>(info[2]);

	return [obj, status, length, data]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->putData(&statusWrapper, length, data);
		return nullptr;
	};
}

v8::Local<v8::Value> ServerBlock::putDataFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::ICryptKey*> ServerBlock::newKeyStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ServerBlock>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->newKey(&statusWrapper);
	};
}

v8::Local<v8::Value> ServerBlock::newKeyFinish(fb::ICryptKey* ret)
{
	return CryptKey::NewInstance(ret);
}

void ClientBlock::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<std::string, getLoginStart, getLoginFinish>(tpl, "getLogin");
	DefineAsyncMethod<std::string, getPasswordStart, getPasswordFinish>(tpl, "getPassword");
	DefineAsyncMethod<const unsigned char*, getDataStart, getDataFinish>(tpl, "getData");
	DefineAsyncMethod<void*, putDataStart, putDataFinish>(tpl, "putData");
	DefineAsyncMethod<fb::ICryptKey*, newKeyStart, newKeyFinish>(tpl, "newKey");
}

MethodStart<void*> ClientBlock::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ClientBlock>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> ClientBlock::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> ClientBlock::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ClientBlock>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> ClientBlock::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<std::string> ClientBlock::getLoginStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ClientBlock>(info.This());

	return [obj]() {
		return obj->interface->getLogin();
	};
}

v8::Local<v8::Value> ClientBlock::getLoginFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> ClientBlock::getPasswordStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ClientBlock>(info.This());

	return [obj]() {
		return obj->interface->getPassword();
	};
}

v8::Local<v8::Value> ClientBlock::getPasswordFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<const unsigned char*> ClientBlock::getDataStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ClientBlock>(info.This());
	auto* length = getAddress<unsigned>(info[0]);

	return [obj, length]() {
		return obj->interface->getData(length);
	};
}

v8::Local<v8::Value> ClientBlock::getDataFinish(const unsigned char* ret)
{
	return Pointer::NewInstance(ret);
}

MethodStart<void*> ClientBlock::putDataStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ClientBlock>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned length = info[1]->NumberValue();
	auto* data = getAddress<unsigned char>(info[2]);

	return [obj, status, length, data]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->putData(&statusWrapper, length, data);
		return nullptr;
	};
}

v8::Local<v8::Value> ClientBlock::putDataFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::ICryptKey*> ClientBlock::newKeyStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ClientBlock>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->newKey(&statusWrapper);
	};
}

v8::Local<v8::Value> ClientBlock::newKeyFinish(fb::ICryptKey* ret)
{
	return CryptKey::NewInstance(ret);
}

void Server::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, setOwnerStart, setOwnerFinish>(tpl, "setOwner");
	DefineAsyncMethod<fb::IReferenceCounted*, getOwnerStart, getOwnerFinish>(tpl, "getOwner");
	DefineAsyncMethod<int, authenticateStart, authenticateFinish>(tpl, "authenticate");
}

MethodStart<void*> Server::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Server>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> Server::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Server::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Server>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> Server::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> Server::setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Server>(info.This());
	auto* r = ReferenceCounted::CheckedUnwrap(info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> Server::setOwnerFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::IReferenceCounted*> Server::getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Server>(info.This());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

v8::Local<v8::Value> Server::getOwnerFinish(fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(ret);
}

MethodStart<int> Server::authenticateStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Server>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* sBlock = ServerBlock::CheckedUnwrap(info[1], "sBlock argument", true);
	auto* writerInterface = Writer::CheckedUnwrap(info[2], "writerInterface argument", true);

	return [obj, status, sBlock, writerInterface]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->authenticate(&statusWrapper, (sBlock ? sBlock->interface : nullptr), (writerInterface ? writerInterface->interface : nullptr));
	};
}

v8::Local<v8::Value> Server::authenticateFinish(int ret)
{
	return Nan::New(ret);
}

void Client::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, setOwnerStart, setOwnerFinish>(tpl, "setOwner");
	DefineAsyncMethod<fb::IReferenceCounted*, getOwnerStart, getOwnerFinish>(tpl, "getOwner");
	DefineAsyncMethod<int, authenticateStart, authenticateFinish>(tpl, "authenticate");
}

MethodStart<void*> Client::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Client>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> Client::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Client::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Client>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> Client::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> Client::setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Client>(info.This());
	auto* r = ReferenceCounted::CheckedUnwrap(info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> Client::setOwnerFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::IReferenceCounted*> Client::getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Client>(info.This());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

v8::Local<v8::Value> Client::getOwnerFinish(fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(ret);
}

MethodStart<int> Client::authenticateStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Client>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* cBlock = ClientBlock::CheckedUnwrap(info[1], "cBlock argument", true);

	return [obj, status, cBlock]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->authenticate(&statusWrapper, (cBlock ? cBlock->interface : nullptr));
	};
}

v8::Local<v8::Value> Client::authenticateFinish(int ret)
{
	return Nan::New(ret);
}

void UserField::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<int, enteredStart, enteredFinish>(tpl, "entered");
	DefineAsyncMethod<int, specifiedStart, specifiedFinish>(tpl, "specified");
	DefineAsyncMethod<void*, setEnteredStart, setEnteredFinish>(tpl, "setEntered");
}

MethodStart<int> UserField::enteredStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<UserField>(info.This());

	return [obj]() {
		return obj->interface->entered();
	};
}

v8::Local<v8::Value> UserField::enteredFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<int> UserField::specifiedStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<UserField>(info.This());

	return [obj]() {
		return obj->interface->specified();
	};
}

v8::Local<v8::Value> UserField::specifiedFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> UserField::setEnteredStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<UserField>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	int newValue = info[1]->NumberValue();

	return [obj, status, newValue]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setEntered(&statusWrapper, newValue);
		return nullptr;
	};
}

v8::Local<v8::Value> UserField::setEnteredFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void CharUserField::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<int, enteredStart, enteredFinish>(tpl, "entered");
	DefineAsyncMethod<int, specifiedStart, specifiedFinish>(tpl, "specified");
	DefineAsyncMethod<void*, setEnteredStart, setEnteredFinish>(tpl, "setEntered");
	DefineAsyncMethod<std::string, getStart, getFinish>(tpl, "get");
	DefineAsyncMethod<void*, setStart, setFinish>(tpl, "set");
}

MethodStart<int> CharUserField::enteredStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<CharUserField>(info.This());

	return [obj]() {
		return obj->interface->entered();
	};
}

v8::Local<v8::Value> CharUserField::enteredFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<int> CharUserField::specifiedStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<CharUserField>(info.This());

	return [obj]() {
		return obj->interface->specified();
	};
}

v8::Local<v8::Value> CharUserField::specifiedFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> CharUserField::setEnteredStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<CharUserField>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	int newValue = info[1]->NumberValue();

	return [obj, status, newValue]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setEntered(&statusWrapper, newValue);
		return nullptr;
	};
}

v8::Local<v8::Value> CharUserField::setEnteredFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<std::string> CharUserField::getStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<CharUserField>(info.This());

	return [obj]() {
		return obj->interface->get();
	};
}

v8::Local<v8::Value> CharUserField::getFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<void*> CharUserField::setStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<CharUserField>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string newValue = *v8::String::Utf8Value(info[1]->ToString());

	return [obj, status, newValue]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->set(&statusWrapper, newValue.c_str());
		return nullptr;
	};
}

v8::Local<v8::Value> CharUserField::setFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void IntUserField::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<int, enteredStart, enteredFinish>(tpl, "entered");
	DefineAsyncMethod<int, specifiedStart, specifiedFinish>(tpl, "specified");
	DefineAsyncMethod<void*, setEnteredStart, setEnteredFinish>(tpl, "setEntered");
	DefineAsyncMethod<int, getStart, getFinish>(tpl, "get");
	DefineAsyncMethod<void*, setStart, setFinish>(tpl, "set");
}

MethodStart<int> IntUserField::enteredStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<IntUserField>(info.This());

	return [obj]() {
		return obj->interface->entered();
	};
}

v8::Local<v8::Value> IntUserField::enteredFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<int> IntUserField::specifiedStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<IntUserField>(info.This());

	return [obj]() {
		return obj->interface->specified();
	};
}

v8::Local<v8::Value> IntUserField::specifiedFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> IntUserField::setEnteredStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<IntUserField>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	int newValue = info[1]->NumberValue();

	return [obj, status, newValue]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setEntered(&statusWrapper, newValue);
		return nullptr;
	};
}

v8::Local<v8::Value> IntUserField::setEnteredFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> IntUserField::getStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<IntUserField>(info.This());

	return [obj]() {
		return obj->interface->get();
	};
}

v8::Local<v8::Value> IntUserField::getFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> IntUserField::setStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<IntUserField>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	int newValue = info[1]->NumberValue();

	return [obj, status, newValue]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->set(&statusWrapper, newValue);
		return nullptr;
	};
}

v8::Local<v8::Value> IntUserField::setFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void User::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<unsigned, operationStart, operationFinish>(tpl, "operation");
	DefineAsyncMethod<fb::ICharUserField*, userNameStart, userNameFinish>(tpl, "userName");
	DefineAsyncMethod<fb::ICharUserField*, passwordStart, passwordFinish>(tpl, "password");
	DefineAsyncMethod<fb::ICharUserField*, firstNameStart, firstNameFinish>(tpl, "firstName");
	DefineAsyncMethod<fb::ICharUserField*, lastNameStart, lastNameFinish>(tpl, "lastName");
	DefineAsyncMethod<fb::ICharUserField*, middleNameStart, middleNameFinish>(tpl, "middleName");
	DefineAsyncMethod<fb::ICharUserField*, commentStart, commentFinish>(tpl, "comment");
	DefineAsyncMethod<fb::ICharUserField*, attributesStart, attributesFinish>(tpl, "attributes");
	DefineAsyncMethod<fb::IIntUserField*, activeStart, activeFinish>(tpl, "active");
	DefineAsyncMethod<fb::IIntUserField*, adminStart, adminFinish>(tpl, "admin");
	DefineAsyncMethod<void*, clearStart, clearFinish>(tpl, "clear");
}

MethodStart<unsigned> User::operationStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<User>(info.This());

	return [obj]() {
		return obj->interface->operation();
	};
}

v8::Local<v8::Value> User::operationFinish(unsigned ret)
{
	return Nan::New(ret);
}

MethodStart<fb::ICharUserField*> User::userNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<User>(info.This());

	return [obj]() {
		return obj->interface->userName();
	};
}

v8::Local<v8::Value> User::userNameFinish(fb::ICharUserField* ret)
{
	return CharUserField::NewInstance(ret);
}

MethodStart<fb::ICharUserField*> User::passwordStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<User>(info.This());

	return [obj]() {
		return obj->interface->password();
	};
}

v8::Local<v8::Value> User::passwordFinish(fb::ICharUserField* ret)
{
	return CharUserField::NewInstance(ret);
}

MethodStart<fb::ICharUserField*> User::firstNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<User>(info.This());

	return [obj]() {
		return obj->interface->firstName();
	};
}

v8::Local<v8::Value> User::firstNameFinish(fb::ICharUserField* ret)
{
	return CharUserField::NewInstance(ret);
}

MethodStart<fb::ICharUserField*> User::lastNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<User>(info.This());

	return [obj]() {
		return obj->interface->lastName();
	};
}

v8::Local<v8::Value> User::lastNameFinish(fb::ICharUserField* ret)
{
	return CharUserField::NewInstance(ret);
}

MethodStart<fb::ICharUserField*> User::middleNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<User>(info.This());

	return [obj]() {
		return obj->interface->middleName();
	};
}

v8::Local<v8::Value> User::middleNameFinish(fb::ICharUserField* ret)
{
	return CharUserField::NewInstance(ret);
}

MethodStart<fb::ICharUserField*> User::commentStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<User>(info.This());

	return [obj]() {
		return obj->interface->comment();
	};
}

v8::Local<v8::Value> User::commentFinish(fb::ICharUserField* ret)
{
	return CharUserField::NewInstance(ret);
}

MethodStart<fb::ICharUserField*> User::attributesStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<User>(info.This());

	return [obj]() {
		return obj->interface->attributes();
	};
}

v8::Local<v8::Value> User::attributesFinish(fb::ICharUserField* ret)
{
	return CharUserField::NewInstance(ret);
}

MethodStart<fb::IIntUserField*> User::activeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<User>(info.This());

	return [obj]() {
		return obj->interface->active();
	};
}

v8::Local<v8::Value> User::activeFinish(fb::IIntUserField* ret)
{
	return IntUserField::NewInstance(ret);
}

MethodStart<fb::IIntUserField*> User::adminStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<User>(info.This());

	return [obj]() {
		return obj->interface->admin();
	};
}

v8::Local<v8::Value> User::adminFinish(fb::IIntUserField* ret)
{
	return IntUserField::NewInstance(ret);
}

MethodStart<void*> User::clearStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<User>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->clear(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> User::clearFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void ListUsers::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, listStart, listFinish>(tpl, "list");
}

MethodStart<void*> ListUsers::listStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ListUsers>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* user = User::CheckedUnwrap(info[1], "user argument", true);

	return [obj, status, user]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->list(&statusWrapper, (user ? user->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> ListUsers::listFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void LogonInfo::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<std::string, nameStart, nameFinish>(tpl, "name");
	DefineAsyncMethod<std::string, roleStart, roleFinish>(tpl, "role");
	DefineAsyncMethod<std::string, networkProtocolStart, networkProtocolFinish>(tpl, "networkProtocol");
	DefineAsyncMethod<std::string, remoteAddressStart, remoteAddressFinish>(tpl, "remoteAddress");
	DefineAsyncMethod<const unsigned char*, authBlockStart, authBlockFinish>(tpl, "authBlock");
}

MethodStart<std::string> LogonInfo::nameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<LogonInfo>(info.This());

	return [obj]() {
		return obj->interface->name();
	};
}

v8::Local<v8::Value> LogonInfo::nameFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> LogonInfo::roleStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<LogonInfo>(info.This());

	return [obj]() {
		return obj->interface->role();
	};
}

v8::Local<v8::Value> LogonInfo::roleFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> LogonInfo::networkProtocolStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<LogonInfo>(info.This());

	return [obj]() {
		return obj->interface->networkProtocol();
	};
}

v8::Local<v8::Value> LogonInfo::networkProtocolFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> LogonInfo::remoteAddressStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<LogonInfo>(info.This());

	return [obj]() {
		return obj->interface->remoteAddress();
	};
}

v8::Local<v8::Value> LogonInfo::remoteAddressFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<const unsigned char*> LogonInfo::authBlockStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<LogonInfo>(info.This());
	auto* length = getAddress<unsigned>(info[0]);

	return [obj, length]() {
		return obj->interface->authBlock(length);
	};
}

v8::Local<v8::Value> LogonInfo::authBlockFinish(const unsigned char* ret)
{
	return Pointer::NewInstance(ret);
}

void Management::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, setOwnerStart, setOwnerFinish>(tpl, "setOwner");
	DefineAsyncMethod<fb::IReferenceCounted*, getOwnerStart, getOwnerFinish>(tpl, "getOwner");
	DefineAsyncMethod<void*, startStart, startFinish>(tpl, "start");
	DefineAsyncMethod<int, executeStart, executeFinish>(tpl, "execute");
	DefineAsyncMethod<void*, commitStart, commitFinish>(tpl, "commit");
	DefineAsyncMethod<void*, rollbackStart, rollbackFinish>(tpl, "rollback");
}

MethodStart<void*> Management::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Management>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> Management::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Management::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Management>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> Management::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> Management::setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Management>(info.This());
	auto* r = ReferenceCounted::CheckedUnwrap(info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> Management::setOwnerFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::IReferenceCounted*> Management::getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Management>(info.This());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

v8::Local<v8::Value> Management::getOwnerFinish(fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(ret);
}

MethodStart<void*> Management::startStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Management>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* logonInfo = LogonInfo::CheckedUnwrap(info[1], "logonInfo argument", true);

	return [obj, status, logonInfo]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->start(&statusWrapper, (logonInfo ? logonInfo->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> Management::startFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Management::executeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Management>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* user = User::CheckedUnwrap(info[1], "user argument", true);
	auto* callback = ListUsers::CheckedUnwrap(info[2], "callback argument", true);

	return [obj, status, user, callback]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->execute(&statusWrapper, (user ? user->interface : nullptr), (callback ? callback->interface : nullptr));
	};
}

v8::Local<v8::Value> Management::executeFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> Management::commitStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Management>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->commit(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> Management::commitFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Management::rollbackStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Management>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->rollback(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> Management::rollbackFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void WireCryptPlugin::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, setOwnerStart, setOwnerFinish>(tpl, "setOwner");
	DefineAsyncMethod<fb::IReferenceCounted*, getOwnerStart, getOwnerFinish>(tpl, "getOwner");
	DefineAsyncMethod<std::string, getKnownTypesStart, getKnownTypesFinish>(tpl, "getKnownTypes");
	DefineAsyncMethod<void*, setKeyStart, setKeyFinish>(tpl, "setKey");
	DefineAsyncMethod<void*, encryptStart, encryptFinish>(tpl, "encrypt");
	DefineAsyncMethod<void*, decryptStart, decryptFinish>(tpl, "decrypt");
}

MethodStart<void*> WireCryptPlugin::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<WireCryptPlugin>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> WireCryptPlugin::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> WireCryptPlugin::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<WireCryptPlugin>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> WireCryptPlugin::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> WireCryptPlugin::setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<WireCryptPlugin>(info.This());
	auto* r = ReferenceCounted::CheckedUnwrap(info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> WireCryptPlugin::setOwnerFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::IReferenceCounted*> WireCryptPlugin::getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<WireCryptPlugin>(info.This());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

v8::Local<v8::Value> WireCryptPlugin::getOwnerFinish(fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(ret);
}

MethodStart<std::string> WireCryptPlugin::getKnownTypesStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<WireCryptPlugin>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getKnownTypes(&statusWrapper);
	};
}

v8::Local<v8::Value> WireCryptPlugin::getKnownTypesFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<void*> WireCryptPlugin::setKeyStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<WireCryptPlugin>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* key = CryptKey::CheckedUnwrap(info[1], "key argument", true);

	return [obj, status, key]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setKey(&statusWrapper, (key ? key->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> WireCryptPlugin::setKeyFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> WireCryptPlugin::encryptStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<WireCryptPlugin>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned length = info[1]->NumberValue();
	auto* from = getAddress<unsigned char>(info[2]);
	auto* to = getAddress<unsigned char>(info[3]);

	return [obj, status, length, from, to]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->encrypt(&statusWrapper, length, from, to);
		return nullptr;
	};
}

v8::Local<v8::Value> WireCryptPlugin::encryptFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> WireCryptPlugin::decryptStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<WireCryptPlugin>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned length = info[1]->NumberValue();
	auto* from = getAddress<unsigned char>(info[2]);
	auto* to = getAddress<unsigned char>(info[3]);

	return [obj, status, length, from, to]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->decrypt(&statusWrapper, length, from, to);
		return nullptr;
	};
}

v8::Local<v8::Value> WireCryptPlugin::decryptFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void CryptKeyCallback::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<unsigned, callbackStart, callbackFinish>(tpl, "callback");
}

MethodStart<unsigned> CryptKeyCallback::callbackStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<CryptKeyCallback>(info.This());
	unsigned dataLength = info[0]->NumberValue();
	auto* data = getAddress<unsigned char>(info[1]);
	unsigned bufferLength = info[2]->NumberValue();
	auto* buffer = getAddress<unsigned char>(info[3]);

	return [obj, dataLength, data, bufferLength, buffer]() {
		return obj->interface->callback(dataLength, data, bufferLength, buffer);
	};
}

v8::Local<v8::Value> CryptKeyCallback::callbackFinish(unsigned ret)
{
	return Nan::New(ret);
}

void KeyHolderPlugin::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, setOwnerStart, setOwnerFinish>(tpl, "setOwner");
	DefineAsyncMethod<fb::IReferenceCounted*, getOwnerStart, getOwnerFinish>(tpl, "getOwner");
	DefineAsyncMethod<int, keyCallbackStart, keyCallbackFinish>(tpl, "keyCallback");
	DefineAsyncMethod<fb::ICryptKeyCallback*, keyHandleStart, keyHandleFinish>(tpl, "keyHandle");
}

MethodStart<void*> KeyHolderPlugin::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<KeyHolderPlugin>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> KeyHolderPlugin::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> KeyHolderPlugin::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<KeyHolderPlugin>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> KeyHolderPlugin::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> KeyHolderPlugin::setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<KeyHolderPlugin>(info.This());
	auto* r = ReferenceCounted::CheckedUnwrap(info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> KeyHolderPlugin::setOwnerFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::IReferenceCounted*> KeyHolderPlugin::getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<KeyHolderPlugin>(info.This());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

v8::Local<v8::Value> KeyHolderPlugin::getOwnerFinish(fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(ret);
}

MethodStart<int> KeyHolderPlugin::keyCallbackStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<KeyHolderPlugin>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* callback = CryptKeyCallback::CheckedUnwrap(info[1], "callback argument", true);

	return [obj, status, callback]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->keyCallback(&statusWrapper, (callback ? callback->interface : nullptr));
	};
}

v8::Local<v8::Value> KeyHolderPlugin::keyCallbackFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<fb::ICryptKeyCallback*> KeyHolderPlugin::keyHandleStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<KeyHolderPlugin>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string keyName = *v8::String::Utf8Value(info[1]->ToString());

	return [obj, status, keyName]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->keyHandle(&statusWrapper, keyName.c_str());
	};
}

v8::Local<v8::Value> KeyHolderPlugin::keyHandleFinish(fb::ICryptKeyCallback* ret)
{
	return CryptKeyCallback::NewInstance(ret);
}

void DbCryptPlugin::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, setOwnerStart, setOwnerFinish>(tpl, "setOwner");
	DefineAsyncMethod<fb::IReferenceCounted*, getOwnerStart, getOwnerFinish>(tpl, "getOwner");
}

MethodStart<void*> DbCryptPlugin::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<DbCryptPlugin>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> DbCryptPlugin::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> DbCryptPlugin::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<DbCryptPlugin>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> DbCryptPlugin::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> DbCryptPlugin::setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<DbCryptPlugin>(info.This());
	auto* r = ReferenceCounted::CheckedUnwrap(info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> DbCryptPlugin::setOwnerFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::IReferenceCounted*> DbCryptPlugin::getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<DbCryptPlugin>(info.This());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

v8::Local<v8::Value> DbCryptPlugin::getOwnerFinish(fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(ret);
}

void ExternalContext::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
}

void ExternalResultSet::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, disposeStart, disposeFinish>(tpl, "dispose");
	DefineAsyncMethod<FB_BOOLEAN, fetchStart, fetchFinish>(tpl, "fetch");
}

MethodStart<void*> ExternalResultSet::disposeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ExternalResultSet>(info.This());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

v8::Local<v8::Value> ExternalResultSet::disposeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<FB_BOOLEAN> ExternalResultSet::fetchStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ExternalResultSet>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->fetch(&statusWrapper);
	};
}

v8::Local<v8::Value> ExternalResultSet::fetchFinish(FB_BOOLEAN ret)
{
	return Nan::New((bool) ret);
}

void ExternalFunction::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, disposeStart, disposeFinish>(tpl, "dispose");
}

MethodStart<void*> ExternalFunction::disposeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ExternalFunction>(info.This());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

v8::Local<v8::Value> ExternalFunction::disposeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void ExternalProcedure::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, disposeStart, disposeFinish>(tpl, "dispose");
}

MethodStart<void*> ExternalProcedure::disposeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ExternalProcedure>(info.This());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

v8::Local<v8::Value> ExternalProcedure::disposeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void ExternalTrigger::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, disposeStart, disposeFinish>(tpl, "dispose");
}

MethodStart<void*> ExternalTrigger::disposeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ExternalTrigger>(info.This());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

v8::Local<v8::Value> ExternalTrigger::disposeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void RoutineMetadata::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<std::string, getPackageStart, getPackageFinish>(tpl, "getPackage");
	DefineAsyncMethod<std::string, getNameStart, getNameFinish>(tpl, "getName");
	DefineAsyncMethod<std::string, getEntryPointStart, getEntryPointFinish>(tpl, "getEntryPoint");
	DefineAsyncMethod<std::string, getBodyStart, getBodyFinish>(tpl, "getBody");
	DefineAsyncMethod<fb::IMessageMetadata*, getInputMetadataStart, getInputMetadataFinish>(tpl, "getInputMetadata");
	DefineAsyncMethod<fb::IMessageMetadata*, getOutputMetadataStart, getOutputMetadataFinish>(tpl, "getOutputMetadata");
	DefineAsyncMethod<fb::IMessageMetadata*, getTriggerMetadataStart, getTriggerMetadataFinish>(tpl, "getTriggerMetadata");
	DefineAsyncMethod<std::string, getTriggerTableStart, getTriggerTableFinish>(tpl, "getTriggerTable");
	DefineAsyncMethod<unsigned, getTriggerTypeStart, getTriggerTypeFinish>(tpl, "getTriggerType");
}

MethodStart<std::string> RoutineMetadata::getPackageStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<RoutineMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getPackage(&statusWrapper);
	};
}

v8::Local<v8::Value> RoutineMetadata::getPackageFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> RoutineMetadata::getNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<RoutineMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getName(&statusWrapper);
	};
}

v8::Local<v8::Value> RoutineMetadata::getNameFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> RoutineMetadata::getEntryPointStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<RoutineMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getEntryPoint(&statusWrapper);
	};
}

v8::Local<v8::Value> RoutineMetadata::getEntryPointFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> RoutineMetadata::getBodyStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<RoutineMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getBody(&statusWrapper);
	};
}

v8::Local<v8::Value> RoutineMetadata::getBodyFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<fb::IMessageMetadata*> RoutineMetadata::getInputMetadataStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<RoutineMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getInputMetadata(&statusWrapper);
	};
}

v8::Local<v8::Value> RoutineMetadata::getInputMetadataFinish(fb::IMessageMetadata* ret)
{
	return MessageMetadata::NewInstance(ret);
}

MethodStart<fb::IMessageMetadata*> RoutineMetadata::getOutputMetadataStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<RoutineMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getOutputMetadata(&statusWrapper);
	};
}

v8::Local<v8::Value> RoutineMetadata::getOutputMetadataFinish(fb::IMessageMetadata* ret)
{
	return MessageMetadata::NewInstance(ret);
}

MethodStart<fb::IMessageMetadata*> RoutineMetadata::getTriggerMetadataStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<RoutineMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getTriggerMetadata(&statusWrapper);
	};
}

v8::Local<v8::Value> RoutineMetadata::getTriggerMetadataFinish(fb::IMessageMetadata* ret)
{
	return MessageMetadata::NewInstance(ret);
}

MethodStart<std::string> RoutineMetadata::getTriggerTableStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<RoutineMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getTriggerTable(&statusWrapper);
	};
}

v8::Local<v8::Value> RoutineMetadata::getTriggerTableFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<unsigned> RoutineMetadata::getTriggerTypeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<RoutineMetadata>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getTriggerType(&statusWrapper);
	};
}

v8::Local<v8::Value> RoutineMetadata::getTriggerTypeFinish(unsigned ret)
{
	return Nan::New(ret);
}

void ExternalEngine::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, setOwnerStart, setOwnerFinish>(tpl, "setOwner");
	DefineAsyncMethod<fb::IReferenceCounted*, getOwnerStart, getOwnerFinish>(tpl, "getOwner");
}

MethodStart<void*> ExternalEngine::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ExternalEngine>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> ExternalEngine::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> ExternalEngine::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ExternalEngine>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> ExternalEngine::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> ExternalEngine::setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ExternalEngine>(info.This());
	auto* r = ReferenceCounted::CheckedUnwrap(info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> ExternalEngine::setOwnerFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::IReferenceCounted*> ExternalEngine::getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<ExternalEngine>(info.This());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

v8::Local<v8::Value> ExternalEngine::getOwnerFinish(fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(ret);
}

void Timer::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, handlerStart, handlerFinish>(tpl, "handler");
}

MethodStart<void*> Timer::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Timer>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> Timer::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Timer::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Timer>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> Timer::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> Timer::handlerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Timer>(info.This());

	return [obj]() {
		obj->interface->handler();
		return nullptr;
	};
}

v8::Local<v8::Value> Timer::handlerFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void TimerControl::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, startStart, startFinish>(tpl, "start");
	DefineAsyncMethod<void*, stopStart, stopFinish>(tpl, "stop");
}

MethodStart<void*> TimerControl::startStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TimerControl>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* timer = Timer::CheckedUnwrap(info[1], "timer argument", true);
	uint64_t microSeconds = info[2]->NumberValue();

	return [obj, status, timer, microSeconds]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->start(&statusWrapper, (timer ? timer->interface : nullptr), microSeconds);
		return nullptr;
	};
}

v8::Local<v8::Value> TimerControl::startFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> TimerControl::stopStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TimerControl>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* timer = Timer::CheckedUnwrap(info[1], "timer argument", true);

	return [obj, status, timer]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->stop(&statusWrapper, (timer ? timer->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> TimerControl::stopFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void VersionCallback::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, callbackStart, callbackFinish>(tpl, "callback");
}

MethodStart<void*> VersionCallback::callbackStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<VersionCallback>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string text = *v8::String::Utf8Value(info[1]->ToString());

	return [obj, status, text]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->callback(&statusWrapper, text.c_str());
		return nullptr;
	};
}

v8::Local<v8::Value> VersionCallback::callbackFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void Util::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, getFbVersionStart, getFbVersionFinish>(tpl, "getFbVersion");
	DefineAsyncMethod<fb::IAttachment*, executeCreateDatabaseStart, executeCreateDatabaseFinish>(tpl, "executeCreateDatabase");
	DefineAsyncMethod<void*, decodeDateStart, decodeDateFinish>(tpl, "decodeDate");
	DefineAsyncMethod<void*, decodeTimeStart, decodeTimeFinish>(tpl, "decodeTime");
	DefineAsyncMethod<int, encodeDateStart, encodeDateFinish>(tpl, "encodeDate");
	DefineAsyncMethod<int, encodeTimeStart, encodeTimeFinish>(tpl, "encodeTime");
	DefineAsyncMethod<unsigned, getClientVersionStart, getClientVersionFinish>(tpl, "getClientVersion");
	DefineAsyncMethod<fb::IXpbBuilder*, getXpbBuilderStart, getXpbBuilderFinish>(tpl, "getXpbBuilder");
	DefineAsyncMethod<unsigned, setOffsetsStart, setOffsetsFinish>(tpl, "setOffsets");
}

MethodStart<void*> Util::getFbVersionStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Util>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* att = Attachment::CheckedUnwrap(info[1], "att argument", true);
	auto* callback = VersionCallback::CheckedUnwrap(info[2], "callback argument", true);

	return [obj, status, att, callback]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->getFbVersion(&statusWrapper, (att ? att->interface : nullptr), (callback ? callback->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> Util::getFbVersionFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::IAttachment*> Util::executeCreateDatabaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Util>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned stmtLength = info[1]->NumberValue();
	std::string creatDBstatement = *v8::String::Utf8Value(info[2]->ToString());
	unsigned dialect = info[3]->NumberValue();
	auto* stmtIsCreateDb = getAddress<unsigned char>(info[4]);

	return [obj, status, stmtLength, creatDBstatement, dialect, stmtIsCreateDb]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->executeCreateDatabase(&statusWrapper, stmtLength, creatDBstatement.c_str(), dialect, stmtIsCreateDb);
	};
}

v8::Local<v8::Value> Util::executeCreateDatabaseFinish(fb::IAttachment* ret)
{
	return Attachment::NewInstance(ret);
}

MethodStart<void*> Util::decodeDateStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Util>(info.This());
	int date = info[0]->NumberValue();
	auto* year = getAddress<unsigned>(info[1]);
	auto* month = getAddress<unsigned>(info[2]);
	auto* day = getAddress<unsigned>(info[3]);

	return [obj, date, year, month, day]() {
		obj->interface->decodeDate(date, year, month, day);
		return nullptr;
	};
}

v8::Local<v8::Value> Util::decodeDateFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> Util::decodeTimeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Util>(info.This());
	int time = info[0]->NumberValue();
	auto* hours = getAddress<unsigned>(info[1]);
	auto* minutes = getAddress<unsigned>(info[2]);
	auto* seconds = getAddress<unsigned>(info[3]);
	auto* fractions = getAddress<unsigned>(info[4]);

	return [obj, time, hours, minutes, seconds, fractions]() {
		obj->interface->decodeTime(time, hours, minutes, seconds, fractions);
		return nullptr;
	};
}

v8::Local<v8::Value> Util::decodeTimeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> Util::encodeDateStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Util>(info.This());
	unsigned year = info[0]->NumberValue();
	unsigned month = info[1]->NumberValue();
	unsigned day = info[2]->NumberValue();

	return [obj, year, month, day]() {
		return obj->interface->encodeDate(year, month, day);
	};
}

v8::Local<v8::Value> Util::encodeDateFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<int> Util::encodeTimeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Util>(info.This());
	unsigned hours = info[0]->NumberValue();
	unsigned minutes = info[1]->NumberValue();
	unsigned seconds = info[2]->NumberValue();
	unsigned fractions = info[3]->NumberValue();

	return [obj, hours, minutes, seconds, fractions]() {
		return obj->interface->encodeTime(hours, minutes, seconds, fractions);
	};
}

v8::Local<v8::Value> Util::encodeTimeFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<unsigned> Util::getClientVersionStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Util>(info.This());

	return [obj]() {
		return obj->interface->getClientVersion();
	};
}

v8::Local<v8::Value> Util::getClientVersionFinish(unsigned ret)
{
	return Nan::New(ret);
}

MethodStart<fb::IXpbBuilder*> Util::getXpbBuilderStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Util>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned kind = info[1]->NumberValue();
	auto* buf = getAddress<unsigned char>(info[2]);
	unsigned len = info[3]->NumberValue();

	return [obj, status, kind, buf, len]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getXpbBuilder(&statusWrapper, kind, buf, len);
	};
}

v8::Local<v8::Value> Util::getXpbBuilderFinish(fb::IXpbBuilder* ret)
{
	return XpbBuilder::NewInstance(ret);
}

MethodStart<unsigned> Util::setOffsetsStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<Util>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* metadata = MessageMetadata::CheckedUnwrap(info[1], "metadata argument", true);
	auto* callback = OffsetsCallback::CheckedUnwrap(info[2], "callback argument", true);

	return [obj, status, metadata, callback]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->setOffsets(&statusWrapper, (metadata ? metadata->interface : nullptr), (callback ? callback->interface : nullptr));
	};
}

v8::Local<v8::Value> Util::setOffsetsFinish(unsigned ret)
{
	return Nan::New(ret);
}

void OffsetsCallback::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, setOffsetStart, setOffsetFinish>(tpl, "setOffset");
}

MethodStart<void*> OffsetsCallback::setOffsetStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<OffsetsCallback>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned index = info[1]->NumberValue();
	unsigned offset = info[2]->NumberValue();
	unsigned nullOffset = info[3]->NumberValue();

	return [obj, status, index, offset, nullOffset]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setOffset(&statusWrapper, index, offset, nullOffset);
		return nullptr;
	};
}

v8::Local<v8::Value> OffsetsCallback::setOffsetFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

void XpbBuilder::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, disposeStart, disposeFinish>(tpl, "dispose");
	DefineAsyncMethod<void*, clearStart, clearFinish>(tpl, "clear");
	DefineAsyncMethod<void*, removeCurrentStart, removeCurrentFinish>(tpl, "removeCurrent");
	DefineAsyncMethod<void*, insertIntStart, insertIntFinish>(tpl, "insertInt");
	DefineAsyncMethod<void*, insertBigIntStart, insertBigIntFinish>(tpl, "insertBigInt");
	DefineAsyncMethod<void*, insertBytesStart, insertBytesFinish>(tpl, "insertBytes");
	DefineAsyncMethod<void*, insertStringStart, insertStringFinish>(tpl, "insertString");
	DefineAsyncMethod<void*, insertTagStart, insertTagFinish>(tpl, "insertTag");
	DefineAsyncMethod<FB_BOOLEAN, isEofStart, isEofFinish>(tpl, "isEof");
	DefineAsyncMethod<void*, moveNextStart, moveNextFinish>(tpl, "moveNext");
	DefineAsyncMethod<void*, rewindStart, rewindFinish>(tpl, "rewind");
	DefineAsyncMethod<FB_BOOLEAN, findFirstStart, findFirstFinish>(tpl, "findFirst");
	DefineAsyncMethod<FB_BOOLEAN, findNextStart, findNextFinish>(tpl, "findNext");
	DefineAsyncMethod<unsigned char, getTagStart, getTagFinish>(tpl, "getTag");
	DefineAsyncMethod<unsigned, getLengthStart, getLengthFinish>(tpl, "getLength");
	DefineAsyncMethod<int, getIntStart, getIntFinish>(tpl, "getInt");
	DefineAsyncMethod<int64_t, getBigIntStart, getBigIntFinish>(tpl, "getBigInt");
	DefineAsyncMethod<std::string, getStringStart, getStringFinish>(tpl, "getString");
	DefineAsyncMethod<const unsigned char*, getBytesStart, getBytesFinish>(tpl, "getBytes");
	DefineAsyncMethod<unsigned, getBufferLengthStart, getBufferLengthFinish>(tpl, "getBufferLength");
	DefineAsyncMethod<const unsigned char*, getBufferStart, getBufferFinish>(tpl, "getBuffer");
}

MethodStart<void*> XpbBuilder::disposeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

v8::Local<v8::Value> XpbBuilder::disposeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> XpbBuilder::clearStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->clear(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> XpbBuilder::clearFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> XpbBuilder::removeCurrentStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->removeCurrent(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> XpbBuilder::removeCurrentFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> XpbBuilder::insertIntStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned char tag = info[1]->NumberValue();
	int value = info[2]->NumberValue();

	return [obj, status, tag, value]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->insertInt(&statusWrapper, tag, value);
		return nullptr;
	};
}

v8::Local<v8::Value> XpbBuilder::insertIntFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> XpbBuilder::insertBigIntStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned char tag = info[1]->NumberValue();
	int64_t value = info[2]->NumberValue();

	return [obj, status, tag, value]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->insertBigInt(&statusWrapper, tag, value);
		return nullptr;
	};
}

v8::Local<v8::Value> XpbBuilder::insertBigIntFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> XpbBuilder::insertBytesStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned char tag = info[1]->NumberValue();
	auto* bytes = getAddress<unsigned char>(info[2]);
	unsigned length = info[3]->NumberValue();

	return [obj, status, tag, bytes, length]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->insertBytes(&statusWrapper, tag, bytes, length);
		return nullptr;
	};
}

v8::Local<v8::Value> XpbBuilder::insertBytesFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> XpbBuilder::insertStringStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned char tag = info[1]->NumberValue();
	std::string str = *v8::String::Utf8Value(info[2]->ToString());

	return [obj, status, tag, str]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->insertString(&statusWrapper, tag, str.c_str());
		return nullptr;
	};
}

v8::Local<v8::Value> XpbBuilder::insertStringFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> XpbBuilder::insertTagStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned char tag = info[1]->NumberValue();

	return [obj, status, tag]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->insertTag(&statusWrapper, tag);
		return nullptr;
	};
}

v8::Local<v8::Value> XpbBuilder::insertTagFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<FB_BOOLEAN> XpbBuilder::isEofStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->isEof(&statusWrapper);
	};
}

v8::Local<v8::Value> XpbBuilder::isEofFinish(FB_BOOLEAN ret)
{
	return Nan::New((bool) ret);
}

MethodStart<void*> XpbBuilder::moveNextStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->moveNext(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> XpbBuilder::moveNextFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> XpbBuilder::rewindStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->rewind(&statusWrapper);
		return nullptr;
	};
}

v8::Local<v8::Value> XpbBuilder::rewindFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<FB_BOOLEAN> XpbBuilder::findFirstStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	unsigned char tag = info[1]->NumberValue();

	return [obj, status, tag]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->findFirst(&statusWrapper, tag);
	};
}

v8::Local<v8::Value> XpbBuilder::findFirstFinish(FB_BOOLEAN ret)
{
	return Nan::New((bool) ret);
}

MethodStart<FB_BOOLEAN> XpbBuilder::findNextStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->findNext(&statusWrapper);
	};
}

v8::Local<v8::Value> XpbBuilder::findNextFinish(FB_BOOLEAN ret)
{
	return Nan::New((bool) ret);
}

MethodStart<unsigned char> XpbBuilder::getTagStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getTag(&statusWrapper);
	};
}

v8::Local<v8::Value> XpbBuilder::getTagFinish(unsigned char ret)
{
	return Nan::New(ret);
}

MethodStart<unsigned> XpbBuilder::getLengthStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getLength(&statusWrapper);
	};
}

v8::Local<v8::Value> XpbBuilder::getLengthFinish(unsigned ret)
{
	return Nan::New(ret);
}

MethodStart<int> XpbBuilder::getIntStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getInt(&statusWrapper);
	};
}

v8::Local<v8::Value> XpbBuilder::getIntFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<int64_t> XpbBuilder::getBigIntStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getBigInt(&statusWrapper);
	};
}

v8::Local<v8::Value> XpbBuilder::getBigIntFinish(int64_t ret)
{
	return Nan::New((double) ret);
}

MethodStart<std::string> XpbBuilder::getStringStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getString(&statusWrapper);
	};
}

v8::Local<v8::Value> XpbBuilder::getStringFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<const unsigned char*> XpbBuilder::getBytesStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getBytes(&statusWrapper);
	};
}

v8::Local<v8::Value> XpbBuilder::getBytesFinish(const unsigned char* ret)
{
	return Pointer::NewInstance(ret);
}

MethodStart<unsigned> XpbBuilder::getBufferLengthStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getBufferLength(&statusWrapper);
	};
}

v8::Local<v8::Value> XpbBuilder::getBufferLengthFinish(unsigned ret)
{
	return Nan::New(ret);
}

MethodStart<const unsigned char*> XpbBuilder::getBufferStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<XpbBuilder>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);

	return [obj, status]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->getBuffer(&statusWrapper);
	};
}

v8::Local<v8::Value> XpbBuilder::getBufferFinish(const unsigned char* ret)
{
	return Pointer::NewInstance(ret);
}

void TraceConnection::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<unsigned, getKindStart, getKindFinish>(tpl, "getKind");
	DefineAsyncMethod<int, getProcessIDStart, getProcessIDFinish>(tpl, "getProcessID");
	DefineAsyncMethod<std::string, getUserNameStart, getUserNameFinish>(tpl, "getUserName");
	DefineAsyncMethod<std::string, getRoleNameStart, getRoleNameFinish>(tpl, "getRoleName");
	DefineAsyncMethod<std::string, getCharSetStart, getCharSetFinish>(tpl, "getCharSet");
	DefineAsyncMethod<std::string, getRemoteProtocolStart, getRemoteProtocolFinish>(tpl, "getRemoteProtocol");
	DefineAsyncMethod<std::string, getRemoteAddressStart, getRemoteAddressFinish>(tpl, "getRemoteAddress");
	DefineAsyncMethod<int, getRemoteProcessIDStart, getRemoteProcessIDFinish>(tpl, "getRemoteProcessID");
	DefineAsyncMethod<std::string, getRemoteProcessNameStart, getRemoteProcessNameFinish>(tpl, "getRemoteProcessName");
}

MethodStart<unsigned> TraceConnection::getKindStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceConnection>(info.This());

	return [obj]() {
		return obj->interface->getKind();
	};
}

v8::Local<v8::Value> TraceConnection::getKindFinish(unsigned ret)
{
	return Nan::New(ret);
}

MethodStart<int> TraceConnection::getProcessIDStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceConnection>(info.This());

	return [obj]() {
		return obj->interface->getProcessID();
	};
}

v8::Local<v8::Value> TraceConnection::getProcessIDFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<std::string> TraceConnection::getUserNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceConnection>(info.This());

	return [obj]() {
		return obj->interface->getUserName();
	};
}

v8::Local<v8::Value> TraceConnection::getUserNameFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> TraceConnection::getRoleNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceConnection>(info.This());

	return [obj]() {
		return obj->interface->getRoleName();
	};
}

v8::Local<v8::Value> TraceConnection::getRoleNameFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> TraceConnection::getCharSetStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceConnection>(info.This());

	return [obj]() {
		return obj->interface->getCharSet();
	};
}

v8::Local<v8::Value> TraceConnection::getCharSetFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> TraceConnection::getRemoteProtocolStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceConnection>(info.This());

	return [obj]() {
		return obj->interface->getRemoteProtocol();
	};
}

v8::Local<v8::Value> TraceConnection::getRemoteProtocolFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> TraceConnection::getRemoteAddressStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceConnection>(info.This());

	return [obj]() {
		return obj->interface->getRemoteAddress();
	};
}

v8::Local<v8::Value> TraceConnection::getRemoteAddressFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<int> TraceConnection::getRemoteProcessIDStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceConnection>(info.This());

	return [obj]() {
		return obj->interface->getRemoteProcessID();
	};
}

v8::Local<v8::Value> TraceConnection::getRemoteProcessIDFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<std::string> TraceConnection::getRemoteProcessNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceConnection>(info.This());

	return [obj]() {
		return obj->interface->getRemoteProcessName();
	};
}

v8::Local<v8::Value> TraceConnection::getRemoteProcessNameFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

void TraceDatabaseConnection::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<unsigned, getKindStart, getKindFinish>(tpl, "getKind");
	DefineAsyncMethod<int, getProcessIDStart, getProcessIDFinish>(tpl, "getProcessID");
	DefineAsyncMethod<std::string, getUserNameStart, getUserNameFinish>(tpl, "getUserName");
	DefineAsyncMethod<std::string, getRoleNameStart, getRoleNameFinish>(tpl, "getRoleName");
	DefineAsyncMethod<std::string, getCharSetStart, getCharSetFinish>(tpl, "getCharSet");
	DefineAsyncMethod<std::string, getRemoteProtocolStart, getRemoteProtocolFinish>(tpl, "getRemoteProtocol");
	DefineAsyncMethod<std::string, getRemoteAddressStart, getRemoteAddressFinish>(tpl, "getRemoteAddress");
	DefineAsyncMethod<int, getRemoteProcessIDStart, getRemoteProcessIDFinish>(tpl, "getRemoteProcessID");
	DefineAsyncMethod<std::string, getRemoteProcessNameStart, getRemoteProcessNameFinish>(tpl, "getRemoteProcessName");
	DefineAsyncMethod<int64_t, getConnectionIDStart, getConnectionIDFinish>(tpl, "getConnectionID");
	DefineAsyncMethod<std::string, getDatabaseNameStart, getDatabaseNameFinish>(tpl, "getDatabaseName");
}

MethodStart<unsigned> TraceDatabaseConnection::getKindStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceDatabaseConnection>(info.This());

	return [obj]() {
		return obj->interface->getKind();
	};
}

v8::Local<v8::Value> TraceDatabaseConnection::getKindFinish(unsigned ret)
{
	return Nan::New(ret);
}

MethodStart<int> TraceDatabaseConnection::getProcessIDStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceDatabaseConnection>(info.This());

	return [obj]() {
		return obj->interface->getProcessID();
	};
}

v8::Local<v8::Value> TraceDatabaseConnection::getProcessIDFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<std::string> TraceDatabaseConnection::getUserNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceDatabaseConnection>(info.This());

	return [obj]() {
		return obj->interface->getUserName();
	};
}

v8::Local<v8::Value> TraceDatabaseConnection::getUserNameFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> TraceDatabaseConnection::getRoleNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceDatabaseConnection>(info.This());

	return [obj]() {
		return obj->interface->getRoleName();
	};
}

v8::Local<v8::Value> TraceDatabaseConnection::getRoleNameFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> TraceDatabaseConnection::getCharSetStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceDatabaseConnection>(info.This());

	return [obj]() {
		return obj->interface->getCharSet();
	};
}

v8::Local<v8::Value> TraceDatabaseConnection::getCharSetFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> TraceDatabaseConnection::getRemoteProtocolStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceDatabaseConnection>(info.This());

	return [obj]() {
		return obj->interface->getRemoteProtocol();
	};
}

v8::Local<v8::Value> TraceDatabaseConnection::getRemoteProtocolFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> TraceDatabaseConnection::getRemoteAddressStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceDatabaseConnection>(info.This());

	return [obj]() {
		return obj->interface->getRemoteAddress();
	};
}

v8::Local<v8::Value> TraceDatabaseConnection::getRemoteAddressFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<int> TraceDatabaseConnection::getRemoteProcessIDStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceDatabaseConnection>(info.This());

	return [obj]() {
		return obj->interface->getRemoteProcessID();
	};
}

v8::Local<v8::Value> TraceDatabaseConnection::getRemoteProcessIDFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<std::string> TraceDatabaseConnection::getRemoteProcessNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceDatabaseConnection>(info.This());

	return [obj]() {
		return obj->interface->getRemoteProcessName();
	};
}

v8::Local<v8::Value> TraceDatabaseConnection::getRemoteProcessNameFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<int64_t> TraceDatabaseConnection::getConnectionIDStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceDatabaseConnection>(info.This());

	return [obj]() {
		return obj->interface->getConnectionID();
	};
}

v8::Local<v8::Value> TraceDatabaseConnection::getConnectionIDFinish(int64_t ret)
{
	return Nan::New((double) ret);
}

MethodStart<std::string> TraceDatabaseConnection::getDatabaseNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceDatabaseConnection>(info.This());

	return [obj]() {
		return obj->interface->getDatabaseName();
	};
}

v8::Local<v8::Value> TraceDatabaseConnection::getDatabaseNameFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

void TraceTransaction::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
}

void TraceParams::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
}

void TraceStatement::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
}

void TraceSQLStatement::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
}

void TraceBLRStatement::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
}

void TraceDYNRequest::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
}

void TraceContextVariable::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
}

void TraceProcedure::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
}

void TraceFunction::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
}

void TraceTrigger::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
}

void TraceServiceConnection::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<unsigned, getKindStart, getKindFinish>(tpl, "getKind");
	DefineAsyncMethod<int, getProcessIDStart, getProcessIDFinish>(tpl, "getProcessID");
	DefineAsyncMethod<std::string, getUserNameStart, getUserNameFinish>(tpl, "getUserName");
	DefineAsyncMethod<std::string, getRoleNameStart, getRoleNameFinish>(tpl, "getRoleName");
	DefineAsyncMethod<std::string, getCharSetStart, getCharSetFinish>(tpl, "getCharSet");
	DefineAsyncMethod<std::string, getRemoteProtocolStart, getRemoteProtocolFinish>(tpl, "getRemoteProtocol");
	DefineAsyncMethod<std::string, getRemoteAddressStart, getRemoteAddressFinish>(tpl, "getRemoteAddress");
	DefineAsyncMethod<int, getRemoteProcessIDStart, getRemoteProcessIDFinish>(tpl, "getRemoteProcessID");
	DefineAsyncMethod<std::string, getRemoteProcessNameStart, getRemoteProcessNameFinish>(tpl, "getRemoteProcessName");
}

MethodStart<unsigned> TraceServiceConnection::getKindStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceServiceConnection>(info.This());

	return [obj]() {
		return obj->interface->getKind();
	};
}

v8::Local<v8::Value> TraceServiceConnection::getKindFinish(unsigned ret)
{
	return Nan::New(ret);
}

MethodStart<int> TraceServiceConnection::getProcessIDStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceServiceConnection>(info.This());

	return [obj]() {
		return obj->interface->getProcessID();
	};
}

v8::Local<v8::Value> TraceServiceConnection::getProcessIDFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<std::string> TraceServiceConnection::getUserNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceServiceConnection>(info.This());

	return [obj]() {
		return obj->interface->getUserName();
	};
}

v8::Local<v8::Value> TraceServiceConnection::getUserNameFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> TraceServiceConnection::getRoleNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceServiceConnection>(info.This());

	return [obj]() {
		return obj->interface->getRoleName();
	};
}

v8::Local<v8::Value> TraceServiceConnection::getRoleNameFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> TraceServiceConnection::getCharSetStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceServiceConnection>(info.This());

	return [obj]() {
		return obj->interface->getCharSet();
	};
}

v8::Local<v8::Value> TraceServiceConnection::getCharSetFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> TraceServiceConnection::getRemoteProtocolStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceServiceConnection>(info.This());

	return [obj]() {
		return obj->interface->getRemoteProtocol();
	};
}

v8::Local<v8::Value> TraceServiceConnection::getRemoteProtocolFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<std::string> TraceServiceConnection::getRemoteAddressStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceServiceConnection>(info.This());

	return [obj]() {
		return obj->interface->getRemoteAddress();
	};
}

v8::Local<v8::Value> TraceServiceConnection::getRemoteAddressFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

MethodStart<int> TraceServiceConnection::getRemoteProcessIDStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceServiceConnection>(info.This());

	return [obj]() {
		return obj->interface->getRemoteProcessID();
	};
}

v8::Local<v8::Value> TraceServiceConnection::getRemoteProcessIDFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<std::string> TraceServiceConnection::getRemoteProcessNameStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceServiceConnection>(info.This());

	return [obj]() {
		return obj->interface->getRemoteProcessName();
	};
}

v8::Local<v8::Value> TraceServiceConnection::getRemoteProcessNameFinish(std::string ret)
{
	return Nan::New(ret).ToLocalChecked();
}

void TraceStatusVector::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
}

void TraceSweepInfo::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
}

void TraceLogWriter::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
}

MethodStart<void*> TraceLogWriter::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceLogWriter>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> TraceLogWriter::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> TraceLogWriter::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceLogWriter>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> TraceLogWriter::releaseFinish(int ret)
{
	return Nan::New(ret);
}

void TraceInitInfo::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
}

void TracePlugin::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
}

MethodStart<void*> TracePlugin::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TracePlugin>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> TracePlugin::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> TracePlugin::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TracePlugin>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> TracePlugin::releaseFinish(int ret)
{
	return Nan::New(ret);
}

void TraceFactory::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, addRefStart, addRefFinish>(tpl, "addRef");
	DefineAsyncMethod<int, releaseStart, releaseFinish>(tpl, "release");
	DefineAsyncMethod<void*, setOwnerStart, setOwnerFinish>(tpl, "setOwner");
	DefineAsyncMethod<fb::IReferenceCounted*, getOwnerStart, getOwnerFinish>(tpl, "getOwner");
}

MethodStart<void*> TraceFactory::addRefStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceFactory>(info.This());

	return [obj]() {
		obj->interface->addRef();
		return nullptr;
	};
}

v8::Local<v8::Value> TraceFactory::addRefFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<int> TraceFactory::releaseStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceFactory>(info.This());

	return [obj]() {
		return obj->interface->release();
	};
}

v8::Local<v8::Value> TraceFactory::releaseFinish(int ret)
{
	return Nan::New(ret);
}

MethodStart<void*> TraceFactory::setOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceFactory>(info.This());
	auto* r = ReferenceCounted::CheckedUnwrap(info[0], "r argument", true);

	return [obj, r]() {
		obj->interface->setOwner((r ? r->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> TraceFactory::setOwnerFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::IReferenceCounted*> TraceFactory::getOwnerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<TraceFactory>(info.This());

	return [obj]() {
		return obj->interface->getOwner();
	};
}

v8::Local<v8::Value> TraceFactory::getOwnerFinish(fb::IReferenceCounted* ret)
{
	return ReferenceCounted::NewInstance(ret);
}

void UdrFunctionFactory::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, disposeStart, disposeFinish>(tpl, "dispose");
	DefineAsyncMethod<void*, setupStart, setupFinish>(tpl, "setup");
	DefineAsyncMethod<fb::IExternalFunction*, newItemStart, newItemFinish>(tpl, "newItem");
}

MethodStart<void*> UdrFunctionFactory::disposeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<UdrFunctionFactory>(info.This());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

v8::Local<v8::Value> UdrFunctionFactory::disposeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> UdrFunctionFactory::setupStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<UdrFunctionFactory>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* context = ExternalContext::CheckedUnwrap(info[1], "context argument", true);
	auto* metadata = RoutineMetadata::CheckedUnwrap(info[2], "metadata argument", true);
	auto* inBuilder = MetadataBuilder::CheckedUnwrap(info[3], "inBuilder argument", true);
	auto* outBuilder = MetadataBuilder::CheckedUnwrap(info[4], "outBuilder argument", true);

	return [obj, status, context, metadata, inBuilder, outBuilder]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setup(&statusWrapper, (context ? context->interface : nullptr), (metadata ? metadata->interface : nullptr), (inBuilder ? inBuilder->interface : nullptr), (outBuilder ? outBuilder->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> UdrFunctionFactory::setupFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::IExternalFunction*> UdrFunctionFactory::newItemStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<UdrFunctionFactory>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* context = ExternalContext::CheckedUnwrap(info[1], "context argument", true);
	auto* metadata = RoutineMetadata::CheckedUnwrap(info[2], "metadata argument", true);

	return [obj, status, context, metadata]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->newItem(&statusWrapper, (context ? context->interface : nullptr), (metadata ? metadata->interface : nullptr));
	};
}

v8::Local<v8::Value> UdrFunctionFactory::newItemFinish(fb::IExternalFunction* ret)
{
	return ExternalFunction::NewInstance(ret);
}

void UdrProcedureFactory::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, disposeStart, disposeFinish>(tpl, "dispose");
	DefineAsyncMethod<void*, setupStart, setupFinish>(tpl, "setup");
	DefineAsyncMethod<fb::IExternalProcedure*, newItemStart, newItemFinish>(tpl, "newItem");
}

MethodStart<void*> UdrProcedureFactory::disposeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<UdrProcedureFactory>(info.This());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

v8::Local<v8::Value> UdrProcedureFactory::disposeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> UdrProcedureFactory::setupStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<UdrProcedureFactory>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* context = ExternalContext::CheckedUnwrap(info[1], "context argument", true);
	auto* metadata = RoutineMetadata::CheckedUnwrap(info[2], "metadata argument", true);
	auto* inBuilder = MetadataBuilder::CheckedUnwrap(info[3], "inBuilder argument", true);
	auto* outBuilder = MetadataBuilder::CheckedUnwrap(info[4], "outBuilder argument", true);

	return [obj, status, context, metadata, inBuilder, outBuilder]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setup(&statusWrapper, (context ? context->interface : nullptr), (metadata ? metadata->interface : nullptr), (inBuilder ? inBuilder->interface : nullptr), (outBuilder ? outBuilder->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> UdrProcedureFactory::setupFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::IExternalProcedure*> UdrProcedureFactory::newItemStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<UdrProcedureFactory>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* context = ExternalContext::CheckedUnwrap(info[1], "context argument", true);
	auto* metadata = RoutineMetadata::CheckedUnwrap(info[2], "metadata argument", true);

	return [obj, status, context, metadata]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->newItem(&statusWrapper, (context ? context->interface : nullptr), (metadata ? metadata->interface : nullptr));
	};
}

v8::Local<v8::Value> UdrProcedureFactory::newItemFinish(fb::IExternalProcedure* ret)
{
	return ExternalProcedure::NewInstance(ret);
}

void UdrTriggerFactory::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<void*, disposeStart, disposeFinish>(tpl, "dispose");
	DefineAsyncMethod<void*, setupStart, setupFinish>(tpl, "setup");
	DefineAsyncMethod<fb::IExternalTrigger*, newItemStart, newItemFinish>(tpl, "newItem");
}

MethodStart<void*> UdrTriggerFactory::disposeStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<UdrTriggerFactory>(info.This());

	return [obj]() {
		obj->interface->dispose();
		return nullptr;
	};
}

v8::Local<v8::Value> UdrTriggerFactory::disposeFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> UdrTriggerFactory::setupStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<UdrTriggerFactory>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* context = ExternalContext::CheckedUnwrap(info[1], "context argument", true);
	auto* metadata = RoutineMetadata::CheckedUnwrap(info[2], "metadata argument", true);
	auto* fieldsBuilder = MetadataBuilder::CheckedUnwrap(info[3], "fieldsBuilder argument", true);

	return [obj, status, context, metadata, fieldsBuilder]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->setup(&statusWrapper, (context ? context->interface : nullptr), (metadata ? metadata->interface : nullptr), (fieldsBuilder ? fieldsBuilder->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> UdrTriggerFactory::setupFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<fb::IExternalTrigger*> UdrTriggerFactory::newItemStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<UdrTriggerFactory>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	auto* context = ExternalContext::CheckedUnwrap(info[1], "context argument", true);
	auto* metadata = RoutineMetadata::CheckedUnwrap(info[2], "metadata argument", true);

	return [obj, status, context, metadata]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		return obj->interface->newItem(&statusWrapper, (context ? context->interface : nullptr), (metadata ? metadata->interface : nullptr));
	};
}

v8::Local<v8::Value> UdrTriggerFactory::newItemFinish(fb::IExternalTrigger* ret)
{
	return ExternalTrigger::NewInstance(ret);
}

void UdrPlugin::InitPrototype(v8::Local<v8::FunctionTemplate>& tpl)
{
	DefineAsyncMethod<fb::IMaster*, getMasterStart, getMasterFinish>(tpl, "getMaster");
	DefineAsyncMethod<void*, registerFunctionStart, registerFunctionFinish>(tpl, "registerFunction");
	DefineAsyncMethod<void*, registerProcedureStart, registerProcedureFinish>(tpl, "registerProcedure");
	DefineAsyncMethod<void*, registerTriggerStart, registerTriggerFinish>(tpl, "registerTrigger");
}

MethodStart<fb::IMaster*> UdrPlugin::getMasterStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<UdrPlugin>(info.This());

	return [obj]() {
		return obj->interface->getMaster();
	};
}

v8::Local<v8::Value> UdrPlugin::getMasterFinish(fb::IMaster* ret)
{
	return Master::NewInstance(ret);
}

MethodStart<void*> UdrPlugin::registerFunctionStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<UdrPlugin>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string name = *v8::String::Utf8Value(info[1]->ToString());
	auto* factory = UdrFunctionFactory::CheckedUnwrap(info[2], "factory argument", true);

	return [obj, status, name, factory]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->registerFunction(&statusWrapper, name.c_str(), (factory ? factory->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> UdrPlugin::registerFunctionFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> UdrPlugin::registerProcedureStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<UdrPlugin>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string name = *v8::String::Utf8Value(info[1]->ToString());
	auto* factory = UdrProcedureFactory::CheckedUnwrap(info[2], "factory argument", true);

	return [obj, status, name, factory]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->registerProcedure(&statusWrapper, name.c_str(), (factory ? factory->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> UdrPlugin::registerProcedureFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

MethodStart<void*> UdrPlugin::registerTriggerStart(Nan::NAN_METHOD_ARGS_TYPE info)
{
	auto* obj = ObjectWrap::Unwrap<UdrPlugin>(info.This());
	auto* status = Status::CheckedUnwrap(info[0], "status argument", true);
	std::string name = *v8::String::Utf8Value(info[1]->ToString());
	auto* factory = UdrTriggerFactory::CheckedUnwrap(info[2], "factory argument", true);

	return [obj, status, name, factory]() {
		fb::ThrowStatusWrapper statusWrapper(status->interface);
		obj->interface->registerTrigger(&statusWrapper, name.c_str(), (factory ? factory->interface : nullptr));
		return nullptr;
	};
}

v8::Local<v8::Value> UdrPlugin::registerTriggerFinish(void* ret)
{
	return v8::Local<v8::Value>(Nan::Undefined());
}

static void initClasses(v8::Local<v8::Object> exports, v8::Local<v8::Object> module)
{
	Nan::HandleScope scope;

	Versioned::Init(exports, "Versioned");
	ReferenceCounted::Init(exports, "ReferenceCounted");
	Disposable::Init(exports, "Disposable");
	Status::Init(exports, "Status");
	Master::Init(exports, "Master");
	PluginBase::Init(exports, "PluginBase");
	PluginSet::Init(exports, "PluginSet");
	ConfigEntry::Init(exports, "ConfigEntry");
	Config::Init(exports, "Config");
	FirebirdConf::Init(exports, "FirebirdConf");
	PluginConfig::Init(exports, "PluginConfig");
	PluginFactory::Init(exports, "PluginFactory");
	PluginModule::Init(exports, "PluginModule");
	PluginManager::Init(exports, "PluginManager");
	CryptKey::Init(exports, "CryptKey");
	ConfigManager::Init(exports, "ConfigManager");
	EventCallback::Init(exports, "EventCallback");
	Blob::Init(exports, "Blob");
	Transaction::Init(exports, "Transaction");
	MessageMetadata::Init(exports, "MessageMetadata");
	MetadataBuilder::Init(exports, "MetadataBuilder");
	ResultSet::Init(exports, "ResultSet");
	Statement::Init(exports, "Statement");
	Request::Init(exports, "Request");
	Events::Init(exports, "Events");
	Attachment::Init(exports, "Attachment");
	Service::Init(exports, "Service");
	Provider::Init(exports, "Provider");
	DtcStart::Init(exports, "DtcStart");
	Dtc::Init(exports, "Dtc");
	Auth::Init(exports, "Auth");
	Writer::Init(exports, "Writer");
	ServerBlock::Init(exports, "ServerBlock");
	ClientBlock::Init(exports, "ClientBlock");
	Server::Init(exports, "Server");
	Client::Init(exports, "Client");
	UserField::Init(exports, "UserField");
	CharUserField::Init(exports, "CharUserField");
	IntUserField::Init(exports, "IntUserField");
	User::Init(exports, "User");
	ListUsers::Init(exports, "ListUsers");
	LogonInfo::Init(exports, "LogonInfo");
	Management::Init(exports, "Management");
	WireCryptPlugin::Init(exports, "WireCryptPlugin");
	CryptKeyCallback::Init(exports, "CryptKeyCallback");
	KeyHolderPlugin::Init(exports, "KeyHolderPlugin");
	DbCryptPlugin::Init(exports, "DbCryptPlugin");
	ExternalContext::Init(exports, "ExternalContext");
	ExternalResultSet::Init(exports, "ExternalResultSet");
	ExternalFunction::Init(exports, "ExternalFunction");
	ExternalProcedure::Init(exports, "ExternalProcedure");
	ExternalTrigger::Init(exports, "ExternalTrigger");
	RoutineMetadata::Init(exports, "RoutineMetadata");
	ExternalEngine::Init(exports, "ExternalEngine");
	Timer::Init(exports, "Timer");
	TimerControl::Init(exports, "TimerControl");
	VersionCallback::Init(exports, "VersionCallback");
	Util::Init(exports, "Util");
	OffsetsCallback::Init(exports, "OffsetsCallback");
	XpbBuilder::Init(exports, "XpbBuilder");
	TraceConnection::Init(exports, "TraceConnection");
	TraceDatabaseConnection::Init(exports, "TraceDatabaseConnection");
	TraceTransaction::Init(exports, "TraceTransaction");
	TraceParams::Init(exports, "TraceParams");
	TraceStatement::Init(exports, "TraceStatement");
	TraceSQLStatement::Init(exports, "TraceSQLStatement");
	TraceBLRStatement::Init(exports, "TraceBLRStatement");
	TraceDYNRequest::Init(exports, "TraceDYNRequest");
	TraceContextVariable::Init(exports, "TraceContextVariable");
	TraceProcedure::Init(exports, "TraceProcedure");
	TraceFunction::Init(exports, "TraceFunction");
	TraceTrigger::Init(exports, "TraceTrigger");
	TraceServiceConnection::Init(exports, "TraceServiceConnection");
	TraceStatusVector::Init(exports, "TraceStatusVector");
	TraceSweepInfo::Init(exports, "TraceSweepInfo");
	TraceLogWriter::Init(exports, "TraceLogWriter");
	TraceInitInfo::Init(exports, "TraceInitInfo");
	TracePlugin::Init(exports, "TracePlugin");
	TraceFactory::Init(exports, "TraceFactory");
	UdrFunctionFactory::Init(exports, "UdrFunctionFactory");
	UdrProcedureFactory::Init(exports, "UdrProcedureFactory");
	UdrTriggerFactory::Init(exports, "UdrTriggerFactory");
	UdrPlugin::Init(exports, "UdrPlugin");
}
