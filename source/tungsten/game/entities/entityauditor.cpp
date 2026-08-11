#include "game/entities/entityauditor.h"

#include <algorithm>
#include <cmath>

namespace {
idEntityAuditorServices defaultAuditorServices;
idEntityAuditorServices* auditorServices = &defaultAuditorServices;

float LengthSqr(const idVec3& vector) {
    return vector.x * vector.x + vector.y * vector.y
        + vector.z * vector.z;
}

float Length(const idVec3& vector) {
    return std::sqrt(LengthSqr(vector));
}

idVec3 Normalize(const idVec3& vector) {
    const float length = Length(vector);
    return length > 1.0e-6f ? vector * (1.0f / length) : idVec3();
}

float WeightedGrenadeDistanceSqr(const idVec3& left,
        const idVec3& right) {
    const idVec3 delta = left - right;
    return delta.x * delta.x + delta.y * delta.y
        + 4.0f * delta.z * delta.z;
}
} // namespace

bool idEntityAuditorServices::HasWorld() const { return true; }
bool idEntityAuditorServices::IsTownMap() const { return false; }
bool idEntityAuditorServices::IsPlayer(const idEntity&) const { return true; }
idVec3 idEntityAuditorServices::GetOrigin(const idEntity& entity) const {
    return entity.origin;
}
idVec3 idEntityAuditorServices::GetViewDirection(
        const idEntity& subject) const {
    return subject.axis[0];
}
int idEntityAuditorServices::FindNearCoverIndex(const idEntity&) const {
    return -1;
}
bool idEntityAuditorServices::IsFiring(const idEntity&) const {
    return false;
}
int idEntityAuditorServices::GetGameMilliseconds() const {
    return idEntity::Services().GetGameMilliseconds();
}
float idEntityAuditorServices::GetWalkSpeed() const { return 160.0f; }
int idEntityAuditorServices::RandomPercent() { return 50; }
void idEntityAuditorServices::GetLivingMembers(const idEncounterGroup&,
        std::vector<idAuditMemberSnapshot>& members) const {
    members.clear();
}
const idAuditCombatStageSnapshot*
idEntityAuditorServices::GetCurrentCombatStage(
        const idEncounterGroup&) const {
    return nullptr;
}
int idEntityAuditorServices::GetNextGrenadeTime(
        const idEncounterGroup&) const {
    return -1;
}
void idEntityAuditorServices::SetWantTauntRageTime(const idEntity&,
        int, const char*) {
}

// Retail: 0x82C46FB0 ??1idPlayerAuditor@@UAA@XZ
idPlayerAuditor::~idPlayerAuditor() = default;

// Retail: 0x82C46FC0 ?Clear@idPlayerAuditor@@UAAXXZ
void idPlayerAuditor::Clear() {
    positions.num = 0;
    positions.head = 0;
    viewdirs.num = 0;
    viewdirs.head = 0;
    waitTime = -1;
    nearCoverIndex = -1;
    nearCoverTime = -1;
    lastFireTime = -1;
    lastOutsideAssaultHint = -1;
    lastOutsideGrenadeHint = -1;
}

// Retail: 0x82C470A0 ??0idAuditResults@@QAA@XZ
idAuditResults::idAuditResults()
    : movement(AUDITMOVEMENT_UNKNOWN),
      inCover(false),
      timeSinceSensed(-1),
      anyMemberMoved(false),
      shouldGrenade(false),
      assaultPrimitiveBreached(false),
      recentPointSensed() {
}

// Retail: 0x82C470D8 ??0idPlayerAuditor@@QAA@XZ
idPlayerAuditor::idPlayerAuditor()
    : nextSampleTime(-1),
      positions(),
      viewdirs(),
      waitPosition(),
      waitTime(-1),
      nearCoverIndex(-1),
      nearCoverTime(-1),
      lastFireTime(-1),
      lastOutsideGrenadeHint(-1),
      lastOutsideAssaultHint(-1),
      currentGrenadeHint(-1) {
}

