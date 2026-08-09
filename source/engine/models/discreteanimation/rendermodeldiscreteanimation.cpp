#include "models/discreteanimation/rendermodeldiscreteanimation.h"

#include <cstring>

idRenderModelDiscreteAnimation::UpdateCallback
    idRenderModelDiscreteAnimation::updateCallback = nullptr;

idRenderModelDiscreteAnimation::idRenderModelDiscreteAnimation()
    : modelData(nullptr), declBreakable(nullptr), modelTimestamp(0),
      currentJointBuffer(0), changed(false) {
    std::memset(jointBuffers, 0, sizeof(jointBuffers));
}

void idRenderModelDiscreteAnimation::SetUpdateCallback(
    UpdateCallback callback) {
    updateCallback = callback;
}

bool idRenderModelDiscreteAnimation::UpdateInView(
    const idRenderView* currentView, const idRenderView* nextView,
    idRenderModelUpdateTools* tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}

const idList<sourceSurface_t, 5>*
idRenderModelDiscreteAnimation::GetSourceSurfaces() const {
    return modelData != nullptr
        ? reinterpret_cast<const idList<sourceSurface_t, 5>*>(
              &modelData->sourceSurfaces)
        : nullptr;
}
