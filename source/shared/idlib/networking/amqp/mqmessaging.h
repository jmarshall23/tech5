#pragma once

#include "mqcommon.h"

enum amqpConnectionMethodId_t {
    AMQP_METHOD_CONNECTION_START = 10,
    AMQP_METHOD_CONNECTION_STARTOK = 11,
    AMQP_METHOD_CONNECTION_SECURE = 20,
    AMQP_METHOD_CONNECTION_SECUREOK = 21,
    AMQP_METHOD_CONNECTION_TUNE = 30,
    AMQP_METHOD_CONNECTION_TUNEOK = 31,
    AMQP_METHOD_CONNECTION_OPEN = 40,
    AMQP_METHOD_CONNECTION_OPENOK = 41,
    AMQP_METHOD_CONNECTION_REDIRECT = 50,
    AMQP_METHOD_CONNECTION_CLOSE = 60,
    AMQP_METHOD_CONNECTION_CLOSEOK = 61
};

enum amqpChannelMethodId_t {
    AMQP_METHOD_CHANNEL_OPEN = 10,
    AMQP_METHOD_CHANNEL_OPENOK = 11,
    AMQP_METHOD_CHANNEL_FLOW = 20,
    AMQP_METHOD_CHANNEL_FLOWOK = 21,
    AMQP_METHOD_CHANNEL_ALERT = 30,
    AMQP_METHOD_CHANNEL_CLOSE = 40,
    AMQP_METHOD_CHANNEL_CLOSEOK = 41
};

enum amqpExchangeMethodId_t {
    AMQP_METHOD_EXCHANGE_DECLARE = 10,
    AMQP_METHOD_EXCHANGE_DECLAREOK = 11,
    AMQP_METHOD_EXCHANGE_DELETE = 20,
    AMQP_METHOD_EXCHANGE_DELETEOK = 21
};

enum amqpQueueMethodId_t {
    AMQP_METHOD_QUEUE_DECLARE = 10,
    AMQP_METHOD_QUEUE_DECLAREOK = 11,
    AMQP_METHOD_QUEUE_BIND = 20,
    AMQP_METHOD_QUEUE_BINDOK = 21,
    AMQP_METHOD_QUEUE_PURGE = 30,
    AMQP_METHOD_QUEUE_PURGEOK = 31,
    AMQP_METHOD_QUEUE_DELETE = 40,
    AMQP_METHOD_QUEUE_DELETEOK = 41,
    AMQP_METHOD_QUEUE_UNBIND = 50,
    AMQP_METHOD_QUEUE_UNBINDOK = 51
};

enum amqpBasicMethodId_t {
    AMQP_METHOD_BASIC_QOS = 10,
    AMQP_METHOD_BASIC_QOSOK = 11,
    AMQP_METHOD_BASIC_CONSUME = 20,
    AMQP_METHOD_BASIC_CONSUMEOK = 21,
    AMQP_METHOD_BASIC_CANCEL = 30,
    AMQP_METHOD_BASIC_CANCELOK = 31,
    AMQP_METHOD_BASIC_PUBLISH = 40,
    AMQP_METHOD_BASIC_RETURN = 50,
    AMQP_METHOD_BASIC_DELIVER = 60,
    AMQP_METHOD_BASIC_GET = 70,
    AMQP_METHOD_BASIC_GETOK = 71,
    AMQP_METHOD_BASIC_GETEMPTY = 72,
    AMQP_METHOD_BASIC_ACK = 80,
    AMQP_METHOD_BASIC_REJECT = 90,
    AMQP_METHOD_BASIC_RECOVERASYNC = 100,
    AMQP_METHOD_BASIC_RECOVER = 110,
    AMQP_METHOD_BASIC_RECOVEROK = 111
};

#define ID_AMQP_METHOD_META(classIdValue, methodIdValue, contentValue, asyncValue) \
    int GetClassId() const override { return classIdValue; } \
    int GetMethodId() const override { return methodIdValue; } \
    bool HasContent() const override { return contentValue; } \
    bool IsAsync() const override { return asyncValue; } \
    void Populate(idMQFrame& frame) override; \
    void ToFrame(idMQFrame& frame) override

