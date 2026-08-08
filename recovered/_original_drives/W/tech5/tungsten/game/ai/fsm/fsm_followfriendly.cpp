
// ========================================================================
// ?Evaluate@FOLLOWFRIENDLY_PathBlocked@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD1970
// RVA : 0x00AD1970
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

int __fastcall FOLLOWFRIENDLY_PathBlocked::Evaluate(
        FOLLOWFRIENDLY_PathBlocked *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3

  MoveInterface = idAI2::GetMoveInterface(this: ai);
  return __CFADD__(MoveInterface->GetMoveStatus(this: MoveInterface) - 2, -2147483646) ? 0 : 0x191;
}


// ========================================================================
// ?Evaluate@FOLLOWFRIENDLY_MoveDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD19C0
// RVA : 0x00AD19C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

int __fastcall FOLLOWFRIENDLY_MoveDone::Evaluate(
        FOLLOWFRIENDLY_MoveDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::IsMoveDone(this: ai, checkAlignment: false) ? 0 : 0x191;
}


// ========================================================================
// ?InternalInitState@idFollowFriendly_Default@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD1A00
// RVA : 0x00AD1A00
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendly_Default::InternalInitState(
        idFollowFriendly_Default *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &FOLLOWFRIENDLY_NoTarget::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_ShouldBackAway::Type,
    nextStateType: &idFollowFriendly_BackAway::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_ShouldWait::Type,
    nextStateType: &idFollowFriendly_ReachedTarget::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_ShouldFollow::Type,
    nextStateType: &idFollowFriendly_MoveToTarget::Type);
}


// ========================================================================
// ?InternalInitState@idFollowFriendly_ReachedTarget@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD1AA0
// RVA : 0x00AD1AA0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendly_ReachedTarget::InternalInitState(
        idFollowFriendly_ReachedTarget *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &FOLLOWFRIENDLY_NoTarget::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_ShouldFollow::Type,
    nextStateType: &idFollowFriendly_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_ShouldBackAway::Type,
    nextStateType: &idFollowFriendly_BackAway::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_ShouldChaseProjectile::Type,
    nextStateType: &idFollowFriendly_ChaseProjectile::Type);
}


// ========================================================================
// ?InternalInitState@idFollowFriendly_PathBlocked@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD1B40
// RVA : 0x00AD1B40
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendly_PathBlocked::InternalInitState(
        idFollowFriendly_PathBlocked *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &FOLLOWFRIENDLY_NoTarget::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_PathClear::Type,
    nextStateType: &idFollowFriendly_Default::Type);
}


// ========================================================================
// ?InternalInitState@idFollowFriendly_MoveToTarget@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD1BA8
// RVA : 0x00AD1BA8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendly_MoveToTarget::InternalInitState(
        idFollowFriendly_MoveToTarget *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &FOLLOWFRIENDLY_NoTarget::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_PathBlocked::Type,
    nextStateType: &idFollowFriendly_PathBlocked::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_MoveDone::Type,
    nextStateType: &idFollowFriendly_ReachedTarget::Type);
}


// ========================================================================
// ?AIState_Work@idFollowFriendly_MoveToTarget@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD1C28
// RVA : 0x00AD1C28
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendly_MoveToTarget::AIState_Work(
        idFollowFriendly_MoveToTarget *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3
  int v6; // r3
  walkState_t v7; // r4

  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v6 = MoveInterface->GetLastTravelTime(this: MoveInterface);
  if ( v6 <= 1000 )
  {
    if ( v6 >= 500 )
      return;
    v7 = WALKSTATE_WALKING;
  }
  else
  {
    v7 = WALKSTATE_RUNNING;
  }
  ai->SetWalkState(this: ai, a2: v7);
}


// ========================================================================
// ?InternalInitState@idFollowFriendly_BackAway@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD1C98
// RVA : 0x00AD1C98
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendly_BackAway::InternalInitState(
        idFollowFriendly_BackAway *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &FOLLOWFRIENDLY_NoTarget::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_PathBlocked::Type,
    nextStateType: &idFollowFriendly_PathBlocked::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_MoveDone::Type,
    nextStateType: &idFollowFriendly_BackAwayWait::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_ShouldChaseProjectile::Type,
    nextStateType: &idFollowFriendly_ChaseProjectile::Type);
}


// ========================================================================
// ?InternalInitState@idFollowFriendly_BackAwayWait@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD1D38
// RVA : 0x00AD1D38
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendly_BackAwayWait::InternalInitState(
        idFollowFriendly_BackAwayWait *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &FOLLOWFRIENDLY_NoTarget::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_TargetMovedAway::Type,
    nextStateType: &idFollowFriendly_MoveToTarget::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_ShouldBackAway::Type,
    nextStateType: &idFollowFriendly_BackAway::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_ShouldChaseProjectile::Type,
    nextStateType: &idFollowFriendly_ChaseProjectile::Type);
}


// ========================================================================
// ?InternalInitState@idFollowFriendly_BackAwayBlocked@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD1DD8
// RVA : 0x00AD1DD8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendly_BackAwayBlocked::InternalInitState(
        idFollowFriendly_BackAwayBlocked *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &FOLLOWFRIENDLY_NoTarget::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_TargetMovedAway::Type,
    nextStateType: &idFollowFriendly_MoveToTarget::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_BackAwayClear::Type,
    nextStateType: &idFollowFriendly_BackAway::Type);
}


