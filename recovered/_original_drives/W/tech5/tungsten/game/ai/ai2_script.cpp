
// ========================================================================
// ?ExecuteThread@idAI2@@UAAXPAVidThread@@@Z
// EA  : 0x82A39200
// RVA : 0x00A39200
// PDB : w:\tech5\tungsten\game\ai\ai2_script.cpp
// ========================================================================

void __fastcall idAI2::ExecuteThread(idAI2 *this, idThread *thread)
{
  ((void (__fastcall *)(idAI2 *))this->ResetFSMWaitThreadIfPossible)(a1: this);
  idEntity::ExecuteThread(this, thread);
}


// ========================================================================
// ?AllThreadsAreFinished@idAI2@@QBA_NXZ
// EA  : 0x82A39250
// RVA : 0x00A39250
// PDB : w:\tech5\tungsten\game\ai\ai2_script.cpp
// ========================================================================

int __fastcall idAI2::AllThreadsAreFinished(idAI2 *this)
{
  int *p_num; // r26
  int v3; // r28
  int v4; // r31
  idStaticList<idHandle<int,enum invalidThreadHandle_t,0>,4> *p_threads; // r29
  idThread *Thread; // r3
  int v7; // r29
  int i; // r31

  p_num = &this->aiVolatile.script.threads.num;
  v3 = 0;
  if ( this->aiVolatile.script.threads.num <= 0 )
  {
LABEL_6:
    v7 = 0;
    if ( this->aiVolatile.script.fibers.num <= 0 )
      return 1;
    for ( i = 0;
          !idSuperScriptSystem::IsThreadHandleValid(
             this: &gameLocal->superScript,
             threadHandle: (idHandle<int,enum invalidFiberId_t,0> *)this->aiVolatile.script.fibers.list[i].value);
          ++i )
    {
      if ( ++v7 >= this->aiVolatile.script.fibers.num )
        return 1;
    }
  }
  else
  {
    v4 = 0;
    p_threads = &this->aiVolatile.script.threads;
    while ( 1 )
    {
      Thread = idThreadManager::GetThread(
                 this: &gameLocal->program.threadManager,
                 threadHandle: (const idHandle<int,enum invalidThreadHandle_t,0> *)p_threads->list[v4].value);
      if ( Thread != nullptr && !Thread->interpreter.threadDying )
        break;
      ++v3;
      ++v4;
      if ( v3 >= *p_num )
        goto LABEL_6;
    }
  }
  return 0;
}


// ========================================================================
// ?IsExecutingScript@idAI2@@QBA_NXZ
// EA  : 0x82A39348
// RVA : 0x00A39348
// PDB : w:\tech5\tungsten\game\ai\ai2_script.cpp
// ========================================================================

BOOL __fastcall idAI2::IsExecutingScript(idAI2 *this)
{
  return (this->aiVolatile.script.threads.num != 0 || this->aiVolatile.script.fibers.num != 0)
      && (_cntlzw((unsigned __int8)idAI2::AllThreadsAreFinished(this)) & 0x20) != 0;
}


// ========================================================================
// ?RemoveFiber@idAI2@@UAAXV?$idHandle@HW4invalidFiberId_t@@$0A@@@@Z
// EA  : 0x82A393B0
// RVA : 0x00A393B0
// PDB : w:\tech5\tungsten\game\ai\ai2_script.cpp
// ========================================================================

void __fastcall idAI2::RemoveFiber(idAI2 *this, const idHandle<int,enum invalidFiberId_t,0> *fiberHandle)
{
  int v2; // r11
  int num; // r7
  int i; // r10
  int v5; // r10
  int v6; // r10

  v2 = 0;
  num = this->aiVolatile.script.fibers.num;
  if ( num > 0 )
  {
    for ( i = 0;
          (const idHandle<int,enum invalidFiberId_t,0> *)this->aiVolatile.script.fibers.list[i].value != fiberHandle;
          ++i )
    {
      if ( ++v2 >= num )
        return;
    }
    if ( v2 >= 0 )
    {
      v5 = this->aiVolatile.script.fibers.num;
      if ( v2 < v5 )
      {
        v6 = v5 - 1;
        this->aiVolatile.script.fibers.num = v6;
        if ( v2 != v6 )
          this->aiVolatile.script.fibers.list[v2].value = this->aiVolatile.script.fibers.list[v6].value;
      }
    }
  }
}


// ========================================================================
// ?RemoveThread@idAI2@@UAAXV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@@Z
// EA  : 0x82A39438
// RVA : 0x00A39438
// PDB : w:\tech5\tungsten\game\ai\ai2_script.cpp
// ========================================================================

