#pragma once

#include "decls/declfxtypes.h"
#include "decls/decltypeinfo.h"
#include "game/navpower/navpowermover.h"
#include "idlib/color.h"
#include "idlib/langdict.h"
#include "idlib/math/vector.h"

class idDeclAiEvent;
class idDeclDamage;
class idDeclEntityDef;
class idDeclFX;
class idDeclMD6;
class idDeclParticle;
class idDeclProjectile;
class idDeclRecipe;
class idDeclRibbon;
class idDeclThrowable;
class idInGameVideoFile;
class idMaterial;
class idSoundShader;
class idStaticModel;
enum rageStat_t : int;

#ifndef TUNGSTEN_EQUIP_SLOT_T_DEFINED
#define TUNGSTEN_EQUIP_SLOT_T_DEFINED
enum equipSlot_t : int {
    EQUIP_NONE = 0,
    EQUIP_LEFT_HAND = 1,
    EQUIP_RIGHT_HAND = 2,
    EQUIP_HEAD = 3,
    EQUIP_TORSO = 4,
    EQUIP_HOLSTER_HIP_LEFT = 5,
    EQUIP_HOLSTER_HIP_RIGHT = 6,
    EQUIP_HOLSTER_BACK = 7,
    EQUIP_HOLSTER_SHOULDER = 8,
    EQUIP_HOLSTER_BELT_LEFT = 9,
    EQUIP_HOLSTER_BELT_RIGHT = 10,
    EQUIP_HOLSTER_BELT_BACK = 11,
    EQUIP_HOLSTER_BELT_FRONT = 12,
    EQUIP_VEHICLE = 13,
    EQUIP_VEHICLE_RAM = 14,
    EQUIP_MAX = 15
};
#endif

enum quickSlotGroup_t : int {
    QUICKSLOTGROUP_NONE = 0,
    QUICKSLOTGROUP_WEAPON = 1,
    QUICKSLOTGROUP_ITEM = 2,
    QUICKSLOTGROUP_VEHICLE = 3
};

enum removeCond_t : int {
    REMOVE_CONDITION_NONE = 0,
    REMOVE_CONDITION_DORMANT = 1,
    REMOVE_CONDITION_TIMEOUT = 2,
    REMOVE_CONDITION_MAX = 3
};

enum burstMode_t : int {
    BURSTMODE_DEFAULT = 0,
    BURSTMODE_SINGLE = 0,
    BURSTMODE_BURST = 1,
    BURSTMODE_FULLAUTO = 2,
    BURSTMODE_MAX = 3
};

enum weaponAnimSet_t : int {
    WEAPONANIM_FISTS = 0,
    WEAPONANIM_MELEE = 1,
    WEAPONANIM_PISTOL = 2,
    WEAPONANIM_RIFLE = 3,
    WEAPONANIM_MAX = 4
};

enum upgradeType_t : int {
    UPGRADE_TIRES = 0,
    UPGRADE_SUPERCHARGER = 1,
    UPGRADE_SUSPENSION = 2,
    UPGRADE_BOOSTER = 3,
    UPGRADE_FRONTGRILL = 4,
    UPGRADE_WEAPONS = 5,
    UPGRADE_FLAG = 6,
    UPGRADE_THEME = 7,
    UPGRADE_TRANSMISSION = 8,
    UPGRADE_ENGINE = 9,
    UPGRADE_ARMOR = 10,
    UPGRADE_TIRERIPPERS = 11,
    UPGRADE_MAGNET = 12,
    UPGRADE_MAX = 13
};

enum vehicleClass_t : int {
    VEHICLE_CLASSNONE = 0,
    VEHICLE_CLASS1 = 1,
    VEHICLE_CLASS2 = 2,
    VEHICLE_CLASS3 = 3,
    VEHICLE_CLASS4 = 4
};

