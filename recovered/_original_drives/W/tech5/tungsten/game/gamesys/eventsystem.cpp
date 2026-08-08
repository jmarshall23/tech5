
// ========================================================================
// ?Free@idEventSystem@@QAAXPAVidEvent@@@Z
// EA  : 0x82D61BD0
// RVA : 0x00D61BD0
// PDB : w:\tech5\tungsten\game\gamesys\eventsystem.cpp
// ========================================================================

void __fastcall idEventSystem::Free(idEventSystem *this, idEvent *ev)
{
  int num; // r10
  int v4; // r4
  int v5; // r11
  unsigned __int8 *data; // r4

  num = this->eventQueue.num;
  v4 = 0;
  if ( num > 0 )
  {
    v5 = 0;
    while ( this->eventQueue.list[v5] != ev )
    {
      ++v4;
      ++v5;
      if ( v4 >= num )
        goto LABEL_8;
    }
    if ( v4 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex((idList<idEntityPtr<idEntity>,58> *)this, index: v4);
  }
LABEL_8:
  data = ev->data;
  if ( data != nullptr )
  {
    idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
    ev->data = nullptr;
  }
  ((void (__fastcall *)(idEvent *, int))ev->dtr_idClass)(a1: ev, a2: 1);
}


// ========================================================================
// ?CancelEvents@idEventSystem@@QAAXPBVidEventReceiver@@PBVidEventDef@@@Z
// EA  : 0x82D61C78
// RVA : 0x00D61C78
// PDB : w:\tech5\tungsten\game\gamesys\eventsystem.cpp
// ========================================================================

void __fastcall idEventSystem::CancelEvents(idEventSystem *this, const idEventReceiver *obj, const idEventDef *evdef)
{
  int num; // r10
  int v7; // r29
  int v8; // r30
  idEvent *v9; // r31
  int v10; // r4
  int v11; // r11
  unsigned __int8 *data; // r4

  num = this->eventQueue.num;
  v7 = 0;
  if ( num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = this->eventQueue.list[v8];
      if ( v9->object == obj && (evdef == nullptr || evdef == v9->eventdef) )
      {
        v10 = 0;
        if ( num > 0 )
        {
          v11 = 0;
          while ( this->eventQueue.list[v11] != v9 )
          {
            ++v10;
            ++v11;
            if ( v10 >= num )
              goto LABEL_13;
          }
          if ( v10 >= 0 )
            idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(
              (idList<idEntityPtr<idEntity>,58> *)this,
              index: v10);
        }
LABEL_13:
        data = v9->data;
        if ( data != nullptr )
        {
          idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
          v9->data = nullptr;
        }
        ((void (__fastcall *)(idEvent *, int))v9->dtr_idClass)(a1: v9, a2: 1);
        --v7;
        --v8;
      }
      num = this->eventQueue.num;
      ++v7;
      ++v8;
    }
    while ( v7 < num );
  }
}


// ========================================================================
// ??0idEvent@@QAA@XZ
// EA  : 0x82D61D70
// RVA : 0x00D61D70
// PDB : w:\tech5\tungsten\game\gamesys\eventsystem.cpp
// ========================================================================

