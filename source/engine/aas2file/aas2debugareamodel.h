#pragma once

#include "aas2file/aas2debugareamodeldata.h"
#include "framework/resource.h"

#include <cstdint>

class idAAS2DebugAreaModel : public idResource {
public:
    idAAS2DebugAreaModel();
    ~idAAS2DebugAreaModel() override;

    void LoadResource() override;
    bool ReloadIfStale() override;
    void WriteResourceFile() override;
    idResourceList* GetResourceList() override;

    static idResourceList resourceList;

    idAAS2DebugAreaModelData data;
    std::uint32_t sourceTimestamp;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idAAS2DebugAreaModel) == 72,
    "Recovered idAAS2DebugAreaModel ABI changed");
#endif
