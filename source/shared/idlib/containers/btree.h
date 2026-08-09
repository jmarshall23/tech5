#pragma once

#include "../blockalloc_base.h"

// Header-only B-tree reconstructed from the recovered idBTree specializations
// and the Add/SplitNode/MergeNodes/Remove/FindSmallestLargerEqual bodies.
template<class Object, class Key>
class idBTreeNode {
public:
    Key key;
    Object* object;
    idBTreeNode* parent;
    idBTreeNode* next;
    idBTreeNode* prev;
    int numChildren;
    idBTreeNode* firstChild;
    idBTreeNode* lastChild;
};

template<class Object, class Key, int maxChildren>
class idBTree {
public:
    using node_t = idBTreeNode<Object, Key>;

    node_t* root;
    idBlockAlloc<node_t, 128, 44> nodeAllocator;

    idBTree() : root(nullptr), nodeAllocator(false) {
        static_assert(maxChildren >= 4, "idBTree requires at least four children");
    }

    ~idBTree() {
        Shutdown();
    }

    idBTree(const idBTree&) = delete;
    idBTree& operator=(const idBTree&) = delete;

    void Init() {
        Shutdown();
        root = AllocNode();
    }

    void Shutdown() {
        nodeAllocator.Shutdown();
        root = nullptr;
    }

    node_t* Add(Object* object, const Key key) {
        if (root == nullptr) root = AllocNode();
        if (root == nullptr) return nullptr;

        if (root->numChildren >= maxChildren) {
            node_t* const newRoot = AllocNode();
            if (newRoot == nullptr) return nullptr;
            newRoot->key = root->key;
            newRoot->firstChild = root;
            newRoot->lastChild = root;
            newRoot->numChildren = 1;
            root->parent = newRoot;
            SplitNode(root);
            root = newRoot;
        }

        node_t* const inserted = AllocNode();
        if (inserted == nullptr) return nullptr;
        inserted->key = key;
        inserted->object = object;

        node_t* branch = root;
        while (branch->firstChild != nullptr) {
            if (key > branch->key) branch->key = key;
            node_t* child = branch->firstChild;
            while (child->next != nullptr && key > child->key) child = child->next;
            if (child->object != nullptr) {
                InsertLeaf(branch, child, inserted);
                return inserted;
            }
            if (child->numChildren >= maxChildren) {
                SplitNode(child);
                if (key <= child->prev->key) child = child->prev;
            }
            branch = child;
        }

        inserted->parent = root;
        root->key = key;
        root->firstChild = inserted;
        root->lastChild = inserted;
        ++root->numChildren;
        return inserted;
    }

    void Remove(node_t* node) {
        if (node == nullptr || node->parent == nullptr) return;
        node_t* branch = node->parent;
        if (node->prev != nullptr) node->prev->next = node->next;
        else branch->firstChild = node->next;
        if (node->next != nullptr) node->next->prev = node->prev;
        else branch->lastChild = node->prev;
        --branch->numChildren;

        for (; branch != root; branch = branch->parent) {
            if (branch->numChildren > 1) break;
            node_t* left = nullptr;
            node_t* right = nullptr;
            if (branch->next != nullptr) {
                left = branch;
                right = branch->next;
            } else if (branch->prev != nullptr) {
                left = branch->prev;
                right = branch;
            } else {
                continue;
            }
            branch = MergeNodes(left, right);
            if (branch->lastChild != nullptr && branch->key > branch->lastChild->key) {
                branch->key = branch->lastChild->key;
            }
            if (branch->numChildren > maxChildren) {
                SplitNode(branch);
                break;
            }
        }

        for (node_t* current = branch; current != nullptr; current = current->parent) {
            if (current->lastChild == nullptr) break;
            if (current->key > current->lastChild->key) {
                current->key = current->lastChild->key;
            }
        }
        nodeAllocator.Free(node);

        if (root != nullptr && root->numChildren == 1
                && root->firstChild != nullptr && root->firstChild->object == nullptr) {
            node_t* const oldRoot = root;
            root = oldRoot->firstChild;
            root->parent = nullptr;
            nodeAllocator.Free(oldRoot);
        }
    }

    node_t* NodeFind(const Key key) const {
        node_t* const node = NodeFindSmallestLargerEqual(key);
        return node != nullptr && node->key == key ? node : nullptr;
    }

    node_t* NodeFindSmallestLargerEqual(const Key key) const {
        if (root == nullptr || root->firstChild == nullptr) return nullptr;
        node_t* child = root->firstChild;
        for (;;) {
            while (child->next != nullptr && child->key < key) child = child->next;
            if (child->object != nullptr) return child->key >= key ? child : nullptr;
            child = child->firstChild;
            if (child == nullptr) return nullptr;
        }
    }

