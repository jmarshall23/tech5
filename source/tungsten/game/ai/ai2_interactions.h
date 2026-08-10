#pragma once

#include "ai2_debug.h"
#include "idlib/bv/bounds.h"

enum playerInteractionState_t : int {
    PISTATE_INACTIVE = 0,
    PISTATE_APPROACH_PLAYED = 1,
    PISTATE_JOB_SETUP_PLAYED = 2,
    PISTATE_JOB_END_PLAYED = 3,
    PISTATE_JOB_IN_PROGRESS = 4
};

struct idIdleTrackFriendlyRuntime {
    float maximumDistance;
    bool playerMustLeave;
    bool playerHasLeft;
    bool hasWorldState;
    bool targetVisible;
    idVec3 targetAimPoint;
    idVec3 aiEyePoint;
};

struct idPlayerApproachRuntime {
    bool playerInterfaceBlocked;
    bool playerStateBlocked;
    bool actionScriptBlocked;
    bool hasInteractionDeclaration;
    float approachRadius;
    float departureRadius;
    float lookAheadTime;
    idVec3 aiOrigin;
    idVec3 playerOrigin;
    idVec3 playerVelocity;
    idBounds playerBounds;
    bool activationVisibilityEnabled;
    bool hasPlayerWorldState;
    bool playerVisible;
};

float GetBoundsExpansionForDir(
    const idBounds& bounds, const idVec3& direction);

playerInteractionState_t Tungsten_GetAI2TempInteractionState(
    const idAI2& ai);
void Tungsten_SetAI2TempInteractionState(
    idAI2& ai, playerInteractionState_t state);
int Tungsten_GetAI2CurrentInteractionIndex(const idAI2& ai);
void Tungsten_SetAI2CurrentInteractionIndex(idAI2& ai, int index);
const aiPlayerInteraction_t* Tungsten_GetAI2Interaction(
    const idAI2& ai, int index);
int Tungsten_GetAI2InteractionIndex(const idAI2& ai,
    const aiPlayerInteraction_t& interaction);
bool Tungsten_GetIdleTrackFriendlyRuntime(const idAI2& ai,
    const idEntity& target, idIdleTrackFriendlyRuntime& runtime);
bool Tungsten_GetPlayerApproachRuntime(const idAI2& ai,
    const idPlayer& player, idPlayerApproachRuntime& runtime);
bool Tungsten_AI2InteractionHasExpired(const idAI2& ai,
    const aiPlayerInteraction_t& interaction, const idPlayer& player);
void Tungsten_AI2PlayerInteractionDone(
    idAI2& ai, bool playerLeft);
const aiPlayerInteraction_t* Tungsten_FindAI2PlayerInteraction(
    idAI2& ai, idPlayer& player, bool modifyState);
bool Tungsten_AI2InteractionActivatesWhenVisible(
    const aiPlayerInteraction_t& interaction);
void Tungsten_SetAI2InteractionEntity(
    idAI2& ai, const idPlayer& player);