enum vehicleQuickUse_t : int {
    VQU_AFTERSHOCKER = 0,
    VQU_HEALTH = 1,
    VQU_HOVERING_TURRETS = 2,
    VQU_JUMP = 3,
    VQU_MONSTERBASHER = 4,
    VQU_REPAIR_BOTS = 5,
    VQU_ROVER_BOMBS = 6,
    VQU_SHIELD = 7,
    VQU_SMASH = 8,
    VQU_DROP_MINES = 9,
    VQU_UNKNOWN = 10,
    VQU_MAX = 11
};

// Retail idScriptObject derives from idClass and stores a type/data pair.
// The recovery surface preserves that Win32 layout without requiring the
// unrecovered game script runtime in declaration-only consumers.
class idScriptObject {
public:
    idScriptObject() : type(nullptr), data(nullptr) {}
    virtual ~idScriptObject() = default;

    void* type;
    unsigned char* data;
};

struct laserSightInfo_t {
    laserSightInfo_t();

    const idMaterial* laserBeamMtr;
    const idMaterial* laserDotMtr;
    float laserBeamHeight;
    float laserDotSize;
    float laserDotDepth;
    float laserDotMinSizeScale;
    float laserDotMaxSizeScale;
    bool laserDotQuad;
    float fadeIn;
    float fadeOut;
};

struct upgradeInfoMD6 {
    upgradeInfoMD6();

    idList<idStr, 5> meshesHiddenWithUpgrade;
    idList<idStr, 5> meshesShownWithUpgrade;
};

struct performanceStats_t {
    int acceleration;
    int suspension;
    int traction;
    int armor;
    float magnet;
};

class idDeclInventory;
class idDeclWeapon;
class idDeclAmmo;
class idDeclVehicleUpgrade;

struct validUpgradeLists_t {
    idList<const idDeclVehicleUpgrade*, 5> tireUpgrades;
    idList<const idDeclVehicleUpgrade*, 5> superChargerUpgrades;
    idList<const idDeclVehicleUpgrade*, 5> suspensionUpgrades;
    idList<const idDeclVehicleUpgrade*, 5> boosterUpgrades;
    idList<const idDeclVehicleUpgrade*, 5> frontGrillUpgrades;
    idList<const idDeclVehicleUpgrade*, 5> weaponUpgrades;
    idList<const idDeclVehicleUpgrade*, 5> flagUpgrades;
    idList<const idDeclVehicleUpgrade*, 5> themeUpgrades;
    idList<const idDeclVehicleUpgrade*, 5> transmissionUpgrades;
    idList<const idDeclVehicleUpgrade*, 5> exhaustUpgrades;
    idList<const idDeclVehicleUpgrade*, 5> armorUpgrades;
    idList<const idDeclVehicleUpgrade*, 5> tireRipperUpgrades;
    idList<const idDeclVehicleUpgrade*, 5> magnetUpgrades;
};

struct idSWFFile : public idAtomicString {
    idSWFFile() : idAtomicString() {}
};

class idDeclInventoryServices {
public:
    virtual ~idDeclInventoryServices() = default;
    virtual bool IsMultiplayer() const { return false; }
    virtual int GetTitleStorageInt(const char*, int defaultValue) const {
        return defaultValue;
    }
    virtual const idDeclAiEvent* ResolveAiEvent(const char*) const {
        return nullptr;
    }
};

void Tungsten_SetDeclInventoryServices(idDeclInventoryServices* services);
idDeclInventoryServices& Tungsten_DeclInventoryServices();

class idDeclInventory : public idDeclTypeInfo {
public:
    enum inventoryUse_t : int {
        INVENTORY_USE_UNDEF = 0,
        INVENTORY_USE_JOB = 1,
        INVENTORY_USE_QUICK = 2,
        INVENTORY_USE_ENGINEERING = 3,
        INVENTORY_USE_SELLABLE = 4,
        INVENTORY_USE_BUYABLE = 5,
        INVENTORY_USE_AMMO = 6,
        INVENTORY_USE_WEAPON = 7,
        INVENTORY_USE_USABLE = 8,
        INVENTORY_USE_NONE = 9,
        INVENTORY_USE_VEHICLE = 10
    };

