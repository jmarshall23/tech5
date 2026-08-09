#pragma once

#include "decls/decl.h"

class idLookupTable;

class idDeclTable : public idDecl {
public:
    idDeclTable();
    ~idDeclTable() override;

    idDeclInfo* GetDeclInfo() const override;
    const char* DefaultDefinition() const override;
    void Parse(idParser* parser) override;
    void FreeData() override;

    float left;
    float right;
    idLookupTable* table;

    static idDeclInfoTemplate<idDeclTable> resourceList;
};

class idDeclThrowable;

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclTable) == 68,
    "Recovered table declaration ABI changed");
#endif
