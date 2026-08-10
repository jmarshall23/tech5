#include "aitest.h"

// Retail symbol: ??0idAITest_Rotation@@QAA@XZ
// EA: 0x82A60B10, RVA: 0x00A60B10
idAITest_Rotation::idAITest_Rotation()
    : tracker()
    , lastDir(1.0f, 0.0f, 0.0f)
    , rate(360.0f, 360.0f, 0.0f) {
}

// Retail symbol: ?Think@idAITest_Rotation@@UAAXXZ
// EA: 0x82A60CA8, RVA: 0x00A60CA8
void idAITest_Rotation::Think() {
    idVec3 origin;
    idMat3 referenceAxis;
    idVec3 debugPlayerEyePosition;
    if (!Tungsten_GetAITestRotationFrame(
            this, origin, referenceAxis, debugPlayerEyePosition)) {
        return;
    }

    idVec3 direction = lastDir;
    if (!Tungsten_IsAITestTrackerFrozen()) {
        direction = debugPlayerEyePosition - origin;
        direction.NormalizeFast();
    }

    tracker.Update(origin, referenceAxis, direction,
        static_cast<float>(Tungsten_GetAITestMillisecondsPerFrame())
            * 0.001f,
        false, Tungsten_GetAITestMilliseconds());
    lastDir = direction;
}
