
// ========================================================================
// ?Cleanup@idPlayerGuis_Render@@QAAXXZ
// EA  : 0x82B62A90
// RVA : 0x00B62A90
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void __fastcall idPlayerGuis_Render::Cleanup(idPlayerGuis_Render *this)
{
  idSWF **guis; // r31
  int i; // r30

  guis = this->guis;
  for ( i = 2; i != 0; --i )
  {
    if ( *guis != nullptr )
      idSWF::ClearEmitter(this: *guis, instant: true);
    ++guis;
  }
}


// ========================================================================
// ?NoteSwfForBuildGame@idPlayerGuis_Render@@SAXXZ
// EA  : 0x82B62AE8
// RVA : 0x00B62AE8
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

static void __fastcall idPlayerGuis_Render::NoteSwfForBuildGame()
{
  idSWF::RegisterSWFResources(filename: "tunggameover");
  if ( common->IsMultiplayer(this: common) )
    idSWF::RegisterSWFResources(filename: "online_textchat");
}


// ========================================================================
// ?DeactivateGuis@idPlayerGuis_Render@@QAAXXZ
// EA  : 0x82B62B40
// RVA : 0x00B62B40
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void __fastcall idPlayerGuis_Render::DeactivateGuis(idPlayerGuis_Render *this)
{
  int v1; // r31
  idSWF **guis; // r30

  v1 = 0;
  guis = this->guis;
  do
  {
    if ( *guis != nullptr && v1 != 0 )
      idSWF::Activate(this: *guis, b: false);
    ++v1;
    ++guis;
  }
  while ( v1 < 2 );
}


// ========================================================================
// ?HandleGuiEvent@idPlayerGuis_Render@@QAA_NPBUsysEvent_t@@@Z
// EA  : 0x82B62BA0
// RVA : 0x00B62BA0
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

