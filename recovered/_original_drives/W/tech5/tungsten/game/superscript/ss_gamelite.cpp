
// ========================================================================
// ?EntityIsValid@idSuperScriptSystem@@UAA_NH@Z
// EA  : 0x82EAB6C8
// RVA : 0x00EAB6C8
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

BOOL __fastcall idSuperScriptSystem::EntityIsValid(idSuperScriptSystem *this, int spawnId)
{
  return gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: spawnId) != nullptr;
}


// ========================================================================
// ?GetAllocThread@idSuperScriptSystem@@UAAHXZ
// EA  : 0x82EAB708
// RVA : 0x00EAB708
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::GetAllocThread(idSuperScriptSystem *this)
{
  if ( this->allocFiberId == -1 )
    return this->GetCurrentThreadId(this);
  else
    return this->allocFiberId;
}


// ========================================================================
// ?SetAllocThread@idSuperScriptSystem@@UAAHH@Z
// EA  : 0x82EAB730
// RVA : 0x00EAB730
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::SetAllocThread(idSuperScriptSystem *this, int threadId)
{
  int result; // r3

  result = this->allocFiberId;
  this->allocFiberId = threadId;
  return result;
}


// ========================================================================
// ?Printf@idSuperScriptSystem@@UAAXPBDZZ
// EA  : 0x82EAB740
// RVA : 0x00EAB740
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idSuperScriptSystem::Printf(
        idSuperScriptSystem *this,
        const char *fmt,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        ...)
{
  __int64 v11; // [sp+80h] [+20h] BYREF
  va_list va; // [sp+80h] [+20h]
  __int64 v13; // [sp+88h] [+28h]
  __int64 v14; // [sp+90h] [+30h]
  __int64 v15; // [sp+98h] [+38h]
  __int64 v16; // [sp+A0h] [+40h]
  __int64 v17; // [sp+A8h] [+48h]
  va_list va1; // [sp+B0h] [+50h] BYREF

  va_start(va1, a11);
  va_start(va, a11);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v11 = *(__int64 *)((char *)&a3 + 4);
  v13 = a3;
  v14 = *(__int64 *)((char *)&a4 + 4);
  v15 = a4;
  v16 = *(__int64 *)((char *)&a5 + 4);
  v17 = a5;
  idLib::VPrintf(fmt, args: va);
}


// ========================================================================
// ?EventGetReturnInt@idSuperScriptSystem@@UAAHXZ
// EA  : 0x82EAB790
// RVA : 0x00EAB790
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::EventGetReturnInt(idSuperScriptSystem *this)
{
  return this->returnInt;
}


// ========================================================================
// ?EventGetReturnFloat@idSuperScriptSystem@@UAAMXZ
// EA  : 0x82EAB798
// RVA : 0x00EAB798
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

float __fastcall idSuperScriptSystem::EventGetReturnFloat(idSuperScriptSystem *this)
{
  double returnFloat; // fp1

  returnFloat = this->returnFloat;
  return *((float *)&returnFloat + 1);
}


// ========================================================================
// ?EventGetReturnVector@idSuperScriptSystem@@UAAXAAUssVec3_t@@@Z
// EA  : 0x82EAB7A0
// RVA : 0x00EAB7A0
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::EventGetReturnVector(idSuperScriptSystem *this, ssVec3_t *v)
{
  *v = (ssVec3_t)this->returnVector;
}


// ========================================================================
// ?EventGetReturnColor@idSuperScriptSystem@@UAAXAAUssColor_t@@@Z
// EA  : 0x82EAB7C0
// RVA : 0x00EAB7C0
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::EventGetReturnColor(idSuperScriptSystem *this, ssColor_t *c)
{
  *c = (ssColor_t)this->returnColor;
}


// ========================================================================
// ?GetPlayerScreenName@idSuperScriptSystem@@UAAPBDH@Z
// EA  : 0x82EAB7E8
// RVA : 0x00EAB7E8
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

const char *__fastcall idSuperScriptSystem::GetPlayerScreenName(idSuperScriptSystem *this, int spawnID)
{
  return "FIXME";
}


// ========================================================================
// ?FindEntity@idSuperScriptSystem@@UAAHPBD@Z
// EA  : 0x82EAB808
// RVA : 0x00EAB808
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

idGameLocal_vtbl *__fastcall idSuperScriptSystem::FindEntity(idSuperScriptSystem *this, const char *name)
{
  const idEntity *v2; // r3
  char v4; // [sp+50h] [-20h] BYREF

  v2 = gameLocal->FindEntity(this: gameLocal, a2: name);
  return idGameLocal::GetSpawnId(this: (idGameLocal *)&v4, result: (idSpawnId *)gameLocal, ent: v2)->__vftable;
}


// ========================================================================
// ?EntityName@idSuperScriptSystem@@UAAPBDH@Z
// EA  : 0x82EAB858
// RVA : 0x00EAB858
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

char *__fastcall idSuperScriptSystem::EntityName(idSuperScriptSystem *this, int spawnId)
{
  idEntity *v2; // r3

  v2 = gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: spawnId);
  if ( v2 != nullptr )
    return v2->name.data;
  else
    return "<null>";
}


// ========================================================================
// ?Allocate@idSuperScriptSystem@@UAAPAXHH@Z
// EA  : 0x82EAB8B0
// RVA : 0x00EAB8B0
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void *__fastcall idSuperScriptSystem::Allocate(idSuperScriptSystem *this, unsigned int len, int threadId)
{
  idSSFiber *currentFiber; // r3
  int num; // r8
  int v5; // r10
  idSSFiber **list; // r9
  int i; // r11
  idSSFiber *v8; // r7

  if ( threadId >= 0 )
  {
    if ( threadId <= 0 )
      return idMem::AllocWithLocation(
               this: &mem,
               location: "w:\\tech5\\tungsten\\game\\superscript\\ss_gamelite.cpp(172) : TAG_SUPERSCRIPT",
               size: len,
               tag: TAG_SUPERSCRIPT,
               zeroBuffer: false,
               align: ALIGN_16,
               heap: HEAP_DEFAULTHEAP);
    num = this->fibers.num;
    v5 = 0;
    if ( num <= 0 )
      return idMem::AllocWithLocation(
               this: &mem,
               location: "w:\\tech5\\tungsten\\game\\superscript\\ss_gamelite.cpp(172) : TAG_SUPERSCRIPT",
               size: len,
               tag: TAG_SUPERSCRIPT,
               zeroBuffer: false,
               align: ALIGN_16,
               heap: HEAP_DEFAULTHEAP);
    list = this->fibers.list;
    for ( i = 0; ; ++i )
    {
      v8 = list[i];
      if ( v8 != nullptr && v8->id == threadId )
        break;
      if ( ++v5 >= num )
        return idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\tungsten\\game\\superscript\\ss_gamelite.cpp(172) : TAG_SUPERSCRIPT",
                 size: len,
                 tag: TAG_SUPERSCRIPT,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
    }
    currentFiber = list[v5];
  }
  else
  {
    currentFiber = this->currentFiber;
  }
  if ( currentFiber == nullptr )
    return idMem::AllocWithLocation(
             this: &mem,
             location: "w:\\tech5\\tungsten\\game\\superscript\\ss_gamelite.cpp(172) : TAG_SUPERSCRIPT",
             size: len,
             tag: TAG_SUPERSCRIPT,
             zeroBuffer: false,
             align: ALIGN_16,
             heap: HEAP_DEFAULTHEAP);
  return idSSFiber::Allocate(this: currentFiber, len);
}


