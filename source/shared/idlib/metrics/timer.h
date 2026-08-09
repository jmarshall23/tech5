#pragma once

#include "idlib/text/str.h"

#include <chrono>
#include <cstdint>

class idTimer {
public:
    enum timerState_t : int { TS_STARTED = 0, TS_STOPPED = 1 };

    idTimer() : state(TS_STOPPED), start(0), clockTicks(0) {}
    virtual ~idTimer() = default;

    void Start() { state = TS_STARTED; start = ClockNow(); }
    void Stop() {
        if (state != TS_STARTED) return;
        clockTicks += ClockNow() - start;
        if (baseClockTicks < 0) InitBaseClockTicks();
        if (clockTicks > baseClockTicks) clockTicks -= baseClockTicks;
        state = TS_STOPPED;
    }
    void Clear() { state = TS_STOPPED; start = 0; clockTicks = 0; }
    std::int64_t ClockTicks() const { return clockTicks; }
    double Milliseconds() const { return static_cast<double>(clockTicks) / 1000000.0; }

    alignas(8) timerState_t state;
    std::int64_t start;
    std::int64_t clockTicks;

private:
    static std::int64_t baseClockTicks;
    void InitBaseClockTicks() const;

    static std::int64_t ClockNow() {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count();
    }
};

class idJobTimer {
public:
    idStr name;
    int start;
    int ends;
};

class idSPUTimer {
public:
    unsigned int startDecr;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idTimer) == 32, "Recovered idTimer ABI changed");
static_assert(sizeof(idJobTimer) == 40, "Recovered idJobTimer ABI changed");
static_assert(sizeof(idSPUTimer) == 4, "Recovered idSPUTimer ABI changed");
#endif
