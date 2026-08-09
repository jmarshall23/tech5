#include "gamelib/effectphysics/effectphysicscuttable.h"

#include "gamelib/physics/tracemodelcache.h"
#include "idlib/geometry/tracemodel.h"

#include <algorithm>

idRenderModelCuttableDynamic* GameLib_AllocCuttableRenderModel(
    idRenderWorld* renderWorld);
void GameLib_DeleteCuttableRenderModel(idRenderModelCuttableDynamic* model);
void GameLib_UploadCuttableRenderModel(idRenderModelCuttableDynamic* model,
    const idMaterial* renderMaterial, const idMaterial* depthMaterial,
    const idList<idDrawVert, 5>& vertices,
    const idList<idVec2, 5>& textureCoordinates,
    const idList<unsigned short, 5>& indices);
void GameLib_UpdateCuttableRenderModel(idRenderModelCuttableDynamic* model,
    const idVec3& origin, const idMat3& axis, float fade, bool hidden);
void GameLib_PlayCuttableCollision(idSoundWorld* soundWorld,
    const idDeclImpactSound* soundTable,
    const idEffectPhysicsCollision& collision, const idVec3& origin,
    float velocitySqr, float minimumVelocitySqr, int& nextSoundTime,
    int currentTime);
void GameLib_DrawEffectTraceModel(const idTraceModelCache* cache,
    int traceModelIndex, int pieceIndex, const idVec3& origin,
    const idMat3& axis);

idEffectPhysicsCuttable::idEffectPhysicsCuttable()
    : freeModels()
    , models()
    , pieces()
    , broadPhase()
    , pieceCollisionAgeDecay(0.0f)
    , pieceFriction(0.0f)
    , pieceMaxLifeTime(30000)
    , pieceLifeTime(5000)
    , pieceFadeTime(2000)
    , pieceMass(8)
    , soundWorld(nullptr) {
}

idEffectPhysicsCuttable::~idEffectPhysicsCuttable() {
    for (int index = 0; index < pieces.Num(); ++index) {
        piece_t& piece = pieces[index];
        if (piece.properties != nullptr && broadPhase.traceModelCache != nullptr) {
            broadPhase.traceModelCache->FreeTraceModel(
                piece.properties->traceModelIndex);
        }
        delete piece.rigidBody;
        delete piece.properties;
        piece.rigidBody = nullptr;
        piece.properties = nullptr;
        piece.soundTable = nullptr;
    }
    for (int index = 0; index < models.Num(); ++index) {
        if (models[index] != nullptr) {
            GameLib_DeleteCuttableRenderModel(models[index]);
        }
    }
}

void idEffectPhysicsCuttable::Init(idRenderWorld* const renderWorld,
    idSoundWorld* const soundWorld_, idClip* const clip,
    idTraceModelCache* const traceModelCache) {
    broadPhase.Init(clip, traceModelCache);
    pieceCollisionAgeDecay = 0.0f;
    pieceMaxLifeTime = 30000;
    pieceLifeTime = 5000;
    pieceFadeTime = 2000;
    pieceMass = 8;
    pieceFriction = 0.0f;
    soundWorld = soundWorld_;

    pieces.SetNum(MAX_PIECES);
    for (int index = 0; index < pieces.Num(); ++index) {
        piece_t& piece = pieces[index];
        piece.properties = nullptr;
        piece.rigidBody = nullptr;
        piece.soundTable = nullptr;
        piece.collision.Clear();
        piece.orientation = idMat3(1.0f);
        piece.position.Zero();
        piece.timeStamp = 0;
        piece.firstCollisionTime = 0;
        piece.renderModelIndex = -1;
        piece.nextSoundTime = 0;
        piece.minBounceVelocitySqr = 1.0f;
    }

    models.Clear();
    freeModels.Clear();
    for (int index = 0; index < MAX_BUFFERS; ++index) {
        models.Append(GameLib_AllocCuttableRenderModel(renderWorld));
        freeModels.Append(model_t{index, 0});
    }
}

void idEffectPhysicsCuttable::ReleasePiece(piece_t& piece,
    const int currentTime) {
    if (piece.renderModelIndex >= 0) {
        freeModels.Append(model_t{piece.renderModelIndex, currentTime});
        if (piece.renderModelIndex < models.Num() &&
            models[piece.renderModelIndex] != nullptr) {
            GameLib_UpdateCuttableRenderModel(models[piece.renderModelIndex],
                idVec3(0.0f, 0.0f, 0.0f), idMat3(1.0f), 0.0f, true);
        }
        piece.renderModelIndex = -1;
    }
    if (piece.rigidBody != nullptr) {
        piece.rigidBody->active = false;
    }
    piece.timeStamp = 0;
}

