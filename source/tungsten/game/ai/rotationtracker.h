#pragma once

#include "../decls/decltrackingparms.h"
#include "../../../shared/idlib/math/radians.h"
#include "../../../shared/idlib/math/vector.h"

class idRotationTrackerRange {
public:
    float minYaw;
    float maxYaw;
    float minPitch;
    float maxPitch;
};

class alignas(4) idRotationTracker {
public:
    idRotationTracker();
    virtual ~idRotationTracker();

    virtual void Update(const idVec3& rotationOrigin,
        const idMat3& referenceAxis, const idVec3& idealDirection,
        float deltaTime, bool force, int debugLevel);

    void GetWorldSpaceDir(const idMat3& referenceAxis, idVec3& result) const;
    void GetWorldSpaceAxis(const idMat3& referenceAxis, idMat3& result) const;
    void GetConstraints(idRotationTrackerRange& range) const;
    void SetConstraints(radians_t maxPitch_, radians_t maxYaw_);
    void SetConstraints(const idRotationTrackerRange& range);

    idQuat rot;
    radians_t maxPitch;
    radians_t maxYaw;
    float maxPitchDot;
    float maxYawDot;
    float halfMaxPitchDot;
    float halfMaxYawDot;
    radians_t maxVelocity;
    radians_t velocity;
    radians_t acceleration;
    radians_t deceleration;
    bool projectWhenBehind;
    bool clampedYaw;
    bool clampedPitch;
};

static_assert(sizeof(idRotationTrackerRange) == 16,
    "Recovered rotation-tracker range ABI changed");

class idAimTracker : public idRotationTracker {
public:
    idAimTracker();
    ~idAimTracker() override = default;

    void Update(const idVec3& rotationOrigin,
        const idMat3& referenceAxis, const idVec3& idealDirection,
        float deltaTime, bool force, int debugLevel) override;

    trackingParms_t curParms;
};

void Tungsten_DebugRotationTracker(const idRotationTracker& tracker,
    const idVec3& origin, const idVec3& desiredDirection,
    const idVec3& currentDirection, int debugLevel);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idRotationTracker) == 64,
    "Recovered rotation-tracker ABI changed");
static_assert(sizeof(idAimTracker) == 104,
    "Recovered aim-tracker ABI changed");
#endif
