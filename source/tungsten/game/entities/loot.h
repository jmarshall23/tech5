#pragma once

#include "game/decls/declinventory.h"
#include "game/entities/entity.h"
#include "game/player/crosshairinfo.h"

class idDeclParticle;
class idPlayer;

enum missionStatus_t : int {
    JOBSTATUS_NONE = 0,
    JOBSTATUS_FAILED = 1,
    JOBSTATUS_ACCEPTED = 2,
    JOBSTATUS_READYTOTURNIN = 3,
    JOBSTATUS_READYTOTURNIN_UNKNOWN = 4,
    JOBSTATUS_COMPLETED = 5
};

class idLootBox {
public:
    struct RandomLootItem {
        const idDeclInventory* item = nullptr;
        float dropPercent = 100.0f;
        int minCount = 1;
        int maxCount = 1;
    };

    const idDeclInventory* GetLootItem(int index, int& count,
        bool ignoreDropPercent) const;
    idList<RandomLootItem, 5> loot;
};

class idDeclLootPool {
public:
    idLootBox lootBox;
};

class idDisassembleLoot {
public:
    bool GetLootBoxForHealthRatio(idLootBox& lootBox,
        float healthRatio) const;
    bool GetLootBox(idLootBox& lootBox, const idEntity* entity);
    void Looted();

    idList<idLootBox, 5> lootBoxes{0};
    const idDeclParticle* disassembleParticle = nullptr;
    const idSoundShader* soundShader = nullptr;
};

class idLootServices {
public:
    virtual ~idLootServices() = default;
    virtual idPlayer* CastPlayer(idEntity* entity) const;
    virtual void ConfigureLootClip(idEntity& entity);
    virtual void TakeLootBox(idPlayer& player, idLootBox& loot,
        bool onlyOneItem);
    virtual int GetJobStatus(const idPlayer& player,
        const char* jobName) const;
    virtual bool IsUniqueItemRemembered(const idPlayer& player,
        const char* entityName) const;
    virtual idPlayer* GetDebugPlayer() const;
    virtual int GetItemCount(const idPlayer& player,
        const idDeclInventory* item, bool includeWeaponClip) const;
    virtual bool GiveItem(idPlayer& player,
        const idDeclInventory* item, int count);
    virtual void ModifyItemCaseCrosshair(const idEntity& itemCase,
        const idEntity& player, const void* focusTrace, int usableState,
        idCrosshairInfo& info);
    virtual void PlayPlayerSound(idPlayer& player,
        const idSoundShader* sound);
    virtual float RandomFloat();
    virtual int RandomInt(int maximum);
    virtual float GetHealthRatio(const idEntity& entity) const;
    virtual int GetLootTestIterations() const;
    virtual void ReportLootTest(const idDeclInventory* item,
        float expectedPercent, float actualPercent);
};

class idLoot_Blocker : public idEntity {
public:
    idLoot_Blocker();
    static void SetServices(idLootServices* services);
    static idLootServices& LootServices();

    bool IsEverUsable(const idEntity* activator) const override;
    int GetUsableState(const idEntity* activator,
        const void* focusTrace) const override;
    bool Use(idEntity* activator, int usableState) override;
    void Spawn() override;
    bool IsCurrentlyUsable(const idEntity* activator) const override;
    bool ModifyCrosshairInfo(const idEntity* activator,
        const void* focusTrace, int usableState,
        void* crosshairInfo) const override;
    void Think() override;

    idLootBox loot;
    bool onlyLootOneItem;
    idStrId displayString;
    idStr requiredJob;
    missionStatus_t minStatus;
    missionStatus_t maxStatus;
    bool uniqueInWorld;
    bool hasCheckedUniqueInWorld;
    bool isLootable;
};

class idLoot_ItemCase : public idEntity {
public:
    struct caseItem_t {
        const idDeclInventory* itemDecl = nullptr;
        int count = 0;
    };

    idLoot_ItemCase();
    ~idLoot_ItemCase() override;
    void Spawn() override;
    bool ModifyCrosshairInfo(const idEntity* activator,
        const void* focusTrace, int usableState,
        void* crosshairInfo) const override;
    bool IsCurrentlyUsable(const idEntity* activator) const override;
    bool Use(idEntity* user, int usableState) override;

    bool triggerTargets;
    const idSoundShader* useSound;
    idList<caseItem_t, 5> caseContents;
    const idSoundShader* foundSound;
    mutable bool ammoCalledOut;
};

class idRandomLoot : public idEntity {
public:
    idRandomLoot();
    void TestFunctionality();

    idLootBox emptyLootBox;
    const idDeclLootPool* lootPool;
    const void* lootClass;
};
