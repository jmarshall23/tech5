#pragma once

#include "decljob.h"
#include "decls/decltypeinfo.h"
#include "idlib/containers/list.h"
#include "idlib/langdict.h"

class idDeclDuck;
class idDeclInventory;
class idDeclParticle;
class idDeclReachIK;
class idDeclTable;
class idDeclTutorialEvent;
class idMaterial;
class idSoundShader;

struct idDLCRewardInfo {
    enum dlcRewardJobStatus_t : int {
        DLCREWARDJOBSTATUS_ACCEPTED = 0,
        DLCREWARDJOBSTATUS_READYTOTURNIN = 1,
        DLCREWARDJOBSTATUS_COMPLETED = 2
    };

    gameDLCState_t dlcState;
    idStr dlcTrackingString;
    idDeclJobRef dlcJobRequired;
    dlcRewardJobStatus_t dlcJobMinStatus;
    bool dlcMarkGivenEvenIfJobTestFailed;
    bool dlcVehicle;
    idList<idDeclInventory*, 5> dlcGiveItems;
};

class idDeclPlayerProps : public idDeclTypeInfo {
public:
    struct screenParticle_t {
        const idDeclParticle* waterDroplets;
        const idDeclParticle* waterDripsSmall;
        const idDeclParticle* waterDripsMedium;
        const idDeclParticle* waterDripsLarge;
    };

    struct playerSounds_t {
        playerSounds_t();

        const idSoundShader* sndAlmostDead;
        const idSoundShader* sndBreatheHeavy;
        const idSoundShader* sndBreatheMedium;
        const idSoundShader* sndBreatheSprinting;
        const idSoundShader* sndCantUseItem;
        const idSoundShader* sndJobAccepted;
        const idSoundShader* sndJobCompleted;
        const idSoundShader* sndJobReadyToTurnIn;
        const idSoundShader* sndJobUpdated;
        const idSoundShader* sndOutOfItems;
        const idSoundShader* sndPickup;
        const idSoundShader* sndPossess;
        const idSoundShader* sndPossessLoop;
        const idSoundShader* sndUseBandage;
        const idSoundShader* sndBurn;
        const idSoundShader* sndButtonBad;
        const idSoundShader* sndButtonDown;
        const idSoundShader* sndButtonUp;
        const idSoundShader* sndCantDropItem;
        const idSoundShader* sndCantLootEntity;
        const idSoundShader* sndClickDown;
        const idSoundShader* sndClickUp;
        const idSoundShader* sndDeath;
        const idSoundShader* sndDisassemble;
        const idSoundShader* sndEnterWater;
        const idSoundShader* sndExitWater;
        const idSoundShader* sndJobFailed;
        const idSoundShader* sndJump;
        const idSoundShader* sndCrouch;
        const idSoundShader* sndStandUp;
        const idSoundShader* sndLandHard;
        const idSoundShader* sndLootEntity;
        const idSoundShader* sndSkipCinematic;
        const idSoundShader* sndSpecialEventJump;
        const idSoundShader* sndSpecialEventNewArea;
        const idSoundShader* sndStepladder;
        const idSoundShader* sndPainSmall;
        const idSoundShader* sndPainMedium;
        const idSoundShader* sndPainLarge;
        const idSoundShader* sndHeartBeatLub;
        const idSoundShader* sndHeartBeatDub;
        const idSoundShader* sndThrownLandingWater;
        const idSoundShader* sndThrownLanding;
        const idSoundShader* sndThrown;
        const idSoundShader* sndCancelRevive;
        const idSoundShader* sndFinishRevive;
        const idSoundShader* sndMPDmgDealtFeedback;
        const idSoundShader* sndMPDmgDealtFeedbackVeh;
        const idSoundShader* sndMPRoverBombSelfDestruct;
        const idSoundShader* sndEndQuadDamage;
    };

    struct playerSoundsParms_t {
        float lowHealthThreshold;
    };

    struct pain_t {
        int pain_delay;
        int pain_threshold;
        float pain_mediumDamageAmount;
        float pain_heavyDamageAmount;
    };

    struct damageFeedback_t {
        float centerIndicatorOffset;
        float centerIndicatorSize;
        float centerIndicatorDecay;
        float outerIndicatorSize;
        int IndicatorMinAlpha;
        int IndicatorMaxAlpha;
        float spikeIndicatorOffset;
        float spikeIndicatorWidth;
        float spikeIndicatorDecay;
        int spikeIndicatorMinAlpha;
        int spikeIndicatorMaxAlpha;
        float dryGainEnd;
        float roomGainEnd;
        float roomHFGainEnd;
        idDeclTable* worldFadeTable;
    };

    struct collectorCardDeck_t {
        const idDeclInventory* cardDeckRealDecl;
        idStrId earlyDeckName;
        idStrId earlyDeckDesc;
        const idMaterial* earlyDeckTexture;
        idStrId realDeckName;
        idStrId realDeckDesc;
        const idMaterial* realDeckTexture;
    };

    struct tutorialData_t {
        const idDeclTutorialEvent* bandageTutorial;
        const idDeclTutorialEvent* reloadTutorial;
        const idDeclGameStateInt* merchantSellGameStateInt;
    };

    idDeclPlayerProps();
    ~idDeclPlayerProps() override = default;

    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    screenParticle_t screenParticles;
    playerSounds_t sounds;
    playerSoundsParms_t soundParms;
    pain_t pain;
    damageFeedback_t damageFeedback;
    const idDeclReachIK* declReachIK;
    const idDeclInventory* reviveItemDecl;
    const idMaterial* coopMultiplierBG;
    const idMaterial* coopMultiplierIcon;
    const idDeclDuck* reviveDuck;
    collectorCardDeck_t collectorCardDeck;
    tutorialData_t tutorialData;
    idList<idDLCRewardInfo, 5> dlcItemInfo;

    static idDeclInfoTemplate<idDeclPlayerProps> resourceList;
};

static_assert(sizeof(idDLCRewardInfo) == 92,
    "Recovered DLC-reward ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclPlayerProps::playerSounds_t) == 200,
    "Recovered player-sounds ABI changed");
static_assert(sizeof(idDeclPlayerProps) == 436,
    "Recovered player-properties declaration ABI changed");
#endif
