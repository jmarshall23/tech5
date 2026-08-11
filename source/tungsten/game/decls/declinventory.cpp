#include "game/decls/declinventory.h"

#include "renderer/declmaterial.h"

#include <algorithm>
#include <cstring>

namespace {

class DefaultInventoryServices final : public idDeclInventoryServices {
};

DefaultInventoryServices defaultInventoryServices;
idDeclInventoryServices* inventoryServices = &defaultInventoryServices;

const idDeclWeapon::skillSettings_t defaultSkillSettings[5] = {
    { 2000, 10000, 100, 500, 100, 2500 },
    { 1000, 8000, 100, 500, 100, 1500 },
    { 500, 4000, 250, 750, 100, 1000 },
    { 250, 2500, 500, 1000, 0, 750 },
    { 250, 1500, 500, 1000, 0, 500 }
};

const idDeclWeapon::accuracySettings_t defaultAccuracySettings[7] = {
    { 16.0f, { 0.01f, 0.10f, 0.0015f, 0.0015f, 500, 500, 0 } },
    { 16.0f, { 0.01f, 0.10f, 0.0015f, 0.0015f, 500, 500, 0 } },
    { 16.0f, { 0.01f, 0.10f, 0.0015f, 0.0015f, 500, 500, 0 } },
    { 16.0f, { 0.01f, 0.05f, 0.0015f, 0.0015f, 400, 500, 0 } },
    { 16.0f, { 0.01f, 0.025f, 0.0015f, 0.0015f, 200, 500, 0 } },
    { 16.0f, { 0.01f, 0.0f, 0.0015f, 0.0015f, 0, 500, 0 } },
    { 0.0f, { 0.0f, 0.0f, 1.0f, 0.0f, 0, 0, 0 } }
};

} // namespace

void Tungsten_SetDeclInventoryServices(idDeclInventoryServices* services) {
    inventoryServices = services != nullptr
        ? services : &defaultInventoryServices;
}

idDeclInventoryServices& Tungsten_DeclInventoryServices() {
    return *inventoryServices;
}

const char* const idDeclInventory::equipSlotTagNames[EQUIP_MAX] = {
    "< none >",
    "left_hand",
    "right_hand",
    "head",
    "torso",
    "holster_hip_left",
    "holster_hip_right",
    "holster_back",
    "holster_shoulder",
    "holster_belt_left",
    "holster_belt_right",
    "holster_belt_back",
    "holster_belt_front",
    "vehicle",
    "vehicle_ram"
};

laserSightInfo_t::laserSightInfo_t()
    : laserBeamMtr(nullptr)
    , laserDotMtr(nullptr)
    , laserBeamHeight(2.0f)
    , laserDotSize(1.0f)
    , laserDotDepth(8.0f)
    , laserDotMinSizeScale(0.25f)
    , laserDotMaxSizeScale(3.0f)
    , laserDotQuad(false)
    , fadeIn(0.0f)
    , fadeOut(0.0f) {
}

upgradeInfoMD6::upgradeInfoMD6()
    : meshesHiddenWithUpgrade()
    , meshesShownWithUpgrade() {
}

// Retail symbol: ??0handCoverMovRot_t@idDeclWeapon@@QAA@XZ
// EA 0x82BC0FF8 (header-defined retail constructor).
idDeclWeapon::handCoverMovRot_t::handCoverMovRot_t()
    : offsetIndication(0.0f, 0.0f, 0.0f)
    , rotIndication(0.0f, -25.0f, 0.0f)
    , offsetLeft(0.0f, 3.6f, 2.15f)
    , rotLeft(15.0f, 0.0f, 0.0f)
    , offsetRight(-1.0f, -2.0f, 2.75f)
    , rotRight(-10.0f, 0.0f, 0.0f)
    , offsetUp(-2.0f, 0.0f, 3.0f)
    , rotUp(-15.0f, 0.0f, 0.0f)
    , offsetDown(0.0f, 4.0f, -0.5f)
    , rotDown(35.0f, 0.0f, 0.0f) {
}

// Retail symbol: ??0itemGroup_t@mgDeclSmartLoot@@QAA@XZ
// EA 0x82BC1E08 (header-defined retail constructor).
mgDeclSmartLoot::itemGroup_t::itemGroup_t()
    : weight(0.0f)
    , limit(1.0f)
    , items()
    , requires() {
}

