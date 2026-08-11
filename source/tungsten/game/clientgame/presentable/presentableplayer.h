#pragma once

#include "presentable.h"
#include "../../../../engine/framework/usercmdgen.h"
#include "../../../../shared/idlib/langdict.h"
#include "../../../../shared/idlib/math/interpolate.h"

#include <cstdint>

class idDeclOnlineScoringCallout;
class idActor;
class idCmdArgs;
class idInventoryItem;
class idDeclEnv;
class idDeclDamage;
class idDeclTutorialEvent;
class idDeclWeapon;
class idDeclPlayerProps;
class idVoiceTrack;
class idRenderModelGui;
class idSWF;
class idWeapon;
class idSoundShader;
struct sysEvent_t;
struct lobbyUserID_t;
struct idHudInfo;

struct decayParams_s {
    float linear{0.0f};
    float quadratic{0.0f};
    float maximum{0.0f};
};

enum playerScopeGuiNum_t : int {
    PLAYER_SCOPE_NONE = 0
};

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

struct localView_t {
    localView_t() : initialized(false) {}
    bool initialized;
};

class idPresentableActorServices {
public:
    virtual ~idPresentableActorServices() = default;
    virtual void PostSerializeRead(idPresentableActor&, bool) {}
    virtual void Think(idPresentableActor&) {}
    virtual void SerializeModifiers(idPresentableActor&, idSerializer&) {}
    virtual void UpdatePhysicsTime(idPresentableActor&, int) {}
    virtual void HandleModifierMessage(idPresentableActor&,
        std::uint32_t, std::uint8_t) {}
    virtual float GetSpeedModifier(const idPresentableActor&) const {
        return 1.0f;
    }
    virtual float GetDamageModifier(const idPresentableActor&) const {
        return 1.0f;
    }
    virtual bool IsOverdriveDisabled(const idPresentableActor&) const {
        return false;
    }
    virtual idActor* GetActorEntity(const idPresentableActor& actor) const {
        return reinterpret_cast<idActor*>(actor.entity);
    }
    virtual idWeapon* GetEquippedWeapon(const idPresentableActor&,
        equipSlot_t) const { return nullptr; }
    virtual idWeapon* GetEquippedWeapon(const idPresentableActor&) const {
        return nullptr;
    }
    virtual idWeapon* FindFiredInventoryWeapon(const idPresentableActor&,
        const idDeclWeapon*) const { return nullptr; }
    virtual idWeapon* GetControlledFiredWeapon(idPresentable*,
        const idDeclWeapon*) const { return nullptr; }
};

void Tungsten_SetPresentableActorServices(idPresentableActorServices* services);

