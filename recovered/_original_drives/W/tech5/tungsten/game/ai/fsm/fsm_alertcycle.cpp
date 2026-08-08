
// ========================================================================
// ?Evaluate@AC_ExecutingScript@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB9610
// RVA : 0x00AB9610
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_ExecutingScript::Evaluate(
        AC_ExecutingScript *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::IsExecutingScript(this: ai) ? 0 : 0xEB;
}


// ========================================================================
// ?Evaluate@AC_UnhandledError@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB9648
// RVA : 0x00AB9648
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall AC_UnhandledError::Evaluate(
        AC_UnhandledError *this,
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
    return 0;
  v7 = (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) != 0;
  result = TRANSCODE_AC_UNHANDLED_CHILD_ERROR;
  if ( !v7 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@AC_IsOnElevator@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB9690
// RVA : 0x00AB9690
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_IsOnElevator::Evaluate(
        AC_IsOnElevator *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return (unsigned __int8)idAI2::IsOnElevator(this: ai) == 0 ? 0 : 0xF4;
}


// ========================================================================
// ?Evaluate@AC_IsRelaxed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB96C8
// RVA : 0x00AB96C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_IsRelaxed::Evaluate(
        AC_IsRelaxed *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 219;
}


// ========================================================================
// ?InternalInitState@idAlertCycle_Default@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB96D0
// RVA : 0x00AB96D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Default::InternalInitState(idAlertCycle_Default *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_UnhandledError::Type,
    nextStateType: &idAlertCycle_UnhandledError::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_IsOnElevator::Type,
    nextStateType: &idAlertCycle_OnElevator::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_ExecutingScript::Type,
    nextStateType: &idAlertCycle_ExecuteDoomscript::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_DropDone::Type,
    nextStateType: &idAlertCycle_PerformDropLanding::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_ShouldDropFromShip::Type,
    nextStateType: &idAlertCycle_DropFromShip::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_ShouldAvoid::Type, nextStateType: &idAlertCycle_Avoid::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_CanUseCombat::Type, nextStateType: &idAlertCycle_Combat::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_CanUseCombatScenePoint::Type,
    nextStateType: &idAlertCycle_CombatScenePoint::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_CanUseSearchScenePoint::Type,
    nextStateType: &idAlertCycle_SearchScenePoint::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_CanUseRoamScenePoint::Type,
    nextStateType: &idAlertCycle_RoamScenePoint::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_CanUseSearch::Type, nextStateType: &idAlertCycle_Search::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_IsRelaxed::Type, nextStateType: &idAlertCycle_Relaxed::Type);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Dying::Type, transCode: 216);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Pain::Type, transCode: 211);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &AC_ShouldBecomePassified::Type,
    nextStateType: &idAlertCycle_Passified::Type);
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_Default@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB9898
// RVA : 0x00AB9898
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Default::AIState_EnterState(
        idAlertCycle_Default *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAI2::SetAlertCycle(this: ai, ac: ALERTCYCLE_RELAXED);
}


// ========================================================================
// ?Evaluate@AC_DoomscriptDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB98A8
// RVA : 0x00AB98A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_DoomscriptDone::Evaluate(
        AC_DoomscriptDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return idAI2::IsExecutingScript(this: ai) ? 0 : 0xEC;
}


// ========================================================================
// ?InternalInitState@idAlertCycle_ExecuteDoomscript@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB98E0
// RVA : 0x00AB98E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_ExecuteDoomscript::InternalInitState(
        idAlertCycle_ExecuteDoomscript *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_ScriptCanUseCombat::Type,
    nextStateType: &idAlertCycle_Combat::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_ScriptCanUseSearch::Type,
    nextStateType: &idAlertCycle_Search::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_DoomscriptDone::Type,
    nextStateType: &idAlertCycle_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_UnhandledError::Type,
    nextStateType: &idAlertCycle_UnhandledError::Type);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Dying::Type, transCode: 216);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Pain::Type, transCode: 211);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &AC_ShouldBecomePassified::Type,
    nextStateType: &idAlertCycle_Passified::Type);
}


// ========================================================================
// ?InternalInitState@idAlertCycle_ExecuteCodeMoveAction@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB99C8
// RVA : 0x00AB99C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_ExecuteCodeMoveAction::InternalInitState(
        idAlertCycle_ExecuteCodeMoveAction *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &Shared_MoveDone::Type, nextStateType: &idAlertCycle_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_UnhandledError::Type,
    nextStateType: &idAlertCycle_UnhandledError::Type);
}


// ========================================================================
// ?InternalInitState@idAlertCycle_ActionScript@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB9A30
// RVA : 0x00AB9A30
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_ActionScript::InternalInitState(
        idAlertCycle_ActionScript *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_ScriptCanUseCombat::Type,
    nextStateType: &idAlertCycle_Combat::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_ScriptCanUseSearch::Type,
    nextStateType: &idAlertCycle_Search::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_PlayerApproaching::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_NoActionScript::Type,
    nextStateType: &idAlertCycle_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_UnhandledError::Type,
    nextStateType: &idAlertCycle_UnhandledError::Type);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Dying::Type, transCode: 216);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Pain::Type, transCode: 211);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &AC_PlayerApproaching::Type,
    nextStateType: &idAlertCycle_Default::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &AC_ShouldBecomePassified::Type,
    nextStateType: &idAlertCycle_Passified::Type);
}


// ========================================================================
// ?AIState_ExitState@idAlertCycle_ActionScript@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB9B38
// RVA : 0x00AB9B38
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_ActionScript::AIState_ExitState(
        idAlertCycle_ActionScript *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAI2::ClearWaitForOverrideAnim(this: ai, priority: PRIORITY_LOW);
}


// ========================================================================
// ?InternalInitState@idAlertCycle_Relaxed@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB9B48
// RVA : 0x00AB9B48
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Relaxed::InternalInitState(idAlertCycle_Relaxed *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_UnhandledError::Type,
    nextStateType: &idAlertCycle_UnhandledError::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_ShouldAvoid::Type, nextStateType: &idAlertCycle_Avoid::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_CanUseCombat::Type, nextStateType: &idAlertCycle_Combat::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_CanUseCombatScenePoint::Type,
    nextStateType: &idAlertCycle_CombatScenePoint::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_CanUseRoamScenePoint::Type,
    nextStateType: &idAlertCycle_RoamScenePoint::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_CanUseSearch::Type, nextStateType: &idAlertCycle_Search::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &AC_PossessedGuyAround::Type,
    nextStateType: &idAlertCycle_WatchPossessedGuy::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &AC_ShouldBecomePassified::Type,
    nextStateType: &idAlertCycle_Passified::Type);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Pain::Type, transCode: 211);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Dying::Type, transCode: 216);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Stuck::Type, transCode: 449);
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_Relaxed@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB9CA0
// RVA : 0x00AB9CA0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Relaxed::AIState_EnterState(
        idAlertCycle_Relaxed *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAI2::SetAlertCycle(this: ai, ac: ALERTCYCLE_RELAXED);
  ai->DisableAIEventResponse(this: ai, a2: AIEVENT_AIM);
}


// ========================================================================
// ?InternalInitState@idAlertCycle_Passified@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB9CF0
// RVA : 0x00AB9CF0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Passified::InternalInitState(
        idAlertCycle_Passified *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_UnhandledError::Type,
    nextStateType: &idAlertCycle_UnhandledError::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_ExecutingScript::Type,
    nextStateType: &idAlertCycle_ExecuteDoomscript::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_ShouldAvoid::Type, nextStateType: &idAlertCycle_Avoid::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_CanUseCombat::Type, nextStateType: &idAlertCycle_Combat::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_CanUseCombatScenePoint::Type,
    nextStateType: &idAlertCycle_CombatScenePoint::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_CanUseRoamScenePoint::Type,
    nextStateType: &idAlertCycle_RoamScenePoint::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_CanUseSearch::Type, nextStateType: &idAlertCycle_Search::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_IsRelaxed::Type, nextStateType: &idAlertCycle_Relaxed::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &AC_PossessedGuyAround::Type,
    nextStateType: &idAlertCycle_WatchPossessedGuy::Type);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Pain::Type, transCode: 211);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Dying::Type, transCode: 216);
}


// ========================================================================
// ?InternalInitState@idAlertCycle_Combat@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB9E48
// RVA : 0x00AB9E48
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Combat::InternalInitState(idAlertCycle_Combat *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_UnhandledError::Type,
    nextStateType: &idAlertCycle_UnhandledError::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_NoEnemy::Type,
    nextStateType: &idAlertCycle_Relaxed::Type,
    transCode: 230);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_NoEnemy::Type,
    nextStateType: &idAlertCycle_Combat::Type,
    transCode: 23);
  idState::AddStateTransition(this, fsm, transType: &AC_ShouldAvoid::Type, nextStateType: &idAlertCycle_Avoid::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_CanUseSearch::Type, nextStateType: &idAlertCycle_Search::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_CombatDone::Type, nextStateType: &idAlertCycle_Relaxed::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &AC_PossessedGuyAround::Type,
    nextStateType: &idAlertCycle_WatchPossessedGuy::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &AC_ShouldBecomePassified::Type,
    nextStateType: &idAlertCycle_Passified::Type);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Pain::Type, transCode: 211);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Stuck::Type, transCode: 449);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Dying::Type, transCode: 216);
}


// ========================================================================
// ?InternalInitState@idAlertCycle_CombatScenePoint@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB9F90
// RVA : 0x00AB9F90
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_CombatScenePoint::InternalInitState(
        idAlertCycle_CombatScenePoint *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &AC_CombatDone::Type, nextStateType: &idAlertCycle_Relaxed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_CanUseSearchScenePoint::Type,
    nextStateType: &idAlertCycle_SearchScenePoint::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_CanUseRoamScenePoint::Type,
    nextStateType: &idAlertCycle_RoamScenePoint::Type);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Pain::Type, transCode: 211);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Stuck::Type, transCode: 449);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Dying::Type, transCode: 216);
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_CombatScenePoint@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABA058
// RVA : 0x00ABA058
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_CombatScenePoint::AIState_EnterState(
        idAlertCycle_CombatScenePoint *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAI2::SetAlertCycle(this: ai, ac: ALERTCYCLE_COMBAT);
  idAI2::LeaveActionNode(this: ai, force: true);
  ai->EnableAIEventResponse(this: ai, a2: AIEVENT_AIM);
}


// ========================================================================
// ?InternalInitState@idAlertCycle_RoamScenePoint@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ABA0B0
// RVA : 0x00ABA0B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_RoamScenePoint::InternalInitState(
        idAlertCycle_RoamScenePoint *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_CanUseCombatScenePoint::Type,
    nextStateType: &idAlertCycle_CombatScenePoint::Type);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Pain::Type, transCode: 211);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Stuck::Type, transCode: 449);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Dying::Type, transCode: 216);
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_RoamScenePoint@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABA140
// RVA : 0x00ABA140
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_RoamScenePoint::AIState_EnterState(
        idAlertCycle_RoamScenePoint *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAI2::SetAlertCycle(this: ai, ac: ALERTCYCLE_RELAXED);
  idAI2::LeaveActionNode(this: ai, force: true);
}


// ========================================================================
// ?InternalInitState@idAlertCycle_SearchScenePoint@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ABA180
// RVA : 0x00ABA180
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_SearchScenePoint::InternalInitState(
        idAlertCycle_SearchScenePoint *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_CanUseCombatScenePoint::Type,
    nextStateType: &idAlertCycle_CombatScenePoint::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_CanUseRoamScenePoint::Type,
    nextStateType: &idAlertCycle_RoamScenePoint::Type);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Pain::Type, transCode: 211);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Stuck::Type, transCode: 449);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Dying::Type, transCode: 216);
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_SearchScenePoint@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABA230
// RVA : 0x00ABA230
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_SearchScenePoint::AIState_EnterState(
        idAlertCycle_SearchScenePoint *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAI2::SetAlertCycle(this: ai, ac: ALERTCYCLE_SEARCH);
  ai->EnableAIEventResponse(this: ai, a2: AIEVENT_AIM);
}


// ========================================================================
// ?InternalInitState@idAlertCycle_Search@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ABA280
// RVA : 0x00ABA280
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Search::InternalInitState(idAlertCycle_Search *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_UnhandledError::Type,
    nextStateType: &idAlertCycle_UnhandledError::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_NoEnemy::Type, nextStateType: &idAlertCycle_Relaxed::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_ShouldAvoid::Type, nextStateType: &idAlertCycle_Avoid::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_CanUseCombat::Type, nextStateType: &idAlertCycle_Combat::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_CanUseCombatScenePoint::Type,
    nextStateType: &idAlertCycle_CombatScenePoint::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_CanUseRoamScenePoint::Type,
    nextStateType: &idAlertCycle_RoamScenePoint::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_SearchFinished::Type,
    nextStateType: &idAlertCycle_Relaxed::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &AC_PossessedGuyAround::Type,
    nextStateType: &idAlertCycle_WatchPossessedGuy::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &AC_ShouldBecomePassified::Type,
    nextStateType: &idAlertCycle_Passified::Type);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Pain::Type, transCode: 211);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Stuck::Type, transCode: 449);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Dying::Type, transCode: 216);
}


// ========================================================================
// ?InternalInitState@idAlertCycle_Pain@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ABA3D8
// RVA : 0x00ABA3D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Pain::InternalInitState(idAlertCycle_Pain *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_UnhandledError::Type,
    nextStateType: &idAlertCycle_UnhandledError::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_PainFinishedMelee::Type,
    nextStateType: &idAlertCycle_Default::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_PainFinished::Type, nextStateType: &idAlertCycle_Default::Type);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Dying::Type, transCode: 216);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Pain::Type, transCode: 211);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &AC_ShouldBecomePassified::Type,
    nextStateType: &idAlertCycle_Passified::Type);
}


// ========================================================================
// ?InternalInitState@idAlertCycle_Melee@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ABA490
// RVA : 0x00ABA490
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Melee::InternalInitState(idAlertCycle_Melee *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_UnhandledError::Type,
    nextStateType: &idAlertCycle_UnhandledError::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_MeleeFinished::Type, nextStateType: &idAlertCycle_Combat::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_ShouldBecomePassified::Type,
    nextStateType: &idAlertCycle_Passified::Type);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Dying::Type, transCode: 216);
}


// ========================================================================
// ?InternalInitState@idAlertCycle_Dying@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ABA528
// RVA : 0x00ABA528
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Dying::InternalInitState(idAlertCycle_Dying *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &AC_DyingFinished::Type, nextStateType: &idAlertCycle_Dead::Type);
}


// ========================================================================
// ?InternalInitState@idAlertCycle_Avoid@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ABA540
// RVA : 0x00ABA540
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Avoid::InternalInitState(idAlertCycle_Avoid *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &AC_AvoidDone::Type, nextStateType: &idAlertCycle_Default::Type);
  idState::AddStateTransition(this, fsm, transType: &AC_AvoidFailed::Type, nextStateType: &idAlertCycle_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_ShouldBecomePassified::Type,
    nextStateType: &idAlertCycle_Passified::Type);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Dying::Type, transCode: 216);
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_Avoid@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABA5C0
// RVA : 0x00ABA5C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Avoid::AIState_EnterState(
        idAlertCycle_Avoid *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAI2::SetAlertCycle(this: ai, ac: ALERTCYCLE_COMBAT);
  ai->DisableAIEventResponse(this: ai, a2: AIEVENT_AIM);
  ai->DisableAIEventResponse(this: ai, a2: AIEVENT_GRENADE);
  ai->DisableAIEventResponse(this: ai, a2: AIEVENT_VEHICLE);
}


// ========================================================================
// ?AIState_ExitState@idAlertCycle_Avoid@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABA640
// RVA : 0x00ABA640
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Avoid::AIState_ExitState(idAlertCycle_Avoid *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  ((void (__fastcall *)(idAI2 *, int, idAIFSM *, int))ai->EnableAIEventResponse)(a1: ai, a2: 64, a3: fsm, a4: curTime);
  ai->EnableAIEventResponse(this: ai, a2: AIEVENT_GRENADE);
  ai->EnableAIEventResponse(this: ai, a2: AIEVENT_VEHICLE);
}


// ========================================================================
// ?InternalInitState@idAlertCycle_WatchPossessedGuy@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ABA6B0
// RVA : 0x00ABA6B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_WatchPossessedGuy::InternalInitState(
        idAlertCycle_WatchPossessedGuy *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_UnhandledError::Type,
    nextStateType: &idAlertCycle_UnhandledError::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &AC_PossessedGuyGone::Type,
    nextStateType: &idAlertCycle_Default::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &AC_ShouldBecomePassified::Type,
    nextStateType: &idAlertCycle_Passified::Type);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Pain::Type, transCode: 211);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Dying::Type, transCode: 216);
}


// ========================================================================
// ?InternalInitState@idAlertCycle_DropFromShip@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ABA760
// RVA : 0x00ABA760
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_DropFromShip::InternalInitState(
        idAlertCycle_DropFromShip *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AC_DropDone::Type,
    nextStateType: &idAlertCycle_PerformDropLanding::Type);
}


// ========================================================================
// ?InternalInitState@idAlertCycle_PerformDropLanding@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ABA778
// RVA : 0x00ABA778
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_PerformDropLanding::InternalInitState(
        idAlertCycle_PerformDropLanding *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &AC_LandDone::Type, nextStateType: &idAlertCycle_Default::Type);
}


// ========================================================================
// ?AIState_ExitState@idAlertCycle_PerformDropLanding@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABA790
// RVA : 0x00ABA790
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_PerformDropLanding::AIState_ExitState(
        idAlertCycle_PerformDropLanding *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAI2::DropComplete(this: ai);
}


// ========================================================================
// ?Evaluate@AC_NotOnElevator@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABA798
// RVA : 0x00ABA798
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_NotOnElevator::Evaluate(
        AC_NotOnElevator *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return (unsigned __int8)idAI2::IsOnElevator(this: ai) != 0 ? 0 : 0xF5;
}


// ========================================================================
// ?InternalInitState@idAlertCycle_OnElevator@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ABA7D0
// RVA : 0x00ABA7D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_OnElevator::InternalInitState(
        idAlertCycle_OnElevator *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &AC_NotOnElevator::Type, nextStateType: &idAlertCycle_Default::Type);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Dying::Type, transCode: 216);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Pain::Type, transCode: 211);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &AC_ShouldBecomePassified::Type,
    nextStateType: &idAlertCycle_Passified::Type);
}


// ========================================================================
// ?InternalInitState@idAlertCycle_Stuck@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ABA868
// RVA : 0x00ABA868
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Stuck::InternalInitState(idAlertCycle_Stuck *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &AC_Unstuck::Type, nextStateType: &idAlertCycle_Default::Type);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Dying::Type, transCode: 216);
  idState::AddFSMEventTransition(this, fsm, nextStateType: &idAlertCycle_Pain::Type, transCode: 211);
}


// ========================================================================
// ?Evaluate@AC_Restart@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABA8E0
// RVA : 0x00ABA8E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_Restart::Evaluate(
        AC_Restart *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 207;
}


// ========================================================================
// ?InternalInitState@idAlertCycle_UnhandledError@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ABA8E8
// RVA : 0x00ABA8E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_UnhandledError::InternalInitState(
        idAlertCycle_UnhandledError *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &AC_Restart::Type, nextStateType: &idAlertCycle_Default::Type);
}


// ========================================================================
// ?Evaluate@AC_ShouldDropFromShip@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABA918
// RVA : 0x00ABA918
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_ShouldDropFromShip::Evaluate(
        AC_ShouldDropFromShip *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  if ( ai->aiVolatile.dropState != 0 )
    return 0;
  ai->aiVolatile.dropState = 1;
  return 239;
}


