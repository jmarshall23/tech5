
// ========================================================================
// ?Evaluate@AVOID_Done@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC0268
// RVA : 0x00AC0268
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

int __fastcall AVOID_Done::Evaluate(
        AVOID_Done *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 341;
}


// ========================================================================
// ?Evaluate@AVOID_Error@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC0270
// RVA : 0x00AC0270
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

int __fastcall AVOID_Error::Evaluate(
        AVOID_Error *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 326;
}


// ========================================================================
// ?InternalInitState@idAvoid_Default@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC0278
// RVA : 0x00AC0278
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_Default::InternalInitState(idAvoid_Default *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AVOID_ShouldDive::Type,
    nextStateType: &idAvoid_Dive::Type,
    transCode: 302);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AVOID_ShouldDive::Type,
    nextStateType: &idAvoid_Dive::Type,
    transCode: 303);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AVOID_ShouldDive::Type,
    nextStateType: &idAvoid_Dive::Type,
    transCode: 304);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AVOID_ShouldDive::Type,
    nextStateType: &idAvoid_Dive::Type,
    transCode: 305);
  idState::AddStateTransition(this, fsm, transType: &AVOID_ShouldRunAway::Type, nextStateType: &idAvoid_RunAway::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AVOID_ShouldTakeCover::Type,
    nextStateType: &idAvoid_MoveToCover::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AVOID_ShouldMoveToGrenade::Type,
    nextStateType: &idAvoid_MoveToGrenade::Type);
  idState::AddStateTransition(this, fsm, transType: &AVOID_ShouldCower::Type, nextStateType: &idAvoid_Cower::Type);
  idState::AddStateTransition(this, fsm, transType: &AVOID_Done::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAvoid_Dive@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC0388
// RVA : 0x00AC0388
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_Dive::InternalInitState(idAvoid_Dive *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AVOID_DiveDoneStillInDanger::Type,
    nextStateType: &idAvoid_Default::Type);
  idState::AddStateTransition(this, fsm, transType: &AVOID_DiveDone::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAvoid_RunAway@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC03F0
// RVA : 0x00AC03F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_RunAway::InternalInitState(idAvoid_RunAway *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AVOID_AvoidEntityInvalid::Type,
    nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &AVOID_MoveFailed::Type, nextStateType: &idAvoid_Cower::Type);
  idState::AddStateTransition(this, fsm, transType: &AVOID_RunAwayDone::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAvoid_MoveToCover@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC0458
// RVA : 0x00AC0458
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_MoveToCover::InternalInitState(idAvoid_MoveToCover *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AVOID_AvoidEntityInvalid::Type,
    nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &AVOID_CoverInvalid::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &AVOID_MoveFailed::Type, nextStateType: &idAvoid_Cower::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AVOID_ReachedCover::Type,
    nextStateType: &idAvoid_WaitInCover::Type);
}


// ========================================================================
// ?InternalInitState@idAvoid_WaitInCover@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC04E0
// RVA : 0x00AC04E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_WaitInCover::InternalInitState(idAvoid_WaitInCover *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &AVOID_CoverVulnerable::Type, nextStateType: &idAvoid_Default::Type);
  idState::AddStateTransition(this, fsm, transType: &AVOID_WaitInCoverDone::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?Evaluate@AVOID_ShouldKickGrenade@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC0548
// RVA : 0x00AC0548
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

int __fastcall AVOID_ShouldKickGrenade::Evaluate(
        AVOID_ShouldKickGrenade *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return idAI2::GetValidMeleeTypes(this: ai, mask: 32) == 0 ? 0 : 0x150;
}


// ========================================================================
// ?Evaluate@AVOID_ReachedGrenade@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC0580
// RVA : 0x00AC0580
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

int __fastcall AVOID_ReachedGrenade::Evaluate(
        AVOID_ReachedGrenade *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::IsMoveDone(this: ai, checkAlignment: false) ? 0 : 0x151;
}


// ========================================================================
// ?InternalInitState@idAvoid_MoveToGrenade@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC05C0
// RVA : 0x00AC05C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_MoveToGrenade::InternalInitState(idAvoid_MoveToGrenade *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AVOID_AvoidEntityInvalid::Type,
    nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &AVOID_MoveFailed::Type, nextStateType: &idAvoid_Cower::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &AVOID_ShouldKickGrenade::Type,
    nextStateType: &idAvoid_KickGrenade::Type);
  idState::AddStateTransition(this, fsm, transType: &AVOID_ReachedGrenade::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?Evaluate@AVOID_KickedGrenade@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC0648
// RVA : 0x00AC0648
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

int __fastcall AVOID_KickedGrenade::Evaluate(
        AVOID_KickedGrenade *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  return idFile_SaveGamePipelined::GetFullPath(this: state) != 0 ? 0 : 0x154;
}


// ========================================================================
// ?InternalInitState@idAvoid_KickGrenade@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC0680
// RVA : 0x00AC0680
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_KickGrenade::InternalInitState(idAvoid_KickGrenade *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &AVOID_KickedGrenade::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InternalInitState@idAvoid_Cower@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC0698
// RVA : 0x00AC0698
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_Cower::InternalInitState(idAvoid_Cower *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &AVOID_CowerVulnerable::Type, nextStateType: &idAvoid_Default::Type);
  idState::AddStateTransition(this, fsm, transType: &AVOID_StopCowering::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?Evaluate@AVOID_CoverInvalid@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC0700
// RVA : 0x00AC0700
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

int __fastcall AVOID_CoverInvalid::Evaluate(
        AVOID_CoverInvalid *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return (unsigned __int8)idAICover::IsValid(this: &ai->aiVolatile.memory.currentCover) != 0 ? 0 : 0x14C;
}


// ========================================================================
// ?Evaluate@AVOID_MoveFailed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC0740
// RVA : 0x00AC0740
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall AVOID_MoveFailed::Evaluate(
        AVOID_MoveFailed *this,
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
  result = TRANSCODE_AVOID_MOVE_FAILED;
  if ( errorTransCode > 20 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@AVOID_ShouldDive@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC07A8
// RVA : 0x00AC07A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall AVOID_ShouldDive::Evaluate(
        AVOID_ShouldDive *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIStateTransition::aiTransCode_t result; // r3

  result = ai->aiVolatile.memory.transCode;
  if ( result != TRANSCODE_OC_DIVE_LEFT
    && result != TRANSCODE_OC_DIVE_RIGHT
    && result != TRANSCODE_OC_DIVE_FORWARD
    && result != TRANSCODE_OC_DIVE_BACKWARD )
  {
    return 0;
  }
  return result;
}


// ========================================================================
// ?Evaluate@AVOID_ShouldRunAway@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC07E0
// RVA : 0x00AC07E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

int __fastcall AVOID_ShouldRunAway::Evaluate(
        AVOID_ShouldRunAway *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return ai->aiVolatile.memory.transCode != TRANSCODE_AVOID_SHOULD_RUN_AWAY ? 0 : 0x142;
}


// ========================================================================
// ?Evaluate@AVOID_ShouldTakeCover@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC0808
// RVA : 0x00AC0808
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

int __fastcall AVOID_ShouldTakeCover::Evaluate(
        AVOID_ShouldTakeCover *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return ai->aiVolatile.memory.transCode != TRANSCODE_AVOID_SHOULD_TAKE_COVER ? 0 : 0x143;
}


// ========================================================================
// ?Evaluate@AVOID_ShouldMoveToGrenade@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC0830
// RVA : 0x00AC0830
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

int __fastcall AVOID_ShouldMoveToGrenade::Evaluate(
        AVOID_ShouldMoveToGrenade *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return ai->aiVolatile.memory.transCode != TRANSCODE_AVOID_SHOULD_MOVE_TO_GRENADE ? 0 : 0x144;
}


// ========================================================================
// ?Evaluate@AVOID_ShouldCower@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC0858
// RVA : 0x00AC0858
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

int __fastcall AVOID_ShouldCower::Evaluate(
        AVOID_ShouldCower *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return ai->aiVolatile.memory.transCode != TRANSCODE_AVOID_SHOULD_COWER ? 0 : 0x145;
}


// ========================================================================
// ?Evaluate@AVOID_DiveDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC0880
// RVA : 0x00AC0880
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

int __fastcall AVOID_DiveDone::Evaluate(
        AVOID_DiveDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x147;
}


// ========================================================================
// ?Evaluate@AVOID_RunAwayDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC08C0
// RVA : 0x00AC08C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall AVOID_RunAwayDone::Evaluate(
        AVOID_RunAwayDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idAIStateTransition::aiTransCode_t result; // r3
  idFiniteStateMachine *FullPath; // r3
  bool v8; // zf

  if ( idAI2::IsMoveDone(this: ai, checkAlignment: false) )
    return TRANSCODE_AVOID_RUN_AWAY_DONE;
  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( FullPath == nullptr )
    return 0;
  v8 = idFiniteStateMachine::GetStatus(this: FullPath) == 0;
  result = TRANSCODE_AVOID_RUN_AWAY_DONE;
  if ( !v8 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@AVOID_ReachedCover@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC0940
// RVA : 0x00AC0940
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall AVOID_ReachedCover::Evaluate(
        AVOID_ReachedCover *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idAIStateTransition::aiTransCode_t result; // r3
  idFiniteStateMachine *FullPath; // r3
  bool v8; // zf

  if ( idAI2::IsMoveDone(this: ai, checkAlignment: false) )
    return TRANSCODE_AVOID_REACHED_COVER;
  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( FullPath == nullptr )
    return 0;
  v8 = idFiniteStateMachine::GetStatus(this: FullPath) == 0;
  result = TRANSCODE_AVOID_RUN_AWAY_DONE;
  if ( !v8 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idAvoid_WaitInCover@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC09C8
// RVA : 0x00AC09C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_WaitInCover::AIState_EnterState(
        idAvoid_WaitInCover *this,
        idAI2 *ai,
        idEventArg *fsm,
        int curTime)
{
  idAICover *p_currentCover; // r28
  char v9; // r8
  idAICover *v10; // r3
  coverOrientation_t coverOrientation; // r28
  posture_t CoverPosture; // r3
  idEventArg *v13; // r26
  idEventArg *v14; // r24
  _BYTE v15[20]; // [sp+70h] [-F0h] BYREF
  idCoverCapabilities v16; // [sp+90h] [-D0h] BYREF
  _DWORD v17[5]; // [sp+A0h] [-C0h] BYREF
  _DWORD v18[5]; // [sp+C0h] [-A0h] BYREF
  idEventArg v19; // [sp+E0h] [-80h] BYREF
  idEventArg v20[4]; // [sp+100h] [-60h] BYREF

  p_currentCover = &ai->aiVolatile.memory.currentCover;
  if ( (unsigned __int8)idAICover::IsValid(this: &ai->aiVolatile.memory.currentCover) != 0 )
  {
    ai->EnableAIEventResponse(this: ai, a2: AIEVENT_GRENADE);
    idAIMemory::SetReachedCoverTime(this: &ai->aiVolatile.memory, curTime);
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
      idAnimBaseFSM::ClearDestination(this: &ai->aiVolatile.animation.animFSM);
    else
      idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
    v9 = *((_BYTE *)&v16 + 8);
    v16.__vftable = (idCoverCapabilities_vtbl *)&idCoverCapabilities::`vftable';
    *((_BYTE *)&v16.idCoverActions + 4) &= 7u;
    ai->aiVolatile.animation.subWeb = AISUBWEB_FCOVER;
    *((_BYTE *)&v16 + 8) = v9 & 1 | 2;
    v10 = p_currentCover;
    coverOrientation = ai->aiVolatile.cover.coverOrientation;
    CoverPosture = idAICover::GetCoverPosture(this: v10);
    if ( idAIBehaviors::HasCoverCapability(
           this: &ai->aiEditable.behaviors,
           ai,
           coverPosture: CoverPosture,
           coverOrientation,
           coverCaps: &v16) )
    {
      idAI2::EndActionScript(this: ai);
      LODWORD(fsm[1].value.v[2]) = this;
      HIBYTE(v17[0]) = 105;
      v17[1] = 1000;
      HIBYTE(v18[0]) = 105;
      v18[1] = 12;
      v13 = idEventArg::idEventArg(this: &v19, data: ai);
      memcpy(Dst: v15, Src: v17, Size: sizeof(v15));
      idEventReceiver::ProcessEvent(
        this: (idEventReceiver *)v20,
        result: fsm,
        ev: *(const idEventDef **)&v13->type,
        arg1: (const idEventArg *)LODWORD(v13->value.v[1]),
        arg2: (const idEventArg *)LODWORD(v13->value.v[2]),
        arg3: (const idEventArg *)__ROL4__(v18[0], 32));
      idAI2::SetCoverAction(this: ai, action: COVERACTION_HIDE);
    }
    else
    {
      HIBYTE(v18[0]) = 105;
      v18[1] = 1;
      HIBYTE(v17[0]) = 105;
      v17[1] = -1;
      v14 = idEventArg::idEventArg(this: v20, data: ai);
      memcpy(Dst: v15, Src: v18, Size: sizeof(v15));
      idEventReceiver::ProcessEvent(
        this: (idEventReceiver *)&v19,
        result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
        ev: (const idEventDef *)(*(_DWORD *)&v14->type - 22228),
        arg1: (const idEventArg *)LODWORD(v14->value.v[1]),
        arg2: (const idEventArg *)LODWORD(v14->value.v[2]),
        arg3: (const idEventArg *)__ROL4__(LODWORD(v14->value.q[3]), 32));
      idAIState::StartQueuedActions(this, ai, parentFSM: (idAIFSM *)fsm, curTime);
    }
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// __unwind$489621
// EA  : 0x82AC0C08
// RVA : 0x00AC0C08
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void _unwind_489621()
{
  int v0; // r12

  idCoverActions::~idCoverActions(this: (idCoverActions *)(v0 - 352 + 144));
}


// ========================================================================
// ?AIState_ExitState@idAvoid_WaitInCover@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC0C30
// RVA : 0x00AC0C30
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_WaitInCover::AIState_ExitState(
        idAvoid_WaitInCover *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  if ( fsm->lastTransitionCode == 333 )
  {
    idAICover::MakeUnusable(this: &ai->aiVolatile.memory.currentCover, duration: 4000);
    idAI2::ReleaseCover(this: ai);
  }
  idAI2::ReleaseCover(this: ai);
}


// ========================================================================
// ?AIState_EnterState@idAvoid_KickGrenade@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC0C88
// RVA : 0x00AC0C88
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_KickGrenade::AIState_EnterState(
        idAvoid_KickGrenade *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idEventArg *v7; // r27
  _BYTE v8[20]; // [sp+70h] [-110h] BYREF
  _BYTE v9[20]; // [sp+90h] [-F0h] BYREF
  float v10[5]; // [sp+B0h] [-D0h] BYREF
  _DWORD v11[5]; // [sp+D0h] [-B0h] BYREF
  int v12; // [sp+F0h] [-90h]
  int v13; // [sp+F4h] [-8Ch]
  const idEventArg *v14; // [sp+F8h] [-88h]
  idEventArg v15; // [sp+110h] [-70h] BYREF
  idEventReceiver v16[6]; // [sp+130h] [-50h] BYREF

  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  HIBYTE(v11[0]) = 105;
  HIBYTE(v12) = 105;
  v10[1] = vec3_origin.x;
  HIBYTE(v10[0]) = 118;
  v10[3] = vec3_origin.z;
  v11[1] = 0;
  v10[2] = vec3_origin.y;
  v13 = 35;
  v7 = idEventArg::idEventArg(this: &v15, data: ai);
  memcpy(Dst: v9, Src: v10, Size: sizeof(v9));
  memcpy(Dst: v8, Src: v11, Size: sizeof(v8));
  idEventReceiver::ProcessEvent(
    this: v16,
    result: fsm,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v12, 32),
    arg4: v14);
}


// ========================================================================
// ?AIState_EnterState@idAvoid_Cower@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC0D68
// RVA : 0x00AC0D68
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_Cower::AIState_EnterState(idAvoid_Cower *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  idEventArg *v8; // r3
  idEventArg *v9; // r24
  _BYTE v10[20]; // [sp+70h] [-E0h] BYREF
  _DWORD v11[5]; // [sp+90h] [-C0h] BYREF
  idEventArg v12; // [sp+B0h] [-A0h] BYREF
  idEventArg v13; // [sp+D0h] [-80h] BYREF
  idEventReceiver v14[8]; // [sp+F0h] [-60h] BYREF

  ai->EnableAIEventResponse(this: ai, a2: AIEVENT_GRENADE);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
    idAnimBaseFSM::ClearDestination(this: &ai->aiVolatile.animation.animFSM);
  else
    idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
  v11[1] = 27;
  HIBYTE(v11[0]) = 105;
  v8 = idEventArg::idEventArg(this: &v12, data: ai);
  idEventReceiver::ProcessEvent(
    this: (idEventReceiver *)&v13,
    result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
    ev: *(const idEventDef **)&v8->type,
    arg1: (const idEventArg *)LODWORD(v8->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v8->value.v[2]));
  HIBYTE(v11[0]) = 105;
  v12.type = 105;
  v11[1] = 1;
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
// ??0idAvoidFSM@@QAA@XZ
// EA  : 0x82AC0EC8
// RVA : 0x00AC0EC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

idAvoidFSM *__fastcall idAvoidFSM::idAvoidFSM(idAvoidFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: "FSM_avoid");
  this->__vftable = (idAvoidFSM_vtbl *)&idAvoidFSM::`vftable';
  idState::idState(this: &this->stateDefault, stateType: &idAvoid_Default::Type, childFSMType: nullptr, flags: 0);
  this->stateDefault.__vftable = (idAvoid_Default_vtbl *)&idAvoid_Default::`vftable';
  idState::idState(this: &this->stateDive, stateType: &idAvoid_Dive::Type, childFSMType: nullptr, flags: 0);
  this->stateDive.__vftable = (idAvoid_Dive_vtbl *)&idAvoid_Dive::`vftable';
  idState::idState(this: &this->stateRunAway, stateType: &idAvoid_RunAway::Type, childFSMType: nullptr, flags: 0);
  this->stateRunAway.__vftable = (idAvoid_RunAway_vtbl *)&idAvoid_RunAway::`vftable';
  idState::idState(
    this: &this->stateMoveToCover,
    stateType: &idAvoid_MoveToCover::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveToCover.__vftable = (idAvoid_MoveToCover_vtbl *)&idAvoid_MoveToCover::`vftable';
  idState::idState(
    this: &this->stateWaitInCover,
    stateType: &idAvoid_WaitInCover::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateWaitInCover.__vftable = (idAvoid_WaitInCover_vtbl *)&idAvoid_WaitInCover::`vftable';
  idState::idState(
    this: &this->stateMoveToGrenade,
    stateType: &idAvoid_MoveToGrenade::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveToGrenade.__vftable = (idAvoid_MoveToGrenade_vtbl *)&idAvoid_MoveToGrenade::`vftable';
  idState::idState(
    this: &this->stateKickGrenade,
    stateType: &idAvoid_KickGrenade::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateKickGrenade.__vftable = (idAvoid_KickGrenade_vtbl *)&idAvoid_KickGrenade::`vftable';
  idState::idState(this: &this->stateCower, stateType: &idAvoid_Cower::Type, childFSMType: nullptr, flags: 0);
  this->stateCower.__vftable = (idAvoid_Cower_vtbl *)&idAvoid_Cower::`vftable';
  idFiniteStateMachine::SetDefaultState(this, state: &this->stateDefault);
  return this;
}


// ========================================================================
// __unwind$489867_0
// EA  : 0x82AC1038
// RVA : 0x00AC1038
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void _unwind_489867_0()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489868
// EA  : 0x82AC1060
// RVA : 0x00AC1060
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void _unwind_489868()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$489869
// EA  : 0x82AC108C
// RVA : 0x00AC108C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void _unwind_489869()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$489870
// EA  : 0x82AC10B8
// RVA : 0x00AC10B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void _unwind_489870()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// __unwind$489871
// EA  : 0x82AC10E4
// RVA : 0x00AC10E4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void _unwind_489871()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 192));
}


// ========================================================================
// __unwind$489872
// EA  : 0x82AC1110
// RVA : 0x00AC1110
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void _unwind_489872()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 220));
}


// ========================================================================
// __unwind$489873
// EA  : 0x82AC113C
// RVA : 0x00AC113C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void _unwind_489873()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 248));
}


// ========================================================================
// __unwind$489874_0
// EA  : 0x82AC1168
// RVA : 0x00AC1168
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void _unwind_489874_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 276));
}


// ========================================================================
// __unwind$489875_0
// EA  : 0x82AC1194
// RVA : 0x00AC1194
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void _unwind_489875_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 304));
}