class idPresentablePlayerServices {
public:
    virtual ~idPresentablePlayerServices() = default;
    virtual bool HasLocalPresentablePlayer() const { return false; }
    virtual const idSoundShader* GetScoringCalloutSound(
        const idDeclOnlineScoringCallout*) const { return nullptr; }
    virtual int GetScoringCalloutPriority(
        const idDeclOnlineScoringCallout*) const { return 0; }
    virtual bool IsClient() const { return false; }
    virtual bool IsLocallyControlled(const idPresentablePlayer&) const {
        return false;
    }
    virtual const idSoundShader* GetLootSound(bool) const { return nullptr; }
    virtual void InitializeLocalView(localView_t&) {}
    virtual bool HandleGuiEvent(void*, const sysEvent_t*) { return false; }
    virtual void Print(const char*) {}
    virtual idPresentablePlayer* FindPlayer(int) const { return nullptr; }
    virtual bool GetSubtitleForLanguage(int, int, bool&) const {
        return false;
    }
    virtual const char* GetLanguageIsoName(int) const { return ""; }
    virtual bool SetSubtitleForLanguage(int, int, bool) { return false; }
    virtual void GetSerializedView(idPresentablePlayer&, idVec3&,
        idMat3&) const {}
    virtual void SyncHands(idPresentablePlayer&) {}
    virtual int GetScaledGameTime() const { return 0; }
    virtual void UpdateFocus(idPresentablePlayer&, const idVec3&,
        const idMat3&) {}
    virtual int GetInventoryWeaponCount(const idPresentablePlayer&) const {
        return 0;
    }
    virtual idWeapon* GetInventoryWeapon(const idPresentablePlayer&,
        int) const { return nullptr; }
    virtual float GetWeaponSelectionPriority(const idWeapon*) const {
        return -1.0f;
    }
    virtual bool WeaponIsUsable(const idPresentablePlayer&,
        const idWeapon*) const { return false; }
    virtual idWeapon* FindInventoryWeapon(const idPresentablePlayer&,
        const char*) const { return nullptr; }
    virtual equipSlot_t GetWeaponEquipSlot(const idWeapon*) const {
        return EQUIP_NONE;
    }
    virtual void SelectHandsWeapon(idPresentablePlayer&, equipSlot_t,
        idWeapon*, bool) {}
    virtual void DeleteCurrentHandsWeapon(idPresentablePlayer&) {}
    virtual void GetPlayerPhysicsTransform(const idPresentablePlayer&,
        idVec3&, idMat3&) const {}
    virtual float RandomUnitFloat() { return 0.0f; }
    virtual void StartScreenParticleModel(idRenderModel*, const idVec3&,
        const idMat3&, float, int, int) {}
    virtual void UpdateScreenParticleModel(idRenderModel*, const idVec3&,
        const idMat3&, float) {}
    virtual bool IsScreenParticleModelUnlinked(idRenderModel*) const {
        return false;
    }
    virtual void UnlinkScreenParticleModel(idRenderModel*) {}
    virtual void EnableInfluenceTrail(idPresentablePlayer&) {}
    virtual void GetViewTransform(const idPresentablePlayer&,
        idVec3& origin, idMat3& axis) const {
        origin.Set(0.0f, 0.0f, 0.0f);
        axis = idMat3(1.0f);
    }
    virtual float GetScreenParticleOffset() const { return 0.0f; }
    virtual void ForceScopeZoomBlur(idPresentablePlayer&, float, float,
        float) {}
    virtual idWeapon* GetControlWeapon(const idPresentablePlayer&) const {
        return nullptr;
    }
    virtual bool WeaponHasActiveScope(const idWeapon*) const { return false; }
    virtual playerScopeGuiNum_t GetWeaponScopeGuiNum(
        const idWeapon*) const { return PLAYER_SCOPE_NONE; }
    virtual bool ItemClosesInventoryOnUse(const idInventoryItem*) const {
        return false;
    }
    virtual bool ItemIsRemovedOnUse(const idInventoryItem*) const {
        return false;
    }
    virtual bool IsServer() const { return false; }
    virtual void ForceCloseInventory(idPresentablePlayer&) {}
    virtual void DeleteInventoryItem(idPresentablePlayer&,
        idInventoryItem*, int) {}
    virtual void PlayCannotUseItemSound(idPresentablePlayer&) {}
    virtual bool HandsContainItem(const idPresentablePlayer&,
        equipSlot_t, const idInventoryItem*) const { return false; }
    virtual void DetachHandsItem(idPresentablePlayer&, equipSlot_t) {}
    virtual void NotifyInventoryRemoved(idPresentablePlayer&,
        idInventoryItem*) {}
    virtual bool AllowUninhibitedCommands(
        const idPresentablePlayer&) const { return false; }
    virtual bool IsInContextualShimmy(
        const idPresentablePlayer&) const { return false; }
    virtual bool IsInWallClimb(
        const idPresentablePlayer&) const { return false; }
    virtual bool IsInSprintSlide(
        const idPresentablePlayer&) const { return false; }
    virtual bool IsInTakedown(
        const idPresentablePlayer&) const { return false; }
    virtual bool ShouldHideWeapon(
        const idPresentablePlayer&) const { return false; }
    virtual void GetLeanHandsOffsetScale(const idPresentablePlayer&,
        idVec2& scale) const { scale.Set(0.0f, 0.0f); }
    virtual void EnterRestrictedHud(idPresentablePlayer&) {}
    virtual void RestoreRestrictedHud(idPresentablePlayer&) {}
    virtual void SetHudRestrictedGameplay(idPresentablePlayer&, bool) {}
    virtual void PrepareChallengeRestart(idPresentablePlayer&) {}
    virtual void InitializeBuildGameView(idPresentablePlayer&,
        localView_t&) {}
    virtual void RegisterSWFResources(const char*) {}
    virtual idSWF* CreatePlayerGui(idPresentablePlayer&, int,
        const char*, bool, bool) { return nullptr; }
    virtual void DestroyPlayerGui(idSWF*) {}
    virtual bool GuiIsActive(const idSWF*) const { return false; }
    virtual void SetGuiPausedRender(idSWF*, bool) {}
    virtual bool ShouldDrawGuis() const { return false; }
    virtual bool IsMainMenuActive() const { return false; }
    virtual void RenderSubtitleGui(idSWF*, idRenderModelGui*, int) {}
    virtual void GetLobbyUserID(const idPresentablePlayer&,
        lobbyUserID_t&) const {}
    virtual void SetLobbyUserID(idPresentablePlayer&,
        const lobbyUserID_t&) {}
    virtual const char* GetPlayerModelName(
        const idPresentablePlayer&) const { return "NULL"; }
    virtual int GetPlayerViewID(const idPresentablePlayer&) const {
        return -1;
    }
    virtual void GetPlayerViewPosition(const idPresentablePlayer&,
        idVec3& origin, idMat3& axis) const {
        origin.Zero();
        axis = idMat3(1.0f);
    }
    virtual void SetCameraShake(idPresentablePlayer&, float) {}
    virtual void SetControllerShake(idPresentablePlayer&, float, float,
        float, float) {}
    virtual void SetEnvironmentOverride(idPresentablePlayer&,
        const idDeclEnv*, float) {}
    virtual void SetEnvironmentParm(idPresentablePlayer&,
        const idDeclRenderParm*, const idVec4&, float) {}
    virtual void ClearEnvironmentParm(idPresentablePlayer&,
        const idDeclRenderParm*, float) {}
    virtual void AddRadialBlur(idPresentablePlayer&, const idVec3&,
        float, float, float, float, float) {}
    virtual int GetPlayerGameTime() const { return GetScaledGameTime(); }
    virtual float RandomCenteredFloat() { return 0.0f; }
    virtual void InitializeClientHands(idPresentablePlayer&) {}
    virtual void SetHandsViewID(idPresentablePlayer&, int) {}
    virtual void ShowAndEnableHands(idPresentablePlayer&) {}
    virtual void HideHands(idPresentablePlayer&) {}
    virtual void PostSerializeInventory(idPresentablePlayer&) {}
    virtual void RestoreSerializedPlayerState(idPresentablePlayer&) {}
    virtual void PresentableRespawn(idPresentablePlayer&, bool) {}
    virtual void ResetViewShake(idPresentablePlayer&) {}
    virtual void PlayRoverBombSelfDestructSound(idPresentablePlayer&) {}
    virtual void UpdateHud(idPresentablePlayer&) {}
    virtual void NotifyServerInventoryAdded(idPresentablePlayer&,
        idInventoryItem*, int) {}
    virtual void ShowInventoryPickup(idPresentablePlayer&,
        idInventoryItem*, int) {}
    virtual void ActivateGui(idSWF*, bool) {}
    virtual bool IsAmmoItem(const idInventoryItem*) const { return false; }
    virtual void SelectAmmoItem(idPresentablePlayer&, idInventoryItem*) {}
    virtual bool IsThrowableItem(const idInventoryItem*) const {
        return false;
    }
    virtual bool CanThrowItem(const idPresentablePlayer&,
        const idInventoryItem*) const { return false; }
    virtual bool UniqueProjectileAllowed(const idPresentablePlayer&,
        const idInventoryItem*) const { return false; }
    virtual bool DeployableAllowed(const idPresentablePlayer&,
        const idInventoryItem*) const { return false; }
    virtual void ThrowItem(idPresentablePlayer&, idInventoryItem*) {}
    virtual bool InfiniteAmmo() const { return false; }
    virtual bool PermanentInfiniteAmmo() const { return false; }
    virtual bool CookItemPending(const idPresentablePlayer&) const {
        return false;
    }
    virtual bool ServerUseItem(idPresentablePlayer&, idInventoryItem*) {
        return false;
    }
    virtual void RestoreFailedServerItemCount(idPresentablePlayer&,
        idInventoryItem*) {}
    virtual void ReplicateCannotUseItem(idPresentablePlayer&) {}
    virtual bool ClientUseItem(idPresentablePlayer&, idInventoryItem*) {
        return false;
    }
    virtual void SendQuickUseMessage(idPresentablePlayer&,
        idInventoryItem*) {}
    virtual int GetClientUseThrottleTime() const { return 0; }
    virtual void PrepareChallengeExit(idPresentablePlayer&) {}
    virtual bool ShouldRestartChallenge(
        const idPresentablePlayer&) const { return false; }
    virtual void FinalizeChallengeRestart(idPresentablePlayer&) {}
    virtual bool CanStartSubtitle(const idPresentablePlayer&,
        const idVoiceTrack*, const idPresentable*) const { return false; }
    virtual const char* GetSubtitleText(const idVoiceTrack*) const {
        return nullptr;
    }
    virtual int GetSubtitleDurationMS(const idVoiceTrack*) const { return 0; }
    virtual void StartSubtitle(idPresentablePlayer&, const char*, float) {}
    virtual void BindSideMissionCallbacks(idPresentablePlayer&, idSWF*) {}
    virtual bool ResumeMap(idPresentablePlayer&) { return false; }
    virtual bool GoToMission(idPresentablePlayer&) { return false; }
    virtual void ClearPlayerGuiModel(idPresentablePlayer&) {}
    virtual void UpdatePlayerHudInfo(idPresentablePlayer&, idHudInfo&) {}
    virtual bool DrawControlledPresentable(idPresentable*,
        idPresentablePlayer&) { return false; }
    virtual void DrawSharedPlayer(idPresentablePlayer&) {}
    virtual bool IsPlayerDead(const idPresentablePlayer&) const {
        return false;
    }
    virtual void RenderDeadPlayerView(idPresentablePlayer&) {}
    virtual void RestoreSerializedViewPosition(idPresentablePlayer&,
        const idVec3&, const idMat3&) {}
    virtual void ProcessPlayerInput(idPresentablePlayer&, bool) {}
    virtual void UpdatePlayerHands(idPresentablePlayer&) {}
    virtual void PredictPlayerTriggers(idPresentablePlayer&) {}
    virtual void UpdateOutlineModel(idRenderModel*, bool,
        const idVec4&) {}
    virtual bool UseFriendlyOutlineColor(
        const idPresentablePlayer&) const { return false; }
    virtual bool SerializeControlledVehiclePrediction(idPresentable*,
        idSerializer&) { return false; }
    virtual void SerializePlayerPhysicsPrediction(idPresentablePlayer&,
        idSerializer&) {}
    virtual void SerializeControlledVehicleNonPrediction(idPresentable*,
        idSerializer&) {}
    virtual void SerializePlayerPhysicsNonPrediction(idPresentablePlayer&,
        idSerializer&) {}
    virtual int GetClientGameFrame() const { return 0; }
    virtual idVec3 GetPlayerPhysicsOrigin(
        const idPresentablePlayer&) const { return idVec3(); }
    virtual float GetControlledVehicleSpeed(idPresentable*) const {
        return 0.0f;
    }
    virtual bool IsPlayerCrouching(const idPresentablePlayer&) const {
        return false;
    }
    virtual bool IsPlayerFullyZoomed(const idPresentablePlayer&) const {
        return false;
    }
    virtual bool IsPlayerControlInhibited(
        const idPresentablePlayer&) const { return false; }
    virtual void GetControlledCameraInhibit(idPresentable*, int&,
        int&) const {}
    virtual bool IsDualWielding(const idPresentablePlayer&) const {
        return false;
    }
    virtual bool UseAimAssist() const { return true; }
    virtual bool IsMultiplayer() const { return false; }
    virtual int GetScaledMSPerFrame() const { return 0; }
    virtual bool ControlIsStaticWeapon(idPresentable*) const {
        return false;
    }
    virtual void AttachController(idPresentable*, idPresentablePlayer&,
        std::uint32_t) {}
    virtual bool ControllerIsAttachedTo(idPresentable*,
        const idPresentablePlayer&) const { return false; }
    virtual void ReleaseController(idPresentable*) {}
    virtual std::uint32_t GetPresentableSpawnId(idPresentable* presentable)
        const { return presentable != nullptr ? presentable->spawnId : 0; }
    virtual idPresentable* ResolveControlledPresentable(
        std::uint32_t) const { return nullptr; }
    virtual bool ShouldSerializeInventory() const { return true; }
    virtual void SerializePlayerInventory(idPresentablePlayer&,
        idSerializer&) {}
    virtual bool HasOfficialSnapshot(const idPresentablePlayer&) const {
        return false;
    }
    virtual void SerializePlayerDeclaration(idSerializer& serializer,
        const void*& declaration) {
        (void)serializer;
        (void)declaration;
    }
    virtual void ShutdownPlayer(idPresentablePlayer&) {}
    virtual bool CanShowTutorial(const idPresentablePlayer&,
        const idDeclTutorialEvent*) const { return false; }
    virtual void ConfigureTutorialGui(idPresentablePlayer&,
        const idDeclTutorialEvent*, idEntity*, idSWF*) {}
    virtual void ScheduleTutorialEnd(idPresentablePlayer&,
        const idDeclTutorialEvent*) {}
    virtual bool HandleTutorialDeactivate(idPresentablePlayer&,
        const idDeclTutorialEvent*, idEntity*) { return false; }
    virtual bool HandleTutorialInput(idPresentablePlayer&,
        const idDeclTutorialEvent*, idEntity*, int) { return false; }
    virtual void PrepareGeneralCardGui(idPresentablePlayer&, idSWF*) {}
    virtual void PrepareInventoryGui(idPresentablePlayer&, idSWF*) {}
    virtual void SetGuiListener(idSWF*, int) {}
    virtual void RenderPlayerGui(idPresentablePlayer&, idSWF*, int) {}
    virtual bool CanRenderGeneralGui(idPresentablePlayer&, idSWF*) {
        return true;
    }
    virtual const char* UpdateSubtitleSequencer(idPresentablePlayer&,
        float) { return nullptr; }
    virtual void SetSubtitleText(idSWF*, const char*) {}
    virtual void SetPlayerClipEnabled(idPresentablePlayer&, bool) {}
    virtual void UpdateHandsHidden(idPresentablePlayer&) {}
    virtual void UpdateNonPredictiveClip(idPresentablePlayer&) {}
    virtual void UpdateClientHudState(idPresentablePlayer&) {}
    virtual void ThinkPlayerHud(idPresentablePlayer&) {}
    virtual void UpdatePlayerAnimation(idPresentablePlayer&, int, float) {}
    virtual void UpdatePlayerSound(idPresentablePlayer&) {}
    virtual void UpdatePlayerDamageFeedback(idPresentablePlayer&) {}
    virtual void UpdatePlayerDamageDealt(idPresentablePlayer&) {}
    virtual void UpdatePlayerWoundDecal(idPresentablePlayer&) {}
    virtual void DrawPlayerHands(idPresentablePlayer&) {}
    virtual void UpdatePlayerInfluence(idPresentablePlayer&, int) {}
    virtual bool ShouldRecordPlayerMove(
        const idPresentablePlayer&) const { return false; }
    virtual idAngles GetPlayerViewAnglesForRecord(
        const idPresentablePlayer&) const { return idAngles(); }
    virtual void ProcessSerializedDamageFeedback(idPresentablePlayer&,
        int) {}
    virtual void SyncPlayerPauseState(idPresentablePlayer&) {}
    virtual void ThinkPlayerActorModifiers(idPresentablePlayer&) {}
    virtual idWeapon* GetPendingQuickWeapon(const idPresentablePlayer&,
        int) const { return nullptr; }
    virtual bool ReloadHand(idPresentablePlayer&, equipSlot_t,
        bool) { return false; }
    virtual int GetPlayerPeerIndex(const idPresentablePlayer&) const {
        return -1;
    }
    virtual idRenderModel* CreatePlayerOutlineModel(idPresentablePlayer&) {
        return nullptr;
    }
    virtual void RespawnPlayerSystems(idPresentablePlayer&, bool) {}
    virtual void StartPerfectPlayerOrigin(idPresentablePlayer&,
        const idVec3&, int) {}
    virtual bool WeaponSupportsZoomLevels(const idWeapon*) const {
        return false;
    }
    virtual int GetWeaponZoomLevel(const idWeapon*) const { return 0; }
    virtual int GetWeaponZoomLevelCount(const idWeapon*) const { return 0; }
    virtual void SetWeaponZoomLevel(idWeapon*, int) {}
    virtual float GetWeaponZoomedFov(const idWeapon*) const {
        return 90.0f;
    }
    virtual float GetWeaponZoomFov(const idWeapon*, int) const {
        return 90.0f;
    }
    virtual int GetWeaponZoomTime(const idWeapon*) const { return 0; }
    virtual int GetWeaponChangeZoomLevelTime(const idWeapon*) const {
        return 0;
    }
    virtual float GetOriginErrorDecayRate() const { return 0.0f; }
    virtual float GetOriginErrorMaximumDecay() const { return 0.0f; }
    virtual float GetDefaultFov() const { return 90.0f; }
    virtual bool ConsumeFovModified() { return false; }
    virtual int GetWeaponCycleSlot(const idWeapon*) const { return 0; }
    virtual bool WeaponCanCycle(const idPresentablePlayer&,
        const idWeapon*, bool) const { return false; }
    virtual void PrepareWeaponForCycleSelection(idWeapon*) {}
    virtual idWeapon* GetPreviousEquippedWeapon(
        const idPresentablePlayer&) const { return nullptr; }
    virtual bool WeaponHasUsableAmmo(const idPresentablePlayer&,
        const idWeapon*) const { return false; }
    virtual int GetWeaponQuickSlot(const idWeapon*) const { return -1; }
    virtual idWeapon* GetQuickWeapon(const idPresentablePlayer&,
        int) const { return nullptr; }
    virtual const idDeclAmmo* GetNextAmmoDeclaration(
        const idPresentablePlayer&, const idWeapon*) const {
        return nullptr;
    }
    virtual void UpdateAmmoStatus(idPresentablePlayer&, bool) {}
    virtual const idDeclAmmo* GetQuickAmmoDeclaration(
        const idPresentablePlayer&, const idWeapon*, int) const {
        return nullptr;
    }
    virtual bool IsQuickAmmoAvailable(const idPresentablePlayer&,
        const idWeapon*, const idDeclAmmo*) const { return false; }
    virtual void PlayBadButtonSound(idPresentablePlayer&) {}
    virtual void ClearHudPickupItems(idPresentablePlayer&) {}
    virtual bool UseThirdPersonSoundOrigin() const { return false; }
    virtual void PredictCollisionTriggers(idPresentablePlayer&) {}
};

