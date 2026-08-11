#include "game/entities/damageableentity.h"

#include <algorithm>
#include <cmath>

namespace {
idDamageableEntityServices defaultDamageableEntityServices;
idDamageableEntityServices* damageableEntityServices =
    &defaultDamageableEntityServices;

constexpr int DAMAGEABLE_THINK_VISUAL = 1;
constexpr int DAMAGEABLE_THINK_PHYSICS = 2;
constexpr int DAMAGEABLE_THINK_ALL = 7;
constexpr int CONTENTS_BREAKABLE = 139584;
constexpr int CONTENTS_STATIC_MULTI_PIECE = 0x2000;
constexpr int CONTENTS_STATIC_MULTI_AGGREGATE = 0x20000;
constexpr int CONTENTS_BROKEN_REMAINDER = 128;

idBounds Expanded(const idBounds& bounds, const float amount) {
    idBounds expanded = bounds;
    const idVec3 extension(amount, amount, amount);
    expanded[0] = expanded[0] - extension;
    expanded[1] = expanded[1] + extension;
    return expanded;
}

float Clamp01(const float value) {
    return std::max(0.0f, std::min(1.0f, value));
}
}

int idDamageableEntityServices::GetGameMilliseconds() const { return 0; }
int idDamageableEntityServices::GetPreviousGameMilliseconds() const {
    return 0;
}
int idDamageableEntityServices::GetGameMillisecondsPerFrame() const {
    return 16;
}
int idDamageableEntityServices::GetGameFrame() const { return 0; }
float idDamageableEntityServices::GetRealMillisecondsPerFrame() const {
    return 16.0f;
}
float idDamageableEntityServices::RandomFloat() { return 0.0f; }
bool idDamageableEntityServices::IsMultiplayer() const { return false; }
bool idDamageableEntityServices::UpdateDormant(idDamageableEntity&) {
    return false;
}
void idDamageableEntityServices::DormantBegin(idDamageableEntity&) {}
void idDamageableEntityServices::PostRemove(idDamageableEntity&) {}
void idDamageableEntityServices::GetModelTransform(
        const idDamageableEntity& entity, idVec3& resultOrigin,
        idMat3& resultAxis) const {
    resultOrigin = entity.origin;
    resultAxis = entity.axis;
}
int idDamageableEntityServices::BaseCollide(idDamageableEntity&, int,
        trace_t*, const idVec3&) { return 0; }
bool idDamageableEntityServices::TakesDamage(
        const idDamageableEntity&) const { return true; }
float idDamageableEntityServices::GetDamageAmount(
        const idDeclDamage*) const { return 0.0f; }
bool idDamageableEntityServices::DamageIgnoresArmoredBreakables(
        const idDeclDamage*) const { return false; }
bool idDamageableEntityServices::DamageIsMelee(
        const idDeclDamage*) const { return false; }
void idDamageableEntityServices::DamageFeedback(idEntity*,
        idDamageableEntity&, idEntity*, const idDeclDamage*, float) {}
idEntity* idDamageableEntityServices::GetWorldEntity() const {
    return nullptr;
}
const idDeclDamage* idDamageableEntityServices::GetSuicideDamage() const {
    return nullptr;
}
bool idDamageableEntityServices::IsVehicle(const idEntity*) const {
    return false;
}
void idDamageableEntityServices::GetTraceInfo(const trace_t* trace,
        idDamageableTraceInfo& info) const {
    info.valid = trace != nullptr;
}
idPresentable* idDamageableEntityServices::AllocatePresentable(
        idDamageableEntity&, idRenderModel*, const idDeclImpactSound*,
        float) { return nullptr; }
idRenderModel* idDamageableEntityServices::GetRenderModel(
        const idDamageableEntity&) const { return nullptr; }
idRenderModel* idDamageableEntityServices::AllocateRenderModelCopy(
        idRenderModel* model) { return model; }
idRenderModelDiscreteAnimation*
idDamageableEntityServices::AsBreakableModel(idRenderModel*) const {
    return nullptr;
}
bool idDamageableEntityServices::HasBreakableDeclaration(
        const idRenderModelDiscreteAnimation*) const { return false; }
int idDamageableEntityServices::GetBreakablePieceCount(
        const idRenderModelDiscreteAnimation*) const { return 0; }
float idDamageableEntityServices::GetBreakableAnimationSeconds(
        const idRenderModelDiscreteAnimation*) const { return 0.0f; }
void idDamageableEntityServices::GetBreakableFriction(
        const idRenderModelDiscreteAnimation*,
        idDamageableRigidBodySettings&) const {}
void idDamageableEntityServices::SetModel(idDamageableEntity&,
        idRenderModel*) {}
void idDamageableEntityServices::PresentAtIdentity(idDamageableEntity&) {}
void idDamageableEntityServices::ConfigurePresentableClip(
        idDamageableEntity&, int) {}
idPhysics* idDamageableEntityServices::CreateRigidBody(
        idDamageableEntity&, const idDamageableRigidBodySettings&) {
    return nullptr;
}
idPhysics* idDamageableEntityServices::CreateStaticMulti(
        idDamageableEntity&, int, float) { return nullptr; }
void idDamageableEntityServices::AddStaticMultiPiece(
        idDamageableEntity&, idPhysics*, int, float) {}
