
// ========================================================================
// ?InternalInitState@idRelaxed_Default@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEB128
// RVA : 0x00AEB128
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_Default::InternalInitState(idRelaxed_Default *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_HasFollowPath::Type,
    nextStateType: &idRelaxed_FollowPath::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_ShouldRCControl::Type,
    nextStateType: &idRelaxed_RCControl::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_ShouldFollowFriendly::Type,
    nextStateType: &idRelaxed_FollowFriendly::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_ShouldInvestigateBody::Type,
    nextStateType: &idRelaxed_InvestigateBody::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_ShouldReturnToSpawnPos::Type,
    nextStateType: &idRelaxed_ReturnToSpawnPos::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &RELAXED_ShouldInvestigateBodyEvent::Type,
    nextStateType: &idRelaxed_InvestigateBody::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &RELAXED_PlayerApproaching::Type,
    nextStateType: &idRelaxed_InteractWithPlayer::Type,
    transCode: 94);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &RELAXED_PlayerApproaching::Type,
    nextStateType: &idRelaxed_IdleTrackFriendly::Type,
    transCode: 96);
}


// ========================================================================
// ?Evaluate@RELAXED_ReachedPathPoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEB228
// RVA : 0x00AEB228
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

int __fastcall RELAXED_ReachedPathPoint::Evaluate(
        RELAXED_ReachedPathPoint *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::IsMoveDone(this: ai, checkAlignment: false) ? 0 : 0x4E;
}


// ========================================================================
// ?InternalInitState@idRelaxed_FollowPath@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEB268
// RVA : 0x00AEB268
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_FollowPath::InternalInitState(idRelaxed_FollowPath *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_ReachedPathPoint::Type,
    nextStateType: &idRelaxed_NextPathPoint::Type);
  idState::AddStateTransition(this, fsm, transType: &RELAXED_ErrorNoPath::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &RELAXED_EndOfPath::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_PathBlocked::Type,
    nextStateType: &idRelaxed_PathBlocked::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &RELAXED_PlayerApproaching::Type,
    nextStateType: &idRelaxed_InteractWithPlayer::Type,
    transCode: 94);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &RELAXED_PlayerApproaching::Type,
    nextStateType: &idRelaxed_IdleTrackFriendly::Type,
    transCode: 96);
}


// ========================================================================
// ?InternalInitState@idRelaxed_NextPathPoint@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEB330
// RVA : 0x00AEB330
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_NextPathPoint::InternalInitState(
        idRelaxed_NextPathPoint *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_RunningActionScript::Type,
    nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_HasPlugAnim::Type,
    nextStateType: &idRelaxed_RunningPlugAnim::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_HasFollowPath::Type,
    nextStateType: &idRelaxed_FollowPath::Type);
  idState::AddStateTransition(this, fsm, transType: &RELAXED_EndOfPath::Type, nextStateType: &idRelaxed_Default::Type);
}


// ========================================================================
// ?InternalInitState@idRelaxed_RunningPlugAnim@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEB3D0
// RVA : 0x00AEB3D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_RunningPlugAnim::InternalInitState(
        idRelaxed_RunningPlugAnim *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_PlugAnimDone::Type,
    nextStateType: &idRelaxed_Default::Type);
}


// ========================================================================
// ?Evaluate@RELAXED_FollowFriendlyError@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEB3E8
// RVA : 0x00AEB3E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall RELAXED_FollowFriendlyError::Evaluate(
        RELAXED_FollowFriendlyError *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v7; // zf

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( FullPath == nullptr )
    return TRANSCODE_RELAXED_FOLLOW_FRIENDLY_ERROR;
  v7 = (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) == 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_RELAXED_FOLLOW_FRIENDLY_ERROR;
  return result;
}


// ========================================================================
// ?InternalInitState@idRelaxed_FollowFriendly@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEB430
// RVA : 0x00AEB430
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_FollowFriendly::InternalInitState(
        idRelaxed_FollowFriendly *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_FollowFriendlyError::Type,
    nextStateType: &idRelaxed_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_FollowFriendlyDone::Type,
    nextStateType: &idRelaxed_Default::Type);
}


// ========================================================================
// ?Evaluate@RELAXED_RetryPath@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEB480
// RVA : 0x00AEB480
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

int __fastcall RELAXED_RetryPath::Evaluate(
        RELAXED_RetryPath *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return __CFADD__(curTime - (unsigned int)state[1].__vftable, (int)state[1].__vftable ^ 0x80000000) ? 0 : 0x62;
}


// ========================================================================
// ?InternalInitState@idRelaxed_PathBlocked@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEB4A0
// RVA : 0x00AEB4A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_PathBlocked::InternalInitState(idRelaxed_PathBlocked *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_RetryPath::Type,
    nextStateType: &idRelaxed_FollowPath::Type);
}


// ========================================================================
// ?AIState_ExitState@idRelaxed_PathBlocked@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEB4B8
// RVA : 0x00AEB4B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

// attributes: thunk
void __fastcall idRelaxed_PathBlocked::AIState_ExitState(
        idRelaxed_PathBlocked *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idAIState::ClearQueuedActions(this, ai, parentFSM: fsm, curTime);
}


// ========================================================================
// ?InternalInitState@idRelaxed_InteractWithPlayer@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEB4C0
// RVA : 0x00AEB4C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_InteractWithPlayer::InternalInitState(
        idRelaxed_InteractWithPlayer *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_PlayerInteractDone::Type,
    nextStateType: &idRelaxed_IdleTrackFriendly::Type,
    transCode: 96);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_PlayerInteractDone::Type,
    nextStateType: &idRelaxed_Default::Type,
    transCode: 95);
}


// ========================================================================
// ?AIState_EnterState@idRelaxed_InteractWithPlayer@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEB518
// RVA : 0x00AEB518
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_InteractWithPlayer::AIState_EnterState(
        idRelaxed_InteractWithPlayer *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAI2::SetInteracting(this: ai, b: true);
}


// ========================================================================
// ?AIState_ExitState@idRelaxed_InteractWithPlayer@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEB528
// RVA : 0x00AEB528
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_InteractWithPlayer::AIState_ExitState(
        idRelaxed_InteractWithPlayer *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAI2::SetInteracting(this: ai, b: false);
}


// ========================================================================
// ?InternalInitState@idRelaxed_IdleTrackFriendly@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEB538
// RVA : 0x00AEB538
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_IdleTrackFriendly::InternalInitState(
        idRelaxed_IdleTrackFriendly *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_IdleTrackFriendlyDone::Type,
    nextStateType: &idRelaxed_Default::Type);
}


// ========================================================================
// ?InternalInitState@idRelaxed_InvestigateBody@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEB550
// RVA : 0x00AEB550
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_InvestigateBody::InternalInitState(
        idRelaxed_InvestigateBody *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_InvestigateBodyDone::Type,
    nextStateType: &idRelaxed_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_MoveFailed::Type,
    nextStateType: &idRelaxed_MoveFailed::Type);
}


