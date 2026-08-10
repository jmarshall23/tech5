#pragma once

#include "framework/framework_runtime.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"

class idPlaytestStorage {
public:
    enum playerBreadCrumbState_t : int {
        PLAYERBREADCRUMBSTATE_NONE = 0,
        PLAYERBREADCRUMBSTATE_NORMAL = 1,
        PLAYERBREADCRUMBSTATE_MISC = 2,
        PLAYERBREADCRUMBSTATE_VEHICLE = 3
    };

    struct playerNormalBreadCrumbInfo_t {
        idVec3 loc;
        idVec3 dir;
        float health;
        float healthPercent;
        float speed;
        int mainAmmoCount;
        bool combatHud;
        bool isCrouching;
        bool isZooming;
        bool isCooking;
        int count;
        int timestamp;
        int lastTimeStamp;
    };

    struct playerNormalBreadCrumbList_t {
        bool inInteraction;
        idStr interactionEntity;
        idStr interactionName;
        idList<playerNormalBreadCrumbInfo_t> breadCrumbs;
    };

    struct playerMiscControlBreadCrumbInfo_t {
        idVec3 loc;
        idVec3 dir;
        float speed;
        int count;
        int timestamp;
        int lastTimeStamp;
    };

    struct playerMiscControlBreadCrumbList_t {
        idStr controlName;
        bool isInteraction;
        idList<playerMiscControlBreadCrumbInfo_t> breadCrumbs;
    };

    struct alignas(4) playerVehicleBreadCrumbInfo_t {
        idVec3 loc;
        idVec3 dir;
        float health;
        float healthPercent;
        float speed;
        float boost;
        int ammo;
        int count;
        int timestamp;
        int lastTimeStamp;
        bool combatHud;
    };

    struct playerVehicleBreadCrumbList_t {
        idStr vehicleName;
        bool isRCBomb;
        idList<playerVehicleBreadCrumbInfo_t> breadCrumbs;
    };

    struct playerMainBreadCrumbInfo_t {
        playerBreadCrumbState_t state;
        idList<playerNormalBreadCrumbList_t> normalBreadCrumbs;
        idList<playerMiscControlBreadCrumbList_t> miscBreadCrumbs;
        idList<playerVehicleBreadCrumbList_t> vehicleBreadCrumbs;
    };

    struct playerButtonInfo_t {
        int buttons;
        char forwardmove;
        char rightmove;
        char upmove;
        int timestamp;
        int lastTimestamp;
    };

    struct itemInfo_t {
        idVec3 loc;
        idStr itemName;
        int count;
        idStr materialName;
        int timestamp;
    };

    struct useFocusInfo_t {
        idVec3 loc;
        idVec3 dir;
        idStr focusName;
        int timestamp;
    };

    struct quickItemInfo_t {
        idVec3 loc;
        idStr quickItemName;
        idStr quickItemMaterial;
        int timestamp;
    };

    struct equipItemInfo_t {
        idVec3 loc;
        idStr equipedItemName;
        idStr equipedItemMaterial;
        int timestamp;
    };

    struct deathInfo_t {
        idVec3 loc;
        idVec3 killerLoc;
        int entityNum;
        idStr entityName;
        int killerEntityNum;
        idStr killerName;
        idStr damageName;
        int timestamp;
    };

    struct weaponFireInfo_t {
        idStr weaponName;
        idStr projectileName;
        int attackerNum;
        idStr attackerName;
        int targetNum;
        float spread;
        idVec3 start;
        idVec3 dir;
        int timestamp;
    };

    struct inventoryElement_t {
        idStr itemName;
        idStr materialName;
        int count;
    };

    struct inventoryInfo_t {
        int timestamp;
        idVec3 loc;
        idList<inventoryElement_t> inventoryList;
    };

    struct radiusDamageInfo_t {
        idVec3 loc;
        float radius;
        float minDamage;
        float maxDamage;
        float playerDamageScale;
        idStr inflictorName;
        idStr attackerName;
        idStr damageDefName;
        int timestamp;
    };

