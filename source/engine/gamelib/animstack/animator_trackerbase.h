#pragma once

#include "gamelib/animstack/animator_base.h"
#include "idlib/math/degrees.h"

class idAnimatorParms_TrackerBase : public idAnimatorParms_Base {
public:
    idAnimatorParms_TrackerBase();
    bool projectReferenceOrientation;
};

class idAnimator_TrackerBase : public idAnimator_Base {
public:
    idAnimator_TrackerBase();
    ~idAnimator_TrackerBase() override;

    void SerializeSnapshot(idSerializer* serializer) override;
    void PreBlendSnapshot(idAnimStack* stack, int currentTime,
        int ticksPerSecond, float fraction) override;
    bool InternalInit(const idAnimatorParms_Base& parameters) override;
    void InternalShutdown(idAnimStack* stack) override;
    void InternalPreBlendTree(const idAnimStack* stack, int currentTime,
        int ticksPerSecond) override;
    bool InternalIsContributing() const override;
    const idMD6Branch* InternalGetMergeBranch() const override {
        return mergeBranch;
    }
    idMD6Branch* InternalGetMergeBranch() override { return mergeBranch; }

    virtual void SetReferenceJointOverride(idJointIndex joint);
    virtual idJointIndex GetReferenceJointOverride() const;
    virtual void GetModelSpaceFrameOfReferenceForChild(
        const idTreeAnimator* animator, idVec3& origin, idMat3& axis) const;
    virtual void GetWorldSpaceFrameOfReferenceForChild(
        const idTreeAnimator* animator, idVec3& origin, idMat3& axis) const;
    virtual void GetWorldSpaceFrameOfReference(
        const idAnimator_TrackerBase* parent,
        const idTreeAnimator* animator, idVec3& origin,
        idMat3& axis) const;
    virtual void GetModelSpaceFrameOfReference(
        const idAnimator_TrackerBase* parent,
        const idTreeAnimator* animator, idVec3& origin,
        idMat3& axis) const;
    virtual void InternalUpdate(const idAnimator_TrackerBase* parent);
    virtual void GetUnconstrainedAngleDeltas(
        const idAnimator_TrackerBase* parent, idTreeAnimator* animator,
        idAngles& angleDeltas, idAngles& angles, idVec3& cross);

    void Update(const idAnimator_TrackerBase* parent,
        const idVec3& newFocusPoint, const idAngles& offsetAngles,
        degrees_t pitchUpLimit, degrees_t pitchDownLimit,
        degrees_t yawRightLimit, degrees_t yawLeftLimit);
    void SetPitchConstraints(degrees_t up, degrees_t down);
    void SetYawConstraints(degrees_t right, degrees_t left);

    const idAnimator_TrackerBase* parentTracker;
    idVec3 focusPoint;
    idVec3 focusPoints[2];
    degrees_t yawRight;
    degrees_t yawLeft;
    degrees_t pitchUp;
    degrees_t pitchDown;
    int trackGroupIndex;
    idMD6Branch* mergeBranch;
    idMD6LeafPause* leaf;
    idVec3 msDirToFocus;
    idVec3 wsFocusJointPos;
    idVec3 msReferenceJointPos;
    idAngles idealOffsetAngles;
    idAngles curOffsetAngles;
    idAngles lastAngles;
    unsigned char reserved : 2;
    unsigned char lockTracking : 1;
    unsigned char clientSnapFocusPoint : 1;
    unsigned char projectReferenceOrientation : 1;
    unsigned char enableConstraints : 1;
    unsigned char pitchClamped : 1;
    unsigned char yawClamped : 1;

protected:
    void InternalDoTracking(const idAnimStack* stack,
        float deltaLerpScale);
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_TrackerBase) == 184,
    "Recovered idAnimator_TrackerBase ABI changed");
static_assert(sizeof(idAnimatorParms_TrackerBase) == 60,
    "Recovered tracker parameters ABI changed");
#endif