int __fastcall idPlayerGuis_Render::HandleGuiEvent(idPlayerGuis_Render *this, const sysEvent_t *ev)
{
  int v3; // r30
  idSWF **i; // r31

  v3 = 1;
  for ( i = &this->guis[1]; *i == nullptr || (unsigned __int8)idSWF::HandleEvent(this: *i, event: ev) == 0; --i )
  {
    if ( --v3 < 0 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?IsPlayerControlInhibited@idPlayerGuis_Render@@QAA_NXZ
// EA  : 0x82B62C00
// RVA : 0x00B62C00
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

int __fastcall idPlayerGuis_Render::IsPlayerControlInhibited(idPlayerGuis_Render *this)
{
  int v1; // r30
  idSWF **i; // r31

  v1 = 0;
  for ( i = this->guis; *i == nullptr || (unsigned __int8)idSWF::IsPlayerControlInhibited(this: *i) == 0; ++i )
  {
    if ( ++v1 >= 2 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?SetPlayerNum@idPlayerGuis_Render@@QAAXH@Z
// EA  : 0x82B62C70
// RVA : 0x00B62C70
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void __fastcall idPlayerGuis_Render::SetPlayerNum(idPlayerGuis_Render *this, int p)
{
  idSWF **guis; // r31
  int i; // r30

  this->playerNum = p;
  guis = this->guis;
  for ( i = 2; i != 0; --i )
  {
    if ( *guis != nullptr )
      idSWF::SetListener(this: *guis, id: p + 1);
    ++guis;
  }
}


// ========================================================================
// ?RenderGame@idPlayerGuis_Render@@QAAXPAVidRenderModelGui@@HPBUrenderView_t@@PBVidRenderWorld@@@Z
// EA  : 0x82B62CB8
// RVA : 0x00B62CB8
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void __fastcall idPlayerGuis_Render::RenderGame(
        idPlayerGuis_Render *this,
        idRenderModelGui *guiModel,
        int currentTime,
        const renderView_t *renderView,
        const idRenderWorld *rw)
{
  const char *v8; // r7
  idSWF *v9; // r3

  if ( common->IsMultiplayer(this: common) || gameLocal == nullptr || !idMainMenu::IsActive(this: gameLocal->mainMenu) )
  {
    v9 = this->guis[1];
    if ( v9 != nullptr )
      idSWF::Render(this: v9, gui: guiModel, time: currentTime, isSplitscreen: false, a5: v8);
  }
}


// ========================================================================
// ?HandleReliableGuiMsg@idPlayerGuis_Render@@QAAXHAAVidBitMsg@@@Z
// EA  : 0x82B62D48
// RVA : 0x00B62D48
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void __fastcall idPlayerGuis_Render::HandleReliableGuiMsg(idPlayerGuis_Render *this, int type, idBitMsg *msg)
{
  int Bits; // r29
  int *p_totalCash; // r30

  if ( type == 19 )
  {
    this->playerGuiInfo.objectiveResults.show = true;
    Bits = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
    if ( Bits != 0 )
    {
      p_totalCash = &this->playerGuiInfo.objectiveResults.totalCash;
      do
      {
        p_totalCash[1] = idBitMsg::ReadBits(this: msg, numBits: 32);
        p_totalCash[2] = idBitMsg::ReadBits(this: msg, numBits: 32);
        p_totalCash[3] = idBitMsg::ReadBits(this: msg, numBits: 32);
        p_totalCash[4] = idBitMsg::ReadBits(this: msg, numBits: 32);
        p_totalCash[5] = idBitMsg::ReadBits(this: msg, numBits: 32);
        p_totalCash[6] = idBitMsg::ReadBits(this: msg, numBits: 32);
        --Bits;
        p_totalCash += 7;
        *p_totalCash = idBitMsg::ReadBits(this: msg, numBits: 32);
      }
      while ( Bits != 0 );
    }
    this->playerGuiInfo.objectiveResults.totalTime = idBitMsg::ReadBits(this: msg, numBits: 32);
    this->playerGuiInfo.objectiveResults.collectibles = idBitMsg::ReadBits(this: msg, numBits: 32);
    this->playerGuiInfo.objectiveResults.collectiblesMax = idBitMsg::ReadBits(this: msg, numBits: 32);
    this->playerGuiInfo.objectiveResults.collectibleBonusScore = idBitMsg::ReadBits(this: msg, numBits: 32);
    this->playerGuiInfo.objectiveResults.finalScore = idBitMsg::ReadBits(this: msg, numBits: 32);
    this->playerGuiInfo.objectiveResults.rating = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
  }
}


// ========================================================================
// ??1idPlayerGuis_Render@@QAA@XZ
// EA  : 0x82B62E78
// RVA : 0x00B62E78
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void __fastcall idPlayerGuis_Render::~idPlayerGuis_Render(idPlayerGuis_Render *this)
{
  idSWF **guis; // r29
  int i; // r27
  idSWF *v4; // r30

  guis = this->guis;
  for ( i = 2; i != 0; --i )
  {
    v4 = *guis;
    if ( *guis != nullptr )
    {
      idSWF::~idSWF(this: *guis);
      idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
      *guis = nullptr;
    }
    ++guis;
  }
  idStr::FreeData(this: &this->textChatHistory);
}


// ========================================================================
// __unwind$488307_0
// EA  : 0x82B62EEC
// RVA : 0x00B62EEC
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488307_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 140));
}


// ========================================================================
// ??0idPlayerGuis_Render@@QAA@XZ
// EA  : 0x82B62F18
// RVA : 0x00B62F18
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

idPlayerGuis_Render *__fastcall idPlayerGuis_Render::idPlayerGuis_Render(idPlayerGuis_Render *this)
{
  this->playerGuiInfo.objectiveResults.playerObjectives[0].score = 0;
  this->playerGuiInfo.objectiveResults.playerObjectives[0].kills = 0;
  this->playerGuiInfo.objectiveResults.playerObjectives[0].multiKills = 0;
  this->playerGuiInfo.objectiveResults.playerObjectives[0].headshotKills = 0;
  this->playerGuiInfo.objectiveResults.playerObjectives[0].assists = 0;
  this->playerGuiInfo.objectiveResults.playerObjectives[0].defends = 0;
  this->playerGuiInfo.objectiveResults.playerObjectives[0].revives = 0;
  this->playerGuiInfo.objectiveResults.playerObjectives[1].score = 0;
  this->playerGuiInfo.objectiveResults.playerObjectives[1].kills = 0;
  this->playerGuiInfo.objectiveResults.playerObjectives[1].multiKills = 0;
  this->playerGuiInfo.objectiveResults.playerObjectives[1].headshotKills = 0;
  this->playerGuiInfo.objectiveResults.playerObjectives[1].assists = 0;
  this->playerGuiInfo.objectiveResults.playerObjectives[1].defends = 0;
  this->playerGuiInfo.objectiveResults.playerObjectives[1].revives = 0;
  this->playerGuiInfo.objectiveResults.show = false;
  this->playerGuiInfo.objectiveResults.earnedCash = 0;
  this->playerGuiInfo.objectiveResults.killCount = 0;
  this->playerGuiInfo.objectiveResults.killBonus = 0;
  this->playerGuiInfo.objectiveResults.itemCount = 0;
  this->playerGuiInfo.objectiveResults.itemBonus = 0;
  this->playerGuiInfo.objectiveResults.collectNum = 0;
  this->playerGuiInfo.objectiveResults.collectMax = 0;
  this->playerGuiInfo.objectiveResults.time = 0;
  this->playerGuiInfo.objectiveResults.parTime = 0;
  this->playerGuiInfo.objectiveResults.bonusCash = 0;
  this->playerGuiInfo.objectiveResults.totalCash = 0;
  this->playerGuiInfo.objectiveResults.totalTime = 0;
  this->playerGuiInfo.objectiveResults.collectibles = 0;
  this->playerGuiInfo.objectiveResults.collectiblesMax = 0;
  this->playerGuiInfo.objectiveResults.collectibleBonusScore = 0;
  this->playerGuiInfo.objectiveResults.finalScore = 0;
  this->textChatHistory.allocedAndFlag = 20;
  this->textChatHistory.data = this->textChatHistory.baseBuffer;
  this->textChatHistory.len = 0;
  this->textChatHistory.baseBuffer[0] = 0;
  this->guis[0] = nullptr;
  this->guis[1] = nullptr;
  this->playerNum = 0;
  return this;
}


// ========================================================================
// `idPlayerGuis_Render::Init'::`15'::idSWFScriptFunction_SendChatText::Call
// EA  : 0x82B62FD0
// RVA : 0x00B62FD0
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idPlayerGuis_Render::Init_::_15_::idSWFScriptFunction_SendChatText::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        __int64 parms,
        __int64 a4,
        __int64 a5)
{
  idSWFScriptVar **v6; // r30
  idStr *v7; // r4
  int v8; // r11
  char v9; // r11
  bool v10; // zf
  int allocedAndFlag; // r11
  char v12; // r11
  messageMode_t v13; // r3
  idStr v15[2]; // [sp+60h] [-40h] BYREF

  v6 = (idSWFScriptVar **)parms;
  if ( *(_DWORD *)(parms + 4) != 2 )
    goto _M488731_2;
  v7 = *(idStr **)parms;
  v8 = **(_DWORD **)parms;
  if ( v8 == 1 || (v10 = v8 != 0, v9 = 0, !v10) )
    v9 = 1;
  if ( v9 == 0 )
    goto _M488731_2;
  allocedAndFlag = v7->allocedAndFlag;
  if ( allocedAndFlag == 2 || allocedAndFlag == 6 || (v10 = allocedAndFlag != 5, v12 = 0, !v10) )
    v12 = 1;
  if ( v12 != 0 )
  {
    LODWORD(a5) = &v7->allocedAndFlag;
    idSWFScriptVar::ToString(this: (idSWFScriptVar *)v15, result: v7, a3: parms, a4, a5);
    v13 = idSWFScriptVar::ToInteger(this: *v6 + 1);
    idClientGame::SendChatText(this: clientGame, text: v15, messagemode: v13);
    idStr::FreeData(this: v15);
  }
  else
  {
_M488731_2:
    idLib::Warning(fmt: "Invalid parameters for sendChatText!");
  }
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// __unwind$488684
// EA  : 0x82B630BC
// RVA : 0x00B630BC
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488684()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// ?SetupBindings@idPlayerGuis_Render@@QAAXXZ
// EA  : 0x82B630F0
// RVA : 0x00B630F0
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void __fastcall idPlayerGuis_Render::SetupBindings(idPlayerGuis_Render *this)
{
  idSWF **v1; // r10
  idSWF *v2; // r27
  idSWFScriptObject *v3; // r3
  idSWFScriptObject *v4; // r28
  idSWF **guis; // [sp+50h] [-150h]
  idSWFScriptVar v7; // [sp+58h] [-148h] BYREF
  idSWFScriptVar v8; // [sp+60h] [-140h] BYREF
  idSWFScriptVar v9; // [sp+68h] [-138h] BYREF
  idSWFScriptVar v10; // [sp+70h] [-130h] BYREF
  idSWFScriptVar v11; // [sp+78h] [-128h] BYREF
  idSWFScriptVar v12; // [sp+80h] [-120h] BYREF
  idSWFScriptVar v13; // [sp+88h] [-118h] BYREF
  idSWFScriptVar v14; // [sp+90h] [-110h] BYREF
  idSWFScriptVar v15; // [sp+98h] [-108h] BYREF
  idSWFScriptVar v16; // [sp+A0h] [-100h] BYREF
  idSWFScriptVar v17; // [sp+A8h] [-F8h] BYREF
  idSWFScriptVar v18; // [sp+B0h] [-F0h] BYREF
  idSWFScriptVar v19; // [sp+B8h] [-E8h] BYREF
  idSWFScriptVar v20; // [sp+C0h] [-E0h] BYREF
  int v21; // [sp+C8h] [-D8h]
  idSWFScriptVar v22; // [sp+D0h] [-D0h] BYREF
  idSWFScriptVar v23; // [sp+D8h] [-C8h] BYREF
  idSWFScriptVar v24; // [sp+E0h] [-C0h] BYREF
  idMem *v25; // [sp+E8h] [-B8h]
  char *v26; // [sp+ECh] [-B4h]
  char *v27; // [sp+F0h] [-B0h]
  char *v28; // [sp+F4h] [-ACh]
  char *v29; // [sp+F8h] [-A8h]

  guis = this->guis;
  v21 = 2;
  v25 = &mem;
  v27 = "SWF_TEXT_RENDER_RANDOM_APPEAR_CAPS";
  v28 = "SWF_TEXT_RENDER_RANDOM_APPEAR";
  v26 = "SWF_TEXT_RENDER_NORMAL";
  v29 = "Keys";
  do
  {
    v1 = guis;
    v2 = *guis;
    if ( *guis != nullptr )
    {
      v3 = idSWFScriptObject::Alloc();
      v13.type = SWF_VAR_UNDEF;
      v4 = v3;
      idSWFScriptVar::Free(this: &v13);
      v13.type = SWF_VAR_INTEGER;
      v13.value.i = 200;
      idSWFScriptObject::Set(this: v4, name: "UP", value: &v13);
      idSWFScriptVar::Free(this: &v13);
      v19.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v19);
      v19.type = SWF_VAR_INTEGER;
      v19.value.i = 208;
      idSWFScriptObject::Set(this: v4, name: "DOWN", value: &v19);
      idSWFScriptVar::Free(this: &v19);
      v15.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v15);
      v15.type = SWF_VAR_INTEGER;
      v15.value.i = 203;
      idSWFScriptObject::Set(this: v4, name: "LEFT", value: &v15);
      idSWFScriptVar::Free(this: &v15);
      v8.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v8);
      v8.type = SWF_VAR_INTEGER;
      v8.value.i = 205;
      idSWFScriptObject::Set(this: v4, name: "RIGHT", value: &v8);
      idSWFScriptVar::Free(this: &v8);
      v23.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v23);
      v23.type = SWF_VAR_INTEGER;
      v23.value.i = 28;
      idSWFScriptObject::Set(this: v4, name: "ENTER", value: &v23);
      idSWFScriptVar::Free(this: &v23);
      v9.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v9);
      v9.type = SWF_VAR_INTEGER;
      v9.value.i = 14;
      idSWFScriptObject::Set(this: v4, name: "BACKSPACE", value: &v9);
      idSWFScriptVar::Free(this: &v9);
      v17.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v17);
      v17.type = SWF_VAR_INTEGER;
      v17.value.i = 15;
      idSWFScriptObject::Set(this: v4, name: "TAB", value: &v17);
      idSWFScriptVar::Free(this: &v17);
      v10.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v10);
      v10.type = SWF_VAR_INTEGER;
      v10.value.i = 258;
      idSWFScriptObject::Set(this: v4, name: "JOY3", value: &v10);
      idSWFScriptVar::Free(this: &v10);
      v12.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v12);
      v12.type = SWF_VAR_INTEGER;
      v12.value.i = 265;
      idSWFScriptObject::Set(this: v4, name: "JOY10", value: &v12);
      idSWFScriptVar::Free(this: &v12);
      v7.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v7);
      if ( v4 != nullptr )
      {
        v7.value.i = (int)v4;
        v7.type = SWF_VAR_OBJECT;
        ++v4->refCount;
      }
      else
      {
        v7.type = SWF_VAR_NULL;
      }
      idSWFScriptObject::Set(this: v2->globals, name: v29, value: &v7);
      idSWFScriptVar::Free(this: &v7);
      if ( v4->refCount-- == 1 )
      {
        idSWFScriptObject::~idSWFScriptObject(this: v4);
        idMem::Free(this: v25, ptr: v4, align: ALIGN_16);
      }
      v14.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v14);
      v14.type = SWF_VAR_INTEGER;
      v14.value.i = 0;
      idSWFScriptObject::Set(this: v2->globals, name: v26, value: &v14);
      idSWFScriptVar::Free(this: &v14);
      v16.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v16);
      v16.type = SWF_VAR_INTEGER;
      v16.value.i = 1;
      idSWFScriptObject::Set(this: v2->globals, name: v28, value: &v16);
      idSWFScriptVar::Free(this: &v16);
      v18.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v18);
      v18.type = SWF_VAR_INTEGER;
      v18.value.i = 2;
      idSWFScriptObject::Set(this: v2->globals, name: v27, value: &v18);
      idSWFScriptVar::Free(this: &v18);
      v20.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v20);
      v20.type = SWF_VAR_INTEGER;
      v20.value.i = 3;
      idSWFScriptObject::Set(this: v2->globals, name: "SWF_TEXT_RENDER_PARAGRAPH", value: &v20);
      idSWFScriptVar::Free(this: &v20);
      v22.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v22);
      v22.type = SWF_VAR_INTEGER;
      v22.value.i = 4;
      idSWFScriptObject::Set(this: v2->globals, name: "SWF_TEXT_RENDER_AUTOSCROLL", value: &v22);
      idSWFScriptVar::Free(this: &v22);
      v24.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v24);
      v24.type = SWF_VAR_INTEGER;
      v24.value.i = 0;
      idSWFScriptObject::Set(this: v2->globals, name: "MESSAGEMODE_ALL", value: &v24);
      idSWFScriptVar::Free(this: &v24);
      v11.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v11);
      v11.type = SWF_VAR_INTEGER;
      v11.value.i = 1;
      idSWFScriptObject::Set(this: v2->globals, name: "MESSAGEMODE_TEAM", value: &v11);
      idSWFScriptVar::Free(this: &v11);
      v1 = guis;
    }
    guis = v1 + 1;
    --v21;
  }
  while ( v21 != 0 );
}


