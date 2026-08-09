#pragma once

#include "framework/resource.h"
#include "models/cuttable/triangleinterpolator.h"
#include "models/rendermodel.h"

class alignas(16) idRenderModelCuttableResource : public idResource {
public:
    using OpenBinaryCallback = idFile* (*)(const char* resourceName,
        unsigned int& timestamp);
    using CloseBinaryCallback = void (*)(idFile* file);
    using TimestampCallback = unsigned int (*)(const char* resourceName);
    using MaterialResolver = const idMaterial* (*)(const char* name);
    using BufferUploadCallback = void (*)(idTriangles* triangles,
        idVertexBuffer*& stMap, const idVec2* stData);
    using BufferReleaseCallback = void (*)(idTriangles* triangles,
        idVertexBuffer* stMap);
    using DepthMaterialCallback = const idMaterial* (*)(
        const idRenderModelCuttableResource* resource);

    idRenderModelCuttableResource();
    ~idRenderModelCuttableResource() override;

    static void SetFileCallbacks(OpenBinaryCallback open,
        CloseBinaryCallback close, TimestampCallback timestamp);
    static void SetMaterialResolver(MaterialResolver resolver);
    static void SetBufferCallbacks(BufferUploadCallback upload,
        BufferReleaseCallback release);
    static void SetDepthMaterialCallback(DepthMaterialCallback callback);

    void LoadResource() override;
    bool ReloadIfStale() override;
    bool LoadBinary(idFile* file, unsigned int fileTimestamp = 0);
    void BuildSurface(idRenderModel* model);
    void FreeCPUData();
    void FreeData();

    const idMaterial* sourceMaterial;
    const idMaterial* material;
    idTriangles* triangles;
    idVec2* stData;
    idVertexBuffer* stMap;
    idList<idVec3, 5> contourBound;
    idTriangleInterpolator triangleInterpolator;
    unsigned int timestamp;

private:
    void BuildDepthSurface(idRenderModelSurface* surface);
    static OpenBinaryCallback openBinaryCallback;
    static CloseBinaryCallback closeBinaryCallback;
    static TimestampCallback timestampCallback;
    static MaterialResolver materialResolver;
    static BufferUploadCallback bufferUploadCallback;
    static BufferReleaseCallback bufferReleaseCallback;
    static DepthMaterialCallback depthMaterialCallback;
};
