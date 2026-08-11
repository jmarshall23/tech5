#pragma once

#include "../clientgame_local.h"
#include "../../../../engine/network/serializer.h"
#include "../../../../shared/idlib/bv/bounds.h"
#include "../../../../shared/idlib/text/str.h"
#include "../../../../shared/idlib/langdict.h"

#include <cstdint>

class idClipModel;
class idCrosshairInfo;
class idAnimStack;
class idActor;
class idDeclAmmo;
class idDeclFX;
class idDeclRenderParm;
class idEntity;
class idInventoryCollection;
class idInventoryItem;
class idFocusTrace;
class idFXManager;
class idMaterial;
class idParmBlock;
class idPlayer;
class idPresentable;
class idPresentableAnimatedEntity;
class idPresentableMultiplayerTrigger;
class idPresentableParticleEmitter;
class idPresentablePieceEmitter;
class idPresentablePlayer;
class idPresentableProp;
class idPresentablePusher;
class idPresentableTurret;
class idPresentableVehicle;
class idPresentableWeapon;
class idPresentableWeaponStatic;
class idRenderModel;
class idTreeAnimator;
class idSoundEmitter;
class idWeapon;
class idDeclWeapon;

enum equipSlot_t : int;

enum fxCondition_t : int;
enum fxExtraCondition_t : int;

enum gameTeam_t : int {
    TEAM_NONE = -1,
    TEAM_0 = 0,
    TEAM_1 = 1
};

enum IFFN_t : int {
    IFFN_UNINITIALIZED = -1,
    IFFN_NEUTRAL = 0,
    IFFN_FRIEND = 1,
    IFFN_FOE = 2
};

enum presentableHighlightColor_t : int {
    PRESENTABLE_HIGHLIGHT_NONE = 0,
    PRESENTABLE_HIGHLIGHT_USE,
    PRESENTABLE_HIGHLIGHT_LOOT,
    PRESENTABLE_HIGHLIGHT_ITEM,
    PRESENTABLE_HIGHLIGHT_EXPLODE
};

enum usableState_t : int {
    USABLE_NOT_USABLE = 0,
    USABLE_DISABLED = 1,
    USABLE_LOOT = 2,
    USABLE_PROP = 3,
    USABLE_AI_TALK = 4,
    USABLE_AI_TOWN = 5,
    USABLE_AI_TAGGABLE = 6,
    USABLE_DOOR = 7,
    USABLE_MOVER = 8,
    USABLE_RC_PICKUP = 9,
    USABLE_VEHICLE_DRIVE = 10,
    USABLE_VEHICLE_GUNNER = 11,
    USABLE_DISASSEMBLE = 12,
    USABLE_AMMO_REFILL = 13,
    USABLE_MAX = 14
};

class idClipModelInfo {
public:
    enum clipModelType_t : int {
        CLIPMODEL_NONE = 0,
        CLIPMODEL_RENDERMODEL = 1,
        CLIPMODEL_CUSTOM = 2,
        CLIPMODEL_BOX = 3,
        CLIPMODEL_CYLINDER = 4,
        CLIPMODEL_CONE = 5,
        CLIPMODEL_BOUNDINGBOX = 6
    };

    idClipModelInfo();
    void Clear();

    clipModelType_t type;
    idVec3 size;
    idVec3 offset;
    int numSides;
    idStr clipModelName;
    bool clipShrink;
    bool allowInline;
    bool softObstacle;
    const idMaterial* overrideClipMaterial;
};

class idPresentableServices {
public:
    virtual ~idPresentableServices() = default;

    virtual void RemovePresentable(idPresentable*) {}
    virtual void DestroyPresentable(idPresentable* presentable);
    virtual void MarkSerialized(idPresentable*) {}
    virtual bool IsMultiplayer() const { return false; }
    virtual bool IsHost() const { return true; }
    virtual bool OptimizePresents() const { return true; }
    virtual int OptimizePresentCountdown() const { return 5; }
    virtual int GetScaledGameTime() const { return 0; }
    virtual int GetScaledFrameTime() const { return 0; }
    virtual int GetFrameNumber() const { return 0; }

