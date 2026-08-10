#include "aicovermanager.h"

#include <cmath>

idAICoverManagerRuntime::idAICoverManagerRuntime()
    : aas(nullptr)
    , travelFlags(0)
    , dynamicCoverCapabilities(0)
    , coverRadius(0.0f)
    , coverRadiusOverride(-1.0f)
    , useVehicleCover(true)
    , useFormationCover(true)
    , useStageCoverFilter(true) {
}

// Retail symbol: ??0idAICoverManager@@QAA@XZ
// EA: 0x82A8A450, RVA: 0x00A8A450
idAICoverManager::idAICoverManager()
    : knownCover(16)
    , lastUpdateTime(0)
    , lastTravelFlags(0)
    , lastUpdatePos(0.0f, 0.0f, 0.0f)
    , forceUpdate(false) {
}

// Retail symbol: ?UpdateCover@idAICoverManager@@QAAXPAVidAI2@@ABVidVec3@@H_N2@Z
// EA: 0x82A8A508, RVA: 0x00A8A508
void idAICoverManager::UpdateCover(idAI2* const ai,
        const idVec3& referencePoint, const int currentTime,
        const bool force, const bool useStageFilter) {
    if (ai == nullptr) {
        return;
    }
    idAICoverManagerRuntime runtime;
    if (!Tungsten_GetAICoverManagerRuntime(*ai, runtime)) {
        return;
    }

    const int elapsedTime = currentTime - lastUpdateTime;
    const bool travelFlagsChanged =
        runtime.travelFlags != lastTravelFlags;
    const bool hasDynamicCover =
        (runtime.dynamicCoverCapabilities & 0xC0) != 0;
    const idVec3 movement = referencePoint - lastUpdatePos;
    const float movedDistanceSqr = movement.LengthSqr();
    bool shouldUpdate = force || forceUpdate || travelFlagsChanged;
    forceUpdate = false;
    if (!shouldUpdate && knownCover.IsEmpty() && elapsedTime >= 5000) {
        shouldUpdate = true;
    }
    if (!shouldUpdate && hasDynamicCover && elapsedTime >= 5000) {
        shouldUpdate = true;
    }
    if (!shouldUpdate && movedDistanceSqr >= 128.0f * 128.0f) {
        shouldUpdate = true;
    }
    if (!shouldUpdate || runtime.aas == nullptr) {
        return;
    }

    lastUpdatePos = referencePoint;
    lastUpdateTime = currentTime;
    lastTravelFlags = runtime.travelFlags;
    if (runtime.coverRadiusOverride != -1.0f) {
        runtime.coverRadius = runtime.coverRadiusOverride;
    }
    if (!runtime.useVehicleCover) {
        runtime.dynamicCoverCapabilities &= ~0x80;
    }
    if (!runtime.useFormationCover) {
        runtime.dynamicCoverCapabilities &= ~0x40;
    }

    knownCover.Clear();
    const int dynamicCoverCount = Tungsten_PopulateAICoverManager(
        *ai, runtime, referencePoint,
        useStageFilter && runtime.useStageCoverFilter, knownCover);
    Tungsten_DebugAICoverManagerUpdate(*ai, currentTime, elapsedTime,
        std::sqrt(movedDistanceSqr), travelFlagsChanged,
        dynamicCoverCount);
}

// Retail symbol: ?HasCover@idAICoverManager@@QAA_NPAVidAI2@@ABVidVec3@@H_N@Z
// EA: 0x82A8AD40, RVA: 0x00A8AD40
bool idAICoverManager::HasCover(idAI2* const ai,
        const idVec3& referencePoint, const int currentTime,
        const bool inAvoid) {
    UpdateCover(ai, referencePoint, currentTime,
        inAvoid, !inAvoid);
    return !knownCover.IsEmpty();
}