// Retail symbol: ??0upgradeInfoMD6@@QAA@XZ
// EA 0x82BC2230 (header-defined retail constructor).

// EA 0x82BC0F98
equipSlot_t idDeclInventory::EquipSlotForName(const char* name) {
    if (name == nullptr) {
        return EQUIP_MAX;
    }
    for (int index = 0; index < EQUIP_MAX; ++index) {
        if (idStr::Icmp(equipSlotTagNames[index], name) == 0) {
            return static_cast<equipSlot_t>(index);
        }
    }
    return EQUIP_MAX;
}

// EA 0x82BC10F0
const char* idDeclInventory::GetIconName() const {
    return icon != nullptr ? icon->GetName() : "";
}

// EA 0x82BC1110
const char* idDeclInventory::GetGarageIconName() const {
    return garageIcon != nullptr ? garageIcon->GetName() : "";
}

// EA 0x82BC1130
unsigned int idDeclAmmo::GetLockableTypeFlags(int index) const {
    switch (lockableTypes[index]) {
    case ID_VEHICLE:
        return 4;
    case ID_BREAKABLE:
        return 8;
    case ID_AI2:
        return 2;
    case ID_ENTITY:
        return 1;
    default:
        return 16;
    }
}

// EA 0x82BC1180
int idDeclWeapon::GetClipSize(const idDeclAmmo* ammoDecl,
        bool weaponUpgraded, bool secondary) const {
    const idList<ammoClip, 5>& clips = secondary
        ? validAmmoClipsSecondary : validAmmoClips;
    for (int index = 0; index < clips.Num(); ++index) {
        const ammoClip& clip = clips[index];
        if (clip.validAmmoDecl != ammoDecl) {
            continue;
        }
        if (weaponUpgraded && clip.upgradedClipSize != -1) {
            return clip.upgradedClipSize;
        }
        return clip.clipSize;
    }
    return 0;
}

// EA 0x82BC1208
int idDeclWeapon::GetAmmoPerReload(const idDeclAmmo* ammoDecl,
        bool weaponUpgraded, bool secondary) const {
    const idList<ammoClip, 5>& clips = secondary
        ? validAmmoClipsSecondary : validAmmoClips;
    for (int index = 0; index < clips.Num(); ++index) {
        const ammoClip& clip = clips[index];
        if (clip.validAmmoDecl != ammoDecl) {
            continue;
        }
        if (weaponUpgraded && clip.upgradedAmmoPerReload != -1) {
            return clip.upgradedAmmoPerReload;
        }
        return clip.ammoPerReload;
    }
    return 0;
}

// EA 0x82BC1560
void idDeclInventory::Parse(idParser* parser) {
    idDeclTypeInfo::Parse(parser);
    idDeclInventoryServices& services = Tungsten_DeclInventoryServices();
    if (!services.IsMultiplayer()) {
        return;
    }

    idStr maxCountKey("itemMaxCount_");
    maxCountKey.Append(GetName());
    maxCountOverride = static_cast<short>(
        services.GetTitleStorageInt(maxCountKey.c_str(), -1));

    idStr setCountKey("itemSetCount_");
    setCountKey.Append(GetName());
    setCountOverride = static_cast<short>(
        services.GetTitleStorageInt(setCountKey.c_str(), -1));
}

