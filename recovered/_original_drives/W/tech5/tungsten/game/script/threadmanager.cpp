
// ========================================================================
// ?GetThread@idThreadManager@@QBAPAVidThread@@V?$idHandle@HW4invalidThreadHandle_t@@$0A@@@@Z
// EA  : 0x82EA5298
// RVA : 0x00EA5298
// PDB : w:\tech5\tungsten\game\script\threadmanager.cpp
// ========================================================================

idThread *__fastcall idThreadManager::GetThread(
        idThreadManager *this,
        const idHandle<int,enum invalidThreadHandle_t,0> *threadHandle)
{
  int num; // r8
  int v3; // r10
  idThread **list; // r9
  int i; // r11
  idThread *result; // r3

  num = this->threadList.num;
  v3 = 0;
  if ( num <= 0 )
    return nullptr;
  list = this->threadList.list;
  for ( i = 0; ; ++i )
  {
    result = list[i];
    if ( (const idHandle<int,enum invalidThreadHandle_t,0> *)result->threadHandle.value == threadHandle )
      break;
    if ( ++v3 >= num )
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?GetCurThreadHandle@idThreadManager@@QBA?AV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@XZ
// EA  : 0x82EA52D8
// RVA : 0x00EA52D8
// PDB : w:\tech5\tungsten\game\script\threadmanager.cpp
// ========================================================================

idThreadManager *__fastcall idThreadManager::GetCurThreadHandle(
        idThreadManager *this,
        idHandle<int,enum invalidThreadHandle_t,0> *result)
{
  if ( result->value != 0 )
    this->currentThread = *(idThread **)(result->value + 36);
  else
    this->currentThread = nullptr;
  return this;
}


// ========================================================================
// ?GetThreadHandle@idThreadManager@@QAA?AV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@XZ
// EA  : 0x82EA5300
// RVA : 0x00EA5300
// PDB : w:\tech5\tungsten\game\script\threadmanager.cpp
// ========================================================================

idThreadManager *__fastcall idThreadManager::GetThreadHandle(
        idThreadManager *this,
        idHandle<int,enum invalidThreadHandle_t,0> *result)
{
  int value; // r7
  int v3; // r11
  idThread *v4; // r8
  int v5; // r10
  int v6; // r11

  value = result[3].value;
  while ( 1 )
  {
    v3 = result[1].value + 1;
    result[1].value = v3;
    if ( v3 == 0 )
      result[1].value = 1;
    v4 = (idThread *)result[1].value;
    v5 = 0;
    if ( value <= 0 )
      break;
    v6 = 0;
    while ( *(idThread **)(*(_DWORD *)(v6 + result[2].value) + 36) != v4 )
    {
      ++v5;
      v6 += 4;
      if ( v5 >= value )
        goto LABEL_8;
    }
  }
LABEL_8:
  this->currentThread = v4;
  return this;
}


// ========================================================================
// ?ObjectMoveDone@idThreadManager@@QAAXV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@PAVidEntity@@@Z
// EA  : 0x82EA5360
// RVA : 0x00EA5360
// PDB : w:\tech5\tungsten\game\script\threadmanager.cpp
// ========================================================================

void __fastcall idThreadManager::ObjectMoveDone(
        idThreadManager *this,
        const idHandle<int,enum invalidThreadHandle_t,0> *threadHandle,
        idEntity *obj)
{
  int num; // r8
  int v4; // r10
  idThread **list; // r9
  int i; // r11
  idThread *v7; // r3

  if ( threadHandle != nullptr )
  {
    num = this->threadList.num;
    v4 = 0;
    if ( num > 0 )
    {
      list = this->threadList.list;
      for ( i = 0; ; ++i )
      {
        v7 = list[i];
        if ( (const idHandle<int,enum invalidThreadHandle_t,0> *)v7->threadHandle.value == threadHandle )
          break;
        if ( ++v4 >= num )
          return;
      }
      idThread::ObjectMoveDone(this: v7, obj);
    }
  }
}


// ========================================================================
// ?KillThread@idThreadManager@@QAAXPBD@Z
// EA  : 0x82EA53B0
// RVA : 0x00EA53B0
// PDB : w:\tech5\tungsten\game\script\threadmanager.cpp
// ========================================================================

void __fastcall idThreadManager::KillThread(idThreadManager *this, const char *name)
{
  char *v4; // r3
  int v5; // r27
  int v6; // r11
  int v7; // r30
  int num; // r28
  idThread *v9; // r31

  v4 = strchr(Str: name, Val: 42);
  if ( v4 != nullptr )
  {
    v5 = v4 - name;
  }
  else
  {
    v6 = 0;
    if ( *name != 0 )
    {
      do
        ++v6;
      while ( name[v6] != 0 );
    }
    v5 = v6;
  }
  if ( this->threadList.num > 0 )
  {
    v7 = 0;
    num = this->threadList.num;
    do
    {
      v9 = this->threadList.list[v7];
      if ( idStr::Cmpn(s1: v9->threadName.data, s2: name, n: v5) == 0 )
        idThread::End(this: v9);
      --num;
      ++v7;
    }
    while ( num != 0 );
  }
}


// ========================================================================
// ?KillThread@idThreadManager@@QAAXV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@@Z
// EA  : 0x82EA5458
// RVA : 0x00EA5458
// PDB : w:\tech5\tungsten\game\script\threadmanager.cpp
// ========================================================================

void __fastcall idThreadManager::KillThread(
        idThreadManager *this,
        const idHandle<int,enum invalidThreadHandle_t,0> *threadHandle)
{
  int num; // r8
  int v3; // r10
  idThread **list; // r9
  int i; // r11
  idThread *v6; // r3

  num = this->threadList.num;
  v3 = 0;
  if ( num > 0 )
  {
    list = this->threadList.list;
    for ( i = 0; ; ++i )
    {
      v6 = list[i];
      if ( (const idHandle<int,enum invalidThreadHandle_t,0> *)v6->threadHandle.value == threadHandle )
        break;
      if ( ++v3 >= num )
        return;
    }
    idThread::End(this: v6);
  }
}


// ========================================================================
// ?ListThreads_f@idThreadManager@@SAXABVidCmdArgs@@@Z
// EA  : 0x82EA5498
// RVA : 0x00EA5498
// PDB : w:\tech5\tungsten\game\script\threadmanager.cpp
// ========================================================================

void __fastcall idThreadManager::ListThreads_f(const idCmdArgs *args)
{
  idList<idThread *,58> *p_threadList; // r27
  int num; // r26
  int v3; // r29
  int v4; // r30
  idThread *v5; // r11
  idInterpreter *p_interpreter; // r31
  const char *data; // r25
  int value; // r24
  int v9; // r23
  char *v10; // r3

  p_threadList = &gameLocal->program.threadManager.threadList;
  num = gameLocal->program.threadManager.threadList.num;
  if ( num > 0 )
  {
    v3 = 0;
    v4 = gameLocal->program.threadManager.threadList.num;
    do
    {
      v5 = p_threadList->list[v3];
      p_interpreter = &v5->interpreter;
      data = v5->threadName.data;
      value = v5->threadHandle.value;
      v9 = idInterpreter::CurrentLine(this: &v5->interpreter);
      v10 = idInterpreter::CurrentFile(this: p_interpreter);
      idLib::Printf(fmt: "%3i: %-20s : %s(%d)\n", value, data, v10, v9);
      --v4;
      ++v3;
    }
    while ( v4 != 0 );
  }
  idLib::Printf(fmt: "%d active threads\n\n", num);
}


// ========================================================================
// ?Restart@idThreadManager@@QAAXXZ
// EA  : 0x82EA5538
// RVA : 0x00EA5538
// PDB : w:\tech5\tungsten\game\script\threadmanager.cpp
// ========================================================================

void __fastcall idThreadManager::Restart(idThreadManager *this)
{
  int v2; // r29
  int v3; // r30
  idThread *v4; // r3
  idThread **list; // r4

  v2 = this->threadList.num - 1;
  this->threadIndex = 0;
  this->currentThread = nullptr;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      v4 = this->threadList.list[v3];
      if ( v4 != nullptr )
        ((void (__fastcall *)(idThread *, int))v4->dtr_idClass)(a1: v4, a2: 1);
      --v2;
      --v3;
    }
    while ( v2 >= 0 );
  }
  if ( this->threadList.listStatic == 0 || this->threadList.listStatic == 2 )
  {
    list = this->threadList.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->threadList.list = nullptr;
    this->threadList.size = 0;
  }
  this->threadList.num = 0;
  memset(Dst: &this->trace, Val: 0, Size: sizeof(this->trace));
  this->trace.c.entityNum = 0x1FFF;
}


