#pragma once

#include "../targetselector_core.h"

class idNeutralTargetSelector : public idTargetSelector {
public:
    ~idNeutralTargetSelector() override = default;
    float GetWeight(
        const idEntity* owner, const idTargetInfo* target) const override;
};
