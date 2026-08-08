#include "mqmessaging.h"

#ifdef nullptr
#undef nullptr
#endif

#define EMPTY_METHOD(name) \
    void name::Populate(idMQFrame&) {} \
    void name::ToFrame(idMQFrame&) {}

void AMQPConnectionStart::Populate(idMQFrame& frame) {
    versionMajor = frame.ReadByte();
    versionMinor = frame.ReadByte();
    frame.ReadTable(serverProperties);
    frame.ReadString(mechanisms);
    frame.ReadString(locales);
}
void AMQPConnectionStart::ToFrame(idMQFrame& frame) {
    frame.WriteByte(versionMajor);
    frame.WriteByte(versionMinor);
    frame.WriteTable(serverProperties);
    frame.WriteString(mechanisms);
    frame.WriteString(locales);
}

void AMQPConnectionStartOk::Populate(idMQFrame& frame) {
    frame.ReadTable(clientProperties);
    mechanism = frame.ReadShortString();
    frame.ReadString(response);
    locale = frame.ReadShortString();
}
void AMQPConnectionStartOk::ToFrame(idMQFrame& frame) {
    frame.WriteTable(clientProperties);
    frame.WriteShortString(mechanism);
    frame.WriteString(response);
    frame.WriteShortString(locale);
}

void AMQPConnectionSecure::Populate(idMQFrame& frame) {
    frame.ReadString(challenge);
}
void AMQPConnectionSecure::ToFrame(idMQFrame& frame) {
    frame.WriteString(challenge);
}
void AMQPConnectionSecureOk::Populate(idMQFrame& frame) {
    frame.ReadString(response);
}
void AMQPConnectionSecureOk::ToFrame(idMQFrame& frame) {
    frame.WriteString(response);
}

void AMQPConnectionTune::Populate(idMQFrame& frame) {
    channelMax = frame.ReadUInt16();
    frameMax = frame.ReadUInt32();
    heartbeat = frame.ReadUInt16();
}
void AMQPConnectionTune::ToFrame(idMQFrame& frame) {
    frame.WriteUInt16(channelMax);
    frame.WriteUInt32(frameMax);
    frame.WriteUInt16(heartbeat);
}
void AMQPConnectionTuneOk::Populate(idMQFrame& frame) {
    channelMax = frame.ReadUInt16();
    frameMax = frame.ReadUInt32();
    heartbeat = frame.ReadUInt16();
}
void AMQPConnectionTuneOk::ToFrame(idMQFrame& frame) {
    frame.WriteUInt16(channelMax);
    frame.WriteUInt32(frameMax);
    frame.WriteUInt16(heartbeat);
}

void AMQPConnectionOpen::Populate(idMQFrame& frame) {
    virtualHost = frame.ReadShortString();
    capabilities = frame.ReadShortString();
    insist = frame.ReadBool();
}
void AMQPConnectionOpen::ToFrame(idMQFrame& frame) {
    frame.WriteShortString(virtualHost);
    frame.WriteShortString(capabilities);
    frame.WriteBool(insist);
}
void AMQPConnectionOpenOk::Populate(idMQFrame& frame) {
    knownHosts = frame.ReadShortString();
}
void AMQPConnectionOpenOk::ToFrame(idMQFrame& frame) {
    frame.WriteShortString(knownHosts);
}
void AMQPConnectionRedirect::Populate(idMQFrame& frame) {
    host = frame.ReadShortString();
    knownHosts = frame.ReadShortString();
}
void AMQPConnectionRedirect::ToFrame(idMQFrame& frame) {
    frame.WriteShortString(host);
    frame.WriteShortString(knownHosts);
}
void AMQPConnectionClose::Populate(idMQFrame& frame) {
    replyCode = frame.ReadUInt16();
    replyText = frame.ReadShortString();
    cId = frame.ReadUInt16();
    mId = frame.ReadUInt16();
}
void AMQPConnectionClose::ToFrame(idMQFrame& frame) {
    frame.WriteUInt16(replyCode);
    frame.WriteShortString(replyText);
    frame.WriteUInt16(cId);
    frame.WriteUInt16(mId);
}
EMPTY_METHOD(AMQPConnectionCloseOk)

