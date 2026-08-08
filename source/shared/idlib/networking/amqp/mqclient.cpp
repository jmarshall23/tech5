#include "mqmessaging.h"

#ifdef nullptr
#undef nullptr
#endif
#ifdef snprintf
#undef snprintf
#endif

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

idMQGraphiteClient::idMQGraphiteClient(const idStr& exchangeName,
        const idStr& metricPrefix)
    : idMQClientThread(), reportTime(0), channel(nullptr), outgoingEvents(),
      exchange(exchangeName), prefix(metricPrefix), threadMutex() {
}

idMQGraphiteClient::~idMQGraphiteClient() {
    StopThread(true);
    for (int index = 0; index < outgoingEvents.Num(); ++index) {
        std::free(const_cast<char*>(outgoingEvents[index].eventName));
    }
}

void idMQGraphiteClient::StartMessageSystem() {
    StartThread("AMQP Graphite Client");
}

void idMQGraphiteClient::PreRun() {
    channel = connection.GetChannel();
    if (channel != nullptr) {
        channel->ExchangeDeclare(exchange, idStr("topic"), true, false);
    }
    reportTime = static_cast<int>(GetTickCount()) + 10000;
}

void idMQGraphiteClient::OnThreadTerminate() { channel = nullptr; }

void idMQGraphiteClient::LogEvent(const idStr& eventName,
        const float duration) {
    idScopedCriticalSection lock(threadMutex);
    for (int index = 0; index < outgoingEvents.Num(); ++index) {
        graphiteEvent_t& event = outgoingEvents[index];
        if (_stricmp(event.eventName, eventName.c_str()) == 0) {
            ++event.count;
            event.duration += duration;
            event.mean += (duration - event.mean) / event.count;
            event.mean2 += duration * duration;
            return;
        }
    }
    graphiteEvent_t event = {};
    event.eventName = _strdup(eventName.c_str());
    event.count = 1;
    event.duration = duration;
    event.mean = duration;
    event.mean2 = duration * duration;
    outgoingEvents.Append(event);
}

void idMQGraphiteClient::ThreadSlice() {
    if (static_cast<int>(GetTickCount()) < reportTime) {
        Sleep(10);
        return;
    }
    idMQList<graphiteEvent_t> events;
    {
        idScopedCriticalSection lock(threadMutex);
        events = outgoingEvents;
        outgoingEvents.Clear();
    }
    const long long timestamp = static_cast<long long>(std::time(nullptr));
    static const char* const names[] = { "rate", "avg", "std" };
    for (int index = 0; index < events.Num(); ++index) {
        const graphiteEvent_t& event = events[index];
        const float values[] = {
            event.duration,
            event.mean,
            event.count == 0 ? 0.0f
                : std::sqrt(event.mean2 / static_cast<float>(event.count))
        };
        for (int metric = 0; metric < 3; ++metric) {
            char line[2048];
            const int amount = std::snprintf(line, sizeof(line),
                "%s.%s.%s %g %lld", prefix.c_str(), event.eventName,
                names[metric], values[metric], timestamp);
            if (channel != nullptr && amount > 0) {
                channel->BasicPublish(exchange, prefix, false, false, line,
                    static_cast<unsigned int>(amount));
            }
        }
        std::free(const_cast<char*>(event.eventName));
    }
    reportTime = static_cast<int>(GetTickCount()) + 10000;
}