void idDamageableEntityServices::AddStaticMultiAggregate(
        idDamageableEntity&, idPhysics*, int, float) {}
void idDamageableEntityServices::ConfigureSimpleBreakablePhysics(
        idDamageableEntity&, float) {}
void idDamageableEntityServices::AttachPhysics(idDamageableEntity&,
        idPhysics*) {}
void idDamageableEntityServices::DetachPhysics(idDamageableEntity&) {}
void idDamageableEntityServices::DestroyPhysics(idPhysics*) {}
void idDamageableEntityServices::UnlinkPhysics(idDamageableEntity&) {}
void idDamageableEntityServices::PutPhysicsToRest(idDamageableEntity&) {}
void idDamageableEntityServices::SetPhysicsOrigin(idDamageableEntity&,
        const idVec3&) {}
void idDamageableEntityServices::SetPhysicsAxis(idDamageableEntity&,
        const idMat3&) {}
void idDamageableEntityServices::SetPieceContents(idDamageableEntity&,
        int, int) {}
void idDamageableEntityServices::SetAllContents(idDamageableEntity&, int) {}
float idDamageableEntityServices::GetPhysicsFloor(
        const idDamageableEntity& entity) const {
    return GetPhysicsBounds(entity)[0].z;
}
idBounds idDamageableEntityServices::GetPhysicsBounds(
        const idDamageableEntity& entity) const {
    idBounds bounds;
    bounds[0] = entity.origin;
    bounds[1] = entity.origin;
    return bounds;
}
idVec3 idDamageableEntityServices::GetLinearVelocity(
        const idDamageableEntity& entity) const {
    return entity.linearVelocity;
}
void idDamageableEntityServices::ActivateNearbyPhysics(
        idDamageableEntity&, const idBounds&) {}
void idDamageableEntityServices::InitializeBreakablePhysics(
        idDamageableEntity&, idRenderModelDiscreteAnimation*, int) {}
void idDamageableEntityServices::ResetBreakablePhysics(
        idDamageableEntity&) {}
void idDamageableEntityServices::UpdateBreakableSimulation(
        idDamageableEntity&, const idVec3&, const idMat3&, int, int, int,
        float) {}
void idDamageableEntityServices::UpdateBreakableModel(
        idDamageableEntity&, const idVec3&, const idMat3&, int) {}
bool idDamageableEntityServices::ActivateAllBreakable(
        idDamageableEntity&, const idVec3&, const idMat3&) { return false; }
bool idDamageableEntityServices::ActivateFloatingPieces(
        idDamageableEntity&, const idVec3&, const idMat3&, float) {
    return false;
}
void idDamageableEntityServices::StartBreakableExplosions(
        idDamageableEntity&, const idVec3&, const idMat3&, int) {}
void idDamageableEntityServices::AddRayImpact(idDamageableEntity&, int,
        const idVec3&, const idMat3&, const idVec3&, const idVec3&) {}
void idDamageableEntityServices::AddRadiusImpact(idDamageableEntity&, int,
        const idVec3&, float, float) {}
void idDamageableEntityServices::AddExplosion(idDamageableEntity&, int,
        const idDamageableExplosionInfo&) {}
void idDamageableEntityServices::EmitSmokeForEachPiece(
        idDamageableEntity&, const idDeclParticle*, int) {}
void idDamageableEntityServices::DrawBreakableCollision(
        idDamageableEntity&, int, const idVec3&, const idMat3&) {}
void idDamageableEntityServices::RegisterBreakableSimulation(
        idDamageableEntity&) {}
void idDamageableEntityServices::UnregisterBreakableSimulation(
        idDamageableEntity&) {}
void idDamageableEntityServices::InitializeDebris(
        idDamageableEntity&, const idDeclBreakable*) {}
void idDamageableEntityServices::EmitDebris(idDamageableEntity&,
        const idVec3&, const idVec3&, const idVec3&, int, int) {}
void idDamageableEntityServices::UpdateDebris(idDamageableEntity&,
        const idVec3&, const idMat3&, const idVec3&, int, int) {}
void idDamageableEntityServices::ResetDebris(idDamageableEntity&) {}
void idDamageableEntityServices::RegisterDebrisSimulation(
        idDamageableEntity&) {}
void idDamageableEntityServices::UnregisterDebrisSimulation(
        idDamageableEntity&) {}
void idDamageableEntityServices::ActivateTargets(idDamageableEntity&,
        idEntity*) {}
void idDamageableEntityServices::StartPresentableExplosions(
        idDamageableEntity&) {}
void idDamageableEntityServices::ActivateAllPresentable(
        idDamageableEntity&) {}
void idDamageableEntityServices::AddPresentableRayImpact(
        idDamageableEntity&, const idVec3&, const idVec3&) {}
void idDamageableEntityServices::SetModelFade(idDamageableEntity&, float) {}
float idDamageableEntityServices::GetModelFade(
        const idDamageableEntity&) const { return 1.0f; }
void idDamageableEntityServices::HidePresentable(idDamageableEntity&) {}
void idDamageableEntityServices::PlaySound(idDamageableEntity&,
        const idSoundShader*, int) {}
void idDamageableEntityServices::AddParticle(idDamageableEntity&,
        const idDeclParticle*, int, float, const idVec3&, const idMat3&) {}
