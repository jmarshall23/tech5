#include "presentableweaponstatic.h"

#include <algorithm>
#include <cmath>

namespace {

idPresentableWeaponStaticServices defaultStaticWeaponServices;
idPresentableWeaponStaticServices* staticWeaponServices =
    &defaultStaticWeaponServices;

float ClampStaticWeapon(float value, float minimum, float maximum) {
    return std::max(minimum, std::min(maximum, value));
}

} // namespace

void Tungsten_SetPresentableWeaponStaticServices(
        idPresentableWeaponStaticServices* services) {
    staticWeaponServices = services != nullptr
        ? services : &defaultStaticWeaponServices;
}

// EA 0x82BB3958
idWeapon* idPresentableWeaponStatic::GetFiredWeapon(
        const idDeclWeapon* declaration) {
    return weaponDecl != nullptr
        && reinterpret_cast<const idDeclWeapon*>(weaponDecl) == declaration
        ? clientWeapon : nullptr;
}

// EA 0x82BB3980
void idPresentableWeaponStatic::PullTrigger() {
    StartSoundShader(SND_CHANNEL_WEAPON, sndFireLoop, 0, 0);
    windupTimer = windupTime;
    shooting = true;
}

// EA 0x82BB39D0
void idPresentableWeaponStatic::ReleaseTrigger() {
    shooting = false;
    StopSound(SND_CHANNEL_WEAPON, 0);
    StartSoundShader(SND_CHANNEL_WEAPON2, sndFireStop, 0, 0);
    windupTimer = windupTime;
}

// EA 0x82BB3A30
void idPresentableWeaponStatic::PostSerializeRead(bool firstClientFrame) {
    idPresentableAnimatedEntity::PostSerializeRead(firstClientFrame);
    if (weaponDecl != nullptr && clientWeapon == nullptr) {
        SetClientWeapon(staticWeaponServices->CreateClientWeapon(weaponDecl));
    }
}

// EA 0x82BB3AB8
bool idPresentableWeaponStatic::Draw(idPresentablePlayer* player) {
    return staticWeaponServices->DrawWeapon(*this, player);
}

// EA 0x82BB3D90
idPresentableWeaponStatic::~idPresentableWeaponStatic() {
    if (clientWeapon != nullptr) {
        staticWeaponServices->BindStaticWeapon(clientWeapon, nullptr);
        staticWeaponServices->DestroyClientWeapon(clientWeapon);
        clientWeapon = nullptr;
    }
    barrels.clear();
}

// EA 0x82BB3E90
void idPresentableWeaponStatic::SetClientWeapon(idWeapon* weapon) {
    if (clientWeapon != nullptr) {
        staticWeaponServices->BindStaticWeapon(clientWeapon, nullptr);
    }
    clientWeapon = weapon;
    if (clientWeapon != nullptr) {
        staticWeaponServices->BindStaticWeapon(clientWeapon, this);
    }
}

// EA 0x82BB3EB0
void idPresentableWeaponStatic::Serialize(idSerializer& serializer) {
    idPresentableProp::Serialize(serializer);
    serializer.Serialize(curHeat);
    serializer.Serialize(maxHeat);
    serializer.Serialize(minPitch);
    serializer.Serialize(maxPitch);
    serializer.Serialize(minYaw);
    serializer.Serialize(maxYaw);
    staticWeaponServices->SerializeInventoryDeclaration(serializer,
        weaponDecl);
    staticWeaponServices->SerializeSoundDeclaration(serializer, sndTurning);
    staticWeaponServices->SerializeSoundDeclaration(serializer, sndFireLoop);
    staticWeaponServices->SerializeSoundDeclaration(serializer, sndFireStop);
    staticWeaponServices->SerializeSoundDeclaration(serializer, sndOverheat);
    serializer.Serialize(windupTime);
    int animatorIndex = serializer.IsWriting()
        ? staticWeaponServices->GetAnimatorIndex(animStack,
            jointModAnimator) : -1;
    serializer.SerializePacked(animatorIndex);
    if (serializer.IsReading()) {
        jointModAnimator = staticWeaponServices->GetAnimatorByIndex(
            animStack, animatorIndex);
    }
    serializer.Serialize(overheating);
}

