
// ========================================================================
// ?Evaluate@COMBAT_ShouldTakeCover@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC5FD0
// RVA : 0x00AC5FD0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idDecl *__fastcall COMBAT_ShouldTakeCover::Evaluate(
        COMBAT_ShouldTakeCover *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idDecl *result; // r3

  result = (idDecl *)idFiniteStateMachine::FindState(this: parentFSM, stateType: &idCombat_TakeCover::Type);
  if ( result != nullptr )
    return (unsigned __int8)idState::CanUse(this: result) == 0 ? nullptr : (idDecl *)0x1E;
  return result;
}


// ========================================================================
// ?Evaluate@COMBAT_ShouldMelee@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC6040
// RVA : 0x00AC6040
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idDecl *__fastcall COMBAT_ShouldMelee::Evaluate(
        COMBAT_ShouldMelee *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idDecl *result; // r3

  result = (idDecl *)idFiniteStateMachine::FindState(this: parentFSM, stateType: &idCombat_Melee::Type);
  if ( result != nullptr )
    return (unsigned __int8)idState::CanUse(this: result) == 0 ? nullptr : (idDecl *)0x1F;
  return result;
}


// ========================================================================
// ?Evaluate@COMBAT_ShouldAdvance@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC60B0
// RVA : 0x00AC60B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall COMBAT_ShouldAdvance::Evaluate(
        COMBAT_ShouldAdvance *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idDecl *v6; // r30
  idEncounterGroup *EncounterGroup; // r3

  v6 = (idDecl *)idFiniteStateMachine::FindState(this: parentFSM, stateType: &idCombat_Advance::Type);
  if ( v6 == nullptr )
    return 0;
  if ( idAI2::GetEncounterGroup(this: ai) != nullptr
    && (EncounterGroup = idAI2::GetEncounterGroup(this: ai), idEncounterGroup::GetShouldAmbush(this: EncounterGroup)) )
  {
    return 0;
  }
  else
  {
    return (unsigned __int8)idState::CanUse(this: v6) == 0 ? 0 : 0x21;
  }
}


// ========================================================================
// ?Evaluate@COMBAT_ShouldOpenCombat@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC6148
// RVA : 0x00AC6148
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall COMBAT_ShouldOpenCombat::Evaluate(
        COMBAT_ShouldOpenCombat *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idDecl *v6; // r30
  idEncounterGroup *EncounterGroup; // r3

  v6 = (idDecl *)idFiniteStateMachine::FindState(this: parentFSM, stateType: &idCombat_OpenCombat::Type);
  if ( v6 == nullptr )
    return 0;
  if ( idAI2::GetEncounterGroup(this: ai) != nullptr
    && (EncounterGroup = idAI2::GetEncounterGroup(this: ai), idEncounterGroup::GetShouldAmbush(this: EncounterGroup)) )
  {
    return 0;
  }
  else
  {
    return (unsigned __int8)idState::CanUse(this: v6) == 0 ? 0 : 0x23;
  }
}


// ========================================================================
// ?Evaluate@COMBAT_NoValidCombatState@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC61E0
// RVA : 0x00AC61E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall COMBAT_NoValidCombatState::Evaluate(
        COMBAT_NoValidCombatState *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 55;
}


// ========================================================================
// ?InternalInitState@idCombat_Default@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC61E8
// RVA : 0x00AC61E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_Default::InternalInitState(idCombat_Default *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_NoEnemies::Type,
    nextStateType: &idCombat_ForceIdle::Type,
    transCode: 23);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_NoEnemies::Type,
    nextStateType: &idAIStateDone::Type,
    transCode: 22);
  idState::AddStateTransition(this, fsm, transType: &COMBAT_ShouldSearch::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ShouldSightEnemy::Type,
    nextStateType: &idCombat_SightedEnemy::Type);
  idState::AddStateTransition(this, fsm, transType: &COMBAT_ShouldRetreat::Type, nextStateType: &idCombat_Retreat::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ShouldFallback::Type,
    nextStateType: &idCombat_Fallback::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ShouldUseTurret::Type,
    nextStateType: &idCombat_MoveToTurret::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ShouldUseZipline::Type,
    nextStateType: &idCombat_MoveToZipline::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ShouldUsePlugAnim::Type,
    nextStateType: &idCombat_MoveToPlugAnim::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ShouldTakeCover::Type,
    nextStateType: &idCombat_TakeCover::Type);
  idState::AddStateTransition(this, fsm, transType: &COMBAT_ShouldMelee::Type, nextStateType: &idCombat_Melee::Type);
  idState::AddStateTransition(this, fsm, transType: &COMBAT_ShouldAdvance::Type, nextStateType: &idCombat_Advance::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ShouldOpenCombat::Type,
    nextStateType: &idCombat_OpenCombat::Type);
}


// ========================================================================
// ?InternalInitState@idCombat_ForceIdle@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC6370
// RVA : 0x00AC6370
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_ForceIdle::InternalInitState(idCombat_ForceIdle *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &COMBAT_ForceIdleDone::Type, nextStateType: &idCombat_Default::Type);
}


// ========================================================================
// ?InternalInitState@idCombat_ForceMoveToEntity@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC6388
// RVA : 0x00AC6388
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_ForceMoveToEntity::InternalInitState(
        idCombat_ForceMoveToEntity *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ForceMoveToEntityDone::Type,
    nextStateType: &idCombat_PlayTraversal::Type,
    transCode: 72);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ForceMoveToEntityDone::Type,
    nextStateType: &idCombat_Default::Type,
    transCode: 71);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_MoveFailed::Type,
    nextStateType: &idCombat_ForceMoveToEntityFailed::Type);
}


// ========================================================================
// ?InternalInitState@idCombat_ForceMoveToEntityFailed@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC63F8
// RVA : 0x00AC63F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_ForceMoveToEntityFailed::InternalInitState(
        idCombat_ForceMoveToEntityFailed *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ForceMoveToEntityAgain::Type,
    nextStateType: &idCombat_ForceMoveToEntity::Type);
}


// ========================================================================
// ?Evaluate@COMBAT_PlayTraversalFailed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC6410
// RVA : 0x00AC6410
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall COMBAT_PlayTraversalFailed::Evaluate(
        COMBAT_PlayTraversalFailed *this,
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
  result = TRANSCODE_PLAY_TRAVERSAL_FAILED;
  if ( !v7 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@COMBAT_PlayTraversalDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC6458
// RVA : 0x00AC6458
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall COMBAT_PlayTraversalDone::Evaluate(
        COMBAT_PlayTraversalDone *this,
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
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) == 0;
  result = TRANSCODE_PLAY_TRAVERSAL_DONE;
  if ( !v7 )
    return 0;
  return result;
}


// ========================================================================
// ?InternalInitState@idCombat_PlayTraversal@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC64A0
// RVA : 0x00AC64A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_PlayTraversal::InternalInitState(
        idCombat_PlayTraversal *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_PlayTraversalDone::Type,
    nextStateType: &idCombat_Default::Type);
}


// ========================================================================
// ?InternalInitState@idCombat_TakeCover@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC64B8
// RVA : 0x00AC64B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_TakeCover::InternalInitState(idCombat_TakeCover *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &COMBAT_RoleChanged::Type, nextStateType: &idCombat_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ShouldUseTurret::Type,
    nextStateType: &idCombat_MoveToTurret::Type);
  idState::AddStateTransition(this, fsm, transType: &COMBAT_TakeCoverDone::Type, nextStateType: &idCombat_Default::Type);
}


// ========================================================================
// ?InternalInitState@idCombat_Melee@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC6520
// RVA : 0x00AC6520
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_Melee::InternalInitState(idCombat_Melee *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &COMBAT_MeleeDone::Type, nextStateType: &idCombat_Default::Type);
}


// ========================================================================
// ?Evaluate@COMBAT_AdvanceDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC6538
// RVA : 0x00AC6538
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall COMBAT_AdvanceDone::Evaluate(
        COMBAT_AdvanceDone *this,
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
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) == 0;
  result = TRANSCODE_COVER_DONE;
  if ( !v7 )
    return 0;
  return result;
}


// ========================================================================
// ?InternalInitState@idCombat_Advance@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC6580
// RVA : 0x00AC6580
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_Advance::InternalInitState(idCombat_Advance *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &COMBAT_RoleChanged::Type, nextStateType: &idCombat_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ShouldUseTurret::Type,
    nextStateType: &idCombat_MoveToTurret::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ShouldUseZipline::Type,
    nextStateType: &idCombat_MoveToZipline::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ShouldUsePlugAnim::Type,
    nextStateType: &idCombat_MoveToPlugAnim::Type);
  idState::AddStateTransition(this, fsm, transType: &COMBAT_AdvanceDone::Type, nextStateType: &idCombat_Default::Type);
}


// ========================================================================
// ?Evaluate@COMBAT_OpenCombatDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC6620
// RVA : 0x00AC6620
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall COMBAT_OpenCombatDone::Evaluate(
        COMBAT_OpenCombatDone *this,
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
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) == 0;
  result = TRANSCODE_OPEN_COMBAT_DONE;
  if ( !v7 )
    return 0;
  return result;
}


// ========================================================================
// ?InternalInitState@idCombat_OpenCombat@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC6668
// RVA : 0x00AC6668
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_OpenCombat::InternalInitState(idCombat_OpenCombat *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &COMBAT_RoleChanged::Type, nextStateType: &idCombat_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ShouldUseTurret::Type,
    nextStateType: &idCombat_MoveToTurret::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ShouldUseZipline::Type,
    nextStateType: &idCombat_MoveToZipline::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ShouldUsePlugAnim::Type,
    nextStateType: &idCombat_MoveToPlugAnim::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_OpenCombatShouldTakeCover::Type,
    nextStateType: &idCombat_TakeCover::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_OpenCombatDone::Type,
    nextStateType: &idCombat_Default::Type);
}


// ========================================================================
// ?InternalInitState@idCombat_SightedEnemy@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC6728
// RVA : 0x00AC6728
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_SightedEnemy::InternalInitState(idCombat_SightedEnemy *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &COMBAT_FinishedSight::Type, nextStateType: &idCombat_Default::Type);
}


// ========================================================================
// ?Evaluate@COMBAT_AtTurret@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC6740
// RVA : 0x00AC6740
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall COMBAT_AtTurret::Evaluate(
        COMBAT_AtTurret *this,
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
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) == 0;
  result = TRANSCODE_AT_TURRET;
  if ( !v7 )
    return 0;
  return result;
}


// ========================================================================
// ?InternalInitState@idCombat_MoveToTurret@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC6788
// RVA : 0x00AC6788
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_MoveToTurret::InternalInitState(idCombat_MoveToTurret *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &COMBAT_AtTurret::Type, nextStateType: &idCombat_UseTurret::Type);
}


// ========================================================================
// ?InternalInitState@idCombat_UseTurret@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC67A0
// RVA : 0x00AC67A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_UseTurret::InternalInitState(idCombat_UseTurret *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ShouldLeaveTurret::Type,
    nextStateType: &idCombat_LeaveTurret::Type);
}


// ========================================================================
// ?InternalInitState@idCombat_LeaveTurret@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC67B8
// RVA : 0x00AC67B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_LeaveTurret::InternalInitState(idCombat_LeaveTurret *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_LeaveTurretDone::Type,
    nextStateType: &idCombat_Default::Type);
}


// ========================================================================
// ?Evaluate@COMBAT_AtZipline@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC67D0
// RVA : 0x00AC67D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall COMBAT_AtZipline::Evaluate(
        COMBAT_AtZipline *this,
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
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) == 0;
  result = TRANSCODE_ZIPLINE;
  if ( !v7 )
    return 0;
  return result;
}


// ========================================================================
// ?InternalInitState@idCombat_MoveToZipline@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC6818
// RVA : 0x00AC6818
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_MoveToZipline::InternalInitState(
        idCombat_MoveToZipline *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_AtZipline::Type,
    nextStateType: &idCombat_MountZipline::Type);
}


// ========================================================================
// ?InternalInitState@idCombat_MountZipline@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC6830
// RVA : 0x00AC6830
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_MountZipline::InternalInitState(idCombat_MountZipline *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ShouldRideZipline::Type,
    nextStateType: &idCombat_RideZipline::Type);
}


// ========================================================================
// ?InternalInitState@idCombat_RideZipline@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC6848
// RVA : 0x00AC6848
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_RideZipline::InternalInitState(idCombat_RideZipline *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_ShouldLeaveZipline::Type,
    nextStateType: &idCombat_LeaveZipline::Type);
}


// ========================================================================
// ?InternalInitState@idCombat_LeaveZipline@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC6860
// RVA : 0x00AC6860
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_LeaveZipline::InternalInitState(idCombat_LeaveZipline *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_LeaveZiplineDone::Type,
    nextStateType: &idCombat_Default::Type);
}


// ========================================================================
// ?Evaluate@COMBAT_AtPlugAnim@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC6878
// RVA : 0x00AC6878
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall COMBAT_AtPlugAnim::Evaluate(
        COMBAT_AtPlugAnim *this,
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
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) == 0;
  result = TRANSCODE_PLUGANIM;
  if ( !v7 )
    return 0;
  return result;
}


// ========================================================================
// ?InternalInitState@idCombat_MoveToPlugAnim@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC68C0
// RVA : 0x00AC68C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_MoveToPlugAnim::InternalInitState(
        idCombat_MoveToPlugAnim *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &COMBAT_AtPlugAnim::Type,
    nextStateType: &idCombat_RunningPlugAnim::Type);
}


// ========================================================================
// ?InternalInitState@idCombat_RunningPlugAnim@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC68D8
// RVA : 0x00AC68D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_RunningPlugAnim::InternalInitState(
        idCombat_RunningPlugAnim *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &COMBAT_PlugAnimDone::Type, nextStateType: &idCombat_Default::Type);
}


// ========================================================================
// ?AIState_Work@idCombat_RunningPlugAnim@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC68F0
// RVA : 0x00AC68F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_RunningPlugAnim::AIState_Work(
        idCombat_RunningPlugAnim *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idLegsFSM *ActionFSM; // r3
  idAIAction *CurrentAction; // r3

  ActionFSM = idAI2::GetActionFSM(this: ai);
  CurrentAction = idAIActionFSM::GetCurrentAction(this: ActionFSM);
  this->plugAnimDone = (_cntlzw((unsigned __int8)idAction_ScriptedAnimWeb::IsTypeOf(c: CurrentAction)) & 0x20) != 0;
}


// ========================================================================
// ?InternalInitState@idCombat_Failsafe@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC6938
// RVA : 0x00AC6938
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_Failsafe::InternalInitState(idCombat_Failsafe *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &COMBAT_RetryCombat::Type, nextStateType: &idCombat_Default::Type);
}


