#pragma once

#include "models/foliage/foliagemodel.h"
#include "models/foliage/jobs/foliagegather.h"
#include "models/foliage/jobs/foliagegen.h"
#include "models/rendermodel.h"

class alignas(16) idRenderModelFoliage : public idRenderModel {
public:
    using UpdateCallback = bool (*)(idRenderModelFoliage* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);

    idRenderModelFoliage();
    ~idRenderModelFoliage() override;
    static void SetUpdateCallback(UpdateCallback callback);
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;

    idFoliageModel* foliageBSP;
    deferredFoliageGatherParms_t* foliageGatherParms;
    deferredFoliageGenParms_t* foliageGenParms;
    foliageRenderView_t* viewData;
    foliageIndex_t* foliageIndices;
    std::int16_t* influenceSphereIndices;
    foliageSubTreeStats_t* subTreeFoliageCounts;

private:
    static UpdateCallback updateCallback;
};
