#pragma once

#include "models/rendermodel.h"
#include "models/zipline/jobs/ziplinegen.h"

class alignas(16) idRenderModelZipline : public idRenderModel {
public:
    using UpdateCallback = bool (*)(idRenderModelZipline* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);

    idRenderModelZipline();
    ~idRenderModelZipline() override;
    static void SetUpdateCallback(UpdateCallback callback);
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;

    const idMaterial* material;
    int splineMaxSubdivisions;
    int splineTessellationDistance;
    float cableDiameter;
    int cableSubdivisions;
    float time;
    float fractionBeforeLerp;
    bool downDirection;
    int dirty;
    sweptPoint_t* sweptPoints;
    idNonUniformBSpline<idVec3>* sourceSpline[2];
    int currentSourceSpline;
    zipLineGenParms_t* parms;
    int currentBuffer;
    idVertexBuffer vertexBuffer[3];
    idIndexBuffer indexBuffer[3];
    int numVertices;
    int numIndices;

private:
    static UpdateCallback updateCallback;
};
