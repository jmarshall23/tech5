#pragma once

#include "decls/decltypeinfo.h"

class idDeclRollBones : public idDeclTypeInfo {
public:
    class idDeclRollBoneInstance {
    public:
        idStr rollSourceJoint;
        idStr rollDestJoint;
        float rollAmount;
    };

    idDeclRollBones();
    ~idDeclRollBones() override;
    idDeclInfo* GetDeclInfo() const override;

    idList<idDeclRollBoneInstance, 5> rollBones;
    static idDeclInfoTemplate<idDeclRollBones> resourceList;
};

class idTestRollBones;

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclRollBones::idDeclRollBoneInstance) == 68,
    "Recovered roll-bone record ABI changed");
static_assert(sizeof(idDeclRollBones) == 80,
    "Recovered roll-bones declaration ABI changed");
#endif
