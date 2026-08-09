#include "models/foliage/rendermodelfoliage.h"

#include <new>

idRenderModelFoliage::UpdateCallback idRenderModelFoliage::updateCallback =
    nullptr;

idRenderModelFoliage::idRenderModelFoliage()
    : foliageBSP(nullptr), foliageGatherParms(nullptr),
      foliageGenParms(nullptr), viewData(nullptr), foliageIndices(nullptr),
      influenceSphereIndices(nullptr), subTreeFoliageCounts(nullptr) {
    g.addAlways = 1;
    g.noInteractions = 1;
    g.noShadow = 1;
    foliageGatherParms = new (std::nothrow)
        deferredFoliageGatherParms_t[128]();
    foliageGenParms = new (std::nothrow)
        deferredFoliageGenParms_t[2048]();
    viewData = new (std::nothrow) foliageRenderView_t();
    foliageIndices = new (std::nothrow) foliageIndex_t[33664]();
    influenceSphereIndices = new (std::nothrow) std::int16_t[33664]();
    subTreeFoliageCounts = new (std::nothrow)
        foliageSubTreeStats_t[128]();
}

idRenderModelFoliage::~idRenderModelFoliage() {
    delete[] foliageGatherParms;
    delete[] foliageGenParms;
    delete viewData;
    delete[] foliageIndices;
    delete[] influenceSphereIndices;
    delete[] subTreeFoliageCounts;
}

void idRenderModelFoliage::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

bool idRenderModelFoliage::UpdateInView(const idRenderView* currentView,
    const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}
