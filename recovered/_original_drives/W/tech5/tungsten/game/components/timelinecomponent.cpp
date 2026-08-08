
// ========================================================================
// ?GetRelativeTime@idComponentTimeLine@@MBAHH@Z
// EA  : 0x82BB84D0
// RVA : 0x00BB84D0
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

int __fastcall idComponentTimeLine::GetRelativeTime(idComponentTimeLine *this, const int timelineIndex)
{
  return gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->startTime;
}


// ========================================================================
// ?ProcessTimelineEvent@idComponentTimeLine@@MBAXPAVidEntity@@ABVidEventDef@@QBVidEventArg@@@Z
// EA  : 0x82BB8578
// RVA : 0x00BB8578
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void __fastcall idComponentTimeLine::ProcessTimelineEvent(
        idComponentTimeLine *this,
        idEventArg *entity,
        const idEventDef *event,
        const idEventArg *args)
{
  idEventReceiver v4[2]; // [sp+50h] [-20h] BYREF

  idEventReceiver::ProcessEventArgArray(this: v4, result: entity, ev: event, numargs: event->numargs, args);
}


// ========================================================================
// ?IsTimelineComplete@idComponentTimeLine@@MBA_NH@Z
// EA  : 0x82BB85A8
// RVA : 0x00BB85A8
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

int __fastcall idComponentTimeLine::IsTimelineComplete(idComponentTimeLine *this, const int timelineIndex)
{
  idComponentTimeLine::idTimeLineEntity *list; // r10
  int *v3; // r9
  int result; // r3

  if ( this->startTime == -1 )
    return 1;
  list = this->entityEvents.list;
  v3 = this->nextEventIndices.list;
  result = 0;
  if ( v3[timelineIndex] >= list[timelineIndex].events.num )
    return 1;
  return result;
}


// ========================================================================
// ?ProcessTimelineEvent@idComponentActionScript@@MBAXPAVidEntity@@ABVidEventDef@@QBVidEventArg@@@Z
// EA  : 0x82BB85F0
// RVA : 0x00BB85F0
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void __fastcall idComponentActionScript::ProcessTimelineEvent(
        idComponentActionScript *this,
        idAI2 *entity,
        const idEventDef *event,
        const idEventArg *args)
{
  idAI2 *v8; // r3
  idAIActionManager *p_actionManager; // r30
  int v10; // r28
  char *data; // r31
  const char *Classname; // r3
  idEventReceiver v13[6]; // [sp+50h] [-50h] BYREF

  if ( event->type == EVENT_ACTION )
  {
    v8 = idAI2::CastTo(c: entity);
    if ( v8 != nullptr )
    {
      p_actionManager = &v8->aiVolatile.fsms.actionManager;
      v8->aiVolatile.fsms.actionManager.actionEventTransCode = 0;
      idEventReceiver::ProcessEventArgArray(
        this: v13,
        result: (idEventArg *)&v8->aiVolatile.fsms.actionManager,
        ev: event,
        numargs: event->numargs,
        args);
      v10 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      if ( ai_debugActionScript.valueInteger > 0 )
        idLib::Printf(fmt: "(%d) Action: %s\n", v10 - this->startTime, event->name);
      if ( (unsigned __int8)idAIActionManager::GetActionBlocks(this: p_actionManager, actionEvent: event) != 0 )
      {
        if ( ai_debugActionScript.valueInteger > 1 )
          idLib::Printf(fmt: "(%d) Action blocking...\n", v10 - this->startTime);
      }
      else
      {
        idFiniteStateMachine::ForceUpdate(this: &p_actionManager->legsFSM);
        idFiniteStateMachine::Update(this: &p_actionManager->legsFSM, evaluate: true, curTime: v10, info: nullptr);
        if ( (unsigned __int8)idFiniteStateMachine::HadError(this: &p_actionManager->legsFSM) != 0 )
        {
          data = entity->name.data;
          Classname = idClass::GetClassname(this: &p_actionManager->legsFSM.prevState->idEventReceiver);
          idLib::Warning(fmt: "Action '%s' in action script failed for '%s'.", Classname, data);
        }
      }
    }
    else
    {
      idLib::Warning(fmt: "idComponentActionScript references entity '%s' that is not idAI2", entity->name.data);
    }
  }
  else
  {
    idEventReceiver::ProcessEventArgArray(
      this: v13,
      result: (idEventArg *)entity,
      ev: event,
      numargs: event->numargs,
      args);
  }
}


// ========================================================================
// ??0idTimeLineEvent@idComponentTimeLine@@QAA@XZ
// EA  : 0x82BB8AE0
// RVA : 0x00BB8AE0
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

idComponentTimeLine::idTimeLineEvent *__fastcall idComponentTimeLine::idTimeLineEvent::idTimeLineEvent(
        idComponentTimeLine::idTimeLineEvent *this)
{
  this->eventTime = 0;
  this->eventCall.eventDef.value = -1;
  this->eventCall.args[0].type = 0;
  this->eventCall.args[0].value.i = 0;
  this->eventCall.args[1].type = 0;
  this->eventCall.args[1].value.i = 0;
  this->eventCall.args[2].type = 0;
  this->eventCall.args[2].value.i = 0;
  this->eventCall.args[3].type = 0;
  this->eventCall.args[3].value.i = 0;
  this->eventCall.args[4].type = 0;
  this->eventCall.args[4].value.i = 0;
  this->eventCall.args[5].type = 0;
  this->eventCall.args[5].value.i = 0;
  this->eventCall.args[6].type = 0;
  this->eventCall.args[6].value.i = 0;
  this->eventCall.args[7].type = 0;
  this->eventCall.args[7].value.i = 0;
  return this;
}


// ========================================================================
// ?Update@idComponentTimeLine@@QAAXXZ
// EA  : 0x82BB8B48
// RVA : 0x00BB8B48
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void __fastcall idComponentTimeLine::Update(idComponentTimeLine *this)
{
  char v2; // r23
  int v3; // r26
  int v4; // r29
  int v5; // r25
  idComponentTimeLine::idTimeLineEntity *v6; // r28
  idEntity *v7; // r3
  idEntity *v8; // r27
  int v9; // r3
  idComponentTimeLine::idTimeLineEvent *v10; // r30
  const idEventDef *EventCommand; // r5

  if ( this->startTime != -1 )
  {
    v2 = 1;
    v3 = 0;
    if ( this->entityEvents.num > 0 )
    {
      v4 = 0;
      v5 = 0;
      do
      {
        v6 = &this->entityEvents.list[v5];
        if ( gameLocal->spawnIds.ptr[v6->entity.spawnId.value & 0x1FFF] == v6->entity.spawnId.value >> 13 )
        {
          v7 = gameLocal->entities.ptr[v6->entity.spawnId.value & 0x1FFF];
          if ( v7 != nullptr )
          {
            v8 = idEntity::CastTo(c: v7);
            if ( v8 != nullptr )
            {
              for ( ; this->nextEventIndices.list[v4] < v6->events.num; ++this->nextEventIndices.list[v4] )
              {
                v9 = this->GetRelativeTime(this, a2: v3);
                if ( v9 == -1 )
                  break;
                v10 = &v6->events.list[this->nextEventIndices.list[v4]];
                if ( v10->eventTime > v9 )
                  break;
                EventCommand = idEventDef::GetEventCommand(eventnum: v10->eventCall.eventDef.value);
                if ( EventCommand != nullptr )
                  this->ProcessTimelineEvent(this, a2: v8, a3: EventCommand, a4: v10->eventCall.args);
              }
              if ( this->IsTimelineComplete(this, a2: v3) )
                this->OnTimelineCompletion(this, a2: v3);
              else
                v2 = 0;
            }
          }
        }
        ++v3;
        ++v5;
        ++v4;
      }
      while ( v3 < this->entityEvents.num );
    }
    if ( v2 != 0 )
      this->startTime = -1;
  }
}


