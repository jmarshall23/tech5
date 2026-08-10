#include "models/detail/rendermodeldetail.h"

#include <cstring>
#include <new>

idRenderModelDetail::MaterialResolver idRenderModelDetail::materialResolver =
    nullptr;
idRenderModelDetail::UpdateCallback idRenderModelDetail::updateCallback =
    nullptr;

idRenderModelDetail::idRenderModelDetail()
    : detailBSP(nullptr), detailGatherParms(nullptr), detailGenParms(nullptr),
      viewData(nullptr), currentIndex(0), detailIndices(nullptr),
      subTreeDetailCounts(nullptr), totalsUsed(nullptr), deferredVerts(nullptr),
      deferredIndices(nullptr), detailMaterial(materialResolver != nullptr
          ? materialResolver("genericDetailVmtr", true) : nullptr) {
    std::memset(vertexBuffers, 0, sizeof(vertexBuffers));
    std::memset(indexBuffers, 0, sizeof(indexBuffers));
    g.addAlways = 1;
    g.noInteractions = 1;
    g.noShadow = 1;

    idTriangles* const geometry = new (std::nothrow) idTriangles();
    if (geometry != nullptr) {
        geometry->bounds[0].Set(-99999.0f, -99999.0f, -99999.0f);
        geometry->bounds[1].Set(99999.0f, 99999.0f, 99999.0f);
        geometry->numVerts = 0;
        geometry->numIndexes = 0;
        geometry->vertexBuffer = vertexBuffers[2];
        geometry->indexBuffer = indexBuffers[2];
        idRenderModelSurface surface{};
        surface.material = detailMaterial;
        surface.geometry = geometry;
        surface.geometryIsReference = false;
        AddSurface(surface);
    }

    detailGatherParms = new (std::nothrow)
        deferredDetailGatherParms_t[128]();
    detailGenParms = new (std::nothrow)
        deferredDetailGenParms_t[4096]();
    viewData = new (std::nothrow) detailRenderView_t();
    detailIndices = new (std::nothrow) std::uint16_t[17280]();
    subTreeDetailCounts = new (std::nothrow) detailSubTreeStats_t[128]();
    totalsUsed = new (std::nothrow) detailGenTotals_t();
}

idRenderModelDetail::~idRenderModelDetail() {
    delete[] detailGatherParms;
    delete[] detailGenParms;
    delete viewData;
    delete[] detailIndices;
    delete[] subTreeDetailCounts;
    delete totalsUsed;
    for (int index = 0; index < surfaces.Num(); ++index) {
        if (!surfaces[index].geometryIsReference) {
            delete surfaces[index].geometry;
            surfaces[index].geometry = nullptr;
        }
    }
}

void idRenderModelDetail::SetMaterialResolver(MaterialResolver resolver) {
    materialResolver = resolver;
}

void idRenderModelDetail::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

bool idRenderModelDetail::UpdateInView(const idRenderView* currentView,
    const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}
