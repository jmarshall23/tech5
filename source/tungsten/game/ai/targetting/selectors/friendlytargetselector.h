#pragma once

#include "../targetselector_core.h"

class idFriendlyTargetSelector : public idTargetSelector {
public:
    ~idFriendlyTargetSelector() override = default;
    float GetWeight(
        const idEntity* owner, const idTargetInfo* target) const override;
};