    virtual void CommitRenderModel(idRenderModel*) {}
    virtual void MarkRenderModelForDelete(idRenderModel*) {}
    virtual bool IsRenderModelUnlinked(idRenderModel*) const { return false; }
    virtual void SetRenderModelUnlinked(idRenderModel*, bool) {}
    virtual const char* GetRenderModelName(idRenderModel*) const {
        return nullptr;
    }
    virtual idRenderModel* CreateRenderModel(const char*) { return nullptr; }
    virtual void GetRenderModelTransform(idRenderModel*, idVec3&, idMat3&,
        bool&) const {}
    virtual void GetRenderModelBounds(idRenderModel*, idBounds&) const {}
    virtual void SetRenderModelTransform(idRenderModel*, const idVec3&,
        const idMat3&) {}
    virtual int GetRenderModelIndex(idRenderModel*) const { return -1; }
    virtual void SetRenderModelGroupMasterIndex(idRenderModel*, int) {}
    virtual void SetRenderParm(idRenderModel*, const idDeclRenderParm*,
        float) {}
    virtual void SetRenderParm(idRenderModel*, const idDeclRenderParm*,
        const idVec3&) {}
    virtual void SetRenderParm(idRenderModel*, const idDeclRenderParm*,
        const idVec4&) {}
    virtual idParmBlock* GetParmBlock(idRenderModel*) { return nullptr; }
    virtual void SerializeRenderModel(idRenderModel*, idSerializer&, bool) {}

    virtual idClipModel* CreateMoveableClipModel(
        const idClipModelInfo&, idRenderModel*, const idVec3&, bool,
        float, const char*) { return nullptr; }
    virtual void DeleteClipModel(idClipModel*) {}
    virtual void SetClipModelContents(idClipModel*, int) {}
    virtual void EnableClipModel(idClipModel*, bool) {}
    virtual void LinkClipModel(idClipModel*, int, int, const idVec3&,
        const idMat3&) {}
    virtual void UnlinkClipModel(idClipModel*) {}
    virtual idBounds GetClipModelBounds(idClipModel*, bool) const {
        return idBounds();
    }

    virtual idSoundEmitter* AllocateSoundEmitter(const char*) {
        return nullptr;
    }
    virtual void FreeSoundEmitter(idSoundEmitter*, bool) {}
    virtual const idSoundShader* GetCurrentSoundShader(idSoundEmitter*,
        soundChannel_t) const { return nullptr; }
    virtual bool IsSoundPlaying(idSoundEmitter*, soundChannel_t) const {
        return false;
    }
    virtual void UpdateSoundEmitter(idSoundEmitter*, const idVec3&,
        const idMat3&, const idVec3&, int) {}
    virtual void FadeSound(idSoundEmitter*, soundChannel_t, float, float) {}
    virtual void FadePitch(idSoundEmitter*, soundChannel_t, float, float) {}
    virtual int StartSound(idSoundEmitter*, soundChannel_t,
        const idSoundShader*, const soundShaderParms_t&) { return 0; }
    virtual void SetSoundVolume(idSoundEmitter*, soundChannel_t, float) {}
    virtual void SetSoundPitch(idSoundEmitter*, soundChannel_t, float) {}
    virtual void ModifySound(idSoundEmitter*, soundChannel_t,
        const idSoundShader*, const soundShaderParms_t&) {}
    virtual void SetVolumeAdjustment(idSoundEmitter*, float) {}
    virtual void ClearVolumeAdjustment(idSoundEmitter*) {}
    virtual void StopSound(idSoundEmitter*, soundChannel_t) {}
    virtual void ReplicateSoundStart(idPresentable*, soundChannel_t,
        const idSoundShader*, const soundShaderParms_t&, std::uint8_t) {}
    virtual void ReplicateSoundVolume(idPresentable*, soundChannel_t, float,
        std::uint8_t) {}
    virtual void ReplicateSoundPitch(idPresentable*, soundChannel_t, float,
        std::uint8_t) {}
    virtual void ReplicateSoundModify(idPresentable*, soundChannel_t,
        const idSoundShader*, const soundShaderParms_t&, std::uint8_t) {}
    virtual void ReplicateVolumeAdjustment(idPresentable*, soundChannel_t,
        float, bool, std::uint8_t) {}
    virtual void ReplicateStopSound(idPresentable*, soundChannel_t,
        std::uint8_t) {}

