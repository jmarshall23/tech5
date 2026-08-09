#pragma once

#include "models/rendermodel.h"
#include "models/static/staticmodelrawsurface.h"

#include <cstdint>

class idMD6Mesh {
public:
    struct vert_t {
        idVec3 xyz;
        idVec2 st;
        idVec3 normal;
        idVec4 tangent;
        std::uint8_t weights[4];
        std::uint8_t jointIdxs[4];
    };

    struct stset_t {
        std::uint8_t slot;
        idList<idVec2, 5> st;
        idVertexBuffer* vb;
    };

    using MaterialResolver = const idMaterial* (*)(const char* name);
    using MaterialNameCallback = const char* (*)(const idMaterial* material);
    using BufferUploadCallback = void (*)(idMD6Mesh* mesh);
    using BufferReleaseCallback = void (*)(idMD6Mesh* mesh);

    idMD6Mesh();
    ~idMD6Mesh();
    static void SetMaterialCallbacks(MaterialResolver resolver,
        MaterialNameCallback nameCallback);
    static const char* MaterialName(const idMaterial* material);
    static void SetBufferCallbacks(BufferUploadCallback upload,
        BufferReleaseCallback release);
    unsigned int Memory() const;
    void WriteMesh_Binary(idFile* file) const;
    bool LoadMesh_Binary(idFile* file, unsigned int magic);
    void CreateHashST();
    void FreeLoadData();
    void Free();

    idStr name;
    const idMaterial* material;
    bool discrete;
    bool allowSkinRemapping;
    int numTexCoordSets;
    idBounds bounds;
    int numVerts;
    int numTris;
    int jointOffset;
    int numJoints;
    int hashST;
    idList<unsigned char, 5> morphMap;
    idTriangles* tris;
    idList<skinRemap_t, 5> skinRemaps;
    idList<vert_t, 19> vertexes;
    idList<stset_t, 19> stSets;
    idList<unsigned short, 19> indexes;

private:
    static MaterialResolver materialResolver;
    static MaterialNameCallback materialNameCallback;
    static BufferUploadCallback bufferUploadCallback;
    static BufferReleaseCallback bufferReleaseCallback;
};

std::uint8_t CompressWeightsToByte(const std::uint8_t weights[4]);

static_assert(sizeof(idMD6Mesh::vert_t) == 56,
    "Recovered MD6 mesh vertex ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idMD6Mesh::stset_t) == 24,
    "Recovered MD6 texture-coordinate set ABI changed");
#endif
