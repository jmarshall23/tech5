#include "decls/decltypeinfo.h"

#include "decls/declmanager.h"
#include "idlib/text/parser.h"
#include "idlib/text/tokenstatic.h"

// Reflection is owned by the type-info subsystem.  These seams preserve the
// recovered declaration lifecycle without inventing a second serializer in
// decls while that subsystem is still being reconstructed.
bool Decls_ReadTypeInfoState(idDeclTypeInfo& declaration, idParser& parser,
    const idDeclTypeInfo* inheritedState);
bool Decls_WriteTypeInfoState(const idDeclTypeInfo& declaration,
    const idDeclTypeInfo* emptyState, idStr& text);

idDeclInfoTemplate<idDeclTypeInfo> idDeclTypeInfo::resourceList(
    "typeinfo", "idDeclTypeInfo", "tdef");

idDeclTypeInfo::idDeclTypeInfo()
    : parent(nullptr), hasBeenParsedAtLeastOnce(false) {
}

idDeclTypeInfo::~idDeclTypeInfo() = default;

idDeclInfo* idDeclTypeInfo::GetDeclInfo() const { return &resourceList; }

void idDeclTypeInfo::Parse(idParser* const parser) {
    parent = nullptr;
    if (parser == nullptr) {
        resourceError = "missing parser";
        return;
    }

    if (parser->PeekTokenString("inherit") != 0) {
        idToken parentName;
        if (!parser->ExpectTokenString("inherit")
            || !parser->ExpectTokenString("=")
            || parser->ExpectAnyToken(parentName) == 0
            || !parser->ExpectTokenString(";")) {
            resourceError = "invalid inherit clause";
            return;
        }

        idDeclInfo* const info = GetDeclInfo();
        if (info != nullptr && parentName.Length() != 0) {
            parent = static_cast<idDeclTypeInfo*>(
                info->Load(parentName.c_str(), false, false));
            if (parent != nullptr && declManager != nullptr)
                declManager->AddDependency(this, parent);
        }
    }

    if (!Decls_ReadTypeInfoState(*this, *parser, parent)) {
        resourceError = "type-info parse failed";
        return;
    }
    hasBeenParsedAtLeastOnce = true;
}

void idDeclTypeInfo::SetState(const idDeclTypeInfo* const emptyState) {
    const idDeclTypeInfo* const baseline = parent != nullptr
        ? parent : emptyState;
    idStr text;
    if (!Decls_WriteTypeInfoState(*this, baseline, text)) {
        resourceError = "type-info write failed";
        return;
    }

    idStr declarationText("{\n");
    if (parent != nullptr) {
        idStr inheritLine;
        inheritLine.Format("\tinherit = \"%s\";\n", parent->GetName());
        declarationText.Append(inheritLine);
    }
    declarationText.Append(text);
    declarationText.Append("\n}");
    SetText(declarationText.c_str());
}

bool idDeclTypeInfo::RebuildTextSource() {
    idDeclTypeInfo* emptyState = parent;
    if (emptyState == nullptr) {
        idDeclInfo* const info = GetDeclInfo();
        emptyState = info != nullptr
            ? static_cast<idDeclTypeInfo*>(info->AllocDecl()) : nullptr;
    }

    SetState(emptyState);
    if (emptyState != parent) delete emptyState;
    return resourceError == nullptr;
}