void Tungsten_SetPresentablePlayerServices(
    idPresentablePlayerServices* services);
idPresentablePlayerServices* Tungsten_GetPresentablePlayerServices();

class idUCmdInhibit {
public:
    enum inhibitFlags_t : int {
        UCMD_INHIBIT_NONE = 0x000,
        UCMD_INHIBIT_MOVEMENT_FWD = 0x001,
        UCMD_INHIBIT_MOVEMENT_RT = 0x002,
        UCMD_INHIBIT_MOVEMENT_UP = 0x004,
        UCMD_INHIBIT_VIEW = 0x008,
        UCMD_INHIBIT_BUTTONS = 0x010,
        UCMD_INHIBIT_MOVEMENT_ONCE = 0x020,
        UCMD_INHIBIT_VIEW_ONCE = 0x040,
        UCMD_INHIBIT_BUTTONS_ONCE = 0x080,
        UCMD_INHIBIT_VIEW_DISCARD = 0x100,
        UCMD_INHIBIT_MOVEMENT = 0x007,
        UCMD_INHIBIT_ALL = 0x01F,
        UCMD_INHIBIT_ALL_ONCE = 0x0E0
    };

    idUCmdInhibit()
        : minForward(-127), maxForward(127)
        , minRight(-127), maxRight(127)
        , minUp(-127), maxUp(127)
        , buttons(0), flags(UCMD_INHIBIT_NONE), game(false) {}

