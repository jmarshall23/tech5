#pragma once

template<typename type>
class idQueueNode {
public:
    type* next;
    idQueueNode() : next(nullptr) {}
};

template<typename type, int blockSize>
class idQueue {
public:
    type* first;
    type* last;

    idQueue() : first(nullptr), last(nullptr) {}
    bool IsEmpty() const { return first == nullptr; }
    type* First() const { return first; }
    void Add(type* node) {
        node->next = nullptr;
        if (last != nullptr) last->next = node;
        else first = node;
        last = node;
    }
    type* RemoveFirst() {
        type* node = first;
        if (node != nullptr) {
            first = node->next;
            node->next = nullptr;
            if (first == nullptr) last = nullptr;
        }
        return node;
    }
    void Clear() { first = nullptr; last = nullptr; }
};

#if defined(_WIN32) && !defined(_WIN64)
struct idRecoveredQueueNode : idQueueNode<idRecoveredQueueNode> {};
static_assert(sizeof(idQueue<idRecoveredQueueNode, 48>) == 8,
    "Recovered idQueue ABI changed");
#endif

