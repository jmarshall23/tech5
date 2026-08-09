#include "gamelib/effectphysics/effectphysicspieceemitter.h"

#include "gamelib/physics/tracemodelcache.h"
#include "idlib/geometry/tracemodel.h"

#include <algorithm>

// These operations cross from GameLib into the renderer/decl/sound modules.
// Their recovered implementations live with those owning subsystems; GameLib
// consumes them without inventing the very large render-model layouts here.
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
void GameLib_DiscreteAnimationSetHidden(
    idRenderModelDiscreteAnimation* model, bool hidden);
void GameLib_DiscreteAnimationDelete(idRenderModelDiscreteAnimation* model);
bool GameLib_GetBreakablePhysicsSettings(const idDeclBreakable* decl,
    idEffectPhysicsPieceSettings& settings);
void GameLib_DrawEffectTraceModel(const idTraceModelCache* cache,
    int traceModelIndex, int pieceIndex, const idVec3& origin,
    const idMat3& axis);
void GameLib_PlayEffectPhysicsCollision(
    idEffectPhysicsPieceEmitter::pieceEmitterSound_t& soundInfo,
    idRenderModelEffects* effects, const idEffectPhysicsCollision& collision,
    const idVec3& origin, float speedSqr, float volumeDb, int currentTime);

idEffectPhysicsPieceEmitter::idEffectPhysicsPieceEmitter()
    : properties(0)
    , pieces(0)
    , broadPhase()
    , random(0)
    , pieceMass(10.0f)
    , pieceCollisionAgeDecay(0.0f)
    , pieceCollisionVolumeDecay(0.0f)
    , model(nullptr)
    , decl(nullptr)
    , modelEffects(nullptr)
    , soundInfo{nullptr, nullptr, 0, 0.0f}
    , pieceLifeTime(0)
    , pieceFriction(0.0f)
    , pieceIndex(0)
    , numPiecesInUse(0)
    , hidden(false)
    , hiddenOverride(false) {
}

idEffectPhysicsPieceEmitter::~idEffectPhysicsPieceEmitter() {
    if (broadPhase.traceModelCache != nullptr) {
        for (int index = 0; index < properties.Num(); ++index) {
            if (properties[index] != nullptr) {
                broadPhase.traceModelCache->FreeTraceModel(
                    properties[index]->traceModelIndex);
            }
        }
    }
    for (int index = 0; index < pieces.Num(); ++index) {
        delete pieces[index].rigidBody;
        pieces[index].rigidBody = nullptr;
    }
    for (int index = 0; index < properties.Num(); ++index) {
        delete properties[index];
    }
    pieces.ClearFree();
    properties.ClearFree();
    if (model != nullptr) {
        GameLib_DiscreteAnimationDelete(model);
        model = nullptr;
    }
}

void idEffectPhysicsPieceEmitter::ApplyDeclSettings(
    idEffectPhysicsProperties& target) const {
    idEffectPhysicsPieceSettings settings{};
    if (decl == nullptr ||
        !GameLib_GetBreakablePhysicsSettings(decl, settings)) {
        return;
    }
    target.linearFriction = settings.linearFriction;
    target.angularFriction = settings.angularFriction;
    target.contactFriction = settings.contactFriction;
    target.linearFrictionWater = settings.linearFrictionWater;
    target.angularFrictionWater = settings.angularFrictionWater;
    target.bouncyness = settings.bouncyness;
    target.gravityVector = settings.gravityVector;
    target.worldCollisionOnly = settings.worldCollisionOnly;
    target.simplePointCollision = settings.simplePointCollision;
    target.crazyBounceChance = settings.crazyBounceChance;
    target.stopSpeed = settings.stopSpeed;
    target.maxLinearVelocity = settings.maxLinearVelocity;
    target.maxAngularVelocity = settings.maxAngularVelocity;
    target.clipMask = settings.clipMask;
}

idEffectPhysicsProperties*
idEffectPhysicsPieceEmitter::GetPropertiesForTraceModel(
    const idTraceModel& traceModel, const idMaterial* const material) {
    if (broadPhase.traceModelCache == nullptr) {
        return nullptr;
    }
    const int traceModelIndex = broadPhase.traceModelCache->AllocTraceModel(
        traceModel, material);
    for (int index = 0; index < properties.Num(); ++index) {
        if (properties[index]->traceModelIndex == traceModelIndex) {
            // AllocTraceModel returned another reference to an existing entry.
            broadPhase.traceModelCache->FreeTraceModel(traceModelIndex);
            return properties[index];
        }
    }

    idEffectPhysicsProperties* const result =
        new idEffectPhysicsProperties();
    result->Setup(&broadPhase, traceModelIndex, pieceMass);
    ApplyDeclSettings(*result);
    properties.Append(result);
    return result;
}

