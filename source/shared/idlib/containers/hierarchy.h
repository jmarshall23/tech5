#pragma once

template<typename type>
class idHierarchy {
public:
    idHierarchy* parent;
    idHierarchy* sibling;
    idHierarchy* child;
    type* owner;

    explicit idHierarchy(type* ownerObject = nullptr)
        : parent(nullptr), sibling(nullptr), child(nullptr), owner(ownerObject) {}
    ~idHierarchy() { RemoveFromHierarchy(); }

    void SetOwner(type* ownerObject) { owner = ownerObject; }
    type* Owner() const { return owner; }
    idHierarchy* Parent() const { return parent; }
    idHierarchy* Child() const { return child; }
    idHierarchy* Sibling() const { return sibling; }

    idHierarchy* GetPriorSiblingNode() const {
        if (parent == nullptr || parent->child == this) return nullptr;
        idHierarchy* node = parent->child;
        while (node != nullptr && node->sibling != this) node = node->sibling;
        return node;
    }

    void ParentTo(idHierarchy& newParent) {
        RemoveFromHierarchy();
        parent = &newParent;
        sibling = newParent.child;
        newParent.child = this;
    }

    void RemoveFromHierarchy() {
        if (parent != nullptr) {
            if (parent->child == this) parent->child = sibling;
            else {
                idHierarchy* prior = GetPriorSiblingNode();
                if (prior != nullptr) prior->sibling = sibling;
            }
        }
        parent = nullptr;
        sibling = nullptr;
    }
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idHierarchy<int>) == 16, "Recovered idHierarchy ABI changed");
#endif

