#include "framework/gametimemanager.h"

#include "framework/timemanager.h"

#include <algorithm>
#include <cmath>

namespace {
int TimeIndex(const gameTimeType_t type) {
    return type == GAMETIME_SCALED ? 1 : 0;
}
}

idGameTimeManager::idGameTimeManager() {
    Clear();
}

void idGameTimeManager::UpdateGameFrame() {
    ++framenum;
}

void idGameTimeManager::SetTimeScale(const float newScale,
        const gameTimeType_t type) {
    const int index = TimeIndex(type);
    useInterpolator = false;
    scale[index] = std::max(0.0f, newScale);
    inSlowMotion = scale[1] < 1.0f;
}

void idGameTimeManager::UpdateGameMs() {
    for (int index = 0; index < 2; ++index) {
        previousTime[index] = time[index];
        time[index] += ticks[index];
    }
}

void idGameTimeManager::SetGameHz(const int hertz) {
    timeManager.SetGameHz(hertz);
}

int idGameTimeManager::GetGameMs(const gameTimeType_t type) const {
    return time[TimeIndex(type)];
}

int idGameTimeManager::GetPreviousGameMs(const gameTimeType_t type) const {
    return previousTime[TimeIndex(type)];
}

int idGameTimeManager::GetGameMsPerFrame(const gameTimeType_t type) const {
    return ticks[TimeIndex(type)];
}

float idGameTimeManager::GetRealMsPerFrame(const gameTimeType_t type) const {
    return timeDelta[TimeIndex(type)];
}

int idGameTimeManager::GetGameHz(const gameTimeType_t type) const {
    return hz[TimeIndex(type)];
}

float idGameTimeManager::GetTimeScale(const gameTimeType_t type) const {
    return scale[TimeIndex(type)];
}

void idGameTimeManager::SetGameMs(const int newTime) {
    for (int index = 0; index < 2; ++index) {
        time[index] = newTime;
        previousTime[index] = newTime - timeManager.gameTimePerFrame.value;
    }
}

void idGameTimeManager::StartSlowmotion(const slowmoParms_t& parms) {
    slowmoParms = parms;
    slowmoDuration = std::max(0.0f, parms.slowmoDuration);
    inSlowMotion = 1;
    useInterpolator = true;
    timeScaleExtrapolation[1].Init(static_cast<float>(time[0]),
        std::max(0.0f, parms.easeInDuration * 1000.0f), scale[1],
        std::max(0.0f, parms.timeScale));
}

void idGameTimeManager::StopSlowmotion() {
    const float now = static_cast<float>(time[0]);
    const float current = timeScaleExtrapolation[1].GetCurrentValue(now);
    timeScaleExtrapolation[1].Init(now,
        std::max(0.0f, slowmoParms.easeOutDuration * 1000.0f), current, 1.0f);
    slowmoDuration = 0.0f;
    inSlowMotion = 0;
    useInterpolator = true;
}

void idGameTimeManager::UpdateTimeScale() {
    hz[0] = timeManager.gameHz;
    ticks[0] = timeManager.gameTimePerFrame.value;
    timeDelta[0] = 1000.0f / static_cast<float>(std::max(1, hz[0]));

    if (useInterpolator) {
        scale[1] = timeScaleExtrapolation[1].GetCurrentValue(
            static_cast<float>(time[0]));
        if (timeScaleExtrapolation[1].IsDone(static_cast<float>(time[0]))) {
            useInterpolator = false;
        }
    }
    hz[1] = std::max(1, static_cast<int>(scale[1] * hz[0]));
    ticks[1] = std::max(0, static_cast<int>(scale[1] * ticks[0]));
    timeDelta[1] = 1000.0f / static_cast<float>(hz[1]);

    if (inSlowMotion && slowmoDuration > 0.0f && !useInterpolator) {
        slowmoDuration -= ticks[0] * 0.001f;
        if (slowmoDuration <= 0.0f) {
            StopSlowmotion();
        }
    }
}

idTypesafeNumber<int, millisecondUnique_t>
idGameTimeManager::ConvertTimeGameToReal(
        const idTypesafeNumber<int, gameTimeUnique_t> value) const {
    const float currentScale = std::max(scale[1], 0.0001f);
    return idTypesafeNumber<int, millisecondUnique_t>(
        static_cast<int>(value.value / currentScale));
}

idTypesafeNumber<int, gameTimeUnique_t>
idGameTimeManager::ConvertTimeRealToGame(
        const idTypesafeNumber<int, millisecondUnique_t> value) const {
    return idTypesafeNumber<int, gameTimeUnique_t>(
        static_cast<int>(value.value * scale[1]));
}

void idGameTimeManager::Clear() {
    framenum = 0;
    slowmoParms = {0.0f, 0.0f, 0.0f, 1.0f};
    reservedBits = 0;
    inSlowMotion = 0;
    useInterpolator = false;
    slowmoDuration = 0.0f;
    for (int index = 0; index < 2; ++index) {
        hz[index] = timeManager.gameHz;
        ticks[index] = timeManager.gameTimePerFrame.value;
        timeDelta[index] = 1000.0f / static_cast<float>(std::max(1, hz[index]));
        time[index] = 0;
        previousTime[index] = 0;
        scale[index] = 1.0f;
        timeScaleExtrapolation[index].Init(0.0f, 0.0f, 1.0f, 1.0f);
    }
}