// ========================================================================
// ?InternalInitState@idFollowFriendly_ChaseProjectile@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD1E58
// RVA : 0x00AD1E58
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendly_ChaseProjectile::InternalInitState(
        idFollowFriendly_ChaseProjectile *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &FOLLOWFRIENDLY_ChaseProjectileDone::Type,
    nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InitStates@idFollowFriendlyFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82AD1E70
// RVA : 0x00AD1E70
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendlyFSM::InitStates(idAvoidFSM *this, const idFiniteStateMachineParams *params)
{
  idAIFSM::InitStates(this, params);
  this->AddState(this, a2: &this->stateDefault);
  this->AddState(this, a2: &this->stateDive);
  this->AddState(this, a2: &this->stateRunAway);
  this->AddState(this, a2: &this->stateMoveToCover);
  this->AddState(this, a2: &this->stateWaitInCover);
  this->AddState(this, a2: &this->stateMoveToGrenade);
  this->AddState(this, a2: &this->stateKickGrenade);
  this->AddState(this, a2: &this->stateCower);
}


// ========================================================================
// ?Evaluate@FOLLOWFRIENDLY_ShouldChaseProjectile@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD1F60
// RVA : 0x00AD1F60
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall FOLLOWFRIENDLY_ShouldChaseProjectile::Evaluate(
        FOLLOWFRIENDLY_ShouldChaseProjectile *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIStateTransition::aiTransCode_t result; // r3
  bool v6; // zf

  if ( !ai->aiEditable.behaviors.decl->chasesProjectiles )
    return 0;
  if ( parentFSM->eventId != 8 )
    return 0;
  v6 = idAIEventProjectedSphere::CastTo(c: (idAIEventProjectedSphere *)parentFSM->eventData) != nullptr;
  result = TRANSCODE_FOLLOW_FRIENDLY_SHOULD_CHASE_PROJECTILE;
  if ( !v6 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idFollowFriendly_BackAwayBlocked@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD1FB0
// RVA : 0x00AD1FB0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendly_BackAwayBlocked::AIState_EnterState(
        idFollowFriendly_BackAwayBlocked *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idEventArg *v7; // r28
  _BYTE v8[20]; // [sp+70h] [-C0h] BYREF
  _DWORD v9[5]; // [sp+90h] [-A0h] BYREF
  int v10; // [sp+B0h] [-80h]
  int v11; // [sp+B4h] [-7Ch]
  idEventArg v12; // [sp+D0h] [-60h] BYREF
  idEventReceiver v13[5]; // [sp+F0h] [-40h] BYREF

  ai->SetWalkState(this: ai, a2: WALKSTATE_WALKING);
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  HIBYTE(v9[0]) = 105;
  v9[1] = 0;
  HIBYTE(v10) = 105;
  v11 = -1;
  v7 = idEventArg::idEventArg(this: &v12, data: ai);
  memcpy(Dst: v8, Src: v9, Size: sizeof(v8));
  idEventReceiver::ProcessEvent(
    this: v13,
    result: fsm,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v10, 32));
}


// ========================================================================
// ??0idFollowFriendlyFSM@@QAA@XZ
// EA  : 0x82AD2078
// RVA : 0x00AD2078
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

idFollowFriendlyFSM *__fastcall idFollowFriendlyFSM::idFollowFriendlyFSM(idFollowFriendlyFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: "FSM_FollowFriendly");
  this->__vftable = (idFollowFriendlyFSM_vtbl *)&idFollowFriendlyFSM::`vftable';
  idState::idState(
    this: &this->stateDefault,
    stateType: &idFollowFriendly_Default::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateDefault.__vftable = (idFollowFriendly_Default_vtbl *)&idFollowFriendly_Default::`vftable';
  idState::idState(
    this: &this->stateReachedTarget,
    stateType: &idFollowFriendly_ReachedTarget::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateReachedTarget.__vftable = (idFollowFriendly_ReachedTarget_vtbl *)&idFollowFriendly_ReachedTarget::`vftable';
  idState::idState(
    this: &this->statePathBlocked,
    stateType: &idFollowFriendly_PathBlocked::Type,
    childFSMType: nullptr,
    flags: 0);
  this->statePathBlocked.__vftable = (idFollowFriendly_PathBlocked_vtbl *)&idFollowFriendly_PathBlocked::`vftable';
  idState::idState(
    this: &this->stateMoveToTarget,
    stateType: &idFollowFriendly_MoveToTarget::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveToTarget.__vftable = (idFollowFriendly_MoveToTarget_vtbl *)&idFollowFriendly_MoveToTarget::`vftable';
  idState::idState(
    this: &this->stateBackAway,
    stateType: &idFollowFriendly_BackAway::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateBackAway.__vftable = (idFollowFriendly_BackAway_vtbl *)&idFollowFriendly_BackAway::`vftable';
  idState::idState(
    this: &this->stateBackAwayWait,
    stateType: &idFollowFriendly_BackAwayWait::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateBackAwayWait.__vftable = (idFollowFriendly_BackAwayWait_vtbl *)&idFollowFriendly_BackAwayWait::`vftable';
  idState::idState(
    this: &this->stateBackAwayBlocked,
    stateType: &idFollowFriendly_BackAwayBlocked::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateBackAwayBlocked.__vftable = (idFollowFriendly_BackAwayBlocked_vtbl *)&idFollowFriendly_BackAwayBlocked::`vftable';
  idState::idState(
    this: &this->stateChaseProjectile,
    stateType: &idFollowFriendly_ChaseProjectile::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateChaseProjectile.__vftable = (idFollowFriendly_ChaseProjectile_vtbl *)&idFollowFriendly_ChaseProjectile::`vftable';
  idFiniteStateMachine::SetDefaultState(this, state: &this->stateDefault);
  return this;
}


// ========================================================================
// __unwind$488788
// EA  : 0x82AD21E8
// RVA : 0x00AD21E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void _unwind_488788()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$488789
// EA  : 0x82AD2210
// RVA : 0x00AD2210
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void _unwind_488789()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$488790
// EA  : 0x82AD223C
// RVA : 0x00AD223C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void _unwind_488790()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$488791
// EA  : 0x82AD2268
// RVA : 0x00AD2268
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void _unwind_488791()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// __unwind$488792
// EA  : 0x82AD2294
// RVA : 0x00AD2294
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void _unwind_488792()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 192));
}


// ========================================================================
// __unwind$488793
// EA  : 0x82AD22C0
// RVA : 0x00AD22C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void _unwind_488793()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 220));
}


// ========================================================================
// __unwind$488794
// EA  : 0x82AD22EC
// RVA : 0x00AD22EC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void _unwind_488794()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 248));
}


// ========================================================================
// __unwind$488795
// EA  : 0x82AD2318
// RVA : 0x00AD2318
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void _unwind_488795()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 276));
}


// ========================================================================
// __unwind$488796
// EA  : 0x82AD2344
// RVA : 0x00AD2344
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void _unwind_488796()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 304));
}


// ========================================================================
// ??1idFollowFriendlyFSM@@UAA@XZ
// EA  : 0x82AD2378
// RVA : 0x00AD2378
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendlyFSM::~idFollowFriendlyFSM(idFollowFriendlyFSM *this)
{
  this->__vftable = (idFollowFriendlyFSM_vtbl *)&idFollowFriendlyFSM::`vftable';
  idState::~idState(this: &this->stateChaseProjectile);
  idState::~idState(this: &this->stateBackAwayBlocked);
  idState::~idState(this: &this->stateBackAwayWait);
  idState::~idState(this: &this->stateBackAway);
  idState::~idState(this: &this->stateMoveToTarget);
  idState::~idState(this: &this->statePathBlocked);
  idState::~idState(this: &this->stateReachedTarget);
  idState::~idState(this: &this->stateDefault);
  idFiniteStateMachine::~idFiniteStateMachine(this);
}


// ========================================================================
// __unwind$488946
// EA  : 0x82AD2404
// RVA : 0x00AD2404
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void _unwind_488946()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488947
// EA  : 0x82AD242C
// RVA : 0x00AD242C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void _unwind_488947()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// __unwind$488948
// EA  : 0x82AD2458
// RVA : 0x00AD2458
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void _unwind_488948()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$488949
// EA  : 0x82AD2484
// RVA : 0x00AD2484
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void _unwind_488949()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// __unwind$488950
// EA  : 0x82AD24B0
// RVA : 0x00AD24B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void _unwind_488950()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 192));
}


// ========================================================================
// __unwind$488951
// EA  : 0x82AD24DC
// RVA : 0x00AD24DC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void _unwind_488951()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 220));
}


// ========================================================================
// __unwind$488952
// EA  : 0x82AD2508
// RVA : 0x00AD2508
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void _unwind_488952()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 248));
}


// ========================================================================
// __unwind$488953
// EA  : 0x82AD2534
// RVA : 0x00AD2534
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void _unwind_488953()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 276));
}


// ========================================================================
// ?FindBackAwayDestination@@YA_NPAVidAI2@@AAVidVec3@@1AAM@Z
// EA  : 0x82AD26A8
// RVA : 0x00AD26A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

