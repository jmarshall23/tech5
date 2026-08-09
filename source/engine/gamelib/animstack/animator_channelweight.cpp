#include "gamelib/animstack/animator_channelweight.h"

#include <cstring>
#include <vector>

idMD6Branch* GameLib_AllocMD6Branch(idAnimStack* stack);
idMD6LeafPause* GameLib_AllocMD6LeafPause(idAnimStack* stack);
void GameLib_FreeMD6Branch(idAnimStack* stack, idMD6Branch* branch);
void GameLib_FreeMD6LeafPause(idAnimStack* stack, idMD6LeafPause* leaf);
int GameLib_GetMD6UserChannelCount(const idAnimStack* stack);
const idMD6Anim* GameLib_GetMD6UserChannelAnimation(
    const idAnimStack* stack, int userChannel);
const idMD6Anim* GameLib_GetMD6BaseUserChannelAnimation(
    const idAnimStack* stack);
int GameLib_GetCompressedUserChannelCount(const idMD6Anim* animation);
bool GameLib_SampleControlUserChannels(const idMD6LeafPlay& animation,
    int currentTime, const idGameTimeManager* manager,
    float* channelValues, int channelCount);
void GameLib_SetChannelWeightLeafValue(idMD6LeafPause& leaf, float value);

namespace {
void InitBranch(idMD6Branch& branch, idMD6Node* const left,
        idMD6Node* const right, const float alpha,
        const md6WeightGroup_t filterGroup) {
    std::memset(&branch, 0, sizeof(branch));
    branch.type = idMD6Node::NODE_BRANCH;
    branch.left = left;
    branch.right = right;
    branch.leftTimeOverride = -1;
    branch.rightTimeOverride = -1;
    branch.filterGroup = static_cast<std::uint8_t>(filterGroup);
    branch.op = 4;
    branch.originBlend = 1;
    branch.currentAlpha = alpha;
    branch.targetAlpha = alpha;
    branch.blendType = idMD6Branch::BLEND_LINEAR;
}
}

idAnimator_ChannelWeight::idAnimator_ChannelWeight()
    : idAnimator_Base()
    , userChannelToLeafMap(16)
    , leaves(16)
    , baseAnimation{nullptr, nullptr}
    , mergeBranch(nullptr)
    , controlAnimation(nullptr)
    , filterGroup(MD6_WEIGHTGROUP_ALL)
    , entityNumber(0x1FFF)
    , lockOwner(nullptr) {
}

bool idAnimator_ChannelWeight::InternalIsContributing() const {
    return controlAnimation != nullptr && baseAnimation.animation != nullptr &&
        leaves.Num() > 0 && userChannelToLeafMap.Num() > 0;
}

bool idAnimator_ChannelWeight::InternalInit(
        const idAnimatorParms_Base& parameters) {
    mergeBranch = GameLib_AllocMD6Branch(parameters.animStack);
    baseAnimation.leaf = GameLib_AllocMD6LeafPause(parameters.animStack);
    if (mergeBranch == nullptr || baseAnimation.leaf == nullptr) {
        return false;
    }
    filterGroup = parameters.filterGroup;

    const int channelCount =
        GameLib_GetMD6UserChannelCount(parameters.animStack);
    if (!userChannelToLeafMap.SetNum(channelCount)) return false;
    leaves.Clear();
    for (int channel = 0; channel < channelCount; ++channel) {
        const idMD6Anim* const animation =
            GameLib_GetMD6UserChannelAnimation(parameters.animStack, channel);
        if (animation == nullptr) {
            userChannelToLeafMap[channel] = 0xFFFF;
            continue;
        }
        userChannelToLeafMap[channel] =
            static_cast<unsigned short>(leaves.Num());
        leafAnimation_t record{};
        record.animation = animation;
        leaves.Append(record);
    }

    InitBranch(*mergeBranch, nullptr, nullptr, 0.0f, filterGroup);
    baseAnimation.animation =
        GameLib_GetMD6BaseUserChannelAnimation(parameters.animStack);
    baseAnimation.leaf->Init(baseAnimation.animation, 0.0f,
        idMD6Leaf::WRAP_CLAMP, MD6_WEIGHTGROUP_ALL);

    idMD6Node* tree = baseAnimation.leaf;
    for (int index = 0; index < leaves.Num(); ++index) {
        leafAnimation_t& record = leaves[index];
        record.leaf = GameLib_AllocMD6LeafPause(parameters.animStack);
        record.branch = GameLib_AllocMD6Branch(parameters.animStack);
        if (record.leaf == nullptr || record.branch == nullptr) {
            InternalShutdown(parameters.animStack);
            return false;
        }
        record.leaf->Init(record.animation, 0.0f,
            idMD6Leaf::WRAP_CLAMP, MD6_WEIGHTGROUP_ALL);
        InitBranch(*record.branch, tree, record.leaf, 0.0f, filterGroup);
        tree = record.branch;
    }
    mergeBranch->right = tree;
    return true;
}

void idAnimator_ChannelWeight::InternalShutdown(idAnimStack* const stack) {
    if (mergeBranch != nullptr) {
        GameLib_FreeMD6Branch(stack, mergeBranch);
        mergeBranch = nullptr;
    }
    if (baseAnimation.leaf != nullptr) {
        GameLib_FreeMD6LeafPause(stack, baseAnimation.leaf);
        baseAnimation.leaf = nullptr;
    }
    for (int index = 0; index < leaves.Num(); ++index) {
        leafAnimation_t& record = leaves[index];
        if (record.leaf != nullptr)
            GameLib_FreeMD6LeafPause(stack, record.leaf);
        if (record.branch != nullptr)
            GameLib_FreeMD6Branch(stack, record.branch);
        record.leaf = nullptr;
        record.branch = nullptr;
    }
    userChannelToLeafMap.ClearFree();
    leaves.ClearFree();
}

void idAnimator_ChannelWeight::SetControlAnimation(
        const idMD6LeafPlay* const animation,
        void* const requestedLockOwner) {
    if (lockOwner != nullptr && lockOwner != requestedLockOwner) return;
    const idMD6Anim* const md6Animation =
        animation != nullptr ? animation->anim : nullptr;
    const int channelCount = md6Animation != nullptr
        ? GameLib_GetCompressedUserChannelCount(md6Animation) : 0;
    if (channelCount <= 0 || channelCount > leaves.Num()) {
        controlAnimation = nullptr;
        lockOwner = nullptr;
        return;
    }
    mergeBranch->currentAlpha = 1.0f;
    mergeBranch->targetAlpha = 1.0f;
    controlAnimation = animation;
    lockOwner = animation != nullptr ? requestedLockOwner : nullptr;
}

void idAnimator_ChannelWeight::InternalPreBlendTree(const idAnimStack*,
        const int currentTime, int) {
    if (!InternalIsContributing()) return;
    std::vector<float> channelValues(
        static_cast<std::size_t>(userChannelToLeafMap.Num()), 0.0f);
    if (!GameLib_SampleControlUserChannels(*controlAnimation, currentTime,
            gametimeManager.gameTimeManager, channelValues.data(),
            static_cast<int>(channelValues.size()))) {
        return;
    }
    for (int channel = 0; channel < userChannelToLeafMap.Num(); ++channel) {
        const unsigned short leafIndex = userChannelToLeafMap[channel];
        if (leafIndex != 0xFFFF && leafIndex < leaves.Num()) {
            GameLib_SetChannelWeightLeafValue(
                *leaves[leafIndex].leaf, channelValues[channel]);
        }
    }
}
