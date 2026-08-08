
// ========================================================================
// ?Evaluate@ReachedPoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82A9E048
// RVA : 0x00A9E048
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall ReachedPoint::Evaluate(
        ReachedPoint *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::IsMoveDone(this: ai, checkAlignment: false) ? 0 : 0x1A;
}


// ========================================================================
// ?Evaluate@MoveFailed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82A9E088
// RVA : 0x00A9E088
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall MoveFailed::Evaluate(
        MoveFailed *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAI2 *v6; // r3
  idAIMoveState *MoveInterface; // r3
  idAI2 *v8; // r3
  idAIMoveState *v9; // r3
  idAIStateTransition::aiTransCode_t result; // r3

  v6 = idAIFSM::GetAI(this: parentFSM);
  MoveInterface = idAI2::GetMoveInterface(this: v6);
  if ( MoveInterface->GetMoveStatus(this: MoveInterface) < 2 )
    return 0;
  v8 = idAIFSM::GetAI(this: parentFSM);
  v9 = idAI2::GetMoveInterface(this: v8);
  switch ( v9->GetMoveStatus(this: v9) )
  {
    case 2:
      result = TRANSCODE_MOVE_ERROR;
      break;
    case 3:
      result = TRANSCODE_MOVE_NO_AAS;
      break;
    case 4:
      result = TRANSCODE_MOVE_INVALID_ENTITY;
      break;
    case 5:
      result = TRANSCODE_MOVE_UNREACHABLE;
      break;
    case 6:
      result = TRANSCODE_MOVE_NOT_IN_AAS;
      break;
    case 7:
      result = TRANSCODE_MOVE_PATHING_FAILED;
      break;
    case 8:
      result = TRANSCODE_MOVE_OBSTRUCTED;
      break;
    case 9:
      result = TRANSCODE_MOVE_NO_PATH_GROUP;
      break;
    case 10:
      result = TRANSCODE_MOVE_NO_PATH_POINT;
      break;
    case 11:
      result = TRANSCODE_MOVE_STUCK;
      break;
    default:
      result = TRANSCODE_MOVE_FAILED;
      break;
  }
  return result;
}


// ========================================================================
// ?Evaluate@MoveStuck@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82A9E248
// RVA : 0x00A9E248
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall MoveStuck::Evaluate(MoveStuck *this, idAI2 *ai, idAIFSM *parentFSM, idAIState *state, const int curTime)
{
  idAIMoveState *MoveInterface; // r3

  MoveInterface = idAI2::GetMoveInterface(this: ai);
  return MoveInterface->GetMoveStatus(this: MoveInterface) != 11 ? 0 : 0x14;
}


// ========================================================================
// ?InternalInitState@idAction_MoveToPoint@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E290
// RVA : 0x00A9E290
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_MoveToPoint::InternalInitState(idAction_MoveToPoint *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &MoveTimedOut::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &MoveStuck::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &MoveFailed::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &ReachedPoint::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_MoveToPointNoFail@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E310
// RVA : 0x00A9E310
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_MoveToPointNoFail::InternalInitState(
        idAction_MoveToPointNoFail *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &ReachedPoint::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_MoveToEntity@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E328
// RVA : 0x00A9E328
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_MoveToEntity::InternalInitState(idAction_MoveToEntity *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &ActionEntityDeleted::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &MoveStuck::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &MoveFailed::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &ReachedPoint::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_MoveToPathPoint@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E3A8
// RVA : 0x00A9E3A8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_MoveToPathPoint::InternalInitState(
        idAction_MoveToPathPoint *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &ActionEntityDeleted::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &MoveTimedOut::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &MoveStuck::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &MoveFailed::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &ReachedPoint::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_MoveToEntityNoFail@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E440
// RVA : 0x00A9E440
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_MoveToEntityNoFail::InternalInitState(
        idAction_MoveToPathPointNoFail *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &ActionEntityDeleted::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &ReachedPoint::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_MoveToCover@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E4A8
// RVA : 0x00A9E4A8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_MoveToCover::InternalInitState(idAction_MoveToCover *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &MoveTimedOut::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &MoveStuck::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &MoveFailed::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &ReachedPoint::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &AbortMoveToCover::Type, nextStateType: &idAIStateError::Type);
}


// ========================================================================
// ?InternalInitState@idAction_HideAttachment@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E540
// RVA : 0x00A9E540
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_HideAttachment::InternalInitState(idAction_SetAccuracy *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &ActionFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_Idle@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E558
// RVA : 0x00A9E558
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_Idle::InternalInitState(idAction_Wait *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &ActionExpired::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_StandToCrouch@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E570
// RVA : 0x00A9E570
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_StandToCrouch::InternalInitState(
        idAction_StandToCrouch *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &FinishedCrouching::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_CrouchToStand@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E588
// RVA : 0x00A9E588
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_CrouchToStand::InternalInitState(
        idAction_CrouchToStand *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &FinishedStanding::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_ReloadWeapon@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E5A0
// RVA : 0x00A9E5A0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_ReloadWeapon::InternalInitState(idAction_ReloadWeapon *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &FinishedReloading::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_ReloadWeaponTorso@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E5B8
// RVA : 0x00A9E5B8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_ReloadWeaponTorso::InternalInitState(
        idAction_ReloadWeaponTorso *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &FinishedReloadingTorso::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_WaitForAnimVia@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E5D0
// RVA : 0x00A9E5D0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_WaitForAnimVia::InternalInitState(
        idAction_WaitForAnimVia *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &AnimFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_LoopAnimExitAtEnd@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E5E8
// RVA : 0x00A9E5E8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_LoopAnimExitAtEnd::InternalInitState(
        idAction_LoopAnimExitAtEnd *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &AnimationError::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &ActionExpired::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?Evaluate@AnimStarted@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82A9E650
// RVA : 0x00A9E650
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall AnimStarted::Evaluate(
        AnimStarted *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x4B;
}


// ========================================================================
// ?InternalInitState@idAction_StartAnim@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E690
// RVA : 0x00A9E690
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_StartAnim::InternalInitState(idAction_StartAnim *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &AnimationError::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &AnimStarted::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_WaitForTraversalAnim@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E6F8
// RVA : 0x00A9E6F8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_WaitForTraversalAnim::InternalInitState(
        idAction_WaitForTraversalAnim *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &AnimationError::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &TraversalAnimDone::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_Dive@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E760
// RVA : 0x00A9E760
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_Dive::InternalInitState(idAction_Dive *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &DiveFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_Melee@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E778
// RVA : 0x00A9E778
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_Melee::InternalInitState(idAction_Melee *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &MeleeFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_TurnToPoint@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E790
// RVA : 0x00A9E790
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_TurnToPoint::InternalInitState(idAction_TurnToPoint *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &TurnToPointFinished::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &AnimFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_TurnToEntity@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E7E0
// RVA : 0x00A9E7E0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_TurnToEntity::InternalInitState(idAction_TurnToEntity *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &TurnToEntityFinished::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &AnimFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_TurnToEntityWithOffset@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E830
// RVA : 0x00A9E830
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_TurnToEntityWithOffset::InternalInitState(
        idAction_TurnToEntityWithOffset *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &TurnToEntityWithOffsetFinished::Type,
    nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &AnimFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_WaitForEntity@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E880
// RVA : 0x00A9E880
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_WaitForEntity::InternalInitState(
        idAction_WaitForEntity *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &ActionEntityDeleted::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &EntityNear::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_EnterVehicle@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E8E8
// RVA : 0x00A9E8E8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_EnterVehicle::InternalInitState(idAction_EnterVehicle *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &ActionEntityDeleted::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &ActionFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_PlayVoiceOver@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E950
// RVA : 0x00A9E950
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_PlayVoiceOver::InternalInitState(
        idAction_PlayVoiceOver *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &VoiceOverFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_PlayInteractionVoiceOver@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E968
// RVA : 0x00A9E968
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_PlayInteractionVoiceOver::InternalInitState(
        idAction_PlayInteractionVoiceOver *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &InteractionVoiceOverFinished::Type,
    nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_ForceAnimState@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E980
// RVA : 0x00A9E980
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_ForceAnimState::InternalInitState(
        idAction_PlayOverrideAnimInterrupt *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &AnimationError::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &AnimFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_LeapAttack@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9E9E8
// RVA : 0x00A9E9E8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_LeapAttack::InternalInitState(idAction_LeapAttack *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &LeapAttackFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_DrawWeapon@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9EA00
// RVA : 0x00A9EA00
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_DrawWeapon::InternalInitState(idAction_DrawWeapon *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &DrawWeaponFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_HolsterWeapon@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9EA18
// RVA : 0x00A9EA18
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_HolsterWeapon::InternalInitState(
        idAction_HolsterWeapon *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &HolsterWeaponFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_PerformCoverAction@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9EA30
// RVA : 0x00A9EA30
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_PerformCoverAction::InternalInitState(
        idAction_PerformCoverAction *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &CoverActionFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_WaitForPlayerInteraction@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9EA48
// RVA : 0x00A9EA48
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_WaitForPlayerInteraction::InternalInitState(
        idAction_WaitForPlayerInteraction *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &InteractionTriggered::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_WaitForAIVar@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9EA60
// RVA : 0x00A9EA60
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_WaitForAIVar::InternalInitState(idAction_WaitForAIVar *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &AIVarExpressionTrue::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_PerfectMovement@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9EA78
// RVA : 0x00A9EA78
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_PerfectMovement::InternalInitState(
        idAction_PerfectMovement *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &PerfectMovementDone::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &AnimFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_ScriptedAnimWeb@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9EAC8
// RVA : 0x00A9EAC8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_ScriptedAnimWeb::InternalInitState(
        idAction_ScriptedAnimWeb *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &ScriptedAnimWebDone::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAction_MoveToScenePoint@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82A9EAE0
// RVA : 0x00A9EAE0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_MoveToScenePoint::InternalInitState(
        idAction_MoveToScenePoint *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &MoveToScenePointDone::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &MoveTimedOut::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &MoveStuck::Type, nextStateType: &idAIStateError::Type);
  idState::AddStateTransition(this, fsm, transType: &MoveFailed::Type, nextStateType: &idAIStateError::Type);
}


// ========================================================================
// ?InternalEnterState@idAIAction@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82A9EB60
// RVA : 0x00A9EB60
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAIAction::InternalEnterState(idAIAction *this, idAIFSM *parentFSM, int curTime)
{
  idAIAction_vtbl *v6; // r31
  idEntity *Owner; // r3

  v6 = this->__vftable;
  Owner = idFiniteStateMachine::GetOwner(this: parentFSM);
  v6->AIAction_EnterState(this, a2: (idAI2 *)Owner, a3: parentFSM, a4: curTime);
}


// ========================================================================
// ?InternalExitState@idAIAction@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82A9EBA8
// RVA : 0x00A9EBA8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAIAction::InternalExitState(idAIAction *this, idAIFSM *parentFSM, int curTime)
{
  idAIAction_vtbl *v6; // r31
  idEntity *Owner; // r3

  v6 = this->__vftable;
  Owner = idFiniteStateMachine::GetOwner(this: parentFSM);
  v6->AIAction_ExitState(this, a2: (idAI2 *)Owner, a3: parentFSM, a4: curTime);
}


// ========================================================================
// ?InternalWork@idAIAction@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82A9EBF0
// RVA : 0x00A9EBF0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAIAction::InternalWork(idAIAction *this, idAIFSM *parentFSM, int curTime)
{
  idAIAction_vtbl *v6; // r31
  idEntity *Owner; // r3

  v6 = this->__vftable;
  Owner = idFiniteStateMachine::GetOwner(this: parentFSM);
  v6->AIAction_Work(this, a2: (idAI2 *)Owner, a3: parentFSM, a4: curTime);
}


// ========================================================================
// ?InternalReenterState@idAIAction@@UAAXPAVidFiniteStateMachine@@HH@Z
// EA  : 0x82A9EC38
// RVA : 0x00A9EC38
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAIAction::InternalReenterState(
        idAIAction *this,
        idAIFSM *parentFSM,
        const int transCode,
        int curTime)
{
  idAIAction_vtbl *v7; // r31
  idEntity *Owner; // r3

  v7 = this->__vftable;
  Owner = idFiniteStateMachine::GetOwner(this: parentFSM);
  v7->AIAction_ReenterState(this, a2: (idAI2 *)Owner, a3: parentFSM, a4: curTime);
}


// ========================================================================
// ?InternalIsStateWaiting@idAIAction@@UBA_NPAVidFiniteStateMachine@@H@Z
// EA  : 0x82A9EC80
// RVA : 0x00A9EC80
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall idAIAction::InternalIsStateWaiting(idAIAction *this, idFiniteStateMachine *parentFSM, int curTime)
{
  idAIAction_vtbl *v6; // r31
  idEntity *Owner; // r3

  v6 = this->__vftable;
  Owner = idFiniteStateMachine::GetOwner(this: parentFSM);
  return ((int (__fastcall *)(idAIAction *, idEntity *, idFiniteStateMachine *, const int))v6->AIAction_IsWaiting)(
           a1: this,
           a2: Owner,
           a3: parentFSM,
           a4: curTime);
}


// ========================================================================
// ?CalcTurnParameters@@YAXPBVidAI2@@ABVidVec3@@1ABVidMat3@@V?$idTypesafeNumber@MW4RadiansUnique_t@@@@PBVidDeclAITurnParms@@AAV2@AAM6AAW4turnDirection_t@@@Z
// EA  : 0x82A9ED40
// RVA : 0x00A9ED40
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall CalcTurnParameters(
        const idAI2 *ai,
        const idVec3 *focusPoint,
        const idVec3 *eyePos,
        const idMat3 *curAxis,
        const idTypesafeNumber<float,enum RadiansUnique_t> *maxAngle,
        const idDeclAITurnParms *turnParms,
        idVec3 *idealDir,
        float *idealDot,
        float *turnAngle,
        turnDirection_t *turnDir,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        float *a28,
        int a29,
        int *a30)
{
  double v31; // fp8
  const idVec3 *v32; // r27
  double v33; // fp6
  double y; // fp5
  double z; // fp2
  double v42; // fp6
  double v43; // fp9
  double v44; // fp7
  double v45; // fp6
  double v46; // fp4
  long double v47; // fp2
  double v48; // fp1
  int v49; // r11
  double extraAngleScale; // fp13
  double value; // fp12
  int v52; // r9
  float x; // r7
  float v54; // r6
  float v55; // r11
  double v56; // fp30
  double v57; // fp0
  int v58; // r11
  double v59; // fp13
  double v60; // fp12
  double v61; // fp11
  double v62; // fp10
  idTypesafeNumber<float,enum RadiansUnique_t> v63; // [sp+50h] [-90h] BYREF
  idVec3 v64; // [sp+58h] [-88h] BYREF
  float v65[6]; // [sp+68h] [-78h] BYREF

  v31 = (float)(focusPoint->y - eyePos->y);
  v32 = &curAxis->mat[2];
  v33 = (float)(focusPoint->z - eyePos->z);
  idealDir->x = focusPoint->x - eyePos->x;
  idealDir->y = v31;
  idealDir->z = v33;
  idVec3::ProjectOntoPlane(this: idealDir, normal: &curAxis->mat[2], overBounce: 1.0);
  y = idealDir->y;
  z = idealDir->z;
  _FP9 = (float)((float)((float)(idealDir->z * idealDir->z)
                       + (float)((float)(idealDir->x * idealDir->x) + (float)(idealDir->y * idealDir->y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f7, f9, f10, f13 }
  v42 = __frsqrte(_FP7);
  v43 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v42
                                                                                      * (float)((float)((float)(idealDir->z * idealDir->z) + (float)((float)(idealDir->x * idealDir->x) + (float)(idealDir->y * idealDir->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v42)
                                                                      - (float)1.5)
                                                      * (float)v42)
                                              * (float)((float)((float)(idealDir->z * idealDir->z)
                                                              + (float)((float)(idealDir->x * idealDir->x)
                                                                      + (float)(idealDir->y * idealDir->y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v42
                                                                              * (float)((float)((float)(idealDir->z * idealDir->z)
                                                                                              + (float)((float)(idealDir->x * idealDir->x) + (float)(idealDir->y * idealDir->y)))
                                                                                      * (float)0.5))
                                                                      * (float)v42)
                                                              - (float)1.5)
                                              * (float)v42))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v42
                                                      * (float)((float)((float)(idealDir->z * idealDir->z)
                                                                      + (float)((float)(idealDir->x * idealDir->x)
                                                                              + (float)(idealDir->y * idealDir->y)))
                                                              * (float)0.5))
                                              * (float)v42)
                                      - (float)1.5)
                      * (float)v42));
  v44 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v42 * (float)((float)((float)(idealDir->z * idealDir->z) + (float)((float)(idealDir->x * idealDir->x) + (float)(idealDir->y * idealDir->y))) * (float)0.5)) * (float)v42) - (float)1.5)
                                                                                      * (float)v42)
                                                                              * (float)((float)((float)(idealDir->z * idealDir->z)
                                                                                              + (float)((float)(idealDir->x * idealDir->x) + (float)(idealDir->y * idealDir->y)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v42 * (float)((float)((float)(idealDir->z * idealDir->z) + (float)((float)(idealDir->x * idealDir->x) + (float)(idealDir->y * idealDir->y))) * (float)0.5)) * (float)v42)
                                                                                              - (float)1.5)
                                                                              * (float)v42))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v42
                                                                                      * (float)((float)((float)(idealDir->z * idealDir->z) + (float)((float)(idealDir->x * idealDir->x) + (float)(idealDir->y * idealDir->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v42)
                                                                      - (float)1.5)
                                                      * (float)v42))
                                      * (float)((float)((float)(idealDir->z * idealDir->z)
                                                      + (float)((float)(idealDir->x * idealDir->x)
                                                              + (float)(idealDir->y * idealDir->y)))
                                              * (float)0.5))
                              * (float)v43)
                      - (float)1.5);
  v45 = (float)((float)v44
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v42
                                                                                              * (float)((float)((float)(idealDir->z * idealDir->z) + (float)((float)(idealDir->x * idealDir->x) + (float)(idealDir->y * idealDir->y))) * (float)0.5))
                                                                                      * (float)v42)
                                                                              - (float)1.5)
                                                              * (float)v42)
                                                      * (float)((float)((float)(idealDir->z * idealDir->z)
                                                                      + (float)((float)(idealDir->x * idealDir->x)
                                                                              + (float)(idealDir->y * idealDir->y)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v42
                                                                                      * (float)((float)((float)(idealDir->z * idealDir->z) + (float)((float)(idealDir->x * idealDir->x) + (float)(idealDir->y * idealDir->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v42)
                                                                      - (float)1.5)
                                                      * (float)v42))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v42
                                                              * (float)((float)((float)(idealDir->z * idealDir->z)
                                                                              + (float)((float)(idealDir->x * idealDir->x)
                                                                                      + (float)(idealDir->y * idealDir->y)))
                                                                      * (float)0.5))
                                                      * (float)v42)
                                              - (float)1.5)
                              * (float)v42)));
  v46 = (float)(idealDir->x * (float)v45);
  idealDir->x = idealDir->x * (float)v45;
  idealDir->y = (float)y * (float)v45;
  *((double *)&v47 + 1) = (float)((float)z * (float)v45);
  idealDir->z = *((double *)&v47 + 1);
  *(double *)&v47 = (float)((float)(curAxis->mat[0].z * (float)*((double *)&v47 + 1))
                          + (float)((float)(curAxis->mat[0].x * (float)v46)
                                  + (float)(curAxis->mat[0].y * (float)((float)y * (float)v45))));
  *idealDot = (float)(curAxis->mat[0].z * (float)*((double *)&v47 + 1))
            + (float)((float)(curAxis->mat[0].x * (float)v46)
                    + (float)(curAxis->mat[0].y * (float)((float)y * (float)v45)));
  v48 = idMath::ACos(a: v47);
  *a28 = v48;
  if ( v48 <= maxAngle->value )
  {
    *a30 = 0;
  }
  else
  {
    v49 = 1;
    if ( (float)((float)(curAxis->mat[1].y * idealDir->y)
               + (float)((float)(curAxis->mat[1].x * idealDir->x) + (float)(idealDir->z * curAxis->mat[1].z))) <= 0.0 )
      v49 = 2;
    *a30 = v49;
    extraAngleScale = turnParms->extraAngleScale;
    if ( extraAngleScale > 0.0 )
    {
      value = maxAngle->value;
      v52 = v49;
      v65[1] = 1.0;
      v65[0] = 0.0;
      x = idealDir->x;
      v54 = idealDir->y;
      v55 = idealDir->z;
      v65[2] = -1.0;
      v56 = (float)((float)(v65[v52] * (float)value) * (float)extraAngleScale);
      v63.value = (float)(v65[v52] * (float)value) * (float)extraAngleScale;
      v64.x = x;
      v64.y = v54;
      v64.z = v55;
      idVec3::RotateSelf(this: &v64, axis: v32, angle: &v63);
      v57 = v64.y;
      v58 = 1;
      v59 = v64.z;
      v60 = v64.x;
      v61 = (float)(*a28 + (float)v56);
      v62 = (float)((float)(curAxis->mat[0].x * v64.x)
                  + (float)((float)(curAxis->mat[0].y * v64.y) + (float)(curAxis->mat[0].z * v64.z)));
      if ( (float)((float)(v64.z * curAxis->mat[1].z)
                 + (float)((float)(curAxis->mat[1].x * v64.x) + (float)(v64.y * curAxis->mat[1].y))) <= 0.0 )
        v58 = 2;
      *a30 = v58;
      *idealDot = v62;
      *a28 = v61;
      idealDir->x = v60;
      idealDir->y = v57;
      idealDir->z = v59;
    }
  }
}


// ========================================================================
// ?TurnToPoint@@YA?AW4turnToResult_t@@PAVidAI2@@ABVidVec3@@@Z
// EA  : 0x82A9EFC0
// RVA : 0x00A9EFC0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall TurnToPoint(idAI2 *ai, const idVec3 *point)
{
  idPhysics *Physics; // r3
  const idVec3 *v5; // r27
  idAIOrientation *BodyOrientation; // r26
  const idDeclAITurnParms **list; // r5
  const idDeclAITurnParms *v8; // r28
  const idDeclAITurnParms *v9; // r5
  float *v11; // [sp+8h] [-118h]
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v12; // [sp+8h] [-118h]
  turnDirection_t *v13; // [sp+Ch] [-114h]
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v14; // [sp+Ch] [-114h]
  int v15; // [sp+10h] [-110h]
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v16; // [sp+10h] [-110h]
  int v17; // [sp+14h] [-10Ch]
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v18; // [sp+14h] [-10Ch]
  int v19; // [sp+18h] [-108h]
  int v20; // [sp+18h] [-108h]
  int v21; // [sp+1Ch] [-104h]
  int v22; // [sp+1Ch] [-104h]
  int v23; // [sp+20h] [-100h]
  int v24; // [sp+20h] [-100h]
  int v25; // [sp+24h] [-FCh]
  int v26; // [sp+24h] [-FCh]
  int v27; // [sp+28h] [-F8h]
  int v28; // [sp+28h] [-F8h]
  int v29; // [sp+2Ch] [-F4h]
  int v30; // [sp+2Ch] [-F4h]
  int v31; // [sp+30h] [-F0h]
  int v32; // [sp+30h] [-F0h]
  int v33; // [sp+34h] [-ECh]
  int v34; // [sp+34h] [-ECh]
  int v35; // [sp+38h] [-E8h]
  int v36; // [sp+38h] [-E8h]
  int v37; // [sp+3Ch] [-E4h]
  int v38; // [sp+3Ch] [-E4h]
  int v39; // [sp+40h] [-E0h]
  int v40; // [sp+40h] [-E0h]
  int v41; // [sp+44h] [-DCh]
  int v42; // [sp+44h] [-DCh]
  int v43; // [sp+48h] [-D8h]
  int v44; // [sp+48h] [-D8h]
  int v45; // [sp+4Ch] [-D4h]
  int v46; // [sp+4Ch] [-D4h]
  int v47; // [sp+50h] [-D0h]
  int v48; // [sp+50h] [-D0h]
  int v49; // [sp+58h] [-C8h]
  int v50; // [sp+58h] [-C8h]
  int v51; // [sp+60h] [-C0h]
  int v52; // [sp+68h] [-B8h]
  unsigned __int16 v53; // [sp+70h] [-B0h] BYREF
  unsigned __int16 v54; // [sp+72h] [-AEh] BYREF
  idTypesafeNumber<float,enum RadiansUnique_t> v55; // [sp+74h] [-ACh] BYREF
  turnDirection_t v56; // [sp+78h] [-A8h] BYREF
  float v57; // [sp+7Ch] [-A4h] BYREF
  aiSubWeb_t subWeb; // [sp+80h] [-A0h] BYREF
  idVec3 v59[2]; // [sp+88h] [-98h] BYREF
  idStr v60; // [sp+A0h] [-80h] BYREF
  idStr v61[3]; // [sp+C0h] [-60h] BYREF

  Physics = idEntity::GetPhysics(this: ai);
  v5 = Physics->GetOrigin(this: Physics, a2: 0);
  BodyOrientation = idAI2::GetBodyOrientation(this: ai);
  list = ai->aiEditable.behaviors.decl->turnParms.list;
  v55.value = idMath::M_DEG2RAD;
  v8 = *list;
  CalcTurnParameters(
    ai,
    focusPoint: point,
    eyePos: v5,
    curAxis: &BodyOrientation->axis,
    maxAngle: &v55,
    turnParms: *list,
    idealDir: v59,
    idealDot: &v57,
    turnAngle: v11,
    turnDir: v13,
    a11: v15,
    a12: v17,
    a13: v19,
    a14: v21,
    a15: v23,
    a16: v25,
    a17: v27,
    a18: v29,
    a19: v31,
    a20: v33,
    a21: v35,
    a22: v37,
    a23: v39,
    a24: v41,
    a25: v43,
    a26: v45,
    a27: v47,
    a28: (float *)&subWeb,
    a29: v49,
    a30: (int *)&v56);
  if ( v56 == TURN_NONE )
    return 0;
  v61[0].len = 0;
  v61[0].allocedAndFlag = 20;
  v61[0].data = v61[0].baseBuffer;
  v61[0].baseBuffer[0] = 0;
  idAI2::GetIdleTurnStateName(this: ai, turnDir: v56, turnDeltaDot: v57, turnParms: v9, name: (idStr *)v8, a6: v61);
  v60.allocedAndFlag = 20;
  v60.data = v60.baseBuffer;
  v60.len = 0;
  v60.baseBuffer[0] = 0;
  idAI2::GetIdleStateName(this: ai, name: &v60);
  v54 = -1;
  v53 = -1;
  subWeb = ai->aiVolatile.animation.subWeb;
  if ( idAI2::ChangeAnimStateVia(
         this: ai,
         web: AIANIMWEB_BODY,
         subWeb,
         stateName: v60.data,
         viaSubWeb: subWeb,
         viaStateName: v61[0].data,
         interruptPath: INTR_PATH_YES,
         interruptBlend: INTR_BLEND_NO,
         subWebIndex: v12,
         stateIndex: v14,
         viaSubWebIndex: v16,
         viaStateIndex: v18,
         a13: v20,
         a14: v22,
         a15: v24,
         a16: v26,
         a17: v28,
         a18: v30,
         a19: v32,
         a20: v34,
         a21: v36,
         a22: v38,
         a23: v40,
         a24: v42,
         a25: v44,
         a26: v46,
         a27: v48,
         a28: nullptr,
         a29: v50,
         a30: nullptr,
         a31: v51,
         a32: (__int16 *)&v54,
         a33: v52,
         a34: (__int16 *)&v53) == AWPATH_OK )
  {
    idAI2::SetAnimWebEvent(
      this: ai,
      web: AIANIMWEB_BODY,
      priority: PRIORITY_LOW,
      swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v54,
      si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v53,
      eventType: ANIMWEB_EVENT_END_BLEND_OUT,
      eventDef: &EV_AnimWeb_Wait);
    idAIOrientation::SetIdealDir(this: BodyOrientation, ai, dir: v59);
    idStr::FreeData(this: &v60);
    idStr::FreeData(this: v61);
    return 1;
  }
  else
  {
    idStr::FreeData(this: &v60);
    idStr::FreeData(this: v61);
    return 2;
  }
}


// ========================================================================
// __unwind$499777
// EA  : 0x82A9F178
// RVA : 0x00A9F178
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_499777()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 192));
}


// ========================================================================
// __unwind$499778
// EA  : 0x82A9F1A0
// RVA : 0x00A9F1A0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_499778()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 160));
}


// ========================================================================
// ?Evaluate@MoveTimedOut@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82A9F1C8
// RVA : 0x00A9F1C8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall MoveTimedOut::Evaluate(
        MoveTimedOut *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  int movementMaxDuration; // r11
  idAIStateTransition::aiTransCode_t result; // r3

  movementMaxDuration = ai->aiVolatile.memory.movementMaxDuration;
  if ( movementMaxDuration < 0 )
    return 0;
  result = TRANSCODE_MOVE_TIMED_OUT;
  if ( curTime <= ai->aiVolatile.memory.movementStartTime + movementMaxDuration )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@ActionExpired@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82A9F200
// RVA : 0x00A9F200
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall ActionExpired::Evaluate(
        ActionExpired *this,
        idAI2 *ai,
        idAIActionFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int actionExpireTime; // r11

  actionExpireTime = idAIActionFSM::CastTo(c: parentFSM)->actionExpireTime;
  if ( actionExpireTime >= 0 )
    return __CFADD__(curTime - actionExpireTime, actionExpireTime ^ 0x80000000) ? 0 : 0x36;
  else
    return 0;
}


// ========================================================================
// ?Evaluate@AnimationError@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82A9F270
// RVA : 0x00A9F270
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall AnimationError::Evaluate(
        AnimationError *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !state->enterFailed ? 0 : 0xCB;
}


// ========================================================================
// ?Evaluate@AnimFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82A9F290
// RVA : 0x00A9F290
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall AnimFinished::Evaluate(
        AnimFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0xCC;
}


// ========================================================================
// ?AIAction_Work@idAction_MoveToPoint@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82A9F2D8
// RVA : 0x00A9F2D8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_MoveToPoint::AIAction_Work(
        idAction_MoveToPoint *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAIMoveState *p_moveState; // r29
  int v8; // [sp+50h] [-70h] BYREF
  idStr v9[3]; // [sp+60h] [-60h] BYREF

  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) == 0 )
  {
    p_moveState = &ai->aiVolatile.physics.moveState;
    if ( ai->aiVolatile.physics.moveState.GetMoveStatus(this: &ai->aiVolatile.physics.moveState) != 1 )
      return;
    if ( !p_moveState->IsPlayingTraversalAnim(this: &ai->aiVolatile.physics.moveState) )
    {
      this->tempUninterruptible = false;
      idAIMoveState::ContinueMove(this: &ai->aiVolatile.physics.moveState, totalTravelTime: &v8);
    }
    if ( p_moveState->GetMoveStatus(this: &ai->aiVolatile.physics.moveState) == 1
      && fsm->stateFrame > 2
      && ai->GetWalkState(this: ai) != this->lastWalkState )
    {
      v9[0].len = 0;
      v9[0].baseBuffer[0] = 0;
      v9[0].allocedAndFlag = 20;
      v9[0].data = v9[0].baseBuffer;
      idAI2::GetMovementStateName(this: ai, name: v9);
      idAI2::ChangeAnimState(
        this: ai,
        web: AIANIMWEB_BODY,
        subWeb: ai->aiVolatile.animation.subWeb,
        stateName: v9[0].data,
        interruptPath: INTR_PATH_YES,
        interruptBlend: INTR_BLEND_NO,
        subWebIndex: nullptr,
        stateIndex: nullptr);
      this->lastWalkState = ai->GetWalkState(this: ai);
      idStr::FreeData(this: v9);
    }
  }
  idAI2::UpdateBodyOrientationWhileMoving(this: ai);
}


// ========================================================================
// __unwind$499979
// EA  : 0x82A9F424
// RVA : 0x00A9F424
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_499979()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?AIAction_Work@idAction_MoveToEntity@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82A9F458
// RVA : 0x00A9F458
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_MoveToEntity::AIAction_Work(idAction_MoveToEntity *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  idScenePoint *curScenePoint; // r3
  idAIMoveState *p_moveState; // r29
  int v10; // [sp+50h] [-70h] BYREF
  idStr v11[3]; // [sp+60h] [-60h] BYREF

  if ( (unsigned __int8)idAI2::UsesScenePoints(this: ai) != 0 )
  {
    curScenePoint = ai->aiVolatile.memory.curScenePoint;
    if ( curScenePoint != nullptr && !idScenePoint::RequestScenePoint(this: curScenePoint, user: ai, curTime) )
    {
      ai->aiVolatile.memory.curScenePoint = nullptr;
      return;
    }
  }
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) == 0 )
  {
    p_moveState = &ai->aiVolatile.physics.moveState;
    if ( ai->aiVolatile.physics.moveState.GetMoveStatus(this: &ai->aiVolatile.physics.moveState) != 1 )
      return;
    if ( !p_moveState->IsPlayingTraversalAnim(this: &ai->aiVolatile.physics.moveState) )
      idAIMoveState::ContinueMove(this: &ai->aiVolatile.physics.moveState, totalTravelTime: &v10);
    if ( p_moveState->GetMoveStatus(this: &ai->aiVolatile.physics.moveState) == 1
      && fsm->stateFrame > 2
      && ai->GetWalkState(this: ai) != this->lastWalkState )
    {
      v11[0].len = 0;
      v11[0].allocedAndFlag = 20;
      v11[0].data = v11[0].baseBuffer;
      v11[0].baseBuffer[0] = 0;
      idAI2::GetMovementStateName(this: ai, name: v11);
      idAI2::ChangeAnimState(
        this: ai,
        web: AIANIMWEB_BODY,
        subWeb: ai->aiVolatile.animation.subWeb,
        stateName: v11[0].data,
        interruptPath: INTR_PATH_YES,
        interruptBlend: INTR_BLEND_NO,
        subWebIndex: nullptr,
        stateIndex: nullptr);
      this->lastWalkState = ai->GetWalkState(this: ai);
      idStr::FreeData(this: v11);
    }
  }
  idAI2::UpdateBodyOrientationWhileMoving(this: ai);
}


// ========================================================================
// __unwind$500091
// EA  : 0x82A9F5EC
// RVA : 0x00A9F5EC
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_500091()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?Evaluate@AbortMoveToCover@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82A9F618
// RVA : 0x00A9F618
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall AbortMoveToCover::Evaluate(
        AbortMoveToCover *this,
        _exception *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAICover *v6; // r30
  idAIStateTransition::aiTransCode_t result; // r3
  idPhysics *Physics; // r3
  float *v9; // r31
  const aas2Cover_t *Origin; // r3
  double v11; // fp10
  double v12; // fp6
  double v13; // fp2

  v6 = (idAICover *)((char *)&ai[912].retval + 12);
  if ( (unsigned __int8)idAICover::IsValid(this: (idAICover *)&ai[912].retval + 1) == 0 )
    return TRANSCODE_ABORT_MOVE_TO_COVER;
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 )
    return 0;
  if ( HIDWORD(ai[206].arg2) != 1 )
    return 0;
  Physics = idEntity::GetPhysics(this: (idEntity *)ai);
  v9 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  Origin = idAICover::GetOrigin(this: v6);
  v11 = (float)(v9[2] - Origin->origin.z);
  v12 = (float)(v9[1] - Origin->origin.y);
  v13 = (float)((float)((float)v12 * (float)v12)
              + (float)((float)((float)(*v9 - Origin->origin.x) * (float)(*v9 - Origin->origin.x))
                      + (float)((float)v11 * (float)v11)));
  result = TRANSCODE_ABORT_MOVE_TO_COVER;
  if ( v13 <= (float)(ai_coverAbortRadius.valueFloat * ai_coverAbortRadius.valueFloat) )
    return 0;
  return result;
}


// ========================================================================
// ?AIAction_ExitState@idAction_MoveToCover@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82A9F708
// RVA : 0x00A9F708
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_MoveToCover::AIAction_ExitState(
        idAction_MoveToCover *this,
        _exception *ai,
        idAIFSM *fsm,
        const int curTime)
{
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) == 0 )
    HIDWORD(ai[206].arg2) = 0;
}


// ========================================================================
// ?Action_SetMovePushStatusEnter@idAction_SetMovePushStatus@@QAA?AVeventVoid@@PAVidEntity@@W4aiMovePushStatus_t@@@Z
// EA  : 0x82A9F748
// RVA : 0x00A9F748
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetMovePushStatus *__fastcall idAction_SetMovePushStatus::Action_SetMovePushStatusEnter(
        idAction_SetMovePushStatus *this,
        eventVoid *result,
        idAI2 *entity,
        aiMovePushStatus_t newStatus)
{
  idAI2 *v6; // r3

  v6 = idAI2::CastTo(c: entity);
  idAI2::SetMovePushStatus(this: v6, newStatus, frameCount: 0);
  return this;
}


// ========================================================================
// ?Action_IdleEnter@idAction_Idle@@QAA?AVeventVoid@@PAVidEntity@@HW4aiIdleTurn_t@@@Z
// EA  : 0x82A9F7A0
// RVA : 0x00A9F7A0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_Idle *__fastcall idAction_Idle::Action_IdleEnter(
        idAction_Idle *this,
        eventVoid *result,
        idAI2 *entity,
        const int time,
        int turnType)
{
  idAI2 *v9; // r29
  idLegsFSM *ActionFSM; // r3
  idAIActionFSM *v11; // r26
  int GameMs; // r3
  const idDeclAIBehavior *decl; // r11
  idStr v15[3]; // [sp+60h] [-60h] BYREF

  v9 = idAI2::CastTo(c: entity);
  ActionFSM = idAI2::GetActionFSM(this: v9);
  v11 = idAIActionFSM::CastTo(c: ActionFSM);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  *(_DWORD *)&result[28] = turnType;
  if ( turnType >= 0 )
  {
    decl = v9->aiEditable.behaviors.decl;
    if ( turnType < decl->turnParms.num && decl->turnParms.list[turnType] != nullptr )
    {
      if ( time < 0 )
        v11->actionExpireTime = -1;
      else
        v11->actionExpireTime = GameMs + time;
      *(_DWORD *)&result[32] = -1;
      result[36] = 0;
      if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v9) != 0 )
      {
        idAnimBaseFSM::ClearDestination(this: &v9->aiVolatile.animation.animFSM);
        v9->aiVolatile.animation.animFSM.idleTurnType = *(_DWORD *)&result[28];
        v9->aiVolatile.animation.animFSM.overrideMoveFlags |= 0x2000u;
      }
      else
      {
        idAIMoveState::Stop(this: &v9->aiVolatile.physics.moveState, newStatus: 0);
        v15[0].len = 0;
        v15[0].allocedAndFlag = 20;
        v15[0].data = v15[0].baseBuffer;
        v15[0].baseBuffer[0] = 0;
        idAI2::GetIdleStateName(this: v9, name: v15);
        idAI2::ChangeAnimState(
          this: v9,
          web: AIANIMWEB_BODY,
          subWeb: v9->aiVolatile.animation.subWeb,
          stateName: v15[0].data,
          interruptPath: INTR_PATH_YES,
          interruptBlend: INTR_BLEND_NO,
          subWebIndex: nullptr,
          stateIndex: nullptr);
        idStr::FreeData(this: v15);
      }
    }
  }
  return this;
}


// ========================================================================
// __unwind$500369
// EA  : 0x82A9F904
// RVA : 0x00A9F904
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_500369()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?AIAction_ExitState@idAction_Idle@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82A9F930
// RVA : 0x00A9F930
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_Idle::AIAction_ExitState(idAction_Idle *this, _exception *ai, idAIFSM *fsm, const int curTime)
{
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 )
  {
    BYTE8(ai[596].retval) = 1;
    LODWORD(ai[596].retval) &= ~0x2000u;
  }
}


// ========================================================================
// ?Action_PainEnter@idAction_Pain@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82A9F990
// RVA : 0x00A9F990
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_Pain *__fastcall idAction_Pain::Action_PainEnter(idAction_Pain *this, eventVoid *result, idAI2 *entity)
{
  idAI2 *v4; // r31
  idAIMoveState *p_moveState; // r31

  v4 = idAI2::CastTo(c: entity);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v4) != 0 )
  {
    idAnimBaseFSM::ClearDestination(this: &v4->aiVolatile.animation.animFSM);
  }
  else
  {
    p_moveState = &v4->aiVolatile.physics.moveState;
    idAIMoveState::Stop(this: p_moveState, newStatus: 0);
    idAIMoveState::SetMovementModeForReal(this: p_moveState, mode: AIMOVEMODE_ANIM);
  }
  return this;
}


// ========================================================================
// ?Evaluate@FinishedCrouching@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82A9FA10
// RVA : 0x00A9FA10
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall FinishedCrouching::Evaluate(
        FinishedCrouching *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAction_StandToCrouch *state,
        const int curTime)
{
  if ( idAction_StandToCrouch::CastTo(c: state)->alreadyCrouched )
    return 48;
  else
    return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x30;
}


// ========================================================================
// ?Evaluate@FinishedStanding@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82A9FA88
// RVA : 0x00A9FA88
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall FinishedStanding::Evaluate(
        FinishedStanding *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAction_CrouchToStand *state,
        const int curTime)
{
  if ( idAction_CrouchToStand::CastTo(c: state)->alreadyCrouched )
    return 48;
  else
    return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x30;
}


// ========================================================================
// ?Action_CrouchToStandEnter@idAction_CrouchToStand@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82A9FB08
// RVA : 0x00A9FB08
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_CrouchToStand *__fastcall idAction_CrouchToStand::Action_CrouchToStandEnter(
        idAction_CrouchToStand *this,
        idState *result,
        idAI2 *entity)
{
  idAI2 *v5; // r3
  _exception *v6; // r30
  idAIAnimWebState *v7; // r3
  const idAnimWebState *v8; // r4
  char v9; // r3
  unsigned __int8 v10; // r3
  idAIAnimWebState_Current v12; // [sp+50h] [-C0h] BYREF
  idAIAnimWebState v13; // [sp+70h] [-A0h] BYREF
  idStr v14; // [sp+90h] [-80h] BYREF
  idStr v15[3]; // [sp+B0h] [-60h] BYREF

  v5 = idAI2::CastTo(c: entity);
  v6 = (_exception *)v5;
  if ( v5 != nullptr
    && !v5->IsDying(this: v5)
    && (*(unsigned __int8 (__fastcall **)(_exception *))(v6->type + 508))(a1: v6) == 0 )
  {
    if ( (*(int (__fastcall **)(_exception *))(v6->type + 784))(a1: v6) == 1 )
    {
      HIBYTE(result[1].__vftable) = 1;
    }
    else
    {
      (*(void (__fastcall **)(_exception *, int))(v6->type + 788))(a1: v6, a2: 1);
      if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: v6) != 0 )
        idAnimBaseFSM::ClearDestination(this: (idAnimBaseFSM *)&v6[545]);
      else
        idAIMoveState::Stop(this: (idAIMoveState *)((char *)&v6[190].arg2 + 4), newStatus: 0);
      v15[0].len = 0;
      v15[0].allocedAndFlag = 20;
      v15[0].data = v15[0].baseBuffer;
      v15[0].baseBuffer[0] = 0;
      idAI2::GetIdleStateName(this: (idAI2 *)v6, name: v15);
      v14.allocedAndFlag = 20;
      v14.data = v14.baseBuffer;
      v14.len = 0;
      v14.baseBuffer[0] = 0;
      idAI2::GetSubWebPrefix(this: (idAI2 *)v6, swt: SDWORD1(v6[527].retval), subWebPrefix: &v14);
      idAIAnimWebState_Current::idAIAnimWebState_Current(this: &v12, ai: (const idAI2 *)v6);
      v7 = idAIAnimWebState::idAIAnimWebState(this: &v13, ai: (idAI2 *)v6, subwebName: v14.data, stateName: v15[0].data);
      v8 = &v7->idAnimWebState;
      if ( v7 == nullptr )
        v8 = nullptr;
      v9 = idAnimWebState::operator==(this: &v12.idAnimWebState, other: v8);
      v13.__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
      if ( v9 != 0 )
      {
        HIBYTE(result[1].__vftable) = 1;
      }
      else
      {
        v10 = idAI2::WaitForAnimToStart(
                this: (idAI2 *)v6,
                awt: AIANIMWEB_BODY,
                priority: PRIORITY_LOW,
                subWebName: v14.data,
                stateName: v15[0].data,
                ev: ANIMWEB_EVENT_START_BLEND_IN);
        idState::SetEnterFailed(this: result, failed: (_cntlzw(v10) & 0x20) != 0);
      }
      v12.__vftable = (idAIAnimWebState_Current_vtbl *)&idAIAnimWebState::`vftable';
      idStr::FreeData(this: &v14);
      idStr::FreeData(this: v15);
    }
  }
  return this;
}


// ========================================================================
// __unwind$500615
// EA  : 0x82A9FCF0
// RVA : 0x00A9FCF0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_500615()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 176));
}


// ========================================================================
// __unwind$500616
// EA  : 0x82A9FD18
// RVA : 0x00A9FD18
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_500616()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 144));
}


// ========================================================================
// __unwind$500617
// EA  : 0x82A9FD40
// RVA : 0x00A9FD40
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_500617()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$500618
// EA  : 0x82A9FD68
// RVA : 0x00A9FD68
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_500618()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 272 + 112));
}


// ========================================================================
// ?AIAction_Work@idAction_StandToCrouch@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82A9FD90
// RVA : 0x00A9FD90
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_StandToCrouch::AIAction_Work(
        idAction_CrouchToStand *this,
        _exception *ai,
        idAIFSM *fsm,
        const int curTime)
{
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 )
    idAnimBaseFSM::ClearDestination(this: (idAnimBaseFSM *)&ai[545]);
  else
    idAIMoveState::Stop(this: (idAIMoveState *)((char *)&ai[190].arg2 + 4), newStatus: 0);
}


// ========================================================================
// ?Action_PullTriggerRightEnter@idAction_PullTriggerRight@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82A9FDF8
// RVA : 0x00A9FDF8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_PullTriggerRight *__fastcall idAction_PullTriggerRight::Action_PullTriggerRightEnter(
        idAction_PullTriggerRight *this,
        eventVoid *result,
        idAI2 *entity)
{
  idAI2 *v4; // r31
  idWeapon *EquippedWeapon; // r3

  v4 = idAI2::CastTo(c: entity);
  EquippedWeapon = idActor::GetEquippedWeapon(this: v4, slot: EQUIP_RIGHT_HAND);
  if ( EquippedWeapon != nullptr )
    EquippedWeapon->PullTrigger(this: EquippedWeapon, a2: v4, a3: false);
  return this;
}


// ========================================================================
// ?Action_ReleaseTriggerRightEnter@idAction_ReleaseTriggerRight@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82A9FE60
// RVA : 0x00A9FE60
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ReleaseTriggerRight *__fastcall idAction_ReleaseTriggerRight::Action_ReleaseTriggerRightEnter(
        idAction_ReleaseTriggerRight *this,
        eventVoid *result,
        idAI2 *entity)
{
  idAI2 *v4; // r31
  idWeapon *EquippedWeapon; // r3

  v4 = idAI2::CastTo(c: entity);
  EquippedWeapon = idActor::GetEquippedWeapon(this: v4, slot: EQUIP_RIGHT_HAND);
  if ( EquippedWeapon != nullptr )
    EquippedWeapon->ReleaseTrigger(this: EquippedWeapon, a2: v4);
  return this;
}


// ========================================================================
// ?Action_PullTriggerLeftEnter@idAction_PullTriggerLeft@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82A9FEC8
// RVA : 0x00A9FEC8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_PullTriggerLeft *__fastcall idAction_PullTriggerLeft::Action_PullTriggerLeftEnter(
        idAction_PullTriggerLeft *this,
        eventVoid *result,
        idAI2 *entity)
{
  idAI2 *v4; // r31
  idWeapon *EquippedWeapon; // r3

  v4 = idAI2::CastTo(c: entity);
  EquippedWeapon = idActor::GetEquippedWeapon(this: v4, slot: EQUIP_LEFT_HAND);
  if ( EquippedWeapon != nullptr )
    EquippedWeapon->PullTrigger(this: EquippedWeapon, a2: v4, a3: false);
  return this;
}


// ========================================================================
// ?Action_ReleaseTriggerLeftEnter@idAction_ReleaseTriggerLeft@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82A9FF30
// RVA : 0x00A9FF30
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ReleaseTriggerLeft *__fastcall idAction_ReleaseTriggerLeft::Action_ReleaseTriggerLeftEnter(
        idAction_ReleaseTriggerLeft *this,
        eventVoid *result,
        idAI2 *entity)
{
  idAI2 *v4; // r31
  idWeapon *EquippedWeapon; // r3

  v4 = idAI2::CastTo(c: entity);
  EquippedWeapon = idActor::GetEquippedWeapon(this: v4, slot: EQUIP_LEFT_HAND);
  if ( EquippedWeapon != nullptr )
    EquippedWeapon->ReleaseTrigger(this: EquippedWeapon, a2: v4);
  return this;
}


// ========================================================================
// ?Evaluate@FinishedReloading@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82A9FF98
// RVA : 0x00A9FF98
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall FinishedReloading::Evaluate(
        FinishedReloading *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  if ( ai->aiVolatile.memory.reloadSlot != EQUIP_NONE )
    return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x33;
  else
    return 51;
}


// ========================================================================
// ?AIAction_ExitState@idAction_ReloadWeapon@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AA0000
// RVA : 0x00AA0000
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_ReloadWeapon::AIAction_ExitState(
        idAction_ReloadWeapon *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  ai->aiVolatile.focus.enableBodyRotation = true;
  ai->aiVolatile.memory.reloadSlot = EQUIP_NONE;
}


// ========================================================================
// ?Evaluate@FinishedReloadingTorso@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AA0020
// RVA : 0x00AA0020
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall FinishedReloadingTorso::Evaluate(
        FinishedReloadingTorso *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  if ( ai->aiVolatile.memory.reloadSlot != EQUIP_NONE )
    return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x34;
  else
    return 52;
}


// ========================================================================
// ?Action_ReloadWeaponTorsoEnter@idAction_ReloadWeaponTorso@@QAA?AVeventVoid@@PAVidEntity@@W4equipSlot_t@@PBVidDeclAmmo@@@Z
// EA  : 0x82AA0088
// RVA : 0x00AA0088
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ReloadWeaponTorso *__fastcall idAction_ReloadWeaponTorso::Action_ReloadWeaponTorsoEnter(
        idAction_ReloadWeaponTorso *this,
        idState *result,
        idAI2 *entity,
        equipSlot_t slot,
        const idDeclAmmo *ammoDecl)
{
  idAI2 *v9; // r3
  idWeapon *EquippedWeapon; // r3

  v9 = idAI2::CastTo(c: entity);
  v9->aiVolatile.memory.reloadSlot = slot;
  EquippedWeapon = idActor::GetEquippedWeapon(this: v9, slot: EQUIP_LEFT_HAND);
  if ( EquippedWeapon != nullptr )
    idWeapon::BeginReloading(this: EquippedWeapon, ammoDecl, secondaryAmmo: false);
  else
    idState::SetEnterFailed(this: result, failed: true);
  return this;
}


// ========================================================================
// ?AIAction_ExitState@idAction_ReloadWeaponTorso@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AA00F8
// RVA : 0x00AA00F8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_ReloadWeaponTorso::AIAction_ExitState(
        idAction_ReloadWeaponTorso *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  ai->aiVolatile.memory.reloadSlot = EQUIP_NONE;
}


// ========================================================================
// ?Action_WaitForAnimEnter@idAction_WaitForAnim@@QAA?AVeventVoid@@PAVidEntity@@ABVidAnimWebPath@@@Z
// EA  : 0x82AA0118
// RVA : 0x00AA0118
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_WaitForAnim *__fastcall idAction_WaitForAnim::Action_WaitForAnimEnter(
        idAction_WaitForAnim *this,
        idState *result,
        idAI2 *entity,
        const idAnimWebPath *animRef)
{
  idAI2 *v7; // r3
  idAI2 *v8; // r27
  unsigned __int8 v9; // r3
  idStr v11; // [sp+50h] [-70h] BYREF
  idStr v12[2]; // [sp+70h] [-50h] BYREF

  v7 = idAI2::CastTo(c: entity);
  v12[0].len = 0;
  v12[0].allocedAndFlag = 20;
  v8 = v7;
  v12[0].data = v12[0].baseBuffer;
  v12[0].baseBuffer[0] = 0;
  v11.allocedAndFlag = 20;
  v11.data = v11.baseBuffer;
  v11.len = 0;
  v11.baseBuffer[0] = 0;
  idAI2::GetSubWebAndStateFromAnimWebPath(this: v7, animWebPath: animRef->data, subWebName: v12, stateName: &v11);
  v9 = idAI2::WaitForAnimToEnd(
         this: v8,
         priority: PRIORITY_LOW,
         subWebName: v12[0].data,
         stateName: v11.data,
         ev: ANIMWEB_EVENT_START_BLEND_OUT);
  idState::SetEnterFailed(this: result, failed: (_cntlzw(v9) & 0x20) != 0);
  idStr::FreeData(this: &v11);
  idStr::FreeData(this: v12);
  return this;
}


// ========================================================================
// __unwind$501002
// EA  : 0x82AA01CC
// RVA : 0x00AA01CC
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_501002()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$501003
// EA  : 0x82AA01F4
// RVA : 0x00AA01F4
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_501003()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?Action_WaitForAnimViaEnter@idAction_WaitForAnimVia@@QAA?AVeventVoid@@PAVidEntity@@ABVidAnimWebPath@@1@Z
// EA  : 0x82AA0228
// RVA : 0x00AA0228
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_WaitForAnimVia *__fastcall idAction_WaitForAnimVia::Action_WaitForAnimViaEnter(
        idAction_WaitForAnimVia *this,
        idState *result,
        idAI2 *entity,
        const idAnimWebPath *destAnim,
        const idAnimWebPath *viaAnim)
{
  idAI2 *v9; // r3
  idAI2 *v10; // r24
  idStr v12; // [sp+50h] [-D0h] BYREF
  idStr v13; // [sp+70h] [-B0h] BYREF
  idStr v14; // [sp+90h] [-90h] BYREF
  idStr v15[3]; // [sp+B0h] [-70h] BYREF

  v9 = idAI2::CastTo(c: entity);
  v15[0].len = 0;
  v15[0].allocedAndFlag = 20;
  v10 = v9;
  v15[0].data = v15[0].baseBuffer;
  v15[0].baseBuffer[0] = 0;
  v14.allocedAndFlag = 20;
  v14.data = v14.baseBuffer;
  v14.len = 0;
  v14.baseBuffer[0] = 0;
  idAI2::GetSubWebAndStateFromAnimWebPath(this: v9, animWebPath: destAnim->data, subWebName: v15, stateName: &v14);
  v13.allocedAndFlag = 20;
  v13.data = v13.baseBuffer;
  v13.len = 0;
  v13.baseBuffer[0] = 0;
  v12.allocedAndFlag = 20;
  v12.data = v12.baseBuffer;
  v12.len = 0;
  v12.baseBuffer[0] = 0;
  idAI2::GetSubWebAndStateFromAnimWebPath(this: v10, animWebPath: viaAnim->data, subWebName: &v13, stateName: &v12);
  if ( (unsigned __int8)idAI2::WaitForAnimToStartVia(
                          this: v10,
                          awt: AIANIMWEB_BODY,
                          priority: PRIORITY_LOW,
                          subWebName: v15[0].data,
                          stateName: v14.data,
                          viaSubWebName: v13.data,
                          viaStateName: v12.data,
                          ev: ANIMWEB_EVENT_START_BLEND_IN) == 0 )
    idState::SetEnterFailed(this: result, failed: true);
  idStr::FreeData(this: &v12);
  idStr::FreeData(this: &v13);
  idStr::FreeData(this: &v14);
  idStr::FreeData(this: v15);
  return this;
}


// ========================================================================
// __unwind$501121
// EA  : 0x82AA0354
// RVA : 0x00AA0354
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_501121()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 176));
}


// ========================================================================
// __unwind$501122
// EA  : 0x82AA037C
// RVA : 0x00AA037C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_501122()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 144));
}


// ========================================================================
// __unwind$501123
// EA  : 0x82AA03A4
// RVA : 0x00AA03A4
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_501123()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$501124
// EA  : 0x82AA03CC
// RVA : 0x00AA03CC
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_501124()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 80));
}


// ========================================================================
// ?AIAction_Work@idAction_LoopAnimExitAtEnd@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AA03F8
// RVA : 0x00AA03F8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAction_LoopAnimExitAtEnd::AIAction_Work(
        idAction_LoopAnimExitAtEnd *this,
        idAI2 *ai,
        idAIActionFSM *fsm,
        const int curTime)
{
  int *p_startAnimTime; // r20
  int startAnimTime; // r22
  int waitTimeMS; // r27
  idAIActionFSM *v8; // r3
  int endFramesFromEnd; // r24
  int numFrames; // r30
  signed int frameRate; // r28
  idAIActionFSM *v12; // r21
  int startingAnimFrameOn; // r31
  int v14; // r29
  int v15; // r3
  int v16; // r25
  unsigned __int64 v17; // r8
  signed __int64 v18; // r5
  __int64 v19; // r3
  int v20; // r11
  int i; // r31
  int v22; // r3
  idClientGame *v23; // r11
  __int128 v24; // r8 OVERLAPPED
  unsigned __int64 v25; // r10

  p_startAnimTime = &ai->aiVolatile.memory.loopAnimExitAtEnd.startAnimTime;
  startAnimTime = ai->aiVolatile.memory.loopAnimExitAtEnd.startAnimTime;
  if ( startAnimTime != 0 )
  {
    waitTimeMS = ai->aiVolatile.memory.loopAnimExitAtEnd.waitTimeMS;
    if ( waitTimeMS >= 0 )
    {
      v8 = idAIActionFSM::CastTo(c: fsm);
      endFramesFromEnd = ai->aiVolatile.memory.loopAnimExitAtEnd.endFramesFromEnd;
      numFrames = ai->aiVolatile.memory.loopAnimExitAtEnd.numFrames;
      frameRate = ai->aiVolatile.memory.loopAnimExitAtEnd.frameRate;
      v12 = v8;
      startingAnimFrameOn = ai->aiVolatile.memory.loopAnimExitAtEnd.startingAnimFrameOn;
      v14 = waitTimeMS;
      if ( numFrames > endFramesFromEnd && frameRate > 0 && numFrames > 0 && startingAnimFrameOn < numFrames )
      {
        v15 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
        v16 = v15 * numFrames / frameRate;
        HIDWORD(v17) = __ROL4__(v15 * numFrames, 1) - 1;
        LODWORD(v18) = v16;
        HIDWORD(v18) = frameRate & ~HIDWORD(v17);
        LODWORD(v19) = v16 / 2 + waitTimeMS;
        __twllei(frameRate, 0);
        LODWORD(v17) = v16 & ~(__ROL4__(v19, 1) - 1);
        v20 = v19 / v18;
        __twlgei(HIDWORD(v18), 0xFFFFFFFF);
        __tdllei(v18, 0);
        __tdlgei(v17, 0xFFFFFFFF);
        if ( v20 < 1 )
          v20 = 1;
        for ( i = v20 * numFrames - startingAnimFrameOn - endFramesFromEnd - 1; i <= 0; i += numFrames )
          ;
        v22 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
        v23 = clientGame;
        *((_QWORD *)&v24 + 1) = __PAIR64__(frameRate, i);
        DWORD1(v24) = v22 * i;
        v25 = __PAIR64__(v22, __ROL4__(v22 * i, 1));
        LODWORD(v25) = frameRate & ~(v25 - 1);
        __tdllei(*(unsigned __int64 *)((char *)&v24 + 4), 0);
        __tdlgei(v25, 0xFFFFFFFF);
        v14 = (__int64)(*(_QWORD *)((char *)&v24 - 4) * __PAIR64__(frameRate, i)) / *(_QWORD *)((char *)&v24 + 4);
        if ( idGameTimeManager::GetGameMs(this: &v23->gameTimeManager, type: GAMETIME_SCALED) >= v14 + startAnimTime )
          v14 += v16;
      }
      if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < v14 + startAnimTime )
      {
        v12->actionExpireTime = v14 + startAnimTime;
        *p_startAnimTime = 0;
        return;
      }
      v12->actionExpireTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                            + 1;
    }
    *p_startAnimTime = 0;
  }
}


// ========================================================================
// ?Evaluate@TraversalAnimDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AA05E8
// RVA : 0x00AA05E8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall TraversalAnimDone::Evaluate(
        TraversalAnimDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x49;
}


// ========================================================================
// ?Action_WaitForTraversalAnimEnter@idAction_WaitForTraversalAnim@@QAA?AVeventVoid@@PAVidEntity@@ABVidAnimWebPath@@_N@Z
// EA  : 0x82AA0630
// RVA : 0x00AA0630
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_WaitForTraversalAnim *__fastcall idAction_WaitForTraversalAnim::Action_WaitForTraversalAnimEnter(
        idAction_WaitForTraversalAnim *this,
        idState *result,
        idAI2 *entity,
        const idAnimWebPath *traversalAnimName,
        const bool runWhenDone)
{
  idAI2 *v9; // r27
  const char *v10; // r4
  unsigned __int8 v11; // r3
  idStr v13[3]; // [sp+50h] [-60h] BYREF

  v13[0].len = 0;
  v13[0].allocedAndFlag = 20;
  v9 = idAI2::CastTo(c: entity);
  v13[0].data = v13[0].baseBuffer;
  v13[0].baseBuffer[0] = 0;
  if ( runWhenDone )
    v10 = "$weaponcombat:run";
  else
    v10 = "$weaponcombat:idle";
  idStr::operator=(this: v13, text: v10);
  v11 = idAI2::WaitForTraversal(
          this: v9,
          priority: PRIORITY_LOW,
          traversalAnimRef: traversalAnimName->data,
          destAnimRef: v13[0].data,
          ev: ANIMWEB_EVENT_START_BLEND_IN);
  idState::SetEnterFailed(this: result, failed: (_cntlzw(v11) & 0x20) != 0);
  idStr::FreeData(this: v13);
  return this;
}


// ========================================================================
// __unwind$501491
// EA  : 0x82AA06E8
// RVA : 0x00AA06E8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_501491()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?Action_DodgeEnter@idAction_Dodge@@QAA?AVeventVoid@@PAVidEntity@@W4aiDodgeDir_t@@@Z
// EA  : 0x82AA0710
// RVA : 0x00AA0710
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_Dodge *__fastcall idAction_Dodge::Action_DodgeEnter(
        idAction_Dodge *this,
        eventVoid *result,
        idAI2 *entity,
        const aiDodgeDir_t dodgeDir)
{
  idAI2 *v6; // r3
  idAI2 *v7; // r31
  overrideAnim_t v8; // r5

  v6 = idAI2::CastTo(c: entity);
  v8 = animForDodgeDir[dodgeDir];
  v7 = v6;
  idAI2::WaitForOverrideAnim(this: v6, priority: PRIORITY_LOW, ot: v8, ev: ANIMWEB_EVENT_START_BLEND_OUT, force: false);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v7) == 0 )
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v7->aiVolatile.physics.moveState);
  return this;
}


// ========================================================================
// ?Action_WaitEnter@idAction_Wait@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82AA0798
// RVA : 0x00AA0798
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_Wait *__fastcall idAction_Wait::Action_WaitEnter(
        idAction_Wait *this,
        eventVoid *result,
        idAI2 *entity,
        const int time)
{
  idAI2 *v6; // r30
  idLegsFSM *ActionFSM; // r3
  idAIActionFSM *v8; // r29
  int v9; // r11

  v6 = idAI2::CastTo(c: entity);
  ActionFSM = idAI2::GetActionFSM(this: v6);
  v8 = idAIActionFSM::CastTo(c: ActionFSM);
  v9 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) + time;
  if ( time < 0 )
    v9 = -1;
  v8->actionExpireTime = v9;
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v6) != 0 )
    idAnimBaseFSM::ClearDestination(this: &v6->aiVolatile.animation.animFSM);
  else
    idAIMoveState::Stop(this: &v6->aiVolatile.physics.moveState, newStatus: 0);
  return this;
}


// ========================================================================
// ?Evaluate@DiveFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AA0838
// RVA : 0x00AA0838
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall DiveFinished::Evaluate(
        DiveFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x38;
}


// ========================================================================
// ?Action_DiveEnter@idAction_Dive@@QAA?AVeventVoid@@PAVidEntity@@W4aiMoveReason_t@@MM@Z
// EA  : 0x82AA0878
// RVA : 0x00AA0878
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_Dive *__fastcall idAction_Dive::Action_DiveEnter(
        idAction_Dive *this,
        eventVoid *result,
        idAI2 *entity,
        aiMoveReason_t moveReason,
        double diveYaw,
        double faceYaw)
{
  idAI2 *v10; // r30
  idMat3 *v11; // r3
  const idVec3 *v12; // r29
  double z; // fp12
  idMat3 *v14; // r3
  float *v15; // r31
  double x; // fp6
  double y; // fp3
  double v18; // fp7
  double v19; // fp0
  overrideAnim_t v20; // r28
  idPhysics *Physics; // r3
  float *v22; // r3
  idAIOrientation *BodyOrientation; // r3
  idPhysics *v24; // r3
  const idDeclAIBehavior *decl; // r11
  double v26; // fp31
  double v27; // fp30
  double v28; // fp29
  float *v29; // r3
  double v30; // fp8
  double v31; // fp6
  idPhysics *v32; // r3
  const idVec3 *v33; // r3
  posture_t v35; // [sp+8h] [-1C8h]
  int v36; // [sp+Ch] [-1C4h]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v37; // [sp+10h] [-1C0h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v38; // [sp+14h] [-1BCh]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v39; // [sp+18h] [-1B8h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v40; // [sp+1Ch] [-1B4h]
  int v41; // [sp+20h] [-1B0h]
  int v42; // [sp+24h] [-1ACh]
  int v43; // [sp+28h] [-1A8h]
  int v44; // [sp+2Ch] [-1A4h]
  int v45; // [sp+30h] [-1A0h]
  int v46; // [sp+34h] [-19Ch]
  int v47; // [sp+38h] [-198h]
  int v48; // [sp+3Ch] [-194h]
  int v49; // [sp+40h] [-190h]
  int v50; // [sp+44h] [-18Ch]
  int v51; // [sp+48h] [-188h]
  int v52; // [sp+4Ch] [-184h]
  int v53; // [sp+50h] [-180h]
  int v54; // [sp+54h] [-17Ch]
  int v55; // [sp+58h] [-178h]
  int v56; // [sp+60h] [-170h]
  int v57; // [sp+68h] [-168h]
  int v58; // [sp+70h] [-160h]
  int v59; // [sp+78h] [-158h]
  int v60; // [sp+80h] [-150h]
  int v61; // [sp+88h] [-148h]
  __int16 v62; // [sp+90h] [-140h] BYREF
  __int16 v63; // [sp+92h] [-13Eh] BYREF
  __int16 v64; // [sp+94h] [-13Ch] BYREF
  __int16 v65; // [sp+96h] [-13Ah] BYREF
  idMat3 v66; // [sp+98h] [-138h] BYREF
  float v67; // [sp+BCh] [-114h]
  float v68; // [sp+C0h] [-110h]
  idAIMoveParms v69; // [sp+D0h] [-100h] BYREF
  idAngles v70[4]; // [sp+120h] [-B0h] BYREF
  idAngles v71[3]; // [sp+150h] [-80h] BYREF

  v66.mat[0].y = faceYaw;
  v10 = idAI2::CastTo(c: entity);
  v66.mat[0].x = 0.0;
  v66.mat[0].z = 0.0;
  v11 = idAngles::ToMat3(this: v70, result: &v66);
  v12 = (const idVec3 *)&result[28];
  *(float *)&result[28] = v11->mat[0].x;
  *(float *)&result[32] = v11->mat[0].y;
  z = v11->mat[0].z;
  v66.mat[2].z = 0.0;
  *(float *)&result[36] = z;
  v67 = diveYaw;
  v68 = 0.0;
  v14 = idAngles::ToMat3(this: v71, result: (idMat3 *)&v66.mat[2].z);
  v15 = (float *)&result[40];
  x = v14->mat[0].x;
  *v15 = v14->mat[0].x;
  y = v14->mat[0].y;
  v15[1] = v14->mat[0].y;
  v18 = v14->mat[0].z;
  v15[2] = v14->mat[0].z;
  v19 = (float)((float)((float)x * v12->x) + (float)((float)(v12->z * (float)v18) + (float)(v12->y * (float)y)));
  if ( v19 <= 0.70710677 )
  {
    if ( v19 >= -0.70710677 )
    {
      Physics = idEntity::GetPhysics(this: v10);
      v22 = (float *)Physics->GetGravityNormal(this: Physics);
      v20 = ANIMOVERRIDE_DIVE_RIGHT;
      if ( (float)((float)(*v15 * (float)((float)(v12->z * v22[1]) - (float)(v12->y * v22[2])))
                 + (float)((float)(v15[2] * (float)((float)(v12->y * *v22) - (float)(v12->x * v22[1])))
                         + (float)(v15[1] * (float)((float)(v12->x * v22[2]) - (float)(v12->z * *v22))))) <= 0.0 )
        v20 = ANIMOVERRIDE_DIVE_LEFT;
    }
    else
    {
      v20 = ANIMOVERRIDE_DIVE_BACK;
    }
    v10->aiVolatile.memory.animAfterOverride = AIMEMORY_ANIMAFTER_OVERRIDE_IDLE;
  }
  else
  {
    v20 = ANIMOVERRIDE_DIVE_START;
  }
  BodyOrientation = idAI2::GetBodyOrientation(this: v10);
  idAIOrientation::SetIdealDir(this: BodyOrientation, ai: v10, dir: v12);
  idAI2::WaitForOverrideAnim(
    this: v10,
    priority: PRIORITY_LOW,
    ot: v20,
    ev: ANIMWEB_EVENT_START_BLEND_OUT,
    force: false);
  v10->aiVolatile.focus.enableBodyRotation = false;
  v24 = idEntity::GetPhysics(this: v10);
  decl = v10->aiEditable.behaviors.decl;
  v26 = (float)(*v15 * decl->dodging.diveDistance);
  v27 = (float)(v15[1] * decl->dodging.diveDistance);
  v28 = (float)(v15[2] * decl->dodging.diveDistance);
  v29 = (float *)v24->GetOrigin(this: v24, a2: 0);
  v30 = (float)(v29[2] + (float)v28);
  v31 = (float)(v29[1] + (float)v27);
  v66.mat[1].y = *v29 + (float)v26;
  v66.mat[2].x = v30;
  v66.mat[1].z = v31;
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v10) == 0 )
  {
    idAIMoveParms::idAIMoveParms(this: &v69);
    v32 = idEntity::GetPhysics(this: v10);
    v64 = -1;
    v65 = -1;
    v62 = -1;
    v63 = -1;
    v33 = v32->GetOrigin(this: v32, a2: 0);
    idAIMoveParms::Init(
      this: &v69,
      moveReason_: moveReason,
      startOrigin_: v33,
      goalOrigin_: (const idVec3 *)&v66.mat[1].y,
      goalEntity_: nullptr,
      goalOrientation_: &quat_identity,
      goalScenePoint_: nullptr,
      goalTolerance_: 0.1,
      intermediateTolerance_: 0.1,
      arrivalAction_: (const aiArrivalAction_t)&v65,
      arrivalPosture_: v35,
      flags_: v36,
      sourceSubWeb_: v37,
      sourceState_: v38,
      destSubWeb_: v39,
      destState_: v40,
      a17: v41,
      a18: v42,
      a19: v43,
      a20: v44,
      a21: v45,
      a22: v46,
      a23: v47,
      a24: v48,
      a25: v49,
      a26: v50,
      a27: v51,
      a28: v52,
      a29: v53,
      a30: v54,
      a31: v55,
      a32: AIARRIVAL_STOP,
      a33: v56,
      a34: POSTURE_STANDING,
      a35: v57,
      a36: 0,
      a37: v58,
      a38: &v63,
      a39: v59,
      arrivalAction__0: &v62,
      a41: v60,
      arrivalPosture_a: &v65,
      a43: v61,
      flags_a: &v64);
    idAIMoveState::StartMove(this: &v10->aiVolatile.physics.moveState, parms: &v69);
  }
  idAIFireControl::SetFireMode(this: v10->aiVolatile.fireControl, owner: v10, mode: FIREMODE_HOLDFIRE);
  return this;
}


// ========================================================================
// ?AIAction_Work@idAction_Dive@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AA0B80
// RVA : 0x00AA0B80
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_Dive::AIAction_Work(idAction_Dive *this, idAI2 *ai, idAIFSM *fsm, const int curTime)
{
  idPhysics *Physics; // r3
  float *v7; // r28
  double v8; // fp7
  double v9; // fp6
  double v10; // fp4
  idRenderWorld *renderWorld; // r26
  idRenderWorld_vtbl *v12; // r25
  double v13; // fp11
  double v14; // fp8
  double v15; // fp6
  idRenderWorld *v16; // r27
  idRenderWorld_vtbl *v17; // r26
  int v18; // r3
  idAIOrientation *BodyOrientation; // r28
  idPhysics *v20; // r3
  int v21; // r3
  idVec3 *p_idealDir; // r5
  const idVec3 *v23; // r30
  double maxRange; // fp31
  int v25; // [sp+50h] [-80h] BYREF
  __int64 v26; // [sp+58h] [-78h]
  float v27[4]; // [sp+60h] [-70h] BYREF
  float v28[4]; // [sp+70h] [-60h] BYREF

  if ( ai_debugDodge.valueInteger != 0 && ai_debugLevel.valueInteger > 0 )
  {
    Physics = idEntity::GetPhysics(this: ai);
    v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v8 = (float)(this->diveDir.x * (float)64.0);
    v9 = *v7;
    v10 = (float)(v7[2] + (float)(this->diveDir.z * (float)64.0));
    v27[1] = v7[1] + (float)(this->diveDir.y * (float)64.0);
    v27[2] = v10;
    v27[0] = (float)v9 + (float)v8;
    renderWorld = clientGame->renderWorld;
    v12 = renderWorld->__vftable;
    gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v12->DebugArrow)(
      a1: renderWorld,
      a2: &idColor::colorGreen,
      a3: v7,
      a4: v27,
      a5: 4.0);
    v13 = (float)(this->idealDir.x * (float)64.0);
    v14 = *v7;
    v15 = (float)(v7[2] + (float)(this->idealDir.z * (float)64.0));
    v28[1] = v7[1] + (float)(this->idealDir.y * (float)64.0);
    v28[2] = v15;
    v28[0] = (float)v14 + (float)v13;
    v16 = clientGame->renderWorld;
    v17 = v16->__vftable;
    v18 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, char *, int, _DWORD, double))v17->DebugArrow)(
      a1: v16,
      a2: &idColor::colorRed,
      a3: v7,
      a4: v28,
      a5: &aAvSsobjectVCom[20],
      a6: v18,
      a7: 0,
      a8: 4.0);
  }
  BodyOrientation = idAI2::GetBodyOrientation(this: ai);
  v20 = idEntity::GetPhysics(this: ai);
  v21 = (int)v20->GetGravityNormal(this: v20);
  p_idealDir = &this->idealDir;
  v23 = (const idVec3 *)v21;
  idAIOrientation::SetIdealDir(this: BodyOrientation, ai, dir: p_idealDir);
  maxRange = ai->aiConstants.movement.bodyTurnRate.maxRange;
  v26 = __PAIR64__(&unk_82390000, gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED));
  idAIOrientation::UpdateAxis(
    this: BodyOrientation,
    normal: v23,
    turnRate: maxRange,
    timeSeconds: (float)((float)v26 * (float)0.001));
  ai->actorVolatile.modelInfo.modelAxis = BodyOrientation->axis;
  idAIMoveState::ContinueMove(this: &ai->aiVolatile.physics.moveState, totalTravelTime: &v25);
}


// ========================================================================
// ?AIAction_ExitState@idAction_Dive@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AA0E00
// RVA : 0x00AA0E00
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_Dive::AIAction_ExitState(idAction_Dive *this, _exception *ai, idAIFSM *fsm, const int curTime)
{
  BYTE1(ai[218].type) = 1;
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 )
  {
    idAnimBaseFSM::ClearDestination(this: (idAnimBaseFSM *)&ai[545]);
  }
  else
  {
    idAIMoveState::ResetStuck(this: (idAIMoveState *)((char *)&ai[190].arg2 + 4));
    idAIMoveState::Stop(this: (idAIMoveState *)((char *)&ai[190].arg2 + 4), newStatus: 0);
  }
  idAI2::ClearWaitForOverrideAnim(this: (idAI2 *)ai, priority: PRIORITY_LOW);
  idAIFireControl::SetFireMode(
    this: (idAIFireControl *)DWORD1(ai[513].retval),
    owner: (idAI2 *)ai,
    mode: FIREMODE_FIREWHENREADY);
}


// ========================================================================
// ?Evaluate@MeleeFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AA0E98
// RVA : 0x00AA0E98
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall MeleeFinished::Evaluate(
        MeleeFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0xCD;
}


// ========================================================================
// ?Action_MeleeEnter@idAction_Melee@@QAA?AVeventVoid@@PAVidEntity@@W4overrideAnim_t@@_NABVidVec3@@@Z
// EA  : 0x82AA0ED8
// RVA : 0x00AA0ED8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_Melee *__fastcall idAction_Melee::Action_MeleeEnter(
        idAction_Melee *this,
        idState *result,
        idAI2 *entity,
        overrideAnim_t overrideAnim,
        const bool align,
        const idVec3 *dir)
{
  idAI2 *v11; // r31
  idAIOrientation *BodyOrientation; // r3
  bool v13; // r3

  v11 = idAI2::CastTo(c: entity);
  idAIFireControl::SetFireMode(this: v11->aiVolatile.fireControl, owner: v11, mode: FIREMODE_HOLDFIRE);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v11) != 0 )
    idAnimBaseFSM::ClearDestination(this: &v11->aiVolatile.animation.animFSM);
  else
    idAIMoveState::Stop(this: &v11->aiVolatile.physics.moveState, newStatus: 0);
  if ( align )
  {
    BodyOrientation = idAI2::GetBodyOrientation(this: v11);
    idAIOrientation::SetIdealDir(this: BodyOrientation, ai: v11, dir);
  }
  v13 = idAI2::WaitForOverrideAnim(
          this: v11,
          priority: PRIORITY_LOW,
          ot: overrideAnim,
          ev: ANIMWEB_EVENT_START_BLEND_OUT,
          force: true);
  idState::SetEnterFailed(this: result, failed: (_cntlzw(v13) & 0x20) != 0);
  return this;
}


// ========================================================================
// ?Evaluate@TurnToEntityWithOffsetFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AA0FA8
// RVA : 0x00AA0FA8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall TurnToEntityWithOffsetFinished::Evaluate(
        TurnToEntityWithOffsetFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return state[1].__vftable != nullptr ? 0 : 0x19;
}


// ========================================================================
// ?Action_TurnToPointEnter@idAction_TurnToPoint@@QAA?AVeventVoid@@PAVidEntity@@ABVidVec3@@@Z
// EA  : 0x82AA0FC0
// RVA : 0x00AA0FC0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_TurnToPoint *__fastcall idAction_TurnToPoint::Action_TurnToPointEnter(
        idAction_TurnToPoint *this,
        idState *result,
        idAI2 *entity,
        const idVec3 *dest)
{
  idAI2 *v7; // r28
  idPhysics *Physics; // r3
  int v9; // r3

  v7 = idAI2::CastTo(c: entity);
  Physics = idEntity::GetPhysics(this: v7);
  Physics->GetOrigin(this: Physics, a2: 0);
  v7->aiVolatile.focus.enableBodyRotation = true;
  v9 = TurnToPoint(ai: v7, point: dest);
  result[1].__vftable = (idState_vtbl *)v9;
  if ( v9 == 2 )
    idState::SetEnterFailed(this: result, failed: true);
  return this;
}


// ========================================================================
// ?Evaluate@EntityNear@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AA1038
// RVA : 0x00AA1038
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall EntityNear::Evaluate(
        EntityNear *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idEntity *v5; // r31
  int v8; // r31
  idPlayer *Player; // r3
  idPhysics *Physics; // r27
  idPhysics *v11; // r26
  float *v12; // r27
  float *v13; // r3
  double v14; // fp8
  double v15; // fp6
  idAIStateTransition::aiTransCode_t result; // r3
  idPhysics *v17; // r31
  idPhysics *v18; // r29
  float *v19; // r31
  float *v20; // r3
  double v21; // fp8
  double v22; // fp6
  double v23; // fp1

  v5 = (idEntity *)state[1].__vftable;
  if ( (unsigned __int8)idPlayerStart::IsTypeOf(c: v5) != 0 )
  {
    v8 = 0;
    while ( 1 )
    {
      Player = idGameLocal::GetPlayer(this: gameLocal, i: v8);
      if ( Player != nullptr )
      {
        Physics = idEntity::GetPhysics(this: Player);
        v11 = idEntity::GetPhysics(this: ai);
        v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v13 = (float *)v11->GetOrigin(this: v11, a2: 0);
        v14 = (float)(v13[1] - v12[1]);
        v15 = (float)(v13[2] - v12[2]);
        if ( (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12))
                   + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) <= (double)(float)(*(float *)&state[1].listenerList * *(float *)&state[1].listenerList) )
          break;
      }
      if ( ++v8 >= 6 )
        return 0;
    }
    return TRANSCODE_WAIT_FOR_ENTITY_FINISHED;
  }
  else
  {
    v17 = idEntity::GetPhysics(this: v5);
    v18 = idEntity::GetPhysics(this: ai);
    v19 = (float *)v17->GetOrigin(this: v17, a2: 0);
    v20 = (float *)v18->GetOrigin(this: v18, a2: 0);
    v21 = (float)(v20[1] - v19[1]);
    v22 = (float)(v20[2] - v19[2]);
    v23 = (float)((float)((float)(*v20 - *v19) * (float)(*v20 - *v19))
                + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21)));
    result = TRANSCODE_WAIT_FOR_ENTITY_FINISHED;
    if ( v23 > (float)(*(float *)&state[1].listenerList * *(float *)&state[1].listenerList) )
      return 0;
  }
  return result;
}


// ========================================================================
// ?Action_PlayVoiceOverEnter@idAction_PlayVoiceOver@@QAA?AVeventVoid@@PAVidEntity@@PBVidDeclVoiceOver@@_N@Z
// EA  : 0x82AA11C8
// RVA : 0x00AA11C8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_PlayVoiceOver *__fastcall idAction_PlayVoiceOver::Action_PlayVoiceOverEnter(
        idAction_PlayVoiceOver *this,
        idState *result,
        idAI2 *entity,
        const idDeclVoiceOver *vo,
        eventVoid wait)
{
  idAI2 *v9; // r31

  v9 = idAI2::CastTo(c: entity);
  idFaceMgr::SetEnableEyeTracking(this: &v9->aiVolatile.faceMgr, owner: v9, enable: true);
  idFaceMgr::SetEnableBlinking(this: &v9->aiVolatile.faceMgr, owner: v9, enable: true);
  idFaceMgr::SetEnableLidDeformation(this: &v9->aiVolatile.faceMgr, owner: v9, enable: true);
  idFaceMgr::SetEnableGestureAnimation(this: &v9->aiVolatile.faceMgr, owner: v9, enable: true);
  idFaceMgr::SetEnableMoodAnimation(this: &v9->aiVolatile.faceMgr, owner: v9, enable: true);
  idFaceMgr::SetEnableMoodAnimation(this: &v9->aiVolatile.faceMgr, owner: v9, enable: true);
  if ( vo != nullptr )
  {
    HIBYTE(result[1].__vftable) = wait;
    idAIVoiceController::PlayVoiceOver(
      this: &v9->aiVolatile.voiceController,
      ai: v9,
      vo,
      priority: AIVOICEPRIORITY_MED,
      samePriorityInterupts: true);
  }
  else
  {
    idState::SetEnterFailed(this: result, failed: true);
  }
  return this;
}


// ========================================================================
// ?Action_StopVoiceOverEnter@idAction_StopVoiceOver@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82AA12A8
// RVA : 0x00AA12A8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_StopVoiceOver *__fastcall idAction_StopVoiceOver::Action_StopVoiceOverEnter(
        idAction_StopVoiceOver *this,
        eventVoid *result,
        idAI2 *entity)
{
  idAI2 *v4; // r3

  v4 = idAI2::CastTo(c: entity);
  idAIVoiceController::StopVoiceOver(this: &v4->aiVolatile.voiceController, ai: v4);
  return this;
}


// ========================================================================
// ?AIAction_ExitState@idAction_PlayInteractionVoiceOver@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AA12F0
// RVA : 0x00AA12F0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_PlayInteractionVoiceOver::AIAction_ExitState(
        idAction_PlayInteractionVoiceOver *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  if ( fsm->lastTransitionCode == 65 )
  {
    idAIVoiceController::FadeVoiceOver(this: &ai->aiVolatile.voiceController, ai);
    if ( this->abortScript && idComponentActionScript::RunningActionScript(this: &ai->actionScript, entity: ai) )
      idAI2::EndActionScript(this: ai);
  }
}


// ========================================================================
// ?Action_PlayOverrideAnimEnter@idAction_PlayOverrideAnim@@QAA?AVeventVoid@@PAVidEntity@@W4overrideAnim_t@@@Z
// EA  : 0x82AA1370
// RVA : 0x00AA1370
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_PlayOverrideAnim *__fastcall idAction_PlayOverrideAnim::Action_PlayOverrideAnimEnter(
        idAction_PlayOverrideAnim *this,
        idState *result,
        idAI2 *entity,
        overrideAnim_t overrideAnim)
{
  idAI2 *v7; // r31
  bool v8; // r11
  idState *v9; // r3
  BOOL v10; // r29

  v7 = idAI2::CastTo(c: entity);
  v8 = idAI2::WaitForOverrideAnim(
         this: v7,
         priority: PRIORITY_LOW,
         ot: overrideAnim,
         ev: ANIMWEB_EVENT_START_BLEND_OUT,
         force: false);
  v9 = result;
  v10 = v8;
  idState::SetEnterFailed(this: v9, failed: (_cntlzw(v8) & 0x20) != 0);
  if ( v10 )
  {
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v7) == 0 )
    {
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v7->aiVolatile.physics.moveState);
      return this;
    }
  }
  else
  {
    idLib::Warning(fmt: "ACTION_PLAY_OVERRIDE_ANIM failed.");
  }
  return this;
}


// ========================================================================
// ?Action_PlayOverrideAnimInterruptEnter@idAction_PlayOverrideAnimInterrupt@@QAA?AVeventVoid@@PAVidEntity@@W4overrideAnim_t@@@Z
// EA  : 0x82AA1410
// RVA : 0x00AA1410
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_PlayOverrideAnimInterrupt *__fastcall idAction_PlayOverrideAnimInterrupt::Action_PlayOverrideAnimInterruptEnter(
        idAction_PlayOverrideAnimInterrupt *this,
        idState *result,
        idAI2 *entity,
        overrideAnim_t overrideAnim)
{
  idAI2 *v7; // r31
  bool v8; // r11
  idState *v9; // r3
  BOOL v10; // r29

  v7 = idAI2::CastTo(c: entity);
  v8 = idAI2::WaitForOverrideAnim(
         this: v7,
         priority: PRIORITY_LOW,
         ot: overrideAnim,
         ev: ANIMWEB_EVENT_START_BLEND_OUT,
         force: false);
  v9 = result;
  v10 = v8;
  idState::SetEnterFailed(this: v9, failed: (_cntlzw(v8) & 0x20) != 0);
  if ( v10 )
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v7->aiVolatile.physics.moveState);
  else
    idLib::Warning(fmt: "ACTION_PLAY_OVERRIDE_ANIM failed.");
  return this;
}


// ========================================================================
// ?Evaluate@LeapAttackFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AA1498
// RVA : 0x00AA1498
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall LeapAttackFinished::Evaluate(
        LeapAttackFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0xCE;
}


// ========================================================================
// ?Action_LeapAttackEnter@idAction_LeapAttack@@QAA?AVeventVoid@@PAVidEntity@@ABVidVec3@@@Z
// EA  : 0x82AA14D8
// RVA : 0x00AA14D8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_LeapAttack *__fastcall idAction_LeapAttack::Action_LeapAttackEnter(
        idAction_LeapAttack *this,
        eventVoid *result,
        idAI2 *entity,
        const idVec3 *leapTarget)
{
  idAI2 *v6; // r31
  idPhysics *Physics; // r3
  idRenderWorld_vtbl *v8; // r29
  int v9; // r3
  idPhysics *v10; // r3
  float *v11; // r3
  double v12; // fp10
  double v15; // fp2
  double v16; // fp5
  double v17; // fp2
  idAIOrientation *BodyOrientation; // r3
  idPhysics *v19; // r3
  const idVec3 *v20; // r30
  idAIOrientation *v21; // r3
  idVec3 v23[6]; // [sp+50h] [-50h] BYREF

  v6 = idAI2::CastTo(c: entity);
  v6->aiVolatile.memory.leapTarget = *leapTarget;
  if ( ai_debugLevel.valueInteger > 0 && ai_debugLeapAttack.valueInteger != 0 )
  {
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorYellow,
      a3: leapTarget,
      a4: 5000,
      a5: true);
    Physics = idEntity::GetPhysics(this: v6);
    v8 = clientGame->renderWorld->__vftable;
    v9 = (int)Physics->GetGravityNormal(this: Physics);
    ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, int, double))v8->DebugCircle)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorYellow,
      a3: leapTarget,
      a4: v9,
      a5: 24.0);
  }
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v6) == 0 )
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v6->aiVolatile.physics.moveState);
  v10 = idEntity::GetPhysics(this: v6);
  v11 = (float *)v10->GetOrigin(this: v10, a2: 0);
  v12 = (float)(leapTarget->y - v11[1]);
  _FP5 = (float)((float)((float)((float)(leapTarget->x - *v11) * (float)(leapTarget->x - *v11))
                       + (float)((float)v12 * (float)v12))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v15 = __frsqrte(_FP3);
  v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                      * (float)((float)((float)((float)(leapTarget->x - *v11) * (float)(leapTarget->x - *v11)) + (float)((float)v12 * (float)v12))
                                                                                              * (float)0.5))
                                                                              * (float)v15)
                                                                      - (float)1.5)
                                                      * (float)v15)
                                              * (float)((float)((float)((float)(leapTarget->x - *v11)
                                                                      * (float)(leapTarget->x - *v11))
                                                              + (float)((float)v12 * (float)v12))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                              * (float)((float)((float)((float)(leapTarget->x - *v11) * (float)(leapTarget->x - *v11))
                                                                                              + (float)((float)v12 * (float)v12))
                                                                                      * (float)0.5))
                                                                      * (float)v15)
                                                              - (float)1.5)
                                              * (float)v15))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v15
                                                      * (float)((float)((float)((float)(leapTarget->x - *v11)
                                                                              * (float)(leapTarget->x - *v11))
                                                                      + (float)((float)v12 * (float)v12))
                                                              * (float)0.5))
                                              * (float)v15)
                                      - (float)1.5)
                      * (float)v15));
  v17 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)(leapTarget->x - *v11) * (float)(leapTarget->x - *v11)) + (float)((float)v12 * (float)v12)) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                              * (float)v15)
                                                                                      * (float)((float)((float)((float)(leapTarget->x - *v11) * (float)(leapTarget->x - *v11)) + (float)((float)v12 * (float)v12))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)(leapTarget->x - *v11) * (float)(leapTarget->x - *v11)) + (float)((float)v12 * (float)v12)) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                      * (float)v15))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                                              * (float)((float)((float)((float)(leapTarget->x - *v11) * (float)(leapTarget->x - *v11)) + (float)((float)v12 * (float)v12)) * (float)0.5))
                                                                                      * (float)v15)
                                                                              - (float)1.5)
                                                              * (float)v15))
                                              * (float)((float)((float)((float)(leapTarget->x - *v11)
                                                                      * (float)(leapTarget->x - *v11))
                                                              + (float)((float)v12 * (float)v12))
                                                      * (float)0.5))
                                      * (float)v16)
                              - (float)1.5)
              * (float)v16);
  v23[0].x = (float)(leapTarget->x - *v11) * (float)v17;
  v23[0].z = (float)v17 * (float)0.0;
  v23[0].y = (float)v12 * (float)v17;
  BodyOrientation = idAI2::GetBodyOrientation(this: v6);
  idAIOrientation::SetIdealDir(this: BodyOrientation, ai: v6, dir: v23);
  v19 = idEntity::GetPhysics(this: v6);
  v20 = v19->GetGravityNormal(this: v19);
  v21 = idAI2::GetBodyOrientation(this: v6);
  idAIOrientation::SetAxis(this: v21, dir: v23, gravityDir: v20);
  idAI2::WaitForOverrideAnim(
    this: v6,
    priority: PRIORITY_LOW,
    ot: ANIMOVERRIDE_LEAP_ATTACK,
    ev: ANIMWEB_EVENT_START_BLEND_OUT,
    force: false);
  return this;
}


// ========================================================================
// ?Evaluate@DrawWeaponFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AA1708
// RVA : 0x00AA1708
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall DrawWeaponFinished::Evaluate(
        DrawWeaponFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIStateTransition::aiTransCode_t result; // r3
  int GameMs; // r30
  int lastConfirmedStimTime; // r10

  if ( idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) )
    return TRANSCODE_ACTION_DRAW_WEAPON_FINISHED;
  if ( ai->GetEquippedWeapon(this: ai) == nullptr )
    return 0;
  if ( idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX) == nullptr )
    return 0;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  lastConfirmedStimTime = idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX)->lastConfirmedStimTime;
  result = TRANSCODE_ACTION_DRAW_WEAPON_FINISHED;
  if ( GameMs - lastConfirmedStimTime >= 1000 )
    return 0;
  return result;
}


// ========================================================================
// ?AIAction_ExitState@idAction_DrawWeapon@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AA17C8
// RVA : 0x00AA17C8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_DrawWeapon::AIAction_ExitState(
        idAction_HolsterWeapon *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAI2::ClearWaitForOverrideAnim(this: ai, priority: PRIORITY_LOW);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
    ai->aiVolatile.animation.animFSM.enableIdlePump = true;
}


// ========================================================================
// ?Evaluate@HolsterWeaponFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AA1820
// RVA : 0x00AA1820
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall HolsterWeaponFinished::Evaluate(
        HolsterWeaponFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x43;
}


// ========================================================================
// ?Action_HolsterWeaponEnter@idAction_HolsterWeapon@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82AA1860
// RVA : 0x00AA1860
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_HolsterWeapon *__fastcall idAction_HolsterWeapon::Action_HolsterWeaponEnter(
        idAction_HolsterWeapon *this,
        eventVoid *result,
        idAI2 *entity)
{
  idAI2 *v4; // r31
  alertCycle_t AlertCycle; // r3
  aiSubWeb_t v6; // r3
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v8; // [sp+50h] [-20h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v9; // [sp+52h] [-1Eh] BYREF

  v4 = idAI2::CastTo(c: entity);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v4) != 0 )
    v4->aiVolatile.animation.animFSM.enableIdlePump = false;
  v9.value = -1;
  v8.value = -1;
  AlertCycle = idAI2::GetAlertCycle(this: v4);
  v6 = idAI2::AlertCycleToSubWeb(this: v4, ac: AlertCycle);
  idAI2::FindAnimWebAndStateIndices(
    this: v4,
    web: AIANIMWEB_BODY,
    subWeb: v6,
    stateName: "idle",
    changeWeapon: true,
    newWeapon: nullptr,
    subWebIndex: &v9,
    stateIndex: &v8);
  if ( idAI2::ChangeAnimState(
         this: v4,
         web: AIANIMWEB_BODY,
         subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v9.value,
         stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v8.value,
         interruptPath: INTR_PATH_NO,
         interruptBlend: INTR_BLEND_NO) == 1 )
    idAI2::SetAnimWebEvent(
      this: v4,
      web: AIANIMWEB_BODY,
      priority: PRIORITY_LOW,
      swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v9.value,
      si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v8.value,
      eventType: ANIMWEB_EVENT_START_BLEND_IN,
      eventDef: &EV_AnimWeb_Wait);
  return this;
}


// ========================================================================
// ?Evaluate@CoverActionFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AA1950
// RVA : 0x00AA1950
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall CoverActionFinished::Evaluate(
        CoverActionFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  coverAction_t coverAction; // r11
  const aiSenseState_t *EnemySenseState; // r3
  aiSenseState_t *v9; // r30
  idAICover *p_currentCover; // r31
  double v11; // fp31
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v14; // zf

  coverAction = ai->aiVolatile.cover.coverAction;
  if ( coverAction == COVERACTION_BLINDFIRE_LEFT
    || coverAction == COVERACTION_BLINDFIRE_RIGHT
    || coverAction == COVERACTION_BLINDFIRE_OVER )
  {
    v14 = idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW);
    result = TRANSCODE_COVER_ACTION_FINISHED;
    if ( v14 )
      return result;
  }
  else
  {
    if ( curTime > ai->aiVolatile.memory.endCoverActionTime )
      return TRANSCODE_COVER_ACTION_FINISHED;
    if ( coverAction != COVERACTION_NONE )
    {
      EnemySenseState = idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
      v9 = (aiSenseState_t *)EnemySenseState;
      if ( EnemySenseState != nullptr && curTime - EnemySenseState->lastConfirmedStimTime < 5000 )
      {
        p_currentCover = &ai->aiVolatile.memory.currentCover;
        if ( (unsigned __int8)idAICover::IsValid(this: p_currentCover) != 0 )
        {
          v11 = idCoverQuery::MAX_COVER_ARC_ACOS_DEGREES;
          ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v9);
          if ( !idAICover::IsPointInArc(this: p_currentCover, point: &ConfirmedPhysicalSafe->origin, arcAcos: v11) )
            return TRANSCODE_COVER_ACTION_FINISHED;
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// ?AIAction_ExitState@idAction_PerformCoverAction@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AA1A58
// RVA : 0x00AA1A58
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_PerformCoverAction::AIAction_ExitState(
        idAction_PerformCoverAction *this,
        _exception *ai,
        idAIFSM *fsm,
        const int curTime)
{
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 )
    BYTE8(ai[596].retval) = 1;
}


// ========================================================================
// ?Action_WaitForPlayerInteractionEnter@idAction_WaitForPlayerInteraction@@QAA?AVeventVoid@@PAVidEntity@@M@Z
// EA  : 0x82AA1AA8
// RVA : 0x00AA1AA8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_WaitForPlayerInteraction *__fastcall idAction_WaitForPlayerInteraction::Action_WaitForPlayerInteractionEnter(
        idAction_WaitForPlayerInteraction *this,
        eventVoid *result,
        idAI2 *entity,
        double distance)
{
  idAI2 *v7; // r3

  v7 = idAI2::CastTo(c: entity);
  *(float *)&result[28] = distance;
  v7->aiVolatile.memory.interactionIsUsable = true;
  return this;
}


// ========================================================================
// ?Evaluate@AIVarExpressionTrue@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AA1B10
// RVA : 0x00AA1B10
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

BOOL __fastcall AIVarExpressionTrue::Evaluate(
        AIVarExpressionTrue *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIVar *v6; // r3

  v6 = idAIBlackboard::Find(this: &gameLocal->aiBlackboard, name: ai->aiVolatile.memory.varName.data);
  return v6 == nullptr
      || v6->Compare_3(this: v6, a2: ai->aiVolatile.memory.varValue.data, a3: ai->aiVolatile.memory.varOp);
}


// ========================================================================
// ?Action_WaitForAIVarEnter@idAction_WaitForAIVar@@QAA?AVeventVoid@@PAVidEntity@@PBDW4aiVarOp_t@@1@Z
// EA  : 0x82AA1BB0
// RVA : 0x00AA1BB0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_WaitForAIVar *__fastcall idAction_WaitForAIVar::Action_WaitForAIVarEnter(
        idAction_WaitForAIVar *this,
        eventVoid *result,
        idAI2 *entity,
        const char *varName,
        aiVarOp_t op,
        const char *varValue)
{
  idAI2 *v10; // r3

  v10 = idAI2::CastTo(c: entity);
  idAIMemory::SetAIVarExpression(this: &v10->aiVolatile.memory, name: varName, op, value: varValue);
  return this;
}


// ========================================================================
// ?AIAction_Work@idAction_PerfectMovement@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AA1BF8
// RVA : 0x00AA1BF8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_PerfectMovement::AIAction_Work(
        idAction_PerfectMovement *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  if ( ai->aiVolatile.physics.moveState.movementMode != AIMOVEMODE_DEAD )
    idAIMoveState::SetMovementModeForReal(this: &ai->aiVolatile.physics.moveState, mode: AIMOVEMODE_PERFECTORIGIN);
}


// ========================================================================
// ?Action_SetAlertCycleEnter@idAction_SetAlertCycle@@QAA?AVeventVoid@@PAVidEntity@@W4alertCycle_t@@@Z
// EA  : 0x82AA1C18
// RVA : 0x00AA1C18
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetAlertCycle *__fastcall idAction_SetAlertCycle::Action_SetAlertCycleEnter(
        idAction_SetAlertCycle *this,
        eventVoid *result,
        idAI2 *entity,
        alertCycle_t ac)
{
  idAI2 *v6; // r29

  v6 = idAI2::CastTo(c: entity);
  idAI2::SetAlertCycle(this: v6, ac);
  idAI2::UpdateTravelFlags(this: v6);
  return this;
}


// ========================================================================
// ?Action_SetSubWebEnter@idAction_SetSubWeb@@QAA?AVeventVoid@@PAVidEntity@@W4aiSubWeb_t@@@Z
// EA  : 0x82AA1C58
// RVA : 0x00AA1C58
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetSubWeb *__fastcall idAction_SetSubWeb::Action_SetSubWebEnter(
        idAction_SetSubWeb *this,
        eventVoid *result,
        idAI2 *entity,
        aiSubWeb_t sw)
{
  idAI2 *v6; // r3

  v6 = idAI2::CastTo(c: entity);
  idAI2::SetSubWeb(this: v6, sw);
  return this;
}


// ========================================================================
// ?Action_SetFocusEnter@idAction_SetFocus@@QAA?AVeventVoid@@PAVidEntity@@PBV3@_N22W4aimPoint_t@@@Z
// EA  : 0x82AA1CA0
// RVA : 0x00AA1CA0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetFocus *__fastcall idAction_SetFocus::Action_SetFocusEnter(
        idAction_SetFocus *this,
        eventVoid *result,
        idAI2 *entity,
        const idEntity *ent,
        const bool aiming,
        bool keepFocusInView,
        const bool trackOnlyVisible,
        aimPoint_t aimPoint)
{
  idAI2 *v13; // r3

  v13 = idAI2::CastTo(c: entity);
  if ( aiming )
  {
    if ( ent != nullptr )
      idAI2::SetAimFocusEntity(this: v13, ent, keepFocusInView, aimPoint, timeout: -1);
    else
      idAI2::ClearAimFocus(this: v13);
    return this;
  }
  else
  {
    if ( ent != nullptr )
      idAI2::SetLookFocusEntity(this: v13, ent, keepFocusInView, aimPoint, timeout: -1);
    else
      idAI2::ClearLookFocus(this: v13);
    return this;
  }
}


// ========================================================================
// ?Action_ClearLookFocusEnter@idAction_ClearLookFocus@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82AA1D48
// RVA : 0x00AA1D48
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ClearLookFocus *__fastcall idAction_ClearLookFocus::Action_ClearLookFocusEnter(
        idAction_ClearLookFocus *this,
        eventVoid *result,
        idAI2 *entity)
{
  idAI2 *v4; // r3

  v4 = idAI2::CastTo(c: entity);
  idAI2::ClearLookFocus(this: v4);
  return this;
}


// ========================================================================
// ?Action_ClearAimFocusEnter@idAction_ClearAimFocus@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82AA1D80
// RVA : 0x00AA1D80
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ClearAimFocus *__fastcall idAction_ClearAimFocus::Action_ClearAimFocusEnter(
        idAction_ClearAimFocus *this,
        eventVoid *result,
        idAI2 *entity)
{
  idAI2 *v4; // r3

  v4 = idAI2::CastTo(c: entity);
  idAI2::ClearAimFocus(this: v4);
  return this;
}


// ========================================================================
// ?Action_SetAimPointEnter@idAction_SetAimPoint@@QAA?AVeventVoid@@PAVidEntity@@W4aimPoint_t@@@Z
// EA  : 0x82AA1DB8
// RVA : 0x00AA1DB8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetAimPoint *__fastcall idAction_SetAimPoint::Action_SetAimPointEnter(
        idAction_SetAimPoint *this,
        eventVoid *result,
        idAI2 *entity,
        aimPoint_t aimPoint)
{
  idAI2 *v6; // r3

  v6 = idAI2::CastTo(c: entity);
  idAI2::SetAimFocusAimPoint(this: v6, point: aimPoint);
  return this;
}


// ========================================================================
// ?Action_SetFireModeEnter@idAction_SetFireMode@@QAA?AVeventVoid@@PAVidEntity@@W4aiFireMode_t@@@Z
// EA  : 0x82AA1E00
// RVA : 0x00AA1E00
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetFireMode *__fastcall idAction_SetFireMode::Action_SetFireModeEnter(
        idAction_SetFireMode *this,
        eventVoid *result,
        idAI2 *entity,
        aiFireMode_t fireMode)
{
  idAI2 *v6; // r4
  idAIFireControl *fireControl; // r3

  v6 = idAI2::CastTo(c: entity);
  fireControl = v6->aiVolatile.fireControl;
  if ( fireControl != nullptr )
    idAIFireControl::SetFireMode(this: fireControl, owner: v6, mode: fireMode);
  return this;
}


// ========================================================================
// ?Action_SetScriptAbortEnter@idAction_SetScriptAbort@@QAA?AVeventVoid@@PAVidEntity@@_N1@Z
// EA  : 0x82AA1E60
// RVA : 0x00AA1E60
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetScriptAbort *__fastcall idAction_SetScriptAbort::Action_SetScriptAbortEnter(
        idAction_SetScriptAbort *this,
        eventVoid *result,
        idAI2 *entity,
        const bool abortForCombat,
        const bool abortForSearch)
{
  idAI2::CastTo(c: entity)->aiVolatile.script.flags = abortForCombat | (!abortForSearch ? 0 : 2);
  return this;
}


// ========================================================================
// ?Action_SetPostureEnter@idAction_SetPosture@@QAA?AVeventVoid@@PAVidEntity@@W4posture_t@@@Z
// EA  : 0x82AA1EB8
// RVA : 0x00AA1EB8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetPosture *__fastcall idAction_SetPosture::Action_SetPostureEnter(
        idAction_SetPosture *this,
        eventVoid *result,
        idAI2 *entity,
        posture_t posture)
{
  idAI2 *v6; // r3

  v6 = idAI2::CastTo(c: entity);
  v6->SetPosture(this: v6, a2: posture);
  return this;
}


// ========================================================================
// ?Action_SetWalkStateEnter@idAction_SetWalkState@@QAA?AVeventVoid@@PAVidEntity@@W4walkState_t@@@Z
// EA  : 0x82AA1F10
// RVA : 0x00AA1F10
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetWalkState *__fastcall idAction_SetWalkState::Action_SetWalkStateEnter(
        idAction_SetWalkState *this,
        eventVoid *result,
        idAI2 *entity,
        walkState_t ws)
{
  idAI2 *v6; // r29

  v6 = idAI2::CastTo(c: entity);
  v6->SetWalkState(this: v6, a2: ws);
  idAI2::UpdateTravelFlags(this: v6);
  return this;
}


// ========================================================================
// ?Action_SetSitStateEnter@idAction_SetSitState@@QAA?AVeventVoid@@PAVidEntity@@W4sitState_t@@@Z
// EA  : 0x82AA1F58
// RVA : 0x00AA1F58
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetSitState *__fastcall idAction_SetSitState::Action_SetSitStateEnter(
        idAction_SetSitState *this,
        eventVoid *result,
        idAI2 *entity,
        sitState_t ss)
{
  idAI2::CastTo(c: entity)->actorEditable.sitState = ss;
  return this;
}


// ========================================================================
// ?Action_SetStandStateEnter@idAction_SetStandState@@QAA?AVeventVoid@@PAVidEntity@@W4standState_t@@@Z
// EA  : 0x82AA1FA0
// RVA : 0x00AA1FA0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetStandState *__fastcall idAction_SetStandState::Action_SetStandStateEnter(
        idAction_SetStandState *this,
        eventVoid *result,
        idAI2 *entity,
        standState_t ss)
{
  idAI2::CastTo(c: entity)->actorEditable.standState = ss;
  return this;
}


// ========================================================================
// ?Action_IgnorePlayerApproachEnter@idAction_IgnorePlayerApproach@@QAA?AVeventVoid@@PAVidEntity@@_N@Z
// EA  : 0x82AA1FE8
// RVA : 0x00AA1FE8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_IgnorePlayerApproach *__fastcall idAction_IgnorePlayerApproach::Action_IgnorePlayerApproachEnter(
        idAction_IgnorePlayerApproach *this,
        eventVoid *result,
        idAI2 *entity,
        const bool permanent)
{
  idAI2 *v6; // r3
  idAI2 *v7; // r31

  v6 = idAI2::CastTo(c: entity);
  v7 = v6;
  v6->aiVolatile.script.flags |= 0x20u;
  if ( permanent )
    v6->DisableAIEventResponse(this: v6, a2: AIEVENT_PLAYER_INTERACTION);
  idFaceMgr::SetEnableEyeTracking(this: &v7->aiVolatile.faceMgr, owner: v7, enable: true);
  idFaceMgr::SetEnableBlinking(this: &v7->aiVolatile.faceMgr, owner: v7, enable: true);
  idFaceMgr::SetEnableLidDeformation(this: &v7->aiVolatile.faceMgr, owner: v7, enable: true);
  idFaceMgr::SetEnableGestureAnimation(this: &v7->aiVolatile.faceMgr, owner: v7, enable: true);
  idFaceMgr::SetEnableMoodAnimation(this: &v7->aiVolatile.faceMgr, owner: v7, enable: true);
  idFaceMgr::SetEnableMoodAnimation(this: &v7->aiVolatile.faceMgr, owner: v7, enable: true);
  return this;
}


// ========================================================================
// ?Action_NoticePlayerApproachEnter@idAction_NoticePlayerApproach@@QAA?AVeventVoid@@PAVidEntity@@_N@Z
// EA  : 0x82AA20B0
// RVA : 0x00AA20B0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_NoticePlayerApproach *__fastcall idAction_NoticePlayerApproach::Action_NoticePlayerApproachEnter(
        idAction_NoticePlayerApproach *this,
        eventVoid *result,
        idAI2 *entity,
        const bool permanent)
{
  idAI2 *v6; // r3

  v6 = idAI2::CastTo(c: entity);
  v6->aiVolatile.script.flags &= ~0x20u;
  if ( permanent )
    v6->EnableAIEventResponse(this: v6, a2: AIEVENT_PLAYER_INTERACTION);
  return this;
}


// ========================================================================
// ?Action_SetPlayerEnemyEnter@idAction_SetPlayerEnemy@@QAA?AVeventVoid@@PAVidEntity@@W4aiPlayer_t@@@Z
// EA  : 0x82AA2128
// RVA : 0x00AA2128
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetPlayerEnemy *__fastcall idAction_SetPlayerEnemy::Action_SetPlayerEnemyEnter(
        idAction_SetPlayerEnemy *this,
        eventVoid *result,
        idAI2 *entity,
        unsigned int player)
{
  idAI2 *v6; // r29
  idPlayer *PlayerTarget; // r3

  v6 = idAI2::CastTo(c: entity);
  PlayerTarget = idAI2::GetPlayerTarget(this: v6, player);
  idAI2::GiveAwarenessOfEntity(this: v6, ent: PlayerTarget, alertCycle: ALERTCYCLE_COMBAT);
  return this;
}


// ========================================================================
// ?Action_SetEnemyEnter@idAction_SetEnemy@@QAA?AVeventVoid@@PAVidEntity@@PBV3@@Z
// EA  : 0x82AA2170
// RVA : 0x00AA2170
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetEnemy *__fastcall idAction_SetEnemy::Action_SetEnemyEnter(
        idAction_SetEnemy *this,
        eventVoid *result,
        idAI2 *entity,
        const idEntity *enemy)
{
  idAI2 *v6; // r3

  v6 = idAI2::CastTo(c: entity);
  idAI2::GiveAwarenessOfEntity(this: v6, ent: enemy, alertCycle: ALERTCYCLE_COMBAT);
  return this;
}


// ========================================================================
// ?Action_SearchToTargetEnter@idAction_SearchToTarget@@QAA?AVeventVoid@@PAVidEntity@@PBV3@@Z
// EA  : 0x82AA21C0
// RVA : 0x00AA21C0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SearchToTarget *__fastcall idAction_SearchToTarget::Action_SearchToTargetEnter(
        idAction_SearchToTarget *this,
        eventVoid *result,
        idAI2 *entity,
        const idEntity *target)
{
  idAI2 *v6; // r3

  v6 = idAI2::CastTo(c: entity);
  idAI2::GiveAwarenessOfEntity(this: v6, ent: target, alertCycle: ALERTCYCLE_SEARCH);
  return this;
}


// ========================================================================
// ?Action_SetPlayerFocusEnter@idAction_SetPlayerFocus@@QAA?AVeventVoid@@PAVidEntity@@W4aiPlayer_t@@_N22W4aimPoint_t@@@Z
// EA  : 0x82AA2210
// RVA : 0x00AA2210
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetPlayerFocus *__fastcall idAction_SetPlayerFocus::Action_SetPlayerFocusEnter(
        idAction_SetPlayerFocus *this,
        eventVoid *result,
        idAI2 *entity,
        unsigned int player,
        const bool aiming,
        bool keepFocusInView,
        const bool trackOnlyVisible,
        aimPoint_t aimPoint)
{
  idAI2 *v12; // r27
  idPlayer *PlayerTarget; // r3

  v12 = idAI2::CastTo(c: entity);
  PlayerTarget = idAI2::GetPlayerTarget(this: v12, player);
  idAI2::SetAimFocusEntity(this: v12, ent: PlayerTarget, keepFocusInView, aimPoint, timeout: -1);
  return this;
}


// ========================================================================
// ?Action_SetActionNodeGroupEnter@idAction_SetActionNodeGroup@@QAA?AVeventVoid@@PAVidEntity@@PBD@Z
// EA  : 0x82AA2268
// RVA : 0x00AA2268
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetActionNodeGroup *__fastcall idAction_SetActionNodeGroup::Action_SetActionNodeGroupEnter(
        idAction_SetActionNodeGroup *this,
        eventVoid *result,
        idAI2 *entity,
        const char *groupName)
{
  idAI2 *v6; // r3

  v6 = idAI2::CastTo(c: entity);
  idAI2::SetActionNodeGroupName(this: v6, groupName);
  return this;
}


// ========================================================================
// ?Action_TriggerEnter@idAction_Trigger@@QAA?AVeventVoid@@PAVidEntity@@0@Z
// EA  : 0x82AA22B0
// RVA : 0x00AA22B0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_Trigger *__fastcall idAction_Trigger::Action_TriggerEnter(
        idAction_Trigger *this,
        eventVoid *result,
        idAI2 *entity,
        idEntity *ent)
{
  idAI2 *v6; // r4

  v6 = idAI2::CastTo(c: entity);
  if ( ent != nullptr )
    idEntity::Activate(this: ent, activator: v6);
  else
    idLib::Warning(fmt: "AI action script attempted to trigger a NULL entity.", v6);
  return this;
}


// ========================================================================
// ?Action_EnableDamageEnter@idAction_EnableDamage@@QAA?AVeventVoid@@PAVidEntity@@_N1@Z
// EA  : 0x82AA2318
// RVA : 0x00AA2318
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_EnableDamage *__fastcall idAction_EnableDamage::Action_EnableDamageEnter(
        idAction_EnableDamage *this,
        eventVoid *result,
        idAI2 *entity,
        bool enabled,
        const bool permanent)
{
  idAI2 *v8; // r3

  v8 = idAI2::CastTo(c: entity);
  if ( permanent )
    *(_BYTE *)&v8->flags = (2 * enabled) & 2 | *(_BYTE *)&v8->flags & 0xFD;
  else
    idAI2::SetActionScriptFlag(this: v8, flags: 64, setFlag: enabled);
  return this;
}


// ========================================================================
// ?Action_EnablePainEnter@idAction_EnablePain@@QAA?AVeventVoid@@PAVidEntity@@_N@Z
// EA  : 0x82AA2380
// RVA : 0x00AA2380
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_EnablePain *__fastcall idAction_EnablePain::Action_EnablePainEnter(
        idAction_EnablePain *this,
        eventVoid *result,
        idAI2 *entity,
        const bool enabled)
{
  idAI2 *v6; // r3

  v6 = idAI2::CastTo(c: entity);
  *((_BYTE *)&v6->aiEditable.death + 84) = (enabled << 7) | *((_BYTE *)&v6->aiEditable.death + 84) & 0x7F;
  return this;
}


// ========================================================================
// ?Action_EnableAutoFocusEnter@idAction_EnableAutoFocus@@QAA?AVeventVoid@@PAVidEntity@@_N1@Z
// EA  : 0x82AA23D0
// RVA : 0x00AA23D0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_EnableAutoFocus *__fastcall idAction_EnableAutoFocus::Action_EnableAutoFocusEnter(
        idAction_EnableAutoFocus *this,
        eventVoid *result,
        idAI2 *entity,
        const bool enabled,
        const bool permanent)
{
  idAI2 *v8; // r3
  idAI2::idAIVolatile::idAIScriptInfo *p_script; // r11
  int flags; // r9

  v8 = idAI2::CastTo(c: entity);
  p_script = &v8->aiVolatile.script;
  flags = v8->aiVolatile.script.flags;
  if ( enabled )
  {
    p_script->flags = flags | 0x200;
    if ( permanent )
    {
      idAI2::SetEnableAutoFocus(this: v8, enable: true);
      return this;
    }
  }
  else
  {
    p_script->flags = flags & 0xFFFFFDFF;
    if ( permanent )
      idAI2::SetEnableAutoFocus(this: v8, enable: false);
  }
  return this;
}


// ========================================================================
// ?Action_EnableBodyRotationEnter@idAction_EnableBodyRotation@@QAA?AVeventVoid@@PAVidEntity@@_N@Z
// EA  : 0x82AA2458
// RVA : 0x00AA2458
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_EnableBodyRotation *__fastcall idAction_EnableBodyRotation::Action_EnableBodyRotationEnter(
        idAction_EnableBodyRotation *this,
        eventVoid *result,
        idAI2 *entity,
        bool enabled)
{
  idAI2::CastTo(c: entity)->aiVolatile.focus.enableBodyRotation = enabled;
  return this;
}


// ========================================================================
// ?Action_EnableWalkIKEnter@idAction_EnableWalkIK@@QAA?AVeventVoid@@PAVidEntity@@_N@Z
// EA  : 0x82AA24B8
// RVA : 0x00AA24B8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_EnableWalkIK *__fastcall idAction_EnableWalkIK::Action_EnableWalkIKEnter(
        idAction_EnableWalkIK *this,
        eventVoid *result,
        idAI2 *entity,
        const bool enabled)
{
  idAnimator_WalkIK *p_walkIK; // r3

  p_walkIK = &idAI2::CastTo(c: entity)->walkIK;
  if ( enabled )
    idAnimator_WalkIK::EnableAll(this: p_walkIK);
  else
    idAnimator_WalkIK::DisableAll(this: p_walkIK);
  return this;
}


// ========================================================================
// ?Action_EnableHeadTrackingEnter@idAction_EnableHeadTracking@@QAA?AVeventVoid@@PAVidEntity@@_N@Z
// EA  : 0x82AA2518
// RVA : 0x00AA2518
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_EnableHeadTracking *__fastcall idAction_EnableHeadTracking::Action_EnableHeadTrackingEnter(
        idAction_EnableHeadTracking *this,
        eventVoid *result,
        idAI2 *entity,
        bool enabled)
{
  idAI2 *v6; // r3

  v6 = idAI2::CastTo(c: entity);
  idAI2::SetEnableHeadTracking(this: v6, enable: enabled);
  return this;
}


// ========================================================================
// ?Action_ForceOpenCombatEnter@idAction_ForceOpenCombat@@QAA?AVeventVoid@@PAVidEntity@@W4aiPlayer_t@@@Z
// EA  : 0x82AA2560
// RVA : 0x00AA2560
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ForceOpenCombat *__fastcall idAction_ForceOpenCombat::Action_ForceOpenCombatEnter(
        idAction_ForceOpenCombat *this,
        eventVoid *result,
        idAI2 *entity,
        unsigned int player)
{
  idAI2 *v6; // r29
  idPlayer *PlayerTarget; // r3

  v6 = idAI2::CastTo(c: entity);
  PlayerTarget = idAI2::GetPlayerTarget(this: v6, player);
  idAI2::ForceOpenCombat(this: v6, enemy: PlayerTarget);
  return this;
}


// ========================================================================
// ?Action_ForceAwarenessByDistanceEnter@idAction_ForceAwarenessByDistance@@QAA?AVeventVoid@@PAVidEntity@@M_N1@Z
// EA  : 0x82AA25A0
// RVA : 0x00AA25A0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ForceAwarenessByDistance *__fastcall idAction_ForceAwarenessByDistance::Action_ForceAwarenessByDistanceEnter(
        idAction_ForceAwarenessByDistance *this,
        eventVoid *result,
        idAI2 *entity,
        double radius,
        const bool playerFlag,
        bool aiFlag)
{
  idAI2 *v9; // r3
  bool v10; // r5

  v9 = idAI2::CastTo(c: entity);
  idAIWorldState::ForceAwarenessByDistance(
    this: &v9->aiVolatile.world.worldState,
    owner: v9,
    forceRadius: radius,
    playerFlag: v10,
    aiFlag);
  return this;
}


// ========================================================================
// ?Action_ForcePlayerInteractionEnter@idAction_ForcePlayerInteraction@@QAA?AVeventVoid@@PAVidEntity@@W4aiPlayer_t@@@Z
// EA  : 0x82AA25F0
// RVA : 0x00AA25F0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ForcePlayerInteraction *__fastcall idAction_ForcePlayerInteraction::Action_ForcePlayerInteractionEnter(
        idAction_ForcePlayerInteraction *this,
        eventVoid *result,
        idAI2 *entity,
        unsigned int player)
{
  idAI2 *v6; // r29
  idPlayer *PlayerTarget; // r3

  v6 = idAI2::CastTo(c: entity);
  PlayerTarget = idAI2::GetPlayerTarget(this: v6, player);
  idAI2::ForcePlayerInteraction(this: v6, ent: PlayerTarget);
  return this;
}


// ========================================================================
// ?Action_SetAIVarEnter@idAction_SetAIVar@@QAA?AVeventVoid@@PAVidEntity@@PBDW4aiVarType_t@@1@Z
// EA  : 0x82AA2630
// RVA : 0x00AA2630
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetAIVar *__fastcall idAction_SetAIVar::Action_SetAIVarEnter(
        idAction_SetAIVar *this,
        eventVoid *result,
        idEntity *entity,
        const char *varName,
        unsigned int type,
        const char *varValue)
{
  idAIVar *v10; // r3
  idAIBlackboard *v12; // r31
  long double v13; // fp2
  idAIBlackboard *p_aiBlackboard; // r31
  int v15; // r3

  v10 = idAIBlackboard::Find(this: &gameLocal->aiBlackboard, name: varName);
  if ( v10 != nullptr )
  {
    v10->Set_3(this: v10, a2: varValue);
  }
  else
  {
    if ( type == 0 )
    {
      p_aiBlackboard = &gameLocal->aiBlackboard;
      v15 = atol(nptr: varValue);
      idAIBlackboard::AllocInt(this: p_aiBlackboard, name: varName, val: v15);
      return this;
    }
    if ( type == 1 )
    {
      v12 = &gameLocal->aiBlackboard;
      v13 = atof(nptr: varValue);
      idAIBlackboard::AllocFloat(this: v12, name: varName, val: (float)*(double *)&v13);
      return this;
    }
    if ( type < 3 )
    {
      idAIBlackboard::AllocString(this: &gameLocal->aiBlackboard, name: varName, val: varValue);
      return this;
    }
  }
  return this;
}


// ========================================================================
// ?Action_SetScriptFlagEnter@idAction_SetScriptFlag@@QAA?AVeventVoid@@PAVidEntity@@W4aiActionScriptFlags_t@@@Z
// EA  : 0x82AA2720
// RVA : 0x00AA2720
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetScriptFlag *__fastcall idAction_SetScriptFlag::Action_SetScriptFlagEnter(
        idAction_SetScriptFlag *this,
        eventVoid *result,
        idAI2 *entity,
        const aiActionScriptFlags_t flags)
{
  idAI2 *v6; // r3

  v6 = idAI2::CastTo(c: entity);
  v6->aiVolatile.script.flags |= flags;
  return this;
}


// ========================================================================
// ?Action_ClearScriptFlagEnter@idAction_ClearScriptFlag@@QAA?AVeventVoid@@PAVidEntity@@W4aiActionScriptFlags_t@@@Z
// EA  : 0x82AA2778
// RVA : 0x00AA2778
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ClearScriptFlag *__fastcall idAction_ClearScriptFlag::Action_ClearScriptFlagEnter(
        idAction_ClearScriptFlag *this,
        eventVoid *result,
        idAI2 *entity,
        const aiActionScriptFlags_t flags)
{
  idAI2 *v6; // r3

  v6 = idAI2::CastTo(c: entity);
  v6->aiVolatile.script.flags &= ~flags;
  return this;
}


// ========================================================================
// ?Action_SetPerceptionFlagEnter@idAction_SetPerceptionFlag@@QAA?AVeventVoid@@PAVidEntity@@W4aiPerceptionFlags_t@@@Z
// EA  : 0x82AA27D0
// RVA : 0x00AA27D0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetPerceptionFlag *__fastcall idAction_SetPerceptionFlag::Action_SetPerceptionFlagEnter(
        idAction_SetPerceptionFlag *this,
        eventVoid *result,
        idAI2 *entity,
        int flags)
{
  idAI2 *v6; // r3

  v6 = idAI2::CastTo(c: entity);
  idAI2::SetPerceptionFlags(this: v6, flags, setFlag: true);
  return this;
}


// ========================================================================
// ?Action_ClearPerceptionFlagEnter@idAction_ClearPerceptionFlag@@QAA?AVeventVoid@@PAVidEntity@@W4aiPerceptionFlags_t@@@Z
// EA  : 0x82AA2820
// RVA : 0x00AA2820
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ClearPerceptionFlag *__fastcall idAction_ClearPerceptionFlag::Action_ClearPerceptionFlagEnter(
        idAction_ClearPerceptionFlag *this,
        eventVoid *result,
        idAI2 *entity,
        const aiPerceptionFlags_t flags)
{
  idAI2 *v6; // r3

  v6 = idAI2::CastTo(c: entity);
  v6->aiVolatile.perception.flags &= ~flags;
  return this;
}


// ========================================================================
// ?Action_GiveItemEnter@idAction_GiveItem@@QAA?AVeventVoid@@PAVidEntity@@PBV3@PBVidDeclInventory@@@Z
// EA  : 0x82AA2870
// RVA : 0x00AA2870
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_GiveItem *__fastcall idAction_GiveItem::Action_GiveItemEnter(
        idAction_GiveItem *this,
        idState *result,
        idAI2 *entity,
        idEntity *giveTo,
        const idDeclJob *itemDecl)
{
  idAI2 *v9; // r3
  idEntity *v10; // r29
  idJobManager *v11; // r3
  idInventoryCollection *v12; // r27
  idInventoryItem *JobByDecl; // r3
  idPresentable *presentable; // r11
  idPresentable *v15; // r31
  idPresentable *v16; // r4
  idInventoryItem *v18; // [sp+50h] [-40h] BYREF

  v9 = idAI2::CastTo(c: entity);
  v10 = v9;
  if ( giveTo != nullptr
    && itemDecl != nullptr
    && (v11 = (idJobManager *)v9->GetInventory_2(this: v9), v12 = (idInventoryCollection *)v11, v11 != nullptr) )
  {
    JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(this: v11, jobDecl: itemDecl);
    presentable = giveTo->presentable;
    v18 = JobByDecl;
    if ( presentable != nullptr )
    {
      v15 = presentable;
    }
    else
    {
      idEntity::InitPresentableInternal(this: giveTo);
      v15 = giveTo->presentable;
    }
    v16 = v10->presentable;
    if ( v16 == nullptr )
    {
      idEntity::InitPresentableInternal(this: v10);
      v16 = v10->presentable;
    }
    idInventoryCollection::TransferItem(
      this: v12,
      owner: v16,
      to: v15,
      item: &v18,
      deleteOwnerItem: true,
      canIntro: false);
    return this;
  }
  else
  {
    idState::SetEnterFailed(this: result, failed: true);
    return this;
  }
}


// ========================================================================
// ?Action_TakeItemEnter@idAction_TakeItem@@QAA?AVeventVoid@@PAVidEntity@@0PBVidDeclInventory@@@Z
// EA  : 0x82AA2948
// RVA : 0x00AA2948
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_TakeItem *__fastcall idAction_TakeItem::Action_TakeItemEnter(
        idAction_TakeItem *this,
        idState *result,
        idAI2 *entity,
        idEntity *takeFrom,
        const idDeclJob *itemDecl)
{
  idAI2 *v9; // r28
  idJobManager *v10; // r3
  idInventoryCollection *v11; // r27
  idPresentable *presentable; // r30
  idPresentable *v13; // r4
  idJob *JobByDecl; // [sp+50h] [-40h] BYREF

  v9 = idAI2::CastTo(c: entity);
  if ( takeFrom == nullptr
    || itemDecl == nullptr
    || (v10 = (idJobManager *)takeFrom->GetInventory_2(this: takeFrom),
        v11 = (idInventoryCollection *)v10,
        v10 == nullptr) )
  {
    idState::SetEnterFailed(this: result, failed: true);
    return this;
  }
  JobByDecl = idJobManager::FindJobByDecl(this: v10, jobDecl: itemDecl);
  if ( JobByDecl == nullptr )
    return this;
  if ( v9->presentable == nullptr )
    idEntity::InitPresentableInternal(this: v9);
  presentable = v9->presentable;
  v13 = takeFrom->presentable;
  if ( v13 == nullptr )
  {
    idEntity::InitPresentableInternal(this: takeFrom);
    v13 = takeFrom->presentable;
  }
  idInventoryCollection::TransferItem(
    this: v11,
    owner: v13,
    to: presentable,
    item: (idInventoryItem **)&JobByDecl,
    deleteOwnerItem: true,
    canIntro: false);
  return this;
}


// ========================================================================
// ?Action_ClearWorldStateEnter@idAction_ClearWorldState@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82AA2A28
// RVA : 0x00AA2A28
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ClearWorldState *__fastcall idAction_ClearWorldState::Action_ClearWorldStateEnter(
        idAction_ClearWorldState *this,
        eventVoid *result,
        idAI2 *entity)
{
  idAI2 *v4; // r3

  v4 = idAI2::CastTo(c: entity);
  idAI2::ClearWorldState(this: v4);
  return this;
}


// ========================================================================
// ?Action_ShowAttachmentEnter@idAction_ShowAttachment@@QAA?AVeventVoid@@PAVidEntity@@PBD@Z
// EA  : 0x82AA2A60
// RVA : 0x00AA2A60
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ShowAttachment *__fastcall idAction_ShowAttachment::Action_ShowAttachmentEnter(
        idAction_ShowAttachment *this,
        idState *result,
        idAI2 *entity,
        const char *slotName)
{
  idAI2 *v7; // r31
  equipSlot_t v8; // r4
  int v10; // r4

  v7 = idAI2::CastTo(c: entity);
  v8 = idDeclInventory::EquipSlotForName(name: slotName);
  if ( (((v8 >= EQUIP_NONE) + ((unsigned int)v8 >= EQUIP_MAX)) & 1) == 0 )
  {
    idLib::Warning(fmt: "AnimEvent_ShowAttachment - Invalid slot name", v8);
LABEL_3:
    idState::SetEnterFailed(this: result, failed: true);
    return this;
  }
  v10 = (int)v7->GetEquipped(this: v7, a2: v8);
  if ( v10 == 0 )
    goto LABEL_3;
  v7->ShowAttachment(this: v7, a2: (idInventoryItem *)v10);
  return this;
}


// ========================================================================
// ?Action_HideAttachmentEnter@idAction_HideAttachment@@QAA?AVeventVoid@@PAVidEntity@@PBD@Z
// EA  : 0x82AA2B18
// RVA : 0x00AA2B18
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_HideAttachment *__fastcall idAction_HideAttachment::Action_HideAttachmentEnter(
        idAction_HideAttachment *this,
        idState *result,
        idAI2 *entity,
        const char *slotName)
{
  idAI2 *v7; // r31
  equipSlot_t v8; // r4
  int v10; // r4

  v7 = idAI2::CastTo(c: entity);
  v8 = idDeclInventory::EquipSlotForName(name: slotName);
  if ( (((v8 >= EQUIP_NONE) + ((unsigned int)v8 >= EQUIP_MAX)) & 1) == 0 )
  {
    idLib::Warning(fmt: "AnimEvent_HideAttachment - Invalid slot name", v8);
LABEL_3:
    idState::SetEnterFailed(this: result, failed: true);
    return this;
  }
  v10 = (int)v7->GetEquipped(this: v7, a2: v8);
  if ( v10 == 0 )
    goto LABEL_3;
  v7->HideAttachment(this: v7, a2: (idInventoryItem *)v10);
  return this;
}


// ========================================================================
// ?Action_DropAttachmentEnter@idAction_DropAttachment@@QAA?AVeventVoid@@PAVidEntity@@PBD@Z
// EA  : 0x82AA2BD0
// RVA : 0x00AA2BD0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_DropAttachment *__fastcall idAction_DropAttachment::Action_DropAttachmentEnter(
        idAction_DropAttachment *this,
        idState *result,
        idAI2 *entity,
        const char *slotName)
{
  idAI2 *v7; // r31
  equipSlot_t v8; // r4
  int v10; // r4

  v7 = idAI2::CastTo(c: entity);
  v8 = idDeclInventory::EquipSlotForName(name: slotName);
  if ( (((v8 >= EQUIP_NONE) + ((unsigned int)v8 >= EQUIP_MAX)) & 1) == 0 )
  {
    idLib::Warning(fmt: "AnimEvent_DropAttachment - Invalid slot name", v8);
LABEL_3:
    idState::SetEnterFailed(this: result, failed: true);
    return this;
  }
  v10 = (int)v7->GetEquipped(this: v7, a2: v8);
  if ( v10 == 0 )
    goto LABEL_3;
  v7->DropAttachment_2(this: v7, a2: (idInventoryItem *)v10);
  return this;
}


// ========================================================================
// ?Action_SetMoveModeEnter@idAction_SetMoveMode@@QAA?AVeventVoid@@PAVidEntity@@W4aiMovementMode_t@@@Z
// EA  : 0x82AA2C88
// RVA : 0x00AA2C88
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetMoveMode *__fastcall idAction_SetMoveMode::Action_SetMoveModeEnter(
        idAction_SetMoveMode *this,
        eventVoid *result,
        idAI2 *entity,
        aiMovementMode_t moveMode)
{
  idAI2 *v6; // r3

  v6 = idAI2::CastTo(c: entity);
  idAIMoveState::SetMovementModeForReal(this: &v6->aiVolatile.physics.moveState, mode: moveMode);
  return this;
}


// ========================================================================
// ?Action_SetAccuracyEnter@idAction_SetAccuracy@@QAA?AVeventVoid@@PAVidEntity@@W4aiAccuracy_t@@@Z
// EA  : 0x82AA2CD8
// RVA : 0x00AA2CD8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetAccuracy *__fastcall idAction_SetAccuracy::Action_SetAccuracyEnter(
        idAction_SetAccuracy *this,
        eventVoid *result,
        idAI2 *entity,
        aiAccuracy_t accuracy)
{
  idAI2 *v6; // r3

  v6 = idAI2::CastTo(c: entity);
  idAI2::SetAccuracy(this: v6, a: accuracy);
  return this;
}


// ========================================================================
// ?Evaluate@ScriptedAnimWebDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AA2D20
// RVA : 0x00AA2D20
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall ScriptedAnimWebDone::Evaluate(
        ScriptedAnimWebDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAction_ScriptedAnimWeb *state,
        const int curTime)
{
  return (*((_BYTE *)idAction_ScriptedAnimWeb::CastTo(c: state) + 84) & 0x80) == 0 ? 0 : 8;
}


// ========================================================================
// ?Evaluate@MoveToScenePointDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AA2D60
// RVA : 0x00AA2D60
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall MoveToScenePointDone::Evaluate(
        MoveToScenePointDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAction_MoveToScenePoint *state,
        const int curTime)
{
  return !idAction_MoveToScenePoint::CastTo(c: state)->isDone ? 0 : 8;
}


// ========================================================================
// ??0idAIAction@@QAA@ABVidTypeInfo@@F@Z
// EA  : 0x82AA2D98
// RVA : 0x00AA2D98
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAIAction *__fastcall idAIAction::idAIAction(idAIAction *this, const idTypeInfo *stateType, __int16 flags)
{
  idState::idState(this, stateType, childFSMType: nullptr, flags);
  this->__vftable = (idAIAction_vtbl *)&idAIAction::`vftable';
  return this;
}


// ========================================================================
// ?AIAction_EnterState@idAIStateError@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AA2DE0
// RVA : 0x00AA2DE0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAIStateError::AIAction_EnterState(
        idAIStateDone *this,
        bfx::BinaryReplayLogOut *ai,
        idAIActionFSM *fsm,
        const int curTime)
{
  idAIActionFSM *v5; // r3
  idAIActionFSM *v6; // r28
  idHealthT<enum simpleHealthComponent_t,1,0> *Thread; // r3
  idThread *v8; // r31
  idHandle<int,enum invalidFiberId_t,0> *value; // r30

  v5 = idAIActionFSM::CastTo(c: fsm);
  v6 = v5;
  if ( v5 != nullptr )
  {
    Thread = (idHealthT<enum simpleHealthComponent_t,1,0> *)idThreadManager::GetThread(
                                                              this: &gameLocal->program.threadManager,
                                                              threadHandle: (const idHandle<int,enum invalidThreadHandle_t,0> *)v5->waitThreadHandle.value);
    v8 = (idThread *)Thread;
    if ( Thread != nullptr && idHealthT<enum simpleHealthComponent_t,1,0>::IsDead_Impl(this: Thread) )
      idThread::DelayedStart(this: v8, delay: 0);
    value = (idHandle<int,enum invalidFiberId_t,0> *)v6->waitFiberHandle.value;
    v6->waitThreadHandle.value = 0;
    if ( idSuperScriptSystem::IsThreadHandleValid(this: &gameLocal->superScript, threadHandle: value)
      && idSuperScriptSystem::IsWaitingForFSM(this: &gameLocal->superScript, fiberHandle: value) )
    {
      idSuperScriptSystem::ClearWaitForFSM(this: &gameLocal->superScript, fiberHandle: value);
    }
    v6->waitFiberHandle.value = 0;
  }
  idPhysics_StaticMulti::UpdateTime(this: ai);
}


// ========================================================================
// ?InternalRespondsTo@idAIActionsQueue@@MBA_NABVidEventDef@@@Z
// EA  : 0x82AA2EC8
// RVA : 0x00AA2EC8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

BOOL __fastcall idAIActionsQueue::InternalRespondsTo(idAIScriptProxy *this, const idEventDef *event)
{
  return (_cntlzw(event->type - 1) & 0x20) != 0;
}


// ========================================================================
// ?GetCurrentAction@idAIActionFSM@@QBAPAVidAIAction@@XZ
// EA  : 0x82AA2EE0
// RVA : 0x00AA2EE0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAIAction *__fastcall idAIActionFSM::GetCurrentAction(idAIActionFSM *this)
{
  return idAIAction::CastTo(c: (idAIAction *)this->curState);
}


// ========================================================================
// ?InitStates@idLegsFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82AA2EE8
// RVA : 0x00AA2EE8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idLegsFSM::InitStates(idLegsFSM *this, const idFiniteStateMachineParams *params)
{
  int v4; // r31
  idList<idEventReceiver *,5> **p_listenerList; // r28
  idList<idEventReceiver *,5> *listeningToList; // r11
  int v7; // r30

  idAIFSM::InitStates(this, params);
  p_listenerList = &params->manager[235].listenerList;
  listeningToList = params->manager[235].listeningToList;
  v4 = 0;
  if ( (int)listeningToList > 0 )
  {
    v7 = 0;
    do
    {
      this->AddState(this, a2: *(idState **)((char *)&(*p_listenerList)->list + v7));
      ++v4;
      v7 += 4;
    }
    while ( v4 < (int)p_listenerList[1] );
  }
}


// ========================================================================
// ?FindFSM@idAIActionManager@@UBAPBVidFiniteStateMachine@@PBD@Z
// EA  : 0x82AA2F58
// RVA : 0x00AA2F58
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idLegsFSM *__fastcall idAIActionManager::FindFSM(idAIActionManager *this, const char *name)
{
  idLegsFSM *result; // r3
  bool v4; // zf

  v4 = idStr::Icmp(s1: this->legsFSM.name.str, s2: name) == 0;
  result = &this->legsFSM;
  if ( !v4 )
    return nullptr;
  return result;
}


// ========================================================================
// ?FindFSM@idAIActionManager@@UAAPAVidFiniteStateMachine@@ABVidTypeInfo@@@Z
// EA  : 0x82AA2F98
// RVA : 0x00AA2F98
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idLegsFSM *__fastcall idAIActionManager::FindFSM(idAIActionManager *this, const idTypeInfo *type)
{
  idLegsFSM *p_legsFSM; // r30
  int v4; // r11
  char v5; // r11
  bool v6; // zf

  p_legsFSM = &this->legsFSM;
  v4 = *(_DWORD *)(this->legsFSM.GetType(this: &this->legsFSM) + 36);
  if ( v4 < type->typeNum || (v6 = v4 <= type->lastChild, v5 = 1, !v6) )
    v5 = 0;
  return v5 == 0 ? nullptr : p_legsFSM;
}


// ========================================================================
// ?GetSubWebAndStateIndices@@YAXPBVidAI2@@W4aiSubWeb_t@@PBDAAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@AAV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82AA3090
// RVA : 0x00AA3090
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall GetSubWebAndStateIndices(
        idAI2 *ai,
        const aiSubWeb_t subweb,
        const char *stateName,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *swi,
        idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *si)
{
  idAI2::idAIVolatile::idAIAnimationInfo *p_animation; // r27
  int v9; // [sp+50h] [-60h] BYREF
  idStr v10[2]; // [sp+60h] [-50h] BYREF

  v10[0].len = 0;
  v10[0].allocedAndFlag = 20;
  v10[0].data = v10[0].baseBuffer;
  v10[0].baseBuffer[0] = 0;
  p_animation = &ai->aiVolatile.animation;
  idAI2::GetSubWebPrefix(this: ai, subWebPrefix: v10);
  swi->value = (__int16)HIWORD(idDeclAnimWeb::GetSubWebIndexForName(
                                 this: (idDeclAnimWeb *)&v9,
                                 result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)p_animation->animWebAnimator.ptr[0].decl,
                                 subWebName: v10[0].data)->__vftable);
  si->value = (__int16)HIWORD(idDeclAnimWeb::GetStateIndexForName(
                                this: (idDeclAnimWeb *)((char *)&v9 + 2),
                                result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)p_animation->animWebAnimator.ptr[0].decl,
                                name: stateName)->__vftable);
  idStr::FreeData(this: v10);
}


// ========================================================================
// __unwind$504918
// EA  : 0x82AA311C
// RVA : 0x00AA311C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_504918()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ??0idAction_MoveToPoint@@QAA@XZ
// EA  : 0x82AA3148
// RVA : 0x00AA3148
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_MoveToPoint *__fastcall idAction_MoveToPoint::idAction_MoveToPoint(idAction_MoveToPoint *this)
{
  idState::idState(this, stateType: &idAction_MoveToPoint::Type, childFSMType: nullptr, flags: 0);
  this->lastWalkState = WALKSTATE_RUNNING;
  this->__vftable = (idAction_MoveToPoint_vtbl *)&idAction_MoveToPoint::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_MoveToPointNoFail@@QAA@XZ
// EA  : 0x82AA31B8
// RVA : 0x00AA31B8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_MoveToPointNoFail *__fastcall idAction_MoveToPointNoFail::idAction_MoveToPointNoFail(
        idAction_MoveToPointNoFail *this)
{
  idState::idState(this, stateType: &idAction_MoveToPointNoFail::Type, childFSMType: nullptr, flags: 0);
  this->lastWalkState = WALKSTATE_RUNNING;
  this->__vftable = (idAction_MoveToPointNoFail_vtbl *)&idAction_MoveToPointNoFail::`vftable';
  idAIMoveParms::idAIMoveParms(this: &this->moveNoFailStatus.moveParms);
  idAIMoveCmd::idAIMoveCmd(this: &this->moveNoFailStatus.moveCmd, user: "MoveNoFail");
  this->moveNoFailStatus.movePhase = PHASE_STARTING;
  this->moveNoFailStatus.phaseTime = 0;
  this->moveNoFailStatus.idleVo = nullptr;
  this->moveNoFailStatus.successCount = 10;
  return this;
}


// ========================================================================
// __unwind$505037
// EA  : 0x82AA3238
// RVA : 0x00AA3238
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_505037()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: *(idCombat_MoveToPlugAnim **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idAction_MoveToEntity@@QAA@XZ
// EA  : 0x82AA32D0
// RVA : 0x00AA32D0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_MoveToEntity *__fastcall idAction_MoveToEntity::idAction_MoveToEntity(idAction_MoveToEntity *this)
{
  idState::idState(this, stateType: &idAction_MoveToEntity::Type, childFSMType: nullptr, flags: 0);
  this->lastWalkState = WALKSTATE_RUNNING;
  this->__vftable = (idAction_MoveToEntity_vtbl *)&idAction_MoveToEntity::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_MoveToEntityNoFail@@QAA@XZ
// EA  : 0x82AA3340
// RVA : 0x00AA3340
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_MoveToEntityNoFail *__fastcall idAction_MoveToEntityNoFail::idAction_MoveToEntityNoFail(
        idAction_MoveToEntityNoFail *this)
{
  idState::idState(this, stateType: &idAction_MoveToEntityNoFail::Type, childFSMType: nullptr, flags: 0);
  this->lastWalkState = WALKSTATE_RUNNING;
  this->__vftable = (idAction_MoveToEntityNoFail_vtbl *)&idAction_MoveToEntityNoFail::`vftable';
  idAIMoveParms::idAIMoveParms(this: &this->moveNoFailStatus.moveParms);
  idAIMoveCmd::idAIMoveCmd(this: &this->moveNoFailStatus.moveCmd, user: "MoveNoFail");
  this->moveNoFailStatus.movePhase = PHASE_STARTING;
  this->moveNoFailStatus.phaseTime = 0;
  this->moveNoFailStatus.idleVo = nullptr;
  this->moveNoFailStatus.successCount = 10;
  return this;
}


// ========================================================================
// __unwind$505132
// EA  : 0x82AA33C0
// RVA : 0x00AA33C0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_505132()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: *(idCombat_MoveToPlugAnim **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idAction_MoveToPathPoint@@QAA@XZ
// EA  : 0x82AA33F8
// RVA : 0x00AA33F8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_MoveToPathPoint *__fastcall idAction_MoveToPathPoint::idAction_MoveToPathPoint(idAction_MoveToPathPoint *this)
{
  idState::idState(this, stateType: &idAction_MoveToPathPoint::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_MoveToPathPoint_vtbl *)&idAction_MoveToPathPoint::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_MoveToPathPointNoFail@@QAA@XZ
// EA  : 0x82AA3460
// RVA : 0x00AA3460
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_MoveToPathPointNoFail *__fastcall idAction_MoveToPathPointNoFail::idAction_MoveToPathPointNoFail(
        idAction_MoveToPathPointNoFail *this)
{
  idState::idState(this, stateType: &idAction_MoveToPathPointNoFail::Type, childFSMType: nullptr, flags: 0);
  this->lastWalkState = WALKSTATE_RUNNING;
  this->__vftable = (idAction_MoveToPathPointNoFail_vtbl *)&idAction_MoveToPathPointNoFail::`vftable';
  idAIMoveParms::idAIMoveParms(this: &this->moveNoFailStatus.moveParms);
  idAIMoveCmd::idAIMoveCmd(this: &this->moveNoFailStatus.moveCmd, user: "MoveNoFail");
  this->moveNoFailStatus.movePhase = PHASE_STARTING;
  this->moveNoFailStatus.phaseTime = 0;
  this->moveNoFailStatus.idleVo = nullptr;
  this->moveNoFailStatus.successCount = 10;
  return this;
}


// ========================================================================
// __unwind$505227
// EA  : 0x82AA34E0
// RVA : 0x00AA34E0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_505227()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: *(idCombat_MoveToPlugAnim **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idAction_MoveToCover@@QAA@XZ
// EA  : 0x82AA3518
// RVA : 0x00AA3518
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_MoveToCover *__fastcall idAction_MoveToCover::idAction_MoveToCover(idAction_MoveToCover *this)
{
  idState::idState(this, stateType: &idAction_MoveToCover::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_MoveToCover_vtbl *)&idAction_MoveToCover::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_UseZipline@@QAA@XZ
// EA  : 0x82AA3578
// RVA : 0x00AA3578
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_UseZipline *__fastcall idAction_UseZipline::idAction_UseZipline(idAction_UseZipline *this)
{
  idState::idState(this, stateType: &idAction_UseZipline::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_UseZipline_vtbl *)&idAction_UseZipline::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetMovePushStatus@@QAA@XZ
// EA  : 0x82AA35D8
// RVA : 0x00AA35D8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetMovePushStatus *__fastcall idAction_SetMovePushStatus::idAction_SetMovePushStatus(
        idAction_SetMovePushStatus *this)
{
  idState::idState(this, stateType: &idAction_SetMovePushStatus::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SetMovePushStatus_vtbl *)&idAction_SetMovePushStatus::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_Idle@@QAA@XZ
// EA  : 0x82AA3638
// RVA : 0x00AA3638
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_Idle *__fastcall idAction_Idle::idAction_Idle(idAction_Idle *this)
{
  idState::idState(this, stateType: &idAction_Idle::Type, childFSMType: nullptr, flags: 0);
  this->idleTurnType = AIIDLETURN_COMBAT;
  this->__vftable = (idAction_Idle_vtbl *)&idAction_Idle::`vftable';
  this->turnTime = -1;
  this->isTurning = false;
  return this;
}


// ========================================================================
// ??0idAction_Pain@@QAA@XZ
// EA  : 0x82AA36B0
// RVA : 0x00AA36B0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_Pain *__fastcall idAction_Pain::idAction_Pain(idAction_Pain *this)
{
  idState::idState(this, stateType: &idAction_Pain::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_Pain_vtbl *)&idAction_Pain::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_StandToCrouch@@QAA@XZ
// EA  : 0x82AA3710
// RVA : 0x00AA3710
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_StandToCrouch *__fastcall idAction_StandToCrouch::idAction_StandToCrouch(idAction_StandToCrouch *this)
{
  idState::idState(this, stateType: &idAction_StandToCrouch::Type, childFSMType: nullptr, flags: 1);
  this->alreadyCrouched = false;
  this->__vftable = (idAction_StandToCrouch_vtbl *)&idAction_StandToCrouch::`vftable';
  return this;
}


// ========================================================================
// ?Action_StandToCrouchEnter@idAction_StandToCrouch@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82AA3780
// RVA : 0x00AA3780
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_StandToCrouch *__fastcall idAction_StandToCrouch::Action_StandToCrouchEnter(
        idAction_StandToCrouch *this,
        idState *result,
        idAI2 *entity)
{
  _exception *v5; // r30
  idAIAnimWebState *v6; // r3
  const idAnimWebState *v7; // r4
  char v8; // r3
  unsigned __int8 v9; // r3
  idAIAnimWebState_Current v11; // [sp+50h] [-C0h] BYREF
  idAIAnimWebState v12; // [sp+70h] [-A0h] BYREF
  idStr v13; // [sp+90h] [-80h] BYREF
  idStr v14[3]; // [sp+B0h] [-60h] BYREF

  v5 = (_exception *)idAI2::CastTo(c: entity);
  if ( (*(int (__fastcall **)(_exception *))(v5->type + 784))(a1: v5) == 2 )
  {
    HIBYTE(result[1].__vftable) = 1;
  }
  else
  {
    (*(void (__fastcall **)(_exception *, int))(v5->type + 788))(a1: v5, a2: 2);
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: v5) != 0 )
      idAnimBaseFSM::ClearDestination(this: (idAnimBaseFSM *)&v5[545]);
    else
      idAIMoveState::Stop(this: (idAIMoveState *)((char *)&v5[190].arg2 + 4), newStatus: 0);
    v14[0].len = 0;
    v14[0].allocedAndFlag = 20;
    v14[0].data = v14[0].baseBuffer;
    v14[0].baseBuffer[0] = 0;
    idAI2::GetIdleStateName(this: (idAI2 *)v5, name: v14);
    v13.allocedAndFlag = 20;
    v13.data = v13.baseBuffer;
    v13.len = 0;
    v13.baseBuffer[0] = 0;
    idAI2::GetSubWebPrefix(this: (idAI2 *)v5, swt: SDWORD1(v5[527].retval), subWebPrefix: &v13);
    idAIAnimWebState_Current::idAIAnimWebState_Current(this: &v11, ai: (const idAI2 *)v5);
    v6 = idAIAnimWebState::idAIAnimWebState(this: &v12, ai: (idAI2 *)v5, subwebName: v13.data, stateName: v14[0].data);
    v7 = &v6->idAnimWebState;
    if ( v6 == nullptr )
      v7 = nullptr;
    v8 = idAnimWebState::operator==(this: &v11.idAnimWebState, other: v7);
    v12.__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
    if ( v8 != 0 )
    {
      HIBYTE(result[1].__vftable) = 1;
    }
    else
    {
      v9 = idAI2::WaitForAnimToStart(
             this: (idAI2 *)v5,
             awt: AIANIMWEB_BODY,
             priority: PRIORITY_LOW,
             subWebName: v13.data,
             stateName: v14[0].data,
             ev: ANIMWEB_EVENT_START_BLEND_IN);
      idState::SetEnterFailed(this: result, failed: (_cntlzw(v9) & 0x20) != 0);
    }
    v11.__vftable = (idAIAnimWebState_Current_vtbl *)&idAIAnimWebState::`vftable';
    idStr::FreeData(this: &v13);
    idStr::FreeData(this: v14);
  }
  return this;
}


// ========================================================================
// __unwind$505570
// EA  : 0x82AA3920
// RVA : 0x00AA3920
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_505570()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 176));
}


// ========================================================================
// __unwind$505571
// EA  : 0x82AA3948
// RVA : 0x00AA3948
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_505571()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 144));
}


// ========================================================================
// __unwind$505572
// EA  : 0x82AA3970
// RVA : 0x00AA3970
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_505572()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$505573
// EA  : 0x82AA3998
// RVA : 0x00AA3998
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_505573()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 272 + 112));
}


// ========================================================================
// ??0idAction_CrouchToStand@@QAA@XZ
// EA  : 0x82AA39C0
// RVA : 0x00AA39C0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_CrouchToStand *__fastcall idAction_CrouchToStand::idAction_CrouchToStand(idAction_CrouchToStand *this)
{
  idState::idState(this, stateType: &idAction_CrouchToStand::Type, childFSMType: nullptr, flags: 1);
  this->alreadyCrouched = false;
  this->__vftable = (idAction_CrouchToStand_vtbl *)&idAction_CrouchToStand::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_PullTriggerRight@@QAA@XZ
// EA  : 0x82AA3A28
// RVA : 0x00AA3A28
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_PullTriggerRight *__fastcall idAction_PullTriggerRight::idAction_PullTriggerRight(
        idAction_PullTriggerRight *this)
{
  idState::idState(this, stateType: &idAction_PullTriggerRight::Type, childFSMType: nullptr, flags: 1);
  this->__vftable = (idAction_PullTriggerRight_vtbl *)&idAction_PullTriggerRight::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_ReleaseTriggerRight@@QAA@XZ
// EA  : 0x82AA3A88
// RVA : 0x00AA3A88
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ReleaseTriggerRight *__fastcall idAction_ReleaseTriggerRight::idAction_ReleaseTriggerRight(
        idAction_ReleaseTriggerRight *this)
{
  idState::idState(this, stateType: &idAction_ReleaseTriggerRight::Type, childFSMType: nullptr, flags: 1);
  this->__vftable = (idAction_ReleaseTriggerRight_vtbl *)&idAction_ReleaseTriggerRight::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_PullTriggerLeft@@QAA@XZ
// EA  : 0x82AA3AE8
// RVA : 0x00AA3AE8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_PullTriggerLeft *__fastcall idAction_PullTriggerLeft::idAction_PullTriggerLeft(idAction_PullTriggerLeft *this)
{
  idState::idState(this, stateType: &idAction_PullTriggerLeft::Type, childFSMType: nullptr, flags: 1);
  this->__vftable = (idAction_PullTriggerLeft_vtbl *)&idAction_PullTriggerLeft::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_ReleaseTriggerLeft@@QAA@XZ
// EA  : 0x82AA3B48
// RVA : 0x00AA3B48
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ReleaseTriggerLeft *__fastcall idAction_ReleaseTriggerLeft::idAction_ReleaseTriggerLeft(
        idAction_ReleaseTriggerLeft *this)
{
  idState::idState(this, stateType: &idAction_ReleaseTriggerLeft::Type, childFSMType: nullptr, flags: 1);
  this->__vftable = (idAction_ReleaseTriggerLeft_vtbl *)&idAction_ReleaseTriggerLeft::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_ReloadWeapon@@QAA@XZ
// EA  : 0x82AA3BA8
// RVA : 0x00AA3BA8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ReloadWeapon *__fastcall idAction_ReloadWeapon::idAction_ReloadWeapon(idAction_ReloadWeapon *this)
{
  idState::idState(this, stateType: &idAction_ReloadWeapon::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_ReloadWeapon_vtbl *)&idAction_ReloadWeapon::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_ReloadWeaponTorso@@QAA@XZ
// EA  : 0x82AA3C08
// RVA : 0x00AA3C08
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ReloadWeaponTorso *__fastcall idAction_ReloadWeaponTorso::idAction_ReloadWeaponTorso(
        idAction_ReloadWeaponTorso *this)
{
  idState::idState(this, stateType: &idAction_ReloadWeaponTorso::Type, childFSMType: nullptr, flags: 1);
  this->__vftable = (idAction_ReloadWeaponTorso_vtbl *)&idAction_ReloadWeaponTorso::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_WaitForAnim@@QAA@XZ
// EA  : 0x82AA3C68
// RVA : 0x00AA3C68
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_WaitForAnim *__fastcall idAction_WaitForAnim::idAction_WaitForAnim(idAction_WaitForAnim *this)
{
  idState::idState(this, stateType: &idAction_WaitForAnim::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_WaitForAnim_vtbl *)&idAction_WaitForAnim::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_WaitForAnimVia@@QAA@XZ
// EA  : 0x82AA3CC8
// RVA : 0x00AA3CC8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_WaitForAnimVia *__fastcall idAction_WaitForAnimVia::idAction_WaitForAnimVia(idAction_WaitForAnimVia *this)
{
  idState::idState(this, stateType: &idAction_WaitForAnimVia::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_WaitForAnimVia_vtbl *)&idAction_WaitForAnimVia::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_LoopAnim@@QAA@XZ
// EA  : 0x82AA3D28
// RVA : 0x00AA3D28
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_LoopAnim *__fastcall idAction_LoopAnim::idAction_LoopAnim(idAction_LoopAnim *this)
{
  idState::idState(this, stateType: &idAction_LoopAnim::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_LoopAnim_vtbl *)&idAction_LoopAnim::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_LoopAnimExitAtEnd@@QAA@XZ
// EA  : 0x82AA3D88
// RVA : 0x00AA3D88
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_LoopAnimExitAtEnd *__fastcall idAction_LoopAnimExitAtEnd::idAction_LoopAnimExitAtEnd(
        idAction_LoopAnimExitAtEnd *this)
{
  idState::idState(this, stateType: &idAction_LoopAnimExitAtEnd::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_LoopAnimExitAtEnd_vtbl *)&idAction_LoopAnimExitAtEnd::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_StartAnim@@QAA@XZ
// EA  : 0x82AA3DE8
// RVA : 0x00AA3DE8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_StartAnim *__fastcall idAction_StartAnim::idAction_StartAnim(idAction_StartAnim *this)
{
  idState::idState(this, stateType: &idAction_StartAnim::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_StartAnim_vtbl *)&idAction_StartAnim::`vftable';
  return this;
}


// ========================================================================
// ?Action_StartAnimEnter@idAction_StartAnim@@QAA?AVeventVoid@@PAVidEntity@@ABVidAnimWebPath@@_N2@Z
// EA  : 0x82AA3E50
// RVA : 0x00AA3E50
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_StartAnim *__fastcall idAction_StartAnim::Action_StartAnimEnter(
        idAction_StartAnim *this,
        idState *result,
        idAI2 *entity,
        const idAnimWebPath *animRef,
        const bool finishBlend,
        const bool wait)
{
  idAI2 *v11; // r3
  char v12; // r6
  idAI2 *v13; // r30
  animWebEvent_t v14; // r28
  bool v15; // r4
  unsigned __int16 v17; // [sp+50h] [-90h] BYREF
  unsigned __int16 v18; // [sp+52h] [-8Eh] BYREF
  idStr v19; // [sp+60h] [-80h] BYREF
  idStr v20[3]; // [sp+80h] [-60h] BYREF

  v11 = idAI2::CastTo(c: entity);
  v20[0].len = 0;
  v20[0].baseBuffer[0] = 0;
  v12 = !finishBlend - 1;
  v20[0].allocedAndFlag = 20;
  v13 = v11;
  v20[0].data = v20[0].baseBuffer;
  v14 = v12 & 2;
  v19.allocedAndFlag = 20;
  v19.len = 0;
  v19.data = v19.baseBuffer;
  v19.baseBuffer[0] = 0;
  idAI2::GetSubWebAndStateFromAnimWebPath(this: v11, animWebPath: animRef->data, subWebName: v20, stateName: &v19);
  if ( wait )
  {
    v15 = (_cntlzw((unsigned __int8)idAI2::WaitForAnimToStart(
                                      this: v13,
                                      awt: AIANIMWEB_BODY,
                                      priority: PRIORITY_LOW,
                                      subWebName: v20[0].data,
                                      stateName: v19.data,
                                      ev: v14))
         & 0x20) != 0;
  }
  else
  {
    idDeclAnimWeb::GetSubWebIndexForName(
      this: (idDeclAnimWeb *)&v18,
      result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v13->aiVolatile.animation.animWebAnimator.ptr[0].decl,
      subWebName: v20[0].data);
    idDeclAnimWeb::GetStateIndexForName(
      this: (idDeclAnimWeb *)&v17,
      result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v13->aiVolatile.animation.animWebAnimator.ptr[0].decl,
      name: v19.data);
    v15 = (_cntlzw(
             idAI2::ChangeAnimState(
               this: v13,
               web: AIANIMWEB_BODY,
               subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v18,
               stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v17,
               interruptPath: INTR_PATH_YES,
               interruptBlend: INTR_BLEND_NO))
         & 0x20) != 0;
  }
  idState::SetEnterFailed(this: result, failed: v15);
  idStr::FreeData(this: &v19);
  idStr::FreeData(this: v20);
  return this;
}


// ========================================================================
// __unwind$506332
// EA  : 0x82AA3F84
// RVA : 0x00AA3F84
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_506332()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// __unwind$506333
// EA  : 0x82AA3FAC
// RVA : 0x00AA3FAC
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_506333()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// ??0idAction_WaitForTraversalAnim@@QAA@XZ
// EA  : 0x82AA3FD8
// RVA : 0x00AA3FD8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_WaitForTraversalAnim *__fastcall idAction_WaitForTraversalAnim::idAction_WaitForTraversalAnim(
        idAction_WaitForTraversalAnim *this)
{
  idState::idState(this, stateType: &idAction_WaitForTraversalAnim::Type, childFSMType: nullptr, flags: 1);
  this->__vftable = (idAction_WaitForTraversalAnim_vtbl *)&idAction_WaitForTraversalAnim::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_ChangeAnimState@@QAA@XZ
// EA  : 0x82AA4038
// RVA : 0x00AA4038
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ChangeAnimState *__fastcall idAction_ChangeAnimState::idAction_ChangeAnimState(idAction_ChangeAnimState *this)
{
  idState::idState(this, stateType: &idAction_ChangeAnimState::Type, childFSMType: nullptr, flags: 1);
  this->__vftable = (idAction_ChangeAnimState_vtbl *)&idAction_ChangeAnimState::`vftable';
  return this;
}


// ========================================================================
// ?Action_ChangeAnimStateEnter@idAction_ChangeAnimState@@QAA?AVeventVoid@@PAVidEntity@@W4aiAnimWeb_t@@ABVidAnimWebPath@@W4aiAnimWait_t@@@Z
// EA  : 0x82AA40A0
// RVA : 0x00AA40A0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ChangeAnimState *__fastcall idAction_ChangeAnimState::Action_ChangeAnimStateEnter(
        idAction_ChangeAnimState *this,
        idState *result,
        idAI2 *entity,
        aiAnimWeb_t aw,
        const idAnimWebPath *destNode,
        const aiAnimWait_t wait)
{
  idAI2 *v11; // r3
  idAI2 *v12; // r29
  unsigned int v13; // r30
  bool v14; // r4
  animWebEvent_t v15; // r8
  idStr v17; // [sp+50h] [-90h] BYREF
  idStr v18[3]; // [sp+70h] [-70h] BYREF

  v11 = idAI2::CastTo(c: entity);
  v18[0].len = 0;
  v18[0].allocedAndFlag = 20;
  v12 = v11;
  v18[0].data = v18[0].baseBuffer;
  v18[0].baseBuffer[0] = 0;
  v17.allocedAndFlag = 20;
  v17.data = v17.baseBuffer;
  v17.len = 0;
  v17.baseBuffer[0] = 0;
  idAI2::GetSubWebAndStateFromAnimWebPath(this: v11, animWebPath: destNode->data, subWebName: v18, stateName: &v17);
  if ( wait != AIANIMWAIT_DONT_WAIT )
  {
    v15 = ANIMWEB_EVENT_START_BLEND_IN;
    if ( wait == AIANIMWAIT_WAIT_FOR_DEST_TO_FINISH_BLEND )
      v15 = ANIMWEB_EVENT_END_BLEND_IN;
    v14 = (_cntlzw((unsigned __int8)idAI2::WaitForAnimToStart(
                                      this: v12,
                                      awt: aw,
                                      priority: PRIORITY_LOW,
                                      subWebName: v18[0].data,
                                      stateName: v17.data,
                                      ev: v15))
         & 0x20) != 0;
  }
  else
  {
    v13 = idAnimator_AnimWeb::ChangeState(
            this: &v12->aiVolatile.animation.animWebAnimator.ptr[aw],
            subWebName: v18[0].data,
            stateName: v17.data,
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_NO,
            blendEventMask_: 0);
    if ( !idAI2::AnimEventReceived(this: v12, priority: PRIORITY_LOW) && ai_debugLevel.valueInteger > 0 )
      idLib::Warning(fmt: "ACTION_CHANGE_ANIM_STATE: event already pending!");
    if ( ai_clearEvents.valueInteger != 0 )
      idAI2::ClearAllAnimWebEvents(this: v12, web: AIANIMWEB_BODY, priority: PRIORITY_LOW);
    v14 = (_cntlzw(v13) & 0x20) != 0;
  }
  idState::SetEnterFailed(this: result, failed: v14);
  idStr::FreeData(this: &v17);
  idStr::FreeData(this: v18);
  return this;
}


// ========================================================================
// __unwind$506571
// EA  : 0x82AA4208
// RVA : 0x00AA4208
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_506571()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// __unwind$506572
// EA  : 0x82AA4230
// RVA : 0x00AA4230
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_506572()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// ??0idAction_ChangeAnimStateVia@@QAA@XZ
// EA  : 0x82AA4258
// RVA : 0x00AA4258
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ChangeAnimStateVia *__fastcall idAction_ChangeAnimStateVia::idAction_ChangeAnimStateVia(
        idAction_ChangeAnimStateVia *this)
{
  idState::idState(this, stateType: &idAction_ChangeAnimStateVia::Type, childFSMType: nullptr, flags: 1);
  this->__vftable = (idAction_ChangeAnimStateVia_vtbl *)&idAction_ChangeAnimStateVia::`vftable';
  return this;
}


// ========================================================================
// ?Action_ChangeAnimStateViaEnter@idAction_ChangeAnimStateVia@@QAA?AVeventVoid@@PAVidEntity@@W4aiAnimWeb_t@@ABVidAnimWebPath@@2W4aiAnimWait_t@@@Z
// EA  : 0x82AA42C0
// RVA : 0x00AA42C0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ChangeAnimStateVia *__fastcall idAction_ChangeAnimStateVia::Action_ChangeAnimStateViaEnter(
        idAction_ChangeAnimStateVia *this,
        idState *result,
        idAI2 *entity,
        aiAnimWeb_t aw,
        const idAnimWebPath *destNode,
        const idAnimWebPath *viaNode,
        const aiAnimWait_t wait)
{
  idAI2 *v13; // r3
  idAI2 *v14; // r29
  unsigned int v15; // r30
  bool v16; // r4
  animWebEvent_t v17; // r10
  idStr v19; // [sp+50h] [-E0h] BYREF
  idStr v20; // [sp+70h] [-C0h] BYREF
  idStr v21; // [sp+90h] [-A0h] BYREF
  idStr v22[4]; // [sp+B0h] [-80h] BYREF

  v13 = idAI2::CastTo(c: entity);
  v22[0].len = 0;
  v22[0].allocedAndFlag = 20;
  v14 = v13;
  v22[0].data = v22[0].baseBuffer;
  v22[0].baseBuffer[0] = 0;
  v21.allocedAndFlag = 20;
  v21.data = v21.baseBuffer;
  v21.len = 0;
  v21.baseBuffer[0] = 0;
  idAI2::GetSubWebAndStateFromAnimWebPath(this: v13, animWebPath: destNode->data, subWebName: v22, stateName: &v21);
  v20.allocedAndFlag = 20;
  v20.data = v20.baseBuffer;
  v20.len = 0;
  v20.baseBuffer[0] = 0;
  v19.allocedAndFlag = 20;
  v19.data = v19.baseBuffer;
  v19.len = 0;
  v19.baseBuffer[0] = 0;
  idAI2::GetSubWebAndStateFromAnimWebPath(this: v14, animWebPath: viaNode->data, subWebName: &v20, stateName: &v19);
  if ( wait != AIANIMWAIT_DONT_WAIT )
  {
    v17 = ANIMWEB_EVENT_START_BLEND_IN;
    if ( wait == AIANIMWAIT_WAIT_FOR_DEST_TO_FINISH_BLEND )
      v17 = ANIMWEB_EVENT_END_BLEND_IN;
    v16 = (_cntlzw((unsigned __int8)idAI2::WaitForAnimToStartVia(
                                      this: v14,
                                      awt: aw,
                                      priority: PRIORITY_LOW,
                                      subWebName: v22[0].data,
                                      stateName: v21.data,
                                      viaSubWebName: v20.data,
                                      viaStateName: v19.data,
                                      ev: v17))
         & 0x20) != 0;
  }
  else
  {
    v15 = idAnimator_AnimWeb::ChangeStateVia(
            this: &v14->aiVolatile.animation.animWebAnimator.ptr[aw],
            subWebName: v22[0].data,
            stateName: v21.data,
            viaSubWebName: v20.data,
            viaStateName: v19.data,
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_NO,
            blendEventMask_: 0);
    if ( !idAI2::AnimEventReceived(this: v14, priority: PRIORITY_LOW) && ai_debugLevel.valueInteger > 0 )
      idLib::Warning(fmt: "ACTION_CHANGE_ANIM_STATE: event already pending!");
    if ( ai_clearEvents.valueInteger != 0 )
      idAI2::ClearAllAnimWebEvents(this: v14, web: AIANIMWEB_BODY, priority: PRIORITY_LOW);
    v16 = (_cntlzw(v15) & 0x20) != 0;
  }
  idState::SetEnterFailed(this: result, failed: v16);
  idStr::FreeData(this: &v19);
  idStr::FreeData(this: &v20);
  idStr::FreeData(this: &v21);
  idStr::FreeData(this: v22);
  return this;
}


// ========================================================================
// __unwind$506763
// EA  : 0x82AA4488
// RVA : 0x00AA4488
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_506763()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 176));
}


// ========================================================================
// __unwind$506764
// EA  : 0x82AA44B0
// RVA : 0x00AA44B0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_506764()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 144));
}


// ========================================================================
// __unwind$506765
// EA  : 0x82AA44D8
// RVA : 0x00AA44D8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_506765()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 112));
}


// ========================================================================
// __unwind$506766
// EA  : 0x82AA4500
// RVA : 0x00AA4500
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_506766()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 80));
}


// ========================================================================
// ??0idAction_ForceAnimState@@QAA@XZ
// EA  : 0x82AA4528
// RVA : 0x00AA4528
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ForceAnimState *__fastcall idAction_ForceAnimState::idAction_ForceAnimState(idAction_ForceAnimState *this)
{
  idState::idState(this, stateType: &idAction_ForceAnimState::Type, childFSMType: nullptr, flags: 1);
  this->__vftable = (idAction_ForceAnimState_vtbl *)&idAction_ForceAnimState::`vftable';
  return this;
}


// ========================================================================
// ?Action_ForceAnimStateEnter@idAction_ForceAnimState@@QAA?AVeventVoid@@PAVidEntity@@W4aiAnimWeb_t@@ABVidAnimWebPath@@HW4aiAnimWait_t@@@Z
// EA  : 0x82AA4590
// RVA : 0x00AA4590
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ForceAnimState *__fastcall idAction_ForceAnimState::Action_ForceAnimStateEnter(
        idAction_ForceAnimState *this,
        idState *result,
        idAI2 *entity,
        aiAnimWeb_t aw,
        const idAnimWebPath *destNode,
        unsigned int blendDurationMS,
        const aiAnimWait_t wait)
{
  idAI2 *v13; // r3
  animWebEvent_t v14; // r30
  idAI2 *v15; // r28
  char *v16; // r8
  char *v17; // r27
  bool v18; // r4
  int v19; // r3
  unsigned __int16 v21; // [sp+50h] [-C0h] BYREF
  unsigned __int16 v22; // [sp+52h] [-BEh] BYREF
  blendParms_t v23; // [sp+60h] [-B0h] BYREF
  idStr v24; // [sp+80h] [-90h] BYREF
  idStr v25[3]; // [sp+A0h] [-70h] BYREF

  v13 = idAI2::CastTo(c: entity);
  v14 = ANIMWEB_EVENT_START_BLEND_IN;
  v25[0].len = 0;
  v25[0].allocedAndFlag = 20;
  v15 = v13;
  v25[0].data = v25[0].baseBuffer;
  v25[0].baseBuffer[0] = 0;
  v24.allocedAndFlag = 20;
  v24.data = v24.baseBuffer;
  v24.len = 0;
  v24.baseBuffer[0] = 0;
  idAI2::GetSubWebAndStateFromAnimWebPath(this: v13, animWebPath: destNode->data, subWebName: v25, stateName: &v24);
  blendParms_t::blendParms_t(this: &v23);
  blendParms_t::SetDurationMS(this: &v23, ms: blendDurationMS);
  v16 = (char *)v15 + 820 * aw;
  v17 = v16 + 32960;
  if ( wait == AIANIMWAIT_DONT_WAIT )
  {
    v18 = (_cntlzw(
             idAnimator_AnimWeb::ForceState(
               this: (idAnimator_AnimWeb *)(v16 + 32960),
               subWebName: v25[0].data,
               stateName: v24.data,
               blendParms: &v23,
               blendEventMask_: 0))
         & 0x20) != 0;
LABEL_9:
    idState::SetEnterFailed(this: result, failed: v18);
    goto LABEL_10;
  }
  idDeclAnimWeb::GetSubWebIndexForName(
    this: (idDeclAnimWeb *)&v22,
    result: *((idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> **)v16 + 8250),
    subWebName: v25[0].data);
  idDeclAnimWeb::GetStateIndexForName(
    this: (idDeclAnimWeb *)&v21,
    result: *((idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> **)v17 + 10),
    name: v24.data);
  if ( wait == AIANIMWAIT_WAIT_FOR_DEST_TO_FINISH_BLEND )
    v14 = ANIMWEB_EVENT_END_BLEND_IN;
  v19 = idAnimator_AnimWeb::ForceState(
          this: (idAnimator_AnimWeb *)v17,
          subWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v22,
          stateIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v21,
          blendParms: &v23,
          blendEventMask_: 0);
  if ( v19 == 0 )
  {
    v18 = true;
    goto LABEL_9;
  }
  if ( v19 == 1 )
    idAI2::SetAnimWebEvent(
      this: v15,
      web: aw,
      priority: PRIORITY_LOW,
      swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v22,
      si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v21,
      eventType: v14,
      eventDef: &EV_AnimWeb_Wait);
LABEL_10:
  idStr::FreeData(this: &v24);
  idStr::FreeData(this: v25);
  return this;
}


// ========================================================================
// __unwind$507065
// EA  : 0x82AA46FC
// RVA : 0x00AA46FC
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_507065()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 160));
}


// ========================================================================
// __unwind$507066
// EA  : 0x82AA4724
// RVA : 0x00AA4724
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_507066()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 128));
}


// ========================================================================
// ??0idAction_Dodge@@QAA@XZ
// EA  : 0x82AA4750
// RVA : 0x00AA4750
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_Dodge *__fastcall idAction_Dodge::idAction_Dodge(idAction_Dodge *this)
{
  idState::idState(this, stateType: &idAction_Dodge::Type, childFSMType: nullptr, flags: 1);
  this->__vftable = (idAction_Dodge_vtbl *)&idAction_Dodge::`vftable';
  this->dodgePoint = vec3_origin;
  return this;
}


// ========================================================================
// ??0idAction_Wait@@QAA@XZ
// EA  : 0x82AA47D0
// RVA : 0x00AA47D0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_Wait *__fastcall idAction_Wait::idAction_Wait(idAction_Wait *this)
{
  idState::idState(this, stateType: &idAction_Wait::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_Wait_vtbl *)&idAction_Wait::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_Dive@@QAA@XZ
// EA  : 0x82AA4830
// RVA : 0x00AA4830
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_Dive *__fastcall idAction_Dive::idAction_Dive(idAction_Dive *this)
{
  idState::idState(this, stateType: &idAction_Dive::Type, childFSMType: nullptr, flags: 1);
  this->__vftable = (idAction_Dive_vtbl *)&idAction_Dive::`vftable';
  this->idealDir.x = 0.0;
  this->idealDir.y = 0.0;
  this->idealDir.z = 0.0;
  this->diveDir.x = 0.0;
  this->diveDir.y = 0.0;
  this->diveDir.z = 0.0;
  return this;
}


// ========================================================================
// ??0idAction_Melee@@QAA@XZ
// EA  : 0x82AA48B0
// RVA : 0x00AA48B0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_Melee *__fastcall idAction_Melee::idAction_Melee(idAction_Melee *this)
{
  idState::idState(this, stateType: &idAction_Melee::Type, childFSMType: nullptr, flags: 1);
  this->__vftable = (idAction_Melee_vtbl *)&idAction_Melee::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_TurnToPoint@@QAA@XZ
// EA  : 0x82AA4910
// RVA : 0x00AA4910
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_TurnToPoint *__fastcall idAction_TurnToPoint::idAction_TurnToPoint(idAction_TurnToPoint *this)
{
  idState::idState(this, stateType: &idAction_TurnToPoint::Type, childFSMType: nullptr, flags: 0);
  this->turnToResult = TURNTO_ERROR;
  this->__vftable = (idAction_TurnToPoint_vtbl *)&idAction_TurnToPoint::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_TurnToEntity@@QAA@XZ
// EA  : 0x82AA4978
// RVA : 0x00AA4978
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_TurnToEntity *__fastcall idAction_TurnToEntity::idAction_TurnToEntity(idAction_TurnToEntity *this)
{
  idState::idState(this, stateType: &idAction_TurnToEntity::Type, childFSMType: nullptr, flags: 0);
  this->turnToResult = TURNTO_ERROR;
  this->__vftable = (idAction_TurnToEntity_vtbl *)&idAction_TurnToEntity::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_TurnToEntityWithOffset@@QAA@XZ
// EA  : 0x82AA49E0
// RVA : 0x00AA49E0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_TurnToEntityWithOffset *__fastcall idAction_TurnToEntityWithOffset::idAction_TurnToEntityWithOffset(
        idAction_TurnToEntityWithOffset *this)
{
  idState::idState(this, stateType: &idAction_TurnToEntityWithOffset::Type, childFSMType: nullptr, flags: 0);
  this->turnToResult = TURNTO_ERROR;
  this->__vftable = (idAction_TurnToEntityWithOffset_vtbl *)&idAction_TurnToEntityWithOffset::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_WaitForEntity@@QAA@XZ
// EA  : 0x82AA4A48
// RVA : 0x00AA4A48
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_WaitForEntity *__fastcall idAction_WaitForEntity::idAction_WaitForEntity(idAction_WaitForEntity *this)
{
  idState::idState(this, stateType: &idAction_WaitForEntity::Type, childFSMType: nullptr, flags: 0);
  this->targetEntity = nullptr;
  this->__vftable = (idAction_WaitForEntity_vtbl *)&idAction_WaitForEntity::`vftable';
  this->range = 0.0;
  return this;
}


// ========================================================================
// ??0idAction_EnterVehicle@@QAA@XZ
// EA  : 0x82AA4AB8
// RVA : 0x00AA4AB8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_EnterVehicle *__fastcall idAction_EnterVehicle::idAction_EnterVehicle(idAction_EnterVehicle *this)
{
  idState::idState(this, stateType: &idAction_EnterVehicle::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_EnterVehicle_vtbl *)&idAction_EnterVehicle::`vftable';
  return this;
}


// ========================================================================
// ?Evaluate@VoiceOverFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AA4B18
// RVA : 0x00AA4B18
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall VoiceOverFinished::Evaluate(
        VoiceOverFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r31

  if ( HIBYTE(state[1].__vftable) == 0 )
    return 8;
  value = ai->aiVolatile.voiceController.nextVoiceTime.value;
  return __CFADD__(
           ((int (__fastcall *)(idGameLocal *, int, idAIFSM *))gameLocal->GetGameMs)(
             a1: gameLocal,
             a2: 1,
             a3: parentFSM)
         - value,
           value ^ 0x80000000)
       ? 0
       : 0x3F;
}


// ========================================================================
// ??0idAction_PlayVoiceOver@@QAA@XZ
// EA  : 0x82AA4BA8
// RVA : 0x00AA4BA8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_PlayVoiceOver *__fastcall idAction_PlayVoiceOver::idAction_PlayVoiceOver(idAction_PlayVoiceOver *this)
{
  idState::idState(this, stateType: &idAction_PlayVoiceOver::Type, childFSMType: nullptr, flags: 0);
  this->waitUntilFinished = false;
  this->__vftable = (idAction_PlayVoiceOver_vtbl *)&idAction_PlayVoiceOver::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_StopVoiceOver@@QAA@XZ
// EA  : 0x82AA4C10
// RVA : 0x00AA4C10
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_StopVoiceOver *__fastcall idAction_StopVoiceOver::idAction_StopVoiceOver(idAction_StopVoiceOver *this)
{
  idState::idState(this, stateType: &idAction_StopVoiceOver::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_StopVoiceOver_vtbl *)&idAction_StopVoiceOver::`vftable';
  return this;
}


// ========================================================================
// ?Evaluate@InteractionVoiceOverFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AA4C70
// RVA : 0x00AA4C70
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall InteractionVoiceOverFinished::Evaluate(
        InteractionVoiceOverFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r31
  idAIStateTransition::aiTransCode_t result; // r3
  idAIState_vtbl *v9; // r9
  idEntity *v10; // r3
  idPhysics *Physics; // r30
  idEntity *v12; // r3
  idPhysics *v13; // r31
  float *v14; // r30
  float *v15; // r3
  double v16; // fp8
  double v17; // fp4
  double v18; // fp1

  value = ai->aiVolatile.voiceController.nextVoiceTime.value;
  if ( value <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
    return TRANSCODE_PLAY_VOICEOVER_FINISHED;
  if ( *(float *)&state[1].listenerList <= 0.0 )
    return 0;
  v9 = state[1].__vftable;
  if ( gameLocal->spawnIds.ptr[(unsigned __int16)v9 & 0x1FFF] != (int)v9 >> 13 )
    return TRANSCODE_TARGET_LEFT_INTERACTION;
  v10 = gameLocal->entities.ptr[(unsigned __int16)v9 & 0x1FFF];
  if ( v10 == nullptr || idEntity::CastTo(c: v10) == nullptr )
    return TRANSCODE_TARGET_LEFT_INTERACTION;
  Physics = idEntity::GetPhysics(this: ai);
  v12 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&state[1]);
  v13 = idEntity::GetPhysics(this: v12);
  v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v15 = (float *)v13->GetOrigin(this: v13, a2: 0);
  v16 = (float)(v15[2] - v14[2]);
  v17 = (float)(v15[1] - v14[1]);
  v18 = (float)((float)((float)v17 * (float)v17)
              + (float)((float)((float)(*v15 - *v14) * (float)(*v15 - *v14)) + (float)((float)v16 * (float)v16)));
  result = TRANSCODE_TARGET_LEFT_INTERACTION;
  if ( v18 <= (float)(*(float *)&state[1].listenerList * *(float *)&state[1].listenerList) )
    return 0;
  return result;
}


// ========================================================================
// ??0idAction_PlayInteractionVoiceOver@@QAA@XZ
// EA  : 0x82AA4DC8
// RVA : 0x00AA4DC8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_PlayInteractionVoiceOver *__fastcall idAction_PlayInteractionVoiceOver::idAction_PlayInteractionVoiceOver(
        idAction_PlayInteractionVoiceOver *this)
{
  idState::idState(this, stateType: &idAction_PlayInteractionVoiceOver::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_PlayInteractionVoiceOver_vtbl *)&idAction_PlayInteractionVoiceOver::`vftable';
  this->trackEntity.spawnId.value = 0x1FFF;
  this->abortScript = false;
  this->maxDistance = 0.0;
  return this;
}


// ========================================================================
// ??0idAction_PlayOverrideAnim@@QAA@XZ
// EA  : 0x82AA4E40
// RVA : 0x00AA4E40
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_PlayOverrideAnim *__fastcall idAction_PlayOverrideAnim::idAction_PlayOverrideAnim(
        idAction_PlayOverrideAnim *this)
{
  idState::idState(this, stateType: &idAction_PlayOverrideAnim::Type, childFSMType: nullptr, flags: 1);
  this->__vftable = (idAction_PlayOverrideAnim_vtbl *)&idAction_PlayOverrideAnim::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_PlayOverrideAnimInterrupt@@QAA@XZ
// EA  : 0x82AA4EA0
// RVA : 0x00AA4EA0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_PlayOverrideAnimInterrupt *__fastcall idAction_PlayOverrideAnimInterrupt::idAction_PlayOverrideAnimInterrupt(
        idAction_PlayOverrideAnimInterrupt *this)
{
  idState::idState(this, stateType: &idAction_PlayOverrideAnimInterrupt::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_PlayOverrideAnimInterrupt_vtbl *)&idAction_PlayOverrideAnimInterrupt::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_LeapAttack@@QAA@XZ
// EA  : 0x82AA4F00
// RVA : 0x00AA4F00
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_LeapAttack *__fastcall idAction_LeapAttack::idAction_LeapAttack(idAction_LeapAttack *this)
{
  idState::idState(this, stateType: &idAction_LeapAttack::Type, childFSMType: nullptr, flags: 1);
  this->__vftable = (idAction_LeapAttack_vtbl *)&idAction_LeapAttack::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_DrawWeapon@@QAA@XZ
// EA  : 0x82AA4F60
// RVA : 0x00AA4F60
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_DrawWeapon *__fastcall idAction_DrawWeapon::idAction_DrawWeapon(idAction_DrawWeapon *this)
{
  idState::idState(this, stateType: &idAction_DrawWeapon::Type, childFSMType: nullptr, flags: 1);
  this->__vftable = (idAction_DrawWeapon_vtbl *)&idAction_DrawWeapon::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_HolsterWeapon@@QAA@XZ
// EA  : 0x82AA4FC0
// RVA : 0x00AA4FC0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_HolsterWeapon *__fastcall idAction_HolsterWeapon::idAction_HolsterWeapon(idAction_HolsterWeapon *this)
{
  idState::idState(this, stateType: &idAction_HolsterWeapon::Type, childFSMType: nullptr, flags: 1);
  this->__vftable = (idAction_HolsterWeapon_vtbl *)&idAction_HolsterWeapon::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_PerformCoverAction@@QAA@XZ
// EA  : 0x82AA5020
// RVA : 0x00AA5020
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_PerformCoverAction *__fastcall idAction_PerformCoverAction::idAction_PerformCoverAction(
        idAction_PerformCoverAction *this)
{
  idState::idState(this, stateType: &idAction_PerformCoverAction::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_PerformCoverAction_vtbl *)&idAction_PerformCoverAction::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_WaitForPlayerInteraction@@QAA@XZ
// EA  : 0x82AA5080
// RVA : 0x00AA5080
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_WaitForPlayerInteraction *__fastcall idAction_WaitForPlayerInteraction::idAction_WaitForPlayerInteraction(
        idAction_WaitForPlayerInteraction *this)
{
  idState::idState(this, stateType: &idAction_WaitForPlayerInteraction::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_WaitForPlayerInteraction_vtbl *)&idAction_WaitForPlayerInteraction::`vftable';
  this->maxDist = 0.0;
  return this;
}


// ========================================================================
// ??0idAction_WaitForAIVar@@QAA@XZ
// EA  : 0x82AA50E8
// RVA : 0x00AA50E8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_WaitForAIVar *__fastcall idAction_WaitForAIVar::idAction_WaitForAIVar(idAction_WaitForAIVar *this)
{
  idState::idState(this, stateType: &idAction_WaitForAIVar::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_WaitForAIVar_vtbl *)&idAction_WaitForAIVar::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_PerfectMovement@@QAA@XZ
// EA  : 0x82AA5148
// RVA : 0x00AA5148
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_PerfectMovement *__fastcall idAction_PerfectMovement::idAction_PerfectMovement(idAction_PerfectMovement *this)
{
  idState::idState(this, stateType: &idAction_PerfectMovement::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_PerfectMovement_vtbl *)&idAction_PerfectMovement::`vftable';
  this->swiWhenFinished.value = -1;
  this->siWhenFinished.value = -1;
  return this;
}


// ========================================================================
// ?Action_PerfectMovementEnter@idAction_PerfectMovement@@QAA?AVeventVoid@@PAVidEntity@@ABVidVec3@@ABVidQuat@@PBD3_N4@Z
// EA  : 0x82AA51B0
// RVA : 0x00AA51B0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_PerfectMovement *__fastcall idAction_PerfectMovement::Action_PerfectMovementEnter(
        idAction_PerfectMovement *this,
        eventVoid *result,
        idAI2 *entity,
        const idVec3 *perfectMovementStartPoint,
        idVec3 *startAxis,
        const char *animWebPath,
        const char *animWebState,
        const bool forceTransition,
        const bool isPerfectDestination,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        char a28)
{
  idAI2 *v35; // r31
  idAnimator_AnimWeb *p_animation; // r30
  idAIMoveState *p_moveState; // r3
  int v38; // r3
  alertCycle_t AlertCycle; // r3
  aiSubWeb_t v40; // r3
  unsigned __int16 v42; // [sp+50h] [-80h] BYREF
  unsigned __int16 v43; // [sp+52h] [-7Eh] BYREF
  __int16 v44; // [sp+54h] [-7Ch] BYREF
  blendParms_t v45[5]; // [sp+60h] [-70h] BYREF

  v35 = idAI2::CastTo(c: entity);
  p_animation = (idAnimator_AnimWeb *)&v35->aiVolatile.animation;
  v35->aiVolatile.focus.enableBodyRotation = false;
  idDeclAnimWeb::GetSubWebIndexForName(
    this: (idDeclAnimWeb *)&v43,
    result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v35->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    subWebName: animWebPath);
  idDeclAnimWeb::GetStateIndexForName(
    this: (idDeclAnimWeb *)&v42,
    result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v35->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    name: animWebState);
  p_moveState = &v35->aiVolatile.physics.moveState;
  if ( a28 != 0 )
    idAIMoveState::StartPerfectDestination(
      this: p_moveState,
      idealAxis: startAxis,
      idealPos: perfectMovementStartPoint,
      lerpTimeMs: 500,
      swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v43,
      si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v42);
  else
    idAIMoveState::StartPerfectOrigin(
      this: p_moveState,
      idealAxis: (const idQuat *)startAxis,
      idealPos: perfectMovementStartPoint,
      lerpTimeMs: 500,
      swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v43,
      si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v42);
  idDeclAnimWeb::FindNodeIndex(
    this: (idDeclAnimWeb *)&v44,
    result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)v35->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v43,
    stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v42);
  if ( v44 >= 0 )
  {
    if ( forceTransition )
    {
      blendParms_t::blendParms_t(this: v45);
      blendParms_t::SetDuration(this: v45, frame: 3);
      blendParms_t::SetDestStartFrame(this: v45, frame: 0);
      v38 = idAnimator_AnimWeb::ForceState(
              this: p_animation,
              subWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v43,
              stateIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v42,
              blendParms: v45,
              blendEventMask_: 0);
    }
    else
    {
      v38 = idAnimator_AnimWeb::ChangeState(
              this: p_animation,
              subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v43,
              stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v42,
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_NO,
              blendEventMask_: 0);
    }
    if ( v38 == 1 )
      idAI2::SetAnimWebEvent(
        this: v35,
        web: AIANIMWEB_BODY,
        priority: PRIORITY_LOW,
        swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v43,
        si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v42,
        eventType: ANIMWEB_EVENT_DEST_CLAMPED,
        eventDef: &EV_AnimWeb_Wait);
  }
  AlertCycle = idAI2::GetAlertCycle(this: v35);
  v40 = idAI2::AlertCycleToSubWeb(this: v35, ac: AlertCycle);
  idAI2::FindAnimWebAndStateIndices(
    this: v35,
    web: AIANIMWEB_BODY,
    subWeb: v40,
    stateName: "idle",
    changeWeapon: false,
    newWeapon: nullptr,
    subWebIndex: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)&result[28],
    stateIndex: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)&result[30]);
  return this;
}


// ========================================================================
// ??0idAction_SetAlertCycle@@QAA@XZ
// EA  : 0x82AA5340
// RVA : 0x00AA5340
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetAlertCycle *__fastcall idAction_SetAlertCycle::idAction_SetAlertCycle(idAction_SetAlertCycle *this)
{
  idState::idState(this, stateType: &idAction_SetAlertCycle::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_SetAlertCycle_vtbl *)&idAction_SetAlertCycle::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetSubWeb@@QAA@XZ
// EA  : 0x82AA53A0
// RVA : 0x00AA53A0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetSubWeb *__fastcall idAction_SetSubWeb::idAction_SetSubWeb(idAction_SetSubWeb *this)
{
  idState::idState(this, stateType: &idAction_SetSubWeb::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_SetSubWeb_vtbl *)&idAction_SetSubWeb::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetFocus@@QAA@XZ
// EA  : 0x82AA5400
// RVA : 0x00AA5400
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetFocus *__fastcall idAction_SetFocus::idAction_SetFocus(idAction_SetFocus *this)
{
  idState::idState(this, stateType: &idAction_SetFocus::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_SetFocus_vtbl *)&idAction_SetFocus::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_ClearLookFocus@@QAA@XZ
// EA  : 0x82AA5460
// RVA : 0x00AA5460
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ClearLookFocus *__fastcall idAction_ClearLookFocus::idAction_ClearLookFocus(idAction_ClearLookFocus *this)
{
  idState::idState(this, stateType: &idAction_ClearLookFocus::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_ClearLookFocus_vtbl *)&idAction_ClearLookFocus::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_ClearAimFocus@@QAA@XZ
// EA  : 0x82AA54C0
// RVA : 0x00AA54C0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ClearAimFocus *__fastcall idAction_ClearAimFocus::idAction_ClearAimFocus(idAction_ClearAimFocus *this)
{
  idState::idState(this, stateType: &idAction_ClearAimFocus::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_ClearAimFocus_vtbl *)&idAction_ClearAimFocus::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetAimPoint@@QAA@XZ
// EA  : 0x82AA5520
// RVA : 0x00AA5520
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetAimPoint *__fastcall idAction_SetAimPoint::idAction_SetAimPoint(idAction_SetAimPoint *this)
{
  idState::idState(this, stateType: &idAction_SetAimPoint::Type, childFSMType: nullptr, flags: 0);
  this->__vftable = (idAction_SetAimPoint_vtbl *)&idAction_SetAimPoint::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetFireMode@@QAA@XZ
// EA  : 0x82AA5580
// RVA : 0x00AA5580
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetFireMode *__fastcall idAction_SetFireMode::idAction_SetFireMode(idAction_SetFireMode *this)
{
  idState::idState(this, stateType: &idAction_SetFireMode::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SetFireMode_vtbl *)&idAction_SetFireMode::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetScriptAbort@@QAA@XZ
// EA  : 0x82AA55E0
// RVA : 0x00AA55E0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetScriptAbort *__fastcall idAction_SetScriptAbort::idAction_SetScriptAbort(idAction_SetScriptAbort *this)
{
  idState::idState(this, stateType: &idAction_SetScriptAbort::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SetScriptAbort_vtbl *)&idAction_SetScriptAbort::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetPosture@@QAA@XZ
// EA  : 0x82AA5640
// RVA : 0x00AA5640
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetPosture *__fastcall idAction_SetPosture::idAction_SetPosture(idAction_SetPosture *this)
{
  idState::idState(this, stateType: &idAction_SetPosture::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SetPosture_vtbl *)&idAction_SetPosture::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetWalkState@@QAA@XZ
// EA  : 0x82AA56A0
// RVA : 0x00AA56A0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetWalkState *__fastcall idAction_SetWalkState::idAction_SetWalkState(idAction_SetWalkState *this)
{
  idState::idState(this, stateType: &idAction_SetWalkState::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SetWalkState_vtbl *)&idAction_SetWalkState::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetSitState@@QAA@XZ
// EA  : 0x82AA5700
// RVA : 0x00AA5700
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetSitState *__fastcall idAction_SetSitState::idAction_SetSitState(idAction_SetSitState *this)
{
  idState::idState(this, stateType: &idAction_SetSitState::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SetSitState_vtbl *)&idAction_SetSitState::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetStandState@@QAA@XZ
// EA  : 0x82AA5760
// RVA : 0x00AA5760
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetStandState *__fastcall idAction_SetStandState::idAction_SetStandState(idAction_SetStandState *this)
{
  idState::idState(this, stateType: &idAction_SetStandState::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SetStandState_vtbl *)&idAction_SetStandState::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetIdleState@@QAA@XZ
// EA  : 0x82AA57C0
// RVA : 0x00AA57C0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetIdleState *__fastcall idAction_SetIdleState::idAction_SetIdleState(idAction_SetIdleState *this)
{
  idState::idState(this, stateType: &idAction_SetIdleState::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SetIdleState_vtbl *)&idAction_SetIdleState::`vftable';
  return this;
}


// ========================================================================
// ?Action_SetIdleStateEnter@idAction_SetIdleState@@QAA?AVeventVoid@@PAVidEntity@@W4runIndexType_t@@@Z
// EA  : 0x82AA5820
// RVA : 0x00AA5820
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetIdleState *__fastcall idAction_SetIdleState::Action_SetIdleStateEnter(
        idAction_SetIdleState *this,
        eventVoid *result,
        idAI2 *entity,
        runIndexType_t state)
{
  bool v6; // r5
  runIndexType_t v7; // r4
  idAI2 *v8; // r3
  double v9; // fp2
  double v10; // fp0

  v8 = idAI2::CastTo(c: entity);
  v9 = 0.0;
  v10 = 0.0;
  if ( state == ANIMWEBAI_RUNINDEXTYPE_INJURED )
  {
    v9 = 1.0;
    v10 = 6.0;
  }
  idAnimWebAI::SetForwardRunIndex(
    this: v8->aiVolatile.animation.animWebAnimator.ptr,
    newRunIndex: v10,
    newIdleIndex: v9,
    t: v7,
    blend: v6,
    a6: state,
    a7: 1);
  return this;
}


// ========================================================================
// ??0idAction_IgnorePlayerApproach@@QAA@XZ
// EA  : 0x82AA58A0
// RVA : 0x00AA58A0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_IgnorePlayerApproach *__fastcall idAction_IgnorePlayerApproach::idAction_IgnorePlayerApproach(
        idAction_IgnorePlayerApproach *this)
{
  idState::idState(this, stateType: &idAction_IgnorePlayerApproach::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_IgnorePlayerApproach_vtbl *)&idAction_IgnorePlayerApproach::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_NoticePlayerApproach@@QAA@XZ
// EA  : 0x82AA5900
// RVA : 0x00AA5900
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_NoticePlayerApproach *__fastcall idAction_NoticePlayerApproach::idAction_NoticePlayerApproach(
        idAction_NoticePlayerApproach *this)
{
  idState::idState(this, stateType: &idAction_NoticePlayerApproach::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_NoticePlayerApproach_vtbl *)&idAction_NoticePlayerApproach::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetPlayerEnemy@@QAA@XZ
// EA  : 0x82AA5960
// RVA : 0x00AA5960
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetPlayerEnemy *__fastcall idAction_SetPlayerEnemy::idAction_SetPlayerEnemy(idAction_SetPlayerEnemy *this)
{
  idState::idState(this, stateType: &idAction_SetPlayerEnemy::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SetPlayerEnemy_vtbl *)&idAction_SetPlayerEnemy::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetEnemy@@QAA@XZ
// EA  : 0x82AA59C0
// RVA : 0x00AA59C0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetEnemy *__fastcall idAction_SetEnemy::idAction_SetEnemy(idAction_SetEnemy *this)
{
  idState::idState(this, stateType: &idAction_SetEnemy::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SetEnemy_vtbl *)&idAction_SetEnemy::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SearchToTarget@@QAA@XZ
// EA  : 0x82AA5A20
// RVA : 0x00AA5A20
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SearchToTarget *__fastcall idAction_SearchToTarget::idAction_SearchToTarget(idAction_SearchToTarget *this)
{
  idState::idState(this, stateType: &idAction_SearchToTarget::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SearchToTarget_vtbl *)&idAction_SearchToTarget::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetPlayerFocus@@QAA@XZ
// EA  : 0x82AA5A80
// RVA : 0x00AA5A80
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetPlayerFocus *__fastcall idAction_SetPlayerFocus::idAction_SetPlayerFocus(idAction_SetPlayerFocus *this)
{
  idState::idState(this, stateType: &idAction_SetPlayerFocus::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SetPlayerFocus_vtbl *)&idAction_SetPlayerFocus::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetActionNodeGroup@@QAA@XZ
// EA  : 0x82AA5AE0
// RVA : 0x00AA5AE0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetActionNodeGroup *__fastcall idAction_SetActionNodeGroup::idAction_SetActionNodeGroup(
        idAction_SetActionNodeGroup *this)
{
  idState::idState(this, stateType: &idAction_SetActionNodeGroup::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SetActionNodeGroup_vtbl *)&idAction_SetActionNodeGroup::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_Trigger@@QAA@XZ
// EA  : 0x82AA5B40
// RVA : 0x00AA5B40
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_Trigger *__fastcall idAction_Trigger::idAction_Trigger(idAction_Trigger *this)
{
  idState::idState(this, stateType: &idAction_Trigger::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_Trigger_vtbl *)&idAction_Trigger::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_EnableDamage@@QAA@XZ
// EA  : 0x82AA5BA0
// RVA : 0x00AA5BA0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_EnableDamage *__fastcall idAction_EnableDamage::idAction_EnableDamage(idAction_EnableDamage *this)
{
  idState::idState(this, stateType: &idAction_EnableDamage::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_EnableDamage_vtbl *)&idAction_EnableDamage::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_EnablePain@@QAA@XZ
// EA  : 0x82AA5C00
// RVA : 0x00AA5C00
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_EnablePain *__fastcall idAction_EnablePain::idAction_EnablePain(idAction_EnablePain *this)
{
  idState::idState(this, stateType: &idAction_EnablePain::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_EnablePain_vtbl *)&idAction_EnablePain::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_EnableAutoFocus@@QAA@XZ
// EA  : 0x82AA5C60
// RVA : 0x00AA5C60
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_EnableAutoFocus *__fastcall idAction_EnableAutoFocus::idAction_EnableAutoFocus(idAction_EnableAutoFocus *this)
{
  idState::idState(this, stateType: &idAction_EnableAutoFocus::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_EnableAutoFocus_vtbl *)&idAction_EnableAutoFocus::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_EnableBodyRotation@@QAA@XZ
// EA  : 0x82AA5CC0
// RVA : 0x00AA5CC0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_EnableBodyRotation *__fastcall idAction_EnableBodyRotation::idAction_EnableBodyRotation(
        idAction_EnableBodyRotation *this)
{
  idState::idState(this, stateType: &idAction_EnableBodyRotation::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_EnableBodyRotation_vtbl *)&idAction_EnableBodyRotation::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_EnableWalkIK@@QAA@XZ
// EA  : 0x82AA5D20
// RVA : 0x00AA5D20
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_EnableWalkIK *__fastcall idAction_EnableWalkIK::idAction_EnableWalkIK(idAction_EnableWalkIK *this)
{
  idState::idState(this, stateType: &idAction_EnableWalkIK::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_EnableWalkIK_vtbl *)&idAction_EnableWalkIK::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_EnableHeadTracking@@QAA@XZ
// EA  : 0x82AA5D80
// RVA : 0x00AA5D80
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_EnableHeadTracking *__fastcall idAction_EnableHeadTracking::idAction_EnableHeadTracking(
        idAction_EnableHeadTracking *this)
{
  idState::idState(this, stateType: &idAction_EnableHeadTracking::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_EnableHeadTracking_vtbl *)&idAction_EnableHeadTracking::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_ForceOpenCombat@@QAA@XZ
// EA  : 0x82AA5DE0
// RVA : 0x00AA5DE0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ForceOpenCombat *__fastcall idAction_ForceOpenCombat::idAction_ForceOpenCombat(idAction_ForceOpenCombat *this)
{
  idState::idState(this, stateType: &idAction_ForceOpenCombat::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_ForceOpenCombat_vtbl *)&idAction_ForceOpenCombat::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_ForceAwarenessByDistance@@QAA@XZ
// EA  : 0x82AA5E40
// RVA : 0x00AA5E40
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ForceAwarenessByDistance *__fastcall idAction_ForceAwarenessByDistance::idAction_ForceAwarenessByDistance(
        idAction_ForceAwarenessByDistance *this)
{
  idState::idState(this, stateType: &idAction_ForceAwarenessByDistance::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_ForceAwarenessByDistance_vtbl *)&idAction_ForceAwarenessByDistance::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_ForcePlayerInteraction@@QAA@XZ
// EA  : 0x82AA5EA0
// RVA : 0x00AA5EA0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ForcePlayerInteraction *__fastcall idAction_ForcePlayerInteraction::idAction_ForcePlayerInteraction(
        idAction_ForcePlayerInteraction *this)
{
  idState::idState(this, stateType: &idAction_ForcePlayerInteraction::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_ForcePlayerInteraction_vtbl *)&idAction_ForcePlayerInteraction::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetAIVar@@QAA@XZ
// EA  : 0x82AA5F00
// RVA : 0x00AA5F00
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetAIVar *__fastcall idAction_SetAIVar::idAction_SetAIVar(idAction_SetAIVar *this)
{
  idState::idState(this, stateType: &idAction_SetAIVar::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SetAIVar_vtbl *)&idAction_SetAIVar::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetScriptFlag@@QAA@XZ
// EA  : 0x82AA5F60
// RVA : 0x00AA5F60
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetScriptFlag *__fastcall idAction_SetScriptFlag::idAction_SetScriptFlag(idAction_SetScriptFlag *this)
{
  idState::idState(this, stateType: &idAction_SetScriptFlag::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SetScriptFlag_vtbl *)&idAction_SetScriptFlag::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_ClearScriptFlag@@QAA@XZ
// EA  : 0x82AA5FC0
// RVA : 0x00AA5FC0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ClearScriptFlag *__fastcall idAction_ClearScriptFlag::idAction_ClearScriptFlag(idAction_ClearScriptFlag *this)
{
  idState::idState(this, stateType: &idAction_ClearScriptFlag::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_ClearScriptFlag_vtbl *)&idAction_ClearScriptFlag::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetPerceptionFlag@@QAA@XZ
// EA  : 0x82AA6020
// RVA : 0x00AA6020
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetPerceptionFlag *__fastcall idAction_SetPerceptionFlag::idAction_SetPerceptionFlag(
        idAction_SetPerceptionFlag *this)
{
  idState::idState(this, stateType: &idAction_SetPerceptionFlag::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SetPerceptionFlag_vtbl *)&idAction_SetPerceptionFlag::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_ClearPerceptionFlag@@QAA@XZ
// EA  : 0x82AA6080
// RVA : 0x00AA6080
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ClearPerceptionFlag *__fastcall idAction_ClearPerceptionFlag::idAction_ClearPerceptionFlag(
        idAction_ClearPerceptionFlag *this)
{
  idState::idState(this, stateType: &idAction_ClearPerceptionFlag::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_ClearPerceptionFlag_vtbl *)&idAction_ClearPerceptionFlag::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_GiveItem@@QAA@XZ
// EA  : 0x82AA60E0
// RVA : 0x00AA60E0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_GiveItem *__fastcall idAction_GiveItem::idAction_GiveItem(idAction_GiveItem *this)
{
  idState::idState(this, stateType: &idAction_GiveItem::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_GiveItem_vtbl *)&idAction_GiveItem::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_TakeItem@@QAA@XZ
// EA  : 0x82AA6140
// RVA : 0x00AA6140
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_TakeItem *__fastcall idAction_TakeItem::idAction_TakeItem(idAction_TakeItem *this)
{
  idState::idState(this, stateType: &idAction_TakeItem::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_TakeItem_vtbl *)&idAction_TakeItem::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_ClearWorldState@@QAA@XZ
// EA  : 0x82AA61A0
// RVA : 0x00AA61A0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ClearWorldState *__fastcall idAction_ClearWorldState::idAction_ClearWorldState(idAction_ClearWorldState *this)
{
  idState::idState(this, stateType: &idAction_ClearWorldState::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_ClearWorldState_vtbl *)&idAction_ClearWorldState::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_ShowAttachment@@QAA@XZ
// EA  : 0x82AA6200
// RVA : 0x00AA6200
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ShowAttachment *__fastcall idAction_ShowAttachment::idAction_ShowAttachment(idAction_ShowAttachment *this)
{
  idState::idState(this, stateType: &idAction_ShowAttachment::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_ShowAttachment_vtbl *)&idAction_ShowAttachment::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_HideAttachment@@QAA@XZ
// EA  : 0x82AA6260
// RVA : 0x00AA6260
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_HideAttachment *__fastcall idAction_HideAttachment::idAction_HideAttachment(idAction_HideAttachment *this)
{
  idState::idState(this, stateType: &idAction_HideAttachment::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_HideAttachment_vtbl *)&idAction_HideAttachment::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_DropAttachment@@QAA@XZ
// EA  : 0x82AA62C0
// RVA : 0x00AA62C0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_DropAttachment *__fastcall idAction_DropAttachment::idAction_DropAttachment(idAction_DropAttachment *this)
{
  idState::idState(this, stateType: &idAction_DropAttachment::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_DropAttachment_vtbl *)&idAction_DropAttachment::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetMoveMode@@QAA@XZ
// EA  : 0x82AA6320
// RVA : 0x00AA6320
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetMoveMode *__fastcall idAction_SetMoveMode::idAction_SetMoveMode(idAction_SetMoveMode *this)
{
  idState::idState(this, stateType: &idAction_SetMoveMode::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SetMoveMode_vtbl *)&idAction_SetMoveMode::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_SetAccuracy@@QAA@XZ
// EA  : 0x82AA6380
// RVA : 0x00AA6380
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_SetAccuracy *__fastcall idAction_SetAccuracy::idAction_SetAccuracy(idAction_SetAccuracy *this)
{
  idState::idState(this, stateType: &idAction_SetAccuracy::Type, childFSMType: nullptr, flags: 2);
  this->__vftable = (idAction_SetAccuracy_vtbl *)&idAction_SetAccuracy::`vftable';
  return this;
}


// ========================================================================
// ??0idAction_ScriptedAnimWeb@@QAA@XZ
// EA  : 0x82AA63E0
// RVA : 0x00AA63E0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ScriptedAnimWeb *__fastcall idAction_ScriptedAnimWeb::idAction_ScriptedAnimWeb(idAction_ScriptedAnimWeb *this)
{
  idState::idState(this, stateType: &idAction_ScriptedAnimWeb::Type, childFSMType: nullptr, flags: 2);
  this->currentScriptState = 0;
  this->__vftable = (idAction_ScriptedAnimWeb_vtbl *)&idAction_ScriptedAnimWeb::`vftable';
  this->currentSubWebTarget.value = -1;
  this->currentStateTarget.value = -1;
  return this;
}


// ========================================================================
// ?AIAction_ExitState@idAction_ScriptedAnimWeb@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AA6458
// RVA : 0x00AA6458
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_ScriptedAnimWeb::AIAction_ExitState(
        idAction_ScriptedAnimWeb *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  char v6; // r28
  idAIScriptedAnimWeb::animState_t *stateInfo; // r11
  idList<idAIScriptedAnimWeb::animWebState_t,5> *animWebStates; // r9
  int currentScriptState; // r8
  int v10; // r11
  int v11; // r25
  int v12; // r24
  idAnimStack *v13; // r3
  double v14; // fp1
  char v15; // r11
  int v16; // r28
  const idAnimStack *v17; // r3
  int v18; // r28
  const idAnimStack *v19; // r3
  unsigned __int16 v20; // [sp+50h] [-A0h] BYREF
  idAIScriptedAnimWeb::animState_t *v21; // [sp+54h] [-9Ch] BYREF
  idStr v22; // [sp+60h] [-90h] BYREF
  idStr v23[3]; // [sp+80h] [-70h] BYREF

  v6 = 0;
  if ( (*((_BYTE *)this + 84) & 0x80) == 0 )
  {
    stateInfo = this->stateInfo;
    if ( stateInfo != nullptr )
    {
      animWebStates = stateInfo->animWebStates;
      currentScriptState = this->currentScriptState;
      v21 = this->stateInfo;
      v10 = (int)&animWebStates->list[currentScriptState];
      if ( *(_DWORD *)(v10 + 64) != 0 )
      {
        v23[0].len = 0;
        v23[0].baseBuffer[0] = 0;
        v23[0].allocedAndFlag = 20;
        v23[0].data = v23[0].baseBuffer;
        v22.allocedAndFlag = 20;
        v22.data = v22.baseBuffer;
        v22.len = 0;
        v22.baseBuffer[0] = 0;
        idAI2::GetSubWebAndStateFromAnimWebPath(
          this: ai,
          animWebPath: *(const char **)(v10 + 68),
          subWebName: v23,
          stateName: &v22);
        idDeclAnimWeb::GetSubWebIndexForName(
          this: (idDeclAnimWeb *)&v21,
          result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
          subWebName: v23[0].data);
        idDeclAnimWeb::GetStateIndexForName(
          this: (idDeclAnimWeb *)&v20,
          result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
          name: v22.data);
        idAI2::ChangeAnimState(
          this: ai,
          web: AIANIMWEB_BODY,
          subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v21),
          stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v20,
          interruptPath: INTR_PATH_YES,
          interruptBlend: INTR_BLEND_YES);
        idAIMoveState::SetMovementModeForReal(this: &ai->aiVolatile.physics.moveState, mode: AIMOVEMODE_ANIM);
        v11 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
        v12 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        v13 = ai->GetAnimStack_2(this: ai);
        idAnimator_JointMod::PreBlendSnapshot(
          this: (idAnimator_JointMod *)&ai->aiVolatile.animation,
          stack: v13,
          curTime: v12,
          ticksPerSec: v11,
          fraction: v14);
        idStr::FreeData(this: &v22);
        idStr::FreeData(this: v23);
      }
    }
  }
  if ( (*((_BYTE *)this + 84) & 0x20) == 0 )
  {
    if ( (*((_BYTE *)this + 84) & 0x40) != 0 )
    {
      if ( !ai->walkIK.enabled || (v15 = 1, ai->walkIK.enabledLegs == 0) )
        v15 = 0;
      if ( v15 == 0 )
      {
        idAnimator_WalkIK::EnableAll(this: &ai->walkIK);
        idAnimator_Base::SetAlpha(this: &ai->walkIK, alpha: 0.0);
        v16 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        v17 = ai->GetAnimStack_2(this: ai);
        idAnimator_Base::Start(this: &ai->walkIK, stack: v17, curTime: v16, blendDurationMS: 200, reset: false);
        goto LABEL_18;
      }
      if ( (*((_BYTE *)this + 84) & 0x40) != 0 )
        goto LABEL_18;
    }
    if ( ai->walkIK.enabled && ai->walkIK.enabledLegs != 0 )
      v6 = 1;
    if ( v6 != 0 )
    {
      idAnimator_WalkIK::DisableAll(this: &ai->walkIK);
      v18 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      v19 = ai->GetAnimStack_2(this: ai);
      idAnimator_Base::End(this: &ai->walkIK, stack: v19, curTime: v18, blendDurationMS: 200, reset: false);
    }
  }
LABEL_18:
  idAI2::SetEnableHeadTracking(this: ai, enable: this->wasHeadTrackingEnabled);
  idAI2::SetSolid(this: ai, isSolid: this->wasSolid);
}


// ========================================================================
// __unwind$510585
// EA  : 0x82AA670C
// RVA : 0x00AA670C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_510585()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$510586
// EA  : 0x82AA6734
// RVA : 0x00AA6734
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_510586()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// ??0idAction_MoveToScenePoint@@QAA@XZ
// EA  : 0x82AA6760
// RVA : 0x00AA6760
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_MoveToScenePoint *__fastcall idAction_MoveToScenePoint::idAction_MoveToScenePoint(
        idAction_MoveToScenePoint *this)
{
  idState::idState(this, stateType: &idAction_MoveToScenePoint::Type, childFSMType: nullptr, flags: 3);
  this->stayTimeOut = -1;
  this->__vftable = (idAction_MoveToScenePoint_vtbl *)&idAction_MoveToScenePoint::`vftable';
  this->scenepointTarget.spawnId.value = 0x1FFF;
  this->mtspFlags = MTSP_NONE;
  this->isDone = false;
  return this;
}


// ========================================================================
// ?StartNextAction@idAIActionsQueue@@QAAXPAVidAI2@@H@Z
// EA  : 0x82AA67D8
// RVA : 0x00AA67D8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAIActionsQueue::StartNextAction(idAIActionsQueue *this, idAI2 *ai, int transCode)
{
  idAIActionManager *p_actionManager; // r30
  idList<idEventDef const *,92> *p_actionEvents; // r31
  idList<idEventArgs,92> *p_actionArgs; // r29
  const idEventDef **list; // r11
  int num; // r11
  int v10; // r11
  bool v11; // zf
  int v12; // r10
  const idEventDef **v13; // r9
  idEventReceiver v14[5]; // [sp+50h] [-40h] BYREF

  if ( this->actionEvents.num != 0 )
  {
    p_actionManager = &ai->aiVolatile.fsms.actionManager;
    idAI2::EndActionScript(this: ai);
    p_actionManager->actionEventTransCode = transCode;
    p_actionEvents = &this->actionEvents;
    list = this->actionEvents.list;
    p_actionArgs = &this->actionArgs;
    idEventReceiver::ProcessEventArgArray(
      this: v14,
      result: (idEventArg *)p_actionManager,
      ev: *list,
      numargs: (*list)->numargs,
      args: p_actionArgs->list->args.ptr);
    num = p_actionEvents->num;
    if ( num > 0 )
    {
      p_actionEvents->num = num - 1;
      v11 = num - 1 <= 0;
      v10 = 0;
      if ( !v11 )
      {
        v12 = 0;
        do
        {
          ++v10;
          v13 = &p_actionEvents->list[v12++];
          *v13 = v13[1];
        }
        while ( v10 < p_actionEvents->num );
      }
    }
    idList<idEventArgs,92>::RemoveIndex(this: p_actionArgs, index: 0);
  }
}


// ========================================================================
// ?StartQueuedActions@idAIActionFSM@@QAAXXZ
// EA  : 0x82AA6888
// RVA : 0x00AA6888
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAIActionFSM::StartQueuedActions(idAIActionFSM *this)
{
  idAI2 *AI; // r3
  idAI2 *v3; // r3

  AI = idAIFSM::GetAI(this);
  idAI2::EndActionScript(this: AI);
  v3 = idAIFSM::GetAI(this);
  idAIActionsQueue::StartNextAction(this: &this->actionsQueue, ai: v3, transCode: 7);
}


// ========================================================================
// ?GetActionStateForEvent@idAIActionManager@@QAAPAVidAIAction@@ABVidEventDef@@@Z
// EA  : 0x82AA68D0
// RVA : 0x00AA68D0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAIAction *__fastcall idAIActionManager::GetActionStateForEvent(idAIActionManager *this, const idEventDef *event)
{
  idAIAction **v4; // [sp+50h] [-20h] BYREF
  int v5[3]; // [sp+54h] [-1Ch] BYREF

  v5[0] = event->eventnum;
  v4 = nullptr;
  if ( (unsigned __int8)idHashTableT<int,idAIAction *>::Get(this: &this->actionsHash, key: v5, value: &v4) != 0 )
    return *v4;
  idLib::Warning(
    fmt: "idAIActionManager::GetActionStateForEvent() doesn't have an action state that handles %s event.",
    event->name);
  return nullptr;
}


// ========================================================================
// ?InternalCallEvent@idAIActionManager@@MAA?AVidEventArg@@ABVidEventDef@@PBV2@@Z
// EA  : 0x82AA6958
// RVA : 0x00AA6958
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAIActionManager *__fastcall idAIActionManager::InternalCallEvent(
        idAIActionManager *this,
        idAIActionManager *result,
        const idEventDef *event,
        const idEventArg *args)
{
  eventType_t type; // r5
  const char *EnumName; // r3
  idAIAction *ActionStateForEvent; // r29
  int GameMs; // r3
  idAIActionManager_vtbl **v13; // r10
  idAIActionManager *v14; // r9
  int i; // ctr
  char v16; // [sp+4Ch] [-54h] BYREF
  idEventReceiver v17[6]; // [sp+50h] [-50h] BYREF

  type = event->type;
  if ( type == EVENT_ACTION )
  {
    ActionStateForEvent = idAIActionManager::GetActionStateForEvent(this: result, event);
    if ( ActionStateForEvent != nullptr )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idFiniteStateMachine::SetCurrentState(
        this: &result->legsFSM,
        newState: ActionStateForEvent,
        fromTransType: nullptr,
        transCode: result->actionEventTransCode,
        curTime: GameMs);
      idEventReceiver::ProcessEventArgPtr(this: v17, result: (idEventArg *)ActionStateForEvent, ev: event, args);
      v13 = (idAIActionManager_vtbl **)&v16;
      result->actionEventTransCode = 0;
      v14 = (idAIActionManager *)((char *)this - 4);
      for ( i = 5; i != 0; --i )
      {
        ++v13;
        v14 = (idAIActionManager *)((char *)v14 + 4);
        v14->__vftable = *v13;
      }
      return this;
    }
    else
    {
      result->actionEventTransCode = 0;
      this->listenerList = nullptr;
      HIBYTE(this->__vftable) = 0;
      return this;
    }
  }
  else
  {
    EnumName = idTypeInfoTools::GetEnumName(
                 this: typeInfoTools,
                 enumTypeName: "eventType_t",
                 enumValue: type,
                 defaultValue: "<unknown>");
    idLib::Warning(fmt: "idAIActionManager::InternalCallEvent() doesn't handle %s event type.", EnumName);
    this->listenerList = nullptr;
    HIBYTE(this->__vftable) = 0;
    return this;
  }
}


// ========================================================================
// ?InternalRespondsTo@idAIActionManager@@MBA_NABVidEventDef@@@Z
// EA  : 0x82AA6A70
// RVA : 0x00AA6A70
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

BOOL __fastcall idAIActionManager::InternalRespondsTo(idAIActionManager *this, const idEventDef *event)
{
  return event->type == EVENT_ACTION && idAIActionManager::GetActionStateForEvent(this, event) != nullptr;
}


// ========================================================================
// ?StartIdleAnimationForMoveNoFail@@YAXPAVidAI2@@AAVidMoveNoFailStatus@@W4aiMoveStatus_t@@@Z
// EA  : 0x82AA6B08
// RVA : 0x00AA6B08
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall StartIdleAnimationForMoveNoFail(idAI2 *ai, idMoveNoFailStatus *moveNoFailStatus, int moveStatus)
{
  idAIMoveState *MoveInterface; // r3
  idObstacleInfo *v6; // r3
  idEntity *v7; // r3
  idEntity *v8; // r3
  idEntity *v9; // r29
  idStr v10[2]; // [sp+50h] [-50h] BYREF

  if ( moveNoFailStatus->successCount != 0 )
    moveNoFailStatus->successCount = 0;
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) == 0 )
  {
    v10[0].len = 0;
    v10[0].baseBuffer[0] = 0;
    v10[0].allocedAndFlag = 20;
    v10[0].data = v10[0].baseBuffer;
    idAI2::GetIdleStateName(this: ai, name: v10);
    idAI2::ChangeAnimState(
      this: ai,
      web: AIANIMWEB_BODY,
      subWeb: ai->aiVolatile.animation.subWeb,
      stateName: v10[0].data,
      interruptPath: INTR_PATH_YES,
      interruptBlend: INTR_BLEND_NO,
      subWebIndex: nullptr,
      stateIndex: nullptr);
    idStr::FreeData(this: v10);
  }
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
  {
    idAnimBaseFSM::ClearDestination(this: &ai->aiVolatile.animation.animFSM);
  }
  else
  {
    idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: moveStatus);
    ai->aiVolatile.physics.moveState.moveParms.flags &= ~1u;
  }
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v6 = MoveInterface->GetObstacleInfo_2(this: MoveInterface);
  if ( gameLocal->spawnIds.ptr[v6->firstObstacle.spawnId.value & 0x1FFF] == v6->firstObstacle.spawnId.value >> 13 )
  {
    v7 = gameLocal->entities.ptr[v6->firstObstacle.spawnId.value & 0x1FFF];
    if ( v7 != nullptr )
    {
      v8 = idEntity::CastTo(c: v7);
      v9 = v8;
      if ( v8 != nullptr
        && ((unsigned __int8)idAI2::IsTypeOf(c: v8) != 0 || (unsigned __int8)idPlayer::IsTypeOf(c: v9) != 0) )
      {
        idAI2::SetAimFocusEntity(
          this: ai,
          ent: v9,
          keepFocusInView: (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 4) != 0,
          aimPoint: AIMPOINT_EYELEVEL,
          timeout: -1);
      }
    }
  }
}


// ========================================================================
// __unwind$511624
// EA  : 0x82AA6C90
// RVA : 0x00AA6C90
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_511624()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?UpdateMoveNoFail@@YAXPAVidAI2@@PAVidState@@AAVidMoveNoFailStatus@@@Z
// EA  : 0x82AA6CB8
// RVA : 0x00AA6CB8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall UpdateMoveNoFail(_exception *ai, idState *state, idMoveNoFailStatus *moveNoFailStatus)
{
  int v5; // r29
  idAIMoveState *v6; // r30
  unsigned int v7; // r3
  int v8; // r29
  idMoveNoFailStatus::moveNoFailPhase_t v9; // r11
  char started; // r3
  int v11; // r3
  const idDeclVoiceOver *idleVo; // r5
  int arg2_high; // r27
  idMoveNoFailStatus::moveNoFailPhase_t v14; // r11
  char v15; // r3
  int v16; // r3
  int (*GetGameMs)(void); // ctr
  int v18; // r3
  int v19[16]; // [sp+50h] [-40h] BYREF

  state->tempUninterruptible = false;
  v5 = 8;
  v6 = (idAIMoveState *)((char *)&ai[190].arg2 + 4);
  if ( (unsigned int)(moveNoFailStatus->movePhase - 1) > 7 )
  {
    v14 = PHASE_BLOCKED_FORCE_WAIT;
    moveNoFailStatus->phaseTime = 0;
    goto LABEL_52;
  }
  if ( moveNoFailStatus->movePhase == PHASE_BLOCKED_FORCE_WAIT )
  {
    if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) >= moveNoFailStatus->phaseTime + 500 )
    {
      if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 )
      {
        idAnimBaseFSM::SetDestination(this: (idAnimBaseFSM *)&ai[545], cmd: &moveNoFailStatus->moveCmd);
      }
      else
      {
        idAIMoveState::SetMoveStatus(this: v6, status: 1);
        if ( idAIMoveState::StartMove(this: v6, parms: &moveNoFailStatus->moveParms) != 1 )
          goto LABEL_45;
      }
LABEL_19:
      v9 = PHASE_PLAY_VO_ON_FAILURE;
LABEL_20:
      moveNoFailStatus->movePhase = v9;
LABEL_21:
      if ( moveNoFailStatus->successCount == 4 )
      {
        idAI2::ClearAimFocus(this: (idAI2 *)ai);
        idAI2::ClearLookFocus(this: (idAI2 *)ai);
      }
      ++moveNoFailStatus->successCount;
      return;
    }
LABEL_53:
    StartIdleAnimationForMoveNoFail((idAI2 *)ai, moveNoFailStatus, moveStatus: v5);
    return;
  }
  if ( moveNoFailStatus->movePhase == PHASE_PLAY_VO_ON_FAILURE )
  {
    started = idLobbyBackend360::StartArbitration(pexcept: ai);
    if ( started != 0 )
      v11 = (*(int (__fastcall **)(long double *))HIDWORD(ai[545].arg2))(a1: &ai[545].arg2);
    else
      v11 = idAIMoveState::ContinueMove(this: v6, totalTravelTime: v19);
    v5 = v11;
    if ( v11 == 1 )
    {
      v9 = PHASE_WALKING;
      goto LABEL_20;
    }
    goto LABEL_45;
  }
  if ( moveNoFailStatus->movePhase != PHASE_START_VO )
  {
    switch ( moveNoFailStatus->movePhase )
    {
      case PHASE_PLAYING_VO:
        arg2_high = HIDWORD(ai[924].arg2);
        if ( arg2_high < gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
        {
          moveNoFailStatus->movePhase = PHASE_JUST_FINISHED_VO;
          moveNoFailStatus->phaseTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          StartIdleAnimationForMoveNoFail((idAI2 *)ai, moveNoFailStatus, moveStatus: 8);
          return;
        }
        goto LABEL_53;
      case PHASE_JUST_FINISHED_VO:
        if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) < moveNoFailStatus->phaseTime + 200 )
          goto LABEL_53;
        break;
      case PHASE_FINISHED_VO_START_MOVE:
        v15 = idLobbyBackend360::StartArbitration(pexcept: ai);
        if ( v15 != 0 )
        {
          idAnimBaseFSM::SetDestination(this: (idAnimBaseFSM *)&ai[545], cmd: &moveNoFailStatus->moveCmd);
          if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) < moveNoFailStatus->phaseTime + 5000 )
          {
            moveNoFailStatus->movePhase = PHASE_FINISHED_VO_CONTINUE_MOVE;
            goto LABEL_21;
          }
          goto LABEL_19;
        }
        idAIMoveState::SetMoveStatus(this: v6, status: 1);
        v16 = idAIMoveState::StartMove(this: v6, parms: &moveNoFailStatus->moveParms);
        GetGameMs = (int (*)(void))gameLocal->GetGameMs;
        if ( v16 == 1 )
        {
          if ( GetGameMs() < moveNoFailStatus->phaseTime + 5000 )
          {
            moveNoFailStatus->movePhase = PHASE_FINISHED_VO_CONTINUE_MOVE;
            goto LABEL_21;
          }
          goto LABEL_19;
        }
        if ( GetGameMs() >= moveNoFailStatus->phaseTime + 5000 )
        {
LABEL_45:
          v14 = PHASE_START_VO;
          goto LABEL_52;
        }
        goto LABEL_53;
      case PHASE_WALKING:
        if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 )
          v7 = (*(int (__fastcall **)(long double *))HIDWORD(ai[545].arg2))(a1: &ai[545].arg2);
        else
          v7 = idAIMoveState::ContinueMove(this: v6, totalTravelTime: v19);
        v8 = v7;
        if ( v7 >= 2 )
        {
          moveNoFailStatus->phaseTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          moveNoFailStatus->movePhase = PHASE_BLOCKED_FORCE_WAIT;
          StartIdleAnimationForMoveNoFail((idAI2 *)ai, moveNoFailStatus, moveStatus: v8);
          return;
        }
        goto LABEL_21;
      default:
        if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 )
          v18 = (*(int (__fastcall **)(long double *))HIDWORD(ai[545].arg2))(a1: &ai[545].arg2);
        else
          v18 = idAIMoveState::ContinueMove(this: v6, totalTravelTime: v19);
        v5 = v18;
        if ( v18 == 1 )
        {
          v9 = PHASE_WALKING;
          goto LABEL_20;
        }
        break;
    }
    v14 = PHASE_FINISHED_VO_START_MOVE;
LABEL_52:
    moveNoFailStatus->movePhase = v14;
    goto LABEL_53;
  }
  idleVo = moveNoFailStatus->idleVo;
  if ( idleVo != nullptr )
    idAIVoiceController::PlayVoiceOver(
      this: (idAIVoiceController *)&ai[924].arg2,
      (idAI2 *)ai,
      vo: idleVo,
      priority: AIVOICEPRIORITY_MED,
      samePriorityInterupts: true);
  moveNoFailStatus->movePhase = PHASE_PLAYING_VO;
  moveNoFailStatus->phaseTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  StartIdleAnimationForMoveNoFail((idAI2 *)ai, moveNoFailStatus, moveStatus: 8);
}


// ========================================================================
// ?UpdateMoveToPathPoint@@YAXPAVidAI2@@PAVidAction_MoveToPathPointNoFail@@@Z
// EA  : 0x82AA70E0
// RVA : 0x00AA70E0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall UpdateMoveToPathPoint(_exception *ai, idAction_MoveToPathPointNoFail *noFail)
{
  idAIMoveState *MoveInterface; // r3
  int v5; // r8
  idEntity *v6; // r3
  idInfoPath *v7; // r3
  idInfoPath *v8; // r31
  const idInfoPath *NextPath; // r30
  idEntity *Focus; // r3
  bool keepFocusInView; // r26
  const idEntity *v12; // r28
  const idEntity *v13; // r29
  int v14; // r30
  double v15; // fp31
  idPlayer *Player; // r3
  idPlayer *v17; // r31
  idPhysics *Physics; // r24
  idPhysics *v19; // r23
  float *v20; // r24
  float *v21; // r3
  double v22; // fp8
  double v23; // fp6
  idPhysics *v24; // r3
  float *v25; // r30
  idPhysics *v26; // r3
  float *v27; // r3
  double v28; // fp9
  int v29[6]; // [sp+50h] [-70h] BYREF

  if ( noFail != nullptr
    || (MoveInterface = idAI2::GetMoveInterface(this: (idAI2 *)ai),
        MoveInterface->GetMoveStatus(this: MoveInterface) == 1) )
  {
    v5 = DWORD2(ai[908].arg1);
    if ( gameLocal->spawnIds.ptr[v5 & 0x1FFF] == v5 >> 13 && (v6 = gameLocal->entities.ptr[v5 & 0x1FFF]) != nullptr )
      v7 = (idInfoPath *)idEntity::CastTo(c: v6);
    else
      v7 = nullptr;
    v8 = idInfoPath::CastTo(c: v7);
    if ( v8 != nullptr )
    {
      NextPath = idAIMemory::GetNextPath(this: (idAIMemory *)(&ai[906].name + 2));
      if ( noFail != nullptr )
      {
        UpdateMoveNoFail(ai, state: noFail, moveNoFailStatus: &noFail->moveNoFailStatus);
      }
      else if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) == 0 )
      {
        idAIMoveState::ContinueMove(this: (idAIMoveState *)((char *)&ai[190].arg2 + 4), totalTravelTime: v29);
      }
      Focus = (idEntity *)idInfoPath::GetFocus(this: v8);
      if ( Focus != nullptr )
      {
        keepFocusInView = v8->keepFocusInView;
        v12 = Focus;
        if ( (unsigned __int8)idPlayerStart::IsTypeOf(c: Focus) != 0 )
        {
          v13 = nullptr;
          v14 = 0;
          v15 = 1.0e30;
          do
          {
            Player = idGameLocal::GetPlayer(this: gameLocal, i: v14);
            v17 = Player;
            if ( Player != nullptr )
            {
              Physics = idEntity::GetPhysics(this: Player);
              v19 = idEntity::GetPhysics(this: (idEntity *)ai);
              v20 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
              v21 = (float *)v19->GetOrigin(this: v19, a2: 0);
              v22 = (float)(v21[1] - v20[1]);
              v23 = (float)(v21[2] - v20[2]);
              if ( (float)((float)((float)v23 * (float)v23)
                         + (float)((float)((float)v22 * (float)v22)
                                 + (float)((float)(*v21 - *v20) * (float)(*v21 - *v20)))) < v15 )
              {
                v15 = (float)((float)((float)v23 * (float)v23)
                            + (float)((float)((float)v22 * (float)v22)
                                    + (float)((float)(*v21 - *v20) * (float)(*v21 - *v20))));
                v13 = v17;
              }
            }
            ++v14;
          }
          while ( v14 < 6 );
          if ( v13 != nullptr )
            v12 = v13;
        }
        idAI2::SetLookFocusEntity(
          this: (idAI2 *)ai,
          ent: v12,
          keepFocusInView,
          aimPoint: AIMPOINT_EYELEVEL,
          timeout: -1);
      }
      else if ( NextPath != nullptr && v8->lookAtNextPoint )
      {
        v24 = idEntity::GetPhysics(this: (idEntity *)ai);
        v25 = (float *)v24->GetOrigin(this: v24, a2: 0);
        v26 = idEntity::GetPhysics(this: v8);
        v27 = (float *)v26->GetOrigin(this: v26, a2: 0);
        v28 = (float)(v25[1] - v27[1]);
        *(float *)&v29[2] = *v25 - *v27;
        *(float *)&v29[3] = v28;
        idAI2::UpdateBodyOrientationWhileMoving(this: (idAI2 *)ai);
        return;
      }
      idAI2::UpdateBodyOrientationWhileMoving(this: (idAI2 *)ai);
    }
  }
}


// ========================================================================
// ?Evaluate@ActionEntityDeleted@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AA7370
// RVA : 0x00AA7370
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall ActionEntityDeleted::Evaluate(
        ActionEntityDeleted *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v6; // r3

  value = ai->aiVolatile.memory.actionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v6) != nullptr )
  {
    return 0;
  }
  else
  {
    return 21;
  }
}


// ========================================================================
// ?AIAction_Work@idAction_MoveToPointNoFail@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AA7400
// RVA : 0x00AA7400
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_MoveToPointNoFail::AIAction_Work(
        idAction_MoveToPointNoFail *this,
        _exception *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idStr v7[2]; // [sp+50h] [-50h] BYREF

  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 )
  {
    UpdateMoveNoFail(ai, state: this, moveNoFailStatus: &this->moveNoFailStatus);
  }
  else
  {
    if ( (*(unsigned __int8 (__fastcall **)(char *))(DWORD1(ai[190].arg2) + 40))(a1: (char *)&ai[190].arg2 + 4) == 0 )
      UpdateMoveNoFail(ai, state: this, moveNoFailStatus: &this->moveNoFailStatus);
    if ( (*(int (__fastcall **)(char *))DWORD1(ai[190].arg2))(a1: (char *)&ai[190].arg2 + 4) == 1
      && fsm->stateFrame > 2
      && (*(int (__fastcall **)(_exception *))(ai->type + 800))(a1: ai) != this->lastWalkState )
    {
      v7[0].len = 0;
      v7[0].allocedAndFlag = 20;
      v7[0].data = v7[0].baseBuffer;
      v7[0].baseBuffer[0] = 0;
      idAI2::GetMovementStateName(this: (idAI2 *)ai, name: v7);
      idAI2::ChangeAnimState(
        this: (idAI2 *)ai,
        web: AIANIMWEB_BODY,
        subWeb: SDWORD1(ai[527].retval),
        stateName: v7[0].data,
        interruptPath: INTR_PATH_YES,
        interruptBlend: INTR_BLEND_NO,
        subWebIndex: nullptr,
        stateIndex: nullptr);
      this->lastWalkState = (*(int (__fastcall **)(_exception *))(ai->type + 800))(a1: ai);
      idStr::FreeData(this: v7);
    }
  }
  idAI2::UpdateBodyOrientationWhileMoving(this: (idAI2 *)ai);
}


// ========================================================================
// __unwind$511977
// EA  : 0x82AA7544
// RVA : 0x00AA7544
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_511977()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?AIAction_Work@idAction_MoveToEntityNoFail@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AA7578
// RVA : 0x00AA7578
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_MoveToEntityNoFail::AIAction_Work(
        idAction_MoveToEntityNoFail *this,
        _exception *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idStr v7[2]; // [sp+60h] [-50h] BYREF

  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 )
  {
    UpdateMoveNoFail(ai, state: this, moveNoFailStatus: &this->moveNoFailStatus);
  }
  else
  {
    if ( (*(unsigned __int8 (__fastcall **)(char *))(DWORD1(ai[190].arg2) + 40))(a1: (char *)&ai[190].arg2 + 4) == 0 )
      UpdateMoveNoFail(ai, state: this, moveNoFailStatus: &this->moveNoFailStatus);
    if ( (*(int (__fastcall **)(char *))DWORD1(ai[190].arg2))(a1: (char *)&ai[190].arg2 + 4) == 1
      && fsm->stateFrame > 2
      && (*(int (__fastcall **)(_exception *))(ai->type + 800))(a1: ai) != this->lastWalkState )
    {
      v7[0].len = 0;
      v7[0].allocedAndFlag = 20;
      v7[0].data = v7[0].baseBuffer;
      v7[0].baseBuffer[0] = 0;
      idAI2::GetMovementStateName(this: (idAI2 *)ai, name: v7);
      idAI2::ChangeAnimState(
        this: (idAI2 *)ai,
        web: AIANIMWEB_BODY,
        subWeb: SDWORD1(ai[527].retval),
        stateName: v7[0].data,
        interruptPath: INTR_PATH_YES,
        interruptBlend: INTR_BLEND_NO,
        subWebIndex: nullptr,
        stateIndex: nullptr);
      this->lastWalkState = (*(int (__fastcall **)(_exception *))(ai->type + 800))(a1: ai);
      idStr::FreeData(this: v7);
    }
  }
  idAI2::UpdateBodyOrientationWhileMoving(this: (idAI2 *)ai);
}


// ========================================================================
// __unwind$512040
// EA  : 0x82AA76C0
// RVA : 0x00AA76C0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_512040()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?AIAction_Work@idAction_MoveToPathPoint@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AA76E8
// RVA : 0x00AA76E8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_MoveToPathPoint::AIAction_Work(
        idAction_MoveToPathPoint *this,
        _exception *ai,
        idAIFSM *fsm,
        const int curTime)
{
  UpdateMoveToPathPoint(ai, noFail: nullptr);
}


// ========================================================================
// ?AIAction_Work@idAction_MoveToPathPointNoFail@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AA76F8
// RVA : 0x00AA76F8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_MoveToPathPointNoFail::AIAction_Work(
        idAction_MoveToPathPointNoFail *this,
        _exception *ai,
        idAIFSM *fsm,
        const int curTime)
{
  UpdateMoveToPathPoint(ai, noFail: this);
}


// ========================================================================
// ?AIAction_Work@idAction_MoveToCover@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AA7710
// RVA : 0x00AA7710
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_MoveToCover::AIAction_Work(
        idAction_MoveToCover *this,
        _exception *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAIMoveState *v6; // r21
  const aiPhysicalState_t *RelevantGoalOrigin; // r3
  float x; // r8
  float y; // r7
  float z; // r6
  char v11; // r20
  char v12; // r24
  double v13; // fp24
  char v14; // r27
  idPhysics *Physics; // r3
  float *v16; // r3
  double v17; // fp30
  double v18; // fp29
  double v19; // fp28
  double v20; // fp31
  bool ShouldScramble; // r28
  double CoverTransitionRadius; // fp1
  double v23; // fp25
  double v24; // fp1
  char v25; // r22
  const aas2Cover_t *Origin; // r3
  float v27; // r8
  float v28; // r7
  const idVec3 *(__fastcall *GetNextPoint)(struct idAIMoveState *); // r6
  float *v30; // r3
  idObstacleInfo *v31; // r3
  int v32; // r4
  idObstacleInfo *(__fastcall *GetObstacleInfo_2)(struct idAIMoveState *); // ctr
  idAIMoveState *v34; // r3
  float *p_x; // r9
  _DWORD *v36; // r3
  idColor *v37; // r9
  float r; // r8
  float b; // r6
  float a; // r5
  idRenderWorld *v41; // r24
  idRenderWorld_vtbl *v42; // r28
  const aas2Cover_t *v43; // r3
  idRenderWorld *v44; // r24
  idRenderWorld_vtbl *v45; // r28
  const aas2Cover_t *v46; // r3
  idPhysics *v47; // r29
  idRenderWorld *v48; // r28
  idPhysics *v49; // r3
  char *data; // r24
  idRenderWorld_vtbl *v51; // r29
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v53; // r3
  idPhysics *v54; // r29
  idRenderWorld *v55; // r28
  float *v56; // r3
  double v57; // fp7
  double v58; // fp6
  idVec3 *wallCorners; // r3
  idPhysics *v60; // r28
  idRenderWorld *v61; // r24
  idRenderWorld_vtbl *v62; // r29
  int v63; // r15
  int v64; // r3
  idObstacleInfo *v65; // r3
  idRenderWorld *v66; // r28
  idRenderWorld_vtbl *v67; // r29
  int v68; // r24
  int v69; // r5
  idColor *v70; // r4
  float *v71; // r6
  idPhysics *v72; // r29
  idPhysics *v73; // r3
  const idVec3 *(__fastcall *v74)(idPhysics *, int); // ctr
  double v75; // fp30
  idAIOrientation *BodyOrientation; // r3
  long double v77; // fp4
  double v78; // fp12
  double v79; // fp11
  long double v80; // fp2
  long double v81; // fp2
  idPhysics *v82; // r29
  idPhysics *v83; // r28
  __int64 v84; // r8
  double v85; // fp29
  float *v86; // r3
  double v87; // fp29
  double v88; // fp28
  float *v89; // r3
  double v90; // fp2
  double v91; // fp1
  double v92; // fp0
  const char *v93; // r29
  idPhysics *v94; // r27
  idAIOrientation *v95; // r3
  idPhysics_vtbl *v96; // r10
  double v97; // fp30
  double v98; // fp29
  double v99; // fp28
  float *v100; // r3
  double v101; // fp7
  double v102; // fp5
  idPhysics *v103; // r3
  double v104; // fp30
  double v105; // fp29
  double v106; // fp28
  float *v107; // r3
  double v108; // fp8
  double v109; // fp6
  idPhysics *v110; // r3
  double v111; // fp30
  double v112; // fp29
  double v113; // fp31
  float *v114; // r3
  double v115; // fp13
  double v116; // fp11
  idPhysics *v117; // r29
  idRenderWorld *v118; // r27
  idPhysics *v119; // r3
  idRenderWorld_vtbl *v120; // r29
  const idVec3 *(__fastcall *v121)(idPhysics *, int); // ctr
  int v122; // r3
  idPhysics *v123; // r29
  idRenderWorld *v124; // r27
  idPhysics *v125; // r3
  idRenderWorld_vtbl *v126; // r29
  const idVec3 *(__fastcall *v127)(idPhysics *, int); // ctr
  int v128; // r3
  idPhysics *v129; // r29
  idRenderWorld *v130; // r27
  idPhysics *v131; // r3
  idRenderWorld_vtbl *v132; // r29
  const idVec3 *(__fastcall *v133)(idPhysics *, int); // ctr
  int v134; // r3
  idRenderWorld *v135; // r29
  idPhysics *v136; // r3
  int v137; // r27
  idPhysics *v138; // r3
  float *v139; // r3
  __int64 v140; // r10
  __int64 v141; // r8
  va *v142; // r3
  idPhysics *v143; // r3
  float *v144; // r3
  double valueFloat; // fp31
  int v146; // r3
  int v147; // r6
  int v148; // r5
  idPhysics *v149; // r3
  float *v150; // r3
  int v151; // [sp+8h] [-1248h]
  int v152; // [sp+Ch] [-1244h]
  int v153; // [sp+10h] [-1240h]
  int v154; // [sp+14h] [-123Ch]
  int v155; // [sp+18h] [-1238h]
  int v156; // [sp+1Ch] [-1234h]
  idVec3 v157; // [sp+60h] [-11F0h] BYREF
  float v158; // [sp+70h] [-11E0h] BYREF
  float v159; // [sp+74h] [-11DCh]
  float v160; // [sp+78h] [-11D8h]
  float v161; // [sp+7Ch] [-11D4h] BYREF
  int v162[2]; // [sp+80h] [-11D0h] BYREF
  idVec3 v163; // [sp+88h] [-11C8h] BYREF
  idVec3 v164[2]; // [sp+98h] [-11B8h] BYREF
  idMat3 v165; // [sp+B0h] [-11A0h] BYREF
  idStr v166; // [sp+E0h] [-1170h] BYREF
  idMat3 v167; // [sp+100h] [-1150h] BYREF
  float v168; // [sp+124h] [-112Ch]
  float v169; // [sp+128h] [-1128h]
  float v170[4]; // [sp+130h] [-1120h] BYREF
  float v171[4]; // [sp+140h] [-1110h] BYREF
  idColor v172; // [sp+150h] [-1100h] BYREF
  int v173; // [sp+160h] [-10F0h] BYREF
  va v174; // [sp+170h] [-10E0h] BYREF

  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 )
    return;
  v6 = (idAIMoveState *)((char *)&ai[190].arg2 + 4);
  if ( (*(int (__fastcall **)(char *))DWORD1(ai[190].arg2))(a1: (char *)&ai[190].arg2 + 4) != 1 )
    return;
  RelevantGoalOrigin = idAIMoveParms::GetRelevantGoalOrigin(this: (idAIMoveParms *)&ai[190].retval, (const idAI2 *)ai);
  x = RelevantGoalOrigin->origin.x;
  y = RelevantGoalOrigin->origin.y;
  z = RelevantGoalOrigin->origin.z;
  v11 = 0;
  v166.allocedAndFlag = 20;
  v12 = 0;
  v161 = 0.0;
  v13 = 0.0;
  v14 = 0;
  v166.data = v166.baseBuffer;
  v166.len = 0;
  v166.baseBuffer[0] = 0;
  v157.x = x;
  v157.y = y;
  v157.z = z;
  Physics = idEntity::GetPhysics(this: (idEntity *)ai);
  v16 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v17 = (float)(v157.z - v16[2]);
  v18 = (float)(v157.y - v16[1]);
  v19 = (float)(v157.x - *v16);
  v163.x = v157.x - *v16;
  v163.z = v17;
  v20 = 0.0;
  v163.y = v18;
  if ( ai_useTransitions.valueInteger != 0
    && ai_useCoverTransitions.valueInteger != 0
    && __fabs(v17) <= 48.0
    && (DWORD1(ai[191].retval) & 4) != 0
    && (*(int (__fastcall **)(_exception *))(ai->type + 784))(a1: ai) == 1
    && !v6->IsPlayingTraversalAnim(this: (idAIMoveState *)((char *)&ai[190].arg2 + 4))
    && (unsigned __int8)idAICover::IsValid(this: (idAICover *)((char *)&ai[909].arg1 + 4)) != 0
    && HIDWORD(ai[206].arg2) == 0 )
  {
    v162[0] = 0;
    ShouldScramble = idAI2::ShouldScramble(this: (idAI2 *)ai);
    CoverTransitionRadius = idAI2::GetCoverTransitionRadius(
                              this: (idAI2 *)ai,
                              cover: (idAICover *)((char *)&ai[909].arg1 + 4),
                              desireScramble: ShouldScramble,
                              desireMicro: false,
                              outAnimName: &v166,
                              outYaw: &v161,
                              outDelta: v164,
                              outFrames: v162);
    v20 = CoverTransitionRadius;
    v23 = CoverTransitionRadius;
    if ( ai_forceMicrotransitions.valueInteger != 0
      || CoverTransitionRadius < 0.0
      || (float)((float)((float)v17 * (float)v17)
               + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) < (double)(float)((float)CoverTransitionRadius * (float)CoverTransitionRadius) )
    {
      v12 = 1;
      if ( ShouldScramble )
      {
        v24 = idAI2::GetCoverTransitionRadius(
                this: (idAI2 *)ai,
                cover: (idAICover *)((char *)&ai[909].arg1 + 4),
                desireScramble: false,
                desireMicro: false,
                outAnimName: &v166,
                outYaw: &v161,
                outDelta: v164,
                outFrames: v162);
        v20 = v24;
        if ( v24 > 0.0
          && (float)((float)((float)v17 * (float)v17)
                   + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) > (double)(float)((float)v24 * (float)v24) )
        {
          ShouldScramble = false;
        }
      }
      if ( ai_forceMicrotransitions.valueInteger != 0
        || v20 < 0.0
        || (float)((float)((float)v17 * (float)v17)
                 + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) < (double)(float)((float)v20 * (float)v20) )
      {
        v20 = idAI2::GetCoverTransitionRadius(
                this: (idAI2 *)ai,
                cover: (idAICover *)((char *)&ai[909].arg1 + 4),
                desireScramble: false,
                desireMicro: true,
                outAnimName: &v166,
                outYaw: &v161,
                outDelta: v164,
                outFrames: v162);
        v14 = 1;
        ShouldScramble = false;
      }
    }
    v25 = 0;
    Origin = idAICover::GetOrigin(this: (idAICover *)((char *)&ai[909].arg1 + 4));
    v27 = Origin->origin.y;
    v28 = Origin->origin.z;
    GetNextPoint = v6->GetNextPoint;
    v158 = Origin->origin.x;
    v159 = v27;
    v160 = v28;
    v30 = (float *)GetNextPoint(this: (struct idAIMoveState *)((char *)&ai[190].arg2 + 4));
    if ( (float)((float)((float)(v30[2] - v160) * (float)(v30[2] - v160))
               + (float)((float)((float)(*v30 - v158) * (float)(*v30 - v158))
                       + (float)((float)(v30[1] - v159) * (float)(v30[1] - v159)))) < 1.0 )
      goto LABEL_28;
    v31 = v6->GetObstacleInfo_2(this: (idAIMoveState *)((char *)&ai[190].arg2 + 4));
    v32 = LODWORD(v31->wallCorners[1].z) | LODWORD(v31->wallCorners[1].y) | LODWORD(v31->wallCorners[1].x);
    GetObstacleInfo_2 = v6->GetObstacleInfo_2;
    v34 = (idAIMoveState *)((char *)&ai[190].arg2 + 4);
    if ( (v32 & 0x7FFFFFFF) != 0 )
    {
      p_x = &GetObstacleInfo_2(this: v34)->wallCorners[1].x;
    }
    else
    {
      v36 = (_DWORD *)GetObstacleInfo_2(this: v34);
      if ( ((v36[17] | v36[16] | v36[15]) & 0x7FFFFFFF) == 0 )
        goto LABEL_29;
      p_x = &v6->GetObstacleInfo_2(this: (idAIMoveState *)((char *)&ai[190].arg2 + 4))->wallCorners[0].x;
    }
    if ( (float)((float)((float)(p_x[2] - v160) * (float)(p_x[2] - v160))
               + (float)((float)((float)(*p_x - v158) * (float)(*p_x - v158))
                       + (float)((float)(p_x[1] - v159) * (float)(p_x[1] - v159)))) < 16.0 )
LABEL_28:
      v25 = 1;
LABEL_29:
    if ( ai_debugCoverTransitions.valueInteger == 0 || ai_debugLevel.valueInteger <= 0 )
      goto LABEL_46;
    v172 = idColor::colorGreen;
    if ( ShouldScramble )
    {
      v37 = &idColor::colorOrange;
      r = idColor::colorOrange.r;
    }
    else
    {
      if ( v14 == 0 )
      {
LABEL_36:
        if ( v12 != 0 )
        {
          v41 = gameLocal->GetRenderWorld(this: gameLocal);
          v42 = v41->__vftable;
          v43 = idAICover::GetOrigin(this: (idAICover *)((char *)&ai[909].arg1 + 4));
          ((void (__fastcall *)(idRenderWorld *, idColor *, const aas2Cover_t *, idVec3 *, double))v42->DebugCircle)(
            a1: v41,
            a2: &idColor::colorRed,
            a3: v43,
            a4: &vec3_up,
            a5: v23);
        }
        v44 = gameLocal->GetRenderWorld(this: gameLocal);
        v45 = v44->__vftable;
        v46 = idAICover::GetOrigin(this: (idAICover *)((char *)&ai[909].arg1 + 4));
        ((void (__fastcall *)(idRenderWorld *, idColor *, const aas2Cover_t *, idVec3 *, double))v45->DebugCircle)(
          a1: v44,
          a2: &v172,
          a3: v46,
          a4: &vec3_up,
          a5: v20);
        v47 = idEntity::GetPhysics(this: (idEntity *)ai);
        v48 = gameLocal->GetRenderWorld(this: gameLocal);
        v49 = v47;
        data = v166.data;
        GetOrigin = v47->GetOrigin;
        v51 = v48->__vftable;
        v53 = (int)GetOrigin(this: v49, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v51->DebugText)(
          a1: v48,
          a2: data,
          a3: v53,
          a4: v51->DebugText,
          a5: &v172,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.2);
        if ( ai_debugCoverTransitions.valueInteger < 2 )
          goto LABEL_46;
        if ( v25 != 0 )
        {
          v72 = idEntity::GetPhysics(this: (idEntity *)ai);
          v66 = gameLocal->GetRenderWorld(this: gameLocal);
          v73 = v72;
          v74 = v72->GetOrigin;
          v67 = v66->__vftable;
          v69 = (int)v74(this: v73, a2: 0);
          v70 = &idColor::colorGreen;
          v71 = &v158;
        }
        else
        {
          v54 = idEntity::GetPhysics(this: (idEntity *)ai);
          v55 = gameLocal->GetRenderWorld(this: gameLocal);
          v56 = (float *)v54->GetOrigin(this: v54, a2: 0);
          v57 = (float)(v56[1] + v159);
          v58 = (float)(v158 + *v56);
          v171[2] = (float)(v56[2] + v160) * (float)0.5;
          v171[1] = (float)v57 * (float)0.5;
          v171[0] = (float)v58 * (float)0.5;
          ((void (__fastcall *)(idRenderWorld *, const char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))v55->DebugText)(
            a1: v55,
            a2: "too many corners",
            a3: v171,
            a4: v55->DebugText,
            a5: &idColor::colorRed,
            a6: 1,
            a7: 1000,
            a8: 0,
            a9: 0.2);
          wallCorners = v6->GetObstacleInfo_2(this: (idAIMoveState *)((char *)&ai[190].arg2 + 4))->wallCorners;
          if ( ((LODWORD(wallCorners->z) | LODWORD(wallCorners->y) | LODWORD(wallCorners->x)) & 0x7FFFFFFF) != 0 )
          {
            v60 = idEntity::GetPhysics(this: (idEntity *)ai);
            v61 = gameLocal->GetRenderWorld(this: gameLocal);
            v62 = v61->__vftable;
            v63 = (int)v6->GetObstacleInfo_2(this: (idAIMoveState *)((char *)&ai[190].arg2 + 4))->wallCorners;
            v64 = (int)v60->GetOrigin(this: v60, a2: 0);
            ((void (__fastcall *)(idRenderWorld *, idColor *, int, int, double))v62->DebugArrow)(
              a1: v61,
              a2: &idColor::colorRed,
              a3: v64,
              a4: v63,
              a5: 0.80000001);
          }
          v65 = v6->GetObstacleInfo_2(this: (idAIMoveState *)((char *)&ai[190].arg2 + 4));
          if ( ((LODWORD(v65->wallCorners[1].z) | LODWORD(v65->wallCorners[1].y) | LODWORD(v65->wallCorners[1].x))
              & 0x7FFFFFFF) == 0 )
            goto LABEL_46;
          v66 = gameLocal->GetRenderWorld(this: gameLocal);
          v67 = v66->__vftable;
          v68 = (int)&v6->GetObstacleInfo_2(this: (idAIMoveState *)((char *)&ai[190].arg2 + 4))->wallCorners[1];
          v69 = (int)v6->GetObstacleInfo_2(this: (idAIMoveState *)((char *)&ai[190].arg2 + 4))->wallCorners;
          v70 = &idColor::colorRed;
          v71 = (float *)v68;
        }
        ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))v67->DebugArrow)(
          a1: v66,
          a2: v70,
          a3: v69,
          a4: v71,
          a5: 0.80000001);
LABEL_46:
        if ( __fsqrts((float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) > 1.0 && v25 != 0 )
        {
          v75 = idVec3::NormalizeFast(this: &v163);
          BodyOrientation = idAI2::GetBodyOrientation(this: (idAI2 *)ai);
          *(double *)&v80 = v163.y;
          v78 = (float)(BodyOrientation->axis.mat[0].y * v163.y);
          v79 = BodyOrientation->axis.mat[0].z;
          *((double *)&v80 + 1) = v163.x;
          LODWORD(v163.x) = &BodyOrientation->axis;
          if ( (float)((float)(BodyOrientation->axis.mat[0].x * (float)*((double *)&v80 + 1))
                     + (float)((float)((float)v79 * v163.z) + (float)v78)) > 0.0 )
          {
            v81 = atan2(v: v80, u: v77);
            v13 = -(float)*(double *)&v81;
            v82 = idEntity::GetPhysics(this: (idEntity *)ai);
            v83 = idEntity::GetPhysics(this: (idEntity *)ai);
            LODWORD(v84) = gameLocal->GetGameHz(this: gameLocal, a2: GAMETIME_SCALED);
            HIDWORD(v84) = v82->__vftable;
            *(_QWORD *)&v163.x = v84;
            v85 = (float)v84;
            v86 = (float *)(*(int (__fastcall **)(int *, idPhysics *, _DWORD))(HIDWORD(v84) + 88))(
                             a1: &v173,
                             a2: v82,
                             a3: 0);
            v88 = (float)((float)((float)1.0 / (float)v85) * *v86);
            v87 = (float)(v86[1] * (float)((float)1.0 / (float)v85));
            v89 = (float *)v83->GetOrigin(this: v83, a2: 0);
            v90 = (float)(v157.y - (float)(v89[1] + (float)v87));
            v91 = (float)(v157.x - (float)((float)v88 + *v89));
            v92 = __fsqrts((float)((float)((float)v91 * (float)v91) + (float)((float)v90 * (float)v90)));
            if ( v75 > v20 && v92 < v20 )
            {
              v11 = 1;
              HIDWORD(ai[206].arg2) = v162[0];
            }
          }
        }
        goto LABEL_52;
      }
      v37 = &idColor::colorBlue;
      r = idColor::colorBlue.r;
    }
    b = v37->b;
    a = v37->a;
    v172.g = v37->g;
    v172.r = r;
    v172.b = b;
    v172.a = a;
    goto LABEL_36;
  }
LABEL_52:
  if ( v11 != 0 )
  {
    v93 = "$weaponfcover:idle";
    if ( idAICover::GetCoverPosture(this: (idAICover *)((char *)&ai[909].arg1 + 4)) == 2 )
    {
      (*(void (__fastcall **)(_exception *, int))(ai->type + 788))(a1: ai, a2: 2);
      v93 = "$weaponfcover:idle_crouch";
    }
    v94 = idEntity::GetPhysics(this: (idEntity *)ai);
    v95 = idAI2::GetBodyOrientation(this: (idAI2 *)ai);
    v96 = v94->__vftable;
    LODWORD(v163.x) = &v95->axis;
    v97 = (float)(v95->axis.mat[0].z * (float)v20);
    v98 = (float)(v95->axis.mat[0].y * (float)v20);
    v99 = (float)(v95->axis.mat[0].x * (float)v20);
    v100 = (float *)v96->GetOrigin(this: v94, a2: 0);
    v101 = (float)(v100[2] + (float)v97);
    v102 = (float)(v100[1] + (float)v98);
    v167.mat[1].y = (float)v99 + *v100;
    v167.mat[0].x = 0.0;
    v167.mat[0].z = 0.0;
    v167.mat[2].x = v101;
    v167.mat[1].z = v102;
    v167.mat[0].y = (float)-(float)((float)v13 + v161) * idMath::M_RAD2DEG;
    idAngles::ToMat3(this: (idAngles *)&v165, result: &v167);
    idAI2::SetAxis(this: (idAI2 *)ai, axis: &v165);
    idAI2::WaitForTraversal(
      this: (idAI2 *)ai,
      priority: PRIORITY_LOW,
      traversalAnimRef: v166.data,
      destAnimRef: v93,
      ev: ANIMWEB_EVENT_START_BLEND_IN);
    if ( ai_debugCoverTransitions.valueInteger != 0 && ai_debugLevel.valueInteger > 0 )
    {
      v103 = idEntity::GetPhysics(this: (idEntity *)ai);
      v104 = (float)((float)(v165.mat[0].z * v164[0].x)
                   + (float)((float)(v165.mat[1].z * v164[0].y) + (float)(v165.mat[2].z * v164[0].z)));
      v105 = (float)((float)(v165.mat[0].y * v164[0].x)
                   + (float)((float)(v165.mat[1].y * v164[0].y) + (float)(v165.mat[2].y * v164[0].z)));
      v106 = (float)((float)(v165.mat[0].x * v164[0].x)
                   + (float)((float)(v165.mat[1].x * v164[0].y) + (float)(v165.mat[2].x * v164[0].z)));
      v107 = (float *)v103->GetOrigin(this: v103, a2: 0);
      v108 = (float)(v107[2] + (float)v104);
      v109 = (float)(v107[1] + (float)v105);
      v170[0] = (float)v106 + *v107;
      v170[2] = v108;
      v170[1] = v109;
      v110 = idEntity::GetPhysics(this: (idEntity *)ai);
      v111 = (float)(v165.mat[0].z * (float)v20);
      v112 = (float)(v165.mat[0].y * (float)v20);
      v113 = (float)(v165.mat[0].x * (float)v20);
      v114 = (float *)v110->GetOrigin(this: v110, a2: 0);
      v115 = (float)(v114[2] + (float)v111);
      v116 = (float)(v114[1] + (float)v112);
      v167.mat[2].z = *v114 + (float)v113;
      v169 = v115;
      v168 = v116;
      v117 = idEntity::GetPhysics(this: (idEntity *)ai);
      v118 = gameLocal->GetRenderWorld(this: gameLocal);
      v119 = v117;
      v121 = v117->GetOrigin;
      v120 = v118->__vftable;
      v122 = (int)v121(this: v119, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))v120->DebugArrow)(
        a1: v118,
        a2: &idColor::colorGreen,
        a3: v122,
        a4: v170,
        a5: 0.5);
      v123 = idEntity::GetPhysics(this: (idEntity *)ai);
      v124 = gameLocal->GetRenderWorld(this: gameLocal);
      v125 = v123;
      v127 = v123->GetOrigin;
      v126 = v124->__vftable;
      v128 = (int)v127(this: v125, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))v126->DebugArrow)(
        a1: v124,
        a2: &idColor::colorYellow,
        a3: v128,
        a4: &v167.mat[2].z,
        a5: 0.80000001);
      v129 = idEntity::GetPhysics(this: (idEntity *)ai);
      v130 = gameLocal->GetRenderWorld(this: gameLocal);
      v131 = v129;
      v133 = v129->GetOrigin;
      v132 = v130->__vftable;
      v134 = (int)v133(this: v131, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))v132->DebugArrow)(
        a1: v130,
        a2: &idColor::colorWhite,
        a3: v134,
        a4: &v167.mat[1].y,
        a5: 0.5);
    }
  }
  else if ( !v6->IsPlayingTraversalAnim(this: (idAIMoveState *)((char *)&ai[190].arg2 + 4))
         && HIDWORD(ai[206].arg2) == 0 )
  {
    this->tempUninterruptible = false;
    idAIMoveState::ContinueMove(this: (idAIMoveState *)((char *)&ai[190].arg2 + 4), totalTravelTime: (int *)&v163);
  }
  idAI2::UpdateBodyOrientationWhileMoving(this: (idAI2 *)ai);
  if ( SHIDWORD(ai[206].arg2) > 0 )
  {
    if ( ai_debugLevel.valueInteger != 0 && ai_debugCoverTransitions.valueInteger != 0 )
    {
      v135 = gameLocal->GetRenderWorld(this: gameLocal);
      v136 = idEntity::GetPhysics(this: (idEntity *)ai);
      v137 = (int)v136->GetOrigin(this: v136, a2: 0);
      v138 = idEntity::GetPhysics(this: (idEntity *)ai);
      v139 = (float *)v138->GetOrigin(this: v138, a2: 0);
      LODWORD(v140) = "1 - formation cover, such as behind regime shield units";
      v142 = va::va(
               this: &v174,
               fmt: "%d:%.1f",
               a3: COERCE__INT64(__fsqrts((float)((float)((float)(v139[2] - v157.z) * (float)(v139[2] - v157.z))
                                            + (float)((float)((float)(*v139 - v157.x) * (float)(*v139 - v157.x))
                                                    + (float)((float)(v139[1] - v157.y) * (float)(v139[1] - v157.y)))))),
               a4: v141,
               a5: v140,
               a6: v151,
               a7: v152,
               a8: v153,
               a9: v154,
               a10: v155,
               a11: v156);
      ((void (__fastcall *)(idRenderWorld *, va *, int, idRenderWorld_vtbl *, idColor *, int, int, _DWORD, double))v135->DebugText)(
        a1: v135,
        a2: v142,
        a3: v137,
        a4: v135->__vftable,
        a5: &idColor::colorWhite,
        a6: 1,
        a7: 3000,
        a8: 0,
        a9: 0.029999999);
    }
    if ( SHIDWORD(ai[206].arg2) < 5 )
    {
      v143 = idEntity::GetPhysics(this: (idEntity *)ai);
      v144 = (float *)v143->GetOrigin(this: v143, a2: 0);
      valueFloat = ai_coverLerpRadius.valueFloat;
      if ( (float)((float)((float)(v144[2] - v157.z) * (float)(v144[2] - v157.z))
                 + (float)((float)((float)(*v144 - v157.x) * (float)(*v144 - v157.x))
                         + (float)((float)(v144[1] - v157.y) * (float)(v144[1] - v157.y)))) < (double)(float)(ai_coverLerpRadius.valueFloat * ai_coverLerpRadius.valueFloat) )
      {
        v146 = GameFramesToTicks(frameNum: HIDWORD(ai[206].arg2), type: GAMETIME_SCALED);
        idAIMoveState::StartLerpToPoint(
          this: (idAIMoveState *)((char *)&ai[190].arg2 + 4),
          dest: &v157,
          tolerance: 0.1,
          maxLerpDist: valueFloat,
          lerpDurationMS: v148,
          lerpAxisFlags_: v147,
          a7: v146,
          a8: 3);
      }
      if ( HIDWORD(ai[206].arg2) == 1 )
      {
        v149 = idEntity::GetPhysics(this: (idEntity *)ai);
        v150 = (float *)v149->GetOrigin(this: v149, a2: 0);
        if ( (float)((float)((float)(v150[2] - v157.z) * (float)(v150[2] - v157.z))
                   + (float)((float)((float)(*v150 - v157.x) * (float)(*v150 - v157.x))
                           + (float)((float)(v150[1] - v157.y) * (float)(v150[1] - v157.y)))) < (double)(float)(ai_coverSnapRadius.valueFloat * ai_coverSnapRadius.valueFloat) )
          idEntity::SetOrigin(this: (idEntity *)ai, org: &v157);
      }
    }
    --HIDWORD(ai[206].arg2);
  }
  idStr::FreeData(this: &v166);
}


// ========================================================================
// __unwind$512126
// EA  : 0x82AA8700
// RVA : 0x00AA8700
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_512126()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4688 + 224));
}


// ========================================================================
// ?AIAction_Work@idAction_Idle@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AA8730
// RVA : 0x00AA8730
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_Idle::AIAction_Work(idAction_Idle *this, idAI2 *ai, idAIFSM *fsm, const int curTime)
{
  aiIdleTurn_t idleTurnType; // r10
  double minRange; // fp31
  idPhysics *Physics; // r3
  const idVec3 *v9; // r29
  double v10; // fp30
  idAIOrientation *BodyOrientation; // r3
  const idDeclAIBehavior *decl; // r11
  aiIdleTurn_t num; // r9
  const idDeclAITurnParms **list; // r9
  const idDeclAITurnParms *v15; // r24
  idAI2::idAIVolatile::idAIFocusInfo *p_focus; // r21
  double maxAngle; // fp0
  double value; // fp31
  idAIOrientation *v19; // r19
  idPhysics *v20; // r3
  float *v21; // r3
  float v22; // r5
  float v23; // r4
  double z; // fp12
  float v25; // r3
  double y; // fp10
  double x; // fp8
  turnDirection_t v28; // r23
  int GameMs; // r3
  idAI2 *v30; // r4
  idAIOrientation *v31; // r3
  bool v32; // zf
  const idDeclAITurnParms *v33; // r5
  const idMD6Anim *AnimForAnimWebNodeIndex; // r3
  idMD6AnimData *animData; // r11
  int numFrames; // r27
  signed int frameRate; // r29
  int v38; // r3
  int v39; // r11
  int v40; // r27
  idEntity *Neutral; // r3
  idPhysics *v42; // r29
  __int64 v43; // r11
  __int64 v44; // r8
  double v45; // fp30
  float *v46; // r3
  double v47; // fp3
  double v48; // fp1
  double v49; // fp0
  double v50; // fp8
  double v51; // fp7
  double v52; // fp6
  float v53; // r29
  const idDeclAITurnParms *v54; // r5
  float *v55; // [sp+8h] [-1A8h]
  float *v56; // [sp+8h] [-1A8h]
  turnDirection_t *v57; // [sp+Ch] [-1A4h]
  turnDirection_t *v58; // [sp+Ch] [-1A4h]
  int v59; // [sp+10h] [-1A0h]
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v60; // [sp+10h] [-1A0h]
  int v61; // [sp+14h] [-19Ch]
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v62; // [sp+14h] [-19Ch]
  int v63; // [sp+18h] [-198h]
  int v64; // [sp+18h] [-198h]
  int v65; // [sp+1Ch] [-194h]
  int v66; // [sp+1Ch] [-194h]
  int v67; // [sp+20h] [-190h]
  int v68; // [sp+20h] [-190h]
  int v69; // [sp+24h] [-18Ch]
  int v70; // [sp+24h] [-18Ch]
  int v71; // [sp+28h] [-188h]
  int v72; // [sp+28h] [-188h]
  int v73; // [sp+2Ch] [-184h]
  int v74; // [sp+2Ch] [-184h]
  int v75; // [sp+30h] [-180h]
  int v76; // [sp+30h] [-180h]
  int v77; // [sp+34h] [-17Ch]
  int v78; // [sp+34h] [-17Ch]
  int v79; // [sp+38h] [-178h]
  int v80; // [sp+38h] [-178h]
  int v81; // [sp+3Ch] [-174h]
  int v82; // [sp+3Ch] [-174h]
  int v83; // [sp+40h] [-170h]
  int v84; // [sp+40h] [-170h]
  int v85; // [sp+44h] [-16Ch]
  int v86; // [sp+44h] [-16Ch]
  int v87; // [sp+48h] [-168h]
  int v88; // [sp+48h] [-168h]
  int v89; // [sp+4Ch] [-164h]
  int v90; // [sp+4Ch] [-164h]
  int v91; // [sp+50h] [-160h]
  int v92; // [sp+50h] [-160h]
  int v93; // [sp+58h] [-158h]
  int v94; // [sp+58h] [-158h]
  int v95; // [sp+60h] [-150h]
  int v96; // [sp+68h] [-148h]
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v97; // [sp+70h] [-140h] BYREF
  unsigned __int16 v98; // [sp+72h] [-13Eh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v99; // [sp+74h] [-13Ch] BYREF
  unsigned __int16 v100; // [sp+76h] [-13Ah] BYREF
  __int64 v101; // [sp+78h] [-138h] BYREF
  float v102[2]; // [sp+80h] [-130h] BYREF
  idTypesafeNumber<float,enum RadiansUnique_t> v103; // [sp+88h] [-128h] BYREF
  float v104; // [sp+8Ch] [-124h] BYREF
  idVec3 v105; // [sp+90h] [-120h] BYREF
  idVec3 v106; // [sp+A0h] [-110h] BYREF
  idVec3 v107; // [sp+B0h] [-100h] BYREF
  float v108[4]; // [sp+C0h] [-F0h] BYREF
  idStr v109; // [sp+D0h] [-E0h] BYREF
  idStr v110; // [sp+F0h] [-C0h] BYREF

  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) == 0 )
  {
    idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
    idleTurnType = this->idleTurnType;
    if ( idleTurnType == AIIDLETURN_INCOVER )
    {
      minRange = ai->aiConstants.movement.bodyTurnRate.minRange;
      Physics = idEntity::GetPhysics(this: ai);
      v9 = Physics->GetGravityNormal(this: Physics);
      v10 = (float)((float)__SPAIR64__(
                             &unk_82390000,
                             gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED))
                  * (float)0.001);
      BodyOrientation = idAI2::GetBodyOrientation(this: ai);
      idAIOrientation::UpdateAxis(this: BodyOrientation, normal: v9, turnRate: minRange, timeSeconds: v10);
      return;
    }
    if ( idleTurnType >= AIIDLETURN_RELAXED )
    {
      decl = ai->aiEditable.behaviors.decl;
      num = decl->turnParms.num;
      LODWORD(v102[0]) = decl;
      if ( idleTurnType < num )
      {
        list = decl->turnParms.list;
        LODWORD(v102[0]) = decl;
        v15 = list[idleTurnType];
        if ( v15 != nullptr
          && v15->turnToFocus
          && v15->allowTurns
          && !ai->aiEditable.movement.suppressBodyRotation
          && ai->aiVolatile.focus.enableBodyRotation
          && (ai->GetPosture(this: ai) != POSTURE_CROUCHED || v15->allowCrouchedTurns)
          && (ai->GetPosture(this: ai) != POSTURE_SITTING || v15->allowSittingTurns) )
        {
          if ( this->isTurning && idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) )
            this->isTurning = false;
          if ( !this->isTurning )
          {
            p_focus = &ai->aiVolatile.focus;
            if ( (unsigned __int8)idFocusInfo::HasFocus(this: ai->aiVolatile.focus.foci.ptr) == 0 )
              p_focus = (idAI2::idAIVolatile::idAIFocusInfo *)&ai->aiVolatile.focus.foci.ptr[1];
            if ( (unsigned __int8)idFocusInfo::HasFocus(this: p_focus->foci.ptr) != 0 )
            {
              maxAngle = v15->maxAngle;
              value = p_focus->foci.ptr[0].aimTracker.maxYaw.value;
              LODWORD(v102[0]) = &p_focus->foci.ptr[0].aimTracker;
              if ( maxAngle >= 0.0 )
                value = maxAngle;
              v19 = idAI2::GetBodyOrientation(this: ai);
              ai->GetEyePos(this: ai, a2: (idVec3 *)v108);
              v20 = idEntity::GetPhysics(this: ai);
              v21 = (float *)v20->GetOrigin(this: v20, a2: 0);
              v22 = v21[1];
              v23 = *v21;
              z = v19->axis.mat[2].z;
              v25 = v21[2];
              y = v19->axis.mat[2].y;
              v105.y = v22;
              v105.x = v23;
              v105.z = v25;
              x = v19->axis.mat[2].x;
              v103.value = value;
              LODWORD(v102[0]) = &v19->axis.mat[2];
              v105.z = v25
                     + (float)((float)((float)x * (float)(v108[0] - v23))
                             + (float)((float)((float)y * (float)(v108[1] - v22))
                                     + (float)((float)z * (float)(v108[2] - v25))));
              CalcTurnParameters(
                ai,
                focusPoint: &p_focus->foci.ptr[0].idealFocusPoint,
                eyePos: &v105,
                curAxis: &v19->axis,
                maxAngle: &v103,
                turnParms: v15,
                idealDir: &v106,
                idealDot: &v104,
                turnAngle: v55,
                turnDir: v57,
                a11: v59,
                a12: v61,
                a13: v63,
                a14: v65,
                a15: v67,
                a16: v69,
                a17: v71,
                a18: v73,
                a19: v75,
                a20: v77,
                a21: v79,
                a22: v81,
                a23: v83,
                a24: v85,
                a25: v87,
                a26: v89,
                a27: v91,
                a28: v102,
                a29: v93,
                a30: (int *)&v101);
              v28 = HIDWORD(v101);
              if ( HIDWORD(v101) == 0
                || ai->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType == ANIMWEBAI_RUNINDEXTYPE_DUCK )
              {
                v30 = ai;
                v31 = v19;
              }
              else
              {
                if ( this->turnTime < 0 && v15->turnDelay > 0 )
                  this->turnTime = idGameTimeManager::GetGameMs(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED)
                                 + v15->turnDelay;
                GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                v30 = ai;
                v32 = this->turnTime >= GameMs;
                v31 = v19;
                if ( !v32 )
                {
                  idAIOrientation::SetIdealDir(this: v19, ai, dir: &v106);
                  v109.len = 0;
                  v109.allocedAndFlag = 20;
                  v109.data = v109.baseBuffer;
                  v109.baseBuffer[0] = 0;
                  idAI2::GetIdleTurnStateName(
                    this: ai,
                    turnDir: v28,
                    turnDeltaDot: v104,
                    turnParms: v33,
                    name: (idStr *)v15,
                    a6: &v109);
                  if ( v15->predictTurns && idAIMemory::GetNeutral(this: p_focus->foci.ptr) != nullptr )
                  {
                    v97.value = -1;
                    v99.value = -1;
                    GetSubWebAndStateIndices(
                      ai,
                      subweb: (const aiSubWeb_t)ai->aiVolatile.animation.subWeb,
                      stateName: v109.data,
                      swi: &v97,
                      si: &v99);
                    LODWORD(v101) = (int)ai->aiVolatile.animation.animWebAnimator.ptr[0].idleIndex;
                    AnimForAnimWebNodeIndex = idAI2::GetAnimForAnimWebNodeIndex(
                                                this: ai,
                                                swi: &v97,
                                                si: &v99,
                                                index: v101);
                    if ( AnimForAnimWebNodeIndex != nullptr )
                    {
                      animData = AnimForAnimWebNodeIndex->animData;
                      numFrames = 0;
                      if ( animData != nullptr )
                      {
                        numFrames = animData->numFrames;
                        frameRate = animData->frameRate;
                      }
                      else
                      {
                        frameRate = 30;
                      }
                      v38 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
                      v39 = __ROL4__(v38 * numFrames, 1);
                      v40 = v38 * numFrames / frameRate;
                      __twllei(frameRate, 0);
                      __twlgei(frameRate & ~(v39 - 1), 0xFFFFFFFF);
                      Neutral = (idEntity *)idAIMemory::GetNeutral(this: p_focus->foci.ptr);
                      v42 = idEntity::GetPhysics(this: Neutral);
                      if ( v42 != nullptr )
                      {
                        LODWORD(v43) = v40;
                        v101 = v43;
                        LODWORD(v44) = gameLocal->GetGameMsPerRealSec(this: gameLocal);
                        HIDWORD(v44) = v42->__vftable;
                        v45 = (float)((float)v101 / (float)v44);
                        v101 = v44;
                        v46 = (float *)(*(int (__fastcall **)(idVec3 *, idPhysics *, _DWORD))(HIDWORD(v44) + 88))(
                                         a1: &v107,
                                         a2: v42,
                                         a3: 0);
                        v47 = (float)(v46[2] * (float)v45);
                        v48 = (float)(v46[1] * (float)v45);
                        v49 = (float)((float)v45 * *v46);
                        v50 = p_focus->foci.ptr[0].idealFocusPoint.z;
                        v51 = p_focus->foci.ptr[0].idealFocusPoint.y;
                        v52 = p_focus->foci.ptr[0].idealFocusPoint.x;
                        *(float *)&v101 = value;
                        LODWORD(v103.value) = (idTypesafeNumber<float,enum RadiansUnique_t>)&p_focus->foci.ptr[0].idealFocusPoint;
                        v107.z = (float)v50 + (float)v47;
                        v107.y = (float)v51 + (float)v48;
                        v107.x = (float)v52 + (float)v49;
                        CalcTurnParameters(
                          ai,
                          focusPoint: &v107,
                          eyePos: &v105,
                          curAxis: &v19->axis,
                          maxAngle: (const idTypesafeNumber<float,enum RadiansUnique_t> *)&v101,
                          turnParms: v15,
                          idealDir: &v106,
                          idealDot: &v104,
                          turnAngle: v56,
                          turnDir: v58,
                          a11: (int)v60,
                          a12: (int)v62,
                          a13: v64,
                          a14: v66,
                          a15: v68,
                          a16: v70,
                          a17: v72,
                          a18: v74,
                          a19: v76,
                          a20: v78,
                          a21: v80,
                          a22: v82,
                          a23: v84,
                          a24: v86,
                          a25: v88,
                          a26: v90,
                          a27: v92,
                          a28: v102,
                          a29: v94,
                          a30: (int *)&v103);
                        v53 = v103.value;
                        if ( LODWORD(v103.value) != v28 )
                        {
                          idAIOrientation::SetIdealDir(this: v19, ai, dir: &v106);
                          v28 = LODWORD(v53);
                          idAI2::GetIdleTurnStateName(
                            this: ai,
                            turnDir: SLODWORD(v53),
                            turnDeltaDot: v104,
                            turnParms: v54,
                            name: (idStr *)v15,
                            a6: &v109);
                        }
                      }
                    }
                  }
                  if ( v28 != TURN_NONE )
                  {
                    v110.allocedAndFlag = 20;
                    v110.len = 0;
                    v110.data = v110.baseBuffer;
                    v110.baseBuffer[0] = 0;
                    idAI2::GetIdleStateName(this: ai, name: &v110);
                    v100 = -1;
                    v98 = -1;
                    v102[0] = *(float *)&ai->aiVolatile.animation.subWeb;
                    if ( idAI2::ChangeAnimStateVia(
                           this: ai,
                           web: AIANIMWEB_BODY,
                           subWeb: SLODWORD(v102[0]),
                           stateName: v110.data,
                           viaSubWeb: SLODWORD(v102[0]),
                           viaStateName: v109.data,
                           interruptPath: INTR_PATH_YES,
                           interruptBlend: INTR_BLEND_NO,
                           subWebIndex: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v56,
                           stateIndex: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v58,
                           viaSubWebIndex: v60,
                           viaStateIndex: v62,
                           a13: v64,
                           a14: v66,
                           a15: v68,
                           a16: v70,
                           a17: v72,
                           a18: v74,
                           a19: v76,
                           a20: v78,
                           a21: v80,
                           a22: v82,
                           a23: v84,
                           a24: v86,
                           a25: v88,
                           a26: v90,
                           a27: v92,
                           a28: nullptr,
                           a29: v94,
                           a30: nullptr,
                           a31: v95,
                           a32: (__int16 *)&v100,
                           a33: v96,
                           a34: (__int16 *)&v98) == AWPATH_OK )
                    {
                      idAI2::SetAnimWebEvent(
                        this: ai,
                        web: AIANIMWEB_BODY,
                        priority: PRIORITY_LOW,
                        swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v100,
                        si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v98,
                        eventType: ANIMWEB_EVENT_END_BLEND_OUT,
                        eventDef: &EV_AnimWeb_Wait);
                      this->turnTime = -1;
                      this->isTurning = true;
                    }
                    idStr::FreeData(this: &v110);
                  }
                  idStr::FreeData(this: &v109);
                  return;
                }
              }
              idAIOrientation::SetIdealDir(this: v31, ai: v30, dir: &v106);
            }
          }
        }
      }
    }
  }
}


// ========================================================================
// __unwind$512864
// EA  : 0x82AA8DC4
// RVA : 0x00AA8DC4
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_512864()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 208));
}


// ========================================================================
// __unwind$512865
// EA  : 0x82AA8DEC
// RVA : 0x00AA8DEC
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_512865()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 240));
}


// ========================================================================
// ?Action_ReloadWeaponEnter@idAction_ReloadWeapon@@QAA?AVeventVoid@@PAVidEntity@@W4equipSlot_t@@PBVidDeclAmmo@@@Z
// EA  : 0x82AA8E20
// RVA : 0x00AA8E20
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ReloadWeapon *__fastcall idAction_ReloadWeapon::Action_ReloadWeaponEnter(
        idAction_ReloadWeapon *this,
        idState *result,
        idAI2 *entity,
        equipSlot_t slot,
        const idDeclAmmo *ammoDecl)
{
  idAI2 *v9; // r30
  idWeapon *EquippedWeapon; // r3
  const idWeapon *v11; // r26
  int v12; // r3
  int v13; // r3
  int GameMs; // r3
  int frameRate; // r11
  int v16; // r10
  int v17; // r5
  idAIFireControl *fireControl; // r3
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v20; // [sp+8h] [-108h]
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v21; // [sp+Ch] [-104h]
  int v22; // [sp+10h] [-100h]
  int v23; // [sp+14h] [-FCh]
  int v24; // [sp+18h] [-F8h]
  int v25; // [sp+1Ch] [-F4h]
  int v26; // [sp+20h] [-F0h]
  int v27; // [sp+24h] [-ECh]
  int v28; // [sp+28h] [-E8h]
  int v29; // [sp+2Ch] [-E4h]
  int v30; // [sp+30h] [-E0h]
  int v31; // [sp+34h] [-DCh]
  int v32; // [sp+38h] [-D8h]
  int v33; // [sp+3Ch] [-D4h]
  int v34; // [sp+40h] [-D0h]
  int v35; // [sp+44h] [-CCh]
  int v36; // [sp+48h] [-C8h]
  int v37; // [sp+4Ch] [-C4h]
  int v38; // [sp+50h] [-C0h]
  int v39; // [sp+58h] [-B8h]
  unsigned __int16 v40; // [sp+60h] [-B0h] BYREF
  unsigned __int16 v41; // [sp+62h] [-AEh] BYREF
  unsigned __int16 v42; // [sp+64h] [-ACh] BYREF
  __int16 v43; // [sp+66h] [-AAh] BYREF
  aiSubWeb_t subWeb; // [sp+68h] [-A8h]
  idAnimator_AnimWeb::animInfo_t v45; // [sp+70h] [-A0h] BYREF
  idStr v46; // [sp+80h] [-90h] BYREF
  idStr v47[3]; // [sp+A0h] [-70h] BYREF

  v9 = idAI2::CastTo(c: entity);
  idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v9->aiVolatile.focus.enableBodyRotation = false;
  v9->aiVolatile.memory.reloadSlot = slot;
  EquippedWeapon = idActor::GetEquippedWeapon(this: v9, slot);
  v11 = EquippedWeapon;
  if ( EquippedWeapon != nullptr )
  {
    idWeapon::BeginReloading(this: EquippedWeapon, ammoDecl, secondaryAmmo: false);
    v46.len = 0;
    v46.allocedAndFlag = 20;
    v46.data = v46.baseBuffer;
    v46.baseBuffer[0] = 0;
    idAI2::GetIdleStateName(this: v9, name: &v46);
    idDeclAnimWeb::GetStateIndexForName(
      this: (idDeclAnimWeb *)&v42,
      result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v9->aiVolatile.animation.animWebAnimator.ptr[0].decl,
      name: v46.data);
    idStr::idStr(this: v47, text: "reload_clip");
    v12 = v9->GetPosture(this: v9);
    idStr::Append(this: v47, text: (char *)postureAnimStateNames[v12]);
    idDeclAnimWeb::GetStateIndexForName(
      this: (idDeclAnimWeb *)&v40,
      result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v9->aiVolatile.animation.animWebAnimator.ptr[0].decl,
      name: v47[0].data);
    v43 = -1;
    v41 = -1;
    subWeb = v9->aiVolatile.animation.subWeb;
    v13 = idAI2::ChangeAnimStateVia(
            this: v9,
            web: AIANIMWEB_BODY,
            subWeb,
            stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v42,
            viaSubWeb: subWeb,
            viaStateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v40,
            interruptPath: INTR_PATH_YES,
            interruptBlend: INTR_BLEND_NO,
            subWebIndex: v20,
            viaSubWebIndex: v21,
            a11: v22,
            a12: v23,
            a13: v24,
            a14: v25,
            a15: v26,
            a16: v27,
            a17: v28,
            a18: v29,
            a19: v30,
            a20: v31,
            a21: v32,
            a22: v33,
            a23: v34,
            a24: v35,
            a25: v36,
            a26: v37,
            a27: v38,
            a28: &v43,
            a29: v39,
            a30: (__int16 *)&v41);
    if ( v13 < 1 )
    {
      idState::SetEnterFailed(this: result, failed: true);
    }
    else if ( v13 == 1 )
    {
      idAI2::SetAnimWebEvent(
        this: v9,
        web: AIANIMWEB_BODY,
        priority: PRIORITY_LOW,
        swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v41,
        si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v40,
        eventType: ANIMWEB_EVENT_START_BLEND_OUT,
        eventDef: &EV_AnimWeb_ReloadRightFinished);
      memset(&v45, 0, sizeof(v45));
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      if ( idAnimator_AnimWeb::GetNodeAnimLength(
             this: (idAnimator_AnimWeb *)&v9->aiVolatile.animation,
             curTime: GameMs,
             modelIndex: nullptr,
             swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v41,
             si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v40,
             wrapMode: WRAP_MAX,
             ignoreAdditive: false,
             animInfo: &v45) )
      {
        frameRate = v45.frameRate;
        v16 = __ROL4__(960 * v45.numFrames, 1);
        v17 = 960 * v45.numFrames / v45.frameRate;
        __twllei(v45.frameRate, 0);
        fireControl = v9->aiVolatile.fireControl;
        __twlgei(frameRate & ~(v16 - 1), 0xFFFFFFFF);
        idAIFireControl::InhibitFire(this: fireControl, weapon: v11, inhibitLength: v17);
      }
      idAIVoiceController::PlayVoice(this: &v9->aiVolatile.voiceController, ai: v9, msg: AIVOICE_COMBAT_RELOAD);
    }
    idStr::FreeData(this: v47);
    idStr::FreeData(this: &v46);
  }
  else
  {
    idState::SetEnterFailed(this: result, failed: true);
  }
  return this;
}


// ========================================================================
// __unwind$513272
// EA  : 0x82AA9080
// RVA : 0x00AA9080
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_513272()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 128));
}


// ========================================================================
// __unwind$513273
// EA  : 0x82AA90A8
// RVA : 0x00AA90A8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_513273()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 160));
}


// ========================================================================
// ?Action_LoopAnimEnter@idAction_LoopAnim@@QAA?AVeventVoid@@PAVidEntity@@ABVidAnimWebPath@@H@Z
// EA  : 0x82AA90D8
// RVA : 0x00AA90D8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_LoopAnim *__fastcall idAction_LoopAnim::Action_LoopAnimEnter(
        idAction_LoopAnim *this,
        idState *result,
        idAI2 *entity,
        const idAnimWebPath *animRef,
        const int waitTimeMS)
{
  idAI2 *v9; // r27
  idLegsFSM *ActionFSM; // r3
  idAIActionFSM *v11; // r29
  int v12; // r11
  unsigned int v13; // r25
  idDeclAnimWebNode **list; // r10
  idDeclAnimWebNode *v15; // r28
  const idDeclAnimWebNode::idModelInfo *ModelInfo; // r3
  idMD6AnimProps *v17; // r11
  unsigned __int16 v19; // [sp+50h] [-C0h] BYREF
  unsigned __int16 v20; // [sp+52h] [-BEh] BYREF
  __int16 v21; // [sp+54h] [-BCh] BYREF
  idStr v22; // [sp+60h] [-B0h] BYREF
  idStr v23; // [sp+80h] [-90h] BYREF
  idStr v24[3]; // [sp+A0h] [-70h] BYREF

  v9 = idAI2::CastTo(c: entity);
  ActionFSM = idAI2::GetActionFSM(this: v9);
  v11 = idAIActionFSM::CastTo(c: ActionFSM);
  v12 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) + waitTimeMS;
  if ( waitTimeMS < 0 )
    v12 = -1;
  v11->actionExpireTime = v12;
  v22.len = 0;
  v22.allocedAndFlag = 20;
  v22.data = v22.baseBuffer;
  v22.baseBuffer[0] = 0;
  v23.allocedAndFlag = 20;
  v23.data = v23.baseBuffer;
  v23.len = 0;
  v23.baseBuffer[0] = 0;
  idAI2::GetSubWebAndStateFromAnimWebPath(this: v9, animWebPath: animRef->data, subWebName: &v22, stateName: &v23);
  if ( v22.len == 0 )
  {
    idAI2::GetWeaponPrefix(this: v9, subWebPrefix: &v22);
    idStr::Append(this: &v22, text: "actionScript");
  }
  v13 = idAnimator_AnimWeb::ChangeState(
          this: (idAnimator_AnimWeb *)&v9->aiVolatile.animation,
          subWebName: v22.data,
          stateName: v23.data,
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_NO,
          blendEventMask_: 0);
  if ( v13 == 0 )
  {
    idLib::Warning(fmt: "ACTION_LOOP_ANIM: Failed to find path to animWeb node '%s:%s'", v22.data, v23.data);
    goto LABEL_17;
  }
  idDeclAnimWeb::GetSubWebIndexForName(
    this: (idDeclAnimWeb *)&v20,
    result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v9->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    subWebName: v22.data);
  idDeclAnimWeb::GetStateIndexForName(
    this: (idDeclAnimWeb *)&v19,
    result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v9->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    name: v23.data);
  idDeclAnimWeb::FindNodeIndex(
    this: (idDeclAnimWeb *)&v21,
    result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)v9->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v20,
    stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v19);
  if ( v21 == -1 )
  {
    v15 = nullptr;
LABEL_12:
    v17 = nullptr;
    goto LABEL_13;
  }
  list = v9->aiVolatile.animation.animWebAnimator.ptr[0].decl->nodes.list;
  v15 = list[v21];
  if ( v15 == nullptr )
    goto LABEL_12;
  ModelInfo = idDeclAnimWebNode::FindModelInfo(this: list[v21], modelIndex: nullptr);
  if ( ModelInfo == nullptr || ModelInfo->animProps.num <= 0 )
    goto LABEL_12;
  v17 = ModelInfo->animProps.list;
LABEL_13:
  if ( v17 != nullptr && v17->wrap != WRAP_REPEAT )
  {
    v24[0].allocedAndFlag = 20;
    v24[0].len = 0;
    v24[0].data = v24[0].baseBuffer;
    v24[0].baseBuffer[0] = 0;
    idDeclAnimWebNode::GetName(this: v15, web: v9->aiVolatile.animation.animWebAnimator.ptr[0].decl, name: v24);
    idLib::Warning(
      fmt: "ACTION_LOOP_ANIM: AI '%s', animWeb '%s', node '%s' is not set to WRAP_REPEAT",
      v9->name.data,
      v9->aiVolatile.animation.animWebAnimator.ptr[0].decl->name.str,
      v24[0].data);
    idStr::FreeData(this: v24);
  }
LABEL_17:
  idState::SetEnterFailed(this: result, failed: (_cntlzw(v13) & 0x20) != 0);
  idStr::FreeData(this: &v23);
  idStr::FreeData(this: &v22);
  return this;
}


// ========================================================================
// __unwind$513437
// EA  : 0x82AA9304
// RVA : 0x00AA9304
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_513437()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$513438
// EA  : 0x82AA932C
// RVA : 0x00AA932C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_513438()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 128));
}


// ========================================================================
// __unwind$513439
// EA  : 0x82AA9354
// RVA : 0x00AA9354
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_513439()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 160));
}


// ========================================================================
// ?Action_LoopAnimExitAtEndEnter@idAction_LoopAnimExitAtEnd@@QAA?AVeventVoid@@PAVidEntity@@ABVidAnimWebPath@@HH@Z
// EA  : 0x82AA9388
// RVA : 0x00AA9388
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_LoopAnimExitAtEnd *__fastcall idAction_LoopAnimExitAtEnd::Action_LoopAnimExitAtEndEnter(
        idAction_LoopAnimExitAtEnd *this,
        idState *result,
        idAI2 *entity,
        const idAnimWebPath *animRef,
        int waitTimeMS,
        int endFramesFromEnd)
{
  idAI2 *v10; // r29
  idLegsFSM *ActionFSM; // r3
  idAIActionFSM *v12; // r15
  int GameMs; // r3
  int *p_startAnimTime; // r19
  int *p_startingAnimFrameOn; // r18
  int v16; // r14
  char v17; // r21
  idAI2::idAIVolatile::idAIAnimationInfo *p_animation; // r27
  int v19; // r20
  idDeclAnimWebNode **list; // r10
  idDeclAnimWebNode *v21; // r24
  const idDeclAnimWebNode::idModelInfo *ModelInfo; // r3
  idMD6AnimProps *v23; // r11
  int v24; // r3
  int v25; // r11
  int nodeStartTime; // r29
  int nodeStartFrame; // r25
  int v29; // r3
  int v30; // r9
  idGameTimeManager *p_gameTimeManager; // r3
  int v32; // r27
  unsigned int v33; // r5
  idDeclAnimWeb v34; // [sp+50h] [-120h] BYREF

  v10 = idAI2::CastTo(c: entity);
  ActionFSM = idAI2::GetActionFSM(this: v10);
  v12 = idAIActionFSM::CastTo(c: ActionFSM);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  p_startAnimTime = &v10->aiVolatile.memory.loopAnimExitAtEnd.startAnimTime;
  p_startingAnimFrameOn = &v10->aiVolatile.memory.loopAnimExitAtEnd.startingAnimFrameOn;
  v10->aiVolatile.memory.loopAnimExitAtEnd.numFrames = 0;
  v10->aiVolatile.memory.loopAnimExitAtEnd.waitTimeMS = waitTimeMS;
  v16 = GameMs;
  v10->aiVolatile.memory.loopAnimExitAtEnd.endFramesFromEnd = endFramesFromEnd;
  v17 = 0;
  v10->aiVolatile.memory.loopAnimExitAtEnd.frameRate = 0;
  v10->aiVolatile.memory.loopAnimExitAtEnd.startAnimTime = 0;
  v10->aiVolatile.memory.loopAnimExitAtEnd.startingAnimFrameOn = 0;
  v34.textLength = 20;
  v34.textSource = (char *)&v34.md5Checksum;
  *((_DWORD *)&v34.idResource + 8) = 0;
  HIBYTE(v34.md5Checksum) = 0;
  v34.subWebs.list = (idDeclAnimWeb::idSubWebInfo *)20;
  *(_DWORD *)&v34.nodes.granularity = &v34.subWebs.num;
  v34.nodes.size = 0;
  HIBYTE(v34.subWebs.num) = 0;
  idAI2::GetSubWebAndStateFromAnimWebPath(
    this: v10,
    animWebPath: animRef->data,
    subWebName: (idStr *)&v34.idResource + 1,
    stateName: (idStr *)&v34.nodes.size);
  if ( *((_DWORD *)&v34.idResource + 8) == 0 )
  {
    idAI2::GetWeaponPrefix(this: v10, subWebPrefix: (idStr *)&v34.idResource + 1);
    idStr::Append(this: (idStr *)&v34.idResource + 1, text: "actionScript");
  }
  p_animation = &v10->aiVolatile.animation;
  v19 = idAnimator_AnimWeb::ChangeState(
          this: (idAnimator_AnimWeb *)&v10->aiVolatile.animation,
          subWebName: v34.textSource,
          stateName: *(const char **)&v34.nodes.granularity,
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_NO,
          blendEventMask_: 0);
  if ( v19 == 0 )
  {
    idLib::Warning(
      fmt: "ACTION_LOOP_ANIM_EXIT_AT_END: Failed to find path to animWeb node '%s:%s'",
      v34.textSource,
      *(const char **)&v34.nodes.granularity);
    idState::SetEnterFailed(this: result, failed: true);
    goto LABEL_23;
  }
  idDeclAnimWeb::GetSubWebIndexForName(
    this: (idDeclAnimWeb *)&v34.trackedMemory,
    result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v10->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    subWebName: v34.textSource);
  idDeclAnimWeb::GetStateIndexForName(
    this: (idDeclAnimWeb *)((char *)&v34.__vftable + 2),
    result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v10->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    name: *(const char **)&v34.nodes.granularity);
  idDeclAnimWeb::FindNodeIndex(
    this: &v34,
    result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)v10->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v34.trackedMemory),
    stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)LOWORD(v34.__vftable));
  if ( SHIWORD(v34.__vftable) == -1 )
  {
    v21 = nullptr;
LABEL_11:
    v23 = nullptr;
    goto LABEL_12;
  }
  list = v10->aiVolatile.animation.animWebAnimator.ptr[0].decl->nodes.list;
  v21 = list[SHIWORD(v34.__vftable)];
  if ( v21 == nullptr )
    goto LABEL_11;
  ModelInfo = idDeclAnimWebNode::FindModelInfo(this: list[SHIWORD(v34.__vftable)], modelIndex: nullptr);
  if ( ModelInfo == nullptr || ModelInfo->animProps.num <= 0 )
    goto LABEL_11;
  v23 = ModelInfo->animProps.list;
LABEL_12:
  if ( v23 != nullptr && v23->wrap != WRAP_REPEAT )
  {
    v34.models.list = (const idDeclMD6 **)20;
    v34.states.size = 0;
    *(_DWORD *)&v34.states.granularity = &v34.models.num;
    HIBYTE(v34.models.num) = 0;
    idDeclAnimWebNode::GetName(
      this: v21,
      web: v10->aiVolatile.animation.animWebAnimator.ptr[0].decl,
      name: (idStr *)&v34.states.size);
    idLib::Warning(
      fmt: "ACTION_LOOP_ANIM: AI '%s', animWeb '%s', node '%s' is not set to WRAP_REPEAT",
      v10->name.data,
      v10->aiVolatile.animation.animWebAnimator.ptr[0].decl->name.str,
      *(const char **)&v34.states.granularity);
    idStr::FreeData(this: (idStr *)&v34.states.size);
  }
  if ( waitTimeMS < 0 )
    goto LABEL_19;
  memset(&v34.name, 0, 12);
  v24 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( idAnimator_AnimWeb::GetNodeAnimLength(
         this: (idAnimator_AnimWeb *)&v10->aiVolatile.animation,
         curTime: v24,
         modelIndex: nullptr,
         nodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)HIWORD(v34.__vftable),
         wrapMode: WRAP_MAX,
         ignoreAdditive: false,
         animInfo: (idAnimator_AnimWeb::animInfo_t *)&v34.name) )
  {
    v10->aiVolatile.memory.loopAnimExitAtEnd.numFrames = (int)v34.nextOnHashChain;
    v10->aiVolatile.memory.loopAnimExitAtEnd.frameRate = (int)v34.resourceListPtr;
    if ( v19 == 1 )
    {
      idAI2::SetAnimWebEvent(
        this: v10,
        web: AIANIMWEB_BODY,
        priority: PRIORITY_LOW,
        swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v34.trackedMemory),
        si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)LOWORD(v34.__vftable),
        eventType: ANIMWEB_EVENT_START_BLEND_IN,
        eventDef: &EV_AnimWeb_BeginAnim);
    }
    else
    {
      nodeStartTime = v10->aiVolatile.animation.animWebAnimator.ptr[0].nodeStartTime;
      nodeStartFrame = p_animation->animWebAnimator.ptr[0].nodeStartFrame;
      if ( nodeStartTime <= 0 )
        nodeStartTime = 1;
      v29 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
      v30 = __ROL4__(v29 * (int)v34.nextOnHashChain, 1);
      v32 = v29 * (int)v34.nextOnHashChain / (int)v34.resourceListPtr;
      p_gameTimeManager = &clientGame->gameTimeManager;
      v33 = (int)v34.resourceListPtr & ~(v30 - 1);
      __twllei((unsigned int)v34.resourceListPtr, 0);
      __twlgei(v33, 0xFFFFFFFF);
      if ( idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED) >= v32 + nodeStartTime )
      {
        nodeStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        nodeStartFrame = 0;
      }
      *p_startAnimTime = nodeStartTime;
      *p_startingAnimFrameOn = nodeStartFrame;
    }
LABEL_19:
    v17 = 1;
  }
  idState::SetEnterFailed(this: result, failed: false);
  v25 = -1;
  if ( v17 == 0 )
    v25 = v16 + waitTimeMS;
  v12->actionExpireTime = v25;
LABEL_23:
  idStr::FreeData(this: (idStr *)&v34.nodes.size);
  idStr::FreeData(this: (idStr *)&v34.idResource + 1);
  return this;
}


// ========================================================================
// __unwind$513730
// EA  : 0x82AA9738
// RVA : 0x00AA9738
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_513730()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 112));
}


// ========================================================================
// __unwind$513731
// EA  : 0x82AA9760
// RVA : 0x00AA9760
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_513731()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 144));
}


// ========================================================================
// __unwind$513732
// EA  : 0x82AA9788
// RVA : 0x00AA9788
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_513732()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 176));
}


// ========================================================================
// ?Action_PlayInteractionVoiceOverEnter@idAction_PlayInteractionVoiceOver@@QAA?AVeventVoid@@PAVidEntity@@PBVidDeclVoiceOver@@PBV3@M_N@Z
// EA  : 0x82AA97B0
// RVA : 0x00AA97B0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_PlayInteractionVoiceOver *__fastcall idAction_PlayInteractionVoiceOver::Action_PlayInteractionVoiceOverEnter(
        idAction_PlayInteractionVoiceOver *this,
        idState *result,
        idAI2 *entity,
        const idDeclVoiceOver *vo,
        const idEntity *ent,
        double distance,
        const bool abort,
        eventVoid a8)
{
  idAI2 *v14; // r3
  idAI2 *v15; // r27
  const idDeclAIPlayerInteraction *decl; // r11
  double departureRadius; // fp0
  char v19; // r28
  int v20; // r9
  idEntity *v21; // r3
  idPhysics *Physics; // r3
  int v23; // r9
  idPhysics *v24; // r30
  idEntity *v25; // r3
  idEntity *v26; // r3
  idPhysics *v27; // r29
  float *v28; // r30
  float *v29; // r3
  double v30; // fp6
  double v31; // fp4

  v14 = idAI2::CastTo(c: entity);
  v15 = v14;
  if ( vo != nullptr )
  {
    if ( ent != nullptr )
      result[1].__vftable = (idState_vtbl *)((gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber);
    else
      result[1].__vftable = (idState_vtbl *)0x1FFF;
    *(float *)&result[1].listenerList = distance;
    if ( distance == 0.0 )
    {
      decl = v14->aiVolatile.aiPlayerInteraction.decl;
      if ( decl != nullptr )
        departureRadius = decl->departureRadius;
      else
        departureRadius = ai_playInteractionVoiceOver_defaultLeaveDistance.valueFloat;
      *(float *)&result[1].listenerList = departureRadius;
    }
    HIBYTE(result[1].listeningToList) = a8;
    v19 = 1;
    v20 = (int)result[1].__vftable;
    if ( gameLocal->spawnIds.ptr[v20 & 0x1FFF] != v20 >> 13 )
      goto LABEL_19;
    v21 = gameLocal->entities.ptr[v20 & 0x1FFF];
    if ( v21 == nullptr || idEntity::CastTo(c: v21) == nullptr )
      goto LABEL_19;
    Physics = idEntity::GetPhysics(this: v15);
    v23 = (int)result[1].__vftable;
    v24 = Physics;
    if ( gameLocal->spawnIds.ptr[v23 & 0x1FFF] == v23 >> 13 && (v25 = gameLocal->entities.ptr[v23 & 0x1FFF]) != nullptr )
      v26 = idEntity::CastTo(c: v25);
    else
      v26 = nullptr;
    v27 = idEntity::GetPhysics(this: v26);
    v28 = (float *)v24->GetOrigin(this: v24, a2: 0);
    v29 = (float *)v27->GetOrigin(this: v27, a2: 0);
    v30 = (float)(v29[2] - v28[2]);
    v31 = (float)(v29[1] - v28[1]);
    if ( (float)((float)((float)v31 * (float)v31)
               + (float)((float)((float)v30 * (float)v30) + (float)((float)(*v29 - *v28) * (float)(*v29 - *v28)))) > (double)(float)(*(float *)&result[1].listenerList * *(float *)&result[1].listenerList) )
LABEL_19:
      v19 = 0;
    if ( v19 != 0 )
    {
      idFaceMgr::SetEnableEyeTracking(this: &v15->aiVolatile.faceMgr, owner: v15, enable: true);
      idFaceMgr::SetEnableBlinking(this: &v15->aiVolatile.faceMgr, owner: v15, enable: true);
      idFaceMgr::SetEnableLidDeformation(this: &v15->aiVolatile.faceMgr, owner: v15, enable: true);
      idFaceMgr::SetEnableGestureAnimation(this: &v15->aiVolatile.faceMgr, owner: v15, enable: true);
      idFaceMgr::SetEnableMoodAnimation(this: &v15->aiVolatile.faceMgr, owner: v15, enable: true);
      idFaceMgr::SetEnableMoodAnimation(this: &v15->aiVolatile.faceMgr, owner: v15, enable: true);
      idAIVoiceController::PlayVoiceOver(
        this: &v15->aiVolatile.voiceController,
        ai: v15,
        vo,
        priority: AIVOICEPRIORITY_MED,
        samePriorityInterupts: true);
    }
    return this;
  }
  else
  {
    idState::SetEnterFailed(this: result, failed: true);
    return this;
  }
}


// ========================================================================
// ?Action_DrawWeaponEnter@idAction_DrawWeapon@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82AA9A40
// RVA : 0x00AA9A40
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_DrawWeapon *__fastcall idAction_DrawWeapon::Action_DrawWeaponEnter(
        idAction_DrawWeapon *this,
        idState *result,
        idAI2 *entity)
{
  idAI2 *v5; // r31
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r4
  idAIEntityState *v10; // r30
  const idWeapon *WeaponToDraw; // r28
  alertCycle_t AlertCycle; // r3
  aiSubWeb_t v13; // r29
  idPhysics *Physics; // r3
  aiSenseState_t *v15; // r30
  float *v16; // r26
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  double v18; // fp9
  double v19; // fp7
  idAnimWebAI *ptr; // r3
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v21; // [sp+50h] [-50h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v22; // [sp+52h] [-4Eh] BYREF
  idVec3 v23[6]; // [sp+58h] [-48h] BYREF

  v5 = idAI2::CastTo(c: entity);
  if ( (unsigned __int8)idAI2::IsWeaponEquipped(this: v5) == 0
    && ((value = v5->aiVolatile.memory.currentEnemy.spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13)
     || (v8 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
      ? (v9 = nullptr)
      : (v9 = idEntity::CastTo(c: v8)),
        (v10 = idAIWorldState::StateForEntity(this: &v5->aiVolatile.world.worldState, ent: v9)) != nullptr
     && (WeaponToDraw = idAI2::FindWeaponToDraw(this: v5)) != nullptr) )
  {
    AlertCycle = idAI2::GetAlertCycle(this: v5);
    v13 = idAI2::AlertCycleToSubWeb(this: v5, ac: AlertCycle);
    Physics = idEntity::GetPhysics(this: v5);
    v15 = v10->senses.ptr[v10->lastSense];
    v16 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v15);
    v18 = (float)(ConfirmedPhysicalSafe->origin.z - v16[2]);
    v19 = (float)(ConfirmedPhysicalSafe->origin.y - v16[1]);
    v23[0].x = ConfirmedPhysicalSafe->origin.x - *v16;
    v23[0].z = v18;
    v23[0].y = v19;
    idVec3::NormalizeFast(this: v23);
    ptr = v5->aiVolatile.animation.animWebAnimator.ptr;
    if ( v13 == AISUBWEB_SEARCH )
      idAnimWebAI::CalcToSearchTurn(this: ptr, desiredDir: v23);
    else
      idAnimWebAI::CalcToCombatTurn(this: ptr, desiredDir: v23);
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v5) != 0 )
      v5->aiVolatile.animation.animFSM.enableIdlePump = false;
    v22.value = -1;
    v21.value = -1;
    idAI2::FindAnimWebAndStateIndices(
      this: v5,
      web: AIANIMWEB_BODY,
      subWeb: v13,
      stateName: "idle",
      changeWeapon: true,
      newWeapon: WeaponToDraw,
      subWebIndex: &v22,
      stateIndex: &v21);
    if ( idAI2::ChangeAnimState(
           this: v5,
           web: AIANIMWEB_BODY,
           subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v22.value,
           stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v21.value,
           interruptPath: INTR_PATH_NO,
           interruptBlend: INTR_BLEND_NO) == 1 )
      idAI2::SetAnimWebEvent(
        this: v5,
        web: AIANIMWEB_BODY,
        priority: PRIORITY_LOW,
        swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v22.value,
        si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v21.value,
        eventType: ANIMWEB_EVENT_START_BLEND_IN,
        eventDef: &EV_AnimWeb_Wait);
    return this;
  }
  else
  {
    idState::SetEnterFailed(this: result, failed: true);
    return this;
  }
}


// ========================================================================
// ?Action_PerformCoverActionEnter@idAction_PerformCoverAction@@QAA?AVeventVoid@@PAVidEntity@@W4coverAction_t@@H@Z
// EA  : 0x82AA9C68
// RVA : 0x00AA9C68
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_PerformCoverAction *__fastcall idAction_PerformCoverAction::Action_PerformCoverActionEnter(
        idAction_PerformCoverAction *this,
        idState *result,
        idAI2 *entity,
        const coverAction_t coverAction,
        const int duration)
{
  idAI2 *v9; // r30
  int v10; // r4
  int v11; // r3
  int v12; // r3
  const idWeapon *v13; // r3
  const idWeapon *v14; // r28
  unsigned __int16 v16; // [sp+50h] [-90h] BYREF
  unsigned __int16 v17; // [sp+52h] [-8Eh] BYREF
  idStr v18; // [sp+60h] [-80h] BYREF
  idStr v19[3]; // [sp+80h] [-60h] BYREF

  v9 = idAI2::CastTo(c: entity);
  v9->aiVolatile.memory.endCoverActionTime = idGameTimeManager::GetGameMs(
                                               this: &clientGame->gameTimeManager,
                                               type: GAMETIME_SCALED)
                                           + duration;
  if ( coverAction == COVERACTION_FIRE_LEAN_LEFT )
  {
    v10 = 1;
  }
  else
  {
    v10 = 2;
    if ( coverAction != COVERACTION_FIRE_LEAN_RIGHT )
      v10 = 0;
  }
  v9->SetLeanState(this: v9, a2: (const leanState_t)v10);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v9) != 0 )
    v9->aiVolatile.animation.animFSM.enableIdlePump = false;
  v18.len = 0;
  v18.baseBuffer[0] = 0;
  v18.allocedAndFlag = 20;
  v18.data = v18.baseBuffer;
  idAI2::GetSubWebPrefix(this: v9, subWebPrefix: &v18);
  idDeclAnimWeb::GetSubWebIndexForName(
    this: (idDeclAnimWeb *)&v17,
    result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v9->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    subWebName: v18.data);
  idStr::idStr(this: v19, text: coverActionNames[coverAction]);
  v11 = v9->GetPosture(this: v9);
  idStr::Append(this: v19, text: (char *)postureAnimStateNames[v11]);
  idDeclAnimWeb::GetStateIndexForName(
    this: (idDeclAnimWeb *)&v16,
    result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v9->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    name: v19[0].data);
  v12 = idAnimator_AnimWeb::ChangeState(
          this: (idAnimator_AnimWeb *)&v9->aiVolatile.animation,
          subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v17,
          stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v16,
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_NO,
          blendEventMask_: 0);
  if ( v12 < 1 )
  {
    idState::SetEnterFailed(this: result, failed: true);
  }
  else if ( v12 == 1 )
  {
    if ( coverAction == COVERACTION_BLINDFIRE_LEFT
      || coverAction == COVERACTION_BLINDFIRE_RIGHT
      || coverAction == COVERACTION_BLINDFIRE_OVER )
    {
      idAI2::SetAnimWebEvent(
        this: v9,
        web: AIANIMWEB_BODY,
        priority: PRIORITY_LOW,
        swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v17,
        si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v16,
        eventType: ANIMWEB_EVENT_START_BLEND_OUT,
        eventDef: &EV_AnimWeb_Wait);
    }
    v13 = v9->GetEquippedWeapon(this: v9);
    v14 = v13;
    if ( coverAction == COVERACTION_BLINDFIRE_LEFT
      || coverAction == COVERACTION_BLINDFIRE_RIGHT
      || coverAction == COVERACTION_BLINDFIRE_OVER )
    {
      idAIFireControl::InhibitFire(this: v9->aiVolatile.fireControl, weapon: v13, inhibitLength: 3000);
    }
    else if ( coverAction == COVERACTION_PEEK_LEFT
           || coverAction == COVERACTION_PEEK_RIGHT
           || coverAction == COVERACTION_PEEK_OVER
           || coverAction == COVERACTION_HIDE )
    {
      idAIFireControl::InhibitFire(this: v9->aiVolatile.fireControl, weapon: v13, inhibitLength: 2000);
    }
    else
    {
      idAI2::SetAnimWebEvent(
        this: v9,
        web: AIANIMWEB_BODY,
        priority: PRIORITY_LOW,
        swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v17,
        si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v16,
        eventType: ANIMWEB_EVENT_END_BLEND_IN,
        eventDef: &EV_AnimWeb_EnableFireFromCover);
      idAIFireControl::InhibitFire(this: v9->aiVolatile.fireControl, weapon: v14, inhibitLength: 1000);
    }
  }
  idStr::FreeData(this: v19);
  idStr::FreeData(this: &v18);
  return this;
}


// ========================================================================
// __unwind$514460
// EA  : 0x82AA9EF8
// RVA : 0x00AA9EF8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_514460()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$514461
// EA  : 0x82AA9F20
// RVA : 0x00AA9F20
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_514461()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// ?Evaluate@InteractionTriggered@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AA9F48
// RVA : 0x00AA9F48
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

BOOL __fastcall InteractionTriggered::Evaluate(
        InteractionTriggered *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idGameLocal *v7; // r11
  int value; // r9
  idPlayer *v9; // r3
  idPlayer *DebugPlayer; // r31
  idPhysics *Physics; // r30
  idPhysics *v13; // r31
  float *v14; // r30
  float *v15; // r3
  double v16; // fp8
  double v17; // fp4

  v7 = gameLocal;
  value = ai->aiVolatile.memory.triggeredInteraction.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v9 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v9 != nullptr )
    {
      if ( idPlayer::CastTo(c: v9) != nullptr )
        return true;
      v7 = gameLocal;
    }
  }
  DebugPlayer = idGameLocal::GetDebugPlayer(this: v7);
  Physics = idEntity::GetPhysics(this: ai);
  v13 = idEntity::GetPhysics(this: DebugPlayer);
  v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v15 = (float *)v13->GetOrigin(this: v13, a2: 0);
  v16 = (float)(v15[2] - v14[2]);
  v17 = (float)(v15[1] - v14[1]);
  return (float)((float)((float)v17 * (float)v17)
               + (float)((float)((float)(*v15 - *v14) * (float)(*v15 - *v14)) + (float)((float)v16 * (float)v16))) > (double)(float)(*(float *)&state[1].__vftable * *(float *)&state[1].__vftable);
}


// ========================================================================
// ?StartNextState@idAction_ScriptedAnimWeb@@QAA_NPAVidAI2@@H@Z
// EA  : 0x82AAA070
// RVA : 0x00AAA070
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall idAction_ScriptedAnimWeb::StartNextState(idAction_ScriptedAnimWeb *this, idAI2 *ai, int newState)
{
  idAIScriptedAnimWeb::animState_t *stateInfo; // r11
  int v6; // r30
  idList<idAIScriptedAnimWeb::animWebState_t,5> *animWebStates; // r10
  const char *Classname; // r3
  idList<idAIScriptedAnimWeb::animWebState_t,5> *v9; // r10
  signed int num; // r29
  int v11; // r3
  idAIScriptedAnimWeb::animState_t *v12; // r3
  char v13; // r11
  int v14; // r3
  idAIScriptedAnimWeb::animState_t *v15; // r9
  int v16; // r24
  int v17; // r30
  int v18; // r27
  int v19; // r9
  idEntity *v20; // r3
  idEntity *v21; // r29
  idEventArg *v22; // r3
  const idEntity *Enemy; // r3
  int v24; // r3
  int v25; // r29
  int v26; // r29
  int stateStartTime; // r27
  idAnimStack *v28; // r3
  double v29; // fp1
  float y; // r5
  float z; // r4
  idQuat *p_nextTargetRotation; // r29
  float x; // r3
  idVec3 *p_nextTargetPosition; // r24
  float v35; // r11
  float w; // r9
  idEntity *v37; // r3
  idPhysics *Physics; // r3
  int v39; // r3
  idEntity *v40; // r3
  idPhysics *v41; // r3
  idQuat *v42; // r3
  idQuat *v43; // r3
  idDeclAnimWebNode *v44; // r11
  idDeclAnimWebNode::idModelInfo *list; // r27
  const idDeclMD6 *decl; // r4
  idMD6AnimProps *v47; // r3
  const idMD6Anim *v48; // r3
  idAIMoveState *p_moveState; // r3
  int v50; // r27
  const idAnimStack *v51; // r3
  char v52; // r11
  int v53; // r27
  const idAnimStack *v54; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v55; // r5
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v56; // r6
  double v57; // fp7
  double v58; // fp6
  idQuat *v59; // r3
  double v60; // fp0
  double v61; // fp13
  double v62; // fp11
  double v63; // fp1
  double v64; // fp9
  double v65; // fp10
  double v66; // fp7
  double v67; // fp8
  double v68; // fp9
  double v69; // fp8
  idQuat *v70; // r3
  double v71; // fp6
  double v72; // fp7
  double v73; // fp0
  double v74; // fp12
  double v75; // fp4
  double v76; // fp11
  double v77; // fp10
  double v78; // fp9
  idDeclAnimWeb v80; // [sp+50h] [-1A0h] BYREF
  idQuat v81[8]; // [sp+170h] [-80h] BYREF

  stateInfo = this->stateInfo;
  v6 = newState;
  if ( stateInfo == nullptr )
    return 0;
  animWebStates = stateInfo->animWebStates;
  v80.trackedMemory = (int)this->stateInfo;
  if ( animWebStates == nullptr )
  {
    Classname = idClass::GetClassname(this);
    idLib::Warning(fmt: "idAction_ScriptedAnimWeb '%s' referencing invalid stateInfo", Classname);
    return 0;
  }
  if ( newState == -3 )
    return 0;
  if ( newState == -2 )
  {
    v9 = stateInfo->animWebStates;
    v80.trackedMemory = (int)stateInfo;
    num = v9->num;
    v11 = idRandom2::RandomInt(this: &clientGame->random, max: num);
    v6 = v11;
    if ( this->currentScriptState == v11 )
    {
      __twllei(num, 0);
      v6 = (v11 + 1) % num;
      __twlgei(num & ~(__ROL4__(v11 + 1, 1) - 1), 0xFFFFFFFF);
    }
  }
  v12 = this->stateInfo;
  if ( v6 < 0 || (v13 = 1, v12->animWebStates->num <= v6) )
    v13 = 0;
  if ( v13 == 0 )
    return 0;
  idAIScriptedAnimWeb::animState_t::SetcurrentState(this: v12, state: v6);
  this->currentScriptState = v6;
  this->currentLoopCount = 0;
  v14 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v15 = this->stateInfo;
  this->stateStartTime = v14;
  v16 = 0;
  v17 = (int)&v15->animWebStates->list[this->currentScriptState];
  if ( *(int *)(v17 + 104) > 0 )
  {
    v18 = 0;
    do
    {
      v19 = *(_DWORD *)(*(_DWORD *)(v17 + 100) + v18);
      if ( gameLocal->spawnIds.ptr[v19 & 0x1FFF] == v19 >> 13 )
      {
        v20 = gameLocal->entities.ptr[v19 & 0x1FFF];
        if ( v20 != nullptr )
        {
          v21 = idEntity::CastTo(c: v20);
          if ( v21 != nullptr )
          {
            v22 = idEventArg::idEventArg(this: (idEventArg *)&v80.edges.size, data: ai);
            idEventReceiver::PostEventMS(
              this: v21,
              ev: &EV_Activate,
              time: *(_DWORD *)&v22->type,
              arg1: (const idEventArg *)LODWORD(v22->value.v[1]));
          }
        }
      }
      ++v16;
      v18 += 4;
    }
    while ( v16 < *(_DWORD *)(v17 + 104) );
  }
  *((_BYTE *)this + 84) = (*(_BYTE *)(v17 + 161) >> 2) & 0x20 | *((_BYTE *)this + 84) & 0xDF;
  idAI2::SetEnableHeadTracking(this: ai, enable: (*(_BYTE *)(v17 + 161) & 0x40) != 0);
  if ( (*(_BYTE *)(v17 + 161) & 0x40) != 0 )
  {
    Enemy = idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
    idAI2::SetAimFocusEntity(this: ai, ent: Enemy, keepFocusInView: false, aimPoint: AIMPOINT_HEAD, timeout: -1);
  }
  v80.nodeCache.size = 0;
  HIBYTE(v80.scalars.num) = 0;
  v80.scalars.list = (idAnimWebScalar *)20;
  *(_DWORD *)&v80.nodeCache.granularity = &v80.scalars.num;
  v80.layers.list = (idDeclAnimWeb::idLayerInfo *)20;
  *(_DWORD *)&v80.editorModels.granularity = &v80.layers.num;
  v80.editorModels.size = 0;
  HIBYTE(v80.layers.num) = 0;
  idAI2::GetSubWebAndStateFromAnimWebPath(
    this: ai,
    animWebPath: *(const char **)(v17 + 4),
    subWebName: (idStr *)&v80.nodeCache.size,
    stateName: (idStr *)&v80.editorModels.size);
  idDeclAnimWeb::GetSubWebIndexForName(
    this: (idDeclAnimWeb *)((char *)&v80.__vftable + 2),
    result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    subWebName: *(const char **)&v80.nodeCache.granularity);
  idDeclAnimWeb::GetStateIndexForName(
    this: &v80,
    result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    name: *(const char **)&v80.editorModels.granularity);
  v81[0] = quat_identity;
  *(idVec3 *)&v80.states.size = vec3_origin;
  if ( (*(_BYTE *)(v17 + 161) & 0x20) != 0 )
  {
    blendParms_t::blendParms_t(this: (blendParms_t *)&v80.edges.size);
    blendParms_t::SetDuration(this: (blendParms_t *)&v80.edges.size, frame: 3);
    blendParms_t::SetDestStartFrame(this: (blendParms_t *)&v80.edges.size, frame: 0);
    v24 = idAnimator_AnimWeb::ForceState(
            this: (idAnimator_AnimWeb *)&ai->aiVolatile.animation,
            subWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)LOWORD(v80.__vftable),
            stateIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v80.__vftable),
            blendParms: (const blendParms_t *)&v80.edges.size,
            blendEventMask_: 0);
  }
  else
  {
    if ( *(_DWORD *)(v17 + 32) != 0 )
    {
      LODWORD(v80.settings.editPos.x) = 20;
      v80.changeId = 0;
      *(_DWORD *)&v80.expandSubWebLinks = &v80.settings.editPos.y;
      HIBYTE(v80.settings.editPos.y) = 0;
      v80.settings.defaultBlendOutWindow = 20;
      *(_DWORD *)&v80.settings.nodeProps[4] = &v80.settings.defaultBlendDuration;
      *(_DWORD *)v80.settings.nodeProps = 0;
      HIBYTE(v80.settings.defaultBlendDuration) = 0;
      idAI2::GetSubWebAndStateFromAnimWebPath(
        this: ai,
        animWebPath: *(const char **)(v17 + 36),
        subWebName: (idStr *)&v80.changeId,
        stateName: (idStr *)v80.settings.nodeProps);
      idDeclAnimWeb::GetSubWebIndexForName(
        this: (idDeclAnimWeb *)&v80.trackedMemory,
        result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
        subWebName: *(const char **)&v80.expandSubWebLinks);
      idDeclAnimWeb::GetStateIndexForName(
        this: (idDeclAnimWeb *)&v80.programaticallyDefined,
        result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
        name: *(const char **)&v80.settings.nodeProps[4]);
      v25 = idAI2::ChangeAnimStateVia(
              this: ai,
              web: AIANIMWEB_BODY,
              subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)LOWORD(v80.__vftable),
              stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v80.__vftable),
              viaSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v80.trackedMemory),
              viaStateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)*(unsigned __int16 *)&v80.programaticallyDefined,
              interruptPath: INTR_PATH_YES,
              interruptBlend: INTR_BLEND_YES);
      idAnimator_AnimWeb::GetNodeTotalMovement(
        this: (idAnimator_AnimWeb *)&ai->aiVolatile.animation,
        modelIndex: nullptr,
        swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)LOWORD(v80.__vftable),
        si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v80.__vftable),
        translation: (idVec3 *)&v80.states.size,
        rotation: v81);
      idStr::FreeData(this: (idStr *)v80.settings.nodeProps);
      idStr::FreeData(this: (idStr *)&v80.changeId);
      goto LABEL_27;
    }
    v24 = idAI2::ChangeAnimState(
            this: ai,
            web: AIANIMWEB_BODY,
            subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)LOWORD(v80.__vftable),
            stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v80.__vftable),
            interruptPath: INTR_PATH_YES,
            interruptBlend: INTR_BLEND_YES);
  }
  v25 = v24;
LABEL_27:
  if ( v25 != 1 )
  {
    if ( v25 == 2 )
    {
      idStr::FreeData(this: (idStr *)&v80.editorModels.size);
      idStr::FreeData(this: (idStr *)&v80.nodeCache.size);
      return 1;
    }
    idStr::FreeData(this: (idStr *)&v80.editorModels.size);
    idStr::FreeData(this: (idStr *)&v80.nodeCache.size);
    return 0;
  }
  v26 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
  stateStartTime = this->stateStartTime;
  v28 = ai->GetAnimStack_2(this: ai);
  idAnimator_JointMod::PreBlendSnapshot(
    this: (idAnimator_JointMod *)&ai->aiVolatile.animation,
    stack: v28,
    curTime: stateStartTime,
    ticksPerSec: v26,
    fraction: v29);
  y = this->nextTargetPosition.y;
  z = this->nextTargetPosition.z;
  p_nextTargetRotation = &this->nextTargetRotation;
  x = this->nextTargetRotation.x;
  p_nextTargetPosition = &this->nextTargetPosition;
  v35 = this->nextTargetRotation.y;
  v80.name.str = (const char *)LODWORD(this->nextTargetPosition.x);
  *(float *)&v80.nextOnHashChain = y;
  *(float *)&v80.resourceListPtr = z;
  *((float *)&v80.idResource + 8) = x;
  w = this->nextTargetRotation.w;
  v80.textLength = LODWORD(this->nextTargetRotation.z);
  *(float *)&v80.textSource = v35;
  *(float *)&v80.md5Checksum = w;
  if ( gameLocal->spawnIds.ptr[*(_DWORD *)(v17 + 96) & 0x1FFF] == *(int *)(v17 + 96) >> 13 )
  {
    v37 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)(v17 + 96));
    Physics = idEntity::GetPhysics(this: v37);
    v39 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v80.name.str = *(const char **)v39;
    v80.nextOnHashChain = *(idResource **)(v39 + 4);
    v80.resourceListPtr = *(idResourceList **)(v39 + 8);
    v40 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)(v17 + 96));
    v41 = idEntity::GetPhysics(this: v40);
    v42 = (idQuat *)v41->GetAxis(this: v41, a2: 0);
    v43 = idMat3::ToQuat(this: (idMat3 *)&v80.nodes.size, result: v42);
  }
  else
  {
    if ( (*(_BYTE *)(v17 + 161) & 0x10) == 0 )
      goto LABEL_41;
    idDeclAnimWeb::FindNodeIndex(
      this: (idDeclAnimWeb *)&v80.trackedMemory,
      result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
      subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)LOWORD(v80.__vftable),
      stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v80.__vftable));
    if ( SHIWORD(v80.trackedMemory) == -1 )
      goto LABEL_41;
    v44 = ai->aiVolatile.animation.animWebAnimator.ptr[0].decl->nodes.list[SHIWORD(v80.trackedMemory)];
    if ( v44 == nullptr )
      goto LABEL_41;
    if ( v44->modelInfo.num <= 0 )
      goto LABEL_41;
    list = v44->modelInfo.list;
    if ( list == nullptr || list->animProps.num <= 0 )
      goto LABEL_41;
    decl = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: ai)->decl;
    v47 = nullptr;
    if ( list->animProps.num > 0 )
      v47 = list->animProps.list;
    v48 = idMD6AnimProps::SelectAnim(this: v47, declMD6: decl, index: 0);
    if ( v48 == nullptr )
      goto LABEL_41;
    *(float *)&v80.name.str = v48->origWorldPos.x;
    *(_DWORD *)&v80.programaticallyDefined = &v48->origWorldPos;
    *(float *)&v80.nextOnHashChain = v48->origWorldPos.y;
    *(float *)&v80.resourceListPtr = v48->origWorldPos.z;
    v43 = idAngles::ToQuat(this: (idAngles *)&v80.nodes.size, result: (idQuat *)&v48->origWorldRot);
  }
  *((float *)&v80.idResource + 8) = v43->x;
  *(float *)&v80.textSource = v43->y;
  *(float *)&v80.textLength = v43->z;
  *(float *)&v80.md5Checksum = v43->w;
LABEL_41:
  p_moveState = &ai->aiVolatile.physics.moveState;
  if ( (*(_BYTE *)(v17 + 160) & 8) != 0 )
    idAIMoveState::StartPerfectOrigin(
      this: p_moveState,
      idealAxis: (const idQuat *)&v80.idResource + 2,
      idealPos: (const idVec3 *)&v80.name,
      lerpTimeMs: 500,
      swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)LOWORD(v80.__vftable),
      si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v80.__vftable));
  else
    idAIMoveState::SetMovementModeForReal(this: p_moveState, mode: AIMOVEMODE_ANIM);
  this->movementMode = ai->aiVolatile.physics.moveState.movementMode;
  idAI2::SetWorldCollision(this: ai, collideWithWorld: (~*(unsigned __int8 *)(v17 + 160) & 0x40) != 0);
  idAI2::SetSolid(this: ai, isSolid: (~*(unsigned __int8 *)(v17 + 160) & 0x20) != 0);
  if ( (*(_BYTE *)(v17 + 160) & 0x80) != 0 )
  {
    idAnimator_WalkIK::DisableAll(this: &ai->walkIK);
    v50 = this->stateStartTime;
    v51 = ai->GetAnimStack_2(this: ai);
    idAnimator_Base::End(this: &ai->walkIK, stack: v51, curTime: v50, blendDurationMS: 200, reset: false);
  }
  else
  {
    if ( !ai->walkIK.enabled || (v52 = 1, ai->walkIK.enabledLegs == 0) )
      v52 = 0;
    if ( v52 == 0 )
    {
      idAnimator_WalkIK::EnableAll(this: &ai->walkIK);
      idAnimator_Base::SetAlpha(this: &ai->walkIK, alpha: 0.0);
      v53 = this->stateStartTime;
      v54 = ai->GetAnimStack_2(this: ai);
      idAnimator_Base::Start(this: &ai->walkIK, stack: v54, curTime: v53, blendDurationMS: 200, reset: false);
    }
  }
  v55 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)LOWORD(v80.__vftable);
  v56 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v80.__vftable);
  this->currentSubWebTarget.value = (__int16)v80.__vftable;
  this->currentStateTarget.value = (__int16)v56;
  if ( (unsigned __int8)idAnimator_AnimWeb::GetNodeTotalMovement(
                          this: (idAnimator_AnimWeb *)&ai->aiVolatile.animation,
                          modelIndex: nullptr,
                          swi: v55,
                          si: v56,
                          translation: (idVec3 *)&v80.subWebs.size,
                          rotation: (idQuat *)&v80.models.size) == 0 )
  {
    *(float *)&v80.subWebs.size = vec3_origin.x;
    *(float *)&v80.subWebs.granularity = vec3_origin.y;
    *(float *)&v80.states.list = vec3_origin.z;
    *(float *)&v80.models.size = quat_identity.x;
    *(float *)&v80.models.granularity = quat_identity.y;
    *(float *)&v80.edges.list = quat_identity.z;
    *(float *)&v80.edges.num = quat_identity.w;
  }
  idQuat::operator*(
    this: (idQuat *)&v80.nodes.size,
    result: (idVec3 *)((char *)&v80.idResource + 32),
    a: (const idVec3 *)&v80.states.size);
  v57 = (float)(*(float *)&v80.nodes.granularity + *(float *)&v80.nextOnHashChain);
  v58 = (float)(*(float *)&v80.nodes.size + *(float *)&v80.name.str);
  this->nextTargetPosition.z = *(float *)&v80.subWebs.list + *(float *)&v80.resourceListPtr;
  this->nextTargetPosition.y = v57;
  p_nextTargetPosition->x = v58;
  v59 = idQuat::Inverse(this: (idQuat *)&v80.edges.size, result: v81);
  v60 = *(float *)&v80.textSource;
  v61 = *((float *)&v80.idResource + 8);
  v62 = *(float *)&v80.textLength;
  v63 = v59->y;
  v64 = v59->z;
  v65 = (float)-(float)((float)(v59->y * *(float *)&v80.textSource)
                      - (float)((float)(v59->w * *(float *)&v80.md5Checksum)
                              - (float)(v59->x * *((float *)&v80.idResource + 8))));
  v66 = (float)((float)(v59->w * *((float *)&v80.idResource + 8))
              + (float)((float)(v59->y * *(float *)&v80.textLength) + (float)(v59->x * *(float *)&v80.md5Checksum)));
  v67 = (float)((float)(v59->w * *(float *)&v80.textLength)
              + (float)((float)(v59->z * *(float *)&v80.md5Checksum) + (float)(v59->x * *(float *)&v80.textSource)));
  this->nextTargetRotation.y = -(float)((float)(v59->x * *(float *)&v80.textLength)
                                      - (float)((float)(v59->z * *((float *)&v80.idResource + 8))
                                              + (float)((float)(v59->y * *(float *)&v80.md5Checksum)
                                                      + (float)(v59->w * *(float *)&v80.textSource))));
  this->nextTargetRotation.w = -(float)((float)((float)v64 * (float)v62) - (float)v65);
  p_nextTargetRotation->x = -(float)((float)((float)v64 * (float)v60) - (float)v66);
  this->nextTargetRotation.z = -(float)((float)((float)v63 * (float)v61) - (float)v67);
  idQuat::operator*(
    this: (idQuat *)&v80.nodes.size,
    result: (idVec3 *)&this->nextTargetRotation,
    a: (const idVec3 *)&v80.subWebs.size);
  v68 = (float)(*(float *)&v80.nodes.granularity + this->nextTargetPosition.y);
  v69 = (float)(*(float *)&v80.subWebs.list + this->nextTargetPosition.z);
  p_nextTargetPosition->x = *(float *)&v80.nodes.size + p_nextTargetPosition->x;
  this->nextTargetPosition.y = v68;
  this->nextTargetPosition.z = v69;
  v70 = idQuat::Inverse(this: (idQuat *)&v80.edges.size, result: (idQuat *)&v80.models.size);
  v71 = this->nextTargetRotation.y;
  v72 = p_nextTargetRotation->x;
  v73 = v70->z;
  v74 = v70->y;
  v75 = this->nextTargetRotation.z;
  v76 = (float)-(float)((float)(v70->y * this->nextTargetRotation.y)
                      - (float)((float)(v70->w * this->nextTargetRotation.w)
                              - (float)(v70->x * this->nextTargetRotation.x)));
  v77 = (float)((float)(v70->z * this->nextTargetRotation.w)
              + (float)((float)(v70->w * this->nextTargetRotation.z) + (float)(v70->x * this->nextTargetRotation.y)));
  v78 = (float)((float)(v70->x * this->nextTargetRotation.w)
              + (float)((float)(v70->y * this->nextTargetRotation.z) + (float)(v70->w * this->nextTargetRotation.x)));
  p_nextTargetRotation->y = -(float)((float)(v70->x * p_nextTargetRotation->z)
                                   - (float)((float)(v70->y * p_nextTargetRotation->w)
                                           + (float)((float)(v70->z * p_nextTargetRotation->x)
                                                   + (float)(v70->w * p_nextTargetRotation->y))));
  this->nextTargetRotation.w = -(float)((float)((float)v73 * (float)v75) - (float)v76);
  this->nextTargetRotation.z = -(float)((float)((float)v74 * (float)v72) - (float)v77);
  p_nextTargetRotation->x = -(float)((float)((float)v73 * (float)v71) - (float)v78);
  idQuat::Normalize(this: &this->nextTargetRotation);
  idStr::FreeData(this: (idStr *)&v80.editorModels.size);
  idStr::FreeData(this: (idStr *)&v80.nodeCache.size);
  return 1;
}


// ========================================================================
// __unwind$514684
// EA  : 0x82AAAA08
// RVA : 0x00AAAA08
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_514684()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 240));
}


// ========================================================================
// __unwind$514685
// EA  : 0x82AAAA30
// RVA : 0x00AAAA30
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_514685()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 272));
}


// ========================================================================
// __unwind$514686
// EA  : 0x82AAAA58
// RVA : 0x00AAAA58
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_514686()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 304));
}


// ========================================================================
// __unwind$514687
// EA  : 0x82AAAA80
// RVA : 0x00AAAA80
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_514687()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 336));
}


// ========================================================================
// ?AIAction_Work@idAction_ScriptedAnimWeb@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AAAAB0
// RVA : 0x00AAAAB0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_ScriptedAnimWeb::AIAction_Work(
        idAction_ScriptedAnimWeb *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idAIScriptedAnimWeb::animState_t *stateInfo; // r11
  _DWORD *currentState; // r11
  int jumpToState; // r17
  int currentScriptState; // r10
  idAIScriptedAnimWeb::animWebState_t *v11; // r26
  _DWORD *v12; // r11
  int v13; // r11
  BOOL IsPlaying; // r7
  idAnimWebBlendTree *BlendTree; // r3
  idAnimWebBlendTree *v16; // r24
  int num; // r25
  char v18; // r28
  int v19; // r30
  int v20; // r29
  int v21; // r28
  int v22; // r29
  int value; // r9
  idEntity *v24; // r3
  idEntity *v25; // r30
  idEventArg *v26; // r3
  int currentLoopCount; // r30
  idMD6LeafPlay *v28; // r29
  signed int v29; // r28
  int GameMs; // r3
  signed int LoopCount; // r3
  BOOL v32; // r11
  signed int loopCountToTrigger; // r10
  int v34; // r28
  int v35; // r29
  idEntity *v36; // r30
  idEventArg *v37; // r3
  idAIScriptedAnimWeb::animState_t *v38; // r9
  int v39; // r7
  int v40; // r10
  int v41; // r30
  int v42; // r29
  idAnimStack *v43; // r3
  double v44; // fp1
  unsigned __int16 v45; // [sp+50h] [-100h] BYREF
  _DWORD *p_animation; // [sp+54h] [-FCh] BYREF
  idEventArg v47; // [sp+60h] [-F0h] BYREF
  idStr v48; // [sp+80h] [-D0h] BYREF
  idStr v49[5]; // [sp+A0h] [-B0h] BYREF

  stateInfo = this->stateInfo;
  if ( stateInfo == nullptr )
    return;
  currentState = (_DWORD *)stateInfo->currentState;
  jumpToState = -1;
  currentScriptState = this->currentScriptState;
  p_animation = currentState;
  if ( (_DWORD *)currentScriptState != currentState )
    jumpToState = (int)currentState;
  idAIMoveState::SetMovementModeForReal(this: &ai->aiVolatile.physics.moveState, mode: this->movementMode);
  v11 = &this->stateInfo->animWebStates->list[this->currentScriptState];
  idAI2::SetWorldCollision(this: ai, collideWithWorld: (~*((unsigned __int8 *)v11 + 160) & 0x40) != 0);
  idAI2::SetSolid(this: ai, isSolid: (~*((_BYTE *)v11 + 160) & 0x20) != 0);
  p_animation = &ai->aiVolatile.animation.animWebAnimator.ptr[0].decl->idAnimator_AnimWeb::__vftable;
  v12 = p_animation;
  if ( p_animation != nullptr )
  {
    HIWORD(p_animation) = ai->aiVolatile.animation.animWebAnimator.ptr[0].curNodeIndex.value;
    if ( SHIWORD(p_animation) != -1 )
    {
      v13 = *(_DWORD *)(4 * SHIWORD(p_animation) + v12[14]);
      if ( v13 != 0
        && *(__int16 *)(v13 + 2) == this->currentSubWebTarget.value
        && *(__int16 *)(v13 + 4) == this->currentStateTarget.value )
      {
        BlendTree = idAnimator_AnimWeb::idModelAnimState::GetBlendTree(
                      this: ai->aiVolatile.animation.animWebAnimator.ptr[0].modelAnimStates.list,
                      nodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)HIWORD(p_animation));
        v16 = BlendTree;
        if ( BlendTree != nullptr )
          num = BlendTree->leaves.num;
        else
          num = 0;
        if ( (*((_BYTE *)v11 + 160) & 0x10) != 0 )
        {
          if ( num <= 0 )
            goto LABEL_47;
          currentLoopCount = this->currentLoopCount;
          v28 = (idMD6LeafPlay *)*BlendTree->leaves.list;
          v29 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          LoopCount = idMD6LeafPlay::GetLoopCount(this: v28, gameTime: GameMs, ticksPerSec: v29);
          this->currentLoopCount = LoopCount;
          if ( currentLoopCount != LoopCount )
          {
            if ( v11->loopTriggerType != TRIGGERTYPE_ONCOUNT )
            {
              loopCountToTrigger = v11->loopCountToTrigger;
              __twllei(loopCountToTrigger, 0);
              __twlgei(loopCountToTrigger & ~(__ROL4__(LoopCount, 1) - 1), 0xFFFFFFFF);
              v32 = (_cntlzw(LoopCount % loopCountToTrigger) & 0x20) != 0;
            }
            else
            {
              v32 = (_cntlzw(LoopCount - v11->loopCountToTrigger) & 0x20) != 0;
            }
            if ( v32 )
            {
              v34 = 0;
              if ( v11->triggerLoopCount.num > 0 )
              {
                v35 = 0;
                do
                {
                  v36 = idEntityPtr<idEntity const>::operator->(this: &v11->triggerLoopCount.list[v35]);
                  if ( v36 != nullptr )
                  {
                    v37 = idEventArg::idEventArg(this: &v47, data: ai);
                    idEventReceiver::PostEventMS(
                      this: v36,
                      ev: &EV_Activate,
                      time: *(_DWORD *)&v37->type,
                      arg1: (const idEventArg *)LODWORD(v37->value.v[1]));
                  }
                  ++v34;
                  ++v35;
                }
                while ( v34 < v11->triggerLoopCount.num );
              }
            }
          }
          if ( this->loopInterval <= 0
            || gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) <= this->stateStartTime + this->loopInterval )
          {
            goto LABEL_47;
          }
        }
        else
        {
          v18 = 1;
          v19 = 0;
          if ( num > 0 )
          {
            v20 = 0;
            do
            {
              if ( v18 == 0 )
                break;
              IsPlaying = idMD6LeafPlay::IsPlaying(
                            this: (idMD6LeafPlay *)v16->leaves.list[v20],
                            gameTime: curTime,
                            ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
                            inWrapMode: (const idMD6Leaf::wrapMode_t)((*((_BYTE *)v11 + 160) & 0x10) != 0),
                            a5: IsPlaying);
              ++v19;
              ++v20;
              v18 = IsPlaying ? 0 : v18;
            }
            while ( v19 < num );
          }
          if ( v18 == 0 )
            goto LABEL_47;
          v21 = 0;
          if ( v11->triggerLeave.num > 0 )
          {
            v22 = 0;
            do
            {
              value = v11->triggerLeave.list[v22].spawnId.value;
              if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
              {
                v24 = gameLocal->entities.ptr[value & 0x1FFF];
                if ( v24 != nullptr )
                {
                  v25 = idEntity::CastTo(c: v24);
                  if ( v25 != nullptr )
                  {
                    v26 = idEventArg::idEventArg(this: &v47, data: ai);
                    idEventReceiver::PostEventMS(
                      this: v25,
                      ev: &EV_Activate,
                      time: *(_DWORD *)&v26->type,
                      arg1: (const idEventArg *)LODWORD(v26->value.v[1]));
                  }
                }
              }
              ++v21;
              ++v22;
            }
            while ( v21 < v11->triggerLeave.num );
          }
          if ( (*((_BYTE *)v11 + 160) & 2) != 0 )
          {
            ai->aiVolatile.perception.flags &= ~1u;
          }
          else if ( (*((_BYTE *)v11 + 160) & 1) != 0 )
          {
            ai->aiVolatile.perception.flags |= 1u;
          }
        }
        if ( (*((_BYTE *)v11 + 160) & 4) != 0 )
        {
          *((_BYTE *)this + 84) |= 0x80u;
        }
        else if ( v11->jumpToState == -1 )
        {
          jumpToState = this->currentScriptState + 1;
        }
        else
        {
          jumpToState = v11->jumpToState;
        }
      }
    }
  }
LABEL_47:
  if ( jumpToState != -1 )
  {
    if ( jumpToState == -3 )
    {
      v38 = this->stateInfo;
      v39 = this->currentScriptState;
      *((_BYTE *)this + 84) |= 0x80u;
      v40 = (int)&v38->animWebStates->list[v39];
      if ( *(_DWORD *)(v40 + 64) != 0 )
      {
        v49[0].len = 0;
        v49[0].baseBuffer[0] = 0;
        v49[0].allocedAndFlag = 20;
        v49[0].data = v49[0].baseBuffer;
        v48.allocedAndFlag = 20;
        v48.data = v48.baseBuffer;
        v48.len = 0;
        v48.baseBuffer[0] = 0;
        p_animation = &ai->aiVolatile.animation;
        idAI2::GetSubWebAndStateFromAnimWebPath(
          this: ai,
          animWebPath: *(const char **)(v40 + 68),
          subWebName: v49,
          stateName: &v48);
        idDeclAnimWeb::GetSubWebIndexForName(
          this: (idDeclAnimWeb *)&p_animation,
          result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
          subWebName: v49[0].data);
        idDeclAnimWeb::GetStateIndexForName(
          this: (idDeclAnimWeb *)&v45,
          result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
          name: v48.data);
        idAI2::ChangeAnimState(
          this: ai,
          web: AIANIMWEB_BODY,
          subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(p_animation),
          stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v45,
          interruptPath: INTR_PATH_YES,
          interruptBlend: INTR_BLEND_YES);
        idAIMoveState::SetMovementModeForReal(this: &ai->aiVolatile.physics.moveState, mode: AIMOVEMODE_ANIM);
        v41 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
        v42 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        v43 = ai->GetAnimStack_2(this: ai);
        idAnimator_JointMod::PreBlendSnapshot(
          this: (idAnimator_JointMod *)&ai->aiVolatile.animation,
          stack: v43,
          curTime: v42,
          ticksPerSec: v41,
          fraction: v44);
        idStr::FreeData(this: &v48);
        idStr::FreeData(this: v49);
      }
    }
    else
    {
      *((_BYTE *)this + 84) = (4
                             * _cntlzw((unsigned __int8)idAction_ScriptedAnimWeb::StartNextState(
                                                          this,
                                                          ai,
                                                          newState: jumpToState)))
                            & 0x80
                            | *((_BYTE *)this + 84) & 0x7F;
    }
  }
}


// ========================================================================
// __unwind$515281
// EA  : 0x82AAB05C
// RVA : 0x00AAB05C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_515281()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 160));
}


// ========================================================================
// __unwind$515282
// EA  : 0x82AAB084
// RVA : 0x00AAB084
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_515282()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 128));
}


// ========================================================================
// ?AIAction_Work@idAction_MoveToScenePoint@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AAB0B8
// RVA : 0x00AAB0B8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_MoveToScenePoint::AIAction_Work(
        idAction_MoveToScenePoint *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  int value; // r10
  idScenePoint *v9; // r3
  idScenePoint *v10; // r3
  idScenePoint *v11; // r27
  idScenePoint **p_curScenePoint; // r28
  idAIMoveState *p_moveState; // r24
  int v14; // r3
  idAIMoveState_vtbl *v15; // r11
  idAIMoveState *v16; // r3
  bool v17; // zf
  int stayTimeOut; // r11
  const idEntity *v19; // r4
  float *presentable; // r11
  double v21; // fp31
  double v22; // fp30
  double v23; // fp29
  float *ScenePointPos; // r3
  double v25; // fp8
  double v26; // fp6
  idScenePoint *NextScenePoint; // r3
  idScenePoint *v28; // r29
  int v29; // r27
  idPresentable *v30; // r11
  idQuat *v31; // r3
  aiArrivalAction_t v32; // r28
  double radius; // fp30
  idPhysics *v34; // r3
  const idVec3 *v35; // r30
  idScenePoint *v36; // r3
  const idEntity *Enemy; // r4
  idPlayer *Player; // r3
  idPhysics *Physics; // r3
  idScenePoint_vtbl *v40; // r30
  int v41; // r3
  posture_t v42; // [sp+8h] [-218h]
  int v43; // [sp+Ch] [-214h]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v44; // [sp+10h] [-210h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v45; // [sp+14h] [-20Ch]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v46; // [sp+18h] [-208h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v47; // [sp+1Ch] [-204h]
  int v48; // [sp+20h] [-200h]
  int v49; // [sp+24h] [-1FCh]
  int v50; // [sp+28h] [-1F8h]
  int v51; // [sp+2Ch] [-1F4h]
  int v52; // [sp+30h] [-1F0h]
  int v53; // [sp+34h] [-1ECh]
  int v54; // [sp+38h] [-1E8h]
  int v55; // [sp+3Ch] [-1E4h]
  int v56; // [sp+40h] [-1E0h]
  int v57; // [sp+44h] [-1DCh]
  int v58; // [sp+48h] [-1D8h]
  int v59; // [sp+4Ch] [-1D4h]
  int v60; // [sp+50h] [-1D0h]
  int v61; // [sp+54h] [-1CCh]
  int v62; // [sp+58h] [-1C8h]
  int v63; // [sp+60h] [-1C0h]
  int v64; // [sp+68h] [-1B8h]
  int v65; // [sp+70h] [-1B0h]
  int v66; // [sp+78h] [-1A8h]
  int v67; // [sp+80h] [-1A0h]
  int v68; // [sp+88h] [-198h]
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v69; // [sp+90h] [-190h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v70; // [sp+92h] [-18Eh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v71; // [sp+94h] [-18Ch] BYREF
  _DWORD v72[2]; // [sp+98h] [-188h] BYREF
  idQuat v73; // [sp+A0h] [-180h] BYREF
  float *v74; // [sp+B0h] [-170h] BYREF
  int v75; // [sp+B4h] [-16Ch]
  idVec3 v76; // [sp+B8h] [-168h] BYREF
  idStr v77; // [sp+D0h] [-150h] BYREF
  idStr v78; // [sp+F0h] [-130h] BYREF
  idMat3 v79[2]; // [sp+110h] [-110h] BYREF
  idVec3 v80[4]; // [sp+170h] [-B0h] BYREF

  value = this->scenepointTarget.spawnId.value;
  v72[0] = &this->scenepointTarget;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
    || (v9 = (idScenePoint *)gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
    || (v10 = idScenePoint::CastTo(c: v9), v11 = v10, v10 == nullptr) )
  {
    this->isDone = true;
    return;
  }
  p_curScenePoint = &ai->aiVolatile.memory.curScenePoint;
  ai->aiVolatile.memory.curScenePoint = v10;
  if ( !idScenePoint::RequestScenePoint(this: v10, user: ai, curTime) )
  {
    this->stayTimeOut = -1;
    *p_curScenePoint = nullptr;
    this->isDone = true;
  }
  p_moveState = &ai->aiVolatile.physics.moveState;
  v14 = ai->aiVolatile.physics.moveState.GetMoveStatus(this: &ai->aiVolatile.physics.moveState);
  v15 = ai->aiVolatile.physics.moveState.__vftable;
  v17 = v14 != 1;
  v16 = &ai->aiVolatile.physics.moveState;
  if ( !v17 )
  {
    if ( !v15->IsPlayingTraversalAnim(this: v16) )
      idAIMoveState::ContinueMove(this: &ai->aiVolatile.physics.moveState, totalTravelTime: (int *)&v74);
    if ( p_moveState->GetMoveStatus(this: &ai->aiVolatile.physics.moveState) == 1 && fsm->stateFrame > 2 )
    {
      v78.len = 0;
      v78.baseBuffer[0] = 0;
      v78.allocedAndFlag = 20;
      v78.data = v78.baseBuffer;
      idAI2::GetMovementStateName(this: ai, name: &v78);
      idAI2::ChangeAnimState(
        this: ai,
        web: AIANIMWEB_BODY,
        subWeb: ai->aiVolatile.animation.subWeb,
        stateName: v78.data,
        interruptPath: INTR_PATH_YES,
        interruptBlend: INTR_BLEND_NO,
        subWebIndex: nullptr,
        stateIndex: nullptr);
      idStr::FreeData(this: &v78);
    }
    idAI2::UpdateBodyOrientationWhileMoving(this: ai);
    goto LABEL_42;
  }
  if ( v15->GetMoveStatus(this: v16) != AIMOVESTATUS_DONE )
  {
    if ( (this->mtspFlags & 0x40) != 0 )
    {
      idAI2::SetEnableHeadTracking(this: ai, enable: true);
      Enemy = idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
      if ( Enemy != nullptr )
      {
        idAI2::SetAimFocusEntity(
          this: ai,
          ent: Enemy,
          keepFocusInView: (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 4) != 0,
          aimPoint: AIMPOINT_BEST,
          timeout: -1);
        idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
      }
    }
    goto LABEL_42;
  }
  stayTimeOut = this->stayTimeOut;
  if ( stayTimeOut == -1 )
  {
    v75 = (int)(float)(v11->duration * (float)1000.0);
    this->stayTimeOut = v75 + curTime;
    if ( v11->duration > 0.0 )
    {
      v77.len = 0;
      v77.baseBuffer[0] = 0;
      v77.allocedAndFlag = 20;
      v77.data = v77.baseBuffer;
      idAI2::GetIdleStateName(this: ai, name: &v77);
      idAI2::ChangeAnimState(
        this: ai,
        web: AIANIMWEB_BODY,
        subWeb: ai->aiVolatile.animation.subWeb,
        stateName: v77.data,
        interruptPath: INTR_PATH_YES,
        interruptBlend: INTR_BLEND_NO,
        subWebIndex: nullptr,
        stateIndex: nullptr);
      idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
      idStr::FreeData(this: &v77);
    }
    idScenePoint::ActivateScenePoint(this: v11, user: ai, curTime);
    goto LABEL_42;
  }
  if ( v11->duration < 0.0 )
    this->stayTimeOut = stayTimeOut + 1000;
  if ( curTime < this->stayTimeOut )
  {
    if ( (this->mtspFlags & 0x80) != 0 )
    {
      idAI2::SetEnableHeadTracking(this: ai, enable: true);
      v19 = idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
      if ( v19 != nullptr )
      {
        idAI2::SetAimFocusEntity(
          this: ai,
          ent: v19,
          keepFocusInView: (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 4) != 0,
          aimPoint: AIMPOINT_BEST,
          timeout: -1);
        idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
        this->isDone = false;
LABEL_42:
        if ( (this->mtspFlags & 1) != 0 )
        {
          Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
          if ( Player != nullptr )
          {
            Physics = idEntity::GetPhysics(this: Player);
            v40 = v11->__vftable;
            v41 = (int)Physics->GetOrigin(this: Physics, a2: 0);
            if ( !v40->IsInArc_2(this: v11, a2: (const idVec3 *)v41) )
              this->isDone = true;
          }
        }
        return;
      }
    }
    else
    {
      idAI2::SetEnableHeadTracking(this: ai, enable: true);
      if ( idAIMemory::GetEnemy(this: &ai->aiVolatile.memory) != nullptr )
      {
        presentable = (float *)v11->presentable;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this: v11);
          presentable = (float *)v11->presentable;
        }
        v21 = (float)(presentable[33] * (float)1000.0);
        v22 = (float)(presentable[34] * (float)1000.0);
        v23 = (float)(presentable[35] * (float)1000.0);
        v74 = presentable + 33;
        ScenePointPos = (float *)idScenePoint::GetScenePointPos(this: (idScenePoint *)v79, result: v11);
        v25 = (float)(ScenePointPos[2] + (float)v23);
        v26 = (float)(ScenePointPos[1] + (float)v22);
        v76.x = *ScenePointPos + (float)v21;
        v76.z = v25;
        v76.y = v26;
        idAI2::SetExplicitAimFocusPoint(
          this: ai,
          point: &v76,
          keepFocusInView: true,
          timeout: -1,
          focusType: AIFOCUS_NOTHING);
        idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
      }
    }
    this->isDone = false;
    goto LABEL_42;
  }
  idAIMemory::UpdateScenePointHistory(this: &ai->aiVolatile.memory, scenePoint: v11);
  idScenePoint::ReleaseScenePoint(this: v11, user: ai);
  NextScenePoint = idScenePoint::GetNextScenePoint(this: v11, spTypeRequired: (scenePointType_t)0);
  v28 = NextScenePoint;
  if ( NextScenePoint == nullptr )
  {
    *p_curScenePoint = nullptr;
    this->isDone = true;
    goto LABEL_42;
  }
  v73.z = 0.0;
  v73.y = 0.0;
  v29 = 2;
  v73.x = 0.0;
  v73.w = 1.0;
  if ( NextScenePoint->duration > 0.0 )
  {
    v30 = NextScenePoint->presentable;
    if ( v30 == nullptr )
    {
      idEntity::InitPresentableInternal(this: NextScenePoint);
      v30 = v28->presentable;
    }
    v31 = (idQuat *)idVec3::ToMat3(this: v80, result: &v30->axis);
    v73 = *idMat3::ToQuat(this: v79, result: v31);
    v29 = 3;
  }
  v70.value = -1;
  v71.value = -1;
  idAI2::GetCurrentSubWebAndStateIndices(this: ai, swi: &v70, si: &v71);
  v69.value = -1;
  HIWORD(v72[0]) = -1;
  idAI2::GetMovementSubWebAndStateIndices(
    this: ai,
    swi: &v69,
    si: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v72);
  ai->SetWalkState(this: ai, a2: (const walkState_t)(((_cntlzw(this->mtspFlags & 0x20) & 0x20) == 0) + 1));
  idAIMoveParms::idAIMoveParms(this: (idAIMoveParms *)&v79[0].mat[1].y);
  v32 = AIARRIVAL_STOP;
  if ( v28->duration == 0.0 )
    v32 = AIARRIVAL_CONTINUE;
  radius = v28->radius;
  v34 = idEntity::GetPhysics(this: ai);
  v35 = v34->GetOrigin(this: v34, a2: 0);
  v36 = idScenePoint::GetScenePointPos(this: (idScenePoint *)v79, result: v28);
  idAIMoveParms::Init(
    this: (idAIMoveParms *)&v79[0].mat[1].y,
    moveReason_: AIMOVEREASON_UNKNOWN,
    startOrigin_: v35,
    goalOrigin_: (const idVec3 *)v36,
    goalEntity_: v28,
    goalOrientation_: &v73,
    goalScenePoint_: nullptr,
    goalTolerance_: radius,
    intermediateTolerance_: 0.1,
    arrivalAction_: (const aiArrivalAction_t)v72,
    arrivalPosture_: v42,
    flags_: v43,
    sourceSubWeb_: v44,
    sourceState_: v45,
    destSubWeb_: v46,
    destState_: v47,
    a17: v48,
    a18: v49,
    a19: v50,
    a20: v51,
    a21: v52,
    a22: v53,
    a23: v54,
    a24: v55,
    a25: v56,
    a26: v57,
    a27: v58,
    a28: v59,
    a29: v60,
    a30: v61,
    a31: v62,
    a32: v32,
    a33: v63,
    a34: POSTURE_STANDING,
    a35: v64,
    a36: v29,
    a37: v65,
    a38: &v70.value,
    a39: v66,
    arrivalAction__0: &v71.value,
    a41: v67,
    arrivalPosture_a: &v69.value,
    a43: v68,
    flags_a: (__int16 *)v72);
  idAIMoveState::StartMove(this: p_moveState, parms: (const idAIMoveParms *)&v79[0].mat[1].y);
  this->stayTimeOut = -1;
}


// ========================================================================
// __unwind$515733
// EA  : 0x82AAB734
// RVA : 0x00AAB734
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_515733()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 240));
}


// ========================================================================
// __unwind$515734
// EA  : 0x82AAB75C
// RVA : 0x00AAB75C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_515734()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 208));
}


// ========================================================================
// ?AIAction_ExitState@idAction_MoveToScenePoint@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AAB790
// RVA : 0x00AAB790
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_MoveToScenePoint::AIAction_ExitState(
        idAction_MoveToScenePoint *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int value; // r10
  idScenePoint *v7; // r3
  idScenePoint *v8; // r3
  idScenePoint *v9; // r28
  idStr v10[2]; // [sp+50h] [-50h] BYREF

  value = this->scenepointTarget.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v7 = (idScenePoint *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v7 != nullptr )
    {
      v8 = idScenePoint::CastTo(c: v7);
      v9 = v8;
      if ( v8 != nullptr )
      {
        idAIMemory::UpdateScenePointHistory(this: &ai->aiVolatile.memory, scenePoint: v8);
        idScenePoint::ReleaseScenePoint(this: v9, user: ai);
        ai->aiVolatile.memory.curScenePoint = nullptr;
      }
    }
  }
  v10[0].len = 0;
  v10[0].baseBuffer[0] = 0;
  this->stayTimeOut = -1;
  this->scenepointTarget.spawnId.value = 0x1FFF;
  this->mtspFlags = MTSP_NONE;
  this->isDone = false;
  v10[0].allocedAndFlag = 20;
  v10[0].data = v10[0].baseBuffer;
  idAI2::GetIdleStateName(this: ai, name: v10);
  idAI2::ChangeAnimState(
    this: ai,
    web: AIANIMWEB_BODY,
    subWeb: ai->aiVolatile.animation.subWeb,
    stateName: v10[0].data,
    interruptPath: INTR_PATH_YES,
    interruptBlend: INTR_BLEND_NO,
    subWebIndex: nullptr,
    stateIndex: nullptr);
  idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
  idStr::FreeData(this: v10);
}


// ========================================================================
// __unwind$516094
// EA  : 0x82AAB8A4
// RVA : 0x00AAB8A4
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_516094()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Clear@idAIActionsQueue@@QAAXXZ
// EA  : 0x82AAB8D0
// RVA : 0x00AAB8D0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAIActionsQueue::Clear(idAIActionsQueue *this)
{
  idEventArgs *list; // r3

  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->actionEvents);
  if ( this->actionArgs.listStatic == 0 || this->actionArgs.listStatic == 2 )
  {
    list = this->actionArgs.list;
    if ( list != nullptr )
      idListArrayDelete<idEventArgs>(ptr: (char *)list, num: this->actionArgs.size);
    this->actionArgs.list = nullptr;
    this->actionArgs.size = 0;
  }
  this->actionArgs.num = 0;
}


// ========================================================================
// ?GetActionBlocks@idAIActionManager@@QBA_NABVidEventDef@@@Z
// EA  : 0x82AAB940
// RVA : 0x00AAB940
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

int __fastcall idAIActionManager::GetActionBlocks(idAIActionManager *this, const idEventDef *actionEvent)
{
  idAIAction *ActionStateForEvent; // r3

  ActionStateForEvent = idAIActionManager::GetActionStateForEvent(this, event: actionEvent);
  if ( ActionStateForEvent != nullptr )
    return ActionStateForEvent->GetActionFlags(this: ActionStateForEvent) & 1;
  else
    return 0;
}


// ========================================================================
// ?GetActionStopsMovement@idAIActionManager@@QBA_NABVidEventDef@@@Z
// EA  : 0x82AAB990
// RVA : 0x00AAB990
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

BOOL __fastcall idAIActionManager::GetActionStopsMovement(idAIActionManager *this, const idEventDef *actionEvent)
{
  idAIAction *ActionStateForEvent; // r3

  ActionStateForEvent = idAIActionManager::GetActionStateForEvent(this, event: actionEvent);
  return ActionStateForEvent != nullptr && (ActionStateForEvent->GetActionFlags(this: ActionStateForEvent) & 2) != 0;
}


// ========================================================================
// ?Action_MoveToPointEnter@idAction_MoveToPoint@@QAA?AVeventVoid@@PAVidEntity@@W4aiMoveReason_t@@ABVidVec3@@W4aiArrivalAction_t@@M_N2@Z
// EA  : 0x82AABAA8
// RVA : 0x00AABAA8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_MoveToPoint *__fastcall idAction_MoveToPoint::Action_MoveToPointEnter(
        idAction_MoveToPoint *this,
        eventVoid *result,
        idAI2 *entity,
        aiMoveReason_t moveReason,
        const idVec3 *dest,
        aiArrivalAction_t arrivalAction,
        double tolerance,
        const bool align,
        const idVec3 *dir,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29)
{
  char v35; // r22
  idAI2 *v36; // r30
  idAI2_vtbl *v37; // r11
  int v38; // r28
  idQuat *v39; // r3
  idQuat *v40; // r3
  const idMat3 *v41; // r3
  idPhysics *Physics; // r3
  const idVec3 *v43; // r3
  posture_t v45; // [sp+8h] [-1E8h]
  int v46; // [sp+Ch] [-1E4h]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v47; // [sp+10h] [-1E0h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v48; // [sp+14h] [-1DCh]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v49; // [sp+18h] [-1D8h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v50; // [sp+1Ch] [-1D4h]
  int v51; // [sp+20h] [-1D0h]
  int v52; // [sp+24h] [-1CCh]
  int v53; // [sp+28h] [-1C8h]
  int v54; // [sp+2Ch] [-1C4h]
  int v55; // [sp+30h] [-1C0h]
  int v56; // [sp+34h] [-1BCh]
  int v57; // [sp+38h] [-1B8h]
  int v58; // [sp+3Ch] [-1B4h]
  int v59; // [sp+40h] [-1B0h]
  int v60; // [sp+44h] [-1ACh]
  int v61; // [sp+48h] [-1A8h]
  int v62; // [sp+4Ch] [-1A4h]
  int v63; // [sp+50h] [-1A0h]
  int v64; // [sp+54h] [-19Ch]
  int v65; // [sp+58h] [-198h]
  int v66; // [sp+60h] [-190h]
  int v67; // [sp+68h] [-188h]
  int v68; // [sp+70h] [-180h]
  int v69; // [sp+78h] [-178h]
  int v70; // [sp+80h] [-170h]
  int v71; // [sp+88h] [-168h]
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v72; // [sp+90h] [-160h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v73; // [sp+92h] [-15Eh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v74; // [sp+94h] [-15Ch] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v75[5]; // [sp+96h] [-15Ah] BYREF
  idMat3 v76[4]; // [sp+A0h] [-150h] BYREF
  bool allowStrafing; // [sp+144h] [-ACh]
  idMat3 v78; // [sp+150h] [-A0h] BYREF

  v35 = (char)dir;
  v36 = idAI2::CastTo(c: entity);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v36) == 0 )
  {
    idAI2::GetDefaultMovementMode(this: v36);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v36->aiVolatile.physics.moveState);
  }
  v37 = v36->__vftable;
  v36->aiVolatile.focus.enableBodyRotation = true;
  *(_DWORD *)&result[28] = v37->GetWalkState(this: v36);
  v38 = 2;
  if ( (*((_BYTE *)&v36->aiEditable.behaviors.decl->movementBehaviors + 40) & 0x20) != 0 )
    v38 = 18;
  if ( v36->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType != ANIMWEBAI_RUNINDEXTYPE_INJURED )
    v38 |= 0xCu;
  v76[0].mat[0].x = quat_identity.x;
  v76[0].mat[0].y = quat_identity.y;
  v76[0].mat[0].z = quat_identity.z;
  v76[0].mat[1].x = quat_identity.w;
  if ( v35 != 0 && ((*(_DWORD *)(a29 + 8) | *(_DWORD *)(a29 + 4) | *(_DWORD *)a29) & 0x7FFFFFFF) != 0 )
  {
    v39 = (idQuat *)idVec3::ToMat3(this: (idVec3 *)&v78.mat[1].y, result: (idMat3 *)a29);
    v40 = idMat3::ToQuat(this: &v78, result: v39);
    v76[0].mat[0].x = v40->x;
    v38 |= 1u;
    v76[0].mat[0].y = v40->y;
    v76[0].mat[0].z = v40->z;
    v76[0].mat[1].x = v40->w;
  }
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v36) != 0 )
  {
    idAIMoveCmd::idAIMoveCmd(
      this: (idAIMoveCmd *)&v76[0].mat[1].y,
      user: "w:\\tech5\\tungsten\\game\\ai\\fsm\\AIAction.cpp(732) : moveToPoint");
    idAIMoveCmd::SetDest(this: (idAIMoveCmd *)&v76[0].mat[1].y, dest, entType: DEST_ENT_NONE);
    idAIMoveCmd::SetArriveRadius(this: (idAIMoveCmd *)&v76[0].mat[1].y, radius: tolerance, height: -1.0);
    if ( (v38 & 1) != 0 )
    {
      v41 = idQuat::ToMat3(this: (idQuat *)&v78.mat[1].y, result: v76);
      idAIMoveCmd::SetArriveOrientation(
        this: (idAIMoveCmd *)&v76[0].mat[1].y,
        orient: AIARRIVAL_ORIENT_ALIGN,
        axis: v41);
    }
    allowStrafing = v36->aiConstants.movement.allowStrafing;
    idAnimBaseFSM::SetDestination(this: &v36->aiVolatile.animation.animFSM, cmd: (const idAIMoveCmd *)&v76[0].mat[1].y);
    idAIMoveCmd::~idAIMoveCmd(this: (idAIMoveCmd *)&v76[0].mat[1].y);
  }
  else
  {
    v75[0].value = -1;
    v74.value = -1;
    idAI2::GetCurrentSubWebAndStateIndices(this: v36, swi: v75, si: &v74);
    v73.value = -1;
    v72.value = -1;
    idAI2::GetMovementSubWebAndStateIndices(this: v36, swi: &v73, si: &v72);
    idAIMoveParms::idAIMoveParms(this: (idAIMoveParms *)&v76[0].mat[1].y);
    Physics = idEntity::GetPhysics(this: v36);
    v43 = Physics->GetOrigin(this: Physics, a2: 0);
    idAIMoveParms::Init(
      this: (idAIMoveParms *)&v76[0].mat[1].y,
      moveReason_: moveReason,
      startOrigin_: v43,
      goalOrigin_: dest,
      goalEntity_: nullptr,
      goalOrientation_: (const idQuat *)v76,
      goalScenePoint_: nullptr,
      goalTolerance_: tolerance,
      intermediateTolerance_: 0.1,
      arrivalAction_: (const aiArrivalAction_t)&v72,
      arrivalPosture_: v45,
      flags_: v46,
      sourceSubWeb_: v47,
      sourceState_: v48,
      destSubWeb_: v49,
      destState_: v50,
      a17: v51,
      a18: v52,
      a19: v53,
      a20: v54,
      a21: v55,
      a22: v56,
      a23: v57,
      a24: v58,
      a25: v59,
      a26: v60,
      a27: v61,
      a28: v62,
      a29: v63,
      a30: v64,
      a31: v65,
      a32: arrivalAction,
      a33: v66,
      a34: POSTURE_STANDING,
      a35: v67,
      a36: v38,
      a37: v68,
      a38: &v75[0].value,
      a39: v69,
      arrivalAction__0: &v74.value,
      a41: v70,
      arrivalPosture_a: &v73.value,
      a43: v71,
      flags_a: &v72.value);
    idAIMoveState::StartMove(this: &v36->aiVolatile.physics.moveState, parms: (const idAIMoveParms *)&v76[0].mat[1].y);
  }
  return this;
}


// ========================================================================
// __unwind$516690
// EA  : 0x82AABD5C
// RVA : 0x00AABD5C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_516690()
{
  int v0; // r12

  idAIMoveCmd::~idAIMoveCmd(this: (idAIMoveCmd *)(v0 - 496 + 176));
}


// ========================================================================
// ?Action_MoveToPointNoFailEnter@idAction_MoveToPointNoFail@@QAA?AVeventVoid@@PAVidEntity@@W4aiMoveReason_t@@ABVidVec3@@W4aiArrivalAction_t@@M_N2PBVidDeclVoiceOver@@@Z
// EA  : 0x82AABD88
// RVA : 0x00AABD88
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_MoveToPointNoFail *__fastcall idAction_MoveToPointNoFail::Action_MoveToPointNoFailEnter(
        idAction_MoveToPointNoFail *this,
        eventVoid *result,
        idAI2 *entity,
        aiMoveReason_t moveReason,
        const idVec3 *dest,
        aiArrivalAction_t arrivalAction,
        double tolerance,
        const bool align,
        const idVec3 *dir,
        const idDeclVoiceOver *ptr,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31)
{
  char v37; // r29
  idAI2 *v38; // r31
  idAI2_vtbl *v39; // r11
  int v40; // r28
  idQuat *v41; // r3
  idQuat *v42; // r3
  const idMat3 *v43; // r3
  idPhysics *Physics; // r3
  const idVec3 *v46; // r3
  int started; // r28
  posture_t v48; // [sp+8h] [-148h]
  int v49; // [sp+Ch] [-144h]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v50; // [sp+10h] [-140h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v51; // [sp+14h] [-13Ch]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v52; // [sp+18h] [-138h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v53; // [sp+1Ch] [-134h]
  int v54; // [sp+20h] [-130h]
  int v55; // [sp+24h] [-12Ch]
  int v56; // [sp+28h] [-128h]
  int v57; // [sp+2Ch] [-124h]
  int v58; // [sp+30h] [-120h]
  int v59; // [sp+34h] [-11Ch]
  int v60; // [sp+38h] [-118h]
  int v61; // [sp+3Ch] [-114h]
  int v62; // [sp+40h] [-110h]
  int v63; // [sp+44h] [-10Ch]
  int v64; // [sp+48h] [-108h]
  int v65; // [sp+4Ch] [-104h]
  int v66; // [sp+50h] [-100h]
  int v67; // [sp+54h] [-FCh]
  int v68; // [sp+58h] [-F8h]
  int v69; // [sp+60h] [-F0h]
  int v70; // [sp+68h] [-E8h]
  int v71; // [sp+70h] [-E0h]
  int v72; // [sp+78h] [-D8h]
  int v73; // [sp+80h] [-D0h]
  int v74; // [sp+88h] [-C8h]
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v75; // [sp+90h] [-C0h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v76; // [sp+92h] [-BEh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v77; // [sp+94h] [-BCh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v78[5]; // [sp+96h] [-BAh] BYREF
  idMat3 v79[2]; // [sp+A0h] [-B0h] BYREF

  v37 = (char)dir;
  v38 = idAI2::CastTo(c: entity);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v38) == 0 )
  {
    idAI2::GetDefaultMovementMode(this: v38);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v38->aiVolatile.physics.moveState);
  }
  v39 = v38->__vftable;
  v38->aiVolatile.focus.enableBodyRotation = true;
  *(_DWORD *)&result[28] = v39->GetWalkState(this: v38);
  v40 = 14;
  if ( (*((_BYTE *)&v38->aiEditable.behaviors.decl->movementBehaviors + 40) & 0x20) != 0 )
    v40 = 30;
  v79[0].mat[0].x = quat_identity.x;
  v79[0].mat[0].y = quat_identity.y;
  v79[0].mat[0].z = quat_identity.z;
  v79[0].mat[1].x = quat_identity.w;
  if ( v37 != 0 && ((*(_DWORD *)(a29 + 8) | *(_DWORD *)(a29 + 4) | *(_DWORD *)a29) & 0x7FFFFFFF) != 0 )
  {
    v41 = (idQuat *)idVec3::ToMat3(this: (idVec3 *)&v79[0].mat[2].z, result: (idMat3 *)a29);
    v42 = idMat3::ToQuat(this: (idMat3 *)&v79[0].mat[1].y, result: v41);
    v79[0].mat[0].x = v42->x;
    v40 |= 1u;
    v79[0].mat[0].y = v42->y;
    v79[0].mat[0].z = v42->z;
    v79[0].mat[1].x = v42->w;
  }
  *(_DWORD *)&result[276] = a31;
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v38) != 0 )
  {
    idAIMoveCmd::Init(
      this: (idAIMoveCmd *)&result[112],
      _userString: "w:\\tech5\\tungsten\\game\\ai\\fsm\\AIAction.cpp(883) : moveToPointNoFail");
    idAIMoveCmd::SetDest(this: (idAIMoveCmd *)&result[112], dest, entType: DEST_ENT_NONE);
    idAIMoveCmd::SetArriveRadius(this: (idAIMoveCmd *)&result[112], radius: tolerance, height: -1.0);
    if ( (v40 & 1) != 0 )
    {
      v43 = idQuat::ToMat3(this: (idQuat *)&v79[0].mat[2].z, result: v79);
      idAIMoveCmd::SetArriveOrientation(this: (idAIMoveCmd *)&result[112], orient: AIARRIVAL_ORIENT_ALIGN, axis: v43);
    }
    result[260] = (eventVoid)v38->aiConstants.movement.allowStrafing;
    idAnimBaseFSM::SetDestination(this: &v38->aiVolatile.animation.animFSM, cmd: (const idAIMoveCmd *)&result[112]);
    *(_DWORD *)&result[272] = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    goto LABEL_12;
  }
  v75.value = -1;
  v76.value = -1;
  idAI2::GetCurrentSubWebAndStateIndices(this: v38, swi: &v75, si: &v76);
  v77.value = -1;
  v78[0].value = -1;
  idAI2::GetMovementSubWebAndStateIndices(this: v38, swi: &v77, si: v78);
  Physics = idEntity::GetPhysics(this: v38);
  v46 = Physics->GetOrigin(this: Physics, a2: 0);
  idAIMoveParms::Init(
    this: (idAIMoveParms *)&result[32],
    moveReason_: moveReason,
    startOrigin_: v46,
    goalOrigin_: dest,
    goalEntity_: nullptr,
    goalOrientation_: (const idQuat *)v79,
    goalScenePoint_: nullptr,
    goalTolerance_: tolerance,
    intermediateTolerance_: 0.1,
    arrivalAction_: (const aiArrivalAction_t)v78,
    arrivalPosture_: v48,
    flags_: v49,
    sourceSubWeb_: v50,
    sourceState_: v51,
    destSubWeb_: v52,
    destState_: v53,
    a17: v54,
    a18: v55,
    a19: v56,
    a20: v57,
    a21: v58,
    a22: v59,
    a23: v60,
    a24: v61,
    a25: v62,
    a26: v63,
    a27: v64,
    a28: v65,
    a29: v66,
    a30: v67,
    a31: v68,
    a32: arrivalAction,
    a33: v69,
    a34: POSTURE_STANDING,
    a35: v70,
    a36: v40,
    a37: v71,
    a38: &v75.value,
    a39: v72,
    arrivalAction__0: &v76.value,
    a41: v73,
    arrivalPosture_a: &v77.value,
    a43: v74,
    flags_a: &v78[0].value);
  *(_DWORD *)&result[272] = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idAIMoveState::SetMoveStatus(this: &v38->aiVolatile.physics.moveState, status: 1);
  started = idAIMoveState::StartMove(
              this: &v38->aiVolatile.physics.moveState,
              parms: (const idAIMoveParms *)&result[32]);
  if ( started == 1 )
  {
LABEL_12:
    *(_DWORD *)&result[268] = 1;
    return this;
  }
  *(_DWORD *)&result[268] = 2;
  *(_DWORD *)&result[272] = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  StartIdleAnimationForMoveNoFail(ai: v38, moveNoFailStatus: (idMoveNoFailStatus *)&result[32], moveStatus: started);
  return this;
}


// ========================================================================
// ?Action_MoveToEntityEnter@idAction_MoveToEntity@@QAA?AVeventVoid@@PAVidEntity@@W4aiMoveReason_t@@PBV3@W4aiArrivalAction_t@@M_NABVidVec3@@4@Z
// EA  : 0x82AAC0D0
// RVA : 0x00AAC0D0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_MoveToEntity *__fastcall idAction_MoveToEntity::Action_MoveToEntityEnter(
        idAction_MoveToEntity *this,
        eventVoid *result,
        idAI2 *entity,
        aiMoveReason_t moveReason,
        idScenePoint *destEnt,
        aiArrivalAction_t arrivalAction,
        double tolerance,
        const bool align,
        const idVec3 *dir,
        const bool smoothTransitions,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        char a31)
{
  char v37; // r24
  idAI2 *v38; // r30
  int GameMs; // r26
  idScenePoint *curScenePoint; // r29
  idEntityPtr<idEntity const > *p_actionEntity; // r9
  int v42; // r27
  idPhysics *Physics; // r3
  float *v44; // r29
  idPhysics *v45; // r3
  float *v46; // r3
  double v47; // fp10
  double v48; // fp6
  idPhysics *v49; // r3
  idQuat *v50; // r3
  idQuat *v51; // r3
  const idMat3 *v52; // r3
  idScenePoint *v53; // r29
  idPhysics *v54; // r3
  const idVec3 *v55; // r3
  aiArrivalAction_t v56; // r10
  posture_t v58; // [sp+8h] [-208h]
  int v59; // [sp+Ch] [-204h]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v60; // [sp+10h] [-200h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v61; // [sp+14h] [-1FCh]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v62; // [sp+18h] [-1F8h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v63; // [sp+1Ch] [-1F4h]
  int v64; // [sp+20h] [-1F0h]
  int v65; // [sp+24h] [-1ECh]
  int v66; // [sp+28h] [-1E8h]
  int v67; // [sp+2Ch] [-1E4h]
  int v68; // [sp+30h] [-1E0h]
  int v69; // [sp+34h] [-1DCh]
  int v70; // [sp+38h] [-1D8h]
  int v71; // [sp+3Ch] [-1D4h]
  int v72; // [sp+40h] [-1D0h]
  int v73; // [sp+44h] [-1CCh]
  int v74; // [sp+48h] [-1C8h]
  int v75; // [sp+4Ch] [-1C4h]
  int v76; // [sp+50h] [-1C0h]
  int v77; // [sp+54h] [-1BCh]
  int v78; // [sp+58h] [-1B8h]
  int v79; // [sp+60h] [-1B0h]
  int v80; // [sp+68h] [-1A8h]
  int v81; // [sp+70h] [-1A0h]
  int v82; // [sp+78h] [-198h]
  int v83; // [sp+80h] [-190h]
  int v84; // [sp+88h] [-188h]
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v85; // [sp+90h] [-180h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v86; // [sp+92h] [-17Eh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v87; // [sp+94h] [-17Ch] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v88[5]; // [sp+96h] [-17Ah] BYREF
  idMat3 v89; // [sp+A0h] [-170h] BYREF
  idAIMoveCmd v90; // [sp+D0h] [-140h] BYREF
  idQuat v91[3]; // [sp+170h] [-A0h] BYREF

  v37 = (char)dir;
  v38 = idAI2::CastTo(c: entity);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( (unsigned __int8)idAI2::UsesScenePoints(this: v38) != 0
    && (curScenePoint = v38->aiVolatile.memory.curScenePoint) == destEnt
    && !idScenePoint::RequestScenePoint(this: v38->aiVolatile.memory.curScenePoint, user: v38, curTime: GameMs) )
  {
    idAIMemory::UpdateScenePointHistory(this: &v38->aiVolatile.memory, scenePoint: curScenePoint);
    idScenePoint::ReleaseScenePoint(this: curScenePoint, user: v38);
    v38->aiVolatile.memory.curScenePoint = nullptr;
  }
  else
  {
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v38) == 0 )
    {
      idAI2::GetDefaultMovementMode(this: v38);
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v38->aiVolatile.physics.moveState);
    }
    v38->aiVolatile.focus.enableBodyRotation = true;
    p_actionEntity = &v38->aiVolatile.memory.actionEntity;
    if ( destEnt != nullptr )
    {
      LODWORD(v89.mat[1].y) = destEnt->entityNumber;
      p_actionEntity->spawnId.value = (gameLocal->spawnIds.ptr[LODWORD(v89.mat[1].y)] << 13) | LODWORD(v89.mat[1].y);
    }
    else
    {
      p_actionEntity->spawnId.value = 0x1FFF;
    }
    *(_DWORD *)&result[28] = v38->GetWalkState(this: v38);
    v42 = 2;
    if ( (*((_BYTE *)&v38->aiEditable.behaviors.decl->movementBehaviors + 40) & 0x20) != 0 )
      v42 = 18;
    if ( v38->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType != ANIMWEBAI_RUNINDEXTYPE_INJURED )
      v42 |= 0xCu;
    Physics = idEntity::GetPhysics(this: destEnt);
    v44 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v45 = idEntity::GetPhysics(this: v38);
    v46 = (float *)v45->GetOrigin(this: v45, a2: 0);
    v47 = (float)(v46[1] - v44[1]);
    v48 = (float)(v46[2] - v44[2]);
    if ( (float)((float)((float)v48 * (float)v48)
               + (float)((float)((float)(*v46 - *v44) * (float)(*v46 - *v44)) + (float)((float)v47 * (float)v47))) < 384.0 )
      v42 |= 0x20u;
    v89.mat[0].x = quat_identity.x;
    v89.mat[0].y = quat_identity.y;
    v89.mat[0].z = quat_identity.z;
    v89.mat[1].x = quat_identity.w;
    if ( v37 == 1 )
    {
      if ( ((*(_DWORD *)(a29 + 8) | *(_DWORD *)(a29 + 4) | *(_DWORD *)a29) & 0x7FFFFFFF) != 0 )
      {
        v50 = (idQuat *)idVec3::ToMat3(this: (idVec3 *)v91, result: (idMat3 *)a29);
      }
      else
      {
        v49 = idEntity::GetPhysics(this: destEnt);
        v50 = (idQuat *)v49->GetAxis(this: v49, a2: 0);
      }
      v51 = idMat3::ToQuat(this: (idMat3 *)&v89.mat[2].z, result: v50);
      v89.mat[0].x = v51->x;
      v42 |= 1u;
      v89.mat[0].y = v51->y;
      v89.mat[0].z = v51->z;
      v89.mat[1].x = v51->w;
    }
    if ( a31 != 0 )
      v42 |= 0x40u;
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v38) != 0 )
    {
      idAIMoveCmd::idAIMoveCmd(
        this: &v90,
        user: "w:\\tech5\\tungsten\\game\\ai\\fsm\\AIAction.cpp(1076) : moveToEntity");
      idAIMoveCmd::SetDest(this: &v90, ent: destEnt, entType: DEST_ENT_NONE);
      idAIMoveCmd::SetArriveRadius(this: &v90, radius: tolerance, height: -1.0);
      if ( (v42 & 1) != 0 )
      {
        v52 = idQuat::ToMat3(this: v91, result: &v89);
        idAIMoveCmd::SetArriveOrientation(this: &v90, orient: AIARRIVAL_ORIENT_ALIGN, axis: v52);
      }
      v90.allowStrafing = v38->aiConstants.movement.allowStrafing;
      idAnimBaseFSM::SetDestination(this: &v38->aiVolatile.animation.animFSM, cmd: &v90);
      idAIMoveCmd::~idAIMoveCmd(this: &v90);
    }
    else
    {
      v87.value = -1;
      v86.value = -1;
      idAI2::GetCurrentSubWebAndStateIndices(this: v38, swi: &v87, si: &v86);
      v85.value = -1;
      v88[0].value = -1;
      idAI2::GetMovementSubWebAndStateIndices(this: v38, swi: &v85, si: v88);
      v53 = idScenePoint::CastTo(c: destEnt);
      idAIMoveParms::idAIMoveParms(this: (idAIMoveParms *)&v90);
      v54 = idEntity::GetPhysics(this: v38);
      v55 = v54->GetOrigin(this: v54, a2: 0);
      idAIMoveParms::Init(
        this: (idAIMoveParms *)&v90,
        moveReason_: moveReason,
        startOrigin_: v55,
        goalOrigin_: &vec3_origin,
        goalEntity_: destEnt,
        goalOrientation_: (const idQuat *)&v89,
        goalScenePoint_: v53,
        goalTolerance_: tolerance,
        intermediateTolerance_: 0.1,
        arrivalAction_: v56,
        arrivalPosture_: v58,
        flags_: v59,
        sourceSubWeb_: v60,
        sourceState_: v61,
        destSubWeb_: v62,
        destState_: v63,
        a17: v64,
        a18: v65,
        a19: v66,
        a20: v67,
        a21: v68,
        a22: v69,
        a23: v70,
        a24: v71,
        a25: v72,
        a26: v73,
        a27: v74,
        a28: v75,
        a29: v76,
        a30: v77,
        a31: v78,
        a32: arrivalAction,
        a33: v79,
        a34: POSTURE_STANDING,
        a35: v80,
        a36: v42,
        a37: v81,
        a38: &v87.value,
        a39: v82,
        arrivalAction__0: &v86.value,
        a41: v83,
        arrivalPosture_a: &v85.value,
        a43: v84,
        flags_a: &v88[0].value);
      idAIMoveState::StartMove(this: &v38->aiVolatile.physics.moveState, parms: (const idAIMoveParms *)&v90);
    }
  }
  return this;
}


// ========================================================================
// __unwind$516829
// EA  : 0x82AAC518
// RVA : 0x00AAC518
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_516829()
{
  int v0; // r12

  idAIMoveCmd::~idAIMoveCmd(this: (idAIMoveCmd *)(v0 - 528 + 208));
}


// ========================================================================
// ?Action_MoveToEntityNoFailEnter@idAction_MoveToEntityNoFail@@QAA?AVeventVoid@@PAVidEntity@@W4aiMoveReason_t@@PBV3@W4aiArrivalAction_t@@M_NABVidVec3@@PBVidDeclVoiceOver@@@Z
// EA  : 0x82AAC540
// RVA : 0x00AAC540
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_MoveToEntityNoFail *__fastcall idAction_MoveToEntityNoFail::Action_MoveToEntityNoFailEnter(
        idAction_MoveToEntityNoFail *this,
        eventVoid *result,
        idAI2 *entity,
        aiMoveReason_t moveReason,
        idEntity *destEnt,
        aiArrivalAction_t arrivalAction,
        double tolerance,
        const bool align,
        const idVec3 *dir,
        const idDeclVoiceOver *ptr,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31)
{
  char v37; // r29
  idAI2 *v38; // r31
  idEntityPtr<idEntity const > *p_actionEntity; // r10
  int v40; // r26
  idPhysics *Physics; // r3
  idQuat *v42; // r3
  idQuat *v43; // r3
  const idMat3 *v44; // r3
  idPhysics *v46; // r3
  const idVec3 *v47; // r3
  aiArrivalAction_t v48; // r10
  int started; // r28
  posture_t v50; // [sp+8h] [-148h]
  int v51; // [sp+Ch] [-144h]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v52; // [sp+10h] [-140h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v53; // [sp+14h] [-13Ch]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v54; // [sp+18h] [-138h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v55; // [sp+1Ch] [-134h]
  int v56; // [sp+20h] [-130h]
  int v57; // [sp+24h] [-12Ch]
  int v58; // [sp+28h] [-128h]
  int v59; // [sp+2Ch] [-124h]
  int v60; // [sp+30h] [-120h]
  int v61; // [sp+34h] [-11Ch]
  int v62; // [sp+38h] [-118h]
  int v63; // [sp+3Ch] [-114h]
  int v64; // [sp+40h] [-110h]
  int v65; // [sp+44h] [-10Ch]
  int v66; // [sp+48h] [-108h]
  int v67; // [sp+4Ch] [-104h]
  int v68; // [sp+50h] [-100h]
  int v69; // [sp+54h] [-FCh]
  int v70; // [sp+58h] [-F8h]
  int v71; // [sp+60h] [-F0h]
  int v72; // [sp+68h] [-E8h]
  int v73; // [sp+70h] [-E0h]
  int v74; // [sp+78h] [-D8h]
  int v75; // [sp+80h] [-D0h]
  int v76; // [sp+88h] [-C8h]
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v77; // [sp+90h] [-C0h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v78; // [sp+92h] [-BEh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v79; // [sp+94h] [-BCh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v80[5]; // [sp+96h] [-BAh] BYREF
  idMat3 v81[2]; // [sp+A0h] [-B0h] BYREF

  v37 = (char)dir;
  v38 = idAI2::CastTo(c: entity);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v38) == 0 )
  {
    idAI2::GetDefaultMovementMode(this: v38);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v38->aiVolatile.physics.moveState);
  }
  v38->aiVolatile.focus.enableBodyRotation = true;
  p_actionEntity = &v38->aiVolatile.memory.actionEntity;
  if ( destEnt != nullptr )
    p_actionEntity->spawnId.value = (gameLocal->spawnIds.ptr[destEnt->entityNumber] << 13) | destEnt->entityNumber;
  else
    p_actionEntity->spawnId.value = 0x1FFF;
  *(_DWORD *)&result[28] = v38->GetWalkState(this: v38);
  v40 = 14;
  if ( (*((_BYTE *)&v38->aiEditable.behaviors.decl->movementBehaviors + 40) & 0x20) != 0 )
    v40 = 30;
  v81[0].mat[0].x = quat_identity.x;
  v81[0].mat[0].y = quat_identity.y;
  v81[0].mat[0].z = quat_identity.z;
  v81[0].mat[1].x = quat_identity.w;
  if ( v37 == 1 )
  {
    if ( ((*(_DWORD *)(a29 + 8) | *(_DWORD *)(a29 + 4) | *(_DWORD *)a29) & 0x7FFFFFFF) != 0 )
    {
      v42 = (idQuat *)idVec3::ToMat3(this: (idVec3 *)&v81[0].mat[2].z, result: (idMat3 *)a29);
    }
    else
    {
      Physics = idEntity::GetPhysics(this: destEnt);
      v42 = (idQuat *)Physics->GetAxis(this: Physics, a2: 0);
    }
    v43 = idMat3::ToQuat(this: (idMat3 *)&v81[0].mat[1].y, result: v42);
    v81[0].mat[0].x = v43->x;
    v40 |= 1u;
    v81[0].mat[0].y = v43->y;
    v81[0].mat[0].z = v43->z;
    v81[0].mat[1].x = v43->w;
  }
  *(_DWORD *)&result[276] = a31;
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v38) != 0 )
  {
    idAIMoveCmd::Init(
      this: (idAIMoveCmd *)&result[112],
      _userString: "w:\\tech5\\tungsten\\game\\ai\\fsm\\AIAction.cpp(1240) : moveToEntityNoFail");
    idAIMoveCmd::SetDest(this: (idAIMoveCmd *)&result[112], ent: destEnt, entType: DEST_ENT_NONE);
    idAIMoveCmd::SetArriveRadius(this: (idAIMoveCmd *)&result[112], radius: tolerance, height: -1.0);
    if ( (v40 & 1) != 0 )
    {
      v44 = idQuat::ToMat3(this: (idQuat *)&v81[0].mat[2].z, result: v81);
      idAIMoveCmd::SetArriveOrientation(this: (idAIMoveCmd *)&result[112], orient: AIARRIVAL_ORIENT_ALIGN, axis: v44);
    }
    result[260] = (eventVoid)v38->aiConstants.movement.allowStrafing;
    idAnimBaseFSM::SetDestination(this: &v38->aiVolatile.animation.animFSM, cmd: (const idAIMoveCmd *)&result[112]);
    *(_DWORD *)&result[272] = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    goto LABEL_17;
  }
  v77.value = -1;
  v78.value = -1;
  idAI2::GetCurrentSubWebAndStateIndices(this: v38, swi: &v77, si: &v78);
  v79.value = -1;
  v80[0].value = -1;
  idAI2::GetMovementSubWebAndStateIndices(this: v38, swi: &v79, si: v80);
  v46 = idEntity::GetPhysics(this: v38);
  v47 = v46->GetOrigin(this: v46, a2: 0);
  idAIMoveParms::Init(
    this: (idAIMoveParms *)&result[32],
    moveReason_: moveReason,
    startOrigin_: v47,
    goalOrigin_: &vec3_origin,
    goalEntity_: destEnt,
    goalOrientation_: (const idQuat *)v81,
    goalScenePoint_: nullptr,
    goalTolerance_: tolerance,
    intermediateTolerance_: 0.1,
    arrivalAction_: v48,
    arrivalPosture_: v50,
    flags_: v51,
    sourceSubWeb_: v52,
    sourceState_: v53,
    destSubWeb_: v54,
    destState_: v55,
    a17: v56,
    a18: v57,
    a19: v58,
    a20: v59,
    a21: v60,
    a22: v61,
    a23: v62,
    a24: v63,
    a25: v64,
    a26: v65,
    a27: v66,
    a28: v67,
    a29: v68,
    a30: v69,
    a31: v70,
    a32: arrivalAction,
    a33: v71,
    a34: POSTURE_STANDING,
    a35: v72,
    a36: v40,
    a37: v73,
    a38: &v77.value,
    a39: v74,
    arrivalAction__0: &v78.value,
    a41: v75,
    arrivalPosture_a: &v79.value,
    a43: v76,
    flags_a: &v80[0].value);
  *(_DWORD *)&result[272] = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idAIMoveState::SetMoveStatus(this: &v38->aiVolatile.physics.moveState, status: 1);
  started = idAIMoveState::StartMove(
              this: &v38->aiVolatile.physics.moveState,
              parms: (const idAIMoveParms *)&result[32]);
  if ( started == 1 )
  {
LABEL_17:
    *(_DWORD *)&result[268] = 1;
    return this;
  }
  *(_DWORD *)&result[268] = 2;
  *(_DWORD *)&result[272] = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  StartIdleAnimationForMoveNoFail(ai: v38, moveNoFailStatus: (idMoveNoFailStatus *)&result[32], moveStatus: started);
  return this;
}


// ========================================================================
// ?Action_MoveToPathPointEnter@idAction_MoveToPathPoint@@QAA?AVeventVoid@@PAVidEntity@@W4aiMoveReason_t@@PBVidInfoPath@@@Z
// EA  : 0x82AAC8E0
// RVA : 0x00AAC8E0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_MoveToPathPoint *__fastcall idAction_MoveToPathPoint::Action_MoveToPathPointEnter(
        idAction_MoveToPathPoint *this,
        idState *result,
        idAI2 *entity,
        aiMoveReason_t moveReason,
        idInfoPath *pathPoint)
{
  idAI2 *v9; // r30
  idEntityPtr<idEntity const > *p_actionEntity; // r8
  idEntity *Focus; // r24
  idEntity *v13; // r25
  int v14; // r27
  double v15; // fp31
  idPlayer *Player; // r3
  idPlayer *v17; // r29
  idPhysics *Physics; // r21
  idPhysics *v19; // r20
  float *v20; // r21
  float *v21; // r3
  double v22; // fp10
  double v23; // fp6
  BOOL alignToNode; // r7
  idQuat *v25; // r3
  BOOL v26; // r6
  int v27; // r26
  aiArrivalAction_t v28; // r27
  idPhysics *v29; // r3
  const idVec3 *v30; // r3
  const idMat3 *v31; // r3
  idPhysics *v32; // r29
  idPhysics *v33; // r28
  const idVec3 *v34; // r29
  const idVec3 *v35; // r3
  posture_t v36; // [sp+8h] [-1F8h]
  int v37; // [sp+Ch] [-1F4h]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v38; // [sp+10h] [-1F0h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v39; // [sp+14h] [-1ECh]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v40; // [sp+18h] [-1E8h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v41; // [sp+1Ch] [-1E4h]
  int v42; // [sp+20h] [-1E0h]
  int v43; // [sp+24h] [-1DCh]
  int v44; // [sp+28h] [-1D8h]
  int v45; // [sp+2Ch] [-1D4h]
  int v46; // [sp+30h] [-1D0h]
  int v47; // [sp+34h] [-1CCh]
  int v48; // [sp+38h] [-1C8h]
  int v49; // [sp+3Ch] [-1C4h]
  int v50; // [sp+40h] [-1C0h]
  int v51; // [sp+44h] [-1BCh]
  int v52; // [sp+48h] [-1B8h]
  int v53; // [sp+4Ch] [-1B4h]
  int v54; // [sp+50h] [-1B0h]
  int v55; // [sp+54h] [-1ACh]
  int v56; // [sp+58h] [-1A8h]
  int v57; // [sp+60h] [-1A0h]
  int v58; // [sp+68h] [-198h]
  int v59; // [sp+70h] [-190h]
  int v60; // [sp+78h] [-188h]
  int v61; // [sp+80h] [-180h]
  int v62; // [sp+88h] [-178h]
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v63; // [sp+90h] [-170h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v64; // [sp+92h] [-16Eh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v65; // [sp+94h] [-16Ch] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v66; // [sp+96h] [-16Ah] BYREF
  int entityNumber; // [sp+98h] [-168h]
  idMat3 v68[4]; // [sp+A0h] [-160h] BYREF
  bool allowStrafing; // [sp+144h] [-BCh]
  idMat3 v70; // [sp+150h] [-B0h] BYREF

  v9 = idAI2::CastTo(c: entity);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v9) == 0 )
  {
    idAI2::GetDefaultMovementMode(this: v9);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v9->aiVolatile.physics.moveState);
  }
  p_actionEntity = &v9->aiVolatile.memory.actionEntity;
  if ( pathPoint != nullptr )
  {
    entityNumber = pathPoint->entityNumber;
    p_actionEntity->spawnId.value = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
    v9->SetWalkState(this: v9, a2: pathPoint->walkState);
    if ( idInfoPath::GetFocus(this: pathPoint) != nullptr )
    {
      Focus = (idEntity *)idInfoPath::GetFocus(this: pathPoint);
      if ( (unsigned __int8)idPlayerStart::IsTypeOf(c: Focus) != 0 )
      {
        v13 = nullptr;
        v14 = 0;
        v15 = 1.0e30;
        do
        {
          Player = idGameLocal::GetPlayer(this: gameLocal, i: v14);
          v17 = Player;
          if ( Player != nullptr )
          {
            Physics = idEntity::GetPhysics(this: Player);
            v19 = idEntity::GetPhysics(this: v9);
            v20 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
            v21 = (float *)v19->GetOrigin(this: v19, a2: 0);
            v22 = (float)(v21[1] - v20[1]);
            v23 = (float)(v21[2] - v20[2]);
            if ( (float)((float)((float)v23 * (float)v23)
                       + (float)((float)((float)(*v21 - *v20) * (float)(*v21 - *v20)) + (float)((float)v22 * (float)v22))) < v15 )
            {
              v15 = (float)((float)((float)v23 * (float)v23)
                          + (float)((float)((float)(*v21 - *v20) * (float)(*v21 - *v20))
                                  + (float)((float)v22 * (float)v22)));
              v13 = v17;
            }
          }
          ++v14;
        }
        while ( v14 < 6 );
        if ( v13 != nullptr )
          Focus = v13;
      }
      idAI2::SetLookFocusEntity(
        this: v9,
        ent: Focus,
        keepFocusInView: pathPoint->keepFocusInView,
        aimPoint: AIMPOINT_CENTER,
        timeout: -1);
    }
    else
    {
      idAI2::ClearLookFocus(this: v9);
    }
    alignToNode = pathPoint->alignToNode;
    v68[0].mat[0].x = quat_identity.x;
    v68[0].mat[0].y = quat_identity.y;
    v68[0].mat[0].z = quat_identity.z;
    v68[0].mat[1].x = quat_identity.w;
    if ( alignToNode )
    {
      v25 = idMat3::ToQuat(this: &v70, result: (idQuat *)&pathPoint->spawnOrientation);
      v68[0].mat[0].x = v25->x;
      v68[0].mat[0].y = v25->y;
      v68[0].mat[0].z = v25->z;
      v68[0].mat[1].x = v25->w;
    }
    v26 = pathPoint->alignToNode;
    v27 = v26 | 0xE;
    if ( (*((_BYTE *)&v9->aiEditable.behaviors.decl->movementBehaviors + 40) & 0x20) != 0 )
      v27 = v26 | 0x1E;
    v28 = ((_cntlzw(idInfoPath::StopAtPoint(this: pathPoint, ai: v9)) & 0x20) == 0) + 1;
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v9) != 0 )
    {
      idAIMoveCmd::idAIMoveCmd(
        this: (idAIMoveCmd *)&v68[0].mat[1].y,
        user: "w:\\tech5\\tungsten\\game\\ai\\fsm\\AIAction.cpp(1422) : moveToPathPoint");
      v29 = idEntity::GetPhysics(this: pathPoint);
      v30 = v29->GetOrigin(this: v29, a2: 0);
      idAIMoveCmd::SetDest(this: (idAIMoveCmd *)&v68[0].mat[1].y, dest: v30, entType: DEST_ENT_NONE);
      idAIMoveCmd::SetArriveRadius(this: (idAIMoveCmd *)&v68[0].mat[1].y, radius: 0.1, height: -1.0);
      idAIMoveCmd::SetArriveAction(this: (D3DXShader::CTokenize *)&v68[0].mat[1].y, enable: v28);
      if ( (v27 & 1) != 0 )
      {
        v31 = idQuat::ToMat3(this: (idQuat *)&v70.mat[1].y, result: v68);
        idAIMoveCmd::SetArriveOrientation(
          this: (idAIMoveCmd *)&v68[0].mat[1].y,
          orient: AIARRIVAL_ORIENT_ALIGN,
          axis: v31);
      }
      allowStrafing = v9->aiConstants.movement.allowStrafing;
      idAnimBaseFSM::SetDestination(this: &v9->aiVolatile.animation.animFSM, cmd: (const idAIMoveCmd *)&v68[0].mat[1].y);
      idAIMoveCmd::~idAIMoveCmd(this: (idAIMoveCmd *)&v68[0].mat[1].y);
    }
    else
    {
      v65.value = -1;
      v63.value = -1;
      idAI2::GetCurrentSubWebAndStateIndices(this: v9, swi: &v65, si: &v63);
      v64.value = -1;
      v66.value = -1;
      idAI2::GetMovementSubWebAndStateIndices(this: v9, swi: &v64, si: &v66);
      idAIMoveParms::idAIMoveParms(this: (idAIMoveParms *)&v68[0].mat[1].y);
      v32 = idEntity::GetPhysics(this: pathPoint);
      v33 = idEntity::GetPhysics(this: v9);
      v34 = v32->GetOrigin(this: v32, a2: 0);
      v35 = v33->GetOrigin(this: v33, a2: 0);
      idAIMoveParms::Init(
        this: (idAIMoveParms *)&v68[0].mat[1].y,
        moveReason_: moveReason,
        startOrigin_: v35,
        goalOrigin_: v34,
        goalEntity_: nullptr,
        goalOrientation_: (const idQuat *)v68,
        goalScenePoint_: nullptr,
        goalTolerance_: 0.1,
        intermediateTolerance_: 0.1,
        arrivalAction_: (const aiArrivalAction_t)&v64,
        arrivalPosture_: v36,
        flags_: v37,
        sourceSubWeb_: v38,
        sourceState_: v39,
        destSubWeb_: v40,
        destState_: v41,
        a17: v42,
        a18: v43,
        a19: v44,
        a20: v45,
        a21: v46,
        a22: v47,
        a23: v48,
        a24: v49,
        a25: v50,
        a26: v51,
        a27: v52,
        a28: v53,
        a29: v54,
        a30: v55,
        a31: v56,
        a32: v28,
        a33: v57,
        a34: POSTURE_STANDING,
        a35: v58,
        a36: v27,
        a37: v59,
        a38: &v65.value,
        a39: v60,
        arrivalAction__0: &v63.value,
        a41: v61,
        arrivalPosture_a: &v64.value,
        a43: v62,
        flags_a: &v66.value);
      idAIMoveState::StartMove(this: &v9->aiVolatile.physics.moveState, parms: (const idAIMoveParms *)&v68[0].mat[1].y);
    }
  }
  else
  {
    p_actionEntity->spawnId.value = 0x1FFF;
    idState::SetEnterFailed(this: result, failed: true);
  }
  return this;
}


// ========================================================================
// __unwind$517218
// EA  : 0x82AACD38
// RVA : 0x00AACD38
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_517218()
{
  int v0; // r12

  idAIMoveCmd::~idAIMoveCmd(this: (idAIMoveCmd *)(v0 - 512 + 176));
}


// ========================================================================
// ?Action_MoveToPathPointNoFailEnter@idAction_MoveToPathPointNoFail@@QAA?AVeventVoid@@PAVidEntity@@W4aiMoveReason_t@@PBVidInfoPath@@PBVidDeclVoiceOver@@@Z
// EA  : 0x82AACD60
// RVA : 0x00AACD60
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_MoveToPathPointNoFail *__fastcall idAction_MoveToPathPointNoFail::Action_MoveToPathPointNoFailEnter(
        idAction_MoveToPathPointNoFail *this,
        idState *result,
        idAI2 *entity,
        aiMoveReason_t moveReason,
        idInfoPath *pathPoint,
        const idDeclVoiceOver *decl)
{
  idAI2 *v11; // r31
  idEntityPtr<idEntity const > *p_actionEntity; // r9
  idEntity *Focus; // r25
  idEntity *v15; // r26
  int v16; // r27
  double v17; // fp31
  idPlayer *Player; // r3
  idPlayer *v19; // r30
  idPhysics *Physics; // r20
  idPhysics *v21; // r19
  float *v22; // r20
  float *v23; // r3
  double v24; // fp10
  double v25; // fp8
  BOOL alignToNode; // r9
  idQuat *v27; // r3
  BOOL v28; // r7
  int v29; // r26
  aiArrivalAction_t v30; // r27
  idPhysics *v31; // r3
  const idVec3 *v32; // r3
  const idMat3 *v33; // r3
  idPhysics *v34; // r30
  idPhysics *v35; // r29
  const idVec3 *v36; // r23
  const idVec3 *v37; // r3
  int started; // r29
  posture_t v39; // [sp+8h] [-168h]
  int v40; // [sp+Ch] [-164h]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v41; // [sp+10h] [-160h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v42; // [sp+14h] [-15Ch]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v43; // [sp+18h] [-158h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v44; // [sp+1Ch] [-154h]
  int v45; // [sp+20h] [-150h]
  int v46; // [sp+24h] [-14Ch]
  int v47; // [sp+28h] [-148h]
  int v48; // [sp+2Ch] [-144h]
  int v49; // [sp+30h] [-140h]
  int v50; // [sp+34h] [-13Ch]
  int v51; // [sp+38h] [-138h]
  int v52; // [sp+3Ch] [-134h]
  int v53; // [sp+40h] [-130h]
  int v54; // [sp+44h] [-12Ch]
  int v55; // [sp+48h] [-128h]
  int v56; // [sp+4Ch] [-124h]
  int v57; // [sp+50h] [-120h]
  int v58; // [sp+54h] [-11Ch]
  int v59; // [sp+58h] [-118h]
  int v60; // [sp+60h] [-110h]
  int v61; // [sp+68h] [-108h]
  int v62; // [sp+70h] [-100h]
  int v63; // [sp+78h] [-F8h]
  int v64; // [sp+80h] [-F0h]
  int v65; // [sp+88h] [-E8h]
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v66; // [sp+90h] [-E0h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v67; // [sp+92h] [-DEh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v68; // [sp+94h] [-DCh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v69[5]; // [sp+96h] [-DAh] BYREF
  idMat3 v70[2]; // [sp+A0h] [-D0h] BYREF

  v11 = idAI2::CastTo(c: entity);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v11) == 0 )
  {
    idAI2::GetDefaultMovementMode(this: v11);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v11->aiVolatile.physics.moveState);
  }
  p_actionEntity = &v11->aiVolatile.memory.actionEntity;
  if ( pathPoint != nullptr )
  {
    p_actionEntity->spawnId.value = (gameLocal->spawnIds.ptr[pathPoint->entityNumber] << 13) | pathPoint->entityNumber;
    v11->SetWalkState(this: v11, a2: pathPoint->walkState);
    if ( idInfoPath::GetFocus(this: pathPoint) != nullptr )
    {
      Focus = (idEntity *)idInfoPath::GetFocus(this: pathPoint);
      if ( (unsigned __int8)idPlayerStart::IsTypeOf(c: Focus) != 0 )
      {
        v15 = nullptr;
        v16 = 0;
        v17 = 1.0e30;
        do
        {
          Player = idGameLocal::GetPlayer(this: gameLocal, i: v16);
          v19 = Player;
          if ( Player != nullptr )
          {
            Physics = idEntity::GetPhysics(this: Player);
            v21 = idEntity::GetPhysics(this: v11);
            v22 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
            v23 = (float *)v21->GetOrigin(this: v21, a2: 0);
            v24 = (float)(v23[1] - v22[1]);
            v25 = (float)(v23[2] - v22[2]);
            if ( (float)((float)((float)(*v23 - *v22) * (float)(*v23 - *v22))
                       + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) < v17 )
            {
              v17 = (float)((float)((float)(*v23 - *v22) * (float)(*v23 - *v22))
                          + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)));
              v15 = v19;
            }
          }
          ++v16;
        }
        while ( v16 < 6 );
        if ( v15 != nullptr )
          Focus = v15;
      }
      idAI2::SetLookFocusEntity(
        this: v11,
        ent: Focus,
        keepFocusInView: pathPoint->keepFocusInView,
        aimPoint: AIMPOINT_CENTER,
        timeout: -1);
    }
    else
    {
      idAI2::ClearLookFocus(this: v11);
    }
    *(_DWORD *)&result[9].enterFailed = decl;
    alignToNode = pathPoint->alignToNode;
    v70[0].mat[0].y = quat_identity.y;
    v70[0].mat[0].x = quat_identity.x;
    v70[0].mat[0].z = quat_identity.z;
    v70[0].mat[1].x = quat_identity.w;
    if ( alignToNode )
    {
      v27 = idMat3::ToQuat(this: (idMat3 *)&v70[0].mat[1].y, result: (idQuat *)&pathPoint->spawnOrientation);
      v70[0].mat[0].x = v27->x;
      v70[0].mat[0].y = v27->y;
      v70[0].mat[0].z = v27->z;
      v70[0].mat[1].x = v27->w;
    }
    v28 = pathPoint->alignToNode;
    v29 = v28 | 0xE;
    if ( (*((_BYTE *)&v11->aiEditable.behaviors.decl->movementBehaviors + 40) & 0x20) != 0 )
      v29 = v28 | 0x1E;
    v30 = ((_cntlzw(idInfoPath::StopAtPoint(this: pathPoint, ai: v11)) & 0x20) == 0) + 1;
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v11) != 0 )
    {
      idAIMoveCmd::Init(
        this: (idAIMoveCmd *)&result[4],
        _userString: "w:\\tech5\\tungsten\\game\\ai\\fsm\\AIAction.cpp(1587) : moveToPathPointNoFail");
      v31 = idEntity::GetPhysics(this: pathPoint);
      v32 = v31->GetOrigin(this: v31, a2: 0);
      idAIMoveCmd::SetDest(this: (idAIMoveCmd *)&result[4], dest: v32, entType: DEST_ENT_NONE);
      idAIMoveCmd::SetArriveRadius(this: (idAIMoveCmd *)&result[4], radius: 0.1, height: -1.0);
      idAIMoveCmd::SetArriveAction(this: (D3DXShader::CTokenize *)&result[4], enable: v30);
      if ( (v29 & 1) != 0 )
      {
        v33 = idQuat::ToMat3(this: (idQuat *)&v70[0].mat[2].z, result: v70);
        idAIMoveCmd::SetArriveOrientation(this: (idAIMoveCmd *)&result[4], orient: AIARRIVAL_ORIENT_ALIGN, axis: v33);
      }
      HIBYTE(result[9].listeningToList) = v11->aiConstants.movement.allowStrafing;
      idAnimBaseFSM::SetDestination(this: &v11->aiVolatile.animation.animFSM, cmd: (const idAIMoveCmd *)&result[4]);
      result[9].childFSM = (idFiniteStateMachine *)gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      result[9].childFSMType = (const idTypeInfo *)1;
      return this;
    }
    else
    {
      v66.value = -1;
      v67.value = -1;
      idAI2::GetCurrentSubWebAndStateIndices(this: v11, swi: &v66, si: &v67);
      v68.value = -1;
      v69[0].value = -1;
      idAI2::GetMovementSubWebAndStateIndices(this: v11, swi: &v68, si: v69);
      v34 = idEntity::GetPhysics(this: pathPoint);
      v35 = idEntity::GetPhysics(this: v11);
      v36 = v34->GetOrigin(this: v34, a2: 0);
      v37 = v35->GetOrigin(this: v35, a2: 0);
      idAIMoveParms::Init(
        this: (idAIMoveParms *)&result[1].listenerList,
        moveReason_: moveReason,
        startOrigin_: v37,
        goalOrigin_: v36,
        goalEntity_: nullptr,
        goalOrientation_: (const idQuat *)v70,
        goalScenePoint_: nullptr,
        goalTolerance_: 0.1,
        intermediateTolerance_: 0.1,
        arrivalAction_: (const aiArrivalAction_t)&v68,
        arrivalPosture_: v39,
        flags_: v40,
        sourceSubWeb_: v41,
        sourceState_: v42,
        destSubWeb_: v43,
        destState_: v44,
        a17: v45,
        a18: v46,
        a19: v47,
        a20: v48,
        a21: v49,
        a22: v50,
        a23: v51,
        a24: v52,
        a25: v53,
        a26: v54,
        a27: v55,
        a28: v56,
        a29: v57,
        a30: v58,
        a31: v59,
        a32: v30,
        a33: v60,
        a34: POSTURE_STANDING,
        a35: v61,
        a36: v29,
        a37: v62,
        a38: &v66.value,
        a39: v63,
        arrivalAction__0: &v67.value,
        a41: v64,
        arrivalPosture_a: &v68.value,
        a43: v65,
        flags_a: &v69[0].value);
      result[9].childFSM = (idFiniteStateMachine *)gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      idAIMoveState::SetMoveStatus(this: &v11->aiVolatile.physics.moveState, status: 1);
      started = idAIMoveState::StartMove(
                  this: &v11->aiVolatile.physics.moveState,
                  parms: (const idAIMoveParms *)&result[1].listenerList);
      if ( started == 1 )
      {
        result[9].childFSMType = (const idTypeInfo *)1;
      }
      else
      {
        result[9].childFSMType = (const idTypeInfo *)2;
        result[9].childFSM = (idFiniteStateMachine *)gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        StartIdleAnimationForMoveNoFail(
          ai: v11,
          moveNoFailStatus: (idMoveNoFailStatus *)&result[1].listenerList,
          moveStatus: started);
      }
      return this;
    }
  }
  else
  {
    p_actionEntity->spawnId.value = 0x1FFF;
    idState::SetEnterFailed(this: result, failed: true);
    return this;
  }
}


// ========================================================================
// ?Action_MoveToCoverEnter@idAction_MoveToCover@@QAA?AVeventVoid@@PAVidEntity@@W4aiMoveReason_t@@ABVidVec3@@W4aiArrivalAction_t@@W4posture_t@@_N2@Z
// EA  : 0x82AAD280
// RVA : 0x00AAD280
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_MoveToCover *__fastcall idAction_MoveToCover::Action_MoveToCoverEnter(
        idAction_MoveToCover *this,
        eventVoid *result,
        idAI2 *entity,
        aiMoveReason_t moveReason,
        const idVec3 *dest,
        aiArrivalAction_t arrivalAction,
        posture_t arrivalPosture,
        const bool align,
        const idVec3 *dir,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  idAI2 *v34; // r30
  const idDeclAIBehavior *decl; // r11
  int v36; // r28
  idQuat *v37; // r3
  idQuat *v38; // r3
  const idMat3 *v39; // r3
  const char *v40; // r28
  bool allowStrafing; // r10
  idAnimWebState *v42; // r29
  idAIAnimWebState *v43; // r3
  float *p_destAnimUpdateDistanceMinSqr; // r10
  idAtomicString *p_debugState; // r11
  int i; // ctr
  idPhysics *Physics; // r3
  const idVec3 *v48; // r3
  posture_t v50; // [sp+8h] [-238h]
  int v51; // [sp+Ch] [-234h]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v52; // [sp+10h] [-230h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v53; // [sp+14h] [-22Ch]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v54; // [sp+18h] [-228h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v55; // [sp+1Ch] [-224h]
  int v56; // [sp+20h] [-220h]
  int v57; // [sp+24h] [-21Ch]
  int v58; // [sp+28h] [-218h]
  int v59; // [sp+2Ch] [-214h]
  int v60; // [sp+30h] [-210h]
  int v61; // [sp+34h] [-20Ch]
  int v62; // [sp+38h] [-208h]
  int v63; // [sp+3Ch] [-204h]
  int v64; // [sp+40h] [-200h]
  int v65; // [sp+44h] [-1FCh]
  int v66; // [sp+48h] [-1F8h]
  int v67; // [sp+4Ch] [-1F4h]
  int v68; // [sp+50h] [-1F0h]
  int v69; // [sp+54h] [-1ECh]
  int v70; // [sp+58h] [-1E8h]
  int v71; // [sp+60h] [-1E0h]
  int v72; // [sp+68h] [-1D8h]
  int v73; // [sp+70h] [-1D0h]
  int v74; // [sp+78h] [-1C8h]
  int v75; // [sp+80h] [-1C0h]
  int v76; // [sp+88h] [-1B8h]
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v77; // [sp+90h] [-1B0h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v78; // [sp+92h] [-1AEh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v79; // [sp+94h] [-1ACh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v80[5]; // [sp+96h] [-1AAh] BYREF
  idMat3 v81; // [sp+A0h] [-1A0h] BYREF
  idStr v82; // [sp+D0h] [-170h] BYREF
  idAIAnimWebState v83; // [sp+F0h] [-150h] BYREF
  idAIMoveCmd v84; // [sp+110h] [-130h] BYREF
  idMat3 v85; // [sp+1B0h] [-90h] BYREF

  v34 = idAI2::CastTo(c: entity);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v34) == 0 )
  {
    idAI2::GetDefaultMovementMode(this: v34);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v34->aiVolatile.physics.moveState);
  }
  decl = v34->aiEditable.behaviors.decl;
  v36 = 2;
  v34->aiVolatile.focus.enableBodyRotation = true;
  if ( (*((_BYTE *)&decl->movementBehaviors + 40) & 0x20) != 0 )
    v36 = 18;
  if ( v34->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType != ANIMWEBAI_RUNINDEXTYPE_INJURED )
    v36 |= 0xCu;
  v81.mat[0].x = quat_identity.x;
  v81.mat[0].y = quat_identity.y;
  v81.mat[0].z = quat_identity.z;
  v81.mat[1].x = quat_identity.w;
  if ( align && ((*(_DWORD *)(a28 + 8) | *(_DWORD *)(a28 + 4) | *(_DWORD *)a28) & 0x7FFFFFFF) != 0 )
  {
    v37 = (idQuat *)idVec3::ToMat3(this: (idVec3 *)&v85.mat[1].y, result: (idMat3 *)a28);
    v38 = idMat3::ToQuat(this: &v85, result: v37);
    v81.mat[0].x = v38->x;
    v36 |= 1u;
    v81.mat[0].y = v38->y;
    v81.mat[0].z = v38->z;
    v81.mat[1].x = v38->w;
  }
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v34) != 0 )
  {
    idAIMoveCmd::idAIMoveCmd(this: &v84, user: "w:\\tech5\\tungsten\\game\\ai\\fsm\\AIAction.cpp(1750) : moveToCover");
    idAIMoveCmd::SetDest(this: &v84, dest, entType: DEST_ENT_NONE);
    idAIMoveCmd::SetArriveRadius(this: &v84, radius: 2.0, height: -1.0);
    if ( (v36 & 1) != 0 )
    {
      v39 = idQuat::ToMat3(this: (idQuat *)&v85.mat[1].y, result: &v81);
      idAIMoveCmd::SetArriveOrientation(this: &v84, orient: AIARRIVAL_ORIENT_ALIGN, axis: v39);
    }
    v40 = "$weaponfcover:idle";
    if ( idAICover::GetCoverPosture(this: &v34->aiVolatile.memory.currentCover) == 2 )
      v40 = "$weaponfcover:idle_crouch";
    allowStrafing = v34->aiConstants.movement.allowStrafing;
    v42 = nullptr;
    v81.mat[1].y = 0.0;
    LODWORD(v81.mat[2].x) = 20;
    LODWORD(v81.mat[1].z) = &v81.mat[2].y;
    v84.allowStrafing = allowStrafing;
    HIBYTE(v81.mat[2].y) = 0;
    v82.allocedAndFlag = 20;
    v82.data = v82.baseBuffer;
    v82.len = 0;
    v82.baseBuffer[0] = 0;
    idAI2::GetSubWebAndStateFromAnimWebPath(
      this: v34,
      animWebPath: v40,
      subWebName: (idStr *)&v81.mat[1].y,
      stateName: &v82);
    v43 = idAIAnimWebState::idAIAnimWebState(
            this: &v83,
            ai: v34,
            subwebName: (const char *)LODWORD(v81.mat[1].z),
            stateName: v82.data);
    if ( v43 != nullptr )
      v42 = &v43->idAnimWebState;
    p_destAnimUpdateDistanceMinSqr = &v84.destAnimUpdateDistanceMinSqr;
    p_debugState = &v42[-1].debugState;
    for ( i = 5; i != 0; --i )
    {
      ++p_debugState;
      *++p_destAnimUpdateDistanceMinSqr = *(float *)&p_debugState->str;
    }
    v83.__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
    idAnimBaseFSM::SetDestination(this: &v34->aiVolatile.animation.animFSM, cmd: &v84);
    idStr::FreeData(this: &v82);
    idStr::FreeData(this: (idStr *)&v81.mat[1].y);
    idAIMoveCmd::~idAIMoveCmd(this: &v84);
  }
  else
  {
    v79.value = -1;
    v77.value = -1;
    idAI2::GetCurrentSubWebAndStateIndices(this: v34, swi: &v79, si: &v77);
    v78.value = -1;
    v80[0].value = -1;
    idAI2::GetMovementSubWebAndStateIndices(this: v34, swi: &v78, si: v80);
    idAIMoveParms::idAIMoveParms(this: (idAIMoveParms *)&v84);
    Physics = idEntity::GetPhysics(this: v34);
    v48 = Physics->GetOrigin(this: Physics, a2: 0);
    idAIMoveParms::Init(
      this: (idAIMoveParms *)&v84,
      moveReason_: moveReason,
      startOrigin_: v48,
      goalOrigin_: dest,
      goalEntity_: nullptr,
      goalOrientation_: (const idQuat *)&v81,
      goalScenePoint_: nullptr,
      goalTolerance_: 2.0,
      intermediateTolerance_: 0.1,
      arrivalAction_: (const aiArrivalAction_t)v80,
      arrivalPosture_: v50,
      flags_: v51,
      sourceSubWeb_: v52,
      sourceState_: v53,
      destSubWeb_: v54,
      destState_: v55,
      a17: v56,
      a18: v57,
      a19: v58,
      a20: v59,
      a21: v60,
      a22: v61,
      a23: v62,
      a24: v63,
      a25: v64,
      a26: v65,
      a27: v66,
      a28: v67,
      a29: v68,
      a30: v69,
      a31: v70,
      a32: arrivalAction,
      a33: v71,
      a34: arrivalPosture,
      a35: v72,
      a36: v36,
      a37: v73,
      a38: &v79.value,
      a39: v74,
      arrivalAction__0: &v77.value,
      a41: v75,
      arrivalPosture_a: &v78.value,
      a43: v76,
      flags_a: &v80[0].value);
    idAIMoveState::StartMove(this: &v34->aiVolatile.physics.moveState, parms: (const idAIMoveParms *)&v84);
    v34->aiVolatile.physics.moveState.remainingTransitionFrames = 0;
  }
  return this;
}


// ========================================================================
// __unwind$517590
// EA  : 0x82AAD5E0
// RVA : 0x00AAD5E0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_517590()
{
  int v0; // r12

  idAIMoveCmd::~idAIMoveCmd(this: (idAIMoveCmd *)(v0 - 576 + 272));
}


// ========================================================================
// __unwind$517591
// EA  : 0x82AAD608
// RVA : 0x00AAD608
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_517591()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 176));
}


// ========================================================================
// __unwind$517592
// EA  : 0x82AAD630
// RVA : 0x00AAD630
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_517592()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 208));
}


// ========================================================================
// ?Action_UseZiplineEnter@idAction_UseZipline@@QAA?AVeventVoid@@PAVidEntity@@0@Z
// EA  : 0x82AAD658
// RVA : 0x00AAD658
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_UseZipline *__fastcall idAction_UseZipline::Action_UseZiplineEnter(
        idAction_UseZipline *this,
        eventVoid *result,
        idAI2 *entity,
        idEntity *destEnt)
{
  idEntityPtr<idEntity> *p_usedProp; // r9
  idAction_UseZipline *v7; // r3

  p_usedProp = &idAI2::CastTo(c: entity)->aiVolatile.memory.usedProp;
  v7 = this;
  if ( destEnt != nullptr )
    p_usedProp->spawnId.value = (gameLocal->spawnIds.ptr[destEnt->entityNumber] << 13) | destEnt->entityNumber;
  else
    p_usedProp->spawnId.value = 0x1FFF;
  return v7;
}


// ========================================================================
// ?AIAction_ExitState@idAction_Melee@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AAD6D8
// RVA : 0x00AAD6D8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_Melee::AIAction_ExitState(idAction_Melee *this, idAI2 *ai, idAIFSM *fsm, const int curTime)
{
  aiSenseState_t *EnemySenseState; // r3
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  float y; // r9
  float z; // r8
  idPhysics *Physics; // r3
  float *v10; // r3
  double v11; // fp11
  double v12; // fp10
  double v13; // fp0
  double v15; // fp2
  double v17; // fp12
  double v18; // fp10
  double v19; // fp3
  double v20; // fp2
  idAIOrientation *BodyOrientation; // r3
  idVec3 v22; // [sp+50h] [-30h] BYREF
  float x; // [sp+60h] [-20h]
  float v24; // [sp+64h] [-1Ch]
  float v25; // [sp+68h] [-18h]

  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) == 0 )
  {
    idAI2::GetDefaultMovementMode(this: ai);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&ai->aiVolatile.physics.moveState);
  }
  EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  if ( EnemySenseState != nullptr )
  {
    ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
    y = ConfirmedPhysicalSafe->origin.y;
    z = ConfirmedPhysicalSafe->origin.z;
    x = ConfirmedPhysicalSafe->origin.x;
    v24 = y;
    v25 = z;
    Physics = idEntity::GetPhysics(this: ai);
    v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v11 = (float)(v24 - v10[1]);
    v12 = (float)(v25 - v10[2]);
    v13 = (float)(x - *v10);
    v24 = v24 - v10[1];
    v25 = v12;
    x = v13;
    _FP3 = (float)((float)((float)((float)v13 * (float)v13)
                         + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v15 = (float)((float)((float)((float)v13 * (float)v13)
                        + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                * (float)0.5);
    __asm { fsel      f1, f3, f4, f12 }
    v17 = __frsqrte(_FP1);
    v18 = (float)((float)v17
                * (float)((float)((float)((float)v13 * (float)v13)
                                + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                        * (float)0.5));
    v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v18 * (float)v17) - (float)1.5)
                                                        * (float)v17)
                                                * (float)v15)
                                        * (float)((float)-(float)((float)((float)v18 * (float)v17) - (float)1.5)
                                                * (float)v17))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)v18 * (float)v17) - (float)1.5) * (float)v17));
    v20 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v18 * (float)v17)
                                                                                - (float)1.5)
                                                                * (float)v17)
                                                        * (float)v15)
                                                * (float)((float)-(float)((float)((float)v18 * (float)v17) - (float)1.5)
                                                        * (float)v17))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)v18 * (float)v17) - (float)1.5) * (float)v17))
                * (float)v15);
    v22.x = (float)v13 * (float)((float)-(float)((float)((float)v20 * (float)v19) - (float)1.5) * (float)v19);
    v22.y = v24 * (float)((float)-(float)((float)((float)v20 * (float)v19) - (float)1.5) * (float)v19);
    v22.z = v25 * (float)((float)-(float)((float)((float)v20 * (float)v19) - (float)1.5) * (float)v19);
    BodyOrientation = idAI2::GetBodyOrientation(this: ai);
    idAIOrientation::SetIdealDir(this: BodyOrientation, ai, dir: &v22);
  }
}


// ========================================================================
// ?Action_TurnToEntityEnter@idAction_TurnToEntity@@QAA?AVeventVoid@@PAVidEntity@@PBV3@@Z
// EA  : 0x82AAD858
// RVA : 0x00AAD858
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_TurnToEntity *__fastcall idAction_TurnToEntity::Action_TurnToEntityEnter(
        idAction_TurnToEntity *this,
        idState *result,
        idAI2 *entity,
        idEntity *ent)
{
  idAI2 *v7; // r31
  idPhysics *Physics; // r3
  const idVec3 *v9; // r3
  int v10; // r3

  v7 = idAI2::CastTo(c: entity);
  if ( ent == nullptr
    || (v7->aiVolatile.memory.actionEntity.spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13)
                                                         | ent->entityNumber,
        v7->aiVolatile.focus.enableBodyRotation = true,
        Physics = idEntity::GetPhysics(this: ent),
        v9 = Physics->GetOrigin(this: Physics, a2: 0),
        v10 = TurnToPoint(ai: v7, point: v9),
        result[1].__vftable = (idState_vtbl *)v10,
        v10 == 2) )
  {
    idState::SetEnterFailed(this: result, failed: true);
  }
  return this;
}


// ========================================================================
// ?Action_TurnToEntityWithOffsetEnter@idAction_TurnToEntityWithOffset@@QAA?AVeventVoid@@PAVidEntity@@PBV3@M@Z
// EA  : 0x82AAD908
// RVA : 0x00AAD908
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_TurnToEntityWithOffset *__fastcall idAction_TurnToEntityWithOffset::Action_TurnToEntityWithOffsetEnter(
        idAction_TurnToEntityWithOffset *this,
        idState *result,
        idAI2 *entity,
        idEntity *ent,
        double yawOffset)
{
  idAI2 *v9; // r3
  idAI2 *v10; // r31
  idPhysics *Physics; // r3
  float *v12; // r27
  idPhysics *v13; // r3
  float *v14; // r3
  double v15; // fp13
  double v16; // fp12
  double v17; // fp0
  double v18; // fp6
  double v19; // fp12
  double v20; // fp11
  int v21; // r3
  idTypesafeNumber<float,enum DegreesUnique_t> v23; // [sp+50h] [-60h] BYREF
  idVec3 v24; // [sp+58h] [-58h] BYREF
  idVec3 v25; // [sp+68h] [-48h] BYREF

  v9 = idAI2::CastTo(c: entity);
  v10 = v9;
  if ( ent == nullptr )
    goto LABEL_3;
  v9->aiVolatile.memory.actionEntity.spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13)
                                                   | ent->entityNumber;
  v9->aiVolatile.focus.enableBodyRotation = true;
  Physics = idEntity::GetPhysics(this: v9);
  v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v13 = idEntity::GetPhysics(this: ent);
  v14 = (float *)v13->GetOrigin(this: v13, a2: 0);
  v15 = *v12;
  v16 = v12[1];
  v17 = v12[2];
  v23.value = yawOffset;
  v18 = (float)(v14[1] - (float)v16);
  v25.x = *v14 - (float)v15;
  v25.y = v18;
  v25.z = v14[2] - (float)v17;
  v24 = v25;
  idVec3::RotateSelf(this: &v24, axis: &vec3_up, angle: &v23);
  v19 = (float)(v12[1] + v24.y);
  v20 = (float)(v24.z + v12[2]);
  v25.x = *v12 + v24.x;
  v25.y = v19;
  v25.z = v20;
  v21 = TurnToPoint(ai: v10, point: &v25);
  result[1].__vftable = (idState_vtbl *)v21;
  if ( v21 == 2 )
LABEL_3:
    idState::SetEnterFailed(this: result, failed: true);
  return this;
}


// ========================================================================
// ?Action_WaitForEntityEnter@idAction_WaitForEntity@@QAA?AVeventVoid@@PAVidEntity@@PBV3@M@Z
// EA  : 0x82AADA70
// RVA : 0x00AADA70
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_WaitForEntity *__fastcall idAction_WaitForEntity::Action_WaitForEntityEnter(
        idAction_WaitForEntity *this,
        eventVoid *result,
        idAI2 *entity,
        const idEntity *ent,
        double distance)
{
  idAI2 *v9; // r3
  idEntityPtr<idEntity const > *p_actionEntity; // r9
  idAction_WaitForEntity *v11; // r3

  v9 = idAI2::CastTo(c: entity);
  *(float *)&result[32] = distance;
  *(_DWORD *)&result[28] = ent;
  p_actionEntity = &v9->aiVolatile.memory.actionEntity;
  v11 = this;
  if ( ent != nullptr )
    p_actionEntity->spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
  else
    p_actionEntity->spawnId.value = 0x1FFF;
  return v11;
}


// ========================================================================
// ?Action_EnterVehicleEnter@idAction_EnterVehicle@@QAA?AVeventVoid@@PAVidEntity@@PAVidVehicle@@0@Z
// EA  : 0x82AADAF8
// RVA : 0x00AADAF8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_EnterVehicle *__fastcall idAction_EnterVehicle::Action_EnterVehicleEnter(
        idAction_EnterVehicle *this,
        eventVoid *result,
        idAI2 *entity,
        idVehicle *vehicle,
        idVehicleAI *vehicleAI)
{
  idAI2 *v8; // r31
  idVehicleAI *v9; // r3
  idVehicleAI *v10; // r29

  v8 = idAI2::CastTo(c: entity);
  v9 = idVehicleAI::CastTo(c: vehicleAI);
  v10 = v9;
  if ( vehicle != nullptr )
  {
    if ( v9 != nullptr )
    {
      v8->aiVolatile.memory.actionEntity.spawnId.value = (gameLocal->spawnIds.ptr[vehicle->entityNumber] << 13)
                                                       | vehicle->entityNumber;
      idEntity::Activate(this: v9, activator: v8);
      idVehicle::AttachNpcToVai(this: vehicle, npc: v8, vai: v10);
    }
    else
    {
      idLib::Warning(fmt: "idAction_EnterVehicle with NULL vehicleAI argument, ignoring");
    }
    return this;
  }
  else
  {
    idLib::Warning(fmt: "idAction_EnterVehicle with NULL vehicle argument, ignoring");
    return this;
  }
}


// ========================================================================
// ?AIAction_ExitState@idAction_PlayOverrideAnimInterrupt@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AADBC0
// RVA : 0x00AADBC0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_PlayOverrideAnimInterrupt::AIAction_ExitState(
        idAction_PlayOverrideAnimInterrupt *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) == 0 )
  {
    idAI2::GetDefaultMovementMode(this: ai);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&ai->aiVolatile.physics.moveState);
  }
  idAI2::ClearWaitForOverrideAnim(this: ai, priority: PRIORITY_LOW);
}


// ========================================================================
// ?AIAction_ExitState@idAction_LeapAttack@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AADC20
// RVA : 0x00AADC20
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_LeapAttack::AIAction_ExitState(
        idAction_LeapAttack *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  aiSenseState_t *EnemySenseState; // r3
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  float y; // r9
  float z; // r8
  idPhysics *Physics; // r3
  float *v10; // r3
  double v11; // fp11
  double v12; // fp10
  double v13; // fp0
  double v15; // fp2
  double v17; // fp12
  double v18; // fp10
  double v19; // fp3
  double v20; // fp2
  idAIOrientation *BodyOrientation; // r3
  idVec3 v22; // [sp+50h] [-40h] BYREF
  float x; // [sp+60h] [-30h]
  float v24; // [sp+64h] [-2Ch]
  float v25; // [sp+68h] [-28h]

  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) == 0 )
  {
    idAI2::GetDefaultMovementMode(this: ai);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&ai->aiVolatile.physics.moveState);
    idAIMoveState::SetMoveStatus(this: &ai->aiVolatile.physics.moveState, status: 0);
  }
  EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  if ( EnemySenseState != nullptr )
  {
    ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
    y = ConfirmedPhysicalSafe->origin.y;
    z = ConfirmedPhysicalSafe->origin.z;
    x = ConfirmedPhysicalSafe->origin.x;
    v24 = y;
    v25 = z;
    Physics = idEntity::GetPhysics(this: ai);
    v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v11 = (float)(v24 - v10[1]);
    v12 = (float)(v25 - v10[2]);
    v13 = (float)(x - *v10);
    v24 = v24 - v10[1];
    v25 = v12;
    x = v13;
    _FP3 = (float)((float)((float)((float)v13 * (float)v13)
                         + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v15 = (float)((float)((float)((float)v13 * (float)v13)
                        + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                * (float)0.5);
    __asm { fsel      f1, f3, f4, f12 }
    v17 = __frsqrte(_FP1);
    v18 = (float)((float)v17
                * (float)((float)((float)((float)v13 * (float)v13)
                                + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                        * (float)0.5));
    v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v18 * (float)v17) - (float)1.5)
                                                        * (float)v17)
                                                * (float)v15)
                                        * (float)((float)-(float)((float)((float)v18 * (float)v17) - (float)1.5)
                                                * (float)v17))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)v18 * (float)v17) - (float)1.5) * (float)v17));
    v20 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v18 * (float)v17)
                                                                                - (float)1.5)
                                                                * (float)v17)
                                                        * (float)v15)
                                                * (float)((float)-(float)((float)((float)v18 * (float)v17) - (float)1.5)
                                                        * (float)v17))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)v18 * (float)v17) - (float)1.5) * (float)v17))
                * (float)v15);
    v22.x = (float)v13 * (float)((float)-(float)((float)((float)v20 * (float)v19) - (float)1.5) * (float)v19);
    v22.y = v24 * (float)((float)-(float)((float)((float)v20 * (float)v19) - (float)1.5) * (float)v19);
    v22.z = v25 * (float)((float)-(float)((float)((float)v20 * (float)v19) - (float)1.5) * (float)v19);
    BodyOrientation = idAI2::GetBodyOrientation(this: ai);
    idAIOrientation::SetIdealDir(this: BodyOrientation, ai, dir: &v22);
  }
  idAI2::ClearWaitForOverrideAnim(this: ai, priority: PRIORITY_LOW);
}


// ========================================================================
// ?AIAction_ExitState@idAction_WaitForPlayerInteraction@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AADDC0
// RVA : 0x00AADDC0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_WaitForPlayerInteraction::AIAction_ExitState(
        idAction_WaitForPlayerInteraction *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  ai->aiVolatile.memory.triggeredInteraction.spawnId.value = 0x1FFF;
  ai->aiVolatile.memory.interactionIsUsable = false;
}


// ========================================================================
// ?AIAction_ExitState@idAction_PerfectMovement@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AADDE8
// RVA : 0x00AADDE8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAction_PerfectMovement::AIAction_ExitState(
        idAction_PerfectMovement *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  aiMovementMode_t DefaultMovementMode; // r3

  ai->aiVolatile.focus.enableBodyRotation = true;
  DefaultMovementMode = idAI2::GetDefaultMovementMode(this: ai);
  idAIMoveState::SetMovementModeForReal(this: &ai->aiVolatile.physics.moveState, mode: DefaultMovementMode);
  if ( (unsigned __int16)this->swiWhenFinished.value < 0x8000u )
    idAI2::ChangeAnimState(
      this: ai,
      web: AIANIMWEB_BODY,
      subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->swiWhenFinished.value,
      stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->siWhenFinished.value,
      interruptPath: INTR_PATH_YES,
      interruptBlend: INTR_BLEND_NO);
}


// ========================================================================
// ?Action_ScriptedAnimWebEnter@idAction_ScriptedAnimWeb@@QAA?AVeventVoid@@PAVidEntity@@0H@Z
// EA  : 0x82AADE60
// RVA : 0x00AADE60
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_ScriptedAnimWeb *__fastcall idAction_ScriptedAnimWeb::Action_ScriptedAnimWebEnter(
        idAction_ScriptedAnimWeb *this,
        idAction_ScriptedAnimWeb *result,
        idAI2 *entity,
        idAIScriptedAnimWeb *entityPtr,
        int loopInterval_)
{
  idAI2 *v9; // r3
  idAI2 *v10; // r28
  eventVoid v11; // r7
  char v12; // r10
  idPhysics *Physics; // r3
  int v14; // r3
  eventVoid v15; // r8
  idAIScriptedAnimWeb *v16; // r30
  idInfoPath *v17; // r3
  idAIScriptedAnimWeb::animState_t *stateInfo; // r11
  idPhysics *v19; // r3
  float *v20; // r3
  idPhysics *v21; // r3
  idQuat *v22; // r3
  idMat3 v24[2]; // [sp+50h] [-60h] BYREF

  v9 = idAI2::CastTo(c: entity);
  result->currentScriptState = 0;
  v10 = v9;
  result->nextTargetPosition.x = vec3_origin.x;
  result->nextTargetPosition.y = vec3_origin.y;
  result->nextTargetPosition.z = vec3_origin.z;
  result->nextTargetRotation.x = quat_identity.x;
  result->nextTargetRotation.y = quat_identity.y;
  result->nextTargetRotation.z = quat_identity.z;
  result->nextTargetRotation.w = quat_identity.w;
  result->stateStartTime = 0;
  v11 = *((eventVoid *)result + 84);
  result->loopInterval = loopInterval_;
  *((_BYTE *)result + 84) = *(_BYTE *)&v11 & 0x7F;
  if ( !v9->walkIK.enabled || (v12 = 1, v9->walkIK.enabledLegs == 0) )
    v12 = 0;
  *((_BYTE *)result + 84) = (v12 << 6) & 0x40 | *(_BYTE *)&v11 & 0x3F;
  result->wasHeadTrackingEnabled = idAI2::GetEnableHeadTracking(this: v9);
  Physics = idEntity::GetPhysics(this: v10);
  v14 = Physics->GetContents(this: Physics, a2: -1);
  v15 = *((eventVoid *)result + 84);
  result->currentLoopCount = 0;
  result->stateInfo = nullptr;
  result->movementMode = AIMOVEMODE_GROUND;
  result->wasSolid = v14 != 0;
  *((_BYTE *)result + 84) = *(_BYTE *)&v15 & 0xDF;
  v16 = idAIScriptedAnimWeb::CastTo(c: entityPtr);
  v17 = idInfoPath::CastTo(c: (idInfoPath *)entityPtr);
  if ( v16 != nullptr )
    result->stateInfo = &v16->stateInfo;
  if ( v17 != nullptr )
    result->stateInfo = &v17->plugAnim.stateInfo;
  stateInfo = result->stateInfo;
  if ( stateInfo != nullptr && stateInfo->animWebStates != nullptr )
    result->currentScriptState = stateInfo->currentState;
  if ( entityPtr != nullptr )
  {
    v19 = idEntity::GetPhysics(this: entityPtr);
    v20 = (float *)v19->GetOrigin(this: v19, a2: 0);
    result->nextTargetPosition.x = *v20;
    result->nextTargetPosition.y = v20[1];
    result->nextTargetPosition.z = v20[2];
    v21 = idEntity::GetPhysics(this: entityPtr);
    v22 = (idQuat *)v21->GetAxis(this: v21, a2: 0);
    result->nextTargetRotation = *idMat3::ToQuat(this: v24, result: v22);
  }
  *((_BYTE *)result + 84) = (4
                           * _cntlzw((unsigned __int8)idAction_ScriptedAnimWeb::StartNextState(
                                                        this: result,
                                                        ai: v10,
                                                        newState: result->currentScriptState)))
                          & 0x80
                          | *((_BYTE *)result + 84) & 0x7F;
  return this;
}


// ========================================================================
// ?Action_MoveToScenePointEnter@idAction_MoveToScenePoint@@QAA?AVeventVoid@@PAVidEntity@@0W4moveToScenePointFlags_t@@@Z
// EA  : 0x82AAE080
// RVA : 0x00AAE080
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAction_MoveToScenePoint *__fastcall idAction_MoveToScenePoint::Action_MoveToScenePointEnter(
        idAction_MoveToScenePoint *this,
        eventVoid *result,
        idAI2 *entity,
        idScenePoint *ent,
        const moveToScenePointFlags_t mtspFlags_)
{
  idAI2 *v9; // r30
  idScenePoint *v10; // r3
  idScenePoint *v11; // r31
  int entityNumber; // r11
  int v13; // r26
  int v14; // r4
  idPresentable *presentable; // r11
  idQuat *v16; // r3
  idQuat *v17; // r3
  aiArrivalAction_t v18; // r29
  double radius; // fp31
  idPhysics *Physics; // r3
  int v21; // r3
  float v22; // r7
  float v23; // r6
  idPhysics *v24; // r3
  const idVec3 *v25; // r3
  idPlayer *Player; // r3
  idEntityPtr<idEntity const > *p_currentEnemy; // r11
  posture_t v29; // [sp+8h] [-188h]
  int v30; // [sp+Ch] [-184h]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v31; // [sp+10h] [-180h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v32; // [sp+14h] [-17Ch]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v33; // [sp+18h] [-178h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v34; // [sp+1Ch] [-174h]
  int v35; // [sp+20h] [-170h]
  int v36; // [sp+24h] [-16Ch]
  int v37; // [sp+28h] [-168h]
  int v38; // [sp+2Ch] [-164h]
  int v39; // [sp+30h] [-160h]
  int v40; // [sp+34h] [-15Ch]
  int v41; // [sp+38h] [-158h]
  int v42; // [sp+3Ch] [-154h]
  int v43; // [sp+40h] [-150h]
  int v44; // [sp+44h] [-14Ch]
  int v45; // [sp+48h] [-148h]
  int v46; // [sp+4Ch] [-144h]
  int v47; // [sp+50h] [-140h]
  int v48; // [sp+54h] [-13Ch]
  int v49; // [sp+58h] [-138h]
  int v50; // [sp+60h] [-130h]
  int v51; // [sp+68h] [-128h]
  int v52; // [sp+70h] [-120h]
  int v53; // [sp+78h] [-118h]
  int v54; // [sp+80h] [-110h]
  int v55; // [sp+88h] [-108h]
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v56; // [sp+90h] [-100h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v57; // [sp+92h] [-FEh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v58; // [sp+94h] [-FCh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v59[5]; // [sp+96h] [-FAh] BYREF
  idQuat v60; // [sp+A0h] [-F0h] BYREF
  idVec3 v61; // [sp+B0h] [-E0h] BYREF
  idMat3 v62[2]; // [sp+C0h] [-D0h] BYREF
  idVec3 v63[3]; // [sp+120h] [-70h] BYREF

  v9 = idAI2::CastTo(c: entity);
  v10 = idScenePoint::CastTo(c: ent);
  v11 = v10;
  if ( v10 != nullptr )
  {
    *(_DWORD *)&result[36] = mtspFlags_;
    entityNumber = v10->entityNumber;
    v13 = 2;
    v14 = gameLocal->spawnIds.ptr[entityNumber] << 13;
    v60.x = 0.0;
    v60.y = 0.0;
    v60.z = 0.0;
    *(_DWORD *)&result[32] = v14 | entityNumber;
    v60.w = 1.0;
    if ( v10->duration > 0.0 )
    {
      presentable = v10->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: v10);
        presentable = v11->presentable;
      }
      v16 = (idQuat *)idVec3::ToMat3(this: v63, result: &presentable->axis);
      v17 = idMat3::ToQuat(this: v62, result: v16);
      v60.x = v17->x;
      v13 = 3;
      v60.y = v17->y;
      v60.z = v17->z;
      v60.w = v17->w;
    }
    v59[0].value = -1;
    v56.value = -1;
    idAI2::GetCurrentSubWebAndStateIndices(this: v9, swi: v59, si: &v56);
    v57.value = -1;
    v58.value = -1;
    idAI2::GetMovementSubWebAndStateIndices(this: v9, swi: &v57, si: &v58);
    v9->SetWalkState(this: v9, a2: (const walkState_t)(((_cntlzw(*(_DWORD *)&result[36] & 0x20) & 0x20) == 0) + 1));
    idAIMoveParms::idAIMoveParms(this: (idAIMoveParms *)&v62[0].mat[1].y);
    v18 = AIARRIVAL_STOP;
    if ( v11->duration == 0.0 )
      v18 = AIARRIVAL_CONTINUE;
    radius = v11->radius;
    Physics = idEntity::GetPhysics(this: v11);
    v21 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v22 = *(float *)(v21 + 4);
    v23 = *(float *)(v21 + 8);
    v61.x = *(float *)v21;
    v61.y = v22;
    v61.z = v23;
    v24 = idEntity::GetPhysics(this: v9);
    v25 = v24->GetOrigin(this: v24, a2: 0);
    idAIMoveParms::Init(
      this: (idAIMoveParms *)&v62[0].mat[1].y,
      moveReason_: AIMOVEREASON_UNKNOWN,
      startOrigin_: v25,
      goalOrigin_: &v61,
      goalEntity_: v11,
      goalOrientation_: &v60,
      goalScenePoint_: nullptr,
      goalTolerance_: radius,
      intermediateTolerance_: 0.1,
      arrivalAction_: (const aiArrivalAction_t)"1 - formation cover, such as behind regime shield units",
      arrivalPosture_: v29,
      flags_: v30,
      sourceSubWeb_: v31,
      sourceState_: v32,
      destSubWeb_: v33,
      destState_: v34,
      a17: v35,
      a18: v36,
      a19: v37,
      a20: v38,
      a21: v39,
      a22: v40,
      a23: v41,
      a24: v42,
      a25: v43,
      a26: v44,
      a27: v45,
      a28: v46,
      a29: v47,
      a30: v48,
      a31: v49,
      a32: v18,
      a33: v50,
      a34: POSTURE_STANDING,
      a35: v51,
      a36: v13,
      a37: v52,
      a38: &v59[0].value,
      a39: v53,
      arrivalAction__0: &v56.value,
      a41: v54,
      arrivalPosture_a: &v57.value,
      a43: v55,
      flags_a: &v58.value);
    idAIMoveState::StartMove(this: &v9->aiVolatile.physics.moveState, parms: (const idAIMoveParms *)&v62[0].mat[1].y);
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
    p_currentEnemy = &v9->aiVolatile.memory.currentEnemy;
    if ( Player == nullptr )
    {
      p_currentEnemy->spawnId.value = 0x1FFF;
      return this;
    }
    p_currentEnemy->spawnId.value = (gameLocal->spawnIds.ptr[Player->entityNumber] << 13) | Player->entityNumber;
  }
  return this;
}


// ========================================================================
// ?SetNextState@idAIActionFSM@@UAAXABUtransResult_t@idStateData@@H@Z
// EA  : 0x82AAE310
// RVA : 0x00AAE310
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAIActionFSM::SetNextState(idAIActionFSM *this, const idStateData::transResult_t *result, int curTime)
{
  char v6; // r29
  int transCode; // r11
  idState *v8; // r3
  int v9; // r30
  idAI2 *AI; // r3

  v6 = 1;
  if ( this->actionsQueue.actionEvents.num != 0 )
  {
    transCode = result->transCode;
    if ( transCode != 1 && transCode != 2 )
    {
      v8 = this->GetDoneState(this);
      if ( result->nextStateType == (const idTypeInfo *)v8->GetType(this: v8) )
        goto LABEL_7;
    }
    idAIActionsQueue::Clear(this: &this->actionsQueue);
  }
  v6 = 0;
LABEL_7:
  if ( v6 != 0 )
  {
    v9 = result->transCode;
    AI = idAIFSM::GetAI(this);
    idAIActionsQueue::StartNextAction(this: &this->actionsQueue, ai: AI, transCode: v9);
  }
  else
  {
    idFiniteStateMachine::SetNextState(this, result, curTime);
  }
}


// ========================================================================
// ?SetState@idAIActionFSM@@UAAXABUtransResult_t@idStateData@@H_N@Z
// EA  : 0x82AAE3C8
// RVA : 0x00AAE3C8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAIActionFSM::SetState(
        idAIActionFSM *this,
        const idStateData::transResult_t *result,
        int curTime,
        bool forcingStack)
{
  int transCode; // r11

  this->actionExpireTime = -1;
  transCode = result->transCode;
  if ( transCode == 1 || transCode == 2 )
    idAIActionsQueue::Clear(this: &this->actionsQueue);
  idFiniteStateMachine::SetState(this, result, curTime, forcingStack);
}


// ========================================================================
// ?Init@idAIActionManager@@QAAXPAVidEntity@@@Z
// EA  : 0x82AAE428
// RVA : 0x00AAE428
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __fastcall idAIActionManager::Init(idAIActionManager *this, idEntity *entity)
{
  idList<idAIAction *,5> *p_actionStates; // r31
  int v4; // r28
  int v5; // r29
  int v6; // r3
  idAIAction *const *v7; // r5
  void *errorState; // [sp+50h] [-40h] BYREF
  idFiniteStateMachineParams v9; // [sp+54h] [-3Ch] BYREF

  if ( entity != nullptr )
    this->owner.spawnId.value = (gameLocal->spawnIds.ptr[entity->entityNumber] << 13) | entity->entityNumber;
  else
    this->owner.spawnId.value = 0x1FFF;
  p_actionStates = &this->actionStates;
  errorState = gameLocal->errorState;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = gameLocal->doneState;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionMoveToPoint;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionMoveToPointNoFail;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionMoveToEntity;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionMoveToEntityNoFail;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionMoveToPathPoint;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionMoveToPathPointNoFail;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionMoveToCover;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionUseZipline;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetMovePushStatus;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionIdle;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionPain;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionStandToCrouch;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionCrouchToStand;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionPullTriggerRight;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionReleaseTriggerRight;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionPullTriggerLeft;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionReleaseTriggerLeft;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionReloadWeapon;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionReloadWeaponTorso;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionWaitForAnim;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionWaitForAnimVia;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionLoopAnim;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionLoopAnimExitAtEnd;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionStartAnim;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionWaitForTraversalAnim;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionChangeAnimState;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionChangeAnimStateVia;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionForceAnimState;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionDodge;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionMelee;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionTurnToPoint;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionTurnToEntity;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionTurnToEntityWithOffset;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionWait;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionDive;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionLeapAttack;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionWaitForEntity;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionEnterVehicle;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionPlayVoiceOver;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionStopVoiceOver;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionPlayInteractionVoiceOver;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionPlayOverrideAnim;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionPlayOverrideAnimInterrupt;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionDrawWeapon;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionHolsterWeapon;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionPerformCoverAction;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionWaitForPlayerInteraction;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionWaitForAIVar;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionPerfectMovement;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetAlertCycle;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetSubWeb;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetFocus;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionClearLookFocus;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionClearAimFocus;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetAimPoint;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetFireMode;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetScriptAbort;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetPosture;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetWalkState;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetSitState;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetStandState;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetIdleState;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetPlayerEnemy;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetEnemy;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSearchToTarget;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetPlayerFocus;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetActionNodeGroup;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionTrigger;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionEnableDamage;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionEnablePain;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionEnableAutoFocus;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionEnableBodyRotation;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionEnableWalkIK;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionEnableHeadTracking;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionForceOpenCombat;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionForceAwarenessByDistance;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionForcePlayerInteraction;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetAIVar;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetScriptFlag;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionClearScriptFlag;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetPerceptionFlag;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionClearPerceptionFlag;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionIgnorePlayerApproach;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionNoticePlayerApproach;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionGiveItem;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionTakeItem;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionClearWorldState;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionShowAttachment;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionHideAttachment;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionDropAttachment;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetMoveMode;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionSetAccuracy;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionScriptedAnimWeb;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  errorState = &this->actionMoveToScenePoint;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->actionStates,
    obj: (const encounterGroupRole_t *)&errorState);
  v4 = 0;
  if ( this->actionStates.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = (int)p_actionStates->list[v5]->GetActionEventDef(this: p_actionStates->list[v5]);
      v7 = &p_actionStates->list[v5];
      errorState = *(void **)(v6 + 28);
      idHashTableT<int,idAIAction *>::Set(this: &this->actionsHash, key: (const int *)&errorState, value: v7);
      ++v4;
      ++v5;
    }
    while ( v4 < this->actionStates.num );
  }
  v9.manager = this;
  idFiniteStateMachine::Init(this: &this->legsFSM, params: &v9);
}


// ========================================================================
// ?InternalCallEvent@idAIActionsQueue@@MAA?AVidEventArg@@ABVidEventDef@@PBV2@@Z
// EA  : 0x82AAEE08
// RVA : 0x00AAEE08
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAIActionsQueue *__fastcall idAIActionsQueue::InternalCallEvent(
        idAIActionsQueue *this,
        idEventArg *result,
        const idEventDef *event,
        const idEventArg *args)
{
  const idEventArgs *v8; // r3
  const idEventDef *v10; // [sp+50h] [-1F0h] BYREF
  idEventArgs v11; // [sp+60h] [-1E0h] BYREF

  v10 = event;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)(&result->value.d + 2),
    obj: (const encounterGroupRole_t *)&v10);
  v8 = idEventArgs::idEventArgs(this: &v11, numberOfParams: event->numargs, params: args);
  idList<idEventArgs,92>::Append(this: (idList<idEventArgs,92> *)&result[1].value.q[1], obj: v8);
  `eh vector destructor iterator'(
    ptr: &v11.strings,
    size: 0x20u,
    count: 8,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  HIBYTE(this->__vftable) = 0;
  this->listenerList = nullptr;
  return this;
}


// ========================================================================
// __unwind$519216
// EA  : 0x82AAEE84
// RVA : 0x00AAEE84
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519216()
{
  int v0; // r12

  idEventArgs::~idEventArgs(this: (idEventArgs *)(v0 - 576 + 96));
}


// ========================================================================
// ??0idAIActionFSM@@QAA@PBD@Z
// EA  : 0x82AAEEB8
// RVA : 0x00AAEEB8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAIActionFSM *__fastcall idAIActionFSM::idAIActionFSM(idAIActionFSM *this, const char *name)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name);
  this->__vftable = (idAIActionFSM_vtbl *)&idAIActionFSM::`vftable';
  idAIActionsQueue::idAIActionsQueue(this: &this->actionsQueue);
  this->actionExpireTime = -1;
  this->waitFiberHandle.value = 0;
  this->waitThreadHandle.value = 0;
  idFiniteStateMachine::SetDefaultState(this, state: gameLocal->doneState);
  return this;
}


// ========================================================================
// __unwind$519252
// EA  : 0x82AAEF4C
// RVA : 0x00AAEF4C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519252()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$519253
// EA  : 0x82AAEF74
// RVA : 0x00AAEF74
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519253()
{
  int v0; // r12

  idAIActionsQueue::~idAIActionsQueue(this: (idAIActionsQueue *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// ??0idLegsFSM@@QAA@XZ
// EA  : 0x82AAEFA0
// RVA : 0x00AAEFA0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idLegsFSM *__fastcall idLegsFSM::idLegsFSM(idLegsFSM *this)
{
  idAIActionFSM::idAIActionFSM(this, name: "FSM_legs");
  this->__vftable = (idLegsFSM_vtbl *)&idLegsFSM::`vftable';
  return this;
}


// ========================================================================
// ??0idAIActionManager@@QAA@XZ
// EA  : 0x82AAEFF0
// RVA : 0x00AAEFF0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

idAIActionManager *__fastcall idAIActionManager::idAIActionManager(idAIActionManager *this)
{
  idHashNodeT<int,idAIAction *> **v2; // r3

  idEventReceiver::idEventReceiver(this);
  this->owner.spawnId.value = 0x1FFF;
  this->__vftable = (idAIActionManager_vtbl *)&idAIActionManager::`vftable';
  idState::idState(
    this: &this->actionMoveToPoint,
    stateType: &idAction_MoveToPoint::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionMoveToPoint.lastWalkState = WALKSTATE_RUNNING;
  this->actionMoveToPoint.__vftable = (idAction_MoveToPoint_vtbl *)&idAction_MoveToPoint::`vftable';
  idAction_MoveToPointNoFail::idAction_MoveToPointNoFail(this: &this->actionMoveToPointNoFail);
  idState::idState(
    this: &this->actionMoveToEntity,
    stateType: &idAction_MoveToEntity::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionMoveToEntity.lastWalkState = WALKSTATE_RUNNING;
  this->actionMoveToEntity.__vftable = (idAction_MoveToEntity_vtbl *)&idAction_MoveToEntity::`vftable';
  idAction_MoveToEntityNoFail::idAction_MoveToEntityNoFail(this: &this->actionMoveToEntityNoFail);
  idState::idState(
    this: &this->actionMoveToPathPoint,
    stateType: &idAction_MoveToPathPoint::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionMoveToPathPoint.__vftable = (idAction_MoveToPathPoint_vtbl *)&idAction_MoveToPathPoint::`vftable';
  idAction_MoveToPathPointNoFail::idAction_MoveToPathPointNoFail(this: &this->actionMoveToPathPointNoFail);
  idState::idState(
    this: &this->actionMoveToCover,
    stateType: &idAction_MoveToCover::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionMoveToCover.__vftable = (idAction_MoveToCover_vtbl *)&idAction_MoveToCover::`vftable';
  idState::idState(
    this: &this->actionUseZipline,
    stateType: &idAction_UseZipline::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionUseZipline.__vftable = (idAction_UseZipline_vtbl *)&idAction_UseZipline::`vftable';
  idState::idState(
    this: &this->actionSetMovePushStatus,
    stateType: &idAction_SetMovePushStatus::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionSetMovePushStatus.__vftable = (idAction_SetMovePushStatus_vtbl *)&idAction_SetMovePushStatus::`vftable';
  idState::idState(this: &this->actionIdle, stateType: &idAction_Idle::Type, childFSMType: nullptr, flags: 0);
  this->actionIdle.turnTime = -1;
  this->actionIdle.isTurning = false;
  this->actionIdle.idleTurnType = AIIDLETURN_COMBAT;
  this->actionIdle.__vftable = (idAction_Idle_vtbl *)&idAction_Idle::`vftable';
  idState::idState(this: &this->actionPain, stateType: &idAction_Pain::Type, childFSMType: nullptr, flags: 0);
  this->actionPain.__vftable = (idAction_Pain_vtbl *)&idAction_Pain::`vftable';
  idState::idState(
    this: &this->actionStandToCrouch,
    stateType: &idAction_StandToCrouch::Type,
    childFSMType: nullptr,
    flags: 1);
  this->actionStandToCrouch.alreadyCrouched = false;
  this->actionStandToCrouch.__vftable = (idAction_StandToCrouch_vtbl *)&idAction_StandToCrouch::`vftable';
  idState::idState(
    this: &this->actionCrouchToStand,
    stateType: &idAction_CrouchToStand::Type,
    childFSMType: nullptr,
    flags: 1);
  this->actionCrouchToStand.alreadyCrouched = false;
  this->actionCrouchToStand.__vftable = (idAction_CrouchToStand_vtbl *)&idAction_CrouchToStand::`vftable';
  idState::idState(
    this: &this->actionPullTriggerRight,
    stateType: &idAction_PullTriggerRight::Type,
    childFSMType: nullptr,
    flags: 1);
  this->actionPullTriggerRight.__vftable = (idAction_PullTriggerRight_vtbl *)&idAction_PullTriggerRight::`vftable';
  idState::idState(
    this: &this->actionReleaseTriggerRight,
    stateType: &idAction_ReleaseTriggerRight::Type,
    childFSMType: nullptr,
    flags: 1);
  this->actionReleaseTriggerRight.__vftable = (idAction_ReleaseTriggerRight_vtbl *)&idAction_ReleaseTriggerRight::`vftable';
  idState::idState(
    this: &this->actionPullTriggerLeft,
    stateType: &idAction_PullTriggerLeft::Type,
    childFSMType: nullptr,
    flags: 1);
  this->actionPullTriggerLeft.__vftable = (idAction_PullTriggerLeft_vtbl *)&idAction_PullTriggerLeft::`vftable';
  idState::idState(
    this: &this->actionReleaseTriggerLeft,
    stateType: &idAction_ReleaseTriggerLeft::Type,
    childFSMType: nullptr,
    flags: 1);
  this->actionReleaseTriggerLeft.__vftable = (idAction_ReleaseTriggerLeft_vtbl *)&idAction_ReleaseTriggerLeft::`vftable';
  idState::idState(
    this: &this->actionReloadWeapon,
    stateType: &idAction_ReloadWeapon::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionReloadWeapon.__vftable = (idAction_ReloadWeapon_vtbl *)&idAction_ReloadWeapon::`vftable';
  idState::idState(
    this: &this->actionReloadWeaponTorso,
    stateType: &idAction_ReloadWeaponTorso::Type,
    childFSMType: nullptr,
    flags: 1);
  this->actionReloadWeaponTorso.__vftable = (idAction_ReloadWeaponTorso_vtbl *)&idAction_ReloadWeaponTorso::`vftable';
  idState::idState(
    this: &this->actionWaitForAnim,
    stateType: &idAction_WaitForAnim::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionWaitForAnim.__vftable = (idAction_WaitForAnim_vtbl *)&idAction_WaitForAnim::`vftable';
  idState::idState(
    this: &this->actionWaitForAnimVia,
    stateType: &idAction_WaitForAnimVia::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionWaitForAnimVia.__vftable = (idAction_WaitForAnimVia_vtbl *)&idAction_WaitForAnimVia::`vftable';
  idState::idState(this: &this->actionLoopAnim, stateType: &idAction_LoopAnim::Type, childFSMType: nullptr, flags: 2);
  this->actionLoopAnim.__vftable = (idAction_LoopAnim_vtbl *)&idAction_LoopAnim::`vftable';
  idState::idState(
    this: &this->actionLoopAnimExitAtEnd,
    stateType: &idAction_LoopAnimExitAtEnd::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionLoopAnimExitAtEnd.__vftable = (idAction_LoopAnimExitAtEnd_vtbl *)&idAction_LoopAnimExitAtEnd::`vftable';
  idState::idState(this: &this->actionStartAnim, stateType: &idAction_StartAnim::Type, childFSMType: nullptr, flags: 2);
  this->actionStartAnim.__vftable = (idAction_StartAnim_vtbl *)&idAction_StartAnim::`vftable';
  idState::idState(
    this: &this->actionWaitForTraversalAnim,
    stateType: &idAction_WaitForTraversalAnim::Type,
    childFSMType: nullptr,
    flags: 1);
  this->actionWaitForTraversalAnim.__vftable = (idAction_WaitForTraversalAnim_vtbl *)&idAction_WaitForTraversalAnim::`vftable';
  idState::idState(
    this: &this->actionChangeAnimState,
    stateType: &idAction_ChangeAnimState::Type,
    childFSMType: nullptr,
    flags: 1);
  this->actionChangeAnimState.__vftable = (idAction_ChangeAnimState_vtbl *)&idAction_ChangeAnimState::`vftable';
  idState::idState(
    this: &this->actionChangeAnimStateVia,
    stateType: &idAction_ChangeAnimStateVia::Type,
    childFSMType: nullptr,
    flags: 1);
  this->actionChangeAnimStateVia.__vftable = (idAction_ChangeAnimStateVia_vtbl *)&idAction_ChangeAnimStateVia::`vftable';
  idState::idState(
    this: &this->actionForceAnimState,
    stateType: &idAction_ForceAnimState::Type,
    childFSMType: nullptr,
    flags: 1);
  this->actionForceAnimState.__vftable = (idAction_ForceAnimState_vtbl *)&idAction_ForceAnimState::`vftable';
  idState::idState(this: &this->actionDodge, stateType: &idAction_Dodge::Type, childFSMType: nullptr, flags: 1);
  this->actionDodge.__vftable = (idAction_Dodge_vtbl *)&idAction_Dodge::`vftable';
  this->actionDodge.dodgePoint = vec3_origin;
  idState::idState(this: &this->actionWait, stateType: &idAction_Wait::Type, childFSMType: nullptr, flags: 0);
  this->actionWait.__vftable = (idAction_Wait_vtbl *)&idAction_Wait::`vftable';
  idState::idState(this: &this->actionMelee, stateType: &idAction_Melee::Type, childFSMType: nullptr, flags: 1);
  this->actionMelee.__vftable = (idAction_Melee_vtbl *)&idAction_Melee::`vftable';
  idState::idState(
    this: &this->actionTurnToPoint,
    stateType: &idAction_TurnToPoint::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionTurnToPoint.turnToResult = TURNTO_ERROR;
  this->actionTurnToPoint.__vftable = (idAction_TurnToPoint_vtbl *)&idAction_TurnToPoint::`vftable';
  idState::idState(
    this: &this->actionTurnToEntity,
    stateType: &idAction_TurnToEntity::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionTurnToEntity.turnToResult = TURNTO_ERROR;
  this->actionTurnToEntity.__vftable = (idAction_TurnToEntity_vtbl *)&idAction_TurnToEntity::`vftable';
  idState::idState(
    this: &this->actionTurnToEntityWithOffset,
    stateType: &idAction_TurnToEntityWithOffset::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionTurnToEntityWithOffset.turnToResult = TURNTO_ERROR;
  this->actionTurnToEntityWithOffset.__vftable = (idAction_TurnToEntityWithOffset_vtbl *)&idAction_TurnToEntityWithOffset::`vftable';
  idState::idState(this: &this->actionDive, stateType: &idAction_Dive::Type, childFSMType: nullptr, flags: 1);
  this->actionDive.__vftable = (idAction_Dive_vtbl *)&idAction_Dive::`vftable';
  this->actionDive.idealDir.x = 0.0;
  this->actionDive.idealDir.y = 0.0;
  this->actionDive.idealDir.z = 0.0;
  this->actionDive.diveDir.x = 0.0;
  this->actionDive.diveDir.y = 0.0;
  this->actionDive.diveDir.z = 0.0;
  idState::idState(
    this: &this->actionLeapAttack,
    stateType: &idAction_LeapAttack::Type,
    childFSMType: nullptr,
    flags: 1);
  this->actionLeapAttack.__vftable = (idAction_LeapAttack_vtbl *)&idAction_LeapAttack::`vftable';
  idState::idState(
    this: &this->actionWaitForEntity,
    stateType: &idAction_WaitForEntity::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionWaitForEntity.range = 0.0;
  this->actionWaitForEntity.targetEntity = nullptr;
  this->actionWaitForEntity.__vftable = (idAction_WaitForEntity_vtbl *)&idAction_WaitForEntity::`vftable';
  idState::idState(
    this: &this->actionEnterVehicle,
    stateType: &idAction_EnterVehicle::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionEnterVehicle.__vftable = (idAction_EnterVehicle_vtbl *)&idAction_EnterVehicle::`vftable';
  idState::idState(
    this: &this->actionPlayVoiceOver,
    stateType: &idAction_PlayVoiceOver::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionPlayVoiceOver.waitUntilFinished = false;
  this->actionPlayVoiceOver.__vftable = (idAction_PlayVoiceOver_vtbl *)&idAction_PlayVoiceOver::`vftable';
  idState::idState(
    this: &this->actionStopVoiceOver,
    stateType: &idAction_StopVoiceOver::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionStopVoiceOver.__vftable = (idAction_StopVoiceOver_vtbl *)&idAction_StopVoiceOver::`vftable';
  idState::idState(
    this: &this->actionPlayInteractionVoiceOver,
    stateType: &idAction_PlayInteractionVoiceOver::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionPlayInteractionVoiceOver.__vftable = (idAction_PlayInteractionVoiceOver_vtbl *)&idAction_PlayInteractionVoiceOver::`vftable';
  this->actionPlayInteractionVoiceOver.trackEntity.spawnId.value = 0x1FFF;
  this->actionPlayInteractionVoiceOver.maxDistance = 0.0;
  this->actionPlayInteractionVoiceOver.abortScript = false;
  idState::idState(
    this: &this->actionPlayOverrideAnim,
    stateType: &idAction_PlayOverrideAnim::Type,
    childFSMType: nullptr,
    flags: 1);
  this->actionPlayOverrideAnim.__vftable = (idAction_PlayOverrideAnim_vtbl *)&idAction_PlayOverrideAnim::`vftable';
  idState::idState(
    this: &this->actionPlayOverrideAnimInterrupt,
    stateType: &idAction_PlayOverrideAnimInterrupt::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionPlayOverrideAnimInterrupt.__vftable = (idAction_PlayOverrideAnimInterrupt_vtbl *)&idAction_PlayOverrideAnimInterrupt::`vftable';
  idState::idState(
    this: &this->actionDrawWeapon,
    stateType: &idAction_DrawWeapon::Type,
    childFSMType: nullptr,
    flags: 1);
  this->actionDrawWeapon.__vftable = (idAction_DrawWeapon_vtbl *)&idAction_DrawWeapon::`vftable';
  idState::idState(
    this: &this->actionHolsterWeapon,
    stateType: &idAction_HolsterWeapon::Type,
    childFSMType: nullptr,
    flags: 1);
  this->actionHolsterWeapon.__vftable = (idAction_HolsterWeapon_vtbl *)&idAction_HolsterWeapon::`vftable';
  idState::idState(
    this: &this->actionPerformCoverAction,
    stateType: &idAction_PerformCoverAction::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionPerformCoverAction.__vftable = (idAction_PerformCoverAction_vtbl *)&idAction_PerformCoverAction::`vftable';
  idState::idState(
    this: &this->actionWaitForPlayerInteraction,
    stateType: &idAction_WaitForPlayerInteraction::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionWaitForPlayerInteraction.maxDist = 0.0;
  this->actionWaitForPlayerInteraction.__vftable = (idAction_WaitForPlayerInteraction_vtbl *)&idAction_WaitForPlayerInteraction::`vftable';
  idState::idState(
    this: &this->actionWaitForAIVar,
    stateType: &idAction_WaitForAIVar::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionWaitForAIVar.__vftable = (idAction_WaitForAIVar_vtbl *)&idAction_WaitForAIVar::`vftable';
  idState::idState(
    this: &this->actionPerfectMovement,
    stateType: &idAction_PerfectMovement::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionPerfectMovement.__vftable = (idAction_PerfectMovement_vtbl *)&idAction_PerfectMovement::`vftable';
  this->actionPerfectMovement.swiWhenFinished.value = -1;
  this->actionPerfectMovement.siWhenFinished.value = -1;
  idState::idState(
    this: &this->actionSetAlertCycle,
    stateType: &idAction_SetAlertCycle::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionSetAlertCycle.__vftable = (idAction_SetAlertCycle_vtbl *)&idAction_SetAlertCycle::`vftable';
  idState::idState(this: &this->actionSetFocus, stateType: &idAction_SetFocus::Type, childFSMType: nullptr, flags: 0);
  this->actionSetFocus.__vftable = (idAction_SetFocus_vtbl *)&idAction_SetFocus::`vftable';
  idState::idState(
    this: &this->actionClearLookFocus,
    stateType: &idAction_ClearLookFocus::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionClearLookFocus.__vftable = (idAction_ClearLookFocus_vtbl *)&idAction_ClearLookFocus::`vftable';
  idState::idState(
    this: &this->actionClearAimFocus,
    stateType: &idAction_ClearAimFocus::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionClearAimFocus.__vftable = (idAction_ClearAimFocus_vtbl *)&idAction_ClearAimFocus::`vftable';
  idState::idState(
    this: &this->actionSetAimPoint,
    stateType: &idAction_SetAimPoint::Type,
    childFSMType: nullptr,
    flags: 0);
  this->actionSetAimPoint.__vftable = (idAction_SetAimPoint_vtbl *)&idAction_SetAimPoint::`vftable';
  idState::idState(
    this: &this->actionSetFireMode,
    stateType: &idAction_SetFireMode::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionSetFireMode.__vftable = (idAction_SetFireMode_vtbl *)&idAction_SetFireMode::`vftable';
  idState::idState(
    this: &this->actionSetScriptAbort,
    stateType: &idAction_SetScriptAbort::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionSetScriptAbort.__vftable = (idAction_SetScriptAbort_vtbl *)&idAction_SetScriptAbort::`vftable';
  idState::idState(
    this: &this->actionSetPosture,
    stateType: &idAction_SetPosture::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionSetPosture.__vftable = (idAction_SetPosture_vtbl *)&idAction_SetPosture::`vftable';
  idState::idState(
    this: &this->actionSetWalkState,
    stateType: &idAction_SetWalkState::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionSetWalkState.__vftable = (idAction_SetWalkState_vtbl *)&idAction_SetWalkState::`vftable';
  idState::idState(
    this: &this->actionSetSitState,
    stateType: &idAction_SetSitState::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionSetSitState.__vftable = (idAction_SetSitState_vtbl *)&idAction_SetSitState::`vftable';
  idState::idState(
    this: &this->actionSetStandState,
    stateType: &idAction_SetStandState::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionSetStandState.__vftable = (idAction_SetStandState_vtbl *)&idAction_SetStandState::`vftable';
  idState::idState(
    this: &this->actionSetIdleState,
    stateType: &idAction_SetIdleState::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionSetIdleState.__vftable = (idAction_SetIdleState_vtbl *)&idAction_SetIdleState::`vftable';
  idState::idState(
    this: &this->actionSetPlayerEnemy,
    stateType: &idAction_SetPlayerEnemy::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionSetPlayerEnemy.__vftable = (idAction_SetPlayerEnemy_vtbl *)&idAction_SetPlayerEnemy::`vftable';
  idState::idState(this: &this->actionSetEnemy, stateType: &idAction_SetEnemy::Type, childFSMType: nullptr, flags: 2);
  this->actionSetEnemy.__vftable = (idAction_SetEnemy_vtbl *)&idAction_SetEnemy::`vftable';
  idState::idState(
    this: &this->actionSearchToTarget,
    stateType: &idAction_SearchToTarget::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionSearchToTarget.__vftable = (idAction_SearchToTarget_vtbl *)&idAction_SearchToTarget::`vftable';
  idState::idState(
    this: &this->actionSetPlayerFocus,
    stateType: &idAction_SetPlayerFocus::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionSetPlayerFocus.__vftable = (idAction_SetPlayerFocus_vtbl *)&idAction_SetPlayerFocus::`vftable';
  idState::idState(
    this: &this->actionSetActionNodeGroup,
    stateType: &idAction_SetActionNodeGroup::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionSetActionNodeGroup.__vftable = (idAction_SetActionNodeGroup_vtbl *)&idAction_SetActionNodeGroup::`vftable';
  idState::idState(this: &this->actionTrigger, stateType: &idAction_Trigger::Type, childFSMType: nullptr, flags: 2);
  this->actionTrigger.__vftable = (idAction_Trigger_vtbl *)&idAction_Trigger::`vftable';
  idState::idState(
    this: &this->actionEnableDamage,
    stateType: &idAction_EnableDamage::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionEnableDamage.__vftable = (idAction_EnableDamage_vtbl *)&idAction_EnableDamage::`vftable';
  idState::idState(
    this: &this->actionEnablePain,
    stateType: &idAction_EnablePain::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionEnablePain.__vftable = (idAction_EnablePain_vtbl *)&idAction_EnablePain::`vftable';
  idState::idState(
    this: &this->actionEnableAutoFocus,
    stateType: &idAction_EnableAutoFocus::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionEnableAutoFocus.__vftable = (idAction_EnableAutoFocus_vtbl *)&idAction_EnableAutoFocus::`vftable';
  idState::idState(
    this: &this->actionEnableBodyRotation,
    stateType: &idAction_EnableBodyRotation::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionEnableBodyRotation.__vftable = (idAction_EnableBodyRotation_vtbl *)&idAction_EnableBodyRotation::`vftable';
  idState::idState(
    this: &this->actionEnableWalkIK,
    stateType: &idAction_EnableWalkIK::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionEnableWalkIK.__vftable = (idAction_EnableWalkIK_vtbl *)&idAction_EnableWalkIK::`vftable';
  idState::idState(
    this: &this->actionEnableHeadTracking,
    stateType: &idAction_EnableHeadTracking::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionEnableHeadTracking.__vftable = (idAction_EnableHeadTracking_vtbl *)&idAction_EnableHeadTracking::`vftable';
  idState::idState(
    this: &this->actionForceOpenCombat,
    stateType: &idAction_ForceOpenCombat::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionForceOpenCombat.__vftable = (idAction_ForceOpenCombat_vtbl *)&idAction_ForceOpenCombat::`vftable';
  idState::idState(
    this: &this->actionForceAwarenessByDistance,
    stateType: &idAction_ForceAwarenessByDistance::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionForceAwarenessByDistance.__vftable = (idAction_ForceAwarenessByDistance_vtbl *)&idAction_ForceAwarenessByDistance::`vftable';
  idState::idState(
    this: &this->actionForcePlayerInteraction,
    stateType: &idAction_ForcePlayerInteraction::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionForcePlayerInteraction.__vftable = (idAction_ForcePlayerInteraction_vtbl *)&idAction_ForcePlayerInteraction::`vftable';
  idState::idState(this: &this->actionSetAIVar, stateType: &idAction_SetAIVar::Type, childFSMType: nullptr, flags: 2);
  this->actionSetAIVar.__vftable = (idAction_SetAIVar_vtbl *)&idAction_SetAIVar::`vftable';
  idState::idState(
    this: &this->actionSetScriptFlag,
    stateType: &idAction_SetScriptFlag::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionSetScriptFlag.__vftable = (idAction_SetScriptFlag_vtbl *)&idAction_SetScriptFlag::`vftable';
  idState::idState(
    this: &this->actionClearScriptFlag,
    stateType: &idAction_ClearScriptFlag::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionClearScriptFlag.__vftable = (idAction_ClearScriptFlag_vtbl *)&idAction_ClearScriptFlag::`vftable';
  idState::idState(
    this: &this->actionSetPerceptionFlag,
    stateType: &idAction_SetPerceptionFlag::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionSetPerceptionFlag.__vftable = (idAction_SetPerceptionFlag_vtbl *)&idAction_SetPerceptionFlag::`vftable';
  idState::idState(
    this: &this->actionClearPerceptionFlag,
    stateType: &idAction_ClearPerceptionFlag::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionClearPerceptionFlag.__vftable = (idAction_ClearPerceptionFlag_vtbl *)&idAction_ClearPerceptionFlag::`vftable';
  idState::idState(
    this: &this->actionIgnorePlayerApproach,
    stateType: &idAction_IgnorePlayerApproach::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionIgnorePlayerApproach.__vftable = (idAction_IgnorePlayerApproach_vtbl *)&idAction_IgnorePlayerApproach::`vftable';
  idState::idState(
    this: &this->actionNoticePlayerApproach,
    stateType: &idAction_NoticePlayerApproach::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionNoticePlayerApproach.__vftable = (idAction_NoticePlayerApproach_vtbl *)&idAction_NoticePlayerApproach::`vftable';
  idState::idState(this: &this->actionSetSubWeb, stateType: &idAction_SetSubWeb::Type, childFSMType: nullptr, flags: 0);
  this->actionSetSubWeb.__vftable = (idAction_SetSubWeb_vtbl *)&idAction_SetSubWeb::`vftable';
  idState::idState(this: &this->actionGiveItem, stateType: &idAction_GiveItem::Type, childFSMType: nullptr, flags: 2);
  this->actionGiveItem.__vftable = (idAction_GiveItem_vtbl *)&idAction_GiveItem::`vftable';
  idState::idState(this: &this->actionTakeItem, stateType: &idAction_TakeItem::Type, childFSMType: nullptr, flags: 2);
  this->actionTakeItem.__vftable = (idAction_TakeItem_vtbl *)&idAction_TakeItem::`vftable';
  idState::idState(
    this: &this->actionClearWorldState,
    stateType: &idAction_ClearWorldState::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionClearWorldState.__vftable = (idAction_ClearWorldState_vtbl *)&idAction_ClearWorldState::`vftable';
  idState::idState(
    this: &this->actionShowAttachment,
    stateType: &idAction_ShowAttachment::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionShowAttachment.__vftable = (idAction_ShowAttachment_vtbl *)&idAction_ShowAttachment::`vftable';
  idState::idState(
    this: &this->actionHideAttachment,
    stateType: &idAction_HideAttachment::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionHideAttachment.__vftable = (idAction_HideAttachment_vtbl *)&idAction_HideAttachment::`vftable';
  idState::idState(
    this: &this->actionDropAttachment,
    stateType: &idAction_DropAttachment::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionDropAttachment.__vftable = (idAction_DropAttachment_vtbl *)&idAction_DropAttachment::`vftable';
  idState::idState(
    this: &this->actionSetMoveMode,
    stateType: &idAction_SetMoveMode::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionSetMoveMode.__vftable = (idAction_SetMoveMode_vtbl *)&idAction_SetMoveMode::`vftable';
  idState::idState(
    this: &this->actionSetAccuracy,
    stateType: &idAction_SetAccuracy::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionSetAccuracy.__vftable = (idAction_SetAccuracy_vtbl *)&idAction_SetAccuracy::`vftable';
  idState::idState(
    this: &this->actionScriptedAnimWeb,
    stateType: &idAction_ScriptedAnimWeb::Type,
    childFSMType: nullptr,
    flags: 2);
  this->actionScriptedAnimWeb.currentScriptState = 0;
  this->actionScriptedAnimWeb.__vftable = (idAction_ScriptedAnimWeb_vtbl *)&idAction_ScriptedAnimWeb::`vftable';
  this->actionScriptedAnimWeb.currentSubWebTarget.value = -1;
  this->actionScriptedAnimWeb.currentStateTarget.value = -1;
  idState::idState(
    this: &this->actionMoveToScenePoint,
    stateType: &idAction_MoveToScenePoint::Type,
    childFSMType: nullptr,
    flags: 3);
  this->actionMoveToScenePoint.stayTimeOut = -1;
  this->actionMoveToScenePoint.__vftable = (idAction_MoveToScenePoint_vtbl *)&idAction_MoveToScenePoint::`vftable';
  this->actionMoveToScenePoint.scenepointTarget.spawnId.value = 0x1FFF;
  this->actionMoveToScenePoint.mtspFlags = MTSP_NONE;
  this->actionMoveToScenePoint.isDone = false;
  idAIActionFSM::idAIActionFSM(this: &this->legsFSM, name: "FSM_legs");
  this->legsFSM.__vftable = (idLegsFSM_vtbl *)&idLegsFSM::`vftable';
  this->actionStates.list = nullptr;
  this->actionStates.granularity = 0;
  this->actionStates.memTag = 5;
  this->actionStates.listStatic = 0;
  this->actionStates.size = 0;
  this->actionStates.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->actionStates);
  this->actionsHash.tableSize = 128;
  v2 = (idHashNodeT<int,idAIAction *> **)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                                           size: 0x200u,
                                           tag: TAG_HASHTABLE,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
  this->actionsHash.heads = v2;
  memset(Dst: v2, Val: 0, Size: 0x200u);
  this->actionsHash.numEntries = 0;
  this->actionsHash.tableSizeMask = 127;
  this->actionEventTransCode = 0;
  if ( this->actionStates.size < 100 )
    idList<idNavSpline *,5>::Resize(
      this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->actionStates,
      newsize: 100);
  return this;
}


// ========================================================================
// __unwind$519324
// EA  : 0x82AAFEE8
// RVA : 0x00AAFEE8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519324()
{
  int v0; // r12

  idFSMManager::~idFSMManager(this: *(idFSMManager **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$519325
// EA  : 0x82AAFF10
// RVA : 0x00AAFF10
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519325()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 16));
}


// ========================================================================
// __unwind$519326
// EA  : 0x82AAFF3C
// RVA : 0x00AAFF3C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519326()
{
  int v0; // r12

  idAction_MoveToPointNoFail::~idAction_MoveToPointNoFail(this: (idAction_MoveToPathPointNoFail *)(*(_DWORD *)(v0 - 160 + 180)
                                                                                                 + 48));
}


// ========================================================================
// __unwind$519327
// EA  : 0x82AAFF68
// RVA : 0x00AAFF68
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519327()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 332));
}


// ========================================================================
// __unwind$519328
// EA  : 0x82AAFF94
// RVA : 0x00AAFF94
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519328()
{
  int v0; // r12

  idAction_MoveToPointNoFail::~idAction_MoveToPointNoFail(this: (idAction_MoveToPathPointNoFail *)(*(_DWORD *)(v0 - 160 + 180)
                                                                                                 + 364));
}


// ========================================================================
// __unwind$519329
// EA  : 0x82AAFFC0
// RVA : 0x00AAFFC0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519329()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 648));
}


// ========================================================================
// __unwind$519330
// EA  : 0x82AAFFEC
// RVA : 0x00AAFFEC
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519330()
{
  int v0; // r12

  idAction_MoveToPointNoFail::~idAction_MoveToPointNoFail(this: (idAction_MoveToPathPointNoFail *)(*(_DWORD *)(v0 - 160 + 180)
                                                                                                 + 676));
}


// ========================================================================
// __unwind$519331
// EA  : 0x82AB0018
// RVA : 0x00AB0018
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519331()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 960));
}


// ========================================================================
// __unwind$519332
// EA  : 0x82AB0044
// RVA : 0x00AB0044
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519332()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 988));
}


// ========================================================================
// __unwind$519333
// EA  : 0x82AB0070
// RVA : 0x00AB0070
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519333()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1016));
}


// ========================================================================
// __unwind$519334
// EA  : 0x82AB009C
// RVA : 0x00AB009C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519334()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1044));
}


// ========================================================================
// __unwind$519335
// EA  : 0x82AB00C8
// RVA : 0x00AB00C8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519335()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1084));
}


// ========================================================================
// __unwind$519336
// EA  : 0x82AB00F4
// RVA : 0x00AB00F4
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519336()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1112));
}


// ========================================================================
// __unwind$519337
// EA  : 0x82AB0120
// RVA : 0x00AB0120
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519337()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1144));
}


// ========================================================================
// __unwind$519338
// EA  : 0x82AB014C
// RVA : 0x00AB014C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519338()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1176));
}


// ========================================================================
// __unwind$519339
// EA  : 0x82AB0178
// RVA : 0x00AB0178
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519339()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1204));
}


// ========================================================================
// __unwind$519340
// EA  : 0x82AB01A4
// RVA : 0x00AB01A4
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519340()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1232));
}


// ========================================================================
// __unwind$519341
// EA  : 0x82AB01D0
// RVA : 0x00AB01D0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519341()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1260));
}


// ========================================================================
// __unwind$519342
// EA  : 0x82AB01FC
// RVA : 0x00AB01FC
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519342()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1288));
}


// ========================================================================
// __unwind$519343
// EA  : 0x82AB0228
// RVA : 0x00AB0228
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519343()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1316));
}


// ========================================================================
// __unwind$519344
// EA  : 0x82AB0254
// RVA : 0x00AB0254
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519344()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1344));
}


// ========================================================================
// __unwind$519345
// EA  : 0x82AB0280
// RVA : 0x00AB0280
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519345()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1372));
}


// ========================================================================
// __unwind$519346
// EA  : 0x82AB02AC
// RVA : 0x00AB02AC
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519346()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1400));
}


// ========================================================================
// __unwind$519347
// EA  : 0x82AB02D8
// RVA : 0x00AB02D8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519347()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1428));
}


// ========================================================================
// __unwind$519348
// EA  : 0x82AB0304
// RVA : 0x00AB0304
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519348()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1456));
}


// ========================================================================
// __unwind$519349
// EA  : 0x82AB0330
// RVA : 0x00AB0330
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519349()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1484));
}


// ========================================================================
// __unwind$519350
// EA  : 0x82AB035C
// RVA : 0x00AB035C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519350()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1512));
}


// ========================================================================
// __unwind$519351
// EA  : 0x82AB0388
// RVA : 0x00AB0388
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519351()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1540));
}


// ========================================================================
// __unwind$519352
// EA  : 0x82AB03B4
// RVA : 0x00AB03B4
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519352()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1568));
}


// ========================================================================
// __unwind$519353
// EA  : 0x82AB03E0
// RVA : 0x00AB03E0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519353()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1596));
}


// ========================================================================
// __unwind$519354
// EA  : 0x82AB040C
// RVA : 0x00AB040C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519354()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1636));
}


// ========================================================================
// __unwind$519355
// EA  : 0x82AB0438
// RVA : 0x00AB0438
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519355()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1664));
}


// ========================================================================
// __unwind$519356
// EA  : 0x82AB0464
// RVA : 0x00AB0464
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519356()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1692));
}


// ========================================================================
// __unwind$519357
// EA  : 0x82AB0490
// RVA : 0x00AB0490
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519357()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1724));
}


// ========================================================================
// __unwind$519358
// EA  : 0x82AB04BC
// RVA : 0x00AB04BC
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519358()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1756));
}


// ========================================================================
// __unwind$519359
// EA  : 0x82AB04E8
// RVA : 0x00AB04E8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519359()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1788));
}


// ========================================================================
// __unwind$519360
// EA  : 0x82AB0514
// RVA : 0x00AB0514
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519360()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1840));
}


// ========================================================================
// __unwind$519361
// EA  : 0x82AB0540
// RVA : 0x00AB0540
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519361()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1868));
}


// ========================================================================
// __unwind$519362
// EA  : 0x82AB056C
// RVA : 0x00AB056C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519362()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1904));
}


// ========================================================================
// __unwind$519363
// EA  : 0x82AB0598
// RVA : 0x00AB0598
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519363()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1932));
}


// ========================================================================
// __unwind$519364
// EA  : 0x82AB05C4
// RVA : 0x00AB05C4
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519364()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1964));
}


// ========================================================================
// __unwind$519365
// EA  : 0x82AB05F0
// RVA : 0x00AB05F0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519365()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 1992));
}


// ========================================================================
// __unwind$519366
// EA  : 0x82AB061C
// RVA : 0x00AB061C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519366()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2032));
}


// ========================================================================
// __unwind$519367
// EA  : 0x82AB0648
// RVA : 0x00AB0648
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519367()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2060));
}


// ========================================================================
// __unwind$519368
// EA  : 0x82AB0674
// RVA : 0x00AB0674
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519368()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2088));
}


// ========================================================================
// __unwind$519369
// EA  : 0x82AB06A0
// RVA : 0x00AB06A0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519369()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2116));
}


// ========================================================================
// __unwind$519370
// EA  : 0x82AB06CC
// RVA : 0x00AB06CC
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519370()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2144));
}


// ========================================================================
// __unwind$519371
// EA  : 0x82AB06F8
// RVA : 0x00AB06F8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519371()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2172));
}


// ========================================================================
// __unwind$519372
// EA  : 0x82AB0724
// RVA : 0x00AB0724
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519372()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2204));
}


// ========================================================================
// __unwind$519373
// EA  : 0x82AB0750
// RVA : 0x00AB0750
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519373()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2232));
}


// ========================================================================
// __unwind$519374
// EA  : 0x82AB077C
// RVA : 0x00AB077C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519374()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2264));
}


// ========================================================================
// __unwind$519375
// EA  : 0x82AB07A8
// RVA : 0x00AB07A8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519375()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2292));
}


// ========================================================================
// __unwind$519376
// EA  : 0x82AB07D4
// RVA : 0x00AB07D4
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519376()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2320));
}


// ========================================================================
// __unwind$519377
// EA  : 0x82AB0800
// RVA : 0x00AB0800
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519377()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2348));
}


// ========================================================================
// __unwind$519378
// EA  : 0x82AB082C
// RVA : 0x00AB082C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519378()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2376));
}


// ========================================================================
// __unwind$519379
// EA  : 0x82AB0858
// RVA : 0x00AB0858
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519379()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2404));
}


// ========================================================================
// __unwind$519380
// EA  : 0x82AB0884
// RVA : 0x00AB0884
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519380()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2432));
}


// ========================================================================
// __unwind$519381
// EA  : 0x82AB08B0
// RVA : 0x00AB08B0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519381()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2460));
}


// ========================================================================
// __unwind$519382
// EA  : 0x82AB08DC
// RVA : 0x00AB08DC
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519382()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2488));
}


// ========================================================================
// __unwind$519383
// EA  : 0x82AB0908
// RVA : 0x00AB0908
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519383()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2516));
}


// ========================================================================
// __unwind$519384
// EA  : 0x82AB0934
// RVA : 0x00AB0934
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519384()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2544));
}


// ========================================================================
// __unwind$519385
// EA  : 0x82AB0960
// RVA : 0x00AB0960
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519385()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2572));
}


// ========================================================================
// __unwind$519386
// EA  : 0x82AB098C
// RVA : 0x00AB098C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519386()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2600));
}


// ========================================================================
// __unwind$519387
// EA  : 0x82AB09B8
// RVA : 0x00AB09B8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519387()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2628));
}


// ========================================================================
// __unwind$519388
// EA  : 0x82AB09E4
// RVA : 0x00AB09E4
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519388()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2656));
}


// ========================================================================
// __unwind$519389
// EA  : 0x82AB0A10
// RVA : 0x00AB0A10
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519389()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2684));
}


// ========================================================================
// __unwind$519390
// EA  : 0x82AB0A3C
// RVA : 0x00AB0A3C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519390()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2712));
}


// ========================================================================
// __unwind$519391
// EA  : 0x82AB0A68
// RVA : 0x00AB0A68
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519391()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2740));
}


// ========================================================================
// __unwind$519392
// EA  : 0x82AB0A94
// RVA : 0x00AB0A94
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519392()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2768));
}


// ========================================================================
// __unwind$519393
// EA  : 0x82AB0AC0
// RVA : 0x00AB0AC0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519393()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2796));
}


// ========================================================================
// __unwind$519394
// EA  : 0x82AB0AEC
// RVA : 0x00AB0AEC
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519394()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2824));
}


// ========================================================================
// __unwind$519395
// EA  : 0x82AB0B18
// RVA : 0x00AB0B18
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519395()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2852));
}


// ========================================================================
// __unwind$519396
// EA  : 0x82AB0B44
// RVA : 0x00AB0B44
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519396()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2880));
}


// ========================================================================
// __unwind$519397
// EA  : 0x82AB0B70
// RVA : 0x00AB0B70
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519397()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2908));
}


// ========================================================================
// __unwind$519398
// EA  : 0x82AB0B9C
// RVA : 0x00AB0B9C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519398()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2936));
}


// ========================================================================
// __unwind$519399
// EA  : 0x82AB0BC8
// RVA : 0x00AB0BC8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519399()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2964));
}


// ========================================================================
// __unwind$519400
// EA  : 0x82AB0BF4
// RVA : 0x00AB0BF4
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519400()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 2992));
}


// ========================================================================
// __unwind$519401
// EA  : 0x82AB0C20
// RVA : 0x00AB0C20
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519401()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3020));
}


// ========================================================================
// __unwind$519402
// EA  : 0x82AB0C4C
// RVA : 0x00AB0C4C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519402()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3048));
}


// ========================================================================
// __unwind$519403
// EA  : 0x82AB0C78
// RVA : 0x00AB0C78
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519403()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3076));
}


// ========================================================================
// __unwind$519404
// EA  : 0x82AB0CA4
// RVA : 0x00AB0CA4
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519404()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3104));
}


// ========================================================================
// __unwind$519405
// EA  : 0x82AB0CD0
// RVA : 0x00AB0CD0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519405()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3132));
}


// ========================================================================
// __unwind$519406
// EA  : 0x82AB0CFC
// RVA : 0x00AB0CFC
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519406()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3160));
}


// ========================================================================
// __unwind$519407
// EA  : 0x82AB0D28
// RVA : 0x00AB0D28
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519407()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3188));
}


// ========================================================================
// __unwind$519408
// EA  : 0x82AB0D54
// RVA : 0x00AB0D54
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519408()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3216));
}


// ========================================================================
// __unwind$519409
// EA  : 0x82AB0D80
// RVA : 0x00AB0D80
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519409()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3244));
}


// ========================================================================
// __unwind$519410
// EA  : 0x82AB0DAC
// RVA : 0x00AB0DAC
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519410()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3272));
}


// ========================================================================
// __unwind$519411
// EA  : 0x82AB0DD8
// RVA : 0x00AB0DD8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519411()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3300));
}


// ========================================================================
// __unwind$519412
// EA  : 0x82AB0E04
// RVA : 0x00AB0E04
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519412()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3328));
}


// ========================================================================
// __unwind$519413
// EA  : 0x82AB0E30
// RVA : 0x00AB0E30
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519413()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3356));
}


// ========================================================================
// __unwind$519414
// EA  : 0x82AB0E5C
// RVA : 0x00AB0E5C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519414()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3384));
}


// ========================================================================
// __unwind$519415
// EA  : 0x82AB0E88
// RVA : 0x00AB0E88
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519415()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3412));
}


// ========================================================================
// __unwind$519416
// EA  : 0x82AB0EB4
// RVA : 0x00AB0EB4
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519416()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3440));
}


// ========================================================================
// __unwind$519417
// EA  : 0x82AB0EE0
// RVA : 0x00AB0EE0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519417()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3468));
}


// ========================================================================
// __unwind$519418
// EA  : 0x82AB0F0C
// RVA : 0x00AB0F0C
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519418()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 160 + 180) + 3556));
}


// ========================================================================
// __unwind$519419
// EA  : 0x82AB0F38
// RVA : 0x00AB0F38
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519419()
{
  int v0; // r12

  idLegsFSM::~idLegsFSM(this: (idLegsFSM *)(*(_DWORD *)(v0 - 160 + 180) + 3600));
}


// ========================================================================
// __unwind$519420
// EA  : 0x82AB0F64
// RVA : 0x00AB0F64
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519420()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 3764));
}


// ========================================================================
// __unwind$519421
// EA  : 0x82AB0F90
// RVA : 0x00AB0F90
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void _unwind_519421()
{
  int v0; // r12

  idHashTableT<int,idAIAction *>::~idHashTableT<int,idAIAction *>(this: (idHashTableT<int,idAIAction *> *)(*(_DWORD *)(v0 - 160 + 180) + 3780));
}


// ========================================================================
// `dynamic initializer for 'ai_debugActionScript''
// EA  : 0x83369298
// RVA : 0x01369298
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugActionScript__()
{
  idCVar::idCVar(
    this: &ai_debugActionScript,
    name: "ai_debugActionScript",
    value: "0",
    flags: 2,
    description: "1 = show debug info for action scripts",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugActionScript__);
}


// ========================================================================
// `dynamic initializer for 'ai_clearEvents''
// EA  : 0x833692F0
// RVA : 0x013692F0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_clearEvents__()
{
  idCVar::idCVar(
    this: &ai_clearEvents,
    name: "ai_clearEvents",
    value: "0",
    flags: 1,
    description: "1 = clear pending anim web events before changing state... testing only",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_clearEvents__);
}


// ========================================================================
// `dynamic initializer for 'ai_playInteractionVoiceOver_defaultLeaveDistance''
// EA  : 0x83369348
// RVA : 0x01369348
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_playInteractionVoiceOver_defaultLeaveDistance__()
{
  idCVar::idCVar(
    this: &ai_playInteractionVoiceOver_defaultLeaveDistance,
    name: "ai_playInteractionVoiceOver_defaultLeaveDistance",
    value: "200",
    flags: 4,
    description: "if there is no interaction decl, default distance for this value",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_playInteractionVoiceOver_defaultLeaveDistance__);
}


// ========================================================================
// `dynamic initializer for 'ai_coverSnapRadius''
// EA  : 0x833693A0
// RVA : 0x013693A0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_coverSnapRadius__()
{
  idCVar::idCVar(
    this: &ai_coverSnapRadius,
    name: "ai_coverSnapRadius",
    value: "8",
    flags: 4,
    description: "distance within which to snap AI to cover on last transition frame, otherwise fail",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_coverSnapRadius__);
}


// ========================================================================
// `dynamic initializer for 'ai_coverLerpRadius''
// EA  : 0x833693F8
// RVA : 0x013693F8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_coverLerpRadius__()
{
  idCVar::idCVar(
    this: &ai_coverLerpRadius,
    name: "ai_coverLerpRadius",
    value: "32",
    flags: 4,
    description: "distance within which to start lerping AI to cover near end of transition",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_coverLerpRadius__);
}


// ========================================================================
// `dynamic initializer for 'ai_coverAbortRadius''
// EA  : 0x83369450
// RVA : 0x01369450
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_coverAbortRadius__()
{
  idCVar::idCVar(
    this: &ai_coverAbortRadius,
    name: "ai_coverAbortRadius",
    value: "32",
    flags: 4,
    description: "distance outside which we abort the move to cover action on the last frame of a transition",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_coverAbortRadius__);
}

