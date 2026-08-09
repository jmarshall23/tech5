#pragma once

#include "framework/resource.h"
#include "framework/resourcelist.h"
#include "models/detail/detailmodel.h"

class idMaterial;

class idDetailModelSurface {
public:
    int numVerts;
    int numIndices;
    detailPaletteVert_t* verts;
    std::uint16_t* indices;
};

class idDetailPaletteData {
public:
    idDetailPaletteData();
    ~idDetailPaletteData();

    void FreeData();
    void CreateDefault();
    bool Generate(const char* name);

    const idMaterial* material;
    int numSurfaces;
    idDetailModelSurface* surfaces;
    idBounds bounds;
};

class idDetailModelData : public idResource {
public:
    using GeometryLoader = bool (*)(const char* modelName,
        idDetailPaletteData& output);

    idDetailModelData();
    ~idDetailModelData() override;

    void LoadResource() override;
    idResourceList* GetResourceList() override;
    void FreeData();
    bool Generate();

    static void SetGeometryLoader(GeometryLoader loader);

    idDetailPaletteData* paletteData;
    int paletteIdx;

    static idTypedResourceList<idDetailModelData> resourceList;
    static idList<idDetailPaletteData*, 98> palette;

private:
    friend class idDetailPaletteData;
    static GeometryLoader geometryLoader;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idDetailModelSurface) == 16,
    "Recovered detail model-surface ABI changed");
static_assert(sizeof(idDetailPaletteData) == 36,
    "Recovered detail palette-data ABI changed");
#endif
