#pragma once

#include "decls/decl.h"

class idParser;

// Type-info declarations are reflected declaration objects.  Their authored
// body is applied on top of either an inherited declaration or an empty
// object of the same registered type.
class alignas(4) idDeclTypeInfo : public idDecl {
public:
    idDeclTypeInfo();
    ~idDeclTypeInfo() override;

    void Parse(idParser* parser) override;
    bool RebuildTextSource() override;
    idDeclInfo* GetDeclInfo() const override;

    void SetState(const idDeclTypeInfo* emptyState);

    idDeclTypeInfo* parent;
    bool hasBeenParsedAtLeastOnce;

    static idDeclInfoTemplate<idDeclTypeInfo> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclTypeInfo) == 64,
    "Recovered type-info declaration ABI changed");
#endif
