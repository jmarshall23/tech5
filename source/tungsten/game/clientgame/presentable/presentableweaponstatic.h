#pragma once

#include "presentableprop.h"

#include <cstdint>
#include <vector>

class idAnimator_JointMod;
class idProp_WeaponStatic;
class idPresentableWeaponStatic;

struct barrelProps_t {
    int muzzleTagIndex{-1};
    int ejectTagIndex{-1};
    bool primary{true};
};

struct staticWeaponControlState_t {
    idAngles angularDelta{0.0f, 0.0f, 0.0f};
    bool primary{false};
    bool secondary{false};
    bool zoom{false};
};

class idPresentableWeaponStaticServices {
public:
    virtual ~idPresentableWeaponStaticServices() = default;
    virtual idWeapon* CreateClientWeapon(const idDeclInventory*) {
        return nullptr;
    }
    virtual void DestroyClientWeapon(idWeapon*) {}
    virtual void BindStaticWeapon(idWeapon*, idPresentableWeaponStatic*) {}
    virtual bool DrawWeapon(idPresentableWeaponStatic&,
        idPresentablePlayer*) { return true; }
    virtual bool GetControlState(idPresentableWeaponStatic&,
        staticWeaponControlState_t&) const { return false; }
    virtual bool IsReadyToFire(idWeapon*) const { return false; }
    virtual bool FireBarrel(idPresentableWeaponStatic&, idWeapon*,
        const barrelProps_t&, bool, bool, const idMat3&) { return false; }
    virtual void ClientUpdateWeapon(idWeapon*) {}
    virtual void SetWeaponZoom(idWeapon*, bool) {}
    virtual void ClearJointMods(idAnimator_JointMod*) {}
    virtual void SetJointMod(idAnimator_JointMod*, std::int16_t,
        const idMat3&) {}
    virtual bool GetPitchJointTransform(idPresentableWeaponStatic&,
        idVec3&, idMat3&) const { return false; }
    virtual void UpdateAnimation(idPresentableWeaponStatic&, int, float) {}
    virtual void UpdateCollision(idPresentableWeaponStatic&,
        const idVec3&, const idMat3&) {}
    virtual int GetAnimatorIndex(idAnimStack*, idAnimator_JointMod*) const {
        return -1;
    }
    virtual idAnimator_JointMod* GetAnimatorByIndex(idAnimStack*, int) const {
        return nullptr;
    }
    virtual void SerializeInventoryDeclaration(idSerializer&,
        const idDeclInventory*&) {}
    virtual void SerializeSoundDeclaration(idSerializer&,
        const idSoundShader*&) {}
};

void Tungsten_SetPresentableWeaponStaticServices(
    idPresentableWeaponStaticServices* services);

class idPresentableWeaponStatic : public idPresentableProp {
public:
    idPresentableWeaponStatic(idProp_WeaponStatic* entity,
        idRenderModel* renderModel, idAnimStack* animStack,
        idAnimator_JointMod* jointModAnimator, int entityNumber,
        const idDeclFX* fxDecl, bool useSphereModel);
    ~idPresentableWeaponStatic() override;

    idWeapon* GetFiredWeapon(const idDeclWeapon* weapon);
    void PullTrigger();
    void ReleaseTrigger();
    void PostSerializeRead(bool firstClientFrame) override;
    bool Draw(idPresentablePlayer* player);
    void SetClientWeapon(idWeapon* weapon);
    void Serialize(idSerializer& serializer) override;
    void ClientThink(int currentTime, float fraction, bool predict) override;
    void Shoot(bool primary, bool secondary);
    void SetDefaults();

    idPresentableWeaponStatic* GetWeaponStaticInterface() override {
        return this;
    }
    presentableType_t GetType() const override {
        return PRESENTABLE_WEAPON_STATIC;
    }

    float curHeat;
    int maxHeat;
    float minPitch;
    float maxPitch;
    float minYaw;
    float maxYaw;
    bool overheating;
    bool fireInOrder;
    idMat3 lookAt;
    int turning;
    std::int16_t jointYaw;
    std::int16_t jointPitch;
    const idDeclInventory* weaponDecl;
    float windupTimer;
    float clipForwardAmount;
    const idSoundShader* sndTurning;
    const idSoundShader* sndFireLoop;
    const idSoundShader* sndFireStop;
    const idSoundShader* sndOverheat;
    int infopropsIndex;
    std::vector<barrelProps_t> barrels;
    idWeapon* clientWeapon;
    float zoomTime;
    bool shooting;
    float windupTime;
    idAnimator_JointMod* jointModAnimator;
    float lastThinkTime;
    int barrelIndex;
};
