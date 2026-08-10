#pragma once

#include "drawvert.h"
#include "../bv/bounds.h"
#include "../containers/list.h"
#include "../math/matrix.h"
#include "../sys/sys_alloc.h"

enum SurfaceSwap : int {
    SWAP_LOWRED = 0,
    SWAP_LOWBLUE = 1
};

enum surfaceType_t : int {
    SURFACE_NONE = 0,
    SURFACE_FLOOR = 1,
    SURFACE_FLOOR_CRAWL = 2,
    SURFACE_WALL = 3,
    SURFACE_WALL_CRAWL = 4,
    SURFACE_CEILING = 5,
    SURFACE_HORIZONTAL_POLE = 6,
    SURFACE_PERCH = 7,
    SURFACE_AIR = 8,
    SURFACE_CUSTOM = 9
};

struct surfaceEdge_t {
    int verts[2];
    int tris[2];
};

class idSurface {
public:
    idSurface();
    idSurface(const idSurface&) = default;
    ~idSurface();

    void TranslateSelf(const idVec3& translation);
    void RotateSelf(const idMat3& rotation);
    void GetBounds(idBounds& bounds) const;

    idList<idDrawVert, TAG_IDLIB> verts;
    idList<int, TAG_IDLIB> indexes;
    idList<surfaceEdge_t, TAG_IDLIB> edges;
    idList<int, TAG_IDLIB> edgeIndexes;

protected:
    void GenerateEdgeIndexes();
};

struct matchVert_t {
    int next;
    int v;
    int tv;
    int morph;
    unsigned int color;
    idVec3 normal;
    idVec3 tangents[2];
};

class idMaterial;

class idRawSurface {
public:
    const idMaterial* material;
    int materialNum;
    const idList<idVec3>* pvList;
    const idList<idVec2>* ptvList;
    const idList<idVec3>* pMorphList;
    idList<int> indexes;
    idList<matchVert_t> verts;
    idList<int> vertHash;
    bool generateNormals;
    float normalEpsilon;
};

// These Xbox graphics objects appeared in the PDB attribution for surface.h,
// but are platform types rather than idSurface storage.  Keep their names
// available without importing XDK definitions into the PC idLib boundary.
struct D3DSurface;
struct D3DSURFACES {
    D3DSurface* pDepthStencilSurface;
    D3DSurface* pRenderTarget[4];
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(surfaceEdge_t) == 16,
    "Recovered surfaceEdge_t ABI changed");
static_assert(sizeof(idSurface) == 64, "Recovered idSurface ABI changed");
static_assert(sizeof(matchVert_t) == 56,
    "Recovered matchVert_t ABI changed");
static_assert(sizeof(idRawSurface) == 76,
    "Recovered idRawSurface ABI changed");
static_assert(sizeof(D3DSURFACES) == 20,
    "Recovered D3DSURFACES ABI changed");
#endif