    enum inventoryGroup_t : int {
        INVENTORY_GROUP_UNGROUPED = 0,
        INVENTORY_GROUP_BOOKS = 1,
        INVENTORY_GROUP_FOODS = 2,
        INVENTORY_GROUP_GAS = 3,
        INVENTORY_GROUP_OIL = 4,
        INVENTORY_GROUP_SMALL = 5,
        INVENTORY_GROUP_BEER = 6,
        INVENTORY_GROUP_TOOLS = 7
    };

    struct idAttachmentInfo {
        idAttachmentInfo()
            : equipSlot(EQUIP_NONE), particleFx(nullptr), tagName() {}
        equipSlot_t equipSlot;
        const idDeclParticle* particleFx;
        idStr tagName;
    };

    struct controllerShankInfo_t {
        float highMagnitude;
        int highDuration;
        float lowMagnitude;
        int lowDuration;
    };

    struct weaponAimSettings_t {
        bool aimPrimary;
        bool aimSecondary;
        bool aimLaserInWeaponDirPrim;
        bool aimLaserInWeaponDirSec;
    };

    struct itemListElement_t {
        const idDeclInventory* item;
        int count;
    };

    idDeclInventory();
    ~idDeclInventory() override = default;

    void Parse(idParser* parser) override;
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    static equipSlot_t EquipSlotForName(const char* name);
    const char* GetIconName() const;
    const char* GetGarageIconName() const;

    idStr inventoryClass;
    const idDeclMD6* handsModelMD6;
    const idDeclMD6* handsModelMD6Alt;
    const idDeclMD6* thirdPersonMD6;
    const idDeclInventory* dualWieldItemDecl;
    idStaticModel* thirdPersonStatic;
    idStaticModel* guiModel;
    float thirdPersonScale;
    idList<const idDeclInventory*, 5> childItem;
    const idMaterial* customMaterial;
    idList<idAttachmentInfo, 5> attachmentInfo;
    float handsFovScale;
    idStrId displayName;
    idStr internalName;
    idStrId description;
    idStrId boostDescription;
    idStrId requiredName;
    const idMaterial* icon;
    const idMaterial* quickIcon;
    const idMaterial* garageIcon;
    const idMaterial* engineeringIcon;
    const idMaterial* merchantIcon;
    const idMaterial* raceRewardImage;
    const idDeclEntityDef* entityDef;
    const idDeclEntityDef* boostEntityDef;
    bool usable;
    bool usableInTown;
    short maxCountOverride;
    quickSlotGroup_t quickSlotGroup;
    bool giveable;
    bool dropable;
    bool droppedBot;
    bool dropRemoveOnContact;
    controllerShankInfo_t droppedControllerShake;
    bool isWeapon;
    bool isVehicleAmmo;
    bool stackable;
    bool singular;
    bool removeOnUse;
    bool closeInventoryGuiOnUse;
    bool noAttachment;
    bool vehicleAttachment;
    bool vehiclePermAttachment;
    bool vehicleArmor;
    idStr vehicleJointName;
    bool noPickupMessage;
    removeCond_t removeCondition;
    float fadeDelay;
    int quickUseCoolDown;
    int maxCount;
    int count;
    int buyCount;
    int sellCount;
    int numHands;
    equipSlot_t equipSlot;
    equipSlot_t holsterSlot;
    bool sellStack;
    int price;
    int sellPrice;
    bool useRaceCertificates;
    bool playerCanSell;
    bool playerCanSeeInInventory;
    const idDeclRecipe* recipe;
    bool specialItem;
    idScriptObject scriptUse;
    bool isContainer;
    const idDeclInventory* containerDecl;
    bool useOnReceive;
    bool selectOnReceive;
    bool useOnDeath;
    bool blockEquipIfEmpty;
    short setCountOverride;
    const idSoundShader* useSound;
    const idSoundShader* dropSound;
    const idSoundShader* hoverSound;
    const idDeclAiEvent* dropEventDecl;
    inventoryUse_t itemUse;
    bool initiallyHidden;
    inventoryGroup_t itemGroup;
    int itemGroupWorth;
    weaponAimSettings_t aimWeaponSettings;
    idList<const idDeclInventory*, 5> giveItemsOnReceive;
    idList<itemListElement_t, 5> giveItemsOnRecieveWithCount;
    idList<idStr, 5> engineerableItems;
    const idDeclFX* weaponFX;
    const idDeclWeapon* equipWeaponOnUse;

