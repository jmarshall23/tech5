#pragma once

#include <vector>

class idDeclInventory;
class idDeclWeapon;
class idEntity;
class idInventoryCollection;
class idInventoryItem;
class idPickupHudInfo;
class idPlayer;
class mgDeclSmartLoot;

struct tempItem_t {
    const idDeclInventory* declaration{nullptr};
    int count{1};
    float weight{0.0f};
};

struct smartLootItemGroupDef_t {
    std::vector<tempItem_t> items;
    float weight{0.0f};
    bool scaleWeightByNeed{false};
};

struct tempItemGroup_t {
    const smartLootItemGroupDef_t* group{nullptr};
    float val{0.0f};
    float need{0.0f};
    float weight{0.0f};
    bool disabled{false};
};

class idSmartLootComponent;

class idSmartLootComponentServices {
public:
    virtual ~idSmartLootComponentServices() = default;
    virtual void DestroyItem(idInventoryItem*) {}
    virtual std::vector<idInventoryItem*> GetOwnerInventory(idEntity*) const {
        return {};
    }
    virtual const idDeclWeapon* GetWeaponDeclaration(idInventoryItem*) const {
        return nullptr;
    }
    virtual const idDeclInventory* GetItemDeclaration(idInventoryItem*) const {
        return nullptr;
    }
    virtual const idDeclWeapon* ResolveLootWeaponDeclaration(
        const idDeclWeapon* declaration) const { return declaration; }
    virtual idInventoryItem* CreateItem(const idDeclInventory*, int,
        bool) { return nullptr; }
    virtual void RemoveOwnerItem(idEntity*, idInventoryItem*) {}
    virtual bool IsCompatibleAmmo(const idDeclInventory*,
        const idDeclWeapon*) const { return false; }
    virtual int GetTotalAmmo(const idInventoryCollection*,
        const idDeclInventory*) const { return 0; }
    virtual float RandomFloat() { return 0.0f; }
    virtual void BuildRandomItemGroups(const mgDeclSmartLoot*,
        const idPlayer*, std::vector<tempItemGroup_t>&) const {}
    virtual void BuildRandomAmmoGroups(const mgDeclSmartLoot*,
        const idPlayer*, const idDeclWeapon*,
        std::vector<tempItemGroup_t>&) const {}
    virtual bool PlayerHasWeapon(const idPlayer*,
        const idDeclWeapon*) const { return false; }
    virtual bool ActorHasDroppedWeapon(const idEntity*) const { return false; }
    virtual void ApplyAmmoToDroppedWeapon(idEntity*, idInventoryItem*) {}
    virtual void GetPickupHudInfo(idInventoryItem*, const idEntity*,
        idPickupHudInfo*) const {}
};

void Tungsten_SetSmartLootComponentServices(
    idSmartLootComponentServices* services);

bool IsCompatibleAmmo(const idDeclInventory* ammo,
    const idDeclWeapon* weapon);
int GetTotalAmmoInInventory(const idInventoryCollection* inventory,
    const idDeclInventory* ammo);
int GetWeightedRandom(const tempItemGroup_t* list, int count);
int GetWeightedRandom(const tempItem_t* list, int count);
idInventoryItem* CreateRandomItem(tempItemGroup_t* groups, int groupCount);

class idSmartLootComponent {
public:
    idSmartLootComponent();
    virtual ~idSmartLootComponent();
    virtual void Update(const idEntity* owner, const idPlayer* player);

    void Activate(idEntity* owner);
    bool PeekLootItems(std::vector<idInventoryItem*>& output,
        bool weaponStuffOnly) const;
    bool GetLootItems(std::vector<idInventoryItem*>& output,
        bool weaponStuffOnly);
    bool CreateRandomItem(const idPlayer* player);
    bool CreateRandomAmmo(const idPlayer* player);
    void GetPickupHudInfo(const idEntity* user, idPickupHudInfo* info,
        bool weaponStuffOnly) const;

    const mgDeclSmartLoot* decl;
    const idDeclWeapon* weaponDecl;
    idInventoryItem* customItem;
    idInventoryItem* weaponItem;
    idInventoryItem* ammoItem;
    idInventoryItem* randomItem;
};

class idSmartLootComponentActor : public idSmartLootComponent {
public:
    void Update(const idEntity* owner, const idPlayer* player) override;
};