// ========================================================================
// ?RemoveThread@idThreadManager@@QAA_NPAVidThread@@@Z
// EA  : 0x82EA55F0
// RVA : 0x00EA55F0
// PDB : w:\tech5\tungsten\game\script\threadmanager.cpp
// ========================================================================

int __fastcall idThreadManager::RemoveThread(idThreadManager *this, idThread *thread)
{
  int num; // r10
  idList<idThread *,58> *p_threadList; // r28
  int v6; // r4
  int v7; // r11
  char v8; // r3
  int v10; // r30
  int v11; // r31
  idThread *v12; // r3

  num = this->threadList.num;
  p_threadList = &this->threadList;
  v6 = 0;
  if ( num <= 0 )
    goto LABEL_5;
  v7 = 0;
  while ( p_threadList->list[v7] != thread )
  {
    ++v6;
    ++v7;
    if ( v6 >= num )
      goto LABEL_5;
  }
  if ( v6 < 0 )
LABEL_5:
    v8 = 0;
  else
    v8 = idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(
           this: (idList<idEntityPtr<idEntity>,58> *)&this->threadList,
           index: v6);
  if ( v8 == 0 )
    return 0;
  v10 = 0;
  if ( this->threadList.num > 0 )
  {
    v11 = 0;
    do
    {
      v12 = p_threadList->list[v11];
      if ( v12->waitingForThread == thread )
        idThread::ThreadCallback(this: v12, thread);
      ++v10;
      ++v11;
    }
    while ( v10 < this->threadList.num );
  }
  if ( this->currentThread == thread )
    this->currentThread = nullptr;
  return 1;
}


