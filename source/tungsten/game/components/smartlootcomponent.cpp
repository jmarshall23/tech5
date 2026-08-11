#include "smartlootcomponent.h"

#include <algorithm>

namespace {

idSmartLootComponentServices defaultSmartLootServices;
idSmartLootComponentServices* smartLootServices = &defaultSmartLootServices;

template<class entry_t>
int WeightedRandom(const entry_t* list, int count) {
    if (list == nullptr || count <= 0) return -1;
    float total = 0.0f;
    for (int index = 0; index < count; ++index) {
        total += std::max(0.0f, list[index].weight);
    }
    if (total <= 0.0f) return -1;
    const float selected = smartLootServices->RandomFloat() * total;
    float cumulative = 0.0f;
    for (int index = 0; index < count; ++index) {
        cumulative += std::max(0.0f, list[index].weight);
        if (selected < cumulative) return index;
    }
    return count - 1;
}

void DestroyOwnedItem(idInventoryItem*& item) {
    if (item != nullptr) smartLootServices->DestroyItem(item);
    item = nullptr;
}

} // namespace

void Tungsten_SetSmartLootComponentServices(
        idSmartLootComponentServices* services) {
    smartLootServices = services != nullptr ? services : &defaultSmartLootServices;
}

// EA 0x82BB6BE8
idSmartLootComponent::idSmartLootComponent()
    : decl(nullptr), weaponDecl(nullptr), customItem(nullptr),
      weaponItem(nullptr), ammoItem(nullptr), randomItem(nullptr) {}

// EA 0x82BB6C18
idSmartLootComponent::~idSmartLootComponent() {
    DestroyOwnedItem(customItem);
    DestroyOwnedItem(weaponItem);
    DestroyOwnedItem(ammoItem);
    DestroyOwnedItem(randomItem);
}

// EA 0x82BB6D48
void idSmartLootComponent::Activate(idEntity* owner) {
    const std::vector<idInventoryItem*> inventory =
        smartLootServices->GetOwnerInventory(owner);
    for (idInventoryItem* item : inventory) {
        const idDeclWeapon* foundWeapon =
            smartLootServices->GetWeaponDeclaration(item);
        if (foundWeapon != nullptr) {
            weaponDecl = smartLootServices->ResolveLootWeaponDeclaration(
                foundWeapon);
        } else if (item != nullptr && customItem == nullptr) {
            customItem = smartLootServices->CreateItem(
                smartLootServices->GetItemDeclaration(item), 1, true);
            if (customItem != nullptr) {
                smartLootServices->RemoveOwnerItem(owner, item);
            }
        }
    }
}

// EA 0x82BB6EE0
bool IsCompatibleAmmo(const idDeclInventory* ammo,
        const idDeclWeapon* weapon) {
    return ammo != nullptr && weapon != nullptr
        && smartLootServices->IsCompatibleAmmo(ammo, weapon);
}

// EA 0x82BB6F58
int GetTotalAmmoInInventory(const idInventoryCollection* inventory,
        const idDeclInventory* ammo) {
    return inventory != nullptr && ammo != nullptr
        ? smartLootServices->GetTotalAmmo(inventory, ammo) : 0;
}

// EA 0x82BB7068
int GetWeightedRandom(const tempItemGroup_t* list, int count) {
    return WeightedRandom(list, count);
}

// EA 0x82BB7168
int GetWeightedRandom(const tempItem_t* list, int count) {
    return WeightedRandom(list, count);
}

// EA 0x82BB7368
bool idSmartLootComponent::PeekLootItems(
        std::vector<idInventoryItem*>& output, bool weaponStuffOnly) const {
    output.clear();
    if (!weaponStuffOnly) {
        idInventoryItem* general = customItem != nullptr
            ? customItem : randomItem;
        if (general != nullptr) output.push_back(general);
    }
    idInventoryItem* weaponLoot = weaponItem != nullptr
        ? weaponItem : ammoItem;
    if (weaponLoot != nullptr) output.push_back(weaponLoot);
    return !output.empty();
}

// EA 0x82BB7400
bool idSmartLootComponent::GetLootItems(std::vector<idInventoryItem*>& output,
        bool weaponStuffOnly) {
    const bool result = PeekLootItems(output, weaponStuffOnly);
    weaponDecl = nullptr;
    weaponItem = nullptr;
    ammoItem = nullptr;
    if (!weaponStuffOnly) {
        customItem = nullptr;
        randomItem = nullptr;
        decl = nullptr;
    }
    return result;
}

