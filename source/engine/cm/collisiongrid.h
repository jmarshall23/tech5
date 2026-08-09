#pragma once

#include "cm/collisiontypes.h"
#include "framework/resource.h"
#include "framework/resourcelist.h"
#include "idlib/containers/bitarray.h"
#include "idlib/containers/list.h"
#include "idlib/math/vectori.h"
#include "idlib/sys/sys_alloc.h"
#include "idlib/text/str.h"

#include <cstdint>

class idFile;
class idMaterial;

class idCollisionGridState {
public:
    idCollisionGridState();
    ~idCollisionGridState() = default;

    void Create(int num, const idMaterial* material);
    void Activate(unsigned int id);
    void Inactivate(unsigned int id);
    int FirstActive() const;
    int NextActive(int id) const;

    const idMaterial* material;
    int numActive;
    int firstActive;
    idBitArray active;
};

struct cm_gridPart_t {
    idBoundsShort bounds;
    std::uint16_t nodeIndex;
    std::uint16_t firstPolygonIndex;
    std::uint16_t numPolygons;
};

struct alignas(4) cm_gridNodeBSP_t {
    idBounds bounds;
    float planeDist;
    std::uint16_t children[2];
    char planeType;
};

class idGenGridModel {
public:
    static constexpr std::uint16_t INVALID_INDEX = 0xFFFFu;

    bool LoadBinary(idFile* file);

    idList<std::uint16_t, TAG_IDLIST> indices;
    idList<idVec3, TAG_IDLIST> vertices;
    idList<cm_edge_t, TAG_IDLIST> edges;
    idList<std::uint16_t, TAG_IDLIST> polygonEdges;
    idList<cm_polygon_t, TAG_IDLIST> polygons;
    idList<cm_gridPart_t, TAG_IDLIST> parts;
    idList<cm_gridNodeBSP_t, TAG_IDLIST> nodes;
    int numX;
    int numY;
    idVec2i offset;
    int dimension;
};

class idCollisionGrid : public idResource {
public:
    ~idCollisionGrid() override = default;

    virtual void CreateState(idCollisionGridState& state) = 0;
    virtual void InactivateFill(const idVec2i* positions, int num,
        idCollisionGridState& state) = 0;
    virtual bool IsValid() const = 0;
};

class idCollisionGridLocal final : public idCollisionGrid {
public:
    idCollisionGridLocal();
    ~idCollisionGridLocal() override;

    void LoadResource() override;
    bool ReloadIfStale() override;
    idResourceList* GetResourceList() override;
    void CreateState(idCollisionGridState& state) override;
    void InactivateFill(const idVec2i* positions, int num,
        idCollisionGridState& state) override;
    bool IsValid() const override;

    idStr GetBinaryFileName(const char* modelName) const;
    void FreeData();
    bool Load_Binary();
    bool LoadBinary();

    static idResourceList resourceList;

    idGenGridModel grid;
    int binaryTimeStamp;
    int sourceTimeStamp;
};

class idGridRasterize {
public:
    static void RasterizePolygon(const idGenGridModel& grid,
        idCollisionGridState& state, const idVec2i* positions, int num);
};

static_assert(sizeof(cm_gridPart_t) == 18,
    "Recovered cm_gridPart_t ABI changed");
static_assert(sizeof(cm_gridNodeBSP_t) == 36,
    "Recovered cm_gridNodeBSP_t ABI changed");

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idCollisionGridState) == 24,
    "Recovered idCollisionGridState ABI changed");
static_assert(sizeof(idGenGridModel) == 132,
    "Recovered idGenGridModel ABI changed");
static_assert(sizeof(idCollisionGrid) == 36,
    "Recovered idCollisionGrid ABI changed");
static_assert(sizeof(idCollisionGridLocal) == 176,
    "Recovered idCollisionGridLocal ABI changed");
#endif