BOOL __fastcall FindBackAwayDestination(idAI2 *ai, idVec3 *bestDest, idVec3 *bestDir, float *bestDist)
{
  int value; // r8
  idEntity *v9; // r3
  idEntity *v10; // r30
  idAIEntityState *v11; // r3
  aiSenseState_t *v12; // r30
  idPhysics *Physics; // r3
  int v14; // r3
  float v15; // r11
  float v16; // r4
  float v17; // r10
  float z; // r5
  double v19; // fp1
  const idAAS2 *v20; // r3
  const idAASPosition *AASPosition; // r3
  idAASPosition *v22; // r23
  int v23; // r19
  float *v24; // r26
  int v25; // r22
  double v26; // fp29
  int travelFlags; // r11
  unsigned int v28; // r16
  double x; // fp30
  double y; // fp29
  double v31; // fp28
  idAAS2 *aas; // r15
  idAAS2_vtbl *v33; // r14
  int AreaNum; // r3
  double v35; // fp13
  double v36; // fp12
  double v37; // fp12
  double v38; // fp11
  double v39; // fp5
  double v40; // fp4
  float v42; // [sp+60h] [-1C0h] BYREF
  float v43; // [sp+64h] [-1BCh]
  float v44; // [sp+68h] [-1B8h]
  idRotation v45; // [sp+70h] [-1B0h] BYREF
  float v46; // [sp+B4h] [-16Ch]
  float v47; // [sp+B8h] [-168h]
  float v48; // [sp+BCh] [-164h]
  int v49; // [sp+C0h] [-160h]
  int v50; // [sp+C4h] [-15Ch]
  int v51; // [sp+C8h] [-158h]
  float v52; // [sp+CCh] [-154h]
  float v53; // [sp+D0h] [-150h]
  float v54; // [sp+D4h] [-14Ch]
  int v55; // [sp+D8h] [-148h]
  int v56; // [sp+DCh] [-144h]
  float v57; // [sp+E0h] [-140h]
  float v58; // [sp+E4h] [-13Ch]
  float v59; // [sp+E8h] [-138h]
  int v60; // [sp+ECh] [-134h]
  int v61; // [sp+F0h] [-130h]
  int v62; // [sp+F4h] [-12Ch]
  int v63; // [sp+F8h] [-128h]
  int v64; // [sp+FCh] [-124h]
  int v65; // [sp+100h] [-120h]
  idRotation v66; // [sp+110h] [-110h] BYREF

  value = ai->aiVolatile.memory.currentFriendly.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v10 = idEntity::CastTo(c: v9);
  }
  else
  {
    v10 = nullptr;
  }
  v11 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v10);
  if ( v10 == nullptr || v11 == nullptr )
    return false;
  v12 = v11->senses.ptr[v11->lastSense];
  Physics = idEntity::GetPhysics(this: ai);
  v14 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v15 = *(float *)(v14 + 4);
  v16 = *(float *)v14;
  v17 = *(float *)(v14 + 8);
  v45.angle = 0.0;
  v45.axis.mat[1].x = 0.0;
  v43 = v15;
  v42 = v16;
  v44 = v17;
  v45.origin.y = v12->unConfirmedPhysical.origin.y;
  v45.origin.x = v12->unConfirmedPhysical.origin.x;
  v45.vec.z = v15 - v45.origin.y;
  z = v12->unConfirmedPhysical.origin.z;
  v45.vec.y = v16 - v45.origin.x;
  v45.axis.mat[0].y = v45.vec.y;
  v45.axis.mat[0].z = v45.vec.z;
  v45.origin.z = z;
  v19 = idVec3::NormalizeFast(this: (idVec3 *)&v45.axis.mat[0].y);
  v20 = (const idAAS2 *)((int (__fastcall *)(idAI2 *, double))ai->GetAAS)(a1: ai, a2: v19);
  AASPosition = idActor::GetAASPosition(this: ai, aas: v20);
  *bestDist = -1.0;
  v22 = (idAASPosition *)AASPosition;
  v23 = -1;
  v24 = (float *)angles;
  v25 = 0;
  do
  {
    v26 = *v24;
    v66.axisValid = false;
    v66.origin.x = vec3_origin.x;
    v66.angle = v26;
    v66.origin.y = vec3_origin.y;
    v66.origin.z = vec3_origin.z;
    v66.vec.x = vec3_up.x;
    v66.vec.y = vec3_up.y;
    v66.vec.z = vec3_up.z;
    v66.axis.mat[0].x = mat3_identity.mat[0].x;
    v66.axis.mat[0].y = mat3_identity.mat[0].y;
    v66.axis.mat[0].z = mat3_identity.mat[0].z;
    v66.axis.mat[1].x = mat3_identity.mat[1].x;
    v66.axis.mat[1].y = mat3_identity.mat[1].y;
    v66.axis.mat[1].z = mat3_identity.mat[1].z;
    v66.axis.mat[2].x = mat3_identity.mat[2].x;
    v66.axis.mat[2].y = mat3_identity.mat[2].y;
    v66.axis.mat[2].z = mat3_identity.mat[2].z;
    idRotation::operator*(this: &v45, result: &v66, v: (const idVec3 *)&v45.axis.mat[0].y);
    v49 = 0;
    v50 = 0;
    v51 = 0;
    v55 = 0;
    v56 = 0;
    *(float *)&v45.axisValid = 0.0;
    v60 = 0;
    v46 = 0.0;
    v61 = 0;
    v47 = 0.0;
    v62 = 0;
    v48 = 0.0;
    v63 = 0;
    v52 = 0.0;
    v64 = 0;
    v53 = 0.0;
    v65 = 0;
    v54 = 0.0;
    travelFlags = ai->aiVolatile.aas.travelFlags;
    v57 = 0.0;
    v58 = 0.0;
    v59 = 0.0;
    v28 = travelFlags & 0xFE78FFFF;
    x = v45.origin.x;
    y = v45.origin.y;
    v31 = v45.origin.z;
    v45.axis.mat[1].z = (float)(v45.origin.x * (float)72.0) + v42;
    v45.axis.mat[2].x = (float)(v45.origin.y * (float)72.0) + v43;
    v45.axis.mat[2].y = v44 + (float)(v45.origin.z * (float)72.0);
    aas = (idAAS2 *)v22->aas;
    v33 = aas->__vftable;
    AreaNum = idAASPosition::GetAreaNum(this: v22);
    ((void (__fastcall *)(idAAS2 *, bool *, float *, int, float *, unsigned int, _DWORD, _DWORD))v33->TraceFloor)(
      a1: aas,
      a2: &v45.axisValid,
      a3: &v42,
      a4: AreaNum,
      a5: &v45.axis.mat[1].z,
      a6: v28,
      a7: 0,
      a8: 0);
    v35 = *(float *)&v45.axisValid;
    if ( (float)(*(float *)&v45.axisValid * 72.0) > (double)*bestDist )
    {
      if ( v35 >= 0.0 )
        v36 = v35 <= 1.0 ? *(float *)&v45.axisValid : 1.0;
      else
        v36 = 0.0;
      *bestDist = (float)v36 * 72.0;
      bestDir->z = v31;
      bestDir->x = x;
      v23 = v25;
      bestDir->y = y;
      v37 = v43;
      v38 = v44;
      v39 = (float)((float)((float)y * *bestDist) * (float)0.94999999);
      v40 = (float)((float)((float)v31 * *bestDist) * (float)0.94999999);
      bestDest->x = (float)((float)(*bestDist * (float)x) * (float)0.94999999) + v42;
      bestDest->y = (float)v39 + (float)v37;
      bestDest->z = (float)v40 + (float)v38;
      if ( v35 >= 1.0 )
        break;
    }
    ++v24;
    ++v25;
  }
  while ( (int)v24 < (int)&flt_82299E24 );
  return v23 >= 0;
}


// ========================================================================
// ?CommonWorkFunction@@YAXPAVidAI2@@@Z
// EA  : 0x82AD2AB8
// RVA : 0x00AD2AB8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall CommonWorkFunction(idAI2 *ai)
{
  int value; // r8
  idEntity *v3; // r3
  idEntity *v4; // r3
  idPlayer *v5; // r31
  idPlayer *v6; // r3
  idPlayer *v7; // r30
  const idEntity *v8; // r4
  int FocusTracker; // r3
  const idVec3 *v10; // r31
  idPhysics *Physics; // r3
  const idVec3 *v12; // r3
  double v13; // fp1
  idAI2 *v14; // r3
  float v15; // r10
  float v16; // r9
  idPresentable *presentable; // r3
  float *v18; // r3
  idPresentable *v19; // r11
  double v20; // fp31
  double v21; // fp30
  double v22; // fp29
  float *v23; // r3
  double v24; // fp12
  double v25; // fp10
  idAI2 *v26; // r3
  idAI2 *v27; // r31
  float y; // r10
  float z; // r9
  idVec3 v30; // [sp+50h] [-60h] BYREF
  idVec3 v31; // [sp+60h] [-50h] BYREF

  value = ai->aiVolatile.memory.currentFriendly.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    goto LABEL_20;
  v3 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v3 == nullptr )
    goto LABEL_20;
  v4 = idEntity::CastTo(c: v3);
  v5 = (idPlayer *)v4;
  if ( v4 == nullptr )
    goto LABEL_20;
  idAI2::SetAimFocusEntity(this: ai, ent: v4, keepFocusInView: true, aimPoint: AIMPOINT_HEAD, timeout: -1);
  if ( !ai->aiEditable.behaviors.decl->lookAtFriendlyTarget )
    return;
  v6 = idPlayer::CastTo(c: v5);
  v7 = v6;
  if ( v6 == nullptr )
  {
    v26 = idAI2::CastTo(c: (idAI2 *)v5);
    v27 = v26;
    if ( v26 != nullptr )
    {
      if ( (unsigned __int8)idFocusInfo::HasFocus(this: v26->aiVolatile.focus.foci.ptr) != 0
        && idAIMemory::GetNeutral(this: v27->aiVolatile.focus.foci.ptr) != ai )
      {
        y = v27->aiVolatile.focus.foci.ptr[0].idealFocusPoint.y;
        z = v27->aiVolatile.focus.foci.ptr[0].idealFocusPoint.z;
        v30.x = v27->aiVolatile.focus.foci.ptr[0].idealFocusPoint.x;
        v30.y = y;
        v30.z = z;
        idAI2::SetExplicitAimFocusPoint(
          this: ai,
          point: &v30,
          keepFocusInView: true,
          timeout: -1,
          focusType: AIFOCUS_LOOK_AROUND);
        return;
      }
      v8 = v27;
      goto LABEL_25;
    }
LABEL_20:
    idAI2::ClearAimFocus(this: ai);
    return;
  }
  if ( idPlayer::GetFocusEntity(this: v6) == ai )
  {
    v8 = v7;
LABEL_25:
    v14 = ai;
LABEL_26:
    idAI2::SetAimFocusEntity(this: v14, ent: v8, keepFocusInView: true, aimPoint: AIMPOINT_HEAD, timeout: -1);
    return;
  }
  FocusTracker = idPlayer::GetFocusTracker(this: v7);
  v10 = (const idVec3 *)(FocusTracker + 112);
  if ( FocusTracker != -112 )
  {
    Physics = idEntity::GetPhysics(this: ai);
    v12 = Physics->GetOrigin(this: Physics, a2: 0);
    v13 = idGeometry::SquarePointLineSegmentDistance(point: v12, start: v10, end: v10 + 2);
    v14 = ai;
    if ( v13 >= 4096.0 )
    {
      v15 = v10[14].y;
      v16 = v10[14].z;
      v30.x = v10[14].x;
      v30.y = v15;
      v30.z = v16;
      idAI2::SetExplicitAimFocusPoint(
        this: ai,
        point: &v30,
        keepFocusInView: true,
        timeout: -1,
        focusType: AIFOCUS_LOOK_AROUND);
      return;
    }
    v8 = v7;
    goto LABEL_26;
  }
  presentable = v7->presentable;
  if ( presentable != nullptr )
    v18 = (float *)presentable->GetPlayerInterface_2(this: presentable);
  else
    v18 = nullptr;
  v19 = v7->presentable;
  v20 = (float)(v18[11636] * (float)1024.0);
  v21 = (float)(v18[11637] * (float)1024.0);
  v22 = (float)(v18[11638] * (float)1024.0);
  if ( v19 != nullptr )
    v23 = (float *)v19->GetPlayerInterface_2(this: v7->presentable);
  else
    v23 = nullptr;
  v24 = (float)(v23[11635] + (float)v22);
  v25 = (float)(v23[11634] + (float)v21);
  v31.x = v23[11633] + (float)v20;
  v31.z = v24;
  v31.y = v25;
  idAI2::SetExplicitAimFocusPoint(
    this: ai,
    point: &v31,
    keepFocusInView: true,
    timeout: -1,
    focusType: AIFOCUS_LOOK_AROUND);
}


