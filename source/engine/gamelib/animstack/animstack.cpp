#include "gamelib/animstack/animstack.h"

#include "gamelib/animstack/animator_base.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <new>

const char* GameLib_GetAnimatorName(const idAnimator_Base* animator);
void GameLib_SerializeAnimStack(idAnimStack& stack,
    idSerializer* serializer, idClip* clip, int currentTime,
    idGameTimeManager* gameTimeManager);
void GameLib_BlendMD6Tree(idTreeAnimator* animator, idMD6Node* tree,
    int currentTime, idParallelJobList* parallelJobList,
    float* localRotation, float* localScale, float* localTranslation,
    float* localUser);
int GameLib_GetMD6LeafAnimLength(const idMD6LeafPlay& leaf,
    int ticksPerSecond, bool applyRateScale);
void GameLib_SetMD6LeafFrameTime(idMD6LeafPlay& leaf,
    int currentTime, int targetTime);

namespace {
bool IsBranch(const idMD6Node* const node) {
    return node != nullptr && (node->type == idMD6Node::NODE_BRANCH ||
        node->type == idMD6Node::NODE_BLEND_BRANCH ||
        node->type == idMD6Node::NODE_BLENDA_BRANCH ||
        node->type == idMD6Node::NODE_FUSION_BRANCH);
}

void FreeTree(idMD6BlockAlloc& allocator, idMD6Node* node) {
    if (node == nullptr) return;
    if (IsBranch(node)) {
        idMD6Branch* const branch = static_cast<idMD6Branch*>(node);
        idMD6Node* const left = branch->left;
        idMD6Node* const right = branch->right;
        branch->left = nullptr;
        branch->right = nullptr;
        FreeTree(allocator, left);
        FreeTree(allocator, right);
    }
    allocator.Free(node);
}
}

idAnimStack::idAnimStack()
    : treeAnimator(nullptr)
    , md6Allocator()
    , blendStack(16)
    , flags(16)
    , tree(nullptr)
    , pauseTime(-1)
    , skipSerialization(false)
    , typesMemory{}
    , branchMemory{}
    , leafMemory{}
    , serializedNewTree(false)
    , prevSerializedTime(0)
    , curSerializedTime(0)
    , createdFromSnapshot(false)
    , blendedFromSnapshot(false)
    , disableSerialization(false)
    , usedSnapshotNodes()
    , rememberedNodes() {
}

idAnimStack::~idAnimStack() {
    tree = nullptr;
    for (int index = blendStack.Num() - 1; index >= 0; --index)
        ShutdownBlendStackIndex(index);
    treeAnimator = nullptr;
}

void idAnimStack::Init(idTreeAnimator* const animator) {
    treeAnimator = animator;
    tree = nullptr;
}

void idAnimStack::Shutdown() { tree = nullptr; }

void idAnimStack::ShutdownBlendStackIndex(const int index) {
    if (index < 0 || index >= blendStack.Num()) return;
    idAnimator_Base* const animator = blendStack[index];
    if (animator != nullptr &&
            animator->serializeProps.createdThroughSerialization) {
        animator->InternalShutdown(this);
        animator->initialized = false;
        for (idMD6Branch*& serializedTree :
                animator->serializeProps.serializedTrees) {
            if (serializedTree != nullptr) {
                serializedTree->left = nullptr;
                FreeTree(md6Allocator, serializedTree);
                serializedTree = nullptr;
            }
        }
        delete animator;
    }
    if (index < blendStack.Num()) blendStack[index] = nullptr;
}

void idAnimStack::AddAnimator(idAnimator_Base* const animator) {
    if (animator == nullptr || GetAnimatorIndex(animator) >= 0) return;
    int index = 0;
    while (index < blendStack.Num() &&
            blendStack[index]->GetStackPriority() <=
                animator->GetStackPriority()) ++index;
    blendStack.Insert(animator, index);
    flags.Insert(0, index);
}

void idAnimStack::RemoveAnimator(idAnimator_Base* const animator) {
    const int index = GetAnimatorIndex(animator);
    if (index < 0) return;
    blendStack.RemoveIndex(index);
    flags.RemoveIndex(index);
    tree = nullptr;
}

