
// ========================================================================
// ?AllocEvent@idAIEventPool@@QAAPAVidAIEvent@@XZ
// EA  : 0x82A44D40
// RVA : 0x00A44D40
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventpool.cpp
// ========================================================================

idAIEvent *__fastcall idAIEventPool::AllocEvent(idAIEventPool *this)
{
  idClass *v2; // r3
  const idTypeInfo *eventType; // r8
  idClass *v4; // r31
  int num; // r10
  int v6; // r10
  idAIEvent **v7; // r9
  int v8; // r9
  int v9; // r9

  if ( this->freeEvents.num != 0 )
  {
    num = this->freeEvents.num;
    v7 = &this->freeEvents.list[num];
    v6 = num - 1;
    v4 = (idClass *)*(v7 - 1);
    if ( v6 >= 0 )
    {
      v8 = this->freeEvents.num;
      if ( v6 < v8 )
      {
        v9 = v8 - 1;
        this->freeEvents.num = v9;
        if ( v6 != v9 )
          this->freeEvents.list[v6] = this->freeEvents.list[v9];
      }
    }
    v4->__vftable[1].GetType(this: v4);
  }
  else
  {
    v2 = this->eventType->CreateInstance();
    eventType = this->eventType;
    v4 = v2;
    idLib::Warning(fmt: "idAIEventPool '%s' : pool exceeded.", eventType->classname);
  }
  return (idAIEvent *)v4;
}


// ========================================================================
// ?GetSize@idAIEventPool@@QBAIXZ
// EA  : 0x82A44E08
// RVA : 0x00A44E08
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventpool.cpp
// ========================================================================

int __fastcall idAIEventPool::GetSize(idAIEventPool *this)
{
  int v2; // r28
  int v3; // r31
  int v4; // r30
  idTypeInfo *v5; // r3

  v2 = 4;
  v3 = 0;
  if ( this->freeEvents.num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = this->freeEvents.list[v4]->GetType(this: this->freeEvents.list[v4]);
      ++v3;
      ++v4;
      v2 += v5->size;
    }
    while ( v3 < this->freeEvents.num );
  }
  return v2;
}


// ========================================================================
// ?Free@idAIEventPool@@AAAXXZ
// EA  : 0x82A44E70
// RVA : 0x00A44E70
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventpool.cpp
// ========================================================================

void __fastcall idAIEventPool::Free(idAIEventPool *this)
{
  int v2; // r29
  int v3; // r30
  idAIEvent *v4; // r3
  idAIEvent **list; // r4

  v2 = 0;
  if ( this->freeEvents.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->freeEvents.list[v3];
      if ( v4 != nullptr )
        ((void (__fastcall *)(idAIEvent *, int))v4->dtr_idClass)(a1: v4, a2: 1);
      ++v2;
      ++v3;
    }
    while ( v2 < this->freeEvents.num );
  }
  if ( this->freeEvents.listStatic == 0 || this->freeEvents.listStatic == 2 )
  {
    list = this->freeEvents.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->freeEvents.list = nullptr;
    this->freeEvents.size = 0;
  }
  this->freeEvents.num = 0;
}


// ========================================================================
// ??0idAIEventPool@@AAA@XZ
// EA  : 0x82A44F20
// RVA : 0x00A44F20
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventpool.cpp
// ========================================================================

idAIEventPool *__fastcall idAIEventPool::idAIEventPool(idAIEventPool *this)
{
  this->initialPoolSize = 0;
  this->__vftable = (idAIEventPool_vtbl *)&idAIEventPool::`vftable';
  this->eventType = nullptr;
  this->freeEvents.list = nullptr;
  this->freeEvents.granularity = 0;
  this->freeEvents.memTag = 5;
  this->freeEvents.listStatic = 0;
  this->freeEvents.size = 0;
  this->freeEvents.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->freeEvents);
  return this;
}


// ========================================================================
// __unwind$487544
// EA  : 0x82A44F98
// RVA : 0x00A44F98
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventpool.cpp
// ========================================================================

void _unwind_487544()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idAIEventPool@@QAA@PBVidTypeInfo@@@Z
// EA  : 0x82A44FC8
// RVA : 0x00A44FC8
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventpool.cpp
// ========================================================================

idAIEventPool *__fastcall idAIEventPool::idAIEventPool(idAIEventPool *this, const idTypeInfo *eventType_)
{
  this->eventType = eventType_;
  this->initialPoolSize = 0;
  this->__vftable = (idAIEventPool_vtbl *)&idAIEventPool::`vftable';
  this->freeEvents.list = nullptr;
  this->freeEvents.granularity = 0;
  this->freeEvents.memTag = 5;
  this->freeEvents.listStatic = 0;
  this->freeEvents.size = 0;
  this->freeEvents.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->freeEvents);
  return this;
}


// ========================================================================
// __unwind$487569
// EA  : 0x82A45040
// RVA : 0x00A45040
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventpool.cpp
// ========================================================================

void _unwind_487569()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idAIEventPool@@UAA@XZ
// EA  : 0x82A45070
// RVA : 0x00A45070
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventpool.cpp
// ========================================================================

void __fastcall idAIEventPool::~idAIEventPool(idAIEventPool *this)
{
  this->__vftable = (idAIEventPool_vtbl *)&idAIEventPool::`vftable';
  idAIEventPool::Free(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->freeEvents);
  this->__vftable = (idAIEventPool_vtbl *)&idClass::`vftable';
}


// ========================================================================
// __unwind$487593
// EA  : 0x82A450CC
// RVA : 0x00A450CC
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventpool.cpp
// ========================================================================

void _unwind_487593()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$487594
// EA  : 0x82A450F4
// RVA : 0x00A450F4
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventpool.cpp
// ========================================================================

void _unwind_487594()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 12));
}


// ========================================================================
// ?AllocInitialPool@idAIEventPool@@QAAXXZ
// EA  : 0x82A45180
// RVA : 0x00A45180
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventpool.cpp
// ========================================================================

void __fastcall idAIEventPool::AllocInitialPool(idAIEventPool *this)
{
  int initialPoolSize; // r4
  idList<idAIEvent *,5> *p_freeEvents; // r27
  int v4; // r3
  int v5; // r31
  int v6; // r30
  idAIEvent **list; // r28

  if ( this->eventType != nullptr )
  {
    initialPoolSize = this->initialPoolSize;
    if ( initialPoolSize > 0 )
    {
      p_freeEvents = &this->freeEvents;
      v4 = idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->freeEvents, newNum: initialPoolSize);
      v5 = 0;
      if ( this->initialPoolSize > 0 )
      {
        v6 = 0;
        do
        {
          list = p_freeEvents->list;
          v4 = ((int (__fastcall *)(int))this->eventType->CreateInstance)(a1: v4);
          ++v5;
          list[v6++] = (idAIEvent *)v4;
        }
        while ( v5 < this->initialPoolSize );
      }
    }
  }
}


// ========================================================================
// ?FreeEvent@idAIEventPool@@QAAXPAVidAIEvent@@@Z
// EA  : 0x82A45200
// RVA : 0x00A45200
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventpool.cpp
// ========================================================================

void __fastcall idAIEventPool::FreeEvent(
        idAIEventPool *this,
        idAIEvent *event,
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
        idAIEvent *a14)
{
  a14 = event;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->freeEvents,
    obj: (const encounterGroupRole_t *)&a14);
}

