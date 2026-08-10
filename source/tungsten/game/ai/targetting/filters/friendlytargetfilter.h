#pragma once

#include "../targetfilter.h"
#include "turretfilter.h"

class idFriendlyTargetFilter : public idTargetFilter {
public:
    explicit idFriendlyTargetFilter(aiAwareness_t minimumAwareness);
    ~idFriendlyTargetFilter() override = default;

    bool InternalFilter(
        const idEntity* owner, const idTargetInfo* target) const override;
};

class idFriendlyDeadTargetFilter : public idTargetFilter {
public:
    explicit idFriendlyDeadTargetFilter(aiAwareness_t minimumAwareness);
    ~idFriendlyDeadTargetFilter() override = default;

    bool InternalFilter(
        const idEntity* owner, const idTargetInfo* target) const override;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idFriendlyTargetFilter) == 8,
    "Recovered friendly target-filter ABI changed");
static_assert(sizeof(idFriendlyDeadTargetFilter) == 8,
    "Recovered friendly-dead target-filter ABI changed");
#endif
