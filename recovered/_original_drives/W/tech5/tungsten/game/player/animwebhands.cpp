
// ========================================================================
// ??0idAnimWebHands@@QAA@XZ
// EA  : 0x82DF5C40
// RVA : 0x00DF5C40
// PDB : w:\tech5\tungsten\game\player\animwebhands.cpp
// ========================================================================

idAnimWebHands *__fastcall idAnimWebHands::idAnimWebHands(idAnimWebHands *this)
{
  idAnimator_AnimWeb::idAnimator_AnimWeb(this);
  this->hands = nullptr;
  this->__vftable = (idAnimWebHands_vtbl *)&idAnimWebHands::`vftable';
  this->punchSelector = 0.0;
  this->throwSelector = 0.0;
  this->idleSelector = 0.0;
  this->meleeReturnSelector = 0.0;
  this->zoomSelector = 0.0;
  this->weaponCondition = 0.0;
  this->variationIndex = 0.0;
  this->previousVariationIndex = 0.0;
  this->weaponAnimVarIndex = 0.0;
  this->attackVariation = 0.0;
  return this;
}


// ========================================================================
// ??1idAnimWebHands@@UAA@XZ
// EA  : 0x82DF5CB8
// RVA : 0x00DF5CB8
// PDB : w:\tech5\tungsten\game\player\animwebhands.cpp
// ========================================================================

void __fastcall idAnimWebHands::~idAnimWebHands(idAnimWebHands *this)
{
  this->__vftable = (idAnimWebHands_vtbl *)&idAnimWebHands::`vftable';
  idAnimator_AnimWeb::~idAnimator_AnimWeb(this);
}


// ========================================================================
// ?InternalStartBlend@idAnimWebHands@@MAAXPBVidDeclAnimWebNode@@0H@Z
// EA  : 0x82DF5CC8
// RVA : 0x00DF5CC8
// PDB : w:\tech5\tungsten\game\player\animwebhands.cpp
// ========================================================================

void __fastcall idAnimWebHands::InternalStartBlend(
        idAnimWebHands *this,
        const idDeclAnimWebNode *curNode,
        const idDeclAnimWebNode *nextNode,
        int curTime)
{
  __int64 v5; // r11
  __int64 v6; // fp0
  __int64 v7; // r8

  idAnimator_AnimWeb::InternalStartBlend(this, curNode, nextNode, curTime);
  HIDWORD(v5) = this->hands->meleeComboCount;
  LODWORD(v5) = SHIDWORD(v5) % 4;
  if ( SHIDWORD(v5) % 4 >= 2 )
  {
    if ( (int)v5 < 3 )
    {
      this->punchSelector = 2.0;
      return;
    }
    HIDWORD(v7) = 1664525 * clientGame->random.seed;
    clientGame->random.seed = HIDWORD(v7) + 1013904223;
    LODWORD(v7) = (((unsigned int)(HIDWORD(v7) + 1013904223) >> 10) & 0x7FFF)
                - 2 * ((int)(((unsigned int)(HIDWORD(v7) + 1013904223) >> 10) & 0x7FFF) >> 1)
                + 3;
    v6 = v7;
  }
  else
  {
    v6 = v5;
  }
  this->punchSelector = (float)v6;
}