    static void DebugPrintInhibitFlagNames(inhibitFlags_t flags);

    std::int8_t minForward;
    std::int8_t maxForward;
    std::int8_t minRight;
    std::int8_t maxRight;
    std::int8_t minUp;
    std::int8_t maxUp;
    int buttons;
    int flags;
    bool game;
};

class idWeaponKick {
public:
    idWeaponKick() = default;

    float GetOffset() const;
    void Init(const float& kick, const float& maximumKick,
        const float& inSpeed, const float& outSpeed, bool additiveKick,
        float recoveryDelay);

    idInterpolate<float> recoilOffset;
    idInterpolate<float> recoveryOffset;
};

struct idHudInfo {
    float armor{0.0f};
    bool combinerItemState[4]{};
};

class idUCmdTrackerServices {
public:
    virtual ~idUCmdTrackerServices() = default;
    virtual int GetScaledFrameTime() const { return 0; }
};

void Tungsten_SetUCmdTrackerServices(idUCmdTrackerServices* services);

class idUCmdTracker {
public:
    idUCmdTracker();

    void SetLastPlayerInputAngles(const std::int16_t angles[2]);
    bool GetAnglesMatchLastPlayerInputAngles(
        const std::int16_t angles[2]) const;
    void ClearAngles();
    void SetCmdAnglesToView();
    void SetViewAngles(const idAngles& angles);
    void ConstrainViewAngles(idAngles& angles);
    void SetViewAnglesConstraintExplicit(bool constrain,
        const idAngles& baseAngles, const idAngles& minDeltaAngles,
        const idAngles& maxDeltaAngles, float rate);
    void ResetPrevViewAngles();
    bool Update(const usercmd_t& newCommand, const idUCmdInhibit& inhibit);
    void Clamp180(idAngles& clamped) const;