// ========================================================================
// ?Evaluate@RELAXED_MoveFailed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEB5B8
// RVA : 0x00AEB5B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall RELAXED_MoveFailed::Evaluate(
        RELAXED_MoveFailed *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3
  idAIMoveState *v7; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v9; // zf

  MoveInterface = idAI2::GetMoveInterface(this: ai);
  if ( MoveInterface->GetMoveStatus(this: MoveInterface) == 0 )
    return 0;
  v7 = idAI2::GetMoveInterface(this: ai);
  v9 = v7->GetMoveStatus(this: v7) != 1;
  result = 1;
  if ( !v9 )
    return 0;
  return result;
}


// ========================================================================
// ?InternalInitState@idRelaxed_ReturnToSpawnPos@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEB628
// RVA : 0x00AEB628
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_ReturnToSpawnPos::InternalInitState(
        idRelaxed_ReturnToSpawnPos *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_MoveFailed::Type,
    nextStateType: &idRelaxed_MoveFailed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RELAXED_ReturnToSpawnPosDone::Type,
    nextStateType: &idRelaxed_Default::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &RELAXED_ShouldInvestigateBodyEvent::Type,
    nextStateType: &idRelaxed_InvestigateBody::Type);
}


// ========================================================================
// ?InternalInitState@idRelaxed_MoveFailed@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEB6A8
// RVA : 0x00AEB6A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_MoveFailed::InternalInitState(idRelaxed_MoveFailed *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &RELAXED_WaitExpired::Type, nextStateType: &idRelaxed_Default::Type);
}


// ========================================================================
// ?InitStates@idRelaxedFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82AEB6C0
// RVA : 0x00AEB6C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxedFSM::InitStates(idRelaxedFSM *this, const idFiniteStateMachineParams *params)
{
  idAIFSM::InitStates(this, params);
  this->AddState(this, a2: &this->stateDefault);
  this->AddState(this, a2: &this->stateFollowPath);
  this->AddState(this, a2: &this->statePathBlocked);
  this->AddState(this, a2: &this->stateNextPathPoint);
  this->AddState(this, a2: &this->stateRunningPlugAnim);
  this->AddState(this, a2: &this->stateFollowFriendly);
  this->AddState(this, a2: &this->stateInteractWithPlayer);
  this->AddState(this, a2: &this->stateIdleTrackFriendly);
  this->AddState(this, a2: &this->stateInvestigateBody);
  this->AddState(this, a2: &this->stateReturnToSpawnPos);
  this->AddState(this, a2: &this->stateRCControl);
  this->AddState(this, a2: &this->stateMoveFailed);
}


// ========================================================================
// ?Evaluate@RELAXED_ShouldRCControl@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEB810
// RVA : 0x00AEB810
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall RELAXED_ShouldRCControl::Evaluate(
        RELAXED_ShouldRCControl *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  idInventoryItem *v6; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v8; // zf

  v6 = (idInventoryItem *)((int (__fastcall *)(idAI2 *, int, idAIFSM *, idAIState *, int))ai->GetEquipped)(
                            a1: ai,
                            a2: 2,
                            a3: parentFSM,
                            a4: state,
                            a5: curTime);
  if ( v6 == nullptr )
  {
    v6 = ai->GetEquipped(this: ai, a2: 1);
    if ( v6 == nullptr )
      return 0;
  }
  v8 = idStr::Cmp(s1: v6->decl->internalName.data, s2: "rcremote") == 0;
  result = TRANSCODE_RELAXED_SHOULD_RC_CONTROL;
  if ( !v8 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@RELAXED_ShouldReturnToSpawnPos@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEB8A0
// RVA : 0x00AEB8A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall RELAXED_ShouldReturnToSpawnPos::Evaluate(
        RELAXED_ShouldReturnToSpawnPos *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3
  idPhysics *Physics; // r3
  float *v8; // r3
  double v9; // fp10
  idAIStateTransition::aiTransCode_t result; // r3
  double v11; // fp7
  double v12; // fp5
  int v13; // [sp+50h] [-20h] BYREF

  if ( !ai->aiEditable.spawnSettings.returnToSpawnPos )
    return 0;
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v13 = 5000;
  if ( MoveInterface->RecentlyFailedMove(
         this: MoveInterface,
         a2: AIMOVEREASON_RELAXED_RETURN_TO_SPAWN_POS,
         a3: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&v13) )
  {
    return 0;
  }
  if ( idEntity::GetPhysics(this: ai)->type != PHYSICS_AI )
    return 0;
  if ( BYTE2(idEntity::GetPhysics(this: ai)[9].clip) == 0 )
    return 0;
  Physics = idEntity::GetPhysics(this: ai);
  v8 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v9 = (float)(ai->spawnPosition.y - v8[1]);
  v11 = (float)(ai->spawnPosition.x - *v8);
  result = TRANSCODE_RELAXED_SHOULD_RETURN_TO_SPAWN_POS;
  v12 = (float)((float)(UNITS_PER_INCH_12 * (float)5.0) * (float)12.0);
  if ( (float)((float)((float)v11 * (float)v11) + (float)((float)v9 * (float)v9)) <= (double)(float)((float)v12 * (float)v12) )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idRelaxed_Default@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEB9A0
// RVA : 0x00AEB9A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_Default::AIState_EnterState(idRelaxed_Default *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  idEventArg *v8; // r3
  idEventArg *v9; // r24
  _BYTE v10[20]; // [sp+70h] [-E0h] BYREF
  idEventReceiver v11[2]; // [sp+90h] [-C0h] BYREF
  idEventArg v12; // [sp+B0h] [-A0h] BYREF
  idEventArg v13; // [sp+D0h] [-80h] BYREF
  idEventReceiver v14[8]; // [sp+F0h] [-60h] BYREF

  if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED )
  {
    v8 = idEventArg::idEventArg(this: &v12, data: ai);
    idEventReceiver::ProcessEvent(
      this: v11,
      result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
      ev: *(const idEventDef **)&v8->type,
      arg1: (const idEventArg *)LODWORD(v8->value.v[1]));
  }
  HIBYTE(v11[0].__vftable) = 105;
  v11[0].listenerList = nullptr;
  v12.type = 105;
  v12.value.i = -1;
  v9 = idEventArg::idEventArg(this: &v13, data: ai);
  memcpy(Dst: v10, Src: v11, Size: sizeof(v10));
  idEventReceiver::ProcessEvent(
    this: v14,
    result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
    ev: *(const idEventDef **)&v9->type,
    arg1: (const idEventArg *)LODWORD(v9->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v9->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v12.type, 32));
  idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
  idAI2::ClearAimFocus(this: ai);
  idAI2::ClearLookFocus(this: ai);
  idAI2::SetEnableAutoFocus(this: ai, enable: true);
  ai->SetWalkState(this: ai, a2: WALKSTATE_WALKING);
  ai->EnableAIEventResponse(this: ai, a2: AIEVENT_BODY);
  ai->EnableAIEventResponse(this: ai, a2: AIEVENT_INVESTIGATE);
  *((_BYTE *)&ai->aiVolatile + 49704) &= ~1u;
}


