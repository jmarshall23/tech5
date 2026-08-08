
// ========================================================================
// ?AdjustCoverActionForOrientation@@YA?AW4coverAction_t@@W41@W4coverOrientation_t@@@Z
// EA  : 0x82AD4C58
// RVA : 0x00AD4C58
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

coverAction_t __fastcall AdjustCoverActionForOrientation(
        coverAction_t coverAction,
        const coverOrientation_t coverOrientation)
{
  if ( coverOrientation == COVERORIENT_BACKWARD )
  {
    switch ( coverAction )
    {
      case COVERACTION_FIRE_LEAN_LEFT:
        return COVERACTION_FIRE_LEAN_RIGHT;
      case COVERACTION_FIRE_STEP_LEFT:
        return COVERACTION_FIRE_STEP_RIGHT;
      case COVERACTION_PEEK_LEFT:
        return COVERACTION_PEEK_RIGHT;
      case COVERACTION_FIRE_LEAN_RIGHT:
        return COVERACTION_FIRE_LEAN_LEFT;
      case COVERACTION_FIRE_STEP_RIGHT:
        return COVERACTION_FIRE_STEP_LEFT;
      case COVERACTION_PEEK_RIGHT:
        return COVERACTION_PEEK_LEFT;
      default:
        break;
    }
  }
  return coverAction;
}


// ========================================================================
// ?Evaluate@IC_Wait@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD4CC0
// RVA : 0x00AD4CC0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_Wait::Evaluate(idTypedResourceList<idStaticModel> *this)
{
  return 404;
}


// ========================================================================
// ?InternalInitState@idInCover_Default@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD4CC8
// RVA : 0x00AD4CC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Default::InternalInitState(idInCover_Default *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &IC_Wait::Type, nextStateType: &idInCover_Wait::Type);
}


// ========================================================================
// ?InternalInitState@idInCover_Wait@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD4CE0
// RVA : 0x00AD4CE0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Wait::InternalInitState(idInCover_Wait *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_OffCoverPoint::Type,
    nextStateType: &idInCover_OffCoverPoint::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_TookDamage::Type, nextStateType: &idInCover_TookDamage::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_CoverCompromised::Type,
    nextStateType: &idInCover_Compromised::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_EnemyClose::Type, nextStateType: &idInCover_EnemyClose::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_CoverExpired::Type,
    nextStateType: &idInCover_CoverExpired::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_ThrowGrenade::Type,
    nextStateType: &idInCover_ThrowGrenade::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_ReloadWeaponSoon::Type, nextStateType: &idInCover_Reload::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_ShouldPeek::Type, nextStateType: &idInCover_Peek::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_ShouldBlindfire::Type,
    nextStateType: &idInCover_Blindfire::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_ShouldHide::Type, nextStateType: &idInCover_Hide::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_ShouldLeanOut::Type, nextStateType: &idInCover_LeaningOut::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &IC_AvoidGrenade::Type,
    nextStateType: &idInCover_CoverExpired::Type);
  idState::AddEventTransition(this, fsm, transType: &IC_AvoidFire::Type, nextStateType: &idInCover_Hide::Type);
  idState::AddEventTransition(this, fsm, transType: &IC_AvoidAim::Type, nextStateType: &idInCover_Hide::Type);
}


// ========================================================================
// ?InternalInitState@idInCover_LeaningOut@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD4E78
// RVA : 0x00AD4E78
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_LeaningOut::InternalInitState(idInCover_LeaningOut *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_CoverExpired::Type,
    nextStateType: &idInCover_CoverExpired::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_CoverCompromised::Type,
    nextStateType: &idInCover_Compromised::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_EnemyClose::Type, nextStateType: &idInCover_EnemyClose::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_OffCoverPoint::Type,
    nextStateType: &idInCover_OffCoverPoint::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_ReloadWeapon::Type, nextStateType: &idInCover_Reload::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_FinishedFiring::Type, nextStateType: &idInCover_Wait::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_PossiblyThrowGrenade::Type,
    nextStateType: &idInCover_Wait::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &IC_AvoidGrenade::Type,
    nextStateType: &idInCover_CoverExpired::Type);
  idState::AddEventTransition(this, fsm, transType: &IC_AvoidFire::Type, nextStateType: &idInCover_Hide::Type);
  idState::AddEventTransition(this, fsm, transType: &IC_AvoidHeavyAim::Type, nextStateType: &idInCover_Hide::Type);
}


// ========================================================================
// ?Evaluate@IC_LeanInFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD4FA8
// RVA : 0x00AD4FA8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_LeanInFinished::Evaluate(
        IC_LeanInFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x19D;
}


// ========================================================================
// ?InternalInitState@idInCover_LeanIn@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD4FE8
// RVA : 0x00AD4FE8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_LeanIn::InternalInitState(idInCover_LeanIn *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &IC_LeanInFinished::Type, nextStateType: &idInCover_Wait::Type);
}


// ========================================================================
// ?InternalInitState@idInCover_Reload@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD5000
// RVA : 0x00AD5000
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Reload::InternalInitState(idInCover_Reload *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_CoverCompromised::Type,
    nextStateType: &idInCover_Compromised::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_OutOfAmmo::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_ReloadFinished::Type, nextStateType: &idInCover_Wait::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &IC_AvoidGrenade::Type,
    nextStateType: &idInCover_CoverExpired::Type);
  idState::AddEventTransition(this, fsm, transType: &IC_AvoidFire::Type, nextStateType: &idInCover_Hide::Type);
  idState::AddEventTransition(this, fsm, transType: &IC_AvoidHeavyAim::Type, nextStateType: &idInCover_Hide::Type);
}


// ========================================================================
// ?Evaluate@IC_CoverExpiredFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD50C0
// RVA : 0x00AD50C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_CoverExpiredFinished::Evaluate(
        IC_CoverExpiredFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 425;
}


// ========================================================================
// ?InternalInitState@idInCover_CoverExpired@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD50C8
// RVA : 0x00AD50C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_CoverExpired::InternalInitState(
        idInCover_CoverExpired *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &IC_CoverExpiredFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?Evaluate@IC_CompromisedFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD50E0
// RVA : 0x00AD50E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_CompromisedFinished::Evaluate(
        IC_CompromisedFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 426;
}


// ========================================================================
// ?InternalInitState@idInCover_Compromised@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD50E8
// RVA : 0x00AD50E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Compromised::InternalInitState(idInCover_Compromised *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &IC_CompromisedFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?Evaluate@IC_EnemyCloseFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD5100
// RVA : 0x00AD5100
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_EnemyCloseFinished::Evaluate(
        IC_EnemyCloseFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 427;
}


// ========================================================================
// ?InternalInitState@idInCover_EnemyClose@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD5108
// RVA : 0x00AD5108
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_EnemyClose::InternalInitState(idInCover_EnemyClose *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &IC_EnemyCloseFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?Evaluate@IC_TookDamageFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD5120
// RVA : 0x00AD5120
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_TookDamageFinished::Evaluate(
        IC_TookDamageFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 428;
}


// ========================================================================
// ?InternalInitState@idInCover_TookDamage@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD5128
// RVA : 0x00AD5128
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_TookDamage::InternalInitState(idInCover_TookDamage *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &IC_TookDamageFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?Evaluate@IC_NoContactFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD5140
// RVA : 0x00AD5140
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_NoContactFinished::Evaluate(
        IC_NoContactFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 429;
}


// ========================================================================
// ?InternalInitState@idInCover_NoContact@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD5148
// RVA : 0x00AD5148
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_NoContact::InternalInitState(idInCover_NoContact *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &IC_NoContactFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?Evaluate@IC_OffCoverPointFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD5160
// RVA : 0x00AD5160
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_OffCoverPointFinished::Evaluate(
        IC_OffCoverPointFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 430;
}


// ========================================================================
// ?InternalInitState@idInCover_OffCoverPoint@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD5168
// RVA : 0x00AD5168
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_OffCoverPoint::InternalInitState(
        idInCover_OffCoverPoint *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_OffCoverPointFinished::Type,
    nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idInCover_ThrowGrenade@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD5180
// RVA : 0x00AD5180
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_ThrowGrenade::InternalInitState(
        idInCover_ThrowGrenade *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &IC_ThrowFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idInCover_Hide@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD5198
// RVA : 0x00AD5198
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Hide::InternalInitState(idInCover_Hide *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_CoverCompromised::Type,
    nextStateType: &idInCover_Compromised::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_EnemyClose::Type, nextStateType: &idInCover_EnemyClose::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_OffCoverPoint::Type,
    nextStateType: &idInCover_OffCoverPoint::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_ShouldBlindfire::Type,
    nextStateType: &idInCover_Blindfire::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_ShouldLeanOut::Type, nextStateType: &idInCover_LeaningOut::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_ShouldPeek::Type, nextStateType: &idInCover_Peek::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_HideFinished::Type, nextStateType: &idInCover_Wait::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &IC_HideTakingDamage::Type,
    nextStateType: &idInCover_Compromised::Type);
  idState::AddEventTransition(this, fsm, transType: &IC_AvoidGrenade::Type, nextStateType: &idInCover_Compromised::Type);
}


// ========================================================================
// ?InternalInitState@idInCover_Peek@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD52A8
// RVA : 0x00AD52A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Peek::InternalInitState(idInCover_Peek *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_CoverCompromised::Type,
    nextStateType: &idInCover_Compromised::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_EnemyClose::Type, nextStateType: &idInCover_EnemyClose::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_OffCoverPoint::Type,
    nextStateType: &idInCover_OffCoverPoint::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_ShouldBlindfire::Type,
    nextStateType: &idInCover_Blindfire::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_ShouldLeanOut::Type, nextStateType: &idInCover_LeaningOut::Type);
  idState::AddStateTransition(this, fsm, transType: &IC_PeekFinished::Type, nextStateType: &idInCover_Wait::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_PossiblyThrowGrenade::Type,
    nextStateType: &idInCover_Wait::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &IC_AvoidGrenade::Type,
    nextStateType: &idInCover_CoverExpired::Type);
  idState::AddEventTransition(this, fsm, transType: &IC_AvoidFire::Type, nextStateType: &idInCover_Hide::Type);
  idState::AddEventTransition(this, fsm, transType: &IC_AvoidHeavyAim::Type, nextStateType: &idInCover_Hide::Type);
}


// ========================================================================
// ?InternalInitState@idInCover_Blindfire@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD53D8
// RVA : 0x00AD53D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Blindfire::InternalInitState(idInCover_Blindfire *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_CoverCompromised::Type,
    nextStateType: &idInCover_Compromised::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_BlindfireFinished::Type,
    nextStateType: &idInCover_Reload::Type,
    transCode: 408);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_BlindfireFinished::Type,
    nextStateType: &idInCover_Wait::Type,
    transCode: 435);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &IC_BlindfireFinished::Type,
    nextStateType: &idInCover_Hide::Type,
    transCode: 415);
}


// ========================================================================
// ?InitStates@idInCoverFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82AD5468
// RVA : 0x00AD5468
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCoverFSM::InitStates(idInCoverFSM *this, const idFiniteStateMachineParams *params)
{
  idAIFSM::InitStates(this, params);
  this->AddState(this, a2: &this->stateDefault);
  this->AddState(this, a2: &this->stateWait);
  this->AddState(this, a2: &this->stateLeaningOut);
  this->AddState(this, a2: &this->stateLeanIn);
  this->AddState(this, a2: &this->stateReload);
  this->AddState(this, a2: &this->stateCoverExpired);
  this->AddState(this, a2: &this->stateCompromised);
  this->AddState(this, a2: &this->stateEnemyClose);
  this->AddState(this, a2: &this->stateTookDamage);
  this->AddState(this, a2: &this->stateOffCoverPoint);
  this->AddState(this, a2: &this->stateOffCoverPoint);
  this->AddState(this, a2: &this->stateThrowGrenade);
  this->AddState(this, a2: &this->stateHide);
  this->AddState(this, a2: &this->statePeek);
  this->AddState(this, a2: &this->stateBlindfire);
}


// ========================================================================
// ?AIState_EnterState@idInCover_Default@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD5608
// RVA : 0x00AD5608
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Default::AIState_EnterState(
        idInCover_Default *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  ai->aiVolatile.memory.exitCoverTime = GetRandomInterval(
                                          _min: ai->aiEditable.behaviors.decl->minCoverDuration,
                                          _max: ai->aiEditable.behaviors.decl->maxCoverDuration)
                                      + curTime;
}


// ========================================================================
// ?Evaluate@IC_FinishedFiring@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD5660
// RVA : 0x00AD5660
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall IC_FinishedFiring::Evaluate(
        IC_FinishedFiring *this,
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
    return TRANSCODE_IC_FINISHED_FIRING;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_IC_FINISHED_FIRING;
  return result;
}


