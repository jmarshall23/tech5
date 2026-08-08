
// ========================================================================
// ?SetChildFSM@idState@@QAAXPAVidFiniteStateMachine@@0@Z
// EA  : 0x82AF6758
// RVA : 0x00AF6758
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idState::SetChildFSM(idState *this, idFiniteStateMachine *parentFSM, idFiniteStateMachine *childFSM_)
{
  this->childFSM = childFSM_;
}


// ========================================================================
// ?IsChildDone@idState@@QBA_NXZ
// EA  : 0x82AF6760
// RVA : 0x00AF6760
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

int __fastcall idState::IsChildDone(idState *this)
{
  idFiniteStateMachine *childFSM; // r3
  int Status; // r3
  unsigned __int8 v4; // r11

  childFSM = this->childFSM;
  if ( childFSM == nullptr )
    return 1;
  Status = idFiniteStateMachine::GetStatus(this: childFSM);
  if ( Status == 0 )
    return 1;
  v4 = 0;
  if ( Status == 2 )
    return 1;
  return v4;
}


// ========================================================================
// ?CanUse@idState@@QBA_NPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AF67C0
// RVA : 0x00AF67C0
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

idDeclInfo *__fastcall idState::CanUse(idDecl *this)
{
  return this->GetDeclInfo(this);
}


// ========================================================================
// ?SetEnterFailed@idState@@QAAX_N@Z
// EA  : 0x82AF67D0
// RVA : 0x00AF67D0
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idState::SetEnterFailed(idState *this, bool failed)
{
  this->enterFailed = failed;
}


