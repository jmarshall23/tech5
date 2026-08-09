#include "gamelib/animstack/animator_ik.h"

#include <algorithm>
#include <cmath>
#include <cstring>

idMD6Branch* GameLib_AllocMD6Branch(idAnimStack* stack);
void GameLib_FreeMD6Branch(idAnimStack* stack, idMD6Branch* branch);
idTreeAnimator* GameLib_GetTreeAnimator(idAnimStack* stack);
bool GameLib_InitWalkIK(idAnimator_WalkIK& ik);
void GameLib_EvaluateWalkIK(idAnimator_WalkIK& ik);
void GameLib_SerializeWalkIK(idSerializer* serializer,
    idAnimator_WalkIK& ik);
bool GameLib_InitReachIK(idAnimator_ReachIK& ik);
void GameLib_EvaluateReachIK(idAnimator_ReachIK& ik);
void GameLib_SerializeReachIK(idSerializer* serializer,
    idAnimator_ReachIK& ik);
float GameLib_GetIKBoneAxis(const idVec3& start, const idVec3& end,
    const idVec3& bendDirection, idMat3& axis);

namespace {
void InitBranch(idMD6Branch& branch, idMD6Node* const right) {
    std::memset(&branch, 0, sizeof(branch));
    branch.type = idMD6Node::NODE_BRANCH;
    branch.right = right;
    branch.leftTimeOverride = -1;
    branch.rightTimeOverride = -1;
    branch.filterGroup = MD6_WEIGHTGROUP_ALL;
    branch.currentAlpha = 1.0f;
    branch.targetAlpha = 1.0f;
    branch.blendType = idMD6Branch::BLEND_LINEAR;
}
}

idAnimator_IK::idAnimator_IK()
    : idAnimator_Base()
    , enabled(true)
    , ikInitialized(false)
    , ik_activate(true)
    , entityNum(0x1FFF)
    , animator(nullptr)
    , clip(nullptr) {
}

idAnimator_IK::~idAnimator_IK() {
    animator = nullptr;
    clip = nullptr;
}

void idAnimator_IK::Evaluate() {}

void idAnimator_IK::PreBlendSnapshot(idAnimStack*, int, int, float) {
    if (InternalIsContributing()) Evaluate();
}

void idAnimator_IK::InternalPreBlendTree(const idAnimStack*, int, int) {
    if (InternalIsContributing()) Evaluate();
}

bool idAnimator_IK::SolveTwoBones(const idVec3& start, const idVec3& end,
        const idVec3& bendDirection, const float firstLength,
        const float secondLength, idVec3& jointPosition) const {
    idVec3 direction = end - start;
    const float distance = direction.NormalizeFast();
    if (distance <= 1.0e-6f || firstLength <= 0.0f ||
            secondLength <= 0.0f) return false;
    const float clampedDistance = (std::max)(
        std::fabs(firstLength - secondLength) + 1.0e-5f,
        (std::min)(firstLength + secondLength - 1.0e-5f, distance));
    const float along = (firstLength * firstLength -
        secondLength * secondLength + clampedDistance * clampedDistance) /
        (2.0f * clampedDistance);
    const float perpendicular = std::sqrt((std::max)(0.0f,
        firstLength * firstLength - along * along));
    idVec3 bend = bendDirection - direction * bendDirection.Dot(direction);
    if (bend.NormalizeFast() <= 1.0e-6f) return false;
    jointPosition = start + direction * along + bend * perpendicular;
    return true;
}

float idAnimator_IK::GetBoneAxis(const idVec3& start, const idVec3& end,
        const idVec3& bendDirection, idMat3& axis) const {
    return GameLib_GetIKBoneAxis(start, end, bendDirection, axis);
}

idAnimator_WalkIK::idAnimator_WalkIK()
    : idAnimator_IK()
    , decl(nullptr)
    , clipModel(nullptr)
    , clipMask(0)
    , upNormal(0.0f, 0.0f, 1.0f)
    , footModel(nullptr)
    , createdClipModel(false)
    , numLegs(0)
    , enabledLegs(0)
    , footJoints{}
    , ankleJoints{}
    , kneeJoints{}
    , hipJoints{}
    , dirJoints{}
    , waistJointHandle()
    , hipForward{}
    , kneeForward{}
    , upperLegLength{}
    , lowerLegLength{}
    , upperLegToHipJoint{}
    , lowerLegToKneeJoint{}
    , kneeJointTransform{}
    , pivotFoot(-1)
    , pivotYaw(0.0f)
    , pivotPos(0.0f, 0.0f, 0.0f)
    , onGround(false)
    , onStairs(false)
    , isDead(false)
    , oldHeightsValid(false)
    , oldWaistHeight(0.0f)
    , oldAnkleHeights{}
    , oldGroundPhysicsId(-1)
    , oldGroundPhysicsOrigin(0.0f, 0.0f, 0.0f)
    , surfaceTypes{}
    , modelQuery{}
    , waistQuery{}
    , legQueries{}
    , footQueries{}
    , lastModelSpaceFootOrigin{}
    , groundTraceDist(0.0f)
    , internalRadiusXY(0.0f)
    , animLeaf{}
    , mergeBranch(nullptr) {
}