// ========================================================================
// ?GetRelativeTime@idComponentActionScript@@MBAHH@Z
// EA  : 0x82BB8D00
// RVA : 0x00BB8D00
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

int __fastcall idComponentActionScript::GetRelativeTime(idComponentActionScript *this, int timelineIndex)
{
  int v3; // r29
  int value; // r8
  idEntity *v6; // r3
  idAI2 *v7; // r3
  idAI2 *v8; // r3

  v3 = timelineIndex;
  value = this->entityEvents.list[timelineIndex].entity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = gameLocal->entities.ptr[this->entityEvents.list[timelineIndex].entity.spawnId.value & 0x1FFF]) != nullptr )
  {
    v7 = (idAI2 *)idEntity::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  v8 = idAI2::CastTo(c: v7);
  if ( v8 == nullptr || idAI2::GetActionStatus(this: v8) == FSMSTATUS_WORKING )
    return -1;
  else
    return this->entityEvents.list[v3].events.list[this->nextEventIndices.list[timelineIndex]].eventTime;
}


// ========================================================================
// ?ResetTimeline@idComponentActionScript@@MAAXH@Z
// EA  : 0x82BB8DB8
// RVA : 0x00BB8DB8
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void __fastcall idComponentActionScript::ResetTimeline(idComponentActionScript *this, const int timelineIndex)
{
  int value; // r9
  idEntity *v3; // r3
  idAI2 *v4; // r3
  idAI2 *v5; // r3
  idFiniteStateMachine *p_legsFSM; // r31
  int v7; // r3

  value = this->entityEvents.list[timelineIndex].entity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = gameLocal->entities.ptr[this->entityEvents.list[timelineIndex].entity.spawnId.value & 0x1FFF]) != nullptr )
  {
    v4 = (idAI2 *)idEntity::CastTo(c: v3);
  }
  else
  {
    v4 = nullptr;
  }
  v5 = idAI2::CastTo(c: v4);
  if ( v5 != nullptr )
  {
    p_legsFSM = &v5->aiVolatile.fsms.actionManager.legsFSM;
    v7 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idFiniteStateMachine::Restart(this: p_legsFSM, curTime: v7);
    idFiniteStateMachine::ForceUpdate(this: p_legsFSM);
  }
}


// ========================================================================
// ?IsTimelineComplete@idComponentActionScript@@MBA_NH@Z
// EA  : 0x82BB8E78
// RVA : 0x00BB8E78
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

int __fastcall idComponentActionScript::IsTimelineComplete(idComponentActionScript *this, const int timelineIndex)
{
  idComponentTimeLine::idTimeLineEntity *v4; // r3
  int num; // r11
  idAI2 *v6; // r3
  idAI2 *v7; // r3

  if ( this->startTime != -1 )
  {
    v4 = &this->entityEvents.list[timelineIndex];
    num = v4->events.num;
    if ( num != 0 )
    {
      if ( this->nextEventIndices.list[timelineIndex] < num )
        return 0;
      v6 = (idAI2 *)idEntityPtr<idEntity const>::operator->(this: &v4->entity);
      v7 = idAI2::CastTo(c: v6);
      if ( v7 != nullptr )
        return -1 - ((idAI2::GetActionStatus(this: v7) == FSMSTATUS_WORKING) - 2);
    }
  }
  return 1;
}


// ========================================================================
// ?OnTimelineCompletion@idComponentActionScript@@MBAXH@Z
// EA  : 0x82BB8F20
// RVA : 0x00BB8F20
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void __fastcall idComponentActionScript::OnTimelineCompletion(idComponentActionScript *this, const int timelineIndex)
{
  int value; // r9
  idEntity *v3; // r3
  idAI2 *v4; // r3
  idAI2 *v5; // r30
  int v6; // r3

  value = this->entityEvents.list[timelineIndex].entity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = gameLocal->entities.ptr[this->entityEvents.list[timelineIndex].entity.spawnId.value & 0x1FFF]) != nullptr )
  {
    v4 = (idAI2 *)idEntity::CastTo(c: v3);
  }
  else
  {
    v4 = nullptr;
  }
  v5 = idAI2::CastTo(c: v4);
  if ( v5 != nullptr )
  {
    v6 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idAI2::OnActionScriptFinished(this: v5, curTime: v6);
  }
}


// ========================================================================
// ??0idTimeLineEntity@idComponentTimeLine@@QAA@XZ
// EA  : 0x82BB9010
// RVA : 0x00BB9010
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

idComponentTimeLine::idTimeLineEntity *__fastcall idComponentTimeLine::idTimeLineEntity::idTimeLineEntity(
        idComponentTimeLine::idTimeLineEntity *this)
{
  this->entity.spawnId.value = 0x1FFF;
  this->events.list = nullptr;
  this->events.granularity = 0;
  this->events.memTag = 5;
  this->events.listStatic = 0;
  this->events.size = 0;
  this->events.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->events);
  return this;
}