// ========================================================================
// __unwind$488809
// EA  : 0x82B63568
// RVA : 0x00B63568
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488809()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 136));
}


// ========================================================================
// __unwind$488810
// EA  : 0x82B63590
// RVA : 0x00B63590
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488810()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 184));
}


// ========================================================================
// __unwind$488811
// EA  : 0x82B635B8
// RVA : 0x00B635B8
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488811()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 152));
}


// ========================================================================
// __unwind$488812
// EA  : 0x82B635E0
// RVA : 0x00B635E0
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488812()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 96));
}


// ========================================================================
// __unwind$488813
// EA  : 0x82B63608
// RVA : 0x00B63608
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488813()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 216));
}


// ========================================================================
// __unwind$488814
// EA  : 0x82B63630
// RVA : 0x00B63630
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488814()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 104));
}


// ========================================================================
// __unwind$488815
// EA  : 0x82B63658
// RVA : 0x00B63658
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488815()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 168));
}


// ========================================================================
// __unwind$488816
// EA  : 0x82B63680
// RVA : 0x00B63680
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488816()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 112));
}


// ========================================================================
// __unwind$488817
// EA  : 0x82B636A8
// RVA : 0x00B636A8
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488817()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 128));
}


// ========================================================================
// __unwind$488818
// EA  : 0x82B636D0
// RVA : 0x00B636D0
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488818()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 88));
}


