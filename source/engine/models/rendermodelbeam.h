#pragma once

#include "models/rendermodel.h"

#include <cstdint>

enum beamOrientType_t : int {
    BEAM_ORIENT_VIEWER = 0,
    BEAM_ORIENT_EXPLICIT,
    BEAM_ORIENT_EXPLICIT_BOTH_EDGES
};

struct beamNodeParms_t {
    idVec3 startPos;
    idVec3 endPos;
    idVec3 startPos2;
    idVec3 endPos2;
    idVec3 orientVec;
    idVec2 sMinMax;
    idVec2 tMinMax;
    float halfWidth;
    std::uint8_t color[4];
    std::uint8_t tangent[4][4];
};

struct beam_t {
    idStaticList<beamNodeParms_t, 128> nodes;
    const idMaterial* material;
    beamOrientType_t orientType;
};

class alignas(16) idRenderModelBeam : public idRenderModel {
public:
    using BufferAllocateCallback = bool (*)(idVertexBuffer* vertexBuffers,
        int numVertexBuffers, idIndexBuffer* indexBuffer, int maxVertices,
        int maxIndexes, unsigned int vertexMask);
    using BufferReferenceCallback = void (*)(idVertexBuffer* destination,
        const idVertexBuffer* source, int numVertexBuffers,
        idIndexBuffer* destinationIndex, const idIndexBuffer* sourceIndex);
    using BufferFreeCallback = void (*)(idVertexBuffer* vertexBuffers,
        int numVertexBuffers, idIndexBuffer* indexBuffer);
    using UpdateCallback = bool (*)(idRenderModelBeam* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);

    idRenderModelBeam();
    ~idRenderModelBeam() override;
    static void Init();
    static void Shutdown();
    static void SetBufferCallbacks(BufferAllocateCallback allocate,
        BufferReferenceCallback reference, BufferFreeCallback freeBuffers);
    static void SetUpdateCallback(UpdateCallback callback);
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;
    bool CommitSubclass() override;
    void Update(int currentTime);
    beam_t* DrawBeamAlloc();
    void DrawBeam(beamNodeParms_t& node, const idMaterial* material,
        beamOrientType_t orientType);
    void DrawBeam(const beamNodeParms_t* nodes, int numNodes,
        const idMaterial* material, beamOrientType_t orientType);

    idStaticList<beam_t, 64> beamBuffer[2];
    int beamRenderBufferIndex;
    idTriangles* triangles;
    idVertexBuffer vertexBuffer[2];
    idIndexBuffer indexBuffer;
    bool usesPreAllocatedBuffer;

private:
    static idVertexBuffer preAllocatedVertexBuffer[2];
    static idIndexBuffer preAllocatedIndexBuffer;
    static bool preAllocatedBufferInUse;
    static bool preAllocatedBufferReady;
    static BufferAllocateCallback bufferAllocateCallback;
    static BufferReferenceCallback bufferReferenceCallback;
    static BufferFreeCallback bufferFreeCallback;
    static UpdateCallback updateCallback;
};

static_assert(sizeof(beamNodeParms_t) == 100,
    "Recovered beam-node parameters ABI changed");