// ========================================================================
// ?Evaluate@RELAXED_ErrorNoPath@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEBB20
// RVA : 0x00AEBB20
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

int __fastcall RELAXED_ErrorNoPath::Evaluate(
        RELAXED_ErrorNoPath *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !state->enterFailed ? 0 : 0x56;
}


// ========================================================================
// ?Evaluate@RELAXED_PathBlocked@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEBB38
// RVA : 0x00AEBB38
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

int __fastcall RELAXED_PathBlocked::Evaluate(
        RELAXED_PathBlocked *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idFiniteStateMachine *v6; // r31
  int errorTransCode; // r11

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  v6 = FullPath;
  if ( FullPath != nullptr
    && (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) != 0
    && ((errorTransCode = v6->errorTransCode) == 9 || errorTransCode == 20 || errorTransCode == 10) )
  {
    return 88;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?AIState_ExitState@idRelaxed_FollowPath@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEBBC0
// RVA : 0x00AEBBC0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_FollowPath::AIState_ExitState(
        idRelaxed_FollowPath *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  ai->aiVolatile.memory.allowCombat = true;
  ai->aiVolatile.memory.allowSearch = true;
}


// ========================================================================
// ?Evaluate@RELAXED_RunningActionScript@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEBBE0
// RVA : 0x00AEBBE0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

int __fastcall RELAXED_RunningActionScript::Evaluate(
        RELAXED_RunningActionScript *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  unsigned int v5; // r3

  v5 = idComponentActionScript::NumScriptActions(this: &ai->actionScript, entity: ai);
  return ((v5 == 0) + (v5 >> 31) - 1) & 0x50;
}


// ========================================================================
// ?Evaluate@RELAXED_HasPlugAnim@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEBC20
// RVA : 0x00AEBC20
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

int __fastcall RELAXED_HasPlugAnim::Evaluate(
        RELAXED_HasPlugAnim *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idRelaxed_NextPathPoint *state,
        const int curTime)
{
  return !idRelaxed_NextPathPoint::CastTo(c: state)->hasPlugAnim ? 0 : 0x51;
}


// ========================================================================
// ?Evaluate@RELAXED_PlugAnimDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEBC58
// RVA : 0x00AEBC58
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

int __fastcall RELAXED_PlugAnimDone::Evaluate(
        RELAXED_PlugAnimDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idRelaxed_RunningPlugAnim *state,
        const int curTime)
{
  return !idRelaxed_RunningPlugAnim::CastTo(c: state)->plugAnimDone ? 0 : 8;
}


// ========================================================================
// ?AIState_Work@idRelaxed_RunningPlugAnim@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEBC90
// RVA : 0x00AEBC90
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_RunningPlugAnim::AIState_Work(
        idRelaxed_RunningPlugAnim *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAIAction *CurrentAction; // r3

  CurrentAction = idAIActionFSM::GetCurrentAction(this: &ai->aiVolatile.fsms.actionManager.legsFSM);
  this->plugAnimDone = (_cntlzw((unsigned __int8)idAction_ScriptedAnimWeb::IsTypeOf(c: CurrentAction)) & 0x20) != 0;
}


// ========================================================================
// ?Evaluate@RELAXED_FollowFriendlyDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEBCD8
// RVA : 0x00AEBCD8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall RELAXED_FollowFriendlyDone::Evaluate(
        RELAXED_FollowFriendlyDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v7; // zf

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( FullPath == nullptr )
    return TRANSCODE_RELAXED_FOLLOW_FRIENDLY_DONE;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_RELAXED_FOLLOW_FRIENDLY_DONE;
  return result;
}


// ========================================================================
// ??0idRelaxed_PathBlocked@@QAA@XZ
// EA  : 0x82AEBD20
// RVA : 0x00AEBD20
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