// ========================================================================
// ?Evaluate@IC_PossiblyThrowGrenade@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD56B0
// RVA : 0x00AD56B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_PossiblyThrowGrenade::Evaluate(
        IC_PossiblyThrowGrenade *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAICover *p_currentCover; // r30
  idCoverActions v8; // [sp+50h] [-30h] BYREF

  p_currentCover = &ai->aiVolatile.memory.currentCover;
  if ( (unsigned __int8)idAICover::IsValid(this: &ai->aiVolatile.memory.currentCover) == 0 )
    return 0;
  *((_BYTE *)&v8 + 4) &= 7u;
  v8.__vftable = (idCoverActions_vtbl *)&idCoverActions::`vftable';
  idAICover::GetCoverActions(this: p_currentCover, actions: &v8);
  if ( ((*((_BYTE *)&v8 + 4) & 0x40) != 0 || (*((_BYTE *)&v8 + 4) & 0x10) != 0)
    && ai->GetEquippedWeapon(this: ai) != nullptr
    && ai->GetEquippedWeapon(this: ai)->triggerState != TRIGGERSTATE_PULLED
    && idAI2::CanThrowGrenade(this: ai, condition: AISELECTCONDITION_COVER)
    && (ai->aiVolatile.groupStatus.condition & 0x400) != 0 )
  {
    return 409;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// __unwind$490383
// EA  : 0x82AD57AC
// RVA : 0x00AD57AC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_490383()
{
  int v0; // r12

  idCoverActions::~idCoverActions(this: (idCoverActions *)(v0 - 128 + 80));
}


// ========================================================================
// ?Evaluate@IC_AvoidGrenade@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD57D8
// RVA : 0x00AD57D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_AvoidGrenade::Evaluate(
        IC_AvoidGrenade *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return parentFSM->eventId != 8 ? 0 : 0x19A;
}


// ========================================================================
// ?Evaluate@IC_AvoidAim@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD57F8
// RVA : 0x00AD57F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall IC_AvoidAim::Evaluate(
        IC_AvoidAim *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  const idDeclAIBehavior *decl; // r28
  idAI2::aiCondition_t condition; // r11
  signed int aimCoverHideChance; // r29
  unsigned int v9; // r4
  idAIStateTransition::aiTransCode_t result; // r3

  decl = ai->aiEditable.behaviors.decl;
  condition = ai->aiVolatile.groupStatus.condition;
  if ( (condition & 8) != 0
    || (condition & 0x200) != 0
    || parentFSM->eventId != 64
    || (unsigned __int8)idAI2::CanHideHelmetGroupTest(this: ai) == 0 )
  {
    return 0;
  }
  aimCoverHideChance = decl->dodging.aimCoverHideChance;
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
     - ai->aiVolatile.memory.lastHeavyAimedAtTime < 200 )
    aimCoverHideChance = decl->dodging.aimHeavyCoverHideChance;
  v9 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v9;
  result = TRANSCODE_IC_AIMED_AT;
  if ( (int)(((v9 >> 10) & 0x7FFF) % 0x64) >= aimCoverHideChance )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@IC_AvoidAnyAim@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD58E8
// RVA : 0x00AD58E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_AvoidAnyAim::Evaluate(
        IC_AvoidAnyAim *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  if ( (ai->aiVolatile.groupStatus.condition & 8) != 0 )
    return 0;
  else
    return parentFSM->eventId != 64 ? 0 : 0x19B;
}


// ========================================================================
// ?Evaluate@IC_AvoidHeavyAim@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD5928
// RVA : 0x00AD5928
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall IC_AvoidHeavyAim::Evaluate(
        IC_AvoidHeavyAim *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  const idDeclAIBehavior *decl; // r28
  signed int aimHeavyCoverHideChance; // r30
  unsigned int v8; // r4
  idAIStateTransition::aiTransCode_t result; // r3

  decl = ai->aiEditable.behaviors.decl;
  if ( (ai->aiVolatile.groupStatus.condition & 8) != 0
    || parentFSM->eventId != 64
    || (unsigned __int8)idAI2::CanHideHelmetGroupTest(this: ai) == 0 )
  {
    return 0;
  }
  aimHeavyCoverHideChance = 0;
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
     - ai->aiVolatile.memory.lastHeavyAimedAtTime < 200 )
    aimHeavyCoverHideChance = decl->dodging.aimHeavyCoverHideChance;
  v8 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v8;
  result = TRANSCODE_IC_AIMED_AT;
  if ( (int)(((v8 >> 10) & 0x7FFF) % 0x64) >= aimHeavyCoverHideChance )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_ExitState@idInCover_LeaningOut@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD5A10
// RVA : 0x00AD5A10
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_LeaningOut::AIState_ExitState(
        idInCover_LeaningOut *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idWeapon *v6; // r3
  const idWeapon *v7; // r30
  idEncounterGroup *EncounterGroup; // r3
  const idDeclAIBehavior *decl; // r30
  aiSkill_t ModifiedSkill; // r28
  aiSkill_t v11; // r3

  v6 = ai->GetEquippedWeapon(this: ai);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v6->ReleaseTrigger(this: v6, a2: ai);
    idAIFireControl::InhibitFire(this: ai->aiVolatile.fireControl, weapon: v7, inhibitLength: 1000);
  }
  ai->aiVolatile.groupStatus.condition &= ~0x20u;
  if ( idAI2::GetEncounterGroup(this: ai) != nullptr )
  {
    EncounterGroup = idAI2::GetEncounterGroup(this: ai);
    idEncounterGroup::UpdateFiringConditions(this: EncounterGroup);
  }
  decl = ai->aiEditable.behaviors.decl;
  if ( ai->aiVolatile.memory.nextCoverActionTime < curTime )
  {
    ModifiedSkill = idAI2::GetModifiedSkill(this: ai);
    v11 = idAI2::GetModifiedSkill(this: ai);
    ai->aiVolatile.memory.nextCoverActionTime = GetRandomInterval(
                                                  _min: decl->takeCoverBehaviors.minWaitInCoverTime.setting[v11],
                                                  _max: decl->takeCoverBehaviors.maxWaitInCoverTime.setting[ModifiedSkill])
                                              + curTime;
  }
}


// ========================================================================
// ?Evaluate@IC_ReloadFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD5AF8
// RVA : 0x00AD5AF8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall IC_ReloadFinished::Evaluate(
        IC_ReloadFinished *this,
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
    return TRANSCODE_IC_RELOAD_FINISHED;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_IC_RELOAD_FINISHED;
  return result;
}


// ========================================================================
// ?Evaluate@IC_OutOfAmmo@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD5B40
// RVA : 0x00AD5B40
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_OutOfAmmo::Evaluate(
        IC_OutOfAmmo *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idWeapon *v6; // r30
  const idInventoryCollection *v8; // r3
  idInventoryCollection *v9; // r28
  const idAmmoItem *ammoClip; // r29
  const idDeclAmmo *decl; // r31

  v6 = ai->GetEquippedWeapon(this: ai);
  if ( v6 == nullptr )
    return 424;
  v8 = ai->GetInventory_2(this: ai);
  v9 = (idInventoryCollection *)v8;
  if ( v8 == nullptr )
    return 424;
  ammoClip = v6->ammoClip;
  if ( ammoClip != nullptr )
    decl = (const idDeclAmmo *)ammoClip->decl;
  else
    decl = nullptr;
  if ( decl == nullptr || !idWeapon::CanReload(this: v6, inventory: v8, ammoDecl: decl, secondaryAmmo: false) )
    decl = idWeapon::FindNextLoadableAmmo(this: v6, inventory: v9, curAmmo: ammoClip, secondaryAmmo: false);
  return decl != nullptr ? 0 : 0x1A8;
}


// ========================================================================
// ?AIState_EnterState@idInCover_Reload@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD5C10
// RVA : 0x00AD5C10
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Reload::AIState_EnterState(idInCover_Reload *this, idAI2 *ai, idEventArg *fsm, int curTime)
{
  startReloadFrame = idAccolade::Count(this: &clientGame->gameTimeManager);
  idAI2::StartReloading(this: ai, fsm, state: this, curTime, reloadSlot: EQUIP_NONE);
  idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai);
}


// ========================================================================
// ?AIState_ExitState@idInCover_Reload@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD5C78
// RVA : 0x00AD5C78
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Reload::AIState_ExitState(idInCover_Reload *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  const idWeapon *v5; // r4

  v5 = (const idWeapon *)((int (__fastcall *)(idAI2 *, idAI2 *, idAIFSM *, int))ai->GetEquippedWeapon)(
                           a1: ai,
                           a2: ai,
                           a3: fsm,
                           a4: curTime);
  if ( v5 != nullptr )
    idAIFireControl::InhibitFire(this: ai->aiVolatile.fireControl, weapon: v5, inhibitLength: 250);
}


// ========================================================================
// ?AIState_EnterState@idInCover_EnemyClose@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD5CD8
// RVA : 0x00AD5CD8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_EnemyClose::AIState_EnterState(
        idInCover_EnemyClose *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  const idDeclAIBehavior *decl; // r28
  double openCombatDuration; // fp13
  aiSenseState_t *EnemySenseState; // r3
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  idPhysics *Physics; // r3
  float *v11; // r3
  double v12; // fp5
  idPhysics *v13; // r3
  idPhysics *v14; // r3
  float *v15; // r3
  float x; // [sp+50h] [-60h]
  float y; // [sp+54h] [-5Ch]
  float z; // [sp+58h] [-58h]

  decl = ai->aiEditable.behaviors.decl;
  idAIMemory::SetInvalidCover(
    this: &ai->aiVolatile.memory,
    cover: &ai->aiVolatile.memory.currentCover,
    unusableTime: 2500);
  openCombatDuration = ai->aiEditable.behaviors.decl->openCombatDuration;
  ai->aiVolatile.focus.enableBodyRotation = true;
  ai->aiVolatile.memory.endOpenCombatTime = curTime - (int)(float)((float)openCombatDuration * (float)-1000.0);
  idAI2::SetEnableHeadTracking(this: ai, enable: true);
  idAI2::ReleaseCover(this: ai);
  idAICover::idAICover(this: &ai->aiVolatile.memory.cachedCover);
  if ( idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX) != nullptr )
  {
    EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
    ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
    x = ConfirmedPhysicalSafe->origin.x;
    y = ConfirmedPhysicalSafe->origin.y;
    z = ConfirmedPhysicalSafe->origin.z;
    Physics = idEntity::GetPhysics(this: ai);
    v11 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v12 = (float)((float)(UNITS_PER_INCH_10 * (float)30.0) * (float)12.0);
    if ( (float)((float)((float)(x - *v11) * (float)(x - *v11))
               + (float)((float)((float)(z - v11[2]) * (float)(z - v11[2]))
                       + (float)((float)(y - v11[1]) * (float)(y - v11[1])))) < (double)(float)((float)v12 * (float)v12) )
    {
      v13 = idEntity::GetPhysics(this: ai);
      v13->GetOrigin(this: v13, a2: 0);
    }
    v14 = idEntity::GetPhysics(this: ai);
    v15 = (float *)v14->GetOrigin(this: v14, a2: 0);
    if ( (float)((float)((float)(x - *v15) * (float)(x - *v15))
               + (float)((float)((float)(z - v15[2]) * (float)(z - v15[2]))
                       + (float)((float)(y - v15[1]) * (float)(y - v15[1])))) < (double)decl->maxChargeDistance
      && ai->aiVolatile.memory.coverExposedTime >= 0
      && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
       - ai->aiVolatile.memory.coverExposedTime < decl->repeatExposeCoverChargeTime )
    {
      ai->aiVolatile.groupStatus.condition |= 0x800u;
    }
  }
  ai->aiVolatile.memory.coverExposedTime = idGameTimeManager::GetGameMs(
                                             this: &clientGame->gameTimeManager,
                                             type: GAMETIME_SCALED);
}


// ========================================================================
// ?AIState_EnterState@idInCover_TookDamage@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD5F10
// RVA : 0x00AD5F10
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_TookDamage::AIState_EnterState(
        idInCover_TookDamage *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAIMemory::SetInvalidCover(
    this: &ai->aiVolatile.memory,
    cover: &ai->aiVolatile.memory.currentCover,
    unusableTime: 2500);
  idAI2::SetEnableHeadTracking(this: ai, enable: true);
  ai->aiVolatile.focus.enableBodyRotation = true;
  idAI2::ReleaseCover(this: ai);
  idAICover::idAICover(this: &ai->aiVolatile.memory.cachedCover);
}


// ========================================================================
// ?AIState_EnterState@idInCover_NoContact@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD5F78
// RVA : 0x00AD5F78
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_NoContact::AIState_EnterState(
        idInCover_NoContact *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAIMemory::SetInvalidCover(
    this: &ai->aiVolatile.memory,
    cover: &ai->aiVolatile.memory.currentCover,
    unusableTime: 2500);
  idAI2::SetEnableHeadTracking(this: ai, enable: true);
  ai->aiVolatile.focus.enableBodyRotation = true;
}


// ========================================================================
// ?AIState_EnterState@idInCover_OffCoverPoint@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD5FD0
// RVA : 0x00AD5FD0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_OffCoverPoint::AIState_EnterState(
        idInCover_OffCoverPoint *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAI2::SetEnableHeadTracking(this: ai, enable: true);
  ai->aiVolatile.focus.enableBodyRotation = true;
}


// ========================================================================
// ?Evaluate@IC_ThrowFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD6010
// RVA : 0x00AD6010
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall IC_ThrowFinished::Evaluate(
        IC_ThrowFinished *this,
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
    return TRANSCODE_IC_THROW_FINISHED;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_IC_THROW_FINISHED;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idInCover_Hide@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD6058
// RVA : 0x00AD6058
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Hide::AIState_EnterState(idInCover_Hide *this, idAI2 *ai, idEventArg *fsm, const int curTime)
{
  idEventArg *v7; // r27
  _BYTE v8[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v9[5]; // [sp+90h] [-B0h] BYREF
  int v10; // [sp+B0h] [-90h]
  int v11; // [sp+B4h] [-8Ch]
  idEventArg v12; // [sp+D0h] [-70h] BYREF
  idEventReceiver v13[6]; // [sp+F0h] [-50h] BYREF

  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  HIBYTE(v9[0]) = 105;
  v9[1] = 1000;
  HIBYTE(v10) = 105;
  v11 = 12;
  v7 = idEventArg::idEventArg(this: &v12, data: ai);
  memcpy(Dst: v8, Src: v9, Size: sizeof(v8));
  idEventReceiver::ProcessEvent(
    this: v13,
    result: fsm,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v10, 32));
  idAI2::SetCoverAction(this: ai, action: COVERACTION_HIDE);
}


// ========================================================================
// ?AIState_EnterState@idInCover_Peek@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD6108
// RVA : 0x00AD6108
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Peek::AIState_EnterState(idInCover_Peek *this, idAI2 *ai, idEventArg *fsm, const int curTime)
{
  int RandomInterval; // r28
  idEventArg *v8; // r30
  _BYTE v9[20]; // [sp+70h] [-C0h] BYREF
  _DWORD v10[5]; // [sp+90h] [-A0h] BYREF
  int v11; // [sp+B0h] [-80h]
  coverAction_t coverAction; // [sp+B4h] [-7Ch]
  idEventArg v13; // [sp+D0h] [-60h] BYREF
  idEventReceiver v14[5]; // [sp+F0h] [-40h] BYREF

  RandomInterval = GetRandomInterval(
                     _min: ai->aiEditable.behaviors.decl->minFireFromCoverDuration,
                     _max: ai->aiEditable.behaviors.decl->maxFireFromCoverDuration);
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  v10[1] = RandomInterval;
  HIBYTE(v10[0]) = 105;
  HIBYTE(v11) = 105;
  coverAction = ai->aiVolatile.cover.coverAction;
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
// ?AIState_ExitState@idInCover_Blindfire@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD61C8
// RVA : 0x00AD61C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Blindfire::AIState_ExitState(
        idInCover_Blindfire *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idEncounterGroup *EncounterGroup; // r3

  ai->aiVolatile.groupStatus.condition &= ~0x20u;
  if ( idAI2::GetEncounterGroup(this: ai) != nullptr )
  {
    EncounterGroup = idAI2::GetEncounterGroup(this: ai);
    idEncounterGroup::UpdateFiringConditions(this: EncounterGroup);
  }
}


// ========================================================================
// ??0idInCoverFSM@@QAA@XZ
// EA  : 0x82AD6228
// RVA : 0x00AD6228
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

idInCoverFSM *__fastcall idInCoverFSM::idInCoverFSM(idInCoverFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: "FSM_inCover");
  this->__vftable = (idInCoverFSM_vtbl *)&idInCoverFSM::`vftable';
  idState::idState(this: &this->stateDefault, stateType: &idInCover_Default::Type, childFSMType: nullptr, flags: 0);
  this->stateDefault.__vftable = (idInCover_Default_vtbl *)&idInCover_Default::`vftable';
  idState::idState(this: &this->stateWait, stateType: &idInCover_Wait::Type, childFSMType: nullptr, flags: 0);
  this->stateWait.__vftable = (idInCover_Wait_vtbl *)&idInCover_Wait::`vftable';
  idState::idState(
    this: &this->stateLeaningOut,
    stateType: &idInCover_LeaningOut::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateLeaningOut.__vftable = (idInCover_LeaningOut_vtbl *)&idInCover_LeaningOut::`vftable';
  idState::idState(this: &this->stateLeanIn, stateType: &idInCover_LeanIn::Type, childFSMType: nullptr, flags: 0);
  this->stateLeanIn.__vftable = (idInCover_LeanIn_vtbl *)&idInCover_LeanIn::`vftable';
  idState::idState(this: &this->stateReload, stateType: &idInCover_Reload::Type, childFSMType: nullptr, flags: 0);
  this->stateReload.__vftable = (idInCover_Reload_vtbl *)&idInCover_Reload::`vftable';
  idState::idState(
    this: &this->stateCoverExpired,
    stateType: &idInCover_CoverExpired::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCoverExpired.__vftable = (idInCover_CoverExpired_vtbl *)&idInCover_CoverExpired::`vftable';
  idState::idState(
    this: &this->stateCompromised,
    stateType: &idInCover_Compromised::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCompromised.__vftable = (idInCover_Compromised_vtbl *)&idInCover_Compromised::`vftable';
  idState::idState(
    this: &this->stateEnemyClose,
    stateType: &idInCover_EnemyClose::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateEnemyClose.__vftable = (idInCover_EnemyClose_vtbl *)&idInCover_EnemyClose::`vftable';
  idState::idState(
    this: &this->stateTookDamage,
    stateType: &idInCover_TookDamage::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateTookDamage.__vftable = (idInCover_TookDamage_vtbl *)&idInCover_TookDamage::`vftable';
  idState::idState(this: &this->stateNoContact, stateType: &idInCover_NoContact::Type, childFSMType: nullptr, flags: 0);
  this->stateNoContact.__vftable = (idInCover_NoContact_vtbl *)&idInCover_NoContact::`vftable';
  idState::idState(
    this: &this->stateOffCoverPoint,
    stateType: &idInCover_OffCoverPoint::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateOffCoverPoint.__vftable = (idInCover_OffCoverPoint_vtbl *)&idInCover_OffCoverPoint::`vftable';
  idState::idState(
    this: &this->stateThrowGrenade,
    stateType: &idInCover_ThrowGrenade::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateThrowGrenade.__vftable = (idInCover_ThrowGrenade_vtbl *)&idInCover_ThrowGrenade::`vftable';
  idState::idState(this: &this->stateHide, stateType: &idInCover_Hide::Type, childFSMType: nullptr, flags: 0);
  this->stateHide.__vftable = (idInCover_Hide_vtbl *)&idInCover_Hide::`vftable';
  idState::idState(this: &this->statePeek, stateType: &idInCover_Peek::Type, childFSMType: nullptr, flags: 0);
  this->statePeek.__vftable = (idInCover_Peek_vtbl *)&idInCover_Peek::`vftable';
  idState::idState(this: &this->stateBlindfire, stateType: &idInCover_Blindfire::Type, childFSMType: nullptr, flags: 0);
  this->stateBlindfire.__vftable = (idInCover_Blindfire_vtbl *)&idInCover_Blindfire::`vftable';
  idFiniteStateMachine::SetDefaultState(this, state: &this->stateDefault);
  return this;
}


// ========================================================================
// __unwind$490949_0
// EA  : 0x82AD6494
// RVA : 0x00AD6494
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_490949_0()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$490950_0
// EA  : 0x82AD64BC
// RVA : 0x00AD64BC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_490950_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$490951_0
// EA  : 0x82AD64E8
// RVA : 0x00AD64E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_490951_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$490952_0
// EA  : 0x82AD6514
// RVA : 0x00AD6514
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_490952_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// __unwind$490953_0
// EA  : 0x82AD6540
// RVA : 0x00AD6540
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_490953_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 192));
}


// ========================================================================
// __unwind$490954_0
// EA  : 0x82AD656C
// RVA : 0x00AD656C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_490954_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 220));
}


// ========================================================================
// __unwind$490955_0
// EA  : 0x82AD6598
// RVA : 0x00AD6598
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_490955_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 248));
}


// ========================================================================
// __unwind$490956
// EA  : 0x82AD65C4
// RVA : 0x00AD65C4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_490956()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 276));
}


// ========================================================================
// __unwind$490957
// EA  : 0x82AD65F0
// RVA : 0x00AD65F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_490957()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 304));
}


// ========================================================================
// __unwind$490958
// EA  : 0x82AD661C
// RVA : 0x00AD661C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_490958()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 332));
}


// ========================================================================
// __unwind$490959
// EA  : 0x82AD6648
// RVA : 0x00AD6648
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_490959()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 360));
}


// ========================================================================
// __unwind$490960
// EA  : 0x82AD6674
// RVA : 0x00AD6674
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_490960()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 388));
}


// ========================================================================
// __unwind$490961
// EA  : 0x82AD66A0
// RVA : 0x00AD66A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_490961()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 416));
}


// ========================================================================
// __unwind$490962
// EA  : 0x82AD66CC
// RVA : 0x00AD66CC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_490962()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 444));
}


// ========================================================================
// __unwind$490963
// EA  : 0x82AD66F8
// RVA : 0x00AD66F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_490963()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 472));
}


// ========================================================================
// __unwind$490964_0
// EA  : 0x82AD6724
// RVA : 0x00AD6724
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_490964_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 500));
}


// ========================================================================
// ??1idInCoverFSM@@UAA@XZ
// EA  : 0x82AD6758
// RVA : 0x00AD6758
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCoverFSM::~idInCoverFSM(idInCoverFSM *this)
{
  this->__vftable = (idInCoverFSM_vtbl *)&idInCoverFSM::`vftable';
  idState::~idState(this: &this->stateBlindfire);
  idState::~idState(this: &this->statePeek);
  idState::~idState(this: &this->stateHide);
  idState::~idState(this: &this->stateThrowGrenade);
  idState::~idState(this: &this->stateOffCoverPoint);
  idState::~idState(this: &this->stateNoContact);
  idState::~idState(this: &this->stateTookDamage);
  idState::~idState(this: &this->stateEnemyClose);
  idState::~idState(this: &this->stateCompromised);
  idState::~idState(this: &this->stateCoverExpired);
  idState::~idState(this: &this->stateReload);
  idState::~idState(this: &this->stateLeanIn);
  idState::~idState(this: &this->stateLeaningOut);
  idState::~idState(this: &this->stateWait);
  idState::~idState(this: &this->stateDefault);
  idFiniteStateMachine::~idFiniteStateMachine(this);
}


// ========================================================================
// __unwind$491225
// EA  : 0x82AD681C
// RVA : 0x00AD681C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_491225()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$491226
// EA  : 0x82AD6844
// RVA : 0x00AD6844
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_491226()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// __unwind$491227
// EA  : 0x82AD6870
// RVA : 0x00AD6870
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_491227()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$491228
// EA  : 0x82AD689C
// RVA : 0x00AD689C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_491228()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// __unwind$491229
// EA  : 0x82AD68C8
// RVA : 0x00AD68C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_491229()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 192));
}


// ========================================================================
// __unwind$491230
// EA  : 0x82AD68F4
// RVA : 0x00AD68F4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_491230()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 220));
}


// ========================================================================
// __unwind$491231
// EA  : 0x82AD6920
// RVA : 0x00AD6920
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_491231()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 248));
}


