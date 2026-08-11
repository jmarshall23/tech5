#pragma once

#include "presentable.h"
#include "presentableptr.h"

#include <cstdint>

class idDeclAmmo;
class idDeclWeapon;
class idFinishFireResults;
class idFXManager;
class idTestFireResults;
struct idFireParms;

class idPresentableWeapon;

class idPresentableWeaponServices {
public:
    virtual ~idPresentableWeaponServices() = default;
    virtual idPresentable* ResolveOwner(int) const { return nullptr; }
    virtual idPresentable* ResolveSpawnId(std::uint32_t) const {
        return nullptr;
    }
    virtual bool IsLocalPlayer(int) const { return false; }
    virtual bool IsClient() const { return true; }
    virtual bool SerializeLocallyControlledWeapons() const { return false; }
    virtual int GetGameTime() const { return 0; }
    virtual int GetMinimumReplayInterval() const { return 0; }
    virtual float GetRollStartAcceleration() const { return 0.0f; }
    virtual float GetRollEndAcceleration() const { return 0.0f; }
    virtual float GetRollTopSpeed() const { return 0.0f; }
    virtual int GetRollEndTime() const { return 0; }
    virtual idWeapon* CreateClientWeapon(const idDeclWeapon*) { return nullptr; }
    virtual void DestroyClientWeapon(idWeapon*) {}
    virtual void BindPresentableWeapon(idWeapon*, idPresentableWeapon*) {}
    virtual void InitializeClientWeapon(idPresentableWeapon&, idWeapon*) {}
    virtual void ShutdownLaserSight(idPresentableWeapon&) {}
    virtual void ShowLaserSight(idPresentableWeapon&, int) {}
    virtual bool GetMuzzleFlashWorldTransform(idWeapon*, const idTreeAnimator*,
        int, idVec3&, idMat3&) const { return false; }
    virtual bool GetLaserSightWorldTransform(const idTreeAnimator*, idVec3&,
        idMat3&) const { return false; }
    virtual void UpdateLaserSight(idPresentableWeapon&, const idVec3&,
        const idVec3&, int) {}
    virtual void SetBarrelRoll(idPresentableWeapon&, const idTreeAnimator*, int,
        const idVec3&, float) {}
    virtual void UpdateWeaponFX(idPresentableWeapon&, idFXManager&,
        const idVec3&, const idMat3&, float, float) {}
    virtual std::uint32_t FindFireHit(const idTestFireResults&, int&) const {
        return 0;
    }
    virtual const idDeclAmmo* GetFiredAmmo(const idFireParms&) const {
        return nullptr;
    }
    virtual bool ReplayFire(idPresentableWeapon&, idWeapon*,
        idPresentable*, idPresentable*, int) { return false; }
    virtual void ForceAmmo(idWeapon*, const idDeclAmmo*) {}
    virtual void SerializeWeaponDeclaration(idSerializer&,
        const idDeclWeapon*&) {}
    virtual void SerializeAmmoDeclaration(idSerializer&,
        const idDeclAmmo*&) {}
    virtual void MarkSerialized(idPresentableWeapon&) {}
};

void Tungsten_SetPresentableWeaponServices(
    idPresentableWeaponServices* services);

class idPresentableWeapon : public idPresentableAnimatedEntity {
public:
    enum attack_t : int { ATTACK_DEFAULT = 0, ATTACK_SECONDARY = 1 };

    idPresentableWeapon(idRenderModel* renderModel,
        const idDeclWeapon* declaration, int ownerEntityNumber,
        idAnimStack* animStack, idEntity* entity, bool useSphereModel);
    ~idPresentableWeapon() override;

    void WeaponDeleted();
    void Shutdown() override;
    void Present() override;
    bool GetMuzzleFlashWorldTransform(idVec3& origin, idMat3& axis,
        attack_t attackType);
    void InitClientWeapon();
    void ShowLaserSight();
    void UpdateOwnerAndAttacker();
    void UpdateLaserSight(const idVec3& start, const idVec3& end,
        int passEntityNumber);
    bool GetLaserSightWorldTransform(const idTreeAnimator* parentModel,
        idVec3& origin, idMat3& axis) const;
    void UpdateFX(const idVec3& origin, const idMat3& axis,
        idFXManager& manager, float fovScale, float depthHack);
    void PostSerializeRead(bool firstClientFrame) override;
    void RecordFireEvent(const idFireParms& fire,
        const idTestFireResults& tests, idFinishFireResults& finish,
        int loadedCount);
    void Serialize(idSerializer& serializer) override;
    bool IsLocallyControlledByPlayer();
    void ClientThink(int currentTime, float fraction, bool predict) override;
    void SetClientWeapon(idWeapon* weapon);

    virtual idWeapon* GetFiredWeapon(const idDeclWeapon*) {
        return clientWeapon;
    }
    idPresentableWeapon* GetWeaponInterface() override { return this; }
    presentableType_t GetType() const override { return PRESENTABLE_WEAPON; }

    static int presentableWeaponCounter;

    idPresentablePtr<idPresentable> attacker;
    idPresentablePtr<idPresentable> vehicleAttacker;
    idPresentablePtr<idPresentable> hitPresentable;
    std::int16_t hitJoint;
    std::int16_t rollJointIndex;
    int presentableWeaponID;
    int lastWeaponID;
    float rollDelta;
    const idDeclWeapon* weaponDecl;
    float rollAngle;
    idWeapon* clientWeapon;
    int netFireIndex;
    int netFireIndexLastSerialize;
    const idDeclAmmo* ammoDecl;
    idPresentable* expectedHit;
    int lastFireTime;
    int ownerEntityNum;
    idVec3 spinJointOrigin;
    idMat3 spinJointMat;
    bool laserSightVisible;
    bool laserSightInitialized;
};
