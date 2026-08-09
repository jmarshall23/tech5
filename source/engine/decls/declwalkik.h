#pragma once

#include "decls/decliktypes.h"
#include "decls/decltypeinfo.h"

class idDeclWalkIK : public idDeclTypeInfo {
public:
    idDeclWalkIK();
    ~idDeclWalkIK() override;
    idDeclInfo* GetDeclInfo() const override;
    void FreeData() override;

    idList<idIKLeg, 83> legJoints;
    idAtomicString waistJoint;
    idVec3 kneeDir;
    float smoothing;
    float waistSmoothing;
    float stairSmoothing;
    float stairWaistSmoothing;
    float footSmoothing;
    float footShift;
    float waistShift;
    float minWaistFloorDist;
    float minWaistAnkleDist;
    float footSize;
    float footUpTrace;
    float footDownTrace;
    float footDownTraceDead;
    float restrictToBoundsTolerance;
    bool usePivot;
    bool restrictToBounds;
    bool dirsFromBasePose;
    bool checkFeetForSolids;

    static idDeclInfoTemplate<idDeclWalkIK> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclWalkIK) == 156,
    "Recovered walk-IK declaration ABI changed");
#endif