void idDamageableEntityServices::AddDamagedAIEvent(idDamageableEntity&,
        const idDeclAiEvent*, idEntity*, int, const idVec3&, int) {}
void idDamageableEntityServices::SetOrigin(idDamageableEntity&,
        const idVec3&) {}
void idDamageableEntityServices::SetAxis(idDamageableEntity&,
        const idMat3&) {}
void idDamageableEntityServices::RunPhysics(idDamageableEntity&) {}
void idDamageableEntityServices::UpdateFX(idDamageableEntity&) {}
void idDamageableEntityServices::UpdatePVSAreas(idDamageableEntity&) {}
void idDamageableEntityServices::UpdateVisuals(idDamageableEntity&) {}
bool idDamageableEntityServices::IsPresentableAnimating(
        const idDamageableEntity&) const { return false; }
void idDamageableEntityServices::BecomeActive(idDamageableEntity&, int) {}
void idDamageableEntityServices::BecomeInactive(idDamageableEntity&, int) {}
void idDamageableEntityServices::ForceDormancy(idDamageableEntity&, bool,
        int) {}
void idDamageableEntityServices::NotifyProgressionOwner(
        idDamageableEntity&) {}
void idDamageableEntityServices::UnlinkMainClip(idDamageableEntity&) {}
void idDamageableEntityServices::InternalApplyRadiusDamage(
        idDamageableEntity&, const idEntity*, const idEntity*,
        const idDeclDamage*, const idVec3&, float, float, float,
        bool, bool) {}
float idDamageableEntityServices::GetDamageablePowerBase() const {
    return 600.0f;
}
float idDamageableEntityServices::GetDamageablePowerScale() const {
    return 8.0f;
}
float idDamageableEntityServices::GetBreakableExplosionImpulseScale() const {
    return -1.0f;
}
int idDamageableEntityServices::GetShowBreakableCollision() const {
    return 0;
}
bool idDamageableEntityServices::GetDebugBreakableIslands() const {
    return false;
}
bool idDamageableEntityServices::IsPlayerWithinDebugDistance(
        const idDamageableEntity&, float) const { return false; }
void idDamageableEntityServices::ReleaseClipModel(
        idClipModel*& clipModel) { clipModel = nullptr; }

void idDamageableEntity::SetServices(
        idDamageableEntityServices* const services) {
    damageableEntityServices = services == nullptr
        ? &defaultDamageableEntityServices : services;
}

idDamageableEntityServices& idDamageableEntity::Services() {
    return *damageableEntityServices;
}

// Retail: 0x82C1C290 ?DormantBegin@idDamageableEntity@@EAAXXZ
void idDamageableEntity::DormantBegin() {
    Services().DormantBegin(*this);
    // The optimized retail expression reduces to state == DEAD.
    if (state == DEAD) {
        removed = true;
        Services().PostRemove(*this);
    }
}

// Retail: 0x82C1C2F8 ?GetModelTransform@idDamageableEntity@@UBAXAAVidVec3@@AAVidMat3@@@Z
void idDamageableEntity::GetModelTransform(
        idVec3& modelOrigin, idMat3& modelAxis) const {
    Services().GetModelTransform(*this, modelOrigin, modelAxis);
}

// Retail: 0x82C1C300 ?Collide@idDamageableEntity@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
int idDamageableEntity::Collide(const int physicsId,
        trace_t* const collision, const idVec3& velocity) {
    lastBump = Services().GetGameMilliseconds();
    return Services().BaseCollide(*this, physicsId, collision, velocity);
}

// Retail: 0x82C1C358 ?IsTargetLockable@idDamageableEntity@@UBA_NPBVidDeclAmmo@@@Z
bool idDamageableEntity::IsTargetLockable(const idDeclAmmo*) const {
    if (Services().IsMultiplayer() && !targetable) {
        return false;
    }
    return state == READY_TO_BREAK || state == BREAKING;
}

// Retail: 0x82C1C3F8 ??1idDamageableEntity@@UAA@XZ
idDamageableEntity::~idDamageableEntity() {
    if (debrisSimulationRegistered) {
        Services().UnregisterDebrisSimulation(*this);
        debrisSimulationRegistered = false;
    }
    if (breakableSimulationRegistered) {
        Services().UnregisterBreakableSimulation(*this);
        breakableSimulationRegistered = false;
    }
    Services().ResetBreakablePhysics(*this);
    Services().UnlinkPhysics(*this);
    if (physicsObj != nullptr) {
        Services().DetachPhysics(*this);
        Services().DestroyPhysics(physicsObj);
        physicsObj = nullptr;
    }
}

// Retail: 0x82C1C5B8 ?AllocPresentable@idDamageableEntity@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
idPresentable* idDamageableEntity::AllocPresentable(
        idRenderModel* const model) {
    return Services().AllocatePresentable(*this, model,
        impactSoundTable, pieceMinBounceVelocity);
}