void __fastcall idAI2::RemoveThread(idAI2 *this, const idHandle<int,enum invalidThreadHandle_t,0> *threadHandle)
{
  int v2; // r11
  int num; // r7
  int i; // r10
  int v5; // r10
  int v6; // r10

  v2 = 0;
  num = this->aiVolatile.script.threads.num;
  if ( num > 0 )
  {
    for ( i = 0;
          (const idHandle<int,enum invalidThreadHandle_t,0> *)this->aiVolatile.script.threads.list[i].value != threadHandle;
          ++i )
    {
      if ( ++v2 >= num )
        return;
    }
    if ( v2 >= 0 )
    {
      v5 = this->aiVolatile.script.threads.num;
      if ( v2 < v5 )
      {
        v6 = v5 - 1;
        this->aiVolatile.script.threads.num = v6;
        if ( v2 != v6 )
          this->aiVolatile.script.threads.list[v2].value = this->aiVolatile.script.threads.list[v6].value;
      }
    }
  }
}


// ========================================================================
// ?GetThread@idAI2@@UBA?AV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@H@Z
// EA  : 0x82A394C0
// RVA : 0x00A394C0
// PDB : w:\tech5\tungsten\game\ai\ai2_script.cpp
// ========================================================================

idAI2 *__fastcall idAI2::GetThread(idAI2 *this, idHandle<int,enum invalidThreadHandle_t,0> *result, const int index)
{
  this->__vftable = *(idAI2_vtbl **)(result[14064].value + 4 * index);
  return this;
}


// ========================================================================
// ?NumThreads@idAI2@@UBAHXZ
// EA  : 0x82A394E0
// RVA : 0x00A394E0
// PDB : w:\tech5\tungsten\game\ai\ai2_script.cpp
// ========================================================================

int __fastcall idAI2::NumThreads(idAI2 *this)
{
  return this->aiVolatile.script.threads.num;
}


// ========================================================================
// ?ResetFSMWaitThreadIfPossible@idAI2@@UAAXPAVidThread@@@Z
// EA  : 0x82A394F0
// RVA : 0x00A394F0
// PDB : w:\tech5\tungsten\game\ai\ai2_script.cpp
// ========================================================================

void __fastcall idAI2::ResetFSMWaitThreadIfPossible(idAI2 *this, idThread *thread)
{
  if ( this != (idAI2 *)-32672
    && this->aiVolatile.fsms.actionManager.legsFSM.waitThreadHandle.value == thread->threadHandle.value )
  {
    this->aiVolatile.fsms.actionManager.legsFSM.waitThreadHandle.value = 0;
  }
}


// ========================================================================
// ?ForceFSMIntoExecutingCodeAction@idAI2@@QAA_NABVidEventDef@@@Z
// EA  : 0x82A395E0
// RVA : 0x00A395E0
// PDB : w:\tech5\tungsten\game\ai\ai2_script.cpp
// ========================================================================

int __fastcall idAI2::ForceFSMIntoExecutingCodeAction(idAI2 *this, const idEventDef *action)
{
  idAI2::idAIVolatile::idAIFSMInfo *p_fsms; // r30
  idFiniteStateMachine *v4; // r3
  idAlertCycle_ExecuteCodeMoveAction *curState; // r3
  idFSMManager::idFSMStack v7[2]; // [sp+50h] [-50h] BYREF

  p_fsms = &this->aiVolatile.fsms;
  v4 = this->aiVolatile.fsms.fsmManager.FindFSM_3(this: &this->aiVolatile.fsms, a2: &idAlertCycleFSM::Type);
  if ( v4 == nullptr )
    return 0;
  curState = (idAlertCycle_ExecuteCodeMoveAction *)v4->curState;
  if ( action->eventnum != ACTION_MoveToPointEnter.eventnum
    || idAlertCycle_ExecuteCodeMoveAction::CastTo(c: curState) != nullptr )
  {
    return 0;
  }
  vehicleAiSetup_t::encounter_t::encounter_t(this: (idASEModel *)v7);
  idFSMManager::idFSMStack::Add(
    this: v7,
    fsmType: &idAlertCycleFSM::Type,
    stateType: &idAlertCycle_ExecuteCodeMoveAction::Type);
  idFSMManager::SetFSMStack(this: &p_fsms->fsmManager, stack: v7);
  idPLog::~idPLog(this: v7);
  return 1;
}


