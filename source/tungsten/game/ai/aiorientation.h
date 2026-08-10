#pragma once

#include "idlib/math/vector.h"

class idAI2;

enum turnDirection_t : int {
    TURN_NONE = 0,
    TURN_LEFT = 1,
    TURN_RIGHT = 2,
    TURN_MAX = 3
};

enum aiArrivalOrientation_t : int {
    AIARRIVAL_ORIENT_NONE = 0,
    AIARRIVAL_ORIENT_ALIGN = 1
};

enum hdpOrientation_t : int {
    O_NONE = 0,
    O_FLIPV = 1,
    O_FLIPH = 2,
    O_FLIPVH = 3,
    O_RCW = 4,
    O_RCW_FLIPV = 5,
    O_RCW_FLIPH = 6,
    O_RCW_FLIPVH = 7,
    O_MAX = 8
};

class idAIOrientation {
public:
    idAIOrientation(float minimumTurnRate, float maximumTurnRate);

    void UpdateStatic();
    void Init(const idMat3& initialAxis);
    void SetIdealDir(idAI2* ai, const idVec3& direction);
    void SetIdealDirTowards(idAI2* ai, const idVec3& point);
    void UpdateFromAnim(const idMat3& newAxis, float turnRate,
        turnDirection_t turnDirection, bool updateIdealDirection);
    turnDirection_t CalculateTurnDirection(const idVec3& normal) const;
    float CalcTurnRateForTime(const idVec3& rotationAxis,
        const idVec3& destinationDirection, float timeSeconds) const;
    bool IsAligned() const;
    bool IsAligned(const idVec3& testIdeal, float degrees) const;
    void SetAxis(const idVec3& direction, const idVec3& gravityDirection);
    void SetAxis(const idMat3& newAxis);
    turnDirection_t UpdateAxis(const idVec3& normal,
        float turnRate, float timeSeconds);
    turnDirection_t UpdateBodyAxis(const idVec3& normal,
        turnDirection_t turnDirection, float turnRate, float timeSeconds);
    void Update(const idVec3& velocity, const idVec3& origin,
        const idVec3& destination, const idVec3& gravityDirection,
        float turnRate, float maximumTurnRate, float timeSeconds);
    void SetAxis(idAI2* ai, const idVec3& direction);

    idVec3 idealDir;
    idMat3 axis;
    float lastTurnDelta;
    float lastTurnRate;
    float tolerance;
    unsigned char currentTurnDir;
    unsigned char previousTurnDir;
    float turnVelocity;
};

bool Tungsten_GetAIOrientationPhysics(const idAI2& ai,
    idVec3& origin, idVec3& gravityNormal);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAIOrientation) == 68,
    "Recovered idAIOrientation ABI changed");
#endif