void idEffectPhysicsPieceEmitter::Init(idClip* const clip,
    idTraceModelCache* const traceModelCache,
    idRenderModelDiscreteAnimation* const renderModel,
    idRenderModelEffects* const renderModelEffects,
    const pieceEmitterSound_t* const sound, const int entityNumber) {
    broadPhase.Init(clip, traceModelCache);
    model = renderModel;
    modelEffects = renderModelEffects;
    decl = renderModel != nullptr
        ? GameLib_DiscreteAnimationDecl(renderModel) : nullptr;
    if (sound != nullptr) {
        soundInfo = *sound;
    }
    pieceIndex = 0;
    numPiecesInUse = 0;

    for (int index = 0; index < pieces.Num(); ++index) {
        delete pieces[index].rigidBody;
    }
    pieces.Clear();
    const int pieceCount = renderModel != nullptr
        ? GameLib_DiscreteAnimationPieceCount(renderModel) : 0;
    pieces.SetNum((std::max)(0, pieceCount));

    for (int index = 0; index < pieces.Num(); ++index) {
        idVec3 position;
        idMat3 orientation(1.0f);
        idTraceModel traceModel;
        const idMaterial* material = nullptr;
        idBreakablePiece& piece = pieces[index];
        piece.rigidBody = nullptr;
        piece.collision.Clear();
        piece.emitTime = 0;
        piece.firstCollisionTime = 0;
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
        piece.rigidBody = new idEffectPhysicsRigidBody();
        piece.rigidBody->Setup(pieceProperties);
        piece.rigidBody->SetPosition(position, orientation);
        piece.rigidBody->SPObject.entityNum = entityNumber;
    }
}

void idEffectPhysicsPieceEmitter::Reset() {
    random.SetSeed(0);
    pieceIndex = 0;
    numPiecesInUse = 0;
    if (model != nullptr) {
        GameLib_DiscreteAnimationReset(model);
    }
    for (int index = 0; index < pieces.Num(); ++index) {
        idBreakablePiece& piece = pieces[index];
        piece.emitTime = 0;
        piece.firstCollisionTime = 0;
        piece.collision.Clear();
        if (piece.rigidBody == nullptr) {
            continue;
        }
        idVec3 position;
        idMat3 orientation(1.0f);
        idTraceModel ignoredTraceModel;
        const idMaterial* ignoredMaterial = nullptr;
        if (model != nullptr && GameLib_DiscreteAnimationGetPiece(model,
                index, position, orientation, ignoredTraceModel,
                ignoredMaterial)) {
            piece.rigidBody->SetPosition(position, orientation);
        }
        piece.rigidBody->active = false;
        piece.rigidBody->settled = false;
        piece.rigidBody->currentState.linearMomentum.Zero();
        piece.rigidBody->currentState.angularMomentum.Zero();
        piece.rigidBody->SPObject.motion.ignore = false;
    }
    for (int index = 0; index < properties.Num(); ++index) {
        ApplyDeclSettings(*properties[index]);
    }
    hiddenOverride = true;
    if (model != nullptr) {
        GameLib_DiscreteAnimationSetHidden(model, true);
    }
}

void idEffectPhysicsPieceEmitter::EmitPiece(const int emitTime,
    const idVec3& position, const idMat3& orientation,
    const idVec3& impulsePoint, const idVec3& impulse) {
    if (pieces.IsEmpty()) {
        return;
    }
    idBreakablePiece& piece = pieces[pieceIndex];
    if (piece.rigidBody == nullptr) {
        pieceIndex = (pieceIndex + 1) % pieces.Num();
        return;
    }
    if (!piece.rigidBody->active) {
        ++numPiecesInUse;
    }
    hiddenOverride = false;
    piece.emitTime = emitTime;
    piece.firstCollisionTime = 0;
    piece.collision.Clear();
    piece.rigidBody->SetPosition(position, orientation);
    piece.rigidBody->currentState.linearMomentum.Zero();
    piece.rigidBody->currentState.angularMomentum.Zero();
    piece.rigidBody->ApplyImpulse(position + impulsePoint, impulse);
    piece.rigidBody->active = true;
    piece.rigidBody->settled = false;
    piece.rigidBody->SPObject.motion.ignore = false;
    pieceIndex = (pieceIndex + 1) % pieces.Num();
}