    static const char* const equipSlotTagNames[EQUIP_MAX];
    static idDeclInfoTemplate<idDeclInventory> resourceList;
};

class mgDeclSmartLoot : public idDeclTypeInfo {
public:
    struct weightedItem_t {
        float weight{0.0f};
        const idDeclInventory* item{nullptr};
        int count{0};
    };

    struct itemGroup_t {
        itemGroup_t();
        float weight;
        float limit;
        idList<weightedItem_t, 5> items;
        idList<const idDeclInventory*, 5> requires;
    };

    struct randomGroups_t {
        itemGroup_t health;
        itemGroup_t armor;
    };

    struct ammoGroups_t {
        itemGroup_t ammo_light;
        itemGroup_t ammo_heavy;
        itemGroup_t ammo_grenade;
        itemGroup_t ammo_shells;
    };

    mgDeclSmartLoot();
    ~mgDeclSmartLoot() override = default;
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    randomGroups_t random;
    ammoGroups_t ammo;

    static idDeclInfoTemplate<mgDeclSmartLoot> resourceList;
};

class idDeclAmmo : public idDeclInventory {
public:
    enum zoomModeOverride_t : int {
        ZOOM_NO_OVERRIDE = 0,
        ZOOM_OVERRIDE_NONE = 1,
        ZOOM_OVERRIDE_WEAPON = 2
    };

    enum lockableTypes_t : int {
        ID_VEHICLE = 0,
        ID_BREAKABLE = 1,
        ID_AI2 = 2,
        ID_ENTITY = 3
    };

    idDeclAmmo();
    ~idDeclAmmo() override = default;
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    unsigned int GetLockableTypeFlags(int index) const;

    const idDeclProjectile* projectileDecl;
    idStr weapon;
    int ammoSlot;
    int extraFireInterval;
    idStr shootAnimPostfix;
    idStr reloadAnimPostfix;
    idStr ammoChangePrefix;
    idStr ammoChangeAnimOverride;
    idStr weaponPrefixOverride;
    zoomModeOverride_t zoomOverride;
    burstMode_t initialBurstModeOverride;
    int burstCountsOverride[3];
    idList<idStr, 5> meshesHiddenOnWeapon;
    idList<idStr, 5> meshesShownOnWeapon;
    idList<idStr, 5> meshesHiddenWhenEmpty;
    int lowAmmoWarningCount;
    const idSoundShader* lowAmmoWarningSound;
    bool chainFire;
    bool chargeFire;
    bool laserFire;
    bool secondaryAmmo;
    bool loopingReloadAnim;
    int chargeTime;
    int numCharges;
    int batteryDrain;
    contentsFlags_t lockableMasks;
    idList<lockableTypes_t, 5> lockableTypes;
    float lockableAngle;
    float unlockZoomedYaw;
    float unlockZoomedPitch;
    bool fireDirectlyAtLocable;

    static idDeclInfoTemplate<idDeclAmmo> resourceList;
};

class idDeclHealthItem : public idDeclInventory {
public:
    idDeclHealthItem();
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    float healthAmount;
    float healthPerTic;
    static idDeclInfoTemplate<idDeclHealthItem> resourceList;
};

class idDeclSecretItem : public idDeclInventory {
public:
    idDeclSecretItem();
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    int secretId;
    static idDeclInfoTemplate<idDeclSecretItem> resourceList;
};

class idDeclDamageBoostItem : public idDeclInventory {
public:
    idDeclDamageBoostItem();
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    float damageBoostMultiplier;
    float damageBoostDuration;
    static idDeclInfoTemplate<idDeclDamageBoostItem> resourceList;
};

