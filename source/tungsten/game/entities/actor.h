#pragma once

#include "game/ai/aaspositionmgr.h"
#include "game/ai/aistates.h"
#include "game/ai/aimoveparms.h"
#include "game/ai/aievents/aievent.h"
#include "game/decls/decldamage.h"
#include "game/decls/declfaction.h"
#include "game/decls/declinventory.h"
#include "game/decls/decltwitchpain.h"
#include "game/effects/gameeffects.h"
#include "game/entities/entityptr.h"
#include "game/entities/loot.h"
#include "game/gamesys/eventarg.h"
#include "idlib/bv/bounds.h"
#include "idlib/containers/list.h"
#include "idlib/handle.h"
#include "idlib/index.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

#include <cstdint>

class idAAS2;
class idActor;
class idDeclAiEvent;
class idDeclEntityDef;
class idDeclFootstepEvents;
class idDeclMD6;
class idDeclParticle;
class idDeclProjectileImpactEffect;
class idDeclWalkIK;
class idEntity;
class idFXManager;
class idInventoryItem;
class idMD6Anim;
class idPresentable;
class idRenderModel;
class idSoundShader;
class idTreeAnimator;
class idVehicle;
class idWeapon;
enum invalidJointIndex_t : int;

using idActorJointIndex = idIndex<short, invalidJointIndex_t>;

enum invalidJointGroupHandle : int {
    INVALID_JOINT_GROUP = 0
};
using idJointGroupHandle =
    idHandle<int, invalidJointGroupHandle, INVALID_JOINT_GROUP>;

enum actorClass_t : int {
    ACTORCLASS_PLAYER = 0,
    ACTORCLASS_HUMAN = 1,
    ACTORCLASS_MUTANT = 2,
    ACTORCLASS_ROBOT = 3,
    ACTORCLASS_MAX = 4
};

enum aimPoint_t : int {
    AIMPOINT_ORIGIN = 0,
    AIMPOINT_HEAD = 1,
    AIMPOINT_TORSO = 2,
    AIMPOINT_CENTER = 3,
    AIMPOINT_LEGS = 4,
    AIMPOINT_FEET = 5,
    AIMPOINT_BEST = 6,
    AIMPOINT_EYELEVEL = 7,
    AIMPOINT_LOOKAHEAD = 8,
    AIMPOINT_MAX = 9
};

enum walkState_t : int {
    WALKSTATE_NOCLIP = 0,
    WALKSTATE_WALKING = 1,
    WALKSTATE_RUNNING = 2,
    WALKSTATE_SPRINTING = 3,
    WALKSTATE_MAX = 4
};

enum leanState_t : int {
    LEAN_NONE = 0,
    LEAN_LEFT = 1,
    LEAN_RIGHT = 2,
    LEAN_MAX = 3
};

enum weaponReadyState_t : int {
    WEAPONREADY_NONE = 0,
    WEAPONREADY_HOLSTERED = 1,
    WEAPONREADY_LOWERED = 2,
    WEAPONREADY_RAISED = 3
};

enum turnState_t : int {
    TURNSTATE_DEFAULT = 0,
    TURNSTATE_ARMSCROSSED = 1,
    TURNSTATE_MAX = 2
};

enum mentalState_t : int {
    MENTALSTATE_AWAKE = 0,
    MENTALSTATE_ASLEEP = 1,
    MENTALSTATE_DRUNK = 2,
    MENTALSTATE_MAX = 3
};

enum factionType_t : int {
    FACTIONTYPE_NONE = 0
};

enum footStepType_t : int {
    FOOTSTEP_LEFT_FOOT = 0,
    FOOTSTEP_RIGHT_FOOT = 1,
    FOOTSTEP_LEFT_REAR_FOOT = 2,
    FOOTSTEP_RIGHT_REAR_FOOT = 3,
    FOOTSTEP_LAND = 4,
    FOOTSTEP_LEFT_FOOT_LADDER = 5,
    FOOTSTEP_RIGHT_FOOT_LADDER = 6,
    FOOTSTEP_LAND_NO_GROUND_CHECK = 7,
    FOOTSTEP_MAX = 8
};