idAnimator_Base* idAnimStack::GetAnimator(const char* const name) {
    if (name == nullptr) return nullptr;
    for (int index = 0; index < blendStack.Num(); ++index) {
        const char* const animatorName = GameLib_GetAnimatorName(
            blendStack[index]);
        if (animatorName != nullptr && _stricmp(animatorName, name) == 0)
            return blendStack[index];
    }
    return nullptr;
}

int idAnimStack::GetAnimatorIndex(
        const idAnimator_Base* const animator) const {
    return blendStack.FindIndex(const_cast<idAnimator_Base*>(animator));
}

idAnimator_Base* idAnimStack::GetAnimatorByIndex(const int index) const {
    return index >= 0 && index < blendStack.Num()
        ? blendStack[index] : nullptr;
}

idAnimator_Base* idAnimStack::GetAnimatorBySerializeType(
        const serializeType_t type) {
    for (int index = 0; index < blendStack.Num(); ++index)
        if (blendStack[index]->GetSerializeType() == type)
            return blendStack[index];
    return nullptr;
}

void idAnimStack::SetAnimatorFlag(const idAnimator_Base* const animator,
        const animatorFlag_t flag) {
    const int index = GetAnimatorIndex(animator);
    if (index >= 0) flags[index] |= static_cast<unsigned char>(flag);
}

void idAnimStack::ClearAnimatorFlag(const idAnimator_Base* const animator,
        const animatorFlag_t flag) {
    const int index = GetAnimatorIndex(animator);
    if (index >= 0) flags[index] &=
        static_cast<unsigned char>(~static_cast<unsigned char>(flag));
}

bool idAnimStack::IsAnimatorFlagSet(const idAnimator_Base* const animator,
        const animatorFlag_t flag) const {
    const int index = GetAnimatorIndex(animator);
    return index >= 0 &&
        (flags[index] & static_cast<unsigned char>(flag)) != 0;
}

void idAnimStack::Pause(
        const idTypesafeNumber<int, gameTimeUnique_t> currentTime) {
    if (pauseTime.value < 0) pauseTime = currentTime;
    for (int index = 0; index < blendStack.Num(); ++index)
        blendStack[index]->Pause(this, currentTime);
}

void idAnimStack::Unpause(
        const idTypesafeNumber<int, gameTimeUnique_t> currentTime) {
    if (pauseTime.value < 0) return;
    pauseTime.value = -1;
    for (int index = 0; index < blendStack.Num(); ++index)
        blendStack[index]->Unpause(this, currentTime);
}

void idAnimStack::FreeSerializedAnimators() {
    for (int index = blendStack.Num() - 1; index >= 0; --index) {
        if (blendStack[index] != nullptr &&
                blendStack[index]->serializeProps.createdThroughSerialization) {
            ShutdownBlendStackIndex(index);
            if (index < blendStack.Num()) {
                blendStack.RemoveIndex(index);
                flags.RemoveIndex(index);
            }
        }
    }
}

void idAnimStack::SerializeSnapshot(idSerializer* const serializer,
        idClip* const clip, const int currentTime,
        idGameTimeManager* const gameTimeManager) {
    if (skipSerialization || disableSerialization) return;
    prevSerializedTime = curSerializedTime;
    curSerializedTime = currentTime;
    GameLib_SerializeAnimStack(*this, serializer, clip, currentTime,
        gameTimeManager);
    for (int index = 0; index < blendStack.Num(); ++index) {
        if ((flags[index] & ANIMATORFLAG_SERIALIZE) != 0)
            blendStack[index]->SerializeSnapshot(serializer);
    }
    serializedNewTree = false;
    md6Allocator.Condense();
}

void idAnimStack::BlendSnapshot(const int currentTime,
        const int previousTime, const int gameMillisecondsPerFrame,
        const float fraction, idGameTimeManager* const gameTimeManager,
        idParallelJobList* const parallelJobList) {
    for (int index = 0; index < blendStack.Num(); ++index) {
        if ((flags[index] & ANIMATORFLAG_ENABLED) != 0)
            blendStack[index]->PreBlendSnapshot(this, currentTime, 60,
                fraction);
    }
    BlendStackInternal(currentTime, previousTime, gameMillisecondsPerFrame,
        60, gameTimeManager, parallelJobList, nullptr, nullptr, nullptr,
        nullptr);
    blendedFromSnapshot = true;
}

