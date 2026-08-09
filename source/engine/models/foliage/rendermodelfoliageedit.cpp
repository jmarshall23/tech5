#include "models/foliage/rendermodelfoliageedit.h"

idRenderModelFoliageEdit::UpdateCallback
    idRenderModelFoliageEdit::updateCallback = nullptr;

idRenderModelFoliageEdit::idRenderModelFoliageEdit()
    : numFoliageQuadsInView(0), maxFoliageQuadsAllowed(0) {
}

void idRenderModelFoliageEdit::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

bool idRenderModelFoliageEdit::UpdateInView(
    const idRenderView* currentView, const idRenderView* nextView,
    idRenderModelUpdateTools* tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}
