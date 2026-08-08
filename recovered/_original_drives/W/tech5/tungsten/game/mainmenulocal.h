
// ========================================================================
// ??0mpMapMode_t@@QAA@XZ
// EA  : 0x825927D0
// RVA : 0x005927D0
// PDB : w:\tech5\tungsten\game\mainmenulocal.h
// ========================================================================

mpMapMode_t *__fastcall mpMapMode_t::mpMapMode_t(mpMapMode_t *this)
{
  this->name.index = -1;
  this->description.index = -1;
  this->layer.allocedAndFlag = 20;
  this->layer.len = 0;
  this->layer.data = this->layer.baseBuffer;
  this->layer.baseBuffer[0] = 0;
  this->menuMaterial.allocedAndFlag = 20;
  this->menuMaterial.len = 0;
  this->menuMaterial.data = this->menuMaterial.baseBuffer;
  this->menuMaterial.baseBuffer[0] = 0;
  this->menuIndex = 0;
  this->titleStorageModeName.allocedAndFlag = 20;
  this->titleStorageModeName.len = 0;
  this->titleStorageModeName.data = this->titleStorageModeName.baseBuffer;
  this->titleStorageModeName.baseBuffer[0] = 0;
  this->cashRequired = 0;
  this->levelRequired = 0;
  this->unlockStatRequired = RAGE_STAT_INVALID;
  idStrId::Set(this: &this->unlockDescription, key: &byte_8200D768);
  this->challengeNightmareCompletionStat = RAGE_STAT_INVALID;
  this->challengeCompletionStats.list = nullptr;
  this->challengeCompletionStats.granularity = 0;
  this->challengeCompletionStats.memTag = 5;
  this->challengeCompletionStats.listStatic = 0;
  this->challengeCompletionStats.size = 0;
  this->challengeCompletionStats.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->challengeCompletionStats);
  this->challengeCollectionStat = RAGE_STAT_INVALID;
  this->challengeSpecialCollectionStat = RAGE_STAT_INVALID;
  this->challengeLeaderboardId = -1;
  this->isTeamGame = false;
  return this;
}


// ========================================================================
// __unwind$689278
// EA  : 0x825928B0
// RVA : 0x005928B0
// PDB : w:\tech5\tungsten\game\mainmenulocal.h
// ========================================================================

void _unwind_689278()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// __unwind$689279
// EA  : 0x825928DC
// RVA : 0x005928DC
// PDB : w:\tech5\tungsten\game\mainmenulocal.h
// ========================================================================

void _unwind_689279()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 40));
}


// ========================================================================
// __unwind$689280
// EA  : 0x82592908
// RVA : 0x00592908
// PDB : w:\tech5\tungsten\game\mainmenulocal.h
// ========================================================================

void _unwind_689280()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 76));
}


// ========================================================================
// ??0actionRepeater_t@idMainMenu@@QAA@XZ
// EA  : 0x82DB18D8
// RVA : 0x00DB18D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.h
// ========================================================================

idMainMenu::actionRepeater_t *__fastcall idMainMenu::actionRepeater_t::actionRepeater_t(
        idMainMenu::actionRepeater_t *this)
{
  this->widget = nullptr;
  this->event.type = WIDGET_EVENT_PRESS;
  this->event.arg = 0;
  this->event.thisObject = nullptr;
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &this->event.parms.idStaticList<idSWFScriptVar,16>);
  this->action.action = WIDGET_ACTION_NONE;
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &this->action.parms.idStaticList<idSWFScriptVar,16>);
  this->action.scriptFunction = nullptr;
  this->numRepetitions = 0;
  this->nextRepeatTime = 0;
  this->menu = MENU_AREA_INVALID;
  this->isActive = false;
  return this;
}


// ========================================================================
// __unwind$536825
// EA  : 0x82DB1944
// RVA : 0x00DB1944
// PDB : w:\tech5\tungsten\game\mainmenulocal.h
// ========================================================================

void _unwind_536825()
{
  int v0; // r12

  idWidgetEvent::~idWidgetEvent(this: (idWidgetEvent *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ??0lobbyPlayerInfo_t@@QAA@XZ
// EA  : 0x82DBE828
// RVA : 0x00DBE828
// PDB : w:\tech5\tungsten\game\mainmenulocal.h
// ========================================================================

lobbyPlayerInfo_t *__fastcall lobbyPlayerInfo_t::lobbyPlayerInfo_t(lobbyPlayerInfo_t *this)
{
  this->name.len = 0;
  this->name.data = this->name.baseBuffer;
  this->name.allocedAndFlag = 20;
  this->name.baseBuffer[0] = 0;
  this->isMasterLocalUser = false;
  this->isPartyMember = false;
  this->partyToken = 0;
  this->sessionUserIndex = 0;
  this->level = 1;
  this->qosState = QOS_STATE_GREAT;
  this->voiceState = VOICECHAT_DISPLAY_NONE;
  return this;
}

