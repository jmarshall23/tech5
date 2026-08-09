#pragma once

#include "models/rendermodel.h"

class alignas(16) idRenderModelImposter : public idRenderModel {
public:
    idRenderModelImposter();
    ~idRenderModelImposter() override = default;

    bool UpdateInView(const idRenderView* view,
        const idRenderView* previousView,
        idRenderModelUpdateTools* tools) override;
    void MimicRenderModel(idRenderModel* parentModel);

    idRenderModel* parent;
};