idAnimator_WalkIK::~idAnimator_WalkIK() {
    decl = nullptr; clipModel = nullptr; footModel = nullptr;
}

bool idAnimator_WalkIK::InternalInit(
        const idAnimatorParms_Base& parameters) {
    const auto& walkParameters =
        static_cast<const idAnimatorParms_WalkIK&>(parameters);
    decl = walkParameters.declWalkIK;
    entityNum = walkParameters.entityNum;
    clipMask = walkParameters.clipMask;
    clip = walkParameters.clip;
    clipModel = walkParameters.clipModel;
    upNormal = walkParameters.upNormal;
    animator = GameLib_GetTreeAnimator(parameters.animStack);
    mergeBranch = GameLib_AllocMD6Branch(parameters.animStack);
    if (mergeBranch == nullptr) return false;
    animLeaf.Init(nullptr, 0.0f, idMD6Leaf::WRAP_CLAMP,
        MD6_WEIGHTGROUP_ALL);
    InitBranch(*mergeBranch, &animLeaf);
    ikInitialized = decl != nullptr && animator != nullptr &&
        GameLib_InitWalkIK(*this);
    return ikInitialized;
}

void idAnimator_WalkIK::InternalShutdown(idAnimStack* const stack) {
    if (mergeBranch != nullptr) {
        GameLib_FreeMD6Branch(stack, mergeBranch);
        mergeBranch = nullptr;
    }
    ikInitialized = false;
    footModel = nullptr;
}

void idAnimator_WalkIK::EnableLeg(const int leg) {
    if (leg >= 0 && leg < numLegs) enabledLegs |= 1 << leg;
}
void idAnimator_WalkIK::DisableLeg(const int leg) {
    if (leg >= 0 && leg < numLegs) enabledLegs &= ~(1 << leg);
}
void idAnimator_WalkIK::EnableAll() {
    enabledLegs = numLegs >= 31 ? -1 : (1 << numLegs) - 1;
}
void idAnimator_WalkIK::DisableAll() { enabledLegs = 0; }
bool idAnimator_WalkIK::IsActive() const {
    return InternalIsContributing();
}
bool idAnimator_WalkIK::InternalIsContributing() const {
    return idAnimator_IK::InternalIsContributing() && enabledLegs != 0;
}
int idAnimator_WalkIK::GetFootSurfaceType() const {
    return pivotFoot >= 0 && pivotFoot < numLegs ? surfaceTypes[pivotFoot] : 0;
}
void idAnimator_WalkIK::Evaluate() {
    if (InternalIsContributing()) GameLib_EvaluateWalkIK(*this);
}
void idAnimator_WalkIK::SerializeSnapshot(idSerializer* const serializer) {
    if (serializer != nullptr) GameLib_SerializeWalkIK(serializer, *this);
}

idAnimator_ReachIK::idAnimator_ReachIK()
    : idAnimator_IK()
    , decl(nullptr)
    , numArms(0)
    , enabledArms(0)
    , handJoints{}
    , elbowJoints{}
    , shoulderJoints{}
    , targetTransforms{}
    , shoulderForward{}
    , elbowForward{}
    , upperArmLength{}
    , lowerArmLength{}
    , upperArmToShoulderJoint{}
    , lowerArmToElbowJoint{} {
}

idAnimator_ReachIK::~idAnimator_ReachIK() { decl = nullptr; }

bool idAnimator_ReachIK::InternalInit(
        const idAnimatorParms_Base& parameters) {
    const auto& reachParameters =
        static_cast<const idAnimatorParms_ReachIK&>(parameters);
    decl = reachParameters.declReachIK;
    entityNum = reachParameters.entityNum;
    clip = reachParameters.clip;
    animator = GameLib_GetTreeAnimator(parameters.animStack);
    ikInitialized = decl != nullptr && animator != nullptr &&
        GameLib_InitReachIK(*this);
    return ikInitialized;
}

void idAnimator_ReachIK::SetTargetOrigin(const int arm,
        const idVec3& origin) {
    if (arm < 0 || arm >= 2) return;
    targetTransforms[arm].origin = origin;
    targetTransforms[arm].validOrigin = true;
    enabledArms |= 1 << arm;
}
void idAnimator_ReachIK::SetTargetAxis(const int arm, const idMat3& axis) {
    if (arm < 0 || arm >= 2) return;
    targetTransforms[arm].axis = axis;
    targetTransforms[arm].validAxis = true;
    enabledArms |= 1 << arm;
}
void idAnimator_ReachIK::Evaluate() {
    if (InternalIsContributing() && enabledArms != 0)
        GameLib_EvaluateReachIK(*this);
}
void idAnimator_ReachIK::SerializeSnapshot(idSerializer* const serializer) {
    if (serializer != nullptr) GameLib_SerializeReachIK(serializer, *this);
}
