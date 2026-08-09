#pragma once

#include "models/rendermodel.h"

class idFoliageEditModel;

class alignas(16) idRenderModelFoliageEdit : public idRenderModel {
public:
    using UpdateCallback = bool (*)(idRenderModelFoliageEdit* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);

    idRenderModelFoliageEdit();
    ~idRenderModelFoliageEdit() override = default;
    static void SetUpdateCallback(UpdateCallback callback);
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;

    idList<idFoliageEditModel*, 53> foliageBSP;
    int numFoliageQuadsInView;
    int maxFoliageQuadsAllowed;

private:
    static UpdateCallback updateCallback;
};