// ========================================================================
// ?Evaluate@AVOID_AvoidEntityInvalid@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC12F0
// RVA : 0x00AC12F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall AVOID_AvoidEntityInvalid::Evaluate(
        AVOID_AvoidEntityInvalid *this,
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

  value = ai->aiVolatile.memory.avoidEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return TRANSCODE_AVOID_AVOID_ENTITY_INVALID;
  v6 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v6 == nullptr )
    return TRANSCODE_AVOID_AVOID_ENTITY_INVALID;
  v7 = idEntity::CastTo(c: v6);
  if ( v7 == nullptr )
    return TRANSCODE_AVOID_AVOID_ENTITY_INVALID;
  v9 = !v7->IsDead(this: v7);
  result = 0;
  if ( !v9 )
    return TRANSCODE_AVOID_AVOID_ENTITY_INVALID;
  return result;
}


// ========================================================================
// ?Evaluate@AVOID_DiveDoneStillInDanger@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC1380
// RVA : 0x00AC1380
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall AVOID_DiveDoneStillInDanger::Evaluate(
        AVOID_DiveDoneStillInDanger *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idProjectile *v8; // r3
  idProjectile *v9; // r31
  idPhysics *Physics; // r3
  idProjectile_vtbl *v11; // r30
  int v12; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v14; // zf

  if ( !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) )
    return 0;
  value = ai->aiVolatile.memory.avoidEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = (idProjectile *)idEntity::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  v9 = idProjectile::CastTo(c: v8);
  if ( v9 == nullptr )
    return 0;
  Physics = idEntity::GetPhysics(this: ai);
  v11 = v9->__vftable;
  v12 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v14 = v11->PointInsideDamageRadius(this: v9, a2: (const idVec3 *)v12, a3: 0.0);
  result = TRANSCODE_AVOID_DIVE_DONE_STILL_IN_DANGER;
  if ( !v14 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idAvoid_Dive@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC1478
// RVA : 0x00AC1478
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_Dive::AIState_EnterState(idAvoid_Dive *this, idAI2 *ai, idEventArg *fsm, const int curTime)
{
  int value; // r6
  idEntity *v8; // r3

  ai->SetEventOverloadDisableFlags(this: ai, a2: AIEVENT_ALL);
  value = ai->aiVolatile.memory.avoidEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v8 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v8 != nullptr )
      idEntity::CastTo(c: v8);
  }
  idAI2::SetupDiveDodgeOrFlinchAction(this: ai, moveReason: 15, state: this, fsm);
}


