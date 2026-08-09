#include "gamelib/animstack/animator_facetracks.h"

#include <algorithm>
#include <cstring>

idAnimAliasHandle GameLib_FindMD6Alias(const idDeclMD6* declaration,
    const char* aliasName);
const idMD6Anim* GameLib_LoadFaceSetupAnimation(idAnimStack* stack,
    const char* aliasName, idAnimAliasHandle& aliasHandle);
int GameLib_GetFaceSetupChannelCount(const idMD6Anim* animation);
float GameLib_GetFaceSetupChannelFrame(const idMD6Anim* animation,
    int channelIndex);
void GameLib_ClearPausedLeafAnimMods(idMD6LeafPause& leaf);
void GameLib_AddPausedLeafUserChannelMod(idMD6LeafPause& leaf,
    idUserChannelIndex channel, float value, int previousCount);

namespace {
constexpr const char* FACE_SETUP_ALIAS = "facesetup/facesetup";

void InitMergeBranch(idMD6Branch& branch) {
    std::memset(&branch, 0, sizeof(branch));
    branch.type = idMD6Node::NODE_BRANCH;
    branch.leftTimeOverride = -1;
    branch.rightTimeOverride = -1;
    branch.filterGroup = MD6_WEIGHTGROUP_MAX;
    branch.op = 10;
    branch.blendType = idMD6Branch::BLEND_LINEAR;
}

void InitAddBranch(idMD6Branch& branch, idMD6Node* const right) {
    std::memset(&branch, 0, sizeof(branch));
    branch.type = idMD6Node::NODE_BRANCH;
    branch.left = nullptr;
    branch.right = right;
    branch.leftTimeOverride = -1;
    branch.rightTimeOverride = -1;
    branch.filterGroup = MD6_WEIGHTGROUP_ALL;
    branch.op = 4;
    branch.originBlend = 1;
    branch.currentAlpha = 1.0f;
    branch.targetAlpha = 1.0f;
    branch.blendType = idMD6Branch::BLEND_LINEAR;
}
}

idAnimator_FaceTracks::idAnimator_FaceTracks()
    : idAnimator_Base()
    , leaves(16)
    , branches(16)
    , leafAnimModsTime(16)
    , mergeBranch{}
    , endBranch(nullptr)
    , faceSetupAnimAlias()
    , animModsTime(-1) {
    InitMergeBranch(mergeBranch);
}

bool idAnimator_FaceTracks::HasFaceTracks(
        const idDeclMD6* const declaration) {
    return declaration != nullptr &&
        GameLib_FindMD6Alias(declaration, FACE_SETUP_ALIAS).IsValid();
}

bool idAnimator_FaceTracks::InternalInit(
        const idAnimatorParms_Base& parameters) {
    if (parameters.animStack == nullptr) {
        return false;
    }
    const idMD6Anim* const animation = GameLib_LoadFaceSetupAnimation(
        parameters.animStack, FACE_SETUP_ALIAS, faceSetupAnimAlias);
    if (animation == nullptr) {
        return false;
    }

    const int count = GameLib_GetFaceSetupChannelCount(animation);
    if (!leaves.SetNum(count) || !branches.SetNum(count) ||
            !leafAnimModsTime.SetNum(count)) {
        return false;
    }

    idMD6Branch* previous = nullptr;
    for (int index = 0; index < count; ++index) {
        leafAnimModsTime[index] = -1;
        idMD6LeafPause& leaf = leaves[index];
        leaf.Init(animation,
            GameLib_GetFaceSetupChannelFrame(animation, count - index - 1),
            idMD6Leaf::WRAP_CLAMP, MD6_WEIGHTGROUP_ALL);
        leaf.flags = static_cast<std::int16_t>(leaf.flags | 0x80);

        idMD6Branch& branch = branches[index];
        InitAddBranch(branch, &leaf);
        if (previous != nullptr) {
            previous->left = &branch;
        }
        previous = &branch;
    }

    mergeBranch.currentAlpha = 1.0f;
    mergeBranch.targetAlpha = 1.0f;
    endBranch = count > 1 ? &branches[count - 1] : nullptr;
    mergeBranch.right = count > 1 ? static_cast<idMD6Node*>(&branches[0])
        : count == 1 ? static_cast<idMD6Node*>(&leaves[0]) : nullptr;
    return true;
}

void idAnimator_FaceTracks::InternalPreBlendTree(const idAnimStack*,
        const int currentTime, int) {
    if (endBranch != nullptr) {
        endBranch->left = nullptr;
    }
    if (animModsTime == -1) {
        return;
    }
    if (currentTime > animModsTime) {
        animModsTime = -1;
    }
    for (int index = 0; index < leaves.Num(); ++index) {
        if (currentTime > leafAnimModsTime[index]) {
            leafAnimModsTime[index] = -1;
            GameLib_ClearPausedLeafAnimMods(leaves[index]);
        }
    }
}

void idAnimator_FaceTracks::AddUserChannelMod(
        const idUserChannelIndex userChannel, const float value,
        const int currentTime) {
    animModsTime = (std::max)(animModsTime, currentTime);
    int leafIndex = leaves.Num() - 1;
    while (leafIndex > 0 &&
            leaves[leafIndex - 1].frame <=
                static_cast<float>(userChannel.Get())) {
        --leafIndex;
    }
    if (leafIndex < 0 || leafIndex >= leaves.Num()) {
        return;
    }
    const int previousCount = leafAnimModsTime[leafIndex] == currentTime
        ? leaves[leafIndex].animMods[0].num : 0;
    leafAnimModsTime[leafIndex] = currentTime;
    GameLib_AddPausedLeafUserChannelMod(leaves[leafIndex], userChannel,
        value, previousCount);
}