// ========================================================================
// ?Free@idSuperScriptSystem@@UAAXPAXH@Z
// EA  : 0x82EAB988
// RVA : 0x00EAB988
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::Free(
        idSuperScriptSystem *this,
        idMapChangeListener *data,
        int threadId,
        int a4,
        int a5,
        int num,
        idSSFiber **list,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idMapChangeListener *a14)
{
  idSSFiber *currentFiber; // r3
  int v15; // r11

  if ( threadId >= 0 )
  {
    if ( threadId <= 0 )
      goto LABEL_9;
    num = this->fibers.num;
    a8 = 0;
    if ( num <= 0 )
      goto LABEL_9;
    list = this->fibers.list;
    v15 = 0;
    while ( 1 )
    {
      a5 = (int)list[v15];
      if ( a5 != 0 )
      {
        a4 = *(_DWORD *)(a5 + 24);
        if ( a4 == threadId )
          break;
      }
      ++a8;
      ++v15;
      if ( a8 >= num )
        goto LABEL_9;
    }
    currentFiber = list[a8];
  }
  else
  {
    currentFiber = this->currentFiber;
  }
  if ( currentFiber == nullptr )
  {
LABEL_9:
    idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
    return;
  }
  idSSFiber::Free(
    this: currentFiber,
    data,
    a3: threadId,
    a4,
    a5,
    a6: num,
    a7: (int)list,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14);
}


// ========================================================================
// ?GetCurrentThreadId@idSuperScriptSystem@@UAAHXZ
// EA  : 0x82EABA08
// RVA : 0x00EABA08
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::GetCurrentThreadId(idSuperScriptSystem *this)
{
  idSSFiber *currentFiber; // r11

  currentFiber = this->currentFiber;
  if ( currentFiber != nullptr )
    return currentFiber->id;
  else
    return 0;
}


// ========================================================================
// ?GetCurrentFiberHandle@idSuperScriptSystem@@QAA?AV?$idHandle@HW4invalidFiberId_t@@$0A@@@XZ
// EA  : 0x82EABA28
// RVA : 0x00EABA28
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

idSuperScriptSystem *__fastcall idSuperScriptSystem::GetCurrentFiberHandle(
        idSuperScriptSystem *this,
        idHandle<int,enum invalidFiberId_t,0> *result)
{
  int value; // r11

  value = result[11].value;
  if ( value != 0 )
    this->__vftable = *(idSuperScriptSystem_vtbl **)(value + 24);
  else
    this->__vftable = nullptr;
  return this;
}


// ========================================================================
// ?RunThread@idSuperScriptSystem@@UAA_NH@Z
// EA  : 0x82EABA50
// RVA : 0x00EABA50
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::RunThread(idSuperScriptSystem *this, int threadId)
{
  int num; // r8
  int v4; // r9
  idSSFiber **list; // r10
  int i; // r11
  idSSFiber *v7; // r7
  int v9; // r31
  idSSFiber *v10; // r3

  num = this->fibers.num;
  v4 = 0;
  if ( num <= 0 )
    return 0;
  list = this->fibers.list;
  for ( i = 0; ; ++i )
  {
    v7 = list[i];
    if ( v7 != nullptr && v7->id == threadId )
      break;
    if ( ++v4 >= num )
      return 0;
  }
  v9 = v4;
  if ( !idSuperScriptSystem::ExecuteFiber(this, fiber: list[v4]) )
  {
    v10 = this->fibers.list[v9];
    if ( v10 != nullptr )
      ((void (__fastcall *)(idSSFiber *, int))v10->dtr_idSysFiber)(a1: v10, a2: 1);
    this->fibers.list[v9] = nullptr;
    return 0;
  }
  return 1;
}


// ========================================================================
// ?FindThread@idSuperScriptSystem@@UAAHPBDPAVidSSObject@@@Z
// EA  : 0x82EABB20
// RVA : 0x00EABB20
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::FindThread(idSuperScriptSystem *this, const char *name, idSSObject *sso)
{
  int v6; // r29
  int i; // r31
  idSSFiber **list; // r11
  idSSFiber *v9; // r10
  idSSFiber *v10; // r11

  v6 = 0;
  if ( this->fibers.num <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    list = this->fibers.list;
    v9 = list[i];
    if ( v9 != nullptr )
    {
      v10 = list[i];
      if ( v9->object == sso && idStr::Icmp(s1: v10->name, s2: name) == 0 )
        break;
    }
    if ( ++v6 >= this->fibers.num )
      return 0;
  }
  return this->fibers.list[v6]->id;
}


// ========================================================================
// ?TerminateThread@idSuperScriptSystem@@UAA_NPBDPAVidSSObject@@@Z
// EA  : 0x82EABBB8
// RVA : 0x00EABBB8
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::TerminateThread(idSuperScriptSystem *this, const char *name, idSSObject *sso)
{
  int v6; // r29
  int i; // r31
  idSSFiber **list; // r11
  idSSFiber *v9; // r10
  idSSFiber *v10; // r11
  idSSFiber **v12; // r11
  idSSFiber *currentFiber; // r3
  idSSFiber *v14; // r3

  v6 = 0;
  if ( this->fibers.num <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    list = this->fibers.list;
    v9 = list[i];
    if ( v9 != nullptr )
    {
      v10 = list[i];
      if ( v9->object == sso && idStr::Icmp(s1: v10->name, s2: name) == 0 )
        break;
    }
    if ( ++v6 >= this->fibers.num )
      return 0;
  }
  v12 = this->fibers.list;
  currentFiber = this->currentFiber;
  if ( v12[v6] == currentFiber )
  {
    currentFiber->alive = false;
    idSysFiber::YieldFiber(this: currentFiber);
    return 1;
  }
  else
  {
    v14 = v12[v6];
    if ( v14 != nullptr )
      ((void (__fastcall *)(idSSFiber *, int))v14->dtr_idSysFiber)(a1: v14, a2: 1);
    this->fibers.list[v6] = nullptr;
    return 1;
  }
}


// ========================================================================
// ?TerminateThread@idSuperScriptSystem@@UAA_NH@Z
// EA  : 0x82EABCA0
// RVA : 0x00EABCA0
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::TerminateThread(idSuperScriptSystem *this, int threadId)
{
  idSSFiber *currentFiber; // r3
  int num; // r8
  int v6; // r9
  idSSFiber **list; // r10
  int i; // r11
  idSSFiber *v9; // r7
  int v10; // r31
  idSSFiber *v11; // r11
  idSSFiber *v12; // r3

  if ( threadId == 0 )
    return 0;
  if ( threadId == -1 )
  {
    currentFiber = this->currentFiber;
    if ( currentFiber != nullptr )
    {
LABEL_4:
      currentFiber->alive = false;
      idSysFiber::YieldFiber(this: currentFiber);
      return 1;
    }
    return 0;
  }
  num = this->fibers.num;
  v6 = 0;
  if ( num <= 0 )
    return 0;
  list = this->fibers.list;
  for ( i = 0; ; ++i )
  {
    v9 = list[i];
    if ( v9 != nullptr && v9->id == threadId )
      break;
    if ( ++v6 >= num )
      return 0;
  }
  v10 = v6;
  currentFiber = this->currentFiber;
  if ( list[v6] == currentFiber )
    goto LABEL_4;
  v11 = list[v6];
  if ( v11->fiber == currentFiber->parent )
    currentFiber->parent = v11->parent;
  v12 = this->fibers.list[v6];
  if ( v12 != nullptr )
    ((void (__fastcall *)(idSSFiber *, int))v12->dtr_idSysFiber)(a1: v12, a2: 1);
  this->fibers.list[v10] = nullptr;
  return 1;
}