// ========================================================================
// ??0idThreadManager@@QAA@XZ
// EA  : 0x82EA56D0
// RVA : 0x00EA56D0
// PDB : w:\tech5\tungsten\game\script\threadmanager.cpp
// ========================================================================

idThreadManager *__fastcall idThreadManager::idThreadManager(idThreadManager *this)
{
  this->threadList.list = nullptr;
  this->threadList.granularity = 0;
  this->threadList.memTag = 58;
  this->threadList.listStatic = 0;
  this->threadList.size = 0;
  this->threadList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->threadList);
  this->currentThread = nullptr;
  this->threadIndex = 0;
  memset(Dst: &this->trace, Val: 0, Size: sizeof(this->trace));
  return this;
}


// ========================================================================
// ??1idThreadManager@@QAA@XZ
// EA  : 0x82EA5750
// RVA : 0x00EA5750
// PDB : w:\tech5\tungsten\game\script\threadmanager.cpp
// ========================================================================

void __fastcall idThreadManager::~idThreadManager(idThreadManager *this)
{
  int v2; // r28
  int v3; // r30
  idThread *v4; // r3
  idThread **list; // r4

  v2 = this->threadList.num - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      v4 = this->threadList.list[v3];
      if ( v4->interpreter.terminateOnExit && v4 != nullptr )
        ((void (__fastcall *)(idThread *, int))v4->dtr_idClass)(a1: v4, a2: 1);
      --v2;
      --v3;
    }
    while ( v2 >= 0 );
  }
  if ( this->threadList.listStatic == 0 || this->threadList.listStatic == 2 )
  {
    list = this->threadList.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->threadList.list = nullptr;
    this->threadList.size = 0;
  }
  this->threadList.num = 0;
}


// ========================================================================
// __unwind$488236
// EA  : 0x82EA5808
// RVA : 0x00EA5808
// PDB : w:\tech5\tungsten\game\script\threadmanager.cpp
// ========================================================================

void _unwind_488236()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// ?AddThread@idThreadManager@@QAA?AV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@PAVidThread@@@Z
// EA  : 0x82EA5838
// RVA : 0x00EA5838
// PDB : w:\tech5\tungsten\game\script\threadmanager.cpp
// ========================================================================

idThreadManager *__fastcall idThreadManager::AddThread(
        idThreadManager *this,
        idHandle<int,enum invalidThreadHandle_t,0> *result,
        idThread *thread,
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
        int a14,
        int a15,
        idThread *a16)
{
  a16 = thread;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&result[2],
    obj: (encounterGroupRole_t *)&a16);
  return idThreadManager::GetThreadHandle(this, result);
}