void idEffectPhysicsPieceEmitter::UpdateSimulation(const idVec3& origin,
    const idMat3& axis, const int currentTime, const int gameMsPerFrame) {
    (void)origin;
    (void)axis;
    const float deltaTime = (std::max)(0, gameMsPerFrame) * 0.001f;
    for (int index = 0; index < pieces.Num(); ++index) {
        idBreakablePiece& piece = pieces[index];
        idEffectPhysicsRigidBody* const body = piece.rigidBody;
        if (body == nullptr || !body->active) {
            continue;
        }
        if (pieceLifeTime > 0 && currentTime >= piece.emitTime + pieceLifeTime) {
            body->active = false;
            body->SPObject.motion.ignore = true;
            numPiecesInUse = (std::max)(0, numPiecesInUse - 1);
            continue;
        }

        float momentumDecay = 0.0f;
        if (piece.firstCollisionTime > 0 && pieceCollisionAgeDecay > 0.0f &&
            pieceLifeTime > 0) {
            momentumDecay = (std::min)(1.0f,
                (currentTime - piece.firstCollisionTime) *
                    pieceCollisionAgeDecay /
                    static_cast<float>(pieceLifeTime));
        }
        body->Update(deltaTime, momentumDecay, piece.collision);
        if (piece.collision.collisionNormalVelocity.LengthSqr() > 0.0f) {
            if (piece.firstCollisionTime == 0) {
                piece.firstCollisionTime = currentTime;
            }
            const idVec3 velocity = body->currentState.linearMomentum *
                body->properties->inverseMass;
            const float volumeDb = pieceCollisionVolumeDecay > 0.0f
                ? -(currentTime - piece.firstCollisionTime) *
                    pieceCollisionVolumeDecay * 0.001f
                : 0.0f;
            GameLib_PlayEffectPhysicsCollision(soundInfo, modelEffects,
                piece.collision, body->currentState.position,
                velocity.LengthSqr(), volumeDb, currentTime);
        }
        if (pieceFriction > 0.0f) {
            const float damping = (std::max)(0.0f,
                1.0f - pieceFriction * deltaTime);
            body->currentState.linearMomentum =
                body->currentState.linearMomentum * damping;
        }
    }
}

void idEffectPhysicsPieceEmitter::UpdateModel(
    const idVec3& activeDrawScale3D) {
    if (model == nullptr) {
        return;
    }
    const idMat3 scale(activeDrawScale3D.x, 0.0f, 0.0f,
        0.0f, activeDrawScale3D.y, 0.0f,
        0.0f, 0.0f, activeDrawScale3D.z);
    for (int index = 0; index < pieces.Num(); ++index) {
        const idBreakablePiece& piece = pieces[index];
        if (piece.rigidBody != nullptr && piece.rigidBody->active) {
            GameLib_DiscreteAnimationSetPiece(model, index,
                piece.rigidBody->currentState.position,
                piece.rigidBody->currentState.orientation * scale);
        } else {
            GameLib_DiscreteAnimationCollapsePiece(model, index);
        }
    }
    if (!hidden && !hiddenOverride) {
        GameLib_DiscreteAnimationUpdate(model);
    }
}

void idEffectPhysicsPieceEmitter::SubmitCollisionQueries(
    const bool worldCollisionModelOnly) {
    broadPhase.SubmitQueries(worldCollisionModelOnly);
}

void idEffectPhysicsPieceEmitter::DrawCollisionModels(const int single,
    const idVec3& offset, const idMat3& axis) {
    for (int index = 0; index < pieces.Num(); ++index) {
        if (single >= 0 && single != index) {
            continue;
        }
        const idBreakablePiece& piece = pieces[index];
        if (piece.rigidBody == nullptr || piece.rigidBody->properties == nullptr) {
            continue;
        }
        idVec3 drawOrigin = piece.rigidBody->currentState.position;
        idMat3 drawAxis = piece.rigidBody->currentState.orientation;
        if (!piece.rigidBody->active) {
            drawOrigin = offset + axis * drawOrigin;
            drawAxis *= axis;
        }
        GameLib_DrawEffectTraceModel(broadPhase.traceModelCache,
            piece.rigidBody->properties->traceModelIndex, index,
            drawOrigin, drawAxis);
    }
}

void idEffectPhysicsPieceEmitter::Hide() {
    hidden = true;
    if (model != nullptr) {
        GameLib_DiscreteAnimationSetHidden(model, true);
    }
}

void idEffectPhysicsPieceEmitter::Show() {
    hidden = false;
    if (model != nullptr && !hiddenOverride) {
        GameLib_DiscreteAnimationSetHidden(model, false);
    }
}
