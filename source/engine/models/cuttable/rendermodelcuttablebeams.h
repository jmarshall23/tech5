#pragma once

#include "models/cuttable/cuttergraph.h"
#include "models/rendermodel.h"

class idRenderModelCuttableBeams : public idRenderModel {
public:
    enum {
        MAX_BEAM_QUADS = 0x1000,
        MAX_BEAM_VERTICES = 0x4000,
        MAX_BEAM_INDICES = 0x6000,
        NUM_VERTEX_BUFFERS = 3,
        SURFACE_INCISIONS = 0,
        SURFACE_INCISIONCROSSINGS,
        SURFACE_INCISIONENDPOINTS,
        SURFACE_MAX
    };

    using UpdateCallback = bool (*)(idRenderModelCuttableBeams* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);
    using MaterialResolver = const idMaterial* (*)(const char* name);
    using MaterialNameCallback = const char* (*)(const idMaterial* material);
    using GeometryUploadCallback = void (*)(
        idRenderModelCuttableBeams* model, int surfaceIndex,
        idTriangles* geometry);

    idRenderModelCuttableBeams();
    ~idRenderModelCuttableBeams() override;
    static void Init();
    static void Shutdown();
    static void StartFrame();
    static void EndFrame();
    static void SetUpdateCallback(UpdateCallback callback);
    static void SetMaterialCallbacks(MaterialResolver resolver,
        MaterialNameCallback nameCallback);
    static void SetGeometryUploadCallback(GeometryUploadCallback callback);
    static void SetBeamParameters(float width, float repeat,
        float crossingSize, float endpointSize);
    void Create(const idMaterial* materialIncision_,
        const idMaterial* materialIncisionCross_);
    void Update(idCutterGraphManager* graphManager_, int graphHandle_);
    void SetBounds(const idBounds& bounds);
    void Save(idFile* file) override;
    bool Load(idFile* file) override;
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;

    const idMaterial* materialIncision;
    const idMaterial* materialIncisionCross;
    idCutterGraphManager* graphManager;
    int graphHandle;

private:
    void BuildIncisions(const graphTree_t& graphTree);
    void BuildIncisionCrossings(const graphTree_t& graphTree);
    void BuildIncisionEndpoints(const graphTree_t& graphTree);
    void UploadSurface(int surfaceIndex, const idMaterial* material,
        const idList<idDrawVert, 5>& vertices,
        const idList<std::uint16_t, 5>& indices);
    static UpdateCallback updateCallback;
    static MaterialResolver materialResolver;
    static MaterialNameCallback materialNameCallback;
    static GeometryUploadCallback geometryUploadCallback;
    static float beamWidth;
    static float beamRepeat;
    static float crossingSize;
    static float endpointSize;
    static int currentBuffer;
};
