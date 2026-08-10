#pragma once

#include "idlib/math/vector.h"

enum navVolumeFlags_t : int {
    NavVolumeNone = 0,
    NavVolumeFly = 1,
    NavVolumeLand = 2,
    NavVolumeDefault = 3,
    NavVolumeAll = 0xFFFFFF
};

enum navProbeResult_t : int {
    PROBE_HIT = 0,
    PROBE_NOHIT = 1
};

struct TungstenNavProbe3DRawResults {
    idVec3 endPos;
    idVec3 endNorm;
    bool collided;
    float distTravelled;
};

bool Tungsten_AnyNavigationVolumesLoaded();
TungstenNavProbe3DRawResults Tungsten_NavigationProbe3D(
    navVolumeFlags_t useVolumes, const idVec3& start,
    const idVec3& direction, float distance);

class idNpMover3D {
public:
    struct idProbeInput3D {
        navVolumeFlags_t useVolumes;
    };

    struct idProbeResults3D {
        idVec3 endPos;
        idVec3 endNorm;
        bool collided;
        float distTotal;
        float distTravelled;
        float distFraction;
    };

    static navProbeResult_t NavProbe3D(const idProbeInput3D& input,
        const idVec3& start, const idVec3& end, idProbeResults3D& results);

    void* impl;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idNpMover3D::idProbeInput3D) == 4,
    "Recovered 3D probe input ABI changed");
static_assert(sizeof(idNpMover3D::idProbeResults3D) == 40,
    "Recovered 3D probe results ABI changed");
static_assert(sizeof(idNpMover3D) == 4,
    "Recovered NavPower 3D mover ABI changed");
#endif
