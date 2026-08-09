#pragma once

#include "idlib/containers/list.h"
#include "idlib/geometry/surface_patch.h"
#include "idlib/math/plane.h"
#include "idlib/text/str.h"

class idFile;
class idLexer;

class idMapGroups {
public:
    idMapGroups() = default;
    virtual ~idMapGroups();

    void WriteGroups(idFile* file, const char* tabs) const;
    void RenameReferenceGroups(const char* referenceName);
    idStr RemoveLeadingReferencePaths();
    static void ParseGroups(idLexer& lexer,
        idList<idStr, TAG_IDLIB>& groups);

    idList<idStr, TAG_IDLIB> groupList;
};

enum mapPrimitiveType_t : int {
    MAP_PRIMITIVE_REFERENCE = -1,
    MAP_PRIMITIVE_BRUSH = 0,
    MAP_PRIMITIVE_PATCH = 1
};

class idMapPrimitive : public idMapGroups {
public:
    idMapPrimitive();
    ~idMapPrimitive() override;

    virtual unsigned int GetGeometryCRC() const;
    virtual void Transform(const idVec3& origin, const idMat3& axis);
    virtual bool Write(idFile* file, int primitiveNumber) const;

    int type;
};

class idMapModel {
public:
    idMapModel();
    ~idMapModel();

    void TransformPrimitives(const idVec3& origin, const idMat3& axis);

    idStr name;
    idList<idMapPrimitive*, TAG_IDLIB> primitives;
};

class idMapBrushSide {
public:
    idMapBrushSide();

    const idPlane& GetPlane() const;

    idStr material;
    idPlane plane;
    idVec3 texMat[2];
    idVec3 origin;
};

class idMapBrush : public idMapPrimitive {
public:
    idMapBrush();
    ~idMapBrush() override;

    unsigned int GetGeometryCRC() const override;
    void Transform(const idVec3& origin, const idMat3& axis) override;
    bool Write(idFile* file, int primitiveNumber) const override;

    static idMapBrush* Parse(idLexer& lexer, const idVec3& origin,
        bool newFormat, int version);
    static idMapBrush* ParseQ3(idLexer& lexer, const idVec3& origin);

    idList<idMapBrushSide*, TAG_IDLIB> sides;
};

class idMapPatch : public idMapPrimitive, public idSurface_Patch {
public:
    explicit idMapPatch(int maxPatchWidth = 0, int maxPatchHeight = 0);
    ~idMapPatch() override;

    unsigned int GetGeometryCRC() const override;
    void Transform(const idVec3& origin, const idMat3& axis) override;
    bool Write(idFile* file, int primitiveNumber) const override;

    const char* GetMaterial() const { return material.c_str(); }
    int GetHorzSubdivisions() const;
    int GetVertSubdivisions() const { return vertSubdivisions; }
    bool GetExplicitlySubdivided() const;

    static idMapPatch* Parse(idLexer& lexer, const idVec3& origin,
        bool patchDef3, int version);

    idVec3 origin;
    idStr material;
    int horzSubdivisions;
    int vertSubdivisions;
    bool explicitSubdivisions;
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
