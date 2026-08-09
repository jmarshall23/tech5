#pragma once

#include "models/rendermodel.h"

class alignas(16) idRenderModelManyBoxes : public idRenderModel {
public:
    struct box_t {
        idVec3 position;
        idMat3 orientation;
        float radius;
    };

    using UpdateCallback = bool (*)(idRenderModelManyBoxes* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);

    idRenderModelManyBoxes();
    ~idRenderModelManyBoxes() override;
    static void SetUpdateCallback(UpdateCallback callback);
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;
    bool CommitSubclass() override;

    int gameTime;
    const idMaterial* material;
    idList<box_t, 5> boxes;
    idVertexBuffer vertexBuffers[2];
    idTriangles triangles;
    idIndexBuffer indexBuffer;

private:
    static UpdateCallback updateCallback;
};

void CreateDrawVertNormal(std::uint8_t (&drawVertNormal)[4],
    const idVec3& normal);

static_assert(sizeof(idRenderModelManyBoxes::box_t) == 52,
    "Recovered many-box model item ABI changed");
