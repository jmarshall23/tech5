#include "models/water/rendermodelwatersurface.h"

#include <cstring>

idRenderModelWaterSurface::UpdateCallback
    idRenderModelWaterSurface::updateCallback = nullptr;

idRenderModelWaterSurface::idRenderModelWaterSurface()
    : waterSim(nullptr), deferredVerts(nullptr), currentIndex(0),
      waterGenBlockParms(nullptr), material(nullptr) {
    std::memset(vertexBuffer, 0, sizeof(vertexBuffer));
    std::memset(&indexBuffer, 0, sizeof(indexBuffer));
    std::memset(&waterSimParms, 0, sizeof(waterSimParms));
}

idRenderModelWaterSurface::~idRenderModelWaterSurface() {
    delete waterSim;
}

void idRenderModelWaterSurface::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

bool idRenderModelWaterSurface::UpdateInView(
    const idRenderView* currentView, const idRenderView* nextView,
    idRenderModelUpdateTools* tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}

bool idRenderModelWaterSurface::ConfigureSimulation(
    const waterSimParms_t& simulationParms) {
    if (simulationParms.spacing <= 0.0f ||
        simulationParms.timeStep <= 0.0f) {
        return false;
    }
    idWaterSurfaceSim* replacement = new idWaterSurfaceSim(
        simulationParms.waterBounds, simulationParms.spacing,
        simulationParms.damping, simulationParms.speed,
        simulationParms.timeStep);
    delete waterSim;
    waterSim = replacement;
    waterSimParms = simulationParms;
    referenceBounds = simulationParms.waterBounds;
    return true;
}