// ========================================================================
// ?InitStates@idCombatFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82AC6950
// RVA : 0x00AC6950
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombatFSM::InitStates(idCombatFSM *this, const idFiniteStateMachineParams *params)
{
  idAIFSM::InitStates(this, params);
  this->AddState(this, a2: &this->stateCombatDefault);
  this->AddState(this, a2: &this->stateTakeCover);
  this->AddState(this, a2: &this->stateMelee);
  this->AddState(this, a2: &this->stateAdvance);
  this->AddState(this, a2: &this->stateRetreat);
  this->AddState(this, a2: &this->stateFallback);
  this->AddState(this, a2: &this->stateOpenCombat);
  this->AddState(this, a2: &this->stateSightedEnemy);
  this->AddState(this, a2: &this->stateCombatFailsafe);
  this->AddState(this, a2: &this->stateMoveToTurret);
  this->AddState(this, a2: &this->stateUseTurret);
  this->AddState(this, a2: &this->stateLeaveTurret);
  this->AddState(this, a2: &this->stateMoveToZipline);
  this->AddState(this, a2: &this->stateMountZipline);
  this->AddState(this, a2: &this->stateRideZipline);
  this->AddState(this, a2: &this->stateLeaveZipline);
  this->AddState(this, a2: &this->stateMoveToPlugAnim);
  this->AddState(this, a2: &this->stateRunningPlugAnim);
  this->AddState(this, a2: &this->stateForceMoveToEntity);
  this->AddState(this, a2: &this->stateForceMoveToEntityFailed);
  this->AddState(this, a2: &this->statePlayTraversal);
  this->AddState(this, a2: &this->stateForceIdle);
}


// ========================================================================
// ?Evaluate@COMBAT_RoleChanged@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC6B90
// RVA : 0x00AC6B90
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall COMBAT_RoleChanged::Evaluate(
        COMBAT_RoleChanged *this,
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
  return v5 == 0 ? 0 : 0x26;
}


// ========================================================================
// ?Evaluate@COMBAT_OpenCombatShouldTakeCover@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC6BD8
// RVA : 0x00AC6BD8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall COMBAT_OpenCombatShouldTakeCover::Evaluate(
        COMBAT_OpenCombatShouldTakeCover *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int *p_openCombatCoverCheckTime; // r29
  idDecl *v7; // r3

  p_openCombatCoverCheckTime = &ai->aiVolatile.memory.openCombatCoverCheckTime;
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= ai->aiVolatile.memory.openCombatCoverCheckTime )
  {
    v7 = (idDecl *)idFiniteStateMachine::FindState(this: parentFSM, stateType: &idCombat_TakeCover::Type);
    if ( v7 != nullptr )
    {
      if ( (unsigned __int8)idState::CanUse(this: v7) != 0 )
        return 30;
      *p_openCombatCoverCheckTime = idGameTimeManager::GetGameMs(
                                      this: &clientGame->gameTimeManager,
                                      type: GAMETIME_SCALED)
                                  + 2000;
    }
  }
  return 0;
}


// ========================================================================
// ?Evaluate@COMBAT_ShouldSearch@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC6C80
// RVA : 0x00AC6C80
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall COMBAT_ShouldSearch::Evaluate(
        COMBAT_ShouldSearch *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return (ai->aiVolatile.groupStatus.condition & 0x1000) == 0 ? 0 : 0x27;
}


// ========================================================================
// ?AIState_EnterState@idCombat_Default@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC6CA8
// RVA : 0x00AC6CA8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_Default::AIState_EnterState(
        idCombat_Default *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  char v5; // r11

  idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
  ai->SetWalkState(this: ai, a2: WALKSTATE_RUNNING);
  idAI2::SetEnableHeadTracking(this: ai, enable: true);
  ai->DisableAIEventResponse(this: ai, a2: AIEVENT_INVESTIGATE);
  *((_BYTE *)&ai->aiVolatile + 49704) |= 1u;
  if ( idAI2::GetEncounterGroup(this: ai) != nullptr )
  {
    idAI2::GetEncounterGroup(this: ai)->active = true;
    if ( (ai->aiVolatile.groupStatus.condition & 0x200) != 0
      || (v5 = 1, !ai->aiVolatile.groupStatus.roleChangeResponseRequired) )
    {
      v5 = 0;
    }
    if ( v5 != 0 )
      ai->aiVolatile.coverManager.forceUpdate = true;
    ai->aiVolatile.groupStatus.roleChangeResponseRequired = false;
  }
}


// ========================================================================
// ?Evaluate@COMBAT_ForceIdleDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC6DA8
// RVA : 0x00AC6DA8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall COMBAT_ForceIdleDone::Evaluate(
        COMBAT_ForceIdleDone *this,
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
    return TRANSCODE_FORCE_IDLE_DONE;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_FORCE_IDLE_DONE;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idCombat_ForceIdle@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC6DF0
// RVA : 0x00AC6DF0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_ForceIdle::AIState_EnterState(
        idCombat_ForceIdle *this,
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
  v11 = 100;
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
// ?AIState_ExitState@idCombat_ForceMoveToEntity@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC6E98
// RVA : 0x00AC6E98
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_ForceMoveToEntity::AIState_ExitState(
        idCombat_ForceMoveToEntity *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  *((_BYTE *)&ai->aiEditable.death + 84) |= 0x80u;
  idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
}


// ========================================================================
// ?Evaluate@COMBAT_TakeCoverFailed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC6EC0
// RVA : 0x00AC6EC0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall COMBAT_TakeCoverFailed::Evaluate(
        COMBAT_TakeCoverFailed *this,
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
  if ( FullPath != nullptr && (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) != 0 )
  {
    errorTransCode = v6->errorTransCode;
    if ( errorTransCode <= 171 )
    {
      if ( errorTransCode == 171 )
        return 41;
      if ( errorTransCode != 9 )
      {
        if ( errorTransCode == 10 )
          return 10;
        return 0;
      }
      return 9;
    }
    if ( errorTransCode == 174 )
      return 174;
    if ( errorTransCode == 175 )
      return 9;
  }
  return 0;
}


// ========================================================================
// ?AIState_CanUse@idCombat_TakeCover@@UBA_NPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC6FA0
// RVA : 0x00AC6FA0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idFiniteStateMachine *__fastcall idCombat_TakeCover::AIState_CanUse(
        idCombat_TakeCover *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idFiniteStateMachine *result; // r3

  result = fsm->manager->FindFSM_3(this: fsm->manager, a2: &idTakeCoverFSM::Type);
  if ( result != nullptr )
    return (idFiniteStateMachine *)result->CanUse(this: result, a2: fsm, a3: curTime);
  return result;
}


// ========================================================================
// ?AIState_CanUse@idCombat_Melee@@UBA_NPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC7010
// RVA : 0x00AC7010
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idFiniteStateMachine *__fastcall idCombat_Melee::AIState_CanUse(
        idCombat_Melee *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idFiniteStateMachine *result; // r3

  result = fsm->manager->FindFSM_3(this: fsm->manager, a2: &idMeleeFSM::Type);
  if ( result != nullptr )
    return (idFiniteStateMachine *)result->CanUse(this: result, a2: fsm, a3: curTime);
  return result;
}


// ========================================================================
// ?AIState_CanUse@idCombat_Advance@@UBA_NPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC7080
// RVA : 0x00AC7080
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idFiniteStateMachine *__fastcall idCombat_Advance::AIState_CanUse(
        idCombat_Advance *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idFiniteStateMachine *result; // r3

  result = fsm->manager->FindFSM_3(this: fsm->manager, a2: &idAdvanceFSM::Type);
  if ( result != nullptr )
    return (idFiniteStateMachine *)result->CanUse(this: result, a2: fsm, a3: curTime);
  return result;
}


// ========================================================================
// ?AIState_EnterState@idCombat_OpenCombat@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC70F0
// RVA : 0x00AC70F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_OpenCombat::AIState_EnterState(
        idCombat_OpenCombat *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  ai->aiVolatile.memory.openCombatCoverCheckTime = idGameTimeManager::GetGameMs(
                                                     this: &clientGame->gameTimeManager,
                                                     type: GAMETIME_SCALED)
                                                 + 2000;
}


// ========================================================================
// ?AIState_ExitState@idCombat_OpenCombat@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC7140
// RVA : 0x00AC7140
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_OpenCombat::AIState_ExitState(idCombat_OpenCombat *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  ai->aiVolatile.memory.endOpenCombatTime = curTime;
}


// ========================================================================
// ?AIState_CanUse@idCombat_OpenCombat@@UBA_NPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC7150
// RVA : 0x00AC7150
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idFiniteStateMachine *__fastcall idCombat_OpenCombat::AIState_CanUse(
        idCombat_OpenCombat *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idFiniteStateMachine *result; // r3

  result = fsm->manager->FindFSM_3(this: fsm->manager, a2: &idOpenCombatFSM::Type);
  if ( result != nullptr )
    return (idFiniteStateMachine *)result->CanUse(this: result, a2: fsm, a3: curTime);
  return result;
}


// ========================================================================
// ?Evaluate@COMBAT_FinishedSight@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC71C0
// RVA : 0x00AC71C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall COMBAT_FinishedSight::Evaluate(
        COMBAT_FinishedSight *this,
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
    return TRANSCODE_FINISHED_SIGHT;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_FINISHED_SIGHT;
  return result;
}


// ========================================================================
// ?Evaluate@COMBAT_LeaveTurretDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC7208
// RVA : 0x00AC7208
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall COMBAT_LeaveTurretDone::Evaluate(
        COMBAT_LeaveTurretDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x3D;
}


// ========================================================================
// ?Evaluate@COMBAT_ShouldRideZipline@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC7248
// RVA : 0x00AC7248
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall COMBAT_ShouldRideZipline::Evaluate(
        COMBAT_ShouldRideZipline *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x4C;
}


// ========================================================================
// ?Evaluate@COMBAT_PlugAnimDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC7288
// RVA : 0x00AC7288
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall COMBAT_PlugAnimDone::Evaluate(
        COMBAT_PlugAnimDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idCombat_RunningPlugAnim *state,
        const int curTime)
{
  return !idCombat_RunningPlugAnim::CastTo(c: state)->plugAnimDone ? 0 : 8;
}


// ========================================================================
// ?Evaluate@COMBAT_RetryCombat@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC72C0
// RVA : 0x00AC72C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall COMBAT_RetryCombat::Evaluate(
        COMBAT_RetryCombat *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return __CFADD__(curTime - ai->aiVolatile.memory.retryCombatTime, ai->aiVolatile.memory.retryCombatTime ^ 0x80000000)
       ? 0
       : 0x35;
}


