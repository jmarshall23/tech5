#include "gamelib/animstack/animator_jointmod.h"

#include <algorithm>

idTreeAnimator* GameLib_GetTreeAnimator(idAnimStack* stack);
void GameLib_SetTreeJointAxis(idTreeAnimator* animator,
    animationPose_t pose, idJointIndex joint, int jointModType,
    const idMat3& axis);

namespace {
constexpr int BOP_LERP = 1;
constexpr int JOINTMOD_MODEL_OVERRIDE = 4;
}

idAnimator_JointMod::idAnimator_JointMod()
    : idAnimator_Base()
    , enabled(true)
    , jointIndex(16)
    , jointValue(16)
    , treeAnimator(nullptr)
    , poseToModify(0) {
}

idAnimator_JointMod::~idAnimator_JointMod() {
    treeAnimator = nullptr;
}

bool idAnimator_JointMod::InternalInit(
        const idAnimatorParms_Base& parameters) {
    const auto& jointParameters =
        static_cast<const idAnimatorParms_JointMod&>(parameters);
    if (jointParameters.treeAnimator == nullptr) {
        return false;
    }
    treeAnimator = jointParameters.treeAnimator;
    poseToModify = jointParameters.poseToModify;
    return true;
}

void idAnimator_JointMod::PreSerializeInit(idAnimStack* const stack,
        idClip* const clip, idGameTimeManager* const gameTimeManager) {
    idAnimator_Base::PreSerializeInit(stack, clip, gameTimeManager);

    idAnimatorParms_JointMod parameters{};
    parameters.animStack = stack;
    parameters.name = "jointmod";
    parameters.blendOp = BOP_LERP;
    parameters.originBlend = 0;
    parameters.weightGroup = MD6_WEIGHTGROUP_ALL;
    parameters.filterGroup = MD6_WEIGHTGROUP_ALL;
    parameters.alpha = 1.0f;
    parameters.treeAnimator = GameLib_GetTreeAnimator(stack);
    parameters.poseToModify = 0;
    Init(gameTimeManager, parameters);
}

void idAnimator_JointMod::ClearJointMods() {
    jointIndex.Clear();
    jointValue.Clear();
}

void idAnimator_JointMod::SetJointMod(const idJointIndex index,
        const idMat3& value) {
    jointIndex.Append(index);
    jointValue.Append(value);
}

void idAnimator_JointMod::InternalPostBlendTree(const idAnimStack*, int) {
    ClearJointMods();
}

void idAnimator_JointMod::InternalPreBlendTree(const idAnimStack* const stack,
        int, int) {
    if (!enabled || stack == nullptr || treeAnimator == nullptr) {
        return;
    }
    const int count = (std::min)(jointIndex.Num(), jointValue.Num());
    for (int index = 0; index < count; ++index) {
        GameLib_SetTreeJointAxis(treeAnimator, poseToModify,
            jointIndex[index], JOINTMOD_MODEL_OVERRIDE, jointValue[index]);
    }
}