// ========================================================================
// ?IsThreadHandleValid@idSuperScriptSystem@@QAA_NV?$idHandle@HW4invalidFiberId_t@@$0A@@@@Z
// EA  : 0x82EABDB8
// RVA : 0x00EABDB8
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::IsThreadHandleValid(
        idSuperScriptSystem *this,
        idHandle<int,enum invalidFiberId_t,0> *threadHandle)
{
  int num; // r8
  int v3; // r10
  int i; // r11
  idSSFiber *v5; // r7

  if ( threadHandle == nullptr )
    return 0;
  num = this->fibers.num;
  v3 = 0;
  if ( num <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v5 = this->fibers.list[i];
    if ( v5 != nullptr && (idHandle<int,enum invalidFiberId_t,0> *)v5->id == threadHandle )
      break;
    if ( ++v3 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?ClearWaitForFSM@idSuperScriptSystem@@QAAXV?$idHandle@HW4invalidFiberId_t@@$0A@@@@Z
// EA  : 0x82EABE18
// RVA : 0x00EABE18
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::ClearWaitForFSM(
        idSuperScriptSystem *this,
        idHandle<int,enum invalidFiberId_t,0> *fiberHandle)
{
  int num; // r8
  int v3; // r10
  idSSFiber **list; // r9
  int v5; // r11
  idSSFiber *v6; // r6

  num = this->fibers.num;
  v3 = 0;
  if ( num <= 0 )
  {
LABEL_6:
    MEMORY[0x1C] = 0;
  }
  else
  {
    list = this->fibers.list;
    v5 = 0;
    while ( 1 )
    {
      v6 = list[v5];
      if ( v6 != nullptr && (idHandle<int,enum invalidFiberId_t,0> *)v6->id == fiberHandle )
        break;
      ++v3;
      ++v5;
      if ( v3 >= num )
        goto LABEL_6;
    }
    list[v3]->waitingForFSM = false;
  }
}


// ========================================================================
// ?IsWaitingForFSM@idSuperScriptSystem@@QBA_NV?$idHandle@HW4invalidFiberId_t@@$0A@@@@Z
// EA  : 0x82EABE78
// RVA : 0x00EABE78
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

BOOL __fastcall idSuperScriptSystem::IsWaitingForFSM(
        idSuperScriptSystem *this,
        idHandle<int,enum invalidFiberId_t,0> *fiberHandle)
{
  int num; // r8
  int v3; // r10
  idSSFiber **list; // r9
  int i; // r11
  idSSFiber *v6; // r7
  idSSFiber *v8; // r3

  num = this->fibers.num;
  v3 = 0;
  if ( num <= 0 )
    return false;
  list = this->fibers.list;
  for ( i = 0; ; ++i )
  {
    v6 = list[i];
    if ( v6 != nullptr && (idHandle<int,enum invalidFiberId_t,0> *)v6->id == fiberHandle )
      break;
    if ( ++v3 >= num )
      return false;
  }
  v8 = list[v3];
  return v8 != nullptr && idSSFiber::IsWaitingForFSM(this: v8);
}


// ========================================================================
// ?WaitForFSM@idSuperScriptSystem@@QAAXXZ
// EA  : 0x82EABEE0
// RVA : 0x00EABEE0
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::WaitForFSM(idSuperScriptSystem *this)
{
  idSSFiber *currentFiber; // r11

  currentFiber = this->currentFiber;
  if ( currentFiber != nullptr )
  {
    currentFiber->waitingForFSM = true;
    while ( idSSFiber::IsWaitingForFSM(this: this->currentFiber) )
      idSysFiber::YieldFiber(this: this->currentFiber);
  }
}


// ========================================================================
// ?Wait@idSuperScriptSystem@@UAAXM@Z
// EA  : 0x82EABF50
// RVA : 0x00EABF50
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::Wait(idSuperScriptSystem *this, double seconds)
{
  int v3; // r30

  if ( this->currentFiber != nullptr )
  {
    v3 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + (int)(float)((float)1000.0 * (float)seconds);
    do
      idSysFiber::YieldFiber(this: this->currentFiber);
    while ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) < v3 );
  }
}


// ========================================================================
// ?WaitFrame@idSuperScriptSystem@@UAAXXZ
// EA  : 0x82EABFD8
// RVA : 0x00EABFD8
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::WaitFrame(idSuperScriptSystem *this)
{
  idSSFiber *currentFiber; // r3

  currentFiber = this->currentFiber;
  if ( currentFiber != nullptr )
    idSysFiber::YieldFiber(this: currentFiber);
}


// ========================================================================
// ?WaitForThread@idSuperScriptSystem@@UAAXH@Z
// EA  : 0x82EABFF0
// RVA : 0x00EABFF0
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::WaitForThread(idSuperScriptSystem *this, int threadId)
{
  char v4; // r8
  int v5; // r11
  int num; // ctr
  idSSFiber *v7; // r10

  if ( this->currentFiber != nullptr )
  {
    do
    {
      idSysFiber::YieldFiber(this: this->currentFiber);
      v4 = 0;
      if ( this->fibers.num > 0 )
      {
        v5 = 0;
        num = this->fibers.num;
        do
        {
          v7 = this->fibers.list[v5];
          if ( v7 != nullptr && v7->id == threadId )
            v4 = 1;
          ++v5;
          --num;
        }
        while ( num != 0 );
      }
    }
    while ( v4 != 0 );
  }
}


// ========================================================================
// ?EventGetReturnString@idSuperScriptSystem@@UAAPBDXZ
// EA  : 0x82EAC088
// RVA : 0x00EAC088
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

char *__fastcall idSuperScriptSystem::EventGetReturnString(idSuperScriptSystem *this)
{
  return this->returnString.data;
}


// ========================================================================
// ?RandomInt@idSuperScriptSystem@@UAAHH@Z
// EA  : 0x82EAC090
// RVA : 0x00EAC090
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::RandomInt(idSuperScriptSystem *this, int max)
{
  unsigned int seed; // r9
  unsigned int v4; // r5
  int v5; // r3

  if ( max == 0 )
    return 0;
  seed = clientGame->random.seed;
  __twllei(max, 0);
  v4 = 1664525 * seed + 1013904223;
  clientGame->random.seed = v4;
  v5 = (v4 >> 10) & 0x7FFF;
  __twlgei(max & ~(__ROL4__(v5, 1) - 1), 0xFFFFFFFF);
  return v5 % max;
}


// ========================================================================
// ?RandomFloat@idSuperScriptSystem@@UAAMXZ
// EA  : 0x82EAC0F0
// RVA : 0x00EAC0F0
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

float __fastcall idSuperScriptSystem::RandomFloat(idSuperScriptSystem *this)
{
  __int64 v1; // r11
  unsigned int v2; // r4
  double v3; // fp1

  HIDWORD(v1) = 1638400;
  v2 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v2;
  LODWORD(v1) = (v2 >> 10) & 0x7FFF;
  v3 = (float)((float)v1 * (float)0.000030518509);
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?GetFrameTime@idSuperScriptSystem@@UAAHXZ
// EA  : 0x82EAC140
// RVA : 0x00EAC140
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::GetFrameTime(idSuperScriptSystem *this)
{
  return idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
}


// ========================================================================
// ?DebugLine@idSuperScriptSystem@@UAAXABUssVec3_t@@00M@Z
// EA  : 0x82EAC158
// RVA : 0x00EAC158
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::DebugLine(
        idSuperScriptSystem *this,
        const ssVec3_t *color,
        const ssVec3_t *start,
        const ssVec3_t *end,
        double lifetime)
{
  double y; // fp12
  double z; // fp11
  double x; // fp10
  double v8; // fp9
  double v9; // fp6
  double v10; // fp7
  double v11; // fp5
  double v12; // fp4
  float v13[4]; // [sp+58h] [-48h] BYREF
  float v14[6]; // [sp+68h] [-38h] BYREF
  float v15[6]; // [sp+80h] [-20h] BYREF

  y = end->y;
  z = end->z;
  x = start->x;
  v8 = start->y;
  v9 = color->x;
  v10 = start->z;
  v11 = color->y;
  v12 = color->z;
  v13[0] = end->x;
  v15[3] = 1.0;
  v13[1] = y;
  v13[2] = z;
  v14[0] = x;
  v14[1] = v8;
  v14[2] = v10;
  v15[0] = v9;
  v15[1] = v11;
  v15[2] = v12;
  clientGame->renderWorld->DebugLine(
    this: clientGame->renderWorld,
    a2: (const idVec4 *)v15,
    a3: (const idVec3 *)v14,
    a4: (const idVec3 *)v13,
    a5: (int)(float)((float)1000.0 * (float)lifetime),
    a6: false);
}


// ========================================================================
// ?DebugArrow@idSuperScriptSystem@@UAAXABUssVec3_t@@00HM@Z
// EA  : 0x82EAC218
// RVA : 0x00EAC218
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::DebugArrow(
        idSuperScriptSystem *this,
        const ssVec3_t *color,
        const ssVec3_t *start,
        const ssVec3_t *end,
        const int size,
        double lifetime,
        int a7,
        __int64 a8)
{
  double y; // fp12
  double z; // fp11
  double x; // fp9
  double v11; // fp7
  double v12; // fp6
  double v13; // fp5
  double v14; // fp4
  double v15; // fp3
  __int64 v16; // [sp+50h] [-40h] BYREF
  float v17; // [sp+58h] [-38h]
  float v18[4]; // [sp+60h] [-30h] BYREF
  float v19[6]; // [sp+70h] [-20h] BYREF

  LODWORD(a8) = size;
  v16 = a8;
  y = end->y;
  z = end->z;
  x = start->x;
  v11 = start->y;
  v12 = start->z;
  v13 = color->x;
  v14 = color->y;
  v15 = color->z;
  v18[0] = end->x;
  v19[3] = 1.0;
  v18[1] = y;
  v18[2] = z;
  v17 = v12;
  v19[0] = v13;
  v19[1] = v14;
  v19[2] = v15;
  *(float *)&v16 = x;
  *((float *)&v16 + 1) = v11;
  ((void (__fastcall *)(idRenderWorld *, float *, __int64 *, float *, double))clientGame->renderWorld->DebugArrow)(
    a1: clientGame->renderWorld,
    a2: v19,
    a3: &v16,
    a4: v18,
    a5: (float)a8);
}


// ========================================================================
// ?DebugCircle@idSuperScriptSystem@@UAAXABUssVec3_t@@00MHM@Z
// EA  : 0x82EAC2E0
// RVA : 0x00EAC2E0
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::DebugCircle(
        idSuperScriptSystem *this,
        const ssVec3_t *color,
        const ssVec3_t *origin,
        const ssVec3_t *dir,
        double radius,
        const int numSteps,
        double lifetime)
{
  double y; // fp12
  double z; // fp11
  double x; // fp10
  double v10; // fp9
  double v11; // fp7
  double v12; // fp6
  double v13; // fp5
  double v14; // fp4
  float v15[4]; // [sp+58h] [-48h] BYREF
  float v16[6]; // [sp+68h] [-38h] BYREF
  float v17[6]; // [sp+80h] [-20h] BYREF

  y = dir->y;
  z = dir->z;
  x = origin->x;
  v10 = origin->y;
  v11 = origin->z;
  v12 = color->x;
  v13 = color->y;
  v14 = color->z;
  v15[0] = dir->x;
  v17[3] = 1.0;
  v15[1] = y;
  v15[2] = z;
  v16[0] = x;
  v16[1] = v10;
  v16[2] = v11;
  v17[0] = v12;
  v17[1] = v13;
  v17[2] = v14;
  ((void (__fastcall *)(idRenderWorld *, float *, float *, float *, double))clientGame->renderWorld->DebugCircle)(
    a1: clientGame->renderWorld,
    a2: v17,
    a3: v16,
    a4: v15,
    a5: radius);
}


// ========================================================================
// ?DebugBounds@idSuperScriptSystem@@UAAXABUssVec3_t@@00M@Z
// EA  : 0x82EAC398
// RVA : 0x00EAC398
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::DebugBounds(
        idSuperScriptSystem *this,
        const ssVec3_t *color,
        const ssVec3_t *mins,
        const ssVec3_t *maxs,
        double lifetime)
{
  double x; // fp13
  double y; // fp12
  double z; // fp11
  double v8; // fp10
  double v9; // fp9
  double v10; // fp7
  double v11; // fp5
  double v12; // fp4
  float v13[4]; // [sp+60h] [-30h] BYREF
  float v14[6]; // [sp+70h] [-20h] BYREF

  x = maxs->x;
  y = maxs->y;
  z = maxs->z;
  v8 = mins->x;
  v9 = mins->y;
  v10 = mins->z;
  v11 = color->y;
  v12 = color->z;
  v13[0] = color->x;
  v13[3] = 1.0;
  v13[1] = v11;
  v13[2] = v12;
  v14[3] = x;
  v14[4] = y;
  v14[5] = z;
  v14[0] = v8;
  v14[1] = v9;
  v14[2] = v10;
  clientGame->renderWorld->DebugBounds(
    this: clientGame->renderWorld,
    a2: (const idVec4 *)v13,
    a3: (const idBounds *)v14,
    a4: &vec3_origin,
    a5: (int)(float)((float)1000.0 * (float)lifetime),
    a6: false);
}


// ========================================================================
// ?DebugOrientedBounds@idSuperScriptSystem@@UAAXABUssVec3_t@@0000M@Z
// EA  : 0x82EAC450
// RVA : 0x00EAC450
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::DebugOrientedBounds(
        idSuperScriptSystem *this,
        const ssVec3_t *color,
        const ssVec3_t *mins,
        const ssVec3_t *maxs,
        const ssVec3_t *origin,
        const ssVec3_t *angles,
        double lifetime)
{
  double y; // fp12
  double z; // fp11
  double x; // fp10
  double v10; // fp9
  double v11; // fp8
  double v12; // fp6
  double v13; // fp5
  double v14; // fp4
  double v15; // fp3
  double v16; // fp2
  double v17; // fp31
  double v18; // fp30
  idRenderWorld *renderWorld; // r31
  int v20; // r30
  idRenderWorld_vtbl *v21; // r29
  idMat3 *v22; // r3
  idMat3 v23; // [sp+58h] [-B8h] BYREF
  float v24[4]; // [sp+80h] [-90h] BYREF
  float v25[8]; // [sp+90h] [-80h] BYREF
  idAngles v26[4]; // [sp+B0h] [-60h] BYREF

  v25[3] = maxs->x;
  y = maxs->y;
  z = maxs->z;
  x = mins->x;
  v24[3] = 1.0;
  v24[0] = color->x;
  v10 = mins->y;
  v11 = mins->z;
  v12 = angles->y;
  v13 = angles->z;
  v14 = origin->x;
  v15 = origin->y;
  v16 = origin->z;
  v17 = color->y;
  v18 = color->z;
  v23.mat[0].x = angles->x;
  v25[4] = y;
  v23.mat[0].y = v12;
  v23.mat[0].z = v13;
  v23.mat[1].y = v14;
  v23.mat[1].z = v15;
  v23.mat[2].x = v16;
  v24[1] = v17;
  v24[2] = v18;
  v25[5] = z;
  v25[0] = x;
  v25[1] = v10;
  v25[2] = v11;
  renderWorld = clientGame->renderWorld;
  v20 = (int)(float)((float)1000.0 * (float)lifetime);
  v21 = renderWorld->__vftable;
  v22 = idAngles::ToMat3(this: v26, result: &v23);
  v21->DebugOrientedBounds(
    this: renderWorld,
    a2: (const idVec4 *)v24,
    a3: (const idBounds *)v25,
    a4: (const idVec3 *)&v23.mat[1].y,
    a5: v22,
    a6: v20,
    a7: false);
}


// ========================================================================
// ?DebugPoint@idSuperScriptSystem@@UAAXABUssVec3_t@@0M@Z
// EA  : 0x82EAC558
// RVA : 0x00EAC558
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::DebugPoint(
        idSuperScriptSystem *this,
        const ssVec3_t *color,
        const ssVec3_t *pt,
        double lifetime)
{
  double y; // fp12
  double z; // fp11
  double x; // fp10
  double v7; // fp9
  double v8; // fp8
  float v9[6]; // [sp+58h] [-38h] BYREF
  float v10[6]; // [sp+70h] [-20h] BYREF

  y = pt->y;
  z = pt->z;
  x = color->x;
  v7 = color->y;
  v8 = color->z;
  v9[0] = pt->x;
  v10[3] = 1.0;
  v9[1] = y;
  v9[2] = z;
  v10[0] = x;
  v10[1] = v7;
  v10[2] = v8;
  clientGame->renderWorld->DebugPoint(
    this: clientGame->renderWorld,
    a2: (const idVec4 *)v10,
    a3: (const idVec3 *)v9,
    a4: (int)(float)((float)1000.0 * (float)lifetime),
    a5: false);
}


// ========================================================================
// ?DebugArc@idSuperScriptSystem@@UAAXABUssVec3_t@@00MMMMM@Z
// EA  : 0x82EAC5F0
// RVA : 0x00EAC5F0
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::DebugArc(
        idSuperScriptSystem *this,
        const ssVec3_t *color,
        const ssVec3_t *pt,
        const ssVec3_t *dir,
        double radius,
        double startAngle,
        double endAngle,
        double anglesPerSeg,
        double lifetime)
{
  double y; // fp12
  double z; // fp11
  double x; // fp10
  double v12; // fp9
  double v13; // fp8
  double v14; // fp7
  double v15; // fp6
  double v16; // fp31
  float v17[4]; // [sp+78h] [-48h] BYREF
  float v18[6]; // [sp+88h] [-38h] BYREF
  float v19[4]; // [sp+A0h] [-20h] BYREF

  y = dir->y;
  z = dir->z;
  x = pt->x;
  v12 = pt->y;
  v13 = pt->z;
  v14 = color->x;
  v15 = color->y;
  v16 = color->z;
  v17[0] = dir->x;
  v19[3] = 1.0;
  v17[1] = y;
  v17[2] = z;
  v18[0] = x;
  v18[1] = v12;
  v18[2] = v13;
  v19[0] = v14;
  v19[1] = v15;
  v19[2] = v16;
  ((void (__fastcall *)(idRenderWorld *, float *, float *, float *, double, double, double, double))clientGame->renderWorld->DebugArc)(
    a1: clientGame->renderWorld,
    a2: v19,
    a3: v18,
    a4: v17,
    a5: radius,
    a6: startAngle,
    a7: endAngle,
    a8: anglesPerSeg);
}


// ========================================================================
// ?DebugText@idSuperScriptSystem@@UAAXPBDABUssVec3_t@@1MH_N2M@Z
// EA  : 0x82EAC6C0
// RVA : 0x00EAC6C0
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::DebugText(
        idSuperScriptSystem *this,
        const char *text,
        const ssVec3_t *color,
        const ssVec3_t *origin,
        double scale,
        const int align,
        bool bold,
        bool seeThroughWalls,
        double lifetime,
        unsigned __int8 a10)
{
  double y; // fp12
  double z; // fp11
  double x; // fp10
  double v13; // fp8
  double v14; // fp7
  float v15[6]; // [sp+68h] [-38h] BYREF
  float v16[6]; // [sp+80h] [-20h] BYREF

  y = color->y;
  z = color->z;
  x = origin->x;
  v13 = origin->y;
  v14 = origin->z;
  v16[0] = color->x;
  v16[1] = y;
  v16[3] = 1.0;
  v16[2] = z;
  v15[0] = x;
  v15[1] = v13;
  v15[2] = v14;
  ((void (__fastcall *)(idRenderWorld *, const char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), float *, bool, int, bool, double))clientGame->renderWorld->DebugText)(
    a1: clientGame->renderWorld,
    a2: text,
    a3: v15,
    a4: clientGame->renderWorld->DebugText,
    a5: v16,
    a6: bold,
    a7: (int)(float)((float)1000.0 * (float)lifetime),
    a8: (_cntlzw(a10) & 0x20) != 0,
    a9: scale);
}


// ========================================================================
// ?SpawnFromDecl@idSuperScriptSystem@@UAAHPBX@Z
// EA  : 0x82EAC768
// RVA : 0x00EAC768
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

idGameLocal_vtbl *__fastcall idSuperScriptSystem::SpawnFromDecl(
        idSuperScriptSystem *this,
        const idDeclEntityDef *declToSpawn)
{
  const idEntity *v2; // r3
  char v4; // [sp+50h] [-20h] BYREF

  if ( declToSpawn == nullptr )
    idLib::Error(fmt: "Attempted to spawn a invalid entity from super script");
  v2 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: declToSpawn, a3: -1, a4: -1, a5: -1);
  return idGameLocal::GetSpawnId(this: (idGameLocal *)&v4, result: (idSpawnId *)gameLocal, ent: v2)->__vftable;
}