enum actorRagdollResult_t : int {
    ACTOR_RAGDOLL_OK = 0,
    ACTOR_RAGDOLL_SOLID = 1,
    ACTOR_RAGDOLL_FAILED = 3
};

enum actorAttachmentAction_t : int {
    ACTOR_ATTACHMENT_HIDE = 0,
    ACTOR_ATTACHMENT_SHOW = 1,
    ACTOR_ATTACHMENT_DETACH = 2,
    ACTOR_ATTACHMENT_REATTACH = 3
};

struct idRagdollInfo {
    int velocityTime = 0;
    float slomoStart = 0.0f;
    float slomoEnd = 0.0f;
    float jointFrictionDent = 0.0f;
    float jointFrictionStart = 0.0f;
    float jointFrictionEnd = 0.0f;
    float contactFrictionDent = 0.0f;
    float contactFrictionStart = 0.0f;
    float contactFrictionEnd = 0.0f;
};

struct idActorSounds {
    const idSoundShader* sndPainSmall = nullptr;
    const idSoundShader* sndPainMedium = nullptr;
    const idSoundShader* sndPainLarge = nullptr;
    const idSoundShader* sndPainHuge = nullptr;
    const idSoundShader* sndFootsteps = nullptr;
    const idSoundShader* sndFoliage = nullptr;
};

struct idDamageGroup {
    idStr groupName;
    float damageScale = 1.0f;
    float locationArmor = 0.0f;
    float armoredDamageScale = 0.0f;
    const idDeclEntityDef* spawnEntity = nullptr;
    const idDeclParticle* spawnParticle = nullptr;
    const idSoundShader* spawnSound = nullptr;
    idList<idStr, 5> hideMeshes{0};
    float forwardRunIndex = 0.0f;
    float injuredIdleIndex = 0.0f;
    idStr tagName;
    int fxTagID = -1;
    bool forceInjured = false;
    float maxHealth = 0.0f;
    float health = 0.0f;
    bool affectsOverallHealth = true;
    idMat3 lastHitAxis{1.0f};
    int currentGoreLevel = 0;
};

struct idInventoryAttachmentDef {
    enum startingSlot_t : int {
        NOT_EQUIPPED = 0,
        EQUIPPED = 1,
        HOLSTERED = 2
    };

    const idDeclInventory* inventoryDecl = nullptr;
    int count = 1;
    startingSlot_t startSlot = NOT_EQUIPPED;
    bool showHolstered = true;
    bool forSale = false;
    bool lootable = true;
};

struct idEntityAttachmentDef {
    const idDeclEntityDef* entityDef = nullptr;
    idStr tag;
};

struct takedownTypes_t {
    idList<idStr, 5> stealthSWFWD{0};
    idList<idStr, 5> stealthSWREV{0};
    idList<idStr, 5> stealthDWFWD{0};
    idList<idStr, 5> stealthDWREV{0};
    idList<idStr, 5> counterSWFWD{0};
    idList<idStr, 5> counterSWREV{0};
    idList<idStr, 5> counterDWFWD{0};
    idList<idStr, 5> counterDWREV{0};
    idList<idStr, 5> AITakedowns{0};
};

struct idActorItemInfo {
    const char* name = "";
    const char* internalName = "";
    equipSlot_t equipSlot = EQUIP_NONE;
    equipSlot_t holsterSlot = EQUIP_NONE;
    const idDeclEntityDef* entityDef = nullptr;
    const idSoundShader* dropSound = nullptr;
    const idDeclAiEvent* dropEventDecl = nullptr;
    int count = 1;
    int numHands = 0;
    int burstMode = 3;
    bool dropable = false;
    bool noAttachment = false;
    bool stackable = false;
    bool initiallyHidden = false;
    bool lootable = false;
};

struct idActorPhysicsState {
    idVec3 origin{0.0f, 0.0f, 0.0f};
    idMat3 axis{1.0f};
    idVec3 gravityNormal{0.0f, 0.0f, -1.0f};
    idVec3 linearVelocity{0.0f, 0.0f, 0.0f};
    idBounds absBounds{};
    bool hasGroundContacts = false;
    float waterLevel = 0.0f;
};

