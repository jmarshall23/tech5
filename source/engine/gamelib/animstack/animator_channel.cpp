#include "gamelib/animstack/animator_channel.h"

#include <algorithm>
#include <cmath>
#include <cstring>

idMD6Branch* GameLib_AllocMD6Branch(idAnimStack* stack);
idMD6LeafPlay* GameLib_AllocMD6LeafPlay(idAnimStack* stack);
void GameLib_FreeMD6Branch(idAnimStack* stack, idMD6Branch* branch);
void GameLib_FreeMD6LeafPlay(idAnimStack* stack, idMD6LeafPlay* leaf);
bool GameLib_IsMD6NodeValid(const idMD6Node* node);
int GameLib_GetBlendDurationMS(const blendParms_t& parameters,
    const idMD6Anim* destination);
void GameLib_GetBlendDestinationFrames(const blendParms_t& parameters,
    const idMD6Anim* destination, std::int16_t& firstFrame,
    std::int16_t& duration);
bool GameLib_IsMD6LeafPlaying(const idMD6LeafPlay& leaf,
    int currentTime, int ticksPerSecond, bool clampIgnoreExtraFrame);
const idMD6Anim* GameLib_ResolveMD6Alias(const idAnimStack* stack,
    idAnimAliasHandle alias, int selection);
int GameLib_GetMD6AliasAnimationCount(const idAnimStack* stack,
    idAnimAliasHandle alias);
bool GameLib_MD6AliasContainsAnimation(const idAnimStack* stack,
    idAnimAliasHandle alias, const idMD6Anim* animation);

namespace {

void InitBranch(idMD6Branch& branch) {
    std::memset(&branch, 0, sizeof(branch));
    branch.type = idMD6Node::NODE_BRANCH;
    branch.filterGroup = MD6_WEIGHTGROUP_ALL;
    branch.currentAlpha = 1.0f;
    branch.targetAlpha = 1.0f;
    branch.blendType = idMD6Branch::BLEND_LINEAR;
}

bool IsBranchNode(const idMD6Node* const node) {
    if (node == nullptr) return false;
    return node->type == idMD6Node::NODE_BRANCH
        || node->type == idMD6Node::NODE_BLEND_BRANCH
        || node->type == idMD6Node::NODE_BLENDA_BRANCH
        || node->type == idMD6Node::NODE_FUSION_BRANCH;
}

idMD6LeafPlay* LastPlayLeaf(idMD6Node* node) {
    while (node != nullptr && IsBranchNode(node)) {
        idMD6Branch* const branch = static_cast<idMD6Branch*>(node);
        node = branch->right != nullptr ? branch->right : branch->left;
    }
    return node != nullptr && node->type == idMD6Node::NODE_LEAF_PLAY
        ? static_cast<idMD6LeafPlay*>(node) : nullptr;
}

} // namespace

idAnimator_Channel::idAnimator_Channel()
    : idAnimator_Base()
    , leaves{nullptr, nullptr, nullptr}
    , branches{nullptr, nullptr}
    , mergeBranch(nullptr)
    , freeLeaves{nullptr, nullptr, nullptr}
    , freeBranches{nullptr, nullptr}
    , random(0)
    , numFreeLeaves(0)
    , numFreeBranches(0)
    , blendOutDurationMS(0)
    , reserved(0)
    , omitFreeLeafWarning(0)
    , forceFree(0) {
}

idAnimator_Channel::~idAnimator_Channel() = default;

bool idAnimator_Channel::InternalInit(
        const idAnimatorParms_Base& parameters) {
    if (parameters.animStack == nullptr) return false;
    mergeBranch = GameLib_AllocMD6Branch(parameters.animStack);
    if (mergeBranch == nullptr) return false;
    InitBranch(*mergeBranch);
    for (int i = 0; i < 3; ++i) {
        leaves[i] = GameLib_AllocMD6LeafPlay(parameters.animStack);
        if (leaves[i] == nullptr) return false;
        freeLeaves[numFreeLeaves++] = leaves[i];
    }
    for (int i = 0; i < 2; ++i) {
        branches[i] = GameLib_AllocMD6Branch(parameters.animStack);
        if (branches[i] == nullptr) return false;
        InitBranch(*branches[i]);
        freeBranches[numFreeBranches++] = branches[i];
    }
    return true;
}

