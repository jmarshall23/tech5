#include "timer.h"

#include <limits>

std::int64_t idTimer::baseClockTicks = -1;

void idTimer::InitBaseClockTicks() const {
    std::int64_t best = (std::numeric_limits<std::int64_t>::max)();
    // The recovered function calibrates the minimum empty Start/Stop cost.
    for (int iteration = 0; iteration < 1000; ++iteration) {
        const std::int64_t begin = ClockNow();
        const std::int64_t elapsed = ClockNow() - begin;
        if (elapsed < best) best = elapsed;
    }
    baseClockTicks = best == (std::numeric_limits<std::int64_t>::max)()
        ? 0 : best;
}
