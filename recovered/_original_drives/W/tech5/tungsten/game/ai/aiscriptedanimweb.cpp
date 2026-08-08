
// ========================================================================
// ?Spawn@idAIScriptedAnimWeb@@QAAXXZ
// EA  : 0x82A60650
// RVA : 0x00A60650
// PDB : w:\tech5\tungsten\game\ai\aiscriptedanimweb.cpp
// ========================================================================

void __fastcall idAIScriptedAnimWeb::Spawn(idAIScriptedAnimWeb *this)
{
  this->stateInfo.animWebStates = &this->animWebStates;
}


// ========================================================================
// ?StartAIAction@idAIScriptedAnimWeb@@QAAXPAVidEntity@@@Z
// EA  : 0x82A607F8
// RVA : 0x00A607F8
// PDB : w:\tech5\tungsten\game\ai\aiscriptedanimweb.cpp
// ========================================================================

void __fastcall idAIScriptedAnimWeb::StartAIAction(idAIScriptedAnimWeb *this, idEntity *activator)
{
  idList<idAIActionParm,5> *p_parms; // r30
  int size; // r11
  char *data; // r27
  idAIActionParm *list; // r30
  idAIActionParm *v8; // r30
  int v9; // r24
  int num; // r11
  int v11; // r27
  int value; // r9
  idEntity *v13; // r3
  idAI2 *v14; // r3
  idAI2 *v15; // r30
  int v16; // r9
  idEntity *v17; // r3
  idTarget_Spawn *v18; // r3
  idTarget_Spawn *v19; // r3
  int v20; // r9
  idEntity *v21; // r3
  idAI2 *v22; // r3
  int GameMs; // r3
  idList<idScriptAction,5> v24[7]; // [sp+60h] [-70h] BYREF

  v24[0].memTag = 5;
  v24[0].listStatic = 0;
  memset(v24, 0, 14);
  if ( (unsigned __int8)idList<idScriptAction,5>::Resize(this: v24, newsize: 1) != 0 )
  {
    v24[0].num = 1;
    if ( v24[0].size <= 1 )
      v24[0].num = v24[0].size;
  }
  idStr::operator=(this: &v24[0].list->eventName, text: "action_ScriptedAnimWeb");
  p_parms = &v24[0].list->parms;
  if ( v24[0].list->parms.size >= 2
    || (unsigned __int8)idList<idAIActionParm,5>::Resize(this: &v24[0].list->parms, newsize: 2) != 0 )
  {
    size = p_parms->size;
    if ( size > 2 )
      size = 2;
    p_parms->num = size;
  }
  data = this->name.data;
  list = v24[0].list->parms.list;
  idAIActionParm::Clear(this: list);
  list->type = 3;
  list->subType = 23;
  idStr::operator=(this: &list->strVal, text: data);
  v8 = v24[0].list->parms.list + 1;
  idAIActionParm::Clear(this: v8);
  v8->type = 1;
  v8->subType = 0;
  v9 = 0;
  v8->intVal = 0;
  num = this->targets.num;
  if ( num > 0 )
  {
    v11 = 0;
    do
    {
      if ( v9 < num
        && (value = this->targets.list[v11].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
        && (v13 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v14 = (idAI2 *)idEntity::CastTo(c: v13);
      }
      else
      {
        v14 = nullptr;
      }
      v15 = idAI2::CastTo(c: v14);
      if ( v15 != nullptr )
        goto LABEL_28;
      if ( v9 < this->targets.num
        && (v16 = this->targets.list[v11].spawnId.value, gameLocal->spawnIds.ptr[v16 & 0x1FFF] == v16 >> 13)
        && (v17 = gameLocal->entities.ptr[v16 & 0x1FFF]) != nullptr )
      {
        v18 = (idTarget_Spawn *)idEntity::CastTo(c: v17);
      }
      else
      {
        v18 = nullptr;
      }
      v19 = idTarget_Spawn::CastTo(c: v18);
      if ( v19 != nullptr )
      {
        v20 = v19->lastSpawned.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v20 & 0x1FFF] == v20 >> 13
          && (v21 = gameLocal->entities.ptr[v20 & 0x1FFF]) != nullptr )
        {
          v22 = (idAI2 *)idEntity::CastTo(c: v21);
        }
        else
        {
          v22 = nullptr;
        }
        v15 = idAI2::CastTo(c: v22);
        if ( v15 != nullptr )
        {
LABEL_28:
          idAI2::SetActionScript(this: v15, script: v24, scriptExecutor: this, activator);
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          idAI2::StartActionScript(this: v15, curTime: GameMs);
        }
      }
      ++v9;
      ++v11;
      num = this->targets.num;
    }
    while ( v9 < num );
  }
  if ( (v24[0].listStatic == 0 || v24[0].listStatic == 2) && v24[0].list != nullptr )
    idListArrayDelete<idScriptAction>(ptr: (char *)v24[0].list, num: v24[0].size);
}


// ========================================================================
// __unwind$488448
// EA  : 0x82A60AC0
// RVA : 0x00A60AC0
// PDB : w:\tech5\tungsten\game\ai\aiscriptedanimweb.cpp
// ========================================================================

void _unwind_488448()
{
  int v0; // r12

  idList<idScriptAction,5>::Clear(this: (idList<idScriptAction,5> *)(v0 - 208 + 96));
}


// ========================================================================
// ?OnActivate@idAIScriptedAnimWeb@@UAAXPAVidEntity@@@Z
// EA  : 0x82A60AE8
// RVA : 0x00A60AE8
// PDB : w:\tech5\tungsten\game\ai\aiscriptedanimweb.cpp
// ========================================================================

void __fastcall idAIScriptedAnimWeb::OnActivate(idAIScriptedAnimWeb *this, idEntity *activator)
{
  if ( this->stateInfo.animWebStates->num > 0 )
    this->stateInfo.currentState = 0;
  idAIScriptedAnimWeb::StartAIAction(this, activator);
}

