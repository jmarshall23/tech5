#pragma once

#include "models/rendermodel.h"
#include "models/water/jobs/watergen.h"
#include "models/water/watersurfacesim.h"

class alignas(16) idRenderModelWaterSurface : public idRenderModel {
public:
    struct waterSimParms_t {
        float spacing;
        float damping;
        float speed;
        float timeStep;
        idBounds waterBounds;
    };

    using UpdateCallback = bool (*)(idRenderModelWaterSurface* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);

    idRenderModelWaterSurface();
    ~idRenderModelWaterSurface() override;
    static void SetUpdateCallback(UpdateCallback callback);
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;
    bool ConfigureSimulation(const waterSimParms_t& simulationParms);

    idWaterSurfaceSim* waterSim;
    idVertexBuffer vertexBuffer[3];
    idIndexBuffer indexBuffer;
    idDrawVert* deferredVerts;
    int currentIndex;
    deferredWaterBlockGenParms_t* waterGenBlockParms;
    waterSimParms_t waterSimParms;
    const idMaterial* material;

private:
    static UpdateCallback updateCallback;
};

static_assert(sizeof(idRenderModelWaterSurface::waterSimParms_t) == 40,
    "Recovered water-simulation parameters ABI changed");