// EA 0x82BC23C0
idDeclInventory::idDeclInventory()
    : inventoryClass("idInventoryItem")
    , handsModelMD6(nullptr)
    , handsModelMD6Alt(nullptr)
    , thirdPersonMD6(nullptr)
    , dualWieldItemDecl(nullptr)
    , thirdPersonStatic(nullptr)
    , guiModel(nullptr)
    , thirdPersonScale(1.0f)
    , childItem()
    , customMaterial(nullptr)
    , attachmentInfo()
    , handsFovScale(0.7f)
    , displayName()
    , internalName()
    , description()
    , boostDescription()
    , requiredName()
    , icon(nullptr)
    , quickIcon(nullptr)
    , garageIcon(nullptr)
    , engineeringIcon(nullptr)
    , merchantIcon(nullptr)
    , raceRewardImage(nullptr)
    , entityDef(nullptr)
    , boostEntityDef(nullptr)
    , usable(true)
    , usableInTown(false)
    , maxCountOverride(-1)
    , quickSlotGroup(QUICKSLOTGROUP_NONE)
    , giveable(false)
    , dropable(true)
    , droppedBot(false)
    , dropRemoveOnContact(false)
    , droppedControllerShake{ 0.0f, 0, 0.0f, 0 }
    , isWeapon(false)
    , isVehicleAmmo(false)
    , stackable(false)
    , singular(false)
    , removeOnUse(false)
    , closeInventoryGuiOnUse(false)
    , noAttachment(false)
    , vehicleAttachment(false)
    , vehiclePermAttachment(false)
    , vehicleArmor(false)
    , vehicleJointName()
    , noPickupMessage(false)
    , removeCondition(REMOVE_CONDITION_NONE)
    , fadeDelay(0.0f)
    , quickUseCoolDown(0)
    , maxCount(9999)
    , count(1)
    , buyCount(1)
    , sellCount(-1)
    , numHands(1)
    , equipSlot(EQUIP_NONE)
    , holsterSlot(EQUIP_NONE)
    , sellStack(false)
    , price(5)
    , sellPrice(2)
    , useRaceCertificates(false)
    , playerCanSell(true)
    , playerCanSeeInInventory(true)
    , recipe(nullptr)
    , specialItem(false)
    , scriptUse()
    , isContainer(false)
    , containerDecl(nullptr)
    , useOnReceive(false)
    , selectOnReceive(true)
    , useOnDeath(false)
    , blockEquipIfEmpty(false)
    , setCountOverride(-1)
    , useSound(nullptr)
    , dropSound(nullptr)
    , hoverSound(nullptr)
    , dropEventDecl(nullptr)
    , itemUse(INVENTORY_USE_UNDEF)
    , initiallyHidden(false)
    , itemGroup(INVENTORY_GROUP_UNGROUPED)
    , itemGroupWorth(1)
    , aimWeaponSettings{ false, false, false, false }
    , giveItemsOnReceive()
    , giveItemsOnRecieveWithCount()
    , engineerableItems()
    , weaponFX(nullptr)
    , equipWeaponOnUse(nullptr) {
    dropEventDecl = Tungsten_DeclInventoryServices().ResolveAiEvent(
        "base/sound/deploy");
}

// EA 0x82BC2890
mgDeclSmartLoot::mgDeclSmartLoot()
    : random()
    , ammo() {
}

// EA 0x82BC2CC8
idDeclAmmo::idDeclAmmo()
    : projectileDecl(nullptr)
    , weapon()
    , ammoSlot(0)
    , extraFireInterval(0)
    , shootAnimPostfix()
    , reloadAnimPostfix()
    , ammoChangePrefix()
    , ammoChangeAnimOverride()
    , weaponPrefixOverride()
    , zoomOverride(ZOOM_NO_OVERRIDE)
    , initialBurstModeOverride(BURSTMODE_MAX)
    , burstCountsOverride{ 0, -1, 0 }
    , meshesHiddenOnWeapon()
    , meshesShownOnWeapon()
    , meshesHiddenWhenEmpty()
    , lowAmmoWarningCount(0)
    , lowAmmoWarningSound(nullptr)
    , chainFire(false)
    , chargeFire(false)
    , laserFire(false)
    , secondaryAmmo(false)
    , loopingReloadAnim(false)
    , chargeTime(0)
    , numCharges(0)
    , batteryDrain(0)
    , lockableMasks(CONTENTS_SOLID)
    , lockableTypes()
    , lockableAngle(35.0f)
    , unlockZoomedYaw(16.5f)
    , unlockZoomedPitch(9.0f)
    , fireDirectlyAtLocable(true) {
    inventoryClass = "idAmmoItem";
    usable = false;
    stackable = true;
}

// EA 0x82BC3368
idDeclHealthItem::idDeclHealthItem()
    : healthAmount(0.0f)
    , healthPerTic(0.0f) {
    usable = true;
    stackable = true;
    inventoryClass = "idHealthItem";
    itemUse = INVENTORY_USE_QUICK;
}

// EA 0x82BC3428
idDeclSecretItem::idDeclSecretItem()
    : secretId(-1) {
    usable = true;
    stackable = true;
    removeOnUse = true;
    useOnReceive = true;
    inventoryClass = "idSecretItem";
    itemUse = INVENTORY_USE_QUICK;
}

