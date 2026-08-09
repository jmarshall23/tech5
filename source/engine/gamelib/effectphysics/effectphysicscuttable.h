#pragma once

#include "gamelib/effectphysics/effectphysicsrigidbody.h"
#include "idlib/containers/staticlist.h"
#include "idlib/geometry/drawvert.h"

class idClip;
class idDeclImpactSound;
class idMaterial;
class idRenderModelCuttableDynamic;
class idRenderWorld;
class idSoundWorld;
class idTraceModel;
class idTraceModelCache;

struct cuttablePhysicsEmitInfo_t {
    const idMaterial* renderMaterial;
    const idMaterial* depthMaterial;
    const idDeclImpactSound* soundTable;
    idTraceModel* traceModel;
    idMat3 orientation;
    idVec3 position;
    idVec3 impulsePoint;
    idVec3 impulse;
    int emitTime;
    int entityNum;
    float minBounceVelocitySqr;
};

class idEffectPhysicsCuttable {
public:
    static constexpr int MAX_PIECES = 8;
    static constexpr int MAX_BUFFERS = 10;

    struct model_t {
        int index;
        int timeStamp;
    };

    struct piece_t {
        idEffectPhysicsProperties* properties;
        idEffectPhysicsRigidBody* rigidBody;
        const idDeclImpactSound* soundTable;
        idEffectPhysicsCollision collision;
        idMat3 orientation;
        idVec3 position;
        int timeStamp;
        int firstCollisionTime;
        int renderModelIndex;
        int nextSoundTime;
        float minBounceVelocitySqr;
    };

    idEffectPhysicsCuttable();
    ~idEffectPhysicsCuttable();

    void Init(idRenderWorld* renderWorld, idSoundWorld* soundWorld,
        idClip* clip, idTraceModelCache* traceModelCache);
    int Emit(const cuttablePhysicsEmitInfo_t& emitInfo,
        const idList<idDrawVert, 5>& vertices,
        const idList<idVec2, 5>& textureCoordinates,
        const idList<unsigned short, 5>& indices);
    void UpdateSimulation(const idVec3& origin, const idMat3& axis,
        int currentTime, int gameMsPerFrame);
    void UpdateModel(const idVec3& scale, int currentTime);
    void SubmitCollisionQueries();
    void DrawCollisionModels(int single);

    idStaticList<model_t, MAX_BUFFERS> freeModels;
    idStaticList<idRenderModelCuttableDynamic*, MAX_BUFFERS> models;
    idStaticList<piece_t, MAX_PIECES> pieces;
    idEffectPhysicsBroadPhase broadPhase;
    float pieceCollisionAgeDecay;
    float pieceFriction;
    int pieceMaxLifeTime;
    int pieceLifeTime;
    int pieceFadeTime;
    int pieceMass;
    idSoundWorld* soundWorld;

private:
    void ReleasePiece(piece_t& piece, int currentTime);
};

static_assert(sizeof(cuttablePhysicsEmitInfo_t) == 100,
    "Recovered cuttablePhysicsEmitInfo_t ABI changed");
static_assert(sizeof(idEffectPhysicsCuttable::model_t) == 8,
    "Recovered cuttable model entry ABI changed");
static_assert(sizeof(idEffectPhysicsCuttable::piece_t) == 108,
    "Recovered cuttable piece ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idEffectPhysicsCuttable) == 1132,
    "Recovered idEffectPhysicsCuttable ABI changed");
#endif