    node_t* NodeFindLargestSmallerEqual(const Key key) const {
        node_t* candidate = nullptr;
        for (node_t* leaf = FirstLeaf(); leaf != nullptr; leaf = GetNextLeaf(leaf)) {
            if (leaf->key > key) break;
            candidate = leaf;
        }
        return candidate;
    }

    Object* Find(const Key key) const {
        node_t* const node = NodeFind(key);
        return node != nullptr ? node->object : nullptr;
    }

    Object* FindSmallestLargerEqual(const Key key) const {
        node_t* const node = NodeFindSmallestLargerEqual(key);
        return node != nullptr ? node->object : nullptr;
    }

    Object* FindLargestSmallerEqual(const Key key) const {
        node_t* const node = NodeFindLargestSmallerEqual(key);
        return node != nullptr ? node->object : nullptr;
    }

    node_t* GetRoot() const { return root; }
    int GetNodeCount() const { return nodeAllocator.GetAllocCount(); }

    node_t* GetNext(node_t* node) const {
        if (node == nullptr) return root;
        if (node->firstChild != nullptr) return node->firstChild;
        while (node != nullptr && node->next == nullptr) node = node->parent;
        return node != nullptr ? node->next : nullptr;
    }

    node_t* GetNextLeaf(node_t* node) const {
        if (node == nullptr) return FirstLeaf();
        while (node != nullptr && node->next == nullptr) node = node->parent;
        if (node == nullptr) return nullptr;
        node = node->next;
        while (node->firstChild != nullptr) node = node->firstChild;
        return node;
    }

private:
    node_t* AllocNode() {
        node_t* const node = nodeAllocator.Alloc();
        if (node == nullptr) return nullptr;
        node->key = Key();
        node->object = nullptr;
        node->parent = nullptr;
        node->next = nullptr;
        node->prev = nullptr;
        node->numChildren = 0;
        node->firstChild = nullptr;
        node->lastChild = nullptr;
        return node;
    }

    node_t* FirstLeaf() const {
        node_t* node = root;
        if (node == nullptr || node->firstChild == nullptr) return nullptr;
        node = node->firstChild;
        while (node->firstChild != nullptr) node = node->firstChild;
        return node;
    }

    static void InsertLeaf(node_t* parent, node_t* position, node_t* inserted) {
        if (inserted->key > position->key) {
            inserted->prev = position;
            inserted->next = position->next;
            position->next = inserted;
            if (inserted->next != nullptr) inserted->next->prev = inserted;
            else parent->lastChild = inserted;
        } else {
            inserted->prev = position->prev;
            inserted->next = position;
            position->prev = inserted;
            if (inserted->prev != nullptr) inserted->prev->next = inserted;
            else parent->firstChild = inserted;
        }
        inserted->parent = parent;
        ++parent->numChildren;
    }

    void SplitNode(node_t* node) {
        node_t* const split = AllocNode();
        if (split == nullptr) return;
        split->parent = node->parent;
        const int movedCount = node->numChildren / 2;
        node_t* splitLast = node->firstChild;
        for (int index = 1; index < movedCount; ++index) splitLast = splitLast->next;
        for (node_t* child = node->firstChild;; child = child->next) {
            child->parent = split;
            if (child == splitLast) break;
        }
        split->key = splitLast->key;
        split->numChildren = movedCount;
        split->firstChild = node->firstChild;
        split->lastChild = splitLast;
        node->numChildren -= movedCount;
        node->firstChild = splitLast->next;
        node->firstChild->prev = nullptr;
        splitLast->next = nullptr;
        split->prev = node->prev;
        split->next = node;
        if (node->prev != nullptr) node->prev->next = split;
        else node->parent->firstChild = split;
        node->prev = split;
        ++node->parent->numChildren;
    }

    node_t* MergeNodes(node_t* left, node_t* right) {
        for (node_t* child = left->firstChild; child != nullptr; child = child->next) {
            child->parent = right;
        }
        left->lastChild->next = right->firstChild;
        right->firstChild->prev = left->lastChild;
        right->firstChild = left->firstChild;
        right->numChildren += left->numChildren;
        if (left->prev != nullptr) left->prev->next = right;
        else left->parent->firstChild = right;
        right->prev = left->prev;
        --right->parent->numChildren;
        nodeAllocator.Free(left);
        return right;
    }
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idBTreeNode<int, int>) == 32,
    "Recovered idBTreeNode ABI changed");
static_assert(sizeof(idBTree<int, int, 4>) == 24,
    "Recovered idBTree ABI changed");
#endif