    bool IsPressedForPlayer(int mask) const;
    bool WasReleasedForPlayer(int mask) const;
    bool WasPressedForPlayer(int mask) const;
    bool IsPressedForMenu(int mask) const;
    bool WasReleasedForMenu(int mask) const;

    int lastPlayerInputTime;
    std::int16_t lastPlayerInputAngles[2];
    usercmd_t prevcmd;
    usercmd_t usercmd;
    usercmd_t usercmdRaw;
    bool cmdInhibited;
    bool clearViewDeltaNextUpdate;
    idAngles deltaViewAngles;
    idAngles viewAngles;
    idAngles prevViewAngles;
    idAngles cmdAngles;
    bool constrainViewAngles;
    idAngles constrainedViewAnglesBase;
    idAngles constrainedViewAnglesMinDelta;
    idAngles constrainedViewAnglesMaxDelta;
    float constrainedViewAnglesRate;
};

class idPresentablePlayer : public idPresentableActor {
public:
    using idPresentable::SetSoundVolume;
    using idPresentable::StartSoundShader;
    using idPresentable::StopSound;

    enum playerGuis_t : int {
        GUI_DELIVERY = 0,
        GUI_JOBOFFER,
        GUI_JOBBOARD,
        GUI_MERCHANT,
        GUI_CLOTHING,
        GUI_RACES,
        GUI_JOB_DEBUG,
        GUI_PLAYTEST_DEBUG,
        GUI_GENERAL_GAME_USE,
        GUI_PLAYERGARAGE,
        GUI_TUNE_VEHICLE,
        GUI_TUNER_VEHICLE,
        GUI_INFO_BIG_NO_PIC,
        GUI_INFO_SMALL,
        GUI_INITIAL_ACTIVATE,
        GUI_SUBTITLE,
        GUI_INVENTORY,
        GUI_SIDEMISSION,
        GUI_VIEWNOTE,
        GUI_TOWTRUCK,
        GUI_TUTORIAL,
        GUI_COUNT
    };