class idDeclWeaponUpgrade : public idDeclInventory {
public:
    idDeclWeaponUpgrade();
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    idStr weaponToUpgrade;
    idStrId weaponToUpgradeName;
    bool upgradeScope;
    bool upgradeMagazine;
    bool upgradeLaserPointer;
    bool upgradeWeaponMode;
    idStr upgradeNodePrefix;

    static idDeclInfoTemplate<idDeclWeaponUpgrade> resourceList;
};

class idDeclLaserCutterUpgrade : public idDeclInventory {
public:
    idDeclLaserCutterUpgrade();
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    idDeclAmmo* ammoUpgrade;
    idDeclAmmo* secondaryAmmoUpgrade;
    idStr itemToUpgrade;
    bool upgradeBattery;
    int batteryAmount;
    bool remoteCutting;
    bool mobileReactor;
    int chargePerSecond;
    float chargeDelaySec;
    idStr upgradeNodePrefix;
    laserSightInfo_t shootingLaserOverride;

    static idDeclInfoTemplate<idDeclLaserCutterUpgrade> resourceList;
};

class idDeclWeapon : public idDeclInventory {
public:
    enum attackSequence_t : int {
        ATTACKSEQ_DEFAULT = 0,
        ATTACKSEQ_LEFT_RIGHT = 1,
        ATTACKSEQ_RANDOM_LEFT_RIGHT = 2,
        ATTACKSEQ_LEFT_RIGHT_2 = 3,
        ATTACKSEQ_RIGHT = 4,
        ATTACKSEQ_LEFT = 5,
        ATTACKSEQ_RIGHT2 = 6,
        ATTACKSEQ_LEFT2 = 7,
        ATTACKSEQ_RIGHT3 = 8,
        ATTACKSEQ_LEFT3 = 9
    };

    enum zoomMode_t : int {
        ZOOM_NONE = 0,
        ZOOM_WEAPON = 1
    };

    enum scopeGuiNum_t : int {
        SCOPE_NONE = 0,
        SCOPE_REGIMEMACHINEGUN = 1,
        SCOPE_CROSSBOW = 2,
        SCOPE_RIFLE = 3,
        SCOPE_REGIMEROCKETLAUNCHER = 4,
        SCOPE_PLASMARIFLE = 5,
        SCOPE_SKIPCROSSHAIR = 6
    };

    enum clipType_t : int {
        AMMOCLIP_NONE = 0,
        AMMOCLIP_SINGLE = 1,
        AMMOCLIP_KILLBURST = 2,
        AMMOCLIP_PISTOL_FATBOY = 3,
        AMMOCLIP_PISTOL_REG12 = 4,
        AMMOCLIP_MG_REG40 = 5,
        AMMOCLIP_SHOTGUN = 6,
        AMMOCLIP_ROCKET = 7,
        AMMOCLIP_SNIPER5 = 8,
        AMMOCLIP_DOUBLE = 9
    };

    struct ammoClip {
        const idDeclAmmo* validAmmoDecl{nullptr};
        clipType_t clipType{AMMOCLIP_NONE};
        int clipSize{0};
        int ammoPerReload{0};
        int upgradedClipSize{-1};
        int upgradedAmmoPerReload{-1};
        bool autoReload{false};
        bool upgradedAutoReload{false};
        bool isMultiplayerAllowed{true};
    };

    struct handMovement_t {
        float clamp;
        float scale;
        float retain;
        float recenter;
        idVec3 offsetAtMaxPitch;
        idVec3 offsetAtMinPitch;
        float offsetByYaw;
        float offsetByPitch;
        bool lockedHorizontal;
    };

    struct handRotation_t {
        idAngles minAngles;
        idAngles maxAngles;
        float scale;
        float retain;
        float extraYawMultiplier;
        float extraPitchMultiplier;
        float accelMaxDipAngle;
        float accelRotChangeSpeed;
        float strafeRotChangeSpeed;
        float strafeRightTiltAngle;
        float strafeLeftTiltAngle;
    };

