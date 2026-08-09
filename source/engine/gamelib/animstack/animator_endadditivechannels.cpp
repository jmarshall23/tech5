#include "gamelib/animstack/animator_endadditivechannels.h"

#include <algorithm>
#include <cmath>
#include <cstring>

const idMD6Anim* GameLib_ResolveMD6AliasForAnimator(
    idTreeAnimator* animator, idAnimAliasHandle handle);
idTreeAnimator* GameLib_GetTreeAnimator(const idAnimStack* stack);
int GameLib_GetPreviousGameMs(const idGameTimeManager* manager);
int GameLib_GetGameTicksPerSecond();

namespace {
void InitMergeBranch(idMD6Branch& branch) {
    std::memset(&branch, 0, sizeof(branch));
    branch.type = idMD6Node::NODE_BRANCH;
    branch.leftTimeOverride = -1;
    branch.rightTimeOverride = -1;
    branch.filterGroup = MD6_WEIGHTGROUP_MAX;
    branch.op = 10;
    branch.blendType = idMD6Branch::BLEND_LINEAR;
}

void InitAddBranch(idMD6Branch& branch, idMD6Node* const right,
        const std::uint8_t operation, const float alpha,
        const md6WeightGroup_t filterGroup) {
    std::memset(&branch, 0, sizeof(branch));
    branch.type = idMD6Node::NODE_BRANCH;
    branch.right = right;
    branch.leftTimeOverride = -1;
    branch.rightTimeOverride = -1;
    branch.filterGroup = static_cast<std::uint8_t>(filterGroup);
    branch.op = operation;
    branch.originBlend = 1;
    branch.currentAlpha = alpha;
    branch.targetAlpha = alpha;
    branch.blendType = idMD6Branch::BLEND_LINEAR;
}
}

idAnimator_EndAdditiveChannels::idAnimator_EndAdditiveChannels()
    : idAnimator_Base()
    , leaves(16)
    , branches(16)
    , aliasWeights(16)
    , mergeBranch{}
    , animAlias(16)
    , numAddedChannels(0)
    , numCurrentChannels(0)
    , wrapMode(idMD6Leaf::WRAP_REPEAT)
    , currentExternalAlpha(0.0f)
    , targetExternalAlpha(0.0f)
    , externalAlphaRate(0.0f) {
    InitMergeBranch(mergeBranch);
}

bool idAnimator_EndAdditiveChannels::InternalInit(
        const idAnimatorParms_Base& parameters) {
    const auto& additiveParameters =
        static_cast<const idAnimatorParms_EndAdditiveChannels&>(parameters);
    const int count = (std::max)(0, additiveParameters.maxChannels);
    return animAlias.SetNum(count) && leaves.SetNum(count) &&
        branches.SetNum(count) && aliasWeights.SetNum(count);
}

void idAnimator_EndAdditiveChannels::SetAnimHandlesAndWeights(
        idTreeAnimator*, int, const idAnimAliasHandle* const handles,
        const int animationCount, const float* const weights,
        const int weightCount) {
    const int count = (std::max)(0, (std::min)({animationCount,
        weightCount, animAlias.Num(), aliasWeights.Num()}));
    numCurrentChannels = count;
    for (int index = 0; index < count; ++index) {
        animAlias[index] = handles[index];
        aliasWeights[index] = weights[index];
    }
}

const idMD6Branch*
idAnimator_EndAdditiveChannels::InternalGetMergeBranch() const {
    return numAddedChannels == 1 ? &branches[0] : &mergeBranch;
}

idMD6Branch* idAnimator_EndAdditiveChannels::InternalGetMergeBranch() {
    return numAddedChannels == 1 ? &branches[0] : &mergeBranch;
}

const idMD6Branch*
idAnimator_EndAdditiveChannels::InternalGetEndBranch() const {
    return numAddedChannels > 1 ? &branches[numAddedChannels - 1] : nullptr;
}

idMD6Branch* idAnimator_EndAdditiveChannels::InternalGetEndBranch() {
    return numAddedChannels > 1 ? &branches[numAddedChannels - 1] : nullptr;
}

void idAnimator_EndAdditiveChannels::SetExternalBlend(
        const float targetAlpha, const int blendMilliseconds) {
    targetExternalAlpha = targetAlpha;
    externalAlphaRate = blendMilliseconds > 0
        ? static_cast<float>(GameLib_GetGameTicksPerSecond()) /
            static_cast<float>(blendMilliseconds)
        : 0.0f;
    if (blendMilliseconds <= 0) currentExternalAlpha = targetAlpha;
}

void idAnimator_EndAdditiveChannels::InternalPreBlendTree(
        const idAnimStack* const stack, const int currentTime,
        const int ticksPerSecond) {
    mergeBranch.left = nullptr;
    mergeBranch.right = nullptr;

    const int previousTime = GameLib_GetPreviousGameMs(
        gametimeManager.gameTimeManager);
    const int elapsed = currentTime - previousTime;
    if (elapsed > 0 && currentExternalAlpha != targetExternalAlpha) {
        const float step = externalAlphaRate *
            (static_cast<float>(elapsed) /
                static_cast<float>((std::max)(1, ticksPerSecond)));
        if (targetExternalAlpha > currentExternalAlpha) {
            currentExternalAlpha = (std::min)(targetExternalAlpha,
                currentExternalAlpha + step);
        } else {
            currentExternalAlpha = (std::max)(targetExternalAlpha,
                currentExternalAlpha - step);
        }
    }

    idTreeAnimator* const animator = GameLib_GetTreeAnimator(stack);
    idMD6Branch* previous = nullptr;
    numAddedChannels = 0;
    for (int index = 0; index < numCurrentChannels; ++index) {
        float alpha = aliasWeights[index];
        if (std::fabs(alpha) <= 1.1920929e-7f) continue;
        const std::uint8_t operation = alpha < 0.0f ? 6 : 4;
        alpha = std::fabs(alpha);
        const idMD6Anim* const animation =
            GameLib_ResolveMD6AliasForAnimator(animator, animAlias[index]);
        if (animation == nullptr) continue;

        idMD6LeafPlay& leaf = leaves[index];
        if (leaf.anim != animation) {
            leaf.Init(animation, currentTime, 1.0f, wrapMode, weightGroup);
        }
        idMD6Branch& branch = branches[numAddedChannels++];
        InitAddBranch(branch, &leaf, operation, alpha, GetFilterGroup());
        if (previous != nullptr) previous->left = &branch;
        previous = &branch;
    }
    if (numAddedChannels > 1) {
        mergeBranch.currentAlpha = 1.0f;
        mergeBranch.targetAlpha = 1.0f;
        mergeBranch.right = &branches[0];
    }
}