class AMQPConnectionStart : public idMQMethod {
public:
    AMQPConnectionStart() : versionMajor(0), versionMinor(0) {}
    ID_AMQP_METHOD_META(10, 10, false, true);
    unsigned char versionMajor;
    unsigned char versionMinor;
    idMQTable serverProperties;
    idMQList<unsigned char> mechanisms;
    idMQList<unsigned char> locales;
};

class AMQPConnectionStartOk : public idMQMethod {
public:
    ID_AMQP_METHOD_META(10, 11, false, false);
    idMQTable clientProperties;
    idStr mechanism;
    idMQList<unsigned char> response;
    idStr locale;
};

class AMQPConnectionSecure : public idMQMethod {
public:
    ID_AMQP_METHOD_META(10, 20, false, true);
    idMQList<unsigned char> challenge;
};

class AMQPConnectionSecureOk : public idMQMethod {
public:
    ID_AMQP_METHOD_META(10, 21, false, false);
    idMQList<unsigned char> response;
};

class AMQPConnectionTune : public idMQMethod {
public:
    AMQPConnectionTune() : channelMax(0), frameMax(0), heartbeat(0) {}
    ID_AMQP_METHOD_META(10, 30, false, true);
    unsigned short channelMax;
    unsigned int frameMax;
    unsigned short heartbeat;
};

class AMQPConnectionTuneOk : public idMQMethod {
public:
    AMQPConnectionTuneOk() : channelMax(0), frameMax(0), heartbeat(0) {}
    ID_AMQP_METHOD_META(10, 31, false, false);
    unsigned short channelMax;
    unsigned int frameMax;
    unsigned short heartbeat;
};

class AMQPConnectionOpen : public idMQMethod {
public:
    AMQPConnectionOpen() : insist(false) {}
    ID_AMQP_METHOD_META(10, 40, false, false);
    idStr virtualHost;
    idStr capabilities;
    bool insist;
};

class AMQPConnectionOpenOk : public idMQMethod {
public:
    ID_AMQP_METHOD_META(10, 41, false, true);
    idStr knownHosts;
};

class AMQPConnectionRedirect : public idMQMethod {
public:
    ID_AMQP_METHOD_META(10, 50, false, true);
    idStr host;
    idStr knownHosts;
};

class AMQPConnectionClose : public idMQMethod {
public:
    AMQPConnectionClose() : replyCode(0), cId(0), mId(0) {}
    ID_AMQP_METHOD_META(10, 60, false, true);
    unsigned short replyCode;
    idStr replyText;
    unsigned short cId;
    unsigned short mId;
};

class AMQPConnectionCloseOk : public idMQMethod {
public:
    ID_AMQP_METHOD_META(10, 61, false, true);
};

class AMQPChannelOpen : public idMQMethod {
public:
    ID_AMQP_METHOD_META(20, 10, false, false);
    idStr oob;
};

class AMQPChannelOpenOk : public idMQMethod {
public:
    ID_AMQP_METHOD_META(20, 11, false, true);
};

class AMQPChannelFlow : public idMQMethod {
public:
    AMQPChannelFlow() : active(false) {}
    ID_AMQP_METHOD_META(20, 20, false, true);
    bool active;
};

class AMQPChannelFlowOk : public idMQMethod {
public:
    AMQPChannelFlowOk() : active(false) {}
    ID_AMQP_METHOD_META(20, 21, false, true);
    bool active;
};

class AMQPChannelAlert : public idMQMethod {
public:
    AMQPChannelAlert() : replyCode(0) {}
    ID_AMQP_METHOD_META(20, 30, false, true);
    unsigned short replyCode;
    idStr replyText;
    idMQTable details;
};

class AMQPChannelClose : public idMQMethod {
public:
    AMQPChannelClose() : replyCode(0), cId(0), mId(0) {}
    ID_AMQP_METHOD_META(20, 40, false, true);
    unsigned short replyCode;
    idStr replyText;
    unsigned short cId;
    unsigned short mId;
};

class AMQPChannelCloseOk : public idMQMethod {
public:
    ID_AMQP_METHOD_META(20, 41, false, true);
};

class AMQPExchangeDeclare : public idMQMethod {
public:
    AMQPExchangeDeclare() : ticket(0), passive(false), durable(false),
        autoDelete(false), isInternal(false), noWait(false) {}
    ID_AMQP_METHOD_META(40, 10, false, false);
    unsigned short ticket;
    idStr exchange;
    idStr type;
    bool passive;
    bool durable;
    bool autoDelete;
    bool isInternal;
    bool noWait;
    idMQTable arguments;
};