// ========================================================================
// __unwind$488819
// EA  : 0x82B636F8
// RVA : 0x00B636F8
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488819()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 144));
}


// ========================================================================
// __unwind$488820
// EA  : 0x82B63720
// RVA : 0x00B63720
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488820()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 160));
}


// ========================================================================
// __unwind$488821
// EA  : 0x82B63748
// RVA : 0x00B63748
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488821()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 176));
}


// ========================================================================
// __unwind$488822
// EA  : 0x82B63770
// RVA : 0x00B63770
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488822()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 192));
}


// ========================================================================
// __unwind$488823
// EA  : 0x82B63798
// RVA : 0x00B63798
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488823()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 208));
}


// ========================================================================
// __unwind$488824
// EA  : 0x82B637C0
// RVA : 0x00B637C0
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488824()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 224));
}


// ========================================================================
// __unwind$488825
// EA  : 0x82B637E8
// RVA : 0x00B637E8
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_488825()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 120));
}


// ========================================================================
// ?Render_TextChat@idPlayerGuis_Render@@AAAXH@Z
// EA  : 0x82B63818
// RVA : 0x00B63818
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void __fastcall idPlayerGuis_Render::Render_TextChat(idPlayerGuis_Render *this, int currentTime)
{
  idSWF *v3; // r3
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r8
  va *v7; // r3
  int v8; // [sp+8h] [-1078h]
  int v9; // [sp+Ch] [-1074h]
  int v10; // [sp+10h] [-1070h]
  int v11; // [sp+14h] [-106Ch]
  int v12; // [sp+18h] [-1068h]
  int v13; // [sp+1Ch] [-1064h]
  idSWFScriptVar v14[2]; // [sp+50h] [-1030h] BYREF
  va v15; // [sp+60h] [-1020h] BYREF

  v3 = this->guis[0];
  if ( v3 != nullptr )
  {
    idSWF::Activate(this: v3, b: true);
    HIDWORD(v4) = this->textChatHistory.data;
    v7 = va::va(this: &v15, fmt: "%s", a3: v4, a4: v6, a5: v5, a6: v8, a7: v9, a8: v10, a9: v11, a10: v12, a11: v13);
    v14[0].type = SWF_VAR_UNDEF;
    idSWFScriptVar::SetString(this: v14, s: v7);
    idSWFScriptObject::Set(this: this->guis[0]->globals, name: "textchathistory", value: v14);
    idSWFScriptVar::Free(this: v14);
  }
}


