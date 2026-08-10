#include "targetlist.h"

// Retail symbol: ?Filter@idTargetList@@QAAHPBVidEntity@@ABVidTargetFilter@@@Z
// EA: 0x82B04410, RVA: 0x00B04410
int idTargetList::Filter(const idEntity* const owner,
        const idTargetFilter& filter) {
    bestTargetIndex = -1;
    viableTargets.Clear();

    for (int index = 0; index < targetCache->targets.Num(); ++index) {
        if (!filter.Filter(owner, targetCache->targets[index])) {
            continue;
        }
        if (viableTargets.Append(index) < 0) {
            return viableTargets.Num();
        }
    }
    return viableTargets.Num();
}

// Retail symbol:
// ?FindBestTarget@idTargetList@@QAAHPBVidEntity@@ABVidTargetFilter@@ABVidTargetSelector@@@Z
// EA: 0x82B044E8, RVA: 0x00B044E8
int idTargetList::FindBestTarget(const idEntity* const owner,
        const idTargetFilter& filter, const idTargetSelector& selector) {
    bestTargetIndex = -1;
    viableTargets.Clear();
    float bestWeight = 0.0f;
    selector.ownerDir = Tungsten_GetTargetListOwnerDirection(*owner);

    for (int index = 0; index < targetCache->targets.Num(); ++index) {
        const idTargetInfo& targetInfo = targetCache->targets[index];
        if (!filter.Filter(owner, targetInfo)) {
            continue;
        }
        if (viableTargets.Append(index) < 0) {
            return bestTargetIndex;
        }

        const float weight = selector.GetWeight(owner, &targetInfo);
        if (Tungsten_DebugTargetListEnabled()) {
            Tungsten_DebugTargetListWeight(*owner, targetInfo, weight);
        }
        if (weight > bestWeight) {
            bestWeight = weight;
            bestTargetIndex = viableTargets.Num() - 1;
        }
    }
    return bestTargetIndex;
}

// Retail symbol: ??0idTargetList@@QAA@ABVidTargetCache@@@Z
// EA: 0x82B048C0, RVA: 0x00B048C0
idTargetList::idTargetList(const idTargetCache& targetCache_)
    : targetCache(&targetCache_)
    , viableTargets()
    , bestTargetIndex(-1) {
}
