#include "mqmessaging.h"
#include "mqconsumer.h"

#ifdef nullptr
#undef nullptr
#endif

#include <cstring>

namespace {

template<class T>
idMQMethod* Decode(idMQFrame& frame) {
    T* value = new T();
    value->Populate(frame);
    return value;
}

void SendMethod(idMQSession* session, idMQMethod& method) {
    if (session == nullptr) return;
    idMQCommand command;
    command.method = &method;
    session->SendCommand(command);
}

} // namespace

amqpBasicGetResultOk_t::amqpBasicGetResultOk_t(
        const amqpBasicGetResultOk_t& other)
    : amqpBasicGetResultOk_t() {
    *this = other;
}

amqpBasicGetResultOk_t& amqpBasicGetResultOk_t::operator=(
        const amqpBasicGetResultOk_t& other) {
    if (this == &other) return *this;
    deliveryTag = other.deliveryTag;
    redelivered = other.redelivered;
    exchange = other.exchange;
    routingKey = other.routingKey;
    messageCount = other.messageCount;
    delete header;
    header = other.header == nullptr ? nullptr
        : new AMQPBasicProperties(*other.header);
    body = other.body;
    return *this;
}

amqpBasicGetResultOk_t::~amqpBasicGetResultOk_t() { delete header; }

idMQChannel::idMQChannel(idMQSession* sessionValue)
    : session(sessionValue), protocolWait(), deferredConnectionStart(),
      deferredConnectionTune(), deferredConnectionOpenOk(),
      deferredChannelOpenOk(), deferredChannelFlow(), deferredChannelFlowOk(),
      deferredExchangeDeclareOk(), deferredExchangeDeleteOk(),
      deferredQueueDeclareOk(), deferredQueueBindOk(), deferredQueuePurgeOk(),
      deferredQueueDeleteOk(), deferredBasicConsumeOk(),
      deferredBasicCancelOk(), deferredBasicGetResultOk(),
      deferredAMQPBasicRecoverOk(), consumers() {
}

idMQChannel::~idMQChannel() = default;

void idMQChannel::Init() {
    deferredConnectionStart.Clear();
    deferredConnectionTune.Clear();
    deferredConnectionOpenOk.Clear();
    deferredChannelOpenOk.Clear();
}

idMQMethod* idMQChannel::DecodeMethod(idMQFrame& frame) {
    const int classId = frame.ReadUInt16();
    const int methodId = frame.ReadUInt16();
    switch (classId) {
        case AMQP_CLASS_CONNECTION:
            switch (methodId) {
                case 10: return Decode<AMQPConnectionStart>(frame);
                case 11: return Decode<AMQPConnectionStartOk>(frame);
                case 20: return Decode<AMQPConnectionSecure>(frame);
                case 21: return Decode<AMQPConnectionSecureOk>(frame);
                case 30: return Decode<AMQPConnectionTune>(frame);
                case 31: return Decode<AMQPConnectionTuneOk>(frame);
                case 40: return Decode<AMQPConnectionOpen>(frame);
                case 41: return Decode<AMQPConnectionOpenOk>(frame);
                case 50: return Decode<AMQPConnectionRedirect>(frame);
                case 60: return Decode<AMQPConnectionClose>(frame);
                case 61: return Decode<AMQPConnectionCloseOk>(frame);
            }
            break;
        case AMQP_CLASS_CHANNEL:
            switch (methodId) {
                case 10: return Decode<AMQPChannelOpen>(frame);
                case 11: return Decode<AMQPChannelOpenOk>(frame);
                case 20: return Decode<AMQPChannelFlow>(frame);
                case 21: return Decode<AMQPChannelFlowOk>(frame);
                case 30: return Decode<AMQPChannelAlert>(frame);
                case 40: return Decode<AMQPChannelClose>(frame);
                case 41: return Decode<AMQPChannelCloseOk>(frame);
            }
            break;
        case AMQP_CLASS_EXCHANGE:
            switch (methodId) {
                case 10: return Decode<AMQPExchangeDeclare>(frame);
                case 11: return Decode<AMQPExchangeDeclareOk>(frame);
                case 20: return Decode<AMQPExchangeDelete>(frame);
                case 21: return Decode<AMQPExchangeDeleteOk>(frame);
            }
            break;
        case AMQP_CLASS_QUEUE:
            switch (methodId) {
                case 10: return Decode<AMQPQueueDeclare>(frame);
                case 11: return Decode<AMQPQueueDeclareOk>(frame);
                case 20: return Decode<AMQPQueueBind>(frame);
                case 21: return Decode<AMQPQueueBindOk>(frame);
                case 30: return Decode<AMQPQueuePurge>(frame);
                case 31: return Decode<AMQPQueuePurgeOk>(frame);
                case 40: return Decode<AMQPQueueDelete>(frame);
                case 41: return Decode<AMQPQueueDeleteOk>(frame);
                case 50: return Decode<AMQPQueueUnbind>(frame);
                case 51: return Decode<AMQPQueueUnbindOk>(frame);
            }
            break;
        case AMQP_CLASS_BASIC:
            switch (methodId) {
                case 10: return Decode<AMQPBasicQos>(frame);
                case 11: return Decode<AMQPBasicQosOk>(frame);
                case 20: return Decode<AMQPBasicConsume>(frame);
                case 21: return Decode<AMQPBasicConsumeOk>(frame);
                case 30: return Decode<AMQPBasicCancel>(frame);
                case 31: return Decode<AMQPBasicCancelOk>(frame);
                case 40: return Decode<AMQPBasicPublish>(frame);
                case 50: return Decode<AMQPBasicReturn>(frame);
                case 60: return Decode<AMQPBasicDeliver>(frame);
                case 70: return Decode<AMQPBasicGet>(frame);
                case 71: return Decode<AMQPBasicGetOk>(frame);
                case 72: return Decode<AMQPBasicGetEmpty>(frame);
                case 80: return Decode<AMQPBasicAck>(frame);
                case 90: return Decode<AMQPBasicReject>(frame);
                case 100: return Decode<AMQPBasicRecoverAsync>(frame);
                case 110: return Decode<AMQPBasicRecover>(frame);
                case 111: return Decode<AMQPBasicRecoverOk>(frame);
            }
            break;
    }
    return nullptr;
}

