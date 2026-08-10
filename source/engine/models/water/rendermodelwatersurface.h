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
    using MaterialNameCallback = const char* (*)(const idMaterial* material);
    using MaterialResolver = const idMaterial* (*)(const char* name,
        bool makeDefault);
    using GradientCallback = bool (*)(const char* imageName, float s, float t,
        idVec4& color);
    using BinaryOpenCallback = idFile* (*)(const char* modelName,
        bool writing);
    using BinaryCloseCallback = void (*)(idFile* file);

    idRenderModelWaterSurface();
    explicit idRenderModelWaterSurface(const char* modelName);
    ~idRenderModelWaterSurface() override;

    static void SetUpdateCallback(UpdateCallback callback);
    static void SetMaterialPersistenceCallbacks(MaterialNameCallback name,
        MaterialResolver resolver);
    static void SetGradientCallback(GradientCallback callback);
    static void SetBinaryFileCallbacks(BinaryOpenCallback open,
        BinaryCloseCallback close);

    void Save(idFile* file) override;
    bool Load(idFile* file) override;
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;
    bool ConfigureSimulation(const waterSimParms_t& simulationParms);
    void BuildWaterModel(const idMaterial* newMaterial,
        const idBounds& waterBounds, float spacing, float damping,
        float speed, float timeStep, const char* gradientImageName = nullptr);
    bool CheckValid(const idWaterSurfaceSim* simulation,
        const idBounds& waterBounds) const;
    bool WriteBinary(const char* modelName) const;
    bool WriteBinary(idFile* file) const;
    bool LoadBinary(const char* modelName);
    bool LoadBinary(idFile* file);
    bool LoadModel(const char* modelName);
    void FreeData();

    idWaterSurfaceSim* waterSim;
    idVertexBuffer vertexBuffer[3];
    idIndexBuffer indexBuffer;
    idDrawVert* deferredVerts;
    int currentIndex;
    deferredWaterBlockGenParms_t* waterGenBlockParms;
    waterSimParms_t waterSimParms;
    const idMaterial* material;

private:
    void CreateGeometry(const idMaterial* newMaterial,
        const char* gradientImageName, const idVec3& origin,
        int width, int height, float spacing, int numBlocksX,
        int numBlocksY);
    bool UpdateSimulation();

    static UpdateCallback updateCallback;
    static MaterialNameCallback materialNameCallback;
    static MaterialResolver materialResolver;
    static GradientCallback gradientCallback;
    static BinaryOpenCallback binaryOpenCallback;
    static BinaryCloseCallback binaryCloseCallback;
};

static_assert(sizeof(idRenderModelWaterSurface::waterSimParms_t) == 40,
    "Recovered water-simulation parameters ABI changed");
