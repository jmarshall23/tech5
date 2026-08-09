#pragma once

#include "idlib/containers/list.h"
#include "models/cuttable/contourinfo.h"

// Owns the linked storage used by the cuttable contour representation.  The
// recovered implementation keeps three intrusive free lists so repeated cuts
// do not continuously allocate small contour records.
class ContourManager {
public:
    ContourManager();
    ~ContourManager();

    Contour* Create(const idList<idVec2i, 5>& points);
    void Free(Contour* contour);
    void Merge(Contour* contours);
    void SplitEdge(ContourEdge_t* edge, const idVec2i& v0,
        const idVec2i& v1, const idVec2i& pos);

private:
    Contour* AllocContour();
    ContourEdge_t* AllocEdge();
    ContourNode_t* AllocNode();

    Contour* contoursPool;
    ContourEdge_t* edgesPool;
    ContourNode_t* nodesPool;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(ContourManager) == 12,
    "Recovered ContourManager ABI changed");
#endif
