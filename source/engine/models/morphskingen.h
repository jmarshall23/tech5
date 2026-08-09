#pragma once

#include "framework/resource.h"
#include "framework/resourcelist.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

#include <cstdint>

class idMorphDef {
public:
    enum flags_t : int {
        MORPHDEF_ELLIPSOID = 0x1,
        MORPHDEF_BOX = 0x2
    };

    idMorphDef() : jointName(), pos(0.0f, 0.0f, 0.0f),
        size(0.0f, 0.0f, 0.0f), flags(0) {}
    idMorphDef(const idMorphDef& rhs) : jointName(rhs.jointName),
        pos(rhs.pos), size(rhs.size), flags(rhs.flags) {}
    idMorphDef& operator=(const idMorphDef& rhs) {
        if (this != &rhs) {
            jointName = rhs.jointName;
            pos = rhs.pos;
            size = rhs.size;
            flags = rhs.flags;
        }
        return *this;
    }
    ~idMorphDef() { jointName.~idStr(); }

    // The executable stores morphFile and jointName in the same idStr. A
    // definition is either projection-file based or primitive based, never
    // both, so the union is part of the recovered 60-byte ABI.
    union {
        idStr jointName;
        idStr fileName;
    };
    idVec3 pos;
    idVec3 size;
    int flags;
};

class idMorphVertices : public idResource {
public:
    enum vertSetFlags_t : int {
        MORPHVERT_ELLIPSOID = 0x1,
        MORPHVERT_BOX = 0x2,
        MORPHVERT_SKIN = 0x4,
        MORPHVERT_CLIP_SPHERE = 0x8,
        MORPHVERT_CLIP_ELLIPSOID = 0x10
    };

    struct vertSet {
        vertSet();

        int meshNum;
        int jointGroupIndex;
        int flags;
        idVec3 pos;
        idVec3 size;
        idMat3 axis;
        idList<std::uint16_t, 115> vertices;
        idList<std::uint8_t, 115> morphDirection;
    };

    idMorphVertices();
    ~idMorphVertices() override = default;

    void LoadResource() override;
    bool ReloadIfStale() override;
    void WriteResourceFile() override;
    idResourceList* GetResourceList() override;

    bool Load_Binary();
    bool Write_Binary();
    bool LoadBinaryFile(const char* fileName);
    bool WriteBinaryFile(const char* fileName) const;

    unsigned int timestampDecl;
    unsigned int timestampModel;
    idList<vertSet, 5> morphVertSet;

    static idTypedResourceList<idMorphVertices> resourceList;
};

class idDeclMD6;
class idMD6Model;

class idMorphVertGen {
public:
    static void ProcessModel(const idMD6Model& model,
        const idDeclMD6* declaration, const idMorphDef& morphDef,
        idMorphVertices& vertices);
    static void OptimizeVertices(idMorphVertices& outputVertices,
        const idMorphVertices& inputVertices);
    static void GenerateMorphVertsFromFile(const idDeclMD6* declaration,
        const char* generationFile, idMorphVertices& vertices);
    static void GenerateMorphVerts(const idDeclMD6* declaration,
        const idList<idMorphDef, 115>& morphDefs,
        idMorphVertices& vertices);
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idMorphDef) == 60,
    "Recovered morph-definition ABI changed");
static_assert(sizeof(idMorphVertices::vertSet) == 104,
    "Recovered morph vertex-set ABI changed");
#endif
