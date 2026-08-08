
// ========================================================================
// ?Evaluate@OC_ReachedCover@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADB1F8
// RVA : 0x00ADB1F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_ReachedCover::Evaluate(
        OC_ReachedCover *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::IsMoveDone(this: ai, checkAlignment: false) ? 0 : 0x124;
}


// ========================================================================
// ?InternalInitState@idOpenCombat_Default@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADB238
// RVA : 0x00ADB238
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_Default::InternalInitState(idOpenCombat_Default *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &OC_IsCrouched::Type, nextStateType: &idOpenCombat_Crouch::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_EnemyNotVisible::Type,
    nextStateType: &idOpenCombat_EnemyNotVisible::Type);
  idState::AddStateTransition(this, fsm, transType: &OC_AttackIdle::Type, nextStateType: &idOpenCombat_AttackIdle::Type);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_MoveTowardEnemy@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADB2B8
// RVA : 0x00ADB2B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_MoveTowardEnemy::InternalInitState(
        idOpenCombat_MoveTowardEnemy *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_EnemyCloseEnoughAndVisible::Type,
    nextStateType: &idOpenCombat_AttackIdle::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ReachedEnemy::Type,
    nextStateType: &idAIStateDone::Type,
    transCode: 265);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ReachedEnemy::Type,
    nextStateType: &idOpenCombat_AttackIdle::Type,
    transCode: 264);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldMoveToRecharge::Type,
    nextStateType: &idOpenCombat_MoveToRecharge::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveFailed::Type,
    nextStateType: &idOpenCombat_MoveTowardEnemyFailed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveFailedAny::Type,
    nextStateType: &idOpenCombat_MoveTowardEnemyFailed::Type);
  idState::AddStateTransition(this, fsm, transType: &OC_ReloadCrouched::Type, nextStateType: &idOpenCombat_Crouch::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 300);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 301);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 302);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 303);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 304);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 305);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 306);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 307);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_MoveToSightEnemy@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADB468
// RVA : 0x00ADB468
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_MoveToSightEnemy::InternalInitState(
        idOpenCombat_MoveToSightEnemy *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_EnemyVisible::Type,
    nextStateType: &idOpenCombat_AttackIdle::Type);
  idState::AddStateTransition(this, fsm, transType: &OC_ShouldEndOpenCombat::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ReachedAttackPos::Type,
    nextStateType: &idOpenCombat_AttackIdle::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldMoveToRecharge::Type,
    nextStateType: &idOpenCombat_MoveToRecharge::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveFailed::Type,
    nextStateType: &idOpenCombat_MoveTowardEnemyFailed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveFailedAny::Type,
    nextStateType: &idOpenCombat_MoveTowardEnemyFailed::Type);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_StartThrowProjectile@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADB528
// RVA : 0x00ADB528
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_StartThrowProjectile::InternalInitState(
        idOpenCombat_StartThrowProjectile *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ThrowProjectile::Type,
    nextStateType: &idOpenCombat_ThrowProjectile::Type,
    transCode: 285);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ThrowProjectile::Type,
    nextStateType: &idOpenCombat_AttackIdle::Type,
    transCode: 286);
}


// ========================================================================
// ?AIState_IsWaiting@idOpenCombat_StartThrowProjectile@@UBA_NPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADB580
// RVA : 0x00ADB580
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

BOOL __fastcall idOpenCombat_StartThrowProjectile::AIState_IsWaiting(
        idOpenCombat_StartThrowProjectile *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  return (unsigned __int8)idAI2::WaitingOnTrajectoryTest(this: ai) != 0;
}


// ========================================================================
// ?Evaluate@OC_ThrowProjectileFailed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADB5B0
// RVA : 0x00ADB5B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_ThrowProjectileFailed::Evaluate(
        OC_ThrowProjectileFailed *this,
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
  result = TRANSCODE_OC_THROW_PROJECTILE_FAILED;
  if ( !v7 )
    return 0;
  return result;
}


// ========================================================================
// ?InternalInitState@idOpenCombat_ThrowProjectile@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADB5F8
// RVA : 0x00ADB5F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_ThrowProjectile::InternalInitState(
        idOpenCombat_ThrowProjectile *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ThrowProjectileFailed::Type,
    nextStateType: &idOpenCombat_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ThrowProjectileFinished::Type,
    nextStateType: &idOpenCombat_AttackIdle::Type);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_AttackIdle@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADB660
// RVA : 0x00ADB660
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_AttackIdle::InternalInitState(
        idOpenCombat_AttackIdle *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &OC_ShouldRage::Type, nextStateType: &idOpenCombat_Rage::Type);
  idState::AddStateTransition(this, fsm, transType: &OC_EnemyIsDead::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ChargeTurret::Type,
    nextStateType: &idOpenCombat_ChargeMelee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldReload::Type,
    nextStateType: &idOpenCombat_MoveOutOfSightAndReload::Type,
    transCode: 282);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldReload::Type,
    nextStateType: &idOpenCombat_ReloadWeapon::Type,
    transCode: 283);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldReloadEnemyOutOfAAS::Type,
    nextStateType: &idOpenCombat_ReloadWeapon::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldMoveToRecharge::Type,
    nextStateType: &idOpenCombat_MoveToRecharge::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_EnemyNotVisible::Type,
    nextStateType: &idOpenCombat_EnemyNotVisible::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_FireBlocked::Type,
    nextStateType: &idOpenCombat_EnemyNotVisible::Type);
  idState::AddStateTransition(this, fsm, transType: &OC_ShouldEndOpenCombat::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_CloseMelee::Type,
    nextStateType: &idOpenCombat_AttackMelee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldThrowProjectile::Type,
    nextStateType: &idOpenCombat_StartThrowProjectile::Type);
  idState::AddStateTransition(this, fsm, transType: &OC_ShouldShoot::Type, nextStateType: &idOpenCombat_Shoot::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ChargeMeleeNotIfRetreating::Type,
    nextStateType: &idOpenCombat_ChargeMelee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldMoveToRoleHintNode::Type,
    nextStateType: &idOpenCombat_MoveToRoleHintNode::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldMoveTowardEnemy::Type,
    nextStateType: &idOpenCombat_MoveTowardEnemy::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_AttackMove::Type,
    nextStateType: &idOpenCombat_AttackMove::Type,
    transCode: 270);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_AttackMove::Type,
    nextStateType: &idOpenCombat_Crouch::Type,
    transCode: 308);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 300);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 301);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 302);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 303);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 304);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 305);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 306);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 307);
}


// ========================================================================
// ?Evaluate@OC_ReachedAttackPos@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADB950
// RVA : 0x00ADB950
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_ReachedAttackPos::Evaluate(
        OC_ReachedAttackPos *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::IsMoveDone(this: ai, checkAlignment: false) ? 0 : 0x10F;
}


// ========================================================================
// ?InternalInitState@idOpenCombat_AttackMove@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADB990
// RVA : 0x00ADB990
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_AttackMove::InternalInitState(
        idOpenCombat_AttackMove *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ReachedAttackPos::Type,
    nextStateType: &idOpenCombat_AttackIdle::Type);
  idState::AddStateTransition(this, fsm, transType: &OC_MoveFailed::Type, nextStateType: &idOpenCombat_MoveFailed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveFailedAny::Type,
    nextStateType: &idOpenCombat_MoveFailed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_EnemyFartherThanOptimalRange::Type,
    nextStateType: &idOpenCombat_AttackIdle::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ChargeMelee::Type,
    nextStateType: &idOpenCombat_ChargeMelee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldMoveToRecharge::Type,
    nextStateType: &idOpenCombat_MoveToRecharge::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 300);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 301);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 302);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 303);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 304);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 305);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 306);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 307);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_Shoot@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADBB20
// RVA : 0x00ADBB20
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_Shoot::InternalInitState(idOpenCombat_Shoot *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_CloseMelee::Type,
    nextStateType: &idOpenCombat_AttackMelee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_StopShooting::Type,
    nextStateType: &idOpenCombat_AttackIdle::Type);
}


// ========================================================================
// ?Evaluate@OC_ChargeFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADBB88
// RVA : 0x00ADBB88
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_ChargeFinished::Evaluate(
        OC_ChargeFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::IsMoveDone(this: ai, checkAlignment: false) ? 0 : 0x116;
}


// ========================================================================
// ?InternalInitState@idOpenCombat_ChargeMelee@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADBBC8
// RVA : 0x00ADBBC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_ChargeMelee::InternalInitState(
        idOpenCombat_ChargeMelee *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ChargeTimedOut::Type,
    nextStateType: &idOpenCombat_AttackIdle::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_TargetMoved::Type,
    nextStateType: &idOpenCombat_AttackIdle::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ChargeFinished::Type,
    nextStateType: &idOpenCombat_AttackMelee::Type);
  idState::AddStateTransition(this, fsm, transType: &OC_MoveFailed::Type, nextStateType: &idOpenCombat_MoveFailed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveFailedAny::Type,
    nextStateType: &idOpenCombat_MoveFailed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldMoveToRecharge::Type,
    nextStateType: &idOpenCombat_MoveToRecharge::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldThrowProjectile::Type,
    nextStateType: &idOpenCombat_StartThrowProjectile::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldLeapAttack::Type,
    nextStateType: &idOpenCombat_LeapAttack::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_ChargeSidestep::Type,
    transCode: 304);
}


// ========================================================================
// ?Evaluate@OC_MeleeFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADBCE0
// RVA : 0x00ADBCE0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_MeleeFinished::Evaluate(
        OC_MeleeFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  return idFile_SaveGamePipelined::GetFullPath(this: state) != 0 ? 0 : 0x111;
}


// ========================================================================
// ?InternalInitState@idOpenCombat_AttackMelee@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADBD18
// RVA : 0x00ADBD18
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_AttackMelee::InternalInitState(
        idOpenCombat_AttackMelee *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MeleeFinished::Type,
    nextStateType: &idOpenCombat_AttackIdle::Type);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_LeapAttack@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADBD30
// RVA : 0x00ADBD30
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_LeapAttack::InternalInitState(
        idOpenCombat_LeapAttack *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_LeapAttackFailed::Type,
    nextStateType: &idOpenCombat_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_LeapAttackDone::Type,
    nextStateType: &idOpenCombat_AttackIdle::Type);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_MoveToCoverAndReload@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADBD98
// RVA : 0x00ADBD98
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_MoveToCoverAndReload::InternalInitState(
        idOpenCombat_MoveToCoverAndReload *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &OC_MoveFailed::Type, nextStateType: &idOpenCombat_Crouch::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ReachedCoverExposed::Type,
    nextStateType: &idOpenCombat_Crouch::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ReachedCover::Type,
    nextStateType: &idOpenCombat_ReloadWeapon::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveFailedAny::Type,
    nextStateType: &idOpenCombat_ReloadWeapon::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 300);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 301);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 302);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 303);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 304);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 305);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_MoveOutOfSightAndReload@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADBEC0
// RVA : 0x00ADBEC0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_MoveOutOfSightAndReload::InternalInitState(
        idOpenCombat_MoveOutOfSightAndReload *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &OC_MoveFailed::Type, nextStateType: &idOpenCombat_Crouch::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ReachedCoverExposed::Type,
    nextStateType: &idOpenCombat_Crouch::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ReachedCover::Type,
    nextStateType: &idOpenCombat_ReloadWeapon::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldMoveToRecharge::Type,
    nextStateType: &idOpenCombat_MoveToRecharge::Type);
  idState::AddStateTransition(this, fsm, transType: &OC_MoveFailedAny::Type, nextStateType: &idOpenCombat_Crouch::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 300);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 301);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 302);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 303);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 304);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 305);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_ReloadWeapon@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADC000
// RVA : 0x00ADC000
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_ReloadWeapon::InternalInitState(
        idOpenCombat_ReloadWeapon *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ReloadFinishedCrouch::Type,
    nextStateType: &idOpenCombat_Crouch::Type);
  idState::AddStateTransition(this, fsm, transType: &OC_ReloadFinished::Type, nextStateType: &idOpenCombat_Stand::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 300);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 301);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 302);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 303);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 304);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 305);
}


// ========================================================================
// ?AIState_EnterState@idCombatScenePoint_Reload@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADC0F0
// RVA : 0x00ADC0F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idCombatScenePoint_Reload::AIState_EnterState(
        idCombatScenePoint_Reload *this,
        idAI2 *ai,
        idEventArg *fsm,
        int curTime)
{
  idAI2::StartReloading(this: ai, fsm, state: this, curTime, reloadSlot: EQUIP_NONE);
}


// ========================================================================
// ?AIState_ExitState@idOpenCombat_ReloadWeapon@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADC108
// RVA : 0x00ADC108
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_ReloadWeapon::AIState_ExitState(
        idOpenCombat_ReloadWeapon *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAI2::ReleaseCover(this: ai);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_Stand@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADC110
// RVA : 0x00ADC110
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_Stand::InternalInitState(idOpenCombat_Stand *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &OC_IsStanding::Type, nextStateType: &idOpenCombat_AttackIdle::Type);
}


// ========================================================================
// ?Evaluate@OC_IsCrouched@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADC128
// RVA : 0x00ADC128
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_IsCrouched::Evaluate(
        OC_IsCrouched *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return ai->GetPosture(this: ai) != POSTURE_CROUCHED ? 0 : 0x127;
}


// ========================================================================
// ?InternalInitState@idOpenCombat_Crouch@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADC170
// RVA : 0x00ADC170
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_Crouch::InternalInitState(idOpenCombat_Crouch *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ReloadCrouched::Type,
    nextStateType: &idOpenCombat_ReloadWeapon::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ChargeMeleeNotIfRetreating::Type,
    nextStateType: &idOpenCombat_ChargeMelee::Type);
  idState::AddStateTransition(this, fsm, transType: &OC_ShouldEndOpenCombat::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldMoveToRecharge::Type,
    nextStateType: &idOpenCombat_MoveToRecharge::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldMoveToRoleHintNode::Type,
    nextStateType: &idOpenCombat_MoveToRoleHintNode::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldThrowProjectile::Type,
    nextStateType: &idOpenCombat_StartThrowProjectile::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldMoveTowardEnemy::Type,
    nextStateType: &idOpenCombat_MoveTowardEnemy::Type);
  idState::AddStateTransition(this, fsm, transType: &OC_StopCrouching::Type, nextStateType: &idOpenCombat_Stand::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_AttackMove::Type,
    nextStateType: &idOpenCombat_AttackMove::Type,
    transCode: 270);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 300);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 301);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 302);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 303);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 304);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 305);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 306);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 307);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_EnemyNotVisible@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADC358
// RVA : 0x00ADC358
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_EnemyNotVisible::InternalInitState(
        idOpenCombat_EnemyNotVisible *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &OC_EnemyVisible::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &OC_EnemyClose::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldMoveToSightEnemy::Type,
    nextStateType: &idOpenCombat_MoveToSightEnemy::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldMoveToRoleHintNode::Type,
    nextStateType: &idOpenCombat_MoveToRoleHintNode::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldMoveTowardEnemy::Type,
    nextStateType: &idOpenCombat_MoveTowardEnemy::Type);
  idState::AddStateTransition(this, fsm, transType: &OC_ShouldEndOpenCombat::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldMoveToRecharge::Type,
    nextStateType: &idOpenCombat_MoveToRecharge::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldReload::Type,
    nextStateType: &idOpenCombat_MoveOutOfSightAndReload::Type,
    transCode: 282);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldReload::Type,
    nextStateType: &idOpenCombat_ReloadWeapon::Type,
    transCode: 283);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_Sidestep@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADC470
// RVA : 0x00ADC470
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_Sidestep::InternalInitState(idOpenCombat_Sidestep *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &OC_SidestepDone::Type, nextStateType: &idOpenCombat_Default::Type);
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_Sidestep@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADC488
// RVA : 0x00ADC488
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_Sidestep::AIState_EnterState(
        idOpenCombat_Sidestep *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idAI2::SetupDiveDodgeOrFlinchAction(this: ai, moveReason: 8, state: this, fsm);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_ChargeSidestep@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADC4A0
// RVA : 0x00ADC4A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_ChargeSidestep::InternalInitState(
        idOpenCombat_ChargeSidestep *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_SidestepDone::Type,
    nextStateType: &idOpenCombat_ChargeMelee::Type);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_Rage@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADC4B8
// RVA : 0x00ADC4B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_Rage::InternalInitState(idOpenCombat_Rage *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &OC_RageDone::Type, nextStateType: &idOpenCombat_Default::Type);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_MoveTowardEnemyFailed@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADC4D0
// RVA : 0x00ADC4D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_MoveTowardEnemyFailed::InternalInitState(
        idOpenCombat_MoveTowardEnemyFailed *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &OC_AttackMove::Type, nextStateType: &idOpenCombat_AttackMove::Type);
  idState::AddStateTransition(this, fsm, transType: &OC_EndOpenCombat::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_MoveFailed@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADC538
// RVA : 0x00ADC538
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_MoveFailed::InternalInitState(
        idOpenCombat_MoveFailed *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveFailedDone::Type,
    nextStateType: &idOpenCombat_AttackIdle::Type);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_MoveToRecharge@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADC550
// RVA : 0x00ADC550
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_MoveToRecharge::InternalInitState(
        idOpenCombat_MoveToRecharge *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &OC_MoveFailed::Type, nextStateType: &idOpenCombat_MoveFailed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_RechargeHintGone::Type,
    nextStateType: &idOpenCombat_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_IsInRechargeZone::Type,
    nextStateType: &idOpenCombat_Recharging::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveFailedAny::Type,
    nextStateType: &idOpenCombat_MoveFailed::Type);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_Recharging@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADC5D8
// RVA : 0x00ADC5D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_Recharging::InternalInitState(
        idOpenCombat_Recharging *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ReloadCrouched::Type,
    nextStateType: &idOpenCombat_ReloadWeapon::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_RechargeHintGone::Type,
    nextStateType: &idOpenCombat_Default::Type);
  idState::AddStateTransition(this, fsm, transType: &OC_RechargeDone::Type, nextStateType: &idOpenCombat_Default::Type);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_MoveToRoleHintNode@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADC640
// RVA : 0x00ADC640
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_MoveToRoleHintNode::InternalInitState(
        idOpenCombat_MoveToRoleHintNode *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveToRoleHintNodeDone::Type,
    nextStateType: &idOpenCombat_AttackIdle::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldMoveToRecharge::Type,
    nextStateType: &idOpenCombat_MoveToRecharge::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_CloseMelee::Type,
    nextStateType: &idOpenCombat_AttackMelee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ShouldThrowProjectile::Type,
    nextStateType: &idOpenCombat_StartThrowProjectile::Type);
  idState::AddStateTransition(this, fsm, transType: &OC_ShouldShoot::Type, nextStateType: &idOpenCombat_Shoot::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_ChargeMeleeNotIfRetreating::Type,
    nextStateType: &idOpenCombat_ChargeMelee::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveToRoleHintNodeFailedObstructed::Type,
    nextStateType: &idOpenCombat_MoveFailed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveToRoleHintNodeFailedStuck::Type,
    nextStateType: &idOpenCombat_MoveFailed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveToRoleHintNodeFailedTimedOut::Type,
    nextStateType: &idOpenCombat_MoveFailed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveToRoleHintNodeFailedInvalidEntity::Type,
    nextStateType: &idOpenCombat_MoveFailed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveToRoleHintNodeFailedUnreachable::Type,
    nextStateType: &idOpenCombat_MoveFailed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveToRoleHintNodeFailedError::Type,
    nextStateType: &idOpenCombat_MoveFailed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveToRoleHintNodeFailedPathingFailed::Type,
    nextStateType: &idOpenCombat_MoveFailed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveToRoleHintNodeFailedNoPathGroup::Type,
    nextStateType: &idOpenCombat_MoveFailed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveToRoleHintNodeFailedNoPathPoint::Type,
    nextStateType: &idOpenCombat_MoveFailed::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_MoveFailedAny::Type,
    nextStateType: &idOpenCombat_MoveFailed::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 300);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 301);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 302);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 303);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 304);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 305);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 306);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &OC_ShouldSidestep::Type,
    nextStateType: &idOpenCombat_Sidestep::Type,
    transCode: 307);
}


// ========================================================================
// ?InternalInitState@idOpenCombat_PlayOverrideAnim@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADC8C8
// RVA : 0x00ADC8C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_PlayOverrideAnim::InternalInitState(
        idOpenCombat_PlayOverrideAnim *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &OC_PlayOverrideAnimDone::Type,
    nextStateType: &idOpenCombat_Default::Type);
}


// ========================================================================
// ?InitStates@idOpenCombatFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82ADC8E0
// RVA : 0x00ADC8E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombatFSM::InitStates(idOpenCombatFSM *this, const idFiniteStateMachineParams *params)
{
  idAIFSM::InitStates(this, params);
  this->AddState(this, a2: &this->stateDefault);
  this->AddState(this, a2: &this->stateMoveTowardEnemy);
  this->AddState(this, a2: &this->stateMoveToSightEnemy);
  this->AddState(this, a2: &this->stateAttackIdle);
  this->AddState(this, a2: &this->stateAttackMove);
  this->AddState(this, a2: &this->stateReachedEnemyPos);
  this->AddState(this, a2: &this->stateStartThrowProjectile);
  this->AddState(this, a2: &this->stateShoot);
  this->AddState(this, a2: &this->stateThrowProjectile);
  this->AddState(this, a2: &this->stateAttackMelee);
  this->AddState(this, a2: &this->stateLeapAttack);
  this->AddState(this, a2: &this->stateChargeMelee);
  this->AddState(this, a2: &this->stateMoveToCoverAndReload);
  this->AddState(this, a2: &this->stateMoveOutOfSightAndReload);
  this->AddState(this, a2: &this->stateStand);
  this->AddState(this, a2: &this->stateCrouch);
  this->AddState(this, a2: &this->stateReloadWeapon);
  this->AddState(this, a2: &this->stateEnemyNotVisible);
  this->AddState(this, a2: &this->stateSidestep);
  this->AddState(this, a2: &this->stateChargeSidestep);
  this->AddState(this, a2: &this->stateMoveTowardEnemyFailed);
  this->AddState(this, a2: &this->stateMoveFailed);
  this->AddState(this, a2: &this->stateRage);
  this->AddState(this, a2: &this->stateMoveToRecharge);
  this->AddState(this, a2: &this->stateRecharging);
  this->AddState(this, a2: &this->stateMoveToRoleHintNode);
  this->AddState(this, a2: &this->statePlayOverrideAnim);
}


// ========================================================================
// ?Evaluate@OC_MoveFailed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADCB98
// RVA : 0x00ADCB98
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_MoveFailed::Evaluate(
        OC_MoveFailed *this,
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
    && ((errorTransCode = v6->errorTransCode) == 9
     || errorTransCode == 10
     || errorTransCode == 19
     || errorTransCode == 20) )
  {
    return 9;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?Evaluate@OC_MoveFailedAny@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADCC28
// RVA : 0x00ADCC28
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_MoveFailedAny::Evaluate(
        OC_MoveFailedAny *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idFiniteStateMachine *v7; // r31
  int errorTransCode; // r11
  idAIMoveState *MoveInterface; // r3

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  v7 = FullPath;
  if ( FullPath != nullptr && (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) != 0 )
  {
    errorTransCode = v7->errorTransCode;
    if ( errorTransCode >= 9 && errorTransCode <= 20 )
      return 9;
  }
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  return __CFADD__(MoveInterface->GetMoveStatus(this: MoveInterface) - 2, -2147483646) ? 0 : 9;
}


// ========================================================================
// ?Evaluate@OC_ShouldSidestep@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADCCD0
// RVA : 0x00ADCCD0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_ShouldSidestep::Evaluate(
        OC_ShouldSidestep *this,
        idAI2 *ai,
        idOpenCombatFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIStateTransition::aiTransCode_t result; // r3

  if ( ai->aiEditable.movement.turretMode )
    return 0;
  result = idAI2::ShouldDiveOrDodgeOrCrouch(this: ai, parentFSM);
  ai->aiVolatile.memory.transCode = result;
  return result;
}


// ========================================================================
// ?Evaluate@OC_EnemyCloserThanOptimalRange@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADCD38
// RVA : 0x00ADCD38
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_EnemyCloserThanOptimalRange::Evaluate(
        OC_EnemyCloserThanOptimalRange *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  aiSenseState_t *EnemySenseState; // r29
  idWeapon *v7; // r3
  idWeapon *v8; // r30
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  idPhysics *Physics; // r3
  float *v11; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  double v15; // fp10
  double v16; // fp1
  double v17; // fp10
  float x; // [sp+50h] [-30h]
  float y; // [sp+54h] [-2Ch]
  float z; // [sp+58h] [-28h]

  EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  v7 = ai->GetEquippedWeapon(this: ai);
  v8 = v7;
  if ( EnemySenseState == nullptr )
    return 0;
  if ( v7 == nullptr )
    return 0;
  if ( v7->decl == nullptr )
    return 0;
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
  x = ConfirmedPhysicalSafe->origin.x;
  y = ConfirmedPhysicalSafe->origin.y;
  z = ConfirmedPhysicalSafe->origin.z;
  Physics = idEntity::GetPhysics(this: ai);
  v11 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  _FP1 = (float)((float)((float)((float)(x - *v11) * (float)(x - *v11))
                       + (float)((float)((float)(z - v11[2]) * (float)(z - v11[2]))
                               + (float)((float)(y - v11[1]) * (float)(y - v11[1]))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f11, f1, f2, f13 }
  v15 = __frsqrte(_FP11);
  v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                      * (float)((float)((float)((float)(x - *v11) * (float)(x - *v11)) + (float)((float)((float)(z - v11[2]) * (float)(z - v11[2])) + (float)((float)(y - v11[1]) * (float)(y - v11[1]))))
                                                                                              * (float)0.5))
                                                                              * (float)v15)
                                                                      - (float)1.5)
                                                      * (float)v15)
                                              * (float)((float)((float)((float)(x - *v11) * (float)(x - *v11))
                                                              + (float)((float)((float)(z - v11[2]) * (float)(z - v11[2]))
                                                                      + (float)((float)(y - v11[1]) * (float)(y - v11[1]))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                              * (float)((float)((float)((float)(x - *v11) * (float)(x - *v11))
                                                                                              + (float)((float)((float)(z - v11[2]) * (float)(z - v11[2])) + (float)((float)(y - v11[1]) * (float)(y - v11[1]))))
                                                                                      * (float)0.5))
                                                                      * (float)v15)
                                                              - (float)1.5)
                                              * (float)v15))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v15
                                                      * (float)((float)((float)((float)(x - *v11) * (float)(x - *v11))
                                                                      + (float)((float)((float)(z - v11[2])
                                                                                      * (float)(z - v11[2]))
                                                                              + (float)((float)(y - v11[1])
                                                                                      * (float)(y - v11[1]))))
                                                              * (float)0.5))
                                              * (float)v15)
                                      - (float)1.5)
                      * (float)v15));
  v17 = (float)((float)((float)-(float)((float)((float)((float)v16
                                                      * (float)((float)((float)((float)(x - *v11) * (float)(x - *v11))
                                                                      + (float)((float)((float)(z - v11[2])
                                                                                      * (float)(z - v11[2]))
                                                                              + (float)((float)(y - v11[1])
                                                                                      * (float)(y - v11[1]))))
                                                              * (float)0.5))
                                              * (float)v16)
                                      - (float)1.5)
                      * (float)v16)
              * (float)((float)((float)(x - *v11) * (float)(x - *v11))
                      + (float)((float)((float)(z - v11[2]) * (float)(z - v11[2]))
                              + (float)((float)(y - v11[1]) * (float)(y - v11[1])))));
  result = TRANSCODE_OC_ENEMY_CLOSER_THAN_OPTIMAL_RANGE;
  if ( v17 >= *(float *)&v8->decl[1].inventoryClass.baseBuffer[4] )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_EnemyFartherThanOptimalRange@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADCE70
// RVA : 0x00ADCE70
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_EnemyFartherThanOptimalRange::Evaluate(
        OC_EnemyFartherThanOptimalRange *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  aiSenseState_t *EnemySenseState; // r29
  idWeapon *v7; // r3
  idWeapon *v8; // r30
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  idPhysics *Physics; // r3
  float *v11; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  double v15; // fp10
  double v16; // fp1
  double v17; // fp10
  float x; // [sp+50h] [-30h]
  float y; // [sp+54h] [-2Ch]
  float z; // [sp+58h] [-28h]

  EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  v7 = ai->GetEquippedWeapon(this: ai);
  v8 = v7;
  if ( EnemySenseState == nullptr )
    return 0;
  if ( v7 == nullptr )
    return 0;
  if ( v7->decl == nullptr )
    return 0;
  if ( ai->aiVolatile.memory.enemyPathBlocked )
    return 0;
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
  x = ConfirmedPhysicalSafe->origin.x;
  y = ConfirmedPhysicalSafe->origin.y;
  z = ConfirmedPhysicalSafe->origin.z;
  Physics = idEntity::GetPhysics(this: ai);
  v11 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  _FP1 = (float)((float)((float)((float)(x - *v11) * (float)(x - *v11))
                       + (float)((float)((float)(z - v11[2]) * (float)(z - v11[2]))
                               + (float)((float)(y - v11[1]) * (float)(y - v11[1]))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f11, f1, f2, f13 }
  v15 = __frsqrte(_FP11);
  v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                      * (float)((float)((float)((float)(x - *v11) * (float)(x - *v11)) + (float)((float)((float)(z - v11[2]) * (float)(z - v11[2])) + (float)((float)(y - v11[1]) * (float)(y - v11[1]))))
                                                                                              * (float)0.5))
                                                                              * (float)v15)
                                                                      - (float)1.5)
                                                      * (float)v15)
                                              * (float)((float)((float)((float)(x - *v11) * (float)(x - *v11))
                                                              + (float)((float)((float)(z - v11[2]) * (float)(z - v11[2]))
                                                                      + (float)((float)(y - v11[1]) * (float)(y - v11[1]))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                              * (float)((float)((float)((float)(x - *v11) * (float)(x - *v11))
                                                                                              + (float)((float)((float)(z - v11[2]) * (float)(z - v11[2])) + (float)((float)(y - v11[1]) * (float)(y - v11[1]))))
                                                                                      * (float)0.5))
                                                                      * (float)v15)
                                                              - (float)1.5)
                                              * (float)v15))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v15
                                                      * (float)((float)((float)((float)(x - *v11) * (float)(x - *v11))
                                                                      + (float)((float)((float)(z - v11[2])
                                                                                      * (float)(z - v11[2]))
                                                                              + (float)((float)(y - v11[1])
                                                                                      * (float)(y - v11[1]))))
                                                              * (float)0.5))
                                              * (float)v15)
                                      - (float)1.5)
                      * (float)v15));
  v17 = (float)((float)((float)-(float)((float)((float)((float)v16
                                                      * (float)((float)((float)((float)(x - *v11) * (float)(x - *v11))
                                                                      + (float)((float)((float)(z - v11[2])
                                                                                      * (float)(z - v11[2]))
                                                                              + (float)((float)(y - v11[1])
                                                                                      * (float)(y - v11[1]))))
                                                              * (float)0.5))
                                              * (float)v16)
                                      - (float)1.5)
                      * (float)v16)
              * (float)((float)((float)(x - *v11) * (float)(x - *v11))
                      + (float)((float)((float)(z - v11[2]) * (float)(z - v11[2]))
                              + (float)((float)(y - v11[1]) * (float)(y - v11[1])))));
  result = TRANSCODE_OC_ENEMY_FARTHER_THAN_OPTIMAL_RANGE;
  if ( v17 <= *(float *)v8->decl[1].inventoryClass.baseBuffer )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_Default@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADCFC0
