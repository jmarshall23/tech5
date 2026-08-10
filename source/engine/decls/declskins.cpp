#include "decls/declskins.h"

#include "idlib/text/parser.h"
#include "idlib/text/tokenstatic.h"
#include "renderer/declmaterial.h"

#include <cstring>

const idMaterial* DeclSkins_FindMaterial(const char* name, bool makeDefault);
const char* DeclSkins_GetMaterialName(const idMaterial* material);

idDeclInfoTemplate<idDeclSkins> idDeclSkins::resourceList(
    "skins", "idDeclSkins", "skin");

idDeclSkins::idDeclSkins() : skins(16) {}

idDeclInfo* idDeclSkins::GetDeclInfo() const { return &resourceList; }

const char* idDeclSkins::DefaultDefinition() const { return "{\n}\n"; }

const idMaterial* idSkin::Remap(const idMaterial* const material) const {
    for (int index = 0; index < mappings.Num(); ++index)
        if (mappings[index].from == material) return mappings[index].to;
    return material;
}

int idDeclSkins::IndexForSkin(const char* const skinName) const {
    if (skinName == nullptr) return -1;
    for (int index = 0; index < skins.Num(); ++index)
        if (_stricmp(skins[index].name.c_str(), skinName) == 0) return index;
    return -1;
}

bool idDeclSkins::RebuildTextSource() {
    idStr text("{\n");
    for (int skinIndex = 0; skinIndex < skins.Num(); ++skinIndex) {
        const idSkin& skin = skins[skinIndex];
        idStr line;
        line.Format("\t%s {\n", skin.name.c_str());
        text.Append(line);
        for (int mappingIndex = 0; mappingIndex < skin.mappings.Num();
                ++mappingIndex) {
            const idSkinMapping& mapping = skin.mappings[mappingIndex];
            if (mapping.from == nullptr || mapping.to == nullptr) continue;
            line.Format("\t\t\"%s\" \"%s\"\n",
                DeclSkins_GetMaterialName(mapping.from),
                DeclSkins_GetMaterialName(mapping.to));
            text.Append(line);
        }
        text.Append("\t}\n");
    }
    text.Append("}\n");
    SetText(text.c_str(), text.Length());
    return true;
}

void idDeclSkins::FreeData() { skins.ClearFree(); }

void idDeclSkins::Parse(idParser* const parser) {
    if (parser == nullptr) return;
    idToken token;
    if (parser->CheckTokenString("}") != 0) return;

    for (;;) {
        idSkin skin;
        if (parser->ExpectAnyToken(token) == 0) {
            parser->Warning("Unexpected end of file");
            return;
        }
        skin.name.Set(token.c_str());
        if (!parser->ExpectTokenString("{")) return;

        while (parser->CheckTokenString("}") == 0) {
            if (!parser->ReadToken(token)) {
                parser->Warning("Unexpected end of file");
                return;
            }
            idSkinMapping mapping{};
            mapping.from = DeclSkins_FindMaterial(token.c_str(), true);
            if (!parser->ReadToken(token)) {
                parser->Warning("Unexpected end of file");
                return;
            }
            mapping.to = DeclSkins_FindMaterial(token.c_str(), true);
            skin.mappings.Append(mapping);
        }

        if (skin.mappings.Num() != 0) skins.Append(skin);
        if (parser->CheckTokenString("}") != 0) return;
    }
}

const idMaterial* DeclSkins_FindMaterial(const char* name,
        bool makeDefault) {
    if (name == nullptr || name[0] == '\0') return nullptr;
    return static_cast<const idMaterial*>(makeDefault
        ? idMaterial::resourceList.Load(name, true, false)
        : idMaterial::resourceList.FindExisting(name, false));
}

const char* DeclSkins_GetMaterialName(const idMaterial* material) {
    return material != nullptr ? material->GetName() : "";
}
