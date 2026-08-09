#pragma once

#include "models/cloth/clothsim.h"

bool SphereLineIntersection(const idVec3& sphereOrigin,
    float radiusSquared, const idVec3& start, const idVec3& end);
void MakeRotationMat(idMat3& orientation, const idVec3& rotationVector,
    float angle);
void RopeGen(clothParms_t& clothParms);
void ClothGenJob(clothParms_t& clothParms);
