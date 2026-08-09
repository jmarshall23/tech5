#pragma once

#include "idlib/math/vector.h"
#include "idlib/text/atomicstring.h"
#include "idlib/text/str.h"

enum footStepType_t : int;

class idJointName : public idStr {
public:
    idJointName() = default;
    explicit idJointName(const char* name) : idStr(name) {}
};

struct idIKArm {
    idJointName hand;
    idJointName elbow;
    idJointName shoulder;
};

struct idIKLeg {
    idAtomicString foot;
    idAtomicString ankle;
    idAtomicString knee;
    idAtomicString hip;
    idAtomicString forward;
    footStepType_t footstep;
    idVec3 kneeDir;

    idIKLeg()
        : foot(""), ankle(""), knee(""), hip(""), forward(""),
          footstep(static_cast<footStepType_t>(0)),
          kneeDir(1.0f, 0.0f, 0.0f) {}
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idJointName) == 32,
    "Recovered joint-name ABI changed");
static_assert(sizeof(idIKArm) == 96, "Recovered arm-IK ABI changed");
static_assert(sizeof(idIKLeg) == 36, "Recovered leg-IK ABI changed");
#endif
