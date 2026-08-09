#pragma once

#include "gamelib/animstack/animator_trackerbase.h"

class idAnimator_TorsoTracker : public idAnimator_TrackerBase {
public:
    idAnimator_TorsoTracker();
    ~idAnimator_TorsoTracker() override;

    serializeType_t GetSerializeType() override {
        return STYPE_TORSO_TRACKER;
    }
    void SerializeSnapshot(idSerializer* serializer) override;
    void SetReferenceJointOverride(idJointIndex joint) override;
    idJointIndex GetReferenceJointOverride() const override;
    void GetModelSpaceFrameOfReferenceForChild(
        const idTreeAnimator* animator, idVec3& origin,
        idMat3& axis) const override;
    void GetWorldSpaceFrameOfReferenceForChild(
        const idTreeAnimator* animator, idVec3& origin,
        idMat3& axis) const override;
    void GetWorldSpaceFrameOfReference(
        const idAnimator_TrackerBase* parent,
        const idTreeAnimator* animator, idVec3& origin,
        idMat3& axis) const override;
    void GetModelSpaceFrameOfReference(
        const idAnimator_TrackerBase* parent,
        const idTreeAnimator* animator, idVec3& origin,
        idMat3& axis) const override;

    idJointIndex referenceJointOverrideIdx;
    bool useOriginXYForWorldSpace;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_TorsoTracker) == 188,
    "Recovered idAnimator_TorsoTracker ABI changed");
#endif
