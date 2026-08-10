#include "models/skeletalanimation/md6blockalloc.h"
#include "models/skeletalanimation/md6animtree.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <malloc.h>
#include <new>

namespace {

struct alignas(16) BlockRecord {
    BlockRecord* next;
    alignas(16) unsigned char storage[1];
};

unsigned int RecoveredNodeSize(idMD6Node::nodeType_t type) {
    switch (type) {
    case idMD6Node::NODE_BRANCH: return 40;
    case idMD6Node::NODE_LEAF_PAUSE: return 80;
    case idMD6Node::NODE_LEAF_PLAY: return 24;
    case idMD6Node::NODE_BLEND_BRANCH: return 156;
    case idMD6Node::NODE_BLENDA_BRANCH: return 84;
    case idMD6Node::NODE_FUSION_BRANCH: return 172;
    case idMD6Node::NODE_BEST_LEAF: return 92;
    case idMD6Node::NODE_TAG_FILTER: return 16;
    default: return 0;
    }
}

std::size_t AllocationSize(idMD6Node::nodeType_t type) {
    std::size_t size = RecoveredNodeSize(type);
    switch (type) {
    case idMD6Node::NODE_BRANCH:
        return (std::max)(size, sizeof(idMD6Branch));
    case idMD6Node::NODE_LEAF_PAUSE:
        return (std::max)(size, sizeof(idMD6LeafPause));
    case idMD6Node::NODE_LEAF_PLAY:
        return (std::max)(size, sizeof(idMD6LeafPlay));
    case idMD6Node::NODE_BLEND_BRANCH:
        return (std::max)(size, sizeof(idMD6BlendBranch));
    case idMD6Node::NODE_BLENDA_BRANCH:
        return (std::max)(size, sizeof(idMD6BlendAdditiveBranch));
    case idMD6Node::NODE_FUSION_BRANCH:
        return (std::max)(size, sizeof(idMD6FusionBranch));
    case idMD6Node::NODE_BEST_LEAF:
        return (std::max)(size, sizeof(idMD6BestLeaf));
    case idMD6Node::NODE_TAG_FILTER:
        return (std::max)(size, sizeof(idMD6TagFilter));
    default:
        return 0;
    }
}

void DestroyNode(idMD6Node* node) {
    if (node == nullptr) return;
    switch (node->type) {
    case idMD6Node::NODE_LEAF_PAUSE:
        idMD6AnimTree::ReleaseAnimMods(
            *static_cast<idMD6LeafPause*>(node));
        break;
    case idMD6Node::NODE_BLEND_BRANCH:
        static_cast<idMD6BlendBranch*>(node)->~idMD6BlendBranch();
        break;
    case idMD6Node::NODE_BLENDA_BRANCH:
        static_cast<idMD6BlendAdditiveBranch*>(node)
            ->~idMD6BlendAdditiveBranch();
        break;
    case idMD6Node::NODE_FUSION_BRANCH:
        static_cast<idMD6FusionBranch*>(node)->~idMD6FusionBranch();
        break;
    case idMD6Node::NODE_BEST_LEAF:
        static_cast<idMD6BestLeaf*>(node)->~idMD6BestLeaf();
        break;
    default:
        break;
    }
}

idMD6RecoveredBlockState* StateForType(idMD6BlockAlloc& allocator,
    idMD6Node::nodeType_t type) {
    switch (type) {
    case idMD6Node::NODE_BRANCH: return &allocator.branches;
    case idMD6Node::NODE_LEAF_PAUSE: return &allocator.pauseLeaves;
    case idMD6Node::NODE_LEAF_PLAY: return &allocator.playLeaves;
    case idMD6Node::NODE_BLEND_BRANCH: return &allocator.blendBranches;
    case idMD6Node::NODE_BLENDA_BRANCH:
        return &allocator.blendAdditiveBranches;
    case idMD6Node::NODE_FUSION_BRANCH: return &allocator.fusionBranches;
    case idMD6Node::NODE_BEST_LEAF: return &allocator.bestLeaves;
    case idMD6Node::NODE_TAG_FILTER: return &allocator.tagFilters;
    default: return nullptr;
    }
}

void InitializeNode(idMD6Node* node, std::size_t size,
    idMD6Node::nodeType_t type) {
    std::memset(node, 0, size);
    if (type == idMD6Node::NODE_BLEND_BRANCH) {
        new (node) idMD6BlendBranch();
    } else if (type == idMD6Node::NODE_BLENDA_BRANCH) {
        new (node) idMD6BlendAdditiveBranch();
    } else if (type == idMD6Node::NODE_FUSION_BRANCH) {
        new (node) idMD6FusionBranch();
    } else if (type == idMD6Node::NODE_BEST_LEAF) {
        new (node) idMD6BestLeaf();
    } else if (type == idMD6Node::NODE_TAG_FILTER) {
        new (node) idMD6TagFilter();
    } else if (type == idMD6Node::NODE_BRANCH) {
        node->type = static_cast<std::uint8_t>(type);
        idMD6Branch* branch = static_cast<idMD6Branch*>(node);
        branch->left = nullptr;
        branch->right = nullptr;
        branch->leftTimeOverride = -1;
        branch->rightTimeOverride = -1;
        branch->filterGroup = MD6_WEIGHTGROUP_MAX;
        branch->op = 10;
        branch->originBlend = 0;
        branch->currentAlpha = 0.0f;
        branch->targetAlpha = 0.0f;
        branch->alphaRate = 0.0f;
        branch->blendType = idMD6Branch::BLEND_LINEAR;
    } else if (type == idMD6Node::NODE_LEAF_PAUSE) {
        idMD6AnimTree::Clear(*static_cast<idMD6LeafPause*>(node));
    } else if (type == idMD6Node::NODE_LEAF_PLAY) {
        idMD6AnimTree::Clear(*static_cast<idMD6LeafPlay*>(node));
    }
}

idMD6Node* AllocateFromState(idMD6RecoveredBlockState& state,
    idMD6Node::nodeType_t type) {
    if (!state.allowAllocs) {
        return nullptr;
    }

    const std::size_t nodeSize = AllocationSize(type);
    if (nodeSize == 0) {
        return nullptr;
    }

    void* storage = state.free;
    if (storage != nullptr) {
        state.free = *static_cast<void**>(storage);
    } else {
        const std::size_t allocationSize =
            offsetof(BlockRecord, storage) + nodeSize;
        BlockRecord* block = static_cast<BlockRecord*>(
            _aligned_malloc(allocationSize, 16));
        if (block == nullptr) {
            return nullptr;
        }
        block->next = static_cast<BlockRecord*>(state.blocks);
        state.blocks = block;
        storage = block->storage;
        ++state.total;
    }

    ++state.active;
    idMD6Node* node = static_cast<idMD6Node*>(storage);
    InitializeNode(node, nodeSize, type);
    return node;
}

void ReleaseStateBlocks(idMD6RecoveredBlockState& state) {
    BlockRecord* block = static_cast<BlockRecord*>(state.blocks);
    while (block != nullptr) {
        BlockRecord* next = block->next;
        _aligned_free(block);
        block = next;
    }
    state.blocks = nullptr;
    state.free = nullptr;
    state.total = 0;
    state.active = 0;
}

idMD6RecoveredBlockState InitialState() {
    idMD6RecoveredBlockState state = {};
    state.allowAllocs = true;
    return state;
}

} // namespace

