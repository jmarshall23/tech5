#pragma once

#include "gamelib/animstack/animator_base.h"
#include "idlib/containers/list.h"

class idDeclPonytail;

struct idConeConstraint_Quat {
    idQuat current;
    idQuat center;
    float limitAngleDot;
    float halfLimitAngleCosine;
    float halfLimitAngleSine;
};

struct idPonytailSegment {
    idVec3 localOrigin;
    idQuat localAxis;
    idVec3 origin;
    idConeConstraint_Quat coneConstraintQ;
    float len;
};

template<typename type>
struct idSpring;
template<>
struct idSpring<idVec3> {
    idVec3 p0;
    idVec3 p1;
    idVec3 vel;
    float maxSpeed;
    idVec3 pMin;
    idVec3 pMax;
    bool hasPMax;
    bool hasPMin;
    float k;
    float c;
    float m;
    float restLength;
};

class idAnimatorParms_Ponytail : public idAnimatorParms_Base {
public:
    const idDeclPonytail* declPonytail;
    idTreeAnimator* parentAnimator;
};

class idAnimator_Ponytail : public idAnimator_Base {
public:
    idAnimator_Ponytail();
    ~idAnimator_Ponytail() override;

    bool InternalInit(const idAnimatorParms_Base& parameters) override;
    void InternalShutdown(idAnimStack* stack) override;
    void InternalPreBlendTree(const idAnimStack* stack, int currentTime,
        int ticksPerSecond) override;
    bool InternalIsContributing() const override { return isInitialized; }
    const idMD6Branch* InternalGetMergeBranch() const override {
        return mergeBranch;
    }
    idMD6Branch* InternalGetMergeBranch() override { return mergeBranch; }

    const idDeclPonytail* declPonytail;
    idTreeAnimator* parentAnimator;
    idList<idJointIndex, 30> joints;
    idMD6Branch* mergeBranch;
    idMD6LeafPause* pauseLeaf;
    idMD6LeafPlay* playLeaf;
    idMD6Branch* lerpBranch;
    idList<idPonytailSegment, 30> segments;
    idSpring<idVec3> ptEndSpring;
    bool isInitialized;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idConeConstraint_Quat) == 44,
    "Recovered quaternion cone-constraint ABI changed");
static_assert(sizeof(idPonytailSegment) == 88,
    "Recovered ponytail segment ABI changed");
static_assert(sizeof(idSpring<idVec3>) == 84,
    "Recovered vector spring ABI changed");
static_assert(sizeof(idAnimator_Ponytail) == 184,
    "Recovered idAnimator_Ponytail ABI changed");
static_assert(sizeof(idAnimatorParms_Ponytail) == 64,
    "Recovered ponytail parameters ABI changed");
#endif
