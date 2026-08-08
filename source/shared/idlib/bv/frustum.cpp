#include "frustum.h"

void idFrustum::ToPoints(idVec3 points[8]) const {
    const idVec3 nearCenter = origin + axis[0] * dNear;
    const idVec3 nearLeft = axis[1] * (dLeft * dNear * invFar);
    const idVec3 nearUp = axis[2] * (dUp * dNear * invFar);
    points[0] = nearCenter + nearLeft + nearUp;
    points[1] = nearCenter - nearLeft + nearUp;
    points[2] = nearCenter - nearLeft - nearUp;
    points[3] = nearCenter + nearLeft - nearUp;

    const idVec3 farCenter = origin + axis[0] * dFar;
    const idVec3 farLeft = axis[1] * dLeft;
    const idVec3 farUp = axis[2] * dUp;
    points[4] = farCenter + farLeft + farUp;
    points[5] = farCenter - farLeft + farUp;
    points[6] = farCenter - farLeft - farUp;
    points[7] = farCenter + farLeft - farUp;
}