struct idActorFootstepContact {
    idVec3 point{0.0f, 0.0f, 0.0f};
    idVec3 normal{0.0f, 0.0f, -1.0f};
    int surfaceType = 0;
    bool valid = false;
};

struct idActorDropRequest {
    idInventoryItem* item = nullptr;
    const idDeclEntityDef* entityDef = nullptr;
    idVec3 offset{0.0f, 0.0f, 0.0f};
    idVec3 velocity{0.0f, 0.0f, 0.0f};
    bool dropToGround = false;
    bool fromAttachment = false;
};

class idActorServices {
public:
    virtual ~idActorServices() = default;

    virtual void SetActorVisible(idActor&, bool) {}
    virtual void ProjectActorOverlay(idActor&, const idVec3&,
        const idVec3&, float, const char*) {}
    virtual void UpdateBaseAttachments(idActor&) {}
    virtual idActorPhysicsState GetPhysicsState(const idActor&) const {
        return {};
    }
    virtual void SetPhysicsOrigin(idActor&, const idVec3&) {}
    virtual void SetPhysicsVelocity(idActor&, const idVec3&) {}
    virtual bool HasActorPhysics(const idActor&) const { return true; }
    virtual void UpdateVisuals(idActor&) {}
    virtual void ForceAwake(idActor&, int) {}
    virtual void KillBox(idActor&) {}

    virtual const idAASPosition& GetAASPosition(
        const idActor&, const idAAS2*) const;
    virtual idWeapon* CastWeapon(idInventoryItem*) const { return nullptr; }
    virtual equipSlot_t GetWeaponSlot(const idActor&) const {
        return EQUIP_RIGHT_HAND;
    }
    virtual idVehicle* GetBoundVehicle(const idActor&) const {
        return nullptr;
    }
    virtual idActor* GetVehicleDriver(const idVehicle*) const {
        return nullptr;
    }

    virtual int GetInventoryCountByName(const idActor&, const char*) const {
        return 0;
    }
    virtual int GetInventoryItemCount(const idInventoryItem*) const {
        return 0;
    }
    virtual int GetNumInventoryItems(const idActor&) const { return 0; }
    virtual idInventoryItem* GetInventoryItem(const idActor&, int) const {
        return nullptr;
    }
    virtual idInventoryItem* FindInventoryItem(
        const idActor&, const idDeclInventory*) const { return nullptr; }
    virtual idInventoryItem* GiveInventoryItem(idActor&,
        const idDeclInventory*, int) { return nullptr; }
    virtual void DeleteInventoryItem(idActor&, idInventoryItem*, int) {}
    virtual void FreeInventory(idActor&) {}
    virtual void BaseInventoryRemoved(idActor&, idInventoryItem*) {}
    virtual idActorItemInfo GetItemInfo(const idInventoryItem*) const {
        return {};
    }
    virtual idActorItemInfo GetDeclInfo(const idDeclInventory*) const {
        return {};
    }
    virtual const idDeclInventory* FindInventoryDecl(const char*) const {
        return nullptr;
    }
    virtual void SetInventoryFlags(idInventoryItem*, bool, bool) {}
    virtual bool IsItemAlreadyDropped(const idInventoryItem*) const {
        return false;
    }
    virtual void SetItemAlreadyDropped(idInventoryItem*, bool) {}
    virtual void OnItemEquipped(idActor&, idInventoryItem*) {}
    virtual void OnItemUnequipped(idActor&, idInventoryItem*) {}

