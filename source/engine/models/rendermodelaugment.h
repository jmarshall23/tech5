#pragma once

#include "models/rendermodel.h"

class idRenderModelAugmentOutline : public idRenderModel {
public:
    using OutlineResourcesCallback = bool (*)(const idMaterial*& material,
        idTriangles*& geometry);

    idRenderModelAugmentOutline();
    ~idRenderModelAugmentOutline() override = default;

    bool CommitSubclass() override;
    static void SetOutlineResourcesCallback(
        OutlineResourcesCallback callback);

private:
    static OutlineResourcesCallback outlineResourcesCallback;
};