// RVA : 0x00ADCFC0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_Default::AIState_EnterState(
        idOpenCombat_Default *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idAIFireControl **p_fireControl; // r29

  ai->aiVolatile.animation.subWeb = AISUBWEB_COMBAT;
  p_fireControl = &ai->aiVolatile.fireControl;
  idAI2::SetEnableHeadTracking(this: ai, enable: true);
  idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
  idAI2::ReleaseCover(this: ai);
  if ( *p_fireControl != nullptr )
    (*p_fireControl)->allowReloads = false;
  if ( curTime >= ai->aiVolatile.memory.endOpenCombatTime )
    ai->aiVolatile.memory.endOpenCombatTime = curTime
                                            - (int)(float)(ai->aiEditable.behaviors.decl->openCombatDuration
                                                         * (float)-1000.0);
}


// ========================================================================
// ?Evaluate@OC_ReachedEnemy@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADD068
// RVA : 0x00ADD068
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_ReachedEnemy::Evaluate(
        OC_ReachedEnemy *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  aiSenseState_t *EnemySenseState; // r31
  idPhysics *Physics; // r3
  float *v8; // r29
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  double v10; // fp10
  double v11; // fp6

  if ( !idAI2::IsMoveDone(this: ai, checkAlignment: false) )
    return 0;
  EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  if ( EnemySenseState == nullptr )
    return 264;
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
     - EnemySenseState->lastConfirmedStimTime < 1000 )
    return 264;
  Physics = idEntity::GetPhysics(this: ai);
  v8 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
  v10 = (float)(ConfirmedPhysicalSafe->origin.z - v8[2]);
  v11 = (float)(ConfirmedPhysicalSafe->origin.y - v8[1]);
  if ( (float)((float)((float)v11 * (float)v11)
             + (float)((float)((float)(ConfirmedPhysicalSafe->origin.x - *v8)
                             * (float)(ConfirmedPhysicalSafe->origin.x - *v8))
                     + (float)((float)v10 * (float)v10))) >= 4096.0 )
    return 264;
  ai->aiVolatile.groupStatus.condition |= 0x1000u;
  return 265;
}


// ========================================================================
// ?Evaluate@OC_ThrowProjectileFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADD170
// RVA : 0x00ADD170
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_ThrowProjectileFinished::Evaluate(
        OC_ThrowProjectileFinished *this,
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
    return TRANSCODE_OC_THROW_PROJECTILE_FINISHED;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_OC_THROW_PROJECTILE_FINISHED;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_ThrowProjectile@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADD1B8
// RVA : 0x00ADD1B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_ThrowProjectile::AIState_EnterState(
        idOpenCombat_ThrowProjectile *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idEventArg *v8; // r3
  const idDeclAIBehavior *decl; // r11
  int minOCThrowInterval; // r30
  int maxOCThrowInterval; // r4
  int RandomInterval; // r3
  unsigned int v13; // r8
  int GameMs; // r3
  idEventArg v15; // [sp+90h] [-70h] BYREF
  idEventReceiver v16[6]; // [sp+B0h] [-50h] BYREF

  idAIState::ClearQueuedActions(this, ai, parentFSM: fsm, curTime);
  idAI2::EndActionScript(this: ai);
  fsm->actionCallerState = this;
  v8 = idEventArg::idEventArg(this: &v15, data: ai);
  idEventReceiver::ProcessEvent(
    this: v16,
    result: (idEventArg *)fsm,
    ev: *(const idEventDef **)&v8->type,
    arg1: (const idEventArg *)LODWORD(v8->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v8->value.v[2]));
  decl = ai->aiEditable.behaviors.decl;
  if ( decl->minOCThrowInterval != 0 )
    minOCThrowInterval = decl->minOCThrowInterval;
  else
    minOCThrowInterval = decl->minThrowInterval;
  maxOCThrowInterval = decl->maxOCThrowInterval;
  if ( maxOCThrowInterval == 0 )
    maxOCThrowInterval = decl->maxThrowInterval;
  RandomInterval = GetRandomInterval(_min: minOCThrowInterval, _max: maxOCThrowInterval);
  if ( (ai->aiVolatile.groupStatus.condition & 0x8000) != 0 )
    RandomInterval = minOCThrowInterval;
  ai->aiVolatile.memory.nextThrowTime = RandomInterval + curTime;
  v13 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v13;
  if ( (signed int)(((v13 >> 10) & 0x7FFF) % 0x64) < ai->aiEditable.behaviors.decl->rageBehaviors.angryRageAfterMissingChance )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idAIMemory::SetWantAngryRageTime(this: &ai->aiVolatile.memory, t: GameMs + 1000, debugReason: "miss enemy");
  }
}


// ========================================================================
// ?AIState_ExitState@idAdvance_ThrowProjectile@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADD350
// RVA : 0x00ADD350
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idAdvance_ThrowProjectile::AIState_ExitState@<r4>(
        idAI2 *this@<r3>,
        int result@<r4>,
        const idMD6Anim *anim@<r5>)
{
  *(_BYTE *)(result + 11056) |= 0x80u;
  return result;
}


// ========================================================================
// ?Evaluate@OC_ShouldRage@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADD360
// RVA : 0x00ADD360
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_ShouldRage::Evaluate(
        OC_ShouldRage *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  aiSenseState_t *EnemySenseState; // r3
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  idPhysics *Physics; // r3
  float *v9; // r3
  idPresentable *presentable; // r11
  double v13; // fp12
  double v14; // fp2
  double v15; // fp31
  double v16; // fp30
  double v17; // fp29
  float x; // [sp+50h] [-40h]
  float y; // [sp+54h] [-3Ch]
  float z; // [sp+58h] [-38h]

  if ( (unsigned __int8)idAI2::HasAngryRage(this: ai) == 0 && (unsigned __int8)idAI2::HasTauntRage(this: ai) == 0 )
    return 0;
  EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  if ( EnemySenseState == nullptr )
    return 0;
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
  x = ConfirmedPhysicalSafe->origin.x;
  y = ConfirmedPhysicalSafe->origin.y;
  z = ConfirmedPhysicalSafe->origin.z;
  Physics = idEntity::GetPhysics(this: ai);
  v9 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  presentable = ai->presentable;
  _FP2 = (float)((float)((float)((float)(x - *v9) * (float)(x - *v9))
                       + (float)((float)((float)(z - v9[2]) * (float)(z - v9[2]))
                               + (float)((float)(y - v9[1]) * (float)(y - v9[1]))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f2, f3, f13 }
  v13 = __frsqrte(_FP13);
  v14 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13
                                                                                      * (float)((float)((float)((float)(x - *v9) * (float)(x - *v9)) + (float)((float)((float)(z - v9[2]) * (float)(z - v9[2])) + (float)((float)(y - v9[1]) * (float)(y - v9[1]))))
                                                                                              * (float)0.5))
                                                                              * (float)v13)
                                                                      - (float)1.5)
                                                      * (float)v13)
                                              * (float)((float)((float)((float)(x - *v9) * (float)(x - *v9))
                                                              + (float)((float)((float)(z - v9[2]) * (float)(z - v9[2]))
                                                                      + (float)((float)(y - v9[1]) * (float)(y - v9[1]))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v13
                                                                              * (float)((float)((float)((float)(x - *v9) * (float)(x - *v9))
                                                                                              + (float)((float)((float)(z - v9[2]) * (float)(z - v9[2])) + (float)((float)(y - v9[1]) * (float)(y - v9[1]))))
                                                                                      * (float)0.5))
                                                                      * (float)v13)
                                                              - (float)1.5)
                                              * (float)v13))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v13
                                                      * (float)((float)((float)((float)(x - *v9) * (float)(x - *v9))
                                                                      + (float)((float)((float)(z - v9[2])
                                                                                      * (float)(z - v9[2]))
                                                                              + (float)((float)(y - v9[1])
                                                                                      * (float)(y - v9[1]))))
                                                              * (float)0.5))
                                              * (float)v13)
                                      - (float)1.5)
                      * (float)v13));
  v15 = (float)((float)(x - *v9)
              * (float)((float)-(float)((float)((float)((float)v14
                                                      * (float)((float)((float)((float)(x - *v9) * (float)(x - *v9))
                                                                      + (float)((float)((float)(z - v9[2])
                                                                                      * (float)(z - v9[2]))
                                                                              + (float)((float)(y - v9[1])
                                                                                      * (float)(y - v9[1]))))
                                                              * (float)0.5))
                                              * (float)v14)
                                      - (float)1.5)
                      * (float)v14));
  v16 = (float)((float)(y - v9[1])
              * (float)((float)-(float)((float)((float)((float)v14
                                                      * (float)((float)((float)((float)(x - *v9) * (float)(x - *v9))
                                                                      + (float)((float)((float)(z - v9[2])
                                                                                      * (float)(z - v9[2]))
                                                                              + (float)((float)(y - v9[1])
                                                                                      * (float)(y - v9[1]))))
                                                              * (float)0.5))
                                              * (float)v14)
                                      - (float)1.5)
                      * (float)v14));
  v17 = (float)((float)(z - v9[2])
              * (float)((float)-(float)((float)((float)((float)v14
                                                      * (float)((float)((float)((float)(x - *v9) * (float)(x - *v9))
                                                                      + (float)((float)((float)(z - v9[2])
                                                                                      * (float)(z - v9[2]))
                                                                              + (float)((float)(y - v9[1])
                                                                                      * (float)(y - v9[1]))))
                                                              * (float)0.5))
                                              * (float)v14)
                                      - (float)1.5)
                      * (float)v14));
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: ai);
    presentable = ai->presentable;
  }
  if ( (float)((float)(presentable->axis.mat[0].x * (float)v15)
             + (float)((float)(presentable->axis.mat[0].z * (float)v17)
                     + (float)(presentable->axis.mat[0].y * (float)v16))) < 0.70700002 )
    return 0;
  if ( (unsigned __int8)idAI2::WantsToTauntRage(this: ai) != 0
    && (unsigned __int8)idAI2::EnemyTooCloseToGoProne(this: ai, facingMatters: true, obscurityMatters: false) == 0 )
  {
    ai->aiVolatile.memory.transCode = TRANSCODE_OC_SHOULD_TAUNT_RAGE;
    return 311;
  }
  if ( (unsigned __int8)idAI2::WantsToAngryRage(this: ai) == 0
    || (unsigned __int8)idAI2::EnemyTooCloseToGoProne(this: ai, facingMatters: true, obscurityMatters: false) != 0 )
  {
    return 0;
  }
  ai->aiVolatile.memory.transCode = TRANSCODE_OC_SHOULD_ANGRY_RAGE;
  return 310;
}


// ========================================================================
// ?Evaluate@OC_ReloadCrouched@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADD578
// RVA : 0x00ADD578
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_ReloadCrouched::Evaluate(
        OC_ReloadCrouched *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idWeapon *v7; // r30
  double v8; // fp1
  idAIStateTransition::aiTransCode_t result; // r3

  if ( (*((_BYTE *)ai->aiEditable.behaviors.decl + 428) & 1) == 0 )
    return 0;
  v7 = ai->GetEquippedWeapon(this: ai);
  if ( (unsigned __int8)idAI2::EnemyTooCloseToGoProne(this: ai, facingMatters: true, obscurityMatters: true) != 0
    && ai->aiVolatile.memory.lastMoveFailedTime < curTime - 1000 )
  {
    return 0;
  }
  if ( v7 == nullptr )
    return 0;
  v8 = ((double (__fastcall *)(idWeapon *, _DWORD))v7->AmmoInClipPercentage)(a1: v7, a2: 0);
  result = TRANSCODE_OC_RELOAD_CROUCHED;
  if ( v8 >= 0.1 )
    return 0;
  return result;
}


// ========================================================================
// ?ChargeFail@@YA?AW4aiTransCode_t@idAIStateTransition@@PBVidAI2@@PBD@Z
// EA  : 0x82ADD630
// RVA : 0x00ADD630
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall ChargeFail(const idAI2 *ai, const char *reason)
{
  idPhysics *Physics; // r3
  idRenderWorld_vtbl *v4; // r31
  int v5; // r3

  if ( ai_debugLevel.valueInteger != 0 && ai_debugCharge.valueInteger != 0 )
  {
    Physics = idEntity::GetPhysics(this: &ai->idActor);
    v4 = clientGame->renderWorld->__vftable;
    v5 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, const char *, int, enum idAIStateTransition::aiTransCode_t (__fastcall **)(COMBAT_AtPlugAnim *__hidden, struct idAI2 *, struct idAIFSM *, struct idAIState *, int), idColor *, int, int, double))v4->DebugText)(
      a1: clientGame->renderWorld,
      a2: reason,
      a3: v5,
      a4: &off_82040000,
      a5: &idColor::colorOrange,
      a6: 1,
      a7: 100,
      a8: 0.2);
  }
  return 0;
}


// ========================================================================
// ?Evaluate@OC_AttackMove@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADD6D8
// RVA : 0x00ADD6D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_AttackMove::Evaluate(
        OC_AttackMove *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  if ( ai->aiEditable.movement.turretMode )
    return 0;
  else
    return ai->aiVolatile.memory.transCode;
}


// ========================================================================
// ?Evaluate@OC_ChargeTimedOut@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADD700
// RVA : 0x00ADD700
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_ChargeTimedOut::Evaluate(
        OC_ChargeTimedOut *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return ((__PAIR64__(
             (unsigned int)(curTime - ai->aiVolatile.memory.lastChargeTime) >> 31,
             ai->aiEditable.behaviors.decl->maxChargeDuration)
         - __PAIR64__(
             (unsigned int)ai->aiEditable.behaviors.decl->maxChargeDuration >> 31,
             curTime - ai->aiVolatile.memory.lastChargeTime)) >> 32)
       & 0x117;
}


// ========================================================================
// ?AIState_ExitState@idOpenCombat_ChargeMelee@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADD738
// RVA : 0x00ADD738
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_ChargeMelee::AIState_ExitState(
        idOpenCombat_ChargeMelee *this,
        _exception *ai,
        idAIFSM *fsm,
        const int curTime)
{
  const idDeclAIBehavior *v4; // r8
  int maxChargeInterval; // r9
  int minChargeInterval; // r11
  signed int v8; // r3
  unsigned int v9; // r7
  signed int v10; // r4

  v4 = *((const idDeclAIBehavior **)&ai[178].name + 1);
  maxChargeInterval = v4->maxChargeInterval;
  minChargeInterval = v4->minChargeInterval;
  if ( minChargeInterval < maxChargeInterval )
  {
    v8 = maxChargeInterval - minChargeInterval + 1;
    v9 = 1664525 * clientGame->random.seed + 1013907456;
    __twllei(v8, 0);
    clientGame->random.seed = v9 - 3233;
    v10 = ((v9 - 3233) >> 10) & 0x7FFF;
    __twlgei(v8 & ~(__ROL4__(v10, 1) - 1), 0xFFFFFFFF);
    minChargeInterval += v10 % v8;
  }
  LODWORD(ai[913].retval) = v4->minChargeInterval + minChargeInterval + curTime;
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 )
    LODWORD(ai[596].retval) &= ~0x1000u;
}


// ========================================================================
// ?Evaluate@OC_LeapAttackFailed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADD810
// RVA : 0x00ADD810
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_LeapAttackFailed::Evaluate(
        ADVANCE_LeapAttackFailed *this,
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
    return TRANSCODE_ADVANCE_LEAP_ATTACK_FAILED;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_ADVANCE_LEAP_ATTACK_FAILED;
  return result;
}


// ========================================================================
// ?Evaluate@OC_LeapAttackDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADD858
// RVA : 0x00ADD858
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_LeapAttackDone::Evaluate(
        ADVANCE_LeapAttackDone *this,
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
    return TRANSCODE_ADVANCE_LEAP_ATTACK_DONE;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_ADVANCE_LEAP_ATTACK_DONE;
  return result;
}


// ========================================================================
// ?AIState_ExitState@idAdvance_LeapAttack@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADD8A0
// RVA : 0x00ADD8A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idAdvance_LeapAttack::AIState_ExitState(
        idAdvance_LeapAttack *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idContents *p_clipMask; // r31
  int v5; // r3

  p_clipMask = &ai->aiConstants.physics.clipMask;
  v5 = idContents::ToFlags(this: &ai->aiConstants.physics.clipMask);
  idContents::FromFlags(this: p_clipMask, flags: v5 & 0xFFFFFBFF);
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_MoveToCoverAndReload@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADD8E0
// RVA : 0x00ADD8E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_MoveToCoverAndReload::AIState_EnterState(
        idOpenCombat_MoveToCoverAndReload *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idPhysics *Physics; // r26
  const aas2Cover_t *Origin; // r25
  float *v10; // r3
  double v11; // fp10
  double v12; // fp8
  walkState_t v13; // r4
  double v14; // fp3
  double v16; // fp1
  double v18; // fp12
  double v19; // fp10
  walkState_t DesiredWalkStateForDistance; // r3

  Physics = idEntity::GetPhysics(this: ai);
  Origin = idAICover::GetOrigin(this: &ai->aiVolatile.memory.cachedCover);
  v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v11 = (float)(v10[1] - Origin->origin.y);
  v12 = (float)(v10[2] - Origin->origin.z);
  v13 = (curTime - ai->aiVolatile.memory.lastFiredAtTime >= 0)
      + ((unsigned int)(curTime - ai->aiVolatile.memory.lastFiredAtTime) >= 0x7D0);
  v14 = (float)((float)((float)(*v10 - Origin->origin.x) * (float)(*v10 - Origin->origin.x))
              + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)));
  _FP2 = (float)((float)((float)((float)(*v10 - Origin->origin.x) * (float)(*v10 - Origin->origin.x))
                       + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v16 = (float)((float)((float)((float)(*v10 - Origin->origin.x) * (float)(*v10 - Origin->origin.x))
                      + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
              * (float)0.5);
  __asm { fsel      f13, f2, f3, f13 }
  v18 = __frsqrte(_FP13);
  v19 = (float)((float)v18
              * (float)((float)((float)((float)(*v10 - Origin->origin.x) * (float)(*v10 - Origin->origin.x))
                              + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                      * (float)0.5));
  DesiredWalkStateForDistance = idAI2::GetDesiredWalkStateForDistance(
                                  this: ai,
                                  distance: (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18) * (float)v16) * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18)) - (float)1.5)
                                                                                        * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5)
                                                                                                * (float)v18))
                                                                                * (float)v16)
                                                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18) * (float)v16) * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18))
                                                                                                - (float)1.5)
                                                                                * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5)
                                                                                        * (float)v18)))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5)
                                                                                                * (float)v18)
                                                                                        * (float)v16)
                                                                                * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5)
                                                                                        * (float)v18))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)v19 * (float)v18)
                                                                                - (float)1.5)
                                                                * (float)v18)))
                                        * (float)v14),
                                  maxWalkState: v13,
                                  firedAt: WALKSTATE_RUNNING,
                                  a5: v13 & 1);
  ai->SetWalkState(this: ai, a2: DesiredWalkStateForDistance);
  if ( (unsigned __int8)idAI2::StartMoveToCover(
                          this: ai,
                          cover: &ai->aiVolatile.memory.cachedCover,
                          fsm,
                          state: this,
                          allowWalk: true,
                          curTime) == 0 )
    idState::SetEnterFailed(this, failed: true);
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_MoveOutOfSightAndReload@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADDA40
// RVA : 0x00ADDA40
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_MoveOutOfSightAndReload::AIState_EnterState(
        idOpenCombat_MoveOutOfSightAndReload *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idPhysics *Physics; // r3
  idVec3 *p_cachedDestination; // r27
  float *v10; // r3
  double v11; // fp10
  double v12; // fp8
  walkState_t v13; // r4
  double v14; // fp3
  double v16; // fp1
  double v18; // fp12
  double v19; // fp10
  walkState_t DesiredWalkStateForDistance; // r3
  double y; // fp12
  double z; // fp10
  idEventArg *v23; // r30
  const idEventArg *v24; // [sp+8h] [-258h]
  const idEventArg *v25; // [sp+Ch] [-254h]
  _BYTE v26[20]; // [sp+70h] [-1F0h] BYREF
  _BYTE v27[20]; // [sp+90h] [-1D0h] BYREF
  _BYTE v28[20]; // [sp+B0h] [-1B0h] BYREF
  _BYTE v29[20]; // [sp+D0h] [-190h] BYREF
  _BYTE v30[20]; // [sp+F0h] [-170h] BYREF
  float v31[5]; // [sp+110h] [-150h] BYREF
  float v32[5]; // [sp+130h] [-130h] BYREF
  _DWORD v33[5]; // [sp+150h] [-110h] BYREF
  int v34; // [sp+170h] [-F0h]
  int v35; // [sp+174h] [-ECh]
  const idEventArg *v36; // [sp+178h] [-E8h]
  const idEventArg *v37; // [sp+17Ch] [-E4h]
  _DWORD v38[5]; // [sp+190h] [-D0h] BYREF
  float v39[5]; // [sp+1B0h] [-B0h] BYREF
  idEventArg v40; // [sp+1D0h] [-90h] BYREF
  idEventReceiver v41[9]; // [sp+1F0h] [-70h] BYREF

  p_cachedDestination = &ai->aiVolatile.memory.cachedDestination;
  Physics = idEntity::GetPhysics(this: ai);
  v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v11 = (float)(v10[2] - ai->aiVolatile.memory.cachedDestination.z);
  v12 = (float)(v10[1] - ai->aiVolatile.memory.cachedDestination.y);
  v13 = (curTime - ai->aiVolatile.memory.lastFiredAtTime >= 0)
      + ((unsigned int)(curTime - ai->aiVolatile.memory.lastFiredAtTime) >= 0x7D0);
  v14 = (float)((float)((float)(*v10 - p_cachedDestination->x) * (float)(*v10 - p_cachedDestination->x))
              + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)));
  _FP2 = (float)((float)((float)((float)(*v10 - p_cachedDestination->x) * (float)(*v10 - p_cachedDestination->x))
                       + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v16 = (float)((float)((float)((float)(*v10 - p_cachedDestination->x) * (float)(*v10 - p_cachedDestination->x))
                      + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
              * (float)0.5);
  __asm { fsel      f13, f2, f3, f13 }
  v18 = __frsqrte(_FP13);
  v19 = (float)((float)v18
              * (float)((float)((float)((float)(*v10 - p_cachedDestination->x) * (float)(*v10 - p_cachedDestination->x))
                              + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                      * (float)0.5));
  DesiredWalkStateForDistance = idAI2::GetDesiredWalkStateForDistance(
                                  this: ai,
                                  distance: (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18) * (float)v16) * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18)) - (float)1.5)
                                                                                        * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5)
                                                                                                * (float)v18))
                                                                                * (float)v16)
                                                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18) * (float)v16) * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18))
                                                                                                - (float)1.5)
                                                                                * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5)
                                                                                        * (float)v18)))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5)
                                                                                                * (float)v18)
                                                                                        * (float)v16)
                                                                                * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5)
                                                                                        * (float)v18))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)v19 * (float)v18)
                                                                                - (float)1.5)
                                                                * (float)v18)))
                                        * (float)v14),
                                  maxWalkState: v13,
                                  firedAt: WALKSTATE_RUNNING,
                                  a5: v13 & 1);
  ai->SetWalkState(this: ai, a2: DesiredWalkStateForDistance);
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  HIBYTE(v31[0]) = 118;
  HIBYTE(v38[0]) = 105;
  v38[1] = 0;
  y = ai->aiVolatile.memory.cachedDestination.y;
  v32[1] = p_cachedDestination->x;
  v32[2] = y;
  z = ai->aiVolatile.memory.cachedDestination.z;
  HIBYTE(v39[0]) = 102;
  HIBYTE(v33[0]) = 105;
  v31[1] = vec3_origin.x;
  v33[1] = 2;
  v31[2] = vec3_origin.y;
  HIBYTE(v32[0]) = 118;
  v31[3] = vec3_origin.z;
  HIBYTE(v34) = 105;
  v39[1] = 0.1;
  v35 = 7;
  v32[3] = z;
  v23 = idEventArg::idEventArg(this: &v40, data: ai);
  memcpy(Dst: v30, Src: v31, Size: sizeof(v30));
  memcpy(Dst: v29, Src: v38, Size: sizeof(v29));
  memcpy(Dst: v28, Src: v39, Size: sizeof(v28));
  memcpy(Dst: v27, Src: v33, Size: sizeof(v27));
  memcpy(Dst: v26, Src: v32, Size: sizeof(v26));
  idEventReceiver::ProcessEvent(
    this: v41,
    result: fsm,
    ev: *(const idEventDef **)&v23->type,
    arg1: (const idEventArg *)LODWORD(v23->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v23->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v34, 32),
    arg4: v36,
    arg5: v37,
    arg6: v24,
    arg7: v25);
}


// ========================================================================
// ?Evaluate@OC_ReloadFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADDC90
// RVA : 0x00ADDC90
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_ReloadFinished::Evaluate(
        OC_ReloadFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idWeapon *v5; // r3
  idWeapon::fireState_t fireState; // r11
  idAIStateTransition::aiTransCode_t result; // r3

  v5 = ai->GetEquippedWeapon(this: ai);
  if ( v5 == nullptr )
    return 0;
  fireState = v5->fireState;
  result = TRANSCODE_OC_RELOAD_FINISHED;
  if ( fireState == FIRESTATE_RELOADING )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_ReloadFinishedCrouch@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADDCE0
// RVA : 0x00ADDCE0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_ReloadFinishedCrouch::Evaluate(
        OC_ReloadFinishedCrouch *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idWeapon *v7; // r3

  if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED
    && (idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
      - ai->aiVolatile.memory.lastFiredAtTime < 2000
     || idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
      - ai->aiVolatile.memory.lastAimedAtTime < 2000
     || (v7 = ai->GetEquippedWeapon(this: ai)) != nullptr && v7->fireState != FIRESTATE_RELOADING) )
  {
    return 294;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?Evaluate@OC_IsStanding@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADDDA8
// RVA : 0x00ADDDA8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_IsStanding::Evaluate(
        OC_IsStanding *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v8; // zf

  if ( ai->GetPosture(this: ai) == POSTURE_STANDING )
    return TRANSCODE_OC_STAND_FINISHED;
  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( FullPath == nullptr )
    return TRANSCODE_OC_STAND_FINISHED;
  v8 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v8 )
    return TRANSCODE_OC_STAND_FINISHED;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_Stand@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADDE20
// RVA : 0x00ADDE20
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_Stand::AIState_EnterState(
        idOpenCombat_Stand *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idEventArg *v7; // r3
  idEventArg v8; // [sp+50h] [-60h] BYREF
  idEventReceiver v9[5]; // [sp+70h] [-40h] BYREF

  if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED )
  {
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    v7 = idEventArg::idEventArg(this: &v8, data: ai);
    idEventReceiver::ProcessEvent(
      this: v9,
      result: fsm,
      ev: *(const idEventDef **)&v7->type,
      arg1: (const idEventArg *)LODWORD(v7->value.v[1]));
  }
}


// ========================================================================
// ?Evaluate@OC_StopCrouching@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADDEA0
// RVA : 0x00ADDEA0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_StopCrouching::Evaluate(
        OC_StopCrouching *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  char v8; // r10

  if ( (unsigned __int8)idAI2::EnemyTooCloseToGoProne(this: ai, facingMatters: true, obscurityMatters: true) != 0 )
    return 296;
  if ( (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 0x40) != 0
    || idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
     - ai->aiVolatile.memory.lastFiredAtTime < 2000
    || idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
     - ai->aiVolatile.memory.lastAimedAtTime < 2000 )
  {
    return 0;
  }
  if ( curTime >= ai->aiVolatile.memory.nextMoveTime )
    return 296;
  if ( (ai->aiVolatile.groupStatus.condition & 0x200) != 0
    || (v8 = 1, !ai->aiVolatile.groupStatus.roleChangeResponseRequired) )
  {
    v8 = 0;
  }
  if ( v8 != 0 )
    return 296;
  return ai->aiVolatile.groupStatus.currentRole != ROLE_CHARGE ? 0 : 0x128;
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_Recharging@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADDFC8
// RVA : 0x00ADDFC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_Recharging::AIState_EnterState(
        idOpenCombat_Recharging *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idEventArg *v8; // r3
  idEventArg *v9; // r24
  _BYTE v10[20]; // [sp+70h] [-E0h] BYREF
  idEventReceiver v11[2]; // [sp+90h] [-C0h] BYREF
  idEventArg v12; // [sp+B0h] [-A0h] BYREF
  idEventArg v13; // [sp+D0h] [-80h] BYREF
  idEventReceiver v14[8]; // [sp+F0h] [-60h] BYREF

  v8 = idEventArg::idEventArg(this: &v12, data: ai);
  idEventReceiver::ProcessEvent(
    this: v11,
    result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
    ev: *(const idEventDef **)&v8->type,
    arg1: (const idEventArg *)LODWORD(v8->value.v[1]));
  HIBYTE(v11[0].__vftable) = 105;
  v11[0].listenerList = (idList<idEventReceiver *,5> *)1;
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
}


// ========================================================================
// ?Evaluate@OC_SidestepDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE0B0
// RVA : 0x00ADE0B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_SidestepDone::Evaluate(
        OC_SidestepDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x135;
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_ChargeSidestep@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADE0F0
// RVA : 0x00ADE0F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_ChargeSidestep::AIState_EnterState(
        idOpenCombat_ChargeSidestep *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  ai->aiVolatile.memory.animAfterOverride = AIMEMORY_ANIMAFTER_OVERRIDE_RUN;
  idAI2::SetupDiveDodgeOrFlinchAction(this: ai, moveReason: 8, state: this, fsm);
}


// ========================================================================
// ?Evaluate@OC_RageDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE118
// RVA : 0x00ADE118
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_RageDone::Evaluate(
        OC_RageDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x138;
}


// ========================================================================
// ?Evaluate@OC_EndOpenCombat@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE158
// RVA : 0x00ADE158
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_EndOpenCombat::Evaluate(
        OC_EndOpenCombat *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  ai->aiVolatile.memory.endOpenCombatTime = idGameTimeManager::GetGameMs(
                                              this: &clientGame->gameTimeManager,
                                              type: GAMETIME_SCALED);
  return 1;
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_MoveFailed@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADE1A8
// RVA : 0x00ADE1A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_MoveFailed::AIState_EnterState(
        idOpenCombat_MoveFailed *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  ai->aiVolatile.memory.lastMoveFailedTime = curTime;
}