    struct moveBufferItem_t {
        usercmd_t prevCmd;
        usercmd_t curCmd;
        idAngles viewAngles;
        int startTime{0};
        int endTime{0};
        idVec3 origin{0.0f, 0.0f, 0.0f};
        float speed{0.0f};
        std::uint8_t predictionBits{0};
    };

    struct clientFireInfo_t {
        std::uint16_t fireCount{0};
        std::int16_t fireAngles[2]{0, 0};
        std::int16_t firePos[3]{0, 0, 0};
    };

    struct coopCalloutItem_t {
        const idDeclOnlineScoringCallout* callout{nullptr};
        int scoreIndex{0};
    };

    struct coopScoreItem_t {
        idVec3 worldPosition{0.0f, 0.0f, 0.0f};
        int score{0};
        int time{0};
        int index{0};
    };

    struct screenParticleState_t {
        idRenderModel* pModel{nullptr};
        float excludeAngle{0.0f};
        int fadeStartTime{0};
        int fadeEndTime{0};
        bool isActive{false};
    };

    struct damageFeedback_t {
        std::uint32_t attackerSpawnId{0};
        const idDeclDamage* damageDefinition{nullptr};
        float damage{0.0f};
        idVec3 impactDirection{0.0f, 0.0f, 0.0f};
        idVec3 impactKick{0.0f, 0.0f, 0.0f};
        int impactOverrideTimer{0};
    };

    class idSWFScriptFunction_resumeMap {
    public:
        bool Call(int parameterCount);
        idPresentablePlayer* pThis{nullptr};
    };

    class idSWFScriptFunction_goToMission {
    public:
        bool Call(int parameterCount);
        idPresentablePlayer* pThis{nullptr};
    };

    class tutorialDeactivateCallback_t {
    public:
        bool Call();
        idPresentablePlayer* player{nullptr};
        const idDeclTutorialEvent* declaration{nullptr};
        idEntity* activatingEntity{nullptr};
    };

    class tutorialWaitInputCallback_t {
    public:
        bool Call(int keyNumber);
        idPresentablePlayer* player{nullptr};
        const idDeclTutorialEvent* declaration{nullptr};
        idEntity* activatingEntity{nullptr};
    };

    idPresentablePlayer();
    idPresentablePlayer(idPlayer* entity, idRenderModel* renderModel,
        idAnimStack* animStack, idInventoryCollection* inventory,
        const idDeclPlayerProps* properties, int entityNumber);
    ~idPresentablePlayer() override;