    virtual void InitializeFX(idPresentable*, const idDeclFX*) {}
    virtual void ShutdownFX(idPresentable*) {}
    virtual void ResetFXAnimator(idPresentable*, idRenderModel*) {}
    virtual void StartFX(idPresentable*, fxCondition_t, fxExtraCondition_t,
        bool) {}
    virtual void StopFX(idPresentable*, fxCondition_t, fxExtraCondition_t,
        bool, bool) {}
    virtual void StopAllFX(idPresentable*, bool, bool) {}
    virtual void UpdateFX(idPresentable*, const idVec3&, const idMat3&,
        const idVec3&, float, float) {}
    virtual void SerializeFX(idPresentable*, idSerializer&) {}

    virtual int GetLocalPlayerTeam() const { return TEAM_NONE; }
    virtual bool PlayerIndexIsLocal(int) const { return false; }
    virtual void SetEntityLUT(int, int) {}
    virtual int GetEntityLUT(int) const { return -1; }
    virtual idBounds GetEntityBounds(idEntity*, int, bool) const {
        return idBounds();
    }
    virtual idPlayer* CastPlayer(idEntity*) const { return nullptr; }
    virtual bool EntityIsTargetLockable(idEntity*, const idDeclAmmo*) const {
        return false;
    }
    virtual usableState_t GetEntityUsableState(idEntity*,
        idPresentablePlayer*) const { return USABLE_NOT_USABLE; }
    virtual void SetCrosshairState(idCrosshairInfo*, int, bool, bool) {}

    virtual idPresentable* ResolvePresentable(std::uint32_t) const {
        return nullptr;
    }
    virtual bool GetJointWorldTransform(idPresentable*, int,
        const idVec3&, const idMat3&, idVec3&, idMat3&) const {
        return false;
    }
    virtual void SerializeDeclaration(idSerializer&, const void*&) {}
};

void Tungsten_SetPresentableServices(idPresentableServices* services);

class idPresentable {
public:
    static constexpr float DEFAULT_PRESENTABLE_RADIUS = 64.0f;
    static constexpr int ENTITYNUM_NONE = 0x1FFF;

    idPresentable();
    idPresentable(idEntity* entity, idRenderModel* renderModel,
        int entityNumber, const idDeclFX* fxDecl);
    virtual ~idPresentable();

