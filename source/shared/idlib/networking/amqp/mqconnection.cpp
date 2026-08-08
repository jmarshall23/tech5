#include "mqmessaging.h"

#ifdef nullptr
#undef nullptr
#endif

#include <cstring>

idMQConnection::idMQConnection()
    : frameMaxSize(131072), knownHosts(), framer(nullptr),
      sessionManager(nullptr), sessionZero(nullptr), terminateConnection(false),
      connectionTerminated(true), isClosing(false), threadHandle(0),
      shutdownReason() {
}

idMQConnection::~idMQConnection() {
    Close();
    delete sessionZero;
    delete sessionManager;
    delete framer;
}

void idMQConnection::Init(amqpEndpoint_t& endpoint) {
    Close();
    delete sessionZero;
    delete sessionManager;
    delete framer;
    framer = new idMQFrameHandler(endpoint);
    sessionManager = new idMQSessionManager(this);
    sessionZero = new idMQSession(0, this);
    sessionZero->Init(true);
    frameMaxSize = endpoint.frameMax == 0 ? 131072 : endpoint.frameMax;
    shutdownReason = amqpShutdownReason_t();
}

void idMQConnection::CreateThread() {
    terminateConnection = false;
    connectionTerminated = false;
    threadHandle = static_cast<unsigned int>(Sys_CreateThread(
        StaticThread, this, THREAD_LOWEST, "AMQP Connection", CORE_ANY,
        0x20000, false));
}

unsigned int idMQConnection::StaticThread(void* value) {
    static_cast<idMQConnection*>(value)->MessageThread();
    return 0;
}

void idMQConnection::MessageThread() {
    while (!terminateConnection && framer != nullptr && framer->tcp.IsOpen()) {
        idMQFrame frame;
        if (framer->ReadFrame(frame) < 0) break;
        idMQSession* session = frame.channel == 0 ? sessionZero
            : sessionManager == nullptr ? nullptr
                : sessionManager->Lookup(frame.channel);
        if (session == nullptr) {
            shutdownReason.error = MQERROR_SESSION_NOT_FOUND;
            shutdownReason.replyText = "AMQP session not found";
            break;
        }
        session->HandleFrame(frame);
    }
    connectionTerminated = true;
}

bool idMQConnection::OpenCommunications() {
    if (framer == nullptr || sessionZero == nullptr || sessionZero->protocol == nullptr
            || !framer->SendHeader()) return false;
    AMQPConnectionStart start;
    if (!sessionZero->protocol->deferredConnectionStart.GetValue(start)) {
        shutdownReason.error = MQERROR_CONNECTION_START;
        shutdownReason.replyText = "Unable to get ConnectionStart details";
        return false;
    }
    if (start.versionMajor != 8 || start.versionMinor != 0) {
        shutdownReason.error = MQERROR_BAD_SPEC_VERSION;
        shutdownReason.replyText = "AMQP protocol version mismatch";
        return false;
    }

    idMQList<unsigned char> response(16);
    response.Append(0);
    const char* username = framer->endpoint.username.c_str();
    for (int i = 0; username[i] != 0; ++i) response.Append(username[i]);
    response.Append(0);
    const char* password = framer->endpoint.password.c_str();
    for (int i = 0; password[i] != 0; ++i) response.Append(password[i]);

    AMQPConnectionTune tune;
    sessionZero->protocol->ConnectionStartOk(tune, idStr("PLAIN"), response,
        idStr("en_US"));
    if (tune.frameMax == 0 && tune.channelMax == 0 && tune.heartbeat == 0) {
        shutdownReason.error = MQERROR_AUTH_FAILED;
        shutdownReason.replyText = "AMQP authentication/tuning failed";
        return false;
    }
    const unsigned short channelMax = framer->endpoint.channelMax == 0
        ? tune.channelMax : framer->endpoint.channelMax;
    const unsigned int frameMax = framer->endpoint.frameMax == 0
        ? tune.frameMax : framer->endpoint.frameMax;
    const unsigned short heartbeat = framer->endpoint.heartbeat == 0
        ? tune.heartbeat : framer->endpoint.heartbeat;
    frameMaxSize = frameMax == 0 ? 131072 : frameMax;
    sessionManager->Init(channelMax);
    sessionZero->protocol->ConnectionTuneOk(channelMax, frameMax, heartbeat);
    idStr hosts;
    sessionZero->protocol->ConnectionOpen(hosts, framer->endpoint.vhost,
        idStr(""), false);
    if (connectionTerminated) return false;
    knownHosts.Clear();
    const char* cursor = hosts.c_str();
    while (*cursor != 0) {
        while (*cursor == ' ') ++cursor;
        const char* begin = cursor;
        while (*cursor != 0 && *cursor != ' ') ++cursor;
        if (cursor != begin) {
            idStr host;
            host.Append(begin, static_cast<int>(cursor - begin));
            knownHosts.Append(host);
        }
    }
    return true;
}

bool idMQConnection::Connect() {
    if (framer == nullptr || !framer->Connect()) return false;
    CreateThread();
    if (!OpenCommunications()) {
        Close(shutdownReason);
        return false;
    }
    connectionTerminated = false;
    return true;
}

void idMQConnection::SendFrame(idMQFrame& frame) {
    if (framer == nullptr || framer->SendFrame(frame) < 0) {
        shutdownReason.error = MQERROR_STREAM_ERROR;
        shutdownReason.replyText = "AMQP stream write failed";
        connectionTerminated = true;
    }
}

idMQChannel* idMQConnection::GetChannel() {
    if (sessionManager == nullptr || connectionTerminated) return nullptr;
    idMQSession* session = sessionManager->CreateSession();
    return session == nullptr ? nullptr : session->protocol;
}

void idMQConnection::Close(const char* reason, const MQErrors_t error) {
    amqpShutdownReason_t value;
    value.error = error;
    value.replyText = reason == nullptr ? "" : reason;
    Close(value);
}

void idMQConnection::Close(amqpShutdownReason_t& reason) {
    if (isClosing) return;
    isClosing = true;
    shutdownReason = reason;
    if (!connectionTerminated && sessionZero != nullptr
            && sessionZero->protocol != nullptr && reason.error == MQERROR_NONE) {
        sessionZero->protocol->ConnectionClose(200, idStr("Goodbye"), 0, 0);
    }
    terminateConnection = true;
    if (framer != nullptr) framer->Close();
    if (threadHandle != 0
            && Sys_GetCurrentThreadID() != static_cast<uintptr_t>(threadHandle)) {
        Sys_WaitForThread(static_cast<uintptr_t>(threadHandle));
        Sys_DestroyThread(static_cast<uintptr_t>(threadHandle));
    }
    threadHandle = 0;
    if (sessionManager != nullptr) sessionManager->Shutdown();
    connectionTerminated = true;
    isClosing = false;
}

void idMQConnection::Close() {
    amqpShutdownReason_t reason;
    Close(reason);
}
