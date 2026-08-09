#pragma once

#include "framework/resource.h"
#include "framework/resourcelist.h"
#include "idlib/bv/bounds.h"
#include "idlib/geometry/jointtransform.h"
#include "idlib/geometry/tracemodel.h"
#include "models/rendermodel.h"

class idCollisionModel;

class idDiscreteAnimationModelSurface {
public:
    int jointOffset;
    int numJoints;
    idTriangles* triangles;
};

class idDiscreteAnimationModelData : public idResource {
public:
    using MaterialResolver = const idMaterial* (*)(const char* name);
    using MaterialNameResolver = const char* (*)(const idMaterial* material);
    using MaterialChecksumResolver = int (*)(const idMaterial* material);
    using CollisionModelResolver = idCollisionModel* (*)(const char* name);
    using CollisionModelNameResolver = const char* (*)(
        const idCollisionModel* model);
    using GenerateCallback = bool (*)(idDiscreteAnimationModelData* data,
        const char* baseCollisionName);
    using SurfaceRemapCallback = void (*)(
        idDiscreteAnimationModelData* data);
    using BufferUpdateCallback = void (*)(idTriangles* triangles);

    idDiscreteAnimationModelData();
    ~idDiscreteAnimationModelData() override;

    void LoadResource() override;
    bool ReloadIfStale() override;
    idResourceList* GetResourceList() override;

    bool LoadBinary(const char* fileName);
    bool WriteBinary(const char* fileName) const;
    bool Generate(const char* baseCollisionName = nullptr);
    void UpdateBuffers();
    void FreeCPUData();
    void RemapSourceSurfaces();
    void FreeData();

    static void SetMaterialCallbacks(MaterialResolver resolver,
        MaterialNameResolver nameResolver,
        MaterialChecksumResolver checksumResolver);
    static void SetCollisionModelCallbacks(CollisionModelResolver resolver,
        CollisionModelNameResolver nameResolver);
    static void SetGenerateCallback(GenerateCallback callback);
    static void SetSurfaceRemapCallback(SurfaceRemapCallback callback);
    static void SetBufferUpdateCallback(BufferUpdateCallback callback);
    static void SetFreeCPUDataAfterUpload(bool enabled);

    unsigned int timestamp;
    float maxRadius;
    idBounds bounds;
    const idMaterial* material;
    idList<idTraceModel, 59> traceModels;
    idList<idJointMat, 59> transforms;
    idList<idDiscreteAnimationModelSurface*, 59> surfaces;
    idList<sourceSurface_t, 59> sourceSurfaces;
    idCollisionModel* baseModel;

    static idTypedResourceList<idDiscreteAnimationModelData> resourceList;

private:
    static MaterialResolver materialResolver;
    static MaterialNameResolver materialNameResolver;
    static MaterialChecksumResolver materialChecksumResolver;
    static CollisionModelResolver collisionModelResolver;
    static CollisionModelNameResolver collisionModelNameResolver;
    static GenerateCallback generateCallback;
    static SurfaceRemapCallback surfaceRemapCallback;
    static BufferUpdateCallback bufferUpdateCallback;
    static bool freeCPUDataAfterUpload;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idDiscreteAnimationModelSurface) == 12,
    "Recovered discrete-animation surface ABI changed");
#endif
