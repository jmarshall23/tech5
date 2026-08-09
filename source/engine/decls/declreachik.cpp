#include "decls/declreachik.h"

idDeclInfoTemplate<idDeclReachIK> idDeclReachIK::resourceList(
    "reachIK", "idDeclReachIK", "reachik");

idDeclReachIK::idDeclReachIK() : armInfo(16) {}
idDeclReachIK::~idDeclReachIK() = default;
idDeclInfo* idDeclReachIK::GetDeclInfo() const { return &resourceList; }
void idDeclReachIK::FreeData() { armInfo.Clear(); }
