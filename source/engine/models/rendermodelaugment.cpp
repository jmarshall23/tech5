#include "models/rendermodelaugment.h"

idRenderModelAugmentOutline::OutlineResourcesCallback
    idRenderModelAugmentOutline::outlineResourcesCallback = nullptr;

idRenderModelAugmentOutline::idRenderModelAugmentOutline() {
    g.isAugment = 1;
    g.addAlways = 1;
    g.noShadow = 1;

    const idMaterial* material = nullptr;
    idTriangles* geometry = nullptr;
    if (outlineResourcesCallback != nullptr &&
            outlineResourcesCallback(material, geometry) &&
            geometry != nullptr) {
        idRenderModelSurface surface{};
        surface.material = material;
        surface.extraGLState = 0x100u;
        surface.geometry = geometry;
        surface.geometryIsReference = true;
        AddSurface(surface);
    }
}

bool idRenderModelAugmentOutline::CommitSubclass() {
    if (g.customMaterial != nullptr) {
        for (int index = 0; index < surfaces.Num(); ++index)
            surfaces[index].material = g.customMaterial;
    }
    return false;
}

void idRenderModelAugmentOutline::SetOutlineResourcesCallback(
        OutlineResourcesCallback callback) {
    outlineResourcesCallback = callback;
}