void AMQPChannelOpen::Populate(idMQFrame& frame) {
    oob = frame.ReadShortString();
}
void AMQPChannelOpen::ToFrame(idMQFrame& frame) {
    frame.WriteShortString(oob);
}
EMPTY_METHOD(AMQPChannelOpenOk)
void AMQPChannelFlow::Populate(idMQFrame& frame) { active = frame.ReadBool(); }
void AMQPChannelFlow::ToFrame(idMQFrame& frame) { frame.WriteBool(active); }
void AMQPChannelFlowOk::Populate(idMQFrame& frame) { active = frame.ReadBool(); }
void AMQPChannelFlowOk::ToFrame(idMQFrame& frame) { frame.WriteBool(active); }
void AMQPChannelAlert::Populate(idMQFrame& frame) {
    replyCode = frame.ReadUInt16();
    replyText = frame.ReadShortString();
    frame.ReadTable(details);
}
void AMQPChannelAlert::ToFrame(idMQFrame& frame) {
    frame.WriteUInt16(replyCode);
    frame.WriteShortString(replyText);
    frame.WriteTable(details);
}
void AMQPChannelClose::Populate(idMQFrame& frame) {
    replyCode = frame.ReadUInt16();
    replyText = frame.ReadShortString();
    cId = frame.ReadUInt16();
    mId = frame.ReadUInt16();
}
void AMQPChannelClose::ToFrame(idMQFrame& frame) {
    frame.WriteUInt16(replyCode);
    frame.WriteShortString(replyText);
    frame.WriteUInt16(cId);
    frame.WriteUInt16(mId);
}
EMPTY_METHOD(AMQPChannelCloseOk)

void AMQPExchangeDeclare::Populate(idMQFrame& frame) {
    ticket = frame.ReadUInt16();
    exchange = frame.ReadShortString();
    type = frame.ReadShortString();
    passive = frame.ReadBool();
    durable = frame.ReadBool();
    autoDelete = frame.ReadBool();
    isInternal = frame.ReadBool();
    noWait = frame.ReadBool();
    frame.ReadTable(arguments);
}
void AMQPExchangeDeclare::ToFrame(idMQFrame& frame) {
    frame.WriteUInt16(ticket);
    frame.WriteShortString(exchange);
    frame.WriteShortString(type);
    frame.WriteBool(passive);
    frame.WriteBool(durable);
    frame.WriteBool(autoDelete);
    frame.WriteBool(isInternal);
    frame.WriteBool(noWait);
    frame.WriteTable(arguments);
}
EMPTY_METHOD(AMQPExchangeDeclareOk)
void AMQPExchangeDelete::Populate(idMQFrame& frame) {
    ticket = frame.ReadUInt16();
    exchange = frame.ReadShortString();
    unused = frame.ReadBool();
    noWait = frame.ReadBool();
}
void AMQPExchangeDelete::ToFrame(idMQFrame& frame) {
    frame.WriteUInt16(ticket);
    frame.WriteShortString(exchange);
    frame.WriteBool(unused);
    frame.WriteBool(noWait);
}
EMPTY_METHOD(AMQPExchangeDeleteOk)