idRelaxed_PathBlocked *__fastcall idRelaxed_PathBlocked::idRelaxed_PathBlocked(idRelaxed_PathBlocked *this)
{
  idState::idState(this, stateType: &idRelaxed_PathBlocked::Type, childFSMType: nullptr, flags: 0);
  this->retryPathTime = 0;
  this->__vftable = (idRelaxed_PathBlocked_vtbl *)&idRelaxed_PathBlocked::`vftable';
  return this;
}


// ========================================================================
// ?AIState_EnterState@idRelaxed_PathBlocked@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEBD80
// RVA : 0x00AEBD80
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_PathBlocked::AIState_EnterState(
        idRelaxed_PathBlocked *this,
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

  this->retryPathTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) + 5000;
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
// ?Evaluate@RELAXED_IdleTrackFriendlyDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEBE48
// RVA : 0x00AEBE48
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

int __fastcall RELAXED_IdleTrackFriendlyDone::Evaluate(
        RELAXED_IdleTrackFriendlyDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3

  if ( idFile_SaveGamePipelined::GetFullPath(this: state) == 0 )
    return 97;
  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  return idFiniteStateMachine::GetStatus(this: FullPath) != 0 ? 0 : 0x61;
}


// ========================================================================
// ?Evaluate@RELAXED_InvestigateBodyDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEBEB8
// RVA : 0x00AEBEB8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall RELAXED_InvestigateBodyDone::Evaluate(
        RELAXED_InvestigateBodyDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v7; // zf

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( FullPath == nullptr )
    return TRANSCODE_RELAXED_INVESTIGATE_BODY_DONE;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_RELAXED_INVESTIGATE_BODY_DONE;
  return result;
}


// ========================================================================
// ?AIState_Work@idRelaxed_InvestigateBody@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEBF00
// RVA : 0x00AEBF00
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_InvestigateBody::AIState_Work(
        idRelaxed_InvestigateBody *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
}


// ========================================================================
// ?AIState_EnterState@idRelaxed_ReturnToSpawnPos@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEBF18
// RVA : 0x00AEBF18
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_ReturnToSpawnPos::AIState_EnterState(
        idRelaxed_ReturnToSpawnPos *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  double z; // fp9
  idEventArg *v8; // r24
  const idEventArg *v9; // [sp+8h] [-248h]
  const idEventArg *v10; // [sp+Ch] [-244h]
  _BYTE v11[20]; // [sp+70h] [-1E0h] BYREF
  _BYTE v12[20]; // [sp+90h] [-1C0h] BYREF
  _BYTE v13[20]; // [sp+B0h] [-1A0h] BYREF
  _BYTE v14[20]; // [sp+D0h] [-180h] BYREF
  _BYTE v15[20]; // [sp+F0h] [-160h] BYREF
  float v16[5]; // [sp+110h] [-140h] BYREF
  float v17[5]; // [sp+130h] [-120h] BYREF
  float v18[5]; // [sp+150h] [-100h] BYREF
  int v19; // [sp+170h] [-E0h]
  int v20; // [sp+174h] [-DCh]
  const idEventArg *v21; // [sp+178h] [-D8h]
  const idEventArg *v22; // [sp+17Ch] [-D4h]
  _DWORD v23[5]; // [sp+190h] [-C0h] BYREF
  _DWORD v24[5]; // [sp+1B0h] [-A0h] BYREF
  idEventArg v25; // [sp+1D0h] [-80h] BYREF
  idEventReceiver v26[8]; // [sp+1F0h] [-60h] BYREF

  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  z = ai->spawnPosition.z;
  v17[2] = ai->spawnPosition.y;
  v17[3] = z;
  v16[1] = vec3_origin.x;
  v17[1] = ai->spawnPosition.x;
  HIBYTE(v16[0]) = 118;
  v16[2] = vec3_origin.y;
  HIBYTE(v23[0]) = 105;
  v16[3] = vec3_origin.z;
  v23[1] = 0;
  v18[1] = 0.1;
  HIBYTE(v18[0]) = 102;
  HIBYTE(v24[0]) = 105;
  v24[1] = 2;
  HIBYTE(v17[0]) = 118;
  HIBYTE(v19) = 105;
  v20 = 28;
  v8 = idEventArg::idEventArg(this: &v25, data: ai);
  memcpy(Dst: v15, Src: v16, Size: sizeof(v15));
  memcpy(Dst: v14, Src: v23, Size: sizeof(v14));
  memcpy(Dst: v13, Src: v18, Size: sizeof(v13));
  memcpy(Dst: v12, Src: v24, Size: sizeof(v12));
  memcpy(Dst: v11, Src: v17, Size: sizeof(v11));
  idEventReceiver::ProcessEvent(
    this: v26,
    result: fsm,
    ev: *(const idEventDef **)&v8->type,
    arg1: (const idEventArg *)LODWORD(v8->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v8->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v19, 32),
    arg4: v21,
    arg5: v22,
    arg6: v9,
    arg7: v10);
}


// ========================================================================
// ?Evaluate@RELAXED_ReturnToSpawnPosDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEC070
// RVA : 0x00AEC070
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall RELAXED_ReturnToSpawnPosDone::Evaluate(
        RELAXED_ReturnToSpawnPosDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v7; // zf

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( FullPath == nullptr )
    return TRANSCODE_RELAXED_RETURN_TO_SPAWN_POS_DONE;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_RELAXED_RETURN_TO_SPAWN_POS_DONE;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idRelaxed_RCControl@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEC0B8
// RVA : 0x00AEC0B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_RCControl::AIState_EnterState(
        idRelaxed_RCControl *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v5; // [sp+50h] [-20h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v6; // [sp+52h] [-1Eh] BYREF

  v6.value = -1;
  v5.value = -1;
  idAI2::FindAnimWebAndStateIndices(
    this: ai,
    web: AIANIMWEB_BODY,
    subWeb: 19,
    stateName: "idle",
    changeWeapon: true,
    newWeapon: nullptr,
    subWebIndex: &v6,
    stateIndex: &v5);
  if ( idAI2::ChangeAnimState(
         this: ai,
         web: AIANIMWEB_BODY,
         subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v6.value,
         stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v5.value,
         interruptPath: INTR_PATH_NO,
         interruptBlend: INTR_BLEND_NO) == 1 )
    idAI2::SetAnimWebEvent(
      this: ai,
      web: AIANIMWEB_BODY,
      priority: PRIORITY_LOW,
      swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v6.value,
      si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v5.value,
      eventType: ANIMWEB_EVENT_START_BLEND_IN,
      eventDef: &EV_AnimWeb_Wait);
}


// ========================================================================
// ?Evaluate@RELAXED_WaitExpired@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEC160
// RVA : 0x00AEC160
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

unsigned int __fastcall RELAXED_WaitExpired::Evaluate(
        RELAXED_WaitExpired *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  return (GameMs >> 31)
       + ((unsigned int)GameMs >= ai->aiVolatile.memory.waitExpireTime)
       + ((unsigned int)ai->aiVolatile.memory.waitExpireTime >> 31);
}


// ========================================================================
// ?AIState_EnterState@idRelaxed_MoveFailed@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEC1C0
// RVA : 0x00AEC1C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_MoveFailed::AIState_EnterState(
        idRelaxed_MoveFailed *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  char *data; // r4
  idEventArg *v8; // r28
  _BYTE v9[20]; // [sp+70h] [-C0h] BYREF
  _DWORD v10[5]; // [sp+90h] [-A0h] BYREF
  int v11; // [sp+B0h] [-80h]
  int v12; // [sp+B4h] [-7Ch]
  idEventArg v13; // [sp+D0h] [-60h] BYREF
  idEventReceiver v14[5]; // [sp+F0h] [-40h] BYREF

  data = ai->name.data;
  ai->aiVolatile.memory.waitExpireTime = curTime + 5000;
  idLib::Warning(fmt: "AI '%s' failed returning to his spawn point or investigating body.", data);
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  HIBYTE(v10[0]) = 105;
  v10[1] = 0;
  HIBYTE(v11) = 105;
  v12 = -1;
  v8 = idEventArg::idEventArg(this: &v13, data: ai);
  memcpy(Dst: v9, Src: v10, Size: sizeof(v9));
  idEventReceiver::ProcessEvent(
    this: v14,
    result: fsm,
    ev: *(const idEventDef **)&v8->type,
    arg1: (const idEventArg *)LODWORD(v8->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v8->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v11, 32));
}


// ========================================================================
// ??0idRelaxedFSM@@QAA@XZ
// EA  : 0x82AEC290
// RVA : 0x00AEC290
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

idRelaxedFSM *__fastcall idRelaxedFSM::idRelaxedFSM(idRelaxedFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: "FSM_relaxed");
  this->__vftable = (idRelaxedFSM_vtbl *)&idRelaxedFSM::`vftable';
  idState::idState(this: &this->stateDefault, stateType: &idRelaxed_Default::Type, childFSMType: nullptr, flags: 2);
  this->stateDefault.__vftable = (idRelaxed_Default_vtbl *)&idRelaxed_Default::`vftable';
  idState::idState(
    this: &this->stateFollowPath,
    stateType: &idRelaxed_FollowPath::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateFollowPath.__vftable = (idRelaxed_FollowPath_vtbl *)&idRelaxed_FollowPath::`vftable';
  idState::idState(
    this: &this->statePathBlocked,
    stateType: &idRelaxed_PathBlocked::Type,
    childFSMType: nullptr,
    flags: 0);
  this->statePathBlocked.retryPathTime = 0;
  this->statePathBlocked.__vftable = (idRelaxed_PathBlocked_vtbl *)&idRelaxed_PathBlocked::`vftable';
  idState::idState(
    this: &this->stateNextPathPoint,
    stateType: &idRelaxed_NextPathPoint::Type,
    childFSMType: nullptr,
    flags: 2);
  this->stateNextPathPoint.__vftable = (idRelaxed_NextPathPoint_vtbl *)&idRelaxed_NextPathPoint::`vftable';
  idState::idState(
    this: &this->stateRunningPlugAnim,
    stateType: &idRelaxed_RunningPlugAnim::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateRunningPlugAnim.__vftable = (idRelaxed_RunningPlugAnim_vtbl *)&idRelaxed_RunningPlugAnim::`vftable';
  idState::idState(
    this: &this->stateFollowFriendly,
    stateType: &idRelaxed_FollowFriendly::Type,
    childFSMType: &idFollowFriendlyFSM::Type,
    flags: 0);
  this->stateFollowFriendly.__vftable = (idRelaxed_FollowFriendly_vtbl *)&idRelaxed_FollowFriendly::`vftable';
  idState::idState(
    this: &this->stateInteractWithPlayer,
    stateType: &idRelaxed_InteractWithPlayer::Type,
    childFSMType: &idPlayerInteractFSM::Type,
    flags: 0);
  this->stateInteractWithPlayer.__vftable = (idRelaxed_InteractWithPlayer_vtbl *)&idRelaxed_InteractWithPlayer::`vftable';
  idState::idState(
    this: &this->stateIdleTrackFriendly,
    stateType: &idRelaxed_IdleTrackFriendly::Type,
    childFSMType: &idIdleTrackFriendlyFSM::Type,
    flags: 0);
  this->stateIdleTrackFriendly.__vftable = (idRelaxed_IdleTrackFriendly_vtbl *)&idRelaxed_IdleTrackFriendly::`vftable';
  idState::idState(
    this: &this->stateInvestigateBody,
    stateType: &idRelaxed_InvestigateBody::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateInvestigateBody.__vftable = (idRelaxed_InvestigateBody_vtbl *)&idRelaxed_InvestigateBody::`vftable';
  idState::idState(
    this: &this->stateReturnToSpawnPos,
    stateType: &idRelaxed_ReturnToSpawnPos::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateReturnToSpawnPos.__vftable = (idRelaxed_ReturnToSpawnPos_vtbl *)&idRelaxed_ReturnToSpawnPos::`vftable';
  idState::idState(this: &this->stateRCControl, stateType: &idRelaxed_RCControl::Type, childFSMType: nullptr, flags: 0);
  this->stateRCControl.__vftable = (idRelaxed_RCControl_vtbl *)&idRelaxed_RCControl::`vftable';
  idState::idState(
    this: &this->stateMoveFailed,
    stateType: &idRelaxed_MoveFailed::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveFailed.__vftable = (idRelaxed_MoveFailed_vtbl *)&idRelaxed_MoveFailed::`vftable';
  idFiniteStateMachine::SetDefaultState(this, state: &this->stateDefault);
  return this;
}


// ========================================================================
// __unwind$489251
// EA  : 0x82AEC4A4
// RVA : 0x00AEC4A4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489251()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489252
// EA  : 0x82AEC4CC
// RVA : 0x00AEC4CC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489252()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$489253
// EA  : 0x82AEC4F8
// RVA : 0x00AEC4F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489253()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$489254
// EA  : 0x82AEC524
// RVA : 0x00AEC524
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489254()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// __unwind$489255
// EA  : 0x82AEC550
// RVA : 0x00AEC550
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489255()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 196));
}