idMQContentHeader* idMQChannel::DecodeContentHeader(idMQFrame& frame) {
    const int classId = frame.ReadUInt16();
    frame.ReadUInt16(); // weight, reserved and always zero
    const std::uint64_t bodyLength = frame.ReadUInt64();
    if (classId != AMQP_CLASS_BASIC) return nullptr;
    AMQPBasicProperties* header = new AMQPBasicProperties();
    header->bodyLength = bodyLength;
    header->Populate(frame);
    return header;
}

idMQConsumer* idMQChannel::LookupConsumer(const idStr& tag) {
    for (int index = 0; index < consumers.Num(); ++index) {
        if (consumers[index] != nullptr
                && _stricmp(consumers[index]->consumerTag.c_str(),
                    tag.c_str()) == 0) {
            return consumers[index];
        }
    }
    return nullptr;
}

bool idMQChannel::RemoveConsumer(const idStr& tag) {
    for (int index = 0; index < consumers.Num(); ++index) {
        if (consumers[index] != nullptr
                && _stricmp(consumers[index]->consumerTag.c_str(),
                    tag.c_str()) == 0) {
            return consumers.RemoveIndex(index);
        }
    }
    return false;
}

MQErrors_t idMQChannel::HandleCommand(idMQCommand& command) {
    if (command.method == nullptr) return MQERROR_UNEXPECTED_METHOD;
    const int classId = command.method->GetClassId();
    const int methodId = command.method->GetMethodId();
    if (classId == AMQP_CLASS_CONNECTION) {
        switch (methodId) {
            case 10: deferredConnectionStart.SetValue(
                *static_cast<AMQPConnectionStart*>(command.method)); break;
            case 30: deferredConnectionTune.SetValue(
                *static_cast<AMQPConnectionTune*>(command.method)); break;
            case 41: deferredConnectionOpenOk.SetValue(
                *static_cast<AMQPConnectionOpenOk*>(command.method)); break;
            case 60: {
                AMQPConnectionCloseOk response;
                SendMethod(session, response);
                return MQERROR_SERVER_CLOSED;
            }
            case 61: break;
            default: return MQERROR_UNEXPECTED_METHOD;
        }
        return MQERROR_NONE;
    }
    if (classId == AMQP_CLASS_CHANNEL) {
        switch (methodId) {
            case 11: deferredChannelOpenOk.SetValue(
                *static_cast<AMQPChannelOpenOk*>(command.method)); break;
            case 20: {
                AMQPChannelFlow& flow = *static_cast<AMQPChannelFlow*>(command.method);
                deferredChannelFlow.SetValue(flow);
                AMQPChannelFlowOk response;
                response.active = flow.active;
                SendMethod(session, response);
                break;
            }
            case 21: deferredChannelFlowOk.SetValue(
                *static_cast<AMQPChannelFlowOk*>(command.method)); break;
            case 40: {
                AMQPChannelCloseOk response;
                SendMethod(session, response);
                return MQERROR_SERVER_CLOSED;
            }
            case 41: break;
            default: return MQERROR_UNEXPECTED_METHOD;
        }
        return MQERROR_NONE;
    }
    if (classId == AMQP_CLASS_EXCHANGE) {
        if (methodId == 11) deferredExchangeDeclareOk.SetValue(
            *static_cast<AMQPExchangeDeclareOk*>(command.method));
        else if (methodId == 21) deferredExchangeDeleteOk.SetValue(
            *static_cast<AMQPExchangeDeleteOk*>(command.method));
        else return MQERROR_UNEXPECTED_METHOD;
        return MQERROR_NONE;
    }
    if (classId == AMQP_CLASS_QUEUE) {
        switch (methodId) {
            case 11: deferredQueueDeclareOk.SetValue(
                *static_cast<AMQPQueueDeclareOk*>(command.method)); break;
            case 21: deferredQueueBindOk.SetValue(
                *static_cast<AMQPQueueBindOk*>(command.method)); break;
            case 31: deferredQueuePurgeOk.SetValue(
                *static_cast<AMQPQueuePurgeOk*>(command.method)); break;
            case 41: deferredQueueDeleteOk.SetValue(
                *static_cast<AMQPQueueDeleteOk*>(command.method)); break;
            default: return MQERROR_UNEXPECTED_METHOD;
        }
        return MQERROR_NONE;
    }
    if (classId == AMQP_CLASS_BASIC) {
        switch (methodId) {
            case 21: {
                AMQPBasicConsumeOk& value =
                    *static_cast<AMQPBasicConsumeOk*>(command.method);
                deferredBasicConsumeOk.SetValue(value);
                idMQConsumer* consumer = LookupConsumer(value.consumerTag);
                if (consumer != nullptr) consumer->ProcessBasicConsumeOk(
                    value.consumerTag);
                break;
            }
            case 30: {
                AMQPBasicCancel& value =
                    *static_cast<AMQPBasicCancel*>(command.method);
                idMQConsumer* consumer = LookupConsumer(value.consumerTag);
                if (consumer != nullptr) consumer->ProcessBasicCancel(
                    value.consumerTag);
                RemoveConsumer(value.consumerTag);
                break;
            }
            case 31: deferredBasicCancelOk.SetValue(
                *static_cast<AMQPBasicCancelOk*>(command.method)); break;
            case 60: {
                AMQPBasicDeliver& value =
                    *static_cast<AMQPBasicDeliver*>(command.method);
                idMQConsumer* consumer = LookupConsumer(value.consumerTag);
                if (consumer != nullptr) consumer->ProcessBasicDeliver(
                    value.consumerTag, value.deliveryTag, value.redelivered,
                    value.exchange, value.routingKey,
                    static_cast<AMQPBasicProperties*>(command.contentHeader),
                    command.contentBody);
                break;
            }
            case 71: {
                AMQPBasicGetOk& value =
                    *static_cast<AMQPBasicGetOk*>(command.method);
                amqpBasicGetResultOk_t result;
                result.deliveryTag = value.deliveryTag;
                result.redelivered = value.redelivered;
                result.exchange = value.exchange;
                result.routingKey = value.routingKey;
                result.messageCount = value.messageCount;
                result.header = command.contentHeader == nullptr ? nullptr
                    : new AMQPBasicProperties(
                        *static_cast<AMQPBasicProperties*>(command.contentHeader));
                result.body = command.contentBody;
                deferredBasicGetResultOk.SetValue(result);
                break;
            }
            case 111: deferredAMQPBasicRecoverOk.SetValue(
                *static_cast<AMQPBasicRecoverOk*>(command.method)); break;
            case 50: case 72: case 80: case 90: break;
            default: return MQERROR_UNEXPECTED_METHOD;
        }
        return MQERROR_NONE;
    }
    return MQERROR_UNEXPECTED_CLASS;
}