void AMQPQueueDeclare::Populate(idMQFrame& frame) {
    ticket = frame.ReadUInt16();
    queue = frame.ReadShortString();
    passive = frame.ReadBool();
    durable = frame.ReadBool();
    exclusive = frame.ReadBool();
    autoDelete = frame.ReadBool();
    noWait = frame.ReadBool();
    frame.ReadTable(arguments);
}
void AMQPQueueDeclare::ToFrame(idMQFrame& frame) {
    frame.WriteUInt16(ticket);
    frame.WriteShortString(queue);
    frame.WriteBool(passive);
    frame.WriteBool(durable);
    frame.WriteBool(exclusive);
    frame.WriteBool(autoDelete);
    frame.WriteBool(noWait);
    frame.WriteTable(arguments);
}
void AMQPQueueDeclareOk::Populate(idMQFrame& frame) {
    queue = frame.ReadShortString();
    messageCount = frame.ReadUInt32();
    consumerCount = frame.ReadUInt32();
}
void AMQPQueueDeclareOk::ToFrame(idMQFrame& frame) {
    frame.WriteShortString(queue);
    frame.WriteUInt32(messageCount);
    frame.WriteUInt32(consumerCount);
}
void AMQPQueueBind::Populate(idMQFrame& frame) {
    ticket = frame.ReadUInt16();
    queue = frame.ReadShortString();
    exchange = frame.ReadShortString();
    routingKey = frame.ReadShortString();
    noWait = frame.ReadBool();
    frame.ReadTable(arguments);
}
void AMQPQueueBind::ToFrame(idMQFrame& frame) {
    frame.WriteUInt16(ticket);
    frame.WriteShortString(queue);
    frame.WriteShortString(exchange);
    frame.WriteShortString(routingKey);
    frame.WriteBool(noWait);
    frame.WriteTable(arguments);
}
EMPTY_METHOD(AMQPQueueBindOk)
void AMQPQueueUnbind::Populate(idMQFrame& frame) {
    ticket = frame.ReadUInt16();
    queue = frame.ReadShortString();
    exchange = frame.ReadShortString();
    routingKey = frame.ReadShortString();
    frame.ReadTable(arguments);
}
void AMQPQueueUnbind::ToFrame(idMQFrame& frame) {
    frame.WriteUInt16(ticket);
    frame.WriteShortString(queue);
    frame.WriteShortString(exchange);
    frame.WriteShortString(routingKey);
    frame.WriteTable(arguments);
}
EMPTY_METHOD(AMQPQueueUnbindOk)
void AMQPQueuePurge::Populate(idMQFrame& frame) {
    ticket = frame.ReadUInt16();
    queue = frame.ReadShortString();
    noWait = frame.ReadBool();
}
void AMQPQueuePurge::ToFrame(idMQFrame& frame) {
    frame.WriteUInt16(ticket);
    frame.WriteShortString(queue);
    frame.WriteBool(noWait);
}
void AMQPQueuePurgeOk::Populate(idMQFrame& frame) {
    messageCount = frame.ReadUInt32();
}
void AMQPQueuePurgeOk::ToFrame(idMQFrame& frame) {
    frame.WriteUInt32(messageCount);
}
void AMQPQueueDelete::Populate(idMQFrame& frame) {
    ticket = frame.ReadUInt16();
    queue = frame.ReadShortString();
    unused = frame.ReadBool();
    empty = frame.ReadBool();
    noWait = frame.ReadBool();
}
void AMQPQueueDelete::ToFrame(idMQFrame& frame) {
    frame.WriteUInt16(ticket);
    frame.WriteShortString(queue);
    frame.WriteBool(unused);
    frame.WriteBool(empty);
    frame.WriteBool(noWait);
}
void AMQPQueueDeleteOk::Populate(idMQFrame& frame) {
    messageCount = frame.ReadUInt32();
}
void AMQPQueueDeleteOk::ToFrame(idMQFrame& frame) {
    frame.WriteUInt32(messageCount);
}

