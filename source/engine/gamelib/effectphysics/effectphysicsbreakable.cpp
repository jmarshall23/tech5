#include "gamelib/effectphysics/effectphysicsbreakable.h"

#include "gamelib/physics/physics.h"
#include "gamelib/physics/tracemodelcache.h"
#include "idlib/geometry/tracemodel.h"

#include <algorithm>
#include <cmath>

int GameLib_DiscreteAnimationPieceCount(
    const idRenderModelDiscreteAnimation* model);
const idDeclBreakable* GameLib_DiscreteAnimationDecl(
    const idRenderModelDiscreteAnimation* model);
bool GameLib_DiscreteAnimationGetPiece(
    const idRenderModelDiscreteAnimation* model, int index,
    idVec3& position, idMat3& orientation, idTraceModel& traceModel,
    const idMaterial*& material);
void GameLib_DiscreteAnimationSetPiece(idRenderModelDiscreteAnimation* model,
    int index, const idVec3& position, const idMat3& orientation);
void GameLib_DiscreteAnimationCollapsePiece(
    idRenderModelDiscreteAnimation* model, int index);
void GameLib_DiscreteAnimationReset(idRenderModelDiscreteAnimation* model);
void GameLib_DiscreteAnimationUpdate(idRenderModelDiscreteAnimation* model);
void GameLib_DiscreteAnimationDelete(idRenderModelDiscreteAnimation* model);
bool GameLib_GetBreakablePhysicsSettings(const idDeclBreakable* decl,
    idEffectPhysicsPieceSettings& settings);
bool GameLib_GetBreakableDeclView(const idDeclBreakable* decl,
    idEffectPhysicsBreakableDeclView& view);
float GameLib_GetBreakablePieceDamageThreshold(
    const idDeclBreakable* decl, int pieceIndex);
int GameLib_StartBreakableExplosion(idGameLibEffects* effects,
    const idBreakableExplosion& explosion, const idVec3& position,
    const idMat3& axis, int startTime, float effectScale);
void GameLib_StopBreakableExplosion(idGameLibEffects* effects, int handle);
void GameLib_EmitBreakableParticle(idGameLibEffects* effects,
    const idDeclParticle* particle, const idVec3& position,
    const idVec3& velocity, int startTime);
void GameLib_EmitBreakableTrail(idGameLibEffects* effects,
    const idBreakableTrail& trail, int pieceIndex, const idVec3& position,
    const idVec3& velocity, int currentTime);
void GameLib_EmitBreakableDecal(idGameLibEffects* effects,
    const idBreakableDecal& decal, int pieceIndex,
    const idEffectPhysicsCollision& collision, int currentTime);
void GameLib_EmitBreakableSpark(idGameLibEffects* effects,
    const idMaterial* material, float size, const idVec3& position,
    const idVec3& velocity, int currentTime);
void GameLib_PlayBreakableCollision(
    idEffectPhysicsBreakable::breakablePieceSound_t& soundInfo,
    const idEffectPhysicsCollision& collision, const idVec3& origin,
    float velocitySqr, int currentTime);
void GameLib_DrawEffectTraceModel(const idTraceModelCache* cache,
    int traceModelIndex, int pieceIndex, const idVec3& origin,
    const idMat3& axis);

namespace {

float Clamp01(const float value) {
    return (std::max)(0.0f, (std::min)(1.0f, value));
}

} // namespace

idEffectPhysicsBreakable::idEffectPhysicsBreakable()
    : properties(0)
    , rigidBodies(0)
    , collisions(0)
    , basePiece(nullptr)
    , explosions(0)
    , explosionFX(0)
    , trails(0)
    , damage(0)
    , particles(0)
    , decals(0)
    , sparks(0)
    , pieceActivationTimes(0)
    , broadPhase()
    , random(0)
    , gameLibEffects(nullptr)
    , model(nullptr)
    , decl(nullptr)
    , soundInfo{nullptr, nullptr, 0, nullptr, 0, 0.0f} {
}

