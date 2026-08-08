
// ========================================================================
// ?ForceMenuArea@idMainMenu@@AAAXW4menuArea_t@@@Z
// EA  : 0x82DA1B60
// RVA : 0x00DA1B60
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::ForceMenuArea(idMainMenu *this, menuArea_t newMenuArea)
{
  if ( newMenuArea != this->menuArea && newMenuArea == MENU_PRESS_START )
  {
    session->MoveToPressStart(this: session);
    this->askedForSignIn = false;
  }
  this->desiredMenuArea = newMenuArea;
  this->menuArea = newMenuArea;
}


// ========================================================================
// ?WarningShown@idMainMenu@@QAAX_N@Z
// EA  : 0x82DA1BD0
// RVA : 0x00DA1BD0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::WarningShown(idMainMenu *this, bool allowAutosave)
{
  this->autosaveWarningShownAllowsAutosave = allowAutosave;
  this->autosaveWarningShown = true;
}


// ========================================================================
// ?IsStorageRequirementMet@idMainMenu@@QAA_NAA_J@Z
// EA  : 0x82DA1BE0
// RVA : 0x00DA1BE0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

int __fastcall idMainMenu::IsStorageRequirementMet(idMainMenu *this, __int64 *neededBytes)
{
  idLocalUser *v3; // r3
  idLocalUser *v4; // r31
  idLocalUser_vtbl *v5; // r30
  int v6; // r3

  v3 = common->GetMasterLocalUser(this: common);
  v4 = v3;
  if ( v3 == nullptr || !v3->IsStorageDeviceAvailable(this: v3) )
    return 0;
  v5 = v4->__vftable;
  v6 = gameLocal->GetMinSaveStorageRequired(this: gameLocal, a2: true);
  return ((int (__fastcall *)(idLocalUser *, int, __int64 *))v5->StorageSizeAvailable)(a1: v4, a2: v6, a3: neededBytes);
}


// ========================================================================
// ?CanScrollMenu@idMainMenu@@QAA_NXZ
// EA  : 0x82DA1C80
// RVA : 0x00DA1C80
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

int __fastcall idMainMenu::CanScrollMenu(idMainMenu *this)
{
  if ( (signed int)Sys_Milliseconds() <= this->nextScrollTime )
    return 0;
  this->nextScrollTime = Sys_Milliseconds() + this->scrollSpeed;
  return 1;
}


// ========================================================================
// ?SetScrollSpeed@idMainMenu@@QAAXH@Z
// EA  : 0x82DA1CE8
// RVA : 0x00DA1CE8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::SetScrollSpeed(idMainMenu *this, int index)
{
  int v2; // r11

  switch ( index )
  {
    case 1:
      this->scrollSpeed = 15;
      break;
    case 2:
      this->scrollSpeed = 0;
      break;
    case 3:
      this->scrollSpeed = 50;
      break;
    case -1:
      this->nextScrollTime = 0;
      break;
    default:
      v2 = 140;
      if ( index != 4 )
        v2 = 210;
      this->scrollSpeed = v2;
      break;
  }
}


// ========================================================================
// ?UnlockProgressAll_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82DA1D50
// RVA : 0x00DA1D50
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall UnlockProgressAll_f(const idCmdArgs *args)
{
  idPlayerProfileGame *v1; // r3

  v1 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v1 != nullptr )
    idPlayerProfileGame::SetAllProgress(this: v1);
}


// ========================================================================
// ?UnlockSecretAll_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82DA1D90
// RVA : 0x00DA1D90
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall UnlockSecretAll_f(const idCmdArgs *args)
{
  idPlayerProfileGame *v1; // r3

  v1 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v1 != nullptr )
    idPlayerProfileGame::SetAllSecrets(this: v1);
}


// ========================================================================
// ?ClearSecretAll_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82DA1DD0
// RVA : 0x00DA1DD0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall ClearSecretAll_f(const idCmdArgs *args)
{
  idPlayerProfileGame *v1; // r3

  v1 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v1 != nullptr )
    idPlayerProfileGame::ClearSecrets(this: v1);
}


// ========================================================================
// ?ArgCompletion_SWF@@YAXAAVidAutoComplete@@@Z
// EA  : 0x82DA1E10
// RVA : 0x00DA1E10
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall ArgCompletion_SWF(idAutoComplete *autoComplete)
{
  cmdSystem->ArgCompletion_FolderExtension(this: cmdSystem, a2: autoComplete, a3: "swf/", a4: "swf", a5: true);
}


// ========================================================================
// ?ShowPartySessions_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82DA1E40
// RVA : 0x00DA1E40
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall ShowPartySessions_f(const idCmdArgs *args)
{
  session->ShowPartySessions(this: session);
}


// ========================================================================
// ?ForceActiveMenu@idMainMenu@@QAAXW4mainMenuScreens_t@@@Z
// EA  : 0x82DA1E58
// RVA : 0x00DA1E58
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::ForceActiveMenu(idMainMenu *this, mainMenuScreens_t newMenuArea)
{
  if ( newMenuArea != this->activeMenu && newMenuArea == MENU_START )
  {
    session->MoveToPressStart(this: session);
    this->askedForSignIn = false;
  }
  this->nextMenu = newMenuArea;
}


// ========================================================================
// ?AdjustSetting@idMainMenu@@QAAX_N@Z
// EA  : 0x82DA1EC8
// RVA : 0x00DA1EC8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::AdjustSetting(idMainMenu *this, bool less)
{
  if ( this->activeMenu == MENU_AUDIO )
    idMainMenu::DisplayAudioValues(this, index: this->menuIndex[6], less, set: true);
}


// ========================================================================
// ?PumpWidgetActionRepeater@idMainMenu@@QAAXXZ
// EA  : 0x82DA1EE8
// RVA : 0x00DA1EE8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::PumpWidgetActionRepeater(idMainMenu *this)
{
  mainMenuScreens_t activeMenu; // r11
  int v3; // r11
  idMenuWidget *widget; // r3

  if ( this->actionRepeater.isActive )
  {
    activeMenu = this->activeMenu;
    if ( activeMenu == this->actionRepeater.menu
      && this->nextMenu == activeMenu
      && !common->IsDialogActive(this: common) )
    {
      if ( this->actionRepeater.nextRepeatTime <= (signed int)Sys_Milliseconds() )
      {
        if ( this->actionRepeater.numRepetitions != 0 )
          v3 = Sys_Milliseconds() + 150;
        else
          v3 = Sys_Milliseconds() + 400;
        widget = this->actionRepeater.widget;
        this->actionRepeater.nextRepeatTime = v3;
        if ( widget != nullptr )
        {
          widget->HandleAction(this: widget, a2: &this->actionRepeater.action, a3: &this->actionRepeater.event);
          ++this->actionRepeater.numRepetitions;
        }
      }
    }
    else
    {
      this->actionRepeater.isActive = false;
    }
  }
}


// ========================================================================
// ?ClearWidgetActionRepeater@idMainMenu@@QAAXXZ
// EA  : 0x82DA1FE0
// RVA : 0x00DA1FE0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::ClearWidgetActionRepeater(idMainMenu *this)
{
  this->actionRepeater.isActive = false;
}


// ========================================================================
// ?IsActive@idMainMenu@@QBA_NXZ
// EA  : 0x82DA2128
// RVA : 0x00DA2128
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

int __fastcall idMainMenu::IsActive(idMainMenu *this)
{
  idSWF *mainMenu; // r11
  idSWF *testGui; // r11
  idSWF *popupGui; // r11
  unsigned __int8 v4; // r11

  mainMenu = this->mainMenu;
  if ( mainMenu != nullptr && mainMenu->isActive )
    return 1;
  testGui = this->testGui;
  if ( testGui != nullptr && testGui->isActive )
    return 1;
  popupGui = this->popupGui;
  if ( popupGui != nullptr && popupGui->isActive )
    return 1;
  if ( this->deferredActivateMsec != 0 )
    return 1;
  v4 = 0;
  if ( this->deferredDeactivateMsec != 0 )
    return 1;
  return v4;
}


// ========================================================================
// ?NeedsDiskSwap@idMainMenu@@QAA_N_N@Z
// EA  : 0x82DA2198
// RVA : 0x00DA2198
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

int __fastcall idMainMenu::NeedsDiskSwap(idMainMenu *this, bool singlePlayerSelected)
{
  if ( discSwapper_enable.valueInteger == 0 )
    return 0;
  this->singlePlayerSelected = singlePlayerSelected;
  if ( resourceManager->GetCurrentDiscNumber(this: resourceManager) == 3 || singlePlayerSelected )
    return 0;
  idDiscSwapManager::Reset(this: discSwapMgr);
  idDiscSwapManager::Swap(this: discSwapMgr, command: DSC_MAIN_MENU, forceDiscNumber: (idResource *)3);
  this->diskSwapInputLock = true;
  idSaveGameManager::CancelAllProcessors(this: session->saveGameManager, forceCancelInFlightProcessor: true);
  return 1;
}


// ========================================================================
// ?MpToSpDiscSwapCheck@idMainMenu@@QAA_NXZ
// EA  : 0x82DA2258
// RVA : 0x00DA2258
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

int __fastcall idMainMenu::MpToSpDiscSwapCheck(idMainMenu *this)
{
  if ( discSwapper_enable.valueInteger == 0 || resourceManager->GetCurrentDiscNumber(this: resourceManager) == 1 )
    return 0;
  idDiscSwapManager::Reset(this: discSwapMgr);
  idDiscSwapManager::Swap(this: discSwapMgr, command: DSC_MAIN_MENU, forceDiscNumber: (idResource *)1);
  this->diskSwapInputLock = true;
  return 1;
}


// ========================================================================
// ?IgnoreSplitScreenEvent@idMainMenu@@QAA_NPBUsysEvent_t@@@Z
// EA  : 0x82DA22F0
// RVA : 0x00DA22F0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

int __fastcall idMainMenu::IgnoreSplitScreenEvent(idMainMenu *this, const sysEvent_t *sev)
{
  idSWF *mainMenu; // r11
  int result; // r3
  bool v5; // zf

  if ( this->pauseMenuState != PAUSEMENU_MULTI_COOP )
    return 0;
  mainMenu = this->mainMenu;
  if ( mainMenu == nullptr )
    return 0;
  if ( !mainMenu->isActive )
    return 0;
  if ( !gameLocal->IsGameActive(this: gameLocal) )
    return 0;
  v5 = sev->inputDevice != common->GetPauseMenuDeviceNum(this: common);
  result = 1;
  if ( !v5 )
    return 0;
  return result;
}


// ========================================================================
// ?SetMainMenuGlobal@idMainMenu@@QAAXABVidStr@@ABVidSWFScriptVar@@@Z
// EA  : 0x82DA2390
// RVA : 0x00DA2390
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::SetMainMenuGlobal(idMainMenu *this, const idStr *name, idSWFScriptVar *value)
{
  idSWF *mainMenu; // r11

  mainMenu = this->mainMenu;
  if ( mainMenu != nullptr )
    idSWFScriptObject::Set(this: mainMenu->globals, name: name->data, value);
}


// ========================================================================
// ?UnlockProgress_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82DA23B0
// RVA : 0x00DA23B0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall UnlockProgress_f(const idCmdArgs *args)
{
  const char *v1; // r3
  int v2; // r31
  idPlayerProfileGame *v3; // r3

  if ( args->argc <= 1 )
    v1 = &byte_8200D768;
  else
    v1 = args->argv[1];
  v2 = atol(nptr: v1);
  v3 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v3 != nullptr )
    idPlayerProfileGame::SetProgress(this: v3, variationId: v2);
}


// ========================================================================
// ?UnlockSecret_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82DA2420
// RVA : 0x00DA2420
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall UnlockSecret_f(const idCmdArgs *args)
{
  const char *v1; // r3
  int v2; // r31
  idPlayerProfileGame *v3; // r3

  if ( args->argc <= 1 )
    v1 = &byte_8200D768;
  else
    v1 = args->argv[1];
  v2 = atol(nptr: v1);
  v3 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v3 != nullptr )
    idPlayerProfileGame::SetSecret(this: v3, secretId: v2);
}


// ========================================================================
// ?TestPlayerProfile_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82DA2490
// RVA : 0x00DA2490
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall TestPlayerProfile_f(const idCmdArgs *args)
{
  idMainMenu::TestPlayerProfile(this: gameLocal->mainMenu);
}


// ========================================================================
// ?testDiskSwap_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82DA24A8
// RVA : 0x00DA24A8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall testDiskSwap_f(const idCmdArgs *args)
{
  idMainMenu::NeedsDiskSwap(this: gameLocal->mainMenu, singlePlayerSelected: false);
}


// ========================================================================
// ?HideButtonBar@idMainMenu@@QAAXXZ
// EA  : 0x82DA24C8
// RVA : 0x00DA24C8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::HideButtonBar(idMainMenu *this)
{
  idSWFSpriteInstance *NestedSprite; // r3

  NestedSprite = idSWFScriptObject::GetNestedSprite(
                   this: this->mainMenu->mainspriteInstance->scriptObject,
                   arg1: "cmdBar",
                   arg2: nullptr,
                   arg3: nullptr,
                   arg4: nullptr,
                   arg5: nullptr,
                   arg6: nullptr);
  if ( NestedSprite != nullptr )
    idSWFSpriteInstance::SetVisible(this: NestedSprite, visible: false);
}


// ========================================================================
// ?SetActiveMenu@idMainMenu@@QAAXW4mainMenuScreens_t@@@Z
// EA  : 0x82DA2520
// RVA : 0x00DA2520
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::SetActiveMenu(idMainMenu *this, mainMenuScreens_t newMenuArea)
{
  int valueInteger; // r11

  if ( this->nextMenu == newMenuArea || newMenuArea != MENU_START )
  {
    this->nextMenu = newMenuArea;
  }
  else
  {
    valueInteger = com_multiplayer.valueInteger;
    this->nextMenu = MENU_START;
    if ( valueInteger != 0 )
      this->menuRequest = MENU_SWITCH_SP;
  }
}


// ========================================================================
// ?GetMenuSprite@idMainMenu@@QAAPAVidSWFSpriteInstance@@W4mainMenuScreens_t@@@Z
// EA  : 0x82DA2560
// RVA : 0x00DA2560
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFSpriteInstance *__fastcall idMainMenu::GetMenuSprite(idMainMenu *this, unsigned int type)
{
  idSWFScriptObject *scriptObject; // r3

  scriptObject = this->mainMenu->mainspriteInstance->scriptObject;
  if ( type > 6 )
    return nullptr;
  switch ( type )
  {
    case 1u:
      return idSWFScriptObject::GetNestedSprite(
               this: scriptObject,
               arg1: "mainMenu",
               arg2: nullptr,
               arg3: nullptr,
               arg4: nullptr,
               arg5: nullptr,
               arg6: nullptr);
    case 2u:
      return idSWFScriptObject::GetNestedSprite(
               this: scriptObject,
               arg1: "devMenu",
               arg2: nullptr,
               arg3: nullptr,
               arg4: nullptr,
               arg5: nullptr,
               arg6: nullptr);
    case 3u:
    case 4u:
      return nullptr;
    case 5u:
      return idSWFScriptObject::GetNestedSprite(
               this: scriptObject,
               arg1: "settingsMenu",
               arg2: nullptr,
               arg3: nullptr,
               arg4: nullptr,
               arg5: nullptr,
               arg6: nullptr);
    default:
      break;
  }
  if ( type != 0 )
    return idSWFScriptObject::GetNestedSprite(
             this: scriptObject,
             arg1: "audioMenu",
             arg2: nullptr,
             arg3: nullptr,
             arg4: nullptr,
             arg5: nullptr,
             arg6: nullptr);
  return idSWFScriptObject::GetNestedSprite(
           this: scriptObject,
           arg1: "startMenu",
           arg2: nullptr,
           arg3: nullptr,
           arg4: nullptr,
           arg5: nullptr,
           arg6: nullptr);
}


// ========================================================================
// ?GetActiveMenu@idMainMenu@@QAAPAVidSWFScriptObject@@XZ
// EA  : 0x82DA2640
// RVA : 0x00DA2640
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptObject *__fastcall idMainMenu::GetActiveMenu(idMainMenu *this)
{
  idSWFSpriteInstance *MenuSprite; // r3

  MenuSprite = idMainMenu::GetMenuSprite(this, type: this->activeMenu);
  if ( MenuSprite != nullptr )
    return MenuSprite->scriptObject;
  else
    return nullptr;
}


// ========================================================================
// ?SyncMenuStateWithSession@idMainMenu@@AAAXW4sessionState_t@idSession@@@Z
// EA  : 0x82DA2918
// RVA : 0x00DA2918
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::SyncMenuStateWithSession(idMainMenu *this, unsigned int sessionState)
{
  mainMenuScreens_t activeMenu; // r11
  idLobbyBase *v4; // r3
  unsigned __int8 v5; // r3
  menuArea_t desiredMenuArea; // r4
  menuArea_t v7; // r11
  idLobbyBase *v8; // r3
  unsigned __int8 v9; // r3

  if ( sessionState > 8 )
  {
    idLib::Error(fmt: "idMainMenu::SyncMenuStateWithSession: Unknown state.\n");
    JUMPOUT(0x82DA2B24);
  }
  if ( sessionState != 1 )
  {
    switch ( sessionState )
    {
      case 2u:
      case 3u:
        this->menuRequest = MENU_SWITCH_MP;
        this->desiredMenuArea = MENU_WAITING;
        return;
      case 4u:
        this->menuRequest = MENU_SWITCH_MP;
        v4 = session->GetPartyLobbyBase(this: session);
        v5 = v4->IsHost(this: v4);
        desiredMenuArea = this->desiredMenuArea;
        v7 = ((_cntlzw(v5) & 0x20) != 0) + 3;
        break;
      case 5u:
        this->menuRequest = MENU_SWITCH_MP;
        v8 = session->GetGameLobbyBase(this: session);
        v9 = v8->IsHost(this: v8);
        desiredMenuArea = this->desiredMenuArea;
        v7 = ((_cntlzw(v9) & 0x20) != 0) + 5;
        break;
      case 0u:
        if ( com_multiplayer.valueInteger == 0 && swf_useDataDrivenMenus.valueInteger != 0 )
        {
          this->nextMenu = MENU_START;
          return;
        }
        if ( this->desiredMenuArea != MENU_PRESS_START && com_multiplayer.valueInteger != 0 )
          this->menuRequest = MENU_SWITCH_SP;
        v7 = MENU_PRESS_START;
        goto LABEL_27;
      default:
        return;
    }
    if ( desiredMenuArea != v7 && v7 == MENU_PRESS_START && com_multiplayer.valueInteger != 0 )
      this->menuRequest = MENU_SWITCH_SP;
LABEL_27:
    this->desiredMenuArea = v7;
    return;
  }
  if ( com_multiplayer.valueInteger != 0 || swf_useDataDrivenMenus.valueInteger == 0 )
  {
    v7 = MENU_MAIN;
    goto LABEL_27;
  }
  activeMenu = this->activeMenu;
  if ( activeMenu == MENU_START || activeMenu == MENU_AREA_INVALID )
    this->nextMenu = MENU_ROOT;
}


// ========================================================================
// `idMainMenu::RebindAction'::`52'::idSWFScriptFunction_AcceptBind::idSWFScriptFunction_AcceptBind
// EA  : 0x82DA2BF0
// RVA : 0x00DA2BF0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall _idMainMenu::RebindAction_::_52_::idSWFScriptFunction_AcceptBind::idSWFScriptFunction_AcceptBind(
        idMainMenu *_menu,
        idSWF *_swf,
        idSWFScriptObject *_action,
        idStr *_oldAction,
        idStr *_keyNum,
        idSWFScriptVar::swfScriptVarValue_t _bindSet,
        idSWFScriptVar::swfScriptVarType _ininputDevice,
        idPlayerProfile *_profile,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idSWFScriptVar *a28)
{
  idStr *p_num; // r3
  size_t len; // r27
  size_t v36; // r28

  _menu->actionRepeater.event.type = WIDGET_EVENT_PRESS;
  _menu->actionRepeater.widget = (idMenuWidget *)&`idMainMenu::RebindAction'::`52'::idSWFScriptFunction_AcceptBind::`vftable';
  *(_DWORD *)&_menu->actionRepeater.event.parms.granularity = 20;
  p_num = (idStr *)&_menu->actionRepeater.event.parms.num;
  _menu->actionRepeater.event.parms.size = (int)p_num->baseBuffer;
  _menu->actionRepeater.event.parms.num = 0;
  HIBYTE(_menu->actionRepeater.event.parms.staticList[0].type) = 0;
  _menu->actionRepeater.event.parms.staticList[3].value.i = 20;
  _menu->actionRepeater.event.parms.staticList[2].value.i = 0;
  _menu->actionRepeater.event.parms.staticList[3].type = (idSWFScriptVar::swfScriptVarType)&_menu->actionRepeater.event.parms.staticList[4];
  HIBYTE(_menu->actionRepeater.event.parms.staticList[4].type) = 0;
  _menu->actionRepeater.event.arg = (int)_swf;
  _menu->actionRepeater.event.thisObject = _action;
  len = _oldAction->len;
  idStr::EnsureAlloced(this: p_num, amount: _oldAction->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: (void *)_menu->actionRepeater.event.parms.size, Src: _oldAction->data, Size: len);
  *(_BYTE *)(_menu->actionRepeater.event.parms.size + len) = 0;
  _menu->actionRepeater.event.parms.num = len;
  v36 = _keyNum->len;
  idStr::EnsureAlloced(
    this: (idStr *)&_menu->actionRepeater.event.parms.staticList[2].value,
    amount: _keyNum->len + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: (void *)_menu->actionRepeater.event.parms.staticList[3].type, Src: _keyNum->data, Size: v36);
  *(_BYTE *)(_menu->actionRepeater.event.parms.staticList[3].type + v36) = 0;
  _menu->actionRepeater.event.parms.staticList[2].value.i = v36;
  _menu->actionRepeater.event.parms.staticList[6].value = _bindSet;
  _menu->actionRepeater.event.parms.staticList[7].type = _ininputDevice;
  _menu->actionRepeater.event.parms.staticList[7].value.i = (int)_profile;
  _menu->actionRepeater.event.parms.list = a28;
  idStr::FreeData(this: _oldAction);
  idStr::FreeData(this: _keyNum);
}


// ========================================================================
// __unwind$520481
// EA  : 0x82DA2D18
// RVA : 0x00DA2D18
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_520481()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 176 + 228));
}


// ========================================================================
// __unwind$520482
// EA  : 0x82DA2D40
// RVA : 0x00DA2D40
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_520482()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 176 + 220));
}


// ========================================================================
// __unwind$520483
// EA  : 0x82DA2D68
// RVA : 0x00DA2D68
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_520483()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: *(idSWFScriptFunction_RefCounted **)(v0 - 176 + 196));
}


// ========================================================================
// __unwind$520484
// EA  : 0x82DA2D90
// RVA : 0x00DA2D90
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_520484()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 20));
}


// ========================================================================
// __unwind$520485
// EA  : 0x82DA2DBC
// RVA : 0x00DA2DBC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_520485()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 52));
}


// ========================================================================
// `idMainMenu::RebindAction'::`53'::idSWFScriptFunction_ConfirmUnbind::idSWFScriptFunction_ConfirmUnbind
// EA  : 0x82DA2EA0
// RVA : 0x00DA2EA0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall _idMainMenu::RebindAction_::_53_::idSWFScriptFunction_ConfirmUnbind::idSWFScriptFunction_ConfirmUnbind(
        idMainMenu *_menu,
        idSWF *_swf,
        idSWFScriptObject *_action,
        idStr *_bindSet,
        idSWFScriptVar::swfScriptVarValue_t _ininputDevice,
        idPlayerProfile *_profile,
        idSWFScriptVar *_keyNum,
        idSWFScriptVar::swfScriptVarType a8)
{
  idStr *p_num; // r3
  size_t len; // r29

  _menu->actionRepeater.event.type = WIDGET_EVENT_PRESS;
  _menu->actionRepeater.widget = (idMenuWidget *)&`idMainMenu::RebindAction'::`53'::idSWFScriptFunction_ConfirmUnbind::`vftable';
  *(_DWORD *)&_menu->actionRepeater.event.parms.granularity = 20;
  p_num = (idStr *)&_menu->actionRepeater.event.parms.num;
  _menu->actionRepeater.event.parms.size = (int)p_num->baseBuffer;
  _menu->actionRepeater.event.parms.num = 0;
  HIBYTE(_menu->actionRepeater.event.parms.staticList[0].type) = 0;
  _menu->actionRepeater.event.arg = (int)_swf;
  _menu->actionRepeater.event.thisObject = _action;
  len = _bindSet->len;
  idStr::EnsureAlloced(this: p_num, amount: _bindSet->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: (void *)_menu->actionRepeater.event.parms.size, Src: _bindSet->data, Size: len);
  *(_BYTE *)(_menu->actionRepeater.event.parms.size + len) = 0;
  _menu->actionRepeater.event.parms.num = len;
  _menu->actionRepeater.event.parms.staticList[2].value = _ininputDevice;
  _menu->actionRepeater.event.parms.list = _keyNum;
  _menu->actionRepeater.event.parms.staticList[3].value.i = (int)_profile;
  _menu->actionRepeater.event.parms.staticList[3].type = a8;
  idStr::FreeData(this: _bindSet);
}


// ========================================================================
// __unwind$520639
// EA  : 0x82DA2F64
// RVA : 0x00DA2F64
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_520639()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 176 + 220));
}


// ========================================================================
// __unwind$520640
// EA  : 0x82DA2F8C
// RVA : 0x00DA2F8C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_520640()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: *(idSWFScriptFunction_RefCounted **)(v0 - 176 + 196));
}


// ========================================================================
// __unwind$520641
// EA  : 0x82DA2FB4
// RVA : 0x00DA2FB4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_520641()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 20));
}


// ========================================================================
// ?loadDevMenuOption_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82DA3128
// RVA : 0x00DA3128
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall loadDevMenuOption_f(const idCmdArgs *args)
{
  const char *v2; // r4
  idResource *v3; // r29
  int v4; // r30
  const char *v5; // r3
  int v6; // r30
  int v7; // r11
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  int v11; // r11
  int v12; // r4
  int v13; // r28
  int v14; // r27
  va *v15; // r3
  int v16; // r11
  __int64 v17; // r8
  int v18; // r11
  __int64 v19; // r10
  va *v20; // r3
  va *v21; // r3
  int v22; // [sp+8h] [-10F8h]
  int v23; // [sp+Ch] [-10F4h]
  int v24; // [sp+10h] [-10F0h]
  int v25; // [sp+14h] [-10ECh]
  int v26; // [sp+18h] [-10E8h]
  int v27; // [sp+1Ch] [-10E4h]
  idStr v28; // [sp+60h] [-10A0h] BYREF
  idStr v29; // [sp+80h] [-1080h] BYREF
  idStr v30; // [sp+A0h] [-1060h] BYREF
  va v31; // [sp+C0h] [-1040h] BYREF

  if ( args->argc < 2 )
  {
    idLib::Printf(fmt: "usage: loadDevMenuOption <idDeclDevMenuList> (sublist index)\n");
    return;
  }
  if ( args->argc <= 1 )
    v2 = &byte_8200D768;
  else
    v2 = args->argv[1];
  idStr::idStr(this: &v28, text: v2);
  v3 = idResourceList::Load(
         this: &idDeclDevMenuList::resourceList,
         name: v28.data,
         makeDefault: false,
         skipStaleCheck: false);
  if ( v3 != nullptr )
  {
    v4 = 0;
    if ( args->argc >= 3 )
    {
      if ( args->argc <= 2 )
        v5 = &byte_8200D768;
      else
        v5 = args->argv[2];
      v4 = atol(nptr: v5);
      if ( v4 < 0 )
        goto _M521238;
    }
    else
    {
      idLib::Warning(fmt: "no subindex passed into loadDevMenuOption, defaulting to 0");
    }
    if ( v4 < *((_DWORD *)&v3[1] + 8) )
    {
      v6 = 316 * v4;
      idStr::idStr(this: &v29, text: (const idStr *)(v3[1].staleCount + v6 + 36));
      idStr::IReplace(this: &v29, old: "maps/", nw: &byte_8200D768);
      idCVar::SetString(this: &si_spawnspot, newValue: *(const char **)(v3[1].staleCount + v6 + 92), force: true);
      idCVar::SetString(this: &si_nextlayeractive, newValue: *(const char **)(v3[1].staleCount + v6 + 224), force: true);
      idCVar::SetString(
        this: &si_nextlayerdeactive,
        newValue: *(const char **)(v3[1].staleCount + v6 + 288),
        force: true);
      v7 = v3[1].staleCount + v6;
      if ( *(_DWORD *)(v7 + 152) == 0 )
      {
        idCVar::SetString(this: &si_jobDebugName, newValue: &byte_8200D768, force: true);
LABEL_24:
        v13 = *(_DWORD *)(v3[1].staleCount + v6 + 76);
        if ( v13 > 0 )
        {
          v14 = 0;
          do
          {
            HIDWORD(v10) = *(_DWORD *)(*(_DWORD *)(v3[1].staleCount + v6 + 72) + v14 + 4);
            v15 = va::va(
                    this: &v31,
                    fmt: "%s\n",
                    a3: v10,
                    a4: v9,
                    a5: v8,
                    a6: v22,
                    a7: v23,
                    a8: v24,
                    a9: v25,
                    a10: v26,
                    a11: v27);
            cmdSystem->AppendCommandText(this: cmdSystem, a2: v15->buffer);
            --v13;
            v14 += 32;
          }
          while ( v13 != 0 );
          cmdSystem->ExecuteCommandBuffer(this: cmdSystem);
        }
        v16 = v3[1].staleCount + v6;
        if ( *(_BYTE *)(v16 + 68) != 0 )
        {
          idStr::idStr(this: &v30, text: "mp/dm");
          v18 = v3[1].staleCount + v6;
          LODWORD(v19) = *(_DWORD *)(v18 + 192);
          if ( (int)v19 > 0 )
            idStr::operator=(this: &v30, text: *(const char **)(**(_DWORD **)(v18 + 188) + 8));
          v20 = va::va(
                  this: &v31,
                  fmt: "loadMPMap %s %s\n",
                  a3: __SPAIR64__((unsigned int)v29.data, (unsigned int)v30.data),
                  a4: v17,
                  a5: v19,
                  a6: v22,
                  a7: v23,
                  a8: v24,
                  a9: v25,
                  a10: v26,
                  a11: v27);
          cmdSystem->AppendCommandText(this: cmdSystem, a2: v20->buffer);
          idStr::FreeData(this: &v30);
        }
        else
        {
          HIDWORD(v10) = v29.data;
          HIDWORD(v8) = *(unsigned __int8 *)(v16 + 68);
          v21 = va::va(
                  this: &v31,
                  fmt: "devcmap %s\n",
                  a3: v10,
                  a4: v9,
                  a5: v8,
                  a6: v22,
                  a7: v23,
                  a8: v24,
                  a9: v25,
                  a10: v26,
                  a11: v27);
          cmdSystem->AppendCommandText(this: cmdSystem, a2: v21->buffer);
        }
        idStr::FreeData(this: &v29);
        goto LABEL_35;
      }
      idCVar::SetString(this: &si_jobDebugName, newValue: *(const char **)(v7 + 156), force: true);
      HIDWORD(v8) = v3[1].staleCount + v6;
      v11 = *(_DWORD *)(HIDWORD(v8) + 184);
      if ( v11 != 0 )
      {
        if ( v11 == 1 )
        {
          v12 = 1;
        }
        else
        {
          if ( v11 != 2 )
            goto LABEL_24;
          v12 = 2;
        }
      }
      else
      {
        v12 = 0;
      }
      idCVar::SetInteger(this: &si_jobDebugState, newValue: v12, force: true);
      goto LABEL_24;
    }
_M521238:
    idLib::Warning(fmt: "loadDevMenuOption invalid index %d on  %s", v4, v28.data);
    goto LABEL_35;
  }
  idLib::Warning(fmt: "loadDevMenuOption could not find idDeclDevMenuList %s", v28.data);
LABEL_35:
  idStr::FreeData(this: &v28);
}


// ========================================================================
// __unwind$521038
// EA  : 0x82DA3480
// RVA : 0x00DA3480
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_521038()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4352 + 96));
}


// ========================================================================
// __unwind$521039
// EA  : 0x82DA34A8
// RVA : 0x00DA34A8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_521039()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4352 + 128));
}


// ========================================================================
// __unwind$521040
// EA  : 0x82DA34D0
// RVA : 0x00DA34D0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_521040()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4352 + 160));
}


// ========================================================================
// ?GetControllerBinding@idMainMenu@@QAA?AVidStr@@PBDH@Z
// EA  : 0x82DA3500
// RVA : 0x00DA3500
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu *__fastcall idMainMenu::GetControllerBinding(
        idMainMenu *this,
        idStr *result,
        const char *keyStr,
        unsigned int bindSet)
{
  keyNum_t v6; // r29
  unsigned int v8; // r3
  cmdGenButton_t UsercmdAction; // r3
  idStr v10[2]; // [sp+60h] [-50h] BYREF

  v6 = idKeyInput::StringToKeyNum(str: keyStr);
  if ( v6 != K_NONE )
  {
    v8 = common->GetFocusDeviceNum(this: common);
    UsercmdAction = idKeyInput::GetUsercmdAction(numDevice: v8, bindset: bindSet, keynum: v6);
    idKeyInput::GetUsercmdActionStr(result: v10, cmd: UsercmdAction);
    idStr::idStr((idStr *)this, text: v10);
    idStr::FreeData(this: v10);
  }
  else
  {
    idStr::idStr((idStr *)this, text: &byte_8200D768);
  }
  return this;
}


// ========================================================================
// __unwind$521404
// EA  : 0x82DA35A8
// RVA : 0x00DA35A8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_521404()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 176;
  if ( (*(_DWORD *)(v0 - 176 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 196));
  }
}


// ========================================================================
// __unwind$521407
// EA  : 0x82DA35EC
// RVA : 0x00DA35EC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_521407()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?restartMapFromDevMenu_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82DA3620
// RVA : 0x00DA3620
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall restartMapFromDevMenu_f(const idCmdArgs *args)
{
  __int64 v1; // r10
  __int64 v2; // r8
  va *v3; // r3
  int v4; // [sp+8h] [-1088h]
  int v5; // [sp+Ch] [-1084h]
  int v6; // [sp+10h] [-1080h]
  int v7; // [sp+14h] [-107Ch]
  int v8; // [sp+18h] [-1078h]
  int v9; // [sp+1Ch] [-1074h]
  idStr v10; // [sp+60h] [-1030h] BYREF
  va v11; // [sp+80h] [-1010h] BYREF

  idStr::idStr(this: &v10, text: mm_savedDevMenuDecl.valueString.data);
  HIDWORD(v1) = &idEventDef::eventDefList[3154];
  LODWORD(v2) = "ame: %s\n";
  HIDWORD(v2) = &mm_savedDevMenuIndex;
  v3 = va::va(
         this: &v11,
         fmt: "loadDevMenuOption %s %d\n",
         a3: __SPAIR64__((unsigned int)v10.data, mm_savedDevMenuIndex.valueInteger),
         a4: v2,
         a5: v1,
         a6: v4,
         a7: v5,
         a8: v6,
         a9: v7,
         a10: v8,
         a11: v9);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: v3->buffer);
  idStr::FreeData(this: &v10);
}


// ========================================================================
// __unwind$521432
// EA  : 0x82DA36A8
// RVA : 0x00DA36A8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_521432()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4240 + 96));
}


// ========================================================================
// ?UpdateButtonBar@idMainMenu@@QAAXXZ
// EA  : 0x82DA36D8
// RVA : 0x00DA36D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateButtonBar(idMainMenu *this)
{
  int v2; // r25
  int len; // r28
  int v4; // r28
  char *data; // r4
  int v6; // r28
  idSWFScriptObject *scriptObject; // r29
  idSWFSpriteInstance *NestedSprite; // r3
  idSWFSpriteInstance *v9; // r28
  idSWFScriptObject *NestedObj; // r27
  idSWFTextInstance *text; // r28
  idStr *v12; // r3
  __int64 v13; // r10
  int v14; // r8
  int v15; // r7
  int v16; // r6
  int v17; // r5
  int v18; // r4
  idSWFSpriteInstance *v19; // r28
  idSWFScriptObject *v20; // r27
  __int64 v21; // r11
  double v22; // fp31
  idSWFTextInstance *v23; // r28
  idStr *v24; // r3
  __int64 v25; // r10
  int v26; // r8
  int v27; // r7
  int v28; // r6
  int v29; // r5
  int v30; // r4
  idSWFSpriteInstance *v31; // r28
  idSWFScriptObject *v32; // r27
  __int64 v33; // r11
  double v34; // fp31
  idSWFTextInstance *v35; // r28
  idStr *v36; // r3
  __int64 v37; // r10
  int v38; // r8
  int v39; // r7
  int v40; // r6
  int v41; // r5
  int v42; // r4
  idSWFSpriteInstance *v43; // r28
  idSWFScriptObject *v44; // r30
  __int64 v45; // r11
  idSWFTextInstance *v46; // r30
  idStr *v47; // r3
  __int64 v48; // r10
  int v49; // r8
  int v50; // r7
  int v51; // r6
  int v52; // r5
  int v53; // r4
  idStr v54; // [sp+60h] [-F0h] BYREF
  idStr v55; // [sp+80h] [-D0h] BYREF
  idStr v56; // [sp+A0h] [-B0h] BYREF
  idStr v57; // [sp+C0h] [-90h] BYREF
  idStr v58; // [sp+E0h] [-70h] BYREF

  v54.len = 0;
  v54.allocedAndFlag = 20;
  v2 = -35;
  v54.data = v54.baseBuffer;
  v54.baseBuffer[0] = 0;
  v55.allocedAndFlag = 20;
  v55.data = v55.baseBuffer;
  v55.len = 0;
  v55.baseBuffer[0] = 0;
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)this->mainMenu) != 0 )
  {
    len = this->btn1Text.len;
    idStr::EnsureAlloced(this: &v55, amount: len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v55.data, Src: this->btn1Text.data, Size: len);
    v55.data[len] = 0;
    v55.len = len;
    v4 = this->btn2Text.len;
    idStr::EnsureAlloced(this: &v54, amount: v4 + 1, keepold: false, geometricGrowth: false);
    data = this->btn2Text.data;
  }
  else
  {
    v6 = this->btn2Text.len;
    idStr::EnsureAlloced(this: &v55, amount: v6 + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v55.data, Src: this->btn2Text.data, Size: v6);
    v55.data[v6] = 0;
    v55.len = v6;
    v4 = this->btn1Text.len;
    idStr::EnsureAlloced(this: &v54, amount: v4 + 1, keepold: false, geometricGrowth: false);
    data = this->btn1Text.data;
  }
  memcpy(Dst: v54.data, Src: data, Size: v4);
  v54.data[v4] = 0;
  v54.len = v4;
  idStr::idStr(this: &v56, text: &this->btn3Text);
  idStr::idStr(this: &v58, text: &this->btn4Text);
  scriptObject = this->mainMenu->mainspriteInstance->scriptObject;
  NestedSprite = idSWFScriptObject::GetNestedSprite(
                   this: scriptObject,
                   arg1: "cmdBar",
                   arg2: nullptr,
                   arg3: nullptr,
                   arg4: nullptr,
                   arg5: nullptr,
                   arg6: nullptr);
  if ( NestedSprite != nullptr )
    idSWFSpriteInstance::SetVisible(this: NestedSprite, visible: true);
  v9 = idSWFScriptObject::GetNestedSprite(
         this: scriptObject,
         arg1: "cmdBar",
         arg2: "joy2",
         arg3: nullptr,
         arg4: nullptr,
         arg5: nullptr,
         arg6: nullptr);
  NestedObj = idSWFScriptObject::GetNestedObj(
                this: scriptObject,
                arg1: "cmdBar",
                arg2: "joy2",
                arg3: "txt_info",
                arg4: nullptr,
                arg5: nullptr,
                arg6: nullptr);
  if ( v9 != nullptr )
  {
    if ( v55.len != 0 )
    {
      idSWFSpriteInstance::SetVisible(this: v9, visible: true);
      idSWFSpriteInstance::SetXPos(this: v9, xPos: -35.0);
      if ( NestedObj->objectType == SWF_OBJECT_TEXT )
      {
        text = NestedObj->data.text;
        if ( text != nullptr )
        {
          v12 = idStr::idStr(this: &v57, text: &v55);
          idSWFTextInstance::SetText(this: text, val: v12);
          v2 = (int)(float)((float)-35.0
                          - (float)(idSWFTextInstance::GetTextLength(
                                      this: text,
                                      a2: v18,
                                      a3: v17,
                                      a4: v16,
                                      a5: v15,
                                      a6: v14,
                                      a7: v13)
                                  + (float)65.0));
        }
      }
    }
    else
    {
      idSWFSpriteInstance::SetVisible(this: v9, visible: false);
    }
  }
  v19 = idSWFScriptObject::GetNestedSprite(
          this: scriptObject,
          arg1: "cmdBar",
          arg2: "joy1",
          arg3: nullptr,
          arg4: nullptr,
          arg5: nullptr,
          arg6: nullptr);
  v20 = idSWFScriptObject::GetNestedObj(
          this: scriptObject,
          arg1: "cmdBar",
          arg2: "joy1",
          arg3: "txt_info",
          arg4: nullptr,
          arg5: nullptr,
          arg6: nullptr);
  if ( v19 != nullptr )
  {
    if ( v54.len != 0 )
    {
      idSWFSpriteInstance::SetVisible(this: v19, visible: true);
      LODWORD(v21) = v2;
      v22 = (float)v21;
      idSWFSpriteInstance::SetXPos(this: v19, xPos: v22);
      if ( v20->objectType == SWF_OBJECT_TEXT )
      {
        v23 = v20->data.text;
        if ( v23 != nullptr )
        {
          v24 = idStr::idStr(this: &v57, text: &v54);
          idSWFTextInstance::SetText(this: v23, val: v24);
          v2 = (int)(float)((float)v22
                          - (float)(idSWFTextInstance::GetTextLength(
                                      this: v23,
                                      a2: v30,
                                      a3: v29,
                                      a4: v28,
                                      a5: v27,
                                      a6: v26,
                                      a7: v25)
                                  + (float)65.0));
        }
      }
    }
    else
    {
      idSWFSpriteInstance::SetVisible(this: v19, visible: false);
    }
  }
  v31 = idSWFScriptObject::GetNestedSprite(
          this: scriptObject,
          arg1: "cmdBar",
          arg2: "joy3",
          arg3: nullptr,
          arg4: nullptr,
          arg5: nullptr,
          arg6: nullptr);
  v32 = idSWFScriptObject::GetNestedObj(
          this: scriptObject,
          arg1: "cmdBar",
          arg2: "joy3",
          arg3: "txt_info",
          arg4: nullptr,
          arg5: nullptr,
          arg6: nullptr);
  if ( v31 != nullptr )
  {
    if ( v56.len != 0 )
    {
      idSWFSpriteInstance::SetVisible(this: v31, visible: true);
      LODWORD(v33) = v2;
      v34 = (float)v33;
      idSWFSpriteInstance::SetXPos(this: v31, xPos: v34);
      if ( v32->objectType == SWF_OBJECT_TEXT )
      {
        v35 = v32->data.text;
        if ( v35 != nullptr )
        {
          v36 = idStr::idStr(this: &v57, text: &v56);
          idSWFTextInstance::SetText(this: v35, val: v36);
          v2 = (int)(float)((float)v34
                          - (float)(idSWFTextInstance::GetTextLength(
                                      this: v35,
                                      a2: v42,
                                      a3: v41,
                                      a4: v40,
                                      a5: v39,
                                      a6: v38,
                                      a7: v37)
                                  - (float)65.0));
        }
      }
    }
    else
    {
      idSWFSpriteInstance::SetVisible(this: v31, visible: false);
    }
  }
  v43 = idSWFScriptObject::GetNestedSprite(
          this: scriptObject,
          arg1: "cmdBar",
          arg2: "joy4",
          arg3: nullptr,
          arg4: nullptr,
          arg5: nullptr,
          arg6: nullptr);
  v44 = idSWFScriptObject::GetNestedObj(
          this: scriptObject,
          arg1: "cmdBar",
          arg2: "joy4",
          arg3: "txt_info",
          arg4: nullptr,
          arg5: nullptr,
          arg6: nullptr);
  if ( v43 != nullptr )
  {
    if ( v56.len != 0 )
    {
      idSWFSpriteInstance::SetVisible(this: v43, visible: true);
      LODWORD(v45) = v2;
      idSWFSpriteInstance::SetXPos(this: v43, xPos: (float)v45);
      if ( v44->objectType == SWF_OBJECT_TEXT )
      {
        v46 = v44->data.text;
        if ( v46 != nullptr )
        {
          v47 = idStr::idStr(this: &v57, text: &v58);
          idSWFTextInstance::SetText(this: v46, val: v47);
          idSWFTextInstance::GetTextLength(this: v46, a2: v53, a3: v52, a4: v51, a5: v50, a6: v49, a7: v48);
        }
      }
    }
    else
    {
      idSWFSpriteInstance::SetVisible(this: v43, visible: false);
    }
  }
  idStr::FreeData(this: &v58);
  idStr::FreeData(this: &v56);
  idStr::FreeData(this: &v55);
  idStr::FreeData(this: &v54);
}


// ========================================================================
// __unwind$521527
// EA  : 0x82DA3C04
// RVA : 0x00DA3C04
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_521527()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 96));
}


// ========================================================================
// __unwind$521528
// EA  : 0x82DA3C2C
// RVA : 0x00DA3C2C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_521528()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 128));
}


// ========================================================================
// __unwind$521529
// EA  : 0x82DA3C54
// RVA : 0x00DA3C54
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_521529()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 160));
}


// ========================================================================
// __unwind$521530
// EA  : 0x82DA3C7C
// RVA : 0x00DA3C7C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_521530()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 224));
}


// ========================================================================
// ?ShowOverwriteSavingDialog@idMainMenu@@QAAX_NH@Z
// EA  : 0x82DA4000
// RVA : 0x00DA4000
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::ShowOverwriteSavingDialog(idMainMenu *this, bool show, int index)
{
  _DWORD *v5; // r3
  _DWORD *v6; // r27
  _DWORD *v7; // r3
  _DWORD *v8; // r6

  if ( show )
  {
    v5 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
           size: 0xCu,
           tag: TAG_SWF,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5[2] = this;
      v5[1] = 0;
      v6 = v5;
      *v5 = &`idMainMenu::ShowOverwriteSavingDialog'::`7'::idSWFScriptFunction_DeclineOverwrite::`vftable';
    }
    else
    {
      v6 = nullptr;
    }
    v7 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
           size: 0x10u,
           tag: TAG_SWF,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    if ( v7 != nullptr )
    {
      v7[2] = this;
      v7[3] = index;
      v8 = v7;
      v7[1] = 0;
      *v7 = &`idMainMenu::ShowOverwriteSavingDialog'::`6'::idSWFScriptFunction_AcceptOverwrite::`vftable';
    }
    else
    {
      v8 = nullptr;
    }
    ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
      a1: common,
      a2: 39,
      a3: 2,
      a4: v8,
      a5: v6,
      a6: 0,
      a7: 0,
      a8: 0);
  }
}


// ========================================================================
// ?GameSave@idMainMenu@@QAAXH@Z
// EA  : 0x82DA4118
// RVA : 0x00DA4118
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::GameSave(idMainMenu *this, int index)
{
  idSaveGameManager *saveGameManager; // r11
  idStaticList<idSaveGameDetails,16> *p_enumeratedSaveGames; // r28
  idSaveGameDetails *v5; // r29
  size_t list; // r30
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  va *v10; // r3
  int i; // r25
  int len; // r30
  int v13; // r4
  int v14; // r11
  char v15; // r27
  int v16; // r29
  int v17; // r30
  idSaveGameDetails *SlotName; // r3
  BOOL v19; // r21
  int v20; // [sp+8h] [-11E8h]
  int v21; // [sp+Ch] [-11E4h]
  int v22; // [sp+10h] [-11E0h]
  int v23; // [sp+14h] [-11DCh]
  int v24; // [sp+18h] [-11D8h]
  int v25; // [sp+1Ch] [-11D4h]
  idStr v26; // [sp+50h] [-11A0h] BYREF
  idStr v27; // [sp+70h] [-1180h] BYREF
  char v28[64]; // [sp+90h] [-1160h] BYREF
  idSaveGameDetails v29; // [sp+D0h] [-1120h] BYREF
  va v30; // [sp+190h] [-1060h] BYREF

  idStr::idStr(this: &v27, text: "RAGE_");
  idStr::idStr(this: &v26, text: &byte_8200D768);
  saveGameManager = session->saveGameManager;
  p_enumeratedSaveGames = &saveGameManager->enumeratedSaveGames;
  if ( index >= saveGameManager->enumeratedSaveGames.num || index < 0 )
  {
    for ( i = 0; ; ++i )
    {
      len = v27.len;
      v13 = v27.len + 1;
      v14 = v26.allocedAndFlag & 0x7FFFFFFF;
      if ( v26.allocedAndFlag >= 0 )
      {
        if ( v13 > v14 )
          idStr::ReAllocate(this: &v26, amount: v13, keepold: false);
      }
      else if ( v13 > v14
             && AssertFailed(
                  file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                  line: 463,
                  expression: "amount <= GetAlloced()",
                  inlineBreak: true) )
      {
        __trap();
      }
      memcpy(Dst: v26.data, Src: v27.data, Size: len);
      v26.data[len] = 0;
      v26.len = len;
      sprintf_0(string: v28, format: "%d", i);
      idStr::Append(this: &v26, text: v28);
      LODWORD(v7) = p_enumeratedSaveGames->num;
      v15 = 0;
      v16 = 0;
      if ( (int)v7 > 0 )
      {
        v17 = 0;
        while ( 1 )
        {
          SlotName = idSaveGameDetails::GetSlotName(
                       this: &v29,
                       result: (idStrStatic<64> *)&p_enumeratedSaveGames->list[v17]);
          v19 = (_cntlzw(idStr::Cmp(s1: v26.data, s2: (const char *)SlotName->descriptors.args.num)) & 0x20) != 0;
          idStr::FreeData(this: (idStr *)&v29);
          if ( v19 )
            break;
          ++v16;
          ++v17;
          if ( v16 >= p_enumeratedSaveGames->num )
            goto LABEL_18;
        }
        v15 = 1;
      }
LABEL_18:
      if ( v15 == 0 )
        break;
    }
  }
  else
  {
    v5 = idSaveGameDetails::GetSlotName(
           this: (idSaveGameDetails *)v29.slotName.buffer,
           result: (idStrStatic<64> *)&p_enumeratedSaveGames->list[index]);
    list = (size_t)v5->descriptors.args.list;
    idStr::EnsureAlloced(
      this: &v26,
      amount: (int)&v5->descriptors.args.list->key.len + 1,
      keepold: false,
      geometricGrowth: false);
    memcpy(Dst: v26.data, Src: (const void *)v5->descriptors.args.num, Size: list);
    v26.data[list] = 0;
    v26.len = list;
    idStr::FreeData(this: (idStr *)v29.slotName.buffer);
  }
  HIDWORD(v9) = v26.data;
  v10 = va::va(
          this: &v30,
          fmt: "saveGame %s\n",
          a3: v9,
          a4: v8,
          a5: v7,
          a6: v20,
          a7: v21,
          a8: v22,
          a9: v23,
          a10: v24,
          a11: v25);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: v10->buffer);
  idLib::Printf(fmt: "Saving %s...\n", v26.data);
  idStr::FreeData(this: &v26);
  idStr::FreeData(this: &v27);
}


// ========================================================================
// __unwind$522624
// EA  : 0x82DA4360
// RVA : 0x00DA4360
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_522624()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 112));
}


// ========================================================================
// __unwind$522625
// EA  : 0x82DA4388
// RVA : 0x00DA4388
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_522625()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 80));
}


// ========================================================================
// __unwind$522626
// EA  : 0x82DA43B0
// RVA : 0x00DA43B0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_522626()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 304));
}


// ========================================================================
// __unwind$522627
// EA  : 0x82DA43D8
// RVA : 0x00DA43D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_522627()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 208));
}


// ========================================================================
// ?DeleteSaveGameConfirm@idMainMenu@@QAAXH@Z
// EA  : 0x82DA4400
// RVA : 0x00DA4400
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::DeleteSaveGameConfirm(idMainMenu *this, int saveIndex)
{
  _DWORD *v4; // r3
  _DWORD *v5; // r26
  _DWORD *v6; // r3
  _DWORD *v7; // r6

  v4 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
         size: 0xCu,
         tag: TAG_SWF,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
  {
    v4[2] = this;
    v4[1] = 0;
    v5 = v4;
    *v4 = &`idMainMenu::DeleteSaveGameConfirm'::`2'::idSWFScriptFunction_CancelDelete::`vftable';
  }
  else
  {
    v5 = nullptr;
  }
  v6 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
         size: 0x10u,
         tag: TAG_SWF,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v6 != nullptr )
  {
    v6[2] = this;
    v6[3] = saveIndex;
    v7 = v6;
    v6[1] = 0;
    *v6 = &`idMainMenu::DeleteSaveGameConfirm'::`3'::idSWFScriptFunction_AcceptDelete::`vftable';
  }
  else
  {
    v7 = nullptr;
  }
  ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
    a1: common,
    a2: 46,
    a3: 2,
    a4: v7,
    a5: v5,
    a6: 0,
    a7: 0,
    a8: 0);
}


// ========================================================================
// ?ExitGameConfirm@idMainMenu@@QAAXH@Z
// EA  : 0x82DA4500
// RVA : 0x00DA4500
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::ExitGameConfirm(idMainMenu *this, int pauseOption)
{
  int *p_currentDeviceIndex; // r24
  _DWORD *v4; // r3
  idSWF *v5; // r11
  _DWORD *v6; // r27
  _DWORD *v7; // r3
  idSWF *v8; // r11
  _DWORD *v9; // r6
  _DWORD *v10; // r3
  idSWF *mainMenu; // r11
  _DWORD *v12; // r26
  _DWORD *v13; // r3
  idSWF *v14; // r11
  _DWORD *v15; // r6
  idLobbyBase *v16; // r3
  int gameType; // r7
  int (*GetGameLobbyBase)(void); // ctr
  int v19; // r3
  idLobbyBase *v20; // r3
  _DWORD *v21; // r3
  idSWF *v22; // r11
  _DWORD *v23; // r26
  _DWORD *v24; // r3
  idSWF *v25; // r11
  _DWORD *v26; // r6
  _DWORD *v27; // r3
  idSWF *v28; // r11
  _DWORD *v29; // r26
  _DWORD *v30; // r3
  idSWF *v31; // r11
  _DWORD *v32; // r6
  int v33; // r3
  idLobbyBase *v34; // r3
  _DWORD *v35; // r3
  idSWF *v36; // r11
  _DWORD *v37; // r26
  _DWORD *v38; // r3
  idSWF *v39; // r11
  _DWORD *v40; // r6
  _DWORD *v41; // r3
  idSWF *v42; // r11
  _DWORD *v43; // r26
  _DWORD *v44; // r3
  idSWF *v45; // r11
  _DWORD *v46; // r6
  _DWORD *v47; // r3
  idSWF *v48; // r11
  _DWORD *v49; // r26
  _DWORD *v50; // r3
  idSWF *v51; // r11
  _DWORD *v52; // r6
  _DWORD *v53; // r3
  idSWF *v54; // r11
  _DWORD *v55; // r26
  _DWORD *v56; // r3
  idSWF *v57; // r11
  _DWORD *v58; // r6
  _DWORD *v59; // r3
  idSWF *v60; // r11
  _DWORD *v61; // r26
  _DWORD *v62; // r3
  idSWF *v63; // r11
  _DWORD *v64; // r6

  p_currentDeviceIndex = &this->currentDeviceIndex;
  this->currentDeviceIndex = 0;
  if ( pauseOption != 0 )
  {
    switch ( pauseOption )
    {
      case 1:
        v10 = idMem::AllocWithLocation(
                this: &mem,
                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                size: 0x14u,
                tag: TAG_SWF,
                zeroBuffer: false,
                align: ALIGN_16,
                heap: HEAP_DEFAULTHEAP);
        if ( v10 != nullptr )
        {
          mainMenu = this->mainMenu;
          v10[1] = 0;
          v12 = v10;
          v10[3] = 1;
          v10[4] = 40;
          *v10 = &`idMainMenu::ExitGameConfirm'::`2'::idSWFScriptFunction_CancelExit::`vftable';
          v10[2] = mainMenu;
        }
        else
        {
          v12 = nullptr;
        }
        v13 = idMem::AllocWithLocation(
                this: &mem,
                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                size: 0x18u,
                tag: TAG_SWF,
                zeroBuffer: false,
                align: ALIGN_16,
                heap: HEAP_DEFAULTHEAP);
        if ( v13 != nullptr )
        {
          v14 = this->mainMenu;
          v13[5] = p_currentDeviceIndex;
          v15 = v13;
          v13[1] = 0;
          v13[3] = 1;
          *v13 = &`idMainMenu::ExitGameConfirm'::`3'::idSWFScriptFunction_AcceptExit::`vftable';
          v13[2] = v14;
          v13[4] = 40;
        }
        else
        {
          v15 = nullptr;
        }
        ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
          a1: common,
          a2: 40,
          a3: 2,
          a4: v15,
          a5: v12,
          a6: 0,
          a7: 0,
          a8: 0);
        break;
      case 2:
        if ( common->IsMultiplayer(this: common) )
        {
          v16 = session->GetGameLobbyBase(this: session);
          gameType = v16->GetMatchParms(this: v16)->gameType;
          GetGameLobbyBase = (int (*)(void))session->GetGameLobbyBase;
          if ( gameType == 1 )
          {
            v19 = GetGameLobbyBase();
            if ( (*(int (__fastcall **)(int))(*(_DWORD *)v19 + 12))(a1: v19) > 1
              && (v20 = session->GetGameLobbyBase(this: session), (v20->GetMatchParms(this: v20)->matchFlags & 1) != 0) )
            {
              v21 = idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x14u,
                      tag: TAG_SWF,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
              if ( v21 != nullptr )
              {
                v22 = this->mainMenu;
                v21[1] = 0;
                v23 = v21;
                v21[3] = 2;
                v21[4] = 111;
                *v21 = &`idMainMenu::ExitGameConfirm'::`2'::idSWFScriptFunction_CancelExit::`vftable';
                v21[2] = v22;
              }
              else
              {
                v23 = nullptr;
              }
              v24 = idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x18u,
                      tag: TAG_SWF,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
              if ( v24 != nullptr )
              {
                v25 = this->mainMenu;
                v24[5] = p_currentDeviceIndex;
                v26 = v24;
                v24[1] = 0;
                v24[3] = 2;
                *v24 = &`idMainMenu::ExitGameConfirm'::`3'::idSWFScriptFunction_AcceptExit::`vftable';
                v24[2] = v25;
                v24[4] = 111;
              }
              else
              {
                v26 = nullptr;
              }
              ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
                a1: common,
                a2: 111,
                a3: 3,
                a4: v26,
                a5: v23,
                a6: 0,
                a7: 0,
                a8: 0);
            }
            else
            {
              v27 = idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x14u,
                      tag: TAG_SWF,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
              if ( v27 != nullptr )
              {
                v28 = this->mainMenu;
                v27[1] = 0;
                v29 = v27;
                v27[3] = 2;
                v27[4] = 57;
                *v27 = &`idMainMenu::ExitGameConfirm'::`2'::idSWFScriptFunction_CancelExit::`vftable';
                v27[2] = v28;
              }
              else
              {
                v29 = nullptr;
              }
              v30 = idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x18u,
                      tag: TAG_SWF,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
              if ( v30 != nullptr )
              {
                v31 = this->mainMenu;
                v30[5] = p_currentDeviceIndex;
                v32 = v30;
                v30[1] = 0;
                v30[3] = 2;
                *v30 = &`idMainMenu::ExitGameConfirm'::`3'::idSWFScriptFunction_AcceptExit::`vftable';
                v30[2] = v31;
                v30[4] = 57;
              }
              else
              {
                v32 = nullptr;
              }
              ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
                a1: common,
                a2: 57,
                a3: 3,
                a4: v32,
                a5: v29,
                a6: 0,
                a7: 0,
                a8: 0);
            }
          }
          else
          {
            v33 = GetGameLobbyBase();
            if ( (*(int (__fastcall **)(int))(*(_DWORD *)v33 + 12))(a1: v33) > 1
              && (v34 = session->GetGameLobbyBase(this: session), (v34->GetMatchParms(this: v34)->matchFlags & 1) != 0) )
            {
              v35 = idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x14u,
                      tag: TAG_SWF,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
              if ( v35 != nullptr )
              {
                v36 = this->mainMenu;
                v35[1] = 0;
                v37 = v35;
                v35[3] = 2;
                v35[4] = 113;
                *v35 = &`idMainMenu::ExitGameConfirm'::`2'::idSWFScriptFunction_CancelExit::`vftable';
                v35[2] = v36;
              }
              else
              {
                v37 = nullptr;
              }
              v38 = idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x18u,
                      tag: TAG_SWF,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
              if ( v38 != nullptr )
              {
                v39 = this->mainMenu;
                v38[5] = p_currentDeviceIndex;
                v40 = v38;
                v38[1] = 0;
                v38[3] = 2;
                *v38 = &`idMainMenu::ExitGameConfirm'::`3'::idSWFScriptFunction_AcceptExit::`vftable';
                v38[2] = v39;
                v38[4] = 113;
              }
              else
              {
                v40 = nullptr;
              }
              ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
                a1: common,
                a2: 113,
                a3: 3,
                a4: v40,
                a5: v37,
                a6: 0,
                a7: 0,
                a8: 0);
            }
            else
            {
              v41 = idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x14u,
                      tag: TAG_SWF,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
              if ( v41 != nullptr )
              {
                v42 = this->mainMenu;
                v41[1] = 0;
                v43 = v41;
                v41[3] = 2;
                v41[4] = 56;
                *v41 = &`idMainMenu::ExitGameConfirm'::`2'::idSWFScriptFunction_CancelExit::`vftable';
                v41[2] = v42;
              }
              else
              {
                v43 = nullptr;
              }
              v44 = idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x18u,
                      tag: TAG_SWF,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
              if ( v44 != nullptr )
              {
                v45 = this->mainMenu;
                v44[5] = p_currentDeviceIndex;
                v46 = v44;
                v44[1] = 0;
                v44[3] = 2;
                *v44 = &`idMainMenu::ExitGameConfirm'::`3'::idSWFScriptFunction_AcceptExit::`vftable';
                v44[2] = v45;
                v44[4] = 56;
              }
              else
              {
                v46 = nullptr;
              }
              ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
                a1: common,
                a2: 56,
                a3: 3,
                a4: v46,
                a5: v43,
                a6: 0,
                a7: 0,
                a8: 0);
            }
          }
        }
        else
        {
          v47 = idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                  size: 0x14u,
                  tag: TAG_SWF,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
          if ( v47 != nullptr )
          {
            v48 = this->mainMenu;
            v47[1] = 0;
            v49 = v47;
            v47[3] = 2;
            v47[4] = 9;
            *v47 = &`idMainMenu::ExitGameConfirm'::`2'::idSWFScriptFunction_CancelExit::`vftable';
            v47[2] = v48;
          }
          else
          {
            v49 = nullptr;
          }
          v50 = idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                  size: 0x18u,
                  tag: TAG_SWF,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
          if ( v50 != nullptr )
          {
            v51 = this->mainMenu;
            v50[5] = p_currentDeviceIndex;
            v52 = v50;
            v50[1] = 0;
            v50[3] = 2;
            *v50 = &`idMainMenu::ExitGameConfirm'::`3'::idSWFScriptFunction_AcceptExit::`vftable';
            v50[2] = v51;
            v50[4] = 9;
          }
          else
          {
            v52 = nullptr;
          }
          ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
            a1: common,
            a2: 9,
            a3: 2,
            a4: v52,
            a5: v49,
            a6: 0,
            a7: 0,
            a8: 0);
        }
        break;
      case 5:
        v53 = idMem::AllocWithLocation(
                this: &mem,
                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                size: 0x14u,
                tag: TAG_SWF,
                zeroBuffer: false,
                align: ALIGN_16,
                heap: HEAP_DEFAULTHEAP);
        if ( v53 != nullptr )
        {
          v54 = this->mainMenu;
          v53[1] = 0;
          v55 = v53;
          v53[3] = 5;
          v53[4] = 55;
          *v53 = &`idMainMenu::ExitGameConfirm'::`2'::idSWFScriptFunction_CancelExit::`vftable';
          v53[2] = v54;
        }
        else
        {
          v55 = nullptr;
        }
        v56 = idMem::AllocWithLocation(
                this: &mem,
                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                size: 0x18u,
                tag: TAG_SWF,
                zeroBuffer: false,
                align: ALIGN_16,
                heap: HEAP_DEFAULTHEAP);
        if ( v56 != nullptr )
        {
          v57 = this->mainMenu;
          v56[5] = p_currentDeviceIndex;
          v58 = v56;
          v56[1] = 0;
          v56[3] = 5;
          *v56 = &`idMainMenu::ExitGameConfirm'::`3'::idSWFScriptFunction_AcceptExit::`vftable';
          v56[2] = v57;
          v56[4] = 55;
        }
        else
        {
          v58 = nullptr;
        }
        ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
          a1: common,
          a2: 55,
          a3: 3,
          a4: v58,
          a5: v55,
          a6: 0,
          a7: 0,
          a8: 0);
        break;
      case 4:
        v59 = idMem::AllocWithLocation(
                this: &mem,
                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                size: 0x14u,
                tag: TAG_SWF,
                zeroBuffer: false,
                align: ALIGN_16,
                heap: HEAP_DEFAULTHEAP);
        if ( v59 != nullptr )
        {
          v60 = this->mainMenu;
          v59[1] = 0;
          v61 = v59;
          v59[3] = 4;
          v59[4] = 54;
          *v59 = &`idMainMenu::ExitGameConfirm'::`2'::idSWFScriptFunction_CancelExit::`vftable';
          v59[2] = v60;
        }
        else
        {
          v61 = nullptr;
        }
        v62 = idMem::AllocWithLocation(
                this: &mem,
                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                size: 0x18u,
                tag: TAG_SWF,
                zeroBuffer: false,
                align: ALIGN_16,
                heap: HEAP_DEFAULTHEAP);
        if ( v62 != nullptr )
        {
          v63 = this->mainMenu;
          v62[5] = p_currentDeviceIndex;
          v64 = v62;
          v62[1] = 0;
          v62[3] = 4;
          *v62 = &`idMainMenu::ExitGameConfirm'::`3'::idSWFScriptFunction_AcceptExit::`vftable';
          v62[2] = v63;
          v62[4] = 54;
        }
        else
        {
          v64 = nullptr;
        }
        ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
          a1: common,
          a2: 54,
          a3: 3,
          a4: v64,
          a5: v61,
          a6: 0,
          a7: 0,
          a8: 0);
        break;
      default:
        break;
    }
  }
  else
  {
    v4 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
           size: 0x14u,
           tag: TAG_SWF,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    if ( v4 != nullptr )
    {
      v5 = this->mainMenu;
      v4[1] = 0;
      v6 = v4;
      v4[3] = 0;
      v4[4] = 10;
      *v4 = &`idMainMenu::ExitGameConfirm'::`2'::idSWFScriptFunction_CancelExit::`vftable';
      v4[2] = v5;
    }
    else
    {
      v6 = nullptr;
    }
    v7 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
           size: 0x18u,
           tag: TAG_SWF,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    if ( v7 != nullptr )
    {
      v8 = this->mainMenu;
      v7[5] = p_currentDeviceIndex;
      v9 = v7;
      v7[1] = 0;
      v7[3] = 0;
      *v7 = &`idMainMenu::ExitGameConfirm'::`3'::idSWFScriptFunction_AcceptExit::`vftable';
      v7[2] = v8;
      v7[4] = 10;
    }
    else
    {
      v9 = nullptr;
    }
    ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
      a1: common,
      a2: 10,
      a3: 2,
      a4: v9,
      a5: v6,
      a6: 0,
      a7: 0,
      a8: 0);
  }
}


// ========================================================================
// ?DeleteSaveGame@idMainMenu@@QAAXH@Z
// EA  : 0x82DA4F80
// RVA : 0x00DA4F80
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::DeleteSaveGame(idMainMenu *this, int saveIndex)
{
  const char *num; // r30
  idStr v3[3]; // [sp+50h] [-80h] BYREF

  num = (const char *)idSaveGameDetails::GetSlotName(
                        this: (idSaveGameDetails *)v3,
                        result: (idStrStatic<64> *)&session->saveGameManager->enumeratedSaveGames.list[saveIndex])->descriptors.args.num;
  idStr::FreeData(this: v3);
  session->DeleteSaveGameSync(this: session, a2: num);
}


// ========================================================================
// ?MarkSaveGameAsCorrupt@idMainMenu@@QAAXPBD@Z
// EA  : 0x82DA5008
// RVA : 0x00DA5008
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::MarkSaveGameAsCorrupt(idMainMenu *this, const char *folder)
{
  int v3; // r28
  idSaveGameManager *saveGameManager; // r11
  idStaticList<idSaveGameDetails,16> *p_enumeratedSaveGames; // r30
  int i; // r29
  idSaveGameDetails *SlotName; // r3
  BOOL v8; // r26
  idSaveGameDetails v9; // [sp+50h] [-A0h] BYREF

  v3 = 0;
  saveGameManager = session->saveGameManager;
  p_enumeratedSaveGames = &saveGameManager->enumeratedSaveGames;
  if ( saveGameManager->enumeratedSaveGames.num > 0 )
  {
    for ( i = 0; ; ++i )
    {
      SlotName = idSaveGameDetails::GetSlotName(this: &v9, result: (idStrStatic<64> *)&p_enumeratedSaveGames->list[i]);
      v8 = (_cntlzw(idStr::Icmp(s1: (const char *)SlotName->descriptors.args.num, s2: folder)) & 0x20) != 0;
      idStr::FreeData(this: (idStr *)&v9);
      if ( v8 )
        break;
      if ( ++v3 >= p_enumeratedSaveGames->num )
        return;
    }
    p_enumeratedSaveGames->list[v3].damaged = true;
  }
}


// ========================================================================
// __unwind$523370
// EA  : 0x82DA50B0
// RVA : 0x00DA50B0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_523370()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// ?RebindAction@idMainMenu@@QAAXPBUsysEvent_t@@@Z
// EA  : 0x82DA50E0
// RVA : 0x00DA50E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::RebindAction(idMainMenu *this, const sysEvent_t *sev)
{
  _DWORD *v4; // r3
  idSWF *mainMenu; // r11
  _DWORD *v6; // r6
  char *Binding; // r24
  int v8; // r11
  cmdGenButton_t v9; // r3
  inputType_t v10; // r6
  unsigned int bindSet; // r4
  int v12; // r3
  unsigned __int8 v13; // r11
  int v14; // r29
  int v15; // r11
  inputType_t v16; // r6
  cmdGenButton_t v17; // r3
  unsigned int v18; // r4
  bool v19; // r28
  int v20; // r3
  idSWFScriptVar *PlayerProfileByInputDevice; // r23
  _DWORD *v22; // r3
  idSWF *v23; // r11
  _DWORD *v24; // r25
  idMainMenu *v25; // r28
  idStr *v26; // r26
  idStr *v27; // r3
  int v28; // r3
  int v29; // r6
  _DWORD *v30; // r3
  idSWF *v31; // r11
  _DWORD *v32; // r25
  idMainMenu *v33; // r28
  idStr *v34; // r3
  int v35; // r3
  int v36; // r6
  int v37; // [sp+8h] [-118h]
  int v38; // [sp+Ch] [-114h]
  int v39; // [sp+10h] [-110h]
  int v40; // [sp+14h] [-10Ch]
  int v41; // [sp+18h] [-108h]
  int v42; // [sp+1Ch] [-104h]
  int v43; // [sp+20h] [-100h]
  int v44; // [sp+24h] [-FCh]
  int v45; // [sp+28h] [-F8h]
  int v46; // [sp+2Ch] [-F4h]
  int v47; // [sp+30h] [-F0h]
  int v48; // [sp+34h] [-ECh]
  int v49; // [sp+38h] [-E8h]
  int v50; // [sp+3Ch] [-E4h]
  int v51; // [sp+40h] [-E0h]
  int v52; // [sp+44h] [-DCh]
  int v53; // [sp+48h] [-D8h]
  int v54; // [sp+4Ch] [-D4h]
  int v55; // [sp+50h] [-D0h]
  int evValue; // [sp+70h] [-B0h]
  idStr v57; // [sp+80h] [-A0h] BYREF
  idStr v58[4]; // [sp+A0h] [-80h] BYREF

  evValue = sev->evValue;
  if ( evValue == 0 || sev->evValue2 == 0 || sev->evType == SE_JOYSTICK || this->bindAction.len == 0 )
    return;
  if ( (unsigned __int8)idKeyInput::IsValidRebindKey(keyNum: evValue) == 0 )
  {
    v4 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
           size: 0x10u,
           tag: TAG_SWF,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    if ( v4 != nullptr )
    {
      mainMenu = this->mainMenu;
      v4[2] = this;
      v6 = v4;
      v4[1] = 0;
      *v4 = &`idMainMenu::RebindAction'::`11'::idSWFScriptFunction_CancelInvalidBind::`vftable';
      v4[3] = mainMenu;
    }
    else
    {
      v6 = nullptr;
    }
    ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD *, _DWORD, _DWORD, _DWORD, _DWORD))common->AddDialog)(
      a1: common,
      a2: 49,
      a3: 0,
      a4: v6,
      a5: 0,
      a6: 0,
      a7: 0,
      a8: 0);
    return;
  }
  Binding = idKeyInput::GetBinding(numDevice: sev->inputDevice, bindset: this->bindSet, keynum: (keyNum_t)sev->evValue);
  if ( idStr::Icmp(s1: Binding, s2: &byte_8200D768) != 0 )
  {
    v19 = idStr::Icmp(s1: this->bindAction.data, s2: Binding) == 0;
    v20 = common->GetFocusDeviceNum(this: common);
    PlayerProfileByInputDevice = (idSWFScriptVar *)idSignInManagerBase::GetPlayerProfileByInputDevice(
                                                     this: session->signInManager,
                                                     index: v20);
    if ( v19 )
    {
      v30 = idMem::AllocWithLocation(
              this: &mem,
              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
              size: 0x14u,
              tag: TAG_SWF,
              zeroBuffer: false,
              align: ALIGN_16,
              heap: HEAP_DEFAULTHEAP);
      if ( v30 != nullptr )
      {
        v31 = this->mainMenu;
        v30[2] = this;
        v30[1] = 0;
        v32 = v30;
        v30[4] = 85;
        *v30 = &`idMainMenu::RebindAction'::`51'::idSWFScriptFunction_CancelBind::`vftable';
        v30[3] = v31;
      }
      else
      {
        v32 = nullptr;
      }
      v33 = (idMainMenu *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x40u,
                            tag: TAG_SWF,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
      if ( v33 != nullptr )
      {
        v34 = idStr::idStr(this: v58, text: &this->bindAction);
        _idMainMenu::RebindAction_::_53_::idSWFScriptFunction_ConfirmUnbind::idSWFScriptFunction_ConfirmUnbind(
          _menu: v33,
          _swf: (idSWF *)this,
          _action: (idSWFScriptObject *)this->mainMenu,
          _bindSet: v34,
          _ininputDevice: (idSWFScriptVar::swfScriptVarValue_t *)this->bindSet,
          _profile: (idPlayerProfile *)sev->inputDevice,
          _keyNum: PlayerProfileByInputDevice,
          a8: (idSWFScriptVar::swfScriptVarType)sev->evValue);
        v36 = v35;
      }
      else
      {
        v36 = 0;
      }
      ((void (__fastcall *)(idCommon *, int, int, int, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
        a1: common,
        a2: 85,
        a3: 2,
        a4: v36,
        a5: v32,
        a6: 0,
        a7: 0,
        a8: 0);
    }
    else
    {
      v22 = idMem::AllocWithLocation(
              this: &mem,
              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
              size: 0x14u,
              tag: TAG_SWF,
              zeroBuffer: false,
              align: ALIGN_16,
              heap: HEAP_DEFAULTHEAP);
      if ( v22 != nullptr )
      {
        v23 = this->mainMenu;
        v22[2] = this;
        v22[1] = 0;
        v24 = v22;
        v22[4] = 48;
        *v22 = &`idMainMenu::RebindAction'::`51'::idSWFScriptFunction_CancelBind::`vftable';
        v22[3] = v23;
      }
      else
      {
        v24 = nullptr;
      }
      v25 = (idMainMenu *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x60u,
                            tag: TAG_SWF,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
      if ( v25 != nullptr )
      {
        v26 = idStr::idStr(this: &v57, text: Binding);
        v27 = idStr::idStr(this: v58, text: &this->bindAction);
        _idMainMenu::RebindAction_::_52_::idSWFScriptFunction_AcceptBind::idSWFScriptFunction_AcceptBind(
          _menu: v25,
          _swf: (idSWF *)this,
          _action: (idSWFScriptObject *)this->mainMenu,
          _oldAction: v27,
          _keyNum: v26,
          _bindSet: (idSWFScriptVar::swfScriptVarValue_t *)sev->evValue,
          _ininputDevice: (idSWFScriptVar::swfScriptVarType)this->bindSet,
          _profile: (idPlayerProfile *)sev->inputDevice,
          a9: v37,
          a10: v38,
          a11: v39,
          a12: v40,
          a13: v41,
          a14: v42,
          a15: v43,
          a16: v44,
          a17: v45,
          a18: v46,
          a19: v47,
          a20: v48,
          a21: v49,
          a22: v50,
          a23: v51,
          a24: v52,
          a25: v53,
          a26: v54,
          a27: v55,
          a28: PlayerProfileByInputDevice);
        v29 = v28;
      }
      else
      {
        v29 = 0;
      }
      ((void (__fastcall *)(idCommon *, int, int, int, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
        a1: common,
        a2: 48,
        a3: 2,
        a4: v29,
        a5: v24,
        a6: 0,
        a7: 0,
        a8: 0);
    }
    return;
  }
  v8 = sev->evValue;
  if ( v8 < 286 || v8 > 295 )
  {
    bindSet = this->bindSet;
    v10 = INPUT_TYPE_KEYBOARD;
  }
  else
  {
    idKeyInput::UnbindBinding(
      numDevice: sev->inputDevice,
      bindset: this->bindSet,
      binding: this->bindAction.data,
      inputType: INPUT_TYPE_MOUSE);
    if ( this->bindSet != 0 )
      goto LABEL_21;
    v9 = usercmdGen->BindStringUsercmdAction(this: usercmdGen, a2: this->bindAction.data);
    if ( v9 != UB_MOVEFORWARD && v9 != UB_MOVEBACK && v9 != UB_MOVELEFT && v9 != UB_MOVERIGHT )
      goto LABEL_21;
    v10 = INPUT_TYPE_MOUSE;
    bindSet = 3;
  }
  idKeyInput::UnbindBinding(
    numDevice: sev->inputDevice,
    bindset: bindSet,
    binding: this->bindAction.data,
    inputType: v10);
LABEL_21:
  if ( idStr::Cmp(s1: this->bindAction.data, s2: "voicechat_talk") == 0
    || (v12 = idStr::Cmp(s1: this->bindAction.data, s2: "messagemode"), v13 = 0, v12 == 0) )
  {
    v13 = 1;
  }
  v14 = v13;
  if ( v13 != 0 )
  {
    v15 = sev->evValue;
    if ( v15 < 286 || v15 > 295 )
    {
      idKeyInput::UnbindBinding(
        numDevice: sev->inputDevice,
        bindset: 0,
        binding: this->bindAction.data,
        inputType: INPUT_TYPE_KEYBOARD);
      v16 = INPUT_TYPE_KEYBOARD;
    }
    else
    {
      idKeyInput::UnbindBinding(
        numDevice: sev->inputDevice,
        bindset: 0,
        binding: this->bindAction.data,
        inputType: INPUT_TYPE_MOUSE);
      v16 = INPUT_TYPE_MOUSE;
    }
    idKeyInput::UnbindBinding(numDevice: sev->inputDevice, bindset: 2u, binding: this->bindAction.data, inputType: v16);
  }
  idKeyInput::SetBinding(
    numDevice: sev->inputDevice,
    bindset: this->bindSet,
    keynum: (keyNum_t)sev->evValue,
    binding: this->bindAction.data);
  if ( this->bindSet == 0 )
  {
    v17 = usercmdGen->BindStringUsercmdAction(this: usercmdGen, a2: this->bindAction.data);
    if ( v17 == UB_MOVEFORWARD || v17 == UB_MOVEBACK || v17 == UB_MOVELEFT || v17 == UB_MOVERIGHT )
      idKeyInput::SetBinding(
        numDevice: sev->inputDevice,
        bindset: 3u,
        keynum: (keyNum_t)sev->evValue,
        binding: this->bindAction.data);
  }
  if ( v14 != 0 )
  {
    v18 = 2;
    if ( this->bindSet != 0 )
      v18 = 0;
    idKeyInput::SetBinding(
      numDevice: sev->inputDevice,
      bindset: v18,
      keynum: (keyNum_t)sev->evValue,
      binding: this->bindAction.data);
  }
  this->finishBinding = true;
  this->bindWaitKey = sev->evValue;
}


// ========================================================================
// __unwind$523462
// EA  : 0x82DA5658
// RVA : 0x00DA5658
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_523462()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 288 + 112), tag: TAG_SWF);
}


// ========================================================================
// __unwind$523463
// EA  : 0x82DA5684
// RVA : 0x00DA5684
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_523463()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 288 + 116));
}


// ========================================================================
// __unwind$523466
// EA  : 0x82DA56AC
// RVA : 0x00DA56AC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_523466()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 288 + 116), tag: TAG_SWF);
}


// ========================================================================
// ?ConfirmBindingReset@idMainMenu@@QAAXXZ
// EA  : 0x82DA56D8
// RVA : 0x00DA56D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::ConfirmBindingReset(idMainMenu *this)
{
  int v2; // r3
  idPlayerProfile *PlayerProfileByInputDevice; // r26
  _DWORD *v4; // r3
  idSWF *mainMenu; // r11
  _DWORD *v6; // r25
  _DWORD *v7; // r3
  idSWF *v8; // r11
  _DWORD *v9; // r6

  v2 = common->GetFocusDeviceNum(this: common);
  PlayerProfileByInputDevice = idSignInManagerBase::GetPlayerProfileByInputDevice(
                                 this: session->signInManager,
                                 index: v2);
  v4 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
         size: 0xCu,
         tag: TAG_SWF,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
  {
    mainMenu = this->mainMenu;
    v4[1] = 0;
    v6 = v4;
    *v4 = &`idMainMenu::ConfirmBindingReset'::`2'::idSWFScriptFunction_CancelRestore::`vftable';
    v4[2] = mainMenu;
  }
  else
  {
    v6 = nullptr;
  }
  v7 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
         size: 0x10u,
         tag: TAG_SWF,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
  {
    v8 = this->mainMenu;
    v7[3] = PlayerProfileByInputDevice;
    v9 = v7;
    v7[1] = 0;
    *v7 = &`idMainMenu::ConfirmBindingReset'::`3'::idSWFScriptFunction_AcceptRestore::`vftable';
    v7[2] = v8;
  }
  else
  {
    v9 = nullptr;
  }
  ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
    a1: common,
    a2: 86,
    a3: 2,
    a4: v9,
    a5: v6,
    a6: 0,
    a7: 0,
    a8: 0);
}


// ========================================================================
// ?CalculateBenchmark@idMainMenu@@QAAXXZ
// EA  : 0x82DA5808
// RVA : 0x00DA5808
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::CalculateBenchmark(idMainMenu *this)
{
  int v1; // r8
  void (*ClearDialog)(void); // ctr
  void (__fastcall *AddDialogIntVal)(idCommon *, const char *, int); // ctr
  _DWORD *v4; // r3
  _DWORD *v5; // r6
  float v6; // [sp+70h] [-30h] BYREF
  float v7; // [sp+74h] [-2Ch] BYREF
  int v9; // [sp+7Ch] [-24h]

  ((void (__fastcall *)(idCommon *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))common->AddDialog)(
    a1: common,
    a2: 127,
    a3: 5,
    a4: 0,
    a5: 0,
    a6: 0,
    a7: 0,
    a8: 0);
  v6 = 0.0;
  v7 = 0.0;
  v1 = (unsigned __int8)idVirtualTextureSystem::RunTranscodeBenchmark(
                          this: &virtualTextureSystem,
                          megaTexelsPerSecond: &v6,
                          score: &v7);
  ClearDialog = (void (*)(void))common->ClearDialog;
  if ( v1 != 0 )
  {
    ClearDialog();
    v9 = (int)v6;
    common->AddDialogIntVal(this: common, a2: "texelsPerSecond", a3: v9);
    AddDialogIntVal = common->AddDialogIntVal;
    v9 = (int)(float)(v7 * (float)100.0);
    AddDialogIntVal(this: common, a2: "benchmarkScore", a3: v9);
    v4 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
           size: 8u,
           tag: TAG_SWF,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    if ( v4 != nullptr )
    {
      v4[1] = 0;
      v5 = v4;
      *v4 = &`idMainMenu::CalculateBenchmark'::`5'::idSWFScriptFunction_BenchmarkComplete::`vftable';
    }
    else
    {
      v5 = nullptr;
    }
    ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD, _DWORD, _DWORD, _DWORD))common->AddDialog)(
      a1: common,
      a2: 128,
      a3: 13,
      a4: v5,
      a5: 0,
      a6: 0,
      a7: 0,
      a8: 0);
  }
  else
  {
    ClearDialog();
  }
}


// ========================================================================
// ?ShowDisplaySettingFailedMessage@idMainMenu@@QAA_NXZ
// EA  : 0x82DA59C0
// RVA : 0x00DA59C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

int __fastcall idMainMenu::ShowDisplaySettingFailedMessage(idMainMenu *this)
{
  _DWORD *v2; // r3
  idSWF *mainMenu; // r11
  _DWORD *v4; // r6

  if ( !failedToApplySettings )
    return 0;
  failedToApplySettings = false;
  gameLocal->waitingOnVideoSettingsConfirm = true;
  v2 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
         size: 0x10u,
         tag: TAG_SWF,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
  {
    mainMenu = this->mainMenu;
    v2[1] = 0;
    v4 = v2;
    v2[3] = 129;
    *v2 = &`idMainMenu::ShowDisplaySettingFailedMessage'::`5'::idSWFScriptFunction_AcceptFailedChanges::`vftable';
    v2[2] = mainMenu;
  }
  else
  {
    v4 = nullptr;
  }
  ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD *, _DWORD, _DWORD, _DWORD, _DWORD))common->AddDialog)(
    a1: common,
    a2: 129,
    a3: 0,
    a4: v4,
    a5: 0,
    a6: 0,
    a7: 0,
    a8: 0);
  return 1;
}


// ========================================================================
// ?SaveSettings@idMainMenu@@QAAXXZ
// EA  : 0x82DA5AC8
// RVA : 0x00DA5AC8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::SaveSettings(idMainMenu *this)
{
  int v1; // r3
  idPlayerProfile *PlayerProfileByInputDevice; // r3

  if ( (unsigned __int8)idMainMenu::ShowDisplaySettingFailedMessage(this) == 0 )
  {
    v1 = common->GetFocusDeviceNum(this: common);
    PlayerProfileByInputDevice = idSignInManagerBase::GetPlayerProfileByInputDevice(
                                   this: session->signInManager,
                                   index: v1);
    if ( PlayerProfileByInputDevice != nullptr )
      idPlayerProfile::SaveSettings(this: PlayerProfileByInputDevice);
  }
}


// ========================================================================
// `idMainMenu::ShowOverwriteSavingDialog'::`6'::idSWFScriptFunction_AcceptOverwrite::Call
// EA  : 0x82DA5B30
// RVA : 0x00DA5B30
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::ShowOverwriteSavingDialog_::_6_::idSWFScriptFunction_AcceptOverwrite::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu::GameSave(this: (idMainMenu *)thisObject->variables.num, index: thisObject->variables.size);
  common->ClearDialog(this: common, a2: GDM_OVERWRITE_SAVE, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idMainMenu::DeleteSaveGameConfirm'::`3'::idSWFScriptFunction_AcceptDelete::Call
// EA  : 0x82DA5B98
// RVA : 0x00DA5B98
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::DeleteSaveGameConfirm_::_3_::idSWFScriptFunction_AcceptDelete::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  common->ClearDialog(this: common, a2: GDM_DELETE_SAVE, a3: nullptr, a4: 0);
  ((void (__fastcall *)(idCommon *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))common->AddDialog)(
    a1: common,
    a2: 47,
    a3: 5,
    a4: 0,
    a5: 0,
    a6: 0,
    a7: 0,
    a8: 0);
  idMainMenu::DeleteSaveGame(this: (idMainMenu *)thisObject->variables.num, saveIndex: thisObject->variables.size);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idMainMenu::CanStartNewGame'::`9'::idSWFScriptFunction_SelectDevice::Call
// EA  : 0x82DA5C30
// RVA : 0x00DA5C30
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::CanStartNewGame_::_9_::idSWFScriptFunction_SelectDevice::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idLocalUserXbox *v5; // r28
  idSignInManagerXbox *signInManager; // r27
  unsigned __int64 v7; // r6
  bool v8; // r8

  v5 = (idLocalUserXbox *)common->GetMasterLocalUser(this: common);
  signInManager = (idSignInManagerXbox *)session->signInManager;
  HIDWORD(v7) = gameLocal->GetMinSaveStorageRequired(this: gameLocal, a2: true);
  LODWORD(v7) = 1;
  idSignInManagerXbox::RequestDeviceSelector(
    this: signInManager,
    user: v5,
    minSizeInBytes: v7,
    forceShow: 1u,
    manageDeviceEnabled: v8);
  *(_BYTE *)(thisObject->variables.num + 898) = 1;
  common->ClearDialog(this: common, a2: GDM_INSUFFICENT_STORAGE_SPACE, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idMainMenu::LoadDamagedGame'::`5'::idSWFScriptFunction_AcceptDelete::Call
// EA  : 0x82DA5CE0
// RVA : 0x00DA5CE0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::LoadDamagedGame_::_5_::idSWFScriptFunction_AcceptDelete::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  common->ClearDialog(this: common, a2: (gameDialogMessages_t)thisObject->variables.size, a3: nullptr, a4: 0);
  idMainMenu::DeleteSaveGameConfirm(
    this: (idMainMenu *)thisObject->variables.num,
    saveIndex: *(_DWORD *)&thisObject->variables.granularity);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idMainMenu::RebindAction'::`52'::idSWFScriptFunction_AcceptBind::Call
// EA  : 0x82DA5D50
// RVA : 0x00DA5D50
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::RebindAction_::_52_::idSWFScriptFunction_AcceptBind::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject *prototype; // r11
  inputType_t v6; // r6
  unsigned int v7; // r28
  int v8; // r3
  unsigned __int8 v9; // r11
  int v10; // r27
  idSWFScriptObject *v11; // r11
  inputType_t v12; // r6
  int v13; // r3
  char v14; // r11
  idSWFScriptObject *v15; // r11
  inputType_t v16; // r6
  idPlayerProfile *v17; // r3

  *(_BYTE *)(thisObject->variables.num + 740) = 0;
  prototype = thisObject->prototype;
  if ( (int)prototype < 286 || (int)prototype > 295 )
  {
    idKeyInput::UnbindBinding(
      numDevice: (unsigned int)thisObject->data.sprite,
      bindset: thisObject->objectType,
      binding: (const char *)thisObject->variablesHash[1],
      inputType: INPUT_TYPE_KEYBOARD);
    v6 = INPUT_TYPE_KEYBOARD;
  }
  else
  {
    idKeyInput::UnbindBinding(
      numDevice: (unsigned int)thisObject->data.sprite,
      bindset: thisObject->objectType,
      binding: (const char *)thisObject->variablesHash[1],
      inputType: INPUT_TYPE_MOUSE);
    v6 = INPUT_TYPE_MOUSE;
  }
  idKeyInput::UnbindBinding(
    numDevice: (unsigned int)thisObject->data.sprite,
    bindset: thisObject->objectType,
    binding: (const char *)thisObject->variablesHash[9],
    inputType: v6);
  v7 = thisObject->objectType != SWF_OBJECT_OBJECT ? 0 : 2;
  if ( idStr::Cmp(s1: (const char *)thisObject->variablesHash[1], s2: "voicechat_talk") == 0
    || (v8 = idStr::Cmp(s1: (const char *)thisObject->variablesHash[1], s2: "messagemode"), v9 = 0, v8 == 0) )
  {
    v9 = 1;
  }
  v10 = v9;
  if ( v9 != 0 )
  {
    v11 = thisObject->prototype;
    if ( (int)v11 < 286 || (v12 = INPUT_TYPE_MOUSE, (int)v11 > 295) )
      v12 = INPUT_TYPE_KEYBOARD;
    idKeyInput::UnbindBinding(
      numDevice: (unsigned int)thisObject->data.sprite,
      bindset: v7,
      binding: (const char *)thisObject->variablesHash[1],
      inputType: v12);
  }
  if ( idStr::Cmp(s1: (const char *)thisObject->variablesHash[9], s2: "voicechat_talk") == 0
    || (v13 = idStr::Cmp(s1: (const char *)thisObject->variablesHash[9], s2: "messagemode"), v14 = 0, v13 == 0) )
  {
    v14 = 1;
  }
  if ( v14 != 0 )
  {
    v15 = thisObject->prototype;
    if ( (int)v15 < 286 || (v16 = INPUT_TYPE_MOUSE, (int)v15 > 295) )
      v16 = INPUT_TYPE_KEYBOARD;
    idKeyInput::UnbindBinding(
      numDevice: (unsigned int)thisObject->data.sprite,
      bindset: v7,
      binding: (const char *)thisObject->variablesHash[9],
      inputType: v16);
  }
  idKeyInput::SetBinding(
    numDevice: (unsigned int)thisObject->data.sprite,
    bindset: thisObject->objectType,
    keynum: (keyNum_t)thisObject->prototype,
    binding: (const char *)thisObject->variablesHash[1]);
  if ( v10 != 0 )
    idKeyInput::SetBinding(
      numDevice: (unsigned int)thisObject->data.sprite,
      bindset: v7,
      keynum: (keyNum_t)thisObject->prototype,
      binding: (const char *)thisObject->variablesHash[1]);
  v17 = *(idPlayerProfile **)&thisObject->variables.granularity;
  if ( v17 != nullptr )
    idPlayerProfile::SaveSettings(this: v17);
  idCVar::SetBool(this: &swf_updateKeyBindings, newValue: true, force: true);
  common->ClearDialog(this: common, a2: GDM_BINDING_ALREDY_SET, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idMainMenu::RebindAction'::`53'::idSWFScriptFunction_ConfirmUnbind::Call
// EA  : 0x82DA5F48
// RVA : 0x00DA5F48
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::RebindAction_::_53_::idSWFScriptFunction_ConfirmUnbind::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r11
  inputType_t v6; // r6
  idPlayerProfile *v7; // r3

  *(_BYTE *)(thisObject->variables.num + 740) = 0;
  v5 = thisObject->variablesHash[9];
  if ( v5 < 286 || (v6 = INPUT_TYPE_MOUSE, v5 > 295) )
    v6 = INPUT_TYPE_KEYBOARD;
  idKeyInput::UnbindBinding(
    numDevice: thisObject->variablesHash[10],
    bindset: thisObject->variablesHash[8],
    binding: (const char *)thisObject->variablesHash[1],
    inputType: v6);
  v7 = *(idPlayerProfile **)&thisObject->variables.granularity;
  if ( v7 != nullptr )
    idPlayerProfile::SaveSettings(this: v7);
  idCVar::SetBool(this: &swf_updateKeyBindings, newValue: true, force: true);
  common->ClearDialog(this: common, a2: GDM_UNBIND_CONFIRM, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idMainMenu::ConfirmBindingReset'::`2'::idSWFScriptFunction_CancelRestore::Call
// EA  : 0x82DA6008
// RVA : 0x00DA6008
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::ConfirmBindingReset_::_2_::idSWFScriptFunction_CancelRestore::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  common->ClearDialog(this: common, a2: GDM_BINDINGS_RESTORE, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setState@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6060
// RVA : 0x00DA6060
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setState *__fastcall idMainMenu::idSWFScriptFunction_setState::Call(
        idMainMenu::idSWFScriptFunction_setState *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms,
        int a5,
        int a6,
        int a7)
{
  idSWFScriptVar::swfScriptVarType type; // r11
  char v9; // r11
  bool v10; // zf
  unsigned int v11; // r3
  unsigned int v12; // r31
  idMainMenu *mainMenu; // r7
  int menuState; // r6

  if ( parms->num < 1 )
    goto LABEL_10;
  type = parms->list->type;
  if ( type == SWF_VAR_FLOAT || type == SWF_VAR_INTEGER || (v10 = type != SWF_VAR_BOOL, v9 = 0, !v10) )
    v9 = 1;
  if ( v9 != 0 )
  {
    v11 = idSWFScriptVar::ToInteger(this: parms->list);
    v12 = v11;
    if ( v11 > 4 )
      idLib::Warning(fmt: "Invalid state specified for setState: %d", v11);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setState_vtbl *)4;
    mainMenu = gameLocal->mainMenu;
    menuState = mainMenu->menuState;
    mainMenu->menuState = v12;
    mainMenu->lastMenuState = menuState;
  }
  else
  {
LABEL_10:
    idLib::Warning(fmt: "Invalid parameters specified for setState", result, thisObject, parms, a5, a6, a7, 0);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setState_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_registerUserMouse@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6140
// RVA : 0x00DA6140
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_registerUserMouse *__fastcall idMainMenu::idSWFScriptFunction_registerUserMouse::Call(
        idMainMenu::idSWFScriptFunction_registerUserMouse *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r3

  if ( parms->num == 1 )
  {
    v5 = idSWFScriptVar::ToInteger(this: parms->list);
    session->signInManager->RegisterLocalUser(this: session->signInManager, a2: v5);
  }
  else
  {
    idLib::Warning(fmt: "No device specified when registering mouse user", result, thisObject);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_registerUserMouse_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_quitGame@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA61C0
// RVA : 0x00DA61C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_quitGame *__fastcall idMainMenu::idSWFScriptFunction_quitGame::Call(
        idMainMenu::idSWFScriptFunction_quitGame *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  _DWORD *v5; // r3
  _DWORD *v6; // r27
  _DWORD *v7; // r3
  _DWORD *v8; // r6

  v5 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
         size: 8u,
         tag: TAG_SWF,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
  {
    v5[1] = 0;
    v6 = v5;
    *v5 = &`idMainMenu::idSWFScriptFunction_quitGame::Call'::`3'::idSWFScriptFunction_DeclineQuit::`vftable';
  }
  else
  {
    v6 = nullptr;
  }
  v7 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
         size: 8u,
         tag: TAG_SWF,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
  {
    v7[1] = 0;
    v8 = v7;
    *v7 = &`idMainMenu::idSWFScriptFunction_quitGame::Call'::`2'::idSWFScriptFunction_AcceptQuit::`vftable';
  }
  else
  {
    v8 = nullptr;
  }
  ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
    a1: common,
    a2: 66,
    a3: 3,
    a4: v8,
    a5: v6,
    a6: 0,
    a7: 0,
    a8: 0);
  this->__vftable = (idMainMenu::idSWFScriptFunction_quitGame_vtbl *)4;
  return this;
}


// ========================================================================
// `idMainMenu::idSWFScriptFunction_quitGame::Call'::`2'::idSWFScriptFunction_AcceptQuit::Call
// EA  : 0x82DA62C0
// RVA : 0x00DA62C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::idSWFScriptFunction_quitGame::Call_::_2_::idSWFScriptFunction_AcceptQuit::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  common->ClearDialog(this: common, a2: GDM_QUIT_GAME, a3: nullptr, a4: 0);
  common->Quit(this: common, a2: 0);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idMainMenu::idSWFScriptFunction_quitGame::Call'::`3'::idSWFScriptFunction_DeclineQuit::Call
// EA  : 0x82DA6338
// RVA : 0x00DA6338
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::idSWFScriptFunction_quitGame::Call_::_3_::idSWFScriptFunction_DeclineQuit::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  common->ClearDialog(this: common, a2: GDM_QUIT_GAME, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?Call@idSWFScriptFunction_moveBetweenSPAndMP@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6390
// RVA : 0x00DA6390
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_moveBetweenSPAndMP *__fastcall idMainMenu::idSWFScriptFunction_moveBetweenSPAndMP::Call(
        idMainMenu::idSWFScriptFunction_moveBetweenSPAndMP *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  menuSwitchRequest_t v4; // r9

  v4 = MENU_SWITCH_MP;
  if ( com_multiplayer.valueInteger != 0 )
    v4 = MENU_SWITCH_SP;
  gameLocal->mainMenu->menuRequest = v4;
  this->__vftable = (idMainMenu::idSWFScriptFunction_moveBetweenSPAndMP_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setGameDifficulty@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA63D0
// RVA : 0x00DA63D0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setGameDifficulty *__fastcall idMainMenu::idSWFScriptFunction_setGameDifficulty::Call(
        idMainMenu::idSWFScriptFunction_setGameDifficulty *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r3

  if ( parms->num == 1 )
  {
    v5 = idSWFScriptVar::ToInteger(this: parms->list);
    idGameLocal::SetGameDifficulty(this: gameLocal, difficulty: v5);
    session->UpdateRichPresence(this: session);
  }
  else
  {
    idLib::Warning(fmt: "no difficulty value passed in to set difficulty", result, thisObject);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_setGameDifficulty_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setNewGameDifficulty@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6458
// RVA : 0x00DA6458
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setNewGameDifficulty *__fastcall idMainMenu::idSWFScriptFunction_setNewGameDifficulty::Call(
        idMainMenu::idSWFScriptFunction_setNewGameDifficulty *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r3

  if ( parms->num == 1 )
  {
    v5 = idSWFScriptVar::ToInteger(this: parms->list);
    idGameLocal::SetNewGameDifficulty(this: gameLocal, difficulty: v5);
  }
  else
  {
    idLib::Warning(fmt: "no difficulty value passed in to set difficulty", result, thisObject);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_setNewGameDifficulty_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_clearWaitForCredits@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA64C0
// RVA : 0x00DA64C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_clearWaitForCredits *__fastcall idMainMenu::idSWFScriptFunction_clearWaitForCredits::Call(
        idMainMenu::idSWFScriptFunction_clearWaitForCredits *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idCVar::SetBool(this: &swf_waitForCredits, newValue: false, force: true);
  this->__vftable = (idMainMenu::idSWFScriptFunction_clearWaitForCredits_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_isProfileScreenOpen@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6508
// RVA : 0x00DA6508
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_isProfileScreenOpen *__fastcall idMainMenu::idSWFScriptFunction_isProfileScreenOpen::Call(
        idMainMenu::idSWFScriptFunction_isProfileScreenOpen *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *mainMenu; // r30

  if ( parms->num == 1 )
  {
    mainMenu = gameLocal->mainMenu;
    mainMenu->isProfileScreenOpenBool = idSWFScriptVar::ToBool(this: parms->list);
  }
  else
  {
    idLib::Warning(fmt: "no difficulty value passed in to set difficulty", result, thisObject);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_isProfileScreenOpen_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setNewGame@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6588
// RVA : 0x00DA6588
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setNewGame *__fastcall idMainMenu::idSWFScriptFunction_setNewGame::Call(
        idMainMenu::idSWFScriptFunction_setNewGame *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idCVar::SetInteger(this: &swf_loadScreenAlternate, newValue: 2, force: true);
  this->__vftable = (idMainMenu::idSWFScriptFunction_setNewGame_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_loadDevMenuOption@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA65D8
// RVA : 0x00DA65D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_loadDevMenuOption *__fastcall idMainMenu::idSWFScriptFunction_loadDevMenuOption::Call(
        idMainMenu::idSWFScriptFunction_loadDevMenuOption *this,
        idSWFScriptVar *result,
        __int64 parms,
        __int64 a4,
        __int64 a5)
{
  idSWFScriptVar **v6; // r29
  idStr *v7; // r4
  int v8; // r11
  char v9; // r11
  bool v10; // zf
  int v11; // r3
  __int64 v12; // r10
  __int64 v13; // r8
  va *v14; // r3
  int v16; // [sp+8h] [-1098h]
  int v17; // [sp+Ch] [-1094h]
  int v18; // [sp+10h] [-1090h]
  int v19; // [sp+14h] [-108Ch]
  int v20; // [sp+18h] [-1088h]
  int v21; // [sp+1Ch] [-1084h]
  idStr v22; // [sp+60h] [-1040h] BYREF
  va v23; // [sp+80h] [-1020h] BYREF

  v6 = (idSWFScriptVar **)parms;
  LODWORD(a5) = *(_DWORD *)(parms + 4);
  if ( (int)a5 < 2 )
    goto LABEL_9;
  v7 = *(idStr **)parms;
  v8 = **(_DWORD **)parms;
  if ( v8 == 3 )
    goto LABEL_9;
  if ( v8 == 1 || (v10 = v8 != 0, v9 = 0, !v10) )
    v9 = 1;
  if ( v9 == 0 || v7->allocedAndFlag == 3 )
  {
LABEL_9:
    idLib::Warning(fmt: "loadDevMenuOption called with bad arguments");
    this->__vftable = (idMainMenu::idSWFScriptFunction_loadDevMenuOption_vtbl *)4;
    return this;
  }
  else
  {
    idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v22, result: v7, a3: parms, a4, a5);
    v11 = idSWFScriptVar::ToInteger(this: *v6 + 1);
    v14 = va::va(
            this: &v23,
            fmt: "loadDevMenuOption %s %d\n",
            a3: __SPAIR64__((unsigned int)v22.data, v11),
            a4: v13,
            a5: v12,
            a6: v16,
            a7: v17,
            a8: v18,
            a9: v19,
            a10: v20,
            a11: v21);
    cmdSystem->AppendCommandText(this: cmdSystem, a2: v14->buffer);
    this->__vftable = (idMainMenu::idSWFScriptFunction_loadDevMenuOption_vtbl *)4;
    idStr::FreeData(this: &v22);
    return this;
  }
}


// ========================================================================
// __unwind$524903
// EA  : 0x82DA66E0
// RVA : 0x00DA66E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_524903()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4256 + 96));
}


// ========================================================================
// __unwind$524900
// EA  : 0x82DA6708
// RVA : 0x00DA6708
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_524900()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 4256;
  if ( (*(_DWORD *)(v0 - 4256 + 84) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 84) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 4276));
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_isGameInstalled@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6750
// RVA : 0x00DA6750
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_isGameInstalled *__fastcall idMainMenu::idSWFScriptFunction_isGameInstalled::Call(
        idMainMenu::idSWFScriptFunction_isGameInstalled *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idFile *v5; // r3
  idPlayerProfile *v6; // r3
  _DWORD *v7; // r3
  _DWORD *v8; // r6

  if ( resourceManager != nullptr && resourceManager->GetCacheFile(this: resourceManager) != nullptr )
  {
    v5 = resourceManager->GetCacheFile(this: resourceManager);
    if ( v5->GetDevice(this: v5) == FS_DEVICE_OPTICAL_DISK_DRIVE )
    {
      v6 = common->GetProfileFromMasterLocalUser(this: common);
      if ( v6 != nullptr && HIBYTE(v6[1].achievementBits2) == 0 )
      {
        HIBYTE(v6[1].achievementBits2) = 1;
        v7 = idMem::AllocWithLocation(
               this: &mem,
               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
               size: 0xCu,
               tag: TAG_SWF,
               zeroBuffer: false,
               align: ALIGN_16,
               heap: HEAP_DEFAULTHEAP);
        if ( v7 != nullptr )
        {
          v7[1] = 0;
          v8 = v7;
          v7[2] = 107;
          *v7 = &`idMainMenu::idSWFScriptFunction_isGameInstalled::Call'::`8'::idSWFScriptFunction_Accept::`vftable';
        }
        else
        {
          v8 = nullptr;
        }
        ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD, _DWORD, _DWORD, _DWORD))common->AddDialog)(
          a1: common,
          a2: 107,
          a3: 12,
          a4: v8,
          a5: 0,
          a6: 0,
          a7: 0,
          a8: 0);
      }
    }
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_isGameInstalled_vtbl *)4;
  return this;
}


// ========================================================================
// `idMainMenu::idSWFScriptFunction_isGameInstalled::Call'::`8'::idSWFScriptFunction_Accept::Call
// EA  : 0x82DA6890
// RVA : 0x00DA6890
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::idSWFScriptFunction_isGameInstalled::Call_::_8_::idSWFScriptFunction_Accept::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idPlayerProfile *v4; // r3

  common->ClearDialog(this: common, a2: (gameDialogMessages_t)thisObject->variables.num, a3: nullptr, a4: 0);
  v4 = common->GetProfileFromMasterLocalUser(this: common);
  if ( v4 != nullptr )
    idPlayerProfile::SaveSettings(this: v4);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?Call@idSWFScriptFunction_ps3ShowNotifications@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6910
// RVA : 0x00DA6910
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_ps3ShowNotifications *__fastcall idMainMenu::idSWFScriptFunction_ps3ShowNotifications::Call(
        idMainMenu::idSWFScriptFunction_ps3ShowNotifications *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptVar::swfScriptVarValue_t v4; // r11

  LODWORD(v4.f) = result->value;
  this->__vftable = (idMainMenu::idSWFScriptFunction_ps3ShowNotifications_vtbl *)4;
  *(_BYTE *)(v4.i + 839) = 1;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_showDLCMenu@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6928
// RVA : 0x00DA6928
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_showDLCMenu *__fastcall idMainMenu::idSWFScriptFunction_showDLCMenu::Call(
        idMainMenu::idSWFScriptFunction_showDLCMenu *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  *(_BYTE *)(result->value.i + 838) = 1;
  ((void (__fastcall *)(idSession *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))session->ShowSystemMarketplaceUI)(
    a1: session,
    a2: result,
    a3: thisObject,
    a4: parms);
  this->__vftable = (idMainMenu::idSWFScriptFunction_showDLCMenu_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_stopPlaytestRenderDemoRecord@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6980
// RVA : 0x00DA6980
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_stopPlaytestRenderDemoRecord *__fastcall idMainMenu::idSWFScriptFunction_stopPlaytestRenderDemoRecord::Call(
        idMainMenu::idSWFScriptFunction_stopPlaytestRenderDemoRecord *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  if ( playtest_MenuStartsRenderDemo.valueInteger != 0 && playtest_log_Any.valueInteger != 0 )
    cmdSystem->AppendCommandText(this: cmdSystem, a2: "demostop\n");
  this->__vftable = (idMainMenu::idSWFScriptFunction_stopPlaytestRenderDemoRecord_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setPlaytestSessionName@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6A08
// RVA : 0x00DA6A08
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setPlaytestSessionName *__fastcall idMainMenu::idSWFScriptFunction_setPlaytestSessionName::Call(
        idMainMenu::idSWFScriptFunction_setPlaytestSessionName *this,
        idStr *result,
        __int64 parms,
        __int64 a4,
        __int64 a5)
{
  int v6; // r11
  char v7; // r11
  bool v8; // zf
  idSWFScriptVar *v9; // r3
  idStr v11; // [sp+60h] [-40h] BYREF

  LODWORD(a5) = 0;
  if ( *(int *)(parms + 4) <= 0 )
    goto _M525130;
  result = *(idStr **)parms;
  v6 = **(_DWORD **)parms;
  if ( v6 == 3 )
    goto _M525130;
  if ( v6 == 1 || (v8 = v6 != 0, v7 = 0, !v8) )
    v7 = 1;
  if ( v7 == 0 )
  {
_M525130:
    idLib::Warning(fmt: "Invalid argument to idSWFScriptFunction_setPlaytestSessionName", result, HIDWORD(parms));
  }
  else
  {
    v9 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v11, result, a3: parms, a4, a5);
    idCVar::SetString(this: &playtest_sessionType, newValue: (const char *)v9->value.i, force: true);
    idStr::FreeData(this: &v11);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_setPlaytestSessionName_vtbl *)4;
  return this;
}


// ========================================================================
// __unwind$525087
// EA  : 0x82DA6AD0
// RVA : 0x00DA6AD0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_525087()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_checkActivatePlaytestLogging@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6AF8
// RVA : 0x00DA6AF8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_checkActivatePlaytestLogging *__fastcall idMainMenu::idSWFScriptFunction_checkActivatePlaytestLogging::Call(
        idMainMenu::idSWFScriptFunction_checkActivatePlaytestLogging *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  if ( playtest_MenuStartsLogging.valueInteger != 0 )
  {
    idCVar::SetBool(this: &playtest_log_Any, newValue: true, force: true);
    idCVar::SetBool(this: &playtest_log_weaponFire, newValue: true, force: true);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_checkActivatePlaytestLogging_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_checkActivateRenderDemo@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6B68
// RVA : 0x00DA6B68
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_checkActivateRenderDemo *__fastcall idMainMenu::idSWFScriptFunction_checkActivateRenderDemo::Call(
        idMainMenu::idSWFScriptFunction_checkActivateRenderDemo *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  if ( playtest_MenuStartsRenderDemo.valueInteger != 0 && playtest_log_Any.valueInteger != 0 )
  {
    cmdSystem->AppendCommandText(this: cmdSystem, a2: "wait 1\n");
    cmdSystem->AppendCommandText(this: cmdSystem, a2: "demorecord_playtest\n");
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_checkActivateRenderDemo_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_confirmExitGame@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6C08
// RVA : 0x00DA6C08
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_confirmExitGame *__fastcall idMainMenu::idSWFScriptFunction_confirmExitGame::Call(
        idMainMenu::idSWFScriptFunction_confirmExitGame *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r3

  if ( parms->num == 1 )
  {
    v5 = idSWFScriptVar::ToInteger(this: parms->list);
    idMainMenu::ExitGameConfirm(this: gameLocal->mainMenu, pauseOption: v5);
  }
  else
  {
    idLib::Warning(fmt: "Confirm dialog requrested but parameters did not meet requirements", result, thisObject);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_confirmExitGame_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_returnToMainMenu@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6C88
// RVA : 0x00DA6C88
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_returnToMainMenu *__fastcall idMainMenu::idSWFScriptFunction_returnToMainMenu::Call(
        idMainMenu::idSWFScriptFunction_returnToMainMenu *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  if ( com_multiplayer.valueInteger != 0 )
    ((void (__fastcall *)(idSession *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))session->QuitMatch)(
      a1: session,
      a2: result,
      a3: thisObject,
      a4: parms);
  else
    cmdSystem->AppendCommandText(this: cmdSystem, a2: "disconnect\n");
  this->__vftable = (idMainMenu::idSWFScriptFunction_returnToMainMenu_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setMenuArea@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6D10
// RVA : 0x00DA6D10
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setMenuArea *__fastcall idMainMenu::idSWFScriptFunction_setMenuArea::Call(
        idMainMenu::idSWFScriptFunction_setMenuArea *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  menuArea_t v6; // r3

  if ( parms->num == 1 )
  {
    v6 = idSWFScriptVar::ToInteger(this: parms->list);
    idMainMenu::ForceMenuArea(this: (idMainMenu *)result->value.i, newMenuArea: v6);
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for setMenuArea", result, thisObject);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_setMenuArea_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_forceMenuArea@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6D88
// RVA : 0x00DA6D88
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_forceMenuArea *__fastcall idMainMenu::idSWFScriptFunction_forceMenuArea::Call(
        idMainMenu::idSWFScriptFunction_forceMenuArea *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  menuArea_t v6; // r3

  if ( parms->num == 1 )
  {
    v6 = idSWFScriptVar::ToInteger(this: parms->list);
    idMainMenu::ForceMenuArea(this: (idMainMenu *)result->value.i, newMenuArea: v6);
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for forceMenuArea", result, thisObject);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_forceMenuArea_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setScrollSpeed@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6E00
// RVA : 0x00DA6E00
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setScrollSpeed *__fastcall idMainMenu::idSWFScriptFunction_setScrollSpeed::Call(
        idMainMenu::idSWFScriptFunction_setScrollSpeed *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v6; // r4

  v6 = 0;
  if ( gameLocal->mainMenu != nullptr )
  {
    if ( parms->num > 0 )
      v6 = idSWFScriptVar::ToInteger(this: parms->list);
    idMainMenu::SetScrollSpeed(this: (idMainMenu *)result->value.i, index: v6);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_setScrollSpeed_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_restartFromPause@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6E80
// RVA : 0x00DA6E80
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_restartFromPause *__fastcall idMainMenu::idSWFScriptFunction_restartFromPause::Call(
        idMainMenu::idSWFScriptFunction_restartFromPause *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  cmdSystem->AppendCommandText(this: cmdSystem, a2: "restartmap\n");
  this->__vftable = (idMainMenu::idSWFScriptFunction_restartFromPause_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_updateSafeFrameScale@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6ED8
// RVA : 0x00DA6ED8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_updateSafeFrameScale *__fastcall idMainMenu::idSWFScriptFunction_updateSafeFrameScale::Call(
        idMainMenu::idSWFScriptFunction_updateSafeFrameScale *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms,
        int a5,
        int a6,
        __int64 a7)
{
  double v8; // fp1
  bool v9; // r4

  if ( parms->num == 1 )
  {
    v8 = idSWFScriptVar::ToFloat(this: parms->list, a2: (int)result, a3: (int)thisObject, a4: (int)parms, a5, a6, a7);
    idCVar::SetFloat(
      this: &swf_safeFrame,
      newValue: (float)((float)((float)v8 * (float)0.0099999998) * (float)0.075000003),
      force: v9);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_updateSafeFrameScale_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_updateGammaValue@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6F48
// RVA : 0x00DA6F48
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_updateGammaValue *__fastcall idMainMenu::idSWFScriptFunction_updateGammaValue::Call(
        idMainMenu::idSWFScriptFunction_updateGammaValue *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms,
        int a5,
        int a6,
        __int64 a7)
{
  double v8; // fp31
  idPlayerProfileGame *v9; // r3

  if ( parms->num == 1 )
  {
    v8 = (float)(idSWFScriptVar::ToFloat(
                   this: parms->list,
                   a2: (int)result,
                   a3: (int)thisObject,
                   a4: (int)parms,
                   a5,
                   a6,
                   a7)
               * (float)0.0099999998);
    v9 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
    idPlayerProfileGame::SetGammaValue(this: v9, percent: v8);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_updateGammaValue_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setAudioVolume@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA6FC8
// RVA : 0x00DA6FC8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setAudioVolume *__fastcall idMainMenu::idSWFScriptFunction_setAudioVolume::Call(
        idMainMenu::idSWFScriptFunction_setAudioVolume *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idPlayerProfileGame *v6; // r30
  int v7; // r3
  idSWFScriptVar *list; // r11
  int v9; // r31
  __int64 v10; // r10
  int v11; // r8
  int v12; // r7
  int v13; // r6
  int v14; // r5
  int v15; // r4
  double v16; // fp1

  if ( parms->num == 2 )
  {
    v6 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
    if ( v6 != nullptr )
    {
      v7 = idSWFScriptVar::ToInteger(this: parms->list);
      list = parms->list;
      v9 = v7;
      v16 = (float)(idSWFScriptVar::ToFloat(this: list + 1, a2: v15, a3: v14, a4: v13, a5: v12, a6: v11, a7: v10)
                  * (float)0.0099999998);
      switch ( v9 )
      {
        case 0:
          idPlayerProfileGame::SetMasterVolume(this: v6, val: v16);
          this->__vftable = (idMainMenu::idSWFScriptFunction_setAudioVolume_vtbl *)4;
          return this;
        case 1:
          idPlayerProfileGame::SetMusicVolume(this: v6, val: v16);
          this->__vftable = (idMainMenu::idSWFScriptFunction_setAudioVolume_vtbl *)4;
          return this;
        case 2:
          idPlayerProfileGame::SetVoiceVolume(this: v6, val: v16);
          this->__vftable = (idMainMenu::idSWFScriptFunction_setAudioVolume_vtbl *)4;
          return this;
        case 3:
          idPlayerProfileGame::SetAmbientVolume(this: v6, val: v16);
          break;
        default:
          break;
      }
    }
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_setAudioVolume_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_invertLook@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA70C0
// RVA : 0x00DA70C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setInvertLook *__fastcall idMainMenu::idSWFScriptFunction_invertLook::Call(
        idMainMenu::idSWFScriptFunction_setInvertLook *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r31
  int v6; // r3
  idPlayerProfile *PlayerProfileByInputDevice; // r3

  if ( parms->num == 1 )
  {
    v5 = idSWFScriptVar::ToBool(this: parms->list);
    v6 = common->GetFocusDeviceNum(this: common);
    PlayerProfileByInputDevice = idSignInManagerBase::GetPlayerProfileByInputDevice(
                                   this: session->signInManager,
                                   index: v6);
    if ( PlayerProfileByInputDevice != nullptr )
      PlayerProfileByInputDevice->SetInvertLook(this: PlayerProfileByInputDevice, a2: v5);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setInvertLook_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for setInvertLook", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setInvertLook_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setSubtitlesEnabled@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA7178
// RVA : 0x00DA7178
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setSubtitlesEnabled *__fastcall idMainMenu::idSWFScriptFunction_setSubtitlesEnabled::Call(
        idMainMenu::idSWFScriptFunction_setSubtitlesEnabled *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v6; // r3

  if ( parms->num == 1 )
  {
    v6 = ((int (__fastcall *)(idCommon *, idSWFScriptVar *, idSWFScriptObject *))common->GetProfileFromMasterLocalUser)(
           a1: common,
           a2: result,
           a3: thisObject);
    *(_BYTE *)(v6 + 2064) = idSWFScriptVar::ToBool(this: parms->list);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_setSubtitlesEnabled_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_updateJoyPitchSpeed@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA71F0
// RVA : 0x00DA71F0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_updateJoyPitchSpeed *__fastcall idMainMenu::idSWFScriptFunction_updateJoyPitchSpeed::Call(
        idMainMenu::idSWFScriptFunction_updateJoyPitchSpeed *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms,
        int a5,
        int a6,
        __int64 a7)
{
  double v8; // fp31
  int v9; // r3
  idPlayerProfile *PlayerProfileByInputDevice; // r3

  if ( parms->num == 1 )
  {
    v8 = (float)((float)((float)(idSWFScriptVar::ToFloat(
                                   this: parms->list,
                                   a2: (int)result,
                                   a3: (int)thisObject,
                                   a4: (int)parms,
                                   a5,
                                   a6,
                                   a7)
                               * (float)0.0099999998)
                       * (float)180.0)
               + (float)30.0);
    v9 = common->GetFocusDeviceNum(this: common);
    PlayerProfileByInputDevice = idSignInManagerBase::GetPlayerProfileByInputDevice(
                                   this: session->signInManager,
                                   index: v9);
    if ( PlayerProfileByInputDevice != nullptr )
      *(float *)&PlayerProfileByInputDevice[1].state = v8;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_updateJoyPitchSpeed_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_updateJoyYawSpeed@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA7298
// RVA : 0x00DA7298
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_updateJoyYawSpeed *__fastcall idMainMenu::idSWFScriptFunction_updateJoyYawSpeed::Call(
        idMainMenu::idSWFScriptFunction_updateJoyYawSpeed *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms,
        int a5,
        int a6,
        __int64 a7)
{
  double v8; // fp31
  int v9; // r3
  idPlayerProfile *PlayerProfileByInputDevice; // r3

  if ( parms->num == 1 )
  {
    v8 = (float)((float)((float)(idSWFScriptVar::ToFloat(
                                   this: parms->list,
                                   a2: (int)result,
                                   a3: (int)thisObject,
                                   a4: (int)parms,
                                   a5,
                                   a6,
                                   a7)
                               * (float)0.0099999998)
                       * (float)400.0)
               + (float)40.0);
    v9 = common->GetFocusDeviceNum(this: common);
    PlayerProfileByInputDevice = idSignInManagerBase::GetPlayerProfileByInputDevice(
                                   this: session->signInManager,
                                   index: v9);
    if ( PlayerProfileByInputDevice != nullptr )
      *((float *)&PlayerProfileByInputDevice[1].__vftable + 1) = v8;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_updateJoyYawSpeed_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setConfig@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA7340
// RVA : 0x00DA7340
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setConfig *__fastcall idMainMenu::idSWFScriptFunction_setConfig::Call(
        idMainMenu::idSWFScriptFunction_setConfig *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v6; // r3
  idPlayerProfileGame *PlayerProfileByInputDevice; // r30
  int v9; // r28
  char v10; // r3
  idSWFScriptVar *list; // r11
  bool v12; // r31
  char v13; // r3

  v6 = common->GetFocusDeviceNum(this: common);
  PlayerProfileByInputDevice = (idPlayerProfileGame *)idSignInManagerBase::GetPlayerProfileByInputDevice(
                                                        this: session->signInManager,
                                                        index: v6);
  if ( PlayerProfileByInputDevice != nullptr )
  {
    if ( parms->num != 3 )
    {
      idLib::Warning(fmt: "setConfig function in MainMenuLocal needs an argument");
      this->__vftable = (idMainMenu::idSWFScriptFunction_setConfig_vtbl *)4;
      return this;
    }
    v9 = idSWFScriptVar::ToInteger(this: parms->list);
    v10 = idSWFScriptVar::ToBool(this: parms->list + 1);
    list = parms->list;
    v12 = v10;
    v13 = idSWFScriptVar::ToBool(this: list + 2);
    idPlayerProfileGame::SetConfig(this: PlayerProfileByInputDevice, config: v9, fps: v12, save: v13);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_setConfig_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_changeConfig@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA7408
// RVA : 0x00DA7408
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_changeConfig *__fastcall idMainMenu::idSWFScriptFunction_changeConfig::Call(
        idMainMenu::idSWFScriptFunction_changeConfig *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v6; // r3
  idPlayerProfileGame *PlayerProfileByInputDevice; // r30
  int v8; // r3
  int v10; // r3
  idSWFScriptVar *list; // r11
  int v12; // r31
  char v13; // r3

  v6 = common->GetFocusDeviceNum(this: common);
  PlayerProfileByInputDevice = (idPlayerProfileGame *)idSignInManagerBase::GetPlayerProfileByInputDevice(
                                                        this: session->signInManager,
                                                        index: v6);
  v8 = common->GetFocusDeviceNum(this: common);
  idKeyInput::SetUserDeviceNumForBind(inputDeviceNum: v8);
  if ( PlayerProfileByInputDevice != nullptr )
  {
    if ( parms->num != 2 )
    {
      idLib::Warning(fmt: "changeConfig function in MainMenuLocal needs an argument");
      this->__vftable = (idMainMenu::idSWFScriptFunction_changeConfig_vtbl *)4;
      return this;
    }
    v10 = idSWFScriptVar::ToInteger(this: parms->list);
    list = parms->list;
    v12 = v10;
    v13 = idSWFScriptVar::ToBool(this: list + 1);
    idPlayerProfileGame::ExecConfig(this: PlayerProfileByInputDevice, config: v12, fps: v13, save: false);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_changeConfig_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_confirmRestoreBindings@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA74E0
// RVA : 0x00DA74E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_confirmRestoreBindings *__fastcall idMainMenu::idSWFScriptFunction_confirmRestoreBindings::Call(
        idMainMenu::idSWFScriptFunction_confirmRestoreBindings *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu::ConfirmBindingReset(this: (idMainMenu *)result->value.i);
  this->__vftable = (idMainMenu::idSWFScriptFunction_confirmRestoreBindings_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setUseAimAssist@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA7520
// RVA : 0x00DA7520
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setUseAimAssist *__fastcall idMainMenu::idSWFScriptFunction_setUseAimAssist::Call(
        idMainMenu::idSWFScriptFunction_setUseAimAssist *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v5; // r31
  int v6; // r3
  idPlayerProfile *PlayerProfileByInputDevice; // r3

  if ( parms->num == 1 )
  {
    v5 = idSWFScriptVar::ToBool(this: parms->list);
    v6 = common->GetFocusDeviceNum(this: common);
    PlayerProfileByInputDevice = idSignInManagerBase::GetPlayerProfileByInputDevice(
                                   this: session->signInManager,
                                   index: v6);
    if ( PlayerProfileByInputDevice != nullptr )
      BYTE1(PlayerProfileByInputDevice[1].__vftable) = v5;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_setUseAimAssist_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setGamepadEnabled@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA75B0
// RVA : 0x00DA75B0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setGamepadEnabled *__fastcall idMainMenu::idSWFScriptFunction_setGamepadEnabled::Call(
        idMainMenu::idSWFScriptFunction_setGamepadEnabled *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v5; // r31
  idPlayerProfile *v6; // r3
  int v7; // r4

  if ( parms->num == 1 )
  {
    v5 = idSWFScriptVar::ToBool(this: parms->list);
    v6 = common->GetProfileFromMasterLocalUser(this: common);
    if ( v6 != nullptr )
    {
      BYTE2(v6[1].__vftable) = v5;
      v7 = 0;
      if ( v5 == 0 )
        v7 = -1;
      idCVar::SetInteger(this: &swf_platformOverride, newValue: v7, force: true);
    }
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_setGamepadEnabled_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setUseVibrate@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA7650
// RVA : 0x00DA7650
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setUseVibrate *__fastcall idMainMenu::idSWFScriptFunction_setUseVibrate::Call(
        idMainMenu::idSWFScriptFunction_setUseVibrate *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v5; // r31
  int v6; // r3
  idPlayerProfile *PlayerProfileByInputDevice; // r3

  if ( parms->num == 1 )
  {
    v5 = idSWFScriptVar::ToBool(this: parms->list);
    v6 = common->GetFocusDeviceNum(this: common);
    PlayerProfileByInputDevice = idSignInManagerBase::GetPlayerProfileByInputDevice(
                                   this: session->signInManager,
                                   index: v6);
    if ( PlayerProfileByInputDevice != nullptr )
      LOBYTE(PlayerProfileByInputDevice[1].__vftable) = v5;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_setUseVibrate_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setMouseSensitivity@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA76E0
// RVA : 0x00DA76E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setMouseSensitivity *__fastcall idMainMenu::idSWFScriptFunction_setMouseSensitivity::Call(
        idMainMenu::idSWFScriptFunction_setMouseSensitivity *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms,
        int a5,
        int a6,
        __int64 a7)
{
  double v8; // fp31
  idPlayerProfileGame *v9; // r3

  if ( parms->num == 1 )
  {
    v8 = (float)((float)((float)(idSWFScriptVar::ToFloat(
                                   this: parms->list,
                                   a2: (int)result,
                                   a3: (int)thisObject,
                                   a4: (int)parms,
                                   a5,
                                   a6,
                                   a7)
                               * (float)0.0099999998)
                       * (float)8.0)
               + (float)2.0);
    v9 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
    if ( v9 != nullptr )
      idPlayerProfileGame::SetMouseSensitivity(this: v9, val: v8);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_setMouseSensitivity_vtbl *)4;
  return this;
}


// ========================================================================
// `idMainMenu::CalculateBenchmark'::`5'::idSWFScriptFunction_BenchmarkComplete::Call
// EA  : 0x82DA7778
// RVA : 0x00DA7778
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::CalculateBenchmark_::_5_::idSWFScriptFunction_BenchmarkComplete::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v4; // r3

  v4 = ((int (__fastcall *)(idCommon *, idSWFScriptObject *, const idSWFParmList *))common->Game)(
         a1: common,
         a2: thisObject,
         a3: parms);
  (*(void (__fastcall **)(int))(*(_DWORD *)v4 + 272))(a1: v4);
  common->ClearDialog(this: common, a2: GDM_DISPLAY_BENCHMARK, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?Call@idSWFScriptFunction_calculateBenchmark@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA7800
// RVA : 0x00DA7800
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_calculateBenchmark *__fastcall idMainMenu::idSWFScriptFunction_calculateBenchmark::Call(
        idMainMenu::idSWFScriptFunction_calculateBenchmark *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu::CalculateBenchmark(this: (idMainMenu *)result->value.i);
  this->__vftable = (idMainMenu::idSWFScriptFunction_calculateBenchmark_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_GetSaveGame@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA7840
// RVA : 0x00DA7840
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_GetSaveGame *__fastcall idMainMenu::idSWFScriptFunction_GetSaveGame::Call(
        idMainMenu::idSWFScriptFunction_GetSaveGame *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  const idStaticList<idSaveGameDetails,16> *v7; // r3
  int v8; // r5

  if ( session->signInManager->GetNumLocalUsers(this: session->signInManager) > 0
    && *(_DWORD *)(result->value.i + 680) != session->GetEnumerationHandle(this: session) )
  {
    *(_DWORD *)(result->value.i + 680) = session->GetEnumerationHandle(this: session);
    if ( session->IsEnumerating(this: session) )
    {
      hasAutosave = false;
      hasSaveGames = false;
      Sys_SaveGameCheck(exists: &hasSaveGames, autosaveExists: &hasAutosave);
      this->__vftable = (idMainMenu::idSWFScriptFunction_GetSaveGame_vtbl *)4;
      return this;
    }
    v7 = session->GetEnumeratedSavegames(this: session);
    v8 = -v7->num & ~v7->num;
    hasAutosave = false;
    hasSaveGames = v8 < 0;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_GetSaveGame_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_deleteGame@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA7960
// RVA : 0x00DA7960
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_deleteGame *__fastcall idMainMenu::idSWFScriptFunction_deleteGame::Call(
        idMainMenu::idSWFScriptFunction_deleteGame *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v6; // r3
  int v7; // r4

  if ( parms->num == 1 )
  {
    v6 = idSWFScriptVar::ToInteger(this: parms->list);
    v7 = v6;
    if ( *(_BYTE *)(result->value.i + 948) == 0 && hasAutosave )
      v7 = v6 + 1;
    idMainMenu::DeleteSaveGameConfirm(this: (idMainMenu *)result->value.i, saveIndex: v7);
    this->__vftable = (idMainMenu::idSWFScriptFunction_deleteGame_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "requested to delete save game with insufficient parms", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_deleteGame_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_select360Storage@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA7A00
// RVA : 0x00DA7A00
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_select360Storage *__fastcall idMainMenu::idSWFScriptFunction_select360Storage::Call(
        idMainMenu::idSWFScriptFunction_select360Storage *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptVar::swfScriptVarValue_t v4; // r31
  idSignInManagerXbox *signInManager; // r30
  bool v7; // r8
  idLocalUserXbox *MasterLocalUser; // r4

  LODWORD(v4.f) = result->value;
  *(_BYTE *)(v4.i + 802) = 0;
  idStr::operator=(this: (idStr *)(v4.i + 804), text: &byte_8200D768);
  *(_BYTE *)(v4.i + 836) = 0;
  signInManager = (idSignInManagerXbox *)session->signInManager;
  MasterLocalUser = (idLocalUserXbox *)idSignInManagerBase::GetMasterLocalUser(this: signInManager);
  if ( MasterLocalUser != nullptr )
    idSignInManagerXbox::RequestDeviceSelector(
      this: signInManager,
      user: MasterLocalUser,
      minSizeInBytes: 1u,
      forceShow: 1u,
      manageDeviceEnabled: v7);
  *(_BYTE *)(v4.i + 801) = 1;
  this->__vftable = (idMainMenu::idSWFScriptFunction_select360Storage_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_continueGame@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA7A80
// RVA : 0x00DA7A80
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_continueGame *__fastcall idMainMenu::idSWFScriptFunction_continueGame::Call(
        idMainMenu::idSWFScriptFunction_continueGame *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idGameLocal_vtbl *v5; // r31
  const char *v6; // r3

  v5 = gameLocal->__vftable;
  v6 = session->GetCurrentSaveSlot(this: session);
  v5->LoadGame(this: gameLocal, a2: v6);
  this->__vftable = (idMainMenu::idSWFScriptFunction_continueGame_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_continueFromMostRecentSave@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA7AE8
// RVA : 0x00DA7AE8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_continueFromMostRecentSave *__fastcall idMainMenu::idSWFScriptFunction_continueFromMostRecentSave::Call(
        idMainMenu::idSWFScriptFunction_continueFromMostRecentSave *this,
        idSWFScriptVar *result,
        __int64 parms,
        __int64 a4,
        __int64 a5)
{
  idStr **v6; // r29
  __int64 v7; // r6
  __int64 v8; // r10
  __int64 v9; // r8
  va *v10; // r3
  int v12; // [sp+8h] [-1098h]
  int v13; // [sp+Ch] [-1094h]
  int v14; // [sp+10h] [-1090h]
  int v15; // [sp+14h] [-108Ch]
  int v16; // [sp+18h] [-1088h]
  int v17; // [sp+1Ch] [-1084h]
  idStr v18; // [sp+60h] [-1040h] BYREF
  va v19; // [sp+80h] [-1020h] BYREF

  v6 = (idStr **)parms;
  LODWORD(a5) = *(_DWORD *)(parms + 4);
  if ( (_DWORD)a5 != 1 )
    idLib::Warning(fmt: "Unable to load game because no game name was passed as parameter");
  idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v18, result: *v6, a3: parms, a4, a5);
  HIDWORD(v7) = v18.data;
  v10 = va::va(
          this: &v19,
          fmt: "loadGame %s\n",
          a3: v7,
          a4: v9,
          a5: v8,
          a6: v12,
          a7: v13,
          a8: v14,
          a9: v15,
          a10: v16,
          a11: v17);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: v10->buffer);
  idLib::Printf(fmt: "Loading %s...\n", v18.data);
  this->__vftable = (idMainMenu::idSWFScriptFunction_continueFromMostRecentSave_vtbl *)4;
  idStr::FreeData(this: &v18);
  return this;
}


// ========================================================================
// __unwind$525873
// EA  : 0x82DA7B98
// RVA : 0x00DA7B98
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_525873()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4256 + 96));
}


// ========================================================================
// __unwind$525874
// EA  : 0x82DA7BC0
// RVA : 0x00DA7BC0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_525874()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 4256;
  if ( (*(_DWORD *)(v0 - 4256 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 4276));
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_SaveGame@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA7C08
// RVA : 0x00DA7C08
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_SaveGame *__fastcall idMainMenu::idSWFScriptFunction_SaveGame::Call(
        idMainMenu::idSWFScriptFunction_SaveGame *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v6; // r3
  int v7; // r5

  if ( parms->num <= 0 || (v6 = idSWFScriptVar::ToInteger(this: parms->list), v7 = v6, v6 == -1) )
  {
    idMainMenu::GameSave(this: (idMainMenu *)result->value.i, index: -1);
  }
  else
  {
    if ( hasAutosave && *(_BYTE *)(result->value.i + 948) == 0 )
      v7 = v6 + 1;
    idMainMenu::ShowOverwriteSavingDialog(this: (idMainMenu *)result->value.i, show: true, index: v7);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_SaveGame_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_LoadGame@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA7CB0
// RVA : 0x00DA7CB0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_LoadGame *__fastcall idMainMenu::idSWFScriptFunction_LoadGame::Call(
        idMainMenu::idSWFScriptFunction_LoadGame *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v4; // r11
  idSaveGameManager *saveGameManager; // r9
  idSaveGameDetails *SlotName; // r3
  __int64 v8; // r10
  __int64 v9; // r6
  __int64 v10; // r8
  va *v11; // r3
  int v13; // [sp+8h] [-10F8h]
  int v14; // [sp+Ch] [-10F4h]
  int v15; // [sp+10h] [-10F0h]
  int v16; // [sp+14h] [-10ECh]
  int v17; // [sp+18h] [-10E8h]
  int v18; // [sp+1Ch] [-10E4h]
  idStr v19; // [sp+60h] [-10A0h] BYREF
  idSaveGameDetails v20[26]; // [sp+80h] [-1080h] BYREF

  v4 = 0;
  if ( parms->num > 0 )
    v4 = idSWFScriptVar::ToInteger(this: parms->list);
  saveGameManager = session->saveGameManager;
  if ( v4 < saveGameManager->enumeratedSaveGames.num )
  {
    SlotName = idSaveGameDetails::GetSlotName(
                 this: v20,
                 result: (idStrStatic<64> *)&saveGameManager->enumeratedSaveGames.list[v4]);
    idStr::idStr(this: &v19, text: (const idStr *)SlotName);
    idStr::FreeData(this: (idStr *)v20);
    LODWORD(v8) = "ame: %s\n";
    HIDWORD(v9) = v19.data;
    v11 = va::va(
            this: (va *)v20[0].slotName.buffer,
            fmt: "loadGame %s\n",
            a3: v9,
            a4: v10,
            a5: v8,
            a6: v13,
            a7: v14,
            a8: v15,
            a9: v16,
            a10: v17,
            a11: v18);
    cmdSystem->AppendCommandText(this: cmdSystem, a2: v11->buffer);
    idLib::Printf(fmt: "Loading %s...\n", v19.data);
    idStr::FreeData(this: &v19);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_LoadGame_vtbl *)4;
  return this;
}


// ========================================================================
// __unwind$525961_0
// EA  : 0x82DA7DA4
// RVA : 0x00DA7DA4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_525961_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4352 + 128));
}


// ========================================================================
// __unwind$525962
// EA  : 0x82DA7DCC
// RVA : 0x00DA7DCC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_525962()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4352 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_loadMap@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA7E00
// RVA : 0x00DA7E00
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_loadMap *__fastcall idMainMenu::idSWFScriptFunction_loadMap::Call(
        idMainMenu::idSWFScriptFunction_loadMap *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  __int64 v6; // r10
  __int64 v7; // r6
  __int64 v8; // r8
  idStr *v9; // r4
  char v10; // r11
  idSWFScriptVar *v11; // r3
  __int64 v12; // r6
  __int64 v13; // r10
  __int64 v14; // r8
  va *v15; // r3
  int v17; // [sp+8h] [-10C8h]
  int v18; // [sp+Ch] [-10C4h]
  int v19; // [sp+10h] [-10C0h]
  int v20; // [sp+14h] [-10BCh]
  int v21; // [sp+18h] [-10B8h]
  int v22; // [sp+1Ch] [-10B4h]
  idStr v23; // [sp+60h] [-1070h] BYREF
  idStr v24; // [sp+80h] [-1050h] BYREF
  va v25; // [sp+A0h] [-1030h] BYREF

  idCVar::SetString(this: &si_spawnspot, newValue: &byte_8200D768, force: true);
  idCVar::SetString(this: &si_nextlayeractive, newValue: &byte_8200D768, force: true);
  idCVar::SetString(this: &si_nextlayerdeactive, newValue: &byte_8200D768, force: true);
  HIDWORD(v8) = parms->num;
  if ( SHIDWORD(v8) > 1 )
  {
    v9 = (idStr *)&parms->list[1];
    if ( v9->len != 3 )
    {
      if ( v9->len == 1 || (v10 = 0, v9->len == 0) )
        v10 = 1;
      if ( v10 != 0 )
      {
        v11 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v23, result: v9, a3: v7, a4: v8, a5: v6);
        idCVar::SetString(this: &si_nextlayeractive, newValue: (const char *)v11->value.i, force: true);
        idStr::FreeData(this: &v23);
      }
    }
  }
  HIDWORD(v12) = idSWFScriptVar::ToString(
                   this: (idSWFScriptVar *)&v24,
                   result: (idStr *)parms->list,
                   a3: v7,
                   a4: v8,
                   a5: v6)->value.i;
  v15 = va::va(
          this: &v25,
          fmt: "devcmap %s\n",
          a3: v12,
          a4: v14,
          a5: v13,
          a6: v17,
          a7: v18,
          a8: v19,
          a9: v20,
          a10: v21,
          a11: v22);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: v15->buffer);
  idStr::FreeData(this: &v24);
  this->__vftable = (idMainMenu::idSWFScriptFunction_loadMap_vtbl *)4;
  return this;
}


// ========================================================================
// __unwind$526040
// EA  : 0x82DA7F34
// RVA : 0x00DA7F34
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526040()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4304 + 96));
}


// ========================================================================
// __unwind$526041
// EA  : 0x82DA7F5C
// RVA : 0x00DA7F5C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526041()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4304 + 128));
}


// ========================================================================
// ?Call@idSWFScriptFunction_restartMap@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA7F88
// RVA : 0x00DA7F88
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_restartMap *__fastcall idMainMenu::idSWFScriptFunction_restartMap::Call(
        idMainMenu::idSWFScriptFunction_restartMap *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idFile *v5; // r3
  idFile_Memory *v6; // r3
  idFile_Memory *v7; // r31

  if ( !common->TimeTrialPlaying(this: common) )
    goto _LN15_2;
  v5 = common->DetachActiveReadSnapshotFile(this: common);
  v6 = (idFile_Memory *)_RTDynamicCast(
                          inptr: v5,
                          VfDelta: 0,
                          SrcType: &idFile `RTTI Type Descriptor',
                          TargetType: &idFile_Memory `RTTI Type Descriptor',
                          isReference: 0);
  v7 = v6;
  if ( v6 == nullptr )
  {
    idLib::Error(fmt: "Error trying to restart a timetrial.");
_LN15_2:
    cmdSystem->AppendCommandText(this: cmdSystem, a2: "restartmap\n");
    goto LABEL_6;
  }
  v6->Seek(this: v6, a2: 0, a3: FS_SEEK_SET);
  common->QueueSnapshotMemFile(this: common, a2: v7, a3: 1414812236u);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: "ttplayqueued");
LABEL_6:
  this->__vftable = (idMainMenu::idSWFScriptFunction_restartMap_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_saveSettings@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DA8090
// RVA : 0x00DA8090
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_saveSettings *__fastcall idMainMenu::idSWFScriptFunction_saveSettings::Call(
        idMainMenu::idSWFScriptFunction_saveSettings *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r3
  idPlayerProfile *PlayerProfileByInputDevice; // r3

  if ( (unsigned __int8)idMainMenu::ShowDisplaySettingFailedMessage(this: (idMainMenu *)result->value.i) == 0 )
  {
    v5 = common->GetFocusDeviceNum(this: common);
    PlayerProfileByInputDevice = idSignInManagerBase::GetPlayerProfileByInputDevice(
                                   this: session->signInManager,
                                   index: v5);
    if ( PlayerProfileByInputDevice != nullptr )
      idPlayerProfile::SaveSettings(this: PlayerProfileByInputDevice);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_saveSettings_vtbl *)4;
  return this;
}


// ========================================================================
// ?UpdateCmds_Start@idMainMenu@@QAAXXZ
// EA  : 0x82DA8118
// RVA : 0x00DA8118
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateCmds_Start(idMainMenu *this)
{
  idSWFScriptObject *NestedObj; // r29
  idSWFScriptFunction *v3; // r3
  idSWF *mainMenu; // r11
  idSWFScriptFunction *v5; // r4
  idSWFScriptVar v6[6]; // [sp+50h] [-30h] BYREF

  NestedObj = idSWFScriptObject::GetNestedObj(
                this: this->mainMenu->mainspriteInstance->scriptObject,
                arg1: "startMenu",
                arg2: "btnStart",
                arg3: nullptr,
                arg4: nullptr,
                arg5: nullptr,
                arg6: nullptr);
  if ( NestedObj != nullptr )
  {
    v3 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x10u,
                                  tag: TAG_SWF,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      mainMenu = this->mainMenu;
      v3[3].__vftable = (idSWFScriptFunction_vtbl *)this;
      v3[1].__vftable = nullptr;
      v5 = v3;
      v3->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateCmds_Start'::`5'::idSWFScriptFunction_startPress::`vftable';
      v3[2].__vftable = (idSWFScriptFunction_vtbl *)mainMenu;
    }
    else
    {
      v5 = nullptr;
    }
    idSWFScriptVar::idSWFScriptVar(this: v6, nf: v5);
    idSWFScriptObject::Set(this: NestedObj, name: "onPress", value: v6);
    idSWFScriptVar::Free(this: v6);
  }
}


// ========================================================================
// __unwind$526164
// EA  : 0x82DA81F0
// RVA : 0x00DA81F0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526164()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 128 + 80));
}


// ========================================================================
// ?UpdateScrollCmds@idMainMenu@@QAAXPAVidSWFScriptObject@@0@Z
// EA  : 0x82DA8220
// RVA : 0x00DA8220
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateScrollCmds(idMainMenu *this, idSWFScriptObject *btnUp, idSWFScriptObject *btnDown)
{
  idSWFScriptFunction *v6; // r3
  idSWF *mainMenu; // r11
  idSWFScriptFunction *v8; // r4
  idSWFScriptFunction *v9; // r3
  idSWF *v10; // r11
  idSWFScriptFunction *v11; // r4
  idSWFScriptFunction *v12; // r3
  idSWF *v13; // r11
  idSWFScriptFunction *v14; // r4
  idSWFScriptFunction *v15; // r3
  idSWF *v16; // r11
  idSWFScriptFunction *v17; // r4
  idSWFScriptVar v18; // [sp+50h] [-A0h] BYREF
  idSWFScriptVar v19; // [sp+58h] [-98h] BYREF
  idSWFScriptVar v20; // [sp+60h] [-90h] BYREF
  idSWFScriptVar v21; // [sp+68h] [-88h] BYREF
  idSWFScriptVar v22; // [sp+70h] [-80h] BYREF
  idSWFScriptVar v23; // [sp+78h] [-78h] BYREF
  idSWFScriptVar v24; // [sp+80h] [-70h] BYREF
  idSWFScriptVar v25; // [sp+88h] [-68h] BYREF
  idSWFScriptVar v26[12]; // [sp+90h] [-60h] BYREF

  if ( btnUp != nullptr && btnDown != nullptr )
  {
    v6 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x14u,
                                  tag: TAG_SWF,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
    if ( v6 != nullptr )
    {
      mainMenu = this->mainMenu;
      v8 = v6;
      v6[3].__vftable = (idSWFScriptFunction_vtbl *)this;
      v6[1].__vftable = nullptr;
      v6->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateScrollCmds'::`2'::idSWFScriptFunction_scroll::`vftable';
      HIBYTE(v6[4].__vftable) = 1;
      v6[2].__vftable = (idSWFScriptFunction_vtbl *)mainMenu;
    }
    else
    {
      v8 = nullptr;
    }
    idSWFScriptVar::idSWFScriptVar(this: &v19, nf: v8);
    idSWFScriptObject::Set(this: btnUp, name: "onPress", value: &v19);
    idSWFScriptVar::Free(this: &v19);
    v9 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x14u,
                                  tag: TAG_SWF,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
    if ( v9 != nullptr )
    {
      v10 = this->mainMenu;
      v11 = v9;
      v9[3].__vftable = (idSWFScriptFunction_vtbl *)this;
      v9[1].__vftable = nullptr;
      v9->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateScrollCmds'::`2'::idSWFScriptFunction_scroll::`vftable';
      HIBYTE(v9[4].__vftable) = 0;
      v9[2].__vftable = (idSWFScriptFunction_vtbl *)v10;
    }
    else
    {
      v11 = nullptr;
    }
    idSWFScriptVar::idSWFScriptVar(this: &v20, nf: v11);
    idSWFScriptObject::Set(this: btnDown, name: "onPress", value: &v20);
    idSWFScriptVar::Free(this: &v20);
    idSWF::GetGlobal(this: (idSWF *)&v18, result: (idSWFScriptVar *)this->mainMenu, name: "shortcutKeys");
    if ( v18.type == SWF_VAR_OBJECT )
    {
      idSWFScriptVar::idSWFScriptVar(this: &v21, o: btnUp);
      idSWFScriptObject::Set(this: v18.value.object, name: "STICK1_UP", value: &v21);
      idSWFScriptVar::Free(this: &v21);
      idSWFScriptVar::idSWFScriptVar(this: &v22, o: btnUp);
      idSWFScriptObject::Set(this: v18.value.object, name: "UP", value: &v22);
      idSWFScriptVar::Free(this: &v22);
      v12 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x14u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v12 != nullptr )
      {
        v13 = this->mainMenu;
        v14 = v12;
        v12[3].__vftable = (idSWFScriptFunction_vtbl *)this;
        v12[1].__vftable = nullptr;
        v12->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateScrollCmds'::`3'::idSWFScriptFunction_scrollWheel::`vftable';
        HIBYTE(v12[4].__vftable) = 1;
        v12[2].__vftable = (idSWFScriptFunction_vtbl *)v13;
      }
      else
      {
        v14 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v23, nf: v14);
      idSWFScriptObject::Set(this: v18.value.object, name: "MWHEEL_UP", value: &v23);
      idSWFScriptVar::Free(this: &v23);
      idSWFScriptVar::idSWFScriptVar(this: &v24, o: btnDown);
      idSWFScriptObject::Set(this: v18.value.object, name: "STICK1_DOWN", value: &v24);
      idSWFScriptVar::Free(this: &v24);
      idSWFScriptVar::idSWFScriptVar(this: &v25, o: btnDown);
      idSWFScriptObject::Set(this: v18.value.object, name: "DOWN", value: &v25);
      idSWFScriptVar::Free(this: &v25);
      v15 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x14u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v15 != nullptr )
      {
        v16 = this->mainMenu;
        v17 = v15;
        v15[3].__vftable = (idSWFScriptFunction_vtbl *)this;
        v15[1].__vftable = nullptr;
        v15->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateScrollCmds'::`3'::idSWFScriptFunction_scrollWheel::`vftable';
        HIBYTE(v15[4].__vftable) = 0;
        v15[2].__vftable = (idSWFScriptFunction_vtbl *)v16;
      }
      else
      {
        v17 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: v26, nf: v17);
      idSWFScriptObject::Set(this: v18.value.object, name: "MWHEEL_DOWN", value: v26);
      idSWFScriptVar::Free(this: v26);
    }
    idSWFScriptVar::Free(this: &v18);
  }
}


// ========================================================================
// __unwind$526238
// EA  : 0x82DA8504
// RVA : 0x00DA8504
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526238()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 88));
}


// ========================================================================
// __unwind$526240
// EA  : 0x82DA852C
// RVA : 0x00DA852C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526240()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$526241
// EA  : 0x82DA8554
// RVA : 0x00DA8554
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526241()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$526242
// EA  : 0x82DA857C
// RVA : 0x00DA857C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526242()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 104));
}


// ========================================================================
// __unwind$526243
// EA  : 0x82DA85A4
// RVA : 0x00DA85A4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526243()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$526245
// EA  : 0x82DA85CC
// RVA : 0x00DA85CC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526245()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 120));
}


// ========================================================================
// __unwind$526246
// EA  : 0x82DA85F4
// RVA : 0x00DA85F4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526246()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$526247
// EA  : 0x82DA861C
// RVA : 0x00DA861C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526247()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 136));
}


// ========================================================================
// __unwind$526249
// EA  : 0x82DA8644
// RVA : 0x00DA8644
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526249()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 144));
}


// ========================================================================
// ?UpdateAcceptBackCmds@idMainMenu@@QAAXXZ
// EA  : 0x82DA8678
// RVA : 0x00DA8678
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateAcceptBackCmds(idMainMenu *this)
{
  idSWFScriptObject *scriptObject; // r27
  idSWFScriptObject *NestedObj; // r29
  idSWFScriptFunction *v4; // r3
  idSWF *mainMenu; // r11
  idSWFScriptFunction *v6; // r4
  idSWFScriptVar *v7; // r3
  idSWFScriptObject *v8; // r29
  idSWFScriptFunction *v9; // r3
  idSWF *v10; // r11
  idSWFScriptFunction *v11; // r4
  idSWFScriptVar *v12; // r3
  idSWFScriptVar v13; // [sp+50h] [-B0h] BYREF
  idSWFScriptVar v14; // [sp+58h] [-A8h] BYREF
  idSWFScriptVar v15; // [sp+60h] [-A0h] BYREF
  idSWFScriptVar v16; // [sp+68h] [-98h] BYREF
  idSWFScriptVar v17; // [sp+70h] [-90h] BYREF
  idSWFScriptVar v18; // [sp+78h] [-88h] BYREF
  idSWFScriptVar v19; // [sp+80h] [-80h] BYREF
  idSWFScriptVar v20; // [sp+88h] [-78h] BYREF
  idSWFScriptVar v21; // [sp+90h] [-70h] BYREF
  idSWFScriptVar v22[13]; // [sp+98h] [-68h] BYREF

  scriptObject = this->mainMenu->mainspriteInstance->scriptObject;
  NestedObj = idSWFScriptObject::GetNestedObj(
                this: scriptObject,
                arg1: "cmdBar",
                arg2: "joy1",
                arg3: nullptr,
                arg4: nullptr,
                arg5: nullptr,
                arg6: nullptr);
  if ( NestedObj != nullptr )
  {
    v4 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x10u,
                                  tag: TAG_SWF,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
    if ( v4 != nullptr )
    {
      mainMenu = this->mainMenu;
      v4[3].__vftable = (idSWFScriptFunction_vtbl *)this;
      v6 = v4;
      v4[1].__vftable = nullptr;
      v4->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateAcceptBackCmds'::`2'::idSWFScriptFunction_accept::`vftable';
      v4[2].__vftable = (idSWFScriptFunction_vtbl *)mainMenu;
    }
    else
    {
      v6 = nullptr;
    }
    idSWFScriptVar::idSWFScriptVar(this: &v14, nf: v6);
    idSWFScriptObject::Set(this: NestedObj, name: "onPress", value: &v14);
    idSWFScriptVar::Free(this: &v14);
  }
  idSWF::GetGlobal(this: (idSWF *)&v13, result: (idSWFScriptVar *)this->mainMenu, name: "shortcutKeys");
  if ( v13.type == SWF_VAR_OBJECT )
  {
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)this->mainMenu) != 0 )
    {
      idSWFScriptVar::idSWFScriptVar(this: &v15, o: NestedObj);
      idSWFScriptObject::Set(this: v13.value.object, name: "JOY2", value: &v15);
      v7 = &v15;
    }
    else
    {
      idSWFScriptVar::idSWFScriptVar(this: &v16, o: NestedObj);
      idSWFScriptObject::Set(this: v13.value.object, name: "JOY1", value: &v16);
      idSWFScriptVar::Free(this: &v16);
      idSWFScriptVar::idSWFScriptVar(this: &v17, o: NestedObj);
      idSWFScriptObject::Set(this: v13.value.object, name: "ENTER", value: &v17);
      v7 = &v17;
    }
    idSWFScriptVar::Free(this: v7);
  }
  v8 = idSWFScriptObject::GetNestedObj(
         this: scriptObject,
         arg1: "cmdBar",
         arg2: "joy2",
         arg3: nullptr,
         arg4: nullptr,
         arg5: nullptr,
         arg6: nullptr);
  if ( v8 != nullptr )
  {
    v9 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x10u,
                                  tag: TAG_SWF,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
    if ( v9 != nullptr )
    {
      v10 = this->mainMenu;
      v9[3].__vftable = (idSWFScriptFunction_vtbl *)this;
      v11 = v9;
      v9[1].__vftable = nullptr;
      v9->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateAcceptBackCmds'::`14'::idSWFScriptFunction_back::`vftable';
      v9[2].__vftable = (idSWFScriptFunction_vtbl *)v10;
    }
    else
    {
      v11 = nullptr;
    }
    idSWFScriptVar::idSWFScriptVar(this: &v18, nf: v11);
    idSWFScriptObject::Set(this: v8, name: "onPress", value: &v18);
    idSWFScriptVar::Free(this: &v18);
  }
  if ( v13.type == SWF_VAR_OBJECT )
  {
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)this->mainMenu) != 0 )
    {
      idSWFScriptVar::idSWFScriptVar(this: &v19, o: v8);
      idSWFScriptObject::Set(this: v13.value.object, name: "JOY1", value: &v19);
      v12 = &v19;
    }
    else
    {
      idSWFScriptVar::idSWFScriptVar(this: &v20, o: v8);
      idSWFScriptObject::Set(this: v13.value.object, name: "JOY2", value: &v20);
      idSWFScriptVar::Free(this: &v20);
      idSWFScriptVar::idSWFScriptVar(this: &v21, o: v8);
      idSWFScriptObject::Set(this: v13.value.object, name: "BACKSPACE", value: &v21);
      idSWFScriptVar::Free(this: &v21);
      idSWFScriptVar::idSWFScriptVar(this: v22, o: v8);
      idSWFScriptObject::Set(this: v13.value.object, name: "ESCAPE", value: v22);
      v12 = v22;
    }
    idSWFScriptVar::Free(this: v12);
  }
  idSWFScriptVar::Free(this: &v13);
}


// ========================================================================
// __unwind$526463
// EA  : 0x82DA8970
// RVA : 0x00DA8970
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526463()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 88));
}


// ========================================================================
// __unwind$526464
// EA  : 0x82DA8998
// RVA : 0x00DA8998
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526464()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$526465
// EA  : 0x82DA89C0
// RVA : 0x00DA89C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526465()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$526466
// EA  : 0x82DA89E8
// RVA : 0x00DA89E8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526466()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 104));
}


// ========================================================================
// __unwind$526467
// EA  : 0x82DA8A10
// RVA : 0x00DA8A10
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526467()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 112));
}


// ========================================================================
// __unwind$526469
// EA  : 0x82DA8A38
// RVA : 0x00DA8A38
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526469()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 120));
}


// ========================================================================
// __unwind$526470
// EA  : 0x82DA8A60
// RVA : 0x00DA8A60
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526470()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$526471
// EA  : 0x82DA8A88
// RVA : 0x00DA8A88
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526471()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 136));
}


// ========================================================================
// __unwind$526472
// EA  : 0x82DA8AB0
// RVA : 0x00DA8AB0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526472()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 144));
}


// ========================================================================
// __unwind$526473
// EA  : 0x82DA8AD8
// RVA : 0x00DA8AD8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526473()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 152));
}


// ========================================================================
// LoadResourcesAndSortBySortId<idDeclChapter>
// EA  : 0x82DA8B08
// RVA : 0x00DA8B08
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall LoadResourcesAndSortBySortId<idDeclChapter>(
        idList<idSpawnArea::GeneratedPosition *,5> *list,
        int a2,
        int a3,
        int a4,
        unsigned __int64 a5,
        __int64 a6)
{
  int num; // r4
  int v8; // r30
  const idDeclChapter **v9; // r4
  unsigned int v10; // r5
  const idDeclChapter **v11; // [sp+50h] [-30h] BYREF
  idSort_Quick<idDeclAccolade const *,idSort_DeclAccoladePtr> v12; // [sp+54h] [-2Ch] BYREF

  LODWORD(a6) = list->size;
  num = idDeclChapter::resourceList.num;
  if ( idDeclChapter::resourceList.num > (int)a6 )
  {
    idList<idNavSpline *,5>::Resize(this: list, newsize: idDeclChapter::resourceList.num);
    num = idDeclChapter::resourceList.num;
  }
  v8 = 0;
  if ( num > 0 )
  {
    do
    {
      v11 = (const idDeclChapter **)idResourceList::Index(this: &idDeclChapter::resourceList, index: v8);
      if ( v11 != nullptr )
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)list,
          obj: (encounterGroupRole_t *)&v11);
      ++v8;
    }
    while ( v8 < idDeclChapter::resourceList.num );
  }
  v12.__vftable = (idSort_Quick<idDeclAccolade const *,idSort_DeclAccoladePtr>_vtbl *)&idSort_Quick_SortId<idDeclChapter const *>::`vftable';
  v9 = (const idDeclChapter **)list->list;
  if ( list->list != nullptr )
  {
    v10 = list->num;
    v11 = (const idDeclChapter **)list->list;
    idSort_Quick<idDeclSecretType const *,idSort_Quick_SortId<idDeclSecretType const *>>::Sort(
      this: &v12,
      base: (const idDeclAccolade **)v9,
      num: v10,
      a4,
      a5,
      a6);
  }
}


// ========================================================================
// __unwind$526666
// EA  : 0x82DA8BB8
// RVA : 0x00DA8BB8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526666()
{
  int v0; // r12

  idSort_Quick_SortId<idDeclChapter const *>::~idSort_Quick_SortId<idDeclChapter const *>(this: (idSort_Quick_SortId<idDeclChapter const *> *)(v0 - 128 + 84));
}


// ========================================================================
// LoadResourcesAndSortBySortId<idDeclSecretType>
// EA  : 0x82DA8BE8
// RVA : 0x00DA8BE8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall LoadResourcesAndSortBySortId<idDeclSecretType>(
        idList<idSpawnArea::GeneratedPosition *,5> *list,
        int a2,
        int a3,
        int a4,
        unsigned __int64 a5,
        __int64 a6)
{
  int num; // r4
  int v8; // r30
  const idDeclSecretType **v9; // r4
  unsigned int v10; // r5
  const idDeclSecretType **v11; // [sp+50h] [-30h] BYREF
  idSort_Quick<idDeclAccolade const *,idSort_DeclAccoladePtr> v12; // [sp+54h] [-2Ch] BYREF

  LODWORD(a6) = list->size;
  num = idDeclSecretType::resourceList.num;
  if ( idDeclSecretType::resourceList.num > (int)a6 )
  {
    idList<idNavSpline *,5>::Resize(this: list, newsize: idDeclSecretType::resourceList.num);
    num = idDeclSecretType::resourceList.num;
  }
  v8 = 0;
  if ( num > 0 )
  {
    do
    {
      v11 = (const idDeclSecretType **)idResourceList::Index(this: &idDeclSecretType::resourceList, index: v8);
      if ( v11 != nullptr )
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)list,
          obj: (encounterGroupRole_t *)&v11);
      ++v8;
    }
    while ( v8 < idDeclSecretType::resourceList.num );
  }
  v12.__vftable = (idSort_Quick<idDeclAccolade const *,idSort_DeclAccoladePtr>_vtbl *)&idSort_Quick_SortId<idDeclSecretType const *>::`vftable';
  v9 = (const idDeclSecretType **)list->list;
  if ( list->list != nullptr )
  {
    v10 = list->num;
    v11 = (const idDeclSecretType **)list->list;
    idSort_Quick<idDeclSecretType const *,idSort_Quick_SortId<idDeclSecretType const *>>::Sort(
      this: &v12,
      base: (const idDeclAccolade **)v9,
      num: v10,
      a4,
      a5,
      a6);
  }
}


// ========================================================================
// __unwind$526752
// EA  : 0x82DA8C98
// RVA : 0x00DA8C98
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_526752()
{
  int v0; // r12

  idSort_Quick_SortId<idDeclSecretType const *>::~idSort_Quick_SortId<idDeclSecretType const *>(this: (idSort_Quick_SortId<idDeclSecretType const *> *)(v0 - 128 + 84));
}


// ========================================================================
// ?SetupBindings@idMainMenu@@QAAXPAVidSWF@@@Z
// EA  : 0x82DA8CC8
// RVA : 0x00DA8CC8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::SetupBindings(idMainMenu *this, idSWF *gui)
{
  int i; // r22
  idDeclMenuPopup *v5; // r20
  char *ScriptName; // r3
  const idStr *v7; // r27
  idMainMenu::idSWFScriptFunction_setGameDifficulty_vtbl *v8; // r11
  idMainMenu::idSWFScriptFunction_setScrollSpeed_vtbl *v9; // r8
  idMainMenu::idSWFScriptFunction_stopPlaytestRenderDemoRecord_vtbl *v10; // r11
  idMainMenu::idSWFScriptFunction_showDLCOption_vtbl *v11; // r8
  _DWORD *v12; // r3
  idSWFScriptVar::swfScriptVarValue_t v13; // r22
  _DWORD *v14; // r3
  idSWFScriptVar::swfScriptVarValue_t v15; // r22
  _DWORD *v16; // r3
  idSWFScriptVar::swfScriptVarValue_t v17; // r22
  idSWFScriptVar v18; // [sp+50h] [-520h] BYREF
  idSWFScriptVar v19; // [sp+58h] [-518h] BYREF
  idSWFScriptVar v20; // [sp+60h] [-510h] BYREF
  idSWFScriptVar v21; // [sp+68h] [-508h] BYREF
  idSWFScriptVar v22; // [sp+70h] [-500h] BYREF
  idSWFScriptVar v23; // [sp+78h] [-4F8h] BYREF
  idSWFScriptVar v24; // [sp+80h] [-4F0h] BYREF
  idSWFScriptVar v25; // [sp+88h] [-4E8h] BYREF
  idSWFScriptVar v26; // [sp+90h] [-4E0h] BYREF
  idSWFScriptVar v27; // [sp+98h] [-4D8h] BYREF
  idSWFScriptVar v28; // [sp+A0h] [-4D0h] BYREF
  idSWFScriptVar v29; // [sp+A8h] [-4C8h] BYREF
  idSWFScriptVar v30; // [sp+B0h] [-4C0h] BYREF
  idSWFScriptVar v31; // [sp+B8h] [-4B8h] BYREF
  idSWFScriptVar v32; // [sp+C0h] [-4B0h] BYREF
  idSWFScriptVar v33; // [sp+C8h] [-4A8h] BYREF
  idSWFScriptVar v34; // [sp+D0h] [-4A0h] BYREF
  idSWFScriptVar v35; // [sp+D8h] [-498h] BYREF
  idSWFScriptVar v36; // [sp+E0h] [-490h] BYREF
  idSWFScriptVar v37; // [sp+E8h] [-488h] BYREF
  idSWFScriptVar v38; // [sp+F0h] [-480h] BYREF
  idSWFScriptVar v39; // [sp+F8h] [-478h] BYREF
  idSWFScriptVar v40; // [sp+100h] [-470h] BYREF
  idSWFScriptVar v41; // [sp+108h] [-468h] BYREF
  idSWFScriptVar v42; // [sp+110h] [-460h] BYREF
  idSWFScriptVar v43; // [sp+118h] [-458h] BYREF
  idSWFScriptVar v44; // [sp+120h] [-450h] BYREF
  idSWFScriptVar v45; // [sp+128h] [-448h] BYREF
  idSWFScriptVar v46; // [sp+130h] [-440h] BYREF
  idSWFScriptVar v47; // [sp+138h] [-438h] BYREF
  idSWFScriptVar v48; // [sp+140h] [-430h] BYREF
  idSWFScriptVar v49; // [sp+148h] [-428h] BYREF
  idSWFScriptVar v50; // [sp+150h] [-420h] BYREF
  idSWFScriptVar v51; // [sp+158h] [-418h] BYREF
  idSWFScriptVar v52; // [sp+160h] [-410h] BYREF
  idSWFScriptVar v53; // [sp+168h] [-408h] BYREF
  idSWFScriptVar v54; // [sp+170h] [-400h] BYREF
  idSWFScriptVar v55; // [sp+178h] [-3F8h] BYREF
  idSWFScriptVar v56; // [sp+180h] [-3F0h] BYREF
  idSWFScriptVar v57; // [sp+188h] [-3E8h] BYREF
  idSWFScriptVar v58; // [sp+190h] [-3E0h] BYREF
  idSWFScriptVar v59; // [sp+198h] [-3D8h] BYREF
  idSWFScriptVar v60; // [sp+1A0h] [-3D0h] BYREF
  idSWFScriptVar v61; // [sp+1A8h] [-3C8h] BYREF
  idSWFScriptVar v62; // [sp+1B0h] [-3C0h] BYREF
  idSWFScriptVar v63; // [sp+1B8h] [-3B8h] BYREF
  idSWFScriptVar v64; // [sp+1C0h] [-3B0h] BYREF
  idSWFScriptVar v65; // [sp+1C8h] [-3A8h] BYREF
  idSWFScriptVar v66; // [sp+1D0h] [-3A0h] BYREF
  idSWFScriptVar v67; // [sp+1D8h] [-398h] BYREF
  idSWFScriptVar v68; // [sp+1E0h] [-390h] BYREF
  idSWFScriptVar v69; // [sp+1E8h] [-388h] BYREF
  idSWFScriptVar v70; // [sp+1F0h] [-380h] BYREF
  idSWFScriptVar v71; // [sp+1F8h] [-378h] BYREF
  idSWFScriptVar v72; // [sp+200h] [-370h] BYREF
  idSWFScriptVar v73; // [sp+208h] [-368h] BYREF
  idSWFScriptVar v74; // [sp+210h] [-360h] BYREF
  idSWFScriptVar v75; // [sp+218h] [-358h] BYREF
  idSWFScriptVar v76; // [sp+220h] [-350h] BYREF
  idSWFScriptVar v77; // [sp+228h] [-348h] BYREF
  idSWFScriptVar v78; // [sp+230h] [-340h] BYREF
  idSWFScriptVar v79; // [sp+238h] [-338h] BYREF
  idSWFScriptVar v80; // [sp+240h] [-330h] BYREF
  idSWFScriptVar v81; // [sp+248h] [-328h] BYREF
  idSWFScriptVar v82; // [sp+250h] [-320h] BYREF
  idSWFScriptVar v83; // [sp+258h] [-318h] BYREF
  idSWFScriptVar v84; // [sp+260h] [-310h] BYREF
  idSWFScriptVar v85; // [sp+268h] [-308h] BYREF
  idSWFScriptVar v86; // [sp+270h] [-300h] BYREF
  idSWFScriptVar v87; // [sp+278h] [-2F8h] BYREF
  idSWFScriptVar v88; // [sp+280h] [-2F0h] BYREF
  idSWFScriptVar v89; // [sp+288h] [-2E8h] BYREF
  idSWFScriptVar v90; // [sp+290h] [-2E0h] BYREF
  idSWFScriptVar v91; // [sp+298h] [-2D8h] BYREF
  idSWFScriptVar v92; // [sp+2A0h] [-2D0h] BYREF
  idSWFScriptVar v93; // [sp+2A8h] [-2C8h] BYREF
  idSWFScriptVar v94; // [sp+2B0h] [-2C0h] BYREF
  idSWFScriptVar v95; // [sp+2B8h] [-2B8h] BYREF
  idSWFScriptVar v96; // [sp+2C0h] [-2B0h] BYREF
  idSWFScriptVar v97; // [sp+2C8h] [-2A8h] BYREF
  idSWFScriptVar v98; // [sp+2D0h] [-2A0h] BYREF
  idSWFScriptVar v99; // [sp+2D8h] [-298h] BYREF
  idSWFScriptVar v100; // [sp+2E0h] [-290h] BYREF
  idSWFScriptVar v101; // [sp+2E8h] [-288h] BYREF
  idSWFScriptVar v102; // [sp+2F0h] [-280h] BYREF
  idSWFScriptVar v103; // [sp+2F8h] [-278h] BYREF
  idSWFScriptVar v104; // [sp+300h] [-270h] BYREF
  idSWFScriptVar v105; // [sp+308h] [-268h] BYREF
  idSWFScriptVar v106; // [sp+310h] [-260h] BYREF
  idSWFScriptVar v107; // [sp+318h] [-258h] BYREF
  idSWFScriptVar v108; // [sp+320h] [-250h] BYREF
  idSWFScriptVar v109; // [sp+328h] [-248h] BYREF
  idSWFScriptVar v110; // [sp+330h] [-240h] BYREF
  idSWFScriptVar v111; // [sp+338h] [-238h] BYREF
  idSWFScriptVar v112; // [sp+340h] [-230h] BYREF
  idSWFScriptVar v113; // [sp+348h] [-228h] BYREF
  idSWFScriptVar v114; // [sp+350h] [-220h] BYREF
  idSWFScriptVar v115; // [sp+358h] [-218h] BYREF
  idSWFScriptVar v116; // [sp+360h] [-210h] BYREF
  idSWFScriptVar v117; // [sp+368h] [-208h] BYREF
  idSWFScriptVar v118; // [sp+370h] [-200h] BYREF
  idSWFScriptVar v119; // [sp+378h] [-1F8h] BYREF
  idSWFScriptVar v120; // [sp+380h] [-1F0h] BYREF
  idSWFScriptVar v121; // [sp+388h] [-1E8h] BYREF
  idSWFScriptVar v122; // [sp+390h] [-1E0h] BYREF
  idSWFScriptVar v123; // [sp+398h] [-1D8h] BYREF
  idSWFScriptVar v124; // [sp+3A0h] [-1D0h] BYREF
  idSWFScriptVar v125; // [sp+3A8h] [-1C8h] BYREF
  idSWFScriptVar v126; // [sp+3B0h] [-1C0h] BYREF
  idSWFScriptVar v127; // [sp+3B8h] [-1B8h] BYREF
  idSWFScriptVar v128; // [sp+3C0h] [-1B0h] BYREF
  idSWFScriptVar v129; // [sp+3C8h] [-1A8h] BYREF
  idSWFScriptVar v130; // [sp+3D0h] [-1A0h] BYREF
  idSWFScriptVar v131; // [sp+3D8h] [-198h] BYREF
  idSWFScriptVar v132; // [sp+3E0h] [-190h] BYREF
  idSWFScriptVar v133; // [sp+3E8h] [-188h] BYREF
  idSWFScriptVar v134; // [sp+3F0h] [-180h] BYREF
  idSWFScriptVar v135; // [sp+3F8h] [-178h] BYREF
  idSWFScriptVar v136; // [sp+400h] [-170h] BYREF
  idSWFScriptVar v137; // [sp+408h] [-168h] BYREF
  idSWFScriptVar v138; // [sp+410h] [-160h] BYREF
  idSWFScriptVar v139; // [sp+418h] [-158h] BYREF
  idSWFScriptVar v140; // [sp+420h] [-150h] BYREF
  idSWFScriptVar v141; // [sp+428h] [-148h] BYREF
  idSWFScriptVar v142; // [sp+430h] [-140h] BYREF
  idSWFScriptVar v143; // [sp+438h] [-138h] BYREF
  idSWFScriptVar v144; // [sp+440h] [-130h] BYREF
  idSWFScriptVar v145; // [sp+448h] [-128h] BYREF
  idSWFScriptVar v146; // [sp+450h] [-120h] BYREF
  idSWFScriptVar v147; // [sp+458h] [-118h] BYREF
  idSWFScriptVar v148; // [sp+460h] [-110h] BYREF
  idSWFScriptVar v149; // [sp+468h] [-108h] BYREF
  idSWFScriptVar v150; // [sp+470h] [-100h] BYREF
  idSWFScriptVar v151; // [sp+478h] [-F8h] BYREF
  idSWFScriptVar v152; // [sp+480h] [-F0h] BYREF
  idSWFScriptVar v153; // [sp+488h] [-E8h] BYREF
  idSWFScriptVar v154; // [sp+490h] [-E0h] BYREF
  idSWFScriptVar v155; // [sp+498h] [-D8h] BYREF
  idSWFScriptVar v156; // [sp+4A0h] [-D0h] BYREF
  idSWFScriptVar v157; // [sp+4A8h] [-C8h] BYREF
  idSWFScriptVar v158; // [sp+4B0h] [-C0h] BYREF
  idSWFScriptVar v159; // [sp+4B8h] [-B8h] BYREF
  idSWFScriptVar v160; // [sp+4C0h] [-B0h] BYREF
  _DWORD *v161; // [sp+4C8h] [-A8h]
  idStr v162[5]; // [sp+4D0h] [-A0h] BYREF

  v23.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v23);
  v23.type = SWF_VAR_INTEGER;
  v23.value.i = 0;
  idSWFScriptObject::Set(this: gui->globals, name: "PAUSEMENU_DEFAULT", value: &v23);
  idSWFScriptVar::Free(this: &v23);
  v93.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v93);
  v93.type = SWF_VAR_INTEGER;
  v93.value.i = 1;
  idSWFScriptObject::Set(this: gui->globals, name: "PAUSEMENU_DEFAULT_NOSAVE", value: &v93);
  idSWFScriptVar::Free(this: &v93);
  v25.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v25);
  v25.type = SWF_VAR_INTEGER;
  v25.value.i = 3;
  idSWFScriptObject::Set(this: gui->globals, name: "PAUSEMENU_MULTI_COOP", value: &v25);
  idSWFScriptVar::Free(this: &v25);
  v127.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v127);
  v127.type = SWF_VAR_INTEGER;
  v127.value.i = 2;
  idSWFScriptObject::Set(this: gui->globals, name: "PAUSEMENU_MULTI_VDM", value: &v127);
  idSWFScriptVar::Free(this: &v127);
  v27.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v27);
  v27.type = SWF_VAR_INTEGER;
  v27.value.i = 0;
  idSWFScriptObject::Set(this: gui->globals, name: "PAUSE_RESTART", value: &v27);
  idSWFScriptVar::Free(this: &v27);
  v95.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v95);
  v95.type = SWF_VAR_INTEGER;
  v95.value.i = 1;
  idSWFScriptObject::Set(this: gui->globals, name: "PAUSE_LOADGAME", value: &v95);
  idSWFScriptVar::Free(this: &v95);
  v29.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v29);
  v29.type = SWF_VAR_INTEGER;
  v29.value.i = 2;
  idSWFScriptObject::Set(this: gui->globals, name: "PAUSE_QUIT", value: &v29);
  idSWFScriptVar::Free(this: &v29);
  v159.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v159);
  v159.type = SWF_VAR_INTEGER;
  v159.value.i = 5;
  idSWFScriptObject::Set(this: gui->globals, name: "PAUSE_MULTI_SELF_DESTRUCT", value: &v159);
  idSWFScriptVar::Free(this: &v159);
  v31.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v31);
  v31.type = SWF_VAR_INTEGER;
  v31.value.i = 4;
  idSWFScriptObject::Set(this: gui->globals, name: "PAUSE_MULTI_RETRY", value: &v31);
  idSWFScriptVar::Free(this: &v31);
  v97.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v97);
  v97.type = SWF_VAR_INTEGER;
  v97.value.i = 0;
  idSWFScriptObject::Set(this: gui->globals, name: "DIFFICULTY_EASY", value: &v97);
  idSWFScriptVar::Free(this: &v97);
  v33.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v33);
  v33.type = SWF_VAR_INTEGER;
  v33.value.i = 1;
  idSWFScriptObject::Set(this: gui->globals, name: "DIFFICULTY_MEDIUM", value: &v33);
  idSWFScriptVar::Free(this: &v33);
  v129.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v129);
  v129.type = SWF_VAR_INTEGER;
  v129.value.i = 2;
  idSWFScriptObject::Set(this: gui->globals, name: "DIFFICULTY_HARD", value: &v129);
  idSWFScriptVar::Free(this: &v129);
  v35.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v35);
  v35.type = SWF_VAR_INTEGER;
  v35.value.i = 3;
  idSWFScriptObject::Set(this: gui->globals, name: "DIFFICULTY_NIGHTMARE", value: &v35);
  idSWFScriptVar::Free(this: &v35);
  for ( i = 0; i < idDeclMenuPopup::resourceList.num; ++i )
  {
    v5 = (idDeclMenuPopup *)idResourceList::Index(this: &idDeclMenuPopup::resourceList, index: i);
    if ( v5 != nullptr )
    {
      v99.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v99);
      v99.type = SWF_VAR_STRING;
      v99.value.i = (int)idSWFScriptString::Alloc(s: &v5->fileName);
      ScriptName = idDeclMenuPopup::GetScriptName(this: v5);
      idSWFScriptObject::Set(this: gui->globals, name: ScriptName, value: &v99);
      idSWFScriptVar::Free(this: &v99);
    }
  }
  v37.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v37);
  v37.type = SWF_VAR_INTEGER;
  v37.value.i = -1;
  idSWFScriptObject::Set(this: gui->globals, name: "POPUP_RESULT_NONE", value: &v37);
  idSWFScriptVar::Free(this: &v37);
  v145.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v145);
  v145.type = SWF_VAR_INTEGER;
  v145.value.i = 0;
  idSWFScriptObject::Set(this: gui->globals, name: "POPUP_RESULT_OPTION1", value: &v145);
  idSWFScriptVar::Free(this: &v145);
  v39.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v39);
  v39.type = SWF_VAR_INTEGER;
  v39.value.i = 1;
  idSWFScriptObject::Set(this: gui->globals, name: "POPUP_RESULT_OPTION2", value: &v39);
  idSWFScriptVar::Free(this: &v39);
  v101.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v101);
  v101.type = SWF_VAR_INTEGER;
  v101.value.i = 2;
  idSWFScriptObject::Set(this: gui->globals, name: "POPUP_RESULT_OPTION3", value: &v101);
  idSWFScriptVar::Free(this: &v101);
  v41.type = SWF_VAR_UNDEF;
  v7 = idStr::idStr(this: v162, text: "online_popup_dialog");
  idSWFScriptVar::Free(this: &v41);
  v41.type = SWF_VAR_STRING;
  v41.value.i = (int)idSWFScriptString::Alloc(s: v7);
  idStr::FreeData(this: v162);
  idSWFScriptObject::Set(this: gui->globals, name: "POPUP_ONLINE_DIALOG", value: &v41);
  idSWFScriptVar::Free(this: &v41);
  v131.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v131);
  v131.type = SWF_VAR_INTEGER;
  v131.value.i = 0;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_AUDIOVOLUME_MASTER", value: &v131);
  idSWFScriptVar::Free(this: &v131);
  v43.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v43);
  v43.type = SWF_VAR_INTEGER;
  v43.value.i = 1;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_AUDIOVOLUME_MUSIC", value: &v43);
  idSWFScriptVar::Free(this: &v43);
  v103.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v103);
  v103.type = SWF_VAR_INTEGER;
  v103.value.i = 2;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_AUDIOVOLUME_VOICE", value: &v103);
  idSWFScriptVar::Free(this: &v103);
  v45.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v45);
  v45.type = SWF_VAR_INTEGER;
  v45.value.i = 3;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_AUDIOVOLUME_AMBIENT", value: &v45);
  idSWFScriptVar::Free(this: &v45);
  v153.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v153);
  v153.type = SWF_VAR_INTEGER;
  v153.value.i = 0;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_PRESS_START", value: &v153);
  idSWFScriptVar::Free(this: &v153);
  v47.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v47);
  v47.type = SWF_VAR_INTEGER;
  v47.value.i = 1;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_MAIN", value: &v47);
  idSWFScriptVar::Free(this: &v47);
  v105.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v105);
  v105.type = SWF_VAR_INTEGER;
  v105.value.i = 2;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_WAITING", value: &v105);
  idSWFScriptVar::Free(this: &v105);
  v49.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v49);
  v49.type = SWF_VAR_INTEGER;
  v49.value.i = 3;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_PARTY_LOBBY_HOST", value: &v49);
  idSWFScriptVar::Free(this: &v49);
  v133.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v133);
  v133.type = SWF_VAR_INTEGER;
  v133.value.i = 4;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_PARTY_LOBBY_PEER", value: &v133);
  idSWFScriptVar::Free(this: &v133);
  v51.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v51);
  v51.type = SWF_VAR_INTEGER;
  v51.value.i = 5;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_GAME_LOBBY_HOST", value: &v51);
  idSWFScriptVar::Free(this: &v51);
  v107.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v107);
  v107.type = SWF_VAR_INTEGER;
  v107.value.i = 6;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_GAME_LOBBY_PEER", value: &v107);
  idSWFScriptVar::Free(this: &v107);
  v53.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v53);
  v53.type = SWF_VAR_INTEGER;
  v53.value.i = 7;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_INGAME", value: &v53);
  idSWFScriptVar::Free(this: &v53);
  v147.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v147);
  v147.type = SWF_VAR_INTEGER;
  v147.value.i = 0;
  idSWFScriptObject::Set(this: gui->globals, name: "BIND_DEFAULT", value: &v147);
  idSWFScriptVar::Free(this: &v147);
  v55.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v55);
  v55.type = SWF_VAR_INTEGER;
  v55.value.i = 2;
  idSWFScriptObject::Set(this: gui->globals, name: "BIND_DRIVE", value: &v55);
  idSWFScriptVar::Free(this: &v55);
  v109.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v109);
  v109.type = SWF_VAR_INTEGER;
  v109.value.i = 4;
  idSWFScriptObject::Set(this: gui->globals, name: "BIND_REMOTE", value: &v109);
  idSWFScriptVar::Free(this: &v109);
  v57.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v57);
  v57.type = SWF_VAR_INTEGER;
  v57.value.i = 3;
  idSWFScriptObject::Set(this: gui->globals, name: "BIND_POSSESS", value: &v57);
  idSWFScriptVar::Free(this: &v57);
  v135.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v135);
  v135.type = SWF_VAR_INTEGER;
  v135.value.i = 5;
  idSWFScriptObject::Set(this: gui->globals, name: "BIND_VEHICLE_GUNNER", value: &v135);
  idSWFScriptVar::Free(this: &v135);
  v59.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v59);
  v59.type = SWF_VAR_INTEGER;
  v59.value.i = 6;
  idSWFScriptObject::Set(this: gui->globals, name: "BIND_VEHICLE_PASSENGER", value: &v59);
  idSWFScriptVar::Free(this: &v59);
  this->scriptFunction_setState.pThis = this;
  v111.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v111);
  v111.value.i = (int)&this->scriptFunction_setState;
  v111.type = SWF_VAR_FUNCTION;
  this->scriptFunction_setState.AddRef(this: &this->scriptFunction_setState);
  idSWFScriptObject::Set(this: gui->globals, name: "setState", value: &v111);
  idSWFScriptVar::Free(this: &v111);
  this->scriptFunction_registerUserMouse.pThis = this;
  v61.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v61);
  v61.value.i = (int)&this->scriptFunction_registerUserMouse;
  v61.type = SWF_VAR_FUNCTION;
  this->scriptFunction_registerUserMouse.AddRef(this: &this->scriptFunction_registerUserMouse);
  idSWFScriptObject::Set(this: gui->globals, name: "registerUserMouse", value: &v61);
  idSWFScriptVar::Free(this: &v61);
  this->scriptFunction_quitGame.pThis = this;
  v157.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v157);
  v157.value.i = (int)&this->scriptFunction_quitGame;
  v157.type = SWF_VAR_FUNCTION;
  this->scriptFunction_quitGame.AddRef(this: &this->scriptFunction_quitGame);
  idSWFScriptObject::Set(this: gui->globals, name: "quitGame", value: &v157);
  idSWFScriptVar::Free(this: &v157);
  this->scriptFunction_setMenuArea.pThis = this;
  v63.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v63);
  v63.value.i = (int)&this->scriptFunction_setMenuArea;
  v63.type = SWF_VAR_FUNCTION;
  this->scriptFunction_setMenuArea.AddRef(this: &this->scriptFunction_setMenuArea);
  idSWFScriptObject::Set(this: gui->globals, name: "setMenuArea", value: &v63);
  idSWFScriptVar::Free(this: &v63);
  this->scriptFunction_forceMenuArea.pThis = this;
  v113.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v113);
  v113.value.i = (int)&this->scriptFunction_forceMenuArea;
  v113.type = SWF_VAR_FUNCTION;
  this->scriptFunction_forceMenuArea.AddRef(this: &this->scriptFunction_forceMenuArea);
  idSWFScriptObject::Set(this: gui->globals, name: "forceMenuArea", value: &v113);
  idSWFScriptVar::Free(this: &v113);
  this->scriptFunction_updateScrolling.pThis = this;
  v65.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v65);
  v65.value.i = (int)&this->scriptFunction_updateScrolling;
  v65.type = SWF_VAR_FUNCTION;
  this->scriptFunction_updateScrolling.AddRef(this: &this->scriptFunction_updateScrolling);
  idSWFScriptObject::Set(this: gui->globals, name: "updateScrolling", value: &v65);
  idSWFScriptVar::Free(this: &v65);
  this->scriptFunction_checkCanPlayOnline.pThis = this;
  v137.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v137);
  v137.value.i = (int)&this->scriptFunction_checkCanPlayOnline;
  v137.type = SWF_VAR_FUNCTION;
  this->scriptFunction_checkCanPlayOnline.AddRef(this: &this->scriptFunction_checkCanPlayOnline);
  idSWFScriptObject::Set(this: gui->globals, name: "checkCanPlayOnline", value: &v137);
  idSWFScriptVar::Free(this: &v137);
  this->scriptFunction_isMpDisc.pThis = this;
  v67.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v67);
  v67.value.i = (int)&this->scriptFunction_isMpDisc;
  v67.type = SWF_VAR_FUNCTION;
  this->scriptFunction_isMpDisc.AddRef(this: &this->scriptFunction_isMpDisc);
  idSWFScriptObject::Set(this: gui->globals, name: "isMpDisc", value: &v67);
  idSWFScriptVar::Free(this: &v67);
  this->scriptFunction_moveBetweenSPAndMP.pThis = this;
  v115.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v115);
  v115.value.i = (int)&this->scriptFunction_moveBetweenSPAndMP;
  v115.type = SWF_VAR_FUNCTION;
  this->scriptFunction_moveBetweenSPAndMP.AddRef(this: &this->scriptFunction_moveBetweenSPAndMP);
  idSWFScriptObject::Set(this: gui->globals, name: "moveBetweenSPAndMP", value: &v115);
  idSWFScriptVar::Free(this: &v115);
  this->scriptFunction_setGameDifficulty.pThis = this;
  v69.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v69);
  v8 = this->scriptFunction_setGameDifficulty.__vftable;
  v69.value.i = (int)&this->scriptFunction_setGameDifficulty;
  v69.type = SWF_VAR_FUNCTION;
  v8->AddRef(this: &this->scriptFunction_setGameDifficulty);
  idSWFScriptObject::Set(this: gui->globals, name: "setGameDifficulty", value: &v69);
  idSWFScriptVar::Free(this: &v69);
  this->scriptFunction_setNewGameDifficulty.pThis = this;
  v149.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v149);
  v149.value.i = (int)&this->scriptFunction_setNewGameDifficulty;
  v149.type = SWF_VAR_FUNCTION;
  this->scriptFunction_setNewGameDifficulty.AddRef(this: &this->scriptFunction_setNewGameDifficulty);
  idSWFScriptObject::Set(this: gui->globals, name: "setNewGameDifficulty", value: &v149);
  idSWFScriptVar::Free(this: &v149);
  this->scriptFunction_getGameDifficulty.pThis = this;
  v71.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v71);
  v71.value.i = (int)&this->scriptFunction_getGameDifficulty;
  v71.type = SWF_VAR_FUNCTION;
  this->scriptFunction_getGameDifficulty.AddRef(this: &this->scriptFunction_getGameDifficulty);
  idSWFScriptObject::Set(this: gui->globals, name: "getGameDifficulty", value: &v71);
  idSWFScriptVar::Free(this: &v71);
  this->scriptFunction_closeMenu.pThis = this;
  v117.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v117);
  v117.value.i = (int)&this->scriptFunction_closeMenu;
  v117.type = SWF_VAR_FUNCTION;
  this->scriptFunction_closeMenu.AddRef(this: &this->scriptFunction_closeMenu);
  idSWFScriptObject::Set(this: gui->globals, name: "closeMenu", value: &v117);
  idSWFScriptVar::Free(this: &v117);
  this->scriptFunction_setNewGame.pThis = this;
  v73.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v73);
  v73.value.i = (int)&this->scriptFunction_setNewGame;
  v73.type = SWF_VAR_FUNCTION;
  this->scriptFunction_setNewGame.AddRef(this: &this->scriptFunction_setNewGame);
  idSWFScriptObject::Set(this: gui->globals, name: "setNewGame", value: &v73);
  idSWFScriptVar::Free(this: &v73);
  this->scriptFunction_needsDiskSwap.pThis = this;
  v139.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v139);
  v139.value.i = (int)&this->scriptFunction_needsDiskSwap;
  v139.type = SWF_VAR_FUNCTION;
  this->scriptFunction_needsDiskSwap.AddRef(this: &this->scriptFunction_needsDiskSwap);
  idSWFScriptObject::Set(this: gui->globals, name: "needsDiskSwap", value: &v139);
  idSWFScriptVar::Free(this: &v139);
  this->scriptFunction_waitForCredits.pThis = this;
  v75.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v75);
  v75.value.i = (int)&this->scriptFunction_waitForCredits;
  v75.type = SWF_VAR_FUNCTION;
  this->scriptFunction_waitForCredits.AddRef(this: &this->scriptFunction_waitForCredits);
  idSWFScriptObject::Set(this: gui->globals, name: "waitForCredits", value: &v75);
  idSWFScriptVar::Free(this: &v75);
  this->scriptFunction_clearWaitForCredits.pThis = this;
  v119.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v119);
  v119.value.i = (int)&this->scriptFunction_clearWaitForCredits;
  v119.type = SWF_VAR_FUNCTION;
  this->scriptFunction_clearWaitForCredits.AddRef(this: &this->scriptFunction_clearWaitForCredits);
  idSWFScriptObject::Set(this: gui->globals, name: "clearWaitForCredits", value: &v119);
  idSWFScriptVar::Free(this: &v119);
  this->scriptFunction_isProfileScreenOpen.pThis = this;
  v77.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v77);
  v77.value.i = (int)&this->scriptFunction_isProfileScreenOpen;
  v77.type = SWF_VAR_FUNCTION;
  this->scriptFunction_isProfileScreenOpen.AddRef(this: &this->scriptFunction_isProfileScreenOpen);
  idSWFScriptObject::Set(this: gui->globals, name: "isProfileScreenOpen", value: &v77);
  idSWFScriptVar::Free(this: &v77);
  this->scriptFunction_needSpDiscSwap.pThis = this;
  v155.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v155);
  v155.value.i = (int)&this->scriptFunction_needSpDiscSwap;
  v155.type = SWF_VAR_FUNCTION;
  this->scriptFunction_needSpDiscSwap.AddRef(this: &this->scriptFunction_needSpDiscSwap);
  idSWFScriptObject::Set(this: gui->globals, name: "needSpDiscSwap", value: &v155);
  idSWFScriptVar::Free(this: &v155);
  this->scriptFunction_canScroll.pThis = this;
  v79.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v79);
  v79.value.i = (int)&this->scriptFunction_canScroll;
  v79.type = SWF_VAR_FUNCTION;
  this->scriptFunction_canScroll.AddRef(this: &this->scriptFunction_canScroll);
  idSWFScriptObject::Set(this: gui->globals, name: "canScroll", value: &v79);
  idSWFScriptVar::Free(this: &v79);
  this->scriptFunction_setScrollSpeed.pThis = this;
  v121.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v121);
  v9 = this->scriptFunction_setScrollSpeed.__vftable;
  v121.value.i = (int)&this->scriptFunction_setScrollSpeed;
  v121.type = SWF_VAR_FUNCTION;
  v9->AddRef(this: &this->scriptFunction_setScrollSpeed);
  idSWFScriptObject::Set(this: gui->globals, name: "setScrollSpeed", value: &v121);
  idSWFScriptVar::Free(this: &v121);
  this->scriptFunction_getChapterList.pThis = this;
  v81.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v81);
  v81.value.i = (int)&this->scriptFunction_getChapterList;
  v81.type = SWF_VAR_FUNCTION;
  this->scriptFunction_getChapterList.AddRef(this: &this->scriptFunction_getChapterList);
  idSWFScriptObject::Set(this: gui->globals, name: "getChapterList", value: &v81);
  idSWFScriptVar::Free(this: &v81);
  this->scriptFunction_loadMap.pThis = this;
  v141.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v141);
  v141.value.i = (int)&this->scriptFunction_loadMap;
  v141.type = SWF_VAR_FUNCTION;
  this->scriptFunction_loadMap.AddRef(this: &this->scriptFunction_loadMap);
  idSWFScriptObject::Set(this: gui->globals, name: "loadMap", value: &v141);
  idSWFScriptVar::Free(this: &v141);
  this->scriptFunction_getDefaultDevMenuOption.pThis = this;
  v83.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v83);
  v83.value.i = (int)&this->scriptFunction_getDefaultDevMenuOption;
  v83.type = SWF_VAR_FUNCTION;
  this->scriptFunction_getDefaultDevMenuOption.AddRef(this: &this->scriptFunction_getDefaultDevMenuOption);
  idSWFScriptObject::Set(this: gui->globals, name: "getDefaultDevMenuOption", value: &v83);
  idSWFScriptVar::Free(this: &v83);
  this->scriptFunction_restartMap.pThis = this;
  v123.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v123);
  v123.value.i = (int)&this->scriptFunction_restartMap;
  v123.type = SWF_VAR_FUNCTION;
  this->scriptFunction_restartMap.AddRef(this: &this->scriptFunction_restartMap);
  idSWFScriptObject::Set(this: gui->globals, name: "restartMap", value: &v123);
  idSWFScriptVar::Free(this: &v123);
  this->scriptFunction_returnToMainMenu.pThis = this;
  v85.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v85);
  v85.value.i = (int)&this->scriptFunction_returnToMainMenu;
  v85.type = SWF_VAR_FUNCTION;
  this->scriptFunction_returnToMainMenu.AddRef(this: &this->scriptFunction_returnToMainMenu);
  idSWFScriptObject::Set(this: gui->globals, name: "returnToMainMenu", value: &v85);
  idSWFScriptVar::Free(this: &v85);
  this->scriptFunction_confirmExitGame.pThis = this;
  v151.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v151);
  v151.value.i = (int)&this->scriptFunction_confirmExitGame;
  v151.type = SWF_VAR_FUNCTION;
  this->scriptFunction_confirmExitGame.AddRef(this: &this->scriptFunction_confirmExitGame);
  idSWFScriptObject::Set(this: gui->globals, name: "confirmExitGame", value: &v151);
  idSWFScriptVar::Free(this: &v151);
  this->scriptFunction_restartFromPause.pThis = this;
  v87.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v87);
  v87.value.i = (int)&this->scriptFunction_restartFromPause;
  v87.type = SWF_VAR_FUNCTION;
  this->scriptFunction_restartFromPause.AddRef(this: &this->scriptFunction_restartFromPause);
  idSWFScriptObject::Set(this: gui->globals, name: "restartFromPause", value: &v87);
  idSWFScriptVar::Free(this: &v87);
  this->scriptFunction_cancelSaveEnumeration.pThis = this;
  v125.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v125);
  v125.value.i = (int)&this->scriptFunction_cancelSaveEnumeration;
  v125.type = SWF_VAR_FUNCTION;
  this->scriptFunction_cancelSaveEnumeration.AddRef(this: &this->scriptFunction_cancelSaveEnumeration);
  idSWFScriptObject::Set(this: gui->globals, name: "cancelSaveEnumeration", value: &v125);
  idSWFScriptVar::Free(this: &v125);
  this->scriptFunction_GetSaveGame.pThis = this;
  v89.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v89);
  v89.value.i = (int)&this->scriptFunction_GetSaveGame;
  v89.type = SWF_VAR_FUNCTION;
  this->scriptFunction_GetSaveGame.AddRef(this: &this->scriptFunction_GetSaveGame);
  idSWFScriptObject::Set(this: gui->globals, name: "GetSaveGame", value: &v89);
  idSWFScriptVar::Free(this: &v89);
  this->scriptFunction_CanSaveGame.pThis = this;
  v91.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v91);
  v91.value.i = (int)&this->scriptFunction_CanSaveGame;
  v91.type = SWF_VAR_FUNCTION;
  this->scriptFunction_CanSaveGame.AddRef(this: &this->scriptFunction_CanSaveGame);
  idSWFScriptObject::Set(this: gui->globals, name: "CanSaveGame", value: &v91);
  idSWFScriptVar::Free(this: &v91);
  this->scriptFunction_SaveGame.pThis = this;
  v21.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v21);
  v21.value.i = (int)&this->scriptFunction_SaveGame;
  v21.type = SWF_VAR_FUNCTION;
  this->scriptFunction_SaveGame.AddRef(this: &this->scriptFunction_SaveGame);
  idSWFScriptObject::Set(this: gui->globals, name: "SaveGame", value: &v21);
  idSWFScriptVar::Free(this: &v21);
  this->scriptFunction_LoadGame.pThis = this;
  v92.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v92);
  v92.value.i = (int)&this->scriptFunction_LoadGame;
  v92.type = SWF_VAR_FUNCTION;
  this->scriptFunction_LoadGame.AddRef(this: &this->scriptFunction_LoadGame);
  idSWFScriptObject::Set(this: gui->globals, name: "LoadGame", value: &v92);
  idSWFScriptVar::Free(this: &v92);
  this->scriptFunction_deleteGame.pThis = this;
  v22.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v22);
  v22.value.i = (int)&this->scriptFunction_deleteGame;
  v22.type = SWF_VAR_FUNCTION;
  this->scriptFunction_deleteGame.AddRef(this: &this->scriptFunction_deleteGame);
  idSWFScriptObject::Set(this: gui->globals, name: "deleteGame", value: &v22);
  idSWFScriptVar::Free(this: &v22);
  this->scriptFunction_select360Storage.pThis = this;
  v24.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v24);
  v24.value.i = (int)&this->scriptFunction_select360Storage;
  v24.type = SWF_VAR_FUNCTION;
  this->scriptFunction_select360Storage.AddRef(this: &this->scriptFunction_select360Storage);
  idSWFScriptObject::Set(this: gui->globals, name: "select360Storage", value: &v24);
  idSWFScriptVar::Free(this: &v24);
  this->scriptFunction_canContinueGame.pThis = this;
  v26.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v26);
  v26.value.i = (int)&this->scriptFunction_canContinueGame;
  v26.type = SWF_VAR_FUNCTION;
  this->scriptFunction_canContinueGame.AddRef(this: &this->scriptFunction_canContinueGame);
  idSWFScriptObject::Set(this: gui->globals, name: "canContinueGame", value: &v26);
  idSWFScriptVar::Free(this: &v26);
  this->scriptFunction_canLoadGame.pThis = this;
  v28.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v28);
  v28.value.i = (int)&this->scriptFunction_canLoadGame;
  v28.type = SWF_VAR_FUNCTION;
  this->scriptFunction_canLoadGame.AddRef(this: &this->scriptFunction_canLoadGame);
  idSWFScriptObject::Set(this: gui->globals, name: "canLoadGame", value: &v28);
  idSWFScriptVar::Free(this: &v28);
  this->scriptFunction_canStartNewGame.pThis = this;
  v30.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v30);
  v30.value.i = (int)&this->scriptFunction_canStartNewGame;
  v30.type = SWF_VAR_FUNCTION;
  this->scriptFunction_canStartNewGame.AddRef(this: &this->scriptFunction_canStartNewGame);
  idSWFScriptObject::Set(this: gui->globals, name: "canStartNewGame", value: &v30);
  idSWFScriptVar::Free(this: &v30);
  this->scriptFunction_startDeviceSignal.pThis = this;
  v32.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v32);
  v32.value.i = (int)&this->scriptFunction_startDeviceSignal;
  v32.type = SWF_VAR_FUNCTION;
  this->scriptFunction_startDeviceSignal.AddRef(this: &this->scriptFunction_startDeviceSignal);
  idSWFScriptObject::Set(this: gui->globals, name: "startDeviceSignal", value: &v32);
  idSWFScriptVar::Free(this: &v32);
  this->scriptFunction_endDeviceSignal.pThis = this;
  v34.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v34);
  v34.value.i = (int)&this->scriptFunction_endDeviceSignal;
  v34.type = SWF_VAR_FUNCTION;
  this->scriptFunction_endDeviceSignal.AddRef(this: &this->scriptFunction_endDeviceSignal);
  idSWFScriptObject::Set(this: gui->globals, name: "endDeviceSignal", value: &v34);
  idSWFScriptVar::Free(this: &v34);
  this->scriptFunction_setSaveLoadUpdate.pThis = this;
  v36.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v36);
  v36.value.i = (int)&this->scriptFunction_setSaveLoadUpdate;
  v36.type = SWF_VAR_FUNCTION;
  this->scriptFunction_setSaveLoadUpdate.AddRef(this: &this->scriptFunction_setSaveLoadUpdate);
  idSWFScriptObject::Set(this: gui->globals, name: "setSaveLoadUpdate", value: &v36);
  idSWFScriptVar::Free(this: &v36);
  this->scriptFunction_isEnumerating.pThis = this;
  v38.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v38);
  v38.value.i = (int)&this->scriptFunction_isEnumerating;
  v38.type = SWF_VAR_FUNCTION;
  this->scriptFunction_isEnumerating.AddRef(this: &this->scriptFunction_isEnumerating);
  idSWFScriptObject::Set(this: gui->globals, name: "isEnumerating", value: &v38);
  idSWFScriptVar::Free(this: &v38);
  this->scriptFunction_continueGame.pThis = this;
  v40.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v40);
  v40.value.i = (int)&this->scriptFunction_continueGame;
  v40.type = SWF_VAR_FUNCTION;
  this->scriptFunction_continueGame.AddRef(this: &this->scriptFunction_continueGame);
  idSWFScriptObject::Set(this: gui->globals, name: "continueGame", value: &v40);
  idSWFScriptVar::Free(this: &v40);
  this->scriptFunction_continueFromMostRecentSave.pThis = this;
  v42.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v42);
  v42.value.i = (int)&this->scriptFunction_continueFromMostRecentSave;
  v42.type = SWF_VAR_FUNCTION;
  this->scriptFunction_continueFromMostRecentSave.AddRef(this: &this->scriptFunction_continueFromMostRecentSave);
  idSWFScriptObject::Set(this: gui->globals, name: "continueFromMostRecentSave", value: &v42);
  idSWFScriptVar::Free(this: &v42);
  this->scriptFunction_loadDamagedFile.pThis = this;
  v44.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v44);
  v44.value.i = (int)&this->scriptFunction_loadDamagedFile;
  v44.type = SWF_VAR_FUNCTION;
  this->scriptFunction_loadDamagedFile.AddRef(this: &this->scriptFunction_loadDamagedFile);
  idSWFScriptObject::Set(this: gui->globals, name: "loadDamagedFile", value: &v44);
  idSWFScriptVar::Free(this: &v44);
  this->scriptFunction_saveSettings.pThis = this;
  v46.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v46);
  v46.value.i = (int)&this->scriptFunction_saveSettings;
  v46.type = SWF_VAR_FUNCTION;
  this->scriptFunction_saveSettings.AddRef(this: &this->scriptFunction_saveSettings);
  idSWFScriptObject::Set(this: gui->globals, name: "saveSettings", value: &v46);
  idSWFScriptVar::Free(this: &v46);
  this->scriptFunction_setBindingWait.pThis = this;
  v48.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v48);
  v48.type = SWF_VAR_FUNCTION;
  v48.value.i = (int)&this->scriptFunction_setBindingWait;
  this->scriptFunction_setBindingWait.AddRef(this: &this->scriptFunction_setBindingWait);
  idSWFScriptObject::Set(this: gui->globals, name: "setBindingWait", value: &v48);
  idSWFScriptVar::Free(this: &v48);
  this->scriptFunction_isLookInverted.pThis = this;
  v50.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v50);
  v50.value.i = (int)&this->scriptFunction_isLookInverted;
  v50.type = SWF_VAR_FUNCTION;
  this->scriptFunction_isLookInverted.AddRef(this: &this->scriptFunction_isLookInverted);
  idSWFScriptObject::Set(this: gui->globals, name: "isLookInverted", value: &v50);
  idSWFScriptVar::Free(this: &v50);
  this->scriptFunction_invertLook.pThis = this;
  v52.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v52);
  v52.value.i = (int)&this->scriptFunction_invertLook;
  v52.type = SWF_VAR_FUNCTION;
  this->scriptFunction_invertLook.AddRef(this: &this->scriptFunction_invertLook);
  idSWFScriptObject::Set(this: gui->globals, name: "invertLook", value: &v52);
  idSWFScriptVar::Free(this: &v52);
  this->scriptFunction_updateSafeFrameScale.pThis = this;
  v54.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v54);
  v54.value.i = (int)&this->scriptFunction_updateSafeFrameScale;
  v54.type = SWF_VAR_FUNCTION;
  this->scriptFunction_updateSafeFrameScale.AddRef(this: &this->scriptFunction_updateSafeFrameScale);
  idSWFScriptObject::Set(this: gui->globals, name: "updateSafeFrameScale", value: &v54);
  idSWFScriptVar::Free(this: &v54);
  this->scriptFunction_GetSafeFrameScale.pThis = this;
  v56.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v56);
  v56.value.i = (int)&this->scriptFunction_GetSafeFrameScale;
  v56.type = SWF_VAR_FUNCTION;
  this->scriptFunction_GetSafeFrameScale.AddRef(this: &this->scriptFunction_GetSafeFrameScale);
  idSWFScriptObject::Set(this: gui->globals, name: "GetSafeFrameScale", value: &v56);
  idSWFScriptVar::Free(this: &v56);
  this->scriptFunction_updateGammaValue.pThis = this;
  v58.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v58);
  v58.value.i = (int)&this->scriptFunction_updateGammaValue;
  v58.type = SWF_VAR_FUNCTION;
  this->scriptFunction_updateGammaValue.AddRef(this: &this->scriptFunction_updateGammaValue);
  idSWFScriptObject::Set(this: gui->globals, name: "updateGammaValue", value: &v58);
  idSWFScriptVar::Free(this: &v58);
  this->scriptFunction_getGammaValue.pThis = this;
  v60.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v60);
  v60.value.i = (int)&this->scriptFunction_getGammaValue;
  v60.type = SWF_VAR_FUNCTION;
  this->scriptFunction_getGammaValue.AddRef(this: &this->scriptFunction_getGammaValue);
  idSWFScriptObject::Set(this: gui->globals, name: "getGammaValue", value: &v60);
  idSWFScriptVar::Free(this: &v60);
  this->scriptFunction_setInvertLook.pThis = this;
  v62.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v62);
  v62.value.i = (int)&this->scriptFunction_setInvertLook;
  v62.type = SWF_VAR_FUNCTION;
  this->scriptFunction_setInvertLook.AddRef(this: &this->scriptFunction_setInvertLook);
  idSWFScriptObject::Set(this: gui->globals, name: "setInvertLook", value: &v62);
  idSWFScriptVar::Free(this: &v62);
  this->scriptFunction_subtitlesEnabled.pThis = this;
  v64.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v64);
  v64.value.i = (int)&this->scriptFunction_subtitlesEnabled;
  v64.type = SWF_VAR_FUNCTION;
  this->scriptFunction_subtitlesEnabled.AddRef(this: &this->scriptFunction_subtitlesEnabled);
  idSWFScriptObject::Set(this: gui->globals, name: "subtitlesEnabled", value: &v64);
  idSWFScriptVar::Free(this: &v64);
  this->scriptFunction_setSubtitlesEnabled.pThis = this;
  v66.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v66);
  v66.value.i = (int)&this->scriptFunction_setSubtitlesEnabled;
  v66.type = SWF_VAR_FUNCTION;
  this->scriptFunction_setSubtitlesEnabled.AddRef(this: &this->scriptFunction_setSubtitlesEnabled);
  idSWFScriptObject::Set(this: gui->globals, name: "setSubtitlesEnabled", value: &v66);
  idSWFScriptVar::Free(this: &v66);
  this->scriptFunction_calculateBenchmark.pThis = this;
  v68.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v68);
  v68.value.i = (int)&this->scriptFunction_calculateBenchmark;
  v68.type = SWF_VAR_FUNCTION;
  this->scriptFunction_calculateBenchmark.AddRef(this: &this->scriptFunction_calculateBenchmark);
  idSWFScriptObject::Set(this: gui->globals, name: "calculateBenchmark", value: &v68);
  idSWFScriptVar::Free(this: &v68);
  this->scriptFunction_getBenchmarkValue.pThis = this;
  v70.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v70);
  v70.value.i = (int)&this->scriptFunction_getBenchmarkValue;
  v70.type = SWF_VAR_FUNCTION;
  this->scriptFunction_getBenchmarkValue.AddRef(this: &this->scriptFunction_getBenchmarkValue);
  idSWFScriptObject::Set(this: gui->globals, name: "getBenchmarkValue", value: &v70);
  idSWFScriptVar::Free(this: &v70);
  this->scriptFunction_setAudioVolume.pThis = this;
  v72.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v72);
  v72.value.i = (int)&this->scriptFunction_setAudioVolume;
  v72.type = SWF_VAR_FUNCTION;
  this->scriptFunction_setAudioVolume.AddRef(this: &this->scriptFunction_setAudioVolume);
  idSWFScriptObject::Set(this: gui->globals, name: "setAudioVolume", value: &v72);
  idSWFScriptVar::Free(this: &v72);
  this->scriptFunction_getAudioVolume.pThis = this;
  v74.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v74);
  v74.value.i = (int)&this->scriptFunction_getAudioVolume;
  v74.type = SWF_VAR_FUNCTION;
  this->scriptFunction_getAudioVolume.AddRef(this: &this->scriptFunction_getAudioVolume);
  idSWFScriptObject::Set(this: gui->globals, name: "getAudioVolume", value: &v74);
  idSWFScriptVar::Free(this: &v74);
  this->scriptFunction_updateJoyYawSpeed.pThis = this;
  v76.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v76);
  v76.value.i = (int)&this->scriptFunction_updateJoyYawSpeed;
  v76.type = SWF_VAR_FUNCTION;
  this->scriptFunction_updateJoyYawSpeed.AddRef(this: &this->scriptFunction_updateJoyYawSpeed);
  idSWFScriptObject::Set(this: gui->globals, name: "updateJoyYawSpeed", value: &v76);
  idSWFScriptVar::Free(this: &v76);
  this->scriptFunction_GetJoyYawSpeed.pThis = this;
  v78.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v78);
  v78.value.i = (int)&this->scriptFunction_GetJoyYawSpeed;
  v78.type = SWF_VAR_FUNCTION;
  this->scriptFunction_GetJoyYawSpeed.AddRef(this: &this->scriptFunction_GetJoyYawSpeed);
  idSWFScriptObject::Set(this: gui->globals, name: "GetJoyYawSpeed", value: &v78);
  idSWFScriptVar::Free(this: &v78);
  this->scriptFunction_updateJoyPitchSpeed.pThis = this;
  v80.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v80);
  v80.value.i = (int)&this->scriptFunction_updateJoyPitchSpeed;
  v80.type = SWF_VAR_FUNCTION;
  this->scriptFunction_updateJoyPitchSpeed.AddRef(this: &this->scriptFunction_updateJoyPitchSpeed);
  idSWFScriptObject::Set(this: gui->globals, name: "updateJoyPitchSpeed", value: &v80);
  idSWFScriptVar::Free(this: &v80);
  this->scriptFunction_GetJoyPitchSpeed.pThis = this;
  v82.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v82);
  v82.value.i = (int)&this->scriptFunction_GetJoyPitchSpeed;
  v82.type = SWF_VAR_FUNCTION;
  this->scriptFunction_GetJoyPitchSpeed.AddRef(this: &this->scriptFunction_GetJoyPitchSpeed);
  idSWFScriptObject::Set(this: gui->globals, name: "GetJoyPitchSpeed", value: &v82);
  idSWFScriptVar::Free(this: &v82);
  this->scriptFunction_getBinding.pThis = this;
  v84.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v84);
  v84.value.i = (int)&this->scriptFunction_getBinding;
  v84.type = SWF_VAR_FUNCTION;
  this->scriptFunction_getBinding.AddRef(this: &this->scriptFunction_getBinding);
  idSWFScriptObject::Set(this: gui->globals, name: "getBinding", value: &v84);
  idSWFScriptVar::Free(this: &v84);
  this->scriptFunction_confirmRestoreBindings.pThis = this;
  v86.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v86);
  v86.value.i = (int)&this->scriptFunction_confirmRestoreBindings;
  v86.type = SWF_VAR_FUNCTION;
  this->scriptFunction_confirmRestoreBindings.AddRef(this: &this->scriptFunction_confirmRestoreBindings);
  idSWFScriptObject::Set(this: gui->globals, name: "confirmRestoreBindings", value: &v86);
  idSWFScriptVar::Free(this: &v86);
  this->scriptFunction_getGamepadEnabled.pThis = this;
  v88.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v88);
  v88.value.i = (int)&this->scriptFunction_getGamepadEnabled;
  v88.type = SWF_VAR_FUNCTION;
  this->scriptFunction_getGamepadEnabled.AddRef(this: &this->scriptFunction_getGamepadEnabled);
  idSWFScriptObject::Set(this: gui->globals, name: "getGamepadEnabled", value: &v88);
  idSWFScriptVar::Free(this: &v88);
  this->scriptFunction_setGamepadEnabled.pThis = this;
  v90.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v90);
  v90.value.i = (int)&this->scriptFunction_setGamepadEnabled;
  v90.type = SWF_VAR_FUNCTION;
  this->scriptFunction_setGamepadEnabled.AddRef(this: &this->scriptFunction_setGamepadEnabled);
  idSWFScriptObject::Set(this: gui->globals, name: "setGamepadEnabled", value: &v90);
  idSWFScriptVar::Free(this: &v90);
  this->scriptFunction_getUseAimAssist.pThis = this;
  v94.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v94);
  v94.value.i = (int)&this->scriptFunction_getUseAimAssist;
  v94.type = SWF_VAR_FUNCTION;
  this->scriptFunction_getUseAimAssist.AddRef(this: &this->scriptFunction_getUseAimAssist);
  idSWFScriptObject::Set(this: gui->globals, name: "getUseAimAssist", value: &v94);
  idSWFScriptVar::Free(this: &v94);
  this->scriptFunction_setUseAimAssist.pThis = this;
  v96.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v96);
  v96.value.i = (int)&this->scriptFunction_setUseAimAssist;
  v96.type = SWF_VAR_FUNCTION;
  this->scriptFunction_setUseAimAssist.AddRef(this: &this->scriptFunction_setUseAimAssist);
  idSWFScriptObject::Set(this: gui->globals, name: "setUseAimAssist", value: &v96);
  idSWFScriptVar::Free(this: &v96);
  this->scriptFunction_setUseVibrate.pThis = this;
  v98.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v98);
  v98.value.i = (int)&this->scriptFunction_setUseVibrate;
  v98.type = SWF_VAR_FUNCTION;
  this->scriptFunction_setUseVibrate.AddRef(this: &this->scriptFunction_setUseVibrate);
  idSWFScriptObject::Set(this: gui->globals, name: "setUseVibrate", value: &v98);
  idSWFScriptVar::Free(this: &v98);
  this->scriptFunction_getUseVibrate.pThis = this;
  v100.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v100);
  v100.value.i = (int)&this->scriptFunction_getUseVibrate;
  v100.type = SWF_VAR_FUNCTION;
  this->scriptFunction_getUseVibrate.AddRef(this: &this->scriptFunction_getUseVibrate);
  idSWFScriptObject::Set(this: gui->globals, name: "getUseVibrate", value: &v100);
  idSWFScriptVar::Free(this: &v100);
  this->scriptFunction_setMouseSensitivity.pThis = this;
  v102.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v102);
  v102.value.i = (int)&this->scriptFunction_setMouseSensitivity;
  v102.type = SWF_VAR_FUNCTION;
  this->scriptFunction_setMouseSensitivity.AddRef(this: &this->scriptFunction_setMouseSensitivity);
  idSWFScriptObject::Set(this: gui->globals, name: "setMouseSensitivity", value: &v102);
  idSWFScriptVar::Free(this: &v102);
  this->scriptFunction_getMouseSensitivity.pThis = this;
  v104.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v104);
  v104.value.i = (int)&this->scriptFunction_getMouseSensitivity;
  v104.type = SWF_VAR_FUNCTION;
  this->scriptFunction_getMouseSensitivity.AddRef(this: &this->scriptFunction_getMouseSensitivity);
  idSWFScriptObject::Set(this: gui->globals, name: "getMouseSensitivity", value: &v104);
  idSWFScriptVar::Free(this: &v104);
  this->scriptFunction_getConfig.pThis = this;
  v106.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v106);
  v106.value.i = (int)&this->scriptFunction_getConfig;
  v106.type = SWF_VAR_FUNCTION;
  this->scriptFunction_getConfig.AddRef(this: &this->scriptFunction_getConfig);
  idSWFScriptObject::Set(this: gui->globals, name: "getConfig", value: &v106);
  idSWFScriptVar::Free(this: &v106);
  this->scriptFunction_setConfig.pThis = this;
  v108.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v108);
  v108.value.i = (int)&this->scriptFunction_setConfig;
  v108.type = SWF_VAR_FUNCTION;
  this->scriptFunction_setConfig.AddRef(this: &this->scriptFunction_setConfig);
  idSWFScriptObject::Set(this: gui->globals, name: "setConfig", value: &v108);
  idSWFScriptVar::Free(this: &v108);
  this->scriptFunction_changeConfig.pThis = this;
  v110.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v110);
  v110.value.i = (int)&this->scriptFunction_changeConfig;
  v110.type = SWF_VAR_FUNCTION;
  this->scriptFunction_changeConfig.AddRef(this: &this->scriptFunction_changeConfig);
  idSWFScriptObject::Set(this: gui->globals, name: "changeConfig", value: &v110);
  idSWFScriptVar::Free(this: &v110);
  this->scriptFunction_getConfigText.pThis = this;
  v112.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v112);
  v112.value.i = (int)&this->scriptFunction_getConfigText;
  v112.type = SWF_VAR_FUNCTION;
  this->scriptFunction_getConfigText.AddRef(this: &this->scriptFunction_getConfigText);
  idSWFScriptObject::Set(this: gui->globals, name: "getConfigText", value: &v112);
  idSWFScriptVar::Free(this: &v112);
  this->scriptFunction_hidePauseMenu.pThis = this;
  v114.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v114);
  v114.value.i = (int)&this->scriptFunction_hidePauseMenu;
  v114.type = SWF_VAR_FUNCTION;
  this->scriptFunction_hidePauseMenu.AddRef(this: &this->scriptFunction_hidePauseMenu);
  idSWFScriptObject::Set(this: gui->globals, name: "hidePauseMenu", value: &v114);
  idSWFScriptVar::Free(this: &v114);
  this->scriptFunction_stopPlaytestRenderDemoRecord.pThis = this;
  v116.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v116);
  v10 = this->scriptFunction_stopPlaytestRenderDemoRecord.__vftable;
  v116.value.i = (int)&this->scriptFunction_stopPlaytestRenderDemoRecord;
  v116.type = SWF_VAR_FUNCTION;
  v10->AddRef(this: &this->scriptFunction_stopPlaytestRenderDemoRecord);
  idSWFScriptObject::Set(this: gui->globals, name: "stopPlaytestRenderDemoRecord", value: &v116);
  idSWFScriptVar::Free(this: &v116);
  this->scriptFunction_setPlaytestSessionName.pThis = this;
  v118.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v118);
  v118.value.i = (int)&this->scriptFunction_setPlaytestSessionName;
  v118.type = SWF_VAR_FUNCTION;
  this->scriptFunction_setPlaytestSessionName.AddRef(this: &this->scriptFunction_setPlaytestSessionName);
  idSWFScriptObject::Set(this: gui->globals, name: "setPlaytestSessionName", value: &v118);
  idSWFScriptVar::Free(this: &v118);
  this->scriptFunction_checkActivatePlaytestLogging.pThis = this;
  v120.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v120);
  v120.value.i = (int)&this->scriptFunction_checkActivatePlaytestLogging;
  v120.type = SWF_VAR_FUNCTION;
  this->scriptFunction_checkActivatePlaytestLogging.AddRef(this: &this->scriptFunction_checkActivatePlaytestLogging);
  idSWFScriptObject::Set(this: gui->globals, name: "checkActivatePlaytestLogging", value: &v120);
  idSWFScriptVar::Free(this: &v120);
  this->scriptFunction_checkActivateRenderDemo.pThis = this;
  v122.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v122);
  v122.value.i = (int)&this->scriptFunction_checkActivateRenderDemo;
  v122.type = SWF_VAR_FUNCTION;
  this->scriptFunction_checkActivateRenderDemo.AddRef(this: &this->scriptFunction_checkActivateRenderDemo);
  idSWFScriptObject::Set(this: gui->globals, name: "checkActivateRenderDemo", value: &v122);
  idSWFScriptVar::Free(this: &v122);
  this->scriptFunction_loadDevMenuOption.pThis = this;
  v124.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v124);
  v124.value.i = (int)&this->scriptFunction_loadDevMenuOption;
  v124.type = SWF_VAR_FUNCTION;
  this->scriptFunction_loadDevMenuOption.AddRef(this: &this->scriptFunction_loadDevMenuOption);
  idSWFScriptObject::Set(this: gui->globals, name: "loadDevMenuOption", value: &v124);
  idSWFScriptVar::Free(this: &v124);
  this->scriptFunction_showCredits.pThis = this;
  v126.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v126);
  v126.value.i = (int)&this->scriptFunction_showCredits;
  v126.type = SWF_VAR_FUNCTION;
  this->scriptFunction_showCredits.AddRef(this: &this->scriptFunction_showCredits);
  idSWFScriptObject::Set(this: gui->globals, name: "showCredits", value: &v126);
  idSWFScriptVar::Free(this: &v126);
  this->scriptFunction_ps3ShowFriends.pThis = this;
  v128.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v128);
  v128.value.i = (int)&this->scriptFunction_ps3ShowFriends;
  v128.type = SWF_VAR_FUNCTION;
  this->scriptFunction_ps3ShowFriends.AddRef(this: &this->scriptFunction_ps3ShowFriends);
  idSWFScriptObject::Set(this: gui->globals, name: "ps3ShowFriends", value: &v128);
  idSWFScriptVar::Free(this: &v128);
  this->scriptFunction_ps3ShowNotifications.pThis = this;
  v130.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v130);
  v130.value.i = (int)&this->scriptFunction_ps3ShowNotifications;
  v130.type = SWF_VAR_FUNCTION;
  this->scriptFunction_ps3ShowNotifications.AddRef(this: &this->scriptFunction_ps3ShowNotifications);
  idSWFScriptObject::Set(this: gui->globals, name: "ps3ShowNotifications", value: &v130);
  idSWFScriptVar::Free(this: &v130);
  this->scriptFunction_ps3CheckInvites.pThis = this;
  v132.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v132);
  v132.value.i = (int)&this->scriptFunction_ps3CheckInvites;
  v132.type = SWF_VAR_FUNCTION;
  this->scriptFunction_ps3CheckInvites.AddRef(this: &this->scriptFunction_ps3CheckInvites);
  idSWFScriptObject::Set(this: gui->globals, name: "ps3CheckInvites", value: &v132);
  idSWFScriptVar::Free(this: &v132);
  this->scriptFunction_hasContentPack.pThis = this;
  v134.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v134);
  v134.value.i = (int)&this->scriptFunction_hasContentPack;
  v134.type = SWF_VAR_FUNCTION;
  this->scriptFunction_hasContentPack.AddRef(this: &this->scriptFunction_hasContentPack);
  idSWFScriptObject::Set(this: gui->globals, name: "hasContentPack", value: &v134);
  idSWFScriptVar::Free(this: &v134);
  this->scriptFunction_isDemoMode.pThis = this;
  v136.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v136);
  v136.value.i = (int)&this->scriptFunction_isDemoMode;
  v136.type = SWF_VAR_FUNCTION;
  this->scriptFunction_isDemoMode.AddRef(this: &this->scriptFunction_isDemoMode);
  idSWFScriptObject::Set(this: gui->globals, name: "isDemoMode", value: &v136);
  idSWFScriptVar::Free(this: &v136);
  this->scriptFunction_showDLCOption.pThis = this;
  v138.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v138);
  v11 = this->scriptFunction_showDLCOption.__vftable;
  v138.value.i = (int)&this->scriptFunction_showDLCOption;
  v138.type = SWF_VAR_FUNCTION;
  v11->AddRef(this: &this->scriptFunction_showDLCOption);
  idSWFScriptObject::Set(this: gui->globals, name: "showDLCOption", value: &v138);
  idSWFScriptVar::Free(this: &v138);
  this->scriptFunction_isGameInstalled.pThis = this;
  v140.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v140);
  v140.value.i = (int)&this->scriptFunction_isGameInstalled;
  v140.type = SWF_VAR_FUNCTION;
  this->scriptFunction_isGameInstalled.AddRef(this: &this->scriptFunction_isGameInstalled);
  idSWFScriptObject::Set(this: gui->globals, name: "isGameInstalled", value: &v140);
  idSWFScriptVar::Free(this: &v140);
  this->scriptFunction_hasNewDLC.pThis = this;
  v142.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v142);
  v142.value.i = (int)&this->scriptFunction_hasNewDLC;
  v142.type = SWF_VAR_FUNCTION;
  this->scriptFunction_hasNewDLC.AddRef(this: &this->scriptFunction_hasNewDLC);
  idSWFScriptObject::Set(this: gui->globals, name: "hasNewDLC", value: &v142);
  idSWFScriptVar::Free(this: &v142);
  this->scriptFunction_showDLCMenu.pThis = this;
  v144.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v144);
  v144.value.i = (int)&this->scriptFunction_showDLCMenu;
  v144.type = SWF_VAR_FUNCTION;
  this->scriptFunction_showDLCMenu.AddRef(this: &this->scriptFunction_showDLCMenu);
  idSWFScriptObject::Set(this: gui->globals, name: "showDLCMenu", value: &v144);
  idSWFScriptVar::Free(this: &v144);
  this->scriptFunction_isMpHandsOnDemo.pThis = this;
  v146.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v146);
  v146.value.i = (int)&this->scriptFunction_isMpHandsOnDemo;
  v146.type = SWF_VAR_FUNCTION;
  this->scriptFunction_isMpHandsOnDemo.AddRef(this: &this->scriptFunction_isMpHandsOnDemo);
  idSWFScriptObject::Set(this: gui->globals, name: "isMpHandsOnDemo", value: &v146);
  idSWFScriptVar::Free(this: &v146);
  v12 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
          size: 0xCu,
          tag: TAG_SWF,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  v13.i = (int)v12;
  v161 = v12;
  if ( v12 != nullptr )
  {
    v12[1] = 0;
    *v12 = `idMainMenu::SetupBindings'::`7'::idSWFScriptFunction_GetKeyBindings::`vftable';
    v12[2] = idSWFScriptObject::Alloc();
  }
  else
  {
    v13.i = 0;
  }
  v18.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v18);
  if ( v13.i != 0 )
  {
    v18.value = v13;
    v18.type = SWF_VAR_FUNCTION;
    (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v13.i + 8))(a1: v13.i);
  }
  else
  {
    v18.type = SWF_VAR_NULL;
  }
  idSWFScriptObject::Set(this: gui->globals, name: "getBindingPC", value: &v18);
  idSWFScriptVar::Free(this: &v18);
  v14 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
          size: 0x10u,
          tag: TAG_SWF,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  if ( v14 != nullptr )
  {
    v14[2] = gui;
    v14[3] = this;
    v15.i = (int)v14;
    v14[1] = 0;
    *v14 = &`idMainMenu::SetupBindings'::`8'::idSWFScriptFunction_updateMenuDisplay::`vftable';
  }
  else
  {
    v15.i = 0;
  }
  v20.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v20);
  if ( v15.i != 0 )
  {
    v20.value = v15;
    v20.type = SWF_VAR_FUNCTION;
    (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v15.i + 8))(a1: v15.i);
  }
  else
  {
    v20.type = SWF_VAR_NULL;
  }
  idSWFScriptObject::Set(this: gui->globals, name: "updateMenuDisplay", value: &v20);
  idSWFScriptVar::Free(this: &v20);
  v16 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
          size: 0x10u,
          tag: TAG_SWF,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  if ( v16 != nullptr )
  {
    v16[2] = gui;
    v16[3] = this;
    v17.i = (int)v16;
    v16[1] = 0;
    *v16 = &`idMainMenu::SetupBindings'::`9'::idSWFScriptFunction_updateMenuCmds::`vftable';
  }
  else
  {
    v17.i = 0;
  }
  v19.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v19);
  if ( v17.i != 0 )
  {
    v19.value = v17;
    v19.type = SWF_VAR_FUNCTION;
    (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v17.i + 8))(a1: v17.i);
  }
  else
  {
    v19.type = SWF_VAR_NULL;
  }
  idSWFScriptObject::Set(this: gui->globals, name: "updateMenuCmds", value: &v19);
  idSWFScriptVar::Free(this: &v19);
  v148.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v148);
  v148.type = SWF_VAR_INTEGER;
  v148.value.i = -1;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_AREA_INVALID", value: &v148);
  idSWFScriptVar::Free(this: &v148);
  v150.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v150);
  v150.type = SWF_VAR_INTEGER;
  v150.value.i = 0;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_START", value: &v150);
  idSWFScriptVar::Free(this: &v150);
  v152.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v152);
  v152.type = SWF_VAR_INTEGER;
  v152.value.i = 1;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_ROOT", value: &v152);
  idSWFScriptVar::Free(this: &v152);
  v154.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v154);
  v154.type = SWF_VAR_INTEGER;
  v154.value.i = 2;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_DEV", value: &v154);
  idSWFScriptVar::Free(this: &v154);
  v156.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v156);
  v156.type = SWF_VAR_INTEGER;
  v156.value.i = 3;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_CAMPAIGN", value: &v156);
  idSWFScriptVar::Free(this: &v156);
  v158.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v158);
  v158.type = SWF_VAR_INTEGER;
  v158.value.i = 4;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_MULTIPLAYER", value: &v158);
  idSWFScriptVar::Free(this: &v158);
  v160.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v160);
  v160.type = SWF_VAR_INTEGER;
  v160.value.i = 5;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_SETTINGS", value: &v160);
  idSWFScriptVar::Free(this: &v160);
  v143.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v143);
  v143.type = SWF_VAR_INTEGER;
  v143.value.i = 6;
  idSWFScriptObject::Set(this: gui->globals, name: "MENU_AUDIO", value: &v143);
  idSWFScriptVar::Free(this: &v143);
  idMainMenu::SetupMPMenuBindings(this, gui);
}


// ========================================================================
// __unwind$527390
// EA  : 0x82DAB420
// RVA : 0x00DAB420
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527390()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 120));
}


// ========================================================================
// __unwind$527391
// EA  : 0x82DAB448
// RVA : 0x00DAB448
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527391()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 680));
}


// ========================================================================
// __unwind$527392
// EA  : 0x82DAB470
// RVA : 0x00DAB470
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527392()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 136));
}


// ========================================================================
// __unwind$527393
// EA  : 0x82DAB498
// RVA : 0x00DAB498
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527393()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 952));
}


// ========================================================================
// __unwind$527394
// EA  : 0x82DAB4C0
// RVA : 0x00DAB4C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527394()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 152));
}


// ========================================================================
// __unwind$527395
// EA  : 0x82DAB4E8
// RVA : 0x00DAB4E8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527395()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 696));
}


// ========================================================================
// __unwind$527396
// EA  : 0x82DAB510
// RVA : 0x00DAB510
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527396()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 168));
}


// ========================================================================
// __unwind$527397
// EA  : 0x82DAB538
// RVA : 0x00DAB538
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527397()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1208));
}


// ========================================================================
// __unwind$527398
// EA  : 0x82DAB560
// RVA : 0x00DAB560
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527398()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 184));
}


// ========================================================================
// __unwind$527399
// EA  : 0x82DAB588
// RVA : 0x00DAB588
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527399()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 712));
}


// ========================================================================
// __unwind$527400
// EA  : 0x82DAB5B0
// RVA : 0x00DAB5B0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527400()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 200));
}


// ========================================================================
// __unwind$527401
// EA  : 0x82DAB5D8
// RVA : 0x00DAB5D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527401()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 968));
}


// ========================================================================
// __unwind$527402
// EA  : 0x82DAB600
// RVA : 0x00DAB600
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527402()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 216));
}


// ========================================================================
// __unwind$527403
// EA  : 0x82DAB628
// RVA : 0x00DAB628
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527403()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 728));
}


// ========================================================================
// __unwind$527404
// EA  : 0x82DAB650
// RVA : 0x00DAB650
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527404()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 232));
}


// ========================================================================
// __unwind$527405
// EA  : 0x82DAB678
// RVA : 0x00DAB678
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527405()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1096));
}


// ========================================================================
// __unwind$527406
// EA  : 0x82DAB6A0
// RVA : 0x00DAB6A0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527406()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 248));
}


// ========================================================================
// __unwind$527407
// EA  : 0x82DAB6C8
// RVA : 0x00DAB6C8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527407()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 744));
}


// ========================================================================
// __unwind$527806
// EA  : 0x82DAB6F0
// RVA : 0x00DAB6F0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527806()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1392 + 1232));
}


// ========================================================================
// __unwind$527408
// EA  : 0x82DAB718
// RVA : 0x00DAB718
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527408()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 264));
}


// ========================================================================
// __unwind$527409
// EA  : 0x82DAB740
// RVA : 0x00DAB740
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527409()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 984));
}


// ========================================================================
// __unwind$527410
// EA  : 0x82DAB768
// RVA : 0x00DAB768
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527410()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 280));
}


// ========================================================================
// __unwind$527411
// EA  : 0x82DAB790
// RVA : 0x00DAB790
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527411()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 760));
}


// ========================================================================
// __unwind$527412
// EA  : 0x82DAB7B8
// RVA : 0x00DAB7B8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527412()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 296));
}


// ========================================================================
// __unwind$527413
// EA  : 0x82DAB7E0
// RVA : 0x00DAB7E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527413()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1160));
}


// ========================================================================
// __unwind$527414
// EA  : 0x82DAB808
// RVA : 0x00DAB808
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527414()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 312));
}


// ========================================================================
// __unwind$527415
// EA  : 0x82DAB830
// RVA : 0x00DAB830
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527415()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 776));
}


// ========================================================================
// __unwind$527416
// EA  : 0x82DAB858
// RVA : 0x00DAB858
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527416()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 328));
}


// ========================================================================
// __unwind$527417
// EA  : 0x82DAB880
// RVA : 0x00DAB880
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527417()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1000));
}


// ========================================================================
// __unwind$527418
// EA  : 0x82DAB8A8
// RVA : 0x00DAB8A8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527418()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 344));
}


// ========================================================================
// __unwind$527419
// EA  : 0x82DAB8D0
// RVA : 0x00DAB8D0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527419()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 792));
}


// ========================================================================
// __unwind$527420
// EA  : 0x82DAB8F8
// RVA : 0x00DAB8F8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527420()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 360));
}


// ========================================================================
// __unwind$527421
// EA  : 0x82DAB920
// RVA : 0x00DAB920
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527421()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1112));
}


// ========================================================================
// __unwind$527422
// EA  : 0x82DAB948
// RVA : 0x00DAB948
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527422()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 376));
}


// ========================================================================
// __unwind$527423
// EA  : 0x82DAB970
// RVA : 0x00DAB970
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527423()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 808));
}


// ========================================================================
// __unwind$527424
// EA  : 0x82DAB998
// RVA : 0x00DAB998
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527424()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 392));
}


// ========================================================================
// __unwind$527425
// EA  : 0x82DAB9C0
// RVA : 0x00DAB9C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527425()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1016));
}


// ========================================================================
// __unwind$527426
// EA  : 0x82DAB9E8
// RVA : 0x00DAB9E8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527426()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 408));
}


// ========================================================================
// __unwind$527427
// EA  : 0x82DABA10
// RVA : 0x00DABA10
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527427()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 824));
}


// ========================================================================
// __unwind$527428
// EA  : 0x82DABA38
// RVA : 0x00DABA38
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527428()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 424));
}


// ========================================================================
// __unwind$527429
// EA  : 0x82DABA60
// RVA : 0x00DABA60
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527429()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1192));
}


// ========================================================================
// __unwind$527430
// EA  : 0x82DABA88
// RVA : 0x00DABA88
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527430()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 440));
}


// ========================================================================
// __unwind$527431
// EA  : 0x82DABAB0
// RVA : 0x00DABAB0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527431()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 840));
}


// ========================================================================
// __unwind$527432
// EA  : 0x82DABAD8
// RVA : 0x00DABAD8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527432()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 456));
}


// ========================================================================
// __unwind$527433
// EA  : 0x82DABB00
// RVA : 0x00DABB00
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527433()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1032));
}


// ========================================================================
// __unwind$527434
// EA  : 0x82DABB28
// RVA : 0x00DABB28
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527434()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 472));
}


// ========================================================================
// __unwind$527435
// EA  : 0x82DABB50
// RVA : 0x00DABB50
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527435()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 856));
}


// ========================================================================
// __unwind$527436
// EA  : 0x82DABB78
// RVA : 0x00DABB78
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527436()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 488));
}


// ========================================================================
// __unwind$527437_0
// EA  : 0x82DABBA0
// RVA : 0x00DABBA0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527437_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1128));
}


// ========================================================================
// __unwind$527438
// EA  : 0x82DABBC8
// RVA : 0x00DABBC8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527438()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 504));
}


// ========================================================================
// __unwind$527439
// EA  : 0x82DABBF0
// RVA : 0x00DABBF0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527439()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 872));
}


// ========================================================================
// __unwind$527440
// EA  : 0x82DABC18
// RVA : 0x00DABC18
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527440()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 520));
}


// ========================================================================
// __unwind$527441
// EA  : 0x82DABC40
// RVA : 0x00DABC40
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527441()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1048));
}


// ========================================================================
// __unwind$527442
// EA  : 0x82DABC68
// RVA : 0x00DABC68
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527442()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 536));
}


// ========================================================================
// __unwind$527443
// EA  : 0x82DABC90
// RVA : 0x00DABC90
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527443()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 888));
}


// ========================================================================
// __unwind$527444
// EA  : 0x82DABCB8
// RVA : 0x00DABCB8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527444()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 552));
}


// ========================================================================
// __unwind$527445
// EA  : 0x82DABCE0
// RVA : 0x00DABCE0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527445()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1176));
}


// ========================================================================
// __unwind$527446
// EA  : 0x82DABD08
// RVA : 0x00DABD08
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527446()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 568));
}


// ========================================================================
// __unwind$527447
// EA  : 0x82DABD30
// RVA : 0x00DABD30
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527447()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 904));
}


// ========================================================================
// __unwind$527448
// EA  : 0x82DABD58
// RVA : 0x00DABD58
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527448()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 584));
}


// ========================================================================
// __unwind$527449
// EA  : 0x82DABD80
// RVA : 0x00DABD80
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527449()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1064));
}


// ========================================================================
// __unwind$527450
// EA  : 0x82DABDA8
// RVA : 0x00DABDA8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527450()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 600));
}


// ========================================================================
// __unwind$527451_0
// EA  : 0x82DABDD0
// RVA : 0x00DABDD0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527451_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 920));
}


// ========================================================================
// __unwind$527452
// EA  : 0x82DABDF8
// RVA : 0x00DABDF8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527452()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 616));
}


// ========================================================================
// __unwind$527453
// EA  : 0x82DABE20
// RVA : 0x00DABE20
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527453()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1144));
}


// ========================================================================
// __unwind$527454
// EA  : 0x82DABE48
// RVA : 0x00DABE48
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527454()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 632));
}


// ========================================================================
// __unwind$527455
// EA  : 0x82DABE70
// RVA : 0x00DABE70
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527455()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 936));
}


// ========================================================================
// __unwind$527456
// EA  : 0x82DABE98
// RVA : 0x00DABE98
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527456()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 648));
}


// ========================================================================
// __unwind$527457
// EA  : 0x82DABEC0
// RVA : 0x00DABEC0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527457()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 664));
}


// ========================================================================
// __unwind$527458
// EA  : 0x82DABEE8
// RVA : 0x00DABEE8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527458()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 104));
}


// ========================================================================
// __unwind$527459
// EA  : 0x82DABF10
// RVA : 0x00DABF10
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527459()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 672));
}


// ========================================================================
// __unwind$527460
// EA  : 0x82DABF38
// RVA : 0x00DABF38
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527460()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 112));
}


// ========================================================================
// __unwind$527461
// EA  : 0x82DABF60
// RVA : 0x00DABF60
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527461()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 128));
}


// ========================================================================
// __unwind$527462
// EA  : 0x82DABF88
// RVA : 0x00DABF88
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527462()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 144));
}


// ========================================================================
// __unwind$527463
// EA  : 0x82DABFB0
// RVA : 0x00DABFB0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527463()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 160));
}


// ========================================================================
// __unwind$527464
// EA  : 0x82DABFD8
// RVA : 0x00DABFD8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527464()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 176));
}


// ========================================================================
// __unwind$527465
// EA  : 0x82DAC000
// RVA : 0x00DAC000
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527465()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 192));
}


// ========================================================================
// __unwind$527466
// EA  : 0x82DAC028
// RVA : 0x00DAC028
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527466()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 208));
}


// ========================================================================
// __unwind$527467
// EA  : 0x82DAC050
// RVA : 0x00DAC050
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527467()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 224));
}


// ========================================================================
// __unwind$527468
// EA  : 0x82DAC078
// RVA : 0x00DAC078
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527468()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 240));
}


// ========================================================================
// __unwind$527469
// EA  : 0x82DAC0A0
// RVA : 0x00DAC0A0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527469()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 256));
}


// ========================================================================
// __unwind$527470
// EA  : 0x82DAC0C8
// RVA : 0x00DAC0C8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527470()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 272));
}


// ========================================================================
// __unwind$527471
// EA  : 0x82DAC0F0
// RVA : 0x00DAC0F0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527471()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 288));
}


// ========================================================================
// __unwind$527472
// EA  : 0x82DAC118
// RVA : 0x00DAC118
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527472()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 304));
}


// ========================================================================
// __unwind$527473
// EA  : 0x82DAC140
// RVA : 0x00DAC140
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527473()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 320));
}


// ========================================================================
// __unwind$527474
// EA  : 0x82DAC168
// RVA : 0x00DAC168
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527474()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 336));
}


// ========================================================================
// __unwind$527475
// EA  : 0x82DAC190
// RVA : 0x00DAC190
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527475()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 352));
}


// ========================================================================
// __unwind$527476
// EA  : 0x82DAC1B8
// RVA : 0x00DAC1B8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527476()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 368));
}


// ========================================================================
// __unwind$527477
// EA  : 0x82DAC1E0
// RVA : 0x00DAC1E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527477()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 384));
}


// ========================================================================
// __unwind$527478
// EA  : 0x82DAC208
// RVA : 0x00DAC208
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527478()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 400));
}


// ========================================================================
// __unwind$527479
// EA  : 0x82DAC230
// RVA : 0x00DAC230
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527479()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 416));
}


// ========================================================================
// __unwind$527480
// EA  : 0x82DAC258
// RVA : 0x00DAC258
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527480()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 432));
}


// ========================================================================
// __unwind$527481
// EA  : 0x82DAC280
// RVA : 0x00DAC280
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527481()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 448));
}


// ========================================================================
// __unwind$527482
// EA  : 0x82DAC2A8
// RVA : 0x00DAC2A8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527482()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 464));
}


// ========================================================================
// __unwind$527483
// EA  : 0x82DAC2D0
// RVA : 0x00DAC2D0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527483()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 480));
}


// ========================================================================
// __unwind$527484
// EA  : 0x82DAC2F8
// RVA : 0x00DAC2F8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527484()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 496));
}


// ========================================================================
// __unwind$527485
// EA  : 0x82DAC320
// RVA : 0x00DAC320
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527485()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 512));
}


// ========================================================================
// __unwind$527486
// EA  : 0x82DAC348
// RVA : 0x00DAC348
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527486()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 528));
}


// ========================================================================
// __unwind$527487
// EA  : 0x82DAC370
// RVA : 0x00DAC370
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527487()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 544));
}


// ========================================================================
// __unwind$527488
// EA  : 0x82DAC398
// RVA : 0x00DAC398
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527488()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 560));
}


// ========================================================================
// __unwind$527489
// EA  : 0x82DAC3C0
// RVA : 0x00DAC3C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527489()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 576));
}


// ========================================================================
// __unwind$527490
// EA  : 0x82DAC3E8
// RVA : 0x00DAC3E8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527490()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 592));
}


// ========================================================================
// __unwind$527491
// EA  : 0x82DAC410
// RVA : 0x00DAC410
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527491()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 608));
}


// ========================================================================
// __unwind$527492
// EA  : 0x82DAC438
// RVA : 0x00DAC438
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527492()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 624));
}


// ========================================================================
// __unwind$527493
// EA  : 0x82DAC460
// RVA : 0x00DAC460
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527493()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 640));
}


// ========================================================================
// __unwind$527494
// EA  : 0x82DAC488
// RVA : 0x00DAC488
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527494()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 656));
}


// ========================================================================
// __unwind$527495
// EA  : 0x82DAC4B0
// RVA : 0x00DAC4B0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527495()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 688));
}


// ========================================================================
// __unwind$527496
// EA  : 0x82DAC4D8
// RVA : 0x00DAC4D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527496()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 704));
}


// ========================================================================
// __unwind$527497
// EA  : 0x82DAC500
// RVA : 0x00DAC500
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527497()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 720));
}


// ========================================================================
// __unwind$527498
// EA  : 0x82DAC528
// RVA : 0x00DAC528
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527498()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 736));
}


// ========================================================================
// __unwind$527499
// EA  : 0x82DAC550
// RVA : 0x00DAC550
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527499()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 752));
}


// ========================================================================
// __unwind$527500
// EA  : 0x82DAC578
// RVA : 0x00DAC578
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527500()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 768));
}


// ========================================================================
// __unwind$527501
// EA  : 0x82DAC5A0
// RVA : 0x00DAC5A0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527501()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 784));
}


// ========================================================================
// __unwind$527502
// EA  : 0x82DAC5C8
// RVA : 0x00DAC5C8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527502()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 800));
}


// ========================================================================
// __unwind$527503
// EA  : 0x82DAC5F0
// RVA : 0x00DAC5F0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527503()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 816));
}


// ========================================================================
// __unwind$527504
// EA  : 0x82DAC618
// RVA : 0x00DAC618
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527504()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 832));
}


// ========================================================================
// __unwind$527505
// EA  : 0x82DAC640
// RVA : 0x00DAC640
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527505()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 848));
}


// ========================================================================
// __unwind$527506
// EA  : 0x82DAC668
// RVA : 0x00DAC668
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527506()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 864));
}


// ========================================================================
// __unwind$527507
// EA  : 0x82DAC690
// RVA : 0x00DAC690
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527507()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 880));
}


// ========================================================================
// __unwind$527508
// EA  : 0x82DAC6B8
// RVA : 0x00DAC6B8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527508()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 896));
}


// ========================================================================
// __unwind$527509
// EA  : 0x82DAC6E0
// RVA : 0x00DAC6E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527509()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 912));
}


// ========================================================================
// __unwind$527510
// EA  : 0x82DAC708
// RVA : 0x00DAC708
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527510()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 928));
}


// ========================================================================
// __unwind$527511
// EA  : 0x82DAC730
// RVA : 0x00DAC730
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527511()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 944));
}


// ========================================================================
// __unwind$527512
// EA  : 0x82DAC758
// RVA : 0x00DAC758
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527512()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 960));
}


// ========================================================================
// __unwind$527513
// EA  : 0x82DAC780
// RVA : 0x00DAC780
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527513()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 976));
}


// ========================================================================
// __unwind$527514
// EA  : 0x82DAC7A8
// RVA : 0x00DAC7A8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527514()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 992));
}


// ========================================================================
// __unwind$527515
// EA  : 0x82DAC7D0
// RVA : 0x00DAC7D0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527515()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1008));
}


// ========================================================================
// __unwind$527516
// EA  : 0x82DAC7F8
// RVA : 0x00DAC7F8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527516()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1024));
}


// ========================================================================
// __unwind$527517
// EA  : 0x82DAC820
// RVA : 0x00DAC820
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527517()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1040));
}


// ========================================================================
// __unwind$527518
// EA  : 0x82DAC848
// RVA : 0x00DAC848
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527518()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1056));
}


// ========================================================================
// __unwind$527519
// EA  : 0x82DAC870
// RVA : 0x00DAC870
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527519()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1072));
}


// ========================================================================
// __unwind$527520
// EA  : 0x82DAC898
// RVA : 0x00DAC898
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527520()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1088));
}


// ========================================================================
// __unwind$527521
// EA  : 0x82DAC8C0
// RVA : 0x00DAC8C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527521()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1104));
}


// ========================================================================
// __unwind$527522
// EA  : 0x82DAC8E8
// RVA : 0x00DAC8E8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527522()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1392 + 1224), tag: TAG_SWF);
}


// ========================================================================
// __unwind$530173
// EA  : 0x82DAC914
// RVA : 0x00DAC914
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_530173()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: *(idSWFScriptFunction_RefCounted **)(v0 - 1392 + 1224));
}


// ========================================================================
// __unwind$527523
// EA  : 0x82DAC93C
// RVA : 0x00DAC93C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527523()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 80));
}


// ========================================================================
// __unwind$527525
// EA  : 0x82DAC964
// RVA : 0x00DAC964
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527525()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 96));
}


// ========================================================================
// __unwind$527527
// EA  : 0x82DAC98C
// RVA : 0x00DAC98C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527527()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 88));
}


// ========================================================================
// __unwind$527528
// EA  : 0x82DAC9B4
// RVA : 0x00DAC9B4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527528()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1120));
}


// ========================================================================
// __unwind$527529
// EA  : 0x82DAC9DC
// RVA : 0x00DAC9DC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527529()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1136));
}


// ========================================================================
// __unwind$527530
// EA  : 0x82DACA04
// RVA : 0x00DACA04
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527530()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1152));
}


// ========================================================================
// __unwind$527531
// EA  : 0x82DACA2C
// RVA : 0x00DACA2C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527531()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1168));
}


// ========================================================================
// __unwind$527532
// EA  : 0x82DACA54
// RVA : 0x00DACA54
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527532()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1184));
}


// ========================================================================
// __unwind$527533
// EA  : 0x82DACA7C
// RVA : 0x00DACA7C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527533()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1200));
}


// ========================================================================
// __unwind$527534
// EA  : 0x82DACAA4
// RVA : 0x00DACAA4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527534()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1216));
}


// ========================================================================
// __unwind$527535
// EA  : 0x82DACACC
// RVA : 0x00DACACC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_527535()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1392 + 1080));
}


// ========================================================================
// `idMainMenu::SetupBindings'::`7'::idSWFScriptFunction_GetKeyBindings::Call
// EA  : 0x82DACB00
// RVA : 0x00DACB00
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::SetupBindings_::_7_::idSWFScriptFunction_GetKeyBindings::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        __int64 parms,
        __int64 a4,
        __int64 a5)
{
  idSWFScriptVar **v6; // r28
  bindSet_t v9; // r28
  char *data; // r27
  int v11; // r3
  idSWFScriptVar v12; // [sp+58h] [-C8h] BYREF
  idSWFScriptVar v13; // [sp+60h] [-C0h] BYREF
  idSWFScriptVar v14; // [sp+68h] [-B8h] BYREF
  idStr v15; // [sp+70h] [-B0h] BYREF
  testReportField_t v16; // [sp+90h] [-90h] BYREF

  v6 = (idSWFScriptVar **)parms;
  if ( *(_DWORD *)(parms + 4) == 2 )
  {
    idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v15, result: *(idStr **)parms, a3: parms, a4, a5);
    v9 = idSWFScriptVar::ToInteger(this: *v6 + 1);
    data = v15.data;
    v11 = common->GetFocusDeviceNum(this: common);
    idKeyInput::KeyBindingsFromBinding(result: (keyBindings_t *)&v16, numDevice: v11, bindset: v9, bind: data);
    idStr::ToUpper(this: &v16.name);
    idSWFScriptVar::idSWFScriptVar(this: &v14, s: v16.name.data);
    idSWFScriptObject::Set(this: (idSWFScriptObject *)thisObject->variables.num, name: "keyboard", value: &v14);
    idSWFScriptVar::Free(this: &v14);
    idSWFScriptVar::idSWFScriptVar(this: &v12, s: v16.type.data);
    idSWFScriptObject::Set(this: (idSWFScriptObject *)thisObject->variables.num, name: "mouse", value: &v12);
    idSWFScriptVar::Free(this: &v12);
    idSWFScriptVar::idSWFScriptVar(this: &v13, s: v16.value.data);
    idSWFScriptObject::Set(this: (idSWFScriptObject *)thisObject->variables.num, name: "gamepad", value: &v13);
    idSWFScriptVar::Free(this: &v13);
    idSWFScriptVar::idSWFScriptVar(this: result, o: (idSWFScriptObject *)thisObject->variables.num);
    keyBindings_t::~keyBindings_t(this: &v16);
    idStr::FreeData(this: &v15);
  }
  else
  {
    result->type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: result);
    result->value.b = false;
    result->type = SWF_VAR_BOOL;
  }
  return result;
}


// ========================================================================
// __unwind$531282
// EA  : 0x82DACC50
// RVA : 0x00DACC50
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531282()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 288;
  if ( (*(_DWORD *)(v0 - 288 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 308));
  }
}


// ========================================================================
// __unwind$531285
// EA  : 0x82DACC94
// RVA : 0x00DACC94
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531285()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$531286
// EA  : 0x82DACCBC
// RVA : 0x00DACCBC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531286()
{
  int v0; // r12

  keyBindings_t::~keyBindings_t(this: (testReportField_t *)(v0 - 288 + 144));
}


// ========================================================================
// __unwind$531287
// EA  : 0x82DACCE4
// RVA : 0x00DACCE4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531287()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 104));
}


// ========================================================================
// __unwind$531288
// EA  : 0x82DACD0C
// RVA : 0x00DACD0C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531288()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 88));
}


// ========================================================================
// __unwind$531289
// EA  : 0x82DACD34
// RVA : 0x00DACD34
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531289()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 96));
}


// ========================================================================
// ?SetupCredits@idMainMenu@@QAAXXZ
// EA  : 0x82DACD68
// RVA : 0x00DACD68
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::SetupCredits(idMainMenu *this)
{
  idMainMenu *v1; // r30
  idStr *rageCredits; // r28
  idSWFScriptObject *v3; // r23
  int v4; // r20
  int v5; // r29
  int data; // r18
  idSWFScriptObject *v7; // r30
  idDeclCredits *CreditEntry; // r14
  idDeclCredits *v9; // r14
  idDeclCredits *v10; // r14
  idDeclCredits::creditEntry_t CreditType; // r3
  idSWFScriptVar::swfScriptVarValue_t v12; // r14
  idSWFScriptVar v15; // [sp+50h] [-140h] BYREF
  idSWFScriptVar v16; // [sp+58h] [-138h] BYREF
  idSWFScriptVar v17; // [sp+60h] [-130h] BYREF
  idSWFScriptVar v18; // [sp+68h] [-128h] BYREF
  idSWFScriptVar v19; // [sp+70h] [-120h] BYREF
  idSWFScriptVar v20; // [sp+78h] [-118h] BYREF
  idSWFScriptVar v21[2]; // [sp+80h] [-110h] BYREF
  idDeclCredits v22[3]; // [sp+90h] [-100h] BYREF

  v1 = this;
  rageCredits = (idStr *)gameLocal->rageCredits;
  if ( rageCredits != nullptr )
  {
    v3 = idSWFScriptObject::Alloc();
    idSWFScriptObject::MakeArray(this: v3);
    v4 = 0;
    v5 = 0;
    data = (int)rageCredits[2].data;
    if ( data > 0 )
    {
      do
      {
        v7 = idSWFScriptObject::Alloc();
        if ( idDeclCredits::GetCreditType(this: (idDeclCredits *)rageCredits, index: v5) == CREDIT_DOUBLE )
        {
          CreditEntry = idDeclCredits::GetCreditEntry(
                          this: (idDeclCredits *)((char *)&v22[0].idResource + 32),
                          result: rageCredits,
                          index: v5,
                          entry: 0);
          v18.type = SWF_VAR_UNDEF;
          idSWFScriptVar::Free(this: &v18);
          v18.type = SWF_VAR_STRING;
          v18.value.i = (int)idSWFScriptString::Alloc(s: (const idStr *)CreditEntry);
          idSWFScriptObject::Set(this: v7, name: "entry0", value: &v18);
          idSWFScriptVar::Free(this: &v18);
          idStr::FreeData(this: (idStr *)&v22[0].idResource + 1);
          v9 = idDeclCredits::GetCreditEntry(this: v22, result: rageCredits, index: v5, entry: 1);
          v19.type = SWF_VAR_UNDEF;
          idSWFScriptVar::Free(this: &v19);
          v19.type = SWF_VAR_STRING;
          v19.value.i = (int)idSWFScriptString::Alloc(s: (const idStr *)v9);
          idSWFScriptObject::Set(this: v7, name: "entry1", value: &v19);
          idSWFScriptVar::Free(this: &v19);
          idStr::FreeData(this: (idStr *)v22);
        }
        else
        {
          v10 = idDeclCredits::GetCreditEntry(
                  this: (idDeclCredits *)&v22[0].creditList,
                  result: rageCredits,
                  index: v5,
                  entry: 0);
          v17.type = SWF_VAR_UNDEF;
          idSWFScriptVar::Free(this: &v17);
          v17.type = SWF_VAR_STRING;
          v17.value.i = (int)idSWFScriptString::Alloc(s: (const idStr *)v10);
          idSWFScriptObject::Set(this: v7, name: "entry0", value: &v17);
          idSWFScriptVar::Free(this: &v17);
          idStr::FreeData(this: (idStr *)&v22[0].creditList);
          idSWFScriptVar::idSWFScriptVar(this: v21, s: &byte_8200D768);
          idSWFScriptObject::Set(this: v7, name: "entry1", value: v21);
          idSWFScriptVar::Free(this: v21);
        }
        CreditType = idDeclCredits::GetCreditType(this: (idDeclCredits *)rageCredits, index: v5);
        v20.type = SWF_VAR_UNDEF;
        v12.i = CreditType;
        idSWFScriptVar::Free(this: &v20);
        v20.value = v12;
        v20.type = SWF_VAR_INTEGER;
        idSWFScriptObject::Set(this: v7, name: "creditType", value: &v20);
        idSWFScriptVar::Free(this: &v20);
        v15.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v15);
        if ( v7 != nullptr )
        {
          v15.value.i = (int)v7;
          v15.type = SWF_VAR_OBJECT;
          ++v7->refCount;
        }
        else
        {
          v15.type = SWF_VAR_NULL;
        }
        idSWFScriptObject::Set(this: v3, index: v4++, value: &v15);
        idSWFScriptVar::Free(this: &v15);
        if ( v7->refCount-- == 1 )
        {
          idSWFScriptObject::~idSWFScriptObject(this: v7);
          idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
        }
        ++v5;
      }
      while ( v5 < data );
      v1 = this;
    }
    v16.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v16);
    if ( v3 != nullptr )
    {
      v16.value.i = (int)v3;
      v16.type = SWF_VAR_OBJECT;
      ++v3->refCount;
    }
    else
    {
      v16.type = SWF_VAR_NULL;
    }
    idSWFScriptObject::Set(this: v1->mainMenu->globals, name: "creditInfo", value: &v16);
    idSWFScriptVar::Free(this: &v16);
    if ( v3->refCount-- == 1 )
    {
      idSWFScriptObject::~idSWFScriptObject(this: v3);
      idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
    }
  }
}


// ========================================================================
// __unwind$531397
// EA  : 0x82DAD06C
// RVA : 0x00DAD06C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531397()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 176));
}


// ========================================================================
// __unwind$531398
// EA  : 0x82DAD094
// RVA : 0x00DAD094
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531398()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 104));
}


// ========================================================================
// __unwind$531399
// EA  : 0x82DAD0BC
// RVA : 0x00DAD0BC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531399()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 144));
}


// ========================================================================
// __unwind$531400
// EA  : 0x82DAD0E4
// RVA : 0x00DAD0E4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531400()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 112));
}


// ========================================================================
// __unwind$531401
// EA  : 0x82DAD10C
// RVA : 0x00DAD10C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531401()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 208));
}


// ========================================================================
// __unwind$531402
// EA  : 0x82DAD134
// RVA : 0x00DAD134
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531402()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 96));
}


// ========================================================================
// __unwind$531403
// EA  : 0x82DAD15C
// RVA : 0x00DAD15C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531403()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 128));
}


// ========================================================================
// __unwind$531404
// EA  : 0x82DAD184
// RVA : 0x00DAD184
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531404()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 120));
}


// ========================================================================
// __unwind$531405
// EA  : 0x82DAD1AC
// RVA : 0x00DAD1AC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531405()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 80));
}


// ========================================================================
// __unwind$531406
// EA  : 0x82DAD1D4
// RVA : 0x00DAD1D4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531406()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 88));
}


// ========================================================================
// ?SetDeadLoadOnly@idMainMenu@@QAAXXZ
// EA  : 0x82DAD208
// RVA : 0x00DAD208
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::SetDeadLoadOnly(idMainMenu *this)
{
  idSWFScriptVar v2; // [sp+50h] [-20h] BYREF

  if ( this->mainMenu != nullptr )
  {
    v2.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v2);
    v2.type = SWF_VAR_BOOL;
    v2.value.b = true;
    idSWFScriptObject::Set(this: this->mainMenu->globals, name: "openToLoad", value: &v2);
    idSWFScriptVar::Free(this: &v2);
  }
}


// ========================================================================
// __unwind$531654
// EA  : 0x82DAD288
// RVA : 0x00DAD288
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531654()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 112 + 80));
}


// ========================================================================
// ?UpdatePauseMenuState@idMainMenu@@QAAXXZ
// EA  : 0x82DAD2B8
// RVA : 0x00DAD2B8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::UpdatePauseMenuState(idMainMenu *this)
{
  idLobbyBase *v2; // r3
  idLobbyBase *v3; // r3
  idLobbyBase *v4; // r3
  bool v5; // r30
  pauseMenuState_t v6; // r11
  idGame *v7; // r3
  pauseMenuState_t pauseMenuState; // r30
  idSWFScriptVar v9; // [sp+50h] [-40h] BYREF
  idSWFScriptVar v10[7]; // [sp+58h] [-38h] BYREF

  if ( !common->IsMultiplayer(this: common) )
  {
    v7 = common->Game(this: common);
    v6 = !v7->Shell_CanSave(this: v7, a2: true);
    goto LABEL_9;
  }
  v2 = session->GetGameLobbyBase(this: session);
  if ( v2->GetMatchParms(this: v2)->gameType != 1 )
  {
    v6 = PAUSEMENU_MULTI_VDM;
LABEL_9:
    this->pauseMenuState = v6;
    goto LABEL_10;
  }
  this->pauseMenuState = PAUSEMENU_MULTI_COOP;
  v3 = session->GetGameLobbyBase(this: session);
  if ( v3->GetNumActiveLobbyUsers(this: v3) <= 1
    || (v4 = session->GetGameLobbyBase(this: session), v5 = true, (v4->GetMatchParms(this: v4)->matchFlags & 2) == 0) )
  {
    v5 = false;
  }
  v9.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v9);
  v9.value.b = v5;
  v9.type = SWF_VAR_BOOL;
  idSWFScriptObject::Set(this: this->mainMenu->globals, name: "showPartnerProfile", value: &v9);
  idSWFScriptVar::Free(this: &v9);
LABEL_10:
  v10[0].type = SWF_VAR_UNDEF;
  pauseMenuState = this->pauseMenuState;
  idSWFScriptVar::Free(this: v10);
  v10[0].value.i = pauseMenuState;
  v10[0].type = SWF_VAR_INTEGER;
  idSWFScriptObject::Set(this: this->mainMenu->globals, name: "pauseState", value: v10);
  idSWFScriptVar::Free(this: v10);
}


// ========================================================================
// __unwind$531690
// EA  : 0x82DAD460
// RVA : 0x00DAD460
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531690()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$531691
// EA  : 0x82DAD488
// RVA : 0x00DAD488
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531691()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 144 + 88));
}


// ========================================================================
// ?UpdateSavedGameList@idMainMenu@@QAAXXZ
// EA  : 0x82DAD4B8
// RVA : 0x00DAD4B8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateSavedGameList(idMainMenu *this)
{
  idMainMenu *v1; // r29
  idSWFScriptObject *v2; // r30
  idLocalUser *v3; // r3
  bool v4; // r11
  int v5; // r11
  const char *v6; // r29
  int v7; // r25
  char *v8; // r28
  idSWFScriptObject *v9; // r30
  idSaveGameDetails *SlotName; // r3
  BOOL v11; // r26
  const idKeyValue *v12; // r3
  const char *v13; // r4
  idStrId *v14; // r11
  const char *v15; // r29
  const char *v16; // r3
  __int64 v17; // r10
  __int64 v18; // r8
  va *v19; // r3
  const idKeyValue *Key; // r3
  const char *data; // r4
  idStrId *v22; // r11
  const char *LocalizedString; // r4
  const char *v24; // r3
  const idStr *v25; // r29
  const idKeyValue *v26; // r3
  const char *v27; // r3
  idSWFScriptVar::swfScriptVarValue_t v28; // r29
  const idKeyValue *v29; // r3
  const char *v30; // r3
  int v31; // r4
  char *v32; // r4
  const idStr *v33; // r29
  const idStr *v34; // r29
  const idStr *v35; // r29
  const idStr *v36; // r29
  int v37; // r29
  int v40; // [sp+8h] [-12D8h]
  int v41; // [sp+Ch] [-12D4h]
  int v42; // [sp+10h] [-12D0h]
  int v43; // [sp+14h] [-12CCh]
  int v44; // [sp+18h] [-12C8h]
  int v45; // [sp+1Ch] [-12C4h]
  idSWFScriptVar v46; // [sp+50h] [-1290h] BYREF
  idSWFScriptVar v47; // [sp+58h] [-1288h] BYREF
  idSWFScriptVar v48; // [sp+60h] [-1280h] BYREF
  idSWFScriptVar v49; // [sp+68h] [-1278h] BYREF
  int v50; // [sp+70h] [-1270h]
  idSWFScriptVar v51; // [sp+78h] [-1268h] BYREF
  idMem *v52; // [sp+80h] [-1260h]
  idSWFScriptVar v53; // [sp+88h] [-1258h] BYREF
  idSWFScriptVar v54; // [sp+90h] [-1250h] BYREF
  idSWFScriptVar v55; // [sp+98h] [-1248h] BYREF
  int num; // [sp+A0h] [-1240h]
  idDeclInfoTemplate<idDeclMapInfo> *v57; // [sp+A4h] [-123Ch]
  int v58; // [sp+A8h] [-1238h]
  idSWFScriptVar v59; // [sp+B0h] [-1230h] BYREF
  idStaticList<idSaveGameDetails,16> *p_enumeratedSaveGames; // [sp+B8h] [-1228h]
  idSWFScriptObject *v61; // [sp+BCh] [-1224h]
  idSWFScriptVar v62; // [sp+C0h] [-1220h] BYREF
  idSWFScriptVar v63; // [sp+C8h] [-1218h] BYREF
  const char *v64; // [sp+D0h] [-1210h]
  const char *v65; // [sp+D4h] [-120Ch]
  const char *v66; // [sp+D8h] [-1208h]
  idStrId v67; // [sp+DCh] [-1204h] BYREF
  const char *v68; // [sp+E0h] [-1200h]
  idSWFScriptVar v69; // [sp+E8h] [-11F8h] BYREF
  idSWFScriptVar v70[2]; // [sp+F0h] [-11F0h] BYREF
  idStr v71; // [sp+100h] [-11E0h] BYREF
  idStr v72; // [sp+120h] [-11C0h] BYREF
  idStr v73; // [sp+140h] [-11A0h] BYREF
  idStr v74; // [sp+160h] [-1180h] BYREF
  idStr v75; // [sp+180h] [-1160h] BYREF
  idStr v76; // [sp+1A0h] [-1140h] BYREF
  idStr v77; // [sp+1C0h] [-1120h] BYREF
  idSaveGameDetails v78; // [sp+1E0h] [-1100h] BYREF

  v1 = this;
  v2 = idSWFScriptObject::Alloc();
  v61 = v2;
  idSWFScriptObject::MakeArray(this: v2);
  v3 = common->GetMasterLocalUser(this: common);
  v52 = &mem;
  if ( v3 == nullptr )
  {
    v4 = false;
    goto LABEL_42;
  }
  v58 = 0;
  p_enumeratedSaveGames = &session->saveGameManager->enumeratedSaveGames;
  num = p_enumeratedSaveGames->num;
  v5 = num;
  if ( num <= 0 )
    goto LABEL_40;
  v50 = 0;
  v68 = "#str_autosave";
  v65 = "%s - %s";
  v6 = "mapName";
  v66 = "mapName";
  v57 = &idDeclMapInfo::resourceList;
  v64 = "AUTOSAVE";
  while ( 1 )
  {
    v7 = v50;
    v8 = (char *)p_enumeratedSaveGames->list + v50;
    v9 = idSWFScriptObject::Alloc();
    SlotName = idSaveGameDetails::GetSlotName(this: &v78, result: (idStrStatic<64> *)v8);
    v11 = (_cntlzw(idStr::Cmp(s1: (const char *)SlotName->descriptors.args.num, s2: v64)) & 0x20) != 0;
    idStr::FreeData(this: (idStr *)&v78);
    if ( !v11 )
    {
      Key = idDict::FindKey(this: (idDict *)v8, key: v6);
      if ( Key != nullptr )
      {
        data = Key->value.data;
        if ( data == nullptr )
        {
          v22 = nullptr;
LABEL_21:
          if ( v22[16].index >= 0 )
            LocalizedString = idStrId::GetLocalizedString(this: v22 + 16);
          else
            LocalizedString = (const char *)v22[2].index;
          idSWFScriptVar::idSWFScriptVar(this: v70, s: LocalizedString);
          idSWFScriptObject::Set(this: v9, name: "name", value: v70);
          idSWFScriptVar::Free(this: v70);
          goto LABEL_25;
        }
      }
      else
      {
        data = &byte_8200D768;
      }
      v22 = (idStrId *)idDeclInfo::FindWithInheritance(this: v57, name: data, makeDefault: true);
      goto LABEL_21;
    }
    v12 = idDict::FindKey(this: (idDict *)v8, key: v6);
    if ( v12 == nullptr )
    {
      v13 = &byte_8200D768;
LABEL_11:
      v14 = (idStrId *)idDeclInfo::FindWithInheritance(this: v57, name: v13, makeDefault: true);
      goto LABEL_12;
    }
    v13 = v12->value.data;
    if ( v13 != nullptr )
      goto LABEL_11;
    v14 = nullptr;
LABEL_12:
    v15 = v14[16].index >= 0 ? idStrId::GetLocalizedString(this: v14 + 16) : (const char *)v14[2].index;
    idStrId::Set(this: &v67, key: v68);
    v16 = idStrId::GetLocalizedString(this: &v67);
    v19 = va::va(
            this: (va *)v78.slotName.buffer,
            fmt: v65,
            a3: __SPAIR64__((unsigned int)v16, (unsigned int)v15),
            a4: v18,
            a5: v17,
            a6: v40,
            a7: v41,
            a8: v42,
            a9: v43,
            a10: v44,
            a11: v45);
    idStr::idStr(this: &v71, text: v19);
    idSWFScriptVar::idSWFScriptVar(this: &v69, s: v71.data);
    idSWFScriptObject::Set(this: v9, name: "name", value: &v69);
    idSWFScriptVar::Free(this: &v69);
    idStr::FreeData(this: &v71);
LABEL_25:
    v24 = Sys_TimeStampToStr(timeStamp: *((_DWORD *)v8 + 15), padded: false);
    v54.type = SWF_VAR_UNDEF;
    v25 = idStr::idStr(this: &v72, text: v24);
    idSWFScriptVar::Free(this: &v54);
    v54.type = SWF_VAR_STRING;
    v54.value.i = (int)idSWFScriptString::Alloc(s: v25);
    idStr::FreeData(this: &v72);
    idSWFScriptObject::Set(this: v9, name: "timeStamp", value: &v54);
    idSWFScriptVar::Free(this: &v54);
    v26 = idDict::FindKey(this: (idDict *)v8, key: "difficulty");
    if ( v26 != nullptr && (v27 = v26->value.data) != nullptr )
      v28.i = atol(nptr: v27);
    else
      v28.i = 0;
    v55.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v55);
    v55.value = v28;
    v55.type = SWF_VAR_INTEGER;
    idSWFScriptObject::Set(this: v9, name: "difficulty", value: &v55);
    idSWFScriptVar::Free(this: &v55);
    v29 = idDict::FindKey(this: (idDict *)v8, key: "time");
    if ( v29 != nullptr && (v30 = v29->value.data) != nullptr )
      v31 = atol(nptr: v30);
    else
      v31 = 0;
    v32 = Sys_SecToStr(result: &v77, sec: v31)->data;
    v48.type = SWF_VAR_UNDEF;
    v33 = idStr::idStr(this: &v74, text: v32);
    idSWFScriptVar::Free(this: &v48);
    v48.type = SWF_VAR_STRING;
    v48.value.i = (int)idSWFScriptString::Alloc(s: v33);
    idStr::FreeData(this: &v74);
    idSWFScriptObject::Set(this: v9, name: "requiredPer", value: &v48);
    idSWFScriptVar::Free(this: &v48);
    idStr::FreeData(this: &v77);
    LOBYTE(v33) = v8[48];
    v59.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v59);
    v59.value.b = (char)v33;
    v59.type = SWF_VAR_BOOL;
    idSWFScriptObject::Set(this: v9, name: "isCorrupt", value: &v59);
    idSWFScriptVar::Free(this: &v59);
    v49.type = SWF_VAR_UNDEF;
    v34 = idStr::idStr(this: &v76, text: &byte_8200D768);
    idSWFScriptVar::Free(this: &v49);
    v49.type = SWF_VAR_STRING;
    v49.value.i = (int)idSWFScriptString::Alloc(s: v34);
    idStr::FreeData(this: &v76);
    idSWFScriptObject::Set(this: v9, name: "isQuick", value: &v49);
    idSWFScriptVar::Free(this: &v49);
    v51.type = SWF_VAR_UNDEF;
    v35 = idStr::idStr(this: &v73, text: &byte_8200D768);
    idSWFScriptVar::Free(this: &v51);
    v51.type = SWF_VAR_STRING;
    v51.value.i = (int)idSWFScriptString::Alloc(s: v35);
    idStr::FreeData(this: &v73);
    idSWFScriptObject::Set(this: v9, name: "mapArea", value: &v51);
    idSWFScriptVar::Free(this: &v51);
    v53.type = SWF_VAR_UNDEF;
    v36 = idStr::idStr(this: &v75, text: &byte_8200D768);
    idSWFScriptVar::Free(this: &v53);
    v53.type = SWF_VAR_STRING;
    v53.value.i = (int)idSWFScriptString::Alloc(s: v36);
    idStr::FreeData(this: &v75);
    idSWFScriptObject::Set(this: v9, name: "activeDesc", value: &v53);
    idSWFScriptVar::Free(this: &v53);
    v47.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v47);
    if ( v9 != nullptr )
    {
      v47.value.i = (int)v9;
      v47.type = SWF_VAR_OBJECT;
      ++v9->refCount;
    }
    else
    {
      v47.type = SWF_VAR_NULL;
    }
    v37 = v58;
    idSWFScriptObject::Set(this: v61, index: v58, value: &v47);
    idSWFScriptVar::Free(this: &v47);
    if ( v9->refCount-- == 1 )
    {
      idSWFScriptObject::~idSWFScriptObject(this: v9);
      idMem::Free(this: v52, ptr: v9, align: ALIGN_16);
    }
    v58 = v37 + 1;
    v50 = v7 + 160;
    num = p_enumeratedSaveGames->num;
    v5 = num;
    if ( v37 + 1 >= num )
      break;
    v6 = v66;
  }
  v1 = this;
  v2 = v61;
LABEL_40:
  num = v5;
  if ( v5 > 0 )
  {
    v4 = true;
LABEL_42:
    hasSaveGames = v4;
  }
  v63.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v63);
  v63.type = SWF_VAR_BOOL;
  v63.value.b = false;
  idSWFScriptObject::Set(this: v2, name: "hasQuickSave", value: &v63);
  idSWFScriptVar::Free(this: &v63);
  v62.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v62);
  v62.value.i = 16;
  v62.type = SWF_VAR_INTEGER;
  idSWFScriptObject::Set(this: v2, name: "maxSaves", value: &v62);
  idSWFScriptVar::Free(this: &v62);
  if ( v1->mainMenu != nullptr )
  {
    v46.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v46);
    if ( v2 != nullptr )
    {
      v46.value.i = (int)v2;
      v46.type = SWF_VAR_OBJECT;
      ++v2->refCount;
    }
    else
    {
      v46.type = SWF_VAR_NULL;
    }
    idSWFScriptObject::Set(this: v1->mainMenu->globals, name: "saveGameList", value: &v46);
    idSWFScriptVar::Free(this: &v46);
  }
  if ( v2->refCount-- == 1 )
  {
    idSWFScriptObject::~idSWFScriptObject(this: v2);
    idMem::Free(this: v52, ptr: v2, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$531779
// EA  : 0x82DADB84
// RVA : 0x00DADB84
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531779()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4832 + 480));
}


// ========================================================================
// __unwind$531780
// EA  : 0x82DADBAC
// RVA : 0x00DADBAC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531780()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4832 + 256));
}


// ========================================================================
// __unwind$531781
// EA  : 0x82DADBD4
// RVA : 0x00DADBD4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531781()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4832 + 232));
}


// ========================================================================
// __unwind$531782
// EA  : 0x82DADBFC
// RVA : 0x00DADBFC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531782()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4832 + 240));
}


// ========================================================================
// __unwind$531972
// EA  : 0x82DADC24
// RVA : 0x00DADC24
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531972()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4832 + 288));
}


// ========================================================================
// __unwind$531783
// EA  : 0x82DADC4C
// RVA : 0x00DADC4C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531783()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4832 + 144));
}


// ========================================================================
// __unwind$531784
// EA  : 0x82DADC74
// RVA : 0x00DADC74
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531784()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4832 + 152));
}


// ========================================================================
// __unwind$531785
// EA  : 0x82DADC9C
// RVA : 0x00DADC9C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531785()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4832 + 448));
}


// ========================================================================
// __unwind$532099
// EA  : 0x82DADCC4
// RVA : 0x00DADCC4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_532099()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4832 + 352));
}


// ========================================================================
// __unwind$531786
// EA  : 0x82DADCEC
// RVA : 0x00DADCEC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531786()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4832 + 96));
}


// ========================================================================
// __unwind$531787
// EA  : 0x82DADD14
// RVA : 0x00DADD14
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531787()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4832 + 176));
}


// ========================================================================
// __unwind$532137
// EA  : 0x82DADD3C
// RVA : 0x00DADD3C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_532137()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4832 + 416));
}


// ========================================================================
// __unwind$531788_0
// EA  : 0x82DADD64
// RVA : 0x00DADD64
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531788_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4832 + 104));
}


// ========================================================================
// __unwind$532157
// EA  : 0x82DADD8C
// RVA : 0x00DADD8C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_532157()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4832 + 320));
}


// ========================================================================
// __unwind$531789_0
// EA  : 0x82DADDB4
// RVA : 0x00DADDB4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531789_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4832 + 120));
}


// ========================================================================
// __unwind$532177
// EA  : 0x82DADDDC
// RVA : 0x00DADDDC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_532177()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4832 + 384));
}


// ========================================================================
// __unwind$531790_0
// EA  : 0x82DADE04
// RVA : 0x00DADE04
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531790_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4832 + 136));
}


// ========================================================================
// __unwind$531791
// EA  : 0x82DADE2C
// RVA : 0x00DADE2C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531791()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4832 + 88));
}


// ========================================================================
// __unwind$531792
// EA  : 0x82DADE54
// RVA : 0x00DADE54
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531792()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4832 + 200));
}


// ========================================================================
// __unwind$531793
// EA  : 0x82DADE7C
// RVA : 0x00DADE7C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531793()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4832 + 192));
}


// ========================================================================
// __unwind$531794
// EA  : 0x82DADEA4
// RVA : 0x00DADEA4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_531794()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4832 + 80));
}


// ========================================================================
// ?LoadDamagedGame@idMainMenu@@QAAXH@Z
// EA  : 0x82DADED8
// RVA : 0x00DADED8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::LoadDamagedGame(idMainMenu *this, int index)
{
  idSaveGameManager *saveGameManager; // r11
  _DWORD *v5; // r3
  _DWORD *v6; // r11
  _DWORD *v7; // r3
  idSWF *mainMenu; // r10
  _DWORD *v9; // r11
  idStrStatic<256> *v10; // r3
  _DWORD *v11; // [sp+60h] [-1D0h] BYREF
  idStrId v12; // [sp+64h] [-1CCh] BYREF
  idStrId v13[2]; // [sp+68h] [-1C8h] BYREF
  idList<idVehicleState *,5> v14; // [sp+70h] [-1C0h] BYREF
  _BYTE v15[16]; // [sp+80h] [-1B0h] BYREF
  idList<enum encounterGroupRole_t,5> v16; // [sp+90h] [-1A0h] BYREF
  int v17; // [sp+A0h] [-190h] BYREF
  idStrStatic<256> v18; // [sp+B0h] [-180h] BYREF

  saveGameManager = session->saveGameManager;
  v12.index = (int)&saveGameManager->enumeratedSaveGames;
  if ( index < saveGameManager->enumeratedSaveGames.num )
  {
    v16.granularity = 1;
    v16.size = 4;
    v16.num = 0;
    v16.memTag = 5;
    v16.list = (encounterGroupRole_t *)&v17;
    v16.listStatic = 1;
    v5 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
           size: 0x14u,
           tag: TAG_SWF,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5[2] = this;
      v5[4] = index;
      v6 = v5;
      v5[1] = 0;
      v5[3] = 69;
      *v5 = &`idMainMenu::LoadDamagedGame'::`5'::idSWFScriptFunction_AcceptDelete::`vftable';
    }
    else
    {
      v6 = nullptr;
    }
    v11 = v6;
    idList<idAnimWebBlendTree *,5>::Append(this: &v16, obj: (encounterGroupRole_t *)&v11);
    v7 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
           size: 0x10u,
           tag: TAG_SWF,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    if ( v7 != nullptr )
    {
      mainMenu = this->mainMenu;
      v7[1] = 0;
      v9 = v7;
      v7[2] = 69;
      *v7 = &`idMainMenu::LoadDamagedGame'::`6'::idSWFScriptFunction_CancelDelete::`vftable';
      v7[3] = mainMenu;
    }
    else
    {
      v9 = nullptr;
    }
    v11 = v9;
    idList<idAnimWebBlendTree *,5>::Append(this: &v16, obj: (encounterGroupRole_t *)&v11);
    *(_QWORD *)&v14.num = 4;
    v14.list = (idVehicleState **)v15;
    *(_DWORD *)&v14.granularity = 66817;
    memset(v15, 255, sizeof(v15));
    idStrId::Set(this: v13, key: "#str_swf_delete");
    idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: (idList<idStrId,5> *)&v14, obj: v13);
    idStrId::Set(this: &v12, key: "#STR_SWF_CANCEL");
    idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: (idList<idStrId,5> *)&v14, obj: &v12);
    v10 = idStrStatic<256>::idStrStatic<256>(this: &v18, text: &byte_8200D768);
    ((void (__fastcall *)(idCommon *, int, idList<enum encounterGroupRole_t,5> *, idList<idVehicleState *,5> *, _DWORD, idStrStatic<256> *, _DWORD, _DWORD))common->AddDynamicDialog)(
      a1: common,
      a2: 69,
      a3: &v16,
      a4: &v14,
      a5: 0,
      a6: v10,
      a7: 0,
      a8: 0);
    idList<idThread *,58>::Clear(this: &v14);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v16);
  }
}


// ========================================================================
// __unwind$532477
// EA  : 0x82DAE0D8
// RVA : 0x00DAE0D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_532477()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 560 + 144));
}


// ========================================================================
// __unwind$532480
// EA  : 0x82DAE100
// RVA : 0x00DAE100
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_532480()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 560 + 112));
}


// ========================================================================
// ?TestGui@idMainMenu@@QAAXPBD@Z
// EA  : 0x82DAE130
// RVA : 0x00DAE130
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::TestGui(idMainMenu *this, char *filename)
{
  idSWF *testGui; // r30
  idSWF *v5; // r3
  idSWF *v6; // r4

  testGui = this->testGui;
  if ( testGui != nullptr )
  {
    idSWF::~idSWF(this: this->testGui);
    idMem::Free(this: &mem, ptr: testGui, align: ALIGN_16);
    this->testGui = nullptr;
  }
  if ( filename != nullptr && *filename != 0 )
  {
    v5 = (idSWF *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                    size: 0x27Cu,
                    tag: TAG_SWF,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
      v6 = idSWF::idSWF(this: v5, filename_: filename, soundWorld: this->soundWorld, atlasPurgable_: true);
    else
      v6 = nullptr;
    this->testGui = v6;
    idMainMenu::SetupBindings(this, gui: v6);
    idSWF::Activate(this: this->testGui, b: true);
  }
}


// ========================================================================
// __unwind$532771
// EA  : 0x82DAE200
// RVA : 0x00DAE200
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_532771()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SWF);
}


// ========================================================================
// ?Call@idSWFScriptFunction_checkCanPlayOnline@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DAE230
// RVA : 0x00DAE230
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_checkCanPlayOnline *__fastcall idMainMenu::idSWFScriptFunction_checkCanPlayOnline::Call(
        idMainMenu::idSWFScriptFunction_checkCanPlayOnline *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idLocalUser *v6; // r3
  char v7; // r28
  idLocalUser *v8; // r3

  if ( net_usePlatformBackend.valueInteger != 0 )
  {
    if ( common->GetMasterLocalUser(this: common) == nullptr
      || (v6 = common->GetMasterLocalUser(this: common), v7 = 1, (v6->GetOnlineCaps(this: v6) & 4) == 0) )
    {
      v7 = 0;
    }
    if ( v7 == 0 )
    {
      v8 = common->GetMasterLocalUser(this: common);
      v8->GetOnlineCaps(this: v8);
      ((void (*)(void))common->AddDialog)();
    }
    this->__vftable = (idMainMenu::idSWFScriptFunction_checkCanPlayOnline_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = v7;
    this->__vftable = (idMainMenu::idSWFScriptFunction_checkCanPlayOnline_vtbl *)5;
    return this;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_checkCanPlayOnline_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = 1;
    this->__vftable = (idMainMenu::idSWFScriptFunction_checkCanPlayOnline_vtbl *)5;
    return this;
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_isMpDisc@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DAE390
// RVA : 0x00DAE390
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_isMpDisc *__fastcall idMainMenu::idSWFScriptFunction_isMpDisc::Call(
        idMainMenu::idSWFScriptFunction_isMpDisc *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  if ( discSwapper_enable.valueInteger != 0
    && ((int (__fastcall *)(idResourceManager *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))resourceManager->GetCurrentDiscNumber)(
         a1: resourceManager,
         a2: result,
         a3: thisObject,
         a4: parms) == 3 )
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_isMpDisc_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = 1;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_isMpDisc_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = 0;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_isMpDisc_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_waitForCredits@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DAE438
// RVA : 0x00DAE438
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_waitForCredits *__fastcall idMainMenu::idSWFScriptFunction_waitForCredits::Call(
        idMainMenu::idSWFScriptFunction_waitForCredits *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  bool v5; // cr58

  v5 = swf_waitForCredits.valueInteger == 0;
  this->__vftable = (idMainMenu::idSWFScriptFunction_waitForCredits_vtbl *)4;
  if ( v5 )
  {
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = 0;
  }
  else
  {
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = 1;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_waitForCredits_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_needsDiskSwap@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DAE4B0
// RVA : 0x00DAE4B0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_needsDiskSwap *__fastcall idMainMenu::idSWFScriptFunction_needsDiskSwap::Call(
        idMainMenu::idSWFScriptFunction_needsDiskSwap *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v7; // r3
  char v8; // r30

  if ( parms->num == 1 )
  {
    v7 = idSWFScriptVar::ToBool(this: parms->list);
    v8 = idMainMenu::NeedsDiskSwap(this: (idMainMenu *)result->value.i, singlePlayerSelected: v7);
    this->__vftable = (idMainMenu::idSWFScriptFunction_needsDiskSwap_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = v8;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_needsDiskSwap_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = 0;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_needsDiskSwap_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_needSpDiscSwap@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DAE538
// RVA : 0x00DAE538
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_needSpDiscSwap *__fastcall idMainMenu::idSWFScriptFunction_needSpDiscSwap::Call(
        idMainMenu::idSWFScriptFunction_needSpDiscSwap *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v5; // r30

  v5 = idMainMenu::MpToSpDiscSwapCheck(this: (idMainMenu *)result->value.i);
  this->__vftable = (idMainMenu::idSWFScriptFunction_needSpDiscSwap_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v5;
  this->__vftable = (idMainMenu::idSWFScriptFunction_needSpDiscSwap_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getGameDifficulty@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DAE598
// RVA : 0x00DAE598
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getGameDifficulty *__fastcall idMainMenu::idSWFScriptFunction_getGameDifficulty::Call(
        idMainMenu::idSWFScriptFunction_getGameDifficulty *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *v5; // r30

  v5 = (idMainMenu *)((int (__fastcall *)(idGameLocal *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))gameLocal->GetGameDifficulty)(
                       a1: gameLocal,
                       a2: result,
                       a3: thisObject,
                       a4: parms);
  this->__vftable = (idMainMenu::idSWFScriptFunction_getGameDifficulty_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  this->pThis = v5;
  this->__vftable = (idMainMenu::idSWFScriptFunction_getGameDifficulty_vtbl *)6;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getDefaultDevMenuOption@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DAE608
// RVA : 0x00DAE608
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getDefaultDevMenuOption *__fastcall idMainMenu::idSWFScriptFunction_getDefaultDevMenuOption::Call(
        idMainMenu::idSWFScriptFunction_getDefaultDevMenuOption *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, s: "devmenuoption/main");
  return this;
}


// ========================================================================
// ?loadMPMap_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82DAE648
// RVA : 0x00DAE648
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall loadMPMap_f(const idCmdArgs *args)
{
  const char *v2; // r4
  const char *v3; // r4
  idStr v4; // [sp+50h] [-12C0h] BYREF
  idStr v5; // [sp+70h] [-12A0h] BYREF
  idMatchParameters v6; // [sp+90h] [-1280h] BYREF

  if ( args->argc >= 2 )
  {
    if ( session->GetState(this: session) == PRESS_START )
    {
      session->signInManager->RegisterLocalUser(this: session->signInManager, a2: 0);
      while ( session->GetState(this: session) != 1 )
      {
        session->UpdateSignInManager(this: session);
        session->Pump(this: session);
        mgthread_sleep(ms: 10);
      }
    }
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    idStr::idStr(this: &v4, text: v2);
    idStr::ToLower(this: &v4);
    idStr::StripFileExtension(this: &v4);
    if ( args->argc <= 2 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[2];
    idStr::idStr(this: &v5, text: v3);
    if ( v5.len != 0 && idStr::Icmp(s1: v5.data, s2: "mp/") != 0 )
    {
      idCVar::SetBool(this: &com_multiplayer, newValue: true, force: true);
      idMainMenu::LoadMultiplayerDecls(this: gameLocal->mainMenu);
      idMainMenu::SetupMultiplayerMenu(this: gameLocal->mainMenu);
      cmdSystem->AppendCommandText(this: cmdSystem, a2: "exec default_mp.cfg\n");
      cmdSystem->ExecuteCommandBuffer(this: cmdSystem);
      gameLocal->mainMenu->localMatch = true;
      idMatchParameters::idMatchParameters(this: &v6);
      v6.gameType = 2;
      v6.matchFlags = 42;
      idMatchParameters::SetMapName(this: &v6, name: v4.data);
      idMatchParameters::SetLayersActive(this: &v6, active: v5.data);
      v6.comboMap = true;
      v6.devmap = true;
      v6.scoreLimit = si_scoreLimit.valueInteger;
      v6.timeLimit = si_timeLimit.valueInteger;
      session->ClearSessionOption(this: session, a2: OPTION_ALL);
      session->CreatePartyLobby(this: session, a2: &v6);
      session->CreateMatch(this: session, a2: &v6);
      idMainMenu::WaitForSessionState(this: gameLocal->mainMenu, desiredState: GAME_LOBBY);
      session->StartMatch(this: session);
      idMainMenu::WaitForSessionState(this: gameLocal->mainMenu, desiredState: PARTY_LOBBY|SEARCHING);
      idMatchParameters::~idMatchParameters(this: &v6);
      idStr::FreeData(this: &v5);
    }
    else
    {
      idLib::Warning(fmt: "loadMPMap: invalid map layer passed in!");
      idStr::FreeData(this: &v5);
    }
    idStr::FreeData(this: &v4);
  }
  else
  {
    idLib::Printf(fmt: "usage: loadMPMap <mapName> (map layer name)\n");
  }
}


// ========================================================================
// __unwind$533254
// EA  : 0x82DAE924
// RVA : 0x00DAE924
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533254()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4880 + 80));
}


// ========================================================================
// __unwind$533255
// EA  : 0x82DAE94C
// RVA : 0x00DAE94C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533255()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4880 + 112));
}


// ========================================================================
// __unwind$533256
// EA  : 0x82DAE974
// RVA : 0x00DAE974
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533256()
{
  int v0; // r12

  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(v0 - 4880 + 144));
}


// ========================================================================
// ?Call@idSWFScriptFunction_isDemoMode@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DAE9A0
// RVA : 0x00DAE9A0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_isDemoMode *__fastcall idMainMenu::idSWFScriptFunction_isDemoMode::Call(
        idMainMenu::idSWFScriptFunction_isDemoMode *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int valueInteger; // r11
  bool v6; // r31

  valueInteger = g_demoMode.valueInteger;
  this->__vftable = (idMainMenu::idSWFScriptFunction_isDemoMode_vtbl *)4;
  v6 = valueInteger != 0;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v6;
  this->__vftable = (idMainMenu::idSWFScriptFunction_isDemoMode_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_isMpHandsOnDemo@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DAEA00
// RVA : 0x00DAEA00
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_isMpHandsOnDemo *__fastcall idMainMenu::idSWFScriptFunction_isMpHandsOnDemo::Call(
        idMainMenu::idSWFScriptFunction_isMpHandsOnDemo *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int valueInteger; // r11
  bool v6; // r31

  valueInteger = swf_mpHandsOnMenus.valueInteger;
  this->__vftable = (idMainMenu::idSWFScriptFunction_isMpHandsOnDemo_vtbl *)4;
  v6 = valueInteger != 0;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v6;
  this->__vftable = (idMainMenu::idSWFScriptFunction_isMpHandsOnDemo_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_showDLCOption@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DAEA60
// RVA : 0x00DAEA60
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_showDLCOption *__fastcall idMainMenu::idSWFScriptFunction_showDLCOption::Call(
        idMainMenu::idSWFScriptFunction_showDLCOption *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int valueInteger; // r11
  bool v6; // r31

  valueInteger = swf_showDLCOption.valueInteger;
  this->__vftable = (idMainMenu::idSWFScriptFunction_showDLCOption_vtbl *)4;
  v6 = valueInteger != 0;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v6;
  this->__vftable = (idMainMenu::idSWFScriptFunction_showDLCOption_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_hasNewDLC@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DAEAC0
// RVA : 0x00DAEAC0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_hasNewDLC *__fastcall idMainMenu::idSWFScriptFunction_hasNewDLC::Call(
        idMainMenu::idSWFScriptFunction_hasNewDLC *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v5; // r30

  v5 = ((int (__fastcall *)(idSession *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))session->GetSystemMarketplaceHasNewContent)(
         a1: session,
         a2: result,
         a3: thisObject,
         a4: parms);
  this->__vftable = (idMainMenu::idSWFScriptFunction_hasNewDLC_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v5;
  this->__vftable = (idMainMenu::idSWFScriptFunction_hasNewDLC_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_showCredits@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DAEB30
// RVA : 0x00DAEB30
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_showCredits *__fastcall idMainMenu::idSWFScriptFunction_showCredits::Call(
        idMainMenu::idSWFScriptFunction_showCredits *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idLocalUser *v5; // r4

  v5 = (idLocalUser *)((int (__fastcall *)(idCommon *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))common->GetMasterLocalUser)(
                        a1: common,
                        a2: result,
                        a3: thisObject,
                        a4: parms);
  if ( v5 != nullptr
    && idRageMetrics::GetStatInt(this: clientGame->rageMetrics, user: v5, stat: RAGE_STAT_GAME_COMPLETED) > 0 )
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_showCredits_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = 1;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_showCredits_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = 0;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_showCredits_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_hasContentPack@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DAEBE8
// RVA : 0x00DAEBE8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_hasContentPack *__fastcall idMainMenu::idSWFScriptFunction_hasContentPack::Call(
        idMainMenu::idSWFScriptFunction_hasContentPack *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char IsDLCStateActive; // r30
  gameDLCState_t v6; // r3

  IsDLCStateActive = 0;
  if ( parms->num == 1 )
  {
    v6 = idSWFScriptVar::ToInteger(this: parms->list);
    IsDLCStateActive = idGameLocal::IsDLCStateActive(this: gameLocal, dlcState: v6);
    this->__vftable = (idMainMenu::idSWFScriptFunction_hasContentPack_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_hasContentPack_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_hasContentPack_vtbl *)5;
  HIBYTE(this->pThis) = IsDLCStateActive;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getChapterList@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DAEC88
// RVA : 0x00DAEC88
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getChapterList *__fastcall idMainMenu::idSWFScriptFunction_getChapterList::Call(
        idMainMenu::idSWFScriptFunction_getChapterList *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idList<idDeclChapter const *,5> *p_chapters; // r20
  int (*GetProfileFromMasterLocalUser)(void); // r8
  idSWFScriptObject *v6; // r28
  idMem *v7; // r22
  int v8; // r29
  idMainMenu *mainMenu; // r11
  int v10; // r27
  const idDeclSecretType *v11; // r30
  idSWFScriptObject *v12; // r3
  idSWFScriptVar::swfScriptVarValue_t v13; // r17
  idSWFScriptObject *v14; // r30
  idSWF *v16; // r11
  int v18; // r25
  const char *v19; // r20
  _DWORD *v20; // r30
  idSWFScriptObject *v21; // r3
  idSWFScriptObject *v22; // r3
  idSWFScriptObject *v23; // r29
  int v24; // r24
  char *v25; // r15
  int v26; // r25
  int *v27; // r26
  idSWFScriptObject *v28; // r3
  idSWFScriptObject *v29; // r27
  idSWFScriptVar::swfScriptVarValue_t v30; // r28
  idSWFScriptVar *v31; // r3
  _DWORD *v32; // r28
  int v33; // r30
  int v34; // r29
  idStr *v35; // r3
  idStr *v36; // r30
  int allocedAndFlag; // r11
  int len; // r29
  int v39; // r4
  int v40; // r9
  char *v41; // r10
  char v42; // r11
  idSWFScriptVar::swfScriptVarValue_t v43; // r11
  const char *v44; // r4
  idStr *v45; // r29
  idStr *v46; // r3
  idStr *v47; // r30
  int v48; // r28
  int v49; // r4
  int v50; // r11
  char *v51; // r10
  int v52; // r9
  char v53; // r11
  idSWFScriptVar::swfScriptVarValue_t v54; // r11
  idSWFScriptObject *v56; // r3
  idSWFScriptObject *v57; // r30
  BOOL v58; // r24
  int v59; // r15
  idMainMenu *v60; // r11
  int v61; // r14
  const idDeclSecretType *v62; // r26
  idSWFScriptVar::swfScriptVarValue_t v63; // r27
  idSWFScriptVar::swfScriptVarValue_t v64; // r21
  idSWFScriptObject *v65; // r3
  idSWFScriptObject *v66; // r19
  int v67; // r17
  int v68; // r20
  int num; // r10
  int v70; // r22
  int v71; // r11
  _DWORD *v72; // r24
  int v73; // r23
  int v74; // r25
  idResource *v75; // r3
  idResource *v76; // r30
  idAtomicString *v77; // r10
  const idList<idAtomicString,5> *v78; // r3
  idResourceList **p_resourceListPtr; // r29
  int v80; // r28
  int v81; // r30
  const char *str; // r4
  int v83; // r3
  char v84; // r11
  int v85; // r4
  idPlayerProfileGame *v86; // r3
  idSWFScriptObject *v88; // r29
  int v89; // r25
  idSWFScriptVar::swfScriptVarValue_t v91; // r30
  idSWFScriptVar *v92; // r3
  unsigned int v93; // r30
  bool v96; // zf
  idSWF *v97; // r11
  bool v100; // [sp+50h] [-A70h]
  _DWORD *v101; // [sp+58h] [-A68h]
  const char **v102; // [sp+60h] [-A60h]
  idSWFScriptObject *v103; // [sp+64h] [-A5Ch]
  int v104; // [sp+68h] [-A58h]
  idSWFScriptObject *v105; // [sp+6Ch] [-A54h]
  idSWFScriptVar v106; // [sp+78h] [-A48h] BYREF
  idSWFScriptVar v107; // [sp+80h] [-A40h] BYREF
  idSWFScriptVar v108; // [sp+88h] [-A38h] BYREF
  idSWFScriptVar v109; // [sp+90h] [-A30h] BYREF
  idSWFScriptVar v110; // [sp+98h] [-A28h] BYREF
  idSWFScriptVar v111; // [sp+A0h] [-A20h] BYREF
  idSWFScriptVar v112; // [sp+A8h] [-A18h] BYREF
  idSWFScriptVar v113; // [sp+B0h] [-A10h] BYREF
  char *v114; // [sp+B8h] [-A08h]
  idSWFScriptVar v115; // [sp+C0h] [-A00h] BYREF
  idSWFScriptVar v116; // [sp+C8h] [-9F8h] BYREF
  idSWFScriptVar v117; // [sp+D0h] [-9F0h] BYREF
  unsigned __int64 v118; // [sp+D8h] [-9E8h] BYREF
  idSWFScriptVar v119; // [sp+E0h] [-9E0h] BYREF
  idPlayerProfileGame *v120; // [sp+E8h] [-9D8h]
  idSWFScriptVar v121; // [sp+F0h] [-9D0h] BYREF
  idSWFScriptObject *v122; // [sp+F8h] [-9C8h]
  idSWFScriptVar v123; // [sp+100h] [-9C0h] BYREF
  char *v124; // [sp+108h] [-9B8h]
  idSWFScriptVar v125; // [sp+110h] [-9B0h] BYREF
  idSWFScriptVar v126; // [sp+118h] [-9A8h] BYREF
  idSWFScriptVar v127; // [sp+120h] [-9A0h] BYREF
  idSWFScriptObject *v128; // [sp+128h] [-998h]
  idSWFScriptVar v129; // [sp+130h] [-990h] BYREF
  idList<idDeclChapter const *,5> *v130; // [sp+138h] [-988h]
  idSWFScriptVar v131; // [sp+140h] [-980h] BYREF
  const char *v132; // [sp+148h] [-978h]
  idSWFScriptVar v133; // [sp+150h] [-970h] BYREF
  const char *v134; // [sp+158h] [-968h]
  idSWFScriptVar v135; // [sp+160h] [-960h] BYREF
  idMem *v136; // [sp+168h] [-958h]
  char *v137; // [sp+16Ch] [-954h]
  char *v138; // [sp+170h] [-950h]
  char *v139; // [sp+174h] [-94Ch]
  char *v140; // [sp+178h] [-948h]
  const char *v141; // [sp+17Ch] [-944h]
  char *v142; // [sp+180h] [-940h]
  char *v143; // [sp+184h] [-93Ch]
  char *v144; // [sp+188h] [-938h]
  int v145; // [sp+190h] [-930h]
  int v146; // [sp+194h] [-92Ch]
  int v147; // [sp+198h] [-928h]
  __int16 v148; // [sp+19Ch] [-924h]
  char v149; // [sp+19Eh] [-922h]
  char v150; // [sp+19Fh] [-921h]
  idStr v151; // [sp+1A0h] [-920h] BYREF
  idStr v152; // [sp+1C0h] [-900h] BYREF
  idStr v153; // [sp+1E0h] [-8E0h] BYREF
  idStr v154; // [sp+200h] [-8C0h] BYREF
  _BYTE v155[2208]; // [sp+220h] [-8A0h] BYREF

  p_chapters = &gameLocal->mainMenu->chapters;
  GetProfileFromMasterLocalUser = (int (*)(void))common->GetProfileFromMasterLocalUser;
  v130 = p_chapters;
  v120 = (idPlayerProfileGame *)GetProfileFromMasterLocalUser();
  v6 = idSWFScriptObject::Alloc();
  idSWFScriptObject::MakeArray(this: v6);
  v7 = &mem;
  v136 = &mem;
  v8 = 0;
  mainMenu = gameLocal->mainMenu;
  if ( mainMenu->secretTypes.num > 0 )
  {
    v10 = 0;
    do
    {
      v11 = mainMenu->secretTypes.list[v10];
      if ( v11 != nullptr )
      {
        v12 = idSWFScriptObject::Alloc();
        SLODWORD(v13.f) = v11->displayName.index;
        v126.type = SWF_VAR_UNDEF;
        v14 = v12;
        idSWFScriptVar::Free(this: &v126);
        v126.value = v13;
        v126.type = SWF_VAR_STRINGID;
        idSWFScriptObject::Set(this: v14, name: "displayname", value: &v126);
        idSWFScriptVar::Free(this: &v126);
        v106.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v106);
        if ( v14 != nullptr )
        {
          v106.value.i = (int)v14;
          v106.type = SWF_VAR_OBJECT;
          ++v14->refCount;
        }
        else
        {
          v106.type = SWF_VAR_NULL;
        }
        idSWFScriptObject::Set(this: v6, index: v8, value: &v106);
        idSWFScriptVar::Free(this: &v106);
        if ( v14->refCount-- == 1 )
        {
          idSWFScriptObject::~idSWFScriptObject(this: v14);
          idMem::Free(this: &mem, ptr: v14, align: ALIGN_16);
        }
      }
      ++v8;
      ++v10;
      mainMenu = gameLocal->mainMenu;
    }
    while ( v8 < mainMenu->secretTypes.num );
  }
  v112.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v112);
  if ( v6 != nullptr )
  {
    v112.value.i = (int)v6;
    v112.type = SWF_VAR_OBJECT;
    ++v6->refCount;
  }
  else
  {
    v112.type = SWF_VAR_NULL;
  }
  idStr::idStr(this: &v153, text: "secretTypeList");
  v16 = gameLocal->mainMenu->mainMenu;
  if ( v16 != nullptr )
    idSWFScriptObject::Set(this: v16->globals, name: v153.data, value: &v112);
  idStr::FreeData(this: &v153);
  idSWFScriptVar::Free(this: &v112);
  if ( v6->refCount-- == 1 )
  {
    idSWFScriptObject::~idSWFScriptObject(this: v6);
    idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
  }
  v103 = idSWFScriptObject::Alloc();
  idSWFScriptObject::MakeArray(this: v103);
  v104 = 0;
  if ( p_chapters->num > 0 )
  {
    v18 = 0;
    v19 = "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag";
    v141 = "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag";
    v138 = "variations";
    v134 = "w:\\tech5\\shared\\idlib\\text/Str.h";
    v132 = "amount <= GetAlloced()";
    v142 = "found";
    v143 = "total";
    v139 = "map";
    v137 = "layer";
    v140 = ",";
    v124 = "unlocked";
    v144 = "variationIndex";
    v114 = "chapterIndex";
    do
    {
      v20 = &v130->list[v18]->__vftable;
      v101 = v20;
      v21 = (idSWFScriptObject *)idMem::AllocWithLocation(
                                   this: v7,
                                   location: v19,
                                   size: 0x60u,
                                   tag: TAG_SWF,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
      if ( v21 != nullptr )
        v122 = idSWFScriptObject::idSWFScriptObject(this: v21);
      else
        v122 = nullptr;
      v100 = false;
      v22 = (idSWFScriptObject *)idMem::AllocWithLocation(
                                   this: v7,
                                   location: v19,
                                   size: 0x60u,
                                   tag: TAG_SWF,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
      if ( v22 != nullptr )
        v23 = idSWFScriptObject::idSWFScriptObject(this: v22);
      else
        v23 = nullptr;
      v105 = v23;
      idSWFScriptObject::MakeArray(this: v23);
      v24 = 0;
      if ( (int)v20[31] > 0 )
      {
        v25 = v124;
        v26 = 0;
        do
        {
          v27 = (int *)(v20[30] + v26);
          v28 = (idSWFScriptObject *)idMem::AllocWithLocation(
                                       this: v7,
                                       location: v19,
                                       size: 0x60u,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
          if ( v28 != nullptr )
            v29 = idSWFScriptObject::idSWFScriptObject(this: v28);
          else
            v29 = nullptr;
          v30.i = v27[1];
          v115.type = SWF_VAR_UNDEF;
          idSWFScriptVar::Free(this: &v115);
          v115.value = v30;
          v115.type = SWF_VAR_STRINGID;
          idSWFScriptObject::Set(this: v29, name: "displayname", value: &v115);
          idSWFScriptVar::Free(this: &v115);
          v116.type = SWF_VAR_UNDEF;
          idSWFScriptVar::Free(this: &v116);
          v116.value.i = v104;
          v116.type = SWF_VAR_INTEGER;
          idSWFScriptObject::Set(this: v29, name: v114, value: &v116);
          idSWFScriptVar::Free(this: &v116);
          v117.type = SWF_VAR_UNDEF;
          idSWFScriptVar::Free(this: &v117);
          v117.value.i = v104;
          v117.type = SWF_VAR_INTEGER;
          idSWFScriptObject::Set(this: v29, name: v144, value: &v117);
          idSWFScriptVar::Free(this: &v117);
          if ( idPlayerProfileGame::GetProgress(this: v120, variationId: *v27) )
          {
            v119.type = SWF_VAR_UNDEF;
            v100 = true;
            idSWFScriptVar::Free(this: &v119);
            v119.type = SWF_VAR_BOOL;
            v119.value.b = true;
            idSWFScriptObject::Set(this: v29, name: v25, value: &v119);
            v31 = &v119;
          }
          else
          {
            v121.type = SWF_VAR_UNDEF;
            idSWFScriptVar::Free(this: &v121);
            v121.type = SWF_VAR_BOOL;
            v121.value.b = false;
            idSWFScriptObject::Set(this: v29, name: v25, value: &v121);
            v31 = &v121;
          }
          idSWFScriptVar::Free(this: v31);
          if ( v27[3] != 0 )
          {
            v151.allocedAndFlag = 20;
            v151.len = 0;
            v151.data = v151.baseBuffer;
            v151.baseBuffer[0] = 0;
            v32 = (_DWORD *)v27[2];
            v33 = 0;
            if ( (int)v32[1] > 0 )
            {
              v34 = 0;
              do
              {
                if ( v33 != 0 )
                  idStr::Append(this: &v151, text: v140);
                idStr::Append(this: &v151, text: *(char **)(*v32 + v34));
                ++v33;
                v34 += 4;
              }
              while ( v33 < v32[1] );
            }
            v123.type = SWF_VAR_UNDEF;
            idSWFScriptVar::Free(this: &v123);
            v123.type = SWF_VAR_STRING;
            v35 = (idStr *)idMem::AllocWithLocation(
                             this: v7,
                             location: v19,
                             size: 0x24u,
                             tag: TAG_SWF,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
            v36 = v35;
            if ( v35 != nullptr )
            {
              v35->allocedAndFlag = 20;
              v35->len = 0;
              v35->data = v35->baseBuffer;
              v35->baseBuffer[0] = 0;
              allocedAndFlag = v35->allocedAndFlag;
              len = v151.len;
              v39 = v151.len + 1;
              if ( allocedAndFlag >= 0 )
              {
                if ( v39 > (allocedAndFlag & 0x7FFFFFFF) )
                  idStr::ReAllocate(this: v35, amount: v39, keepold: true);
              }
              else if ( v39 > (allocedAndFlag & 0x7FFFFFFF)
                     && AssertFailed(file: v134, line: 463, expression: v132, inlineBreak: true) )
              {
                __trap();
              }
              v40 = (int)(v36->data - 1);
              v41 = v151.data - 1;
              do
              {
                v42 = *++v41;
                *(_BYTE *)++v40 = *v41;
              }
              while ( v42 != 0 );
              v36->len = len;
              v43.i = (int)v36;
              v36[1].len = 1;
            }
            else
            {
              v43.i = 0;
            }
            v123.value = v43;
            idSWFScriptObject::Set(this: v29, name: v137, value: &v123);
            idSWFScriptVar::Free(this: &v123);
            v44 = *(const char **)(v27[2] + 16);
            v125.type = SWF_VAR_UNDEF;
            v45 = idStr::idStr(this: &v154, text: v44);
            idSWFScriptVar::Free(this: &v125);
            v125.type = SWF_VAR_STRING;
            v46 = (idStr *)idMem::AllocWithLocation(
                             this: v7,
                             location: v19,
                             size: 0x24u,
                             tag: TAG_SWF,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
            v47 = v46;
            if ( v46 != nullptr )
            {
              v46->allocedAndFlag = 20;
              v46->len = 0;
              v46->data = v46->baseBuffer;
              v46->baseBuffer[0] = 0;
              v48 = v45->len;
              v49 = v45->len + 1;
              v50 = v46->allocedAndFlag;
              if ( v50 >= 0 )
              {
                if ( v49 > (v50 & 0x7FFFFFFF) )
                  idStr::ReAllocate(this: v46, amount: v49, keepold: true);
              }
              else if ( v49 > (v50 & 0x7FFFFFFF)
                     && AssertFailed(file: v134, line: 463, expression: v132, inlineBreak: true) )
              {
                __trap();
              }
              v51 = v45->data - 1;
              v52 = (int)(v47->data - 1);
              do
              {
                v53 = *++v51;
                *(_BYTE *)++v52 = *v51;
              }
              while ( v53 != 0 );
              v47->len = v48;
              v54.i = (int)v47;
              v47[1].len = 1;
            }
            else
            {
              v54.i = 0;
            }
            v125.value = v54;
            idStr::FreeData(this: &v154);
            idSWFScriptObject::Set(this: v29, name: v139, value: &v125);
            idSWFScriptVar::Free(this: &v125);
            idStr::FreeData(this: &v151);
            v23 = v105;
            v20 = v101;
          }
          v109.type = SWF_VAR_UNDEF;
          idSWFScriptVar::Free(this: &v109);
          if ( v29 != nullptr )
          {
            v109.value.i = (int)v29;
            v109.type = SWF_VAR_OBJECT;
            ++v29->refCount;
          }
          else
          {
            v109.type = SWF_VAR_NULL;
          }
          idSWFScriptObject::Set(this: v23, index: v24, value: &v109);
          idSWFScriptVar::Free(this: &v109);
          if ( v29->refCount-- == 1 )
          {
            idSWFScriptObject::~idSWFScriptObject(this: v29);
            idMem::Free(this: v7, ptr: v29, align: ALIGN_16);
          }
          ++v24;
          v26 += 28;
        }
        while ( v24 < v20[31] );
      }
      v56 = (idSWFScriptObject *)idMem::AllocWithLocation(
                                   this: v7,
                                   location: v19,
                                   size: 0x60u,
                                   tag: TAG_SWF,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
      if ( v56 != nullptr )
        v57 = idSWFScriptObject::idSWFScriptObject(this: v56);
      else
        v57 = nullptr;
      v128 = v57;
      idSWFScriptObject::MakeArray(this: v57);
      v58 = v100;
      if ( v100 )
      {
        memset(v155, 0, 2048);
        v59 = 0;
        v60 = gameLocal->mainMenu;
        if ( v60->secretTypes.num > 0 )
        {
          v61 = 0;
          do
          {
            v62 = v60->secretTypes.list[v61];
            if ( v62 != nullptr )
            {
              v63.i = 0;
              v64.i = 0;
              v65 = (idSWFScriptObject *)idMem::AllocWithLocation(
                                           this: v7,
                                           location: v19,
                                           size: 0x60u,
                                           tag: TAG_SWF,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
              if ( v65 != nullptr )
                v66 = idSWFScriptObject::idSWFScriptObject(this: v65);
              else
                v66 = nullptr;
              v67 = 0;
              if ( (int)v101[31] > 0 )
              {
                v68 = 0;
                num = idDeclSecrets::resourceList.num;
                do
                {
                  v70 = 0;
                  v71 = v101[30] + v68;
                  v72 = (_DWORD *)(v71 + 8);
                  if ( *(int *)(v71 + 12) > 0 )
                  {
                    v148 = 0;
                    v150 = 0;
                    v73 = 0;
                    v149 = 5;
                    v145 = 0;
                    v147 = 0;
                    v146 = 0;
                    do
                    {
                      v74 = 0;
                      if ( num > 0 )
                      {
                        do
                        {
                          v75 = idResourceList::Index(this: &idDeclSecrets::resourceList, index: v74);
                          v76 = v75;
                          if ( v75 != nullptr )
                          {
                            v77 = *((idAtomicString **)&v75[1] + 8);
                            v78 = (const idList<idAtomicString,5> *)(*v72 + v73);
                            if ( v77 == v78[1].list
                              && (unsigned __int8)idDeclChapter::ContainsAll<idList<idAtomicString,5>,idList<idAtomicString,5>>(
                                                    haystack: v78,
                                                    needles: (const idList<idAtomicString,5> *)&v76[2]) != 0 )
                            {
                              p_resourceListPtr = &v76[2].resourceListPtr;
                              v80 = 0;
                              if ( (int)v76[2].resourceError > 0 )
                              {
                                v81 = 0;
                                do
                                {
                                  str = v62->name.str;
                                  v102 = (const char **)((char *)&(*p_resourceListPtr)->resourceTypeName + v81 * 4);
                                  if ( *v102 == str || (v83 = idStr::Cmp(s1: *v102, s2: str), v84 = 0, v83 == 0) )
                                    v84 = 1;
                                  if ( v84 != 0 )
                                  {
                                    v85 = (int)(&(*p_resourceListPtr)->__vftable)[v81];
                                    if ( v155[v85] == 0 )
                                    {
                                      v86 = v120;
                                      ++v63.i;
                                      v155[v85] = 1;
                                      if ( idPlayerProfileGame::GetSecret(this: v86, secretId: v85) )
                                        ++v64.i;
                                    }
                                  }
                                  ++v80;
                                  v81 += 3;
                                }
                                while ( v80 < (int)p_resourceListPtr[1] );
                              }
                            }
                          }
                          ++v74;
                          num = idDeclSecrets::resourceList.num;
                        }
                        while ( v74 < idDeclSecrets::resourceList.num );
                      }
                      ++v70;
                      v73 += 20;
                    }
                    while ( v70 < v72[1] );
                  }
                  ++v67;
                  v68 += 28;
                }
                while ( v67 < v101[31] );
                v57 = v128;
                v19 = v141;
                v7 = v136;
              }
              v127.type = SWF_VAR_UNDEF;
              idSWFScriptVar::Free(this: &v127);
              v127.value = v63;
              v127.type = SWF_VAR_INTEGER;
              idSWFScriptObject::Set(this: v66, name: v143, value: &v127);
              idSWFScriptVar::Free(this: &v127);
              v129.type = SWF_VAR_UNDEF;
              idSWFScriptVar::Free(this: &v129);
              v129.value = v64;
              v129.type = SWF_VAR_INTEGER;
              idSWFScriptObject::Set(this: v66, name: v142, value: &v129);
              idSWFScriptVar::Free(this: &v129);
              v111.type = SWF_VAR_UNDEF;
              idSWFScriptVar::Free(this: &v111);
              if ( v66 != nullptr )
              {
                v111.value.i = (int)v66;
                v111.type = SWF_VAR_OBJECT;
                ++v66->refCount;
              }
              else
              {
                v111.type = SWF_VAR_NULL;
              }
              idSWFScriptObject::Set(this: v57, index: v59, value: &v111);
              idSWFScriptVar::Free(this: &v111);
              if ( v66->refCount-- == 1 )
              {
                idSWFScriptObject::~idSWFScriptObject(this: v66);
                idMem::Free(this: v7, ptr: v66, align: ALIGN_16);
              }
            }
            ++v59;
            ++v61;
            v60 = gameLocal->mainMenu;
          }
          while ( v59 < v60->secretTypes.num );
          v58 = v100;
        }
      }
      v131.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v131);
      v131.type = SWF_VAR_BOOL;
      v131.value.b = v100;
      v88 = v122;
      idSWFScriptObject::Set(this: v122, name: v124, value: &v131);
      idSWFScriptVar::Free(this: &v131);
      v133.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v133);
      v89 = v104;
      v133.type = SWF_VAR_INTEGER;
      v133.value.i = v104;
      idSWFScriptObject::Set(this: v88, name: v114, value: &v133);
      idSWFScriptVar::Free(this: &v133);
      v113.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v113);
      if ( v105 != nullptr )
      {
        v113.value.i = (int)v105;
        v113.type = SWF_VAR_OBJECT;
        ++v105->refCount;
      }
      else
      {
        v113.type = SWF_VAR_NULL;
      }
      idSWFScriptObject::Set(this: v88, name: v138, value: &v113);
      idSWFScriptVar::Free(this: &v113);
      v107.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v107);
      if ( v57 != nullptr )
      {
        v107.value.i = (int)v57;
        v107.type = SWF_VAR_OBJECT;
        ++v57->refCount;
      }
      else
      {
        v107.type = SWF_VAR_NULL;
      }
      idSWFScriptObject::Set(this: v88, name: "secrets", value: &v107);
      idSWFScriptVar::Free(this: &v107);
      if ( v57->refCount-- == 1 )
      {
        idSWFScriptObject::~idSWFScriptObject(this: v57);
        idMem::Free(this: v7, ptr: v57, align: ALIGN_16);
      }
      if ( v58 )
      {
        LODWORD(v91.f) = (idSWFScriptVar::swfScriptVarValue_t)v101[17];
        v135.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v135);
        v135.value = v91;
        v135.type = SWF_VAR_STRINGID;
        idSWFScriptObject::Set(this: v88, name: "displayname", value: &v135);
        v92 = &v135;
      }
      else
      {
        v93 = v101[18];
        HIDWORD(v118) = 4;
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v118);
        v118 = v93;
        idSWFScriptObject::Set(this: v88, name: "displayname", value: (idSWFScriptVar *)&v118);
        v92 = (idSWFScriptVar *)&v118;
      }
      idSWFScriptVar::Free(this: v92);
      if ( v105->refCount-- == 1 )
      {
        idSWFScriptObject::~idSWFScriptObject(this: v105);
        idMem::Free(this: v7, ptr: v105, align: ALIGN_16);
      }
      v108.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v108);
      if ( v88 != nullptr )
      {
        v108.value.i = (int)v88;
        v108.type = SWF_VAR_OBJECT;
        ++v88->refCount;
      }
      else
      {
        v108.type = SWF_VAR_NULL;
      }
      idSWFScriptObject::Set(this: v103, index: v104, value: &v108);
      idSWFScriptVar::Free(this: &v108);
      if ( v88->refCount-- == 1 )
      {
        idSWFScriptObject::~idSWFScriptObject(this: v88);
        idMem::Free(this: v7, ptr: v88, align: ALIGN_16);
      }
      ++v104;
      v96 = v89 + 1 < v130->num;
      v18 = v89 + 1;
    }
    while ( v96 );
  }
  v110.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v110);
  if ( v103 != nullptr )
  {
    v110.value.i = (int)v103;
    v110.type = SWF_VAR_OBJECT;
    ++v103->refCount;
  }
  else
  {
    v110.type = SWF_VAR_NULL;
  }
  idStr::idStr(this: &v152, text: "chapterList");
  v97 = gameLocal->mainMenu->mainMenu;
  if ( v97 != nullptr )
    idSWFScriptObject::Set(this: v97->globals, name: v152.data, value: &v110);
  idStr::FreeData(this: &v152);
  idSWFScriptVar::Free(this: &v110);
  if ( v103->refCount-- == 1 )
  {
    idSWFScriptObject::~idSWFScriptObject(this: v103);
    idMem::Free(this: v7, ptr: v103, align: ALIGN_16);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_getChapterList_vtbl *)4;
  return this;
}


// ========================================================================
// __unwind$533567
// EA  : 0x82DAFB6C
// RVA : 0x00DAFB6C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533567()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 280));
}


// ========================================================================
// __unwind$533568
// EA  : 0x82DAFB94
// RVA : 0x00DAFB94
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533568()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 120));
}


// ========================================================================
// __unwind$533569
// EA  : 0x82DAFBBC
// RVA : 0x00DAFBBC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533569()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 168));
}


// ========================================================================
// __unwind$533570
// EA  : 0x82DAFBE4
// RVA : 0x00DAFBE4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533570()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2752 + 480));
}


// ========================================================================
// __unwind$533787
// EA  : 0x82DAFC0C
// RVA : 0x00DAFC0C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533787()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2752 + 84), tag: TAG_SWF);
}


// ========================================================================
// __unwind$533804
// EA  : 0x82DAFC38
// RVA : 0x00DAFC38
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533804()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2752 + 84), tag: TAG_SWF);
}


// ========================================================================
// __unwind$533834
// EA  : 0x82DAFC64
// RVA : 0x00DAFC64
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533834()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2752 + 84), tag: TAG_SWF);
}


// ========================================================================
// __unwind$533571
// EA  : 0x82DAFC90
// RVA : 0x00DAFC90
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533571()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 192));
}


// ========================================================================
// __unwind$533572
// EA  : 0x82DAFCB8
// RVA : 0x00DAFCB8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533572()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 200));
}


// ========================================================================
// __unwind$533573
// EA  : 0x82DAFCE0
// RVA : 0x00DAFCE0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533573()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 208));
}


// ========================================================================
// __unwind$533574
// EA  : 0x82DAFD08
// RVA : 0x00DAFD08
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533574()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 224));
}


// ========================================================================
// __unwind$533575
// EA  : 0x82DAFD30
// RVA : 0x00DAFD30
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533575()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 240));
}


// ========================================================================
// __unwind$533576
// EA  : 0x82DAFD58
// RVA : 0x00DAFD58
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533576()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2752 + 416));
}


// ========================================================================
// __unwind$533987
// EA  : 0x82DAFD80
// RVA : 0x00DAFD80
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533987()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2752 + 84), tag: TAG_SWF);
}


// ========================================================================
// __unwind$533577
// EA  : 0x82DAFDAC
// RVA : 0x00DAFDAC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533577()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 256));
}


// ========================================================================
// __unwind$534208
// EA  : 0x82DAFDD4
// RVA : 0x00DAFDD4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_534208()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2752 + 512));
}


// ========================================================================
// __unwind$534215
// EA  : 0x82DAFDFC
// RVA : 0x00DAFDFC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_534215()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2752 + 84), tag: TAG_SWF);
}


// ========================================================================
// __unwind$533578
// EA  : 0x82DAFE28
// RVA : 0x00DAFE28
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533578()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 272));
}


// ========================================================================
// __unwind$533579
// EA  : 0x82DAFE50
// RVA : 0x00DAFE50
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533579()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 144));
}


// ========================================================================
// __unwind$534486
// EA  : 0x82DAFE78
// RVA : 0x00DAFE78
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_534486()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2752 + 84), tag: TAG_SWF);
}


// ========================================================================
// __unwind$534518
// EA  : 0x82DAFEA4
// RVA : 0x00DAFEA4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_534518()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2752 + 96), tag: TAG_SWF);
}


// ========================================================================
// __unwind$533580
// EA  : 0x82DAFED0
// RVA : 0x00DAFED0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533580()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2752 + 400));
}


// ========================================================================
// __unwind$533581
// EA  : 0x82DAFEF8
// RVA : 0x00DAFEF8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533581()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 288));
}


// ========================================================================
// __unwind$533582
// EA  : 0x82DAFF20
// RVA : 0x00DAFF20
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533582()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 304));
}


// ========================================================================
// __unwind$533583
// EA  : 0x82DAFF48
// RVA : 0x00DAFF48
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533583()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 160));
}


// ========================================================================
// __unwind$533584
// EA  : 0x82DAFF70
// RVA : 0x00DAFF70
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533584()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 320));
}


// ========================================================================
// __unwind$533585
// EA  : 0x82DAFF98
// RVA : 0x00DAFF98
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533585()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 336));
}


// ========================================================================
// __unwind$533586
// EA  : 0x82DAFFC0
// RVA : 0x00DAFFC0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533586()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 176));
}


// ========================================================================
// __unwind$533587
// EA  : 0x82DAFFE8
// RVA : 0x00DAFFE8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533587()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 128));
}


// ========================================================================
// __unwind$533588
// EA  : 0x82DB0010
// RVA : 0x00DB0010
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533588()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 352));
}


// ========================================================================
// __unwind$533589
// EA  : 0x82DB0038
// RVA : 0x00DB0038
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533589()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 216));
}


// ========================================================================
// __unwind$533590
// EA  : 0x82DB0060
// RVA : 0x00DB0060
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533590()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 136));
}


// ========================================================================
// __unwind$533591
// EA  : 0x82DB0088
// RVA : 0x00DB0088
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533591()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2752 + 152));
}


// ========================================================================
// __unwind$533592
// EA  : 0x82DB00B0
// RVA : 0x00DB00B0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_533592()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2752 + 448));
}


// ========================================================================
// ?Call@idSWFScriptFunction_isLookInverted@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB00D8
// RVA : 0x00DB00D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_isLookInverted *__fastcall idMainMenu::idSWFScriptFunction_isLookInverted::Call(
        idMainMenu::idSWFScriptFunction_isLookInverted *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r3
  idPlayerProfileGame *PlayerProfileByInputDevice; // r3
  bool InvertLook; // r30
  int valueInteger; // r11

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for isLookInverted", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_isLookInverted_vtbl *)4;
  }
  else
  {
    v5 = ((int (__fastcall *)(idCommon *, idSWFScriptVar *, idSWFScriptObject *))common->GetFocusDeviceNum)(
           a1: common,
           a2: result,
           a3: thisObject);
    PlayerProfileByInputDevice = (idPlayerProfileGame *)idSignInManagerBase::GetPlayerProfileByInputDevice(
                                                          this: session->signInManager,
                                                          index: v5);
    if ( PlayerProfileByInputDevice != nullptr )
    {
      InvertLook = idPlayerProfileGame::GetInvertLook(this: PlayerProfileByInputDevice);
      this->__vftable = (idMainMenu::idSWFScriptFunction_isLookInverted_vtbl *)4;
    }
    else
    {
      valueInteger = in_invertLook.valueInteger;
      this->__vftable = (idMainMenu::idSWFScriptFunction_isLookInverted_vtbl *)4;
      InvertLook = valueInteger != 0;
    }
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->__vftable = (idMainMenu::idSWFScriptFunction_isLookInverted_vtbl *)5;
    HIBYTE(this->pThis) = InvertLook;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setBindingWait@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB01C0
// RVA : 0x00DB01C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setBindingWait *__fastcall idMainMenu::idSWFScriptFunction_setBindingWait::Call(
        idMainMenu::idSWFScriptFunction_setBindingWait *this,
        idSWFScriptVar *result,
        __int64 parms,
        __int64 a4)
{
  idSWFScriptVar **v6; // r26
  idSWFScriptVar *v7; // r24
  size_t type; // r29
  idStr *v9; // r30
  idStr v11[3]; // [sp+60h] [-70h] BYREF

  v6 = (idSWFScriptVar **)parms;
  LODWORD(a4) = gameLocal->mainMenu;
  if ( (_DWORD)a4 != 0 )
  {
    if ( *(_DWORD *)(parms + 4) == 2 )
    {
      v7 = idSWFScriptVar::ToString(
             this: (idSWFScriptVar *)v11,
             result: *(idStr **)parms,
             a3: parms,
             a4,
             a5: 0x153B8000150000LL);
      type = v7->type;
      v9 = (idStr *)(result->value.i + 748);
      idStr::EnsureAlloced(this: v9, amount: v7->type + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v9->data, Src: v7->value.object, Size: type);
      v9->data[type] = 0;
      v9->len = type;
      idStr::FreeData(this: v11);
      *(_DWORD *)(result->value.i + 780) = idSWFScriptVar::ToInteger(this: *v6 + 1);
      *(_BYTE *)(result->value.i + 740) = 1;
      this->__vftable = (idMainMenu::idSWFScriptFunction_setBindingWait_vtbl *)4;
    }
    else
    {
      *(_BYTE *)(result->value.i + 740) = 0;
      this->__vftable = (idMainMenu::idSWFScriptFunction_setBindingWait_vtbl *)4;
    }
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_setBindingWait_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = 0;
    this->__vftable = (idMainMenu::idSWFScriptFunction_setBindingWait_vtbl *)5;
  }
  return this;
}


// ========================================================================
// __unwind$535371_0
// EA  : 0x82DB02C4
// RVA : 0x00DB02C4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_535371_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_canScroll@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB02F0
// RVA : 0x00DB02F0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_canScroll *__fastcall idMainMenu::idSWFScriptFunction_canScroll::Call(
        idMainMenu::idSWFScriptFunction_canScroll *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char CanScrollMenu; // r30

  CanScrollMenu = 0;
  if ( gameLocal->mainMenu != nullptr )
    CanScrollMenu = idMainMenu::CanScrollMenu(this: (idMainMenu *)result->value.i);
  this->__vftable = (idMainMenu::idSWFScriptFunction_canScroll_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = CanScrollMenu;
  this->__vftable = (idMainMenu::idSWFScriptFunction_canScroll_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_GetSafeFrameScale@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB0370
// RVA : 0x00DB0370
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_GetSafeFrameScale *__fastcall idMainMenu::idSWFScriptFunction_GetSafeFrameScale::Call(
        idMainMenu::idSWFScriptFunction_GetSafeFrameScale *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  double valueFloat; // fp31

  valueFloat = swf_safeFrame.valueFloat;
  this->__vftable = (idMainMenu::idSWFScriptFunction_GetSafeFrameScale_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  this->__vftable = (idMainMenu::idSWFScriptFunction_GetSafeFrameScale_vtbl *)6;
  this->pThis = (idMainMenu *)(1 - (int)(float)((float)((float)valueFloat * (float)13.333333) * (float)-100.0));
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getGammaValue@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB03F0
// RVA : 0x00DB03F0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getGammaValue *__fastcall idMainMenu::idSWFScriptFunction_getGammaValue::Call(
        idMainMenu::idSWFScriptFunction_getGammaValue *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idPlayerProfileGame *v5; // r3
  double GammaValue; // fp1
  double v7; // fp31

  v5 = (idPlayerProfileGame *)((int (__fastcall *)(idCommon *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))common->GetProfileFromMasterLocalUser)(
                                a1: common,
                                a2: result,
                                a3: thisObject,
                                a4: parms);
  GammaValue = idPlayerProfileGame::GetGammaValue(this: v5);
  this->__vftable = (idMainMenu::idSWFScriptFunction_getGammaValue_vtbl *)4;
  v7 = (float)((float)GammaValue * (float)100.0);
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  *(float *)&this->pThis = v7;
  this->__vftable = (idMainMenu::idSWFScriptFunction_getGammaValue_vtbl *)2;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getAudioVolume@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB0468
// RVA : 0x00DB0468
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getAudioVolume *__fastcall idMainMenu::idSWFScriptFunction_getAudioVolume::Call(
        idMainMenu::idSWFScriptFunction_getAudioVolume *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idPlayerProfileGame *v6; // r30
  int v7; // r3
  double v8; // fp31
  double MasterVolume; // fp1
  double v10; // fp0

  v6 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v6 == nullptr || parms->num != 1 )
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_getAudioVolume_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    v10 = 0.0;
    goto LABEL_14;
  }
  v7 = idSWFScriptVar::ToInteger(this: parms->list);
  v8 = 0.0;
  switch ( v7 )
  {
    case 0:
      MasterVolume = idPlayerProfileGame::GetMasterVolume(this: v6);
LABEL_11:
      v8 = MasterVolume;
      break;
    case 1:
      MasterVolume = idPlayerProfileGame::GetMusicVolume(this: v6);
      goto LABEL_11;
    case 2:
      MasterVolume = idPlayerProfileGame::GetVoiceVolume(this: v6);
      goto LABEL_11;
    case 3:
      MasterVolume = idPlayerProfileGame::GetAmbientVolume(this: v6);
      goto LABEL_11;
    default:
      break;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_getAudioVolume_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  v10 = (float)((float)v8 * (float)100.0);
LABEL_14:
  *(float *)&this->pThis = v10;
  this->__vftable = (idMainMenu::idSWFScriptFunction_getAudioVolume_vtbl *)2;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_subtitlesEnabled@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB0568
// RVA : 0x00DB0568
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_subtitlesEnabled *__fastcall idMainMenu::idSWFScriptFunction_subtitlesEnabled::Call(
        idMainMenu::idSWFScriptFunction_subtitlesEnabled *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v5; // r30
  int v6; // r3

  v5 = 0;
  v6 = ((int (__fastcall *)(idCommon *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))common->GetProfileFromMasterLocalUser)(
         a1: common,
         a2: result,
         a3: thisObject,
         a4: parms);
  if ( v6 != 0 )
    v5 = *(_BYTE *)(v6 + 2064);
  this->__vftable = (idMainMenu::idSWFScriptFunction_subtitlesEnabled_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v5;
  this->__vftable = (idMainMenu::idSWFScriptFunction_subtitlesEnabled_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_GetJoyPitchSpeed@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB05E0
// RVA : 0x00DB05E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_GetJoyPitchSpeed *__fastcall idMainMenu::idSWFScriptFunction_GetJoyPitchSpeed::Call(
        idMainMenu::idSWFScriptFunction_GetJoyPitchSpeed *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  double v5; // fp31
  int v6; // r3
  idPlayerProfile *PlayerProfileByInputDevice; // r3

  v5 = 0.0;
  v6 = ((int (__fastcall *)(idCommon *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))common->GetFocusDeviceNum)(
         a1: common,
         a2: result,
         a3: thisObject,
         a4: parms);
  PlayerProfileByInputDevice = idSignInManagerBase::GetPlayerProfileByInputDevice(
                                 this: session->signInManager,
                                 index: v6);
  if ( PlayerProfileByInputDevice != nullptr )
    v5 = *(float *)&PlayerProfileByInputDevice[1].state;
  this->__vftable = (idMainMenu::idSWFScriptFunction_GetJoyPitchSpeed_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  this->__vftable = (idMainMenu::idSWFScriptFunction_GetJoyPitchSpeed_vtbl *)2;
  *(float *)&this->pThis = (float)((float)((float)v5 - (float)30.0) * (float)0.0055555557) * (float)100.0;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_GetJoyYawSpeed@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB0698
// RVA : 0x00DB0698
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_GetJoyYawSpeed *__fastcall idMainMenu::idSWFScriptFunction_GetJoyYawSpeed::Call(
        idMainMenu::idSWFScriptFunction_GetJoyYawSpeed *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  double v5; // fp31
  int v6; // r3
  idPlayerProfile *PlayerProfileByInputDevice; // r3

  v5 = 0.0;
  v6 = ((int (__fastcall *)(idCommon *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))common->GetFocusDeviceNum)(
         a1: common,
         a2: result,
         a3: thisObject,
         a4: parms);
  PlayerProfileByInputDevice = idSignInManagerBase::GetPlayerProfileByInputDevice(
                                 this: session->signInManager,
                                 index: v6);
  if ( PlayerProfileByInputDevice != nullptr )
    v5 = *((float *)&PlayerProfileByInputDevice[1].__vftable + 1);
  this->__vftable = (idMainMenu::idSWFScriptFunction_GetJoyYawSpeed_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  this->__vftable = (idMainMenu::idSWFScriptFunction_GetJoyYawSpeed_vtbl *)2;
  *(float *)&this->pThis = (float)((float)((float)v5 - (float)40.0) * (float)0.0024999999) * (float)100.0;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getConfig@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB0750
// RVA : 0x00DB0750
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getConfig *__fastcall idMainMenu::idSWFScriptFunction_getConfig::Call(
        idMainMenu::idSWFScriptFunction_getConfig *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v6; // r3
  XGRAPHICS::CFG *PlayerProfileByInputDevice; // r30
  idMainMenu *Config; // r30

  v6 = common->GetFocusDeviceNum(this: common);
  PlayerProfileByInputDevice = (XGRAPHICS::CFG *)idSignInManagerBase::GetPlayerProfileByInputDevice(
                                                   this: session->signInManager,
                                                   index: v6);
  if ( PlayerProfileByInputDevice != nullptr )
  {
    if ( parms->num == 1 )
    {
      idSWFScriptVar::ToBool(this: parms->list);
      Config = (idMainMenu *)idPlayerProfileGame::GetConfig(this: PlayerProfileByInputDevice);
      this->__vftable = (idMainMenu::idSWFScriptFunction_getConfig_vtbl *)4;
      idSWFScriptVar::Free((idSWFScriptVar *)this);
      this->pThis = Config;
    }
    else
    {
      idLib::Warning(fmt: "getConfig function in MainMenuLocal needs an argument");
      this->__vftable = (idMainMenu::idSWFScriptFunction_getConfig_vtbl *)4;
      idSWFScriptVar::Free((idSWFScriptVar *)this);
      this->pThis = nullptr;
    }
    this->__vftable = (idMainMenu::idSWFScriptFunction_getConfig_vtbl *)6;
    return this;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_getConfig_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->pThis = nullptr;
    this->__vftable = (idMainMenu::idSWFScriptFunction_getConfig_vtbl *)6;
    return this;
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_getConfigText@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB0850
// RVA : 0x00DB0850
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getConfigText *__fastcall idMainMenu::idSWFScriptFunction_getConfigText::Call(
        idMainMenu::idSWFScriptFunction_getConfigText *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v7; // r3
  idSWFScriptVar *list; // r11
  int v9; // r30
  char v10; // r28
  idStrId *v11; // r3
  const char *LocalizedString; // r3
  __int64 v13; // r6
  __int64 v14; // r10
  __int64 v15; // r8
  va *v16; // r3
  int v17; // [sp+8h] [-10A8h]
  int v18; // [sp+Ch] [-10A4h]
  int v19; // [sp+10h] [-10A0h]
  int v20; // [sp+14h] [-109Ch]
  int v21; // [sp+18h] [-1098h]
  int v22; // [sp+1Ch] [-1094h]
  idStrId v23; // [sp+54h] [-105Ch] BYREF
  idStrId v24[2]; // [sp+58h] [-1058h] BYREF
  idStr v25; // [sp+60h] [-1050h] BYREF
  va v26; // [sp+80h] [-1030h] BYREF

  if ( parms->num == 2 )
  {
    v7 = idSWFScriptVar::ToInteger(this: parms->list);
    list = parms->list;
    v9 = v7;
    v10 = idSWFScriptVar::ToBool(this: list + 1);
    idStr::idStr(this: &v25, text: &byte_8200D768);
    if ( v10 != 0 )
    {
      idStrId::Set(this: &v23, key: "#str_swf_config_set_fps");
      v11 = &v23;
    }
    else
    {
      idStrId::Set(this: v24, key: "#str_swf_config_set_vehicle");
      v11 = v24;
    }
    LocalizedString = idStrId::GetLocalizedString(this: v11);
    HIDWORD(v13) = v9;
    v16 = va::va(
            this: &v26,
            fmt: LocalizedString,
            a3: v13,
            a4: v15,
            a5: v14,
            a6: v17,
            a7: v18,
            a8: v19,
            a9: v20,
            a10: v21,
            a11: v22);
    idStr::operator=(this: &v25, text: v16);
    this->__vftable = (idMainMenu::idSWFScriptFunction_getConfigText_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->__vftable = (idMainMenu::idSWFScriptFunction_getConfigText_vtbl *)1;
    this->pThis = (idMainMenu *)idSWFScriptString::Alloc(s: &v25);
    idStr::FreeData(this: &v25);
    return this;
  }
  else
  {
    idLib::Warning(fmt: "getConfigText function in MainMenuLocal needs an argument");
    idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, s: &byte_8200D768);
    return this;
  }
}


// ========================================================================
// __unwind$535696
// EA  : 0x82DB0968
// RVA : 0x00DB0968
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_535696()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 4272;
  if ( (*(_DWORD *)(v0 - 4272 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 4292));
  }
}


// ========================================================================
// __unwind$535699
// EA  : 0x82DB09AC
// RVA : 0x00DB09AC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_535699()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4272 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_getBinding@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB09E0
// RVA : 0x00DB09E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getBinding *__fastcall idMainMenu::idSWFScriptFunction_getBinding::Call(
        idMainMenu::idSWFScriptFunction_getBinding *this,
        idSWFScriptVar *result,
        __int64 parms,
        __int64 a4,
        __int64 a5)
{
  idSWFScriptVar **v6; // r30
  const char *i; // r27
  unsigned int v10; // r3
  idStr v11; // [sp+60h] [-70h] BYREF
  idStr v12[2]; // [sp+80h] [-50h] BYREF

  v6 = (idSWFScriptVar **)parms;
  LODWORD(a5) = *(_DWORD *)(parms + 4);
  if ( (_DWORD)a5 == 2 )
  {
    i = (const char *)idSWFScriptVar::ToString(this: (idSWFScriptVar *)v12, result: *(idStr **)parms, a3: parms, a4, a5)->value.i;
    idStr::FreeData(this: v12);
    v10 = idSWFScriptVar::ToInteger(this: *v6 + 1);
    idMainMenu::GetControllerBinding(this: (idMainMenu *)&v11, result: result->value.string, keyStr: i, bindSet: v10);
    idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, s: v11.data);
    idStr::FreeData(this: &v11);
  }
  else
  {
    idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, s: &byte_8200D768);
  }
  return this;
}


// ========================================================================
// __unwind$535751
// EA  : 0x82DB0A8C
// RVA : 0x00DB0A8C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_535751()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 208;
  if ( (*(_DWORD *)(v0 - 208 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 228));
  }
}


// ========================================================================
// __unwind$535755
// EA  : 0x82DB0AD0
// RVA : 0x00DB0AD0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_535755()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_getUseAimAssist@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB0AF8
// RVA : 0x00DB0AF8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getUseAimAssist *__fastcall idMainMenu::idSWFScriptFunction_getUseAimAssist::Call(
        idMainMenu::idSWFScriptFunction_getUseAimAssist *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v5; // r30
  int v6; // r3
  idPlayerProfile *PlayerProfileByInputDevice; // r3

  v5 = 0;
  v6 = ((int (__fastcall *)(idCommon *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))common->GetFocusDeviceNum)(
         a1: common,
         a2: result,
         a3: thisObject,
         a4: parms);
  PlayerProfileByInputDevice = idSignInManagerBase::GetPlayerProfileByInputDevice(
                                 this: session->signInManager,
                                 index: v6);
  if ( PlayerProfileByInputDevice != nullptr )
    v5 = BYTE1(PlayerProfileByInputDevice[1].__vftable);
  this->__vftable = (idMainMenu::idSWFScriptFunction_getUseAimAssist_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v5;
  this->__vftable = (idMainMenu::idSWFScriptFunction_getUseAimAssist_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getGamepadEnabled@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB0B88
// RVA : 0x00DB0B88
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getGamepadEnabled *__fastcall idMainMenu::idSWFScriptFunction_getGamepadEnabled::Call(
        idMainMenu::idSWFScriptFunction_getGamepadEnabled *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v5; // r30
  int v6; // r3

  v5 = 0;
  v6 = ((int (__fastcall *)(idCommon *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))common->GetProfileFromMasterLocalUser)(
         a1: common,
         a2: result,
         a3: thisObject,
         a4: parms);
  if ( v6 != 0 )
    v5 = *(_BYTE *)(v6 + 2066);
  this->__vftable = (idMainMenu::idSWFScriptFunction_getGamepadEnabled_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v5;
  this->__vftable = (idMainMenu::idSWFScriptFunction_getGamepadEnabled_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getUseVibrate@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB0C00
// RVA : 0x00DB0C00
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getUseVibrate *__fastcall idMainMenu::idSWFScriptFunction_getUseVibrate::Call(
        idMainMenu::idSWFScriptFunction_getUseVibrate *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r3
  idPlayerProfile *PlayerProfileByInputDevice; // r3
  char v7; // r30

  v5 = ((int (__fastcall *)(idCommon *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))common->GetFocusDeviceNum)(
         a1: common,
         a2: result,
         a3: thisObject,
         a4: parms);
  PlayerProfileByInputDevice = idSignInManagerBase::GetPlayerProfileByInputDevice(
                                 this: session->signInManager,
                                 index: v5);
  if ( PlayerProfileByInputDevice != nullptr )
  {
    v7 = (char)PlayerProfileByInputDevice[1].__vftable;
    this->__vftable = (idMainMenu::idSWFScriptFunction_getUseVibrate_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = v7;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_getUseVibrate_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = 1;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_getUseVibrate_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getMouseSensitivity@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB0CA0
// RVA : 0x00DB0CA0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getMouseSensitivity *__fastcall idMainMenu::idSWFScriptFunction_getMouseSensitivity::Call(
        idMainMenu::idSWFScriptFunction_getMouseSensitivity *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  double v5; // fp31
  int v6; // r3

  v5 = 0.0;
  v6 = ((int (__fastcall *)(idCommon *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))common->GetProfileFromMasterLocalUser)(
         a1: common,
         a2: result,
         a3: thisObject,
         a4: parms);
  if ( v6 != 0 )
    v5 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v6 + 20))(a1: v6);
  this->__vftable = (idMainMenu::idSWFScriptFunction_getMouseSensitivity_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  this->__vftable = (idMainMenu::idSWFScriptFunction_getMouseSensitivity_vtbl *)2;
  *(float *)&this->pThis = (float)((float)((float)v5 - (float)2.0) * (float)0.125) * (float)100.0;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getBenchmarkValue@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB0D50
// RVA : 0x00DB0D50
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getBenchmarkValue *__fastcall idMainMenu::idSWFScriptFunction_getBenchmarkValue::Call(
        idMainMenu::idSWFScriptFunction_getBenchmarkValue *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  this->__vftable = (idMainMenu::idSWFScriptFunction_getBenchmarkValue_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  this->__vftable = (idMainMenu::idSWFScriptFunction_getBenchmarkValue_vtbl *)6;
  this->pThis = (idMainMenu *)50;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_CanSaveGame@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB0D98
// RVA : 0x00DB0D98
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_CanSaveGame *__fastcall idMainMenu::idSWFScriptFunction_CanSaveGame::Call(
        idMainMenu::idSWFScriptFunction_CanSaveGame *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v5; // r30

  v5 = ((int (__fastcall *)(idGameLocal *, _DWORD, idSWFScriptObject *, const idSWFParmList *))gameLocal->MainMenu_CanSave)(
         a1: gameLocal,
         a2: 0,
         a3: thisObject,
         a4: parms);
  this->__vftable = (idMainMenu::idSWFScriptFunction_CanSaveGame_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v5;
  this->__vftable = (idMainMenu::idSWFScriptFunction_CanSaveGame_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_canContinueGame@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB0E08
// RVA : 0x00DB0E08
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_canContinueGame *__fastcall idMainMenu::idSWFScriptFunction_canContinueGame::Call(
        idMainMenu::idSWFScriptFunction_canContinueGame *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  bool v5; // r31

  v5 = hasSaveGames;
  this->__vftable = (idMainMenu::idSWFScriptFunction_canContinueGame_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v5;
  this->__vftable = (idMainMenu::idSWFScriptFunction_canContinueGame_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_loadDamagedFile@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB0E60
// RVA : 0x00DB0E60
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_loadDamagedFile *__fastcall idMainMenu::idSWFScriptFunction_loadDamagedFile::Call(
        idMainMenu::idSWFScriptFunction_loadDamagedFile *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v6; // r4

  v6 = 0;
  if ( parms->num > 0 )
    v6 = idSWFScriptVar::ToInteger(this: parms->list);
  if ( v6 < session->saveGameManager->enumeratedSaveGames.num )
    idMainMenu::LoadDamagedGame(this: (idMainMenu *)result->value.i, index: v6);
  this->__vftable = (idMainMenu::idSWFScriptFunction_loadDamagedFile_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_isEnumerating@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB0EE0
// RVA : 0x00DB0EE0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_isEnumerating *__fastcall idMainMenu::idSWFScriptFunction_isEnumerating::Call(
        idMainMenu::idSWFScriptFunction_isEnumerating *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v5; // r30

  v5 = ((int (__fastcall *)(idSession *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))session->IsEnumerating)(
         a1: session,
         a2: result,
         a3: thisObject,
         a4: parms);
  this->__vftable = (idMainMenu::idSWFScriptFunction_isEnumerating_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v5;
  this->__vftable = (idMainMenu::idSWFScriptFunction_isEnumerating_vtbl *)5;
  return this;
}


// ========================================================================
// ?TestGui_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82DB0F50
// RVA : 0x00DB0F50
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall TestGui_f(const idCmdArgs *args)
{
  char *v1; // r4

  if ( args->argc <= 1 )
    v1 = &byte_8200D768;
  else
    v1 = args->argv[1];
  idMainMenu::TestGui(this: gameLocal->mainMenu, filename: v1);
}


// ========================================================================
// ?UpdateMenuCmds@idMainMenu@@QAAXXZ
// EA  : 0x82DB0F88
// RVA : 0x00DB0F88
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateMenuCmds(idMainMenu *this)
{
  idMenuScreen *v1; // r3
  mainMenuScreens_t activeMenu; // r11

  if ( swf_useDataDrivenMenus.valueInteger != 0 && this->menuScreens[this->activeMenu] != nullptr )
  {
    v1 = this->menuScreens[this->activeMenu];
    v1->Update(this: v1);
  }
  else
  {
    activeMenu = this->activeMenu;
    if ( (unsigned int)activeMenu <= MENU_AUDIO )
    {
      switch ( activeMenu )
      {
        case MENU_ROOT:
          idMainMenu::UpdateCmds_Root(this);
          break;
        case MENU_DEV:
          idMainMenu::UpdateCmds_Dev(this);
          break;
        case MENU_CAMPAIGN:
        case MENU_MULTIPLAYER:
LABEL_18:
          break;
        case MENU_SETTINGS:
          idMainMenu::UpdateCmds_Settings(this);
          break;
        default:
          if ( activeMenu != MENU_START )
            idMainMenu::UpdateCmds_Audio(this);
          else
            idMainMenu::UpdateCmds_Start(this);
          goto LABEL_18;
      }
    }
  }
}


// ========================================================================
// ?KillStartButton@idMainMenu@@QAAXXZ
// EA  : 0x82DB1020
// RVA : 0x00DB1020
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::KillStartButton(idMainMenu *this)
{
  idSWFScriptObject *NestedObj; // r30
  idSWFScriptVar v3; // [sp+50h] [-60h] BYREF
  idSWFScriptVar v4; // [sp+58h] [-58h] BYREF
  idSWFScriptVar v5; // [sp+60h] [-50h] BYREF
  idSWFScriptVar v6[9]; // [sp+68h] [-48h] BYREF

  NestedObj = idSWFScriptObject::GetNestedObj(
                this: this->mainMenu->mainspriteInstance->scriptObject,
                arg1: "startMenu",
                arg2: "btnStart",
                arg3: nullptr,
                arg4: nullptr,
                arg5: nullptr,
                arg6: nullptr);
  if ( NestedObj != nullptr )
  {
    v3.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v3);
    v3.type = SWF_VAR_INTEGER;
    v3.value.i = 0;
    idSWFScriptObject::Set(this: NestedObj, name: "onPress", value: &v3);
    idSWFScriptVar::Free(this: &v3);
    v4.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v4);
    v4.type = SWF_VAR_INTEGER;
    v4.value.i = 0;
    idSWFScriptObject::Set(this: NestedObj, name: "onRelease", value: &v4);
    idSWFScriptVar::Free(this: &v4);
    idSWF::GetGlobal(this: (idSWF *)&v5, result: (idSWFScriptVar *)this->mainMenu, name: "shortcutKeys");
    if ( v5.type == SWF_VAR_OBJECT )
    {
      idSWFScriptVar::idSWFScriptVar(this: v6, o: NestedObj);
      idSWFScriptObject::Set(this: v5.value.object, name: "START", value: v6);
      idSWFScriptVar::Free(this: v6);
    }
    idSWFScriptVar::Free(this: &v5);
  }
}


// ========================================================================
// __unwind$536080
// EA  : 0x82DB1134
// RVA : 0x00DB1134
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_536080()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$536081
// EA  : 0x82DB115C
// RVA : 0x00DB115C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_536081()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$536082
// EA  : 0x82DB1184
// RVA : 0x00DB1184
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_536082()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$536083
// EA  : 0x82DB11AC
// RVA : 0x00DB11AC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_536083()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 104));
}


// ========================================================================
// ?ClearActiveMenuOnEnterFrame@idMainMenu@@QAAXXZ
// EA  : 0x82DB11E0
// RVA : 0x00DB11E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::ClearActiveMenuOnEnterFrame(idMainMenu *this)
{
  idSWFSpriteInstance *MenuSprite; // r3
  idSWFScriptObject *scriptObject; // r30
  idSWFScriptVar v3; // [sp+50h] [-20h] BYREF

  MenuSprite = idMainMenu::GetMenuSprite(this, type: this->activeMenu);
  if ( MenuSprite != nullptr )
  {
    scriptObject = MenuSprite->scriptObject;
    if ( scriptObject != nullptr )
    {
      v3.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v3);
      v3.type = SWF_VAR_INTEGER;
      v3.value.i = 0;
      idSWFScriptObject::Set(this: scriptObject, name: "onEnterFrame", value: &v3);
      idSWFScriptVar::Free(this: &v3);
    }
  }
}


// ========================================================================
// __unwind$536164
// EA  : 0x82DB1268
// RVA : 0x00DB1268
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_536164()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 112 + 80));
}


// ========================================================================
// ?Load@idMainMenu@@QAA_NPBD@Z
// EA  : 0x82DB1300
// RVA : 0x00DB1300
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

int __fastcall idMainMenu::Load(idMainMenu *this, char *filename, unsigned __int64 a3, int a4)
{
  idSWF *mainMenu; // r29
  idSWF *v8; // r3
  idSWF *v9; // r4

  mainMenu = this->mainMenu;
  if ( mainMenu != nullptr )
  {
    idSWF::~idSWF(this: this->mainMenu);
    idMem::Free(this: &mem, ptr: mainMenu, align: ALIGN_16);
  }
  if ( this->guiModel != nullptr )
    idRenderModelGui::Clear(
      this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
      a2: defaultExtraGLState,
      bits: a3,
      a4);
  if ( filename != nullptr )
  {
    idLBCache::Reset(this: this->lbCache);
    v8 = (idSWF *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                    size: 0x27Cu,
                    tag: TAG_SWF,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    if ( v8 != nullptr )
      v9 = idSWF::idSWF(this: v8, filename_: filename, soundWorld: this->soundWorld, atlasPurgable_: true);
    else
      v9 = nullptr;
    this->mainMenu = v9;
    idMainMenu::SetupBindings(this, gui: v9);
    idMainMenu::SetupCredits(this);
    return 1;
  }
  else
  {
    this->mainMenu = nullptr;
    return 0;
  }
}


// ========================================================================
// __unwind$536304
// EA  : 0x82DB13E8
// RVA : 0x00DB13E8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_536304()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SWF);
}


// ========================================================================
// `idMainMenu::SetupBindings'::`9'::idSWFScriptFunction_updateMenuCmds::Call
// EA  : 0x82DB1418
// RVA : 0x00DB1418
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::SetupBindings_::_9_::idSWFScriptFunction_updateMenuCmds::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *size; // r3

  size = (idMainMenu *)thisObject->variables.size;
  if ( size != nullptr )
    idMainMenu::UpdateMenuCmds(this: size);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?StartWidgetActionRepeater@idMainMenu@@QAAXPAVidMenuWidget@@ABVidWidgetAction@@ABVidWidgetEvent@@@Z
// EA  : 0x82DB17D0
// RVA : 0x00DB17D0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::StartWidgetActionRepeater(
        idMainMenu *this,
        idMenuWidget *widget,
        const idWidgetAction *action,
        const idWidgetEvent *event)
{
  mainMenuScreens_t activeMenu; // r10

  if ( !this->actionRepeater.isActive
    || (unsigned __int8)idWidgetAction::operator==(this: &this->actionRepeater.action, otherAction: action) == 0 )
  {
    this->actionRepeater.isActive = true;
    idWidgetAction::operator=(this: &this->actionRepeater.action, __that: action);
    this->actionRepeater.widget = widget;
    idWidgetEvent::operator=(this: &this->actionRepeater.event, __that: event);
    activeMenu = this->activeMenu;
    this->actionRepeater.numRepetitions = 0;
    this->actionRepeater.nextRepeatTime = 0;
    this->actionRepeater.menu = activeMenu;
    idMainMenu::PumpWidgetActionRepeater(this);
  }
}


// ========================================================================
// ?InternalActivate@idMainMenu@@QAAXXZ
// EA  : 0x82DB1A50
// RVA : 0x00DB1A50
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::InternalActivate(idMainMenu *this)
{
  idSWF *mainMenu; // r3
  bool v3; // r30
  idStaticList<idSWFScriptVar,16> v4; // [sp+50h] [-B0h] BYREF

  mainMenu = this->mainMenu;
  v3 = !mainMenu->isActive;
  idSWF::Activate(this: mainMenu, b: true);
  if ( v3 )
  {
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v4);
    idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v4);
    idSWF::Invoke(this: this->mainMenu, functionName: "activate", parms: (const idSWFParmList *)&v4);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v4);
  }
}


// ========================================================================
// __unwind$536919
// EA  : 0x82DB1AC4
// RVA : 0x00DB1AC4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_536919()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 256 + 80));
}


// ========================================================================
// ?Show@idMainMenu@@QAAX_N@Z
// EA  : 0x82DB1AF0
// RVA : 0x00DB1AF0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::Show(idMainMenu *this, bool show)
{
  int valueInteger; // r31
  int v4; // r4

  if ( this->mainMenu != nullptr )
  {
    valueInteger = swf_deferredDelayMsec.valueInteger;
    if ( show )
    {
      if ( swf_deferredDelayMsec.valueInteger <= 0 )
      {
        idMainMenu::InternalActivate(this);
      }
      else
      {
        this->deferredActivateMsec = Sys_Milliseconds() + valueInteger;
        common->PurgeOverlays(this: common);
        if ( swf_debugDeferredDelay.valueInteger != 0 )
          idLib::Printf(fmt: "setting deferredActivateMsec to %i msec\n", this->deferredActivateMsec);
      }
    }
    else
    {
      if ( swf_deferredDelayMsec.valueInteger > 0 )
      {
        v4 = Sys_Milliseconds() + valueInteger;
        this->deferredDeactivateMsec = v4;
        if ( swf_debugDeferredDelay.valueInteger != 0 )
          idLib::Printf(fmt: "setting deferredDeactivateMsec to %i msec\n", v4);
      }
      idSWF::Activate(this: this->mainMenu, b: false);
    }
  }
}


// ========================================================================
// ?UpdateMenuArea@idMainMenu@@AAAXXZ
// EA  : 0x82DB1BF0
// RVA : 0x00DB1BF0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateMenuArea(idMainMenu *this)
{
  menuArea_t desiredMenuArea; // r11
  const char *LocalizedString; // r3
  idStaticList<idSWFScriptVar,16> *v4; // r3
  idStrId v5[4]; // [sp+50h] [-300h] BYREF
  idStaticList<idSWFScriptVar,16> v6; // [sp+60h] [-2F0h] BYREF
  idStaticList<idSWFScriptVar,16> v7; // [sp+F0h] [-260h] BYREF
  idStaticList<idSWFScriptVar,16> v8; // [sp+180h] [-1D0h] BYREF
  idStaticList<idSWFScriptVar,16> v9; // [sp+210h] [-140h] BYREF
  idStaticList<idSWFScriptVar,16> v10; // [sp+2A0h] [-B0h] BYREF

  desiredMenuArea = this->desiredMenuArea;
  if ( this->menuArea != desiredMenuArea )
  {
    if ( (unsigned int)desiredMenuArea <= MENU_GAME_LOBBY_PEER )
    {
      switch ( desiredMenuArea )
      {
        case MENU_MAIN:
          idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v6);
          idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v6);
          idSWF::Invoke(this: this->mainMenu, functionName: "hideLoadingPacifier", parms: (const idSWFParmList *)&v6);
          idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v6);
          idSWF::Invoke(this: this->mainMenu, functionName: "startPressed", parms: (const idSWFParmList *)&v6);
          this->moveToCampaign = false;
          v4 = &v6;
          break;
        case MENU_WAITING:
          idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v10);
          idStrId::Set(this: v5, key: "#str_online_connecting");
          LocalizedString = idStrId::GetLocalizedString(this: v5);
          idSWFParmList::Append(this: (idSWFParmList *)&v10, s: LocalizedString);
          idSWF::Invoke(this: this->mainMenu, functionName: "showLoadingPacifier", parms: (const idSWFParmList *)&v10);
          v4 = &v10;
          break;
        case MENU_PARTY_LOBBY_HOST:
        case MENU_PARTY_LOBBY_PEER:
          idMainMenu::GoToPartyLobby(this);
          idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v9);
          idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v9);
          idSWF::Invoke(this: this->mainMenu, functionName: "hideLoadingPacifier", parms: (const idSWFParmList *)&v9);
          v4 = &v9;
          break;
        default:
          if ( desiredMenuArea != MENU_PRESS_START )
          {
            idMainMenu::GoToGameLobby(this);
            idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v8);
            idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v8);
            idSWF::Invoke(this: this->mainMenu, functionName: "hideLoadingPacifier", parms: (const idSWFParmList *)&v8);
            v4 = &v8;
          }
          else
          {
            playerMatchResults[0].shouldShowMatchResults = false;
            playerMatchResults[1].shouldShowMatchResults = false;
            idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v7);
            idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v7);
            idSWF::Invoke(this: this->mainMenu, functionName: "hideLoadingPacifier", parms: (const idSWFParmList *)&v7);
            idSWF::Activate(this: this->mainMenu, b: false);
            idSWF::Activate(this: this->mainMenu, b: true);
            v4 = &v7;
          }
          break;
      }
      idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: v4);
    }
    this->menuArea = this->desiredMenuArea;
  }
}


// ========================================================================
// __unwind$536968_0
// EA  : 0x82DB1DC0
// RVA : 0x00DB1DC0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_536968_0()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 848 + 240));
}


// ========================================================================
// __unwind$536969
// EA  : 0x82DB1DE8
// RVA : 0x00DB1DE8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_536969()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 848 + 528));
}


// ========================================================================
// __unwind$536970
// EA  : 0x82DB1E10
// RVA : 0x00DB1E10
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_536970()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 848 + 384));
}


// ========================================================================
// __unwind$536971
// EA  : 0x82DB1E38
// RVA : 0x00DB1E38
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_536971()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 848 + 672));
}


// ========================================================================
// __unwind$536972
// EA  : 0x82DB1E60
// RVA : 0x00DB1E60
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_536972()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 848 + 96));
}


// ========================================================================
// ?HandleGuiEvent@idMainMenu@@QAA_NPBUsysEvent_t@@@Z
// EA  : 0x82DB1E90
// RVA : 0x00DB1E90
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

int __fastcall idMainMenu::HandleGuiEvent(idMainMenu *this, const sysEvent_t *sev)
{
  int v4; // r30
  idPlayerProfile *PlayerProfileByInputDevice; // r3
  idSWF *mainMenu; // r3
  idLobbyBase *v8; // r3
  char v9; // r5
  BOOL v10; // r28
  idSWF *popupGui; // r3
  idSWF *testGui; // r3
  idSWF *v13; // r11
  int evValue; // [sp+50h] [-170h]
  idStaticList<idSWFScriptVar,16> v15; // [sp+60h] [-160h] BYREF
  idStaticList<idSWFScriptVar,16> v16; // [sp+F0h] [-D0h] BYREF

  if ( this->diskSwapInputLock || gameLocal->waitingOnVideoSettingsConfirm )
    return 1;
  if ( !gameLocal->IsGameActive(this: gameLocal) )
  {
    v4 = 0;
    do
    {
      PlayerProfileByInputDevice = idSignInManagerBase::GetPlayerProfileByInputDevice(
                                     this: session->signInManager,
                                     index: v4);
      if ( PlayerProfileByInputDevice != nullptr
        && (PlayerProfileByInputDevice->state == SAVING || PlayerProfileByInputDevice->requestedState == SAVE_REQUESTED) )
      {
        return 1;
      }
    }
    while ( ++v4 < 4 );
  }
  if ( swf_waitForCredits.valueInteger != 0 )
  {
    mainMenu = this->mainMenu;
    if ( mainMenu != nullptr )
      return idSWF::HandleEvent(this: mainMenu, event: sev);
  }
  v8 = session->GetGameLobbyBase(this: session);
  v9 = ~v8->GetMatchParms(this: v8)->matchFlags;
  v10 = (v9 & 2) != 0;
  if ( ((v9 & 2) == 0 || session->GetState(this: session) < GAME_LOBBY)
    && common->GetMasterLocalUserInputDevice(this: common) != sev->inputDevice )
  {
    return 1;
  }
  if ( v10 && sev->inputDevice != common->GetFocusDeviceNum(this: common) && this->isProfileScreenOpenBool )
    return 1;
  if ( (unsigned __int8)idMainMenu::IgnoreSplitScreenEvent(this, sev) != 0 )
    return 1;
  common->SetFocusDeviceNum(this: common, a2: sev->inputDevice);
  popupGui = this->popupGui;
  if ( popupGui != nullptr && (unsigned __int8)idSWF::HandleEvent(this: popupGui, event: sev) != 0 )
    return 1;
  testGui = this->testGui;
  if ( testGui != nullptr && (unsigned __int8)idSWF::HandleEvent(this: testGui, event: sev) != 0 )
    return 1;
  v13 = this->mainMenu;
  if ( v13 == nullptr || !v13->isActive )
    return 0;
  if ( swf_updateKeyBindings.valueInteger != 0 )
  {
    idCVar::SetBool(this: &swf_updateKeyBindings, newValue: false, force: true);
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v15);
    idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v15);
    idSWF::Invoke(this: this->mainMenu, functionName: "finishBinding", parms: (const idSWFParmList *)&v15);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v15);
  }
  if ( this->waitForBinding )
  {
    evValue = sev->evValue;
    if ( evValue != 1 )
    {
      if ( evValue != 28 && evValue != 14 && evValue != 63 && evValue != 67 && evValue != 15 )
      {
        if ( this->finishBinding )
        {
          if ( sev->evValue2 == 0 && evValue == this->bindWaitKey )
          {
            this->waitForBinding = false;
            this->finishBinding = false;
            this->bindWaitKey = -1;
            idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v16);
            idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v16);
            idSWF::Invoke(this: this->mainMenu, functionName: "finishBinding", parms: (const idSWFParmList *)&v16);
            idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v16);
          }
          return 1;
        }
        idMainMenu::RebindAction(this, sev);
        return 0;
      }
      return 1;
    }
  }
  idSWF::HandleEvent(this: this->mainMenu, event: sev);
  idKeyInput::ClearStates();
  return 1;
}


// ========================================================================
// __unwind$537067
// EA  : 0x82DB21D8
// RVA : 0x00DB21D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537067()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 448 + 96));
}


// ========================================================================
// __unwind$537068
// EA  : 0x82DB2200
// RVA : 0x00DB2200
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537068()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 448 + 240));
}


// ========================================================================
// `idMainMenu::ExitGameConfirm'::`2'::idSWFScriptFunction_CancelExit::Call
// EA  : 0x82DB2230
// RVA : 0x00DB2230
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::ExitGameConfirm_::_2_::idSWFScriptFunction_CancelExit::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r27
  const char *v7; // r4
  idStaticList<idSWFScriptVar,16> v8; // [sp+60h] [-C0h] BYREF

  if ( !common->IsMultiplayer(this: common)
    || (v5 = common->GetFocusDeviceNum(this: common)) == common->GetRecentInputDevice(this: common) )
  {
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v8);
    common->ClearDialog(
      this: common,
      a2: *(gameDialogMessages_t *)&thisObject->variables.granularity,
      a3: nullptr,
      a4: 0);
    if ( thisObject->variables.size == 1 )
      v7 = "loadDialogCancelled";
    else
      v7 = "dialogCancelled";
    idSWF::Invoke(this: (idSWF *)thisObject->variables.num, functionName: v7, parms: (const idSWFParmList *)&v8);
    result->type = SWF_VAR_UNDEF;
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v8);
    return result;
  }
  else
  {
    result->type = SWF_VAR_UNDEF;
    return result;
  }
}


// ========================================================================
// __unwind$537234
// EA  : 0x82DB2338
// RVA : 0x00DB2338
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537234()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 288;
  if ( (*(_DWORD *)(v0 - 288 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 308));
  }
}


// ========================================================================
// __unwind$537237
// EA  : 0x82DB237C
// RVA : 0x00DB237C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537237()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 288 + 96));
}


// ========================================================================
// `idMainMenu::ExitGameConfirm'::`3'::idSWFScriptFunction_AcceptExit::Call
// EA  : 0x82DB23B0
// RVA : 0x00DB23B0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::ExitGameConfirm_::_3_::idSWFScriptFunction_AcceptExit::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r27
  const char *v7; // r4
  idStaticList<idSWFScriptVar,16> v8; // [sp+60h] [-C0h] BYREF

  if ( common->IsMultiplayer(this: common) )
  {
    v5 = common->GetFocusDeviceNum(this: common);
    if ( v5 != common->GetRecentInputDevice(this: common) )
    {
      result->type = SWF_VAR_UNDEF;
      return result;
    }
  }
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v8);
  common->ClearDialog(this: common, a2: *(gameDialogMessages_t *)&thisObject->variables.granularity, a3: nullptr, a4: 0);
  if ( thisObject->variables.size != 1 )
  {
    v7 = "dialogConfirmed";
    goto LABEL_9;
  }
  if ( *(_DWORD *)thisObject->variablesHash[0] == 0 )
  {
    v7 = "loadDialogConfirmed";
LABEL_9:
    idSWF::Invoke(this: (idSWF *)thisObject->variables.num, functionName: v7, parms: (const idSWFParmList *)&v8);
    goto LABEL_10;
  }
  idLib::PrintfIf(
    condition: saveGame_verbose.valueInteger != 0,
    fmt: "Device changed when not looking, not loading game\n");
LABEL_10:
  result->type = SWF_VAR_UNDEF;
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v8);
  return result;
}


// ========================================================================
// __unwind$537273
// EA  : 0x82DB24EC
// RVA : 0x00DB24EC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537273()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 288;
  if ( (*(_DWORD *)(v0 - 288 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 308));
  }
}


// ========================================================================
// __unwind$537276
// EA  : 0x82DB2530
// RVA : 0x00DB2530
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537276()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 288 + 96));
}


// ========================================================================
// ?RefreshSaveData@idMainMenu@@QAAX_N@Z
// EA  : 0x82DB2560
// RVA : 0x00DB2560
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::RefreshSaveData(idMainMenu *this, bool changed)
{
  idSWF *mainMenu; // r3
  idStaticList<idSWFScriptVar,16> v5; // [sp+50h] [-B0h] BYREF

  this->isDeletingGame = false;
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v5);
  idSWFParmList::Append(this: (idSWFParmList *)&v5, b: false);
  idSWFParmList::Append(this: (idSWFParmList *)&v5, b: changed);
  mainMenu = this->mainMenu;
  if ( mainMenu != nullptr )
    idSWF::Invoke(this: mainMenu, functionName: "refreshLoadScreen", parms: (const idSWFParmList *)&v5);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v5);
}


// ========================================================================
// __unwind$537315
// EA  : 0x82DB25CC
// RVA : 0x00DB25CC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537315()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 256 + 80));
}


// ========================================================================
// ?CanStartNewGame@idMainMenu@@QAA_NXZ
// EA  : 0x82DB2600
// RVA : 0x00DB2600
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

int __fastcall idMainMenu::CanStartNewGame(idMainMenu *this)
{
  _DWORD *v2; // r3
  _DWORD *v3; // r11
  const char *LocalizedString; // r3
  __int64 v5; // r10
  __int64 v6; // r8
  __int128 v7; // r6
  va *v8; // r3
  __int64 v9; // r6
  __int64 v10; // r10
  __int64 v11; // r8
  va *v12; // r3
  idStrStatic<256> *v13; // r3
  idLocalUser *MasterLocalUser; // r3
  bool *p_askToDeleteAutosaveOnNewGame; // r29
  _DWORD *v17; // r3
  idSWF *mainMenu; // r11
  _DWORD *v19; // r24
  _DWORD *v20; // r3
  _DWORD *v21; // r6
  int v22; // [sp+8h] [-2328h]
  int v23; // [sp+8h] [-2328h]
  int v24; // [sp+Ch] [-2324h]
  int v25; // [sp+Ch] [-2324h]
  int v26; // [sp+10h] [-2320h]
  int v27; // [sp+10h] [-2320h]
  int v28; // [sp+14h] [-231Ch]
  int v29; // [sp+14h] [-231Ch]
  int v30; // [sp+18h] [-2318h]
  int v31; // [sp+18h] [-2318h]
  int v32; // [sp+1Ch] [-2314h]
  int v33; // [sp+1Ch] [-2314h]
  idStrId v34; // [sp+70h] [-22C0h] BYREF
  _DWORD *v35; // [sp+74h] [-22BCh] BYREF
  idStrId v36[2]; // [sp+78h] [-22B8h] BYREF
  idList<idVehicleState *,5> v37; // [sp+80h] [-22B0h] BYREF
  _BYTE v38[16]; // [sp+90h] [-22A0h] BYREF
  idList<enum encounterGroupRole_t,5> v39; // [sp+A0h] [-2290h] BYREF
  int v40; // [sp+B0h] [-2280h] BYREF
  __int64 v41; // [sp+C0h] [-2270h] BYREF
  idStr v42; // [sp+D0h] [-2260h] BYREF
  idStr v43; // [sp+F0h] [-2240h] BYREF
  idStr v44; // [sp+110h] [-2220h] BYREF
  idStaticList<idSWFScriptVar,16> v45; // [sp+130h] [-2200h] BYREF
  idStrStatic<256> v46; // [sp+1C0h] [-2170h] BYREF
  va v47; // [sp+2E0h] [-2050h] BYREF
  va v48; // [sp+12E0h] [-1050h] BYREF

  if ( saveGame_enable.valueInteger != 0 )
  {
    if ( (unsigned __int8)idMainMenu::IsStorageRequirementMet(this, neededBytes: &v41) == 0 )
    {
      *(_QWORD *)&v39.num = 4;
      v39.list = (encounterGroupRole_t *)&v40;
      *(_DWORD *)&v39.granularity = 66817;
      *(_QWORD *)&v37.num = 4;
      v37.list = (idVehicleState **)v38;
      *(_DWORD *)&v37.granularity = 66817;
      memset(v38, 255, sizeof(v38));
      v2 = idMem::AllocWithLocation(
             this: &mem,
             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
             size: 0xCu,
             tag: TAG_SWF,
             zeroBuffer: false,
             align: ALIGN_16,
             heap: HEAP_DEFAULTHEAP);
      if ( v2 != nullptr )
      {
        v2[2] = this;
        v2[1] = 0;
        v3 = v2;
        *v2 = &`idMainMenu::CanStartNewGame'::`9'::idSWFScriptFunction_SelectDevice::`vftable';
      }
      else
      {
        v3 = nullptr;
      }
      v35 = v3;
      idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: (encounterGroupRole_t *)&v35);
      idStrId::Set(this: v36, key: "#str_dlg_select_a_device");
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: (idList<idStrId,5> *)&v37, obj: v36);
      idStrId::Set(this: &v34, key: "#str_dlg_360_space_required");
      LocalizedString = idStrId::GetLocalizedString(this: &v34);
      idStr::idStr(this: &v44, text: LocalizedString);
      HIDWORD(v5) = &unk_821C0000;
      LODWORD(v6) = "ame: %s\n";
      *(double *)((char *)&v7 + 4) = (float)((float)v41 * (float)0.00000095367432);
      v8 = va::va(
             this: &v47,
             fmt: (const char *)DWORD1(v7),
             a3: v7,
             a4: v6,
             a5: v5,
             a6: v22,
             a7: v24,
             a8: v26,
             a9: v28,
             a10: v30,
             a11: v32);
      idStr::idStr(this: &v43, text: v8);
      HIDWORD(v9) = v43.data;
      v12 = va::va(
              this: &v48,
              fmt: v44.data,
              a3: v9,
              a4: v11,
              a5: v10,
              a6: v23,
              a7: v25,
              a8: v27,
              a9: v29,
              a10: v31,
              a11: v33);
      idStr::idStr(this: &v42, text: v12);
      v13 = idStrStatic<256>::idStrStatic<256>(this: &v46, text: &v42);
      ((void (__fastcall *)(idCommon *, int, idList<enum encounterGroupRole_t,5> *, idList<idVehicleState *,5> *, int, idStrStatic<256> *, _DWORD, _DWORD))common->AddDynamicDialog)(
        a1: common,
        a2: 60,
        a3: &v39,
        a4: &v37,
        a5: 1,
        a6: v13,
        a7: 0,
        a8: 0);
      MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: session->signInManager);
      MasterLocalUser->ResetStorageDevice(this: MasterLocalUser);
      idStr::FreeData(this: &v42);
      idStr::FreeData(this: &v43);
      idStr::FreeData(this: &v44);
      idList<idThread *,58>::Clear(this: &v37);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
      return 0;
    }
    if ( discSwapper_enable.valueInteger != 0 && resourceManager->GetCurrentDiscNumber(this: resourceManager) != 1 )
    {
      idDiscSwapManager::Reset(this: discSwapMgr);
      idDiscSwapManager::Swap(this: discSwapMgr, command: DSC_MAIN_MENU, forceDiscNumber: (idResource *)1);
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v45);
      idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v45);
      idSWF::Invoke(this: this->mainMenu, functionName: "resetLoadMostRecent", parms: (const idSWFParmList *)&v45);
      idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v45);
      return 0;
    }
    if ( hasAutosave )
    {
      this->askToDeleteAutosaveOnNewGame = true;
      p_askToDeleteAutosaveOnNewGame = &this->askToDeleteAutosaveOnNewGame;
      v17 = idMem::AllocWithLocation(
              this: &mem,
              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
              size: 0x14u,
              tag: TAG_SWF,
              zeroBuffer: false,
              align: ALIGN_16,
              heap: HEAP_DEFAULTHEAP);
      if ( v17 != nullptr )
      {
        mainMenu = this->mainMenu;
        v17[4] = p_askToDeleteAutosaveOnNewGame;
        v19 = v17;
        v17[3] = 52;
        v17[1] = 0;
        *v17 = &`idMainMenu::CanStartNewGame'::`20'::idSWFScriptFunction_CancelExit::`vftable';
        v17[2] = mainMenu;
      }
      else
      {
        v19 = nullptr;
      }
      v20 = idMem::AllocWithLocation(
              this: &mem,
              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
              size: 0x14u,
              tag: TAG_SWF,
              zeroBuffer: false,
              align: ALIGN_16,
              heap: HEAP_DEFAULTHEAP);
      if ( v20 != nullptr )
      {
        v20[2] = this;
        v20[4] = p_askToDeleteAutosaveOnNewGame;
        v21 = v20;
        v20[1] = 0;
        v20[3] = 52;
        *v20 = &`idMainMenu::CanStartNewGame'::`19'::idSWFScriptFunction_AcceptExit::`vftable';
      }
      else
      {
        v21 = nullptr;
      }
      ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
        a1: common,
        a2: 52,
        a3: 2,
        a4: v21,
        a5: v19,
        a6: 0,
        a7: 0,
        a8: 0);
      return 0;
    }
  }
  return 1;
}


// ========================================================================
// __unwind$537362
// EA  : 0x82DB29D8
// RVA : 0x00DB29D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537362()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 9008 + 160));
}


// ========================================================================
// __unwind$537363
// EA  : 0x82DB2A00
// RVA : 0x00DB2A00
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537363()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 9008 + 128));
}


// ========================================================================
// __unwind$537365
// EA  : 0x82DB2A28
// RVA : 0x00DB2A28
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537365()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9008 + 272));
}


// ========================================================================
// __unwind$537366
// EA  : 0x82DB2A50
// RVA : 0x00DB2A50
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537366()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9008 + 240));
}


// ========================================================================
// __unwind$537367
// EA  : 0x82DB2A78
// RVA : 0x00DB2A78
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537367()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9008 + 208));
}


// ========================================================================
// __unwind$537369
// EA  : 0x82DB2AA0
// RVA : 0x00DB2AA0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537369()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 9008 + 304));
}


// ========================================================================
// `idMainMenu::CanStartNewGame'::`19'::idSWFScriptFunction_AcceptExit::Call
// EA  : 0x82DB2AD0
// RVA : 0x00DB2AD0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::CanStartNewGame_::_19_::idSWFScriptFunction_AcceptExit::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idStaticList<idSWFScriptVar,16> v6; // [sp+60h] [-C0h] BYREF

  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v6);
  common->ClearDialog(this: common, a2: (gameDialogMessages_t)thisObject->variables.size, a3: nullptr, a4: 0);
  **(_BYTE **)&thisObject->variables.granularity = 0;
  result->type = SWF_VAR_UNDEF;
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v6);
  return result;
}


// ========================================================================
// __unwind$537575
// EA  : 0x82DB2B4C
// RVA : 0x00DB2B4C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537575()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 288 + 96));
}


// ========================================================================
// __unwind$537576
// EA  : 0x82DB2B74
// RVA : 0x00DB2B74
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537576()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 288;
  if ( (*(_DWORD *)(v0 - 288 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 308));
  }
}


// ========================================================================
// `idMainMenu::CanStartNewGame'::`20'::idSWFScriptFunction_CancelExit::Call
// EA  : 0x82DB2BC0
// RVA : 0x00DB2BC0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::CanStartNewGame_::_20_::idSWFScriptFunction_CancelExit::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idStaticList<idSWFScriptVar,16> v6; // [sp+60h] [-C0h] BYREF

  common->ClearDialog(this: common, a2: (gameDialogMessages_t)thisObject->variables.size, a3: nullptr, a4: 0);
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v6);
  if ( v6.listStatic == 0 || v6.listStatic == 2 )
  {
    if ( v6.list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v6.list, num: v6.size);
    v6.list = nullptr;
    v6.size = 0;
  }
  v6.num = 0;
  idSWF::Invoke(
    this: (idSWF *)thisObject->variables.num,
    functionName: "resetLoadMostRecent",
    parms: (const idSWFParmList *)&v6);
  **(_BYTE **)&thisObject->variables.granularity = 0;
  result->type = SWF_VAR_UNDEF;
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v6);
  return result;
}


// ========================================================================
// __unwind$537613
// EA  : 0x82DB2C84
// RVA : 0x00DB2C84
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537613()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 288 + 96));
}


// ========================================================================
// __unwind$537614
// EA  : 0x82DB2CAC
// RVA : 0x00DB2CAC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537614()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 288;
  if ( (*(_DWORD *)(v0 - 288 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 308));
  }
}


// ========================================================================
// `idMainMenu::LoadDamagedGame'::`6'::idSWFScriptFunction_CancelDelete::Call
// EA  : 0x82DB2CF8
// RVA : 0x00DB2CF8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::LoadDamagedGame_::_6_::idSWFScriptFunction_CancelDelete::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWF *size; // r3
  idStaticList<idSWFScriptVar,16> v7; // [sp+60h] [-C0h] BYREF

  common->ClearDialog(this: common, a2: (gameDialogMessages_t)thisObject->variables.num, a3: nullptr, a4: 0);
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v7);
  if ( v7.listStatic == 0 || v7.listStatic == 2 )
  {
    if ( v7.list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v7.list, num: v7.size);
    v7.list = nullptr;
    v7.size = 0;
  }
  size = (idSWF *)thisObject->variables.size;
  v7.num = 0;
  if ( size != nullptr )
    idSWF::Invoke(this: size, functionName: "loadDialogCancelled", parms: (const idSWFParmList *)&v7);
  result->type = SWF_VAR_UNDEF;
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v7);
  return result;
}


// ========================================================================
// __unwind$537654
// EA  : 0x82DB2DBC
// RVA : 0x00DB2DBC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537654()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 288 + 96));
}


// ========================================================================
// __unwind$537655
// EA  : 0x82DB2DE4
// RVA : 0x00DB2DE4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537655()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 288;
  if ( (*(_DWORD *)(v0 - 288 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 308));
  }
}


// ========================================================================
// `idMainMenu::RebindAction'::`11'::idSWFScriptFunction_CancelInvalidBind::Call
// EA  : 0x82DB2E30
// RVA : 0x00DB2E30
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::RebindAction_::_11_::idSWFScriptFunction_CancelInvalidBind::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idStaticList<idSWFScriptVar,16> v6; // [sp+60h] [-C0h] BYREF

  *(_BYTE *)(thisObject->variables.num + 740) = 0;
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v6);
  if ( v6.listStatic == 0 || v6.listStatic == 2 )
  {
    if ( v6.list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v6.list, num: v6.size);
    v6.list = nullptr;
    v6.size = 0;
  }
  v6.num = 0;
  idSWF::Invoke(
    this: (idSWF *)thisObject->variables.size,
    functionName: "finishBinding",
    parms: (const idSWFParmList *)&v6);
  common->ClearDialog(this: common, a2: GDM_CANNOT_BIND, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v6);
  return result;
}


// ========================================================================
// __unwind$537695
// EA  : 0x82DB2EF4
// RVA : 0x00DB2EF4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537695()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 288 + 96));
}


// ========================================================================
// __unwind$537696
// EA  : 0x82DB2F1C
// RVA : 0x00DB2F1C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537696()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 288;
  if ( (*(_DWORD *)(v0 - 288 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 308));
  }
}


// ========================================================================
// `idMainMenu::RebindAction'::`51'::idSWFScriptFunction_CancelBind::Call
// EA  : 0x82DB2F68
// RVA : 0x00DB2F68
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::RebindAction_::_51_::idSWFScriptFunction_CancelBind::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idStaticList<idSWFScriptVar,16> v6; // [sp+60h] [-C0h] BYREF

  *(_BYTE *)(thisObject->variables.num + 740) = 0;
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v6);
  if ( v6.listStatic == 0 || v6.listStatic == 2 )
  {
    if ( v6.list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v6.list, num: v6.size);
    v6.list = nullptr;
    v6.size = 0;
  }
  v6.num = 0;
  idSWF::Invoke(
    this: (idSWF *)thisObject->variables.size,
    functionName: "finishBinding",
    parms: (const idSWFParmList *)&v6);
  common->ClearDialog(this: common, a2: *(gameDialogMessages_t *)&thisObject->variables.granularity, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v6);
  return result;
}


// ========================================================================
// __unwind$537740
// EA  : 0x82DB302C
// RVA : 0x00DB302C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537740()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 288 + 96));
}


// ========================================================================
// __unwind$537741
// EA  : 0x82DB3054
// RVA : 0x00DB3054
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537741()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 288;
  if ( (*(_DWORD *)(v0 - 288 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 308));
  }
}


// ========================================================================
// `idMainMenu::ConfirmBindingReset'::`3'::idSWFScriptFunction_AcceptRestore::Call
// EA  : 0x82DB30A0
// RVA : 0x00DB30A0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::ConfirmBindingReset_::_3_::idSWFScriptFunction_AcceptRestore::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  va *v8; // r3
  XGRAPHICS::CFG *size; // r3
  int Config; // r3
  int v11; // r3
  int v13; // [sp+8h] [-11C8h]
  int v14; // [sp+Ch] [-11C4h]
  int v15; // [sp+10h] [-11C0h]
  int v16; // [sp+14h] [-11BCh]
  int v17; // [sp+18h] [-11B8h]
  int v18; // [sp+1Ch] [-11B4h]
  void *v19; // [sp+50h] [-1180h] BYREF
  int v20; // [sp+54h] [-117Ch]
  idStr v21; // [sp+60h] [-1170h] BYREF
  idStaticList<idSWFScriptVar,16> v22; // [sp+80h] [-1150h] BYREF
  idStaticList<idSWFScriptVar,16> v23; // [sp+110h] [-10C0h] BYREF
  va v24; // [sp+1A0h] [-1030h] BYREF

  v20 = 0;
  idStr::idStr(this: &v21, text: "default.cfg");
  if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: "French") == 0 )
    idStr::operator=(this: &v21, text: "default_french.cfg");
  idStr::DefaultFileExtension(this: &v21, extension: ".cfg");
  fileSystem->ReadFile(this: fileSystem, a2: v21.data, a3: &v19, a4: nullptr);
  HIDWORD(v7) = v19;
  if ( v19 != nullptr )
  {
    v8 = va::va(this: &v24, fmt: "%s\n", a3: v7, a4: v6, a5: v5, a6: v13, a7: v14, a8: v15, a9: v16, a10: v17, a11: v18);
    cmdSystem->AppendCommandText(this: cmdSystem, a2: v8->buffer);
    cmdSystem->ExecuteCommandBuffer(this: cmdSystem);
    fileSystem->FreeFile(this: fileSystem, a2: v19);
    size = (XGRAPHICS::CFG *)thisObject->variables.size;
    if ( size != nullptr )
    {
      Config = idPlayerProfileGame::GetConfig(this: size);
      idPlayerProfileGame::ExecConfig(
        this: (idPlayerProfileGame *)thisObject->variables.size,
        config: Config,
        fps: true,
        save: false);
      v11 = idPlayerProfileGame::GetConfig(this: (XGRAPHICS::CFG *)thisObject->variables.size);
      idPlayerProfileGame::ExecConfig(
        this: (idPlayerProfileGame *)thisObject->variables.size,
        config: v11,
        fps: false,
        save: false);
      idPlayerProfile::SaveSettings(this: (idPlayerProfile *)thisObject->variables.size);
    }
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v22);
    idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v22);
    idSWF::Invoke(
      this: (idSWF *)thisObject->variables.num,
      functionName: "finishBinding",
      parms: (const idSWFParmList *)&v22);
    common->ClearDialog(this: common, a2: GDM_BINDINGS_RESTORE, a3: nullptr, a4: 0);
    result->type = SWF_VAR_UNDEF;
    v20 = 1;
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v22);
  }
  else
  {
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v23);
    idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v23);
    idSWF::Invoke(
      this: (idSWF *)thisObject->variables.num,
      functionName: "finishBinding",
      parms: (const idSWFParmList *)&v23);
    common->ClearDialog(this: common, a2: GDM_BINDINGS_RESTORE, a3: nullptr, a4: 0);
    result->type = SWF_VAR_UNDEF;
    v20 = 1;
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v23);
  }
  idStr::FreeData(this: &v21);
  return result;
}


// ========================================================================
// __unwind$537786
// EA  : 0x82DB32C8
// RVA : 0x00DB32C8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537786()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 96));
}


// ========================================================================
// __unwind$537787
// EA  : 0x82DB32F0
// RVA : 0x00DB32F0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537787()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 4560 + 272));
}


// ========================================================================
// __unwind$537788
// EA  : 0x82DB3318
// RVA : 0x00DB3318
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537788()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 4560;
  if ( (*(_DWORD *)(v0 - 4560 + 84) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 84) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 4580));
  }
}


// ========================================================================
// __unwind$537791
// EA  : 0x82DB335C
// RVA : 0x00DB335C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537791()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 4560 + 128));
}


// ========================================================================
// ?Call@idSWFScriptFunction_hidePauseMenu@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB3388
// RVA : 0x00DB3388
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_hidePauseMenu *__fastcall idMainMenu::idSWFScriptFunction_hidePauseMenu::Call(
        idMainMenu::idSWFScriptFunction_hidePauseMenu *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu::Show(this: (idMainMenu *)result->value.i, show: false);
  this->__vftable = (idMainMenu::idSWFScriptFunction_hidePauseMenu_vtbl *)4;
  return this;
}


// ========================================================================
// ?ResetMenuFromBenchmark@idMainMenu@@QAAXXZ
// EA  : 0x82DB33D8
// RVA : 0x00DB33D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::ResetMenuFromBenchmark(idMainMenu *this)
{
  idStaticList<idSWFScriptVar,16> v2; // [sp+50h] [-B0h] BYREF

  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v2);
  if ( v2.listStatic == 0 || v2.listStatic == 2 )
  {
    if ( v2.list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v2.list, num: v2.size);
    v2.list = nullptr;
    v2.size = 0;
  }
  v2.num = 0;
  idSWF::Invoke(this: this->mainMenu, functionName: "finishedBenchmark", parms: (const idSWFParmList *)&v2);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v2);
}


// ========================================================================
// __unwind$537889
// EA  : 0x82DB3450
// RVA : 0x00DB3450
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537889()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 256 + 80));
}


// ========================================================================
// ?Call@idSWFScriptFunction_canStartNewGame@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB3478
// RVA : 0x00DB3478
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_canStartNewGame *__fastcall idMainMenu::idSWFScriptFunction_canStartNewGame::Call(
        idMainMenu::idSWFScriptFunction_canStartNewGame *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char CanStartNewGame; // r30

  CanStartNewGame = idMainMenu::CanStartNewGame(this: (idMainMenu *)result->value.i);
  this->__vftable = (idMainMenu::idSWFScriptFunction_canStartNewGame_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = CanStartNewGame;
  this->__vftable = (idMainMenu::idSWFScriptFunction_canStartNewGame_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setSaveLoadUpdate@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB34D8
// RVA : 0x00DB34D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setSaveLoadUpdate *__fastcall idMainMenu::idSWFScriptFunction_setSaveLoadUpdate::Call(
        idMainMenu::idSWFScriptFunction_setSaveLoadUpdate *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  if ( parms->num == 1 )
  {
    *(_BYTE *)(result->value.i + 948) = idSWFScriptVar::ToBool(this: parms->list);
    idMainMenu::UpdateSavedGameList(this: (idMainMenu *)result->value.i);
    idMainMenu::RefreshSaveData(this: (idMainMenu *)result->value.i, changed: false);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setSaveLoadUpdate_vtbl *)4;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_setSaveLoadUpdate_vtbl *)4;
  }
  return this;
}


// ========================================================================
// `idMainMenu::ShowDisplaySettingFailedMessage'::`5'::idSWFScriptFunction_AcceptFailedChanges::Call
// EA  : 0x82DB3560
// RVA : 0x00DB3560
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::ShowDisplaySettingFailedMessage_::_5_::idSWFScriptFunction_AcceptFailedChanges::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject *v5; // r27
  idSWFScriptObject *v6; // r3
  int *v7; // r3
  idSWFScriptObject *v8; // r3
  idSWFScriptObject *size; // r30
  idSWFScriptObject *v10; // r3
  idSWFScriptObject *v11; // r3
  int v12; // r3
  idPlayerProfile *PlayerProfileByInputDevice; // r3
  idSWFScriptObject v15[2]; // [sp+50h] [-240h] BYREF
  idStaticList<idSWFScriptVar,16> v16; // [sp+130h] [-160h] BYREF
  idStaticList<idSWFScriptVar,16> v17; // [sp+1C0h] [-D0h] BYREF

  *(_DWORD *)&v15[0].variables.granularity = 0;
  v15[0].variables.num = 4;
  gameLocal->waitingOnVideoSettingsConfirm = false;
  v5 = *(idSWFScriptObject **)(*(_DWORD *)(thisObject->variables.num + 64) + 40);
  if ( !common->IsMultiplayer(this: common) || gameLocal->IsGameActive(this: gameLocal) )
  {
    v8 = idSWFScriptObject::Get(
           this: (idSWFScriptObject *)&v15[0].variablesHash[5],
           result: v5,
           name: "_absRight_videoMenu");
    idSWFScriptVar::operator=(this: (idSWFScriptVar *)&v15[0].variables.num, other: (const idSWFScriptVar *)v8);
    v7 = &v15[0].variablesHash[5];
  }
  else
  {
    v6 = idSWFScriptObject::Get(
           this: (idSWFScriptObject *)&v15[0].variablesHash[9],
           result: v5,
           name: "_absLeft_videoMenu");
    idSWFScriptVar::operator=(this: (idSWFScriptVar *)&v15[0].variables.num, other: (const idSWFScriptVar *)v6);
    v7 = &v15[0].variablesHash[9];
  }
  idSWFScriptVar::Free(this: (idSWFScriptVar *)v7);
  if ( v15[0].variables.num == 8 )
  {
    size = (idSWFScriptObject *)v15[0].variables.size;
    idSWFScriptObject::Get(
      this: v15,
      result: (idSWFScriptObject *)v15[0].variables.size,
      name: "initializeSettingValues");
    if ( v15[0].refCount == 7 )
    {
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v15[0].variablesHash[15]);
      idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: (idList<idSWFScriptVar,5> *)&v15[0].variablesHash[15]);
      (*(void (__fastcall **)(int *, idSWFScriptObject::swfNamedVar_t *, _DWORD, int *))(v15[0].variables.list->index + 4))(
        a1: &v15[0].variablesHash[11],
        a2: v15[0].variables.list,
        a3: 0,
        a4: &v15[0].variablesHash[15]);
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v15[0].variablesHash[11]);
      idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v15[0].variablesHash[15]);
    }
    v10 = idSWFScriptObject::Get(this: (idSWFScriptObject *)&v15[0].variablesHash[1], result: size, name: "updateMenu");
    idSWFScriptVar::operator=(this: (idSWFScriptVar *)v15, other: (const idSWFScriptVar *)v10);
    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v15[0].variablesHash[1]);
    if ( v15[0].refCount == 7 )
    {
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v16);
      idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v16);
      (*(void (__fastcall **)(int *, idSWFScriptObject::swfNamedVar_t *, _DWORD, idStaticList<idSWFScriptVar,16> *))(v15[0].variables.list->index + 4))(
        a1: &v15[0].variablesHash[13],
        a2: v15[0].variables.list,
        a3: 0,
        a4: &v16);
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v15[0].variablesHash[13]);
      idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v16);
    }
    v11 = idSWFScriptObject::Get(this: (idSWFScriptObject *)&v15[0].variablesHash[3], result: size, name: "updateCmds");
    idSWFScriptVar::operator=(this: (idSWFScriptVar *)v15, other: (const idSWFScriptVar *)v11);
    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v15[0].variablesHash[3]);
    if ( v15[0].refCount == 7 )
    {
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v17);
      idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v17);
      (*(void (__fastcall **)(int *, idSWFScriptObject::swfNamedVar_t *, _DWORD, idStaticList<idSWFScriptVar,16> *))(v15[0].variables.list->index + 4))(
        a1: &v15[0].variablesHash[7],
        a2: v15[0].variables.list,
        a3: 0,
        a4: &v17);
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v15[0].variablesHash[7]);
      idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v17);
    }
    idSWFScriptVar::Free(this: (idSWFScriptVar *)v15);
  }
  common->ClearDialog(this: common, a2: (gameDialogMessages_t)thisObject->variables.size, a3: nullptr, a4: 0);
  v12 = common->GetFocusDeviceNum(this: common);
  PlayerProfileByInputDevice = idSignInManagerBase::GetPlayerProfileByInputDevice(
                                 this: session->signInManager,
                                 index: v12);
  if ( PlayerProfileByInputDevice != nullptr )
    idPlayerProfile::SaveSettings(this: PlayerProfileByInputDevice);
  result->type = SWF_VAR_UNDEF;
  *(_DWORD *)&v15[0].variables.granularity = 1;
  idSWFScriptVar::Free(this: (idSWFScriptVar *)&v15[0].variables.num);
  return result;
}


// ========================================================================
// __unwind$537970
// EA  : 0x82DB3814
// RVA : 0x00DB3814
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537970()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 88));
}


// ========================================================================
// __unwind$537971
// EA  : 0x82DB383C
// RVA : 0x00DB383C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537971()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 136));
}


// ========================================================================
// __unwind$537972
// EA  : 0x82DB3864
// RVA : 0x00DB3864
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537972()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 120));
}


// ========================================================================
// __unwind$537973
// EA  : 0x82DB388C
// RVA : 0x00DB388C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537973()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 80));
}


// ========================================================================
// __unwind$537974
// EA  : 0x82DB38B4
// RVA : 0x00DB38B4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537974()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 656 + 160));
}


// ========================================================================
// __unwind$537976
// EA  : 0x82DB38DC
// RVA : 0x00DB38DC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537976()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 104));
}


// ========================================================================
// __unwind$537977
// EA  : 0x82DB3904
// RVA : 0x00DB3904
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537977()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 656 + 304));
}


// ========================================================================
// __unwind$537979
// EA  : 0x82DB392C
// RVA : 0x00DB392C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537979()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 112));
}


// ========================================================================
// __unwind$537980
// EA  : 0x82DB3954
// RVA : 0x00DB3954
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537980()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 656 + 448));
}


// ========================================================================
// __unwind$537982
// EA  : 0x82DB397C
// RVA : 0x00DB397C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_537982()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 656;
  if ( (*(_DWORD *)(v0 - 656 + 96) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 96) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 676));
  }
}


// ========================================================================
// ?PlayScrollSound@idMainMenu@@QAAXXZ
// EA  : 0x82DB39C8
// RVA : 0x00DB39C8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::PlayScrollSound(idMainMenu *this)
{
  idStaticList<idSWFScriptVar,16> v2; // [sp+50h] [-B0h] BYREF

  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v2);
  idSWF::Invoke(this: this->mainMenu, functionName: "playScrollSound", parms: (const idSWFParmList *)&v2);
  if ( v2.listStatic == 0 || v2.listStatic == 2 )
  {
    if ( v2.list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v2.list, num: v2.size);
    v2.list = nullptr;
    v2.size = 0;
  }
  v2.num = 0;
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v2);
}


// ========================================================================
// __unwind$538166
// EA  : 0x82DB3A58
// RVA : 0x00DB3A58
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538166()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 256 + 80));
}


// ========================================================================
// ?NewDLCAvailable@idMainMenu@@QAAXXZ
// EA  : 0x82DB3A88
// RVA : 0x00DB3A88
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::NewDLCAvailable(idMainMenu *this)
{
  idStaticList<idSWFScriptVar,16> v2; // [sp+50h] [-B0h] BYREF

  if ( this->mainMenu != nullptr )
  {
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v2);
    idSWFParmList::Append(this: (idSWFParmList *)&v2, b: true);
    idSWF::Invoke(this: this->mainMenu, functionName: "showNewDLCIndicator", parms: (const idSWFParmList *)&v2);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v2);
  }
}


// ========================================================================
// __unwind$538197
// EA  : 0x82DB3AF8
// RVA : 0x00DB3AF8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538197()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 256 + 80));
}


// ========================================================================
// ?RestartMenuMusic@idMainMenu@@QAAXXZ
// EA  : 0x82DB3B28
// RVA : 0x00DB3B28
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::RestartMenuMusic(idMainMenu *this)
{
  idStaticList<idSWFScriptVar,16> v2; // [sp+50h] [-B0h] BYREF

  if ( this->mainMenu != nullptr )
  {
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v2);
    idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v2);
    idSWF::Invoke(this: this->mainMenu, functionName: "restoreMusic", parms: (const idSWFParmList *)&v2);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v2);
  }
}


// ========================================================================
// __unwind$538222
// EA  : 0x82DB3B94
// RVA : 0x00DB3B94
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538222()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 256 + 80));
}


// ========================================================================
// ?ToggleMainMenu_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82DB3BC0
// RVA : 0x00DB3BC0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall ToggleMainMenu_f(const idCmdArgs *args)
{
  idGame *v1; // r3
  unsigned __int8 IsActive; // r3
  idMainMenu *v3; // r8

  v1 = common->Game(this: common);
  if ( v1->IsGameActive(this: v1) && !common->IsDialogActive(this: common) )
  {
    IsActive = idMainMenu::IsActive(this: gameLocal->mainMenu);
    idMainMenu::Show(this: v3, show: (_cntlzw(IsActive) & 0x20) != 0);
  }
}


// ========================================================================
// ?mpMenu_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82DB3C70
// RVA : 0x00DB3C70
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall mpMenu_f(const idCmdArgs *args)
{
  const idMatchParameters *matched; // r3
  unsigned __int64 v2; // r6
  idMatchParameters v3; // [sp+50h] [-1270h] BYREF

  if ( session->GetState(this: session) == PRESS_START )
  {
    session->signInManager->RegisterLocalUser(this: session->signInManager, a2: 0);
    while ( session->GetState(this: session) != 1 )
    {
      session->UpdateSignInManager(this: session);
      session->Pump(this: session);
      mgthread_sleep(ms: 10);
    }
  }
  idCVar::SetBool(this: &com_multiplayer, newValue: true, force: true);
  matched = idMatchParameters::idMatchParameters(this: &v3);
  session->UpdateMatchParms(this: session, a2: matched);
  idMatchParameters::~idMatchParameters(this: &v3);
  idMainMenu::SetupMultiplayerMenu(this: gameLocal->mainMenu);
  idMainMenu::Load(this: gameLocal->mainMenu, filename: "mpshell", a3: v2, a4: (int)&unk_82340000);
  idMainMenu::Show(this: gameLocal->mainMenu, show: true);
}


// ========================================================================
// __unwind$538262
// EA  : 0x82DB3DAC
// RVA : 0x00DB3DAC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538262()
{
  int v0; // r12

  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(v0 - 4800 + 80));
}


// ========================================================================
// ?LoadGui_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82DB3DD8
// RVA : 0x00DB3DD8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall LoadGui_f(const idCmdArgs *args, int a2, unsigned __int64 a3, int a4)
{
  char *v4; // r4

  if ( args->argc <= 1 )
    v4 = &byte_8200D768;
  else
    v4 = args->argv[1];
  idMainMenu::Load(this: gameLocal->mainMenu, filename: v4, a3, a4);
  idMainMenu::Show(this: gameLocal->mainMenu, show: true);
}


// ========================================================================
// ?EnterMenus@idMainMenu@@QAAXXZ
// EA  : 0x82DB3E50
// RVA : 0x00DB3E50
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::EnterMenus(idMainMenu *this)
{
  idMenuScreen *v2; // r11
  idMenuScreen *v3; // r11
  idSWFScriptObject *scriptObject; // r28
  idSWFSpriteInstance *NestedSprite; // r29
  idSWFSpriteInstance *v6; // r28
  idStaticList<idSWFScriptVar,16> v7; // [sp+50h] [-C0h] BYREF

  if ( swf_useDataDrivenMenus.valueInteger != 0 )
  {
    v2 = this->menuScreens[0];
    if ( v2 != nullptr )
      ((void (*)(void))v2->HideScreen)();
    v3 = this->menuScreens[1];
    if ( v3 != nullptr )
      ((void (*)(void))v3->ShowScreen)();
  }
  else
  {
    scriptObject = this->mainMenu->mainspriteInstance->scriptObject;
    NestedSprite = idSWFScriptObject::GetNestedSprite(
                     this: scriptObject,
                     arg1: "startMenu",
                     arg2: nullptr,
                     arg3: nullptr,
                     arg4: nullptr,
                     arg5: nullptr,
                     arg6: nullptr);
    v6 = idSWFScriptObject::GetNestedSprite(
           this: scriptObject,
           arg1: "mainMenu",
           arg2: nullptr,
           arg3: nullptr,
           arg4: nullptr,
           arg5: nullptr,
           arg6: nullptr);
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v7);
    if ( NestedSprite != nullptr )
    {
      idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v7);
      idSWFParmList::Append(this: (idSWFParmList *)&v7, s: "rollOff");
      idSWFSpriteInstance::PlayFrame(this: NestedSprite, parms: (const idSWFParmList *)&v7);
    }
    if ( this->mainMenu != nullptr && v6 != nullptr )
    {
      idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v7);
      idSWFParmList::Append(this: (idSWFParmList *)&v7, s: "rollOnBack");
      idSWFSpriteInstance::PlayFrame(this: v6, parms: (const idSWFParmList *)&v7);
    }
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v7);
  }
}


// ========================================================================
// __unwind$538319_0
// EA  : 0x82DB3F9C
// RVA : 0x00DB3F9C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538319_0()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 272 + 80));
}


// ========================================================================
// ?ClearCmdButtons@idMainMenu@@QAAXXZ
// EA  : 0x82DB3FD0
// RVA : 0x00DB3FD0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::ClearCmdButtons(idMainMenu *this)
{
  idSWFScriptObject *scriptObject; // r29
  idSWFScriptObject *NestedObj; // r27
  idSWFScriptObject *v4; // r24
  idSWFScriptObject *v5; // r23
  idSWFScriptObject *v6; // r22
  idSWFScriptVar v7; // [sp+50h] [-150h] BYREF
  idSWFScriptVar v8; // [sp+58h] [-148h] BYREF
  idSWFScriptVar v9; // [sp+60h] [-140h] BYREF
  idSWFScriptVar v10; // [sp+68h] [-138h] BYREF
  idSWFScriptVar v11; // [sp+70h] [-130h] BYREF
  idSWFScriptVar v12; // [sp+78h] [-128h] BYREF
  idSWFScriptVar v13; // [sp+80h] [-120h] BYREF
  idSWFScriptVar v14; // [sp+88h] [-118h] BYREF
  idSWFScriptObject v15[2]; // [sp+90h] [-110h] BYREF

  idSWF::GetGlobal(this: (idSWF *)&v15[0].variables.num, result: (idSWFScriptVar *)this->mainMenu, name: "shortcutKeys");
  if ( v15[0].variables.num == 8 )
  {
    idSWFScriptObject::Get(this: v15, result: (idSWFScriptObject *)v15[0].variables.size, name: "clear");
    if ( v15[0].refCount == 7 )
    {
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v15[0].variablesHash[3]);
      idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: (idList<idSWFScriptVar,5> *)&v15[0].variablesHash[3]);
      (*(void (__fastcall **)(__int16 *, idSWFScriptObject::swfNamedVar_t *, _DWORD, int *))(v15[0].variables.list->index
                                                                                           + 4))(
        a1: &v15[0].variables.granularity,
        a2: v15[0].variables.list,
        a3: 0,
        a4: &v15[0].variablesHash[3]);
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v15[0].variables.granularity);
      idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v15[0].variablesHash[3]);
    }
    idSWFScriptVar::Free(this: (idSWFScriptVar *)v15);
  }
  idMainMenu::KillStartButton(this);
  scriptObject = this->mainMenu->mainspriteInstance->scriptObject;
  NestedObj = idSWFScriptObject::GetNestedObj(
                this: scriptObject,
                arg1: "cmdBar",
                arg2: "joy1",
                arg3: nullptr,
                arg4: nullptr,
                arg5: nullptr,
                arg6: nullptr);
  v4 = idSWFScriptObject::GetNestedObj(
         this: scriptObject,
         arg1: "cmdBar",
         arg2: "joy2",
         arg3: nullptr,
         arg4: nullptr,
         arg5: nullptr,
         arg6: nullptr);
  v5 = idSWFScriptObject::GetNestedObj(
         this: scriptObject,
         arg1: "cmdBar",
         arg2: "joy3",
         arg3: nullptr,
         arg4: nullptr,
         arg5: nullptr,
         arg6: nullptr);
  v6 = idSWFScriptObject::GetNestedObj(
         this: scriptObject,
         arg1: "cmdBar",
         arg2: "joy4",
         arg3: nullptr,
         arg4: nullptr,
         arg5: nullptr,
         arg6: nullptr);
  if ( NestedObj != nullptr )
  {
    v13.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v13);
    v13.type = SWF_VAR_INTEGER;
    v13.value.i = 0;
    idSWFScriptObject::Set(this: NestedObj, name: "_visible", value: &v13);
    idSWFScriptVar::Free(this: &v13);
    v9.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v9);
    v9.type = SWF_VAR_INTEGER;
    v9.value.i = 0;
    idSWFScriptObject::Set(this: NestedObj, name: "onPress", value: &v9);
    idSWFScriptVar::Free(this: &v9);
  }
  if ( v4 != nullptr )
  {
    v12.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v12);
    v12.type = SWF_VAR_INTEGER;
    v12.value.i = 0;
    idSWFScriptObject::Set(this: v4, name: "_visible", value: &v12);
    idSWFScriptVar::Free(this: &v12);
    v11.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v11);
    v11.type = SWF_VAR_INTEGER;
    v11.value.i = 0;
    idSWFScriptObject::Set(this: v4, name: "onPress", value: &v11);
    idSWFScriptVar::Free(this: &v11);
  }
  if ( v5 != nullptr )
  {
    v14.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v14);
    v14.type = SWF_VAR_INTEGER;
    v14.value.i = 0;
    idSWFScriptObject::Set(this: v5, name: "_visible", value: &v14);
    idSWFScriptVar::Free(this: &v14);
    v7.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v7);
    v7.type = SWF_VAR_INTEGER;
    v7.value.i = 0;
    idSWFScriptObject::Set(this: v5, name: "onPress", value: &v7);
    idSWFScriptVar::Free(this: &v7);
  }
  if ( v6 != nullptr )
  {
    v8.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v8);
    v8.type = SWF_VAR_INTEGER;
    v8.value.i = 0;
    idSWFScriptObject::Set(this: v6, name: "_visible", value: &v8);
    idSWFScriptVar::Free(this: &v8);
    v10.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v10);
    v10.type = SWF_VAR_INTEGER;
    v10.value.i = 0;
    idSWFScriptObject::Set(this: v6, name: "onPress", value: &v10);
    idSWFScriptVar::Free(this: &v10);
  }
  idStr::operator=(this: &this->btn1Text, text: &byte_8200D768);
  idStr::operator=(this: &this->btn2Text, text: &byte_8200D768);
  idStr::operator=(this: &this->btn3Text, text: &byte_8200D768);
  idStr::operator=(this: &this->btn4Text, text: &byte_8200D768);
  idSWFScriptVar::Free(this: (idSWFScriptVar *)&v15[0].variables.num);
}


// ========================================================================
// __unwind$538372
// EA  : 0x82DB430C
// RVA : 0x00DB430C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538372()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 152));
}


// ========================================================================
// __unwind$538373
// EA  : 0x82DB4334
// RVA : 0x00DB4334
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538373()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 144));
}


// ========================================================================
// __unwind$538374
// EA  : 0x82DB435C
// RVA : 0x00DB435C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538374()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 416 + 176));
}


// ========================================================================
// __unwind$538376
// EA  : 0x82DB4384
// RVA : 0x00DB4384
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538376()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 128));
}


// ========================================================================
// __unwind$538377
// EA  : 0x82DB43AC
// RVA : 0x00DB43AC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538377()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 96));
}


// ========================================================================
// __unwind$538378
// EA  : 0x82DB43D4
// RVA : 0x00DB43D4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538378()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 120));
}


// ========================================================================
// __unwind$538379
// EA  : 0x82DB43FC
// RVA : 0x00DB43FC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538379()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 112));
}


// ========================================================================
// __unwind$538380
// EA  : 0x82DB4424
// RVA : 0x00DB4424
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538380()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 136));
}


// ========================================================================
// __unwind$538381
// EA  : 0x82DB444C
// RVA : 0x00DB444C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538381()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 80));
}


// ========================================================================
// __unwind$538382
// EA  : 0x82DB4474
// RVA : 0x00DB4474
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538382()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 88));
}


// ========================================================================
// __unwind$538383
// EA  : 0x82DB449C
// RVA : 0x00DB449C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538383()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 416 + 104));
}


// ========================================================================
// ?SyncMenuArea@idMainMenu@@QAAXXZ
// EA  : 0x82DB44D0
// RVA : 0x00DB44D0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::SyncMenuArea(idMainMenu *this)
{
  mainMenuScreens_t nextMenu; // r11
  mainMenuScreens_t activeMenu; // r4
  idMenuScreen *v4; // r10
  mainMenuScreens_t v5; // r11
  idMenuScreen *v6; // r10
  idSWFSpriteInstance *MenuSprite; // r29
  idSWFSpriteInstance *NestedSprite; // r29
  idStaticList<idSWFScriptVar,16> *v9; // r3
  mainMenuTransition_t menuTransition; // r11
  idSWFSpriteInstance *v11; // r29
  idSWFSpriteInstance *v12; // r29
  idSWFSpriteInstance *v13; // r29
  idSWFSpriteInstance *v14; // r29
  mainMenuScreens_t v15; // r11
  idStaticList<idSWFScriptVar,16> v16; // [sp+50h] [-380h] BYREF
  idStaticList<idSWFScriptVar,16> v17; // [sp+E0h] [-2F0h] BYREF
  idStaticList<idSWFScriptVar,16> v18; // [sp+170h] [-260h] BYREF
  idStaticList<idSWFScriptVar,16> v19; // [sp+200h] [-1D0h] BYREF
  idStaticList<idSWFScriptVar,16> v20; // [sp+290h] [-140h] BYREF
  idStaticList<idSWFScriptVar,16> v21; // [sp+320h] [-B0h] BYREF

  nextMenu = this->nextMenu;
  activeMenu = this->activeMenu;
  if ( activeMenu != nextMenu )
  {
    if ( swf_useDataDrivenMenus.valueInteger != 0 )
    {
      if ( (unsigned int)activeMenu <= MENU_AUDIO )
      {
        v4 = this->menuScreens[activeMenu];
        if ( v4 != nullptr )
          ((void (*)(void))v4->HideScreen)();
      }
      v5 = this->nextMenu;
      if ( (unsigned int)v5 <= MENU_AUDIO )
      {
        v6 = this->menuScreens[v5];
        if ( v6 != nullptr )
          ((void (*)(void))v6->ShowScreen)();
      }
      goto LABEL_32;
    }
    if ( (unsigned int)nextMenu <= MENU_AUDIO )
    {
      if ( nextMenu != MENU_ROOT && nextMenu != MENU_DEV )
      {
        if ( nextMenu == MENU_CAMPAIGN || nextMenu == MENU_MULTIPLAYER )
          goto LABEL_32;
        if ( nextMenu == MENU_START )
        {
          playerMatchResults[0].shouldShowMatchResults = false;
          playerMatchResults[1].shouldShowMatchResults = false;
          MenuSprite = idMainMenu::GetMenuSprite(this, type: this->activeMenu);
          if ( MenuSprite != nullptr )
          {
            idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v20);
            idSWFParmList::Append(this: (idSWFParmList *)&v20, s: "rollOffBack");
            idSWFSpriteInstance::PlayFrame(this: MenuSprite, parms: (const idSWFParmList *)&v20);
            idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v20);
          }
          NestedSprite = idSWFScriptObject::GetNestedSprite(
                           this: this->mainMenu->mainspriteInstance->scriptObject,
                           arg1: "startMenu",
                           arg2: nullptr,
                           arg3: nullptr,
                           arg4: nullptr,
                           arg5: nullptr,
                           arg6: nullptr);
          if ( NestedSprite == nullptr )
            goto LABEL_32;
          idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v18);
          idSWFParmList::Append(this: (idSWFParmList *)&v18, s: "rollOn");
          idSWFSpriteInstance::PlayFrame(this: NestedSprite, parms: (const idSWFParmList *)&v18);
          v9 = &v18;
          goto LABEL_31;
        }
      }
      if ( activeMenu != MENU_START )
      {
        menuTransition = this->menuTransition;
        if ( menuTransition != MENU_TRANSITION_ADVANCE )
        {
          if ( menuTransition != MENU_TRANSITION_BACK )
            goto LABEL_32;
          v13 = idMainMenu::GetMenuSprite(this, type: activeMenu);
          if ( v13 != nullptr )
          {
            idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v19);
            idSWFParmList::Append(this: (idSWFParmList *)&v19, s: "rollOffBack");
            idSWFSpriteInstance::PlayFrame(this: v13, parms: (const idSWFParmList *)&v19);
            idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v19);
          }
          v14 = idMainMenu::GetMenuSprite(this, type: this->nextMenu);
          if ( v14 == nullptr )
            goto LABEL_32;
          idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v21);
          idSWFParmList::Append(this: (idSWFParmList *)&v21, s: "rollOnFront");
          idSWFSpriteInstance::PlayFrame(this: v14, parms: (const idSWFParmList *)&v21);
          v9 = &v21;
        }
        else
        {
          v11 = idMainMenu::GetMenuSprite(this, type: activeMenu);
          if ( v11 != nullptr )
          {
            idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v16);
            idSWFParmList::Append(this: (idSWFParmList *)&v16, s: "rollOffFront");
            idSWFSpriteInstance::PlayFrame(this: v11, parms: (const idSWFParmList *)&v16);
            idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v16);
          }
          v12 = idMainMenu::GetMenuSprite(this, type: this->nextMenu);
          if ( v12 == nullptr )
            goto LABEL_32;
          idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v17);
          idSWFParmList::Append(this: (idSWFParmList *)&v17, s: "rollOnBack");
          idSWFSpriteInstance::PlayFrame(this: v12, parms: (const idSWFParmList *)&v17);
          v9 = &v17;
        }
LABEL_31:
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: v9);
        goto LABEL_32;
      }
      idMainMenu::KillStartButton(this);
      idMainMenu::EnterMenus(this);
    }
LABEL_32:
    v15 = this->nextMenu;
    this->menuTransition = MENU_TRANSITION_INVALID;
    this->activeMenu = v15;
  }
}


// ========================================================================
// __unwind$538589
// EA  : 0x82DB47C0
// RVA : 0x00DB47C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538589()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 976 + 656));
}


// ========================================================================
// __unwind$538590
// EA  : 0x82DB47E8
// RVA : 0x00DB47E8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538590()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 976 + 368));
}


// ========================================================================
// __unwind$538591
// EA  : 0x82DB4810
// RVA : 0x00DB4810
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538591()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 976 + 80));
}


// ========================================================================
// __unwind$538592
// EA  : 0x82DB4838
// RVA : 0x00DB4838
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538592()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 976 + 224));
}


// ========================================================================
// __unwind$538593
// EA  : 0x82DB4860
// RVA : 0x00DB4860
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538593()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 976 + 512));
}


// ========================================================================
// __unwind$538594
// EA  : 0x82DB4888
// RVA : 0x00DB4888
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538594()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 976 + 800));
}


// ========================================================================
// ?Init@idMainMenu@@QAAXXZ
// EA  : 0x82DB48B8
// RVA : 0x00DB48B8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::Init(idMainMenu *this)
{
  idRenderModelGui *v2; // r3
  idRenderModelGui *v3; // r3
  idLBCache *v4; // r3
  idLBCache *v5; // r3
  idSoundWorld *v6; // r3
  __int64 v7; // r10
  unsigned __int64 v8; // r8
  int v9; // r6
  int v10; // r5
  int v11; // r4
  __int64 v12; // r10
  unsigned __int64 v13; // r8
  int v14; // r6
  int v15; // r5
  int v16; // r4
  mainMenuTransition_t *p_menuTransition; // r10
  int i; // ctr
  idMenuWidget *v19; // r3
  idMenuScreen *v20; // r29
  idMenuScreen *v21; // r3
  idMenuWidget *v22; // r3
  idMenuScreen *v23; // r29
  idMenuScreen *v24; // r3
  idMenuWidget *v25; // r3
  idMenuScreen *v26; // r29
  idMenuScreen *v27; // r3
  idMenuWidget *v28; // r3
  idMenuWidget *v29; // r29
  idMenuScreen *v30; // r3
  idMenuWidget *v31; // r3
  idMenuScreen *v32; // r29
  idMenuScreen *v33; // r3

  v2 = (idRenderModelGui *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0xA410u,
                             tag: TAG_GUI_MODEL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idRenderModelGui::idRenderModelGui(this: v2);
  else
    v3 = nullptr;
  this->guiModel = v3;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v4 = (idLBCache *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0xA0u,
                      tag: TAG_GUI,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idLBCache::idLBCache(this: v4);
  else
    v5 = nullptr;
  this->lbCache = v5;
  v6 = soundSystem->AllocSoundWorld(this: soundSystem, a2: 0, a3: 0);
  this->soundWorld = v6;
  v6->PlaceListener(this: v6, a2: &vec3_origin, a3: &mat3_identity, a4: &vec3_origin, a5: 0);
  InitLeaderboards();
  idMainMenu::LoadMultiplayerDecls(this);
  idDeclChapter::LoadAllDecls();
  idDeclSecretType::LoadAllDecls();
  idDeclSecrets::LoadAllDecls();
  LoadResourcesAndSortBySortId<idDeclChapter>(
    list: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->chapters,
    a2: v11,
    a3: v10,
    a4: v9,
    a5: v8,
    a6: v7);
  LoadResourcesAndSortBySortId<idDeclSecretType>(
    list: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->secretTypes,
    a2: v16,
    a3: v15,
    a4: v14,
    a5: v13,
    a6: v12);
  idSignInManagerXbox::SetDeviceSelectorSignal(
    this: (idSignInManagerXbox *)session->signInManager,
    signal: &this->deviceRequestedSignal);
  p_menuTransition = &this->menuTransition;
  for ( i = 7; i != 0; --i )
    *++p_menuTransition = MENU_TRANSITION_ADVANCE;
  v19 = (idMenuWidget *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0xB4u,
                          tag: TAG_SWF,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v20 = (idMenuScreen *)v19;
  if ( v19 != nullptr )
  {
    idMenuWidget::idMenuWidget(this: v19);
    v21 = v20;
    v20->__vftable = (idMenuScreen_vtbl *)&idMenuScreen_Root::`vftable';
  }
  else
  {
    v21 = nullptr;
  }
  this->menuScreens[1] = v21;
  v21->Initialize(this: v21);
  v22 = (idMenuWidget *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0xB4u,
                          tag: TAG_SWF,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v23 = (idMenuScreen *)v22;
  if ( v22 != nullptr )
  {
    idMenuWidget::idMenuWidget(this: v22);
    v24 = v23;
    v23->__vftable = (idMenuScreen_vtbl *)&idMenuScreen_Start::`vftable';
  }
  else
  {
    v24 = nullptr;
  }
  this->menuScreens[0] = v24;
  v24->Initialize(this: v24);
  v25 = (idMenuWidget *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0xB4u,
                          tag: TAG_SWF,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v26 = (idMenuScreen *)v25;
  if ( v25 != nullptr )
  {
    idMenuWidget::idMenuWidget(this: v25);
    v27 = v26;
    v26->__vftable = (idMenuScreen_vtbl *)&idMenuScreen_Settings::`vftable';
  }
  else
  {
    v27 = nullptr;
  }
  this->menuScreens[5] = v27;
  v27->Initialize(this: v27);
  v28 = (idMenuWidget *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x128u,
                          tag: TAG_SWF,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v29 = v28;
  if ( v28 != nullptr )
  {
    idMenuWidget::idMenuWidget(this: v28);
    v29->__vftable = (idMenuWidget_vtbl *)&idMenuScreen_AudioSettings::`vftable';
    idMenuScreen_AudioSettings::idMenuDataSource_AudioSettings::idMenuDataSource_AudioSettings(this: (idMenuScreen_AudioSettings::idMenuDataSource_AudioSettings *)&v29[1]);
    v30 = (idMenuScreen *)v29;
  }
  else
  {
    v30 = nullptr;
  }
  this->menuScreens[6] = v30;
  v30->Initialize(this: v30);
  v31 = (idMenuWidget *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0xB8u,
                          tag: TAG_SWF,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v32 = (idMenuScreen *)v31;
  if ( v31 != nullptr )
  {
    idMenuWidget::idMenuWidget(this: v31);
    v32[1].__vftable = nullptr;
    v33 = v32;
    v32->__vftable = (idMenuScreen_vtbl *)&idMenuScreen_Dev::`vftable';
  }
  else
  {
    v33 = nullptr;
  }
  this->menuScreens[2] = v33;
  v33->Initialize(this: v33);
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$538780
// EA  : 0x82DB4C08
// RVA : 0x00DB4C08
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538780()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_GUI_MODEL);
}


// ========================================================================
// __unwind$538781
// EA  : 0x82DB4C34
// RVA : 0x00DB4C34
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538781()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 144 + 84));
}


// ========================================================================
// __unwind$538782
// EA  : 0x82DB4C5C
// RVA : 0x00DB4C5C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538782()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_GUI);
}


// ========================================================================
// __unwind$538783
// EA  : 0x82DB4C88
// RVA : 0x00DB4C88
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538783()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$538784
// EA  : 0x82DB4CB4
// RVA : 0x00DB4CB4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538784()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$538785
// EA  : 0x82DB4CE0
// RVA : 0x00DB4CE0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538785()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$538786
// EA  : 0x82DB4D0C
// RVA : 0x00DB4D0C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538786()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$538843
// EA  : 0x82DB4D38
// RVA : 0x00DB4D38
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538843()
{
  int v0; // r12

  idMenuWidget_List::~idMenuWidget_List(this: *(idMenuScreen **)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$538787
// EA  : 0x82DB4D60
// RVA : 0x00DB4D60
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538787()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SWF);
}


// ========================================================================
// ?Update@idMainMenu@@QAAXXZ
// EA  : 0x82DB4D98
// RVA : 0x00DB4D98
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::Update(idMainMenu *this)
{
  int currentDeviceIndex; // r11
  idSession *v3; // r3
  idStaticList<idSWFScriptVar,16> v4; // [sp+50h] [-1E0h] BYREF
  idStaticList<idSWFScriptVar,16> v5; // [sp+E0h] [-150h] BYREF
  idStaticList<idSWFScriptVar,16> v6; // [sp+170h] [-C0h] BYREF

  if ( !session->IsEnumerating(this: session) && Sys_SignalWait(handle: &this->deviceRequestedSignal.handle, timeout: 0) )
  {
    if ( this->askToDeleteAutosaveOnNewGame || this->storageDialogActivated )
    {
      this->askToDeleteAutosaveOnNewGame = false;
      this->storageDialogActivated = false;
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v6);
      idSWF::Invoke(this: this->mainMenu, functionName: "resetLoadMostRecent", parms: (const idSWFParmList *)&v6);
      idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v6);
    }
    common->ClearDialog(this: common, a2: GDM_DELETE_SAVE, a3: nullptr, a4: 0);
    currentDeviceIndex = this->currentDeviceIndex;
    this->requestingDevice = false;
    this->currentDeviceIndex = currentDeviceIndex + 1;
    session->EnumerateSaveGamesSync(this: session);
    idMainMenu::UpdateSavedGameList(this);
    idLib::Printf(fmt: "Device selector choice confirmed.\n");
  }
  if ( this->saveAfterDeviceRequest && this->autosaveWarningShown )
  {
    if ( this->autosaveWarningShownAllowsAutosave )
      gameLocal->SaveGame(this: gameLocal, a2: this->saveAfterDeviceRequestFolder.data, a3: false, a4: false);
    this->saveAfterDeviceRequest = false;
    this->autosaveWarningShown = false;
    this->autosaveWarningShownAllowsAutosave = false;
  }
  v3 = session;
  if ( this->requestingDevice && BYTE1(session->signInManager[7].minDesiredLocalUsers) == 0 )
  {
    idMainMenu::RefreshSaveData(this, changed: false);
    v3 = session;
  }
  if ( this->requestingDLC )
  {
    if ( !v3->IsSystemUIShowing(this: v3) )
    {
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v5);
      idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v5);
      idSWF::Invoke(this: this->mainMenu, functionName: "restoreMainMenuButtons", parms: (const idSWFParmList *)&v5);
      this->requestingDLC = false;
      idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v5);
    }
    v3 = session;
  }
  if ( this->ps3MenuRequested && !v3->IsSystemUIShowing(this: v3) )
  {
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v4);
    idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v4);
    idSWF::Invoke(this: this->mainMenu, functionName: "restorePS3MenuButtons", parms: (const idSWFParmList *)&v4);
    this->ps3MenuRequested = false;
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v4);
  }
  idMainMenu::UpdatePauseMenuState(this);
}


// ========================================================================
// __unwind$538936
// EA  : 0x82DB4FD4
// RVA : 0x00DB4FD4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538936()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 560 + 368));
}


// ========================================================================
// __unwind$538937
// EA  : 0x82DB4FFC
// RVA : 0x00DB4FFC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538937()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 560 + 224));
}


// ========================================================================
// __unwind$538938_0
// EA  : 0x82DB5024
// RVA : 0x00DB5024
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_538938_0()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 560 + 80));
}


// ========================================================================
// ?LoadMainMenu@idMainMenu@@QAAXXZ
// EA  : 0x82DB5058
// RVA : 0x00DB5058
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::LoadMainMenu(idMainMenu *this, int a2, unsigned __int64 a3, int a4)
{
  idMainMenu *v4; // r30
  int i; // r29
  const idStr *v6; // r3
  int v7; // r7
  unsigned __int64 v8; // r6
  char *data; // r4
  idStr v10[2]; // [sp+50h] [-50h] BYREF

  v4 = this;
  if ( com_multiplayer.valueInteger != 0 )
  {
    idMainMenu::Load(this, filename: "tungshell", a3, a4);
    idMainMenu::LoadMultiplayerDecls(this: v4);
    v4->menuArea = MENU_PRESS_START;
    v4->desiredMenuArea = MENU_PRESS_START;
    v4->activeMenu = MENU_AREA_INVALID;
    v4->nextMenu = MENU_START;
    idMainMenu::SetupMultiplayerMenu(this: v4);
    cmdSystem->AppendCommandText(this: cmdSystem, a2: "exec default_mp.cfg\n");
    HIDWORD(a3) = allocationCurrent[242];
    if ( (unsigned int)idLib::production <= PROD_BUILDING )
    {
      for ( i = 0; i < idDeclMenuPopup::resourceList.num; ++i )
      {
        v6 = (const idStr *)idResourceList::Index(this: &idDeclMenuPopup::resourceList, index: i);
        if ( v6 != nullptr )
        {
          idStr::idStr(this: v10, text: v6 + 2);
          idMainMenu::Load(this: v4, filename: v10[0].data, a3: v8, a4: v7);
          idStr::FreeData(this: v10);
        }
      }
    }
    this = v4;
    data = swf_mp_shell.valueString.data;
  }
  else
  {
    this->menuArea = MENU_PRESS_START;
    this->desiredMenuArea = MENU_PRESS_START;
    this->activeMenu = MENU_AREA_INVALID;
    data = "tungshell";
    this->nextMenu = MENU_START;
  }
  idMainMenu::Load(this, filename: data, a3, a4);
  v4->isProfileScreenOpenBool = false;
  idMainMenu::Show(this: v4, show: true);
}


// ========================================================================
// __unwind$539013
// EA  : 0x82DB5198
// RVA : 0x00DB5198
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539013()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?EnableMultiplayer@idMainMenu@@AAAX_N@Z
// EA  : 0x82DB51C0
// RVA : 0x00DB51C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::EnableMultiplayer(idMainMenu *this, bool enable)
{
  int v2; // r7
  unsigned __int64 v3; // r6
  int v4; // r4

  if ( (com_multiplayer.valueInteger != 0) != enable )
  {
    idCVar::SetBool(this: &com_multiplayer, newValue: enable, force: true);
    idMainMenu::LoadMainMenu(this: gameLocal->mainMenu, a2: v4, a3: v3, a4: v2);
  }
}


// ========================================================================
// `idMainMenu::ShowOverwriteSavingDialog'::`7'::idSWFScriptFunction_DeclineOverwrite::Call
// EA  : 0x82DB5220
// RVA : 0x00DB5220
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::ShowOverwriteSavingDialog_::_7_::idSWFScriptFunction_DeclineOverwrite::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  common->ClearDialog(this: common, a2: GDM_OVERWRITE_SAVE, a3: nullptr, a4: 0);
  idMainMenu::RefreshSaveData(this: (idMainMenu *)thisObject->variables.num, changed: false);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idMainMenu::DeleteSaveGameConfirm'::`2'::idSWFScriptFunction_CancelDelete::Call
// EA  : 0x82DB5290
// RVA : 0x00DB5290
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::DeleteSaveGameConfirm_::_2_::idSWFScriptFunction_CancelDelete::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  common->ClearDialog(this: common, a2: GDM_DELETE_SAVE, a3: nullptr, a4: 0);
  idMainMenu::RefreshSaveData(this: (idMainMenu *)thisObject->variables.num, changed: false);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idMainMenu::UpdateCmds_Start'::`5'::idSWFScriptFunction_startPress::Call
// EA  : 0x82DB5300
// RVA : 0x00DB5300
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::UpdateCmds_Start_::_5_::idSWFScriptFunction_startPress::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms,
        int a4)
{
  int v7; // r29
  int size; // r6

  if ( *(_DWORD *)(a4 + 4) == 1 )
  {
    v7 = idSWFScriptVar::ToInteger(this: *(idSWFScriptVar **)a4);
    idMainMenu::ClearCmdButtons(this: (idMainMenu *)thisObject->variables.size);
    session->signInManager->RegisterLocalUser(this: session->signInManager, a2: v7);
    size = thisObject->variables.size;
    result->type = SWF_VAR_UNDEF;
    *(_DWORD *)(size + 332) = 1;
    return result;
  }
  else
  {
    idLib::Warning(fmt: "No device specified when registering mouse user");
    result->type = SWF_VAR_UNDEF;
    return result;
  }
}


// ========================================================================
// ?ScrollActiveScreen@idMainMenu@@QAAX_N0@Z
// EA  : 0x82DB53A0
// RVA : 0x00DB53A0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::ScrollActiveScreen(idMainMenu *this, bool up, bool fast)
{
  mainMenuScreens_t activeMenu; // r11
  int v7; // r11
  int v8; // r10
  idSWFSpriteInstance *MenuSprite; // r3
  idSWFSpriteInstance *v10; // r30
  const char *v11; // r4
  idSWFScriptObject *p_num; // r3
  int v13; // r11
  int v14; // r8
  int v15; // r10
  idSWFSpriteInstance *v16; // r3
  idSWFSpriteInstance *v17; // r30
  const char *v18; // r4
  idSWFScriptObject v19; // [sp+50h] [-290h] BYREF
  idStaticList<idSWFScriptVar,16> v20; // [sp+100h] [-1E0h] BYREF
  idStaticList<idSWFScriptVar,16> v21; // [sp+190h] [-150h] BYREF
  idStaticList<idSWFScriptVar,16> v22; // [sp+220h] [-C0h] BYREF

  if ( !this->scrollingMenu )
  {
    idMainMenu::ClearActiveMenuOnEnterFrame(this);
    if ( swf_useDataDrivenMenus.valueInteger != 0 )
    {
      if ( this->menuScreens[this->activeMenu] != nullptr )
      {
        idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v22);
        *(_DWORD *)&v19.variables.granularity = !up ? 8 : 6;
        v19.variablesHash[0] = 0;
        v19.variablesHash[1] = 0;
        idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(
          this: (idStaticList<idSWFScriptVar,16> *)&v19.variablesHash[2],
          other: &v22);
        idMenuWidget::ReceiveEvent(
          this: this->menuScreens[this->activeMenu],
          event: (const idWidgetEvent *)&v19.variables.granularity);
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v19.variablesHash[2]);
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v22);
      }
      return;
    }
    activeMenu = this->activeMenu;
    if ( up )
    {
      v7 = 4 * (activeMenu + 92);
      v8 = *(int *)((char *)&this->actionRepeater.widget + v7);
      if ( v8 > 0 )
      {
        *(idMenuWidget **)((char *)&this->actionRepeater.widget + v7) = (idMenuWidget *)(v8 - 1);
        this->scrollingMenu = true;
        MenuSprite = idMainMenu::GetMenuSprite(this, type: this->activeMenu);
        if ( MenuSprite != nullptr )
        {
          idSWFScriptObject::Get(
            this: (idSWFScriptObject *)&v19.variables.num,
            result: MenuSprite->scriptObject,
            name: "options");
          v10 = idSWFScriptVar::ToSprite(this: (idSWFScriptVar *)&v19.variables.num);
          if ( v10 != nullptr )
          {
            idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v20);
            if ( fast )
              v11 = "rollUpFast";
            else
              v11 = "rollUp";
            idSWFParmList::Append(this: (idSWFParmList *)&v20, s: v11);
            idSWFSpriteInstance::PlayFrame(this: v10, parms: (const idSWFParmList *)&v20);
            idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v20);
          }
          p_num = (idSWFScriptObject *)&v19.variables.num;
_M539254:
          idSWFScriptVar::Free(this: (idSWFScriptVar *)p_num);
        }
      }
    }
    else
    {
      v14 = 4 * (activeMenu + 99);
      v13 = 4 * (activeMenu + 92);
      v15 = *(int *)((char *)&this->actionRepeater.widget + v13);
      if ( v15 + 1 < *(int *)((char *)&this->actionRepeater.widget + v14) )
      {
        *(idMenuWidget **)((char *)&this->actionRepeater.widget + v13) = (idMenuWidget *)(v15 + 1);
        this->scrollingMenu = true;
        v16 = idMainMenu::GetMenuSprite(this, type: this->activeMenu);
        if ( v16 != nullptr )
        {
          idSWFScriptObject::Get(this: &v19, result: v16->scriptObject, name: "options");
          v17 = idSWFScriptVar::ToSprite(this: (idSWFScriptVar *)&v19);
          if ( v17 != nullptr )
          {
            idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v21);
            if ( fast )
              v18 = "rollDownFast";
            else
              v18 = "rollDown";
            idSWFParmList::Append(this: (idSWFParmList *)&v21, s: v18);
            idSWFSpriteInstance::PlayFrame(this: v17, parms: (const idSWFParmList *)&v21);
            idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v21);
          }
          p_num = &v19;
          goto _M539254;
        }
      }
    }
  }
}


// ========================================================================
// __unwind$539169
// EA  : 0x82DB55EC
// RVA : 0x00DB55EC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539169()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 736 + 544));
}


// ========================================================================
// __unwind$539170
// EA  : 0x82DB5614
// RVA : 0x00DB5614
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539170()
{
  int v0; // r12

  idWidgetEvent::~idWidgetEvent(this: (idWidgetEvent *)(v0 - 736 + 96));
}


// ========================================================================
// __unwind$539171
// EA  : 0x82DB563C
// RVA : 0x00DB563C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539171()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 736 + 88));
}


// ========================================================================
// __unwind$539172
// EA  : 0x82DB5664
// RVA : 0x00DB5664
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539172()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 736 + 256));
}


// ========================================================================
// __unwind$539173
// EA  : 0x82DB568C
// RVA : 0x00DB568C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539173()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 736 + 80));
}


// ========================================================================
// __unwind$539174
// EA  : 0x82DB56B4
// RVA : 0x00DB56B4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539174()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 736 + 400));
}


// ========================================================================
// `idMainMenu::UpdateScrollCmds'::`2'::idSWFScriptFunction_scroll::Call
// EA  : 0x82DB56E0
// RVA : 0x00DB56E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::UpdateScrollCmds_::_2_::idSWFScriptFunction_scroll::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu::ScrollActiveScreen(
    this: (idMainMenu *)thisObject->variables.size,
    up: HIBYTE(thisObject->variables.granularity),
    fast: false);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idMainMenu::UpdateScrollCmds'::`3'::idSWFScriptFunction_scrollWheel::Call
// EA  : 0x82DB5728
// RVA : 0x00DB5728
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::UpdateScrollCmds_::_3_::idSWFScriptFunction_scrollWheel::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu::ScrollActiveScreen(
    this: (idMainMenu *)thisObject->variables.size,
    up: HIBYTE(thisObject->variables.granularity),
    fast: true);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?UpdateSPMPMenuState@idMainMenu@@QAAXXZ
// EA  : 0x82DB5770
// RVA : 0x00DB5770
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateSPMPMenuState(idMainMenu *this)
{
  menuSwitchRequest_t menuRequest; // r11
  bool v3; // r4

  menuRequest = this->menuRequest;
  if ( menuRequest != MENU_SWITCH_NONE )
  {
    if ( menuRequest == MENU_SWITCH_MP )
    {
      v3 = true;
    }
    else
    {
      if ( menuRequest != MENU_SWITCH_SP )
      {
LABEL_7:
        this->menuRequest = MENU_SWITCH_NONE;
        return;
      }
      v3 = false;
    }
    idMainMenu::EnableMultiplayer(this, enable: v3);
    goto LABEL_7;
  }
}


// ========================================================================
// ?Render@idMainMenu@@QAAPAVidRenderModelGui@@XZ
// EA  : 0x82DB57D8
// RVA : 0x00DB57D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idRenderModelGui *__fastcall idMainMenu::Render(idMainMenu *this)
{
  int v3; // r7
  unsigned __int64 v4; // r6
  unsigned int v5; // r26
  unsigned int v6; // r3
  int v7; // r27
  __int64 v8; // r6
  int v9; // r9
  int v10; // r8
  int v11; // r7
  const char *v12; // r7
  idSWF *mainMenu; // r11
  const char *v14; // r7
  idSWF *v15; // r3
  bool isActive; // r28
  int valueInteger; // r29
  int v18; // r4
  idSWF *testGui; // r3
  idSWF *popupGui; // r29
  idSWF *v21; // r3
  BOOL showingMatchResults; // r10
  idSWFScriptVar *v23; // r3
  __int64 v24; // [sp+8h] [-128h]
  idSWFScriptVar v25; // [sp+58h] [-D8h] BYREF
  idStaticList<idSWFScriptVar,16> v26; // [sp+60h] [-D0h] BYREF

  if ( idLib::headless )
  {
    idMainMenu::EnsureHeadlessServer(this);
    return nullptr;
  }
  if ( com_multiplayer.valueInteger != 0
    && session->GetState(this: session) == PRESS_START
    && com_production.valueInteger == 0 )
  {
    this->menuRequest = MENU_SWITCH_SP;
  }
  idMainMenu::UpdateSPMPMenuState(this);
  idRenderModelGui::Clear(
    this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
    a2: defaultExtraGLState,
    bits: v4,
    a4: v3);
  v5 = renderSystem->GetHeight(this: renderSystem);
  v6 = renderSystem->GetWidth(this: renderSystem);
  idRenderModelGui::SetViewport(this: this->guiModel, x: 0, y: 0, width: v6, height: v5);
  renderSystem->GetWidth(this: renderSystem);
  v7 = renderSystem->GetHeight(this: renderSystem);
  renderSystem->GetPixelAspect(this: renderSystem);
  HIDWORD(v8) = v7;
  idRenderModelGui::SetVirtualSize(this: this->guiModel, height: v8, a3: v11, a4: v10, a5: v9, a6: v24);
  if ( this->mainMenu != nullptr )
  {
    if ( this->deferredActivateMsec <= 0 )
    {
      if ( this->deferredDeactivateMsec > 0 )
      {
        if ( (signed int)Sys_Milliseconds() <= this->deferredDeactivateMsec )
          return nullptr;
        if ( swf_debugDeferredDelay.valueInteger != 0 )
          idLib::Printf(fmt: "resetting deferredDeactivateMsec\n");
        this->deferredDeactivateMsec = 0;
      }
    }
    else if ( (signed int)Sys_Milliseconds() > this->deferredActivateMsec )
    {
      if ( swf_debugDeferredDelay.valueInteger != 0 )
        idLib::Printf(fmt: "resetting deferredActivateMsec\n");
      this->deferredActivateMsec = 0;
      idMainMenu::InternalActivate(this);
    }
  }
  mainMenu = this->mainMenu;
  if ( mainMenu != nullptr && mainMenu->isActive )
  {
    idMainMenu::Update(this);
    if ( com_multiplayer.valueInteger == 0 )
      idMainMenu::SyncMenuArea(this);
    idMainMenu::UpdateMPMenu(this);
    idMainMenu::EnsureHeadlessServer(this);
    idMainMenu::PumpWidgetActionRepeater(this);
    idLBCache::Pump(this: this->lbCache);
    if ( this->refreshWhenMasterIsOnline && idSignInManagerBase::IsMasterLocalUserOnline(this: session->signInManager) )
    {
      idMainMenu::SetLeaderboardIndex(this, isVDM: this->vdmLeaderboard);
      this->refreshWhenMasterIsOnline = false;
    }
    if ( this->refreshLeaderboard )
    {
      idMainMenu::RefreshLeaderboard(this);
      this->refreshLeaderboard = false;
    }
    v15 = this->mainMenu;
    isActive = v15->isActive;
    idSWF::Render(this: v15, gui: this->guiModel, time: 0, isSplitscreen: false, a5: v14);
    valueInteger = swf_deferredDelayMsec.valueInteger;
    if ( swf_deferredDelayMsec.valueInteger > 0 && isActive && !this->mainMenu->isActive )
    {
      v18 = Sys_Milliseconds() + valueInteger;
      this->deferredDeactivateMsec = v18;
      if ( swf_debugDeferredDelay.valueInteger != 0 )
        idLib::Printf(fmt: "setting deferredDeactivateMsec to %i msec\n", v18);
    }
  }
  testGui = this->testGui;
  if ( testGui != nullptr )
    idSWF::Render(this: testGui, gui: this->guiModel, time: 0, isSplitscreen: false, a5: v12);
  popupGui = this->popupGui;
  if ( popupGui != nullptr )
  {
    v21 = this->popupGui;
    if ( this->closePopupGui )
    {
      idSWF::~idSWF(this: v21);
      idMem::Free(this: &mem, ptr: popupGui, align: ALIGN_16);
      showingMatchResults = this->showingMatchResults;
      this->popupGui = nullptr;
      this->closePopupGui = false;
      if ( showingMatchResults )
      {
        idMainMenu::ShowNextMatchResultPopup(this);
      }
      else
      {
        idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v26);
        v23 = idSWFScriptVar::idSWFScriptVar(this: &v25, i: (idSWFScriptVar::swfScriptVarValue_t *)this->popupResult);
        idSWFParmList::Append(this: (idSWFParmList *)&v26, other: v23);
        idSWFScriptVar::Free(this: &v25);
        idSWF::Invoke(this: this->mainMenu, functionName: this->popupCallback.data, parms: (const idSWFParmList *)&v26);
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v26);
      }
    }
    else
    {
      idSWF::Render(this: v21, gui: this->guiModel, time: 0, isSplitscreen: false, a5: v12);
    }
  }
  return this->guiModel;
}


// ========================================================================
// __unwind$539343
// EA  : 0x82DB5BB0
// RVA : 0x00DB5BB0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539343()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 304 + 96));
}


// ========================================================================
// __unwind$539344
// EA  : 0x82DB5BD8
// RVA : 0x00DB5BD8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539344()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 88));
}


// ========================================================================
// ?UpdateMenuDisplay@idMainMenu@@QAAXW4mainMenuScreens_t@@@Z
// EA  : 0x82DB5C00
// RVA : 0x00DB5C00
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateMenuDisplay(idMainMenu *this, mainMenuScreens_t menu)
{
  idMenuScreen *v3; // r10

  if ( menu == MENU_AREA_INVALID )
    menu = this->activeMenu;
  if ( swf_useDataDrivenMenus.valueInteger != 0 && (v3 = this->menuScreens[menu]) != nullptr )
  {
    ((void (*)(void))v3->Update)();
  }
  else if ( (unsigned int)menu <= MENU_AUDIO )
  {
    switch ( menu )
    {
      case MENU_ROOT:
        idMainMenu::UpdateMenu_Root(this);
        break;
      case MENU_DEV:
        idMainMenu::UpdateMenu_Dev(this);
        break;
      case MENU_CAMPAIGN:
      case MENU_MULTIPLAYER:
LABEL_20:
        break;
      case MENU_SETTINGS:
        idMainMenu::UpdateMenu_Settings(this);
        break;
      default:
        if ( menu != MENU_START )
        {
          idMainMenu::UpdateMenu_Audio(this);
        }
        else
        {
          idMainMenu::ClearCmdButtons(this);
          idMainMenu::UpdateButtonBar(this);
        }
        goto LABEL_20;
    }
  }
}


// ========================================================================
// ?HandleMenuSelection@idMainMenu@@QAAXW4mainMenuTransition_t@@@Z
// EA  : 0x82DB5D30
// RVA : 0x00DB5D30
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::HandleMenuSelection(idMainMenu *this, mainMenuTransition_t type)
{
  idMenuScreen *v4; // r10
  mainMenuScreens_t activeMenu; // r11

  if ( swf_useDataDrivenMenus.valueInteger != 0 && (v4 = this->menuScreens[this->activeMenu]) != nullptr )
  {
    ((void (*)(void))v4->HandleMenu)();
  }
  else if ( !this->scrollingMenu )
  {
    idMainMenu::ClearActiveMenuOnEnterFrame(this);
    activeMenu = this->activeMenu;
    if ( (unsigned int)activeMenu <= MENU_AUDIO )
    {
      switch ( activeMenu )
      {
        case MENU_ROOT:
          idMainMenu::HandleMenu_Root(this, type);
          break;
        case MENU_DEV:
          idMainMenu::HandleMenu_Dev(this, type);
          break;
        case MENU_CAMPAIGN:
        case MENU_MULTIPLAYER:
LABEL_21:
          break;
        case MENU_SETTINGS:
          idMainMenu::HandleMenu_Settings(this, type);
          break;
        default:
          if ( activeMenu != MENU_START )
          {
            idMainMenu::HandleMenu_Audio(this, type);
          }
          else
          {
            if ( type == MENU_TRANSITION_ADVANCE )
              idMainMenu::EnterMenus(this);
            this->menuTransition = type;
          }
          goto LABEL_21;
      }
    }
  }
}


// ========================================================================
// ?UpdateScrolling@idMainMenu@@QAAXXZ
// EA  : 0x82DB5E48
// RVA : 0x00DB5E48
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateScrolling(idMainMenu *this)
{
  int scrollCounter; // r11
  __int32 v3; // r10
  int v4; // r11
  idMenuWidget *v5; // r9
  __int32 v6; // r10
  int v7; // r11
  const char *v8; // r29
  idSWFSpriteInstance *MenuSprite; // r3
  idSWFSpriteInstance *v10; // r3
  mainMenuScreens_t activeMenu; // r4
  idSWFScriptVar v12[6]; // [sp+50h] [-30h] BYREF

  if ( !this->scrollingMenu )
    return;
  scrollCounter = this->scrollCounter;
  if ( scrollCounter > 0 )
  {
    v3 = this->activeMenu + 92;
    this->scrollCounter = scrollCounter - 1;
    v4 = 4 * v3;
    v5 = (idMenuWidget *)(*((_DWORD *)&this->actionRepeater.widget + v3) + 1);
LABEL_6:
    *(idMenuWidget **)((char *)&this->actionRepeater.widget + v4) = v5;
    goto LABEL_7;
  }
  if ( scrollCounter < 0 )
  {
    v6 = this->activeMenu + 92;
    this->scrollCounter = scrollCounter + 1;
    v4 = 4 * v6;
    v5 = (idMenuWidget *)(*((_DWORD *)&this->actionRepeater.widget + v6) - 1);
    goto LABEL_6;
  }
LABEL_7:
  v7 = this->scrollCounter;
  if ( v7 != 0 )
  {
    if ( v7 <= 0 )
      v8 = "rollUpFast";
    else
      v8 = "rollDownFast";
    idMainMenu::UpdateMenuDisplay(this, menu: this->activeMenu);
    MenuSprite = idMainMenu::GetMenuSprite(this, type: this->activeMenu);
    if ( MenuSprite != nullptr )
    {
      idSWFScriptObject::Get(this: (idSWFScriptObject *)v12, result: MenuSprite->scriptObject, name: "options");
      v10 = idSWFScriptVar::ToSprite(this: v12);
      if ( v10 != nullptr )
        idSWFSpriteInstance::PlayFrame(this: v10, frameName: v8);
      idSWFScriptVar::Free(this: v12);
    }
  }
  else
  {
    activeMenu = this->activeMenu;
    this->scrollingMenu = false;
    idMainMenu::UpdateMenuDisplay(this, menu: activeMenu);
  }
  if ( !this->scrollingMenu && this->activeMenu == MENU_AUDIO )
    idMainMenu::UpdateAdjustmentCmds(this, menuName: "audioMenu");
}


// ========================================================================
// __unwind$539474
// EA  : 0x82DB5F78
// RVA : 0x00DB5F78
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539474()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 128 + 80));
}


// ========================================================================
// `idMainMenu::UpdateAcceptBackCmds'::`2'::idSWFScriptFunction_accept::Call
// EA  : 0x82DB5FA0
// RVA : 0x00DB5FA0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::UpdateAcceptBackCmds_::_2_::idSWFScriptFunction_accept::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *size; // r3

  size = (idMainMenu *)thisObject->variables.size;
  if ( size != nullptr )
    idMainMenu::HandleMenuSelection(this: size, type: MENU_TRANSITION_ADVANCE);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idMainMenu::UpdateAcceptBackCmds'::`14'::idSWFScriptFunction_back::Call
// EA  : 0x82DB5FE8
// RVA : 0x00DB5FE8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::UpdateAcceptBackCmds_::_14_::idSWFScriptFunction_back::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *size; // r3

  size = (idMainMenu *)thisObject->variables.size;
  if ( size != nullptr )
    idMainMenu::HandleMenuSelection(this: size, type: MENU_TRANSITION_BACK);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?Call@idSWFScriptFunction_updateScrolling@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DB6030
// RVA : 0x00DB6030
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_updateScrolling *__fastcall idMainMenu::idSWFScriptFunction_updateScrolling::Call(
        idMainMenu::idSWFScriptFunction_updateScrolling *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *mainMenu; // r3

  mainMenu = gameLocal->mainMenu;
  if ( mainMenu != nullptr )
    idMainMenu::UpdateScrolling(this: mainMenu);
  this->__vftable = (idMainMenu::idSWFScriptFunction_updateScrolling_vtbl *)4;
  return this;
}


// ========================================================================
// `idMainMenu::SetupBindings'::`8'::idSWFScriptFunction_updateMenuDisplay::Call
// EA  : 0x82DB60F0
// RVA : 0x00DB60F0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::SetupBindings_::_8_::idSWFScriptFunction_updateMenuDisplay::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms,
        idSWFScriptVar **a4)
{
  mainMenuScreens_t v6; // r3

  if ( thisObject->variables.size != 0 )
  {
    v6 = idSWFScriptVar::ToInteger(this: *a4);
    idMainMenu::UpdateMenuDisplay(this: (idMainMenu *)thisObject->variables.size, menu: v6);
  }
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ??0idMainMenu@@QAA@XZ
// EA  : 0x82DB6158
// RVA : 0x00DB6158
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idMainMenu *__fastcall idMainMenu::idMainMenu(idMainMenu *this)
{
  mainMenuTransition_t *p_menuTransition; // r11
  int i; // ctr
  char *data; // r4
  size_t v5; // r5
  char *v6; // r3
  idLobbyController *v7; // r3
  idLobbyController *v8; // r3
  idStr v10; // [sp+60h] [-870h] BYREF
  char v11; // [sp+80h] [-850h] BYREF

  idMainMenu::actionRepeater_t::actionRepeater_t(this: &this->actionRepeater);
  this->btn1Text.len = 0;
  this->btn1Text.allocedAndFlag = 20;
  this->btn1Text.data = this->btn1Text.baseBuffer;
  this->btn1Text.baseBuffer[0] = 0;
  this->btn2Text.allocedAndFlag = 20;
  this->btn2Text.len = 0;
  this->btn2Text.data = this->btn2Text.baseBuffer;
  this->btn2Text.baseBuffer[0] = 0;
  this->btn3Text.allocedAndFlag = 20;
  this->btn3Text.len = 0;
  this->btn3Text.data = this->btn3Text.baseBuffer;
  this->btn3Text.baseBuffer[0] = 0;
  this->btn4Text.allocedAndFlag = 20;
  this->btn4Text.len = 0;
  this->btn4Text.data = this->btn4Text.baseBuffer;
  this->btn4Text.baseBuffer[0] = 0;
  this->devMapListNames.list = nullptr;
  this->devMapListNames.granularity = 0;
  this->devMapListNames.memTag = 5;
  this->devMapListNames.listStatic = 0;
  this->devMapListNames.size = 0;
  this->devMapListNames.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->devMapListNames);
  this->devMapListIndexes.list = nullptr;
  this->devMapListIndexes.granularity = 0;
  this->devMapListIndexes.memTag = 5;
  this->devMapListIndexes.listStatic = 0;
  this->devMapListIndexes.size = 0;
  this->devMapListIndexes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->devMapListIndexes);
  this->optionTypes.list = nullptr;
  this->optionTypes.granularity = 0;
  this->optionTypes.memTag = 5;
  this->optionTypes.listStatic = 0;
  this->optionTypes.size = 0;
  this->optionTypes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->optionTypes);
  this->popupCallback.allocedAndFlag = 20;
  this->popupCallback.len = 0;
  this->popupCallback.data = this->popupCallback.baseBuffer;
  this->popupCallback.baseBuffer[0] = 0;
  this->bindAction.allocedAndFlag = 20;
  this->bindAction.data = this->bindAction.baseBuffer;
  this->bindAction.len = 0;
  this->bindAction.baseBuffer[0] = 0;
  Sys_SignalCreate(handle: &this->deviceRequestedSignal.handle, manualReset: false);
  this->saveAfterDeviceRequestFolder.allocedAndFlag = 20;
  this->saveAfterDeviceRequestFolder.len = 0;
  this->saveAfterDeviceRequestFolder.data = this->saveAfterDeviceRequestFolder.baseBuffer;
  this->saveAfterDeviceRequestFolder.baseBuffer[0] = 0;
  this->displayResolutions.granularity = 0;
  this->displayResolutions.memTag = 5;
  this->displayResolutions.listStatic = 0;
  this->displayResolutions.list = nullptr;
  this->displayResolutions.size = 0;
  this->displayResolutions.num = 0;
  this->chatHistory.allocedAndFlag = 20;
  this->chatHistory.baseBuffer[0] = 0;
  this->chatHistory.data = this->chatHistory.buffer;
  this->chatHistory.buffer[0] = 0;
  this->chatHistory.len = 0;
  this->chatHistory.allocedAndFlag = -2147481600;
  this->raceDescriptions.list = nullptr;
  this->raceDescriptions.granularity = 0;
  this->raceDescriptions.memTag = 5;
  this->raceDescriptions.listStatic = 0;
  this->raceDescriptions.size = 0;
  this->raceDescriptions.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->raceDescriptions);
  this->roadRageLeaderboards.size = 5;
  this->roadRageLeaderboards.num = 0;
  this->roadRageLeaderboards.granularity = 1;
  this->roadRageLeaderboards.list = this->roadRageLeaderboards.staticList;
  this->roadRageLeaderboards.memTag = 5;
  this->roadRageLeaderboards.listStatic = 1;
  this->roadRageLeaderboards.staticList[0].lb = nullptr;
  this->roadRageLeaderboards.staticList[0].name.index = -1;
  this->roadRageLeaderboards.staticList[1].lb = nullptr;
  this->roadRageLeaderboards.staticList[1].name.index = -1;
  this->roadRageLeaderboards.staticList[2].lb = nullptr;
  this->roadRageLeaderboards.staticList[2].name.index = -1;
  this->roadRageLeaderboards.staticList[3].lb = nullptr;
  this->roadRageLeaderboards.staticList[3].name.index = -1;
  this->roadRageLeaderboards.staticList[4].lb = nullptr;
  this->roadRageLeaderboards.staticList[4].name.index = -1;
  this->coopLeaderboards.list = nullptr;
  this->coopLeaderboards.granularity = 0;
  this->coopLeaderboards.memTag = 5;
  this->coopLeaderboards.listStatic = 0;
  this->coopLeaderboards.size = 0;
  this->coopLeaderboards.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->coopLeaderboards);
  this->mpMaps.granularity = 0;
  this->mpMaps.memTag = 57;
  this->mpMaps.listStatic = 0;
  this->mpMaps.list = nullptr;
  this->mpMaps.size = 0;
  this->mpMaps.num = 0;
  this->chapters.list = nullptr;
  this->chapters.granularity = 0;
  this->chapters.memTag = 5;
  this->chapters.listStatic = 0;
  this->chapters.size = 0;
  this->chapters.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->chapters);
  this->secretTypes.list = nullptr;
  this->secretTypes.granularity = 0;
  this->secretTypes.memTag = 5;
  this->secretTypes.listStatic = 0;
  this->secretTypes.size = 0;
  this->secretTypes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->secretTypes);
  this->scriptFunction_setState.pThis = nullptr;
  this->scriptFunction_setState.__vftable = (idMainMenu::idSWFScriptFunction_setState_vtbl *)&idMainMenu::idSWFScriptFunction_setState::`vftable';
  this->scriptFunction_registerUserMouse.pThis = nullptr;
  this->scriptFunction_registerUserMouse.__vftable = (idMainMenu::idSWFScriptFunction_registerUserMouse_vtbl *)&idMainMenu::idSWFScriptFunction_registerUserMouse::`vftable';
  this->scriptFunction_quitGame.pThis = nullptr;
  this->scriptFunction_quitGame.__vftable = (idMainMenu::idSWFScriptFunction_quitGame_vtbl *)&idMainMenu::idSWFScriptFunction_quitGame::`vftable';
  this->scriptFunction_waitForCredits.pThis = nullptr;
  this->scriptFunction_waitForCredits.__vftable = (idMainMenu::idSWFScriptFunction_waitForCredits_vtbl *)&idMainMenu::idSWFScriptFunction_waitForCredits::`vftable';
  this->scriptFunction_clearWaitForCredits.pThis = nullptr;
  this->scriptFunction_clearWaitForCredits.__vftable = (idMainMenu::idSWFScriptFunction_clearWaitForCredits_vtbl *)&idMainMenu::idSWFScriptFunction_clearWaitForCredits::`vftable';
  this->scriptFunction_updateScrolling.pThis = nullptr;
  this->scriptFunction_updateScrolling.__vftable = (idMainMenu::idSWFScriptFunction_updateScrolling_vtbl *)&idMainMenu::idSWFScriptFunction_updateScrolling::`vftable';
  this->scriptFunction_checkCanPlayOnline.pThis = nullptr;
  this->scriptFunction_checkCanPlayOnline.__vftable = (idMainMenu::idSWFScriptFunction_checkCanPlayOnline_vtbl *)&idMainMenu::idSWFScriptFunction_checkCanPlayOnline::`vftable';
  this->scriptFunction_isMpDisc.pThis = nullptr;
  this->scriptFunction_isMpDisc.__vftable = (idMainMenu::idSWFScriptFunction_isMpDisc_vtbl *)&idMainMenu::idSWFScriptFunction_isMpDisc::`vftable';
  this->scriptFunction_moveBetweenSPAndMP.pThis = nullptr;
  this->scriptFunction_moveBetweenSPAndMP.__vftable = (idMainMenu::idSWFScriptFunction_moveBetweenSPAndMP_vtbl *)&idMainMenu::idSWFScriptFunction_moveBetweenSPAndMP::`vftable';
  this->scriptFunction_setGameDifficulty.pThis = nullptr;
  this->scriptFunction_setGameDifficulty.__vftable = (idMainMenu::idSWFScriptFunction_setGameDifficulty_vtbl *)&idMainMenu::idSWFScriptFunction_setGameDifficulty::`vftable';
  this->scriptFunction_setNewGameDifficulty.pThis = nullptr;
  this->scriptFunction_setNewGameDifficulty.__vftable = (idMainMenu::idSWFScriptFunction_setNewGameDifficulty_vtbl *)&idMainMenu::idSWFScriptFunction_setNewGameDifficulty::`vftable';
  this->scriptFunction_getGameDifficulty.pThis = nullptr;
  this->scriptFunction_getGameDifficulty.__vftable = (idMainMenu::idSWFScriptFunction_getGameDifficulty_vtbl *)&idMainMenu::idSWFScriptFunction_getGameDifficulty::`vftable';
  this->scriptFunction_closeMenu.pThis = nullptr;
  this->scriptFunction_closeMenu.__vftable = (idMainMenu::idSWFScriptFunction_closeMenu_vtbl *)&idMainMenu::idSWFScriptFunction_closeMenu::`vftable';
  this->scriptFunction_setNewGame.pThis = nullptr;
  this->scriptFunction_setNewGame.__vftable = (idMainMenu::idSWFScriptFunction_setNewGame_vtbl *)&idMainMenu::idSWFScriptFunction_setNewGame::`vftable';
  this->scriptFunction_needsDiskSwap.pThis = nullptr;
  this->scriptFunction_needsDiskSwap.__vftable = (idMainMenu::idSWFScriptFunction_needsDiskSwap_vtbl *)&idMainMenu::idSWFScriptFunction_needsDiskSwap::`vftable';
  this->scriptFunction_isProfileScreenOpen.pThis = nullptr;
  this->scriptFunction_isProfileScreenOpen.__vftable = (idMainMenu::idSWFScriptFunction_isProfileScreenOpen_vtbl *)&idMainMenu::idSWFScriptFunction_isProfileScreenOpen::`vftable';
  this->scriptFunction_createTeamLobby.pThis = nullptr;
  this->scriptFunction_createTeamLobby.__vftable = (idMainMenu::idSWFScriptFunction_createTeamLobby_vtbl *)&idMainMenu::idSWFScriptFunction_createTeamLobby::`vftable';
  this->scriptFunction_createGameLobby.pThis = nullptr;
  this->scriptFunction_createGameLobby.__vftable = (idMainMenu::idSWFScriptFunction_createGameLobby_vtbl *)&idMainMenu::idSWFScriptFunction_createGameLobby::`vftable';
  this->scriptFunction_autoJoinGameLobby.pThis = nullptr;
  this->scriptFunction_autoJoinGameLobby.__vftable = (idMainMenu::idSWFScriptFunction_autoJoinGameLobby_vtbl *)&idMainMenu::idSWFScriptFunction_autoJoinGameLobby::`vftable';
  this->scriptFunction_isInGameLobby.pThis = nullptr;
  this->scriptFunction_isInGameLobby.__vftable = (idMainMenu::idSWFScriptFunction_isInGameLobby_vtbl *)&idMainMenu::idSWFScriptFunction_isInGameLobby::`vftable';
  this->scriptFunction_needSpDiscSwap.pThis = nullptr;
  this->scriptFunction_needSpDiscSwap.__vftable = (idMainMenu::idSWFScriptFunction_needSpDiscSwap_vtbl *)&idMainMenu::idSWFScriptFunction_needSpDiscSwap::`vftable';
  this->scriptFunction_setBindingWait.pThis = nullptr;
  this->scriptFunction_setBindingWait.__vftable = (idMainMenu::idSWFScriptFunction_setBindingWait_vtbl *)&idMainMenu::idSWFScriptFunction_setBindingWait::`vftable';
  this->scriptFunction_canScroll.pThis = nullptr;
  this->scriptFunction_canScroll.__vftable = (idMainMenu::idSWFScriptFunction_canScroll_vtbl *)&idMainMenu::idSWFScriptFunction_canScroll::`vftable';
  this->scriptFunction_setScrollSpeed.pThis = nullptr;
  this->scriptFunction_setScrollSpeed.__vftable = (idMainMenu::idSWFScriptFunction_setScrollSpeed_vtbl *)&idMainMenu::idSWFScriptFunction_setScrollSpeed::`vftable';
  this->scriptFunction_startMatch.pThis = nullptr;
  this->scriptFunction_startMatch.__vftable = (idMainMenu::idSWFScriptFunction_startMatch_vtbl *)&idMainMenu::idSWFScriptFunction_startMatch::`vftable';
  this->scriptFunction_startMatchCountdown.pThis = nullptr;
  this->scriptFunction_startMatchCountdown.__vftable = (idMainMenu::idSWFScriptFunction_startMatchCountdown_vtbl *)&idMainMenu::idSWFScriptFunction_startMatchCountdown::`vftable';
  this->scriptFunction_cancelMatch.pThis = nullptr;
  this->scriptFunction_cancelMatch.__vftable = (idMainMenu::idSWFScriptFunction_cancelMatch_vtbl *)&idMainMenu::idSWFScriptFunction_cancelMatch::`vftable';
  this->scriptFunction_cancelMatchCountdown.pThis = nullptr;
  this->scriptFunction_cancelMatchCountdown.__vftable = (idMainMenu::idSWFScriptFunction_cancelMatchCountdown_vtbl *)&idMainMenu::idSWFScriptFunction_cancelMatchCountdown::`vftable';
  this->scriptFunction_joinMatch.pThis = nullptr;
  this->scriptFunction_joinMatch.__vftable = (idMainMenu::idSWFScriptFunction_joinMatch_vtbl *)&idMainMenu::idSWFScriptFunction_joinMatch::`vftable';
  this->scriptFunction_showServerGamerCardUI.pThis = nullptr;
  this->scriptFunction_showServerGamerCardUI.__vftable = (idMainMenu::idSWFScriptFunction_showServerGamerCardUI_vtbl *)&idMainMenu::idSWFScriptFunction_showServerGamerCardUI::`vftable';
  this->scriptFunction_inviteFriends.pThis = nullptr;
  this->scriptFunction_inviteFriends.__vftable = (idMainMenu::idSWFScriptFunction_inviteFriends_vtbl *)&idMainMenu::idSWFScriptFunction_inviteFriends::`vftable';
  this->scriptFunction_showPartySessions.pThis = nullptr;
  this->scriptFunction_showPartySessions.__vftable = (idMainMenu::idSWFScriptFunction_showPartySessions_vtbl *)&idMainMenu::idSWFScriptFunction_showPartySessions::`vftable';
  this->scriptFunction_getMatchType.pThis = nullptr;
  this->scriptFunction_getMatchType.__vftable = (idMainMenu::idSWFScriptFunction_getMatchType_vtbl *)&idMainMenu::idSWFScriptFunction_getMatchType::`vftable';
  this->scriptFunction_setMatchType.pThis = nullptr;
  this->scriptFunction_setMatchType.__vftable = (idMainMenu::idSWFScriptFunction_setMatchType_vtbl *)&idMainMenu::idSWFScriptFunction_setMatchType::`vftable';
  this->scriptFunction_isPeer.pThis = nullptr;
  this->scriptFunction_isPeer.__vftable = (idMainMenu::idSWFScriptFunction_isPeer_vtbl *)&idMainMenu::idSWFScriptFunction_isPeer::`vftable';
  this->scriptFunction_isPartyPeer.pThis = nullptr;
  this->scriptFunction_isPartyPeer.__vftable = (idMainMenu::idSWFScriptFunction_isPartyPeer_vtbl *)&idMainMenu::idSWFScriptFunction_isPartyPeer::`vftable';
  this->scriptFunction_updateLanServerList.pThis = nullptr;
  this->scriptFunction_updateLanServerList.__vftable = (idMainMenu::idSWFScriptFunction_updateLanServerList_vtbl *)&idMainMenu::idSWFScriptFunction_updateLanServerList::`vftable';
  this->scriptFunction_isLobbyFull.pThis = nullptr;
  this->scriptFunction_isLobbyFull.__vftable = (idMainMenu::idSWFScriptFunction_isLobbyFull_vtbl *)&idMainMenu::idSWFScriptFunction_isLobbyFull::`vftable';
  this->scriptFunction_getChapterList.pThis = nullptr;
  this->scriptFunction_getChapterList.__vftable = (idMainMenu::idSWFScriptFunction_getChapterList_vtbl *)&idMainMenu::idSWFScriptFunction_getChapterList::`vftable';
  this->scriptFunction_showVoteResults.pThis = nullptr;
  this->scriptFunction_showVoteResults.__vftable = (idMainMenu::idSWFScriptFunction_showVoteResults_vtbl *)&idMainMenu::idSWFScriptFunction_showVoteResults::`vftable';
  this->scriptFunction_voteToSkipMap.pThis = nullptr;
  this->scriptFunction_voteToSkipMap.__vftable = (idMainMenu::idSWFScriptFunction_voteToSkipMap_vtbl *)&idMainMenu::idSWFScriptFunction_voteToSkipMap::`vftable';
  this->scriptFunction_getMapList.pThis = nullptr;
  this->scriptFunction_getMapList.__vftable = (idMainMenu::idSWFScriptFunction_getMapList_vtbl *)&idMainMenu::idSWFScriptFunction_getMapList::`vftable';
  this->scriptFunction_getGameMapAvailable.pThis = nullptr;
  this->scriptFunction_getGameMapAvailable.__vftable = (idMainMenu::idSWFScriptFunction_getGameMapAvailable_vtbl *)&idMainMenu::idSWFScriptFunction_getGameMapAvailable::`vftable';
  this->scriptFunction_getMatchMap.pThis = nullptr;
  this->scriptFunction_getMatchMap.__vftable = (idMainMenu::idSWFScriptFunction_getMatchMap_vtbl *)&idMainMenu::idSWFScriptFunction_getMatchMap::`vftable';
  this->scriptFunction_setMatchMap.pThis = nullptr;
  this->scriptFunction_setMatchMap.__vftable = (idMainMenu::idSWFScriptFunction_setMatchMap_vtbl *)&idMainMenu::idSWFScriptFunction_setMatchMap::`vftable';
  this->scriptFunction_updateMapSelection.pThis = nullptr;
  this->scriptFunction_updateMapSelection.__vftable = (idMainMenu::idSWFScriptFunction_updateMapSelection_vtbl *)&idMainMenu::idSWFScriptFunction_updateMapSelection::`vftable';
  this->scriptFunction_getModeList.pThis = nullptr;
  this->scriptFunction_getModeList.__vftable = (idMainMenu::idSWFScriptFunction_getModeList_vtbl *)&idMainMenu::idSWFScriptFunction_getModeList::`vftable';
  this->scriptFunction_getGameModeAvailable.pThis = nullptr;
  this->scriptFunction_getGameModeAvailable.__vftable = (idMainMenu::idSWFScriptFunction_getGameModeAvailable_vtbl *)&idMainMenu::idSWFScriptFunction_getGameModeAvailable::`vftable';
  this->scriptFunction_getMatchMode.pThis = nullptr;
  this->scriptFunction_getMatchMode.__vftable = (idMainMenu::idSWFScriptFunction_getMatchMode_vtbl *)&idMainMenu::idSWFScriptFunction_getMatchMode::`vftable';
  this->scriptFunction_setMatchMode.pThis = nullptr;
  this->scriptFunction_setMatchMode.__vftable = (idMainMenu::idSWFScriptFunction_setMatchMode_vtbl *)&idMainMenu::idSWFScriptFunction_setMatchMode::`vftable';
  this->scriptFunction_joinQuickMatch.pThis = nullptr;
  this->scriptFunction_joinQuickMatch.__vftable = (idMainMenu::idSWFScriptFunction_joinQuickMatch_vtbl *)&idMainMenu::idSWFScriptFunction_joinQuickMatch::`vftable';
  this->scriptFunction_setPrivateMatch.pThis = nullptr;
  this->scriptFunction_setPrivateMatch.__vftable = (idMainMenu::idSWFScriptFunction_setPrivateMatch_vtbl *)&idMainMenu::idSWFScriptFunction_setPrivateMatch::`vftable';
  this->scriptFunction_isPrivateMatch.pThis = nullptr;
  this->scriptFunction_isPrivateMatch.__vftable = (idMainMenu::idSWFScriptFunction_isPrivateMatch_vtbl *)&idMainMenu::idSWFScriptFunction_isPrivateMatch::`vftable';
  this->scriptFunction_setLocalMatch.pThis = nullptr;
  this->scriptFunction_setLocalMatch.__vftable = (idMainMenu::idSWFScriptFunction_setLocalMatch_vtbl *)&idMainMenu::idSWFScriptFunction_setLocalMatch::`vftable';
  this->scriptFunction_isLocalMatch.pThis = nullptr;
  this->scriptFunction_isLocalMatch.__vftable = (idMainMenu::idSWFScriptFunction_isLocalMatch_vtbl *)&idMainMenu::idSWFScriptFunction_isLocalMatch::`vftable';
  this->scriptFunction_sendChatText.pThis = nullptr;
  this->scriptFunction_sendChatText.__vftable = (idMainMenu::idSWFScriptFunction_sendChatText_vtbl *)&idMainMenu::idSWFScriptFunction_sendChatText::`vftable';
  this->scriptFunction_togglePlayerMute.pThis = nullptr;
  this->scriptFunction_togglePlayerMute.__vftable = (idMainMenu::idSWFScriptFunction_togglePlayerMute_vtbl *)&idMainMenu::idSWFScriptFunction_togglePlayerMute::`vftable';
  this->scriptFunction_showGamerCardUI.pThis = nullptr;
  this->scriptFunction_showGamerCardUI.__vftable = (idMainMenu::idSWFScriptFunction_showGamerCardUI_vtbl *)&idMainMenu::idSWFScriptFunction_showGamerCardUI::`vftable';
  this->scriptFunction_kickPlayer.pThis = nullptr;
  this->scriptFunction_kickPlayer.__vftable = (idMainMenu::idSWFScriptFunction_kickPlayer_vtbl *)&idMainMenu::idSWFScriptFunction_kickPlayer::`vftable';
  this->scriptFunction_isInPlatformParty.pThis = nullptr;
  this->scriptFunction_isInPlatformParty.__vftable = (idMainMenu::idSWFScriptFunction_isInPlatformParty_vtbl *)&idMainMenu::idSWFScriptFunction_isInPlatformParty::`vftable';
  this->scriptFunction_invitePlatformParty.pThis = nullptr;
  this->scriptFunction_invitePlatformParty.__vftable = (idMainMenu::idSWFScriptFunction_invitePlatformParty_vtbl *)&idMainMenu::idSWFScriptFunction_invitePlatformParty::`vftable';
  this->scriptFunction_loadProfileData.pThis = nullptr;
  this->scriptFunction_loadProfileData.__vftable = (idMainMenu::idSWFScriptFunction_loadProfileData_vtbl *)&idMainMenu::idSWFScriptFunction_loadProfileData::`vftable';
  this->scriptFunction_setMenuArea.pThis = nullptr;
  this->scriptFunction_setMenuArea.__vftable = (idMainMenu::idSWFScriptFunction_setMenuArea_vtbl *)&idMainMenu::idSWFScriptFunction_setMenuArea::`vftable';
  this->scriptFunction_forceMenuArea.pThis = nullptr;
  this->scriptFunction_forceMenuArea.__vftable = (idMainMenu::idSWFScriptFunction_forceMenuArea_vtbl *)&idMainMenu::idSWFScriptFunction_forceMenuArea::`vftable';
  this->scriptFunction_getPostGameResults.pThis = nullptr;
  this->scriptFunction_getPostGameResults.__vftable = (idMainMenu::idSWFScriptFunction_getPostGameResults_vtbl *)&idMainMenu::idSWFScriptFunction_getPostGameResults::`vftable';
  this->scriptFunction_updateModeSelection.pThis = nullptr;
  this->scriptFunction_updateModeSelection.__vftable = (idMainMenu::idSWFScriptFunction_updateModeSelection_vtbl *)&idMainMenu::idSWFScriptFunction_updateModeSelection::`vftable';
  this->scriptFunction_changeTeam.pThis = nullptr;
  this->scriptFunction_changeTeam.__vftable = (idMainMenu::idSWFScriptFunction_changeTeam_vtbl *)&idMainMenu::idSWFScriptFunction_changeTeam::`vftable';
  this->scriptFunction_isGameModeTeam.pThis = nullptr;
  this->scriptFunction_isGameModeTeam.__vftable = (idMainMenu::idSWFScriptFunction_isGameModeTeam_vtbl *)&idMainMenu::idSWFScriptFunction_isGameModeTeam::`vftable';
  this->scriptFunction_showMatchResultsPopup.pThis = nullptr;
  this->scriptFunction_showMatchResultsPopup.__vftable = (idMainMenu::idSWFScriptFunction_showMatchResultsPopup_vtbl *)&idMainMenu::idSWFScriptFunction_showMatchResultsPopup::`vftable';
  this->scriptFunction_showNextUnlockPopup.pThis = nullptr;
  this->scriptFunction_showNextUnlockPopup.__vftable = (idMainMenu::idSWFScriptFunction_showNextUnlockPopup_vtbl *)&idMainMenu::idSWFScriptFunction_showNextUnlockPopup::`vftable';
  this->scriptFunction_showPopupDialog.pThis = nullptr;
  this->scriptFunction_showPopupDialog.__vftable = (idMainMenu::idSWFScriptFunction_showPopupDialog_vtbl *)&idMainMenu::idSWFScriptFunction_showPopupDialog::`vftable';
  this->scriptFunction_closePopup.pThis = nullptr;
  this->scriptFunction_closePopup.__vftable = (idMainMenu::idSWFScriptFunction_closePopup_vtbl *)&idMainMenu::idSWFScriptFunction_closePopup::`vftable';
  this->scriptFunction_loadMap.pThis = nullptr;
  this->scriptFunction_loadMap.__vftable = (idMainMenu::idSWFScriptFunction_loadMap_vtbl *)&idMainMenu::idSWFScriptFunction_loadMap::`vftable';
  this->scriptFunction_getDefaultDevMenuOption.pThis = nullptr;
  this->scriptFunction_getDefaultDevMenuOption.__vftable = (idMainMenu::idSWFScriptFunction_getDefaultDevMenuOption_vtbl *)&idMainMenu::idSWFScriptFunction_getDefaultDevMenuOption::`vftable';
  this->scriptFunction_restartMap.pThis = nullptr;
  this->scriptFunction_restartMap.__vftable = (idMainMenu::idSWFScriptFunction_restartMap_vtbl *)&idMainMenu::idSWFScriptFunction_restartMap::`vftable';
  this->scriptFunction_returnToMainMenu.pThis = nullptr;
  this->scriptFunction_returnToMainMenu.__vftable = (idMainMenu::idSWFScriptFunction_returnToMainMenu_vtbl *)&idMainMenu::idSWFScriptFunction_returnToMainMenu::`vftable';
  this->scriptFunction_confirmExitGame.pThis = nullptr;
  this->scriptFunction_confirmExitGame.__vftable = (idMainMenu::idSWFScriptFunction_confirmExitGame_vtbl *)&idMainMenu::idSWFScriptFunction_confirmExitGame::`vftable';
  this->scriptFunction_restartFromPause.pThis = nullptr;
  this->scriptFunction_restartFromPause.__vftable = (idMainMenu::idSWFScriptFunction_restartFromPause_vtbl *)&idMainMenu::idSWFScriptFunction_restartFromPause::`vftable';
  this->scriptFunction_cancelSaveEnumeration.pThis = nullptr;
  this->scriptFunction_cancelSaveEnumeration.__vftable = (idMainMenu::idSWFScriptFunction_cancelSaveEnumeration_vtbl *)&idMainMenu::idSWFScriptFunction_cancelSaveEnumeration::`vftable';
  this->scriptFunction_GetSaveGame.pThis = nullptr;
  this->scriptFunction_GetSaveGame.__vftable = (idMainMenu::idSWFScriptFunction_GetSaveGame_vtbl *)&idMainMenu::idSWFScriptFunction_GetSaveGame::`vftable';
  this->scriptFunction_CanSaveGame.pThis = nullptr;
  this->scriptFunction_CanSaveGame.__vftable = (idMainMenu::idSWFScriptFunction_CanSaveGame_vtbl *)&idMainMenu::idSWFScriptFunction_CanSaveGame::`vftable';
  this->scriptFunction_SaveGame.pThis = nullptr;
  this->scriptFunction_SaveGame.__vftable = (idMainMenu::idSWFScriptFunction_SaveGame_vtbl *)&idMainMenu::idSWFScriptFunction_SaveGame::`vftable';
  this->scriptFunction_LoadGame.pThis = nullptr;
  this->scriptFunction_LoadGame.__vftable = (idMainMenu::idSWFScriptFunction_LoadGame_vtbl *)&idMainMenu::idSWFScriptFunction_LoadGame::`vftable';
  this->scriptFunction_deleteGame.pThis = nullptr;
  this->scriptFunction_deleteGame.__vftable = (idMainMenu::idSWFScriptFunction_deleteGame_vtbl *)&idMainMenu::idSWFScriptFunction_deleteGame::`vftable';
  this->scriptFunction_select360Storage.pThis = nullptr;
  this->scriptFunction_select360Storage.__vftable = (idMainMenu::idSWFScriptFunction_select360Storage_vtbl *)&idMainMenu::idSWFScriptFunction_select360Storage::`vftable';
  this->scriptFunction_canContinueGame.pThis = nullptr;
  this->scriptFunction_canContinueGame.__vftable = (idMainMenu::idSWFScriptFunction_canContinueGame_vtbl *)&idMainMenu::idSWFScriptFunction_canContinueGame::`vftable';
  this->scriptFunction_canLoadGame.pThis = nullptr;
  this->scriptFunction_canLoadGame.__vftable = (idMainMenu::idSWFScriptFunction_canLoadGame_vtbl *)&idMainMenu::idSWFScriptFunction_canLoadGame::`vftable';
  this->scriptFunction_canStartNewGame.pThis = nullptr;
  this->scriptFunction_canStartNewGame.__vftable = (idMainMenu::idSWFScriptFunction_canStartNewGame_vtbl *)&idMainMenu::idSWFScriptFunction_canStartNewGame::`vftable';
  this->scriptFunction_startDeviceSignal.pThis = nullptr;
  this->scriptFunction_startDeviceSignal.__vftable = (idMainMenu::idSWFScriptFunction_startDeviceSignal_vtbl *)&idMainMenu::idSWFScriptFunction_startDeviceSignal::`vftable';
  this->scriptFunction_endDeviceSignal.pThis = nullptr;
  this->scriptFunction_endDeviceSignal.__vftable = (idMainMenu::idSWFScriptFunction_endDeviceSignal_vtbl *)&idMainMenu::idSWFScriptFunction_endDeviceSignal::`vftable';
  this->scriptFunction_setSaveLoadUpdate.pThis = nullptr;
  this->scriptFunction_setSaveLoadUpdate.__vftable = (idMainMenu::idSWFScriptFunction_setSaveLoadUpdate_vtbl *)&idMainMenu::idSWFScriptFunction_setSaveLoadUpdate::`vftable';
  this->scriptFunction_isEnumerating.pThis = nullptr;
  this->scriptFunction_isEnumerating.__vftable = (idMainMenu::idSWFScriptFunction_isEnumerating_vtbl *)&idMainMenu::idSWFScriptFunction_isEnumerating::`vftable';
  this->scriptFunction_continueGame.pThis = nullptr;
  this->scriptFunction_continueGame.__vftable = (idMainMenu::idSWFScriptFunction_continueGame_vtbl *)&idMainMenu::idSWFScriptFunction_continueGame::`vftable';
  this->scriptFunction_continueFromMostRecentSave.pThis = nullptr;
  this->scriptFunction_continueFromMostRecentSave.__vftable = (idMainMenu::idSWFScriptFunction_continueFromMostRecentSave_vtbl *)&idMainMenu::idSWFScriptFunction_continueFromMostRecentSave::`vftable';
  this->scriptFunction_loadDamagedFile.pThis = nullptr;
  this->scriptFunction_loadDamagedFile.__vftable = (idMainMenu::idSWFScriptFunction_loadDamagedFile_vtbl *)&idMainMenu::idSWFScriptFunction_loadDamagedFile::`vftable';
  this->scriptFunction_isLookInverted.pThis = nullptr;
  this->scriptFunction_isLookInverted.__vftable = (idMainMenu::idSWFScriptFunction_isLookInverted_vtbl *)&idMainMenu::idSWFScriptFunction_isLookInverted::`vftable';
  this->scriptFunction_invertLook.pThis = nullptr;
  this->scriptFunction_invertLook.__vftable = (idMainMenu::idSWFScriptFunction_invertLook_vtbl *)&idMainMenu::idSWFScriptFunction_invertLook::`vftable';
  this->scriptFunction_updateSafeFrameScale.pThis = nullptr;
  this->scriptFunction_updateSafeFrameScale.__vftable = (idMainMenu::idSWFScriptFunction_updateSafeFrameScale_vtbl *)&idMainMenu::idSWFScriptFunction_updateSafeFrameScale::`vftable';
  this->scriptFunction_GetSafeFrameScale.pThis = nullptr;
  this->scriptFunction_GetSafeFrameScale.__vftable = (idMainMenu::idSWFScriptFunction_GetSafeFrameScale_vtbl *)&idMainMenu::idSWFScriptFunction_GetSafeFrameScale::`vftable';
  this->scriptFunction_updateGammaValue.pThis = nullptr;
  this->scriptFunction_updateGammaValue.__vftable = (idMainMenu::idSWFScriptFunction_updateGammaValue_vtbl *)&idMainMenu::idSWFScriptFunction_updateGammaValue::`vftable';
  this->scriptFunction_getGammaValue.pThis = nullptr;
  this->scriptFunction_getGammaValue.__vftable = (idMainMenu::idSWFScriptFunction_getGammaValue_vtbl *)&idMainMenu::idSWFScriptFunction_getGammaValue::`vftable';
  this->scriptFunction_setInvertLook.pThis = nullptr;
  this->scriptFunction_setInvertLook.__vftable = (idMainMenu::idSWFScriptFunction_setInvertLook_vtbl *)&idMainMenu::idSWFScriptFunction_setInvertLook::`vftable';
  this->scriptFunction_subtitlesEnabled.pThis = nullptr;
  this->scriptFunction_subtitlesEnabled.__vftable = (idMainMenu::idSWFScriptFunction_subtitlesEnabled_vtbl *)&idMainMenu::idSWFScriptFunction_subtitlesEnabled::`vftable';
  this->scriptFunction_setSubtitlesEnabled.pThis = nullptr;
  this->scriptFunction_setSubtitlesEnabled.__vftable = (idMainMenu::idSWFScriptFunction_setSubtitlesEnabled_vtbl *)&idMainMenu::idSWFScriptFunction_setSubtitlesEnabled::`vftable';
  this->scriptFunction_calculateBenchmark.pThis = nullptr;
  this->scriptFunction_calculateBenchmark.__vftable = (idMainMenu::idSWFScriptFunction_calculateBenchmark_vtbl *)&idMainMenu::idSWFScriptFunction_calculateBenchmark::`vftable';
  this->scriptFunction_getBenchmarkValue.pThis = nullptr;
  this->scriptFunction_getBenchmarkValue.__vftable = (idMainMenu::idSWFScriptFunction_getBenchmarkValue_vtbl *)&idMainMenu::idSWFScriptFunction_getBenchmarkValue::`vftable';
  this->scriptFunction_getAudioVolume.pThis = nullptr;
  this->scriptFunction_getAudioVolume.__vftable = (idMainMenu::idSWFScriptFunction_getAudioVolume_vtbl *)&idMainMenu::idSWFScriptFunction_getAudioVolume::`vftable';
  this->scriptFunction_setAudioVolume.pThis = nullptr;
  this->scriptFunction_setAudioVolume.__vftable = (idMainMenu::idSWFScriptFunction_setAudioVolume_vtbl *)&idMainMenu::idSWFScriptFunction_setAudioVolume::`vftable';
  this->scriptFunction_updateJoyYawSpeed.pThis = nullptr;
  this->scriptFunction_updateJoyYawSpeed.__vftable = (idMainMenu::idSWFScriptFunction_updateJoyYawSpeed_vtbl *)&idMainMenu::idSWFScriptFunction_updateJoyYawSpeed::`vftable';
  this->scriptFunction_GetJoyYawSpeed.pThis = nullptr;
  this->scriptFunction_GetJoyYawSpeed.__vftable = (idMainMenu::idSWFScriptFunction_GetJoyYawSpeed_vtbl *)&idMainMenu::idSWFScriptFunction_GetJoyYawSpeed::`vftable';
  this->scriptFunction_updateJoyPitchSpeed.pThis = nullptr;
  this->scriptFunction_updateJoyPitchSpeed.__vftable = (idMainMenu::idSWFScriptFunction_updateJoyPitchSpeed_vtbl *)&idMainMenu::idSWFScriptFunction_updateJoyPitchSpeed::`vftable';
  this->scriptFunction_GetJoyPitchSpeed.pThis = nullptr;
  this->scriptFunction_GetJoyPitchSpeed.__vftable = (idMainMenu::idSWFScriptFunction_GetJoyPitchSpeed_vtbl *)&idMainMenu::idSWFScriptFunction_GetJoyPitchSpeed::`vftable';
  this->scriptFunction_getBinding.pThis = nullptr;
  this->scriptFunction_getBinding.__vftable = (idMainMenu::idSWFScriptFunction_getBinding_vtbl *)&idMainMenu::idSWFScriptFunction_getBinding::`vftable';
  this->scriptFunction_confirmRestoreBindings.pThis = nullptr;
  this->scriptFunction_confirmRestoreBindings.__vftable = (idMainMenu::idSWFScriptFunction_confirmRestoreBindings_vtbl *)&idMainMenu::idSWFScriptFunction_confirmRestoreBindings::`vftable';
  this->scriptFunction_getGamepadEnabled.pThis = nullptr;
  this->scriptFunction_getGamepadEnabled.__vftable = (idMainMenu::idSWFScriptFunction_getGamepadEnabled_vtbl *)&idMainMenu::idSWFScriptFunction_getGamepadEnabled::`vftable';
  this->scriptFunction_setGamepadEnabled.pThis = nullptr;
  this->scriptFunction_setGamepadEnabled.__vftable = (idMainMenu::idSWFScriptFunction_setGamepadEnabled_vtbl *)&idMainMenu::idSWFScriptFunction_setGamepadEnabled::`vftable';
  this->scriptFunction_getUseAimAssist.pThis = nullptr;
  this->scriptFunction_getUseAimAssist.__vftable = (idMainMenu::idSWFScriptFunction_getUseAimAssist_vtbl *)&idMainMenu::idSWFScriptFunction_getUseAimAssist::`vftable';
  this->scriptFunction_setUseAimAssist.pThis = nullptr;
  this->scriptFunction_setUseAimAssist.__vftable = (idMainMenu::idSWFScriptFunction_setUseAimAssist_vtbl *)&idMainMenu::idSWFScriptFunction_setUseAimAssist::`vftable';
  this->scriptFunction_setUseVibrate.pThis = nullptr;
  this->scriptFunction_setUseVibrate.__vftable = (idMainMenu::idSWFScriptFunction_setUseVibrate_vtbl *)&idMainMenu::idSWFScriptFunction_setUseVibrate::`vftable';
  this->scriptFunction_getUseVibrate.pThis = nullptr;
  this->scriptFunction_getUseVibrate.__vftable = (idMainMenu::idSWFScriptFunction_getUseVibrate_vtbl *)&idMainMenu::idSWFScriptFunction_getUseVibrate::`vftable';
  this->scriptFunction_setMouseSensitivity.pThis = nullptr;
  this->scriptFunction_setMouseSensitivity.__vftable = (idMainMenu::idSWFScriptFunction_setMouseSensitivity_vtbl *)&idMainMenu::idSWFScriptFunction_setMouseSensitivity::`vftable';
  this->scriptFunction_getMouseSensitivity.pThis = nullptr;
  this->scriptFunction_getMouseSensitivity.__vftable = (idMainMenu::idSWFScriptFunction_getMouseSensitivity_vtbl *)&idMainMenu::idSWFScriptFunction_getMouseSensitivity::`vftable';
  this->scriptFunction_getConfig.pThis = nullptr;
  this->scriptFunction_getConfig.__vftable = (idMainMenu::idSWFScriptFunction_getConfig_vtbl *)&idMainMenu::idSWFScriptFunction_getConfig::`vftable';
  this->scriptFunction_setConfig.pThis = nullptr;
  this->scriptFunction_setConfig.__vftable = (idMainMenu::idSWFScriptFunction_setConfig_vtbl *)&idMainMenu::idSWFScriptFunction_setConfig::`vftable';
  this->scriptFunction_changeConfig.pThis = nullptr;
  this->scriptFunction_changeConfig.__vftable = (idMainMenu::idSWFScriptFunction_changeConfig_vtbl *)&idMainMenu::idSWFScriptFunction_changeConfig::`vftable';
  this->scriptFunction_getConfigText.pThis = nullptr;
  this->scriptFunction_getConfigText.__vftable = (idMainMenu::idSWFScriptFunction_getConfigText_vtbl *)&idMainMenu::idSWFScriptFunction_getConfigText::`vftable';
  this->scriptFunction_hidePauseMenu.pThis = nullptr;
  this->scriptFunction_hidePauseMenu.__vftable = (idMainMenu::idSWFScriptFunction_hidePauseMenu_vtbl *)&idMainMenu::idSWFScriptFunction_hidePauseMenu::`vftable';
  this->scriptFunction_getCoopDifficulty.pThis = nullptr;
  this->scriptFunction_getCoopDifficulty.__vftable = (idMainMenu::idSWFScriptFunction_getCoopDifficulty_vtbl *)&idMainMenu::idSWFScriptFunction_getCoopDifficulty::`vftable';
  this->scriptFunction_setCoopDifficulty.pThis = nullptr;
  this->scriptFunction_setCoopDifficulty.__vftable = (idMainMenu::idSWFScriptFunction_setCoopDifficulty_vtbl *)&idMainMenu::idSWFScriptFunction_setCoopDifficulty::`vftable';
  this->scriptFunction_getSessionCoopDifficulty.pThis = nullptr;
  this->scriptFunction_getSessionCoopDifficulty.__vftable = (idMainMenu::idSWFScriptFunction_getSessionCoopDifficulty_vtbl *)&idMainMenu::idSWFScriptFunction_getSessionCoopDifficulty::`vftable';
  this->scriptFunction_loadScrollingControlValues.pThis = nullptr;
  this->scriptFunction_loadScrollingControlValues.__vftable = (idMainMenu::idSWFScriptFunction_loadScrollingControlValues_vtbl *)&idMainMenu::idSWFScriptFunction_loadScrollingControlValues::`vftable';
  this->scriptFunction_getTimeLimit.pThis = nullptr;
  this->scriptFunction_getTimeLimit.__vftable = (idMainMenu::idSWFScriptFunction_getTimeLimit_vtbl *)&idMainMenu::idSWFScriptFunction_getTimeLimit::`vftable';
  this->scriptFunction_setTimeLimit.pThis = nullptr;
  this->scriptFunction_setTimeLimit.__vftable = (idMainMenu::idSWFScriptFunction_setTimeLimit_vtbl *)&idMainMenu::idSWFScriptFunction_setTimeLimit::`vftable';
  this->scriptFunction_getScoreLimit.pThis = nullptr;
  this->scriptFunction_getScoreLimit.__vftable = (idMainMenu::idSWFScriptFunction_getScoreLimit_vtbl *)&idMainMenu::idSWFScriptFunction_getScoreLimit::`vftable';
  this->scriptFunction_setScoreLimit.pThis = nullptr;
  this->scriptFunction_setScoreLimit.__vftable = (idMainMenu::idSWFScriptFunction_setScoreLimit_vtbl *)&idMainMenu::idSWFScriptFunction_setScoreLimit::`vftable';
  this->scriptFunction_getCOOPPrivacy.pThis = nullptr;
  this->scriptFunction_getCOOPPrivacy.__vftable = (idMainMenu::idSWFScriptFunction_getCOOPPrivacy_vtbl *)&idMainMenu::idSWFScriptFunction_getCOOPPrivacy::`vftable';
  this->scriptFunction_setCOOPPrivacy.pThis = nullptr;
  this->scriptFunction_setCOOPPrivacy.__vftable = (idMainMenu::idSWFScriptFunction_setCOOPPrivacy_vtbl *)&idMainMenu::idSWFScriptFunction_setCOOPPrivacy::`vftable';
  this->scriptFunction_shouldPrivacyBeVisible.pThis = nullptr;
  this->scriptFunction_shouldPrivacyBeVisible.__vftable = (idMainMenu::idSWFScriptFunction_shouldPrivacyBeVisible_vtbl *)&idMainMenu::idSWFScriptFunction_shouldPrivacyBeVisible::`vftable';
  this->scriptFunction_getAllowFriendlyFire.pThis = nullptr;
  this->scriptFunction_getAllowFriendlyFire.__vftable = (idMainMenu::idSWFScriptFunction_getAllowFriendlyFire_vtbl *)&idMainMenu::idSWFScriptFunction_getAllowFriendlyFire::`vftable';
  this->scriptFunction_setAllowFriendlyFire.pThis = nullptr;
  this->scriptFunction_setAllowFriendlyFire.__vftable = (idMainMenu::idSWFScriptFunction_setAllowFriendlyFire_vtbl *)&idMainMenu::idSWFScriptFunction_setAllowFriendlyFire::`vftable';
  this->scriptFunction_getAllowSpectators.pThis = nullptr;
  this->scriptFunction_getAllowSpectators.__vftable = (idMainMenu::idSWFScriptFunction_getAllowSpectators_vtbl *)&idMainMenu::idSWFScriptFunction_getAllowSpectators::`vftable';
  this->scriptFunction_setAllowSpectators.pThis = nullptr;
  this->scriptFunction_setAllowSpectators.__vftable = (idMainMenu::idSWFScriptFunction_setAllowSpectators_vtbl *)&idMainMenu::idSWFScriptFunction_setAllowSpectators::`vftable';
  this->scriptFunction_getAllowPowerups.pThis = nullptr;
  this->scriptFunction_getAllowPowerups.__vftable = (idMainMenu::idSWFScriptFunction_getAllowPowerups_vtbl *)&idMainMenu::idSWFScriptFunction_getAllowPowerups::`vftable';
  this->scriptFunction_setAllowPowerups.pThis = nullptr;
  this->scriptFunction_setAllowPowerups.__vftable = (idMainMenu::idSWFScriptFunction_setAllowPowerups_vtbl *)&idMainMenu::idSWFScriptFunction_setAllowPowerups::`vftable';
  this->scriptFunction_getAllowQuickUse.pThis = nullptr;
  this->scriptFunction_getAllowQuickUse.__vftable = (idMainMenu::idSWFScriptFunction_getAllowQuickUse_vtbl *)&idMainMenu::idSWFScriptFunction_getAllowQuickUse::`vftable';
  this->scriptFunction_setAllowQuickUse.pThis = nullptr;
  this->scriptFunction_setAllowQuickUse.__vftable = (idMainMenu::idSWFScriptFunction_setAllowQuickUse_vtbl *)&idMainMenu::idSWFScriptFunction_setAllowQuickUse::`vftable';
  this->scriptFunction_getAllowSponsors.pThis = nullptr;
  this->scriptFunction_getAllowSponsors.__vftable = (idMainMenu::idSWFScriptFunction_getAllowSponsors_vtbl *)&idMainMenu::idSWFScriptFunction_getAllowSponsors::`vftable';
  this->scriptFunction_setAllowSponsors.pThis = nullptr;
  this->scriptFunction_setAllowSponsors.__vftable = (idMainMenu::idSWFScriptFunction_setAllowSponsors_vtbl *)&idMainMenu::idSWFScriptFunction_setAllowSponsors::`vftable';
  this->scriptFunction_getAllowBoost.pThis = nullptr;
  this->scriptFunction_getAllowBoost.__vftable = (idMainMenu::idSWFScriptFunction_getAllowBoost_vtbl *)&idMainMenu::idSWFScriptFunction_getAllowBoost::`vftable';
  this->scriptFunction_setAllowBoost.pThis = nullptr;
  this->scriptFunction_setAllowBoost.__vftable = (idMainMenu::idSWFScriptFunction_setAllowBoost_vtbl *)&idMainMenu::idSWFScriptFunction_setAllowBoost::`vftable';
  this->scriptFunction_suicide.pThis = nullptr;
  this->scriptFunction_suicide.__vftable = (idMainMenu::idSWFScriptFunction_suicide_vtbl *)&idMainMenu::idSWFScriptFunction_suicide::`vftable';
  this->scriptFunction_getPlayerLevelTitle.pThis = nullptr;
  this->scriptFunction_getPlayerLevelTitle.__vftable = (idMainMenu::idSWFScriptFunction_getPlayerLevelTitle_vtbl *)&idMainMenu::idSWFScriptFunction_getPlayerLevelTitle::`vftable';
  this->scriptFunction_getAccoladeInfo.pThis = nullptr;
  this->scriptFunction_getAccoladeInfo.__vftable = (idMainMenu::idSWFScriptFunction_getAccoladeInfo_vtbl *)&idMainMenu::idSWFScriptFunction_getAccoladeInfo::`vftable';
  this->scriptFunction_getAccoladeCount.pThis = nullptr;
  this->scriptFunction_getAccoladeCount.__vftable = (idMainMenu::idSWFScriptFunction_getAccoladeCount_vtbl *)&idMainMenu::idSWFScriptFunction_getAccoladeCount::`vftable';
  this->scriptFunction_selectAccolade.pThis = nullptr;
  this->scriptFunction_selectAccolade.__vftable = (idMainMenu::idSWFScriptFunction_selectAccolade_vtbl *)&idMainMenu::idSWFScriptFunction_selectAccolade::`vftable';
  this->scriptFunction_drawPlayerInfo.pThis = nullptr;
  this->scriptFunction_drawPlayerInfo.__vftable = (idMainMenu::idSWFScriptFunction_drawPlayerInfo_vtbl *)&idMainMenu::idSWFScriptFunction_drawPlayerInfo::`vftable';
  this->scriptFunction_getMissionMapList.pThis = nullptr;
  this->scriptFunction_getMissionMapList.__vftable = (idMainMenu::idSWFScriptFunction_getMissionMapList_vtbl *)&idMainMenu::idSWFScriptFunction_getMissionMapList::`vftable';
  this->scriptFunction_hasNewAccolade.pThis = nullptr;
  this->scriptFunction_hasNewAccolade.__vftable = (idMainMenu::idSWFScriptFunction_hasNewAccolade_vtbl *)&idMainMenu::idSWFScriptFunction_hasNewAccolade::`vftable';
  this->scriptFunction_loadMenuItems.pThis = nullptr;
  this->scriptFunction_loadMenuItems.__vftable = (idMainMenu::idSWFScriptFunction_loadMenuItems_vtbl *)&idMainMenu::idSWFScriptFunction_loadMenuItems::`vftable';
  this->scriptFunction_saveSettings.pThis = nullptr;
  this->scriptFunction_saveSettings.__vftable = (idMainMenu::idSWFScriptFunction_saveSettings_vtbl *)&idMainMenu::idSWFScriptFunction_saveSettings::`vftable';
  this->scriptFunction_clearLeaderboard.pThis = nullptr;
  this->scriptFunction_clearLeaderboard.__vftable = (idMainMenu::idSWFScriptFunction_clearLeaderboard_vtbl *)&idMainMenu::idSWFScriptFunction_clearLeaderboard::`vftable';
  this->scriptFunction_refreshLeaderboard.pThis = nullptr;
  this->scriptFunction_refreshLeaderboard.__vftable = (idMainMenu::idSWFScriptFunction_refreshLeaderboard_vtbl *)&idMainMenu::idSWFScriptFunction_refreshLeaderboard::`vftable';
  this->scriptFunction_scrollLeaderboard.pThis = nullptr;
  this->scriptFunction_scrollLeaderboard.__vftable = (idMainMenu::idSWFScriptFunction_scrollLeaderboard_vtbl *)&idMainMenu::idSWFScriptFunction_scrollLeaderboard::`vftable';
  this->scriptFunction_nextLeaderboard.pThis = nullptr;
  this->scriptFunction_nextLeaderboard.__vftable = (idMainMenu::idSWFScriptFunction_nextLeaderboard_vtbl *)&idMainMenu::idSWFScriptFunction_nextLeaderboard::`vftable';
  this->scriptFunction_prevLeaderboard.pThis = nullptr;
  this->scriptFunction_prevLeaderboard.__vftable = (idMainMenu::idSWFScriptFunction_prevLeaderboard_vtbl *)&idMainMenu::idSWFScriptFunction_prevLeaderboard::`vftable';
  this->scriptFunction_selectLeaderboardIndex.pThis = nullptr;
  this->scriptFunction_selectLeaderboardIndex.__vftable = (idMainMenu::idSWFScriptFunction_selectLeaderboardIndex_vtbl *)&idMainMenu::idSWFScriptFunction_selectLeaderboardIndex::`vftable';
  this->scriptFunction_showLeaderboardGamerCardUI.pThis = nullptr;
  this->scriptFunction_showLeaderboardGamerCardUI.__vftable = (idMainMenu::idSWFScriptFunction_showLeaderboardGamerCardUI_vtbl *)&idMainMenu::idSWFScriptFunction_showLeaderboardGamerCardUI::`vftable';
  this->scriptFunction_toggleCoopNightmareLeaderboard.pThis = nullptr;
  this->scriptFunction_toggleCoopNightmareLeaderboard.__vftable = (idMainMenu::idSWFScriptFunction_toggleCoopNightmareLeaderboard_vtbl *)&idMainMenu::idSWFScriptFunction_toggleCoopNightmareLeaderboard::`vftable';
  this->scriptFunction_isCoopNightmareLeaderboard.pThis = nullptr;
  this->scriptFunction_isCoopNightmareLeaderboard.__vftable = (idMainMenu::idSWFScriptFunction_isCoopNightmareLeaderboard_vtbl *)&idMainMenu::idSWFScriptFunction_isCoopNightmareLeaderboard::`vftable';
  this->scriptFunction_filterList.pThis = nullptr;
  this->scriptFunction_filterList.__vftable = (idMainMenu::idSWFScriptFunction_filterList_vtbl *)&idMainMenu::idSWFScriptFunction_filterList::`vftable';
  this->scriptFunction_setScrolling.pThis = nullptr;
  this->scriptFunction_setScrolling.__vftable = (idMainMenu::idSWFScriptFunction_setScrolling_vtbl *)&idMainMenu::idSWFScriptFunction_setScrolling::`vftable';
  this->scriptFunction_updateScroll.pThis = nullptr;
  this->scriptFunction_updateScroll.__vftable = (idMainMenu::idSWFScriptFunction_updateScroll_vtbl *)&idMainMenu::idSWFScriptFunction_updateScroll::`vftable';
  this->scriptFunction_updateLbScroll.pThis = nullptr;
  this->scriptFunction_updateLbScroll.__vftable = (idMainMenu::idSWFScriptFunction_updateLbScroll_vtbl *)&idMainMenu::idSWFScriptFunction_updateLbScroll::`vftable';
  this->scriptFunction_stopPlaytestRenderDemoRecord.pThis = nullptr;
  this->scriptFunction_stopPlaytestRenderDemoRecord.__vftable = (idMainMenu::idSWFScriptFunction_stopPlaytestRenderDemoRecord_vtbl *)&idMainMenu::idSWFScriptFunction_stopPlaytestRenderDemoRecord::`vftable';
  this->scriptFunction_setPlaytestSessionName.pThis = nullptr;
  this->scriptFunction_setPlaytestSessionName.__vftable = (idMainMenu::idSWFScriptFunction_setPlaytestSessionName_vtbl *)&idMainMenu::idSWFScriptFunction_setPlaytestSessionName::`vftable';
  this->scriptFunction_checkActivatePlaytestLogging.pThis = nullptr;
  this->scriptFunction_checkActivatePlaytestLogging.__vftable = (idMainMenu::idSWFScriptFunction_checkActivatePlaytestLogging_vtbl *)&idMainMenu::idSWFScriptFunction_checkActivatePlaytestLogging::`vftable';
  this->scriptFunction_checkActivateRenderDemo.pThis = nullptr;
  this->scriptFunction_checkActivateRenderDemo.__vftable = (idMainMenu::idSWFScriptFunction_checkActivateRenderDemo_vtbl *)&idMainMenu::idSWFScriptFunction_checkActivateRenderDemo::`vftable';
  this->scriptFunction_loadDevMenuOption.pThis = nullptr;
  this->scriptFunction_loadDevMenuOption.__vftable = (idMainMenu::idSWFScriptFunction_loadDevMenuOption_vtbl *)&idMainMenu::idSWFScriptFunction_loadDevMenuOption::`vftable';
  this->scriptFunction_isDemoMode.pThis = nullptr;
  this->scriptFunction_isDemoMode.__vftable = (idMainMenu::idSWFScriptFunction_isDemoMode_vtbl *)&idMainMenu::idSWFScriptFunction_isDemoMode::`vftable';
  this->scriptFunction_showDLCOption.pThis = nullptr;
  this->scriptFunction_showDLCOption.__vftable = (idMainMenu::idSWFScriptFunction_showDLCOption_vtbl *)&idMainMenu::idSWFScriptFunction_showDLCOption::`vftable';
  this->scriptFunction_hasNewDLC.pThis = nullptr;
  this->scriptFunction_hasNewDLC.__vftable = (idMainMenu::idSWFScriptFunction_hasNewDLC_vtbl *)&idMainMenu::idSWFScriptFunction_hasNewDLC::`vftable';
  this->scriptFunction_showDLCMenu.pThis = nullptr;
  this->scriptFunction_showDLCMenu.__vftable = (idMainMenu::idSWFScriptFunction_showDLCMenu_vtbl *)&idMainMenu::idSWFScriptFunction_showDLCMenu::`vftable';
  this->scriptFunction_isGameInstalled.pThis = nullptr;
  this->scriptFunction_isGameInstalled.__vftable = (idMainMenu::idSWFScriptFunction_isGameInstalled_vtbl *)&idMainMenu::idSWFScriptFunction_isGameInstalled::`vftable';
  this->scriptFunction_showCredits.pThis = nullptr;
  this->scriptFunction_showCredits.__vftable = (idMainMenu::idSWFScriptFunction_showCredits_vtbl *)&idMainMenu::idSWFScriptFunction_showCredits::`vftable';
  this->scriptFunction_ps3ShowFriends.pThis = nullptr;
  this->scriptFunction_ps3ShowFriends.__vftable = (idMainMenu::idSWFScriptFunction_ps3ShowFriends_vtbl *)&idMainMenu::idSWFScriptFunction_ps3ShowFriends::`vftable';
  this->scriptFunction_ps3ShowNotifications.pThis = nullptr;
  this->scriptFunction_ps3ShowNotifications.__vftable = (idMainMenu::idSWFScriptFunction_ps3ShowNotifications_vtbl *)&idMainMenu::idSWFScriptFunction_ps3ShowNotifications::`vftable';
  this->scriptFunction_ps3CheckInvites.pThis = nullptr;
  this->scriptFunction_ps3CheckInvites.__vftable = (idMainMenu::idSWFScriptFunction_ps3CheckInvites_vtbl *)&idMainMenu::idSWFScriptFunction_ps3CheckInvites::`vftable';
  this->scriptFunction_hasContentPack.pThis = nullptr;
  this->scriptFunction_hasContentPack.__vftable = (idMainMenu::idSWFScriptFunction_hasContentPack_vtbl *)&idMainMenu::idSWFScriptFunction_hasContentPack::`vftable';
  this->scriptFunction_isMpHandsOnDemo.pThis = nullptr;
  this->scriptFunction_isMpHandsOnDemo.__vftable = (idMainMenu::idSWFScriptFunction_isMpHandsOnDemo_vtbl *)&idMainMenu::idSWFScriptFunction_isMpHandsOnDemo::`vftable';
  if ( idMainMenu::pMPMaps == nullptr )
    idMainMenu::pMPMaps = &this->mpMaps;
  this->activeMenu = MENU_AREA_INVALID;
  p_menuTransition = &this->menuTransition;
  this->nextMenu = MENU_AREA_INVALID;
  for ( i = 7; i != 0; --i )
  {
    *((_DWORD *)p_menuTransition + 8) = 0;
    *((_DWORD *)p_menuTransition++ + 15) = 0;
    *p_menuTransition = MENU_TRANSITION_ADVANCE;
  }
  this->menuTransition = MENU_TRANSITION_INVALID;
  this->scrollingMenu = false;
  this->scrollCounter = 0;
  this->devMenuDepth = 0;
  this->devMenuList = nullptr;
  this->guiModel = nullptr;
  this->audioMasterVolume = 0.0;
  this->soundWorld = nullptr;
  this->audioVoiceVolume = 0.0;
  this->loadMostRecentCallingGui = nullptr;
  this->audioMusicVolume = 0.0;
  this->testGui = nullptr;
  this->audioAmbientVolume = 0.0;
  this->mainMenu = nullptr;
  this->audioMasterVolume_Restore = 0.0;
  this->popupGui = nullptr;
  this->audioVoiceVolume_Restore = 0.0;
  this->currentDeviceIndex = 0;
  this->audioMusicVolume_Restore = 0.0;
  this->savegameEnumHandle = 0;
  this->audioAmbientVolume_Restore = 0.0;
  this->closePopupGui = false;
  this->popupResult = -1;
  this->showingMatchResults = false;
  this->showingUnlockedItemIndex = 0;
  this->nextScrollTime = 0;
  this->scrollSpeed = 210;
  this->waitForBinding = false;
  this->finishBinding = false;
  this->bindWaitKey = -1;
  this->bindSet = 0;
  this->savedGamesUpdateRequested = false;
  this->audioSubtitles = false;
  this->audioSubtitles_Restore = false;
  *(_WORD *)&this->isDeletingGame = 1;
  this->pauseMenuState = PAUSEMENU_DEFAULT;
  this->askedForSignIn = false;
  this->singlePlayerSelected = false;
  this->requestingDevice = false;
  this->saveAfterDeviceRequest = false;
  this->autosaveWarningShown = false;
  this->autosaveWarningShownAllowsAutosave = false;
  this->requestingDLC = false;
  this->ps3MenuRequested = false;
  this->returnToPressStartWaitSaveComplete = false;
  this->matchMapIndex = 0;
  this->matchModeIndex = 0;
  this->matchSearchIndex = -1;
  this->matchTypeIndex = 0;
  this->privateMatch = true;
  this->localMatch = false;
  this->coopDifficulty = 0;
  this->scoreLimit = 200;
  this->timeLimit = 600;
  this->coopInviteOnly = false;
  this->vdmInviteOnly = false;
  this->deferredActivateMsec = 0;
  this->deferredDeactivateMsec = 0;
  this->menuState = -1;
  this->lastMenuState = -1;
  this->installMessageShown = false;
  this->diskSwapInputLock = false;
  this->storageDialogActivated = false;
  this->askToDeleteAutosaveOnNewGame = false;
  this->lbCache = nullptr;
  this->vdmLeaderboard = true;
  this->coopLBIndex = 0;
  this->vdmLBIndex = 0;
  this->refreshLeaderboard = false;
  this->refreshWhenMasterIsOnline = false;
  this->moveToCampaign = false;
  this->isScrolling = false;
  this->refreshing = false;
  this->scrollDelay = 0;
  this->pausedOnEnter = false;
  this->isProfileScreenOpenBool = false;
  this->onLoadMenu = true;
  v10.baseBuffer[0] = 0;
  this->menuRequest = MENU_SWITCH_NONE;
  v11 = 0;
  v10.data = &v11;
  v10.len = 0;
  v10.allocedAndFlag = -2147481600;
  idStr::operator=(this: &v10, text: &byte_8200D768);
  data = v10.data;
  v5 = v10.len + 1;
  v6 = this->chatHistory.data;
  this->chatHistory.len = v10.len;
  memcpy(Dst: v6, Src: data, Size: v5);
  idStr::FreeData(this: &v10);
  this->viewCoopNightmareLeaderboard = false;
  this->wasViewingMpConfig = false;
  this->menuArea = MENU_PRESS_START;
  this->desiredMenuArea = MENU_PRESS_START;
  this->oldSessionState = PRESS_START;
  this->showingMigratingTime = -1;
  v7 = (idLobbyController *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x50u,
                              tag: TAG_NETWORKING,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
    v8 = idLobbyController::idLobbyController(this: v7, menu: this);
  else
    v8 = nullptr;
  this->lobbyController = v8;
  return this;
}


// ========================================================================
// __unwind$539591
// EA  : 0x82DB77D8
// RVA : 0x00DB77D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539591()
{
  int v0; // r12

  idMainMenu::actionRepeater_t::~actionRepeater_t(this: *(idMainMenu::actionRepeater_t **)(v0 - 2256 + 2276));
}


// ========================================================================
// __unwind$539592
// EA  : 0x82DB7800
// RVA : 0x00DB7800
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539592()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 2256 + 2276) + 432));
}


// ========================================================================
// __unwind$539593
// EA  : 0x82DB782C
// RVA : 0x00DB782C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539593()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 2256 + 2276) + 464));
}


// ========================================================================
// __unwind$539594
// EA  : 0x82DB7858
// RVA : 0x00DB7858
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539594()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 2256 + 2276) + 496));
}


// ========================================================================
// __unwind$539595
// EA  : 0x82DB7884
// RVA : 0x00DB7884
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539595()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 2256 + 2276) + 528));
}


// ========================================================================
// __unwind$539596
// EA  : 0x82DB78B0
// RVA : 0x00DB78B0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539596()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 2256 + 2276) + 568));
}


// ========================================================================
// __unwind$539597
// EA  : 0x82DB78DC
// RVA : 0x00DB78DC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539597()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 2256 + 2276) + 584));
}


// ========================================================================
// __unwind$539598
// EA  : 0x82DB7908
// RVA : 0x00DB7908
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539598()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 2256 + 2276) + 600));
}


// ========================================================================
// __unwind$539599
// EA  : 0x82DB7934
// RVA : 0x00DB7934
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539599()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 2256 + 2276) + 692));
}


// ========================================================================
// __unwind$539600
// EA  : 0x82DB7960
// RVA : 0x00DB7960
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539600()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 2256 + 2276) + 748));
}


// ========================================================================
// __unwind$539601
// EA  : 0x82DB798C
// RVA : 0x00DB798C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539601()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 2256 + 2276) + 796));
}


// ========================================================================
// __unwind$539602_0
// EA  : 0x82DB79B8
// RVA : 0x00DB79B8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539602_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 2256 + 2276) + 804));
}


// ========================================================================
// __unwind$539603
// EA  : 0x82DB79E4
// RVA : 0x00DB79E4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539603()
{
  int v0; // r12

  idList<idSubtitles::idPart,5>::Clear(this: (idSubtitleSequencer *)(*(_DWORD *)(v0 - 2256 + 2276) + 932));
}


// ========================================================================
// __unwind$539604
// EA  : 0x82DB7A10
// RVA : 0x00DB7A10
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539604()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 2256 + 2276) + 956));
}


// ========================================================================
// __unwind$539605
// EA  : 0x82DB7A3C
// RVA : 0x00DB7A3C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539605()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 2256 + 2276) + 3036));
}


// ========================================================================
// __unwind$539606
// EA  : 0x82DB7A68
// RVA : 0x00DB7A68
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539606()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 2256 + 2276) + 3056));
}


// ========================================================================
// __unwind$539607
// EA  : 0x82DB7A94
// RVA : 0x00DB7A94
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539607()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 2256 + 2276) + 3112));
}


// ========================================================================
// __unwind$539608
// EA  : 0x82DB7AC0
// RVA : 0x00DB7AC0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539608()
{
  int v0; // r12

  idList<mpMap_t,57>::Clear(this: (idList<mpMap_t,57> *)(*(_DWORD *)(v0 - 2256 + 2276) + 3132));
}


// ========================================================================
// __unwind$539609
// EA  : 0x82DB7AEC
// RVA : 0x00DB7AEC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539609()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 2256 + 2276) + 3148));
}


// ========================================================================
// __unwind$539610
// EA  : 0x82DB7B18
// RVA : 0x00DB7B18
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539610()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 2256 + 2276) + 3164));
}


// ========================================================================
// __unwind$539611_0
// EA  : 0x82DB7B44
// RVA : 0x00DB7B44
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539611_0()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3196));
}


// ========================================================================
// __unwind$539612
// EA  : 0x82DB7B70
// RVA : 0x00DB7B70
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539612()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3204));
}


// ========================================================================
// __unwind$539613
// EA  : 0x82DB7B9C
// RVA : 0x00DB7B9C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539613()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3212));
}


// ========================================================================
// __unwind$539614
// EA  : 0x82DB7BC8
// RVA : 0x00DB7BC8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539614()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3220));
}


// ========================================================================
// __unwind$539615
// EA  : 0x82DB7BF4
// RVA : 0x00DB7BF4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539615()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3228));
}


// ========================================================================
// __unwind$539616
// EA  : 0x82DB7C20
// RVA : 0x00DB7C20
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539616()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3236));
}


// ========================================================================
// __unwind$539617
// EA  : 0x82DB7C4C
// RVA : 0x00DB7C4C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539617()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3244));
}


// ========================================================================
// __unwind$539618
// EA  : 0x82DB7C78
// RVA : 0x00DB7C78
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539618()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3252));
}


// ========================================================================
// __unwind$539619
// EA  : 0x82DB7CA4
// RVA : 0x00DB7CA4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539619()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3260));
}


// ========================================================================
// __unwind$539620
// EA  : 0x82DB7CD0
// RVA : 0x00DB7CD0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539620()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3268));
}


// ========================================================================
// __unwind$539621
// EA  : 0x82DB7CFC
// RVA : 0x00DB7CFC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539621()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3276));
}


// ========================================================================
// __unwind$539622
// EA  : 0x82DB7D28
// RVA : 0x00DB7D28
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539622()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3284));
}


// ========================================================================
// __unwind$539623
// EA  : 0x82DB7D54
// RVA : 0x00DB7D54
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539623()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3292));
}


// ========================================================================
// __unwind$539624
// EA  : 0x82DB7D80
// RVA : 0x00DB7D80
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539624()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3300));
}


// ========================================================================
// __unwind$539625
// EA  : 0x82DB7DAC
// RVA : 0x00DB7DAC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539625()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3308));
}


// ========================================================================
// __unwind$539626
// EA  : 0x82DB7DD8
// RVA : 0x00DB7DD8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539626()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3316));
}


// ========================================================================
// __unwind$539627
// EA  : 0x82DB7E04
// RVA : 0x00DB7E04
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539627()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3324));
}


// ========================================================================
// __unwind$539628
// EA  : 0x82DB7E30
// RVA : 0x00DB7E30
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539628()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3332));
}


// ========================================================================
// __unwind$539629
// EA  : 0x82DB7E5C
// RVA : 0x00DB7E5C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539629()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3340));
}


// ========================================================================
// __unwind$539630
// EA  : 0x82DB7E88
// RVA : 0x00DB7E88
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539630()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3348));
}


// ========================================================================
// __unwind$539631
// EA  : 0x82DB7EB4
// RVA : 0x00DB7EB4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539631()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3356));
}


// ========================================================================
// __unwind$539632
// EA  : 0x82DB7EE0
// RVA : 0x00DB7EE0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539632()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3364));
}


// ========================================================================
// __unwind$539633
// EA  : 0x82DB7F0C
// RVA : 0x00DB7F0C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539633()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3372));
}


// ========================================================================
// __unwind$539634
// EA  : 0x82DB7F38
// RVA : 0x00DB7F38
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539634()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3380));
}


// ========================================================================
// __unwind$539635
// EA  : 0x82DB7F64
// RVA : 0x00DB7F64
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539635()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3388));
}


// ========================================================================
// __unwind$539636
// EA  : 0x82DB7F90
// RVA : 0x00DB7F90
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539636()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3396));
}


// ========================================================================
// __unwind$539637
// EA  : 0x82DB7FBC
// RVA : 0x00DB7FBC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539637()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3404));
}


// ========================================================================
// __unwind$539638
// EA  : 0x82DB7FE8
// RVA : 0x00DB7FE8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539638()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3412));
}


// ========================================================================
// __unwind$539639
// EA  : 0x82DB8014
// RVA : 0x00DB8014
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539639()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3420));
}


// ========================================================================
// __unwind$539640
// EA  : 0x82DB8040
// RVA : 0x00DB8040
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539640()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3428));
}


// ========================================================================
// __unwind$539641
// EA  : 0x82DB806C
// RVA : 0x00DB806C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539641()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3436));
}


// ========================================================================
// __unwind$539642
// EA  : 0x82DB8098
// RVA : 0x00DB8098
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539642()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3444));
}


// ========================================================================
// __unwind$539643
// EA  : 0x82DB80C4
// RVA : 0x00DB80C4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539643()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3452));
}


// ========================================================================
// __unwind$539644
// EA  : 0x82DB80F0
// RVA : 0x00DB80F0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539644()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3460));
}


// ========================================================================
// __unwind$539645
// EA  : 0x82DB811C
// RVA : 0x00DB811C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539645()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3468));
}


// ========================================================================
// __unwind$539646
// EA  : 0x82DB8148
// RVA : 0x00DB8148
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539646()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3476));
}


// ========================================================================
// __unwind$539647
// EA  : 0x82DB8174
// RVA : 0x00DB8174
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539647()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3484));
}


// ========================================================================
// __unwind$539648
// EA  : 0x82DB81A0
// RVA : 0x00DB81A0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539648()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3492));
}


// ========================================================================
// __unwind$539649
// EA  : 0x82DB81CC
// RVA : 0x00DB81CC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539649()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3500));
}


// ========================================================================
// __unwind$539650
// EA  : 0x82DB81F8
// RVA : 0x00DB81F8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539650()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3508));
}


// ========================================================================
// __unwind$539651
// EA  : 0x82DB8224
// RVA : 0x00DB8224
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539651()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3516));
}


// ========================================================================
// __unwind$539652
// EA  : 0x82DB8250
// RVA : 0x00DB8250
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539652()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3524));
}


// ========================================================================
// __unwind$539653
// EA  : 0x82DB827C
// RVA : 0x00DB827C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539653()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3532));
}


// ========================================================================
// __unwind$539654
// EA  : 0x82DB82A8
// RVA : 0x00DB82A8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539654()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3540));
}


// ========================================================================
// __unwind$539655
// EA  : 0x82DB82D4
// RVA : 0x00DB82D4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539655()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3548));
}


// ========================================================================
// __unwind$539656
// EA  : 0x82DB8300
// RVA : 0x00DB8300
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539656()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3556));
}


// ========================================================================
// __unwind$539657
// EA  : 0x82DB832C
// RVA : 0x00DB832C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539657()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3564));
}


// ========================================================================
// __unwind$539658
// EA  : 0x82DB8358
// RVA : 0x00DB8358
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539658()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3572));
}


// ========================================================================
// __unwind$539659
// EA  : 0x82DB8384
// RVA : 0x00DB8384
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539659()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3580));
}


// ========================================================================
// __unwind$539660
// EA  : 0x82DB83B0
// RVA : 0x00DB83B0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539660()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3588));
}


// ========================================================================
// __unwind$539661
// EA  : 0x82DB83DC
// RVA : 0x00DB83DC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539661()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3596));
}


// ========================================================================
// __unwind$539662
// EA  : 0x82DB8408
// RVA : 0x00DB8408
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539662()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3604));
}


// ========================================================================
// __unwind$539663
// EA  : 0x82DB8434
// RVA : 0x00DB8434
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539663()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3612));
}


// ========================================================================
// __unwind$539664
// EA  : 0x82DB8460
// RVA : 0x00DB8460
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539664()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3620));
}


// ========================================================================
// __unwind$539665
// EA  : 0x82DB848C
// RVA : 0x00DB848C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539665()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3628));
}


// ========================================================================
// __unwind$539666
// EA  : 0x82DB84B8
// RVA : 0x00DB84B8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539666()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3636));
}


// ========================================================================
// __unwind$539667
// EA  : 0x82DB84E4
// RVA : 0x00DB84E4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539667()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3644));
}


// ========================================================================
// __unwind$539668
// EA  : 0x82DB8510
// RVA : 0x00DB8510
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539668()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3652));
}


// ========================================================================
// __unwind$539669
// EA  : 0x82DB853C
// RVA : 0x00DB853C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539669()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3660));
}


// ========================================================================
// __unwind$539670
// EA  : 0x82DB8568
// RVA : 0x00DB8568
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539670()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3668));
}


// ========================================================================
// __unwind$539671_0
// EA  : 0x82DB8594
// RVA : 0x00DB8594
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539671_0()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3676));
}


// ========================================================================
// __unwind$539672
// EA  : 0x82DB85C0
// RVA : 0x00DB85C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539672()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3684));
}


// ========================================================================
// __unwind$539673
// EA  : 0x82DB85EC
// RVA : 0x00DB85EC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539673()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3692));
}


// ========================================================================
// __unwind$539674
// EA  : 0x82DB8618
// RVA : 0x00DB8618
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539674()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3700));
}


// ========================================================================
// __unwind$539675
// EA  : 0x82DB8644
// RVA : 0x00DB8644
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539675()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3708));
}


// ========================================================================
// __unwind$539676
// EA  : 0x82DB8670
// RVA : 0x00DB8670
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539676()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3716));
}


// ========================================================================
// __unwind$539677
// EA  : 0x82DB869C
// RVA : 0x00DB869C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539677()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3724));
}


// ========================================================================
// __unwind$539678
// EA  : 0x82DB86C8
// RVA : 0x00DB86C8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539678()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3732));
}


// ========================================================================
// __unwind$539679
// EA  : 0x82DB86F4
// RVA : 0x00DB86F4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539679()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3740));
}


// ========================================================================
// __unwind$539680
// EA  : 0x82DB8720
// RVA : 0x00DB8720
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539680()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3748));
}


// ========================================================================
// __unwind$539681
// EA  : 0x82DB874C
// RVA : 0x00DB874C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539681()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3756));
}


// ========================================================================
// __unwind$539682
// EA  : 0x82DB8778
// RVA : 0x00DB8778
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539682()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3764));
}


// ========================================================================
// __unwind$539683
// EA  : 0x82DB87A4
// RVA : 0x00DB87A4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539683()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3772));
}


// ========================================================================
// __unwind$539684
// EA  : 0x82DB87D0
// RVA : 0x00DB87D0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539684()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3780));
}


// ========================================================================
// __unwind$539685
// EA  : 0x82DB87FC
// RVA : 0x00DB87FC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539685()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3788));
}


// ========================================================================
// __unwind$539686
// EA  : 0x82DB8828
// RVA : 0x00DB8828
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539686()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3796));
}


// ========================================================================
// __unwind$539687
// EA  : 0x82DB8854
// RVA : 0x00DB8854
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539687()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3804));
}


// ========================================================================
// __unwind$539688
// EA  : 0x82DB8880
// RVA : 0x00DB8880
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539688()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3812));
}


// ========================================================================
// __unwind$539689
// EA  : 0x82DB88AC
// RVA : 0x00DB88AC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539689()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3820));
}


// ========================================================================
// __unwind$539690
// EA  : 0x82DB88D8
// RVA : 0x00DB88D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539690()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3828));
}


// ========================================================================
// __unwind$539691
// EA  : 0x82DB8904
// RVA : 0x00DB8904
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539691()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3836));
}


// ========================================================================
// __unwind$539692
// EA  : 0x82DB8930
// RVA : 0x00DB8930
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539692()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3844));
}


// ========================================================================
// __unwind$539693
// EA  : 0x82DB895C
// RVA : 0x00DB895C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539693()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3852));
}


// ========================================================================
// __unwind$539694
// EA  : 0x82DB8988
// RVA : 0x00DB8988
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539694()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3860));
}


// ========================================================================
// __unwind$539695
// EA  : 0x82DB89B4
// RVA : 0x00DB89B4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539695()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3868));
}


// ========================================================================
// __unwind$539696
// EA  : 0x82DB89E0
// RVA : 0x00DB89E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539696()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3876));
}


// ========================================================================
// __unwind$539697
// EA  : 0x82DB8A0C
// RVA : 0x00DB8A0C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539697()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3884));
}


// ========================================================================
// __unwind$539698
// EA  : 0x82DB8A38
// RVA : 0x00DB8A38
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539698()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3892));
}


// ========================================================================
// __unwind$539699
// EA  : 0x82DB8A64
// RVA : 0x00DB8A64
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539699()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3900));
}


// ========================================================================
// __unwind$539700
// EA  : 0x82DB8A90
// RVA : 0x00DB8A90
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539700()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3908));
}


// ========================================================================
// __unwind$539701
// EA  : 0x82DB8ABC
// RVA : 0x00DB8ABC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539701()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3916));
}


// ========================================================================
// __unwind$539702
// EA  : 0x82DB8AE8
// RVA : 0x00DB8AE8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539702()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3924));
}


// ========================================================================
// __unwind$539703
// EA  : 0x82DB8B14
// RVA : 0x00DB8B14
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539703()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3932));
}


// ========================================================================
// __unwind$539704
// EA  : 0x82DB8B40
// RVA : 0x00DB8B40
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539704()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3940));
}


// ========================================================================
// __unwind$539705
// EA  : 0x82DB8B6C
// RVA : 0x00DB8B6C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539705()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3948));
}


// ========================================================================
// __unwind$539706
// EA  : 0x82DB8B98
// RVA : 0x00DB8B98
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539706()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3956));
}


// ========================================================================
// __unwind$539707
// EA  : 0x82DB8BC4
// RVA : 0x00DB8BC4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539707()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3964));
}


// ========================================================================
// __unwind$539708
// EA  : 0x82DB8BF0
// RVA : 0x00DB8BF0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539708()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3972));
}


// ========================================================================
// __unwind$539709_0
// EA  : 0x82DB8C1C
// RVA : 0x00DB8C1C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539709_0()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3980));
}


// ========================================================================
// __unwind$539710
// EA  : 0x82DB8C48
// RVA : 0x00DB8C48
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539710()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3988));
}


// ========================================================================
// __unwind$539711
// EA  : 0x82DB8C74
// RVA : 0x00DB8C74
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539711()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 3996));
}


// ========================================================================
// __unwind$539712
// EA  : 0x82DB8CA0
// RVA : 0x00DB8CA0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539712()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4004));
}


// ========================================================================
// __unwind$539713
// EA  : 0x82DB8CCC
// RVA : 0x00DB8CCC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539713()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4012));
}


// ========================================================================
// __unwind$539714
// EA  : 0x82DB8CF8
// RVA : 0x00DB8CF8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539714()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4020));
}


// ========================================================================
// __unwind$539715
// EA  : 0x82DB8D24
// RVA : 0x00DB8D24
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539715()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4028));
}


// ========================================================================
// __unwind$539716
// EA  : 0x82DB8D50
// RVA : 0x00DB8D50
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539716()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4036));
}


// ========================================================================
// __unwind$539717
// EA  : 0x82DB8D7C
// RVA : 0x00DB8D7C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539717()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4044));
}


// ========================================================================
// __unwind$539718_0
// EA  : 0x82DB8DA8
// RVA : 0x00DB8DA8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539718_0()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4052));
}


// ========================================================================
// __unwind$539719
// EA  : 0x82DB8DD4
// RVA : 0x00DB8DD4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539719()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4060));
}


// ========================================================================
// __unwind$539720
// EA  : 0x82DB8E00
// RVA : 0x00DB8E00
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539720()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4068));
}


// ========================================================================
// __unwind$539721
// EA  : 0x82DB8E2C
// RVA : 0x00DB8E2C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539721()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4076));
}


// ========================================================================
// __unwind$539722
// EA  : 0x82DB8E58
// RVA : 0x00DB8E58
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539722()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4084));
}


// ========================================================================
// __unwind$539723
// EA  : 0x82DB8E84
// RVA : 0x00DB8E84
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539723()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4092));
}


// ========================================================================
// __unwind$539724
// EA  : 0x82DB8EB0
// RVA : 0x00DB8EB0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539724()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4100));
}


// ========================================================================
// __unwind$539725
// EA  : 0x82DB8EDC
// RVA : 0x00DB8EDC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539725()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4108));
}


// ========================================================================
// __unwind$539726
// EA  : 0x82DB8F08
// RVA : 0x00DB8F08
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539726()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4116));
}


// ========================================================================
// __unwind$539727
// EA  : 0x82DB8F34
// RVA : 0x00DB8F34
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539727()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4124));
}


// ========================================================================
// __unwind$539728
// EA  : 0x82DB8F60
// RVA : 0x00DB8F60
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539728()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4132));
}


// ========================================================================
// __unwind$539729
// EA  : 0x82DB8F8C
// RVA : 0x00DB8F8C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539729()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4140));
}


// ========================================================================
// __unwind$539730
// EA  : 0x82DB8FB8
// RVA : 0x00DB8FB8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539730()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4148));
}


// ========================================================================
// __unwind$539731
// EA  : 0x82DB8FE4
// RVA : 0x00DB8FE4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539731()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4156));
}


// ========================================================================
// __unwind$539732
// EA  : 0x82DB9010
// RVA : 0x00DB9010
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539732()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4164));
}


// ========================================================================
// __unwind$539733
// EA  : 0x82DB903C
// RVA : 0x00DB903C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539733()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4172));
}


// ========================================================================
// __unwind$539734
// EA  : 0x82DB9068
// RVA : 0x00DB9068
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539734()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4180));
}


// ========================================================================
// __unwind$539735
// EA  : 0x82DB9094
// RVA : 0x00DB9094
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539735()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4188));
}


// ========================================================================
// __unwind$539736
// EA  : 0x82DB90C0
// RVA : 0x00DB90C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539736()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4196));
}


// ========================================================================
// __unwind$539737
// EA  : 0x82DB90EC
// RVA : 0x00DB90EC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539737()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4204));
}


// ========================================================================
// __unwind$539738
// EA  : 0x82DB9118
// RVA : 0x00DB9118
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539738()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4212));
}


// ========================================================================
// __unwind$539739
// EA  : 0x82DB9144
// RVA : 0x00DB9144
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539739()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4220));
}


// ========================================================================
// __unwind$539740
// EA  : 0x82DB9170
// RVA : 0x00DB9170
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539740()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4228));
}


// ========================================================================
// __unwind$539741
// EA  : 0x82DB919C
// RVA : 0x00DB919C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539741()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4236));
}


// ========================================================================
// __unwind$539742
// EA  : 0x82DB91C8
// RVA : 0x00DB91C8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539742()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4244));
}


// ========================================================================
// __unwind$539743
// EA  : 0x82DB91F4
// RVA : 0x00DB91F4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539743()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4252));
}


// ========================================================================
// __unwind$539744
// EA  : 0x82DB9220
// RVA : 0x00DB9220
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539744()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4260));
}


// ========================================================================
// __unwind$539745
// EA  : 0x82DB924C
// RVA : 0x00DB924C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539745()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4268));
}


// ========================================================================
// __unwind$539746
// EA  : 0x82DB9278
// RVA : 0x00DB9278
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539746()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4276));
}


// ========================================================================
// __unwind$539747
// EA  : 0x82DB92A4
// RVA : 0x00DB92A4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539747()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4284));
}


// ========================================================================
// __unwind$539748
// EA  : 0x82DB92D0
// RVA : 0x00DB92D0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539748()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4292));
}


// ========================================================================
// __unwind$539749
// EA  : 0x82DB92FC
// RVA : 0x00DB92FC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539749()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4300));
}


// ========================================================================
// __unwind$539750
// EA  : 0x82DB9328
// RVA : 0x00DB9328
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539750()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4308));
}


// ========================================================================
// __unwind$539751
// EA  : 0x82DB9354
// RVA : 0x00DB9354
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539751()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4316));
}


// ========================================================================
// __unwind$539752
// EA  : 0x82DB9380
// RVA : 0x00DB9380
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539752()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4324));
}


// ========================================================================
// __unwind$539753
// EA  : 0x82DB93AC
// RVA : 0x00DB93AC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539753()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4332));
}


// ========================================================================
// __unwind$539754
// EA  : 0x82DB93D8
// RVA : 0x00DB93D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539754()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4340));
}


// ========================================================================
// __unwind$539755
// EA  : 0x82DB9404
// RVA : 0x00DB9404
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539755()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4348));
}


// ========================================================================
// __unwind$539756
// EA  : 0x82DB9430
// RVA : 0x00DB9430
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539756()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4356));
}


// ========================================================================
// __unwind$539757
// EA  : 0x82DB945C
// RVA : 0x00DB945C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539757()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4364));
}


// ========================================================================
// __unwind$539758
// EA  : 0x82DB9488
// RVA : 0x00DB9488
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539758()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4372));
}


// ========================================================================
// __unwind$539759
// EA  : 0x82DB94B4
// RVA : 0x00DB94B4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539759()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4380));
}


// ========================================================================
// __unwind$539760_0
// EA  : 0x82DB94E0
// RVA : 0x00DB94E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539760_0()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4388));
}


// ========================================================================
// __unwind$539761
// EA  : 0x82DB950C
// RVA : 0x00DB950C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539761()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4396));
}


// ========================================================================
// __unwind$539762
// EA  : 0x82DB9538
// RVA : 0x00DB9538
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539762()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4404));
}


// ========================================================================
// __unwind$539763
// EA  : 0x82DB9564
// RVA : 0x00DB9564
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539763()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4412));
}


// ========================================================================
// __unwind$539764
// EA  : 0x82DB9590
// RVA : 0x00DB9590
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539764()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4420));
}


// ========================================================================
// __unwind$539765
// EA  : 0x82DB95BC
// RVA : 0x00DB95BC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539765()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4428));
}


// ========================================================================
// __unwind$539766
// EA  : 0x82DB95E8
// RVA : 0x00DB95E8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539766()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4436));
}


// ========================================================================
// __unwind$539767
// EA  : 0x82DB9614
// RVA : 0x00DB9614
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539767()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4444));
}


// ========================================================================
// __unwind$539768
// EA  : 0x82DB9640
// RVA : 0x00DB9640
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539768()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4452));
}


// ========================================================================
// __unwind$539769
// EA  : 0x82DB966C
// RVA : 0x00DB966C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539769()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4460));
}


// ========================================================================
// __unwind$539770
// EA  : 0x82DB9698
// RVA : 0x00DB9698
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539770()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4468));
}


// ========================================================================
// __unwind$539771
// EA  : 0x82DB96C4
// RVA : 0x00DB96C4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539771()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4476));
}


// ========================================================================
// __unwind$539772
// EA  : 0x82DB96F0
// RVA : 0x00DB96F0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539772()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4484));
}


// ========================================================================
// __unwind$539773
// EA  : 0x82DB971C
// RVA : 0x00DB971C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539773()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4492));
}


// ========================================================================
// __unwind$539774
// EA  : 0x82DB9748
// RVA : 0x00DB9748
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539774()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4500));
}


// ========================================================================
// __unwind$539775
// EA  : 0x82DB9774
// RVA : 0x00DB9774
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539775()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4508));
}


// ========================================================================
// __unwind$539776
// EA  : 0x82DB97A0
// RVA : 0x00DB97A0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539776()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4516));
}


// ========================================================================
// __unwind$539777
// EA  : 0x82DB97CC
// RVA : 0x00DB97CC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539777()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4524));
}


// ========================================================================
// __unwind$539778
// EA  : 0x82DB97F8
// RVA : 0x00DB97F8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539778()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4532));
}


// ========================================================================
// __unwind$539779
// EA  : 0x82DB9824
// RVA : 0x00DB9824
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539779()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4540));
}


// ========================================================================
// __unwind$539780
// EA  : 0x82DB9850
// RVA : 0x00DB9850
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539780()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4548));
}


// ========================================================================
// __unwind$539781
// EA  : 0x82DB987C
// RVA : 0x00DB987C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539781()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4556));
}


// ========================================================================
// __unwind$539782
// EA  : 0x82DB98A8
// RVA : 0x00DB98A8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539782()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4564));
}


// ========================================================================
// __unwind$539783
// EA  : 0x82DB98D4
// RVA : 0x00DB98D4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539783()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4572));
}


// ========================================================================
// __unwind$539784
// EA  : 0x82DB9900
// RVA : 0x00DB9900
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539784()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4580));
}


// ========================================================================
// __unwind$539785_0
// EA  : 0x82DB992C
// RVA : 0x00DB992C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539785_0()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4588));
}


// ========================================================================
// __unwind$539786
// EA  : 0x82DB9958
// RVA : 0x00DB9958
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539786()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4596));
}


// ========================================================================
// __unwind$539787
// EA  : 0x82DB9984
// RVA : 0x00DB9984
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539787()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4604));
}


// ========================================================================
// __unwind$539788
// EA  : 0x82DB99B0
// RVA : 0x00DB99B0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539788()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4612));
}


// ========================================================================
// __unwind$539789
// EA  : 0x82DB99DC
// RVA : 0x00DB99DC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539789()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4620));
}


// ========================================================================
// __unwind$539790
// EA  : 0x82DB9A08
// RVA : 0x00DB9A08
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539790()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4628));
}


// ========================================================================
// __unwind$539791
// EA  : 0x82DB9A34
// RVA : 0x00DB9A34
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539791()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4636));
}


// ========================================================================
// __unwind$539792
// EA  : 0x82DB9A60
// RVA : 0x00DB9A60
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539792()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4644));
}


// ========================================================================
// __unwind$539793
// EA  : 0x82DB9A8C
// RVA : 0x00DB9A8C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539793()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4652));
}


// ========================================================================
// __unwind$539794
// EA  : 0x82DB9AB8
// RVA : 0x00DB9AB8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539794()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4660));
}


// ========================================================================
// __unwind$539795
// EA  : 0x82DB9AE4
// RVA : 0x00DB9AE4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539795()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4668));
}


// ========================================================================
// __unwind$539796
// EA  : 0x82DB9B10
// RVA : 0x00DB9B10
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539796()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4676));
}


// ========================================================================
// __unwind$539797
// EA  : 0x82DB9B3C
// RVA : 0x00DB9B3C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539797()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4684));
}


// ========================================================================
// __unwind$539798
// EA  : 0x82DB9B68
// RVA : 0x00DB9B68
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539798()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4692));
}


// ========================================================================
// __unwind$539799
// EA  : 0x82DB9B94
// RVA : 0x00DB9B94
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539799()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 2256 + 2276) + 4700));
}


// ========================================================================
// __unwind$543140
// EA  : 0x82DB9BC0
// RVA : 0x00DB9BC0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_543140()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2256 + 96));
}


// ========================================================================
// __unwind$539801
// EA  : 0x82DB9BE8
// RVA : 0x00DB9BE8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_539801()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2256 + 80), tag: TAG_NETWORKING);
}


// ========================================================================
// ??1idMainMenu@@QAA@XZ
// EA  : 0x82DB9C20
// RVA : 0x00DB9C20
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __fastcall idMainMenu::~idMainMenu(idMainMenu *this)
{
  idRenderModelGui *guiModel; // r3
  idRenderModelGui *v3; // r3
  idLBCache *lbCache; // r29
  idSWF *testGui; // r29
  idSWF *mainMenu; // r29
  idLobbyController *lobbyController; // r4
  idMenuScreen **menuScreens; // r29
  int i; // r28
  const idDeclSecretType **list; // r4
  const idDeclChapter **v11; // r4
  mpMap_t *v12; // r27
  int size; // r29
  mpMap_t *v14; // r28
  idMainMenu::coopLeaderboard_t *v15; // r4
  idMainMenu::roadRageLeaderboard_t *v16; // r4
  const struct idDeclRaceDescription **v17; // r4
  idPcDisplayInfo *v18; // r27
  int v19; // r29
  idStr *p_displayString; // r28
  int *v21; // r4
  int *v22; // r4
  const char **v23; // r4
  idSWFScriptFunction *scriptFunction; // r3

  idMainMenu::pMPMaps = nullptr;
  session->CancelListServers(this: session);
  idSignInManagerXbox::SetDeviceSelectorSignal(this: (idSignInManagerXbox *)session->signInManager, signal: nullptr);
  guiModel = this->guiModel;
  if ( guiModel != nullptr )
  {
    guiModel->unlinked = true;
    guiModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: guiModel);
    v3 = this->guiModel;
    if ( v3 != nullptr )
      ((void (__fastcall *)(idRenderModelGui *, int))v3->dtr_idRenderModel)(a1: v3, a2: 1);
    this->guiModel = nullptr;
  }
  lbCache = this->lbCache;
  if ( lbCache != nullptr )
  {
    `eh vector destructor iterator'(
      ptr: lbCache,
      size: 0x18u,
      count: 5,
      pDtor: (void (__fastcall *)(void *))idLBRowBlock::~idLBRowBlock);
    idMem::Free(this: &mem, ptr: lbCache, align: ALIGN_16);
    this->lbCache = nullptr;
  }
  testGui = this->testGui;
  if ( testGui != nullptr )
  {
    idSWF::~idSWF(this: this->testGui);
    idMem::Free(this: &mem, ptr: testGui, align: ALIGN_16);
    this->testGui = nullptr;
  }
  mainMenu = this->mainMenu;
  if ( mainMenu != nullptr )
  {
    idSWF::~idSWF(this: this->mainMenu);
    idMem::Free(this: &mem, ptr: mainMenu, align: ALIGN_16);
    this->mainMenu = nullptr;
  }
  lobbyController = this->lobbyController;
  if ( lobbyController != nullptr )
  {
    idMem::Free(this: &mem, ptr: lobbyController, align: ALIGN_16);
    this->lobbyController = nullptr;
  }
  soundSystem->FreeSoundWorld(this: soundSystem, a2: this->soundWorld);
  menuScreens = this->menuScreens;
  for ( i = 7; i != 0; --i )
  {
    if ( *menuScreens != nullptr )
      ((void (__fastcall *)(idMenuScreen *, int))(*menuScreens)->dtr_idMenuWidget)(a1: *menuScreens, a2: 1);
    ++menuScreens;
  }
  this->scriptFunction_isMpHandsOnDemo.__vftable = (idMainMenu::idSWFScriptFunction_isMpHandsOnDemo_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_hasContentPack.__vftable = (idMainMenu::idSWFScriptFunction_hasContentPack_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_ps3CheckInvites.__vftable = (idMainMenu::idSWFScriptFunction_ps3CheckInvites_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_ps3ShowNotifications.__vftable = (idMainMenu::idSWFScriptFunction_ps3ShowNotifications_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_ps3ShowFriends.__vftable = (idMainMenu::idSWFScriptFunction_ps3ShowFriends_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_showCredits.__vftable = (idMainMenu::idSWFScriptFunction_showCredits_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_isGameInstalled.__vftable = (idMainMenu::idSWFScriptFunction_isGameInstalled_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_showDLCMenu.__vftable = (idMainMenu::idSWFScriptFunction_showDLCMenu_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_hasNewDLC.__vftable = (idMainMenu::idSWFScriptFunction_hasNewDLC_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_showDLCOption.__vftable = (idMainMenu::idSWFScriptFunction_showDLCOption_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_isDemoMode.__vftable = (idMainMenu::idSWFScriptFunction_isDemoMode_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_loadDevMenuOption.__vftable = (idMainMenu::idSWFScriptFunction_loadDevMenuOption_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_checkActivateRenderDemo.__vftable = (idMainMenu::idSWFScriptFunction_checkActivateRenderDemo_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_checkActivatePlaytestLogging.__vftable = (idMainMenu::idSWFScriptFunction_checkActivatePlaytestLogging_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setPlaytestSessionName.__vftable = (idMainMenu::idSWFScriptFunction_setPlaytestSessionName_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_stopPlaytestRenderDemoRecord.__vftable = (idMainMenu::idSWFScriptFunction_stopPlaytestRenderDemoRecord_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_updateLbScroll.__vftable = (idMainMenu::idSWFScriptFunction_updateLbScroll_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_updateScroll.__vftable = (idMainMenu::idSWFScriptFunction_updateScroll_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setScrolling.__vftable = (idMainMenu::idSWFScriptFunction_setScrolling_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_filterList.__vftable = (idMainMenu::idSWFScriptFunction_filterList_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_isCoopNightmareLeaderboard.__vftable = (idMainMenu::idSWFScriptFunction_isCoopNightmareLeaderboard_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_toggleCoopNightmareLeaderboard.__vftable = (idMainMenu::idSWFScriptFunction_toggleCoopNightmareLeaderboard_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_showLeaderboardGamerCardUI.__vftable = (idMainMenu::idSWFScriptFunction_showLeaderboardGamerCardUI_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_selectLeaderboardIndex.__vftable = (idMainMenu::idSWFScriptFunction_selectLeaderboardIndex_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_prevLeaderboard.__vftable = (idMainMenu::idSWFScriptFunction_prevLeaderboard_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_nextLeaderboard.__vftable = (idMainMenu::idSWFScriptFunction_nextLeaderboard_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_scrollLeaderboard.__vftable = (idMainMenu::idSWFScriptFunction_scrollLeaderboard_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_refreshLeaderboard.__vftable = (idMainMenu::idSWFScriptFunction_refreshLeaderboard_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_clearLeaderboard.__vftable = (idMainMenu::idSWFScriptFunction_clearLeaderboard_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_saveSettings.__vftable = (idMainMenu::idSWFScriptFunction_saveSettings_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_loadMenuItems.__vftable = (idMainMenu::idSWFScriptFunction_loadMenuItems_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_hasNewAccolade.__vftable = (idMainMenu::idSWFScriptFunction_hasNewAccolade_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getMissionMapList.__vftable = (idMainMenu::idSWFScriptFunction_getMissionMapList_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_drawPlayerInfo.__vftable = (idMainMenu::idSWFScriptFunction_drawPlayerInfo_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_selectAccolade.__vftable = (idMainMenu::idSWFScriptFunction_selectAccolade_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getAccoladeCount.__vftable = (idMainMenu::idSWFScriptFunction_getAccoladeCount_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getAccoladeInfo.__vftable = (idMainMenu::idSWFScriptFunction_getAccoladeInfo_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getPlayerLevelTitle.__vftable = (idMainMenu::idSWFScriptFunction_getPlayerLevelTitle_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_suicide.__vftable = (idMainMenu::idSWFScriptFunction_suicide_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setAllowBoost.__vftable = (idMainMenu::idSWFScriptFunction_setAllowBoost_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getAllowBoost.__vftable = (idMainMenu::idSWFScriptFunction_getAllowBoost_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setAllowSponsors.__vftable = (idMainMenu::idSWFScriptFunction_setAllowSponsors_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getAllowSponsors.__vftable = (idMainMenu::idSWFScriptFunction_getAllowSponsors_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setAllowQuickUse.__vftable = (idMainMenu::idSWFScriptFunction_setAllowQuickUse_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getAllowQuickUse.__vftable = (idMainMenu::idSWFScriptFunction_getAllowQuickUse_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setAllowPowerups.__vftable = (idMainMenu::idSWFScriptFunction_setAllowPowerups_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getAllowPowerups.__vftable = (idMainMenu::idSWFScriptFunction_getAllowPowerups_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setAllowSpectators.__vftable = (idMainMenu::idSWFScriptFunction_setAllowSpectators_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getAllowSpectators.__vftable = (idMainMenu::idSWFScriptFunction_getAllowSpectators_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setAllowFriendlyFire.__vftable = (idMainMenu::idSWFScriptFunction_setAllowFriendlyFire_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getAllowFriendlyFire.__vftable = (idMainMenu::idSWFScriptFunction_getAllowFriendlyFire_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_shouldPrivacyBeVisible.__vftable = (idMainMenu::idSWFScriptFunction_shouldPrivacyBeVisible_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setCOOPPrivacy.__vftable = (idMainMenu::idSWFScriptFunction_setCOOPPrivacy_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getCOOPPrivacy.__vftable = (idMainMenu::idSWFScriptFunction_getCOOPPrivacy_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setScoreLimit.__vftable = (idMainMenu::idSWFScriptFunction_setScoreLimit_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getScoreLimit.__vftable = (idMainMenu::idSWFScriptFunction_getScoreLimit_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setTimeLimit.__vftable = (idMainMenu::idSWFScriptFunction_setTimeLimit_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getTimeLimit.__vftable = (idMainMenu::idSWFScriptFunction_getTimeLimit_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_loadScrollingControlValues.__vftable = (idMainMenu::idSWFScriptFunction_loadScrollingControlValues_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getSessionCoopDifficulty.__vftable = (idMainMenu::idSWFScriptFunction_getSessionCoopDifficulty_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setCoopDifficulty.__vftable = (idMainMenu::idSWFScriptFunction_setCoopDifficulty_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getCoopDifficulty.__vftable = (idMainMenu::idSWFScriptFunction_getCoopDifficulty_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_hidePauseMenu.__vftable = (idMainMenu::idSWFScriptFunction_hidePauseMenu_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getConfigText.__vftable = (idMainMenu::idSWFScriptFunction_getConfigText_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_changeConfig.__vftable = (idMainMenu::idSWFScriptFunction_changeConfig_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setConfig.__vftable = (idMainMenu::idSWFScriptFunction_setConfig_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getConfig.__vftable = (idMainMenu::idSWFScriptFunction_getConfig_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getMouseSensitivity.__vftable = (idMainMenu::idSWFScriptFunction_getMouseSensitivity_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setMouseSensitivity.__vftable = (idMainMenu::idSWFScriptFunction_setMouseSensitivity_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getUseVibrate.__vftable = (idMainMenu::idSWFScriptFunction_getUseVibrate_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setUseVibrate.__vftable = (idMainMenu::idSWFScriptFunction_setUseVibrate_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setUseAimAssist.__vftable = (idMainMenu::idSWFScriptFunction_setUseAimAssist_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getUseAimAssist.__vftable = (idMainMenu::idSWFScriptFunction_getUseAimAssist_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setGamepadEnabled.__vftable = (idMainMenu::idSWFScriptFunction_setGamepadEnabled_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getGamepadEnabled.__vftable = (idMainMenu::idSWFScriptFunction_getGamepadEnabled_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_confirmRestoreBindings.__vftable = (idMainMenu::idSWFScriptFunction_confirmRestoreBindings_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getBinding.__vftable = (idMainMenu::idSWFScriptFunction_getBinding_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_GetJoyPitchSpeed.__vftable = (idMainMenu::idSWFScriptFunction_GetJoyPitchSpeed_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_updateJoyPitchSpeed.__vftable = (idMainMenu::idSWFScriptFunction_updateJoyPitchSpeed_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_GetJoyYawSpeed.__vftable = (idMainMenu::idSWFScriptFunction_GetJoyYawSpeed_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_updateJoyYawSpeed.__vftable = (idMainMenu::idSWFScriptFunction_updateJoyYawSpeed_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setAudioVolume.__vftable = (idMainMenu::idSWFScriptFunction_setAudioVolume_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getAudioVolume.__vftable = (idMainMenu::idSWFScriptFunction_getAudioVolume_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getBenchmarkValue.__vftable = (idMainMenu::idSWFScriptFunction_getBenchmarkValue_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_calculateBenchmark.__vftable = (idMainMenu::idSWFScriptFunction_calculateBenchmark_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setSubtitlesEnabled.__vftable = (idMainMenu::idSWFScriptFunction_setSubtitlesEnabled_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_subtitlesEnabled.__vftable = (idMainMenu::idSWFScriptFunction_subtitlesEnabled_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setInvertLook.__vftable = (idMainMenu::idSWFScriptFunction_setInvertLook_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getGammaValue.__vftable = (idMainMenu::idSWFScriptFunction_getGammaValue_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_updateGammaValue.__vftable = (idMainMenu::idSWFScriptFunction_updateGammaValue_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_GetSafeFrameScale.__vftable = (idMainMenu::idSWFScriptFunction_GetSafeFrameScale_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_updateSafeFrameScale.__vftable = (idMainMenu::idSWFScriptFunction_updateSafeFrameScale_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_invertLook.__vftable = (idMainMenu::idSWFScriptFunction_invertLook_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_isLookInverted.__vftable = (idMainMenu::idSWFScriptFunction_isLookInverted_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_loadDamagedFile.__vftable = (idMainMenu::idSWFScriptFunction_loadDamagedFile_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_continueFromMostRecentSave.__vftable = (idMainMenu::idSWFScriptFunction_continueFromMostRecentSave_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_continueGame.__vftable = (idMainMenu::idSWFScriptFunction_continueGame_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_isEnumerating.__vftable = (idMainMenu::idSWFScriptFunction_isEnumerating_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setSaveLoadUpdate.__vftable = (idMainMenu::idSWFScriptFunction_setSaveLoadUpdate_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_endDeviceSignal.__vftable = (idMainMenu::idSWFScriptFunction_endDeviceSignal_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_startDeviceSignal.__vftable = (idMainMenu::idSWFScriptFunction_startDeviceSignal_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_canStartNewGame.__vftable = (idMainMenu::idSWFScriptFunction_canStartNewGame_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_canLoadGame.__vftable = (idMainMenu::idSWFScriptFunction_canLoadGame_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_canContinueGame.__vftable = (idMainMenu::idSWFScriptFunction_canContinueGame_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_select360Storage.__vftable = (idMainMenu::idSWFScriptFunction_select360Storage_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_deleteGame.__vftable = (idMainMenu::idSWFScriptFunction_deleteGame_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_LoadGame.__vftable = (idMainMenu::idSWFScriptFunction_LoadGame_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_SaveGame.__vftable = (idMainMenu::idSWFScriptFunction_SaveGame_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_CanSaveGame.__vftable = (idMainMenu::idSWFScriptFunction_CanSaveGame_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_GetSaveGame.__vftable = (idMainMenu::idSWFScriptFunction_GetSaveGame_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_cancelSaveEnumeration.__vftable = (idMainMenu::idSWFScriptFunction_cancelSaveEnumeration_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_restartFromPause.__vftable = (idMainMenu::idSWFScriptFunction_restartFromPause_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_confirmExitGame.__vftable = (idMainMenu::idSWFScriptFunction_confirmExitGame_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_returnToMainMenu.__vftable = (idMainMenu::idSWFScriptFunction_returnToMainMenu_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_restartMap.__vftable = (idMainMenu::idSWFScriptFunction_restartMap_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getDefaultDevMenuOption.__vftable = (idMainMenu::idSWFScriptFunction_getDefaultDevMenuOption_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_loadMap.__vftable = (idMainMenu::idSWFScriptFunction_loadMap_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_closePopup.__vftable = (idMainMenu::idSWFScriptFunction_closePopup_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_showPopupDialog.__vftable = (idMainMenu::idSWFScriptFunction_showPopupDialog_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_showNextUnlockPopup.__vftable = (idMainMenu::idSWFScriptFunction_showNextUnlockPopup_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_showMatchResultsPopup.__vftable = (idMainMenu::idSWFScriptFunction_showMatchResultsPopup_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_isGameModeTeam.__vftable = (idMainMenu::idSWFScriptFunction_isGameModeTeam_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_changeTeam.__vftable = (idMainMenu::idSWFScriptFunction_changeTeam_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_updateModeSelection.__vftable = (idMainMenu::idSWFScriptFunction_updateModeSelection_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getPostGameResults.__vftable = (idMainMenu::idSWFScriptFunction_getPostGameResults_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_forceMenuArea.__vftable = (idMainMenu::idSWFScriptFunction_forceMenuArea_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setMenuArea.__vftable = (idMainMenu::idSWFScriptFunction_setMenuArea_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_loadProfileData.__vftable = (idMainMenu::idSWFScriptFunction_loadProfileData_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_invitePlatformParty.__vftable = (idMainMenu::idSWFScriptFunction_invitePlatformParty_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_isInPlatformParty.__vftable = (idMainMenu::idSWFScriptFunction_isInPlatformParty_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_kickPlayer.__vftable = (idMainMenu::idSWFScriptFunction_kickPlayer_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_showGamerCardUI.__vftable = (idMainMenu::idSWFScriptFunction_showGamerCardUI_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_togglePlayerMute.__vftable = (idMainMenu::idSWFScriptFunction_togglePlayerMute_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_sendChatText.__vftable = (idMainMenu::idSWFScriptFunction_sendChatText_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_isLocalMatch.__vftable = (idMainMenu::idSWFScriptFunction_isLocalMatch_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setLocalMatch.__vftable = (idMainMenu::idSWFScriptFunction_setLocalMatch_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_isPrivateMatch.__vftable = (idMainMenu::idSWFScriptFunction_isPrivateMatch_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setPrivateMatch.__vftable = (idMainMenu::idSWFScriptFunction_setPrivateMatch_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_joinQuickMatch.__vftable = (idMainMenu::idSWFScriptFunction_joinQuickMatch_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setMatchMode.__vftable = (idMainMenu::idSWFScriptFunction_setMatchMode_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getMatchMode.__vftable = (idMainMenu::idSWFScriptFunction_getMatchMode_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getGameModeAvailable.__vftable = (idMainMenu::idSWFScriptFunction_getGameModeAvailable_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getModeList.__vftable = (idMainMenu::idSWFScriptFunction_getModeList_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_updateMapSelection.__vftable = (idMainMenu::idSWFScriptFunction_updateMapSelection_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setMatchMap.__vftable = (idMainMenu::idSWFScriptFunction_setMatchMap_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getMatchMap.__vftable = (idMainMenu::idSWFScriptFunction_getMatchMap_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getGameMapAvailable.__vftable = (idMainMenu::idSWFScriptFunction_getGameMapAvailable_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getMapList.__vftable = (idMainMenu::idSWFScriptFunction_getMapList_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_voteToSkipMap.__vftable = (idMainMenu::idSWFScriptFunction_voteToSkipMap_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_showVoteResults.__vftable = (idMainMenu::idSWFScriptFunction_showVoteResults_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getChapterList.__vftable = (idMainMenu::idSWFScriptFunction_getChapterList_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_isLobbyFull.__vftable = (idMainMenu::idSWFScriptFunction_isLobbyFull_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_updateLanServerList.__vftable = (idMainMenu::idSWFScriptFunction_updateLanServerList_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_isPartyPeer.__vftable = (idMainMenu::idSWFScriptFunction_isPartyPeer_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_isPeer.__vftable = (idMainMenu::idSWFScriptFunction_isPeer_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setMatchType.__vftable = (idMainMenu::idSWFScriptFunction_setMatchType_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getMatchType.__vftable = (idMainMenu::idSWFScriptFunction_getMatchType_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_showPartySessions.__vftable = (idMainMenu::idSWFScriptFunction_showPartySessions_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_inviteFriends.__vftable = (idMainMenu::idSWFScriptFunction_inviteFriends_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_showServerGamerCardUI.__vftable = (idMainMenu::idSWFScriptFunction_showServerGamerCardUI_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_joinMatch.__vftable = (idMainMenu::idSWFScriptFunction_joinMatch_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_cancelMatchCountdown.__vftable = (idMainMenu::idSWFScriptFunction_cancelMatchCountdown_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_cancelMatch.__vftable = (idMainMenu::idSWFScriptFunction_cancelMatch_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_startMatchCountdown.__vftable = (idMainMenu::idSWFScriptFunction_startMatchCountdown_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_startMatch.__vftable = (idMainMenu::idSWFScriptFunction_startMatch_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setScrollSpeed.__vftable = (idMainMenu::idSWFScriptFunction_setScrollSpeed_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_canScroll.__vftable = (idMainMenu::idSWFScriptFunction_canScroll_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setBindingWait.__vftable = (idMainMenu::idSWFScriptFunction_setBindingWait_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_needSpDiscSwap.__vftable = (idMainMenu::idSWFScriptFunction_needSpDiscSwap_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_isInGameLobby.__vftable = (idMainMenu::idSWFScriptFunction_isInGameLobby_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_autoJoinGameLobby.__vftable = (idMainMenu::idSWFScriptFunction_autoJoinGameLobby_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_createGameLobby.__vftable = (idMainMenu::idSWFScriptFunction_createGameLobby_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_createTeamLobby.__vftable = (idMainMenu::idSWFScriptFunction_createTeamLobby_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_isProfileScreenOpen.__vftable = (idMainMenu::idSWFScriptFunction_isProfileScreenOpen_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_needsDiskSwap.__vftable = (idMainMenu::idSWFScriptFunction_needsDiskSwap_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setNewGame.__vftable = (idMainMenu::idSWFScriptFunction_setNewGame_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_closeMenu.__vftable = (idMainMenu::idSWFScriptFunction_closeMenu_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getGameDifficulty.__vftable = (idMainMenu::idSWFScriptFunction_getGameDifficulty_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setNewGameDifficulty.__vftable = (idMainMenu::idSWFScriptFunction_setNewGameDifficulty_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setGameDifficulty.__vftable = (idMainMenu::idSWFScriptFunction_setGameDifficulty_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_moveBetweenSPAndMP.__vftable = (idMainMenu::idSWFScriptFunction_moveBetweenSPAndMP_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_isMpDisc.__vftable = (idMainMenu::idSWFScriptFunction_isMpDisc_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_checkCanPlayOnline.__vftable = (idMainMenu::idSWFScriptFunction_checkCanPlayOnline_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_updateScrolling.__vftable = (idMainMenu::idSWFScriptFunction_updateScrolling_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_clearWaitForCredits.__vftable = (idMainMenu::idSWFScriptFunction_clearWaitForCredits_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_waitForCredits.__vftable = (idMainMenu::idSWFScriptFunction_waitForCredits_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_quitGame.__vftable = (idMainMenu::idSWFScriptFunction_quitGame_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_registerUserMouse.__vftable = (idMainMenu::idSWFScriptFunction_registerUserMouse_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setState.__vftable = (idMainMenu::idSWFScriptFunction_setState_vtbl *)&idSWFScriptFunction::`vftable';
  if ( this->secretTypes.listStatic == 0 || this->secretTypes.listStatic == 2 )
  {
    list = this->secretTypes.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->secretTypes.list = nullptr;
    this->secretTypes.size = 0;
  }
  this->secretTypes.num = 0;
  if ( this->chapters.listStatic == 0 || this->chapters.listStatic == 2 )
  {
    v11 = this->chapters.list;
    if ( v11 != nullptr )
      idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    this->chapters.list = nullptr;
    this->chapters.size = 0;
  }
  this->chapters.num = 0;
  if ( this->mpMaps.listStatic == 0 || this->mpMaps.listStatic == 2 )
  {
    v12 = this->mpMaps.list;
    if ( v12 != nullptr )
    {
      size = this->mpMaps.size;
      if ( size > 0 )
      {
        v14 = this->mpMaps.list;
        do
        {
          mpMap_t::~mpMap_t(this: v14);
          --size;
          ++v14;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
    }
    this->mpMaps.list = nullptr;
    this->mpMaps.size = 0;
  }
  this->mpMaps.num = 0;
  if ( this->coopLeaderboards.listStatic == 0 || this->coopLeaderboards.listStatic == 2 )
  {
    v15 = this->coopLeaderboards.list;
    if ( v15 != nullptr )
      idMem::Free(this: &mem, ptr: v15, align: ALIGN_16);
    this->coopLeaderboards.list = nullptr;
    this->coopLeaderboards.size = 0;
  }
  this->coopLeaderboards.num = 0;
  if ( this->roadRageLeaderboards.listStatic == 0 || this->roadRageLeaderboards.listStatic == 2 )
  {
    v16 = this->roadRageLeaderboards.list;
    if ( v16 != nullptr )
      idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
    this->roadRageLeaderboards.list = nullptr;
    this->roadRageLeaderboards.size = 0;
  }
  this->roadRageLeaderboards.num = 0;
  if ( this->raceDescriptions.listStatic == 0 || this->raceDescriptions.listStatic == 2 )
  {
    v17 = this->raceDescriptions.list;
    if ( v17 != nullptr )
      idMem::Free(this: &mem, ptr: v17, align: ALIGN_16);
    this->raceDescriptions.list = nullptr;
    this->raceDescriptions.size = 0;
  }
  this->raceDescriptions.num = 0;
  idStr::FreeData(this: &this->chatHistory);
  if ( this->displayResolutions.listStatic == 0 || this->displayResolutions.listStatic == 2 )
  {
    v18 = this->displayResolutions.list;
    if ( v18 != nullptr )
    {
      v19 = this->displayResolutions.size;
      if ( v19 > 0 )
      {
        p_displayString = &v18->displayString;
        do
        {
          idStr::FreeData(this: p_displayString);
          --v19;
          p_displayString = (idStr *)((char *)p_displayString + 44);
        }
        while ( v19 != 0 );
      }
      idMem::Free(this: &mem, ptr: v18, align: ALIGN_16);
    }
    this->displayResolutions.list = nullptr;
    this->displayResolutions.size = 0;
  }
  this->displayResolutions.num = 0;
  idStr::FreeData(this: &this->saveAfterDeviceRequestFolder);
  Sys_SignalDestroy(handle: &this->deviceRequestedSignal.handle);
  idStr::FreeData(this: &this->bindAction);
  idStr::FreeData(this: &this->popupCallback);
  if ( this->optionTypes.listStatic == 0 || this->optionTypes.listStatic == 2 )
  {
    v21 = this->optionTypes.list;
    if ( v21 != nullptr )
      idMem::Free(this: &mem, ptr: v21, align: ALIGN_16);
    this->optionTypes.list = nullptr;
    this->optionTypes.size = 0;
  }
  this->optionTypes.num = 0;
  if ( this->devMapListIndexes.listStatic == 0 || this->devMapListIndexes.listStatic == 2 )
  {
    v22 = this->devMapListIndexes.list;
    if ( v22 != nullptr )
      idMem::Free(this: &mem, ptr: v22, align: ALIGN_16);
    this->devMapListIndexes.list = nullptr;
    this->devMapListIndexes.size = 0;
  }
  this->devMapListIndexes.num = 0;
  if ( this->devMapListNames.listStatic == 0 || this->devMapListNames.listStatic == 2 )
  {
    v23 = this->devMapListNames.list;
    if ( v23 != nullptr )
      idMem::Free(this: &mem, ptr: v23, align: ALIGN_16);
    this->devMapListNames.list = nullptr;
    this->devMapListNames.size = 0;
  }
  this->devMapListNames.num = 0;
  idStr::FreeData(this: &this->btn4Text);
  idStr::FreeData(this: &this->btn3Text);
  idStr::FreeData(this: &this->btn2Text);
  idStr::FreeData(this: &this->btn1Text);
  scriptFunction = this->actionRepeater.action.scriptFunction;
  if ( scriptFunction != nullptr )
    ((void (__fastcall *)(idSWFScriptFunction *, int))scriptFunction->dtr_idSWFScriptFunction)(
      a1: scriptFunction,
      a2: 1);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &this->actionRepeater.action.parms.idStaticList<idSWFScriptVar,16>);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &this->actionRepeater.event.parms.idStaticList<idSWFScriptVar,16>);
}


// ========================================================================
// __unwind$544110
// EA  : 0x82DBA3EC
// RVA : 0x00DBA3EC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544110()
{
  int v0; // r12

  idMainMenu::actionRepeater_t::~actionRepeater_t(this: *(idMainMenu::actionRepeater_t **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$544111
// EA  : 0x82DBA414
// RVA : 0x00DBA414
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544111()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 432));
}


// ========================================================================
// __unwind$544112
// EA  : 0x82DBA440
// RVA : 0x00DBA440
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544112()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 464));
}


// ========================================================================
// __unwind$544113
// EA  : 0x82DBA46C
// RVA : 0x00DBA46C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544113()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 496));
}


// ========================================================================
// __unwind$544114
// EA  : 0x82DBA498
// RVA : 0x00DBA498
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544114()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 528));
}


// ========================================================================
// __unwind$544115
// EA  : 0x82DBA4C4
// RVA : 0x00DBA4C4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544115()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 568));
}


// ========================================================================
// __unwind$544116
// EA  : 0x82DBA4F0
// RVA : 0x00DBA4F0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544116()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 584));
}


// ========================================================================
// __unwind$544117
// EA  : 0x82DBA51C
// RVA : 0x00DBA51C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544117()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 600));
}


// ========================================================================
// __unwind$544118
// EA  : 0x82DBA548
// RVA : 0x00DBA548
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544118()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 692));
}


// ========================================================================
// __unwind$544119
// EA  : 0x82DBA574
// RVA : 0x00DBA574
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544119()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 748));
}


// ========================================================================
// __unwind$544120
// EA  : 0x82DBA5A0
// RVA : 0x00DBA5A0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544120()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 160 + 180) + 796));
}


// ========================================================================
// __unwind$544121
// EA  : 0x82DBA5CC
// RVA : 0x00DBA5CC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544121()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 804));
}


// ========================================================================
// __unwind$544122
// EA  : 0x82DBA5F8
// RVA : 0x00DBA5F8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544122()
{
  int v0; // r12

  idList<idSubtitles::idPart,5>::Clear(this: (idSubtitleSequencer *)(*(_DWORD *)(v0 - 160 + 180) + 932));
}


// ========================================================================
// __unwind$544123
// EA  : 0x82DBA624
// RVA : 0x00DBA624
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544123()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 956));
}


// ========================================================================
// __unwind$544124
// EA  : 0x82DBA650
// RVA : 0x00DBA650
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544124()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 3036));
}


// ========================================================================
// __unwind$544125
// EA  : 0x82DBA67C
// RVA : 0x00DBA67C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544125()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 3056));
}


// ========================================================================
// __unwind$544126
// EA  : 0x82DBA6A8
// RVA : 0x00DBA6A8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544126()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 3112));
}


// ========================================================================
// __unwind$544127
// EA  : 0x82DBA6D4
// RVA : 0x00DBA6D4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544127()
{
  int v0; // r12

  idList<mpMap_t,57>::Clear(this: (idList<mpMap_t,57> *)(*(_DWORD *)(v0 - 160 + 180) + 3132));
}


// ========================================================================
// __unwind$544128
// EA  : 0x82DBA700
// RVA : 0x00DBA700
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544128()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 3148));
}


// ========================================================================
// __unwind$544129
// EA  : 0x82DBA72C
// RVA : 0x00DBA72C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544129()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 3164));
}


// ========================================================================
// __unwind$544130
// EA  : 0x82DBA758
// RVA : 0x00DBA758
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544130()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3196));
}


// ========================================================================
// __unwind$544131
// EA  : 0x82DBA784
// RVA : 0x00DBA784
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544131()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3204));
}


// ========================================================================
// __unwind$544132
// EA  : 0x82DBA7B0
// RVA : 0x00DBA7B0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544132()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3212));
}


// ========================================================================
// __unwind$544133
// EA  : 0x82DBA7DC
// RVA : 0x00DBA7DC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544133()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3220));
}


// ========================================================================
// __unwind$544134
// EA  : 0x82DBA808
// RVA : 0x00DBA808
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544134()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3228));
}


// ========================================================================
// __unwind$544135
// EA  : 0x82DBA834
// RVA : 0x00DBA834
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544135()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3236));
}


// ========================================================================
// __unwind$544136
// EA  : 0x82DBA860
// RVA : 0x00DBA860
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544136()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3244));
}


// ========================================================================
// __unwind$544137
// EA  : 0x82DBA88C
// RVA : 0x00DBA88C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544137()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3252));
}


// ========================================================================
// __unwind$544138
// EA  : 0x82DBA8B8
// RVA : 0x00DBA8B8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544138()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3260));
}


// ========================================================================
// __unwind$544139
// EA  : 0x82DBA8E4
// RVA : 0x00DBA8E4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544139()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3268));
}


// ========================================================================
// __unwind$544140
// EA  : 0x82DBA910
// RVA : 0x00DBA910
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544140()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3276));
}


// ========================================================================
// __unwind$544141
// EA  : 0x82DBA93C
// RVA : 0x00DBA93C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544141()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3284));
}


// ========================================================================
// __unwind$544142
// EA  : 0x82DBA968
// RVA : 0x00DBA968
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544142()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3292));
}


// ========================================================================
// __unwind$544143
// EA  : 0x82DBA994
// RVA : 0x00DBA994
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544143()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3300));
}


// ========================================================================
// __unwind$544144
// EA  : 0x82DBA9C0
// RVA : 0x00DBA9C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544144()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3308));
}


// ========================================================================
// __unwind$544145
// EA  : 0x82DBA9EC
// RVA : 0x00DBA9EC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544145()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3316));
}


// ========================================================================
// __unwind$544146
// EA  : 0x82DBAA18
// RVA : 0x00DBAA18
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544146()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3324));
}


// ========================================================================
// __unwind$544147
// EA  : 0x82DBAA44
// RVA : 0x00DBAA44
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544147()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3332));
}


// ========================================================================
// __unwind$544148
// EA  : 0x82DBAA70
// RVA : 0x00DBAA70
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544148()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3340));
}


// ========================================================================
// __unwind$544149
// EA  : 0x82DBAA9C
// RVA : 0x00DBAA9C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544149()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3348));
}


// ========================================================================
// __unwind$544150
// EA  : 0x82DBAAC8
// RVA : 0x00DBAAC8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544150()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3356));
}


// ========================================================================
// __unwind$544151
// EA  : 0x82DBAAF4
// RVA : 0x00DBAAF4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544151()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3364));
}


// ========================================================================
// __unwind$544152
// EA  : 0x82DBAB20
// RVA : 0x00DBAB20
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544152()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3372));
}


// ========================================================================
// __unwind$544153
// EA  : 0x82DBAB4C
// RVA : 0x00DBAB4C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544153()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3380));
}


// ========================================================================
// __unwind$544154
// EA  : 0x82DBAB78
// RVA : 0x00DBAB78
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544154()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3388));
}


// ========================================================================
// __unwind$544155
// EA  : 0x82DBABA4
// RVA : 0x00DBABA4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544155()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3396));
}


// ========================================================================
// __unwind$544156
// EA  : 0x82DBABD0
// RVA : 0x00DBABD0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544156()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3404));
}


// ========================================================================
// __unwind$544157
// EA  : 0x82DBABFC
// RVA : 0x00DBABFC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544157()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3412));
}


// ========================================================================
// __unwind$544158
// EA  : 0x82DBAC28
// RVA : 0x00DBAC28
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544158()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3420));
}


// ========================================================================
// __unwind$544159
// EA  : 0x82DBAC54
// RVA : 0x00DBAC54
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544159()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3428));
}


// ========================================================================
// __unwind$544160
// EA  : 0x82DBAC80
// RVA : 0x00DBAC80
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544160()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3436));
}


// ========================================================================
// __unwind$544161
// EA  : 0x82DBACAC
// RVA : 0x00DBACAC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544161()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3444));
}


// ========================================================================
// __unwind$544162
// EA  : 0x82DBACD8
// RVA : 0x00DBACD8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544162()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3452));
}


// ========================================================================
// __unwind$544163
// EA  : 0x82DBAD04
// RVA : 0x00DBAD04
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544163()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3460));
}


// ========================================================================
// __unwind$544164
// EA  : 0x82DBAD30
// RVA : 0x00DBAD30
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544164()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3468));
}


// ========================================================================
// __unwind$544165
// EA  : 0x82DBAD5C
// RVA : 0x00DBAD5C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544165()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3476));
}


// ========================================================================
// __unwind$544166
// EA  : 0x82DBAD88
// RVA : 0x00DBAD88
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544166()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3484));
}


// ========================================================================
// __unwind$544167
// EA  : 0x82DBADB4
// RVA : 0x00DBADB4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544167()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3492));
}


// ========================================================================
// __unwind$544168
// EA  : 0x82DBADE0
// RVA : 0x00DBADE0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544168()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3500));
}


// ========================================================================
// __unwind$544169
// EA  : 0x82DBAE0C
// RVA : 0x00DBAE0C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544169()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3508));
}


// ========================================================================
// __unwind$544170
// EA  : 0x82DBAE38
// RVA : 0x00DBAE38
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544170()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3516));
}


// ========================================================================
// __unwind$544171_0
// EA  : 0x82DBAE64
// RVA : 0x00DBAE64
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544171_0()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3524));
}


// ========================================================================
// __unwind$544172
// EA  : 0x82DBAE90
// RVA : 0x00DBAE90
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544172()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3532));
}


// ========================================================================
// __unwind$544173
// EA  : 0x82DBAEBC
// RVA : 0x00DBAEBC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544173()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3540));
}


// ========================================================================
// __unwind$544174
// EA  : 0x82DBAEE8
// RVA : 0x00DBAEE8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544174()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3548));
}


// ========================================================================
// __unwind$544175
// EA  : 0x82DBAF14
// RVA : 0x00DBAF14
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544175()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3556));
}


// ========================================================================
// __unwind$544176
// EA  : 0x82DBAF40
// RVA : 0x00DBAF40
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544176()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3564));
}


// ========================================================================
// __unwind$544177
// EA  : 0x82DBAF6C
// RVA : 0x00DBAF6C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544177()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3572));
}


// ========================================================================
// __unwind$544178
// EA  : 0x82DBAF98
// RVA : 0x00DBAF98
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544178()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3580));
}


// ========================================================================
// __unwind$544179
// EA  : 0x82DBAFC4
// RVA : 0x00DBAFC4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544179()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3588));
}


// ========================================================================
// __unwind$544180
// EA  : 0x82DBAFF0
// RVA : 0x00DBAFF0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544180()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3596));
}


// ========================================================================
// __unwind$544181
// EA  : 0x82DBB01C
// RVA : 0x00DBB01C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544181()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3604));
}


// ========================================================================
// __unwind$544182
// EA  : 0x82DBB048
// RVA : 0x00DBB048
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544182()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3612));
}


// ========================================================================
// __unwind$544183
// EA  : 0x82DBB074
// RVA : 0x00DBB074
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544183()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3620));
}


// ========================================================================
// __unwind$544184
// EA  : 0x82DBB0A0
// RVA : 0x00DBB0A0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544184()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3628));
}


// ========================================================================
// __unwind$544185
// EA  : 0x82DBB0CC
// RVA : 0x00DBB0CC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544185()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3636));
}


// ========================================================================
// __unwind$544186
// EA  : 0x82DBB0F8
// RVA : 0x00DBB0F8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544186()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3644));
}


// ========================================================================
// __unwind$544187
// EA  : 0x82DBB124
// RVA : 0x00DBB124
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544187()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3652));
}


// ========================================================================
// __unwind$544188
// EA  : 0x82DBB150
// RVA : 0x00DBB150
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544188()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3660));
}


// ========================================================================
// __unwind$544189
// EA  : 0x82DBB17C
// RVA : 0x00DBB17C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544189()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3668));
}


// ========================================================================
// __unwind$544190
// EA  : 0x82DBB1A8
// RVA : 0x00DBB1A8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544190()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3676));
}


// ========================================================================
// __unwind$544191
// EA  : 0x82DBB1D4
// RVA : 0x00DBB1D4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544191()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3684));
}


// ========================================================================
// __unwind$544192
// EA  : 0x82DBB200
// RVA : 0x00DBB200
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544192()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3692));
}


// ========================================================================
// __unwind$544193
// EA  : 0x82DBB22C
// RVA : 0x00DBB22C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544193()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3700));
}


// ========================================================================
// __unwind$544194
// EA  : 0x82DBB258
// RVA : 0x00DBB258
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544194()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3708));
}


// ========================================================================
// __unwind$544195
// EA  : 0x82DBB284
// RVA : 0x00DBB284
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544195()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3716));
}


// ========================================================================
// __unwind$544196
// EA  : 0x82DBB2B0
// RVA : 0x00DBB2B0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544196()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3724));
}


// ========================================================================
// __unwind$544197
// EA  : 0x82DBB2DC
// RVA : 0x00DBB2DC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544197()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3732));
}


// ========================================================================
// __unwind$544198_0
// EA  : 0x82DBB308
// RVA : 0x00DBB308
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544198_0()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3740));
}


// ========================================================================
// __unwind$544199
// EA  : 0x82DBB334
// RVA : 0x00DBB334
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544199()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3748));
}


// ========================================================================
// __unwind$544200
// EA  : 0x82DBB360
// RVA : 0x00DBB360
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544200()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3756));
}


// ========================================================================
// __unwind$544201
// EA  : 0x82DBB38C
// RVA : 0x00DBB38C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544201()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3764));
}


// ========================================================================
// __unwind$544202
// EA  : 0x82DBB3B8
// RVA : 0x00DBB3B8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544202()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3772));
}


// ========================================================================
// __unwind$544203
// EA  : 0x82DBB3E4
// RVA : 0x00DBB3E4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544203()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3780));
}


// ========================================================================
// __unwind$544204
// EA  : 0x82DBB410
// RVA : 0x00DBB410
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544204()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3788));
}


// ========================================================================
// __unwind$544205_0
// EA  : 0x82DBB43C
// RVA : 0x00DBB43C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544205_0()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3796));
}


// ========================================================================
// __unwind$544206
// EA  : 0x82DBB468
// RVA : 0x00DBB468
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544206()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3804));
}


// ========================================================================
// __unwind$544207
// EA  : 0x82DBB494
// RVA : 0x00DBB494
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544207()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3812));
}


// ========================================================================
// __unwind$544208
// EA  : 0x82DBB4C0
// RVA : 0x00DBB4C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544208()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3820));
}


// ========================================================================
// __unwind$544209
// EA  : 0x82DBB4EC
// RVA : 0x00DBB4EC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544209()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3828));
}


// ========================================================================
// __unwind$544210
// EA  : 0x82DBB518
// RVA : 0x00DBB518
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544210()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3836));
}


// ========================================================================
// __unwind$544211
// EA  : 0x82DBB544
// RVA : 0x00DBB544
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544211()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3844));
}


// ========================================================================
// __unwind$544212
// EA  : 0x82DBB570
// RVA : 0x00DBB570
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544212()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3852));
}


// ========================================================================
// __unwind$544213
// EA  : 0x82DBB59C
// RVA : 0x00DBB59C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544213()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3860));
}


// ========================================================================
// __unwind$544214
// EA  : 0x82DBB5C8
// RVA : 0x00DBB5C8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544214()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3868));
}


// ========================================================================
// __unwind$544215
// EA  : 0x82DBB5F4
// RVA : 0x00DBB5F4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544215()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3876));
}


// ========================================================================
// __unwind$544216
// EA  : 0x82DBB620
// RVA : 0x00DBB620
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544216()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3884));
}


// ========================================================================
// __unwind$544217
// EA  : 0x82DBB64C
// RVA : 0x00DBB64C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544217()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3892));
}


// ========================================================================
// __unwind$544218
// EA  : 0x82DBB678
// RVA : 0x00DBB678
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544218()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3900));
}


// ========================================================================
// __unwind$544219
// EA  : 0x82DBB6A4
// RVA : 0x00DBB6A4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544219()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3908));
}


// ========================================================================
// __unwind$544220
// EA  : 0x82DBB6D0
// RVA : 0x00DBB6D0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544220()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3916));
}


// ========================================================================
// __unwind$544221
// EA  : 0x82DBB6FC
// RVA : 0x00DBB6FC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544221()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3924));
}


// ========================================================================
// __unwind$544222
// EA  : 0x82DBB728
// RVA : 0x00DBB728
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544222()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3932));
}


// ========================================================================
// __unwind$544223
// EA  : 0x82DBB754
// RVA : 0x00DBB754
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544223()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3940));
}


// ========================================================================
// __unwind$544224
// EA  : 0x82DBB780
// RVA : 0x00DBB780
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544224()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3948));
}


// ========================================================================
// __unwind$544225
// EA  : 0x82DBB7AC
// RVA : 0x00DBB7AC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544225()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3956));
}


// ========================================================================
// __unwind$544226
// EA  : 0x82DBB7D8
// RVA : 0x00DBB7D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544226()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3964));
}


// ========================================================================
// __unwind$544227
// EA  : 0x82DBB804
// RVA : 0x00DBB804
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544227()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3972));
}


// ========================================================================
// __unwind$544228
// EA  : 0x82DBB830
// RVA : 0x00DBB830
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544228()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3980));
}


// ========================================================================
// __unwind$544229
// EA  : 0x82DBB85C
// RVA : 0x00DBB85C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544229()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3988));
}


// ========================================================================
// __unwind$544230
// EA  : 0x82DBB888
// RVA : 0x00DBB888
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544230()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 3996));
}


// ========================================================================
// __unwind$544231
// EA  : 0x82DBB8B4
// RVA : 0x00DBB8B4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544231()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4004));
}


// ========================================================================
// __unwind$544232
// EA  : 0x82DBB8E0
// RVA : 0x00DBB8E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544232()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4012));
}


// ========================================================================
// __unwind$544233
// EA  : 0x82DBB90C
// RVA : 0x00DBB90C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544233()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4020));
}


// ========================================================================
// __unwind$544234
// EA  : 0x82DBB938
// RVA : 0x00DBB938
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544234()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4028));
}


// ========================================================================
// __unwind$544235
// EA  : 0x82DBB964
// RVA : 0x00DBB964
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544235()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4036));
}


// ========================================================================
// __unwind$544236
// EA  : 0x82DBB990
// RVA : 0x00DBB990
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544236()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4044));
}


// ========================================================================
// __unwind$544237
// EA  : 0x82DBB9BC
// RVA : 0x00DBB9BC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544237()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4052));
}


// ========================================================================
// __unwind$544238
// EA  : 0x82DBB9E8
// RVA : 0x00DBB9E8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544238()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4060));
}


// ========================================================================
// __unwind$544239
// EA  : 0x82DBBA14
// RVA : 0x00DBBA14
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544239()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4068));
}


// ========================================================================
// __unwind$544240
// EA  : 0x82DBBA40
// RVA : 0x00DBBA40
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544240()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4076));
}


// ========================================================================
// __unwind$544241
// EA  : 0x82DBBA6C
// RVA : 0x00DBBA6C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544241()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4084));
}


// ========================================================================
// __unwind$544242
// EA  : 0x82DBBA98
// RVA : 0x00DBBA98
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544242()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4092));
}


// ========================================================================
// __unwind$544243
// EA  : 0x82DBBAC4
// RVA : 0x00DBBAC4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544243()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4100));
}


// ========================================================================
// __unwind$544244
// EA  : 0x82DBBAF0
// RVA : 0x00DBBAF0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544244()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4108));
}


// ========================================================================
// __unwind$544245
// EA  : 0x82DBBB1C
// RVA : 0x00DBBB1C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544245()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4116));
}


// ========================================================================
// __unwind$544246
// EA  : 0x82DBBB48
// RVA : 0x00DBBB48
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544246()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4124));
}


// ========================================================================
// __unwind$544247
// EA  : 0x82DBBB74
// RVA : 0x00DBBB74
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544247()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4132));
}


// ========================================================================
// __unwind$544248
// EA  : 0x82DBBBA0
// RVA : 0x00DBBBA0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544248()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4140));
}


// ========================================================================
// __unwind$544249
// EA  : 0x82DBBBCC
// RVA : 0x00DBBBCC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544249()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4148));
}


// ========================================================================
// __unwind$544250
// EA  : 0x82DBBBF8
// RVA : 0x00DBBBF8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544250()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4156));
}


// ========================================================================
// __unwind$544251
// EA  : 0x82DBBC24
// RVA : 0x00DBBC24
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544251()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4164));
}


// ========================================================================
// __unwind$544252
// EA  : 0x82DBBC50
// RVA : 0x00DBBC50
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544252()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4172));
}


// ========================================================================
// __unwind$544253
// EA  : 0x82DBBC7C
// RVA : 0x00DBBC7C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544253()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4180));
}


// ========================================================================
// __unwind$544254
// EA  : 0x82DBBCA8
// RVA : 0x00DBBCA8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544254()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4188));
}


// ========================================================================
// __unwind$544255
// EA  : 0x82DBBCD4
// RVA : 0x00DBBCD4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544255()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4196));
}


// ========================================================================
// __unwind$544256
// EA  : 0x82DBBD00
// RVA : 0x00DBBD00
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544256()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4204));
}


// ========================================================================
// __unwind$544257
// EA  : 0x82DBBD2C
// RVA : 0x00DBBD2C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544257()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4212));
}


// ========================================================================
// __unwind$544258
// EA  : 0x82DBBD58
// RVA : 0x00DBBD58
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544258()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4220));
}


// ========================================================================
// __unwind$544259
// EA  : 0x82DBBD84
// RVA : 0x00DBBD84
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544259()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4228));
}


// ========================================================================
// __unwind$544260
// EA  : 0x82DBBDB0
// RVA : 0x00DBBDB0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544260()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4236));
}


// ========================================================================
// __unwind$544261
// EA  : 0x82DBBDDC
// RVA : 0x00DBBDDC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544261()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4244));
}


// ========================================================================
// __unwind$544262
// EA  : 0x82DBBE08
// RVA : 0x00DBBE08
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544262()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4252));
}


// ========================================================================
// __unwind$544263
// EA  : 0x82DBBE34
// RVA : 0x00DBBE34
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544263()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4260));
}


// ========================================================================
// __unwind$544264
// EA  : 0x82DBBE60
// RVA : 0x00DBBE60
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544264()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4268));
}


// ========================================================================
// __unwind$544265
// EA  : 0x82DBBE8C
// RVA : 0x00DBBE8C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544265()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4276));
}


// ========================================================================
// __unwind$544266
// EA  : 0x82DBBEB8
// RVA : 0x00DBBEB8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544266()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4284));
}


// ========================================================================
// __unwind$544267
// EA  : 0x82DBBEE4
// RVA : 0x00DBBEE4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544267()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4292));
}


// ========================================================================
// __unwind$544268
// EA  : 0x82DBBF10
// RVA : 0x00DBBF10
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544268()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4300));
}


// ========================================================================
// __unwind$544269
// EA  : 0x82DBBF3C
// RVA : 0x00DBBF3C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544269()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4308));
}


// ========================================================================
// __unwind$544270
// EA  : 0x82DBBF68
// RVA : 0x00DBBF68
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544270()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4316));
}


// ========================================================================
// __unwind$544271
// EA  : 0x82DBBF94
// RVA : 0x00DBBF94
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544271()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4324));
}


// ========================================================================
// __unwind$544272
// EA  : 0x82DBBFC0
// RVA : 0x00DBBFC0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544272()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4332));
}


// ========================================================================
// __unwind$544273
// EA  : 0x82DBBFEC
// RVA : 0x00DBBFEC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544273()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4340));
}


// ========================================================================
// __unwind$544274
// EA  : 0x82DBC018
// RVA : 0x00DBC018
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544274()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4348));
}


// ========================================================================
// __unwind$544275
// EA  : 0x82DBC044
// RVA : 0x00DBC044
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544275()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4356));
}


// ========================================================================
// __unwind$544276
// EA  : 0x82DBC070
// RVA : 0x00DBC070
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544276()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4364));
}


// ========================================================================
// __unwind$544277
// EA  : 0x82DBC09C
// RVA : 0x00DBC09C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544277()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4372));
}


// ========================================================================
// __unwind$544278_0
// EA  : 0x82DBC0C8
// RVA : 0x00DBC0C8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544278_0()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4380));
}


// ========================================================================
// __unwind$544279
// EA  : 0x82DBC0F4
// RVA : 0x00DBC0F4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544279()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4388));
}


// ========================================================================
// __unwind$544280
// EA  : 0x82DBC120
// RVA : 0x00DBC120
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544280()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4396));
}


// ========================================================================
// __unwind$544281
// EA  : 0x82DBC14C
// RVA : 0x00DBC14C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544281()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4404));
}


// ========================================================================
// __unwind$544282
// EA  : 0x82DBC178
// RVA : 0x00DBC178
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544282()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4412));
}


// ========================================================================
// __unwind$544283
// EA  : 0x82DBC1A4
// RVA : 0x00DBC1A4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544283()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4420));
}


// ========================================================================
// __unwind$544284
// EA  : 0x82DBC1D0
// RVA : 0x00DBC1D0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544284()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4428));
}


// ========================================================================
// __unwind$544285
// EA  : 0x82DBC1FC
// RVA : 0x00DBC1FC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544285()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4436));
}


// ========================================================================
// __unwind$544286
// EA  : 0x82DBC228
// RVA : 0x00DBC228
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544286()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4444));
}


// ========================================================================
// __unwind$544287
// EA  : 0x82DBC254
// RVA : 0x00DBC254
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544287()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4452));
}


// ========================================================================
// __unwind$544288
// EA  : 0x82DBC280
// RVA : 0x00DBC280
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544288()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4460));
}


// ========================================================================
// __unwind$544289
// EA  : 0x82DBC2AC
// RVA : 0x00DBC2AC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544289()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4468));
}


// ========================================================================
// __unwind$544290
// EA  : 0x82DBC2D8
// RVA : 0x00DBC2D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544290()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4476));
}


// ========================================================================
// __unwind$544291
// EA  : 0x82DBC304
// RVA : 0x00DBC304
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544291()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4484));
}


// ========================================================================
// __unwind$544292
// EA  : 0x82DBC330
// RVA : 0x00DBC330
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544292()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4492));
}


// ========================================================================
// __unwind$544293
// EA  : 0x82DBC35C
// RVA : 0x00DBC35C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544293()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4500));
}


// ========================================================================
// __unwind$544294
// EA  : 0x82DBC388
// RVA : 0x00DBC388
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544294()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4508));
}


// ========================================================================
// __unwind$544295
// EA  : 0x82DBC3B4
// RVA : 0x00DBC3B4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544295()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4516));
}


// ========================================================================
// __unwind$544296
// EA  : 0x82DBC3E0
// RVA : 0x00DBC3E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544296()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4524));
}


// ========================================================================
// __unwind$544297
// EA  : 0x82DBC40C
// RVA : 0x00DBC40C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544297()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4532));
}


// ========================================================================
// __unwind$544298
// EA  : 0x82DBC438
// RVA : 0x00DBC438
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544298()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4540));
}


// ========================================================================
// __unwind$544299
// EA  : 0x82DBC464
// RVA : 0x00DBC464
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544299()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4548));
}


// ========================================================================
// __unwind$544300
// EA  : 0x82DBC490
// RVA : 0x00DBC490
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544300()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4556));
}


// ========================================================================
// __unwind$544301
// EA  : 0x82DBC4BC
// RVA : 0x00DBC4BC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544301()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4564));
}


// ========================================================================
// __unwind$544302
// EA  : 0x82DBC4E8
// RVA : 0x00DBC4E8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544302()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4572));
}


// ========================================================================
// __unwind$544303
// EA  : 0x82DBC514
// RVA : 0x00DBC514
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544303()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4580));
}


// ========================================================================
// __unwind$544304_0
// EA  : 0x82DBC540
// RVA : 0x00DBC540
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544304_0()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4588));
}


// ========================================================================
// __unwind$544305_0
// EA  : 0x82DBC56C
// RVA : 0x00DBC56C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544305_0()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4596));
}


// ========================================================================
// __unwind$544306
// EA  : 0x82DBC598
// RVA : 0x00DBC598
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544306()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4604));
}


// ========================================================================
// __unwind$544307
// EA  : 0x82DBC5C4
// RVA : 0x00DBC5C4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544307()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4612));
}


// ========================================================================
// __unwind$544308
// EA  : 0x82DBC5F0
// RVA : 0x00DBC5F0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544308()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4620));
}


// ========================================================================
// __unwind$544309
// EA  : 0x82DBC61C
// RVA : 0x00DBC61C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544309()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4628));
}


// ========================================================================
// __unwind$544310
// EA  : 0x82DBC648
// RVA : 0x00DBC648
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544310()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4636));
}


// ========================================================================
// __unwind$544311
// EA  : 0x82DBC674
// RVA : 0x00DBC674
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544311()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4644));
}


// ========================================================================
// __unwind$544312
// EA  : 0x82DBC6A0
// RVA : 0x00DBC6A0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544312()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4652));
}


// ========================================================================
// __unwind$544313
// EA  : 0x82DBC6CC
// RVA : 0x00DBC6CC
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544313()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4660));
}


// ========================================================================
// __unwind$544314
// EA  : 0x82DBC6F8
// RVA : 0x00DBC6F8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544314()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4668));
}


// ========================================================================
// __unwind$544315
// EA  : 0x82DBC724
// RVA : 0x00DBC724
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544315()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4676));
}


// ========================================================================
// __unwind$544316
// EA  : 0x82DBC750
// RVA : 0x00DBC750
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544316()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4684));
}


// ========================================================================
// __unwind$544317
// EA  : 0x82DBC77C
// RVA : 0x00DBC77C
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544317()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4692));
}


// ========================================================================
// __unwind$544318
// EA  : 0x82DBC7A8
// RVA : 0x00DBC7A8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_544318()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 4700));
}


// ========================================================================
// __unwind$547684
// EA  : 0x82DBC7D4
// RVA : 0x00DBC7D4
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_547684()
{
  int v0; // r12

  idWidgetEvent::~idWidgetEvent(this: (idWidgetEvent *)(*(_DWORD *)(v0 - 160 + 180) + 4));
}


// ========================================================================
// __unwind$547691
// EA  : 0x82DBC800
// RVA : 0x00DBC800
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void _unwind_547691()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(*(_DWORD *)(v0 - 160 + 80) + 4));
}


// ========================================================================
// `dynamic initializer for 'playtest_MenuStartsLogging''
// EA  : 0x83384F68
// RVA : 0x01384F68
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__playtest_MenuStartsLogging__()
{
  idCVar::idCVar(
    this: &playtest_MenuStartsLogging,
    name: "playtest_MenuStartsLogging",
    value: "0",
    flags: 1,
    description: "if true, we're actually going to start logging when the menu tells us...",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__playtest_MenuStartsLogging__);
}


// ========================================================================
// `dynamic initializer for 'playtest_MenuStartsRenderDemo''
// EA  : 0x83384FC0
// RVA : 0x01384FC0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__playtest_MenuStartsRenderDemo__()
{
  idCVar::idCVar(
    this: &playtest_MenuStartsRenderDemo,
    name: "playtest_MenuStartsRenderDemo",
    value: "0",
    flags: 1,
    description: "if true we start renderdemos with the playtest menu... needs playtest_MenuStartsLogging to be true as well",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__playtest_MenuStartsRenderDemo__);
}


// ========================================================================
// `dynamic initializer for 'playtest_RenderDemoCounter''
// EA  : 0x83385018
// RVA : 0x01385018
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__playtest_RenderDemoCounter__()
{
  idCVar::idCVar(
    this: &playtest_RenderDemoCounter,
    name: "playtest_RenderDemoCounter",
    value: "1",
    flags: 2,
    description: "for multi map playtest renderdemos.  used in naming",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__playtest_RenderDemoCounter__);
}


// ========================================================================
// `dynamic initializer for 'swf_waitForCredits''
// EA  : 0x83385070
// RVA : 0x01385070
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_waitForCredits__()
{
  idCVar::idCVar(
    this: &swf_waitForCredits,
    name: "swf_waitForCredits",
    value: "0",
    flags: 1,
    description: "when set to true and returning to main menu we show the credits",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_waitForCredits__);
}


// ========================================================================
// `dynamic initializer for 'swf_deferredDelayMsec''
// EA  : 0x833850C8
// RVA : 0x013850C8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_deferredDelayMsec__()
{
  idCVar::idCVar(
    this: &swf_deferredDelayMsec,
    name: "swf_deferredDelayMsec",
    value: "125",
    flags: 2,
    description: "set to delay the main menu activation to free up purged hud images beforehand",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_deferredDelayMsec__);
}


// ========================================================================
// `dynamic initializer for 'swf_debugDeferredDelay''
// EA  : 0x83385120
// RVA : 0x01385120
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_debugDeferredDelay__()
{
  idCVar::idCVar(
    this: &swf_debugDeferredDelay,
    name: "swf_debugDeferredDelay",
    value: "0",
    flags: 1,
    description: "set to output deferred delay debug info",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_debugDeferredDelay__);
}


// ========================================================================
// `dynamic initializer for 'swf_mp_shell''
// EA  : 0x83385178
// RVA : 0x01385178
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_mp_shell__()
{
  idCVar::idCVar(
    this: &swf_mp_shell,
    name: "swf_mp_shell",
    value: "mpshell",
    flags: 0,
    description: "GUI to load for the multiplayer shell",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_mp_shell__);
}


// ========================================================================
// `dynamic initializer for 'swf_showDLCOption''
// EA  : 0x833851D0
// RVA : 0x013851D0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_showDLCOption__()
{
  idCVar::idCVar(
    this: &swf_showDLCOption,
    name: "swf_showDLCOption",
    value: "1",
    flags: 1,
    description: "If this is set to 1 the DLC menu will show instead of the DEV menu",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_showDLCOption__);
}


// ========================================================================
// `dynamic initializer for 'swf_mpHandsOnMenus''
// EA  : 0x83385228
// RVA : 0x01385228
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_mpHandsOnMenus__()
{
  idCVar::idCVar(
    this: &swf_mpHandsOnMenus,
    name: "swf_mpHandsOnMenus",
    value: "0",
    flags: 1,
    description: "is this a hands on build for mp demos",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_mpHandsOnMenus__);
}


// ========================================================================
// `dynamic initializer for 'savegame_maxSlots''
// EA  : 0x83385280
// RVA : 0x01385280
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__savegame_maxSlots__()
{
  idCVar::idCVar(
    this: &savegame_maxSlots,
    name: "savegame_maxSlots",
    value: "16",
    flags: 2,
    description: "maximum GUI slots available",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__savegame_maxSlots__);
}


// ========================================================================
// `dynamic initializer for 'swf_updateKeyBindings''
// EA  : 0x833852D8
// RVA : 0x013852D8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_updateKeyBindings__()
{
  idCVar::idCVar(
    this: &swf_updateKeyBindings,
    name: "swf_updateKeyBindings",
    value: "0",
    flags: 1,
    description: "used to force an update on the key binding menu",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_updateKeyBindings__);
}


// ========================================================================
// `dynamic initializer for 'swf_showVideoBenchmarkOption''
// EA  : 0x83385330
// RVA : 0x01385330
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_showVideoBenchmarkOption__()
{
  idCVar::idCVar(
    this: &swf_showVideoBenchmarkOption,
    name: "swf_showVideoBenchmarkOption",
    value: "1",
    flags: 1,
    description: "Whether to show the BENCHMARK option in the video settings menu",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_showVideoBenchmarkOption__);
}


// ========================================================================
// `dynamic initializer for 'swf_useDataDrivenMenus''
// EA  : 0x83385388
// RVA : 0x01385388
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_useDataDrivenMenus__()
{
  idCVar::idCVar(
    this: &swf_useDataDrivenMenus,
    name: "swf_useDataDrivenMenus",
    value: "0",
    flags: 1,
    description: "Whether to use the new form of data driven menus. Must /disconnect after changing.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_useDataDrivenMenus__);
}


// ========================================================================
// `dynamic initializer for 'mm_savedDevMenuDecl''
// EA  : 0x833853E0
// RVA : 0x013853E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mm_savedDevMenuDecl__()
{
  idCVar::idCVar(
    this: &mm_savedDevMenuDecl,
    name: "mm_savedDevMenuDecl",
    value: &byte_8200D768,
    flags: 0,
    description: "saved job debug name",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mm_savedDevMenuDecl__);
}


// ========================================================================
// `dynamic initializer for 'mm_savedDevMenuIndex''
// EA  : 0x83385438
// RVA : 0x01385438
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mm_savedDevMenuIndex__()
{
  idCVar::idCVar(
    this: &mm_savedDevMenuIndex,
    name: "mm_savedDevMenuIndex",
    value: "0",
    flags: 2,
    description: "saved debug job state.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mm_savedDevMenuIndex__);
}


// ========================================================================
// `dynamic initializer for 'loadMPMap_v''
// EA  : 0x83385490
// RVA : 0x01385490
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__loadMPMap_v__()
{
  return idCommandLink::idCommandLink(
           this: &loadMPMap_v,
           cmdName: "loadMPMap",
           function: loadMPMap_f,
           description: "loads a map from the console/main menu/cmd line, in MP mode.",
           argCompletion: idCmdSystem::ArgCompletion_MapName);
}


// ========================================================================
// `dynamic initializer for 'loadDevMenuOption_v''
// EA  : 0x833854C0
// RVA : 0x013854C0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__loadDevMenuOption_v__()
{
  return idCommandLink::idCommandLink(
           this: &loadDevMenuOption_v,
           cmdName: "loadDevMenuOption",
           function: loadDevMenuOption_f,
           description: "loads a map from a idDeclDevMenuList and sublist option",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclDevMenuList>);
}


// ========================================================================
// `dynamic initializer for 'UnlockProgressAll_v''
// EA  : 0x833854F0
// RVA : 0x013854F0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__UnlockProgressAll_v__()
{
  return idCommandLink::idCommandLink(
           this: &UnlockProgressAll_v,
           cmdName: "UnlockProgressAll",
           function: UnlockProgressAll_f,
           description: "Unlocks all progress",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'UnlockProgress_v''
// EA  : 0x83385518
// RVA : 0x01385518
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__UnlockProgress_v__()
{
  return idCommandLink::idCommandLink(
           this: &UnlockProgress_v,
           cmdName: "UnlockProgress",
           function: UnlockProgress_f,
           description: "Unlocks progress",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'UnlockSecretAll_v''
// EA  : 0x83385540
// RVA : 0x01385540
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__UnlockSecretAll_v__()
{
  return idCommandLink::idCommandLink(
           this: &UnlockSecretAll_v,
           cmdName: "UnlockSecretAll",
           function: UnlockSecretAll_f,
           description: "Unlocks all secret",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'UnlockSecret_v''
// EA  : 0x83385568
// RVA : 0x01385568
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__UnlockSecret_v__()
{
  return idCommandLink::idCommandLink(
           this: &UnlockSecret_v,
           cmdName: "UnlockSecret",
           function: UnlockSecret_f,
           description: "Unlocks a secret",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ClearSecretAll_v''
// EA  : 0x83385590
// RVA : 0x01385590
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ClearSecretAll_v__()
{
  return idCommandLink::idCommandLink(
           this: &ClearSecretAll_v,
           cmdName: "ClearSecretAll",
           function: ClearSecretAll_f,
           description: "clears all secret",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestPlayerProfile_v''
// EA  : 0x833855B8
// RVA : 0x013855B8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestPlayerProfile_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestPlayerProfile_v,
           cmdName: "TestPlayerProfile",
           function: TestPlayerProfile_f,
           description: "Toggle the main menu",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ToggleMainMenu_v''
// EA  : 0x833855E0
// RVA : 0x013855E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ToggleMainMenu_v__()
{
  return idCommandLink::idCommandLink(
           this: &ToggleMainMenu_v,
           cmdName: "ToggleMainMenu",
           function: ToggleMainMenu_f,
           description: "Toggle the main menu",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'mpMenu_v''
// EA  : 0x83385608
// RVA : 0x01385608
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__mpMenu_v__()
{
  return idCommandLink::idCommandLink(
           this: &mpMenu_v,
           cmdName: "mpMenu",
           function: mpMenu_f,
           description: "Show the multiplayer menu",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'restartMapFromDevMenu_v''
// EA  : 0x83385630
// RVA : 0x01385630
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__restartMapFromDevMenu_v__()
{
  return idCommandLink::idCommandLink(
           this: &restartMapFromDevMenu_v,
           cmdName: "restartMapFromDevMenu",
           function: restartMapFromDevMenu_f,
           description: "re runs whatever command was last used to start a map from the development menu",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestGui_v''
// EA  : 0x83385658
// RVA : 0x01385658
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestGui_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestGui_v,
           cmdName: "TestGui",
           function: TestGui_f,
           description: "For testing GUIs",
           argCompletion: ArgCompletion_SWF);
}


// ========================================================================
// `dynamic initializer for 'LoadGui_v''
// EA  : 0x83385688
// RVA : 0x01385688
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__LoadGui_v__()
{
  return idCommandLink::idCommandLink(
           this: &LoadGui_v,
           cmdName: "LoadGui",
           function: (void (__fastcall *)(const idCmdArgs *))LoadGui_f,
           description: "For loading a gui in MainMenu",
           argCompletion: ArgCompletion_SWF);
}


// ========================================================================
// `dynamic initializer for 'ShowPartySessions_v''
// EA  : 0x833856B8
// RVA : 0x013856B8
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ShowPartySessions_v__()
{
  return idCommandLink::idCommandLink(
           this: &ShowPartySessions_v,
           cmdName: "ShowPartySessions",
           function: ShowPartySessions_f,
           description: "For showing all party sessions",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testDiskSwap_v''
// EA  : 0x833856E0
// RVA : 0x013856E0
// PDB : w:\tech5\tungsten\game\mainmenulocal.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testDiskSwap_v__()
{
  return idCommandLink::idCommandLink(
           this: &testDiskSwap_v,
           cmdName: "testDiskSwap",
           function: testDiskSwap_f,
           description: "testDiskSwap - Testing mainmenu's SP -> MP disk swap",
           argCompletion: nullptr);
}