void idPlayerAuditor::SetServices(idEntityAuditorServices* services) {
    auditorServices = services != nullptr ? services : &defaultAuditorServices;
}

idEntityAuditorServices& idPlayerAuditor::Services() {
    return *auditorServices;
}

// Retail: 0x82C47178 ?CollectData@idPlayerAuditor@@UAAXPBVidEntity@@H@Z
void idPlayerAuditor::CollectData(const idEntity* subject,
        const int curTime) {
    idEntityAuditorServices& services = Services();
    if (subject == nullptr || !services.HasWorld()
            || nextSampleTime > curTime) {
        return;
    }

    nextSampleTime = curTime + 500;
    if (services.IsTownMap() || !services.IsPlayer(*subject)) {
        return;
    }

    const idVec3 origin = services.GetOrigin(*subject);
    positions.Add(origin);
    viewdirs.Add(services.GetViewDirection(*subject));

    if (waitTime < 0 || Length(origin - waitPosition) > 256.0f) {
        waitPosition = origin;
        waitTime = curTime;
    }

    const int coverIndex = services.FindNearCoverIndex(*subject);
    if (coverIndex < 0) {
        nearCoverIndex = -1;
        nearCoverTime = -1;
    } else if (coverIndex != nearCoverIndex) {
        nearCoverIndex = coverIndex;
        nearCoverTime = curTime;
    }

    if (services.IsFiring(*subject)) {
        lastFireTime = curTime;
    }
}

