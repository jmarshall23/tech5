#pragma once

#include "decls/decl.h"
#include "renderer/parmblock.h"

class idDeclEnv : public idDecl {
public:
    idDeclEnv();
    idDeclInfo* GetDeclInfo() const override;
    const char* DefaultDefinition() const override;
    void FreeData() override;
    void Parse(idParser* parser) override;

    idParmBlock parmBlock;
    idAtomicString parentDeclName;
    float blendDuration;

    static idDeclInfoTemplate<idDeclEnv> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclEnv) == 104,
    "Recovered environment declaration ABI changed");
#endif
