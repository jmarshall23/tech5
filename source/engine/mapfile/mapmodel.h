#pragma once

#include "idlib/containers/list.h"
#include "idlib/geometry/surface_patch.h"
#include "idlib/math/plane.h"
#include "idlib/text/str.h"

class idFile;

class idMapGroups {
public:
    virtual ~idMapGroups() = default;
    idList<idStr, TAG_IDLIB> groupList;
};

enum mapPrimitiveType_t : int {
    MAP_PRIMITIVE_BRUSH = 0,
    MAP_PRIMITIVE_PATCH = 1
};

class idMapPrimitive : public idMapGroups {
public:
    ~idMapPrimitive() override = default;
    virtual unsigned int GetGeometryCRC() { return 0; }
    virtual void Transform(const idVec3*, const idMat3*) {}
    virtual bool Write(idFile*, int) { return false; }

    int type = MAP_PRIMITIVE_BRUSH;
};

class idMapModel {
public:
    idStr name;
    idList<idMapPrimitive*, TAG_IDLIB> primitives;
};

class idMapBrushSide {
public:
    idStr material;
    idPlane plane;
    idVec3 texMat[2];
    idVec3 origin;
};

class idMapBrush : public idMapPrimitive {
public:
    idList<idMapBrushSide*, TAG_IDLIB> sides;
};

class idMapPatch : public idMapPrimitive, public idSurface_Patch {
public:
    idVec3 origin;
    idStr material;
    int horzSubdivisions = 0;
    int vertSubdivisions = 0;
    bool explicitSubdivisions = false;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idMapPrimitive) == 24,
    "Recovered idMapPrimitive ABI changed");
static_assert(sizeof(idMapModel) == 48,
    "Recovered idMapModel ABI changed");
static_assert(sizeof(idMapBrushSide) == 84,
    "Recovered idMapBrushSide ABI changed");
static_assert(sizeof(idMapBrush) == 40,
    "Recovered idMapBrush ABI changed");
static_assert(sizeof(idMapPatch) == 164,
    "Recovered idMapPatch ABI changed");
#endif
