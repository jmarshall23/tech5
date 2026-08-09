#include "gamelib/animstack/animator_dragjoints.h"

#include <cstring>

idMD6Branch* GameLib_AllocMD6Branch(idAnimStack* stack);
void GameLib_FreeMD6Branch(idAnimStack* stack, idMD6Branch* branch);
idTreeAnimator* GameLib_GetTreeAnimator(idAnimStack* stack);
bool GameLib_InitDragJoints(idAnimator_DragJoints& animator,
    const idDeclDragJoints* declaration);
void GameLib_ReinitDragJoints(idAnimator_DragJoints& animator);
void GameLib_UpdateDragJoints(idAnimator_DragJoints& animator,
    const idAnimStack* stack, int currentTime, int ticksPerSecond);

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

idAnimator_DragJoints::idAnimator_DragJoints()
    : idAnimator_Base()
    , enabled(false)
    , blendFrame(0)
    , numBlendFrames(20)
    , animweb(nullptr)
    , subwebs(16)
    , baseJoint()
    , joints(16)
    , animator(nullptr)
    , animLeaf{}
    , mergeBranch(nullptr) {
}

idAnimator_DragJoints::~idAnimator_DragJoints() {
    animator = nullptr;
    animweb = nullptr;
}

bool idAnimator_DragJoints::InternalInit(
        const idAnimatorParms_Base& parameters) {
    const auto& dragParameters =
        static_cast<const idAnimatorParms_DragJoints&>(parameters);
    mergeBranch = GameLib_AllocMD6Branch(parameters.animStack);
    if (mergeBranch == nullptr) return false;
    animator = GameLib_GetTreeAnimator(parameters.animStack);
    animLeaf.Init(nullptr, 0.0f, idMD6Leaf::WRAP_CLAMP,
        MD6_WEIGHTGROUP_ALL);
    InitBranch(*mergeBranch, &animLeaf);
    enabled = animator != nullptr && dragParameters.declDragJoints != nullptr &&
        GameLib_InitDragJoints(*this, dragParameters.declDragJoints);
    if (enabled) ReinitJoints();
    return enabled;
}

void idAnimator_DragJoints::InternalShutdown(idAnimStack* const stack) {
    if (mergeBranch != nullptr) {
        GameLib_FreeMD6Branch(stack, mergeBranch);
        mergeBranch = nullptr;
    }
    subwebs.ClearFree();
    joints.ClearFree();
    enabled = false;
}

void idAnimator_DragJoints::ReinitJoints() {
    if (animator != nullptr && joints.Num() > 0)
        GameLib_ReinitDragJoints(*this);
}

void idAnimator_DragJoints::InternalPreBlendTree(
        const idAnimStack* const stack, const int currentTime,
        const int ticksPerSecond) {
    if (enabled) GameLib_UpdateDragJoints(*this, stack, currentTime,
        ticksPerSecond);
}
