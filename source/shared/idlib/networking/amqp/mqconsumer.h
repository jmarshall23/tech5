#pragma once

#include "mqcommon.h"

class AMQPBasicProperties;

class idMQConsumer {
public:
    idMQConsumer() : consumerTag(), isConsuming(false), mutex() {}
    virtual ~idMQConsumer() = default;
    virtual void ProcessBasicConsumeOk(const idStr& tag) {
        idScopedCriticalSection lock(mutex);
        consumerTag = tag;
        isConsuming = true;
    }
    virtual void ProcessBasicCancel(const idStr&) {
        idScopedCriticalSection lock(mutex);
        isConsuming = false;
    }
    virtual void ProcessBasicCancelOk(const idStr& tag) {
        ProcessBasicCancel(tag);
    }
    virtual void ProcessBasicDeliver(const idStr& consumerTag,
        std::uint64_t deliveryTag, bool redelivered, const idStr& exchange,
        const idStr& routingKey, const AMQPBasicProperties* properties,
        const idMQList<unsigned char>& body) = 0;

    idStr consumerTag;
    bool isConsuming;
    idSysMutex mutex;
};