// ========================================================================
// ?SoundDuck@idSuperScriptSystem@@UAAXPBXMMM@Z
// EA  : 0x82EAC7D8
// RVA : 0x00EAC7D8
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::SoundDuck(
        idSuperScriptSystem *this,
        const idDeclDuck *decl,
        double fadeIn,
        double sustain,
        double fadeOut)
{
  idSoundWorld *v9; // r3

  if ( decl != nullptr )
  {
    v9 = gameLocal->GetSoundWorld(this: gameLocal);
    v9->Duck(
      this: v9,
      a2: decl,
      a3: (int)(float)((float)1000.0 * (float)fadeIn),
      a4: (int)(float)((float)1000.0 * (float)sustain),
      a5: (int)(float)((float)1000.0 * (float)fadeOut));
  }
}


// ========================================================================
// ?TableLookup@idSuperScriptSystem@@UAAMPBXM@Z
// EA  : 0x82EAC890
// RVA : 0x00EAC890
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

double __fastcall idSuperScriptSystem::TableLookup(idSuperScriptSystem *this, idLookupTable **decl, double index)
{
  if ( decl != nullptr )
    return idLookupTable::TableLookup(this: decl[16], time: index, fastSearch: (bool)decl);
  else
    return 0.0;
}


// ========================================================================
// ?TableLookupNormalized@idSuperScriptSystem@@UAAMPBXM@Z
// EA  : 0x82EAC8B0
// RVA : 0x00EAC8B0
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

