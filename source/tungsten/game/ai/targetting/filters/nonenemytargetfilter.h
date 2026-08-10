#pragma once

#include "../targetfilter.h"

class idNonEnemyTargetFilter : public idTargetFilter {
public:
    explicit idNonEnemyTargetFilter(aiAwareness_t minimumAwareness);
    ~idNonEnemyTargetFilter() override = default;

    bool InternalFilter(
        const idEntity* owner, const idTargetInfo* target) const override;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idNonEnemyTargetFilter) == 8,
    "Recovered non-enemy target-filter ABI changed");
#endif