// ========================================================================
// __unwind$488037
// EA  : 0x82A3968C
// RVA : 0x00A3968C
// PDB : w:\tech5\tungsten\game\ai\ai2_script.cpp
// ========================================================================

void _unwind_488037()
{
  int v0; // r12

  idPLog::~idPLog(this: (idFSMManager::idFSMStack *)(v0 - 160 + 80));
}


// ========================================================================
// ?AddThread@idAI2@@UAAHV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@@Z
// EA  : 0x82A396B8
// RVA : 0x00A396B8
// PDB : w:\tech5\tungsten\game\ai\ai2_script.cpp
// ========================================================================

int __fastcall idAI2::AddThread(
        idAI2 *this,
        const idHandle<int,enum invalidThreadHandle_t,0> *threadHandle,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idHandle<int,enum invalidFiberId_t,0> a14)
{
  int *p_num; // r22
  int v17; // r30
  int v18; // r28
  idStaticList<idHandle<int,enum invalidThreadHandle_t,0>,4> *p_threads; // r31
  const idHandle<int,enum invalidThreadHandle_t,0> *value; // r29
  int num; // r11
  int v22; // r11

  a14.value = (int)threadHandle;
  p_num = &this->aiVolatile.script.threads.num;
  v17 = this->aiVolatile.script.threads.num - 1;
  if ( v17 < 0 )
  {
LABEL_11:
    idList<idHandle<int,enum invalidFiberId_t,0>,5>::Append(
      this: (idList<idHandle<int,enum invalidFiberId_t,0>,5> *)&this->aiVolatile.script.threads,
      obj: &a14);
    return *p_num - 1;
  }
  v18 = v17;
  p_threads = &this->aiVolatile.script.threads;
  while ( 1 )
  {
    value = (const idHandle<int,enum invalidThreadHandle_t,0> *)p_threads->list[v18].value;
    if ( idThreadManager::GetThread(this: &gameLocal->program.threadManager, threadHandle: value) != nullptr )
      break;
    num = p_threads->num;
    if ( v17 < num )
    {
      v22 = num - 1;
      p_threads->num = v22;
      if ( v17 != v22 )
        p_threads->list[v18].value = p_threads->list[v22].value;
    }
    if ( threadHandle == value )
      return -1;
LABEL_10:
    --v17;
    --v18;
    if ( v17 < 0 )
      goto LABEL_11;
  }
  if ( value != threadHandle )
    goto LABEL_10;
  return v17;
}


// ========================================================================
// ?AddFiber@idAI2@@UAAHV?$idHandle@HW4invalidFiberId_t@@$0A@@@@Z
// EA  : 0x82A397A8
// RVA : 0x00A397A8
// PDB : w:\tech5\tungsten\game\ai\ai2_script.cpp
// ========================================================================

int __fastcall idAI2::AddFiber(
        idAI2 *this,
        const idHandle<int,enum invalidFiberId_t,0> *fiberHandle,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idHandle<int,enum invalidFiberId_t,0> a14)
{
  int *p_num; // r22
  int v17; // r30
  int v18; // r28
  idStaticList<idHandle<int,enum invalidFiberId_t,0>,4> *p_fibers; // r31
  const idHandle<int,enum invalidFiberId_t,0> *value; // r29
  int num; // r11
  int v22; // r11

  a14.value = (int)fiberHandle;
  p_num = &this->aiVolatile.script.fibers.num;
  v17 = this->aiVolatile.script.fibers.num - 1;
  if ( v17 < 0 )
  {
LABEL_11:
    idList<idHandle<int,enum invalidFiberId_t,0>,5>::Append(this: &this->aiVolatile.script.fibers, obj: &a14);
    return *p_num;
  }
  v18 = v17;
  p_fibers = &this->aiVolatile.script.fibers;
  while ( 1 )
  {
    value = (const idHandle<int,enum invalidFiberId_t,0> *)p_fibers->list[v18].value;
    if ( idSuperScriptSystem::IsThreadHandleValid(this: &gameLocal->superScript, threadHandle: value) )
      break;
    num = p_fibers->num;
    if ( v17 < num )
    {
      v22 = num - 1;
      p_fibers->num = v22;
      if ( v17 != v22 )
        p_fibers->list[v18].value = p_fibers->list[v22].value;
    }
    if ( value == fiberHandle )
      return -1;
LABEL_10:
    --v17;
    --v18;
    if ( v17 < 0 )
      goto LABEL_11;
  }
  if ( value != fiberHandle )
    goto LABEL_10;
  return v17;
}

