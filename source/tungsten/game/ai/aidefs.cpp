#include "aidefs.h"

// Runtime-owned state exposed until idClientGame/idGameLocal are recovered.
unsigned int& Tungsten_GetAIRandomSeed();
int Tungsten_GetAIGameMilliseconds();
int Tungsten_GetAIGameMillisecondsPerRealSecond();

namespace {

constexpr unsigned int RANDOM_MULTIPLIER = 1664525u;
constexpr unsigned int RANDOM_INCREMENT = 1013904223u;
constexpr float RANDOM_FLOAT_SCALE = 1.0f / 32767.0f;

int NextRandom15() {
    unsigned int& seed = Tungsten_GetAIRandomSeed();
    seed = RANDOM_MULTIPLIER * seed + RANDOM_INCREMENT;
    return static_cast<int>((seed >> 10) & 0x7FFFu);
}

} // namespace

// Retail symbol: ?GetEndTimeByFrames@@YAHH@Z
// EA: 0x82A42788, RVA: 0x00A42788
int GetEndTimeByFrames(const int frameCount) {
    if (frameCount <= 0) {
        return 0;
    }
    return Tungsten_GetAIGameMilliseconds()
        + Tungsten_GetAIGameMillisecondsPerRealSecond() * frameCount / 30;
}

// Retail symbol: ?GetRandomInterval@@YAHHH@Z
// EA: 0x82A42810, RVA: 0x00A42810
int GetRandomInterval(const int minValue, const int maxValue) {
    return maxValue > minValue
        ? minValue + NextRandom15() % (maxValue - minValue)
        : minValue;
}

// Retail symbol: ?GetRandomInterval@@YAMMM@Z
// EA: 0x82A42880, RVA: 0x00A42880
float GetRandomInterval(const float minValue, const float maxValue) {
    return maxValue > minValue
        ? minValue + static_cast<float>(NextRandom15())
            * (maxValue - minValue) * RANDOM_FLOAT_SCALE
        : minValue;
}

// Retail symbol: ?GetRandomIntervalBySeconds@@YAHMM@Z
// EA: 0x82A428E0, RVA: 0x00A428E0
int GetRandomIntervalBySeconds(
        const float minSeconds, const float maxSeconds) {
    const float seconds = minSeconds + static_cast<float>(NextRandom15())
        * (maxSeconds - minSeconds) * RANDOM_FLOAT_SCALE;
    return static_cast<int>(static_cast<float>(
        Tungsten_GetAIGameMillisecondsPerRealSecond()) * seconds);
}

// Retail symbol: ?RandomInt@@YAHH@Z
// EA: 0x82A42990, RVA: 0x00A42990
int RandomInt(const int maxValue) {
    return maxValue != 0 ? NextRandom15() % maxValue : 0;
}

// Retail symbol: ?RandomInt@@YAHHH@Z
// EA: 0x82A429F0, RVA: 0x00A429F0
int RandomInt(const int minValue, const int maxValue) {
    return minValue < maxValue
        ? minValue + NextRandom15() % (maxValue - minValue + 1)
        : minValue;
}

// Retail symbol: ?RandomFloat@@YAMXZ
// EA: 0x82A42A58, RVA: 0x00A42A58
float RandomFloat() {
    return static_cast<float>(NextRandom15()) * RANDOM_FLOAT_SCALE;
}

// Retail symbol: ?RandomFloat@@YAMM@Z
// EA: 0x82A42AA8, RVA: 0x00A42AA8
float RandomFloat(const float maxValue) {
    return static_cast<float>(NextRandom15()) * maxValue * RANDOM_FLOAT_SCALE;
}

// Retail symbol: ?RandomFloat@@YAMMM@Z
// EA: 0x82A42AF8, RVA: 0x00A42AF8
float RandomFloat(const float minValue, const float maxValue) {
    return minValue + static_cast<float>(NextRandom15())
        * (maxValue - minValue) * RANDOM_FLOAT_SCALE;
}

// Retail symbol:
// ?SecondsToTicks@@YA?AV?$idTypesafeNumber@HW4gameTimeUnique_t@@@@M@Z
// EA: 0x82A42B50, RVA: 0x00A42B50
gameTime_t SecondsToTicks(const float seconds) {
    return gameTime_t(static_cast<int>(static_cast<float>(
        Tungsten_GetAIGameMillisecondsPerRealSecond()) * seconds));
}