// ========================================================================
// ?Init@idComponentTimeLine@@QAAXXZ
// EA  : 0x82BB9078
// RVA : 0x00BB9078
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void __fastcall idComponentTimeLine::Init(idComponentTimeLine *this)
{
  int v2; // r6
  __int64 v3; // r10
  __int64 v4; // r8
  int v5; // r22
  int v6; // r24
  idComponentTimeLine::idTimeLineEntity *v7; // r28
  idComponentTimeLine::idTimeLineEvent *list; // r4
  unsigned int num; // r5
  idEntity *v10; // r3
  int v11; // r25
  int v12; // r26
  idComponentTimeLine::idTimeLineEvent *v13; // r30
  const idEventDef *EventCommand; // r29
  int v15; // r11
  idEntity *v16; // r3
  idEntity *v17; // r3
  idEntity *v18; // r3
  const char *name; // r30
  idEntity *v20; // r3
  idEntity *v21; // r11
  idSort_Quick<idComponentTimeLine::idTimeLineEvent,idSort_TimeLineEvent> v22; // [sp+50h] [-90h] BYREF
  idComponentTimeLine::idTimeLineEvent *v23; // [sp+54h] [-8Ch] BYREF

  if ( this->startTime != -1 )
    this->startTime = -1;
  v2 = 0;
  if ( this->entityEvents.num > 0 )
  {
    HIDWORD(v3) = &unk_822C0000;
    LODWORD(v4) = &unk_822C0000;
    HIDWORD(v4) = &unk_822C0000;
    v5 = 0;
    do
    {
      v6 = v2 + 1;
      LODWORD(v3) = this->nextEventIndices.num;
      v7 = &this->entityEvents.list[v5];
      if ( (int)v3 < v2 + 1 )
      {
        v23 = nullptr;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->nextEventIndices,
          obj: (encounterGroupRole_t *)&v23);
      }
      v22.__vftable = (idSort_Quick<idComponentTimeLine::idTimeLineEvent,idSort_TimeLineEvent>_vtbl *)&idSort_TimeLineEvent::`vftable';
      list = v7->events.list;
      if ( list != nullptr )
      {
        num = v7->events.num;
        v23 = v7->events.list;
        idSort_Quick<idComponentTimeLine::idTimeLineEvent,idSort_TimeLineEvent>::Sort(
          this: &v22,
          base: list,
          num,
          a4: v2,
          a5: v4,
          a6: v3);
      }
      v22.__vftable = (idSort_Quick<idComponentTimeLine::idTimeLineEvent,idSort_TimeLineEvent>_vtbl *)&idSort<idComponentTimeLine::idTimeLineEvent>::`vftable';
      if ( gameLocal->spawnIds.ptr[v7->entity.spawnId.value & 0x1FFF] != v7->entity.spawnId.value >> 13
        || (v10 = gameLocal->entities.ptr[v7->entity.spawnId.value & 0x1FFF]) == nullptr
        || idEntity::CastTo(c: v10) == nullptr )
      {
        idLib::Warning(fmt: "idComponentTimeLine references bad entity");
      }
      v11 = 0;
      if ( v7->events.num > 0 )
      {
        v12 = 0;
        do
        {
          v13 = &v7->events.list[v12];
          EventCommand = idEventDef::GetEventCommand(eventnum: v13->eventCall.eventDef.value);
          if ( EventCommand != nullptr )
          {
            HIDWORD(v3) = gameLocal;
            LODWORD(v4) = v7->entity.spawnId.value >> 13;
            HIDWORD(v4) = (v7->entity.spawnId.value & 0x1FFF) + 29755;
            if ( *((_DWORD *)&gameLocal->__vftable + HIDWORD(v4)) == (_DWORD)v4 )
            {
              v15 = (v7->entity.spawnId.value & 0x1FFF) + 21563;
              v16 = *((idEntity **)&gameLocal->__vftable + v15);
              HIDWORD(v3) = 4 * v15;
              if ( v16 != nullptr && idEntity::CastTo(c: v16) != nullptr )
              {
                if ( gameLocal->spawnIds.ptr[v7->entity.spawnId.value & 0x1FFF] == v7->entity.spawnId.value >> 13
                  && (v17 = gameLocal->entities.ptr[v7->entity.spawnId.value & 0x1FFF]) != nullptr )
                {
                  v18 = idEntity::CastTo(c: v17);
                }
                else
                {
                  v18 = nullptr;
                }
                HIDWORD(v3) = v18->RespondsTo(this: v18, a2: EventCommand);
                if ( HIDWORD(v3) == 0 )
                {
                  name = EventCommand->name;
                  if ( gameLocal->spawnIds.ptr[v7->entity.spawnId.value & 0x1FFF] == v7->entity.spawnId.value >> 13
                    && (v20 = gameLocal->entities.ptr[v7->entity.spawnId.value & 0x1FFF]) != nullptr )
                  {
                    v21 = idEntity::CastTo(c: v20);
                  }
                  else
                  {
                    v21 = nullptr;
                  }
                  idLib::Warning(
                    fmt: "idComponentTimeLine references entity '%s' that doesn't respond to event '%s'",
                    v21->name.data,
                    name);
                }
              }
            }
          }
          else
          {
            idLib::Warning(fmt: "idComponentTimeLine references bad event '%d'", v13->eventCall.eventDef.value);
          }
          ++v11;
          ++v12;
        }
        while ( v11 < v7->events.num );
      }
      v2 = v6;
      ++v5;
    }
    while ( v6 < this->entityEvents.num );
  }
}


// ========================================================================
// __unwind$490028_0
// EA  : 0x82BB9308
// RVA : 0x00BB9308
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_490028_0()
{
  int v0; // r12

  idSort_TimeLineEvent::~idSort_TimeLineEvent(this: (idSort_TimeLineEvent *)(v0 - 224 + 80));
}


// ========================================================================
// ?Start@idComponentTimeLine@@QAAXXZ
// EA  : 0x82BB9330
// RVA : 0x00BB9330
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void __fastcall idComponentTimeLine::Start(idComponentTimeLine *this)
{
  int v2; // r30
  int v3; // [sp+50h] [-30h] BYREF

  if ( this->startTime == -1 )
  {
    this->startTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nextEventIndices);
    v2 = 0;
    if ( this->entityEvents.num > 0 )
    {
      v3 = 0;
      do
      {
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->nextEventIndices,
          obj: (encounterGroupRole_t *)&v3);
        this->ResetTimeline(this, a2: v2++);
      }
      while ( v2 < this->entityEvents.num );
    }
    idComponentTimeLine::Update(this);
  }
}


// ========================================================================
// ?GetTimelineIndex@idComponentActionScript@@ABA?BHPBVidEntity@@@Z
// EA  : 0x82BB93D0
// RVA : 0x00BB93D0
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

int __fastcall idComponentActionScript::GetTimelineIndex(idComponentActionScript *this, const idEntity *entity)
{
  idGameLocal *v3; // r10
  int v4; // r11
  int v5; // r26
  int v6; // r27
  int v7; // r25
  int i; // r30
  int value; // r9
  idEntity *v10; // r3
  idEntity *v11; // r3
  idEntity *v12; // r31
  idEntity *v13; // r3
  idEntity *v14; // r3

  v3 = gameLocal;
  if ( entity != nullptr )
    v4 = (gameLocal->spawnIds.ptr[entity->entityNumber] << 13) | entity->entityNumber;
  else
    v4 = 0x1FFF;
  v5 = 0;
  if ( this->entityEvents.num <= 0 )
    return -1;
  v6 = v4 & 0x1FFF;
  v7 = v4 >> 13;
  for ( i = 0; ; ++i )
  {
    value = this->entityEvents.list[i].entity.spawnId.value;
    if ( v3->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v10 = v3->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v11 = idEntity::CastTo(c: v10);
      v3 = gameLocal;
      v12 = v11;
    }
    else
    {
      v12 = nullptr;
    }
    if ( v3->spawnIds.ptr[v6] == v7 && (v13 = v3->entities.ptr[v6]) != nullptr )
    {
      v14 = idEntity::CastTo(c: v13);
      v3 = gameLocal;
    }
    else
    {
      v14 = nullptr;
    }
    if ( v12 == v14 )
      break;
    if ( ++v5 >= this->entityEvents.num )
      return -1;
  }
  return v5;
}