void AMQPBasicQos::Populate(idMQFrame& frame) {
    prefetchSize = frame.ReadUInt32();
    prefetchCount = frame.ReadUInt16();
    isGlobal = frame.ReadBool();
}
void AMQPBasicQos::ToFrame(idMQFrame& frame) {
    frame.WriteUInt32(prefetchSize);
    frame.WriteUInt16(prefetchCount);
    frame.WriteBool(isGlobal);
}
EMPTY_METHOD(AMQPBasicQosOk)
void AMQPBasicConsume::Populate(idMQFrame& frame) {
    ticket = frame.ReadUInt16();
    queue = frame.ReadShortString();
    consumerTag = frame.ReadShortString();
    noLocal = frame.ReadBool();
    noAck = frame.ReadBool();
    exclusive = frame.ReadBool();
    noWait = frame.ReadBool();
}
void AMQPBasicConsume::ToFrame(idMQFrame& frame) {
    frame.WriteUInt16(ticket);
    frame.WriteShortString(queue);
    frame.WriteShortString(consumerTag);
    frame.WriteBool(noLocal);
    frame.WriteBool(noAck);
    frame.WriteBool(exclusive);
    frame.WriteBool(noWait);
}
void AMQPBasicConsumeOk::Populate(idMQFrame& frame) {
    consumerTag = frame.ReadShortString();
}
void AMQPBasicConsumeOk::ToFrame(idMQFrame& frame) {
    frame.WriteShortString(consumerTag);
}
void AMQPBasicCancel::Populate(idMQFrame& frame) {
    consumerTag = frame.ReadShortString();
    noWait = frame.ReadBool();
}
void AMQPBasicCancel::ToFrame(idMQFrame& frame) {
    frame.WriteShortString(consumerTag);
    frame.WriteBool(noWait);
}
void AMQPBasicCancelOk::Populate(idMQFrame& frame) {
    consumerTag = frame.ReadShortString();
}
void AMQPBasicCancelOk::ToFrame(idMQFrame& frame) {
    frame.WriteShortString(consumerTag);
}
void AMQPBasicPublish::Populate(idMQFrame& frame) {
    ticket = frame.ReadUInt16();
    exchange = frame.ReadShortString();
    routingKey = frame.ReadShortString();
    mandatory = frame.ReadBool();
    immediate = frame.ReadBool();
}
void AMQPBasicPublish::ToFrame(idMQFrame& frame) {
    frame.WriteUInt16(ticket);
    frame.WriteShortString(exchange);
    frame.WriteShortString(routingKey);
    frame.WriteBool(mandatory);
    frame.WriteBool(immediate);
}
void AMQPBasicReturn::Populate(idMQFrame& frame) {
    replyCode = frame.ReadUInt16();
    replyText = frame.ReadShortString();
    exchange = frame.ReadShortString();
    routingKey = frame.ReadShortString();
}
void AMQPBasicReturn::ToFrame(idMQFrame& frame) {
    frame.WriteUInt16(replyCode);
    frame.WriteShortString(replyText);
    frame.WriteShortString(exchange);
    frame.WriteShortString(routingKey);
}
void AMQPBasicDeliver::Populate(idMQFrame& frame) {
    consumerTag = frame.ReadShortString();
    deliveryTag = frame.ReadUInt64();
    redelivered = frame.ReadBool();
    exchange = frame.ReadShortString();
    routingKey = frame.ReadShortString();
}
void AMQPBasicDeliver::ToFrame(idMQFrame& frame) {
    frame.WriteShortString(consumerTag);
    frame.WriteUInt64(deliveryTag);
    frame.WriteBool(redelivered);
    frame.WriteShortString(exchange);
    frame.WriteShortString(routingKey);
}
void AMQPBasicGet::Populate(idMQFrame& frame) {
    ticket = frame.ReadUInt16();
    queue = frame.ReadShortString();
    noAck = frame.ReadBool();
}
void AMQPBasicGet::ToFrame(idMQFrame& frame) {
    frame.WriteUInt16(ticket);
    frame.WriteShortString(queue);
    frame.WriteBool(noAck);
}
void AMQPBasicGetOk::Populate(idMQFrame& frame) {
    deliveryTag = frame.ReadUInt64();
    redelivered = frame.ReadBool();
    exchange = frame.ReadShortString();
    routingKey = frame.ReadShortString();
    messageCount = frame.ReadUInt32();
}
void AMQPBasicGetOk::ToFrame(idMQFrame& frame) {
    frame.WriteUInt64(deliveryTag);
    frame.WriteBool(redelivered);
    frame.WriteShortString(exchange);
    frame.WriteShortString(routingKey);
    frame.WriteUInt32(messageCount);
}
void AMQPBasicGetEmpty::Populate(idMQFrame& frame) {
    clusterId = frame.ReadShortString();
}
void AMQPBasicGetEmpty::ToFrame(idMQFrame& frame) {
    frame.WriteShortString(clusterId);
}
void AMQPBasicAck::Populate(idMQFrame& frame) {
    deliveryTag = frame.ReadUInt64();
    multiple = frame.ReadBool();
}
void AMQPBasicAck::ToFrame(idMQFrame& frame) {
    frame.WriteUInt64(deliveryTag);
    frame.WriteBool(multiple);
}
void AMQPBasicReject::Populate(idMQFrame& frame) {
    deliveryTag = frame.ReadUInt64();
    requeue = frame.ReadBool();
}
void AMQPBasicReject::ToFrame(idMQFrame& frame) {
    frame.WriteUInt64(deliveryTag);
    frame.WriteBool(requeue);
}
void AMQPBasicRecoverAsync::Populate(idMQFrame& frame) {
    requeue = frame.ReadBool();
}
void AMQPBasicRecoverAsync::ToFrame(idMQFrame& frame) {
    frame.WriteBool(requeue);
}
void AMQPBasicRecover::Populate(idMQFrame& frame) {
    requeue = frame.ReadBool();
}
void AMQPBasicRecover::ToFrame(idMQFrame& frame) {
    frame.WriteBool(requeue);
}
EMPTY_METHOD(AMQPBasicRecoverOk)

