#include "game/entities/cuttablemanager.h"

#include "gamelib/physics/clip.h"
#include "models/cuttable/rendermodelcuttablesurface.h"

namespace {
idCuttableManagerServices defaultCuttableManagerServices;
idCuttableManagerServices* cuttableManagerServices =
    &defaultCuttableManagerServices;
}

idVertexBuffer* idCuttableManagerServices::AllocateVertexBuffer(
        const int bytes, unsigned int) {
    idVertexBuffer* const buffer = new idVertexBuffer;
    buffer->size = bytes;
    buffer->offsetInOtherBuffer = 0;
    buffer->apiObject = nullptr;
    buffer->usage = BU_DYNAMIC;
    return buffer;
}

idIndexBuffer* idCuttableManagerServices::AllocateIndexBuffer(
        const int bytes) {
    idIndexBuffer* const buffer = new idIndexBuffer;
    buffer->size = bytes;
    buffer->offsetInOtherBuffer = 0;
    buffer->apiObject = nullptr;
    buffer->usage = BU_DYNAMIC;
    return buffer;
}

void idCuttableManagerServices::ResizeVertexBuffer(
        idVertexBuffer& buffer, const int bytes, unsigned int) {
    buffer.size = bytes;
    buffer.usage = BU_DYNAMIC;
}

void idCuttableManagerServices::ResizeIndexBuffer(
        idIndexBuffer& buffer, const int bytes) {
    buffer.size = bytes;
    buffer.usage = BU_DYNAMIC;
}

void idCuttableManagerServices::UploadVertexBuffer(
        idVertexBuffer&, const void*, int) {}
void idCuttableManagerServices::UploadIndexBuffer(
        idIndexBuffer&, const void*, int) {}
void idCuttableManagerServices::FreeVertexBuffer(
        idVertexBuffer* const buffer) { delete buffer; }
void idCuttableManagerServices::FreeIndexBuffer(
        idIndexBuffer* const buffer) { delete buffer; }
int idCuttableManagerServices::GetShowPhysics() const { return 0; }

void idCuttableManager::SetServices(
        idCuttableManagerServices* const services) {
    cuttableManagerServices = services != nullptr ? services
        : &defaultCuttableManagerServices;
}

idCuttableManagerServices& idCuttableManager::Services() {
    return *cuttableManagerServices;
}

// Retail: 0x82C1B528 ?SubmitCollisionQueries@idCuttableManager@@QAAXXZ
void idCuttableManager::SubmitCollisionQueries() {
    effectPhysics.SubmitCollisionQueries();
}

// Retail: 0x82C1B530 ?Emit@idCuttableManager@@QAAHABUcuttablePhysicsEmitInfo_t@@ABV?$idList@VidDrawVert@@$04@@ABV?$idList@VidVec2@@$04@@ABV?$idList@G$04@@@Z
int idCuttableManager::Emit(const cuttablePhysicsEmitInfo_t& emitInfo,
        const idList<idDrawVert, 5>& vertices,
        const idList<idVec2, 5>& st,
        const idList<unsigned short, 5>& indices) {
    return effectPhysics.Emit(emitInfo, vertices, st, indices);
}

// Retail: 0x82C1B538 ?ClearCuttable@idCuttableManager@@QAAXH@Z
void idCuttableManager::ClearCuttable(const int index) {
    if (index < 0 || index >= infoCuttables.Num()) {
        return;
    }
    cuttableInfo_t& info = infoCuttables[index];
    info.renderModel = nullptr;
    info.physics = nullptr;
    info.outerContour = nullptr;
    info.innerContour = nullptr;
}

// Retail: 0x82C1B560 ?Update@idCuttableManager@@QAAXHH@Z
void idCuttableManager::Update(const int currentTime,
        const unsigned int gameMsPerFrame) {
    effectPhysics.UpdateSimulation(idVec3(0.0f, 0.0f, 0.0f),
        idMat3(1.0f), currentTime, static_cast<int>(gameMsPerFrame));
    effectPhysics.UpdateModel(idVec3(1.0f, 1.0f, 1.0f), currentTime);
    const int showPhysics = Services().GetShowPhysics();
    if (showPhysics != 0) {
        effectPhysics.DrawCollisionModels(
            showPhysics >= 0 ? -1 : -1 - showPhysics);
    }
}

// Retail: 0x82C1B770 ?Shutdown@idCuttableManager@@QAAXXZ
void idCuttableManager::Shutdown() {
    for (int index = 0; index < vertexBuffers.Num(); ++index) {
        Services().FreeVertexBuffer(vertexBuffers[index]);
    }
    for (int index = 0; index < stBuffers.Num(); ++index) {
        Services().FreeVertexBuffer(stBuffers[index]);
    }
    for (int index = 0; index < indexBuffers.Num(); ++index) {
        Services().FreeIndexBuffer(indexBuffers[index]);
    }
    vertexBuffers.Clear();
    stBuffers.Clear();
    indexBuffers.Clear();
    freeBuffer = -1;
}

