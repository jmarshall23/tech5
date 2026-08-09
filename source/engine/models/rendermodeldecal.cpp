#include "models/rendermodeldecal.h"

#include <cstring>

idRenderModelDecal::UpdateCallback idRenderModelDecal::updateCallback = nullptr;

idRenderModelDecal::idRenderModelDecal()
    : decals(nullptr), tireDecals(nullptr), gameTime(0), latchedTime(0),
      usesPreAllocatedBuffer(false), triangles(nullptr) {
    std::memset(decalRange, 0, sizeof(decalRange));
    std::memset(tireDecalRange, 0, sizeof(tireDecalRange));
    std::memset(latchedDecalRange, 0, sizeof(latchedDecalRange));
    std::memset(latchedTireDecalRange, 0, sizeof(latchedTireDecalRange));
    std::memset(vertexBuffer, 0, sizeof(vertexBuffer));
    std::memset(&indexBufferBoxes, 0, sizeof(indexBufferBoxes));
    std::memset(&indexBufferQuads, 0, sizeof(indexBufferQuads));
    std::memset(parmPositionToLocalBoxSpace, 0,
        sizeof(parmPositionToLocalBoxSpace));
}

void idRenderModelDecal::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

bool idRenderModelDecal::UpdateInView(const idRenderView* currentView,
    const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}
