#pragma once

#include "game/entities/entity.h"
#include "game/gamesys/circularbuffer.h"

#include <vector>

class idEncounterGroup;

class idAuditResults {
public:
    enum auditMovement_t {
        AUDITMOVEMENT_UNKNOWN = 0,
        AUDITMOVEMENT_RETREATING = 1,
        AUDITMOVEMENT_FALLINGBACK = 2,
        AUDITMOVEMENT_WAITING = 3,
        AUDITMOVEMENT_ADVANCING = 4,
        AUDITMOVEMENT_CHARGING = 5,
        AUDITMOVEMENT_MAX = 6
    };

    idAuditResults();

    auditMovement_t movement;
    bool inCover;
    int timeSinceSensed;
    bool anyMemberMoved;
    bool shouldGrenade;
    bool assaultPrimitiveBreached;
    idVec3 recentPointSensed;
};

struct idAuditMemberSnapshot {
    const idEntity* entity = nullptr;
    idVec3 origin;
    bool hasConfirmedSense = false;
    int lastConfirmedStimTime = -1;
    idVec3 confirmedPhysicalOrigin;
    idVec3 sensedAIOrigin;
    int tauntRageFleeingEnemyChance = 0;
};

struct idAuditHintSnapshot {
    float entityWeight = 0.0f;
    float pointWeight = 0.0f;
    int delay = 0;
    idVec3 origin;
};

struct idAuditCombatStageSnapshot {
    std::vector<idAuditHintSnapshot> assaultHints;
    std::vector<idAuditHintSnapshot> grenadeHints;
    std::vector<bool> assaultBreachRules;
};

class idEntityAuditorServices {
public:
    virtual ~idEntityAuditorServices() = default;

    virtual bool HasWorld() const;
    virtual bool IsTownMap() const;
    virtual bool IsPlayer(const idEntity& subject) const;
    virtual idVec3 GetOrigin(const idEntity& entity) const;
    virtual idVec3 GetViewDirection(const idEntity& subject) const;
    virtual int FindNearCoverIndex(const idEntity& subject) const;
    virtual bool IsFiring(const idEntity& subject) const;
    virtual int GetGameMilliseconds() const;
    virtual float GetWalkSpeed() const;
    virtual int RandomPercent();

    virtual void GetLivingMembers(const idEncounterGroup& group,
        std::vector<idAuditMemberSnapshot>& members) const;
    virtual const idAuditCombatStageSnapshot* GetCurrentCombatStage(
        const idEncounterGroup& group) const;
    virtual int GetNextGrenadeTime(const idEncounterGroup& group) const;
    virtual void SetWantTauntRageTime(const idEntity& member,
        int gameTime, const char* reason);
};

class idEntityAuditor {
public:
    virtual ~idEntityAuditor() = default;
    virtual void CollectData(const idEntity* subject, int curTime) = 0;
    virtual void Audit(idEncounterGroup* group, const idEntity* subject,
        int curTime, idAuditResults* results) = 0;
    virtual void Clear() = 0;
};

class idPlayerAuditor final : public idEntityAuditor {
public:
    idPlayerAuditor();
    ~idPlayerAuditor() override;

    static void SetServices(idEntityAuditorServices* services);
    static idEntityAuditorServices& Services();

    void CollectData(const idEntity* subject, int curTime) override;
    void Audit(idEncounterGroup* group, const idEntity* subject,
        int curTime, idAuditResults* results) override;
    void Clear() override;

    int nextSampleTime;
    idCircularBuffer<idVec3, 5> positions;
    idCircularBuffer<idVec3, 5> viewdirs;
    idVec3 waitPosition;
    int waitTime;
    int nearCoverIndex;
    int nearCoverTime;
    int lastFireTime;
    int lastOutsideGrenadeHint;
    int lastOutsideAssaultHint;
    int currentGrenadeHint;
};
