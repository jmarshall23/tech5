#include "models/detail/detailmodeldata.h"

#include <algorithm>
#include <cstring>
#include <new>

idTypedResourceList<idDetailModelData>
    idDetailModelData::resourceList("detailModelData");
idList<idDetailPaletteData*, 98> idDetailModelData::palette;
idDetailModelData::GeometryLoader idDetailModelData::geometryLoader = nullptr;

idDetailPaletteData::idDetailPaletteData()
    : material(nullptr), numSurfaces(0), surfaces(nullptr) {
    bounds[0].Zero();
    bounds[1].Zero();
}

idDetailPaletteData::~idDetailPaletteData() {
    FreeData();
}

void idDetailPaletteData::FreeData() {
    for (int index = 0; index < numSurfaces; ++index) {
        delete[] surfaces[index].verts;
        delete[] surfaces[index].indices;
    }
    delete[] surfaces;
    material = nullptr;
    numSurfaces = 0;
    surfaces = nullptr;
    bounds[0].Zero();
    bounds[1].Zero();
}

void idDetailPaletteData::CreateDefault() {
    FreeData();
    surfaces = new (std::nothrow) idDetailModelSurface[1]();
    if (surfaces == nullptr) return;
    numSurfaces = 1;
    idDetailModelSurface& surface = surfaces[0];
    surface.numVerts = 8;
    surface.numIndices = 36;
    surface.verts = new (std::nothrow) detailPaletteVert_t[8]();
    surface.indices = new (std::nothrow) std::uint16_t[36];
    if (surface.verts == nullptr || surface.indices == nullptr) {
        FreeData();
        return;
    }

    const std::int16_t positions[8][3] = {
        {-1, -1, -1}, { 1, -1, -1}, { 1,  1, -1}, {-1,  1, -1},
        {-1, -1,  1}, { 1, -1,  1}, { 1,  1,  1}, {-1,  1,  1}
    };
    for (int index = 0; index < 8; ++index) {
        std::memcpy(surface.verts[index].xyz, positions[index],
            sizeof(positions[index]));
        surface.verts[index].st[0] = 0;
        surface.verts[index].st[1] = 0;
    }
    const std::uint16_t cubeIndices[36] = {
        2,3,1, 3,0,1, 5,1,4, 1,0,4,
        7,4,3, 4,0,3, 1,5,6, 2,1,6,
        3,2,6, 7,3,6, 4,7,6, 5,4,6
    };
    std::memcpy(surface.indices, cubeIndices, sizeof(cubeIndices));
    bounds[0].Set(-1.0f, -1.0f, -1.0f);
    bounds[1].Set(1.0f, 1.0f, 1.0f);
}

bool idDetailPaletteData::Generate(const char* const name) {
    FreeData();
    return idDetailModelData::geometryLoader != nullptr
        && idDetailModelData::geometryLoader(name, *this)
        && numSurfaces > 0 && surfaces != nullptr;
}

idDetailModelData::idDetailModelData()
    : paletteData(nullptr), paletteIdx(-1) {
}

idDetailModelData::~idDetailModelData() {
    FreeData();
}

void idDetailModelData::SetGeometryLoader(GeometryLoader loader) {
    geometryLoader = loader;
}

idResourceList* idDetailModelData::GetResourceList() {
    return &resourceList;
}

void idDetailModelData::FreeData() {
    if (paletteIdx >= 0 && paletteIdx < palette.Num()
        && palette[paletteIdx] == paletteData) {
        palette[paletteIdx] = nullptr;
    }
    delete paletteData;
    paletteData = nullptr;
    paletteIdx = -1;
}

bool idDetailModelData::Generate() {
    FreeData();
    paletteData = new (std::nothrow) idDetailPaletteData();
    if (paletteData == nullptr) return false;
    if (!paletteData->Generate(GetName())) {
        SetResourceError("defaulted '%s'", GetName());
        paletteData->CreateDefault();
    }
    if (paletteData->numSurfaces != 1 || paletteData->surfaces == nullptr) {
        FreeData();
        return false;
    }

    const idDetailModelSurface& surface = paletteData->surfaces[0];
    int totalVertices = 0;
    int totalIndices = 0;
    int freeSlot = -1;
    for (int index = 0; index < palette.Num(); ++index) {
        if (palette[index] == nullptr) {
            if (freeSlot < 0) freeSlot = index;
            continue;
        }
        const idDetailModelSurface& registered =
            palette[index]->surfaces[0];
        totalVertices += registered.numVerts;
        totalIndices += registered.numIndices;
    }
    if (surface.numVerts < 0 || surface.numVerts > 50
        || surface.numIndices < 0 || surface.numIndices > 300
        || surface.verts == nullptr || surface.indices == nullptr
        || 2 * (5 * (totalVertices + surface.numVerts)
            + totalIndices + surface.numIndices) > 0x8000) {
        FreeData();
        return false;
    }
    if (freeSlot >= 0) {
        palette[freeSlot] = paletteData;
        paletteIdx = freeSlot;
    } else {
        paletteIdx = palette.Append(paletteData);
    }
    if (paletteIdx < 0) {
        FreeData();
        return false;
    }
    return true;
}

void idDetailModelData::LoadResource() {
    if (!Generate()) {
        SetResourceError("Couldn't load detailmodeldata '%s'", GetName());
    }
}