// ========================================================================
// __unwind$489193
// EA  : 0x82B638AC
// RVA : 0x00B638AC
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_489193()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4224 + 80));
}


// ========================================================================
// ?Init@idPlayerGuis_Render@@QAAXPBVidStr@@@Z
// EA  : 0x82B638E0
// RVA : 0x00B638E0
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void __fastcall idPlayerGuis_Render::Init(idPlayerGuis_Render *this, const idStr *mapName)
{
  idLobbyBase *v3; // r3
  idSWF *v4; // r3
  idSWF *v5; // r3
  idSWF *v6; // r3
  idSWF *v7; // r3
  idSWFScriptFunction *v8; // r3
  idSWFScriptFunction *v9; // r4
  idSWF *v10; // r3
  idSWFScriptVar v11[9]; // [sp+58h] [-48h] BYREF

  if ( !common->IsMultiplayer(this: common)
    || (v3 = session->GetActingGameStateLobbyBase(this: session), v3->GetMatchParms(this: v3)->gameType == 1) )
  {
    v4 = (idSWF *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                    size: 0x27Cu,
                    tag: TAG_SWF,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    if ( v4 != nullptr )
      v5 = idSWF::idSWF(this: v4, filename_: "tunggameover", soundWorld: clientGame->soundWorld, atlasPurgable_: true);
    else
      v5 = nullptr;
    this->guis[1] = v5;
  }
  else
  {
    this->guis[1] = nullptr;
  }
  if ( common->IsMultiplayer(this: common) )
  {
    v6 = (idSWF *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                    size: 0x27Cu,
                    tag: TAG_SWF,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    if ( v6 != nullptr )
      v7 = idSWF::idSWF(
             this: v6,
             filename_: "online_textchat",
             soundWorld: clientGame->soundWorld,
             atlasPurgable_: true);
    else
      v7 = nullptr;
    this->guis[0] = v7;
  }
  else
  {
    this->guis[0] = nullptr;
  }
  if ( this->guis[0] != nullptr )
  {
    v8 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0xCu,
                                  tag: TAG_SWF,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
    if ( v8 != nullptr )
    {
      v8[2].__vftable = (idSWFScriptFunction_vtbl *)this;
      v8[1].__vftable = nullptr;
      v9 = v8;
      v8->__vftable = (idSWFScriptFunction_vtbl *)&`idPlayerGuis_Render::Init'::`15'::idSWFScriptFunction_SendChatText::`vftable';
    }
    else
    {
      v9 = nullptr;
    }
    idSWFScriptVar::idSWFScriptVar(this: v11, nf: v9);
    idSWFScriptObject::Set(this: this->guis[0]->globals, name: "sendChatText", value: v11);
    idSWFScriptVar::Free(this: v11);
  }
  idPlayerGuis_Render::SetupBindings(this);
  idPlayerGuis_Render::DeactivateGuis(this);
  v10 = this->guis[0];
  if ( v10 != nullptr )
    idSWF::Activate(this: v10, b: true);
}


// ========================================================================
// __unwind$489246_0
// EA  : 0x82B63AE0
// RVA : 0x00B63AE0
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_489246_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$489247_0
// EA  : 0x82B63B0C
// RVA : 0x00B63B0C
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_489247_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$489249
// EA  : 0x82B63B38
// RVA : 0x00B63B38
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_489249()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 160 + 88));
}


