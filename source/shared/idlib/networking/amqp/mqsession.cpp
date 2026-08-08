#include "mqmessaging.h"

#include <algorithm>

idMQSession::idMQSession(const int number, idMQConnection* owner)
    : connection(owner), cmdBuilder(), protocol(nullptr), currentCommand(),
      channelNumber(number), isOpen(false) {
}

idMQSession::~idMQSession() {
    currentCommand.Reset();
    delete protocol;
}

void idMQSession::Init(const bool connectionChannel) {
    if (protocol == nullptr) protocol = new idMQChannel(this);
    protocol->Init();
    isOpen = true;
    if (!connectionChannel) protocol->ChannelOpen();
}

void idMQSession::Close() {
    Close("client shutdown", MQERROR_NONE, true);
}

void idMQSession::Close(const char*, const MQErrors_t, const bool notifyServer) {
    if (!isOpen) return;
    if (notifyServer && channelNumber != 0 && protocol != nullptr) {
        AMQPChannelClose request;
        request.replyCode = 200;
        request.replyText = "Goodbye";
        idMQCommand command;
        command.method = &request;
        SendCommand(command);
    }
    isOpen = false;
}

void idMQSession::HandleFrame(idMQFrame& frame) {
    const MQErrors_t error = cmdBuilder.HandleFrame(currentCommand, frame);
    if (error != MQERROR_NONE) {
        Close("invalid frame", error, false);
        currentCommand.Reset();
        return;
    }
    if (currentCommand.complete) {
        const MQErrors_t result = protocol == nullptr
            ? MQERROR_UNKNOWN : protocol->HandleCommand(currentCommand);
        if (result != MQERROR_NONE && result != MQERROR_SERVER_CLOSED) {
            Close("command handling failed", result, false);
        }
        currentCommand.Reset();
    }
}

void idMQSession::SendCommand(idMQCommand& command) {
    if (connection == nullptr || command.method == nullptr) return;
    idMQFrame methodFrame(AMQP_FRAME_METHOD,
        static_cast<unsigned short>(channelNumber));
    methodFrame.WriteUInt16(command.method->GetClassId());
    methodFrame.WriteUInt16(command.method->GetMethodId());
    command.method->ToFrame(methodFrame);
    connection->SendFrame(methodFrame);

    if (!command.method->HasContent() || command.contentHeader == nullptr) return;
    command.contentHeader->bodyLength = command.contentBody.Num();
    idMQFrame headerFrame(AMQP_FRAME_HEADER,
        static_cast<unsigned short>(channelNumber));
    headerFrame.WriteUInt16(command.contentHeader->GetProtocolId());
    headerFrame.WriteUInt16(0);
    headerFrame.WriteUInt64(command.contentHeader->bodyLength);
    command.contentHeader->ToFrame(headerFrame);
    connection->SendFrame(headerFrame);

    const unsigned int maximum = connection->frameMaxSize > 8
        ? connection->frameMaxSize - 8 : 131064;
    int offset = 0;
    while (offset < command.contentBody.Num()) {
        const int amount = std::min(command.contentBody.Num() - offset,
            static_cast<int>(maximum));
        idMQFrame bodyFrame(AMQP_FRAME_BODY,
            static_cast<unsigned short>(channelNumber));
        bodyFrame.WriteData(command.contentBody.Ptr() + offset, amount);
        connection->SendFrame(bodyFrame);
        offset += amount;
    }
}

idMQSessionManager::idMQSessionManager(idMQConnection* owner)
    : initialized(false), connection(owner), maxSessions(0), sessionList() {
}

idMQSessionManager::~idMQSessionManager() { Shutdown(); }

void idMQSessionManager::Init(const int maximumSessions) {
    Shutdown();
    maxSessions = maximumSessions <= 0 ? 65535 : maximumSessions;
    initialized = true;
}

void idMQSessionManager::Shutdown() {
    for (int index = 0; index < sessionList.Num(); ++index) {
        delete sessionList[index];
    }
    sessionList.Clear();
    initialized = false;
}

idMQSession* idMQSessionManager::CreateSession() {
    if (!initialized || sessionList.Num() >= maxSessions) return nullptr;
    int number = 1;
    while (Lookup(number) != nullptr) ++number;
    idMQSession* session = new idMQSession(number, connection);
    sessionList.Append(session);
    session->Init(false);
    return session;
}

idMQSession* idMQSessionManager::Lookup(const int number) {
    for (int index = 0; index < sessionList.Num(); ++index) {
        if (sessionList[index] != nullptr
                && sessionList[index]->channelNumber == number) {
            return sessionList[index];
        }
    }
    return nullptr;
}