// ========================================================================
// ?RunningActionScript@idComponentActionScript@@QBA_NPBVidEntity@@@Z
// EA  : 0x82BB94E8
// RVA : 0x00BB94E8
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

BOOL __fastcall idComponentActionScript::RunningActionScript(idComponentActionScript *this, const idEntity *entity)
{
  int TimelineIndex; // r4

  TimelineIndex = idComponentActionScript::GetTimelineIndex(this, entity);
  return TimelineIndex >= 0 && (_cntlzw(this->IsTimelineComplete(this, a2: TimelineIndex)) & 0x20) != 0;
}


// ========================================================================
// ?ClearActionScript@idComponentActionScript@@QAAXPBVidEntity@@@Z
// EA  : 0x82BB9558
// RVA : 0x00BB9558
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void __fastcall idComponentActionScript::ClearActionScript(idComponentActionScript *this, const idEntity *entity)
{
  int TimelineIndex; // r3
  int v4; // r31

  this->startTime = -1;
  TimelineIndex = idComponentActionScript::GetTimelineIndex(this, entity);
  v4 = TimelineIndex;
  if ( TimelineIndex >= 0 )
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->entityEvents.list[TimelineIndex].events);
    this->nextEventIndices.list[v4] = 0;
  }
}


// ========================================================================
// ?NumScriptActions@idComponentActionScript@@QBAHPBVidEntity@@@Z
// EA  : 0x82BB95D0
// RVA : 0x00BB95D0
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

int __fastcall idComponentActionScript::NumScriptActions(idComponentActionScript *this, const idEntity *entity)
{
  int TimelineIndex; // r3

  TimelineIndex = idComponentActionScript::GetTimelineIndex(this, entity);
  if ( TimelineIndex >= 0 )
    return this->entityEvents.list[TimelineIndex].events.num;
  else
    return 0;
}


// ========================================================================
// ??0idComponentTimeLine@@QAA@XZ
// EA  : 0x82BB9960
// RVA : 0x00BB9960
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

idComponentTimeLine *__fastcall idComponentTimeLine::idComponentTimeLine(idComponentTimeLine *this)
{
  this->__vftable = (idComponentTimeLine_vtbl *)&idComponentTimeLine::`vftable';
  this->entityEvents.granularity = 0;
  this->entityEvents.memTag = 5;
  this->entityEvents.listStatic = 0;
  this->entityEvents.list = nullptr;
  this->entityEvents.size = 0;
  this->entityEvents.num = 0;
  this->nextEventIndices.list = nullptr;
  this->nextEventIndices.granularity = 0;
  this->nextEventIndices.memTag = 5;
  this->nextEventIndices.listStatic = 0;
  this->nextEventIndices.size = 0;
  this->nextEventIndices.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nextEventIndices);
  this->startTime = -1;
  return this;
}


// ========================================================================
// __unwind$490912
// EA  : 0x82BB99F8
// RVA : 0x00BB99F8
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_490912()
{
  int v0; // r12

  idList<idComponentTimeLine::idTimeLineEntity,5>::~idList<idComponentTimeLine::idTimeLineEntity,5>(this: (idList<idVOChainState,5> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ??1idComponentTimeLine@@UAA@XZ
// EA  : 0x82BB9A30
// RVA : 0x00BB9A30
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void __fastcall idComponentTimeLine::~idComponentTimeLine(idComponentTimeLine *this)
{
  char *list; // r3

  this->__vftable = (idComponentTimeLine_vtbl *)&idComponentTimeLine::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nextEventIndices);
  if ( this->entityEvents.listStatic == 0 || this->entityEvents.listStatic == 2 )
  {
    list = (char *)this->entityEvents.list;
    if ( list != nullptr )
      idListArrayDelete<idStateData::transition_t>(ptr: list, num: this->entityEvents.size);
    this->entityEvents.list = nullptr;
    this->entityEvents.size = 0;
  }
  this->entityEvents.num = 0;
}


// ========================================================================
// __unwind$490950_2
// EA  : 0x82BB9ABC
// RVA : 0x00BB9ABC
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_490950_2()
{
  int v0; // r12

  idList<idComponentTimeLine::idTimeLineEntity,5>::~idList<idComponentTimeLine::idTimeLineEntity,5>(this: (idList<idVOChainState,5> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ??0idComponentActionScript@@QAA@XZ
// EA  : 0x82BB9AE8
// RVA : 0x00BB9AE8
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

idComponentActionScript *__fastcall idComponentActionScript::idComponentActionScript(idComponentActionScript *this)
{
  idComponentTimeLine::idComponentTimeLine(this);
  this->__vftable = (idComponentActionScript_vtbl *)&idComponentActionScript::`vftable';
  return this;
}