// ========================================================================
// __unwind$489256
// EA  : 0x82AEC57C
// RVA : 0x00AEC57C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489256()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 228));
}


// ========================================================================
// __unwind$489257
// EA  : 0x82AEC5A8
// RVA : 0x00AEC5A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489257()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 260));
}


// ========================================================================
// __unwind$489258
// EA  : 0x82AEC5D4
// RVA : 0x00AEC5D4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489258()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 288));
}


// ========================================================================
// __unwind$489259
// EA  : 0x82AEC600
// RVA : 0x00AEC600
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489259()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 316));
}


// ========================================================================
// __unwind$489260
// EA  : 0x82AEC62C
// RVA : 0x00AEC62C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489260()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 344));
}


// ========================================================================
// __unwind$489261
// EA  : 0x82AEC658
// RVA : 0x00AEC658
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489261()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 372));
}


// ========================================================================
// __unwind$489262
// EA  : 0x82AEC684
// RVA : 0x00AEC684
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489262()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 400));
}


// ========================================================================
// __unwind$489263
// EA  : 0x82AEC6B0
// RVA : 0x00AEC6B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489263()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 428));
}


// ========================================================================
// ??1idRelaxedFSM@@UAA@XZ
// EA  : 0x82AEC6E8
// RVA : 0x00AEC6E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxedFSM::~idRelaxedFSM(idRelaxedFSM *this)
{
  this->__vftable = (idRelaxedFSM_vtbl *)&idRelaxedFSM::`vftable';
  idState::~idState(this: &this->stateMoveFailed);
  idState::~idState(this: &this->stateRCControl);
  idState::~idState(this: &this->stateReturnToSpawnPos);
  idState::~idState(this: &this->stateInvestigateBody);
  idState::~idState(this: &this->stateIdleTrackFriendly);
  idState::~idState(this: &this->stateInteractWithPlayer);
  idState::~idState(this: &this->stateFollowFriendly);
  idState::~idState(this: &this->stateRunningPlugAnim);
  idState::~idState(this: &this->stateNextPathPoint);
  idState::~idState(this: &this->statePathBlocked);
  idState::~idState(this: &this->stateFollowPath);
  idState::~idState(this: &this->stateDefault);
  idFiniteStateMachine::~idFiniteStateMachine(this);
}


// ========================================================================
// __unwind$489477
// EA  : 0x82AEC794
// RVA : 0x00AEC794
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489477()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489478
// EA  : 0x82AEC7BC
// RVA : 0x00AEC7BC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489478()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// __unwind$489479
// EA  : 0x82AEC7E8
// RVA : 0x00AEC7E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489479()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$489480
// EA  : 0x82AEC814
// RVA : 0x00AEC814
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489480()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// __unwind$489481
// EA  : 0x82AEC840
// RVA : 0x00AEC840
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489481()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 196));
}


// ========================================================================
// __unwind$489482
// EA  : 0x82AEC86C
// RVA : 0x00AEC86C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489482()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 228));
}


// ========================================================================
// __unwind$489483
// EA  : 0x82AEC898
// RVA : 0x00AEC898
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489483()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 260));
}


// ========================================================================
// __unwind$489484
// EA  : 0x82AEC8C4
// RVA : 0x00AEC8C4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489484()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 288));
}


// ========================================================================
// __unwind$489485
// EA  : 0x82AEC8F0
// RVA : 0x00AEC8F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489485()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 316));
}


// ========================================================================
// __unwind$489486
// EA  : 0x82AEC91C
// RVA : 0x00AEC91C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489486()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 344));
}


// ========================================================================
// __unwind$489487
// EA  : 0x82AEC948
// RVA : 0x00AEC948
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489487()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 372));
}


// ========================================================================
// __unwind$489488
// EA  : 0x82AEC974
// RVA : 0x00AEC974
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void _unwind_489488()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 400));
}


// ========================================================================
// ?Evaluate@RELAXED_HasFollowPath@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AECA58
// RVA : 0x00AECA58
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

int __fastcall RELAXED_HasFollowPath::Evaluate(
        RELAXED_HasFollowPath *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idInfoPath *v8; // r3

  if ( idComponentActionScript::NumScriptActions(this: &ai->actionScript, entity: ai) <= 0
    && (value = ai->aiVolatile.memory.currentPath.spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
    && (v8 = (idInfoPath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idInfoPath::CastTo(c: v8) != nullptr )
  {
    return 79;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?Evaluate@RELAXED_EndOfPath@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AECB00
// RVA : 0x00AECB00
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

int __fastcall RELAXED_EndOfPath::Evaluate(
        RELAXED_EndOfPath *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idInfoPath *v6; // r3

  value = ai->aiVolatile.memory.currentPath.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = (idInfoPath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idInfoPath::CastTo(c: v6) != nullptr )
  {
    return 0;
  }
  else
  {
    return 87;
  }
}


// ========================================================================
// ?Evaluate@RELAXED_ShouldFollowFriendly@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AECB88
// RVA : 0x00AECB88
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall RELAXED_ShouldFollowFriendly::Evaluate(
        RELAXED_ShouldFollowFriendly *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idRelationship::attitude_t followFriendlyThreshold; // r30
  int value; // r7
  idEntity *v8; // r3
  idEntity *v9; // r3
  const idFaction *v10; // r29
  idFaction *v11; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v13; // zf

  followFriendlyThreshold = ai->aiEditable.behaviors.decl->followFriendlyThreshold;
  value = ai->aiVolatile.memory.currentFriendly.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v8 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v8 == nullptr )
    return 0;
  v9 = idEntity::CastTo(c: v8);
  if ( v9 == nullptr )
    return 0;
  v10 = v9->GetFaction_2(this: v9);
  v11 = ai->GetFaction(this: ai);
  v13 = idFaction::GetAttitudeTowards(this: v11, otherFaction: v10) >= followFriendlyThreshold;
  result = TRANSCODE_RELAXED_SHOULD_FOLLOW_FRIENDLY;
  if ( !v13 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@RELAXED_ShouldInvestigateBody@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AECC38
// RVA : 0x00AECC38
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall RELAXED_ShouldInvestigateBody::Evaluate(
        RELAXED_ShouldInvestigateBody *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v6; // r3
  idPlayer *v7; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v9; // zf

  if ( !ai->aiEditable.behaviors.decl->investigatesBody )
    return 0;
  value = ai->aiVolatile.memory.actionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = (idPlayer *)idEntity::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  v9 = idPlayer::CastTo(c: v7) != nullptr;
  result = TRANSCODE_RELAXED_SHOULD_INVESTIGATE_BODY;
  if ( !v9 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_Work@idRelaxed_Default@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AECCC8
// RVA : 0x00AECCC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_Default::AIState_Work(idRelaxed_Default *this, idAI2 *ai, idAIFSM *fsm, const int curTime)
{
  idEncounterGroup *EncounterGroup; // r3

  if ( idAI2::GetEncounterGroup(this: ai) != nullptr )
  {
    EncounterGroup = idAI2::GetEncounterGroup(this: ai);
    if ( idEncounterGroup::AnyMemberHighestAlertCycle(this: EncounterGroup) < ALERTCYCLE_COMBAT
      && (unsigned __int8)idAI2::UseRelaxedChatterVO(this: ai) != 0 )
    {
      idAI2::GetAlertCycleFSM(this: ai);
    }
  }
}


// ========================================================================
// ?AIState_EnterState@idRelaxed_FollowPath@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AECD30
// RVA : 0x00AECD30
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_FollowPath::AIState_EnterState(
        idRelaxed_FollowPath *this,
        _exception *ai,
        idEventArg *fsm,
        const int curTime)
{
  int v7; // r8
  idInfoPath *v8; // r3
  idInfoPath *v9; // r30
  aiWalkModifier_t walkMod; // r11
  aiWalkModifier_t runMod; // r11
  double v12; // fp31
  idPhysics *Physics; // r29
  idAIMoveState *MoveInterface; // r26
  idPhysics *v15; // r3
  idAIMoveState_vtbl *v16; // r29
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v18; // r3
  idEventArg *v19; // r26
  idEventArg *v20; // r27
  idEventArg *v21; // r26
  _BYTE v22[20]; // [sp+70h] [-E0h] BYREF
  idEventReceiver v23[2]; // [sp+90h] [-C0h] BYREF
  int v24; // [sp+B0h] [-A0h]
  int v25; // [sp+B4h] [-9Ch]
  idEventArg v26; // [sp+D0h] [-80h] BYREF
  idEventArg v27; // [sp+F0h] [-60h] BYREF

  v7 = *((_DWORD *)&ai[911].name + 1);
  if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13
    && (v8 = (idInfoPath *)gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
  {
    v9 = idInfoPath::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  LOBYTE(ai[218].type) = 1;
  walkMod = v9->walkMod;
  if ( walkMod != AIWALKMOD_DEFAULT )
    LODWORD(ai[172].retval) = walkMod;
  runMod = v9->runMod;
  if ( runMod != AIWALKMOD_DEFAULT )
    ai[173].type = runMod;
  LODWORD(ai[111].arg1) = v9->standState;
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 )
    v12 = *((float *)&ai[557].arg2 + 3);
  else
    v12 = *((float *)&ai[191].arg2 + 1);
  Physics = idEntity::GetPhysics(this: v9);
  MoveInterface = idAI2::GetMoveInterface(this: (idAI2 *)ai);
  v15 = Physics;
  GetOrigin = Physics->GetOrigin;
  v16 = MoveInterface->__vftable;
  v18 = (int)GetOrigin(this: v15, a2: 0);
  if ( v16->ReachedPoint(this: MoveInterface, a2: (const idVec3 *)v18, a3: v12) )
  {
    idAI2::EndActionScript(this: (idAI2 *)ai);
    LODWORD(fsm[1].value.v[2]) = this;
    HIBYTE(v23[0].__vftable) = 105;
    HIBYTE(v24) = 105;
    v23[0].listenerList = nullptr;
    v25 = -1;
    v19 = idEventArg::idEventArg(this: &v26, data: (const idEntity *)ai);
    memcpy(Dst: v22, Src: v23, Size: sizeof(v22));
    idEventReceiver::ProcessEvent(
      this: (idEventReceiver *)&v27,
      result: fsm,
      ev: *(const idEventDef **)&v19->type,
      arg1: (const idEventArg *)LODWORD(v19->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v19->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v24, 32));
  }
  else
  {
    idAI2::EndActionScript(this: (idAI2 *)ai);
    LODWORD(fsm[1].value.v[2]) = this;
    HIBYTE(v24) = 105;
    v25 = 26;
    v20 = idEventArg::idEventArg(this: &v27, data: v9);
    v21 = idEventArg::idEventArg(this: &v26, data: (const idEntity *)ai);
    memcpy(Dst: v22, Src: v20, Size: sizeof(v22));
    idEventReceiver::ProcessEvent(
      this: v23,
      result: fsm,
      ev: *(const idEventDef **)&v21->type,
      arg1: (const idEventArg *)LODWORD(v21->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v21->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v24, 32));
  }
  if ( !v9->abortForCombat )
    BYTE1(ai[912].arg2) = 0;
  if ( !v9->abortForSearch )
    BYTE2(ai[912].arg2) = 0;
}


// ========================================================================
// ?AIState_Work@idRelaxed_FollowPath@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AECF98
// RVA : 0x00AECF98
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_FollowPath::AIState_Work(
        idRelaxed_FollowPath *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idEncounterGroup *EncounterGroup; // r3

  if ( idAI2::GetEncounterGroup(this: ai) != nullptr )
  {
    EncounterGroup = idAI2::GetEncounterGroup(this: ai);
    if ( idEncounterGroup::AnyMemberHighestAlertCycle(this: EncounterGroup) < ALERTCYCLE_COMBAT
      && curTime - idAI2::GetAlertCycleFSM(this: ai)->lastTransitionTime > 1000 )
    {
      idAI2::UseRelaxedChatterVO(this: ai);
    }
  }
}


// ========================================================================
// ?AIState_EnterState@idRelaxed_NextPathPoint@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AED010
// RVA : 0x00AED010
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_NextPathPoint::AIState_EnterState(
        idRelaxed_NextPathPoint *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idEntityPtr<idInfoPath> *p_currentPath; // r31
  int value; // r9
  idInfoPath *v9; // r3
  idInfoPath *v10; // r27
  idInfoPath *v11; // r3
  idInfoPath *v12; // r3
  bool v13; // r11
  int v14; // r8
  idInfoPath *v15; // r3
  idInfoPath *v16; // r4

  p_currentPath = &ai->aiVolatile.memory.currentPath;
  value = ai->aiVolatile.memory.currentPath.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = (idInfoPath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v10 = idInfoPath::CastTo(c: v9)) != nullptr )
  {
    if ( gameLocal->spawnIds.ptr[p_currentPath->spawnId.value & 0x1FFF] == p_currentPath->spawnId.value >> 13 )
    {
      v11 = (idInfoPath *)gameLocal->entities.ptr[p_currentPath->spawnId.value & 0x1FFF];
      if ( v11 != nullptr )
      {
        v12 = idInfoPath::CastTo(c: v11);
        if ( v12 != nullptr )
          ai->aiVolatile.script.flags = (!v12->abortForSearch ? 0 : 2) | v12->abortForCombat;
      }
    }
    v13 = v10->plugAnim.plugAnims.num != 0;
    this->hasPlugAnim = v13;
    if ( !v13 )
    {
      v14 = ai->aiVolatile.memory.nextPath.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v14 & 0x1FFF] == v14 >> 13
        && (v15 = (idInfoPath *)gameLocal->entities.ptr[v14 & 0x1FFF]) != nullptr )
      {
        v16 = idInfoPath::CastTo(c: v15);
      }
      else
      {
        v16 = nullptr;
      }
      idAIMemory::SetCurrentPath(this: &ai->aiVolatile.memory, path: v16);
      if ( v10->actionScript.num != 0 )
      {
        idAI2::SetActionScript(this: ai, script: &v10->actionScript, scriptExecutor: v10, activator: ai);
        idAI2::StartActionScript(this: ai, curTime);
      }
    }
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?AIState_EnterState@idRelaxed_RunningPlugAnim@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AED1B0
// RVA : 0x00AED1B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_RunningPlugAnim::AIState_EnterState(
        idRelaxed_RunningPlugAnim *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idInfoPath *v8; // r3
  idInfoPath *v9; // r3
  const idEntity *v10; // r30
  idEventArg *v11; // r27
  idEventArg *v12; // r31
  _BYTE v13[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v14[5]; // [sp+90h] [-B0h] BYREF
  idEventArg v15; // [sp+B0h] [-90h] BYREF
  idEventArg v16; // [sp+D0h] [-70h] BYREF
  idEventReceiver v17[6]; // [sp+F0h] [-50h] BYREF

  value = ai->aiVolatile.memory.currentPath.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = (idInfoPath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v9 = idInfoPath::CastTo(c: v8), v10 = v9, v9 != nullptr) )
  {
    if ( v9->plugAnim.plugAnims.num != 0 )
    {
      idAI2::EndActionScript(this: ai);
      LODWORD(fsm[1].value.v[2]) = this;
      HIBYTE(v14[0]) = 105;
      v14[1] = -1;
      v11 = idEventArg::idEventArg(this: &v15, data: v10);
      v12 = idEventArg::idEventArg(this: &v16, data: ai);
      memcpy(Dst: v13, Src: v14, Size: sizeof(v13));
      idEventReceiver::ProcessEvent(
        this: v17,
        result: fsm,
        ev: *(const idEventDef **)&v12->type,
        arg1: (const idEventArg *)LODWORD(v12->value.v[1]),
        arg2: (const idEventArg *)LODWORD(v12->value.v[2]),
        arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v11->type, 32));
      this->plugAnimDone = false;
    }
    else
    {
      this->plugAnimDone = true;
    }
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?AIState_ExitState@idRelaxed_RunningPlugAnim@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AED2E0
// RVA : 0x00AED2E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_RunningPlugAnim::AIState_ExitState(
        idRelaxed_RunningPlugAnim *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int value; // r8
  idInfoPath *v6; // r3
  idInfoPath *v7; // r4

  value = ai->aiVolatile.memory.nextPath.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = (idInfoPath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idInfoPath::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  idAIMemory::SetCurrentPath(this: &ai->aiVolatile.memory, path: v7);
}


// ========================================================================
// ?AIState_EnterState@idRelaxed_InvestigateBody@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AED368
// RVA : 0x00AED368
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

void __fastcall idRelaxed_InvestigateBody::AIState_EnterState(
        idRelaxed_InvestigateBody *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  idEntity *v10; // r29
  idEventArg *v11; // r20
  idEventArg *v12; // r19
  idEventArg *v13; // r3
  const idEventArg *v14; // [sp+8h] [-2B8h]
  const idEventArg *v15; // [sp+Ch] [-2B4h]
  const idEventArg *v16; // [sp+10h] [-2B0h]
  _BYTE v17[20]; // [sp+70h] [-250h] BYREF
  _BYTE v18[20]; // [sp+90h] [-230h] BYREF
  _BYTE v19[20]; // [sp+B0h] [-210h] BYREF
  _BYTE v20[20]; // [sp+D0h] [-1F0h] BYREF
  _BYTE v21[20]; // [sp+F0h] [-1D0h] BYREF
  _BYTE v22[20]; // [sp+110h] [-1B0h] BYREF
  char v23; // [sp+130h] [-190h]
  int v24; // [sp+134h] [-18Ch]
  const idEventArg *v25; // [sp+138h] [-188h]
  const idEventArg *v26; // [sp+13Ch] [-184h]
  float v27[5]; // [sp+150h] [-170h] BYREF
  _DWORD v28[5]; // [sp+170h] [-150h] BYREF
  _DWORD v29[5]; // [sp+190h] [-130h] BYREF
  float v30[5]; // [sp+1B0h] [-110h] BYREF
  _DWORD v31[5]; // [sp+1D0h] [-F0h] BYREF
  idEventArg v32; // [sp+1F0h] [-D0h] BYREF
  idEventArg v33; // [sp+210h] [-B0h] BYREF
  idEventArg v34[7]; // [sp+230h] [-90h] BYREF

  value = ai->aiVolatile.memory.actionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v10 = idEntity::CastTo(c: v9)) != nullptr )
  {
    ai->SetWalkState(this: ai, a2: WALKSTATE_RUNNING);
    HIBYTE(v31[0]) = 105;
    v30[1] = 8.0;
    v27[2] = vec3_origin.y;
    v27[3] = vec3_origin.z;
    v31[1] = 0;
    HIBYTE(v27[0]) = 118;
    HIBYTE(v29[0]) = 105;
    v29[1] = 0;
    HIBYTE(v30[0]) = 102;
    HIBYTE(v28[0]) = 105;
    v28[1] = 2;
    v23 = 105;
    v24 = 27;
    v27[1] = vec3_origin.x;
    v11 = idEventArg::idEventArg(this: v34, data: v10);
    v12 = idEventArg::idEventArg(this: &v33, data: ai);
    memcpy(Dst: v22, Src: v31, Size: sizeof(v22));
    memcpy(Dst: v21, Src: v27, Size: sizeof(v21));
    memcpy(Dst: v20, Src: v29, Size: sizeof(v20));
    memcpy(Dst: v19, Src: v30, Size: sizeof(v19));
    memcpy(Dst: v18, Src: v28, Size: sizeof(v18));
    memcpy(Dst: v17, Src: v11, Size: sizeof(v17));
    idEventReceiver::ProcessEvent(
      this: (idEventReceiver *)&v32,
      result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
      ev: *(const idEventDef **)&v12->type,
      arg1: (const idEventArg *)LODWORD(v12->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v12->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(LODWORD(v12->value.q[3]), 32),
      arg4: v25,
      arg5: v26,
      arg6: v14,
      arg7: v15,
      arg8: v16);
    v23 = 105;
    v24 = 56;
    v13 = idEventArg::idEventArg(this: &v32, data: ai);
    idEventReceiver::ProcessEvent(
      this: (idEventReceiver *)&v33,
      result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
      ev: *(const idEventDef **)&v13->type,
      arg1: (const idEventArg *)LODWORD(v13->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v13->value.v[2]));
    idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?Evaluate@RELAXED_ShouldInvestigateBodyEvent@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AED5B8
// RVA : 0x00AED5B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

int __fastcall RELAXED_ShouldInvestigateBodyEvent::Evaluate(
        RELAXED_ShouldInvestigateBodyEvent *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIEventSphere *eventData; // r31
  idAIEventSphere *v7; // r3
  idPlayer *Originator; // r3
  const idEntity *v9; // r3
  idEntityPtr<idEntity const > *p_actionEntity; // r10

  if ( parentFSM->eventId != 16 )
    return 0;
  if ( !ai->aiEditable.behaviors.decl->investigatesBody )
    return 0;
  eventData = (idAIEventSphere *)parentFSM->eventData;
  v7 = idAIEventSphere::CastTo(c: eventData);
  if ( v7 == nullptr )
    return 0;
  Originator = (idPlayer *)idAIEvent::GetOriginator(this: v7);
  if ( idPlayer::CastTo(c: Originator) == nullptr )
    return 0;
  v9 = idAIEvent::GetOriginator(this: eventData);
  p_actionEntity = &ai->aiVolatile.memory.actionEntity;
  if ( v9 != nullptr )
    p_actionEntity->spawnId.value = (gameLocal->spawnIds.ptr[v9->entityNumber] << 13) | v9->entityNumber;
  else
    p_actionEntity->spawnId.value = 0x1FFF;
  return 99;
}


// ========================================================================
// ?Evaluate@RELAXED_PlayerApproaching@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AED680
// RVA : 0x00AED680
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

int __fastcall RELAXED_PlayerApproaching::Evaluate(
        RELAXED_PlayerApproaching *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIEventSphere *eventData; // r31
  int value; // r10
  idEntity *v9; // r3
  idPlayer *v10; // r3
  idPlayer *v11; // r31
  idFiniteStateMachine *v13; // r3

  if ( parentFSM->eventId != 0x200000 )
    return 0;
  eventData = (idAIEventSphere *)parentFSM->eventData;
  if ( idAIEventSphere::CastTo(c: eventData) == nullptr )
    return 0;
  value = eventData->originator.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v10 = (idPlayer *)idEntity::CastTo(c: v9);
  }
  else
  {
    v10 = nullptr;
  }
  v11 = idPlayer::CastTo(c: v10);
  if ( (unsigned __int8)idAI2::PlayerApproachingInteraction(this: ai, player: v11) != 0 )
    return 94;
  if ( v11 != idAIEvent::GetInstigator(this: (idAIEvent *)&ai->aiVolatile.memory)
    && v11 != idAIMemory::GetNeutral(this: (idFocusInfo *)&ai->aiVolatile.memory) )
  {
    return 0;
  }
  if ( (unsigned __int8)idAI2::CanIdleTrackFriendlyTarget(this: ai, friendlyTarget: v11) == 0 )
    return 0;
  v13 = parentFSM->manager->FindFSM_3(this: parentFSM->manager, a2: &idIdleTrackFriendlyFSM::Type);
  if ( v13 == nullptr )
    return 0;
  if ( v11 != nullptr )
    v13[1].nextUpdateTime = (gameLocal->spawnIds.ptr[v11->entityNumber] << 13) | v11->entityNumber;
  else
    v13[1].nextUpdateTime = 0x1FFF;
  return 96;
}


// ========================================================================
// ?Evaluate@RELAXED_PlayerInteractDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AED7E8
// RVA : 0x00AED7E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_relaxed.cpp
// ========================================================================

int __fastcall RELAXED_PlayerInteractDone::Evaluate(
        RELAXED_PlayerInteractDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idFiniteStateMachine *v9; // r31
  idPlayer *InteractionEntity; // r3
  int entityNumber; // r11

  if ( idFile_SaveGamePipelined::GetFullPath(this: state) == 0
    || (FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state),
        idFiniteStateMachine::GetStatus(this: FullPath) == 0) )
  {
    if ( ai->aiEditable.interactions.idleTrackFriendlyDist < 0.0 )
      return 95;
    v9 = parentFSM->manager->FindFSM_3(this: parentFSM->manager, a2: &idIdleTrackFriendlyFSM::Type);
    if ( v9 != nullptr )
    {
      InteractionEntity = idAIMemory::GetInteractionEntity(this: &ai->aiVolatile.memory);
      if ( InteractionEntity != nullptr )
      {
        entityNumber = InteractionEntity->entityNumber;
        v9[1].nextUpdateTime = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
        return 96;
      }
      else
      {
        v9[1].nextUpdateTime = 0x1FFF;
        return 96;
      }
    }
  }
  return 0;
}