idEvent *__fastcall idEvent::idEvent(idEvent *this)
{
  this->eventdef = nullptr;
  this->__vftable = (idEvent_vtbl *)&idEvent::`vftable';
  this->args[0].type = 0;
  this->args[0].value.i = 0;
  this->args[1].type = 0;
  this->args[1].value.i = 0;
  this->args[2].type = 0;
  this->args[2].value.i = 0;
  this->args[3].type = 0;
  this->args[3].value.i = 0;
  this->args[4].type = 0;
  this->args[4].value.i = 0;
  this->args[5].type = 0;
  this->args[5].value.i = 0;
  this->args[6].type = 0;
  this->args[6].value.i = 0;
  this->args[7].type = 0;
  this->args[7].value.i = 0;
  this->data = nullptr;
  this->time = 0;
  this->object = nullptr;
  this->eventNode.head = &this->eventNode;
  this->eventNode.next = &this->eventNode;
  this->eventNode.owner = nullptr;
  this->eventNode.prev = &this->eventNode;
  memset(Dst: this->args, Val: 0, Size: sizeof(this->args));
  return this;
}


// ========================================================================
// ?Alloc@idEventSystem@@QAAPAVidEvent@@ABVidEventDef@@HPAD@Z
// EA  : 0x82D61E20
// RVA : 0x00D61E20
// PDB : w:\tech5\tungsten\game\gamesys\eventsystem.cpp
// ========================================================================

idEvent *__fastcall idEventSystem::Alloc(idEventSystem *this, const idEventDef *evdef, int numargs, char *args)
{
  idEvent *v7; // r3
  idEvent *v8; // r25
  int numstrings; // r11
  char *data; // r29
  int v11; // r30
  const char *formatspec; // r28
  idEventArg *i; // r31
  char v14; // r10
  unsigned int v15; // r11
  char *v16; // r11
  char v17; // r9
  char *v18; // r10
  _DWORD *v19; // r9
  int j; // ctr
  unsigned int v21; // r10
  _DWORD *v22; // r10
  _DWORD *v23; // r9
  int k; // ctr
  unsigned int v26; // r4
  idEvent *v27; // r3
  _BYTE v28[8]; // [sp+4Ch] [-74h] BYREF
  char *v29; // [sp+54h] [-6Ch]

  v7 = (idEvent *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                    size: 0xC4u,
                    tag: TAG_NEW,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
    v8 = idEvent::idEvent(this: v7);
  else
    v8 = nullptr;
  v8->eventdef = evdef;
  if ( numargs != evdef->numargs )
    idLib::Error(fmt: "idEventSystem::Alloc: Wrong number of args for '%s' event.", evdef->name);
  numstrings = evdef->numstrings;
  if ( numstrings > 0 )
    v8->data = (unsigned __int8 *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\tungsten\\game\\gamesys\\EventSystem.cpp(67) : TAG_EVENTS",
                                    size: numstrings << 8,
                                    tag: TAG_EVENTS,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  data = (char *)v8->data;
  v11 = 0;
  formatspec = evdef->formatspec;
  if ( numargs <= 0 )
    return v8;
  for ( i = v8->args; ; ++i )
  {
    v14 = formatspec[v11];
    v15 = (unsigned int)(args + 7) & 0xFFFFFFF8;
    args = (char *)(v15 + 8);
    v16 = *(char **)(v15 + 4);
    v17 = *v16;
    if ( v14 != *v16 && (v14 != 101 || v17 != 105 || *((_DWORD *)v16 + 1) != 0) && (v14 != 98 || v17 != 105) )
      break;
    v18 = v16 - 4;
    v19 = (_DWORD *)&i[-1].value.q[3];
    for ( j = 5; j != 0; --j )
    {
      v18 += 4;
      *++v19 = *(_DWORD *)v18;
    }
    v21 = (unsigned __int8)formatspec[v11];
    if ( v21 <= 0x35 )
    {
      if ( v21 != 53 && (v21 < 0x31 || v21 > 0x32) )
        goto LABEL_27;
LABEL_24:
      idStr::Copynz(dest: data, src: *((const char **)v16 + 1), destsize: 256);
      v22 = v28;
      v29 = data;
      v28[4] = 115;
      v23 = (_DWORD *)&i[-1].value.q[3];
      for ( k = 5; k != 0; --k )
        *++v23 = *++v22;
      data += 256;
      i->type = formatspec[v11];
      goto LABEL_27;
    }
    if ( v21 == 115 )
      goto LABEL_24;
LABEL_27:
    if ( ++v11 >= numargs )
      return v8;
  }
  idLib::Error(
    fmt: "idEventSystem::Alloc : Wrong type passed in for arg # %d on '%s' event (expected %c, got %c).",
    v11,
    evdef->name,
    v14,
    v17);
  return (idEvent *)idEvent::`vector deleting destructor'(this: v27, a2: v26);
}


// ========================================================================
// ?Schedule@idEventSystem@@QAAXPAVidEvent@@PAVidEventReceiver@@H@Z
// EA  : 0x82D62068
// RVA : 0x00D62068
// PDB : w:\tech5\tungsten\game\gamesys\eventsystem.cpp
// ========================================================================

