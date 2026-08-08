
// ========================================================================
// ?Evaluate@ADVANCE_MoveFailedAny@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB49A8
// RVA : 0x00AB49A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

int __fastcall ADVANCE_MoveFailedAny::Evaluate(
        ADVANCE_MoveFailedAny *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3

  MoveInterface = idAI2::GetMoveInterface(this: ai);
  return __CFADD__(MoveInterface->GetMoveStatus(this: MoveInterface) - 2, -2147483646) ? 0 : 9;
}


// ========================================================================
// ?Evaluate@ADVANCE_MeleeFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB49F8
// RVA : 0x00AB49F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

int __fastcall ADVANCE_MeleeFinished::Evaluate(
        ADVANCE_MeleeFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  return idFile_SaveGamePipelined::GetFullPath(this: state) != 0 ? 0 : 0x184;
}


// ========================================================================
// ?InternalInitState@idAdvance_AttackMelee@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB4A30
// RVA : 0x00AB4A30
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_AttackMelee::InternalInitState(idAdvance_AttackMelee *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_MeleeFinished::Type,
    nextStateType: &idAdvance_Default::Type);
}


// ========================================================================
// ?InternalInitState@idAdvance_Default@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB4A48
// RVA : 0x00AB4A48
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_Default::InternalInitState(idAdvance_Default *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &ADVANCE_ShouldRage::Type, nextStateType: &idAdvance_Rage::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldBackStand::Type,
    nextStateType: &idAdvance_BackStand::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldMelee::Type,
    nextStateType: &idAdvance_AttackMelee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldThrowProjectile::Type,
    nextStateType: &idAdvance_ThrowProjectile::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldLeapAttack::Type,
    nextStateType: &idAdvance_LeapAttack::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldMoveTowardsEnemy::Type,
    nextStateType: &idAdvance_MoveTowardsEnemy::Type,
    transCode: 361);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldMoveTowardsEnemy::Type,
    nextStateType: &idAdvance_MoveTowardsValidEnemyPos::Type,
    transCode: 362);
  idState::AddStateTransition(this, fsm, transType: &ADVANCE_ShouldWait::Type, nextStateType: &idAdvance_Wait::Type);
}


// ========================================================================
// ?InternalInitState@idAdvance_Wait@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB4B48
// RVA : 0x00AB4B48
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_Wait::InternalInitState(idAdvance_Wait *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &ADVANCE_ShouldRage::Type, nextStateType: &idAdvance_Rage::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldMelee::Type,
    nextStateType: &idAdvance_AttackMelee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldThrowProjectile::Type,
    nextStateType: &idAdvance_ThrowProjectile::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldLeapAttack::Type,
    nextStateType: &idAdvance_LeapAttack::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldMoveTowardsEnemy::Type,
    nextStateType: &idAdvance_MoveTowardsEnemy::Type,
    transCode: 361);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldMoveTowardsEnemy::Type,
    nextStateType: &idAdvance_MoveTowardsValidEnemyPos::Type,
    transCode: 362);
}


// ========================================================================
// ?InternalInitState@idAdvance_MoveTowardsEnemy@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB4C10
// RVA : 0x00AB4C10
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_MoveTowardsEnemy::InternalInitState(
        idAdvance_MoveTowardsEnemy *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &ADVANCE_ShouldRage::Type, nextStateType: &idAdvance_Rage::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldMelee::Type,
    nextStateType: &idAdvance_AttackMelee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldBackStand::Type,
    nextStateType: &idAdvance_BackStand::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_MoveFailed::Type,
    nextStateType: &idAdvance_MoveFailedStop::Type);
  idState::AddStateTransition(this, fsm, transType: &ADVANCE_AdvanceDone::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_MoveTowardsEnemyDone::Type,
    nextStateType: &idAIStateDone::Type,
    transCode: 394);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_MoveTowardsEnemyDone::Type,
    nextStateType: &idAdvance_Default::Type,
    transCode: 365);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldLeapAttack::Type,
    nextStateType: &idAdvance_LeapAttack::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldThrowProjectile::Type,
    nextStateType: &idAdvance_ThrowProjectile::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldMoveTowardsEnemy::Type,
    nextStateType: &idAdvance_MoveTowardsValidEnemyPos::Type,
    transCode: 362);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_MoveFailedAny::Type,
    nextStateType: &idAdvance_MoveFailedStop::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldSideStep::Type,
    nextStateType: &idAdvance_SideStep::Type);
}


// ========================================================================
// ?InternalInitState@idAdvance_MoveTowardsValidEnemyPos@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB4D80
// RVA : 0x00AB4D80
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_MoveTowardsValidEnemyPos::InternalInitState(
        idAdvance_MoveTowardsValidEnemyPos *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &ADVANCE_ShouldRage::Type, nextStateType: &idAdvance_Rage::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldMelee::Type,
    nextStateType: &idAdvance_AttackMelee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldBackStand::Type,
    nextStateType: &idAdvance_BackStand::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_MoveFailed::Type,
    nextStateType: &idAdvance_MoveFailedStop::Type);
  idState::AddStateTransition(this, fsm, transType: &ADVANCE_AdvanceDone::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_MoveTowardsEnemyDone::Type,
    nextStateType: &idAIStateDone::Type,
    transCode: 394);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_MoveTowardsEnemyDone::Type,
    nextStateType: &idAdvance_Default::Type,
    transCode: 365);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldLeapAttack::Type,
    nextStateType: &idAdvance_LeapAttack::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldThrowProjectile::Type,
    nextStateType: &idAdvance_ThrowProjectile::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldMoveTowardsEnemy::Type,
    nextStateType: &idAdvance_MoveTowardsEnemy::Type,
    transCode: 361);
  idState::AddStateTransition(this, fsm, transType: &ADVANCE_ShouldWait::Type, nextStateType: &idAdvance_Wait::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_MoveFailedAny::Type,
    nextStateType: &idAdvance_MoveFailedStop::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldSideStep::Type,
    nextStateType: &idAdvance_SideStep::Type);
}


// ========================================================================
// ?InternalInitState@idAdvance_SideStep@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB4F10
// RVA : 0x00AB4F10
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_SideStep::InternalInitState(idAdvance_SideStep *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_SideStepFailed::Type,
    nextStateType: &idAdvance_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_SideStepDone::Type,
    nextStateType: &idAdvance_Default::Type);
}


// ========================================================================
// ?AIState_EnterState@idAdvance_SideStep@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB4F60
// RVA : 0x00AB4F60
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_SideStep::AIState_EnterState(
        idAdvance_SideStep *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idAI2::SetupDiveDodgeOrFlinchAction(this: ai, moveReason: 12, state: this, fsm);
}


// ========================================================================
// ?InternalInitState@idAdvance_LeapAttack@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB4F78
// RVA : 0x00AB4F78
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_LeapAttack::InternalInitState(idAdvance_LeapAttack *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_LeapAttackFailed::Type,
    nextStateType: &idAdvance_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_LeapAttackDone::Type,
    nextStateType: &idAdvance_Default::Type);
}


// ========================================================================
// ?InternalInitState@idAdvance_SneakUpOnEnemy@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB4FC8
// RVA : 0x00AB4FC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_SneakUpOnEnemy::InternalInitState(
        idAdvance_SneakUpOnEnemy *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_SneakUpOnEnemyFailed::Type,
    nextStateType: &idAdvance_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_SneakUpOnEnemyDone::Type,
    nextStateType: &idAdvance_Default::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &ADVANCE_ShouldSideStep::Type,
    nextStateType: &idAdvance_SideStep::Type);
}


// ========================================================================
// ?Evaluate@ADVANCE_ThrowProjectileFailed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB5030
// RVA : 0x00AB5030
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall ADVANCE_ThrowProjectileFailed::Evaluate(
        ADVANCE_ThrowProjectileFailed *this,
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
  result = TRANSCODE_ADVANCE_THROW_PROJECTILE_FAILED;
  if ( !v7 )
    return 0;
  return result;
}


// ========================================================================
// ?InternalInitState@idAdvance_ThrowProjectile@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB5078
// RVA : 0x00AB5078
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_ThrowProjectile::InternalInitState(
        idAdvance_ThrowProjectile *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ThrowProjectileDone::Type,
    nextStateType: &idAdvance_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_ThrowProjectileFailed::Type,
    nextStateType: &idAdvance_Default::Type);
}


// ========================================================================
// ?InternalInitState@idAdvance_Rage@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB50C8
// RVA : 0x00AB50C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_Rage::InternalInitState(idAdvance_Rage *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &ADVANCE_RageDone::Type, nextStateType: &idAdvance_Default::Type);
}


// ========================================================================
// ?Evaluate@ADVANCE_ShouldBackStand@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB50E0
// RVA : 0x00AB50E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

idDecl *__fastcall ADVANCE_ShouldBackStand::Evaluate(
        ADVANCE_ShouldBackStand *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idDecl *result; // r3

  result = (idDecl *)idFiniteStateMachine::FindState(this: parentFSM, stateType: &idAdvance_BackStand::Type);
  if ( result != nullptr )
    return (unsigned __int8)idState::CanUse(this: result) == 0 ? nullptr : (idDecl *)0x20;
  return result;
}


// ========================================================================
// ?Evaluate@ADVANCE_BackStandDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB5150
// RVA : 0x00AB5150
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall ADVANCE_BackStandDone::Evaluate(
        ADVANCE_BackStandDone *this,
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
    return TRANSCODE_MAX;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_MAX;
  return result;
}


// ========================================================================
// ?InternalInitState@idAdvance_BackStand@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB5198
// RVA : 0x00AB5198
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_BackStand::InternalInitState(idAdvance_BackStand *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_BackStandDone::Type,
    nextStateType: &idAdvance_Default::Type);
}


// ========================================================================
// ?InternalInitState@idAdvance_PlayOverrideAnim@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB51B0
// RVA : 0x00AB51B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_PlayOverrideAnim::InternalInitState(
        idAdvance_PlayOverrideAnim *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_PlayOverrideAnimDone::Type,
    nextStateType: &idAdvance_Default::Type);
}


// ========================================================================
// ?Evaluate@ADVANCE_MoveFailedStopDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB51C8
// RVA : 0x00AB51C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

int __fastcall ADVANCE_MoveFailedStopDone::Evaluate(
        ADVANCE_MoveFailedStopDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 395;
}


// ========================================================================
// ?InternalInitState@idAdvance_MoveFailedStop@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AB51D0
// RVA : 0x00AB51D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_MoveFailedStop::InternalInitState(
        idAdvance_MoveFailedStop *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ADVANCE_MoveFailedStopDone::Type,
    nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InitStates@idAdvanceFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82AB51E8
// RVA : 0x00AB51E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvanceFSM::InitStates(idAdvanceFSM *this, const idFiniteStateMachineParams *params)
{
  idAIFSM::InitStates(this, params);
  this->AddState(this, a2: &this->stateDefault);
  this->AddState(this, a2: &this->stateMoveTowardsEnemy);
  this->AddState(this, a2: &this->stateMoveTowardsValidEnemyPos);
  this->AddState(this, a2: &this->stateSideStep);
  this->AddState(this, a2: &this->stateLeapAttack);
  this->AddState(this, a2: &this->stateSneakUpOnEnemy);
  this->AddState(this, a2: &this->stateThrowProjectile);
  this->AddState(this, a2: &this->stateAttackMelee);
  this->AddState(this, a2: &this->stateRage);
  this->AddState(this, a2: &this->stateBackStand);
  this->AddState(this, a2: &this->statePlayOverrideAnim);
  this->AddState(this, a2: &this->stateWait);
  this->AddState(this, a2: &this->stateMoveFailedStop);
}


// ========================================================================
// DontLeapAttackBecause
// EA  : 0x82AB5350
// RVA : 0x00AB5350
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall DontLeapAttackBecause(idAI2 *ai, char *txt)
{
  idPhysics *Physics; // r31
  idRenderWorld *v4; // r29
  idPhysics *v5; // r3
  idRenderWorld_vtbl *v6; // r31
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v8; // r3

  if ( ai_debugLeapAttack.valueInteger != 0 && ai_debugLevel.valueInteger > 0 )
  {
    Physics = idEntity::GetPhysics(this: ai);
    v4 = common->RW(this: common);
    v5 = Physics;
    GetOrigin = Physics->GetOrigin;
    v6 = v4->__vftable;
    v8 = (int)GetOrigin(this: v5, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, char *, int, enum idAIStateTransition::aiTransCode_t (__fastcall **)(COMBAT_AtPlugAnim *__hidden, struct idAI2 *, struct idAIFSM *, struct idAIState *, int), idColor *, int, int, _DWORD, double))v6->DebugText)(
      a1: v4,
      a2: txt,
      a3: v8,
      a4: &off_82040000,
      a5: &idColor::colorMagenta,
      a6: 1,
      a7: 16,
      a8: 0,
      a9: 0.2);
  }
  return 0;
}


// ========================================================================
// ?Evaluate@TC_ShouldDodge@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB5410
// RVA : 0x00AB5410
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall TC_ShouldDodge::Evaluate(
        ADVANCE_ShouldSideStep *this,
        idAI2 *ai,
        idOpenCombatFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIStateTransition::aiTransCode_t result; // r3

  result = idAI2::ShouldDiveOrDodgeOrCrouch(this: ai, parentFSM);
  ai->aiVolatile.memory.transCode = result;
  return result;
}


// ========================================================================
// ?Evaluate@ADVANCE_ShouldRage@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB5450
// RVA : 0x00AB5450
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

