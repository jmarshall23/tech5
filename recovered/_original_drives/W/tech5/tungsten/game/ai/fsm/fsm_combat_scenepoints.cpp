
// ========================================================================
// ?InternalInitState@idCombatScenePoint_Find@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ACAE10
// RVA : 0x00ACAE10
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_Find::InternalInitState(
        idCombatScenePoint_Find *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Melee::Type,
    nextStateType: &idCombatScenePoint_Melee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Reload::Type,
    nextStateType: &idCombatScenePoint_Reload::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_ApplyRestriction::Type,
    nextStateType: &idCombatScenePoint_Find::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_ApplyRestriction::Type,
    nextStateType: &idCombatScenePoint_ApplyRestriction::Type,
    transCode: 454);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_MoveToScenePoint::Type,
    nextStateType: &idCombatScenePoint_MoveTo::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Close::Type,
    nextStateType: &idCombatScenePoint_Close::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_Find::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_SharedWaitForAnimation::Type,
    transCode: 454);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Idle::Type,
    nextStateType: &idCombatScenePoint_Idle::Type);
}


// ========================================================================
// ?InternalInitState@idCombatScenePoint_MoveTo@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ACAF30
// RVA : 0x00ACAF30
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_MoveTo::InternalInitState(
        idCombatScenePoint_MoveTo *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Melee::Type,
    nextStateType: &idCombatScenePoint_Melee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Reload::Type,
    nextStateType: &idCombatScenePoint_Reload::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_ApplyRestriction::Type,
    nextStateType: &idCombatScenePoint_Find::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_ApplyRestriction::Type,
    nextStateType: &idCombatScenePoint_ApplyRestriction::Type,
    transCode: 454);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Enter_Turret::Type,
    nextStateType: &idCombatScenePoint_UseTurret::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_StayAtScenePoint::Type,
    nextStateType: &idCombatScenePoint_StayAt::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_StayAtScenePoint::Type,
    nextStateType: &idCombatScenePoint_EnterScenePoint::Type,
    transCode: 454);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_Find::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_SharedWaitForAnimation::Type,
    transCode: 454);
}


// ========================================================================
// ?InternalInitState@idCombatScenePoint_StayAt@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ACB058
// RVA : 0x00ACB058
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_StayAt::InternalInitState(
        idCombatScenePoint_StayAt *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Melee::Type,
    nextStateType: &idCombatScenePoint_Melee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Reload::Type,
    nextStateType: &idCombatScenePoint_Reload::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_ApplyRestriction::Type,
    nextStateType: &idCombatScenePoint_Find::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_ApplyRestriction::Type,
    nextStateType: &idCombatScenePoint_ApplyRestriction::Type,
    transCode: 454);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_Find::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_SharedWaitForAnimation::Type,
    transCode: 454);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_TacticalAttack::Type,
    nextStateType: &idCombatScenePoint_TacticalAttack::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_TacticalCover::Type,
    nextStateType: &idCombatScenePoint_TacticalCover::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Close::Type,
    nextStateType: &idCombatScenePoint_Close::Type);
}


// ========================================================================
// ?InternalInitState@idCombatScenePoint_TacticalAttack@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ACB178
// RVA : 0x00ACB178
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_TacticalAttack::InternalInitState(
        idCombatScenePoint_TacticalAttack *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Reload::Type,
    nextStateType: &idCombatScenePoint_Reload::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_ApplyRestriction::Type,
    nextStateType: &idCombatScenePoint_Find::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_ApplyRestriction::Type,
    nextStateType: &idCombatScenePoint_ApplyRestriction::Type,
    transCode: 454);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_Find::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_SharedWaitForAnimation::Type,
    transCode: 454);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_TacticalCover::Type,
    nextStateType: &idCombatScenePoint_TacticalCover::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Close::Type,
    nextStateType: &idCombatScenePoint_Close::Type);
}


// ========================================================================
// ?InternalInitState@idCombatScenePoint_TacticalCover@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ACB260
// RVA : 0x00ACB260
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_TacticalCover::InternalInitState(
        idCombatScenePoint_TacticalCover *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Reload::Type,
    nextStateType: &idCombatScenePoint_Reload::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_ApplyRestriction::Type,
    nextStateType: &idCombatScenePoint_Find::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_ApplyRestriction::Type,
    nextStateType: &idCombatScenePoint_ApplyRestriction::Type,
    transCode: 454);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_Find::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_SharedWaitForAnimation::Type,
    transCode: 454);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_TacticalAttack::Type,
    nextStateType: &idCombatScenePoint_TacticalAttack::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Close::Type,
    nextStateType: &idCombatScenePoint_Close::Type);
}


// ========================================================================
// ?InternalInitState@idCombatScenePoint_UseTurret@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ACB348
// RVA : 0x00ACB348
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_UseTurret::InternalInitState(
        idCombatScenePoint_UseTurret *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_SharedWaitForAnimation::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_SharedWaitForAnimation::Type,
    transCode: 454);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Exit_Turret::Type,
    nextStateType: &idCombatScenePoint_SharedWaitForAnimation::Type);
}


// ========================================================================
// ?InternalInitState@idCombatScenePoint_Close@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ACB3B8
// RVA : 0x00ACB3B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_Close::InternalInitState(
        idCombatScenePoint_Close *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Melee::Type,
    nextStateType: &idCombatScenePoint_Melee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Dodge::Type,
    nextStateType: &idCombatScenePoint_Dodge::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Reload::Type,
    nextStateType: &idCombatScenePoint_Reload::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_ApplyRestriction::Type,
    nextStateType: &idCombatScenePoint_Find::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_ApplyRestriction::Type,
    nextStateType: &idCombatScenePoint_ApplyRestriction::Type,
    transCode: 454);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_Find::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_SharedWaitForAnimation::Type,
    transCode: 454);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Close::Type,
    nextStateType: &idCombatScenePoint_Close::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Idle::Type,
    nextStateType: &idCombatScenePoint_Idle::Type);
}


// ========================================================================
// ?InternalInitState@idCombatScenePoint_ApplyRestriction@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ACB4D8
// RVA : 0x00ACB4D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_ApplyRestriction::InternalInitState(
        idCombatScenePoint_ApplyRestriction *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Melee::Type,
    nextStateType: &idCombatScenePoint_Melee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Dodge::Type,
    nextStateType: &idCombatScenePoint_Dodge::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Reload::Type,
    nextStateType: &idCombatScenePoint_Reload::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shared_Finished::Type,
    nextStateType: &idCombatScenePoint_SharedFinished::Type);
}


// ========================================================================
// ?InternalInitState@idCombatScenePoint_EnterScenePoint@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ACB578
// RVA : 0x00ACB578
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_EnterScenePoint::InternalInitState(
        idCombatScenePoint_EnterScenePoint *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shared_Finished::Type,
    nextStateType: &idCombatScenePoint_StayAt::Type);
}


// ========================================================================
// ?InternalInitState@idCombatScenePoint_Reload@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ACB590
// RVA : 0x00ACB590
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_Reload::InternalInitState(
        idCombatScenePoint_SharedWaitForAnimation *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shared_Finished::Type,
    nextStateType: &idCombatScenePoint_SharedFinished::Type);
}


// ========================================================================
// ?InternalInitState@idCombatScenePoint_SharedFinished@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ACB5A8
// RVA : 0x00ACB5A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_SharedFinished::InternalInitState(
        idCombatScenePoint_SharedFinished *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Melee::Type,
    nextStateType: &idCombatScenePoint_Melee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Dodge::Type,
    nextStateType: &idCombatScenePoint_Dodge::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Reload::Type,
    nextStateType: &idCombatScenePoint_Reload::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_ApplyRestriction::Type,
    nextStateType: &idCombatScenePoint_Find::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_ApplyRestriction::Type,
    nextStateType: &idCombatScenePoint_ApplyRestriction::Type,
    transCode: 454);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_MoveToScenePoint::Type,
    nextStateType: &idCombatScenePoint_MoveTo::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_StayAtScenePoint::Type,
    nextStateType: &idCombatScenePoint_StayAt::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_TacticalAttack::Type,
    nextStateType: &idCombatScenePoint_TacticalAttack::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_TacticalCover::Type,
    nextStateType: &idCombatScenePoint_TacticalCover::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_Find::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_SharedWaitForAnimation::Type,
    transCode: 454);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Close::Type,
    nextStateType: &idCombatScenePoint_Close::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Idle::Type,
    nextStateType: &idCombatScenePoint_Idle::Type);
}


// ========================================================================
// ?InternalInitState@idCombatScenePoint_Idle@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ACB738
// RVA : 0x00ACB738
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_Idle::InternalInitState(
        idCombatScenePoint_Idle *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Melee::Type,
    nextStateType: &idCombatScenePoint_Melee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Dodge::Type,
    nextStateType: &idCombatScenePoint_Dodge::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Reload::Type,
    nextStateType: &idCombatScenePoint_Reload::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_ApplyRestriction::Type,
    nextStateType: &idCombatScenePoint_Find::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_ApplyRestriction::Type,
    nextStateType: &idCombatScenePoint_ApplyRestriction::Type,
    transCode: 454);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_MoveToScenePoint::Type,
    nextStateType: &idCombatScenePoint_MoveTo::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_StayAtScenePoint::Type,
    nextStateType: &idCombatScenePoint_StayAt::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_TacticalAttack::Type,
    nextStateType: &idCombatScenePoint_TacticalAttack::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_TacticalCover::Type,
    nextStateType: &idCombatScenePoint_TacticalCover::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_Find::Type,
    transCode: 453);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idCombatScenePoint_SharedWaitForAnimation::Type,
    transCode: 454);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &CombatScenePoint_Shall_Close::Type,
    nextStateType: &idCombatScenePoint_Close::Type);
}


// ========================================================================
// ?InitStates@idCombatScenePointFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82ACB8B0
// RVA : 0x00ACB8B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePointFSM::InitStates(
        idCombatScenePointFSM *this,
        const idFiniteStateMachineParams *params)
{
  idAIFSM::InitStates(this, params);
  this->AddState(this, a2: &this->stateCombatSPFind);
  this->AddState(this, a2: &this->stateCombatSPMoveTo);
  this->AddState(this, a2: &this->stateCombatSPStayAt);
  this->AddState(this, a2: &this->stateCombatSPEnter);
  this->AddState(this, a2: &this->stateCombatSPTacticalAttack);
  this->AddState(this, a2: &this->stateCombatSPTacticalCover);
  this->AddState(this, a2: &this->stateCombatSPUseTurret);
  this->AddState(this, a2: &this->stateCombatSPClose);
  this->AddState(this, a2: &this->stateCombatSPIdle);
  this->AddState(this, a2: &this->stateCombatSPApplyRestriction);
  this->AddState(this, a2: &this->stateCombatSPReload);
  this->AddState(this, a2: &this->stateCombatSPMelee);
  this->AddState(this, a2: &this->stateCombatSPDodge);
  this->AddState(this, a2: &this->stateCombatSPSharedFinished);
  this->AddState(this, a2: &this->stateCombatSPSharedWaitForAnimation);
}