idEffectPhysicsBreakable::~idEffectPhysicsBreakable() {
    RemoveExplosions();
    if (broadPhase.traceModelCache != nullptr) {
        for (int index = 0; index < properties.Num(); ++index) {
            if (properties[index] != nullptr) {
                broadPhase.traceModelCache->FreeTraceModel(
                    properties[index]->traceModelIndex);
            }
        }
    }
    for (int index = 0; index < rigidBodies.Num(); ++index) {
        delete rigidBodies[index];
    }
    for (int index = 0; index < properties.Num(); ++index) {
        delete properties[index];
    }
    rigidBodies.ClearFree();
    properties.ClearFree();
    if (model != nullptr) {
        GameLib_DiscreteAnimationDelete(model);
        model = nullptr;
    }
}

idEffectPhysicsProperties*
idEffectPhysicsBreakable::GetPropertiesForTraceModel(
    const idTraceModel& traceModel, const idMaterial* const material) {
    if (broadPhase.traceModelCache == nullptr) {
        return nullptr;
    }
    const int traceModelIndex = broadPhase.traceModelCache->AllocTraceModel(
        traceModel, material);
    for (int index = 0; index < properties.Num(); ++index) {
        if (properties[index]->traceModelIndex == traceModelIndex) {
            broadPhase.traceModelCache->FreeTraceModel(traceModelIndex);
            return properties[index];
        }
    }
    idEffectPhysicsProperties* const result =
        new idEffectPhysicsProperties();
    result->Setup(&broadPhase, traceModelIndex, 10.0f);
    idEffectPhysicsPieceSettings settings{};
    if (decl != nullptr &&
        GameLib_GetBreakablePhysicsSettings(decl, settings)) {
        result->linearFriction = settings.linearFriction;
        result->angularFriction = settings.angularFriction;
        result->contactFriction = settings.contactFriction;
        result->linearFrictionWater = settings.linearFrictionWater;
        result->angularFrictionWater = settings.angularFrictionWater;
        result->bouncyness = settings.bouncyness;
        result->gravityVector = settings.gravityVector;
        result->worldCollisionOnly = settings.worldCollisionOnly;
        result->simplePointCollision = settings.simplePointCollision;
        result->crazyBounceChance = settings.crazyBounceChance;
        result->stopSpeed = settings.stopSpeed;
        result->maxLinearVelocity = settings.maxLinearVelocity;
        result->maxAngularVelocity = settings.maxAngularVelocity;
        result->clipMask = settings.clipMask;
    }
    properties.Append(result);
    return result;
}

void idEffectPhysicsBreakable::Init(idClip* const clip,
    idTraceModelCache* const traceModelCache,
    idGameLibEffects* const effects,
    idRenderModelDiscreteAnimation* const renderModel,
    const int entityNumber, const breakablePieceSound_t* const sound) {
    broadPhase.Init(clip, traceModelCache);
    gameLibEffects = effects;
    model = renderModel;
    decl = renderModel != nullptr
        ? GameLib_DiscreteAnimationDecl(renderModel) : nullptr;
    if (sound != nullptr) {
        soundInfo = *sound;
    }

    for (int index = 0; index < rigidBodies.Num(); ++index) {
        delete rigidBodies[index];
    }
    rigidBodies.Clear();
    collisions.Clear();
    const int pieceCount = renderModel != nullptr
        ? GameLib_DiscreteAnimationPieceCount(renderModel) : 0;
    rigidBodies.SetNum((std::max)(0, pieceCount));
    collisions.SetNum(rigidBodies.Num());
    damage.SetNum(rigidBodies.Num());
    pieceActivationTimes.SetNum(rigidBodies.Num());

    for (int index = 0; index < rigidBodies.Num(); ++index) {
        rigidBodies[index] = nullptr;
        collisions[index].Clear();
        damage[index] = 0.0f;
        pieceActivationTimes[index] = 0;
        idVec3 position;
        idMat3 orientation(1.0f);
        idTraceModel traceModel;
        const idMaterial* material = nullptr;
        if (!GameLib_DiscreteAnimationGetPiece(renderModel, index,
                position, orientation, traceModel, material)) {
            continue;
        }
        traceModel.Shrink(0.1875f);
        idEffectPhysicsProperties* const pieceProperties =
            GetPropertiesForTraceModel(traceModel, material);
        if (pieceProperties == nullptr) {
            continue;
        }
        rigidBodies[index] = new idEffectPhysicsRigidBody();
        rigidBodies[index]->Setup(pieceProperties);
        rigidBodies[index]->SetPosition(position, orientation);
        rigidBodies[index]->SPObject.entityNum = entityNumber;
    }
    InitExplosionsAndTrails(sound, effects, random.RandomFloat());
}

