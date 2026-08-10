#pragma once

#include "cm/collisiongrid.h"
#include "cm/collisiontypes.h"
#include "idlib/bv/bounds.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

class idMaterial;

struct genVert_t {
	idVec3 xyz;
	idVec3 normal;
	idVec2 st;
};
struct genTri_t { int indexes[3]; };
struct genModelSurfParms_t {
	unsigned int flags;
	float texelDensity;
};

class idGenModelSurf {
public:
	idList< genVert_t, 5 > verts;
	idList< genTri_t, 5 > tris;
	idBounds bounds;
	const idMaterial * material;
	const idMaterial * mappingMaterial;
	genModelSurfParms_t parms;
	int materialNum;
	int basePoseVertexMask;
};

class idGenModel {
public:
	idStr path;
	unsigned int timestamp;
	idList< idGenModelSurf *, 5 > surfaces;
	idList< idStr, 5 > binaryModelNames;
	idBounds bounds;
	idBounds staticBounds;
};
