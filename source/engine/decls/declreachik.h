#pragma once

#include "decls/decliktypes.h"
#include "decls/decltypeinfo.h"

class idDeclReachIK : public idDeclTypeInfo {
public:
    idDeclReachIK();
    ~idDeclReachIK() override;
    idDeclInfo* GetDeclInfo() const override;
    void FreeData() override;

    idList<idIKArm, 83> armInfo;
    static idDeclInfoTemplate<idDeclReachIK> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclReachIK) == 80,
    "Recovered reach-IK declaration ABI changed");
#endif
