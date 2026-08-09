#pragma once

#include "models/cuttable/rendermodelcuttableresource.h"
#include "models/rendermodel.h"

class Contour;

class alignas(16) idRenderModelCuttableSurface : public idRenderModel {
public:
    using UpdateCallback = bool (*)(idRenderModelCuttableSurface* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);
    using ResourceResolver = idRenderModelCuttableResource* (*)(
        const char* modelName);

    idRenderModelCuttableSurface();
    explicit idRenderModelCuttableSurface(const char* modelName);
    ~idRenderModelCuttableSurface() override = default;
    static void SetUpdateCallback(UpdateCallback callback);
    static void SetResourceResolver(ResourceResolver resolver);
    void Save(idFile* file) override;
    bool Load(idFile* file) override;
    bool LoadModel(const char* modelName);
    int UpdateGeometry(int bufferIndex_,
        const idVertexBuffer& vertexBuffer,
        const idVertexBuffer& stBuffer,
        const idIndexBuffer& indexBuffer,
        int numVertices, int numIndices);
    void BuildGeometry(const Contour* outer, const Contour* inner,
        idList<idDrawVert, 5>& vertices,
        idList<idVec2, 5>& originalST,
        idList<std::uint16_t, 5>& indices) const;
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;

    idRenderModelCuttableResource* modelResource;
    const idTriangleInterpolator* triangleInterpolator;
    int bufferIndex;

private:
    static UpdateCallback updateCallback;
    static ResourceResolver resourceResolver;
};