// ========================================================================
// ?Evaluate@FOLLOWFRIENDLY_NoTarget@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD2DA8
// RVA : 0x00AD2DA8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

int __fastcall FOLLOWFRIENDLY_NoTarget::Evaluate(
        FOLLOWFRIENDLY_NoTarget *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r4

  value = ai->aiVolatile.memory.currentFriendly.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = idEntity::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  return idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8) != nullptr ? 0 : 0x18C;
}


// ========================================================================
// ?Evaluate@FOLLOWFRIENDLY_ShouldWait@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD2E40
// RVA : 0x00AD2E40
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall FOLLOWFRIENDLY_ShouldWait::Evaluate(
        FOLLOWFRIENDLY_ShouldWait *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r31
  idAIMoveState *MoveInterface; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v11; // zf

  value = ai->aiVolatile.memory.currentFriendly.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = idEntity::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  if ( idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8) == nullptr )
    return 0;
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v11 = MoveInterface->ReachedEntity(this: MoveInterface, a2: v8, a3: 48.0);
  result = TRANSCODE_FOLLOWFRIENDLY_SHOULD_WAIT;
  if ( !v11 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@FOLLOWFRIENDLY_ShouldFollow@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD2F10
// RVA : 0x00AD2F10
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall FOLLOWFRIENDLY_ShouldFollow::Evaluate(
        FOLLOWFRIENDLY_ShouldFollow *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r31
  idAIMoveState *v10; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v12; // zf
  int v13; // [sp+50h] [-20h] BYREF

  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v13 = 3000;
  if ( MoveInterface->RecentlyFailedMove(
         this: MoveInterface,
         a2: AIMOVEREASON_FOLLOW_MOVE_TO_TARGET,
         a3: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&v13) )
  {
    return 0;
  }
  value = ai->aiVolatile.memory.currentFriendly.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = idEntity::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  if ( idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v9) == nullptr )
    return 0;
  v10 = idAI2::GetMoveInterface(this: ai);
  v12 = !v10->ReachedEntity(this: v10, a2: v9, a3: 48.0);
  result = TRANSCODE_FOLLOWFRIENDLY_SHOULD_MOVE;
  if ( !v12 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@FOLLOWFRIENDLY_ShouldBackAway@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD3018
// RVA : 0x00AD3018
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall FOLLOWFRIENDLY_ShouldBackAway::Evaluate(
        FOLLOWFRIENDLY_ShouldBackAway *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r31
  idAIEntityState *v10; // r3
  aiSenseState_t *v11; // r29
  idAIMoveState *v12; // r3
  double v13; // fp31
  idPhysics *Physics; // r3
  int v15; // r3
  float y; // r10
  float v17; // r6
  float x; // r9
  int v19; // r5
  idAIStateTransition::aiTransCode_t result; // r3
  _DWORD v21[7]; // [sp+50h] [-50h] BYREF
  float v22; // [sp+6Ch] [-34h]
  int v23; // [sp+70h] [-30h]

  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v21[0] = 3000;
  if ( MoveInterface->RecentlyFailedMove(
         this: MoveInterface,
         a2: AIMOVEREASON_FOLLOW_BACK_AWAY,
         a3: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)v21) )
  {
    return 0;
  }
  value = ai->aiVolatile.memory.currentFriendly.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = idEntity::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  v10 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v9);
  if ( v10 == nullptr )
    return 0;
  v11 = v10->senses.ptr[v10->lastSense];
  v12 = idAI2::GetMoveInterface(this: ai);
  v13 = ((double (__fastcall *)(idAIMoveState *, idEntity *, double))v12->GetReachedEntityDist)(
          a1: v12,
          a2: v9,
          a3: 24.0);
  Physics = idEntity::GetPhysics(this: ai);
  v15 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  y = v11->unConfirmedPhysical.origin.y;
  v17 = *(float *)v15;
  x = v11->unConfirmedPhysical.origin.x;
  v19 = *(_DWORD *)(v15 + 8);
  v22 = *(float *)(v15 + 4);
  result = TRANSCODE_FOLLOWFRIENDLY_SHOULD_MOVE;
  *(float *)&v21[3] = y;
  *(float *)&v21[6] = v17;
  *(float *)&v21[2] = x;
  v21[4] = LODWORD(v11->unConfirmedPhysical.origin.z);
  v23 = v19;
  if ( __fsqrts((float)((float)((float)(y - v22) * (float)(y - v22)) + (float)((float)(x - v17) * (float)(x - v17)))) >= v13 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@FOLLOWFRIENDLY_TargetMovedAway@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD3190
// RVA : 0x00AD3190
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall FOLLOWFRIENDLY_TargetMovedAway::Evaluate(
        FOLLOWFRIENDLY_TargetMovedAway *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r31
  idAIEntityState *v9; // r3
  aiSenseState_t *v10; // r29
  idAIMoveState *MoveInterface; // r3
  double v12; // fp31
  idPhysics *Physics; // r3
  float *v14; // r3
  float v15; // r6
  idAIStateTransition::aiTransCode_t result; // r3
  float v17; // [sp+64h] [-3Ch]

  value = ai->aiVolatile.memory.currentFriendly.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = idEntity::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  v9 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8);
  if ( v9 == nullptr )
    return 0;
  v10 = v9->senses.ptr[v9->lastSense];
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v12 = ((double (__fastcall *)(idAIMoveState *, idEntity *, double))MoveInterface->GetReachedEntityDist)(
          a1: MoveInterface,
          a2: v8,
          a3: 128.0);
  Physics = idEntity::GetPhysics(this: ai);
  v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v15 = *v14;
  v17 = v14[1];
  result = TRANSCODE_FOLLOWFRIENDLY_SHOULD_MOVE;
  if ( __fsqrts((float)((float)((float)(v10->unConfirmedPhysical.origin.y - v17)
                              * (float)(v10->unConfirmedPhysical.origin.y - v17))
                      + (float)((float)(v10->unConfirmedPhysical.origin.x - v15)
                              * (float)(v10->unConfirmedPhysical.origin.x - v15)))) <= v12 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@FOLLOWFRIENDLY_ChaseProjectileDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD32D8
// RVA : 0x00AD32D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall FOLLOWFRIENDLY_ChaseProjectileDone::Evaluate(
        FOLLOWFRIENDLY_ChaseProjectileDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r31
  int value; // r8
  idEntity *v8; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v10; // zf

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  value = ai->aiVolatile.memory.avoidEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return TRANSCODE_FOLLOW_FRIENDLY_CHASE_PROJECTILE_DONE;
  v8 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v8 == nullptr )
    return TRANSCODE_FOLLOW_FRIENDLY_CHASE_PROJECTILE_DONE;
  if ( idEntity::CastTo(c: v8) == nullptr )
    return TRANSCODE_FOLLOW_FRIENDLY_CHASE_PROJECTILE_DONE;
  if ( FullPath == nullptr )
    return TRANSCODE_FOLLOW_FRIENDLY_CHASE_PROJECTILE_DONE;
  v10 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v10 )
    return TRANSCODE_FOLLOW_FRIENDLY_CHASE_PROJECTILE_DONE;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idFollowFriendly_ReachedTarget@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD3388
// RVA : 0x00AD3388
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendly_ReachedTarget::AIState_EnterState(
        idFollowFriendly_ReachedTarget *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r7
  idEntity *v8; // r3
  idEntity *v9; // r30
  idAIGameState *p_aiGameState; // r28
  const idSpawnId *v11; // r30
  const idAILogic *v12; // r3
  const idSpawnId *v13; // r8
  idEventArg *v14; // r28
  _BYTE v15[20]; // [sp+70h] [-F0h] BYREF
  idSpawnId v16; // [sp+90h] [-D0h] BYREF
  idSpawnId v17; // [sp+94h] [-CCh] BYREF
  _DWORD v18[5]; // [sp+A0h] [-C0h] BYREF
  int v19; // [sp+C0h] [-A0h]
  int v20; // [sp+C4h] [-9Ch]
  idEventArg v21; // [sp+E0h] [-80h] BYREF
  idAILogic v22[3]; // [sp+100h] [-60h] BYREF

  ai->SetWalkState(this: ai, a2: WALKSTATE_WALKING);
  value = ai->aiVolatile.memory.currentFriendly.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = idEntity::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  idAI2::SetAimFocusEntity(this: ai, ent: v9, keepFocusInView: true, aimPoint: AIMPOINT_HEAD, timeout: -1);
  p_aiGameState = &gameLocal->aiGameState;
  idSpawnId::idSpawnId(this: &v16, ent: ai);
  v11 = idSpawnId::idSpawnId(this: &v17, ent: v9);
  v12 = idAILogic::idAILogic(this: v22, ai);
  idAIWorldState::AddEntityState(
    this: &ai->aiVolatile.world.worldState,
    gameState: p_aiGameState,
    owner: v12,
    entId: v11,
    stimulusType: AISTIMULUS_TRIGGER,
    stimulusAmount: 1.0,
    sourceId: v13);
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  HIBYTE(v18[0]) = 105;
  HIBYTE(v19) = 105;
  v18[1] = 0;
  v20 = -1;
  v14 = idEventArg::idEventArg(this: &v21, data: ai);
  memcpy(Dst: v15, Src: v18, Size: sizeof(v15));
  idEventReceiver::ProcessEvent(
    this: (idEventReceiver *)v22,
    result: fsm,
    ev: *(const idEventDef **)&v14->type,
    arg1: (const idEventArg *)LODWORD(v14->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v14->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v19, 32));
}


// ========================================================================
// ?AIState_Work@idFollowFriendly_BackAwayWait@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD3510
// RVA : 0x00AD3510
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendly_BackAwayWait::AIState_Work(
        idFollowFriendly_BackAwayWait *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  CommonWorkFunction(ai);
}


// ========================================================================
// ?Evaluate@FOLLOWFRIENDLY_PathClear@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD3518
// RVA : 0x00AD3518
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

int __fastcall FOLLOWFRIENDLY_PathClear::Evaluate(
        FOLLOWFRIENDLY_PathClear *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r29
  int v9; // r30
  idPhysics *Physics; // r3
  const idVec3 *v11; // r3
  posture_t v13; // [sp+8h] [-138h]
  int v14; // [sp+Ch] [-134h]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v15; // [sp+10h] [-130h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v16; // [sp+14h] [-12Ch]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v17; // [sp+18h] [-128h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v18; // [sp+1Ch] [-124h]
  int v19; // [sp+20h] [-120h]
  int v20; // [sp+24h] [-11Ch]
  int v21; // [sp+28h] [-118h]
  int v22; // [sp+2Ch] [-114h]
  int v23; // [sp+30h] [-110h]
  int v24; // [sp+34h] [-10Ch]
  int v25; // [sp+38h] [-108h]
  int v26; // [sp+3Ch] [-104h]
  int v27; // [sp+40h] [-100h]
  int v28; // [sp+44h] [-FCh]
  int v29; // [sp+48h] [-F8h]
  int v30; // [sp+4Ch] [-F4h]
  int v31; // [sp+50h] [-F0h]
  int v32; // [sp+54h] [-ECh]
  int v33; // [sp+58h] [-E8h]
  int v34; // [sp+60h] [-E0h]
  int v35; // [sp+68h] [-D8h]
  int v36; // [sp+70h] [-D0h]
  int v37; // [sp+78h] [-C8h]
  int v38; // [sp+80h] [-C0h]
  int v39; // [sp+88h] [-B8h]
  __int16 v40; // [sp+90h] [-B0h] BYREF
  __int16 v41; // [sp+92h] [-AEh] BYREF
  __int16 v42; // [sp+94h] [-ACh] BYREF
  __int16 v43; // [sp+96h] [-AAh] BYREF
  _BYTE v44[8]; // [sp+98h] [-A8h] BYREF
  _BYTE v45[16]; // [sp+A0h] [-A0h] BYREF
  _BYTE v46[16]; // [sp+B0h] [-90h] BYREF
  idAIMoveParms v47; // [sp+C0h] [-80h] BYREF

  value = ai->aiVolatile.memory.currentFriendly.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v7 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr )
    return 0;
  v8 = idEntity::CastTo(c: v7);
  if ( v8 == nullptr )
    return 0;
  idAIMoveParms::idAIMoveParms(this: &v47);
  v9 = 14;
  if ( (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 0x20) != 0 )
    v9 = 30;
  Physics = idEntity::GetPhysics(this: ai);
  v43 = -1;
  v42 = -1;
  v41 = -1;
  v40 = -1;
  v11 = Physics->GetOrigin(this: Physics, a2: 0);
  idAIMoveParms::Init(
    this: &v47,
    moveReason_: AIMOVEREASON_TEST,
    startOrigin_: v11,
    goalOrigin_: &vec3_origin,
    goalEntity_: v8,
    goalOrientation_: &quat_identity,
    goalScenePoint_: nullptr,
    goalTolerance_: 48.0,
    intermediateTolerance_: 0.1,
    arrivalAction_: (const aiArrivalAction_t)&v40,
    arrivalPosture_: v13,
    flags_: v14,
    sourceSubWeb_: v15,
    sourceState_: v16,
    destSubWeb_: v17,
    destState_: v18,
    a17: v19,
    a18: v20,
    a19: v21,
    a20: v22,
    a21: v23,
    a22: v24,
    a23: v25,
    a24: v26,
    a25: v27,
    a26: v28,
    a27: v29,
    a28: v30,
    a29: v31,
    a30: v32,
    a31: v33,
    a32: AIARRIVAL_STOP,
    a33: v34,
    a34: POSTURE_STANDING,
    a35: v35,
    a36: v9,
    a37: v36,
    a38: &v40,
    a39: v37,
    arrivalAction__0: &v41,
    a41: v38,
    arrivalPosture_a: &v42,
    a43: v39,
    flags_a: &v43);
  if ( (unsigned int)ai->aiVolatile.physics.moveState.TestMove(
                       this: &ai->aiVolatile.physics.moveState,
                       a2: &v47,
                       a3: (idVec3 *)v46,
                       a4: (idVec3 *)v45,
                       a5: (int *)v44) < AIMOVESTATUS_ERROR )
    return 399;
  else
    return 0;
}