// EA 0x82BB7468
idInventoryItem* CreateRandomItem(tempItemGroup_t* groups, int groupCount) {
    if (groups == nullptr || groupCount <= 0) return nullptr;
    for (int index = 0; index < groupCount; ++index) {
        tempItemGroup_t& candidate = groups[index];
        if (candidate.disabled || candidate.group == nullptr) {
            candidate.weight = 0.0f;
        } else {
            candidate.weight = candidate.group->weight;
            if (candidate.group->scaleWeightByNeed) {
                candidate.weight *= std::max(0.0f, candidate.need);
            }
        }
    }
    const int groupIndex = GetWeightedRandom(groups, groupCount);
    if (groupIndex < 0) return nullptr;
    tempItemGroup_t& selectedGroup = groups[groupIndex];
    std::vector<tempItem_t> candidates = selectedGroup.group->items;
    if (candidates.empty()) return nullptr;
    if (selectedGroup.need != 0.0f && candidates.size() > 1) {
        const float denominator = static_cast<float>(candidates.size() - 1);
        for (std::size_t index = 0; index < candidates.size(); ++index) {
            const float rank = static_cast<float>(index) / denominator;
            candidates[index].weight *= std::max(0.0f,
                1.0f + (rank - 1.0f) * selectedGroup.need);
        }
    }
    const int itemIndex = GetWeightedRandom(candidates.data(),
        static_cast<int>(candidates.size()));
    if (itemIndex < 0) return nullptr;
    const tempItem_t& selected = candidates[itemIndex];
    return smartLootServices->CreateItem(selected.declaration,
        selected.count, true);
}

// EA 0x82BB7C70
bool idSmartLootComponent::CreateRandomItem(const idPlayer* player) {
    std::vector<tempItemGroup_t> groups;
    smartLootServices->BuildRandomItemGroups(decl, player, groups);
    idInventoryItem* created = groups.empty() ? nullptr
        : ::CreateRandomItem(groups.data(), static_cast<int>(groups.size()));
    if (created == nullptr) return false;
    DestroyOwnedItem(randomItem);
    randomItem = created;
    return true;
}

// EA 0x82BB7D60
bool idSmartLootComponent::CreateRandomAmmo(const idPlayer* player) {
    std::vector<tempItemGroup_t> groups;
    smartLootServices->BuildRandomAmmoGroups(decl, player, weaponDecl,
        groups);
    idInventoryItem* created = groups.empty() ? nullptr
        : ::CreateRandomItem(groups.data(), static_cast<int>(groups.size()));
    if (created == nullptr) return false;
    DestroyOwnedItem(ammoItem);
    ammoItem = created;
    return true;
}

// EA 0x82BB7EB8
void idSmartLootComponentActor::Update(const idEntity* owner,
        const idPlayer* player) {
    if (weaponDecl != nullptr) {
        const bool dropped = smartLootServices->ActorHasDroppedWeapon(owner);
        if (dropped && smartLootServices->PlayerHasWeapon(player, weaponDecl)) {
            if (ammoItem == nullptr) CreateRandomAmmo(player);
            if (ammoItem != nullptr) {
                smartLootServices->ApplyAmmoToDroppedWeapon(
                    const_cast<idEntity*>(owner), ammoItem);
            }
        } else if (dropped) {
            if (weaponItem == nullptr) {
                weaponItem = smartLootServices->CreateItem(
                    reinterpret_cast<const idDeclInventory*>(weaponDecl),
                    1, true);
            }
        } else {
            DestroyOwnedItem(weaponItem);
            DestroyOwnedItem(ammoItem);
        }
    }
    if (customItem == nullptr && randomItem == nullptr && decl != nullptr
            && !CreateRandomItem(player)) decl = nullptr;
}

// EA 0x82BB81A8
void idSmartLootComponent::Update(const idEntity*, const idPlayer* player) {
    if (weaponDecl != nullptr) {
        if (smartLootServices->PlayerHasWeapon(player, weaponDecl)) {
            if (ammoItem == nullptr) CreateRandomAmmo(player);
        } else if (weaponItem == nullptr) {
            weaponItem = smartLootServices->CreateItem(
                reinterpret_cast<const idDeclInventory*>(weaponDecl), 1,
                true);
        }
    }
    if (customItem == nullptr && randomItem == nullptr && decl != nullptr
            && !CreateRandomItem(player)) decl = nullptr;
}

// EA 0x82BB8348
void idSmartLootComponent::GetPickupHudInfo(const idEntity* user,
        idPickupHudInfo* info, bool weaponStuffOnly) const {
    std::vector<idInventoryItem*> items;
    if (!PeekLootItems(items, weaponStuffOnly)) return;
    for (idInventoryItem* item : items) {
        smartLootServices->GetPickupHudInfo(item, user, info);
    }
}
