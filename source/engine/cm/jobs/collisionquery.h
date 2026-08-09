#pragma once

#include "cm/jobs/collisionresults.h"
#include "cm/collisiontypes.h"

#include <cstdint>

enum traceType_t : int {
    TRACE_INVALID = 0,
    TRACE_TRANSLATION = 1,
    TRACE_TRANSLATION_POINT = 2,
    TRACE_ROTATION = 3,
    TRACE_ROTATION_POINT = 4,
    TRACE_CONTENTS = 5,
    TRACE_CONTENTS_POINT = 6,
    TRACE_CONTACTS_UNI_DIR = 7,
    TRACE_CONTACTS_OMNI_DIR = 8,
    TRACE_CLIP = 9
};

enum queryStatus_t : int {
    QUERY_STATUS_PENDING = 0,
    QUERY_STATUS_SUCCESS = 1,
    QUERY_STATUS_BAD_START = 2,
    QUERY_STATUS_FAILED = 4
};

enum dependencyType_t : int {
    DEPENDENCY_NONE = 0,
    DEPENDENCY_MOTION_ROTATION = 1,
    DEPENDENCY_MOTION_CONTACTS = 2,
    DEPENDENCY_STEPMOVE_STEP_UP = 3,
    DEPENDENCY_STEPMOVE_2ND_MOVE = 4,
    DEPENDENCY_STEPMOVE_STEP_DOWN = 5,
    DEPENDENCY_STEPMOVE_CONTACTS = 6,
    DEPENDENCY_SLIDEMOVE_STEP_UP_1 = 7,
    DEPENDENCY_SLIDEMOVE_STEP_UP_2 = 8,
    DEPENDENCY_SLIDEMOVE_STEP_UP_3 = 9,
    DEPENDENCY_SLIDEMOVE_STEP_UP_4 = 10,
    DEPENDENCY_SLIDEMOVE_2ND_MOVE_1 = 11,
    DEPENDENCY_SLIDEMOVE_2ND_MOVE_2 = 12,
    DEPENDENCY_SLIDEMOVE_2ND_MOVE_3 = 13,
    DEPENDENCY_SLIDEMOVE_2ND_MOVE_4 = 14,
    DEPENDENCY_SLIDEMOVE_STEP_DOWN_1 = 15,
    DEPENDENCY_SLIDEMOVE_STEP_DOWN_2 = 16,
    DEPENDENCY_SLIDEMOVE_STEP_DOWN_3 = 17,
    DEPENDENCY_SLIDEMOVE_STEP_DOWN_4 = 18,
    DEPENDENCY_SLIDEMOVE_SLIDE = 19,
    DEPENDENCY_SLIDEMOVE_CONTACTS = 20,
    DEPENDENCY_LOCAL_SPACE = 21
};

class idCollisionQuery {
public:
    std::uint64_t offset;
};

class idTraceModel;
struct idTraceWork;
class idJointMat;
struct queryResults_t;

struct queryParms_t {
    traceType_t type;
    bool autoMerge;
    bool testQuery;
    std::uint8_t pad[10];
    idVec3 start;
    idVec3 end;
    idVec3 rotationOrigin;
    idVec3 rotationAxis;
    float rotationAngle;
    idVec3 dir;
    float depth;
    idMat3 trmAxis;
    int contentMask;
    idVec3 modelOrigin;
    idMat3 modelAxis;
    int modelEntityNum;
    int modelPhysicsId;
    int modelBodyId;
    int modelContentsOverride;
    int selfId;
};

class idCollisionQueryExecute {
public:
    static void ExecuteSubModelQuery(idTraceWork* tw,
        queryResults_t& results, const queryParms_t* parms,
        const idTraceModel* trm, const cm_subModelData_t* subModelData,
        int subModelNum);
    static void ExecutePolygonModelQuery(idTraceWork* tw,
        queryResults_t& results, const queryParms_t* parms,
        const idTraceModel* trm, const cm_polygonModel_t* polygonModel);
    static void ExecuteSphereModelQuery(queryResults_t& results,
        const queryParms_t* parms, const idJointMat* modelJoints,
        const cm_sphereModel_t* sphereModel);
    static void SetupDependentParms(queryParms_t* resultParms,
        const queryParms_t* sourceParms,
        const queryResults_t* modelPosition,
        dependencyType_t dependencyType,
        const queryResults_t* dependency1,
        const queryResults_t* dependency2);
};

struct queryResults_t {
    struct query_t {
        traceType_t type;
        int done;
        int merged;
        queryStatus_t status;
        std::uint16_t executeThreadId;
        std::uint16_t mergeThreadId;
        std::uint32_t profile[5];
        std::uint64_t modelQueryIndex;
    } query;
    std::uint8_t data[928];
};

static_assert(sizeof(idCollisionQuery) == 8,
    "Recovered idCollisionQuery ABI changed");
static_assert(sizeof(queryResults_t::query_t) == 48,
    "Recovered queryResults_t::query_t ABI changed");
static_assert(sizeof(queryResults_t) == 976,
    "Recovered queryResults_t ABI changed");
static_assert(sizeof(queryParms_t) == 192,
    "Recovered queryParms_t ABI changed");