// ========================================================================
// ??1idCombatFSM@@UAA@XZ
// EA  : 0x82AC72F0
// RVA : 0x00AC72F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombatFSM::~idCombatFSM(idCombatFSM *this)
{
  this->__vftable = (idCombatFSM_vtbl *)&idCombatFSM::`vftable';
  idState::~idState(this: &this->stateForceIdle);
  idState::~idState(this: &this->statePlayTraversal);
  idState::~idState(this: &this->stateForceMoveToEntityFailed);
  idState::~idState(this: &this->stateForceMoveToEntity);
  idState::~idState(this: &this->stateRunningPlugAnim);
  idState::~idState(this: &this->stateMoveToPlugAnim);
  idState::~idState(this: &this->stateLeaveZipline);
  idState::~idState(this: &this->stateRideZipline);
  idState::~idState(this: &this->stateMountZipline);
  idState::~idState(this: &this->stateMoveToZipline);
  idState::~idState(this: &this->stateLeaveTurret);
  idState::~idState(this: &this->stateUseTurret);
  idState::~idState(this: &this->stateMoveToTurret);
  idState::~idState(this: &this->stateCombatFailsafe);
  idState::~idState(this: &this->stateSightedEnemy);
  idState::~idState(this: &this->stateOpenCombat);
  idState::~idState(this: &this->stateMelee);
  idState::~idState(this: &this->stateFallback);
  idState::~idState(this: &this->stateRetreat);
  idState::~idState(this: &this->stateAdvance);
  idState::~idState(this: &this->stateTakeCover);
  idState::~idState(this: &this->stateCombatDefault);
  idFiniteStateMachine::~idFiniteStateMachine(this);
}


// ========================================================================
// __unwind$490769
// EA  : 0x82AC73EC
// RVA : 0x00AC73EC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490769()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$490770
// EA  : 0x82AC7414
// RVA : 0x00AC7414
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490770()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// __unwind$490771
// EA  : 0x82AC7440
// RVA : 0x00AC7440
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490771()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$490772
// EA  : 0x82AC746C
// RVA : 0x00AC746C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490772()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// __unwind$490773
// EA  : 0x82AC7498
// RVA : 0x00AC7498
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490773()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 192));
}


// ========================================================================
// __unwind$490774
// EA  : 0x82AC74C4
// RVA : 0x00AC74C4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490774()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 220));
}


// ========================================================================
// __unwind$490775
// EA  : 0x82AC74F0
// RVA : 0x00AC74F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490775()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 248));
}


// ========================================================================
// __unwind$490776
// EA  : 0x82AC751C
// RVA : 0x00AC751C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490776()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 276));
}


// ========================================================================
// __unwind$490777
// EA  : 0x82AC7548
// RVA : 0x00AC7548
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490777()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 304));
}


// ========================================================================
// __unwind$490778
// EA  : 0x82AC7574
// RVA : 0x00AC7574
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490778()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 332));
}


// ========================================================================
// __unwind$490779
// EA  : 0x82AC75A0
// RVA : 0x00AC75A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490779()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 360));
}


// ========================================================================
// __unwind$490780
// EA  : 0x82AC75CC
// RVA : 0x00AC75CC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490780()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 388));
}


// ========================================================================
// __unwind$490781
// EA  : 0x82AC75F8
// RVA : 0x00AC75F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490781()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 416));
}


// ========================================================================
// __unwind$490782
// EA  : 0x82AC7624
// RVA : 0x00AC7624
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490782()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 444));
}


// ========================================================================
// __unwind$490783
// EA  : 0x82AC7650
// RVA : 0x00AC7650
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490783()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 472));
}


// ========================================================================
// __unwind$490784
// EA  : 0x82AC767C
// RVA : 0x00AC767C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490784()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 500));
}


// ========================================================================
// __unwind$490785
// EA  : 0x82AC76A8
// RVA : 0x00AC76A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490785()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 528));
}


// ========================================================================
// __unwind$490786
// EA  : 0x82AC76D4
// RVA : 0x00AC76D4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490786()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 556));
}


// ========================================================================
// __unwind$490787
// EA  : 0x82AC7700
// RVA : 0x00AC7700
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490787()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 588));
}


// ========================================================================
// __unwind$490788
// EA  : 0x82AC772C
// RVA : 0x00AC772C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490788()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 620));
}


// ========================================================================
// __unwind$490789_0
// EA  : 0x82AC7758
// RVA : 0x00AC7758
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490789_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 648));
}


// ========================================================================
// __unwind$490790_0
// EA  : 0x82AC7784
// RVA : 0x00AC7784
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_490790_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 676));
}


// ========================================================================
// ?Evaluate@COMBAT_NoEnemies@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC77B0
// RVA : 0x00AC77B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall COMBAT_NoEnemies::Evaluate(
        COMBAT_NoEnemies *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idEncounterGroup *EncounterGroup; // r3
  int curCombatStage; // r11
  idEncounterGroup *v8; // r3
  int v9; // r11
  int v10; // r11

  if ( idAI2::AwareOfEnemy(this: ai) )
    return 0;
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
      v8 = idAI2::GetEncounterGroup(this: ai);
      v9 = v8->curCombatStage;
      if ( v9 < 0 || v9 >= v8->combatStages.num )
        v10 = 0;
      else
        v10 = (int)&v8->combatStages.list[v9];
      if ( (*(_BYTE *)(v10 + 92) & 8) != 0 )
        return 23;
    }
  }
  return 22;
}


// ========================================================================
// ?Evaluate@COMBAT_ShouldSightEnemy@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC7918
// RVA : 0x00AC7918
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall COMBAT_ShouldSightEnemy::Evaluate(
        COMBAT_ShouldSightEnemy *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r4
  idAIStateTransition::aiTransCode_t result; // r3
  bool v10; // zf

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
  if ( (*((_BYTE *)idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8) + 541) & 0x40) != 0 )
    return TRANSCODE_SIGHTED_ENEMY;
  if ( ai->GetEquippedWeapon(this: ai) != nullptr )
    return 0;
  v10 = idAI2::FindWeaponToDraw(this: ai) != nullptr;
  result = TRANSCODE_SIGHTED_ENEMY;
  if ( !v10 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@COMBAT_ShouldUseZipline@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC79F8
// RVA : 0x00AC79F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall COMBAT_ShouldUseZipline::Evaluate(
        COMBAT_ShouldUseZipline *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v6; // r3
  idProp_Zipline *v7; // r3

  value = ai->aiVolatile.memory.usedProp.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = (idProp_Zipline *)idEntity::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  return idProp_Zipline::CastTo(c: v7) == nullptr ? 0 : 0x4C;
}


// ========================================================================
// ?Evaluate@COMBAT_ShouldUsePlugAnim@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC7A78
// RVA : 0x00AC7A78
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall COMBAT_ShouldUsePlugAnim::Evaluate(
        COMBAT_ShouldUsePlugAnim *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idInfoPath *v6; // r3
  idInfoPath *v7; // r3
  int num; // r11
  idAIStateTransition::aiTransCode_t result; // r3

  value = ai->aiVolatile.memory.currentPath.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v6 = (idInfoPath *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v6 == nullptr )
    return 0;
  v7 = idInfoPath::CastTo(c: v6);
  if ( v7 == nullptr )
    return 0;
  if ( v7->plugAnim.priority < ALERTCYCLE_COMBAT )
    return 0;
  num = v7->plugAnim.plugAnims.num;
  result = TRANSCODE_PLUGANIM;
  if ( num <= 0 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@COMBAT_ForceMoveToEntityDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC7B08
// RVA : 0x00AC7B08
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall COMBAT_ForceMoveToEntityDone::Evaluate(
        COMBAT_ForceMoveToEntityDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idInfoTraversal *v8; // r3

  if ( !idAI2::IsMoveDone(this: ai, checkAlignment: false) )
    return 0;
  value = ai->aiVolatile.memory.actionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = (idInfoTraversal *)idEntity::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  if ( idInfoTraversal::CastTo(c: v8) != nullptr )
    return 72;
  *((_BYTE *)&ai->aiEditable.death + 84) |= 0x80u;
  return 71;
}


// ========================================================================
// ?AIState_EnterState@idCombat_ForceMoveToEntity@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC7BE8
// RVA : 0x00AC7BE8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_ForceMoveToEntity::AIState_EnterState(
        idCombat_ForceMoveToEntity *this,
        idAI2 *ai,
        __int64 curTime)
{
  int v3; // r28
  __int64 v6; // r10
  __int64 v7; // r8
  idEntity *v8; // r3
  idEntity *v9; // r29
  va *v10; // r3
  char v11; // r9
  idPhysics *Physics; // r3
  int v13; // r3
  float v14; // r11
  float v15; // r10
  double v16; // fp12
  idEventArg *v17; // r30
  idEventArg *v18; // r31
  const idEventArg *v19; // [sp+8h] [-1298h]
  const idEventArg *v20; // [sp+Ch] [-1294h]
  const idEventArg *v21; // [sp+10h] [-1290h]
  int v22; // [sp+14h] [-128Ch]
  int v23; // [sp+18h] [-1288h]
  int v24; // [sp+1Ch] [-1284h]
  _BYTE v25[20]; // [sp+70h] [-1230h] BYREF
  _BYTE v26[20]; // [sp+90h] [-1210h] BYREF
  _BYTE v27[20]; // [sp+B0h] [-11F0h] BYREF
  _BYTE v28[20]; // [sp+D0h] [-11D0h] BYREF
  _BYTE v29[20]; // [sp+F0h] [-11B0h] BYREF
  _BYTE v30[20]; // [sp+110h] [-1190h] BYREF
  float v31[5]; // [sp+130h] [-1170h] BYREF
  _DWORD v32[5]; // [sp+150h] [-1150h] BYREF
  int v33; // [sp+170h] [-1130h]
  int v34; // [sp+174h] [-112Ch]
  const idEventArg *v35; // [sp+178h] [-1128h]
  const idEventArg *v36; // [sp+17Ch] [-1124h]
  _DWORD v37[5]; // [sp+190h] [-1110h] BYREF
  float v38[5]; // [sp+1B0h] [-10F0h] BYREF
  _DWORD v39[5]; // [sp+1D0h] [-10D0h] BYREF
  idEventArg v40; // [sp+1F0h] [-10B0h] BYREF
  idEventReceiver v41[2]; // [sp+210h] [-1090h] BYREF
  idEventArg v42; // [sp+230h] [-1070h] BYREF
  va v43; // [sp+250h] [-1050h] BYREF

  v3 = HIDWORD(curTime);
  v6 = (unsigned int)gameLocal | 0xE31800000000LL;
  LODWORD(v7) = ai->aiVolatile.memory.actionEntity.spawnId.value;
  HIDWORD(v7) = (int)v7 >> 13;
  LODWORD(curTime) = (v7 & 0x1FFF) + 29755;
  if ( *((_DWORD *)&gameLocal->__vftable + curTime) == (int)v7 >> 13
    && (HIDWORD(v6) = 4 * ((v7 & 0x1FFF) + 21563),
        (v8 = *(idEntity **)((char *)&gameLocal->__vftable + HIDWORD(v6))) != nullptr)
    && (v9 = idEntity::CastTo(c: v8)) != nullptr )
  {
    idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
    v11 = *((_BYTE *)&ai->aiEditable.death + 84);
    ai->aiVolatile.focus.enableBodyRotation = true;
    *((_BYTE *)&ai->aiEditable.death + 84) = v11 & 0x7F;
    Physics = idEntity::GetPhysics(this: v9);
    v13 = (int)Physics->GetAxis(this: Physics, a2: 0);
    v14 = *(float *)(v13 + 4);
    v15 = *(float *)(v13 + 8);
    v31[0] = *(float *)v13;
    v31[1] = v14;
    v31[2] = v15;
    idAI2::EndActionScript(this: ai);
    *(_DWORD *)(v3 + 32) = this;
    v16 = v31[2];
    v31[2] = v31[1];
    v31[1] = v31[0];
    v31[3] = v16;
    v38[1] = 0.0;
    HIBYTE(v37[0]) = 105;
    v37[1] = 0;
    HIBYTE(v31[0]) = 118;
    HIBYTE(v39[0]) = 105;
    v39[1] = 1;
    HIBYTE(v38[0]) = 102;
    HIBYTE(v32[0]) = 105;
    v32[1] = 1;
    HIBYTE(v33) = 105;
    v34 = 18;
    v17 = idEventArg::idEventArg(this: &v40, data: v9);
    v18 = idEventArg::idEventArg(this: &v42, data: ai);
    memcpy(Dst: v30, Src: v37, Size: sizeof(v30));
    memcpy(Dst: v29, Src: v31, Size: sizeof(v29));
    memcpy(Dst: v28, Src: v39, Size: sizeof(v28));
    memcpy(Dst: v27, Src: v38, Size: sizeof(v27));
    memcpy(Dst: v26, Src: v32, Size: sizeof(v26));
    memcpy(Dst: v25, Src: v17, Size: sizeof(v25));
    idEventReceiver::ProcessEvent(
      this: v41,
      result: (idEventArg *)v3,
      ev: *(const idEventDef **)&v18->type,
      arg1: (const idEventArg *)LODWORD(v18->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v18->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v33, 32),
      arg4: v35,
      arg5: v36,
      arg6: v19,
      arg7: v20,
      arg8: v21);
  }
  else
  {
    HIDWORD(curTime) = ai->name.data;
    v10 = va::va(
            this: &v43,
            fmt: "AI %s ForceMoveToEntity has no specified target in spawn setting",
            a3: curTime,
            a4: v7,
            a5: v6,
            a6: (int)v19,
            a7: (int)v20,
            a8: (int)v21,
            a9: v22,
            a10: v23,
            a11: v24);
    idLib::Warning(fmt: v10->buffer);
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?AIState_EnterState@idCombat_PlayTraversal@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC7E28
// RVA : 0x00AC7E28
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_PlayTraversal::AIState_EnterState(
        idCombat_PlayTraversal *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idInfoTraversal *v9; // r3
  idInfoTraversal *v10; // r31
  char *data; // r8
  BOOL runWhenDone; // r9
  idEventArg *v13; // r31
  _BYTE v14[20]; // [sp+70h] [-C0h] BYREF
  int v15; // [sp+90h] [-A0h]
  char *v16; // [sp+94h] [-9Ch]
  _DWORD v17[5]; // [sp+B0h] [-80h] BYREF
  idEventArg v18; // [sp+D0h] [-60h] BYREF
  idEventReceiver v19[5]; // [sp+F0h] [-40h] BYREF

  value = ai->aiVolatile.memory.actionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = (idInfoTraversal *)idEntity::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  v10 = idInfoTraversal::CastTo(c: v9);
  if ( v10 != nullptr )
  {
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    data = v10->traversalAnim.data;
    runWhenDone = v10->runWhenDone;
    HIBYTE(v17[0]) = 105;
    HIBYTE(v15) = 49;
    v17[1] = runWhenDone;
    v16 = data;
    v13 = idEventArg::idEventArg(this: &v18, data: ai);
    memcpy(Dst: v14, Src: v17, Size: sizeof(v14));
    idEventReceiver::ProcessEvent(
      this: v19,
      result: fsm,
      ev: *(const idEventDef **)&v13->type,
      arg1: (const idEventArg *)LODWORD(v13->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v13->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v15, 32));
  }
}


// ========================================================================
// ?AIState_EnterState@idCombat_SightedEnemy@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC7F38
// RVA : 0x00AC7F38
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_SightedEnemy::AIState_EnterState(
        idCombat_SightedEnemy *this,
        _exception *ai,
        idEventArg *fsm,
        const int curTime)
{
  const idDeclAIBehavior *v4; // r23
  idEntityPtr<idEntity const > *p_arg1; // r29
  int arg1_high; // r9
  idEntity *v10; // r3
  idEntity *v11; // r4
  idAIEntityState *v12; // r27
  idEntity *v13; // r3
  idEntity *v14; // r4
  idEventArg *v15; // r3
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r29
  idPhysics *Physics; // r3
  float *v18; // r3
  double v19; // fp10
  double v20; // fp8
  double v21; // fp6
  double v24; // fp12
  double v25; // fp2
  idEventArg *v26; // r25
  idDeclAnimWeb *v27; // r29
  const char *StateName; // r3
  idDeclAnimWeb *v29; // r3
  char *data; // r29
  char *SubWebName; // r3
  idEventArg *v32; // r24
  aiSenseState_t *v33; // r29
  idAI2 *Enemy; // r3
  _BYTE v35[20]; // [sp+70h] [-190h] BYREF
  _BYTE v36[20]; // [sp+90h] [-170h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v37; // [sp+B0h] [-150h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v38; // [sp+B2h] [-14Eh] BYREF
  __int16 v39; // [sp+B4h] [-14Ch] BYREF
  idEventReceiver v40[2]; // [sp+C0h] [-140h] BYREF
  idVec3 v41; // [sp+D8h] [-128h] BYREF
  _DWORD v42[5]; // [sp+F0h] [-110h] BYREF
  idEventArg v43; // [sp+110h] [-F0h] BYREF
  idStr v44; // [sp+130h] [-D0h] BYREF
  idStr v45; // [sp+150h] [-B0h] BYREF
  idEventArg v46; // [sp+170h] [-90h] BYREF
  idEventReceiver v47[9]; // [sp+190h] [-70h] BYREF

  v4 = *((const idDeclAIBehavior **)&ai[178].name + 1);
  p_arg1 = (idEntityPtr<idEntity const > *)&ai[906].arg1;
  arg1_high = HIDWORD(ai[906].arg1);
  if ( gameLocal->spawnIds.ptr[arg1_high & 0x1FFF] == arg1_high >> 13
    && (v10 = gameLocal->entities.ptr[arg1_high & 0x1FFF]) != nullptr )
  {
    v11 = idEntity::CastTo(c: v10);
  }
  else
  {
    v11 = nullptr;
  }
  v12 = idAIWorldState::StateForEntity(this: (idAIWorldState *)&ai[219].retval, ent: v11);
  if ( v12 != nullptr )
  {
    *((_BYTE *)v12 + 541) &= ~0x40u;
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 )
      idAnimBaseFSM::ClearDestination(this: (idAnimBaseFSM *)&ai[545]);
    else
      idAIMoveState::Stop(this: (idAIMoveState *)((char *)&ai[190].arg2 + 4), newStatus: 0);
    idAIFireControl::SetFireMode(
      this: (idAIFireControl *)DWORD1(ai[513].retval),
      owner: (idAI2 *)ai,
      mode: FIREMODE_HOLDFIRE);
    if ( gameLocal->spawnIds.ptr[p_arg1->spawnId.value & 0x1FFF] == p_arg1->spawnId.value >> 13
      && (v13 = gameLocal->entities.ptr[p_arg1->spawnId.value & 0x1FFF]) != nullptr )
    {
      v14 = idEntity::CastTo(c: v13);
    }
    else
    {
      v14 = nullptr;
    }
    idAI2::SetAimFocusEntity(this: (idAI2 *)ai, ent: v14, keepFocusInView: true, aimPoint: AIMPOINT_BEST, timeout: -1);
    if ( (unsigned __int8)idAI2::IsWeaponEquipped(this: (idAI2 *)ai) != 0
      || idAI2::FindWeaponToDraw(this: (idAI2 *)ai) == nullptr )
    {
      ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v12->senses.ptr[v12->lastSense]);
      Physics = idEntity::GetPhysics(this: (idEntity *)ai);
      v18 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v19 = (float)(ConfirmedPhysicalSafe->origin.y - v18[1]);
      v20 = (float)(ConfirmedPhysicalSafe->origin.x - *v18);
      v21 = (float)(ConfirmedPhysicalSafe->origin.z - v18[2]);
      _FP2 = (float)((float)((float)((float)v21 * (float)v21)
                           + (float)((float)((float)(ConfirmedPhysicalSafe->origin.x - *v18)
                                           * (float)(ConfirmedPhysicalSafe->origin.x - *v18))
                                   + (float)((float)v19 * (float)v19)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f13, f2, f3, f13 }
      v24 = __frsqrte(_FP13);
      v25 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24
                                                                                          * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v24)
                                                                          - (float)1.5)
                                                          * (float)v24)
                                                  * (float)((float)((float)((float)v21 * (float)v21)
                                                                  + (float)((float)((float)v20 * (float)v20)
                                                                          + (float)((float)v19 * (float)v19)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v24
                                                                                  * (float)((float)((float)((float)v21 * (float)v21)
                                                                                                  + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)))
                                                                                          * (float)0.5))
                                                                          * (float)v24)
                                                                  - (float)1.5)
                                                  * (float)v24))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v24
                                                          * (float)((float)((float)((float)v21 * (float)v21)
                                                                          + (float)((float)((float)v20 * (float)v20)
                                                                                  + (float)((float)v19 * (float)v19)))
                                                                  * (float)0.5))
                                                  * (float)v24)
                                          - (float)1.5)
                          * (float)v24));
      v41.y = (float)v19
            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24)
                                                                                            * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                            * (float)v24))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5))
                                                                                            * (float)v24)
                                                                                    - (float)1.5)
                                                                    * (float)v24))
                                                    * (float)((float)((float)((float)v21 * (float)v21)
                                                                    + (float)((float)((float)v20 * (float)v20)
                                                                            + (float)((float)v19 * (float)v19)))
                                                            * (float)0.5))
                                            * (float)v25)
                                    - (float)1.5)
                    * (float)v25);
      v41.x = (float)v20
            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24)
                                                                                            * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                            * (float)v24))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5))
                                                                                            * (float)v24)
                                                                                    - (float)1.5)
                                                                    * (float)v24))
                                                    * (float)((float)((float)((float)v21 * (float)v21)
                                                                    + (float)((float)((float)v20 * (float)v20)
                                                                            + (float)((float)v19 * (float)v19)))
                                                            * (float)0.5))
                                            * (float)v25)
                                    - (float)1.5)
                    * (float)v25);
      v41.z = (float)v21
            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24)
                                                                                            * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                            * (float)v24))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5))
                                                                                            * (float)v24)
                                                                                    - (float)1.5)
                                                                    * (float)v24))
                                                    * (float)((float)((float)((float)v21 * (float)v21)
                                                                    + (float)((float)((float)v20 * (float)v20)
                                                                            + (float)((float)v19 * (float)v19)))
                                                            * (float)0.5))
                                            * (float)v25)
                                    - (float)1.5)
                    * (float)v25);
      idAnimWebAI::CalcToCombatTurn(this: (idAnimWebAI *)&ai[515], desiredDir: &v41);
      v37.value = -1;
      v38.value = -1;
      idAI2::FindAnimWebAndStateIndices(
        this: (idAI2 *)ai,
        web: AIANIMWEB_BODY,
        subWeb: 1,
        stateName: "idle",
        changeWeapon: false,
        newWeapon: nullptr,
        subWebIndex: &v37,
        stateIndex: &v38);
      idAnimator_AnimWeb::GetCurSubWebIndex(
        this: (idAnimator_AnimWeb *)&v39,
        result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)&ai[515]);
      if ( v39 == v37.value )
      {
        idAI2::EndActionScript(this: (idAI2 *)ai);
        LODWORD(fsm[1].value.v[2]) = this;
        HIBYTE(v42[0]) = 105;
        v42[1] = 1;
        HIBYTE(v40[0].__vftable) = 105;
        v40[0].listenerList = (idList<idEventReceiver *,5> *)100;
        v26 = idEventArg::idEventArg(this: &v43, data: (const idEntity *)ai);
        memcpy(Dst: v35, Src: v42, Size: sizeof(v35));
        idEventReceiver::ProcessEvent(
          this: (idEventReceiver *)&v46,
          result: fsm,
          ev: *(const idEventDef **)&v26->type,
          arg1: (const idEventArg *)LODWORD(v26->value.v[1]),
          arg2: (const idEventArg *)LODWORD(v26->value.v[2]),
          arg3: (const idEventArg *)__ROL4__(v40[0].__vftable, 32));
      }
      else
      {
        idAnimator_AnimWeb::ChangeState(
          this: (idAnimator_AnimWeb *)&ai[515],
          subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v37.value,
          stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v38.value,
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_NO,
          blendEventMask_: 0);
        v44.len = 0;
        v44.allocedAndFlag = 20;
        v44.data = v44.baseBuffer;
        v44.baseBuffer[0] = 0;
        v27 = (idDeclAnimWeb *)DWORD2(ai[515].arg2);
        StateName = idDeclAnimWeb::GetStateName(
                      this: v27,
                      index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v38.value);
        idStr::idStr(this: &v45, text: StateName);
        if ( (*((_BYTE *)&v4->movementBehaviors + 40) & 1) != 0
          && (*(int (__fastcall **)(_exception *))(ai->type + 784))(a1: ai) == 2 )
        {
          idStr::Append(this: &v45, text: "_crouch");
        }
        v29 = v27;
        data = v45.data;
        SubWebName = (char *)idDeclAnimWeb::GetSubWebName(
                               this: v29,
                               index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v37.value);
        idAnimWebPath::SetPath(this: (idAnimWebPath *)&v44, webName: nullptr, subWebName: SubWebName, stateName: data);
        idAI2::EndActionScript(this: (idAI2 *)ai);
        LODWORD(fsm[1].value.v[2]) = this;
        v42[1] = 0;
        HIBYTE(v40[0].__vftable) = 105;
        v40[0].listenerList = (idList<idEventReceiver *,5> *)1;
        HIBYTE(v42[0]) = 105;
        v43.type = 49;
        v43.value.i = (int)v44.data;
        v32 = idEventArg::idEventArg(this: &v46, data: (const idEntity *)ai);
        memcpy(Dst: v36, Src: v40, Size: sizeof(v36));
        memcpy(Dst: v35, Src: v42, Size: sizeof(v35));
        idEventReceiver::ProcessEvent(
          this: v47,
          result: fsm,
          ev: *(const idEventDef **)&v32->type,
          arg1: (const idEventArg *)LODWORD(v32->value.v[1]),
          arg2: (const idEventArg *)LODWORD(v32->value.v[2]),
          arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v43.type, 32),
          arg4: (const idEventArg *)LODWORD(v43.value.v[1]));
        idStr::FreeData(this: &v45);
        idStr::FreeData(this: &v44);
      }
    }
    else
    {
      idAI2::EndActionScript(this: (idAI2 *)ai);
      LODWORD(fsm[1].value.v[2]) = this;
      v15 = idEventArg::idEventArg(this: &v43, data: (const idEntity *)ai);
      idEventReceiver::ProcessEvent(
        this: v40,
        result: fsm,
        ev: *(const idEventDef **)&v15->type,
        arg1: (const idEventArg *)LODWORD(v15->value.v[1]));
    }
    if ( v12->senses.ptr[1]->lastUnconfirmedStimTime >= 0 || v12->senses.ptr[0]->lastUnconfirmedStimTime >= 0 )
    {
      v33 = v12->senses.ptr[v12->lastSense];
      if ( (v33->senseFlags & 1) != 0
        && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
         - v33->lastConfirmedStimTime < 1000
        && LODWORD(ai[513].arg2) != 2 )
      {
        Enemy = (idAI2 *)idAIMemory::GetEnemy(this: (idAIMemory *)(&ai[906].name + 2));
        idAI2::EnemySightedHelper(this: (idAI2 *)ai, ent: Enemy, firstSight: true);
      }
    }
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// __unwind$492960
// EA  : 0x82AC84B8
// RVA : 0x00AC84B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_492960()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 304));
}


// ========================================================================
// __unwind$492961
// EA  : 0x82AC84E0
// RVA : 0x00AC84E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_492961()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 336));
}


// ========================================================================
// ?AIState_EnterState@idCombat_MoveToTurret@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC8508
// RVA : 0x00AC8508
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_MoveToTurret::AIState_EnterState(
        idCombat_MoveToTurret *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  idProp_WeaponStatic *v10; // r3
  idProp_WeaponStatic *v11; // r30
  idPresentable *presentable; // r11
  float z; // r4
  double v16; // fp1
  double v17; // fp4
  double v18; // fp1
  idEventArg *v19; // r21
  const idEventArg *v20; // [sp+8h] [-278h]
  const idEventArg *v21; // [sp+Ch] [-274h]
  _BYTE v22[20]; // [sp+70h] [-210h] BYREF
  _BYTE v23[20]; // [sp+90h] [-1F0h] BYREF
  _BYTE v24[20]; // [sp+B0h] [-1D0h] BYREF
  _BYTE v25[20]; // [sp+D0h] [-1B0h] BYREF
  _BYTE v26[20]; // [sp+F0h] [-190h] BYREF
  idEventReceiver v27; // [sp+110h] [-170h] BYREF
  float v28[6]; // [sp+128h] [-158h] BYREF
  float v29[5]; // [sp+140h] [-140h] BYREF
  float v30[5]; // [sp+160h] [-120h] BYREF
  _DWORD v31[5]; // [sp+180h] [-100h] BYREF
  _DWORD v32[5]; // [sp+1A0h] [-E0h] BYREF
  int v33; // [sp+1C0h] [-C0h]
  int v34; // [sp+1C4h] [-BCh]
  const idEventArg *v35; // [sp+1C8h] [-B8h]
  const idEventArg *v36; // [sp+1CCh] [-B4h]
  float v37[5]; // [sp+1E0h] [-A0h] BYREF
  idEventArg v38[6]; // [sp+200h] [-80h] BYREF

  value = ai->aiVolatile.memory.usedProp.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v10 = (idProp_WeaponStatic *)idEntity::CastTo(c: v9);
  }
  else
  {
    v10 = nullptr;
  }
  v11 = idProp_WeaponStatic::CastTo(c: v10);
  v11->GetUseLocation(this: v11, a2: ai, a3: (idVec3 *)v28);
  presentable = v11->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: v11);
    presentable = v11->presentable;
  }
  v27.__vftable = (idEventReceiver_vtbl *)LODWORD(presentable->axis.mat[0].x);
  v27.listenerList = (idList<idEventReceiver *,5> *)LODWORD(presentable->axis.mat[0].y);
  v29[2] = v28[1];
  z = presentable->axis.mat[0].z;
  v37[1] = 0.1;
  v29[1] = v28[0];
  *(float *)&v27.listeningToList = z;
  v29[3] = v28[2];
  HIBYTE(v30[0]) = 118;
  HIBYTE(v31[0]) = 105;
  v31[1] = 1;
  HIBYTE(v37[0]) = 102;
  HIBYTE(v32[0]) = 105;
  v32[1] = 2;
  HIBYTE(v29[0]) = 118;
  HIBYTE(v33) = 105;
  v34 = 19;
  _FP4 = (float)((float)((float)(z * z)
                       + (float)((float)(*(float *)&v27.listenerList * *(float *)&v27.listenerList)
                               + (float)(*(float *)&v27.__vftable * *(float *)&v27.__vftable)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f4, f5, f13 }
  v16 = __frsqrte(_FP2);
  v17 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16
                                                                                      * (float)((float)((float)(z * z) + (float)((float)(*(float *)&v27.listenerList * *(float *)&v27.listenerList) + (float)(*(float *)&v27.__vftable * *(float *)&v27.__vftable)))
                                                                                              * (float)0.5))
                                                                              * (float)v16)
                                                                      - (float)1.5)
                                                      * (float)v16)
                                              * (float)((float)((float)(z * z)
                                                              + (float)((float)(*(float *)&v27.listenerList
                                                                              * *(float *)&v27.listenerList)
                                                                      + (float)(*(float *)&v27.__vftable
                                                                              * *(float *)&v27.__vftable)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v16
                                                                              * (float)((float)((float)(z * z)
                                                                                              + (float)((float)(*(float *)&v27.listenerList * *(float *)&v27.listenerList) + (float)(*(float *)&v27.__vftable * *(float *)&v27.__vftable)))
                                                                                      * (float)0.5))
                                                                      * (float)v16)
                                                              - (float)1.5)
                                              * (float)v16))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v16
                                                      * (float)((float)((float)(z * z)
                                                                      + (float)((float)(*(float *)&v27.listenerList
                                                                                      * *(float *)&v27.listenerList)
                                                                              + (float)(*(float *)&v27.__vftable
                                                                                      * *(float *)&v27.__vftable)))
                                                              * (float)0.5))
                                              * (float)v16)
                                      - (float)1.5)
                      * (float)v16));
  v18 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)(z * z) + (float)((float)(*(float *)&v27.listenerList * *(float *)&v27.listenerList) + (float)(*(float *)&v27.__vftable * *(float *)&v27.__vftable))) * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                              * (float)v16)
                                                                                      * (float)((float)((float)(z * z) + (float)((float)(*(float *)&v27.listenerList * *(float *)&v27.listenerList) + (float)(*(float *)&v27.__vftable * *(float *)&v27.__vftable)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)(z * z) + (float)((float)(*(float *)&v27.listenerList * *(float *)&v27.listenerList) + (float)(*(float *)&v27.__vftable * *(float *)&v27.__vftable))) * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                      * (float)v16))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v16
                                                                                              * (float)((float)((float)(z * z) + (float)((float)(*(float *)&v27.listenerList * *(float *)&v27.listenerList) + (float)(*(float *)&v27.__vftable * *(float *)&v27.__vftable))) * (float)0.5))
                                                                                      * (float)v16)
                                                                              - (float)1.5)
                                                              * (float)v16))
                                              * (float)((float)((float)(z * z)
                                                              + (float)((float)(*(float *)&v27.listenerList
                                                                              * *(float *)&v27.listenerList)
                                                                      + (float)(*(float *)&v27.__vftable
                                                                              * *(float *)&v27.__vftable)))
                                                      * (float)0.5))
                                      * (float)v17)
                              - (float)1.5)
              * (float)v17);
  v30[1] = *(float *)&v27.__vftable * (float)v18;
  v30[2] = *(float *)&v27.listenerList * (float)v18;
  v30[3] = (float)v18 * z;
  v19 = idEventArg::idEventArg(this: v38, data: ai);
  memcpy(Dst: v26, Src: v30, Size: sizeof(v26));
  memcpy(Dst: v25, Src: v31, Size: sizeof(v25));
  memcpy(Dst: v24, Src: v37, Size: sizeof(v24));
  memcpy(Dst: v23, Src: v32, Size: sizeof(v23));
  memcpy(Dst: v22, Src: v29, Size: sizeof(v22));
  idEventReceiver::ProcessEvent(
    this: &v27,
    result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
    ev: *(const idEventDef **)&v19->type,
    arg1: (const idEventArg *)LODWORD(v19->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v19->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v33, 32),
    arg4: v35,
    arg5: v36,
    arg6: v20,
    arg7: v21);
  idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
}


// ========================================================================
// ?Evaluate@COMBAT_ShouldLeaveTurret@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC8770
// RVA : 0x00AC8770
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall COMBAT_ShouldLeaveTurret::Evaluate(
        COMBAT_ShouldLeaveTurret *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idProp_WeaponStatic *v8; // r3
  idProp_WeaponStatic *v9; // r27
  idAIStateTransition::aiTransCode_t result; // r3
  const idEntity *Enemy; // r4
  idAIEntityState *v12; // r3
  idAIEntityState *v13; // r28
  encounterGroupRole_t currentRole; // r11
  idPhysics *Physics; // r3
  const idVec3 *v16; // r29
  encounterGroupRole_t v17; // r31
  idEncounterGroup *EncounterGroup; // r3
  int curCombatStage; // r11
  idCombatStage *v20; // r3
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r4
  bool v22; // zf

  value = ai->aiVolatile.memory.usedProp.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = (idProp_WeaponStatic *)idEntity::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  v9 = idProp_WeaponStatic::CastTo(c: v8);
  if ( v9 == nullptr )
    return TRANSCODE_SHOULD_LEAVE_TURRET;
  if ( idAI2::GetAlertCycle(this: ai) != ALERTCYCLE_COMBAT )
    return TRANSCODE_SHOULD_LEAVE_TURRET;
  if ( v9->IsDead(this: v9) )
    return TRANSCODE_SHOULD_LEAVE_TURRET;
  Enemy = idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
  if ( Enemy == nullptr )
    return TRANSCODE_SHOULD_LEAVE_TURRET;
  v12 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: Enemy);
  v13 = v12;
  if ( v12 == nullptr || v12->senses.ptr[v12->lastSense]->lastUnconfirmedStimTime < 0 )
    return TRANSCODE_SHOULD_LEAVE_TURRET;
  if ( idAI2::GetCurrentCombatStage(this: ai) != nullptr )
  {
    currentRole = ai->aiVolatile.groupStatus.currentRole;
    if ( currentRole != ROLE_NONE )
    {
      if ( currentRole == ROLE_CHARGE )
        return TRANSCODE_SHOULD_LEAVE_TURRET;
      if ( idAI2::GetEncounterGroup(this: ai) != nullptr )
      {
        Physics = idEntity::GetPhysics(this: v9);
        v16 = Physics->GetOrigin(this: Physics, a2: 0);
        v17 = ai->aiVolatile.groupStatus.currentRole;
        EncounterGroup = idAI2::GetEncounterGroup(this: ai);
        curCombatStage = EncounterGroup->curCombatStage;
        if ( curCombatStage < 0 || curCombatStage >= EncounterGroup->combatStages.num )
          v20 = nullptr;
        else
          v20 = &EncounterGroup->combatStages.list[curCombatStage];
        if ( idCombatStage::GetRolePositionWeight(this: v20, role: v17, pos: v16, hintClass: CLASS_ALL) == 0.0 )
          return TRANSCODE_SHOULD_LEAVE_TURRET;
      }
    }
  }
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v13->senses.ptr[v13->lastSense]);
  if ( (*((_BYTE *)ai->aiEditable.behaviors.decl + 197) & 0x40) != 0 )
    return 0;
  v22 = !idProp_WeaponStatic::IsPointInFiringRange(this: v9, target: &ConfirmedPhysicalSafe->origin, safetyMargin: 0.0);
  result = TRANSCODE_SHOULD_LEAVE_TURRET;
  if ( !v22 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idCombat_MoveToZipline@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC8978
// RVA : 0x00AC8978
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_MoveToZipline::AIState_EnterState(
        idCombat_MoveToZipline *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  idProp_Zipline *v10; // r3
  idProp_Zipline *v11; // r30
  idPhysics *Physics; // r3
  float *v13; // r3
  idPresentable *presentable; // r11
  double v15; // fp31
  double v16; // fp29
  double v17; // fp30
  idEventReceiver_vtbl *x_low; // r4
  double v21; // fp2
  double v22; // fp5
  double v23; // fp2
  idEventArg *v24; // r21
  const idEventArg *v25; // [sp+8h] [-278h]
  const idEventArg *v26; // [sp+Ch] [-274h]
  _BYTE v27[20]; // [sp+70h] [-210h] BYREF
  _BYTE v28[20]; // [sp+90h] [-1F0h] BYREF
  _BYTE v29[20]; // [sp+B0h] [-1D0h] BYREF
  _BYTE v30[20]; // [sp+D0h] [-1B0h] BYREF
  _BYTE v31[20]; // [sp+F0h] [-190h] BYREF
  idVec3 v32; // [sp+110h] [-170h] BYREF
  float v33[5]; // [sp+130h] [-150h] BYREF
  float v34[5]; // [sp+150h] [-130h] BYREF
  _DWORD v35[5]; // [sp+170h] [-110h] BYREF
  _DWORD v36[5]; // [sp+190h] [-F0h] BYREF
  int v37; // [sp+1B0h] [-D0h]
  int v38; // [sp+1B4h] [-CCh]
  const idEventArg *v39; // [sp+1B8h] [-C8h]
  const idEventArg *v40; // [sp+1BCh] [-C4h]
  float v41[5]; // [sp+1D0h] [-B0h] BYREF
  idEventArg v42; // [sp+1F0h] [-90h] BYREF

  value = ai->aiVolatile.memory.usedProp.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v10 = (idProp_Zipline *)idEntity::CastTo(c: v9);
  }
  else
  {
    v10 = nullptr;
  }
  v11 = idProp_Zipline::CastTo(c: v10);
  Physics = idEntity::GetPhysics(this: v11);
  v13 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  presentable = v11->presentable;
  v15 = *v13;
  v16 = v13[1];
  v17 = (float)(v13[2] - (float)128.0);
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: v11);
    presentable = v11->presentable;
  }
  v32 = presentable->axis.mat[0];
  x_low = (idEventReceiver_vtbl *)LODWORD(v32.x);
  v41[1] = 0.1;
  v33[1] = v15;
  v33[2] = v16;
  v33[3] = v17;
  HIBYTE(v34[0]) = 118;
  HIBYTE(v35[0]) = 105;
  v35[1] = 1;
  HIBYTE(v41[0]) = 102;
  HIBYTE(v36[0]) = 105;
  v36[1] = 2;
  HIBYTE(v33[0]) = 118;
  HIBYTE(v37) = 105;
  v38 = 20;
  _FP5 = (float)((float)((float)(*(float *)&x_low * *(float *)&x_low)
                       + (float)((float)(v32.z * v32.z) + (float)(v32.y * v32.y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v21 = __frsqrte(_FP3);
  v22 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21
                                                                                      * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)((float)(v32.z * v32.z) + (float)(v32.y * v32.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v21)
                                                                      - (float)1.5)
                                                      * (float)v21)
                                              * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low)
                                                              + (float)((float)(v32.z * v32.z) + (float)(v32.y * v32.y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v21
                                                                              * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low)
                                                                                              + (float)((float)(v32.z * v32.z) + (float)(v32.y * v32.y)))
                                                                                      * (float)0.5))
                                                                      * (float)v21)
                                                              - (float)1.5)
                                              * (float)v21))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v21
                                                      * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low)
                                                                      + (float)((float)(v32.z * v32.z)
                                                                              + (float)(v32.y * v32.y)))
                                                              * (float)0.5))
                                              * (float)v21)
                                      - (float)1.5)
                      * (float)v21));
  v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)((float)(v32.z * v32.z) + (float)(v32.y * v32.y))) * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                              * (float)v21)
                                                                                      * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)((float)(v32.z * v32.z) + (float)(v32.y * v32.y)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)((float)(v32.z * v32.z) + (float)(v32.y * v32.y))) * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                      * (float)v21))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v21
                                                                                              * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)((float)(v32.z * v32.z) + (float)(v32.y * v32.y))) * (float)0.5))
                                                                                      * (float)v21)
                                                                              - (float)1.5)
                                                              * (float)v21))
                                              * (float)((float)((float)(*(float *)&x_low * *(float *)&x_low)
                                                              + (float)((float)(v32.z * v32.z) + (float)(v32.y * v32.y)))
                                                      * (float)0.5))
                                      * (float)v22)
                              - (float)1.5)
              * (float)v22);
  v34[1] = v32.x * (float)v23;
  v34[2] = v32.y * (float)v23;
  v34[3] = v32.z * (float)v23;
  v24 = idEventArg::idEventArg(this: &v42, data: ai);
  memcpy(Dst: v31, Src: v34, Size: sizeof(v31));
  memcpy(Dst: v30, Src: v35, Size: sizeof(v30));
  memcpy(Dst: v29, Src: v41, Size: sizeof(v29));
  memcpy(Dst: v28, Src: v36, Size: sizeof(v28));
  memcpy(Dst: v27, Src: v33, Size: sizeof(v27));
  idEventReceiver::ProcessEvent(
    this: (idEventReceiver *)&v32,
    result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
    ev: *(const idEventDef **)&v24->type,
    arg1: (const idEventArg *)LODWORD(v24->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v24->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v37, 32),
    arg4: v39,
    arg5: v40,
    arg6: v25,
    arg7: v26);
  idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
}


// ========================================================================
// ?AIState_EnterState@idCombat_RideZipline@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC8C08
// RVA : 0x00AC8C08
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_RideZipline::AIState_EnterState(
        idCombat_RideZipline *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int value; // r8
  idEntity *v6; // r3
  idProp_Zipline *v7; // r3
  idProp_Zipline *v8; // r3

  value = ai->aiVolatile.memory.usedProp.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = (idProp_Zipline *)idEntity::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  v8 = idProp_Zipline::CastTo(c: v7);
  v8->Use(this: v8, a2: ai, a3: USABLE_PROP);
}


// ========================================================================
// ?AIState_EnterState@idCombat_MoveToPlugAnim@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC8CA0
// RVA : 0x00AC8CA0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_MoveToPlugAnim::AIState_EnterState(
        idCombat_MoveToPlugAnim *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idGameLocal *v7; // r11
  int value; // r9
  idInfoPath *v9; // r3
  idInfoPath *v10; // r3
  idInfoPath *v11; // r30
  aiWalkModifier_t walkMod; // r11
  aiWalkModifier_t runMod; // r11
  idPhysics *Physics; // r3
  idAIMoveState_vtbl *v15; // r28
  double goalTolerance; // fp31
  int v17; // r3
  idEventArg *v18; // r29
  idEventArg *v19; // r29
  idEventArg *v20; // r31
  _BYTE v21[20]; // [sp+70h] [-E0h] BYREF
  idEventReceiver v22[2]; // [sp+90h] [-C0h] BYREF
  int v23; // [sp+B0h] [-A0h]
  int v24; // [sp+B4h] [-9Ch]
  idEventArg v25; // [sp+D0h] [-80h] BYREF
  idEventArg v26; // [sp+F0h] [-60h] BYREF

  v7 = gameLocal;
  value = ai->aiVolatile.memory.currentPath.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = (idInfoPath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v10 = idInfoPath::CastTo(c: v9);
    v7 = gameLocal;
    v11 = v10;
  }
  else
  {
    v11 = nullptr;
  }
  if ( v11 != nullptr )
    this->infoPath.spawnId.value = (v7->spawnIds.ptr[v11->entityNumber] << 13) | v11->entityNumber;
  else
    this->infoPath.spawnId.value = 0x1FFF;
  walkMod = v11->walkMod;
  if ( walkMod != AIWALKMOD_DEFAULT )
    ai->aiEditable.movement.walkMod = walkMod;
  runMod = v11->runMod;
  if ( runMod != AIWALKMOD_DEFAULT )
    ai->aiEditable.movement.runMod = runMod;
  ai->actorEditable.standState = v11->standState;
  Physics = idEntity::GetPhysics(this: v11);
  v15 = ai->aiVolatile.physics.moveState.__vftable;
  goalTolerance = ai->aiVolatile.physics.moveState.moveParms.goalTolerance;
  v17 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  if ( v15->ReachedPoint(this: &ai->aiVolatile.physics.moveState, a2: (const idVec3 *)v17, a3: goalTolerance) )
  {
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    HIBYTE(v22[0].__vftable) = 105;
    HIBYTE(v23) = 105;
    v22[0].listenerList = nullptr;
    v24 = -1;
    v18 = idEventArg::idEventArg(this: &v25, data: ai);
    memcpy(Dst: v21, Src: v22, Size: sizeof(v21));
    idEventReceiver::ProcessEvent(
      this: (idEventReceiver *)&v26,
      result: fsm,
      ev: *(const idEventDef **)&v18->type,
      arg1: (const idEventArg *)LODWORD(v18->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v18->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v23, 32));
  }
  else
  {
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    HIBYTE(v23) = 105;
    v24 = 26;
    v19 = idEventArg::idEventArg(this: &v26, data: v11);
    v20 = idEventArg::idEventArg(this: &v25, data: ai);
    memcpy(Dst: v21, Src: v19, Size: sizeof(v21));
    idEventReceiver::ProcessEvent(
      this: v22,
      result: fsm,
      ev: *(const idEventDef **)&v20->type,
      arg1: (const idEventArg *)LODWORD(v20->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v20->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v23, 32));
  }
}


// ========================================================================
// ?AIState_EnterState@idCombat_RunningPlugAnim@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC8ED8
// RVA : 0x00AC8ED8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_RunningPlugAnim::AIState_EnterState(
        idCombat_RunningPlugAnim *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idInfoPath *v8; // r3
  idInfoPath *v9; // r3
  const idEntity *v10; // r31
  idEventArg *v11; // r26
  idEventArg *v12; // r25
  int v13; // r8
  idInfoPath *v14; // r3
  idInfoPath *v15; // r3
  _BYTE v16[20]; // [sp+70h] [-E0h] BYREF
  _DWORD v17[5]; // [sp+90h] [-C0h] BYREF
  idEventArg v18; // [sp+B0h] [-A0h] BYREF
  idEventArg v19; // [sp+D0h] [-80h] BYREF
  idEventReceiver v20[8]; // [sp+F0h] [-60h] BYREF

  value = ai->aiVolatile.memory.currentPath.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = (idInfoPath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v9 = idInfoPath::CastTo(c: v8), v10 = v9, v9 != nullptr) )
  {
    if ( v9->plugAnim.plugAnims.num != 0 )
    {
      idAI2::EndActionScript(this: ai);
      LODWORD(fsm[1].value.v[2]) = this;
      HIBYTE(v17[0]) = 105;
      v17[1] = -1;
      v11 = idEventArg::idEventArg(this: &v18, data: v10);
      v12 = idEventArg::idEventArg(this: &v19, data: ai);
      memcpy(Dst: v16, Src: v17, Size: sizeof(v16));
      idEventReceiver::ProcessEvent(
        this: v20,
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
    v13 = ai->aiVolatile.memory.nextPath.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13
      && (v14 = (idInfoPath *)gameLocal->entities.ptr[v13 & 0x1FFF]) != nullptr )
    {
      v15 = idInfoPath::CastTo(c: v14);
      idAIMemory::SetCurrentPath(this: &ai->aiVolatile.memory, path: v15);
    }
    else
    {
      idAIMemory::SetCurrentPath(this: &ai->aiVolatile.memory, path: nullptr);
    }
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?AIState_EnterState@idCombat_Failsafe@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC9070
// RVA : 0x00AC9070
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_Failsafe::AIState_EnterState(
        idCombat_Failsafe *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idEventArg *v8; // r26
  int value; // r3
  idEntity *v10; // r3
  idEntity *v11; // r4
  _BYTE v12[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v13[5]; // [sp+90h] [-B0h] BYREF
  int v14; // [sp+B0h] [-90h]
  int v15; // [sp+B4h] [-8Ch]
  idEventArg v16; // [sp+D0h] [-70h] BYREF
  idEventReceiver v17[6]; // [sp+F0h] [-50h] BYREF

  idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  HIBYTE(v13[0]) = 105;
  v13[1] = 1;
  HIBYTE(v14) = 105;
  v15 = -1;
  v8 = idEventArg::idEventArg(this: &v16, data: ai);
  memcpy(Dst: v12, Src: v13, Size: sizeof(v12));
  idEventReceiver::ProcessEvent(
    this: v17,
    result: fsm,
    ev: *(const idEventDef **)&v8->type,
    arg1: (const idEventArg *)LODWORD(v8->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v8->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v14, 32));
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v10 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v11 = idEntity::CastTo(c: v10);
  }
  else
  {
    v11 = nullptr;
  }
  idAI2::SetAimFocusEntity(this: ai, ent: v11, keepFocusInView: true, aimPoint: AIMPOINT_BEST, timeout: -1);
  ai->aiVolatile.memory.retryCombatTime = curTime + 2000;
}


// ========================================================================
// ??0idCombatFSM@@QAA@XZ
// EA  : 0x82AC91B0
// RVA : 0x00AC91B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

idCombatFSM *__fastcall idCombatFSM::idCombatFSM(idCombatFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: "FSM_combat");
  this->__vftable = (idCombatFSM_vtbl *)&idCombatFSM::`vftable';
  idState::idState(this: &this->stateCombatDefault, stateType: &idCombat_Default::Type, childFSMType: nullptr, flags: 0);
  this->stateCombatDefault.__vftable = (idCombat_Default_vtbl *)&idCombat_Default::`vftable';
  idState::idState(
    this: &this->stateTakeCover,
    stateType: &idCombat_TakeCover::Type,
    childFSMType: &idTakeCoverFSM::Type,
    flags: 0);
  this->stateTakeCover.__vftable = (idCombat_TakeCover_vtbl *)&idCombat_TakeCover::`vftable';
  idState::idState(
    this: &this->stateAdvance,
    stateType: &idCombat_Advance::Type,
    childFSMType: &idAdvanceFSM::Type,
    flags: 0);
  this->stateAdvance.__vftable = (idCombat_Advance_vtbl *)&idCombat_Advance::`vftable';
  idState::idState(this: &this->stateRetreat, stateType: &idCombat_Retreat::Type, childFSMType: nullptr, flags: 0);
  this->stateRetreat.__vftable = (idCombat_Retreat_vtbl *)&idCombat_Retreat::`vftable';
  idState::idState(this: &this->stateFallback, stateType: &idCombat_Fallback::Type, childFSMType: nullptr, flags: 0);
  this->stateFallback.__vftable = (idCombat_Fallback_vtbl *)&idCombat_Fallback::`vftable';
  idState::idState(this: &this->stateMelee, stateType: &idCombat_Melee::Type, childFSMType: &idMeleeFSM::Type, flags: 0);
  this->stateMelee.__vftable = (idCombat_Melee_vtbl *)&idCombat_Melee::`vftable';
  idState::idState(
    this: &this->stateOpenCombat,
    stateType: &idCombat_OpenCombat::Type,
    childFSMType: &idOpenCombatFSM::Type,
    flags: 0);
  this->stateOpenCombat.__vftable = (idCombat_OpenCombat_vtbl *)&idCombat_OpenCombat::`vftable';
  idState::idState(
    this: &this->stateSightedEnemy,
    stateType: &idCombat_SightedEnemy::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateSightedEnemy.__vftable = (idCombat_SightedEnemy_vtbl *)&idCombat_SightedEnemy::`vftable';
  idState::idState(
    this: &this->stateCombatFailsafe,
    stateType: &idCombat_Failsafe::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateCombatFailsafe.__vftable = (idCombat_Failsafe_vtbl *)&idCombat_Failsafe::`vftable';
  idState::idState(
    this: &this->stateMoveToTurret,
    stateType: &idCombat_MoveToTurret::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveToTurret.__vftable = (idCombat_MoveToTurret_vtbl *)&idCombat_MoveToTurret::`vftable';
  idState::idState(this: &this->stateUseTurret, stateType: &idCombat_UseTurret::Type, childFSMType: nullptr, flags: 0);
  this->stateUseTurret.__vftable = (idCombat_UseTurret_vtbl *)&idCombat_UseTurret::`vftable';
  idState::idState(
    this: &this->stateLeaveTurret,
    stateType: &idCombat_LeaveTurret::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateLeaveTurret.__vftable = (idCombat_LeaveTurret_vtbl *)&idCombat_LeaveTurret::`vftable';
  idState::idState(
    this: &this->stateMoveToZipline,
    stateType: &idCombat_MoveToZipline::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveToZipline.__vftable = (idCombat_MoveToZipline_vtbl *)&idCombat_MoveToZipline::`vftable';
  idState::idState(
    this: &this->stateMountZipline,
    stateType: &idCombat_MountZipline::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMountZipline.__vftable = (idCombat_MountZipline_vtbl *)&idCombat_MountZipline::`vftable';
  idState::idState(
    this: &this->stateRideZipline,
    stateType: &idCombat_RideZipline::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateRideZipline.__vftable = (idCombat_RideZipline_vtbl *)&idCombat_RideZipline::`vftable';
  idState::idState(
    this: &this->stateLeaveZipline,
    stateType: &idCombat_LeaveZipline::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateLeaveZipline.__vftable = (idCombat_LeaveZipline_vtbl *)&idCombat_LeaveZipline::`vftable';
  idState::idState(
    this: &this->stateMoveToPlugAnim,
    stateType: &idCombat_MoveToPlugAnim::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveToPlugAnim.__vftable = (idCombat_MoveToPlugAnim_vtbl *)&idCombat_MoveToPlugAnim::`vftable';
  this->stateMoveToPlugAnim.infoPath.spawnId.value = 0x1FFF;
  idState::idState(
    this: &this->stateRunningPlugAnim,
    stateType: &idCombat_RunningPlugAnim::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateRunningPlugAnim.__vftable = (idCombat_RunningPlugAnim_vtbl *)&idCombat_RunningPlugAnim::`vftable';
  idState::idState(
    this: &this->stateForceMoveToEntity,
    stateType: &idCombat_ForceMoveToEntity::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateForceMoveToEntity.__vftable = (idCombat_ForceMoveToEntity_vtbl *)&idCombat_ForceMoveToEntity::`vftable';
  idState::idState(
    this: &this->stateForceMoveToEntityFailed,
    stateType: &idCombat_ForceMoveToEntityFailed::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateForceMoveToEntityFailed.__vftable = (idCombat_ForceMoveToEntityFailed_vtbl *)&idCombat_ForceMoveToEntityFailed::`vftable';
  idState::idState(
    this: &this->statePlayTraversal,
    stateType: &idCombat_PlayTraversal::Type,
    childFSMType: nullptr,
    flags: 0);
  this->statePlayTraversal.__vftable = (idCombat_PlayTraversal_vtbl *)&idCombat_PlayTraversal::`vftable';
  idState::idState(this: &this->stateForceIdle, stateType: &idCombat_ForceIdle::Type, childFSMType: nullptr, flags: 0);
  this->stateForceIdle.__vftable = (idCombat_ForceIdle_vtbl *)&idCombat_ForceIdle::`vftable';
  idFiniteStateMachine::SetDefaultState(this, state: &this->stateCombatDefault);
  return this;
}


// ========================================================================
// __unwind$494212
// EA  : 0x82AC953C
// RVA : 0x00AC953C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494212()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$494213
// EA  : 0x82AC9564
// RVA : 0x00AC9564
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494213()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$494214
// EA  : 0x82AC9590
// RVA : 0x00AC9590
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494214()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$494215
// EA  : 0x82AC95BC
// RVA : 0x00AC95BC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494215()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// __unwind$494216
// EA  : 0x82AC95E8
// RVA : 0x00AC95E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494216()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 192));
}


// ========================================================================
// __unwind$494217_0
// EA  : 0x82AC9614
// RVA : 0x00AC9614
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494217_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 220));
}


// ========================================================================
// __unwind$494218_0
// EA  : 0x82AC9640
// RVA : 0x00AC9640
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494218_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 248));
}