    struct handCoverMovRot_t {
        handCoverMovRot_t();
        idVec3 offsetIndication;
        idVec3 rotIndication;
        idVec3 offsetLeft;
        idVec3 rotLeft;
        idVec3 offsetRight;
        idVec3 rotRight;
        idVec3 offsetUp;
        idVec3 rotUp;
        idVec3 offsetDown;
        idVec3 rotDown;
    };

    struct skillSettings_t {
        int minRepullTriggerInterval;
        int maxRepullTriggerInterval;
        int minBurstDuration;
        int maxBurstDuration;
        int minShotDelay;
        int maxShotDelay;
    };

    struct accuracySettings_t {
        struct wanderingAim_t {
            float fireKick;
            float maxDivergence;
            float firingConvergenceRate;
            float notFiringWanderRate;
            int aimCorrectionDelay;
            int aimCorrectionDuration;
            int requiredConvergenceTime;
        };
        float spread;
        wanderingAim_t wanderingAim;
    };

    struct zoomInfo_t {
        float zoomedFOV;
        float mouse_sensitivity_scale;
        float joy_sensitivity_scale;
        float movement_scale;
        float crouched_scale;
        int zoomTime;
        float spreadReductionWithZoom;
        bool hideHandsOnZoom;
        scopeGuiNum_t scopeGuiNum;
        int settleTime;
        idVec3 offset;
    };

    struct shellEjectEmitter_t {
        const idDeclEntityDef* breakableEmitter;
        float baseSpeed;
        float deltaSpeed;
        float deltaAngle;
    };

    idDeclWeapon();
    ~idDeclWeapon() override;
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    int GetClipSize(const idDeclAmmo* ammoDecl, bool weaponUpgraded,
        bool secondary) const;
    int GetAmmoPerReload(const idDeclAmmo* ammoDecl, bool weaponUpgraded,
        bool secondary) const;

    const idDeclAmmo* initialAmmoDecl;
    const idDeclAmmo* initialAmmoDeclSecondary;
    idList<ammoClip, 5> validAmmoClips;
    idList<ammoClip, 5> validAmmoClipsSecondary;
    bool infiniteAmmo;
    bool canOverheat;
    int timeTillOverheat;
    bool canZoom;
    int ammoPerShot;
    int weaponSlot;
    idAngles recoilAngles;
    float maxRange;
    float maxOptimalRange;
    float minOptimalRange;
    float minRange;
    bool alternatingFire;
    int addedFiringInterval;
    int reloadInterval;
    idStaticModel* crosshairModel;
    bool silenced;
    bool preferAimAtHead;
    bool usesFireControl;
    float thirdPersonFireAnimAlpha;
    bool thirdPersonRotateBarrel;
    idStr animPrefix;
    burstMode_t initialBurstMode;
    int burstCounts[3];
    bool postfixAmmo;
    attackSequence_t attackSequence;
    handMovement_t handLag;
    handRotation_t handRotation;
    handCoverMovRot_t handCoverMovRot;
    skillSettings_t skillSettings[5];
    accuracySettings_t accuracySettings[7];
    weaponAnimSet_t weaponAnimSet;
    bool trackProjectile;
    bool hasEmptyAnims;
    bool hasLastShotAnims;
    bool skipReloadAnims;
    bool lowerWhenNoTension;
    bool ignoreTensionForLower;
    const idDeclProjectile* pistolWhipProjectile;
    const idDeclProjectile* upgradedPistolWhipProjectile;
    idList<const idDeclThrowable*, 5> throwableDefList;
    bool allowLock;
    float lockOnRange;
    float unlockRange;
    float lockAngle;
    float unlockYaw;
    float unlockPitch;
    int maxLaunchDelayTime;
    int hideDelayTime;
    rageStat_t killStat;
    bool isDualWieldable;
    const idDeclAiEvent* reloadEventDecl;
    const idDeclAiEvent* silencedGunfireEventDecl;
    const idDeclAiEvent* gunfireEventDecl;
    bool attackVariations[3];
    idAngles minHandAngles;
    idAngles maxHandAngles;
    bool lockingFire;
    bool autoLock;
    const idSoundShader* acquiringSound;
    int acquireLoop;
    const idSoundShader* lockedSound;
    float lockTime;
    const idSoundShader* lockOn;
    const idSoundShader* lockOff;
    bool hasScopeUpgrade;
    upgradeInfoMD6 scopeUpgradeMD6Info;
    zoomMode_t zoomMode;
    zoomInfo_t ironSightZoom;
    idList<zoomInfo_t, 5> scopeZoom;
    float bobSwayScale;
    int bobSwayTransitionTime;
    float spreadReductionWithCrouch;
    float spreadIncreasedByMovement;
    idList<idStr, 5> upgradeDeclList;
    bool hasMagazineUpgrade;
    upgradeInfoMD6 magazineUpgradeMD6Info;
    bool hasLaserUpgrade;
    upgradeInfoMD6 laserUpgradeMD6Info;
    laserSightInfo_t laserSightInfo;
    bool hasWeaponModeUpgrade;
    upgradeInfoMD6 weponModeUpgradeMD6Info;
    bool barrelSpin;
    float maxSpin;
    float restSpin;
    float spinupRate;
    idStr nameRotation;
    const idSoundShader* overHeatingSound;
    const idSoundShader* overHeatRecoverySound;
    bool shouldSwitchWeaponWhenOutOfAmmo;
    int timeBetweenDecals;
    shellEjectEmitter_t shellEmitter;
    idStr shellEjectLeftTagName;
    idVec3 shellEjectLeftFirstPersonOffset;
    idStr shellEjectRightTagName;
    idVec3 shellEjectRightFirstPersonOffset;
    bool hideShellsOnZoom;
    const idDeclRibbon* ribbonEffect;
    int ribbonLifeSpan;
    int introAnimationID;
    int reloadVariation;
    const idInGameVideoFile* videoFile;
    bool videoPlaysWhenEquipped;
    bool allowForceFullClip;
    bool allowQuickuseDuringReload;
    bool allowSprintFire;
    const idMaterial* dwIcon;
    int firingIntervals[3];

