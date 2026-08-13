#include "game/entities/loot.h"

#include <algorithm>

namespace {
idLootServices defaultLootServices;
idLootServices* lootServices = &defaultLootServices;
unsigned int lootRandomSeed = 0x12345678u;
}

idPlayer* idLootServices::CastPlayer(idEntity*) const { return nullptr; }
void idLootServices::ConfigureLootClip(idEntity& entity) {
    entity.contents = 0x200000;
}
void idLootServices::TakeLootBox(idPlayer&, idLootBox&, bool) {}
int idLootServices::GetJobStatus(const idPlayer&, const char*) const {
    return JOBSTATUS_NONE;
}
bool idLootServices::IsUniqueItemRemembered(
        const idPlayer&, const char*) const {
    return false;
}
idPlayer* idLootServices::GetDebugPlayer() const { return nullptr; }
int idLootServices::GetItemCount(
        const idPlayer&, const idDeclInventory*, bool) const {
    return 0;
}
bool idLootServices::GiveItem(idPlayer&, const idDeclInventory*, int) {
    return false;
}
void idLootServices::ModifyItemCaseCrosshair(const idEntity&,
        const idEntity&, const void*, int, idCrosshairInfo&) {}
void idLootServices::PlayPlayerSound(idPlayer&, const idSoundShader*) {}
float idLootServices::RandomFloat() {
    lootRandomSeed = 1664525u * lootRandomSeed + 1013904223u;
    return static_cast<float>((lootRandomSeed >> 10) & 0x7fffu)
        * (1.0f / 32768.0f);
}
int idLootServices::RandomInt(int maximum) {
    if (maximum <= 0) return 0;
    return static_cast<int>(RandomFloat() * static_cast<float>(maximum));
}
float idLootServices::GetHealthRatio(const idEntity&) const { return 1.0f; }
int idLootServices::GetLootTestIterations() const { return 100000000; }
void idLootServices::ReportLootTest(
        const idDeclInventory*, float, float) {}

void idLoot_Blocker::SetServices(idLootServices* services) {
    lootServices = services != nullptr ? services : &defaultLootServices;
}
idLootServices& idLoot_Blocker::LootServices() { return *lootServices; }

// Retail: 0x82C6D0A0
bool idLoot_Blocker::IsEverUsable(const idEntity* activator) const {
    return !flags.hidden && IsCurrentlyUsable(activator);
}

// Retail: 0x82C6D108
int idLoot_Blocker::GetUsableState(
        const idEntity* activator, const void*) const {
    return IsCurrentlyUsable(activator) ? USABLE_LOOT : USABLE_NOT_USABLE;
}

// Retail: 0x82C6D148
bool idLoot_Blocker::Use(idEntity* activator, int) {
    if (!isLootable) return false;
    idPlayer* const player = LootServices().CastPlayer(activator);
    if (player == nullptr) return false;
    isLootable = false;
    LootServices().TakeLootBox(*player, loot, onlyLootOneItem);
    ActivateTargets(activator);
    return true;
}

// Retail: 0x82C6D1D0
void idLoot_Blocker::Spawn() {
    LootServices().ConfigureLootClip(*this);
    if (uniqueInWorld) BecomeActive(1);
    else BecomeInactive(1);
}

// Retail: 0x82C6D260
void idLoot_ItemCase::Spawn() {
    idLoot_Blocker::LootServices().ConfigureLootClip(*this);
}

// Retail: 0x82C6D2C0
const idDeclInventory* idLootBox::GetLootItem(
        int index, int& count, bool ignoreDropPercent) const {
    if (index < 0 || index >= loot.Num()) {
        count = 0;
        return nullptr;
    }
    const RandomLootItem& entry = loot[index];
    if (!ignoreDropPercent
            && idLoot_Blocker::LootServices().RandomFloat()
                > entry.dropPercent * 0.01f) {
        count = 0;
        return nullptr;
    }
    const int countRange = (std::max)(0, entry.maxCount - entry.minCount);
    count = entry.minCount
        + idLoot_Blocker::LootServices().RandomInt(countRange);
    return entry.item;
}

// Retail: 0x82C6D3B8
bool idLoot_Blocker::IsCurrentlyUsable(const idEntity* activator) const {
    if (!isLootable) return false;
    if (requiredJob.IsEmpty()) return true;
    idPlayer* const player = LootServices().CastPlayer(
        const_cast<idEntity*>(activator));
    if (player == nullptr) return false;
    const int status = LootServices().GetJobStatus(
        *player, requiredJob.c_str());
    if (status == JOBSTATUS_NONE) return false;
    if (minStatus != JOBSTATUS_NONE && status < minStatus) return false;
    if (maxStatus != JOBSTATUS_NONE && status > maxStatus) return false;
    return true;
}

// Retail: 0x82C6D490
bool idLoot_Blocker::ModifyCrosshairInfo(const idEntity*, const void*,
        int, void* crosshairInfo) const {
    if (crosshairInfo == nullptr) return false;
    idCrosshairInfo& info = *static_cast<idCrosshairInfo*>(crosshairInfo);
    info.color = idColor::colorGreen;
    info.colorState = CROSSHAIR_COLOR_NORMAL;
    info.textColorState = CROSSHAIR_TEXT_COLOR_NORMAL;
    info.material = CHMATERIAL_LOOT;
    info.text = displayString;
    return true;
}

// Retail: 0x82C6D4E0
void idLoot_Blocker::Think() {
    if (!uniqueInWorld || hasCheckedUniqueInWorld) return;
    idPlayer* const player = LootServices().GetDebugPlayer();
    if (player == nullptr) return;
    if (LootServices().IsUniqueItemRemembered(*player, name.c_str())) {
        Remove();
    } else {
        hasCheckedUniqueInWorld = true;
        BecomeInactive(1);
    }
}