void idAnimator_Channel::InternalShutdown(idAnimStack* const stack) {
    if (mergeBranch != nullptr) {
        GameLib_FreeMD6Branch(stack, mergeBranch);
        mergeBranch = nullptr;
    }
    for (int i = 0; i < 3; ++i) {
        if (leaves[i] != nullptr) GameLib_FreeMD6LeafPlay(stack, leaves[i]);
        leaves[i] = nullptr;
        freeLeaves[i] = nullptr;
    }
    for (int i = 0; i < 2; ++i) {
        if (branches[i] != nullptr) GameLib_FreeMD6Branch(stack, branches[i]);
        branches[i] = nullptr;
        freeBranches[i] = nullptr;
    }
    numFreeLeaves = 0;
    numFreeBranches = 0;
}

void idAnimator_Channel::ClearAnimator() {
    InternalEnd(nullptr, 0, idTypesafeNumber<int, gameTimeUnique_t>(0));
}

void idAnimator_Channel::FreeTree(idMD6Node* const node) {
    if (node == nullptr) return;
    if (IsBranchNode(node)) {
        idMD6Branch* const branch = static_cast<idMD6Branch*>(node);
        FreeTree(branch->left);
        FreeTree(branch->right);
        branch->left = nullptr;
        branch->right = nullptr;
        for (int i = 0; i < numFreeBranches; ++i)
            if (freeBranches[i] == branch) return;
        if (numFreeBranches < 2) freeBranches[numFreeBranches++] = branch;
    } else if (node->type == idMD6Node::NODE_LEAF_PLAY) {
        idMD6LeafPlay* const leaf = static_cast<idMD6LeafPlay*>(node);
        for (int i = 0; i < numFreeLeaves; ++i)
            if (freeLeaves[i] == leaf) return;
        if (numFreeLeaves < 3) freeLeaves[numFreeLeaves++] = leaf;
    }
}

void idAnimator_Channel::ForceFreeLeaf() {
    if (mergeBranch == nullptr || mergeBranch->right == nullptr) return;
    idMD6Node* node = mergeBranch->right;
    idMD6Branch* parent = nullptr;
    while (IsBranchNode(node)) {
        parent = static_cast<idMD6Branch*>(node);
        node = parent->left != nullptr ? parent->left : parent->right;
    }
    if (node == nullptr || node->type != idMD6Node::NODE_LEAF_PLAY) return;
    if (parent == nullptr) {
        mergeBranch->right = nullptr;
    } else if (parent->left == node) {
        parent->left = nullptr;
    } else {
        parent->right = nullptr;
    }
    FreeTree(node);
}

idMD6LeafPlay* idAnimator_Channel::AllocLeaf() {
    if (numFreeLeaves == 0 && forceFree) ForceFreeLeaf();
    if (numFreeLeaves == 0) return nullptr;
    return freeLeaves[--numFreeLeaves];
}

idMD6LeafPlay* idAnimator_Channel::GetLastPlayedLeaf() const {
    return mergeBranch != nullptr ? LastPlayLeaf(mergeBranch->right) : nullptr;
}

void idAnimator_Channel::InternalEnd(const idAnimStack*, int,
        const idTypesafeNumber<int, gameTimeUnique_t> blendTime) {
    if (mergeBranch == nullptr || blendTime.value > 0) return;
    FreeTree(mergeBranch->right);
    mergeBranch->left = nullptr;
    mergeBranch->right = nullptr;
}

