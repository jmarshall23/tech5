
// ========================================================================
// ?InternalInitState@idTakeCover_Default@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AF3BD0
// RVA : 0x00AF3BD0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void __fastcall idTakeCover_Default::InternalInitState(idTakeCover_Default *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &TC_AlreadyAtCover::Type,
    nextStateType: &idTakeCover_ReachedCover::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &TC_HasValidCover::Type,
    nextStateType: &idTakeCover_MoveToCover::Type);
  idState::AddStateTransition(this, fsm, transType: &TC_NoCover::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idTakeCover_MoveToCover@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AF3C50
// RVA : 0x00AF3C50
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void __fastcall idTakeCover_MoveToCover::InternalInitState(
        idTakeCover_MoveToCover *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &TC_MoveFailedUnreachable::Type,
    nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &TC_MoveFailedObstructed::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &TC_MoveFailedStuck::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &TC_MoveFailedPathingFailed::Type,
    nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &TC_MoveFailedOther::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &TC_ReachedCover::Type,
    nextStateType: &idTakeCover_ReachedCover::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &TC_DestinationCoverCompromised::Type,
    nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idTakeCover_Dodge@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AF3D18
// RVA : 0x00AF3D18
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void __fastcall idTakeCover_Dodge::InternalInitState(idTakeCover_Dodge *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &TC_DodgeDone::Type, nextStateType: &idTakeCover_Default::Type);
}


// ========================================================================
// ?AIState_EnterState@idTakeCover_Dodge@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF3D30
// RVA : 0x00AF3D30
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void __fastcall idTakeCover_Dodge::AIState_EnterState(
        idTakeCover_Dodge *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idAI2::SetupDiveDodgeOrFlinchAction(this: ai, moveReason: 31, state: this, fsm);
}


// ========================================================================
// ?Evaluate@TC_ReachedCoverDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF3D48
// RVA : 0x00AF3D48
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall TC_ReachedCoverDone::Evaluate(
        TC_ReachedCoverDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIAction *CurrentAction; // r3
  idClass *v6; // r31
  idAIStateTransition::aiTransCode_t result; // r3
  bool v8; // zf

  CurrentAction = idAI2::GetCurrentAction(this: ai);
  v6 = CurrentAction;
  if ( CurrentAction == nullptr )
    return TRANSCODE_TC_REACHED_COVER_DONE;
  if ( (unsigned __int8)idAction_CrouchToStand::IsTypeOf(c: CurrentAction) != 0 )
    return 0;
  v8 = (unsigned __int8)idAction_StandToCrouch::IsTypeOf(c: v6) == 0;
  result = TRANSCODE_TC_REACHED_COVER_DONE;
  if ( !v8 )
    return 0;
  return result;
}


// ========================================================================
// ?InternalInitState@idTakeCover_ReachedCover@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AF3DC8
// RVA : 0x00AF3DC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void __fastcall idTakeCover_ReachedCover::InternalInitState(
        idTakeCover_ReachedCover *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &TC_ReachedCoverDone::Type,
    nextStateType: &idTakeCover_InCover::Type);
}


// ========================================================================
// ?Evaluate@TC_ReevaluateCover@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF3DE0
// RVA : 0x00AF3DE0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

int __fastcall TC_ReevaluateCover::Evaluate(
        TC_ReevaluateCover *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idState::IsChildDone(this: state) ? 0 : 0xC4;
}


// ========================================================================
// ?InternalInitState@idTakeCover_InCover@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AF3E18
// RVA : 0x00AF3E18
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void __fastcall idTakeCover_InCover::InternalInitState(idTakeCover_InCover *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &TC_StartOpenCombat::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &TC_OffCoverPoint::Type,
    nextStateType: &idTakeCover_MoveToCover::Type);
  idState::AddStateTransition(this, fsm, transType: &TC_TakeCoverDone::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &TC_ReevaluateCover::Type,
    nextStateType: &idTakeCover_ReevaluateCover::Type);
}


// ========================================================================
// ?InternalInitState@idTakeCover_ReevaluateCover@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AF3EA0
// RVA : 0x00AF3EA0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void __fastcall idTakeCover_ReevaluateCover::InternalInitState(
        idTakeCover_ReevaluateCover *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &TC_NoCover::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &TC_HasValidCover::Type, nextStateType: &idTakeCover_Default::Type);
}


// ========================================================================
// ?InitStates@idTakeCoverFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82AF3F08
// RVA : 0x00AF3F08
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void __fastcall idTakeCoverFSM::InitStates(idTakeCoverFSM *this, const idFiniteStateMachineParams *params)
{
  idAIFSM::InitStates(this, params);
  this->AddState(this, a2: &this->stateTakeCoverDefault);
  this->AddState(this, a2: &this->stateMoveToCover);
  this->AddState(this, a2: &this->stateReachedCover);
  this->AddState(this, a2: &this->stateInCover);
  this->AddState(this, a2: &this->stateReevaluateCover);
  this->AddState(this, a2: &this->stateDodge);
}


// ========================================================================
// ?Evaluate@TC_HasValidCover@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF3FC8
// RVA : 0x00AF3FC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

