#include "gamelib/animstack/animator_torsotracker.h"

void GameLib_SerializeTorsoTracker(idSerializer* serializer,
    idAnimator_TorsoTracker& tracker);
void GameLib_GetTorsoTrackerFrame(const idAnimator_TorsoTracker& tracker,
    const idAnimator_TrackerBase* parent, const idTreeAnimator* animator,
    bool worldSpace, bool forChild, idVec3& origin, idMat3& axis);

idAnimator_TorsoTracker::idAnimator_TorsoTracker()
    : idAnimator_TrackerBase()
    , referenceJointOverrideIdx()
    , useOriginXYForWorldSpace(false) {
}

idAnimator_TorsoTracker::~idAnimator_TorsoTracker() = default;

void idAnimator_TorsoTracker::SetReferenceJointOverride(
        const idJointIndex joint) {
    referenceJointOverrideIdx = joint;
}

idJointIndex idAnimator_TorsoTracker::GetReferenceJointOverride() const {
    return referenceJointOverrideIdx;
}

void idAnimator_TorsoTracker::SerializeSnapshot(
        idSerializer* const serializer) {
    idAnimator_TrackerBase::SerializeSnapshot(serializer);
    if (serializer != nullptr) GameLib_SerializeTorsoTracker(serializer, *this);
}

void idAnimator_TorsoTracker::GetModelSpaceFrameOfReferenceForChild(
        const idTreeAnimator* const animator, idVec3& origin,
        idMat3& axis) const {
    GameLib_GetTorsoTrackerFrame(*this, parentTracker, animator, false,
        true, origin, axis);
}

void idAnimator_TorsoTracker::GetWorldSpaceFrameOfReferenceForChild(
        const idTreeAnimator* const animator, idVec3& origin,
        idMat3& axis) const {
    GameLib_GetTorsoTrackerFrame(*this, parentTracker, animator, true,
        true, origin, axis);
}

void idAnimator_TorsoTracker::GetWorldSpaceFrameOfReference(
        const idAnimator_TrackerBase* const parent,
        const idTreeAnimator* const animator, idVec3& origin,
        idMat3& axis) const {
    GameLib_GetTorsoTrackerFrame(*this, parent, animator, true, false,
        origin, axis);
}

void idAnimator_TorsoTracker::GetModelSpaceFrameOfReference(
        const idAnimator_TrackerBase* const parent,
        const idTreeAnimator* const animator, idVec3& origin,
        idMat3& axis) const {
    GameLib_GetTorsoTrackerFrame(*this, parent, animator, false, false,
        origin, axis);
}