// Retail: 0x82C1B7B8 ?UpdateModel@idCuttableManager@@QAAXHPAVContour@@0@Z
void idCuttableManager::UpdateModel(const int infoHandle,
        Contour* const outer, Contour* const inner) {
    if (infoHandle < 0 || infoHandle >= infoCuttables.Num()) {
        return;
    }
    cuttableInfo_t& info = infoCuttables[infoHandle];
    info.outerContour = outer;
    info.innerContour = inner;
    idRenderModelCuttableSurface* const renderModel = info.renderModel;
    if (renderModel == nullptr) {
        return;
    }

    idList<idDrawVert, 5> vertices;
    idList<idVec2, 5> st;
    idList<unsigned short, 5> indices;
    renderModel->BuildGeometry(outer, inner, vertices, st, indices);
    if (freeBuffer < 0 || freeBuffer >= vertexBuffers.Num()
            || freeBuffer >= stBuffers.Num()
            || freeBuffer >= indexBuffers.Num()) {
        freeBuffer = AllocateBuffer();
    }
    if (freeBuffer < 0) {
        return;
    }

    idVertexBuffer* const vertexBuffer = vertexBuffers[freeBuffer];
    idVertexBuffer* const stBuffer = stBuffers[freeBuffer];
    idIndexBuffer* const indexBuffer = indexBuffers[freeBuffer];
    const int vertexBytes = vertices.Num()
        * static_cast<int>(sizeof(idDrawVert));
    const int stBytes = st.Num() * static_cast<int>(sizeof(idVec2));
    const int indexBytes = indices.Num()
        * static_cast<int>(sizeof(unsigned short));
    if ((vertexBuffer->size & 0x7FFFFFFF) < vertexBytes) {
        Services().ResizeVertexBuffer(*vertexBuffer, vertexBytes, 31);
    }
    if ((stBuffer->size & 0x7FFFFFFF) < stBytes) {
        Services().ResizeVertexBuffer(*stBuffer, stBytes, 9216);
    }
    if ((indexBuffer->size & 0x7FFFFFFF) < indexBytes) {
        Services().ResizeIndexBuffer(*indexBuffer, indexBytes);
    }
    Services().UploadVertexBuffer(*vertexBuffer, vertices.Ptr(), vertexBytes);
    Services().UploadVertexBuffer(*stBuffer, st.Ptr(), stBytes);
    Services().UploadIndexBuffer(*indexBuffer, indices.Ptr(), indexBytes);
    freeBuffer = renderModel->UpdateGeometry(freeBuffer,
        *vertexBuffer, *stBuffer, *indexBuffer,
        vertices.Num(), indices.Num());
}

// Retail: 0x82C1BB28 ??0idCuttableManager@@QAA@XZ
idCuttableManager::idCuttableManager()
    : infoCuttables(), nameCuttables(), vertexBuffers(), stBuffers(),
      indexBuffers(), effectPhysics(), freeBuffer(-1) {
}

// Retail: 0x82C1BCE0 ??1idCuttableManager@@QAA@XZ
idCuttableManager::~idCuttableManager() {
    Shutdown();
}

// Retail: 0x82C1C020 ?AllocateBuffer@idCuttableManager@@AAAHXZ
int idCuttableManager::AllocateBuffer() {
    const int index = vertexBuffers.Num();
    idVertexBuffer* const vertex =
        Services().AllocateVertexBuffer(0x4000, 31);
    idVertexBuffer* const texture =
        Services().AllocateVertexBuffer(4096, 9216);
    idIndexBuffer* const indices = Services().AllocateIndexBuffer(3072);
    if (vertex == nullptr || texture == nullptr || indices == nullptr) {
        Services().FreeVertexBuffer(vertex);
        Services().FreeVertexBuffer(texture);
        Services().FreeIndexBuffer(indices);
        return -1;
    }
    vertexBuffers.Append(vertex);
    stBuffers.Append(texture);
    indexBuffers.Append(indices);
    return index;
}

// Retail: 0x82C1C1E8 ?Init@idCuttableManager@@QAAXPAVidRenderWorld@@PAVidSoundWorld@@PAVidClip@@@Z
void idCuttableManager::Init(idRenderWorld* const renderWorld,
        idSoundWorld* const soundWorld, idClip* const clip) {
    effectPhysics.Init(renderWorld, soundWorld, clip,
        clip != nullptr ? clip->traceModelCache : nullptr);
    freeBuffer = AllocateBuffer();
}

// Retail: 0x82C1C230 ?AllocateCuttable@idCuttableManager@@QAAHABVidStr@@PAVidRenderModelCuttableSurface@@PAVidPhysics@@@Z
int idCuttableManager::AllocateCuttable(const idStr& name,
        idRenderModelCuttableSurface* const renderModel,
        idPhysics* const physics) {
    const int index = infoCuttables.Num();
    cuttableInfo_t info;
    info.renderModel = renderModel;
    info.physics = physics;
    infoCuttables.Append(info);
    nameCuttables.Append(name);
    if (renderModel != nullptr) {
        renderModel->bufferIndex = AllocateBuffer();
    }
    return index;
}