    virtual void AddItemAttachment(idActor&, idInventoryItem*,
        equipSlot_t) {}
    virtual bool HasItemAttachment(const idActor&, idInventoryItem*) const {
        return false;
    }
    virtual void RemoveItemAttachment(idActor&, idInventoryItem*) {}
    virtual void ActOnItemAttachment(idActor&, idInventoryItem*,
        actorAttachmentAction_t) {}
    virtual void RemoveEntityAttachment(idActor&, const idEntity*) {}
    virtual void AddModelAttachment(idActor&, const idDeclMD6*,
        const char*) {}
    virtual void RemoveModelAttachment(idActor&, const idDeclMD6*) {}
    virtual void AddEntityAttachment(idActor&, idEntity*, const char*) {}
    virtual idEntity* FindEntity(const char*) const { return nullptr; }
    virtual idTreeAnimator* GetItemAttachmentAnimator(
        const idActor&, idInventoryItem*) const { return nullptr; }
    virtual idFXManager* GetAttachmentFXManager(
        idActor&, idInventoryItem*) { return nullptr; }
    virtual bool GetAnimatorTag(idTreeAnimator*, const char*, tagData_t&,
        idVec3&) const { return false; }
    virtual void SetAllAttachmentsVisible(idActor&, bool) {}
    virtual void DeleteAttachedEntities(idActor&) {}

    virtual bool IsDead(const idActor&) const { return false; }
    virtual float GetHealth(const idActor&) const { return 0.0f; }
    virtual float GetMaxHealth(const idActor&) const { return 0.0f; }
    virtual void IncreaseHealth(idActor&, float) {}
    virtual void DecreaseHealth(idActor&, float) {}
    virtual void SetHealth(idActor&, float) {}
    virtual void RepairShield(idActor&, float) {}
    virtual void DamageFeedback(idActor&, idEntity*, idEntity*,
        const idDeclDamage*, float) {}

    virtual idPresentable* AllocActorPresentable(
        idActor&, idRenderModel*) { return nullptr; }
    virtual bool GetRagdollModelTransform(
        const idActor&, idVec3&, idMat3&) const { return false; }
    virtual bool GetRagdollSoundTransform(
        const idActor&, idVec3&, idMat3&) const { return false; }
    virtual bool GetSoundJointTransform(
        const idActor&, idVec3&, idMat3&) const { return false; }
    virtual bool GetAnimatedModelOrigin(
        const idActor&, idVec3&) const { return false; }
    virtual idMat3 GetPresentableAxis(const idActor&) const {
        return idMat3(1.0f);
    }
    virtual idVec3 GetScale(const idActor&) const {
        return idVec3(1.0f, 1.0f, 1.0f);
    }
    virtual bool UseStandingEyeOffsetWhenCrouched(
        const idActor&) const { return false; }
    virtual bool GetBindMasterAimPoint(
        const idActor&, aimPoint_t, idVec3&) const { return false; }

    virtual actorRagdollResult_t StartRagdoll(
        idActor&, const idRagdollInfo&) { return ACTOR_RAGDOLL_FAILED; }
    virtual bool IsRagdollActive(const idActor&) const { return false; }
    virtual void StopRagdoll(idActor&) {}
    virtual void InitActorModel(idActor&, idRenderModel*) {}

    virtual const char* GetJointGroupName(const idActor&,
        int, idActorJointIndex) const { return nullptr; }
    virtual const char* GetJointGroupNameForHandle(const idActor&,
        const idJointGroupHandle&) const { return nullptr; }
    virtual idJointGroupHandle GetJointGroupHandle(const idActor&,
        int, idActorJointIndex) const { return {}; }

    virtual int GetGameMilliseconds() const { return 0; }
    virtual int GetGameMillisecondsPerFrame() const { return 16; }
    virtual float RandomFloat() { return 0.0f; }
    virtual void EmitWaterParticle(idActor&, const idDeclParticle*,
        const idVec3&, float) {}
    virtual const idDeclParticle* GetWaterParticleForSpeed(
        const idActor&, bool) const { return nullptr; }

    virtual bool IsServer() const { return true; }
    virtual bool IsMultiplayer() const { return false; }
    virtual bool IsCoopChallenge() const { return false; }
    virtual bool AllowLootingInCoop() const { return false; }
    virtual bool AllowWeaponDropInCoop() const { return false; }
    virtual void ClearLootHighlight(idActor&) {}
    virtual void UpdatePostureClip(idActor&, bool) {}
    virtual float GetAIFovDot(const idActor&) const { return 0.0f; }
    virtual std::uint8_t FovDotToByte(float) const { return 0; }

