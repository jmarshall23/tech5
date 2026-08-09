#include "gamelib/animstack/animator_ponytail.h"

#include <cstring>

idMD6Branch* GameLib_AllocMD6Branch(idAnimStack* stack);
idMD6LeafPause* GameLib_AllocMD6LeafPause(idAnimStack* stack);
idMD6LeafPlay* GameLib_AllocMD6LeafPlay(idAnimStack* stack);
void GameLib_FreeMD6Branch(idAnimStack* stack, idMD6Branch* branch);
void GameLib_FreeMD6LeafPause(idAnimStack* stack, idMD6LeafPause* leaf);
void GameLib_FreeMD6LeafPlay(idAnimStack* stack, idMD6LeafPlay* leaf);
bool GameLib_InitPonytailAnimator(idAnimator_Ponytail& ponytail);
void GameLib_UpdatePonytailAnimator(idAnimator_Ponytail& ponytail,
    const idAnimStack* stack, int currentTime, int ticksPerSecond);

namespace {
void InitBranch(idMD6Branch& branch, idMD6Node* const left,
        idMD6Node* const right, const float alpha) {
    std::memset(&branch, 0, sizeof(branch));
    branch.type = idMD6Node::NODE_BRANCH;
    branch.left = left;
    branch.right = right;
    branch.leftTimeOverride = -1;
    branch.rightTimeOverride = -1;
    branch.filterGroup = MD6_WEIGHTGROUP_ALL;
    branch.op = 1;
    branch.currentAlpha = alpha;
    branch.targetAlpha = alpha;
    branch.blendType = idMD6Branch::BLEND_LINEAR;
}
}

idAnimator_Ponytail::idAnimator_Ponytail()
    : idAnimator_Base()
    , declPonytail(nullptr)
    , parentAnimator(nullptr)
    , joints(16)
    , mergeBranch(nullptr)
    , pauseLeaf(nullptr)
    , playLeaf(nullptr)
    , lerpBranch(nullptr)
    , segments(16)
    , ptEndSpring{}
    , isInitialized(false) {
}

idAnimator_Ponytail::~idAnimator_Ponytail() {
    declPonytail = nullptr;
    parentAnimator = nullptr;
}

bool idAnimator_Ponytail::InternalInit(
        const idAnimatorParms_Base& parameters) {
    const auto& ponytailParameters =
        static_cast<const idAnimatorParms_Ponytail&>(parameters);
    declPonytail = ponytailParameters.declPonytail;
    parentAnimator = ponytailParameters.parentAnimator;
    mergeBranch = GameLib_AllocMD6Branch(parameters.animStack);
    lerpBranch = GameLib_AllocMD6Branch(parameters.animStack);
    pauseLeaf = GameLib_AllocMD6LeafPause(parameters.animStack);
    playLeaf = GameLib_AllocMD6LeafPlay(parameters.animStack);
    if (mergeBranch == nullptr || lerpBranch == nullptr ||
            pauseLeaf == nullptr || playLeaf == nullptr) {
        InternalShutdown(parameters.animStack);
        return false;
    }
    pauseLeaf->Init(nullptr, 0.0f, idMD6Leaf::WRAP_CLAMP,
        MD6_WEIGHTGROUP_ALL);
    playLeaf->Init(nullptr, 0, 1.0f, idMD6Leaf::WRAP_REPEAT,
        MD6_WEIGHTGROUP_ALL);
    InitBranch(*lerpBranch, pauseLeaf, playLeaf, 0.0f);
    InitBranch(*mergeBranch, nullptr, lerpBranch, 1.0f);
    isInitialized = declPonytail != nullptr && parentAnimator != nullptr &&
        GameLib_InitPonytailAnimator(*this);
    return isInitialized;
}

void idAnimator_Ponytail::InternalShutdown(idAnimStack* const stack) {
    if (mergeBranch != nullptr) GameLib_FreeMD6Branch(stack, mergeBranch);
    if (lerpBranch != nullptr) GameLib_FreeMD6Branch(stack, lerpBranch);
    if (pauseLeaf != nullptr) GameLib_FreeMD6LeafPause(stack, pauseLeaf);
    if (playLeaf != nullptr) GameLib_FreeMD6LeafPlay(stack, playLeaf);
    mergeBranch = nullptr;
    lerpBranch = nullptr;
    pauseLeaf = nullptr;
    playLeaf = nullptr;
    joints.ClearFree();
    segments.ClearFree();
    isInitialized = false;
}

void idAnimator_Ponytail::InternalPreBlendTree(const idAnimStack* const stack,
        const int currentTime, const int ticksPerSecond) {
    if (isInitialized)
        GameLib_UpdatePonytailAnimator(*this, stack, currentTime,
            ticksPerSecond);
}