// ========================================================================
// __unwind$494219
// EA  : 0x82AC966C
// RVA : 0x00AC966C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494219()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 276));
}


// ========================================================================
// __unwind$494220
// EA  : 0x82AC9698
// RVA : 0x00AC9698
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494220()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 304));
}


// ========================================================================
// __unwind$494221
// EA  : 0x82AC96C4
// RVA : 0x00AC96C4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494221()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 332));
}


// ========================================================================
// __unwind$494222
// EA  : 0x82AC96F0
// RVA : 0x00AC96F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494222()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 360));
}


// ========================================================================
// __unwind$494223
// EA  : 0x82AC971C
// RVA : 0x00AC971C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494223()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 388));
}


// ========================================================================
// __unwind$494224
// EA  : 0x82AC9748
// RVA : 0x00AC9748
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494224()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 416));
}


// ========================================================================
// __unwind$494225
// EA  : 0x82AC9774
// RVA : 0x00AC9774
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494225()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 444));
}


// ========================================================================
// __unwind$494226
// EA  : 0x82AC97A0
// RVA : 0x00AC97A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494226()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 472));
}


// ========================================================================
// __unwind$494227
// EA  : 0x82AC97CC
// RVA : 0x00AC97CC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494227()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 500));
}


// ========================================================================
// __unwind$494228
// EA  : 0x82AC97F8
// RVA : 0x00AC97F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494228()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 528));
}