// ========================================================================
// ?AIState_EnterState@idAvoid_RunAway@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC1510
// RVA : 0x00AC1510
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_RunAway::AIState_EnterState(idAvoid_RunAway *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  int value; // r6
  idEntity *v9; // r3
  idEventArg *v10; // r3
  idPhysics *Physics; // r3
  float *v12; // r3
  double v13; // fp12
  double v14; // fp10
  double v15; // fp11
  double v16; // fp0
  double v19; // fp5
  double v20; // fp1
  double v21; // fp0
  idAIOrientation *BodyOrientation; // r3
  double x; // fp0
  double z; // fp12
  idEventArg *v25; // r29
  idEventArg *v26; // r24
  const idEventArg *v27; // [sp+8h] [-288h]
  const idEventArg *v28; // [sp+Ch] [-284h]
  _BYTE v29[20]; // [sp+90h] [-200h] BYREF
  _BYTE v30[20]; // [sp+B0h] [-1E0h] BYREF
  _BYTE v31[20]; // [sp+D0h] [-1C0h] BYREF
  _BYTE v32[20]; // [sp+F0h] [-1A0h] BYREF
  idVec3 v33; // [sp+110h] [-180h] BYREF
  idEventArg v34; // [sp+120h] [-170h] BYREF
  idEventReceiver v35[2]; // [sp+140h] [-150h] BYREF
  char v36; // [sp+160h] [-130h]
  float v37; // [sp+164h] [-12Ch]
  float y; // [sp+168h] [-128h]
  float v39; // [sp+16Ch] [-124h]
  float v40[5]; // [sp+180h] [-110h] BYREF
  float v41[5]; // [sp+1A0h] [-F0h] BYREF
  _DWORD v42[5]; // [sp+1C0h] [-D0h] BYREF
  idEventArg v43; // [sp+1E0h] [-B0h] BYREF
  idEventArg v44[7]; // [sp+200h] [-90h] BYREF

  ai->SetWalkState(this: ai, a2: WALKSTATE_RUNNING);
  value = ai->aiVolatile.memory.avoidEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v9 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v9 != nullptr )
      idEntity::CastTo(c: v9);
  }
  if ( ai_useTransitions.valueInteger != 0 && ai_useStartTransitions.valueInteger != 0 )
  {
    ai->SetPosture(this: ai, a2: POSTURE_STANDING);
  }
  else
  {
    v10 = idEventArg::idEventArg(this: &v34, data: ai);
    idEventReceiver::ProcessEvent(
      this: v35,
      result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
      ev: *(const idEventDef **)&v10->type,
      arg1: (const idEventArg *)LODWORD(v10->value.v[1]));
  }
  Physics = idEntity::GetPhysics(this: ai);
  v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v13 = (float)(ai->aiVolatile.memory.avoidancePoint.y - v12[1]);
  v14 = (float)(ai->aiVolatile.memory.avoidancePoint.x - *v12);
  v15 = (float)(ai->aiVolatile.memory.avoidancePoint.z - v12[2]);
  v33.y = ai->aiVolatile.memory.avoidancePoint.y - v12[1];
  v33.x = v14;
  v33.z = v15;
  v16 = (float)((float)((float)v15 * (float)v15)
              + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)));
  if ( v16 > 1.0 )
  {
    _FP8 = (float)((float)((float)((float)v15 * (float)v15)
                         + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f6, f8, f0, f9 }
    v19 = __frsqrte(_FP6);
    v20 = (float)((float)-(float)((float)((float)((float)v19
                                                * (float)((float)((float)((float)v15 * (float)v15)
                                                                + (float)((float)((float)v14 * (float)v14)
                                                                        + (float)((float)v13 * (float)v13)))
                                                        * (float)0.5))
                                        * (float)v19)
                                - (float)1.5)
                * (float)v19);
    v21 = (float)((float)((float)-(float)((float)((float)((float)v19 * (float)((float)v16 * (float)0.5)) * (float)v19)
                                        - (float)1.5)
                        * (float)v19)
                * (float)((float)v16 * (float)0.5));
    v33.x = (float)v14
          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5)
                                                          * (float)v20)
                                                  * (float)((float)((float)((float)v15 * (float)v15)
                                                                  + (float)((float)((float)v14 * (float)v14)
                                                                          + (float)((float)v13 * (float)v13)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5)
                                                  * (float)v20))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5) * (float)v20));
    v33.y = (float)v13
          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5)
                                                          * (float)v20)
                                                  * (float)((float)((float)((float)v15 * (float)v15)
                                                                  + (float)((float)((float)v14 * (float)v14)
                                                                          + (float)((float)v13 * (float)v13)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5)
                                                  * (float)v20))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5) * (float)v20));
    v33.z = (float)v15
          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5)
                                                          * (float)v20)
                                                  * (float)((float)((float)((float)v15 * (float)v15)
                                                                  + (float)((float)((float)v14 * (float)v14)
                                                                          + (float)((float)v13 * (float)v13)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5)
                                                  * (float)v20))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5) * (float)v20));
  }
  BodyOrientation = idAI2::GetBodyOrientation(this: ai);
  idAIOrientation::SetIdealDir(this: BodyOrientation, ai, dir: &v33);
  idAI2::ClearAimFocus(this: ai);
  idAI2::ClearLookFocus(this: ai);
  idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
  v40[1] = vec3_origin.x;
  v40[2] = vec3_origin.y;
  v40[3] = vec3_origin.z;
  HIBYTE(v40[0]) = 118;
  v41[1] = 0.1;
  HIBYTE(v42[0]) = 105;
  v42[1] = 0;
  HIBYTE(v41[0]) = 102;
  HIBYTE(v35[0].__vftable) = 105;
  v35[0].listenerList = (idList<idEventReceiver *,5> *)2;
  v36 = 118;
  v34.type = 105;
  x = ai->aiVolatile.memory.avoidancePoint.x;
  v34.value.i = 13;
  z = ai->aiVolatile.memory.avoidancePoint.z;
  y = ai->aiVolatile.memory.avoidancePoint.y;
  v37 = x;
  v39 = z;
  v25 = idEventArg::idEventArg(this: &v43, data: ai);
  memcpy(Dst: v32, Src: v40, Size: sizeof(v32));
  memcpy(Dst: v31, Src: v42, Size: sizeof(v31));
  memcpy(Dst: v30, Src: v41, Size: sizeof(v30));
  memcpy(Dst: v29, Src: v35, Size: sizeof(v29));
  idEventReceiver::ProcessEvent(
    this: (idEventReceiver *)v44,
    result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
    ev: *(const idEventDef **)&v25->type,
    arg1: (const idEventArg *)LODWORD(v25->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v25->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v34.type, 32),
    arg4: (const idEventArg *)LODWORD(v34.value.v[1]),
    arg5: (const idEventArg *)LODWORD(v34.value.v[2]),
    arg6: v27,
    arg7: v28);
  v34.type = 105;
  HIBYTE(v35[0].__vftable) = 105;
  v34.value.i = 1;
  v35[0].listenerList = (idList<idEventReceiver *,5> *)500;
  v26 = idEventArg::idEventArg(this: v44, data: ai);
  idEventReceiver::ProcessEvent(
    this: (idEventReceiver *)&v43,
    result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
    ev: *(const idEventDef **)&v26->type,
    arg1: (const idEventArg *)LODWORD(v26->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v26->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v35[0].__vftable, 32));
  idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
}