int idEffectPhysicsCuttable::Emit(
    const cuttablePhysicsEmitInfo_t& emitInfo,
    const idList<idDrawVert, 5>& vertices,
    const idList<idVec2, 5>& textureCoordinates,
    const idList<unsigned short, 5>& indices) {
    if (emitInfo.traceModel == nullptr || broadPhase.traceModelCache == nullptr ||
        pieces.IsEmpty()) {
        return -1;
    }

    int pieceIndex = 0;
    for (int index = 1; index < pieces.Num(); ++index) {
        if (pieces[index].timeStamp < pieces[pieceIndex].timeStamp) {
            pieceIndex = index;
        }
    }
    piece_t& piece = pieces[pieceIndex];

    // The pool has two more models than live pieces.  Return the recycled
    // piece's model before selecting the oldest free buffer.
    if (piece.renderModelIndex >= 0) {
        freeModels.Append(model_t{piece.renderModelIndex, emitInfo.emitTime});
        piece.renderModelIndex = -1;
    }
    int freeIndex = 0;
    for (int index = 1; index < freeModels.Num(); ++index) {
        if (freeModels[index].timeStamp < freeModels[freeIndex].timeStamp) {
            freeIndex = index;
        }
    }
    const int renderModelIndex = freeModels.IsEmpty()
        ? -1 : freeModels[freeIndex].index;
    if (!freeModels.IsEmpty()) {
        freeModels.RemoveIndexFast(freeIndex);
    }

    if (piece.properties != nullptr) {
        broadPhase.traceModelCache->FreeTraceModel(
            piece.properties->traceModelIndex);
    }
    delete piece.rigidBody;
    delete piece.properties;
    piece.rigidBody = nullptr;
    piece.properties = nullptr;

    idTraceModel centeredTraceModel = *emitInfo.traceModel;
    const idVec3 center =
        (centeredTraceModel.bounds[0] + centeredTraceModel.bounds[1]) * 0.5f;
    centeredTraceModel.Translate(-center);
    const int traceModelIndex = broadPhase.traceModelCache->AllocTraceModel(
        centeredTraceModel, emitInfo.renderMaterial);

    piece.properties = new idEffectPhysicsProperties();
    piece.properties->Setup(&broadPhase, traceModelIndex,
        static_cast<float>(pieceMass));
    piece.properties->contactFriction = 0.5f;
    piece.properties->linearFriction = 0.6f;
    piece.properties->angularFriction = 0.6f;
    piece.properties->bouncyness = 0.6f;
    piece.properties->angularFrictionWater = 1.0f;
    piece.properties->linearFrictionWater = 1.0f;
    piece.properties->gravityVector.Set(0.0f, 0.0f, -250.0f);
    piece.properties->worldCollisionOnly = true;
    piece.properties->simplePointCollision = false;
    piece.properties->crazyBounceChance = 0.0f;
    piece.properties->maxLinearVelocity = 5000.0f;
    piece.properties->stopSpeed = 30.0f;
    piece.properties->maxAngularVelocity = 12.566370614359f;
    piece.properties->clipMask = 1;

    piece.rigidBody = new idEffectPhysicsRigidBody();
    piece.rigidBody->Setup(piece.properties);
    piece.rigidBody->SPObject.entityNum = emitInfo.entityNum;
    piece.rigidBody->SetPosition(emitInfo.position + center,
        emitInfo.orientation);
    piece.rigidBody->currentState.linearMomentum.Zero();
    piece.rigidBody->currentState.angularMomentum.Zero();
    if (emitInfo.impulse.LengthSqr() > 0.25f) {
        piece.rigidBody->ApplyImpulse(
            emitInfo.position + emitInfo.impulsePoint, emitInfo.impulse);
    }
    piece.rigidBody->active = true;
    piece.rigidBody->SPObject.motion.ignore = false;

    piece.soundTable = emitInfo.soundTable;
    piece.collision.Clear();
    piece.orientation = emitInfo.orientation;
    piece.position = -center;
    piece.timeStamp = emitInfo.emitTime;
    piece.firstCollisionTime = 0;
    piece.renderModelIndex = renderModelIndex;
    piece.nextSoundTime = emitInfo.emitTime;
    piece.minBounceVelocitySqr = emitInfo.minBounceVelocitySqr;

    if (renderModelIndex >= 0 && renderModelIndex < models.Num() &&
        models[renderModelIndex] != nullptr) {
        GameLib_UploadCuttableRenderModel(models[renderModelIndex],
            emitInfo.renderMaterial, emitInfo.depthMaterial,
            vertices, textureCoordinates, indices);
        GameLib_UpdateCuttableRenderModel(models[renderModelIndex],
            emitInfo.position, emitInfo.orientation, 1.0f, false);
    }
    return pieceIndex;
}