double __fastcall idSuperScriptSystem::TableLookupNormalized(
        idSuperScriptSystem *this,
        idLookupTable **decl,
        double index)
{
  if ( decl != nullptr )
    return idLookupTable::TableLookupNormalized(this: decl[16], time: index, fastSearch: (bool)decl);
  else
    return 0.0;
}


// ========================================================================
// ?GetScriptObject@idSuperScriptSystem@@UAAPAVidSSObject@@HH@Z
// EA  : 0x82EAC990
// RVA : 0x00EAC990
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

idSSObject *__fastcall idSuperScriptSystem::GetScriptObject(idSuperScriptSystem *this, int spawnId, int objectId)
{
  idEntity *v4; // r3
  int num; // r10
  idSSObject *result; // r3

  v4 = gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: spawnId);
  if ( v4 == nullptr )
    return nullptr;
  if ( objectId <= 0 )
    return nullptr;
  num = v4->superScriptObjects.num;
  if ( objectId > num )
    return nullptr;
  if ( objectId - 1 >= num )
    return nullptr;
  result = v4->superScriptObjects.list[objectId - 1];
  if ( result == nullptr )
    return nullptr;
  return result;
}


// ========================================================================
// ?ThreadInfo@idSuperScriptSystem@@UAA_NHAAUssThreadInfo_t@@@Z
// EA  : 0x82EACA28
// RVA : 0x00EACA28
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::ThreadInfo(idSuperScriptSystem *this, int threadId, ssThreadInfo_t *threadInfo)
{
  idSSFiber *currentFiber; // r11
  int num; // r8
  int v6; // r10
  idSSFiber **list; // r9
  int v8; // r11
  idSSFiber *v9; // r7
  idSSObject *object; // r31
  int v12; // r4
  int v13; // r3
  int v14; // r8
  int v15; // r10
  int i; // r9
  char v17; // r11
  idSSObject *v18; // r11

  if ( threadId == -1 )
  {
    currentFiber = this->currentFiber;
  }
  else
  {
    num = this->fibers.num;
    v6 = 0;
    if ( num <= 0 )
    {
LABEL_11:
      threadInfo->spawnId = 0;
      threadInfo->objectId = 0;
      threadInfo->name = "<unknown>";
      return 0;
    }
    list = this->fibers.list;
    v8 = 0;
    while ( 1 )
    {
      v9 = list[v8];
      if ( v9 != nullptr && v9->id == threadId )
        break;
      ++v6;
      ++v8;
      if ( v6 >= num )
        goto LABEL_11;
    }
    currentFiber = list[v6];
  }
  if ( currentFiber == nullptr )
    goto LABEL_11;
  threadInfo->name = currentFiber->name;
  object = currentFiber->object;
  if ( object != nullptr )
    v12 = object->_getEntity(this: object);
  else
    v12 = 0;
  threadInfo->spawnId = v12;
  threadInfo->objectId = 0;
  v13 = ((int (__fastcall *)(idGameLocal *))gameLocal->GetEntityForSpawnId_2)(a1: gameLocal);
  if ( v13 != 0 )
  {
    v14 = *(_DWORD *)(v13 + 736);
    v15 = 0;
    if ( v14 > 0 )
    {
      for ( i = 0; ; i += 4 )
      {
        if ( v15 < 0 || (v17 = 1, v15 >= v14) )
          v17 = 0;
        v18 = v17 != 0 ? *(idSSObject **)(*(_DWORD *)(v13 + 732) + i) : nullptr;
        if ( v18 == object )
          break;
        if ( ++v15 >= v14 )
          return 1;
      }
      threadInfo->objectId = v15 + 1;
    }
  }
  return 1;
}


