#include "models/rendermodelimposter.h"

idRenderModelImposter::idRenderModelImposter()
    : parent(nullptr) {
}

bool idRenderModelImposter::UpdateInView(const idRenderView* view,
        const idRenderView* previousView, idRenderModelUpdateTools* tools) {
    return parent != nullptr && parent->UpdateInView(view, previousView, tools);
}

void idRenderModelImposter::MimicRenderModel(idRenderModel* parentModel) {
    parent = parentModel;
    if (parent == nullptr) {
        return;
    }
    g = parent->g;
    referenceBounds = parent->referenceBounds;
    committed = parent->committed;
    useDeferredPosition = parent->useDeferredPosition;
    deferredOrigin = parent->deferredOrigin;
    deferredAxis = parent->deferredAxis;
}
