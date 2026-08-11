#include "presentableweapon.h"

#include "presentablevehiclecar.h"

#include <algorithm>

namespace {

idPresentableWeaponServices defaultWeaponServices;
idPresentableWeaponServices* weaponServices = &defaultWeaponServices;

} // namespace

int idPresentableWeapon::presentableWeaponCounter = 0;

void Tungsten_SetPresentableWeaponServices(
        idPresentableWeaponServices* services) {
    weaponServices = services != nullptr ? services : &defaultWeaponServices;
}

// EA 0x82BB1C58
void idPresentableWeapon::WeaponDeleted() {
    clientWeapon = nullptr;
}

// EA 0x82BB1C68
void idPresentableWeapon::Shutdown() {
    idPresentable::Shutdown();
}

// EA 0x82BB1C70
void idPresentableWeapon::Present() {
    idPresentableAnimatedEntity::Present();
}

// EA 0x82BB1C78
bool idPresentableWeapon::GetMuzzleFlashWorldTransform(idVec3& outOrigin,
        idMat3& outAxis, attack_t attackType) {
    const idTreeAnimator* treeAnimator = GetTreeAnimator();
    return clientWeapon != nullptr && treeAnimator != nullptr
        && weaponServices->GetMuzzleFlashWorldTransform(clientWeapon,
            treeAnimator, static_cast<int>(attackType), outOrigin, outAxis);
}

// EA 0x82BB1CF8
idPresentableWeapon::idPresentableWeapon(idRenderModel* renderModel,
        const idDeclWeapon* declaration, int ownerEntityNumber,
        idAnimStack* stack, idEntity* ownerEntity, bool useSphereModel)
    : idPresentableAnimatedEntity(ownerEntity, renderModel, stack,
        ownerEntity != nullptr ? ownerEntityNumber : ENTITYNUM_NONE,
        nullptr, useSphereModel), hitJoint(-1), rollJointIndex(-1),
      presentableWeaponID(presentableWeaponCounter++), lastWeaponID(-1),
      rollDelta(0.0f), weaponDecl(declaration), rollAngle(0.0f),
      clientWeapon(nullptr), netFireIndex(0), netFireIndexLastSerialize(0),
      ammoDecl(nullptr), expectedHit(nullptr), lastFireTime(0),
      ownerEntityNum(ownerEntityNumber), spinJointOrigin(0.0f, 0.0f, 0.0f),
      spinJointMat(1.0f), laserSightVisible(false),
      laserSightInitialized(declaration != nullptr) {
    UpdateOwnerAndAttacker();
}

// EA 0x82BB1F88
idPresentableWeapon::~idPresentableWeapon() {
    if (clientWeapon != nullptr) {
        weaponServices->BindPresentableWeapon(clientWeapon, nullptr);
        if (weaponServices->IsClient()) {
            weaponServices->DestroyClientWeapon(clientWeapon);
        }
        clientWeapon = nullptr;
    }
    weaponServices->ShutdownLaserSight(*this);
    laserSightInitialized = false;
    laserSightVisible = false;
}

// EA 0x82BB20C8
void idPresentableWeapon::InitClientWeapon() {
    if (clientWeapon == nullptr) return;
    laserSightInitialized = true;
    weaponServices->InitializeClientWeapon(*this, clientWeapon);
}

// EA 0x82BB22D0
void idPresentableWeapon::ShowLaserSight() {
    laserSightVisible = true;
    weaponServices->ShowLaserSight(*this, weaponServices->GetGameTime());
}

// EA 0x82BB2380
void idPresentableWeapon::UpdateOwnerAndAttacker() {
    if (ownerEntityNum < 0 || ownerEntityNum == ENTITYNUM_NONE) return;
    idPresentable* owner = weaponServices->ResolveOwner(ownerEntityNum);
    if (owner == nullptr) {
        attacker.spawnId = 0;
        vehicleAttacker.spawnId = 0;
        return;
    }
    idPresentableVehicle* vehicle = owner->GetVehicleInterface();
    if (vehicle != nullptr) {
        vehicleAttacker.spawnId = owner->spawnId;
        idPresentable* driver = vehicle->GetDriver();
        attacker.spawnId = driver != nullptr ? driver->spawnId : 0;
    } else {
        vehicleAttacker.spawnId = 0;
        attacker.spawnId = owner->spawnId;
    }
}

// EA 0x82BB2468
void idPresentableWeapon::UpdateLaserSight(const idVec3& start,
        const idVec3& end, int passEntityNumber) {
    if (!laserSightInitialized) return;
    weaponServices->UpdateLaserSight(*this, start, end, passEntityNumber);
}

// EA 0x82BB2540
bool idPresentableWeapon::GetLaserSightWorldTransform(
        const idTreeAnimator* parentModel, idVec3& outOrigin,
        idMat3& outAxis) const {
    if (parentModel == nullptr) return false;
    if (weaponServices->GetLaserSightWorldTransform(
            parentModel, outOrigin, outAxis)) {
        return true;
    }
    outOrigin.Zero();
    outAxis = idMat3(1.0f);
    return false;
}