// ========================================================================
// ??1idState@@UAA@XZ
// EA  : 0x82AF67D8
// RVA : 0x00AF67D8
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idState::~idState(idState *this)
{
  idStateData *stateData; // r11

  stateData = this->stateData;
  this->__vftable = (idState_vtbl *)&idState::`vftable';
  if ( stateData != nullptr )
  {
    --stateData->refCount;
    this->stateData = nullptr;
  }
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// ?StartChildFSM@idState@@QAAXPAVidFiniteStateMachine@@HH@Z
// EA  : 0x82AF6808
// RVA : 0x00AF6808
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idState::StartChildFSM(idState *this, idFiniteStateMachine *parentFSM, int transCode, int curTime)
{
  idState *v8; // r3
  idFiniteStateMachine *v9; // r3

  v8 = parentFSM->GetDoneState(this: parentFSM);
  idFiniteStateMachine::SetCurrentState(this: parentFSM, newState: v8, fromTransType: nullptr, transCode, curTime);
  v9 = parentFSM->manager->FindFSM_3(this: parentFSM->manager, a2: this->childFSMType);
  this->childFSM = v9;
  v9->Restart(this: v9, a2: parentFSM, a3: curTime);
}


// ========================================================================
// ?InitState@idState@@QAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AF6890
// RVA : 0x00AF6890
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idState::InitState(idState *this, const idFiniteStateMachine *fsm)
{
  this->InternalInitState(this, a2: fsm);
  this->stateData->flags |= 0x8000u;
}


// ========================================================================
// ?IsInterruptible@idState@@QBA_NXZ
// EA  : 0x82AF68D8
// RVA : 0x00AF68D8
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

BOOL __fastcall idState::IsInterruptible(idState *this)
{
  idFiniteStateMachine *childFSM; // r3

  if ( (this->stateData->flags & 1) != 0 || this->tempUninterruptible )
    return false;
  childFSM = this->childFSM;
  return childFSM == nullptr
      || idFiniteStateMachine::GetStatus(this: childFSM) != 1
      || idFiniteStateMachine::IsInterruptible(this: this->childFSM);
}


// ========================================================================
// ?Save@idState@@UBAXPBVidFiniteStateMachine@@AAVidFile_String@@PBD@Z
// EA  : 0x82AF6AB0
// RVA : 0x00AF6AB0
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idState::Save(
        idState *this,
        const idFiniteStateMachine *parentFSM,
        idFile_String *file,
        const char *indent)
{
  const char *Classname; // r3
  __int64 v9; // r10
  __int64 v10; // r8
  va *v11; // r3
  idStateData *stateData; // r11
  __int64 v13; // r10
  __int64 v14; // r6
  idList<idStateData::transition_t,111> *p_transitions; // r30
  __int64 v16; // r8
  va *v17; // r3
  __int64 v18; // r10
  __int64 v19; // r6
  __int64 v20; // r8
  int v21; // r29
  int v22; // r28
  va *v23; // r3
  unsigned int i; // r5
  int v25; // r11
  __int64 v26; // r10
  __int64 v27; // r8
  __int64 v28; // r6
  int v29; // r3
  va *v30; // r3
  unsigned int j; // r5
  int v32; // [sp+8h] [-10D8h]
  int v33; // [sp+8h] [-10D8h]
  int v34; // [sp+8h] [-10D8h]
  int v35; // [sp+8h] [-10D8h]
  int v36; // [sp+Ch] [-10D4h]
  int v37; // [sp+Ch] [-10D4h]
  int v38; // [sp+Ch] [-10D4h]
  int v39; // [sp+Ch] [-10D4h]
  int v40; // [sp+10h] [-10D0h]
  int v41; // [sp+10h] [-10D0h]
  int v42; // [sp+10h] [-10D0h]
  int v43; // [sp+10h] [-10D0h]
  int v44; // [sp+14h] [-10CCh]
  int v45; // [sp+14h] [-10CCh]
  int v46; // [sp+14h] [-10CCh]
  int v47; // [sp+14h] [-10CCh]
  int v48; // [sp+18h] [-10C8h]
  int v49; // [sp+18h] [-10C8h]
  int v50; // [sp+18h] [-10C8h]
  int v51; // [sp+18h] [-10C8h]
  int v52; // [sp+1Ch] [-10C4h]
  int v53; // [sp+1Ch] [-10C4h]
  int v54; // [sp+1Ch] [-10C4h]
  int v55; // [sp+1Ch] [-10C4h]
  idStr v56; // [sp+50h] [-1090h] BYREF
  idStr v57; // [sp+70h] [-1070h] BYREF
  va v58; // [sp+90h] [-1050h] BYREF

  Classname = idClass::GetClassname(this);
  v11 = va::va(
          this: &v58,
          fmt: "%sstate \"%s\" {\n",
          a3: __SPAIR64__((unsigned int)indent, (unsigned int)Classname),
          a4: v10,
          a5: v9,
          a6: v32,
          a7: v36,
          a8: v40,
          a9: v44,
          a10: v48,
          a11: v52);
  idFile_String::operator+=(this: file, str: v11->buffer);
  stateData = this->stateData;
  LODWORD(v13) = "Could not find AI state, idVS_ds_Car_Chase! ";
  HIDWORD(v14) = indent;
  LODWORD(v14) = stateData->transitions.num;
  p_transitions = &stateData->transitions;
  v17 = va::va(
          this: &v58,
          fmt: "%s\ttransitions %d {\n",
          a3: v14,
          a4: v16,
          a5: v13,
          a6: v33,
          a7: v37,
          a8: v41,
          a9: v45,
          a10: v49,
          a11: v53);
  idFile_String::operator+=(this: file, str: v17->buffer);
  idStr::idStr(this: &v57, text: indent);
  idStr::Append(this: &v57, text: "\t\t");
  LODWORD(v20) = p_transitions->num;
  v21 = 0;
  if ( (int)v20 > 0 )
  {
    v22 = 0;
    do
    {
      p_transitions->list[v22].transition->Save(
        this: p_transitions->list[v22].transition,
        a2: file,
        a3: v57.data,
        a4: (const idList<idStateTransition::transDest_t,5> *)&p_transitions->list[v22].destinations);
      HIDWORD(v18) = p_transitions->num;
      ++v21;
      ++v22;
    }
    while ( v21 < SHIDWORD(v18) );
  }
  HIDWORD(v19) = indent;
  v23 = va::va(
          this: &v58,
          fmt: "%s\t}\n",
          a3: v19,
          a4: v20,
          a5: v18,
          a6: v34,
          a7: v38,
          a8: v42,
          a9: v46,
          a10: v50,
          a11: v54);
  for ( i = 0; v23->buffer[i] != 0; ++i )
    ;
  file->Write(this: file, a2: v23, a3: i);
  idStr::idStr(this: &v56, text: indent);
  v25 = v56.len + 2;
  if ( v56.allocedAndFlag >= 0 )
  {
    if ( v25 > (v56.allocedAndFlag & 0x7FFFFFFF) )
      idStr::ReAllocate(this: &v56, amount: (v25 >> 1) + v25, keepold: true);
  }
  else if ( v25 > (v56.allocedAndFlag & 0x7FFFFFFF)
         && AssertFailed(
              file: "w:\\tech5\\shared\\idlib\\text/Str.h",
              line: 463,
              expression: "amount <= GetAlloced()",
              inlineBreak: true) )
  {
    __trap();
  }
  LODWORD(v26) = 9;
  HIDWORD(v26) = v56.data;
  LODWORD(v27) = 0;
  v56.data[v56.len] = 9;
  HIDWORD(v27) = v56.data;
  LODWORD(v28) = v56.len++;
  v56.data[v56.len] = 0;
  if ( this->childFSMType != nullptr )
  {
    v29 = ((int (__fastcall *)(idFSMManager *))parentFSM->manager->FindFSM_3)(a1: parentFSM->manager);
    if ( v29 != 0 )
      (*(void (__fastcall **)(int, idFile_String *, char *))(*(_DWORD *)v29 + 36))(a1: v29, a2: file, a3: v56.data);
  }
  HIDWORD(v28) = indent;
  v30 = va::va(
          this: &v58,
          fmt: "%s}\n",
          a3: v28,
          a4: v27,
          a5: v26,
          a6: v35,
          a7: v39,
          a8: v43,
          a9: v47,
          a10: v51,
          a11: v55);
  for ( j = 0; v30->buffer[j] != 0; ++j )
    ;
  file->Write(this: file, a2: v30, a3: j);
  idStr::FreeData(this: &v56);
  idStr::FreeData(this: &v57);
}


// ========================================================================
// __unwind$489742
// EA  : 0x82AF6D2C
// RVA : 0x00AF6D2C
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_489742()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4320 + 112));
}


// ========================================================================
// __unwind$489743
// EA  : 0x82AF6D54
// RVA : 0x00AF6D54
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_489743()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4320 + 80));
}


// ========================================================================
// ??0idState@@QAA@ABVidTypeInfo@@PBV1@F@Z
// EA  : 0x82AF6F18
// RVA : 0x00AF6F18
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

idState *__fastcall idState::idState(
        idState *this,
        const idTypeInfo *stateType,
        const idTypeInfo *childFSMType,
        unsigned __int16 flags)
{
  idStateData *v8; // r3
  idStateData *v9; // r3
  idStateData *stateData; // r11

  idEventReceiver::idEventReceiver(this);
  this->childFSMType = childFSMType;
  this->stateData = nullptr;
  this->__vftable = (idState_vtbl *)&idState::`vftable';
  this->childFSM = nullptr;
  this->enterFailed = false;
  this->tempUninterruptible = false;
  v8 = idClassFactory<idStateTransition,1024,111>::Find(
         this: &gameLocal->stateDataFactory,
         hashKey: stateType->classname);
  if ( v8 != nullptr )
  {
    this->stateData = v8;
  }
  else
  {
    v9 = idClassFactory<idStateTransition,1024,111>::Create(
           this: &gameLocal->stateDataFactory,
           classType: &idStateData::Type,
           hashKey: stateType->classname);
    this->stateData = v9;
    v9->flags = flags;
  }
  stateData = this->stateData;
  if ( stateData != nullptr )
    ++stateData->refCount;
  return this;
}


