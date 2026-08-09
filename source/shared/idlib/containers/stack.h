#pragma once

template<typename type>
class idStackNode {
public:
    type* next;
    idStackNode() : next(nullptr) {}
};

template<typename type, int blockSize>
class idStack {
public:
    type* first;
    type* last;

    idStack() : first(nullptr), last(nullptr) {}
    bool IsEmpty() const { return first == nullptr; }
    type* First() const { return first; }
    void Push(type* node) {
        node->next = first;
        first = node;
        if (last == nullptr) last = node;
    }
    type* Pop() {
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
struct idRecoveredStackNode : idStackNode<idRecoveredStackNode> {};
static_assert(sizeof(idStack<idRecoveredStackNode, 32>) == 8,
    "Recovered idStack ABI changed");
#endif

