
// ========================================================================
// ?GetScriptFunction@idStateThread@@QAAPBVfunction_t@@PBD@Z
// EA  : 0x82EA18A8
// RVA : 0x00EA18A8
// PDB : w:\tech5\tungsten\game\script\statethread.cpp
// ========================================================================

const function_t *__fastcall idStateThread::GetScriptFunction(idStateThread *this, const char *funcname)
{
  int value; // r10
  idEntity *v5; // r3
  int v6; // r9
  idEntity *v7; // r3
  idEntity *v8; // r3
  idScriptObject *v9; // r30
  const function_t *Function; // r31
  char *TypeName; // r3

  value = this->entity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
    || (v5 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
    || idEntity::CastTo(c: v5) == nullptr )
  {
    idThread::Error(this, fmt: "idStateThread::GetScriptFunction : Null entity");
  }
  v6 = this->entity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13 && (v7 = gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
    v8 = idEntity::CastTo(c: v7);
  else
    v8 = nullptr;
  v9 = v8->GetScriptObject_2(this: v8);
  Function = idScriptObject::GetFunction(this: v9, name: funcname);
  if ( Function == nullptr )
  {
    TypeName = idScriptObject::GetTypeName(this: v9);
    idThread::Error(this, fmt: "Unknown function '%s' in '%s'", funcname, TypeName);
  }
  return Function;
}


// ========================================================================
// ?CallConstructor@idStateThread@@QAAXXZ
// EA  : 0x82EA19B0
// RVA : 0x00EA19B0
// PDB : w:\tech5\tungsten\game\script\statethread.cpp
// ========================================================================

void __fastcall idStateThread::CallConstructor(idStateThread *this)
{
  int value; // r10
  idEntity *v3; // r3
  int v4; // r9
  idEntity *v5; // r3
  idEntity *v6; // r3

  value = this->entity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
    || (v3 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
    || idEntity::CastTo(c: v3) == nullptr )
  {
    idLib::Error(fmt: "idStateThread::EndState : Null entity");
  }
  v4 = this->entity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v4 & 0x1FFF] == v4 >> 13 && (v5 = gameLocal->entities.ptr[v4 & 0x1FFF]) != nullptr )
    v6 = idEntity::CastTo(c: v5);
  else
    v6 = nullptr;
  idEntity::ConstructScriptObject(this: v6);
}


// ========================================================================
// ?EndState@idStateThread@@QAAXXZ
// EA  : 0x82EA1A80
// RVA : 0x00EA1A80
// PDB : w:\tech5\tungsten\game\script\statethread.cpp
// ========================================================================

void __fastcall idStateThread::EndState(idStateThread *this)
{
  int value; // r10
  idEntity *v3; // r3
  int v4; // r10
  idEntity *v5; // r3
  idEntity *v6; // r3
  const char *data; // r30
  int GameMs; // r3

  value = this->entity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
    || (v3 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
    || idEntity::CastTo(c: v3) == nullptr )
  {
    idThread::Error(this, fmt: "idStateThread::EndState : Null entity");
  }
  v4 = this->entity.spawnId.value;
  if ( ai_debugScript.valueInteger == (v4 & 0x1FFF) && this->state != nullptr )
  {
    if ( gameLocal->spawnIds.ptr[this->entity.spawnId.value & 0x1FFF] == this->entity.spawnId.value >> 13
      && (v5 = gameLocal->entities.ptr[v4 & 0x1FFF]) != nullptr )
    {
      v6 = idEntity::CastTo(c: v5);
    }
    else
    {
      v6 = nullptr;
    }
    data = v6->name.data;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(fmt: "%d: %s: End state\n", GameMs, data);
  }
  this->state = nullptr;
  this->idealState = nullptr;
  idThread::End(this);
}


// ========================================================================
// ?SetState@idStateThread@@QAAXPBVfunction_t@@@Z
// EA  : 0x82EA1BA0
// RVA : 0x00EA1BA0
// PDB : w:\tech5\tungsten\game\script\statethread.cpp
// ========================================================================