// ========================================================================
// ?AIState_EnterState@idFollowFriendly_MoveToTarget@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD3698
// RVA : 0x00AD3698
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendly_MoveToTarget::AIState_EnterState(
        idFollowFriendly_MoveToTarget *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r6
  idEntity *v8; // r3
  idEntity *v9; // r30
  idEventArg *v10; // r23
  idEventArg *v11; // r31
  const idEventArg *v12; // [sp+8h] [-298h]
  const idEventArg *v13; // [sp+Ch] [-294h]
  const idEventArg *v14; // [sp+10h] [-290h]
  _BYTE v15[20]; // [sp+70h] [-230h] BYREF
  _BYTE v16[20]; // [sp+90h] [-210h] BYREF
  _BYTE v17[20]; // [sp+B0h] [-1F0h] BYREF
  _BYTE v18[20]; // [sp+D0h] [-1D0h] BYREF
  _BYTE v19[20]; // [sp+F0h] [-1B0h] BYREF
  _BYTE v20[20]; // [sp+110h] [-190h] BYREF
  float v21[5]; // [sp+130h] [-170h] BYREF
  _DWORD v22[5]; // [sp+150h] [-150h] BYREF
  char v23; // [sp+170h] [-130h]
  int v24; // [sp+174h] [-12Ch]
  const idEventArg *v25; // [sp+178h] [-128h]
  const idEventArg *v26; // [sp+17Ch] [-124h]
  _DWORD v27[5]; // [sp+190h] [-110h] BYREF
  _DWORD v28[5]; // [sp+1B0h] [-F0h] BYREF
  float v29[5]; // [sp+1D0h] [-D0h] BYREF
  idEventArg v30; // [sp+1F0h] [-B0h] BYREF
  idEventArg v31; // [sp+210h] [-90h] BYREF
  idEventReceiver v32[9]; // [sp+230h] [-70h] BYREF

  ai->SetWalkState(this: ai, a2: WALKSTATE_WALKING);
  value = ai->aiVolatile.memory.currentFriendly.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = idEntity::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  idAI2::SetAimFocusEntity(this: ai, ent: v9, keepFocusInView: true, aimPoint: AIMPOINT_HEAD, timeout: -1);
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  v28[1] = 0;
  v27[1] = 0;
  HIBYTE(v28[0]) = 105;
  v29[1] = 48.0;
  v21[3] = vec3_origin.z;
  HIBYTE(v21[0]) = 118;
  HIBYTE(v27[0]) = 105;
  v21[2] = vec3_origin.y;
  HIBYTE(v29[0]) = 102;
  v21[1] = vec3_origin.x;
  HIBYTE(v22[0]) = 105;
  v22[1] = 2;
  v23 = 105;
  v24 = 21;
  v10 = idEventArg::idEventArg(this: &v30, data: v9);
  v11 = idEventArg::idEventArg(this: &v31, data: ai);
  memcpy(Dst: v20, Src: v28, Size: sizeof(v20));
  memcpy(Dst: v19, Src: v21, Size: sizeof(v19));
  memcpy(Dst: v18, Src: v27, Size: sizeof(v18));
  memcpy(Dst: v17, Src: v29, Size: sizeof(v17));
  memcpy(Dst: v16, Src: v22, Size: sizeof(v16));
  memcpy(Dst: v15, Src: v10, Size: sizeof(v15));
  idEventReceiver::ProcessEvent(
    this: v32,
    result: fsm,
    ev: *(const idEventDef **)&v11->type,
    arg1: (const idEventArg *)LODWORD(v11->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v11->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(LODWORD(v11->value.q[3]), 32),
    arg4: v25,
    arg5: v26,
    arg6: v12,
    arg7: v13,
    arg8: v14);
}


// ========================================================================
// ?AIState_EnterState@idFollowFriendly_BackAway@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD3880
// RVA : 0x00AD3880
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendly_BackAway::AIState_EnterState(
        idFollowFriendly_BackAway *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  idEntity *v10; // r30
  idAIEntityState *v11; // r3
  idAIEntityState *v12; // r29
  double z; // fp31
  idPhysics *Physics; // r3
  const idVec3 *v15; // r3
  double x; // fp29
  double y; // fp30
  float *v18; // r11
  int v19; // r5
  double v20; // fp10
  double v21; // fp9
  idAI2_vtbl *v22; // r10
  double v23; // fp13
  double v24; // fp12
  const idVec3 *(__fastcall *GetEyeOffset)(struct idAI2 *, const idVec3 *); // r9
  double v26; // fp28
  double v27; // fp27
  double v28; // fp26
  idPhysics *v29; // r3
  float *v30; // r3
  double v31; // fp13
  double v32; // fp12
  idEventArg *v33; // r24
  const idEventArg *v34; // [sp+8h] [-328h]
  const idEventArg *v35; // [sp+Ch] [-324h]
  _BYTE v36[20]; // [sp+70h] [-2C0h] BYREF
  _BYTE v37[20]; // [sp+90h] [-2A0h] BYREF
  _BYTE v38[20]; // [sp+B0h] [-280h] BYREF
  _BYTE v39[20]; // [sp+D0h] [-260h] BYREF
  _BYTE v40[20]; // [sp+F0h] [-240h] BYREF
  idVec3 v41[2]; // [sp+110h] [-220h] BYREF
  idVec3 v42; // [sp+128h] [-208h] BYREF
  idVec3 v43; // [sp+138h] [-1F8h] BYREF
  idVec3 v44; // [sp+148h] [-1E8h] BYREF
  _BYTE v45[20]; // [sp+160h] [-1D0h] BYREF
  float v46[11]; // [sp+174h] [-1BCh] BYREF
  int v47; // [sp+1A0h] [-190h]
  int v48; // [sp+1A4h] [-18Ch]
  const idEventArg *v49; // [sp+1A8h] [-188h]
  const idEventArg *v50; // [sp+1ACh] [-184h]
  float v51[5]; // [sp+1C0h] [-170h] BYREF
  _DWORD v52[5]; // [sp+1E0h] [-150h] BYREF
  trace_t v53; // [sp+200h] [-130h] BYREF
  idEventArg v54; // [sp+280h] [-B0h] BYREF
  idEventReceiver v55[6]; // [sp+2A0h] [-90h] BYREF

  ai->SetWalkState(this: ai, a2: WALKSTATE_WALKING);
  if ( FindBackAwayDestination(ai, bestDest: v41, bestDir: (idVec3 *)v45, bestDist: v46) )
  {
    value = ai->aiVolatile.memory.currentFriendly.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v10 = idEntity::CastTo(c: v9);
    }
    else
    {
      v10 = nullptr;
    }
    idAI2::SetAimFocusEntity(this: ai, ent: v10, keepFocusInView: true, aimPoint: AIMPOINT_HEAD, timeout: -1);
    v11 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v10);
    v12 = v11;
    if ( v10 != nullptr && v11 != nullptr )
    {
      z = v41[0].z;
      v42.z = v41[0].z + (float)128.0;
      v42.y = v41[0].y;
      v44.z = v41[0].z - (float)128.0;
      v44.y = v41[0].y;
      v42.x = v41[0].x;
      v44.x = v41[0].x;
      Physics = idEntity::GetPhysics(this: v10);
      v15 = Physics->GetOrigin(this: Physics, a2: 0);
      idClip::TracePoint(
        this: &clientGame->clip,
        result: &v53,
        start: v15,
        end: &v42,
        clipMask: 17,
        passEntityNumber: 0x1FFF);
      if ( v53.fraction < 1.0 )
      {
        v42.x = v53.c.point.x;
        v42.y = v53.c.point.y;
        v42.z = v53.c.point.z;
        v44.x = v53.c.point.x;
        v44.y = v53.c.point.y;
      }
      idClip::TracePoint(
        this: &clientGame->clip,
        result: &v53,
        start: &v42,
        end: &v44,
        clipMask: 17,
        passEntityNumber: 0x1FFF);
      if ( v53.fraction >= 1.0 )
      {
        y = v41[0].y;
        x = v41[0].x;
      }
      else
      {
        x = v53.c.point.x;
        y = v53.c.point.y;
        z = v53.c.point.z;
      }
      v18 = (float *)v12->senses.ptr[v12->lastSense];
      v19 = curTime - ai->aiVolatile.memory.spawnTime;
      v20 = (float)(v18[2] - (float)y);
      v21 = (float)(v18[3] - (float)z);
      v41[0].x = v18[1] - (float)x;
      v41[0].y = v20;
      v41[0].z = v21;
      if ( v19 < 1000 )
      {
        v22 = ai->__vftable;
        v23 = ai->actorVolatile.modelInfo.modelAxis.mat[0].y;
        v24 = ai->actorVolatile.modelInfo.modelAxis.mat[0].z;
        v41[0].x = ai->actorVolatile.modelInfo.modelAxis.mat[0].x;
        GetEyeOffset = v22->GetEyeOffset;
        v41[0].y = v23;
        v41[0].z = v24;
        GetEyeOffset(this: (struct idAI2 *)&v43, result: (const idVec3 *)ai);
        v26 = (float)(ai->actorVolatile.modelInfo.modelAxis.mat[0].x
                    * (float)((float)(UNITS_PER_INCH_9 * (float)20.0) * (float)12.0));
        v27 = (float)(ai->actorVolatile.modelInfo.modelAxis.mat[0].y
                    * (float)((float)(UNITS_PER_INCH_9 * (float)20.0) * (float)12.0));
        v28 = (float)((float)((float)(UNITS_PER_INCH_9 * (float)20.0) * (float)12.0)
                    * ai->actorVolatile.modelInfo.modelAxis.mat[0].z);
        v29 = idEntity::GetPhysics(this: ai);
        v30 = (float *)v29->GetOrigin(this: v29, a2: 0);
        v31 = (float)(v30[1] + (float)v27);
        v32 = (float)(v30[2] + (float)v28);
        v43.x = (float)(*v30 + (float)v26) + v43.x;
        v43.y = v43.y + (float)v31;
        v43.z = v43.z + (float)v32;
        idAI2::SetExplicitAimFocusPoint(
          this: ai,
          point: &v43,
          keepFocusInView: true,
          timeout: 2000,
          focusType: AIFOCUS_LAST_SENSED_POS);
      }
      idVec3::NormalizeFast(this: v41);
      idAI2::EndActionScript(this: ai);
      LODWORD(fsm[1].value.v[2]) = this;
      *(float *)&v45[4] = v41[0].x;
      *(float *)&v45[8] = v41[0].y;
      *(float *)&v45[12] = v41[0].z;
      v41[0].y = x;
      v41[0].z = y;
      v41[1].x = z;
      v45[0] = 118;
      HIBYTE(v46[3]) = 105;
      LODWORD(v46[4]) = 1;
      HIBYTE(v51[0]) = 102;
      HIBYTE(v52[0]) = 105;
      v52[1] = 2;
      HIBYTE(v41[0].x) = 118;
      HIBYTE(v47) = 105;
      v48 = 22;
      v51[1] = 0.1;
      v33 = idEventArg::idEventArg(this: &v54, data: ai);
      memcpy(Dst: v40, Src: v45, Size: sizeof(v40));
      memcpy(Dst: v39, Src: &v46[3], Size: sizeof(v39));
      memcpy(Dst: v38, Src: v51, Size: sizeof(v38));
      memcpy(Dst: v37, Src: v52, Size: sizeof(v37));
      memcpy(Dst: v36, Src: v41, Size: sizeof(v36));
      idEventReceiver::ProcessEvent(
        this: v55,
        result: fsm,
        ev: *(const idEventDef **)&v33->type,
        arg1: (const idEventArg *)LODWORD(v33->value.v[1]),
        arg2: (const idEventArg *)LODWORD(v33->value.v[2]),
        arg3: (const idEventArg *)__ROL4__(v47, 32),
        arg4: v49,
        arg5: v50,
        arg6: v34,
        arg7: v35);
    }
    else
    {
      idState::SetEnterFailed(this, failed: true);
    }
  }
  else if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
  {
    idAnimBaseFSM::ClearDestination(this: &ai->aiVolatile.animation.animFSM);
  }
  else
  {
    idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
  }
}


