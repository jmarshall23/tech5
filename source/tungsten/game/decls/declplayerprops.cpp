#include "game/decls/declplayerprops.h"

idDeclInfoTemplate<idDeclPlayerProps> idDeclPlayerProps::resourceList(
    "playerProps", "idDeclPlayerProps", "tdef");

// EA 0x82BCA978
idDeclPlayerProps::playerSounds_t::playerSounds_t()
    : sndAlmostDead(nullptr)
    , sndBreatheHeavy(nullptr)
    , sndBreatheMedium(nullptr)
    , sndBreatheSprinting(nullptr)
    , sndCantUseItem(nullptr)
    , sndJobAccepted(nullptr)
    , sndJobCompleted(nullptr)
    , sndJobReadyToTurnIn(nullptr)
    , sndJobUpdated(nullptr)
    , sndOutOfItems(nullptr)
    , sndPickup(nullptr)
    , sndPossess(nullptr)
    , sndPossessLoop(nullptr)
    , sndUseBandage(nullptr)
    , sndBurn(nullptr)
    , sndButtonBad(nullptr)
    , sndButtonDown(nullptr)
    , sndButtonUp(nullptr)
    , sndCantDropItem(nullptr)
    , sndCantLootEntity(nullptr)
    , sndClickDown(nullptr)
    , sndClickUp(nullptr)
    , sndDeath(nullptr)
    , sndDisassemble(nullptr)
    , sndEnterWater(nullptr)
    , sndExitWater(nullptr)
    , sndJobFailed(nullptr)
    , sndJump(nullptr)
    , sndCrouch(nullptr)
    , sndStandUp(nullptr)
    , sndLandHard(nullptr)
    , sndLootEntity(nullptr)
    , sndSkipCinematic(nullptr)
    , sndSpecialEventJump(nullptr)
    , sndSpecialEventNewArea(nullptr)
    , sndStepladder(nullptr)
    , sndPainSmall(nullptr)
    , sndPainMedium(nullptr)
    , sndPainLarge(nullptr)
    , sndHeartBeatLub(nullptr)
    , sndHeartBeatDub(nullptr)
    , sndThrownLandingWater(nullptr)
    , sndThrownLanding(nullptr)
    , sndThrown(nullptr)
    , sndCancelRevive(nullptr)
    , sndFinishRevive(nullptr)
    , sndMPDmgDealtFeedback(nullptr)
    , sndMPDmgDealtFeedbackVeh(nullptr)
    , sndMPRoverBombSelfDestruct(nullptr)
    , sndEndQuadDamage(nullptr) {
}

// EA 0x82BCAA50
idDeclPlayerProps::idDeclPlayerProps()
    : screenParticles{nullptr, nullptr, nullptr, nullptr}
    , sounds()
    , soundParms{20.0f}
    , pain{0, 0, 20.0f, 50.0f}
    , damageFeedback{0.1f, 0.35f, 0.02f, 0.5f,
        0, 255, 0.75f, 0.2f, 0.1f, 0, 255,
        -45.0f, -15.0f, -14.0f, nullptr}
    , declReachIK(nullptr)
    , reviveItemDecl(nullptr)
    , coopMultiplierBG(nullptr)
    , coopMultiplierIcon(nullptr)
    , reviveDuck(nullptr)
    , collectorCardDeck{nullptr, idStrId(), idStrId(), nullptr,
        idStrId(), idStrId(), nullptr}
    , tutorialData{nullptr, nullptr, nullptr}
    , dlcItemInfo() {
}
