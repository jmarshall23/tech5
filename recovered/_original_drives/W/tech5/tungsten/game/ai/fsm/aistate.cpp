
// ========================================================================
// ?Evaluate@idAIStateTransition@@UBAHPAVidFiniteStateMachine@@PAVidState@@H@Z
// EA  : 0x82AB2360
// RVA : 0x00AB2360
// PDB : w:\tech5\tungsten\game\ai\fsm\aistate.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall idAIStateTransition::Evaluate(
        idAIStateTransition *this,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  idAIStateTransition_vtbl *v8; // r27
  idEntity *Owner; // r3

  v8 = this->__vftable;
  Owner = idFiniteStateMachine::GetOwner(this: parentFSM);
  return v8->Evaluate_2(this, a2: (idAI2 *)Owner, a3: parentFSM, a4: state, a5: curTime);
}


// ========================================================================
// ?NameForTransitionCode@idAIStateTransition@@SAPBDW4aiTransCode_t@1@@Z
// EA  : 0x82AB23B0
// RVA : 0x00AB23B0
// PDB : w:\tech5\tungsten\game\ai\fsm\aistate.cpp
// ========================================================================

char *__fastcall idAIStateTransition::NameForTransitionCode(const idAIStateTransition::aiTransCode_t tc)
{
  idGame *v2; // r3
  idTypeInfoTools *v3; // r3
  const enumTypeInfo_t *EnumInfo; // r3
  const enumValueInfo_t *values; // r9
  int v6; // r10
  const enumValueInfo_t *v7; // r11

  v2 = common->Game(this: common);
  v3 = (idTypeInfoTools *)v2->GetTypeInfoTools(this: v2);
  EnumInfo = idTypeInfoTools::FindEnumInfo(this: v3, typeName: "aiTransCode_t");
  if ( EnumInfo == nullptr )
    return &byte_8200D768;
  values = EnumInfo->values;
  v6 = 0;
  if ( values->name == nullptr )
    return &byte_8200D768;
  v7 = EnumInfo->values;
  while ( v7->value != tc )
  {
    v7 = &values[++v6];
    if ( v7->name == nullptr )
      return &byte_8200D768;
  }
  return (char *)v7->name;
}


// ========================================================================
// ?InternalCanUse@idAIState@@UBA_NPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AB2470
// RVA : 0x00AB2470
// PDB : w:\tech5\tungsten\game\ai\fsm\aistate.cpp
// ========================================================================

int __fastcall idAIState::InternalCanUse(idAIState *this, idFiniteStateMachine *fsm, int curTime)
{
  idAIState_vtbl *v6; // r31
  idEntity *Owner; // r3

  v6 = this->__vftable;
  Owner = idFiniteStateMachine::GetOwner(this: fsm);
  return ((int (__fastcall *)(idAIState *, idEntity *, idFiniteStateMachine *, const int))v6->AIState_CanUse)(
           a1: this,
           a2: Owner,
           a3: fsm,
           a4: curTime);
}


// ========================================================================
// ?InternalEnterState@idAIState@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AB24B8
// RVA : 0x00AB24B8
// PDB : w:\tech5\tungsten\game\ai\fsm\aistate.cpp
// ========================================================================

void __fastcall idAIState::InternalEnterState(idAIState *this, idAIFSM *fsm, int curTime)
{
  idAIState_vtbl *v6; // r31
  idEntity *Owner; // r3

  v6 = this->__vftable;
  Owner = idFiniteStateMachine::GetOwner(this: fsm);
  v6->AIState_EnterState(this, a2: (idAI2 *)Owner, a3: fsm, a4: curTime);
}


// ========================================================================
// ?InternalExitState@idAIState@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AB2500
// RVA : 0x00AB2500
// PDB : w:\tech5\tungsten\game\ai\fsm\aistate.cpp
// ========================================================================

void __fastcall idAIState::InternalExitState(idAIState *this, idAIFSM *fsm, int curTime)
{
  idAIState_vtbl *v6; // r31
  idEntity *Owner; // r3

  v6 = this->__vftable;
  Owner = idFiniteStateMachine::GetOwner(this: fsm);
  v6->AIState_ExitState(this, a2: (idAI2 *)Owner, a3: fsm, a4: curTime);
}


