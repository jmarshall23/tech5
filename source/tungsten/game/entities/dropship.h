#pragma once

#include "idlib/containers/list.h"
#include "idlib/math/vector.h"

class idDeclEntityDef;
class idDeclInventory;
class idDeclMD6;
class idDeclVehicleWeapon;
class idEntity;
class idSoundShader;
class idSplinePath;
class idTarget_Spawn;
class idWeapon;
class idDropShip;

enum dropShipState_t {
    DPSP_HOVER = 0,
    DPSP_ENROUTE,
    DPSP_DROPCARGO,
    DPSP_WAITTILLCLEAR,
    DPSP_HEADINGOUT,
    DPSP_POWERDOWN,
    DPSP_LANDED,
    DPSP_DONE
};

enum dropShipSplineType_t {
    DPST_NONE = 0,
    DPST_STARTSPLINE,
    DPST_ENDSPLINE
};

struct dropShipSpline {
    idSplinePath* spline = nullptr;
    dropShipSplineType_t type = DPST_NONE;
    float speed = 0.0f;
};

struct dropShipCargo_t {
    idTarget_Spawn* targetSpawn = nullptr;
    const idDeclEntityDef* cargoDef = nullptr;
    int count = 0;
    bool waitTillClear = false;
};

struct dropShipSpeedTable_t {
    float distance = 0.0f;
    float speed = 0.0f;
};

struct idDropShipSound {
    const idSoundShader* sound = nullptr;
    float minPitch = 0.0f;
    float maxPitch = 0.0f;
    float minVolume = 0.0f;
    float maxVolume = 0.0f;
};

struct idDropShipSpring {
    float restLength = 0.0f;
    float k = 1.0f;
    float m = 1.0f;
    float c = 2.0f;
    idVec3 p0{0.0f, 0.0f, 0.0f};
    idVec3 p1{0.0f, 0.0f, 0.0f};
    idVec3 velocity{0.0f, 0.0f, 0.0f};
    float maxSpeed = 0.0f;
};

class idDropShipSplineCurve {
public:
    virtual ~idDropShipSplineCurve() = default;
    virtual bool IsDone(float time) const = 0;
    virtual float GetEndTime() const = 0;
    virtual float GetLengthForTime(float time) const = 0;
    virtual idVec3 GetCurrentValue(float time) const = 0;
    virtual idVec3 GetCurrentFirstDerivative(float time) const = 0;
};

class idDropShipServices {
public:
    virtual ~idDropShipServices() = default;

    virtual int GetGameMilliseconds() const;
    virtual int GetGameMillisecondsPerFrame() const;
    virtual float GetRealSecondsPerFrame() const;
    virtual float GetRealMillisecondsPerFrame() const;
    virtual bool UsesRelaxedChatter(const idDropShip& ship) const;

    virtual void BecomeActive(idDropShip& ship, int flags);
    virtual void BecomeInactive(idDropShip& ship, int flags);
    virtual void QueueRemove(idDropShip& ship);
    virtual void ShowEntity(idDropShip& ship);
    virtual void StartConditionFX(idDropShip& ship, int condition);
    virtual void StopConditionFX(idDropShip& ship, int condition);
    virtual void UpdateBaseFX(idDropShip& ship);
    virtual void UpdateFrameCommands(idDropShip& ship);
    virtual void UpdateAnimation(idDropShip& ship);
    virtual void UpdateAttachments(idDropShip& ship);

    virtual bool IsPlayingSound(const idDropShip& ship, int channel) const;
    virtual void StartSound(idDropShip& ship, int channel,
        const idSoundShader* sound, bool looping);
    virtual void SetSoundPitch(idDropShip& ship, int channel, float pitch);
    virtual void SetSoundVolume(idDropShip& ship, int channel, float volume);

    virtual idVec3 GetOrigin(const idDropShip& ship) const;
    virtual idMat3 GetAxis(const idDropShip& ship) const;
    virtual void SetOrigin(idDropShip& ship, const idVec3& origin);
    virtual void SetAxis(idDropShip& ship, const idMat3& axis);
    virtual bool GetDropTagTransform(const idDropShip& ship,
        const char* tagName, idVec3& origin, idMat3& axis) const;

    virtual bool IsSplinePathValid(const idSplinePath* path) const;
    virtual idDropShipSplineCurve* AllocateSpline(idSplinePath* path,
        float speed);
    virtual void ReleaseSpline(idDropShipSplineCurve* spline);

