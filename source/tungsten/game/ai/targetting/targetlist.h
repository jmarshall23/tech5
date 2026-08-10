#pragma once

#include "targetcache.h"
#include "targetfilter.h"
#include "targetselector_core.h"

enum garageList_t : int {
    GARAGE_NONE = 0,
    GARAGE_HAGER = 1,
    GARAGE_WELLSPRING = 2,
    GARAGE_SUBWAYTOWN = 3,
    GARAGE_MAX = 4
};

enum targetListType_t : int {
    TARGETTYPE_ENTER = 0,
    TARGETTYPE_EXIT = 1,
    TARGETTYPE_PRIMARYFIRE = 2,
    TARGETTYPE_SECONDARYFIRE = 3
};

class idTargetList {
public:
    explicit idTargetList(const idTargetCache& targetCache_);
    int Filter(const idEntity* owner, const idTargetFilter& filter);
    int FindBestTarget(const idEntity* owner, const idTargetFilter& filter,
        const idTargetSelector& selector);

    const idTargetCache* targetCache;
    idStaticList<int, 8> viableTargets;
    int bestTargetIndex;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idTargetList) == 56,
    "Recovered AI target-list ABI changed");
#endif

idVec3 Tungsten_GetTargetListOwnerDirection(const idEntity& owner);
bool Tungsten_DebugTargetListEnabled();
void Tungsten_DebugTargetListWeight(const idEntity& owner,
    const idTargetInfo& targetInfo, float weight);