// ========================================================================
// ?AIState_EnterState@idAvoid_MoveToCover@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC18E8
// RVA : 0x00AC18E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_MoveToCover::AIState_EnterState(
        idAvoid_MoveToCover *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  bfx::BinaryReplayLogOut v10[2]; // [sp+50h] [-50h] BYREF

  value = ai->aiVolatile.memory.avoidEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v9) != nullptr )
  {
    idAICover::idAICover(this: (idAICover *)v10);
    idAICover::idAICover(this: (idAICover *)v10);
    if ( (unsigned __int8)idAICover::IsValid(this: &ai->aiVolatile.memory.cachedCover) != 0 )
    {
      idAI2::ReserveCover(this: ai, cover: &ai->aiVolatile.memory.cachedCover);
      if ( (unsigned __int8)idAI2::StartMoveToCover(
                              this: ai,
                              cover: &ai->aiVolatile.memory.currentCover,
                              fsm,
                              state: this,
                              allowWalk: false,
                              curTime) != 0 )
      {
        ai->SetWalkState(this: ai, a2: WALKSTATE_RUNNING);
        idAI2::ClearAimFocus(this: ai);
        idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
      }
      else
      {
        idAICover::idAICover(this: (idAICover *)v10);
      }
    }
    else if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
    {
      idAnimBaseFSM::ClearDestination(this: &ai->aiVolatile.animation.animFSM);
    }
    else
    {
      idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
    }
    idPhysics_StaticMulti::UpdateTime(this: v10);
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// __unwind$491203
// EA  : 0x82AC1A50
// RVA : 0x00AC1A50
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void _unwind_491203()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 160 + 80));
}


// ========================================================================
// ?Evaluate@AVOID_CoverVulnerable@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC1A78
// RVA : 0x00AC1A78
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

int __fastcall AVOID_CoverVulnerable::Evaluate(
        AVOID_CoverVulnerable *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r4
  idAIEntityState *v10; // r3

  value = ai->aiVolatile.memory.avoidEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v8 = idEntity::CastTo(c: v7)) != nullptr
    && (v10 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8)) != nullptr
    && (*((_BYTE *)v10 + 541) & 0x80) != 0 )
  {
    return !idAIEntityState::IsVisible(this: v10) ? 0 : 0x14D;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?Evaluate@AVOID_WaitInCoverDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC1B48
// RVA : 0x00AC1B48
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

int __fastcall AVOID_WaitInCoverDone::Evaluate(
        AVOID_WaitInCoverDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r3
  idVehicle *v9; // r31
  idVehicle *v10; // r3
  idPhysics *Physics; // r3
  float *v12; // r31
  idPhysics *v13; // r3
  float *v14; // r3
  double v15; // fp10
  double v16; // fp6

  value = ai->aiVolatile.memory.avoidEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 334;
  v7 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr )
    return 334;
  v8 = idEntity::CastTo(c: v7);
  v9 = (idVehicle *)v8;
  if ( v8 == nullptr )
    return 334;
  if ( v8->IsDead(this: v8) )
    return 334;
  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v9) != 0 )
    return 334;
  v10 = idVehicle::CastTo(c: v9);
  if ( v10 != nullptr
    && (Physics = idEntity::GetPhysics(this: v10),
        v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0),
        v13 = idEntity::GetPhysics(this: ai),
        v14 = (float *)v13->GetOrigin(this: v13, a2: 0),
        v15 = (float)(v12[1] - v14[1]),
        (float)((float)((float)(v16 = (float)(v12[2] - v14[2])) * (float)v16)
              + (float)((float)((float)(*v12 - *v14) * (float)(*v12 - *v14)) + (float)((float)v15 * (float)v15))) > 128.0) )
  {
    return 334;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?AIState_EnterState@idAvoid_MoveToGrenade@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC1C90
// RVA : 0x00AC1C90
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_MoveToGrenade::AIState_EnterState(
        idAvoid_MoveToGrenade *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idEventArg *v8; // r3
  int value; // r5
  idEntity *v10; // r4
  int v11; // r3
  idEntity *v12; // r3
  idEventArg *v13; // r29
  idEventArg *v14; // r19
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

  ai->SetWalkState(this: ai, a2: WALKSTATE_RUNNING);
  if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED )
  {
    v8 = idEventArg::idEventArg(this: &v26, data: ai);
    idEventReceiver::ProcessEvent(
      this: v25,
      result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
      ev: *(const idEventDef **)&v8->type,
      arg1: (const idEventArg *)LODWORD(v8->value.v[1]));
  }
  value = ai->aiVolatile.memory.avoidEntity.spawnId.value;
  HIBYTE(v24[0]) = 118;
  v24[1] = vec3_origin.x;
  v24[2] = vec3_origin.y;
  v24[3] = vec3_origin.z;
  v10 = nullptr;
  v29[1] = 32.0;
  HIBYTE(v28[0]) = 105;
  v28[1] = 0;
  HIBYTE(v27[0]) = 105;
  v11 = gameLocal->spawnIds.ptr[value & 0x1FFF];
  v27[1] = 0;
  HIBYTE(v29[0]) = 102;
  HIBYTE(v25[0].__vftable) = 105;
  v25[0].listenerList = (idList<idEventReceiver *,5> *)2;
  if ( v11 == value >> 13 )
  {
    v12 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v12 != nullptr )
      v10 = idEntity::CastTo(c: v12);
  }
  v26.type = 105;
  v26.value.i = 14;
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
}


// ========================================================================
// ?Evaluate@AVOID_StopCowering@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC1EB8
// RVA : 0x00AC1EB8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall AVOID_StopCowering::Evaluate(
        AVOID_StopCowering *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v6; // r3
  idEntity *v7; // r3
  idEntity *v8; // r31
  idAIStateTransition::aiTransCode_t result; // r3
  bool v10; // zf

  value = ai->aiVolatile.memory.avoidEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return TRANSCODE_AVOID_STOP_COWERING;
  v6 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v6 == nullptr )
    return TRANSCODE_AVOID_STOP_COWERING;
  v7 = idEntity::CastTo(c: v6);
  v8 = v7;
  if ( v7 == nullptr )
    return TRANSCODE_AVOID_STOP_COWERING;
  if ( v7->IsDead(this: v7) )
    return TRANSCODE_AVOID_STOP_COWERING;
  v10 = (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v8) == 0;
  result = 0;
  if ( !v10 )
    return TRANSCODE_AVOID_STOP_COWERING;
  return result;
}


// ========================================================================
// ?CanUse@idAvoidFSM@@UBA_NPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AC1F68
// RVA : 0x00AC1F68
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

BOOL __fastcall idAvoidFSM::CanUse(idAvoidFSM *this, idFiniteStateMachine *fsm, const int curTime)
{
  idEntity *Owner; // r3
  idEntity *v4; // r29
  int size; // r8
  idEntity *v6; // r3
  idEntity *v7; // r3
  const idEntity *v8; // r30
  idProp_WeaponStatic *UsedProp; // r3
  char v10; // r11

  Owner = idFiniteStateMachine::GetOwner(this: fsm);
  v4 = Owner;
  if ( (*(_BYTE *)(*(_DWORD *)Owner[14].renderModelInfo.editorModel.baseBuffer + 86) & 0x80) == 0 )
    return false;
  if ( BYTE2(Owner[13].numPVSAreas) != 0 )
    return false;
  size = Owner[73].targets.size;
  if ( gameLocal->spawnIds.ptr[size & 0x1FFF] != size >> 13 )
    return false;
  v6 = gameLocal->entities.ptr[size & 0x1FFF];
  if ( v6 == nullptr )
    return false;
  v7 = idEntity::CastTo(c: v6);
  v8 = v7;
  if ( v7 == nullptr )
    return false;
  if ( v7->IsDead(this: v7) )
    return false;
  UsedProp = (idProp_WeaponStatic *)idAIMemory::GetUsedProp(this: (idAIMemory *)((char *)&v4[72].bindInfo + 112));
  if ( idProp_WeaponStatic::CastTo(c: UsedProp) != nullptr
    || idAIMemory::GetIgnoreProjectile(this: (idAIMemory *)((char *)&v4[72].bindInfo + 112)) == v8 )
  {
    return false;
  }
  if ( ((int (__fastcall *)(idEntity *))v4->__vftable[1].GetScale)(a1: v4) == 0
    || *(_DWORD *)(((int (__fastcall *)(idEntity *))v4->__vftable[1].GetScale)(a1: v4) + 72) == 3 )
  {
    return true;
  }
  if ( LOWORD(v4[41].clipModelInfo.numSides) >= 0x8000u
    || (v10 = 1, HIWORD(v4[41].clipModelInfo.clipModelName.str) >= 0x8000u) )
  {
    v10 = 0;
  }
  return v10 == 0;
}


// ========================================================================
// ?FindCoverFrom@@YA_NPAVidAI2@@PBVidEntity@@AAVidAICover@@@Z
// EA  : 0x82AC2240
// RVA : 0x00AC2240
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