void idEffectPhysicsCuttable::UpdateSimulation(const idVec3& origin,
    const idMat3& axis, const int currentTime, const int gameMsPerFrame) {
    (void)origin;
    (void)axis;
    const float deltaTime = (std::max)(0, gameMsPerFrame) * 0.001f;
    for (int index = 0; index < pieces.Num(); ++index) {
        piece_t& piece = pieces[index];
        idEffectPhysicsRigidBody* const body = piece.rigidBody;
        if (piece.timeStamp == 0 || body == nullptr || !body->active) {
            continue;
        }
        const int deathTime = piece.firstCollisionTime != 0
            ? piece.firstCollisionTime + pieceLifeTime + pieceFadeTime
            : piece.timeStamp + pieceMaxLifeTime;
        if (currentTime >= deathTime) {
            ReleasePiece(piece, currentTime);
            continue;
        }
        body->Update(deltaTime, 0.0f, piece.collision);
        if (body->settled && piece.firstCollisionTime == 0) {
            piece.firstCollisionTime = currentTime;
        } else if (piece.collision.collisionNormalVelocity.LengthSqr() > 0.0f) {
            if (piece.firstCollisionTime == 0) {
                piece.firstCollisionTime = currentTime;
            }
            const idVec3 velocity = body->currentState.linearMomentum *
                body->properties->inverseMass -
                body->properties->gravityVector * deltaTime;
            GameLib_PlayCuttableCollision(soundWorld, piece.soundTable,
                piece.collision, body->currentState.position,
                velocity.LengthSqr(), piece.minBounceVelocitySqr,
                piece.nextSoundTime, currentTime);
        }
        if (pieceFriction > 0.0f) {
            body->currentState.linearMomentum =
                body->currentState.linearMomentum * (std::max)(0.0f,
                    1.0f - pieceFriction * deltaTime);
        }
    }
}

void idEffectPhysicsCuttable::UpdateModel(const idVec3& scale,
    const int currentTime) {
    const idMat3 scaleAxis(scale.x, 0.0f, 0.0f,
        0.0f, scale.y, 0.0f, 0.0f, 0.0f, scale.z);
    for (int index = 0; index < pieces.Num(); ++index) {
        piece_t& piece = pieces[index];
        if (piece.timeStamp == 0 || piece.rigidBody == nullptr ||
            !piece.rigidBody->active || piece.renderModelIndex < 0 ||
            piece.renderModelIndex >= models.Num() ||
            models[piece.renderModelIndex] == nullptr) {
            continue;
        }
        const idVec3 renderOrigin = piece.rigidBody->currentState.position +
            piece.rigidBody->currentState.orientation * piece.position;
        float fade = 1.0f;
        if (piece.firstCollisionTime != 0 && pieceFadeTime > 0) {
            const int fadeAge = currentTime -
                (piece.firstCollisionTime + pieceLifeTime);
            if (fadeAge > 0) {
                fade = (std::max)(0.0f,
                    1.0f - fadeAge / static_cast<float>(pieceFadeTime));
            }
        }
        GameLib_UpdateCuttableRenderModel(models[piece.renderModelIndex],
            renderOrigin, piece.rigidBody->currentState.orientation * scaleAxis,
            fade, false);
    }
}

void idEffectPhysicsCuttable::SubmitCollisionQueries() {
    broadPhase.SubmitQueries(false);
}

void idEffectPhysicsCuttable::DrawCollisionModels(const int single) {
    for (int index = 0; index < pieces.Num(); ++index) {
        if (single >= 0 && index != single) {
            continue;
        }
        const piece_t& piece = pieces[index];
        if (piece.timeStamp == 0 || piece.rigidBody == nullptr ||
            !piece.rigidBody->active || piece.properties == nullptr) {
            continue;
        }
        GameLib_DrawEffectTraceModel(broadPhase.traceModelCache,
            piece.properties->traceModelIndex, index,
            piece.rigidBody->currentState.position,
            piece.rigidBody->currentState.orientation);
    }
}
