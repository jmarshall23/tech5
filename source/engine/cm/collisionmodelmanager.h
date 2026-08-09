#pragma once

#include "cm/collisionqueryjobmanager.h"

class idCollisionModel;
class idCollisionGrid;
class idCollisionGridState;
class idJointMat;
class idMapFile;
class idMaterial;
class idRenderModel;
class idStaticModel;
class idTraceModel;
class idVec3;
class idMat3;

class idCollisionDebugDrawSink {
public:
    virtual ~idCollisionDebugDrawSink() = default;
    virtual void DrawLine(const idVec3& start, const idVec3& end,
        bool internalEdge, int lifeTime) = 0;
    virtual void DrawPolygon(const idVec3* points, int numPoints,
        int contents, int surfaceFlags, int surfaceType,
        int lifeTime) = 0;
    virtual void DrawSphere(const idVec3& center, float radius,
        int surfaceType, int lifeTime) = 0;
};

int ContentsFromString(const char* string);

class idTrmFromSubModel {
public:
    static bool TrmFromSubModel(const idCollisionModelLocal* model,
        const cm_subModelData_t* subModelData, idTraceModel& trm);
};

class idCollisionModelManager {
public:
    static void SetDebugDrawSink(idCollisionDebugDrawSink* sink);

    idCollisionModel* ModelFromTrm(const char* modelName,
        const idTraceModel& traceModel, const idMaterial* material);
    idCollisionModel* BuildModel(const char* modelName,
        const idStaticModel* staticModel, const int* subModelIndices,
        int numSubModelIndices);
    void BuildModelsForMapFile(const idMapFile* mapFile,
        bool mapModelOnly);
    idCollisionModel* ModelFromRender(const char* modelName,
        const idRenderModel* renderModel);
    idCollisionModel* ModelFromGrid(const char* modelName,
        const idCollisionGrid* grid, const idCollisionGridState& state,
        const idMaterial* material);
    void DrawCollisionModel(idCollisionModel* model,
        const idJointMat* modelJoints, const idVec3& modelOrigin,
        const idMat3& modelAxis, const idVec3& viewOrigin,
        const idMat3& viewAxis, float radius, int lifeTime);
    void DebugOutput(const idVec3& viewOrigin, const idMat3& viewAxis);

    void Init();
    void Shutdown();
    void StartQueryFrame();
    void EndQueryFrame();
    void SubmitQueries();
    void WaitForAllQueries();

    idCollisionModel* LoadModel(const char* modelName);
    idCollisionGrid* LoadGrid(const char* modelName);
    int FindStreamArea(idCollisionModel* model, const char* areaName);
    void StreamModel(idCollisionModel* model, const int* areaIndices,
        int numAreaIndices, bool wait);
    bool IsResident(const idBounds& bounds,
        const idPositionedCollisionModel* models, int numModels);
    bool TrmFromModel(const char* modelName, idTraceModel& trm);
    int CompoundTrmFromModel(const char* modelName, idTraceModel* trms,
        int maxTrms, int* invalidSubmodelIndices,
        int* numInvalidIndices);

