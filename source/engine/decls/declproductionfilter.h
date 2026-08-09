#pragma once

#include "decls/decltypeinfo.h"

class idDeclProductionFilter : public idDeclTypeInfo {
public:
    idDeclProductionFilter();
    ~idDeclProductionFilter() override;
    void Parse(idParser* parser) override;
    idDeclInfo* GetDeclInfo() const override;

    idList<idStr, 5> entityFilter;
    idList<idStr, 5> entityRenderModelFilter;

    static idDeclInfoTemplate<idDeclProductionFilter> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclProductionFilter) == 96,
    "Recovered production-filter declaration ABI changed");
#endif