class AMQPExchangeDeclareOk : public idMQMethod {
public:
    ID_AMQP_METHOD_META(40, 11, false, true);
};

class AMQPExchangeDelete : public idMQMethod {
public:
    AMQPExchangeDelete() : ticket(0), unused(false), noWait(false) {}
    ID_AMQP_METHOD_META(40, 20, false, false);
    unsigned short ticket;
    idStr exchange;
    bool unused;
    bool noWait;
};

class AMQPExchangeDeleteOk : public idMQMethod {
public:
    ID_AMQP_METHOD_META(40, 21, false, true);
};

class AMQPQueueDeclare : public idMQMethod {
public:
    AMQPQueueDeclare() : ticket(0), passive(false), durable(false),
        exclusive(false), autoDelete(false), noWait(false) {}
    ID_AMQP_METHOD_META(50, 10, false, false);
    unsigned short ticket;
    idStr queue;
    bool passive;
    bool durable;
    bool exclusive;
    bool autoDelete;
    bool noWait;
    idMQTable arguments;
};

class AMQPQueueDeclareOk : public idMQMethod {
public:
    AMQPQueueDeclareOk() : messageCount(0), consumerCount(0) {}
    ID_AMQP_METHOD_META(50, 11, false, true);
    idStr queue;
    unsigned int messageCount;
    unsigned int consumerCount;
};

class AMQPQueueBind : public idMQMethod {
public:
    AMQPQueueBind() : ticket(0), noWait(false) {}
    ID_AMQP_METHOD_META(50, 20, false, false);
    unsigned short ticket;
    idStr queue;
    idStr exchange;
    idStr routingKey;
    bool noWait;
    idMQTable arguments;
};

class AMQPQueueBindOk : public idMQMethod {
public:
    ID_AMQP_METHOD_META(50, 21, false, true);
};

class AMQPQueueUnbind : public idMQMethod {
public:
    AMQPQueueUnbind() : ticket(0) {}
    ID_AMQP_METHOD_META(50, 50, false, false);
    unsigned short ticket;
    idStr queue;
    idStr exchange;
    idStr routingKey;
    idMQTable arguments;
};

class AMQPQueueUnbindOk : public idMQMethod {
public:
    ID_AMQP_METHOD_META(50, 51, false, true);
};

class AMQPQueuePurge : public idMQMethod {
public:
    AMQPQueuePurge() : ticket(0), noWait(false) {}
    ID_AMQP_METHOD_META(50, 30, false, false);
    unsigned short ticket;
    idStr queue;
    bool noWait;
};

class AMQPQueuePurgeOk : public idMQMethod {
public:
    AMQPQueuePurgeOk() : messageCount(0) {}
    ID_AMQP_METHOD_META(50, 31, false, true);
    unsigned int messageCount;
};

class AMQPQueueDelete : public idMQMethod {
public:
    AMQPQueueDelete() : ticket(0), unused(false), empty(false), noWait(false) {}
    ID_AMQP_METHOD_META(50, 40, false, false);
    unsigned short ticket;
    idStr queue;
    bool unused;
    bool empty;
    bool noWait;
};

class AMQPQueueDeleteOk : public idMQMethod {
public:
    AMQPQueueDeleteOk() : messageCount(0) {}
    ID_AMQP_METHOD_META(50, 41, false, true);
    unsigned int messageCount;
};

class AMQPBasicQos : public idMQMethod {
public:
    AMQPBasicQos() : prefetchSize(0), prefetchCount(0), isGlobal(false) {}
    ID_AMQP_METHOD_META(60, 10, false, false);
    unsigned int prefetchSize;
    unsigned short prefetchCount;
    bool isGlobal;
};

class AMQPBasicQosOk : public idMQMethod {
public:
    ID_AMQP_METHOD_META(60, 11, false, true);
};

class AMQPBasicConsume : public idMQMethod {
public:
    AMQPBasicConsume() : ticket(0), noLocal(false), noAck(false),
        exclusive(false), noWait(false) {}
    ID_AMQP_METHOD_META(60, 20, false, false);
    unsigned short ticket;
    idStr queue;
    idStr consumerTag;
    bool noLocal;
    bool noAck;
    bool exclusive;
    bool noWait;
};