// ========================================================================
// ?Render@idPlayerGuis_Render@@QAAXPAVidRenderModelGui@@HPBUrenderView_t@@PBVidRenderWorld@@@Z
// EA  : 0x82B63B60
// RVA : 0x00B63B60
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void __fastcall idPlayerGuis_Render::Render(
        idPlayerGuis_Render *this,
        idRenderModelGui *guiModel,
        int currentTime,
        const renderView_t *renderView,
        const idRenderWorld *rw)
{
  const char *v8; // r7
  idSWF *v9; // r3

  idPlayerGuis_Render::Render_TextChat(this, currentTime);
  v9 = this->guis[0];
  if ( v9 != nullptr )
    idSWF::Render(this: v9, gui: guiModel, time: currentTime, isSplitscreen: false, a5: v8);
}


// ========================================================================
// ?Call@idSWFScriptFunction_CancelChatting@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82B63BB0
// RVA : 0x00B63BB0
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

idSWFScriptFunction_CancelChatting *__fastcall idSWFScriptFunction_CancelChatting::Call(
        idSWFScriptFunction_CancelChatting *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject *v5; // r30
  idSWFScriptObject v7[2]; // [sp+50h] [-D0h] BYREF

  v7[0].variables.num = 0;
  v5 = *(idSWFScriptObject **)(*(_DWORD *)(result[1].type + 64) + 40);
  idSWFScriptObject::Get(this: v7, result: v5, name: "Activate");
  if ( v7[0].refCount == 7 )
  {
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v7[0].variablesHash[3]);
    idSWFParmList::Append(this: (idSWFParmList *)&v7[0].variablesHash[3], b: false);
    (*(void (__fastcall **)(__int16 *, idSWFScriptObject::swfNamedVar_t *, idSWFScriptObject *, int *))(v7[0].variables.list->index + 4))(
      a1: &v7[0].variables.granularity,
      a2: v7[0].variables.list,
      a3: v5,
      a4: &v7[0].variablesHash[3]);
    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v7[0].variables.granularity);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v7[0].variablesHash[3]);
  }
  this->__vftable = (idSWFScriptFunction_CancelChatting_vtbl *)4;
  v7[0].variables.num = 1;
  idSWFScriptVar::Free(this: (idSWFScriptVar *)v7);
  return this;
}


