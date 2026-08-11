#include "presentableturret.h"

#include <algorithm>
#include <cmath>

namespace {

idPresentableTurretServices defaultTurretServices;
idPresentableTurretServices* turretServices = &defaultTurretServices;

constexpr std::int16_t NULL_JOINT = -1;
constexpr float SHORT_TO_ANGLE = 360.0f / 65536.0f;
constexpr float ANGLE_TO_SHORT = 65536.0f / 360.0f;
constexpr float RAD_TO_DEG = 57.29577951308232f;

std::int16_t InterpolateShort(std::int16_t from, std::int16_t to,
        float fraction) {
    return static_cast<std::int16_t>(static_cast<int>(from
        + (to - from) * fraction));
}

idAngles MatrixToTurretAngles(const idMat3& matrix) {
    const float pitch = std::asin(std::max(-1.0f,
        std::min(1.0f, -matrix[0].z))) * RAD_TO_DEG;
    const float yaw = std::atan2(matrix[0].y, matrix[0].x) * RAD_TO_DEG;
    return idAngles(pitch, yaw, 0.0f);
}

void SerializeJoint(idSerializer& serializer, std::int16_t& joint) {
    serializer.Serialize(joint);
}

} // namespace

void Tungsten_SetPresentableTurretServices(
        idPresentableTurretServices* services) {
    turretServices = services != nullptr ? services : &defaultTurretServices;
}

// EA 0x82B8FCD8
idPresentableTurret::idPresentableTurret(
        const idDeclWeapon* weaponDeclaration, idTurret* turret,
        idRenderModel* renderModel, idAnimator_JointMod* jointMod,
        std::int16_t rotationJoint, std::int16_t pitchJoint,
        std::int16_t spinwheelJoint, idAnimStack* stack, int entityNumber,
        const idDeclFX*, bool sphereModel)
    : idPresentableWeapon(renderModel, weaponDeclaration, entityNumber,
        stack, reinterpret_cast<idEntity*>(turret), sphereModel),
      jointModAnimator(jointMod), jointRotation(rotationJoint),
      jointRotationYaw(0), clientLastUpdateRotationYaw(0),
      jointRotationPitch(0), clientLastUpdateRotationPitch(0),
      jointPitch(pitchJoint), jointPitchPitch(0),
      clientLastUpdateJointPitch(0), jointSpinwheel(spinwheelJoint) {
}

// EA 0x82B8FD60
void idPresentableTurret::ClientThink(int currentTime, float fraction,
        bool predict) {
    if (jointModAnimator != nullptr && serializeCount > 2) {
        turretServices->ClearJointMods(jointModAnimator);
        if (jointRotation != NULL_JOINT) {
            const std::int16_t yaw = InterpolateShort(
                clientLastUpdateRotationYaw, jointRotationYaw, fraction);
            const std::int16_t pitch = InterpolateShort(
                clientLastUpdateRotationPitch, jointRotationPitch, fraction);
            turretServices->SetJointMod(jointModAnimator, jointRotation,
                idAngles(pitch * SHORT_TO_ANGLE,
                    yaw * SHORT_TO_ANGLE, 0.0f).ToMat3());
        }
        if (jointPitch != NULL_JOINT) {
            const std::int16_t pitch = InterpolateShort(
                clientLastUpdateJointPitch, jointPitchPitch, fraction);
            turretServices->SetJointMod(jointModAnimator, jointPitch,
                idAngles(pitch * SHORT_TO_ANGLE, 0.0f, 0.0f).ToMat3());
        }
        if (jointSpinwheel != NULL_JOINT) {
            turretServices->SetJointMod(jointModAnimator, jointSpinwheel,
                idAngles(0.0f, 0.0f, 0.0f).ToMat3());
        }
    }
    idPresentableWeapon::ClientThink(currentTime, fraction, predict);
}

// EA 0x82B8FFD0
void idPresentableTurret::ApplyJointMod(std::int16_t jointIndex,
        const idMat3& jointAxis) {
    const idAngles angles = MatrixToTurretAngles(jointAxis);
    if (jointRotation != NULL_JOINT && jointRotation == jointIndex) {
        jointRotationYaw = static_cast<std::int16_t>(
            static_cast<int>(angles.yaw * ANGLE_TO_SHORT));
        jointRotationPitch = static_cast<std::int16_t>(
            static_cast<int>(angles.pitch * ANGLE_TO_SHORT));
    }
    if (jointPitch != NULL_JOINT && jointPitch == jointIndex) {
        jointPitchPitch = static_cast<std::int16_t>(
            static_cast<int>(angles.pitch * ANGLE_TO_SHORT));
    }
}

// EA 0x82B900C0
idWeapon* idPresentableTurret::GetFiredWeapon(const idDeclWeapon*) {
    return turretServices->GetTurretWeapon(entity);
}

// EA 0x82B90108
void idPresentableTurret::Serialize(idSerializer& serializer) {
    idPresentableWeapon::Serialize(serializer);
    if (serializer.IsReading()) {
        clientLastUpdateRotationYaw = jointRotationYaw;
        clientLastUpdateRotationPitch = jointRotationPitch;
        clientLastUpdateJointPitch = jointPitchPitch;
    }
    int animatorIndex = serializer.IsWriting()
        ? turretServices->GetAnimatorIndex(animStack, jointModAnimator) : -1;
    serializer.SerializePacked(animatorIndex);
    if (serializer.IsReading()) {
        jointModAnimator = turretServices->GetAnimatorByIndex(animStack,
            animatorIndex);
    }
    SerializeJoint(serializer, jointRotation);
    serializer.Serialize(jointRotationYaw);
    serializer.Serialize(jointRotationPitch);
    SerializeJoint(serializer, jointPitch);
    serializer.Serialize(jointPitchPitch);
    SerializeJoint(serializer, jointSpinwheel);
}
