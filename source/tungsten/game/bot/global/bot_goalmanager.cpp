#include "bot_goalmanager.h"

#include <cfloat>

namespace {
idBotGoalManagerServices* g_goalManagerServices = nullptr;

void SetFollowGoal(idBotGoal& goal, const idEntity* const player) {
    goal.GoalManager_InitEntityGoal(4, player, 128.0f, 768.0f, true);
}

void SetRoamGoal(idBotGoal& goal, const idEntity& target) {
    goal.GoalManager_InitPosGoal(128,
        g_goalManagerServices->GetEntityOrigin(target),
        256.0f, 2048.0f, false);
}

idEntity* FindDeathmatchTarget(idEntity& bot, bool& abortThink) {
    abortThink = false;
    std::vector<idEntity*> players;
    g_goalManagerServices->GetPlayerEntities(players);
    for (idEntity* const player : players) {
        if (player != nullptr && player != &bot &&
                !g_goalManagerServices->IsDead(*player) &&
                !g_goalManagerServices->IsNoTarget(*player) &&
                !g_goalManagerServices->IsExcludedTarget(*player)) {
            return player;
        }
    }

    std::vector<idEntity*> activeAI;
    g_goalManagerServices->GetActiveAI(activeAI);
    for (idEntity* const ai : activeAI) {
        if (ai != nullptr && !g_goalManagerServices->IsDead(*ai)) return ai;
    }
    // Retail exits the entire DM manager update when its final active-AI
    // fallback is empty or contains no living entry.
    abortThink = true;
    return nullptr;
}
} // namespace

void Tungsten_SetBotGoalManagerServices(
        idBotGoalManagerServices* const services) {
    g_goalManagerServices = services;
    Tungsten_SetBotGoalServices(services);
}

// Retail symbol: ??0idBotGoalManager_DM@@QAA@XZ
// EA: 0x82B492D8, RVA: 0x00B492D8
idBotGoalManager_DM::idBotGoalManager_DM() = default;

// Retail symbol: ??0idBotGoalManager_TDM@@QAA@XZ
// EA: 0x82B49318, RVA: 0x00B49318
idBotGoalManager_TDM::idBotGoalManager_TDM() = default;

// Retail symbol: ??0idBotGoalManager_CTF@@QAA@XZ
// EA: 0x82B49358, RVA: 0x00B49358
idBotGoalManager_CTF::idBotGoalManager_CTF() = default;

// Retail symbol: ??0idBotGoalManager_HORDE@@QAA@XZ
// EA: 0x82B49398, RVA: 0x00B49398
idBotGoalManager_HORDE::idBotGoalManager_HORDE() = default;

// Retail symbol: ??0idBotGoalManager_DOM@@QAA@XZ
// EA: 0x82B493D8, RVA: 0x00B493D8
idBotGoalManager_DOM::idBotGoalManager_DOM() = default;

// Retail symbol: ?Think@idBotGoalManager_DM@@UAAXH@Z
// EA: 0x82B49480, RVA: 0x00B49480
void idBotGoalManager_DM::Think(const int) {
    if (g_goalManagerServices == nullptr) return;
    std::vector<idEntity*> bots;
    g_goalManagerServices->GetBotEntities(bots);
    for (idEntity* const bot : bots) {
        if (bot == nullptr) continue;
        idBotGoal* const goal = g_goalManagerServices->GetBotGoal(*bot);
        if (goal == nullptr) continue;
        idEntity* const debugPlayer =
            g_goalManagerServices->GetDebugPlayer();
        if (g_goalManagerServices->GetFollowPlayerSetting() &&
                debugPlayer != nullptr) {
            SetFollowGoal(*goal, debugPlayer);
            continue;
        }

        const idEntity* target = g_goalManagerServices->ResolveEntitySpawnId(
            goal->goalEnemy.GetSpawnId());
        bool abortThink = false;
        if (target == nullptr) {
            target = FindDeathmatchTarget(*bot, abortThink);
        }
        if (abortThink) return;
        if (target != nullptr) SetRoamGoal(*goal, *target);
    }
}

