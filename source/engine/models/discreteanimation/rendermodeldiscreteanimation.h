#pragma once

#include "idlib/geometry/jointtransform.h"
#include "models/discreteanimation/discreteanimationmodeldata.h"
#include "models/rendermodel.h"

class idDeclBreakable;
class idDecl;

class alignas(16) idRenderModelDiscreteAnimation : public idRenderModel {
public:
    using UpdateCallback = bool (*)(idRenderModelDiscreteAnimation* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);
    using ModelResolver = const idDiscreteAnimationModelData* (*)(
        const char* modelName);
    using BreakableResolver = const idDeclBreakable* (*)(
        const idDecl* declaration);
    using ShadowPolicyCallback = bool (*)(
        const idDeclBreakable* declaration);
    using JointBufferInitCallback = bool (*)(idJointBuffer* buffer,
        const idJointMat* joints, int numJoints);
    using JointBufferUpdateCallback = bool (*)(idJointBuffer* buffer,
        const idJointMat* joints, int numJoints);
    using JointBufferReferenceCallback = bool (*)(idJointBuffer* reference,
        const idJointBuffer* source, int firstJoint, int numJoints);
    using JointBufferFreeCallback = void (*)(idJointBuffer* buffer);

    idRenderModelDiscreteAnimation();
    idRenderModelDiscreteAnimation(const char* modelName,
        const idDecl* declaration);
    ~idRenderModelDiscreteAnimation() override;
    static void SetUpdateCallback(UpdateCallback callback);
    static void SetRuntimeCallbacks(ModelResolver modelResolver,
        BreakableResolver breakableResolver,
        ShadowPolicyCallback shadowPolicy);
    static void SetJointBufferCallbacks(JointBufferInitCallback initialize,
        JointBufferUpdateCallback update,
        JointBufferReferenceCallback reference,
        JointBufferFreeCallback freeBuffer);

    void Save(idFile* file) override;
    bool Load(idFile* file) override;
    void SerializeSnapshot(idSerializer* serializer,
        bool serializeParmBlock) override;
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;
    bool CommitSubclass() override;
    const idList<sourceSurface_t, 5>* GetSourceSurfaces() const override;

    bool LoadModel(const char* modelName);
    void SetModelData(const idDiscreteAnimationModelData* data);
    void Update();
    void Reset();
    int GetNumPieces() const;
    const idDeclBreakable* GetDeclBreakable() const;
    bool GetPiecePosition(int index, idVec3& position,
        idMat3& orientation) const;
    bool SetPiecePosition(int index, const idVec3& position,
        const idMat3& orientation);
    bool CollapsePiece(int index);
    bool SetBasePiecePosition(const idVec3& position,
        const idMat3& orientation);
    bool GetPieceTraceModel(int index, idTraceModel& traceModel) const;

    const idDiscreteAnimationModelData* modelData;
    const idDeclBreakable* declBreakable;
    unsigned int modelTimestamp;
    idJointBuffer jointBuffers[2];
    int currentJointBuffer;
    idList<idJointMat, 59> transforms;
    idList<bool, 59> collapsed;
    bool changed;

private:
    void LoadModelData();
    void FreeModelSurfaces();
    void ReferenceSurfaceJointBuffers();
    void UpdateReferenceBounds();

    static UpdateCallback updateCallback;
    static ModelResolver modelResolver;
    static BreakableResolver breakableResolver;
    static ShadowPolicyCallback shadowPolicyCallback;
    static JointBufferInitCallback jointBufferInitCallback;
    static JointBufferUpdateCallback jointBufferUpdateCallback;
    static JointBufferReferenceCallback jointBufferReferenceCallback;
    static JointBufferFreeCallback jointBufferFreeCallback;
};
