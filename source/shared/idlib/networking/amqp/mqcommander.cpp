#include "mqmessaging.h"

idMQCommand::idMQCommand()
    : method(nullptr), contentHeader(nullptr), complete(false), contentBody(16),
      remainingBodyBytes(0) {
}

idMQCommand::~idMQCommand() = default;

void idMQCommand::Reset() {
    delete method;
    delete contentHeader;
    method = nullptr;
    contentHeader = nullptr;
    complete = false;
    contentBody.Clear();
    remainingBodyBytes = 0;
}

idMQCommandBuilder::idMQCommandBuilder()
    : state(MQ_CMDSTATE_NEED_METHOD), remainingBytes(0) {
}

MQErrors_t idMQCommandBuilder::HandleFrame(idMQCommand& command,
        idMQFrame& frame) {
    if (state == MQ_CMDSTATE_NEED_METHOD) {
        if (frame.type != AMQP_FRAME_METHOD) return MQERROR_INVALID_FRAME;
        command.method = idMQChannel::DecodeMethod(frame);
        if (command.method == nullptr) return MQERROR_UNEXPECTED_METHOD;
        state = command.method->HasContent()
            ? MQ_CMDSTATE_NEED_HEADER : MQ_CMDSTATE_COMPLETE;
    } else if (state == MQ_CMDSTATE_NEED_HEADER) {
        if (frame.type != AMQP_FRAME_HEADER) return MQERROR_INVALID_FRAME;
        command.contentHeader = idMQChannel::DecodeContentHeader(frame);
        if (command.contentHeader == nullptr) return MQERROR_UNEXPECTED_CLASS;
        command.remainingBodyBytes = command.contentHeader->bodyLength;
        state = command.remainingBodyBytes == 0
            ? MQ_CMDSTATE_COMPLETE : MQ_CMDSTATE_NEED_BODY;
    } else if (state == MQ_CMDSTATE_NEED_BODY) {
        if (frame.type != AMQP_FRAME_BODY) return MQERROR_INVALID_FRAME;
        if (static_cast<std::uint64_t>(frame.data.Num())
                > command.remainingBodyBytes) return MQERROR_FRAME_OVERFLOW;
        for (int index = 0; index < frame.data.Num(); ++index) {
            command.contentBody.Append(frame.data[index]);
        }
        command.remainingBodyBytes -= frame.data.Num();
        if (command.remainingBodyBytes == 0) state = MQ_CMDSTATE_COMPLETE;
    } else {
        return MQERROR_UNKNOWN;
    }

    command.complete = state == MQ_CMDSTATE_COMPLETE;
    if (command.complete) {
        state = MQ_CMDSTATE_NEED_METHOD;
        remainingBytes = 0;
    }
    return MQERROR_NONE;
}