// ========================================================================
// ?Evaluate@OC_IsInRechargeZone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE1B8
// RVA : 0x00ADE1B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_IsInRechargeZone::Evaluate(
        OC_IsInRechargeZone *this,
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
    return TRANSCODE_IS_IN_RECHARGE_ZONE;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_IS_IN_RECHARGE_ZONE;
  return result;
}


// ========================================================================
// ?Evaluate@OC_RechargeDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE200
// RVA : 0x00ADE200
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_RechargeDone::Evaluate(
        OC_RechargeDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIStateTransition::aiTransCode_t result; // r3

  result = TRANSCODE_OC_RECHARGE_DONE;
  if ( ai->aiHealth.components[1].cur != ai->aiHealth.components[1].max )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_MoveToRoleHintNodeDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE230
// RVA : 0x00ADE230
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_MoveToRoleHintNodeDone::Evaluate(
        OC_MoveToRoleHintNodeDone *this,
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
    return TRANSCODE_OC_MOVE_TO_ROLE_HINT_NODE_DONE;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_OC_MOVE_TO_ROLE_HINT_NODE_DONE;
  return result;
}


// ========================================================================
// ?Evaluate@OC_MoveToRoleHintNodeFailedError@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE278
// RVA : 0x00ADE278
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_MoveToRoleHintNodeFailedError::Evaluate(
        OC_MoveToRoleHintNodeFailedError *this,
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
  result = TRANSCODE_MOVE_FAILED;
  if ( v6->errorTransCode != 11 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_MoveToRoleHintNodeFailedInvalidEntity@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE2D8
// RVA : 0x00ADE2D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_MoveToRoleHintNodeFailedInvalidEntity::Evaluate(
        OC_MoveToRoleHintNodeFailedInvalidEntity *this,
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
  result = TRANSCODE_MOVE_FAILED;
  if ( v6->errorTransCode != 13 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_MoveToRoleHintNodeFailedUnreachable@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE338
// RVA : 0x00ADE338
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_MoveToRoleHintNodeFailedUnreachable::Evaluate(
        OC_MoveToRoleHintNodeFailedUnreachable *this,
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
  result = TRANSCODE_MOVE_FAILED;
  if ( v6->errorTransCode != 14 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_MoveToRoleHintNodeFailedPathingFailed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE398
// RVA : 0x00ADE398
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_MoveToRoleHintNodeFailedPathingFailed::Evaluate(
        OC_MoveToRoleHintNodeFailedPathingFailed *this,
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
  result = TRANSCODE_MOVE_FAILED;
  if ( v6->errorTransCode != 16 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_MoveToRoleHintNodeFailedNoPathGroup@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE3F8
// RVA : 0x00ADE3F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_MoveToRoleHintNodeFailedNoPathGroup::Evaluate(
        OC_MoveToRoleHintNodeFailedNoPathGroup *this,
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
  result = TRANSCODE_MOVE_FAILED;
  if ( v6->errorTransCode != 17 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_MoveToRoleHintNodeFailedNoPathPoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE458
// RVA : 0x00ADE458
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_MoveToRoleHintNodeFailedNoPathPoint::Evaluate(
        OC_MoveToRoleHintNodeFailedNoPathPoint *this,
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
  result = TRANSCODE_MOVE_FAILED;
  if ( v6->errorTransCode != 18 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_MoveToRoleHintNodeFailedTimedOut@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE4B8
// RVA : 0x00ADE4B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_MoveToRoleHintNodeFailedTimedOut::Evaluate(
        OC_MoveToRoleHintNodeFailedTimedOut *this,
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
  result = TRANSCODE_MOVE_FAILED;
  if ( v6->errorTransCode != 19 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_MoveToRoleHintNodeFailedStuck@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE518
// RVA : 0x00ADE518
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_MoveToRoleHintNodeFailedStuck::Evaluate(
        OC_MoveToRoleHintNodeFailedStuck *this,
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
  result = TRANSCODE_MOVE_FAILED;
  if ( v6->errorTransCode != 20 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_MoveToRoleHintNodeFailedObstructed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE578
// RVA : 0x00ADE578
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_MoveToRoleHintNodeFailedObstructed::Evaluate(
        OC_MoveToRoleHintNodeFailedObstructed *this,
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
  result = TRANSCODE_MOVE_FAILED;
  if ( v6->errorTransCode != 10 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_MoveToRoleHintNodeFailedNoAAS@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE5D8
// RVA : 0x00ADE5D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_MoveToRoleHintNodeFailedNoAAS::Evaluate(
        OC_MoveToRoleHintNodeFailedNoAAS *this,
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
  result = TRANSCODE_MOVE_FAILED;
  if ( v6->errorTransCode != 12 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_MoveToRoleHintNodeFailedNotInAAS@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE638
// RVA : 0x00ADE638
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_MoveToRoleHintNodeFailedNotInAAS::Evaluate(
        OC_MoveToRoleHintNodeFailedNotInAAS *this,
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
  result = TRANSCODE_MOVE_FAILED;
  if ( v6->errorTransCode != 15 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_PlayOverrideAnimDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADE698
// RVA : 0x00ADE698
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_PlayOverrideAnimDone::Evaluate(
        OC_PlayOverrideAnimDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idFiniteStateMachine *AlertCycleFSM; // r31
  int GameMs; // r3

  if ( !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) )
    return 0;
  if ( ai->aiEditable.actionSettings.customRobot.usesRobot )
  {
    AlertCycleFSM = idAI2::GetAlertCycleFSM(this: ai);
    if ( AlertCycleFSM != nullptr )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idFiniteStateMachine::Restart(this: AlertCycleFSM, curTime: GameMs);
      return 0;
    }
  }
  return 320;
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_PlayOverrideAnim@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADE740
// RVA : 0x00ADE740
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_PlayOverrideAnim::AIState_EnterState(
        idOpenCombat_PlayOverrideAnim *this,
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
      || (idLib::Warning(fmt: "FSM_OpenCombat::PlayOverrideAnim for %s missing animation specification", ai->name.data),
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
// __unwind$493486
// EA  : 0x82ADE8A8
// RVA : 0x00ADE8A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493486()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 272));
}


// ========================================================================
// ??0idOpenCombatFSM@@QAA@XZ
// EA  : 0x82ADE8D8
// RVA : 0x00ADE8D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idOpenCombatFSM *__fastcall idOpenCombatFSM::idOpenCombatFSM(idOpenCombatFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: "FSM_openCombat");
  this->__vftable = (idOpenCombatFSM_vtbl *)&idOpenCombatFSM::`vftable';
  idState::idState(this: &this->stateDefault, stateType: &idOpenCombat_Default::Type, childFSMType: nullptr, flags: 0);
  this->stateDefault.__vftable = (idOpenCombat_Default_vtbl *)&idOpenCombat_Default::`vftable';
  idState::idState(
    this: &this->stateMoveTowardEnemy,
    stateType: &idOpenCombat_MoveTowardEnemy::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveTowardEnemy.__vftable = (idOpenCombat_MoveTowardEnemy_vtbl *)&idOpenCombat_MoveTowardEnemy::`vftable';
  idState::idState(
    this: &this->stateMoveToSightEnemy,
    stateType: &idOpenCombat_MoveToSightEnemy::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveToSightEnemy.__vftable = (idOpenCombat_MoveToSightEnemy_vtbl *)&idOpenCombat_MoveToSightEnemy::`vftable';
  idState::idState(
    this: &this->stateAttackIdle,
    stateType: &idOpenCombat_AttackIdle::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateAttackIdle.__vftable = (idOpenCombat_AttackIdle_vtbl *)&idOpenCombat_AttackIdle::`vftable';
  idState::idState(
    this: &this->stateStartThrowProjectile,
    stateType: &idOpenCombat_StartThrowProjectile::Type,
    childFSMType: nullptr,
    flags: 4);
  this->stateStartThrowProjectile.__vftable = (idOpenCombat_StartThrowProjectile_vtbl *)&idOpenCombat_StartThrowProjectile::`vftable';
  idState::idState(
    this: &this->stateThrowProjectile,
    stateType: &idOpenCombat_ThrowProjectile::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateThrowProjectile.__vftable = (idOpenCombat_ThrowProjectile_vtbl *)&idOpenCombat_ThrowProjectile::`vftable';
  idState::idState(this: &this->stateShoot, stateType: &idOpenCombat_Shoot::Type, childFSMType: nullptr, flags: 0);
  this->stateShoot.__vftable = (idOpenCombat_Shoot_vtbl *)&idOpenCombat_Shoot::`vftable';
  idState::idState(
    this: &this->stateAttackMove,
    stateType: &idOpenCombat_AttackMove::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateAttackMove.__vftable = (idOpenCombat_AttackMove_vtbl *)&idOpenCombat_AttackMove::`vftable';
  idState::idState(
    this: &this->stateReachedEnemyPos,
    stateType: &idOpenCombat_ReachedEnemyPos::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateReachedEnemyPos.__vftable = (idOpenCombat_ReachedEnemyPos_vtbl *)&idOpenCombat_ReachedEnemyPos::`vftable';
  idState::idState(
    this: &this->stateAttackMelee,
    stateType: &idOpenCombat_AttackMelee::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateAttackMelee.__vftable = (idOpenCombat_AttackMelee_vtbl *)&idOpenCombat_AttackMelee::`vftable';
  idState::idState(
    this: &this->stateChargeMelee,
    stateType: &idOpenCombat_ChargeMelee::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateChargeMelee.__vftable = (idOpenCombat_ChargeMelee_vtbl *)&idOpenCombat_ChargeMelee::`vftable';
  idState::idState(
    this: &this->stateLeapAttack,
    stateType: &idOpenCombat_LeapAttack::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateLeapAttack.__vftable = (idOpenCombat_LeapAttack_vtbl *)&idOpenCombat_LeapAttack::`vftable';
  idState::idState(
    this: &this->stateMoveToCoverAndReload,
    stateType: &idOpenCombat_MoveToCoverAndReload::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveToCoverAndReload.__vftable = (idOpenCombat_MoveToCoverAndReload_vtbl *)&idOpenCombat_MoveToCoverAndReload::`vftable';
  idState::idState(
    this: &this->stateMoveOutOfSightAndReload,
    stateType: &idOpenCombat_MoveOutOfSightAndReload::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveOutOfSightAndReload.__vftable = (idOpenCombat_MoveOutOfSightAndReload_vtbl *)&idOpenCombat_MoveOutOfSightAndReload::`vftable';
  idState::idState(
    this: &this->stateReloadWeapon,
    stateType: &idOpenCombat_ReloadWeapon::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateReloadWeapon.__vftable = (idOpenCombat_ReloadWeapon_vtbl *)&idOpenCombat_ReloadWeapon::`vftable';
  idState::idState(this: &this->stateStand, stateType: &idOpenCombat_Stand::Type, childFSMType: nullptr, flags: 0);
  this->stateStand.__vftable = (idOpenCombat_Stand_vtbl *)&idOpenCombat_Stand::`vftable';
  idState::idState(this: &this->stateCrouch, stateType: &idOpenCombat_Crouch::Type, childFSMType: nullptr, flags: 0);
  this->stateCrouch.__vftable = (idOpenCombat_Crouch_vtbl *)&idOpenCombat_Crouch::`vftable';
  idState::idState(
    this: &this->stateEnemyNotVisible,
    stateType: &idOpenCombat_EnemyNotVisible::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateEnemyNotVisible.__vftable = (idOpenCombat_EnemyNotVisible_vtbl *)&idOpenCombat_EnemyNotVisible::`vftable';
  idState::idState(this: &this->stateSidestep, stateType: &idOpenCombat_Sidestep::Type, childFSMType: nullptr, flags: 0);
  this->stateSidestep.__vftable = (idOpenCombat_Sidestep_vtbl *)&idOpenCombat_Sidestep::`vftable';
  idState::idState(
    this: &this->stateChargeSidestep,
    stateType: &idOpenCombat_ChargeSidestep::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateChargeSidestep.__vftable = (idOpenCombat_ChargeSidestep_vtbl *)&idOpenCombat_ChargeSidestep::`vftable';
  idState::idState(
    this: &this->stateMoveTowardEnemyFailed,
    stateType: &idOpenCombat_MoveTowardEnemyFailed::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveTowardEnemyFailed.__vftable = (idOpenCombat_MoveTowardEnemyFailed_vtbl *)&idOpenCombat_MoveTowardEnemyFailed::`vftable';
  idState::idState(
    this: &this->stateMoveFailed,
    stateType: &idOpenCombat_MoveFailed::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveFailed.__vftable = (idOpenCombat_MoveFailed_vtbl *)&idOpenCombat_MoveFailed::`vftable';
  idState::idState(this: &this->stateRage, stateType: &idOpenCombat_Rage::Type, childFSMType: nullptr, flags: 0);
  this->stateRage.__vftable = (idOpenCombat_Rage_vtbl *)&idOpenCombat_Rage::`vftable';
  idState::idState(
    this: &this->stateMoveToRecharge,
    stateType: &idOpenCombat_MoveToRecharge::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveToRecharge.__vftable = (idOpenCombat_MoveToRecharge_vtbl *)&idOpenCombat_MoveToRecharge::`vftable';
  idState::idState(
    this: &this->stateRecharging,
    stateType: &idOpenCombat_Recharging::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateRecharging.__vftable = (idOpenCombat_Recharging_vtbl *)&idOpenCombat_Recharging::`vftable';
  idState::idState(
    this: &this->stateMoveToRoleHintNode,
    stateType: &idOpenCombat_MoveToRoleHintNode::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveToRoleHintNode.__vftable = (idOpenCombat_MoveToRoleHintNode_vtbl *)&idOpenCombat_MoveToRoleHintNode::`vftable';
  idState::idState(
    this: &this->statePlayOverrideAnim,
    stateType: &idOpenCombat_PlayOverrideAnim::Type,
    childFSMType: nullptr,
    flags: 0);
  this->statePlayOverrideAnim.__vftable = (idOpenCombat_PlayOverrideAnim_vtbl *)&idOpenCombat_PlayOverrideAnim::`vftable';
  idFiniteStateMachine::SetDefaultState(this, state: &this->stateDefault);
  return this;
}


// ========================================================================
// __unwind$493557
// EA  : 0x82ADECF4
// RVA : 0x00ADECF4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493557()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$493558
// EA  : 0x82ADED1C
// RVA : 0x00ADED1C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493558()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$493559
// EA  : 0x82ADED48
// RVA : 0x00ADED48
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493559()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$493560
// EA  : 0x82ADED74
// RVA : 0x00ADED74
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493560()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// __unwind$493561
// EA  : 0x82ADEDA0
// RVA : 0x00ADEDA0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493561()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 192));
}


// ========================================================================
// __unwind$493562
// EA  : 0x82ADEDCC
// RVA : 0x00ADEDCC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493562()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 220));
}


// ========================================================================
// __unwind$493563
// EA  : 0x82ADEDF8
// RVA : 0x00ADEDF8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493563()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 248));
}


// ========================================================================
// __unwind$493564
// EA  : 0x82ADEE24
// RVA : 0x00ADEE24
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493564()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 276));
}


// ========================================================================
// __unwind$493565
// EA  : 0x82ADEE50
// RVA : 0x00ADEE50
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493565()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 304));
}


// ========================================================================
// __unwind$493566
// EA  : 0x82ADEE7C
// RVA : 0x00ADEE7C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493566()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 332));
}


// ========================================================================
// __unwind$493567
// EA  : 0x82ADEEA8
// RVA : 0x00ADEEA8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493567()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 360));
}


// ========================================================================
// __unwind$493568
// EA  : 0x82ADEED4
// RVA : 0x00ADEED4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493568()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 388));
}


// ========================================================================
// __unwind$493569
// EA  : 0x82ADEF00
// RVA : 0x00ADEF00
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493569()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 416));
}


// ========================================================================
// __unwind$493570
// EA  : 0x82ADEF2C
// RVA : 0x00ADEF2C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493570()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 444));
}


// ========================================================================
// __unwind$493571
// EA  : 0x82ADEF58
// RVA : 0x00ADEF58
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493571()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 472));
}


// ========================================================================
// __unwind$493572
// EA  : 0x82ADEF84
// RVA : 0x00ADEF84
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493572()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 500));
}


// ========================================================================
// __unwind$493573
// EA  : 0x82ADEFB0
// RVA : 0x00ADEFB0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493573()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 528));
}


// ========================================================================
// __unwind$493574
// EA  : 0x82ADEFDC
// RVA : 0x00ADEFDC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493574()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 556));
}


// ========================================================================
// __unwind$493575
// EA  : 0x82ADF008
// RVA : 0x00ADF008
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493575()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 584));
}


// ========================================================================
// __unwind$493576
// EA  : 0x82ADF034
// RVA : 0x00ADF034
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493576()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 612));
}


// ========================================================================
// __unwind$493577
// EA  : 0x82ADF060
// RVA : 0x00ADF060
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493577()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 640));
}


// ========================================================================
// __unwind$493578
// EA  : 0x82ADF08C
// RVA : 0x00ADF08C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493578()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 668));
}


// ========================================================================
// __unwind$493579
// EA  : 0x82ADF0B8
// RVA : 0x00ADF0B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493579()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 696));
}


// ========================================================================
// __unwind$493580
// EA  : 0x82ADF0E4
// RVA : 0x00ADF0E4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493580()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 724));
}


// ========================================================================
// __unwind$493581
// EA  : 0x82ADF110
// RVA : 0x00ADF110
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493581()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 752));
}


// ========================================================================
// __unwind$493582
// EA  : 0x82ADF13C
// RVA : 0x00ADF13C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493582()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 780));
}


// ========================================================================
// __unwind$493583
// EA  : 0x82ADF168
// RVA : 0x00ADF168
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493583()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 808));
}


// ========================================================================
// __unwind$493584
// EA  : 0x82ADF194
// RVA : 0x00ADF194
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_493584()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 836));
}


