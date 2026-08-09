#pragma once

#include "idlib/containers/sort.h"

#include <cstdint>

// The owning game component is recovered later.  This exact event record is
// sufficient for GameLib's sorter and preserves the 168-byte PC layout of
// the nested idComponentTimeLine::idTimeLineEvent type.
class idComponentTimeLine {
public:
    struct idTimeLineEvent {
        std::uint16_t eventTime;
        std::uint8_t eventCall[166];
    };
};

class idSort_TimeLineEvent
    : public idSort<idComponentTimeLine::idTimeLineEvent> {
public:
    void Sort(idComponentTimeLine::idTimeLineEvent* events,
            const unsigned int count) override {
        if (events == nullptr || count < 2) return;
        for (unsigned int index = 1; index < count; ++index) {
            idComponentTimeLine::idTimeLineEvent value = events[index];
            unsigned int insertion = index;
            while (insertion > 0 &&
                    events[insertion - 1].eventTime > value.eventTime) {
                events[insertion] = events[insertion - 1];
                --insertion;
            }
            events[insertion] = value;
        }
    }
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idComponentTimeLine::idTimeLineEvent) == 168,
    "Recovered timeline-event ABI changed");
static_assert(sizeof(idSort_TimeLineEvent) == 4,
    "Recovered timeline sorter ABI changed");
#endif