void __fastcall idEventSystem::Schedule(idEventSystem *this, idEvent *ev, idEventReceiver *obj, int time)
{
  int v6; // r9
  int v7; // r10
  int num; // r30
  int v9; // r11
  int granularity; // r4
  int size; // r11
  bool v12; // cr58
  signed int v13; // r10
  int v14; // r4
  int v15; // r11
  int v16; // r11
  int v17; // r11
  int v18; // ctr
  idEvent **v19; // r10
  int v20; // r4

  ev->object = obj;
  v6 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) + time;
  v7 = 0;
  ev->time = v6;
  num = this->eventQueue.num;
  if ( num > 0 )
  {
    v9 = 0;
    while ( v6 >= this->eventQueue.list[v9]->time )
    {
      ++v7;
      ++v9;
      if ( v7 >= this->eventQueue.num )
        goto LABEL_7;
    }
    num = v7;
  }
LABEL_7:
  if ( this->eventQueue.list != nullptr )
    goto LABEL_11;
  granularity = this->eventQueue.granularity;
  if ( granularity <= 0 )
    granularity = 1;
  if ( (unsigned __int8)idList<idNavSpline *,5>::Resize(
                          (idList<idSpawnArea::GeneratedPosition *,5> *)this,
                          newsize: granularity) != 0 )
  {
LABEL_11:
    size = this->eventQueue.size;
    if ( this->eventQueue.num != size )
      goto LABEL_20;
    if ( forceIdListsToReallocateEveryAppend )
    {
      v12 = (unsigned __int8)idList<idNavSpline *,5>::Resize(
                               (idList<idSpawnArea::GeneratedPosition *,5> *)this,
                               newsize: size + 1) == 0;
    }
    else
    {
      v13 = this->eventQueue.granularity;
      if ( this->eventQueue.granularity != 0 )
      {
        v15 = size + v13;
        __twllei(v13, 0);
        __twlgei(v13 & ~(__ROL4__(v15, 1) - 1), 0xFFFFFFFF);
        v12 = (unsigned __int8)idList<idNavSpline *,5>::Resize(
                                 (idList<idSpawnArea::GeneratedPosition *,5> *)this,
                                 newsize: v15 - v15 % v13) == 0;
      }
      else
      {
        v14 = 2 * size;
        if ( 2 * size == 0 )
          v14 = 1;
        v12 = (unsigned __int8)idList<idNavSpline *,5>::Resize(
                                 (idList<idSpawnArea::GeneratedPosition *,5> *)this,
                                 newsize: v14) == 0;
      }
    }
    if ( !v12 )
    {
LABEL_20:
      if ( num >= 0 )
      {
        if ( num > this->eventQueue.num )
          num = this->eventQueue.num;
      }
      else
      {
        num = 0;
      }
      v16 = this->eventQueue.num;
      if ( v16 < this->eventQueue.size )
      {
        if ( v16 > num )
        {
          v18 = v16 - num;
          v17 = v16;
          do
          {
            v19 = &this->eventQueue.list[v17--];
            *v19 = *(v19 - 1);
            --v18;
          }
          while ( v18 != 0 );
        }
        ++this->eventQueue.num;
      }
      this->eventQueue.list[num] = ev;
    }
  }
  if ( gameLocal != nullptr && gameLocal->gamestate == GAMESTATE_ACTIVE )
  {
    v20 = this->eventQueue.num;
    if ( v20 > 128 && g_debugEventQueue.valueInteger != 0 && v20 > g_debugEventQueue.valueInteger )
      idLib::Warning(fmt: "idEventSystem's eventQueue has %d events", v20);
  }
}


// ========================================================================
// ?ServiceEvents@idEventSystem@@QAAXXZ
// EA  : 0x82D622A0
// RVA : 0x00D622A0
// PDB : w:\tech5\tungsten\game\gamesys\eventsystem.cpp
// ========================================================================