    presentableType_t GetType() const override { return PRESENTABLE_PLAYER; }
    idPresentablePlayer* GetPlayerInterface() override { return this; }
    void SetViewAnglesConstraintExplicit(bool constrain,
        const idAngles& baseAngles, const idAngles& minDeltaAngles,
        const idAngles& maxDeltaAngles, float rate);
    void SetViewAnglesConstraint(bool constrain, const idAngles& minAngles,
        const idAngles& maxAngles, float rate);
    void ExecuteCoopScoringCallout(
        const idDeclOnlineScoringCallout* callout);
    moveBufferItem_t& GetMoveBufferItemForClientGameFrame(int frame);
    void WriteFireDataToUserCmd(usercmd_t& command);
    bool IsInterpolated() const;
    bool IsLocallyControlled() const override;
    bool IsZoomedIn() const;
    idWeapon* GetPendingWeapon() const;
    void Reload();
    void ClearPendingAmmo();
    int StartSoundShader(soundChannel_t channel, const idSoundShader* shader,
        const soundShaderParms_t& parms, std::uint8_t peerMask);
    int StartSoundShader_Predicted(soundChannel_t channel,
        const idSoundShader* shader, int soundShaderFlags);
    void StopSound(soundChannel_t channel, std::uint8_t peerMask);
    void StopSound_Predicted(soundChannel_t channel);
    void SetSoundVolume(soundChannel_t channel, float volume,
        std::uint8_t peerMask);
    void PlayLocalSound(soundChannel_t channel,
        const idSoundShader* shader, int soundShaderFlags);
    const decayParams_s& GetDecayParams(bool crouch) const;
    idInventoryCollection* GetInventory();
    void DisplayDeathMessage();
    int GetPeerIndex();
    std::uint8_t GetPeerMaskForPrediction();
    void InitOutlineModel();
    void PresentableRespawn(bool initial);
    void StartPerfectOrigin(const idQuat& idealAxis,
        const idVec3& idealPosition, int lerpTimeMS);
    void ChangeCurrentZoomLevel();
    void SetCurrentZoomLevel(int zoomLevel);
    void DecayOriginError();
    idAngles GetViewAngles(bool includeWeaponKick) const;
    void SetLocalViewLimits(const idAngles& minimum,
        const idAngles& maximum);
    void ResetLocalViewLimits();
    float DefaultFov() const;
    float CalcFov(bool honorZoom) const;
    void CheckFovModified();
    idWeapon* GetWeaponClosestToSlot(bool forward, int currentSlot,
        bool requireAmmo);
    void SelectClosestWeapon(bool forward);
    void NextWeapon();
    void PrevWeapon();
    void EquipPrevEquippedWeapon();
    int NextQuickWeaponSlot() const;
    const idDeclAmmo* GetNextAmmoDecl() const;
    void ReleaseWeaponKickRecoveryDelay();
    void SetAmmoStatus(bool leftHand);
    void SelectQuickAmmo(int slot);
    void SelectQuickWeapon(int slot);
    void ClearPickupItems();
    void UpdateSound();
    void ClientPredictTriggers();
    void PlayLootSound(bool hasLoot);
    localView_t* GetLocalView();
    void ChallengeExit();
    void SetPlayerGuiFile(playerGuis_t gui, const char* filename,
        bool purgableImage);
    bool HandleGuiEvent(const sysEvent_t* event);
    void UpdateSerializedView();
    void ClientJobSync() override;
    void UpdateScoringCallout();
    void ClientUpdateFocusEntity();
    idWeapon* SelectBestWeapon();
    void SelectFists(bool deleteCurrentWeapon);
    void GetViewTransform(idVec3& outOrigin, idMat3& outAxis) const;
    void StartScreenParticle(unsigned int screenParticleType,
        float excludeAngle);
    void StopScreenParticle(unsigned int screenParticleType, int fadeTime);
    int StartFxScreenParticle(idRenderModel* particleModel,
        float excludeAngle);
    void StopFxScreenParticle(unsigned int handle, int fadeTime);
    void UpdateScreenParticles();
    void EnableInfluenceTrail();
    int GetUserCmdsForNetSend(usercmd_t** buffer, int bufferSize);
    void ScopeZoomBlur();
    playerScopeGuiNum_t GetScopeGuiNum() const;
    void RespondToUseItem(idInventoryItem* item, bool used);
    void InventoryRemoved(idInventoryItem* item);
    bool ClientCanUseItem(idInventoryItem* item);
    void SetServerOverridePos(bool teleport, int extra);
    idUCmdInhibit::inhibitFlags_t GetInhibitFlags(
        int& specificInhibitButtons);
    void SetInhibitFlags(idUCmdInhibit::inhibitFlags_t flags);
    void AddInhibitFlags(idUCmdInhibit::inhibitFlags_t flags);
    void ClearInhibitFlags(idUCmdInhibit::inhibitFlags_t flags);
    void SetRestrictedGamePlay(bool restricted, bool canRun);
    void SetInhibitRaiseWeapon(bool restricted);
    bool PlayerBehavior_ContextualShimmy_IsInShimmy() const;
    bool PlayerBehavior_WallClimb_IsInWallClimb() const;
    bool PlayerBehavior_SprintSlide_IsSliding() const;
    bool PlayerBehavior_Shared_ShouldHideWeapon() const;
    void PlayerBehavior_Lean_GetHandsOffsetScale(idVec2& scale) const;
    void ExitedVehicle();
    void ChallengeRestart();
    void NoteSwfForBuildGame();
    idSWF* GetPlayerGui(playerGuis_t gui);
    bool ClearPlayerGui(playerGuis_t gui);
    bool GuiIsActive(playerGuis_t gui) const;
    void SetGeneralGameGui(idSWF* gui);
    void DrawSubtitles(idRenderModelGui* guiModel);
    void ToggleShowLegendTitle(const idStrId& legendTitle);
    void GetLobbyUserID(lobbyUserID_t& result) const;
    void SetLobbyUserID(const lobbyUserID_t& value);
    void InitForClient();
    void SerializeHud(idSerializer& serializer, idHudInfo& info);
    void PostSerializeRead(bool firstClientFrame) override;
    void HudThink();
    void InventoryAdded(idInventoryItem* item, int count, bool canIntro);
    void ApplyDamageToPresentable(idPresentable* attacker,
        const idDeclDamage* damageDefinition, float damage,
        const idVec3& impactDirection, const idVec3& impactKick,
        int impactOverrideTimer);
    void HideTutorialGui();
    void HideSpecificTutorialGui(const idDeclTutorialEvent* declaration);
    void DeactivateGuis();
    idPresentable* GetControl() const;
    idPresentableVehicle* GetVehicle() const;
    bool UseItem(idInventoryItem* item);
    void ChallengeRestartRequest(bool restartChallenge, bool local);
    void SetupSubtitle(const idVoiceTrack* track,
        const idPresentable* source, const idStrId& whoStartedMeText);
    void InitSideMissions();
    bool Draw(idPresentablePlayer* player);
    void ClientPredict(int currentTime, float fraction) override;
    bool ShouldLinkPresentableCollision() override;
    void UpdateOutline();
    void SerializePredictionState(idSerializer& serializer);
    void SerializeNonPredictionState(idSerializer& serializer);
    void RecordMove(const usercmd_t& previousCommand,
        const usercmd_t& command, const idAngles& angles,
        int startTime, int endTime);
    void HandleUserCmds(const usercmd_t& newCommand);
    int GetPlayerGameTime();
    void AttachController(idPresentable* control);
    void DetachController(idPresentable* control);
    void Serialize(idSerializer& serializer) override;
    void RemoveControl(idPresentable* control);
    void ResetControl();
    bool ShowTutorialGui(const idDeclTutorialEvent* declaration,
        idEntity* activatingEntity);
    void DrawGuis(int listenerId);
    void ResetLocalViews();
    void AddControl(idPresentable* control);
    void UpdateSubtitles(int currentTime);
    void ClientThink(int currentTime, float fraction, bool predict) override;