int __fastcall ADVANCE_ShouldRage::Evaluate(
        ADVANCE_ShouldRage *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3
  aiSenseState_t *EnemySenseState; // r3
  aiSenseState_t *v8; // r28
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  float y; // r9
  float z; // r8
  idPhysics *Physics; // r3
  float *v13; // r3
  double v14; // fp29
  double v15; // fp31
  double v16; // fp30
  idPresentable *presentable; // r11
  const idDeclAIBehavior *decl; // r29
  double v19; // fp6
  double v20; // fp31
  double v21; // fp30
  double v22; // fp29
  const aiPhysicalState_t *v23; // r3
  unsigned int v24; // r4
  int GameMs; // r3
  idVec3 v27; // [sp+50h] [-60h] BYREF
  idVec3 v28; // [sp+60h] [-50h]

  if ( (unsigned __int8)idAI2::HasTauntRage(this: ai) == 0 && (unsigned __int8)idAI2::HasAngryRage(this: ai) == 0 )
    return 0;
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  if ( MoveInterface->IsPlayingTraversalAnim(this: MoveInterface) )
    return 0;
  EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  v8 = EnemySenseState;
  if ( EnemySenseState == nullptr )
    return 0;
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
  y = ConfirmedPhysicalSafe->origin.y;
  z = ConfirmedPhysicalSafe->origin.z;
  v28.x = ConfirmedPhysicalSafe->origin.x;
  v28.y = y;
  v28.z = z;
  Physics = idEntity::GetPhysics(this: ai);
  v13 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v14 = (float)(v28.z - v13[2]);
  v15 = (float)(v28.x - *v13);
  v28.z = v28.z - v13[2];
  v28.x = v15;
  v16 = (float)(v28.y - v13[1]);
  v28.y = v28.y - v13[1];
  v27 = v28;
  idVec3::NormalizeFast(this: &v27);
  presentable = ai->presentable;
  decl = ai->aiEditable.behaviors.decl;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: ai);
    presentable = ai->presentable;
  }
  if ( (float)((float)(v27.x * presentable->axis.mat[0].x)
             + (float)((float)(presentable->axis.mat[0].y * v27.y) + (float)(presentable->axis.mat[0].z * v27.z))) < (double)decl->rageBehaviors.minRageFacingDot )
    return 0;
  v19 = (float)((float)(UNITS_PER_INCH_7 * (float)15.0) * (float)12.0);
  if ( (float)((float)((float)v15 * (float)v15)
             + (float)((float)((float)v14 * (float)v14) + (float)((float)v16 * (float)v16))) < (double)(float)((float)v19 * (float)v19) )
  {
    v20 = -v27.x;
    v21 = -v27.y;
    v22 = -v27.z;
    v23 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v8);
    if ( (float)((float)((float)v20 * v23->viewfwd.x)
               + (float)((float)(v23->viewfwd.z * (float)v22) + (float)(v23->viewfwd.y * (float)v21))) < 0.5 )
    {
      v24 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v24;
      if ( (signed int)(((v24 >> 10) & 0x7FFF) % 0x64) < decl->rageBehaviors.tauntRageBehindEnemyChance )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idAIMemory::SetWantTauntRageTime(this: &ai->aiVolatile.memory, t: GameMs, debugReason: "behind enemy");
      }
    }
  }
  if ( (unsigned __int8)idAI2::WantsToTauntRage(this: ai) != 0
    && (unsigned __int8)idAI2::EnemyTooCloseToGoProne(this: ai, facingMatters: true, obscurityMatters: false) == 0 )
  {
    ai->aiVolatile.memory.transCode = TRANSCODE_ADVANCE_SHOULD_TAUNT_RAGE;
    return 390;
  }
  if ( (unsigned __int8)idAI2::WantsToAngryRage(this: ai) == 0
    || (unsigned __int8)idAI2::EnemyTooCloseToGoProne(this: ai, facingMatters: true, obscurityMatters: false) != 0 )
  {
    return 0;
  }
  ai->aiVolatile.memory.transCode = TRANSCODE_ADVANCE_SHOULD_ANGRY_RAGE;
  return 389;
}


// ========================================================================
// ?AIState_EnterState@idAdvance_Wait@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB5768
// RVA : 0x00AB5768
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_Wait::AIState_EnterState(idAdvance_Wait *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  idEventArg *v8; // r25
  _BYTE v9[20]; // [sp+70h] [-E0h] BYREF
  _DWORD v10[5]; // [sp+90h] [-C0h] BYREF
  int v11; // [sp+B0h] [-A0h]
  int v12; // [sp+B4h] [-9Ch]
  idEventArg v13; // [sp+D0h] [-80h] BYREF
  idEventReceiver v14[8]; // [sp+F0h] [-60h] BYREF

  HIBYTE(v10[0]) = 105;
  HIBYTE(v11) = 105;
  v10[1] = 1;
  v12 = -1;
  v8 = idEventArg::idEventArg(this: &v13, data: ai);
  memcpy(Dst: v9, Src: v10, Size: sizeof(v9));
  idEventReceiver::ProcessEvent(
    this: v14,
    result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
    ev: *(const idEventDef **)&v8->type,
    arg1: (const idEventArg *)LODWORD(v8->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v8->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v11, 32));
  idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
}


// ========================================================================
// CloseRageHelper
// EA  : 0x82AB5818
// RVA : 0x00AB5818
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall CloseRageHelper(idAI2 *ai, int curTime)
{
  idVec3 *v4; // r4
  aiSenseState_t *EnemySenseState; // r3
  idPhysics *Physics; // r3
  float *v7; // r3
  float v8; // [sp+50h] [-30h]
  float v9; // [sp+54h] [-2Ch]
  float v10; // [sp+58h] [-28h]

  EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  if ( EnemySenseState != nullptr )
  {
    aiSenseState_t::ExtrapolatePosition(this: EnemySenseState, seconds: 0.5, futurePos: v4);
    Physics = idEntity::GetPhysics(this: ai);
    v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    if ( (float)((float)((float)(v8 - *v7) * (float)(v8 - *v7))
               + (float)((float)((float)(v10 - v7[2]) * (float)(v10 - v7[2]))
                       + (float)((float)(v9 - v7[1]) * (float)(v9 - v7[1])))) < (double)(float)(ai->aiEditable.behaviors.decl->rageBehaviors.angryRageWhenCloseDistance
                                                                                              * ai->aiEditable.behaviors.decl->rageBehaviors.angryRageWhenCloseDistance) )
      idAIMemory::SetWantAngryRageTime(this: &ai->aiVolatile.memory, t: curTime, debugReason: "close");
  }
}


// ========================================================================
// ?AIState_ExitState@idAdvance_MoveTowardsValidEnemyPos@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB58E8
// RVA : 0x00AB58E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_MoveTowardsValidEnemyPos::AIState_ExitState(
        idAdvance_MoveTowardsValidEnemyPos *this,
        _exception *ai,
        idAIFSM *fsm,
        const int curTime)
{
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 )
    LODWORD(ai[596].retval) &= 0xFFFFEF7F;
}


// ========================================================================
// ?AIState_Work@idAdvance_MoveTowardsValidEnemyPos@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB5940
// RVA : 0x00AB5940
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_MoveTowardsValidEnemyPos::AIState_Work(
        idAdvance_MoveTowardsValidEnemyPos *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  aiSenseState_t *EnemySenseState; // r30
  idPhysics *Physics; // r3

  CloseRageHelper(ai, curTime);
  EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  if ( EnemySenseState != nullptr )
  {
    Physics = idEntity::GetPhysics(this: ai);
    Physics->GetOrigin(this: Physics, a2: 0);
    aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
  }
}


// ========================================================================
// ?Evaluate@ADVANCE_SideStepDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB59B8
// RVA : 0x00AB59B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

int __fastcall ADVANCE_SideStepDone::Evaluate(
        ADVANCE_SideStepDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x173;
}


// ========================================================================
// ?Evaluate@ADVANCE_SneakUpOnEnemyFailed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB59F8
// RVA : 0x00AB59F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall ADVANCE_SneakUpOnEnemyFailed::Evaluate(
        ADVANCE_SneakUpOnEnemyFailed *this,
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
    return TRANSCODE_ADVANCE_SNEAK_UP_ON_ENEMY_FAILED;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_ADVANCE_SNEAK_UP_ON_ENEMY_FAILED;
  return result;
}


// ========================================================================
// ?Evaluate@ADVANCE_RageDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB5A40
// RVA : 0x00AB5A40
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

int __fastcall ADVANCE_RageDone::Evaluate(
        ADVANCE_RageDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x187;
}


// ========================================================================
// ?AIState_CanUse@idAdvance_BackStand@@UBA_NPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB5A80
// RVA : 0x00AB5A80
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

idFiniteStateMachine *__fastcall idAdvance_BackStand::AIState_CanUse(
        idAdvance_BackStand *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idFiniteStateMachine *result; // r3

  result = fsm->manager->FindFSM_3(this: fsm->manager, a2: &idBackStandFSM::Type);
  if ( result != nullptr )
    return (idFiniteStateMachine *)result->CanUse(this: result, a2: fsm, a3: curTime);
  return result;
}


// ========================================================================
// ?Evaluate@ADVANCE_PlayOverrideAnimDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB5AF0
// RVA : 0x00AB5AF0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

int __fastcall ADVANCE_PlayOverrideAnimDone::Evaluate(
        ADVANCE_PlayOverrideAnimDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x188;
}


// ========================================================================
// ?AIState_EnterState@idAdvance_PlayOverrideAnim@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB5B38
// RVA : 0x00AB5B38
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_PlayOverrideAnim::AIState_EnterState(
        idAdvance_PlayOverrideAnim *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  const idDeclAIBehavior *decl; // r26
  overrideAnim_t EntranceAnim; // r28
  BOOL v9; // r7
  idEventArg *v10; // r27
  idEventArg *v11; // r3
  _BYTE v12[20]; // [sp+70h] [-100h] BYREF
  _DWORD v13[5]; // [sp+90h] [-E0h] BYREF
  int v14; // [sp+B0h] [-C0h]
  char *data; // [sp+B4h] [-BCh]
  idEventArg v16; // [sp+D0h] [-A0h] BYREF
  idEventArg v17; // [sp+F0h] [-80h] BYREF
  idStr v18[3]; // [sp+110h] [-60h] BYREF

  decl = ai->aiEditable.behaviors.decl;
  EntranceAnim = idAI2::GetEntranceAnim(this: ai);
  if ( EntranceAnim != ANIMOVERRIDE_NONE )
  {
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    data = (char *)EntranceAnim;
    HIBYTE(v14) = 105;
    v11 = idEventArg::idEventArg(this: &v17, data: ai);
    idEventReceiver::ProcessEvent(
      this: (idEventReceiver *)&v16,
      result: fsm,
      ev: *(const idEventDef **)&v11->type,
      arg1: (const idEventArg *)LODWORD(v11->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v11->value.v[2]));
  }
  else
  {
    idAI2::GetEntranceAnimWebPath(this: (idAI2 *)v18, result: (idAnimWebPath *)ai);
    if ( v18[0].len != 0
      || (idLib::Warning(fmt: "FSM_Advance::PlayOverrideAnim for %s missing animation specification", ai->name.data),
          v18[0].len != 0) )
    {
      idAI2::EndActionScript(this: ai);
      LODWORD(fsm[1].value.v[2]) = this;
      v9 = (*((_BYTE *)decl + 196) & 0x20) != 0;
      HIBYTE(v13[0]) = 105;
      HIBYTE(v14) = 49;
      v13[1] = v9;
      data = v18[0].data;
      v10 = idEventArg::idEventArg(this: &v16, data: ai);
      memcpy(Dst: v12, Src: v13, Size: sizeof(v12));
      idEventReceiver::ProcessEvent(
        this: (idEventReceiver *)&v17,
        result: fsm,
        ev: *(const idEventDef **)&v10->type,
        arg1: (const idEventArg *)LODWORD(v10->value.v[1]),
        arg2: (const idEventArg *)LODWORD(v10->value.v[2]),
        arg3: (const idEventArg *)__ROL4__(v14, 32));
    }
    idStr::FreeData(this: v18);
  }
}


// ========================================================================
// __unwind$489967
// EA  : 0x82AB5CA0
// RVA : 0x00AB5CA0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_489967()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 272));
}


// ========================================================================
// ?AIState_EnterState@idAdvance_MoveFailedStop@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB5CC8
// RVA : 0x00AB5CC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_MoveFailedStop::AIState_EnterState(
        idAdvance_MoveFailedStop *this,
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
  v11 = 300;
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
// ??0idAdvanceFSM@@QAA@XZ
// EA  : 0x82AB5D78
// RVA : 0x00AB5D78
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