bool idAnimator_Channel::IsDone(const idAnimStack* const stack,
        const int currentTime) const {
    return IsDone(stack, currentTime, false);
}
bool idAnimator_Channel::IsDone(const idAnimStack*, const int currentTime,
        const bool clampIgnoreExtraFrame) const {
    const idMD6LeafPlay* const leaf = GetLastPlayedLeaf();
    if (leaf == nullptr || !GameLib_IsMD6NodeValid(leaf)) return true;
    return !GameLib_IsMD6LeafPlaying(*leaf, currentTime,
        60, clampIgnoreExtraFrame);
}

bool idAnimator_Channel::StartNode(idMD6Node* const node,
        const int currentTime, const idMD6Leaf::wrapMode_t wrap,
        const blendParms_t& parameters, const int requestedBlendOut) {
    (void)currentTime;
    if (mergeBranch == nullptr || node == nullptr) return false;
    const int duration = (std::max)(0,
        GameLib_GetBlendDurationMS(parameters,
            node->type == idMD6Node::NODE_LEAF_PLAY
                ? static_cast<idMD6LeafPlay*>(node)->anim : nullptr));
    idMD6Node* const oldTree = mergeBranch->right;
    if (oldTree != nullptr && duration > 0) {
        if (numFreeBranches == 0) return false;
        idMD6Branch* const blend = freeBranches[--numFreeBranches];
        InitBranch(*blend);
        blend->left = oldTree;
        blend->right = node;
        blend->filterGroup = static_cast<std::uint8_t>(GetFilterGroup());
        blend->originBlend = static_cast<std::uint8_t>(
            parameters.parms.originBlend);
        blend->blendType = static_cast<idMD6Branch::blendType_t>(
            (std::max)(0, (std::min)(3,
                static_cast<int>(parameters.parms.blendType))));
        blend->currentAlpha = 0.0f;
        blend->targetAlpha = 1.0f;
        blend->alphaRate = 1000.0f / static_cast<float>(duration);
        mergeBranch->right = blend;
    } else {
        if (oldTree != nullptr) FreeTree(oldTree);
        mergeBranch->right = node;
    }
    mergeBranch->targetAlpha = 1.0f;
    if (mergeBranch->currentAlpha <= 0.0f) mergeBranch->currentAlpha = 1.0f;
    mergeBranch->alphaRate = 0.0f;
    blendOutDurationMS = static_cast<std::int16_t>(wrap == idMD6Leaf::WRAP_REPEAT
        ? 0 : (requestedBlendOut >= 0 ? requestedBlendOut : duration));
    return true;
}

bool idAnimator_Channel::StartLeaf(const idMD6Anim* const animation,
        const int currentTime, const float rateScale,
        const idMD6Leaf::wrapMode_t wrap,
        const blendParms_t& parameters, const int blendOut,
        idMD6LeafPlay** const leafStarted) {
    if (animation == nullptr) return false;
    idMD6LeafPlay* const leaf = AllocLeaf();
    if (leaf == nullptr) return false;
    std::int16_t firstFrame = 0;
    std::int16_t duration = 0;
    GameLib_GetBlendDestinationFrames(parameters, animation,
        firstFrame, duration);
    (void)firstFrame;
    (void)duration;
    leaf->Init(animation, currentTime, rateScale, wrap, weightGroup);
    if (!StartNode(leaf, currentTime, wrap, parameters, blendOut)) {
        freeLeaves[numFreeLeaves++] = leaf;
        return false;
    }
    if (leafStarted != nullptr) *leafStarted = leaf;
    return true;
}