    idUCmdTracker ucmdTracker1;
    idUCmdTracker ucmdTracker2;
    clientFireInfo_t clientFire;
    moveBufferItem_t moveBuffer[64];
    int lastRecordedMoveBufferIndex{0};
    localView_t localView;
    bool challengeLeavingSoon{false};
    bool challengeLocalRestart{false};
    bool challengeRemoteRestart{false};
    idStr guiNames[GUI_COUNT];
    bool purgableGuis[GUI_COUNT]{};
    void* loadedGuis[GUI_COUNT]{};
    int inhibitFlags{idUCmdInhibit::UCMD_INHIBIT_NONE};
    bool restrictedGamePlay{false};
    bool restrictedCanRun{false};
    bool allowWeaponChange{true};
    bool inhibitChangeWeapon{false};
    bool inhibitRaiseWeapon{false};
    int lastUsedTime{0};
    int serverOverridePositionTime{0};
    std::uint8_t teleportedCount{0};
    std::uint8_t teleportedLastCount{0};
    std::uint8_t respawnCount{0};
    std::uint8_t respawnLastCount{0};
    std::uint8_t vehicleExitedCount{0};
    std::uint8_t vehicleExitedLastCount{0};
    bool firstPredictionSerialize{false};
    idVec3 serializedOrigins[2];
    int roverBombSoundCounter{0};
    int localRoverBombSoundCounter{0};
    damageFeedback_t damageFeedback[10];
    int damageFeedbackBufferPos{0};
    const idDeclTutorialEvent* currentTutorialGuiDecl{nullptr};
    idList<idPresentable*, 5> controlledPresentables;
    idPresentable* groupMaster{nullptr};
    idRenderModel* outlineModel{nullptr};
    idHudInfo hudInfo;
    int clientPlayerInputFrame{0};
    bool isSprinting{false};
    bool isTurretControl{false};
    const idDeclPlayerProps* playerProps{nullptr};
    bool sentOfficialSnap{false};
    int serializeDamageFeedbackCount{0};
    bool wasPaused{false};
    bool zoomedIn{false};
    int pendingQuickWeapon{-1};
    const idDeclAmmo* pendingAmmo{nullptr};
    int nextAmmoChangeTime{0};
    int nextWeaponChangeTime{0};
    idInventoryCollection* activeInventory{nullptr};
    bool deathInfoShow{false};
    decayParams_s standingDecay;
    decayParams_s crouchingDecay;
    int respawnSerial{0};
    bool perfectOriginActive{false};
    idQuat perfectOriginRotation;
    int perfectOriginDuration{0};
    int perfectOriginStartTime{0};
    idInterpolate<float> zoomFov;
    idVec3 originError{0.0f, 0.0f, 0.0f};
    idAngles localMinViewAngles{-89.0f, -180.0f, 0.0f};
    idAngles localMaxViewAngles{89.0f, 180.0f, 0.0f};
    idAngles playerViewAngles{0.0f, 0.0f, 0.0f};
    idWeaponKick weaponKick[5];
    bool challengeRestartingSoon{false};
    bool disableSubtitles{false};
    int subtitleStartTime{-1};
    idSWFScriptFunction_resumeMap scriptFunction_resumeMap;
    idSWFScriptFunction_goToMission scriptFunction_goToMission;
    bool isGeneralGuiCardGame{false};
    bool renderLegendTitle{false};
    idStrId coopLegendTitle;
    idVec3 serializedViewOrigin{0.0f, 0.0f, 0.0f};
    idMat3 serializedViewAxis{1.0f};
    coopCalloutItem_t calloutHistory[4];
    int calloutHistoryIndex{0};
    int lastCalloutHistoryIndex{0};
    coopScoreItem_t coopScoreHistory[4];
    int coopScoringIndex{0};
    int lastCoopScoringIndex{0};
    idVec3 firstPersonViewOrigin{0.0f, 0.0f, 0.0f};
    idMat3 firstPersonViewAxis{1.0f};
    idList<screenParticleState_t, 5> screenPrtState;
    screenParticleState_t fxScreenPrtState[4];
};

class idPlayerViewCallbacks {
public:
    explicit idPlayerViewCallbacks(idPresentablePlayer* player = nullptr)
        : self(player) {}

    const char* GetName();
    int GetViewID() const;
    void GetPosition(idVec3& origin, idMat3& axis);
    void GetViewPosition(idVec3& origin, idMat3& axis);
    void ApplyScreenShake(float shakeMagnitude,
        const idAngles& shakeAngles, const idVec3& shakeOffsets);
    void ApplyControllerShake(float highDuration, float lowDuration,
        float highMagnitude, float lowMagnitude);
    void ApplyDynEnvOverride(const idDeclEnv* environment,
        float blendDuration);
    void ApplyDynEnvParmOverride(const idDeclRenderParm* parameter,
        const idVec4& value, bool clearParameter, float blendDuration);
    void ApplyRadialBlur(const idVec3& position, float startTime,
        float duration, float minimumBlur, float maximumBlur,
        float maximumScale);
    int AddScreenParticle(idRenderModel* particleModel, float excludeAngle);
    void RemoveScreenParticle(unsigned int handle, int fadeTime);

    idPresentablePlayer* self;
};

void p_printInhibitFlags_f(const idCmdArgs& args);
void p_clearInhibitFlags_f(const idCmdArgs& args);
void sub_status_f(const idCmdArgs& args);
void sub_set_f(const idCmdArgs& args);