// ========================================================================
// __unwind$490181
// EA  : 0x82AF6FE0
// RVA : 0x00AF6FE0
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490181()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 144 + 164));
}


// ========================================================================
// ?EnterState@idState@@QAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AF7010
// RVA : 0x00AF7010
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idState::EnterState(idState *this, idFiniteStateMachine *fsm, int curTime)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  idState_vtbl *v8; // r9
  idPLogScope v9[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "idState::EnterState");
  LODWORD(v6) = "idState::EnterState";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: v9, pl: &pLog, gMask: v6, label: v7);
  v8 = this->__vftable;
  this->enterFailed = false;
  this->tempUninterruptible = false;
  v8->InternalEnterState(this, a2: fsm, a3: curTime);
  idPLogScope::~idPLogScope(this: v9);
  RD_EventEnd();
}


// ========================================================================
// __unwind$490352
// EA  : 0x82AF7090
// RVA : 0x00AF7090
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490352()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$490353
// EA  : 0x82AF70B8
// RVA : 0x00AF70B8
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490353()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?ExitState@idState@@QAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AF70E8
// RVA : 0x00AF70E8
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idState::ExitState(idState *this, idFiniteStateMachine *fsm, int curTime)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  idFiniteStateMachine *childFSM; // r3
  idFiniteStateMachine *v9; // r3
  idState *v10; // r3
  idPLogScope v11[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "idState::ExitState");
  LODWORD(v6) = "idState::ExitState";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: v11, pl: &pLog, gMask: v6, label: v7);
  childFSM = this->childFSM;
  this->tempUninterruptible = false;
  if ( childFSM != nullptr && idFiniteStateMachine::GetStatus(this: childFSM) == 1 )
  {
    v9 = this->childFSM;
    if ( v9->curState != nullptr )
    {
      v10 = v9->GetDoneState(this: v9);
      idFiniteStateMachine::SetCurrentState(
        this: this->childFSM,
        newState: v10,
        fromTransType: nullptr,
        transCode: 2,
        curTime);
    }
  }
  this->InternalExitState(this, a2: fsm, a3: curTime);
  idPLogScope::~idPLogScope(this: v11);
  RD_EventEnd();
}


// ========================================================================
// __unwind$490389_0
// EA  : 0x82AF71B4
// RVA : 0x00AF71B4
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490389_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$490390_0
// EA  : 0x82AF71DC
// RVA : 0x00AF71DC
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490390_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?Work@idState@@QAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AF7210
// RVA : 0x00AF7210
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idState::Work(idState *this, idFiniteStateMachine *fsm, int curTime)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  idPLogScope v8[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "idState::DoWork");
  LODWORD(v6) = "idState::DoWork";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: v8, pl: &pLog, gMask: v6, label: v7);
  this->InternalWork(this, a2: fsm, a3: curTime);
  idPLogScope::~idPLogScope(this: v8);
  RD_EventEnd();
}


