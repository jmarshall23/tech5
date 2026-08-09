#pragma once

#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"
#include "models/rendermodel.h"

#include <cstdint>

class idLexer;
class idMaterial;
class idMD6Model;
class idMD6Skel;

struct processVert_t {
    idVec3 xyz;
    idVec3 normal;
    idVec4 tangent;
    std::uint8_t morph[4];
    std::uint8_t weights[4];
    std::uint8_t jointIdxs[4];
};

struct processST_t {
    idList<idVec2, 5> st;
    std::uint8_t slot;

    processST_t() : slot(0) {}
};

struct idProcessMesh {
    idList<processVert_t, 5> vertexes;
    idList<processST_t, 5> uvs;
    idList<int, 5> indexes;
    idList<int, 5> faceMaterialIndex;
    int minJoint;
    int maxJoint;
    int hashST;

    idProcessMesh() : minJoint(0), maxJoint(255), hashST(0) {}
};

struct idProcessSurface {
    idStr name;
    const idMaterial* material;
    bool discrete;
    bool allowSkinRemapping;
    int numTexCoordSets;
    idProcessMesh mesh;
    int sourceOrdinal;

    idProcessSurface()
        : material(nullptr), discrete(false), allowSkinRemapping(true),
          numTexCoordSets(1), sourceOrdinal(-1) {}
};

struct vertexMorphOffset_t {
    idVec3 xyz;
    idVec3 offset;
};

class idMD6BinaryGenerator {
public:
    using SkeletonResolver = idMD6Skel* (*)(const char* name);
    using MaterialResolver = const idMaterial* (*)(const char* name);
    using MaterialNameCallback = const char* (*)(const idMaterial* material);
    using MaterialChecksumCallback = unsigned int (*)(
        const idMaterial* material);
    using MaterialDiscreteCallback = bool (*)(const idMaterial* material);
    using MaterialMergeCallback = bool (*)(const idMaterial* first,
        const idMaterial* second);
    using MorphMapLoader = bool (*)(const char* fileName,
        const idVec3& offset, idList<vertexMorphOffset_t, 5>& offsets);

    idMD6BinaryGenerator();
    ~idMD6BinaryGenerator();

    bool LoadAndProcessText(const char* sourceModel);
    bool WriteBinaryFile(const char* fileName) const;
    bool PopulateModel(idMD6Model& model) const;
    void CreateHashST();
    void LoadMorphMap(const char* fileName, const idVec3& offset,
        idList<vertexMorphOffset_t, 5>& offsets) const;
    void SplitMeshesForJointLimit(int maxJointsPerSurface);
    void SplitMeshesForIndexLimit(int maxIndexesPerSurface);
    void MergeMeshesAndBuildSourceSurfaces(int maxJointsPerSurface);
    void Clear();

    static bool GenerateModel(idMD6Model* model, const char* sourceFileName);
    static void SetCallbacks(SkeletonResolver skeletonResolver,
        MaterialResolver materialResolver, MaterialNameCallback materialName,
        MaterialChecksumCallback materialChecksum,
        MaterialDiscreteCallback materialDiscrete,
        MaterialMergeCallback materialMerge, MorphMapLoader morphLoader);

    idStr sourceFileName;
    unsigned int timestamp;
    unsigned int skelTimestamp;
    idBounds defaultBounds;
    bool remapForSkinning;
    idVec3 minBoundsExpansion;
    idVec3 maxBoundsExpansion;
    idStr morphSkinName;
    idMD6Skel* skeleton;
    idList<unsigned char, 5> jointRemap;
    idList<idProcessSurface*, 5> surfaces;
    idList<sourceSurface_t, 5> sourceSurfaces;

private:
    bool ParseMesh(idLexer& lexer, int version, int numModelJoints,
        bool exportedNormals, const idList<short, 5>& modelToSkeleton);
    void SetupJointRemap();
    static bool MatchMorphVerts(
        const idList<vertexMorphOffset_t, 5>& offsets,
        idList<processVert_t, 5>& vertices);

    static SkeletonResolver skeletonResolverCallback;
    static MaterialResolver materialResolverCallback;
    static MaterialNameCallback materialNameCallback;
    static MaterialChecksumCallback materialChecksumCallback;
    static MaterialDiscreteCallback materialDiscreteCallback;
    static MaterialMergeCallback materialMergeCallback;
    static MorphMapLoader morphMapLoaderCallback;
};

static_assert(sizeof(processVert_t) == 52,
    "Recovered MD6 process vertex ABI changed");
