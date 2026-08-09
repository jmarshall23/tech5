#include "gamelib/animstack/animator_synced.h"

#include <algorithm>
#include <cstring>

idMD6Branch* GameLib_AllocMD6Branch(idAnimStack* stack);
idMD6LeafPlay* GameLib_AllocMD6LeafPlay(idAnimStack* stack);
void GameLib_FreeMD6Branch(idAnimStack* stack, idMD6Branch* branch);
void GameLib_FreeMD6LeafPlay(idAnimStack* stack, idMD6LeafPlay* leaf);
const idMD6Anim* GameLib_ResolveMD6AliasForAnimator(
    idTreeAnimator* animator, idAnimAliasHandle handle);
bool GameLib_IsMD6LeafPlaying(const idMD6LeafPlay& leaf,
    int currentTime, int ticksPerSecond, bool clampIgnoreExtraFrame);

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
    branch.op = 1;
    branch.originBlend = 1;
    branch.currentAlpha = alpha;
    branch.targetAlpha = alpha;
    branch.blendType = idMD6Branch::BLEND_LINEAR;
}
}

idAnimator_Synced::idAnimator_Synced()
    : idAnimator_Base()
    , leaves{}
    , branches{}
    , mergeBranch(nullptr)
    , anims()
    , aliasHandles()
    , aliasWeights()
    , alphaValues()
    , wrapMode(idMD6Leaf::WRAP_REPEAT)
    , rateScale(1.0f) {
    for (int index = 0; index < 8; ++index) {
        anims.staticList[index] = nullptr;
        aliasHandles.staticList[index].Invalidate();
        aliasWeights.staticList[index] = 0.0f;
        alphaValues.staticList[index] = 0.0f;
    }
}

idAnimator_Synced::~idAnimator_Synced() {
    mergeBranch = nullptr;
}

bool idAnimator_Synced::InternalInit(
        const idAnimatorParms_Base& parameters) {
    mergeBranch = GameLib_AllocMD6Branch(parameters.animStack);
    if (mergeBranch == nullptr) return false;
    InitBranch(*mergeBranch, nullptr, nullptr, 1.0f,
        parameters.filterGroup);
    for (int index = 0; index < 8; ++index) {
        leaves[index] = GameLib_AllocMD6LeafPlay(parameters.animStack);
        if (leaves[index] == nullptr) return false;
    }
    for (int index = 0; index < 7; ++index) {
        branches[index] = GameLib_AllocMD6Branch(parameters.animStack);
        if (branches[index] == nullptr) return false;
    }
    return true;
}

void idAnimator_Synced::InternalShutdown(idAnimStack* const stack) {
    if (mergeBranch != nullptr) {
        GameLib_FreeMD6Branch(stack, mergeBranch);
        mergeBranch = nullptr;
    }
    for (idMD6LeafPlay*& leaf : leaves) {
        if (leaf != nullptr) GameLib_FreeMD6LeafPlay(stack, leaf);
        leaf = nullptr;
    }
    for (idMD6Branch*& branch : branches) {
        if (branch != nullptr) GameLib_FreeMD6Branch(stack, branch);
        branch = nullptr;
    }
}

void idAnimator_Synced::SetAnimHandle(idTreeAnimator* const animator,
        const int currentTime, const int index,
        const idAnimAliasHandle& handle) {
    if (index < 0 || index >= aliasHandles.Num()) return;
    aliasHandles[index] = handle;
    const idMD6Anim* const animation =
        GameLib_ResolveMD6AliasForAnimator(animator, handle);
    anims[index] = animation;
    if (animation != nullptr && leaves[index] != nullptr &&
            leaves[index]->anim != animation) {
        leaves[index]->Init(animation, currentTime, rateScale, wrapMode,
            weightGroup);
    }
}

void idAnimator_Synced::CalcAlphaValuesFromWeights() {
    const int count = (std::max)(0, aliasWeights.Num() - 1);
    alphaValues.SetNum(count);
    float accumulated = 0.0f;
    for (int index = 0; index < count; ++index) {
        accumulated += aliasWeights[index];
        const float denominator = accumulated + aliasWeights[index + 1];
        alphaValues[index] = denominator == 0.0f ? 0.0f
            : (std::max)(0.0f, (std::min)(1.0f,
                aliasWeights[index + 1] / denominator));
    }
}

void idAnimator_Synced::SetAnimHandlesAndWeights(
        idTreeAnimator* const animator, const int currentTime,
        const idAnimAliasHandle* const handles, const int animationCount,
        const float* const weights, const int weightCount) {
    const int safeAnimationCount = (std::max)(0,
        (std::min)(8, animationCount));
    const int safeWeightCount = (std::max)(0,
        (std::min)(8, weightCount));
    aliasHandles.SetNum(safeAnimationCount);
    anims.SetNum(safeAnimationCount);
    aliasWeights.SetNum(safeWeightCount);
    for (int index = 0; index < safeAnimationCount; ++index) {
        aliasHandles[index] = handles[index];
        SetAnimHandle(animator, currentTime, index, handles[index]);
    }
    for (int index = 0; index < safeWeightCount; ++index) {
        aliasWeights[index] = weights[index];
    }
    if (safeAnimationCount > 1) CalcAlphaValuesFromWeights();
    else alphaValues.Clear();
}

bool idAnimator_Synced::IsDone(const idAnimStack*,
        const int currentTime) const {
    for (int index = 0; index < aliasHandles.Num(); ++index) {
        if (leaves[index] != nullptr && GameLib_IsMD6LeafPlaying(
                *leaves[index], currentTime, 60, false)) {
            return false;
        }
    }
    return true;
}

void idAnimator_Synced::InternalEnd(const idAnimStack*, int,
        const idTypesafeNumber<int, gameTimeUnique_t> blendTime) {
    if (blendTime.value > 0) return;
    if (mergeBranch != nullptr) {
        mergeBranch->left = nullptr;
        mergeBranch->right = nullptr;
    }
    aliasHandles.Clear();
    anims.Clear();
    aliasWeights.Clear();
    alphaValues.Clear();
}

void idAnimator_Synced::InternalPreBlendTree(const idAnimStack*,
        const int currentTime, int) {
    if (mergeBranch == nullptr) return;
    mergeBranch->left = nullptr;
    mergeBranch->right = nullptr;
    if (mergeBranch->targetAlpha == 0.0f &&
            (mergeBranch->alphaRate == 0.0f ||
             mergeBranch->currentAlpha == mergeBranch->targetAlpha)) {
        aliasHandles.Clear();
        anims.Clear();
        aliasWeights.Clear();
        alphaValues.Clear();
        return;
    }

    idMD6Node* tree = nullptr;
    for (int index = 0; index < anims.Num(); ++index) {
        idMD6LeafPlay* const leaf = leaves[index];
        if (leaf == nullptr || anims[index] == nullptr) continue;
        if (leaf->anim != anims[index]) {
            leaf->Init(anims[index], currentTime, rateScale, wrapMode,
                weightGroup);
        }
        if (tree == nullptr) {
            tree = leaf;
        } else {
            idMD6Branch* const branch = branches[index - 1];
            const float alpha = index - 1 < alphaValues.Num()
                ? alphaValues[index - 1] : 0.0f;
            InitBranch(*branch, tree, leaf, alpha, GetFilterGroup());
            tree = branch;
        }
    }
    if (anims.Num() > 0) mergeBranch->right = tree;
}