// Retail: 0x82C1C670 ?SetupRigidBodyPhysics@idDamageableEntity@@AAAXXZ
void idDamageableEntity::SetupRigidBodyPhysics() {
    if (physicsObj != nullptr) {
        Services().DetachPhysics(*this);
        Services().DestroyPhysics(physicsObj);
        physicsObj = nullptr;
    }

    idDamageableRigidBodySettings settings;
    settings.density = density;
    settings.moveable = moveable;
    settings.barrelCollision = barrelCollision;
    settings.clipMask = moveable ? 37953 : 1;
    if (breakableModel != nullptr) {
        Services().GetBreakableFriction(breakableModel, settings);
    }
    physicsObj = Services().CreateRigidBody(*this, settings);
    physicsType = DAMAGEABLE_PHYSICS_RIGID_BODY;
    Services().AttachPhysics(*this, physicsObj);
    Services().PutPhysicsToRest(*this);
}

// Retail: 0x82C1C870 ?ThrowDebris@idDamageableEntity@@AAAXABVidVec3@@00H@Z
void idDamageableEntity::ThrowDebris(const idVec3& position,
        const idVec3& hitVelocity, const idVec3& normal,
        const int count) {
    if (breakableDebris == nullptr || Services().RandomFloat() <= 0.75f) {
        return;
    }
    Services().EmitDebris(*this, position, hitVelocity * 0.25f,
        normal, count, Services().GetGameMilliseconds());
}

// Retail: 0x82C1C980 ?StartExplosions@idDamageableEntity@@AAAXXZ
void idDamageableEntity::StartExplosions() {
    if (!explosionsStarted) {
        Services().ActivateTargets(*this,
            reinterpret_cast<idEntity*>(this));
        Services().StartBreakableExplosions(*this, origin, axis,
            Services().GetGameMilliseconds());
        explosionsStarted = true;
        Services().StartPresentableExplosions(*this);
    }
    if (state == BREAKING) {
        state = BROKEN;
    }
}

// Retail: 0x82C1CA80 ?ReorientSwap@idDamageableEntity@@AAAXABVidVec3@@@Z
void idDamageableEntity::ReorientSwap(const idVec3& spot) {
    if (!reorientOnSwap || spot.LengthSqr() == 0.0f) {
        return;
    }
    idVec3 forward(spot.x - origin.x, spot.y - origin.y, 0.0f);
    if (forward.NormalizeFast() == 0.0f) {
        return;
    }
    idMat3 orientation(1.0f);
    orientation[0] = forward;
    orientation[2].Set(0.0f, 0.0f, 1.0f);
    orientation[1] = orientation[2].Cross(forward);
    SetAxis(orientation * axis);
}

// Retail: 0x82C1CBA0 ?ActivateAll@idDamageableEntity@@AAAXXZ
void idDamageableEntity::ActivateAll() {
    if (!Services().ActivateAllBreakable(*this, origin, axis)) {
        return;
    }
    for (int index = 0; index < pieces.Num(); ++index) {
        pieces[index].active = true;
        pieces[index].settled = false;
    }
    Services().ActivateAllPresentable(*this);
    Services().PlaySound(*this, sndCrumble, 0);
    if (destroyParticle != nullptr) {
        Services().AddParticle(*this, destroyParticle,
            Services().GetGameMilliseconds(), Services().RandomFloat(),
            origin, axis);
    }
}

// Retail: 0x82C1CD80 ?UpdateBreakableSim@idDamageableEntity@@AAAXXZ
void idDamageableEntity::UpdateBreakableSim() {
    const int currentTime = Services().GetGameMilliseconds();
    Services().UpdateBreakableSimulation(*this, origin, axis,
        currentTime, Services().GetGameMillisecondsPerFrame(),
        Services().GetGameFrame(),
        Services().GetRealMillisecondsPerFrame());
    Services().UpdateBreakableModel(*this, origin, axis, currentTime);
}

// Retail: 0x82C1CE78 ?Event_Kill@idDamageableEntity@@AAA?AVeventVoid@@XZ
void idDamageableEntity::Event_Kill() {
    const idDeclDamage* const suicideDamage = Services().GetSuicideDamage();
    if (health > 0.0f && suicideDamage != nullptr) {
        const idVec3 zero(0.0f, 0.0f, 0.0f);
        Damage(nullptr, nullptr, suicideDamage, 1.0f, zero, nullptr);
    }
}

// Retail: 0x82C1CF00 ??0idDamageableEntity@@QAA@XZ
idDamageableEntity::idDamageableEntity()
    : health(20.0f), healthMax(20.0f), physicsObj(nullptr),
      initialModel(nullptr), useRigidBody(true), useStaticMulti(false),
      sndBreak(nullptr), sndCrumble(nullptr), impactSoundTable(nullptr),
      pieceMinBounceVelocity(40.0f), armorValue(0),
      radiusDamageKills(false), reorientOnSwap(false), fadeTime(3000),
      maxSimulationTime(14000), fadeParticle(nullptr),
      swapParticle(nullptr), destroyParticle(nullptr),
      damagedAiEventDecl(nullptr), collideIgnoreImpulse(3500),
      destructionPercent(0.85f), noClipPercent(0.65f),
      resistPercent(0.6f), secondBlastScale(0.0f), density(0.003f),
      hitsTaken(0), breakableTime(0), explosionsStarted(false),
      moveable(false), barrelCollision(false), targetable(false),
      deadClipModel(nullptr), breakableDebris(nullptr),
      debrisScale(1.0f, 1.0f, 1.0f), staticVehicleCollisions(false),
      state(UNBREAKABLE), breakableModel(nullptr), renderModel(nullptr),
      fadeStartTime(0), fadeEndTime(0), lastBump(0),
      resetWhenDormant(false), breakImmediately(false),
      playerOwnerSpawnId(0x1FFF), origin(0.0f, 0.0f, 0.0f),
      axis(1.0f), spawnPosition(0.0f, 0.0f, 0.0f),
      spawnOrientation(1.0f), linearVelocity(0.0f, 0.0f, 0.0f),
      physicsType(DAMAGEABLE_PHYSICS_STATIC), pieces(), thinkFlags(0),
      removed(false), hidden(false), mainClipLinked(true),
      debrisInitialized(false), breakableInitialized(false),
      debrisSimulationRegistered(false),
      breakableSimulationRegistered(false) {
}