bool idAnimator_Channel::PlayAnim(const idAnimStack*,
        const idMD6Anim* const animation, const int currentTime,
        const float rateScale, const blendParms_t& parameters,
        const int blendOut, idMD6LeafPlay** const leafStarted) {
    return StartLeaf(animation, currentTime, rateScale,
        idMD6Leaf::WRAP_CLAMP, parameters, blendOut, leafStarted);
}
bool idAnimator_Channel::CycleAnim(const idAnimStack*,
        const idMD6Anim* const animation, const int currentTime,
        const float rateScale, const blendParms_t& parameters,
        idMD6LeafPlay** const leafStarted) {
    return StartLeaf(animation, currentTime, rateScale,
        idMD6Leaf::WRAP_REPEAT, parameters,
        GameLib_GetBlendDurationMS(parameters, animation), leafStarted);
}
bool idAnimator_Channel::PlayAnim(const idAnimStack* const stack,
        const idAnimAliasHandle& alias, const int currentTime,
        const float rateScale, const blendParms_t& parameters,
        const int blendOut, idMD6LeafPlay** const leafStarted) {
    const int count = GameLib_GetMD6AliasAnimationCount(stack, alias);
    const idMD6Anim* const animation = count > 0
        ? GameLib_ResolveMD6Alias(stack, alias, random.RandomInt(count))
        : nullptr;
    return PlayAnim(stack, animation, currentTime, rateScale,
        parameters, blendOut, leafStarted);
}
bool idAnimator_Channel::CycleAnim(const idAnimStack* const stack,
        const idAnimAliasHandle& alias, const int currentTime,
        const float rateScale, const blendParms_t& parameters,
        idMD6LeafPlay** const leafStarted) {
    const int count = GameLib_GetMD6AliasAnimationCount(stack, alias);
    const idMD6Anim* const animation = count > 0
        ? GameLib_ResolveMD6Alias(stack, alias, random.RandomInt(count))
        : nullptr;
    return CycleAnim(stack, animation, currentTime, rateScale,
        parameters, leafStarted);
}

bool idAnimator_Channel::IsAnimPlaying(const idAnimStack* const stack,
        const idAnimAliasHandle& alias, const int currentTime) const {
    idMD6Node* pending[8]{};
    int count = 0;
    if (mergeBranch != nullptr && mergeBranch->right != nullptr)
        pending[count++] = mergeBranch->right;
    while (count > 0) {
        idMD6Node* const node = pending[--count];
        if (IsBranchNode(node)) {
            idMD6Branch* const branch = static_cast<idMD6Branch*>(node);
            if (branch->left != nullptr && count < 8)
                pending[count++] = branch->left;
            if (branch->right != nullptr && count < 8)
                pending[count++] = branch->right;
        } else if (node->type == idMD6Node::NODE_LEAF_PLAY) {
            idMD6LeafPlay* const leaf = static_cast<idMD6LeafPlay*>(node);
            if (GameLib_IsMD6LeafPlaying(*leaf, currentTime, 60, false)
                    && GameLib_MD6AliasContainsAnimation(stack, alias,
                        leaf->anim)) return true;
        }
    }
    return false;
}

void idAnimator_Channel::InternalPreBlendTree(const idAnimStack*,
        int, const int ticksPerSecond) {
    if (mergeBranch == nullptr || mergeBranch->right == nullptr) return;
    idMD6Node* node = mergeBranch->right;
    if (!IsBranchNode(node)) return;
    idMD6Branch* const blend = static_cast<idMD6Branch*>(node);
    if (blend == mergeBranch || blend->alphaRate == 0.0f) return;
    const float seconds = ticksPerSecond > 0
        ? 1.0f / static_cast<float>(ticksPerSecond) : 1.0f / 60.0f;
    blend->currentAlpha = (std::min)(blend->targetAlpha,
        blend->currentAlpha + blend->alphaRate * seconds);
    if (blend->currentAlpha >= blend->targetAlpha) {
        idMD6Node* const completed = blend->right;
        FreeTree(blend->left);
        blend->left = nullptr;
        blend->right = nullptr;
        if (numFreeBranches < 2) freeBranches[numFreeBranches++] = blend;
        mergeBranch->right = completed;
    }
}