    virtual void Shutdown();
    virtual void ClientJobSync() {}
    virtual void Present();
    virtual void Serialize(idSerializer& serializer);
    virtual void PostSerializeRead(bool firstClientFrame);
    virtual void Interpolate(int currentTime, float fraction);
    virtual void ClientPredict(int, float) {}
    virtual void ClientThink(int currentTime, float fraction, bool predict);
    virtual bool IsLocallyControlled() const { return false; }
    virtual void SerializeFX(idSerializer& serializer);
    virtual presentableType_t GetType() const { return PRESENTABLE_GENERIC; }
    virtual void SetRenderModel(idRenderModel* renderModel,
        bool inheritTransform);
    virtual bool ShouldSerializeRenderModelParms() const { return true; }
    virtual bool ShouldSerializeHidden() const { return true; }
    virtual bool ShouldInterpolate() const { return true; }
    virtual bool ShouldLinkPresentableCollision() { return !hidden; }
    virtual void Hide(bool stopFX);
    virtual void Show();
    virtual void GetWorldTransform(idVec3& outOrigin, idMat3& outAxis);
    virtual idBounds GetBounds(int bodyId) const;
    virtual idBounds GetAbsBounds(int bodyId) const;
    virtual bool IsTargetLockable(const idDeclAmmo* ammo) const;
    virtual void StartFX(fxCondition_t condition,
        fxExtraCondition_t extraCondition);
    virtual void StopAllFX();
    virtual void UpdateFX(const idVec3& origin, const idMat3& axis,
        float fovScale, float depthHack);
    virtual void LocalStartFX(fxCondition_t condition);
    virtual usableState_t GetOnlineUsableState(idPresentablePlayer* user,
        int clientGameFrame) const;
    virtual void GetOnlineModifiedCrosshairInfo(
        const idPresentable* activator, const idFocusTrace& trace,
        usableState_t usable, idCrosshairInfo& info);
    virtual void BecomeReplicated();
    virtual void InitFXMgr(const idDeclFX* declaration);
    virtual void ShutdownFXMgr();
    virtual void UpdateClientCollision(const idVec3& oldOrigin,
        const idMat3& oldAxis, const idVec3& newOrigin,
        const idMat3& newAxis);

    virtual idPresentableAnimatedEntity* GetAnimatedEntityInterface() {
        return nullptr;
    }
    virtual idPresentablePlayer* GetPlayerInterface() { return nullptr; }
    virtual idPresentableProp* GetPropInterface() { return nullptr; }
    virtual idPresentablePusher* GetPusherInterface() { return nullptr; }
    virtual idPresentableTurret* GetTurretInterface() { return nullptr; }
    virtual idPresentableVehicle* GetVehicleInterface() { return nullptr; }
    virtual idPresentableWeapon* GetWeaponInterface() { return nullptr; }
    virtual idPresentableWeaponStatic* GetWeaponStaticInterface() {
        return nullptr;
    }
    virtual idPresentableMultiplayerTrigger* GetMultiplayerTriggerInterface() {
        return nullptr;
    }
    virtual idPresentableParticleEmitter* GetParticleEmitterInterface() {
        return nullptr;
    }
    virtual idPresentablePieceEmitter* GetPieceEmitterInterface() {
        return nullptr;
    }
    virtual idStrId GetOnlineUsableText() const { return idStrId(); }

    void Delete();
    void SetClipModelContents(int contents);
    const idSoundShader* GetCurrentSoundShader(soundChannel_t channel) const;
    void FreeSoundEmitter(bool immediate);
    void SetLocalClipModelContents(int contents);
    void SetParm(const idDeclRenderParm* parm, float scalar);
    void SetParm(const idDeclRenderParm* parm, const idVec3& vector);
    void SetParm(const idDeclRenderParm* parm, const idVec4& vector);
    idParmBlock* GetParmBlock();
    void FreeRenderModel();
    void InheritPropertiesFromModel(bool inheritTransform);
    void UpdateModelTransform();
    void ClientOverrideClipContents(int contents);

    idSoundEmitter* GetSoundEmitter(bool allocate);
    void UpdateSound(const idVec3& soundOrigin, const idMat3& soundAxis,
        const idVec3& velocity, int listenerId);
    void UpdateSound();
    bool IsPlayingSound(soundChannel_t channel) const;
    void FadeSound(soundChannel_t channel, float to, float over);
    void FadePitch(soundChannel_t channel, float to, float over);
    int StartSoundShader(soundChannel_t channel, const idSoundShader* shader,
        const soundShaderParms_t& parms, std::uint8_t peerMask);
    int StartSoundShader(soundChannel_t channel, const idSoundShader* shader,
        int soundShaderFlags, std::uint8_t peerMask);
    void SetSoundVolume(soundChannel_t channel, float volume,
        std::uint8_t peerMask);
    void SetSoundPitch(soundChannel_t channel, float pitch,
        std::uint8_t peerMask);
    void ModifySound(soundChannel_t channel, const idSoundShader* shader,
        const soundShaderParms_t& parms, std::uint8_t peerMask);
    void SetVolumeAdjustment(soundChannel_t channel, float adjustment,
        std::uint8_t peerMask);
    void SetClearVolumeAdjustment(soundChannel_t channel,
        std::uint8_t peerMask);
    void StopSound(soundChannel_t channel, std::uint8_t peerMask);