// ========================================================================
// __unwind$491232
// EA  : 0x82AD694C
// RVA : 0x00AD694C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_491232()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 276));
}


// ========================================================================
// __unwind$491233
// EA  : 0x82AD6978
// RVA : 0x00AD6978
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_491233()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 304));
}


// ========================================================================
// __unwind$491234
// EA  : 0x82AD69A4
// RVA : 0x00AD69A4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_491234()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 332));
}


// ========================================================================
// __unwind$491235
// EA  : 0x82AD69D0
// RVA : 0x00AD69D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_491235()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 360));
}


// ========================================================================
// __unwind$491236
// EA  : 0x82AD69FC
// RVA : 0x00AD69FC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_491236()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 388));
}


// ========================================================================
// __unwind$491237
// EA  : 0x82AD6A28
// RVA : 0x00AD6A28
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_491237()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 416));
}


// ========================================================================
// __unwind$491238
// EA  : 0x82AD6A54
// RVA : 0x00AD6A54
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_491238()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 444));
}


// ========================================================================
// __unwind$491239
// EA  : 0x82AD6A80
// RVA : 0x00AD6A80
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_491239()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 472));
}


// ========================================================================
// ?CanUse@idInCoverFSM@@UBA_NPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AD6AB0
// RVA : 0x00AD6AB0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

BOOL __fastcall idInCoverFSM::CanUse(idInCoverFSM *this, idFiniteStateMachine *fsm, const int curTime)
{
  idAI2 *Owner; // r3

  Owner = (idAI2 *)idFiniteStateMachine::GetOwner(this: fsm);
  return idAI2::CastTo(c: Owner)->aiVolatile.cover.coverAction != COVERACTION_NONE;
}