void idEffectPhysicsBreakable::InitExplosionsAndTrails(
    const breakablePieceSound_t* const sound, idGameLibEffects* const effects,
    const float diversity) {
    (void)diversity;
    gameLibEffects = effects;
    if (sound != nullptr) {
        soundInfo = *sound;
    }
    explosions.Clear();
    explosionFX.Clear();
    trails.Clear();
    decals.Clear();
    sparks.Clear();

    idEffectPhysicsBreakableDeclView view;
    if (decl == nullptr || !GameLib_GetBreakableDeclView(decl, view)) {
        return;
    }
    explosions.SetNum(view.explosions.Num());
    explosionFX.SetNum(view.explosions.Num());
    for (int index = 0; index < explosions.Num(); ++index) {
        explosions[index].decl = view.explosions[index];
        explosions[index].startTime = 0;
        explosions[index].fxIndex = -1;
        explosions[index].worldPosition.Zero();
        explosions[index].effectsEnabled = false;
        explosions[index].forceApplied = false;
        explosions[index].localSpace = true;
        explosionFX[index] = -1;
    }
    trails.SetNum(view.trails.Num());
    for (int index = 0; index < trails.Num(); ++index) {
        trails[index].decl = view.trails[index];
        const int count = trails[index].decl.pieces.Num();
        trails[index].pieceStartTime.SetNum(count);
        trails[index].pieceLastParticleDropPos.SetNum(count);
        for (int piece = 0; piece < count; ++piece) {
            trails[index].pieceStartTime[piece] = 0;
            trails[index].pieceLastParticleDropPos[piece].Zero();
        }
    }
    decals.SetNum(view.decals.Num());
    for (int index = 0; index < decals.Num(); ++index) {
        decals[index].decl = view.decals[index];
        const int count = decals[index].decl.pieces.Num();
        decals[index].pieceStartTime.SetNum(count);
        decals[index].lastCollisionPos.SetNum(count);
        decals[index].lastCollisionNormal.SetNum(count);
        decals[index].pieceLastDecalDropPos.SetNum(count);
        for (int piece = 0; piece < count; ++piece) {
            decals[index].pieceStartTime[piece] = 0;
            decals[index].lastCollisionPos[piece].Zero();
            decals[index].lastCollisionNormal[piece].Zero();
            decals[index].pieceLastDecalDropPos[piece].Zero();
        }
    }
    if (!view.sparks.materials.IsEmpty()) {
        sparks.SetNum(rigidBodies.Num());
        for (int index = 0; index < sparks.Num(); ++index) {
            sparks[index].material = view.sparks.materials[
                random.RandomInt(view.sparks.materials.Num())];
            sparks[index].size = view.sparks.sizeMin + random.RandomFloat() *
                (view.sparks.sizeMax - view.sparks.sizeMin);
            sparks[index].velocityScale = view.sparks.velocityScaleMin +
                random.RandomFloat() * (view.sparks.velocityScaleMax -
                    view.sparks.velocityScaleMin);
        }
    }
}