// ========================================================================
// ?InternalTriggerEvent@idAnimWebHands@@MAAXPBVidDeclAnimWebNode@@W4animWebEvent_t@@ABV?$idHandle@FW4invalidAnimWebHandle_t@@$0?0@@HH@Z
// EA  : 0x82DF5DB0
// RVA : 0x00DF5DB0
// PDB : w:\tech5\tungsten\game\player\animwebhands.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAnimWebHands::InternalTriggerEvent(
        idAnimWebHands *this,
        const idDeclAnimWebNode *node,
        unsigned int eventType,
        const idHandle<short,enum invalidAnimWebHandle_t,-1> *webHandle,
        unsigned int eventNum,
        const int eventParm)
{
  const idEventDef *EventCommand; // r28
  __int16 value; // r10
  __int16 v13; // r7
  __int16 v14; // r9
  int v15; // r8 OVERLAPPED
  __int128 v16; // r7 OVERLAPPED
  char *data; // r29
  __int64 v18; // r8
  int GameMs; // r3
  __int64 v20; // r10
  const char *v21; // r4
  __int64 v22; // [sp+8h] [-198h]
  __int64 v23; // [sp+10h] [-190h]
  __int64 v24; // [sp+18h] [-188h]
  __int64 v25; // [sp+20h] [-180h]
  __int64 v26; // [sp+28h] [-178h]
  __int64 v27; // [sp+30h] [-170h]
  __int64 v28; // [sp+38h] [-168h]
  __int64 v29; // [sp+40h] [-160h]
  __int64 v30; // [sp+48h] [-158h]
  __int64 v31; // [sp+50h] [-150h]
  __int64 v32; // [sp+58h] [-148h]
  int v33; // [sp+64h] [-13Ch]
  int v34; // [sp+68h] [-138h]
  int v35; // [sp+6Ch] [-134h]
  int v36[8]; // [sp+70h] [-130h] BYREF
  int v37[8]; // [sp+90h] [-110h] BYREF
  _DWORD v38[5]; // [sp+B0h] [-F0h] BYREF
  _DWORD v39[5]; // [sp+D0h] [-D0h] BYREF
  int v40; // [sp+F0h] [-B0h]
  int v41; // [sp+F4h] [-ACh]
  __int64 v42; // [sp+F8h] [-A8h]
  int v43; // [sp+100h] [-A0h]
  char v44; // [sp+110h] [-90h]
  int v45; // [sp+114h] [-8Ch]
  __int64 v46; // [sp+118h] [-88h]
  int v47; // [sp+120h] [-80h]
  idStr v48[3]; // [sp+130h] [-70h] BYREF

  EventCommand = idEventDef::GetEventCommand(eventnum: eventNum);
  if ( EventCommand != nullptr )
  {
    v38[1] = eventParm;
    value = node->states.stateIndex[0].value;
    HIBYTE(v38[0]) = 105;
    v13 = webHandle->value;
    v14 = node->subWebIndex.value;
    HIBYTE(v39[0]) = 105;
    v44 = 105;
    HIBYTE(v40) = 105;
    v41 = v13;
    v39[1] = value;
    v45 = v14;
    memcpy(Dst: v37, Src: v38, Size: 0x14u);
    memcpy(Dst: v36, Src: v39, Size: 0x14u);
    v15 = __ROL4__(v43, 32);
    DWORD1(v16) = v40;
    *((_QWORD *)&v16 + 1) = v42;
    idEventReceiver::PostEventMS(
      this: this->hands,
      ev: EventCommand,
      arg1: *(__int64 *)((char *)&v16 + 4),
      arg3: *(__int64 *)&v15,
      arg4: v46,
      a6: v22,
      a7: v23,
      a8: v24,
      a9: v25,
      a10: v26,
      a11: v27,
      a12: v28,
      a13: v29,
      a14: v30,
      a15: v31,
      a16: v32,
      a17: v47,
      a18: v33,
      a19: v34,
      a20: v35,
      a21: v36[0],
      a22: v36[1],
      arg3a: v36[2],
      arg3_4: v36[3],
      arg3_8: v36[4],
      arg3_12: v36[5],
      arg3_16: v36[6],
      a28: v36[7],
      arg4a: v37[0]);
  }
  if ( this->debug && node != nullptr )
  {
    v48[0].len = 0;
    v48[0].allocedAndFlag = 20;
    v48[0].data = v48[0].baseBuffer;
    v48[0].baseBuffer[0] = 0;
    idDeclAnimWebNode::GetName(this: node, web: this->decl, name: v48);
    if ( eventType <= 3 )
    {
      if ( eventType == 1 )
      {
        data = v48[0].data;
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        LODWORD(v20) = &unk_82340000;
        v21 = "( %d ): Posted START_BLEND_OUT - node '%s'\n";
      }
      else if ( eventType == 2 )
      {
        data = v48[0].data;
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        LODWORD(v20) = &unk_82340000;
        v21 = "( %d ): Posted END_BLEND_IN - node '%s'\n";
      }
      else
      {
        data = v48[0].data;
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        LODWORD(v20) = &unk_82340000;
        if ( eventType != 0 )
          v21 = "( %d ): Posted END_BLEND_OUT - node '%s'\n";
        else
          v21 = "( %d ): Posted START_BLEND_IN - node '%s'\n";
      }
      idAnimator_AnimWeb::DebugPrint(
        this,
        fmt: v21,
        a3: __SPAIR64__(GameMs, (unsigned int)data),
        a4: v18,
        a5: v20,
        a6: SHIDWORD(v22),
        a7: v22,
        a8: SHIDWORD(v23),
        a9: v23,
        a10: SHIDWORD(v24),
        a11: v24);
    }
    idStr::FreeData(this: v48);
  }
}


