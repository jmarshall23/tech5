#pragma once

#include "presentable.h"
#include "presentableptr.h"

#include <cstdint>
#include <vector>

class idAnimator_VehicleCar;
class idCmdArgs;
class idDeclDamage;
class idDeclInventory;
class idDeclMaterial;
class idDeclParticle;
class idDeclProjectile;
class idDeclVehicleProps;
class idDeclWeapon;
struct idFireParms;
class idFinishFireResults;
class idPhysics;
class idPhysicsCallbacks;
class idPresentableVehicle;
class idTestFireResults;
class idThirdPersonCrosshair;
class idVehicle;
class idVehicleQuickItem;
class idVehicleWeapon;
class idView;

struct vehicleEffectsMaterials_t {
    const idDeclMaterial* metal{nullptr};
    const idDeclMaterial* stone{nullptr};
    const idDeclMaterial* wood{nullptr};
    const idDeclMaterial* cardboard{nullptr};
    const idDeclMaterial* liquid{nullptr};
    const idDeclMaterial* glass{nullptr};
    const idDeclMaterial* plastic{nullptr};
    const idDeclMaterial* asphalt{nullptr};
    const idDeclMaterial* dirt{nullptr};
    const idDeclMaterial* concrete{nullptr};
    const idDeclMaterial* foliage{nullptr};
    const idDeclMaterial* linoleum{nullptr};
    const idDeclMaterial* fabric{nullptr};
    const idDeclMaterial* rubber{nullptr};
    const idDeclMaterial* rock{nullptr};
};

struct vehicleCameraPlacement_t {
    float yaw{0.0f};
    float height{0.0f};
    float lateral{0.0f};
};

const idDeclMaterial* GetEffectsMaterial(
    const vehicleEffectsMaterials_t& materials, int surfaceType);
idVec3 Mat3DiffToAngularVelocity(const idMat3& from, const idMat3& to);
idVec3 ComputeCameraViewOrigin(const vehicleCameraPlacement_t& placement,
    const idVec3& targetOrigin, const idMat3& targetAxis, float range);

enum vehicleCollideResult_t : int {
    VEHICLE_COLLIDE_NONE = 0,
    VEHICLE_COLLIDE = 1
};

class idPresentableVehicleServices {
public:
    virtual ~idPresentableVehicleServices() = default;
    virtual void Event(idPresentableVehicle&, const char*) {}
    virtual bool EventBool(const idPresentableVehicle&, const char*,
        bool fallback = false) const { return fallback; }
    virtual int EventInt(const idPresentableVehicle&, const char*,
        int fallback = 0) const { return fallback; }
    virtual float EventFloat(const idPresentableVehicle&, const char*,
        float fallback = 0.0f) const { return fallback; }
    virtual void* EventPointer(const idPresentableVehicle&, const char*) const {
        return nullptr;
    }
    virtual idVec3 EventVector(const idPresentableVehicle&, const char*,
        const idVec3& fallback = idVec3(0.0f, 0.0f, 0.0f)) const {
        return fallback;
    }
    virtual idMat3 EventMatrix(const idPresentableVehicle&, const char*,
        const idMat3& fallback = idMat3(1.0f)) const { return fallback; }
    virtual void SerializeExtra(idPresentableVehicle&, idSerializer&,
        const char*) {}
};

void Tungsten_SetPresentableVehicleServices(
    idPresentableVehicleServices* services);

class idPresentableVehiclePhysicsCB {
public:
    explicit idPresentableVehiclePhysicsCB(idPresentableVehicle* owner = nullptr)
        : vehicle(owner) {}
    const char* GetName() const;
    bool GetMasterPosition(idVec3& origin, idMat3& axis) const;
    vehicleCollideResult_t Contact(int entityNumber, void* contactInfo);
    void ApplyImpulse(int entityNumber, int bodyId, const idVec3& point,
        const idVec3& impulse);
    void ApplyForce(int entityNumber, int bodyId, const idVec3& point,
        const idVec3& force);
    bool Crush(int entityNumber);
    void ApplyDamage(int entityNumber, int bodyId,
        const idDeclDamage* damage);
    void ActivatePhysics(int entityNumber);
    void DeactivatePhysics(int entityNumber);
    void ApplyWaterEffects(int entityNumber, int bodyId);
    void ApplyWaterSplashEffects(int entityNumber, int bodyId,
        int surfaceType, int splashState);
    vehicleCollideResult_t Collide(int entityNumber, trace_t& trace,
        const idVec3& velocity);
    idPresentableVehicle* vehicle;
};