void idAnimStack::AddNodeToSyncGroups(idList<syncGroup_t, 5>& groups,
        idMD6LeafPlay* const node, const float alpha) {
    for (int index = 0; index < groups.Num(); ++index) {
        if (groups[index].groupNumber == node->syncGroup) {
            syncNode_t record{node, alpha};
            groups[index].nodes.Append(record);
            return;
        }
    }
    syncGroup_t group{};
    group.groupNumber = node->syncGroup;
    group.fraction = 0.0f;
    group.syncRate = 0.0f;
    group.nodes.Append(syncNode_t{node, alpha});
    groups.Append(group);
}

void idAnimStack::PreSynchronizeNode_r(idList<syncGroup_t, 5>& groups,
        idMD6Node* const node, const float branchAlpha) {
    if (node == nullptr) return;
    if (node->type == idMD6Node::NODE_LEAF_PLAY) {
        idMD6LeafPlay* const leaf = static_cast<idMD6LeafPlay*>(node);
        if (leaf->syncEnabled != 0) AddNodeToSyncGroups(groups, leaf,
            branchAlpha);
        return;
    }
    if (!IsBranch(node)) return;
    idMD6Branch* const branch = static_cast<idMD6Branch*>(node);
    const float rightAlpha = branch->currentAlpha * branchAlpha;
    const float leftAlpha = (1.0f - branch->currentAlpha) * branchAlpha;
    PreSynchronizeNode_r(groups, branch->right, rightAlpha);
    PreSynchronizeNode_r(groups, branch->left, leftAlpha);
}

void idAnimStack::UpdateSynchronization(const int currentTime,
        const int previousTime, int, const int ticksPerSecond) {
    idList<syncGroup_t, 5> groups(4);
    PreSynchronizeNode_r(groups, tree, 1.0f);
    const float elapsedSeconds =
        static_cast<float>(currentTime - previousTime) * 0.001f;
    for (int groupIndex = 0; groupIndex < groups.Num(); ++groupIndex) {
        syncGroup_t& group = groups[groupIndex];
        if (group.nodes.Num() == 0) continue;
        float alphaTotal = 0.0f;
        float weightedRate = 0.0f;
        syncNode_t* reference = &group.nodes[0];
        for (int nodeIndex = 0; nodeIndex < group.nodes.Num(); ++nodeIndex) {
            syncNode_t& syncNode = group.nodes[nodeIndex];
            const int length = GameLib_GetMD6LeafAnimLength(*syncNode.node,
                ticksPerSecond, false);
            if (length > 0 && syncNode.alpha != 0.0f) {
                alphaTotal += syncNode.alpha;
                weightedRate += syncNode.alpha /
                    (static_cast<float>(length) * 0.001f);
                if (syncNode.alpha > reference->alpha) reference = &syncNode;
            }
        }
        if (alphaTotal <= 0.0f) continue;
        group.syncRate = weightedRate / alphaTotal;
        const int referenceLength = GameLib_GetMD6LeafAnimLength(
            *reference->node, ticksPerSecond, false);
        if (referenceLength <= 0) continue;
        float fraction = static_cast<float>(previousTime -
            reference->node->startTime) / static_cast<float>(referenceLength);
        fraction = fraction - std::floor(fraction +
            elapsedSeconds * group.syncRate) +
            elapsedSeconds * group.syncRate;
        if (fraction < 0.0f) fraction += 1.0f;
        group.fraction = fraction;
        for (int nodeIndex = 0; nodeIndex < group.nodes.Num(); ++nodeIndex) {
            syncNode_t& syncNode = group.nodes[nodeIndex];
            const int length = GameLib_GetMD6LeafAnimLength(*syncNode.node,
                ticksPerSecond, false);
            GameLib_SetMD6LeafFrameTime(*syncNode.node, currentTime,
                static_cast<int>(static_cast<float>(length) * fraction));
        }
    }
}