int __fastcall FindCoverFrom(idAI2 *ai, const idEntity *avoid, idAICover *coverPoint)
{
  int value; // r8
  idEntity *v6; // r3
  idEntity *v7; // r5
  idPhysics *Physics; // r3
  const idVec3 *v9; // r3
  idList<idVehicleState *,5> v11; // [sp+50h] [-150h] BYREF
  idCoverQueryAvoid v12; // [sp+60h] [-140h] BYREF

  value = ai->aiVolatile.memory.avoidEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idEntity::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  idCoverQueryAvoid::idCoverQueryAvoid(
    this: &v12,
    ai,
    avoidEnt: v7,
    exclude: &ai->aiVolatile.memory.invalidCover,
    maxAvoidTime: 3.0);
  memset(&v11, 0, 14);
  *(_WORD *)&v11.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v11);
  idAI2::GetKnownEnemiesAsCoverTargets(this: ai, targets: &v11, minAwareness: AIAWARE_UNAWARE);
  Physics = idEntity::GetPhysics(this: ai);
  v9 = Physics->GetOrigin(this: Physics, a2: 0);
  if ( (unsigned __int8)idCoverQuery::Execute(
                          this: &v12,
                          targets: (const idList<idCoverQuery::coverTarget_t,5> *)&v11,
                          referencePoint: v9,
                          bestCover: coverPoint,
                          inAvoid: true) != 0
    && (unsigned __int8)idAICover::IsValid(this: coverPoint) != 0 )
  {
    idList<idThread *,58>::Clear(this: &v11);
    idCoverQuery::~idCoverQuery(this: &v12);
    return 1;
  }
  else
  {
    idList<idThread *,58>::Clear(this: &v11);
    idCoverQuery::~idCoverQuery(this: &v12);
    return 0;
  }
}


// ========================================================================
// __unwind$492029
// EA  : 0x82AC2388
// RVA : 0x00AC2388
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void _unwind_492029()
{
  int v0; // r12

  idCoverQueryTakeCover::~idCoverQueryTakeCover(this: (idCoverQueryClosest *)(v0 - 416 + 96));
}


// ========================================================================
// __unwind$492030
// EA  : 0x82AC23B0
// RVA : 0x00AC23B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void _unwind_492030()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 416 + 80));
}