// Retail: 0x82C6D590
bool idLoot_ItemCase::ModifyCrosshairInfo(const idEntity* activator,
        const void* focusTrace, int usableState,
        void* crosshairInfo) const {
    idPlayer* const player = idLoot_Blocker::LootServices().CastPlayer(
        const_cast<idEntity*>(activator));
    if (player == nullptr || crosshairInfo == nullptr) return false;
    if (!ammoCalledOut) {
        idLoot_Blocker::LootServices().PlayPlayerSound(*player, foundSound);
        ammoCalledOut = true;
    }
    idLoot_Blocker::LootServices().ModifyItemCaseCrosshair(
        *this, *activator, focusTrace, usableState,
        *static_cast<idCrosshairInfo*>(crosshairInfo));
    return true;
}

// Retail: 0x82C6D648
bool idLoot_ItemCase::IsCurrentlyUsable(const idEntity* activator) const {
    idPlayer* const player = idLoot_Blocker::LootServices().CastPlayer(
        const_cast<idEntity*>(activator));
    if (player == nullptr) return false;
    for (int index = 0; index < caseContents.Num(); ++index) {
        const caseItem_t& item = caseContents[index];
        if (idLoot_Blocker::LootServices().GetItemCount(
                *player, item.itemDecl, true) < item.count) {
            return true;
        }
    }
    return false;
}

// Retail: 0x82C6D7B8
bool idLoot_ItemCase::Use(idEntity* user, int) {
    idPlayer* const player = idLoot_Blocker::LootServices().CastPlayer(user);
    if (player == nullptr || caseContents.Num() == 0) return false;
    bool gaveItem = false;
    for (int index = 0; index < caseContents.Num(); ++index) {
        const caseItem_t& item = caseContents[index];
        const int currentCount = idLoot_Blocker::LootServices().GetItemCount(
            *player, item.itemDecl, true);
        if (currentCount >= item.count) continue;
        const int amount = item.count - currentCount;
        gaveItem = idLoot_Blocker::LootServices().GiveItem(
            *player, item.itemDecl, amount) || gaveItem;
    }
    if (gaveItem) {
        idLoot_Blocker::LootServices().PlayPlayerSound(*player, useSound);
        if (triggerTargets) ActivateTargets(user);
    }
    return gaveItem;
}

// Retail: 0x82C6DA70
void idRandomLoot::TestFunctionality() {
    if (lootPool == nullptr || lootPool->lootBox.loot.Num() == 0) return;
    idList<int, 5> drops;
    drops.SetNum(lootPool->lootBox.loot.Num());
    for (int index = 0; index < drops.Num(); ++index) drops[index] = 0;
    const int iterations = (std::max)(0,
        idLoot_Blocker::LootServices().GetLootTestIterations());
    for (int iteration = 0; iteration < iterations; ++iteration) {
        for (int index = 0; index < drops.Num(); ++index) {
            int count = 0;
            if (lootPool->lootBox.GetLootItem(index, count, false) != nullptr) {
                ++drops[index];
            }
        }
    }
    for (int index = 0; index < drops.Num(); ++index) {
        int ignoredCount = 0;
        const idDeclInventory* item = lootPool->lootBox.GetLootItem(
            index, ignoredCount, true);
        const float actual = iterations > 0
            ? static_cast<float>(drops[index])
                * 100.0f / static_cast<float>(iterations)
            : 0.0f;
        idLoot_Blocker::LootServices().ReportLootTest(item,
            lootPool->lootBox.loot[index].dropPercent, actual);
    }
}

// Retail: 0x82C6DCD0
idRandomLoot::idRandomLoot() : lootPool(nullptr), lootClass(nullptr) {}

// Retail: 0x82C6DDD8
bool idDisassembleLoot::GetLootBoxForHealthRatio(
        idLootBox& lootBox, float healthRatio) const {
    if (lootBoxes.Num() == 0) {
        lootBox.loot.Clear();
        return false;
    }
    if (lootBoxes.Num() == 1 || healthRatio >= 1.0f) {
        lootBox.loot = lootBoxes[0].loot;
        return true;
    }
    int index;
    if (healthRatio <= 0.0f) index = lootBoxes.Num() - 1;
    else {
        index = static_cast<int>((1.0f - healthRatio)
            * static_cast<float>(lootBoxes.Num() - 2) + 1.0f);
        index = (std::max)(1, (std::min)(lootBoxes.Num() - 1, index));
    }
    lootBox.loot = lootBoxes[index].loot;
    return false;
}

// Retail: 0x82C6DEB8
idLoot_Blocker::idLoot_Blocker()
    : onlyLootOneItem(false), minStatus(JOBSTATUS_NONE),
      maxStatus(JOBSTATUS_NONE), uniqueInWorld(false),
      hasCheckedUniqueInWorld(false), isLootable(true) {
    displayString.index = -1;
}

// Retail: 0x82C6E038
bool idDisassembleLoot::GetLootBox(
        idLootBox& lootBox, const idEntity* entity) {
    const float healthRatio = entity != nullptr
        ? idLoot_Blocker::LootServices().GetHealthRatio(*entity) : 0.0f;
    return GetLootBoxForHealthRatio(lootBox, healthRatio);
}

// Retail header: 0x824FC000
idLoot_ItemCase::idLoot_ItemCase()
    : triggerTargets(false), useSound(nullptr), foundSound(nullptr),
      ammoCalledOut(false) {}

// Retail header: 0x824FC0A0
idLoot_ItemCase::~idLoot_ItemCase() { caseContents.Clear(); }

// Retail header: 0x82E76DD8
void idDisassembleLoot::Looted() { lootBoxes.ClearFree(); }
