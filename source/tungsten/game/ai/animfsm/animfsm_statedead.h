#pragma once

#include "animfsm_state_core.h"

class idAI2;
class idAnimBaseFSM;

class idAnimStateDead : public idAIStateLite {
public:
    idAnimStateDead();
    virtual ~idAnimStateDead() = default;

    virtual void Enter(idAI2* ai, idAnimBaseFSM* fsm);
};
