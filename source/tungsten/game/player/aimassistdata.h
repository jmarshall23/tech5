#pragma once

struct aimAssistData_t {
    aimAssistData_t();

    bool targetAdhesionEnable;
    bool targetFrictionEnable;
    bool targetAdhesionEnableWhileMoving;
    bool targetZoomSnapEnable;
    float targetValidFovDot;
    float targetMaxDistance;
    float targetSelectionRadius;
    float targetZoomSelectionRadius;
    float targetCoverZoomSelectionRadius;
    float targetHeadShotZoomSelectionRadius;
    float targetAdhesionRadius;
    float targetAdhesionYawSpeedMax;
    float targetAdhesionPitchSpeedMax;
    float targetAdhesionContributionPctMax;
    float targetAdhesionContributionPctMaxZoom;
    float targetAdhesionZoomYawSpeedMax;
    float targetAdhesionZoomPitchSpeedMax;
    float targetFrictionMaxDistance;
    float targetFrictionOptimalDistance;
    float targetFrictionOptimalRadius;
    float targetFrictionRadius;
    float targetFrictionMultiplierMin;
    float targetFrictionMultiplierMax;
    float targetFrictionMultiplierMinZoom;
    float targetFrictionMultiplierMaxZoom;
    bool meleeSnapEnable;
    bool meleeLeftHandEnable;
    int meleeEquipWindow;
    bool meleeLungeEnable;
    float meleeLungeMinDist;
    float meleeLungeMaxDist;
    float meleeLungeMinSpeed;
    float meleeLungeMaxSpeed;
};

static_assert(sizeof(aimAssistData_t) == 116,
    "Recovered aim-assist data ABI changed");