idAdvanceFSM *__fastcall idAdvanceFSM::idAdvanceFSM(idAdvanceFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: "FSM_advance");
  this->__vftable = (idAdvanceFSM_vtbl *)&idAdvanceFSM::`vftable';
  idState::idState(this: &this->stateDefault, stateType: &idAdvance_Default::Type, childFSMType: nullptr, flags: 0);
  this->stateDefault.__vftable = (idAdvance_Default_vtbl *)&idAdvance_Default::`vftable';
  idState::idState(
    this: &this->stateMoveTowardsEnemy,
    stateType: &idAdvance_MoveTowardsEnemy::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveTowardsEnemy.__vftable = (idAdvance_MoveTowardsEnemy_vtbl *)&idAdvance_MoveTowardsEnemy::`vftable';
  idState::idState(
    this: &this->stateMoveTowardsValidEnemyPos,
    stateType: &idAdvance_MoveTowardsValidEnemyPos::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveTowardsValidEnemyPos.__vftable = (idAdvance_MoveTowardsValidEnemyPos_vtbl *)&idAdvance_MoveTowardsValidEnemyPos::`vftable';
  idState::idState(this: &this->stateSideStep, stateType: &idAdvance_SideStep::Type, childFSMType: nullptr, flags: 0);
  this->stateSideStep.__vftable = (idAdvance_SideStep_vtbl *)&idAdvance_SideStep::`vftable';
  idState::idState(
    this: &this->stateLeapAttack,
    stateType: &idAdvance_LeapAttack::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateLeapAttack.__vftable = (idAdvance_LeapAttack_vtbl *)&idAdvance_LeapAttack::`vftable';
  idState::idState(
    this: &this->stateSneakUpOnEnemy,
    stateType: &idAdvance_SneakUpOnEnemy::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateSneakUpOnEnemy.__vftable = (idAdvance_SneakUpOnEnemy_vtbl *)&idAdvance_SneakUpOnEnemy::`vftable';
  idState::idState(
    this: &this->stateThrowProjectile,
    stateType: &idAdvance_ThrowProjectile::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateThrowProjectile.__vftable = (idAdvance_ThrowProjectile_vtbl *)&idAdvance_ThrowProjectile::`vftable';
  idState::idState(
    this: &this->stateAttackMelee,
    stateType: &idAdvance_AttackMelee::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateAttackMelee.__vftable = (idAdvance_AttackMelee_vtbl *)&idAdvance_AttackMelee::`vftable';
  idState::idState(this: &this->stateRage, stateType: &idAdvance_Rage::Type, childFSMType: nullptr, flags: 0);
  this->stateRage.__vftable = (idAdvance_Rage_vtbl *)&idAdvance_Rage::`vftable';
  idState::idState(
    this: &this->stateBackStand,
    stateType: &idAdvance_BackStand::Type,
    childFSMType: &idBackStandFSM::Type,
    flags: 0);
  this->stateBackStand.__vftable = (idAdvance_BackStand_vtbl *)&idAdvance_BackStand::`vftable';
  idState::idState(
    this: &this->statePlayOverrideAnim,
    stateType: &idAdvance_PlayOverrideAnim::Type,
    childFSMType: nullptr,
    flags: 0);
  this->statePlayOverrideAnim.__vftable = (idAdvance_PlayOverrideAnim_vtbl *)&idAdvance_PlayOverrideAnim::`vftable';
  idState::idState(this: &this->stateWait, stateType: &idAdvance_Wait::Type, childFSMType: nullptr, flags: 0);
  this->stateWait.__vftable = (idAdvance_Wait_vtbl *)&idAdvance_Wait::`vftable';
  idState::idState(
    this: &this->stateMoveFailedStop,
    stateType: &idAdvance_MoveFailedStop::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveFailedStop.__vftable = (idAdvance_MoveFailedStop_vtbl *)&idAdvance_MoveFailedStop::`vftable';
  idFiniteStateMachine::SetDefaultState(this, state: &this->stateDefault);
  return this;
}


// ========================================================================
// __unwind$490063
// EA  : 0x82AB5FA0
// RVA : 0x00AB5FA0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490063()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$490064
// EA  : 0x82AB5FC8
// RVA : 0x00AB5FC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490064()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$490065
// EA  : 0x82AB5FF4
// RVA : 0x00AB5FF4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490065()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$490066
// EA  : 0x82AB6020
// RVA : 0x00AB6020
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490066()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// __unwind$490067
// EA  : 0x82AB604C
// RVA : 0x00AB604C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490067()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 192));
}


// ========================================================================
// __unwind$490068
// EA  : 0x82AB6078
// RVA : 0x00AB6078
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490068()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 220));
}


// ========================================================================
// __unwind$490069
// EA  : 0x82AB60A4
// RVA : 0x00AB60A4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490069()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 248));
}


// ========================================================================
// __unwind$490070
// EA  : 0x82AB60D0
// RVA : 0x00AB60D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490070()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 276));
}


// ========================================================================
// __unwind$490071
// EA  : 0x82AB60FC
// RVA : 0x00AB60FC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490071()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 304));
}


// ========================================================================
// __unwind$490072
// EA  : 0x82AB6128
// RVA : 0x00AB6128
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490072()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 332));
}


// ========================================================================
// __unwind$490073
// EA  : 0x82AB6154
// RVA : 0x00AB6154
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490073()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 360));
}


// ========================================================================
// __unwind$490074
// EA  : 0x82AB6180
// RVA : 0x00AB6180
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490074()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 388));
}


// ========================================================================
// __unwind$490075
// EA  : 0x82AB61AC
// RVA : 0x00AB61AC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490075()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 416));
}


// ========================================================================
// __unwind$490076
// EA  : 0x82AB61D8
// RVA : 0x00AB61D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490076()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 444));
}