// ========================================================================
// ?Evaluate@CombatScenePoint_Shall_MoveToScenePoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ACBA48
// RVA : 0x00ACBA48
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall CombatScenePoint_Shall_MoveToScenePoint::Evaluate(
        CombatScenePoint_Shall_MoveToScenePoint *this,
        idAI2 *ai,
        idCombatScenePointFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idCombatScenePointFSM *v6; // r3
  idScenePoint *curScenePoint; // r11
  char v8; // r11
  bool v9; // zf
  int stayTime; // r11
  idAIStateTransition::aiTransCode_t result; // r3

  v6 = idCombatScenePointFSM::CastTo(c: parentFSM);
  curScenePoint = ai->aiVolatile.memory.curScenePoint;
  if ( curScenePoint == nullptr || (v9 = curScenePoint->type == 4, v8 = 1, !v9) )
    v8 = 0;
  if ( v8 == 0 )
    return 0;
  stayTime = v6->stayTime;
  result = TRANSCODE_MAX;
  if ( stayTime != -1 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@CombatScenePoint_Shall_TacticalAttack@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ACBAC0
// RVA : 0x00ACBAC0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

int __fastcall CombatScenePoint_Shall_TacticalAttack::Evaluate(
        CombatScenePoint_Shall_TacticalAttack *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idCombatScenePoint_TacticalCover *state,
        unsigned int curTime)
{
  idScenePoint_Combat *v7; // r3
  idCombatScenePoint_TacticalCover *v8; // r3
  __int64 v9; // r11

  v7 = idScenePoint_Combat::CastTo(c: (idScenePoint_Combat *)ai->aiVolatile.memory.curScenePoint);
  if ( v7 == nullptr || v7->customSet.customCoverSet.len != 0 || !idScenePoint_Combat::IsTactical(this: v7) )
    return 0;
  v8 = idCombatScenePoint_TacticalCover::CastTo(c: state);
  if ( v8 == nullptr )
    return 456;
  LODWORD(v9) = v8->coverTime;
  HIDWORD(v9) = curTime >> 31;
  return ((v9 - __PAIR64__((unsigned int)v9 >> 31, curTime)) >> 32) & 0x1C8;
}


// ========================================================================
// ?Evaluate@CombatScenePoint_Shall_TacticalCover@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ACBB68
// RVA : 0x00ACBB68
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

int __fastcall CombatScenePoint_Shall_TacticalCover::Evaluate(
        CombatScenePoint_Shall_TacticalCover *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idCombatScenePoint_TacticalAttack *state,
        int curTime)
{
  idScenePoint_Combat *v8; // r3
  idCombatScenePoint_TacticalAttack *v9; // r3

  v8 = idScenePoint_Combat::CastTo(c: (idScenePoint_Combat *)ai->aiVolatile.memory.curScenePoint);
  if ( v8 == nullptr || v8->customSet.customCoverSet.len != 0 || !idScenePoint_Combat::IsTactical(this: v8) )
    return 0;
  v9 = idCombatScenePoint_TacticalAttack::CastTo(c: state);
  if ( v9 != nullptr && curTime > v9->attackTime )
    return 456;
  else
    return ai->aiVolatile.cover.coverAction != COVERACTION_NONE ? 0 : 0x1C8;
}


// ========================================================================
// ?Evaluate@CombatScenePoint_Shall_Idle@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ACBC10
// RVA : 0x00ACBC10
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall CombatScenePoint_Shall_Idle::Evaluate(
        CombatScenePoint_Shall_Idle *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIStateTransition::aiTransCode_t result; // r3
  idScenePoint *curScenePoint; // r11
  char v9; // r11
  bool v10; // zf
  const aiSenseState_t *EnemySenseState; // r3
  int lastConfirmedStimTime; // r11

  if ( !ai->aiEditable.actionSettings.cover.usesIdle )
    return 0;
  curScenePoint = ai->aiVolatile.memory.curScenePoint;
  if ( curScenePoint == nullptr || (v10 = curScenePoint->type == 4, v9 = 1, !v10) )
    v9 = 0;
  if ( v9 != 0 )
    return 0;
  if ( ai->aiEditable.perception.combatTimeoutInterval < 0.0 )
    return TRANSCODE_MAX;
  EnemySenseState = idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  if ( EnemySenseState == nullptr )
    return TRANSCODE_MAX;
  lastConfirmedStimTime = EnemySenseState->lastConfirmedStimTime;
  if ( lastConfirmedStimTime <= 0 )
    return TRANSCODE_MAX;
  result = 0;
  if ( curTime - lastConfirmedStimTime <= (int)(float)((float)1000.0 * ai->aiEditable.perception.combatTimeoutInterval) )
    return TRANSCODE_MAX;
  return result;
}


// ========================================================================
// ?Evaluate@CombatScenePoint_Shall_Reload@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ACBCF0
// RVA : 0x00ACBCF0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall CombatScenePoint_Shall_Reload::Evaluate(
        CombatScenePoint_Shall_Reload *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idWeapon *v5; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v7; // zf

  v5 = ai->GetEquippedWeapon(this: ai);
  if ( v5 == nullptr )
    return 0;
  if ( v5->fireState == FIRESTATE_RELOADING )
    return 0;
  v7 = v5->NeedsReload(this: v5, a2: false);
  result = TRANSCODE_MAX;
  if ( !v7 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idCombatScenePoint_Find@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACBD60
// RVA : 0x00ACBD60
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_Find::AIState_EnterState(
        idCombatScenePoint_Find *this,
        idAI2 *ai,
        idCombatScenePointFSM *fsm,
        const int curTime)
{
  idScenePoint *BestScenePoint; // r30
  idCombatScenePointFSM *v8; // r3

  BestScenePoint = GetBestScenePoint(
                     ai,
                     minRange: ai->aiEditable.actionSettings.cover.coverMinRange,
                     maxRange: ai->aiEditable.actionSettings.cover.coverMaxRange,
                     _focus: (const idAIPos *)ai,
                     spType: (scenePointType_t)fsm,
                     lookFlags: (scenePointLookFlags_t)&ai->aiVolatile.memory.currentEnemySuspectedPos);
  if ( BestScenePoint != nullptr )
  {
    v8 = idCombatScenePointFSM::CastTo(c: fsm);
    if ( v8 != nullptr )
    {
      v8->stayTime = -1;
      v8->enterValid = false;
    }
    ai->aiVolatile.memory.curScenePoint = BestScenePoint;
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?AIState_ReenterState@idCombatScenePoint_Find@@UAAXPAVidAI2@@PAVidAIFSM@@HH@Z
// EA  : 0x82ACBDF0
// RVA : 0x00ACBDF0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_Find::AIState_ReenterState(
        idCombatScenePoint_Find *this,
        idAI2 *ai,
        idCombatScenePointFSM *fsm,
        const int transCode,
        const int curTime)
{
  idScenePoint *curScenePoint; // r11
  char v9; // r11
  bool v10; // zf
  idScenePoint *BestScenePoint; // r30
  idCombatScenePointFSM *v12; // r3
  int v13; // [sp+5Ch] [-34h]

  curScenePoint = ai->aiVolatile.memory.curScenePoint;
  if ( curScenePoint == nullptr || (v10 = curScenePoint->type == 4, v9 = 1, !v10) )
    v9 = 0;
  if ( v9 == 0 )
  {
    v13 = *(_DWORD *)&ai->aiVolatile.memory.currentEnemySuspectedPos.bValid;
    if ( HIBYTE(v13) != 0
      && (BestScenePoint = GetBestScenePoint(
                             ai,
                             minRange: ai->aiEditable.actionSettings.cover.coverMinRange,
                             maxRange: ai->aiEditable.actionSettings.cover.coverMaxRange,
                             _focus: (const idAIPos *)HIBYTE(v13),
                             spType: (scenePointType_t)fsm,
                             lookFlags: (scenePointLookFlags_t)&ai->aiVolatile.memory.currentEnemySuspectedPos)) != nullptr )
    {
      v12 = idCombatScenePointFSM::CastTo(c: fsm);
      if ( v12 != nullptr )
      {
        v12->stayTime = -1;
        v12->enterValid = false;
      }
      ai->aiVolatile.memory.curScenePoint = BestScenePoint;
    }
    else
    {
      idState::SetEnterFailed(this, failed: true);
    }
  }
}


// ========================================================================
// ?AIState_ExitState@idCombatScenePoint_MoveTo@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACBEE8
// RVA : 0x00ACBEE8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_MoveTo::AIState_ExitState(
        idCombatScenePoint_MoveTo *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idScenePoint_Combat *v5; // r3
  idEntity *v6; // r29
  int v7; // r3
  idEntityPtr<idEntity> *list; // r11
  int v9; // r27
  int v10; // r6
  int v11; // r5
  idEventReceiver v12; // [sp+50h] [-70h] BYREF
  int v13; // [sp+60h] [-60h] BYREF
  idStr v14[2]; // [sp+70h] [-50h] BYREF

  v5 = idScenePoint_Combat::CastTo(c: (idScenePoint_Combat *)ai->aiVolatile.memory.curScenePoint);
  v6 = v5;
  if ( v5 == nullptr || v5->duration != 0.0 )
  {
    v14[0].len = 0;
    v14[0].baseBuffer[0] = 0;
    v14[0].allocedAndFlag = 20;
    v14[0].data = v14[0].baseBuffer;
    idAI2::GetIdleStateName(this: ai, name: v14);
    idAI2::ChangeAnimState(
      this: ai,
      web: AIANIMWEB_BODY,
      subWeb: ai->aiVolatile.animation.subWeb,
      stateName: v14[0].data,
      interruptPath: INTR_PATH_YES,
      interruptBlend: INTR_BLEND_NO,
      subWebIndex: nullptr,
      stateIndex: nullptr);
    idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
    if ( v6 != nullptr )
    {
      v7 = GameFramesToTicks(frameNum: 10, type: GAMETIME_SCALED);
      list = v6[1].targets.list;
      v9 = v7;
      if ( list != nullptr )
        (*(void (__fastcall **)(idEntityPtr<idEntity> *, idAI2 *, idEventReceiver *))(list->spawnId.value + 668))(
          a1: v6[1].targets.list,
          a2: ai,
          a3: &v12);
      else
        v12 = idScenePoint::GetScenePointPos(this: (idScenePoint *)&v13, result: v6)->idEventReceiver;
      idAIMoveState::StartLerpToPoint(
        this: &ai->aiVolatile.physics.moveState,
        dest: (const idVec3 *)&v12,
        tolerance: 0.1,
        maxLerpDist: 40.0,
        lerpDurationMS: v11,
        lerpAxisFlags_: v10,
        a7: v9,
        a8: 3);
    }
    idStr::FreeData(this: v14);
  }
}


// ========================================================================
// __unwind$490198
// EA  : 0x82ACC040
// RVA : 0x00ACC040
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490198()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// ?AIState_EnterState@idCombatScenePoint_EnterScenePoint@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACC068
// RVA : 0x00ACC068
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_EnterScenePoint::AIState_EnterState(
        idCombatScenePoint_EnterScenePoint *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idScenePoint_Combat *curScenePoint; // r31
  idScenePoint_Combat *v7; // r29
  idPhysics *Physics; // r3
  idQuat *v9; // r28
  idPhysics *v10; // r3
  int v11; // r3
  float v12; // r9
  float v13; // r11
  idVec3 v14; // [sp+50h] [-40h] BYREF

  curScenePoint = (idScenePoint_Combat *)ai->aiVolatile.memory.curScenePoint;
  v7 = idScenePoint_Combat::CastTo(c: curScenePoint);
  if ( v7 != nullptr )
  {
    Physics = idEntity::GetPhysics(this: curScenePoint);
    v9 = (idQuat *)Physics->GetAxis(this: Physics, a2: 0);
    v10 = idEntity::GetPhysics(this: curScenePoint);
    v11 = (int)v10->GetOrigin(this: v10, a2: 0);
    v12 = *(float *)(v11 + 4);
    v13 = *(float *)(v11 + 8);
    v14.x = *(float *)v11;
    v14.y = v12;
    v14.z = v13;
    idAI2::PlayAnimWebPathPerfect(
      this: ai,
      animPath: &v7->enterAnimSet.enterAnim,
      pos: &v14,
      axis: v9,
      forcedTransition: false,
      perfectDestination: true);
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?AIState_EnterState@idCombatScenePoint_TacticalCover@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACC130
// RVA : 0x00ACC130
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_TacticalCover::AIState_EnterState(
        idCombatScenePoint_TacticalCover *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  void (__fastcall *SetLeanState)(struct idAI2 *, const leanState_t); // r7
  idEventArg *v9; // r26
  _BYTE v10[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v11[5]; // [sp+90h] [-B0h] BYREF
  int v12; // [sp+B0h] [-90h]
  int v13; // [sp+B4h] [-8Ch]
  idEventArg v14; // [sp+D0h] [-70h] BYREF
  idEventReceiver v15[6]; // [sp+F0h] [-50h] BYREF

  if ( idScenePoint_Combat::CastTo(c: (idScenePoint_Combat *)ai->aiVolatile.memory.curScenePoint) != nullptr )
  {
    SetLeanState = ai->SetLeanState;
    ai->aiVolatile.animation.subWeb = AISUBWEB_FCOVER;
    SetLeanState(this: ai, a2: LEAN_NONE);
    ai->aiVolatile.fireControl->allowReloads = true;
    idAI2::SetCoverAction(this: ai, action: COVERACTION_NONE);
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    HIBYTE(v11[0]) = 105;
    v11[1] = 2;
    HIBYTE(v12) = 105;
    v13 = -1;
    v9 = idEventArg::idEventArg(this: &v14, data: ai);
    memcpy(Dst: v10, Src: v11, Size: sizeof(v10));
    idEventReceiver::ProcessEvent(
      this: v15,
      result: fsm,
      ev: *(const idEventDef **)&v9->type,
      arg1: (const idEventArg *)LODWORD(v9->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v9->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v12, 32));
    this->coverTime = curTime + 2000;
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?AIState_ExitState@idCombatScenePoint_StayAt@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACC258
// RVA : 0x00ACC258
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_StayAt::AIState_ExitState(
        idCombatScenePoint_TacticalCover *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  BOOL v8; // r8
  idAI2_vtbl *v9; // r11
  idEventArg *v10; // r3
  idEventArg v11; // [sp+50h] [-60h] BYREF
  idEventReceiver v12[5]; // [sp+70h] [-40h] BYREF

  if ( ai->aiVolatile.memory.curScenePoint == nullptr )
  {
    ai->aiVolatile.animation.subWeb = AISUBWEB_COMBAT;
    v8 = idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW);
    v9 = ai->__vftable;
    if ( v8 )
    {
      if ( v9->GetPosture(this: ai) == POSTURE_CROUCHED )
      {
        v10 = idEventArg::idEventArg(this: &v11, data: ai);
        idEventReceiver::ProcessEvent(
          this: v12,
          result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
          ev: *(const idEventDef **)&v10->type,
          arg1: (const idEventArg *)LODWORD(v10->value.v[1]));
        idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
      }
    }
    else
    {
      v9->SetPosture(this: ai, a2: POSTURE_STANDING);
    }
  }
}


// ========================================================================
// ?AIState_ExitState@idSearchScenePoint_MoveTo@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACC340
// RVA : 0x00ACC340
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idSearchScenePoint_MoveTo::AIState_ExitState(
        idCombatScenePoint_Close *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idStr v5; // [sp+50h] [-40h] BYREF

  v5.len = 0;
  v5.allocedAndFlag = 20;
  v5.data = v5.baseBuffer;
  v5.baseBuffer[0] = 0;
  idAI2::GetIdleStateName(this: ai, name: &v5);
  idAI2::ChangeAnimState(
    this: ai,
    web: AIANIMWEB_BODY,
    subWeb: ai->aiVolatile.animation.subWeb,
    stateName: v5.data,
    interruptPath: INTR_PATH_YES,
    interruptBlend: INTR_BLEND_NO,
    subWebIndex: nullptr,
    stateIndex: nullptr);
  idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
  idStr::FreeData(this: &v5);
}


// ========================================================================
// __unwind$490686_0
// EA  : 0x82ACC3DC
// RVA : 0x00ACC3DC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490686_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?AIState_ExitState@idCombatScenePoint_ApplyRestriction@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACC410
// RVA : 0x00ACC410
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_ApplyRestriction::AIState_ExitState(
        idCombatScenePoint_ApplyRestriction *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idStr v5[2]; // [sp+50h] [-40h] BYREF

  v5[0].len = 0;
  v5[0].allocedAndFlag = 20;
  v5[0].data = v5[0].baseBuffer;
  v5[0].baseBuffer[0] = 0;
  idAI2::GetIdleStateName(this: ai, name: v5);
  idAI2::ChangeAnimState(
    this: ai,
    web: AIANIMWEB_BODY,
    subWeb: ai->aiVolatile.animation.subWeb,
    stateName: v5[0].data,
    interruptPath: INTR_PATH_YES,
    interruptBlend: INTR_BLEND_NO,
    subWebIndex: nullptr,
    stateIndex: nullptr);
  idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
  ai->aiVolatile.memory.restrictionStopOnEnter = false;
  idStr::FreeData(this: v5);
}


// ========================================================================
// __unwind$490744
// EA  : 0x82ACC4A0
// RVA : 0x00ACC4A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490744()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ??0idCombatScenePointFSM@@QAA@XZ
// EA  : 0x82ACC4D0
// RVA : 0x00ACC4D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

idCombatScenePointFSM *__fastcall idCombatScenePointFSM::idCombatScenePointFSM(idCombatScenePointFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: "FSM_combatScenePoint");
  this->__vftable = (idCombatScenePointFSM_vtbl *)&idCombatScenePointFSM::`vftable';
  idState::idState(
    this: &this->stateCombatSPFind,
    stateType: &idCombatScenePoint_Find::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCombatSPFind.__vftable = (idCombatScenePoint_Find_vtbl *)&idCombatScenePoint_Find::`vftable';
  idState::idState(
    this: &this->stateCombatSPMoveTo,
    stateType: &idCombatScenePoint_MoveTo::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCombatSPMoveTo.__vftable = (idCombatScenePoint_MoveTo_vtbl *)&idCombatScenePoint_MoveTo::`vftable';
  idState::idState(
    this: &this->stateCombatSPStayAt,
    stateType: &idCombatScenePoint_StayAt::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCombatSPStayAt.__vftable = (idCombatScenePoint_StayAt_vtbl *)&idCombatScenePoint_StayAt::`vftable';
  idState::idState(
    this: &this->stateCombatSPEnter,
    stateType: &idCombatScenePoint_EnterScenePoint::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCombatSPEnter.__vftable = (idCombatScenePoint_EnterScenePoint_vtbl *)&idCombatScenePoint_EnterScenePoint::`vftable';
  idState::idState(
    this: &this->stateCombatSPTacticalAttack,
    stateType: &idCombatScenePoint_TacticalAttack::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCombatSPTacticalAttack.__vftable = (idCombatScenePoint_TacticalAttack_vtbl *)&idCombatScenePoint_TacticalAttack::`vftable';
  idState::idState(
    this: &this->stateCombatSPTacticalCover,
    stateType: &idCombatScenePoint_TacticalCover::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCombatSPTacticalCover.__vftable = (idCombatScenePoint_TacticalCover_vtbl *)&idCombatScenePoint_TacticalCover::`vftable';
  idState::idState(
    this: &this->stateCombatSPUseTurret,
    stateType: &idCombatScenePoint_UseTurret::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCombatSPUseTurret.__vftable = (idCombatScenePoint_UseTurret_vtbl *)&idCombatScenePoint_UseTurret::`vftable';
  idState::idState(
    this: &this->stateCombatSPClose,
    stateType: &idCombatScenePoint_Close::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCombatSPClose.__vftable = (idCombatScenePoint_Close_vtbl *)&idCombatScenePoint_Close::`vftable';
  idState::idState(
    this: &this->stateCombatSPIdle,
    stateType: &idCombatScenePoint_Idle::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCombatSPIdle.__vftable = (idCombatScenePoint_Idle_vtbl *)&idCombatScenePoint_Idle::`vftable';
  idState::idState(
    this: &this->stateCombatSPApplyRestriction,
    stateType: &idCombatScenePoint_ApplyRestriction::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCombatSPApplyRestriction.__vftable = (idCombatScenePoint_ApplyRestriction_vtbl *)&idCombatScenePoint_ApplyRestriction::`vftable';
  idState::idState(
    this: &this->stateCombatSPReload,
    stateType: &idCombatScenePoint_Reload::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCombatSPReload.__vftable = (idCombatScenePoint_Reload_vtbl *)&idCombatScenePoint_Reload::`vftable';
  idState::idState(
    this: &this->stateCombatSPMelee,
    stateType: &idCombatScenePoint_Melee::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCombatSPMelee.__vftable = (idCombatScenePoint_Melee_vtbl *)&idCombatScenePoint_Melee::`vftable';
  idState::idState(
    this: &this->stateCombatSPDodge,
    stateType: &idCombatScenePoint_Dodge::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCombatSPDodge.__vftable = (idCombatScenePoint_Dodge_vtbl *)&idCombatScenePoint_Dodge::`vftable';
  idState::idState(
    this: &this->stateCombatSPSharedWaitForAnimation,
    stateType: &idCombatScenePoint_SharedWaitForAnimation::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCombatSPSharedWaitForAnimation.__vftable = (idCombatScenePoint_SharedWaitForAnimation_vtbl *)&idCombatScenePoint_SharedWaitForAnimation::`vftable';
  idState::idState(
    this: &this->stateCombatSPSharedFinished,
    stateType: &idCombatScenePoint_SharedFinished::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCombatSPSharedFinished.__vftable = (idCombatScenePoint_SharedFinished_vtbl *)&idCombatScenePoint_SharedFinished::`vftable';
  idFiniteStateMachine::SetDefaultState(this, state: &this->stateCombatSPFind);
  this->stayTime = -1;
  return this;
}


// ========================================================================
// __unwind$490831
// EA  : 0x82ACC744
// RVA : 0x00ACC744
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490831()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$490832
// EA  : 0x82ACC76C
// RVA : 0x00ACC76C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490832()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$490833
// EA  : 0x82ACC798
// RVA : 0x00ACC798
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490833()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$490834
// EA  : 0x82ACC7C4
// RVA : 0x00ACC7C4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490834()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// __unwind$490835_0
// EA  : 0x82ACC7F0
// RVA : 0x00ACC7F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490835_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 192));
}


// ========================================================================
// __unwind$490836_0
// EA  : 0x82ACC81C
// RVA : 0x00ACC81C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490836_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 220));
}


// ========================================================================
// __unwind$490837
// EA  : 0x82ACC848
// RVA : 0x00ACC848
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490837()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 252));
}


// ========================================================================
// __unwind$490838
// EA  : 0x82ACC874
// RVA : 0x00ACC874
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490838()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 284));
}


// ========================================================================
// __unwind$490839
// EA  : 0x82ACC8A0
// RVA : 0x00ACC8A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490839()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 312));
}


// ========================================================================
// __unwind$490840
// EA  : 0x82ACC8CC
// RVA : 0x00ACC8CC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490840()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 340));
}


// ========================================================================
// __unwind$490841
// EA  : 0x82ACC8F8
// RVA : 0x00ACC8F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490841()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 368));
}


// ========================================================================
// __unwind$490842
// EA  : 0x82ACC924
// RVA : 0x00ACC924
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490842()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 396));
}


// ========================================================================
// __unwind$490843
// EA  : 0x82ACC950
// RVA : 0x00ACC950
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490843()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 424));
}


// ========================================================================
// __unwind$490844
// EA  : 0x82ACC97C
// RVA : 0x00ACC97C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490844()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 452));
}


// ========================================================================
// __unwind$490845
// EA  : 0x82ACC9A8
// RVA : 0x00ACC9A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490845()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 480));
}


// ========================================================================
// __unwind$490846
// EA  : 0x82ACC9D4
// RVA : 0x00ACC9D4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_490846()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 508));
}


