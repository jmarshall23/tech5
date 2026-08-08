#pragma once

// Recovered AMQP 0-8 surface used by tungsten's telemetry clients.  The wire
// protocol remains AMQP compatible; only the old Xbox socket/thread plumbing
// is replaced by the portable idTCP and Win32 primitives already in idLib.
#include "idlib/precompiled.h"
#include "idlib/sys/sys_networking.h"

#ifdef nullptr
#undef nullptr
#endif
#ifdef _stricmp
#undef _stricmp
#endif

#include <cstdint>
#include <cstring>
#include <new>

template<class T>
class idMQList {
public:
    explicit idMQList(int initialGranularity = 16)
        : list(nullptr), num(0), size(0),
          granularity(static_cast<short>(initialGranularity)), memTag(5),
          listStatic(0) {}
    idMQList(const idMQList& other) : idMQList(other.granularity) {
        *this = other;
    }
    ~idMQList() { delete[] list; }
    idMQList& operator=(const idMQList& other) {
        if (this == &other) return *this;
        SetNum(other.num);
        for (int index = 0; index < num; ++index) list[index] = other[index];
        return *this;
    }
    void Clear() { num = 0; }
    int Num() const { return num; }
    T* Ptr() { return list; }
    const T* Ptr() const { return list; }
    T& operator[](int index) { return list[index]; }
    const T& operator[](int index) const { return list[index]; }
    void SetNum(int newNum) {
        if (newNum > size) Resize(newNum);
        if (newNum >= 0 && newNum <= size) num = newNum;
    }
    int Append(const T& value) {
        if (num == size && !Resize(num + 1)) return -1;
        list[num] = value;
        return num++;
    }
    bool RemoveIndex(int index) {
        if (index < 0 || index >= num) return false;
        for (int i = index; i + 1 < num; ++i) list[i] = list[i + 1];
        --num;
        return true;
    }
private:
    bool Resize(int required) {
        const int step = granularity > 0 ? granularity : 16;
        const int newSize = ((required + step - 1) / step) * step;
        T* replacement = new (std::nothrow) T[newSize];
        if (replacement == nullptr) return false;
        for (int index = 0; index < num; ++index) replacement[index] = list[index];
        delete[] list;
        list = replacement;
        size = newSize;
        return true;
    }
    T* list;
    int num;
    int size;
    short granularity;
    unsigned char memTag;
    unsigned char listStatic;
};

class idMQKeyValue {
public:
    idMQKeyValue() : key(), value() {}
    idMQKeyValue(const char* keyText, const char* valueText)
        : key(keyText), value(valueText) {}
    const idStr& GetKey() const { return key; }
    const idStr& GetValue() const { return value; }
    idStr key;
    idStr value;
};

class idMQTable {
public:
    idMQTable() : args(), hash{} {}
    void Clear() { args.Clear(); }
    int GetNumKeyVals() const { return args.Num(); }
    const idMQKeyValue* GetKeyVal(int index) const {
        return index >= 0 && index < args.Num() ? &args[index] : nullptr;
    }
    void Set(const char* key, const char* value) {
        const char* safeKey = key == nullptr ? "" : key;
        for (int index = 0; index < args.Num(); ++index) {
            if (_stricmp(args[index].key.c_str(), safeKey) == 0) {
                args[index].value = value == nullptr ? "" : value;
                return;
            }
        }
        args.Append(idMQKeyValue(safeKey, value == nullptr ? "" : value));
    }
    const char* GetString(const char* key, const char* defaultValue = "") const {
        const char* safeKey = key == nullptr ? "" : key;
        for (int index = 0; index < args.Num(); ++index) {
            if (_stricmp(args[index].key.c_str(), safeKey) == 0) {
                return args[index].value.c_str();
            }
        }
        return defaultValue;
    }
private:
    idMQList<idMQKeyValue> args;
    std::uint32_t hash[8];
};

enum MQErrors_t {
    MQERROR_NONE = 0,
    MQERROR_UNKNOWN,
    MQERROR_INVALID_FRAME,
    MQERROR_FRAME_OVERFLOW,
    MQERROR_SESSION_NOT_FOUND,
    MQERROR_STREAM_ERROR,
    MQERROR_CONNECTION_START,
    MQERROR_BAD_SPEC_VERSION,
    MQERROR_AUTH_FAILED,
    MQERROR_UNEXPECTED_CLASS,
    MQERROR_UNEXPECTED_METHOD,
    MQERROR_SERVER_CLOSED
};

enum MQAssemblerState_t {
    MQ_CMDSTATE_NEED_METHOD = 0,
    MQ_CMDSTATE_NEED_HEADER,
    MQ_CMDSTATE_NEED_BODY,
    MQ_CMDSTATE_COMPLETE
};

enum amqpClassId_t {
    AMQP_CLASS_CONNECTION = 10,
    AMQP_CLASS_CHANNEL = 20,
    AMQP_CLASS_ACCESS = 30,
    AMQP_CLASS_EXCHANGE = 40,
    AMQP_CLASS_QUEUE = 50,
    AMQP_CLASS_BASIC = 60
};

