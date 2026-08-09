#pragma once

#include "cm/collisiontypes.h"
#include "cm/jobs/polygonmodel/polygonmodel_inline.h"

inline int CM_EdgeIndex(const std::uint16_t edgeReference) {
    return edgeReference & 0x7FFF;
}

inline int CM_EdgeStartVertex(const cm_edge_t& edge,
    const std::uint16_t edgeReference) {
    return edge.vertexNum[edgeReference >> 15];
}

inline int CM_EdgeEndVertex(const cm_edge_t& edge,
    const std::uint16_t edgeReference) {
    return edge.vertexNum[(edgeReference >> 15) ^ 1];
}

// Recovered from engine/cm/jobs/polygonmodel/polygonmodeldata.h.
inline void CM_GetPolygonPlane(const cm_subModelPtrs_t& subModel,
    const cm_polygon_t& polygon, idPlane& plane) {
    const std::uint16_t firstReference =
        subModel.polygonEdges[polygon.firstEdge];
    const std::uint16_t secondReference =
        subModel.polygonEdges[polygon.firstEdge + 1];
    const cm_edge_t& firstEdge =
        subModel.edges[CM_EdgeIndex(firstReference)];
    const cm_edge_t& secondEdge =
        subModel.edges[CM_EdgeIndex(secondReference)];
    const idVec3& firstPoint =
        subModel.vertices[CM_EdgeStartVertex(firstEdge, firstReference)].p;
    const idVec3& sharedPoint =
        subModel.vertices[CM_EdgeStartVertex(secondEdge, secondReference)].p;
    const idVec3& secondPoint =
        subModel.vertices[CM_EdgeEndVertex(secondEdge, secondReference)].p;

    idVec3 normal = (secondPoint - sharedPoint).Cross(
        firstPoint - sharedPoint);
    normal.NormalizeFast();
    plane.a = normal.x;
    plane.b = normal.y;
    plane.c = normal.z;
    plane.d = -normal.Dot(sharedPoint);
}