class idPresentableVehicle : public idPresentableAnimatedEntity {
public:
    enum reverseBoostState_t : int {
        RBS_NONE = 0, RBS_PULLED = 1, RBS_RELEASED = 2, RBS_BOOSTING = 3
    };
    enum autoRollState_t : int {
        AUTOROLL_NONE = 0, AUTOROLL_PITCH = 1, AUTOROLL_ROLL = 2
    };
    enum wheelLoc_t : int {
        WHEEL_FRONT_LEFT = 0, WHEEL_FRONT_RIGHT = 1,
        WHEEL_REAR_LEFT = 2, WHEEL_REAR_RIGHT = 3
    };
    enum vehicleSeat_t : int { VEHICLE_SEAT_DRIVER = 0, VEHICLE_SEAT_GUNNER = 1 };
    enum vehicleWeaponAnimState_t : int {
        VEHICLE_WEAPON_IDLE = 0, VEHICLE_WEAPON_RAISE = 1,
        VEHICLE_WEAPON_LOWER = 2, VEHICLE_WEAPON_FIRE = 3
    };

    struct vehicleDamageInfo_t {
        const idDeclDamage* damageDef{nullptr};
        idVec3 damageDir{0.0f, 0.0f, 0.0f};
        idVec3 impactPoint{0.0f, 0.0f, 0.0f};
        float damageScale{0.0f};
        float damage{0.0f};
        float startHealth{0.0f};
        float endHealth{0.0f};
        int time{0};
        std::uint32_t attackerSpawnId{0};
        bool predicted{false};
    };

    idPresentableVehicle(idVehicle* entity, idRenderModel* renderModel,
        idAnimStack* animStack, idAnimator_VehicleCar* animator,
        const idDeclVehicleProps* properties,
        idPhysicsCallbacks* callbacks, int entityNumber);
    ~idPresentableVehicle() override;