    void ResetFXMgr(const idDeclFX* declaration);
    void InitFXMgr(const idDeclFX* declaration, idFXManager* manager);
    void ShutdownFXMgr(idFXManager* manager);
    void StopFX(fxCondition_t condition, fxExtraCondition_t extraCondition);
    void LocalStopFX(fxCondition_t condition);
    void LocalStopAllFX();
    void UpdateFX(float fovScale, float depthHack);

    int GetLocalPlayerTeamNumber() const;
    void IdentifyFriendFoeNeutral();
    void SetTeam(gameTeam_t newTeam);
    void SetOwnerPlayerIndex(int ownerIndex);
    static idClipModel* CreateMoveableClipModel(
        const idClipModelInfo& information, idRenderModel* renderModel,
        const idVec3& renderModelScale, bool barrelCollision,
        float overrideRadius, const char* debugName);
    void AddToEntityLUT();
    void RemoveFromEntityLUT();
    idPlayer* GetPlayerEntity() const;
    bool GetShouldPresent() const;
    void SetParent(idPresentable* parent, int joint);
    idPresentable* GetParent() const;
    void SetClipModelInfo(const idClipModelInfo& information,
        const idVec3& spawnPosition, const idMat3& spawnAxis);
    void SetClipModelInfo_DynamicRenderModel(const idVec3& spawnPosition,
        const idMat3& spawnAxis, int contents);
    void SetEntityNumber(int value);
    void UpdateModelGroupMaster();
    void GetWorldTransformInternal(const idVec3& inOrigin,
        const idMat3& inAxis, idVec3& outOrigin, idMat3& outAxis) const;
    void SetGroupMaster(idPresentable* presentable);

    std::uint32_t groupMasterSpawnId;
    idPresentable* groupMaster;
    bool clipModelDynamic;
    bool clipModelDynamicAxis;
    int clipModelPhysID;
    idVec3 origins[2];
    idMat3 axes[2];
    bool becameReplicated;
    idVec3 origin;
    idMat3 axis;
    idRenderModel* model;
    IFFN_t curIFF;
    bool hidden;
    int entityNumber;
    idClipModelInfo clipModelInfo;
    idVec3 clipModelSpawnPos;
    idMat3 clipModelSpawnAxis;
    idClipModel* clipModel;
    int clipModelContents;
    bool overridingClipContents;
    bool fxInitialized;
    const idDeclFX* fxDecl;
    idSoundEmitter* soundEmitter;
    std::uint32_t parentSpawnId;
    idPresentable* parent;
    int parentJoint;
    std::uint32_t controllerSpawnId;
    idPresentablePlayer* controller;
    int index;
    int activeIndex;
    int serializedIndex;
    const char* debugName;
    int serializeCount;
    idEntity* entity;
    std::uint32_t spawnId;
    float radius;
    std::uint32_t peerInRangeMask[2];
    int changedCount;
    int stopSerializeCount;
    bool clientThink;
    gameTeam_t team;
    int ownerPlayerIndex;
    int influenceHandle;
    std::uint8_t usablePlayerMask;
    usableState_t usableState;
    int lastUsedTime;
    presentableHighlightColor_t highlightColor;
    std::uint32_t predictedKey;
    bool entityNumAdded;
    std::uint64_t serverPermanentSoundChannels;
    bool hideDuringFirstSSInterval;
    bool queueForDelete;
    void* csInterface;
    std::uint32_t entityTypeFlags;
    bool shouldPresent;
    int shouldPresentCounter;
};