// ========================================================================
// ??1idAdvanceFSM@@UAA@XZ
// EA  : 0x82AB6210
// RVA : 0x00AB6210
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvanceFSM::~idAdvanceFSM(idAdvanceFSM *this)
{
  this->__vftable = (idAdvanceFSM_vtbl *)&idAdvanceFSM::`vftable';
  idState::~idState(this: &this->stateMoveFailedStop);
  idState::~idState(this: &this->stateWait);
  idState::~idState(this: &this->statePlayOverrideAnim);
  idState::~idState(this: &this->stateBackStand);
  idState::~idState(this: &this->stateRage);
  idState::~idState(this: &this->stateAttackMelee);
  idState::~idState(this: &this->stateThrowProjectile);
  idState::~idState(this: &this->stateSneakUpOnEnemy);
  idState::~idState(this: &this->stateLeapAttack);
  idState::~idState(this: &this->stateSideStep);
  idState::~idState(this: &this->stateMoveTowardsValidEnemyPos);
  idState::~idState(this: &this->stateMoveTowardsEnemy);
  idState::~idState(this: &this->stateDefault);
  idFiniteStateMachine::~idFiniteStateMachine(this);
}


// ========================================================================
// __unwind$490305
// EA  : 0x82AB62C4
// RVA : 0x00AB62C4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490305()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$490306
// EA  : 0x82AB62EC
// RVA : 0x00AB62EC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490306()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// __unwind$490307
// EA  : 0x82AB6318
// RVA : 0x00AB6318
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490307()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$490308
// EA  : 0x82AB6344
// RVA : 0x00AB6344
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490308()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// __unwind$490309
// EA  : 0x82AB6370
// RVA : 0x00AB6370
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490309()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 192));
}


// ========================================================================
// __unwind$490310
// EA  : 0x82AB639C
// RVA : 0x00AB639C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490310()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 220));
}


// ========================================================================
// __unwind$490311
// EA  : 0x82AB63C8
// RVA : 0x00AB63C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490311()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 248));
}


// ========================================================================
// __unwind$490312
// EA  : 0x82AB63F4
// RVA : 0x00AB63F4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490312()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 276));
}


// ========================================================================
// __unwind$490313
// EA  : 0x82AB6420
// RVA : 0x00AB6420
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490313()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 304));
}


// ========================================================================
// __unwind$490314
// EA  : 0x82AB644C
// RVA : 0x00AB644C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490314()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 332));
}


// ========================================================================
// __unwind$490315
// EA  : 0x82AB6478
// RVA : 0x00AB6478
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490315()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 360));
}


// ========================================================================
// __unwind$490316
// EA  : 0x82AB64A4
// RVA : 0x00AB64A4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490316()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 388));
}


// ========================================================================
// __unwind$490317
// EA  : 0x82AB64D0
// RVA : 0x00AB64D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void _unwind_490317()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 416));
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_LeapAttack@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB6500
// RVA : 0x00AB6500
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idOpenCombat_LeapAttack::AIState_EnterState(
        idAdvance_LeapAttack *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idEventArg *v7; // r3
  unsigned int v8; // r8
  int GameMs; // r3
  unsigned int v10; // r7
  double v11; // fp0
  int v12; // r3
  idEventArg v13; // [sp+90h] [-60h] BYREF
  idEventReceiver v14[5]; // [sp+B0h] [-40h] BYREF

  ai->aiVolatile.memory.nextLeapAttackTime = GetRandomInterval(
                                               _min: ai->aiEditable.behaviors.decl->minLeapAttackInterval,
                                               _max: ai->aiEditable.behaviors.decl->maxLeapAttackInterval)
                                           + curTime;
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  v7 = idEventArg::idEventArg(this: &v13, data: ai);
  idEventReceiver::ProcessEvent(
    this: v14,
    result: fsm,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]));
  v8 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v8;
  if ( (signed int)(((v8 >> 10) & 0x7FFF) % 0x64) < ai->aiEditable.behaviors.decl->rageBehaviors.angryRageAfterMissingChance )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idAIMemory::SetWantAngryRageTime(this: &ai->aiVolatile.memory, t: GameMs + 1000, debugReason: "miss enemy");
  }
  v10 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v10;
  if ( ((v10 >> 10) & 0x7FFF) == 2 * ((int)((v10 >> 10) & 0x7FFF) >> 1) )
    v11 = 0.0;
  else
    v11 = 1.0;
  ai->aiVolatile.animation.animWebAnimator.ptr[0].select01 = v11;
  v12 = idContents::ToFlags(this: &ai->aiConstants.physics.clipMask);
  idContents::FromFlags(this: &ai->aiConstants.physics.clipMask, flags: v12 | 0x400);
}


// ========================================================================
// ?AIState_EnterState@idAdvance_Rage@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB66B8
// RVA : 0x00AB66B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_Rage::AIState_EnterState(idAdvance_Rage *this, idAI2 *ai, idEventArg *fsm, const int curTime)
{
  idAIMemory *p_memory; // r31
  int v8; // r30
  idAIMemory *v9; // r3
  int soonestTauntRageTime; // r11
  int soonestAngryRageTime; // r11
  idEventArg *v12; // r3
  idEventArg v13; // [sp+90h] [-70h] BYREF
  idEventReceiver v14[6]; // [sp+B0h] [-50h] BYREF

  p_memory = &ai->aiVolatile.memory;
  v8 = GetRandomInterval(
         _min: ai->aiEditable.behaviors.decl->rageBehaviors.minRageInterval,
         _max: ai->aiEditable.behaviors.decl->rageBehaviors.maxRageInterval)
     + curTime;
  v9 = &ai->aiVolatile.memory;
  if ( ai->aiVolatile.memory.transCode == TRANSCODE_ADVANCE_SHOULD_TAUNT_RAGE )
    idAIMemory::SetWantTauntRageTime(this: v9, t: -1, debugReason: &byte_8200D768);
  else
    idAIMemory::SetWantAngryRageTime(this: v9, t: -1, debugReason: &byte_8200D768);
  soonestTauntRageTime = ai->aiVolatile.memory.soonestTauntRageTime;
  if ( soonestTauntRageTime <= v8 )
    soonestTauntRageTime = v8;
  ai->aiVolatile.memory.soonestTauntRageTime = soonestTauntRageTime;
  soonestAngryRageTime = ai->aiVolatile.memory.soonestAngryRageTime;
  if ( soonestAngryRageTime <= v8 )
    soonestAngryRageTime = v8;
  ai->aiVolatile.memory.soonestAngryRageTime = soonestAngryRageTime;
  p_memory->transCode = 0;
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  v12 = idEventArg::idEventArg(this: &v13, data: ai);
  idEventReceiver::ProcessEvent(
    this: v14,
    result: fsm,
    ev: *(const idEventDef **)&v12->type,
    arg1: (const idEventArg *)LODWORD(v12->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v12->value.v[2]));
}


// ========================================================================
// ?Evaluate@ADVANCE_ShouldLeapAttack@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB6818
// RVA : 0x00AB6818
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall ADVANCE_ShouldLeapAttack::Evaluate(
        ADVANCE_ShouldLeapAttack *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  idAIMoveState *MoveInterface; // r3
  const idDeclAIBehavior *decl; // r29
  unsigned int v10; // r3
  idTurret *Enemy; // r3
  const idEntity *v12; // r24
  idVec3 *v13; // r4
  idAIEntityState *v14; // r3
  aiSenseState_t *v15; // r28
  char v16; // r27
  const idAAS2 *v17; // r3
  const idAASPosition *AASPosition; // r3
  idAASPosition *v19; // r29
  idPhysics *Physics; // r3
  idAAS2 *aas; // r23
  idPhysics *v22; // r22
  idAAS2_vtbl *v23; // r26
  unsigned int v24; // r21
  int AreaNum; // r20
  int v26; // r3
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  float y; // r9
  float z; // r8
  const idAAS2 *v30; // r23
  idAAS2_vtbl *v31; // r22
  int v32; // r3
  int v33; // r3
  idPhysics *v34; // r3
  idAAS2 *v35; // r26
  idPhysics *v36; // r23
  idAASPosition *v37; // r3
  idAAS2_vtbl *v38; // r29
  unsigned int v39; // r22
  int v40; // r21
  int v41; // r3
  idPhysics *v42; // r29
  idRenderWorld *v43; // r26
  idPhysics *v44; // r3
  idRenderWorld_vtbl *v45; // r29
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v47; // r3
  idRenderWorld *v48; // r26
  idRenderWorld_vtbl *v49; // r29
  const aiPhysicalState_t *v50; // r3
  idPhysics *v51; // r31
  idRenderWorld *v52; // r29
  idPhysics *v53; // r3
  idRenderWorld_vtbl *v54; // r31
  const idVec3 *(__fastcall *v55)(idPhysics *, int); // ctr
  int v56; // r3
  int v57; // r6
  idRenderWorld *v58; // r29
  idPhysics *v59; // r3
  int v60; // r3
  idRenderWorld *v61; // r26
  idRenderWorld_vtbl *v62; // r29
  const aiPhysicalState_t *v63; // r3
  idPhysics *v64; // r31
  idRenderWorld *v65; // r29
  idPhysics *v66; // r3
  idRenderWorld_vtbl *v67; // r31
  const idVec3 *(__fastcall *v68)(idPhysics *, int); // ctr
  int v69; // r3
  idRenderWorld *v70; // r27
  idRenderWorld_vtbl *v71; // r30
  const aiPhysicalState_t *v72; // r3
  idRenderWorld *v73; // r30
  idPhysics *v74; // r3
  int v75; // r3
  double v76; // fp13
  double v77; // fp12
  idVec3 v78; // [sp+60h] [-1A0h] BYREF
  float x; // [sp+70h] [-190h] BYREF
  float v80; // [sp+74h] [-18Ch]
  float v81; // [sp+78h] [-188h]
  float v82[22]; // [sp+80h] [-180h] BYREF
  idVec3 v83[2]; // [sp+D8h] [-128h] BYREF
  char v84; // [sp+F0h] [-110h] BYREF
  trace_t v85; // [sp+110h] [-F0h] BYREF

  if ( ai->aiEditable.movement.turretMode || curTime <= ai->aiVolatile.memory.nextLeapAttackTime )
    return 0;
  if ( ai->aiVolatile.groupStatus.currentRole == ROLE_THROW )
    return DontLeapAttackBecause(ai, txt: "THROWER");
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  if ( MoveInterface->IsPlayingTraversalAnim(this: MoveInterface) )
    return DontLeapAttackBecause(ai, txt: "TRAVERSING");
  decl = ai->aiEditable.behaviors.decl;
  v10 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v10;
  if ( (signed int)(((v10 >> 10) & 0x7FFF) % 0x64) >= decl->leapAttackChance )
    return DontLeapAttackBecause(ai, txt: "CHANCE");
  if ( ai->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType == ANIMWEBAI_RUNINDEXTYPE_INJURED )
    return DontLeapAttackBecause(ai, txt: "HEALTH");
  if ( ai->aiVolatile.memory.wantTauntRageTime > 0
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
     - ai->aiVolatile.memory.wantTauntRageTime < 1000 )
  {
    return DontLeapAttackBecause(ai, txt: "TAUNT");
  }
  Enemy = (idTurret *)idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
  v12 = Enemy;
  if ( Enemy == nullptr )
    return 0;
  if ( idTurret::CastTo(c: Enemy) != nullptr )
  {
    DontLeapAttackBecause(ai, txt: "ENEMY TYPE");
    return 0;
  }
  v14 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v12);
  if ( v14 == nullptr )
    return DontLeapAttackBecause(ai, txt: "SIGHT");
  v15 = v14->senses.ptr[1];
  if ( v15->lastUnconfirmedStimTime < 0 )
    return DontLeapAttackBecause(ai, txt: "SIGHT");
  if ( curTime - v15->lastConfirmedStimTime >= 1000 )
    return DontLeapAttackBecause(ai, txt: "UNCONFIRMED");
  aiSenseState_t::ExtrapolatePosition(
    this: v14->senses.ptr[1],
    seconds: decl->leapAttackTargetExtrapolate,
    futurePos: v13);
  if ( (unsigned __int8)idAI2::IsTargetInLeapAttackZone(this: ai, targetPos: &v78) == 0 )
    return 0;
  v16 = 1;
  if ( ai->GetAAS(this: ai) == nullptr )
    goto LABEL_29;
  v17 = ai->GetAAS(this: ai);
  AASPosition = idActor::GetAASPosition(this: ai, aas: v17);
  memset(&v82[4], 0, 12);
  v19 = (idAASPosition *)AASPosition;
  v82[10] = 0.0;
  v82[11] = 0.0;
  v82[0] = 0.0;
  memset(&v82[15], 0, 24);
  v82[1] = 0.0;
  v82[2] = 0.0;
  v82[3] = 0.0;
  v82[7] = 0.0;
  v82[8] = 0.0;
  v82[9] = 0.0;
  v82[12] = 0.0;
  v82[13] = 0.0;
  v82[14] = 0.0;
  Physics = idEntity::GetPhysics(this: ai);
  aas = (idAAS2 *)v19->aas;
  v22 = Physics;
  v23 = aas->__vftable;
  v24 = ai->aiVolatile.aas.travelFlags & 0xFE78FFFF;
  AreaNum = idAASPosition::GetAreaNum(this: v19);
  v26 = (int)v22->GetOrigin(this: v22, a2: 0);
  ((void (__fastcall *)(idAAS2 *, float *, int, int, idVec3 *, unsigned int, _DWORD, _DWORD))v23->TraceFloor)(
    a1: aas,
    a2: v82,
    a3: v26,
    a4: AreaNum,
    a5: &v78,
    a6: v24,
    a7: 0,
    a8: 0);
  if ( v82[0] >= 1.0 )
    goto LABEL_29;
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v15);
  y = ConfirmedPhysicalSafe->origin.y;
  z = ConfirmedPhysicalSafe->origin.z;
  x = ConfirmedPhysicalSafe->origin.x;
  v80 = y;
  v81 = z;
  v30 = v19->aas;
  v31 = v30->__vftable;
  v32 = (int)v30->DefaultSearchBounds(this: (idAAS2 *)&v84, result: (idBounds *)v30);
  v33 = v31->PointReachableAreaNum(
          this: (idAAS2 *)v30,
          a2: nullptr,
          a3: (const idVec3 *)&x,
          a4: (const idBounds *)v32,
          a5: 2,
          a6: 1);
  v19->aas->PushPointIntoAreaNum(this: (idAAS2 *)v19->aas, a2: v33, a3: (idVec3 *)&x);
  v78.x = x;
  v78.y = v80;
  v78.z = v81;
  v34 = idEntity::GetPhysics(this: ai);
  v35 = (idAAS2 *)v19->aas;
  v36 = v34;
  v37 = v19;
  v38 = v35->__vftable;
  v39 = ai->aiVolatile.aas.travelFlags & 0xFE78FFFF;
  v40 = idAASPosition::GetAreaNum(this: v37);
  v41 = (int)v36->GetOrigin(this: v36, a2: 0);
  ((void (__fastcall *)(idAAS2 *, float *, int, int, idVec3 *, unsigned int, _DWORD, _DWORD))v38->TraceFloor)(
    a1: v35,
    a2: v82,
    a3: v41,
    a4: v40,
    a5: &v78,
    a6: v39,
    a7: 0,
    a8: 0);
  if ( v82[0] < 1.0 )
  {
    if ( idAI2::GetDebugLevel() > 0 && ai_debugLeapAttack.valueInteger != 0 )
    {
      v42 = idEntity::GetPhysics(this: ai);
      v43 = common->RW(this: common);
      v44 = v42;
      GetOrigin = v42->GetOrigin;
      v45 = v43->__vftable;
      v47 = (int)GetOrigin(this: v44, a2: 0);
      v45->DebugLine(
        this: v43,
        a2: (const idVec4 *)&idColor::colorOrange,
        a3: (const idVec3 *)v47,
        a4: &v78,
        a5: 2000,
        a6: true);
      v48 = common->RW(this: common);
      v49 = v48->__vftable;
      v50 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v15);
      ((void (__fastcall *)(idRenderWorld *, idColor *, const aiPhysicalState_t *, idVec3 *, double))v49->DebugArrow)(
        a1: v48,
        a2: &idColor::colorWhite,
        a3: v50,
        a4: &v78,
        a5: 10.0);
      v51 = idEntity::GetPhysics(this: ai);
      v52 = common->RW(this: common);
      v53 = v51;
      v55 = v51->GetOrigin;
      v54 = v52->__vftable;
      v56 = (int)v55(this: v53, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, const char *, int, int, idColor *, int, int, _DWORD, double))v54->DebugText)(
        a1: v52,
        a2: "AAS",
        a3: v56,
        a4: v57,
        a5: &idColor::colorMagenta,
        a6: 1,
        a7: 2000,
        a8: 0,
        a9: 0.2);
    }
    return 0;
  }
  else
  {
LABEL_29:
    ai->GetEyePos(this: ai, a2: v83);
    idClip::TraceBounds(
      this: &clientGame->clip,
      result: &v85,
      start: v83,
      end: &v78,
      trm: nullptr,
      clipMask: 1025,
      passEntityNumber: ai->entityNumber);
    if ( v85.fraction >= 1.0 || v85.c.entityNum == v12->entityNumber )
      v16 = 0;
    if ( v16 != 0 )
    {
      if ( idAI2::GetDebugLevel() > 0 && ai_debugLeapAttack.valueInteger != 0 )
      {
        v58 = common->RW(this: common);
        v59 = idEntity::GetPhysics(this: ai);
        v60 = (int)v59->GetOrigin(this: v59, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, idColor *, int, idVec3 *, double))v58->DebugArrow)(
          a1: v58,
          a2: &idColor::colorOrange,
          a3: v60,
          a4: &v78,
          a5: 10.0);
        v61 = common->RW(this: common);
        v62 = v61->__vftable;
        v63 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v15);
        ((void (__fastcall *)(idRenderWorld *, idColor *, const aiPhysicalState_t *, idVec3 *, double))v62->DebugArrow)(
          a1: v61,
          a2: &idColor::colorWhite,
          a3: v63,
          a4: &v78,
          a5: 10.0);
        v64 = idEntity::GetPhysics(this: ai);
        v65 = common->RW(this: common);
        v66 = v64;
        v68 = v64->GetOrigin;
        v67 = v65->__vftable;
        v69 = (int)v68(this: v66, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, const char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))v67->DebugText)(
          a1: v65,
          a2: "BLOCKED",
          a3: v69,
          a4: v67->DebugText,
          a5: &idColor::colorMagenta,
          a6: 1,
          a7: 16,
          a8: 0,
          a9: 0.2);
      }
      return 0;
    }
    else
    {
      if ( idAI2::GetDebugLevel() > 0 && ai_debugLeapAttack.valueInteger != 0 )
      {
        v70 = common->RW(this: common);
        v71 = v70->__vftable;
        v72 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v15);
        ((void (__fastcall *)(idRenderWorld *, idColor *, const aiPhysicalState_t *, idVec3 *, double))v71->DebugArrow)(
          a1: v70,
          a2: &idColor::colorWhite,
          a3: v72,
          a4: &v78,
          a5: 10.0);
        v73 = common->RW(this: common);
        v74 = idEntity::GetPhysics(this: ai);
        v75 = (int)v74->GetOrigin(this: v74, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, idColor *, int, idVec3 *, double))v73->DebugArrow)(
          a1: v73,
          a2: &idColor::colorYellow,
          a3: v75,
          a4: &v78,
          a5: 10.0);
      }
      v76 = v78.y;
      v77 = v78.z;
      ai->aiVolatile.memory.leapTarget.x = v78.x;
      ai->aiVolatile.memory.leapTarget.y = v76;
      ai->aiVolatile.memory.leapTarget.z = v77;
      return TRANSCODE_ADVANCE_SHOULD_LEAP_ATTACK;
    }
  }
}


// ========================================================================
// ?AIState_EnterState@idAdvance_AttackMelee@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB7140
// RVA : 0x00AB7140
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_AttackMelee::AIState_EnterState(
        idAdvance_AttackMelee *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  const idDeclAIBehavior *decl; // r11
  int minCloseMeleeInterval; // r9
  signed int v9; // r11
  int v10; // r11
  unsigned int seed; // r8
  unsigned int v12; // r4
  int v13; // r3
  unsigned int v14; // r4
  void (__fastcall *SetWeaponReadyState)(struct idAI2 *, const weaponReadyState_t); // r5
  int value; // r9
  idEntity *v17; // r3
  idTurret *v18; // r30
  idAIEntityState *v19; // r3
  aiSenseState_t *v20; // r29
  int v21; // r30
  idVec3 *p_velocity; // r28
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  aiMelee_t MeleeTypeForTarget; // r28
  overrideAnim_t v25; // r30
  idVec3 *v26; // r21
  const aiPhysicalState_t *v27; // r3
  idPhysics *Physics; // r3
  float *v29; // r3
  double v30; // fp7
  double v31; // fp6
  idEventArg *v32; // r20
  unsigned int v33; // r6
  int GameMs; // r3
  const char *v35; // r30
  int v36; // r11
  const char **v37; // r10
  idVec3 *v38; // r28
  const aiPhysicalState_t *v39; // r3
  idPhysics *v40; // r3
  idRenderWorld *renderWorld; // r29
  idRenderWorld_vtbl *v42; // r28
  int v43; // r3
  int v44; // r3
  unsigned int v45; // r7
  _BYTE v46[20]; // [sp+70h] [-160h] BYREF
  _BYTE v47[20]; // [sp+90h] [-140h] BYREF
  bool v48; // [sp+B0h] [-120h] BYREF
  idVec3 v49[2]; // [sp+B8h] [-118h] BYREF
  float v50[5]; // [sp+D0h] [-100h] BYREF
  _DWORD v51[5]; // [sp+F0h] [-E0h] BYREF
  int v52; // [sp+110h] [-C0h]
  overrideAnim_t v53; // [sp+114h] [-BCh]
  const idEventArg *v54; // [sp+118h] [-B8h]
  idEventArg v55; // [sp+130h] [-A0h] BYREF
  idEventReceiver v56[10]; // [sp+150h] [-80h] BYREF

  decl = ai->aiEditable.behaviors.decl;
  if ( (*((_BYTE *)decl + 196) & 4) != 0 )
  {
    minCloseMeleeInterval = decl->minCloseMeleeInterval;
    v9 = decl->maxCloseMeleeInterval - minCloseMeleeInterval;
    if ( v9 != 0 )
    {
      seed = clientGame->random.seed;
      __twllei(v9, 0);
      v12 = 1664525 * seed + 1013904223;
      clientGame->random.seed = v12;
      v13 = (v12 >> 10) & 0x7FFF;
      v14 = v9 & ~(__ROL4__(v13, 1) - 1);
      v10 = v13 % v9;
      __twlgei(v14, 0xFFFFFFFF);
    }
    else
    {
      v10 = 0;
    }
    SetWeaponReadyState = ai->SetWeaponReadyState;
    ai->aiVolatile.memory.nextCloseMeleeTime = v10 + minCloseMeleeInterval + curTime;
    SetWeaponReadyState(this: ai, a2: WEAPONREADY_LOWERED);
    idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
    ai->aiVolatile.fireControl->allowReloads = false;
    value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v17 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v18 = (idTurret *)idEntity::CastTo(c: v17);
    }
    else
    {
      v18 = nullptr;
    }
    v19 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v18);
    if ( v19 != nullptr )
    {
      v20 = v19->senses.ptr[v19->lastSense];
      v21 = idAI2::MeleePreference(this: ai, target: v18);
      p_velocity = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v20)->velocity;
      ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v20);
      MeleeTypeForTarget = idAI2::GetMeleeTypeForTarget(
                             this: ai,
                             targetPos: &ConfirmedPhysicalSafe->origin,
                             targetVel: p_velocity,
                             meleeMask: -1,
                             preferredMask: v21);
      if ( MeleeTypeForTarget != AIMELEE_NONE && (!idActor::IsCrouching(this: ai) || (MeleeTypeForTarget & 0x1E00) != 0) )
      {
        v25 = AIMeleeTypeToOverrideAnim(meleeType: MeleeTypeForTarget);
        v26 = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v20)->velocity;
        v27 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v20);
        idAI2::ExtrapolateMeleeTarget(this: ai, targetPos: &v27->origin, targetVel: v26, outAttackTo: v49);
        Physics = idEntity::GetPhysics(this: ai);
        v29 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v30 = (float)(v49[0].y - v29[1]);
        v31 = (float)(v49[0].z - v29[2]);
        v49[0].x = v49[0].x - *v29;
        v49[0].y = v30;
        v49[0].z = v31;
        idVec3::NormalizeFast(this: v49);
        if ( v25 != ANIMOVERRIDE_NONE )
        {
          idAI2::EndActionScript(this: ai);
          LODWORD(fsm[1].value.v[2]) = this;
          v53 = v25;
          v50[1] = v49[0].x;
          v50[2] = v49[0].y;
          HIBYTE(v51[0]) = 105;
          v50[3] = v49[0].z;
          HIBYTE(v50[0]) = 118;
          v51[1] = 1;
          HIBYTE(v52) = 105;
          v32 = idEventArg::idEventArg(this: &v55, data: ai);
          memcpy(Dst: v47, Src: v50, Size: sizeof(v47));
          memcpy(Dst: v46, Src: v51, Size: sizeof(v46));
          idEventReceiver::ProcessEvent(
            this: v56,
            result: fsm,
            ev: *(const idEventDef **)&v32->type,
            arg1: (const idEventArg *)LODWORD(v32->value.v[1]),
            arg2: (const idEventArg *)LODWORD(v32->value.v[2]),
            arg3: (const idEventArg *)__ROL4__(v52, 32),
            arg4: v54);
        }
        v33 = 1664525 * clientGame->random.seed + 1013904223;
        clientGame->random.seed = v33;
        if ( (signed int)(((v33 >> 10) & 0x7FFF) % 0x64) < ai->aiEditable.behaviors.decl->rageBehaviors.angryRageAfterMissingChance )
        {
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          idAIMemory::SetWantAngryRageTime(this: &ai->aiVolatile.memory, t: GameMs, debugReason: "miss enemy");
        }
        if ( ai_debugmelee.valueInteger != 0 && ai_debugLevel.valueInteger > 0 )
        {
          aiSenseState_t::GetConfirmedPhysicalSafe(this: v20);
          v35 = "UNKNOWN";
          v36 = 2;
          v37 = &aiMeleeAnimNodeNames[1];
          do
          {
            if ( MeleeTypeForTarget >> (v36 - 2) == AIMELEE_NONE )
              v35 = *(v37 - 1);
            if ( MeleeTypeForTarget >> (v36 - 1) == AIMELEE_NONE )
              v35 = *v37;
            if ( MeleeTypeForTarget >> v36 == AIMELEE_NONE )
              v35 = v37[1];
            if ( MeleeTypeForTarget >> (v36 + 1) == AIMELEE_NONE )
              v35 = v37[2];
            v36 += 4;
            v37 += 4;
          }
          while ( v36 - 2 < 16 );
          v38 = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v20)->velocity;
          v39 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v20);
          idAI2::GetMeleeDirection(this: ai, target: &v39->origin, vel: v38, outNarrowFront: &v48, debug: true);
          v40 = idEntity::GetPhysics(this: ai);
          renderWorld = clientGame->renderWorld;
          v42 = renderWorld->__vftable;
          v43 = (int)v40->GetOrigin(this: v40, a2: 0);
          ((void (__fastcall *)(idRenderWorld *, const char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))v42->DebugText)(
            a1: renderWorld,
            a2: v35,
            a3: v43,
            a4: v42->DebugText,
            a5: &idColor::colorYellow,
            a6: 1,
            a7: 1500,
            a8: 0,
            a9: 0.2);
        }
        v44 = idContents::ToFlags(this: &ai->aiConstants.physics.clipMask);
        idContents::FromFlags(this: &ai->aiConstants.physics.clipMask, flags: v44 | 0x400);
        v45 = 1664525 * clientGame->random.seed + 1013904223;
        clientGame->random.seed = v45;
        if ( ((v45 >> 10) & 0x7FFF) == 2 * ((int)((v45 >> 10) & 0x7FFF) >> 1) )
          ai->aiVolatile.animation.animWebAnimator.ptr[0].select01 = 0.0;
        else
          ai->aiVolatile.animation.animWebAnimator.ptr[0].select01 = 1.0;
      }
    }
  }
}


// ========================================================================
// ?Evaluate@ADVANCE_ShouldMoveTowardsEnemy@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB7680
// RVA : 0x00AB7680
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

int __fastcall ADVANCE_ShouldMoveTowardsEnemy::Evaluate(
        ADVANCE_ShouldMoveTowardsEnemy *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idActor *v9; // r31
  idActor *v10; // r3
  idActor *v11; // r30
  const idAAS2 *v12; // r3
  const idAASPosition *AASPosition; // r31
  idPhysics *Physics; // r3
  float *v15; // r3
  double v16; // fp11
  double v17; // fp9

  if ( ai->aiEditable.movement.turretMode )
    return 0;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = (idActor *)idEntity::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  v10 = idActor::CastTo(c: v9);
  v11 = v10;
  if ( v9 == nullptr )
    return 0;
  if ( v10 != nullptr )
  {
    v12 = ai->GetAAS(this: ai);
    AASPosition = idActor::GetAASPosition(this: v11, aas: v12);
    if ( !AASPosition->valid )
    {
      Physics = idEntity::GetPhysics(this: ai);
      v15 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v16 = (float)(v15[1] - AASPosition->validOrigin.y);
      v17 = (float)(*v15 - AASPosition->validOrigin.x);
      if ( (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)) > 1.0 )
        return 362;
      return 0;
    }
  }
  return ai->aiVolatile.memory.enemyPathBlocked ? 0 : 0x169;
}


// ========================================================================
// ?Evaluate@ADVANCE_ShouldMelee@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB77C8
// RVA : 0x00AB77C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

int __fastcall ADVANCE_ShouldMelee::Evaluate(
        ADVANCE_ShouldMelee *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3
  idVehicle *Enemy; // r3
  idTurret *v8; // r28
  idAIEntityState *v9; // r3
  idAIEntityState *v10; // r30
  aiSenseState_t *v11; // r30
  int v12; // r29
  idVec3 *p_velocity; // r26
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  aiMelee_t MeleeTypeForTarget; // r29
  const aiPhysicalState_t *v16; // r3
  int entityNumber; // r29
  const aiPhysicalState_t *v18; // r3
  char v19; // r11
  idRenderWorld *v20; // r27
  idPhysics *Physics; // r3
  int v22; // r26
  idRenderWorld_vtbl *v23; // r29
  const aiPhysicalState_t *v24; // r3
  idPhysics *v25; // r31
  idRenderWorld *v26; // r30
  idPhysics *v27; // r3
  idRenderWorld_vtbl *v28; // r31
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v30; // r3
  int v31; // r6
  idRenderWorld *v33; // r29
  idPhysics *v34; // r3
  int v35; // r28
  idRenderWorld_vtbl *v36; // r31
  const aiPhysicalState_t *v37; // r3
  idVec3 v38; // [sp+60h] [-D0h] BYREF
  trace_t v39; // [sp+70h] [-C0h] BYREF

  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < ai->aiVolatile.memory.nextCloseMeleeTime )
    return 0;
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  if ( MoveInterface->IsPlayingTraversalAnim(this: MoveInterface) )
    return 0;
  if ( !idAI2::CanMelee(this: ai) )
    return 0;
  Enemy = (idVehicle *)idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
  v8 = (idTurret *)Enemy;
  if ( Enemy == nullptr )
    return 0;
  if ( idVehicle::CastTo(c: Enemy) != nullptr )
    return 0;
  v9 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8);
  v10 = v9;
  if ( v9 == nullptr )
    return 0;
  if ( v9->curAwareness != 3 )
    return 0;
  if ( !idAIEntityState::IsVisible(this: v9) )
    return 0;
  v11 = v10->senses.ptr[v10->lastSense];
  v12 = idAI2::MeleePreference(this: ai, target: v8);
  p_velocity = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v11)->velocity;
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v11);
  MeleeTypeForTarget = idAI2::GetMeleeTypeForTarget(
                         this: ai,
                         targetPos: &ConfirmedPhysicalSafe->origin,
                         targetVel: p_velocity,
                         meleeMask: -1,
                         preferredMask: v12);
  if ( MeleeTypeForTarget == AIMELEE_NONE )
    return 0;
  v16 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v11);
  if ( (unsigned __int8)idAI2::IsTargetInMeleeRange(this: ai, targetPos: &v16->origin, meleeType: MeleeTypeForTarget) == 0 )
    return 0;
  ai->GetEyePos(this: ai, a2: &v38);
  entityNumber = ai->entityNumber;
  v18 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v11);
  idClip::TraceBounds(
    this: &clientGame->clip,
    result: &v39,
    start: &v38,
    end: &v18->eyePos,
    trm: nullptr,
    clipMask: 1025,
    passEntityNumber: entityNumber);
  if ( v39.fraction >= 1.0 || (v19 = 1, v39.c.entityNum == v8->entityNumber) )
    v19 = 0;
  if ( v19 != 0 )
  {
    if ( idAI2::GetDebugLevel() > 0 && ai_debugmelee.valueInteger != 0 )
    {
      v20 = common->RW(this: common);
      Physics = idEntity::GetPhysics(this: ai);
      v22 = (int)Physics->GetOrigin(this: Physics, a2: 0);
      v23 = v20->__vftable;
      v24 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v11);
      ((void (__fastcall *)(idRenderWorld *, idColor *, int, const aiPhysicalState_t *, double))v23->DebugArrow)(
        a1: v20,
        a2: &idColor::colorOrange,
        a3: v22,
        a4: v24,
        a5: 10.0);
      v25 = idEntity::GetPhysics(this: ai);
      v26 = common->RW(this: common);
      v27 = v25;
      GetOrigin = v25->GetOrigin;
      v28 = v26->__vftable;
      v30 = (int)GetOrigin(this: v27, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, const char *, int, int, idColor *, int, int, _DWORD, double))v28->DebugText)(
        a1: v26,
        a2: "BLOCKED",
        a3: v30,
        a4: v31,
        a5: &idColor::colorMagenta,
        a6: 1,
        a7: 16,
        a8: 0,
        a9: 0.2);
    }
    return 0;
  }
  if ( idAI2::GetDebugLevel() > 0 && ai_debugmelee.valueInteger != 0 )
  {
    v33 = common->RW(this: common);
    v34 = idEntity::GetPhysics(this: ai);
    v35 = (int)v34->GetOrigin(this: v34, a2: 0);
    v36 = v33->__vftable;
    v37 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v11);
    ((void (__fastcall *)(idRenderWorld *, idColor *, int, const aiPhysicalState_t *, double))v36->DebugArrow)(
      a1: v33,
      a2: &idColor::colorYellow,
      a3: v35,
      a4: v37,
      a5: 10.0);
  }
  return 387;
}


// ========================================================================
// ?Evaluate@ADVANCE_ShouldWait@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB7B60
// RVA : 0x00AB7B60
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall ADVANCE_ShouldWait::Evaluate(
        ADVANCE_ShouldWait *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idActor *v8; // r31
  idActor *v9; // r30
  idVehicle *v10; // r28
  const idAAS2 *v11; // r3
  const idAASPosition *AASPosition; // r31
  idPhysics *Physics; // r3
  float *v14; // r3
  double v15; // fp11
  double v16; // fp9
  idAIStateTransition::aiTransCode_t result; // r3

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = (idActor *)idEntity::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  v9 = idActor::CastTo(c: v8);
  v10 = idVehicle::CastTo(c: (idVehicle *)v8);
  if ( v8 == nullptr )
    return 0;
  if ( v9 != nullptr )
  {
    v11 = ai->GetAAS(this: ai);
    AASPosition = idActor::GetAASPosition(this: v9, aas: v11);
    if ( !AASPosition->valid )
    {
      Physics = idEntity::GetPhysics(this: ai);
      v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v15 = (float)(*v14 - AASPosition->validOrigin.x);
      v16 = (float)(v14[1] - AASPosition->validOrigin.y);
      if ( (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15)) < 1.0 )
        return TRANSCODE_ADVANCE_SHOULD_WAIT;
    }
  }
  if ( v10 != nullptr )
    return TRANSCODE_ADVANCE_SHOULD_WAIT;
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
  {
    if ( idEntityPtr<idEntity const>::operator->(this: &ai->aiVolatile.animation.animFSM.currentMove.destEnt) != nullptr
      && ai->aiVolatile.memory.enemyPathBlocked )
    {
      return TRANSCODE_ADVANCE_SHOULD_WAIT;
    }
    return 0;
  }
  if ( idAIMoveState::GetGoalEntity(this: &ai->aiVolatile.physics.moveState) == nullptr )
    return 0;
  result = TRANSCODE_ADVANCE_SHOULD_WAIT;
  if ( !ai->aiVolatile.memory.enemyPathBlocked )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@ADVANCE_MoveTowardsEnemyDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB7CF0
// RVA : 0x00AB7CF0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

int __fastcall ADVANCE_MoveTowardsEnemyDone::Evaluate(
        ADVANCE_MoveTowardsEnemyDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  aiSenseState_t *EnemySenseState; // r30
  idPhysics *Physics; // r3
  float *v9; // r29
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  double v11; // fp10
  double v12; // fp8
  int value; // r9
  idEntity *v15; // r3
  idEntity *Enemy; // r28
  const idEntity *v17; // r28

  if ( idAI2::IsMoveDone(this: ai, checkAlignment: false) )
  {
    EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
    if ( EnemySenseState != nullptr
      && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
       - EnemySenseState->lastConfirmedStimTime >= 1000 )
    {
      Physics = idEntity::GetPhysics(this: ai);
      v9 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
      v11 = (float)(ConfirmedPhysicalSafe->origin.y - v9[1]);
      v12 = (float)(ConfirmedPhysicalSafe->origin.z - v9[2]);
      if ( (float)((float)((float)(ConfirmedPhysicalSafe->origin.x - *v9)
                         * (float)(ConfirmedPhysicalSafe->origin.x - *v9))
                 + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) < 4096.0 )
      {
        ai->aiVolatile.groupStatus.condition |= 0x1000u;
        return 394;
      }
    }
    return 365;
  }
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
  {
    value = ai->aiVolatile.animation.animFSM.currentMove.destEnt.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v15 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v15 != nullptr && idEntity::CastTo(c: v15) != nullptr )
      {
        Enemy = (idEntity *)idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
        if ( idEntityPtr<idEntity const>::operator->(this: &ai->aiVolatile.animation.animFSM.currentMove.destEnt) != Enemy )
          return 365;
      }
    }
  }
  else if ( idAIMoveState::GetGoalEntity(this: &ai->aiVolatile.physics.moveState) != nullptr )
  {
    v17 = idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
    if ( idAIMoveState::GetGoalEntity(this: &ai->aiVolatile.physics.moveState) != v17 )
      return 365;
  }
  return ((__PAIR64__((unsigned int)(curTime - ai->aiVolatile.memory.movementStartTime) >> 31, 5000)
         - (unsigned int)(curTime - ai->aiVolatile.memory.movementStartTime)) >> 32)
       & 0x16D;
}


// ========================================================================
// ?AIState_EnterState@idAdvance_MoveTowardsEnemy@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB7EE8
// RVA : 0x00AB7EE8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_MoveTowardsEnemy::AIState_EnterState(
        idAdvance_MoveTowardsEnemy *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  idEntity *v10; // r3
  idPlayer *v11; // r29
  bool v12; // r5
  idAI2_vtbl *v13; // r8
  idEventArg *v14; // r3
  idPhysics *Physics; // r3
  float *v16; // r24
  idPhysics *v17; // r3
  float *v18; // r3
  double v19; // fp10
  double v20; // fp0
  double v21; // fp7
  idAIOrientation *BodyOrientation; // r3
  double v23; // fp31
  idEventArg *v24; // r20
  idEventArg *v25; // r19
  const idEventArg *v26; // [sp+8h] [-2C8h]
  const idEventArg *v27; // [sp+Ch] [-2C4h]
  const idEventArg *v28; // [sp+10h] [-2C0h]
  _BYTE v29[20]; // [sp+70h] [-260h] BYREF
  _BYTE v30[20]; // [sp+90h] [-240h] BYREF
  _BYTE v31[20]; // [sp+B0h] [-220h] BYREF
  _BYTE v32[20]; // [sp+D0h] [-200h] BYREF
  _BYTE v33[20]; // [sp+F0h] [-1E0h] BYREF
  _BYTE v34[20]; // [sp+110h] [-1C0h] BYREF
  idVec3 v35; // [sp+130h] [-1A0h] BYREF
  float v36[5]; // [sp+140h] [-190h] BYREF
  idEventArg v37; // [sp+160h] [-170h] BYREF
  idEventReceiver v38[10]; // [sp+180h] [-150h] BYREF
  idEventArg v39; // [sp+200h] [-D0h] BYREF
  idEventArg v40; // [sp+220h] [-B0h] BYREF
  idEventReceiver v41[2]; // [sp+240h] [-90h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v10 = idEntity::CastTo(c: v9), v11 = (idPlayer *)v10, v10 != nullptr) )
  {
    if ( (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 4) != 0
      || (v12 = false, ai_enableNonStrafeMoveToEntity.valueInteger == 0) )
    {
      v12 = true;
    }
    idAI2::SetAimFocusEntity(this: ai, ent: v10, keepFocusInView: v12, aimPoint: AIMPOINT_BEST, timeout: -1);
    idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
    v13 = ai->__vftable;
    ai->aiVolatile.focus.enableBodyRotation = true;
    v13->SetWalkState(this: ai, a2: WALKSTATE_RUNNING);
    if ( idActor::IsCrouching(this: ai) )
    {
      if ( ai_useTransitions.valueInteger != 0 && ai_useStartTransitions.valueInteger != 0 )
      {
        ai->SetPosture(this: ai, a2: POSTURE_STANDING);
      }
      else
      {
        v14 = idEventArg::idEventArg(this: &v37, data: ai);
        idEventReceiver::ProcessEvent(
          this: v38,
          result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
          ev: *(const idEventDef **)&v14->type,
          arg1: (const idEventArg *)LODWORD(v14->value.v[1]));
      }
    }
    Physics = idEntity::GetPhysics(this: ai);
    v16 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v17 = idEntity::GetPhysics(this: v11);
    v18 = (float *)v17->GetOrigin(this: v17, a2: 0);
    v19 = (float)(v18[1] - v16[1]);
    v20 = (float)(*v18 - *v16);
    v21 = (float)(v18[2] - v16[2]);
    v35.y = v18[1] - v16[1];
    v35.x = v20;
    v35.z = v21;
    if ( (float)((float)((float)v21 * (float)v21)
               + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) > 1.0 )
    {
      idVec3::NormalizeFast(this: &v35);
      BodyOrientation = idAI2::GetBodyOrientation(this: ai);
      idAIOrientation::SetIdealDir(this: BodyOrientation, ai, dir: &v35);
    }
    v23 = 8.0;
    if ( idPlayer::CastTo(c: v11) != nullptr )
      v23 = 32.0;
    v38[8].listenerList = nullptr;
    v38[5].listeningToList = nullptr;
    *(float *)&v38[3].__vftable = v23;
    HIBYTE(v38[8].__vftable) = 105;
    HIBYTE(v38[5].listenerList) = 105;
    v36[1] = vec3_origin.x;
    v36[2] = vec3_origin.y;
    HIBYTE(v36[0]) = 118;
    v36[3] = vec3_origin.z;
    HIBYTE(v38[2].listeningToList) = 102;
    HIBYTE(v38[0].__vftable) = 105;
    v38[0].listenerList = (idList<idEventReceiver *,5> *)2;
    v37.type = 105;
    v37.value.i = 9;
    v24 = idEventArg::idEventArg(this: &v39, data: v11);
    v25 = idEventArg::idEventArg(this: &v40, data: ai);
    memcpy(Dst: v34, Src: &v38[8], Size: sizeof(v34));
    memcpy(Dst: v33, Src: v36, Size: sizeof(v33));
    memcpy(Dst: v32, Src: &v38[5].listenerList, Size: sizeof(v32));
    memcpy(Dst: v31, Src: &v38[2].listeningToList, Size: sizeof(v31));
    memcpy(Dst: v30, Src: v38, Size: sizeof(v30));
    memcpy(Dst: v29, Src: v24, Size: sizeof(v29));
    idEventReceiver::ProcessEvent(
      this: v41,
      result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
      ev: *(const idEventDef **)&v25->type,
      arg1: (const idEventArg *)LODWORD(v25->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v25->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v37.type, 32),
      arg4: (const idEventArg *)LODWORD(v37.value.v[1]),
      arg5: (const idEventArg *)LODWORD(v37.value.v[2]),
      arg6: v26,
      arg7: v27,
      arg8: v28);
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
      ai->aiVolatile.animation.animFSM.overrideMoveFlags |= 0x1080u;
    idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?AIState_EnterState@idAdvance_MoveTowardsValidEnemyPos@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB82C0
// RVA : 0x00AB82C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_MoveTowardsValidEnemyPos::AIState_EnterState(
        idAdvance_MoveTowardsValidEnemyPos *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  idActor *v10; // r3
  idActor *v11; // r3
  idActor *v12; // r29
  bool v13; // r5
  idAI2_vtbl *v14; // r8
  idEventArg *v15; // r3
  const idAAS2 *v16; // r3
  const idAASPosition *AASPosition; // r3
  double y; // fp9
  double z; // fp8
  idEventArg *v20; // r20
  const idEventArg *v21; // [sp+8h] [-268h]
  const idEventArg *v22; // [sp+Ch] [-264h]
  _BYTE v23[20]; // [sp+70h] [-200h] BYREF
  _BYTE v24[20]; // [sp+90h] [-1E0h] BYREF
  _BYTE v25[20]; // [sp+B0h] [-1C0h] BYREF
  _BYTE v26[20]; // [sp+D0h] [-1A0h] BYREF
  _BYTE v27[20]; // [sp+F0h] [-180h] BYREF
  float v28[5]; // [sp+110h] [-160h] BYREF
  float v29[5]; // [sp+130h] [-140h] BYREF
  idEventArg v30; // [sp+150h] [-120h] BYREF
  idEventReceiver v31[8]; // [sp+170h] [-100h] BYREF
  idEventArg v32; // [sp+1D0h] [-A0h] BYREF
  idEventReceiver v33[10]; // [sp+1F0h] [-80h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v10 = (idActor *)idEntity::CastTo(c: v9);
  }
  else
  {
    v10 = nullptr;
  }
  v11 = idActor::CastTo(c: v10);
  v12 = v11;
  if ( v11 == nullptr )
    goto LABEL_18;
  if ( (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 4) == 0
    || (v13 = false, ai_enableNonStrafeMoveToEntity.valueInteger == 0) )
  {
    v13 = true;
  }
  idAI2::SetAimFocusEntity(this: ai, ent: v11, keepFocusInView: v13, aimPoint: AIMPOINT_BEST, timeout: -1);
  idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
  v14 = ai->__vftable;
  ai->aiVolatile.focus.enableBodyRotation = true;
  v14->SetWalkState(this: ai, a2: WALKSTATE_RUNNING);
  if ( idActor::IsCrouching(this: ai) )
  {
    if ( ai_useTransitions.valueInteger != 0 && ai_useStartTransitions.valueInteger != 0 )
    {
      ai->SetPosture(this: ai, a2: POSTURE_STANDING);
    }
    else
    {
      v15 = idEventArg::idEventArg(this: &v30, data: ai);
      idEventReceiver::ProcessEvent(
        this: v31,
        result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
        ev: *(const idEventDef **)&v15->type,
        arg1: (const idEventArg *)LODWORD(v15->value.v[1]));
    }
  }
  if ( idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v12) != nullptr )
  {
    v16 = ai->GetAAS(this: ai);
    AASPosition = idActor::GetAASPosition(this: v12, aas: v16);
    y = AASPosition->validOrigin.y;
    z = AASPosition->validOrigin.z;
    v28[1] = AASPosition->validOrigin.x;
    v29[1] = vec3_origin.x;
    v29[2] = vec3_origin.y;
    v29[3] = vec3_origin.z;
    *(float *)&v31[3].__vftable = 0.0;
    v28[2] = y;
    v28[3] = z;
    HIBYTE(v29[0]) = 118;
    HIBYTE(v31[5].listenerList) = 105;
    v31[5].listeningToList = nullptr;
    HIBYTE(v31[2].listeningToList) = 102;
    HIBYTE(v31[0].__vftable) = 105;
    v31[0].listenerList = (idList<idEventReceiver *,5> *)2;
    HIBYTE(v28[0]) = 118;
    v30.type = 105;
    v30.value.i = 10;
    v20 = idEventArg::idEventArg(this: &v32, data: ai);
    memcpy(Dst: v27, Src: v29, Size: sizeof(v27));
    memcpy(Dst: v26, Src: &v31[5].listenerList, Size: sizeof(v26));
    memcpy(Dst: v25, Src: &v31[2].listeningToList, Size: sizeof(v25));
    memcpy(Dst: v24, Src: v31, Size: sizeof(v24));
    memcpy(Dst: v23, Src: v28, Size: sizeof(v23));
    idEventReceiver::ProcessEvent(
      this: v33,
      result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
      ev: *(const idEventDef **)&v20->type,
      arg1: (const idEventArg *)LODWORD(v20->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v20->value.v[2]),
      arg3: *(const idEventArg **)&v30.type,
      arg4: (const idEventArg *)LODWORD(v30.value.v[1]),
      arg5: (const idEventArg *)LODWORD(v30.value.v[2]),
      arg6: v21,
      arg7: v22);
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
      ai->aiVolatile.animation.animFSM.overrideMoveFlags |= 0x1080u;
    idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
  }
  else
  {
LABEL_18:
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?Evaluate@ADVANCE_ShouldSneakUpOnEnemy@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB8608
// RVA : 0x00AB8608
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall ADVANCE_ShouldSneakUpOnEnemy::Evaluate(
        ADVANCE_ShouldSneakUpOnEnemy *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  const idDeclAIBehavior *decl; // r29
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r3
  const idEntity *v10; // r30
  idAIEntityState *v11; // r3
  aiSenseState_t *v12; // r28
  idPhysics *Physics; // r27
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r28
  float *v15; // r3
  double v16; // fp31
  double v17; // fp30
  double v18; // fp29
  __int64 v19; // r9
  double v20; // fp8
  double v21; // fp13
  idAIStateTransition::aiTransCode_t result; // r3
  double v23; // fp0

  decl = ai->aiEditable.behaviors.decl;
  if ( (*((_BYTE *)decl + 196) & 2) == 0 )
    return 0;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v8 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v8 == nullptr )
    return 0;
  v9 = idEntity::CastTo(c: v8);
  v10 = v9;
  if ( v9 == nullptr )
    return 0;
  v11 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v9);
  if ( v11 == nullptr )
    return 0;
  v12 = v11->senses.ptr[v11->lastSense];
  Physics = idEntity::GetPhysics(this: ai);
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v12);
  v15 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v16 = (float)(*v15 - ConfirmedPhysicalSafe->origin.x);
  v17 = (float)(v15[1] - ConfirmedPhysicalSafe->origin.y);
  v18 = (float)(v15[2] - ConfirmedPhysicalSafe->origin.z);
  if ( idAI2::IsFacingMe(this: ai, entity: v10, dotThreshold: 0.93000001) )
    return 0;
  LODWORD(v19) = decl->surroundRadius;
  v20 = (float)((float)v19 * (float)1.2);
  v21 = (float)((float)((float)v16 * (float)v16)
              + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)));
  if ( v21 >= (float)((float)v20 * (float)v20) )
    return 0;
  result = TRANSCODE_ADVANCE_SHOULD_SNEAK_UP_ON_ENEMY;
  v23 = (float)((float)v19 * (float)0.5);
  if ( v21 <= (float)((float)v23 * (float)v23) )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@ADVANCE_SneakUpOnEnemyDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB87A0
// RVA : 0x00AB87A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall ADVANCE_SneakUpOnEnemyDone::Evaluate(
        ADVANCE_SneakUpOnEnemyDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r3
  const idEntity *v10; // r29
  idAIEntityState *v11; // r30
  idAIStateTransition::aiTransCode_t result; // r3
  aiSenseState_t *v13; // r30
  idPhysics *Physics; // r29
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r30
  double v16; // fp10
  double v17; // fp8
  __int64 v18; // r4
  double v19; // fp1
  double v20; // fp13
  double v21; // fp0
  idFiniteStateMachine *FullPath; // r3
  bool v23; // zf

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return TRANSCODE_ADVANCE_SNEAK_UP_ON_ENEMY_DONE;
  v8 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v8 == nullptr )
    return TRANSCODE_ADVANCE_SNEAK_UP_ON_ENEMY_DONE;
  v9 = idEntity::CastTo(c: v8);
  v10 = v9;
  if ( v9 == nullptr )
    return TRANSCODE_ADVANCE_SNEAK_UP_ON_ENEMY_DONE;
  v11 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v9);
  if ( v11 == nullptr )
    return TRANSCODE_ADVANCE_SNEAK_UP_ON_ENEMY_DONE;
  if ( idAI2::IsFacingMe(this: ai, entity: v10, dotThreshold: 0.93000001) )
    return TRANSCODE_ADVANCE_SNEAK_UP_ON_ENEMY_SEEN;
  v13 = v11->senses.ptr[v11->lastSense];
  Physics = idEntity::GetPhysics(this: ai);
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v13);
  HIDWORD(v18) = Physics->GetOrigin(this: Physics, a2: 0);
  v16 = (float)(*(float *)(HIDWORD(v18) + 4) - ConfirmedPhysicalSafe->origin.y);
  v17 = (float)(*(float *)(HIDWORD(v18) + 8) - ConfirmedPhysicalSafe->origin.z);
  LODWORD(v18) = ai->aiEditable.behaviors.decl->surroundRadius;
  v19 = (float)((float)v18 * (float)0.5);
  v20 = (float)((float)((float)(*(float *)HIDWORD(v18) - ConfirmedPhysicalSafe->origin.x)
                      * (float)(*(float *)HIDWORD(v18) - ConfirmedPhysicalSafe->origin.x))
              + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)));
  if ( v20 < (float)((float)v19 * (float)v19) )
    return TRANSCODE_ADVANCE_SNEAK_UP_ON_ENEMY_CLOSE_ENOUGH;
  v21 = (float)((float)v18 * (float)1.2);
  if ( v20 > (float)((float)v21 * (float)v21) )
    return TRANSCODE_ADVANCE_SNEAK_UP_ON_ENEMY_TOO_FAR;
  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( FullPath == nullptr )
    return TRANSCODE_ADVANCE_SNEAK_UP_ON_ENEMY_DONE;
  v23 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v23 )
    return TRANSCODE_ADVANCE_SNEAK_UP_ON_ENEMY_DONE;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idAdvance_SneakUpOnEnemy@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB8958
// RVA : 0x00AB8958
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_SneakUpOnEnemy::AIState_EnterState(
        idAdvance_SneakUpOnEnemy *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r3
  const idEntity *v10; // r30
  idAI2_vtbl *v11; // r8
  idEventArg *v12; // r23
  idEventArg *v13; // r31
  const idEventArg *v14; // [sp+8h] [-298h]
  const idEventArg *v15; // [sp+Ch] [-294h]
  const idEventArg *v16; // [sp+10h] [-290h]
  _BYTE v17[20]; // [sp+70h] [-230h] BYREF
  _BYTE v18[20]; // [sp+90h] [-210h] BYREF
  _BYTE v19[20]; // [sp+B0h] [-1F0h] BYREF
  _BYTE v20[20]; // [sp+D0h] [-1D0h] BYREF
  _BYTE v21[20]; // [sp+F0h] [-1B0h] BYREF
  _BYTE v22[20]; // [sp+110h] [-190h] BYREF
  float v23[5]; // [sp+130h] [-170h] BYREF
  _DWORD v24[5]; // [sp+150h] [-150h] BYREF
  int v25; // [sp+170h] [-130h]
  int v26; // [sp+174h] [-12Ch]
  const idEventArg *v27; // [sp+178h] [-128h]
  const idEventArg *v28; // [sp+17Ch] [-124h]
  _DWORD v29[5]; // [sp+190h] [-110h] BYREF
  _DWORD v30[5]; // [sp+1B0h] [-F0h] BYREF
  float v31[5]; // [sp+1D0h] [-D0h] BYREF
  idEventArg v32; // [sp+1F0h] [-B0h] BYREF
  idEventArg v33; // [sp+210h] [-90h] BYREF
  idEventReceiver v34[9]; // [sp+230h] [-70h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v9 = idEntity::CastTo(c: v8), v10 = v9, v9 != nullptr) )
  {
    idAI2::SetAimFocusEntity(this: ai, ent: v9, keepFocusInView: true, aimPoint: AIMPOINT_BEST, timeout: -1);
    idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
    v11 = ai->__vftable;
    ai->aiVolatile.focus.enableBodyRotation = true;
    v11->SetWalkState(this: ai, a2: WALKSTATE_WALKING);
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    HIBYTE(v30[0]) = 105;
    v31[1] = 48.0;
    v23[3] = vec3_origin.z;
    v30[1] = 0;
    v23[2] = vec3_origin.y;
    HIBYTE(v23[0]) = 118;
    v23[1] = vec3_origin.x;
    HIBYTE(v29[0]) = 105;
    v29[1] = 0;
    HIBYTE(v31[0]) = 102;
    HIBYTE(v24[0]) = 105;
    v24[1] = 2;
    HIBYTE(v25) = 105;
    v26 = 11;
    v12 = idEventArg::idEventArg(this: &v32, data: v10);
    v13 = idEventArg::idEventArg(this: &v33, data: ai);
    memcpy(Dst: v22, Src: v30, Size: sizeof(v22));
    memcpy(Dst: v21, Src: v23, Size: sizeof(v21));
    memcpy(Dst: v20, Src: v29, Size: sizeof(v20));
    memcpy(Dst: v19, Src: v31, Size: sizeof(v19));
    memcpy(Dst: v18, Src: v24, Size: sizeof(v18));
    memcpy(Dst: v17, Src: v12, Size: sizeof(v17));
    idEventReceiver::ProcessEvent(
      this: v34,
      result: fsm,
      ev: *(const idEventDef **)&v13->type,
      arg1: (const idEventArg *)LODWORD(v13->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v13->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v25, 32),
      arg4: v27,
      arg5: v28,
      arg6: v14,
      arg7: v15,
      arg8: v16);
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?Evaluate@ADVANCE_ShouldThrowProjectile@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB8B78
// RVA : 0x00AB8B78
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

int __fastcall ADVANCE_ShouldThrowProjectile::Evaluate(
        ADVANCE_ShouldThrowProjectile *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  const idDeclAIBehavior *decl; // r24
  int value; // r8
  idEntity *v9; // r3
  idActor *v10; // r3
  idVehicle *v11; // r29
  idActor *v12; // r28
  bool v13; // r30
  idVehicle *v14; // r26
  const idAAS2 *v15; // r3
  encounterGroupRole_t currentRole; // r10
  aiItemSelect_t v17; // r11
  BOOL v18; // r27
  idEncounterGroup *EncounterGroup; // r3
  idAIEntityState *v20; // r3
  aiSenseState_t *v21; // r30
  idPhysics *Physics; // r3
  float *v23; // r29
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  double v25; // fp0
  double v26; // fp6
  idPresentable *presentable; // r11
  const idDeclAIBehavior *v28; // r29
  const aiPhysicalState_t *v29; // r3
  idPhysics *v30; // r29
  const aiPhysicalState_t *v31; // r28
  float *v32; // r3
  double v33; // fp9
  double v34; // fp0
  const aiPhysicalState_t *v35; // r3
  idAIGameState *p_aiGameState; // r30
  float y; // r7
  float z; // r6
  const idSpawnId **v39; // r29
  const idSpawnId **v40; // r3
  int v41; // r10
  idRenderWorld *v42; // r3
  idRenderWorld *v44; // r3
  int v45; // [sp+8h] [-1C8h]
  int v46; // [sp+Ch] [-1C4h]
  int v47; // [sp+10h] [-1C0h]
  int v48; // [sp+14h] [-1BCh]
  int v49; // [sp+18h] [-1B8h]
  int v50; // [sp+1Ch] [-1B4h]
  int v51; // [sp+20h] [-1B0h]
  int v52; // [sp+24h] [-1ACh]
  int v53; // [sp+28h] [-1A8h]
  idSpawnId *v54; // [sp+2Ch] [-1A4h]
  int v55; // [sp+30h] [-1A0h]
  idSpawnId *v56; // [sp+34h] [-19Ch]
  idVec3 v57; // [sp+50h] [-180h] BYREF
  float v58; // [sp+5Ch] [-174h] BYREF
  float v59; // [sp+60h] [-170h] BYREF
  float v60; // [sp+64h] [-16Ch] BYREF
  idVec3 v61; // [sp+68h] [-168h] BYREF
  float v62; // [sp+74h] [-15Ch] BYREF
  idVec3 v63; // [sp+78h] [-158h] BYREF
  idSpawnId v64; // [sp+84h] [-14Ch] BYREF
  idSpawnId v65; // [sp+88h] [-148h] BYREF
  idAIProjectileInfo v66; // [sp+90h] [-140h] BYREF
  trace_t v67; // [sp+100h] [-D0h] BYREF

  decl = ai->aiEditable.behaviors.decl;
  if ( decl->itemSelect[0] == AIITEMSELECT_NONE )
    return 0;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v9 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v9 == nullptr )
    return 0;
  v10 = (idActor *)idEntity::CastTo(c: v9);
  v11 = (idVehicle *)v10;
  if ( v10 == nullptr )
    return 0;
  v12 = idActor::CastTo(c: v10);
  v13 = false;
  v14 = idVehicle::CastTo(c: v11);
  if ( v12 != nullptr )
  {
    v15 = ai->GetAAS(this: ai);
    v13 = !idActor::GetAASPosition(this: v12, aas: v15)->valid;
  }
  if ( ai->aiVolatile.memory.enemyPathBlocked || ai->aiEditable.movement.turretMode )
    v13 = true;
  currentRole = ai->aiVolatile.groupStatus.currentRole;
  if ( currentRole == ROLE_CHARGE && decl->itemSelect[0] != AIITEMSELECT_IMP && !v13 )
    return 0;
  v17 = decl->itemSelect[0];
  if ( v17 == AIITEMSELECT_CLUB_MUTANT && !v13 && v14 == nullptr )
    return 0;
  if ( curTime < ai->aiVolatile.memory.nextThrowTime
    || ai->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType == ANIMWEBAI_RUNINDEXTYPE_DUCK )
  {
    return 0;
  }
  v18 = v13;
  if ( !v13
    && v14 == nullptr
    && currentRole == ROLE_NONE
    && (v17 == AIITEMSELECT_PIPE_BANDIT || v17 == AIITEMSELECT_DUAL_MUTANT)
    && idAI2::GetEncounterGroup(this: ai) != nullptr )
  {
    EncounterGroup = idAI2::GetEncounterGroup(this: ai);
    if ( idEncounterGroup::GetClosestActiveGroupMemberToEntity(this: EncounterGroup, ent: v11) == ai )
      return 0;
  }
  v20 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v11);
  if ( v20 == nullptr || v12 == nullptr && v14 == nullptr )
    return 0;
  v21 = v20->senses.ptr[1];
  if ( v21->lastUnconfirmedStimTime < 0 || curTime - v21->lastConfirmedStimTime >= 1000 )
    return 0;
  Physics = idEntity::GetPhysics(this: ai);
  v23 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v21);
  v25 = v23[2];
  v26 = (float)(ConfirmedPhysicalSafe->origin.y - v23[1]);
  v57.x = ConfirmedPhysicalSafe->origin.x - *v23;
  v57.y = v26;
  v57.z = ConfirmedPhysicalSafe->origin.z - (float)v25;
  idVec3::NormalizeFast(this: &v57);
  presentable = ai->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: ai);
    presentable = ai->presentable;
  }
  if ( (float)((float)(presentable->axis.mat[0].x * v57.x)
             + (float)((float)(presentable->axis.mat[0].y * v57.y) + (float)(presentable->axis.mat[0].z * v57.z))) < (double)decl->minThrowDot )
    return 0;
  v59 = 0.0;
  v62 = 0.0;
  v60 = 0.0;
  v58 = 0.0;
  idAIProjectileInfo::idAIProjectileInfo(this: &v66);
  v28 = ai->aiEditable.behaviors.decl;
  v29 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v21);
  if ( (unsigned __int8)idAI2::GetMinMaxRangedAttackDistancesForTargetPos(
                          this: ai,
                          selector: (const aiItemSelect_t)v28->itemSelect[0],
                          targetPos: &v29->origin,
                          outProjectileInfo: &v66,
                          outMinRange: &v59,
                          outMinOptimalRange: &v62,
                          outMaxOptimalRange: &v60,
                          outMaxRange: &v58) == 0 )
    return 0;
  v30 = idEntity::GetPhysics(this: ai);
  v31 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v21);
  v32 = (float *)v30->GetOrigin(this: v30, a2: 0);
  v33 = (float)(v32[1] - v31->origin.y);
  v34 = (float)((float)((float)v33 * (float)v33) + (float)((float)(*v32 - v31->origin.x) * (float)(*v32 - v31->origin.x)));
  if ( !v18 && v14 == nullptr && (v34 < (float)(v59 * v59) || v34 > (float)(v58 * v58)) )
    return 0;
  ai->GetEyePos(this: ai, a2: &v63);
  v35 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v21);
  p_aiGameState = &gameLocal->aiGameState;
  y = v35->eyePos.y;
  z = v35->eyePos.z;
  v61.x = v35->eyePos.x;
  v61.y = y;
  v61.z = z;
  v39 = (const idSpawnId **)idSpawnId::idSpawnId(this: &v65, ent: ai);
  v40 = (const idSpawnId **)idSpawnId::idSpawnId(this: &v64, ent: ai);
  if ( (unsigned __int8)idAIVisibility::TraceVisible(
                          gameState: p_aiGameState,
                          fromPoint: &v63,
                          toPoint: &v61,
                          ignoreId: *v40,
                          destId: *v39,
                          tr: &v67,
                          seeThroughBreakables: true,
                          a8: v41,
                          a9: v45,
                          a10: v46,
                          a11: v47,
                          a12: v48,
                          a13: v49,
                          a14: v50,
                          a15: v51,
                          a16: v52,
                          a17: v53,
                          a18: v54,
                          a19: v55,
                          a20: v56) == 0 )
  {
    if ( idAI2::GetDebugLevel() > 0 && ai_debugThrow.valueInteger != 0 )
    {
      v42 = common->RW(this: common);
      v42->DebugLine(this: v42, a2: (const idVec4 *)&idColor::colorRed, a3: &v63, a4: &v61, a5: 1000, a6: true);
    }
    return 0;
  }
  if ( idAI2::GetDebugLevel() > 0 && ai_debugThrow.valueInteger != 0 )
  {
    v44 = common->RW(this: common);
    v44->DebugLine(this: v44, a2: (const idVec4 *)&idColor::colorGreen, a3: &v63, a4: &v61, a5: 1000, a6: true);
  }
  return 384;
}


// ========================================================================
// ?Evaluate@ADVANCE_ThrowProjectileDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB9080
// RVA : 0x00AB9080
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall ADVANCE_ThrowProjectileDone::Evaluate(
        ADVANCE_ThrowProjectileDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  int value; // r8
  idEntity *v8; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v10; // zf

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( FullPath == nullptr )
    return TRANSCODE_ADVANCE_THROW_PROJECTILE_DONE;
  if ( idFiniteStateMachine::GetStatus(this: FullPath) == 0 )
    return TRANSCODE_ADVANCE_THROW_PROJECTILE_DONE;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return TRANSCODE_ADVANCE_THROW_PROJECTILE_DONE;
  v8 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v8 == nullptr )
    return TRANSCODE_ADVANCE_THROW_PROJECTILE_DONE;
  v10 = idEntity::CastTo(c: v8) != nullptr;
  result = 0;
  if ( !v10 )
    return TRANSCODE_ADVANCE_THROW_PROJECTILE_DONE;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idAdvance_ThrowProjectile@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB9120
// RVA : 0x00AB9120
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __fastcall idAdvance_ThrowProjectile::AIState_EnterState(
        idAdvance_ThrowProjectile *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  idEntity *v10; // r3
  const idEntity *v11; // r30
  idAIEntityState *v12; // r3
  aiSenseState_t *v13; // r29
  overrideAnim_t overrideAnim; // r30
  idEventArg *v15; // r3
  idEventArg *v16; // r24
  const idDeclAIBehavior *decl; // r11
  int minThrowInterval; // r30
  int v19; // r11
  unsigned int v20; // r9
  int GameMs; // r3
  _BYTE v22[20]; // [sp+70h] [-160h] BYREF
  _DWORD v23[5]; // [sp+90h] [-140h] BYREF
  idEventArg v24; // [sp+B0h] [-120h] BYREF
  idEventArg v25; // [sp+D0h] [-100h] BYREF
  idEventReceiver v26[2]; // [sp+F0h] [-E0h] BYREF
  idAIProjectileInfo v27; // [sp+110h] [-C0h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    goto LABEL_16;
  v9 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v9 == nullptr )
    goto LABEL_16;
  v10 = idEntity::CastTo(c: v9);
  v11 = v10;
  if ( v10 == nullptr )
    goto LABEL_16;
  idAI2::SetAimFocusEntity(this: ai, ent: v10, keepFocusInView: true, aimPoint: AIMPOINT_BEST, timeout: -1);
  ai->aiVolatile.focus.enableBodyRotation = true;
  v12 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v11);
  if ( v12 == nullptr )
    goto LABEL_16;
  v13 = v12->senses.ptr[1];
  if ( v13->lastUnconfirmedStimTime < 0 )
    goto LABEL_16;
  if ( ai->aiEditable.behaviors.decl->itemSelect[0] != AIITEMSELECT_HEAVY_BANDIT )
  {
    idAIProjectileInfo::idAIProjectileInfo(this: &v27);
    if ( (unsigned __int8)idAI2::LaunchProjectile(
                            this: ai,
                            target: v11,
                            senseState: v13,
                            projectileInfo: &v27,
                            itemSelect: ai->aiEditable.behaviors.decl->itemSelect) != 0 )
    {
      overrideAnim = v27.overrideAnim;
      goto LABEL_10;
    }
LABEL_16:
    idState::SetEnterFailed(this, failed: true);
    return;
  }
  overrideAnim = ANIMOVERRIDE_THROW_PROJECTILE;
LABEL_10:
  idAIState::ClearQueuedActions(this, ai, parentFSM: fsm, curTime);
  v23[1] = overrideAnim;
  HIBYTE(v23[0]) = 105;
  v15 = idEventArg::idEventArg(this: &v24, data: ai);
  idEventReceiver::ProcessEvent(
    this: (idEventReceiver *)&v25,
    result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
    ev: *(const idEventDef **)&v15->type,
    arg1: (const idEventArg *)LODWORD(v15->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v15->value.v[2]));
  if ( idle )
  {
    HIBYTE(v23[0]) = 105;
    v23[1] = 1;
    v24.type = 105;
    v24.value.i = -1;
    v16 = idEventArg::idEventArg(this: &v25, data: ai);
    memcpy(Dst: v22, Src: v23, Size: sizeof(v22));
    idEventReceiver::ProcessEvent(
      this: v26,
      result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
      ev: *(const idEventDef **)&v16->type,
      arg1: (const idEventArg *)LODWORD(v16->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v16->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v24.type, 32));
  }
  idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
  decl = ai->aiEditable.behaviors.decl;
  minThrowInterval = decl->minThrowInterval;
  v19 = idRandom2::RandomInt(this: &clientGame->random, max: decl->maxThrowInterval - minThrowInterval)
      + minThrowInterval;
  if ( (ai->aiVolatile.groupStatus.condition & 0x8000) != 0 )
    v19 = minThrowInterval;
  ai->aiVolatile.memory.nextThrowTime = v19 + curTime;
  v20 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v20;
  if ( (signed int)(((v20 >> 10) & 0x7FFF) % 0x64) < ai->aiEditable.behaviors.decl->rageBehaviors.angryRageAfterMissingChance )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idAIMemory::SetWantAngryRageTime(this: &ai->aiVolatile.memory, t: GameMs + 1000, debugReason: "miss enemy");
  }
}


// ========================================================================
// ?CanUse@idAdvanceFSM@@SA_NPAVidAI2@@PAVidFiniteStateMachine@@H@Z
// EA  : 0x82AB9410
// RVA : 0x00AB9410
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

int __fastcall idAdvanceFSM::CanUse(idAI2 *ai, idFiniteStateMachine *parentFSM, const int curTime)
{
  const idDeclAIBehavior *decl; // r30
  int result; // r3
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r4
  aiSenseState_t *EnemySenseState; // r29
  idPhysics *Physics; // r3
  float *v11; // r31
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  double v13; // fp8
  double v14; // fp4
  double v15; // fp1

  decl = ai->aiEditable.behaviors.decl;
  if ( (*((_BYTE *)decl + 196) & 0x20) == 0 )
    return 0;
  if ( !idAI2::AwareOfEnemy(this: ai) )
    return 0;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v7 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr )
    return 0;
  v8 = idEntity::CastTo(c: v7);
  if ( v8 == nullptr
    || idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8) == nullptr
    || ai->aiEditable.movement.noAdvanceIfStatic && ai->aiVolatile.physics.moveState.movementMode == AIMOVEMODE_STATIC )
  {
    return 0;
  }
  if ( (*((_BYTE *)decl + 196) & 8) != 8 )
    return 1;
  if ( ai->aiVolatile.groupStatus.currentRole == ROLE_CHARGE )
    return 1;
  EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  Physics = idEntity::GetPhysics(this: ai);
  v11 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
  v13 = (float)(ConfirmedPhysicalSafe->origin.z - v11[2]);
  v14 = (float)(ConfirmedPhysicalSafe->origin.y - v11[1]);
  v15 = (float)((float)((float)v14 * (float)v14)
              + (float)((float)((float)(ConfirmedPhysicalSafe->origin.x - *v11)
                              * (float)(ConfirmedPhysicalSafe->origin.x - *v11))
                      + (float)((float)v13 * (float)v13)));
  result = 0;
  if ( v15 <= (float)(decl->maxChargeDistance * decl->maxChargeDistance) )
    return 1;
  return result;
}


// ========================================================================
// ?CanUse@idAdvanceFSM@@UBA_NPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AB9580
// RVA : 0x00AB9580
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

int __fastcall idAdvanceFSM::CanUse(idAdvanceFSM *this, idFiniteStateMachine *parentFSM, int curTime)
{
  idAI2 *Owner; // r3
  idAI2 *v6; // r3

  Owner = (idAI2 *)idFiniteStateMachine::GetOwner(this: parentFSM);
  v6 = idAI2::CastTo(c: Owner);
  return idAdvanceFSM::CanUse(ai: v6, parentFSM, curTime);
}


// ========================================================================
// ?Evaluate@ADVANCE_AdvanceDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB95D0
// RVA : 0x00AB95D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

int __fastcall ADVANCE_AdvanceDone::Evaluate(
        ADVANCE_AdvanceDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  return (unsigned __int8)idAdvanceFSM::CanUse(ai, parentFSM, curTime) != 0 ? 0 : 0x166;
}


// ========================================================================
// `dynamic initializer for 'ai_enableNonStrafeMoveToEntity''
// EA  : 0x83369500
// RVA : 0x01369500
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_advance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_enableNonStrafeMoveToEntity__()
{
  idCVar::idCVar(
    this: &ai_enableNonStrafeMoveToEntity,
    name: "ai_enableNonStrafeMoveToEntity",
    value: "1",
    flags: 1,
    description: "1 = ai with strafeMoveToEntity false will not keep focus in view when moving to entity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_enableNonStrafeMoveToEntity__);
}

