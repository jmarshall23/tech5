#pragma once

struct TungstenSoundRandomValue {
    float min;
    float max;
    float granularity;
};

struct TungstenSoundShaderParms {
    struct ConeAttenuation {
        float innerAngle;
        float outerAngle;
        float outerVolume;
    };
    struct DistanceRanges {
        float nearMinRange;
        float farMaxRange;
    };
    struct MaxPlay {
        int maxShaders;
        int playbackType;
    };

    float minDistance;
    float maxDistance;
    float distanceFactor;
    float wetMinDistanceOffset;
    float wetMaxDistanceOffset;
    ConeAttenuation coneAttenuation;
    DistanceRanges distanceBasedRanges;
    TungstenSoundRandomValue volume;
    float wetVolume;
    TungstenSoundRandomValue pitch;
    float loopFadeInDuration;
    float loopFadeOutDuration;
    float dopplerMultiplier;
    float shakes;
    float minShakeDistance;
    float maxShakeDistance;
    const void* shakeFalloff;
    int groups;
    int soundChannel;
    int soundShaderFlags;
    float lowPassMinDistance;
    float lowPassStrength;
    float lfeVolume;
    float centerChannel;
    const void* falloff;
    const void* wetFalloff;
    float headroom;
    MaxPlay maxPlay;
    int priority;

    void Clear() {
        *this = {};
        minDistance = 128.0f;
        maxDistance = 1024.0f;
        distanceFactor = 1.0f;
        pitch.min = 1.0f;
        pitch.max = 1.0f;
        lfeVolume = -6.0f;
        priority = 1; // SPRIORITY_MEDIUM
        maxPlay.playbackType = 0; // SMAX_IGNORE
    }
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(TungstenSoundShaderParms) == 148,
    "Recovered sound parameter ABI changed");
#endif
