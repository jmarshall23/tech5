
// ========================================================================
// ?GetActionEventDef@idAIStateError@@UBAABVidEventDef@@XZ
// EA  : 0x824FA410
// RVA : 0x004FA410
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAIStateError::GetActionEventDef(idAIStateError *this)
{
  return &ACTION_ErrorEnter;
}


// ========================================================================
// ?GetActionEventDef@idAIStateDone@@UBAABVidEventDef@@XZ
// EA  : 0x82501430
// RVA : 0x00501430
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAIStateDone::GetActionEventDef(idAIStateDone *this)
{
  return &ACTION_DoneEnter;
}


// ========================================================================
// ??0idAIActionsQueue@@QAA@XZ
// EA  : 0x8253EE58
// RVA : 0x0053EE58
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

idAIActionsQueue *__fastcall idAIActionsQueue::idAIActionsQueue(idAIActionsQueue *this)
{
  idEventReceiver::idEventReceiver(this);
  this->__vftable = (idAIActionsQueue_vtbl *)&idAIActionsQueue::`vftable';
  this->actionEvents.list = nullptr;
  this->actionEvents.granularity = 0;
  this->actionEvents.memTag = 92;
  this->actionEvents.listStatic = 0;
  this->actionEvents.size = 0;
  this->actionEvents.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->actionEvents);
  this->actionArgs.granularity = 0;
  this->actionArgs.memTag = 92;
  this->actionArgs.listStatic = 0;
  this->actionArgs.list = nullptr;
  this->actionArgs.size = 0;
  this->actionArgs.num = 0;
  return this;
}


// ========================================================================
// __unwind$584415
// EA  : 0x8253EED4
// RVA : 0x0053EED4
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

void _unwind_584415()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$584416
// EA  : 0x8253EEFC
// RVA : 0x0053EEFC
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

void _unwind_584416()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 12));
}


// ========================================================================
// ??1idAIActionsQueue@@UAA@XZ
// EA  : 0x8253EF30
// RVA : 0x0053EF30
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

void __fastcall idAIActionsQueue::~idAIActionsQueue(idAIActionsQueue *this)
{
  idEventArgs *list; // r3

  this->__vftable = (idAIActionsQueue_vtbl *)&idAIActionsQueue::`vftable';
  if ( this->actionArgs.listStatic == 0 || this->actionArgs.listStatic == 2 )
  {
    list = this->actionArgs.list;
    if ( list != nullptr )
      idListArrayDelete<idEventArgs>(ptr: (char *)list, num: this->actionArgs.size);
    this->actionArgs.list = nullptr;
    this->actionArgs.size = 0;
  }
  this->actionArgs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->actionEvents);
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// __unwind$584456
// EA  : 0x8253EFA4
// RVA : 0x0053EFA4
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

void _unwind_584456()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$584457
// EA  : 0x8253EFCC
// RVA : 0x0053EFCC
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

void _unwind_584457()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 12));
}


