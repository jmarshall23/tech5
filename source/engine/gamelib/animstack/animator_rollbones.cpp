#include "gamelib/animstack/animator_rollbones.h"

#include <cstring>

idMD6Branch* GameLib_AllocMD6Branch(idAnimStack* stack);
void GameLib_FreeMD6Branch(idAnimStack* stack, idMD6Branch* branch);
idTreeAnimator* GameLib_GetTreeAnimator(idAnimStack* stack);
bool GameLib_HasTreeSkeleton(const idTreeAnimator* animator);
int GameLib_GetRollBoneCount(const idDeclRollBones* declaration);
bool GameLib_BuildRollBoneInstance(idTreeAnimator* animator,
    const idDeclRollBones* declaration, int definitionIndex,
    idVec3& rollAxis, float& rollAmount, idJointIndex& sourceJoint,
    idJointIndex& destinationJoint);
void GameLib_ApplyRollBone(idTreeAnimator* animator,
    const idAnimator_RollBones::idRollInstance& rollBone,
    animationPose_t pose);

namespace {
void InitBranch(idMD6Branch& branch) {
    std::memset(&branch, 0, sizeof(branch));
    branch.type = idMD6Node::NODE_BRANCH;
    branch.filterGroup = MD6_WEIGHTGROUP_ALL;
    branch.currentAlpha = 1.0f;
    branch.targetAlpha = 1.0f;
}
}

idAnimator_RollBones::idAnimator_RollBones()
    : idAnimator_Base()
    , enabled(false)
    , animator(nullptr)
    , animLeaf{}
    , mergeBranch(nullptr)
    , rollBones(16) {
}

idAnimator_RollBones::~idAnimator_RollBones() {
    animator = nullptr;
}

bool idAnimator_RollBones::InternalInit(
        const idAnimatorParms_Base& parameters) {
    const auto& rollParameters =
        static_cast<const idAnimatorParms_RollBones&>(parameters);
    mergeBranch = GameLib_AllocMD6Branch(parameters.animStack);
    if (mergeBranch == nullptr) {
        return false;
    }
    InitBranch(*mergeBranch);
    animator = GameLib_GetTreeAnimator(parameters.animStack);
    if (animator == nullptr || !GameLib_HasTreeSkeleton(animator)) {
        return false;
    }

    const int count = rollParameters.declRollBones != nullptr
        ? GameLib_GetRollBoneCount(rollParameters.declRollBones) : 0;
    if (!rollBones.SetNum(count)) {
        return false;
    }
    for (int index = 0; index < count; ++index) {
        idRollInstance& instance = rollBones[index];
        if (!GameLib_BuildRollBoneInstance(animator,
                rollParameters.declRollBones, index, instance.rollAxis,
                instance.rollAmount, instance.rollSourceJoint,
                instance.rollDestJoint)) {
            enabled = false;
            return false;
        }
        instance.rollAxis.NormalizeFast();
    }
    enabled = rollParameters.declRollBones != nullptr;
    return enabled;
}

void idAnimator_RollBones::InternalShutdown(idAnimStack* const stack) {
    if (mergeBranch != nullptr) {
        GameLib_FreeMD6Branch(stack, mergeBranch);
        mergeBranch = nullptr;
    }
}

void idAnimator_RollBones::InternalPreBlendTree(const idAnimStack*, int,
        int) {
    if (!enabled || animator == nullptr ||
            !GameLib_HasTreeSkeleton(animator)) {
        return;
    }
    for (int index = 0; index < rollBones.Num(); ++index) {
        GameLib_ApplyRollBone(animator, rollBones[index], 0);
    }
}
