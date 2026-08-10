#include "models/rendermodelimposter.h"

#include <algorithm>

idRenderModelImposter::idRenderModelImposter()
    : parent(nullptr) {
}

bool idRenderModelImposter::UpdateInView(const idRenderView* view,
        const idRenderView* previousView, idRenderModelUpdateTools* tools) {
    (void)view;
    (void)previousView;
    (void)tools;
    if (parent == nullptr) return false;

    const int count = (std::min)(surfaces.Num(), parent->surfaces.Num());
    for (int index = 0; index < count; ++index) {
        idRenderModelSurface& destination = surfaces[index];
        const idRenderModelSurface& source = parent->surfaces[index];
        destination.geometry = source.geometry;
        destination.material = source.material;
        destination.materialNum = source.materialNum;
        destination.joints = source.joints;
        destination.morphMap = source.morphMap;
        destination.skinOffsets = source.skinOffsets;
        destination.extraGLState = source.extraGLState;
    }
    CommitSurfaces();
    return true;
}

void idRenderModelImposter::MimicRenderModel(idRenderModel* parentModel) {
    FreeSurfaces();
    parent = nullptr;
    if (parentModel == nullptr) return;

    SetMaxSurfaces(parentModel->surfaces.Num());
    for (int index = 0; index < parentModel->surfaces.Num(); ++index) {
        idRenderModelSurface surface = parentModel->surfaces[index];
        surface.geometryIsReference = true;
        surface.referenceMask = 3;
        AddSurface(surface);
    }
    FinishSurfaces();
    parent = parentModel;
}