class idPresentableAnimatedEntityServices {
public:
    virtual ~idPresentableAnimatedEntityServices() = default;
    virtual idTreeAnimator* AsTreeAnimator(idRenderModel*) const {
        return nullptr;
    }
    virtual bool EntityHasClipModel(idEntity*) const { return true; }
    virtual idClipModel* CreateSphereModel(idTreeAnimator*, int) {
        return nullptr;
    }
    virtual void DeleteSphereModel(idClipModel*) {}
    virtual void UnlinkSphereModel(idClipModel*) {}
    virtual void LinkSphereModel(idClipModel*, int, const idVec3&,
        const idMat3&, bool) {}
    virtual void EnableSphereModel(idClipModel*, bool) {}
    virtual int GetSphereModelContents(idClipModel*) const { return 0; }
    virtual void SetSphereModelContents(idClipModel*, int) {}
    virtual void GetAnimatorTransform(idTreeAnimator*, idVec3& origin,
        idMat3& axis) const {
        origin.Zero();
        axis = idMat3(1.0f);
    }
    virtual idBounds GetAnimatorBounds(idTreeAnimator*) const {
        return idBounds();
    }
    virtual void SetAnimatorDeferred(idTreeAnimator*, bool) {}
    virtual void SyncAnimatorJoints(idTreeAnimator*, int) {}
    virtual bool GetTagTransform(idTreeAnimator*, const char*, const char*,
        idVec3&, idMat3&) const { return false; }
    virtual bool GetTagTransform(idTreeAnimator*, int, int,
        idVec3&, idMat3&) const { return false; }
    virtual idVec3 GetRenderModelBoundsCenter(idRenderModel*) const {
        return idVec3(0.0f, 0.0f, 0.0f);
    }

    virtual bool IsServer() const { return false; }
    virtual bool IsClient() const { return true; }
    virtual int GetServerGameTime() const { return 0; }
    virtual int GetScaledGameTime() const { return 0; }
    virtual int GetScaledFrameTime() const { return 0; }
    virtual int GetTicksPerSecond() const { return 0; }
    virtual idInventoryCollection* GetEntityInventory(idEntity*) const {
        return nullptr;
    }
    virtual void InventoryAdded(idEntity*, idInventoryItem*, int, bool) {}
    virtual idVec3 GetEntityEyePosition(idEntity*) const {
        return idVec3(0.0f, 0.0f, 0.0f);
    }
    virtual float GetEntityCurrentHealth(idEntity*) const { return 0.0f; }
    virtual float GetEntityMaximumHealth(idEntity*) const { return 0.0f; }
    virtual bool EntityCanAimAssist(idEntity*) const { return false; }
    virtual bool EntityIsTargetLockable(idEntity*, const idDeclAmmo*) const {
        return false;
    }
    virtual void AddAimAssistTarget(idPresentableAnimatedEntity*) {}
    virtual void RemoveAimAssistTarget(idPresentableAnimatedEntity*) {}

    virtual idTreeAnimator* GetAnimStackTreeAnimator(idAnimStack*) const {
        return nullptr;
    }
    virtual idAnimStack* CreateAnimStack(idTreeAnimator*) { return nullptr; }
    virtual void DestroyAnimStack(idAnimStack*) {}
    virtual void FreeSerializedAnimators(idAnimStack*) {}
    virtual void SerializeAnimStack(idAnimStack*, idSerializer&, int) {}
    virtual void BlendAnimStack(idAnimStack*, int, int, int, float) {}
    virtual void ResetFXTreeAnimator(idPresentableAnimatedEntity*,
        idTreeAnimator*) {}
};