// ========================================================================
// ?InternalWork@idAIState@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AB2548
// RVA : 0x00AB2548
// PDB : w:\tech5\tungsten\game\ai\fsm\aistate.cpp
// ========================================================================

void __fastcall idAIState::InternalWork(idAIState *this, idAIFSM *fsm, int curTime)
{
  idAIState_vtbl *v6; // r31
  idEntity *Owner; // r3

  v6 = this->__vftable;
  Owner = idFiniteStateMachine::GetOwner(this: fsm);
  v6->AIState_Work(this, a2: (idAI2 *)Owner, a3: fsm, a4: curTime);
}


// ========================================================================
// ?InternalReenterState@idAIState@@UAAXPAVidFiniteStateMachine@@HH@Z
// EA  : 0x82AB2590
// RVA : 0x00AB2590
// PDB : w:\tech5\tungsten\game\ai\fsm\aistate.cpp
// ========================================================================

void __fastcall idAIState::InternalReenterState(idAIState *this, idAIFSM *fsm, int transCode, int curTime)
{
  idAIState_vtbl *v8; // r31
  idEntity *Owner; // r3

  v8 = this->__vftable;
  Owner = idFiniteStateMachine::GetOwner(this: fsm);
  v8->AIState_ReenterState(this, a2: (idAI2 *)Owner, a3: fsm, a4: transCode, a5: curTime);
}


// ========================================================================
// ?InternalIsStateWaiting@idAIState@@UBA_NPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AB25E0
// RVA : 0x00AB25E0
// PDB : w:\tech5\tungsten\game\ai\fsm\aistate.cpp
// ========================================================================

int __fastcall idAIState::InternalIsStateWaiting(idAIState *this, idFiniteStateMachine *fsm, int curTime)
{
  idAIState_vtbl *v6; // r31
  idEntity *Owner; // r3

  v6 = this->__vftable;
  Owner = idFiniteStateMachine::GetOwner(this: fsm);
  return ((int (__fastcall *)(idAIState *, idEntity *, idFiniteStateMachine *, const int))v6->AIState_IsWaiting)(
           a1: this,
           a2: Owner,
           a3: fsm,
           a4: curTime);
}


// ========================================================================
// ?InternalSave@idAIStateTransitionStatic@@UBAXAAVidFile_String@@PBDABV?$idList@UtransDest_t@idStateTransition@@$04@@@Z
// EA  : 0x82AB2628
// RVA : 0x00AB2628
// PDB : w:\tech5\tungsten\game\ai\fsm\aistate.cpp
// ========================================================================

