#pragma once

#include "idlib/math/vector.h"

float LerpToWithScale(float current, float destination, float scale);
float LerpToWithRate(float current, float destination, float absoluteRate);

bool UpdateWalkBlend(const idVec3& velocity, const idMat3& axis,
    float lerpScale, float& blendBack, float& blendRight, float& blendAngle,
    float& sync8Index1, float& sync8Index2, float& sync8BlendAngle);

bool UpdateWalkBlendFromAngle(float angle, float lerpScale,
    float& blendBack, float& blendRight, float& blendAngle,
    float& sync8Index1, float& sync8Index2, float& sync8BlendAngle);
