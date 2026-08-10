#pragma once

#include "idlib/blockalloc_base.h"
#include "idlib/bv/bounds.h"
#include "idlib/containers/hashindex.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

class idMaterial;
class idWinding;
struct manifoldEdge_t;
struct manifoldTriangle_t;

struct manifoldVertex_t {
	idVec3 xyz;
	idList< manifoldEdge_t *, 5 > edges;
	int flags;
};
struct manifoldEdgeTriangle_t {
	manifoldTriangle_t * triangle;
	int edgeNumber;
};
struct manifoldEdge_t {
	manifoldVertex_t * verts[2];
	manifoldEdgeTriangle_t * tris[2];
	manifoldEdge_t * split[2];
	int numTris;
	int flags;
};
struct manifoldTriangle_t {
	manifoldVertex_t * verts[3];
	manifoldEdge_t * edges[3];
	const idMaterial * material;
	idVec4 plane;
	int flags;
};
struct manifoldIsland_t {
	idList< manifoldTriangle_t *, 5 > triangles;
	idBounds bounds;
	int flags;
};
struct manifoldHint_t {
	int planeType;
	float planeDist;
	idWinding * winding;
};
struct manifoldNode_t {
	int planeType;
	float planeDist;
	idBounds bounds;
	idList< manifoldHint_t, 5 > hints;
	idList< manifoldTriangle_t *, 5 > triangles;
	idHashIndex triangleHash;
	idList< manifoldIsland_t *, 5 > islands;
	manifoldNode_t * children[2];
};

class idManifold {
public:
	enum occluders_t : int {
		OCCLUDERS_NONE, OCCLUDERS_ALL, OCCLUDERS_SIGNIFICANT,
		OCCLUDERS_OMNI_SIGNIFICANT, OCCLUDERS_DETAIL, OCCLUDERS_PIPE
	};
	enum color_t : int { COLOR_NONE, COLOR_ISLANDS, COLOR_NODES };
	struct tree_t {
		manifoldNode_t * root;
		occluders_t splitOccluders;
		int trianglesPerNode;
		float planarEpsilon, colinearEpsilon, flipEpsilon, convexEpsilon;
		float textureSpaceEpsilon;
		int doneTriangles, donePercent;
	};
	struct tjunction_t { manifoldEdge_t * edge; manifoldVertex_t * vertex; };

	idList< manifoldVertex_t *, 5 > vertices;
	idList< manifoldEdge_t *, 5 > edges;
	idList< manifoldTriangle_t *, 5 > triangles;
	idList< manifoldIsland_t *, 5 > islands;
	idHashIndex vertexHash, edgeHash, triangleHash;
	idList< manifoldEdge_t *, 5 > splitEdges;
	tree_t tree;
	idList< idStr, 5 > binaryModelNames;
	idList< bool, 5 > binaryModelState;
	idBlockAlloc< manifoldVertex_t, 1024, 12 > manifoldVertexAllocator;
	idBlockAlloc< manifoldEdgeTriangle_t, 1024, 12 > manifoldEdgeTriangleAllocator;
	idBlockAlloc< manifoldEdge_t, 1024, 12 > manifoldEdgeAllocator;
	idBlockAlloc< manifoldTriangle_t, 1024, 12 > manifoldTriangleAllocator;
	idBlockAlloc< manifoldIsland_t, 128, 12 > manifoldIslandAllocator;
	idBlockAlloc< manifoldNode_t, 1024, 12 > manifoldNodeAllocator;
};
