#include "models/detail/rendermodeldetailedit.h"

#include <cstring>

idRenderModelDetailEdit::UpdateCallback
    idRenderModelDetailEdit::updateCallback = nullptr;

idRenderModelDetailEdit::idRenderModelDetailEdit() {
    std::memset(vertexBuffers, 0, sizeof(vertexBuffers));
    std::memset(indexBuffers, 0, sizeof(indexBuffers));
}

void idRenderModelDetailEdit::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

bool idRenderModelDetailEdit::UpdateInView(const idRenderView* currentView,
    const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}