// Retail: 0x82C1D128 ?SetupStaticMultiPhysics@idDamageableEntity@@AAAXXZ
void idDamageableEntity::SetupStaticMultiPhysics() {
    if (breakableModel == nullptr) {
        return;
    }
    if (physicsObj != nullptr) {
        Services().DetachPhysics(*this);
        Services().DestroyPhysics(physicsObj);
        physicsObj = nullptr;
    }
    const int pieceCount = std::max(0,
        Services().GetBreakablePieceCount(breakableModel));
    pieces.SetNum(pieceCount);
    physicsObj = Services().CreateStaticMulti(
        *this, pieceCount, density);
    for (int index = 0; index < pieceCount; ++index) {
        pieces[index] = idDamageablePieceState();
        pieces[index].contents = CONTENTS_STATIC_MULTI_PIECE;
        Services().AddStaticMultiPiece(
            *this, physicsObj, index, density);
    }
    Services().AddStaticMultiAggregate(
        *this, physicsObj, pieceCount, density);
    physicsType = DAMAGEABLE_PHYSICS_STATIC_MULTI;
    Services().AttachPhysics(*this, physicsObj);
    Services().PutPhysicsToRest(*this);
}

// Retail: 0x82C1D590 ?AllSettled@idDamageableEntity@@AAA_NXZ
bool idDamageableEntity::AllSettled() const {
    for (int index = 0; index < pieces.Num(); ++index) {
        if (!pieces[index].settled) {
            return false;
        }
    }
    return true;
}

// Retail: 0x82C1D5D8 ?DeactivatePhysics@idDamageableEntity@@UAAXH@Z
void idDamageableEntity::DeactivatePhysics(int) {
    for (int index = 0; index < pieces.Num(); ++index) {
        if (pieces[index].active) {
            return;
        }
    }
    Services().PutPhysicsToRest(*this);
    if (state != DEAD) {
        thinkFlags &= ~DAMAGEABLE_THINK_PHYSICS;
        Services().BecomeInactive(*this, DAMAGEABLE_THINK_PHYSICS);
    }
}

void idDamageableEntity::SetPieceContents(
        const int pieceIndex, const int contents) {
    if (pieceIndex >= 0 && pieceIndex < pieces.Num()) {
        pieces[pieceIndex].contents = contents;
    }
    Services().SetPieceContents(*this, pieceIndex, contents);
}

void idDamageableEntity::SetAllPieceContents(const int contents) {
    for (int index = 0; index < pieces.Num(); ++index) {
        pieces[index].contents = contents;
    }
    Services().SetAllContents(*this, contents);
}

// Retail: 0x82C1D680 ?CheckDamagedPieces@idDamageableEntity@@AAAXXZ
void idDamageableEntity::CheckDamagedPieces() {
    if (state == BREAKABLE) {
        return;
    }
    const int oldHitsTaken = hitsTaken;
    const int maximumPasses = std::max(1, pieces.Num() + 1);
    for (int pass = 0; pass < maximumPasses; ++pass) {
        hitsTaken = 0;
        for (int index = 0; index < pieces.Num(); ++index) {
            if (pieces[index].active) {
                SetPieceContents(index, 0);
                ++hitsTaken;
            }
        }
        if (!Services().ActivateFloatingPieces(*this, origin, axis,
                Services().GetPhysicsFloor(*this))) {
            break;
        }
    }
    if (hitsTaken > oldHitsTaken) {
        thinkFlags |= DAMAGEABLE_THINK_PHYSICS;
        Services().BecomeActive(*this, DAMAGEABLE_THINK_PHYSICS);
        Services().PlaySound(*this, sndBreak, 1);
        breakableTime = Services().GetGameMilliseconds()
            + static_cast<int>(Services().GetBreakableAnimationSeconds(
                breakableModel) * 1000.0f);
    }
}

// Retail: 0x82C1D860 ?SetOrigin@idDamageableEntity@@UAAXABVidVec3@@@Z
void idDamageableEntity::SetOrigin(const idVec3& newOrigin) {
    origin = newOrigin;
    Services().SetOrigin(*this, newOrigin);
    UpdateBreakableSim();
}

// Retail: 0x82C1D898 ?SetAxis@idDamageableEntity@@UAAXABVidMat3@@@Z
void idDamageableEntity::SetAxis(const idMat3& newAxis) {
    axis = newAxis;
    Services().SetAxis(*this, newAxis);
    UpdateBreakableSim();
}

