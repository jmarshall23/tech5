#pragma once

#include "idlib/bv/bounds.h"
#include "idlib/bv/sphere.h"
#include "idlib/containers/list.h"
#include "idlib/geometry/drawvert.h"
#include "idlib/math/plane.h"
#include "models/particles/declparticle.h"

class idDeclCloth;

enum clothType_t : int {
    CLOTH_NONE = 0,
    CLOTH_ROPE,
    CLOTH_SQUARE,
    CLOTH_GENERIC,
    CLOTH_FLAG
};

enum clothSprings_t : int {
    CLOTH_SPRING_QUAD = 0,
    CLOTH_SPRING_CROSS,
    CLOTH_SPRING_BANDED
};

class alignas(4) idClothSpring {
public:
    idClothSpring();
    void Init(float springFriction, idClothParticle* particles,
        int firstParticle, int secondParticle, bool isBand, bool isEdge);
    void Init2(int firstParticle, int secondParticle, float restLength,
        float springFriction, float lengthMultiplier);
    void Constrain(idClothParticle* particles);
    void Constrain2(idClothParticle* particles);

    float springLength;
    float slSquared;
    float friction;
    float maxLengthMultiplier;
    int p1;
    int p2;
    bool band;
    bool edge;
};

struct alignas(4) clothWeaponTrace_t {
    idVec3 start;
    idVec3 dir;
    float strength;
    bool causesHoles;
};

struct alignas(4) clothParms_t {
    clothType_t type;
    idClothParticle* cloth;
    int numClothParticles;
    idClothSpring* springs;
    int numSprings;
    idSphere* collisions;
    int numCollisions;
    clothWeaponTrace_t* weaponTraces;
    int numWeaponTraces;
    idDrawVert* vertices;
    idBounds* bounds;
    idVec3 org;
    idMat3 axis;
    float friction;
    idVec3 gravity;
    idVec3 windDirection;
    idPlane collisionPlane;
    bool hasCollisionPlane;
    float collisionFriction;
    int width;
    int height;
    float vSpacing;
    float hSpacing;
    float timeDelta;
    int numIterations;
    bool rect;
};

class idClothSim {
public:
    idClothSim(const idDeclCloth* clothSystem);
    idClothSim(int width, int height, float horizontalSpacing,
        float verticalSpacing, const idDeclCloth* clothSystem, bool rect);
    ~idClothSim();

    void Reset();
    void SetOriginAxis(const idVec3& newOrigin, const idMat3& newAxis,
        bool updateParticles);
    void SetAnchor(int index, bool temporaryAnchor);
    void SetAnchorPosition(int index, const idVec3& position);
    void SetAnchorAxis(int index, const idMat3& modelAxis);
    void AddCollisionSphere(const idSphere& sphere, bool temporary);
    void AddWeaponTrace(const idVec3& start, const idVec3& direction,
        float strength, bool causesHoles);
    void GetRopeParticleOriginAxis(int index, idList<idVec3, 5>& origins,
        idList<idMat3, 5>& orientations) const;
    void Run(void* parallelJobList = nullptr);

    const idDeclCloth* clothDecl;
    int width;
    int height;
    float hSpacing;
    float vSpacing;
    idVec3 origin;
    idMat3 axis;
    idVec3 windDirection;
    idVec3 gravity;
    int numIterations;
    float timeDelta;
    idClothParticle* cloth;
    int numClothParticles;
    int currentDeferred;
    idBounds* clothBoundsFromJob;
    idBounds clothBounds;
    clothParms_t* clothParms;
    bool isRect;
    idList<idClothSpring, 81> springs;
    idList<idSphere, 81> permanentCollisionSpheres;
    idList<idSphere, 81> temporaryCollisionSpheres[2];
    idList<clothWeaponTrace_t, 81> weaponTraces[2];
    idPlane collisionPlane[2];

private:
    void GenerateGeneric();
    void GenerateRope();
    void GenerateSquare();
    void GenerateTriangle(const idDeclCloth* clothSystem);
    void GenerateRect(const idDeclCloth* clothSystem);
    void Swap();
    int ResolveParticleIndex(int publicIndex) const;
};

static_assert(sizeof(idClothSpring) == 28,
    "Recovered cloth-spring ABI changed");
static_assert(sizeof(clothWeaponTrace_t) == 32,
    "Recovered cloth weapon-trace ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(clothParms_t) == 172,
    "Recovered cloth generation parameters ABI changed");
static_assert(sizeof(idClothSim) == 276,
    "Recovered cloth simulation ABI changed");
#endif
