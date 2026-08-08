
// ========================================================================
// ??0idAIInteraction@@QAA@XZ
// EA  : 0x82A52088
// RVA : 0x00A52088
// PDB : w:\tech5\tungsten\game\ai\aiinteraction.cpp
// ========================================================================

idAIInteraction *__fastcall idAIInteraction::idAIInteraction(idAIInteraction *this)
{
  idEntity::idEntity(this);
  this->startTime = -1;
  this->interactionDecl = nullptr;
  this->__vftable = (idAIInteraction_vtbl *)&idAIInteraction::`vftable';
  this->nextEvent = -1;
  this->activator.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ?Spawn@idAIInteraction@@QAAXXZ
// EA  : 0x82A520E0
// RVA : 0x00A520E0
// PDB : w:\tech5\tungsten\game\ai\aiinteraction.cpp
// ========================================================================

void __fastcall idAIInteraction::Spawn(idAIInteraction *this)
{
  const idDeclAIInteraction *interactionDecl; // r7
  int num; // r8
  int timeMS; // r9
  int v5; // r4
  idDeclAIInteraction::eventData_t *list; // r6
  int v7; // r11

  idEntity::BecomeInactive(this, flags: 1);
  interactionDecl = this->interactionDecl;
  if ( interactionDecl != nullptr )
  {
    num = interactionDecl->events.num;
    timeMS = 0;
    v5 = 0;
    if ( num > 0 )
    {
      list = interactionDecl->events.list;
      v7 = 0;
      do
      {
        if ( list[v7].type == IEV_MAX )
        {
          idLib::Error(fmt: "Event %d in AI interaction decl '%s' has an invalid type.", v5, interactionDecl->name.str);
_LN36_4:
          idLib::Error(
            fmt: "Event %d in AI interaction decl '%s' is out of order (events must be sorted by increasing time).",
            v5,
            interactionDecl->name.str);
          JUMPOUT(0x82A521AC);
        }
        if ( list[v7].timeMS < timeMS )
          goto _LN36_4;
        ++v5;
        timeMS = list[v7++].timeMS;
      }
      while ( v5 < num );
    }
  }
  else
  {
    idLib::Warning(fmt: "idAIInteraction '%s': no interaction decl specified!", this->name.data);
  }
}


// ========================================================================
// ?BeginInteraction@idAIInteraction@@AAAXPAVidEntity@@@Z
// EA  : 0x82A521B0
// RVA : 0x00A521B0
// PDB : w:\tech5\tungsten\game\ai\aiinteraction.cpp
// ========================================================================

void __fastcall idAIInteraction::BeginInteraction(idAIInteraction *this, idEntity *activator)
{
  int v4; // r27
  int v5; // r30
  int value; // r9
  idEntity *v7; // r3
  idAI2 *v8; // r3
  idAI2 *v9; // r3

  if ( this->interactionDecl != nullptr )
  {
    this->startTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->nextEvent = 0;
    if ( activator != nullptr )
      this->activator.spawnId.value = (gameLocal->spawnIds.ptr[activator->entityNumber] << 13) | activator->entityNumber;
    else
      this->activator.spawnId.value = 0x1FFF;
    idEntity::BecomeActive(this, flags: 1);
    v4 = 0;
    if ( this->targets.num > 0 )
    {
      v5 = 0;
      do
      {
        if ( v4 < this->targets.num
          && (value = this->targets.list[v5].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
          && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v8 = (idAI2 *)idEntity::CastTo(c: v7);
        }
        else
        {
          v8 = nullptr;
        }
        v9 = idAI2::CastTo(c: v8);
        if ( v9 != nullptr )
          v9->aiVolatile.memory.currentInteraction.spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13)
                                                                 | this->entityNumber;
        ++v4;
        ++v5;
      }
      while ( v4 < this->targets.num );
    }
  }
  else
  {
    idLib::Warning(fmt: "idAIInteraction '%s': no interaction decl specified!", this->name.data);
  }
}


// ========================================================================
// ?EndInteraction@idAIInteraction@@AAAXXZ
// EA  : 0x82A52308
// RVA : 0x00A52308
// PDB : w:\tech5\tungsten\game\ai\aiinteraction.cpp
// ========================================================================

void __fastcall idAIInteraction::EndInteraction(idAIInteraction *this)
{
  int v2; // r29
  int v3; // r30
  int value; // r9
  idEntity *v5; // r3
  idAI2 *v6; // r3
  idAI2 *v7; // r3

  v2 = 0;
  if ( this->targets.num > 0 )
  {
    v3 = 0;
    do
    {
      if ( v2 < this->targets.num
        && (value = this->targets.list[v3].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
        && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v6 = (idAI2 *)idEntity::CastTo(c: v5);
      }
      else
      {
        v6 = nullptr;
      }
      v7 = idAI2::CastTo(c: v6);
      if ( v7 != nullptr )
        v7->aiVolatile.memory.currentInteraction.spawnId.value = 0x1FFF;
      ++v2;
      ++v3;
    }
    while ( v2 < this->targets.num );
  }
  this->activator.spawnId.value = 0x1FFF;
  this->nextEvent = -1;
  this->startTime = -1;
  idEntity::BecomeInactive(this, flags: 1);
}


// ========================================================================
// ?Think@idAIInteraction@@UAAXXZ
// EA  : 0x82A523D8
// RVA : 0x00A523D8
// PDB : w:\tech5\tungsten\game\ai\aiinteraction.cpp
// ========================================================================

void __fastcall idAIInteraction::Think(idAIInteraction *this)
{
  const idDeclAIInteraction *interactionDecl; // r11
  int v3; // r25
  idDeclAIInteraction::eventData_t *v4; // r29
  int actorIndex; // r11
  int value; // r9
  idEntity *v7; // r3
  idAI2 *v8; // r3
  idAI2 *v9; // r3
  idAI2 *v10; // r30
  int v11; // r9
  idEntity *v12; // r3
  idEntity *v13; // r6
  int GameMs; // r3
  const idDeclAIInteraction *v15; // r10
  int v16; // r11

  interactionDecl = this->interactionDecl;
  if ( interactionDecl != nullptr && interactionDecl->events.num > 0 )
  {
    v3 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - this->startTime;
    v4 = &this->interactionDecl->events.list[this->nextEvent];
    if ( v4->timeMS <= v3 )
    {
      while ( 1 )
      {
        if ( v4->type == IEV_ACTIONSCRIPT )
        {
          actorIndex = v4->actorIndex;
          if ( actorIndex < this->targets.num
            && (value = this->targets.list[actorIndex].spawnId.value,
                gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
            && (v7 = gameLocal->entities.ptr[this->targets.list[actorIndex].spawnId.value & 0x1FFF]) != nullptr )
          {
            v8 = (idAI2 *)idEntity::CastTo(c: v7);
          }
          else
          {
            v8 = nullptr;
          }
          v9 = idAI2::CastTo(c: v8);
          v10 = v9;
          if ( v9 != nullptr )
          {
            if ( !v9->IsDead(this: v9) )
            {
              v11 = this->activator.spawnId.value;
              if ( gameLocal->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13
                && (v12 = gameLocal->entities.ptr[v11 & 0x1FFF]) != nullptr )
              {
                v13 = idEntity::CastTo(c: v12);
              }
              else
              {
                v13 = nullptr;
              }
              idAI2::SetActionScript(this: v10, script: &v4->actionScript, scriptExecutor: this, activator: v13);
              GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
              idAI2::StartActionScript(this: v10, curTime: GameMs);
            }
          }
          else
          {
            idLib::Warning(
              fmt: "Event %d in AI interaction decl '%s' specifies an invalid actorIndex %d for an action script (entity type must be an AI).",
              this->nextEvent,
              this->interactionDecl->name.str,
              v4->actorIndex);
          }
        }
        v15 = this->interactionDecl;
        v16 = this->nextEvent + 1;
        this->nextEvent = v16;
        if ( v16 >= v15->events.num )
          break;
        v4 = &v15->events.list[v16];
        if ( v4->timeMS > v3 )
          return;
      }
      idAIInteraction::EndInteraction(this);
    }
  }
  else
  {
    idEntity::BecomeInactive(this, flags: 1);
  }
}


// ========================================================================
// ?OnActivate@idAIInteraction@@UAAXPAVidEntity@@@Z
// EA  : 0x82A525E0
// RVA : 0x00A525E0
// PDB : w:\tech5\tungsten\game\ai\aiinteraction.cpp
// ========================================================================

// attributes: thunk
void __fastcall idAIInteraction::OnActivate(idAIInteraction *this, idEntity *activator)
{
  idAIInteraction::BeginInteraction(this, activator);
}


// ========================================================================
// ??0idDeclAIInteraction@@QAA@XZ
// EA  : 0x82A525F0
// RVA : 0x00A525F0
// PDB : w:\tech5\tungsten\game\ai\aiinteraction.cpp
// ========================================================================

idDeclAIInteraction *__fastcall idDeclAIInteraction::idDeclAIInteraction(idDeclAIInteraction *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->__vftable = (idDeclAIInteraction_vtbl *)&idDeclAIInteraction::`vftable';
  this->events.granularity = 0;
  this->events.memTag = 5;
  this->events.listStatic = 0;
  this->events.list = nullptr;
  this->events.size = 0;
  this->events.num = 0;
  return this;
}


// ========================================================================
// __unwind$489391
// EA  : 0x82A52660
// RVA : 0x00A52660
// PDB : w:\tech5\tungsten\game\ai\aiinteraction.cpp
// ========================================================================

void _unwind_489391()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}