// ========================================================================
// ?Evaluate@IC_ReloadWeapon@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD6AF0
// RVA : 0x00AD6AF0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall IC_ReloadWeapon::Evaluate(
        IC_ReloadWeapon *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  char v5; // r11
  idWeapon *v6; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v8; // zf

  if ( (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeNodeIndex.value >= 0x8000u
    || (v5 = 1, (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeIndex >= 0x8000u) )
  {
    v5 = 0;
  }
  if ( v5 != 0 )
    return 0;
  v6 = ai->GetEquippedWeapon(this: ai);
  if ( v6 == nullptr )
    return 0;
  v8 = v6->NeedsReload(this: v6, a2: false);
  result = TRANSCODE_IC_RELOAD_WEAPON;
  if ( !v8 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@IC_ReloadWeaponSoon@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD6B88
// RVA : 0x00AD6B88
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall IC_ReloadWeaponSoon::Evaluate(
        IC_ReloadWeaponSoon *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  char v5; // r11
  idWeapon *v6; // r3
  double v7; // fp1
  idAIStateTransition::aiTransCode_t result; // r3

  if ( (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeNodeIndex.value >= 0x8000u
    || (v5 = 1, (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeIndex >= 0x8000u) )
  {
    v5 = 0;
  }
  if ( v5 != 0 )
    return 0;
  v6 = ai->GetEquippedWeapon(this: ai);
  if ( v6 == nullptr )
    return 0;
  v7 = ((double (__fastcall *)(idWeapon *, _DWORD))v6->AmmoInClipPercentage)(a1: v6, a2: 0);
  result = TRANSCODE_IC_RELOAD_WEAPON;
  if ( v7 >= 0.30000001 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@IC_ShouldLeanOut@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD6C20
// RVA : 0x00AD6C20
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_ShouldLeanOut::Evaluate(
        IC_ShouldLeanOut *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  char v5; // r11
  coverAction_t coverAction; // r11

  if ( (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeNodeIndex.value >= 0x8000u
    || (v5 = 1, (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeIndex >= 0x8000u) )
  {
    v5 = 0;
  }
  if ( v5 == 0
    && ((coverAction = ai->aiVolatile.cover.coverAction) == COVERACTION_FIRE_LEAN_LEFT
     || coverAction == COVERACTION_FIRE_STEP_LEFT
     || coverAction == COVERACTION_FIRE_LEAN_RIGHT
     || coverAction == COVERACTION_FIRE_STEP_RIGHT
     || coverAction == COVERACTION_FIRE_OVER) )
  {
    return 405;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?Evaluate@IC_CoverExpired@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD6C98
// RVA : 0x00AD6C98
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall IC_CoverExpired::Evaluate(
        IC_CoverExpired *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  char v7; // r11
  char v8; // r11
  idAIStateTransition::aiTransCode_t result; // r3
  idPhysics *Physics; // r3
  const idVec3 *v11; // r30
  idCombatStage *CurrentCombatStage; // r3
  idEncounterGroup *EncounterGroup; // r3
  int exitCoverTime; // r11
  idVec3 v15[5]; // [sp+50h] [-40h] BYREF

  if ( (ai->aiVolatile.groupStatus.condition & 0x200) != 0 )
    return 0;
  if ( (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeNodeIndex.value >= 0x8000u
    || (v7 = 1, (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeIndex >= 0x8000u) )
  {
    v7 = 0;
  }
  if ( v7 != 0 || (unsigned __int8)idAI2::IsIdling(this: ai) == 0 )
    return 0;
  if ( (ai->aiVolatile.groupStatus.condition & 0x200) != 0
    || (v8 = 1, !ai->aiVolatile.groupStatus.roleChangeResponseRequired) )
  {
    v8 = 0;
  }
  if ( v8 != 0 )
    return TRANSCODE_IC_ROLE_CHANGED;
  if ( ai->aiHealth.components[1].max > 0.0
    && ai->aiHealth.components[1].cur <= 0.0
    && idAI2::GetCurrentCombatStage(this: ai) != nullptr )
  {
    Physics = idEntity::GetPhysics(this: ai);
    v11 = Physics->GetOrigin(this: Physics, a2: 0);
    CurrentCombatStage = idAI2::GetCurrentCombatStage(this: ai);
    if ( (unsigned __int8)idCombatStage::GetClosestHintNodePos(
                            this: CurrentCombatStage,
                            hintType: 6u,
                            currentPos: v11,
                            outPos: v15,
                            hintClass: CLASS_ALL) != 0 )
      return TRANSCODE_OC_SHOULD_MOVE_TO_RECHARGE;
  }
  if ( (unsigned __int8)idAICover::IsValid(this: &ai->aiVolatile.memory.currentCover) == 0 )
    return TRANSCODE_IC_COVER_EXPIRED;
  if ( idAI2::GetEncounterGroup(this: ai) != nullptr )
  {
    EncounterGroup = idAI2::GetEncounterGroup(this: ai);
    if ( idEncounterGroup::GetShouldAmbush(this: EncounterGroup) )
    {
      exitCoverTime = curTime + 1000;
      if ( ai->aiVolatile.memory.exitCoverTime > curTime + 1000 )
        exitCoverTime = ai->aiVolatile.memory.exitCoverTime;
      ai->aiVolatile.memory.exitCoverTime = exitCoverTime;
    }
  }
  if ( (unsigned __int8)idAICover::IsExpired(
                          this: &ai->aiVolatile.memory.currentCover,
                          stayTime: curTime - ai->aiVolatile.memory.reachedCoverTime) != 0 )
  {
    idAICover::MakeUnusable(this: &ai->aiVolatile.memory.currentCover, duration: 5000);
    return TRANSCODE_IC_COVER_EXPIRED;
  }
  result = TRANSCODE_IC_COVER_EXPIRED;
  if ( curTime < ai->aiVolatile.memory.exitCoverTime )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@IC_CoverCompromised@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD6EB0
// RVA : 0x00AD6EB0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_CoverCompromised::Evaluate(
        IC_CoverCompromised *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAICover *p_currentCover; // r26
  int v8; // r22
  int i; // r28
  idTargetInfo *v10; // r29
  aiSenseState_t *v11; // r30
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  double v13; // fp31
  const aiPhysicalState_t *v14; // r3
  idPlayer *Entity; // r3
  idPlayer *v16; // r3
  const idPlayerCoverScore_t *CoverScoreInfo; // r3
  idTargetFilter v18[2]; // [sp+58h] [-88h] BYREF

  p_currentCover = &ai->aiVolatile.memory.currentCover;
  if ( (unsigned __int8)idAICover::IsValid(this: &ai->aiVolatile.memory.currentCover) == 0 )
    return 419;
  if ( (*((_BYTE *)&ai->aiEditable.cover + 8) & 0x80) != 0 )
    return 0;
  idEnemyTargetFilter::idEnemyTargetFilter(this: (idEnemyTargetFilter *)v18, minAwareness_: AIAWARE_CONFIRMED);
  v8 = 0;
  if ( ai->aiVolatile.world.worldState.targetCache.targets.num <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v10 = &ai->aiVolatile.world.worldState.targetCache.targets.list[i];
    if ( idTargetFilter::Filter(this: v18, owner: ai, ti: v10) && v10->es != nullptr )
    {
      v11 = v10->es->senses.ptr[v10->es->lastSense];
      if ( v11->lastUnconfirmedStimTime >= 0
        && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
         - v11->lastConfirmedStimTime < 5000 )
      {
        ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v11);
        if ( !idAICover::IsPointInFrontOf(this: p_currentCover, point: &ConfirmedPhysicalSafe->origin) )
          return 419;
        v13 = idCoverQuery::MAX_COVER_ARC_ACOS_DEGREES;
        v14 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v11);
        if ( !idAICover::IsPointInArc(this: p_currentCover, point: &v14->origin, arcAcos: v13) )
          return 419;
      }
      if ( !idAICover::IsPartiallyExposed(this: p_currentCover)
        && !idAICover::IsFullyExposed(this: p_currentCover)
        && g_usePlayerCoverCheck.valueInteger != 0 )
      {
        Entity = (idPlayer *)idAIEntityState::GetEntity(this: (idAIEntityState *)v10->es);
        v16 = idPlayer::CastTo(c: Entity);
        if ( v16 != nullptr )
        {
          CoverScoreInfo = idPlayer::GetCoverScoreInfo(this: v16, coverIndex: p_currentCover->coverIndex);
          if ( CoverScoreInfo != nullptr
            && CoverScoreInfo->standingScore > (double)ai_deferredVisCheckThreshold.valueFloat )
          {
            break;
          }
        }
      }
    }
    if ( ++v8 >= ai->aiVolatile.world.worldState.targetCache.targets.num )
      return 0;
  }
  return 419;
}


// ========================================================================
// __unwind$492347
// EA  : 0x82AD70A0
// RVA : 0x00AD70A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_492347()
{
  int v0; // r12

  idAvoidTargetFilter::~idAvoidTargetFilter(this: (idFriendlyDeadTargetFilter *)(v0 - 224 + 88));
}


// ========================================================================
// ?Evaluate@IC_OffCoverPoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD70C8
// RVA : 0x00AD70C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_OffCoverPoint::Evaluate(
        IC_OffCoverPoint *this,
        _exception *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  char v7; // r11
  idAICover *v8; // r30
  idAI2 *Entity; // r3
  idAI2 *v10; // r3
  idAI2 *v11; // r29
  idPhysics *Physics; // r3
  float *v13; // r3
  idPhysics *v15; // r29
  idAIMoveState *MoveInterface; // r28
  idAIMoveState_vtbl *v17; // r31
  double v18; // fp31
  int v19; // r29
  const aas2Cover_t *Origin; // r3
  char v21; // [sp+58h] [-48h] BYREF

  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) == 0 && SHIDWORD(ai[204].arg2) > curTime )
    return 0;
  if ( LOWORD(ai[516].arg2) >= 0x8000u || (v7 = 1, HIWORD(ai[516].retval) >= 0x8000u) )
    v7 = 0;
  if ( v7 != 0 )
    return 0;
  v8 = (idAICover *)((char *)&ai[909].arg1 + 4);
  if ( (unsigned __int8)idAICover::IsValid(this: (idAICover *)((char *)&ai[909].arg1 + 4)) == 0 )
    return 0;
  if ( (unsigned __int8)idAI2::IsIdling(this: (idAI2 *)ai) == 0 )
  {
    if ( DWORD2(ai[909].arg1) == 0x1FFF )
      return 0;
    Entity = (idAI2 *)idEventArg::GetEntity(this: (idAICover *)((char *)&ai[909].arg1 + 4));
    v10 = idAI2::CastTo(c: Entity);
    v11 = v10;
    if ( v10 == nullptr )
      return 0;
    Physics = idEntity::GetPhysics(this: v10);
    v13 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v21, result: (idVec3 *)Physics, a3: 0);
    if ( (float)((float)(v13[2] * v13[2]) + (float)((float)(*v13 * *v13) + (float)(v13[1] * v13[1]))) < 1.0
      && idAI2::GetBodyOrientation(this: v11)->currentTurnDir == 0 )
    {
      return 0;
    }
  }
  v15 = idEntity::GetPhysics(this: (idEntity *)ai);
  MoveInterface = idAI2::GetMoveInterface(this: (idAI2 *)ai);
  v17 = MoveInterface->__vftable;
  v18 = REACHED_COVER_TOLERANCE;
  v19 = (int)v15->GetOrigin(this: v15, a2: 0);
  Origin = idAICover::GetOrigin(this: v8);
  return ((unsigned __int8 (__fastcall *)(idAIMoveState *, const aas2Cover_t *, int, double))v17->PointInMovementRange)(
           a1: MoveInterface,
           a2: Origin,
           a3: v19,
           a4: v18) != 0
       ? 0
       : 0x1A4;
}


// ========================================================================
// ?Evaluate@IC_ThrowGrenade@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD7280
// RVA : 0x00AD7280
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_ThrowGrenade::Evaluate(
        IC_ThrowGrenade *this,
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
    return 0;
  v11[0] = -1;
  v6 = idTrajectory_Parabolic::SelectTrajectory(trajectories: ai->aiVolatile.trajectories.ptr, num: 4, parmsIndex: v11);
  if ( v6 == nullptr )
  {
    idAI2::ClearTrajectoryResults(this: ai);
    return 0;
  }
  p_gravity = (_DWORD *)&v6->GetTrajectoryParms_2(this: v6, a2: v11[0])[-1].gravity;
  v8 = &ai->aiVolatile.memory.projectileInfo.linearParms.gravity;
  for ( i = 7; i != 0; --i )
    *++v8 = *(float *)++p_gravity;
  idAI2::ClearTrajectoryResults(this: ai);
  return 431;
}


// ========================================================================
// ?Evaluate@IC_ShouldHide@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD7348
// RVA : 0x00AD7348
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall IC_ShouldHide::Evaluate(
        IC_ShouldHide *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  char v5; // r11
  idAIStateTransition::aiTransCode_t result; // r3

  if ( (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeNodeIndex.value >= 0x8000u
    || (v5 = 1, (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeIndex >= 0x8000u) )
  {
    v5 = 0;
  }
  if ( v5 != 0 )
    return 0;
  result = TRANSCODE_IC_SHOULD_HIDE;
  if ( ai->aiVolatile.cover.coverAction != COVERACTION_HIDE )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@IC_ShouldPeek@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD73A0
// RVA : 0x00AD73A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_ShouldPeek::Evaluate(
        IC_ShouldPeek *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  char v5; // r11
  coverAction_t coverAction; // r11

  if ( (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeNodeIndex.value >= 0x8000u
    || (v5 = 1, (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeIndex >= 0x8000u) )
  {
    v5 = 0;
  }
  if ( v5 == 0
    && ((coverAction = ai->aiVolatile.cover.coverAction) == COVERACTION_PEEK_LEFT
     || coverAction == COVERACTION_PEEK_RIGHT
     || coverAction == COVERACTION_PEEK_OVER) )
  {
    return 416;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?Evaluate@IC_ShouldBlindfire@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD7408
// RVA : 0x00AD7408
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_ShouldBlindfire::Evaluate(
        IC_ShouldBlindfire *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  char v5; // r11
  coverAction_t coverAction; // r11

  if ( (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeNodeIndex.value >= 0x8000u
    || (v5 = 1, (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeIndex >= 0x8000u) )
  {
    v5 = 0;
  }
  if ( v5 == 0
    && ((coverAction = ai->aiVolatile.cover.coverAction) == COVERACTION_BLINDFIRE_LEFT
     || coverAction == COVERACTION_BLINDFIRE_RIGHT
     || coverAction == COVERACTION_BLINDFIRE_OVER) )
  {
    return 417;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?AIState_EnterState@idInCover_LeanIn@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD7478
// RVA : 0x00AD7478
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_LeanIn::AIState_EnterState(
        idInCover_LeanIn *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  __int64 v7; // r8
  __int64 v8; // r10
  va *v9; // r3
  idEventArg *v10; // r27
  int v11; // [sp+8h] [-11E8h]
  int v12; // [sp+Ch] [-11E4h]
  int v13; // [sp+10h] [-11E0h]
  int v14; // [sp+14h] [-11DCh]
  int v15; // [sp+18h] [-11D8h]
  int v16; // [sp+1Ch] [-11D4h]
  _BYTE v17[20]; // [sp+70h] [-1180h] BYREF
  _BYTE v18[20]; // [sp+90h] [-1160h] BYREF
  idStr v19; // [sp+B0h] [-1140h] BYREF
  idStr v20; // [sp+D0h] [-1120h] BYREF
  int v21; // [sp+F0h] [-1100h]
  char *data; // [sp+F4h] [-10FCh]
  const idEventArg *v23; // [sp+F8h] [-10F8h]
  _DWORD v24[5]; // [sp+110h] [-10E0h] BYREF
  _DWORD v25[5]; // [sp+130h] [-10C0h] BYREF
  idStr v26; // [sp+150h] [-10A0h] BYREF
  idEventReceiver v27[2]; // [sp+170h] [-1080h] BYREF
  idEventArg v28; // [sp+190h] [-1060h] BYREF
  va v29; // [sp+1B0h] [-1040h] BYREF

  v19.len = 0;
  v19.allocedAndFlag = 20;
  v19.data = v19.baseBuffer;
  v19.baseBuffer[0] = 0;
  idAI2::GetSubWebPrefix(this: ai, swt: (const aiSubWeb_t)ai->aiVolatile.animation.subWeb, subWebPrefix: &v19);
  v20.allocedAndFlag = 20;
  v20.len = 0;
  v20.data = v20.baseBuffer;
  v20.baseBuffer[0] = 0;
  idAI2::GetIdleStateName(this: ai, name: &v20);
  HIDWORD(v7) = "1 - formation cover, such as behind regime shield units";
  v9 = va::va(
         this: &v29,
         fmt: "%s:%s",
         a3: __SPAIR64__((unsigned int)v19.data, (unsigned int)v20.data),
         a4: v7,
         a5: v8,
         a6: v11,
         a7: v12,
         a8: v13,
         a9: v14,
         a10: v15,
         a11: v16);
  idStr::idStr(this: &v26, text: v9);
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  HIBYTE(v25[0]) = 105;
  v25[1] = 1;
  HIBYTE(v24[0]) = 105;
  v24[1] = 1;
  HIBYTE(v21) = 115;
  data = v26.data;
  v10 = idEventArg::idEventArg(this: &v28, data: ai);
  memcpy(Dst: v18, Src: v25, Size: sizeof(v18));
  memcpy(Dst: v17, Src: v24, Size: sizeof(v17));
  idEventReceiver::ProcessEvent(
    this: v27,
    result: fsm,
    ev: *(const idEventDef **)&v10->type,
    arg1: (const idEventArg *)LODWORD(v10->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v10->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v21, 32),
    arg4: v23);
  idStr::FreeData(this: &v26);
  idStr::FreeData(this: &v20);
  idStr::FreeData(this: &v19);
}


// ========================================================================
// __unwind$492655_0
// EA  : 0x82AD75D4
// RVA : 0x00AD75D4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_492655_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 176));
}


// ========================================================================
// __unwind$492656_0
// EA  : 0x82AD75FC
// RVA : 0x00AD75FC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_492656_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 208));
}


// ========================================================================
// __unwind$492657
// EA  : 0x82AD7624
// RVA : 0x00AD7624
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_492657()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 336));
}


// ========================================================================
// ?AIState_EnterState@idInCover_ThrowGrenade@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD7658
// RVA : 0x00AD7658
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_ThrowGrenade::AIState_EnterState(
        idInCover_ThrowGrenade *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  const idDeclAnimWeb *decl; // r29
  int value; // r11
  idDeclAnimWebNode *v9; // r11
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v10; // r26
  char *StateName; // r25
  char *SubWebName; // r3
  idEventArg *v13; // r3
  idEventArg v14; // [sp+90h] [-A0h] BYREF
  idEventReceiver v15[2]; // [sp+B0h] [-80h] BYREF
  idStr v16[3]; // [sp+D0h] [-60h] BYREF

  decl = ai->aiVolatile.animation.animWebAnimator.ptr[0].decl;
  value = ai->aiVolatile.memory.projectileInfo.nodeIndex.value;
  if ( value != -1 && (v9 = decl->nodes.list[value]) != nullptr )
  {
    v16[0].len = 0;
    v16[0].allocedAndFlag = 20;
    v16[0].data = v16[0].baseBuffer;
    v16[0].baseBuffer[0] = 0;
    v10 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v9->subWebIndex.value;
    StateName = (char *)idDeclAnimWeb::GetStateName(
                          this: decl,
                          index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v9->states.stateIndex[0].value);
    SubWebName = (char *)idDeclAnimWeb::GetSubWebName(this: decl, index: v10);
    idAnimWebPath::SetPath(
      this: (idAnimWebPath *)v16,
      webName: &byte_8200D768,
      subWebName: SubWebName,
      stateName: StateName);
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    v13 = idEventArg::idEventArg(this: &v14, data: ai);
    idEventReceiver::ProcessEvent(
      this: v15,
      result: fsm,
      ev: *(const idEventDef **)&v13->type,
      arg1: (const idEventArg *)LODWORD(v13->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v13->value.v[2]));
    idStr::FreeData(this: v16);
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// __unwind$492777_0
// EA  : 0x82AD7784
// RVA : 0x00AD7784
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_492777_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 208));
}


// ========================================================================
// ?Evaluate@IC_TookDamage@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD7810
// RVA : 0x00AD7810
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_TookDamage::Evaluate(
        IC_TookDamage *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r10
  idEntity *v8; // r3
  idActor *v9; // r3
  idActor *v10; // r4
  idAIEntityState *v12; // r3
  aiSenseState_t *v13; // r11

  if ( ai->aiVolatile.memory.lastDamageTime <= ai->aiVolatile.memory.reachedCoverTime )
    return 0;
  value = ai->aiVolatile.memory.lastAttacker.spawnId.value;
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
  if ( v10 != nullptr
    && (v12 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v10)) != nullptr
    && (v13 = v12->senses.ptr[1])->lastUnconfirmedStimTime >= 0
    && curTime - v13->lastConfirmedStimTime < 5000 )
  {
    return 0;
  }
  else
  {
    return 414;
  }
}


// ========================================================================
// ?Evaluate@IC_EnemyClose@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD78F0
// RVA : 0x00AD78F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_EnemyClose::Evaluate(
        IC_EnemyClose *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r4
  idVec3 *v9; // r4
  idAIEntityState *v10; // r3
  const idDeclAIBehavior *decl; // r30
  idPhysics *Physics; // r3
  float *v13; // r3
  double v14; // fp0
  const idAAS2 *v15; // r3
  idAASPosition *AASPosition; // r27
  unsigned int v17; // r22
  idAAS2 *aas; // r20
  int travelFlags; // r19
  idAAS2_vtbl *v20; // r31
  int AreaNum; // r3
  int (*RW)(void); // ctr
  int v23; // r3
  idColor *v24; // r4
  float v26; // [sp+60h] [-F0h] BYREF
  float v27; // [sp+64h] [-ECh]
  float v28; // [sp+68h] [-E8h]
  idVec3 v29; // [sp+70h] [-E0h] BYREF
  float v30[22]; // [sp+80h] [-D0h] BYREF

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
  v10 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8);
  if ( v10 == nullptr )
    return 0;
  decl = ai->aiEditable.behaviors.decl;
  aiSenseState_t::ExtrapolatePosition(this: v10->senses.ptr[v10->lastSense], seconds: 0.5, futurePos: v9);
  Physics = idEntity::GetPhysics(this: ai);
  v13 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v14 = (float)((float)((float)(v26 - *v13) * (float)(v26 - *v13))
              + (float)((float)((float)(v28 - v13[2]) * (float)(v28 - v13[2]))
                      + (float)((float)(v27 - v13[1]) * (float)(v27 - v13[1]))));
  if ( v14 >= (float)(decl->exposeCoverDistance * decl->exposeCoverDistance)
    || v14 >= (float)(decl->exposeCoverMinDistance * decl->exposeCoverMinDistance) )
  {
    return 0;
  }
  v15 = ai->GetAAS(this: ai);
  memset(&v30[4], 0, 12);
  v30[10] = 0.0;
  v30[0] = 0.0;
  AASPosition = (idAASPosition *)idActor::GetAASPosition(this: ai, aas: v15);
  v30[1] = 0.0;
  v30[2] = 0.0;
  v17 = 0;
  v30[3] = 0.0;
  v30[11] = 0.0;
  v30[7] = 0.0;
  memset(&v30[15], 0, 24);
  v30[8] = 0.0;
  v30[9] = 0.0;
  v30[12] = 0.0;
  v30[13] = 0.0;
  v30[14] = 0.0;
  while ( 1 )
  {
    if ( (unsigned __int8)idAICover::GetExposedPoint(
                            this: &ai->aiVolatile.memory.currentCover,
                            fp: v17,
                            exposedPoint: &v29) != 0 )
    {
      aas = (idAAS2 *)AASPosition->aas;
      travelFlags = ai->aiVolatile.aas.travelFlags;
      v20 = aas->__vftable;
      AreaNum = idAASPosition::GetAreaNum(this: AASPosition);
      ((void (__fastcall *)(idAAS2 *, float *, idVec3 *, int, float *, int, _DWORD, int))v20->TraceFloor)(
        a1: aas,
        a2: v30,
        a3: &v29,
        a4: AreaNum,
        a5: &v26,
        a6: travelFlags,
        a7: 0,
        a8: 1);
      if ( ai_debugCover.valueInteger > 1 && ai_debugLevel.valueInteger > 0 )
      {
        RW = (int (*)(void))common->RW;
        if ( v30[0] < 1.0 )
        {
          v23 = RW();
          v24 = &idColor::colorGreen;
        }
        else
        {
          v23 = RW();
          v24 = &idColor::colorRed;
        }
        (*(void (__fastcall **)(int, idColor *, idVec3 *, float *, double))(*(_DWORD *)v23 + 180))(
          a1: v23,
          a2: v24,
          a3: &v29,
          a4: &v26,
          a5: 1.0);
      }
      if ( v30[0] >= 1.0 )
        break;
    }
    if ( (int)++v17 >= 3 )
      return 0;
  }
  return 418;
}


// ========================================================================
// ?Evaluate@IC_NoContact@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD7BC0
// RVA : 0x00AD7BC0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall IC_NoContact::Evaluate(
        IC_NoContact *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r4
  idAIEntityState *v10; // r3
  const idDeclAIBehavior *decl; // r11
  int noContactInterval; // r31
  idAIStateTransition::aiTransCode_t result; // r3
  bool v14; // zf

  if ( (unsigned __int8)idAI2::IsIdling(this: ai) == 0 )
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
  if ( v10->lastVisible > 2u )
    return 0;
  decl = ai->aiEditable.behaviors.decl;
  if ( curTime - ai->aiVolatile.memory.reachedCoverTime < decl->minCoverDuration )
    return 0;
  noContactInterval = decl->noContactInterval;
  v14 = curTime - aiSenseState_t::GetConfirmedStimTimeSafe(this: v10->senses.ptr[v10->lastSense]) > noContactInterval;
  result = TRANSCODE_IC_NO_CONTACT;
  if ( !v14 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idInCover_Wait@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD7CC8
// RVA : 0x00AD7CC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Wait::AIState_EnterState(idInCover_Wait *this, idAI2 *ai, idEventArg *fsm, const int curTime)
{
  idAICover *p_currentCover; // r30
  idAIFireControl **p_fireControl; // r29
  idPhysics *Physics; // r3
  idAIFireControl *v10; // r3
  int value; // r8
  idEntity *v12; // r3
  idEntity *v13; // r4
  idAIOrientation *BodyOrientation; // r3
  int v15; // r29
  const aas2Cover_t *Origin; // r3
  float y; // r9
  float z; // r8
  idPhysics *v19; // r3
  int v20; // r6
  idEventArg *v21; // r29
  _BYTE v22[20]; // [sp+70h] [-130h] BYREF
  idVec3 v23[2]; // [sp+90h] [-110h] BYREF
  int v24; // [sp+B0h] [-F0h]
  int v25; // [sp+B4h] [-ECh]
  idMat3 v26; // [sp+D0h] [-D0h] BYREF
  idEventArg v27; // [sp+100h] [-A0h] BYREF
  idEventReceiver v28[2]; // [sp+120h] [-80h] BYREF
  idMat3 v29[2]; // [sp+140h] [-60h] BYREF

  p_currentCover = &ai->aiVolatile.memory.currentCover;
  if ( idAICover::IsFullyExposed(this: &ai->aiVolatile.memory.currentCover) )
    ai->aiVolatile.animation.subWeb = AISUBWEB_COMBAT;
  else
    ai->aiVolatile.animation.subWeb = AISUBWEB_FCOVER;
  ai->SetLeanState(this: ai, a2: LEAN_NONE);
  p_fireControl = &ai->aiVolatile.fireControl;
  ai->aiVolatile.fireControl->allowReloads = true;
  idAI2::SetCoverAction(this: ai, action: COVERACTION_NONE);
  if ( (unsigned __int8)idAICover::IsValid(this: p_currentCover) != 0 )
  {
    idAICover::GetAxis(this: p_currentCover, axis: v29);
    Physics = idEntity::GetPhysics(this: ai);
    Physics->GetGravityNormal(this: Physics);
    idAICover::GetOrigin(this: p_currentCover);
    v10 = *p_fireControl;
    if ( ai->aiVolatile.cover.coverOrientation == COVERORIENT_BACKWARD )
    {
      idAIFireControl::SetFireMode(this: v10, owner: ai, mode: FIREMODE_HOLDFIRE);
      idAI2::SetEnableHeadTracking(this: ai, enable: false);
      idAI2::ClearAimFocus(this: ai);
      idAI2::ClearLookFocus(this: ai);
    }
    else
    {
      idAIFireControl::SetFireMode(this: v10, owner: ai, mode: FIREMODE_FIREWHENREADY);
      idAI2::SetEnableHeadTracking(this: ai, enable: true);
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
      idAI2::SetAimFocusEntity(this: ai, ent: v13, keepFocusInView: false, aimPoint: AIMPOINT_BEST, timeout: -1);
    }
    idAIFireControl::SetFireMode(this: *p_fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
    idAICover::GetOrientation(
      this: p_currentCover,
      orient: (const coverOrientation_t)ai->aiVolatile.cover.coverOrientation,
      axis: &v26);
    BodyOrientation = idAI2::GetBodyOrientation(this: ai);
    idAIOrientation::SetIdealDir(this: BodyOrientation, ai, dir: v26.mat);
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) == 0 )
    {
      v15 = GameFramesToTicks(frameNum: 10, type: GAMETIME_SCALED);
      Origin = idAICover::GetOrigin(this: p_currentCover);
      y = Origin->origin.y;
      z = Origin->origin.z;
      v23[0].x = Origin->origin.x;
      v23[0].y = y;
      v23[0].z = z;
      v19 = idEntity::GetPhysics(this: ai);
      v23[0].z = v19->GetOrigin(this: v19, a2: 0)->z;
      idAIMoveState::StartLerpToPoint(
        this: &ai->aiVolatile.physics.moveState,
        dest: v23,
        tolerance: 0.1,
        maxLerpDist: REACHED_COVER_LERP_TOLERANCE,
        lerpDurationMS: (const int)&joystick.joyAxis[0][2],
        lerpAxisFlags_: v20,
        a7: v15,
        a8: 3);
    }
  }
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  HIBYTE(v23[0].x) = 105;
  LODWORD(v23[0].y) = 2;
  HIBYTE(v24) = 105;
  v25 = -1;
  v21 = idEventArg::idEventArg(this: &v27, data: ai);
  memcpy(Dst: v22, Src: v23, Size: sizeof(v22));
  idEventReceiver::ProcessEvent(
    this: v28,
    result: fsm,
    ev: *(const idEventDef **)&v21->type,
    arg1: (const idEventArg *)LODWORD(v21->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v21->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v24, 32));
}


// ========================================================================
// ?CoverActionHelper@@YA?AW4coverAction_t@@PAVidAI2@@H_N111@Z
// EA  : 0x82AD7FA8
// RVA : 0x00AD7FA8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall CoverActionHelper(
        idAI2 *ai,
        int curTime,
        const bool considerFire,
        bool considerHide,
        const bool considerPeek,
        const bool considerBlindfire)
{
  const idDeclAIBehavior *decl; // r24
  idWeapon *(__fastcall *GetEquippedWeapon)(struct idAI2 *); // ctr
  int v11; // r3
  int v12; // r26
  unsigned __int8 v13; // r11
  int v14; // r25
  char v15; // r11
  idAIOrientation *BodyOrientation; // r3
  const idEntity *Enemy; // r4
  idAIEntityState *v19; // r3
  int lastSense; // r10
  aiSenseState_t *v21; // r28
  idAIOrientation *v22; // r3
  float y; // r7
  float z; // r6
  const idVec3 *Dir; // r3
  posture_t CoverPosture; // r22
  coverOrientation_t coverOrientation; // r21
  idPhysics *Physics; // r3
  float *v29; // r3
  double v30; // fp11
  double v31; // fp10
  double v32; // fp7
  double v33; // fp6
  double v34; // fp31
  double v35; // fp30
  double v36; // fp29
  const aas2Cover_t *Origin; // r3
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  coverAction_t *v39; // r10
  __int64 v40; // r9
  int i; // ctr
  char b_high; // r15
  bool HasCoverCapability; // r3
  char c_high; // r19
  bool v45; // r29
  bool v46; // r23
  bool v47; // r18
  bool v48; // r27
  idPhysics *v49; // r3
  float *v50; // r22
  const aiPhysicalState_t *v51; // r3
  double v52; // fp10
  double v53; // fp6
  bool v54; // r10
  BOOL v55; // r22
  bool v56; // r17
  int (__fastcall *v57)(int, _DWORD); // r7
  bool v58; // r20
  bool v59; // r21
  char v60; // r19
  bool v61; // r11
  int aimCoverHideChance; // r10
  bool v63; // r15
  char v64; // r24
  bool v65; // r29
  char v66; // r26
  char v67; // r25
  int v68; // r10
  bool v69; // r11
  bool v70; // r14
  bool v71; // r11
  bool v72; // r18
  bool v73; // zf
  bool v74; // r11
  bool v75; // r10
  posture_t v76; // r25
  int v77; // r23
  char v78; // r11
  char v79; // r24
  coverOrientation_t v80; // r22
  int v81; // r27
  char v82; // r10
  char v83; // r11
  int v84; // r29
  coverAction_t coverActionToAvoid; // r11
  int v86; // r29
  char v87; // r10
  char v88; // r11
  bool v89; // r3
  unsigned int v90; // r26
  int v91; // r10
  bool v92; // r8
  int v93; // r29
  char v94; // r10
  char v95; // r11
  int v96; // r10
  bool v97; // r11
  int v98; // r29
  char v99; // r10
  char v100; // r11
  int v101; // r9
  bool v102; // r10
  int v103; // r29
  char v104; // r10
  char v105; // r11
  int v106; // r10
  bool v107; // r11
  _DWORD *v108; // r11
  int j; // ctr
  _DWORD *v110; // r11
  int k; // ctr
  int v112; // r8
  int v113; // r4
  int v114; // r11
  int v115; // ctr
  int *v116; // r9
  int *v117; // r7
  unsigned __int8 *v118; // r10
  int v119; // r5
  int v120; // r3
  coverAction_t v121; // r29
  idPhysics *v122; // r30
  idRenderWorld *v123; // r28
  idPhysics *v124; // r3
  idRenderWorld_vtbl *v125; // r30
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v127; // r3
  idCoverCapabilities v128; // [sp+60h] [-1E0h] BYREF
  coverAction_t coverAction; // [sp+6Ch] [-1D4h]
  coverOrientation_t v130; // [sp+70h] [-1D0h]
  int v131; // [sp+74h] [-1CCh]
  idPlane v132; // [sp+80h] [-1C0h] BYREF
  planeSide_t v133; // [sp+90h] [-1B0h]
  posture_t v134; // [sp+94h] [-1ACh]
  bool v135; // [sp+98h] [-1A8h]
  idCoverActions v136; // [sp+A0h] [-1A0h] BYREF
  coverAction_t v137; // [sp+A8h] [-198h] BYREF
  int v138; // [sp+B0h] [-190h] BYREF
  char v139; // [sp+B4h] [-18Ch] BYREF
  _BYTE v140[71]; // [sp+B5h] [-18Bh] BYREF
  int v141; // [sp+FCh] [-144h] BYREF
  _DWORD v142[11]; // [sp+100h] [-140h] BYREF
  int v143; // [sp+12Ch] [-114h] BYREF
  _DWORD v144[12]; // [sp+130h] [-110h] BYREF
  idMat3 v145; // [sp+160h] [-E0h] BYREF

  decl = ai->aiEditable.behaviors.decl;
  GetEquippedWeapon = ai->GetEquippedWeapon;
  v137 = COVERACTION_NONE;
  v11 = (int)GetEquippedWeapon(this: ai);
  v12 = v11;
  if ( v11 == 0 || (v13 = 1, *(_DWORD *)(v11 + 72) != 3) )
    v13 = 0;
  v14 = v13;
  if ( v13 != 0 )
    goto LABEL_169;
  if ( (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeNodeIndex.value >= 0x8000u
    || (v15 = 1, (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeIndex >= 0x8000u) )
  {
    v15 = 0;
  }
  if ( v15 == 0 )
  {
LABEL_169:
    if ( v11 != 0 )
    {
      BodyOrientation = idAI2::GetBodyOrientation(this: ai);
      if ( idAIOrientation::IsAligned(this: BodyOrientation)
        && (unsigned __int8)idAICover::IsValid(this: &ai->aiVolatile.memory.currentCover) != 0 )
      {
        Enemy = idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
        if ( Enemy != nullptr )
        {
          v19 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: Enemy);
          if ( v19 != nullptr )
          {
            lastSense = v19->lastSense;
            if ( lastSense != 2 )
            {
              v21 = v19->senses.ptr[lastSense];
              v22 = idAI2::GetBodyOrientation(this: ai);
              y = v22->axis.mat[0].y;
              z = v22->axis.mat[0].z;
              v132.a = v22->axis.mat[0].x;
              v132.b = y;
              v132.c = z;
              Dir = idAICover::GetDir(this: &ai->aiVolatile.memory.currentCover);
              if ( (float)((float)(Dir->x * v132.a) + (float)((float)(Dir->y * v132.b) + (float)(Dir->z * v132.c))) >= 0.70709997 )
              {
                CoverPosture = idAICover::GetCoverPosture(this: &ai->aiVolatile.memory.currentCover);
                v134 = CoverPosture;
                coverOrientation = ai->aiVolatile.cover.coverOrientation;
                v130 = coverOrientation;
                idAICover::GetAxis(this: &ai->aiVolatile.memory.currentCover, axis: &v145);
                Physics = idEntity::GetPhysics(this: ai);
                v29 = (float *)Physics->GetGravityNormal(this: Physics);
                v30 = v29[2];
                v31 = *v29;
                v32 = (float)(v145.mat[0].z * *v29);
                v33 = (float)(v145.mat[0].x * v29[1]);
                v34 = (float)((float)(v145.mat[0].z * v29[1]) - (float)(v145.mat[0].y * v29[2]));
                v35 = (float)((float)(v145.mat[0].x * v29[2]) - (float)(v145.mat[0].z * *v29));
                v132.a = (float)(v145.mat[0].z * v29[1]) - (float)(v145.mat[0].y * v29[2]);
                v132.b = (float)(v145.mat[0].x * (float)v30) - (float)v32;
                v36 = (float)((float)(v145.mat[0].y * (float)v31) - (float)v33);
                v132.c = (float)(v145.mat[0].y * (float)v31) - (float)v33;
                Origin = idAICover::GetOrigin(this: &ai->aiVolatile.memory.currentCover);
                v132.d = -(float)((float)((float)v34 * Origin->origin.x)
                                + (float)((float)(Origin->origin.y * (float)v35) + (float)(Origin->origin.z * (float)v36)));
                ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v21);
                v133 = idPlane::Side(this: &v132, v: &ConfirmedPhysicalSafe->origin, epsilon: 0.0);
                v39 = &v137;
                LODWORD(v40) = 0;
                for ( i = 10; i != 0; --i )
                {
                  v39 += 2;
                  *(_QWORD *)v39 = v40;
                }
                coverAction = COVERACTION_NONE;
                *((_BYTE *)&v136 + 4) &= 7u;
                v136.__vftable = (idCoverActions_vtbl *)&idCoverActions::`vftable';
                idAICover::GetCoverActions(this: &ai->aiVolatile.memory.currentCover, actions: &v136);
                HIBYTE(v132.b) &= 7u;
                LODWORD(v132.a) = &idCoverCapabilities::`vftable';
                HIBYTE(v132.c) &= 1u;
                idCoverCapabilities::Promote(this: (idCoverCapabilities *)&v132, actions: &v136);
                v128.__vftable = (idCoverCapabilities_vtbl *)&idCoverCapabilities::`vftable';
                b_high = HIBYTE(v132.b);
                *((_BYTE *)&v128 + 8) &= 1u;
                *((_BYTE *)&v128.idCoverActions + 4) = HIBYTE(v132.b) & 0x80 | *((_BYTE *)&v128.idCoverActions + 4) & 7;
                v131 = HIBYTE(v132.b);
                HasCoverCapability = idAIBehaviors::HasCoverCapability(
                                       this: &ai->aiEditable.behaviors,
                                       ai,
                                       coverPosture: CoverPosture,
                                       coverOrientation,
                                       coverCaps: &v128);
                c_high = HIBYTE(v132.c);
                v45 = HasCoverCapability;
                *((_BYTE *)&v128.idCoverActions + 4) &= 7u;
                *((_BYTE *)&v128 + 8) = HIBYTE(v132.c) & 0x1C | *((_BYTE *)&v128 + 8) & 1;
                v46 = idAIBehaviors::HasCoverCapability(
                        this: &ai->aiEditable.behaviors,
                        ai,
                        coverPosture: CoverPosture,
                        coverOrientation,
                        coverCaps: &v128);
                *((_BYTE *)&v128.idCoverActions + 4) &= 7u;
                *((_BYTE *)&v128 + 8) = c_high & 2 | *((_BYTE *)&v128 + 8) & 1;
                v47 = idAIBehaviors::HasCoverCapability(
                        this: &ai->aiEditable.behaviors,
                        ai,
                        coverPosture: CoverPosture,
                        coverOrientation,
                        coverCaps: &v128);
                *((_BYTE *)&v128.idCoverActions + 4) &= 7u;
                *((_BYTE *)&v128 + 8) = c_high & 0xE0 | *((_BYTE *)&v128 + 8) & 1;
                v48 = idAIBehaviors::HasCoverCapability(
                        this: &ai->aiEditable.behaviors,
                        ai,
                        coverPosture: CoverPosture,
                        coverOrientation,
                        coverCaps: &v128);
                v49 = idEntity::GetPhysics(this: ai);
                v50 = (float *)v49->GetOrigin(this: v49, a2: 0);
                v51 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v21);
                v54 = false;
                if ( v14 == 0 )
                {
                  if ( curTime >= ai->aiVolatile.memory.nextCoverActionTime
                    && (ai->aiVolatile.groupStatus.condition & 0x100) == 0
                    || (ai->aiVolatile.groupStatus.condition & 0x200) != 0
                    || (v52 = (float)(v51->origin.y - v50[1]),
                        (float)((float)((float)(v53 = (float)(v51->origin.z - v50[2])) * (float)v53)
                              + (float)((float)((float)(v51->origin.x - *v50) * (float)(v51->origin.x - *v50))
                                      + (float)((float)v52 * (float)v52))) < 160000.0) )
                  {
                    v54 = true;
                  }
                }
                v56 = v54;
                v57 = *(int (__fastcall **)(int, _DWORD))(*(_DWORD *)v12 + 136);
                v58 = (ai->aiVolatile.groupStatus.condition & 2) != 0;
                v59 = (ai->aiVolatile.groupStatus.condition & 0x10) != 0;
                v135 = (ai->aiVolatile.groupStatus.condition & 8) != 0;
                v55 = v135;
                v60 = v57(a1: v12, a2: 0);
                v61 = v55
                   || !v45
                   || (ai->aiVolatile.groupStatus.condition & 0x400) != 0
                   && ((b_high & 0x10) != 0 || (b_high & 0x40) != 0);
                aimCoverHideChance = decl->dodging.aimCoverHideChance;
                v63 = v61;
                if ( aimCoverHideChance != 0
                  || decl->dodging.aimHeavyCoverHideChance != 0
                  || decl->dodging.gunfireCoverHideChance != 0
                  || decl->dodging.damageCoverHideChance != 0 )
                {
                  LOBYTE(aimCoverHideChance) = 1;
                }
                v64 = aimCoverHideChance;
                v65 = considerHide;
                v66 = ((curTime - ai->aiVolatile.memory.lastDamageTime >= 0)
                     + ((unsigned int)(curTime - ai->aiVolatile.memory.lastDamageTime) >= 0x7D0))
                    & 1;
                v67 = (((ai->aiVolatile.memory.endHeavyAimedAtTime ^ curTime) >= 0)
                     + ((unsigned int)curTime >= ai->aiVolatile.memory.endHeavyAimedAtTime))
                    & 1;
                if ( (unsigned __int8)idAI2::CanHideHelmetGroupTest(this: ai) == 0 )
                {
                  v65 = false;
                  v67 = 0;
                }
                v68 = curTime - v21->lastConfirmedStimTime;
                v69 = v48 && considerBlindfire && v60 == 0 && v56 && !v55 && v64 != 0 && (v59 || v66 != 0 || v67 != 0);
                v70 = v69;
                v71 = v46
                   && considerPeek
                   && v60 == 0
                   && v56
                   && !v55
                   && !v59
                   && ((((v68 >= 0) + ((unsigned int)v68 >= 0x7D0)) & 1) == 0
                    || v68 >= 1000
                    && (curTime - ai->aiVolatile.memory.lastFiredAtTime < 5000
                     || curTime - ai->aiVolatile.memory.lastAimedAtTime < 5000));
                v73 = !v47;
                v72 = v71;
                v74 = !v73 && v65 && !v70 && !v55 && v64 != 0 && (v66 != 0 || v59 || v58 || v67 != 0);
                v75 = v74;
                if ( !considerFire || v60 != 0 || v67 != 0 && v64 != 0 || !v56 )
                {
                  v76 = v134;
                  v77 = v131;
                }
                else
                {
                  v76 = v134;
                  v77 = v131;
                  if ( !v55 || v134 != POSTURE_CROUCHED || (v131 & 0x10) != 0 || (v131 & 0x40) != 0 )
                  {
                    v78 = 1;
                    goto LABEL_86;
                  }
                }
                v78 = 0;
LABEL_86:
                v79 = v78;
                if ( !v75 )
                {
                  if ( (v77 & 0xFFFFFF80) == 0
                    || v63
                    || (v81 = 1,
                        v82 = *((_BYTE *)&v128.idCoverActions + 4) & 7,
                        v83 = *((_BYTE *)&v128 + 8) & 1,
                        *((_BYTE *)&v128.idCoverActions + 4) &= 7u,
                        v84 = 1,
                        *((_BYTE *)&v128 + 8) &= 1u,
                        v55) )
                  {
                    v80 = v130;
                  }
                  else
                  {
                    if ( v70 )
                    {
                      v84 = 6;
                      *((_BYTE *)&v128 + 8) = v83 | 0x20;
                    }
                    else if ( v72 )
                    {
                      v84 = 9;
                      *((_BYTE *)&v128 + 8) = v83 | 4;
                    }
                    else if ( v79 != 0 )
                    {
                      *((_BYTE *)&v128.idCoverActions + 4) = v82 | 0x80;
                    }
                    v80 = v130;
                    if ( idAIBehaviors::HasCoverCapability(
                           this: &ai->aiEditable.behaviors,
                           ai,
                           coverPosture: v76,
                           coverOrientation: v130,
                           coverCaps: &v128) )
                    {
                      coverActionToAvoid = ai->aiVolatile.cover.coverActionToAvoid;
                      v138 = v84;
                      v139 = 1;
                      v140[0] = (_cntlzw(coverActionToAvoid - 1) & 0x20) != 0;
LABEL_103:
                      if ( (v77 & 0x40) != 0 )
                      {
                        v86 = 2;
                        v87 = *((_BYTE *)&v128.idCoverActions + 4) & 7;
                        v88 = *((_BYTE *)&v128 + 8) & 1;
                        *((_BYTE *)&v128.idCoverActions + 4) &= 7u;
                        *((_BYTE *)&v128 + 8) &= 1u;
                        if ( v70 )
                        {
                          v86 = 7;
                          *((_BYTE *)&v128 + 8) = v88 | 0x80;
                        }
                        else if ( v72 )
                        {
                          v86 = 10;
                          *((_BYTE *)&v128 + 8) = v88 | 0x10;
                        }
                        else if ( v79 != 0 )
                        {
                          *((_BYTE *)&v128.idCoverActions + 4) = v87 | 0x40;
                        }
                        v89 = idAIBehaviors::HasCoverCapability(
                                this: &ai->aiEditable.behaviors,
                                ai,
                                coverPosture: v76,
                                coverOrientation: v80,
                                coverCaps: &v128);
                        v90 = v133;
                        if ( v89 )
                        {
                          v91 = 8 * v81;
                          v92 = (_cntlzw(ai->aiVolatile.cover.coverActionToAvoid - 2) & 0x20) != 0;
                          v140[v91 - 1] = (_cntlzw(v133 - 1) & 0x20) != 0;
                          ++v81;
                          v140[v91] = v92;
                          *(int *)((char *)&v138 + v91) = v86;
                        }
                      }
                      else
                      {
                        v90 = v133;
                      }
                      if ( (v77 & 0x10) != 0 )
                      {
                        v93 = 3;
                        v94 = *((_BYTE *)&v128.idCoverActions + 4) & 7;
                        v95 = *((_BYTE *)&v128 + 8) & 1;
                        *((_BYTE *)&v128.idCoverActions + 4) &= 7u;
                        *((_BYTE *)&v128 + 8) &= 1u;
                        if ( v70 )
                        {
                          v93 = 8;
                          *((_BYTE *)&v128 + 8) = v95 | 0x40;
                        }
                        else if ( v72 )
                        {
                          v93 = 11;
                          *((_BYTE *)&v128 + 8) = v95 | 8;
                        }
                        else if ( v79 != 0 )
                        {
                          *((_BYTE *)&v128.idCoverActions + 4) = v94 | 0x10;
                        }
                        if ( idAIBehaviors::HasCoverCapability(
                               this: &ai->aiEditable.behaviors,
                               ai,
                               coverPosture: v76,
                               coverOrientation: v80,
                               coverCaps: &v128) )
                        {
                          v96 = 8 * v81;
                          v97 = (_cntlzw(ai->aiVolatile.cover.coverActionToAvoid - 3) & 0x20) != 0;
                          v140[v96 - 1] = (_cntlzw(v90) & 0x20) != 0;
                          ++v81;
                          v140[v96] = v97;
                          *(int *)((char *)&v138 + v96) = v93;
                        }
                      }
                      if ( (v77 & 0x20) != 0 )
                      {
                        v98 = 4;
                        v99 = *((_BYTE *)&v128.idCoverActions + 4) & 7;
                        v100 = *((_BYTE *)&v128 + 8) & 1;
                        *((_BYTE *)&v128.idCoverActions + 4) &= 7u;
                        *((_BYTE *)&v128 + 8) &= 1u;
                        if ( v70 )
                        {
                          v98 = 7;
                          *((_BYTE *)&v128 + 8) = v100 | 0x40;
                        }
                        else if ( v72 )
                        {
                          v98 = 10;
                          *((_BYTE *)&v128 + 8) = v100 | 8;
                        }
                        else if ( v79 != 0 )
                        {
                          *((_BYTE *)&v128.idCoverActions + 4) = v99 | 0x20;
                        }
                        if ( idAIBehaviors::HasCoverCapability(
                               this: &ai->aiEditable.behaviors,
                               ai,
                               coverPosture: v76,
                               coverOrientation: v80,
                               coverCaps: &v128) )
                        {
                          v101 = 8 * v81;
                          v102 = (_cntlzw(ai->aiVolatile.cover.coverActionToAvoid - 2) & 0x20) != 0;
                          v140[v101 - 1] = (_cntlzw(v90 - 1) & 0x20) != 0;
                          ++v81;
                          v140[v101] = v102;
                          *(int *)((char *)&v138 + v101) = v98;
                        }
                      }
                      if ( (v77 & 8) != 0 )
                      {
                        v103 = 5;
                        v104 = *((_BYTE *)&v128.idCoverActions + 4) & 7;
                        v105 = *((_BYTE *)&v128 + 8) & 1;
                        *((_BYTE *)&v128.idCoverActions + 4) &= 7u;
                        *((_BYTE *)&v128 + 8) &= 1u;
                        if ( v70 )
                        {
                          v103 = 8;
                          *((_BYTE *)&v128 + 8) = v105 | 0x40;
                        }
                        else if ( v72 )
                        {
                          v103 = 11;
                          *((_BYTE *)&v128 + 8) = v105 | 8;
                        }
                        else if ( v79 != 0 )
                        {
                          *((_BYTE *)&v128.idCoverActions + 4) = v104 | 8;
                        }
                        if ( idAIBehaviors::HasCoverCapability(
                               this: &ai->aiEditable.behaviors,
                               ai,
                               coverPosture: v76,
                               coverOrientation: v80,
                               coverCaps: &v128) )
                        {
                          v106 = 8 * v81;
                          v107 = (_cntlzw(ai->aiVolatile.cover.coverActionToAvoid - 3) & 0x20) != 0;
                          v140[v106 - 1] = (_cntlzw(v90) & 0x20) != 0;
                          ++v81;
                          v140[v106] = v107;
                          *(int *)((char *)&v138 + v106) = v103;
                        }
                      }
                      goto LABEL_141;
                    }
                  }
                  v81 = coverAction;
                  goto LABEL_103;
                }
                v80 = v130;
                *((_BYTE *)&v128.idCoverActions + 4) &= 7u;
                *((_BYTE *)&v128 + 8) = *((_BYTE *)&v128 + 8) & 1 | 2;
                if ( idAIBehaviors::HasCoverCapability(
                       this: &ai->aiEditable.behaviors,
                       ai,
                       coverPosture: v76,
                       coverOrientation: v130,
                       coverCaps: &v128) )
                {
                  v81 = 1;
                  v139 = 1;
                  v138 = 12;
                  v140[0] = 0;
                  coverAction = ai->aiVolatile.cover.coverAction;
                  if ( coverAction != COVERACTION_NONE )
                    idAI2::RememberCoverActionToAvoid(this: ai, coverAction);
                }
                else
                {
                  v81 = coverAction;
                }
LABEL_141:
                v108 = v144;
                v144[0] = 0;
                for ( j = 9; j != 0; --j )
                  *++v108 = 0;
                v110 = v142;
                v142[0] = 0;
                for ( k = 9; k != 0; --k )
                  *++v110 = 0;
                v112 = 0;
                v113 = 0;
                v114 = 0;
                if ( v81 <= 0 )
                  goto LABEL_159;
                v115 = v81;
                v116 = &v143;
                v117 = &v141;
                v118 = v140;
                do
                {
                  if ( *(v118 - 1) != 0 )
                  {
                    v119 = *v118;
                    ++v112;
                    *++v116 = v114;
                    if ( v119 == 0 )
                    {
                      *++v117 = v114;
                      ++v113;
                    }
                  }
                  ++v114;
                  v118 += 8;
                  --v115;
                }
                while ( v115 != 0 );
                if ( v112 <= 0 )
                {
LABEL_159:
                  v120 = idRandom2::RandomInt(this: &clientGame->random, max: v81);
                }
                else if ( v112 == 1 )
                {
                  v120 = v144[0];
                }
                else if ( v113 <= 0 )
                {
                  v120 = v144[idRandom2::RandomInt(this: &clientGame->random, max: v112)];
                }
                else if ( v113 == 1 )
                {
                  v120 = v142[0];
                }
                else
                {
                  v120 = v142[idRandom2::RandomInt(this: &clientGame->random, max: v113)];
                }
                if ( v81 <= 0 )
                  v121 = v137;
                else
                  v121 = AdjustCoverActionForOrientation(
                           coverAction: (coverAction_t)*(&v138 + 2 * v120),
                           coverOrientation: v80);
                if ( ai_debugLevel.valueInteger > 0 && ai_debugCoverActions.valueInteger != 0 )
                {
                  v122 = idEntity::GetPhysics(this: ai);
                  v123 = common->RW(this: common);
                  v124 = v122;
                  GetOrigin = v122->GetOrigin;
                  v125 = v123->__vftable;
                  v127 = (int)GetOrigin(this: v124, a2: 0);
                  ((void (__fastcall *)(idRenderWorld *, const char *, int, _DWORD, idColor *, int, int, _DWORD, double))v125->DebugText)(
                    a1: v123,
                    a2: coverActionNames[v121],
                    a3: v127,
                    a4: 0,
                    a5: &idColor::colorOrange,
                    a6: 1,
                    a7: 15,
                    a8: 0,
                    a9: 0.5);
                }
                return v121;
              }
            }
          }
        }
      }
    }
  }
  return 17;
}


// ========================================================================
// __unwind$493725
// EA  : 0x82AD8EAC
// RVA : 0x00AD8EAC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_493725()
{
  int v0; // r12

  idCoverActions::~idCoverActions(this: (idCoverActions *)(v0 - 576 + 160));
}


// ========================================================================
// __unwind$493726
// EA  : 0x82AD8ED4
// RVA : 0x00AD8ED4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_493726()
{
  int v0; // r12

  idCoverActions::~idCoverActions(this: (idCoverActions *)(v0 - 576 + 128));
}


// ========================================================================
// __unwind$493727
// EA  : 0x82AD8EFC
// RVA : 0x00AD8EFC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_493727()
{
  int v0; // r12

  idCoverActions::~idCoverActions(this: (idCoverActions *)(v0 - 576 + 96));
}


// ========================================================================
// ?AIState_Work@idInCover_Wait@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD8F28
// RVA : 0x00AD8F28
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Wait::AIState_Work(idInCover_Wait *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  coverAction_t v6; // r27
  const idDeclAIBehavior *decl; // r29
  const idEntity *Enemy; // r4
  idAIEntityState *v9; // r3
  int lastSense; // r10
  aiSenseState_t *v11; // r30
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  const aiPhysicalState_t *v13; // r3
  const aiPhysicalState_t *v14; // r3
  float y; // r4
  float z; // r11
  idEncounterGroup *EncounterGroup; // r3
  int curCombatStage; // r11
  idEncounterGroup *v19; // r3
  int v20; // r11
  idCombatStage *v21; // r3
  coverAction_t v22; // r3
  voChainState_t voChainCategory; // r11
  idEncounterGroup *v24; // r3
  idEncounterGroup *v25; // r3
  idEncounterGroup *v26; // r3
  idVec3 v27; // [sp+50h] [-C0h] BYREF
  idVec3 v28; // [sp+60h] [-B0h] BYREF
  idAIProjectileInfo v29; // [sp+70h] [-A0h] BYREF

  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0
    || ai->aiVolatile.physics.moveState.endLerpTime <= curTime )
  {
    v6 = CoverActionHelper(
           ai,
           curTime,
           considerFire: true,
           considerHide: true,
           considerPeek: true,
           considerBlindfire: true);
    if ( v6 != COVERACTION_MAX )
    {
      if ( idAI2::CanThrowGrenade(this: ai, condition: AISELECTCONDITION_COVER)
        && (ai->aiVolatile.groupStatus.condition & 0x400) != 0 )
      {
        decl = ai->aiEditable.behaviors.decl;
        Enemy = idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
        if ( Enemy == nullptr )
          return;
        v9 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: Enemy);
        if ( v9 == nullptr )
          return;
        lastSense = v9->lastSense;
        if ( lastSense == 2 )
          return;
        v11 = v9->senses.ptr[lastSense];
        idAIProjectileInfo::idAIProjectileInfo(this: &v29);
        ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v11);
        v29.actualTargetPos.x = ConfirmedPhysicalSafe->origin.x;
        v29.actualTargetPos.y = ConfirmedPhysicalSafe->origin.y;
        v29.actualTargetPos.z = ConfirmedPhysicalSafe->origin.z;
        v13 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v11);
        v29.actualTargetVel.x = v13->velocity.x;
        v29.actualTargetVel.y = v13->velocity.y;
        v29.actualTargetVel.z = v13->velocity.z;
        v14 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v11);
        y = v14->origin.y;
        z = v14->origin.z;
        v27.x = v14->origin.x;
        v27.y = y;
        v27.z = z;
        if ( idAI2::GetEncounterGroup(this: ai) != nullptr )
        {
          EncounterGroup = idAI2::GetEncounterGroup(this: ai);
          curCombatStage = EncounterGroup->curCombatStage;
          if ( curCombatStage >= 0
            && curCombatStage < EncounterGroup->combatStages.num
            && &EncounterGroup->combatStages.list[curCombatStage] != nullptr )
          {
            v19 = idAI2::GetEncounterGroup(this: ai);
            v20 = v19->curCombatStage;
            if ( v20 < 0 || v20 >= v19->combatStages.num )
              v21 = nullptr;
            else
              v21 = &v19->combatStages.list[v20];
            if ( (unsigned __int8)idCombatStage::GetClosestHintNodePos(
                                    this: v21,
                                    hintType: 5u,
                                    currentPos: &v27,
                                    outPos: &v28,
                                    hintClass: CLASS_ALL) != 0 )
            {
              v27.x = v28.x;
              v27.y = v28.y;
              v27.z = v28.z;
            }
          }
          v22 = CoverActionHelper(
                  ai,
                  curTime,
                  considerFire: true,
                  considerHide: false,
                  considerPeek: false,
                  considerBlindfire: false);
          if ( (unsigned __int8)idAI2::SelectThrowable(
                                  this: ai,
                                  selectorType: decl->itemSelect[2],
                                  targetPos: &v27,
                                  coverAction: v22,
                                  info: &v29) != 0 )
          {
            if ( (unsigned __int8)idAI2::CheckGrenadeThrow(this: ai, info: &v29) != 0 )
            {
              voChainCategory = ai->aiVolatile.groupStatus.voChainCategory;
              if ( voChainCategory != VOCHAIN_NONE )
              {
                if ( voChainCategory != VOCHAIN_ORDER_GRENADE
                  || ai->aiVolatile.groupStatus.voChainState == VOCHAIN_ORDER_GRENADE )
                {
                  ai->aiVolatile.groupStatus.voChainCategory = VOCHAIN_NONE;
                  ai->aiVolatile.groupStatus.voChainState = VOCHAIN_NONE;
                  idAIProjectileInfo::operator=(this: &ai->aiVolatile.memory.projectileInfo, __that: &v29);
                  ai->aiVolatile.memory.nextThrowTime = GetRandomInterval(
                                                          _min: ai->aiEditable.behaviors.decl->minThrowInterval,
                                                          _max: ai->aiEditable.behaviors.decl->maxThrowInterval)
                                                      + curTime;
                  v25 = idAI2::GetEncounterGroup(this: ai);
                  idEncounterGroup::SetLivingMemberCondition(this: v25, condition: 1024, value: false);
                  v26 = idAI2::GetEncounterGroup(this: ai);
                  idEncounterGroup::BumpNextGrenadeTime(this: v26);
                }
              }
              else
              {
                ai->aiVolatile.groupStatus.voChainCategory = VOCHAIN_ORDER_GRENADE;
                ai->aiVolatile.groupStatus.voChainState = VOCHAIN_DELAYED_VO;
                v24 = idAI2::GetEncounterGroup(this: ai);
                idEncounterGroup::SetLivingMemberCondition(this: v24, condition: 1024, value: false);
                ai->aiVolatile.groupStatus.condition |= 0x400u;
              }
              return;
            }
          }
          else
          {
            ai->aiVolatile.groupStatus.condition &= ~0x400u;
          }
        }
      }
      if ( v6 != COVERACTION_NONE )
        idAI2::SetCoverAction(this: ai, action: v6);
    }
  }
}


// ========================================================================
// ?Evaluate@IC_AvoidFire@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD9288
// RVA : 0x00AD9288
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall IC_AvoidFire::Evaluate(
        IC_AvoidFire *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  const idDeclAIBehavior *decl; // r30
  signed int gunfireCoverHideChance; // r10
  idAI2::aiCondition_t condition; // r11
  unsigned int v10; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v12; // zf

  decl = ai->aiEditable.behaviors.decl;
  gunfireCoverHideChance = 0;
  condition = ai->aiVolatile.groupStatus.condition;
  if ( (condition & 8) != 0 || (condition & 0x200) != 0 )
    return 0;
  if ( parentFSM->eventId == 2 )
  {
    if ( (unsigned __int8)idAI2::CanHideHelmetGroupTest(this: ai) == 0 )
      return 0;
    if ( curTime - ai->aiVolatile.memory.lastDamageTime >= 100 )
      gunfireCoverHideChance = decl->dodging.gunfireCoverHideChance;
    else
      gunfireCoverHideChance = decl->dodging.damageCoverHideChance;
  }
  v10 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v10;
  if ( (int)(((v10 >> 10) & 0x7FFF) % 0x64) >= gunfireCoverHideChance )
    return 0;
  v12 = CoverActionHelper(
          ai,
          curTime,
          considerFire: false,
          considerHide: true,
          considerPeek: false,
          considerBlindfire: false) == 12;
  result = TRANSCODE_IC_SHOT_AT;
  if ( !v12 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idInCover_LeaningOut@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD9398
// RVA : 0x00AD9398
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_LeaningOut::AIState_EnterState(
        idInCover_LeaningOut *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r4
  int RandomInterval; // r3
  idAI2_vtbl *v11; // r10
  int v12; // r29
  const idWeapon *v13; // r3
  const idWeapon *v14; // r30
  coverAction_t coverAction; // r30
  idEventArg *v16; // r27
  idEncounterGroup *EncounterGroup; // r3
  _BYTE v18[20]; // [sp+70h] [-E0h] BYREF
  int v19; // [sp+90h] [-C0h] BYREF
  int v20[11]; // [sp+94h] [-BCh] BYREF
  int v21; // [sp+C0h] [-90h]
  coverAction_t v22; // [sp+C4h] [-8Ch]
  idEventArg v23; // [sp+E0h] [-70h] BYREF
  idEventReceiver v24[6]; // [sp+100h] [-50h] BYREF

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
  RandomInterval = GetRandomInterval(
                     _min: ai->aiEditable.behaviors.decl->minFireFromCoverDuration,
                     _max: ai->aiEditable.behaviors.decl->maxFireFromCoverDuration);
  v11 = ai->__vftable;
  v12 = RandomInterval;
  v20[0] = 1000;
  v19 = 1000;
  v13 = v11->GetEquippedWeapon(this: ai);
  v14 = v13;
  if ( v13 != nullptr )
  {
    idAI2::GetBurstDuration(this: ai, weapon: v13, min: v20, max: &v19);
    idAIFireControl::InhibitFire(this: ai->aiVolatile.fireControl, weapon: v14, inhibitLength: 500);
    idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
  }
  if ( v19 > v12 )
    v12 = v19;
  if ( (ai->aiVolatile.groupStatus.condition & 8) != 0 )
    v12 = 10000;
  coverAction = ai->aiVolatile.cover.coverAction;
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  v20[4] = v12;
  v22 = coverAction;
  HIBYTE(v20[3]) = 105;
  HIBYTE(v21) = 105;
  v16 = idEventArg::idEventArg(this: &v23, data: ai);
  memcpy(Dst: v18, Src: &v20[3], Size: sizeof(v18));
  idEventReceiver::ProcessEvent(
    this: v24,
    result: fsm,
    ev: *(const idEventDef **)&v16->type,
    arg1: (const idEventArg *)LODWORD(v16->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v16->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v21, 32));
  ai->aiVolatile.groupStatus.condition |= 0x20u;
  if ( idAI2::GetEncounterGroup(this: ai) != nullptr )
  {
    EncounterGroup = idAI2::GetEncounterGroup(this: ai);
    idEncounterGroup::UpdateFiringConditions(this: EncounterGroup);
  }
}


// ========================================================================
// ?AIState_Work@idInCover_LeaningOut@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD9580
// RVA : 0x00AD9580
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_LeaningOut::AIState_Work(idInCover_LeaningOut *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  coverAction_t v5; // r3

  v5 = CoverActionHelper(
         ai,
         curTime,
         considerFire: true,
         considerHide: false,
         considerPeek: false,
         considerBlindfire: false);
  if ( v5 != COVERACTION_NONE
    && v5 != COVERACTION_MAX
    && v5 != COVERACTION_FIRE_LEAN_LEFT
    && v5 != COVERACTION_FIRE_LEAN_RIGHT
    && v5 != COVERACTION_FIRE_OVER )
  {
    idAI2::SetCoverAction(this: ai, action: v5);
  }
}


// ========================================================================
// ?AIState_EnterState@idInCover_Compromised@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD95F8
// RVA : 0x00AD95F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Compromised::AIState_EnterState(
        idInCover_Compromised *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  const idDeclAIBehavior *decl; // r26
  aiSenseState_t *EnemySenseState; // r28
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  idPhysics *Physics; // r3
  float *v10; // r3
  double v11; // fp5
  idPhysics *v12; // r3
  idPhysics *v13; // r3
  float *v14; // r3
  unsigned int v15; // r4
  int value; // r8
  idEntity *v17; // r3
  idEntity *v18; // r4
  idAIEntityState *v19; // r3
  aiSenseState_t *v20; // r30
  idPhysics *v21; // r3
  float *v22; // r29
  const aiPhysicalState_t *v23; // r3
  double v24; // fp8
  double v25; // fp6
  float x; // [sp+50h] [-70h]
  float y; // [sp+54h] [-6Ch]
  float z; // [sp+58h] [-68h]

  decl = ai->aiEditable.behaviors.decl;
  idAI2::SetEnableHeadTracking(this: ai, enable: true);
  ai->aiVolatile.focus.enableBodyRotation = true;
  EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
  idAIMemory::SetInvalidCover(
    this: &ai->aiVolatile.memory,
    cover: &ai->aiVolatile.memory.currentCover,
    unusableTime: 2500);
  if ( EnemySenseState != nullptr )
  {
    ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
    x = ConfirmedPhysicalSafe->origin.x;
    y = ConfirmedPhysicalSafe->origin.y;
    z = ConfirmedPhysicalSafe->origin.z;
    Physics = idEntity::GetPhysics(this: ai);
    v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v11 = (float)((float)(UNITS_PER_INCH_10 * (float)30.0) * (float)12.0);
    if ( (float)((float)((float)(x - *v10) * (float)(x - *v10))
               + (float)((float)((float)(z - v10[2]) * (float)(z - v10[2]))
                       + (float)((float)(y - v10[1]) * (float)(y - v10[1])))) < (double)(float)((float)v11 * (float)v11) )
    {
      v12 = idEntity::GetPhysics(this: ai);
      v12->GetOrigin(this: v12, a2: 0);
    }
    v13 = idEntity::GetPhysics(this: ai);
    v14 = (float *)v13->GetOrigin(this: v13, a2: 0);
    if ( (float)((float)((float)(x - *v14) * (float)(x - *v14))
               + (float)((float)((float)(z - v14[2]) * (float)(z - v14[2]))
                       + (float)((float)(y - v14[1]) * (float)(y - v14[1])))) < (double)decl->maxChargeDistance
      && ai->aiVolatile.memory.coverExposedTime >= 0
      && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
       - ai->aiVolatile.memory.coverExposedTime < decl->repeatExposeCoverChargeTime )
    {
      ai->aiVolatile.groupStatus.condition |= 0x800u;
    }
  }
  ai->aiVolatile.memory.coverExposedTime = idGameTimeManager::GetGameMs(
                                             this: &clientGame->gameTimeManager,
                                             type: GAMETIME_SCALED);
  v15 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v15;
  if ( (signed int)(((v15 >> 10) & 0x7FFF) % 0x64) < decl->exposeCoverOpenCombatChance )
  {
    value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v17 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v18 = idEntity::CastTo(c: v17);
    }
    else
    {
      v18 = nullptr;
    }
    v19 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v18);
    if ( v19 != nullptr )
    {
      v20 = v19->senses.ptr[v19->lastSense];
      v21 = idEntity::GetPhysics(this: ai);
      v22 = (float *)v21->GetOrigin(this: v21, a2: 0);
      v23 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v20);
      v24 = (float)(v23->origin.y - v22[1]);
      v25 = (float)(v23->origin.z - v22[2]);
      if ( (float)((float)((float)(v23->origin.x - *v22) * (float)(v23->origin.x - *v22))
                 + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) < (double)(float)(decl->exposeCoverDistance * decl->exposeCoverDistance) )
        ai->aiVolatile.memory.endOpenCombatTime = curTime - (int)(float)(decl->openCombatDuration * (float)-1000.0);
    }
  }
  idAI2::ReleaseCover(this: ai);
  idAICover::idAICover(this: &ai->aiVolatile.memory.cachedCover);
}


// ========================================================================
// ?Evaluate@IC_HideFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD9960
// RVA : 0x00AD9960
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall IC_HideFinished::Evaluate(
        IC_HideFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  int v5; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v7; // zf

  v5 = CoverActionHelper(
         ai,
         curTime,
         considerFire: true,
         considerHide: true,
         considerPeek: true,
         considerBlindfire: true);
  if ( v5 == 12 )
    return 0;
  v7 = v5 != 17;
  result = TRANSCODE_IC_HIDE_FINISHED;
  if ( !v7 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@IC_HideTakingDamage@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD99B0
// RVA : 0x00AD99B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall IC_HideTakingDamage::Evaluate(
        IC_HideTakingDamage *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  const idDeclAIBehavior *decl; // r29
  unsigned int gunfireHideBailChance; // r31
  idAICover *p_currentCover; // r28
  idAIMemory *p_memory; // r30
  idEntity *LastAttacker; // r3
  idPhysics *Physics; // r3
  const idVec3 *v12; // r3
  __int64 v13; // r5
  double v14; // fp1
  __int64 v15; // r7
  unsigned int v16; // r9

  decl = ai->aiEditable.behaviors.decl;
  gunfireHideBailChance = 0;
  if ( parentFSM->eventId == 2 )
  {
    if ( curTime - ai->aiVolatile.memory.lastDamageTime >= 100 )
    {
      gunfireHideBailChance = decl->dodging.gunfireHideBailChance;
    }
    else
    {
      gunfireHideBailChance = decl->dodging.damageHideBailChance;
      p_currentCover = &ai->aiVolatile.memory.currentCover;
      if ( (unsigned __int8)idAICover::IsValid(this: &ai->aiVolatile.memory.currentCover) != 0 )
      {
        p_memory = &ai->aiVolatile.memory;
        if ( idAIMemory::GetLastAttacker(this: p_memory) != nullptr )
        {
          LastAttacker = idAIMemory::GetLastAttacker(this: p_memory);
          Physics = idEntity::GetPhysics(this: LastAttacker);
          v12 = Physics->GetOrigin(this: Physics, a2: 0);
          v14 = idAICover::AngleToPoint(this: p_currentCover, point: v12, considerFireOver: false);
          gunfireHideBailChance = decl->dodging.damageHideBailChance;
          if ( v14 > 0.0 )
          {
            HIDWORD(v15) = decl->dodging.damageHideBailMaxChance - gunfireHideBailChance;
            LODWORD(v15) = decl->dodging.damageHideBailChance;
            LODWORD(v13) = HIDWORD(v15);
            gunfireHideBailChance = (int)(float)((float)((float)((float)v13 * (float)v14)
                                                       / (float)((float)110.0 * (float)0.5))
                                               + (float)v15);
          }
        }
      }
    }
  }
  v16 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v16;
  return ((__PAIR64__(gunfireHideBailChance >> 31, ((v16 >> 10) & 0x7FFF) % 0x64) - gunfireHideBailChance) >> 32)
       & 0x19A;
}


// ========================================================================
// ?AIState_Work@idInCover_Hide@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD9B40
// RVA : 0x00AD9B40
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Hide::AIState_Work(idInCover_Hide *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  coverAction_t v5; // r3

  v5 = CoverActionHelper(
         ai,
         curTime,
         considerFire: true,
         considerHide: true,
         considerPeek: true,
         considerBlindfire: true);
  if ( v5 != COVERACTION_MAX && v5 != COVERACTION_HIDE )
    idAI2::SetCoverAction(this: ai, action: v5);
}


// ========================================================================
// ?Evaluate@IC_PeekFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD9BA0
// RVA : 0x00AD9BA0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_PeekFinished::Evaluate(
        IC_PeekFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  idFiniteStateMachine *FullPath; // r3
  const idEntity *Enemy; // r3
  idAIEntityState *v12; // r3
  aiSenseState_t *v13; // r11

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v9) != nullptr
    && (FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state)) != nullptr
    && idFiniteStateMachine::GetStatus(this: FullPath) != 0
    && ((Enemy = idAIMemory::GetEnemy(this: &ai->aiVolatile.memory),
         (v12 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: Enemy)) == nullptr)
     || (v13 = v12->senses.ptr[1])->lastUnconfirmedStimTime < 0
     || curTime - v13->lastConfirmedStimTime >= 1000) )
  {
    return (((unsigned int)(curTime - ai->aiVolatile.memory.lastFiredAtTime)
           - __PAIR64__((unsigned int)(curTime - ai->aiVolatile.memory.lastFiredAtTime) >> 31, 500)) >> 32)
         & 0x1B2;
  }
  else
  {
    return 434;
  }
}


// ========================================================================
// ?AIState_Work@idInCover_Peek@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD9CB0
// RVA : 0x00AD9CB0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Peek::AIState_Work(idInCover_Peek *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  coverAction_t v5; // r3

  v5 = CoverActionHelper(
         ai,
         curTime,
         considerFire: true,
         considerHide: true,
         considerPeek: true,
         considerBlindfire: true);
  if ( v5 != COVERACTION_NONE
    && v5 != COVERACTION_MAX
    && v5 != COVERACTION_PEEK_LEFT
    && v5 != COVERACTION_PEEK_RIGHT
    && v5 != COVERACTION_PEEK_OVER )
  {
    idAI2::SetCoverAction(this: ai, action: v5);
  }
}


// ========================================================================
// ?Evaluate@IC_BlindfireFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD9D28
// RVA : 0x00AD9D28
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

int __fastcall IC_BlindfireFinished::Evaluate(
        IC_BlindfireFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  char v8; // r11
  idWeapon *v9; // r3

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( FullPath != nullptr && idFiniteStateMachine::GetStatus(this: FullPath) != 0 )
    return 0;
  if ( (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeNodeIndex.value >= 0x8000u
    || (v8 = 1, (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeIndex >= 0x8000u) )
  {
    v8 = 0;
  }
  if ( v8 != 0 )
    return 0;
  v9 = ai->GetEquippedWeapon(this: ai);
  if ( v9 != nullptr && v9->NeedsReload(this: v9, a2: false) )
    return 408;
  if ( CoverActionHelper(
         ai,
         curTime,
         considerFire: false,
         considerHide: true,
         considerPeek: false,
         considerBlindfire: false) == 12 )
    return 415;
  return 435;
}


// ========================================================================
// ?AIState_EnterState@idInCover_Blindfire@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD9E38
// RVA : 0x00AD9E38
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void __fastcall idInCover_Blindfire::AIState_EnterState(
        idInCover_Blindfire *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  posture_t v8; // r3
  posture_t v9; // r3
  idEventArg *v10; // r3
  const idDeclAIBehavior *decl; // r28
  aiSkill_t ModifiedSkill; // r29
  aiSkill_t v13; // r3
  idEncounterGroup *EncounterGroup; // r3
  idStr v15; // [sp+70h] [-150h] BYREF
  idStr v16; // [sp+90h] [-130h] BYREF
  idStr v17; // [sp+B0h] [-110h] BYREF
  char v18; // [sp+D0h] [-F0h]
  char *data; // [sp+D4h] [-ECh]
  idStr v20; // [sp+F0h] [-D0h] BYREF
  idStr v21; // [sp+110h] [-B0h] BYREF
  idEventArg v22; // [sp+130h] [-90h] BYREF
  idEventReceiver v23[9]; // [sp+150h] [-70h] BYREF

  v15.len = 0;
  v15.allocedAndFlag = 20;
  v15.data = v15.baseBuffer;
  v15.baseBuffer[0] = 0;
  idAI2::GetSubWebPrefix(this: ai, subWebPrefix: &v15);
  idStr::idStr(this: &v20, text: coverActionNames[ai->aiVolatile.cover.coverAction]);
  v8 = ai->GetPosture(this: ai);
  idStr::Append(this: &v20, text: (char *)postureAnimStateNames[v8]);
  v16.allocedAndFlag = 20;
  v16.len = 0;
  v16.data = v16.baseBuffer;
  v16.baseBuffer[0] = 0;
  idAnimWebPath::SetPath(
    this: (idAnimWebPath *)&v16,
    webName: &byte_8200D768,
    subWebName: v15.data,
    stateName: v20.data);
  idStr::idStr(this: &v21, text: "idle");
  v9 = ai->GetPosture(this: ai);
  idStr::Append(this: &v21, text: (char *)postureAnimStateNames[v9]);
  v17.allocedAndFlag = 20;
  v17.len = 0;
  v17.data = v17.baseBuffer;
  v17.baseBuffer[0] = 0;
  idAnimWebPath::SetPath(
    this: (idAnimWebPath *)&v17,
    webName: &byte_8200D768,
    subWebName: v15.data,
    stateName: v21.data);
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  v18 = 49;
  data = v16.data;
  v10 = idEventArg::idEventArg(this: &v22, data: ai);
  idEventReceiver::ProcessEvent(
    this: v23,
    result: fsm,
    ev: *(const idEventDef **)&v10->type,
    arg1: (const idEventArg *)LODWORD(v10->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v10->value.v[2]));
  decl = ai->aiEditable.behaviors.decl;
  ModifiedSkill = idAI2::GetModifiedSkill(this: ai);
  v13 = idAI2::GetModifiedSkill(this: ai);
  ai->aiVolatile.memory.nextCoverActionTime = GetRandomInterval(
                                                _min: decl->takeCoverBehaviors.minWaitInCoverTime.setting[v13],
                                                _max: decl->takeCoverBehaviors.maxWaitInCoverTime.setting[ModifiedSkill])
                                            + curTime;
  ai->aiVolatile.groupStatus.condition |= 0x20u;
  if ( idAI2::GetEncounterGroup(this: ai) != nullptr )
  {
    EncounterGroup = idAI2::GetEncounterGroup(this: ai);
    idEncounterGroup::UpdateFiringConditions(this: EncounterGroup);
  }
  idStr::FreeData(this: &v17);
  idStr::FreeData(this: &v21);
  idStr::FreeData(this: &v16);
  idStr::FreeData(this: &v20);
  idStr::FreeData(this: &v15);
}


// ========================================================================
// __unwind$495010
// EA  : 0x82ADA064
// RVA : 0x00ADA064
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_495010()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 112));
}


// ========================================================================
// __unwind$495011
// EA  : 0x82ADA08C
// RVA : 0x00ADA08C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_495011()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 240));
}


// ========================================================================
// __unwind$495012
// EA  : 0x82ADA0B4
// RVA : 0x00ADA0B4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_495012()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 144));
}


// ========================================================================
// __unwind$495013
// EA  : 0x82ADA0DC
// RVA : 0x00ADA0DC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_495013()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 272));
}


// ========================================================================
// __unwind$495014
// EA  : 0x82ADA104
// RVA : 0x00ADA104
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_incover.cpp
// ========================================================================

void _unwind_495014()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 176));
}