// ========================================================================
// __unwind$489400_0
// EA  : 0x82B63C64
// RVA : 0x00B63C64
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_489400_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 80));
}


// ========================================================================
// __unwind$489401
// EA  : 0x82B63C8C
// RVA : 0x00B63C8C
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_489401()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$489403
// EA  : 0x82B63CB4
// RVA : 0x00B63CB4
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_489403()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 288;
  if ( (*(_DWORD *)(v0 - 288 + 88) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 88) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 308));
  }
}


// ========================================================================
// ?DisplayTextChatEntry@idPlayerGuis_Render@@QAAXXZ
// EA  : 0x82B63D00
// RVA : 0x00B63D00
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void __fastcall idPlayerGuis_Render::DisplayTextChatEntry(idPlayerGuis_Render *this)
{
  idSWFScriptFunction *v2; // r3
  idSWF *v3; // r11
  idSWFScriptFunction *v4; // r4
  idSWFScriptVar v5; // [sp+50h] [-C0h] BYREF
  idSWFScriptVar v6; // [sp+58h] [-B8h] BYREF
  idStaticList<idSWFScriptVar,16> v7; // [sp+60h] [-B0h] BYREF

  if ( this->guis[0] != nullptr )
  {
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v7);
    idSWF::Invoke(this: this->guis[0], functionName: "ShowTextChatBox", parms: (const idSWFParmList *)&v7);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v7);
    idSWF::GetGlobal(this: (idSWF *)&v5, result: (idSWFScriptVar *)this->guis[0], name: "shortcutKeys");
    if ( v5.type == SWF_VAR_OBJECT )
    {
      v2 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0xCu,
                                    tag: TAG_SWF,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
      if ( v2 != nullptr )
      {
        v3 = this->guis[0];
        v2[1].__vftable = nullptr;
        v4 = v2;
        v2->__vftable = (idSWFScriptFunction_vtbl *)&idSWFScriptFunction_CancelChatting::`vftable';
        v2[2].__vftable = (idSWFScriptFunction_vtbl *)v3;
      }
      else
      {
        v4 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v6, nf: v4);
      idSWFScriptObject::Set(this: v5.value.object, name: "ESCAPE", value: &v6);
      idSWFScriptVar::Free(this: &v6);
    }
    idSWFScriptVar::Free(this: &v5);
  }
}


// ========================================================================
// __unwind$489471
// EA  : 0x82B63E08
// RVA : 0x00B63E08
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_489471()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$489472
// EA  : 0x82B63E30
// RVA : 0x00B63E30
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_489472()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$489474_0
// EA  : 0x82B63E58
// RVA : 0x00B63E58
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_489474_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 272 + 88));
}


// ========================================================================
// ?DisplayTeamTextChatEntry@idPlayerGuis_Render@@QAAXXZ
// EA  : 0x82B63E88
// RVA : 0x00B63E88
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void __fastcall idPlayerGuis_Render::DisplayTeamTextChatEntry(idPlayerGuis_Render *this)
{
  idSWFScriptFunction *v2; // r3
  idSWF *v3; // r11
  idSWFScriptFunction *v4; // r4
  idSWFScriptVar v5; // [sp+50h] [-C0h] BYREF
  idSWFScriptVar v6; // [sp+58h] [-B8h] BYREF
  idStaticList<idSWFScriptVar,16> v7; // [sp+60h] [-B0h] BYREF

  if ( this->guis[0] != nullptr )
  {
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v7);
    idSWF::Invoke(this: this->guis[0], functionName: "ShowTeamTextChatBox", parms: (const idSWFParmList *)&v7);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v7);
    idSWF::GetGlobal(this: (idSWF *)&v5, result: (idSWFScriptVar *)this->guis[0], name: "shortcutKeys");
    if ( v5.type == SWF_VAR_OBJECT )
    {
      v2 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0xCu,
                                    tag: TAG_SWF,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
      if ( v2 != nullptr )
      {
        v3 = this->guis[0];
        v2[1].__vftable = nullptr;
        v4 = v2;
        v2->__vftable = (idSWFScriptFunction_vtbl *)&idSWFScriptFunction_CancelChatting::`vftable';
        v2[2].__vftable = (idSWFScriptFunction_vtbl *)v3;
      }
      else
      {
        v4 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v6, nf: v4);
      idSWFScriptObject::Set(this: v5.value.object, name: "ESCAPE", value: &v6);
      idSWFScriptVar::Free(this: &v6);
    }
    idSWFScriptVar::Free(this: &v5);
  }
}


