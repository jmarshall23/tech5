#include "sys_time.h"

#include <algorithm>
#include <chrono>
#include <cstdio>
#include <ctime>

#if defined(_WIN32)
#include <Windows.h>
#endif

namespace {
thread_local char timeString[128];

bool LocalTime(const std::time_t value, std::tm& output) {
#if defined(_WIN32)
    return localtime_s(&output, &value) == 0;
#else
    return localtime_r(&value, &output) != nullptr;
#endif
}
}

std::uint64_t Sys_CurrentSystemTime() {
#if defined(_WIN32)
    FILETIME fileTime;
    GetSystemTimeAsFileTime(&fileTime);
    return (static_cast<std::uint64_t>(fileTime.dwHighDateTime) << 32)
        | static_cast<std::uint64_t>(fileTime.dwLowDateTime);
#else
    constexpr std::uint64_t windowsEpochOffset = 116444736000000000ULL;
    const auto ticks = std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    ).count() / 100;
    return windowsEpochOffset + static_cast<std::uint64_t>(ticks);
#endif
}

char* Sys_TimeStampToLogFormat(const int timeStamp) {
    timeString[0] = '\0';
    if (timeStamp == -1) {
        return timeString;
    }
    const std::time_t source = static_cast<std::time_t>(timeStamp);
    std::tm local = {};
    if (LocalTime(source, local)) {
        std::snprintf(timeString, sizeof(timeString),
            "%d-%02d-%02dT%02d:%02d:%02dZ",
            local.tm_year + 1900, local.tm_mon + 1, local.tm_mday,
            local.tm_hour, local.tm_min, local.tm_sec);
    }
    return timeString;
}

char* Sys_TimeStampToStr(const int timeStamp, const bool padded) {
    timeString[0] = '\0';
    if (timeStamp == -1) {
        return timeString;
    }
    const std::time_t source = static_cast<std::time_t>(timeStamp);
    std::tm local = {};
    if (!LocalTime(source, local)) {
        return timeString;
    }

    int hour = local.tm_hour % 12;
    if (hour == 0) {
        hour = 12;
    }
    if (padded) {
        std::snprintf(timeString, sizeof(timeString),
            "%02d/%02d/%d  %02d:%02d:%02d%s",
            local.tm_mon + 1, local.tm_mday, local.tm_year + 1900,
            hour, local.tm_min, local.tm_sec,
            local.tm_hour < 12 ? "am" : "pm");
    } else {
        std::snprintf(timeString, sizeof(timeString),
            "%d/%d/%d  %d:%02d:%02d%s",
            local.tm_mon + 1, local.tm_mday, local.tm_year + 1900,
            hour, local.tm_min, local.tm_sec,
            local.tm_hour < 12 ? "am" : "pm");
    }
    return timeString;
}

char* Sys_DateStr(const bool padded) {
    return Sys_TimeStampToStr(static_cast<int>(std::time(nullptr)), padded);
}

idStr Sys_SecToStr(int seconds) {
    idStr result;
    if (seconds < 0) {
        seconds = 0;
    }
    char buffer[32];
    const int weeks = seconds / 604800;
    if (weeks > 0) {
        std::snprintf(buffer, sizeof(buffer), "%dw, ", weeks);
        result.Append(buffer);
        seconds %= 604800;
    }
    const int days = seconds / 86400;
    if (weeks > 0 || days > 0) {
        std::snprintf(buffer, sizeof(buffer), "%dd, ", days);
        result.Append(buffer);
        seconds %= 86400;
    }
    const int hours = seconds / 3600;
    const int minutes = (seconds % 3600) / 60;
    const int remainingSeconds = seconds % 60;
    std::snprintf(buffer, sizeof(buffer), "%d:%02d:%02d",
        hours, minutes, remainingSeconds);
    result.Append(buffer);
    return result;
}