// ========================================================================
// __unwind$494229
// EA  : 0x82AC9824
// RVA : 0x00AC9824
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494229()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 556));
}


// ========================================================================
// __unwind$494230
// EA  : 0x82AC9850
// RVA : 0x00AC9850
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494230()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 588));
}


// ========================================================================
// __unwind$494231
// EA  : 0x82AC987C
// RVA : 0x00AC987C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494231()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 620));
}


// ========================================================================
// __unwind$494232
// EA  : 0x82AC98A8
// RVA : 0x00AC98A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494232()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 648));
}


// ========================================================================
// __unwind$494233
// EA  : 0x82AC98D4
// RVA : 0x00AC98D4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494233()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 676));
}


// ========================================================================
// __unwind$494234
// EA  : 0x82AC9900
// RVA : 0x00AC9900
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494234()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 704));
}


// ========================================================================
// ?CanUse@idCombatFSM@@UBA_NPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AC9930
// RVA : 0x00AC9930
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall idCombatFSM::CanUse(idCombatFSM *this, idFiniteStateMachine *fsm, const int curTime)
{
  idAI2 *Owner; // r3
  const idDeclAIBehavior *decl; // r11
  idAI2 *v5; // r31
  idEntity *UsedProp; // r3
  idInfoPath *CurrentPath; // r3
  const idEntity *Enemy; // r3
  idEntity *v9; // r25
  idAIEntityState *v10; // r3
  idAIEntityState *v11; // r28
  idEncounterGroup *EncounterGroup; // r3
  idEncounterGroup *v13; // r26
  aiSenseState_t *v14; // r11
  char v15; // r31
  char v16; // r30
  char v17; // r29
  unsigned __int8 senseFlags; // r11
  aiSenseState_t *v19; // r11
  unsigned __int8 v20; // r11
  idEntity *v21; // r27
  idEncounterState *p_ownGroupAlertState; // r31
  idEncounterState::groupStates_t state; // r11

  Owner = (idAI2 *)idFiniteStateMachine::GetOwner(this: fsm);
  decl = Owner->aiEditable.behaviors.decl;
  v5 = Owner;
  if ( decl != nullptr && (*((_BYTE *)decl + 196) & 0x80) != 0 && !idAI2::PerceptionFlagIsSet(this: Owner, flags: 1) )
  {
    if ( v5->aiEditable.spawnSettings.alwaysInCombat )
      return 1;
    UsedProp = idAIMemory::GetUsedProp(this: &v5->aiVolatile.memory);
    if ( (unsigned __int8)idProp_Zipline::IsTypeOf(c: UsedProp) != 0 )
      return 1;
    if ( !v5->aiVolatile.memory.allowCombat )
      return 0;
    CurrentPath = idAIMemory::GetCurrentPath(this: &v5->aiVolatile.memory);
    if ( CurrentPath != nullptr && !CurrentPath->abortForCombat )
      return 0;
    if ( !idAI2::AwareOfEnemy(this: v5) )
      return 0;
    Enemy = idAIMemory::GetEnemy(this: &v5->aiVolatile.memory);
    v9 = (idEntity *)Enemy;
    if ( Enemy == nullptr )
      return 0;
    v10 = idAIWorldState::StateForEntity(this: &v5->aiVolatile.world.worldState, ent: Enemy);
    v11 = v10;
    if ( v10 == nullptr || v10->curAwareness != 3 )
      return 0;
    EncounterGroup = idAI2::GetEncounterGroup(this: v5);
    v13 = EncounterGroup;
    if ( EncounterGroup == nullptr )
      return 1;
    v14 = v11->senses.ptr[1];
    v15 = 0;
    v16 = 0;
    v17 = 0;
    if ( v14->lastUnconfirmedStimTime >= 0 && v14->lastConfirmedStimTime >= 0 )
    {
      senseFlags = v14->senseFlags;
      v15 = senseFlags & 1;
      v16 = (senseFlags & 2) != 0;
      v17 = (senseFlags & 8) != 0;
    }
    v19 = v11->senses.ptr[0];
    if ( v19->lastUnconfirmedStimTime >= 0 && v19->lastConfirmedStimTime >= 0 )
    {
      v20 = v19->senseFlags;
      v15 |= v20 & 1;
      v16 |= (v20 & 2) != 0;
      v17 |= (v20 & 8) != 0;
    }
    v21 = (idEntity *)idAIMemory::GetEnemy(this: (idAIMemory *)&EncounterGroup->otherGroupAlertState);
    if ( v15 != 0 || v16 != 0 || v17 != 0 )
    {
      p_ownGroupAlertState = &v13->ownGroupAlertState;
      v21 = (idEntity *)idAIMemory::GetEnemy(this: (idAIMemory *)&v13->ownGroupAlertState);
    }
    else
    {
      p_ownGroupAlertState = &v13->otherGroupAlertState;
    }
    if ( p_ownGroupAlertState == nullptr )
      return 0;
    state = p_ownGroupAlertState->state;
    if ( p_ownGroupAlertState->state == DEFAULT || state == COMBAT )
      return 1;
    if ( state == AMBUSH )
    {
      if ( idEncounterGroup::AnyMemberHighestAlertCycle(this: v13) < ALERTCYCLE_COMBAT )
      {
        if ( v21 != nullptr )
        {
          idEncounterGroup::SetShouldAmbush(this: v13, val: true);
          idEncounterGroup::InitGroupAmbush(this: v13, enemy: v9, ambushTarget: v21);
          return 1;
        }
        idLib::Warning(fmt: "No ambush target set for group %s", v13->groupName.data);
      }
      return 1;
    }
  }
  return 0;
}


