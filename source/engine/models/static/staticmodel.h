#pragma once

#include "framework/resource.h"
#include "framework/resourcelist.h"
#include "idlib/filesystem/file.h"
#include "models/rendermodel.h"
#include "models/static/staticmodelrawsurface.h"

class idStaticModel : public idResource {
public:
    struct materialGenerationTraits_t {
        int autospriteType = 0;
        bool disableTriangleStrips = false;
        bool transparencySort = false;
        bool discrete = false;
    };

    enum modelLoadFlags_t : int {
        MODELLOADFLAGS_RESIDE_ON_CPU = 0x1,
        MODELLOADFLAGS_RESIDE_ON_GPU = 0x2,
        MODELLOADFLAGS_DEFAULT = MODELLOADFLAGS_RESIDE_ON_GPU
    };

    using MaterialResolver = const idMaterial* (*)(const char* name);
    using MaterialNameCallback = const char* (*)(const idMaterial* material);
    using MaterialChecksumCallback = int (*)(const idMaterial* material);
    using GenerateCallback = bool (*)(idStaticModel* model,
        const char* sourceFile, const char* binaryFile);
    using BufferUpdateCallback = void (*)(idTriangles* geometry);
    using BufferReleaseCallback = void (*)(idTriangles* geometry);
    using SourceSurfaceRemapCallback = void (*)(idStaticModel* model);
    using MaterialTraitsCallback = bool (*)(const idMaterial* material,
        materialGenerationTraits_t& traits);

    idStaticModel();
    ~idStaticModel() override;

    void LoadResource() override;
    bool ReloadIfStale() override;
    void WriteResourceFile() override;
    idResourceList* GetResourceList() override;
    void Print() override;
    void List() override;

    void PristineLoadResource();
    void UpdateBuffers();
    void FreeCPUData();
    int CPUMemory() const;
    int GPUMemory() const;
    void RemapSourceSurfaces();
    void FreeSurfaces();
    void AddSurface(const idStaticModelSurface& surface);
    void MakeDefaultModel(float low = -8.0f, float high = 8.0f);
    void MakeExtrudeBox();
    void MakeSimpleCube(float low = -8.0f, float high = 8.0f);
    void FinishStaticModel(bool cleanup = true);
    bool ReadStaticBModel(const char* fileName);
    bool WriteBinaryModel(const char* fileName) const;
    bool GenerateStaticModel(const char* sourceFile);
    bool GenerateBinaryModelFile(const char* sourceFile,
        const char* binaryFile);
    bool ConvertASEToModelSurfaces(const class idASEModel* ase);
    bool ConvertLWOToModelSurfaces(const struct lwObject* lwo,
        const struct lwLayer* layer, float vertexSlop = 0.01f,
        float texCoordSlop = 0.0001f);
    bool ConvertOBJToModelSurfaces(const class idOBJModel* obj);
    bool ConvertToOBJ(const char* groupName, class idOBJModel* obj) const;
    void BuildAutospriteData();
    void BuildMergeList(const idList<idStr, 5>& materialNames,
        idList<const idMaterial*, 5>& resolvedMaterials,
        idList<int, 5>& mergeTo,
        idList<const idMaterial*, 5>& uniqueMaterials,
        idList<int, 5>& uniqueMaterialNumbers);
    void MergeSurfacesAndBuildSourceSurfaces();
    void ConvertToTriStrips();
    bool WriteStaticBModel(const char* fileName,
        fsPath_t basePath = FSPATH_BASE) const;
    static bool WriteStaticBModel(const char* fileName,
        unsigned int timestamp,
        const idList<idStaticModelSurface, 84>& surfaces,
        const idList<sourceSurface_t, 5>& sourceSurfaces,
        fsPath_t basePath = FSPATH_BASE);
    void WriteStaticModel() const;
    static bool WriteStaticModel(const char* fileName,
        unsigned int timestamp,
        const idList<idStaticModelSurface, 84>& surfaces,
        fsPath_t basePath = FSPATH_BASE);

    static void SetCallbacks(MaterialResolver materialResolver,
        MaterialNameCallback materialName,
        MaterialChecksumCallback materialChecksum,
        GenerateCallback generator, BufferUpdateCallback updateBuffers,
        BufferReleaseCallback releaseBuffers,
        SourceSurfaceRemapCallback remapSurfaces);
    static void SetMaterialTraitsCallback(MaterialTraitsCallback callback);
    static const idMaterial* ResolveMaterial(const char* name);
    static const char* MaterialName(const idMaterial* material);
    static int MaterialChecksum(const idMaterial* material);
    static bool GetMaterialTraits(const idMaterial* material,
        materialGenerationTraits_t& traits);

    static idTypedResourceList<idStaticModel> resourceList;

    bool pristine;
    bool isReloadable;
    char binaryFileName[256];
    unsigned int binaryTimeStamp;
    unsigned int sourceTimeStamp;
    int reloadCount;
    bool modelIsAutosprite;
    bool usesTransparencySort;
    idBounds referenceBounds;
    idVec3 referencePosition;
    bool sharedSurfaces;
    int modelLoadFlags;
    idList<idStaticModelSurface, 84> surfaces;
    idList<sourceSurface_t, 5> sourceSurfaces;
    idList<const idMaterial*, 5> materials;

private:
    static MaterialResolver materialResolverCallback;
    static MaterialNameCallback materialNameCallback;
    static MaterialChecksumCallback materialChecksumCallback;
    static GenerateCallback generateCallback;
    static BufferUpdateCallback bufferUpdateCallback;
    static BufferReleaseCallback bufferReleaseCallback;
    static SourceSurfaceRemapCallback sourceSurfaceRemapCallback;
    static MaterialTraitsCallback materialTraitsCallback;
};

idStaticModel* PristineModelFromOptimizedModel(
    const idStaticModel& optimizedModel);