// ========================================================================
// ?Evaluate@AC_CanUseCombat@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABA948
// RVA : 0x00ABA948
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_CanUseCombat::Evaluate(
        AC_CanUseCombat *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  const aiSenseState_t *EnemySenseState; // r30
  idFiniteStateMachine *v10; // r3

  if ( (unsigned __int8)idAI2::UsesScenePoints(this: ai) != 0
    || idComponentActionScript::RunningActionScript(this: &ai->actionScript, entity: ai)
    && (ai->aiVolatile.script.flags & 1) == 0 )
  {
    return 0;
  }
  if ( (ai->aiVolatile.groupStatus.condition & 0x1000) != 0 )
  {
    EnemySenseState = idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
    if ( EnemySenseState != nullptr
      && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
       - EnemySenseState->lastConfirmedStimTime < 1000 )
    {
      ai->aiVolatile.groupStatus.condition &= ~0x1000u;
      goto LABEL_9;
    }
    return 0;
  }
LABEL_9:
  v10 = parentFSM->manager->FindFSM_4(this: parentFSM->manager, a2: "FSM_combat");
  return !v10->CanUse(this: v10, a2: parentFSM, a3: curTime) ? 0 : 0xD1;
}


// ========================================================================
// ?Evaluate@AC_CanUseSearch@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABAA70
// RVA : 0x00ABAA70
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_CanUseSearch::Evaluate(
        AC_CanUseSearch *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  idFiniteStateMachine *v9; // r3

  if ( idComponentActionScript::RunningActionScript(this: &ai->actionScript, entity: ai)
    && (ai->aiVolatile.script.flags & 2) == 0 )
  {
    return 0;
  }
  v9 = parentFSM->manager->FindFSM_4(this: parentFSM->manager, a2: "FSM_search");
  return !v9->CanUse(this: v9, a2: parentFSM, a3: curTime) ? 0 : 0xD2;
}


// ========================================================================
// ?AC_InPain@@YA?AW4aiTransCode_t@idAIStateTransition@@PBVidEntity@@@Z
// EA  : 0x82ABAB18
// RVA : 0x00ABAB18
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall AC_InPain(idAI2 *owner)
{
  idAI2 *v1; // r31
  painType_t type; // r11
  idAIStateTransition::aiTransCode_t result; // r3

  v1 = idAI2::CastTo(c: owner);
  if ( idEntity::GetPhysics(this: v1)->type != PHYSICS_AI )
    return 0;
  if ( BYTE2(idEntity::GetPhysics(this: v1)[9].clip) == 0 )
    return 0;
  type = v1->actorVolatile.pain.type;
  if ( type == PAIN_NONE )
    return 0;
  result = TRANSCODE_AC_IN_PAIN;
  if ( type == PAIN_DEATH )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@AC_ShouldAvoid@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABAB88
// RVA : 0x00ABAB88
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_ShouldAvoid::Evaluate(
        AC_ShouldAvoid *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  idFiniteStateMachine *v8; // r3

  if ( idComponentActionScript::RunningActionScript(this: &ai->actionScript, entity: ai) )
    return 0;
  v8 = parentFSM->manager->FindFSM_4(this: parentFSM->manager, a2: "FSM_avoid");
  return !v8->CanUse(this: v8, a2: parentFSM, a3: curTime) ? 0 : 0xE3;
}


// ========================================================================
// ?Evaluate@AC_PossessedGuyAround@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABAC28
// RVA : 0x00ABAC28
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_PossessedGuyAround::Evaluate(
        AC_PossessedGuyAround *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return parentFSM->eventId != 0x2000 ? 0 : 0xE8;
}


// ========================================================================
// ?Evaluate@AC_ScriptCanUseCombat@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABAC48
// RVA : 0x00ABAC48
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_ScriptCanUseCombat::Evaluate(
        AC_ScriptCanUseCombat *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  int v8; // r3

  if ( (ai->aiVolatile.script.flags & 1) == 0 )
    return 0;
  v8 = ((int (__fastcall *)(idFSMManager *, const char *, idAIFSM *, idAIState *))parentFSM->manager->FindFSM_4)(
         a1: parentFSM->manager,
         a2: "FSM_combat",
         a3: parentFSM,
         a4: state);
  return (*(unsigned __int8 (__fastcall **)(int, idAIFSM *, int))(*(_DWORD *)v8 + 24))(
           a1: v8,
           a2: parentFSM,
           a3: curTime) == 0
       ? 0
       : 0xD1;
}


// ========================================================================
// ?Evaluate@AC_ScriptCanUseSearch@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABACE8
// RVA : 0x00ABACE8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_ScriptCanUseSearch::Evaluate(
        AC_ScriptCanUseSearch *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  int v8; // r3

  if ( (ai->aiVolatile.script.flags & 2) == 0 )
    return 0;
  v8 = ((int (__fastcall *)(idFSMManager *, const char *, idAIFSM *, idAIState *))parentFSM->manager->FindFSM_4)(
         a1: parentFSM->manager,
         a2: "FSM_search",
         a3: parentFSM,
         a4: state);
  return (*(unsigned __int8 (__fastcall **)(int, idAIFSM *, int))(*(_DWORD *)v8 + 24))(
           a1: v8,
           a2: parentFSM,
           a3: curTime) == 0
       ? 0
       : 0xD2;
}


// ========================================================================
// ?Evaluate@AC_NoActionScript@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABAD88
// RVA : 0x00ABAD88
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_NoActionScript::Evaluate(
        AC_NoActionScript *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int GameMs; // r3

  if ( idComponentActionScript::RunningActionScript(this: &ai->actionScript, entity: ai) )
    return 0;
  if ( ai_debugActionScript.valueInteger > 0 )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(fmt: "(%d) AlertCycle_ActionScript ended\n", GameMs);
  }
  return 224;
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_ActionScript@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABAE18
// RVA : 0x00ABAE18
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_ActionScript::AIState_EnterState(
        idAlertCycle_ActionScript *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  ai->aiVolatile.focus.enableGreetings = false;
  ai->aiVolatile.script.flags &= ~0x200u;
}


// ========================================================================
// ?Evaluate@AC_PassifiedDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABAE38
// RVA : 0x00ABAE38
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_PassifiedDone::Evaluate(
        AC_PassifiedDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0xEE;
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_Passified@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABAE78
// RVA : 0x00ABAE78
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Passified::AIState_EnterState(
        idAlertCycle_Passified *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idEventArg *v7; // r3
  idEventArg v8; // [sp+90h] [-60h] BYREF
  idEventReceiver v9[5]; // [sp+B0h] [-40h] BYREF

  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  v7 = idEventArg::idEventArg(this: &v8, data: ai);
  idEventReceiver::ProcessEvent(
    this: v9,
    result: fsm,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]));
}


// ========================================================================
// ?Evaluate@AC_CombatDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABAF00
// RVA : 0x00ABAF00
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_CombatDone::Evaluate(
        AC_CombatDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3

  if ( idFile_SaveGamePipelined::GetFullPath(this: state) == 0 )
    return 220;
  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  return idFiniteStateMachine::GetStatus(this: FullPath) != 0 ? 0 : 0xDC;
}


// ========================================================================
// ?Evaluate@AC_SearchFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABAF70
// RVA : 0x00ABAF70
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_SearchFinished::Evaluate(
        AC_SearchFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3

  if ( idFile_SaveGamePipelined::GetFullPath(this: state) == 0 )
    return 221;
  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  return idFiniteStateMachine::GetStatus(this: FullPath) != 0 ? 0 : 0xDD;
}


// ========================================================================
// ?Evaluate@AC_PainFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABAFE0
// RVA : 0x00ABAFE0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_PainFinished::Evaluate(
        AC_PainFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  if ( !ai->aiVolatile.memory.painFailed )
    return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0xD4;
  ai->aiVolatile.memory.painFailed = false;
  return 212;
}


// ========================================================================
// ?AIState_Work@idAlertCycle_Pain@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABB050
// RVA : 0x00ABB050
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Pain::AIState_Work(idAlertCycle_Pain *this, idAI2 *ai, idAIFSM *fsm, const int curTime)
{
  idRibbon::~idRibbon(this: (idRibbon *)&ai->aiVolatile.meleeTrace);
}


// ========================================================================
// ?Evaluate@AC_AvoidDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABB060
// RVA : 0x00ABB060
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_AvoidDone::Evaluate(
        AC_AvoidDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3

  if ( idFile_SaveGamePipelined::GetFullPath(this: state) == 0 )
    return 228;
  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  return idFiniteStateMachine::GetStatus(this: FullPath) != 0 ? 0 : 0xE4;
}


// ========================================================================
// ?Evaluate@AC_PossessedGuyGone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABB0D0
// RVA : 0x00ABB0D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_PossessedGuyGone::Evaluate(
        AC_PossessedGuyGone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return parentFSM->eventId == 0x2000 ? 0 : 0xE8;
}


// ========================================================================
// ?Evaluate@AC_DropDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABB0F0
// RVA : 0x00ABB0F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_DropDone::Evaluate(
        AC_DropDone *this,
        _exception *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 || ai[192].type == 3 )
    return WORD5(ai[956].arg2) != 2 ? 0 : 0xF0;
  else
    return 0;
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_DropFromShip@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABB170
// RVA : 0x00ABB170
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_DropFromShip::AIState_EnterState(
        idAlertCycle_DropFromShip *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  double maxDropSpeed; // fp31

  idAI2::SetAlertCycle(this: ai, ac: ALERTCYCLE_COMBAT);
  if ( idEntity::GetPhysics(this: ai)->type == PHYSICS_AI )
  {
    BYTE2(idEntity::GetPhysics(this: ai)[9].clip) = 0;
    maxDropSpeed = ai->aiEditable.maxDropSpeed;
    *(float *)&idEntity::GetPhysics(this: ai)[13].entityNumber = maxDropSpeed;
  }
  else
  {
    idLib::Warning(
      fmt: "AI '%s' does not have physics type 'PHYSICS_AI', but entered the DropFromShip State",
      ai->name.data);
  }
  idAI2::ResetAnimState(this: ai, web: AIANIMWEB_BODY, subWeb: AISUBWEB_DROPSHIP_FALL, stateName: "drop_cycle");
}


// ========================================================================
// ?AIState_Work@idAlertCycle_DropFromShip@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABB210
// RVA : 0x00ABB210
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_DropFromShip::AIState_Work(
        idAlertCycle_DropFromShip *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  float *Physics; // r30
  idPhysics *v6; // r30
  idPhysics *v7; // r29
  int GameMs; // r28
  idPresentable *presentable; // r31
  const idMat3 *v10; // r30
  const idVec3 *v11; // r3
  _BYTE v12[8]; // [sp+50h] [-40h] BYREF
  float v13; // [sp+58h] [-38h]

  Physics = (float *)idEntity::GetPhysics(this: ai);
  (*(void (__fastcall **)(_BYTE *, float *, _DWORD))(*(_DWORD *)Physics + 88))(a1: v12, a2: Physics, a3: 0);
  if ( __fabs((float)(ai->aiEditable.maxDropSpeed - Physics[160])) < 0.5
    && v13 < (double)(float)(ai->aiEditable.maxDropSpeed + (float)2.0) )
  {
    Physics[160] = ai->aiEditable.maxDropSpeed - (float)2.0;
    v6 = idEntity::GetPhysics(this: ai);
    v7 = idEntity::GetPhysics(this: ai);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    if ( ai->presentable == nullptr )
      idEntity::InitPresentableInternal(this: ai);
    presentable = ai->presentable;
    v10 = v6->GetAxis(this: v6, a2: 0);
    v11 = v7->GetOrigin(this: v7, a2: 0);
    idFXManager::StartFX(this: &presentable->fxManager, org: v11, axis: v10, time: GameMs, startCondition: 3);
  }
}


// ========================================================================
// ?Evaluate@AC_LandDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABB330
// RVA : 0x00ABB330
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_LandDone::Evaluate(
        AC_LandDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0xF1;
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_PerformDropLanding@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABB370
// RVA : 0x00ABB370
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_PerformDropLanding::AIState_EnterState(
        idAlertCycle_PerformDropLanding *this,
        _exception *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idPhysics *Physics; // r3
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v6; // [sp+50h] [-30h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v7; // [sp+52h] [-2Eh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v8; // [sp+54h] [-2Ch] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v9; // [sp+56h] [-2Ah] BYREF
  float v10[4]; // [sp+58h] [-28h] BYREF

  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) == 0 )
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)((char *)&ai[190].arg2 + 4));
  Physics = idEntity::GetPhysics(this: (idEntity *)ai);
  v10[0] = 0.0;
  v10[1] = 0.0;
  v10[2] = 0.0;
  Physics->SetLinearVelocity(this: Physics, a2: (const idVec3 *)v10, a3: 0);
  v9.value = -1;
  v8.value = -1;
  idAI2::FindAnimWebAndStateIndices(
    this: (idAI2 *)ai,
    web: AIANIMWEB_BODY,
    subWeb: 22,
    stateName: "drop_land",
    changeWeapon: false,
    newWeapon: nullptr,
    subWebIndex: &v9,
    stateIndex: &v8);
  v7.value = -1;
  v6.value = -1;
  idAI2::FindAnimWebAndStateIndices(
    this: (idAI2 *)ai,
    web: AIANIMWEB_BODY,
    subWeb: 1,
    stateName: "idle",
    changeWeapon: false,
    newWeapon: nullptr,
    subWebIndex: &v7,
    stateIndex: &v6);
  if ( idAI2::ChangeAnimStateVia(
         this: (idAI2 *)ai,
         web: AIANIMWEB_BODY,
         subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v7.value,
         stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v6.value,
         viaSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v9.value,
         viaStateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v8.value,
         interruptPath: INTR_PATH_YES,
         interruptBlend: INTR_BLEND_NO) != 1 )
    idLib::Warning(
      fmt: "AI '%s' had trouble changing anim state while peforming a drop landing.",
      (const char *)HIDWORD(ai->arg1));
  idAI2::SetAnimWebEvent(
    this: (idAI2 *)ai,
    web: AIANIMWEB_BODY,
    priority: PRIORITY_LOW,
    swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v7.value,
    si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v6.value,
    eventType: ANIMWEB_EVENT_START_BLEND_IN,
    eventDef: &EV_AnimWeb_Wait);
}