// ========================================================================
// ?ConsiderTurret@@YA_NPBVidAI2@@PBVidProp_WeaponStatic@@ABVidVec3@@@Z
// EA  : 0x82AC9BD0
// RVA : 0x00AC9BD0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall ConsiderTurret(idAI2 *ai, idProp_WeaponStatic *turret, const idVec3 *enemyPos)
{
  int value; // r10
  idActor *v7; // r3
  idPhysics *Physics; // r3
  const idVec3 *v10; // r29
  encounterGroupRole_t v11; // r30
  idEncounterGroup *EncounterGroup; // r3
  int curCombatStage; // r11
  idCombatStage *v14; // r3
  idPhysics *v15; // r3
  float *v16; // r3
  double v18; // fp1
  double v20; // fp13
  double v21; // fp10
  double v22; // fp29
  idPhysics *v23; // r3
  float *v24; // r3
  double v25; // fp10
  double v26; // fp6
  double v27; // fp3
  double v29; // fp1
  double v31; // fp13
  double v32; // fp10
  int v33; // r28
  int v34; // r29
  idAIEntityState *es; // r3
  idAI2 *Entity; // r3
  idEntity *v37; // r30
  idAI2 *v38; // r3
  idProp_WeaponStatic *UsedProp; // r3
  idPhysics *v40; // r3
  float *v41; // r3
  double v42; // fp12
  double v43; // fp0
  encounterGroupRole_t currentRole; // [sp+50h] [-C0h]
  idFriendlyTargetFilter v45; // [sp+58h] [-B8h] BYREF
  float v46[4]; // [sp+60h] [-B0h] BYREF
  idTargetList v47; // [sp+70h] [-A0h] BYREF

  value = turret->user.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v7 = (idActor *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v7 != nullptr && idActor::CastTo(c: v7) != nullptr )
      return 0;
  }
  if ( turret->IsDead(this: turret) || (*((_BYTE *)ai->aiEditable.behaviors.decl + 197) & 0x80) == 0 )
    return 0;
  if ( idAI2::GetCurrentCombatStage(this: ai) != nullptr )
  {
    currentRole = ai->aiVolatile.groupStatus.currentRole;
    if ( currentRole != ROLE_NONE )
    {
      if ( currentRole == ROLE_CHARGE )
        return 0;
      if ( idAI2::GetEncounterGroup(this: ai) != nullptr )
      {
        Physics = idEntity::GetPhysics(this: turret);
        v10 = Physics->GetOrigin(this: Physics, a2: 0);
        v11 = ai->aiVolatile.groupStatus.currentRole;
        EncounterGroup = idAI2::GetEncounterGroup(this: ai);
        curCombatStage = EncounterGroup->curCombatStage;
        if ( curCombatStage < 0 || curCombatStage >= EncounterGroup->combatStages.num )
          v14 = nullptr;
        else
          v14 = &EncounterGroup->combatStages.list[curCombatStage];
        if ( idCombatStage::GetRolePositionWeight(this: v14, role: v11, pos: v10, hintClass: CLASS_ALL) == 0.0 )
          return 0;
      }
    }
  }
  if ( !idProp_WeaponStatic::IsPointInFiringRange(
          this: turret,
          target: enemyPos,
          safetyMargin: turret->rangeSafetyMargin) )
    return 0;
  turret->GetUseLocation(this: turret, a2: ai, a3: (idVec3 *)v46);
  v15 = idEntity::GetPhysics(this: ai);
  v16 = (float *)v15->GetOrigin(this: v15, a2: 0);
  _FP2 = (float)((float)((float)((float)(v16[2] - v46[2]) * (float)(v16[2] - v46[2]))
                       + (float)((float)((float)(*v16 - v46[0]) * (float)(*v16 - v46[0]))
                               + (float)((float)(v16[1] - v46[1]) * (float)(v16[1] - v46[1]))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v18 = (float)((float)((float)((float)(v16[2] - v46[2]) * (float)(v16[2] - v46[2]))
                      + (float)((float)((float)(*v16 - v46[0]) * (float)(*v16 - v46[0]))
                              + (float)((float)(v16[1] - v46[1]) * (float)(v16[1] - v46[1]))))
              * (float)0.5);
  __asm { fsel      f0, f2, f3, f0 }
  v20 = __frsqrte(_FP0);
  v21 = (float)-(float)((float)((float)((float)v20
                                      * (float)((float)((float)((float)(v16[2] - v46[2]) * (float)(v16[2] - v46[2]))
                                                      + (float)((float)((float)(*v16 - v46[0]) * (float)(*v16 - v46[0]))
                                                              + (float)((float)(v16[1] - v46[1])
                                                                      * (float)(v16[1] - v46[1]))))
                                              * (float)0.5))
                              * (float)v20)
                      - (float)1.5);
  v22 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)v21 * (float)v20)
                                                                                              * (float)v18)
                                                                                      * (float)((float)v21 * (float)v20))
                                                                              - (float)1.5)
                                                              * (float)((float)v21 * (float)v20))
                                                      * (float)v18)
                                              * (float)((float)-(float)((float)((float)((float)((float)v21 * (float)v20)
                                                                                      * (float)v18)
                                                                              * (float)((float)v21 * (float)v20))
                                                                      - (float)1.5)
                                                      * (float)((float)v21 * (float)v20)))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)((float)v21 * (float)v20) * (float)v18)
                                                      * (float)((float)v21 * (float)v20))
                                              - (float)1.5)
                              * (float)((float)v21 * (float)v20)))
              * (float)((float)((float)(v16[2] - v46[2]) * (float)(v16[2] - v46[2]))
                      + (float)((float)((float)(*v16 - v46[0]) * (float)(*v16 - v46[0]))
                              + (float)((float)(v16[1] - v46[1]) * (float)(v16[1] - v46[1])))));
  v23 = idEntity::GetPhysics(this: ai);
  v24 = (float *)v23->GetOrigin(this: v23, a2: 0);
  v25 = (float)(v24[1] - enemyPos->y);
  v26 = (float)(v24[2] - enemyPos->z);
  v27 = (float)((float)((float)v26 * (float)v26)
              + (float)((float)((float)(*v24 - enemyPos->x) * (float)(*v24 - enemyPos->x))
                      + (float)((float)v25 * (float)v25)));
  _FP2 = (float)((float)((float)((float)v26 * (float)v26)
                       + (float)((float)((float)(*v24 - enemyPos->x) * (float)(*v24 - enemyPos->x))
                               + (float)((float)v25 * (float)v25)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v29 = (float)((float)((float)((float)v26 * (float)v26)
                      + (float)((float)((float)(*v24 - enemyPos->x) * (float)(*v24 - enemyPos->x))
                              + (float)((float)v25 * (float)v25)))
              * (float)0.5);
  __asm { fsel      f0, f2, f3, f0 }
  v31 = __frsqrte(_FP0);
  v32 = (float)-(float)((float)((float)((float)v31
                                      * (float)((float)((float)((float)v26 * (float)v26)
                                                      + (float)((float)((float)(*v24 - enemyPos->x)
                                                                      * (float)(*v24 - enemyPos->x))
                                                              + (float)((float)v25 * (float)v25)))
                                              * (float)0.5))
                              * (float)v31)
                      - (float)1.5);
  if ( v22 > (float)(turret->travelSafetyMargin
                   * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)v32 * (float)v31) * (float)v29) * (float)((float)v32 * (float)v31))
                                                                                           - (float)1.5)
                                                                           * (float)((float)v32 * (float)v31))
                                                                   * (float)v29)
                                                           * (float)((float)-(float)((float)((float)((float)((float)v32 * (float)v31) * (float)v29)
                                                                                           * (float)((float)v32 * (float)v31))
                                                                                   - (float)1.5)
                                                                   * (float)((float)v32 * (float)v31)))
                                                   - (float)1.5)
                                   * (float)((float)-(float)((float)((float)((float)((float)v32 * (float)v31)
                                                                           * (float)v29)
                                                                   * (float)((float)v32 * (float)v31))
                                                           - (float)1.5)
                                           * (float)((float)v32 * (float)v31)))
                           * (float)v27)) )
    return 0;
  idFriendlyTargetFilter::idFriendlyTargetFilter(this: &v45, minAwareness_: AIAWARE_CONFIRMED);
  idTargetList::idTargetList(this: &v47, targetCache_: &ai->aiVolatile.world.worldState.targetCache);
  idTargetList::Filter(this: &v47, owner: ai, filter: &v45);
  v33 = 0;
  if ( v47.viableTargets.num <= 0 )
  {
LABEL_30:
    idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)&v47);
    return 1;
  }
  else
  {
    v34 = 0;
    while ( 1 )
    {
      es = (idAIEntityState *)v47.targetCache->targets.list[v47.viableTargets.list[v34]].es;
      if ( es != nullptr )
      {
        Entity = (idAI2 *)idAIEntityState::GetEntity(this: es);
        v37 = Entity;
        if ( Entity != nullptr )
        {
          v38 = idAI2::CastTo(c: Entity);
          if ( v38 != nullptr )
          {
            UsedProp = (idProp_WeaponStatic *)idAIMemory::GetUsedProp(this: &v38->aiVolatile.memory);
            if ( idProp_WeaponStatic::CastTo(c: UsedProp) == turret )
            {
              v40 = idEntity::GetPhysics(this: v37);
              v41 = (float *)v40->GetOrigin(this: v40, a2: 0);
              v42 = __fsqrts((float)((float)((float)(v46[1] - v41[1]) * (float)(v46[1] - v41[1]))
                                   + (float)((float)((float)(v46[0] - *v41) * (float)(v46[0] - *v41))
                                           + (float)((float)(v46[2] - v41[2]) * (float)(v46[2] - v41[2])))));
              if ( v42 < (float)((float)(turret->reserveRadiusFeet * UNITS_PER_INCH_8) * (float)12.0) )
              {
                v43 = ai->entityNumber >= v37->entityNumber
                    ? (float)((float)(PRIORITY_OFFSET * UNITS_PER_INCH_8) * (float)12.0)
                    : -(float)((float)(PRIORITY_OFFSET * UNITS_PER_INCH_8) * (float)12.0);
                if ( v42 < (float)((float)v43 + (float)v22) )
                  break;
              }
            }
          }
        }
      }
      ++v33;
      ++v34;
      if ( v33 >= v47.viableTargets.num )
        goto LABEL_30;
    }
    idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)&v47);
    return 0;
  }
}


