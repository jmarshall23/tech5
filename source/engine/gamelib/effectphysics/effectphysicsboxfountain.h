#pragma once

#include "gamelib/effectphysics/effectphysicsbroadphase.h"
#include "gamelib/effectphysics/effectphysicsproperties.h"
#include "idlib/containers/list.h"
#include "idlib/math/random.h"

class idClip;
class idEffectPhysicsRigidBody;
class idRenderModelManyBoxes;
class idTraceModelCache;

class alignas(8) idEffectPhysicsBoxFountain {
public:
    idEffectPhysicsBoxFountain();
    ~idEffectPhysicsBoxFountain();

    void Init(idClip* clip, idTraceModelCache* traceModelCache,
        int entityNumber);

    idEffectPhysicsBroadPhase broadPhase;
    idEffectPhysicsProperties properties;
    idList<idEffectPhysicsRigidBody*, 59> rigidBodies;
    idRenderModelManyBoxes* manyBoxes;
    int lastFireTime;
    int currentFireRigidBody;
    idVec3 startOrigin;
    idVec3 spawnOrigin;
    idSPObject spawnObject;
    idRandom random;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idEffectPhysicsBoxFountain) == 456,
    "Recovered idEffectPhysicsBoxFountain ABI changed");
#endif