// ========================================================================
// ?AIState_ExitState@idCombatScenePoint_Reload@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABB4B8
// RVA : 0x00ABB4B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idCombatScenePoint_Reload::AIState_ExitState(
        idAlertCycle_OnElevator *this,
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

  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  HIBYTE(v9[0]) = 105;
  v9[1] = 1;
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
// ?Evaluate@AC_Unstuck@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABB560
// RVA : 0x00ABB560
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall AC_Unstuck::Evaluate(
        AC_Unstuck *this,
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
    return TRANSCODE_AC_UNSTUCK;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_AC_UNSTUCK;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_Stuck@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABB5A8
// RVA : 0x00ABB5A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Stuck::AIState_EnterState(
        idAlertCycle_Stuck *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idPhysics *Physics; // r3
  float *p_clip; // r28
  const idVec3 *v9; // r29
  idAIOrientation *MoveOrientation; // r3
  double v11; // fp13
  double v12; // fp11
  double v15; // fp5
  double v16; // fp9
  double v17; // fp28
  double v18; // fp27
  double v19; // fp22
  idAIOrientation *BodyOrientation; // r3
  idPhysics *v21; // r3
  float *v22; // r3
  double v23; // fp13
  double v24; // fp12
  double x; // fp26
  double y; // fp25
  double z; // fp23
  double v30; // fp6
  double v31; // fp10
  double v32; // fp9
  double v33; // fp8
  double v36; // fp2
  double v37; // fp7
  idPhysics *v38; // r3
  float *v39; // r3
  const idAAS2 *(__fastcall *GetAAS)(struct idAI2 *); // r6
  double v41; // fp1
  double v42; // fp12
  int *v43; // r25
  unsigned int v44; // r24
  idPhysics *v45; // r3
  int v46; // r23
  int v47; // r30
  const idAAS2 *v48; // r3
  int AreaNum; // r3
  idEventArg *v50; // r21
  idPhysics *v51; // r3
  const idVec3 *v52; // r3
  double v53; // fp31
  double v54; // fp29
  double v55; // fp24
  idPhysics *v56; // r3
  float *v57; // r3
  double v58; // fp9
  double v59; // fp7
  idPhysics *v60; // r3
  const idVec3 *v61; // r3
  idPhysics *v62; // r3
  float *v63; // r3
  double v64; // fp4
  double v65; // fp3
  idPhysics *v66; // r3
  const idVec3 *v67; // r3
  idPhysics *v68; // r3
  float *v69; // r3
  double v70; // fp11
  double v71; // fp9
  idPhysics *v72; // r3
  const idVec3 *v73; // r3
  idColor *v74; // r4
  idEventArg *v75; // r29
  const idEventArg *v76; // [sp+8h] [-368h]
  const idEventArg *v77; // [sp+Ch] [-364h]
  _BYTE v78[20]; // [sp+70h] [-300h] BYREF
  _BYTE v79[20]; // [sp+90h] [-2E0h] BYREF
  _BYTE v80[20]; // [sp+B0h] [-2C0h] BYREF
  _BYTE v81[20]; // [sp+D0h] [-2A0h] BYREF
  _BYTE v82[20]; // [sp+F0h] [-280h] BYREF
  float v83; // [sp+110h] [-260h] BYREF
  float v84; // [sp+114h] [-25Ch]
  float v85; // [sp+118h] [-258h]
  float v86[4]; // [sp+120h] [-250h] BYREF
  float v87[4]; // [sp+130h] [-240h] BYREF
  idVec3 v88; // [sp+140h] [-230h] BYREF
  float v89[4]; // [sp+150h] [-220h] BYREF
  const idEventArg *v90[5]; // [sp+160h] [-210h] BYREF
  _DWORD v91[5]; // [sp+180h] [-1F0h] BYREF
  float v92[24]; // [sp+1A0h] [-1D0h] BYREF
  float v93[5]; // [sp+200h] [-170h] BYREF
  float v94[5]; // [sp+220h] [-150h] BYREF
  _DWORD v95[5]; // [sp+240h] [-130h] BYREF
  float v96[5]; // [sp+260h] [-110h] BYREF
  idEventArg v97; // [sp+280h] [-F0h] BYREF
  idEventArg v98[5]; // [sp+2A0h] [-D0h] BYREF

  Physics = idEntity::GetPhysics(this: ai);
  p_clip = (float *)&Physics[12].clip;
  v9 = (const idVec3 *)((char *)&Physics[12].residencyQuery.index + 4);
  MoveOrientation = idAI2::GetMoveOrientation(this: ai);
  v11 = -MoveOrientation->idealDir.x;
  v12 = -MoveOrientation->idealDir.y;
  _FP8 = (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f6, f8, f9, f0 }
  v15 = __frsqrte(_FP6);
  v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                      * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))
                                                                                              * (float)0.5))
                                                                              * (float)v15)
                                                                      - (float)1.5)
                                                      * (float)v15)
                                              * (float)((float)((float)((float)v12 * (float)v12)
                                                              + (float)((float)v11 * (float)v11))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                              * (float)((float)((float)((float)v12 * (float)v12)
                                                                                              + (float)((float)v11 * (float)v11))
                                                                                      * (float)0.5))
                                                                      * (float)v15)
                                                              - (float)1.5)
                                              * (float)v15))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v15
                                                      * (float)((float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)v11 * (float)v11))
                                                              * (float)0.5))
                                              * (float)v15)
                                      - (float)1.5)
                      * (float)v15));
  v17 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15)
                                                                                              * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                              * (float)v15))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)) * (float)0.5))
                                                                                              * (float)v15)
                                                                                      - (float)1.5)
                                                                      * (float)v15))
                                                      * (float)((float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)v11 * (float)v11))
                                                              * (float)0.5))
                                              * (float)v16)
                                      - (float)1.5)
                      * (float)v16)
              * (float)v11);
  v18 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15)
                                                                                              * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                              * (float)v15))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)) * (float)0.5))
                                                                                              * (float)v15)
                                                                                      - (float)1.5)
                                                                      * (float)v15))
                                                      * (float)((float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)v11 * (float)v11))
                                                              * (float)0.5))
                                              * (float)v16)
                                      - (float)1.5)
                      * (float)v16)
              * (float)v12);
  v19 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15)
                                                                                              * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                              * (float)v15))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)) * (float)0.5))
                                                                                              * (float)v15)
                                                                                      - (float)1.5)
                                                                      * (float)v15))
                                                      * (float)((float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)v11 * (float)v11))
                                                              * (float)0.5))
                                              * (float)v16)
                                      - (float)1.5)
                      * (float)v16)
              * (float)0.0);
  if ( __fabs((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) <= idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    BodyOrientation = idAI2::GetBodyOrientation(this: ai);
    v17 = (float)(BodyOrientation->axis.mat[0].x * (float)-1.0);
    v18 = (float)(BodyOrientation->axis.mat[0].y * (float)-1.0);
    v19 = (float)(BodyOrientation->axis.mat[0].z * (float)-1.0);
  }
  v21 = idEntity::GetPhysics(this: ai);
  v22 = (float *)v21->GetOrigin(this: v21, a2: 0);
  v23 = (float)(*v22 - v9->x);
  v24 = (float)(v22[1] - v9->y);
  if ( ((LODWORD(v9->x) | LODWORD(v9->z) | LODWORD(v9->y)) & 0x7FFFFFFF) != 0 )
  {
    _FP9 = (float)((float)((float)((float)(*v22 - v9->x) * (float)(*v22 - v9->x)) + (float)((float)v24 * (float)v24))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f7, f9, f10, f0 }
    v30 = __frsqrte(_FP7);
    v31 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30
                                                                                        * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)v24 * (float)v24))
                                                                                                * (float)0.5))
                                                                                * (float)v30)
                                                                        - (float)1.5)
                                                        * (float)v30)
                                                * (float)((float)((float)((float)v23 * (float)v23)
                                                                + (float)((float)v24 * (float)v24))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v30
                                                                                * (float)((float)((float)((float)v23 * (float)v23)
                                                                                                + (float)((float)v24 * (float)v24))
                                                                                        * (float)0.5))
                                                                        * (float)v30)
                                                                - (float)1.5)
                                                * (float)v30))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v30
                                                        * (float)((float)((float)((float)v23 * (float)v23)
                                                                        + (float)((float)v24 * (float)v24))
                                                                * (float)0.5))
                                                * (float)v30)
                                        - (float)1.5)
                        * (float)v30));
    x = (float)((float)v23
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)v24 * (float)v24)) * (float)0.5)) * (float)v30) - (float)1.5) * (float)v30)
                                                                                              * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)v24 * (float)v24)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)v24 * (float)v24)) * (float)0.5)) * (float)v30) - (float)1.5)
                                                                                              * (float)v30))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)v24 * (float)v24)) * (float)0.5))
                                                                                              * (float)v30)
                                                                                      - (float)1.5)
                                                                      * (float)v30))
                                                      * (float)((float)((float)((float)v23 * (float)v23)
                                                                      + (float)((float)v24 * (float)v24))
                                                              * (float)0.5))
                                              * (float)v31)
                                      - (float)1.5)
                      * (float)v31));
    y = (float)((float)v24
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)v24 * (float)v24)) * (float)0.5)) * (float)v30) - (float)1.5) * (float)v30)
                                                                                              * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)v24 * (float)v24)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)v24 * (float)v24)) * (float)0.5)) * (float)v30) - (float)1.5)
                                                                                              * (float)v30))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)v24 * (float)v24)) * (float)0.5))
                                                                                              * (float)v30)
                                                                                      - (float)1.5)
                                                                      * (float)v30))
                                                      * (float)((float)((float)((float)v23 * (float)v23)
                                                                      + (float)((float)v24 * (float)v24))
                                                              * (float)0.5))
                                              * (float)v31)
                                      - (float)1.5)
                      * (float)v31));
    z = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)v24 * (float)v24)) * (float)0.5)) * (float)v30) - (float)1.5) * (float)v30)
                                                                                              * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)v24 * (float)v24)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)v24 * (float)v24)) * (float)0.5)) * (float)v30) - (float)1.5)
                                                                                              * (float)v30))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)v24 * (float)v24)) * (float)0.5))
                                                                                              * (float)v30)
                                                                                      - (float)1.5)
                                                                      * (float)v30))
                                                      * (float)((float)((float)((float)v23 * (float)v23)
                                                                      + (float)((float)v24 * (float)v24))
                                                              * (float)0.5))
                                              * (float)v31)
                                      - (float)1.5)
                      * (float)v31)
              * (float)0.0);
  }
  else
  {
    x = vec3_origin.x;
    y = vec3_origin.y;
    z = vec3_origin.z;
  }
  v32 = (float)((float)(*p_clip + (float)v17) + (float)x);
  v33 = (float)((float)(p_clip[1] + (float)v18) + (float)y);
  _FP5 = (float)((float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f0 }
  v36 = __frsqrte(_FP3);
  v37 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v36
                                                                                      * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))
                                                                                              * (float)0.5))
                                                                              * (float)v36)
                                                                      - (float)1.5)
                                                      * (float)v36)
                                              * (float)((float)((float)((float)v33 * (float)v33)
                                                              + (float)((float)v32 * (float)v32))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v36
                                                                              * (float)((float)((float)((float)v33 * (float)v33)
                                                                                              + (float)((float)v32 * (float)v32))
                                                                                      * (float)0.5))
                                                                      * (float)v36)
                                                              - (float)1.5)
                                              * (float)v36))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v36
                                                      * (float)((float)((float)((float)v33 * (float)v33)
                                                                      + (float)((float)v32 * (float)v32))
                                                              * (float)0.5))
                                              * (float)v36)
                                      - (float)1.5)
                      * (float)v36));
  v88.x = (float)v32
        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)) * (float)0.5)) * (float)v36) - (float)1.5)
                                                                                                * (float)v36)
                                                                                        * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)) * (float)0.5)) * (float)v36) - (float)1.5)
                                                                                        * (float)v36))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v36
                                                                                                * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)) * (float)0.5))
                                                                                        * (float)v36)
                                                                                - (float)1.5)
                                                                * (float)v36))
                                                * (float)((float)((float)((float)v33 * (float)v33)
                                                                + (float)((float)v32 * (float)v32))
                                                        * (float)0.5))
                                        * (float)v37)
                                - (float)1.5)
                * (float)v37);
  v88.y = (float)v33
        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)) * (float)0.5)) * (float)v36) - (float)1.5)
                                                                                                * (float)v36)
                                                                                        * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)) * (float)0.5)) * (float)v36) - (float)1.5)
                                                                                        * (float)v36))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v36
                                                                                                * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)) * (float)0.5))
                                                                                        * (float)v36)
                                                                                - (float)1.5)
                                                                * (float)v36))
                                                * (float)((float)((float)((float)v33 * (float)v33)
                                                                + (float)((float)v32 * (float)v32))
                                                        * (float)0.5))
                                        * (float)v37)
                                - (float)1.5)
                * (float)v37);
  v88.z = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)) * (float)0.5)) * (float)v36) - (float)1.5)
                                                                                                * (float)v36)
                                                                                        * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)) * (float)0.5)) * (float)v36) - (float)1.5)
                                                                                        * (float)v36))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v36
                                                                                                * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)) * (float)0.5))
                                                                                        * (float)v36)
                                                                                - (float)1.5)
                                                                * (float)v36))
                                                * (float)((float)((float)((float)v33 * (float)v33)
                                                                + (float)((float)v32 * (float)v32))
                                                        * (float)0.5))
                                        * (float)v37)
                                - (float)1.5)
                * (float)v37)
        * (float)0.0;
  v38 = idEntity::GetPhysics(this: ai);
  v39 = (float *)v38->GetOrigin(this: v38, a2: 0);
  GetAAS = ai->GetAAS;
  v41 = (float)(v39[2] + (float)(v88.z * (float)32.0));
  v42 = (float)(v39[1] + (float)(v88.y * (float)32.0));
  v83 = *v39 + (float)(v88.x * (float)32.0);
  v92[0] = 0.0;
  memset(&v92[4], 0, 12);
  v92[1] = 0.0;
  v92[2] = 0.0;
  v92[3] = 0.0;
  v92[10] = 0.0;
  v92[7] = 0.0;
  v92[11] = 0.0;
  v92[8] = 0.0;
  memset(&v92[15], 0, 24);
  v92[9] = 0.0;
  v85 = v41;
  v84 = v42;
  v92[12] = 0.0;
  v92[13] = 0.0;
  v92[14] = 0.0;
  v43 = (int *)GetAAS(this: ai);
  v44 = ai->aiVolatile.aas.travelFlags & 0xFE78FFFF;
  v45 = idEntity::GetPhysics(this: ai);
  v46 = (int)v45->GetOrigin(this: v45, a2: 0);
  v47 = *v43;
  v48 = ai->GetAAS(this: ai);
  AreaNum = idActor::GetAreaNum(this: ai, aas: v48);
  (*(void (__fastcall **)(int *, float *, int, int, float *, unsigned int, _DWORD, int))(v47 + 64))(
    a1: v43,
    a2: v92,
    a3: v46,
    a4: AreaNum,
    a5: &v83,
    a6: v44,
    a7: 0,
    a8: 1);
  if ( v92[0] < 1.0 )
  {
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    v90[1] = (const idEventArg *)1;
    HIBYTE(v90[0]) = 105;
    HIBYTE(v91[0]) = 105;
    v91[1] = 500;
    v75 = idEventArg::idEventArg(this: v98, data: ai);
    memcpy(Dst: v78, Src: v90, Size: sizeof(v78));
    idEventReceiver::ProcessEvent(
      this: (idEventReceiver *)&v97,
      result: fsm,
      ev: *(const idEventDef **)&v75->type,
      arg1: (const idEventArg *)LODWORD(v75->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v75->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v91[0], 32));
  }
  else
  {
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) == 0 )
      idAIOrientation::SetAxis(
        this: &ai->aiVolatile.physics.moveState.moveOrientation,
        ai: ai->aiVolatile.physics.moveState.ai,
        dir: &v88);
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    v94[1] = -v17;
    v95[1] = 1;
    v94[2] = -v18;
    v91[1] = 1;
    v94[3] = -v19;
    v93[1] = v83;
    HIBYTE(v94[0]) = 118;
    v93[2] = v84;
    HIBYTE(v95[0]) = 105;
    v93[3] = v85;
    HIBYTE(v96[0]) = 102;
    HIBYTE(v91[0]) = 105;
    HIBYTE(v93[0]) = 118;
    HIBYTE(v90[0]) = 105;
    v90[1] = (const idEventArg *)36;
    v96[1] = 0.1;
    v50 = idEventArg::idEventArg(this: &v97, data: ai);
    memcpy(Dst: v82, Src: v94, Size: sizeof(v82));
    memcpy(Dst: v81, Src: v95, Size: sizeof(v81));
    memcpy(Dst: v80, Src: v96, Size: sizeof(v80));
    memcpy(Dst: v79, Src: v91, Size: sizeof(v79));
    memcpy(Dst: v78, Src: v93, Size: sizeof(v78));
    idEventReceiver::ProcessEvent(
      this: (idEventReceiver *)v98,
      result: fsm,
      ev: *(const idEventDef **)&v50->type,
      arg1: (const idEventArg *)LODWORD(v50->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v50->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v90[0], 32),
      arg4: v90[2],
      arg5: v90[3],
      arg6: v76,
      arg7: v77);
    if ( ai_debugStuck.valueInteger != 0 )
    {
      v51 = idEntity::GetPhysics(this: ai);
      v52 = v51->GetOrigin(this: v51, a2: 0);
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorGreen,
        a3: v52,
        a4: (const idVec3 *)&v83,
        a5: 2500,
        a6: false);
      v53 = (float)(*p_clip * (float)32.0);
      v54 = (float)(p_clip[1] * (float)32.0);
      v55 = (float)(p_clip[2] * (float)32.0);
      v56 = idEntity::GetPhysics(this: ai);
      v57 = (float *)v56->GetOrigin(this: v56, a2: 0);
      v58 = (float)(v57[2] + (float)v55);
      v59 = (float)(v57[1] + (float)v54);
      v89[0] = (float)v53 + *v57;
      v89[2] = v58;
      v89[1] = v59;
      v60 = idEntity::GetPhysics(this: ai);
      v61 = v60->GetOrigin(this: v60, a2: 0);
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorYellow,
        a3: v61,
        a4: (const idVec3 *)v89,
        a5: 2500,
        a6: false);
      v62 = idEntity::GetPhysics(this: ai);
      v63 = (float *)v62->GetOrigin(this: v62, a2: 0);
      v64 = v63[1];
      v65 = (float)(v63[2] + (float)((float)v19 * (float)32.0));
      v86[0] = (float)((float)v17 * (float)32.0) + *v63;
      v86[2] = v65;
      v86[1] = (float)v64 + (float)((float)v18 * (float)32.0);
      v66 = idEntity::GetPhysics(this: ai);
      v67 = v66->GetOrigin(this: v66, a2: 0);
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorBlue,
        a3: v67,
        a4: (const idVec3 *)v86,
        a5: 2500,
        a6: false);
      v68 = idEntity::GetPhysics(this: ai);
      v69 = (float *)v68->GetOrigin(this: v68, a2: 0);
      v70 = (float)(v69[2] + (float)((float)z * (float)32.0));
      v71 = (float)(v69[1] + (float)((float)y * (float)32.0));
      v87[0] = *v69 + (float)((float)x * (float)32.0);
      v87[2] = v70;
      v87[1] = v71;
      v72 = idEntity::GetPhysics(this: ai);
      v73 = v72->GetOrigin(this: v72, a2: 0);
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorWhite,
        a3: v73,
        a4: (const idVec3 *)v87,
        a5: 2500,
        a6: false);
      if ( ((LODWORD(v9->x) | LODWORD(v9->z) | LODWORD(v9->y)) & 0x7FFFFFFF) != 0 )
        v74 = &idColor::colorWhite;
      else
        v74 = &idColor::colorRed;
      clientGame->renderWorld->DebugPoint(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)v74,
        a3: v9,
        a4: 2500,
        a5: false);
    }
  }
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_UnhandledError@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABBDB8
// RVA : 0x00ABBDB8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_UnhandledError::AIState_EnterState(
        idAlertCycle_UnhandledError *this,
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

  idAI2::SetAlertCycle(this: ai, ac: ALERTCYCLE_ERROR);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
    idAnimBaseFSM::ClearDestination(this: &ai->aiVolatile.animation.animFSM);
  else
    idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
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
// ??0idAlertCycleFSM@@QAA@XZ
// EA  : 0x82ABBEA0
// RVA : 0x00ABBEA0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

idAlertCycleFSM *__fastcall idAlertCycleFSM::idAlertCycleFSM(idAlertCycleFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: "FSM_alertCycle");
  this->__vftable = (idAlertCycleFSM_vtbl *)&idAlertCycleFSM::`vftable';
  idState::idState(this: &this->stateDefault, stateType: &idAlertCycle_Default::Type, childFSMType: nullptr, flags: 0);
  this->stateDefault.__vftable = (idAlertCycle_Default_vtbl *)&idAlertCycle_Default::`vftable';
  idState::idState(
    this: &this->stateExecuteDoomscript,
    stateType: &idAlertCycle_ExecuteDoomscript::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateExecuteDoomscript.__vftable = (idAlertCycle_ExecuteDoomscript_vtbl *)&idAlertCycle_ExecuteDoomscript::`vftable';
  idState::idState(
    this: &this->stateExecuteCodeMoveAction,
    stateType: &idAlertCycle_ExecuteCodeMoveAction::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateExecuteCodeMoveAction.__vftable = (idAlertCycle_ExecuteCodeMoveAction_vtbl *)&idAlertCycle_ExecuteCodeMoveAction::`vftable';
  idState::idState(
    this: &this->stateActionScript,
    stateType: &idAlertCycle_ActionScript::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateActionScript.__vftable = (idAlertCycle_ActionScript_vtbl *)&idAlertCycle_ActionScript::`vftable';
  idState::idState(
    this: &this->stateDropFromShip,
    stateType: &idAlertCycle_DropFromShip::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateDropFromShip.__vftable = (idAlertCycle_DropFromShip_vtbl *)&idAlertCycle_DropFromShip::`vftable';
  idState::idState(
    this: &this->statePerformDropLanding,
    stateType: &idAlertCycle_PerformDropLanding::Type,
    childFSMType: nullptr,
    flags: 0);
  this->statePerformDropLanding.__vftable = (idAlertCycle_PerformDropLanding_vtbl *)&idAlertCycle_PerformDropLanding::`vftable';
  idState::idState(
    this: &this->stateRelaxed,
    stateType: &idAlertCycle_Relaxed::Type,
    childFSMType: &idRelaxedFSM::Type,
    flags: 0);
  this->stateRelaxed.__vftable = (idAlertCycle_Relaxed_vtbl *)&idAlertCycle_Relaxed::`vftable';
  idState::idState(
    this: &this->stateCombat,
    stateType: &idAlertCycle_Combat::Type,
    childFSMType: &idCombatFSM::Type,
    flags: 0);
  this->stateCombat.__vftable = (idAlertCycle_Combat_vtbl *)&idAlertCycle_Combat::`vftable';
  idState::idState(
    this: &this->stateCombatSP,
    stateType: &idAlertCycle_CombatScenePoint::Type,
    childFSMType: &idCombatScenePointFSM::Type,
    flags: 0);
  this->stateCombatSP.__vftable = (idAlertCycle_CombatScenePoint_vtbl *)&idAlertCycle_CombatScenePoint::`vftable';
  idState::idState(
    this: &this->stateSearchSP,
    stateType: &idAlertCycle_SearchScenePoint::Type,
    childFSMType: &idSearchScenePointFSM::Type,
    flags: 0);
  this->stateSearchSP.__vftable = (idAlertCycle_SearchScenePoint_vtbl *)&idAlertCycle_SearchScenePoint::`vftable';
  idState::idState(
    this: &this->stateRoamSP,
    stateType: &idAlertCycle_RoamScenePoint::Type,
    childFSMType: &idRoamScenePointFSM::Type,
    flags: 0);
  this->stateRoamSP.__vftable = (idAlertCycle_RoamScenePoint_vtbl *)&idAlertCycle_RoamScenePoint::`vftable';
  idState::idState(
    this: &this->stateSearch,
    stateType: &idAlertCycle_Search::Type,
    childFSMType: &idSearchFSM::Type,
    flags: 0);
  this->stateSearch.__vftable = (idAlertCycle_Search_vtbl *)&idAlertCycle_Search::`vftable';
  idState::idState(this: &this->statePain, stateType: &idAlertCycle_Pain::Type, childFSMType: nullptr, flags: 2);
  this->statePain.__vftable = (idAlertCycle_Pain_vtbl *)&idAlertCycle_Pain::`vftable';
  idState::idState(this: &this->stateDying, stateType: &idAlertCycle_Dying::Type, childFSMType: nullptr, flags: 2);
  this->stateDying.__vftable = (idAlertCycle_Dying_vtbl *)&idAlertCycle_Dying::`vftable';
  idState::idState(this: &this->stateDead, stateType: &idAlertCycle_Dead::Type, childFSMType: nullptr, flags: 0);
  this->stateDead.__vftable = (idAlertCycle_Dead_vtbl *)&idAlertCycle_Dead::`vftable';
  idState::idState(
    this: &this->stateAvoid,
    stateType: &idAlertCycle_Avoid::Type,
    childFSMType: &idAvoidFSM::Type,
    flags: 0);
  this->stateAvoid.__vftable = (idAlertCycle_Avoid_vtbl *)&idAlertCycle_Avoid::`vftable';
  idState::idState(this: &this->stateMelee, stateType: &idAlertCycle_Melee::Type, childFSMType: nullptr, flags: 0);
  this->stateMelee.__vftable = (idAlertCycle_Melee_vtbl *)&idAlertCycle_Melee::`vftable';
  idState::idState(
    this: &this->stateWatchPossession,
    stateType: &idAlertCycle_WatchPossessedGuy::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateWatchPossession.__vftable = (idAlertCycle_WatchPossessedGuy_vtbl *)&idAlertCycle_WatchPossessedGuy::`vftable';
  idState::idState(
    this: &this->stateUnhandledError,
    stateType: &idAlertCycle_UnhandledError::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateUnhandledError.__vftable = (idAlertCycle_UnhandledError_vtbl *)&idAlertCycle_UnhandledError::`vftable';
  idState::idState(
    this: &this->statePassified,
    stateType: &idAlertCycle_Passified::Type,
    childFSMType: nullptr,
    flags: 0);
  this->statePassified.__vftable = (idAlertCycle_Passified_vtbl *)&idAlertCycle_Passified::`vftable';
  idState::idState(
    this: &this->stateOnElevator,
    stateType: &idAlertCycle_OnElevator::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateOnElevator.__vftable = (idAlertCycle_OnElevator_vtbl *)&idAlertCycle_OnElevator::`vftable';
  idFiniteStateMachine::SetDefaultState(this, state: &this->stateDefault);
  return this;
}


// ========================================================================
// __unwind$492204
// EA  : 0x82ABC200
// RVA : 0x00ABC200
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492204()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$492205
// EA  : 0x82ABC228
// RVA : 0x00ABC228
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492205()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$492206
// EA  : 0x82ABC254
// RVA : 0x00ABC254
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492206()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$492207
// EA  : 0x82ABC280
// RVA : 0x00ABC280
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492207()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// __unwind$492208
// EA  : 0x82ABC2AC
// RVA : 0x00ABC2AC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492208()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 192));
}


// ========================================================================
// __unwind$492209
// EA  : 0x82ABC2D8
// RVA : 0x00ABC2D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492209()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 220));
}


