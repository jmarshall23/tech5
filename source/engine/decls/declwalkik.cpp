#include "decls/declwalkik.h"

idDeclInfoTemplate<idDeclWalkIK> idDeclWalkIK::resourceList(
    "walkIK", "idDeclWalkIK", "walkik");

idDeclWalkIK::idDeclWalkIK() : legJoints(16), waistJoint("") {
    FreeData();
}

idDeclWalkIK::~idDeclWalkIK() = default;
idDeclInfo* idDeclWalkIK::GetDeclInfo() const { return &resourceList; }

void idDeclWalkIK::FreeData() {
    legJoints.Clear();
    kneeDir.Set(1.0f, 0.0f, 0.0f);
    usePivot = false;
    dirsFromBasePose = false;
    restrictToBounds = false;
    checkFeetForSolids = false;
    smoothing = 0.75f;
    waistSmoothing = 0.5f;
    stairSmoothing = 0.85000002f;
    stairWaistSmoothing = 0.75f;
    footSmoothing = 0.0f;
    footShift = 0.0f;
    waistShift = 0.0f;
    minWaistFloorDist = 0.0f;
    minWaistAnkleDist = 0.0f;
    footSize = 4.0f;
    footUpTrace = 32.0f;
    footDownTrace = 32.0f;
    footDownTraceDead = 256.0f;
    restrictToBoundsTolerance = 0.0f;
}