void __fastcall idStateThread::SetState(idStateThread *this, idDecl *newState)
{
  int value; // r10
  idEntityPtr<idEntity> *p_entity; // r31
  idEntity *v6; // r3
  char *data; // r27
  int GameMs; // r26
  const char *v9; // r3
  idEntity *v10; // r3
  idEntity *v11; // r4

  if ( newState != nullptr )
  {
    value = this->entity.spawnId.value;
    p_entity = &this->entity;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
      && idEntity::CastTo(c: v6) != nullptr )
    {
      if ( ai_debugScript.valueInteger == (p_entity->spawnId.value & 0x1FFF) )
      {
        data = idEntityPtr<idEntity const>::operator->(this: &this->entity)->name.data;
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v9 = (const char *)function_t::Name(this: newState);
        idLib::Printf(fmt: "%d: %s: State: %s\n", GameMs, data, v9);
      }
      this->idealState = (const function_t *)newState;
      this->state = (const function_t *)newState;
      this->interpreter.doneProcessing = true;
      if ( gameLocal->spawnIds.ptr[p_entity->spawnId.value & 0x1FFF] == p_entity->spawnId.value >> 13
        && (v10 = gameLocal->entities.ptr[p_entity->spawnId.value & 0x1FFF]) != nullptr )
      {
        v11 = idEntity::CastTo(c: v10);
      }
      else
      {
        v11 = nullptr;
      }
      idThread::CallObjectFunction(this, self: v11, func: this->state, clearStack: true);
    }
    else
    {
      idThread::Error(this, fmt: "idStateThread::SetState: Null entity");
    }
  }
  else
  {
    idThread::Error(this, fmt: "idStateThread::SetState: Null state");
  }
}


// ========================================================================
// ?SetState@idStateThread@@QAAXPBD@Z
// EA  : 0x82EA1D08
// RVA : 0x00EA1D08
// PDB : w:\tech5\tungsten\game\script\statethread.cpp
// ========================================================================

void __fastcall idStateThread::SetState(idStateThread *this, const char *statename)
{
  idDecl *ScriptFunction; // r3

  ScriptFunction = (idDecl *)idStateThread::GetScriptFunction(this, funcname: statename);
  idStateThread::SetState(this, newState: ScriptFunction);
}


// ========================================================================
// ?UpdateScript@idStateThread@@QAAXXZ
// EA  : 0x82EA1D40
// RVA : 0x00EA1D40
// PDB : w:\tech5\tungsten\game\script\statethread.cpp
// ========================================================================

void __fastcall idStateThread::UpdateScript(idStateThread *this)
{
  int v2; // r29
  const function_t *idealState; // r11
  int value; // r9
  idEntity *v5; // r3
  idEntity *v6; // r4
  idThread *waitingForThread; // r11

  this->interpreter.debug = ai_debugScript.valueInteger == (this->entity.spawnId.value & 0x1FFF);
  v2 = 0;
  while ( 1 )
  {
    idealState = this->idealState;
    if ( idealState != this->state )
    {
      this->state = idealState;
      value = this->entity.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v6 = idEntity::CastTo(c: v5);
      }
      else
      {
        v6 = nullptr;
      }
      idThread::CallObjectFunction(this, self: v6, func: this->state, clearStack: true);
    }
    if ( idThread::IsWaiting(this) )
    {
      waitingForThread = this->waitingForThread;
      if ( waitingForThread == nullptr || !waitingForThread->interpreter.threadDying )
        goto LABEL_17;
      idThread::ClearWaitFor(this);
    }
    idThread::Execute(this);
    if ( this->idealState == this->state )
      break;
    if ( ++v2 >= 20 )
      goto LABEL_17;
  }
  if ( this->interpreter.threadDying )
    idStateThread::EndState(this);
LABEL_17:
  if ( v2 == 20 )
    idThread::Warning(this, fmt: "idStateThread::UpdateScript: exited loop to prevent lockup");
}


// ========================================================================
// ??0idStateThread@@QAA@XZ
// EA  : 0x82EA1E80
// RVA : 0x00EA1E80
// PDB : w:\tech5\tungsten\game\script\statethread.cpp
// ========================================================================

idStateThread *__fastcall idStateThread::idStateThread(idStateThread *this)
{
  idThread::idThread(this);
  this->__vftable = (idStateThread_vtbl *)&idStateThread::`vftable';
  this->entity.spawnId.value = 0x1FFF;
  this->entity.spawnId.value = 0x1FFF;
  this->state = nullptr;
  this->idealState = nullptr;
  this->manualControl = true;
  return this;
}