// ========================================================================
// ?AIState_EnterState@idFollowFriendly_BackAwayWait@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD3D30
// RVA : 0x00AD3D30
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendly_BackAwayWait::AIState_EnterState(
        idFollowFriendly_BackAwayWait *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r6
  idEntity *v8; // r3
  idEntity *v9; // r4
  idEventArg *v10; // r28
  _BYTE v11[20]; // [sp+70h] [-C0h] BYREF
  _DWORD v12[5]; // [sp+90h] [-A0h] BYREF
  int v13; // [sp+B0h] [-80h]
  int v14; // [sp+B4h] [-7Ch]
  idEventArg v15; // [sp+D0h] [-60h] BYREF
  idEventReceiver v16[5]; // [sp+F0h] [-40h] BYREF

  ai->SetWalkState(this: ai, a2: WALKSTATE_WALKING);
  value = ai->aiVolatile.memory.currentFriendly.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = idEntity::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  idAI2::SetAimFocusEntity(this: ai, ent: v9, keepFocusInView: true, aimPoint: AIMPOINT_HEAD, timeout: -1);
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  HIBYTE(v12[0]) = 105;
  HIBYTE(v13) = 105;
  v12[1] = 0;
  v14 = -1;
  v10 = idEventArg::idEventArg(this: &v15, data: ai);
  memcpy(Dst: v11, Src: v12, Size: sizeof(v11));
  idEventReceiver::ProcessEvent(
    this: v16,
    result: fsm,
    ev: *(const idEventDef **)&v10->type,
    arg1: (const idEventArg *)LODWORD(v10->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v10->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v13, 32));
}