    idCollisionQuery Translation(trace_t* result, const idVec3& start,
        const idVec3& end, const idBounds& globalBounds,
        const idTraceModel** trms, int numTrms, const idMat3& trmAxis,
        int contentMask, const idPositionedCollisionModel* models,
        int numModels, const char* userName);
    idCollisionQuery LocalTranslation(idCollisionQuery localSpace,
        const idVec3& start, const idVec3& end,
        const idBounds& globalBounds, const idTraceModel** trms,
        int numTrms, const idMat3& trmAxis, int contentMask,
        const idPositionedCollisionModel* models, int numModels,
        const char* userName);
    idCollisionQuery Rotation(trace_t* result, const idVec3& start,
        const idRotation& rotation, const idBounds& globalBounds,
        const idTraceModel** trms, int numTrms, const idMat3& trmAxis,
        int contentMask, const idPositionedCollisionModel* models,
        int numModels, const char* userName);
    idCollisionQuery Motion(trace_t* result, const idVec3& start,
        const idVec3& end, const idRotation& rotation,
        const idBounds& globalBounds, const idTraceModel** trms,
        int numTrms, const idMat3& trmAxis, int contentMask,
        const idPositionedCollisionModel* models, int numModels,
        const char* userName);
    idCollisionQuery MotionContacts(trace_t* result,
        contactsResult_t* contacts, const idVec3& start,
        const idVec3& end, const idRotation& rotation, float depth,
        const idBounds& globalBounds, const idTraceModel** trms,
        int numTrms, const idMat3& trmAxis, int contentMask,
        const idPositionedCollisionModel* models, int numModels,
        const char* userName);
    idCollisionQuery Contents(trace_t* result, const idVec3& start,
        const idBounds& globalBounds, const idTraceModel** trms,
        int numTrms, const idMat3& trmAxis, int contentMask,
        const idPositionedCollisionModel* models, int numModels,
        const char* userName);
    idCollisionQuery LocalContents(idCollisionQuery localSpace,
        const idVec3& start, const idBounds& globalBounds,
        const idTraceModel** trms, int numTrms, const idMat3& trmAxis,
        int contentMask, const idPositionedCollisionModel* models,
        int numModels, const char* userName);
    idCollisionQuery Contacts(contactsResult_t* result,
        const idVec3& start, const idVec3& direction, float depth,
        const idBounds& globalBounds, const idTraceModel** trms,
        int numTrms, const idMat3& trmAxis, int contentMask,
        const idPositionedCollisionModel* models, int numModels,
        const char* userName);
    idCollisionQuery Clip(clipResult_t* result, const idVec3& start,
        const idBounds& globalBounds, const idTraceModel** trms,
        int numTrms, const idMat3& trmAxis, int contentMask,
        const idPositionedCollisionModel* models, int numModels,
        const char* userName);
    idCollisionQuery StepMove(trace_t* result, const idVec3& start,
        const idVec3& end, const idVec3& downNormal, float stepUp,
        float stepDown, const idBounds& globalBounds,
        const idTraceModel** trms, int numTrms, const idMat3& trmAxis,
        int contentMask, const idPositionedCollisionModel* models,
        int numModels, const char* userName);
    idCollisionQuery StepMoveContacts(trace_t* result,
        contactsResult_t* contacts, const idVec3& start,
        const idVec3& end, const idVec3& downNormal, float stepUp,
        float stepDown, const idBounds& globalBounds,
        const idTraceModel** trms, int numTrms, const idMat3& trmAxis,
        int contentMask, const idPositionedCollisionModel* models,
        int numModels, const char* userName);
    idCollisionQuery SlideMove(trace_t* result, const idVec3& start,
        const idVec3& velocity, const idVec3& gravityVector,
        float stepUp, float stepDown, const idBounds& globalBounds,
        const idTraceModel** trms, int numTrms, const idMat3& trmAxis,
        int contentMask, const idPositionedCollisionModel* models,
        int numModels, const char* userName);
    idCollisionQuery SlideMoveContacts(trace_t* result,
        contactsResult_t* contacts, const idVec3& start,
        const idVec3& velocity, const idVec3& gravityVector,
        float stepUp, float stepDown, const idBounds& globalBounds,
        const idTraceModel** trms, int numTrms, const idMat3& trmAxis,
        int contentMask, const idPositionedCollisionModel* models,
        int numModels, const char* userName);

    bool GetContentsResult(trace_t* result, idCollisionQuery& query,
        bool peek);
    bool GetMotionContactsResult(trace_t* result,
        contactsResult_t* contacts, idCollisionQuery& query, bool peek);
    bool GetClipResult(clipResult_t* result, idCollisionQuery& query,
        bool peek);
    bool GetStepMoveContactsResult(trace_t* result,
        contactsResult_t* contacts, idCollisionQuery& query, bool peek);
};

extern idCollisionModelManager collisionModelManager;

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idCollisionModelManager) == 1,
    "Recovered idCollisionModelManager ABI changed");
#endif