// Retail: 0x82C1D8D8 ?SetBreakableModel@idDamageableEntity@@AAAXXZ
void idDamageableEntity::SetBreakableModel() {
    if (state != BREAKABLE || breakableModel == nullptr) {
        return;
    }
    idRenderModel* const breakableRenderModel =
        reinterpret_cast<idRenderModel*>(breakableModel);
    if (Services().GetRenderModel(*this) != breakableRenderModel) {
        Services().SetModel(*this, breakableRenderModel);
    }
    state = READY_TO_BREAK;
    if (moveable || useRigidBody) {
        SetupRigidBodyPhysics();
    } else if (useStaticMulti) {
        SetupStaticMultiPhysics();
    } else {
        Services().ConfigureSimpleBreakablePhysics(*this, density);
        physicsType = DAMAGEABLE_PHYSICS_STATIC;
        DeactivatePhysics(0);
    }
    Services().PresentAtIdentity(*this);
}

// Retail: 0x82C1DBD0 ?BreakBreakable@idDamageableEntity@@AAA_NABVidVec3@@@Z
bool idDamageableEntity::BreakBreakable(const idVec3& source) {
    if (health >= resistPercent * healthMax) {
        return true;
    }

    Services().ActivateNearbyPhysics(*this,
        Expanded(Services().GetPhysicsBounds(*this), 16.0f));

    if (moveable && physicsType == DAMAGEABLE_PHYSICS_RIGID_BODY) {
        if (health > 0.0f) {
            return false;
        }
        if (state == BREAKABLE) {
            Services().SetModel(*this,
                reinterpret_cast<idRenderModel*>(breakableModel));
            state = READY_TO_BREAK;
            Services().PresentAtIdentity(*this);
        }
        Services().UpdateBreakableModel(*this,
            idVec3(0.0f, 0.0f, 0.0f), idMat3(1.0f),
            Services().GetGameMilliseconds());
        Services().UnlinkPhysics(*this);
        if (physicsObj != nullptr) {
            Services().DetachPhysics(*this);
            Services().DestroyPhysics(physicsObj);
            physicsObj = nullptr;
        }
        if (useStaticMulti) {
            const idVec3 savedOrigin = origin;
            const idMat3 savedAxis = axis;
            SetupStaticMultiPhysics();
            Services().SetPhysicsOrigin(*this, savedOrigin);
            Services().SetPhysicsAxis(*this, savedAxis);
        }
    }

    if (state == BREAKABLE) {
        SetBreakableModel();
    } else if (state == UNBREAKABLE && renderModel != nullptr
            && health <= 0.0f) {
        Services().SetModel(*this, renderModel);
        renderModel = nullptr;
        ReorientSwap(source);
    }

    if (state == READY_TO_BREAK
            || (state == BREAKING && health <= 0.0f)) {
        thinkFlags |= DAMAGEABLE_THINK_PHYSICS;
        Services().BecomeActive(*this, DAMAGEABLE_THINK_PHYSICS);
        state = BREAKING;
        ActivateAll();
        if (health <= 0.0f) {
            StartExplosions();
            Services().ForceDormancy(*this, false, 30000);
            Services().NotifyProgressionOwner(*this);
        }
    } else if (state == BROKEN) {
        thinkFlags |= DAMAGEABLE_THINK_PHYSICS;
        Services().BecomeActive(*this, DAMAGEABLE_THINK_PHYSICS);
    }
    return true;
}