    virtual void SetWalkIKEnabled(idActor&, bool) {}
    virtual void SetLegIKEnabled(idActor&, int, bool) {}
    virtual void BlendTwoLegIK(idActor&, bool, int) {}
    virtual int GetWeaponBurstMode(const idWeapon*) const { return 3; }

    virtual bool HasGroundContacts(const idActor&) const { return false; }
    virtual const idDeclAiEvent* GetFootstepEvent(
        const idActor&, footStepType_t, walkState_t, posture_t) const {
        return nullptr;
    }
    virtual const idDeclProjectileImpactEffect* GetFootstepEffects(
        const idActor&, footStepType_t, walkState_t, posture_t) const {
        return nullptr;
    }
    virtual void EmitAIEvent(idActor&, const idDeclAiEvent*,
        idEntity*, int) {}
    virtual idActorFootstepContact GetFootstepContact(
        const idActor&, footStepType_t) const { return {}; }
    virtual void PlayFootstepImpact(idActor&,
        const idDeclProjectileImpactEffect*, const idActorFootstepContact&,
        footStepType_t) {}

    virtual int GetSpawnId(const idEntity*) const { return 0x1FFF; }
    virtual idEntity* ResolveEntity(int) const { return nullptr; }
    virtual bool ApplyCrushDamage(idActor&, int) { return false; }
    virtual idEntity* SpawnDroppedEntity(
        idActor&, const idActorDropRequest&) { return nullptr; }
    virtual bool PlaceDroppedEntity(idActor&, idEntity*,
        const idActorDropRequest&) { return true; }
    virtual void RemoveEntity(idEntity*) {}
    virtual void PlayDropFailureSound(idActor&) {}
    virtual void PlayItemDropSound(idActor&, const idSoundShader*) {}
    virtual void ConfigureDroppedEntity(idActor&, idEntity*,
        idInventoryItem*, bool) {}
    virtual void ScheduleDroppedItemDelete(idActor&, equipSlot_t) {}
    virtual bool HasLootableProjectile(const idActor&) const {
        return false;
    }

    virtual void RegisterActor(idActor&) {}
    virtual bool HasAnimatedModel(const idActor&) const { return true; }
    virtual void SetRadiusDamageJoints(idActor&,
        const idList<idStr, 5>&) {}
    virtual void InitializeActorAnimation(idActor&) {}
    virtual int FindSoundJoint(const idActor&, const char*) const {
        return -1;
    }
    virtual void SetHighQualityShadows(idActor&) {}
    virtual void AddDeclEntityAttachment(idActor&,
        const idEntityAttachmentDef&) {}
    virtual void InitDeferredVisibility(idActor&, const idVec3&) {}
    virtual void AddBehaviorAnimations(const idList<idStr, 5>&) {}
    virtual void PostActorSpawn(idActor&) {}
    virtual void StopAllSounds(idActor&) {}
    virtual void FreeAttachments(idActor&) {}
};