// ========================================================================
// ?Evaluate@FOLLOWFRIENDLY_BackAwayClear@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD3E58
// RVA : 0x00AD3E58
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

int __fastcall FOLLOWFRIENDLY_BackAwayClear::Evaluate(
        FOLLOWFRIENDLY_BackAwayClear *this,
        _exception *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int arg1_low; // r8
  idEntity *v7; // r3
  int v9; // r30
  idPhysics *Physics; // r3
  const idVec3 *v11; // r3
  posture_t v12; // [sp+8h] [-158h]
  int v13; // [sp+Ch] [-154h]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v14; // [sp+10h] [-150h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v15; // [sp+14h] [-14Ch]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v16; // [sp+18h] [-148h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v17; // [sp+1Ch] [-144h]
  int v18; // [sp+20h] [-140h]
  int v19; // [sp+24h] [-13Ch]
  int v20; // [sp+28h] [-138h]
  int v21; // [sp+2Ch] [-134h]
  int v22; // [sp+30h] [-130h]
  int v23; // [sp+34h] [-12Ch]
  int v24; // [sp+38h] [-128h]
  int v25; // [sp+3Ch] [-124h]
  int v26; // [sp+40h] [-120h]
  int v27; // [sp+44h] [-11Ch]
  int v28; // [sp+48h] [-118h]
  int v29; // [sp+4Ch] [-114h]
  int v30; // [sp+50h] [-110h]
  int v31; // [sp+54h] [-10Ch]
  int v32; // [sp+58h] [-108h]
  int v33; // [sp+60h] [-100h]
  int v34; // [sp+68h] [-F8h]
  int v35; // [sp+70h] [-F0h]
  int v36; // [sp+78h] [-E8h]
  int v37; // [sp+80h] [-E0h]
  int v38; // [sp+88h] [-D8h]
  __int16 v39; // [sp+90h] [-D0h] BYREF
  __int16 v40; // [sp+92h] [-CEh] BYREF
  __int16 v41; // [sp+94h] [-CCh] BYREF
  __int16 v42; // [sp+96h] [-CAh] BYREF
  _BYTE v43[4]; // [sp+98h] [-C8h] BYREF
  float v44; // [sp+9Ch] [-C4h] BYREF
  idVec3 v45; // [sp+A0h] [-C0h] BYREF
  idVec3 v46; // [sp+B0h] [-B0h] BYREF
  _BYTE v47[16]; // [sp+C0h] [-A0h] BYREF
  _BYTE v48[16]; // [sp+D0h] [-90h] BYREF
  idAIMoveParms v49; // [sp+E0h] [-80h] BYREF

  arg1_low = LODWORD(ai[906].arg1);
  if ( gameLocal->spawnIds.ptr[arg1_low & 0x1FFF] != arg1_low >> 13 )
    return 0;
  v7 = gameLocal->entities.ptr[arg1_low & 0x1FFF];
  if ( v7 == nullptr || idEntity::CastTo(c: v7) == nullptr )
    return 0;
  if ( !FindBackAwayDestination((idAI2 *)ai, bestDest: &v45, bestDir: &v46, bestDist: &v44) )
  {
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 )
    {
      idAnimBaseFSM::ClearDestination(this: (idAnimBaseFSM *)&ai[545]);
      return 0;
    }
    idAIMoveState::Stop(this: (idAIMoveState *)((char *)&ai[190].arg2 + 4), newStatus: 0);
    return 0;
  }
  idAIMoveParms::idAIMoveParms(this: &v49);
  v9 = 14;
  if ( (*(_BYTE *)(*((_DWORD *)&ai[178].name + 1) + 324) & 0x20) != 0 )
    v9 = 30;
  Physics = idEntity::GetPhysics(this: (idEntity *)ai);
  v42 = -1;
  v40 = -1;
  v39 = -1;
  v41 = -1;
  v11 = Physics->GetOrigin(this: Physics, a2: 0);
  idAIMoveParms::Init(
    this: &v49,
    moveReason_: AIMOVEREASON_TEST,
    startOrigin_: v11,
    goalOrigin_: &v45,
    goalEntity_: nullptr,
    goalOrientation_: &quat_identity,
    goalScenePoint_: nullptr,
    goalTolerance_: 0.1,
    intermediateTolerance_: 0.1,
    arrivalAction_: (const aiArrivalAction_t)&v39,
    arrivalPosture_: v12,
    flags_: v13,
    sourceSubWeb_: v14,
    sourceState_: v15,
    destSubWeb_: v16,
    destState_: v17,
    a17: v18,
    a18: v19,
    a19: v20,
    a20: v21,
    a21: v22,
    a22: v23,
    a23: v24,
    a24: v25,
    a25: v26,
    a26: v27,
    a27: v28,
    a28: v29,
    a29: v30,
    a30: v31,
    a31: v32,
    a32: AIARRIVAL_STOP,
    a33: v33,
    a34: POSTURE_STANDING,
    a35: v34,
    a36: v9,
    a37: v35,
    a38: &v41,
    a39: v36,
    arrivalAction__0: &v39,
    a41: v37,
    arrivalPosture_a: &v40,
    a43: v38,
    flags_a: &v42);
  if ( (unsigned int)(*(int (__fastcall **)(char *, idAIMoveParms *, _BYTE *, _BYTE *, _BYTE *))(DWORD1(ai[190].arg2)
                                                                                               + 72))(
                       a1: (char *)&ai[190].arg2 + 4,
                       a2: &v49,
                       a3: v47,
                       a4: v48,
                       a5: v43) > 1 )
    return 0;
  return 399;
}


