#pragma once

#include "cm/collisiontypes.h"

struct trace_t;
class idJointMat;

class idSphereModelCollisionDetection {
public:
    static int SetupCollisionSpherePtrs(const cm_sphereModel_t* model,
        cm_sphereModelPtrs_t& pointers);
    static void TraceThroughModel(trace_t& trace,
        const cm_sphereModel_t& model, const idVec3& start,
        const idVec3& end, float radius, const idMat3& trmAxis,
        const idJointMat* modelJoints, const idVec3& modelOrigin,
        const idMat3& modelAxis, int modelEntityNum, int modelPhysicsId,
        int modelBodyId, int selfId, int modelContentsOverride);
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(cm_sphereModel_t) == 52,
    "Recovered cm_sphereModel_t ABI changed");
static_assert(sizeof(cm_sphereModelPtrs_t) == 24,
    "Recovered cm_sphereModelPtrs_t ABI changed");
#endif
