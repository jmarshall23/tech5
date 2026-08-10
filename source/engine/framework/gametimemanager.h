#pragma once

#include "idlib/math/interpolate.h"
#include "idlib/typesafenumber.h"

enum gameTimeUnique_t : int;
enum millisecondUnique_t : int;

enum gameTimeType_t : int {
    GAMETIME_NORMAL = 0,
    GAMETIME_SCALED = 1,
    GAMETIME_TOTAL = 2
};

struct slowmoParms_t {
    float easeInDuration;
    float slowmoDuration;
    float easeOutDuration;
    float timeScale;
};

class idGameTimeManager {
public:
    idGameTimeManager();

    void UpdateGameFrame();
    void SetTimeScale(float newScale, gameTimeType_t type);
    void UpdateGameMs();
    static void SetGameHz(int hertz);
    int GetGameMs(gameTimeType_t type) const;
    int GetPreviousGameMs(gameTimeType_t type) const;
    int GetGameMsPerFrame(gameTimeType_t type) const;
    float GetRealMsPerFrame(gameTimeType_t type) const;
    int GetGameHz(gameTimeType_t type) const;
    float GetTimeScale(gameTimeType_t type) const;
    int GetFrameNum() const { return framenum; }
    void SetGameMs(int newTime);
    void StartSlowmotion(const slowmoParms_t& parms);
    void StopSlowmotion();
    void UpdateTimeScale();
    idTypesafeNumber<int, millisecondUnique_t> ConvertTimeGameToReal(
        idTypesafeNumber<int, gameTimeUnique_t> value) const;
    idTypesafeNumber<int, gameTimeUnique_t> ConvertTimeRealToGame(
        idTypesafeNumber<int, millisecondUnique_t> value) const;
    void Clear();

    int framenum;
    int hz[2];
    int ticks[2];
    float timeDelta[2];
    int time[2];
    int previousTime[2];
    float scale[2];
    idInterpolate<float> timeScaleExtrapolation[2];
    slowmoParms_t slowmoParms;
    unsigned char reservedBits : 7;
    unsigned char inSlowMotion : 1;
    bool useInterpolator;
    float slowmoDuration;
};

class idGameTimeManagerPtr {
public:
    idGameTimeManager* gameTimeManager;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(slowmoParms_t) == 16, "Recovered slowmoParms_t ABI changed");
static_assert(sizeof(idGameTimeManager) == 124,
    "Recovered idGameTimeManager ABI changed");
#endif
