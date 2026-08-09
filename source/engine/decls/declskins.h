#pragma once

#include "decls/decl.h"

class idMaterial;

struct idSkinMapping {
    const idMaterial* from;
    const idMaterial* to;
};

struct idSkin {
    idSkin() : name(""), mappings(16) {}
    const idMaterial* Remap(const idMaterial* material) const;

    idAtomicString name;
    idList<idSkinMapping, 46> mappings;
};

class idDeclSkins : public idDecl {
public:
    idDeclSkins();
    idDeclInfo* GetDeclInfo() const override;
    const char* DefaultDefinition() const override;
    bool RebuildTextSource() override;
    void Parse(idParser* parser) override;
    void FreeData() override;

    int IndexForSkin(const char* skinName) const;

    idList<idSkin, 46> skins;
    static idDeclInfoTemplate<idDeclSkins> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idSkinMapping) == 8,
    "Recovered skin mapping ABI changed");
static_assert(sizeof(idSkin) == 20, "Recovered skin ABI changed");
static_assert(sizeof(idDeclSkins) == 72,
    "Recovered skins declaration ABI changed");
#endif