int __fastcall TC_HasValidCover::Evaluate(
        TC_HasValidCover *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  char v5; // r11

  if ( (ai->aiVolatile.groupStatus.condition & 0x200) != 0
    || (v5 = 1, !ai->aiVolatile.groupStatus.roleChangeResponseRequired) )
  {
    v5 = 0;
  }
  if ( v5 != 0 || (ai->aiVolatile.groupStatus.condition & 0x800) != 0 )
    return 0;
  else
    return (unsigned __int8)idAICover::IsValid(this: &ai->aiVolatile.memory.currentCover) == 0 ? 0 : 0xAC;
}


// ========================================================================
// ?Evaluate@TC_AlreadyAtCover@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF4068
// RVA : 0x00AF4068
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall TC_AlreadyAtCover::Evaluate(
        TC_AlreadyAtCover *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  char v6; // r11
  const aas2Cover_t *Origin; // r30
  idPhysics *Physics; // r29
  idAIMoveState *MoveInterface; // r28
  idAIMoveState_vtbl *v10; // r31
  double v11; // fp31
  int v12; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v14; // zf

  if ( (ai->aiVolatile.groupStatus.condition & 0x200) != 0
    || (v6 = 1, !ai->aiVolatile.groupStatus.roleChangeResponseRequired) )
  {
    v6 = 0;
  }
  if ( v6 != 0 )
    return 0;
  if ( (ai->aiVolatile.groupStatus.condition & 0x800) != 0 )
    return 0;
  if ( (unsigned __int8)idAICover::IsValid(this: &ai->aiVolatile.memory.currentCover) == 0 )
    return 0;
  Origin = idAICover::GetOrigin(this: &ai->aiVolatile.memory.currentCover);
  Physics = idEntity::GetPhysics(this: ai);
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v10 = MoveInterface->__vftable;
  v11 = REACHED_COVER_LERP_TOLERANCE;
  v12 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v14 = ((unsigned __int8 (__fastcall *)(idAIMoveState *, const aas2Cover_t *, int, double))v10->PointInMovementRange)(
          a1: MoveInterface,
          a2: Origin,
          a3: v12,
          a4: v11) != 0;
  result = TRANSCODE_TC_ALREADY_AT_COVER;
  if ( !v14 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idTakeCover_Default@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF4170
// RVA : 0x00AF4170
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void __fastcall idTakeCover_Default::AIState_EnterState(
        idTakeCover_Default *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  ai->aiVolatile.animation.subWeb = AISUBWEB_COMBAT;
  idAI2::ReserveCover(this: ai, cover: &ai->aiVolatile.memory.cachedCover);
}


// ========================================================================
// ?Evaluate@TC_ReachedCover@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF4198
// RVA : 0x00AF4198
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

int __fastcall TC_ReachedCover::Evaluate(
        TC_ReachedCover *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  if ( ai_unstuckCover.valueInteger != 0 )
  {
    idCVar::SetBool(this: &ai_unstuckCover, newValue: false, force: true);
    return 173;
  }
  if ( idAI2::IsMoveDone(this: ai, checkAlignment: false) )
    return 173;
  return idFile_SaveGamePipelined::GetFullPath(this: state) != 0 ? 0 : 0xAD;
}


// ========================================================================
// ?Evaluate@TC_MoveFailedObstructed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF4228
// RVA : 0x00AF4228
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall TC_MoveFailedObstructed::Evaluate(
        TC_MoveFailedObstructed *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idFiniteStateMachine *v6; // r31
  idAIStateTransition::aiTransCode_t result; // r3

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  v6 = FullPath;
  if ( FullPath == nullptr )
    return 0;
  if ( (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) == 0 )
    return 0;
  result = TRANSCODE_TC_COVER_BLOCKED;
  if ( v6->errorTransCode != 10 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@TC_MoveFailedUnreachable@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF4288
// RVA : 0x00AF4288
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall TC_MoveFailedUnreachable::Evaluate(
        TC_MoveFailedUnreachable *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idFiniteStateMachine *v6; // r31
  idAIStateTransition::aiTransCode_t result; // r3

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  v6 = FullPath;
  if ( FullPath == nullptr )
    return 0;
  if ( (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) == 0 )
    return 0;
  result = TRANSCODE_TC_COVER_BLOCKED;
  if ( v6->errorTransCode != 14 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@TC_MoveFailedStuck@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF42E8
// RVA : 0x00AF42E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall TC_MoveFailedStuck::Evaluate(
        TC_MoveFailedStuck *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idFiniteStateMachine *v6; // r31
  idAIStateTransition::aiTransCode_t result; // r3

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  v6 = FullPath;
  if ( FullPath == nullptr )
    return 0;
  if ( (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) == 0 )
    return 0;
  result = TRANSCODE_TC_COVER_BLOCKED;
  if ( v6->errorTransCode != 20 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@TC_MoveFailedPathingFailed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF4348
// RVA : 0x00AF4348
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall TC_MoveFailedPathingFailed::Evaluate(
        TC_MoveFailedPathingFailed *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idFiniteStateMachine *v6; // r31
  idAIStateTransition::aiTransCode_t result; // r3

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  v6 = FullPath;
  if ( FullPath == nullptr )
    return 0;
  if ( (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) == 0 )
    return 0;
  result = TRANSCODE_TC_COVER_BLOCKED;
  if ( v6->errorTransCode != 16 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@TC_MoveFailedOther@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF43A8
// RVA : 0x00AF43A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall TC_MoveFailedOther::Evaluate(
        TC_MoveFailedOther *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idFiniteStateMachine *v6; // r31
  int errorTransCode; // r11
  idAIStateTransition::aiTransCode_t result; // r3

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  v6 = FullPath;
  if ( FullPath == nullptr )
    return 0;
  if ( (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) == 0 )
    return 0;
  errorTransCode = v6->errorTransCode;
  if ( errorTransCode < 9 )
    return 0;
  result = TRANSCODE_TC_COVER_BLOCKED;
  if ( errorTransCode > 20 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_ExitState@idTakeCover_MoveToCover@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF4410
// RVA : 0x00AF4410
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void __fastcall idTakeCover_MoveToCover::AIState_ExitState(
        idTakeCover_MoveToCover *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int lastTransitionCode; // r11
  idAICover *p_currentCover; // r3
  int *p_coverExposedTime; // r30

  lastTransitionCode = fsm->lastTransitionCode;
  p_currentCover = &ai->aiVolatile.memory.currentCover;
  if ( lastTransitionCode > 175 )
  {
    if ( lastTransitionCode == 197 || lastTransitionCode > 299 && lastTransitionCode <= 308 )
      goto LABEL_15;
  }
  else
  {
    if ( lastTransitionCode != 175 )
    {
      if ( lastTransitionCode <= 0 )
        return;
      if ( lastTransitionCode > 2 )
      {
        if ( lastTransitionCode == 174 )
        {
          idAICover::MakeUnusable(this: p_currentCover, duration: 5000);
          idAI2::ReleaseCover(this: ai);
        }
        return;
      }
LABEL_15:
      idAI2::ReleaseCover(this: ai);
      return;
    }
    idAICover::MakeUnusable(this: p_currentCover, duration: 2500);
    idAI2::ReleaseCover(this: ai);
    p_coverExposedTime = &ai->aiVolatile.memory.coverExposedTime;
    if ( ai->aiVolatile.memory.coverExposedTime >= 0
      && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - *p_coverExposedTime < ai->aiEditable.behaviors.decl->repeatExposeCoverChargeTime
      && (*((_BYTE *)&ai->aiEditable.cover + 8) & 0x80) == 0 )
    {
      ai->aiVolatile.groupStatus.condition |= 0x800u;
    }
    *p_coverExposedTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  }
}


// ========================================================================
// ?AIState_ExitState@idTakeCover_ReachedCover@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF4528
// RVA : 0x00AF4528
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void __fastcall idTakeCover_ReachedCover::AIState_ExitState(
        idTakeCover_ReachedCover *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  ai->aiVolatile.memory.flags &= ~1u;
  if ( fsm->lastTransitionCode == 178 )
    idAIMemory::SetInvalidCover(
      this: &ai->aiVolatile.memory,
      cover: &ai->aiVolatile.memory.currentCover,
      unusableTime: 2500);
}


// ========================================================================
// ?Evaluate@TC_StartOpenCombat@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF4560
// RVA : 0x00AF4560
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

int __fastcall TC_StartOpenCombat::Evaluate(
        TC_StartOpenCombat *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  char v6; // r11
  int endOpenCombatTime; // r31

  if ( (ai->aiVolatile.groupStatus.condition & 0x200) != 0
    || (v6 = 1, !ai->aiVolatile.groupStatus.roleChangeResponseRequired) )
  {
    v6 = 0;
  }
  if ( v6 != 0 || (ai->aiVolatile.groupStatus.condition & 0x800) != 0 )
    return 197;
  if ( idState::IsChildDone(this: state) )
  {
    endOpenCombatTime = ai->aiVolatile.memory.endOpenCombatTime;
    if ( endOpenCombatTime > idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
      return 194;
  }
  return 0;
}


// ========================================================================
// ?Evaluate@TC_TakeCoverDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF4650
// RVA : 0x00AF4650
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall TC_TakeCoverDone::Evaluate(
        TC_TakeCoverDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  idAIStateTransition::aiTransCode_t result; // r3

  if ( !idState::IsChildDone(this: state) )
    return 0;
  if ( (unsigned __int8)idAICover::IsValid(this: &ai->aiVolatile.memory.currentCover) == 0
    && (unsigned __int8)idAICover::IsValid(this: &ai->aiVolatile.memory.cachedCover) == 0 )
  {
    return TRANSCODE_TC_TAKE_COVER_DONE;
  }
  result = TRANSCODE_TC_TAKE_COVER_DONE;
  if ( curTime < ai->aiVolatile.memory.exitCoverTime )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@TC_OffCoverPoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF46F0
// RVA : 0x00AF46F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall TC_OffCoverPoint::Evaluate(
        TC_OffCoverPoint *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAICover *p_currentCover; // r30
  idPhysics *Physics; // r29
  idAIMoveState *MoveInterface; // r28
  idAIMoveState_vtbl *v9; // r31
  double v10; // fp31
  int v11; // r29
  const aas2Cover_t *Origin; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v14; // zf

  if ( !idState::IsChildDone(this: state) )
    return 0;
  p_currentCover = &ai->aiVolatile.memory.currentCover;
  if ( (unsigned __int8)idAICover::IsValid(this: &ai->aiVolatile.memory.currentCover) == 0 )
    return 0;
  Physics = idEntity::GetPhysics(this: ai);
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v9 = MoveInterface->__vftable;
  v10 = REACHED_COVER_TOLERANCE;
  v11 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  Origin = idAICover::GetOrigin(this: p_currentCover);
  v14 = ((unsigned __int8 (__fastcall *)(idAIMoveState *, const aas2Cover_t *, int, double))v9->PointInMovementRange)(
          a1: MoveInterface,
          a2: Origin,
          a3: v11,
          a4: v10) == 0;
  result = TRANSCODE_TC_OFF_COVER_POINT;
  if ( !v14 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_ExitState@idTakeCover_InCover@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF47C0
// RVA : 0x00AF47C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void __fastcall idTakeCover_InCover::AIState_ExitState(
        idTakeCover_InCover *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  ai->aiVolatile.animation.subWeb = AISUBWEB_COMBAT;
}


// ========================================================================
// ??0idTakeCoverFSM@@QAA@XZ
// EA  : 0x82AF47E0
// RVA : 0x00AF47E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

idTakeCoverFSM *__fastcall idTakeCoverFSM::idTakeCoverFSM(idTakeCoverFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: "FSM_takeCover");
  this->__vftable = (idTakeCoverFSM_vtbl *)&idTakeCoverFSM::`vftable';
  idState::idState(
    this: &this->stateTakeCoverDefault,
    stateType: &idTakeCover_Default::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateTakeCoverDefault.__vftable = (idTakeCover_Default_vtbl *)&idTakeCover_Default::`vftable';
  idState::idState(
    this: &this->stateMoveToCover,
    stateType: &idTakeCover_MoveToCover::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveToCover.__vftable = (idTakeCover_MoveToCover_vtbl *)&idTakeCover_MoveToCover::`vftable';
  idState::idState(
    this: &this->stateReachedCover,
    stateType: &idTakeCover_ReachedCover::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateReachedCover.__vftable = (idTakeCover_ReachedCover_vtbl *)&idTakeCover_ReachedCover::`vftable';
  idState::idState(
    this: &this->stateInCover,
    stateType: &idTakeCover_InCover::Type,
    childFSMType: &idInCoverFSM::Type,
    flags: 0);
  this->stateInCover.__vftable = (idTakeCover_InCover_vtbl *)&idTakeCover_InCover::`vftable';
  idState::idState(
    this: &this->stateReevaluateCover,
    stateType: &idTakeCover_ReevaluateCover::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateReevaluateCover.__vftable = (idTakeCover_ReevaluateCover_vtbl *)&idTakeCover_ReevaluateCover::`vftable';
  idState::idState(this: &this->stateDodge, stateType: &idTakeCover_Dodge::Type, childFSMType: nullptr, flags: 0);
  this->stateDodge.__vftable = (idTakeCover_Dodge_vtbl *)&idTakeCover_Dodge::`vftable';
  idFiniteStateMachine::SetDefaultState(this, state: &this->stateTakeCoverDefault);
  return this;
}


// ========================================================================
// __unwind$489202
// EA  : 0x82AF490C
// RVA : 0x00AF490C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_489202()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489203
// EA  : 0x82AF4934
// RVA : 0x00AF4934
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_489203()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$489204
// EA  : 0x82AF4960
// RVA : 0x00AF4960
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_489204()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$489205
// EA  : 0x82AF498C
// RVA : 0x00AF498C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_489205()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// __unwind$489206
// EA  : 0x82AF49B8
// RVA : 0x00AF49B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_489206()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 192));
}


// ========================================================================
// __unwind$489207
// EA  : 0x82AF49E4
// RVA : 0x00AF49E4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_489207()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 220));
}


// ========================================================================
// __unwind$489208
// EA  : 0x82AF4A10
// RVA : 0x00AF4A10
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_489208()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 248));
}


// ========================================================================
// ??1idTakeCoverFSM@@UAA@XZ
// EA  : 0x82AF4A48
// RVA : 0x00AF4A48
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void __fastcall idTakeCoverFSM::~idTakeCoverFSM(idTakeCoverFSM *this)
{
  this->__vftable = (idTakeCoverFSM_vtbl *)&idTakeCoverFSM::`vftable';
  idState::~idState(this: &this->stateDodge);
  idState::~idState(this: &this->stateReevaluateCover);
  idState::~idState(this: &this->stateInCover);
  idState::~idState(this: &this->stateReachedCover);
  idState::~idState(this: &this->stateMoveToCover);
  idState::~idState(this: &this->stateTakeCoverDefault);
  idFiniteStateMachine::~idFiniteStateMachine(this);
}


// ========================================================================
// __unwind$489325
// EA  : 0x82AF4AC4
// RVA : 0x00AF4AC4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_489325()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489326
// EA  : 0x82AF4AEC
// RVA : 0x00AF4AEC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_489326()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// __unwind$489327
// EA  : 0x82AF4B18
// RVA : 0x00AF4B18
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_489327()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$489328
// EA  : 0x82AF4B44
// RVA : 0x00AF4B44
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_489328()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// __unwind$489329
// EA  : 0x82AF4B70
// RVA : 0x00AF4B70
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_489329()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 192));
}


// ========================================================================
// __unwind$489330
// EA  : 0x82AF4B9C
// RVA : 0x00AF4B9C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_489330()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 220));
}


// ========================================================================
// ?Evaluate@TC_NoCover@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF4BC8
// RVA : 0x00AF4BC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall TC_NoCover::Evaluate(
        TC_NoCover *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idPhysics *Physics; // r3
  const idVec3 *v7; // r30
  idCombatStage *CurrentCombatStage; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  char v10; // r11
  idVec3 v11[2]; // [sp+50h] [-30h] BYREF

  if ( state->enterFailed || (unsigned __int8)idAICover::IsValid(this: &ai->aiVolatile.memory.currentCover) == 0 )
    return TRANSCODE_TC_NO_COVER;
  if ( ai->aiHealth.components[1].max > 0.0
    && ai->aiHealth.components[1].cur <= 0.0
    && idAI2::GetCurrentCombatStage(this: ai) != nullptr )
  {
    Physics = idEntity::GetPhysics(this: ai);
    v7 = Physics->GetOrigin(this: Physics, a2: 0);
    CurrentCombatStage = idAI2::GetCurrentCombatStage(this: ai);
    if ( (unsigned __int8)idCombatStage::GetClosestHintNodePos(
                            this: CurrentCombatStage,
                            hintType: 6u,
                            currentPos: v7,
                            outPos: v11,
                            hintClass: CLASS_ALL) != 0 )
      return TRANSCODE_OC_SHOULD_MOVE_TO_RECHARGE;
  }
  if ( (ai->aiVolatile.groupStatus.condition & 0x200) != 0
    || (v10 = 1, !ai->aiVolatile.groupStatus.roleChangeResponseRequired) )
  {
    v10 = 0;
  }
  if ( v10 != 0 )
    return TRANSCODE_TC_NO_COVER;
  result = 0;
  if ( (ai->aiVolatile.groupStatus.condition & 0x800) != 0 )
    return TRANSCODE_TC_NO_COVER;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idTakeCover_MoveToCover@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF4D08
// RVA : 0x00AF4D08
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void __fastcall idTakeCover_MoveToCover::AIState_EnterState(
        idTakeCover_MoveToCover *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idAICover *p_currentCover; // r29
  idAIMoveState *v7; // r3
  unsigned int v8; // r3
  idAIMoveState *MoveInterface; // r3

  p_currentCover = &ai->aiVolatile.memory.currentCover;
  ai->aiVolatile.animation.subWeb = AISUBWEB_COMBAT;
  if ( (unsigned __int8)idAI2::StartMoveToCover(
                          this: ai,
                          cover: &ai->aiVolatile.memory.currentCover,
                          fsm,
                          state: this,
                          allowWalk: true,
                          curTime) != 0 )
  {
    if ( p_currentCover->spawnId.value == 0x1FFF
      || (*(_BYTE *)&ai->aiEditable.behaviors.decl->dynamicCoverCaps & 0x40) == 0 )
    {
      MoveInterface = idAI2::GetMoveInterface(this: ai);
      MoveInterface->GetLastTravelTime(this: MoveInterface);
    }
    else
    {
      v7 = idAI2::GetMoveInterface(this: ai);
      if ( v7->GetLastTravelTime(this: v7) > 500 )
      {
        v8 = 1664525 * clientGame->random.seed + 1013904223;
        clientGame->random.seed = v8;
        if ( ((v8 >> 10) & 0x7FFF) % 0x64 >= 0x32 )
          idAI2::GetEncounterGroup(this: ai);
      }
    }
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?Evaluate@TC_DestinationCoverCompromised@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF4E90
// RVA : 0x00AF4E90
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall TC_DestinationCoverCompromised::Evaluate(
        TC_DestinationCoverCompromised *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  idAI2 *Reserver; // r3
  const idEntity *Enemy; // r3
  idAIEntityState *v10; // r3
  aiSenseState_t *EnemySenseState; // r30
  double v12; // fp31
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  idPhysics *Physics; // r3
  float *v15; // r29
  const aiPhysicalState_t *v16; // r3
  double v17; // fp8
  double v18; // fp6
  double v19; // fp1

  MoveInterface = idAI2::GetMoveInterface(this: ai);
  if ( MoveInterface->IsPlayingTraversalAnim(this: MoveInterface) )
    return 0;
  if ( (unsigned __int8)idAICover::IsValid(this: &ai->aiVolatile.memory.currentCover) != 0 )
  {
    Reserver = (idAI2 *)idAICover::GetReserver(this: &ai->aiVolatile.memory.currentCover);
    if ( Reserver == nullptr || Reserver == ai )
    {
      Enemy = idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
      v10 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: Enemy);
      if ( v10 == nullptr )
        return 0;
      if ( v10->senses.ptr[1]->lastUnconfirmedStimTime < 0 )
        return 0;
      EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
      if ( EnemySenseState == nullptr
        || idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
         - EnemySenseState->lastConfirmedStimTime >= 5000 )
      {
        return 0;
      }
      v12 = idCoverQuery::MAX_COVER_ARC_ACOS_DEGREES;
      ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
      if ( idAICover::IsPointInArc(
             this: &ai->aiVolatile.memory.currentCover,
             point: &ConfirmedPhysicalSafe->origin,
             arcAcos: v12) )
      {
        if ( ai->aiVolatile.memory.enemyPathBlocked )
          return 0;
        Physics = idEntity::GetPhysics(this: ai);
        v15 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v16 = aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
        v17 = (float)(v16->origin.z - v15[2]);
        v18 = (float)(v16->origin.y - v15[1]);
        v19 = (float)((float)((float)v18 * (float)v18)
                    + (float)((float)((float)v17 * (float)v17)
                            + (float)((float)(v16->origin.x - *v15) * (float)(v16->origin.x - *v15))));
        result = TRANSCODE_TC_DESTINATION_COVER_COMPROMISED;
        if ( v19 >= (float)(ai->aiEditable.behaviors.decl->exposeCoverMinDistance
                          * ai->aiEditable.behaviors.decl->exposeCoverMinDistance) )
          return 0;
        return result;
      }
    }
  }
  return TRANSCODE_TC_DESTINATION_COVER_COMPROMISED;
}


// ========================================================================
// ?Evaluate@TC_EnemyNotOnLeanSide@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF5040
// RVA : 0x00AF5040
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall TC_EnemyNotOnLeanSide::Evaluate(
        TC_EnemyNotOnLeanSide *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r4
  idAIEntityState *v9; // r3
  aiSenseState_t *v10; // r31
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v13; // zf

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
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
  v10 = v9->senses.ptr[1];
  if ( v10->lastUnconfirmedStimTime < 0 )
    return 0;
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
     - v10->lastConfirmedStimTime >= 5000 )
    return 0;
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v10);
  v13 = (unsigned __int8)idAICover::IsPointOnLeanSide(
                           this: &ai->aiVolatile.memory.currentCover,
                           point: &ConfirmedPhysicalSafe->origin) == 0;
  result = TRANSCODE_TC_ENEMY_NOT_ON_LEAN_SIDE;
  if ( !v13 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idTakeCover_ReachedCover@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF5138
// RVA : 0x00AF5138
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void __fastcall idTakeCover_ReachedCover::AIState_EnterState(
        idTakeCover_ReachedCover *this,
        idAI2 *ai,
        idEventArg *fsm,
        int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r4
  int v10; // r27
  double v11; // fp31
  const aas2Cover_t *Origin; // r3
  int v13; // r6
  int v14; // r5
  unsigned int CoverPosture; // r3
  idEventArg *v16; // r11
  idEventReceiver *v17; // r3
  idEventArg v18; // [sp+50h] [-B0h] BYREF
  char v19; // [sp+70h] [-90h] BYREF
  idEventArg v20; // [sp+90h] [-70h] BYREF
  char v21; // [sp+B0h] [-50h] BYREF

  idAIMemory::SetReachedCoverTime(this: &ai->aiVolatile.memory, curTime);
  if ( ai->aiVolatile.cover.coverOrientation == COVERORIENT_BACKWARD )
  {
    idAI2::ClearAimFocus(this: ai);
    idAI2::ClearLookFocus(this: ai);
    idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
  }
  else
  {
    value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v9 = idEntity::CastTo(c: v8);
    }
    else
    {
      v9 = nullptr;
    }
    idAI2::SetAimFocusEntity(this: ai, ent: v9, keepFocusInView: false, aimPoint: AIMPOINT_BEST, timeout: -1);
  }
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) == 0 )
  {
    v10 = GameFramesToTicks(frameNum: 10, type: GAMETIME_SCALED);
    v11 = REACHED_COVER_LERP_TOLERANCE;
    Origin = idAICover::GetOrigin(this: &ai->aiVolatile.memory.currentCover);
    idAIMoveState::StartLerpToPoint(
      this: &ai->aiVolatile.physics.moveState,
      dest: &Origin->origin,
      tolerance: 0.1,
      maxLerpDist: v11,
      lerpDurationMS: v14,
      lerpAxisFlags_: v13,
      a7: v10,
      a8: 3);
  }
  CoverPosture = idAICover::GetCoverPosture(this: &ai->aiVolatile.memory.currentCover);
  if ( CoverPosture == 0 )
  {
LABEL_13:
    if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED )
      return;
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    v16 = idEventArg::idEventArg(this: &v20, data: ai);
    v17 = (idEventReceiver *)&v21;
    goto LABEL_15;
  }
  if ( CoverPosture != 1 )
  {
    if ( CoverPosture >= 3 )
      return;
    goto LABEL_13;
  }
  if ( ai->GetPosture(this: ai) != POSTURE_STANDING )
  {
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    v16 = idEventArg::idEventArg(this: &v18, data: ai);
    v17 = (idEventReceiver *)&v19;
LABEL_15:
    idEventReceiver::ProcessEvent(
      this: v17,
      result: fsm,
      ev: *(const idEventDef **)&v16->type,
      arg1: (const idEventArg *)v16->value.i);
  }
}


// ========================================================================
// ?AIState_EnterState@idTakeCover_ReevaluateCover@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF5340
// RVA : 0x00AF5340
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void __fastcall idTakeCover_ReevaluateCover::AIState_EnterState(
        idTakeCover_ReevaluateCover *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAICover *p_invalidCover; // r29
  idPhysics *Physics; // r3
  const idVec3 *v7; // r3
  idList<idVehicleState *,5> v8; // [sp+50h] [-120h] BYREF
  bfx::BinaryReplayLogOut v9[9]; // [sp+60h] [-110h] BYREF

  p_invalidCover = &ai->aiVolatile.memory.invalidCover;
  idCoverQuery::idCoverQuery(
    this: (idCoverQuery *)&v9[0].m_buf.m_size,
    ai,
    exclude: &ai->aiVolatile.memory.invalidCover,
    flags: 31);
  v9[0].m_buf.m_size = (int)&idCoverQueryTakeCover::`vftable';
  idAICover::idAICover(this: p_invalidCover);
  idAI2::ReleaseCover(this: ai);
  memset(&v8, 0, 14);
  *(_WORD *)&v8.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v8);
  idAI2::GetKnownEnemiesAsCoverTargets(this: ai, targets: &v8, minAwareness: AIAWARE_UNAWARE);
  idAICover::idAICover(this: (idAICover *)v9);
  Physics = idEntity::GetPhysics(this: ai);
  v7 = Physics->GetOrigin(this: Physics, a2: 0);
  if ( (unsigned __int8)idCoverQuery::Execute(
                          this: (idCoverQuery *)&v9[0].m_buf.m_size,
                          targets: (const idList<idCoverQuery::coverTarget_t,5> *)&v8,
                          referencePoint: v7,
                          bestCover: (idAICover *)v9,
                          inAvoid: false) != 0
    && (unsigned __int8)idAICover::IsValid(this: (idAICover *)v9) != 0 )
  {
    idAICover::operator=(this: &ai->aiVolatile.memory.cachedCover, other: (const idAICover *)v9);
    idAI2::ReserveCover(this: ai, cover: (idAICover *)v9);
  }
  else
  {
    ai->aiVolatile.focus.enableBodyRotation = true;
  }
  idPhysics_StaticMulti::UpdateTime(this: v9);
  idList<idThread *,58>::Clear(this: &v8);
  idCoverQuery::~idCoverQuery(this: (idCoverQuery *)&v9[0].m_buf.m_size);
}


// ========================================================================
// __unwind$490341
// EA  : 0x82AF5464
// RVA : 0x00AF5464
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_490341()
{
  int v0; // r12

  idCoverQueryTakeCover::~idCoverQueryTakeCover(this: (idCoverQueryClosest *)(v0 - 368 + 112));
}


// ========================================================================
// __unwind$490342
// EA  : 0x82AF548C
// RVA : 0x00AF548C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_490342()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 368 + 80));
}


// ========================================================================
// __unwind$490343
// EA  : 0x82AF54B4
// RVA : 0x00AF54B4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_490343()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 368 + 96));
}


// ========================================================================
// ?CanUse@idTakeCoverFSM@@UBA_NPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AF54E8
// RVA : 0x00AF54E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

int __fastcall idTakeCoverFSM::CanUse(idTakeCoverFSM *this, idFiniteStateMachine *fsm, const int curTime)
{
  idAI2 *Owner; // r3
  idAI2 *v4; // r30
  int setting; // r28
  int v6; // r29
  aiSkill_t ModifiedSkill; // r3
  char v8; // r11
  int value; // r8
  idEntity *v10; // r3
  idAI2 *v11; // r28
  idAIMoveState *MoveInterface; // r3
  idAI2 *v13; // r29
  idPlayer *v14; // r3
  idProp_WeaponStatic *UsedProp; // r3
  idWeapon *v16; // r3
  idEncounterGroup *EncounterGroup; // r3
  idPhysics *Physics; // r3
  const idVec3 *v19; // r29
  idCombatStage *CurrentCombatStage; // r3
  char v21; // r11
  idTurret *v22; // r29
  idPhysics *v23; // r27
  idPhysics *v24; // r28
  float *v25; // r27
  float *v26; // r3
  double v27; // fp30
  double v28; // fp29
  double v29; // fp28
  idPhysics *v30; // r3
  const idVec3 *v31; // r3
  bfx::BinaryReplayLogOut v33; // [sp+50h] [-170h] BYREF
  idList<idDeclVehicleUpgrade const *,5> v34; // [sp+70h] [-150h] BYREF
  idVec3 v35; // [sp+80h] [-140h] BYREF
  idCoverQuery v36; // [sp+90h] [-130h] BYREF

  Owner = (idAI2 *)idFiniteStateMachine::GetOwner(this: fsm);
  v4 = idAI2::CastTo(c: Owner);
  setting = (int)v4->aiEditable.behaviors.decl->takeCoverBehaviors.usesForwardCover.setting;
  if ( *(_BYTE *)(idAI2::GetModifiedSkill(this: v4) + setting) != 0
    || (v6 = (int)v4->aiEditable.behaviors.decl->takeCoverBehaviors.usesBackwardCover.setting,
        ModifiedSkill = idAI2::GetModifiedSkill(this: v4),
        v8 = 0,
        *(_BYTE *)(ModifiedSkill + v6) != 0) )
  {
    v8 = 1;
  }
  if ( v8 == 0 )
    return 0;
  if ( v4->aiEditable.movement.turretMode )
    return 0;
  value = v4->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v10 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v10 == nullptr )
    return 0;
  v11 = (idAI2 *)idEntity::CastTo(c: v10);
  if ( v11 == nullptr )
    return 0;
  MoveInterface = idAI2::GetMoveInterface(this: v4);
  v33.m_buf.m_data = (unsigned __int8 *)2000;
  if ( MoveInterface->RecentlyFailedMove(
         this: MoveInterface,
         a2: AIMOVEREASON_COVER,
         a3: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&v33.m_buf) )
  {
    return 0;
  }
  v13 = idAI2::CastTo(c: v11);
  v14 = idPlayer::CastTo(c: (idPlayer *)v11);
  if ( v13 != nullptr && v14 == nullptr )
  {
    UsedProp = (idProp_WeaponStatic *)idAIMemory::GetUsedProp(this: &v4->aiVolatile.memory);
    if ( idProp_WeaponStatic::CastTo(c: UsedProp) == nullptr )
    {
      v16 = v4->GetEquippedWeapon(this: v4);
      if ( v16 != nullptr && idWeapon::IsMelee(this: v16) )
        return 0;
    }
  }
  if ( idAI2::GetEncounterGroup(this: v4) == nullptr
    || (EncounterGroup = idAI2::GetEncounterGroup(this: v4), !idEncounterGroup::GetShouldAmbush(this: EncounterGroup)) )
  {
    if ( (unsigned __int8)idAI2::EnemyTooCloseToGoProne(this: v4, facingMatters: true, obscurityMatters: false) != 0 )
      return 0;
  }
  if ( v4->aiHealth.components[1].max > 0.0
    && v4->aiHealth.components[1].cur <= 0.0
    && idAI2::GetCurrentCombatStage(this: v4) != nullptr )
  {
    Physics = idEntity::GetPhysics(this: v4);
    v19 = Physics->GetOrigin(this: Physics, a2: 0);
    CurrentCombatStage = idAI2::GetCurrentCombatStage(this: v4);
    if ( (unsigned __int8)idCombatStage::GetClosestHintNodePos(
                            this: CurrentCombatStage,
                            hintType: 6u,
                            currentPos: v19,
                            outPos: &v35,
                            hintClass: CLASS_ALL) != 0 )
      return 0;
  }
  if ( (v4->aiVolatile.groupStatus.condition & 0x200) != 0
    || (v21 = 1, !v4->aiVolatile.groupStatus.roleChangeResponseRequired) )
  {
    v21 = 0;
  }
  if ( v21 != 0 )
    return 0;
  if ( (v4->aiVolatile.groupStatus.condition & 0x800) != 0 )
    return 0;
  v22 = idTurret::CastTo(c: (idTurret *)v11);
  if ( v22 != nullptr )
  {
    v23 = idEntity::GetPhysics(this: v4);
    v24 = idEntity::GetPhysics(this: v11);
    v25 = (float *)v23->GetOrigin(this: v23, a2: 0);
    v26 = (float *)v24->GetOrigin(this: v24, a2: 0);
    v27 = (float)(v26[2] - v25[2]);
    v28 = (float)(v26[1] - v25[1]);
    v29 = (float)(*v26 - *v25);
    idTurret::GetMuzzleDirection(this: v22, dir: (idVec3 *)&v33.m_buf.m_size);
    if ( (float)((float)((float)v28 * *(float *)&v33.m_buf.m_cap)
               + (float)((float)(*(float *)&v33.m_buf.m_size * (float)v29)
                       + (float)(*(float *)&v33.m_buf.m_tag * (float)v27))) < 0.0 )
      return 0;
  }
  idCoverQuery::idCoverQuery(this: &v36, ai: v4, exclude: &v4->aiVolatile.memory.invalidCover, flags: 31);
  v36.__vftable = (idCoverQuery_vtbl *)&idCoverQueryTakeCover::`vftable';
  idAICover::idAICover(this: &v4->aiVolatile.memory.invalidCover);
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v34);
  idAI2::GetKnownEnemiesAsCoverTargets(
    this: v4,
    targets: (idList<idVehicleState *,5> *)&v34,
    minAwareness: AIAWARE_UNAWARE);
  idAICover::idAICover(this: (idAICover *)&v33);
  v30 = idEntity::GetPhysics(this: v4);
  v31 = v30->GetOrigin(this: v30, a2: 0);
  if ( (unsigned __int8)idCoverQuery::Execute(
                          this: &v36,
                          targets: (const idList<idCoverQuery::coverTarget_t,5> *)&v34,
                          referencePoint: v31,
                          bestCover: (idAICover *)&v33,
                          inAvoid: false) != 0
    && (unsigned __int8)idAICover::IsValid(this: (idAICover *)&v33) != 0 )
  {
    idAICover::operator=(this: &v4->aiVolatile.memory.cachedCover, other: (const idAICover *)&v33);
  }
  if ( (unsigned __int8)idAICover::IsValid(this: (idAICover *)&v33) == 0 )
  {
    idPhysics_StaticMulti::UpdateTime(this: &v33);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v34);
    idCoverQuery::~idCoverQuery(this: &v36);
    return 0;
  }
  idPhysics_StaticMulti::UpdateTime(this: &v33);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v34);
  idCoverQuery::~idCoverQuery(this: &v36);
  return 1;
}


// ========================================================================
// __unwind$490416
// EA  : 0x82AF593C
// RVA : 0x00AF593C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_490416()
{
  int v0; // r12

  idCoverQueryTakeCover::~idCoverQueryTakeCover(this: (idCoverQueryClosest *)(v0 - 448 + 144));
}


// ========================================================================
// __unwind$490417
// EA  : 0x82AF5964
// RVA : 0x00AF5964
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_490417()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 448 + 112));
}


// ========================================================================
// __unwind$490418
// EA  : 0x82AF598C
// RVA : 0x00AF598C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void _unwind_490418()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 448 + 80));
}


// ========================================================================
// `dynamic initializer for 'ai_unstuckCover''
// EA  : 0x833697E0
// RVA : 0x013697E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_takecover.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_unstuckCover__()
{
  idCVar::idCVar(
    this: &ai_unstuckCover,
    name: "ai_unstuckCover",
    value: "0",
    flags: 1,
    description: "1 = forces TC_ReachedCover transition to be true so AI get unstuck, auto resets to 0",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_unstuckCover__);
}

