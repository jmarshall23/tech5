#pragma once

#include "animfsm_stateidle.h"
#include "animfsm_statedead.h"

class idGuiListBox;

class idAnimStateMoveGround : public idAIStateLite {};

class idAnimFSM_AAS {
public:
    virtual ~idAnimFSM_AAS() = default;
};

class idAnimFSMHumanoid : public idAnimFSM_AAS {
public:
    idAnimFSMHumanoid();
    ~idAnimFSMHumanoid() override;

    virtual void Reset();
    virtual void PrintDebugInfo(idGuiListBox& information);
    virtual idAIStateLite* GetState(int stateIndex);

    idAnimStateIdleGround stateIdle;
    idAnimStateMoveGround stateMove;
    idAnimStateDead stateDead;
};

void Tungsten_ResetAnimFSMHumanoid(idAnimFSMHumanoid& fsm);
void Tungsten_PrintAnimFSMHumanoidDebug(
    idAnimFSMHumanoid& fsm, idGuiListBox& information);
void Tungsten_InitializeHumanoidAnimState(
    idAnimFSMHumanoid& fsm, int stateIndex, idAIStateLite& state);
void Tungsten_ShutdownHumanoidAnimState(
    idAnimFSMHumanoid& fsm, int stateIndex, idAIStateLite& state);