// EA 0x82BB2708
void idPresentableWeapon::UpdateFX(const idVec3& updateOrigin,
        const idMat3& updateAxis, idFXManager& manager, float fovScale,
        float depthHack) {
    idPresentable::UpdateFX(updateOrigin, updateAxis, fovScale, depthHack);
    weaponServices->UpdateWeaponFX(*this, manager, updateOrigin, updateAxis,
        fovScale, depthHack);
    if (rollJointIndex < 0) return;
    const int currentTime = weaponServices->GetGameTime();
    if (currentTime - lastFireTime >= weaponServices->GetRollEndTime()) {
        rollDelta = std::max(0.0f,
            rollDelta - weaponServices->GetRollEndAcceleration());
    } else {
        rollDelta = std::min(weaponServices->GetRollTopSpeed(),
            rollDelta + weaponServices->GetRollStartAcceleration());
    }
    rollAngle += rollDelta;
    if (rollAngle >= 180.0f) rollAngle -= 360.0f;
    weaponServices->SetBarrelRoll(*this, GetTreeAnimator(), rollJointIndex,
        spinJointMat[0], -rollAngle);
}

// EA 0x82BB2920
void idPresentableWeapon::PostSerializeRead(bool firstClientFrame) {
    idPresentableAnimatedEntity::PostSerializeRead(firstClientFrame);
    UpdateOwnerAndAttacker();
    if (weaponDecl != nullptr && clientWeapon == nullptr) {
        SetClientWeapon(weaponServices->CreateClientWeapon(weaponDecl));
        if (clientWeapon != nullptr) InitClientWeapon();
    }
    if (clientWeapon != nullptr && ammoDecl != nullptr) {
        weaponServices->ForceAmmo(clientWeapon, ammoDecl);
    }
}

// EA 0x82BB2A90
void idPresentableWeapon::RecordFireEvent(const idFireParms& fire,
        const idTestFireResults& tests, idFinishFireResults&, int loadedCount) {
    weaponServices->MarkSerialized(*this);
    int joint = -1;
    hitPresentable.spawnId = weaponServices->FindFireHit(tests, joint);
    hitJoint = static_cast<std::int16_t>(joint);
    if (expectedHit != nullptr) {
        hitPresentable.spawnId = expectedHit->spawnId;
        expectedHit = nullptr;
    }
    ++netFireIndex;
    ammoDecl = weaponServices->GetFiredAmmo(fire);
    lastFireTime = weaponServices->GetGameTime();
    lastWeaponID = loadedCount;
}

// EA 0x82BB2E80
void idPresentableWeapon::Serialize(idSerializer& serializer) {
    idPresentableAnimatedEntity::Serialize(serializer);
    if (serializer.IsWriting()) netFireIndexLastSerialize = netFireIndex;
    serializer.SerializePacked(netFireIndexLastSerialize);
    serializer.SerializePacked(ownerEntityNum);
    weaponServices->SerializeWeaponDeclaration(serializer, weaponDecl);
    weaponServices->SerializeAmmoDeclaration(serializer, ammoDecl);
    UpdateOwnerAndAttacker();
    if (weaponServices->ResolveSpawnId(vehicleAttacker.spawnId) == nullptr) {
        serializer.Serialize(hitPresentable.spawnId);
        serializer.Serialize(hitJoint);
    }
}

// EA 0x82BB2F88
bool idPresentableWeapon::IsLocallyControlledByPlayer() {
    idPresentable* attackOwner = weaponServices->ResolveSpawnId(attacker.spawnId);
    if (attackOwner == nullptr) {
        UpdateOwnerAndAttacker();
        attackOwner = weaponServices->ResolveSpawnId(attacker.spawnId);
    }
    return attackOwner != nullptr
        && attackOwner->GetPlayerInterface() != nullptr
        && weaponServices->IsLocalPlayer(attackOwner->entityNumber);
}

// EA 0x82BB3088
void idPresentableWeapon::ClientThink(int currentTime, float fraction,
        bool predict) {
    idPresentableAnimatedEntity::ClientThink(currentTime, fraction, predict);
    if (GetTreeAnimator() == nullptr) return;
    if (IsLocallyControlledByPlayer()
            && !weaponServices->SerializeLocallyControlledWeapons()) {
        netFireIndex = netFireIndexLastSerialize;
        return;
    }
    if (clientWeapon == nullptr || weaponDecl == nullptr) {
        netFireIndex = netFireIndexLastSerialize;
        return;
    }
    if (laserSightVisible) {
        idVec3 laserOrigin;
        idMat3 laserAxis;
        if (GetLaserSightWorldTransform(GetTreeAnimator(),
                laserOrigin, laserAxis)) {
            UpdateLaserSight(laserOrigin,
                laserOrigin + laserAxis[0] * 8192.0f, entityNumber);
        }
    }
    if (netFireIndex < netFireIndexLastSerialize
            && lastFireTime + weaponServices->GetMinimumReplayInterval()
                <= weaponServices->GetGameTime()) {
        idPresentable* attackOwner =
            weaponServices->ResolveSpawnId(attacker.spawnId);
        idPresentable* hit =
            weaponServices->ResolveSpawnId(hitPresentable.spawnId);
        if (weaponServices->ReplayFire(*this, clientWeapon, attackOwner,
                hit, hitJoint)) {
            ++netFireIndex;
            lastFireTime = weaponServices->GetGameTime();
        }
    }
}

// EA 0x82BB38C0
void idPresentableWeapon::SetClientWeapon(idWeapon* weapon) {
    if (clientWeapon != nullptr) {
        weaponServices->BindPresentableWeapon(clientWeapon, nullptr);
    }
    clientWeapon = weapon;
    if (clientWeapon != nullptr) {
        weaponServices->BindPresentableWeapon(clientWeapon, this);
    }
}
