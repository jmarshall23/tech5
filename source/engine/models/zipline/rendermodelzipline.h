#pragma once

#include "idlib/math/curve.h"
#include "models/rendermodel.h"
#include "models/zipline/jobs/ziplinegen.h"

class alignas(16) idRenderModelZipline : public idRenderModel {
public:
    using UpdateCallback = bool (*)(idRenderModelZipline* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);
    using MaterialNameCallback = const char* (*)(const idMaterial* material);
    using MaterialResolver = const idMaterial* (*)(const char* name,
        bool makeDefault);

    idRenderModelZipline();
    ~idRenderModelZipline() override;

    static void SetUpdateCallback(UpdateCallback callback);
    static void SetMaterialPersistenceCallbacks(MaterialNameCallback name,
        MaterialResolver resolver);

    void Save(idFile* file) override;
    bool Load(idFile* file) override;
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;
    void BuildModel(const idMaterial* newMaterial,
        int tessellationDistance, int maximumSubdivisions,
        float diameter, int radialSubdivisions);
    void SetSpline(const idCurve_Spline<idVec3>* spline, float sampleTime,
        float lerpFraction, bool travelsDown);

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
    void FreeGeometry();

    static UpdateCallback updateCallback;
    static MaterialNameCallback materialNameCallback;
    static MaterialResolver materialResolver;
};
