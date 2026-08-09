#pragma once

#include "idlib/bv/bounds.h"
#include "idlib/math/plane.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

#include <cstdint>

struct pvsNode_t {
    unsigned int planeNum;
    std::int16_t children[2];
};

struct pvsPortal_t {
    int firstVertex;
    int numVertices;
};

struct pvsArea_t {
    int firstPortal;
    int numPortals;
};

struct pvsHandle_t {
    int i;
    unsigned int h;

    bool operator==(const pvsHandle_t& other) const {
        return i == other.i && h == other.h;
    }
};

struct pvsCurrent_t {
    pvsHandle_t handle;
    std::uint8_t* pvs;
};

class idPVS {
public:
    struct header_t {
        int magic;
        int numPlanes;
        int numVertices;
        int numNodes;
        int numPortals;
        int numAreas;
        int numPVSBytes;
    };

    static constexpr int PVS_MAGIC = 55793232;

    idPVS();
    virtual ~idPVS();

    int GetPVSAreas(const idBounds& bounds, int* areas, int maxAreas) const;
    int GetPVSArea(const idVec3& point) const;
    pvsHandle_t DecodePVS(const int* sourceAreas, int numSourceAreas) const;
    void FreePVS(pvsHandle_t handle) const;
    bool InPVS(pvsHandle_t handle, const int* targetAreas,
        int numTargetAreas) const;

    void LoadResource();
    void SetName(const char* name) { pvsName = name; }
    void SetBare(bool value) { bare = value; }

    // These allocation/default hooks are part of the recovered implementation
    // boundary and are public here so resource loaders can populate the data.
    unsigned int Alloc(bool bareAllocation);
    void Free();
    void Default();

    static void DecompressAddPVS(std::uint8_t* pvs, int numBytes,
        const std::uint8_t* compressed);

    header_t header;
    idStr pvsName;
    std::uint8_t* dataStart;
    idPlane* planes;
    idVec3* vertices;
    pvsNode_t* nodes;
    pvsPortal_t* portals;
    pvsArea_t* areas;
    int* areaOffsets;
    std::uint8_t* areaPVS;
    mutable pvsCurrent_t currentPVS[8];
    bool bare;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(pvsNode_t) == 8, "Recovered pvsNode_t ABI changed");
static_assert(sizeof(pvsPortal_t) == 8,
    "Recovered pvsPortal_t ABI changed");
static_assert(sizeof(pvsArea_t) == 8, "Recovered pvsArea_t ABI changed");
static_assert(sizeof(pvsHandle_t) == 8,
    "Recovered pvsHandle_t ABI changed");
static_assert(sizeof(pvsCurrent_t) == 12,
    "Recovered pvsCurrent_t ABI changed");
static_assert(sizeof(idPVS::header_t) == 28,
    "Recovered idPVS header ABI changed");
static_assert(sizeof(idPVS) == 196, "Recovered idPVS ABI changed");
#endif
