#include "gamelib/animstack/animator_trackerbase.h"

#include <cstring>

idMD6Branch* GameLib_AllocMD6Branch(idAnimStack* stack);
idMD6LeafPause* GameLib_AllocMD6LeafPause(idAnimStack* stack);
void GameLib_FreeMD6Branch(idAnimStack* stack, idMD6Branch* branch);
void GameLib_FreeMD6LeafPause(idAnimStack* stack, idMD6LeafPause* leaf);
void GameLib_SerializeTracker(idSerializer* serializer,
    idAnimator_TrackerBase& tracker);
bool GameLib_TrackerHasAnimMods(const idMD6LeafPause* leaf);
void GameLib_DoTrackerUpdate(idAnimator_TrackerBase& tracker,
    const idAnimStack* stack, float deltaLerpScale);
void GameLib_GetTrackerUnconstrainedAngles(idAnimator_TrackerBase& tracker,
    const idAnimator_TrackerBase* parent, idTreeAnimator* animator,
    idAngles& angleDeltas, idAngles& angles, idVec3& cross);
void GameLib_GetTrackerFrame(const idAnimator_TrackerBase& tracker,
    const idAnimator_TrackerBase* parent, const idTreeAnimator* animator,
    bool worldSpace, bool forChild, idVec3& origin, idMat3& axis);

namespace {
void InitBranch(idMD6Branch& branch) {
    std::memset(&branch, 0, sizeof(branch));
    branch.type = idMD6Node::NODE_BRANCH;
    branch.leftTimeOverride = -1;
    branch.rightTimeOverride = -1;
    branch.filterGroup = MD6_WEIGHTGROUP_TORSO;
    branch.op = 2;
    branch.currentAlpha = 1.0f;
    branch.targetAlpha = 1.0f;
    branch.blendType = idMD6Branch::BLEND_LINEAR;
}
}

idAnimatorParms_TrackerBase::idAnimatorParms_TrackerBase()
    : idAnimatorParms_Base{}
    , projectReferenceOrientation(false) {
    blendOp = 2;
}

idAnimator_TrackerBase::idAnimator_TrackerBase()
    : idAnimator_Base()
    , parentTracker(nullptr)
    , focusPoint(0.0f, 0.0f, 0.0f)
    , focusPoints{idVec3(0.0f, 0.0f, 0.0f),
        idVec3(0.0f, 0.0f, 0.0f)}
    , yawRight(-90.0f)
    , yawLeft(90.0f)
    , pitchUp(-90.0f)
    , pitchDown(90.0f)
    , trackGroupIndex(-1)
    , mergeBranch(nullptr)
    , leaf(nullptr)
    , msDirToFocus(1.0f, 0.0f, 0.0f)
    , wsFocusJointPos(0.0f, 0.0f, 0.0f)
    , msReferenceJointPos(0.0f, 0.0f, 0.0f)
    , idealOffsetAngles(0.0f, 0.0f, 0.0f)
    , curOffsetAngles(0.0f, 0.0f, 0.0f)
    , lastAngles(0.0f, 0.0f, 0.0f)
    , reserved(0)
    , lockTracking(0)
    , clientSnapFocusPoint(0)
    , projectReferenceOrientation(0)
    , enableConstraints(0)
    , pitchClamped(0)
    , yawClamped(0) {
}

idAnimator_TrackerBase::~idAnimator_TrackerBase() {
    parentTracker = nullptr;
    mergeBranch = nullptr;
    leaf = nullptr;
}

bool idAnimator_TrackerBase::InternalInit(
        const idAnimatorParms_Base& parameters) {
    const auto& trackerParameters =
        static_cast<const idAnimatorParms_TrackerBase&>(parameters);
    mergeBranch = GameLib_AllocMD6Branch(parameters.animStack);
    leaf = GameLib_AllocMD6LeafPause(parameters.animStack);
    if (mergeBranch == nullptr || leaf == nullptr) return false;
    InitBranch(*mergeBranch);
    leaf->Init(nullptr, 0.0f, idMD6Leaf::WRAP_CLAMP,
        MD6_WEIGHTGROUP_ALL);
    mergeBranch->right = leaf;
    projectReferenceOrientation =
        trackerParameters.projectReferenceOrientation;
    clientSnapFocusPoint = 1;
    return true;
}

void idAnimator_TrackerBase::InternalShutdown(idAnimStack* const stack) {
    if (mergeBranch != nullptr) {
        GameLib_FreeMD6Branch(stack, mergeBranch);
        mergeBranch = nullptr;
    }
    if (leaf != nullptr) {
        GameLib_FreeMD6LeafPause(stack, leaf);
        leaf = nullptr;
    }
}