// ========================================================================
// ?AvoidEntity@@YA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PBVidEntity@@AAVidVec3@@@Z
// EA  : 0x82AC23E0
// RVA : 0x00AC23E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall AvoidEntity(idAI2 *ai, idProjectile_Grenade *avoidEnt, idVec3 *bestPos)
{
  bool v5; // r27
  idVehicle *v6; // r3
  const idDeclAIBehavior *decl; // r22
  bool v8; // r24
  idPhysics *Physics; // r3
  const idVec3 *v10; // r23
  idPhysics *v11; // r3
  float *v12; // r30
  idPhysics *v13; // r3
  const idVec3 *v14; // r18
  idPhysics *v15; // r3
  double v16; // fp0
  double v17; // fp10
  double v20; // fp6
  double v21; // fp9
  double v22; // fp6
  double v23; // fp11
  double v24; // fp12
  double v25; // fp13
  double v26; // fp0
  double v27; // fp10
  double v28; // fp9
  double x; // fp13
  double y; // fp11
  double v31; // fp9
  double v32; // fp8
  double v33; // fp0
  double v34; // fp9
  double v35; // fp1
  double z; // fp8
  double v37; // fp7
  idProjectile *v38; // r3
  idAIEvent *Event; // r3
  double v40; // fp11
  double v41; // fp8
  double v42; // fp29
  double v45; // fp2
  double v46; // fp7
  double v47; // fp15
  idProjectile *v48; // r3
  char v49; // r11
  char v50; // r9
  char v51; // r11
  char v52; // r25
  bool v53; // r11
  char v54; // r29
  idAIStateTransition::aiTransCode_t result; // r3
  const idAAS2 *v56; // r3
  double v57; // fp19
  double v58; // fp31
  double v59; // fp16
  const idAAS2 *v60; // r3
  const idAASPosition *AASPosition; // r3
  idAASPosition *v62; // r20
  idPhysics *v63; // r3
  int *v64; // r3
  int v65; // r25
  int v66; // r28
  float v67; // r29
  idPhysics *v68; // r3
  float *v69; // r24
  const aas2Cover_t *v70; // r3
  double v71; // fp10
  double v72; // fp6
  idPhysics *v73; // r3
  float *v74; // r24
  const aas2Cover_t *Origin; // r3
  double v76; // fp10
  double v77; // fp6
  char IsValid; // r3
  double v79; // fp23
  double v80; // fp22
  double v81; // fp21
  signed int i; // r29
  const aas2Cover_t *v83; // r3
  double v84; // fp28
  double v85; // fp27
  const aas2Cover_t *v86; // r3
  idPhysics *v87; // r3
  double v88; // fp13
  int v89; // r22
  int travelFlags; // r15
  int v91; // r30
  int AreaNum; // r3
  __int64 v95; // r11
  double v96; // fp30
  double v97; // fp29
  double v98; // fp28
  double v99; // fp24
  __int64 v100; // r8
  __int64 v101; // r10
  va *v102; // r3
  const idVec3 *v103; // r15
  double v104; // fp13
  double v105; // fp12
  double v106; // fp9
  double v107; // fp7
  int v108; // r30
  idPhysics *v109; // r3
  const idVec3 *v110; // r3
  posture_t v111; // [sp+8h] [-13C8h]
  int v112; // [sp+Ch] [-13C4h]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v113; // [sp+10h] [-13C0h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v114; // [sp+14h] [-13BCh]
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v115; // [sp+18h] [-13B8h]
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v116; // [sp+1Ch] [-13B4h]
  double v117; // [sp+20h] [-13B0h]
  double v118; // [sp+28h] [-13A8h]
  double v119; // [sp+30h] [-13A0h]
  __int64 v120; // [sp+38h] [-1398h]
  int v121; // [sp+40h] [-1390h]
  int v122; // [sp+44h] [-138Ch]
  int v123; // [sp+48h] [-1388h]
  int v124; // [sp+4Ch] [-1384h]
  int v125; // [sp+50h] [-1380h]
  int v126; // [sp+54h] [-137Ch]
  int v127; // [sp+58h] [-1378h]
  int v128; // [sp+60h] [-1370h]
  int v129; // [sp+68h] [-1368h]
  int v130; // [sp+70h] [-1360h]
  int v131; // [sp+78h] [-1358h]
  int v132; // [sp+80h] [-1350h]
  int v133; // [sp+88h] [-1348h]
  float v134; // [sp+90h] [-1340h] BYREF
  float v135; // [sp+94h] [-133Ch]
  float v136; // [sp+98h] [-1338h]
  float v137; // [sp+A0h] [-1330h] BYREF
  float v138; // [sp+A4h] [-132Ch]
  float v139; // [sp+A8h] [-1328h]
  __int64 v140; // [sp+B0h] [-1320h]
  float v141; // [sp+B8h] [-1318h]
  bfx::BinaryReplayLogOut v142; // [sp+C0h] [-1310h] BYREF
  float v143; // [sp+DCh] [-12F4h]
  float v144; // [sp+E0h] [-12F0h]
  const idDeclAIBehavior *v145; // [sp+E4h] [-12ECh]
  idCVar *v146; // [sp+E8h] [-12E8h]
  const idVec3 *v147; // [sp+ECh] [-12E4h] BYREF
  float v148; // [sp+F0h] [-12E0h] BYREF
  float v149; // [sp+F4h] [-12DCh]
  float v150; // [sp+F8h] [-12D8h]
  idAngles v151; // [sp+100h] [-12D0h] BYREF
  idHandle<int,enum invalidAIEvent_t,-1> v152; // [sp+10Ch] [-12C4h] BYREF
  bfx::BinaryReplayLogOut v153; // [sp+110h] [-12C0h] BYREF
  idVec3 v154; // [sp+130h] [-12A0h] BYREF
  idColor v155; // [sp+140h] [-1290h] BYREF
  float v156[4]; // [sp+150h] [-1280h] BYREF
  float v157[4]; // [sp+160h] [-1270h] BYREF
  idVec3 v158; // [sp+170h] [-1260h] BYREF
  float v159[4]; // [sp+180h] [-1250h] BYREF
  float v160[4]; // [sp+190h] [-1240h] BYREF
  float v161[4]; // [sp+1A0h] [-1230h] BYREF
  float v162[4]; // [sp+1B0h] [-1220h] BYREF
  idVec3 v163; // [sp+1C0h] [-1210h] BYREF
  float v164[4]; // [sp+1D0h] [-1200h] BYREF
  float v165[22]; // [sp+1E0h] [-11F0h] BYREF
  int v166; // [sp+238h] [-1198h] BYREF
  int v167; // [sp+248h] [-1188h] BYREF
  idAIMoveParms v168; // [sp+260h] [-1170h] BYREF
  va v169; // [sp+2B0h] [-1120h] BYREF

  if ( avoidEnt == nullptr )
    return 0;
  v5 = idProjectile_Grenade::CastTo(c: avoidEnt) != nullptr;
  v6 = idVehicle::CastTo(c: (idVehicle *)avoidEnt);
  decl = ai->aiEditable.behaviors.decl;
  v8 = v6 != nullptr;
  v145 = decl;
  Physics = idEntity::GetPhysics(this: ai);
  v10 = Physics->GetOrigin(this: Physics, a2: 0);
  v147 = v10;
  v11 = idEntity::GetPhysics(this: ai);
  v12 = (float *)v11->GetGravityNormal(this: v11);
  v13 = idEntity::GetPhysics(this: avoidEnt);
  v14 = v13->GetOrigin(this: v13, a2: 0);
  v15 = idEntity::GetPhysics(this: avoidEnt);
  v15->GetLinearVelocity(this: (idPhysics *)&v134, result: (idVec3 *)v15, a3: 0);
  v16 = idMath::FLT_SMALLEST_NON_DENORMAL;
  v17 = (float)((float)(v134 * v134) + (float)(v135 * v135));
  _FP9 = (float)((float)((float)(v134 * v134) + (float)(v135 * v135)) - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f7, f9, f10, f0 }
  v20 = __frsqrte(_FP7);
  v21 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20
                                                                                      * (float)((float)((float)(v134 * v134) + (float)(v135 * v135))
                                                                                              * (float)0.5))
                                                                              * (float)v20)
                                                                      - (float)1.5)
                                                      * (float)v20)
                                              * (float)((float)((float)(v134 * v134) + (float)(v135 * v135)) * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v20
                                                                              * (float)((float)((float)(v134 * v134)
                                                                                              + (float)(v135 * v135))
                                                                                      * (float)0.5))
                                                                      * (float)v20)
                                                              - (float)1.5)
                                              * (float)v20))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v20
                                                      * (float)((float)((float)(v134 * v134) + (float)(v135 * v135))
                                                              * (float)0.5))
                                              * (float)v20)
                                      - (float)1.5)
                      * (float)v20));
  v22 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v134 * v134) + (float)(v135 * v135)) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                              * (float)v20)
                                                                                      * (float)((float)((float)(v134 * v134) + (float)(v135 * v135))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v134 * v134) + (float)(v135 * v135)) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                      * (float)v20))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v20
                                                                                              * (float)((float)((float)(v134 * v134) + (float)(v135 * v135)) * (float)0.5))
                                                                                      * (float)v20)
                                                                              - (float)1.5)
                                                              * (float)v20))
                                              * (float)((float)((float)(v134 * v134) + (float)(v135 * v135)) * (float)0.5))
                                      * (float)v21)
                              - (float)1.5)
              * (float)v21);
  v23 = (float)(v134 * (float)v22);
  v134 = v134 * (float)v22;
  v24 = (float)(v135 * (float)v22);
  v135 = v135 * (float)v22;
  v25 = (float)((float)v22 * (float)0.0);
  v136 = (float)v22 * (float)0.0;
  v146 = &ai_debugAvoid;
  if ( (float)((float)v22 * (float)v17) >= 50.0 )
  {
    v26 = (float)((float)(v12[2] * (float)v23) - (float)(*v12 * (float)((float)v22 * (float)0.0)));
    v27 = (float)((float)(*v12 * (float)v24) - (float)(v12[1] * (float)v23));
    v28 = (float)((float)(v12[1] * (float)((float)v22 * (float)0.0)) - (float)(v12[2] * (float)v24));
    if ( ai_debugLevel.valueInteger > 0 && ai_debugAvoid.valueInteger > 0 )
    {
      x = v14->x;
      y = v14->y;
      v157[2] = v14->z + (float)((float)v27 * (float)32.0);
      v157[1] = (float)((float)v26 * (float)32.0) + (float)y;
      v157[0] = (float)((float)v28 * (float)32.0) + (float)x;
      ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorOrange,
        a3: v14,
        a4: v157,
        a5: 8.0);
      v31 = v14->y;
      v32 = v14->x;
      v160[2] = v14->z + (float)(v136 * (float)32.0);
      v160[1] = (float)(v135 * (float)32.0) + (float)v31;
      v160[0] = (float)(v134 * (float)32.0) + (float)v32;
      ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorPink,
        a3: v14,
        a4: v160,
        a5: 8.0);
      v25 = v136;
      v24 = v135;
      v23 = v134;
    }
    v33 = v14->x;
    v34 = v14->y;
    v163.z = v14->z + (float)((float)v25 * (float)2048.0);
    v163.y = (float)((float)v24 * (float)2048.0) + (float)v34;
    v163.x = (float)((float)v23 * (float)2048.0) + (float)v33;
    v35 = idGeometry::PositionOnLineSegment(point: v10, start: v14, end: &v163);
    z = v14->z;
    v37 = v14->x;
    v16 = idMath::FLT_SMALLEST_NON_DENORMAL;
    v138 = (float)((float)(v135 * (float)2048.0) * (float)v35) + v14->y;
    v137 = (float)((float)(v134 * (float)2048.0) * (float)v35) + (float)v37;
    v139 = (float)z + (float)((float)(v136 * (float)2048.0) * (float)v35);
  }
  else
  {
    v137 = v14->x;
    v138 = v14->y;
    v139 = v14->z;
    v134 = vec3_origin.x;
    v135 = vec3_origin.y;
    v136 = vec3_origin.z;
  }
  if ( v5 )
  {
    v38 = idProjectile::CastTo(c: avoidEnt);
    if ( v38 != nullptr )
    {
      v152.value = v38->aiEventHandle.value;
      Event = idAIEventManager::GetEvent(this: &gameLocal->aiEventManager, handle: &v152);
      if ( Event != nullptr )
      {
        v137 = Event->origin.x;
        v142.m_buf.m_data = (unsigned __int8 *)&Event->origin;
        v138 = Event->origin.y;
        v139 = Event->origin.z;
      }
    }
    v16 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  v40 = (float)(v10->y - v138);
  v41 = (float)(v10->x - v137);
  v42 = 128.0;
  _FP5 = (float)((float)((float)((float)(v10->x - v137) * (float)(v10->x - v137))
                       + (float)((float)(v10->y - v138) * (float)(v10->y - v138)))
               - (float)v16);
  __asm { fsel      f3, f5, f6, f0 }
  v45 = __frsqrte(_FP3);
  v46 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v45
                                                                                      * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40))
                                                                                              * (float)0.5))
                                                                              * (float)v45)
                                                                      - (float)1.5)
                                                      * (float)v45)
                                              * (float)((float)((float)((float)v41 * (float)v41)
                                                              + (float)((float)v40 * (float)v40))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v45
                                                                              * (float)((float)((float)((float)v41 * (float)v41)
                                                                                              + (float)((float)v40 * (float)v40))
                                                                                      * (float)0.5))
                                                                      * (float)v45)
                                                              - (float)1.5)
                                              * (float)v45))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v45
                                                      * (float)((float)((float)((float)v41 * (float)v41)
                                                                      + (float)((float)v40 * (float)v40))
                                                              * (float)0.5))
                                              * (float)v45)
                                      - (float)1.5)
                      * (float)v45));
  v143 = (float)(v10->y - v138)
       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v45 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40)) * (float)0.5)) * (float)v45) - (float)1.5)
                                                                                               * (float)v45)
                                                                                       * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40))
                                                                                               * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)v45 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40)) * (float)0.5)) * (float)v45) - (float)1.5)
                                                                                       * (float)v45))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v45
                                                                                               * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40)) * (float)0.5))
                                                                                       * (float)v45)
                                                                               - (float)1.5)
                                                               * (float)v45))
                                               * (float)((float)((float)((float)v41 * (float)v41)
                                                               + (float)((float)v40 * (float)v40))
                                                       * (float)0.5))
                                       * (float)v46)
                               - (float)1.5)
               * (float)v46);
  *(float *)&v142.m_buf.m_tag = (float)v41
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v45 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40)) * (float)0.5)) * (float)v45) - (float)1.5) * (float)v45) * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40)) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v45 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40)) * (float)0.5)) * (float)v45) - (float)1.5) * (float)v45))
                                                                                              - (float)1.5)
                                                                              * (float)((float)-(float)((float)((float)((float)v45 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40)) * (float)0.5)) * (float)v45) - (float)1.5)
                                                                                      * (float)v45))
                                                                      * (float)((float)((float)((float)v41 * (float)v41)
                                                                                      + (float)((float)v40 * (float)v40))
                                                                              * (float)0.5))
                                                              * (float)v46)
                                                      - (float)1.5)
                                      * (float)v46);
  v144 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v45 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40)) * (float)0.5)) * (float)v45) - (float)1.5)
                                                                                               * (float)v45)
                                                                                       * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40))
                                                                                               * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)v45 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40)) * (float)0.5)) * (float)v45) - (float)1.5)
                                                                                       * (float)v45))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v45
                                                                                               * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40)) * (float)0.5))
                                                                                       * (float)v45)
                                                                               - (float)1.5)
                                                               * (float)v45))
                                               * (float)((float)((float)((float)v41 * (float)v41)
                                                               + (float)((float)v40 * (float)v40))
                                                       * (float)0.5))
                                       * (float)v46)
                               - (float)1.5)
               * (float)v46)
       * (float)0.0;
  v47 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v45 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40)) * (float)0.5)) * (float)v45) - (float)1.5) * (float)v45)
                                                                                              * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v45 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40)) * (float)0.5)) * (float)v45) - (float)1.5)
                                                                                              * (float)v45))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v45 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40)) * (float)0.5))
                                                                                              * (float)v45)
                                                                                      - (float)1.5)
                                                                      * (float)v45))
                                                      * (float)((float)((float)((float)v41 * (float)v41)
                                                                      + (float)((float)v40 * (float)v40))
                                                              * (float)0.5))
                                              * (float)v46)
                                      - (float)1.5)
                      * (float)v46)
              * (float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40)));
  v48 = idProjectile::CastTo(c: avoidEnt);
  if ( v48 != nullptr )
    v42 = (float)(idProjectile::GetMaxDamageRadius(this: v48) - (float)v47);
  if ( (*((_BYTE *)decl + 86) & 0x20) == 0 || (v49 = 1, !v5) )
    v49 = 0;
  v50 = v49;
  if ( (*((_BYTE *)decl + 86) & 0x10) == 0
    || !v8
    || (v51 = 1, ai->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType == ANIMWEBAI_RUNINDEXTYPE_INJURED) )
  {
    v51 = 0;
  }
  v52 = v51;
  v53 = (*((_BYTE *)decl + 86) & 0x40) != 0 && (v5 || v8);
  v54 = v53;
  if ( v50 != 0 )
  {
    idAICover::idAICover(this: (idAICover *)&v153);
    if ( (unsigned __int8)FindCoverFrom(ai, avoid: avoidEnt, coverPoint: (idAICover *)&v153) != 0 )
    {
      idAICover::operator=(this: &ai->aiVolatile.memory.cachedCover, other: (const idAICover *)&v153);
      idPhysics_StaticMulti::UpdateTime(this: &v153);
      return TRANSCODE_AVOID_SHOULD_TAKE_COVER;
    }
    idPhysics_StaticMulti::UpdateTime(this: &v153);
  }
  else if ( v52 == 0
         && !v53
         && (idAI2::CastTo(c: (idAI2 *)avoidEnt) != nullptr
          || idPlayer::CastTo(c: (idPlayer *)avoidEnt) != nullptr
          || idRobot::CastTo(c: (idRobot *)avoidEnt) != nullptr) )
  {
    v54 = 1;
  }
  if ( v52 != 0 && v42 < decl->dodging.diveDistance )
  {
    result = idAI2::ShouldDiveOrDodgeOrCrouch(this: ai, parentFSM: nullptr);
    if ( result != 0 )
    {
      ai->aiVolatile.memory.transCode = result;
      return result;
    }
  }
  v56 = ai->GetAAS(this: ai);
  if ( v54 != 0 && v56 != nullptr )
  {
    if ( (_S18_6 & 1) == 0 )
    {
      _S18_6 |= 1u;
      arcAngles = 45.0;
    }
    v57 = idVec3::ToYaw(this: (idVec3 *)&v142.m_buf.m_tag);
    v58 = (float)((float)v42 + (float)128.0);
    v59 = -3.4028235e38;
    v60 = ai->GetAAS(this: ai);
    AASPosition = idActor::GetAASPosition(this: ai, aas: v60);
    v165[0] = 0.0;
    v165[1] = 0.0;
    memset(&v165[4], 0, 12);
    v165[2] = 0.0;
    v165[3] = 0.0;
    v165[7] = 0.0;
    v165[10] = 0.0;
    v165[8] = 0.0;
    v165[11] = 0.0;
    v165[9] = 0.0;
    memset(&v165[15], 0, 24);
    v165[12] = 0.0;
    v165[13] = 0.0;
    v165[14] = 0.0;
    v62 = (idAASPosition *)AASPosition;
    v63 = idEntity::GetPhysics(this: ai);
    v64 = (int *)v63->GetOrigin(this: v63, a2: 0);
    v65 = *v64;
    v66 = v64[1];
    v67 = *((float *)v64 + 2);
    HIDWORD(v140) = *v64;
    LODWORD(v140) = v66;
    v141 = v67;
    idAICover::idAICover(this: (idAICover *)&v142, other: &ai->aiVolatile.memory.currentCover);
    if ( (unsigned __int8)idAICover::IsValid(this: (idAICover *)&v142) == 0
      || (v68 = idEntity::GetPhysics(this: ai),
          v69 = (float *)v68->GetOrigin(this: v68, a2: 0),
          v70 = idAICover::GetOrigin(this: (idAICover *)&v142),
          v71 = (float)(v70->origin.y - v69[1]),
          (float)((float)((float)(v72 = (float)(v70->origin.z - v69[2])) * (float)v72)
                + (float)((float)((float)(v70->origin.x - *v69) * (float)(v70->origin.x - *v69))
                        + (float)((float)v71 * (float)v71))) > 4096.0) )
    {
      idAICover::operator=(this: (idAICover *)&v142, other: &ai->aiVolatile.memory.lastCover);
      if ( (unsigned __int8)idAICover::IsValid(this: (idAICover *)&v142) != 0 )
      {
        v73 = idEntity::GetPhysics(this: ai);
        v74 = (float *)v73->GetOrigin(this: v73, a2: 0);
        Origin = idAICover::GetOrigin(this: (idAICover *)&v142);
        v76 = (float)(Origin->origin.y - v74[1]);
        v77 = (float)(Origin->origin.z - v74[2]);
        if ( (float)((float)((float)v77 * (float)v77)
                   + (float)((float)((float)(Origin->origin.x - *v74) * (float)(Origin->origin.x - *v74))
                           + (float)((float)v76 * (float)v76))) > 4096.0 )
          idAICover::operator=(this: (idAICover *)&v142, other: &ai->aiVolatile.memory.currentCover);
      }
    }
    IsValid = idAICover::IsValid(this: (idAICover *)&v142);
    v79 = v141;
    v80 = *((float *)&v140 + 1);
    v81 = *(float *)&v140;
    if ( IsValid != 0 )
    {
      for ( i = 0; i < 3; ++i )
      {
        if ( i != 2
          && (unsigned __int8)idAICover::GetFiringPoint(this: (idAICover *)&v142, user: ai, fp: i, firePoint: &v154) != 0 )
        {
          v83 = idAICover::GetOrigin(this: (idAICover *)&v142);
          v84 = (float)((float)(v154.x - v83->origin.x) * (float)2.5);
          v85 = (float)((float)(v154.y - v83->origin.y) * (float)2.5);
          v86 = idAICover::GetOrigin(this: (idAICover *)&v142);
          v80 = (float)(v86->origin.y + (float)v85);
          v81 = (float)(v86->origin.x + (float)v84);
          v87 = idEntity::GetPhysics(this: ai);
          v79 = v87->GetOrigin(this: v87, a2: 0)->z;
          if ( ai_debugLevel.valueInteger > 0 && ai_debugAvoid.valueInteger > 0 )
          {
            ((void (__fastcall *)(idRenderWorld *, const char *, idVec3 *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
              a1: clientGame->renderWorld,
              a2: "firepoint",
              a3: &v154,
              a4: clientGame->renderWorld->DebugText,
              a5: &idColor::colorGreen,
              a6: 1,
              a7: 3000,
              a8: 0,
              a9: 0.2);
            clientGame->renderWorld->DebugPoint(
              this: clientGame->renderWorld,
              a2: (const idVec4 *)&idColor::colorGreen,
              a3: &v154,
              a4: 3000,
              a5: false);
          }
        }
      }
      v141 = v79;
      v67 = v141;
      *((float *)&v140 + 1) = v80;
      v66 = v140;
      *(float *)&v140 = v81;
      v65 = HIDWORD(v140);
    }
    v88 = 0.0;
    v89 = 0;
    do
    {
      v158.x = 0.0;
      v158.z = 0.0;
      v158.y = (float)((float)v88 * arcAngles) + (float)v57;
      idAngles::ToForward(this: &v151, result: &v158);
      *(float *)&v153.m_buf.m_tag = v67;
      v153.m_buf.m_size = v65;
      v153.m_buf.m_cap = v66;
      v159[2] = (float)(v151.roll * (float)v58) + (float)v79;
      v159[1] = (float)v80 + (float)(v151.yaw * (float)v58);
      v159[0] = (float)(v151.pitch * (float)v58) + (float)v81;
      v142.m_buf.m_data = (unsigned __int8 *)v62->aas;
      travelFlags = ai->aiVolatile.aas.travelFlags;
      v91 = *(_DWORD *)v142.m_buf.m_data;
      AreaNum = idAASPosition::GetAreaNum(this: v62);
      LOBYTE(v126) = 1;
      (*(void (__fastcall **)(unsigned __int8 *, float *, int *, int, float *, int, _DWORD, int))(v91 + 64))(
        a1: v142.m_buf.m_data,
        a2: v165,
        a3: &v153.m_buf.m_size,
        a4: AreaNum,
        a5: v159,
        a6: travelFlags | 0x400000,
        a7: 0,
        a8: 1);
      _FP4 = (float)((float)1.0 - v165[0]);
      __asm { fsel      f3, f4, f0, f27 }
      HIDWORD(v95) = ai_debugLevel.valueInteger;
      v96 = (float)((float)_FP3 * (float)0.89999998);
      v97 = (float)((float)((float)_FP3 * (float)0.89999998) * (float)0.5);
      v149 = (float)v80 + (float)((float)(v151.yaw * (float)((float)_FP3 * (float)0.89999998)) * (float)v58);
      v150 = (float)((float)(v151.roll * (float)((float)_FP3 * (float)0.89999998)) * (float)v58) + (float)v79;
      v148 = (float)((float)(v151.pitch * (float)((float)_FP3 * (float)0.89999998)) * (float)v58) + (float)v81;
      v98 = (float)((float)((float)((float)((float)(v151.roll * v144)
                                          + (float)((float)(v151.pitch * *(float *)&v142.m_buf.m_tag)
                                                  + (float)(v151.yaw * v143)))
                                  + (float)1.0)
                          * (float)0.5)
                  * (float)0.5);
      v99 = (float)((float)((float)((float)_FP3 * (float)0.89999998) * (float)0.5)
                  + (float)((float)((float)((float)((float)(v151.roll * v144)
                                                  + (float)((float)(v151.pitch * *(float *)&v142.m_buf.m_tag)
                                                          + (float)(v151.yaw * v143)))
                                          + (float)1.0)
                                  * (float)0.5)
                          * (float)0.5));
      if ( ai_debugLevel.valueInteger > 0 && v146->valueInteger > 0 )
      {
        v155 = idColor::colorWhite;
        v164[0] = idColor::colorWhite.r;
        v164[2] = idColor::colorWhite.b;
        v164[1] = idColor::colorWhite.g;
        v164[3] = idColor::colorWhite.a;
        clientGame->renderWorld->DebugLine(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)v164,
          a3: (const idVec3 *)&v153.m_buf.m_size,
          a4: (const idVec3 *)&v148,
          a5: 3000,
          a6: false);
        v120 = 0;
        LODWORD(v100) = 0;
        v119 = v97;
        HIDWORD(v100) = LODWORD(v97);
        v118 = v98;
        v117 = v99;
        v102 = va::va(
                 this: &v169,
                 fmt: "%5.3f = (%.2f + %.2f)*%.2f",
                 a3: __SPAIR64__(LODWORD(v99), LODWORD(v98)),
                 a4: v100,
                 a5: v101,
                 a6: v111,
                 a7: v112,
                 a8: (int)v113,
                 a9: (int)v114,
                 a10: (int)v115,
                 a11: (int)v116,
                 v99,
                 v98,
                 v97,
                 0.0);
        LOBYTE(v126) = 0;
        ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
          a1: clientGame->renderWorld,
          a2: v102,
          a3: &v148,
          a4: clientGame->renderWorld->__vftable,
          a5: &v155,
          a6: 1,
          a7: 3000,
          a8: 0,
          a9: 0.5);
      }
      if ( v99 <= v59 || v96 <= 0.33000001 )
      {
        v103 = bestPos;
      }
      else
      {
        v103 = bestPos;
        v104 = v149;
        v59 = v99;
        v105 = v150;
        bestPos->x = v148;
        bestPos->y = v104;
        bestPos->z = v105;
      }
      LODWORD(v95) = ++v89;
      v140 = v95;
      v88 = (float)v95;
    }
    while ( v88 < 8.0 );
    if ( ai_debugLevel.valueInteger > 0 && v146->valueInteger > 0 )
    {
      v106 = v14->z;
      v107 = v14->y;
      v162[0] = (float)(v134 * (float)512.0) + v14->x;
      v162[2] = (float)v106 + (float)(v136 * (float)512.0);
      v162[1] = (float)(v135 * (float)512.0) + (float)v107;
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorCyan,
        a3: v14,
        a4: (const idVec3 *)v162,
        a5: 3000,
        a6: false);
      v156[1] = v138;
      *(float *)&v142.m_buf.m_data = v138;
      v156[0] = v137;
      v156[2] = v139 + (float)8.0;
      clientGame->renderWorld->DebugPoint(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorYellow,
        a3: (const idVec3 *)v156,
        a4: 3000,
        a5: false);
      v161[2] = (float)((float)v47 * v144) + v139;
      v161[1] = (float)(v143 * (float)v47) + v138;
      v161[0] = (float)(*(float *)&v142.m_buf.m_tag * (float)v47) + v137;
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorBlue,
        a3: &v137,
        a4: v161,
        a5: 8.0);
      ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, const idVec3 *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorRed,
        a3: v147,
        a4: v103,
        a5: 8.0);
      clientGame->renderWorld->DebugPoint(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorGreen,
        a3: v103,
        a4: 3000,
        a5: false);
    }
    if ( v59 <= 0.0 )
    {
      decl = v145;
    }
    else
    {
      idAIMoveParms::idAIMoveParms(this: &v168);
      decl = v145;
      v108 = 14;
      if ( (*((_BYTE *)&v145->movementBehaviors + 40) & 0x20) != 0 )
        v108 = 30;
      v109 = idEntity::GetPhysics(this: ai);
      v142.m_buf.m_cap = -1;
      v142.m_buf.m_size = -1;
      v110 = v109->GetOrigin(this: v109, a2: 0);
      idAIMoveParms::Init(
        this: &v168,
        moveReason_: AIMOVEREASON_AVOID_AVOID_ENTITY,
        startOrigin_: v110,
        goalOrigin_: v103,
        goalEntity_: nullptr,
        goalOrientation_: &quat_identity,
        goalScenePoint_: nullptr,
        goalTolerance_: 0.1,
        intermediateTolerance_: 0.1,
        arrivalAction_: (const aiArrivalAction_t)&v142.m_buf.m_size,
        arrivalPosture_: v111,
        flags_: v112,
        sourceSubWeb_: v113,
        sourceState_: v114,
        destSubWeb_: v115,
        destState_: v116,
        a17: SHIDWORD(v117),
        a18: SLODWORD(v117),
        a19: SHIDWORD(v118),
        a20: SLODWORD(v118),
        a21: SHIDWORD(v119),
        a22: SLODWORD(v119),
        a23: SHIDWORD(v120),
        a24: v120,
        a25: v121,
        a26: v122,
        a27: v123,
        a28: v124,
        a29: v125,
        a30: v126,
        a31: v127,
        a32: AIARRIVAL_STOP,
        a33: v128,
        a34: POSTURE_STANDING,
        a35: v129,
        a36: v108,
        a37: v130,
        a38: (__int16 *)&v142.m_buf.m_size + 1,
        a39: v131,
        arrivalAction__0: (__int16 *)&v142.m_buf.m_cap,
        a41: v132,
        arrivalPosture_a: (__int16 *)&v142.m_buf.m_size,
        a43: v133,
        flags_a: (__int16 *)&v142.m_buf.m_cap + 1);
      if ( ai->aiVolatile.physics.moveState.TestMove(
             this: &ai->aiVolatile.physics.moveState,
             a2: &v168,
             a3: (idVec3 *)&v167,
             a4: (idVec3 *)&v166,
             a5: (int *)&v147) <= AIMOVESTATUS_MOVING )
      {
        idPhysics_StaticMulti::UpdateTime(this: &v142);
        return TRANSCODE_AVOID_SHOULD_RUN_AWAY;
      }
    }
    idPhysics_StaticMulti::UpdateTime(this: &v142);
  }
  if ( (*((_BYTE *)decl + 86) & 8) == 0 )
    return 0;
  result = TRANSCODE_AVOID_SHOULD_COWER;
  if ( ai->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType == ANIMWEBAI_RUNINDEXTYPE_INJURED )
    return 0;
  return result;
}


