#include "decls/decldragjoints.h"

idDeclInfoTemplate<idDeclDragJoints> idDeclDragJoints::resourceList(
    "dragJoints", "idDeclDragJoints", "dragjoints");

idDeclDragJoints::idDeclDragJoints()
    : ghostJointDistance(16.0f), baseJoint(), joints(16), subWebs(16) {}
idDeclDragJoints::~idDeclDragJoints() = default;
idDeclInfo* idDeclDragJoints::GetDeclInfo() const { return &resourceList; }