class idActor {
public:
    struct idActorModel {
        idStr soundJoint;
        idVec3 modelOffset{0.0f, 0.0f, 0.0f};
    };
    struct idActorPerception {
        idVec3 eyeOffset{0.0f, 0.0f, 0.0f};
        idVec3 crouchedEyeOffset{0.0f, 0.0f, 0.0f};
    };
    struct waterInteraction_t {
        const idDeclParticle* waterPrtSlow = nullptr;
        const idDeclParticle* waterPrtFast = nullptr;
        const idDeclParticle* waterPrtSplash = nullptr;
        float moveSpeedSlow = 150.0f;
        float emissionRate = 0.5f;
    };
    struct idActorConstant {
        idActorModel modelInfo;
        idActorPerception perception;
        idActorSounds actorSounds;
        bool useCombatBox = false;
        const idDeclProjectileImpactEffect* footstepEffectTable_Sprint = nullptr;
        const idDeclProjectileImpactEffect* footstepEffectTable = nullptr;
        const idDeclProjectileImpactEffect* footstepEffectTable_SlowWalk = nullptr;
        const idDeclProjectileImpactEffect* footstepEffectTable_CrouchWalk = nullptr;
        const idDeclProjectileImpactEffect* footstepEffectTable_Landing = nullptr;
        const idDeclFootstepEvents* footstepEvents = nullptr;
        waterInteraction_t waterInteraction;
        actorClass_t actorClass = ACTORCLASS_MAX;
        float aimAssistRadiusOverrideScale = 1.0f;
    };
    struct idActorEditable {
        posture_t bodyState = POSTURE_STANDING;
        standState_t standState = STANDSTATE_DEFAULT;
        sitState_t sitState = SITSTATE_DEFAULT;
        turnState_t turnState = TURNSTATE_DEFAULT;
        mentalState_t mentalState = MENTALSTATE_AWAKE;
        bool forceBodyState = false;
        bool isInteracting = false;
        idList<idDamageGroup, 5> damageGroups{0};
        idList<idStr, 5> radiusDamageJoints{0};
    };
    struct idActorModelCache {
        idMat3 modelAxis{1.0f};
        idMat3 eyeAxis{1.0f};
        idVec3 eyePos{0.0f, 0.0f, 0.0f};
        idActorJointIndex soundJoint;
    };
    struct idPainInfo {
        idJointGroupHandle jointGroupHandle;
        idEntityPtr<const idEntity> attacker;
        idEntityPtr<const idEntity> inflictor;
        idActorJointIndex joint;
        painType_t type = PAIN_NONE;
        damageDirection_t direction = DAMAGEDIR_NONE;
        damageIntensity_t intensity = DAMAGEINTENSITY_NONE;
        const idDeclDamage* damageDecl = nullptr;
    };
    struct idActorVolatile {
        idActorModelCache modelInfo;
        idPainInfo pain;
        walkState_t walkState = WALKSTATE_WALKING;
        leanState_t leanState = LEAN_NONE;
        weaponReadyState_t weaponReadyState = WEAPONREADY_LOWERED;
        bool onStairs = false;
        int postureChangeTime = -10000;
        float damageTakenMultiplier = 1.0f;
        idAASPosition aasPosition{};
    };

    idActor();
    virtual ~idActor();

    static void SetServices(idActorServices* services);
    static idActorServices& Services();

