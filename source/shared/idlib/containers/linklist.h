#pragma once

template<typename type>
class idLinkList {
public:
    idLinkList* head;
    idLinkList* next;
    idLinkList* prev;
    type* owner;

    explicit idLinkList(type* ownerObject = nullptr)
        : head(this), next(this), prev(this), owner(ownerObject) {}
    ~idLinkList() { Remove(); }

    void SetOwner(type* ownerObject) { owner = ownerObject; }
    type* Owner() const { return owner; }
    bool InList() const { return head != this; }
    bool IsListEmpty() const { return head->next == head; }

    void AddToFront(idLinkList& node) {
        node.Remove();
        node.head = head;
        node.next = head->next;
        node.prev = head;
        head->next->prev = &node;
        head->next = &node;
    }

    void AddToEnd(idLinkList& node) {
        node.Remove();
        node.head = head;
        node.next = head;
        node.prev = head->prev;
        head->prev->next = &node;
        head->prev = &node;
    }

    void Remove() {
        if (head != this) {
            prev->next = next;
            next->prev = prev;
        }
        head = this;
        next = this;
        prev = this;
    }

    void Clear() {
        while (next != this) next->Remove();
    }

    type* Next() const { return next == head ? nullptr : next->owner; }
    type* Prev() const { return prev == head ? nullptr : prev->owner; }
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idLinkList<int>) == 16, "Recovered idLinkList ABI changed");
#endif

