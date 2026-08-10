#pragma once

#include "declonlinevocallout.h"

class idDeclOnlineCoopScoring : public idDeclTypeInfo {
public:
    struct cooptScoring_Event_t {
        float assistPct;
        int enemyKill;
        int enemyHeadhshotKill;
        int enemySpecialKill;
        int heavyKill;
        int heavyHeadhshotKill;
        int heavySpecialKill;
        int doubleKill;
        int tripleKill;
        int quadKill;
        int killingSpree;
        int collectiableBonus;
    };

    struct coopScoring_Multiplier_t {
        struct damageMultiplierTable_t {
            float multiplier;
            int numTimesHit;
        };

        coopScoring_Multiplier_t();

        float normalDamageMultiplierPointsFactor;
        float headshotDamageMultiplierPointsFactor;
        float takenNormalDamageScale;
        float takenMeleeDamageScale;
        float takenProjectileDamageScale;
        float takenDamageMultiplierScale;
        int assistPoints;
        int revengePoints;
        int comboPoints;
        int defendPoints;
        int covertPoints;
        int brutalPoints;
        int incapacitatePoints;
        int incapacitatePointsPerSecond;
        float revivePCTPoints;
        int idlePointsPerSecond;
        float idlePointsStartupTime;
        idList<damageMultiplierTable_t, 5> takenDamageTable;
        int takenDamageResetTime;
    };

    idDeclOnlineCoopScoring();
    ~idDeclOnlineCoopScoring() override;

    // Retail symbol: ?GetDeclInfo@idDeclOnlineCoopScoring@@UBAPAVidDeclInfo@@XZ
    // EA: 0x82BC9728, RVA: 0x00BC9728
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    static void LoadAllDecls();

    cooptScoring_Event_t events;
    coopScoring_Multiplier_t multiplier;
    int multiplierPointsPerLevel;
    int multiplierPointsLevelBuffer;
    int maxMultiplierPoints;
    const idDeclOnlineScoringCallout* multiplierUpCallout;
    const idDeclOnlineScoringCallout* multiplierDownCallout;
    const idDeclOnlineScoringCallout* headshotCallout;
    const idDeclOnlineScoringCallout* defendCallout;
    const idDeclOnlineScoringCallout* assistCallout;
    const idDeclOnlineScoringCallout* revengeCallout;
    const idDeclOnlineScoringCallout* comboCallout;
    const idDeclOnlineScoringCallout* brutalCallout;
    const idDeclOnlineScoringCallout* covertCallout;
    const idDeclOnlineScoringCallout* doubleKillCallout;
    const idDeclOnlineScoringCallout* tripleKillCallout;
    const idDeclOnlineScoringCallout* quadKillCallout;
    const idDeclOnlineScoringCallout* killingSpreeCallout;
    const idDeclOnlineScoringCallout* collectableCallout;

    static idDeclInfoTemplate<idDeclOnlineCoopScoring> resourceList;
};

static_assert(sizeof(idDeclOnlineCoopScoring::cooptScoring_Event_t) == 48,
    "Recovered co-op event-score layout changed");
static_assert(sizeof(idDeclOnlineCoopScoring::coopScoring_Multiplier_t::damageMultiplierTable_t) == 8,
    "Recovered co-op damage-multiplier row layout changed");

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclOnlineCoopScoring::coopScoring_Multiplier_t) == 88,
    "Recovered co-op multiplier ABI changed");
static_assert(sizeof(idDeclOnlineCoopScoring) == 268,
    "Recovered online co-op scoring ABI changed");
#endif