// ========================================================================
// __unwind$492178
// EA  : 0x82AC3344
// RVA : 0x00AC3344
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void _unwind_492178()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 5072 + 272));
}


// ========================================================================
// __unwind$492179
// EA  : 0x82AC336C
// RVA : 0x00AC336C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void _unwind_492179()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 5072 + 192));
}


// ========================================================================
// ?AIState_EnterState@idAvoid_Default@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC3398
// RVA : 0x00AC3398
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_Default::AIState_EnterState(idAvoid_Default *this, idAI2 *ai, idAIFSM *fsm, const int curTime)
{
  idEntityPtr<idEntity const > *p_avoidEntity; // r28
  int value; // r7
  idEntity *v7; // r3
  idProjectile *v8; // r3
  idProjectile *v9; // r3
  idProjectile *v10; // r29
  idAIGameState *p_aiGameState; // r27
  const idEntity *AttackerEntity; // r3
  const idSpawnId *v13; // r29
  const idAILogic *v14; // r3
  const idSpawnId *v15; // r8
  idEntity *v16; // r3
  idProjectile_Grenade *v17; // r4
  idAIStateTransition::aiTransCode_t v18; // r3
  double x; // fp0
  double y; // fp13
  double z; // fp12
  double v22; // fp11
  double v23; // fp10
  double v24; // fp9
  idSpawnId v25; // [sp+50h] [-80h] BYREF
  idSpawnId v26; // [sp+54h] [-7Ch] BYREF
  idVec3 v27; // [sp+58h] [-78h] BYREF
  idAILogic v28[3]; // [sp+70h] [-60h] BYREF

  p_avoidEntity = &ai->aiVolatile.memory.avoidEntity;
  ai->aiVolatile.memory.lastAvoidTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  value = ai->aiVolatile.memory.avoidEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = (idProjectile *)idEntity::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  v9 = idProjectile::CastTo(c: v8);
  v10 = v9;
  if ( v9 != nullptr && idProjectile::GetAttacker(this: v9) != nullptr )
  {
    p_aiGameState = &gameLocal->aiGameState;
    idSpawnId::idSpawnId(this: &v25, ent: ai);
    AttackerEntity = idProjectile::GetAttackerEntity(this: v10);
    v13 = idSpawnId::idSpawnId(this: &v26, ent: AttackerEntity);
    v14 = idAILogic::idAILogic(this: v28, ai);
    idAIWorldState::AddEntityState(
      this: &ai->aiVolatile.world.worldState,
      gameState: p_aiGameState,
      owner: v14,
      entId: v13,
      stimulusType: AISTIMULUS_GUNFIRE,
      stimulusAmount: 1.0,
      sourceId: v15);
  }
  idAI2::UpdateTravelFlags(this: ai);
  if ( gameLocal->spawnIds.ptr[p_avoidEntity->spawnId.value & 0x1FFF] == p_avoidEntity->spawnId.value >> 13
    && (v16 = gameLocal->entities.ptr[p_avoidEntity->spawnId.value & 0x1FFF]) != nullptr )
  {
    v17 = (idProjectile_Grenade *)idEntity::CastTo(c: v16);
  }
  else
  {
    v17 = nullptr;
  }
  v18 = AvoidEntity(ai, avoidEnt: v17, bestPos: &v27);
  x = v27.x;
  y = v27.y;
  z = v27.z;
  v22 = v27.x;
  v23 = v27.y;
  v24 = v27.z;
  ai->aiVolatile.memory.transCode = v18;
  ai->aiVolatile.memory.avoidanceDir.x = x;
  ai->aiVolatile.memory.avoidanceDir.y = y;
  ai->aiVolatile.memory.avoidanceDir.z = z;
  ai->aiVolatile.memory.avoidancePoint.x = v22;
  ai->aiVolatile.memory.avoidancePoint.y = v23;
  ai->aiVolatile.memory.avoidancePoint.z = v24;
}


