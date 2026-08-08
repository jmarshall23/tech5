
// ========================================================================
// ?InternalInitState@idIdleTrackFriendly_Default@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD4360
// RVA : 0x00AD4360
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

void __fastcall idIdleTrackFriendly_Default::InternalInitState(
        idIdleTrackFriendly_Default *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &ITF_NoTarget::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &ITF_Track::Type, nextStateType: &idIdleTrackFriendly_Track::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &ITF_PlayerApproaching::Type,
    nextStateType: &idIdleTrackFriendly_EndTrack::Type);
}


// ========================================================================
// ?InternalInitState@idIdleTrackFriendly_Track@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD43E0
// RVA : 0x00AD43E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

void __fastcall idIdleTrackFriendly_Track::InternalInitState(
        idIdleTrackFriendly_Track *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &ITF_EndTrack::Type,
    nextStateType: &idIdleTrackFriendly_EndTrack::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &ITF_PlayerApproaching::Type,
    nextStateType: &idIdleTrackFriendly_EndTrack::Type);
}


// ========================================================================
// ?Evaluate@ITF_Finished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD4430
// RVA : 0x00AD4430
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

int __fastcall ITF_Finished::Evaluate(
        ITF_Finished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 447;
}


// ========================================================================
// ?InternalInitState@idIdleTrackFriendly_EndTrack@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AD4438
// RVA : 0x00AD4438
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