// ========================================================================
// ??1idCombatScenePointFSM@@UAA@XZ
// EA  : 0x82ACCA08
// RVA : 0x00ACCA08
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePointFSM::~idCombatScenePointFSM(idCombatScenePointFSM *this)
{
  this->__vftable = (idCombatScenePointFSM_vtbl *)&idCombatScenePointFSM::`vftable';
  idState::~idState(this: &this->stateCombatSPSharedFinished);
  idState::~idState(this: &this->stateCombatSPSharedWaitForAnimation);
  idState::~idState(this: &this->stateCombatSPDodge);
  idState::~idState(this: &this->stateCombatSPMelee);
  idState::~idState(this: &this->stateCombatSPReload);
  idState::~idState(this: &this->stateCombatSPApplyRestriction);
  idState::~idState(this: &this->stateCombatSPIdle);
  idState::~idState(this: &this->stateCombatSPClose);
  idState::~idState(this: &this->stateCombatSPUseTurret);
  idState::~idState(this: &this->stateCombatSPTacticalCover);
  idState::~idState(this: &this->stateCombatSPTacticalAttack);
  idState::~idState(this: &this->stateCombatSPEnter);
  idState::~idState(this: &this->stateCombatSPStayAt);
  idState::~idState(this: &this->stateCombatSPMoveTo);
  idState::~idState(this: &this->stateCombatSPFind);
  idFiniteStateMachine::~idFiniteStateMachine(this);
}


// ========================================================================
// __unwind$491107
// EA  : 0x82ACCACC
// RVA : 0x00ACCACC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_491107()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$491108
// EA  : 0x82ACCAF4
// RVA : 0x00ACCAF4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_491108()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// __unwind$491109
// EA  : 0x82ACCB20
// RVA : 0x00ACCB20
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_491109()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$491110
// EA  : 0x82ACCB4C
// RVA : 0x00ACCB4C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_491110()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// __unwind$491111
// EA  : 0x82ACCB78
// RVA : 0x00ACCB78
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_491111()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 192));
}


// ========================================================================
// __unwind$491112
// EA  : 0x82ACCBA4
// RVA : 0x00ACCBA4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_491112()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 220));
}


// ========================================================================
// __unwind$491113
// EA  : 0x82ACCBD0
// RVA : 0x00ACCBD0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_491113()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 252));
}


// ========================================================================
// __unwind$491114
// EA  : 0x82ACCBFC
// RVA : 0x00ACCBFC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_491114()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 284));
}


// ========================================================================
// __unwind$491115
// EA  : 0x82ACCC28
// RVA : 0x00ACCC28
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_491115()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 312));
}


// ========================================================================
// __unwind$491116
// EA  : 0x82ACCC54
// RVA : 0x00ACCC54
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_491116()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 340));
}


// ========================================================================
// __unwind$491117
// EA  : 0x82ACCC80
// RVA : 0x00ACCC80
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_491117()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 368));
}


// ========================================================================
// __unwind$491118
// EA  : 0x82ACCCAC
// RVA : 0x00ACCCAC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_491118()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 396));
}


// ========================================================================
// __unwind$491119
// EA  : 0x82ACCCD8
// RVA : 0x00ACCCD8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_491119()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 424));
}


// ========================================================================
// __unwind$491120
// EA  : 0x82ACCD04
// RVA : 0x00ACCD04
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_491120()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 452));
}


// ========================================================================
// __unwind$491121
// EA  : 0x82ACCD30
// RVA : 0x00ACCD30
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_491121()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 480));
}


// ========================================================================
// ?Evaluate@CombatScenePoint_Shall_FindScenePoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ACCD60
// RVA : 0x00ACCD60
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall CombatScenePoint_Shall_FindScenePoint::Evaluate(
        CombatScenePoint_Shall_FindScenePoint *this,
        idAI2 *ai,
        idCombatScenePointFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  const aiSenseState_t *EnemySenseState; // r3
  int lastConfirmedStimTime; // r11
  idScenePoint_Combat *v10; // r3
  idScenePoint *v11; // r31
  idAIStateTransition::aiTransCode_t result; // r3
  idScenePoint **p_curScenePoint; // r19
  idScenePoint_Combat *v14; // r3
  double coverTargetTimeout; // fp31
  idScenePoint_Combat *v16; // r27
  const aiSenseState_t *v17; // r31
  int v18; // r31
  bool v19; // r21
  scenePointArcSector_t ArcSector; // r22
  idCombatScenePointFSM *v21; // r23
  bool v22; // r3
  int v23; // r31
  int stayTime; // r11
  double v25; // fp31
  const aiSenseState_t *v26; // r29
  int GameMs; // r3
  float x; // r8
  float y; // r7
  int v30; // r6
  int v31; // r11
  idAIMemory *p_memory; // r3
  const idAnimWebPath *ExitAnimation; // r4
  int lastScenePointSearchTime; // r11
  char v35; // r11
  bool v36; // zf
  idVec3 v37; // [sp+60h] [-90h] BYREF
  int v38; // [sp+6Ch] [-84h]

  if ( !ai->aiEditable.actionSettings.cover.usesCombatScenePoints )
    return 0;
  if ( ai->aiEditable.perception.combatTimeoutInterval >= 0.0 )
  {
    EnemySenseState = idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
    if ( EnemySenseState != nullptr )
    {
      lastConfirmedStimTime = EnemySenseState->lastConfirmedStimTime;
      if ( lastConfirmedStimTime > 0
        && curTime - lastConfirmedStimTime > (int)(float)(ai->aiEditable.perception.combatTimeoutInterval * 1000.0) )
      {
        v10 = idScenePoint_Combat::CastTo(c: (idScenePoint_Combat *)ai->aiVolatile.memory.curScenePoint);
        v11 = v10;
        if ( v10 != nullptr )
        {
          idAIMemory::UpdateScenePointHistory(this: &ai->aiVolatile.memory, scenePoint: v10);
          idScenePoint::ReleaseScenePoint(this: v11, user: ai);
          ai->aiVolatile.memory.curScenePoint = nullptr;
          return 0;
        }
        return 0;
      }
    }
  }
  p_curScenePoint = &ai->aiVolatile.memory.curScenePoint;
  v14 = idScenePoint_Combat::CastTo(c: (idScenePoint_Combat *)ai->aiVolatile.memory.curScenePoint);
  coverTargetTimeout = ai->aiEditable.actionSettings.cover.coverTargetTimeout;
  v16 = v14;
  if ( coverTargetTimeout > 0.0 )
  {
    v17 = idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
    if ( v17 != nullptr
      && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
       - v17->lastConfirmedStimTime >= (int)(float)(1000.0 * (float)coverTargetTimeout) )
    {
      if ( v16 != nullptr )
      {
        idAIMemory::UpdateScenePointHistory(this: &ai->aiVolatile.memory, scenePoint: v16);
        idScenePoint::ReleaseScenePoint(this: v16, user: ai);
        *p_curScenePoint = nullptr;
        return 0;
      }
      return 0;
    }
  }
  if ( v16 != nullptr )
  {
    v18 = 1;
    v19 = false;
    ArcSector = ARC_SECTOR_INVALID;
    v21 = idCombatScenePointFSM::CastTo(c: parentFSM);
    if ( (v16->scriptFlags & 1) != 0 )
    {
      v22 = IsScriptScenePointValid(ai, scriptScenePoint: v16);
      LOBYTE(v23) = v22;
      v19 = (_cntlzw(v22) & 0x20) != 0;
      if ( v22 && v21 != nullptr && v16->duration >= 0.0 )
      {
        stayTime = v21->stayTime;
        if ( stayTime >= 0 )
          LOBYTE(v23) = !__CFADD__(stayTime - curTime, curTime ^ 0x80000000) && v22;
      }
      if ( (_BYTE)v23 != 0 )
        LOBYTE(v23) = (*(_BYTE *)&v16->flags & 8) == 0 ? 0 : v23;
      if ( (_BYTE)v23 != 0
        && (unsigned __int8)idAIMemory::HasOverrideScriptScenePointOfType(
                              this: &ai->aiVolatile.memory,
                              spType: (scenePointType_t)4) != 0 )
      {
        LOBYTE(v23) = 0;
      }
    }
    else
    {
      v25 = ai->aiEditable.actionSettings.cover.coverTargetTimeout;
      if ( v25 > 0.0 )
      {
        v26 = idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
        if ( v26 != nullptr )
        {
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v18 = ((__PAIR64__((unsigned int)(int)(float)(1000.0 * (float)v25) >> 31, GameMs - v26->lastConfirmedStimTime)
                - __PAIR64__(
                    (unsigned int)(GameMs - v26->lastConfirmedStimTime) >> 31,
                    (int)(float)(1000.0 * (float)v25))) >> 32)
              & 1;
        }
      }
      x = ai->aiVolatile.memory.currentEnemySuspectedPos.pos.x;
      y = ai->aiVolatile.memory.currentEnemySuspectedPos.pos.y;
      v30 = *(_DWORD *)&ai->aiVolatile.memory.currentEnemySuspectedPos.bValid;
      v37.z = ai->aiVolatile.memory.currentEnemySuspectedPos.pos.z;
      v37.x = x;
      v37.y = y;
      v38 = v30;
      v23 = HIBYTE(v30) == 0 ? 0 : v18;
      if ( (_BYTE)v23 != 0 && !v16->IsInArc_2(this: v16, a2: &v37) )
      {
        if ( v21->stayTime >= 0 )
          ArcSector = idScenePoint_Arc::GetArcSector(this: v16, point: &v37);
        v23 = 0;
      }
      if ( (_BYTE)v23 != 0 && v21 != nullptr && v16->duration >= 0.0 )
      {
        v31 = v21->stayTime;
        if ( v31 >= 0 && curTime > v31 )
        {
          ArcSector = idScenePoint_Arc::GetArcSector(this: v16, point: &v37);
          v23 = 0;
        }
      }
      if ( (_BYTE)v23 != 0 )
        v23 = (*(_BYTE *)&v16->flags & 8) == 0 ? 0 : v23;
      if ( (_BYTE)v23 != 0 )
        v23 = (unsigned __int8)idAIMemory::CheckIfDirtyScenePoint(this: &ai->aiVolatile.memory, dirtyScenePoint: v16) != 0
            ? 0
            : v23;
      if ( (_BYTE)v23 != 0 )
        v23 = !idScenePoint::RequestScenePoint(this: v16, user: ai, curTime) ? 0 : v23;
      if ( (_BYTE)v23 != 0 )
        v23 = (unsigned __int8)idAIMemory::HasOverrideScriptScenePointOfType(
                                 this: &ai->aiVolatile.memory,
                                 spType: (scenePointType_t)4) != 0
            ? 0
            : v23;
    }
    if ( (_BYTE)v23 == 0 )
    {
      if ( v21 != nullptr )
        v21->stayTime = -1;
      p_memory = &ai->aiVolatile.memory;
      if ( v19 )
        idAIMemory::ClearScenePointHistory(this: p_memory);
      else
        idAIMemory::UpdateScenePointHistory(this: p_memory, scenePoint: v16);
      idScenePoint::ReleaseScenePoint(this: v16, user: ai);
      *p_curScenePoint = nullptr;
      if ( ArcSector != ARC_SECTOR_INVALID )
      {
        ExitAnimation = idScenePoint_Combat::GetExitAnimation(this: v16, arcSector: ArcSector);
        if ( ExitAnimation->len != 0
          && idAI2::PlayAnimWebPath(this: ai, animPath: ExitAnimation, forceTransition: false) == 1 )
        {
          return TRANSCODE_ALTERNATIVE_2;
        }
      }
      return TRANSCODE_ALTERNATIVE_1;
    }
    return 0;
  }
  if ( (unsigned __int8)idAIMemory::HasOverrideScriptScenePointOfType(
                          this: &ai->aiVolatile.memory,
                          spType: (scenePointType_t)4) != 0 )
    return TRANSCODE_ALTERNATIVE_1;
  if ( ai->aiVolatile.memory.scenePointVolumes.num <= 0 )
    return 0;
  lastScenePointSearchTime = ai->aiVolatile.memory.lastScenePointSearchTime;
  if ( lastScenePointSearchTime == 0 || (v36 = curTime <= lastScenePointSearchTime + 2000, v35 = 0, !v36) )
    v35 = 1;
  result = TRANSCODE_ALTERNATIVE_1;
  if ( v35 == 0 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@CombatScenePoint_Shall_StayAtScenePoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ACD2D8
// RVA : 0x00ACD2D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

int __fastcall CombatScenePoint_Shall_StayAtScenePoint::Evaluate(
        CombatScenePoint_Shall_StayAtScenePoint *this,
        idAI2 *ai,
        idCombatScenePointFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idScenePoint **p_curScenePoint; // r27
  idScenePoint_Combat *v9; // r29
  int v10; // r3
  idCombatScenePointFSM *v11; // r3
  idStr v13[3]; // [sp+60h] [-60h] BYREF

  p_curScenePoint = &ai->aiVolatile.memory.curScenePoint;
  v9 = idScenePoint_Combat::CastTo(c: (idScenePoint_Combat *)ai->aiVolatile.memory.curScenePoint);
  if ( v9 == nullptr )
    return 0;
  v10 = ai->aiVolatile.physics.moveState.GetMoveStatus(this: &ai->aiVolatile.physics.moveState);
  if ( v10 != 0 )
  {
    if ( v10 != 1 )
    {
      idLib::Warning(fmt: "%s is for some reason unreachable, disabling it for 10 seconds.", v9->name.data);
      v9->currentUser = nullptr;
      v9->requestTime = curTime - (int)(float)((float)1000.0 * (float)-10.0);
      v13[0].allocedAndFlag = 20;
      *p_curScenePoint = nullptr;
      v13[0].data = v13[0].baseBuffer;
      v13[0].len = 0;
      v13[0].baseBuffer[0] = 0;
      idAI2::GetIdleStateName(this: ai, name: v13);
      idAI2::ChangeAnimState(
        this: ai,
        web: AIANIMWEB_BODY,
        subWeb: ai->aiVolatile.animation.subWeb,
        stateName: v13[0].data,
        interruptPath: INTR_PATH_YES,
        interruptBlend: INTR_BLEND_NO,
        subWebIndex: nullptr,
        stateIndex: nullptr);
      idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
      idStr::FreeData(this: v13);
    }
    return 0;
  }
  v11 = idCombatScenePointFSM::CastTo(c: parentFSM);
  if ( v9->enterAnimSet.enterAnim.len != 0 && v11 != nullptr && v11->enterValid )
    return 454;
  else
    return 453;
}


// ========================================================================
// __unwind$492159
// EA  : 0x82ACD424
// RVA : 0x00ACD424
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_492159()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?Evaluate@CombatScenePoint_Shall_Enter_Turret@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ACD458
// RVA : 0x00ACD458
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

int __fastcall CombatScenePoint_Shall_Enter_Turret::Evaluate(
        CombatScenePoint_Shall_Enter_Turret *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idScenePoint **p_curScenePoint; // r27
  idScenePoint_Combat *v8; // r3
  int v9; // r3
  idScenePoint *v11; // r30
  char *data; // r4
  const char *v13; // r5
  idStr v14[3]; // [sp+60h] [-60h] BYREF

  p_curScenePoint = &ai->aiVolatile.memory.curScenePoint;
  v8 = idScenePoint_Combat::CastTo(c: (idScenePoint_Combat *)ai->aiVolatile.memory.curScenePoint);
  if ( v8 != nullptr && v8->scenePointTurret != nullptr )
  {
    v9 = ai->aiVolatile.physics.moveState.GetMoveStatus(this: &ai->aiVolatile.physics.moveState);
    if ( v9 == 0 )
      return 456;
    if ( v9 != 1 )
    {
      v11 = *p_curScenePoint;
      if ( *p_curScenePoint != nullptr )
      {
        data = v11->name.data;
        v13 = aiMoveStatusNames[v9];
        if ( (v11->scriptFlags & 1) != 0 )
          idLib::Warning(fmt: "SCRIPT SCENEPOINT: %s is unreachable! Status: %s Should not happen. Ever! ", data, v13);
        else
          idLib::Warning(fmt: "SCENEPOINT: %s is unreachable. Disabling it for 10 secs. Status: %s ", data, v13);
        v11->currentUser = nullptr;
        v11->requestTime = curTime - (int)(float)((float)1000.0 * (float)-10.0);
        *p_curScenePoint = nullptr;
      }
      v14[0].len = 0;
      v14[0].baseBuffer[0] = 0;
      v14[0].allocedAndFlag = 20;
      v14[0].data = v14[0].baseBuffer;
      idAI2::GetIdleStateName(this: ai, name: v14);
      idAI2::ChangeAnimState(
        this: ai,
        web: AIANIMWEB_BODY,
        subWeb: ai->aiVolatile.animation.subWeb,
        stateName: v14[0].data,
        interruptPath: INTR_PATH_YES,
        interruptBlend: INTR_BLEND_NO,
        subWebIndex: nullptr,
        stateIndex: nullptr);
      idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
      idStr::FreeData(this: v14);
    }
  }
  return 0;
}


// ========================================================================
// __unwind$492273
// EA  : 0x82ACD5B0
// RVA : 0x00ACD5B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_492273()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// GetBestCoverAction
// EA  : 0x82ACD680
// RVA : 0x00ACD680
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall GetBestCoverAction(idAI2 *ai, idScenePoint_Combat *curScenePoint)
{
  int v4; // r27
  int value; // r8
  idEntity *v6; // r3
  scenePointTacFlags_t tacFlags; // r24
  float y; // r8
  float z; // r7
  int v10; // r6
  bool v11; // r26
  int v12; // r25
  const aiSenseState_t *EnemySenseState; // r30
  int v14; // r2 OVERLAPPED
  unsigned int v15; // r23
  int GameMs; // r3
  int v17; // r3
  char v18; // r8
  __int64 v19; // r10
  unsigned int v20; // r4
  __int64 v22; // r4
  unsigned int v23; // r5
  int v24; // r3
  __int64 v25; // r10
  unsigned int v26; // r4
  __int64 v27; // r4
  unsigned int v28; // r5
  int v29; // r3
  idVec3 v30; // [sp+60h] [-60h] BYREF
  int v31; // [sp+6Ch] [-54h]

  v4 = 0;
  if ( ai == nullptr )
    return 0;
  if ( curScenePoint == nullptr )
    return 0;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v6 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v6 == nullptr || idEntity::CastTo(c: v6) == nullptr )
    return 0;
  tacFlags = curScenePoint->tacFlags;
  y = ai->aiVolatile.memory.currentEnemySuspectedPos.pos.y;
  z = ai->aiVolatile.memory.currentEnemySuspectedPos.pos.z;
  v10 = *(_DWORD *)&ai->aiVolatile.memory.currentEnemySuspectedPos.bValid;
  v30.x = ai->aiVolatile.memory.currentEnemySuspectedPos.pos.x;
  v30.y = y;
  v30.z = z;
  v31 = v10;
  v11 = idEntity::IsToLeft(this: ai, pos: &v30);
  LOBYTE(v12) = 1;
  EnemySenseState = idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  if ( EnemySenseState != nullptr )
  {
    v15 = (int)(float)((float)1000.0 * (float)6.6599998);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v12 = ((__PAIR64__(v15 >> 31, GameMs - EnemySenseState->lastConfirmedStimTime)
          - __PAIR64__((unsigned int)(GameMs - EnemySenseState->lastConfirmedStimTime) >> 31, v15)) >> 32)
        & 1;
  }
  if ( (tacFlags & 0x1000) == 0
    || (v17 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED),
        v18 = 1,
        v17 - ai->aiVolatile.memory.lastFiredAtTime >= 500) )
  {
    v18 = 0;
  }
  if ( v11 )
  {
    if ( (tacFlags & 0x20) != 0 )
    {
      if ( (tacFlags & 0x80) != 0 )
      {
        if ( v18 != 0 )
        {
          HIDWORD(v19) = "Could not find AI state, idVS_ds_Car_Chase! ";
          v20 = 1664525 * clientGame->random.seed + 1013904223;
          clientGame->random.seed = v20;
          LODWORD(v19) = (v20 >> 10) & 0x7FFF;
          if ( (float)((float)v19 * (float)0.000030518509) <= 0.5 )
            return 7;
          return 6;
        }
        v4 = 2;
        HIDWORD(v22) = 1664525 * clientGame->random.seed;
        clientGame->random.seed = HIDWORD(v22) + 1013904223;
        LODWORD(v22) = ((unsigned int)(HIDWORD(v22) + 1013904223) >> 10) & 0x7FFF;
        if ( (float)((float)v22 * (float)0.000030518509) > 0.5 )
          v4 = 1;
        if ( (_BYTE)v12 == 0 )
        {
          v23 = 1664525 * clientGame->random.seed + 1013904223;
          clientGame->random.seed = v23;
          v24 = (v23 >> 10) & 0x7FFF;
          if ( (float)((float)*(__int64 *)(&v14 - 1) * (float)0.000030518509) <= 0.5 )
            return 10;
          return 9;
        }
        return v4;
      }
      if ( (tacFlags & 0x20) != 0 )
      {
        if ( v18 != 0 )
          return 7;
        v4 = 2;
        if ( (_BYTE)v12 == 0 )
          return 10;
        return v4;
      }
    }
    if ( (tacFlags & 0x80) != 0 )
    {
      if ( v18 == 0 )
        goto LABEL_29;
      return 6;
    }
    if ( (tacFlags & 0x40) == 0 )
      return v4;
    if ( v18 != 0 )
      return 8;
LABEL_35:
    v4 = 3;
    if ( (_BYTE)v12 == 0 )
      return 11;
    return v4;
  }
  if ( (tacFlags & 0x40) != 0 )
  {
    if ( (tacFlags & 0x80) != 0 )
    {
      if ( v18 != 0 )
      {
        HIDWORD(v25) = "Could not find AI state, idVS_ds_Car_Chase! ";
        v26 = 1664525 * clientGame->random.seed + 1013904223;
        clientGame->random.seed = v26;
        LODWORD(v25) = (v26 >> 10) & 0x7FFF;
        if ( (float)((float)v25 * (float)0.000030518509) > 0.5 )
          return 6;
        return 8;
      }
      else
      {
        v4 = 3;
        HIDWORD(v27) = 1664525 * clientGame->random.seed;
        clientGame->random.seed = HIDWORD(v27) + 1013904223;
        LODWORD(v27) = ((unsigned int)(HIDWORD(v27) + 1013904223) >> 10) & 0x7FFF;
        if ( (float)((float)v27 * (float)0.000030518509) > 0.5 )
          v4 = 1;
        if ( (_BYTE)v12 != 0 )
          return v4;
        v28 = 1664525 * clientGame->random.seed + 1013904223;
        clientGame->random.seed = v28;
        v29 = (v28 >> 10) & 0x7FFF;
        if ( (float)((float)*(__int64 *)(&v14 - 1) * (float)0.000030518509) > 0.5 )
          return 9;
        return 11;
      }
    }
    if ( (tacFlags & 0x40) != 0 )
    {
      if ( v18 != 0 )
        return 8;
      goto LABEL_35;
    }
  }
  if ( (tacFlags & 0x80) != 0 )
  {
    if ( v18 == 0 )
    {
LABEL_29:
      v4 = 1;
      if ( (_BYTE)v12 == 0 )
        return 9;
      return v4;
    }
    return 6;
  }
  else
  {
    if ( (tacFlags & 0x20) != 0 )
    {
      if ( v18 != 0 )
        return 7;
      v4 = 2;
      if ( (_BYTE)v12 == 0 )
        return 10;
    }
    return v4;
  }
}


// ========================================================================
// ?Evaluate@CombatScenePoint_Shall_Melee@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ACDBD8
// RVA : 0x00ACDBD8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall CombatScenePoint_Shall_Melee::Evaluate(
        CombatScenePoint_Shall_Melee *this,
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
  int v12; // r9
  idAIStateTransition::aiTransCode_t result; // r3

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v7 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr )
    return 0;
  v8 = idEntity::CastTo(c: v7);
  if ( v8 == nullptr )
    return 0;
  v9 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8);
  if ( v9 == nullptr )
    return 0;
  v10 = v9->senses.ptr[v9->lastSense];
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v10);
  if ( (unsigned __int8)idAI2::IsTargetInMeleeRange(
                          this: ai,
                          targetPos: &ConfirmedPhysicalSafe->origin,
                          meleeType: AIMELEE_ALL) == 0 )
    return 0;
  v12 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
      - v10->lastConfirmedStimTime;
  result = TRANSCODE_MAX;
  if ( v12 >= 1000 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@CombatScenePoint_Shall_Dodge@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ACDCD0
// RVA : 0x00ACDCD0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall CombatScenePoint_Shall_Dodge::Evaluate(
        CombatScenePoint_Shall_Dodge *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  dodgeFlags_t dodgeFlags; // r28
  int value; // r8
  idEntity *v9; // r3
  idEntity *v10; // r3
  idEntity *v11; // r30
  idPhysics *Physics; // r3
  float *v13; // r27
  idPhysics *v14; // r3
  float *v15; // r3
  double v16; // fp8
  double v17; // fp4
  double v18; // fp12
  idAIStateTransition::aiTransCode_t result; // r3
  bool v20; // zf

  if ( ai->aiVolatile.memory.nextDodgeTime > curTime )
    return 0;
  dodgeFlags = ai->aiEditable.actionSettings.dodge.dodgeFlags;
  if ( (dodgeFlags & 0x18) == 0 )
    return 0;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v9 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v9 == nullptr )
    return 0;
  v10 = idEntity::CastTo(c: v9);
  v11 = v10;
  if ( v10 == nullptr )
    return 0;
  Physics = idEntity::GetPhysics(this: v10);
  v13 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v14 = idEntity::GetPhysics(this: ai);
  v15 = (float *)v14->GetOrigin(this: v14, a2: 0);
  v16 = (float)(v13[1] - v15[1]);
  v17 = (float)(v13[2] - v15[2]);
  v18 = (float)((float)((float)v17 * (float)v17)
              + (float)((float)((float)(*v13 - *v15) * (float)(*v13 - *v15)) + (float)((float)v16 * (float)v16)));
  if ( v18 < (float)(ai->aiEditable.actionSettings.dodge.dodgeMinRange
                   * ai->aiEditable.actionSettings.dodge.dodgeMinRange)
    || ai->aiEditable.actionSettings.dodge.dodgeMaxRange >= 0.0
    && v18 > (float)(ai->aiEditable.actionSettings.dodge.dodgeMaxRange
                   * ai->aiEditable.actionSettings.dodge.dodgeMaxRange) )
  {
    return 0;
  }
  if ( (dodgeFlags & 1) != 0 && curTime - ai->aiVolatile.memory.lastAimedAtTime < 500
    || (dodgeFlags & 2) != 0 && curTime - ai->aiVolatile.memory.lastFiredAtTime < 500 )
  {
    return TRANSCODE_MAX;
  }
  if ( (dodgeFlags & 4) == 0 )
    return 0;
  v20 = (unsigned __int8)idAI2::IsBlockedByFriendly(this: ai, _pEnemy: v11) != 0;
  result = TRANSCODE_MAX;
  if ( !v20 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@CombatScenePoint_Shared_Finished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ACDE80
// RVA : 0x00ACDE80
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

int __fastcall CombatScenePoint_Shared_Finished::Evaluate(
        CombatScenePoint_Shared_Finished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  idScenePoint *curScenePoint; // r3
  idVolume_Restriction *v8; // r30
  idPhysics *Physics; // r3
  const idVec3 *v10; // r3
  idEntityPtr<idVolume_Restriction> v11; // [sp+50h] [-20h] BYREF

  curScenePoint = ai->aiVolatile.memory.curScenePoint;
  if ( curScenePoint != nullptr )
    idScenePoint::RequestScenePoint(this: curScenePoint, user: ai, curTime);
  if ( idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW)
    && (ai->aiVolatile.physics.moveState.GetMoveStatus(this: &ai->aiVolatile.physics.moveState) != 1
     || ai->aiVolatile.memory.restrictionStopOnEnter
     && idAIMemory::HasRestrictionVolume(this: &ai->aiVolatile.memory)
     && (v11.spawnId.value = ai->aiVolatile.memory.restrictionVolume.spawnId.value,
         v8 = idEntityPtr<idVolume_Restriction>::operator idVolume_Restriction *(this: &v11),
         Physics = idEntity::GetPhysics(this: ai),
         v10 = Physics->GetOrigin(this: Physics, a2: 0),
         idVolume_ItemGroup::Contains(this: v8, pos: v10))) )
  {
    return 456;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?AIState_EnterState@idCombatScenePoint_StayAt@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACDF88
// RVA : 0x00ACDF88
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_StayAt::AIState_EnterState(
        idCombatScenePoint_StayAt *this,
        idAI2 *ai,
        idCombatScenePointFSM *fsm,
        int curTime)
{
  idScenePoint_Combat *v8; // r29
  idCombatScenePointFSM *v9; // r30
  int v10; // r11
  int value; // r8
  idEntity *v12; // r3
  idEntity *v13; // r4
  scenePointScriptFlags_t scriptFlags; // r10
  BOOL v15; // r30
  char v16; // r11
  idAI2 *v17; // r4
  idAIFireControl *fireControl; // r3
  aiFireMode_t v19; // r5
  idEventArg *v20; // r24
  scenePointTacFlags_t tacFlags; // r10
  char v22; // r11
  double v23; // r10
  unsigned int v24; // r3
  idEventArg *v25; // r3
  _BYTE v26[20]; // [sp+70h] [-F0h] BYREF
  double v27; // [sp+90h] [-D0h]
  _DWORD v28[5]; // [sp+A0h] [-C0h] BYREF
  int v29; // [sp+C0h] [-A0h]
  int v30; // [sp+C4h] [-9Ch]
  idEventArg v31; // [sp+E0h] [-80h] BYREF
  idEventArg v32[4]; // [sp+100h] [-60h] BYREF

  v8 = idScenePoint_Combat::CastTo(c: (idScenePoint_Combat *)ai->aiVolatile.memory.curScenePoint);
  if ( v8 == nullptr )
  {
    idState::SetEnterFailed(this, failed: true);
    return;
  }
  v9 = idCombatScenePointFSM::CastTo(c: fsm);
  if ( v9->stayTime == -1 )
  {
    idScenePoint::ActivateScenePoint(this: v8, user: ai, curTime);
    LODWORD(v27) = (int)(float)(v8->duration * 1000.0);
    v10 = LODWORD(v27) + curTime;
    if ( SLODWORD(v27) < 0 )
      v10 = 666;
    v9->stayTime = v10;
  }
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v12 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v12 != nullptr )
    {
      v13 = idEntity::CastTo(c: v12);
      if ( v13 != nullptr )
      {
        scriptFlags = v8->scriptFlags;
        if ( (scriptFlags & 1) != 0 )
        {
          v15 = (v8->scriptFlags & 8) != 0;
          if ( (scriptFlags & 8) != 0 || (v16 = 0, (scriptFlags & 4) != 0) )
            v16 = 1;
          if ( v16 == 0 )
          {
            idAI2::ClearAimFocus(this: ai);
            v19 = FIREMODE_HOLDFIRE;
            v17 = ai;
            fireControl = ai->aiVolatile.fireControl;
            goto LABEL_20;
          }
          idAI2::SetAimFocusEntity(
            this: ai,
            ent: v13,
            keepFocusInView: (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 4) != 0,
            aimPoint: AIMPOINT_BEST,
            timeout: -1);
          v17 = ai;
          fireControl = ai->aiVolatile.fireControl;
          if ( !v15 )
          {
            v19 = FIREMODE_HOLDFIRE;
LABEL_20:
            idAIFireControl::SetFireMode(this: fireControl, owner: v17, mode: v19);
            goto LABEL_21;
          }
        }
        else
        {
          idAI2::SetAimFocusEntity(
            this: ai,
            ent: v13,
            keepFocusInView: (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 4) != 0,
            aimPoint: AIMPOINT_BEST,
            timeout: -1);
          v17 = ai;
          fireControl = ai->aiVolatile.fireControl;
        }
        v19 = FIREMODE_FIREWHENREADY;
        goto LABEL_20;
      }
    }
  }
LABEL_21:
  if ( v8->customSet.customCoverSet.len != 0 )
  {
    if ( idAI2::PlayAnimWebPath(this: ai, animPath: &v8->customSet.customCoverSet, forceTransition: false) != 1 )
    {
      idLib::Warning(fmt: "ScenePoint %s's custom cover set was not activatable by AI %s", v8->name.data, ai->name.data);
      v8->currentUser = nullptr;
      v8->requestTime = curTime - (int)(float)(1000.0 * (float)-30.0);
    }
  }
  else
  {
    if ( idScenePoint_Combat::IsTactical(this: v8) )
    {
      ai->aiVolatile.animation.subWeb = AISUBWEB_FCOVER;
    }
    else if ( v8->duration != 0.0 )
    {
      idAI2::EndActionScript(this: ai);
      fsm->actionCallerState = this;
      HIBYTE(v28[0]) = 105;
      HIBYTE(v29) = 105;
      v28[1] = 1;
      v30 = -1;
      v20 = idEventArg::idEventArg(this: &v31, data: ai);
      memcpy(Dst: v26, Src: v28, Size: sizeof(v26));
      idEventReceiver::ProcessEvent(
        this: (idEventReceiver *)v32,
        result: (idEventArg *)fsm,
        ev: *(const idEventDef **)&v20->type,
        arg1: (const idEventArg *)LODWORD(v20->value.v[1]),
        arg2: (const idEventArg *)LODWORD(v20->value.v[2]),
        arg3: (const idEventArg *)__ROL4__(v29, 32));
    }
    tacFlags = v8->tacFlags;
    v22 = 0;
    if ( (tacFlags & 2) != 0 )
    {
      if ( (tacFlags & 1) != 0 )
      {
        HIDWORD(v23) = "Could not find AI state, idVS_ds_Car_Chase! ";
        v24 = 1664525 * clientGame->random.seed + 1013904223;
        clientGame->random.seed = v24;
        LODWORD(v23) = (v24 >> 10) & 0x7FFF;
        v27 = v23;
      }
      v22 = 1;
    }
    if ( v22 != 0 )
    {
      v25 = idEventArg::idEventArg(this: v32, data: ai);
      idEventReceiver::ProcessEvent(
        this: (idEventReceiver *)&v31,
        result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
        ev: *(const idEventDef **)&v25->type,
        arg1: (const idEventArg *)LODWORD(v25->value.v[1]));
      idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
    }
  }
}


// ========================================================================
// ?AIState_EnterState@idCombatScenePoint_TacticalAttack@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACE360
// RVA : 0x00ACE360
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_TacticalAttack::AIState_EnterState(
        idCombatScenePoint_TacticalAttack *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idScenePoint_Combat *v8; // r4
  coverAction_t BestCoverAction; // r3
  coverAction_t v10; // r30
  idEventArg *v11; // r25
  _BYTE v12[20]; // [sp+70h] [-E0h] BYREF
  _DWORD v13[5]; // [sp+90h] [-C0h] BYREF
  int v14; // [sp+B0h] [-A0h]
  coverAction_t v15; // [sp+B4h] [-9Ch]
  idEventArg v16; // [sp+D0h] [-80h] BYREF
  idEventReceiver v17[8]; // [sp+F0h] [-60h] BYREF

  v8 = idScenePoint_Combat::CastTo(c: (idScenePoint_Combat *)ai->aiVolatile.memory.curScenePoint);
  if ( v8 != nullptr
    && (BestCoverAction = GetBestCoverAction(ai, curScenePoint: v8),
        v10 = BestCoverAction,
        BestCoverAction != COVERACTION_NONE) )
  {
    idAI2::SetCoverAction(this: ai, action: BestCoverAction);
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    v15 = v10;
    HIBYTE(v13[0]) = 105;
    v13[1] = 5000;
    HIBYTE(v14) = 105;
    v11 = idEventArg::idEventArg(this: &v16, data: ai);
    memcpy(Dst: v12, Src: v13, Size: sizeof(v12));
    idEventReceiver::ProcessEvent(
      this: v17,
      result: fsm,
      ev: *(const idEventDef **)&v11->type,
      arg1: (const idEventArg *)LODWORD(v11->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v11->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v14, 32));
    this->attackTime = curTime + 5000;
    idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?AIState_EnterState@idCombatScenePoint_UseTurret@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACE478
// RVA : 0x00ACE478
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_UseTurret::AIState_EnterState(
        idCombatScenePoint_UseTurret *this,
        idAI2 *ai,
        idCombatScenePointFSM *fsm,
        int curTime)
{
  idScenePoint_Combat *v8; // r30
  idCombatScenePointFSM *v9; // r28
  int v10; // r11
  int value; // r8
  idEntity *v12; // r3
  idEntity *v13; // r4
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v14; // [sp+50h] [-40h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v15; // [sp+52h] [-3Eh] BYREF
  int v17; // [sp+5Ch] [-34h]

  v8 = idScenePoint_Combat::CastTo(c: (idScenePoint_Combat *)ai->aiVolatile.memory.curScenePoint);
  if ( v8 == nullptr )
    goto LABEL_12;
  v9 = idCombatScenePointFSM::CastTo(c: fsm);
  if ( v9->stayTime == -1 )
  {
    idScenePoint::ActivateScenePoint(this: v8, user: ai, curTime);
    v17 = (int)(float)(v8->duration * (float)1000.0);
    v10 = v17 + curTime;
    if ( v17 < 0 )
      v10 = 666;
    v9->stayTime = v10;
  }
  idFocusInfo::SetEnableTracking(this: ai->aiVolatile.focus.foci.ptr, owner: ai, enable: false);
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v12 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v13 = idEntity::CastTo(c: v12);
  }
  else
  {
    v13 = nullptr;
  }
  idAI2::SetLookFocusEntity(this: ai, ent: v13, keepFocusInView: false, aimPoint: AIMPOINT_BEST, timeout: -1);
  v15.value = -1;
  v14.value = -1;
  idAI2::FindAnimWebAndStateIndices(
    this: ai,
    web: AIANIMWEB_BODY,
    subWeb: 18,
    stateName: "aiming",
    changeWeapon: true,
    newWeapon: nullptr,
    subWebIndex: &v15,
    stateIndex: &v14);
  if ( idAI2::ChangeAnimState(
         this: ai,
         web: AIANIMWEB_BODY,
         subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v15.value,
         stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v14.value,
         interruptPath: INTR_PATH_NO,
         interruptBlend: INTR_BLEND_NO) == 1 )
  {
    idAI2::SetAnimWebEvent(
      this: ai,
      web: AIANIMWEB_BODY,
      priority: PRIORITY_LOW,
      swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v15.value,
      si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v14.value,
      eventType: ANIMWEB_EVENT_START_BLEND_IN,
      eventDef: &EV_AnimWeb_StartUseTurret);
    *((_BYTE *)&ai->aiEditable.death + 84) &= 0x3Fu;
  }
  else
  {
LABEL_12:
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?AIState_EnterState@idCombatScenePoint_Close@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACE628
// RVA : 0x00ACE628
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_Close::AIState_EnterState(
        idCombatScenePoint_Close *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  idEntity *v10; // r29
  void (__fastcall *SetWalkState)(struct idAI2 *, const walkState_t); // r7
  idEventArg *v12; // r3
  idEventArg *v13; // r19
  idEventArg *v14; // r18
  const idEventArg *v15; // [sp+8h] [-2B8h]
  const idEventArg *v16; // [sp+Ch] [-2B4h]
  const idEventArg *v17; // [sp+10h] [-2B0h]
  _BYTE v18[20]; // [sp+70h] [-250h] BYREF
  _BYTE v19[20]; // [sp+90h] [-230h] BYREF
  _BYTE v20[20]; // [sp+B0h] [-210h] BYREF
  _BYTE v21[20]; // [sp+D0h] [-1F0h] BYREF
  _BYTE v22[20]; // [sp+F0h] [-1D0h] BYREF
  _BYTE v23[20]; // [sp+110h] [-1B0h] BYREF
  float v24[5]; // [sp+130h] [-190h] BYREF
  idEventReceiver v25[2]; // [sp+150h] [-170h] BYREF
  idEventArg v26; // [sp+170h] [-150h] BYREF
  _DWORD v27[5]; // [sp+190h] [-130h] BYREF
  _DWORD v28[5]; // [sp+1B0h] [-110h] BYREF
  float v29[5]; // [sp+1D0h] [-F0h] BYREF
  idEventArg v30; // [sp+1F0h] [-D0h] BYREF
  idEventArg v31; // [sp+210h] [-B0h] BYREF
  idEventReceiver v32[12]; // [sp+230h] [-90h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v9 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v9 != nullptr )
    {
      v10 = idEntity::CastTo(c: v9);
      if ( v10 != nullptr )
      {
        SetWalkState = ai->SetWalkState;
        ai->aiVolatile.animation.subWeb = AISUBWEB_COMBAT;
        SetWalkState(this: ai, a2: WALKSTATE_RUNNING);
        if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED )
        {
          v12 = idEventArg::idEventArg(this: &v26, data: ai);
          idEventReceiver::ProcessEvent(
            this: v25,
            result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
            ev: *(const idEventDef **)&v12->type,
            arg1: (const idEventArg *)LODWORD(v12->value.v[1]));
        }
        v29[1] = ai->aiEditable.actionSettings.close.closeMinRange;
        HIBYTE(v28[0]) = 105;
        HIBYTE(v27[0]) = 105;
        v24[1] = vec3_origin.x;
        v24[2] = vec3_origin.y;
        v28[1] = 0;
        v24[3] = vec3_origin.z;
        HIBYTE(v24[0]) = 118;
        v27[1] = 0;
        HIBYTE(v29[0]) = 102;
        HIBYTE(v25[0].__vftable) = 105;
        v25[0].listenerList = (idList<idEventReceiver *,5> *)2;
        v26.type = 105;
        v26.value.i = 0;
        v13 = idEventArg::idEventArg(this: &v30, data: v10);
        v14 = idEventArg::idEventArg(this: &v31, data: ai);
        memcpy(Dst: v23, Src: v28, Size: sizeof(v23));
        memcpy(Dst: v22, Src: v24, Size: sizeof(v22));
        memcpy(Dst: v21, Src: v27, Size: sizeof(v21));
        memcpy(Dst: v20, Src: v29, Size: sizeof(v20));
        memcpy(Dst: v19, Src: v25, Size: sizeof(v19));
        memcpy(Dst: v18, Src: v13, Size: sizeof(v18));
        idEventReceiver::ProcessEvent(
          this: v32,
          result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
          ev: *(const idEventDef **)&v14->type,
          arg1: (const idEventArg *)LODWORD(v14->value.v[1]),
          arg2: (const idEventArg *)LODWORD(v14->value.v[2]),
          arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v26.type, 32),
          arg4: (const idEventArg *)LODWORD(v26.value.v[1]),
          arg5: (const idEventArg *)LODWORD(v26.value.v[2]),
          arg6: v15,
          arg7: v16,
          arg8: v17);
        idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
        idAI2::SetAimFocusEntity(this: ai, ent: v10, keepFocusInView: false, aimPoint: AIMPOINT_BEST, timeout: -1);
        idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
      }
    }
  }
}


// ========================================================================
// ?AIState_ReenterState@idCombatScenePoint_Close@@UAAXPAVidAI2@@PAVidAIFSM@@HH@Z
// EA  : 0x82ACE898
// RVA : 0x00ACE898
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_Close::AIState_ReenterState(
        idCombatScenePoint_Close *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int transCode,
        int curTime)
{
  int value; // r8
  idEntity *v10; // r3
  idEntity *v11; // r29
  void (__fastcall *SetWalkState)(struct idAI2 *, const walkState_t); // r7
  idEventArg *v13; // r3
  idEventArg *v14; // r19
  idEventArg *v15; // r18
  const idEventArg *v16; // [sp+8h] [-2B8h]
  const idEventArg *v17; // [sp+Ch] [-2B4h]
  const idEventArg *v18; // [sp+10h] [-2B0h]
  _BYTE v19[20]; // [sp+70h] [-250h] BYREF
  _BYTE v20[20]; // [sp+90h] [-230h] BYREF
  _BYTE v21[20]; // [sp+B0h] [-210h] BYREF
  _BYTE v22[20]; // [sp+D0h] [-1F0h] BYREF
  _BYTE v23[20]; // [sp+F0h] [-1D0h] BYREF
  _BYTE v24[20]; // [sp+110h] [-1B0h] BYREF
  float v25[5]; // [sp+130h] [-190h] BYREF
  idEventReceiver v26[2]; // [sp+150h] [-170h] BYREF
  idEventArg v27; // [sp+170h] [-150h] BYREF
  _DWORD v28[5]; // [sp+190h] [-130h] BYREF
  _DWORD v29[5]; // [sp+1B0h] [-110h] BYREF
  float v30[5]; // [sp+1D0h] [-F0h] BYREF
  idEventArg v31; // [sp+1F0h] [-D0h] BYREF
  idEventArg v32; // [sp+210h] [-B0h] BYREF
  idEventReceiver v33[12]; // [sp+230h] [-90h] BYREF

  if ( ai->aiVolatile.physics.moveState.GetMoveStatus(this: &ai->aiVolatile.physics.moveState) != 1 )
  {
    value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v10 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v10 != nullptr )
      {
        v11 = idEntity::CastTo(c: v10);
        if ( v11 != nullptr )
        {
          SetWalkState = ai->SetWalkState;
          ai->aiVolatile.animation.subWeb = AISUBWEB_COMBAT;
          SetWalkState(this: ai, a2: WALKSTATE_RUNNING);
          if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED )
          {
            v13 = idEventArg::idEventArg(this: &v27, data: ai);
            idEventReceiver::ProcessEvent(
              this: v26,
              result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
              ev: *(const idEventDef **)&v13->type,
              arg1: (const idEventArg *)LODWORD(v13->value.v[1]));
          }
          v30[1] = ai->aiEditable.actionSettings.close.closeMinRange;
          HIBYTE(v29[0]) = 105;
          HIBYTE(v28[0]) = 105;
          v25[1] = vec3_origin.x;
          v25[2] = vec3_origin.y;
          v29[1] = 0;
          v25[3] = vec3_origin.z;
          HIBYTE(v25[0]) = 118;
          v28[1] = 0;
          HIBYTE(v30[0]) = 102;
          HIBYTE(v26[0].__vftable) = 105;
          v26[0].listenerList = (idList<idEventReceiver *,5> *)2;
          v27.type = 105;
          v27.value.i = 0;
          v14 = idEventArg::idEventArg(this: &v31, data: v11);
          v15 = idEventArg::idEventArg(this: &v32, data: ai);
          memcpy(Dst: v24, Src: v29, Size: sizeof(v24));
          memcpy(Dst: v23, Src: v25, Size: sizeof(v23));
          memcpy(Dst: v22, Src: v28, Size: sizeof(v22));
          memcpy(Dst: v21, Src: v30, Size: sizeof(v21));
          memcpy(Dst: v20, Src: v26, Size: sizeof(v20));
          memcpy(Dst: v19, Src: v14, Size: sizeof(v19));
          idEventReceiver::ProcessEvent(
            this: v33,
            result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
            ev: *(const idEventDef **)&v15->type,
            arg1: (const idEventArg *)LODWORD(v15->value.v[1]),
            arg2: (const idEventArg *)LODWORD(v15->value.v[2]),
            arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v27.type, 32),
            arg4: (const idEventArg *)LODWORD(v27.value.v[1]),
            arg5: (const idEventArg *)LODWORD(v27.value.v[2]),
            arg6: v16,
            arg7: v17,
            arg8: v18);
          idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
          idAI2::SetAimFocusEntity(this: ai, ent: v11, keepFocusInView: false, aimPoint: AIMPOINT_BEST, timeout: -1);
          idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
        }
      }
    }
  }
}


// ========================================================================
// ?AIState_Work@idCombatScenePoint_Close@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACEB28
// RVA : 0x00ACEB28
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_Close::AIState_Work(
        idCombatScenePoint_Close *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int value; // r8
  idEntity *v6; // r3
  idEntity *v7; // r3
  idEntity *v8; // r29
  bool v9; // r28
  idPhysics *Physics; // r3
  const idVec3 *v11; // r3
  double DistanceSqrTo; // fp31
  idAIEntityState *v13; // r3
  idStr v14; // [sp+50h] [-60h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v6 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v6 != nullptr )
    {
      v7 = idEntity::CastTo(c: v6);
      v8 = v7;
      if ( v7 != nullptr )
      {
        v9 = false;
        Physics = idEntity::GetPhysics(this: v7);
        v11 = Physics->GetOrigin(this: Physics, a2: 0);
        DistanceSqrTo = idEntity::GetDistanceSqrTo(this: ai, pos: v11);
        if ( DistanceSqrTo <= (float)(ai->aiEditable.actionSettings.close.closeMinRange
                                    * ai->aiEditable.actionSettings.close.closeMinRange) )
          v9 = ai->aiVolatile.physics.moveState.GetMoveStatus(this: &ai->aiVolatile.physics.moveState) != 0;
        if ( (ai->aiEditable.actionSettings.close.closeFlags & 1) != 0 )
        {
          v13 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8);
          if ( idAIEntityState::IsVisible(this: v13) )
          {
            if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > ai->aiVolatile.memory.currentFriendlyBlockerTime
              && (ai->aiEditable.actionSettings.close.stopOnSpotRange < 0.0
               || DistanceSqrTo < (float)(ai->aiEditable.actionSettings.close.stopOnSpotRange
                                        * ai->aiEditable.actionSettings.close.stopOnSpotRange)) )
            {
              v9 = true;
            }
            if ( (unsigned __int8)idAI2::IsBlockedByFriendly(this: ai, _pEnemy: v8) != 0 )
              v9 = true;
          }
        }
        if ( v9 )
        {
          v14.len = 0;
          v14.baseBuffer[0] = 0;
          v14.allocedAndFlag = 20;
          v14.data = v14.baseBuffer;
          idAI2::GetIdleStateName(this: ai, name: &v14);
          idAI2::ChangeAnimState(
            this: ai,
            web: AIANIMWEB_BODY,
            subWeb: ai->aiVolatile.animation.subWeb,
            stateName: v14.data,
            interruptPath: INTR_PATH_YES,
            interruptBlend: INTR_BLEND_NO,
            subWebIndex: nullptr,
            stateIndex: nullptr);
          idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
          idStr::FreeData(this: &v14);
        }
      }
    }
  }
}


// ========================================================================
// __unwind$494022
// EA  : 0x82ACED08
// RVA : 0x00ACED08
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_494022()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?AIState_EnterState@idCombatScenePoint_Idle@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACED38
// RVA : 0x00ACED38
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_Idle::AIState_EnterState(
        idCombatScenePoint_Idle *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r29
  idEventArg *v10; // r27
  _BYTE v11[20]; // [sp+70h] [-100h] BYREF
  _DWORD v12[5]; // [sp+90h] [-E0h] BYREF
  int v13; // [sp+B0h] [-C0h]
  int v14; // [sp+B4h] [-BCh]
  idEventArg v15; // [sp+D0h] [-A0h] BYREF
  idEventReceiver v16[2]; // [sp+F0h] [-80h] BYREF
  idStr v17[3]; // [sp+110h] [-60h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v8 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v8 != nullptr )
    {
      v9 = idEntity::CastTo(c: v8);
      if ( v9 != nullptr )
      {
        ai->aiVolatile.animation.subWeb = AISUBWEB_COMBAT;
        idAI2::SetEnableHeadTracking(this: ai, enable: true);
        v17[0].len = 0;
        v17[0].allocedAndFlag = 20;
        v17[0].data = v17[0].baseBuffer;
        v17[0].baseBuffer[0] = 0;
        idAI2::GetIdleStateName(this: ai, name: v17);
        idAI2::ChangeAnimState(
          this: ai,
          web: AIANIMWEB_BODY,
          subWeb: ai->aiVolatile.animation.subWeb,
          stateName: v17[0].data,
          interruptPath: INTR_PATH_YES,
          interruptBlend: INTR_BLEND_NO,
          subWebIndex: nullptr,
          stateIndex: nullptr);
        idAI2::SetAimFocusEntity(
          this: ai,
          ent: v9,
          keepFocusInView: (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 4) != 0,
          aimPoint: AIMPOINT_BEST,
          timeout: -1);
        idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
        idStr::FreeData(this: v17);
      }
    }
  }
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  v12[1] = 1;
  HIBYTE(v12[0]) = 105;
  HIBYTE(v13) = 105;
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
// __unwind$494189
// EA  : 0x82ACEED8
// RVA : 0x00ACEED8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_494189()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 272));
}


// ========================================================================
// ?AIState_Work@idCombatScenePoint_ApplyRestriction@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACEF00
// RVA : 0x00ACEF00
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_ApplyRestriction::AIState_Work(
        idCombatScenePoint_ApplyRestriction *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAIMemory *p_memory; // r29
  int value; // r8
  idVolume_Restriction *v7; // r3
  idVolume_Restriction *v8; // r31
  idPhysics *Physics; // r3
  idPhysics *v10; // r3
  const idVec3 *v11; // r3
  idPhysics *v12; // r3
  const idVec3 *v13; // r3

  p_memory = &ai->aiVolatile.memory;
  if ( idAIMemory::HasRestrictionVolume(this: &ai->aiVolatile.memory) )
  {
    value = ai->aiVolatile.memory.restrictionVolume.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v7 = (idVolume_Restriction *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v8 = idVolume_Restriction::CastTo(c: v7);
    }
    else
    {
      v8 = nullptr;
    }
    Physics = idEntity::GetPhysics(this: ai);
    if ( Physics->HasGroundContacts(this: Physics) )
    {
      v10 = idEntity::GetPhysics(this: ai);
      v11 = v10->GetOrigin(this: v10, a2: 0);
      if ( idVolume_ItemGroup::Contains(this: v8, pos: v11) )
      {
        v12 = idEntity::GetPhysics(this: ai);
        v13 = v12->GetOrigin(this: v12, a2: 0);
        idAIMemory::SetRestrictionPos(this: p_memory, pos: v13);
      }
    }
  }
}


// ========================================================================
// ?AIState_EnterState@idCombatScenePoint_Melee@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACF008
// RVA : 0x00ACF008
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_Melee::AIState_EnterState(
        idCombatScenePoint_Melee *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  const idDeclAIBehavior *decl; // r8
  int minCloseMeleeInterval; // r9
  int maxCloseMeleeInterval; // r7
  signed int v11; // r11
  int v12; // r11
  unsigned int seed; // r7
  unsigned int v14; // r3
  int v15; // r8
  unsigned int v16; // r4
  int value; // r3
  idEntity *v18; // r3
  idEntity *v19; // r3
  idTurret *v20; // r30
  idAIEntityState *v21; // r11
  idTurret *v22; // r4
  aiSenseState_t *v23; // r30
  int v24; // r26
  idVec3 *p_velocity; // r25
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  aiMelee_t MeleeTypeForTarget; // r3
  overrideAnim_t v28; // r30
  idEventArg *v29; // r27
  _BYTE v30[20]; // [sp+70h] [-120h] BYREF
  _BYTE v31[20]; // [sp+90h] [-100h] BYREF
  float v32[5]; // [sp+B0h] [-E0h] BYREF
  _DWORD v33[5]; // [sp+D0h] [-C0h] BYREF
  int v34; // [sp+F0h] [-A0h]
  overrideAnim_t v35; // [sp+F4h] [-9Ch]
  const idEventArg *v36; // [sp+F8h] [-98h]
  idEventArg v37; // [sp+110h] [-80h] BYREF
  idEventReceiver v38[8]; // [sp+130h] [-60h] BYREF

  idAI2::SetEnableHeadTracking(this: ai, enable: true);
  decl = ai->aiEditable.behaviors.decl;
  minCloseMeleeInterval = decl->minCloseMeleeInterval;
  maxCloseMeleeInterval = decl->maxCloseMeleeInterval;
  v11 = maxCloseMeleeInterval - minCloseMeleeInterval;
  if ( maxCloseMeleeInterval == minCloseMeleeInterval )
  {
    v12 = 0;
  }
  else
  {
    seed = clientGame->random.seed;
    __twllei(v11, 0);
    v14 = 1664525 * seed + 1013904223;
    clientGame->random.seed = v14;
    v15 = (v14 >> 10) & 0x7FFF;
    v16 = v11 & ~(__ROL4__(v15, 1) - 1);
    v12 = v15 % v11;
    __twlgei(v16, 0xFFFFFFFF);
  }
  ai->aiVolatile.memory.nextCloseMeleeTime = v12 + minCloseMeleeInterval + curTime;
  idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
  ai->aiVolatile.fireControl->allowReloads = false;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v18 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v19 = idEntity::CastTo(c: v18), v20 = (idTurret *)v19, v19 != nullptr)
    && (v21 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v19)) != nullptr )
  {
    v22 = v20;
    v23 = v21->senses.ptr[v21->lastSense];
    v24 = idAI2::MeleePreference(this: ai, target: v22);
    p_velocity = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v23)->velocity;
    ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v23);
    MeleeTypeForTarget = idAI2::GetMeleeTypeForTarget(
                           this: ai,
                           targetPos: &ConfirmedPhysicalSafe->origin,
                           targetVel: p_velocity,
                           meleeMask: -1,
                           preferredMask: v24);
    if ( MeleeTypeForTarget == AIMELEE_NONE )
      MeleeTypeForTarget = AIMELEE_FORWARD;
    v28 = AIMeleeTypeToOverrideAnim(meleeType: MeleeTypeForTarget);
    if ( v28 != ANIMOVERRIDE_NONE )
    {
      idAI2::EndActionScript(this: ai);
      LODWORD(fsm[1].value.v[2]) = this;
      v35 = v28;
      v33[1] = 0;
      HIBYTE(v33[0]) = 105;
      v32[1] = vec3_origin.x;
      HIBYTE(v32[0]) = 118;
      HIBYTE(v34) = 105;
      v32[3] = vec3_origin.z;
      v32[2] = vec3_origin.y;
      v29 = idEventArg::idEventArg(this: &v37, data: ai);
      memcpy(Dst: v31, Src: v32, Size: sizeof(v31));
      memcpy(Dst: v30, Src: v33, Size: sizeof(v30));
      idEventReceiver::ProcessEvent(
        this: v38,
        result: fsm,
        ev: *(const idEventDef **)&v29->type,
        arg1: (const idEventArg *)LODWORD(v29->value.v[1]),
        arg2: (const idEventArg *)LODWORD(v29->value.v[2]),
        arg3: (const idEventArg *)__ROL4__(v34, 32),
        arg4: v36);
    }
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?AIState_EnterState@idCombatScenePoint_Dodge@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACF278
// RVA : 0x00ACF278
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_Dodge::AIState_EnterState(
        idCombatScenePoint_Dodge *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  idEntity *v10; // r25
  __int64 v11; // r5
  char IsBlockedByFriendly; // r3
  dodgeFlags_t dodgeFlags; // r11
  char v14; // r30
  unsigned int v15; // r7
  idPresentable *presentable; // r11
  double v17; // fp30
  double v18; // fp29
  double v19; // fp27
  idPhysics *Physics; // r3
  float *v21; // r3
  double v22; // fp9
  double v23; // fp7
  unsigned __int8 v24; // r3
  idPresentable *v25; // r11
  unsigned __int8 v26; // r29
  double v27; // fp30
  double v28; // fp29
  double v29; // fp27
  idPhysics *v30; // r3
  float *v31; // r3
  double v32; // fp9
  double v33; // fp7
  __int64 v34; // r5
  unsigned __int8 v35; // r3
  unsigned int v36; // r7
  float v37; // r30
  unsigned __int8 v38; // r30
  idPhysics *v39; // r3
  float *v40; // r29
  idPhysics *v41; // r3
  float *v42; // r3
  double v43; // fp10
  double v44; // fp6
  idPresentable *v45; // r11
  double v46; // fp30
  double v47; // fp29
  double v48; // fp27
  idPhysics *v49; // r3
  float *v50; // r3
  double v51; // fp9
  double v52; // fp7
  idPresentable *v53; // r11
  double v54; // fp30
  double v55; // fp29
  double v56; // fp31
  idPhysics *v57; // r3
  float *v58; // r3
  double v59; // fp9
  double v60; // fp7
  __int64 v61; // r5
  unsigned int v62; // r7
  idEventArg *v63; // r3
  unsigned int v64; // r7
  idVec3 *v65; // r11
  double x; // fp29
  double y; // fp30
  double z; // fp31
  char v69; // r11
  idEventArg *v70; // r24
  unsigned int v71; // r7
  int v72; // r11
  __int64 v73; // r5
  idEventArg *v74; // r3
  const idEventArg *v75; // [sp+8h] [-318h]
  const idEventArg *v76; // [sp+Ch] [-314h]
  const idEventArg *v77; // [sp+10h] [-310h]
  _BYTE v78[20]; // [sp+70h] [-2B0h] BYREF
  _BYTE v79[20]; // [sp+90h] [-290h] BYREF
  _BYTE v80[20]; // [sp+B0h] [-270h] BYREF
  _BYTE v81[20]; // [sp+D0h] [-250h] BYREF
  _BYTE v82[20]; // [sp+F0h] [-230h] BYREF
  _BYTE v83[20]; // [sp+110h] [-210h] BYREF
  idVec3 v84[2]; // [sp+130h] [-1F0h] BYREF
  idVec3 v85; // [sp+148h] [-1D8h] BYREF
  idVec3 v86[2]; // [sp+158h] [-1C8h] BYREF
  float v87[5]; // [sp+170h] [-1B0h] BYREF
  idEventArg v88; // [sp+190h] [-190h] BYREF
  idVec3 v89; // [sp+1A8h] [-178h] BYREF
  idVec3 v90; // [sp+1B8h] [-168h] BYREF
  idEventReceiver v91[10]; // [sp+1D0h] [-150h] BYREF
  idEventArg v92; // [sp+250h] [-D0h] BYREF
  idEventArg v93[3]; // [sp+270h] [-B0h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v10 = idEntity::CastTo(c: v9);
  }
  else
  {
    v10 = nullptr;
  }
  IsBlockedByFriendly = idAI2::IsBlockedByFriendly(this: ai, _pEnemy: v10);
  dodgeFlags = ai->aiEditable.actionSettings.dodge.dodgeFlags;
  v14 = 0;
  if ( IsBlockedByFriendly != 0 )
  {
    ai->aiVolatile.memory.nextDodgeTime = curTime + 2000;
    goto LABEL_13;
  }
  ai->aiVolatile.memory.nextDodgeTime = curTime + 5000;
  if ( (dodgeFlags & 0x10) != 0 )
  {
    if ( (dodgeFlags & 8) != 0 )
    {
      v15 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v15;
      LODWORD(v11) = (v15 >> 10) & 0x7FFF;
      *(_QWORD *)&v84[0].x = v11;
      if ( (float)((float)v11 * (float)0.000030518509) > 0.5 )
      {
        v14 = 0;
        goto LABEL_13;
      }
    }
    else if ( (dodgeFlags & 0x10) == 0 )
    {
      goto LABEL_13;
    }
    v14 = 1;
  }
LABEL_13:
  presentable = ai->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: ai);
    presentable = ai->presentable;
  }
  v17 = (float)(presentable->axis.mat[1].x * (float)150.0);
  v18 = (float)(presentable->axis.mat[1].y * (float)150.0);
  v19 = (float)(presentable->axis.mat[1].z * (float)150.0);
  Physics = idEntity::GetPhysics(this: ai);
  v21 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v22 = (float)(v21[2] + (float)v19);
  v23 = (float)(v21[1] + (float)v18);
  v86[0].x = *v21 + (float)v17;
  v86[0].z = v22;
  v86[0].y = v23;
  v24 = (unsigned __int8)idAIMoveState::PointReachable(this: &ai->aiVolatile.physics.moveState, point: v86);
  v25 = ai->presentable;
  v26 = v24;
  if ( v25 == nullptr )
  {
    idEntity::InitPresentableInternal(this: ai);
    v25 = ai->presentable;
  }
  v27 = (float)(v25->axis.mat[1].x * (float)150.0);
  v28 = (float)(v25->axis.mat[1].y * (float)150.0);
  v29 = (float)(v25->axis.mat[1].z * (float)150.0);
  v30 = idEntity::GetPhysics(this: ai);
  v31 = (float *)v30->GetOrigin(this: v30, a2: 0);
  v32 = (float)(v31[2] - (float)v29);
  v33 = (float)(v31[1] - (float)v28);
  v85.x = *v31 - (float)v27;
  v85.z = v32;
  v85.y = v33;
  v35 = (unsigned __int8)idAIMoveState::PointReachable(this: &ai->aiVolatile.physics.moveState, point: &v85);
  if ( v14 != 0 )
  {
    if ( v26 != 0 )
    {
      if ( v35 == 0
        || (v36 = 1664525 * clientGame->random.seed + 1013904223,
            clientGame->random.seed = v36,
            LODWORD(v34) = (v36 >> 10) & 0x7FFF,
            *(_QWORD *)&v84[0].x = v34,
            (float)((float)v34 * (float)0.000030518509) <= 0.5) )
      {
        LODWORD(v37) = 23;
LABEL_39:
        idAI2::EndActionScript(this: ai);
        LODWORD(fsm[1].value.v[2]) = this;
        v87[1] = v37;
        HIBYTE(v87[0]) = 105;
        v63 = idEventArg::idEventArg(this: &v88, data: ai);
        idEventReceiver::ProcessEvent(
          this: v91,
          result: fsm,
          ev: *(const idEventDef **)&v63->type,
          arg1: (const idEventArg *)LODWORD(v63->value.v[1]),
          arg2: (const idEventArg *)LODWORD(v63->value.v[2]));
        return;
      }
LABEL_22:
      LODWORD(v37) = 22;
      goto LABEL_39;
    }
    if ( v35 != 0 )
      goto LABEL_22;
    v38 = 0;
    if ( v10 != nullptr )
    {
      v39 = idEntity::GetPhysics(this: v10);
      v40 = (float *)v39->GetOrigin(this: v39, a2: 0);
      v41 = idEntity::GetPhysics(this: ai);
      v42 = (float *)v41->GetOrigin(this: v41, a2: 0);
      v43 = (float)(v40[2] - v42[2]);
      v44 = (float)(v40[1] - v42[1]);
      if ( (float)((float)((float)v44 * (float)v44)
                 + (float)((float)((float)(*v40 - *v42) * (float)(*v40 - *v42)) + (float)((float)v43 * (float)v43))) >= 50625.0 )
      {
        v45 = ai->presentable;
        if ( v45 == nullptr )
        {
          idEntity::InitPresentableInternal(this: ai);
          v45 = ai->presentable;
        }
        v46 = (float)(v45->axis.mat[0].x * (float)150.0);
        v47 = (float)(v45->axis.mat[0].y * (float)150.0);
        v48 = (float)(v45->axis.mat[0].z * (float)150.0);
        v49 = idEntity::GetPhysics(this: ai);
        v50 = (float *)v49->GetOrigin(this: v49, a2: 0);
        v51 = (float)(v50[2] - (float)v48);
        v52 = (float)(v50[1] - (float)v47);
        v89.x = *v50 - (float)v46;
        v89.z = v51;
        v89.y = v52;
        v38 = (unsigned __int8)idAIMoveState::PointReachable(this: &ai->aiVolatile.physics.moveState, point: &v89);
      }
    }
    v53 = ai->presentable;
    if ( v53 == nullptr )
    {
      idEntity::InitPresentableInternal(this: ai);
      v53 = ai->presentable;
    }
    v54 = (float)(v53->axis.mat[0].x * (float)150.0);
    v55 = (float)(v53->axis.mat[0].y * (float)150.0);
    v56 = (float)(v53->axis.mat[0].z * (float)150.0);
    v57 = idEntity::GetPhysics(this: ai);
    v58 = (float *)v57->GetOrigin(this: v57, a2: 0);
    v59 = (float)(v58[2] - (float)v56);
    v60 = (float)(v58[1] - (float)v55);
    v90.x = *v58 - (float)v54;
    v90.z = v59;
    v90.y = v60;
    if ( (unsigned __int8)idAIMoveState::PointReachable(this: &ai->aiVolatile.physics.moveState, point: &v90) != 0 )
    {
      if ( v38 == 0
        || (v62 = 1664525 * clientGame->random.seed + 1013904223,
            clientGame->random.seed = v62,
            LODWORD(v61) = (v62 >> 10) & 0x7FFF,
            *(_QWORD *)&v84[0].x = v61,
            (float)((float)v61 * (float)0.000030518509) > 0.5) )
      {
        LODWORD(v37) = 24;
        goto LABEL_39;
      }
LABEL_38:
      LODWORD(v37) = 21;
      goto LABEL_39;
    }
    if ( v38 != 0 )
      goto LABEL_38;
    goto LABEL_57;
  }
  v84[0] = vec3_origin;
  if ( v26 != 0 )
  {
    if ( v35 != 0 )
    {
      v64 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v64;
      v65 = v86;
      LODWORD(v34) = (v64 >> 10) & 0x7FFF;
      *(_QWORD *)&v84[0].x = v34;
      if ( (float)((float)v34 * (float)0.000030518509) > 0.5 )
        v65 = &v85;
      x = v65->x;
      y = v65->y;
      z = v65->z;
    }
    else
    {
      x = v86[0].x;
      y = v86[0].y;
      z = v86[0].z;
    }
  }
  else if ( v35 != 0 )
  {
    x = v85.x;
    y = v85.y;
    z = v85.z;
  }
  else
  {
    z = v84[0].z;
    y = v84[0].y;
    x = v84[0].x;
  }
  if ( x != vec3_origin.x || y != vec3_origin.y || (v69 = 1, z != vec3_origin.z) )
    v69 = 0;
  if ( v69 != 0 )
  {
LABEL_57:
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    v71 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v71;
    v72 = 25;
    LODWORD(v73) = (v71 >> 10) & 0x7FFF;
    *(_QWORD *)&v84[0].x = v73;
    if ( (float)((float)v73 * (float)0.000030518509) > 0.5 )
      v72 = 26;
    v88.value.i = v72;
    v88.type = 105;
    v74 = idEventArg::idEventArg(this: v93, data: ai);
    idEventReceiver::ProcessEvent(
      this: (idEventReceiver *)&v92,
      result: fsm,
      ev: *(const idEventDef **)&v74->type,
      arg1: (const idEventArg *)LODWORD(v74->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v74->value.v[2]));
    return;
  }
  if ( v10 != nullptr )
  {
    idAI2::SetAimFocusEntity(this: ai, ent: v10, keepFocusInView: true, aimPoint: AIMPOINT_BEST, timeout: -1);
    idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
  }
  ai->SetWalkState(this: ai, a2: WALKSTATE_WALKING);
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  v87[1] = x;
  v87[2] = y;
  v87[3] = z;
  *(float *)&v91[5].listeningToList = 0.1;
  v84[1].x = vec3_origin.z;
  HIBYTE(v91[2].listeningToList) = 105;
  v91[3].__vftable = nullptr;
  v84[0].z = vec3_origin.y;
  HIBYTE(v84[0].x) = 118;
  v84[0].y = vec3_origin.x;
  HIBYTE(v91[8].__vftable) = 105;
  v91[8].listenerList = nullptr;
  HIBYTE(v91[5].listenerList) = 102;
  HIBYTE(v91[0].__vftable) = 105;
  v91[0].listenerList = (idList<idEventReceiver *,5> *)2;
  HIBYTE(v87[0]) = 118;
  v88.type = 105;
  v88.value.i = 0;
  v70 = idEventArg::idEventArg(this: &v92, data: ai);
  memcpy(Dst: v83, Src: &v91[2].listeningToList, Size: sizeof(v83));
  memcpy(Dst: v82, Src: v84, Size: sizeof(v82));
  memcpy(Dst: v81, Src: &v91[8], Size: sizeof(v81));
  memcpy(Dst: v80, Src: &v91[5].listenerList, Size: sizeof(v80));
  memcpy(Dst: v79, Src: v91, Size: sizeof(v79));
  memcpy(Dst: v78, Src: v87, Size: sizeof(v78));
  idEventReceiver::ProcessEvent(
    this: (idEventReceiver *)v93,
    result: fsm,
    ev: &ACTION_MoveToPointEnter,
    arg1: (const idEventArg *)LODWORD(v70->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v70->value.v[2]),
    arg3: *(const idEventArg **)&v88.type,
    arg4: (const idEventArg *)LODWORD(v88.value.v[1]),
    arg5: (const idEventArg *)LODWORD(v88.value.v[2]),
    arg6: v75,
    arg7: v76,
    arg8: v77);
}


// ========================================================================
// ?Evaluate@CombatScenePoint_Shall_Close@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ACFC50
// RVA : 0x00ACFC50
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

int __fastcall CombatScenePoint_Shall_Close::Evaluate(
        CombatScenePoint_Shall_Close *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIMemory *p_memory; // r30
  idScenePoint *curScenePoint; // r11
  char v9; // r11
  bool v10; // zf
  idEntity *Enemy; // r29
  float y; // r8
  float z; // r7
  int v14; // r6
  idVolume_Restriction *v15; // r3
  const aiSenseState_t *EnemySenseState; // r3
  int lastConfirmedStimTime; // r11
  double DistanceSqrTo; // fp1
  double v19; // fp31
  idAIEntityState *v20; // r3
  idVec3 v22; // [sp+50h] [-60h] BYREF
  int v23; // [sp+5Ch] [-54h]
  idVec3 v24[2]; // [sp+60h] [-50h] BYREF

  if ( !ai->aiEditable.actionSettings.cover.usesClose )
    return 0;
  p_memory = &ai->aiVolatile.memory;
  curScenePoint = ai->aiVolatile.memory.curScenePoint;
  if ( curScenePoint == nullptr || (v10 = curScenePoint->type == 4, v9 = 1, !v10) )
    v9 = 0;
  if ( v9 != 0 )
    return 0;
  if ( (unsigned __int8)idAIEditable::idAIActionSettings::HasSquadLeader(this: &ai->aiEditable.actionSettings) != 0 )
    return 0;
  Enemy = (idEntity *)idAIMemory::GetEnemy(this: p_memory);
  if ( Enemy == nullptr )
    return 0;
  y = ai->aiVolatile.memory.currentEnemySuspectedPos.pos.y;
  z = ai->aiVolatile.memory.currentEnemySuspectedPos.pos.z;
  v14 = *(_DWORD *)&ai->aiVolatile.memory.currentEnemySuspectedPos.bValid;
  v22.x = ai->aiVolatile.memory.currentEnemySuspectedPos.pos.x;
  v22.y = y;
  v22.z = z;
  v23 = v14;
  if ( HIBYTE(v14) == 0 )
    return 0;
  v24[0] = v22;
  if ( idAIMemory::HasRestrictionVolume(this: p_memory) )
  {
    LODWORD(v22.x) = ai->aiVolatile.memory.restrictionVolume.spawnId.value;
    v15 = idEntityPtr<idVolume_Restriction>::operator idVolume_Restriction *(this: (idEntityPtr<idVolume_Restriction> *)&v22);
    if ( !idVolume_ItemGroup::Contains(this: v15, pos: v24) )
      return 0;
  }
  if ( ai->aiEditable.perception.combatTimeoutInterval >= 0.0 )
  {
    EnemySenseState = idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
    if ( EnemySenseState != nullptr )
    {
      lastConfirmedStimTime = EnemySenseState->lastConfirmedStimTime;
      if ( lastConfirmedStimTime > 0 )
      {
        LODWORD(v22.y) = (int)(float)(ai->aiEditable.perception.combatTimeoutInterval * (float)1000.0);
        if ( curTime - lastConfirmedStimTime > SLODWORD(v22.y) )
          return 0;
      }
    }
  }
  DistanceSqrTo = idEntity::GetDistanceSqrTo(this: ai, pos: v24);
  v19 = DistanceSqrTo;
  if ( DistanceSqrTo < (float)(ai->aiEditable.actionSettings.close.closeMinRange
                             * ai->aiEditable.actionSettings.close.closeMinRange)
    || ai->aiEditable.actionSettings.close.closeMaxRange >= 0.0
    && DistanceSqrTo > (float)(ai->aiEditable.actionSettings.close.closeMaxRange
                             * ai->aiEditable.actionSettings.close.closeMaxRange) )
  {
    return 0;
  }
  if ( (ai->aiEditable.actionSettings.close.closeFlags & 1) != 0
    && (v20 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: Enemy),
        idAIEntityState::IsVisible(this: v20))
    && (idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > ai->aiVolatile.memory.currentFriendlyBlockerTime
     && (ai->aiEditable.actionSettings.close.stopOnSpotRange < 0.0
      || v19 < (float)(ai->aiEditable.actionSettings.close.stopOnSpotRange
                     * ai->aiEditable.actionSettings.close.stopOnSpotRange))
     || (unsigned __int8)idAI2::IsBlockedByFriendly(this: ai, _pEnemy: Enemy) != 0) )
  {
    return 0;
  }
  else
  {
    return 456;
  }
}


// ========================================================================
// ?Evaluate@CombatScenePoint_Shall_ApplyRestriction@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ACFEA8
// RVA : 0x00ACFEA8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

int __fastcall CombatScenePoint_Shall_ApplyRestriction::Evaluate(
        CombatScenePoint_Shall_ApplyRestriction *this,
        idAI2 *ai,
        idCombatScenePointFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIEditable::idAIActionSettings *p_actionSettings; // r29
  idScenePoint_Combat *curScenePoint; // r3
  idScenePoint_Combat *v9; // r3
  idScenePoint *v10; // r30
  idActor *SquadLeader; // r3
  idPhysics *v12; // r3
  float *v13; // r29
  float *v14; // r3
  double v15; // fp9
  double v16; // fp7
  double v17; // fp5
  idCombatScenePointFSM *v18; // r3
  idPhysics *v20; // r3
  int v21; // r3
  int v22; // r9
  float *v23; // r30
  idActor *v24; // r3
  idActor *v25; // r3
  idPhysics *v26; // r3
  float *v27; // r3
  double v28; // fp9
  double v29; // fp7
  double v30; // fp5
  idScenePoint **p_curScenePoint; // r27
  idScenePoint_Combat *v32; // r3
  idScenePoint *v33; // r30
  int value; // r8
  idVolume_Restriction *v35; // r3
  idVolume_Restriction *v36; // r29
  idPhysics *Physics; // r3
  const idVec3 *v38; // r3
  idScenePoint *ScenePointPos; // r3
  idPhysics *v40; // r3
  idPhysics *v41; // r3
  const idVec3 *v42; // r3
  _BYTE v43[96]; // [sp+50h] [-60h] BYREF

  p_actionSettings = &ai->aiEditable.actionSettings;
  if ( (unsigned __int8)idAIEditable::idAIActionSettings::HasSquadLeader(this: &ai->aiEditable.actionSettings) == 0 )
  {
LABEL_14:
    p_curScenePoint = &ai->aiVolatile.memory.curScenePoint;
    v32 = idScenePoint_Combat::CastTo(c: (idScenePoint_Combat *)ai->aiVolatile.memory.curScenePoint);
    v33 = v32;
    if ( v32 != nullptr && (v32->scriptFlags & 1) != 0
      || !idAIMemory::HasRestrictionVolume(this: &ai->aiVolatile.memory) )
    {
      return 0;
    }
    value = ai->aiVolatile.memory.restrictionVolume.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v35 = (idVolume_Restriction *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v36 = idVolume_Restriction::CastTo(c: v35);
    }
    else
    {
      v36 = nullptr;
    }
    Physics = idEntity::GetPhysics(this: ai);
    v38 = Physics->GetOrigin(this: Physics, a2: 0);
    if ( idVolume_ItemGroup::Contains(this: v36, pos: v38) )
    {
      if ( v33 != nullptr )
      {
        ScenePointPos = idScenePoint::GetScenePointPos(this: (idScenePoint *)v43, result: v33);
        if ( !idVolume_ItemGroup::Contains(this: v36, pos: (const idVec3 *)ScenePointPos) )
        {
          idAIMemory::UpdateScenePointHistory(this: &ai->aiVolatile.memory, scenePoint: v33);
          idScenePoint::ReleaseScenePoint(this: v33, user: ai);
          *p_curScenePoint = nullptr;
        }
      }
      v40 = idEntity::GetPhysics(this: ai);
      if ( v40->HasGroundContacts(this: v40) )
      {
        v41 = idEntity::GetPhysics(this: ai);
        v42 = v41->GetOrigin(this: v41, a2: 0);
        idAIMemory::SetRestrictionPos(this: &ai->aiVolatile.memory, pos: v42);
      }
      return 0;
    }
    if ( v33 != nullptr
      && (unsigned __int8)idAIMemory::CheckIfDirtyScenePoint(this: &ai->aiVolatile.memory, dirtyScenePoint: v33) != 0 )
    {
      idAIMemory::UpdateScenePointHistory(this: &ai->aiVolatile.memory, scenePoint: v33);
      idScenePoint::ReleaseScenePoint(this: v33, user: ai);
      *p_curScenePoint = nullptr;
    }
    return 454;
  }
  curScenePoint = (idScenePoint_Combat *)ai->aiVolatile.memory.curScenePoint;
  if ( curScenePoint == nullptr || (v9 = idScenePoint_Combat::CastTo(c: curScenePoint), v10 = v9, v9 == nullptr) )
  {
    v20 = idEntity::GetPhysics(this: ai);
    v21 = (int)v20->GetOrigin(this: v20, a2: 0);
    v22 = ai->aiEditable.actionSettings.squad.squadLeader.spawnId.value;
    v23 = (float *)v21;
    if ( gameLocal->spawnIds.ptr[v22 & 0x1FFF] == v22 >> 13
      && (v24 = (idActor *)gameLocal->entities.ptr[v22 & 0x1FFF]) != nullptr )
    {
      v25 = idActor::CastTo(c: v24);
    }
    else
    {
      v25 = nullptr;
    }
    v26 = idEntity::GetPhysics(this: v25);
    v27 = (float *)v26->GetOrigin(this: v26, a2: 0);
    v28 = (float)(v23[1] - v27[1]);
    v29 = (float)(v23[2] - v27[2]);
    v30 = (float)(ai->aiEditable.actionSettings.squad.leaderRange + (float)200.0);
    if ( (float)((float)((float)(*v23 - *v27) * (float)(*v23 - *v27))
               + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28))) > (double)(float)((float)v30 * (float)v30) )
      return 454;
    goto LABEL_14;
  }
  if ( (v9->scriptFlags & 1) != 0 )
    return 0;
  SquadLeader = (idActor *)idAIEditable::idAIActionSettings::GetSquadLeader(this: p_actionSettings);
  v12 = idEntity::GetPhysics(this: SquadLeader);
  v13 = (float *)v12->GetOrigin(this: v12, a2: 0);
  v14 = (float *)idScenePoint::GetScenePointPos(this: (idScenePoint *)v43, result: v10);
  v15 = (float)(v13[1] - v14[1]);
  v16 = (float)(v13[2] - v14[2]);
  v17 = (float)(ai->aiEditable.actionSettings.squad.scenePointRange + (float)250.0);
  if ( (float)((float)((float)(*v13 - *v14) * (float)(*v13 - *v14))
             + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) <= (double)(float)((float)v17 * (float)v17) )
    return 0;
  v18 = idCombatScenePointFSM::CastTo(c: parentFSM);
  if ( v18 != nullptr )
    v18->stayTime = -1;
  idAIMemory::UpdateScenePointHistory(this: &ai->aiVolatile.memory, scenePoint: v10);
  idScenePoint::ReleaseScenePoint(this: v10, user: ai);
  ai->aiVolatile.memory.curScenePoint = nullptr;
  return 453;
}


// ========================================================================
// ?AIState_EnterState@idCombatScenePoint_MoveTo@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD0258
// RVA : 0x00AD0258
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_MoveTo::AIState_EnterState(
        idCombatScenePoint_MoveTo *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idScenePoint_Combat *v7; // r3
  idScenePoint_Combat *v8; // r28
  scenePointScriptFlags_t scriptFlags; // r11
  idAI2 *v10; // r3
  void (__fastcall *SetWalkState)(struct idAI2 *, const walkState_t); // ctr
  int v12; // r4
  int value; // r8
  idEntity *v14; // r3
  idEntity *v15; // r27
  scenePointScriptFlags_t v16; // r10
  BOOL v17; // r30
  char v18; // r11
  idAIFireControl *fireControl; // r3
  idProp_WeaponStatic *scenePointTurret; // r10
  int entityNumber; // r11
  idProp_WeaponStatic *v22; // r30
  idPresentable *presentable; // r11
  idList<idEventReceiver *,5> *y_low; // r9
  idList<idEventReceiver *,5> *z_low; // r8
  double v26; // fp12
  idEventArg *v27; // r30
  __int16 *SubWebIndexForName; // r3
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *decl; // r4
  idMD6Anim *AnimForAnimWebNode; // r3
  bool v31; // r30
  idPhysics *Physics; // r3
  float *v33; // r3
  double v34; // fp31
  idPhysics *v35; // r3
  float *v36; // r27
  float *ScenePointPos; // r3
  double v38; // fp13
  double v39; // fp9
  idPresentable *v40; // r11
  float y; // r10
  float z; // r9
  double v43; // fp29
  double v44; // fp31
  double v45; // fp30
  idCombatScenePointFSM *v46; // r3
  idEventArg *v47; // r23
  double duration; // fp0
  double radius; // fp13
  idEventArg *v50; // r30
  idEventArg *v51; // r29
  idPresentable *v52; // r11
  double v53; // fp12
  idEventArg *v54; // r30
  idEventArg *v55; // r29
  const idEventArg *v56; // [sp+8h] [-378h]
  const idEventArg *v57; // [sp+Ch] [-374h]
  const idEventArg *v58; // [sp+10h] [-370h]
  _BYTE v59[20]; // [sp+70h] [-310h] BYREF
  _BYTE v60[20]; // [sp+90h] [-2F0h] BYREF
  _BYTE v61[20]; // [sp+B0h] [-2D0h] BYREF
  _BYTE v62[20]; // [sp+D0h] [-2B0h] BYREF
  _BYTE v63[20]; // [sp+F0h] [-290h] BYREF
  _BYTE v64[20]; // [sp+110h] [-270h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v65; // [sp+130h] [-250h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v66; // [sp+132h] [-24Eh] BYREF
  idEventReceiver v67[2]; // [sp+140h] [-240h] BYREF
  idVec3 v68[2]; // [sp+158h] [-228h] BYREF
  float v69[5]; // [sp+170h] [-210h] BYREF
  idDeclAnimWeb v70; // [sp+184h] [-1FCh] BYREF
  idEventArg v71; // [sp+2B0h] [-D0h] BYREF
  idMat3 v72; // [sp+2D0h] [-B0h] BYREF

  v7 = idScenePoint_Combat::CastTo(c: (idScenePoint_Combat *)ai->aiVolatile.memory.curScenePoint);
  v8 = v7;
  if ( v7 == nullptr )
  {
    idState::SetEnterFailed(this, failed: true);
    return;
  }
  ai->aiVolatile.animation.subWeb = AISUBWEB_COMBAT;
  scriptFlags = v7->scriptFlags;
  if ( (scriptFlags & 1) == 0 )
  {
    v10 = ai;
    SetWalkState = ai->SetWalkState;
    goto LABEL_7;
  }
  v10 = ai;
  SetWalkState = ai->SetWalkState;
  if ( (scriptFlags & 2) != 0 )
  {
LABEL_7:
    v12 = 2;
    goto LABEL_8;
  }
  v12 = 1;
LABEL_8:
  SetWalkState(this: v10, a2: (const walkState_t)v12);
  idAI2::SetEnableHeadTracking(this: ai, enable: true);
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v14 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v15 = idEntity::CastTo(c: v14)) != nullptr )
  {
    v16 = v8->scriptFlags;
    if ( (v16 & 1) != 0 )
    {
      v17 = (v8->scriptFlags & 8) != 0;
      if ( (v16 & 8) != 0 || (v18 = 0, (v16 & 4) != 0) )
        v18 = 1;
      if ( v18 != 0 )
      {
        idAI2::SetAimFocusEntity(
          this: ai,
          ent: v15,
          keepFocusInView: (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 4) != 0,
          aimPoint: AIMPOINT_BEST,
          timeout: -1);
        fireControl = ai->aiVolatile.fireControl;
        if ( v17 )
          idAIFireControl::SetFireMode(this: fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
        else
          idAIFireControl::SetFireMode(this: fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
      }
      else
      {
        idAI2::ClearAimFocus(this: ai);
        idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
      }
    }
    else
    {
      idAIVoiceController::PlayVoice(this: &ai->aiVolatile.voiceController, ai, msg: AIVOICE_COMBAT_CHANGE_POSITION);
      idAI2::SetAimFocusEntity(
        this: ai,
        ent: v15,
        keepFocusInView: (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 4) != 0,
        aimPoint: AIMPOINT_BEST,
        timeout: -1);
      idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
    }
  }
  else
  {
    idAI2::ClearAimFocus(this: ai);
  }
  scenePointTurret = v8->scenePointTurret;
  if ( scenePointTurret != nullptr )
  {
    entityNumber = scenePointTurret->entityNumber;
    v70.__vftable = (idDeclAnimWeb_vtbl *)v8->scenePointTurret;
    ai->aiVolatile.memory.usedProp.spawnId.value = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
    v8->scenePointTurret->GetUseLocation(this: v8->scenePointTurret, a2: ai, a3: (idVec3 *)&v70.nodeCache.granularity);
    v22 = v8->scenePointTurret;
    presentable = v22->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: v8->scenePointTurret);
      presentable = v22->presentable;
    }
    y_low = (idList<idEventReceiver *,5> *)LODWORD(presentable->axis.mat[0].y);
    z_low = (idList<idEventReceiver *,5> *)LODWORD(presentable->axis.mat[0].z);
    v67[0].__vftable = (idEventReceiver_vtbl *)LODWORD(presentable->axis.mat[0].x);
    v67[0].listenerList = y_low;
    v67[0].listeningToList = z_low;
    idVec3::NormalizeFast(this: (idVec3 *)v67);
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    v26 = *(float *)&v67[0].listeningToList;
    v67[0].listeningToList = v67[0].listenerList;
    v67[0].listenerList = (idList<idEventReceiver *,5> *)v67[0].__vftable;
    HIBYTE(v70.nextOnHashChain) = 105;
    *(float *)&v67[1].__vftable = v26;
    *(float *)&v70.models.size = 0.1;
    v70.resourceListPtr = nullptr;
    v69[1] = *(float *)&v70.nodeCache.granularity;
    v69[2] = *(float *)&v70.scalars.list;
    HIBYTE(v67[0].__vftable) = 118;
    v69[3] = *(float *)&v70.scalars.num;
    HIBYTE(v70.edgeCache.num) = 105;
    v70.edgeCache.size = 1;
    HIBYTE(v70.models.num) = 102;
    HIBYTE(v70.md5Checksum) = 105;
    *(_DWORD *)&v70.programaticallyDefined = 2;
    HIBYTE(v69[0]) = 118;
    HIBYTE(v70.subWebs.num) = 105;
    v70.subWebs.size = 19;
    v27 = idEventArg::idEventArg(this: &v71, data: ai);
    memcpy(Dst: v64, Src: &v70.nextOnHashChain, Size: sizeof(v64));
    memcpy(Dst: v63, Src: v67, Size: sizeof(v63));
    memcpy(Dst: v62, Src: &v70.edgeCache.num, Size: sizeof(v62));
    memcpy(Dst: v61, Src: &v70.models.num, Size: sizeof(v61));
    memcpy(Dst: v60, Src: &v70.md5Checksum, Size: sizeof(v60));
    memcpy(Dst: v59, Src: v69, Size: sizeof(v59));
    idEventReceiver::ProcessEvent(
      this: (idEventReceiver *)&v70.settings.defaultBlendDuration,
      result: fsm,
      ev: *(const idEventDef **)&v27->type,
      arg1: (const idEventArg *)LODWORD(v27->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v27->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(LODWORD(v27->value.q[3]), 32),
      arg4: *(const idEventArg **)&v70.subWebs.granularity,
      arg5: (const idEventArg *)v70.states.list,
      arg6: v56,
      arg7: v57,
      arg8: v58);
    return;
  }
  if ( v8->enterAnimSet.enterAnim.len != 0 )
  {
    v70.layers.num = 0;
    HIBYTE(v70.edgeIndexCache) = 0;
    *(_DWORD *)&v70.layers.granularity = 20;
    v70.layers.size = (int)&v70.edgeIndexCache;
    v70.settings.gridSize = 20;
    LODWORD(v70.settings.editPos.z) = &v70.settings.snapToGrid;
    v70.settings.editPos.y = 0.0;
    v70.settings.snapToGrid = false;
    idAI2::GetSubWebAndStateFromAnimWebPath(
      this: ai,
      animWebPath: v8->enterAnimSet.enterAnim.data,
      subWebName: (idStr *)&v70.layers.num,
      stateName: (idStr *)&v70.settings.editPos.y);
    v65.value = -1;
    v66.value = -1;
    SubWebIndexForName = (__int16 *)idDeclAnimWeb::GetSubWebIndexForName(
                                      this: (idDeclAnimWeb *)&v70.nodeCache.size,
                                      result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
                                      subWebName: (const char *)v70.layers.size);
    decl = (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl;
    v65.value = *SubWebIndexForName;
    v66.value = HIWORD(idDeclAnimWeb::GetStateIndexForName(
                         this: &v70,
                         result: decl,
                         name: (const char *)LODWORD(v70.settings.editPos.z))->__vftable);
    AnimForAnimWebNode = idAI2::GetAnimForAnimWebNode(this: ai, swi: &v65, si: &v66);
    if ( AnimForAnimWebNode != nullptr )
    {
      idMD6Anim::GetAnimationDelta(
        this: AnimForAnimWebNode,
        deltaTrans: (idVec3 *)&v70.scalars.granularity,
        deltaAxis: &v72);
      idScenePoint::GetScenePointPos(this: (idScenePoint *)v68, result: v8);
      v68[0].x = v68[0].x - *(float *)&v70.scalars.granularity;
      v68[0].y = v68[0].y - *(float *)&v70.editorModels.list;
      v68[0].z = v68[0].z - *(float *)&v70.editorModels.num;
      if ( (unsigned __int8)idAIMoveState::PointReachable(this: &ai->aiVolatile.physics.moveState, point: v68) != 0 )
      {
        v31 = true;
        if ( !v8->enterAnimSet.forced )
        {
          Physics = idEntity::GetPhysics(this: ai);
          v33 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
          v34 = (float)((float)((float)(v68[0].z - v33[2]) * (float)(v68[0].z - v33[2]))
                      + (float)((float)((float)(v68[0].x - *v33) * (float)(v68[0].x - *v33))
                              + (float)((float)(v68[0].y - v33[1]) * (float)(v68[0].y - v33[1]))));
          v35 = idEntity::GetPhysics(this: ai);
          v36 = (float *)v35->GetOrigin(this: v35, a2: 0);
          ScenePointPos = (float *)idScenePoint::GetScenePointPos(this: (idScenePoint *)v67, result: v8);
          v38 = (float)(ScenePointPos[1] - v36[1]);
          v39 = (float)(ScenePointPos[2] - v36[2]);
          v31 = v34 <= (float)((float)((float)v39 * (float)v39)
                             + (float)((float)((float)(*ScenePointPos - *v36) * (float)(*ScenePointPos - *v36))
                                     + (float)((float)v38 * (float)v38)));
        }
        if ( v31 )
        {
          v40 = v8->presentable;
          if ( v40 == nullptr )
          {
            idEntity::InitPresentableInternal(this: v8);
            v40 = v8->presentable;
          }
          y = v40->axis.mat[0].y;
          z = v40->axis.mat[0].z;
          v67[0].__vftable = (idEventReceiver_vtbl *)LODWORD(v40->axis.mat[0].x);
          *(float *)&v67[0].listenerList = y;
          *(float *)&v67[0].listeningToList = z;
          v43 = (float)(z - v72.mat[0].z);
          v44 = (float)(*(float *)&v67[0].__vftable - v72.mat[0].x);
          v45 = (float)(y - v72.mat[0].y);
          v46 = idCombatScenePointFSM::CastTo(c: (idCombatScenePointFSM *)fsm);
          if ( v46 != nullptr )
            v46->enterValid = true;
          idAI2::EndActionScript(this: ai);
          LODWORD(fsm[1].value.v[2]) = this;
          v69[1] = v44;
          HIBYTE(v70.subWebs.num) = 105;
          HIBYTE(v70.md5Checksum) = 105;
          *(float *)&v70.models.size = 0.1;
          HIBYTE(v70.edgeCache.num) = 105;
          HIBYTE(v70.nextOnHashChain) = 105;
          v69[2] = v45;
          v69[3] = v43;
          v70.subWebs.size = 0;
          *(float *)&v67[0].listeningToList = v68[0].y;
          HIBYTE(v69[0]) = 118;
          *(float *)&v67[1].__vftable = v68[0].z;
          *(_DWORD *)&v70.programaticallyDefined = 1;
          HIBYTE(v70.models.num) = 102;
          v70.edgeCache.size = 2;
          HIBYTE(v67[0].__vftable) = 118;
          v70.resourceListPtr = (idResourceList *)35;
          *(float *)&v67[0].listenerList = v68[0].x;
          v47 = idEventArg::idEventArg(this: (idEventArg *)&v70.settings.defaultBlendDuration, data: ai);
          memcpy(Dst: v64, Src: &v70.subWebs.num, Size: sizeof(v64));
          memcpy(Dst: v63, Src: v69, Size: sizeof(v63));
          memcpy(Dst: v62, Src: &v70.md5Checksum, Size: sizeof(v62));
          memcpy(Dst: v61, Src: &v70.models.num, Size: sizeof(v61));
          memcpy(Dst: v60, Src: &v70.edgeCache.num, Size: sizeof(v60));
          memcpy(Dst: v59, Src: v67, Size: sizeof(v59));
          idEventReceiver::ProcessEvent(
            this: (idEventReceiver *)&v71,
            result: fsm,
            ev: *(const idEventDef **)&v47->type,
            arg1: (const idEventArg *)LODWORD(v47->value.v[1]),
            arg2: (const idEventArg *)LODWORD(v47->value.v[2]),
            arg3: (const idEventArg *)__ROL4__(v70.nextOnHashChain, 32),
            arg4: (const idEventArg *)v70.resourceError,
            arg5: (const idEventArg *)v70.networkID,
            arg6: v56,
            arg7: v57,
            arg8: v58);
          idStr::FreeData(this: (idStr *)&v70.settings.editPos.y);
          idStr::FreeData(this: (idStr *)&v70.layers.num);
          return;
        }
      }
      else
      {
        idLib::Warning(
          fmt: "Enter animation location for scenepoint %s not reachable by AI %s! Skipping it.",
          v8->name.data,
          ai->name.data);
      }
    }
    idStr::FreeData(this: (idStr *)&v70.settings.editPos.y);
    idStr::FreeData(this: (idStr *)&v70.layers.num);
  }
  if ( idScenePoint_Combat::IsTactical(this: v8) || v8->customSet.customCoverSet.len != 0 )
  {
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    v52 = v8->presentable;
    HIBYTE(v70.subWebs.num) = 105;
    v70.subWebs.size = 0;
    if ( v52 == nullptr )
    {
      idEntity::InitPresentableInternal(this: v8);
      v52 = v8->presentable;
    }
    v69[1] = v52->axis.mat[0].x;
    v53 = v52->axis.mat[0].z;
    v69[2] = v52->axis.mat[0].y;
    v69[3] = v53;
    *(float *)&v70.models.size = 0.0;
    v70.__vftable = (idDeclAnimWeb_vtbl *)&v52->axis;
    HIBYTE(v69[0]) = 118;
    HIBYTE(v70.md5Checksum) = 105;
    *(_DWORD *)&v70.programaticallyDefined = 1;
    HIBYTE(v70.models.num) = 102;
    HIBYTE(v70.edgeCache.num) = 105;
    v70.edgeCache.size = 2;
    HIBYTE(v70.nextOnHashChain) = 105;
    v70.resourceListPtr = (idResourceList *)35;
    v54 = idEventArg::idEventArg(this: (idEventArg *)&v70.settings.defaultBlendDuration, data: v8);
    v55 = idEventArg::idEventArg(this: &v71, data: ai);
    memcpy(Dst: v64, Src: &v70.subWebs.num, Size: sizeof(v64));
    memcpy(Dst: v63, Src: v69, Size: sizeof(v63));
    memcpy(Dst: v62, Src: &v70.md5Checksum, Size: sizeof(v62));
    memcpy(Dst: v61, Src: &v70.models.num, Size: sizeof(v61));
    memcpy(Dst: v60, Src: &v70.edgeCache.num, Size: sizeof(v60));
    memcpy(Dst: v59, Src: v54, Size: sizeof(v59));
    idEventReceiver::ProcessEvent(
      this: v67,
      result: fsm,
      ev: *(const idEventDef **)&v55->type,
      arg1: (const idEventArg *)LODWORD(v55->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v55->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v70.nextOnHashChain, 32),
      arg4: (const idEventArg *)v70.resourceError,
      arg5: (const idEventArg *)v70.networkID,
      arg6: v56,
      arg7: v57,
      arg8: v58);
  }
  else
  {
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    duration = v8->duration;
    v70.subWebs.size = 0;
    HIBYTE(v70.subWebs.num) = 105;
    HIBYTE(v69[0]) = 118;
    v69[1] = vec3_origin.x;
    v69[3] = vec3_origin.z;
    v69[2] = vec3_origin.y;
    radius = v8->radius;
    HIBYTE(v70.md5Checksum) = 105;
    HIBYTE(v70.models.num) = 102;
    *(_DWORD *)&v70.programaticallyDefined = (_cntlzw(duration == 0.0) & 0x20) != 0;
    *(float *)&v70.models.size = (float)radius * (float)0.5;
    HIBYTE(v70.nextOnHashChain) = 105;
    HIBYTE(v70.edgeCache.num) = 105;
    v70.edgeCache.size = 35;
    v70.resourceListPtr = (idResourceList *)(*(_DWORD *)&v70.programaticallyDefined + 1);
    v50 = idEventArg::idEventArg(this: (idEventArg *)&v70.settings.defaultBlendDuration, data: v8);
    v51 = idEventArg::idEventArg(this: &v71, data: ai);
    memcpy(Dst: v64, Src: &v70.subWebs.num, Size: sizeof(v64));
    memcpy(Dst: v63, Src: v69, Size: sizeof(v63));
    memcpy(Dst: v62, Src: &v70.md5Checksum, Size: sizeof(v62));
    memcpy(Dst: v61, Src: &v70.models.num, Size: sizeof(v61));
    memcpy(Dst: v60, Src: &v70.nextOnHashChain, Size: sizeof(v60));
    memcpy(Dst: v59, Src: v50, Size: sizeof(v59));
    idEventReceiver::ProcessEvent(
      this: v67,
      result: fsm,
      ev: *(const idEventDef **)&v51->type,
      arg1: (const idEventArg *)LODWORD(v51->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v51->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v70.edgeCache.num, 32),
      arg4: *(const idEventArg **)&v70.edgeCache.granularity,
      arg5: (const idEventArg *)v70.nodeCache.list,
      arg6: v56,
      arg7: v57,
      arg8: v58);
  }
}


// ========================================================================
// __unwind$495811
// EA  : 0x82AD0D2C
// RVA : 0x00AD0D2C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_495811()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 896 + 592));
}


// ========================================================================
// __unwind$495812
// EA  : 0x82AD0D54
// RVA : 0x00AD0D54
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_495812()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 896 + 624));
}


// ========================================================================
// ?AIState_ExitState@idCombatScenePoint_UseTurret@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD0D80
// RVA : 0x00AD0D80
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_UseTurret::AIState_ExitState(
        idCombatScenePoint_UseTurret *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  const idWeapon *WeaponToDraw; // r8
  int GameMs; // r29
  int v7; // r30
  const idAnimStack *v8; // r3
  idEntityPtr<idEntity> *p_usedProp; // r31
  idEntity *v10; // r3
  idProp_WeaponStatic *v11; // r3
  idProp_WeaponStatic *v12; // r3
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v13; // [sp+50h] [-30h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v14; // [sp+52h] [-2Eh] BYREF

  WeaponToDraw = idAI2::FindWeaponToDraw(this: ai);
  if ( WeaponToDraw != nullptr )
  {
    v14.value = -1;
    v13.value = -1;
    idAI2::FindAnimWebAndStateIndices(
      this: ai,
      web: AIANIMWEB_BODY,
      subWeb: 1,
      stateName: "idle",
      changeWeapon: true,
      newWeapon: WeaponToDraw,
      subWebIndex: &v14,
      stateIndex: &v13);
    if ( idAI2::ChangeAnimState(
           this: ai,
           web: AIANIMWEB_BODY,
           subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v14.value,
           stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v13.value,
           interruptPath: INTR_PATH_NO,
           interruptBlend: INTR_BLEND_NO) == 1 )
      idAI2::SetAnimWebEvent(
        this: ai,
        web: AIANIMWEB_BODY,
        priority: PRIORITY_LOW,
        swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v14.value,
        si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v13.value,
        eventType: ANIMWEB_EVENT_START_BLEND_IN,
        eventDef: &EV_AnimWeb_Wait);
  }
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v7 = blendMS_0;
  v8 = ai->GetAnimStack_2(this: ai);
  idAnimator_Base::End(
    this: &ai->aiVolatile.animation.turretAnimator,
    stack: v8,
    curTime: GameMs,
    blendDurationMS: v7,
    reset: true);
  *((_BYTE *)&ai->aiEditable.death + 84) |= 0xC0u;
  idFocusInfo::SetEnableTracking(this: ai->aiVolatile.focus.foci.ptr, owner: ai, enable: true);
  idAI2::ClearLookFocus(this: ai);
  p_usedProp = &ai->aiVolatile.memory.usedProp;
  if ( gameLocal->spawnIds.ptr[p_usedProp->spawnId.value & 0x1FFF] == p_usedProp->spawnId.value >> 13
    && (v10 = gameLocal->entities.ptr[p_usedProp->spawnId.value & 0x1FFF]) != nullptr )
  {
    v11 = (idProp_WeaponStatic *)idEntity::CastTo(c: v10);
  }
  else
  {
    v11 = nullptr;
  }
  v12 = idProp_WeaponStatic::CastTo(c: v11);
  if ( v12 != nullptr )
  {
    v12->Use(this: v12, a2: nullptr, a3: USABLE_MAX);
    p_usedProp->spawnId.value = 0x1FFF;
  }
}


// ========================================================================
// ?AIState_EnterState@idCombatScenePoint_ApplyRestriction@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD0F20
// RVA : 0x00AD0F20
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void __fastcall idCombatScenePoint_ApplyRestriction::AIState_EnterState(
        idCombatScenePoint_ApplyRestriction *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  int value; // r6
  idEntity *v9; // r3
  idEntity *v10; // r4
  double leaderRange; // fp31
  idEventArg *v12; // r3
  int v13; // r9
  int v14; // r8
  idActor *v15; // r3
  idActor *v16; // r3
  idPhysics *Physics; // r3
  float *v18; // r3
  double v19; // fp13
  double v20; // fp12
  idEventArg *v21; // r29
  int v22; // r8
  idVolume_Restriction *v23; // r3
  idVolume_Restriction *v24; // r28
  float y; // r8
  float z; // r7
  float v27; // r6
  idPhysics *v28; // r3
  const idVec3 *v29; // r3
  char v30; // r24
  idScenePoint *ClosestEnterPoint; // r29
  int num; // r27
  idPhysics *v33; // r3
  const idVec3 *v34; // r3
  double v35; // fp31
  idEntityPtr<idAISearchHintGroup> *list; // r9
  idGameLocal *v37; // r11
  int v38; // r28
  int v39; // r8
  idScenePoint *v40; // r3
  idScenePoint *v41; // r3
  idPhysics *v42; // r3
  int v43; // r3
  float v44; // r7
  float v45; // r6
  idPhysics *v46; // r3
  float *v47; // r3
  int v48; // r8
  idScenePoint *v49; // r3
  idScenePoint *v50; // r3
  float *v51; // r11
  idPhysics *v52; // r3
  float v53; // r9
  float v54; // r8
  idScenePoint *v55; // r4
  int v56; // r7
  idEntity *v57; // r3
  idEntity *v58; // r4
  idEventArg *v59; // r3
  double v60; // fp10
  idEventArg *v61; // r29
  const idEventArg *v62; // [sp+8h] [-2E8h]
  const idEventArg *v63; // [sp+Ch] [-2E4h]
  const idEventArg *v64; // [sp+10h] [-2E0h]
  _BYTE v65[20]; // [sp+70h] [-280h] BYREF
  _BYTE v66[20]; // [sp+90h] [-260h] BYREF
  _BYTE v67[20]; // [sp+B0h] [-240h] BYREF
  _BYTE v68[20]; // [sp+D0h] [-220h] BYREF
  _BYTE v69[20]; // [sp+F0h] [-200h] BYREF
  idEventArg v70; // [sp+110h] [-1E0h]
  float v71[5]; // [sp+130h] [-1C0h] BYREF
  idAIEditable::idAIActionSettings::idAISquadSettings *p_squad; // [sp+144h] [-1ACh]
  float v73[8]; // [sp+150h] [-1A0h] BYREF
  idList<idEntityPtr<idAISearchHintGroup>,5> v74; // [sp+170h] [-180h] BYREF
  idEventArg v75; // [sp+180h] [-170h] BYREF
  idEventReceiver v76[8]; // [sp+1A0h] [-150h] BYREF
  idEventArg v77; // [sp+200h] [-F0h]
  idEventArg v78; // [sp+220h] [-D0h] BYREF
  idEventArg v79; // [sp+240h] [-B0h] BYREF

  if ( (unsigned __int8)idAIEditable::idAIActionSettings::HasSquadLeader(this: &ai->aiEditable.actionSettings) != 0 )
  {
    ai->aiVolatile.animation.subWeb = AISUBWEB_COMBAT;
    idAI2::SetEnableHeadTracking(this: ai, enable: true);
    value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v9 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v9 != nullptr )
      {
        v10 = idEntity::CastTo(c: v9);
        if ( v10 != nullptr )
        {
          idAI2::SetAimFocusEntity(this: ai, ent: v10, keepFocusInView: false, aimPoint: AIMPOINT_BEST, timeout: -1);
          idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
        }
      }
    }
    ai->SetWalkState(this: ai, a2: WALKSTATE_RUNNING);
    leaderRange = ai->aiEditable.actionSettings.squad.leaderRange;
    if ( leaderRange < 0.0 )
      leaderRange = 100.0;
    if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED )
    {
      v12 = idEventArg::idEventArg(this: &v75, data: ai);
      idEventReceiver::ProcessEvent(
        this: v76,
        result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
        ev: *(const idEventDef **)&v12->type,
        arg1: (const idEventArg *)LODWORD(v12->value.v[1]));
    }
    v13 = ai->aiEditable.actionSettings.squad.squadLeader.spawnId.value;
    *(float *)&v76[5].listeningToList = leaderRange;
    v77.type = 105;
    HIBYTE(v76[2].listeningToList) = 105;
    v73[1] = vec3_origin.x;
    HIBYTE(v76[0].__vftable) = 105;
    v73[2] = vec3_origin.y;
    v14 = gameLocal->spawnIds.ptr[v13 & 0x1FFF];
    v73[3] = vec3_origin.z;
    v77.value.i = 0;
    HIBYTE(v73[0]) = 118;
    v76[3].__vftable = nullptr;
    HIBYTE(v76[5].listenerList) = 102;
    v76[0].listenerList = (idList<idEventReceiver *,5> *)2;
    p_squad = &ai->aiEditable.actionSettings.squad;
    if ( v14 == v13 >> 13 && (v15 = (idActor *)gameLocal->entities.ptr[v13 & 0x1FFF]) != nullptr )
      v16 = idActor::CastTo(c: v15);
    else
      v16 = nullptr;
    Physics = idEntity::GetPhysics(this: v16);
    v18 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    HIBYTE(v71[0]) = 118;
    v75.type = 105;
    v75.value.i = 0;
    v19 = v18[1];
    v20 = v18[2];
    v71[1] = *v18;
    v71[2] = v19;
    v71[3] = v20;
    v21 = idEventArg::idEventArg(this: &v78, data: ai);
    v70 = v77;
    memcpy(Dst: v69, Src: v73, Size: sizeof(v69));
    memcpy(Dst: v68, Src: &v76[2].listeningToList, Size: sizeof(v68));
    memcpy(Dst: v67, Src: &v76[5].listenerList, Size: sizeof(v67));
    memcpy(Dst: v66, Src: v76, Size: sizeof(v66));
    memcpy(Dst: v65, Src: v71, Size: sizeof(v65));
    idEventReceiver::ProcessEvent(
      this: (idEventReceiver *)&v79,
      result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
      ev: *(const idEventDef **)&v21->type,
      arg1: (const idEventArg *)LODWORD(v21->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v21->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v75.type, 32),
      arg4: (const idEventArg *)LODWORD(v75.value.v[1]),
      arg5: (const idEventArg *)LODWORD(v75.value.v[2]),
      arg6: v62,
      arg7: v63,
      arg8: v64);
  }
  else
  {
    v22 = ai->aiVolatile.memory.restrictionVolume.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v22 & 0x1FFF] == v22 >> 13
      && (v23 = (idVolume_Restriction *)gameLocal->entities.ptr[v22 & 0x1FFF]) != nullptr )
    {
      v24 = idVolume_Restriction::CastTo(c: v23);
    }
    else
    {
      v24 = nullptr;
    }
    y = ai->aiVolatile.memory.restrictionPos.pos.y;
    z = ai->aiVolatile.memory.restrictionPos.pos.z;
    v27 = *(float *)&ai->aiVolatile.memory.restrictionPos.bValid;
    v73[0] = ai->aiVolatile.memory.restrictionPos.pos.x;
    v73[1] = y;
    v73[2] = z;
    v73[3] = v27;
    v28 = idEntity::GetPhysics(this: ai);
    v29 = v28->GetOrigin(this: v28, a2: 0);
    v30 = HIBYTE(v73[3]);
    ClosestEnterPoint = (idScenePoint *)idVolume_Restriction::GetClosestEnterPoint(this: v24, comparePos: v29);
    if ( ClosestEnterPoint != nullptr || HIBYTE(v73[3]) != 0 )
    {
      ai->aiVolatile.memory.restrictionStopOnEnter = false;
    }
    else
    {
      idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&v74);
      idAIMemory::GetScenePoints(this: &ai->aiVolatile.memory, spList: &v74, spType: (scenePointType_t)4);
      num = v74.num;
      if ( v74.num <= 0 )
      {
        v33 = idEntity::GetPhysics(this: ai);
        v34 = v33->GetOrigin(this: v33, a2: 0);
        if ( !idVolume_ItemGroup::Contains(this: v24, pos: v34) )
        {
          idLib::Warning(
            fmt: "Restriction volume error! No enter points, nor any scenepoints within. AI can't find it's way inside! Volume: %s AI: %s",
            v24->name.data,
            ai->name.data);
          idState::SetEnterFailed(this, failed: true);
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v74);
          return;
        }
      }
      ClosestEnterPoint = nullptr;
      v35 = -1.0;
      if ( num > 0 )
      {
        list = v74.list;
        v37 = gameLocal;
        v38 = 0;
        do
        {
          v39 = list[v38].spawnId.value;
          p_squad = (idAIEditable::idAIActionSettings::idAISquadSettings *)&list[v38];
          if ( v37->spawnIds.ptr[v39 & 0x1FFF] == v39 >> 13 )
          {
            v40 = (idScenePoint *)v37->entities.ptr[v39 & 0x1FFF];
            if ( v40 != nullptr )
              v41 = idScenePoint::CastTo(c: v40);
            else
              v41 = nullptr;
          }
          else
          {
            v41 = nullptr;
          }
          v42 = idEntity::GetPhysics(this: v41);
          v43 = (int)v42->GetOrigin(this: v42, a2: 0);
          v44 = *(float *)(v43 + 4);
          v45 = *(float *)(v43 + 8);
          v71[0] = *(float *)v43;
          v71[1] = v44;
          v71[2] = v45;
          v46 = idEntity::GetPhysics(this: ai);
          v47 = (float *)v46->GetOrigin(this: v46, a2: 0);
          if ( v35 >= 0.0
            && (float)((float)((float)(v71[2] - v47[2]) * (float)(v71[2] - v47[2]))
                     + (float)((float)((float)(v71[0] - *v47) * (float)(v71[0] - *v47))
                             + (float)((float)(v71[1] - v47[1]) * (float)(v71[1] - v47[1])))) >= v35 )
          {
            list = v74.list;
            v37 = gameLocal;
          }
          else
          {
            list = v74.list;
            v35 = (float)((float)((float)(v71[2] - v47[2]) * (float)(v71[2] - v47[2]))
                        + (float)((float)((float)(v71[0] - *v47) * (float)(v71[0] - *v47))
                                + (float)((float)(v71[1] - v47[1]) * (float)(v71[1] - v47[1]))));
            v37 = gameLocal;
            p_squad = (idAIEditable::idAIActionSettings::idAISquadSettings *)&v74.list[v38];
            v48 = v74.list[v38].spawnId.value;
            if ( gameLocal->spawnIds.ptr[v48 & 0x1FFF] == v48 >> 13
              && (v49 = (idScenePoint *)gameLocal->entities.ptr[v48 & 0x1FFF]) != nullptr )
            {
              v50 = idScenePoint::CastTo(c: v49);
              list = v74.list;
              v37 = gameLocal;
              ClosestEnterPoint = v50;
            }
            else
            {
              ClosestEnterPoint = nullptr;
            }
          }
          --num;
          ++v38;
        }
        while ( num != 0 );
      }
      ai->aiVolatile.memory.restrictionStopOnEnter = true;
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v74);
    }
    if ( v30 != 0 )
    {
      v51 = v73;
    }
    else
    {
      v52 = idEntity::GetPhysics(this: ClosestEnterPoint);
      v51 = (float *)v52->GetOrigin(this: v52, a2: 0);
    }
    v53 = v51[1];
    v54 = v51[2];
    v71[0] = *v51;
    v71[1] = v53;
    v71[2] = v54;
    v55 = idScenePoint::CastTo(c: ClosestEnterPoint);
    if ( v55 != nullptr )
      idAIMemory::SetOverrideScenePoint(this: &ai->aiVolatile.memory, scenePoint: v55);
    ai->aiVolatile.animation.subWeb = AISUBWEB_COMBAT;
    v56 = ai->aiVolatile.memory.currentEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v56 & 0x1FFF] == v56 >> 13 )
    {
      v57 = gameLocal->entities.ptr[v56 & 0x1FFF];
      if ( v57 != nullptr )
      {
        v58 = idEntity::CastTo(c: v57);
        if ( v58 != nullptr )
        {
          idAI2::SetAimFocusEntity(this: ai, ent: v58, keepFocusInView: false, aimPoint: AIMPOINT_BEST, timeout: -1);
          idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
        }
      }
    }
    ai->SetWalkState(this: ai, a2: WALKSTATE_RUNNING);
    if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED )
    {
      v59 = idEventArg::idEventArg(this: &v79, data: ai);
      idEventReceiver::ProcessEvent(
        this: (idEventReceiver *)&v78,
        result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
        ev: *(const idEventDef **)&v59->type,
        arg1: (const idEventArg *)LODWORD(v59->value.v[1]));
    }
    v60 = v71[2];
    v71[2] = v71[1];
    v71[1] = v71[0];
    v73[1] = vec3_origin.x;
    v75.type = 105;
    v73[2] = vec3_origin.y;
    v75.value.i = 0;
    v73[3] = vec3_origin.z;
    *(float *)&v76[5].listeningToList = 16.0;
    HIBYTE(v73[0]) = 118;
    v71[3] = v60;
    HIBYTE(v76[0].__vftable) = 105;
    v76[0].listenerList = nullptr;
    HIBYTE(v76[5].listenerList) = 102;
    HIBYTE(v76[2].listeningToList) = 105;
    v76[3].__vftable = (idEventReceiver_vtbl *)2;
    HIBYTE(v71[0]) = 118;
    v77.type = 105;
    v77.value.i = 0;
    v61 = idEventArg::idEventArg(this: &v79, data: ai);
    v70 = v75;
    memcpy(Dst: v69, Src: v73, Size: sizeof(v69));
    memcpy(Dst: v68, Src: v76, Size: sizeof(v68));
    memcpy(Dst: v67, Src: &v76[5].listenerList, Size: sizeof(v67));
    memcpy(Dst: v66, Src: &v76[2].listeningToList, Size: sizeof(v66));
    memcpy(Dst: v65, Src: v71, Size: sizeof(v65));
    idEventReceiver::ProcessEvent(
      this: (idEventReceiver *)&v78,
      result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
      ev: *(const idEventDef **)&v61->type,
      arg1: (const idEventArg *)LODWORD(v61->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v61->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v77.type, 32),
      arg4: (const idEventArg *)LODWORD(v77.value.v[1]),
      arg5: (const idEventArg *)LODWORD(v77.value.v[2]),
      arg6: v62,
      arg7: v63,
      arg8: v64);
  }
  idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
}


// ========================================================================
// __unwind$496772
// EA  : 0x82AD17EC
// RVA : 0x00AD17EC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

void _unwind_496772()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 752 + 368));
}


// ========================================================================
// ?CanUse@idCombatScenePointFSM@@UBA_NPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AD1818
// RVA : 0x00AD1818
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.cpp
// ========================================================================

int __fastcall idCombatScenePointFSM::CanUse(idCombatScenePointFSM *this, idFiniteStateMachine *fsm, const int curTime)
{
  idAI2 *Owner; // r30
  int result; // r3
  idScenePoint *curScenePoint; // r11
  char v7; // r10
  char v8; // r11
  bool v9; // zf
  const aiSenseState_t *EnemySenseState; // r3
  int lastConfirmedStimTime; // r11

  Owner = (idAI2 *)idFiniteStateMachine::GetOwner(this: fsm);
  if ( (unsigned __int8)idAI2::UsesScenePoints(this: Owner) == 0 )
    return 0;
  if ( (unsigned __int8)idAIMemory::HasOverrideScriptScenePointOfType(
                          this: &Owner->aiVolatile.memory,
                          spType: (scenePointType_t)4) != 0 )
    return 1;
  curScenePoint = Owner->aiVolatile.memory.curScenePoint;
  if ( curScenePoint == nullptr
    || (*(_BYTE *)&curScenePoint->flags & 8) == 0
    || (v7 = 1, (curScenePoint->scriptFlags & 1) == 0) )
  {
    v7 = 0;
  }
  if ( v7 != 0 )
  {
    if ( curScenePoint == nullptr || (v9 = curScenePoint->type == 4, v8 = 1, !v9) )
      v8 = 0;
    if ( v8 != 0 )
      return 1;
  }
  if ( (unsigned __int8)idAIEditable::idAIActionSettings::HasSquadLeader(this: &Owner->aiEditable.actionSettings) != 0 )
    return 1;
  if ( !idAI2::AwareOfEnemy(this: Owner) )
    return 0;
  if ( Owner->aiEditable.perception.combatTimeoutInterval < 0.0 )
    return 1;
  EnemySenseState = idAI2::GetEnemySenseState(this: Owner, senseType: AISENSE_MAX);
  if ( EnemySenseState == nullptr )
    return 1;
  lastConfirmedStimTime = EnemySenseState->lastConfirmedStimTime;
  if ( lastConfirmedStimTime <= 0 )
    return 1;
  result = 0;
  if ( curTime - lastConfirmedStimTime <= (int)(float)((float)1000.0 * Owner->aiEditable.perception.combatTimeoutInterval) )
    return 1;
  return result;
}