    virtual void GatherPlayers(const idDropShip& ship,
        idList<idEntity*, 5>& players) const;
    virtual bool IsEntityDead(const idEntity* entity) const;
    virtual bool IsEntityDying(const idEntity* entity) const;
    virtual idVec3 GetEntityOrigin(const idEntity* entity) const;
    virtual void SetControllerShake(idEntity* player, float magnitude);

    virtual idWeapon* CreateWeapon(const idDeclVehicleWeapon* declaration);
    virtual void DestroyWeapon(idWeapon* weapon);
    virtual void AttachWeapon(idDropShip& ship, idWeapon* weapon,
        const char* tagName);
    virtual bool AimWeapon(idDropShip& ship, idWeapon* weapon,
        idEntity* target, idVec3& muzzleOrigin, idMat3& muzzleAxis);
    virtual void FireWeapon(idDropShip& ship, idWeapon* weapon,
        idEntity* target, const idVec3& muzzleOrigin,
        const idMat3& muzzleAxis);

    virtual idEntity* SpawnCargo(idTarget_Spawn* targetSpawn,
        const idDeclEntityDef* entityDef, const idVec3& origin);
    virtual bool IsAI(const idEntity* entity) const;
    virtual void SetCargoTransform(idEntity* entity, const idVec3& origin,
        const idMat3& axis);
    virtual void SetCargoDropState(idEntity* entity, int state);
    virtual void GiveJetPack(idEntity* entity,
        const idDeclInventory* inventoryDecl);

    virtual bool SpringTuningChanged() const;
    virtual void ClearSpringTuningChanged();
    virtual void DrawSpringDebug(const idDropShip& ship,
        const idDropShipSpring& spring);
    virtual void ReportWarning(const idDropShip& ship, const char* message);
    virtual void ReportError(const idDropShip& ship, const char* message);
    virtual void ReleaseRuntime(idDropShip& ship);
};

class idDropShip {
public:
    using dropShipSound_t = idDropShipSound;

    idDropShip();
    virtual ~idDropShip();
    static void SetServices(idDropShipServices* services);
    static idDropShipServices& Services();

    void UpdatePropellerVisuals(bool on);
    void State_Done();
    void ChangeState(dropShipState_t newState);
    void UpdateSounds();
    idVec3 GetDropLocation(int index);
    void ModifyAxisFromMovementSpring(idMat3& axis) const;
    virtual void Show();
    void State_EnRoute();
    void State_HeadingOut();
    void State_PowerDown();
    void RunPhysics();
    virtual void UpdateFX();
    void DebugDropShip();
    void State_WaitTillEnemyCleared();
    void FindSplineType(dropShipSplineType_t splineType);
    void UpdateWeapons();
    virtual void OnActivate(idEntity* activator);
    void Spawn();
    void DropCargo();
    void State_DropCargo();
    virtual void Think();

    idList<dropShipSpline, 5> splines;
    idList<dropShipCargo_t, 5> cargo;
    float timeBetweenDrops;
    const idDeclInventory* jetPackInventory;
    idList<dropShipSpeedTable_t, 5> speedTable;
    bool dropImmediately;
    bool startOffHovering;
    bool powerDownAtEndOfSpline;
    float timeToPowerDown;
    const idSoundShader* powerDownSound;
    float fireDelayWhenMoving;
    float fireDelayWhenHovering;
    const idDeclVehicleWeapon* vehicleWeapon;
    const idDeclMD6* weaponAttachment;
    idList<dropShipSound_t, 5> dropShipSound;
    float soundFadeTime;
    idList<idEntity*, 5> droppedCargo;
    idWeapon* weapon;
    idDropShipSplineCurve* currentSpline;
    int currentSplineIdx;
    idDropShipSpring movementSpring;
    idMat3 currentAxis;
    idAngles angles;
    float currentDt;
    dropShipState_t dropShipState;
    int stateTimer;
    int stateStartTime;
    int soundStartTime;
    float currentSplineTime;
    int fireTimer;
    int curNumDropped;
    idVec2 engineShake;
    idVec3 physicsOrigin;
    idMat3 physicsAxis;
    bool propellersOn;
    bool removalPosted;
    bool spawnValid;

    float springConstant;
    float springDampen;
    float springMass;
    float springMaxSpeed;
    float springGravity;
    float springRollClamp;
    float springMaxRoll;
    float springPitchClamp;
    float springMaxPitch;
    bool springDebug;
};
