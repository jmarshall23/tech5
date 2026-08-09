#pragma once

#include "framework/resource.h"
#include "framework/resourcelist.h"
#include "idlib/containers/list.h"
#include "idlib/geometry/drawvert.h"

#include <cstdint>

class idStaticParticleModelData : public idResource {
public:
    using GeometryLoader = bool (*)(const char* modelName,
        idList<idDrawVert, 79>& vertices,
        idList<std::uint16_t, 79>& indexes,
        unsigned int& sourceTimestamp);

    idStaticParticleModelData();
    ~idStaticParticleModelData() override;

    void LoadResource() override;
    bool ReloadIfStale() override;
    idResourceList* GetResourceList() override;

    void FreeData();
    bool LoadBinary(const char* fileName);
    bool WriteBinary(const char* fileName) const;
    bool Generate();
    bool GenerateFromGeometry(const idDrawVert* vertices, int numVertices,
        const std::uint16_t* indexes, int numIndexes,
        unsigned int sourceTimestamp);

    static void SetGeometryLoader(GeometryLoader loader);

    unsigned int timestamp;
    idDrawVert* staticVerts;
    int numStaticVerts;

    static idTypedResourceList<idStaticParticleModelData> resourceList;

private:
    static GeometryLoader geometryLoader;
};