void idEffectPhysicsBreakable::Reset(const bool skipModelReset) {
    if (model == nullptr) {
        return;
    }
    if (!skipModelReset) {
        GameLib_DiscreteAnimationReset(model);
    }
    random.SetSeed(0);
    for (int index = 0; index < rigidBodies.Num(); ++index) {
        idEffectPhysicsRigidBody* const body = rigidBodies[index];
        if (body == nullptr) {
            continue;
        }
        idVec3 position;
        idMat3 orientation(1.0f);
        idTraceModel ignoredTraceModel;
        const idMaterial* ignoredMaterial = nullptr;
        if (GameLib_DiscreteAnimationGetPiece(model, index, position,
                orientation, ignoredTraceModel, ignoredMaterial)) {
            body->SetPosition(position, orientation);
        }
        body->active = false;
        body->settled = false;
        body->SPObject.motion.ignore = false;
        body->currentState.linearMomentum.Zero();
        body->currentState.angularMomentum.Zero();
        collisions[index].Clear();
        damage[index] = 0.0f;
        pieceActivationTimes[index] = 0;
    }
    for (int index = 0; index < properties.Num(); ++index) {
        idEffectPhysicsPieceSettings settings{};
        if (decl != nullptr &&
            GameLib_GetBreakablePhysicsSettings(decl, settings)) {
            properties[index]->linearFriction = settings.linearFriction;
            properties[index]->angularFriction = settings.angularFriction;
            properties[index]->contactFriction = settings.contactFriction;
            properties[index]->linearFrictionWater =
                settings.linearFrictionWater;
            properties[index]->angularFrictionWater =
                settings.angularFrictionWater;
            properties[index]->bouncyness = settings.bouncyness;
            properties[index]->gravityVector = settings.gravityVector;
            properties[index]->worldCollisionOnly =
                settings.worldCollisionOnly;
            properties[index]->clipMask = settings.clipMask;
        }
    }
    RemoveExplosions();
    InitExplosionsAndTrails(&soundInfo, gameLibEffects,
        random.RandomFloat());
}

bool idEffectPhysicsBreakable::ActivateNoisy(const int pieceIndex,
    const idVec3& origin, const idMat3& axis) {
    if (pieceIndex < 0 || pieceIndex >= rigidBodies.Num() ||
        rigidBodies[pieceIndex] == nullptr) {
        return false;
    }
    idEffectPhysicsRigidBody* const body = rigidBodies[pieceIndex];
    if (body->active) {
        return false;
    }
    body->SetPosition(origin + axis * body->currentState.position,
        body->currentState.orientation * axis);
    body->active = true;
    body->settled = false;
    body->SPObject.motion.ignore = false;
    return true;
}

bool idEffectPhysicsBreakable::ActivateAllNow(const idVec3& origin,
    const idMat3& axis) {
    bool activated = false;
    for (int index = 0; index < rigidBodies.Num(); ++index) {
        activated = ActivateNoisy(index, origin, axis) || activated;
    }
    return activated;
}

bool idEffectPhysicsBreakable::ActivateFloatingPieces(const idVec3& origin,
    const idMat3& axis, const float impulse) {
    bool activated = false;
    for (int index = 0; index < rigidBodies.Num(); ++index) {
        idEffectPhysicsRigidBody* const body = rigidBodies[index];
        if (body == nullptr || body->active ||
            body->currentState.position.z <= 0.0f) {
            continue;
        }
        if (ActivateNoisy(index, origin, axis)) {
            const idVec3 direction(0.0f, 0.0f, 1.0f);
            body->ApplyImpulse(body->currentState.position,
                direction * impulse);
            activated = true;
        }
    }
    return activated;
}

void idEffectPhysicsBreakable::ApplyImpulseToBody(const int bodyIndex,
    const idPhysics* const impactPhysics, const idVec3& point,
    const idVec3& impulse) {
    if (bodyIndex < 0 || bodyIndex >= rigidBodies.Num() ||
        rigidBodies[bodyIndex] == nullptr) {
        return;
    }
    idVec3 adjustedImpulse = impulse;
    if (impactPhysics != nullptr) {
        impactInfo_t impact{};
        const_cast<idPhysics*>(impactPhysics)->GetImpactInfo(
            0, &point, &impact);
        adjustedImpulse = adjustedImpulse + impact.velocity *
            (1.0f / (impact.invMass > 0.0f ? impact.invMass : 1.0f));
    }
    rigidBodies[bodyIndex]->ApplyImpulse(point, adjustedImpulse);
    rigidBodies[bodyIndex]->active = true;
}

