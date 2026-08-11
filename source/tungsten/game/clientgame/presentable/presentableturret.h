#pragma once

#include "presentableweapon.h"

#include <cstdint>

class idAnimator_JointMod;
class idTurret;
class idPresentableTurret;

class idPresentableTurretServices {
public:
    virtual ~idPresentableTurretServices() = default;
    virtual void ClearJointMods(idAnimator_JointMod*) {}
    virtual void SetJointMod(idAnimator_JointMod*, std::int16_t,
        const idMat3&) {}
    virtual idWeapon* GetTurretWeapon(idEntity*) const { return nullptr; }
    virtual int GetAnimatorIndex(idAnimStack*, idAnimator_JointMod*) const {
        return -1;
    }
    virtual idAnimator_JointMod* GetAnimatorByIndex(idAnimStack*, int) const {
        return nullptr;
    }
};

void Tungsten_SetPresentableTurretServices(
    idPresentableTurretServices* services);

class idPresentableTurret : public idPresentableWeapon {
public:
    idPresentableTurret(const idDeclWeapon* weaponDeclaration,
        idTurret* entity, idRenderModel* renderModel,
        idAnimator_JointMod* jointMod, std::int16_t jointRotation,
        std::int16_t jointPitch, std::int16_t jointSpinwheel,
        idAnimStack* animStack, int entityNumber, const idDeclFX* fxDecl,
        bool useSphereModel);

    void ClientThink(int currentTime, float fraction, bool predict) override;
    void ApplyJointMod(std::int16_t jointIndex, const idMat3& jointAxis);
    idWeapon* GetFiredWeapon(const idDeclWeapon* weapon) override;
    void Serialize(idSerializer& serializer) override;
    idPresentableTurret* GetTurretInterface() override { return this; }

    idAnimator_JointMod* jointModAnimator;
    std::int16_t jointRotation;
    std::int16_t jointRotationYaw;
    std::int16_t clientLastUpdateRotationYaw;
    std::int16_t jointRotationPitch;
    std::int16_t clientLastUpdateRotationPitch;
    std::int16_t jointPitch;
    std::int16_t jointPitchPitch;
    std::int16_t clientLastUpdateJointPitch;
    std::int16_t jointSpinwheel;
};
