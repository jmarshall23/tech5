#pragma once

#include "models/rendermodel.h"

class idDetailEditModel;

class alignas(16) idRenderModelDetailEdit : public idRenderModel {
public:
    using UpdateCallback = bool (*)(idRenderModelDetailEdit* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);

    idRenderModelDetailEdit();
    ~idRenderModelDetailEdit() override = default;
    static void SetUpdateCallback(UpdateCallback callback);
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;

    idList<idDetailEditModel*, 98> detailBSP;
    idVertexBuffer vertexBuffers[2];
    idIndexBuffer indexBuffers[2];

private:
    static UpdateCallback updateCallback;
};
