#include "game/decls/declonlinecoopscoring.h"

idDeclInfoTemplate<idDeclOnlineCoopScoring>
    idDeclOnlineCoopScoring::resourceList(
        "onlineCoopScoring", "idDeclOnlineCoopScoring", "tdef");
idDeclInfoTemplate<idDeclOnlineScoringCallout>
    idDeclOnlineScoringCallout::resourceList(
        "onlineCoopCallout", "idDeclOnlineScoringCallout", "tdef");

// EA 0x82BC9410
idDeclOnlineScoringCallout::idDeclOnlineScoringCallout()
    : sound(nullptr)
    , text()
    , icon(nullptr)
    , priority(0) {
}

// EA 0x82BC9540
idDeclOnlineCoopScoring::coopScoring_Multiplier_t::
        coopScoring_Multiplier_t()
    : normalDamageMultiplierPointsFactor(1.0f)
    , headshotDamageMultiplierPointsFactor(1.0f)
    , takenNormalDamageScale(1.0f)
    , takenMeleeDamageScale(1.0f)
    , takenProjectileDamageScale(1.0f)
    , takenDamageMultiplierScale(10.0f)
    , assistPoints(50)
    // The retail constructor does not write revengePoints (offset 0x1c).
    , comboPoints(50)
    , defendPoints(50)
    , covertPoints(50)
    , brutalPoints(50)
    , incapacitatePoints(-1000)
    , incapacitatePointsPerSecond(-10)
    , revivePCTPoints(0.75f)
    , idlePointsPerSecond(-10)
    , idlePointsStartupTime(15.0f)
    , takenDamageTable()
    , takenDamageResetTime(5000) {
}

// EA 0x82BC94E0
void idDeclOnlineCoopScoring::LoadAllDecls() {
    for (int sourceIndex = 0;
            sourceIndex < resourceList.declSources.Num(); ++sourceIndex) {
        const idDeclSource* source = resourceList.declSources[sourceIndex];
        if (source != nullptr && source->name.c_str() != nullptr) {
            resourceList.FindWithInheritance(source->name.c_str(), false);
        }
    }
}

// EA 0x82BC9610
idDeclOnlineCoopScoring::idDeclOnlineCoopScoring()
    : events{0.1f, 25, 50, 75, 75, 150, 175,
        100, 200, 300, 500, 50}
    , multiplier()
    , multiplierPointsPerLevel(1000)
    , multiplierPointsLevelBuffer(100)
    , maxMultiplierPoints(3000)
    , multiplierUpCallout(nullptr)
    , multiplierDownCallout(nullptr)
    , headshotCallout(nullptr)
    , defendCallout(nullptr)
    , assistCallout(nullptr)
    , revengeCallout(nullptr)
    , comboCallout(nullptr)
    , brutalCallout(nullptr)
    , covertCallout(nullptr)
    , doubleKillCallout(nullptr)
    , tripleKillCallout(nullptr)
    , quadKillCallout(nullptr)
    , killingSpreeCallout(nullptr)
    , collectableCallout(nullptr) {
}

// EA 0x82BC9740
idDeclOnlineCoopScoring::~idDeclOnlineCoopScoring() = default;