void idMQChannel::ConnectionStartOk(AMQPConnectionTune& tune,
        const idStr& mechanism, const idMQList<unsigned char>& response,
        const idStr& locale) {
    idScopedCriticalSection lock(protocolWait);
    AMQPConnectionStartOk request;
    request.mechanism = mechanism;
    request.response = response;
    request.locale = locale;
    SendMethod(session, request);
    deferredConnectionTune.GetValue(tune);
}

void idMQChannel::ConnectionTuneOk(const unsigned short channelMax,
        const unsigned int frameMax, const unsigned short heartbeat) {
    AMQPConnectionTuneOk request;
    request.channelMax = channelMax;
    request.frameMax = frameMax;
    request.heartbeat = heartbeat;
    SendMethod(session, request);
}

void idMQChannel::ConnectionOpen(idStr& knownHosts, const idStr& vhost,
        const idStr& capabilities, const bool insist) {
    idScopedCriticalSection lock(protocolWait);
    AMQPConnectionOpen request;
    request.virtualHost = vhost;
    request.capabilities = capabilities;
    request.insist = insist;
    SendMethod(session, request);
    AMQPConnectionOpenOk result;
    if (deferredConnectionOpenOk.GetValue(result)) knownHosts = result.knownHosts;
}

void idMQChannel::ConnectionClose(const unsigned short replyCode,
        const idStr& replyText, const unsigned short classId,
        const unsigned short methodId) {
    AMQPConnectionClose request;
    request.replyCode = replyCode;
    request.replyText = replyText;
    request.cId = classId;
    request.mId = methodId;
    SendMethod(session, request);
}

