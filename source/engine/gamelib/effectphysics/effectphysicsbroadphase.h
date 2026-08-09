#pragma once

#include "cm/collisionmodel.h"
#include "cm/jobs/collisionquery.h"
#include "gamelib/physics/tracemodelcache.h"
#include "idlib/bv/boundsshort.h"
#include "idlib/containers/list.h"
#include "idlib/math/rotation.h"

class idClip;
class idJointMat;
struct trace_t;

struct idSPObjectMotion {
    bool valid;
    bool worldCollisionOnly;
    bool ignore;
    idVec3 translation;
    idVec3 rotationVec;
    float rotationAngle;
};

class idSPObject {
public:
    // Materialized in the authoritative effectphysicsbroadphase.h dump.
    idSPObject()
        : id(0), traceModelIndex(-1), entityNum(0x1FFF), clipMask(1),
          origin(), axis(1.0f), absBounds(), motion{}, query{0}, index{},
          overlap(0) {
        origin.Zero();
        absBounds.b[0][0] = 0x7FFF;
        absBounds.b[0][1] = 0x7FFF;
        absBounds.b[0][2] = 0x7FFF;
        absBounds.b[1][0] = static_cast<short>(0x8000);
        absBounds.b[1][1] = static_cast<short>(0x8000);
        absBounds.b[1][2] = static_cast<short>(0x8000);
        motion.translation.Zero();
        motion.rotationVec.Zero();
        motion.rotationAngle = 0.0f;
    }

    int id;
    int traceModelIndex;
    int entityNum;
    int clipMask;
    idVec3 origin;
    idMat3 axis;
    idBoundsShort absBounds;
    idSPObjectMotion motion;
    idCollisionQuery query;
    int index[2][3];
    idList<short, 59> overlap;
};

// Reconstructed from PDB local types 14572 and 14574.
class idEffectPhysicsBroadPhase {
public:
    class idSPMarker {
    public:
        short value;
        unsigned short data;
    };

    idEffectPhysicsBroadPhase();
    ~idEffectPhysicsBroadPhase();

    void Init(idClip* clip_, idTraceModelCache* traceModelCache_);
    bool GetMotionResult(trace_t* result, idSPObject* object);
    int GetPositionedModels(const idSPObject* object,
        idPositionedCollisionModel* models, int maxModels) const;
    void SubmitQueries(bool worldCollisionModelOnly);
    void RemoveObject(idSPObject* object);
    void AddObject(idSPObject* object, const idVec3& origin,
        const idMat3& axis, const idBounds* bounds);
    void SetObjectPosition(idSPObject* object, const idVec3& origin,
        const idMat3& axis, const idBounds* bounds);
    void ApplyMotion(idSPObject* object, const idVec3& translation,
        const idRotation& rotation);

    idClip *clip;
    idTraceModelCache *traceModelCache;
    idList<idSPObject *, 59> objects;
    idList<idSPMarker, 59> markers[3];

private:
    const idBounds* ResolveBounds(const idSPObject* object,
        const idBounds* suppliedBounds) const;
    void MoveObject(idSPObject* object);
    void RebuildBroadPhase();
};

static_assert(sizeof(idEffectPhysicsBroadPhase::idSPMarker) == 4,
    "Recovered idSPMarker ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idPositionedCollisionModel) == 80,
    "Recovered positioned collision-model ABI changed");
static_assert(sizeof(idSPObjectMotion) == 32,
    "Recovered idSPObjectMotion ABI changed");
static_assert(sizeof(idSPObject) == 160,
    "Recovered idSPObject ABI changed");
static_assert(sizeof(idEffectPhysicsBroadPhase) == 72,
    "Recovered idEffectPhysicsBroadPhase ABI changed");
#endif