void idEffectPhysicsBreakable::ApplyForce(const idVec3& origin,
    const idMat3& axis, const idVec3& force) {
    (void)origin;
    (void)axis;
    for (int index = 0; index < rigidBodies.Num(); ++index) {
        if (rigidBodies[index] != nullptr && rigidBodies[index]->active) {
            rigidBodies[index]->AddForce(force);
        }
    }
}

void idEffectPhysicsBreakable::AddRadiusImpact(const int time,
    const idPhysics* const impactPhysics, const idVec3& position,
    const float radius, const float impulse) {
    const float radiusSqr = radius * radius;
    for (int index = 0; index < rigidBodies.Num(); ++index) {
        idEffectPhysicsRigidBody* const body = rigidBodies[index];
        if (body == nullptr) {
            continue;
        }
        idVec3 delta = body->currentState.position - position;
        const float distanceSqr = delta.LengthSqr();
        if (distanceSqr > radiusSqr) {
            continue;
        }
        if (!body->active) {
            body->active = true;
            pieceActivationTimes[index] = time;
        }
        const float distance = delta.NormalizeFast();
        const float falloff = radius > 0.0f
            ? Clamp01(1.0f - distance / radius) : 1.0f;
        ApplyImpulseToBody(index, impactPhysics, body->currentState.position,
            delta * (impulse * falloff));
    }
}

void idEffectPhysicsBreakable::CollideWith(const idVec3& origin,
    const idPhysics* const impactPhysics, const idVec3& point,
    const float impulseScale) {
    int nearest = -1;
    float nearestDistance = 1.0e30f;
    for (int index = 0; index < rigidBodies.Num(); ++index) {
        if (rigidBodies[index] == nullptr) {
            continue;
        }
        const float distance =
            (rigidBodies[index]->currentState.position + origin - point)
                .LengthSqr();
        if (distance < nearestDistance) {
            nearestDistance = distance;
            nearest = index;
        }
    }
    if (nearest >= 0) {
        idVec3 direction =
            rigidBodies[nearest]->currentState.position + origin - point;
        if (direction.NormalizeFast() == 0.0f) {
            direction.Set(0.0f, 0.0f, 1.0f);
        }
        ApplyImpulseToBody(nearest, impactPhysics, point,
            direction * impulseScale);
    }
}

bool idEffectPhysicsBreakable::DamagePiece(const int time,
    const int pieceIndex, const float amount, const idVec3& position) {
    (void)position;
    if (pieceIndex < 0 || pieceIndex >= damage.Num()) {
        return false;
    }
    damage[pieceIndex] += amount;
    const float threshold =
        GameLib_GetBreakablePieceDamageThreshold(decl, pieceIndex);
    if (damage[pieceIndex] < (threshold > 0.0f ? threshold : 1.0f)) {
        return false;
    }
    if (rigidBodies[pieceIndex] != nullptr) {
        rigidBodies[pieceIndex]->active = true;
        rigidBodies[pieceIndex]->settled = false;
        pieceActivationTimes[pieceIndex] = time;
    }
    return true;
}

void idEffectPhysicsBreakable::AddRayImpact(const int time,
    const idVec3& origin, const idMat3& axis, const idVec3& start,
    const idVec3& end, const bool activeOnly) {
    const idVec3 ray = end - start;
    const float rayLengthSqr = ray.LengthSqr();
    if (rayLengthSqr <= 1.0e-8f) {
        return;
    }
    for (int index = 0; index < rigidBodies.Num(); ++index) {
        idEffectPhysicsRigidBody* const body = rigidBodies[index];
        if (body == nullptr || (activeOnly && !body->active)) {
            continue;
        }
        const idVec3 piecePosition = body->active
            ? body->currentState.position
            : origin + axis * body->currentState.position;
        const float fraction = Clamp01(
            (piecePosition - start).Dot(ray) / rayLengthSqr);
        const idVec3 closest = start + ray * fraction;
        if ((piecePosition - closest).LengthSqr() > 64.0f) {
            continue;
        }
        if (!body->active) {
            ActivateNoisy(index, origin, axis);
        }
        DamagePiece(time, index, 1.0f, closest);
        idVec3 impulseDirection = ray;
        impulseDirection.NormalizeFast();
        body->ApplyImpulse(closest,
            (impulseDirection + idVec3(0.0f, 0.0f, 0.1f)) * 10.0f);
        break;
    }
}

