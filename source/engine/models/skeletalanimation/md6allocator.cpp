#include "models/skeletalanimation/md6allocator.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <malloc.h>

namespace {

unsigned int RecoveredNodeSize(idMD6Node::nodeType_t type) {
    switch (type) {
    case idMD6Node::NODE_BRANCH:
        return 40;
    case idMD6Node::NODE_LEAF_PAUSE:
        return 80;
    case idMD6Node::NODE_LEAF_PLAY:
        return 24;
    case idMD6Node::NODE_BLEND_BRANCH:
        return 156;
    case idMD6Node::NODE_BLENDA_BRANCH:
        return 84;
    case idMD6Node::NODE_FUSION_BRANCH:
        return 172;
    case idMD6Node::NODE_BEST_LEAF:
        return 92;
    case idMD6Node::NODE_TAG_FILTER:
        return 16;
    default:
        return 0;
    }
}

std::size_t AllocationSize(idMD6Node::nodeType_t type) {
    std::size_t size = RecoveredNodeSize(type);
    if (type == idMD6Node::NODE_BRANCH) {
        size = (std::max)(size, sizeof(idMD6Branch));
    } else if (type == idMD6Node::NODE_LEAF_PAUSE) {
        size = (std::max)(size, sizeof(idMD6LeafPause));
    } else if (type == idMD6Node::NODE_LEAF_PLAY) {
        size = (std::max)(size, sizeof(idMD6LeafPlay));
    }
    return size;
}

idMD6Node* AllocateNode(idMD6Node::nodeType_t type) {
    const std::size_t size = AllocationSize(type);
    if (size == 0) {
        return nullptr;
    }

    void* storage = _aligned_malloc(size, 16);
    if (storage == nullptr) {
        return nullptr;
    }
    std::memset(storage, 0, size);

    idMD6Node* node = static_cast<idMD6Node*>(storage);
    node->type = static_cast<std::uint8_t>(type);
    if (type == idMD6Node::NODE_BRANCH) {
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
    }
    return node;
}

} // namespace

idMD6Allocator::~idMD6Allocator() = default;

idMD6Allocator_New::~idMD6Allocator_New() {
    for (int index = 0; index < nodes.Num(); ++index) {
        _aligned_free(nodes[index]);
    }
    nodes.Clear();
}

idMD6Node* idMD6Allocator_New::Alloc(idMD6Node::nodeType_t type) {
    idMD6Node* node = AllocateNode(type);
    if (node == nullptr) {
        return nullptr;
    }
    if (nodes.Append(node) < 0) {
        _aligned_free(node);
        return nullptr;
    }
    return node;
}

void idMD6Allocator_New::Free(idMD6Node* node) {
    const int index = nodes.FindIndex(node);
    if (index < 0) {
        return;
    }
    _aligned_free(nodes[index]);
    nodes.RemoveIndexFast(index);
}

void idMD6Allocator_New::Condense() {
    nodes.Resize(nodes.Num());
}

unsigned int idMD6Allocator_New::Size() {
    unsigned int bytes = 0;
    for (int index = 0; index < nodes.Num(); ++index) {
        if (nodes[index] != nullptr) {
            bytes += RecoveredNodeSize(static_cast<idMD6Node::nodeType_t>(
                nodes[index]->type));
        }
    }
    return bytes;
}

int idMD6Allocator_New::NumNodes() {
    return nodes.Num();
}

idMD6Node* idMD6Allocator_New::NodeForIndex(int index) {
    return index >= 0 && index < nodes.Num() ? nodes[index] : nullptr;
}

const idMD6Node* idMD6Allocator_New::NodeForIndex(int index) const {
    return index >= 0 && index < nodes.Num() ? nodes[index] : nullptr;
}