// ========================================================================
// ?AIState_ExitState@idAvoid_Dive@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC3550
// RVA : 0x00AC3550
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_Dive::AIState_ExitState(idAvoid_Dive *this, idAI2 *ai, idAIFSM *fsm, const int curTime)
{
  ai->aiVolatile.memory.lastDiveTime = idGameTimeManager::GetGameMs(
                                         this: &clientGame->gameTimeManager,
                                         type: GAMETIME_SCALED);
  if ( fsm->lastTransitionCode == 327 )
    ai->aiVolatile.memory.avoidEntity.spawnId.value = 0x1FFF;
  ai->SetEventOverloadDisableFlags(this: ai, a2: AIEVENT_NONE);
}


// ========================================================================
// ?AIState_ExitState@idAvoid_RunAway@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC35E0
// RVA : 0x00AC35E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_RunAway::AIState_ExitState(idAvoid_RunAway *this, idAI2 *ai, idAIFSM *fsm, const int curTime)
{
  if ( fsm->lastTransitionCode != 331 )
    ai->aiVolatile.memory.avoidEntity.spawnId.value = 0x1FFF;
}


// ========================================================================
// ?AIState_ExitState@idAvoid_MoveToCover@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC3600
// RVA : 0x00AC3600
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_avoid.cpp
// ========================================================================

void __fastcall idAvoid_MoveToCover::AIState_ExitState(
        idAvoid_MoveToCover *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int lastTransitionCode; // r11
  idAICover *p_currentCover; // r30

  lastTransitionCode = fsm->lastTransitionCode;
  p_currentCover = &ai->aiVolatile.memory.currentCover;
  if ( lastTransitionCode != 330 )
  {
    if ( lastTransitionCode == 331 )
    {
      if ( (unsigned __int8)idAICover::IsValid(this: &ai->aiVolatile.memory.currentCover) != 0 )
      {
        idAICover::MakeUnusable(this: p_currentCover, duration: 5000);
        idAI2::ReleaseCover(this: ai);
      }
    }
    else
    {
      ai->aiVolatile.memory.avoidEntity.spawnId.value = 0x1FFF;
    }
  }
}