// Retail symbol: ?Think@idBotGoalManager_TDM@@UAAXH@Z
// EA: 0x82B497E8, RVA: 0x00B497E8
void idBotGoalManager_TDM::Think(const int currentTime) {
    if (g_goalManagerServices == nullptr) return;
    std::vector<idEntity*> bots;
    g_goalManagerServices->GetBotEntities(bots);

    idEntity* const debugPlayer = g_goalManagerServices->GetDebugPlayer();
    bool canAssignFollower = debugPlayer != nullptr &&
        !g_goalManagerServices->IsDead(*debugPlayer) &&
        !g_goalManagerServices->IsNoclip(*debugPlayer);
    if (canAssignFollower) {
        for (idEntity* const bot : bots) {
            if (bot == nullptr ||
                    g_goalManagerServices->IsHostile(*debugPlayer, *bot)) {
                continue;
            }
            const idBotGoal* const goal =
                g_goalManagerServices->GetBotGoal(*bot);
            if (goal != nullptr && (goal->goalType.flags & 4U) != 0U) {
                canAssignFollower = false;
                break;
            }
        }
    }

    if (canAssignFollower) {
        idEntity* closestBot = nullptr;
        float closestDistanceSqr = FLT_MAX;
        const idVec3 debugOrigin =
            g_goalManagerServices->GetEntityOrigin(*debugPlayer);
        for (idEntity* const bot : bots) {
            if (bot == nullptr || g_goalManagerServices->IsDead(*bot) ||
                    g_goalManagerServices->IsHostile(*debugPlayer, *bot) ||
                    !g_goalManagerServices->CanFollowDebugPlayer(
                        *bot, currentTime)) {
                continue;
            }
            const float distanceSqr =
                (g_goalManagerServices->GetEntityOrigin(*bot) - debugOrigin)
                    .LengthSqr();
            if (distanceSqr < closestDistanceSqr) {
                closestDistanceSqr = distanceSqr;
                closestBot = bot;
            }
        }
        if (closestBot != nullptr) {
            idBotGoal* const goal =
                g_goalManagerServices->GetBotGoal(*closestBot);
            if (goal != nullptr) SetFollowGoal(*goal, debugPlayer);
        }
    }

    for (idEntity* const bot : bots) {
        if (bot == nullptr) continue;
        idBotGoal* const goal = g_goalManagerServices->GetBotGoal(*bot);
        if (goal == nullptr) continue;
        if (g_goalManagerServices->GetFollowPlayerSetting() &&
                debugPlayer != nullptr) {
            SetFollowGoal(*goal, debugPlayer);
            continue;
        }
        if (goal->goalType.flags != 0x80000000U) continue;

        const idEntity* target = g_goalManagerServices->ResolveEntitySpawnId(
            goal->goalEnemy.GetSpawnId());
        if (target == nullptr) {
            std::vector<idEntity*> candidates;
            std::vector<idEntity*> players;
            g_goalManagerServices->GetPlayerEntities(players);
            for (idEntity* const player : players) {
                if (player == nullptr || player == bot ||
                        g_goalManagerServices->IsDead(*player) ||
                        g_goalManagerServices->IsNoTarget(*player) ||
                        g_goalManagerServices->IsExcludedTarget(*player)) {
                    continue;
                }
                if (g_goalManagerServices->IsHostile(*player, *bot) ||
                        g_goalManagerServices->RandomInt(100) <= 10) {
                    bool duplicate = false;
                    for (idEntity* const candidate : candidates) {
                        if (candidate == player) duplicate = true;
                    }
                    if (!duplicate) candidates.push_back(player);
                }
            }
            if (!candidates.empty()) {
                target = candidates[static_cast<std::size_t>(
                    g_goalManagerServices->RandomInt(
                        static_cast<int>(candidates.size())))];
            }
        }
        if (target != nullptr) SetRoamGoal(*goal, *target);
    }
}