enum amqpFrameType_t {
    AMQP_FRAME_METHOD = 1,
    AMQP_FRAME_HEADER = 2,
    AMQP_FRAME_BODY = 3,
    AMQP_FRAME_HEARTBEAT = 8,
    AMQP_FRAME_END = 0xCE
};

struct amqpEndpoint_t {
    amqpEndpoint_t();

    idStr host;
    unsigned short port;
    idStr username;
    idStr password;
    idStr vhost;
    unsigned short channelMax;
    unsigned short frameMax;
    unsigned short heartbeat;
    bool nonBlocking;
    bool silent;
    int minorVersion;
    int majorVersion;
};

struct amqpShutdownReason_t {
    amqpShutdownReason_t()
        : replyCode(0), cId(0), mId(0), error(MQERROR_NONE), replyText("") {}
    unsigned short replyCode;
    unsigned short cId;
    unsigned short mId;
    MQErrors_t error;
    const char* replyText;
};

class idMQFrame;

class idMQMethod {
public:
    virtual ~idMQMethod() = default;
    virtual int GetClassId() const = 0;
    virtual int GetMethodId() const = 0;
    virtual bool HasContent() const { return false; }
    virtual bool IsAsync() const { return false; }
    virtual void Populate(idMQFrame& frame) = 0;
    virtual void ToFrame(idMQFrame& frame) = 0;
};

class idMQFrame {
public:
    idMQFrame();
    idMQFrame(unsigned char frameType, unsigned short channelNumber);

    void Clear();
    void ReadData(void* destination, int length);
    void WriteData(const void* source, int length);
    unsigned char ReadByte();
    unsigned short ReadUInt16();
    unsigned int ReadUInt32();
    std::uint64_t ReadUInt64();
    bool ReadBool();
    idStr ReadShortString();
    void ReadString(idMQList<unsigned char>& value);
    void ReadTable(idMQTable& value);
    bool ReadPropertyPresence();
    void FinalizeReadPresence();

    void WriteByte(unsigned char value);
    void WriteUInt16(unsigned short value);
    void WriteUInt32(unsigned int value);
    void WriteUInt64(std::uint64_t value);
    void WriteBool(bool value);
    void WriteShortString(const idStr& value);
    void WriteString(const idMQList<unsigned char>& value);
    void WriteTable(const idMQTable& value);
    void WritePropertyPresence(bool present);
    void FinalizeWritePresence();
    void FlushWriteBitBuffer();
    void FinalizeFrame();

    int ReadFromStream(class idMQTCP& stream);
    int WriteToStream(class idMQTCP& stream);

    unsigned char type;
    unsigned short channel;
    idMQList<unsigned char> data;
    int readPos;
    bool locked;
    bool resetReadBitBuffer;
    unsigned char readBitBuffer;
    unsigned int readBitMask;
    bool flushWriteBitBuffer;
    unsigned char writeBitBuffer;
    unsigned int writeBitMask;
    unsigned short readPresenceBuffer;
    unsigned short readPresencePosition;
    unsigned short writePresenceBuffer;
    unsigned short writePresencePosition;
};

class idMQTCP {
public:
    idMQTCP();
    ~idMQTCP();
    bool Connect(const char* host, unsigned short port, bool nonBlocking,
        bool silent);
    void Close();
    bool IsOpen() const;
    int Read(void* data, int size, bool blocking = true,
        int timeoutMS = 5000);
    int Write(const void* data, int size, bool blocking = true,
        int timeoutMS = 5000);
    int ReadByte(unsigned char& value, bool blocking = true,
        int timeoutMS = 5000);
    int ReadUInt16(unsigned short& value, bool blocking = true,
        int timeoutMS = 5000);
    int ReadUInt32(unsigned int& value, bool blocking = true,
        int timeoutMS = 5000);

    idTCP tcp;
};

class idMQContentHeader {
public:
    idMQContentHeader() : bodyLength(0) {}
    virtual ~idMQContentHeader() = default;
    virtual int GetProtocolId() const = 0;
    virtual void Populate(idMQFrame& frame) = 0;
    virtual void ToFrame(idMQFrame& frame) = 0;

    std::uint64_t bodyLength;
};

class idMQBuffer {
public:
    idMQBuffer();
    void Clear();
    void WriteData(const void* data, int size);
    void WriteUInt16(unsigned short value, bool bigEndian = true);
    void WriteUInt32(unsigned int value, bool bigEndian = true);

    idMQList<unsigned char> body;
    int readPos;
};

class idMQFrameHandler {
public:
    explicit idMQFrameHandler(const amqpEndpoint_t& endpointValue);
    ~idMQFrameHandler();
    bool Connect();
    void Close();
    int SendFrame(idMQFrame& frame);
    int ReadFrame(idMQFrame& frame);
    bool SendHeader();

    amqpEndpoint_t endpoint;
    idSysMutex readLock;
    idSysMutex writeLock;
    idMQTCP tcp;
};