// ========================================================================
// __unwind$487573_0
// EA  : 0x82DF5F98
// RVA : 0x00DF5F98
// PDB : w:\tech5\tungsten\game\player\animwebhands.cpp
// ========================================================================

void _unwind_487573_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 304));
}


// ========================================================================
// ?InternalUpdateTriggerEvent@idAnimWebHands@@MAAXPBVidDeclAnimWebNode@@W4animWebEvent_t@@@Z
// EA  : 0x82DF5FC8
// RVA : 0x00DF5FC8
// PDB : w:\tech5\tungsten\game\player\animwebhands.cpp
// ========================================================================

void __fastcall idAnimWebHands::InternalUpdateTriggerEvent(
        idAnimWebHands *this,
        const idDeclAnimWebNode *node,
        unsigned int eventType)
{
  char *data; // r29
  __int64 v6; // r8
  int GameMs; // r3
  __int64 v8; // r10
  const char *v9; // r4
  int v10; // [sp+8h] [-88h]
  int v11; // [sp+Ch] [-84h]
  int v12; // [sp+10h] [-80h]
  int v13; // [sp+14h] [-7Ch]
  int v14; // [sp+18h] [-78h]
  int v15; // [sp+1Ch] [-74h]
  idStr v16[2]; // [sp+50h] [-40h] BYREF

  if ( this->debug && node != nullptr )
  {
    v16[0].len = 0;
    v16[0].allocedAndFlag = 20;
    v16[0].data = v16[0].baseBuffer;
    v16[0].baseBuffer[0] = 0;
    idDeclAnimWebNode::GetName(this: node, web: this->decl, name: v16);
    if ( eventType <= 3 )
    {
      if ( eventType == 1 )
      {
        data = v16[0].data;
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        LODWORD(v8) = &unk_822D0000;
        v9 = "( %d ): START_BLEND_OUT - node '%s'\n";
      }
      else if ( eventType == 2 )
      {
        data = v16[0].data;
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        LODWORD(v8) = &unk_822D0000;
        v9 = "( %d ): END_BLEND_IN - node '%s'\n";
      }
      else if ( eventType != 0 )
      {
        data = v16[0].data;
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        LODWORD(v8) = &unk_822D0000;
        v9 = "( %d ): END_BLEND_OUT - node '%s'\n";
      }
      else
      {
        data = v16[0].data;
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        LODWORD(v8) = &unk_822D0000;
        v9 = "( %d ): START_BLEND_IN - node '%s'\n";
      }
      idAnimator_AnimWeb::DebugPrint(
        this,
        fmt: v9,
        a3: __SPAIR64__(GameMs, (unsigned int)data),
        a4: v6,
        a5: v8,
        a6: v10,
        a7: v11,
        a8: v12,
        a9: v13,
        a10: v14,
        a11: v15);
    }
    idStr::FreeData(this: v16);
  }
}


// ========================================================================
// __unwind$487696
// EA  : 0x82DF60F8
// RVA : 0x00DF60F8
// PDB : w:\tech5\tungsten\game\player\animwebhands.cpp
// ========================================================================

void _unwind_487696()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?InternalGetEdgeCost@idAnimWebHands@@MBAHV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidEdgeIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82DF6188
// RVA : 0x00DF6188
// PDB : w:\tech5\tungsten\game\player\animwebhands.cpp
// ========================================================================

int __fastcall idAnimWebHands::InternalGetEdgeCost(
        idAnimWebHands *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *nodeIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *edgeIndex)
{
  const idDeclAnimWeb *decl; // r3
  __int16 value; // r8
  idDeclAnimWebNode *v6; // r31
  const char *StateName; // r3
  const char *v8; // r3
  int result; // r3
  bool v10; // zf

  decl = this->decl;
  value = decl->edgeCache.list[(__int16)edgeIndex].destNodeIndex.value;
  if ( value == -1 )
    v6 = nullptr;
  else
    v6 = decl->nodes.list[value];
  StateName = idDeclAnimWeb::GetStateName(
                this: decl,
                index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v6->states.stateIndex[0].value);
  if ( idStr::Icmp(s1: StateName, s2: "melee") == 0 )
    return 1000;
  v8 = idDeclAnimWeb::GetStateName(
         this: this->decl,
         index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v6->states.stateIndex[0].value);
  v10 = idStr::Icmp(s1: v8, s2: "shoot") != 0;
  result = 100;
  if ( !v10 )
    return 1000;
  return result;
}