// ========================================================================
// __unwind$492210
// EA  : 0x82ABC304
// RVA : 0x00ABC304
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492210()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 248));
}


// ========================================================================
// __unwind$492211
// EA  : 0x82ABC330
// RVA : 0x00ABC330
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492211()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 276));
}


// ========================================================================
// __unwind$492212
// EA  : 0x82ABC35C
// RVA : 0x00ABC35C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492212()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 304));
}


// ========================================================================
// __unwind$492213
// EA  : 0x82ABC388
// RVA : 0x00ABC388
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492213()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 332));
}


// ========================================================================
// __unwind$492214
// EA  : 0x82ABC3B4
// RVA : 0x00ABC3B4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492214()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 360));
}


// ========================================================================
// __unwind$492215
// EA  : 0x82ABC3E0
// RVA : 0x00ABC3E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492215()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 388));
}


// ========================================================================
// __unwind$492216
// EA  : 0x82ABC40C
// RVA : 0x00ABC40C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492216()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 416));
}


// ========================================================================
// __unwind$492217
// EA  : 0x82ABC438
// RVA : 0x00ABC438
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492217()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 444));
}


// ========================================================================
// __unwind$492218
// EA  : 0x82ABC464
// RVA : 0x00ABC464
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492218()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 472));
}


// ========================================================================
// __unwind$492219
// EA  : 0x82ABC490
// RVA : 0x00ABC490
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492219()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 500));
}


// ========================================================================
// __unwind$492220
// EA  : 0x82ABC4BC
// RVA : 0x00ABC4BC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492220()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 528));
}


// ========================================================================
// __unwind$492221
// EA  : 0x82ABC4E8
// RVA : 0x00ABC4E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492221()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 556));
}


// ========================================================================
// __unwind$492222
// EA  : 0x82ABC514
// RVA : 0x00ABC514
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492222()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 584));
}


// ========================================================================
// __unwind$492223
// EA  : 0x82ABC540
// RVA : 0x00ABC540
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492223()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 612));
}


// ========================================================================
// __unwind$492224
// EA  : 0x82ABC56C
// RVA : 0x00ABC56C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492224()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 640));
}


// ========================================================================
// __unwind$492225
// EA  : 0x82ABC598
// RVA : 0x00ABC598
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492225()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 668));
}