// ========================================================================
// ??1idComponentActionScript@@UAA@XZ
// EA  : 0x82BB9B28
// RVA : 0x00BB9B28
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void __fastcall idComponentActionScript::~idComponentActionScript(idComponentActionScript *this)
{
  this->__vftable = (idComponentActionScript_vtbl *)&idComponentActionScript::`vftable';
  idComponentTimeLine::~idComponentTimeLine(this);
}


// ========================================================================
// ?SetActionScript@idComponentActionScript@@QAAXPAVidEntity@@ABV?$idList@VidScriptAction@@$04@@00_N@Z
// EA  : 0x82BB9C98
// RVA : 0x00BB9C98
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void __fastcall idComponentActionScript::SetActionScript(
        idComponentActionScript *this,
        idEntity *entity,
        const idList<idScriptAction,5> *script,
        idEntity *scriptExecutor,
        idEntity *activator,
        bool tool,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  idComponentTimeLine::idTimeLineEntity *list; // r9
  int num; // r11
  const char *v16; // r16
  char v17; // r25
  int v18; // r24
  idStr *ActionEventName; // r3
  const idEventDef *Event; // r26
  idScriptAction *v21; // r10
  int v22; // r27
  idScriptAction *v23; // r11
  int v24; // r21
  idAIActionParm *v25; // r29
  int intVal; // r11
  int subType; // r11
  double v28; // fp0
  double x; // fp12
  double y; // fp13
  double z; // fp12
  idEntity *v32; // r29
  const idEventArg *v33; // r4
  idComponentTimeLine::idTimeLineEntity *v34; // r11
  idList<idComponentTimeLine::idTimeLineEvent,5> *p_events; // r29
  int v36; // r11
  int size; // r10
  idComponentTimeLine::idTimeLineEvent *v38; // r10
  idComponentTimeLine::idTimeLineEvent *v39; // r11
  int v40; // r27
  idEventArgs *v41; // r29
  char *p_type; // r28
  int type; // r11
  char v44; // r11
  bool v45; // zf
  _DWORD *v46; // r11
  char *v47; // r10
  int v48; // ctr
  int *p_argsNumber; // r11
  char *v50; // r10
  int i; // ctr
  int v52; // r10
  int v53; // r9
  int v54; // r8
  int v55; // r7
  int v56; // r6
  int v57; // r5
  int v58; // r4
  int v59; // r3
  int numargs; // [sp+50h] [-7A0h]
  idEntityPtr<idEntity> v61; // [sp+54h] [-79Ch] BYREF
  int TimelineIndex; // [sp+58h] [-798h] BYREF
  idEntityPtr<idEntity> v63; // [sp+5Ch] [-794h] BYREF
  idAtomicString v64; // [sp+60h] [-790h] BYREF
  const char *v65; // [sp+64h] [-78Ch]
  const char *v66; // [sp+68h] [-788h]
  const char *v67; // [sp+6Ch] [-784h]
  const char *v68; // [sp+70h] [-780h]
  idEventDef *v69; // [sp+74h] [-77Ch]
  const char *v70; // [sp+78h] [-778h]
  idEventDef *v71; // [sp+7Ch] [-774h]
  idEventDef *v72; // [sp+80h] [-770h]
  idEventDef *v73; // [sp+84h] [-76Ch]
  BOOL v74; // [sp+88h] [-768h]
  const char *v75; // [sp+8Ch] [-764h]
  idSpawnId v76; // [sp+90h] [-760h] BYREF
  const char *v77; // [sp+94h] [-75Ch]
  const char *v78; // [sp+98h] [-758h]
  const char *v79; // [sp+9Ch] [-754h]
  idEventDef *v80; // [sp+A0h] [-750h]
  const char *v81; // [sp+A4h] [-74Ch]
  idEventDef *v82; // [sp+A8h] [-748h]
  const char *v83; // [sp+ACh] [-744h]
  idEventDef *v84; // [sp+B0h] [-740h]
  idEventDef *v85; // [sp+B4h] [-73Ch]
  const char *v86; // [sp+B8h] [-738h]
  idEventDef *v87; // [sp+BCh] [-734h]
  const char *v88; // [sp+C0h] [-730h]
  idEventDef *v89; // [sp+C4h] [-72Ch]
  const char *v90; // [sp+C8h] [-728h]
  const char *v91; // [sp+CCh] [-724h]
  idEventDef *v92; // [sp+D0h] [-720h]
  idSpawnId v93; // [sp+D4h] [-71Ch] BYREF
  const char *v94; // [sp+D8h] [-718h]
  idEventDef *v95; // [sp+DCh] [-714h]
  idStr v96; // [sp+E0h] [-710h] BYREF
  idEventArg v97; // [sp+100h] [-6F0h] BYREF
  idEventArg v98; // [sp+120h] [-6D0h] BYREF
  idStr v99; // [sp+140h] [-6B0h] BYREF
  idStr v100; // [sp+160h] [-690h] BYREF
  idStr v101; // [sp+180h] [-670h] BYREF
  idEventArg v102; // [sp+1A0h] [-650h] BYREF
  _DWORD v103[9]; // [sp+1BCh] [-634h] BYREF
  idEventArg v104; // [sp+1E0h] [-610h] BYREF
  idEventArg v105; // [sp+200h] [-5F0h] BYREF
  idEventArg v106; // [sp+220h] [-5D0h] BYREF
  idEventArg v107; // [sp+240h] [-5B0h] BYREF
  idEventArg v108; // [sp+260h] [-590h] BYREF
  idEventArg v109; // [sp+280h] [-570h] BYREF
  _DWORD v110[8]; // [sp+2A0h] [-550h] BYREF
  idEventArg v111; // [sp+2C0h] [-530h] BYREF
  _DWORD v112[8]; // [sp+2E0h] [-510h] BYREF
  idEventArg v113; // [sp+300h] [-4F0h] BYREF
  _DWORD v114[8]; // [sp+320h] [-4D0h] BYREF
  idEventArg v115; // [sp+340h] [-4B0h] BYREF
  idEventArg v116; // [sp+360h] [-490h] BYREF
  idEventArg v117; // [sp+380h] [-470h] BYREF
  idEventArg v118; // [sp+3A0h] [-450h] BYREF
  idEventArg v119; // [sp+3C0h] [-430h] BYREF
  idEventArg v120; // [sp+3E0h] [-410h] BYREF
  idEventArg v121; // [sp+400h] [-3F0h] BYREF
  idStr v122; // [sp+420h] [-3D0h] BYREF
  idStr v123; // [sp+440h] [-3B0h] BYREF
  idStr v124; // [sp+460h] [-390h] BYREF
  idStr v125; // [sp+480h] [-370h] BYREF
  idStr v126; // [sp+4A0h] [-350h] BYREF
  idStr v127; // [sp+4C0h] [-330h] BYREF
  idStr v128; // [sp+4E0h] [-310h] BYREF
  idStr v129; // [sp+500h] [-2F0h] BYREF
  idStr v130; // [sp+520h] [-2D0h] BYREF
  idStr v131; // [sp+540h] [-2B0h] BYREF
  idEventArgs v132; // [sp+560h] [-290h] BYREF
  idStr v133; // [sp+710h] [-E0h] BYREF
  idStr v134[6]; // [sp+730h] [-C0h] BYREF

  if ( this->nextEventIndices.num != this->entityEvents.num )
    return;
  v61.spawnId.value = 0x1FFF;
  if ( entity != nullptr )
  {
    v64.str = (const char *)entity->entityNumber;
    v61.spawnId.value = (*((_DWORD *)&gameLocal->__vftable + (int)(v64.str + 29755)) << 13) | (unsigned int)v64.str;
  }
  else
  {
    v61.spawnId.value = 0x1FFF;
  }
  v74 = tool;
  if ( tool )
    idGameState::SetUnresolvedEntityName(ptr: &v61, name: entity->name.data);
  TimelineIndex = idComponentActionScript::GetTimelineIndex(this, entity);
  if ( TimelineIndex < 0 )
  {
    TimelineIndex = 0;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->nextEventIndices,
      obj: (encounterGroupRole_t *)&TimelineIndex);
    idList<idComponentTimeLine::idTimeLineEntity,5>::Alloc(this: &this->entityEvents);
    list = this->entityEvents.list;
    TimelineIndex = this->entityEvents.num - 1;
    list[TimelineIndex].entity = v61;
  }
  idComponentActionScript::ClearActionScript(this, entity);
  num = script->num;
  v65 = nullptr;
  if ( num <= 0 )
    return;
  v91 = "Script action '%s' not queued";
  v69 = &ACTION_MoveToEntityNoFailEnter;
  v89 = &ACTION_SetPlayerFocusEnter;
  v87 = &ACTION_IdleEnter;
  v85 = &ACTION_StartAnimEnter;
  v83 = "Action script parameter has unknown decl sub-type.";
  v81 = "Script action event '%s' is called with decl %d parameter, but expects %s type";
  v78 = "Action script parameter has unknown string sub-type.";
  v72 = &ACTION_TriggerEnter;
  v70 = "Script action event '%s' is called with entity %d parameter, but expects %s type";
  v68 = "Script action event '%s' is called with string %d parameter, but expects %s type";
  v66 = "Action script parameter has unknown float sub-type.";
  v79 = "Script action event '%s' is called with angles %d parameter, but expects %s type";
  v88 = "Script action event '%s' is called with vec3 %d parameter, but expects %s type";
  v67 = "Script action event '%s' is called with float %d parameter, but expects %s type";
  v86 = "Action script parameter has unknown discrete sub-type.";
  v94 = "Script action event '%s' is called with integer %d parameter, but expects %s type";
  v82 = &ACTION_MoveToEntityEnter;
  v75 = "Script action event '%s' is called with enum %d parameter, but expects %s type";
  v77 = "Script action event '%s' is called with boolean %d parameter, but expects %s type";
  v90 = "Script action event '%s' is called with %d parameters, but expects %d parameters";
  v73 = &ACTION_DiveEnter;
  v84 = &ACTION_MoveToCoverEnter;
  v71 = &ACTION_MoveToPathPointNoFailEnter;
  v92 = &ACTION_MoveToPathPointEnter;
  v16 = v65;
  v80 = &ACTION_MoveToPointNoFailEnter;
  v65 = "Script action event '%s' not found. The script action was not queued.";
  v95 = &ACTION_MoveToPointEnter;
  while ( 1 )
  {
    v17 = 0;
    v18 = (int)v16;
    ActionEventName = idAIAction::GetActionEventName(result: v134, name: &script->list[(_DWORD)v16].eventName);
    Event = idEventDef::FindEvent(name: ActionEventName->data);
    idStr::FreeData(this: v134);
    if ( Event != nullptr )
      break;
    idLib::Warning(fmt: v65, script->list[v18].eventName.data);
LABEL_136:
    if ( (int)++v16 >= script->num )
      return;
  }
  idEventArgs::idEventArgs(this: &v132);
  v93.value = v61.spawnId.value;
  idEventArg::idEventArg(this: &v102, data: &v93);
  idEventArgs::AddArg(this: &v132, arg: &v102);
  if ( Event == v95
    || Event == v80
    || Event == v82
    || Event == v69
    || Event == v92
    || Event == v71
    || Event == v84
    || Event == v73 )
  {
    v111.type = 105;
    v111.value.i = 33;
    idEventArgs::AddArg(this: &v132, arg: &v111);
  }
  v21 = &script->list[v18];
  if ( v132.argsNumber + v21->parms.num != Event->numargs )
  {
    idLib::Warning(fmt: v90, v21->eventName.data);
    v17 = 1;
  }
  v22 = 0;
  v23 = &script->list[v18];
  if ( v23->parms.num <= 0 )
  {
LABEL_98:
    numargs = Event->numargs;
    if ( v132.argsNumber == numargs )
    {
LABEL_116:
      if ( v17 != 0 )
      {
        idLib::Warning(fmt: v91, script->list[v18].eventName.data);
      }
      else
      {
        v34 = &this->entityEvents.list[TimelineIndex];
        p_events = &v34->events;
        idList<idComponentTimeLine::idTimeLineEvent,5>::PreAllocateWithGranularity(
          this: &v34->events,
          newSize: v34->events.num + 1);
        v36 = p_events->num;
        size = p_events->size;
        if ( v36 >= size )
        {
          v39 = &p_events->list[size - 1];
        }
        else
        {
          v38 = p_events->list;
          p_events->num = v36 + 1;
          v39 = &v38[v36];
        }
        v39->eventTime = (unsigned __int16)v16;
        v40 = 0;
        v39->eventCall.eventDef.value = Event->eventnum;
        if ( Event->numargs > 0 )
        {
          v41 = &v132;
          p_type = &v39->eventCall.args[0].type;
          do
          {
            type = v41->args.ptr[0].type;
            if ( type == 115 || type == 49 || type == 50 || (v45 = type != 53, v44 = 0, !v45) )
              v44 = 1;
            if ( v44 != 0 )
            {
              idAtomicString::Set(this: &v64, str_: v41->args.ptr[0].value.s);
              v46 = v103;
              HIBYTE(v103[1]) = 115;
              v47 = p_type - 4;
              v48 = 5;
              v103[2] = v64.str;
              do
              {
                ++v46;
                v47 += 4;
                *(_DWORD *)v47 = *v46;
                --v48;
              }
              while ( v48 != 0 );
              *p_type = v41->args.ptr[0].type;
            }
            else
            {
              p_argsNumber = &v41[-1].argsNumber;
              v50 = p_type - 4;
              for ( i = 5; i != 0; --i )
              {
                ++p_argsNumber;
                v50 += 4;
                *(_DWORD *)v50 = *p_argsNumber;
              }
            }
            ++v40;
            v41 = (idEventArgs *)((char *)v41 + 20);
            p_type += 20;
          }
          while ( v40 < Event->numargs );
        }
      }
      `eh vector destructor iterator'(
        ptr: &v132.strings,
        size: 0x20u,
        count: 8,
        pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
      goto LABEL_136;
    }
    if ( Event == v85 )
    {
      if ( numargs - v132.argsNumber == 2 )
      {
        v116.type = 105;
        v116.value.i = 0;
        idEventArgs::AddArg(this: &v132, arg: &v116);
      }
      if ( Event->numargs - v132.argsNumber != 1 )
        goto LABEL_115;
      HIBYTE(v112[0]) = 105;
      v33 = (const idEventArg *)v112;
      v112[1] = 1;
    }
    else if ( Event == v87 )
    {
      if ( numargs - v132.argsNumber == 2 )
      {
        v120.type = 105;
        v120.value.i = -1;
        idEventArgs::AddArg(this: &v132, arg: &v120);
      }
      if ( Event->numargs - v132.argsNumber != 1 )
        goto LABEL_115;
      HIBYTE(v114[0]) = 105;
      v33 = (const idEventArg *)v114;
      v114[1] = 1;
    }
    else
    {
      if ( Event != v89 )
        goto LABEL_115;
      if ( numargs - v132.argsNumber == 2 )
      {
        v118.type = 105;
        v118.value.i = 1;
        idEventArgs::AddArg(this: &v132, arg: &v118);
      }
      if ( Event->numargs - v132.argsNumber != 1 )
        goto LABEL_115;
      HIBYTE(v110[0]) = 105;
      v33 = (const idEventArg *)v110;
      v110[1] = 1;
    }
    idEventArgs::AddArg(this: &v132, arg: v33);