void __fastcall idAIStateTransitionStatic::InternalSave(
        idAIStateTransitionStatic *this,
        idFile_String *file,
        const char *indent,
        const idList<idStateTransition::transDest_t,5> *dests,
        __int64 a5)
{
  int v8; // r23
  __int64 v9; // r10
  int v10; // r27
  idStateTransition::transDest_t *v11; // r11
  const char **p_classname; // r11
  __int64 v13; // r6
  va *v14; // r3
  va *v15; // r4
  unsigned int i; // r5
  const char *classname; // r31
  __int64 v18; // r8
  __int64 v19; // r10
  va *v20; // r3
  int v21; // [sp+8h] [-1098h]
  int v22; // [sp+Ch] [-1094h]
  int v23; // [sp+10h] [-1090h]
  int v24; // [sp+14h] [-108Ch]
  int v25; // [sp+18h] [-1088h]
  int v26; // [sp+1Ch] [-1084h]
  va v27; // [sp+50h] [-1050h] BYREF

  v8 = 0;
  if ( dests->num > 0 )
  {
    HIDWORD(v9) = "1 - formation cover, such as behind regime shield units";
    v10 = 0;
    do
    {
      v11 = &dests->list[v10];
      LODWORD(v9) = v11->transCode;
      if ( (_DWORD)v9 != 0 )
      {
        if ( v11->nextStateType != nullptr )
          classname = v11->nextStateType->classname;
        else
          classname = "NULL";
        HIDWORD(v18) = idAIStateTransition::NameForTransitionCode(tc: (const idAIStateTransition::aiTransCode_t)v11->transCode);
        v20 = va::va(
                this: &v27,
                fmt: "%s\tto \"%s\" (%s)\n",
                a3: __SPAIR64__((unsigned int)indent, (unsigned int)classname),
                a4: v18,
                a5: v19,
                a6: v21,
                a7: v22,
                a8: v23,
                a9: v24,
                a10: v25,
                a11: v26);
        v15 = v20;
        for ( i = 0; v20->buffer[i] != 0; ++i )
          ;
      }
      else
      {
        p_classname = &v11->nextStateType->classname;
        if ( p_classname != nullptr )
          LODWORD(v13) = *p_classname;
        else
          LODWORD(v13) = "NULL";
        HIDWORD(v13) = indent;
        v14 = va::va(
                this: &v27,
                fmt: "%s\tto \"%s\"\n",
                a3: v13,
                a4: a5,
                a5: v9,
                a6: v21,
                a7: v22,
                a8: v23,
                a9: v24,
                a10: v25,
                a11: v26);
        v15 = v14;
        for ( i = 0; v14->buffer[i] != 0; ++i )
          ;
      }
      file->Write(this: file, a2: v15, a3: i);
      ++v8;
      ++v10;
    }
    while ( v8 < dests->num );
  }
}


// ========================================================================
// ?StartQueuedActions@idAIState@@QAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB2760
// RVA : 0x00AB2760
// PDB : w:\tech5\tungsten\game\ai\fsm\aistate.cpp
// ========================================================================

void __fastcall idAIState::StartQueuedActions(idAIState *this, idAI2 *ai, idAIFSM *parentFSM, int curTime)
{
  idLegsFSM *p_legsFSM; // r29
  idFiniteStateMachine *FullPath; // r3

  p_legsFSM = &ai->aiVolatile.fsms.actionManager.legsFSM;
  if ( ai != (idAI2 *)-32672 )
  {
    idAIActionFSM::StartQueuedActions(this: &ai->aiVolatile.fsms.actionManager.legsFSM);
    if ( idFile_SaveGamePipelined::GetFullPath((XGRAPHICS::IRInst *)this) != 0
      && (idLegsFSM *)idFile_SaveGamePipelined::GetFullPath((XGRAPHICS::IRInst *)this) != p_legsFSM )
    {
      FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath((XGRAPHICS::IRInst *)this);
      idFiniteStateMachine::ExitChildStates(this: FullPath, parentFSM, curTime);
    }
    idState::SetChildFSM(this, parentFSM, childFSM_: p_legsFSM);
  }
}


// ========================================================================
// ?ClearQueuedActions@idAIState@@QAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AB27E0
// RVA : 0x00AB27E0
// PDB : w:\tech5\tungsten\game\ai\fsm\aistate.cpp
// ========================================================================

void __fastcall idAIState::ClearQueuedActions(idAIState *this, idAI2 *ai, idAIFSM *parentFSM, int curTime)
{
  idLegsFSM *p_legsFSM; // r29
  idFiniteStateMachine *FullPath; // r3

  p_legsFSM = &ai->aiVolatile.fsms.actionManager.legsFSM;
  if ( ai != (idAI2 *)-32672 )
  {
    idAIActionsQueue::Clear(this: &ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue);
    if ( idFile_SaveGamePipelined::GetFullPath((XGRAPHICS::IRInst *)this) != 0
      && (idLegsFSM *)idFile_SaveGamePipelined::GetFullPath((XGRAPHICS::IRInst *)this) != p_legsFSM )
    {
      FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath((XGRAPHICS::IRInst *)this);
      idFiniteStateMachine::ExitChildStates(this: FullPath, parentFSM, curTime);
    }
    idState::SetChildFSM(this, parentFSM, childFSM_: nullptr);
  }
}

