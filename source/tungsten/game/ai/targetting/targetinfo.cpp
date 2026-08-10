#include "targetinfo.h"

// Retail symbol: ??0idTargetInfo@@QAA@XZ
// EA: 0x82B04158, RVA: 0x00B04158
idTargetInfo::idTargetInfo()
    : es(nullptr)
    , distSqr(0.0f)
    , distTo(0.0f)
    , delta()
    , faceDir(1.0f, 0.0f, 0.0f)
    , dirTo(1.0f, 0.0f, 0.0f)
    , attitude(-1)
    , healthRatio(0xFFu) {
}

// Retail symbol:
// ?Cache@idTargetInfo@@QAAXPBUaiLatchedState_t@@PBVidAIEntityState@@@Z
// EA: 0x82B041B0, RVA: 0x00B041B0
void idTargetInfo::Cache(const aiLatchedState_t* const ownerState,
        const idAIEntityState* const entityState) {
    es = entityState;
    delta = Tungsten_GetTargetInfoConfirmedOrigin(*entityState)
        - Tungsten_GetTargetInfoOwnerOrigin(*ownerState);
    distSqr = delta.LengthSqr();
    dirTo = delta;
    distTo = dirTo.NormalizeFast();
    faceDir = Tungsten_GetTargetInfoConfirmedViewForward(*entityState);
    attitude = 3;

    if (!Tungsten_TargetInfoHasEntity(*entityState)) {
        return;
    }

    const int ratio = Tungsten_GetTargetInfoHealthRatio(*entityState);
    if (ratio < 0) {
        healthRatio = 0;
    } else if (ratio > 255) {
        healthRatio = 0xFFu;
    } else {
        healthRatio = static_cast<unsigned char>(ratio);
    }

    char resolvedAttitude = attitude;
    if (Tungsten_GetTargetInfoAttitude(
            *ownerState, *entityState, resolvedAttitude)) {
        attitude = resolvedAttitude;
    }
}