// ========================================================================
// __unwind$494980
// EA  : 0x82ACA03C
// RVA : 0x00ACA03C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494980()
{
  int v0; // r12

  idAvoidTargetFilter::~idAvoidTargetFilter(this: (idFriendlyDeadTargetFilter *)(v0 - 272 + 88));
}


// ========================================================================
// __unwind$494981
// EA  : 0x82ACA064
// RVA : 0x00ACA064
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_494981()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 272 + 112));
}


// ========================================================================
// ?Evaluate@COMBAT_ShouldUseTurret@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ACA098
// RVA : 0x00ACA098
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall COMBAT_ShouldUseTurret::Evaluate(
        COMBAT_ShouldUseTurret *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3
  int value; // r8
  idEntity *v9; // r3
  idEntity *v10; // r4
  idAIEntityState *v11; // r3
  aiSenseState_t *v12; // r3
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r21
  idEntity *v14; // r26
  int v15; // r24
  double v16; // fp28
  int v17; // r25
  idAIEntityState *es; // r3
  idProp_WeaponStatic *Entity; // r3
  idProp_WeaponStatic *v20; // r3
  idEntity *v21; // r30
  const idAAS2 *v22; // r3
  const idAASPosition *AASPosition; // r3
  idAASPosition *v24; // r19
  idAAS2 *aas; // r18
  int travelFlags; // r17
  idPhysics *Physics; // r3
  int v28; // r16
  idAAS2_vtbl *v29; // r27
  int AreaNum; // r3
  idPhysics *v31; // r27
  idPhysics *v32; // r19
  float *v33; // r27
  float *v34; // r3
  double v35; // fp9
  double v36; // fp5
  double v37; // fp2
  double v39; // fp13
  double v41; // fp11
  double v42; // fp9
  int entityNumber; // [sp+60h] [-170h] BYREF
  float v44[22]; // [sp+70h] [-160h] BYREF
  idTurretFilter v45; // [sp+C8h] [-108h] BYREF
  _BYTE v46[16]; // [sp+D0h] [-100h] BYREF
  idTargetList v47; // [sp+E0h] [-F0h] BYREF

  MoveInterface = idAI2::GetMoveInterface(this: ai);
  entityNumber = 5000;
  if ( MoveInterface->RecentlyFailedMove(
         this: MoveInterface,
         a2: AIMOVEREASON_COMBAT_MOVE_TO_TURRET,
         a3: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&entityNumber) )
  {
    return 0;
  }
  if ( ai->aiHealth.IsDead_Impl(this: &ai->aiHealth) )
    return 0;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v9 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v9 == nullptr )
    return 0;
  v10 = idEntity::CastTo(c: v9);
  if ( v10 == nullptr )
    return 0;
  if ( (*((_BYTE *)ai->aiEditable.behaviors.decl + 197) & 0x80) == 0 )
    return 0;
  v11 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v10);
  if ( v11 == nullptr )
    return 0;
  v12 = v11->senses.ptr[v11->lastSense];
  if ( v12->lastUnconfirmedStimTime < 0 )
    return 0;
  entityNumber = (int)v12;
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v12);
  idTurretFilter::idTurretFilter(this: &v45);
  idTargetList::idTargetList(this: &v47, targetCache_: &ai->aiVolatile.world.worldState.targetCache);
  idTargetList::Filter(this: &v47, owner: ai, filter: &v45);
  v14 = nullptr;
  v15 = 0;
  v16 = 0.0;
  if ( v47.viableTargets.num <= 0 )
    goto LABEL_23;
  v17 = 0;
  do
  {
    es = (idAIEntityState *)v47.targetCache->targets.list[v47.viableTargets.list[v17]].es;
    if ( es != nullptr )
    {
      Entity = (idProp_WeaponStatic *)idAIEntityState::GetEntity(this: es);
      if ( Entity != nullptr )
      {
        v20 = idProp_WeaponStatic::CastTo(c: Entity);
        v21 = v20;
        if ( v20 != nullptr
          && (unsigned __int8)ConsiderTurret(ai, turret: v20, enemyPos: &ConfirmedPhysicalSafe->origin) != 0 )
        {
          v22 = ai->GetAAS(this: ai);
          AASPosition = idActor::GetAASPosition(this: ai, aas: v22);
          v44[0] = 0.0;
          v44[1] = 0.0;
          memset(&v44[4], 0, 12);
          v44[2] = 0.0;
          v44[3] = 0.0;
          v44[7] = 0.0;
          v44[10] = 0.0;
          v44[8] = 0.0;
          v44[11] = 0.0;
          v44[9] = 0.0;
          memset(&v44[15], 0, 24);
          v44[12] = 0.0;
          v44[13] = 0.0;
          v44[14] = 0.0;
          v24 = (idAASPosition *)AASPosition;
          ((void (__fastcall *)(idEntity *, idAI2 *, _BYTE *))v21->__vftable[1].JobSync)(a1: v21, a2: ai, a3: v46);
          aas = (idAAS2 *)v24->aas;
          travelFlags = ai->aiVolatile.aas.travelFlags;
          Physics = idEntity::GetPhysics(this: ai);
          v28 = (int)Physics->GetOrigin(this: Physics, a2: 0);
          v29 = aas->__vftable;
          AreaNum = idAASPosition::GetAreaNum(this: v24);
          ((void (__fastcall *)(idAAS2 *, float *, int, int, _BYTE *, int, _DWORD, _DWORD))v29->TraceFloor)(
            a1: aas,
            a2: v44,
            a3: v28,
            a4: AreaNum,
            a5: v46,
            a6: travelFlags,
            a7: 0,
            a8: 0);
          if ( v44[0] >= 1.0 )
          {
            v31 = idEntity::GetPhysics(this: v21);
            v32 = idEntity::GetPhysics(this: ai);
            v33 = (float *)v31->GetOrigin(this: v31, a2: 0);
            v34 = (float *)v32->GetOrigin(this: v32, a2: 0);
            v35 = (float)(v34[1] - v33[1]);
            v36 = (float)(v34[2] - v33[2]);
            v37 = (float)((float)((float)v36 * (float)v36)
                        + (float)((float)((float)(*v34 - *v33) * (float)(*v34 - *v33)) + (float)((float)v35 * (float)v35)));
            _FP1 = (float)((float)((float)((float)v36 * (float)v36)
                                 + (float)((float)((float)(*v34 - *v33) * (float)(*v34 - *v33))
                                         + (float)((float)v35 * (float)v35)))
                         - idMath::FLT_SMALLEST_NON_DENORMAL);
            v39 = (float)((float)((float)((float)v36 * (float)v36)
                                + (float)((float)((float)(*v34 - *v33) * (float)(*v34 - *v33))
                                        + (float)((float)v35 * (float)v35)))
                        * (float)0.5);
            __asm { fsel      f12, f1, f2, f0 }
            v41 = __frsqrte(_FP12);
            v42 = (float)((float)v41
                        * (float)((float)((float)((float)v36 * (float)v36)
                                        + (float)((float)((float)(*v34 - *v33) * (float)(*v34 - *v33))
                                                + (float)((float)v35 * (float)v35)))
                                * (float)0.5));
            if ( v14 == nullptr
              || (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v42 * (float)v41) - (float)1.5) * (float)v41) * (float)v39)
                                                                                               * (float)((float)-(float)((float)((float)v42 * (float)v41) - (float)1.5) * (float)v41))
                                                                                       - (float)1.5)
                                                                       * (float)((float)-(float)((float)((float)v42 * (float)v41)
                                                                                               - (float)1.5)
                                                                               * (float)v41))
                                                               * (float)v39)
                                                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v42 * (float)v41) - (float)1.5) * (float)v41)
                                                                                               * (float)v39)
                                                                                       * (float)((float)-(float)((float)((float)v42 * (float)v41) - (float)1.5)
                                                                                               * (float)v41))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)v42 * (float)v41)
                                                                                       - (float)1.5)
                                                                       * (float)v41)))
                                               - (float)1.5)
                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v42 * (float)v41)
                                                                                               - (float)1.5)
                                                                               * (float)v41)
                                                                       * (float)v39)
                                                               * (float)((float)-(float)((float)((float)v42 * (float)v41)
                                                                                       - (float)1.5)
                                                                       * (float)v41))
                                                       - (float)1.5)
                                       * (float)((float)-(float)((float)((float)v42 * (float)v41) - (float)1.5)
                                               * (float)v41)))
                       * (float)v37) < v16 )
            {
              v14 = v21;
              v16 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v42 * (float)v41) - (float)1.5) * (float)v41) * (float)v39)
                                                                                                  * (float)((float)-(float)((float)((float)v42 * (float)v41) - (float)1.5) * (float)v41))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)v42 * (float)v41)
                                                                                                  - (float)1.5)
                                                                                  * (float)v41))
                                                                  * (float)v39)
                                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v42 * (float)v41) - (float)1.5) * (float)v41)
                                                                                                  * (float)v39)
                                                                                          * (float)((float)-(float)((float)((float)v42 * (float)v41) - (float)1.5)
                                                                                                  * (float)v41))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)v42
                                                                                                  * (float)v41)
                                                                                          - (float)1.5)
                                                                          * (float)v41)))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v42 * (float)v41)
                                                                                                  - (float)1.5)
                                                                                  * (float)v41)
                                                                          * (float)v39)
                                                                  * (float)((float)-(float)((float)((float)v42
                                                                                                  * (float)v41)
                                                                                          - (float)1.5)
                                                                          * (float)v41))
                                                          - (float)1.5)
                                          * (float)((float)-(float)((float)((float)v42 * (float)v41) - (float)1.5)
                                                  * (float)v41)))
                          * (float)v37);
            }
          }
        }
      }
    }
    ++v15;
    ++v17;
  }
  while ( v15 < v47.viableTargets.num );
  if ( v14 != nullptr )
  {
    entityNumber = v14->entityNumber;
    ai->aiVolatile.memory.usedProp.spawnId.value = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
    idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)&v47);
    return 57;
  }
  else
  {
LABEL_23:
    idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)&v47);
    return 0;
  }
}