    static idDeclInfoTemplate<idDeclWeapon> resourceList;
};

class idDeclLaserCutter : public idDeclWeapon {
public:
    idDeclLaserCutter();
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    laserSightInfo_t laserCutInfo;
    laserSightInfo_t laserShootInfo;
    laserSightInfo_t laserBounceIndicationInfo;
    bool hasBatteryUpgrade;
    bool hasRemoteCuttingUpgrade;
    bool hasMobileReactorUpgrade;
    upgradeInfoMD6 batteryUpgradeMD6Info;
    upgradeInfoMD6 remoteCuttingUpgradeMD6Info;
    upgradeInfoMD6 mobileReactorUpgradeUpgradeMD6Info;
    float clipSpinSpeed;
    idStr clipJointName;
    bool hasZoomLens;
    bool hasReflectionLens;
    bool hasLockOnLens;
    int maxBattery;
    int batteryAmount;
    int batteryDrainIntervalCut;

    static idDeclInfoTemplate<idDeclLaserCutter> resourceList;
};

class idDeclVehicleWeapon : public idDeclWeapon {
public:
    enum vehicleWeaponType_t : int {
        VEHICLEWEAPON_NONE = 0,
        VEHICLEWEAPON_MG = 1,
        VEHICLEWEAPON_MISSILE = 2,
        VEHICLEWEAPON_HEAVY_MG = 3,
        VEHICLEWEAPON_ROCKET = 4,
        VEHICLEWEAPON_NAIL_GUN = 5,
        VEHICLEWEAPON_RAIL_GUN = 6,
        VEHICLEWEAPON_PULSE_CANNON = 7,
        VEHICLEWEAPON_CLUSTER_BOMB = 8
    };

    struct anims_t {
        idStr idle;
        idStr entry;
        idStr exit;
        idStr fire;
        idStr mannedIdle;
        idStr mannedEntry;
        idStr mannedExit;
        idStr gunnerEnter;
        idStr gunnerExit;
    };