void idEffectPhysicsBreakable::EmitSmokeForEachPiece(
    const idDeclParticle* const particle, const int time) {
    for (int index = 0; index < rigidBodies.Num(); ++index) {
        if (rigidBodies[index] == nullptr) {
            continue;
        }
        particles.Append(idBreakableParticle{
            particle, rigidBodies[index]->currentState.position, time});
        GameLib_EmitBreakableParticle(gameLibEffects, particle,
            rigidBodies[index]->currentState.position,
            idVec3(0.0f, 0.0f, 0.0f), time);
    }
}

void idEffectPhysicsBreakable::AddExplosion(
    const idDeclParticle* const particle, const int time,
    const idVec3& position, const float radius, const float impulse,
    const float falloff, const float angular, const int delay,
    const int duration, const bool localSpace, const int activateAllDelay,
    const float distanceDelayScale, const idVec3& endLinear,
    const float effectScale) {
    idExplosion explosion{};
    explosion.decl.particle = particle;
    explosion.decl.position = position;
    explosion.decl.radius = radius;
    explosion.decl.impulse = impulse;
    explosion.decl.falloff = falloff;
    explosion.decl.angular = angular;
    explosion.decl.delay = delay;
    explosion.decl.duration = duration;
    explosion.decl.activateAllDelay = activateAllDelay;
    explosion.decl.distTimeScaleDelay = distanceDelayScale;
    explosion.decl.endLinear = endLinear;
    explosion.startTime = time + delay;
    explosion.fxIndex = -1;
    explosion.worldPosition = position;
    explosion.effectsEnabled = effectScale > 0.0f;
    explosion.forceApplied = false;
    explosion.localSpace = localSpace;
    explosions.Append(explosion);
    explosionFX.Append(-1);
}

void idEffectPhysicsBreakable::StartExplosions(const idVec3& origin,
    const idMat3& axis, const int time) {
    for (int index = 0; index < explosions.Num(); ++index) {
        idExplosion& explosion = explosions[index];
        explosion.startTime = time + explosion.decl.delay;
        explosion.worldPosition = explosion.localSpace
            ? origin + axis * explosion.decl.position
            : explosion.decl.position;
        explosion.forceApplied = false;
        explosion.effectsEnabled = true;
        if (index < explosionFX.Num()) {
            explosionFX[index] = GameLib_StartBreakableExplosion(
                gameLibEffects, explosion.decl, explosion.worldPosition,
                axis, explosion.startTime, 1.0f);
            explosion.fxIndex = explosionFX[index];
        }
    }
}

void idEffectPhysicsBreakable::StopExplosionFX(const int index) {
    if (index < 0 || index >= explosionFX.Num()) {
        return;
    }
    if (explosionFX[index] >= 0) {
        GameLib_StopBreakableExplosion(gameLibEffects, explosionFX[index]);
        explosionFX[index] = -1;
    }
    if (index < explosions.Num()) {
        explosions[index].fxIndex = -1;
        explosions[index].effectsEnabled = false;
    }
}

void idEffectPhysicsBreakable::RemoveExplosions() {
    for (int index = 0; index < explosionFX.Num(); ++index) {
        StopExplosionFX(index);
    }
    explosions.Clear();
    explosionFX.Clear();
}

