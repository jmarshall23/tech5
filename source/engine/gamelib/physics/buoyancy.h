#pragma once

#include "idlib/containers/staticlist.h"
#include "idlib/math/plane.h"
#include "idlib/math/vector.h"

class idClip;
class idClipModel;
class idDeclDamage;
class idPhysics;
enum surfTypes_t : int;

struct buoyantClipModel_t {
    int physicsId;
    int bodyId;
};

struct idBuoyancyResult {
    int bodyId;
    idVec3 centerOfBuoyancy;
    idVec3 linearVelocity;
    float displacedVolume;
    float waterLevel;
};

class idBuoyancy {
public:
    idBuoyancy();

    void CalculateBuoyancyWeights(const int* polytopeNumPlanes,
        const idPlane* polytopePlanes, int numPolytopes,
        const idClipModel* clipModel, float* weights);
    void ApplyBuoyancy(idClip* clip, idPhysics* physics, float timeStep,
        const idDeclDamage* waterDamage, const idVec3& waterCurrent,
        float waterDensity, float waterViscosity, int clipMask,
        surfTypes_t surfaceOverride);

    idStaticList<buoyantClipModel_t, 128> buoyantClipModels;
};

static_assert(sizeof(buoyantClipModel_t) == 8,
    "Recovered buoyant clip-model ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idBuoyancy) == 1040,
    "Recovered idBuoyancy ABI changed");
#endif