LABEL_115:
    v17 = Event->numargs == v132.argsNumber ? 0 : v17;
    goto LABEL_116;
  }
  v24 = 0;
  while ( 1 )
  {
    v25 = &v23->parms.list[v24];
    if ( (unsigned int)v25->type - 1 > 3 )
      goto LABEL_97;
    if ( v25->type == 2 )
    {
      subType = v25->subType;
      switch ( subType )
      {
        case 17:
          if ( Event->formatspec[v132.argsNumber] != 102 )
          {
            idStr::idStr(this: &v131, text: &byte_8200D768);
            idEventDef::GetEventArgTypeName(eventNum: Event->eventnum, argNum: v132.argsNumber, argType: &v131);
            idLib::Warning(fmt: v67, script->list[v18].eventName.data, v22, v131.data);
            v17 = 1;
            idStr::FreeData(this: &v131);
          }
          v106.value.f = v25->floatVal.x;
          v106.type = 102;
          idEventArgs::AddArg(this: &v132, arg: &v106);
          goto LABEL_97;
        case 18:
          if ( Event->formatspec[v132.argsNumber] != 118 )
          {
            idStr::idStr(this: &v127, text: &byte_8200D768);
            idEventDef::GetEventArgTypeName(eventNum: Event->eventnum, argNum: v132.argsNumber, argType: &v127);
            idLib::Warning(fmt: v88, script->list[v18].eventName.data, v22, v127.data);
            v17 = 1;
            idStr::FreeData(this: &v127);
          }
          y = v25->floatVal.y;
          z = v25->floatVal.z;
          v97.value.f = v25->floatVal.x;
          v97.type = 118;
          v97.value.v[1] = y;
          v97.value.v[2] = z;
          idEventArgs::AddArg(this: &v132, arg: &v97);
          goto LABEL_97;
        case 19:
          if ( Event->formatspec[v132.argsNumber] != 97 )
          {
            idStr::idStr(this: &v130, text: &byte_8200D768);
            idEventDef::GetEventArgTypeName(eventNum: Event->eventnum, argNum: v132.argsNumber, argType: &v130);
            idLib::Warning(fmt: v79, script->list[v18].eventName.data, v22, v130.data);
            v17 = 1;
            idStr::FreeData(this: &v130);
          }
          v28 = v25->floatVal.z;
          x = v25->floatVal.x;
          v98.value.v[1] = v25->floatVal.y;
          v98.type = 97;
          v98.value.v[2] = v28;
          v98.value.f = x;
          idEventArgs::AddArg(this: &v132, arg: &v98);
          goto LABEL_97;
        default:
          break;
      }
      idLib::Warning(fmt: v66);
      goto LABEL_96;
    }
    if ( v25->type == 3 )
      break;
    if ( v25->type == 1 )
    {
      if ( v25->subType == 0 )
      {
        if ( Event->formatspec[v132.argsNumber] != 105 )
        {
          idStr::idStr(this: &v125, text: &byte_8200D768);
          idEventDef::GetEventArgTypeName(eventNum: Event->eventnum, argNum: v132.argsNumber, argType: &v125);
          idLib::Warning(fmt: v94, script->list[v18].eventName.data, v22, v125.data);
          v17 = 1;
          idStr::FreeData(this: &v125);
        }
        v104.value.i = v25->intVal;
        v104.type = 105;
        idEventArgs::AddArg(this: &v132, arg: &v104);
        goto LABEL_97;
      }
      if ( v25->subType == 1 )
      {
        if ( Event->formatspec[v132.argsNumber] != 98 )
        {
          idStr::idStr(this: &v129, text: &byte_8200D768);
          idEventDef::GetEventArgTypeName(eventNum: Event->eventnum, argNum: v132.argsNumber, argType: &v129);
          idLib::Warning(fmt: v77, script->list[v18].eventName.data, v22, v129.data);
          v17 = 1;
          idStr::FreeData(this: &v129);
        }
        intVal = v25->intVal;
        v115.type = 105;
        v115.value.i = intVal != 0;
        idEventArgs::AddArg(this: &v132, arg: &v115);
        goto LABEL_97;
      }
      if ( (unsigned __int8)idAIActionParm::IsEnum(this: v25) != 0 )
      {
        if ( Event->formatspec[v132.argsNumber] != 105 )
        {
          idStr::idStr(this: &v122, text: &byte_8200D768);
          idEventDef::GetEventArgTypeName(eventNum: Event->eventnum, argNum: v132.argsNumber, argType: &v122);
          idLib::Warning(fmt: v75, script->list[v18].eventName.data, v22, v122.data);
          v17 = 1;
          idStr::FreeData(this: &v122);
        }
        v113.value.i = v25->intVal;
        v113.type = 105;
        idEventArgs::AddArg(this: &v132, arg: &v113);
        goto LABEL_97;
      }
      idLib::Warning(fmt: v86);
      goto LABEL_96;
    }
    if ( Event->formatspec[v132.argsNumber] != 100 )
    {
      idStr::idStr(this: &v128, text: &byte_8200D768);
      idEventDef::GetEventArgTypeName(eventNum: Event->eventnum, argNum: v132.argsNumber, argType: &v128);
      idLib::Warning(fmt: v81, script->list[v18].eventName.data, v22, v128.data);
      v17 = 1;
      idStr::FreeData(this: &v128);
    }
    if ( (unsigned int)v25->subType - 24 > 6 )
      goto LABEL_95;
    if ( v25->subType == 25 )
    {
      v119.value.i = (int)v25->declVal;
      v119.type = 100;
      idEventArgs::AddArg(this: &v132, arg: &v119);
    }
    else
    {
      if ( v25->subType != 26 )
      {
        if ( v25->subType != 27 && v25->subType != 28 && v25->subType != 29 )
        {
          if ( v25->subType == 24 )
          {
            v107.value.i = (int)v25->declVal;
            v107.type = 100;
            idEventArgs::AddArg(this: &v132, arg: &v107);
          }
          else
          {
            v121.value.i = (int)v25->declVal;
            v121.type = 100;
            idEventArgs::AddArg(this: &v132, arg: &v121);
          }
          goto LABEL_97;
        }
LABEL_95:
        idLib::Warning(fmt: v83);
LABEL_96:
        v17 = 1;
        goto LABEL_97;
      }
      v109.value.i = (int)v25->declVal;
      v109.type = 100;
      idEventArgs::AddArg(this: &v132, arg: &v109);
    }
LABEL_97:
    ++v22;
    ++v24;
    v23 = &script->list[v18];
    if ( v22 >= v23->parms.num )
      goto LABEL_98;
  }
  if ( (unsigned int)v25->subType - 20 > 3 )
  {
    idLib::Warning(fmt: v78);
    goto LABEL_96;
  }
  if ( v25->subType != 21 )
  {
    if ( v25->subType == 22 )
    {
      if ( Event->formatspec[v132.argsNumber] != 49 )
      {
        idStr::idStr(this: &v124, text: &byte_8200D768);
        idEventDef::GetEventArgTypeName(eventNum: Event->eventnum, argNum: v132.argsNumber, argType: &v124);
        idLib::Warning(
          fmt: "Script action event '%s' is called with anim web path %d parameter, but expects %s type",
          script->list[v18].eventName.data,
          v22,
          v124.data);
        v17 = 1;
        idStr::FreeData(this: &v124);
      }
      v101.allocedAndFlag = 20;
      v101.len = 0;
      v101.data = v101.baseBuffer;
      v101.baseBuffer[0] = 0;
      idAIActionParm::Get(this: v25, out: &v101, subType_: SP_ANIM_WEB_NODE);
      idStr::idStr(this: &v133, text: &v101);
      v105.type = 49;
      v105.value.i = (int)v133.data;
      idEventArgs::AddArg(this: &v132, arg: &v105);
      idStr::FreeData(this: &v133);
      idStr::FreeData(this: &v101);
    }
    else if ( v25->subType == 20 )
    {
      if ( Event->formatspec[v132.argsNumber] != 115 )
      {
        idStr::idStr(this: &v123, text: &byte_8200D768);
        idEventDef::GetEventArgTypeName(eventNum: Event->eventnum, argNum: v132.argsNumber, argType: &v123);
        idLib::Warning(fmt: v68, script->list[v18].eventName.data, v22, v123.data);
        v17 = 1;
        idStr::FreeData(this: &v123);
      }
      v100.allocedAndFlag = 20;
      v100.len = 0;
      v100.data = v100.baseBuffer;
      v100.baseBuffer[0] = 0;
      idAIActionParm::Get(this: v25, out: &v100, subType_: SP_STRING);
      v108.type = 115;
      v108.value.i = (int)v100.data;
      idEventArgs::AddArg(this: &v132, arg: &v108);
      idStr::FreeData(this: &v100);
    }
    else
    {
      if ( Event->formatspec[v132.argsNumber] != 101 )
      {
        idStr::idStr(this: &v126, text: &byte_8200D768);
        idEventDef::GetEventArgTypeName(eventNum: Event->eventnum, argNum: v132.argsNumber, argType: &v126);
        idLib::Warning(fmt: v70, script->list[v18].eventName.data, v22, v126.data);
        v17 = 1;
        idStr::FreeData(this: &v126);
      }
      v96.allocedAndFlag = 20;
      v96.len = 0;
      v96.data = v96.baseBuffer;
      v96.baseBuffer[0] = 0;
      idAIActionParm::Get(this: v25, out: &v96, subType_: SP_ENTITY_NAME);
      if ( v96.len != 0 )
      {
        v99.allocedAndFlag = 20;
        v99.len = 0;
        v99.data = v99.baseBuffer;
        v99.baseBuffer[0] = 0;
        v32 = gameLocal->FindEntityForName(this: gameLocal, a2: v96.data, a3: scriptExecutor, a4: activator, a5: &v99);
        if ( v32 == nullptr && Event == v72 && idStr::Icmp(s1: v96.data, s2: ACTIONSCRIPT_NULL) != 0 )
          goto _LN709;
        v63.spawnId.value = 0x1FFF;
        if ( v32 != nullptr )
          v63.spawnId.value = (gameLocal->spawnIds.ptr[v32->entityNumber] << 13) | v32->entityNumber;
        else
          v63.spawnId.value = 0x1FFF;
        if ( v74 )
          idGameState::SetUnresolvedEntityName(ptr: &v63, name: v32->name.data);
        v76.value = v63.spawnId.value;
        idEventArg::idEventArg(this: &v102, data: &v76);
        idEventArgs::AddArg(this: &v132, arg: &v102);
        idStr::FreeData(this: &v99);
      }
      else
      {
        v117.type = 105;
        v117.value.i = 0;
        idEventArgs::AddArg(this: &v132, arg: &v117);
      }
      idStr::FreeData(this: &v96);
    }
    goto LABEL_97;
  }
  idLib::Error(fmt: "Anim Alias parameters are no longer allowed in action scripts due to resource dependencies!");