void idMQChannel::ChannelOpen(const idStr& outOfBand) {
    idScopedCriticalSection lock(protocolWait);
    AMQPChannelOpen request;
    request.oob = outOfBand;
    SendMethod(session, request);
    deferredChannelOpenOk.GetValue();
}

void idMQChannel::ExchangeDeclareInternal(const idStr& exchange,
        const idStr& type, const bool passive, const bool durable,
        const bool autoDelete, const bool internal, const bool noWait) {
    idScopedCriticalSection lock(protocolWait);
    AMQPExchangeDeclare request;
    request.exchange = exchange;
    request.type = type;
    request.passive = passive;
    request.durable = durable;
    request.autoDelete = autoDelete;
    request.isInternal = internal;
    request.noWait = noWait;
    SendMethod(session, request);
    if (!noWait) deferredExchangeDeclareOk.GetValue();
}

void idMQChannel::ExchangeDeclare(const idStr& exchange, const idStr& type,
        const bool durable) {
    ExchangeDeclareInternal(exchange, type, false, durable, false, false,
        false);
}

void idMQChannel::ExchangeDeclare(const idStr& exchange, const idStr& type,
        const bool durable, const bool autoDelete) {
    ExchangeDeclareInternal(exchange, type, false, durable, autoDelete,
        false, false);
}

void idMQChannel::BasicPublishInternal(const idStr& exchange,
        const idStr& routingKey, const bool mandatory, const bool immediate,
        const idMQList<unsigned char>& body) {
    AMQPBasicPublish method;
    method.exchange = exchange;
    method.routingKey = routingKey;
    method.mandatory = mandatory;
    method.immediate = immediate;
    AMQPBasicProperties properties;
    properties.bodyLength = body.Num();
    idMQCommand command;
    command.method = &method;
    command.contentHeader = &properties;
    command.contentBody = body;
    session->SendCommand(command);
}

void idMQChannel::BasicPublish(const idStr& exchange,
        const idStr& routingKey, const idMQList<unsigned char>& body) {
    BasicPublishInternal(exchange, routingKey, false, false, body);
}

void idMQChannel::BasicPublish(const idStr& exchange,
        const idStr& routingKey, const bool mandatory, const bool immediate,
        const void* data, const unsigned int size) {
    idMQList<unsigned char> body(16);
    const unsigned char* bytes = static_cast<const unsigned char*>(data);
    for (unsigned int index = 0; index < size; ++index) body.Append(bytes[index]);
    BasicPublishInternal(exchange, routingKey, mandatory, immediate, body);
}

void idMQChannel::Close() {
    if (session != nullptr) session->Close();
}