void Tungsten_SetPresentableAnimatedEntityServices(
    idPresentableAnimatedEntityServices* services);

class idPresentableAnimatedEntity : public idPresentable {
public:
    idPresentableAnimatedEntity();
    idPresentableAnimatedEntity(idEntity* entity, idRenderModel* renderModel,
        idAnimStack* stack, int entityNumber, const idDeclFX* fx,
        bool useSphereModel = false);
    ~idPresentableAnimatedEntity() override;

    void Hide(bool stopFX) override;
    const idTreeAnimator* GetTreeAnimator() const;
    void Present() override;
    void UpdateClientCollision(const idVec3& oldOrigin,
        const idMat3& oldAxis, const idVec3& newOrigin,
        const idMat3& newAxis) override;
    void Show() override;
    void ClientJobSync() override;
    void SetRenderModel(idRenderModel* renderModel,
        bool inheritTransform) override;
    bool GetPresentableTagPosition(const char* propName,
        const char* tagName, idVec3& outOrigin, idMat3& outAxis) const;
    bool GetPresentableTagPosition(int propIndex, int tagIndex,
        idVec3& outOrigin, idMat3& outAxis) const;
    virtual const idInventoryCollection* GetInventory() const;
    virtual idInventoryCollection* GetInventory();
    virtual void InventoryAdded(idInventoryItem* item, int count,
        bool canIntro);
    void GetEyePos(idVec3& eyePosition) const;
    virtual float GetTotalCurHealth() const;
    virtual float GetTotalMaxHealth() const;
    bool GetCanAimAssist();
    bool IsTargetLockable(const idDeclAmmo* ammo) const override;
    void Serialize(idSerializer& serializer) override;
    void UpdateAnimation(int currentTime, float fraction);
    void ClientThink(int currentTime, float fraction, bool predict) override;
    void PostSerializeRead(bool firstClientFrame) override;
    void UpdateAimAssist();
    virtual bool ShouldEnableSphereCollision() const { return true; }

    presentableType_t GetType() const override {
        return PRESENTABLE_ANIMATED_ENTITY;
    }
    idPresentableAnimatedEntity* GetAnimatedEntityInterface() override {
        return this;
    }

    idAnimStack* animStack;
    bool useSphereModel;
    idClipModel* sphereModel;
    int sphereModelContents;
    bool createdAnimStack;
    idVec3 serializedEyePos;
    bool isAimAssistable;
    bool serializedAimAssist;
    float serializedTotalCurHealth;
    bool wasAddedToAimAssistList;
    float serializedTotalMaxHealth;
    idTreeAnimator* cachedAnimator;
};

class idPresentableActor : public idPresentableAnimatedEntity {
public:
    idPresentableActor();
    idPresentableActor(idEntity* entity, idRenderModel* renderModel,
        idAnimStack* stack, idInventoryCollection* actorInventory,
        int entityNumber, const idDeclFX* fx, bool sphereModel);
    ~idPresentableActor() override;

    void PostSerializeRead(bool firstClientFrame) override;
    void ClientThink(int currentTime, float fraction, bool predict) override;
    virtual void ServerThink(int currentTime);
    void Serialize(idSerializer& serializer) override;
    virtual void HandleActorModifierMessage(std::uint32_t uid,
        std::uint8_t modifierIndex);
    virtual float GetSpeedScale();
    virtual float GetDamageScale();
    virtual bool IsOverdriveDisabled();
    virtual idActor* GetActorEntity() const;
    virtual idWeapon* GetEquippedWeapon(equipSlot_t slot);
    virtual idWeapon* GetEquippedWeapon();
    virtual idWeapon* GetFiredWeapon(const idDeclWeapon* weaponDefinition);
    virtual void PostAlloc();

    idInventoryCollection* inventory;
    void* actorModifierManager;
    float overdrivePoints;
    std::uint32_t predictedModifierParentSpawnId{0};
};