    void Hide();
    void Show();
    void ProjectOverlay(const idVec3& origin, const idVec3& dir,
        float size, const char* material);
    void UpdateAttachments();
    int GetAreaNum(const idAAS2* aas) const;
    const idAASPosition& GetAASPosition(const idAAS2* aas) const;
    idWeapon* GetEquippedWeapon(equipSlot_t slot) const;
    idWeapon* GetEquippedWeapon() const;
    void InventoryRemoved(idInventoryItem* item);
    void DropAttachment(equipSlot_t slot);
    idInventoryItem* GetEquipped(equipSlot_t slot) const;
    void ClearEquipped(equipSlot_t slot);
    void ClearEquipped(idInventoryItem* item);
    void SetFaction(const idDeclFaction* factionDecl);
    bool IsCrouching() const;
    bool IsSitting() const;
    idVehicle* GetVehicle();
    const idVehicle* GetVehicle() const;
    bool IsDrivingVehicle() const;
    eventBool Event_ItemInInventory(const char* internalName, float count);
    eventInt Event_NumOfItemTypeInInventory(const char* declName);
    eventString Event_CurrentNPC() const;
    eventBool Event_IsDead() const;
    eventFloat Event_GetWalkState() const;
    eventFloat Event_GetWeaponReadyState() const;
    idDisassembleLoot* GetDisassembleLoot();
    eventVoid Event_PostSpawn();
    bool CanBeHealed() const;
    void SetAxis(const idMat3& axis);
    int GetDefaultSurfaceType() const;
    idPresentable* AllocPresentable(idRenderModel* renderModel);
    void GetModelTransform(idVec3& origin, idMat3& axis) const;
    void GetSoundTransform(idVec3& origin, idMat3& axis) const;
    idVec3 GetEyeOffset() const;
    void GetViewTransform(idVec3& origin, idMat3& axis) const;
    void GetEyePos(idVec3& eyePos) const;
    void GetAimPoint(aimPoint_t type, idVec3& pos) const;
    actorRagdollResult_t StartRagdoll(const idRagdollInfo& info);
    void StopRagdoll();
    void Teleport(const idVec3& origin, const idAngles& angles);
    int GetLastValidAreaNum(const idAAS2* aas) const;
    const idVec3& GetLastValidAASOrigin(const idAAS2* aas) const;
    const idVec3& GetAASOrigin(const idAAS2* aas) const;
    void DoLocationDamage(const idDeclDamage* damageDecl,
        idDamageGroup* damageGroup, float baseDamage,
        float& outBodyDamage, float& outLimbDamage,
        float& outArmorDamage, float& outArmorDamageScale,
        float& outArmoredHealthDamageScale,
        float& outBleedThroughDamage, float& outExcessDamage,
        idDeclDamage::damageType_t damageTypes);
    idDamageGroup* GetDamageGroup(idActorJointIndex joint);
    idJointGroupHandle GetDamageGroupHandle(idActorJointIndex joint) const;
    idDamageGroup* GetDamageGroup(const idJointGroupHandle& handle);
    idDamageGroup* GetDamageGroup(const char* groupName);
    idJointGroupHandle GetPainGroupHandle(idActorJointIndex joint) const;
    idJointGroupHandle GetDeathGroupHandle(idActorJointIndex joint) const;
    static damageDirection_t GetDamageDirection(const idMat3& axis,
        const idVec3& direction, int numDirections);
    damageIntensity_t GetDamageIntensity(
        const idDeclDamage* damageDef, float damage) const;
    void ApplyWaterEffects(int physicsId, int id);
    idTreeAnimator* GetEquippedWeaponAnimator();
    bool GetMeleeTagData(const char* tagName, tagData_t& tag,
        idVec3& origin, bool& useWeaponAnimator);
    bool IsEquippedWeaponOneHanded() const;
    bool EquipItem(idInventoryItem* item, equipSlot_t slot);
    void ShowAttachment(idInventoryItem* item);
    void HideAttachment(idInventoryItem* item);
    eventVoid Event_UnequipAndDeleteDroppedItem(equipSlot_t slot);
    idFXManager* GetFXMgrForAttachment(idInventoryItem* item);
    void RepairShield(float value);
    bool HolsterItem(idInventoryItem* item, bool showHolstered);
    bool UnequipItem(idInventoryItem* item);
    void SetLooted(bool value);
    bool HasLootableItems() const;
    idFaction* GetFaction();
    const idFaction* GetFaction() const;
    void UpdateTempFaction();
    posture_t GetPosture() const { return actorEditable.bodyState; }
    void SetPosture(posture_t state);
    walkState_t GetWalkState() const { return actorVolatile.walkState; }
    weaponReadyState_t GetWeaponReadyState() const {
        return actorVolatile.weaponReadyState;
    }
    void DamageFeedback(idEntity* victim, idEntity* inflictor,
        const idDeclDamage* damageDef, float& damage);
    void GetViewStateFOV(idVec3& forward, std::uint8_t& horizontal,
        std::uint8_t& vertical) const;
    eventVoid Event_SetPosture(posture_t posture);
    eventBool Event_NeedsHealth() const;
    eventVoid Event_IncreaseHealth(float amount);
    eventVoid Event_DecreaseHealth(float amount);
    eventVoid Event_SetHealth(float health);
    eventVoid Event_EnableWalkIK();
    eventVoid Event_DisableWalkIK();
    eventVoid Event_EnableLegIK(int leg);
    eventVoid Event_DisableLegIK(int leg);
    eventVoid Event_RemoveAllInventoryItems();
    eventVoid Event_HideAttachment(const char* slotName);
    eventVoid Event_ShowAttachment(const char* slotName);
    eventVoid Event_RemoveAttachment(const idEntity* entity);
    eventFloat Event_WeaponBurstMode(int slot) const;
    eventVoid AnimEvent_StartRagdoll(const idMD6Anim*, int velocityTime,
        int slomoStartTime, int slomoEndTime);
    eventVoid AnimEvent_HideAttachment(const idMD6Anim*, const char* slot);
    eventVoid AnimEvent_ShowAttachment(const idMD6Anim*, const char* slot);
    eventVoid AnimEvent_DetachAttachment(const idMD6Anim*, const char* slot);
    eventVoid AnimEvent_ReattachAttachment(const idMD6Anim*, const char* slot);
    eventVoid AnimEvent_HideModel(const idMD6Anim*, const idDeclMD6* model);
    eventVoid AnimEvent_ShowModel(const idMD6Anim*, const idDeclMD6* model,
        const char* tag);
    eventVoid AnimEvent_AttachEntity(const idMD6Anim*,
        const char* entityName, const char* tagName);
    eventVoid AnimEvent_DetachEntity(const idMD6Anim*,
        const char* entityName);
    eventVoid AnimEvent_DisableTwoLegIKBlend(const idMD6Anim*);
    eventVoid AnimEvent_EnableTwoLegIKBlend(const idMD6Anim*);
    eventVoid AnimEvent_ModifyDamageGroupScale(const idMD6Anim*,
        const char* damageGroupName, float scale);
    void SetModel(idRenderModel* model);
    float GetDamageForJoint(idActorJointIndex joint);
    idEntity* GetAttachedLoot() const;
    eventVoid Event_GiveInventoryItem(const char* declName, float count);
    eventVoid Event_RemoveInventoryItem(const char* declName, float count);
    void DeleteSubEntities();
    idEntity* DropItem(idInventoryItem* item, bool dropToGround,
        bool deleteOnDrop, int count, const idVec3& offset,
        const idVec3& velocity);
    bool HasLootableProjectiles() const;
    void SetAttachedLoot(idEntity* object);
    void SetPain(painType_t type, idActorJointIndex joint,
        const idEntity* attacker, const idEntity* inflictor,
        const idJointGroupHandle& jointGroup, damageDirection_t direction,
        damageIntensity_t intensity, const idDeclDamage* damageDecl);
    void ClearPain();
    bool PlayFootStepEffect(footStepType_t footstepType);
    eventVoid AnimEvent_LeftFoot(const idMD6Anim*);
    eventVoid AnimEvent_RightFoot(const idMD6Anim*);
    eventVoid AnimEvent_LeftRearFoot(const idMD6Anim*);
    eventVoid AnimEvent_RightRearFoot(const idMD6Anim*);
    void Spawn();
    bool IsLootable() const;
    void DropAttachment(idInventoryItem* item);
    void SetRelationshipList(const idRelationshipList& relationships);