void __fastcall idEventSystem::ServiceEvents(idEventSystem *this)
{
  idEvent *v2; // r26
  const char *Classname; // r3
  int v4; // r23
  const char *v5; // r28
  idPLog::logEntry_t *v6; // r29
  __int64 v7; // r3
  int v8; // r25
  const char *v9; // r28
  idPLog::logEntry_t *v10; // r29
  __int64 v11; // r3
  int num; // r8
  int v13; // r11
  int v14; // r10
  int v15; // r10
  idEvent **v16; // r9
  char *v17; // r28
  int v18; // r27
  idThread *v19; // r3
  idInterpreter *p_interpreter; // r29
  int v21; // r29
  unsigned __int64 v22; // r4
  double v23; // fp31
  const idEventDef *eventdef; // r11
  idThread *object; // r3
  idThread *v26; // r3
  int value; // r9
  idThread *v28; // r29
  idEntity *v29; // r3
  const char *v30; // r4
  idInterpreter *v31; // r29
  int v32; // r28
  const char *v33; // r4
  const char *name; // r29
  idPLog::logEntry_t *v35; // r29
  int v36; // r3
  int parent; // r11
  __int64 v38; // r9
  idPLog::logEntry_t *v39; // r29
  int v40; // r3
  int v41; // r11
  __int64 v42; // r9
  int v43; // [sp+50h] [-F0h]
  idEventReceiver v44[2]; // [sp+80h] [-C0h] BYREF

  v43 = 0;
  while ( this->eventQueue.num > 0 )
  {
    v2 = *this->eventQueue.list;
    if ( v2->time > idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
      break;
    Classname = idClass::GetClassname(this: v2->object);
    RD_EventBegin(name: Classname);
    v4 = -1;
    v5 = idClass::GetClassname(this: v2->object);
    if ( (pLog.groupMask & 2) != 0 )
    {
      idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
      idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
        this: &pLog.logEntries,
        newSize: pLog.logEntries.num + 1);
      if ( pLog.logEntries.num >= pLog.logEntries.size )
        v6 = &pLog.logEntries.list[pLog.logEntries.size - 1];
      else
        v6 = &pLog.logEntries.list[pLog.logEntries.num++];
      idMem::PopHeap(this: &mem);
      v6->label = v5;
      v6->parent = pLog.lastEntry;
      v4 = pLog.logEntries.num - 1;
      pLog.lastEntry = pLog.logEntries.num - 1;
      LODWORD(v7) = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v6->totalTicks = v7;
    }
    RD_EventBegin(name: v2->eventdef->name);
    v8 = -1;
    v9 = *(const char **)HIDWORD(pLog.groupMask);
    if ( (pLog.groupMask & 2) != 0 )
    {
      idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
      idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
        this: &pLog.logEntries,
        newSize: pLog.logEntries.num + 1);
      if ( pLog.logEntries.num >= pLog.logEntries.size )
        v10 = &pLog.logEntries.list[pLog.logEntries.size - 1];
      else
        v10 = &pLog.logEntries.list[pLog.logEntries.num++];
      idMem::PopHeap(this: &mem);
      v10->label = v9;
      v10->parent = pLog.lastEntry;
      v8 = pLog.logEntries.num - 1;
      pLog.lastEntry = pLog.logEntries.num - 1;
      LODWORD(v11) = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v10->totalTicks = v11;
    }
    num = this->eventQueue.num;
    v13 = 0;
    if ( num > 0 )
    {
      v14 = 0;
      while ( this->eventQueue.list[v14] != v2 )
      {
        ++v13;
        ++v14;
        if ( v13 >= this->eventQueue.num )
          goto LABEL_23;
      }
      if ( v13 >= 0 && v13 < num )
      {
        this->eventQueue.num = num - 1;
        if ( v13 < num - 1 )
        {
          v15 = v13;
          do
          {
            ++v13;
            v16 = &this->eventQueue.list[v15++];
            *v16 = v16[1];
          }
          while ( v13 < this->eventQueue.num );
        }
      }
    }
LABEL_23:
    v17 = &byte_8200D768;
    v18 = -1;
    if ( v2->eventdef->eventnum == EV_Execute.eventnum )
    {
      v19 = idThread::CastTo(c: (idThread *)v2->object);
      if ( v19 != nullptr )
      {
        p_interpreter = &v19->interpreter;
        v18 = idInterpreter::CurrentLine(this: &v19->interpreter);
        v17 = (char *)idInterpreter::CurrentFile(this: p_interpreter);
      }
    }
    v21 = Sys_Microseconds() >> 32;
    idEventReceiver::ProcessEventArgPtr(this: v44, result: v2->object, ev: v2->eventdef, args: (idAICover *)v2->args);
    v22 = Sys_Microseconds();
    v23 = (float)((float)_u64tod(a1: HIDWORD(v22) - v21, a2: v22) * (float)0.001);
    if ( g_showEventTimes.valueInteger != 0 && v23 > g_eventTimeThreshold.valueFloat )
    {
      eventdef = v2->eventdef;
      object = (idThread *)v2->object;
      if ( eventdef->eventnum == EV_Execute.eventnum )
      {
        v26 = idThread::CastTo(c: object);
        value = v26->threadEntity.spawnId.value;
        v28 = v26;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v29 = gameLocal->entities.ptr[value & 0x1FFF];
          if ( v29 != nullptr )
            idEntity::CastTo(c: v29);
        }
        idLib::Printf(
          fmt: "Script Thread '%s : %s' took %.2f ms\n",
          v28->threadName.data,
          (const char *)HIDWORD(v23),
          v23);
        v30 = v17;
        if ( v17 == nullptr )
          v30 = "<NULL>";
        idLib::Printf(fmt: "start - %s, line : %d\n", v30, v18);
        v31 = &v28->interpreter;
        v32 = idInterpreter::CurrentLine(this: v31);
        v33 = idInterpreter::CurrentFile(this: v31);
        if ( v33 == nullptr )
          v33 = "<NULL>";
        idLib::Printf(fmt: "end - %s, line : %d\n", v33, v32);
      }
      else
      {
        name = eventdef->name;
        idClass::GetClassname(this: object);
        idLib::Printf(fmt: "Event '%s : %s' took %.2f ms\n", name, v23, v23);
      }
    }
    idEventSystem::Free(this, ev: v2);
    if ( ++v43 > 4096 )
    {
      idLib::Error(fmt: "Event overflow.  Possible infinite loop in script.");
      _LN164();
      return;
    }
    if ( v8 >= 0 )
    {
      v35 = &pLog.logEntries.list[v8];
      v36 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      parent = v35->parent;
      LODWORD(v38) = v36 - LODWORD(v35->totalTicks);
      v35->totalTicks = v38;
      pLog.lastEntry = parent;
    }
    RD_EventEnd();
    if ( v4 >= 0 )
    {
      v39 = &pLog.logEntries.list[v4];
      v40 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v41 = v39->parent;
      LODWORD(v42) = v40 - LODWORD(v39->totalTicks);
      v39->totalTicks = v42;
      pLog.lastEntry = v41;
    }
    RD_EventEnd();
  }
}