// Retail: 0x82C1E080 ?Think@idDamageableEntity@@UAAXXZ
void idDamageableEntity::Think() {
    if (Services().UpdateDormant(*this)) {
        return;
    }
    Services().RunPhysics(*this);
    Services().UpdateFX(*this);
    Services().UpdatePVSAreas(*this);

    const int currentTime = Services().GetGameMilliseconds();
    bool simulationExpired = false;
    bool breakableWasSimulated = false;
    if (fadeStartTime > 0 && currentTime >= fadeStartTime) {
        if (currentTime < fadeEndTime) {
            const int duration = fadeEndTime - fadeStartTime;
            const float fade = duration > 0
                ? Clamp01(1.0f - static_cast<float>(
                    currentTime - fadeStartTime) / duration)
                : 0.0f;
            if (fade < 1.0f && fadeParticle != nullptr
                    && Services().GetModelFade(*this) == 1.0f) {
                Services().EmitSmokeForEachPiece(
                    *this, fadeParticle, currentTime);
            }
            Services().SetModelFade(*this, fade);
        } else {
            hidden = true;
            Services().HidePresentable(*this);
            fadeStartTime = -1;
            thinkFlags &= ~DAMAGEABLE_THINK_ALL;
            Services().BecomeInactive(*this, DAMAGEABLE_THINK_ALL);
            removed = true;
            Services().PostRemove(*this);
        }
    }

    if ((thinkFlags & DAMAGEABLE_THINK_PHYSICS) != 0) {
        if (state > READY_TO_BREAK) {
            UpdateBreakableSim();
            breakableWasSimulated = true;
            if (state == DEAD) {
                if (maxSimulationTime <= 0) {
                    simulationExpired = true;
                } else {
                    maxSimulationTime -= currentTime
                        - Services().GetPreviousGameMilliseconds();
                }
            } else {
                const int pieceCount = pieces.Num();
                if (hitsTaken == pieceCount) {
                    StartExplosions();
                    state = DEAD;
                } else if (hitsTaken >= destructionPercent * pieceCount) {
                    state = DEAD;
                    SetAllPieceContents(0);
                    hitsTaken = pieceCount;
                    StartExplosions();
                } else if (hitsTaken >= noClipPercent * pieceCount) {
                    for (int index = 0; index < pieceCount; ++index) {
                        if (!pieces[index].active) {
                            SetPieceContents(index,
                                CONTENTS_BROKEN_REMAINDER);
                        }
                    }
                }
            }
        }
        Services().UpdateDebris(*this, origin, axis, debrisScale,
            currentTime, Services().GetGameMillisecondsPerFrame());
        if (!debrisSimulationRegistered) {
            Services().RegisterDebrisSimulation(*this);
            debrisSimulationRegistered = true;
        }
    }

    if (!Services().IsPresentableAnimating(*this)
            && !breakableWasSimulated) {
        if (state != UNBREAKABLE) {
            Services().UpdateBreakableModel(
                *this, origin, axis, currentTime);
        } else {
            Services().UpdateVisuals(*this);
        }
    }

    if (swapParticle != nullptr && health <= 0.0f && state != DEAD
            && (fadeStartTime == 0 || currentTime < fadeStartTime)) {
        Services().AddParticle(*this, swapParticle, currentTime,
            Services().RandomFloat(), origin, axis);
    }

    const idVec3 velocity = Services().GetLinearVelocity(*this);
    const bool slowAndFinished = velocity.LengthSqr() < 1.0f
        && health <= 0.0f && lastBump > 0 && fadeStartTime == 0
        && (state == DEAD || state == UNBREAKABLE) && AllSettled()
        && currentTime > lastBump + 1000;
    if (simulationExpired || slowAndFinished) {
        thinkFlags &= ~DAMAGEABLE_THINK_PHYSICS;
        thinkFlags |= DAMAGEABLE_THINK_VISUAL;
        Services().BecomeInactive(*this, DAMAGEABLE_THINK_PHYSICS);
        Services().BecomeActive(*this, DAMAGEABLE_THINK_VISUAL);
        Services().ResetDebris(*this);
        if (health <= 0.0f) {
            state = DEAD;
            mainClipLinked = false;
            Services().UnlinkMainClip(*this);
            if (fadeTime >= 0) {
                fadeStartTime = currentTime + 500;
                fadeEndTime = currentTime + fadeTime + 500;
            }
        }
    }

    const int showCollision = Services().GetShowBreakableCollision();
    if (showCollision != 0
            && Services().IsPlayerWithinDebugDistance(*this, 1000.0f)) {
        Services().DrawBreakableCollision(*this,
            showCollision >= 0 ? -1 : -1 - showCollision, origin, axis);
    }
    if (Services().GetDebugBreakableIslands() && physicsObj != nullptr) {
        Services().ActivateFloatingPieces(*this, origin, axis,
            Services().GetPhysicsFloor(*this));
    }
    if ((state == BREAKING && useStaticMulti) || state != UNBREAKABLE) {
        Services().RegisterBreakableSimulation(*this);
        breakableSimulationRegistered = true;
    }
}

// Retail: 0x82C1ECC0 ?ApplyRadiusDamage@idDamageableEntity@@QAAXPBVidEntity@@0PBVidDeclDamage@@ABVidVec3@@MMM@Z
void idDamageableEntity::ApplyRadiusDamage(const idEntity* const inflictor,
        const idEntity* const attacker, const idDeclDamage* const damage,
        const idVec3& position, const float damageScale,
        const float radiusScale, const float radius) {
    if (damage == nullptr) {
        return;
    }
    const float amount = Services().GetDamageAmount(damage) * damageScale;
    const bool radiusKills = health > 0.0f && radiusDamageKills
        && amount > static_cast<float>(armorValue) * 0.5f;
    const bool shouldBreak = state != UNBREAKABLE
        && health < resistPercent * healthMax;
    Services().InternalApplyRadiusDamage(*this, inflictor, attacker,
        damage, position, damageScale, radiusScale, radius,
        radiusKills, shouldBreak);
    if (radiusKills) {
        health = 0.0f;
        if (state != UNBREAKABLE) {
            StartExplosions();
        }
    }
    if (!shouldBreak) {
        return;
    }

    BreakBreakable(position);
    const float powerBase = health > 0.0f
        ? Services().GetDamageablePowerBase()
        : Services().GetDamageablePowerBase()
            + std::max(amount - 1000.0f, 0.0f);
    const float power = powerBase * Services().GetDamageablePowerScale();
    const int currentTime = Services().GetGameMilliseconds();
    Services().AddRadiusImpact(*this, currentTime,
        position, radius, power);
    if (health <= 0.0f) {
        float secondScale =
            Services().GetBreakableExplosionImpulseScale();
        if (secondScale == -1.0f) {
            secondScale = secondBlastScale;
        }
        idDamageableExplosionInfo explosion;
        explosion.position = position;
        explosion.radius = radius;
        explosion.impulse = secondScale * power;
        Services().AddExplosion(*this, currentTime, explosion);
    }
    CheckDamagedPieces();
}