// ========================================================================
// ??1idOpenCombatFSM@@UAA@XZ
// EA  : 0x82ADF1C8
// RVA : 0x00ADF1C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombatFSM::~idOpenCombatFSM(idOpenCombatFSM *this)
{
  this->__vftable = (idOpenCombatFSM_vtbl *)&idOpenCombatFSM::`vftable';
  idState::~idState(this: &this->statePlayOverrideAnim);
  idState::~idState(this: &this->stateMoveToRoleHintNode);
  idState::~idState(this: &this->stateRecharging);
  idState::~idState(this: &this->stateMoveToRecharge);
  idState::~idState(this: &this->stateRage);
  idState::~idState(this: &this->stateMoveFailed);
  idState::~idState(this: &this->stateMoveTowardEnemyFailed);
  idState::~idState(this: &this->stateChargeSidestep);
  idState::~idState(this: &this->stateSidestep);
  idState::~idState(this: &this->stateEnemyNotVisible);
  idState::~idState(this: &this->stateCrouch);
  idState::~idState(this: &this->stateStand);
  idState::~idState(this: &this->stateReloadWeapon);
  idState::~idState(this: &this->stateMoveOutOfSightAndReload);
  idState::~idState(this: &this->stateMoveToCoverAndReload);
  idState::~idState(this: &this->stateLeapAttack);
  idState::~idState(this: &this->stateChargeMelee);
  idState::~idState(this: &this->stateAttackMelee);
  idState::~idState(this: &this->stateReachedEnemyPos);
  idState::~idState(this: &this->stateAttackMove);
  idState::~idState(this: &this->stateShoot);
  idState::~idState(this: &this->stateThrowProjectile);
  idState::~idState(this: &this->stateStartThrowProjectile);
  idState::~idState(this: &this->stateAttackIdle);
  idState::~idState(this: &this->stateMoveToSightEnemy);
  idState::~idState(this: &this->stateMoveTowardEnemy);
  idState::~idState(this: &this->stateDefault);
  idFiniteStateMachine::~idFiniteStateMachine(this);
}


// ========================================================================
// __unwind$494037
// EA  : 0x82ADF2EC
// RVA : 0x00ADF2EC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494037()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$494038
// EA  : 0x82ADF314
// RVA : 0x00ADF314
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494038()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// __unwind$494039
// EA  : 0x82ADF340
// RVA : 0x00ADF340
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494039()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$494040
// EA  : 0x82ADF36C
// RVA : 0x00ADF36C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494040()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// __unwind$494041
// EA  : 0x82ADF398
// RVA : 0x00ADF398
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494041()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 192));
}


// ========================================================================
// __unwind$494042
// EA  : 0x82ADF3C4
// RVA : 0x00ADF3C4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494042()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 220));
}


// ========================================================================
// __unwind$494043
// EA  : 0x82ADF3F0
// RVA : 0x00ADF3F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494043()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 248));
}


// ========================================================================
// __unwind$494044
// EA  : 0x82ADF41C
// RVA : 0x00ADF41C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494044()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 276));
}


// ========================================================================
// __unwind$494045
// EA  : 0x82ADF448
// RVA : 0x00ADF448
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494045()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 304));
}


// ========================================================================
// __unwind$494046
// EA  : 0x82ADF474
// RVA : 0x00ADF474
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494046()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 332));
}


// ========================================================================
// __unwind$494047
// EA  : 0x82ADF4A0
// RVA : 0x00ADF4A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494047()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 360));
}


// ========================================================================
// __unwind$494048
// EA  : 0x82ADF4CC
// RVA : 0x00ADF4CC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494048()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 388));
}


// ========================================================================
// __unwind$494049
// EA  : 0x82ADF4F8
// RVA : 0x00ADF4F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494049()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 416));
}


// ========================================================================
// __unwind$494050
// EA  : 0x82ADF524
// RVA : 0x00ADF524
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494050()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 444));
}


// ========================================================================
// __unwind$494051
// EA  : 0x82ADF550
// RVA : 0x00ADF550
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494051()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 472));
}


// ========================================================================
// __unwind$494052
// EA  : 0x82ADF57C
// RVA : 0x00ADF57C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494052()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 500));
}


// ========================================================================
// __unwind$494053
// EA  : 0x82ADF5A8
// RVA : 0x00ADF5A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494053()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 528));
}


// ========================================================================
// __unwind$494054
// EA  : 0x82ADF5D4
// RVA : 0x00ADF5D4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494054()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 556));
}


// ========================================================================
// __unwind$494055
// EA  : 0x82ADF600
// RVA : 0x00ADF600
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494055()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 584));
}


// ========================================================================
// __unwind$494056
// EA  : 0x82ADF62C
// RVA : 0x00ADF62C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494056()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 612));
}


// ========================================================================
// __unwind$494057
// EA  : 0x82ADF658
// RVA : 0x00ADF658
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494057()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 640));
}


// ========================================================================
// __unwind$494058
// EA  : 0x82ADF684
// RVA : 0x00ADF684
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494058()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 668));
}


// ========================================================================
// __unwind$494059
// EA  : 0x82ADF6B0
// RVA : 0x00ADF6B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494059()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 696));
}


// ========================================================================
// __unwind$494060
// EA  : 0x82ADF6DC
// RVA : 0x00ADF6DC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494060()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 724));
}


// ========================================================================
// __unwind$494061
// EA  : 0x82ADF708
// RVA : 0x00ADF708
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494061()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 752));
}


// ========================================================================
// __unwind$494062
// EA  : 0x82ADF734
// RVA : 0x00ADF734
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494062()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 780));
}


// ========================================================================
// __unwind$494063
// EA  : 0x82ADF760
// RVA : 0x00ADF760
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_494063()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 808));
}


// ========================================================================
// ?CanUse@idOpenCombatFSM@@UBA_NPAVidFiniteStateMachine@@H@Z
// EA  : 0x82ADF790
// RVA : 0x00ADF790
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

BOOL __fastcall idOpenCombatFSM::CanUse(idOpenCombatFSM *this, idFiniteStateMachine *fsm, const int curTime)
{
  idAI2 *Owner; // r3
  idAI2 *v4; // r3
  unsigned __int8 v6; // r11

  Owner = (idAI2 *)idFiniteStateMachine::GetOwner(this: fsm);
  v4 = idAI2::CastTo(c: Owner);
  if ( (*((_BYTE *)v4->aiEditable.behaviors.decl + 196) & 8) == 0 )
    return false;
  if ( (v4->aiVolatile.groupStatus.condition & 0x200) != 0
    || (v6 = 1, !v4->aiVolatile.groupStatus.roleChangeResponseRequired) )
  {
    v6 = 0;
  }
  return (_cntlzw(v6) & 0x20) != 0;
}


// ========================================================================
// CheckMoveDir2
// EA  : 0x82ADF818
// RVA : 0x00ADF818
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

float __fastcall CheckMoveDir2(
        idAI2 *ai,
        idAIFSM *fsm,
        aiSenseState_t *curTime,
        const idVec3 *dir,
        const aiSenseState_t *ss,
        idVec3 *bestPos)
{
  double v10; // fp29
  idPhysics *Physics; // r3
  const idVec3 *v12; // r29
  double v13; // fp26
  const idAAS2 *v14; // r22
  double v15; // fp9
  double z; // fp6
  double v17; // fp4
  const idAAS2 *v18; // r3
  idAASPosition *AASPosition; // r3
  idAAS2 *aas; // r20
  unsigned int v21; // r19
  idAAS2_vtbl *v22; // r28
  int AreaNum; // r3
  double fraction; // fp30
  double v25; // fp1
  double y; // fp13
  double v27; // fp12
  double v28; // fp1
  int v30; // [sp+8h] [-218h]
  bool v31; // [sp+Fh] [-211h]
  const char *v32; // [sp+10h] [-210h]
  int v33; // [sp+14h] [-20Ch]
  int v34; // [sp+18h] [-208h]
  int v35; // [sp+1Ch] [-204h]
  int v36; // [sp+20h] [-200h]
  int v37; // [sp+24h] [-1FCh]
  int v38; // [sp+28h] [-1F8h]
  int v39; // [sp+2Ch] [-1F4h]
  int v40; // [sp+30h] [-1F0h]
  int v41; // [sp+34h] [-1ECh]
  int v42; // [sp+38h] [-1E8h]
  int v43; // [sp+3Ch] [-1E4h]
  int v44; // [sp+40h] [-1E0h]
  int v45; // [sp+44h] [-1DCh]
  int v46; // [sp+48h] [-1D8h]
  int v47; // [sp+4Ch] [-1D4h]
  int v48; // [sp+50h] [-1D0h]
  int v49; // [sp+58h] [-1C8h]
  int v50; // [sp+60h] [-1C0h]
  idVec3 v51; // [sp+70h] [-1B0h] BYREF
  float v52[21]; // [sp+80h] [-1A0h] BYREF
  float v53; // [sp+D4h] [-14Ch] BYREF
  float v54; // [sp+D8h] [-148h] BYREF
  float v55; // [sp+DCh] [-144h] BYREF
  float v56[2]; // [sp+E0h] [-140h] BYREF
  char v57; // [sp+E8h] [-138h] BYREF
  trace_t v58; // [sp+F0h] [-130h] BYREF

  v10 = 200.0;
  Physics = idEntity::GetPhysics(this: ai);
  v12 = Physics->GetOrigin(this: Physics, a2: 0);
  v13 = -1.0;
  v14 = ai->GetAAS(this: ai);
  do
  {
    v15 = (float)(*(float *)&fsm->listeningToList * (float)v10);
    z = v12->z;
    v17 = (float)((float)(*(float *)&fsm->listenerList * (float)v10) + v12->y);
    v51.x = v12->x + (float)(*(float *)&fsm->__vftable * (float)v10);
    v51.y = v17;
    v51.z = (float)v15 + (float)z;
    if ( v14 != nullptr )
    {
      v18 = ai->GetAAS(this: ai);
      AASPosition = (idAASPosition *)idActor::GetAASPosition(this: ai, aas: v18);
      v52[0] = 0.0;
      v52[1] = 0.0;
      memset(&v52[4], 0, 12);
      v52[2] = 0.0;
      v52[3] = 0.0;
      v52[7] = 0.0;
      v52[10] = 0.0;
      v52[8] = 0.0;
      v52[11] = 0.0;
      v52[9] = 0.0;
      memset(&v52[15], 0, 24);
      v52[12] = 0.0;
      v52[13] = 0.0;
      v52[14] = 0.0;
      aas = (idAAS2 *)AASPosition->aas;
      v21 = ai->aiVolatile.aas.travelFlags & 0xFE78FFFF;
      v22 = aas->__vftable;
      AreaNum = idAASPosition::GetAreaNum(this: AASPosition);
      ((void (__fastcall *)(idAAS2 *, float *, const idVec3 *, int, idVec3 *, unsigned int, _DWORD, int))v22->TraceFloor)(
        a1: aas,
        a2: v52,
        a3: v12,
        a4: AreaNum,
        a5: &v51,
        a6: v21,
        a7: 0,
        a8: 1);
      fraction = v52[0];
    }
    else
    {
      idClip::Translation(
        this: (idClip *)&v57,
        result: &clientGame->clip,
        a3: &v58,
        start: v12,
        end: dir,
        clipModel: clientGame->clip.clip32x32x96,
        startAxis: &mat3_identity,
        clipMask: 1,
        passEntityNumber: v30,
        moveClipModel: v31,
        userName: v32,
        a12: v33,
        a13: v34,
        a14: v35,
        a15: v36,
        a16: v37,
        a17: v38,
        a18: v39,
        a19: v40,
        a20: v41,
        a21: v42,
        a22: v43,
        a23: v44,
        a24: v45,
        a25: v46,
        a26: v47,
        a27: v48,
        a28: ai->entityNumber,
        a29: v49,
        a30: false,
        a31: v50,
        a32: 0);
      fraction = v58.fraction;
    }
    if ( fraction >= 1.0 )
    {
      v25 = idAI2::PositionScore(
              this: ai,
              candidatePosition: &v51,
              ss: curTime,
              targetDistScore: &v53,
              aiDistScore: v56,
              groupScore: &v54,
              hintNodeScore: &v55);
      if ( v25 > v13 )
      {
        v13 = v25;
        y = v51.y;
        v27 = v51.z;
        dir->x = v51.x;
        dir->y = y;
        dir->z = v27;
      }
    }
    v10 = (float)((float)v10 * (float)0.5);
  }
  while ( fraction < 1.0 && v10 >= 45.0 );
  v28 = v13;
  return *((float *)&v28 + 1);
}


// ========================================================================
// CheckMove
// EA  : 0x82ADFA70
// RVA : 0x00ADFA70
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall CheckMove(
        idAI2 *ai,
        idAIFSM *fsm,
        float *curTime,
        const bool stayNearCover,
        idVec3 *outPos)
{
  char v5; // r30
  aiSenseState_t *EnemySenseState; // r27
  int v9; // r11
  idArray<enum idAI2::idVisibilityObscurity::obscurity_t,7> *p_visibilityObscurity; // r10
  char v11; // r11
  idAIMoveState *MoveInterface; // r3
  idAIOrientation *BodyOrientation; // r3
  int v14; // r28
  double x; // fp10
  double y; // fp9
  double z; // fp7
  double v18; // fp13
  double v19; // fp12
  double v20; // fp4
  double v21; // fp11
  double v22; // fp3
  double v23; // fp2
  idPhysics *Physics; // r3
  const idVec3 *v25; // r3
  idVec3 *v26; // r8
  const aiSenseState_t *v27; // r7
  double v28; // fp31
  int v29; // r30
  idAIFSM *v30; // r29
  double v31; // fp1
  double v32; // fp13
  double v33; // fp12
  idAIStateTransition::aiTransCode_t result; // r3
  bool v35; // zf
  int v36; // [sp+50h] [-C0h] BYREF
  float v37; // [sp+54h] [-BCh] BYREF
  float v38; // [sp+58h] [-B8h] BYREF
  float v39; // [sp+5Ch] [-B4h] BYREF
  idVec3 v40; // [sp+60h] [-B0h] BYREF
  float v41[3]; // [sp+70h] [-A0h] BYREF
  float v42; // [sp+7Ch] [-94h]
  float v43; // [sp+80h] [-90h]
  float v44; // [sp+84h] [-8Ch]
  float v45; // [sp+88h] [-88h]
  float v46; // [sp+8Ch] [-84h]
  float v47; // [sp+90h] [-80h]
  float v48; // [sp+94h] [-7Ch]
  float v49; // [sp+98h] [-78h]
  float v50; // [sp+9Ch] [-74h]
  float v51; // [sp+A0h] [-70h]
  float v52; // [sp+A4h] [-6Ch]
  float v53; // [sp+A8h] [-68h]
  float v54; // [sp+ACh] [-64h]
  float v55; // [sp+B0h] [-60h]
  float v56; // [sp+B4h] [-5Ch]
  float v57; // [sp+B8h] [-58h]
  float v58; // [sp+BCh] [-54h]
  float v59; // [sp+C0h] [-50h]
  float v60; // [sp+C4h] [-4Ch]
  float v61; // [sp+C8h] [-48h]
  float v62; // [sp+CCh] [-44h]

  v5 = (char)fsm;
  EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  if ( EnemySenseState == nullptr )
    return 0;
  if ( v5 != 0 && ai->aiVolatile.visibilityObscurity.valid )
  {
    v9 = 0;
    p_visibilityObscurity = &ai->aiVolatile.visibilityObscurity.visibilityObscurity;
    while ( p_visibilityObscurity->ptr[0] != OBSCURITY_PATH_OPEN_WITH_COVER )
    {
      ++v9;
      p_visibilityObscurity = (idArray<enum idAI2::idVisibilityObscurity::obscurity_t,7> *)((char *)p_visibilityObscurity
                                                                                          + 4);
      if ( v9 >= 7 )
      {
        v11 = 0;
        goto LABEL_8;
      }
    }
    v11 = 1;
LABEL_8:
    if ( v11 != 0 )
      return 0;
  }
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v36 = 2000;
  if ( MoveInterface->RecentlyFailedMove(
         this: MoveInterface,
         a2: AIMOVEREASON_OC_ATTACK_MOVE,
         a3: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&v36) )
  {
    BodyOrientation = idAI2::GetBodyOrientation(this: ai);
    v14 = -1;
    x = BodyOrientation->axis.mat[0].x;
    y = BodyOrientation->axis.mat[0].y;
    z = BodyOrientation->axis.mat[0].z;
    v18 = BodyOrientation->axis.mat[1].x;
    v19 = BodyOrientation->axis.mat[1].y;
    v20 = (float)(BodyOrientation->axis.mat[1].x + BodyOrientation->axis.mat[0].x);
    v21 = BodyOrientation->axis.mat[1].z;
    v22 = (float)(BodyOrientation->axis.mat[1].y + BodyOrientation->axis.mat[0].y);
    v23 = (float)(BodyOrientation->axis.mat[1].z + BodyOrientation->axis.mat[0].z);
    v41[0] = BodyOrientation->axis.mat[0].x;
    v41[1] = y;
    v53 = -z;
    v51 = -x;
    v41[2] = z;
    v52 = -y;
    v45 = v18;
    v46 = v19;
    v47 = v21;
    v42 = (float)v20 * (float)0.70710677;
    v57 = -v18;
    v58 = -v19;
    v59 = -v21;
    v43 = (float)v22 * (float)0.70710677;
    v44 = (float)v23 * (float)0.70710677;
    v48 = (float)((float)v18 + v51) * (float)0.70710677;
    v49 = (float)((float)v19 + v52) * (float)0.70710677;
    v50 = (float)((float)v21 + v53) * (float)0.70710677;
    v54 = -v42;
    v55 = -v43;
    v56 = -v44;
    v60 = -v48;
    v61 = -v49;
    v62 = -v50;
    Physics = idEntity::GetPhysics(this: ai);
    v25 = Physics->GetOrigin(this: Physics, a2: 0);
    v28 = idAI2::PositionScore(
            this: ai,
            candidatePosition: v25,
            ss: EnemySenseState,
            targetDistScore: (float *)&v36,
            aiDistScore: &v37,
            groupScore: &v38,
            hintNodeScore: &v39);
    v29 = 0;
    v30 = (idAIFSM *)v41;
    do
    {
      v31 = CheckMoveDir2(ai, fsm: v30, curTime: EnemySenseState, dir: &v40, ss: v27, bestPos: v26);
      if ( v31 > v28 )
      {
        v28 = v31;
        v32 = v40.y;
        v14 = v29;
        v33 = v40.z;
        *curTime = v40.x;
        curTime[1] = v32;
        curTime[2] = v33;
      }
      ++v29;
      v30 = (idAIFSM *)((char *)v30 + 12);
    }
    while ( v29 < 8 );
    if ( v14 != -1 )
      return TRANSCODE_OC_ATTACK_MOVE;
  }
  if ( (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 0x40) == 0 )
    return 0;
  if ( (unsigned __int8)idAI2::EnemyTooCloseToGoProne(this: ai, facingMatters: true, obscurityMatters: true) != 0 )
    return 0;
  v35 = ai->GetPosture(this: ai) != POSTURE_CROUCHED;
  result = TRANSCODE_OC_CROUCH;
  if ( !v35 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_ShouldMoveToSightEnemy@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADFD30
// RVA : 0x00ADFD30
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_ShouldMoveToSightEnemy::Evaluate(
        OC_ShouldMoveToSightEnemy *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3
  idFiniteStateMachine *FullPath; // r3
  idFiniteStateMachine *v9; // r30
  idAIAction *v10; // r3
  const aiSenseState_t *EnemySenseState; // r30
  idCombatStage *v12; // r30
  idEncounterGroup *EncounterGroup; // r3
  int curCombatStage; // r11
  idEncounterGroup *v15; // r3
  int v16; // r11
  int v17; // r3
  unsigned int v18; // r22
  idPhysics *Physics; // r3
  idAICombatHint::combatHintClass_t combatHintClass; // r29
  const idVec3 *v21; // r3
  idPhysics *v22; // r3
  idAICombatHint::combatHintClass_t v23; // r30
  const idVec3 *v24; // r3
  double v25; // fp31
  idAI2::idVisibilityObscurity::obscurityTest_t v26; // r29
  idArray<enum idAI2::idVisibilityObscurity::obscurity_t,7> *p_visibilityObscurity; // r23
  idPhysics *v28; // r3
  float *v29; // r3
  double v30; // fp30
  double v31; // fp0
  double v32; // fp12
  idPhysics *v33; // r30
  idRenderWorld *v34; // r21
  idPhysics *v35; // r3
  idRenderWorld_vtbl *v36; // r30
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v38; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  int v40; // [sp+50h] [-A0h] BYREF
  idAI2::idVisibilityObscurity v41; // [sp+58h] [-98h] BYREF

  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v40 = 2500;
  if ( MoveInterface->RecentlyFailedMove(
         this: MoveInterface,
         a2: AIMOVEREASON_OC_MOVE_TO_SIGHT_ENEMY,
         a3: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&v40) )
  {
    return 0;
  }
  if ( ai->aiEditable.movement.turretMode )
    return 0;
  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  v9 = FullPath;
  if ( FullPath != nullptr && idFiniteStateMachine::GetStatus(this: FullPath) != 0 )
  {
    v10 = idAIAction::CastTo(c: (idAIAction *)v9->curState);
    if ( v10 == nullptr || (unsigned __int8)idAction_Idle::IsTypeOf(c: v10) == 0 )
      return 0;
  }
  EnemySenseState = idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  if ( EnemySenseState == nullptr
    || idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
     - EnemySenseState->lastConfirmedStimTime >= 5000
    || !ai->aiVolatile.visibilityObscurity.valid
    || (ai->aiVolatile.groupStatus.condition & 8) != 0
    && ai->aiVolatile.death.injuredCount >= ai->aiEditable.behaviors.decl->damageBehaviors.injuredDontMoveCount )
  {
    return 0;
  }
  v12 = nullptr;
  if ( idAI2::GetEncounterGroup(this: ai) != nullptr )
  {
    EncounterGroup = idAI2::GetEncounterGroup(this: ai);
    curCombatStage = EncounterGroup->curCombatStage;
    if ( curCombatStage >= 0
      && curCombatStage < EncounterGroup->combatStages.num
      && &EncounterGroup->combatStages.list[curCombatStage] != nullptr )
    {
      v15 = idAI2::GetEncounterGroup(this: ai);
      v16 = v15->curCombatStage;
      if ( v16 < 0 || v16 >= v15->combatStages.num )
        v12 = nullptr;
      else
        v12 = &v15->combatStages.list[v16];
    }
  }
  v17 = idCombatStage::RoleToHintType(role: (const encounterGroupRole_t)ai->aiVolatile.groupStatus.currentRole);
  v18 = v17;
  if ( v12 != nullptr && v17 != 8 )
  {
    Physics = idEntity::GetPhysics(this: ai);
    combatHintClass = ai->aiEditable.movement.combatHintClass;
    v21 = Physics->GetOrigin(this: Physics, a2: 0);
    if ( idCombatStage::GetClosestHintNodePtr(this: v12, hintType: v18, currentPos: v21, hintClass: combatHintClass) != nullptr )
    {
      v22 = idEntity::GetPhysics(this: ai);
      v23 = ai->aiEditable.movement.combatHintClass;
      v24 = v22->GetOrigin(this: v22, a2: 0);
      if ( idAI2::RoleHintNodeScore(this: ai, point: v24, hintClass: v23) == 0.0 )
        return 0;
    }
  }
  v25 = 0.0;
  v26 = OBSCURITYTEST_MUZZLE_POS;
  p_visibilityObscurity = &ai->aiVolatile.visibilityObscurity.visibilityObscurity;
  do
  {
    if ( v26 != OBSCURITYTEST_MUZZLE_POS && p_visibilityObscurity->ptr[0] == OBSCURITY_PATH_OPEN_AND_ENEMY_VISIBLE )
    {
      idAI2::idVisibilityObscurity::GetDestination(
        this: &v41,
        result: (idVec3 *)&ai->aiVolatile.visibilityObscurity,
        (idVec3 *)ai,
        obscurityTest: v26);
      v28 = idEntity::GetPhysics(this: ai);
      v29 = (float *)v28->GetOrigin(this: v28, a2: 0);
      v30 = (float)((float)((float)(*(float *)&v41.clipQuery[0].index - *v29)
                          * (float)(*(float *)&v41.clipQuery[0].index - *v29))
                  + (float)((float)((float)(*(float *)&v41.clipQuery[1].index - v29[2])
                                  * (float)(*(float *)&v41.clipQuery[1].index - v29[2]))
                          + (float)((float)(*((float *)&v41.clipQuery[0].index + 1) - v29[1])
                                  * (float)(*((float *)&v41.clipQuery[0].index + 1) - v29[1]))));
      if ( (v25 == 0.0 || v30 > v25)
        && (v18 == 8
         || idAI2::RoleHintNodeScore(
              this: ai,
              point: (const idVec3 *)&v41,
              hintClass: ai->aiEditable.movement.combatHintClass) != 0.0) )
      {
        v31 = *((float *)&v41.clipQuery[0].index + 1);
        v25 = v30;
        v32 = *(float *)&v41.clipQuery[1].index;
        ai->aiVolatile.memory.cachedDestination.x = *(float *)&v41.clipQuery[0].index;
        ai->aiVolatile.memory.cachedDestination.y = v31;
        ai->aiVolatile.memory.cachedDestination.z = v32;
        if ( ai_debugDodge.valueInteger != 0 && idAI2::GetDebugLevel() > 0 )
        {
          v33 = idEntity::GetPhysics(this: ai);
          v34 = common->RW(this: common);
          v35 = v33;
          GetOrigin = v33->GetOrigin;
          v36 = v34->__vftable;
          v38 = (int)GetOrigin(this: v35, a2: 0);
          ((void (__fastcall *)(idRenderWorld *, idColor *, int, idAI2::idVisibilityObscurity *, double))v36->DebugArrow)(
            a1: v34,
            a2: &idColor::colorMagenta,
            a3: v38,
            a4: &v41,
            a5: 2.0);
        }
      }
    }
    ++v26;
    p_visibilityObscurity = (idArray<enum idAI2::idVisibilityObscurity::obscurity_t,7> *)((char *)p_visibilityObscurity
                                                                                        + 4);
  }
  while ( v26 < OBSCURITYTEST_NUM );
  result = TRANSCODE_OC_SHOULD_MOVE_TO_SIGHT_ENEMY;
  if ( v25 == 0.0 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_ThrowProjectile@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE0128
// RVA : 0x00AE0128
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_ThrowProjectile::Evaluate(
        OC_ThrowProjectile *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  const idTrajectory_Parabolic *v6; // r3
  _DWORD *p_gravity; // r11
  float *v8; // r10
  int i; // ctr
  int v11[4]; // [sp+50h] [-20h] BYREF

  if ( (unsigned __int8)idAI2::HasWaitingTrajectoryResults(this: ai) == 0 )
    return 285;
  v11[0] = -1;
  v6 = idTrajectory_Parabolic::SelectTrajectory(trajectories: ai->aiVolatile.trajectories.ptr, num: 4, parmsIndex: v11);
  if ( v6 != nullptr )
  {
    p_gravity = (_DWORD *)&v6->GetTrajectoryParms_2(this: v6, a2: v11[0])[-1].gravity;
    v8 = &ai->aiVolatile.memory.projectileInfo.linearParms.gravity;
    for ( i = 7; i != 0; --i )
      *++v8 = *(float *)++p_gravity;
    idAI2::ClearTrajectoryResults(this: ai);
    return 285;
  }
  idAI2::ClearTrajectoryResults(this: ai);
  return 286;
}


// ========================================================================
// ?Evaluate@OC_ShouldReload@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE01F0
// RVA : 0x00AE01F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_ShouldReload::Evaluate(
        OC_ShouldReload *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idWeapon *v7; // r30
  idAIMoveState *MoveInterface; // r3
  idAI2::idVisibilityObscurity::obscurityTest_t v9; // r6
  idAI2::idVisibilityObscurity::obscurity_t *i; // r11
  double v12; // fp13
  double v13; // fp12
  idPhysics *Physics; // r31
  idRenderWorld *v15; // r30
  idPhysics *v16; // r3
  idRenderWorld_vtbl *v17; // r31
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v19; // r3
  int v20; // [sp+50h] [-40h] BYREF
  float v21[14]; // [sp+58h] [-38h] BYREF

  v7 = ai->GetEquippedWeapon(this: ai);
  if ( (ai->aiVolatile.groupStatus.condition & 8) == 0
    && (unsigned __int8)idAI2::EnemyTooCloseToGoProne(this: ai, facingMatters: true, obscurityMatters: true) != 0
    && ai->aiVolatile.memory.lastMoveFailedTime < curTime - 1000
    || v7 == nullptr
    || idWeapon::IsFullyLoaded(this: v7, secondaryAmmo: false)
    || !v7->NeedsReload(this: v7, a2: false)
    && ((double (__fastcall *)(idWeapon *, _DWORD))v7->AmmoInClipPercentage)(a1: v7, a2: 0) >= 0.1 )
  {
    return 0;
  }
  if ( ai->aiEditable.movement.turretMode )
    return 283;
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v20 = 5000;
  if ( MoveInterface->RecentlyFailedMove(
         this: MoveInterface,
         a2: AIMOVEREASON_OC_RELOAD_OUT_OF_SIGHT,
         a3: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&v20)
    || idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX) == nullptr
    || curTime - idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX)->lastConfirmedStimTime >= 1000 )
  {
    return 283;
  }
  if ( !ai->aiVolatile.visibilityObscurity.valid )
    return 0;
  v9 = OBSCURITYTEST_HALF_HEIGHT_FAR_LEFT;
  for ( i = &ai->aiVolatile.visibilityObscurity.visibilityObscurity.ptr[1]; *i != OBSCURITY_PATH_OPEN_WITH_COVER; ++i )
  {
    if ( ++v9 >= OBSCURITYTEST_NUM )
      return 283;
  }
  idAI2::idVisibilityObscurity::GetDestination(
    this: (idAI2::idVisibilityObscurity *)v21,
    result: (idVec3 *)&ai->aiVolatile.visibilityObscurity,
    (idVec3 *)ai,
    obscurityTest: v9);
  v12 = v21[1];
  v13 = v21[2];
  ai->aiVolatile.memory.cachedDestination.x = v21[0];
  ai->aiVolatile.memory.cachedDestination.y = v12;
  ai->aiVolatile.memory.cachedDestination.z = v13;
  if ( ai_debugDodge.valueInteger != 0 && idAI2::GetDebugLevel() > 0 )
  {
    Physics = idEntity::GetPhysics(this: ai);
    v15 = common->RW(this: common);
    v16 = Physics;
    GetOrigin = Physics->GetOrigin;
    v17 = v15->__vftable;
    v19 = (int)GetOrigin(this: v16, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))v17->DebugArrow)(
      a1: v15,
      a2: &idColor::colorOrange,
      a3: v19,
      a4: v21,
      a5: 2.0);
  }
  return 282;
}


// ========================================================================
// ?Evaluate@OC_ShouldEndOpenCombat@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE0470
// RVA : 0x00AE0470
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_ShouldEndOpenCombat::Evaluate(
        OC_ShouldEndOpenCombat *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  if ( curTime - ai->aiVolatile.memory.lastFiredAtTime < 2000
    || ai->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType == ANIMWEBAI_RUNINDEXTYPE_DUCK )
  {
    return 0;
  }
  else
  {
    return __CFADD__(
             curTime - ai->aiVolatile.memory.endOpenCombatTime,
             ai->aiVolatile.memory.endOpenCombatTime ^ 0x80000000)
         ? 0
         : 0x110;
  }
}


// ========================================================================
// ?AIState_Work@idOpenCombat_Crouch@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE04D0
// RVA : 0x00AE04D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_Crouch::AIState_Work(idOpenCombat_Crouch *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  idAIMemory *p_memory; // r26
  idWeapon *(__fastcall *GetEquippedWeapon)(struct idAI2 *); // r10
  int v8; // r3
  int v9; // r28
  bool v10; // r27
  idVec3 *v11; // r7
  unsigned int v12; // r6
  idVec3 *v13; // r4
  aiSenseState_t *EnemySenseState; // r3
  idPhysics *Physics; // r3
  float *v16; // r3
  int v17; // r11
  double v20; // fp10
  double v21; // fp1
  double v22; // fp0
  unsigned int v23; // r4
  bool v24; // cr58
  double v25; // fp13
  double v26; // fp12
  float v27; // [sp+50h] [-60h]
  float v28; // [sp+54h] [-5Ch]
  float v29; // [sp+58h] [-58h]
  float v30[20]; // [sp+60h] [-50h] BYREF

  p_memory = &ai->aiVolatile.memory;
  GetEquippedWeapon = ai->GetEquippedWeapon;
  ai->aiVolatile.memory.transCode = 0;
  v8 = (int)GetEquippedWeapon(this: ai);
  v9 = v8;
  if ( v8 != 0
    && (*(unsigned __int8 (__fastcall **)(int, _DWORD))(*(_DWORD *)v8 + 136))(a1: v8, a2: 0) == 0
    && *(_DWORD *)(v9 + 72) != 3 )
  {
    if ( ai->aiVolatile.memory.numShotsThisPullBlockedConsecutive != 0 )
      ai->aiVolatile.memory.nextMoveTime = 0;
    v10 = curTime >= ai->aiVolatile.memory.nextMoveTime;
    EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
    if ( EnemySenseState != nullptr && curTime > ai->aiVolatile.memory.lastMoveFailedTime + 1000 )
    {
      aiSenseState_t::ExtrapolatePosition(this: EnemySenseState, seconds: 1.0, futurePos: v13);
      Physics = idEntity::GetPhysics(this: ai);
      v16 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v11 = (idVec3 *)0x82000000;
      v12 = 0x82000000;
      v17 = *(_DWORD *)(v9 + 12);
      _FP1 = (float)((float)((float)((float)(v27 - *v16) * (float)(v27 - *v16))
                           + (float)((float)((float)(v29 - v16[2]) * (float)(v29 - v16[2]))
                                   + (float)((float)(v28 - v16[1]) * (float)(v28 - v16[1]))))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f11, f1, f2, f13 }
      v20 = __frsqrte(_FP11);
      v21 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20
                                                                                          * (float)((float)((float)((float)(v27 - *v16) * (float)(v27 - *v16)) + (float)((float)((float)(v29 - v16[2]) * (float)(v29 - v16[2])) + (float)((float)(v28 - v16[1]) * (float)(v28 - v16[1]))))
                                                                                                  * (float)0.5))
                                                                                  * (float)v20)
                                                                          - (float)1.5)
                                                          * (float)v20)
                                                  * (float)((float)((float)((float)(v27 - *v16) * (float)(v27 - *v16))
                                                                  + (float)((float)((float)(v29 - v16[2])
                                                                                  * (float)(v29 - v16[2]))
                                                                          + (float)((float)(v28 - v16[1])
                                                                                  * (float)(v28 - v16[1]))))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v20
                                                                                  * (float)((float)((float)((float)(v27 - *v16) * (float)(v27 - *v16))
                                                                                                  + (float)((float)((float)(v29 - v16[2]) * (float)(v29 - v16[2])) + (float)((float)(v28 - v16[1]) * (float)(v28 - v16[1]))))
                                                                                          * (float)0.5))
                                                                          * (float)v20)
                                                                  - (float)1.5)
                                                  * (float)v20))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v20
                                                          * (float)((float)((float)((float)(v27 - *v16)
                                                                                  * (float)(v27 - *v16))
                                                                          + (float)((float)((float)(v29 - v16[2])
                                                                                          * (float)(v29 - v16[2]))
                                                                                  + (float)((float)(v28 - v16[1])
                                                                                          * (float)(v28 - v16[1]))))
                                                                  * (float)0.5))
                                                  * (float)v20)
                                          - (float)1.5)
                          * (float)v20));
      v22 = (float)((float)((float)-(float)((float)((float)((float)v21
                                                          * (float)((float)((float)((float)(v27 - *v16)
                                                                                  * (float)(v27 - *v16))
                                                                          + (float)((float)((float)(v29 - v16[2])
                                                                                          * (float)(v29 - v16[2]))
                                                                                  + (float)((float)(v28 - v16[1])
                                                                                          * (float)(v28 - v16[1]))))
                                                                  * (float)0.5))
                                                  * (float)v21)
                                          - (float)1.5)
                          * (float)v21)
                  * (float)((float)((float)(v27 - *v16) * (float)(v27 - *v16))
                          + (float)((float)((float)(v29 - v16[2]) * (float)(v29 - v16[2]))
                                  + (float)((float)(v28 - v16[1]) * (float)(v28 - v16[1])))));
      if ( v22 < *(float *)(v17 + 584) )
        v10 = true;
      if ( v22 > *(float *)(v17 + 580) )
        v10 = true;
    }
    if ( p_memory->transCode == 0 && v10 )
    {
      p_memory->transCode = CheckMove(ai, fsm: (idAIFSM *)1, curTime: v30, stayNearCover: v12, outPos: v11);
      v23 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v23;
      v24 = p_memory->transCode == 0;
      ai->aiVolatile.memory.nextMoveTime = ((v23 >> 10) & 0x7FFF) % 0x7D0 + curTime + 3000;
      if ( !v24 )
      {
        v25 = v30[1];
        v26 = v30[2];
        ai->aiVolatile.memory.cachedDestination.x = v30[0];
        ai->aiVolatile.memory.cachedDestination.y = v25;
        ai->aiVolatile.memory.cachedDestination.z = v26;
      }
    }
  }
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_Rage@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE0738
// RVA : 0x00AE0738
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_Rage::AIState_EnterState(
        idOpenCombat_Rage *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
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
  if ( ai->aiVolatile.memory.transCode == TRANSCODE_OC_SHOULD_TAUNT_RAGE )
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
// ?AIState_EnterState@idOpenCombat_MoveTowardEnemyFailed@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE0838
// RVA : 0x00AE0838
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_MoveTowardEnemyFailed::AIState_EnterState(
        idOpenCombat_MoveTowardEnemyFailed *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime,
        idVec3 *a5)
{
  idAIMemory *p_memory; // r28
  idAIStateTransition::aiTransCode_t v8; // r29
  int v9; // r27
  idPhysics *Physics; // r3
  const idVec3 *v11; // r3
  idClientGame *v12; // r11
  double v13; // fp0
  double v14; // fp13
  double v15; // fp12
  posture_t v16; // [sp+8h] [-158h]
  int v17; // [sp+Ch] [-154h]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v18; // [sp+10h] [-150h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v19; // [sp+14h] [-14Ch]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v20; // [sp+18h] [-148h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v21; // [sp+1Ch] [-144h]
  int v22; // [sp+20h] [-140h]
  int v23; // [sp+24h] [-13Ch]
  int v24; // [sp+28h] [-138h]
  int v25; // [sp+2Ch] [-134h]
  int v26; // [sp+30h] [-130h]
  int v27; // [sp+34h] [-12Ch]
  int v28; // [sp+38h] [-128h]
  int v29; // [sp+3Ch] [-124h]
  int v30; // [sp+40h] [-120h]
  int v31; // [sp+44h] [-11Ch]
  int v32; // [sp+48h] [-118h]
  int v33; // [sp+4Ch] [-114h]
  int v34; // [sp+50h] [-110h]
  int v35; // [sp+54h] [-10Ch]
  int v36; // [sp+58h] [-108h]
  int v37; // [sp+60h] [-100h]
  int v38; // [sp+68h] [-F8h]
  int v39; // [sp+70h] [-F0h]
  int v40; // [sp+78h] [-E8h]
  int v41; // [sp+80h] [-E0h]
  int v42; // [sp+88h] [-D8h]
  __int16 v43; // [sp+90h] [-D0h] BYREF
  __int16 v44; // [sp+92h] [-CEh] BYREF
  __int16 v45; // [sp+94h] [-CCh] BYREF
  __int16 v46; // [sp+96h] [-CAh] BYREF
  int v47; // [sp+98h] [-C8h] BYREF
  float v48[4]; // [sp+A0h] [-C0h] BYREF
  idVec3 v49; // [sp+B0h] [-B0h] BYREF
  _BYTE v50[16]; // [sp+C0h] [-A0h] BYREF
  idAIMoveParms v51; // [sp+D0h] [-90h] BYREF

  ai->aiVolatile.memory.lastMoveFailedTime = curTime;
  p_memory = &ai->aiVolatile.memory;
  v8 = CheckMove(ai, fsm: nullptr, curTime: &v49.x, stayNearCover: curTime, outPos: a5);
  ai->aiVolatile.memory.transCode = 0;
  if ( v8 != 0 )
  {
    idAIMoveParms::idAIMoveParms(this: &v51);
    v9 = 14;
    if ( (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 0x20) != 0 )
      v9 = 30;
    Physics = idEntity::GetPhysics(this: ai);
    v46 = -1;
    v45 = -1;
    v44 = -1;
    v43 = -1;
    v11 = Physics->GetOrigin(this: Physics, a2: 0);
    idAIMoveParms::Init(
      this: &v51,
      moveReason_: AIMOVEREASON_TEST,
      startOrigin_: v11,
      goalOrigin_: &v49,
      goalEntity_: nullptr,
      goalOrientation_: &quat_identity,
      goalScenePoint_: nullptr,
      goalTolerance_: 0.1,
      intermediateTolerance_: 0.1,
      arrivalAction_: (const aiArrivalAction_t)&v44,
      arrivalPosture_: v16,
      flags_: v17,
      sourceSubWeb_: v18,
      sourceState_: v19,
      destSubWeb_: v20,
      destState_: v21,
      a17: v22,
      a18: v23,
      a19: v24,
      a20: v25,
      a21: v26,
      a22: v27,
      a23: v28,
      a24: v29,
      a25: v30,
      a26: v31,
      a27: v32,
      a28: v33,
      a29: v34,
      a30: v35,
      a31: v36,
      a32: AIARRIVAL_STOP,
      a33: v37,
      a34: POSTURE_STANDING,
      a35: v38,
      a36: v9,
      a37: v39,
      a38: &v43,
      a39: v40,
      arrivalAction__0: &v44,
      a41: v41,
      arrivalPosture_a: &v45,
      a43: v42,
      flags_a: &v46);
    if ( ai->aiVolatile.physics.moveState.TestMove(
           this: &ai->aiVolatile.physics.moveState,
           a2: &v51,
           a3: (idVec3 *)v48,
           a4: (idVec3 *)v50,
           a5: &v47) == AIMOVESTATUS_MOVING )
    {
      p_memory->transCode = v8;
      v12 = clientGame;
      clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
      v13 = v48[0];
      v14 = v48[1];
      v15 = v48[2];
      ai->aiVolatile.memory.nextMoveTime = ((v12->random.seed >> 10) & 0x7FFF) % 0xBB8 + v47 + curTime + 2000;
      ai->aiVolatile.memory.cachedDestination.x = v13;
      ai->aiVolatile.memory.cachedDestination.y = v14;
      ai->aiVolatile.memory.cachedDestination.z = v15;
    }
  }
}


// ========================================================================
// ?Evaluate@OC_RechargeHintGone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE0A18
// RVA : 0x00AE0A18
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_RechargeHintGone::Evaluate(
        OC_RechargeHintGone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idCombatStage *CurrentCombatStage; // r30
  idPhysics *Physics; // r3
  const idVec3 *v8; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v10; // zf
  idVec3 v11[2]; // [sp+50h] [-30h] BYREF

  CurrentCombatStage = idAI2::GetCurrentCombatStage(this: ai);
  if ( CurrentCombatStage == nullptr )
    return 0;
  Physics = idEntity::GetPhysics(this: ai);
  v8 = Physics->GetOrigin(this: Physics, a2: 0);
  v10 = (unsigned __int8)idCombatStage::GetClosestHintNodePos(
                           this: CurrentCombatStage,
                           hintType: 6u,
                           currentPos: v8,
                           outPos: v11,
                           hintClass: CLASS_ALL) == 0;
  result = TRANSCODE_MOVE_FAILED;
  if ( !v10 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_ShouldMoveToRoleHintNode@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE0AA8
// RVA : 0x00AE0AA8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_ShouldMoveToRoleHintNode::Evaluate(
        OC_ShouldMoveToRoleHintNode *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3
  aiSenseState_t *EnemySenseState; // r3
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  float x; // r29
  float y; // r28
  float z; // r27
  idCombatStage *CurrentCombatStage; // r26
  int v13; // r3
  unsigned int v14; // r30
  idPhysics *Physics; // r3
  float *v16; // r3
  idAICombatHint *ClosestHintNodePtr; // r30
  idPhysics *v18; // r3
  const idVec3 *v19; // r3
  idPhysics *v20; // r3
  float *v21; // r3
  idAICombatHint::combatHintClass_t hintClass; // r11
  int v24; // [sp+50h] [-50h] BYREF
  idVec3 v25; // [sp+58h] [-48h] BYREF

  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v24 = 5000;
  if ( MoveInterface->RecentlyFailedMove(
         this: MoveInterface,
         a2: AIMOVEREASON_OC_MOVE_TO_ROLE_HINT_NODE,
         a3: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&v24) )
  {
    return 0;
  }
  if ( ai->aiEditable.movement.turretMode )
    return 0;
  if ( idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX) == nullptr )
    return 0;
  EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
  x = ConfirmedPhysicalSafe->origin.x;
  y = ConfirmedPhysicalSafe->origin.y;
  z = ConfirmedPhysicalSafe->origin.z;
  CurrentCombatStage = idAI2::GetCurrentCombatStage(this: ai);
  if ( ai->aiVolatile.groupStatus.currentRole == ROLE_NONE )
    return 0;
  if ( idAI2::GetEncounterGroup(this: ai) == nullptr )
    return 0;
  if ( CurrentCombatStage == nullptr )
    return 0;
  v13 = idCombatStage::RoleToHintType(role: (const encounterGroupRole_t)ai->aiVolatile.groupStatus.currentRole);
  v14 = v13;
  if ( v13 == 8 )
    return 0;
  v25.x = x;
  v25.y = y;
  v25.z = z;
  if ( v13 == 0 )
  {
    Physics = idEntity::GetPhysics(this: ai);
    v16 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v25.x = *v16;
    v25.y = v16[1];
    v25.z = v16[2];
  }
  ClosestHintNodePtr = (idAICombatHint *)idCombatStage::GetClosestHintNodePtr(
                                           this: CurrentCombatStage,
                                           hintType: v14,
                                           currentPos: &v25,
                                           hintClass: (const idAICombatHint::combatHintClass_t)ai->aiEditable.movement.combatHintClass);
  if ( ClosestHintNodePtr == nullptr )
    return 0;
  v18 = idEntity::GetPhysics(this: ai);
  v19 = v18->GetOrigin(this: v18, a2: 0);
  if ( idAICombatHint::GetPointWeight(this: ClosestHintNodePtr, point: v19) != 0.0 )
    return 0;
  v20 = idEntity::GetPhysics(this: ClosestHintNodePtr);
  v21 = (float *)v20->GetOrigin(this: v20, a2: 0);
  ai->aiVolatile.memory.cachedDestination.x = *v21;
  ai->aiVolatile.memory.cachedDestination.y = v21[1];
  ai->aiVolatile.memory.cachedDestination.z = v21[2];
  hintClass = ClosestHintNodePtr->hintClass;
  if ( hintClass != CLASS_ALL )
    ai->aiEditable.movement.combatHintClass = hintClass;
  return 315;
}


// ========================================================================
// ?Evaluate@OC_MoveToRoleHintNodeFailed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE0C80
// RVA : 0x00AE0C80
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_MoveToRoleHintNodeFailed::Evaluate(
        OC_MoveToRoleHintNodeFailed *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idFiniteStateMachine *v7; // r31
  int errorTransCode; // r11
  idAIStateTransition::aiTransCode_t result; // r3
  idAIMoveState *MoveInterface; // r3
  encounterGroupRole_t currentRole; // r31
  const idVec3 *v12; // r29
  idCombatStage *CurrentCombatStage; // r3
  double RolePositionWeight; // fp1

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  v7 = FullPath;
  if ( FullPath != nullptr && (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) != 0 )
  {
    errorTransCode = v7->errorTransCode;
    if ( errorTransCode == 9 || errorTransCode == 10 || errorTransCode == 19 || errorTransCode == 20 )
      return TRANSCODE_MOVE_FAILED;
  }
  if ( idAI2::GetCurrentCombatStage(this: ai) == nullptr )
    return 0;
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  currentRole = ai->aiVolatile.groupStatus.currentRole;
  v12 = MoveInterface->GetFinalPoint(this: MoveInterface);
  CurrentCombatStage = idAI2::GetCurrentCombatStage(this: ai);
  RolePositionWeight = idCombatStage::GetRolePositionWeight(
                         this: CurrentCombatStage,
                         role: currentRole,
                         pos: v12,
                         hintClass: CLASS_ALL);
  result = TRANSCODE_MOVE_FAILED;
  if ( RolePositionWeight != 0.0 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_ShouldMoveTowardEnemy@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE0DB8
// RVA : 0x00AE0DB8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_ShouldMoveTowardEnemy::Evaluate(
        OC_ShouldMoveTowardEnemy *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3
  const idEntity *Enemy; // r30
  idAIMoveState *v9; // r3
  idAI2::idAIVolatile::idAIGroupStatus *p_groupStatus; // r29
  idAIEntityState *v12; // r3
  idAIEntityState *v13; // r30
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  float x; // r7
  float y; // r6
  float z; // r5
  idPhysics *Physics; // r3
  float *v19; // r3
  int v20; // r11
  idArray<enum idAI2::idVisibilityObscurity::obscurity_t,7> *p_visibilityObscurity; // r10
  char v22; // r11
  aiSenseState_t *v23; // r11
  float v24; // [sp+50h] [-C0h] BYREF
  float v25; // [sp+54h] [-BCh] BYREF
  float v26; // [sp+58h] [-B8h] BYREF
  float v27; // [sp+5Ch] [-B4h] BYREF
  idVec3 v28; // [sp+60h] [-B0h] BYREF
  int v29; // [sp+70h] [-A0h] BYREF
  int forwardRunIndex; // [sp+74h] [-9Ch]
  idAIProjectileInfo v31; // [sp+80h] [-90h] BYREF

  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v29 = 1000;
  if ( MoveInterface->RecentlyFailedMove(
         this: MoveInterface,
         a2: AIMOVEREASON_OC_MOVE_TOWARD_ENEMY,
         a3: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&v29) )
  {
    return 0;
  }
  if ( ai->aiEditable.movement.turretMode )
    return 0;
  if ( ai->aiVolatile.memory.enemyPathBlocked )
    return 0;
  Enemy = idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
  if ( Enemy == nullptr )
    return 0;
  v9 = idAI2::GetMoveInterface(this: ai);
  if ( v9->ReachedEntity(this: v9, a2: Enemy, a3: 32.0) )
    return 0;
  forwardRunIndex = (int)ai->aiVolatile.animation.animWebAnimator.ptr[0].forwardRunIndex;
  if ( forwardRunIndex == 1 )
    return 0;
  p_groupStatus = &ai->aiVolatile.groupStatus;
  if ( ai->aiVolatile.groupStatus.currentRole == ROLE_CHARGE )
    return 267;
  if ( (ai->aiVolatile.groupStatus.condition & 8) != 0
    && ai->aiVolatile.death.injuredCount >= ai->aiEditable.behaviors.decl->damageBehaviors.injuredDontMoveCount )
  {
    return 0;
  }
  v12 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: Enemy);
  v13 = v12;
  if ( v12 == nullptr )
    return 0;
  if ( (*((_BYTE *)v12 + 541) & 0x80) == 0 )
    return 0;
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v12->senses.ptr[v12->lastSense]);
  x = ConfirmedPhysicalSafe->origin.x;
  y = ConfirmedPhysicalSafe->origin.y;
  z = ConfirmedPhysicalSafe->origin.z;
  v26 = 0.0;
  v25 = 0.0;
  v24 = 0.0;
  v27 = 0.0;
  v28.x = x;
  v28.y = y;
  v28.z = z;
  idAIProjectileInfo::idAIProjectileInfo(this: &v31);
  if ( (unsigned __int8)idAI2::GetMinMaxRangedAttackDistancesForTargetPos(
                          this: ai,
                          selector: (const aiItemSelect_t)ai->aiEditable.behaviors.decl->itemSelect[1],
                          targetPos: &v28,
                          outProjectileInfo: &v31,
                          outMinRange: &v26,
                          outMinOptimalRange: &v25,
                          outMaxOptimalRange: &v24,
                          outMaxRange: &v27) == 0
    || p_groupStatus->currentRole != ROLE_NONE && p_groupStatus->currentRole != ROLE_THROW )
  {
    return 0;
  }
  Physics = idEntity::GetPhysics(this: ai);
  v19 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  if ( (float)((float)((float)(v19[1] - v28.y) * (float)(v19[1] - v28.y))
             + (float)((float)(*v19 - v28.x) * (float)(*v19 - v28.x))) > (double)(float)(v24 * v24) )
    return 267;
  if ( ai->aiVolatile.visibilityObscurity.valid )
  {
    v20 = 0;
    p_visibilityObscurity = &ai->aiVolatile.visibilityObscurity.visibilityObscurity;
    while ( p_visibilityObscurity->ptr[0] != OBSCURITY_PATH_OPEN_AND_ENEMY_VISIBLE )
    {
      ++v20;
      p_visibilityObscurity = (idArray<enum idAI2::idVisibilityObscurity::obscurity_t,7> *)((char *)p_visibilityObscurity
                                                                                          + 4);
      if ( v20 >= 7 )
      {
        v22 = 0;
        goto LABEL_22;
      }
    }
    v22 = 1;
LABEL_22:
    if ( v22 == 0 )
      return 267;
  }
  v23 = v13->senses.ptr[1];
  if ( v23->lastUnconfirmedStimTime >= 0 && curTime - v23->lastConfirmedStimTime < 5000 )
    return 0;
  else
    return 267;
}


// ========================================================================
// ?Evaluate@OC_EnemyVisible@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE1060
// RVA : 0x00AE1060
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_EnemyVisible::Evaluate(
        OC_EnemyVisible *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r4
  idAIEntityState *v10; // r3
  idAIEntityState *v11; // r31
  idPhysics *Physics; // r3
  float *v13; // r3
  int v14; // r10
  idAIStateTransition::aiTransCode_t result; // r3
  char v16; // [sp+50h] [-30h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v8 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v8 != nullptr )
    {
      v9 = idEntity::CastTo(c: v8);
      if ( v9 != nullptr )
      {
        v10 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v9);
        v11 = v10;
        if ( v10 != nullptr
          && v10->curAwareness == 3
          && idAIEntityState::IsVisible(this: v10)
          && (!ai->aiVolatile.visibilityObscurity.valid
           || ai->aiVolatile.visibilityObscurity.visibilityObscurity.ptr[0] >= OBSCURITY_PATH_OPEN_AND_ENEMY_VISIBLE) )
        {
          Physics = idEntity::GetPhysics(this: ai);
          v13 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v16, result: (idVec3 *)Physics, a3: 0);
          v14 = curTime - v11->visChangeTime;
          if ( (float)((float)(v13[2] * v13[2]) + (float)((float)(*v13 * *v13) + (float)(v13[1] * v13[1]))) <= 1.0 )
          {
            result = TRANSCODE_OC_ENEMY_VISIBLE;
            if ( v14 > 100 )
              return result;
          }
          else if ( v14 > 750 )
          {
            return TRANSCODE_OC_ENEMY_VISIBLE;
          }
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// ?Evaluate@OC_EnemyCloseEnoughAndVisible@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE11A8
// RVA : 0x00AE11A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_EnemyCloseEnoughAndVisible::Evaluate(
        OC_EnemyCloseEnoughAndVisible *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r4
  idAIEntityState *v10; // r3
  idAIEntityState *v11; // r30
  aiSenseState_t *v12; // r31
  const idDeclAIBehavior *decl; // r27
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  idPhysics *Physics; // r27
  const aiPhysicalState_t *v16; // r31
  float *v17; // r3
  double v18; // fp6
  idAIStateTransition::aiTransCode_t result; // r3
  float v20; // [sp+50h] [-B0h] BYREF
  float v21; // [sp+54h] [-ACh] BYREF
  float v22; // [sp+58h] [-A8h] BYREF
  float v23; // [sp+5Ch] [-A4h] BYREF
  idAIProjectileInfo v24; // [sp+60h] [-A0h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v8 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v8 == nullptr )
    return 0;
  v9 = idEntity::CastTo(c: v8);
  if ( v9 == nullptr )
    return 0;
  v10 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v9);
  v11 = v10;
  if ( v10 == nullptr )
    return 0;
  v12 = v10->senses.ptr[v10->lastSense];
  if ( curTime - v12->lastConfirmedStimTime >= 1000 )
    return 0;
  v22 = 0.0;
  v20 = 0.0;
  v21 = 0.0;
  v23 = 0.0;
  idAIProjectileInfo::idAIProjectileInfo(this: &v24);
  decl = ai->aiEditable.behaviors.decl;
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v12);
  if ( (unsigned __int8)idAI2::GetMinMaxRangedAttackDistancesForTargetPos(
                          this: ai,
                          selector: (const aiItemSelect_t)decl->itemSelect[1],
                          targetPos: &ConfirmedPhysicalSafe->origin,
                          outProjectileInfo: &v24,
                          outMinRange: &v22,
                          outMinOptimalRange: &v20,
                          outMaxOptimalRange: &v21,
                          outMaxRange: &v23) == 0 )
    return 0;
  Physics = idEntity::GetPhysics(this: ai);
  v16 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v12);
  v17 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v18 = (float)(v17[1] - v16->origin.y);
  if ( (float)((float)((float)v18 * (float)v18) + (float)((float)(*v17 - v16->origin.x) * (float)(*v17 - v16->origin.x))) > (double)(float)((float)((float)(v21 + v20) * (float)0.5) * (float)((float)(v21 + v20) * (float)0.5))
    || (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 2) != 0
    && ai->aiVolatile.visibilityObscurity.valid
    && ai->aiVolatile.visibilityObscurity.visibilityObscurity.ptr[0] < OBSCURITY_PATH_OPEN_AND_ENEMY_VISIBLE )
  {
    return 0;
  }
  if ( v11->curAwareness != 3 )
    return 0;
  if ( !idAIEntityState::IsVisible(this: v11) )
    return 0;
  result = TRANSCODE_OC_ENEMY_VISIBLE;
  if ( curTime - v11->visChangeTime <= 750 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_EnemyNotVisible@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE1390
// RVA : 0x00AE1390
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_EnemyNotVisible::Evaluate(
        OC_EnemyNotVisible *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r4
  idAIEntityState *v10; // r3
  idAIEntityState *v11; // r31
  idPhysics *Physics; // r3
  float *v13; // r3
  int v14; // r10
  idAIStateTransition::aiTransCode_t result; // r3
  char v16; // [sp+50h] [-30h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v8 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v8 == nullptr )
    return 0;
  v9 = idEntity::CastTo(c: v8);
  if ( v9 == nullptr )
    return 0;
  if ( ai->aiEditable.movement.turretMode )
    return 0;
  v10 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v9);
  v11 = v10;
  if ( v10 == nullptr )
    return 0;
  if ( v10->curAwareness != 3 || !idAIEntityState::IsVisible(this: v10) )
  {
    Physics = idEntity::GetPhysics(this: ai);
    v13 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v16, result: (idVec3 *)Physics, a3: 0);
    v14 = curTime - v11->visChangeTime;
    if ( (float)((float)(v13[2] * v13[2]) + (float)((float)(*v13 * *v13) + (float)(v13[1] * v13[1]))) <= 1.0 )
    {
      if ( v14 > 1000 )
        return TRANSCODE_OC_ENEMY_NOT_VISIBLE;
    }
    else if ( v14 > 750 )
    {
      return TRANSCODE_OC_ENEMY_NOT_VISIBLE;
    }
  }
  if ( ai->GetEquippedWeapon(this: ai) == nullptr )
    return 0;
  if ( BYTE2(ai->GetEquippedWeapon(this: ai)->decl[1].thirdPersonMD6) == 0 )
    return 0;
  if ( !ai->aiVolatile.visibilityObscurity.valid )
    return 0;
  result = TRANSCODE_OC_ENEMY_NOT_VISIBLE;
  if ( ai->aiVolatile.visibilityObscurity.visibilityObscurity.ptr[0] >= OBSCURITY_PATH_OPEN_AND_ENEMY_VISIBLE )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_ShouldThrowProjectile@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE1530
// RVA : 0x00AE1530
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_ShouldThrowProjectile::Evaluate(
        OC_ShouldThrowProjectile *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  const idDeclAIBehavior *decl; // r27
  aiItemSelect_t v8; // r11
  const idEntity *Enemy; // r3
  idActor *v10; // r30
  idAIEntityState *v11; // r29
  aiItemSelect_t v12; // r11
  aiSenseState_t *v13; // r29
  idPhysics *Physics; // r3
  float *v15; // r30
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  double v17; // fp0
  double v18; // fp6
  idPresentable *presentable; // r11
  unsigned int v20; // r30
  idAICombatHint::combatHintClass_t combatHintClass; // r28
  idPhysics *v22; // r3
  const idVec3 *v23; // r27
  idCombatStage *CurrentCombatStage; // r3
  idAICombatHint *ClosestHintNodePtr; // r30
  idPhysics *v26; // r3
  const idVec3 *v27; // r3
  idVec3 *v28; // r4
  aiSenseState_t *EnemySenseState; // r3
  idPhysics *v30; // r31
  const aiPhysicalState_t *v31; // r30
  float *v32; // r3
  double v33; // fp7
  double v34; // fp0
  idAIStateTransition::aiTransCode_t result; // r3
  idVec3 v36; // [sp+50h] [-D0h] BYREF
  float v37; // [sp+5Ch] [-C4h] BYREF
  float v38; // [sp+60h] [-C0h] BYREF
  float v39; // [sp+64h] [-BCh] BYREF
  float v40[2]; // [sp+68h] [-B8h] BYREF
  idVec3 v41; // [sp+70h] [-B0h] BYREF
  idAIProjectileInfo v42; // [sp+80h] [-A0h] BYREF

  decl = ai->aiEditable.behaviors.decl;
  v8 = decl->itemSelect[1];
  if ( v8 == AIITEMSELECT_NONE
    || ai->aiVolatile.groupStatus.pendingRole == ROLE_CHARGE && v8 != AIITEMSELECT_HEAVY_BANDIT )
  {
    return 0;
  }
  if ( curTime < ai->aiVolatile.memory.nextThrowTime )
    return 0;
  if ( ai->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType == ANIMWEBAI_RUNINDEXTYPE_DUCK )
    return 0;
  Enemy = idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
  v10 = (idActor *)Enemy;
  if ( Enemy == nullptr )
    return 0;
  v11 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: Enemy);
  if ( v11 == nullptr )
    return 0;
  v12 = decl->itemSelect[1];
  if ( v12 != AIITEMSELECT_LARGE_RANGED_MUTANT
    && v12 != AIITEMSELECT_SCOOP_MUTANT
    && idActor::CastTo(c: v10) == nullptr
    && idVehicle::CastTo(c: (idVehicle *)v10) == nullptr )
  {
    return 0;
  }
  v13 = v11->senses.ptr[1];
  if ( v13->lastUnconfirmedStimTime < 0 || curTime - v13->lastConfirmedStimTime >= 1000 )
    return 0;
  Physics = idEntity::GetPhysics(this: ai);
  v15 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v13);
  v17 = v15[2];
  v18 = (float)(ConfirmedPhysicalSafe->origin.y - v15[1]);
  v36.x = ConfirmedPhysicalSafe->origin.x - *v15;
  v36.y = v18;
  v36.z = ConfirmedPhysicalSafe->origin.z - (float)v17;
  idVec3::NormalizeFast(this: &v36);
  presentable = ai->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: ai);
    presentable = ai->presentable;
  }
  if ( (float)((float)(presentable->axis.mat[0].x * v36.x)
             + (float)((float)(presentable->axis.mat[0].y * v36.y) + (float)(presentable->axis.mat[0].z * v36.z))) < (double)decl->minThrowDot )
    return 0;
  if ( !ai->aiEditable.movement.canThrowOutsideHintNode )
  {
    v20 = idCombatStage::RoleToHintType(role: (const encounterGroupRole_t)ai->aiVolatile.groupStatus.currentRole);
    if ( v20 != 8 && idAI2::GetCurrentCombatStage(this: ai) != nullptr )
    {
      combatHintClass = ai->aiEditable.movement.combatHintClass;
      v22 = idEntity::GetPhysics(this: ai);
      v23 = v22->GetOrigin(this: v22, a2: 0);
      CurrentCombatStage = idAI2::GetCurrentCombatStage(this: ai);
      ClosestHintNodePtr = (idAICombatHint *)idCombatStage::GetClosestHintNodePtr(
                                               this: CurrentCombatStage,
                                               hintType: v20,
                                               currentPos: v23,
                                               hintClass: combatHintClass);
      if ( ClosestHintNodePtr != nullptr )
      {
        v26 = idEntity::GetPhysics(this: ai);
        v27 = v26->GetOrigin(this: v26, a2: 0);
        if ( idAICombatHint::GetPointWeight(this: ClosestHintNodePtr, point: v27) == 0.0 )
          return 0;
      }
    }
  }
  EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  if ( EnemySenseState == nullptr )
    return 0;
  aiSenseState_t::ExtrapolatePosition(this: EnemySenseState, seconds: 1.0, futurePos: v28);
  v38 = 0.0;
  v39 = 0.0;
  v40[0] = 0.0;
  v37 = 0.0;
  idAIProjectileInfo::idAIProjectileInfo(this: &v42);
  if ( (unsigned __int8)idAI2::GetMinMaxRangedAttackDistancesForTargetPos(
                          this: ai,
                          selector: (const aiItemSelect_t)ai->aiEditable.behaviors.decl->itemSelect[1],
                          targetPos: &v41,
                          outProjectileInfo: &v42,
                          outMinRange: &v38,
                          outMinOptimalRange: &v39,
                          outMaxOptimalRange: v40,
                          outMaxRange: &v37) == 0 )
    return 0;
  v30 = idEntity::GetPhysics(this: ai);
  v31 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v13);
  v32 = (float *)v30->GetOrigin(this: v30, a2: 0);
  v33 = (float)(v32[1] - v31->origin.y);
  v34 = (float)((float)((float)v33 * (float)v33) + (float)((float)(*v32 - v31->origin.x) * (float)(*v32 - v31->origin.x)));
  if ( v34 < (float)(v38 * v38) )
    return 0;
  result = TRANSCODE_OC_SHOULD_THROW_PROJECTILE;
  if ( v34 > (float)(v37 * v37) )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_ShouldShoot@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE1890
// RVA : 0x00AE1890
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_ShouldShoot::Evaluate(
        OC_ShouldShoot *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r4
  idAIEntityState *v10; // r3
  aiSenseState_t *v11; // r29
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  float y; // r9
  float z; // r8
  idPhysics *Physics; // r3
  float *v16; // r3
  double v17; // fp7
  double v18; // fp6
  double v19; // fp1
  idPresentable *presentable; // r11
  int v21; // r30
  idPhysics *v22; // r28
  const aiPhysicalState_t *v23; // r29
  float *v24; // r3
  int v25; // r11
  double v26; // fp9
  double v27; // fp0
  idVec3 v29; // [sp+50h] [-50h] BYREF
  float x; // [sp+60h] [-40h]
  float v31; // [sp+64h] [-3Ch]
  float v32; // [sp+68h] [-38h]

  if ( (*((_BYTE *)ai->aiEditable.behaviors.decl + 197) & 0x20) == 0 )
    return 0;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v8 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v8 == nullptr )
    return 0;
  v9 = idEntity::CastTo(c: v8);
  if ( v9 == nullptr )
    return 0;
  v10 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v9);
  if ( v10 == nullptr )
    return 0;
  v11 = v10->senses.ptr[v10->lastSense];
  if ( curTime - v11->lastConfirmedStimTime >= 1000
    || ai->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType == ANIMWEBAI_RUNINDEXTYPE_DUCK )
  {
    return 0;
  }
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v11);
  y = ConfirmedPhysicalSafe->origin.y;
  z = ConfirmedPhysicalSafe->origin.z;
  x = ConfirmedPhysicalSafe->origin.x;
  v31 = y;
  v32 = z;
  Physics = idEntity::GetPhysics(this: ai);
  v16 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v17 = (float)(v31 - v16[1]);
  v18 = (float)(v32 - v16[2]);
  v29.x = x - *v16;
  v29.y = v17;
  v29.z = v18;
  v19 = idVec3::NormalizeFast(this: &v29);
  presentable = ai->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: ai);
    presentable = ai->presentable;
  }
  if ( (float)((float)(presentable->axis.mat[0].x * v29.x)
             + (float)((float)(presentable->axis.mat[0].z * v29.z) + (float)(presentable->axis.mat[0].y * v29.y))) >= 0.70700002
    && (v21 = ((int (__fastcall *)(idAI2 *, double))ai->GetEquippedWeapon)(a1: ai, a2: v19)) != 0
    && (v22 = idEntity::GetPhysics(this: ai),
        v23 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v11),
        v24 = (float *)v22->GetOrigin(this: v22, a2: 0),
        v25 = *(_DWORD *)(v21 + 12),
        v26 = (float)(v24[1] - v23->origin.y),
        (v27 = (float)((float)((float)v26 * (float)v26)
                     + (float)((float)(*v24 - v23->origin.x) * (float)(*v24 - v23->origin.x)))) >= (float)(*(float *)(v25 + 588) * *(float *)(v25 + 588)))
    && v27 <= (float)(*(float *)(v25 + 576) * *(float *)(v25 + 576))
    && (!ai->aiVolatile.visibilityObscurity.valid
     || ai->aiVolatile.visibilityObscurity.visibilityObscurity.ptr[0] >= OBSCURITY_PATH_OPEN_AND_ENEMY_VISIBLE) )
  {
    return 289;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?Evaluate@OC_ReachedCoverExposed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE1AF0
// RVA : 0x00AE1AF0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_ReachedCoverExposed::Evaluate(
        OC_ReachedCoverExposed *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  const idDeclAIBehavior *decl; // r30
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r4
  idAIEntityState *v10; // r3
  idAIStateTransition::aiTransCode_t result; // r3

  decl = ai->aiEditable.behaviors.decl;
  if ( !idAI2::IsMoveDone(this: ai, checkAlignment: false) )
    return 0;
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
  v10 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v9);
  if ( v10 == nullptr )
    return 0;
  if ( !idAIEntityState::IsVisible(this: v10) )
    return 0;
  result = TRANSCODE_OC_REACHED_COVER_EXPOSED;
  if ( (*((_BYTE *)decl + 428) & 1) == 0 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_AttackIdle@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE1BC8
// RVA : 0x00AE1BC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_AttackIdle::Evaluate(
        OC_AttackIdle *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  int value; // r8
  idEntity *v9; // r3
  idEntity *v10; // r4
  idAIEntityState *v11; // r3

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( (FullPath == nullptr || idFiniteStateMachine::GetStatus(this: FullPath) == 0)
    && (value = ai->aiVolatile.memory.currentEnemy.spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
    && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v10 = idEntity::CastTo(c: v9)) != nullptr
    && (v11 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v10)) != nullptr )
  {
    return !idAIEntityState::IsVisible(this: v11) ? 0 : 0x10D;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_MoveTowardEnemy@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE1CA8
// RVA : 0x00AE1CA8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_MoveTowardEnemy::AIState_EnterState(
        idOpenCombat_MoveTowardEnemy *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idEntityPtr<idEntity const > *p_currentEnemy; // r30
  int value; // r9
  idEntity *v10; // r3
  idEntity *v11; // r3
  const idEntity *v12; // r25
  idAIEntityState *v13; // r3
  aiSenseState_t *v14; // r28
  int v15; // r11
  int v16; // r3
  const idDeclAIBehavior *decl; // r30
  idEntity *v18; // r3
  idEntity *v19; // r4
  idPhysics *Physics; // r30
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r29
  float *v22; // r3
  double v23; // fp10
  double v24; // fp8
  double v25; // fp3
  double v27; // fp1
  double v29; // fp12
  double v30; // fp10
  idWeapon *v32; // r3
  const idDeclInventory *v33; // r11
  int GameMs; // r3
  walkState_t DesiredWalkStateForDistance; // r29
  idEventArg *v37; // r3
  idEventArg *v38; // r20
  idEventArg *v39; // r19
  const idEventArg *v40; // [sp+8h] [-2C8h]
  const idEventArg *v41; // [sp+Ch] [-2C4h]
  const idEventArg *v42; // [sp+10h] [-2C0h]
  _BYTE v43[20]; // [sp+70h] [-260h] BYREF
  _BYTE v44[20]; // [sp+90h] [-240h] BYREF
  _BYTE v45[20]; // [sp+B0h] [-220h] BYREF
  _BYTE v46[20]; // [sp+D0h] [-200h] BYREF
  _BYTE v47[20]; // [sp+F0h] [-1E0h] BYREF
  _BYTE v48[20]; // [sp+110h] [-1C0h] BYREF
  float v49[5]; // [sp+130h] [-1A0h] BYREF
  idEventReceiver v50[2]; // [sp+150h] [-180h] BYREF
  idEventArg v51; // [sp+170h] [-160h] BYREF
  _DWORD v52[5]; // [sp+190h] [-140h] BYREF
  _DWORD v53[5]; // [sp+1B0h] [-120h] BYREF
  float v54[5]; // [sp+1D0h] [-100h] BYREF
  idEventArg v55; // [sp+1F0h] [-E0h] BYREF
  idEventArg v56; // [sp+210h] [-C0h] BYREF
  idEventReceiver v57[2]; // [sp+230h] [-A0h] BYREF

  p_currentEnemy = &ai->aiVolatile.memory.currentEnemy;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v10 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v10 != nullptr )
    {
      v11 = idEntity::CastTo(c: v10);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v13 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v11);
        if ( v13 != nullptr )
        {
          v14 = v13->senses.ptr[v13->lastSense];
          ai->SetWeaponReadyState(this: ai, a2: WEAPONREADY_RAISED);
          idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
          ai->aiVolatile.fireControl->allowReloads = true;
          ai->aiVolatile.focus.enableBodyRotation = true;
          idAI2::SetEnableHeadTracking(this: ai, enable: true);
          v15 = p_currentEnemy->spawnId.value & 0x1FFF;
          v16 = p_currentEnemy->spawnId.value >> 13;
          decl = ai->aiEditable.behaviors.decl;
          if ( gameLocal->spawnIds.ptr[v15] == v16 && (v18 = gameLocal->entities.ptr[v15]) != nullptr )
            v19 = idEntity::CastTo(c: v18);
          else
            v19 = nullptr;
          idAI2::SetAimFocusEntity(
            this: ai,
            ent: v19,
            keepFocusInView: (*((_BYTE *)&decl->movementBehaviors + 40) & 4) != 0,
            aimPoint: AIMPOINT_BEST,
            timeout: -1);
          Physics = idEntity::GetPhysics(this: ai);
          ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v14);
          v22 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
          v23 = (float)(v22[2] - ConfirmedPhysicalSafe->origin.z);
          v24 = (float)(v22[1] - ConfirmedPhysicalSafe->origin.y);
          v25 = (float)((float)((float)(*v22 - ConfirmedPhysicalSafe->origin.x)
                              * (float)(*v22 - ConfirmedPhysicalSafe->origin.x))
                      + (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23)));
          _FP2 = (float)((float)((float)((float)(*v22 - ConfirmedPhysicalSafe->origin.x)
                                       * (float)(*v22 - ConfirmedPhysicalSafe->origin.x))
                               + (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          v27 = (float)((float)((float)((float)(*v22 - ConfirmedPhysicalSafe->origin.x)
                                      * (float)(*v22 - ConfirmedPhysicalSafe->origin.x))
                              + (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23)))
                      * (float)0.5);
          __asm { fsel      f13, f2, f3, f13 }
          v29 = __frsqrte(_FP13);
          v30 = (float)((float)v29
                      * (float)((float)((float)((float)(*v22 - ConfirmedPhysicalSafe->origin.x)
                                              * (float)(*v22 - ConfirmedPhysicalSafe->origin.x))
                                      + (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23)))
                              * (float)0.5));
          _FP31 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v30 * (float)v29) - (float)1.5) * (float)v29) * (float)v27)
                                                                                                * (float)((float)-(float)((float)((float)v30 * (float)v29) - (float)1.5) * (float)v29))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)v30 * (float)v29)
                                                                                                - (float)1.5)
                                                                                * (float)v29))
                                                                * (float)v27)
                                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v30 * (float)v29) - (float)1.5) * (float)v29)
                                                                                                * (float)v27)
                                                                                        * (float)((float)-(float)((float)((float)v30 * (float)v29) - (float)1.5)
                                                                                                * (float)v29))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)v30 * (float)v29)
                                                                                        - (float)1.5)
                                                                        * (float)v29)))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v30 * (float)v29)
                                                                                                - (float)1.5)
                                                                                * (float)v29)
                                                                        * (float)v27)
                                                                * (float)((float)-(float)((float)((float)v30 * (float)v29)
                                                                                        - (float)1.5)
                                                                        * (float)v29))
                                                        - (float)1.5)
                                        * (float)((float)-(float)((float)((float)v30 * (float)v29) - (float)1.5)
                                                * (float)v29)))
                        * (float)v25);
          v32 = ai->GetEquippedWeapon(this: ai);
          if ( v32 != nullptr )
          {
            v33 = v32->decl;
            if ( v33 != nullptr )
            {
              _FP10 = -(float)-(float)((float)((float)(*(float *)&v33[1].inventoryClass.baseBuffer[4]
                                                     + *(float *)v33[1].inventoryClass.baseBuffer)
                                             * (float)0.5)
                                     - (float)_FP31);
              __asm { fsel      f31, f10, f0, f11 }
            }
          }
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          DesiredWalkStateForDistance = idAI2::GetDesiredWalkStateForDistance(
                                          this: ai,
                                          distance: _FP31,
                                          maxWalkState: (const walkState_t)(GameMs - ai->aiVolatile.memory.lastFiredAtTime - 2000),
                                          firedAt: WALKSTATE_SPRINTING,
                                          a5: ((GameMs - ai->aiVolatile.memory.lastFiredAtTime >= 0)
                                         + ((unsigned int)(GameMs - ai->aiVolatile.memory.lastFiredAtTime) >= 0x7D0))
                                        & 1);
          ai->SetWalkState(this: ai, a2: DesiredWalkStateForDistance);
          if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED && DesiredWalkStateForDistance >= WALKSTATE_RUNNING )
          {
            if ( ai_useTransitions.valueInteger != 0 && ai_useStartTransitions.valueInteger != 0 )
            {
              ai->SetPosture(this: ai, a2: POSTURE_STANDING);
            }
            else
            {
              v37 = idEventArg::idEventArg(this: &v51, data: ai);
              idEventReceiver::ProcessEvent(
                this: v50,
                result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
                ev: *(const idEventDef **)&v37->type,
                arg1: (const idEventArg *)LODWORD(v37->value.v[1]));
            }
          }
          v53[1] = 0;
          v52[1] = 0;
          v51.value.i = 1;
          v49[1] = vec3_origin.x;
          HIBYTE(v53[0]) = 105;
          v49[2] = vec3_origin.y;
          v49[3] = vec3_origin.z;
          HIBYTE(v49[0]) = 118;
          v54[1] = 32.0;
          HIBYTE(v52[0]) = 105;
          HIBYTE(v54[0]) = 102;
          HIBYTE(v50[0].__vftable) = 105;
          v50[0].listenerList = (idList<idEventReceiver *,5> *)2;
          v51.type = 105;
          v38 = idEventArg::idEventArg(this: &v55, data: v12);
          v39 = idEventArg::idEventArg(this: &v56, data: ai);
          memcpy(Dst: v48, Src: v53, Size: sizeof(v48));
          memcpy(Dst: v47, Src: v49, Size: sizeof(v47));
          memcpy(Dst: v46, Src: v52, Size: sizeof(v46));
          memcpy(Dst: v45, Src: v54, Size: sizeof(v45));
          memcpy(Dst: v44, Src: v50, Size: sizeof(v44));
          memcpy(Dst: v43, Src: v38, Size: sizeof(v43));
          idEventReceiver::ProcessEvent(
            this: v57,
            result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
            ev: *(const idEventDef **)&v39->type,
            arg1: (const idEventArg *)LODWORD(v39->value.v[1]),
            arg2: (const idEventArg *)LODWORD(v39->value.v[2]),
            arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v51.type, 32),
            arg4: (const idEventArg *)LODWORD(v51.value.v[1]),
            arg5: (const idEventArg *)LODWORD(v51.value.v[2]),
            arg6: v40,
            arg7: v41,
            arg8: v42);
          idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
        }
      }
    }
  }
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_MoveToSightEnemy@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE2168
// RVA : 0x00AE2168
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_MoveToSightEnemy::AIState_EnterState(
        idOpenCombat_MoveToSightEnemy *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idEntityPtr<idEntity const > *p_currentEnemy; // r29
  int value; // r9
  idEntity *v9; // r3
  idEntity *v10; // r26
  int v11; // r11
  int v12; // r7
  const idDeclAIBehavior *decl; // r29
  idEntity *v14; // r3
  idEntity *v15; // r4
  idPhysics *Physics; // r3
  idVec3 *p_cachedDestination; // r29
  float *v18; // r3
  double v19; // fp10
  double v20; // fp8
  double v21; // fp3
  double v23; // fp1
  double v25; // fp12
  double v26; // fp10
  walkState_t DesiredWalkStateForDistance; // r3
  idPhysics *v28; // r3
  float *v29; // r28
  idPhysics *v30; // r3
  float *v31; // r3
  double v32; // fp31
  double v33; // fp30
  double v34; // fp29
  double x; // fp8
  double y; // fp7
  double z; // fp6
  idEventArg *v38; // r29
  const idEventArg *v39; // [sp+8h] [-268h]
  const idEventArg *v40; // [sp+Ch] [-264h]
  _BYTE v41[20]; // [sp+70h] [-200h] BYREF
  _BYTE v42[20]; // [sp+90h] [-1E0h] BYREF
  _BYTE v43[20]; // [sp+B0h] [-1C0h] BYREF
  _BYTE v44[20]; // [sp+D0h] [-1A0h] BYREF
  _BYTE v45[20]; // [sp+F0h] [-180h] BYREF
  float v46[5]; // [sp+110h] [-160h] BYREF
  float v47[5]; // [sp+130h] [-140h] BYREF
  float v48[5]; // [sp+150h] [-120h] BYREF
  int v49; // [sp+170h] [-100h]
  int v50; // [sp+174h] [-FCh]
  const idEventArg *v51; // [sp+178h] [-F8h]
  const idEventArg *v52; // [sp+17Ch] [-F4h]
  _DWORD v53[5]; // [sp+190h] [-E0h] BYREF
  _DWORD v54[5]; // [sp+1B0h] [-C0h] BYREF
  idEventArg v55; // [sp+1D0h] [-A0h] BYREF
  idEventReceiver v56[2]; // [sp+1F0h] [-80h] BYREF

  p_currentEnemy = &ai->aiVolatile.memory.currentEnemy;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v9 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v9 != nullptr )
    {
      v10 = idEntity::CastTo(c: v9);
      if ( v10 != nullptr )
      {
        ai->SetWeaponReadyState(this: ai, a2: WEAPONREADY_RAISED);
        idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
        ai->aiVolatile.fireControl->allowReloads = true;
        ai->aiVolatile.focus.enableBodyRotation = true;
        idAI2::SetEnableHeadTracking(this: ai, enable: true);
        v11 = p_currentEnemy->spawnId.value & 0x1FFF;
        v12 = p_currentEnemy->spawnId.value >> 13;
        decl = ai->aiEditable.behaviors.decl;
        if ( gameLocal->spawnIds.ptr[v11] == v12 && (v14 = gameLocal->entities.ptr[v11]) != nullptr )
          v15 = idEntity::CastTo(c: v14);
        else
          v15 = nullptr;
        idAI2::SetAimFocusEntity(
          this: ai,
          ent: v15,
          keepFocusInView: (*((_BYTE *)&decl->movementBehaviors + 40) & 4) != 0,
          aimPoint: AIMPOINT_BEST,
          timeout: -1);
        Physics = idEntity::GetPhysics(this: ai);
        p_cachedDestination = &ai->aiVolatile.memory.cachedDestination;
        v18 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v19 = (float)(v18[2] - ai->aiVolatile.memory.cachedDestination.z);
        v20 = (float)(v18[1] - ai->aiVolatile.memory.cachedDestination.y);
        v21 = (float)((float)((float)(*v18 - p_cachedDestination->x) * (float)(*v18 - p_cachedDestination->x))
                    + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)));
        _FP2 = (float)((float)((float)((float)(*v18 - p_cachedDestination->x) * (float)(*v18 - p_cachedDestination->x))
                             + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        v23 = (float)((float)((float)((float)(*v18 - p_cachedDestination->x) * (float)(*v18 - p_cachedDestination->x))
                            + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)))
                    * (float)0.5);
        __asm { fsel      f13, f2, f3, f13 }
        v25 = __frsqrte(_FP13);
        v26 = (float)((float)v25
                    * (float)((float)((float)((float)(*v18 - p_cachedDestination->x)
                                            * (float)(*v18 - p_cachedDestination->x))
                                    + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)))
                            * (float)0.5));
        DesiredWalkStateForDistance = idAI2::GetDesiredWalkStateForDistance(
                                        this: ai,
                                        distance: (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v26 * (float)v25) - (float)1.5) * (float)v25) * (float)v23) * (float)((float)-(float)((float)((float)v26 * (float)v25) - (float)1.5) * (float)v25)) - (float)1.5)
                                                                                              * (float)((float)-(float)((float)((float)v26 * (float)v25) - (float)1.5) * (float)v25))
                                                                                      * (float)v23)
                                                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v26 * (float)v25) - (float)1.5) * (float)v25) * (float)v23) * (float)((float)-(float)((float)((float)v26 * (float)v25) - (float)1.5) * (float)v25)) - (float)1.5)
                                                                                      * (float)((float)-(float)((float)((float)v26 * (float)v25) - (float)1.5)
                                                                                              * (float)v25)))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v26 * (float)v25) - (float)1.5) * (float)v25)
                                                                                              * (float)v23)
                                                                                      * (float)((float)-(float)((float)((float)v26 * (float)v25) - (float)1.5)
                                                                                              * (float)v25))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)v26 * (float)v25)
                                                                                      - (float)1.5)
                                                                      * (float)v25)))
                                              * (float)v21),
                                        maxWalkState: (const walkState_t)0x82000000,
                                        firedAt: WALKSTATE_SPRINTING,
                                        a5: 0);
        ai->SetWalkState(this: ai, a2: DesiredWalkStateForDistance);
        v28 = idEntity::GetPhysics(this: ai);
        v29 = (float *)v28->GetOrigin(this: v28, a2: 0);
        v30 = idEntity::GetPhysics(this: v10);
        v31 = (float *)v30->GetOrigin(this: v30, a2: 0);
        v32 = (float)(*v31 - *v29);
        v33 = (float)(v31[1] - v29[1]);
        v34 = (float)(v31[2] - v29[2]);
        idAI2::EndActionScript(this: ai);
        LODWORD(fsm[1].value.v[2]) = this;
        x = ai->aiVolatile.memory.cachedDestination.x;
        y = ai->aiVolatile.memory.cachedDestination.y;
        z = ai->aiVolatile.memory.cachedDestination.z;
        v53[1] = 1;
        v46[1] = v32;
        v46[2] = v33;
        HIBYTE(v46[0]) = 118;
        v46[3] = v34;
        HIBYTE(v53[0]) = 105;
        v48[1] = 0.1;
        v47[1] = x;
        v47[2] = y;
        HIBYTE(v48[0]) = 102;
        v47[3] = z;
        HIBYTE(v54[0]) = 105;
        v54[1] = 2;
        HIBYTE(v47[0]) = 118;
        HIBYTE(v49) = 105;
        v50 = 2;
        v38 = idEventArg::idEventArg(this: &v55, data: ai);
        memcpy(Dst: v45, Src: v46, Size: sizeof(v45));
        memcpy(Dst: v44, Src: v53, Size: sizeof(v44));
        memcpy(Dst: v43, Src: v48, Size: sizeof(v43));
        memcpy(Dst: v42, Src: v54, Size: sizeof(v42));
        memcpy(Dst: v41, Src: v47, Size: sizeof(v41));
        idEventReceiver::ProcessEvent(
          this: v56,
          result: fsm,
          ev: *(const idEventDef **)&v38->type,
          arg1: (const idEventArg *)LODWORD(v38->value.v[1]),
          arg2: (const idEventArg *)LODWORD(v38->value.v[2]),
          arg3: (const idEventArg *)__ROL4__(v49, 32),
          arg4: v51,
          arg5: v52,
          arg6: v39,
          arg7: v40);
      }
    }
  }
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_StartThrowProjectile@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE24F8
// RVA : 0x00AE24F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_StartThrowProjectile::AIState_EnterState(
        idOpenCombat_StartThrowProjectile *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r3
  const idEntity *v9; // r30
  idAIEntityState *v10; // r11
  aiSenseState_t *v11; // r28
  idAIProjectileInfo v12; // [sp+50h] [-90h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    goto LABEL_6;
  v7 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr
    || (v8 = idEntity::CastTo(c: v7), v9 = v8, v8 == nullptr)
    || (idAI2::SetAimFocusEntity(
          this: ai,
          ent: v8,
          keepFocusInView: (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 4) != 0,
          aimPoint: AIMPOINT_BEST,
          timeout: -1),
        ai->aiVolatile.focus.enableBodyRotation = true,
        (v10 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v9)) == nullptr)
    || (v11 = v10->senses.ptr[1],
        idAIProjectileInfo::idAIProjectileInfo(this: &v12),
        (unsigned __int8)idAI2::LaunchProjectile(
                           this: ai,
                           target: v9,
                           senseState: v11,
                           projectileInfo: &v12,
                           itemSelect: &ai->aiEditable.behaviors.decl->itemSelect[1]) == 0) )
  {
LABEL_6:
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?Evaluate@OC_FireBlocked@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE25E8
// RVA : 0x00AE25E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_FireBlocked::Evaluate(
        OC_FireBlocked *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r4
  idAIEntityState *v9; // r3
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
  if ( ai->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType == ANIMWEBAI_RUNINDEXTYPE_DUCK )
    return 0;
  if ( ai->aiEditable.movement.turretMode )
    return 0;
  v9 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8);
  if ( v9 == nullptr )
    return 0;
  if ( v9->curAwareness != 3 )
    return 0;
  if ( !idAIEntityState::IsVisible(this: v9) )
    return 0;
  if ( !ai->aiVolatile.visibilityObscurity.valid )
    return 0;
  result = TRANSCODE_OC_FIRE_BLOCKED;
  if ( ai->aiVolatile.visibilityObscurity.visibilityObscurity.ptr[0] >= OBSCURITY_PATH_OPEN_AND_ENEMY_VISIBLE )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@OC_ChargeTurret@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE26E0
// RVA : 0x00AE26E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_ChargeTurret::Evaluate(
        OC_ChargeTurret *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3
  idTurret *Enemy; // r3
  const idEntity *v8; // r30
  idAIEntityState *v9; // r3
  idAIEntityState *v10; // r30
  aiSenseState_t *v11; // r30
  idPhysics *Physics; // r3
  float *v13; // r29
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  double v15; // fp7
  double v16; // fp6
  idWeapon *v17; // r3
  idPhysics *v18; // r3
  float *v19; // r29
  const aiPhysicalState_t *v20; // r3
  double v21; // fp31
  double v22; // fp30
  double v23; // fp29
  double v24; // fp1
  double v25; // fp7
  double v26; // fp6
  idPhysics *v27; // r3
  const idVec3 *v28; // r3
  const aiPhysicalState_t *v29; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  double v31; // fp9
  int v32; // [sp+50h] [-60h] BYREF
  idVec3 v33; // [sp+58h] [-58h] BYREF
  float v34[4]; // [sp+68h] [-48h] BYREF

  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v32 = 2500;
  if ( MoveInterface->RecentlyFailedMove(
         this: MoveInterface,
         a2: AIMOVEREASON_OC_CHARGE_MELEE,
         a3: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&v32) )
  {
    return 0;
  }
  if ( idAI2::GetValidMeleeTypes(this: ai, mask: 98) == 0 )
    return 0;
  if ( ai->aiEditable.movement.turretMode )
    return 0;
  Enemy = (idTurret *)idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
  v8 = Enemy;
  if ( Enemy == nullptr )
    return 0;
  if ( idTurret::CastTo(c: Enemy) == nullptr )
    return 0;
  if ( ai->aiVolatile.memory.enemyPathBlocked )
    return 0;
  v9 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8);
  v10 = v9;
  if ( v9 == nullptr )
    return 0;
  if ( v9->curAwareness != 3 )
    return 0;
  if ( !idAIEntityState::IsVisible(this: v9) )
    return 0;
  if ( (ai->aiVolatile.groupStatus.condition & 8) != 0 )
    return 0;
  v11 = v10->senses.ptr[1];
  Physics = idEntity::GetPhysics(this: ai);
  v13 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v11);
  v15 = (float)(ConfirmedPhysicalSafe->origin.y - v13[1]);
  v16 = (float)(ConfirmedPhysicalSafe->origin.z - v13[2]);
  v33.x = ConfirmedPhysicalSafe->origin.x - *v13;
  v33.y = v15;
  v33.z = v16;
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
     - v11->lastConfirmedStimTime >= 5000 )
    return 0;
  v17 = ai->GetEquippedWeapon(this: ai);
  if ( v17 != nullptr && v17->fireState == FIRESTATE_RELOADING )
    return 0;
  v18 = idEntity::GetPhysics(this: ai);
  v19 = (float *)v18->GetOrigin(this: v18, a2: 0);
  v20 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v11);
  v21 = (float)(v20->origin.x - *v19);
  v22 = (float)(v20->origin.y - v19[1]);
  v23 = (float)(v20->origin.z - v19[2]);
  v24 = idVec3::NormalizeFast(this: &v33);
  if ( v24 < 128.0 )
    return 0;
  if ( v24 > 512.0 )
    return 0;
  ai->GetEyePos(this: ai, a2: (idVec3 *)v34);
  v25 = (float)(ai->aiVolatile.focus.foci.ptr[0].curFocusPoint.y - v34[1]);
  v26 = (float)(ai->aiVolatile.focus.foci.ptr[0].curFocusPoint.z - v34[2]);
  v33.x = ai->aiVolatile.focus.foci.ptr[0].curFocusPoint.x - v34[0];
  v33.y = v25;
  v33.z = v26;
  v27 = idEntity::GetPhysics(this: ai);
  v28 = v27->GetGravityNormal(this: v27);
  idVec3::ProjectOntoPlane(this: &v33, normal: v28, overBounce: 1.0);
  if ( (float)((float)(v33.x * (float)v21) + (float)((float)(v33.z * (float)v23) + (float)(v33.y * (float)v22))) < 0.70710677 )
    return 0;
  v29 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v11);
  v31 = (float)((float)(v29->viewfwd.x * (float)v21)
              + (float)((float)(v29->viewfwd.z * (float)v23) + (float)(v29->viewfwd.y * (float)v22)));
  result = TRANSCODE_OC_CHARGE_TURRET;
  if ( v31 < -1.0 )
    return 0;
  return result;
}


// ========================================================================
// ShouldCharge
// EA  : 0x82AE29E8
// RVA : 0x00AE29E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall ShouldCharge(
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime,
        const bool notIfRetreating)
{
  const char *v7; // r4
  idAIMoveState *MoveInterface; // r3
  idTurret *Enemy; // r3
  idPlayer *v10; // r27
  idAIEntityState *v11; // r3
  aiSenseState_t *v12; // r3
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  float y; // r9
  float z; // r8
  idPhysics *Physics; // r3
  float *v17; // r3
  double v18; // fp29
  double v19; // fp31
  double v20; // fp30
  const idDeclAIBehavior *decl; // r30
  double v22; // fp30
  double v23; // fp31
  idActor *v24; // r3
  int v25; // r3
  double v26; // fp29
  const idAI2 *v27; // r3
  bool v28; // zf
  idWeapon *v29; // r3
  _DWORD *v30; // r28
  int chargeChance; // r29
  idActor *v32; // r30
  idVehicle *v33; // r25
  idPlayer *v34; // r3
  idWeapon *v35; // r3
  int v36; // r11
  unsigned int v37; // r3
  double v38; // fp7
  double v39; // fp6
  idPhysics *v40; // r3
  const idVec3 *v41; // r3
  int v43; // [sp+50h] [-90h] BYREF
  idVec3 v44; // [sp+58h] [-88h] BYREF
  idVec3 v45; // [sp+68h] [-78h] BYREF
  float v46[4]; // [sp+78h] [-68h] BYREF

  if ( (_BYTE)state != 0
    && idAI2::GetCurrentCombatStage(this: ai) != nullptr
    && (idAI2::GetCurrentCombatStage(this: ai)->stageType == COMBAT_STAGE_FALLBACK
     || idAI2::GetCurrentCombatStage(this: ai)->stageType == COMBAT_STAGE_RETREAT) )
  {
    v7 = "no charge:in retreat/fallback stage";
    goto LABEL_62;
  }
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v43 = 2500;
  if ( MoveInterface->RecentlyFailedMove(
         this: MoveInterface,
         a2: AIMOVEREASON_OC_CHARGE_MELEE,
         a3: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&v43) )
  {
    v7 = "no charge:move failed recently";
    goto LABEL_62;
  }
  if ( ai->aiEditable.movement.turretMode )
  {
    v7 = "no charge:turret mode";
    goto LABEL_62;
  }
  Enemy = (idTurret *)idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
  v10 = (idPlayer *)Enemy;
  if ( Enemy == nullptr )
  {
    v7 = "no charge:no enemy";
    goto LABEL_62;
  }
  if ( idTurret::CastTo(c: Enemy) != nullptr )
  {
    v7 = "no charge:turret";
    goto LABEL_62;
  }
  if ( ai->aiVolatile.memory.enemyPathBlocked )
  {
    v7 = "no charge:enemy path blocked";
    goto LABEL_62;
  }
  v11 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v10);
  if ( v11 == nullptr || v11->curAwareness != 3 )
  {
    v7 = "no charge:no awareness";
    goto LABEL_62;
  }
  v12 = v11->senses.ptr[1];
  if ( v12->lastUnconfirmedStimTime < 0 )
  {
    v7 = "no charge:invalid sight sense";
    goto LABEL_62;
  }
  if ( (int)parentFSM - v12->lastConfirmedStimTime >= 1000 )
  {
    v7 = "no charge:not freshly confirmed";
    goto LABEL_62;
  }
  if ( (ai->aiVolatile.groupStatus.condition & 8) != 0 )
  {
    v7 = "no charge:injured";
    goto LABEL_62;
  }
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v12);
  y = ConfirmedPhysicalSafe->origin.y;
  z = ConfirmedPhysicalSafe->origin.z;
  v44.x = ConfirmedPhysicalSafe->origin.x;
  v44.y = y;
  v44.z = z;
  Physics = idEntity::GetPhysics(this: ai);
  v17 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v18 = (float)(v44.z - v17[2]);
  v19 = (float)(v44.x - *v17);
  v45.z = v44.z - v17[2];
  v45.x = v19;
  v20 = (float)(v44.y - v17[1]);
  v45.y = v44.y - v17[1];
  idVec3::NormalizeFast(this: &v45);
  decl = ai->aiEditable.behaviors.decl;
  v22 = (float)((float)((float)v19 * (float)v19)
              + (float)((float)((float)v18 * (float)v18) + (float)((float)v20 * (float)v20)));
  v23 = __fsqrts(v22);
  if ( v23 < decl->minChargeDistance )
  {
    v7 = "no charge:too close";
    goto LABEL_62;
  }
  if ( v23 < decl->closeMeleeDist )
  {
    v7 = "no charge:within melee dist";
    goto LABEL_62;
  }
  v24 = idActor::CastTo(c: v10);
  if ( v24 != nullptr )
  {
    v25 = (int)v24->GetHealthComponent(this: v24);
    if ( v25 == 0
      || (float)((float)(v26 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v25 + 80))(a1: v25))
               / ai->aiHealth.GetMaxBaseHealth_Impl(this: &ai->aiHealth)) >= 4.0 )
    {
      v7 = "no charge:enemy too brute";
      goto LABEL_62;
    }
  }
  v28 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= ai->aiVolatile.memory.nextCloseMeleeTime;
  v27 = ai;
  if ( v28 )
  {
    v29 = ai->GetEquippedWeapon(this: ai);
    v30 = &v29->__vftable;
    if ( v29 == nullptr || v29->fireState != FIRESTATE_RELOADING )
    {
      if ( ai->aiVolatile.groupStatus.currentRole != ROLE_CHARGE && (ai->aiVolatile.groupStatus.condition & 0x800) == 0 )
      {
        if ( (int)parentFSM < ai->aiVolatile.memory.nextChargeTime )
        {
          v7 = "no charge:time limited";
          goto LABEL_62;
        }
        if ( v22 > (float)(decl->maxChargeDistance * decl->maxChargeDistance) )
        {
          v7 = "no charge:too far";
          goto LABEL_62;
        }
        chargeChance = decl->chargeChance;
        if ( chargeChance > 0 )
        {
          v32 = idActor::CastTo(c: v10);
          v33 = idVehicle::CastTo(c: (idVehicle *)v10);
          v34 = idPlayer::CastTo(c: v10);
          if ( v33 != nullptr )
          {
            chargeChance = 0;
          }
          else if ( v32 != nullptr
                 && v34 == nullptr
                 && v32->GetEquippedWeapon(this: v32) != nullptr
                 && (v35 = v32->GetEquippedWeapon(this: v32), idWeapon::IsMelee(this: v35)) )
          {
            chargeChance = 0;
          }
          else if ( v30 != nullptr
                 && ((v36 = v30[3]) != 0 && v23 < *(float *)(v36 + 584)
                  || (*(unsigned __int8 (__fastcall **)(_DWORD *, _DWORD))(*v30 + 136))(a1: v30, a2: 0) != 0) )
          {
            chargeChance = 100;
          }
        }
        v37 = 1664525 * clientGame->random.seed + 1013904223;
        clientGame->random.seed = v37;
        if ( (int)(((v37 >> 10) & 0x7FFF) % 0x64) >= chargeChance )
        {
          v7 = "no charge:chance";
          goto LABEL_62;
        }
      }
      ai->GetEyePos(this: ai, a2: (idVec3 *)v46);
      v38 = (float)(ai->aiVolatile.focus.foci.ptr[0].curFocusPoint.y - v46[1]);
      v39 = (float)(ai->aiVolatile.focus.foci.ptr[0].curFocusPoint.z - v46[2]);
      v44.x = ai->aiVolatile.focus.foci.ptr[0].curFocusPoint.x - v46[0];
      v44.y = v38;
      v44.z = v39;
      v40 = idEntity::GetPhysics(this: ai);
      v41 = v40->GetGravityNormal(this: v40);
      idVec3::ProjectOntoPlane(this: &v44, normal: v41, overBounce: 1.0);
      idVec3::NormalizeFast(this: &v44);
      if ( (float)((float)(v44.x * v45.x) + (float)((float)(v45.z * v44.z) + (float)(v45.y * v44.y))) >= -1.0 )
        return TRANSCODE_OC_CHARGE_MELEE;
      v7 = "no charge:facing angle";
      goto LABEL_62;
    }
    v7 = "no charge:reloading";
LABEL_62:
    v27 = ai;
    return ChargeFail(ai: v27, reason: v7);
  }
  v7 = "no charge:melee time limited";
  return ChargeFail(ai: v27, reason: v7);
}


// ========================================================================
// ?Evaluate@OC_ChargeMelee@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE2FD0
// RVA : 0x00AE2FD0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_ChargeMelee::Evaluate(
        OC_ChargeMelee *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        idAIFSM *curTime)
{
  return ShouldCharge(
           ai,
           parentFSM: curTime,
           state: nullptr,
           curTime: (const int)state,
           notIfRetreating: (const bool)curTime);
}


// ========================================================================
// ?Evaluate@OC_ChargeMeleeNotIfRetreating@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE2FE0
// RVA : 0x00AE2FE0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_ChargeMeleeNotIfRetreating::Evaluate(
        OC_ChargeMeleeNotIfRetreating *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        idAIFSM *curTime)
{
  bool v7; // r29
  unsigned int v8; // r30
  bool v9; // r7
  int v10; // r6
  idAICombatHint::combatHintClass_t combatHintClass; // r27
  idPhysics *Physics; // r3
  const idVec3 *v13; // r26
  idCombatStage *CurrentCombatStage; // r3
  idAICombatHint *ClosestHintNodePtr; // r30
  idPhysics *v16; // r3
  const idVec3 *v17; // r3

  v7 = false;
  v8 = idCombatStage::RoleToHintType(role: (const encounterGroupRole_t)ai->aiVolatile.groupStatus.currentRole);
  if ( v8 != 8 && idAI2::GetCurrentCombatStage(this: ai) != nullptr )
  {
    combatHintClass = ai->aiEditable.movement.combatHintClass;
    Physics = idEntity::GetPhysics(this: ai);
    v13 = Physics->GetOrigin(this: Physics, a2: 0);
    CurrentCombatStage = idAI2::GetCurrentCombatStage(this: ai);
    ClosestHintNodePtr = (idAICombatHint *)idCombatStage::GetClosestHintNodePtr(
                                             this: CurrentCombatStage,
                                             hintType: v8,
                                             currentPos: v13,
                                             hintClass: combatHintClass);
    if ( ClosestHintNodePtr != nullptr )
    {
      v16 = idEntity::GetPhysics(this: ai);
      v17 = v16->GetOrigin(this: v16, a2: 0);
      v7 = idAICombatHint::GetPointWeight(this: ClosestHintNodePtr, point: v17) > 0.0;
    }
  }
  return ShouldCharge(
           ai,
           parentFSM: curTime,
           state: (idAIState *)((_cntlzw(v7) & 0x20) != 0),
           curTime: v10,
           notIfRetreating: v9);
}


// ========================================================================
// ?Evaluate@OC_CloseMelee@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE30C8
// RVA : 0x00AE30C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_CloseMelee::Evaluate(
        OC_CloseMelee *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idVehicle *v8; // r3
  idTurret *v9; // r29
  idAIEntityState *v10; // r3
  idAIEntityState *v11; // r31
  aiSenseState_t *v12; // r31
  int v13; // r29
  idVec3 *p_velocity; // r28
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  aiMelee_t MeleeTypeForTarget; // r29
  const aiPhysicalState_t *v17; // r3

  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < ai->aiVolatile.memory.nextCloseMeleeTime )
    return 0;
  if ( !idAI2::CanMelee(this: ai) )
    return 0;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v7 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr )
    return 0;
  v8 = (idVehicle *)idEntity::CastTo(c: v7);
  v9 = (idTurret *)v8;
  if ( v8 == nullptr )
    return 0;
  if ( idVehicle::CastTo(c: v8) != nullptr )
    return 0;
  v10 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v9);
  v11 = v10;
  if ( v10 == nullptr )
    return 0;
  if ( v10->curAwareness != 3 )
    return 0;
  if ( !idAIEntityState::IsVisible(this: v10) )
    return 0;
  if ( (ai->aiVolatile.groupStatus.condition & 8) != 0 )
    return 0;
  v12 = v11->senses.ptr[v11->lastSense];
  v13 = idAI2::MeleePreference(this: ai, target: v9);
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
  return (unsigned __int8)idAI2::IsTargetInMeleeRange(this: ai, targetPos: &v17->origin, meleeType: MeleeTypeForTarget) == 0
       ? 0
       : 0x112;
}


// ========================================================================
// ?Evaluate@OC_EnemyIsDead@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE3260
// RVA : 0x00AE3260
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_EnemyIsDead::Evaluate(
        OC_EnemyIsDead *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v6; // r3
  idEntity *v7; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v9; // zf

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return TRANSCODE_OC_ENEMY_DEAD;
  v6 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v6 == nullptr )
    return TRANSCODE_OC_ENEMY_DEAD;
  v7 = idEntity::CastTo(c: v6);
  if ( v7 == nullptr )
    return TRANSCODE_OC_ENEMY_DEAD;
  v9 = !v7->IsDead(this: v7);
  result = 0;
  if ( !v9 )
    return TRANSCODE_OC_ENEMY_DEAD;
  return result;
}


// ========================================================================
// ?Evaluate@OC_ShouldReloadEnemyOutOfAAS@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE32F0
// RVA : 0x00AE32F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_ShouldReloadEnemyOutOfAAS::Evaluate(
        OC_ShouldReloadEnemyOutOfAAS *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idActor *v8; // r30
  idActor *v9; // r29
  const idAAS2 *v10; // r3
  idAASPosition *AASPosition; // r3
  int AreaNum; // r3
  idPhysics *Physics; // r30
  const idAAS2 *v14; // r28
  idAAS2_vtbl *v15; // r29
  int v16; // r3
  idWeapon *v17; // r3
  idWeapon *v18; // r31
  idAIStateTransition::aiTransCode_t result; // r3
  bool v20; // zf

  if ( ai->GetAAS(this: ai) == nullptr )
    return 0;
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
  if ( v9 != nullptr )
  {
    v10 = ai->GetAAS(this: ai);
    AASPosition = (idAASPosition *)idActor::GetAASPosition(this: v9, aas: v10);
    AreaNum = idAASPosition::GetAreaNum(this: AASPosition);
  }
  else
  {
    Physics = idEntity::GetPhysics(this: v8);
    v14 = ai->GetAAS(this: ai);
    v15 = v14->__vftable;
    v16 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    AreaNum = v15->PointAreaNum(this: (idAAS2 *)v14, a2: nullptr, a3: (const idVec3 *)v16);
  }
  if ( AreaNum > 0 )
    return 0;
  v17 = ai->GetEquippedWeapon(this: ai);
  v18 = v17;
  if ( v17 == nullptr )
    return 0;
  if ( !v17->NeedsReload(this: v17, a2: false) )
    return 0;
  v20 = !idWeapon::IsFullyLoaded(this: v18, secondaryAmmo: false);
  result = TRANSCODE_OC_RELOAD_IN_OPEN;
  if ( !v20 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_AttackIdle@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE3478
// RVA : 0x00AE3478
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_AttackIdle::AIState_EnterState(
        idOpenCombat_AttackIdle *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  unsigned int v7; // r5
  int value; // r9
  idEntity *v9; // r3
  idEntity *v10; // r3
  const idEntity *v11; // r29
  idEventArg *v12; // r28
  _BYTE v13[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v14[5]; // [sp+90h] [-B0h] BYREF
  int v15; // [sp+B0h] [-90h]
  int v16; // [sp+B4h] [-8Ch]
  idEventArg v17; // [sp+D0h] [-70h] BYREF
  idEventReceiver v18[6]; // [sp+F0h] [-50h] BYREF

  ai->aiVolatile.memory.transCode = 0;
  v7 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v7;
  ai->aiVolatile.memory.nextMoveTime = ((v7 >> 10) & 0x7FFF) % 0x3E8 + curTime + 1000;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v9 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v9 != nullptr )
    {
      v10 = idEntity::CastTo(c: v9);
      v11 = v10;
      if ( v10 != nullptr && idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v10) != nullptr )
      {
        idAI2::SetAimFocusEntity(
          this: ai,
          ent: v11,
          keepFocusInView: (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 4) != 0,
          aimPoint: AIMPOINT_BEST,
          timeout: -1);
        ai->aiVolatile.focus.enableBodyRotation = true;
        idAI2::SetEnableHeadTracking(this: ai, enable: true);
        ai->SetWeaponReadyState(this: ai, a2: WEAPONREADY_RAISED);
        idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
        ai->aiVolatile.fireControl->allowReloads = false;
        idAI2::EndActionScript(this: ai);
        LODWORD(fsm[1].value.v[2]) = this;
        v14[1] = 1;
        HIBYTE(v14[0]) = 105;
        HIBYTE(v15) = 105;
        v16 = -1;
        v12 = idEventArg::idEventArg(this: &v17, data: ai);
        memcpy(Dst: v13, Src: v14, Size: sizeof(v13));
        idEventReceiver::ProcessEvent(
          this: v18,
          result: fsm,
          ev: *(const idEventDef **)&v12->type,
          arg1: (const idEventArg *)LODWORD(v12->value.v[1]),
          arg2: (const idEventArg *)LODWORD(v12->value.v[2]),
          arg3: (const idEventArg *)__ROL4__(v15, 32));
      }
    }
  }
}


// ========================================================================
// ?AIState_Work@idOpenCombat_AttackIdle@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE3660
// RVA : 0x00AE3660
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_AttackIdle::AIState_Work(
        idOpenCombat_AttackIdle *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idAIMemory *p_memory; // r28
  int numShotsThisPullBlockedConsecutive; // r7
  int *p_nextMoveTime; // r29
  bool v9; // r27
  idVec3 *v10; // r7
  bool v11; // r6
  idVec3 *v12; // r4
  aiSenseState_t *EnemySenseState; // r3
  idPhysics *Physics; // r3
  float *v15; // r3
  double v18; // fp9
  double v19; // fp1
  double v20; // fp0
  unsigned int v21; // r4
  bool v22; // cr58
  double v23; // fp13
  double v24; // fp12
  float v25; // [sp+50h] [-D0h] BYREF
  float v26; // [sp+54h] [-CCh] BYREF
  float v27; // [sp+58h] [-C8h] BYREF
  float v28; // [sp+5Ch] [-C4h] BYREF
  idVec3 v29; // [sp+60h] [-C0h] BYREF
  float v30[4]; // [sp+70h] [-B0h] BYREF
  idAIProjectileInfo v31; // [sp+80h] [-A0h] BYREF

  p_memory = &ai->aiVolatile.memory;
  numShotsThisPullBlockedConsecutive = (unsigned __int16)ai->aiVolatile.memory.numShotsThisPullBlockedConsecutive;
  ai->aiVolatile.memory.transCode = 0;
  if ( numShotsThisPullBlockedConsecutive != 0 )
    ai->aiVolatile.memory.nextMoveTime = 0;
  p_nextMoveTime = &ai->aiVolatile.memory.nextMoveTime;
  v9 = curTime >= ai->aiVolatile.memory.nextMoveTime;
  EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  if ( EnemySenseState != nullptr && curTime > ai->aiVolatile.memory.lastMoveFailedTime + 1000 )
  {
    aiSenseState_t::ExtrapolatePosition(this: EnemySenseState, seconds: 1.0, futurePos: v12);
    v27 = 0.0;
    v25 = 0.0;
    v26 = 0.0;
    v28 = 0.0;
    idAIProjectileInfo::idAIProjectileInfo(this: &v31);
    if ( (unsigned __int8)idAI2::GetMinMaxRangedAttackDistancesForTargetPos(
                            this: ai,
                            selector: (const aiItemSelect_t)ai->aiEditable.behaviors.decl->itemSelect[1],
                            targetPos: &v29,
                            outProjectileInfo: &v31,
                            outMinRange: &v27,
                            outMinOptimalRange: &v25,
                            outMaxOptimalRange: &v26,
                            outMaxRange: &v28) == 0 )
      return;
    Physics = idEntity::GetPhysics(this: ai);
    v15 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v10 = (idVec3 *)0x82000000;
    _FP1 = (float)((float)((float)((float)(v29.x - *v15) * (float)(v29.x - *v15))
                         + (float)((float)((float)(v29.z - v15[2]) * (float)(v29.z - v15[2]))
                                 + (float)((float)(v29.y - v15[1]) * (float)(v29.y - v15[1]))))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f10, f1, f2, f13 }
    v18 = __frsqrte(_FP10);
    v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18
                                                                                        * (float)((float)((float)((float)(v29.x - *v15) * (float)(v29.x - *v15)) + (float)((float)((float)(v29.z - v15[2]) * (float)(v29.z - v15[2])) + (float)((float)(v29.y - v15[1]) * (float)(v29.y - v15[1]))))
                                                                                                * (float)0.5))
                                                                                * (float)v18)
                                                                        - (float)1.5)
                                                        * (float)v18)
                                                * (float)((float)((float)((float)(v29.x - *v15) * (float)(v29.x - *v15))
                                                                + (float)((float)((float)(v29.z - v15[2])
                                                                                * (float)(v29.z - v15[2]))
                                                                        + (float)((float)(v29.y - v15[1])
                                                                                * (float)(v29.y - v15[1]))))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v18
                                                                                * (float)((float)((float)((float)(v29.x - *v15) * (float)(v29.x - *v15))
                                                                                                + (float)((float)((float)(v29.z - v15[2]) * (float)(v29.z - v15[2])) + (float)((float)(v29.y - v15[1]) * (float)(v29.y - v15[1]))))
                                                                                        * (float)0.5))
                                                                        * (float)v18)
                                                                - (float)1.5)
                                                * (float)v18))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v18
                                                        * (float)((float)((float)((float)(v29.x - *v15)
                                                                                * (float)(v29.x - *v15))
                                                                        + (float)((float)((float)(v29.z - v15[2])
                                                                                        * (float)(v29.z - v15[2]))
                                                                                + (float)((float)(v29.y - v15[1])
                                                                                        * (float)(v29.y - v15[1]))))
                                                                * (float)0.5))
                                                * (float)v18)
                                        - (float)1.5)
                        * (float)v18));
    v20 = (float)((float)((float)-(float)((float)((float)((float)v19
                                                        * (float)((float)((float)((float)(v29.x - *v15)
                                                                                * (float)(v29.x - *v15))
                                                                        + (float)((float)((float)(v29.z - v15[2])
                                                                                        * (float)(v29.z - v15[2]))
                                                                                + (float)((float)(v29.y - v15[1])
                                                                                        * (float)(v29.y - v15[1]))))
                                                                * (float)0.5))
                                                * (float)v19)
                                        - (float)1.5)
                        * (float)v19)
                * (float)((float)((float)(v29.x - *v15) * (float)(v29.x - *v15))
                        + (float)((float)((float)(v29.z - v15[2]) * (float)(v29.z - v15[2]))
                                + (float)((float)(v29.y - v15[1]) * (float)(v29.y - v15[1])))));
    if ( v20 < v25 )
      v9 = true;
    if ( v20 > v26 )
      v9 = true;
  }
  if ( p_memory->transCode == 0 && v9 )
  {
    p_memory->transCode = CheckMove(ai, fsm: (idAIFSM *)1, curTime: v30, stayNearCover: v11, outPos: v10);
    v21 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v21;
    v22 = p_memory->transCode == 0;
    *p_nextMoveTime = ((v21 >> 10) & 0x7FFF) % 0x7D0 + curTime + 3000;
    if ( !v22 )
    {
      v23 = v30[1];
      v24 = v30[2];
      ai->aiVolatile.memory.cachedDestination.x = v30[0];
      ai->aiVolatile.memory.cachedDestination.y = v23;
      ai->aiVolatile.memory.cachedDestination.z = v24;
    }
  }
}


// ========================================================================
// ?MoveToPointHelper@@YA_NW4aiMoveReason_t@@PAVidAI2@@ABVidVec3@@HPAVidAIFSM@@PAVidAIState@@_NM@Z
// EA  : 0x82AE38C8
// RVA : 0x00AE38C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall MoveToPointHelper(
        int moveReason,
        idAI2 *ai,
        const idVec3 *dest,
        int curTime,
        idAIFSM *fsm,
        idAIState *state,
        bool crouchAtDest,
        double tolerance)
{
  idEntityPtr<idEntity const > *p_currentEnemy; // r23
  int value; // r9
  idEntity *v17; // r3
  idEntity *v18; // r4
  idAIFireControl **p_fireControl; // r21
  idPhysics *Physics; // r3
  idVec3 *p_cachedDestination; // r30
  float *v23; // r3
  double v24; // fp10
  double v25; // fp6
  int lastFiredAtTime; // r8
  double v27; // fp3
  double v29; // fp1
  double v31; // fp13
  double v32; // fp10
  walkState_t DesiredWalkStateForDistance; // r28
  idEventArg *v34; // r3
  idEntity *v35; // r3
  idEntity *v36; // r3
  idPhysics *v37; // r3
  float *v38; // r3
  double v39; // fp8
  double x; // fp11
  double v41; // fp6
  double v44; // fp0
  double v45; // fp4
  idEventArg *v46; // r24
  char v47; // r30
  char v48; // r28
  idPhysics *v49; // r3
  float *v50; // r3
  double v51; // fp7
  double v52; // fp5
  double v53; // fp3
  double v54; // fp0
  double v57; // fp6
  double v58; // fp11
  double v59; // fp6
  double v60; // fp13
  idAIOrientation *v61; // r3
  const idDeclAIBehavior *decl; // r30
  idEntity *v63; // r3
  idEntity *v64; // r4
  aiFireMode_t v65; // r5
  idAIOrientation *v66; // r3
  const idEntity *Enemy; // r3
  idAIOrientation *BodyOrientation; // r3
  const idEventArg *v69; // [sp+8h] [-2D8h]
  const idEventArg *v70; // [sp+Ch] [-2D4h]
  _BYTE v71[20]; // [sp+70h] [-270h] BYREF
  _BYTE v72[20]; // [sp+90h] [-250h] BYREF
  _BYTE v73[20]; // [sp+B0h] [-230h] BYREF
  _BYTE v74[20]; // [sp+D0h] [-210h] BYREF
  _BYTE v75[20]; // [sp+F0h] [-1F0h] BYREF
  idVec3 v76; // [sp+110h] [-1D0h] BYREF
  idVec3 v77; // [sp+120h] [-1C0h] BYREF
  float v78[5]; // [sp+130h] [-1B0h] BYREF
  float v79[5]; // [sp+150h] [-190h] BYREF
  idEventArg v80; // [sp+170h] [-170h] BYREF
  idEventReceiver v81[8]; // [sp+190h] [-150h] BYREF
  idEventArg v82; // [sp+1F0h] [-F0h] BYREF
  idEventReceiver v83[2]; // [sp+210h] [-D0h] BYREF

  p_currentEnemy = &ai->aiVolatile.memory.currentEnemy;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v17 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v17 == nullptr )
    return 0;
  v18 = idEntity::CastTo(c: v17);
  if ( v18 == nullptr )
    return 0;
  idAI2::SetAimFocusEntity(
    this: ai,
    ent: v18,
    keepFocusInView: (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 4) != 0,
    aimPoint: AIMPOINT_BEST,
    timeout: -1);
  p_fireControl = &ai->aiVolatile.fireControl;
  idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
  ai->SetWeaponReadyState(this: ai, a2: WEAPONREADY_RAISED);
  ai->aiVolatile.focus.enableBodyRotation = true;
  Physics = idEntity::GetPhysics(this: ai);
  p_cachedDestination = &ai->aiVolatile.memory.cachedDestination;
  v23 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v24 = (float)(v23[2] - ai->aiVolatile.memory.cachedDestination.z);
  v25 = (float)(v23[1] - ai->aiVolatile.memory.cachedDestination.y);
  lastFiredAtTime = ai->aiVolatile.memory.lastFiredAtTime;
  v27 = (float)((float)((float)v25 * (float)v25)
              + (float)((float)((float)(*v23 - p_cachedDestination->x) * (float)(*v23 - p_cachedDestination->x))
                      + (float)((float)v24 * (float)v24)));
  _FP2 = (float)((float)((float)((float)v25 * (float)v25)
                       + (float)((float)((float)(*v23 - p_cachedDestination->x) * (float)(*v23 - p_cachedDestination->x))
                               + (float)((float)v24 * (float)v24)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v29 = (float)((float)((float)((float)v25 * (float)v25)
                      + (float)((float)((float)(*v23 - p_cachedDestination->x) * (float)(*v23 - p_cachedDestination->x))
                              + (float)((float)v24 * (float)v24)))
              * (float)0.5);
  __asm { fsel      f0, f2, f3, f0 }
  v31 = __frsqrte(_FP0);
  v32 = (float)-(float)((float)((float)((float)v31
                                      * (float)((float)((float)((float)v25 * (float)v25)
                                                      + (float)((float)((float)(*v23 - p_cachedDestination->x)
                                                                      * (float)(*v23 - p_cachedDestination->x))
                                                              + (float)((float)v24 * (float)v24)))
                                              * (float)0.5))
                              * (float)v31)
                      - (float)1.5);
  DesiredWalkStateForDistance = idAI2::GetDesiredWalkStateForDistance(
                                  this: ai,
                                  distance: (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)v32 * (float)v31) * (float)v29) * (float)((float)v32 * (float)v31)) - (float)1.5)
                                                                                        * (float)((float)v32 * (float)v31))
                                                                                * (float)v29)
                                                                        * (float)((float)-(float)((float)((float)((float)((float)v32 * (float)v31) * (float)v29) * (float)((float)v32 * (float)v31))
                                                                                                - (float)1.5)
                                                                                * (float)((float)v32 * (float)v31)))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)((float)v32 * (float)v31)
                                                                                        * (float)v29)
                                                                                * (float)((float)v32 * (float)v31))
                                                                        - (float)1.5)
                                                        * (float)((float)v32 * (float)v31)))
                                        * (float)v27),
                                  maxWalkState: (const walkState_t)~((curTime - lastFiredAtTime) ^ 0x7D0),
                                  firedAt: WALKSTATE_SPRINTING,
                                  a5: ((curTime - lastFiredAtTime >= 0)
                                 + ((unsigned int)(curTime - lastFiredAtTime) >= 0x7D0))
                                & 1);
  ai->SetWalkState(this: ai, a2: DesiredWalkStateForDistance);
  if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED && DesiredWalkStateForDistance >= WALKSTATE_RUNNING )
  {
    if ( ai_useTransitions.valueInteger != 0 && ai_useStartTransitions.valueInteger != 0 )
    {
      ai->SetPosture(this: ai, a2: POSTURE_STANDING);
    }
    else
    {
      v34 = idEventArg::idEventArg(this: &v80, data: ai);
      idEventReceiver::ProcessEvent(
        this: v81,
        result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
        ev: *(const idEventDef **)&v34->type,
        arg1: (const idEventArg *)LODWORD(v34->value.v[1]));
    }
  }
  if ( gameLocal->spawnIds.ptr[p_currentEnemy->spawnId.value & 0x1FFF] == p_currentEnemy->spawnId.value >> 13
    && (v35 = gameLocal->entities.ptr[p_currentEnemy->spawnId.value & 0x1FFF]) != nullptr )
  {
    v36 = idEntity::CastTo(c: v35);
  }
  else
  {
    v36 = nullptr;
  }
  v37 = idEntity::GetPhysics(this: v36);
  v38 = (float *)v37->GetOrigin(this: v37, a2: 0);
  v39 = (float)(v38[1] - ai->aiVolatile.memory.cachedDestination.y);
  x = p_cachedDestination->x;
  v41 = (float)(*v38 - p_cachedDestination->x);
  v78[2] = ai->aiVolatile.memory.cachedDestination.y;
  v78[1] = x;
  v78[3] = ai->aiVolatile.memory.cachedDestination.z;
  HIBYTE(v79[0]) = 118;
  *(float *)&v81[5].listeningToList = tolerance;
  HIBYTE(v81[2].listeningToList) = 105;
  v81[3].__vftable = (idEventReceiver_vtbl *)1;
  HIBYTE(v81[5].listenerList) = 102;
  HIBYTE(v81[0].__vftable) = 105;
  v81[0].listenerList = (idList<idEventReceiver *,5> *)2;
  HIBYTE(v78[0]) = 118;
  v80.type = 105;
  v80.value.i = moveReason;
  _FP3 = (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v39 * (float)v39))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f3, f4, f0 }
  v44 = __frsqrte(_FP1);
  v45 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44
                                                                                      * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v39 * (float)v39))
                                                                                              * (float)0.5))
                                                                              * (float)v44)
                                                                      - (float)1.5)
                                                      * (float)v44)
                                              * (float)((float)((float)((float)v41 * (float)v41)
                                                              + (float)((float)v39 * (float)v39))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v44
                                                                              * (float)((float)((float)((float)v41 * (float)v41)
                                                                                              + (float)((float)v39 * (float)v39))
                                                                                      * (float)0.5))
                                                                      * (float)v44)
                                                              - (float)1.5)
                                              * (float)v44))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v44
                                                      * (float)((float)((float)((float)v41 * (float)v41)
                                                                      + (float)((float)v39 * (float)v39))
                                                              * (float)0.5))
                                              * (float)v44)
                                      - (float)1.5)
                      * (float)v44));
  v76.x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v39 * (float)v39)) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                                * (float)v44)
                                                                                        * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v39 * (float)v39))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v39 * (float)v39)) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                        * (float)v44))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v44
                                                                                                * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v39 * (float)v39)) * (float)0.5))
                                                                                        * (float)v44)
                                                                                - (float)1.5)
                                                                * (float)v44))
                                                * (float)((float)((float)((float)v41 * (float)v41)
                                                                + (float)((float)v39 * (float)v39))
                                                        * (float)0.5))
                                        * (float)v45)
                                - (float)1.5)
                * (float)v45)
        * (float)v41;
  v76.y = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v39 * (float)v39)) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                                * (float)v44)
                                                                                        * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v39 * (float)v39))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v39 * (float)v39)) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                        * (float)v44))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v44
                                                                                                * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v39 * (float)v39)) * (float)0.5))
                                                                                        * (float)v44)
                                                                                - (float)1.5)
                                                                * (float)v44))
                                                * (float)((float)((float)((float)v41 * (float)v41)
                                                                + (float)((float)v39 * (float)v39))
                                                        * (float)0.5))
                                        * (float)v45)
                                - (float)1.5)
                * (float)v45)
        * (float)v39;
  v76.z = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v39 * (float)v39)) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                                * (float)v44)
                                                                                        * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v39 * (float)v39))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v39 * (float)v39)) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                        * (float)v44))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v44
                                                                                                * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v39 * (float)v39)) * (float)0.5))
                                                                                        * (float)v44)
                                                                                - (float)1.5)
                                                                * (float)v44))
                                                * (float)((float)((float)((float)v41 * (float)v41)
                                                                + (float)((float)v39 * (float)v39))
                                                        * (float)0.5))
                                        * (float)v45)
                                - (float)1.5)
                * (float)v45)
        * (float)0.0;
  *(idVec3 *)&v79[1] = v76;
  v46 = idEventArg::idEventArg(this: &v82, data: ai);
  memcpy(Dst: v75, Src: v79, Size: sizeof(v75));
  memcpy(Dst: v74, Src: &v81[2].listeningToList, Size: sizeof(v74));
  memcpy(Dst: v73, Src: &v81[5].listenerList, Size: sizeof(v73));
  memcpy(Dst: v72, Src: v81, Size: sizeof(v72));
  memcpy(Dst: v71, Src: v78, Size: sizeof(v71));
  idEventReceiver::ProcessEvent(
    this: v83,
    result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
    ev: *(const idEventDef **)&v46->type,
    arg1: (const idEventArg *)LODWORD(v46->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v46->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v80.type, 32),
    arg4: (const idEventArg *)LODWORD(v80.value.v[1]),
    arg5: (const idEventArg *)LODWORD(v80.value.v[2]),
    arg6: v69,
    arg7: v70);
  v47 = 0;
  v48 = 0;
  v49 = idEntity::GetPhysics(this: ai);
  v50 = (float *)v49->GetOrigin(this: v49, a2: 0);
  v51 = (float)(dest->y - v50[1]);
  v52 = (float)(dest->x - *v50);
  v53 = (float)(dest->z - v50[2]);
  v54 = (float)((float)((float)v53 * (float)v53)
              + (float)((float)((float)(dest->x - *v50) * (float)(dest->x - *v50)) + (float)((float)v51 * (float)v51)));
  _FP11 = (float)((float)((float)((float)v53 * (float)v53)
                        + (float)((float)((float)(dest->x - *v50) * (float)(dest->x - *v50))
                                + (float)((float)v51 * (float)v51)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f8, f11, f0, f13 }
  v57 = __frsqrte(_FP8);
  v58 = (float)((float)-(float)((float)((float)((float)v57
                                              * (float)((float)((float)((float)v53 * (float)v53)
                                                              + (float)((float)((float)(dest->x - *v50)
                                                                              * (float)(dest->x - *v50))
                                                                      + (float)((float)v51 * (float)v51)))
                                                      * (float)0.5))
                                      * (float)v57)
                              - (float)1.5)
              * (float)v57);
  v59 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57
                                                                              * (float)((float)((float)((float)v53 * (float)v53)
                                                                                              + (float)((float)((float)(dest->x - *v50) * (float)(dest->x - *v50)) + (float)((float)v51 * (float)v51)))
                                                                                      * (float)0.5))
                                                                      * (float)v57)
                                                              - (float)1.5)
                                              * (float)v57)
                                      * (float)((float)((float)((float)v53 * (float)v53)
                                                      + (float)((float)((float)(dest->x - *v50) * (float)(dest->x - *v50))
                                                              + (float)((float)v51 * (float)v51)))
                                              * (float)0.5))
                              * (float)((float)-(float)((float)((float)((float)v57
                                                                      * (float)((float)((float)((float)v53 * (float)v53)
                                                                                      + (float)((float)((float)(dest->x - *v50) * (float)(dest->x - *v50))
                                                                                              + (float)((float)v51 * (float)v51)))
                                                                              * (float)0.5))
                                                              * (float)v57)
                                                      - (float)1.5)
                                      * (float)v57))
                      - (float)1.5);
  v60 = (float)((float)-(float)((float)((float)((float)((float)v59 * (float)v58)
                                              * (float)((float)((float)((float)v53 * (float)v53)
                                                              + (float)((float)((float)(dest->x - *v50)
                                                                              * (float)(dest->x - *v50))
                                                                      + (float)((float)v51 * (float)v51)))
                                                      * (float)0.5))
                                      * (float)((float)v59 * (float)v58))
                              - (float)1.5)
              * (float)((float)v59 * (float)v58));
  v77.z = (float)v53
        * (float)((float)-(float)((float)((float)((float)((float)v59 * (float)v58)
                                                * (float)((float)((float)((float)v53 * (float)v53)
                                                                + (float)((float)((float)(dest->x - *v50)
                                                                                * (float)(dest->x - *v50))
                                                                        + (float)((float)v51 * (float)v51)))
                                                        * (float)0.5))
                                        * (float)((float)v59 * (float)v58))
                                - (float)1.5)
                * (float)((float)v59 * (float)v58));
  v77.x = (float)v52 * (float)v60;
  v77.y = (float)v51 * (float)v60;
  if ( (float)((float)(v77.y * v76.y) + (float)((float)(v77.x * v76.x) + (float)(v77.z * v76.z))) > -0.5
    || (float)((float)v60 * (float)v54) < 256.0 )
  {
    v47 = 1;
  }
  if ( idAI2::ShouldAimAtEnemyWhileMoving(this: ai) )
    v48 = 1;
  if ( v47 == 0 )
  {
    if ( v48 == 0 )
    {
      BodyOrientation = idAI2::GetBodyOrientation(this: ai);
      idAIOrientation::SetIdealDir(this: BodyOrientation, ai, dir: &v77);
      idAI2::ClearAimFocus(this: ai);
      idAI2::ClearLookFocus(this: ai);
      v65 = FIREMODE_HOLDFIRE;
      goto LABEL_34;
    }
    v66 = idAI2::GetBodyOrientation(this: ai);
    idAIOrientation::SetIdealDir(this: v66, ai, dir: &v77);
    idAI2::SetEnableHeadTracking(this: ai, enable: true);
    Enemy = idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
    idAI2::SetAimFocusEntity(this: ai, ent: Enemy, keepFocusInView: false, aimPoint: AIMPOINT_BEST, timeout: -1);
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0
      && !ai->aiConstants.movement.allowStrafing )
    {
      v65 = FIREMODE_SPRAYWHENREADY;
      goto LABEL_34;
    }
    goto LABEL_28;
  }
  v61 = idAI2::GetBodyOrientation(this: ai);
  idAIOrientation::SetIdealDir(this: v61, ai, dir: &v76);
  idAI2::SetEnableHeadTracking(this: ai, enable: true);
  decl = ai->aiEditable.behaviors.decl;
  if ( gameLocal->spawnIds.ptr[p_currentEnemy->spawnId.value & 0x1FFF] == p_currentEnemy->spawnId.value >> 13
    && (v63 = gameLocal->entities.ptr[p_currentEnemy->spawnId.value & 0x1FFF]) != nullptr )
  {
    v64 = idEntity::CastTo(c: v63);
  }
  else
  {
    v64 = nullptr;
  }
  idAI2::SetAimFocusEntity(
    this: ai,
    ent: v64,
    keepFocusInView: (*((_BYTE *)&decl->movementBehaviors + 40) & 4) != 0,
    aimPoint: AIMPOINT_BEST,
    timeout: -1);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) == 0
    || ai->aiConstants.movement.allowStrafing )
  {
LABEL_28:
    v65 = FIREMODE_FIREWHENREADY;
    goto LABEL_34;
  }
  v65 = FIREMODE_SPRAYWHENREADY;
LABEL_34:
  idAIFireControl::SetFireMode(this: *p_fireControl, owner: ai, mode: v65);
  idAIState::StartQueuedActions(this: state, ai, parentFSM: fsm, curTime);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
    (*p_fireControl)->ResetNextPullTriggerTime(this: *p_fireControl, a2: ai);
  return 1;
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_AttackMove@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE3FF0
// RVA : 0x00AE3FF0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_AttackMove::AIState_EnterState(
        idOpenCombat_AttackMove *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  if ( (unsigned __int8)MoveToPointHelper(
                          moveReason: 4,
                          ai,
                          dest: &ai->aiVolatile.memory.cachedDestination,
                          curTime,
                          fsm,
                          state: this,
                          crouchAtDest: (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 0x40) != 0,
                          tolerance: 0.1) == 0 )
    idState::SetEnterFailed(this, failed: true);
}


// ========================================================================
// ?Evaluate@OC_StopShooting@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE4060
// RVA : 0x00AE4060
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_StopShooting::Evaluate(
        OC_StopShooting *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  idEntity *v10; // r4
  idAIEntityState *v11; // r3
  aiSenseState_t *v12; // r30
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  float y; // r7
  float z; // r6
  idPhysics *Physics; // r3
  float *v17; // r3
  double v18; // fp7
  double v19; // fp6
  long double v20; // fp2
  long double v21; // fp2
  idPresentable *presentable; // r11
  double v23; // fp31
  idWeapon *v24; // r29
  idPhysics *v25; // r28
  const aiPhysicalState_t *v26; // r30
  float *v27; // r3
  const idDeclInventory *decl; // r11
  double v29; // fp9
  double v30; // fp0
  idVec3 v32; // [sp+50h] [-60h] BYREF
  float x; // [sp+60h] [-50h]
  float v34; // [sp+64h] [-4Ch]
  float v35; // [sp+68h] [-48h]

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 290;
  v9 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v9 == nullptr )
    return 290;
  v10 = idEntity::CastTo(c: v9);
  if ( v10 == nullptr )
    return 290;
  v11 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v10);
  if ( v11 == nullptr )
    return 290;
  v12 = v11->senses.ptr[v11->lastSense];
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v12);
  y = ConfirmedPhysicalSafe->origin.y;
  z = ConfirmedPhysicalSafe->origin.z;
  x = ConfirmedPhysicalSafe->origin.x;
  v34 = y;
  v35 = z;
  Physics = idEntity::GetPhysics(this: ai);
  v17 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v18 = (float)(v34 - v17[1]);
  v19 = (float)(v35 - v17[2]);
  v32.x = x - *v17;
  v32.y = v18;
  v32.z = v19;
  idVec3::NormalizeFast(this: &v32);
  *(double *)&v20 = ai->aiVolatile.focus.foci.ptr[0].aimTracker.maxYaw.value;
  v21 = cos(x: v20);
  presentable = ai->presentable;
  v23 = (float)*(double *)&v21;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: ai);
    presentable = ai->presentable;
  }
  if ( (float)((float)(v32.x * presentable->axis.mat[0].x)
             + (float)((float)(presentable->axis.mat[0].z * v32.z) + (float)(presentable->axis.mat[0].y * v32.y))) >= v23
    && (v24 = ai->GetEquippedWeapon(this: ai)) != nullptr
    && ai->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType != ANIMWEBAI_RUNINDEXTYPE_DUCK
    && (curTime - parentFSM->lastTransitionTime <= 3000
     || curTime - v12->lastConfirmedStimTime < 5000
     && (v25 = idEntity::GetPhysics(this: ai),
         v26 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v12),
         v27 = (float *)v25->GetOrigin(this: v25, a2: 0),
         decl = v24->decl,
         v29 = (float)(v27[1] - v26->origin.y),
         (v30 = (float)((float)((float)v29 * (float)v29)
                      + (float)((float)(*v27 - v26->origin.x) * (float)(*v27 - v26->origin.x)))) >= (float)(*(float *)&decl[1].inventoryClass.baseBuffer[8] * *(float *)&decl[1].inventoryClass.baseBuffer[8]))
     && v30 <= (float)(*(float *)&decl[1].inventoryClass.allocedAndFlag
                     * *(float *)&decl[1].inventoryClass.allocedAndFlag)
     && (!ai->aiVolatile.visibilityObscurity.valid
      || ai->aiVolatile.visibilityObscurity.visibilityObscurity.ptr[0] >= OBSCURITY_PATH_OPEN_AND_ENEMY_VISIBLE)) )
  {
    return 0;
  }
  else
  {
    return 290;
  }
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_Shoot@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE42D8
// RVA : 0x00AE42D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_Shoot::AIState_EnterState(
        idOpenCombat_Shoot *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r4
  idEventArg *v10; // r27
  _BYTE v11[20]; // [sp+70h] [-F0h] BYREF
  _DWORD v12[5]; // [sp+90h] [-D0h] BYREF
  int v13; // [sp+B0h] [-B0h]
  char *data; // [sp+B4h] [-ACh]
  idEventArg v15; // [sp+D0h] [-90h] BYREF
  idEventReceiver v16[2]; // [sp+F0h] [-70h] BYREF
  idStr v17[2]; // [sp+110h] [-50h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v8 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v8 != nullptr )
    {
      v9 = idEntity::CastTo(c: v8);
      if ( v9 != nullptr )
        idAI2::SetAimFocusEntity(
          this: ai,
          ent: v9,
          keepFocusInView: (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 4) != 0,
          aimPoint: AIMPOINT_BEST,
          timeout: -1);
    }
  }
  idStr::idStr(this: v17, text: "$weaponcombat:shoot");
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  HIBYTE(v12[0]) = 105;
  v12[1] = 0;
  HIBYTE(v13) = 115;
  data = v17[0].data;
  v10 = idEventArg::idEventArg(this: &v15, data: ai);
  memcpy(Dst: v11, Src: v12, Size: sizeof(v11));
  idEventReceiver::ProcessEvent(
    this: v16,
    result: fsm,
    ev: *(const idEventDef **)&v10->type,
    arg1: (const idEventArg *)LODWORD(v10->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v10->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v13, 32));
  idStr::FreeData(this: v17);
}


// ========================================================================
// __unwind$499805
// EA  : 0x82AE440C
// RVA : 0x00AE440C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void _unwind_499805()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 272));
}


// ========================================================================
// ?Evaluate@OC_TargetMoved@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE4438
// RVA : 0x00AE4438
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_TargetMoved::Evaluate(
        OC_TargetMoved *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idEntityPtr<idEntity const > *p_currentEnemy; // r31
  int value; // r9
  idEntity *v8; // r3
  idAIMoveState *MoveInterface; // r3
  idAIMoveState *v10; // r31
  int v11; // r11
  int v12; // r8
  idEntity *v13; // r3
  idEntity *v14; // r3
  idPhysics *Physics; // r30
  float *v16; // r31
  float *v17; // r3
  double v18; // fp10
  double v19; // fp8
  idAIStateTransition::aiTransCode_t result; // r3
  double v21; // fp1

  if ( !idAI2::IsMoveDone(this: ai, checkAlignment: false) )
    return 0;
  p_currentEnemy = &ai->aiVolatile.memory.currentEnemy;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v8 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v8 == nullptr || idEntity::CastTo(c: v8) == nullptr )
    return 0;
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v11 = p_currentEnemy->spawnId.value & 0x1FFF;
  v12 = p_currentEnemy->spawnId.value >> 13;
  v10 = MoveInterface;
  if ( gameLocal->spawnIds.ptr[v11] == v12 && (v13 = gameLocal->entities.ptr[v11]) != nullptr )
    v14 = idEntity::CastTo(c: v13);
  else
    v14 = nullptr;
  Physics = idEntity::GetPhysics(this: v14);
  v16 = (float *)v10->GetFinalPoint(this: v10);
  v17 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v18 = (float)(v17[1] - v16[1]);
  v19 = (float)(v17[2] - v16[2]);
  v21 = (float)((float)((float)(*v17 - *v16) * (float)(*v17 - *v16))
              + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18)));
  result = TRANSCODE_OC_TARGET_MOVED;
  if ( __fsqrts(v21) <= (float)((float)(UNITS_PER_INCH_11 * ABORT_MELEE_DISTANCE) * (float)12.0) )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_ChargeMelee@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE45A8
// RVA : 0x00AE45A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_ChargeMelee::AIState_EnterState(
        idOpenCombat_ChargeMelee *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  idEntity *v10; // r3
  idTurret *v11; // r28
  idAIFireControl **p_fireControl; // r30
  idAI2_vtbl *v13; // r8
  unsigned int v14; // r6
  idWeapon *v15; // r29
  idEventArg *v16; // r3
  double v17; // fp31
  idEventArg *v18; // r20
  idEventArg *v19; // r19
  const idEventArg *v20; // [sp+8h] [-2B8h]
  const idEventArg *v21; // [sp+Ch] [-2B4h]
  const idEventArg *v22; // [sp+10h] [-2B0h]
  _BYTE v23[20]; // [sp+70h] [-250h] BYREF
  _BYTE v24[20]; // [sp+90h] [-230h] BYREF
  _BYTE v25[20]; // [sp+B0h] [-210h] BYREF
  _BYTE v26[20]; // [sp+D0h] [-1F0h] BYREF
  _BYTE v27[20]; // [sp+F0h] [-1D0h] BYREF
  _BYTE v28[20]; // [sp+110h] [-1B0h] BYREF
  float v29[5]; // [sp+130h] [-190h] BYREF
  idEventReceiver v30[2]; // [sp+150h] [-170h] BYREF
  idEventArg v31; // [sp+170h] [-150h] BYREF
  _DWORD v32[5]; // [sp+190h] [-130h] BYREF
  _DWORD v33[5]; // [sp+1B0h] [-110h] BYREF
  float v34[5]; // [sp+1D0h] [-F0h] BYREF
  idEventArg v35; // [sp+1F0h] [-D0h] BYREF
  idEventArg v36; // [sp+210h] [-B0h] BYREF
  idEventReceiver v37[2]; // [sp+230h] [-90h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v10 = idEntity::CastTo(c: v9), v11 = (idTurret *)v10, v10 != nullptr) )
  {
    idAI2::SetAimFocusEntity(
      this: ai,
      ent: v10,
      keepFocusInView: (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 4) != 0,
      aimPoint: AIMPOINT_BEST,
      timeout: -1);
    p_fireControl = &ai->aiVolatile.fireControl;
    idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
    v13 = ai->__vftable;
    ai->aiVolatile.focus.enableBodyRotation = true;
    v13->SetWalkState(this: ai, a2: WALKSTATE_RUNNING);
    v14 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v14;
    if ( ((v14 >> 10) & 0x7FFF) % 0x64 >= 0x32 )
      idAIFireControl::SetFireMode(this: *p_fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
    else
      ai->SetWeaponReadyState(this: ai, a2: WEAPONREADY_LOWERED);
    if ( idTurret::CastTo(c: v11) != nullptr )
    {
      ai->SetWeaponReadyState(this: ai, a2: WEAPONREADY_LOWERED);
      v15 = ai->GetEquippedWeapon(this: ai);
      if ( v15 != nullptr )
      {
        idAIFireControl::SetFireMode(this: *p_fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
        v15->ReleaseTrigger(this: v15, a2: ai);
      }
    }
    if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED )
    {
      if ( ai_useTransitions.valueInteger != 0 && ai_useStartTransitions.valueInteger != 0 )
      {
        ai->SetPosture(this: ai, a2: POSTURE_STANDING);
      }
      else
      {
        v16 = idEventArg::idEventArg(this: &v31, data: ai);
        idEventReceiver::ProcessEvent(
          this: v30,
          result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
          ev: *(const idEventDef **)&v16->type,
          arg1: (const idEventArg *)LODWORD(v16->value.v[1]));
      }
    }
    (*p_fireControl)->allowReloads = false;
    ai->aiVolatile.memory.lastChargeTime = curTime;
    v17 = 8.0;
    if ( idPlayer::CastTo(c: (idPlayer *)v11) != nullptr )
      v17 = 22.0;
    v33[1] = 0;
    v32[1] = 0;
    v34[1] = v17;
    HIBYTE(v33[0]) = 105;
    HIBYTE(v32[0]) = 105;
    v29[1] = vec3_origin.x;
    v29[2] = vec3_origin.y;
    HIBYTE(v29[0]) = 118;
    v29[3] = vec3_origin.z;
    HIBYTE(v34[0]) = 102;
    HIBYTE(v30[0].__vftable) = 105;
    v30[0].listenerList = (idList<idEventReceiver *,5> *)2;
    v31.type = 105;
    v31.value.i = 6;
    v18 = idEventArg::idEventArg(this: &v35, data: v11);
    v19 = idEventArg::idEventArg(this: &v36, data: ai);
    memcpy(Dst: v28, Src: v33, Size: sizeof(v28));
    memcpy(Dst: v27, Src: v29, Size: sizeof(v27));
    memcpy(Dst: v26, Src: v32, Size: sizeof(v26));
    memcpy(Dst: v25, Src: v34, Size: sizeof(v25));
    memcpy(Dst: v24, Src: v30, Size: sizeof(v24));
    memcpy(Dst: v23, Src: v18, Size: sizeof(v23));
    idEventReceiver::ProcessEvent(
      this: v37,
      result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
      ev: *(const idEventDef **)&v19->type,
      arg1: (const idEventArg *)LODWORD(v19->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v19->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v31.type, 32),
      arg4: (const idEventArg *)LODWORD(v31.value.v[1]),
      arg5: (const idEventArg *)LODWORD(v31.value.v[2]),
      arg6: v20,
      arg7: v21,
      arg8: v22);
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
      ai->aiVolatile.animation.animFSM.overrideMoveFlags |= 0x1000u;
    idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_AttackMelee@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE49C8
// RVA : 0x00AE49C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_AttackMelee::AIState_EnterState(
        idOpenCombat_AttackMelee *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  const idDeclAIBehavior *decl; // r11
  int minCloseMeleeInterval; // r9
  signed int v9; // r11
  int v10; // r11
  unsigned int seed; // r7
  signed int v12; // r8
  unsigned int v13; // r3
  void (__fastcall *SetWeaponReadyState)(struct idAI2 *, const weaponReadyState_t); // r5
  int value; // r9
  idEntity *v16; // r3
  idTurret *v17; // r30
  idAIEntityState *v18; // r3
  aiSenseState_t *v19; // r28
  int v20; // r30
  idVec3 *p_velocity; // r29
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  aiMelee_t MeleeTypeForTarget; // r29
  idVec3 *v24; // r30
  const aiPhysicalState_t *v25; // r3
  idPhysics *Physics; // r3
  float *v27; // r3
  double v28; // fp7
  double v29; // fp6
  overrideAnim_t v30; // r30
  idEventArg *v31; // r22
  const char *v32; // r30
  int v33; // r11
  const char **v34; // r10
  idVec3 *v35; // r29
  const aiPhysicalState_t *v36; // r3
  idPhysics *v37; // r3
  idRenderWorld *renderWorld; // r29
  idRenderWorld_vtbl *v39; // r28
  int v40; // r3
  idContents *p_clipMask; // r31
  int v42; // r3
  _BYTE v43[20]; // [sp+70h] [-150h] BYREF
  _BYTE v44[20]; // [sp+90h] [-130h] BYREF
  bool v45; // [sp+B0h] [-110h] BYREF
  idVec3 v46[2]; // [sp+B8h] [-108h] BYREF
  float v47[5]; // [sp+D0h] [-F0h] BYREF
  _DWORD v48[5]; // [sp+F0h] [-D0h] BYREF
  int v49; // [sp+110h] [-B0h]
  overrideAnim_t v50; // [sp+114h] [-ACh]
  const idEventArg *v51; // [sp+118h] [-A8h]
  idEventArg v52; // [sp+130h] [-90h] BYREF
  idEventReceiver v53[9]; // [sp+150h] [-70h] BYREF

  decl = ai->aiEditable.behaviors.decl;
  if ( (*((_BYTE *)decl + 196) & 4) != 0 )
  {
    minCloseMeleeInterval = decl->minCloseMeleeInterval;
    v9 = decl->maxCloseMeleeInterval - minCloseMeleeInterval;
    if ( v9 != 0 )
    {
      seed = clientGame->random.seed;
      __twllei(v9, 0);
      clientGame->random.seed = 1664525 * seed + 1013904223;
      v12 = ((1664525 * seed + 1013904223) >> 10) & 0x7FFF;
      v13 = v9 & ~(__ROL4__(v12, 1) - 1);
      v10 = v12 % v9;
      __twlgei(v13, 0xFFFFFFFF);
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
      && (v16 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v17 = (idTurret *)idEntity::CastTo(c: v16);
    }
    else
    {
      v17 = nullptr;
    }
    v18 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v17);
    if ( v18 != nullptr )
    {
      v19 = v18->senses.ptr[v18->lastSense];
      v20 = idAI2::MeleePreference(this: ai, target: v17);
      p_velocity = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v19)->velocity;
      ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v19);
      MeleeTypeForTarget = idAI2::GetMeleeTypeForTarget(
                             this: ai,
                             targetPos: &ConfirmedPhysicalSafe->origin,
                             targetVel: p_velocity,
                             meleeMask: -1,
                             preferredMask: v20);
      if ( MeleeTypeForTarget != AIMELEE_NONE )
      {
        v24 = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v19)->velocity;
        v25 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v19);
        idAI2::ExtrapolateMeleeTarget(this: ai, targetPos: &v25->origin, targetVel: v24, outAttackTo: v46);
        Physics = idEntity::GetPhysics(this: ai);
        v27 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v28 = (float)(v46[0].y - v27[1]);
        v29 = (float)(v46[0].z - v27[2]);
        v46[0].x = v46[0].x - *v27;
        v46[0].y = v28;
        v46[0].z = v29;
        idVec3::NormalizeFast(this: v46);
        if ( !idActor::IsCrouching(this: ai) || (MeleeTypeForTarget & 0x1E00) != 0 )
        {
          v30 = AIMeleeTypeToOverrideAnim(meleeType: MeleeTypeForTarget);
          if ( v30 != ANIMOVERRIDE_NONE )
          {
            idAI2::EndActionScript(this: ai);
            LODWORD(fsm[1].value.v[2]) = this;
            v50 = v30;
            v47[1] = v46[0].x;
            v47[2] = v46[0].y;
            HIBYTE(v48[0]) = 105;
            v47[3] = v46[0].z;
            HIBYTE(v47[0]) = 118;
            v48[1] = 1;
            HIBYTE(v49) = 105;
            v31 = idEventArg::idEventArg(this: &v52, data: ai);
            memcpy(Dst: v44, Src: v47, Size: sizeof(v44));
            memcpy(Dst: v43, Src: v48, Size: sizeof(v43));
            idEventReceiver::ProcessEvent(
              this: v53,
              result: fsm,
              ev: *(const idEventDef **)&v31->type,
              arg1: (const idEventArg *)LODWORD(v31->value.v[1]),
              arg2: (const idEventArg *)LODWORD(v31->value.v[2]),
              arg3: (const idEventArg *)__ROL4__(v49, 32),
              arg4: v51);
          }
          if ( ai_debugmelee.valueInteger != 0 && ai_debugLevel.valueInteger > 0 )
          {
            aiSenseState_t::GetConfirmedPhysicalSafe(this: v19);
            v32 = "UNKNOWN";
            v33 = 2;
            v34 = &aiMeleeAnimNodeNames[1];
            do
            {
              if ( MeleeTypeForTarget >> (v33 - 2) == AIMELEE_NONE )
                v32 = *(v34 - 1);
              if ( MeleeTypeForTarget >> (v33 - 1) == AIMELEE_NONE )
                v32 = *v34;
              if ( MeleeTypeForTarget >> v33 == AIMELEE_NONE )
                v32 = v34[1];
              if ( MeleeTypeForTarget >> (v33 + 1) == AIMELEE_NONE )
                v32 = v34[2];
              v33 += 4;
              v34 += 4;
            }
            while ( v33 - 2 < 16 );
            v35 = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v19)->velocity;
            v36 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v19);
            idAI2::GetMeleeDirection(this: ai, target: &v36->origin, vel: v35, outNarrowFront: &v45, debug: true);
            v37 = idEntity::GetPhysics(this: ai);
            renderWorld = clientGame->renderWorld;
            v39 = renderWorld->__vftable;
            v40 = (int)v37->GetOrigin(this: v37, a2: 0);
            ((void (__fastcall *)(idRenderWorld *, const char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))v39->DebugText)(
              a1: renderWorld,
              a2: v32,
              a3: v40,
              a4: v39->DebugText,
              a5: &idColor::colorYellow,
              a6: 1,
              a7: 1500,
              a8: 0,
              a9: 0.2);
          }
          p_clipMask = &ai->aiConstants.physics.clipMask;
          v42 = idContents::ToFlags(this: p_clipMask);
          idContents::FromFlags(this: p_clipMask, flags: v42 | 0x400);
        }
      }
    }
  }
}


// ========================================================================
// ?Evaluate@OC_ShouldLeapAttack@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE4E28
// RVA : 0x00AE4E28
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_ShouldLeapAttack::Evaluate(
        OC_ShouldLeapAttack *this,
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
  int entityNumber; // r29
  const aiPhysicalState_t *v58; // r3
  idRenderWorld *v59; // r26
  idPhysics *v60; // r3
  int v61; // r25
  idRenderWorld_vtbl *v62; // r29
  const aiPhysicalState_t *v63; // r3
  idPhysics *v64; // r31
  idRenderWorld *v65; // r29
  idPhysics *v66; // r3
  idRenderWorld_vtbl *v67; // r31
  const idVec3 *(__fastcall *v68)(idPhysics *, int); // ctr
  int v69; // r3
  int v70; // r6
  idRenderWorld *v71; // r29
  idPhysics *v72; // r3
  int v73; // r27
  idRenderWorld_vtbl *v74; // r30
  const aiPhysicalState_t *v75; // r3
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
  ((void (__fastcall *)(idAAS2 *, float *, int, int, idVec3 *, unsigned int, _DWORD, int))v38->TraceFloor)(
    a1: v35,
    a2: v82,
    a3: v41,
    a4: v40,
    a5: &v78,
    a6: v39,
    a7: 0,
    a8: 1);
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
        a2: &idColor::colorOrange,
        a3: v50,
        a4: &v78,
        a5: 10.0);
      v51 = idEntity::GetPhysics(this: ai);
      v52 = common->RW(this: common);
      v53 = v51;
      v55 = v51->GetOrigin;
      v54 = v52->__vftable;
      v56 = (int)v55(this: v53, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, const char *, int, char *, idColor *, int, int, _DWORD, double))v54->DebugText)(
        a1: v52,
        a2: "AAS",
        a3: v56,
        a4: &aAvSsobjectVCom[20],
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
    entityNumber = ai->entityNumber;
    v58 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v15);
    idClip::TraceBounds(
      this: &clientGame->clip,
      result: &v85,
      start: v83,
      end: &v58->eyePos,
      trm: nullptr,
      clipMask: 1025,
      passEntityNumber: entityNumber);
    if ( v85.fraction >= 1.0 || v85.c.entityNum == v12->entityNumber )
      v16 = 0;
    if ( v16 != 0 )
    {
      if ( idAI2::GetDebugLevel() > 0 && ai_debugLeapAttack.valueInteger != 0 )
      {
        v59 = common->RW(this: common);
        v60 = idEntity::GetPhysics(this: ai);
        v61 = (int)v60->GetOrigin(this: v60, a2: 0);
        v62 = v59->__vftable;
        v63 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v15);
        ((void (__fastcall *)(idRenderWorld *, idColor *, int, const aiPhysicalState_t *, double))v62->DebugArrow)(
          a1: v59,
          a2: &idColor::colorOrange,
          a3: v61,
          a4: v63,
          a5: 10.0);
        v64 = idEntity::GetPhysics(this: ai);
        v65 = common->RW(this: common);
        v66 = v64;
        v68 = v64->GetOrigin;
        v67 = v65->__vftable;
        v69 = (int)v68(this: v66, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, const char *, int, int, idColor *, int, int, _DWORD, double))v67->DebugText)(
          a1: v65,
          a2: "BLOCKED",
          a3: v69,
          a4: v70,
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
        v71 = common->RW(this: common);
        v72 = idEntity::GetPhysics(this: ai);
        v73 = (int)v72->GetOrigin(this: v72, a2: 0);
        v74 = v71->__vftable;
        v75 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v15);
        ((void (__fastcall *)(idRenderWorld *, idColor *, int, const aiPhysicalState_t *, double))v74->DebugArrow)(
          a1: v71,
          a2: &idColor::colorYellow,
          a3: v73,
          a4: v75,
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
// ?Evaluate@OC_EnemyClose@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE56D0
// RVA : 0x00AE56D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

int __fastcall OC_EnemyClose::Evaluate(
        OC_EnemyClose *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r31
  idAIMoveState *MoveInterface; // r3

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v7 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr )
    return 0;
  v8 = idEntity::CastTo(c: v7);
  if ( v8 == nullptr )
    return 0;
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  return !MoveInterface->ReachedEntity(this: MoveInterface, a2: v8, a3: 32.0) ? 0 : 0x129;
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_EnemyNotVisible@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE5798
// RVA : 0x00AE5798
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_EnemyNotVisible::AIState_EnterState(
        idOpenCombat_EnemyNotVisible *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r3
  const idEntity *v10; // r30
  idEventArg *v11; // r28
  _BYTE v12[20]; // [sp+70h] [-C0h] BYREF
  _DWORD v13[5]; // [sp+90h] [-A0h] BYREF
  int v14; // [sp+B0h] [-80h]
  int v15; // [sp+B4h] [-7Ch]
  idEventArg v16; // [sp+D0h] [-60h] BYREF
  idEventReceiver v17[5]; // [sp+F0h] [-40h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v8 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v8 != nullptr )
    {
      v9 = idEntity::CastTo(c: v8);
      v10 = v9;
      if ( v9 != nullptr && idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v9) != nullptr )
      {
        idAI2::SetAimFocusEntity(
          this: ai,
          ent: v10,
          keepFocusInView: (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 4) != 0,
          aimPoint: AIMPOINT_BEST,
          timeout: -1);
        ai->aiVolatile.focus.enableBodyRotation = true;
        idAI2::SetEnableHeadTracking(this: ai, enable: true);
        ai->SetWeaponReadyState(this: ai, a2: WEAPONREADY_RAISED);
        idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
        idAI2::EndActionScript(this: ai);
        LODWORD(fsm[1].value.v[2]) = this;
        v13[1] = 1;
        HIBYTE(v13[0]) = 105;
        HIBYTE(v14) = 105;
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
      }
    }
  }
}


// ========================================================================
// ?Evaluate@OC_ShouldMoveToRecharge@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE5908
// RVA : 0x00AE5908
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall OC_ShouldMoveToRecharge::Evaluate(
        OC_ShouldMoveToRecharge *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3
  idEncounterGroup *EncounterGroup; // r3
  int curCombatStage; // r11
  idCombatStage *v9; // r31
  idPhysics *Physics; // r3
  const idVec3 *v11; // r3
  int v13; // [sp+50h] [-20h] BYREF

  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v13 = 5000;
  if ( !MoveInterface->RecentlyFailedMove(
          this: MoveInterface,
          a2: AIMOVEREASON_OC_RECHARGE,
          a3: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&v13) )
  {
    EncounterGroup = idAI2::GetEncounterGroup(this: ai);
    if ( !ai->aiEditable.movement.turretMode && EncounterGroup != nullptr )
    {
      curCombatStage = EncounterGroup->curCombatStage;
      if ( curCombatStage >= 0 && curCombatStage < EncounterGroup->combatStages.num )
      {
        v9 = &EncounterGroup->combatStages.list[curCombatStage];
        if ( v9 != nullptr && idEntityPtr<idAIHintGroup>::operator->(this: &v9->hintGroup) != nullptr )
        {
          Physics = idEntity::GetPhysics(this: ai);
          v11 = Physics->GetOrigin(this: Physics, a2: 0);
          idCombatStage::GetHintWeight(this: v9, hintType: 6u, pos: v11, hintClass: CLASS_ALL);
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_MoveToRecharge@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE5A00
// RVA : 0x00AE5A00
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_MoveToRecharge::AIState_EnterState(
        idOpenCombat_MoveToRecharge *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  if ( (unsigned __int8)MoveToPointHelper(
                          moveReason: 5,
                          ai,
                          dest: &ai->aiVolatile.memory.cachedDestination,
                          curTime,
                          fsm,
                          state: this,
                          crouchAtDest: true,
                          tolerance: 0.1) == 0 )
    idState::SetEnterFailed(this, failed: true);
}


// ========================================================================
// ?AIState_EnterState@idOpenCombat_MoveToRoleHintNode@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE5A68
// RVA : 0x00AE5A68
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_MoveToRoleHintNode::AIState_EnterState(
        idOpenCombat_MoveToRoleHintNode *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  if ( (unsigned __int8)MoveToPointHelper(
                          moveReason: 3,
                          ai,
                          dest: &ai->aiVolatile.memory.cachedDestination,
                          curTime,
                          fsm,
                          state: this,
                          crouchAtDest: (*((_BYTE *)&ai->aiEditable.behaviors.decl->movementBehaviors + 40) & 0x40) != 0,
                          tolerance: 32.0) == 0 )
    idState::SetEnterFailed(this, failed: true);
}


// ========================================================================
// ?AIState_ExitState@idOpenCombat_Shoot@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE5B40
// RVA : 0x00AE5B40
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idOpenCombat_Shoot::AIState_ExitState(
        idOpenCombat_Shoot *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idWeapon *v5; // r3
  idPresentableWeapon *PresentableWeapon; // r3

  idEntity::StopSound(this: ai, channel: SND_CHANNEL_WEAPON, peerMask: 0);
  if ( ai->GetEquippedWeapon(this: ai) != nullptr )
  {
    v5 = ai->GetEquippedWeapon(this: ai);
    PresentableWeapon = idWeapon::GetPresentableWeapon(this: v5);
    idFXManager::StopFX(this: &PresentableWeapon->fxManager, time: 61, stopCondition: 0, immediateStop: false);
  }
}


// ========================================================================
// ?AIState_ExitState@idAdvance_AttackMelee@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE5BC0
// RVA : 0x00AE5BC0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __fastcall idAdvance_AttackMelee::AIState_ExitState(
        idAdvance_AttackMelee *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idContents *p_clipMask; // r31
  int v6; // r3

  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) == 0 )
  {
    idAI2::GetDefaultMovementMode(this: ai);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&ai->aiVolatile.physics.moveState);
  }
  ai->SetWeaponReadyState(this: ai, a2: WEAPONREADY_RAISED);
  p_clipMask = &ai->aiConstants.physics.clipMask;
  v6 = idContents::ToFlags(this: p_clipMask);
  idContents::FromFlags(this: p_clipMask, flags: v6 & 0xFFFFFBFF);
}


// ========================================================================
// `dynamic initializer for 'ai_debugCharge''
// EA  : 0x83369660
// RVA : 0x01369660
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugCharge__()
{
  idCVar::idCVar(
    this: &ai_debugCharge,
    name: "ai_debugCharge",
    value: "0",
    flags: 1,
    description: "1 = debug AI charge reasons",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugCharge__);
}

