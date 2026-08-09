#pragma once

#include "models/detail/detailmodel.h"
#include "models/detail/jobs/detailgen.h"
#include "models/rendermodel.h"

class alignas(16) idRenderModelDetail : public idRenderModel {
public:
    using UpdateCallback = bool (*)(idRenderModelDetail* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);

    idRenderModelDetail();
    ~idRenderModelDetail() override;
    static void SetUpdateCallback(UpdateCallback callback);
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;

    idDetailModel* detailBSP;
    deferredDetailGatherParms_t* detailGatherParms;
    deferredDetailGenParms_t* detailGenParms;
    detailRenderView_t* viewData;
    int currentIndex;
    std::uint16_t* detailIndices;
    detailSubTreeStats_t* subTreeDetailCounts;
    detailGenTotals_t* totalsUsed;
    idVertexBuffer vertexBuffers[3];
    idIndexBuffer indexBuffers[3];
    idDrawVert* deferredVerts;
    std::uint16_t* deferredIndices;
    const idMaterial* detailMaterial;

private:
    static UpdateCallback updateCallback;
};

struct renderModelDetails_t {
    const char* modelName;
    int count;
};