// ========================================================================
// ?EventCall@idSuperScriptSystem@@UAA_NHHPBDPATssVarg_t@@@Z
// EA  : 0x82EACBA0
// RVA : 0x00EACBA0
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::EventCall(
        idSuperScriptSystem *this,
        int spawnId,
        unsigned int eventNum,
        const char *format,
        ssVarg_t *args)
{
  const char *v6; // r14
  idEventReceiver *v8; // r25
  const idEventDef *EventCommand; // r3
  const idEventDef *v10; // r26
  const char *formatspec; // r11
  int v12; // r30
  int v13; // r10
  int v14; // r6
  float v15; // r15
  ssVarg_t *v16; // r31
  float *p_value; // r28
  unsigned __int8 v18; // r8
  unsigned int v19; // r11
  _DWORD *v20; // r10
  int v21; // ctr
  float *v22; // r11
  int v23; // r11
  double v24; // fp13
  double v25; // fp12
  _DWORD *v26; // r10
  float *v27; // r9
  int k; // ctr
  double v29; // fp31
  double v30; // fp30
  double v31; // fp29
  const char *v32; // r15
  const char *v33; // r14
  const char *v34; // r3
  _DWORD *v35; // r10
  float *v36; // r9
  int v37; // ctr
  BOOL b; // r8
  float *v39; // r9
  int v40; // ctr
  _DWORD *v41; // r11
  int v42; // r9
  int v43; // ctr
  float *v44; // r9
  _DWORD *v45; // r11
  double y; // fp13
  float *p_a; // r10
  double z; // fp12
  double a; // fp11
  float *v50; // r9
  int v51; // ctr
  double v52; // fp31
  double v53; // fp30
  double v54; // fp29
  double v55; // fp28
  const char *listenerList; // r15
  const char *name; // r14
  const char *v58; // r3
  _DWORD *v59; // r10
  float *v60; // r9
  int j; // ctr
  const idEntity *v62; // r3
  char *v63; // r10
  float *v64; // r9
  int i; // ctr
  int v66; // r8
  float *v67; // r9
  int v68; // ctr
  _DWORD *v69; // r11
  int v70; // ctr
  float *v71; // r11
  float *v72; // r10
  double v73; // fp31
  _DWORD *v74; // r10
  float *v75; // r9
  int m; // ctr
  double v77; // fp13
  _DWORD *v78; // r10
  double v79; // fp12
  float *v80; // r9
  int n; // ctr
  double v82; // fp31
  double v83; // fp30
  double v84; // fp29
  const char *v85; // r15
  const char *v86; // r14
  const char *v87; // r3
  _DWORD *v88; // r10
  float *v89; // r9
  int v90; // ctr
  idSSFiber1<char const *> *v91; // r3
  float v92; // [sp+50h] [-370h] BYREF
  int v93; // [sp+54h] [-36Ch]
  const char *v94; // [sp+58h] [-368h]
  idVec3 v95; // [sp+60h] [-360h] BYREF
  idVec3 v96; // [sp+70h] [-350h] BYREF
  idAngles v97; // [sp+80h] [-340h] BYREF
  idAngles v98; // [sp+90h] [-330h] BYREF
  idColor v99; // [sp+A0h] [-320h] BYREF
  idColor v100; // [sp+B0h] [-310h] BYREF
  char v101; // [sp+C0h] [-300h]
  float f; // [sp+C4h] [-2FCh]
  float v103; // [sp+C8h] [-2F8h]
  float v104; // [sp+CCh] [-2F4h]
  float v105; // [sp+D0h] [-2F0h]
  _BYTE v106[8]; // [sp+DCh] [-2E4h] BYREF
  float v107; // [sp+E4h] [-2DCh]
  float v108; // [sp+E8h] [-2D8h]
  float v109; // [sp+ECh] [-2D4h]
  float v110; // [sp+F0h] [-2D0h]
  _BYTE v111[8]; // [sp+FCh] [-2C4h] BYREF
  float v112; // [sp+104h] [-2BCh]
  float v113; // [sp+108h] [-2B8h]
  float v114; // [sp+10Ch] [-2B4h]
  _BYTE v115[8]; // [sp+11Ch] [-2A4h] BYREF
  float v116; // [sp+124h] [-29Ch]
  float v117; // [sp+128h] [-298h]
  float v118; // [sp+12Ch] [-294h]
  _BYTE v119[8]; // [sp+13Ch] [-284h] BYREF
  float x; // [sp+144h] [-27Ch]
  float v121; // [sp+148h] [-278h]
  float v122; // [sp+14Ch] [-274h]
  _BYTE v123[8]; // [sp+15Ch] [-264h] BYREF
  float v124; // [sp+164h] [-25Ch]
  float v125; // [sp+168h] [-258h]
  float v126; // [sp+16Ch] [-254h]
  _DWORD v127[8]; // [sp+17Ch] [-244h] BYREF
  _BYTE v128[8]; // [sp+19Ch] [-224h] BYREF
  float v129; // [sp+1A4h] [-21Ch]
  _DWORD v130[8]; // [sp+1BCh] [-204h] BYREF
  _BYTE v131[8]; // [sp+1DCh] [-1E4h] BYREF
  int v132; // [sp+1E4h] [-1DCh]
  float v133[8]; // [sp+1FCh] [-1C4h] BYREF
  char v134; // [sp+21Ch] [-1A4h] BYREF
  idEventArg v135; // [sp+220h] [-1A0h] BYREF
  _DWORD v136[9]; // [sp+23Ch] [-184h] BYREF
  idAICover v137; // [sp+260h] [-160h] BYREF
  char v138; // [sp+274h] [-14Ch]
  int v139; // [sp+278h] [-148h]
  char v140; // [sp+288h] [-138h]
  int v141; // [sp+28Ch] [-134h]
  char v142; // [sp+29Ch] [-124h]
  int v143; // [sp+2A0h] [-120h]
  char v144; // [sp+2B0h] [-110h]
  int v145; // [sp+2B4h] [-10Ch]
  char v146; // [sp+2C4h] [-FCh]
  int v147; // [sp+2C8h] [-F8h]
  char v148; // [sp+2D8h] [-E8h]
  int v149; // [sp+2DCh] [-E4h]
  char v150; // [sp+2ECh] [-D4h]
  int v151; // [sp+2F0h] [-D0h]

  v6 = format;
  v8 = (idEventReceiver *)((int (__fastcall *)(idGameLocal *))gameLocal->GetEntityForSpawnId_2)(a1: gameLocal);
  if ( v8 != nullptr )
  {
    EventCommand = idEventDef::GetEventCommand(eventnum: eventNum);
    v10 = EventCommand;
    if ( EventCommand != nullptr )
    {
      formatspec = EventCommand->formatspec;
      v12 = 0;
      v13 = *(unsigned __int8 *)v6;
      HIBYTE(v137.aas) = 0;
      v137.spawnId.value = 0;
      v138 = 0;
      v139 = 0;
      v140 = 0;
      v141 = 0;
      v142 = 0;
      v143 = 0;
      v144 = 0;
      v145 = 0;
      v146 = 0;
      v147 = 0;
      v148 = 0;
      v149 = 0;
      v94 = formatspec;
      v150 = 0;
      v151 = 0;
      if ( v13 != 0 )
      {
        v92 = *(float *)&v6;
        v14 = formatspec - v6;
        v93 = formatspec - v6;
        v15 = *(float *)&v6;
        v16 = args - 1;
        p_value = (float *)&v137.spawnId.value;
        while ( 1 )
        {
          v18 = *(_BYTE *)LODWORD(v15);
          if ( *(_BYTE *)LODWORD(v15) != *(_BYTE *)(v14 + LODWORD(v15)) )
          {
            idLib::Error(fmt: "SS: Incorrect format string for '%s': Expected %s, got %s", v10->name, v94, v6);
_LN165_1:
            idLib::Warning(fmt: "SS: cannot call event with a script list");
            return;
          }
          v19 = (unsigned __int8)*(_BYTE *)LODWORD(v15);
          if ( v19 > 0x65 )
            break;
          if ( *(_BYTE *)LODWORD(v15) == 101 )
          {
            v62 = gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: v16[1].i);
            idEventArg::idEventArg(this: &v135, data: v62);
            v63 = &v134;
            ++v12;
            ++v16;
            v64 = p_value - 2;
            for ( i = 5; i != 0; --i )
            {
              v63 += 4;
              *++v64 = *(float *)v63;
            }
          }
          else if ( v19 > 0x62 )
          {
            if ( v19 == 99 )
            {
              y = v16[1].v.y;
              p_a = &v100.a;
              z = v16[1].v.z;
              a = v16[1].clr.a;
              f = v16[1].f;
              v101 = 99;
              v103 = y;
              v50 = p_value - 2;
              v104 = z;
              v51 = 5;
              v105 = a;
              do
              {
                *++v50 = *++p_a;
                --v51;
              }
              while ( v51 != 0 );
              v52 = *p_value;
              v53 = p_value[1];
              ++v12;
              v54 = p_value[2];
              ++v16;
              v55 = p_value[3];
              v99.r = *p_value;
              v99.g = v53;
              v99.b = v54;
              v99.a = v55;
              if ( (unsigned __int8)IsValid<idColor>(v: &v99) == 0 )
              {
                listenerList = (const char *)v8[1].listenerList;
                name = v10->name;
                v100.r = v52;
                v100.g = v53;
                v100.b = v54;
                v100.a = v55;
                v58 = idColor::ToString(this: &v100, precision: 6, parens: false);
                idLib::Warning(
                  fmt: "SS: '%s.%s', invalid color value '%s' for parameter %d",
                  listenerList,
                  name,
                  v58,
                  v12);
                v59 = v106;
                v107 = 0.0;
                v108 = 0.0;
                v106[4] = 99;
                v109 = 0.0;
                v110 = 0.0;
                v60 = p_value - 2;
                for ( j = 5; j != 0; --j )
                  *++v60 = *(float *)++v59;
                v15 = v92;
              }
            }
            else
            {
              if ( v19 != 100 )
                goto LABEL_66;
              v42 = v16[1].i;
              ++v12;
              HIBYTE(v130[1]) = 100;
              ++v16;
              v43 = 5;
              v130[2] = v42;
              v44 = p_value - 2;
              v45 = v130;
              do
              {
                *++v44 = *(float *)++v45;
                --v43;
              }
              while ( v43 != 0 );
            }
          }
          else if ( v19 == 98 )
          {
            b = v16[1].b;
            HIBYTE(v136[1]) = 105;
            ++v12;
            ++v16;
            v39 = p_value - 2;
            v40 = 5;
            v136[2] = b;
            v41 = v136;
            do
            {
              *++v39 = *(float *)++v41;
              --v40;
            }
            while ( v40 != 0 );
          }
          else if ( v19 > 0x35 )
          {
            if ( v19 != 97 )
              goto LABEL_66;
            v24 = v16[1].v.y;
            v25 = v16[1].v.z;
            v26 = v111;
            v112 = v16[1].f;
            v111[4] = 97;
            v27 = p_value - 2;
            v113 = v24;
            v114 = v25;
            for ( k = 5; k != 0; --k )
              *++v27 = *(float *)++v26;
            v29 = *p_value;
            v30 = p_value[1];
            ++v12;
            v31 = p_value[2];
            ++v16;
            v96.x = *p_value;
            v96.y = v30;
            v96.z = v31;
            if ( (unsigned __int8)IsValid<idVec3>(v: &v96) == 0 )
            {
              v32 = (const char *)v8[1].listenerList;
              v33 = v10->name;
              v97.pitch = v29;
              v97.yaw = v30;
              v97.roll = v31;
              v34 = idVec3::ToString(this: &v97, precision: 6);
              idLib::Warning(fmt: "SS: '%s.%s', invalid angle value '%s' for parameter %d", v32, v33, v34, v12);
              v35 = v119;
              v119[4] = 118;
              x = vec3_origin.x;
              v36 = p_value - 2;
              v121 = vec3_origin.y;
              v37 = 5;
              v122 = vec3_origin.z;
              do
              {
                *++v36 = *(float *)++v35;
                --v37;
              }
              while ( v37 != 0 );
              v15 = v92;
            }
          }
          else
          {
            if ( v19 != 53 && (v19 < 0x31 || v19 > 0x32) )
            {
LABEL_66:
              idLib::Error(fmt: "SS: Invalid arg format string for '%s'.", v10->name);
              idSSFiber1<int>::Run(this: v91);
              return;
            }
LABEL_15:
            ++v16;
            v20 = v131;
            ++v12;
            v21 = 5;
            v132 = v16->i;
            v131[4] = 115;
            v22 = p_value - 2;
            do
            {
              *++v22 = *(float *)++v20;
              --v21;
            }
            while ( v21 != 0 );
            *((_BYTE *)p_value - 4) = v18;
          }
LABEL_18:
          ++LODWORD(v15);
          v23 = (unsigned __int8)*(_BYTE *)LODWORD(v15);
          p_value += 5;
          v92 = v15;
          if ( v23 == 0 )
            goto LABEL_19;
          v14 = v93;
          v6 = format;
        }
        switch ( *(_BYTE *)LODWORD(v15) )
        {
          case 'f':
            v133[2] = v16[1].f;
            HIBYTE(v133[1]) = 102;
            ++v12;
            ++v16;
            v70 = 5;
            v71 = v133;
            v72 = p_value - 2;
            do
            {
              *++v72 = *++v71;
              --v70;
            }
            while ( v70 != 0 );
            v73 = *p_value;
            v92 = *p_value;
            if ( (unsigned __int8)IsValid<float>(f: &v92) == 0 )
            {
              idLib::Warning(
                fmt: "SS: '%s.%s', invalid float value '%f' for parameter %d",
                (const char *)v8[1].listenerList,
                v10->name,
                v73,
                LODWORD(v73));
              v74 = v128;
              v129 = 0.0;
              v128[4] = 102;
              v75 = p_value - 2;
              for ( m = 5; m != 0; --m )
                *++v75 = *(float *)++v74;
            }
            goto LABEL_18;
          case 'i':
            v66 = v16[1].i;
            HIBYTE(v127[1]) = 105;
            ++v12;
            ++v16;
            v67 = p_value - 2;
            v68 = 5;
            v127[2] = v66;
            v69 = v127;
            do
            {
              *++v67 = *(float *)++v69;
              --v68;
            }
            while ( v68 != 0 );
            goto LABEL_18;
          case 'l':
            goto _LN165_1;
          case 's':
            goto LABEL_15;
          case 'v':
            v77 = v16[1].v.y;
            v78 = v115;
            v79 = v16[1].v.z;
            v116 = v16[1].f;
            v115[4] = 118;
            v117 = v77;
            v118 = v79;
            v80 = p_value - 2;
            for ( n = 5; n != 0; --n )
              *++v80 = *(float *)++v78;
            v82 = *p_value;
            v83 = p_value[1];
            ++v12;
            v84 = p_value[2];
            ++v16;
            v95.x = *p_value;
            v95.y = v83;
            v95.z = v84;
            if ( (unsigned __int8)IsValid<idVec3>(v: &v95) == 0 )
            {
              v85 = (const char *)v8[1].listenerList;
              v86 = v10->name;
              v98.pitch = v82;
              v98.yaw = v83;
              v98.roll = v84;
              v87 = idVec3::ToString(this: &v98, precision: 6);
              idLib::Warning(fmt: "SS: '%s.%s', invalid vector value '%s' for parameter %d", v85, v86, v87, v12);
              v88 = v123;
              v123[4] = 118;
              v124 = vec3_origin.x;
              v89 = p_value - 2;
              v125 = vec3_origin.y;
              v90 = 5;
              v126 = vec3_origin.z;
              do
              {
                *++v89 = *(float *)++v88;
                --v90;
              }
              while ( v90 != 0 );
              v15 = v92;
            }
            goto LABEL_18;
          case 'x':
            idLib::Warning(fmt: "SS: cannot call event with variable args");
            break;
          default:
            goto LABEL_66;
        }
      }
      else
      {
LABEL_19:
        if ( v8->RespondsTo(this: v8, a2: v10) )
          idEventReceiver::ProcessEventArgPtr(this: (idEventReceiver *)&v135, result: v8, ev: v10, args: &v137);
      }
    }
  }
}