class AMQPBasicConsumeOk : public idMQMethod {
public:
    ID_AMQP_METHOD_META(60, 21, false, true);
    idStr consumerTag;
};

class AMQPBasicCancel : public idMQMethod {
public:
    AMQPBasicCancel() : noWait(false) {}
    ID_AMQP_METHOD_META(60, 30, false, false);
    idStr consumerTag;
    bool noWait;
};

class AMQPBasicCancelOk : public idMQMethod {
public:
    ID_AMQP_METHOD_META(60, 31, false, true);
    idStr consumerTag;
};

class AMQPBasicPublish : public idMQMethod {
public:
    AMQPBasicPublish() : ticket(0), mandatory(false), immediate(false) {}
    ID_AMQP_METHOD_META(60, 40, true, false);
    unsigned short ticket;
    idStr exchange;
    idStr routingKey;
    bool mandatory;
    bool immediate;
};

class AMQPBasicReturn : public idMQMethod {
public:
    AMQPBasicReturn() : replyCode(0) {}
    ID_AMQP_METHOD_META(60, 50, true, true);
    unsigned short replyCode;
    idStr replyText;
    idStr exchange;
    idStr routingKey;
};

class AMQPBasicDeliver : public idMQMethod {
public:
    AMQPBasicDeliver() : deliveryTag(0), redelivered(false) {}
    ID_AMQP_METHOD_META(60, 60, true, true);
    idStr consumerTag;
    std::uint64_t deliveryTag;
    bool redelivered;
    idStr exchange;
    idStr routingKey;
};

class AMQPBasicGet : public idMQMethod {
public:
    AMQPBasicGet() : ticket(0), noAck(false) {}
    ID_AMQP_METHOD_META(60, 70, false, false);
    unsigned short ticket;
    idStr queue;
    bool noAck;
};

class AMQPBasicGetOk : public idMQMethod {
public:
    AMQPBasicGetOk() : deliveryTag(0), redelivered(false), messageCount(0) {}
    ID_AMQP_METHOD_META(60, 71, true, true);
    std::uint64_t deliveryTag;
    bool redelivered;
    idStr exchange;
    idStr routingKey;
    unsigned int messageCount;
};

class AMQPBasicGetEmpty : public idMQMethod {
public:
    ID_AMQP_METHOD_META(60, 72, false, true);
    idStr clusterId;
};

class AMQPBasicAck : public idMQMethod {
public:
    AMQPBasicAck() : deliveryTag(0), multiple(false) {}
    ID_AMQP_METHOD_META(60, 80, false, true);
    std::uint64_t deliveryTag;
    bool multiple;
};

class AMQPBasicReject : public idMQMethod {
public:
    AMQPBasicReject() : deliveryTag(0), requeue(false) {}
    ID_AMQP_METHOD_META(60, 90, false, true);
    std::uint64_t deliveryTag;
    bool requeue;
};

class AMQPBasicRecoverAsync : public idMQMethod {
public:
    AMQPBasicRecoverAsync() : requeue(false) {}
    ID_AMQP_METHOD_META(60, 100, false, false);
    bool requeue;
};

class AMQPBasicRecover : public idMQMethod {
public:
    AMQPBasicRecover() : requeue(false) {}
    ID_AMQP_METHOD_META(60, 110, false, false);
    bool requeue;
};

class AMQPBasicRecoverOk : public idMQMethod {
public:
    ID_AMQP_METHOD_META(60, 111, false, true);
};

class AMQPBasicProperties : public idMQContentHeader {
public:
    AMQPBasicProperties();
    int GetProtocolId() const override { return AMQP_CLASS_BASIC; }
    void Populate(idMQFrame& frame) override;
    void ToFrame(idMQFrame& frame) override;

    idStr contentType;
    idStr contentEncoding;
    idMQTable headers;
    unsigned char deliveryMode;
    unsigned char priority;
    idStr correlationId;
    idStr replyTo;
    idStr expiration;
    idStr messageId;
    std::uint64_t timestamp;
    idStr type;
    idStr userId;
    idStr appId;
    idStr clusterId;
    bool b_contentType;
    bool b_contentEncoding;
    bool b_headers;
    bool b_deliveryMode;
    bool b_priority;
    bool b_correlationId;
    bool b_replyTo;
    bool b_expiration;
    bool b_messageId;
    bool b_timestamp;
    bool b_type;
    bool b_userId;
    bool b_appId;
    bool b_clusterId;
};

