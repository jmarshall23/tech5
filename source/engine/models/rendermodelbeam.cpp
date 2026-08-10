#include "models/rendermodelbeam.h"

#include <cstring>
#include <algorithm>

idVertexBuffer idRenderModelBeam::preAllocatedVertexBuffer[2]{};
idIndexBuffer idRenderModelBeam::preAllocatedIndexBuffer{};
bool idRenderModelBeam::preAllocatedBufferInUse = false;
bool idRenderModelBeam::preAllocatedBufferReady = false;
idRenderModelBeam::BufferAllocateCallback
    idRenderModelBeam::bufferAllocateCallback = nullptr;
idRenderModelBeam::BufferReferenceCallback
    idRenderModelBeam::bufferReferenceCallback = nullptr;
idRenderModelBeam::BufferFreeCallback idRenderModelBeam::bufferFreeCallback =
    nullptr;
idRenderModelBeam::UpdateCallback idRenderModelBeam::updateCallback = nullptr;

idRenderModelBeam::idRenderModelBeam()
    : beamRenderBufferIndex(0), triangles(nullptr),
      usesPreAllocatedBuffer(false) {
    std::memset(vertexBuffer, 0, sizeof(vertexBuffer));
    std::memset(&indexBuffer, 0, sizeof(indexBuffer));
    g.addAlways = 1;
    g.noShadow = 1;
    if (preAllocatedBufferReady && !preAllocatedBufferInUse) {
        if (bufferReferenceCallback != nullptr) {
            bufferReferenceCallback(vertexBuffer, preAllocatedVertexBuffer,
                2, &indexBuffer, &preAllocatedIndexBuffer);
        } else {
            std::memcpy(vertexBuffer, preAllocatedVertexBuffer,
                sizeof(vertexBuffer));
            indexBuffer = preAllocatedIndexBuffer;
        }
        preAllocatedBufferInUse = true;
        usesPreAllocatedBuffer = true;
    } else if (bufferAllocateCallback != nullptr) {
        bufferAllocateCallback(vertexBuffer, 2, &indexBuffer, 32512,
            48768, 0x1Fu);
    }
    triangles = new idTriangles[32]{};
    for (int index = 0; index < 32; ++index) {
        triangles[index].bounds[0].Set(-99999.0f, -99999.0f, -99999.0f);
        triangles[index].bounds[1].Set(99999.0f, 99999.0f, 99999.0f);
    }
}

idRenderModelBeam::~idRenderModelBeam() {
    if (usesPreAllocatedBuffer)
        preAllocatedBufferInUse = false;
    if (bufferFreeCallback != nullptr)
        bufferFreeCallback(vertexBuffer, 2, &indexBuffer);
    delete[] triangles;
    triangles = nullptr;
}

void idRenderModelBeam::Init() {
    if (preAllocatedBufferReady || bufferAllocateCallback == nullptr) return;
    preAllocatedBufferReady = bufferAllocateCallback(
        preAllocatedVertexBuffer, 2, &preAllocatedIndexBuffer, 32512,
        48768, 0x1Fu);
}

void idRenderModelBeam::Shutdown() {
    if (preAllocatedBufferReady && bufferFreeCallback != nullptr) {
        bufferFreeCallback(preAllocatedVertexBuffer, 2,
            &preAllocatedIndexBuffer);
    }
    std::memset(preAllocatedVertexBuffer, 0,
        sizeof(preAllocatedVertexBuffer));
    std::memset(&preAllocatedIndexBuffer, 0,
        sizeof(preAllocatedIndexBuffer));
    preAllocatedBufferReady = false;
    preAllocatedBufferInUse = false;
}

void idRenderModelBeam::SetBufferCallbacks(
        BufferAllocateCallback allocate, BufferReferenceCallback reference,
        BufferFreeCallback freeBuffers) {
    bufferAllocateCallback = allocate;
    bufferReferenceCallback = reference;
    bufferFreeCallback = freeBuffers;
}

void idRenderModelBeam::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

bool idRenderModelBeam::UpdateInView(const idRenderView* currentView,
    const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}

void idRenderModelBeam::Update(int) {
    beamBuffer[beamRenderBufferIndex ^ 1].Clear();
    CommitThisFrame();
}

bool idRenderModelBeam::CommitSubclass() {
    beamBuffer[beamRenderBufferIndex].Clear();
    beamRenderBufferIndex ^= 1;
    return false;
}

beam_t* idRenderModelBeam::DrawBeamAlloc() {
    idStaticList<beam_t, 64>& writeBuffer =
        beamBuffer[beamRenderBufferIndex ^ 1];
    if (writeBuffer.Num() >= writeBuffer.Max()) return nullptr;
    beam_t* beam = writeBuffer.Alloc();
    if (beam != nullptr) {
        beam->nodes.Clear();
        beam->material = nullptr;
        beam->orientType = BEAM_ORIENT_VIEWER;
    }
    return beam;
}

void idRenderModelBeam::DrawBeam(beamNodeParms_t& node,
        const idMaterial* material, const beamOrientType_t orientType) {
    if (material == nullptr) return;
    beam_t* beam = DrawBeamAlloc();
    if (beam == nullptr) return;
    beam->material = material;
    beam->orientType = orientType;
    beam->nodes.Append(node);
}

void idRenderModelBeam::DrawBeam(const beamNodeParms_t* nodes,
        const int numNodes, const idMaterial* material,
        const beamOrientType_t orientType) {
    if (nodes == nullptr || numNodes <= 0 || material == nullptr) return;
    beam_t* beam = DrawBeamAlloc();
    if (beam == nullptr) return;
    beam->material = material;
    beam->orientType = orientType;
    const int count = (std::min)(numNodes, beam->nodes.Max());
    for (int index = 0; index < count; ++index)
        beam->nodes.Append(nodes[index]);
}