// Retail: 0x82C47688 ?Audit@idPlayerAuditor@@UAAXPAVidEncounterGroup@@PBVidEntity@@HAAVidAuditResults@@@Z
void idPlayerAuditor::Audit(idEncounterGroup* group,
        const idEntity* subject, const int curTime,
        idAuditResults* results) {
    if (results == nullptr) {
        return;
    }

    nextSampleTime = curTime + 450;
    *results = idAuditResults();
    if (group == nullptr || subject == nullptr) {
        return;
    }

    idEntityAuditorServices& services = Services();
    std::vector<idAuditMemberSnapshot> members;
    services.GetLivingMembers(*group, members);

    int latestSenseTime = -1;
    bool hasConfirmedSense = false;
    for (const idAuditMemberSnapshot& member : members) {
        if (!member.hasConfirmedSense || member.lastConfirmedStimTime < 0
                || member.lastConfirmedStimTime <= latestSenseTime) {
            continue;
        }
        latestSenseTime = member.lastConfirmedStimTime;
        hasConfirmedSense = true;
        results->recentPointSensed = member.confirmedPhysicalOrigin;
        if (LengthSqr(member.sensedAIOrigin - member.origin)
                > 128.0f * 128.0f) {
            results->anyMemberMoved = true;
        }
    }

    results->timeSinceSensed = latestSenseTime > 0
        ? services.GetGameMilliseconds() - latestSenseTime : 0;
    results->inCover = nearCoverIndex >= 0 && nearCoverTime >= 0
        && curTime - nearCoverTime > 3000;
    if (waitTime > 0 && curTime - waitTime > 7500) {
        results->movement = idAuditResults::AUDITMOVEMENT_WAITING;
    }

    if (!results->inCover
            && results->movement == idAuditResults::AUDITMOVEMENT_UNKNOWN) {
        std::vector<idVec3> directions;
        float totalDistance = 0.0f;
        for (int sample = 1; sample < positions.num; ++sample) {
            const idVec3 delta =
                positions.buffer[(positions.head + sample) % 5]
                - positions.buffer[(positions.head + sample - 1) % 5];
            const float distance = Length(delta);
            if (distance <= 1.0e-6f) {
                continue;
            }
            directions.push_back(delta * (1.0f / distance));
            totalDistance += distance;
        }

        const float averageDistance = directions.empty() ? 0.0f
            : totalDistance / static_cast<float>(directions.size());
        int membersApproached = 0;
        int membersRetreatedFrom = 0;
        for (const idAuditMemberSnapshot& member : members) {
            int approachSamples = 0;
            int retreatSamples = 0;
            for (std::size_t sample = 0; sample < directions.size();
                    ++sample) {
                const idVec3& sampleOrigin =
                    positions.buffer[(positions.head
                        + static_cast<int>(sample)) % 5];
                const idVec3 memberDirection = Normalize(
                    member.origin - sampleOrigin);
                const float dot = directions[sample].Dot(memberDirection);
                if (dot > 0.70710677f) {
                    ++approachSamples;
                } else if (dot < -0.70710677f) {
                    ++retreatSamples;
                }
            }

            if (approachSamples >= 4) {
                ++membersApproached;
            } else if (retreatSamples >= 4) {
                ++membersRetreatedFrom;
                if (member.entity != nullptr
                        && services.RandomPercent()
                            < member.tauntRageFleeingEnemyChance) {
                    services.SetWantTauntRageTime(*member.entity,
                        services.GetGameMilliseconds(), "enemy fleeing");
                }
            }
        }

        const float walkSpeed = services.GetWalkSpeed();
        const float memberMajority =
            static_cast<float>(members.size()) * 0.5f;
        if (averageDistance > walkSpeed * 0.75f * 0.5f) {
            if (static_cast<float>(membersApproached) > memberMajority) {
                results->movement = averageDistance <= walkSpeed * 0.75f
                    ? idAuditResults::AUDITMOVEMENT_ADVANCING
                    : idAuditResults::AUDITMOVEMENT_CHARGING;
            } else if (static_cast<float>(membersRetreatedFrom)
                        > memberMajority
                    && membersApproached == 0) {
                results->movement = averageDistance <= walkSpeed * 0.75f
                    ? idAuditResults::AUDITMOVEMENT_FALLINGBACK
                    : idAuditResults::AUDITMOVEMENT_RETREATING;
            }
        }
    }

    const idAuditCombatStageSnapshot* stage =
        services.GetCurrentCombatStage(*group);
    const idAuditHintSnapshot* assaultHint = nullptr;
    const idAuditHintSnapshot* grenadeHint = nullptr;
    int grenadeHintIndex = -1;

    if (stage != nullptr && hasConfirmedSense) {
        for (const idAuditHintSnapshot& hint : stage->assaultHints) {
            if (hint.entityWeight > 0.0f) {
                assaultHint = &hint;
                break;
            }
        }
        for (std::size_t index = 0; index < stage->grenadeHints.size();
                ++index) {
            const idAuditHintSnapshot& hint = stage->grenadeHints[index];
            if (hint.pointWeight > 0.0f) {
                grenadeHint = &hint;
                grenadeHintIndex = static_cast<int>(index);
                break;
            }
        }
    }

    if (grenadeHint == nullptr) {
        currentGrenadeHint = -1;
        lastOutsideGrenadeHint = curTime;
    } else {
        if (currentGrenadeHint != grenadeHintIndex) {
            lastOutsideGrenadeHint = curTime;
        }
        currentGrenadeHint = grenadeHintIndex;

        if (lastOutsideGrenadeHint != -1
                && curTime - lastOutsideGrenadeHint > grenadeHint->delay
                && services.GetNextGrenadeTime(*group)
                    < services.GetGameMilliseconds()) {
            bool memberTooClose = false;
            for (const idAuditMemberSnapshot& member : members) {
                if (WeightedGrenadeDistanceSqr(member.origin,
                        grenadeHint->origin) < 256.0f * 256.0f) {
                    memberTooClose = true;
                    break;
                }
            }
            if (!memberTooClose) {
                results->shouldGrenade = true;
                lastOutsideGrenadeHint = curTime;
            }
        }
    }

    if (assaultHint != nullptr) {
        if (curTime - lastOutsideAssaultHint > assaultHint->delay
                && stage != nullptr) {
            for (const bool breached : stage->assaultBreachRules) {
                if (breached) {
                    results->assaultPrimitiveBreached = true;
                }
            }
        }
    } else {
        lastOutsideAssaultHint = curTime;
    }
}