// ========================================================================
// __unwind$489549
// EA  : 0x82B63F90
// RVA : 0x00B63F90
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_489549()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$489550
// EA  : 0x82B63FB8
// RVA : 0x00B63FB8
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_489550()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$489552
// EA  : 0x82B63FE0
// RVA : 0x00B63FE0
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_489552()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 272 + 88));
}


// ========================================================================
// ?DisplayTextChatMessage@idPlayerGuis_Render@@QAAXABVidStr@@@Z
// EA  : 0x82B64010
// RVA : 0x00B64010
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void __fastcall idPlayerGuis_Render::DisplayTextChatMessage(idPlayerGuis_Render *this, const idStr *message)
{
  idStr *p_textChatHistory; // r29
  idSWFScriptVar v5[2]; // [sp+50h] [-D0h] BYREF
  idStaticList<idSWFScriptVar,16> v6; // [sp+60h] [-C0h] BYREF

  if ( this->guis[0] != nullptr )
  {
    p_textChatHistory = &this->textChatHistory;
    idStr::Append(this: &this->textChatHistory, text: "\n");
    idStr::Append(this: p_textChatHistory, text: message);
    idSWF::Activate(this: this->guis[0], b: true);
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v6);
    v5[0].type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: v5);
    v5[0].type = SWF_VAR_STRING;
    v5[0].value.i = (int)idSWFScriptString::Alloc(s: message);
    idSWFParmList::Append(this: (idSWFParmList *)&v6, other: v5);
    idSWFScriptVar::Free(this: v5);
    idSWF::Invoke(this: this->guis[0], functionName: "TextChatUpdated", parms: (const idSWFParmList *)&v6);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v6);
  }
}


// ========================================================================
// __unwind$489622
// EA  : 0x82B640C4
// RVA : 0x00B640C4
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_489622()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 288 + 96));
}


// ========================================================================
// __unwind$489623
// EA  : 0x82B640EC
// RVA : 0x00B640EC
// PDB : w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.cpp
// ========================================================================

void _unwind_489623()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 80));
}

