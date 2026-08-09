#include "decls/declrollbones.h"

idDeclInfoTemplate<idDeclRollBones> idDeclRollBones::resourceList(
    "rollBones", "idDeclRollBones", "rollbones");

idDeclRollBones::idDeclRollBones() : rollBones(16) {}
idDeclRollBones::~idDeclRollBones() = default;
idDeclInfo* idDeclRollBones::GetDeclInfo() const { return &resourceList; }
