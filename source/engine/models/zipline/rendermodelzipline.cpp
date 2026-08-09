#include "models/zipline/rendermodelzipline.h"

#include <cstring>

idRenderModelZipline::UpdateCallback idRenderModelZipline::updateCallback =
    nullptr;

idRenderModelZipline::idRenderModelZipline()
    : material(nullptr), splineMaxSubdivisions(64),
      splineTessellationDistance(16), cableDiameter(1.0f),
      cableSubdivisions(6), time(0.0f), fractionBeforeLerp(0.5f),
      downDirection(false), dirty(1), sweptPoints(nullptr),
      currentSourceSpline(0), parms(new zipLineGenParms_t()),
      currentBuffer(0), numVertices(0), numIndices(0) {
    sourceSpline[0] = new idNonUniformBSpline<idVec3>();
    sourceSpline[1] = new idNonUniformBSpline<idVec3>();
    std::memset(parms, 0, sizeof(*parms));
    std::memset(vertexBuffer, 0, sizeof(vertexBuffer));
    std::memset(indexBuffer, 0, sizeof(indexBuffer));
}

idRenderModelZipline::~idRenderModelZipline() {
    delete parms;
    delete sourceSpline[1];
    delete sourceSpline[0];
}

void idRenderModelZipline::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

bool idRenderModelZipline::UpdateInView(const idRenderView* currentView,
    const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}