// EA 0x82BC34E8
idDeclDamageBoostItem::idDeclDamageBoostItem()
    : damageBoostMultiplier(4.0f)
    , damageBoostDuration(30.0f) {
    usable = true;
    stackable = true;
    inventoryClass = "idDamageBoostItem";
    itemUse = INVENTORY_USE_QUICK;
}

// EA 0x82BC35B0
idDeclWeaponUpgrade::idDeclWeaponUpgrade()
    : weaponToUpgrade()
    , weaponToUpgradeName()
    , upgradeScope(false)
    , upgradeMagazine(false)
    , upgradeLaserPointer(false)
    , upgradeWeaponMode(false)
    , upgradeNodePrefix() {
    inventoryClass = "idWeaponUpgrade";
    dropable = false;
    giveable = true;
    removeOnUse = true;
    usable = true;
    singular = true;
    playerCanSell = false;
    closeInventoryGuiOnUse = true;
    upgradeNodePrefix.Clear();
}

// EA 0x82BC37C0
idDeclLaserCutterUpgrade::idDeclLaserCutterUpgrade()
    : ammoUpgrade(nullptr)
    , secondaryAmmoUpgrade(nullptr)
    , itemToUpgrade()
    , upgradeBattery(false)
    , batteryAmount(0)
    , remoteCutting(false)
    , mobileReactor(false)
    , chargePerSecond(0)
    , chargeDelaySec(0.0f)
    , upgradeNodePrefix()
    , shootingLaserOverride() {
    inventoryClass = "idLaserCutterUpgrade";
    dropable = false;
    giveable = true;
    removeOnUse = true;
    usable = true;
    singular = true;
    playerCanSell = false;
    closeInventoryGuiOnUse = true;
    upgradeNodePrefix.Clear();
}

