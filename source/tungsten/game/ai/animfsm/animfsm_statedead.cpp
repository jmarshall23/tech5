#include "animfsm_statedead.h"

#include "aimovecmd.h"

void Tungsten_SetAnimFSMDestination(
    idAnimBaseFSM* fsm, const idAIMoveCmd* command);

// Retail symbol: ?Enter@idAnimStateDead@@UAAXPAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA: 0x82A7F148, RVA: 0x00A7F148
void idAnimStateDead::Enter(idAI2* const ai, idAnimBaseFSM* const fsm) {
    (void)ai;
    Tungsten_SetAnimFSMDestination(fsm, &idAIMoveCmd::s_null);
}

// Retail symbol: ??0idAnimStateDead@@QAA@XZ
// EA: 0x82A7F158, RVA: 0x00A7F158
idAnimStateDead::idAnimStateDead()
    : idAIStateLite() {
}
