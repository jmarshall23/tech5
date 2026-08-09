#pragma once

#include "cm/jobs/collisionquery.h"
#include "idlib/containers/list.h"
#include "idlib/math/spatialmat.h"
#include "idlib/text/atomicstring.h"

#ifndef ID_CLIP_QUERY_DEFINED
#define ID_CLIP_QUERY_DEFINED
struct idClipQuery { std::uint64_t index; };
#endif

class idAFConstraint;
class idAFTree;
class idClipModel;
class idSerializer;

struct AFBodyPState_t {
    idVec3 worldOrigin;
    idMat3 worldAxis;
    idVec3 atRestOrigin;
    idMat3 atRestAxis;
    idVec6 spatialVelocity;
    idVec6 externalForce;
};

class alignas(16) idAFBody {
public:
    struct afBodyFlags_t {
        std::uint8_t clearClipMaskInSolid : 1;
        std::uint8_t noSyncCollide : 1;
        std::uint8_t isZero : 1;
        std::uint8_t useContactMotorDir : 1;
        std::uint8_t useFrictionDir : 1;
        std::uint8_t spatialInertiaSparse : 1;
        std::uint8_t selfCollision : 1;
        std::uint8_t clipMaskSet : 1;
    };

    idAFBody();
    idAFBody(const char* name, idClipModel* clipModel, float density);
    virtual ~idAFBody();
    virtual void Serialize(idSerializer* serializer);

    void Init();
    void SetClipModel(idClipModel* model);
    void SetBouncyness(float bounce);
    void SetFriction(float linear, float angular, float contact);
    void SetDensity(float density, const idMat3& inertiaScale);
    void SetFrictionDirection(const idVec3& direction);
    bool GetFrictionDirection(idVec3& direction) const;
    void SetContactMotorDirection(const idVec3& direction);
    bool GetContactMotorDirection(idVec3& direction) const;
    idVec3 GetPointVelocity(const idVec3& point) const;
    void AddForce(const idVec3& point, const idVec3& force);

    alignas(16) idAtomicString name;
    idClipModel* clipModel;
    int clipMask;
    float linearFrictionWater;
    float angularFrictionWater;
    float linearFriction;
    float angularFriction;
    float contactFriction;
    float bouncyness;
    idVec3 frictionDir;
    idVec3 contactMotorDir;
    float contactMotorVelocity;
    float contactMotorForce;
    float mass;
    float invMass;
    idVec3 centerOfMass;
    idMat3 inertiaTensor;
    idMat3 inverseInertiaTensor;
    idAFBody* parent;
    idList<idAFBody*, 71> children;
    idAFConstraint* primaryConstraint;
    idList<idAFConstraint*, 71> constraints;
    idAFTree* tree;
    afBodyFlags_t fl;
    AFBodyPState_t current;
    AFBodyPState_t saved;
    idClipQuery motionQuery;
    idSpatialMat inverseWorldSpatialInertia;
    idSpatialMat I;
    idSpatialMat invI;
    idSpatialMat J;
    idStaticSpatialVec s;
    idStaticSpatialVec totalForce;
    idStaticSpatialVec auxForce;
    idStaticSpatialVec acceleration;
    float* response;
    int* responseIndex;
    int numResponses;
    int maxAuxiliaryIndex;
    int maxSubTreeAuxiliaryIndex;
};

static_assert(sizeof(AFBodyPState_t) == 144,
    "Recovered articulated-body state ABI changed");
static_assert(sizeof(idAFBody::afBodyFlags_t) == 1,
    "Recovered articulated-body flags ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAFBody) == 816,
    "Recovered idAFBody ABI changed");
#endif
