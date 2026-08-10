#pragma once

#include "rotationtracker.h"

class idAITest_Rotation {
public:
    idAITest_Rotation();
    virtual ~idAITest_Rotation() = default;

    virtual void Think();

    idRotationTracker tracker;
    idVec3 lastDir;
    idAngles rate;
};

bool Tungsten_GetAITestRotationFrame(
    const idAITest_Rotation* test, idVec3& origin,
    idMat3& referenceAxis, idVec3& debugPlayerEyePosition);
bool Tungsten_IsAITestTrackerFrozen();
int Tungsten_GetAITestMillisecondsPerFrame();
int Tungsten_GetAITestMilliseconds();