// EA 0x82BC3A30
idDeclWeapon::idDeclWeapon()
    : initialAmmoDecl(nullptr)
    , initialAmmoDeclSecondary(nullptr)
    , validAmmoClips()
    , validAmmoClipsSecondary()
    , infiniteAmmo(false)
    , canOverheat(false)
    , timeTillOverheat(3500)
    , canZoom(true)
    , ammoPerShot(0)
    , weaponSlot(-1)
    , recoilAngles(-1.0f, 0.0f, 0.0f)
    , maxRange(2048.0f)
    , maxOptimalRange(512.0f)
    , minOptimalRange(256.0f)
    , minRange(0.0f)
    , alternatingFire(false)
    , addedFiringInterval(0)
    , reloadInterval(3000)
    , crosshairModel(nullptr)
    , silenced(false)
    , preferAimAtHead(false)
    , usesFireControl(true)
    , thirdPersonFireAnimAlpha(1.0f)
    , thirdPersonRotateBarrel(false)
    , animPrefix()
    , initialBurstMode(BURSTMODE_DEFAULT)
    , burstCounts{ 0, -1, 0 }
    , postfixAmmo(false)
    , attackSequence(ATTACKSEQ_DEFAULT)
    , handLag{ 0.0f, 0.0f, 0.0f, 0.015f,
        idVec3(0.0f, 0.0f, 0.0f), idVec3(0.0f, 0.0f, 0.0f),
        0.0f, 0.0f, false }
    , handRotation{ idAngles(0.0f, 0.0f, 0.0f),
        idAngles(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f }
    , handCoverMovRot()
    , skillSettings{}
    , accuracySettings{}
    , weaponAnimSet(WEAPONANIM_FISTS)
    , trackProjectile(false)
    , hasEmptyAnims(false)
    , hasLastShotAnims(false)
    , skipReloadAnims(true)
    , lowerWhenNoTension(true)
    , ignoreTensionForLower(false)
    , pistolWhipProjectile(nullptr)
    , upgradedPistolWhipProjectile(nullptr)
    , throwableDefList()
    , allowLock(true)
    , lockOnRange(4500.0f)
    , unlockRange(5500.0f)
    , lockAngle(25.0f)
    , unlockYaw(35.0f)
    , unlockPitch(15.0f)
    , maxLaunchDelayTime(0)
    , hideDelayTime(15000)
    , killStat(static_cast<rageStat_t>(-1))
    , isDualWieldable(false)
    , reloadEventDecl(nullptr)
    , silencedGunfireEventDecl(nullptr)
    , gunfireEventDecl(nullptr)
    , attackVariations{ true, true, true }
    , minHandAngles(-180.0f, -180.0f, 0.0f)
    , maxHandAngles(180.0f, 180.0f, 0.0f)
    , lockingFire(false)
    , autoLock(false)
    , acquiringSound(nullptr)
    , acquireLoop(300)
    , lockedSound(nullptr)
    , lockTime(2.0f)
    , lockOn(nullptr)
    , lockOff(nullptr)
    , hasScopeUpgrade(false)
    , scopeUpgradeMD6Info()
    , zoomMode(ZOOM_NONE)
    , ironSightZoom{ 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0, 0.5f,
        false, SCOPE_NONE, 0, idVec3(0.0f, 0.0f, 0.0f) }
    , scopeZoom()
    , bobSwayScale(0.1f)
    , bobSwayTransitionTime(100)
    , spreadReductionWithCrouch(1.0f)
    , spreadIncreasedByMovement(1.0f)
    , upgradeDeclList()
    , hasMagazineUpgrade(false)
    , magazineUpgradeMD6Info()
    , hasLaserUpgrade(false)
    , laserUpgradeMD6Info()
    , laserSightInfo()
    , hasWeaponModeUpgrade(false)
    , weponModeUpgradeMD6Info()
    , barrelSpin(false)
    , maxSpin(300.0f)
    , restSpin(200.0f)
    , spinupRate(25.0f)
    , nameRotation()
    , overHeatingSound(nullptr)
    , overHeatRecoverySound(nullptr)
    , shouldSwitchWeaponWhenOutOfAmmo(true)
    , timeBetweenDecals(0)
    , shellEmitter{ nullptr, 0.0f, 0.0f, 0.0f }
    , shellEjectLeftTagName()
    , shellEjectLeftFirstPersonOffset(0.0f, 0.0f, 0.0f)
    , shellEjectRightTagName()
    , shellEjectRightFirstPersonOffset(0.0f, 0.0f, 0.0f)
    , hideShellsOnZoom(true)
    , ribbonEffect(nullptr)
    , ribbonLifeSpan(0)
    , introAnimationID(-1)
    , reloadVariation(0)
    , videoFile(nullptr)
    , videoPlaysWhenEquipped(true)
    , allowForceFullClip(true)
    , allowQuickuseDuringReload(true)
    , allowSprintFire(false)
    , dwIcon(nullptr)
    , firingIntervals{ 500, 0, 0 } {
    inventoryClass = "idWeapon";
    usable = false;
    price = 50;
    equipSlot = EQUIP_RIGHT_HAND;
    singular = true;
    playerCanSell = false;
    std::copy(defaultSkillSettings, defaultSkillSettings + 5,
        skillSettings);
    std::copy(defaultAccuracySettings, defaultAccuracySettings + 7,
        accuracySettings);
}

// EA 0x82BC4398
idDeclWeapon::~idDeclWeapon() = default;

// EA 0x82BC46A8
idDeclLaserCutter::idDeclLaserCutter()
    : laserCutInfo()
    , laserShootInfo()
    , laserBounceIndicationInfo()
    , hasBatteryUpgrade(false)
    , hasRemoteCuttingUpgrade(false)
    , hasMobileReactorUpgrade(false)
    , batteryUpgradeMD6Info()
    , remoteCuttingUpgradeMD6Info()
    , mobileReactorUpgradeUpgradeMD6Info()
    , clipSpinSpeed(120.0f)
    , clipJointName()
    , hasZoomLens(false)
    , hasReflectionLens(false)
    , hasLockOnLens(false)
    , maxBattery(0)
    , batteryAmount(0)
    , batteryDrainIntervalCut(0) {
    inventoryClass = "idLaserCutter";
}

// EA 0x82BC4A18
idDeclVehicleWeapon::idDeclVehicleWeapon()
    : anims()
    , pitchJointName("pitch")
    , yawJointName("yaw")
    , spinJointName()
    , spinDir(1.0f)
    , spinAxis(0)
    , isDependent(false)
    , playerSeatWeapon("player_seat_weapon")
    , transitionSeat()
    , zoomSeat()
    , npcSeatWeapon("npc_seat_weapon")
    , switchToSound(nullptr)
    , beginFireSound(nullptr)
    , endFireSound(nullptr)
    , beginDryFireSound(nullptr)
    , dryFireSound(nullptr)
    , quadFireLoop(nullptr)
    , canAttackActors(true)
    , useLaserSight(false)
    , remoteFireWeapon(nullptr)
    , remoteWeaponDelay(0.0f)
    , isRemoteFired(false)
    , aiMinDelayTimeSecs(1.0f)
    , aiMaxDelayTimeSecs(3.0f)
    , aiMinFireTimeSecs(1.0f)
    , aiMaxFireTimeSecs(3.0f)
    , minAngles(0.0f, 360.0f, 0.0f)
    , maxAngles(0.0f, 360.0f, 0.0f)
    , minAnglesAtWeapon(-15.0f, -181.0f, 0.0f)
    , maxAnglesAtWeapon(15.0f, 181.0f, 0.0f)
    , aiMinAngles(-45.0f, -181.0f, 0.0f)
    , aiMaxAngles(45.0f, 181.0f, 0.0f)
    , playerRotatable(false)
    , rotateSpeed(5.0f)
    , viewOffset(0.0f, 0.0f, 0.0f)
    , vehicleWeaponType(VEHICLEWEAPON_NONE)
    , lockAimAssist(10.0f)
    , disableHudTarget(false)
    , positionOffsetHack(0.0f, 0.0f, 0.0f) {
    equipSlot = EQUIP_VEHICLE;
    giveable = false;
    infiniteAmmo = false;
    canOverheat = false;
    timeTillOverheat = 3500;
    ammoPerShot = 0;
    weaponSlot = -1;
    initialBurstMode = BURSTMODE_FULLAUTO;
    burstCounts[0] = -1;
}

// EA 0x82BC4FE8
idDeclVehicleUpgrade::idDeclVehicleUpgrade()
    : upgradeType(UPGRADE_TIRES)
    , displayTypeStr()
    , upgradedDef(nullptr)
    , performanceStats{ 0, 0, 0, 0, 0.0f }
    , stage(0)
    , appendDecl()
    , removeDecl() {
    dropable = false;
    usable = false;
    inventoryClass = "idVehicleUpgrade";
    playerCanSell = false;
    singular = true;
    playerCanSeeInInventory = false;
    useRaceCertificates = true;
}

// EA 0x82BC5218
idDeclVehicleKey::idDeclVehicleKey()
    : vehicleClass(VEHICLE_CLASS2)
    , vehicleDef(nullptr)
    , validUpgradeLists()
    , repairCost(125)
    , vehicleIcon(nullptr)
    , vehicleNameIcon(nullptr)
    , raceImage(nullptr)
    , tunerGui()
    , townGarageZAdjust(10.0f) {
    dropable = false;
    usable = false;
    singular = true;
    playerCanSell = false;
    inventoryClass = "idVehicleKey";
}

// EA 0x82BC53A0
idDeclPlayerArmor::idDeclPlayerArmor()
    : protectionPercent(0.0f)
    , armorReductionPercent(0.0f)
    , armorAmount(0.0f)
    , maxArmor(0.0f) {
    inventoryClass = "idPlayerArmor";
    singular = true;
    playerCanSell = false;
    equipSlot = EQUIP_TORSO;
    playerCanSeeInInventory = false;
    useOnReceive = true;
}

// EA 0x82BC5470
idDeclVehicleArmor::idDeclVehicleArmor()
    : damageScale(1.0f)
    , damageItemLast(false)
    , isSpike(false) {
    playerCanSell = false;
}

// EA 0x82BC54E0
idDeclVehicleArmorKit::idDeclVehicleArmorKit()
    : armorItemDecls() {
    playerCanSell = false;
}

// EA 0x82BC5578
idDeclVehicleQuickUseItem::idDeclVehicleQuickUseItem()
    : weaponDecl(nullptr)
    , damageDecl(nullptr)
    , damagePerSecond(-1.0f)
    , fxType(FX_NONE)
    , useCooldown(3000)
    , entityDuration(10000)
    , shieldHealthyColor(0.3f, 0.5f, 0.7f, 0.9f)
    , shieldDamagedColor(0.85f, 0.2f, 0.2f, 0.9f)
    , shieldDamagePercentage(0.9f)
    , quickUseType(VQU_UNKNOWN) {
}
