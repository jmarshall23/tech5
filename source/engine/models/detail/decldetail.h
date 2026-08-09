#pragma once

#include "decls/decl.h"
#include "idlib/math/vector.h"

class idDeclDetail : public idDecl {
public:
    idDeclDetail();

    idDeclInfo* GetDeclInfo() const override;
    const char* DefaultDefinition() const override;
    void Parse(idParser* parser) override;

    idAtomicString modelName;
    idVec3 colorVariance;

    static idDeclInfoTemplate<idDeclDetail> resourceList;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idDeclDetail) == 72,
    "Recovered detail declaration ABI changed");
#endif