// ========================================================================
// ??1idAlertCycleFSM@@UAA@XZ
// EA  : 0x82ABC5D0
// RVA : 0x00ABC5D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycleFSM::~idAlertCycleFSM(idAlertCycleFSM *this)
{
  this->__vftable = (idAlertCycleFSM_vtbl *)&idAlertCycleFSM::`vftable';
  idState::~idState(this: &this->stateOnElevator);
  idState::~idState(this: &this->statePassified);
  idState::~idState(this: &this->stateUnhandledError);
  idState::~idState(this: &this->stateWatchPossession);
  idState::~idState(this: &this->stateMelee);
  idState::~idState(this: &this->stateAvoid);
  idState::~idState(this: &this->stateDead);
  idState::~idState(this: &this->stateDying);
  idState::~idState(this: &this->statePain);
  idState::~idState(this: &this->stateSearch);
  idState::~idState(this: &this->stateRoamSP);
  idState::~idState(this: &this->stateSearchSP);
  idState::~idState(this: &this->stateCombatSP);
  idState::~idState(this: &this->stateCombat);
  idState::~idState(this: &this->stateRelaxed);
  idState::~idState(this: &this->statePerformDropLanding);
  idState::~idState(this: &this->stateDropFromShip);
  idState::~idState(this: &this->stateActionScript);
  idState::~idState(this: &this->stateExecuteCodeMoveAction);
  idState::~idState(this: &this->stateExecuteDoomscript);
  idState::~idState(this: &this->stateDefault);
  idFiniteStateMachine::~idFiniteStateMachine(this);
}


// ========================================================================
// __unwind$492583
// EA  : 0x82ABC6C4
// RVA : 0x00ABC6C4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492583()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$492584
// EA  : 0x82ABC6EC
// RVA : 0x00ABC6EC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492584()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// __unwind$492585
// EA  : 0x82ABC718
// RVA : 0x00ABC718
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492585()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$492586
// EA  : 0x82ABC744
// RVA : 0x00ABC744
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492586()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// __unwind$492587
// EA  : 0x82ABC770
// RVA : 0x00ABC770
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492587()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 192));
}


// ========================================================================
// __unwind$492588
// EA  : 0x82ABC79C
// RVA : 0x00ABC79C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492588()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 220));
}


// ========================================================================
// __unwind$492589
// EA  : 0x82ABC7C8
// RVA : 0x00ABC7C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492589()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 248));
}


// ========================================================================
// __unwind$492590
// EA  : 0x82ABC7F4
// RVA : 0x00ABC7F4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492590()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 276));
}


// ========================================================================
// __unwind$492591
// EA  : 0x82ABC820
// RVA : 0x00ABC820
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492591()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 304));
}


// ========================================================================
// __unwind$492592
// EA  : 0x82ABC84C
// RVA : 0x00ABC84C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492592()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 332));
}


// ========================================================================
// __unwind$492593
// EA  : 0x82ABC878
// RVA : 0x00ABC878
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492593()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 360));
}


// ========================================================================
// __unwind$492594
// EA  : 0x82ABC8A4
// RVA : 0x00ABC8A4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492594()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 388));
}


// ========================================================================
// __unwind$492595
// EA  : 0x82ABC8D0
// RVA : 0x00ABC8D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492595()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 416));
}


// ========================================================================
// __unwind$492596
// EA  : 0x82ABC8FC
// RVA : 0x00ABC8FC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492596()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 444));
}


// ========================================================================
// __unwind$492597
// EA  : 0x82ABC928
// RVA : 0x00ABC928
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492597()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 472));
}


// ========================================================================
// __unwind$492598
// EA  : 0x82ABC954
// RVA : 0x00ABC954
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492598()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 500));
}


// ========================================================================
// __unwind$492599
// EA  : 0x82ABC980
// RVA : 0x00ABC980
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492599()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 528));
}


// ========================================================================
// __unwind$492600
// EA  : 0x82ABC9AC
// RVA : 0x00ABC9AC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492600()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 556));
}


// ========================================================================
// __unwind$492601
// EA  : 0x82ABC9D8
// RVA : 0x00ABC9D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492601()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 584));
}


// ========================================================================
// __unwind$492602
// EA  : 0x82ABCA04
// RVA : 0x00ABCA04
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492602()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 612));
}


// ========================================================================
// __unwind$492603
// EA  : 0x82ABCA30
// RVA : 0x00ABCA30
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_492603()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 640));
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_Combat@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABCA60
// RVA : 0x00ABCA60
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Combat::AIState_EnterState(
        idAlertCycle_Combat *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int value; // r29
  idPhysics *Physics; // r31
  idRenderWorld *v7; // r30
  idPhysics *v8; // r3
  idRenderWorld_vtbl *v9; // r31
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v11; // r3

  idAI2::SetAlertCycle(this: ai, ac: ALERTCYCLE_COMBAT);
  idAI2::LeaveActionNode(this: ai, force: true);
  ai->EnableAIEventResponse(this: ai, a2: AIEVENT_AIM);
  value = ai->aiVolatile.voiceController.nextVoiceTime.value;
  if ( value - gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) > 2000 )
  {
    idAIVoiceController::StopVoiceOver(this: &ai->aiVolatile.voiceController, ai);
    if ( ai_debugVoice.valueInteger != 0 && ai_debugLevel.valueInteger > 0 )
    {
      Physics = idEntity::GetPhysics(this: ai);
      v7 = common->RW(this: common);
      v8 = Physics;
      GetOrigin = Physics->GetOrigin;
      v9 = v7->__vftable;
      v11 = (int)GetOrigin(this: v8, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, const char *, int, enum idAIStateTransition::aiTransCode_t (__fastcall **)(COMBAT_AtPlugAnim *__hidden, struct idAI2 *, struct idAIFSM *, struct idAIState *, int), idColor *, int, int, _DWORD, double))v9->DebugText)(
        a1: v7,
        a2: "AWARENES CUT OFF RELAXED/SEARCH VO",
        a3: v11,
        a4: &off_82040000,
        a5: &idColor::colorWhite,
        a6: 1,
        a7: 2000,
        a8: 0,
        a9: 0.2);
    }
  }
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_Search@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABCB98
// RVA : 0x00ABCB98
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Search::AIState_EnterState(
        idAlertCycle_Search *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int value; // r29
  idPhysics *Physics; // r31
  idRenderWorld *v7; // r30
  idPhysics *v8; // r3
  idRenderWorld_vtbl *v9; // r31
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v11; // r3

  idAI2::SetAlertCycle(this: ai, ac: ALERTCYCLE_SEARCH);
  ai->DisableAIEventResponse(this: ai, a2: AIEVENT_AIM);
  value = ai->aiVolatile.voiceController.nextVoiceTime.value;
  if ( value - gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) > 2500 )
  {
    idAIVoiceController::StopVoiceOver(this: &ai->aiVolatile.voiceController, ai);
    if ( ai_debugVoice.valueInteger != 0 && ai_debugLevel.valueInteger > 0 )
    {
      Physics = idEntity::GetPhysics(this: ai);
      v7 = common->RW(this: common);
      v8 = Physics;
      GetOrigin = Physics->GetOrigin;
      v9 = v7->__vftable;
      v11 = (int)GetOrigin(this: v8, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, const char *, int, enum idAIStateTransition::aiTransCode_t (__fastcall **)(COMBAT_AtPlugAnim *__hidden, struct idAI2 *, struct idAIFSM *, struct idAIState *, int), idColor *, int, int, _DWORD, double))v9->DebugText)(
        a1: v7,
        a2: "AWARENES CUT OFF RELAXED VO",
        a3: v11,
        a4: &off_82040000,
        a5: &idColor::colorWhite,
        a6: 1,
        a7: 2000,
        a8: 0,
        a9: 0.2);
    }
  }
}


// ========================================================================
// ?Evaluate@AC_DyingFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABCCC8
// RVA : 0x00ABCCC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_DyingFinished::Evaluate(
        AC_DyingFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  idAnimator_AF *v7; // r3
  char v8; // r11
  char *CurSubWebName; // r3
  const char *CurStateName; // r3
  deathFlags_t deathFlags; // r11
  const idDeclAnimWebNode *deathAnimationNode; // r27
  idDeclAnimWeb_vtbl *decl; // r4
  bool (__fastcall *ReloadIfStale)(struct idDeclAnimWeb *); // r11
  int value; // r9
  __int16 v17; // r8
  const idDeclAnimWebNode *v18; // r29
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v19; // r28
  idMD6Anim *AnimForAnimWebNode; // r3
  double v21; // fp10
  double v22; // fp8
  idQuat *v23; // r3
  double w; // fp5
  double z; // fp4
  double y; // fp3
  double v27; // fp13
  double v28; // fp11
  double v29; // fp9
  const idQuat *v30; // r3
  idDeclAnimWeb v31; // [sp+50h] [-120h] BYREF

  v7 = ai->GetAF_2(this: ai);
  if ( v7 != nullptr )
  {
    if ( v7->isActive || (v8 = 0, v7->isClientAuthoritativeActive) )
      v8 = 1;
    if ( v8 != 0 )
      return 456;
  }
  if ( (ai->aiVolatile.death.deathInfo.deathFlags & 8) == 0
    && ai->aiVolatile.death.deathInfo.startDeathTime + 100 < curTime )
  {
    v31.networkID = 20;
    v31.resourceListPtr = nullptr;
    v31.resourceError = (const char *)&v31.staleCount;
    HIBYTE(v31.staleCount) = 0;
    CurSubWebName = idAnimator_AnimWeb::GetCurSubWebName(this: (idAnimator_AnimWeb *)&ai->aiVolatile.animation);
    idStr::operator=(this: (idStr *)&v31.resourceListPtr, text: CurSubWebName);
    v31.nodes.list = (idDeclAnimWebNode **)20;
    v31.declSource = (idDeclSource *)&v31.nodes.num;
    *(_DWORD *)&v31.programaticallyDefined = 0;
    HIBYTE(v31.nodes.num) = 0;
    CurStateName = idAnimator_AnimWeb::GetCurStateName(this: (idAnimator_AnimWeb *)&ai->aiVolatile.animation);
    idStr::operator=(this: (idStr *)&v31.programaticallyDefined, text: CurStateName);
    deathFlags = ai->aiVolatile.death.deathInfo.deathFlags;
    if ( (deathFlags & 1) != 0 )
    {
      if ( idStr::Cmp(s1: v31.resourceError, s2: "death_custom") != 0 )
      {
        ai->StartRagdoll(this: ai, a2: &ai->ragdollInfo);
        idStr::FreeData(this: (idStr *)&v31.programaticallyDefined);
        idStr::FreeData(this: (idStr *)&v31.resourceListPtr);
        return 456;
      }
      goto LABEL_16;
    }
    if ( (deathFlags & 2) != 0 )
    {
      if ( idStr::Find(
             searchIn: (const char *)v31.declSource,
             searchFor: "death_local",
             casesensitive: true,
             start: 0,
             end: -1) == -1 )
      {
LABEL_14:
        ai->StartRagdoll(this: ai, a2: &ai->ragdollInfo);
        idStr::FreeData(this: (idStr *)&v31.programaticallyDefined);
        idStr::FreeData(this: (idStr *)&v31.resourceListPtr);
        return 456;
      }
    }
    else if ( idStr::Cmp(s1: v31.resourceError, s2: "death") != 0 )
    {
      goto LABEL_14;
    }
LABEL_16:
    ai->aiVolatile.death.deathInfo.deathFlags |= 8u;
    idStr::FreeData(this: (idStr *)&v31.programaticallyDefined);
    idStr::FreeData(this: (idStr *)&v31.resourceListPtr);
  }
  if ( (ai->aiVolatile.death.deathInfo.deathFlags & 4) != 0 )
  {
    deathAnimationNode = ai->aiVolatile.death.deathInfo.deathAnimationNode;
    if ( deathAnimationNode == nullptr || deathAnimationNode->edges.num <= 0 )
      return 456;
    decl = (idDeclAnimWeb_vtbl *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl;
    ReloadIfStale = decl[2].ReloadIfStale;
    value = deathAnimationNode->edges.list->value;
    v31.__vftable = decl;
    v17 = *((_WORD *)ReloadIfStale + 2 * value);
    if ( v17 == -1 )
      v18 = nullptr;
    else
      v18 = *((const idDeclAnimWebNode **)decl->FreeData + v17);
    v31.edgeCache.list = (idDeclAnimWeb::idEdgeCache *)20;
    v31.edges.size = 0;
    *(_DWORD *)&v31.edges.granularity = &v31.edgeCache.num;
    HIBYTE(v31.edgeCache.num) = 0;
    v31.__vftable = decl;
    idDeclAnimWebNode::GetStateName(this: v18, web: (const idDeclAnimWeb *)decl, name: (idStr *)&v31.edges.size);
    v19 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v18->subWebIndex.value;
    idDeclAnimWeb::GetStateIndexForName(
      this: &v31,
      result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
      name: *(const char **)&v31.edges.granularity);
    if ( idAI2::ChangeAnimState(
           this: ai,
           web: AIANIMWEB_BODY,
           subWebIndex: v19,
           stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v31.__vftable),
           interruptPath: INTR_PATH_NO,
           interruptBlend: INTR_BLEND_NO) != 1
      || (ai->aiVolatile.death.deathInfo.deathFlags &= ~4u,
          ai->aiVolatile.death.deathInfo.deathAnimationNode = v18,
          v31.trackedMemory = *(_DWORD *)&deathAnimationNode->subWebIndex.value,
          (AnimForAnimWebNode = idAI2::GetAnimForAnimWebNode(
                                  this: ai,
                                  swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)&v31.trackedMemory,
                                  si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)&v31.trackedMemory + 1)) == nullptr) )
    {
      ai->StartRagdoll(this: ai, a2: &ai->ragdollInfo);
      idStr::FreeData(this: (idStr *)&v31.edges.size);
      return 456;
    }
    idMD6Anim::GetAnimationDelta(
      this: AnimForAnimWebNode,
      deltaTrans: (idVec3 *)&v31.states.size,
      deltaAxis: (idMat3 *)&v31.scalars.size);
    v21 = (float)(ai->aiVolatile.physics.moveState.perfectOriginPosition.z + *(float *)&v31.models.list);
    v22 = (float)(ai->aiVolatile.physics.moveState.perfectOriginPosition.y + *(float *)&v31.states.granularity);
    *(float *)&v31.subWebs.size = ai->aiVolatile.physics.moveState.perfectOriginPosition.x + *(float *)&v31.states.size;
    *(float *)&v31.states.list = v21;
    v31.name.str = (const char *)&ai->aiVolatile.physics.moveState.perfectOriginPosition;
    *(float *)&v31.subWebs.granularity = v22;
    v23 = idMat3::ToQuat(this: (idMat3 *)&v31.nodeCache.size, result: (idQuat *)&v31.scalars.size);
    w = ai->aiVolatile.physics.moveState.perfectOriginRotation.w;
    z = ai->aiVolatile.physics.moveState.perfectOriginRotation.z;
    y = ai->aiVolatile.physics.moveState.perfectOriginRotation.y;
    v31.name.str = (const char *)&ai->aiVolatile.physics.moveState.perfectOriginRotation;
    v27 = (float)(v23->w + (float)w);
    v28 = (float)(v23->z + (float)z);
    v29 = (float)(v23->y + (float)y);
    *(float *)&v31.models.size = v23->x + ai->aiVolatile.physics.moveState.perfectOriginRotation.x;
    *(float *)&v31.edges.num = v27;
    *(float *)&v31.edges.list = v28;
    *(float *)&v31.models.granularity = v29;
    v30 = idQuat::Normalize(this: (idQuat *)&v31.models.size);
    idAIMoveState::StartPerfectOrigin(
      this: &ai->aiVolatile.physics.moveState,
      idealAxis: v30,
      idealPos: (const idVec3 *)&v31.subWebs.size,
      lerpTimeMs: 100,
      swi: v19,
      si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v31.__vftable));
    idStr::FreeData(this: (idStr *)&v31.edges.size);
  }
  return 0;
}


// ========================================================================
// __unwind$493762
// EA  : 0x82ABD0EC
// RVA : 0x00ABD0EC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_493762()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 96));
}


// ========================================================================
// __unwind$493763
// EA  : 0x82ABD114
// RVA : 0x00ABD114
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_493763()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 128));
}


// ========================================================================
// __unwind$493764
// EA  : 0x82ABD13C
// RVA : 0x00ABD13C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_493764()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 208));
}


// ========================================================================
// ?Evaluate@AC_CanUseCombatScenePoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABD210
// RVA : 0x00ABD210
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_CanUseCombatScenePoint::Evaluate(
        AC_CanUseCombatScenePoint *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  idScenePoint *curScenePoint; // r11
  char v9; // r10
  char v10; // r11
  bool v11; // zf
  int value; // r8
  idInfoPath *v13; // r3
  idInfoPath *v14; // r3
  idFiniteStateMachine *v15; // r3
  idScenePoint *v16; // r11
  int v17; // r10
  char v18; // r11
  idScenePoint *keptOverrideScenePoint; // r4

  if ( (unsigned __int8)idAI2::UsesScenePoints(this: ai) == 0
    || idComponentActionScript::RunningActionScript(this: &ai->actionScript, entity: ai)
    && (ai->aiVolatile.script.flags & 1) == 0
    || (unsigned __int8)idAIMemory::HasOverrideScriptScenePointNotOfType(
                          this: &ai->aiVolatile.memory,
                          spType: (scenePointType_t)4) != 0
    && ai->aiVolatile.memory.overrideScenePoint->type != LOOK )
  {
    return 0;
  }
  curScenePoint = ai->aiVolatile.memory.curScenePoint;
  if ( curScenePoint == nullptr
    || (*(_BYTE *)&curScenePoint->flags & 8) == 0
    || (v9 = 1, (curScenePoint->scriptFlags & 1) == 0) )
  {
    v9 = 0;
  }
  if ( v9 != 0 )
  {
    if ( curScenePoint == nullptr || (v11 = curScenePoint->type == 4, v10 = 1, !v11) )
      v10 = 0;
    if ( v10 == 0 )
      return 0;
  }
  value = ai->aiVolatile.memory.currentPath.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v13 = (idInfoPath *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v13 != nullptr )
    {
      v14 = idInfoPath::CastTo(c: v13);
      if ( v14 != nullptr && !v14->abortForCombat )
        return 0;
    }
  }
  v15 = parentFSM->manager->FindFSM_4(this: parentFSM->manager, a2: "FSM_combatScenePoint");
  if ( !v15->CanUse(this: v15, a2: parentFSM, a3: curTime) )
    return 0;
  v16 = ai->aiVolatile.memory.curScenePoint;
  if ( v16 == nullptr || (*(_BYTE *)&v16->flags & 8) == 0 || (v17 = v16->scriptFlags & 1, v18 = 1, v17 == 0) )
    v18 = 0;
  if ( v18 == 0 && ai->aiVolatile.memory.overrideScenePoint == nullptr )
  {
    keptOverrideScenePoint = ai->aiVolatile.memory.keptOverrideScenePoint;
    if ( keptOverrideScenePoint != nullptr && keptOverrideScenePoint->type == 4 )
      idAIMemory::SetOverrideScenePoint(this: &ai->aiVolatile.memory, scenePoint: keptOverrideScenePoint);
  }
  return 456;
}


// ========================================================================
// ?Evaluate@AC_CanUseSearchScenePoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABD430
// RVA : 0x00ABD430
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_CanUseSearchScenePoint::Evaluate(
        AC_CanUseSearchScenePoint *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  idScenePoint *curScenePoint; // r10
  char v9; // r11
  char v10; // r11
  char v11; // r11
  idFiniteStateMachine *v12; // r3
  idScenePoint *v13; // r11
  int v14; // r10
  char v15; // r11
  idScenePoint *keptOverrideScenePoint; // r4

  if ( (unsigned __int8)idAI2::UsesScenePoints(this: ai) == 0
    || idComponentActionScript::RunningActionScript(this: &ai->actionScript, entity: ai)
    || (unsigned __int8)idAIMemory::HasOverrideScriptScenePointNotOfType(
                          this: &ai->aiVolatile.memory,
                          spType: ROAM|LOOK) != 0
    && ai->aiVolatile.memory.overrideScenePoint->type != LOOK )
  {
    return 0;
  }
  curScenePoint = ai->aiVolatile.memory.curScenePoint;
  if ( curScenePoint == nullptr
    || (*(_BYTE *)&curScenePoint->flags & 8) == 0
    || (v9 = 1, (curScenePoint->scriptFlags & 1) == 0) )
  {
    v9 = 0;
  }
  if ( v9 != 0 )
  {
    if ( curScenePoint == nullptr || (v10 = 1, curScenePoint->type != (ROAM|LOOK)) )
      v10 = 0;
    if ( v10 == 0 )
      return 0;
  }
  if ( curScenePoint == nullptr
    || (*(_BYTE *)&curScenePoint->flags & 8) == 0
    || (v11 = 1, (curScenePoint->scriptFlags & 1) == 0) )
  {
    v11 = 0;
  }
  if ( v11 == 0
    && (unsigned __int8)idAIMemory::HasOverrideScriptScenePointNotOfType(this: &ai->aiVolatile.memory, spType: ROAM) == 0
    && idAIMemory::GetCurrentPath(this: &ai->aiVolatile.memory) != nullptr )
  {
    return 0;
  }
  v12 = parentFSM->manager->FindFSM_4(this: parentFSM->manager, a2: "FSM_searchScenePoint");
  if ( !v12->CanUse(this: v12, a2: parentFSM, a3: curTime) )
    return 0;
  v13 = ai->aiVolatile.memory.curScenePoint;
  if ( v13 == nullptr || (*(_BYTE *)&v13->flags & 8) == 0 || (v14 = v13->scriptFlags & 1, v15 = 1, v14 == 0) )
    v15 = 0;
  if ( v15 == 0 && ai->aiVolatile.memory.overrideScenePoint == nullptr )
  {
    keptOverrideScenePoint = ai->aiVolatile.memory.keptOverrideScenePoint;
    if ( keptOverrideScenePoint != nullptr && keptOverrideScenePoint->type == (ROAM|LOOK) )
      idAIMemory::SetOverrideScenePoint(this: &ai->aiVolatile.memory, scenePoint: keptOverrideScenePoint);
  }
  return 456;
}


// ========================================================================
// ?Evaluate@AC_CanUseRoamScenePoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABD640
// RVA : 0x00ABD640
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_CanUseRoamScenePoint::Evaluate(
        AC_CanUseRoamScenePoint *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  idScenePoint *curScenePoint; // r10
  char v9; // r11
  char v10; // r11
  char v11; // r11
  idFiniteStateMachine *v12; // r3
  idScenePoint *v13; // r11
  int v14; // r10
  char v15; // r11
  idScenePoint *keptOverrideScenePoint; // r4

  if ( (unsigned __int8)idAI2::UsesScenePoints(this: ai) == 0
    || idComponentActionScript::RunningActionScript(this: &ai->actionScript, entity: ai)
    || (unsigned __int8)idAIMemory::HasOverrideScriptScenePointNotOfType(this: &ai->aiVolatile.memory, spType: ROAM) != 0
    && ai->aiVolatile.memory.overrideScenePoint->type != LOOK )
  {
    return 0;
  }
  curScenePoint = ai->aiVolatile.memory.curScenePoint;
  if ( curScenePoint == nullptr
    || (*(_BYTE *)&curScenePoint->flags & 8) == 0
    || (v9 = 1, (curScenePoint->scriptFlags & 1) == 0) )
  {
    v9 = 0;
  }
  if ( v9 != 0 )
  {
    if ( curScenePoint == nullptr || (v10 = 1, curScenePoint->type != ROAM) )
      v10 = 0;
    if ( v10 == 0 )
      return 0;
  }
  if ( curScenePoint == nullptr
    || (*(_BYTE *)&curScenePoint->flags & 8) == 0
    || (v11 = 1, (curScenePoint->scriptFlags & 1) == 0) )
  {
    v11 = 0;
  }
  if ( v11 == 0
    && (unsigned __int8)idAIMemory::HasOverrideScriptScenePointNotOfType(this: &ai->aiVolatile.memory, spType: ROAM) == 0
    && idAIMemory::GetCurrentPath(this: &ai->aiVolatile.memory) != nullptr )
  {
    return 0;
  }
  v12 = parentFSM->manager->FindFSM_4(this: parentFSM->manager, a2: "FSM_roamScenePoint");
  if ( !v12->CanUse(this: v12, a2: parentFSM, a3: curTime) )
    return 0;
  v13 = ai->aiVolatile.memory.curScenePoint;
  if ( v13 == nullptr || (*(_BYTE *)&v13->flags & 8) == 0 || (v14 = v13->scriptFlags & 1, v15 = 1, v14 == 0) )
    v15 = 0;
  if ( v15 == 0 && ai->aiVolatile.memory.overrideScenePoint == nullptr )
  {
    keptOverrideScenePoint = ai->aiVolatile.memory.keptOverrideScenePoint;
    if ( keptOverrideScenePoint != nullptr && keptOverrideScenePoint->type == ROAM )
      idAIMemory::SetOverrideScenePoint(this: &ai->aiVolatile.memory, scenePoint: keptOverrideScenePoint);
  }
  return 456;
}


// ========================================================================
// ?Evaluate@AC_NoEnemy@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABD850
// RVA : 0x00ABD850
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

int __fastcall AC_NoEnemy::Evaluate(
        AC_NoEnemy *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r3
  idEntity *v9; // r31
  idEncounterGroup *EncounterGroup; // r3
  int curCombatStage; // r11
  idEncounterGroup *v12; // r3
  int v13; // r11
  int v14; // r11
  idAIEntityState *v15; // r3

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v7 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v7 != nullptr )
    {
      v8 = idEntity::CastTo(c: v7);
      v9 = v8;
      if ( v8 != nullptr )
      {
        v15 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8);
        if ( v15 != nullptr && (*((_BYTE *)v15 + 541) & 0x80) != 0 && !v9->IsDead(this: v9) )
          return 0;
      }
    }
  }
  if ( ai->aiEditable.spawnSettings.alwaysInCombat )
    return 23;
  if ( idAI2::GetEncounterGroup(this: ai) != nullptr )
  {
    EncounterGroup = idAI2::GetEncounterGroup(this: ai);
    curCombatStage = EncounterGroup->curCombatStage;
    if ( curCombatStage >= 0
      && curCombatStage < EncounterGroup->combatStages.num
      && &EncounterGroup->combatStages.list[curCombatStage] != nullptr )
    {
      v12 = idAI2::GetEncounterGroup(this: ai);
      v13 = v12->curCombatStage;
      if ( v13 < 0 || v13 >= v12->combatStages.num )
        v14 = 0;
      else
        v14 = (int)&v12->combatStages.list[v13];
      if ( (*(_BYTE *)(v14 + 92) & 8) != 0 )
        return 23;
    }
  }
  return 230;
}


// ========================================================================
// ?Evaluate@AC_PlayerApproaching@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABD9C0
// RVA : 0x00ABD9C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall AC_PlayerApproaching::Evaluate(
        AC_PlayerApproaching *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIEventSphere *eventData; // r31
  int value; // r10
  idEntity *v8; // r3
  idPlayer *v9; // r3
  idPlayer *v10; // r4
  idAIStateTransition::aiTransCode_t result; // r3
  bool v12; // zf

  if ( parentFSM->eventId != 0x200000 )
    return 0;
  eventData = (idAIEventSphere *)parentFSM->eventData;
  if ( idAIEventSphere::CastTo(c: eventData) == nullptr )
    return 0;
  value = eventData->originator.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = (idPlayer *)idEntity::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  v10 = idPlayer::CastTo(c: v9);
  if ( v10 == nullptr )
    return 0;
  v12 = (unsigned __int8)idAI2::PlayerApproachingInteraction(this: ai, player: v10) != 0;
  result = TRANSCODE_AC_PLAYER_APPROACHING;
  if ( !v12 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@AC_PainFinishedMelee@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABDA88
// RVA : 0x00ABDA88
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall AC_PainFinishedMelee::Evaluate(
        AC_PainFinishedMelee *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  painType_t type; // r11
  unsigned int v7; // r4
  const idEntity *LastAttacker; // r3
  idTurret *v9; // r30
  idAIEntityState *v10; // r3
  idTurret *v11; // r4
  aiSenseState_t *v12; // r30
  int v13; // r29
  idVec3 *p_velocity; // r28
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  aiMelee_t MeleeTypeForTarget; // r29
  const aiPhysicalState_t *v17; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v19; // zf

  if ( !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) )
    return 0;
  if ( !idAI2::CanMelee(this: ai) )
    return 0;
  type = ai->actorVolatile.pain.type;
  if ( type != PAIN_STUN && type != PAIN_STUN_IGNORE )
    return 0;
  v7 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v7;
  if ( (signed int)(((v7 >> 10) & 0x7FFF) % 0x64) >= ai->aiEditable.behaviors.decl->meleeFromStunChance )
    return 0;
  LastAttacker = idAIMemory::GetLastAttacker(this: &ai->aiVolatile.memory);
  v9 = (idTurret *)LastAttacker;
  if ( LastAttacker == nullptr )
    return 0;
  v10 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: LastAttacker);
  if ( v10 == nullptr )
    return 0;
  v11 = v9;
  v12 = v10->senses.ptr[v10->lastSense];
  v13 = idAI2::MeleePreference(this: ai, target: v11);
  p_velocity = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v12)->velocity;
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v12);
  MeleeTypeForTarget = idAI2::GetMeleeTypeForTarget(
                         this: ai,
                         targetPos: &ConfirmedPhysicalSafe->origin,
                         targetVel: p_velocity,
                         meleeMask: -1,
                         preferredMask: v13);
  if ( MeleeTypeForTarget == AIMELEE_NONE )
    return 0;
  v17 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v12);
  v19 = (unsigned __int8)idAI2::IsTargetInMeleeRange(this: ai, targetPos: &v17->origin, meleeType: MeleeTypeForTarget) != 0;
  result = TRANSCODE_AC_PAIN_FINISHED_MELEE;
  if ( !v19 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_Pain@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABDBF8
// RVA : 0x00ABDBF8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Pain::AIState_EnterState(
        idAlertCycle_Pain *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  const idDeclAIBehavior *decl; // r24
  char v6; // r11
  alertCycle_t AlertCycle; // r3
  const idDeclMD6 *v8; // r11
  idJointGroupCollection *p_jointGroupCollection; // r3
  const idJointGroup *JointGroup; // r14
  idWeapon *v11; // r3
  const idWeapon *v12; // r18
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> **p_animation; // r16
  posture_t v14; // r3
  idPhysics *Physics; // r3
  unsigned __int8 v16; // r11
  signed int v17; // r26
  int v18; // r28
  unsigned int v19; // r4
  idCVar *md5Checksum; // r15
  int resourceListPtr; // r21
  int str; // r19
  bool v23; // r11
  char v24; // r22
  idDamageGroup *v25; // r20
  idDamageGroup *DamageGroup; // r3
  __int16 *SubWebIndexForName; // r3
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v28; // r4
  __int16 *StateIndexForName; // r3
  posture_t (__fastcall *GetPosture)(struct idAI2 *); // r4
  __int16 *v31; // r3
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v32; // r4
  int v33; // r29
  idRenderModel *RenderModelFromPresentable; // r3
  float *p_deferredAxis; // r11
  double v36; // fp29
  double v37; // fp28
  double v38; // fp30
  const char *v39; // r4
  idRenderModel *v40; // r3
  float *p_axis; // r11
  int injuredIdleIndex; // fp11
  const idMD6Anim *AnimForAnimWebNode; // r3
  idPresentable *presentable; // r11
  double v45; // fp11
  double v46; // fp9
  double v47; // fp8
  double z; // fp7
  double v49; // fp30
  double v50; // fp29
  double v51; // fp28
  idPhysics *v52; // r3
  float *v53; // r3
  const idAAS2 *(__fastcall *GetAAS)(struct idAI2 *); // r5
  double v55; // fp8
  double v56; // fp6
  const idAAS2 *v57; // r3
  const idAASPosition *AASPosition; // r3
  idAASPosition *v59; // r29
  idPhysics *v60; // r3
  idAAS2 *aas; // r15
  idPhysics *v62; // r16
  idAASPosition *v63; // r3
  idAAS2_vtbl *v64; // r29
  unsigned int v65; // r14
  idResource *AreaNum; // r3
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // r9
  int v68; // r3
  bool v69; // r11
  idPresentable *v70; // r11
  int entityNumber; // r29
  double y; // fp3
  double x; // fp2
  double v74; // fp10
  double v75; // fp8
  idPlayer *v76; // r3
  int valueInteger; // r10
  int v78; // r11
  idPhysics *v79; // r29
  idRenderWorld *v80; // r26
  idPhysics *v81; // r3
  idRenderWorld_vtbl *v82; // r29
  const idVec3 *(__fastcall *v83)(idPhysics *, int); // ctr
  int v84; // r3
  idPhysics *v85; // r29
  idRenderWorld *v86; // r16
  idPhysics *v87; // r3
  idRenderWorld_vtbl *v88; // r29
  const idVec3 *(__fastcall *v89)(idPhysics *, int); // ctr
  int v90; // r3
  const char *v91; // fp11
  __int16 *v92; // r3
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v93; // r4
  __int64 v94; // r8
  bool v95; // r5
  runIndexType_t v96; // r4
  idPhysics *v97; // r29
  int GameMs; // r26
  idPhysics *v99; // r3
  const idDeclAIBehaviorEvents *declBehaviorEvents; // r25
  idAIEventManager *p_aiEventManager; // r29
  const idVec3 *(__fastcall *v102)(idPhysics *, int); // ctr
  const idVec3 *v103; // r3
  bool v104; // r5
  runIndexType_t v105; // r4
  double v106; // fp1
  const idDeclAIBehavior *v107; // r11
  double injuredRunThreshold; // fp0
  aiInjuredRunMode_t injuredRunMode; // r10
  idPhysics *v110; // r29
  int v111; // r27
  idPhysics *v112; // r3
  const idDeclAIBehaviorEvents *v113; // r26
  idAIEventManager *v114; // r29
  const idVec3 *(__fastcall *v115)(idPhysics *, int); // ctr
  const idVec3 *v116; // r3
  int v117; // r3
  double v118; // [sp+18h] [-368h]
  double v119; // [sp+18h] [-368h]
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v120; // [sp+60h] [-320h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v121; // [sp+62h] [-31Eh] BYREF
  idDeclAnimWeb v122; // [sp+64h] [-31Ch] BYREF
  float v123[24]; // [sp+180h] [-200h] BYREF
  idStr v124; // [sp+1E0h] [-1A0h] BYREF
  idStr v125; // [sp+200h] [-180h] BYREF
  idStr v126; // [sp+220h] [-160h] BYREF
  trace_t v127; // [sp+240h] [-140h] BYREF

  decl = ai->aiEditable.behaviors.decl;
  v6 = *((_BYTE *)&decl->damageBehaviors + 84);
  *(_DWORD *)&v122.programaticallyDefined = decl;
  if ( v6 < 0 )
  {
    AlertCycle = idAI2::GetAlertCycle(this: ai);
    v122.models.num = idAI2::AlertCycleToSubWeb(this: ai, ac: AlertCycle);
    if ( v122.models.num == 0
      && ai->aiVolatile.fsms.previousAlertCycle != ALERTCYCLE_MAX
      && idAIMemory::GetEnemy(this: &ai->aiVolatile.memory) != nullptr )
    {
      v122.models.num = idAI2::AlertCycleToSubWeb(this: ai, ac: ai->aiVolatile.fsms.previousAlertCycle);
    }
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
    {
      idAnimBaseFSM::ClearDestination(this: &ai->aiVolatile.animation.animFSM);
    }
    else
    {
      idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&ai->aiVolatile.physics.moveState);
    }
    idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
    idAI2::SetCoverAction(this: ai, action: COVERACTION_NONE);
    idStr::idStr(this: (idStr *)&v122.edges.num, text: "pain_chest");
    v8 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: ai)->decl;
    p_jointGroupCollection = &v8->jointGroupCollection;
    if ( v8 == nullptr )
      p_jointGroupCollection = nullptr;
    JointGroup = idJointGroupCollection::GetJointGroup(
                   this: p_jointGroupCollection,
                   handle: &ai->actorVolatile.pain.jointGroupHandle);
    v122.textLength = (int)JointGroup;
    if ( JointGroup != nullptr )
      idStr::operator=(this: (idStr *)&v122.edges.num, text: JointGroup->groupName.str);
    v11 = ai->GetEquippedWeapon(this: ai);
    v122.subWebs.num = 0;
    HIBYTE(v122.states.list) = 0;
    v122.subWebs.size = (int)&v122.states;
    v12 = v11;
    *(_DWORD *)&v122.subWebs.granularity = 20;
    v121.value = -1;
    v120.value = -1;
    p_animation = (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> **)&ai->aiVolatile.animation;
    v122.declSource = (idDeclSource *)&ai->aiVolatile.animation;
    idStr::idStr(this: (idStr *)&v122.layers.num, text: "idle");
    v14 = ai->GetPosture(this: ai);
    v122.trackedMemory = (int)"_crouch";
    if ( v14 == POSTURE_CROUCHED )
      idStr::Append(this: (idStr *)&v122.layers.num, text: "_crouch");
    Physics = idEntity::GetPhysics(this: ai);
    Physics->GetLinearVelocity(this: (idPhysics *)&v122.nodes.num, result: (idVec3 *)Physics, a3: 0);
    if ( ai_lotsOfInjuries.valueInteger != 0 || (v16 = 0, (*((_BYTE *)&ai->aiEditable.death + 84) & 0x10) != 0) )
      v16 = 1;
    v122.models.size = 0;
    v17 = 0;
    v18 = v16;
    if ( v16 == 0 )
    {
      v19 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v19;
      v17 = ((v19 >> 10) & 0x7FFF) % 0x64;
      v122.models.size = v17;
    }
    md5Checksum = &ai_enableInjuredRuns;
    resourceListPtr = -1;
    str = -1;
    v122.md5Checksum = (unsigned int)&ai_enableInjuredRuns;
    v23 = ai_forceInjury.valueInteger != 0
       || ai_enableInjuredRuns.valueInteger != 0
       && (*((_BYTE *)&ai->aiEditable.death + 84) & 0x20) != 0
       && (((double (__fastcall *)(idAIHealth *))ai->aiHealth.GetBaseHealthRatio_Impl)(a1: &ai->aiHealth) < decl->damageBehaviors.injuredRunThreshold
        || v18 != 0)
       && decl->damageBehaviors.injuredRunMode == AIINJUREDRUNMODE_AFTERPAIN
       && (v17 < decl->damageBehaviors.injuredChance || (ai->aiVolatile.groupStatus.condition & 8) != 0);
    v24 = v23;
    if ( JointGroup != nullptr )
    {
      DamageGroup = idActor::GetDamageGroup(
                      this: ai,
                      joint: (const idIndex<short,enum invalidJointIndex_t> *)JointGroup->joints.list->value);
      v25 = DamageGroup;
      if ( DamageGroup != nullptr )
        v24 |= DamageGroup->forceInjured;
    }
    else
    {
      v25 = nullptr;
    }
    if ( (*((_BYTE *)&decl->damageBehaviors + 85) & 8) != 0
      && (ai->actorVolatile.pain.damageDecl->damageTypes & 0x100) != 0 )
    {
      idStr::idStr(this: &v125, text: "pain_explosion");
      if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED )
        idStr::Append(this: &v125, text: "_crouch");
      idAI2::GetSubWebPrefix(this: ai, weapon: v12, swt: 5, subWebPrefix: (idStr *)&v122.subWebs.num);
      idStr::Append(
        this: (idStr *)&v122.subWebs.num,
        text: (char *)subWebNameForDamageDir[ai->actorVolatile.pain.direction]);
      SubWebIndexForName = (__int16 *)idDeclAnimWeb::GetSubWebIndexForName(
                                        this: (idDeclAnimWeb *)&v122.resourceError,
                                        result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
                                        subWebName: (const char *)v122.subWebs.size);
      v28 = (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl;
      v121.value = *SubWebIndexForName;
      StateIndexForName = (__int16 *)idDeclAnimWeb::GetStateIndexForName(
                                       this: (idDeclAnimWeb *)&v122.nextOnHashChain,
                                       result: v28,
                                       name: v125.data);
      GetPosture = ai->GetPosture;
      v120.value = *StateIndexForName;
      if ( GetPosture(this: ai) == POSTURE_CROUCHED
        && idAI2::GetAnimForAnimWebNode(this: ai, swi: &v121, si: &v120) == nullptr )
      {
        idStr::operator=(this: &v125, text: "pain_explosion");
        v120.value = HIWORD(idDeclAnimWeb::GetStateIndexForName(
                              this: (idDeclAnimWeb *)&v122.nextOnHashChain,
                              result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
                              name: v125.data)->__vftable);
      }
      idStr::FreeData(this: &v125);
    }
    else if ( (ai->actorVolatile.pain.damageDecl->damageTypes & 0x400) != 0 )
    {
      idStr::operator=(this: (idStr *)&v122.edges.num, text: "pain_shock");
      idAI2::GetSubWebPrefix(this: ai, weapon: v12, swt: 5, subWebPrefix: (idStr *)&v122.subWebs.num);
      idStr::Append(this: (idStr *)&v122.subWebs.num, text: (char *)subWebNameForDamageDir[1]);
      idStr::operator=(this: (idStr *)&v122.layers.num, text: "idle");
      v31 = (__int16 *)idDeclAnimWeb::GetSubWebIndexForName(
                         this: (idDeclAnimWeb *)&v122.nextOnHashChain,
                         result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
                         subWebName: (const char *)v122.subWebs.size);
      v32 = (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl;
      v121.value = *v31;
      v120.value = HIWORD(idDeclAnimWeb::GetStateIndexForName(
                            this: (idDeclAnimWeb *)&v122.resourceError,
                            result: v32,
                            name: (const char *)v122.edges.size)->__vftable);
    }
    if ( idAI2::GetAnimForAnimWebNode(this: ai, swi: &v121, si: &v120) != nullptr )
      goto LABEL_104;
    if ( ai_enableMovingPains.valueInteger == 0 )
      goto LABEL_104;
    v33 = *(_DWORD *)&v122.programaticallyDefined;
    if ( (*(_BYTE *)(*(_DWORD *)&v122.programaticallyDefined + 172) & 0x20) == 0 )
      goto LABEL_104;
    if ( ai->GetPosture(this: ai) != POSTURE_STANDING
      || (float)((float)(*(float *)&v122.nodes.granularity * *(float *)&v122.nodes.granularity)
               + (float)((float)(*(float *)&v122.nodes.num * *(float *)&v122.nodes.num)
                       + (float)(*(float *)&v122.nodes.size * *(float *)&v122.nodes.size))) <= (double)(float)(*(float *)(v33 + 116) * *(float *)(v33 + 116))
      || ai->actorVolatile.walkState < WALKSTATE_RUNNING )
    {
      if ( ai_debugLevel.valueInteger != 0 && ai_debugPain.valueInteger != 0 )
      {
        v119 = __fsqrts((float)((float)(*(float *)&v122.nodes.granularity * *(float *)&v122.nodes.granularity)
                              + (float)((float)(*(float *)&v122.nodes.num * *(float *)&v122.nodes.num)
                                      + (float)(*(float *)&v122.nodes.size * *(float *)&v122.nodes.size))));
        idLib::Printf(
          fmt: (const char *)HIDWORD(v119),
          LODWORD(v119),
          (unsigned int)COERCE_UNSIGNED_INT64(*(float *)(v33 + 116)));
      }
      goto LABEL_104;
    }
    idAI2::GetSubWebPrefix(this: ai, weapon: v12, swt: 6, subWebPrefix: (idStr *)&v122.subWebs.num);
    v122.staleCount = v122.nodes.num;
    *((_DWORD *)&v122.idResource + 8) = v122.nodes.size;
    v122.textSource = *(char **)&v122.nodes.granularity;
    idVec3::NormalizeFast(this: (idVec3 *)&v122.staleCount);
    RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: ai);
    p_deferredAxis = (float *)&RenderModelFromPresentable->deferredAxis;
    if ( !RenderModelFromPresentable->useDeferredPosition )
      p_deferredAxis = (float *)&RenderModelFromPresentable->g.axis;
    v36 = *((float *)&v122.idResource + 8);
    v37 = *(float *)&v122.staleCount;
    v38 = (float)((float)(*p_deferredAxis * *(float *)&v122.staleCount)
                + (float)((float)(p_deferredAxis[1] * *((float *)&v122.idResource + 8))
                        + (float)(p_deferredAxis[2] * *(float *)&v122.textSource)));
    idStr::idStr(this: &v124, text: "_front");
    if ( v38 < 0.70710677 )
    {
      if ( v38 >= -0.70710677 )
      {
        v40 = idEntity::GetRenderModelFromPresentable(this: ai);
        p_axis = (float *)&v40->deferredAxis;
        if ( !v40->useDeferredPosition )
          p_axis = (float *)&v40->g.axis;
        if ( (float)((float)(p_axis[1] * (float)v37) - (float)((float)v36 * *p_axis)) >= 0.0 )
          v39 = "_right";
        else
          v39 = "_left";
      }
      else
      {
        v39 = "_back";
      }
      idStr::operator=(this: &v124, text: v39);
    }
    idStr::Append(this: (idStr *)&v122.subWebs.num, text: &v124);
    v121.value = HIWORD(idDeclAnimWeb::GetSubWebIndexForName(
                          this: (idDeclAnimWeb *)&v122.nextOnHashChain,
                          result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
                          subWebName: (const char *)v122.subWebs.size)->__vftable);
    idStr::idStr(this: &v126, text: (const idStr *)&v122.edges.num);
    if ( JointGroup != nullptr && v24 != 0 )
    {
      idStr::Append(this: (idStr *)&v122.edges.num, text: "_toinjured");
      v120.value = HIWORD(idDeclAnimWeb::GetStateIndexForName(
                            this: (idDeclAnimWeb *)&v122.nextOnHashChain,
                            result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
                            name: (const char *)v122.edges.size)->__vftable);
    }
    if ( v120.value >= 0 && idAI2::GetAnimForAnimWebNode(this: ai, swi: &v121, si: &v120) != nullptr && v25 != nullptr )
    {
      idStr::operator=(this: (idStr *)&v122.layers.num, text: "idle_crouch");
      injuredIdleIndex = (int)v25->injuredIdleIndex;
      v122.resourceListPtr = (idResourceList *)(int)v25->forwardRunIndex;
      *((_DWORD *)&v122.idResource + 8) = injuredIdleIndex;
      resourceListPtr = (int)v122.resourceListPtr;
      str = injuredIdleIndex;
    }
    else
    {
      idStr::operator=(this: (idStr *)&v122.edges.num, text: &v126);
      v120.value = HIWORD(idDeclAnimWeb::GetStateIndexForName(
                            this: (idDeclAnimWeb *)&v122.nextOnHashChain,
                            result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
                            name: (const char *)v122.edges.size)->__vftable);
    }
    if ( idAI2::GetAnimForAnimWebNode(this: ai, swi: &v121, si: &v120) == nullptr )
      goto LABEL_88;
    if ( resourceListPtr == -1 )
      idStr::operator=(this: (idStr *)&v122.layers.num, text: "run");
    if ( ai_newMovingPainTest.valueInteger == 0 )
    {
      AnimForAnimWebNode = idAI2::GetAnimForAnimWebNode(this: ai, swi: &v121, si: &v120);
      idAI2::GetAnimationDelta(this: ai, anim: AnimForAnimWebNode, outDelta: (idVec3 *)&v122.nodeCache.num);
      presentable = ai->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: ai);
        presentable = ai->presentable;
      }
      v45 = (float)(presentable->axis.mat[2].z * *(float *)&v122.nodeCache.granularity);
      v46 = (float)(presentable->axis.mat[2].y * *(float *)&v122.nodeCache.granularity);
      v47 = (float)(presentable->axis.mat[2].x * *(float *)&v122.nodeCache.granularity);
      z = presentable->axis.mat[1].z;
      v122.nextOnHashChain = (idResource *)&presentable->axis;
      v49 = (float)((float)(presentable->axis.mat[0].z * *(float *)&v122.nodeCache.num)
                  + (float)((float)((float)z * *(float *)&v122.nodeCache.size) + (float)v45));
      v50 = (float)((float)(presentable->axis.mat[0].y * *(float *)&v122.nodeCache.num)
                  + (float)((float)(presentable->axis.mat[1].y * *(float *)&v122.nodeCache.size) + (float)v46));
      v51 = (float)((float)(presentable->axis.mat[0].x * *(float *)&v122.nodeCache.num)
                  + (float)((float)(presentable->axis.mat[1].x * *(float *)&v122.nodeCache.size) + (float)v47));
      v52 = idEntity::GetPhysics(this: ai);
      v53 = (float *)v52->GetOrigin(this: v52, a2: 0);
      GetAAS = ai->GetAAS;
      v55 = (float)(v53[2] + (float)v49);
      v56 = (float)(v53[1] + (float)v50);
      *(float *)&v122.scalars.num = (float)v51 + *v53;
      *(float *)&v122.scalars.granularity = v55;
      *(float *)&v122.scalars.size = v56;
      v57 = GetAAS(this: ai);
      AASPosition = idActor::GetAASPosition(this: ai, aas: v57);
      v123[0] = 0.0;
      v123[1] = 0.0;
      memset(&v123[4], 0, 12);
      v123[2] = 0.0;
      v123[3] = 0.0;
      v123[7] = 0.0;
      v123[10] = 0.0;
      v123[8] = 0.0;
      v123[11] = 0.0;
      v123[9] = 0.0;
      memset(&v123[15], 0, 24);
      v123[12] = 0.0;
      v123[13] = 0.0;
      v123[14] = 0.0;
      v59 = (idAASPosition *)AASPosition;
      v60 = idEntity::GetPhysics(this: ai);
      aas = (idAAS2 *)v59->aas;
      v62 = v60;
      v63 = v59;
      v64 = aas->__vftable;
      v65 = ai->aiVolatile.aas.travelFlags & 0xFE78FFFF;
      AreaNum = (idResource *)idAASPosition::GetAreaNum(this: v63);
      GetOrigin = v62->GetOrigin;
      v122.nextOnHashChain = AreaNum;
      v68 = (int)GetOrigin(this: v62, a2: 0);
      ((void (__fastcall *)(idAAS2 *, float *, int, idResource *, int *, unsigned int, _DWORD, int))v64->TraceFloor)(
        a1: aas,
        a2: v123,
        a3: v68,
        a4: v122.nextOnHashChain,
        a5: &v122.scalars.num,
        a6: v65,
        a7: 0,
        a8: 1);
      v69 = v123[0] < 1.0;
      if ( v123[0] >= 1.0 )
      {
        ai->GetEyePos(this: ai, a2: (idVec3 *)&v122.editorModels.num);
        v70 = ai->presentable;
        entityNumber = ai->entityNumber;
        if ( v70 == nullptr )
        {
          idEntity::InitPresentableInternal(this: ai);
          v70 = ai->presentable;
        }
        y = v70->axis.mat[0].y;
        x = v70->axis.mat[0].x;
        v74 = (float)((float)(v70->axis.mat[1].y * *(float *)&v122.nodeCache.size)
                    + (float)(v70->axis.mat[2].y * *(float *)&v122.nodeCache.granularity));
        v75 = (float)((float)(v70->axis.mat[1].x * *(float *)&v122.nodeCache.size)
                    + (float)(v70->axis.mat[2].x * *(float *)&v122.nodeCache.granularity));
        *(float *)&v122.settings.gridSize = *(float *)&v122.editorModels.granularity
                                          + (float)((float)(v70->axis.mat[0].z * *(float *)&v122.nodeCache.num)
                                                  + (float)((float)(v70->axis.mat[1].z * *(float *)&v122.nodeCache.size)
                                                          + (float)(v70->axis.mat[2].z
                                                                  * *(float *)&v122.nodeCache.granularity)));
        v122.nextOnHashChain = (idResource *)&v70->axis;
        v122.settings.editPos.z = *(float *)&v122.editorModels.size
                                + (float)((float)((float)y * *(float *)&v122.nodeCache.num) + (float)v74);
        v122.settings.editPos.y = *(float *)&v122.editorModels.num
                                + (float)((float)(*(float *)&v122.nodeCache.num * (float)x) + (float)v75);
        idClip::TraceBounds(
          this: &clientGame->clip,
          result: &v127,
          start: (const idVec3 *)&v122.editorModels.num,
          end: (const idVec3 *)&v122.settings.editPos.y,
          trm: nullptr,
          clipMask: 1025,
          passEntityNumber: entityNumber);
        if ( v127.fraction >= 0.80000001
          || (v76 = idPlayer::CastTo(c: (idPlayer *)gameLocal->entities.ptr[v127.c.entityNum]),
              v69 = true,
              v76 != nullptr) )
        {
          v69 = false;
        }
      }
      if ( v69 )
      {
        valueInteger = ai_debugLevel.valueInteger;
        if ( ai_debugLevel.valueInteger != 0 )
        {
          v78 = ai_debugPain.valueInteger;
          if ( ai_debugPain.valueInteger != 0 )
          {
            v79 = idEntity::GetPhysics(this: ai);
            v80 = common->RW(this: common);
            v81 = v79;
            v83 = v79->GetOrigin;
            v82 = v80->__vftable;
            v84 = (int)v83(this: v81, a2: 0);
            ((void (__fastcall *)(idRenderWorld *, idColor *, int, int *, double))v82->DebugArrow)(
              a1: v80,
              a2: &idColor::colorRed,
              a3: v84,
              a4: &v122.scalars.num,
              a5: 1.0);
            valueInteger = ai_debugLevel.valueInteger;
            v78 = ai_debugPain.valueInteger;
          }
          if ( valueInteger != 0 && v78 != 0 )
            idLib::Printf(fmt: "idAlertCycle_Pain::Enter - no room for moving pain.");
        }
LABEL_88:
        ai->aiVolatile.memory.painFailed = true;
        idStr::FreeData(this: &v126);
        idStr::FreeData(this: &v124);
        idStr::FreeData(this: (idStr *)&v122.layers.num);
        idStr::FreeData(this: (idStr *)&v122.subWebs.num);
LABEL_141:
        idStr::FreeData(this: (idStr *)&v122.edges.num);
        return;
      }
      if ( ai_debugLevel.valueInteger == 0 )
      {
        md5Checksum = (idCVar *)v122.md5Checksum;
        JointGroup = (const idJointGroup *)v122.textLength;
        p_animation = (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> **)v122.declSource;
LABEL_99:
        idStr::FreeData(this: &v126);
        idStr::FreeData(this: &v124);
LABEL_104:
        if ( idAI2::GetAnimForAnimWebNode(this: ai, swi: &v121, si: &v120) == nullptr )
        {
          idAI2::GetSubWebPrefix(this: ai, weapon: v12, swt: 5, subWebPrefix: (idStr *)&v122.subWebs.num);
          idStr::Append(
            this: (idStr *)&v122.subWebs.num,
            text: (char *)subWebNameForDamageDir[ai->actorVolatile.pain.direction]);
          if ( JointGroup != nullptr && md5Checksum->valueInteger != 0 )
          {
            idStr::operator=(this: (idStr *)&v122.edges.num, text: JointGroup->groupName.str);
            if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED )
              idStr::Append(this: (idStr *)&v122.edges.num, text: (char *)v122.trackedMemory);
            if ( v24 != 0 && v25 != nullptr && v25->forwardRunIndex > 0.0 )
            {
              if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED )
              {
                idStr::Append(this: (idStr *)&v122.edges.num, text: "_toinjured");
                v122.name.str = (const char *)(int)v25->forwardRunIndex;
                *((_DWORD *)&v122.idResource + 8) = (int)v25->injuredIdleIndex;
                str = *((_DWORD *)&v122.idResource + 8);
                resourceListPtr = (int)v122.name.str;
              }
              else if ( ai->actorVolatile.pain.direction == DAMAGEDIR_FRONT )
              {
                idStr::Append(this: (idStr *)&v122.edges.num, text: "_toinjured");
                idStr::operator=(this: (idStr *)&v122.layers.num, text: "idle_crouch");
                *((_DWORD *)&v122.idResource + 8) = (int)v25->forwardRunIndex;
                v122.name.str = (const char *)(int)v25->injuredIdleIndex;
                str = (int)v122.name.str;
                resourceListPtr = *((_DWORD *)&v122.idResource + 8);
              }
              else
              {
                idAI2::GetSubWebPrefix(this: ai, weapon: v12, swt: 5, subWebPrefix: (idStr *)&v122.subWebs.num);
                idStr::Append(this: (idStr *)&v122.subWebs.num, text: (char *)subWebNameForDamageDir[1]);
                idStr::Append(this: (idStr *)&v122.edges.num, text: "_toinjured");
                idStr::operator=(this: (idStr *)&v122.layers.num, text: "idle_crouch");
                v91 = (const char *)(int)v25->injuredIdleIndex;
                *((_DWORD *)&v122.idResource + 8) = (int)v25->forwardRunIndex;
                v122.name.str = v91;
                resourceListPtr = *((_DWORD *)&v122.idResource + 8);
                str = (int)v91;
              }
            }
          }
          v92 = (__int16 *)idDeclAnimWeb::GetSubWebIndexForName(
                             this: (idDeclAnimWeb *)&v122.nextOnHashChain,
                             result: p_animation[10],
                             subWebName: (const char *)v122.subWebs.size);
          v93 = (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)p_animation[10];
          v121.value = *v92;
          v120.value = HIWORD(idDeclAnimWeb::GetStateIndexForName(
                                this: (idDeclAnimWeb *)&v122.resourceError,
                                result: v93,
                                name: (const char *)v122.edges.size)->__vftable);
        }
        *(_DWORD *)&v122.settings.showAbbreviatedNodeProps = 0;
        HIBYTE(v122.settings.defaultBlendOutWindow) = 0;
        *(_DWORD *)v122.settings.nodeProps = &v122.settings.defaultBlendOutWindow;
        *(_DWORD *)&v122.settings.nodeProps[4] = 20;
        idAI2::GetSubWebPrefix(
          this: ai,
          weapon: v12,
          swt: v122.models.num,
          subWebPrefix: (idStr *)&v122.settings.showAbbreviatedNodeProps);
        idDeclAnimWeb::GetSubWebIndexForName(
          this: &v122,
          result: p_animation[10],
          subWebName: *(const char **)v122.settings.nodeProps);
        idDeclAnimWeb::GetStateIndexForName(
          this: (idDeclAnimWeb *)((char *)&v122.__vftable + 2),
          result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)p_animation[10],
          name: (const char *)v122.layers.size);
        if ( (unsigned __int16)v121.value == 0xFFFF
          || (unsigned __int16)v120.value == 0xFFFF
          || HIWORD(v122.__vftable) == 0xFFFF
          || LOWORD(v122.__vftable) == 0xFFFF )
        {
          idLib::Warning(
            fmt: "idAlertCycle_Pain::Enter - invalid sub-web or state for pain: %s:%s",
            (const char *)v122.subWebs.size,
            (const char *)v122.edges.size);
          ai->aiVolatile.memory.painFailed = true;
          idStr::FreeData(this: (idStr *)&v122.settings.showAbbreviatedNodeProps);
          idStr::FreeData(this: (idStr *)&v122.layers.num);
          idStr::FreeData(this: (idStr *)&v122.subWebs.num);
        }
        else
        {
          if ( resourceListPtr >= 0 )
          {
            ai->SetPosture(this: ai, a2: POSTURE_CROUCHED);
            LODWORD(v94) = str;
            *(_QWORD *)&v122.staleCount = v94;
            *(_QWORD *)&v122.trackedMemory = __PAIR64__(str, resourceListPtr);
            idAnimWebAI::SetForwardRunIndex(
              this: (idAnimWebAI *)p_animation,
              newRunIndex: (float)__SPAIR64__(str, resourceListPtr),
              newIdleIndex: (float)v94,
              t: v96,
              blend: v95,
              a6: ANIMWEBAI_RUNINDEXTYPE_INJURED,
              a7: 1);
            idAnimator_WalkIK::DisableLeg(this: &ai->walkIK, num: 0);
            idAnimator_WalkIK::DisableLeg(this: &ai->walkIK, num: 1);
            if ( ai->aiEditable.behaviors.declBehaviorEvents != nullptr )
            {
              v97 = idEntity::GetPhysics(this: ai);
              GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
              v99 = v97;
              declBehaviorEvents = ai->aiEditable.behaviors.declBehaviorEvents;
              v102 = v97->GetOrigin;
              p_aiEventManager = &gameLocal->aiEventManager;
              v103 = v102(this: v99, a2: 0);
              idAIEventManager::AddEvent(
                this: (idAIEventManager *)&v122.trackedMemory,
                result: p_aiEventManager,
                eventDecl: declBehaviorEvents->injuredVOEventDecl,
                curTime: GameMs,
                originator: nullptr,
                instigator: ai,
                origin: v103,
                delay: 2000);
            }
          }
          if ( idAI2::ChangeAnimStateVia(
                 this: ai,
                 web: AIANIMWEB_BODY,
                 subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v122.__vftable),
                 stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)LOWORD(v122.__vftable),
                 viaSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v121.value,
                 viaStateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v120.value,
                 interruptPath: INTR_PATH_YES,
                 interruptBlend: INTR_BLEND_YES) == 1 )
            idAI2::SetAnimWebEvent(
              this: ai,
              web: AIANIMWEB_BODY,
              priority: PRIORITY_LOW,
              swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v122.__vftable),
              si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)LOWORD(v122.__vftable),
              eventType: ANIMWEB_EVENT_START_BLEND_IN,
              eventDef: &EV_AnimWeb_Wait);
          if ( md5Checksum->valueInteger != 0
            && JointGroup != nullptr
            && v25 != nullptr
            && (*((_BYTE *)&ai->aiEditable.death + 84) & 0x20) != 0 )
          {
            v106 = ((double (__fastcall *)(idAIHealth *))ai->aiHealth.GetBaseHealthRatio_Impl)(a1: &ai->aiHealth);
            v107 = ai->aiEditable.behaviors.decl;
            injuredRunThreshold = v107->damageBehaviors.injuredRunThreshold;
            v122.trackedMemory = (int)v107;
            if ( v106 < injuredRunThreshold )
            {
              injuredRunMode = v107->damageBehaviors.injuredRunMode;
              v122.trackedMemory = (int)v107;
              if ( injuredRunMode == AIINJUREDRUNMODE_MOSTDAMAGED
                && v25->forwardRunIndex != 0.0
                && p_animation[183] != (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)1
                && v122.models.size < *(_DWORD *)(*(_DWORD *)&v122.programaticallyDefined + 132) )
              {
                if ( ai->aiEditable.behaviors.declBehaviorEvents != nullptr )
                {
                  v110 = idEntity::GetPhysics(this: ai);
                  v111 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                  v112 = v110;
                  v113 = ai->aiEditable.behaviors.declBehaviorEvents;
                  v115 = v110->GetOrigin;
                  v114 = &gameLocal->aiEventManager;
                  v116 = v115(this: v112, a2: 0);
                  idAIEventManager::AddEvent(
                    this: (idAIEventManager *)&v122.trackedMemory,
                    result: v114,
                    eventDecl: v113->injuredVOEventDecl,
                    curTime: v111,
                    originator: nullptr,
                    instigator: ai,
                    origin: v116,
                    delay: 2000);
                }
                idAnimWebAI::SetForwardRunIndex(
                  this: (idAnimWebAI *)p_animation,
                  newRunIndex: v25->forwardRunIndex,
                  newIdleIndex: v25->injuredIdleIndex,
                  t: v105,
                  blend: v104,
                  a6: ANIMWEBAI_RUNINDEXTYPE_INJURED,
                  a7: 1);
              }
            }
          }
          idAI2::SetEnableHeadTracking(this: ai, enable: false);
          idAI2::UpdateGoreLevel(this: ai, painTest: true);
          v117 = idContents::ToFlags(this: &ai->aiConstants.physics.clipMask);
          idContents::FromFlags(this: &ai->aiConstants.physics.clipMask, flags: v117 | 0x400);
          idRibbon::~idRibbon(this: (idRibbon *)&ai->aiVolatile.meleeTrace);
          idStr::FreeData(this: (idStr *)&v122.settings.showAbbreviatedNodeProps);
          idStr::FreeData(this: (idStr *)&v122.layers.num);
          idStr::FreeData(this: (idStr *)&v122.subWebs.num);
        }
        goto LABEL_141;
      }
      if ( ai_debugPain.valueInteger != 0 )
      {
        v85 = idEntity::GetPhysics(this: ai);
        v86 = common->RW(this: common);
        v87 = v85;
        v89 = v85->GetOrigin;
        v88 = v86->__vftable;
        v90 = (int)v89(this: v87, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, idColor *, int, int *, double))v88->DebugArrow)(
          a1: v86,
          a2: &idColor::colorGreen,
          a3: v90,
          a4: &v122.scalars.num,
          a5: 1.0);
      }
      p_animation = (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> **)v122.declSource;
      JointGroup = (const idJointGroup *)v122.textLength;
      md5Checksum = (idCVar *)v122.md5Checksum;
    }
    if ( ai_debugLevel.valueInteger != 0 && ai_debugPain.valueInteger != 0 )
    {
      v118 = __fsqrts((float)((float)(*(float *)&v122.nodes.granularity * *(float *)&v122.nodes.granularity)
                            + (float)((float)(*(float *)&v122.nodes.num * *(float *)&v122.nodes.num)
                                    + (float)(*(float *)&v122.nodes.size * *(float *)&v122.nodes.size))));
      idLib::Printf(
        fmt: (const char *)HIDWORD(v118),
        LODWORD(v118),
        (unsigned int)COERCE_UNSIGNED_INT64(*(float *)(*(_DWORD *)&v122.programaticallyDefined + 116)));
      if ( v121.value < 0 || v120.value < 0 )
        idLib::Printf(
          fmt: "moving pain anim not found %s:%s, reverting to staggering pain\n",
          (const char *)v122.subWebs.size,
          (const char *)v122.edges.size);
    }
    goto LABEL_99;
  }
}


// ========================================================================
// __unwind$495417
// EA  : 0x82ABEF4C
// RVA : 0x00ABEF4C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_495417()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 896 + 224));
}


// ========================================================================
// __unwind$495418
// EA  : 0x82ABEF74
// RVA : 0x00ABEF74
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_495418()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 896 + 176));
}


// ========================================================================
// __unwind$495419
// EA  : 0x82ABEF9C
// RVA : 0x00ABEF9C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_495419()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 896 + 304));
}


// ========================================================================
// __unwind$495420
// EA  : 0x82ABEFC4
// RVA : 0x00ABEFC4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_495420()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 896 + 512));
}


// ========================================================================
// __unwind$495421
// EA  : 0x82ABEFEC
// RVA : 0x00ABEFEC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_495421()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 896 + 480));
}


// ========================================================================
// __unwind$495422
// EA  : 0x82ABF014
// RVA : 0x00ABF014
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_495422()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 896 + 544));
}


// ========================================================================
// __unwind$495423
// EA  : 0x82ABF03C
// RVA : 0x00ABF03C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void _unwind_495423()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 896 + 352));
}


// ========================================================================
// ?Evaluate@AC_MeleeFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ABF068
// RVA : 0x00ABF068
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall AC_MeleeFinished::Evaluate(
        AC_MeleeFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r4
  idFiniteStateMachine *FullPath; // r3
  idFiniteStateMachine *v11; // r31
  idAIStateTransition::aiTransCode_t result; // r3
  bool v13; // zf

  value = ai->aiVolatile.memory.lastAttacker.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return TRANSCODE_AC_MELEE_FINISHED;
  v8 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v8 == nullptr )
    return TRANSCODE_AC_MELEE_FINISHED;
  v9 = idEntity::CastTo(c: v8);
  if ( v9 == nullptr )
    return TRANSCODE_AC_MELEE_FINISHED;
  if ( idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v9) == nullptr )
    return TRANSCODE_AC_MELEE_FINISHED;
  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  v11 = FullPath;
  if ( FullPath == nullptr )
    return TRANSCODE_AC_MELEE_FINISHED;
  if ( (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) != 0 )
    return TRANSCODE_AC_MELEE_FINISHED;
  v13 = idFiniteStateMachine::GetStatus(this: v11) != 0;
  result = 0;
  if ( !v13 )
    return TRANSCODE_AC_MELEE_FINISHED;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_Melee@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABF130
// RVA : 0x00ABF130
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Melee::AIState_EnterState(
        idAlertCycle_Melee *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r6
  idEntity *v8; // r3
  idEntity *v9; // r3
  idTurret *v10; // r30
  idAIEntityState *v11; // r3
  idTurret *v12; // r4
  aiSenseState_t *v13; // r30
  int v14; // r27
  idVec3 *p_velocity; // r26
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  aiMelee_t MeleeTypeForTarget; // r3
  overrideAnim_t v18; // r30
  idEventArg *v19; // r27
  _BYTE v20[20]; // [sp+70h] [-110h] BYREF
  _BYTE v21[20]; // [sp+90h] [-F0h] BYREF
  float v22[5]; // [sp+B0h] [-D0h] BYREF
  _DWORD v23[5]; // [sp+D0h] [-B0h] BYREF
  int v24; // [sp+F0h] [-90h]
  overrideAnim_t v25; // [sp+F4h] [-8Ch]
  const idEventArg *v26; // [sp+F8h] [-88h]
  idEventArg v27; // [sp+110h] [-70h] BYREF
  idEventReceiver v28[6]; // [sp+130h] [-50h] BYREF

  idAI2::SetAlertCycle(this: ai, ac: ALERTCYCLE_COMBAT);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
  {
    idAnimBaseFSM::ClearDestination(this: &ai->aiVolatile.animation.animFSM);
  }
  else
  {
    idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&ai->aiVolatile.physics.moveState);
  }
  idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
  idAI2::SetCoverAction(this: ai, action: COVERACTION_NONE);
  idAI2::SetEnableHeadTracking(this: ai, enable: false);
  value = ai->aiVolatile.memory.lastAttacker.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v8 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v8 != nullptr )
    {
      v9 = idEntity::CastTo(c: v8);
      v10 = (idTurret *)v9;
      if ( v9 != nullptr )
      {
        v11 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v9);
        if ( v11 != nullptr )
        {
          v12 = v10;
          v13 = v11->senses.ptr[v11->lastSense];
          v14 = idAI2::MeleePreference(this: ai, target: v12);
          p_velocity = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v13)->velocity;
          ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v13);
          MeleeTypeForTarget = idAI2::GetMeleeTypeForTarget(
                                 this: ai,
                                 targetPos: &ConfirmedPhysicalSafe->origin,
                                 targetVel: p_velocity,
                                 meleeMask: -1,
                                 preferredMask: v14);
          if ( MeleeTypeForTarget != AIMELEE_NONE )
          {
            v18 = AIMeleeTypeToOverrideAnim(meleeType: MeleeTypeForTarget);
            if ( v18 != ANIMOVERRIDE_NONE )
            {
              idAI2::EndActionScript(this: ai);
              LODWORD(fsm[1].value.v[2]) = this;
              v25 = v18;
              HIBYTE(v23[0]) = 105;
              HIBYTE(v24) = 105;
              v22[1] = vec3_origin.x;
              HIBYTE(v22[0]) = 118;
              v23[1] = 0;
              v22[3] = vec3_origin.z;
              v22[2] = vec3_origin.y;
              v19 = idEventArg::idEventArg(this: &v27, data: ai);
              memcpy(Dst: v21, Src: v22, Size: sizeof(v21));
              memcpy(Dst: v20, Src: v23, Size: sizeof(v20));
              idEventReceiver::ProcessEvent(
                this: v28,
                result: fsm,
                ev: *(const idEventDef **)&v19->type,
                arg1: (const idEventArg *)LODWORD(v19->value.v[1]),
                arg2: (const idEventArg *)LODWORD(v19->value.v[2]),
                arg3: (const idEventArg *)__ROL4__(v24, 32),
                arg4: v26);
            }
          }
        }
      }
    }
  }
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_Dying@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABF358
// RVA : 0x00ABF358
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Dying::AIState_EnterState(
        idAlertCycle_Dying *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idEventArg *v8; // r3
  idAIStateLite *currentState; // r3
  const char *name; // r30
  const char *Classname; // r3
  char v12; // r6
  int num; // r7
  int v14; // r10
  idAIDeathSound *list; // r9
  int v16; // r11
  idAIDeathSound *v17; // r30
  const idDeclVoiceOver *voiceOver; // r5
  idEntityPtr<idEntity> *p_lastAttacker; // r30
  char v20; // r29
  int value; // r10
  idEntity *v22; // r3
  idEntity *v23; // r3
  idEntity *v24; // r4
  idAIEntityState *v25; // r3
  const idDeclDamage *damageDecl; // r11
  aiSenseState_t *v27; // r11
  idPhysics *Physics; // r26
  int GameMs; // r25
  idPhysics *v30; // r3
  const idDeclAIBehaviorEvents *declBehaviorEvents; // r24
  idAIEventManager *p_aiEventManager; // r26
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v34; // r23
  const idEntity *LastAttacker; // r3
  idEntity *v36; // r3
  idPlayer *v37; // r3
  idPlayer *v38; // r3
  const idPlayer *v39; // r29
  int v40; // r7
  idEntity *v41; // r3
  idProjectile_Arrow *v42; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v43; // r29
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v44; // r28
  idDeclAnimWebNode *v45; // r3
  const idDeclAnimWebNode::idModelInfo *v46; // r3
  __int64 v47; // r11
  idDeclAnimWeb v48; // [sp+50h] [-160h] BYREF

  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  v8 = idEventArg::idEventArg(this: (idEventArg *)&v48.subWebs.size, data: ai);
  idEventReceiver::ProcessEvent(
    this: (idEventReceiver *)&v48.programaticallyDefined,
    result: fsm,
    ev: *(const idEventDef **)&v8->type,
    arg1: (const idEventArg *)LODWORD(v8->value.v[1]));
  idAI2::SetAlertCycle(this: ai, ac: ALERTCYCLE_DYING);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
  {
    idAnimBaseFSM::ClearDestination(this: &ai->aiVolatile.animation.animFSM);
    if ( ai->aiVolatile.animation.animFSM.RespondsTo(this: &ai->aiVolatile.animation.animFSM, a2: &FSM_NotifyDead) )
    {
      idEventReceiver::ProcessEvent(
        this: (idEventReceiver *)&v48.programaticallyDefined,
        result: (idEventArg *)&ai->aiVolatile.animation.animFSM,
        ev: &FSM_NotifyDead);
    }
    else
    {
      currentState = ai->aiVolatile.animation.animFSM.currentState;
      name = FSM_NotifyDead.name;
      if ( currentState != nullptr )
      {
        Classname = idClass::GetClassname(this: currentState);
        idLib::Warning(fmt: "State '%s' didn't handle event '%s'", Classname, name);
      }
      else
      {
        idLib::Warning(fmt: "State '%s' didn't handle event '%s'", &byte_8200D768, FSM_NotifyDead.name);
      }
    }
  }
  else
  {
    idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
  }
  idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
  idAI2::SetEnableHeadTracking(this: ai, enable: false);
  idRibbon::~idRibbon(this: (idRibbon *)&ai->aiVolatile.meleeTrace);
  idAI2::SetSolid(this: ai, isSolid: false);
  v12 = 0;
  if ( ai->actorVolatile.pain.type == PAIN_DEATH )
  {
    num = ai->aiEditable.death.deathSounds.num;
    v14 = 0;
    if ( num > 0 )
    {
      list = ai->aiEditable.death.deathSounds.list;
      v16 = 0;
      while ( 1 )
      {
        v17 = &list[v16];
        if ( list[v16].damageType == ai->actorVolatile.pain.damageDecl )
          break;
        ++v14;
        ++v16;
        if ( v14 >= num )
          goto LABEL_19;
      }
      voiceOver = v17->voiceOver;
      if ( voiceOver != nullptr )
        idAIVoiceController::PlayVoiceOver(
          this: &ai->aiVolatile.voiceController,
          ai,
          vo: voiceOver,
          priority: AIVOICEPRIORITY_DEATH,
          samePriorityInterupts: false);
      if ( v17->soundShader != nullptr )
      {
        soundShaderParms_t::Clear(this: (soundShaderParms_t *)&v48.models.size);
        idEntity::StartSoundShader(
          this: ai,
          channel: SND_CHANNEL_AMBIENT,
          shader: v17->soundShader,
          parms: (const soundShaderParms_t *)&v48.models.size,
          peerMask: 0xFFu);
      }
      v12 = 1;
    }
  }
LABEL_19:
  if ( v12 == 0 )
  {
    p_lastAttacker = &ai->aiVolatile.memory.lastAttacker;
    v20 = 0;
    value = ai->aiVolatile.memory.lastAttacker.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v22 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
      && idEntity::CastTo(c: v22) != nullptr
      && (gameLocal->spawnIds.ptr[p_lastAttacker->spawnId.value & 0x1FFF] != p_lastAttacker->spawnId.value >> 13
       || (v23 = gameLocal->entities.ptr[p_lastAttacker->spawnId.value & 0x1FFF]) == nullptr
        ? (v24 = nullptr)
        : (v24 = idEntity::CastTo(c: v23)),
          (v25 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v24),
           (damageDecl = ai->aiVolatile.death.deathInfo.impulse.damageDecl) != nullptr)
       && !damageDecl->isStealthy
       || v25 != nullptr
       && (v27 = v25->senses.ptr[1])->lastUnconfirmedStimTime >= 0
       && curTime - v27->lastConfirmedStimTime < 5000) )
    {
      if ( ai->aiEditable.behaviors.declBehaviorEvents != nullptr )
      {
        Physics = idEntity::GetPhysics(this: ai);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v30 = Physics;
        declBehaviorEvents = ai->aiEditable.behaviors.declBehaviorEvents;
        GetOrigin = Physics->GetOrigin;
        p_aiEventManager = &gameLocal->aiEventManager;
        v34 = GetOrigin(this: v30, a2: 0);
        LastAttacker = idAIMemory::GetLastAttacker(this: &ai->aiVolatile.memory);
        idAIEventManager::AddEvent(
          this: (idAIEventManager *)&v48.name,
          result: p_aiEventManager,
          eventDecl: declBehaviorEvents->gotKilledVoiceEventDecl,
          curTime: GameMs,
          originator: ai,
          instigator: LastAttacker,
          origin: v34,
          delay: 0);
      }
    }
    else
    {
      v20 = 1;
    }
    if ( v20 != 0 )
    {
      if ( gameLocal->spawnIds.ptr[p_lastAttacker->spawnId.value & 0x1FFF] == p_lastAttacker->spawnId.value >> 13
        && (v36 = gameLocal->entities.ptr[p_lastAttacker->spawnId.value & 0x1FFF]) != nullptr )
      {
        v37 = (idPlayer *)idEntity::CastTo(c: v36);
      }
      else
      {
        v37 = nullptr;
      }
      v38 = idPlayer::CastTo(c: v37);
      v39 = v38;
      if ( v38 != nullptr )
      {
        idRageMetrics::StealthKill(this: clientGame->rageMetrics, player: v38, victim: ai);
        v40 = ai->aiVolatile.memory.lastInflictor.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v40 & 0x1FFF] == v40 >> 13
          && (v41 = gameLocal->entities.ptr[v40 & 0x1FFF]) != nullptr )
        {
          v42 = (idProjectile_Arrow *)idEntity::CastTo(c: v41);
        }
        else
        {
          v42 = nullptr;
        }
        if ( idProjectile_Arrow::CastTo(c: v42) != nullptr )
          idRageMetrics::StealthCrossbowKill(this: clientGame->rageMetrics, player: v39);
      }
    }
  }
  if ( (ai->aiVolatile.death.deathInfo.deathFlags & 0x10) == 0 )
  {
    v43 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)ai->aiVolatile.death.deathInfo.deathAnimSubWeb.value;
    v44 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)ai->aiVolatile.death.deathInfo.deathAnimState.value;
    if ( (__int16)v43 < 0 )
      goto LABEL_55;
    if ( (__int16)v44 < 0 )
      goto LABEL_55;
    blendParms_t::blendParms_t(this: (blendParms_t *)&v48.resourceListPtr);
    blendParms_t::SetDuration(this: (blendParms_t *)&v48.resourceListPtr, frame: 5);
    blendParms_t::SetDestStartFrame(this: (blendParms_t *)&v48.resourceListPtr, frame: 5);
    if ( idAnimator_AnimWeb::ForceState(
           this: (idAnimator_AnimWeb *)&ai->aiVolatile.animation,
           subWebIndex_: v43,
           stateIndex_: v44,
           blendParms: (const blendParms_t *)&v48.resourceListPtr,
           blendEventMask_: 0) != 1 )
      goto LABEL_55;
    idDeclAnimWeb::FindNodeIndex(
      this: &v48,
      result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
      subWebIndex: v43,
      stateIndex: v44);
    if ( SHIWORD(v48.__vftable) < 0 )
      return;
    if ( SHIWORD(v48.__vftable) != -1
      && (v45 = ai->aiVolatile.animation.animWebAnimator.ptr[0].decl->nodes.list[SHIWORD(v48.__vftable)]) != nullptr )
    {
      ai->aiVolatile.death.deathInfo.deathAnimationNode = v45;
      v46 = idDeclAnimWebNode::NumAnims(this: v45, modelIndex: nullptr);
      LODWORD(v47) = idRandom2::RandomInt(this: &clientGame->random, max: (int)&v46[-1].tagGroups + 3);
      *(_QWORD *)&v48.name.str = v47;
      ai->aiVolatile.animation.animWebAnimator.ptr[0].select01 = (float)v47;
    }
    else
    {
LABEL_55:
      ai->StartRagdoll(this: ai, a2: &ai->ragdollInfo);
    }
  }
}


// ========================================================================
// ?AIState_ExitState@idAlertCycle_Dying@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABF8E8
// RVA : 0x00ABF8E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Dying::AIState_ExitState(
        idAlertCycle_Dying *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idPhysics *Physics; // r29
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r27
  int GameMs; // r30
  idPhysics *v10; // r3
  const idDeclAIBehaviorEvents *declBehaviorEvents; // r26
  idAIEventManager *p_aiEventManager; // r29
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v14; // r3
  char v15; // [sp+50h] [-40h] BYREF

  idGameLocal::RemoveDyingAI(this: gameLocal, ai);
  idAIEventManager::RemoveEntityEvents(this: &gameLocal->aiEventManager, ent: ai);
  if ( ai->aiEditable.behaviors.declBehaviorEvents != nullptr )
  {
    Physics = idEntity::GetPhysics(this: ai);
    value = ai->aiVolatile.memory.lastAttacker.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v8 = idEntity::CastTo(c: v7);
    }
    else
    {
      v8 = nullptr;
    }
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v10 = Physics;
    declBehaviorEvents = ai->aiEditable.behaviors.declBehaviorEvents;
    GetOrigin = Physics->GetOrigin;
    p_aiEventManager = &gameLocal->aiEventManager;
    v14 = GetOrigin(this: v10, a2: 0);
    idAIEventManager::AddEvent(
      this: (idAIEventManager *)&v15,
      result: p_aiEventManager,
      eventDecl: declBehaviorEvents->bodyEventDecl,
      curTime: GameMs,
      originator: ai,
      instigator: v8,
      origin: v14,
      delay: 0);
  }
}


// ========================================================================
// ?InitStates@idAlertCycleFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82ABF9F0
// RVA : 0x00ABF9F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycleFSM::InitStates(idAlertCycleFSM *this, const idFiniteStateMachineParams *params)
{
  int value; // r3
  idEntity *v5; // r3
  idAI2 *v6; // r3
  idAI2 *v7; // r3

  idAIFSM::InitStates(this, params);
  this->AddState(this, a2: &this->stateDefault);
  this->AddState(this, a2: &this->stateExecuteDoomscript);
  this->AddState(this, a2: &this->stateExecuteCodeMoveAction);
  this->AddState(this, a2: &this->stateActionScript);
  this->AddState(this, a2: &this->stateDropFromShip);
  this->AddState(this, a2: &this->statePerformDropLanding);
  this->AddState(this, a2: &this->stateRelaxed);
  this->AddState(this, a2: &this->stateCombat);
  this->AddState(this, a2: &this->stateCombatSP);
  this->AddState(this, a2: &this->stateSearchSP);
  this->AddState(this, a2: &this->stateRoamSP);
  this->AddState(this, a2: &this->stateSearch);
  this->AddState(this, a2: &this->statePain);
  this->AddState(this, a2: &this->stateDying);
  this->AddState(this, a2: &this->stateDead);
  this->AddState(this, a2: &this->stateAvoid);
  this->AddState(this, a2: &this->stateMelee);
  this->AddState(this, a2: &this->stateWatchPossession);
  this->AddState(this, a2: &this->stateUnhandledError);
  this->AddState(this, a2: &this->statePassified);
  this->AddState(this, a2: &this->stateOnElevator);
  value = params->manager->owner.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = (idAI2 *)idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  v7 = idAI2::CastTo(c: v6);
  this->AddState(this, a2: &v7->patch1.stateStuck);
}


// ========================================================================
// ?AIState_ExitState@idAlertCycle_Pain@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABFC90
// RVA : 0x00ABFC90
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Pain::AIState_ExitState(
        idAlertCycle_Pain *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idPlayer *v5; // r4
  int value; // r8
  idEntity *v7; // r3
  idPlayer *v8; // r3
  idContents *p_clipMask; // r31
  int v10; // r3

  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) == 0 )
  {
    idAI2::GetDefaultMovementMode(this: ai);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&ai->aiVolatile.physics.moveState);
  }
  if ( ai->IsDead(this: ai) && ai->actorVolatile.pain.type == PAIN_STUN )
  {
    value = ai->aiVolatile.memory.lastAttacker.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v8 = (idPlayer *)idEntity::CastTo(c: v7);
    }
    else
    {
      v8 = nullptr;
    }
    v5 = idPlayer::CastTo(c: v8);
    if ( v5 != nullptr )
      idRageMetrics::ComboKill(this: clientGame->rageMetrics, player: v5, victim: ai);
  }
  if ( ((unsigned __int8 (__fastcall *)(idAI2 *, idPlayer *))ai->IsDead)(a1: ai, a2: v5) == 0
    && ai->actorVolatile.pain.type != PAIN_DEATH )
  {
    idActor::ClearPain(this: ai);
  }
  *((_BYTE *)&ai->aiVolatile.death + 1760) &= ~0x80u;
  idAI2::SetEnableHeadTracking(this: ai, enable: true);
  p_clipMask = &ai->aiConstants.physics.clipMask;
  v10 = idContents::ToFlags(this: p_clipMask);
  idContents::FromFlags(this: p_clipMask, flags: v10 & 0xFFFFFBFF);
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_Dead@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ABFDF0
// RVA : 0x00ABFDF0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_Dead::AIState_EnterState(
        idAlertCycle_Dead *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idPhysics *Physics; // r29
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r30
  int GameMs; // r27
  idPhysics *v10; // r3
  const idDeclAIBehaviorEvents *declBehaviorEvents; // r26
  idAIEventManager *p_aiEventManager; // r29
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v14; // r3
  idAIStateLite *currentState; // r3
  const char *name; // r30
  const char *Classname; // r3
  int v18; // r4
  idList<idEntityPtr<idEntity>,58> *p_activeAI; // r3
  int num; // r9
  int v21; // r11
  idAIEventManager v22; // [sp+50h] [-60h] BYREF

  if ( ai->aiEditable.behaviors.declBehaviorEvents != nullptr )
  {
    Physics = idEntity::GetPhysics(this: ai);
    value = ai->aiVolatile.memory.lastAttacker.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v8 = idEntity::CastTo(c: v7);
    }
    else
    {
      v8 = nullptr;
    }
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v10 = Physics;
    declBehaviorEvents = ai->aiEditable.behaviors.declBehaviorEvents;
    GetOrigin = Physics->GetOrigin;
    p_aiEventManager = &gameLocal->aiEventManager;
    v14 = GetOrigin(this: v10, a2: 0);
    idAIEventManager::AddEvent(
      this: &v22,
      result: p_aiEventManager,
      eventDecl: declBehaviorEvents->deadBodyLandEventDecl,
      curTime: GameMs,
      originator: ai,
      instigator: v8,
      origin: v14,
      delay: 400);
  }
  idAI2::SetAlertCycle(this: ai, ac: ALERTCYCLE_DEAD);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
  {
    idAnimBaseFSM::ClearDestination(this: &ai->aiVolatile.animation.animFSM);
    if ( ai->aiVolatile.animation.animFSM.RespondsTo(this: &ai->aiVolatile.animation.animFSM, a2: &FSM_NotifyDead) )
    {
      idEventReceiver::ProcessEvent(
        this: (idEventReceiver *)&v22.eventHash,
        result: (idEventArg *)&ai->aiVolatile.animation.animFSM,
        ev: &FSM_NotifyDead);
    }
    else
    {
      currentState = ai->aiVolatile.animation.animFSM.currentState;
      name = FSM_NotifyDead.name;
      if ( currentState != nullptr )
      {
        Classname = idClass::GetClassname(this: currentState);
        idLib::Warning(fmt: "State '%s' didn't handle event '%s'", Classname, name);
      }
      else
      {
        idLib::Warning(fmt: "State '%s' didn't handle event '%s'", &byte_8200D768, FSM_NotifyDead.name);
      }
    }
  }
  else
  {
    idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&ai->aiVolatile.physics.moveState);
  }
  idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
  idAI2::SetCoverAction(this: ai, action: COVERACTION_NONE);
  idAI2::SetEnableHeadTracking(this: ai, enable: false);
  ai->DisableAIEventResponse(this: ai, a2: AIEVENT_ALL);
  v18 = 0;
  p_activeAI = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->activeAI;
  num = gameLocal->activeAI.num;
  if ( num > 0 )
  {
    v21 = 0;
    while ( p_activeAI->list[v21].spawnId.value != ((gameLocal->spawnIds.ptr[ai->entityNumber] << 13) | ai->entityNumber) )
    {
      ++v18;
      ++v21;
      if ( v18 >= num )
        goto LABEL_21;
    }
    if ( v18 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_activeAI, index: v18);
  }
LABEL_21:
  idEntity::BecomeInactive(this: ai, flags: 1);
}


// ========================================================================
// ?AIState_EnterState@idAlertCycle_WatchPossessedGuy@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC0080
// RVA : 0x00AC0080
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __fastcall idAlertCycle_WatchPossessedGuy::AIState_EnterState(
        idAlertCycle_WatchPossessedGuy *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idEventArg *v8; // r3
  int value; // r8
  idEntity *v10; // r3
  idEntity *v11; // r4
  idEventArg *v12; // r24
  _BYTE v13[20]; // [sp+70h] [-E0h] BYREF
  idEventReceiver v14[2]; // [sp+90h] [-C0h] BYREF
  idEventArg v15; // [sp+B0h] [-A0h] BYREF
  idEventArg v16; // [sp+D0h] [-80h] BYREF
  idEventReceiver v17[8]; // [sp+F0h] [-60h] BYREF

  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) == 0 )
  {
    idAI2::GetDefaultMovementMode(this: ai);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&ai->aiVolatile.physics.moveState);
  }
  idAI2::SetAlertCycle(this: ai, ac: ALERTCYCLE_RELAXED);
  idAI2::SetEnableHeadTracking(this: ai, enable: true);
  idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
  idAI2::SetCoverAction(this: ai, action: COVERACTION_NONE);
  idAI2::ReleaseCover(this: ai);
  idActor::ClearPain(this: ai);
  if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED )
  {
    v8 = idEventArg::idEventArg(this: &v15, data: ai);
    idEventReceiver::ProcessEvent(
      this: v14,
      result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
      ev: *(const idEventDef **)&v8->type,
      arg1: (const idEventArg *)LODWORD(v8->value.v[1]));
  }
  value = ai->aiVolatile.memory.nearbyPossessed.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v10 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v10 != nullptr )
    {
      v11 = idEntity::CastTo(c: v10);
      if ( v11 != nullptr )
        idAI2::SetAimFocusEntity(this: ai, ent: v11, keepFocusInView: true, aimPoint: AIMPOINT_EYELEVEL, timeout: -1);
    }
  }
  HIBYTE(v14[0].__vftable) = 105;
  v14[0].listenerList = (idList<idEventReceiver *,5> *)1;
  v15.type = 105;
  v15.value.i = -1;
  v12 = idEventArg::idEventArg(this: &v16, data: ai);
  memcpy(Dst: v13, Src: v14, Size: sizeof(v13));
  idEventReceiver::ProcessEvent(
    this: v17,
    result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
    ev: *(const idEventDef **)&v12->type,
    arg1: (const idEventArg *)LODWORD(v12->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v12->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v15.type, 32));
  idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
}


// ========================================================================
// `dynamic initializer for 'ai_showDeathInfo''
// EA  : 0x83369558
// RVA : 0x01369558
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_showDeathInfo__()
{
  idCVar::idCVar(
    this: &ai_showDeathInfo,
    name: "ai_showDeathInfo",
    value: "0",
    flags: 1,
    description: "1 = show pain info on death",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_showDeathInfo__);
}


// ========================================================================
// `dynamic initializer for 'ai_forceInjury''
// EA  : 0x833695B0
// RVA : 0x013695B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_forceInjury__()
{
  idCVar::idCVar(
    this: &ai_forceInjury,
    name: "ai_forceInjury",
    value: "0",
    flags: 1,
    description: "1 = force stagger pains to be injuries",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_forceInjury__);
}


// ========================================================================
// `dynamic initializer for 'ai_painGoreTest''
// EA  : 0x83369608
// RVA : 0x01369608
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_painGoreTest__()
{
  idCVar::idCVar(
    this: &ai_painGoreTest,
    name: "ai_painGoreTest",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_painGoreTest__);
}