    idStr name;
    int entityNumber;
    bool looted;
    idEntityPtr<idEntity> droppedItem1;
    idEntityPtr<idEntity> droppedItem2;
    idEntityPtr<idEntity> attachedLoot;
    bool spawnPending;
    idRagdollInfo ragdollInfo;
    idActorConstant actorConstants;
    idActorEditable actorEditable;
    idStr npcName;
    idFaction faction;
    const idDeclFaction* tempFaction;
    int tempFactionTime;
    factionType_t factionType;
    float weaponProficiency;
    float armorProficiency;
    float shieldBleedThrough;
    float mass;
    bool lootable;
    bool dropRandomLoot;
    idList<idInventoryAttachmentDef, 5> startingInventory;
    idList<idEntityAttachmentDef, 5> entityAttachments;
    idDisassembleLoot disassembleLoot;
    takedownTypes_t takedownTypes;
    idActorVolatile actorVolatile;
    const idDeclWalkIK* walkIKDecl;
    idInventoryItem* equipped[EQUIP_MAX];
    int damageGroup;
    idList<idEntityPtr<idEntity>, 5> touching;

private:
    eventVoid AttachmentEvent(const char* slotName,
        actorAttachmentAction_t action, const char* source);
};

class idActorPhysicsCallbacks {
public:
    idActorPhysicsCallbacks() : owner(nullptr), ent(), af(nullptr) {}
    bool Crush(int physicsId);

    idActor* owner;
    idEntityPtr<idEntity> ent;
    void* af;
};

void StringListAddIfUnique(const idList<idStr, 5>& listToAdd,
    idList<idStr, 5>& addToList);