// ========================================================================
// ?GetActionEventDef@idAction_MoveToPoint@@UBAABVidEventDef@@XZ
// EA  : 0x82AA31A0
// RVA : 0x00AA31A0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_MoveToPoint::GetActionEventDef(idAction_MoveToPoint *this)
{
  return &ACTION_MoveToPointEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_MoveToPointNoFail@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3260
// RVA : 0x00AA3260
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_MoveToPointNoFail::GetActionEventDef(idAction_MoveToPointNoFail *this)
{
  return &ACTION_MoveToPointNoFailEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_MoveToEntity@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3328
// RVA : 0x00AA3328
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_MoveToEntity::GetActionEventDef(idAction_MoveToEntity *this)
{
  return &ACTION_MoveToEntityEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_MoveToEntityNoFail@@UBAABVidEventDef@@XZ
// EA  : 0x82AA33E8
// RVA : 0x00AA33E8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_MoveToEntityNoFail::GetActionEventDef(idAction_MoveToEntityNoFail *this)
{
  return &ACTION_MoveToEntityNoFailEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_MoveToPathPoint@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3448
// RVA : 0x00AA3448
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_MoveToPathPoint::GetActionEventDef(idAction_MoveToPathPoint *this)
{
  return &ACTION_MoveToPathPointEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_MoveToPathPointNoFail@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3508
// RVA : 0x00AA3508
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_MoveToPathPointNoFail::GetActionEventDef(idAction_MoveToPathPointNoFail *this)
{
  return &ACTION_MoveToPathPointNoFailEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_MoveToCover@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3568
// RVA : 0x00AA3568
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_MoveToCover::GetActionEventDef(idAction_MoveToCover *this)
{
  return &ACTION_MoveToCoverEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_UseZipline@@UBAABVidEventDef@@XZ
// EA  : 0x82AA35C8
// RVA : 0x00AA35C8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_UseZipline::GetActionEventDef(idAction_UseZipline *this)
{
  return &ACTION_UseZiplineEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetMovePushStatus@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3628
// RVA : 0x00AA3628
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetMovePushStatus::GetActionEventDef(idAction_SetMovePushStatus *this)
{
  return &ACTION_SetMovePushStatusEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_Idle@@UBAABVidEventDef@@XZ
// EA  : 0x82AA36A0
// RVA : 0x00AA36A0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_Idle::GetActionEventDef(idAction_Idle *this)
{
  return &ACTION_IdleEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_Pain@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3700
// RVA : 0x00AA3700
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_Pain::GetActionEventDef(idAction_Pain *this)
{
  return &ACTION_PainEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_StandToCrouch@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3768
// RVA : 0x00AA3768
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_StandToCrouch::GetActionEventDef(idAction_StandToCrouch *this)
{
  return &ACTION_StandToCrouchEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_CrouchToStand@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3A18
// RVA : 0x00AA3A18
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_CrouchToStand::GetActionEventDef(idAction_CrouchToStand *this)
{
  return &ACTION_CrouchToStandEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_PullTriggerRight@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3A78
// RVA : 0x00AA3A78
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_PullTriggerRight::GetActionEventDef(idAction_PullTriggerRight *this)
{
  return &ACTION_PullTriggerRightEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_ReleaseTriggerRight@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3AD8
// RVA : 0x00AA3AD8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_ReleaseTriggerRight::GetActionEventDef(idAction_ReleaseTriggerRight *this)
{
  return &ACTION_ReleaseTriggerRightEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_PullTriggerLeft@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3B38
// RVA : 0x00AA3B38
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_PullTriggerLeft::GetActionEventDef(idAction_PullTriggerLeft *this)
{
  return &ACTION_PullTriggerLeftEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_ReleaseTriggerLeft@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3B98
// RVA : 0x00AA3B98
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_ReleaseTriggerLeft::GetActionEventDef(idAction_ReleaseTriggerLeft *this)
{
  return &ACTION_ReleaseTriggerLeftEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_ReloadWeapon@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3BF8
// RVA : 0x00AA3BF8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_ReloadWeapon::GetActionEventDef(idAction_ReloadWeapon *this)
{
  return &ACTION_ReloadWeaponEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_ReloadWeaponTorso@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3C58
// RVA : 0x00AA3C58
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_ReloadWeaponTorso::GetActionEventDef(idAction_ReloadWeaponTorso *this)
{
  return &ACTION_ReloadWeaponTorsoEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_WaitForAnim@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3CB8
// RVA : 0x00AA3CB8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_WaitForAnim::GetActionEventDef(idAction_WaitForAnim *this)
{
  return &ACTION_WaitForAnimEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_WaitForAnimVia@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3D18
// RVA : 0x00AA3D18
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_WaitForAnimVia::GetActionEventDef(idAction_WaitForAnimVia *this)
{
  return &ACTION_WaitForAnimViaEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_LoopAnim@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3D78
// RVA : 0x00AA3D78
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_LoopAnim::GetActionEventDef(idAction_LoopAnim *this)
{
  return &ACTION_LoopAnimEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_LoopAnimExitAtEnd@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3DD8
// RVA : 0x00AA3DD8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_LoopAnimExitAtEnd::GetActionEventDef(idAction_LoopAnimExitAtEnd *this)
{
  return &ACTION_LoopAnimExitAtEndEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_StartAnim@@UBAABVidEventDef@@XZ
// EA  : 0x82AA3E38
// RVA : 0x00AA3E38
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_StartAnim::GetActionEventDef(idAction_StartAnim *this)
{
  return &ACTION_StartAnimEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_WaitForTraversalAnim@@UBAABVidEventDef@@XZ
// EA  : 0x82AA4028
// RVA : 0x00AA4028
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_WaitForTraversalAnim::GetActionEventDef(idAction_WaitForTraversalAnim *this)
{
  return &ACTION_WaitForTraversalAnimEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_ChangeAnimState@@UBAABVidEventDef@@XZ
// EA  : 0x82AA4088
// RVA : 0x00AA4088
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_ChangeAnimState::GetActionEventDef(idAction_ChangeAnimState *this)
{
  return &ACTION_ChangeAnimStateEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_ChangeAnimStateVia@@UBAABVidEventDef@@XZ
// EA  : 0x82AA42A8
// RVA : 0x00AA42A8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_ChangeAnimStateVia::GetActionEventDef(idAction_ChangeAnimStateVia *this)
{
  return &ACTION_ChangeAnimStateViaEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_ForceAnimState@@UBAABVidEventDef@@XZ
// EA  : 0x82AA4578
// RVA : 0x00AA4578
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_ForceAnimState::GetActionEventDef(idAction_ForceAnimState *this)
{
  return &ACTION_ForceAnimStateEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_Dodge@@UBAABVidEventDef@@XZ
// EA  : 0x82AA47C0
// RVA : 0x00AA47C0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_Dodge::GetActionEventDef(idAction_Dodge *this)
{
  return &ACTION_DodgeEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_Wait@@UBAABVidEventDef@@XZ
// EA  : 0x82AA4820
// RVA : 0x00AA4820
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_Wait::GetActionEventDef(idAction_Wait *this)
{
  return &ACTION_WaitEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_Dive@@UBAABVidEventDef@@XZ
// EA  : 0x82AA48A0
// RVA : 0x00AA48A0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_Dive::GetActionEventDef(idAction_Dive *this)
{
  return &ACTION_DiveEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_Melee@@UBAABVidEventDef@@XZ
// EA  : 0x82AA4900
// RVA : 0x00AA4900
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_Melee::GetActionEventDef(idAction_Melee *this)
{
  return &ACTION_MeleeEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_TurnToPoint@@UBAABVidEventDef@@XZ
// EA  : 0x82AA4968
// RVA : 0x00AA4968
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_TurnToPoint::GetActionEventDef(idAction_TurnToPoint *this)
{
  return &ACTION_TurnToPointEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_TurnToEntity@@UBAABVidEventDef@@XZ
// EA  : 0x82AA49D0
// RVA : 0x00AA49D0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_TurnToEntity::GetActionEventDef(idAction_TurnToEntity *this)
{
  return &ACTION_TurnToEntityEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_TurnToEntityWithOffset@@UBAABVidEventDef@@XZ
// EA  : 0x82AA4A38
// RVA : 0x00AA4A38
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_TurnToEntityWithOffset::GetActionEventDef(idAction_TurnToEntityWithOffset *this)
{
  return &ACTION_TurnToEntityWithOffsetEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_WaitForEntity@@UBAABVidEventDef@@XZ
// EA  : 0x82AA4AA8
// RVA : 0x00AA4AA8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_WaitForEntity::GetActionEventDef(idAction_WaitForEntity *this)
{
  return &ACTION_WaitForEntityEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_EnterVehicle@@UBAABVidEventDef@@XZ
// EA  : 0x82AA4B08
// RVA : 0x00AA4B08
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_EnterVehicle::GetActionEventDef(idAction_EnterVehicle *this)
{
  return &ACTION_EnterVehicleEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_PlayVoiceOver@@UBAABVidEventDef@@XZ
// EA  : 0x82AA4C00
// RVA : 0x00AA4C00
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_PlayVoiceOver::GetActionEventDef(idAction_PlayVoiceOver *this)
{
  return &ACTION_PlayVoiceOverEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_StopVoiceOver@@UBAABVidEventDef@@XZ
// EA  : 0x82AA4C60
// RVA : 0x00AA4C60
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_StopVoiceOver::GetActionEventDef(idAction_StopVoiceOver *this)
{
  return &ACTION_StopVoiceOverEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_PlayInteractionVoiceOver@@UBAABVidEventDef@@XZ
// EA  : 0x82AA4E30
// RVA : 0x00AA4E30
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_PlayInteractionVoiceOver::GetActionEventDef(
        idAction_PlayInteractionVoiceOver *this)
{
  return &ACTION_PlayInteractionVoiceOverEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_PlayOverrideAnim@@UBAABVidEventDef@@XZ
// EA  : 0x82AA4E90
// RVA : 0x00AA4E90
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_PlayOverrideAnim::GetActionEventDef(idAction_PlayOverrideAnim *this)
{
  return &ACTION_PlayOverrideAnimEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_PlayOverrideAnimInterrupt@@UBAABVidEventDef@@XZ
// EA  : 0x82AA4EF0
// RVA : 0x00AA4EF0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_PlayOverrideAnimInterrupt::GetActionEventDef(
        idAction_PlayOverrideAnimInterrupt *this)
{
  return &ACTION_PlayOverrideAnimInterruptEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_LeapAttack@@UBAABVidEventDef@@XZ
// EA  : 0x82AA4F50
// RVA : 0x00AA4F50
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_LeapAttack::GetActionEventDef(idAction_LeapAttack *this)
{
  return &ACTION_LeapAttackEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_DrawWeapon@@UBAABVidEventDef@@XZ
// EA  : 0x82AA4FB0
// RVA : 0x00AA4FB0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_DrawWeapon::GetActionEventDef(idAction_DrawWeapon *this)
{
  return &ACTION_DrawWeaponEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_HolsterWeapon@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5010
// RVA : 0x00AA5010
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_HolsterWeapon::GetActionEventDef(idAction_HolsterWeapon *this)
{
  return &ACTION_HolsterWeaponEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_PerformCoverAction@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5070
// RVA : 0x00AA5070
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_PerformCoverAction::GetActionEventDef(idAction_PerformCoverAction *this)
{
  return &ACTION_PerformCoverActionEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_WaitForPlayerInteraction@@UBAABVidEventDef@@XZ
// EA  : 0x82AA50D8
// RVA : 0x00AA50D8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_WaitForPlayerInteraction::GetActionEventDef(
        idAction_WaitForPlayerInteraction *this)
{
  return &ACTION_WaitForPlayerInteractionEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_WaitForAIVar@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5138
// RVA : 0x00AA5138
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_WaitForAIVar::GetActionEventDef(idAction_WaitForAIVar *this)
{
  return &ACTION_WaitForAIVarEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_PerfectMovement@@UBAABVidEventDef@@XZ
// EA  : 0x82AA51A0
// RVA : 0x00AA51A0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_PerfectMovement::GetActionEventDef(idAction_PerfectMovement *this)
{
  return &ACTION_PerfectMovementEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetAlertCycle@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5390
// RVA : 0x00AA5390
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetAlertCycle::GetActionEventDef(idAction_SetAlertCycle *this)
{
  return &ACTION_SetAlertCycleEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetSubWeb@@UBAABVidEventDef@@XZ
// EA  : 0x82AA53F0
// RVA : 0x00AA53F0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetSubWeb::GetActionEventDef(idAction_SetSubWeb *this)
{
  return &ACTION_SetSubWebEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetFocus@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5450
// RVA : 0x00AA5450
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetFocus::GetActionEventDef(idAction_SetFocus *this)
{
  return &ACTION_SetFocusEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_ClearLookFocus@@UBAABVidEventDef@@XZ
// EA  : 0x82AA54B0
// RVA : 0x00AA54B0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_ClearLookFocus::GetActionEventDef(idAction_ClearLookFocus *this)
{
  return &ACTION_ClearLookFocusEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_ClearAimFocus@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5510
// RVA : 0x00AA5510
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_ClearAimFocus::GetActionEventDef(idAction_ClearAimFocus *this)
{
  return &ACTION_ClearAimFocusEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetAimPoint@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5570
// RVA : 0x00AA5570
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetAimPoint::GetActionEventDef(idAction_SetAimPoint *this)
{
  return &ACTION_SetAimPointEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetFireMode@@UBAABVidEventDef@@XZ
// EA  : 0x82AA55D0
// RVA : 0x00AA55D0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetFireMode::GetActionEventDef(idAction_SetFireMode *this)
{
  return &ACTION_SetFireModeEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetScriptAbort@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5630
// RVA : 0x00AA5630
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetScriptAbort::GetActionEventDef(idAction_SetScriptAbort *this)
{
  return &ACTION_SetScriptAbortEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetPosture@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5690
// RVA : 0x00AA5690
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetPosture::GetActionEventDef(idAction_SetPosture *this)
{
  return &ACTION_SetPostureEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetWalkState@@UBAABVidEventDef@@XZ
// EA  : 0x82AA56F0
// RVA : 0x00AA56F0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetWalkState::GetActionEventDef(idAction_SetWalkState *this)
{
  return &ACTION_SetWalkStateEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetSitState@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5750
// RVA : 0x00AA5750
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetSitState::GetActionEventDef(idAction_SetSitState *this)
{
  return &ACTION_SetSitStateEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetStandState@@UBAABVidEventDef@@XZ
// EA  : 0x82AA57B0
// RVA : 0x00AA57B0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetStandState::GetActionEventDef(idAction_SetStandState *this)
{
  return &ACTION_SetStandStateEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetIdleState@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5810
// RVA : 0x00AA5810
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetIdleState::GetActionEventDef(idAction_SetIdleState *this)
{
  return &ACTION_SetIdleStateEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_IgnorePlayerApproach@@UBAABVidEventDef@@XZ
// EA  : 0x82AA58F0
// RVA : 0x00AA58F0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_IgnorePlayerApproach::GetActionEventDef(idAction_IgnorePlayerApproach *this)
{
  return &ACTION_IgnorePlayerApproachEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_NoticePlayerApproach@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5950
// RVA : 0x00AA5950
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_NoticePlayerApproach::GetActionEventDef(idAction_NoticePlayerApproach *this)
{
  return &ACTION_NoticePlayerApproachEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetPlayerEnemy@@UBAABVidEventDef@@XZ
// EA  : 0x82AA59B0
// RVA : 0x00AA59B0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetPlayerEnemy::GetActionEventDef(idAction_SetPlayerEnemy *this)
{
  return &ACTION_SetPlayerEnemyEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetEnemy@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5A10
// RVA : 0x00AA5A10
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetEnemy::GetActionEventDef(idAction_SetEnemy *this)
{
  return &ACTION_SetEnemyEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SearchToTarget@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5A70
// RVA : 0x00AA5A70
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SearchToTarget::GetActionEventDef(idAction_SearchToTarget *this)
{
  return &ACTION_SearchToTargetEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetPlayerFocus@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5AD0
// RVA : 0x00AA5AD0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetPlayerFocus::GetActionEventDef(idAction_SetPlayerFocus *this)
{
  return &ACTION_SetPlayerFocusEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetActionNodeGroup@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5B30
// RVA : 0x00AA5B30
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetActionNodeGroup::GetActionEventDef(idAction_SetActionNodeGroup *this)
{
  return &ACTION_SetActionNodeGroupEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_Trigger@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5B90
// RVA : 0x00AA5B90
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_Trigger::GetActionEventDef(idAction_Trigger *this)
{
  return &ACTION_TriggerEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_EnableDamage@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5BF0
// RVA : 0x00AA5BF0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_EnableDamage::GetActionEventDef(idAction_EnableDamage *this)
{
  return &ACTION_EnableDamageEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_EnablePain@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5C50
// RVA : 0x00AA5C50
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_EnablePain::GetActionEventDef(idAction_EnablePain *this)
{
  return &ACTION_EnablePainEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_EnableAutoFocus@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5CB0
// RVA : 0x00AA5CB0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_EnableAutoFocus::GetActionEventDef(idAction_EnableAutoFocus *this)
{
  return &ACTION_EnableAutoFocusEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_EnableBodyRotation@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5D10
// RVA : 0x00AA5D10
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_EnableBodyRotation::GetActionEventDef(idAction_EnableBodyRotation *this)
{
  return &ACTION_EnableBodyRotationEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_EnableWalkIK@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5D70
// RVA : 0x00AA5D70
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_EnableWalkIK::GetActionEventDef(idAction_EnableWalkIK *this)
{
  return &ACTION_EnableWalkIKEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_EnableHeadTracking@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5DD0
// RVA : 0x00AA5DD0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_EnableHeadTracking::GetActionEventDef(idAction_EnableHeadTracking *this)
{
  return &ACTION_EnableHeadTrackingEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_ForceOpenCombat@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5E30
// RVA : 0x00AA5E30
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_ForceOpenCombat::GetActionEventDef(idAction_ForceOpenCombat *this)
{
  return &ACTION_ForceOpenCombatEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_ForceAwarenessByDistance@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5E90
// RVA : 0x00AA5E90
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_ForceAwarenessByDistance::GetActionEventDef(
        idAction_ForceAwarenessByDistance *this)
{
  return &ACTION_ForceAwarenessByDistanceEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_ForcePlayerInteraction@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5EF0
// RVA : 0x00AA5EF0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_ForcePlayerInteraction::GetActionEventDef(idAction_ForcePlayerInteraction *this)
{
  return &ACTION_ForcePlayerInteractionEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetAIVar@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5F50
// RVA : 0x00AA5F50
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetAIVar::GetActionEventDef(idAction_SetAIVar *this)
{
  return &ACTION_SetAIVarEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetScriptFlag@@UBAABVidEventDef@@XZ
// EA  : 0x82AA5FB0
// RVA : 0x00AA5FB0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetScriptFlag::GetActionEventDef(idAction_SetScriptFlag *this)
{
  return &ACTION_SetScriptFlagEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_ClearScriptFlag@@UBAABVidEventDef@@XZ
// EA  : 0x82AA6010
// RVA : 0x00AA6010
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_ClearScriptFlag::GetActionEventDef(idAction_ClearScriptFlag *this)
{
  return &ACTION_ClearScriptFlagEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetPerceptionFlag@@UBAABVidEventDef@@XZ
// EA  : 0x82AA6070
// RVA : 0x00AA6070
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetPerceptionFlag::GetActionEventDef(idAction_SetPerceptionFlag *this)
{
  return &ACTION_SetPerceptionFlagEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_ClearPerceptionFlag@@UBAABVidEventDef@@XZ
// EA  : 0x82AA60D0
// RVA : 0x00AA60D0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_ClearPerceptionFlag::GetActionEventDef(idAction_ClearPerceptionFlag *this)
{
  return &ACTION_ClearPerceptionFlagEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_GiveItem@@UBAABVidEventDef@@XZ
// EA  : 0x82AA6130
// RVA : 0x00AA6130
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_GiveItem::GetActionEventDef(idAction_GiveItem *this)
{
  return &ACTION_GiveItemEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_TakeItem@@UBAABVidEventDef@@XZ
// EA  : 0x82AA6190
// RVA : 0x00AA6190
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_TakeItem::GetActionEventDef(idAction_TakeItem *this)
{
  return &ACTION_TakeItemEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_ClearWorldState@@UBAABVidEventDef@@XZ
// EA  : 0x82AA61F0
// RVA : 0x00AA61F0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_ClearWorldState::GetActionEventDef(idAction_ClearWorldState *this)
{
  return &ACTION_ClearWorldStateEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_ShowAttachment@@UBAABVidEventDef@@XZ
// EA  : 0x82AA6250
// RVA : 0x00AA6250
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_ShowAttachment::GetActionEventDef(idAction_ShowAttachment *this)
{
  return &ACTION_ShowAttachmentEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_HideAttachment@@UBAABVidEventDef@@XZ
// EA  : 0x82AA62B0
// RVA : 0x00AA62B0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_HideAttachment::GetActionEventDef(idAction_HideAttachment *this)
{
  return &ACTION_HideAttachmentEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_DropAttachment@@UBAABVidEventDef@@XZ
// EA  : 0x82AA6310
// RVA : 0x00AA6310
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_DropAttachment::GetActionEventDef(idAction_DropAttachment *this)
{
  return &ACTION_DropAttachmentEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetMoveMode@@UBAABVidEventDef@@XZ
// EA  : 0x82AA6370
// RVA : 0x00AA6370
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetMoveMode::GetActionEventDef(idAction_SetMoveMode *this)
{
  return &ACTION_SetMoveModeEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_SetAccuracy@@UBAABVidEventDef@@XZ
// EA  : 0x82AA63D0
// RVA : 0x00AA63D0
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_SetAccuracy::GetActionEventDef(idAction_SetAccuracy *this)
{
  return &ACTION_SetAccuracyEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_ScriptedAnimWeb@@UBAABVidEventDef@@XZ
// EA  : 0x82AA6440
// RVA : 0x00AA6440
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_ScriptedAnimWeb::GetActionEventDef(idAction_ScriptedAnimWeb *this)
{
  return &ACTION_ScriptedAnimWebEnter;
}


// ========================================================================
// ?GetActionEventDef@idAction_MoveToScenePoint@@UBAABVidEventDef@@XZ
// EA  : 0x82AA67C8
// RVA : 0x00AA67C8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

const idEventDef *__fastcall idAction_MoveToScenePoint::GetActionEventDef(idAction_MoveToScenePoint *this)
{
  return &ACTION_MoveToScenePointEnter;
}


// ========================================================================
// ?GetActionEventName@idAIAction@@SA?AVidStr@@ABV2@@Z
// EA  : 0x82BB8FD8
// RVA : 0x00BB8FD8
// PDB : w:\tech5\tungsten\game\ai\fsm\aiaction.h
// ========================================================================

idStr *__fastcall idAIAction::GetActionEventName(idStr *result, const idStr *name)
{
  operator+(result, a: name, b: "Enter");
  return result;
}

