#pragma once

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstring>

template<typename nodeType, typename priorityType, priorityType LOWEST_VALUE>
class idBinaryHeap {
public:
    struct idHeapNode {
        nodeType node;
        priorityType priority;
    };

    explicit idBinaryHeap(const int initialSize_ = 16)
        : nodes(nullptr), curSize(0), initialSize(std::max(1, initialSize_)),
          numNodes(0), ordered(true), externalBuffer(false) {
        Allocate(initialSize);
    }

    idBinaryHeap(idHeapNode* const buffer, const int bufferSize)
        : nodes(buffer), curSize(std::max(0, bufferSize - 1)),
          initialSize(std::max(0, bufferSize - 1)), numNodes(0),
          ordered(true), externalBuffer(true) {
        if (nodes != nullptr && bufferSize > 0) {
            nodes[0].priority = LOWEST_VALUE;
        }
    }

    ~idBinaryHeap() {
        if (!externalBuffer) {
            std::free(nodes);
        }
    }

    idBinaryHeap(const idBinaryHeap&) = delete;
    idBinaryHeap& operator=(const idBinaryHeap&) = delete;

    bool Insert(const nodeType& node, const priorityType& priority) {
        if (!ordered) {
            return InsertUnsorted(node, priority);
        }
        if (!EnsureCapacity()) {
            return false;
        }
        int hole = ++numNodes;
        while (hole > 1 && priority < nodes[hole / 2].priority) {
            nodes[hole] = nodes[hole / 2];
            hole /= 2;
        }
        nodes[hole].node = node;
        nodes[hole].priority = priority;
        return true;
    }

    bool InsertUnsorted(const nodeType& node, const priorityType& priority) {
        if (!EnsureCapacity()) {
            return false;
        }
        ++numNodes;
        nodes[numNodes].node = node;
        nodes[numNodes].priority = priority;
        if (numNodes > 1 && priority < nodes[numNodes / 2].priority) {
            ordered = false;
        }
        return true;
    }

    nodeType GetMin() {
        SortHeap();
        return numNodes == 0 ? nodeType() : nodes[1].node;
    }

    priorityType GetMinPriority() {
        SortHeap();
        return numNodes == 0 ? LOWEST_VALUE : nodes[1].priority;
    }

    nodeType RemoveMin() {
        SortHeap();
        if (numNodes == 0) {
            return nodeType();
        }
        const nodeType result = nodes[1].node;
        nodes[1] = nodes[numNodes--];
        if (numNodes > 0) {
            PercolateDown(1);
        }
        return result;
    }

    void SortHeap() {
        if (ordered || numNodes < 2) {
            ordered = true;
            return;
        }
        for (int index = numNodes / 2; index > 0; --index) {
            PercolateDown(index);
        }
        ordered = true;
    }

    void MakeEmpty() {
        if (!externalBuffer && curSize != initialSize) {
            std::free(nodes);
            nodes = nullptr;
            curSize = 0;
            Allocate(initialSize);
        }
        numNodes = 0;
        ordered = true;
        if (nodes != nullptr) {
            nodes[0].priority = LOWEST_VALUE;
        }
    }

    int Num() const { return numNodes; }
    bool IsEmpty() const { return numNodes == 0; }

private:
    idHeapNode* nodes;
    int curSize;
    int initialSize;
    int numNodes;
    bool ordered;
    bool externalBuffer;

    bool Allocate(const int size) {
        idHeapNode* const storage = static_cast<idHeapNode*>(
            std::malloc(sizeof(idHeapNode) * static_cast<std::size_t>(size + 1))
        );
        if (storage == nullptr) {
            return false;
        }
        nodes = storage;
        curSize = size;
        nodes[0].priority = LOWEST_VALUE;
        return true;
    }

    bool Resize(const int newSize) {
        if (externalBuffer || newSize <= curSize) {
            return false;
        }
        idHeapNode* const replacement = static_cast<idHeapNode*>(
            std::malloc(sizeof(idHeapNode) * static_cast<std::size_t>(newSize + 1))
        );
        if (replacement == nullptr) {
            return false;
        }
        std::memcpy(replacement, nodes,
            sizeof(idHeapNode) * static_cast<std::size_t>(numNodes + 1));
        std::free(nodes);
        nodes = replacement;
        curSize = newSize;
        return true;
    }

    bool EnsureCapacity() {
        if (numNodes < curSize) {
            return true;
        }
        return Resize(std::max(1, curSize * 2));
    }

    void PercolateDown(int hole) {
        const idHeapNode value = nodes[hole];
        while (hole * 2 <= numNodes) {
            int child = hole * 2;
            if (child != numNodes
                && nodes[child + 1].priority < nodes[child].priority) {
                ++child;
            }
            if (!(nodes[child].priority < value.priority)) {
                break;
            }
            nodes[hole] = nodes[child];
            hole = child;
        }
        nodes[hole] = value;
    }
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idBinaryHeap<int, int, (-2147483647 - 1)>) == 20,
    "Recovered idBinaryHeap ABI changed");
#endif
