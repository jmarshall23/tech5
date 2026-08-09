#include "decls/animwebs/animprops.h"

const idMD6Anim* AnimWeb_SelectAliasAnim(const idDeclMD6* declaration,
    idAnimAliasHandle aliasHandle, int index, bool load);

void idMD6AnimProps::SetAliasHandle(const idAnimAliasHandle handle) {
    aliasHandle = handle;
    anim = nullptr;
}

void idMD6AnimProps::SetAnim(const idMD6Anim* const animation) {
    anim = animation;
    aliasHandle.Invalidate();
}

const idMD6Anim* idMD6AnimProps::SelectAnim(
        const idDeclMD6* const modelDeclaration, const int index) const {
    if (anim != nullptr) return anim;
    if (!aliasHandle.IsValid()) return nullptr;
    return AnimWeb_SelectAliasAnim(modelDeclaration, aliasHandle, index,
        false);
}

const idMD6Anim* idMD6AnimProps::SelectAndLoadAnim(
        const idDeclMD6* const modelDeclaration, const int index) const {
    if (anim != nullptr) return anim;
    if (!aliasHandle.IsValid()) return nullptr;
    return AnimWeb_SelectAliasAnim(modelDeclaration, aliasHandle, index,
        true);
}