template<class T>
class idDeferredResult {
public:
    idDeferredResult() : value(), filled(false), signal(false) {}

    void SetValue(const T& newValue) {
        value = newValue;
        filled = true;
        signal.Raise();
    }
    bool GetValue(T& result) {
        if (!signal.Wait(5000) || !filled) return false;
        result = value;
        filled = false;
        return true;
    }
    bool GetValue() {
        if (!signal.Wait(5000) || !filled) return false;
        filled = false;
        return true;
    }
    void Clear() {
        filled = false;
        signal.Clear();
    }

    T value;
    bool filled;
    idSysSignal signal;
};

class idMQCommand {
public:
    idMQCommand();
    ~idMQCommand();
    void Reset();

    idMQMethod* method;
    idMQContentHeader* contentHeader;
    bool complete;
    idMQList<unsigned char> contentBody;
    std::uint64_t remainingBodyBytes;
};

class idMQCommandBuilder {
public:
    idMQCommandBuilder();
    MQErrors_t HandleFrame(idMQCommand& command, idMQFrame& frame);

    MQAssemblerState_t state;
    std::uint64_t remainingBytes;
};

class idMQChannel;
class idMQSessionManager;

class idMQConnection {
public:
    idMQConnection();
    ~idMQConnection();
    void Init(amqpEndpoint_t& endpoint);
    bool Connect();
    void Close();
    void Close(const char* reason, MQErrors_t error);
    void Close(amqpShutdownReason_t& reason);
    void SendFrame(idMQFrame& frame);
    idMQChannel* GetChannel();

    unsigned int frameMaxSize;
    idMQList<idStr> knownHosts;
    idMQFrameHandler* framer;
    idMQSessionManager* sessionManager;
    class idMQSession* sessionZero;
    volatile bool terminateConnection;
    volatile bool connectionTerminated;
    volatile bool isClosing;
    unsigned int threadHandle;
    amqpShutdownReason_t shutdownReason;

private:
    bool OpenCommunications();
    void CreateThread();
    void MessageThread();
    static unsigned int StaticThread(void* connection);
};

class idMQSession {
public:
    idMQSession(int channelNumber, idMQConnection* connection);
    ~idMQSession();
    void Init(bool connectionChannel = false);
    void Close();
    void Close(const char* reason, MQErrors_t error,
        bool notifyServer = true);
    void HandleFrame(idMQFrame& frame);
    void SendCommand(idMQCommand& command);

    idMQConnection* connection;
    idMQCommandBuilder cmdBuilder;
    idMQChannel* protocol;
    idMQCommand currentCommand;
    int channelNumber;
    bool isOpen;
};

class idMQSessionManager {
public:
    explicit idMQSessionManager(idMQConnection* connection);
    ~idMQSessionManager();
    void Init(int maximumSessions);
    void Shutdown();
    idMQSession* CreateSession();
    idMQSession* Lookup(int channelNumber);

    bool initialized;
    idMQConnection* connection;
    int maxSessions;
    idMQList<idMQSession*> sessionList;
};

class idMQClientThread {
public:
    idMQClientThread();
    virtual ~idMQClientThread();
    virtual void StartMessageSystem() { StartThread("AMQP Client"); }
    virtual void StopMessageSystem() { StopThread(true); }
    virtual void PreRun() {}
    virtual void ThreadSlice() { Sys_Yield(); }
    virtual void OnThreadTerminate() {}

    void StartThread(const char* threadName);
    void StopThread(bool waitForStop);

    unsigned int handle;
    volatile bool signalQuit;
    volatile bool terminated;
    idMQConnection connection;
    int retryTime;

protected:
    static void Connect(idMQClientThread* thread);
    static unsigned int Thread(void* thread);
};

class idMQClient : public idMQClientThread {};

class idMQGraphiteClient : public idMQClientThread {
public:
    struct graphiteEvent_t {
        const char* eventName;
        int count;
        float duration;
        float mean;
        float mean2;
    };

    idMQGraphiteClient(const idStr& exchangeName, const idStr& metricPrefix);
    ~idMQGraphiteClient() override;
    void StartMessageSystem() override;
    void PreRun() override;
    void ThreadSlice() override;
    void OnThreadTerminate() override;
    void LogEvent(const idStr& eventName, float duration);

    int reportTime;
    idMQChannel* channel;
    idMQList<graphiteEvent_t> outgoingEvents;
    idStr exchange;
    idStr prefix;
    idSysMutex threadMutex;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idMQTCP) == 20, "Recovered idMQTCP ABI changed");
static_assert(sizeof(idMQList<unsigned char>) == 16,
    "Recovered AMQP list ABI changed");
static_assert(sizeof(idMQTable) == 48, "Recovered AMQP table ABI changed");
static_assert(sizeof(idMQBuffer) == 20, "Recovered idMQBuffer ABI changed");
static_assert(sizeof(idMQMethod) == 4, "Recovered idMQMethod ABI changed");
static_assert(sizeof(idMQContentHeader) == 16,
    "Recovered idMQContentHeader ABI changed");
#endif
