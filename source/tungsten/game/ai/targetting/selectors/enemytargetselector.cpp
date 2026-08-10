#include "enemytargetselector.h"

#include <algorithm>

// Retail symbol:
// ?GetWeight@idEnemyTargetSelector@@UBAMPBVidEntity@@ABVidTargetInfo@@@Z
// EA: 0x82B02350, RVA: 0x00B02350
float idEnemyTargetSelector::GetWeight(const idEntity* const owner,
        const idTargetInfo* const target) const {
    if (target->es == nullptr) {
        return 0.0f;
    }

    idEnemyTargetSelectorRuntime runtime;
    Tungsten_GetEnemyTargetSelectorRuntime(*owner, *target->es, runtime);

    // Combat AI checks the live entity's death state. All other owners use
    // the cached AI-world-state death flag.
    if (runtime.ownerIsAI && runtime.ownerInCombat) {
        if (runtime.targetEntityExists && runtime.targetEntityDead) {
            return 0.0f;
        }
    } else if (runtime.targetStateDead) {
        return 0.0f;
    }

    idEnemyTargetSelectorComponents components;
    components.current = runtime.ownerIsAI && runtime.targetIsCurrentEnemy
        ? 1.0f : 0.0f;

    if (runtime.targetIsActor) {
        if (runtime.targetIsPlayer) {
            components.player = 1.0f;
            if (runtime.ownerIsAI && runtime.settings.playerWeight < 0.0f) {
                return 0.0f;
            }
        } else if (runtime.targetIsAI) {
            components.ai = 1.0f;
            if (runtime.ownerIsAI && runtime.settings.aiWeight < 0.0f) {
                return 0.0f;
            }
        }

        if (runtime.targetIsVehicleOrRobot) {
            components.vehicle = 1.0f;
            if (runtime.ownerIsAI
                    && runtime.settings.vehicleWeight < 0.0f) {
                return 0.0f;
            }
        }
    }

    if (runtime.ownerIsAI) {
        if (runtime.ownerHasFakeEnemy) {
            if (runtime.targetIsOwnerFakeEnemy
                    && runtime.ownerFakeEnemyVisible) {
                components.player = 0.0f;
                components.ai = 0.0f;
                components.fake = runtime.ownerFakeEnemyWeight;
                if (runtime.settings.fakeWeight < 0.0f) {
                    return 0.0f;
                }
            }
        } else if (runtime.targetIsFakeEnemyEntity) {
            return 0.0f;
        }

        components.group = runtime.targetIsEncounterGroupEnemy ? 1.0f : 0.0f;
        if (target->distTo > runtime.settings.rangeMax) {
            return 0.0f;
        }
        components.range = 1.0f - target->distTo / runtime.settings.rangeMax;
        components.damager = runtime.targetRecentlyDamagedOwner ? 1.0f : 0.0f;
        if (runtime.targetIsMemoryOriginator) {
            components.aggro = runtime.scriptedAggro;
        }
    }

    if (runtime.targetVisible) {
        components.spotted = 1.0f;
    } else if (runtime.hasConfirmedStimulus) {
        const int recentLimit = runtime.ownerIsAI
            ? static_cast<int>(runtime.settings.spottedMax * 1000.0f)
            : 5000;
        if (runtime.millisecondsSinceConfirmedStimulus < recentLimit) {
            components.spotted = 1.0f;
        } else if (runtime.currentAwareness == 0) {
            components.spotted = 0.1f;
        }
    } else if (runtime.currentAwareness == 0) {
        components.spotted = 0.1f;
    }

    if (target->attitude >= 3) {
        return 0.0f;
    }
    components.angle = (std::max)(ownerDir.Dot(target->dirTo), 0.0f);
    components.relationship = static_cast<float>(3 - target->attitude)
        * (1.0f / 3.0f);

    float weight;
    if (runtime.ownerIsAI) {
        const idEnemyTargetSelectorSettings& settings = runtime.settings;
        weight = settings.rangeWeight * components.range
            + settings.angleWeight * components.angle
            + settings.relationWeight * components.relationship
            + settings.groupWeight * components.group
            + settings.currentWeight * components.current
            + settings.damagerWeight * components.damager
            + settings.spottedWeight * components.spotted
            + settings.fakeWeight * components.fake
            + settings.vehicleWeight * components.vehicle
            + settings.playerWeight * components.player
            + settings.aiWeight * components.ai
            + settings.aggroWeight * components.aggro;
    } else {
        weight = components.range + components.angle
            + components.relationship + components.group
            + components.current + components.damager
            + components.spotted + components.fake
            + components.vehicle + components.player
            + components.ai + components.aggro;
    }

    if (weight > 0.0f && Tungsten_DebugEnemyTargetSelectorEnabled()) {
        Tungsten_DebugEnemyTargetSelectorWeight(
            *owner, *target, runtime, components, weight);
    }
    return weight;
}