// ========================================================================
// __unwind$490426
// EA  : 0x82AF7284
// RVA : 0x00AF7284
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490426()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$490427
// EA  : 0x82AF72AC
// RVA : 0x00AF72AC
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490427()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?ReenterState@idState@@QAAXPAVidFiniteStateMachine@@HH@Z
// EA  : 0x82AF72E0
// RVA : 0x00AF72E0
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idState::ReenterState(idState *this, idFiniteStateMachine *fsm, int transCode, int curTime)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  idPLogScope v10[10]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "idState::ReenterState");
  LODWORD(v8) = "idState::ReenterState";
  HIDWORD(v8) = 6;
  idPLogScope::idPLogScope(this: v10, pl: &pLog, gMask: v8, label: v9);
  this->InternalReenterState(this, a2: fsm, a3: transCode, a4: curTime);
  idPLogScope::~idPLogScope(this: v10);
  RD_EventEnd();
}


// ========================================================================
// __unwind$490457
// EA  : 0x82AF735C
// RVA : 0x00AF735C
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490457()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$490458
// EA  : 0x82AF7384
// RVA : 0x00AF7384
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490458()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?IsStateWaiting@idState@@QBA_NPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AF73B8
// RVA : 0x00AF73B8
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

int __fastcall idState::IsStateWaiting(idState *this, idFiniteStateMachine *fsm, int curTime)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int v8; // r30
  idPLogScope v10[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "idState::IsStateWaiting");
  LODWORD(v6) = "idState::IsStateWaiting";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: v10, pl: &pLog, gMask: v6, label: v7);
  v8 = ((int (__fastcall *)(idState *, idFiniteStateMachine *, int))this->InternalIsStateWaiting)(
         a1: this,
         a2: fsm,
         a3: curTime);
  idPLogScope::~idPLogScope(this: v10);
  RD_EventEnd();
  return v8;
}


// ========================================================================
// __unwind$490489
// EA  : 0x82AF7434
// RVA : 0x00AF7434
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490489()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$490490
// EA  : 0x82AF745C
// RVA : 0x00AF745C
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490490()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?EvaluateTransitions@idState@@QAA_NPAVidFiniteStateMachine@@ABV?$idList@Utransition_t@idStateData@@$0GP@@@HAAUtransResult_t@idStateData@@@Z
// EA  : 0x82AF7490
// RVA : 0x00AF7490
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

int __fastcall idState::EvaluateTransitions(
        idState *this,
        idFiniteStateMachine *fsm,
        const idList<idStateData::transition_t,111> *transitions,
        int curTime,
        idStateData::transResult_t *result)
{
  const char *Classname; // r3
  unsigned int v11; // r3
  const char *v12; // r7
  int v13; // r21
  int v14; // r23
  idStateData::transition_t *v15; // r30
  int v16; // r27
  int v17; // r28
  int v18; // r29
  idStateTransition::transDest_t *v19; // r11
  int transCode; // r10
  idState *State; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v23; // r30
  int v24; // r3
  __int64 totalTicks; // r11
  __int64 v26; // r9
  idPLog *v28; // r29
  idPLog::logEntry_t *v29; // r30
  int v30; // r3
  __int64 v31; // r11
  __int64 v32; // r9
  idPLogScope v33; // [sp+58h] [-88h] BYREF

  Classname = idClass::GetClassname(this);
  RD_EventBegin(name: Classname);
  v11 = (unsigned int)idClass::GetClassname(this);
  idPLogScope::idPLogScope(this: &v33, pl: &::pLog, gMask: v11 | 0x600000000LL, label: v12);
  v13 = 0;
  if ( transitions->num <= 0 )
  {
LABEL_12:
    result->nextStateType = nullptr;
    result->transitionType = nullptr;
    result->transCode = 0;
    if ( v33.logIndex >= 0 )
    {
      pLog = v33.pLog;
      v23 = &v33.pLog->logEntries.list[v33.logIndex];
      v24 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v23->totalTicks;
      HIDWORD(totalTicks) = v23->parent;
      LODWORD(v26) = v24 - totalTicks;
      v23->totalTicks = v26;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
    RD_EventEnd();
    return 0;
  }
  else
  {
    v14 = 0;
    while ( 1 )
    {
      v15 = &transitions->list[v14];
      v16 = v15->transition->Evaluate(this: v15->transition, a2: fsm, a3: this, a4: curTime);
      if ( v16 != 0 )
      {
        v17 = 0;
        if ( v15->destinations.num > 0 )
          break;
      }
LABEL_11:
      ++v13;
      ++v14;
      if ( v13 >= transitions->num )
        goto LABEL_12;
    }
    v18 = 0;
    while ( 1 )
    {
      v19 = &v15->destinations.list[v18];
      transCode = v19->transCode;
      if ( transCode == 0 || transCode == v16 )
      {
        if ( (v15->transition->flags & 1) == 0 )
          break;
        State = idFiniteStateMachine::FindState(this: fsm, stateType: v19->nextStateType);
        if ( State->InternalCanUse(this: State, a2: fsm, a3: curTime) )
          break;
      }
      ++v17;
      ++v18;
      if ( v17 >= v15->destinations.num )
        goto LABEL_11;
    }
    result->transitionType = v15->transition->GetType(this: v15->transition);
    result->nextStateType = v15->destinations.list[v17].nextStateType;
    result->transCode = v16;
    if ( v33.logIndex >= 0 )
    {
      v28 = v33.pLog;
      v29 = &v33.pLog->logEntries.list[v33.logIndex];
      v30 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v31 = v29->totalTicks;
      HIDWORD(v31) = v29->parent;
      LODWORD(v32) = v30 - v31;
      v29->totalTicks = v32;
      v28->lastEntry = HIDWORD(v31);
    }
    RD_EventEnd();
    return 1;
  }
}


// ========================================================================
// __unwind$490522
// EA  : 0x82AF7684
// RVA : 0x00AF7684
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490522()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$490523
// EA  : 0x82AF76AC
// RVA : 0x00AF76AC
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490523()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 88));
}