idMD6BlockAlloc::idMD6BlockAlloc()
    : playLeaves(InitialState())
    , pauseLeaves(InitialState())
    , branches(InitialState())
    , blendBranches(InitialState())
    , blendAdditiveBranches(InitialState())
    , fusionBranches(InitialState())
    , bestLeaves(InitialState())
    , tagFilters(InitialState()) {
}

idMD6BlockAlloc::~idMD6BlockAlloc() {
    for (int index = 0; index < nodes.Num(); ++index) {
        DestroyNode(nodes[index]);
    }
    DeferredFree();
    ReleaseStateBlocks(playLeaves);
    ReleaseStateBlocks(pauseLeaves);
    ReleaseStateBlocks(branches);
    ReleaseStateBlocks(blendBranches);
    ReleaseStateBlocks(blendAdditiveBranches);
    ReleaseStateBlocks(fusionBranches);
    ReleaseStateBlocks(bestLeaves);
    ReleaseStateBlocks(tagFilters);
    nodes.Clear();
}

idMD6Node* idMD6BlockAlloc::Alloc(idMD6Node::nodeType_t type) {
    idMD6RecoveredBlockState* state = StateForType(*this, type);
    if (state == nullptr) {
        return nullptr;
    }

    idMD6Node* node = AllocateFromState(*state, type);
    if (node == nullptr) {
        return nullptr;
    }
    if (nodes.Append(node) < 0) {
        DestroyNode(node);
        *reinterpret_cast<void**>(node) = state->free;
        state->free = node;
        --state->active;
        return nullptr;
    }
    return node;
}

void idMD6BlockAlloc::Free(idMD6Node* node) {
    const int index = nodes.FindIndex(node);
    if (index < 0) {
        return;
    }
    if (nodesToDelete.Append(node) < 0) {
        return;
    }
    nodes.RemoveIndexFast(index);
}

void idMD6BlockAlloc::DeferredFree() {
    for (int index = 0; index < nodesToDelete.Num(); ++index) {
        idMD6Node* node = nodesToDelete[index];
        if (node == nullptr) {
            continue;
        }

        idMD6RecoveredBlockState* state = StateForType(*this,
            static_cast<idMD6Node::nodeType_t>(node->type));
        if (state == nullptr) {
            continue;
        }
        DestroyNode(node);
        *reinterpret_cast<void**>(node) = state->free;
        state->free = node;
        if (state->active > 0) {
            --state->active;
        }
    }
    nodesToDelete.Clear();
}

void idMD6BlockAlloc::Condense() {
    nodes.Resize(nodes.Num());
}

unsigned int idMD6BlockAlloc::Size() {
    return 40u * (2u * static_cast<unsigned int>(pauseLeaves.total) +
               static_cast<unsigned int>(branches.total)) +
        172u * static_cast<unsigned int>(fusionBranches.total) +
        156u * static_cast<unsigned int>(blendBranches.total) +
        92u * static_cast<unsigned int>(bestLeaves.total) +
        84u * static_cast<unsigned int>(blendAdditiveBranches.total) +
        16u * static_cast<unsigned int>(tagFilters.total) +
        24u * static_cast<unsigned int>(playLeaves.total) + 436u;
}

int idMD6BlockAlloc::NumNodes() {
    return nodes.Num();
}

idMD6Node* idMD6BlockAlloc::NodeForIndex(int index) {
    return index >= 0 && index < nodes.Num() ? nodes[index] : nullptr;
}

const idMD6Node* idMD6BlockAlloc::NodeForIndex(int index) const {
    return index >= 0 && index < nodes.Num() ? nodes[index] : nullptr;
}