void idAnimStack::BlendStackInternal(const int currentTime,
        const int previousTime, const int gameMillisecondsPerFrame,
        const int ticksPerSecond, idGameTimeManager*,
        idParallelJobList* const parallelJobList, float* localRotation,
        float* localScale, float* localTranslation, float* localUser) {
    tree = nullptr;
    for (int index = 0; index < blendStack.Num(); ++index) {
        idAnimator_Base* const animator = blendStack[index];
        if ((flags[index] & ANIMATORFLAG_ENABLED) == 0) continue;
        animator->InternalPreBlendTree(this, currentTime, ticksPerSecond);
        idMD6Branch* const branch = animator->InternalGetMergeBranch();
        if (branch != nullptr && animator->IsContributing()) {
            branch->left = tree;
            tree = branch;
            flags[index] |= ANIMATORFLAG_CONTRIBUTED_LAST_SERIALIZE;
        } else {
            flags[index] &= static_cast<unsigned char>(
                ~ANIMATORFLAG_CONTRIBUTED_LAST_SERIALIZE);
        }
    }
    UpdateSynchronization(currentTime, previousTime,
        gameMillisecondsPerFrame, ticksPerSecond);
    GameLib_BlendMD6Tree(treeAnimator, tree, currentTime, parallelJobList,
        localRotation, localScale, localTranslation, localUser);
    for (int index = 0; index < blendStack.Num(); ++index)
        blendStack[index]->InternalPostBlendTree(this, currentTime);
}

int GameLib_GetAnimatorIndex(const idAnimStack* stack,
        const idAnimator_Base* animator) {
    return stack != nullptr ? stack->GetAnimatorIndex(animator) : -1;
}
void GameLib_AddAnimator(idAnimStack* stack,
        idAnimator_Base* animator) {
    if (stack != nullptr) stack->AddAnimator(animator);
}
void GameLib_RemoveAnimator(idAnimStack* stack,
        idAnimator_Base* animator) {
    if (stack != nullptr) stack->RemoveAnimator(animator);
}
void GameLib_SetAnimatorFlag(idAnimStack* stack,
        idAnimator_Base* animator, int flag) {
    if (stack != nullptr) stack->SetAnimatorFlag(animator,
        static_cast<idAnimStack::animatorFlag_t>(flag));
}
void GameLib_ClearAnimatorFlag(idAnimStack* stack,
        idAnimator_Base* animator, int flag) {
    if (stack != nullptr) stack->ClearAnimatorFlag(animator,
        static_cast<idAnimStack::animatorFlag_t>(flag));
}
bool GameLib_IsAnimatorFlagSet(const idAnimStack* stack,
        const idAnimator_Base* animator, int flag) {
    return stack != nullptr && stack->IsAnimatorFlagSet(animator,
        static_cast<idAnimStack::animatorFlag_t>(flag));
}
idMD6Branch* GameLib_AllocMD6Branch(idAnimStack* stack) {
    return stack != nullptr ? static_cast<idMD6Branch*>(
        stack->md6Allocator.Alloc(idMD6Node::NODE_BRANCH)) : nullptr;
}
idMD6LeafPlay* GameLib_AllocMD6LeafPlay(idAnimStack* stack) {
    return stack != nullptr ? static_cast<idMD6LeafPlay*>(
        stack->md6Allocator.Alloc(idMD6Node::NODE_LEAF_PLAY)) : nullptr;
}
idMD6LeafPause* GameLib_AllocMD6LeafPause(idAnimStack* stack) {
    return stack != nullptr ? static_cast<idMD6LeafPause*>(
        stack->md6Allocator.Alloc(idMD6Node::NODE_LEAF_PAUSE)) : nullptr;
}
void GameLib_FreeMD6Branch(idAnimStack* stack,
        idMD6Branch* branch) {
    if (stack != nullptr) stack->md6Allocator.Free(branch);
}
void GameLib_FreeMD6LeafPlay(idAnimStack* stack,
        idMD6LeafPlay* leaf) {
    if (stack != nullptr) stack->md6Allocator.Free(leaf);
}
void GameLib_FreeMD6LeafPause(idAnimStack* stack,
        idMD6LeafPause* leaf) {
    if (stack != nullptr) stack->md6Allocator.Free(leaf);
}
void GameLib_FreeMD6Tree(idAnimStack* stack, idMD6Node* root) {
    if (stack != nullptr) FreeTree(stack->md6Allocator, root);
}
idTreeAnimator* GameLib_GetTreeAnimator(idAnimStack* stack) {
    return stack != nullptr ? stack->treeAnimator : nullptr;
}
idTreeAnimator* GameLib_GetTreeAnimator(const idAnimStack* stack) {
    return stack != nullptr ? stack->treeAnimator : nullptr;
}
bool GameLib_IsMD6NodeValid(const idMD6Node* node) {
    return node != nullptr && node->type != idMD6Node::NODE_NONE;
}
int GameLib_GetGameTicksPerSecond() { return 60; }