void idAnimator_TrackerBase::SetPitchConstraints(const degrees_t up,
        const degrees_t down) {
    pitchUp = up;
    pitchDown = down;
}

void idAnimator_TrackerBase::SetYawConstraints(const degrees_t right,
        const degrees_t left) {
    yawRight = right;
    yawLeft = left;
}

void idAnimator_TrackerBase::Update(
        const idAnimator_TrackerBase* const parent,
        const idVec3& newFocusPoint, const idAngles& offsetAngles,
        const degrees_t pitchUpLimit, const degrees_t pitchDownLimit,
        const degrees_t yawRightLimit, const degrees_t yawLeftLimit) {
    focusPoint = newFocusPoint;
    idealOffsetAngles = offsetAngles;
    parentTracker = parent;
    pitchUp = pitchUpLimit;
    pitchDown = pitchDownLimit;
    yawRight = yawRightLimit;
    yawLeft = yawLeftLimit;
    InternalUpdate(parent);
}

void idAnimator_TrackerBase::SerializeSnapshot(
        idSerializer* const serializer) {
    focusPoints[0] = focusPoints[1];
    focusPoints[1] = focusPoint;
    if (serializer != nullptr) GameLib_SerializeTracker(serializer, *this);
}

bool idAnimator_TrackerBase::InternalIsContributing() const {
    return GameLib_TrackerHasAnimMods(leaf);
}

void idAnimator_TrackerBase::InternalDoTracking(
        const idAnimStack* const stack, const float deltaLerpScale) {
    if (mergeBranch == nullptr || leaf == nullptr) return;
    GameLib_DoTrackerUpdate(*this, stack, deltaLerpScale);
    mergeBranch->left = nullptr;
    mergeBranch->right = leaf;
    mergeBranch->filterGroup = MD6_WEIGHTGROUP_TORSO;
    parentTracker = nullptr;
}

void idAnimator_TrackerBase::PreBlendSnapshot(idAnimStack* const stack,
        int, int, const float fraction) {
    if (clientSnapFocusPoint || !InternalIsContributing()) {
        focusPoints[0] = focusPoints[1];
        focusPoint = focusPoints[1];
        clientSnapFocusPoint = !InternalIsContributing();
    } else {
        focusPoint.x = focusPoints[0].x +
            (focusPoints[1].x - focusPoints[0].x) * fraction;
        focusPoint.y = focusPoints[0].y +
            (focusPoints[1].y - focusPoints[0].y) * fraction;
        focusPoint.z = focusPoints[0].z +
            (focusPoints[1].z - focusPoints[0].z) * fraction;
    }
    InternalDoTracking(stack != nullptr ? stack : serializeProps.animStack,
        1.0f);
}

void idAnimator_TrackerBase::InternalPreBlendTree(
        const idAnimStack* const stack, int, int) {
    InternalDoTracking(stack, 1.0f);
}

void idAnimator_TrackerBase::SetReferenceJointOverride(idJointIndex) {}
idJointIndex idAnimator_TrackerBase::GetReferenceJointOverride() const {
    return idJointIndex();
}

void idAnimator_TrackerBase::GetModelSpaceFrameOfReferenceForChild(
        const idTreeAnimator* const animator, idVec3& origin,
        idMat3& axis) const {
    GameLib_GetTrackerFrame(*this, parentTracker, animator, false, true,
        origin, axis);
}

void idAnimator_TrackerBase::GetWorldSpaceFrameOfReferenceForChild(
        const idTreeAnimator* const animator, idVec3& origin,
        idMat3& axis) const {
    GameLib_GetTrackerFrame(*this, parentTracker, animator, true, true,
        origin, axis);
}

void idAnimator_TrackerBase::GetWorldSpaceFrameOfReference(
        const idAnimator_TrackerBase* const parent,
        const idTreeAnimator* const animator, idVec3& origin,
        idMat3& axis) const {
    GameLib_GetTrackerFrame(*this, parent, animator, true, false,
        origin, axis);
}

void idAnimator_TrackerBase::GetModelSpaceFrameOfReference(
        const idAnimator_TrackerBase* const parent,
        const idTreeAnimator* const animator, idVec3& origin,
        idMat3& axis) const {
    GameLib_GetTrackerFrame(*this, parent, animator, false, false,
        origin, axis);
}

void idAnimator_TrackerBase::InternalUpdate(
        const idAnimator_TrackerBase*) {}

void idAnimator_TrackerBase::GetUnconstrainedAngleDeltas(
        const idAnimator_TrackerBase* const parent,
        idTreeAnimator* const animator, idAngles& angleDeltas,
        idAngles& angles, idVec3& cross) {
    GameLib_GetTrackerUnconstrainedAngles(*this, parent, animator,
        angleDeltas, angles, cross);
}