// ========================================================================
// ?EvaluateTransitions@idState@@QAA_NPAVidFiniteStateMachine@@HAAUtransResult_t@idStateData@@@Z
// EA  : 0x82AF76D8
// RVA : 0x00AF76D8
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

int __fastcall idState::EvaluateTransitions(
        idState *this,
        idFiniteStateMachine *fsm,
        int curTime,
        idStateData::transResult_t *result)
{
  return idState::EvaluateTransitions(this, fsm, transitions: &this->stateData->transitions, curTime, result);
}


// ========================================================================
// ?EvaluateEventTransitions@idState@@QAA_NPAVidFiniteStateMachine@@HAAUtransResult_t@idStateData@@@Z
// EA  : 0x82AF76F0
// RVA : 0x00AF76F0
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

int __fastcall idState::EvaluateEventTransitions(
        idState *this,
        idFiniteStateMachine *fsm,
        int curTime,
        idStateData::transResult_t *result)
{
  return idState::EvaluateTransitions(this, fsm, transitions: &this->stateData->eventTransitions, curTime, result);
}


// ========================================================================
// ?EvaluateFSMEventTransitions@idState@@QAA_NPAVidFiniteStateMachine@@HAAUtransResult_t@idStateData@@@Z
// EA  : 0x82AF7708
// RVA : 0x00AF7708
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

int __fastcall idState::EvaluateFSMEventTransitions(
        idState *this,
        idFiniteStateMachine *fsm,
        int curTime,
        idStateData::transResult_t *result)
{
  return idState::EvaluateTransitions(this, fsm, transitions: &this->stateData->fsmEventTransitions, curTime, result);
}


// ========================================================================
// ??0idStateData@@QAA@XZ
// EA  : 0x82AF7920
// RVA : 0x00AF7920
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

