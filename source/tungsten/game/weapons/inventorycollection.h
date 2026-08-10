#pragma once

#include "../../../shared/idlib/containers/list.h"

class idDeclInventory;
class idInventoryItem;

class idInventoryCollection {
public:
    struct net_itemTransaction_t {
        const idDeclInventory* itemDecl;
        int count;
        bool setCount;
    };

    idInventoryCollection();

    idInventoryItem* GetInventoryItem(int index) const;
    int GetInventoryItemIndex(const idInventoryItem* item) const;

    idList<idInventoryItem*, 5> inventory;
    bool readingFromFile;
    net_itemTransaction_t net_addedItems[64];
    int net_itemAddIndex;
    int net_lastItemAddIndex;
    bool net_serializeInventoryChanges;
};

// The constructor is inlined at each use in the retail binary. The recovered
// out-of-line destructor records the state to restore when a guarded inventory
// operation leaves its scope, including exceptional exits.
class idInventorySerializeLock {
public:
    ~idInventorySerializeLock();

    idInventoryCollection* inv;
    bool lock;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idInventoryCollection::net_itemTransaction_t) == 12,
    "Recovered inventory transaction ABI changed");
static_assert(sizeof(idInventoryCollection) == 800,
    "Recovered inventory collection ABI changed");
static_assert(sizeof(idInventorySerializeLock) == 8,
    "Recovered inventory serialization lock ABI changed");
#endif