// ========================================================================
// ?CreateThreadDelayed@idSuperScriptSystem@@UAAHPBDPAVidSSObject@@P6AX1PAX@Z2@Z
// EA  : 0x82EAD320
// RVA : 0x00EAD320
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::CreateThreadDelayed(
        idSuperScriptSystem *this,
        const char *name,
        idSSObject *sso,
        idSSFiber_vtbl *entryPoint,
        char *data)
{
  int nextFiberId; // r29
  idSSFiber *v11; // r3
  idSSFiber *v12; // r30
  idSSFiber *v13; // r11
  idSSFiber *v15; // [sp+50h] [-50h] BYREF

  nextFiberId = this->nextFiberId;
  this->nextFiberId = nextFiberId + 1;
  v11 = (idSSFiber *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                       size: 0x38u,
                       tag: TAG_NEW,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  v12 = v11;
  v15 = v11;
  if ( v11 != nullptr )
  {
    idSSFiber::idSSFiber(this: v11, name, fiberId: nextFiberId, sso);
    v12[1].__vftable = entryPoint;
    v13 = v12;
    v12[1].name = data;
    v12->__vftable = (idSSFiber_vtbl *)&idSSFiber0::`vftable';
  }
  else
  {
    v13 = nullptr;
  }
  v15 = v13;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fibers,
    obj: (encounterGroupRole_t *)&v15);
  return nextFiberId;
}


// ========================================================================
// __unwind$490275_1
// EA  : 0x82EAD3D4
// RVA : 0x00EAD3D4
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall _unwind_490275_1(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// ?CreateThread@idSuperScriptSystem@@UAAHPBDPAVidSSObject@@P6AX1PAX@Z2@Z
// EA  : 0x82EAD408
// RVA : 0x00EAD408
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::CreateThread(
        idSuperScriptSystem *this,
        const char *name,
        idSSObject *sso,
        idSSFiber_vtbl *entryPoint,
        char *data)
{
  int nextFiberId; // r24
  idSSFiber *v12; // r3
  idSSFiber *v13; // r30
  int v14; // r27
  idSSFiber *v15; // [sp+50h] [-50h] BYREF

  if ( sso == nullptr )
    return 0;
  nextFiberId = this->nextFiberId;
  this->nextFiberId = nextFiberId + 1;
  v12 = (idSSFiber *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                       size: 0x38u,
                       tag: TAG_NEW,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  v13 = v12;
  v15 = v12;
  if ( v12 != nullptr )
  {
    idSSFiber::idSSFiber(this: v12, name, fiberId: nextFiberId, sso);
    v13[1].__vftable = entryPoint;
    v13[1].name = data;
    v13->__vftable = (idSSFiber_vtbl *)&idSSFiber0::`vftable';
  }
  else
  {
    v13 = nullptr;
  }
  v15 = v13;
  v14 = idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->fibers,
          obj: (encounterGroupRole_t *)&v15);
  if ( !idSuperScriptSystem::ExecuteFiber(this, fiber: v13) )
  {
    idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(
      this: (idList<idEntityPtr<idEntity>,58> *)&this->fibers,
      index: v14);
    if ( v13 != nullptr )
      ((void (__fastcall *)(idSSFiber *, int))v13->dtr_idSysFiber)(a1: v13, a2: 1);
  }
  return nextFiberId;
}


