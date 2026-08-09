#pragma once

#include "idlib/bv/bounds2d.h"
#include "idlib/math/vectori.h"

struct ContourNode_t {
    ContourNode_t* next;
    idVec2i pos;
};

struct ContourEdge_t {
    ContourEdge_t* next;
    ContourNode_t* node;
};

// Linked contour representation used by the cuttable graph and clipper.
// Storage is owned by ContourManager; this type only supplies traversal and
// geometric queries.
class Contour {
public:
    static bool SlopesEqual(const idVec2i& v1, const idVec2i& v2,
        const idVec2i& v3, const idVec2i& v4);
    static bool SlopesEqual(const idVec2i& v1, const idVec2i& v2,
        const idVec2i& v3);

    ContourEdge_t* FindEdge(const idVec2i& v0, const idVec2i& v1);
    static ContourNode_t* FindNode(ContourEdge_t* edge,
        const idVec2i& v0, const idVec2i& v1);
    bool ContainsPoint(const idVec2i& pos) const;

    Contour* next;
    ContourEdge_t* edges;
    idBounds2D bound;
    int numEdges;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(ContourNode_t) == 12,
    "Recovered ContourNode_t ABI changed");
static_assert(sizeof(ContourEdge_t) == 8,
    "Recovered ContourEdge_t ABI changed");
static_assert(sizeof(Contour) == 28, "Recovered Contour ABI changed");
#endif
