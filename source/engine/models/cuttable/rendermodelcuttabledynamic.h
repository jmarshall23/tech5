#pragma once

#include "models/rendermodel.h"

class idRenderModelCuttableDynamic : public idRenderModel {
public:
    enum { MAX_VERTICES = 0x80, MAX_INDICES = 0x180 };

    using BufferUploadCallback = void (*)(idTriangles* geometry,
        const idDrawVert* vertices, int numVertices,
        const std::uint16_t* indices, int numIndices,
        idVertexBuffer* stMap, const idVec2* textureCoordinates,
        int numTextureCoordinates);

    idRenderModelCuttableDynamic();
    ~idRenderModelCuttableDynamic() override;

    static void SetBufferUploadCallback(BufferUploadCallback callback);
    bool IsValid() const;
    void Upload(const idMaterial* renderMaterial,
        const idMaterial* depthMaterial,
        const idList<idDrawVert, 5>& vertices,
        const idList<idVec2, 5>& st,
        const idList<std::uint16_t, 5>& indices);

private:
    void UploadRenderGeometry(const idMaterial* material,
        const idList<idDrawVert, 5>& vertices,
        const idList<std::uint16_t, 5>& indices);
    static BufferUploadCallback bufferUploadCallback;
};
