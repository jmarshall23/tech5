#pragma once

#include "framework/resource.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

class idRenderWorld;

class idAAS2DebugAreaModelData {
public:
    struct areaTri_t { int v0; int v1; int v2; };
    struct debugAreaInfo_t { idList<areaTri_t, 5> tris; };

    idAAS2DebugAreaModelData();
    ~idAAS2DebugAreaModelData();

    using drawTriangleCallback_t = void (*)(idRenderWorld* renderWorld,
        const idVec3& v0, const idVec3& v1, const idVec3& v2,
        const float color[4]);
    static void SetDrawTriangleCallback(drawTriangleCallback_t callback);

    void Draw(idRenderWorld* renderWorld,
        const idList<int, 5>& visibleAreas) const;
    static void BuildResourceNameFromAASName(const char* aasName,
        idStr& resourceName);
    void Free();
    idResource::resourceError_t LoadBinary(const char* binaryFileName,
        idStr& errorMessage);

    static constexpr int BINARY_VERSION_HI = 1;
    static constexpr int BINARY_VERSION_LO = 0;
    static constexpr const char* BINARY_FILE_EXTENSION = "baasd";
    static constexpr const char* TEXT_FILE_EXTENSION = ".aasd";

    idList<idVec3, 5> vertices;
    idList<debugAreaInfo_t, 5> areas;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idAAS2DebugAreaModelData::areaTri_t) == 12,
    "Recovered debug area triangle ABI changed");
static_assert(sizeof(idAAS2DebugAreaModelData::debugAreaInfo_t) == 16,
    "Recovered debug area info ABI changed");
static_assert(sizeof(idAAS2DebugAreaModelData) == 32,
    "Recovered debug area data ABI changed");
#endif
