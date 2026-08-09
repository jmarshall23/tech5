#pragma once

#include "decls/decliktypes.h"
#include "decls/decltypeinfo.h"

class idDeclDragJoints : public idDeclTypeInfo {
public:
    idDeclDragJoints();
    ~idDeclDragJoints() override;
    idDeclInfo* GetDeclInfo() const override;

    float ghostJointDistance;
    idJointName baseJoint;
    idList<idJointName, 5> joints;
    idList<idStr, 5> subWebs;

    static idDeclInfoTemplate<idDeclDragJoints> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclDragJoints) == 132,
    "Recovered drag-joints declaration ABI changed");
#endif
