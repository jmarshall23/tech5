#pragma once

#include "../targetfilter.h"

class idEnemyTargetFilter : public idTargetFilter {
public:
    explicit idEnemyTargetFilter(aiAwareness_t minimumAwareness);
    ~idEnemyTargetFilter() override = default;

    bool InternalFilter(
        const idEntity* owner, const idTargetInfo* target) const override;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idEnemyTargetFilter) == 8,
    "Recovered enemy target-filter ABI changed");
#endif