void idEffectPhysicsBreakable::UpdateSimulation(const idVec3& origin,
    const idMat3& axis, const int currentTime, const int gameMsPerFrame,
    const int frameNumber, const float lodScale, const float effectScale) {
    (void)frameNumber;
    (void)lodScale;
    const float deltaTime = (std::max)(0, gameMsPerFrame) * 0.001f;

    for (int index = 0; index < explosions.Num(); ++index) {
        idExplosion& explosion = explosions[index];
        if (currentTime < explosion.startTime) {
            continue;
        }
        if (!explosion.forceApplied) {
            AddRadiusImpact(currentTime, nullptr, explosion.worldPosition,
                explosion.decl.radius,
                explosion.decl.impulse * effectScale);
            explosion.forceApplied = true;
        }
        if (explosion.decl.duration > 0 &&
            currentTime >= explosion.startTime + explosion.decl.duration) {
            StopExplosionFX(index);
        }
    }

    for (int index = 0; index < rigidBodies.Num(); ++index) {
        idEffectPhysicsRigidBody* const body = rigidBodies[index];
        if (body == nullptr || !body->active) {
            continue;
        }
        body->Update(deltaTime, 0.0f, collisions[index]);
        const idVec3 velocity = body->currentState.linearMomentum *
            body->properties->inverseMass;
        if (collisions[index].collisionNormalVelocity.LengthSqr() > 0.0f) {
            GameLib_PlayBreakableCollision(soundInfo, collisions[index],
                body->currentState.position, velocity.LengthSqr(), currentTime);
        }
        for (int trailIndex = 0; trailIndex < trails.Num(); ++trailIndex) {
            const idBreakableTrail& trail = trails[trailIndex].decl;
            if (velocity.LengthSqr() >=
                trail.minTrailVelocity * trail.minTrailVelocity) {
                GameLib_EmitBreakableTrail(gameLibEffects, trail, index,
                    body->currentState.position, velocity, currentTime);
            }
        }
        for (int decalIndex = 0; decalIndex < decals.Num(); ++decalIndex) {
            if (collisions[index].collisionNormalVelocity.LengthSqr() >=
                decals[decalIndex].decl.minBounceVelocity *
                    decals[decalIndex].decl.minBounceVelocity) {
                GameLib_EmitBreakableDecal(gameLibEffects,
                    decals[decalIndex].decl, index, collisions[index],
                    currentTime);
            }
        }
        if (index < sparks.Num() &&
            collisions[index].collisionNormalVelocity.LengthSqr() > 0.0f) {
            GameLib_EmitBreakableSpark(gameLibEffects,
                sparks[index].material, sparks[index].size,
                collisions[index].collisionPoint,
                velocity * sparks[index].velocityScale, currentTime);
        }
    }
    broadPhase.SubmitQueries(false);
    UpdateModel(origin, axis, currentTime);
}

void idEffectPhysicsBreakable::UpdateModel(const idVec3& origin,
    const idMat3& axis, const int currentTime) {
    (void)origin;
    (void)axis;
    (void)currentTime;
    if (model == nullptr) {
        return;
    }
    for (int index = 0; index < rigidBodies.Num(); ++index) {
        if (rigidBodies[index] != nullptr && rigidBodies[index]->active) {
            GameLib_DiscreteAnimationSetPiece(model, index,
                rigidBodies[index]->currentState.position,
                rigidBodies[index]->currentState.orientation);
        } else {
            GameLib_DiscreteAnimationCollapsePiece(model, index);
        }
    }
    GameLib_DiscreteAnimationUpdate(model);
}

void idEffectPhysicsBreakable::DrawCollisionModels(const int single,
    const idVec3& offset, const idMat3& axis) {
    for (int index = 0; index < rigidBodies.Num(); ++index) {
        if (single >= 0 && single != index) {
            continue;
        }
        idEffectPhysicsRigidBody* const body = rigidBodies[index];
        if (body == nullptr || body->properties == nullptr) {
            continue;
        }
        const idVec3 drawOrigin = body->active
            ? body->currentState.position
            : offset + axis * body->currentState.position;
        const idMat3 drawAxis = body->active
            ? body->currentState.orientation
            : body->currentState.orientation * axis;
        GameLib_DrawEffectTraceModel(broadPhase.traceModelCache,
            body->properties->traceModelIndex, index, drawOrigin, drawAxis);
    }
}