    struct ai2FSMStateInfo_t {
        idStr fsmName;
        idStr stateName;
        idStr lastTransition;
    };

    struct ai2StateInfo_t {
        int timestamp;
        int lastTimeStamp;
        int count;
        idList<ai2FSMStateInfo_t> states;
    };

    struct alignas(4) ai2BreadCrumbInfo_t {
        idVec3 loc;
        idVec3 dir;
        float health;
        float healthPercent;
        float speed;
        int count;
        int timestamp;
        int lastTimeStamp;
        bool isHostile;
        bool isTalking;
    };

    struct ai2Info_t {
        int entNum;
        idStr entName;
        int creationTimeStamp;
        bool isDormant;
        idList<ai2StateInfo_t> stateLog;
        idList<idList<ai2BreadCrumbInfo_t>> breadCrumbs;
        idList<int> dormantTimeStamps;
    };

    struct alignas(4) aiVehicleBreadCrumbInfo_t {
        idVec3 loc;
        idVec3 dir;
        float health;
        float healthPercent;
        float speed;
        float boost;
        int ammo;
        int count;
        int timestamp;
        int lastTimeStamp;
        bool hasCar;
        bool isRCBomb;
    };

    struct aiVehicleInfo_t {
        int entNum;
        idStr entName;
        int creationTimeStamp;
        idList<aiVehicleBreadCrumbInfo_t> breadCrumbs;
    };

    struct weaponUsageReport_t {
        idStr weaponName;
        int time;
        float percentage;
        int projectilesSpawned;
    };

    struct quickItemReport_t {
        idStr itemName;
        int count;
    };

    struct killReport_t {
        idStr damageName;
        int count;
    };

    idPlaytestStorage();
    ~idPlaytestStorage();

    void Clear();
    void FullClear();
    void Record(const tech5Framework::playtestEvent_t& event);
    idStr BuildReport() const;
    void WriteTextFile(const idStr& fileName, const idStr& mapName,
        const idList<idStr>& mapLayersSpawned);
    bool ReadBinaryFile(const idStr& fileName);
    static idStr CreateReadableTimeString(int timeMS);
    void GenerateWeaponUseInfo(int playerNum,
        idList<weaponUsageReport_t>& weaponList) const;
    void GenerateKillInfo(int playerNum, idList<killReport_t>& killList) const;
    void GenerateQuickItemInfo(int playerNum,
        idList<quickItemReport_t>& quickItemList) const;

    idList<playerMainBreadCrumbInfo_t> playerBreadCrumbs;
    idList<idList<playerButtonInfo_t>> playerButtonInfo;
    idList<idList<itemInfo_t>> playerItemInfo;
    idList<idList<useFocusInfo_t>> playerUseFocusInfo;
    idList<idList<quickItemInfo_t>> playerUseQuickItemInfo;
    idList<idList<equipItemInfo_t>> playerEquipItemInfo;
    idList<idList<deathInfo_t>> playerDeathInfo;
    idList<idList<weaponFireInfo_t>> playerWeaponFireInfo;
    idList<idList<inventoryInfo_t>> playerInventoryInfo;
    idList<radiusDamageInfo_t> radiusDamageInfo;
    idList<deathInfo_t> otherDeathInfo;
    idList<weaponFireInfo_t> otherWeaponFireInfo;
    idList<ai2Info_t> ai2Info;
    idList<aiVehicleInfo_t> aiVehicleInfo;
    int numPlayers;
    int version;
    idStr buildVersionString;
    int buildNumberMajor;
    int buildNumberMinor;
    idStr machineName;
    idStr fileName;
    idStr playMapName;
    int numActiveLayers;
    idList<idStr> activeLayers;
    int beginTime;
    int lastTime;
    int offsetTime;
};

class idPlaytestMetaStorage {
public:
    idPlaytestMetaStorage();
    idStr BuildReport() const;

    int version;
    int beginTime;
    int lastTime;
    idStr fileName;
    idStr buildVersionString;
    int buildNumberMajor;
    int buildNumberMinor;
    idStr machineName;
    idList<idPlaytestStorage> storageList;
};