class idMQConsumer;

struct amqpBasicGetResultOk_t {
    amqpBasicGetResultOk_t()
        : deliveryTag(0), redelivered(false), exchange(), routingKey(),
          messageCount(0), header(nullptr), body() {}
    amqpBasicGetResultOk_t(const amqpBasicGetResultOk_t& other);
    amqpBasicGetResultOk_t& operator=(const amqpBasicGetResultOk_t& other);
    ~amqpBasicGetResultOk_t();
    std::uint64_t deliveryTag;
    bool redelivered;
    idStr exchange;
    idStr routingKey;
    unsigned int messageCount;
    AMQPBasicProperties* header;
    idMQList<unsigned char> body;
};

class idMQChannel {
public:
    explicit idMQChannel(idMQSession* session);
    ~idMQChannel();
    void Init();
    void Close();
    MQErrors_t HandleCommand(idMQCommand& command);

    static idMQMethod* DecodeMethod(idMQFrame& frame);
    static idMQContentHeader* DecodeContentHeader(idMQFrame& frame);

    void ConnectionStartOk(AMQPConnectionTune& tune,
        const idStr& mechanism, const idMQList<unsigned char>& response,
        const idStr& locale);
    void ConnectionTuneOk(unsigned short channelMax, unsigned int frameMax,
        unsigned short heartbeat);
    void ConnectionOpen(idStr& knownHosts, const idStr& vhost,
        const idStr& capabilities, bool insist);
    void ConnectionClose(unsigned short replyCode, const idStr& replyText,
        unsigned short classId, unsigned short methodId);
    void ChannelOpen(const idStr& outOfBand = idStr(""));
    void ExchangeDeclare(const idStr& exchange, const idStr& type,
        bool durable);
    void ExchangeDeclare(const idStr& exchange, const idStr& type,
        bool durable, bool autoDelete);
    void BasicPublish(const idStr& exchange, const idStr& routingKey,
        const idMQList<unsigned char>& body);
    void BasicPublish(const idStr& exchange, const idStr& routingKey,
        bool mandatory, bool immediate, const void* data, unsigned int size);

    idMQSession* session;
    idSysMutex protocolWait;
    idDeferredResult<AMQPConnectionStart> deferredConnectionStart;
    idDeferredResult<AMQPConnectionTune> deferredConnectionTune;
    idDeferredResult<AMQPConnectionOpenOk> deferredConnectionOpenOk;
    idDeferredResult<AMQPChannelOpenOk> deferredChannelOpenOk;
    idDeferredResult<AMQPChannelFlow> deferredChannelFlow;
    idDeferredResult<AMQPChannelFlowOk> deferredChannelFlowOk;
    idDeferredResult<AMQPExchangeDeclareOk> deferredExchangeDeclareOk;
    idDeferredResult<AMQPExchangeDeleteOk> deferredExchangeDeleteOk;
    idDeferredResult<AMQPQueueDeclareOk> deferredQueueDeclareOk;
    idDeferredResult<AMQPQueueBindOk> deferredQueueBindOk;
    idDeferredResult<AMQPQueuePurgeOk> deferredQueuePurgeOk;
    idDeferredResult<AMQPQueueDeleteOk> deferredQueueDeleteOk;
    idDeferredResult<AMQPBasicConsumeOk> deferredBasicConsumeOk;
    idDeferredResult<AMQPBasicCancelOk> deferredBasicCancelOk;
    idDeferredResult<amqpBasicGetResultOk_t> deferredBasicGetResultOk;
    idDeferredResult<AMQPBasicRecoverOk> deferredAMQPBasicRecoverOk;
    idMQList<idMQConsumer*> consumers;

private:
    void ExchangeDeclareInternal(const idStr& exchange, const idStr& type,
        bool passive, bool durable, bool autoDelete, bool internal,
        bool noWait);
    void BasicPublishInternal(const idStr& exchange, const idStr& routingKey,
        bool mandatory, bool immediate,
        const idMQList<unsigned char>& body);
    idMQConsumer* LookupConsumer(const idStr& tag);
    bool RemoveConsumer(const idStr& tag);
};

#undef ID_AMQP_METHOD_META