// Retail: 0x82C1EF58 ?Spawn@idDamageableEntity@@QAAXXZ
void idDamageableEntity::Spawn() {
    idRenderModel* const currentModel = Services().GetRenderModel(*this);
    if (currentModel != nullptr) {
        if (initialModel != nullptr) {
            idRenderModel* const allocatedModel =
                Services().AllocateRenderModelCopy(currentModel);
            idRenderModelDiscreteAnimation* const allocatedBreakable =
                Services().AsBreakableModel(allocatedModel);
            if (allocatedBreakable != nullptr) {
                breakableModel = allocatedBreakable;
                state = BREAKABLE;
            } else {
                renderModel = allocatedModel;
                state = UNBREAKABLE;
            }
            Services().SetModel(*this, initialModel);
        } else {
            idRenderModelDiscreteAnimation* const currentBreakable =
                Services().AsBreakableModel(currentModel);
            if (currentBreakable != nullptr
                    && Services().HasBreakableDeclaration(
                        currentBreakable)) {
                breakableModel = currentBreakable;
                state = BREAKABLE;
                SetBreakableModel();
            } else {
                breakableModel = nullptr;
            }
        }
    }

    if (state != READY_TO_BREAK) {
        if (useRigidBody || moveable) {
            SetupRigidBodyPhysics();
        } else if (state != UNBREAKABLE) {
            Services().ConfigureSimpleBreakablePhysics(*this, density);
            physicsType = DAMAGEABLE_PHYSICS_STATIC;
            DeactivatePhysics(0);
        }
    }

    if (state != UNBREAKABLE) {
        const int pieceCount = std::max(0,
            Services().GetBreakablePieceCount(breakableModel));
        pieces.SetNum(pieceCount);
        for (int index = 0; index < pieceCount; ++index) {
            pieces[index] = idDamageablePieceState();
        }
        Services().InitializeBreakablePhysics(
            *this, breakableModel, pieceCount);
        breakableInitialized = true;
    }
    healthMax = health;
    if (breakableDebris != nullptr) {
        Services().InitializeDebris(*this, breakableDebris);
        debrisInitialized = true;
    }
    SetAxis(spawnOrientation);
    SetOrigin(spawnPosition);
    Services().ConfigurePresentableClip(*this,
        state == UNBREAKABLE ? 0 : CONTENTS_BREAKABLE);
}

// Retail: 0x82C1F3E4 $LN88
void DamageableEntityAllocationCleanup(idClipModel*& clipModel) {
    idDamageableEntity::Services().ReleaseClipModel(clipModel);
}

void idDamageableEntity::AddRayDamageImpact(const int currentTime,
        const idVec3& start, const idVec3& end) {
    Services().AddRayImpact(*this, currentTime,
        origin, axis, start, end);
    Services().AddPresentableRayImpact(*this, start, end);
}

// Retail: 0x82C1F410 ?Damage@idDamageableEntity@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
float idDamageableEntity::Damage(idEntity* inflictor,
        idEntity* attacker, const idDeclDamage* const damage,
        const float damageScale, const idVec3& direction,
        trace_t* const trace) {
    if (!Services().TakesDamage(*this) || damage == nullptr) {
        return 0.0f;
    }
    if (armorValue > 0
            && Services().DamageIgnoresArmoredBreakables(damage)) {
        return 0.0f;
    }
    if (inflictor == nullptr) {
        inflictor = Services().GetWorldEntity();
    }
    if (attacker == nullptr) {
        attacker = Services().GetWorldEntity();
    }
    const float amount = std::max(0.0f,
        Services().GetDamageAmount(damage) * damageScale
            - static_cast<float>(armorValue));
    Services().DamageFeedback(attacker, *this,
        inflictor, damage, amount);
    const int currentTime = Services().GetGameMilliseconds();
    lastBump = currentTime;

    idDamageableTraceInfo traceInfo;
    Services().GetTraceInfo(trace, traceInfo);
    if (amount != 0.0f) {
        health -= amount;
        if (health <= 0.0f || health < resistPercent * healthMax) {
            const idVec3 source = traceInfo.valid
                ? traceInfo.point : idVec3(0.0f, 0.0f, 0.0f);
            if (!BreakBreakable(source)) {
                return amount;
            }
            if (state != UNBREAKABLE) {
                if (!traceInfo.valid) {
                    CheckDamagedPieces();
                    return amount;
                }
                if (!(attacker == inflictor
                        && Services().IsVehicle(inflictor))
                        && (physicsType == DAMAGEABLE_PHYSICS_STATIC_MULTI
                            || physicsType
                                == DAMAGEABLE_PHYSICS_RIGID_BODY)) {
                    float rayScale = density != 0.0f
                        ? amount / (density * 5000.0f) : 0.0f;
                    if (Services().DamageIsMelee(damage)) {
                        rayScale *= 0.2f;
                    }
                    AddRayDamageImpact(currentTime, traceInfo.point,
                        traceInfo.point + direction * rayScale);
                    CheckDamagedPieces();
                    ThrowDebris(traceInfo.point,
                        direction * (amount + 10.0f),
                        traceInfo.normal, 1);
                    Services().AddDamagedAIEvent(*this,
                        damagedAiEventDecl, attacker, currentTime,
                        origin, 400);
                    return amount;
                }
            }
        }
    }

    if (traceInfo.valid) {
        if (state != UNBREAKABLE) {
            AddRayDamageImpact(currentTime,
                traceInfo.point, traceInfo.point);
        }
        ThrowDebris(traceInfo.point, direction * (amount + 10.0f),
            traceInfo.normal, 1);
    }
    return amount;
}