AMQPBasicProperties::AMQPBasicProperties()
    : idMQContentHeader(), contentType(), contentEncoding(), headers(),
      deliveryMode(0), priority(0), correlationId(), replyTo(), expiration(),
      messageId(), timestamp(0), type(), userId(), appId(), clusterId(),
      b_contentType(false), b_contentEncoding(false), b_headers(false),
      b_deliveryMode(false), b_priority(false), b_correlationId(false),
      b_replyTo(false), b_expiration(false), b_messageId(false),
      b_timestamp(false), b_type(false), b_userId(false), b_appId(false),
      b_clusterId(false) {
}

void AMQPBasicProperties::Populate(idMQFrame& frame) {
    b_contentType = frame.ReadPropertyPresence();
    b_contentEncoding = frame.ReadPropertyPresence();
    b_headers = frame.ReadPropertyPresence();
    b_deliveryMode = frame.ReadPropertyPresence();
    b_priority = frame.ReadPropertyPresence();
    b_correlationId = frame.ReadPropertyPresence();
    b_replyTo = frame.ReadPropertyPresence();
    b_expiration = frame.ReadPropertyPresence();
    b_messageId = frame.ReadPropertyPresence();
    b_timestamp = frame.ReadPropertyPresence();
    b_type = frame.ReadPropertyPresence();
    b_userId = frame.ReadPropertyPresence();
    b_appId = frame.ReadPropertyPresence();
    b_clusterId = frame.ReadPropertyPresence();
    frame.FinalizeReadPresence();
    if (b_contentType) contentType = frame.ReadShortString();
    if (b_contentEncoding) contentEncoding = frame.ReadShortString();
    if (b_headers) frame.ReadTable(headers);
    if (b_deliveryMode) deliveryMode = frame.ReadByte();
    if (b_priority) priority = frame.ReadByte();
    if (b_correlationId) correlationId = frame.ReadShortString();
    if (b_replyTo) replyTo = frame.ReadShortString();
    if (b_expiration) expiration = frame.ReadShortString();
    if (b_messageId) messageId = frame.ReadShortString();
    if (b_timestamp) timestamp = frame.ReadUInt64();
    if (b_type) type = frame.ReadShortString();
    if (b_userId) userId = frame.ReadShortString();
    if (b_appId) appId = frame.ReadShortString();
    if (b_clusterId) clusterId = frame.ReadShortString();
}

void AMQPBasicProperties::ToFrame(idMQFrame& frame) {
    frame.WritePropertyPresence(b_contentType);
    frame.WritePropertyPresence(b_contentEncoding);
    frame.WritePropertyPresence(b_headers);
    frame.WritePropertyPresence(b_deliveryMode);
    frame.WritePropertyPresence(b_priority);
    frame.WritePropertyPresence(b_correlationId);
    frame.WritePropertyPresence(b_replyTo);
    frame.WritePropertyPresence(b_expiration);
    frame.WritePropertyPresence(b_messageId);
    frame.WritePropertyPresence(b_timestamp);
    frame.WritePropertyPresence(b_type);
    frame.WritePropertyPresence(b_userId);
    frame.WritePropertyPresence(b_appId);
    frame.WritePropertyPresence(b_clusterId);
    frame.FinalizeWritePresence();
    if (b_contentType) frame.WriteShortString(contentType);
    if (b_contentEncoding) frame.WriteShortString(contentEncoding);
    if (b_headers) frame.WriteTable(headers);
    if (b_deliveryMode) frame.WriteByte(deliveryMode);
    if (b_priority) frame.WriteByte(priority);
    if (b_correlationId) frame.WriteShortString(correlationId);
    if (b_replyTo) frame.WriteShortString(replyTo);
    if (b_expiration) frame.WriteShortString(expiration);
    if (b_messageId) frame.WriteShortString(messageId);
    if (b_timestamp) frame.WriteUInt64(timestamp);
    if (b_type) frame.WriteShortString(type);
    if (b_userId) frame.WriteShortString(userId);
    if (b_appId) frame.WriteShortString(appId);
    if (b_clusterId) frame.WriteShortString(clusterId);
}

#undef EMPTY_METHOD