// EA 0x82BB4230
void idPresentableWeaponStatic::ClientThink(int currentTime, float fraction,
        bool predict) {
    staticWeaponServices->ClearJointMods(jointModAnimator);
    idVec3 pitchOrigin;
    idMat3 pitchAxis;
    if (!staticWeaponServices->GetPitchJointTransform(*this,
            pitchOrigin, pitchAxis)) {
        idPresentableAnimatedEntity::ClientThink(currentTime, fraction,
            predict);
        return;
    }
    if (lookAt.Determinant() == 0.0f) lookAt = pitchAxis;
    staticWeaponControlState_t control;
    const bool controlled = staticWeaponServices->GetControlState(
        *this, control);
    const float elapsed = lastThinkTime > 0.0f
        ? std::max(0.0f, (currentTime - lastThinkTime) * 0.001f) : 0.0f;
    if (controlled) {
        const bool wantsFire = control.primary || control.secondary;
        if (wantsFire && !shooting) PullTrigger();
        if (wantsFire) {
            windupTimer = std::max(0.0f, windupTimer - elapsed);
            if (windupTimer <= 0.0f) Shoot(control.primary,
                control.secondary);
        } else if (shooting) {
            ReleaseTrigger();
        }
        if (control.zoom) {
            zoomTime = std::max(0.0f, zoomTime - elapsed * 1000.0f);
            staticWeaponServices->SetWeaponZoom(clientWeapon, true);
        } else {
            zoomTime = std::min(180.0f, zoomTime + elapsed * 1000.0f);
            staticWeaponServices->SetWeaponZoom(clientWeapon, false);
        }
        idAngles angles = control.angularDelta;
        angles.pitch = ClampStaticWeapon(angles.pitch, -minPitch, maxPitch);
        angles.yaw = ClampStaticWeapon(angles.yaw, -minYaw, maxYaw);
        lookAt = angles.ToMat3();
        lookAt.OrthoNormalizeSelf();
        const float turnMagnitude = std::sqrt(
            control.angularDelta.pitch * control.angularDelta.pitch
            + control.angularDelta.yaw * control.angularDelta.yaw
            + control.angularDelta.roll * control.angularDelta.roll);
        turning = turnMagnitude > 0.0f ? std::min(turning + 1, 4)
                                      : std::max(turning - 1, 0);
    } else if (shooting) {
        ReleaseTrigger();
    }
    staticWeaponServices->SetJointMod(jointModAnimator, jointPitch,
        lookAt * axis.Transpose());
    if (jointYaw != jointPitch) {
        idAngles yawOnly(0.0f, control.angularDelta.yaw, 0.0f);
        staticWeaponServices->SetJointMod(jointModAnimator, jointYaw,
            yawOnly.ToMat3());
    }
    staticWeaponServices->UpdateAnimation(*this, currentTime, fraction);
    staticWeaponServices->UpdateCollision(*this,
        pitchOrigin + pitchAxis[0] * clipForwardAmount, lookAt);
    staticWeaponServices->ClientUpdateWeapon(clientWeapon);
    lastThinkTime = static_cast<float>(currentTime);
    idPresentableAnimatedEntity::ClientThink(currentTime, fraction, predict);
}

// EA 0x82BB4A90
void idPresentableWeaponStatic::Shoot(bool primary, bool secondary) {
    if (clientWeapon == nullptr
            || !staticWeaponServices->IsReadyToFire(clientWeapon)
            || barrels.empty()) return;
    if (!fireInOrder) {
        for (const barrelProps_t& barrel : barrels) {
            staticWeaponServices->FireBarrel(*this, clientWeapon, barrel,
                primary, secondary, lookAt);
        }
        return;
    }
    barrelIndex = std::max(0,
        std::min(barrelIndex, static_cast<int>(barrels.size()) - 1));
    const barrelProps_t& barrel = barrels[barrelIndex];
    const bool selected = barrel.primary ? primary : secondary;
    if (selected) {
        staticWeaponServices->FireBarrel(*this, clientWeapon, barrel,
            primary, secondary, lookAt);
    }
    barrelIndex = (barrelIndex + 1) % static_cast<int>(barrels.size());
}

// EA 0x82BB4F98
void idPresentableWeaponStatic::SetDefaults() {
    overheating = false;
    maxHeat = 100;
    curHeat = 0.0f;
    minPitch = 0.0f;
    maxPitch = 0.0f;
    minYaw = 0.0f;
    maxYaw = 0.0f;
    fireInOrder = false;
    lookAt = idMat3(1.0f);
    turning = 0;
    weaponDecl = nullptr;
    sndTurning = nullptr;
    sndFireLoop = nullptr;
    sndFireStop = nullptr;
    sndOverheat = nullptr;
    zoomTime = 180.0f;
    windupTime = 0.5f;
    windupTimer = 0.0f;
    clipForwardAmount = 22.0f;
    lastThinkTime = 0.0f;
    shooting = false;
    barrelIndex = 0;
    clientWeapon = nullptr;
    infopropsIndex = -1;
    if (barrels.empty()) barrels.push_back(barrelProps_t());
}

// EA 0x82BB50D0
idPresentableWeaponStatic::idPresentableWeaponStatic(
        idProp_WeaponStatic* staticWeapon, idRenderModel* renderModel,
        idAnimStack* stack, idAnimator_JointMod* jointAnimator,
        int newEntityNumber, const idDeclFX* declaration,
        bool useSphereModel)
    : idPresentableProp(reinterpret_cast<idProp*>(staticWeapon), renderModel,
        stack, newEntityNumber, declaration, useSphereModel, nullptr, false),
      jointYaw(-1), jointPitch(-1), jointModAnimator(jointAnimator) {
    SetDefaults();
    jointModAnimator = jointAnimator;
}