    void Interpolate(int currentTime, float fraction) override;
    void Megaboost(float acceleration, int duration);
    int GetCurrentWeaponGroup() const;
    void* GetCrosshair();
    void DeactivateCrosshair();
    void WeaponFiredWithNoAmmo();
    void AddProjectileLock();
    void Present() override;
    void InitImpactMgr();
    void KillEngineSounds();
    void UpdateAirTime();
    bool InitVehicleBody();
    bool InitVehiclePhysics(idPhysicsCallbacks* callbacks);
    void UpdateCurrentThrottle(float target);
    void UpdateCurrentMPH();
    float GetBoostPower() const;
    float GetBoostDuration() const;
    void RechargeBoost(int elapsedMS);
    void ResetBoostPower();
    void BoostForce(float scale);
    float GetMaxSteerAngle(float speed) const;
    void RunPhysics();
    bool UseSteerControl();
    void PitchRollStabilize();
    void GetViewOriginAndAxis(idVec3& origin, idMat3& axis);
    void GetDriverView(idVec3& origin, idMat3& axis, float& fov,
        idView* view);
    void ResetDriverView();
    void AddQuickSlotItem(idInventoryItem* item, int slot);
    void SetCurQuickItem(int itemIndex);
    void RemoveQuickItemThink(idVehicleQuickItem* item);
    void QuickItemThink();
    void UpdateDriverViewAngles(const usercmd_t& oldCommand,
        const usercmd_t& command);
    void AdjustCg();
    void UpdateStickControl(float x, float y, bool absolute);
    void ResetBoostFOV();
    void StopBoost();
    void SetBoostDuration(float duration);
    float GetHealth() const;
    bool GetHasInfiniteAmmo() const;
    void PredictPickup();
    void RestoreDetachableItems();
    void GetInputSettings(idPresentablePlayer* player);
    void* GetPredictedFXMgr();
    void UpdateFX(float fovScale, float depthHack);
    void UpdateFX(const idVec3& origin, const idMat3& axis);
    void InitFXMgr(const idDeclFX* declaration) override;
    void ShutdownFXMgr() override;
    void StartPredictedFX(fxCondition_t condition,
        fxExtraCondition_t extraCondition);
    void StopPredictedFX(fxCondition_t condition,
        fxExtraCondition_t extraCondition);
    bool IsDead() const;
    void AddBoostUpSP(int amount);
    void AddJumpManSP();
    void DrawBirdsView(idPresentablePlayer* player);
    bool GetTagPosition(const char* propName, const char* tagName,
        idVec3& origin, idMat3& axis) const;
    void ClearDamageFX();
    void TransformDetachable(int index);
    void PredictHitScanHit(idPresentable* attacker, float damageScale,
        const idVec3& start, const idVec3& end,
        const idDeclProjectile* projectile, trace_t* trace);
    bool HasAlternateEngine() const;
    void OnHitByEMP();
    void RemoveProjectileLock();
    void UpdateSmash();
    void SerializePredictionOnly(idSerializer& serializer);
    void SerializeNonPredictionState(idSerializer& serializer);
    void HandleWheelDustTrail(wheelLoc_t wheel, const idVec3& origin,
        int surface, float speed, float compression);
    void HandleWheelDust(wheelLoc_t wheel, const idDeclParticle* particle,
        const idVec3& origin, int surface, float speed);
    void CheckRampLanding();
    void DropTireMark(bool left, const idVec3& origin, void* tireMark,
        float width, float alpha, float fade, const idVec3& normal,
        const void* material, float s0, float s1, float life,
        int wheel, int surface);
    idVehicleWeapon* GetWeaponForGroup(int group);
    void InventoryAdded(idInventoryItem* item, int count,
        bool canIntro) override;
    bool AddBoost(float amount);
    float GetMaxSpeed() const;
    void ArcadeSteering();
    void AutoRollOver();
    void CalcWheelsOnGround();
    void UpdateHorn(usercmd_t& oldCommand, usercmd_t& command);
    void StartBoostFX();
    void StopBoostFX();
    void ForceBoostFx(int duration);
    void SetBoostDisabled(bool disabled);
    bool GetUserCommand(vehicleSeat_t seat, usercmd_t* oldCommand,
        usercmd_t* command) const;
    void DeleteWeapons();
    void UpdateDetachableItems();
    bool WeaponGroupHasAmmo(int group);
    void ClearAllWeaponAnims();
    void SetCurrentWeapon();
    bool PlayWeaponGroupAnim(vehicleWeaponAnimState_t state);
    bool CheckInhibitFire(usercmd_t* command);
    const idDeclWeapon* GetWeaponDecl();
    void RecordClientDamageInfo(const idDeclDamage* damage,
        const idVec3& direction, const idVec3& point, float damageScale,
        float damageAmount, float startHealth, float endHealth,
        idPresentable* attacker, bool predicted);
    bool GetWeaponView(idVec3& origin, idMat3& axis, float& fov,
        bool& thirdPerson);
    void GetDetachableWorldTransform(const idDeclInventory* declaration,
        idVec3& origin, idMat3& axis);
    bool PredictSpecialDeath();
    void UpdateWheelSkid();
    void HandleBoostViewFx(float fraction, float& fov, float& shake);
    void GetSimpleCameraInternal(idVec3& origin, idMat3& axis, float& fov);
    void StopBlurFX();
    idPresentablePlayer* PlayerIsOccupant() const;
    idPresentable* GetDriver() const;
    idPresentablePlayer* GetPlayerDriver() const;
    idEntity* GetDriverAsEntity() const;
    idPresentable* GetGunner() const;
    idEntity* GetDriverEntity();
    void* GetVisualAsEntity(void* occupant) const;
    void* GetNpcAsEntity(void* occupant) const;
    void SendCurrentWeaponToServer();
    int GetNumActiveOccupants() const;
    bool IsLocallyControlled() const override;
    bool IsLocallyControlledByPlayer() const;
    bool IsRemotelyControlledByPlayer() const;
    void ClientHandleDamageInfo(vehicleDamageInfo_t& damage);
    void* GetClientFire();
    bool GetPassengerView(idVec3& origin, idMat3& axis, float& fov);
    bool GetFPSDriverView(idVec3& origin, idMat3& axis, float& fov);
    void UpdateWhiplash();
    idPresentable* ThrowAttachedItem(const idDeclInventory* declaration);
    void SetLockScrambling(bool scrambling);
    void TriggerBoostExtender();
    void SetSmashActive(bool active);
    idPresentable* GetLockedTarget();
    void SerializeWeaponList(idSerializer& serializer);
    void SerializePredictionState(idSerializer& serializer);
    bool ServerOverridingPosition() const;
    void UpdateTireTracks();
    void* GetFXMgrForActiveWeapon();
    void UpdateRemoteClientSimulation(const idVec3& origin,
        const idMat3& axis);
    void GetDriverViewInternalTest(idVec3& origin, idMat3& axis,
        float& fov);
    void AddQuickItemThink(idVehicleQuickItem* item);
    void UpdateExhaust();
    int StartSoundShader_Predicted(soundChannel_t channel,
        const idSoundShader* shader, int flags);
    void StopSound_Predicted(soundChannel_t channel);
    int GetPeerIndex();
    idVehicleWeapon* AddWeaponToVehicle(const idDeclWeapon* declaration);
    void SetCurrentWeaponGroup(int group);
    bool Draw(idPresentablePlayer* player);
    void ThrowAllDetachableItems();
    void ActivateWeaponGroup(bool active);
    void StartMannedWeaponChange();
    void ActivateCrosshair();
    bool IsTargetLockable(const idDeclAmmo* ammo) const override;
    void UpdateCrosshair(vehicleSeat_t seat, const usercmd_t& oldCommand,
        const usercmd_t& command);
    void ClientHitScanHit(int entityNumber, int joint, int body,
        const idDeclWeapon* weapon, const idDeclProjectile* projectile,
        int damageIndex);
    void RecordClientFire(const idWeapon* weapon,
        const idDeclProjectile* projectile, const idFireParms& fire,
        const idTestFireResults& test, const idFinishFireResults& finish);
    void EvaluateClientWeaponSwitch();
    void PerformClientFire(idVehicleWeapon* weapon, int index,
        const idVec3& origin, const idMat3& axis, idPresentable* target);
    void StartFxOnAttachments(fxCondition_t condition);
    void StopFxOnAttachments(fxCondition_t condition);
    void TriggerSmashActive();
    bool Init(idRenderModel* renderModel, idAnimator_VehicleCar* animator,
        const idDeclVehicleProps* properties, idPhysicsCallbacks* callbacks);
    void SerializeOccupants(idSerializer& serializer);
    void UpdateRemoteSimulationParms_Server();
    void UpdateAnimator();
    void Respawn();
    void UpdateDriverView();
    const void* GetSoundDef() const;
    void NextWeapon(bool force);
    void PrevWeapon(bool force);
    void SerializeWeaponChange(idSerializer& serializer);
    void UpdateWeapons();
    void CheckImpulse_Local(vehicleSeat_t seat, usercmd_t& oldCommand,
        usercmd_t& command);
    void ClientHitScanHit_ClientFire(int entityNumber,
        const idDeclWeapon* weapon, int damageIndex);
    void EvaluateClientFire();
    void ThrowDebris(const idVec3& origin, const idVec3& velocity,
        const idVec3& angularVelocity, int count);
    void SetDefaults();
    void SerializeDetachableItems(idSerializer& serializer);
    void UpdateSounds();
    void UpdateEffects();
    void UpdateSteerAngle(float fraction);
    void UseQuickItem(idVehicleQuickItem* item);
    vehicleCollideResult_t HandleCollisionClientServer(
        idPresentable* other, int bodyId, trace_t& trace,
        const idVec3& velocity);
    void AddDetachableItem(const void* detachable, bool attached);
    void Serialize(idSerializer& serializer) override;
    void ServerClientThink(int currentTime);
    void UseQuickItem();
    vehicleCollideResult_t Collide(int entityNumber, trace_t& trace,
        const idVec3& velocity);
    void ClientThink(int currentTime, float fraction, bool predict) override;
    void ServerThink(int currentTime);
    bool SelectQuickItem(int itemIndex);
    void UpdateQuickUse(usercmd_t& oldCommand, usercmd_t& command,
        int startTime, int endTime);
    void PostSerializeRead(bool firstClientFrame) override;
    void DriveControl_Local(idPresentablePlayer* player,
        usercmd_t& oldCommand, usercmd_t& command, int startTime,
        int endTime, bool predict);
    void DriveControl(idPresentablePlayer* player);
    void ClientPredict(int currentTime, float fraction) override;