_LN709:
  idLib::Error(fmt: "Action script references invalid entity '%s' - %s.", v96.data, v99.data);
  _LN710(a1: v59, a2: v58, a3: v57, a4: v56, a5: v55, a6: v54, a7: v53, a8: v52, a9, a10, a11, a12: this);
}


// ========================================================================
// $LN710
// EA  : 0x82BBAB0C
// RVA : 0x00BBAB0C
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _LN710()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2032 + 1840));
}


// ========================================================================
// __unwind$491061
// EA  : 0x82BBAB34
// RVA : 0x00BBAB34
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_491061()
{
  int v0; // r12

  idEventArgs::~idEventArgs(this: (idEventArgs *)(v0 - 2032 + 1376));
}


// ========================================================================
// __unwind$491064
// EA  : 0x82BBAB5C
// RVA : 0x00BBAB5C
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_491064()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2032 + 1056));
}


// ========================================================================
// __unwind$491062
// EA  : 0x82BBAB84
// RVA : 0x00BBAB84
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_491062()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2032 + 1280));
}


// ========================================================================
// __unwind$491063
// EA  : 0x82BBABAC
// RVA : 0x00BBABAC
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_491063()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2032 + 1152));
}


// ========================================================================
// __unwind$491067_0
// EA  : 0x82BBABD4
// RVA : 0x00BBABD4
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_491067_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2032 + 1312));
}