// ========================================================================
// ?AIState_EnterState@idFollowFriendly_ChaseProjectile@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD4040
// RVA : 0x00AD4040
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendly_ChaseProjectile::AIState_EnterState(
        idFollowFriendly_ChaseProjectile *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r3
  const idEntity *v10; // r30
  idEventArg *v11; // r23
  idEventArg *v12; // r31
  const idEventArg *v13; // [sp+8h] [-298h]
  const idEventArg *v14; // [sp+Ch] [-294h]
  const idEventArg *v15; // [sp+10h] [-290h]
  _BYTE v16[20]; // [sp+70h] [-230h] BYREF
  _BYTE v17[20]; // [sp+90h] [-210h] BYREF
  _BYTE v18[20]; // [sp+B0h] [-1F0h] BYREF
  _BYTE v19[20]; // [sp+D0h] [-1D0h] BYREF
  _BYTE v20[20]; // [sp+F0h] [-1B0h] BYREF
  _BYTE v21[20]; // [sp+110h] [-190h] BYREF
  float v22[5]; // [sp+130h] [-170h] BYREF
  _DWORD v23[5]; // [sp+150h] [-150h] BYREF
  char v24; // [sp+170h] [-130h]
  int v25; // [sp+174h] [-12Ch]
  const idEventArg *v26; // [sp+178h] [-128h]
  const idEventArg *v27; // [sp+17Ch] [-124h]
  _DWORD v28[5]; // [sp+190h] [-110h] BYREF
  _DWORD v29[5]; // [sp+1B0h] [-F0h] BYREF
  float v30[5]; // [sp+1D0h] [-D0h] BYREF
  idEventArg v31; // [sp+1F0h] [-B0h] BYREF
  idEventArg v32; // [sp+210h] [-90h] BYREF
  idEventReceiver v33[9]; // [sp+230h] [-70h] BYREF

  value = ai->aiVolatile.memory.avoidEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v9 = idEntity::CastTo(c: v8), v10 = v9, v9 != nullptr) )
  {
    idAI2::SetAimFocusEntity(this: ai, ent: v9, keepFocusInView: true, aimPoint: AIMPOINT_CENTER, timeout: -1);
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    v22[1] = vec3_origin.x;
    v22[3] = vec3_origin.z;
    HIBYTE(v29[0]) = 105;
    v22[2] = vec3_origin.y;
    v29[1] = 0;
    v30[1] = UNITS_PER_INCH_9 * (float)12.0;
    HIBYTE(v22[0]) = 118;
    HIBYTE(v28[0]) = 105;
    v28[1] = 0;
    HIBYTE(v30[0]) = 102;
    HIBYTE(v23[0]) = 105;
    v23[1] = 2;
    v24 = 105;
    v25 = 23;
    v11 = idEventArg::idEventArg(this: &v31, data: v10);
    v12 = idEventArg::idEventArg(this: &v32, data: ai);
    memcpy(Dst: v21, Src: v29, Size: sizeof(v21));
    memcpy(Dst: v20, Src: v22, Size: sizeof(v20));
    memcpy(Dst: v19, Src: v28, Size: sizeof(v19));
    memcpy(Dst: v18, Src: v30, Size: sizeof(v18));
    memcpy(Dst: v17, Src: v23, Size: sizeof(v17));
    memcpy(Dst: v16, Src: v11, Size: sizeof(v16));
    idEventReceiver::ProcessEvent(
      this: v33,
      result: fsm,
      ev: *(const idEventDef **)&v12->type,
      arg1: (const idEventArg *)LODWORD(v12->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v12->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(LODWORD(v12->value.q[3]), 32),
      arg4: v26,
      arg5: v27,
      arg6: v13,
      arg7: v14,
      arg8: v15);
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?AIState_Work@idFollowFriendly_ChaseProjectile@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD4230
// RVA : 0x00AD4230
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.cpp
// ========================================================================

void __fastcall idFollowFriendly_ChaseProjectile::AIState_Work(
        idFollowFriendly_ChaseProjectile *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idProjectile_Grenade *v9; // r3
  idProjectile_Grenade *v10; // r3
  idEventArg *v11; // r27
  _BYTE v12[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v13[5]; // [sp+90h] [-B0h] BYREF
  int v14; // [sp+B0h] [-90h]
  int v15; // [sp+B4h] [-8Ch]
  idEventArg v16; // [sp+D0h] [-70h] BYREF
  idEventReceiver v17[6]; // [sp+F0h] [-50h] BYREF

  value = ai->aiVolatile.memory.avoidEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = (idProjectile_Grenade *)idEntity::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  v10 = idProjectile_Grenade::CastTo(c: v9);
  if ( v10 != nullptr && v10->IsDead(this: v10) )
  {
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    HIBYTE(v13[0]) = 105;
    HIBYTE(v14) = 105;
    v13[1] = 0;
    v15 = -1;
    v11 = idEventArg::idEventArg(this: &v16, data: ai);
    memcpy(Dst: v12, Src: v13, Size: sizeof(v12));
    idEventReceiver::ProcessEvent(
      this: v17,
      result: fsm,
      ev: *(const idEventDef **)&v11->type,
      arg1: (const idEventArg *)LODWORD(v11->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v11->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v14, 32));
    idAI2::ClearAimFocus(this: ai);
    idAI2::ClearLookFocus(this: ai);
  }
}