    presentableType_t GetType() const override { return PRESENTABLE_VEHICLE; }
    idPresentableVehicle* GetVehicleInterface() override { return this; }

    idAnimator_VehicleCar* animator;
    const idDeclVehicleProps* vehicleProps;
    idPhysics* physicsObj;
    idPhysicsCallbacks* clientPhysicsCB;
    idPresentableVehiclePhysicsCB physicsCallbacks;
    bool enableVehicleControls;
    bool engineRunning;
    bool accelerating;
    bool reversing;
    bool boosting;
    bool canAccelerate;
    bool braking;
    bool handBraking;
    bool engineDisabled;
    bool boostDisabled;
    bool hasBoosted;
    bool hasQuad;
    bool allowWeaponChange;
    bool hasInfiniteAmmoSerialized;
    bool isLockScrambling;
    bool isSmashActive;
    bool crosshairActive;
    bool weaponGroupActive;
    bool pushCrosshairLocked;
    float currentThrottle;
    float currentMPH;
    float currentApproxMPH;
    float maxSpeed;
    float currentMaxSpeed;
    float currentMaxReverseSpeed;
    float currentSteerAngle;
    float boostPower;
    float boostDuration;
    float boostScalePercent;
    float megaBoostAcceleration;
    float healthSerialized;
    float maxHealthSerialized;
    int megaBoostTime;
    int boostStartTime;
    int externalBoostDuration;
    int numWheelsOnGround;
    int timeInAir;
    int currentWeaponGroup;
    int clientPendingWeaponGroup;
    int forceBoostFxTime;
    int EMPTimeout;
    int numLockedProjectiles;
    int smashTimeout;
    int predictSmashActiveFrame;
    int serverOverridePositionTime;
    int curQuickItem;
    int curQuickItemSlot;
    int damageHistoryIndex;
    int damageHistoryLastSerialize;
    reverseBoostState_t reverseBoostState;
    autoRollState_t autoRollState;
    idVec3 currentApproxLinearVelocity;
    idVec3 driverViewOrigin;
    idMat3 driverViewAxis;
    float driverViewFov;
    idAngles driverViewAngles;
    idPresentable* occupants[2];
    idPresentable* lockedTarget;
    std::vector<idVehicleWeapon*> weapons;
    std::vector<idVehicleQuickItem*> quickItems;
    std::vector<const idDeclInventory*> detachableItems;
    vehicleDamageInfo_t damageHistory[8];
    netBoolEvent_t quadOn;
    netBoolEvent_t quadOff;
    netBoolEvent_t resetBoost;
};

int Tungsten_GetVehicleSurfaceSound(int surfaceType, int fallback);
void Tungsten_TestServerArmor(const idCmdArgs& args);
void Tungsten_TestServerArmorRestore(const idCmdArgs& args);
