#pragma once

#include "models/rendermodel.h"

#include <cstdint>

struct skinRemap_t {
    const idMaterial* mtr;
    idVec2 texOffset;
};

class idStaticModelSurface : public idRenderModelSurface {
public:
    idStaticModelSurface() {
        material = nullptr;
        materialNum = 0;
        extraGLState = 0;
        geometry = nullptr;
        geometryIsReference = false;
        referenceMask = 0;
        binaryModelId = 0;
        joints = nullptr;
        morphMap = nullptr;
        stMap = nullptr;
        skinOffsets.Set(0.0f, 0.0f, 0.0f, 0.0f);
    }

    idList<skinRemap_t, 5> skinRemaps;
};

struct matchVert_t {
    int next;
    int v;
    int tv;
    int morph;
    unsigned int color;
    idVec3 normal;
};

struct vertexTangents_t {
    idVec3 normal;
    idVec3 tangents[2];
};

struct idSplitResults {
    idList<int, 5> indexes;
    idList<int, 5> vertices;
};

class idRawSurface {
public:
    idRawSurface();

    void InitHash(const idList<idVec3, 5>& positions,
        const idList<idVec2, 5>& texCoords,
        const idList<idVec3, 5>& morphPositions);
    void GenerateNormals();
    void InitIndex(int maxIndexes);
    void DuplicateMirroredVertexes();
    void AddVert(int position, int texCoord, const idVec3& normal,
        unsigned int color, int morph = 0);
    void MakeSurfaces(idList<idStaticModelSurface, 5>& surfaces);

    const idMaterial* material;
    int materialNum;
    bool generateNormals;
    float normalEpsilon;
    const idList<idVec3, 5>* pvList;
    const idList<idVec2, 5>* ptvList;
    const idList<idVec3, 5>* pMorphList;
    idList<int, 5> vertHash;
    idList<matchVert_t, 5> verts;
    idList<int, 5> indexes;
};

bool BuildAveragedSurfaceNormals(const idList<idVec3, 5>& vertices,
    const idList<int, 5>& indexes,
    idList<idVec3, 5>& averagedSurfaceNormals);
void DeriveVertexTangents(const idList<int, 5>& indexes,
    const idList<idDrawVert, 5>& vertices,
    idList<vertexTangents_t, 5>& tangents);
void SplitTrianglesForVertexLimit(const idList<int, 5>& indexes,
    int maxVertices, idList<idSplitResults, 5>& split);

class idStaticModel;
void EmitRawSurfacesToStaticModel(idList<idRawSurface, 5>& rawSurfaces,
    idStaticModel& model);

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(skinRemap_t) == 12,
    "Recovered skin-remap ABI changed");
#endif

static_assert(sizeof(vertexTangents_t) == 36,
    "Recovered tangent accumulator ABI changed");