// ========================================================================
// __unwind$491066
// EA  : 0x82BBABFC
// RVA : 0x00BBABFC
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_491066()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2032 + 1216));
}


// ========================================================================
// __unwind$491065
// EA  : 0x82BBAC24
// RVA : 0x00BBAC24
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_491065()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2032 + 1344));
}


// ========================================================================
// __unwind$491068_0
// EA  : 0x82BBAC4C
// RVA : 0x00BBAC4C
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_491068_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2032 + 1088));
}


// ========================================================================
// __unwind$491069
// EA  : 0x82BBAC74
// RVA : 0x00BBAC74
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_491069()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2032 + 352));
}


// ========================================================================
// __unwind$491070
// EA  : 0x82BBAC9C
// RVA : 0x00BBAC9C
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_491070()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2032 + 1120));
}


// ========================================================================
// __unwind$491071
// EA  : 0x82BBACC4
// RVA : 0x00BBACC4
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_491071()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2032 + 384));
}


// ========================================================================
// __unwind$491072_0
// EA  : 0x82BBACEC
// RVA : 0x00BBACEC
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_491072_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2032 + 1808));
}


// ========================================================================
// __unwind$491073
// EA  : 0x82BBAD14
// RVA : 0x00BBAD14
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_491073()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2032 + 1184));
}


// ========================================================================
// __unwind$491074
// EA  : 0x82BBAD3C
// RVA : 0x00BBAD3C
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_491074()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2032 + 224));
}


// ========================================================================
// __unwind$491075
// EA  : 0x82BBAD64
// RVA : 0x00BBAD64
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_491075()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2032 + 320));
}


// ========================================================================
// __unwind$491076
// EA  : 0x82BBAD8C
// RVA : 0x00BBAD8C
// PDB : w:\tech5\tungsten\game\components\timelinecomponent.cpp
// ========================================================================

void _unwind_491076()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2032 + 1248));
}