    idDeclVehicleWeapon();
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    anims_t anims;
    idStr pitchJointName;
    idStr yawJointName;
    idStr spinJointName;
    float spinDir;
    int spinAxis;
    bool isDependent;
    idStr playerSeatWeapon;
    idStr transitionSeat;
    idStr zoomSeat;
    idStr npcSeatWeapon;
    const idSoundShader* switchToSound;
    const idSoundShader* beginFireSound;
    const idSoundShader* endFireSound;
    const idSoundShader* beginDryFireSound;
    const idSoundShader* dryFireSound;
    const idSoundShader* quadFireLoop;
    bool canAttackActors;
    bool useLaserSight;
    idDeclVehicleWeapon* remoteFireWeapon;
    float remoteWeaponDelay;
    bool isRemoteFired;
    float aiMinDelayTimeSecs;
    float aiMaxDelayTimeSecs;
    float aiMinFireTimeSecs;
    float aiMaxFireTimeSecs;
    idAngles minAngles;
    idAngles maxAngles;
    idAngles minAnglesAtWeapon;
    idAngles maxAnglesAtWeapon;
    idAngles aiMinAngles;
    idAngles aiMaxAngles;
    bool playerRotatable;
    float rotateSpeed;
    idVec3 viewOffset;
    vehicleWeaponType_t vehicleWeaponType;
    float lockAimAssist;
    bool disableHudTarget;
    idVec3 positionOffsetHack;

    static idDeclInfoTemplate<idDeclVehicleWeapon> resourceList;
};

class idDeclVehicleUpgrade : public idDeclInventory {
public:
    idDeclVehicleUpgrade();
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    upgradeType_t upgradeType;
    idStrId displayTypeStr;
    idDeclEntityDef* upgradedDef;
    performanceStats_t performanceStats;
    int stage;
    idList<idDeclInventory*, 5> appendDecl;
    idList<idDeclInventory*, 5> removeDecl;

    static idDeclInfoTemplate<idDeclVehicleUpgrade> resourceList;
};

class idDeclVehicleKey : public idDeclInventory {
public:
    idDeclVehicleKey();
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    vehicleClass_t vehicleClass;
    idDeclEntityDef* vehicleDef;
    validUpgradeLists_t validUpgradeLists;
    int repairCost;
    const idMaterial* vehicleIcon;
    const idMaterial* vehicleNameIcon;
    const idMaterial* raceImage;
    idSWFFile tunerGui;
    float townGarageZAdjust;

    static idDeclInfoTemplate<idDeclVehicleKey> resourceList;
};

class idDeclPlayerArmor : public idDeclInventory {
public:
    idDeclPlayerArmor();
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    float protectionPercent;
    float armorReductionPercent;
    float armorAmount;
    float maxArmor;
    static idDeclInfoTemplate<idDeclPlayerArmor> resourceList;
};

class idDeclVehicleArmor : public idDeclInventory {
public:
    idDeclVehicleArmor();
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    float damageScale;
    bool damageItemLast;
    bool isSpike;
    static idDeclInfoTemplate<idDeclVehicleArmor> resourceList;
};

class idDeclVehicleArmorKit : public idDeclInventory {
public:
    idDeclVehicleArmorKit();
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    idList<const idDeclInventory*, 5> armorItemDecls;
    static idDeclInfoTemplate<idDeclVehicleArmorKit> resourceList;
};

class idDeclVehicleQuickUseItem : public idDeclInventory {
public:
    idDeclVehicleQuickUseItem();
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    const idDeclWeapon* weaponDecl;
    const idDeclDamage* damageDecl;
    float damagePerSecond;
    fxCondition_t fxType;
    int useCooldown;
    int entityDuration;
    idColor shieldHealthyColor;
    idColor shieldDamagedColor;
    float shieldDamagePercentage;
    vehicleQuickUse_t quickUseType;

    static idDeclInfoTemplate<idDeclVehicleQuickUseItem> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idScriptObject) == 12,
    "Recovered script-object ABI changed");
static_assert(sizeof(idDeclInventory) == 504,
    "Recovered inventory declaration ABI changed");
static_assert(sizeof(idDeclWeapon) == 1896,
    "Recovered weapon declaration ABI changed");
#endif
