#include "aibehaviors.h"

// Retail symbol: ??0idAIBehaviors@@QAA@XZ
// EA: 0x82A3F278, RVA: 0x00A3F278
idAIBehaviors::idAIBehaviors()
    : decl(nullptr)
    , declBehaviorVo(nullptr)
    , declBehaviorVoChains(nullptr)
    , declBehaviorEvents(nullptr)
    , aimTrackingParms(nullptr)
    , lookTrackingParms(nullptr)
    , avoidRadius(0.0f) {
}

// Retail symbol:
// ?GetWeaponCoverCapabilities@idAIBehaviors@@QBA_NPBVidWeapon@@W4posture_t@@W4coverOrientation_t@@AAVidCoverCapabilities@@@Z
// EA: 0x82A3F520, RVA: 0x00A3F520
bool idAIBehaviors::GetWeaponCoverCapabilities(
        const idWeapon* const weapon, const posture_t coverPosture,
        const coverOrientation_t coverOrientation,
        idCoverCapabilities& capabilities) const {
    if (weapon == nullptr || (coverOrientation != COVERORIENT_FORWARD
            && coverOrientation != COVERORIENT_BACKWARD)) {
        return false;
    }
    const int weaponCategory = Tungsten_GetAIBehaviorWeaponCategory(*weapon);
    const idAICoverCapabilities* const postureCapabilities =
        Tungsten_GetAIBehaviorWeaponCoverSet(
            *this, coverOrientation, weaponCategory);
    if (postureCapabilities == nullptr) {
        return false;
    }
    if (coverPosture == POSTURE_STANDING) {
        capabilities = postureCapabilities->fullCaps;
    } else if (coverPosture == POSTURE_CROUCHED) {
        capabilities = postureCapabilities->crouchCaps;
    } else {
        return false;
    }
    return true;
}

// Retail symbol:
// ?HasCoverCapability@idAIBehaviors@@QBA_NPBVidAI2@@W4posture_t@@W4coverOrientation_t@@ABVidCoverCapabilities@@@Z
// EA: 0x82A3F5F8, RVA: 0x00A3F5F8
bool idAIBehaviors::HasCoverCapability(const idAI2* const ai,
        const posture_t coverPosture,
        const coverOrientation_t coverOrientation,
        const idCoverCapabilities& coverCapabilities) const {
    idCoverCapabilities weaponCapabilities;
    GetWeaponCoverCapabilities(Tungsten_GetAIBehaviorEquippedWeapon(*ai),
        coverPosture, coverOrientation, weaponCapabilities);
    return weaponCapabilities.HasCapability(coverCapabilities);
}

// Retail symbol:
// ?FindBestCoverOrientation@idAIBehaviors@@QBA?AW4coverOrientation_t@@PBVidAI2@@ABVidAICover@@@Z
// EA: 0x82A3F6B0, RVA: 0x00A3F6B0
coverOrientation_t idAIBehaviors::FindBestCoverOrientation(
        const idAI2* const ai, const idAICover& cover) const {
    const bool forward = Tungsten_AIBehaviorUsesForwardCover(*this, *ai);
    const bool backward = Tungsten_AIBehaviorUsesBackwardCover(*this, *ai)
        && !Tungsten_IsAIBehaviorCoverPartiallyExposed(cover);
    if (!forward && backward) {
        return COVERORIENT_BACKWARD;
    }
    if (!backward) {
        return forward ? COVERORIENT_FORWARD : COVERORIENT_NONE;
    }

    idCoverActions actions;
    Tungsten_GetAIBehaviorCoverActions(cover, actions);
    idCoverCapabilities availableCapabilities;
    availableCapabilities.Promote(actions);

    const idWeapon* const weapon = Tungsten_GetAIBehaviorEquippedWeapon(*ai);
    const posture_t posture = Tungsten_GetAIBehaviorCoverPosture(cover);
    idCoverCapabilities forwardCapabilities;
    GetWeaponCoverCapabilities(weapon, posture,
        COVERORIENT_FORWARD, forwardCapabilities);
    idCoverCapabilities backwardCapabilities;
    GetWeaponCoverCapabilities(weapon, posture,
        COVERORIENT_BACKWARD, backwardCapabilities);

    const int forwardMatches = availableCapabilities.NumMatchingCapabilities(
        forwardCapabilities);
    const int backwardMatches = availableCapabilities.NumMatchingCapabilities(
        backwardCapabilities);
    return forwardMatches > backwardMatches
        ? COVERORIENT_FORWARD : COVERORIENT_BACKWARD;
}
