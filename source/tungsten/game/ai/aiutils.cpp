#include "aiutils.h"

#include <cmath>

// Retail symbol: ?CalcDecelerationDistance@idAIUtils@@SAMMM@Z
// EA: 0x82A60E58, RVA: 0x00A60E58
float idAIUtils::CalcDecelerationDistance(
        const float currentVelocity, const float decelerationRate) {
    if (std::fabs(decelerationRate) < 0.00001f) {
        return 0.0f;
    }
    return -(currentVelocity * currentVelocity) / (decelerationRate * 2.0f);
}

// Retail symbol: ?CalcExactDecelerationRate@idAIUtils@@SAMMM@Z
// EA: 0x82A60E98, RVA: 0x00A60E98
float idAIUtils::CalcExactDecelerationRate(
        const float currentVelocity, const float distance) {
    if (std::fabs(distance) <= 0.00001f) {
        return 0.0f;
    }
    return -(currentVelocity * currentVelocity) / (distance * 2.0f);
}