// ========================================================================
// __unwind$490310_0
// EA  : 0x82EAD514
// RVA : 0x00EAD514
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

void __fastcall _unwind_490310_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// ?FindObject@idSuperScriptSystem@@UAAHHPBD_N@Z
// EA  : 0x82EAD540
// RVA : 0x00EAD540
// PDB : w:\tech5\tungsten\game\superscript\ss_gamelite.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::FindObject(idSuperScriptSystem *this, int spawnId, const char *name, bool create)
{
  int v7; // r3
  int v8; // r31
  int v9; // r11
  int v10; // r30
  int v11; // r29
  char v12; // r11
  bool v13; // zf
  int v14; // r3
  idSSObject *v15; // r30
  int v16; // r29
  idGameLocal *v17; // r3
  encounterGroupRole_t v19[20]; // [sp+50h] [-50h] BYREF

  v7 = ((int (__fastcall *)(idGameLocal *))gameLocal->GetEntityForSpawnId_2)(a1: gameLocal);
  v8 = v7;
  if ( v7 == 0 )
    return 0;
  v9 = *(_DWORD *)(v7 + 736);
  v10 = 0;
  if ( v9 <= 0 )
  {
LABEL_11:
    if ( create )
    {
      v19[0] = (encounterGroupRole_t)idSuperScriptSystem::CreateObject(this, name);
      v15 = (idSSObject *)v19[0];
      v16 = idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)(v8 + 732), obj: v19)
          + 1;
      v17 = idGameLocal::GetSpawnId(this: (idGameLocal *)v19, result: (idSpawnId *)gameLocal, ent: (const idEntity *)v8);
      v15->_setEntity(this: v15, a2: (int)v17->__vftable);
      this->CreateThread(this, a2: "Init", a3: v15, a4: idSuperScriptSystem::FiberEntry_Init, a5: nullptr);
      return v16;
    }
    return 0;
  }
  v11 = 0;
  while ( 1 )
  {
    if ( v10 < 0 || (v13 = v10 < v9, v12 = 1, !v13) )
      v12 = 0;
    if ( v12 != 0 )
    {
      v14 = *(_DWORD *)(*(_DWORD *)(v8 + 732) + v11);
      if ( v14 != 0
        && (*(unsigned __int8 (__fastcall **)(int, const char *))(*(_DWORD *)v14 + 96))(a1: v14, a2: name) != 0 )
      {
        return v10 + 1;
      }
    }
    v9 = *(_DWORD *)(v8 + 736);
    ++v10;
    v11 += 4;
    if ( v10 >= v9 )
      goto LABEL_11;
  }
}