// ========================================================================
// __unwind$495282
// EA  : 0x82ACA4C8
// RVA : 0x00ACA4C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_495282()
{
  int v0; // r12

  idAvoidTargetFilter::~idAvoidTargetFilter(this: (idFriendlyDeadTargetFilter *)(v0 - 464 + 200));
}


// ========================================================================
// __unwind$495283
// EA  : 0x82ACA4F0
// RVA : 0x00ACA4F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void _unwind_495283()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 464 + 224));
}


// ========================================================================
// ?AIState_ExitState@idCombat_SightedEnemy@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACA518
// RVA : 0x00ACA518
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_SightedEnemy::AIState_ExitState(
        idCombat_SightedEnemy *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAI2::SetAlertCycle(this: ai, ac: ALERTCYCLE_COMBAT);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) == 0 )
  {
    idAI2::GetDefaultMovementMode(this: ai);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&ai->aiVolatile.physics.moveState);
  }
}


// ========================================================================
// ?Evaluate@COMBAT_MoveToTurretFailed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ACA578
// RVA : 0x00ACA578
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall COMBAT_MoveToTurretFailed::Evaluate(
        COMBAT_MoveToTurretFailed *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idEntityPtr<idEntity> *p_usedProp; // r28
  idFiniteStateMachine *FullPath; // r29
  int value; // r9
  idEntity *v9; // r3
  idProp_WeaponStatic *v10; // r3
  idProp_WeaponStatic *v11; // r30
  idPhysics *Physics; // r3
  float *v14; // r3
  aiSenseState_t *EnemySenseState; // r3
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  float v17; // [sp+50h] [-40h] BYREF
  float v18; // [sp+54h] [-3Ch]
  float v19; // [sp+58h] [-38h]

  p_usedProp = &ai->aiVolatile.memory.usedProp;
  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  value = ai->aiVolatile.memory.usedProp.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v10 = (idProp_WeaponStatic *)idEntity::CastTo(c: v9);
  }
  else
  {
    v10 = nullptr;
  }
  v11 = idProp_WeaponStatic::CastTo(c: v10);
  if ( v11 == nullptr )
    return 59;
  if ( FullPath != nullptr )
  {
    if ( (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) != 0 )
      return 59;
    if ( idFiniteStateMachine::GetStatus(this: FullPath) != 0 )
      goto LABEL_17;
  }
  v11->GetUseLocation(this: v11, a2: ai, a3: (idVec3 *)&v17);
  Physics = idEntity::GetPhysics(this: ai);
  v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  if ( (float)((float)((float)(*v14 - v17) * (float)(*v14 - v17))
             + (float)((float)((float)(v14[2] - v19) * (float)(v14[2] - v19))
                     + (float)((float)(v14[1] - v18) * (float)(v14[1] - v18)))) <= (double)(float)((float)(UNITS_PER_INCH_8 * (float)12.0)
                                                                                                 * (float)(UNITS_PER_INCH_8 * (float)12.0)) )
  {
LABEL_17:
    EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
    if ( EnemySenseState != nullptr )
    {
      ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: EnemySenseState);
      if ( (unsigned __int8)ConsiderTurret(ai, turret: v11, enemyPos: &ConfirmedPhysicalSafe->origin) != 0 )
        return 0;
    }
  }
  p_usedProp->spawnId.value = 0x1FFF;
  return 59;
}


// ========================================================================
// ?AIState_EnterState@idCombat_UseTurret@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACA710
// RVA : 0x00ACA710
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_UseTurret::AIState_EnterState(
        idCombat_UseTurret *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idEntityPtr<idEntity> *p_usedProp; // r28
  int value; // r9
  idEntity *v8; // r3
  idProp_WeaponStatic *v9; // r3
  idProp_WeaponStatic *v10; // r3
  idProp_WeaponStatic *v11; // r30
  int v12; // r9
  idActor *v13; // r3
  idPhysics *Physics; // r3
  float *v15; // r3
  double v16; // fp2
  const idEntity *Enemy; // r3
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v18; // [sp+50h] [-50h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v19; // [sp+52h] [-4Eh] BYREF
  float v20; // [sp+58h] [-48h] BYREF
  float v21; // [sp+5Ch] [-44h]
  float v22; // [sp+60h] [-40h]

  p_usedProp = &ai->aiVolatile.memory.usedProp;
  value = ai->aiVolatile.memory.usedProp.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = (idProp_WeaponStatic *)idEntity::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  v10 = idProp_WeaponStatic::CastTo(c: v9);
  v11 = v10;
  if ( v10 == nullptr
    || (v12 = v10->user.spawnId.value, gameLocal->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13)
    && (v13 = (idActor *)gameLocal->entities.ptr[v12 & 0x1FFF]) != nullptr
    && idActor::CastTo(c: v13) != nullptr )
  {
    idState::SetEnterFailed(this, failed: true);
    p_usedProp->spawnId.value = 0x1FFF;
  }
  else
  {
    v11->GetUseLocation(this: v11, a2: ai, a3: (idVec3 *)&v20);
    Physics = idEntity::GetPhysics(this: ai);
    v15 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v16 = (float)((float)(UNITS_PER_INCH_8 * (float)3.0) * (float)12.0);
    if ( (float)((float)((float)(v21 - v15[1]) * (float)(v21 - v15[1]))
               + (float)((float)((float)(v22 - v15[2]) * (float)(v22 - v15[2]))
                       + (float)((float)(v20 - *v15) * (float)(v20 - *v15)))) <= (double)(float)((float)v16 * (float)v16) )
    {
      idFocusInfo::SetEnableTracking(this: ai->aiVolatile.focus.foci.ptr, owner: ai, enable: false);
      Enemy = idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
      idAI2::SetLookFocusEntity(this: ai, ent: Enemy, keepFocusInView: false, aimPoint: AIMPOINT_BEST, timeout: -1);
      v19.value = -1;
      v18.value = -1;
      idAI2::FindAnimWebAndStateIndices(
        this: ai,
        web: AIANIMWEB_BODY,
        subWeb: 18,
        stateName: "aiming",
        changeWeapon: true,
        newWeapon: nullptr,
        subWebIndex: &v19,
        stateIndex: &v18);
      if ( idAI2::ChangeAnimState(
             this: ai,
             web: AIANIMWEB_BODY,
             subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v19.value,
             stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v18.value,
             interruptPath: INTR_PATH_NO,
             interruptBlend: INTR_BLEND_NO) == 1 )
      {
        idAI2::SetAnimWebEvent(
          this: ai,
          web: AIANIMWEB_BODY,
          priority: PRIORITY_LOW,
          swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v19.value,
          si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v18.value,
          eventType: ANIMWEB_EVENT_START_BLEND_IN,
          eventDef: &EV_AnimWeb_StartUseTurret);
        *((_BYTE *)&ai->aiEditable.death + 84) &= 0x3Fu;
      }
    }
    else
    {
      idState::SetEnterFailed(this, failed: true);
    }
  }
}


// ========================================================================
// ?AIState_ExitState@idCombat_UseTurret@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACA950
// RVA : 0x00ACA950
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_UseTurret::AIState_ExitState(
        idCombat_UseTurret *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  const idWeapon *WeaponToDraw; // r3
  int GameMs; // r29
  int v7; // r30
  const idAnimStack *v8; // r3
  idEntityPtr<idEntity> *p_usedProp; // r31
  idEntity *v10; // r3
  idProp_WeaponStatic *v11; // r3
  idProp_WeaponStatic *v12; // r3
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v13; // [sp+50h] [-30h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v14; // [sp+52h] [-2Eh] BYREF

  if ( !ai->IsDead(this: ai) )
  {
    WeaponToDraw = idAI2::FindWeaponToDraw(this: ai);
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
  v7 = blendMS;
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
// ?Evaluate@COMBAT_ShouldLeaveZipline@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ACAB00
// RVA : 0x00ACAB00
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

int __fastcall COMBAT_ShouldLeaveZipline::Evaluate(
        COMBAT_ShouldLeaveZipline *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idEntity *BindMaster; // r3
  idEntityPtr<idEntity> *p_usedProp; // r31
  idEntity *v8; // r3
  idEntity *v9; // r3

  BindMaster = idEntity::GetBindMaster(this: ai);
  if ( (unsigned __int8)idProp_Zipline::IsTypeOf(c: BindMaster) != 0 )
    return 0;
  p_usedProp = &ai->aiVolatile.memory.usedProp;
  if ( gameLocal->spawnIds.ptr[p_usedProp->spawnId.value & 0x1FFF] == p_usedProp->spawnId.value >> 13
    && (v8 = gameLocal->entities.ptr[p_usedProp->spawnId.value & 0x1FFF]) != nullptr )
  {
    v9 = idEntity::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  if ( (unsigned __int8)idProp_Zipline::IsTypeOf(c: v9) != 0 )
    p_usedProp->spawnId.value = 0x1FFF;
  return 76;
}


// ========================================================================
// ?AIState_EnterState@idCombat_MountZipline@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACABC8
// RVA : 0x00ACABC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_MountZipline::AIState_EnterState(
        idCombat_MountZipline *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idEntityPtr<idEntity> *p_usedProp; // r30
  int value; // r9
  idEntity *v8; // r3
  idProp_Zipline *v9; // r3
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v10; // [sp+50h] [-30h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v11; // [sp+52h] [-2Eh] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v12; // [sp+54h] [-2Ch] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v13; // [sp+56h] [-2Ah] BYREF

  p_usedProp = &ai->aiVolatile.memory.usedProp;
  value = ai->aiVolatile.memory.usedProp.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = (idProp_Zipline *)idEntity::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  if ( idProp_Zipline::CastTo(c: v9) != nullptr )
  {
    v13.value = -1;
    v12.value = -1;
    idAI2::FindAnimWebAndStateIndices(
      this: ai,
      web: AIANIMWEB_BODY,
      subWeb: 21,
      stateName: "mount",
      changeWeapon: false,
      newWeapon: nullptr,
      subWebIndex: &v13,
      stateIndex: &v12);
    v11.value = -1;
    v10.value = -1;
    idAI2::FindAnimWebAndStateIndices(
      this: ai,
      web: AIANIMWEB_BODY,
      subWeb: 21,
      stateName: "idle",
      changeWeapon: false,
      newWeapon: nullptr,
      subWebIndex: &v11,
      stateIndex: &v10);
    if ( idAI2::ChangeAnimStateVia(
           this: ai,
           web: AIANIMWEB_BODY,
           subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v11.value,
           stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v10.value,
           viaSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v13.value,
           viaStateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v12.value,
           interruptPath: INTR_PATH_YES,
           interruptBlend: INTR_BLEND_NO) != 1 )
      idLib::Warning(fmt: "ai '%s' had trouble changing anim state while mounting on zipline", ai->name.data);
    idAI2::SetAnimWebEvent(
      this: ai,
      web: AIANIMWEB_BODY,
      priority: PRIORITY_LOW,
      swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v11.value,
      si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v10.value,
      eventType: ANIMWEB_EVENT_START_BLEND_IN,
      eventDef: &EV_AnimWeb_Wait);
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
    p_usedProp->spawnId.value = 0x1FFF;
  }
}


// ========================================================================
// ?AIState_Work@idCombat_MoveToPlugAnim@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ACAD20
// RVA : 0x00ACAD20
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_combat.cpp
// ========================================================================

void __fastcall idCombat_MoveToPlugAnim::AIState_Work(
        idCombat_MoveToPlugAnim *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idGameLocal *v5; // r11
  idInfoPath *v6; // r3
  idInfoPath *v7; // r3
  idInfoPath *v8; // r30
  idEntityPtr<idEntity const > *p_actionEntity; // r29
  idEntity *v10; // r3
  idEntity *v11; // r3

  v5 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->infoPath.spawnId.value & 0x1FFF] == this->infoPath.spawnId.value >> 13
    && (v6 = (idInfoPath *)gameLocal->entities.ptr[this->infoPath.spawnId.value & 0x1FFF]) != nullptr )
  {
    v7 = idInfoPath::CastTo(c: v6);
    v5 = gameLocal;
    v8 = v7;
  }
  else
  {
    v8 = nullptr;
  }
  p_actionEntity = &ai->aiVolatile.memory.actionEntity;
  if ( v5->spawnIds.ptr[p_actionEntity->spawnId.value & 0x1FFF] == p_actionEntity->spawnId.value >> 13
    && (v10 = v5->entities.ptr[p_actionEntity->spawnId.value & 0x1FFF]) != nullptr )
  {
    v11 = idEntity::CastTo(c: v10);
    v5 = gameLocal;
  }
  else
  {
    v11 = nullptr;
  }
  if ( v11 != v8 )
  {
    if ( v8 != nullptr )
      p_actionEntity->spawnId.value = (v5->spawnIds.ptr[v8->entityNumber] << 13) | v8->entityNumber;
    else
      p_actionEntity->spawnId.value = 0x1FFF;
  }
}