void __fastcall idIdleTrackFriendly_EndTrack::InternalInitState(
        idIdleTrackFriendly_EndTrack *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &ITF_Finished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InitStates@idIdleTrackFriendlyFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82AD4450
// RVA : 0x00AD4450
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

void __fastcall idIdleTrackFriendlyFSM::InitStates(
        idIdleTrackFriendlyFSM *this,
        const idFiniteStateMachineParams *params)
{
  idAIFSM::InitStates(this, params);
  this->AddState(this, a2: &this->stateDefault);
  this->AddState(this, a2: &this->stateTrack);
  this->AddState(this, a2: &this->stateEndTrack);
}


// ========================================================================
// ??1idIdleTrackFriendlyFSM@@UAA@XZ
// EA  : 0x82AD44D0
// RVA : 0x00AD44D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

void __fastcall idIdleTrackFriendlyFSM::~idIdleTrackFriendlyFSM(idIdleTrackFriendlyFSM *this)
{
  this->__vftable = (idIdleTrackFriendlyFSM_vtbl *)&idIdleTrackFriendlyFSM::`vftable';
  idState::~idState(this: &this->stateEndTrack);
  idState::~idState(this: &this->stateTrack);
  idState::~idState(this: &this->stateDefault);
  idFiniteStateMachine::~idFiniteStateMachine(this);
}


// ========================================================================
// __unwind$487847
// EA  : 0x82AD4534
// RVA : 0x00AD4534
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

void _unwind_487847()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$487848
// EA  : 0x82AD455C
// RVA : 0x00AD455C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

void _unwind_487848()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// __unwind$487849
// EA  : 0x82AD4588
// RVA : 0x00AD4588
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

void _unwind_487849()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// ?AIState_EnterState@idIdleTrackFriendly_Default@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD45C0
// RVA : 0x00AD45C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

void __fastcall idIdleTrackFriendly_Default::AIState_EnterState(
        idIdleTrackFriendly_Default *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  __int16 v6; // [sp+50h] [-160h] BYREF
  idDeclAnimWeb v7; // [sp+52h] [-15Eh] BYREF

  HIBYTE(fsm[1].callback) = idAI2::GetEnableHeadTracking(this: ai);
  BYTE1(fsm[1].callback) = ai->aiVolatile.focus.enableAutoFocus;
  *((_BYTE *)&ai->aiVolatile + 49704) |= 0x10u;
  idAnimator_AnimWeb::GetCurStateIndex(
    this: (idAnimator_AnimWeb *)&v6,
    result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)&ai->aiVolatile.animation);
  BYTE2(v7.networkID) = 0;
  BYTE2(v7.md5Checksum) = 0;
  *(idResourceList **)((char *)&v7.resourceListPtr + 2) = (idResourceList *)((char *)&v7.md5Checksum + 2);
  *(idResource **)((char *)&v7.nextOnHashChain + 2) = nullptr;
  *(const char **)((char *)&v7.resourceError + 2) = (const char *)-2147483392;
  LOWORD(fsm[1].stateFrame) = v6;
  idAI2::GetIdleStateName(this: ai, name: (idStr *)((char *)&v7.nextOnHashChain + 2));
  HIWORD(fsm[1].stateFrame) = HIWORD(idDeclAnimWeb::GetStateIndexForName(
                                       this: &v7,
                                       result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
                                       name: *(const char **)((char *)&v7.resourceListPtr + 2))->__vftable);
  idStr::FreeData(this: (idStr *)((char *)&v7.nextOnHashChain + 2));
}


// ========================================================================
// __unwind$488073
// EA  : 0x82AD4674
// RVA : 0x00AD4674
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

void _unwind_488073()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 96));
}


// ========================================================================
// ??0idIdleTrackFriendlyFSM@@QAA@XZ
// EA  : 0x82AD46A8
// RVA : 0x00AD46A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

idIdleTrackFriendlyFSM *__fastcall idIdleTrackFriendlyFSM::idIdleTrackFriendlyFSM(idIdleTrackFriendlyFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: "FSM_IdleTrackFriendly");
  this->__vftable = (idIdleTrackFriendlyFSM_vtbl *)&idIdleTrackFriendlyFSM::`vftable';
  idState::idState(
    this: &this->stateDefault,
    stateType: &idIdleTrackFriendly_Default::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateDefault.__vftable = (idIdleTrackFriendly_Default_vtbl *)&idIdleTrackFriendly_Default::`vftable';
  idState::idState(
    this: &this->stateTrack,
    stateType: &idIdleTrackFriendly_Track::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateTrack.__vftable = (idIdleTrackFriendly_Track_vtbl *)&idIdleTrackFriendly_Track::`vftable';
  idState::idState(
    this: &this->stateEndTrack,
    stateType: &idIdleTrackFriendly_EndTrack::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateEndTrack.__vftable = (idIdleTrackFriendly_EndTrack_vtbl *)&idIdleTrackFriendly_EndTrack::`vftable';
  this->target.spawnId.value = 0x1FFF;
  this->idleStateIndex.value = -1;
  this->startStateIndex.value = -1;
  this->oldEnableHeadTracking = false;
  this->oldEnableAutoFocus = false;
  idFiniteStateMachine::SetDefaultState(this, state: &this->stateDefault);
  return this;
}


// ========================================================================
// __unwind$488198
// EA  : 0x82AD479C
// RVA : 0x00AD479C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

void _unwind_488198()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$488199
// EA  : 0x82AD47C4
// RVA : 0x00AD47C4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

void _unwind_488199()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$488200
// EA  : 0x82AD47F0
// RVA : 0x00AD47F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

void _unwind_488200()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$488201
// EA  : 0x82AD481C
// RVA : 0x00AD481C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

void _unwind_488201()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// ?Evaluate@ITF_PlayerApproaching@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD48A8
// RVA : 0x00AD48A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall ITF_PlayerApproaching::Evaluate(
        ITF_PlayerApproaching *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIEventSphere *eventData; // r31
  int value; // r10
  idEntity *v8; // r3
  idPlayer *v9; // r3
  idPlayer *v10; // r3
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
  v12 = (unsigned __int8)idAI2::PlayerApproachingInteraction(this: ai, player: v10) != 0;
  result = TRANSCODE_ITF_PLAYER_APPROACHING;
  if ( !v12 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@ITF_NoTarget@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD4968
// RVA : 0x00AD4968
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

int __fastcall ITF_NoTarget::Evaluate(
        ITF_NoTarget *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int nextUpdateTime; // r10
  idEntity *v6; // r3

  nextUpdateTime = parentFSM[1].nextUpdateTime;
  if ( gameLocal->spawnIds.ptr[nextUpdateTime & 0x1FFF] == nextUpdateTime >> 13
    && (v6 = gameLocal->entities.ptr[nextUpdateTime & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v6) != nullptr )
  {
    return 0;
  }
  else
  {
    return 445;
  }
}


// ========================================================================
// ?Evaluate@ITF_Track@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD49E8
// RVA : 0x00AD49E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall ITF_Track::Evaluate(
        ITF_Track *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int nextUpdateTime; // r10
  idEntity *v6; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v8; // zf

  nextUpdateTime = parentFSM[1].nextUpdateTime;
  if ( gameLocal->spawnIds.ptr[nextUpdateTime & 0x1FFF] != nextUpdateTime >> 13 )
    return 0;
  v6 = gameLocal->entities.ptr[nextUpdateTime & 0x1FFF];
  if ( v6 == nullptr )
    return 0;
  v8 = idEntity::CastTo(c: v6) != nullptr;
  result = TRANSCODE_ITF_TRACK;
  if ( !v8 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@ITF_EndTrack@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AD4A58
// RVA : 0x00AD4A58
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

int __fastcall ITF_EndTrack::Evaluate(
        ITF_EndTrack *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int nextUpdateTime; // r10
  idEntity *v7; // r3
  idEntity *v8; // r4

  nextUpdateTime = parentFSM[1].nextUpdateTime;
  if ( gameLocal->spawnIds.ptr[nextUpdateTime & 0x1FFF] == nextUpdateTime >> 13
    && (v7 = gameLocal->entities.ptr[nextUpdateTime & 0x1FFF]) != nullptr )
  {
    v8 = idEntity::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  return (unsigned __int8)idAI2::CanIdleTrackFriendlyTarget(this: ai, friendlyTarget: v8) != 0 ? 0 : 0x1BE;
}


// ========================================================================
// ?AIState_Work@idIdleTrackFriendly_Track@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD4AE8
// RVA : 0x00AD4AE8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

void __fastcall idIdleTrackFriendly_Track::AIState_Work(
        idIdleTrackFriendly_Track *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAnimator_AnimWeb *CurStateIndex; // r3
  int stateFrame_low; // r11
  int nextUpdateTime; // r9
  idEntity *v9; // r3
  idEntity *v10; // r4
  char v11; // [sp+50h] [-20h] BYREF

  if ( HIWORD(fsm[1].stateFrame) < 0x8000u )
  {
    CurStateIndex = idAnimator_AnimWeb::GetCurStateIndex(
                      this: (idAnimator_AnimWeb *)&v11,
                      result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)&ai->aiVolatile.animation);
    stateFrame_low = SLOWORD(fsm[1].stateFrame);
    if ( SHIWORD(CurStateIndex->__vftable) != stateFrame_low || stateFrame_low == SHIWORD(fsm[1].stateFrame) )
    {
      HIWORD(fsm[1].stateFrame) = -1;
      idAI2::SetEnableHeadTracking(this: ai, enable: true);
      idAI2::SetEnableAutoFocus(this: ai, enable: false);
      nextUpdateTime = fsm[1].nextUpdateTime;
      if ( gameLocal->spawnIds.ptr[nextUpdateTime & 0x1FFF] == nextUpdateTime >> 13
        && (v9 = gameLocal->entities.ptr[nextUpdateTime & 0x1FFF]) != nullptr )
      {
        v10 = idEntity::CastTo(c: v9);
      }
      else
      {
        v10 = nullptr;
      }
      idAI2::SetLookFocusEntity(this: ai, ent: v10, keepFocusInView: false, aimPoint: AIMPOINT_HEAD, timeout: -1);
    }
  }
}


// ========================================================================
// ?AIState_EnterState@idIdleTrackFriendly_EndTrack@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AD4BE0
// RVA : 0x00AD4BE0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_idletrackfriendly.cpp
// ========================================================================

void __fastcall idIdleTrackFriendly_EndTrack::AIState_EnterState(
        idIdleTrackFriendly_EndTrack *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  fsm[1].nextUpdateTime = 0x1FFF;
  idAI2::SetEnableHeadTracking(this: ai, enable: HIBYTE(fsm[1].callback));
  idAI2::SetEnableAutoFocus(this: ai, enable: BYTE1(fsm[1].callback));
  *((_BYTE *)&ai->aiVolatile + 49704) &= ~0x10u;
  idAI2::ClearLookFocus(this: ai);
}