// ========================================================================
// $LN164
// EA  : 0x82D627B0
// RVA : 0x00D627B0
// PDB : w:\tech5\tungsten\game\gamesys\eventsystem.cpp
// ========================================================================

void _LN164()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 320 + 148));
}


// ========================================================================
// __unwind$488551
// EA  : 0x82D627D8
// RVA : 0x00D627D8
// PDB : w:\tech5\tungsten\game\gamesys\eventsystem.cpp
// ========================================================================

void _unwind_488551()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 320 + 112));
}


// ========================================================================
// __unwind$488552
// EA  : 0x82D62800
// RVA : 0x00D62800
// PDB : w:\tech5\tungsten\game\gamesys\eventsystem.cpp
// ========================================================================

void _unwind_488552()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 320 + 149));
}


// ========================================================================
// __unwind$488553
// EA  : 0x82D62828
// RVA : 0x00D62828
// PDB : w:\tech5\tungsten\game\gamesys\eventsystem.cpp
// ========================================================================

void _unwind_488553()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 320 + 104));
}


// ========================================================================
// `dynamic initializer for 'g_showEventTimes''
// EA  : 0x83380668
// RVA : 0x01380668
// PDB : w:\tech5\tungsten\game\gamesys\eventsystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showEventTimes__()
{
  idCVar::idCVar(
    this: &g_showEventTimes,
    name: "g_showEventTimes",
    value: "0",
    flags: 1,
    description: "1 = show execution times for game events",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showEventTimes__);
}


// ========================================================================
// `dynamic initializer for 'g_eventTimeThreshold''
// EA  : 0x833806C0
// RVA : 0x013806C0
// PDB : w:\tech5\tungsten\game\gamesys\eventsystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_eventTimeThreshold__()
{
  idCVar::idCVar(
    this: &g_eventTimeThreshold,
    name: "g_eventTimeThreshold",
    value: "1",
    flags: 4,
    description: "only show times for events that exceed this",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_eventTimeThreshold__);
}


// ========================================================================
// `dynamic initializer for 'g_debugEventQueue''
// EA  : 0x83380718
// RVA : 0x01380718
// PDB : w:\tech5\tungsten\game\gamesys\eventsystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugEventQueue__()
{
  idCVar::idCVar(
    this: &g_debugEventQueue,
    name: "g_debugEventQueue",
    value: "0",
    flags: 2,
    description: "prints a message if event queue num exceeds this amount",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugEventQueue__);
}