idStateData *__fastcall idStateData::idStateData(idStateData *this)
{
  this->__vftable = (idStateData_vtbl *)&idStateData::`vftable';
  this->transitions.granularity = 0;
  this->transitions.memTag = 111;
  this->transitions.listStatic = 0;
  this->transitions.list = nullptr;
  this->transitions.size = 0;
  this->transitions.num = 0;
  this->eventTransitions.granularity = 0;
  this->eventTransitions.memTag = 111;
  this->eventTransitions.listStatic = 0;
  this->eventTransitions.list = nullptr;
  this->eventTransitions.size = 0;
  this->eventTransitions.num = 0;
  this->fsmEventTransitions.granularity = 0;
  this->fsmEventTransitions.memTag = 111;
  this->fsmEventTransitions.listStatic = 0;
  this->fsmEventTransitions.list = nullptr;
  this->fsmEventTransitions.size = 0;
  this->fsmEventTransitions.num = 0;
  this->flags = 0;
  this->refCount = 0;
  return this;
}


// ========================================================================
// __unwind$490689_0
// EA  : 0x82AF79B4
// RVA : 0x00AF79B4
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490689_0()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 32 + 52));
}


// ========================================================================
// __unwind$490690
// EA  : 0x82AF79DC
// RVA : 0x00AF79DC
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490690()
{
  int v0; // r12

  idList<idComponentTimeLine::idTimeLineEntity,5>::~idList<idComponentTimeLine::idTimeLineEntity,5>(this: (idList<idVOChainState,5> *)(*(_DWORD *)(v0 - 32 + 52) + 4));
}


// ========================================================================
// __unwind$490691
// EA  : 0x82AF7A08
// RVA : 0x00AF7A08
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490691()
{
  int v0; // r12

  idList<idComponentTimeLine::idTimeLineEntity,5>::~idList<idComponentTimeLine::idTimeLineEntity,5>(this: (idList<idVOChainState,5> *)(*(_DWORD *)(v0 - 32 + 52) + 20));
}


// ========================================================================
// ??1idStateData@@UAA@XZ
// EA  : 0x82AF7A40
// RVA : 0x00AF7A40
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idStateData::~idStateData(idStateData *this)
{
  char *list; // r3
  char *v3; // r3
  char *v4; // r3
  char *v5; // r3
  char *v6; // r3
  char *v7; // r3

  this->__vftable = (idStateData_vtbl *)&idStateData::`vftable';
  gameLocal->GetGameFlags(this: gameLocal);
  if ( this->transitions.listStatic == 0 || this->transitions.listStatic == 2 )
  {
    list = (char *)this->transitions.list;
    if ( list != nullptr )
      idListArrayDelete<idStateData::transition_t>(ptr: list, num: this->transitions.size);
    this->transitions.list = nullptr;
    this->transitions.size = 0;
  }
  this->transitions.num = 0;
  if ( this->eventTransitions.listStatic == 0 || this->eventTransitions.listStatic == 2 )
  {
    v3 = (char *)this->eventTransitions.list;
    if ( v3 != nullptr )
      idListArrayDelete<idStateData::transition_t>(ptr: v3, num: this->eventTransitions.size);
    this->eventTransitions.list = nullptr;
    this->eventTransitions.size = 0;
  }
  this->eventTransitions.num = 0;
  if ( this->fsmEventTransitions.listStatic == 0 || this->fsmEventTransitions.listStatic == 2 )
  {
    v4 = (char *)this->fsmEventTransitions.list;
    if ( v4 != nullptr )
      idListArrayDelete<idStateData::transition_t>(ptr: v4, num: this->fsmEventTransitions.size);
    this->fsmEventTransitions.list = nullptr;
    this->fsmEventTransitions.size = 0;
  }
  this->fsmEventTransitions.num = 0;
  if ( this->fsmEventTransitions.listStatic == 0 || this->fsmEventTransitions.listStatic == 2 )
  {
    v5 = (char *)this->fsmEventTransitions.list;
    if ( v5 != nullptr )
      idListArrayDelete<idStateData::transition_t>(ptr: v5, num: this->fsmEventTransitions.size);
    this->fsmEventTransitions.list = nullptr;
    this->fsmEventTransitions.size = 0;
  }
  this->fsmEventTransitions.num = 0;
  if ( this->eventTransitions.listStatic == 0 || this->eventTransitions.listStatic == 2 )
  {
    v6 = (char *)this->eventTransitions.list;
    if ( v6 != nullptr )
      idListArrayDelete<idStateData::transition_t>(ptr: v6, num: this->eventTransitions.size);
    this->eventTransitions.list = nullptr;
    this->eventTransitions.size = 0;
  }
  this->eventTransitions.num = 0;
  if ( this->transitions.listStatic == 0 || this->transitions.listStatic == 2 )
  {
    v7 = (char *)this->transitions.list;
    if ( v7 != nullptr )
      idListArrayDelete<idStateData::transition_t>(ptr: v7, num: this->transitions.size);
    this->transitions.list = nullptr;
    this->transitions.size = 0;
  }
  this->transitions.num = 0;
  this->__vftable = (idStateData_vtbl *)&idClass::`vftable';
}


// ========================================================================
// __unwind$490762
// EA  : 0x82AF7BCC
// RVA : 0x00AF7BCC
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490762()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$490763_0
// EA  : 0x82AF7BF4
// RVA : 0x00AF7BF4
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490763_0()
{
  int v0; // r12

  idList<idComponentTimeLine::idTimeLineEntity,5>::~idList<idComponentTimeLine::idTimeLineEntity,5>(this: (idList<idVOChainState,5> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$490764_0
// EA  : 0x82AF7C20
// RVA : 0x00AF7C20
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490764_0()
{
  int v0; // r12

  idList<idComponentTimeLine::idTimeLineEntity,5>::~idList<idComponentTimeLine::idTimeLineEntity,5>(this: (idList<idVOChainState,5> *)(*(_DWORD *)(v0 - 112 + 132) + 20));
}


// ========================================================================
// __unwind$490765
// EA  : 0x82AF7C4C
// RVA : 0x00AF7C4C
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490765()
{
  int v0; // r12

  idList<idComponentTimeLine::idTimeLineEntity,5>::~idList<idComponentTimeLine::idTimeLineEntity,5>(this: (idList<idVOChainState,5> *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// ?Condense@idStateData@@QAAXXZ
// EA  : 0x82AF7C78
// RVA : 0x00AF7C78
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idStateData::Condense(idStateData *this)
{
  int v2; // r29
  int v3; // r30
  int v4; // r30
  int v5; // r29
  int v6; // r30
  int v7; // r29

  v2 = 0;
  if ( this->transitions.num > 0 )
  {
    v3 = 0;
    do
    {
      idList<idStateTransition::transDest_t,111>::Resize(
        this: (idList<swfGlyphEntry_t,72> *)&this->transitions.list[v3].destinations,
        newsize: this->transitions.list[v3].destinations.num);
      ++v2;
      ++v3;
    }
    while ( v2 < this->transitions.num );
  }
  idList<idStateData::transition_t,5>::Resize(
    this: (idList<idStateData::transition_t,5> *)&this->transitions,
    newsize: this->transitions.num);
  v4 = 0;
  if ( this->eventTransitions.num > 0 )
  {
    v5 = 0;
    do
    {
      idList<idStateTransition::transDest_t,111>::Resize(
        this: (idList<swfGlyphEntry_t,72> *)&this->eventTransitions.list[v5].destinations,
        newsize: this->eventTransitions.list[v5].destinations.num);
      ++v4;
      ++v5;
    }
    while ( v4 < this->eventTransitions.num );
  }
  idList<idStateData::transition_t,5>::Resize(
    this: (idList<idStateData::transition_t,5> *)&this->eventTransitions,
    newsize: this->eventTransitions.num);
  v6 = 0;
  if ( this->fsmEventTransitions.num > 0 )
  {
    v7 = 0;
    do
    {
      idList<idStateTransition::transDest_t,111>::Resize(
        this: (idList<swfGlyphEntry_t,72> *)&this->fsmEventTransitions.list[v7].destinations,
        newsize: this->fsmEventTransitions.list[v7].destinations.num);
      ++v6;
      ++v7;
    }
    while ( v6 < this->fsmEventTransitions.num );
  }
  idList<idStateData::transition_t,5>::Resize(
    this: (idList<idStateData::transition_t,5> *)&this->fsmEventTransitions,
    newsize: this->fsmEventTransitions.num);
}


// ========================================================================
// ?Condense@idState@@QAAXXZ
// EA  : 0x82AF7D68
// RVA : 0x00AF7D68
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idState::Condense(idState *this)
{
  idStateData *stateData; // r3

  stateData = this->stateData;
  if ( stateData != nullptr )
    idStateData::Condense(this: stateData);
}


// ========================================================================
// ?AllocTransition@idStateData@@AAAXAAV?$idList@Utransition_t@idStateData@@$04@@PBVidFiniteStateMachine@@ABVidTypeInfo@@2H@Z
// EA  : 0x82AF7DE8
// RVA : 0x00AF7DE8
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idStateData::AllocTransition(
        idStateData *this,
        idList<idStateData::transition_t,5> *list,
        const idFiniteStateMachine *fsm,
        const idTypeInfo *transType,
        const idTypeInfo *nextStateType,
        int transCode)
{
  int v10; // r29
  int v11; // r28
  idStateData::transition_t *v12; // r28
  int num; // r11
  int size; // r10
  idStateData::transition_t *v15; // r9
  int v16; // r11
  idStateData **v17; // r30
  idStateData *v18; // r3
  int v19; // r11
  int v20; // r10
  idStateTransition::transDest_t *v21; // r9
  idStateTransition::transDest_t *v22; // r11
  idStateTransition::transDest_t *v23; // r11

  v10 = 0;
  if ( list->num <= 0 )
    goto LABEL_7;
  v11 = 0;
  while ( list->list[v11].transition->GetType(this: list->list[v11].transition) != transType )
  {
    ++v10;
    ++v11;
    if ( v10 >= list->num )
      goto LABEL_7;
  }
  v12 = &list->list[v10];
  if ( v12 == nullptr )
  {
LABEL_7:
    idList<idStateData::transition_t,5>::PreAllocateWithGranularity(this: list, newSize: list->num + 1);
    num = list->num;
    size = list->size;
    v15 = list->list;
    if ( num >= size )
    {
      v16 = (int)&v15[size - 1];
    }
    else
    {
      list->num = num + 1;
      v16 = (int)&v15[num];
    }
    if ( v16 != 0 )
    {
      *(_DWORD *)v16 = 0;
      *(_WORD *)(v16 + 16) = 0;
      *(_BYTE *)(v16 + 18) = 111;
      v17 = (idStateData **)v16;
      *(_BYTE *)(v16 + 19) = 0;
      *(_DWORD *)(v16 + 4) = 0;
      *(_DWORD *)(v16 + 12) = 0;
      *(_DWORD *)(v16 + 8) = 0;
    }
    else
    {
      v17 = nullptr;
    }
    v12 = (idStateData::transition_t *)v17;
    v18 = idClassFactory<idStateTransition,1024,111>::Find(
            this: (idClassFactory<idStateData,256,112> *)&gameLocal->stateTransitionFactory,
            hashKey: transType->classname);
    *v17 = v18;
    if ( v18 == nullptr )
      *v17 = idClassFactory<idStateTransition,1024,111>::Create(
               this: (idClassFactory<idStateData,256,112> *)&gameLocal->stateTransitionFactory,
               classType: transType,
               hashKey: transType->classname);
  }
  idList<swfGlyphEntry_t,72>::PreAllocateWithGranularity(
    this: (idList<swfGlyphEntry_t,72> *)&v12->destinations,
    newSize: v12->destinations.num + 1);
  v19 = v12->destinations.num;
  v20 = v12->destinations.size;
  v21 = v12->destinations.list;
  if ( v19 >= v20 )
  {
    v23 = &v21[v20];
    v23[-1].nextStateType = nextStateType;
    v23[-1].transCode = transCode;
  }
  else
  {
    v12->destinations.num = v19 + 1;
    v22 = &v21[v19];
    v22->nextStateType = nextStateType;
    v22->transCode = transCode;
  }
}


// ========================================================================
// __unwind$490944_0
// EA  : 0x82AF7FA0
// RVA : 0x00AF7FA0
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void _unwind_490944_0()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 176 + 88));
}


// ========================================================================
// ?AddStateTransition@idState@@QAAXPBVidFiniteStateMachine@@ABVidTypeInfo@@1@Z
// EA  : 0x82AF7FD0
// RVA : 0x00AF7FD0
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idState::AddStateTransition(
        idState *this,
        const idFiniteStateMachine *fsm,
        const idTypeInfo *transType,
        const idTypeInfo *nextStateType)
{
  idStateData *stateData; // r3

  stateData = this->stateData;
  if ( stateData->flags >> 15 == 0 )
    idStateData::AllocTransition(
      this: stateData,
      list: (idList<idStateData::transition_t,5> *)&stateData->transitions,
      fsm,
      transType,
      nextStateType,
      transCode: 0);
}


// ========================================================================
// ?AddStateTransition@idState@@QAAXPBVidFiniteStateMachine@@ABVidTypeInfo@@1H@Z
// EA  : 0x82AF8000
// RVA : 0x00AF8000
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idState::AddStateTransition(
        idState *this,
        const idFiniteStateMachine *fsm,
        const idTypeInfo *transType,
        const idTypeInfo *nextStateType,
        int transCode)
{
  idStateData *stateData; // r3

  stateData = this->stateData;
  if ( stateData->flags >> 15 == 0 )
    idStateData::AllocTransition(
      this: stateData,
      list: (idList<idStateData::transition_t,5> *)&stateData->transitions,
      fsm,
      transType,
      nextStateType,
      transCode);
}


// ========================================================================
// ?AddEventTransition@idState@@QAAXPBVidFiniteStateMachine@@ABVidTypeInfo@@1@Z
// EA  : 0x82AF8030
// RVA : 0x00AF8030
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idState::AddEventTransition(
        idState *this,
        const idFiniteStateMachine *fsm,
        const idTypeInfo *transType,
        const idTypeInfo *nextStateType)
{
  idStateData *stateData; // r3

  stateData = this->stateData;
  if ( stateData->flags >> 15 == 0 )
    idStateData::AllocTransition(
      this: stateData,
      list: (idList<idStateData::transition_t,5> *)&stateData->eventTransitions,
      fsm,
      transType,
      nextStateType,
      transCode: 0);
}


// ========================================================================
// ?AddEventTransition@idState@@QAAXPBVidFiniteStateMachine@@ABVidTypeInfo@@1H@Z
// EA  : 0x82AF8060
// RVA : 0x00AF8060
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idState::AddEventTransition(
        idState *this,
        const idFiniteStateMachine *fsm,
        const idTypeInfo *transType,
        const idTypeInfo *nextStateType,
        int transCode)
{
  idStateData *stateData; // r3

  stateData = this->stateData;
  if ( stateData->flags >> 15 == 0 )
    idStateData::AllocTransition(
      this: stateData,
      list: (idList<idStateData::transition_t,5> *)&stateData->eventTransitions,
      fsm,
      transType,
      nextStateType,
      transCode);
}


// ========================================================================
// ?AddFSMEventTransition@idState@@QAAXPBVidFiniteStateMachine@@ABVidTypeInfo@@H@Z
// EA  : 0x82AF8090
// RVA : 0x00AF8090
// PDB : w:\tech5\tungsten\game\ai\fsm\state.cpp
// ========================================================================

void __fastcall idState::AddFSMEventTransition(
        idState *this,
        const idFiniteStateMachine *fsm,
        const idTypeInfo *nextStateType,
        int transCode)
{
  idStateData *stateData; // r3

  stateData = this->stateData;
  if ( stateData->flags >> 15 == 0 )
    idStateData::AllocTransition(
      this: stateData,
      list: (idList<idStateData::transition_t,5> *)&stateData->fsmEventTransitions,
      fsm,
      transType: &Shared_FSMEventTransCode::Type,
      nextStateType,
      transCode);
}

