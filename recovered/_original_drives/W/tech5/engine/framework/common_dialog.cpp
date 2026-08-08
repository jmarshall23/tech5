
// ========================================================================
// ?ActivateDialog@idCommonLocal@@IAAX_N@Z
// EA  : 0x8264CF98
// RVA : 0x0064CF98
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall idCommonLocal::ActivateDialog(idCommonLocal *this, bool activate)
{
  idSWF *dialog; // r3

  dialog = this->dialog;
  this->dialogInUse = activate;
  if ( dialog != nullptr )
  {
    idSWF::Activate(this: dialog, b: activate);
    if ( !activate && this->dialogWingstickActive )
    {
      this->dialogWingstickActive = false;
      renderSystem->EndAutomaticBackgroundSwaps(this: renderSystem);
    }
  }
}


// ========================================================================
// ?ShowSaveIndicator@idCommonLocal@@UAAX_N0@Z
// EA  : 0x8264D030
// RVA : 0x0064D030
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall idCommonLocal::ShowSaveIndicator(
        idCommonLocal *this,
        bool show,
        bool forceHackUntilCommonDialogNotLinkedToIsActive)
{
  idSWF **p_saveIndicator; // r30
  idSWF *saveIndicator; // r3
  idSWF *v6; // r3

  p_saveIndicator = &this->saveIndicator;
  saveIndicator = this->saveIndicator;
  this->dialogShowingSaveIndicatorRequested = show;
  if ( saveIndicator != nullptr )
  {
    if ( show )
    {
      idSWF::Activate(this: saveIndicator, b: true);
      this->dialogShowingSaveIndicatorTimeRemaining = dialog_saveClearLevel1.valueInteger + Sys_Milliseconds();
    }
    else if ( this->dialogShowingSaveIndicatorTimeRemaining < Sys_Milliseconds() )
    {
      v6 = *p_saveIndicator;
      this->dialogShowingSaveIndicatorTimeRemaining = 0;
      idSWF::Activate(this: v6, b: false);
    }
  }
}


// ========================================================================
// ?RemoveWaitDialogs@idCommonLocal@@IAAXXZ
// EA  : 0x8264D0E8
// RVA : 0x0064D0E8
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall idCommonLocal::RemoveWaitDialogs(idCommonLocal *this)
{
  int *p_num; // r25
  char v3; // r24
  int v4; // r30
  int num; // r11
  idStaticList<idDialogInfo,4> *p_messageList; // r29
  int v7; // r31
  int *v8; // r28
  int v9; // r11
  bool v10; // cr58
  char v11; // r11

  p_num = &this->messageList.num;
  v3 = 0;
  v4 = 0;
  num = this->messageList.num;
  if ( num > 0 )
  {
    p_messageList = &this->messageList;
    while ( 1 )
    {
      v7 = v4;
      v8 = (int *)&p_messageList->list[v4];
      v9 = *v8;
      if ( *v8 > 53 )
        break;
      if ( *v8 != 53 && v9 != 38 )
      {
        v10 = v9 == 45;
        goto LABEL_8;
      }
LABEL_9:
      v11 = 1;
LABEL_10:
      if ( v11 != 0 && Sys_Milliseconds() >= v8[9] && p_messageList->list[v7].waitClear )
      {
        p_messageList->list[v7].clear = true;
        p_messageList->list[v7].waitClear = false;
        if ( v4 == 0 )
          v3 = 1;
      }
      num = *p_num;
      if ( ++v4 >= *p_num )
        goto LABEL_16;
    }
    v10 = v9 == 58;
LABEL_8:
    v11 = 0;
    if ( !v10 )
      goto LABEL_10;
    goto LABEL_9;
  }
LABEL_16:
  if ( v3 != 0 && num > 0 )
    idCommonLocal::ActivateDialog(this, activate: false);
}


// ========================================================================
// ?ClearAllDialogHack@idCommonLocal@@QAAXXZ
// EA  : 0x8264D1F0
// RVA : 0x0064D1F0
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall idCommonLocal::ClearAllDialogHack(idCommonLocal *this)
{
  int v1; // r10
  int v2; // r11
  idStaticList<idDialogInfo,4> *p_messageList; // r9

  v1 = 0;
  if ( this->messageList.num > 0 )
  {
    v2 = 0;
    p_messageList = &this->messageList;
    do
    {
      ++v1;
      p_messageList->list[v2].clear = true;
      p_messageList->list[v2++].waitClear = false;
    }
    while ( v1 < this->messageList.num );
  }
}


// ========================================================================
// ?HasDialogMsg@idCommonLocal@@UAA_NW4gameDialogMessages_t@@PA_N@Z
// EA  : 0x8264D250
// RVA : 0x0064D250
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

int __fastcall idCommonLocal::HasDialogMsg(idCommonLocal *this, gameDialogMessages_t msg, bool *isNowActive)
{
  signed int v3; // r9
  int num; // r7
  int v5; // r11
  idDialogInfo *list; // r8

  v3 = 0;
  num = this->messageList.num;
  if ( num <= 0 )
  {
LABEL_6:
    if ( isNowActive != nullptr )
      *isNowActive = false;
    return 0;
  }
  else
  {
    v5 = 0;
    list = this->messageList.list;
    while ( list[v5].msg != msg || list[v5].clear )
    {
      ++v3;
      ++v5;
      if ( v3 >= num )
        goto LABEL_6;
    }
    if ( isNowActive != nullptr )
      *isNowActive = (_cntlzw(v3) & 0x20) != 0;
    return 1;
  }
}


// ========================================================================
// ?ClearDialog@idCommonLocal@@UAAXW4gameDialogMessages_t@@PBDH@Z
// EA  : 0x8264D2D8
// RVA : 0x0064D2D8
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall idCommonLocal::ClearDialog(
        idCommonLocal *this,
        gameDialogMessages_t msg,
        const char *location,
        int lineNumber)
{
  int *p_num; // r20
  unsigned __int8 v8; // r24
  int v9; // r28
  int num; // r8
  int v11; // r10
  idStaticList<idDialogInfo,4> *p_messageList; // r26
  idDialogInfo *list; // r9
  int v14; // r11
  idDialogInfo *v15; // r27
  bool v16; // cr58
  char v17; // r11
  int v18; // r31
  idDialogInfo *v19; // r30
  int v20; // r3
  idDialogInfo *v21; // r11
  int v22; // r30
  int valueInteger; // r29
  idDialogInfo *v24; // r11
  const char *v25; // r7
  int v26; // [sp+8h] [-C8h]
  int v27; // [sp+Ch] [-C4h]

  p_num = &this->messageList.num;
  v8 = 0;
  v9 = 0;
  num = this->messageList.num;
  if ( num <= 0 )
    goto LABEL_26;
  v11 = 0;
  p_messageList = &this->messageList;
  list = this->messageList.list;
  while ( 1 )
  {
    v14 = list[v11].msg;
    v15 = &list[v11];
    if ( v14 != msg || v15->clear )
      goto LABEL_14;
    if ( v14 > 53 )
    {
      v16 = v14 == 58;
LABEL_10:
      v17 = 0;
      if ( !v16 )
        goto LABEL_12;
      goto LABEL_11;
    }
    if ( v14 != 53 && v14 != 38 )
    {
      v16 = v14 == 45;
      goto LABEL_10;
    }
LABEL_11:
    v17 = 1;
LABEL_12:
    if ( v17 == 0 )
    {
      v18 = v9;
      v24 = &list[v9];
      goto LABEL_20;
    }
    if ( !v15->waitClear )
      break;
LABEL_14:
    ++v9;
    ++v11;
    if ( v9 >= num )
      goto LABEL_26;
  }
  v18 = v9;
  v19 = &list[v9];
  v20 = Sys_Milliseconds();
  v21 = p_messageList->list;
  v22 = v20 - v19->startTime;
  valueInteger = dialog_saveClearLevel2.valueInteger;
  if ( v22 < dialog_saveClearLevel2.valueInteger )
  {
    v21[v18].killTime = Sys_Milliseconds() + valueInteger - v22;
    p_messageList->list[v18].waitClear = true;
    goto LABEL_22;
  }
  v24 = &v21[v18];
LABEL_20:
  v24->clear = true;
  if ( v9 == 0 )
    v8 = 1;
LABEL_22:
  if ( location != nullptr )
    v25 = location;
  else
    v25 = "NULL";
  idLib::PrintfIf(
    condition: popupDialog_debug.valueInteger != 0,
    fmt: "[%s] msg: %s, from: %s:%d, topMessageCleared = %d, m.clear = %d, m.waitClear = %d, m.killTime = %d\n",
    "idCommonLocal::ClearDialog",
    dialogStateToString[v15->msg],
    v25,
    lineNumber,
    v8,
    p_messageList->list[v18].clear,
    v26,
    v27);
LABEL_26:
  if ( v8 != 0 && *p_num > 0 )
    idCommonLocal::ActivateDialog(this, activate: false);
}


// ========================================================================
// ?ReleaseCallBacks@idCommonLocal@@IAAXH@Z
// EA  : 0x8264D4A8
// RVA : 0x0064D4A8
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall idCommonLocal::ReleaseCallBacks(idCommonLocal *this, int index)
{
  int v2; // r31
  idStaticList<idDialogInfo,4> *p_messageList; // r30
  idSWFScriptFunction *acceptCB; // r3
  idSWFScriptFunction *cancelCB; // r3
  idSWFScriptFunction *altCBOne; // r3
  idSWFScriptFunction *altCBTwo; // r3

  if ( index < this->messageList.num )
  {
    v2 = index;
    p_messageList = &this->messageList;
    acceptCB = this->messageList.list[index].acceptCB;
    if ( acceptCB != nullptr )
    {
      acceptCB->Release(this: acceptCB);
      p_messageList->list[v2].acceptCB = nullptr;
    }
    cancelCB = p_messageList->list[v2].cancelCB;
    if ( cancelCB != nullptr )
    {
      cancelCB->Release(this: cancelCB);
      p_messageList->list[v2].cancelCB = nullptr;
    }
    altCBOne = p_messageList->list[v2].altCBOne;
    if ( altCBOne != nullptr )
    {
      altCBOne->Release(this: altCBOne);
      p_messageList->list[v2].altCBOne = nullptr;
    }
    altCBTwo = p_messageList->list[v2].altCBTwo;
    if ( altCBTwo != nullptr )
    {
      altCBTwo->Release(this: altCBTwo);
      p_messageList->list[v2].altCBTwo = nullptr;
    }
  }
}


// ========================================================================
// ?HandleDialogEvent@idCommonLocal@@QAA_NPBUsysEvent_t@@@Z
// EA  : 0x8264D5A0
// RVA : 0x0064D5A0
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

int __fastcall idCommonLocal::HandleDialogEvent(idCommonLocal *this, const sysEvent_t *sev)
{
  idSWF *dialog; // r11

  dialog = this->dialog;
  if ( dialog == nullptr || dialog->frameRate == 0 || !dialog->isActive || this->saveIndicator->isActive )
    return 0;
  if ( idSWF::HandleEvent(this: this->dialog, event: sev) )
  {
    idKeyInput::ClearStates();
    sys->ClearEvents(this: sys);
  }
  return 1;
}


// ========================================================================
// ?IsDialogActive@idCommonLocal@@UAA_NXZ
// EA  : 0x8264D648
// RVA : 0x0064D648
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

BOOL __fastcall idCommonLocal::IsDialogActive(idCommonLocal *this)
{
  idSWF *dialog; // r11

  dialog = this->dialog;
  return dialog != nullptr && dialog->isActive;
}


// ========================================================================
// ?commonDialogClear_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8264D670
// RVA : 0x0064D670
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall commonDialogClear_f(const idCmdArgs *args)
{
  idCommonLocal::ClearAllDialogHack(this: &commonLocal);
}


// ========================================================================
// ?testShowDialog_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8264D680
// RVA : 0x0064D680
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall testShowDialog_f(const idCmdArgs *args)
{
  const char *v1; // r3
  int v2; // r3

  if ( args->argc <= 1 )
    v1 = &byte_8200D768;
  else
    v1 = args->argv[1];
  v2 = atol(nptr: v1);
  ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))common->AddDialog)(
    a1: common,
    a2: v2,
    a3: 0,
    a4: 0,
    a5: 0,
    a6: 0,
    a7: 0,
    a8: 0);
}


// ========================================================================
// ?testShowDialogBug_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8264D700
// RVA : 0x0064D700
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall testShowDialogBug_f(const idCmdArgs *args)
{
  const char *v2; // r3
  int v3; // r3

  common->ShowSaveIndicator(this: common, a2: true, a3: false);
  common->ShowSaveIndicator(this: common, a2: false, a3: false);
  if ( args->argc <= 1 )
    v2 = &byte_8200D768;
  else
    v2 = args->argv[1];
  v3 = atol(nptr: v2);
  ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD))common->AddDialog)(a1: common, a2: v3, a3: 0, a4: 0);
}


// ========================================================================
// ?KillDialog@idCommonLocal@@QAAXXZ
// EA  : 0x8264DAB8
// RVA : 0x0064DAB8
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall idCommonLocal::KillDialog(idCommonLocal *this)
{
  idSWF *dialog; // r30
  idRenderModelGui *dialogGuiModel; // r3
  idSWF *saveIndicator; // r30
  idRenderModelGui **p_saveIndicatorGuiModel; // r31

  idLib::PrintfIf(condition: popupDialog_debug.valueInteger != 0, fmt: "[%s]\n", "idCommonLocal::KillDialog");
  this->ClearDialogs(this, a2: false);
  idRenderManager::ClearAllGuiModels(this: &renderManager);
  dialog = this->dialog;
  if ( dialog != nullptr )
  {
    idSWF::~idSWF(this: this->dialog);
    idMem::Free(this: &mem, ptr: dialog, align: ALIGN_16);
    this->dialog = nullptr;
  }
  dialogGuiModel = this->dialogGuiModel;
  if ( dialogGuiModel != nullptr )
  {
    ((void (__fastcall *)(idRenderModelGui *, int))dialogGuiModel->dtr_idRenderModel)(a1: dialogGuiModel, a2: 1);
    this->dialogGuiModel = nullptr;
  }
  saveIndicator = this->saveIndicator;
  if ( saveIndicator != nullptr )
  {
    idSWF::~idSWF(this: this->saveIndicator);
    idMem::Free(this: &mem, ptr: saveIndicator, align: ALIGN_16);
    this->saveIndicator = nullptr;
  }
  p_saveIndicatorGuiModel = &this->saveIndicatorGuiModel;
  if ( *p_saveIndicatorGuiModel != nullptr )
  {
    ((void (__fastcall *)(idRenderModelGui *, int))(*p_saveIndicatorGuiModel)->dtr_idRenderModel)(
      a1: *p_saveIndicatorGuiModel,
      a2: 1);
    *p_saveIndicatorGuiModel = nullptr;
  }
}


// ========================================================================
// ?GetDialogMsg@idCommonLocal@@QAA?AVidStr@@W4gameDialogMessages_t@@@Z
// EA  : 0x8264DBE8
// RVA : 0x0064DBE8
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

idCommonLocal *__fastcall idCommonLocal::GetDialogMsg(idCommonLocal *this, idStr *result, gameDialogMessages_t msg)
{
  const char *v5; // r4

  this->logFileWriter.__vftable = (idCommonLocal::idLogFileWriter_vtbl *)&this->logFileWriter.wantColor;
  this->logFileWriter.next = (idPrintListener *)20;
  this->__vftable = nullptr;
  this->logFileWriter.wantColor = false;
  idStr::operator=((idStr *)this, text: "#str_dlg_360_");
  switch ( msg )
  {
    case GDM_SWAP_DISKS_TO1:
      idStr::Append((idStr *)this, text: "switch_disc_to_1");
      return this;
    case GDM_SWAP_DISKS_TO2:
      idStr::Append((idStr *)this, text: "switch_disc_to_2");
      return this;
    case GDM_SWAP_DISKS_TO3:
      idStr::Append((idStr *)this, text: "switch_disc_to_3");
      return this;
    case GDM_NO_GAMER_PROFILE:
      idStr::Append((idStr *)this, text: "signin_request");
      return this;
    case GDM_PLAY_ONLINE_NO_PROFILE:
      idStr::Append((idStr *)this, text: "online_signin_request");
      return this;
    case GDM_LEADERBOARD_ONLINE_NO_PROFILE:
      idStr::Append((idStr *)this, text: "online_signing_request_leaderboards");
      return this;
    case GDM_NO_STORAGE_SELECTED:
      idStr::Append((idStr *)this, text: "storage_device_selection_request");
      return this;
    case GDM_ONLINE_INCORRECT_PERMISSIONS:
      idStr::Append((idStr *)this, text: "incorrect_online_permissions");
      return this;
    case GDM_SP_QUIT_SAVE:
      v5 = "#str_dlg_quit_progress_lost";
      goto LABEL_127;
    case GDM_SP_RESTART_SAVE:
      v5 = "#str_dlg_restart_progress_lost";
      goto LABEL_127;
    case GDM_SP_SIGNIN_CHANGE:
      v5 = "#str_dlg_signin_changed";
      goto LABEL_127;
    case GDM_SERVER_NOT_AVAILABLE:
      idStr::Append((idStr *)this, text: "game_server_unavailable");
      return this;
    case GDM_CONNECTION_LOST_HOST:
      v5 = "#str_dlg_opponent_connection_lost_ranking_not_counted";
      goto LABEL_127;
    case GDM_CONNECTION_LOST:
      idStr::Append((idStr *)this, text: "online_connection_lost_main_menu_return");
      return this;
    case GDM_OPPONENT_CONNECTION_LOST:
      v5 = "#str_dlg_opponent_connection_lost";
      goto LABEL_127;
    case GDM_HOST_CONNECTION_LOST:
      v5 = "#str_dlg_host_connection_lost";
      goto LABEL_127;
    case GDM_CONNECTION_TO_HOST_LOST:
      v5 = "#str_dlg_host_connection_lost_ranking_not_counted";
      goto LABEL_127;
    case GDM_FAILED_TO_LOAD_RANKINGS:
      v5 = "#str_dlg_ranking_load_failed";
      goto LABEL_127;
    case GDM_HOST_QUIT:
      v5 = "#str_dlg_host_quit";
      goto LABEL_127;
    case GDM_BECAME_HOST_PARTY:
      v5 = "#str_dlg_became_host_party";
      goto LABEL_127;
    case GDM_NEW_HOST_PARTY:
      v5 = "#str_dlg_new_host_party";
      goto LABEL_127;
    case GDM_LOBBY_BECAME_HOST_GAME:
      v5 = "#str_dlg_lobby_became_host_game";
      goto LABEL_127;
    case GDM_LOBBY_NEW_HOST_GAME:
      idStr::Append((idStr *)this, text: "lobby_new_host_game");
      return this;
    case GDM_NEW_HOST_GAME:
      v5 = "#str_dlg_new_host_game";
      goto LABEL_127;
    case GDM_NEW_HOST_GAME_STATS_DROPPED:
      v5 = "#str_dlg_new_host_game_stats_dropped";
      goto LABEL_127;
    case GDM_BECAME_HOST_GAME:
      idStr::Append((idStr *)this, text: "became_host_game");
      return this;
    case GDM_BECAME_HOST_GAME_STATS_DROPPED:
      v5 = "#str_dlg_became_host_game_stats_dropped";
      goto LABEL_127;
    case GDM_LOBBY_DISBANDED:
      idStr::Append((idStr *)this, text: "lobby_disbanded");
      return this;
    case GDM_LEAVE_WITH_PARTY:
      v5 = "#str_dlg_leave_with_party";
      goto LABEL_127;
    case GDM_LEAVE_LOBBY_RET_MAIN:
      v5 = "#str_dlg_leave_lobby_ret_main";
      goto LABEL_127;
    case GDM_LEAVE_LOBBY_RET_NEW_PARTY:
      idStr::Append((idStr *)this, text: "leave_lobby_ret_new_party");
      return this;
    case GDM_MIGRATING:
      v5 = "#str_online_host_migration";
      goto LABEL_127;
    case GDM_OPPONENT_LEFT:
      v5 = "#str_dlg_opponent_left";
      goto LABEL_127;
    case GDM_NO_MATCHES_FOUND:
      v5 = "#str_dlg_matches_not_found";
      goto LABEL_127;
    case GDM_INVALID_INVITE:
      v5 = "#str_dlg_invalid_game";
      goto LABEL_127;
    case GDM_KICKED:
      v5 = "#str_dlg_kicked";
      goto LABEL_127;
    case GDM_BANNED:
      v5 = "#str_dlg_banned";
      goto LABEL_127;
    case GDM_SAVING:
    case GDM_QUICK_SAVE:
      idStr::Append((idStr *)this, text: "saving");
      return this;
    case GDM_OVERWRITE_SAVE:
      v5 = "#str_dlg_overwrite_save";
      goto LABEL_127;
    case GDM_LOAD_REQUEST:
      idStr::Append((idStr *)this, text: "load_request");
      return this;
    case GDM_AUTOSAVE_DISABLED_STORAGE_REMOVED:
      idStr::Append((idStr *)this, text: "storage_removed_autosave_disabled");
      return this;
    case GDM_STORAGE_INVALID:
      idStr::Append((idStr *)this, text: "storage_not_available");
      return this;
    case GDM_CONNECTING:
      v5 = "#str_dlg_connecting";
      goto LABEL_127;
    case GDM_REFRESHING:
      v5 = "#str_dlg_refreshing";
      goto LABEL_127;
    case GDM_DELETE_SAVE:
      idStr::Append((idStr *)this, text: "delete_save");
      return this;
    case GDM_DELETING:
      idStr::Append((idStr *)this, text: "deleting");
      return this;
    case GDM_BINDING_ALREDY_SET:
      idStr::Append((idStr *)this, text: "bind_exists");
      return this;
    case GDM_CANNOT_BIND:
      idStr::Append((idStr *)this, text: "cannont_bind");
      return this;
    case GDM_OVERLAY_DISABLED:
      idStr::Append((idStr *)this, text: "overlay_disabled");
      return this;
    case GDM_DIRECT_MAP_CHANGE:
      v5 = "#str_dlg_direct_map_change";
      goto LABEL_127;
    case GDM_DELETE_AUTOSAVE:
      idStr::Append((idStr *)this, text: "delete_autosave");
      return this;
    case GDM_MULTI_RETRY:
      v5 = "#str_online_confirm_retry";
      goto LABEL_127;
    case GDM_MULTI_SELF_DESTRUCT:
      v5 = "#str_online_confirm_suicide";
      goto LABEL_127;
    case GDM_MULTI_VDM_QUIT:
      v5 = "#str_online_confirm_quit_generic";
      goto LABEL_127;
    case GDM_MULTI_COOP_QUIT:
      v5 = "#str_online_confirm_coop_quit_game_generic";
      goto LABEL_127;
    case GDM_LOADING_PROFILE:
      v5 = "#str_dlg_loading_profile";
      goto LABEL_127;
    case GDM_STORAGE_REQUIRED:
      idStr::Append((idStr *)this, text: "storage_required");
      return this;
    case GDM_INSUFFICENT_STORAGE_SPACE:
      v5 = "#str_dlg_insufficient_space";
      goto LABEL_127;
    case GDM_PARTNER_LEFT:
      v5 = "#str_dlg_partner_left";
      goto LABEL_127;
    case GDM_RESTORE_CORRUPT_SAVEGAME:
      v5 = "#str_dlg_restore_corrupt_savegame";
      goto LABEL_127;
    case GDM_UNRECOVERABLE_SAVEGAME:
      v5 = "#str_dlg_unrecoverable_savegame";
      goto LABEL_127;
    case GDM_PROFILE_SAVE_ERROR:
      idStr::Append((idStr *)this, text: "profile_save_error");
      return this;
    case GDM_LOBBY_FULL:
      v5 = "#str_dlg_lobby_full";
      goto LABEL_127;
    case GDM_QUIT_GAME:
      v5 = "#str_dlg_confirm_quit";
      goto LABEL_127;
    case GDM_CONNECTION_PROBLEMS:
      v5 = "#str_online_connection_problems";
      goto LABEL_127;
    case GDM_VOICE_RESTRICTED:
      idStr::Append((idStr *)this, text: "voice_restricted");
      return this;
    case GDM_LOAD_DAMAGED_FILE:
      v5 = "#str_dlg_corrupt_save_file";
      goto LABEL_127;
    case GDM_MUST_SIGNIN:
      idStr::Append((idStr *)this, text: "must_signin");
      return this;
    case GDM_CONNECTION_LOST_NO_LEADERBOARD:
      idStr::Append((idStr *)this, text: "online_connection_lost_no_leaderboard");
      return this;
    case GDM_SP_SIGNIN_CHANGE_POST:
      idStr::Append((idStr *)this, text: "signin_changed_post");
      return this;
    case GDM_MIGRATING_WAITING:
      v5 = "#str_online_host_migration_waiting";
      goto LABEL_127;
    case GDM_MIGRATING_RELAUNCHING:
      v5 = "#str_online_host_migration_relaunching";
      goto LABEL_127;
    case GDM_MIGRATING_FAILED_CONNECTION:
      v5 = "#str_online_host_migration_failed";
      goto LABEL_127;
    case GDM_MIGRATING_FAILED_CONNECTION_STATS:
      v5 = "#str_online_host_migration_failed_stats";
      goto LABEL_127;
    case GDM_MIGRATING_FAILED_DISBANDED:
      v5 = "#str_online_host_migration_failed_disbanded";
      goto LABEL_127;
    case GDM_MIGRATING_FAILED_DISBANDED_STATS:
      v5 = "#str_online_host_migration_failed_disbanded_stats";
      goto LABEL_127;
    case GDM_MIGRATING_FAILED_PARTNER_LEFT:
      v5 = "#str_online_host_migration_failed_partner_left";
      goto LABEL_127;
    case GDM_HOST_RETURNED_TO_LOBBY:
      idStr::Append((idStr *)this, text: "host_quit_to_lobby");
      return this;
    case GDM_HOST_RETURNED_TO_LOBBY_STATS_DROPPED:
      idStr::Append((idStr *)this, text: "host_quit_to_lobby_stats_dropped");
      return this;
    case GDM_FAILED_JOIN_LOCAL_SESSION:
      v5 = "#str_dlg_failed_join_local_session";
      goto LABEL_127;
    case GDM_DELETE_CORRUPT_SAVEGAME:
      v5 = "#str_dlg_delete_corrupt_savegame";
      goto LABEL_127;
    case GDM_LEAVE_INCOMPLETE_INSTANCE:
      v5 = "#str_dlg_leave_incomplete_instance";
      goto LABEL_127;
    case GDM_UNBIND_CONFIRM:
      v5 = "#str_dlg_bind_unbind";
      goto LABEL_127;
    case GDM_BINDINGS_RESTORE:
      v5 = "#str_dlg_bind_restore";
      goto LABEL_127;
    case GDM_NEW_HOST:
      idStr::Append((idStr *)this, text: "new_host");
      return this;
    case GDM_CONFIRM_VIDEO_CHANGES:
      v5 = "#str_dlg_confirm_display_changes";
      goto LABEL_127;
    case GDM_UNABLE_TO_USE_SELECTED_STORAGE_DEVICE:
      idStr::Append((idStr *)this, text: "unable_to_use_selected_storage_device");
      return this;
    case GDM_ERROR_LOADING_SAVEGAME:
      v5 = "#str_dlg_error_loading_savegame";
      goto LABEL_127;
    case GDM_ERROR_SAVING_SAVEGAME:
      v5 = "#str_dlg_error_saving_savegame";
      goto LABEL_127;
    case GDM_DISCARD_CHANGES:
      v5 = "#str_dlg_confirm_discard";
      goto LABEL_127;
    case GDM_LEAVE_LOBBY:
      v5 = "#str_online_leave_game_lobby_alt_02";
      goto LABEL_127;
    case GDM_LEAVE_LOBBY_AND_TEAM:
      v5 = "#str_online_party_leave_game";
      goto LABEL_127;
    case GDM_CONTROLLER_DISCONNECTED_0:
    case GDM_CONTROLLER_DISCONNECTED_1:
    case GDM_CONTROLLER_DISCONNECTED_2:
    case GDM_CONTROLLER_DISCONNECTED_3:
    case GDM_CONTROLLER_DISCONNECTED_4:
    case GDM_CONTROLLER_DISCONNECTED_5:
    case GDM_CONTROLLER_DISCONNECTED_6:
      v5 = "#str_dlg_reconnect_controller";
      goto LABEL_127;
    case GDM_DLC_ERROR_REMOVED:
      idStr::Append((idStr *)this, text: "dlc_error_content_removed");
      return this;
    case GDM_DLC_ERROR_CORRUPT:
      idStr::Append((idStr *)this, text: "dlc_error_content_corrupt");
      return this;
    case GDM_DLC_ERROR_MISSING:
      idStr::Append((idStr *)this, text: "dlc_error_content_missing");
      return this;
    case GDM_DLC_ERROR_MISSING_GENERIC:
      idStr::Append((idStr *)this, text: "dlc_error_content_missing_generic");
      return this;
    case GDM_DISC_SWAP:
      v5 = "#str_dlg_disc_swap";
      goto LABEL_127;
    case GDM_NEEDS_INSTALL:
      v5 = "#str_dlg_game_install_message";
      goto LABEL_127;
    case GDM_NO_SAVEGAMES_AVAILABLE:
      v5 = "#str_dlg_no_savegames_available";
      goto LABEL_127;
    case GDM_ERROR_JOIN_TWO_PROFILES_ONE_BOX:
      idStr::Append((idStr *)this, text: "online_join_error_two_profiles_one_box");
      return this;
    case GDM_WARNING_PLAYING_COOP_SOLO:
      v5 = "#str_online_lotw_solo_warning_alt_05";
      goto LABEL_127;
    case GDM_MULTI_COOP_QUIT_LOSE_LEADERBOARDS:
      v5 = "#str_online_confirm_coop_quit_game";
      goto LABEL_127;
    case GDM_CORRUPT_CONTINUE:
      v5 = "#str_online_360_cert_corrupt_save_load";
      goto LABEL_127;
    case GDM_MULTI_VDM_QUIT_LOSE_LEADERBOARDS:
      v5 = "#str_online_confirm_quit_game";
      goto LABEL_127;
    case GDM_WARNING_PLAYING_VDM_SOLO:
      v5 = "#str_online_cr_custom_game_no_stats";
      goto LABEL_127;
    case GDM_NO_GUEST_SUPPORT:
      v5 = "#str_dlg_ps3_incorrect_online_permissions";
      goto LABEL_127;
    case GDM_DISC_SWAP_CONFIRMATION:
      v5 = "#str_dlg_disc_swap_confirmation";
      goto LABEL_127;
    case GDM_ERROR_LOADING_PROFILE:
      idStr::Append((idStr *)this, text: "error_loading_profile");
      return this;
    case GDM_CANNOT_INVITE_LOBBY_FULL:
      v5 = "#str_online_join_error_full";
      goto LABEL_127;
    case GDM_WARNING_FOR_NEW_DEVICE_ABOUT_TO_LOSE_PROGRESS:
      v5 = "#str_dlg_360_new_device_selected";
      goto LABEL_127;
    case GDM_DISCONNECTED:
      v5 = "#str_online_connection_error_03";
      goto LABEL_127;
    case GDM_INCOMPATIBLE_NEWER_SAVE:
      v5 = "#str_dlg_newer_incompatible_savegame";
      goto LABEL_127;
    case GDM_ACHIEVEMENTS_DISABLED_DUE_TO_CHEATING:
      v5 = "#str_dlg_achievements_disabled_due_to_cheating";
      goto LABEL_127;
    case GDM_INCOMPATIBLE_POINTER_SIZE:
      v5 = "#str_dlg_pointer_size_mismatch";
      goto LABEL_127;
    case GDM_TEXTUREDETAIL_RESTARTREQUIRED:
      v5 = "#str_swf_texture_restart";
      goto LABEL_127;
    case GDM_TEXTUREDETAIL_INSUFFICIENT_CPU:
      v5 = "#str_swf_insufficient_cores";
      goto LABEL_127;
    case GDM_CALCULATING_BENCHMARK:
      v5 = "#str_swf_calc_benchmark";
      goto LABEL_127;
    case GDM_DISPLAY_BENCHMARK:
      v5 = "BENCHMARK SCORE = ";
      goto LABEL_127;
    case GDM_DISPLAY_CHANGE_FAILED:
      v5 = "#str_swf_display_changes_failed";
      goto LABEL_127;
    case GDM_GPU_TRANSCODE_FAILED:
      v5 = "#str_swf_gpu_transcode_failed";
      goto LABEL_127;
    case GDM_OUT_OF_MEMORY:
      v5 = "#str_swf_failed_level_load";
      goto LABEL_127;
    case GDM_CORRUPT_PROFILE:
      v5 = "#str_dlg_corrupt_profile";
      goto LABEL_127;
    case GDM_PROFILE_TOO_OUT_OF_DATE_DEVELOPMENT_ONLY:
      v5 = "#str_dlg_profile_too_out_of_date_development_only";
      goto LABEL_127;
    default:
      v5 = "MESSAGE TYPE NOT DEFINED";
LABEL_127:
      idStr::operator=((idStr *)this, text: v5);
      return this;
  }
}


// ========================================================================
// __unwind$224410
// EA  : 0x8264E59C
// RVA : 0x0064E59C
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_224410()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 128;
  if ( (*(_DWORD *)(v0 - 128 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 148));
  }
}


// ========================================================================
// ?ClearDialogs@idCommonLocal@@UAAX_N@Z
// EA  : 0x8264E8D8
// RVA : 0x0064E8D8
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall idCommonLocal::ClearDialogs(idCommonLocal *this, bool forceClear)
{
  int *p_num; // r28
  char v5; // r27
  int v6; // r31
  idStaticList<idDialogInfo,4> *p_messageList; // r30

  p_num = &this->messageList.num;
  v5 = 0;
  v6 = 0;
  if ( this->messageList.num > 0 )
  {
    p_messageList = &this->messageList;
    do
    {
      if ( !p_messageList->list[v6].leaveOnClear || forceClear )
      {
        idCommonLocal::ReleaseCallBacks(this, index: v6);
        idList<idDialogInfo,5>::RemoveIndex(this: p_messageList, index: v6);
        if ( v6 == 0 )
          v5 = 1;
        --v6;
      }
      ++v6;
    }
    while ( v6 < *p_num );
  }
  if ( v5 != 0 )
    idCommonLocal::ActivateDialog(this, activate: false);
}


// ========================================================================
// `testShowDynamicDialog_f'::`2'::idSWFScriptFunction_Continue::Call
// EA  : 0x8264ECC8
// RVA : 0x0064ECC8
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

idSWFScriptVar *__fastcall _testShowDynamicDialog_f_::_2_::idSWFScriptFunction_Continue::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  common->ClearDialog(this: common, a2: GDM_INSUFFICENT_STORAGE_SPACE, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?AddDialogIntVal@idCommonLocal@@UAAXPBDH@Z
// EA  : 0x8264EEE0
// RVA : 0x0064EEE0
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall idCommonLocal::AddDialogIntVal(
        idCommonLocal *this,
        const char *name,
        idSWFScriptVar::swfScriptVarValue_t val)
{
  idSWF **p_dialog; // r30
  idSWFScriptVar v6[6]; // [sp+50h] [-30h] BYREF

  p_dialog = &this->dialog;
  if ( this->dialog != nullptr )
  {
    v6[0].type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: v6);
    v6[0].value = val;
    v6[0].type = SWF_VAR_INTEGER;
    idSWFScriptObject::Set(this: (*p_dialog)->globals, name, value: v6);
    idSWFScriptVar::Free(this: v6);
  }
}


// ========================================================================
// __unwind$225191
// EA  : 0x8264EF4C
// RVA : 0x0064EF4C
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225191()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 128 + 80));
}


// ========================================================================
// ?ShowDialog@idCommonLocal@@IAAXABVidDialogInfo@@_N@Z
// EA  : 0x8264EF80
// RVA : 0x0064EF80
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall idCommonLocal::ShowDialog(idCommonLocal *this, const idDialogInfo *info, bool waitOnAtlas)
{
  gameDialogMessages_t msg; // r11
  bool v7; // cr58
  char v8; // r11
  idSWF **p_dialog; // r30
  idSWFScriptVar *v10; // r3
  dialogType_t type; // r25
  idSWFScriptFunction *acceptCB; // r4
  dialogType_t v13; // r11
  idSWFScriptFunction *v14; // r3
  gameDialogMessages_t v15; // r11
  idSWFScriptFunction *v16; // r4
  idSWFScriptVar *v17; // r3
  int index; // r25
  int v19; // r25
  int v20; // r25
  int v21; // r26
  dialogType_t v22; // r11
  unsigned __int64 v23; // r6
  idRenderModelGui **p_dialogGuiModel; // r29
  int v25; // r26
  int v26; // r3
  __int64 v27; // r4
  double v28; // fp31
  int v29; // r27
  double v30; // fp1
  idRenderModelGui *v31; // r3
  idSWFScriptVar v32; // [sp+50h] [-100h] BYREF
  idSWFScriptVar v33; // [sp+58h] [-F8h] BYREF
  idSWFScriptVar v34; // [sp+60h] [-F0h] BYREF
  idSWFScriptVar v35; // [sp+68h] [-E8h] BYREF
  idSWFScriptVar v36; // [sp+70h] [-E0h] BYREF
  idSWFScriptVar v37; // [sp+78h] [-D8h] BYREF
  idSWFScriptVar v38; // [sp+80h] [-D0h] BYREF
  __int64 v39; // [sp+88h] [-C8h]
  idSWFScriptVar v40; // [sp+90h] [-C0h] BYREF
  idSWFScriptVar v41; // [sp+98h] [-B8h] BYREF
  idSWFScriptVar v42; // [sp+A0h] [-B0h] BYREF
  idSWFScriptVar v43; // [sp+A8h] [-A8h] BYREF
  idSWFScriptVar v44[2]; // [sp+B0h] [-A0h] BYREF
  idStr v45; // [sp+C0h] [-90h] BYREF

  idLib::PrintfIf(
    condition: popupDialog_debug.valueInteger != 0,
    fmt: "[%s] msg: %s, m.clear = %d, m.waitClear = %d, m.killTime = %d\n",
    "idCommonLocal::ShowDialog",
    dialogStateToString[info->msg],
    info->clear,
    info->waitClear,
    info->killTime);
  msg = info->msg;
  if ( info->msg > GDM_QUICK_SAVE )
  {
    v7 = msg == GDM_LOADING_PROFILE;
  }
  else
  {
    if ( info->msg == GDM_QUICK_SAVE || msg == GDM_SAVING )
      goto LABEL_7;
    v7 = msg == GDM_REFRESHING;
  }
  v8 = 0;
  if ( v7 )
LABEL_7:
    v8 = 1;
  if ( v8 != 0 && !this->dialogInUse )
  {
    this->startSaveTime = Sys_Milliseconds();
    this->stopSaveTime = 0;
  }
  if ( this->IsDialogActive(this) )
  {
    idSWF::Activate(this: this->dialog, b: false);
    if ( this->dialogWingstickActive )
    {
      this->dialogWingstickActive = false;
      renderSystem->EndAutomaticBackgroundSwaps(this: renderSystem);
    }
  }
  idCommonLocal::GetDialogMsg(this: (idCommonLocal *)&v45, result: (idStr *)this, msg: info->msg);
  if ( info->overrideMsg.len != 0 )
  {
    v35.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v35);
    v35.type = SWF_VAR_STRING;
    v35.value.i = (int)idSWFScriptString::Alloc(s: &info->overrideMsg);
    p_dialog = &this->dialog;
    idSWFScriptObject::Set(this: this->dialog->globals, name: "messageInfo", value: &v35);
    v10 = &v35;
  }
  else
  {
    v38.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v38);
    v38.type = SWF_VAR_STRING;
    v38.value.i = (int)idSWFScriptString::Alloc(s: &v45);
    p_dialog = &this->dialog;
    idSWFScriptObject::Set(this: this->dialog->globals, name: "messageInfo", value: &v38);
    v10 = &v38;
  }
  idSWFScriptVar::Free(this: v10);
  v34.type = SWF_VAR_UNDEF;
  type = info->type;
  idSWFScriptVar::Free(this: &v34);
  v34.value.i = type;
  v34.type = SWF_VAR_INTEGER;
  idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "Infotype", value: &v34);
  idSWFScriptVar::Free(this: &v34);
  acceptCB = info->acceptCB;
  if ( acceptCB != nullptr || (v13 = info->type) == DIALOG_WAIT || v13 == DIALOG_WAIT_BLACKOUT )
  {
    idSWFScriptVar::idSWFScriptVar(this: &v43, nf: acceptCB);
    idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "acceptCallBack", value: &v43);
    v17 = &v43;
  }
  else
  {
    v14 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0xCu,
                                   tag: TAG_SWF,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
    if ( v14 != nullptr )
    {
      v15 = info->msg;
      v14[1].__vftable = nullptr;
      v16 = v14;
      v14->__vftable = (idSWFScriptFunction_vtbl *)&`idCommonLocal::ShowDialog'::`19'::idSWFScriptFunction_Accept::`vftable';
      v14[2].__vftable = (idSWFScriptFunction_vtbl *)v15;
    }
    else
    {
      v16 = nullptr;
    }
    idSWFScriptVar::idSWFScriptVar(this: &v40, nf: v16);
    idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "acceptCallBack", value: &v40);
    v17 = &v40;
  }
  idSWFScriptVar::Free(this: v17);
  idSWFScriptVar::idSWFScriptVar(this: &v42, nf: info->cancelCB);
  idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "cancelCallBack", value: &v42);
  idSWFScriptVar::Free(this: &v42);
  idSWFScriptVar::idSWFScriptVar(this: v44, nf: info->altCBOne);
  idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "altCBOne", value: v44);
  idSWFScriptVar::Free(this: v44);
  idSWFScriptVar::idSWFScriptVar(this: &v41, nf: info->altCBTwo);
  idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "altCBTwo", value: &v41);
  idSWFScriptVar::Free(this: &v41);
  v37.type = SWF_VAR_UNDEF;
  index = info->txt1.index;
  idSWFScriptVar::Free(this: &v37);
  v37.value.i = index;
  v37.type = SWF_VAR_STRINGID;
  idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "opt1Txt", value: &v37);
  idSWFScriptVar::Free(this: &v37);
  v33.type = SWF_VAR_UNDEF;
  v19 = info->txt2.index;
  idSWFScriptVar::Free(this: &v33);
  v33.value.i = v19;
  v33.type = SWF_VAR_STRINGID;
  idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "opt2Txt", value: &v33);
  idSWFScriptVar::Free(this: &v33);
  v36.type = SWF_VAR_UNDEF;
  v20 = info->txt3.index;
  idSWFScriptVar::Free(this: &v36);
  v36.value.i = v20;
  v36.type = SWF_VAR_STRINGID;
  idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "opt3Txt", value: &v36);
  idSWFScriptVar::Free(this: &v36);
  v32.type = SWF_VAR_UNDEF;
  v21 = info->txt4.index;
  idSWFScriptVar::Free(this: &v32);
  v32.value.i = v21;
  v32.type = SWF_VAR_STRINGID;
  idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "opt4Txt", value: &v32);
  idSWFScriptVar::Free(this: &v32);
  if ( info->msg >= GDM_SWAP_DISKS_TO1 && info->msg <= GDM_SWAP_DISKS_TO3 )
    this->preventOverlayPurge = true;
  v22 = info->type;
  if ( v22 == DIALOG_QUICK_SAVE || v22 == DIALOG_CRAWL_SAVE || info->msg == GDM_CALCULATING_BENCHMARK )
  {
    idSWF::LoadAtlasImage(this: *p_dialog, force: true);
    idCommonLocal::ActivateDialog(this, activate: true);
    p_dialogGuiModel = &this->dialogGuiModel;
    if ( this->dialogGuiModel != nullptr )
    {
      idRenderModelGui::Clear(this: (idRenderModelGui *)HIDWORD(defaultExtraGLState), bits: v23);
      v25 = renderSystem->GetHeight(this: renderSystem);
      v26 = renderSystem->GetWidth(this: renderSystem);
      idRenderModelGui::SetViewport(this: *p_dialogGuiModel, x: 0, y: 0, width: v26, height: v25);
      HIDWORD(v27) = renderSystem->GetWidth(this: renderSystem);
      LODWORD(v27) = HIDWORD(v27);
      v39 = v27;
      v28 = (float)v27;
      v29 = renderSystem->GetHeight(this: renderSystem);
      v30 = ((double (__fastcall *)(idRenderSystem *))renderSystem->GetPixelAspect)(a1: renderSystem);
      v31 = *p_dialogGuiModel;
      LODWORD(v39) = (int)(float)((float)v30 * (float)v28);
      idRenderModelGui::SetVirtualSize(this: v31, width: v39, height: v29);
      idSWF::Render(this: *p_dialog, gui: *p_dialogGuiModel, time: 0, isSplitscreen: false);
      idRenderManager::BuildGuiFrame(this: &renderManager, baseGui: *p_dialogGuiModel, loading: false);
      idRenderManager::RenderFrameAndBeginAutomaticBackgroundSwaps(this: &renderManager);
      this->dialogWingstickActive = true;
    }
  }
  else
  {
    if ( waitOnAtlas )
      idSWF::LoadAtlasImage(this: *p_dialog, force: true);
    idCommonLocal::ActivateDialog(this, activate: true);
  }
  idStr::FreeData(this: &v45);
}


// ========================================================================
// __unwind$225250
// EA  : 0x8264F574
// RVA : 0x0064F574
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225250()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 192));
}


// ========================================================================
// __unwind$225251
// EA  : 0x8264F59C
// RVA : 0x0064F59C
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225251()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 336 + 128));
}


// ========================================================================
// __unwind$225252
// EA  : 0x8264F5C4
// RVA : 0x0064F5C4
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225252()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 336 + 104));
}


// ========================================================================
// __unwind$225253
// EA  : 0x8264F5EC
// RVA : 0x0064F5EC
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225253()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 336 + 96));
}


// ========================================================================
// __unwind$225255_0
// EA  : 0x8264F614
// RVA : 0x0064F614
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225255_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 336 + 144));
}


// ========================================================================
// __unwind$225256_0
// EA  : 0x8264F63C
// RVA : 0x0064F63C
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225256_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 336 + 168));
}


// ========================================================================
// __unwind$225257
// EA  : 0x8264F664
// RVA : 0x0064F664
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225257()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 336 + 160));
}


// ========================================================================
// __unwind$225258
// EA  : 0x8264F68C
// RVA : 0x0064F68C
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225258()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 336 + 176));
}


// ========================================================================
// __unwind$225259
// EA  : 0x8264F6B4
// RVA : 0x0064F6B4
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225259()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 336 + 152));
}


// ========================================================================
// __unwind$225260
// EA  : 0x8264F6DC
// RVA : 0x0064F6DC
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225260()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 336 + 120));
}


// ========================================================================
// __unwind$225261
// EA  : 0x8264F704
// RVA : 0x0064F704
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225261()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 336 + 88));
}


// ========================================================================
// __unwind$225262
// EA  : 0x8264F72C
// RVA : 0x0064F72C
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225262()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 336 + 112));
}


// ========================================================================
// __unwind$225263
// EA  : 0x8264F754
// RVA : 0x0064F754
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225263()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 336 + 80));
}


// ========================================================================
// ?ShowNextDialog@idCommonLocal@@IAAX_N@Z
// EA  : 0x8264F788
// RVA : 0x0064F788
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall idCommonLocal::ShowNextDialog(idCommonLocal *this, bool waitForAtlas)
{
  int v4; // r10
  int v5; // r11
  idDialogInfo *list; // r9
  idDialogInfo *v7; // r7
  int num; // [sp+50h] [-190h]
  idDialogInfo v9; // [sp+60h] [-180h] BYREF

  v4 = 0;
  num = this->messageList.num;
  if ( num > 0 )
  {
    v5 = 0;
    list = this->messageList.list;
    v7 = list;
    while ( v7->clear )
    {
      ++v4;
      v7 = &list[++v5];
      if ( v4 >= num )
        return;
    }
    idDialogInfo::idDialogInfo(this: &v9, __that: &list[v4]);
    idCommonLocal::ShowDialog(this, info: &v9, waitOnAtlas: v9.waitOnAtlas || waitForAtlas);
    idStr::FreeData(this: &v9.overrideMsg);
  }
}


// ========================================================================
// __unwind$225624
// EA  : 0x8264F82C
// RVA : 0x0064F82C
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225624()
{
  int v0; // r12

  idDialogInfo::~idDialogInfo(this: (idDialogInfo *)(v0 - 480 + 96));
}


// ========================================================================
// ?InitDialog@idCommonLocal@@QAAXXZ
// EA  : 0x8264F860
// RVA : 0x0064F860
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall idCommonLocal::InitDialog(idCommonLocal *this)
{
  idSWF *v2; // r3
  idSWF *v3; // r11
  idSWF **p_dialog; // r28
  idSWF *v5; // r3
  idSWF *v6; // r11
  idRenderModelGui *v7; // r3
  idRenderModelGui *v8; // r11
  idRenderModelGui *v9; // r3
  idRenderModelGui *v10; // r3
  bool v11; // cr58
  idSWFScriptVar v12; // [sp+58h] [-A8h] BYREF
  idSWFScriptVar v13; // [sp+60h] [-A0h] BYREF
  idSWFScriptVar v14; // [sp+68h] [-98h] BYREF
  idSWFScriptVar v15; // [sp+70h] [-90h] BYREF
  idSWFScriptVar v16; // [sp+78h] [-88h] BYREF
  idSWFScriptVar v17; // [sp+80h] [-80h] BYREF
  idSWFScriptVar v18; // [sp+88h] [-78h] BYREF
  idSWFScriptVar v19; // [sp+90h] [-70h] BYREF
  idSWFScriptVar v20; // [sp+98h] [-68h] BYREF
  idSWFScriptVar v21; // [sp+A0h] [-60h] BYREF
  idSWFScriptVar v22; // [sp+A8h] [-58h] BYREF
  idSWFScriptVar v23; // [sp+B0h] [-50h] BYREF
  idSWFScriptVar v24; // [sp+B8h] [-48h] BYREF
  idSWFScriptVar v25[8]; // [sp+C0h] [-40h] BYREF

  idLib::PrintfIf(condition: popupDialog_debug.valueInteger != 0, fmt: "[%s]\n", "idCommonLocal::InitDialog");
  idCommonLocal::KillDialog(this);
  v2 = (idSWF *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                  size: 0x27Cu,
                  tag: TAG_SWF,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idSWF::idSWF(this: v2, filename_: "tungdialog", soundWorld: nullptr, atlasPurgable_: true);
  else
    v3 = nullptr;
  p_dialog = &this->dialog;
  this->dialog = v3;
  v5 = (idSWF *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                  size: 0x27Cu,
                  tag: TAG_SWF,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v6 = idSWF::idSWF(this: v5, filename_: "save_indicator", soundWorld: nullptr, atlasPurgable_: true);
  else
    v6 = nullptr;
  this->saveIndicator = v6;
  v7 = (idRenderModelGui *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0xA410u,
                             tag: TAG_GUI_MODEL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
    v8 = idRenderModelGui::idRenderModelGui(this: v7);
  else
    v8 = nullptr;
  this->dialogGuiModel = v8;
  v9 = (idRenderModelGui *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0xA410u,
                             tag: TAG_GUI_MODEL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v9 != nullptr )
    v10 = idRenderModelGui::idRenderModelGui(this: v9);
  else
    v10 = nullptr;
  v11 = *p_dialog == nullptr;
  this->saveIndicatorGuiModel = v10;
  if ( !v11 )
  {
    v12.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v12);
    v12.type = SWF_VAR_INTEGER;
    v12.value.i = 0;
    idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "DIALOG_ACCEPT", value: &v12);
    idSWFScriptVar::Free(this: &v12);
    v13.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v13);
    v13.type = SWF_VAR_INTEGER;
    v13.value.i = 1;
    idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "DIALOG_CONTINUE", value: &v13);
    idSWFScriptVar::Free(this: &v13);
    v14.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v14);
    v14.type = SWF_VAR_INTEGER;
    v14.value.i = 2;
    idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "DIALOG_ACCEPT_CANCEL", value: &v14);
    idSWFScriptVar::Free(this: &v14);
    v15.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v15);
    v15.type = SWF_VAR_INTEGER;
    v15.value.i = 3;
    idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "DIALOG_YES_NO", value: &v15);
    idSWFScriptVar::Free(this: &v15);
    v16.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v16);
    v16.type = SWF_VAR_INTEGER;
    v16.value.i = 4;
    idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "DIALOG_CANCEL", value: &v16);
    idSWFScriptVar::Free(this: &v16);
    v17.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v17);
    v17.type = SWF_VAR_INTEGER;
    v17.value.i = 5;
    idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "DIALOG_WAIT", value: &v17);
    idSWFScriptVar::Free(this: &v17);
    v18.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v18);
    v18.type = SWF_VAR_INTEGER;
    v18.value.i = 6;
    idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "DIALOG_WAIT_BLACKOUT", value: &v18);
    idSWFScriptVar::Free(this: &v18);
    v19.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v19);
    v19.type = SWF_VAR_INTEGER;
    v19.value.i = 7;
    idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "DIALOG_WAIT_CANCEL", value: &v19);
    idSWFScriptVar::Free(this: &v19);
    v20.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v20);
    v20.type = SWF_VAR_INTEGER;
    v20.value.i = 8;
    idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "DIALOG_DYNAMIC", value: &v20);
    idSWFScriptVar::Free(this: &v20);
    v21.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v21);
    v21.type = SWF_VAR_INTEGER;
    v21.value.i = 9;
    idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "DIALOG_QUICK_SAVE", value: &v21);
    idSWFScriptVar::Free(this: &v21);
    v22.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v22);
    v22.type = SWF_VAR_INTEGER;
    v22.value.i = 10;
    idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "DIALOG_TIMER_ACCEPT_REVERT", value: &v22);
    idSWFScriptVar::Free(this: &v22);
    v23.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v23);
    v23.type = SWF_VAR_INTEGER;
    v23.value.i = 11;
    idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "DIALOG_CRAWL_SAVE", value: &v23);
    idSWFScriptVar::Free(this: &v23);
    v24.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v24);
    v24.type = SWF_VAR_INTEGER;
    v24.value.i = 12;
    idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "DIALOG_CONTINUE_LARGE", value: &v24);
    idSWFScriptVar::Free(this: &v24);
    v25[0].type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: v25);
    v25[0].type = SWF_VAR_INTEGER;
    v25[0].value.i = 13;
    idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "DIALOG_BENCHMARK", value: v25);
    idSWFScriptVar::Free(this: v25);
  }
}


// ========================================================================
// __unwind$225704
// EA  : 0x8264FD1C
// RVA : 0x0064FD1C
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225704()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$225705
// EA  : 0x8264FD48
// RVA : 0x0064FD48
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225705()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$225706
// EA  : 0x8264FD74
// RVA : 0x0064FD74
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225706()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_GUI_MODEL);
}


// ========================================================================
// __unwind$225707
// EA  : 0x8264FDA0
// RVA : 0x0064FDA0
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225707()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_GUI_MODEL);
}


// ========================================================================
// __unwind$225708
// EA  : 0x8264FDCC
// RVA : 0x0064FDCC
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225708()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 88));
}


// ========================================================================
// __unwind$225709
// EA  : 0x8264FDF4
// RVA : 0x0064FDF4
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225709()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$225710
// EA  : 0x8264FE1C
// RVA : 0x0064FE1C
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225710()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 104));
}


// ========================================================================
// __unwind$225711
// EA  : 0x8264FE44
// RVA : 0x0064FE44
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225711()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 112));
}


// ========================================================================
// __unwind$225712
// EA  : 0x8264FE6C
// RVA : 0x0064FE6C
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225712()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 120));
}


// ========================================================================
// __unwind$225713_0
// EA  : 0x8264FE94
// RVA : 0x0064FE94
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225713_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$225714_0
// EA  : 0x8264FEBC
// RVA : 0x0064FEBC
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225714_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 136));
}


// ========================================================================
// __unwind$225715_0
// EA  : 0x8264FEE4
// RVA : 0x0064FEE4
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225715_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 144));
}


// ========================================================================
// __unwind$225716_0
// EA  : 0x8264FF0C
// RVA : 0x0064FF0C
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225716_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 152));
}


// ========================================================================
// __unwind$225717_0
// EA  : 0x8264FF34
// RVA : 0x0064FF34
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225717_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 160));
}


// ========================================================================
// __unwind$225718_0
// EA  : 0x8264FF5C
// RVA : 0x0064FF5C
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225718_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 168));
}


// ========================================================================
// __unwind$225719
// EA  : 0x8264FF84
// RVA : 0x0064FF84
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225719()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 176));
}


// ========================================================================
// __unwind$225720
// EA  : 0x8264FFAC
// RVA : 0x0064FFAC
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225720()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 184));
}


// ========================================================================
// __unwind$225721
// EA  : 0x8264FFD4
// RVA : 0x0064FFD4
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_225721()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 192));
}


// ========================================================================
// ?testShowDynamicDialog_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82650008
// RVA : 0x00650008
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall testShowDynamicDialog_f(const idCmdArgs *args)
{
  _DWORD *v1; // r3
  _DWORD *v2; // r11
  const char *LocalizedString; // r3
  __int64 v4; // r10
  __int64 v5; // r8
  va *v6; // r3
  __int64 v7; // r6
  __int64 v8; // r10
  __int64 v9; // r8
  va *v10; // r3
  idStrStatic<256> *v11; // r3
  int v12; // [sp+8h] [-1248h]
  int v13; // [sp+8h] [-1248h]
  int v14; // [sp+Ch] [-1244h]
  int v15; // [sp+Ch] [-1244h]
  int v16; // [sp+10h] [-1240h]
  int v17; // [sp+10h] [-1240h]
  int v18; // [sp+14h] [-123Ch]
  int v19; // [sp+14h] [-123Ch]
  int v20; // [sp+18h] [-1238h]
  int v21; // [sp+18h] [-1238h]
  int v22; // [sp+1Ch] [-1234h]
  int v23; // [sp+1Ch] [-1234h]
  idStrId v24; // [sp+60h] [-11F0h] BYREF
  idStrId v25; // [sp+64h] [-11ECh] BYREF
  encounterGroupRole_t v26[2]; // [sp+68h] [-11E8h] BYREF
  idList<idVehicleState *,5> v27; // [sp+70h] [-11E0h] BYREF
  _BYTE v28[16]; // [sp+80h] [-11D0h] BYREF
  idList<enum encounterGroupRole_t,5> v29; // [sp+90h] [-11C0h] BYREF
  int v30; // [sp+A0h] [-11B0h] BYREF
  idStr v31; // [sp+B0h] [-11A0h] BYREF
  idStr v32; // [sp+D0h] [-1180h] BYREF
  idStr v33; // [sp+F0h] [-1160h] BYREF
  idStrStatic<256> v34; // [sp+110h] [-1140h] BYREF
  va v35; // [sp+230h] [-1020h] BYREF

  *(_QWORD *)&v29.num = 4;
  v29.list = (encounterGroupRole_t *)&v30;
  *(_DWORD *)&v29.granularity = 66817;
  *(_QWORD *)&v27.num = 4;
  v27.list = (idVehicleState **)v28;
  *(_DWORD *)&v27.granularity = 66817;
  memset(v28, 255, sizeof(v28));
  v1 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
         size: 8u,
         tag: TAG_SWF,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
  {
    v1[1] = 0;
    v2 = v1;
    *v1 = &`testShowDynamicDialog_f'::`2'::idSWFScriptFunction_Continue::`vftable';
  }
  else
  {
    v2 = nullptr;
  }
  v26[0] = (encounterGroupRole_t)v2;
  idList<idAnimWebBlendTree *,5>::Append(this: &v29, obj: v26);
  idStrId::Set(this: &v24, key: "#str_swf_btn_continue");
  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: (idList<idStrId,5> *)&v27, obj: &v24);
  idStrId::Set(this: &v25, key: "#str_dlg_space_required");
  LocalizedString = idStrId::GetLocalizedString(this: &v25);
  idStr::idStr(this: &v32, text: LocalizedString);
  HIDWORD(v4) = 20;
  LODWORD(v5) = v31.baseBuffer;
  v31.len = 0;
  v31.allocedAndFlag = 20;
  v31.data = v31.baseBuffer;
  v31.baseBuffer[0] = 0;
  HIDWORD(v5) = &unk_821D0000;
  v6 = va::va(
         this: &v35,
         fmt: (const char *)0x40624F80,
         a3: (unsigned int)&unk_821D0000,
         a4: v5,
         a5: v4,
         a6: v12,
         a7: v14,
         a8: v16,
         a9: v18,
         a10: v20,
         a11: v22);
  idStr::operator=(this: &v31, text: v6);
  HIDWORD(v7) = v31.data;
  v10 = va::va(
          this: &v35,
          fmt: v32.data,
          a3: v7,
          a4: v9,
          a5: v8,
          a6: v13,
          a7: v15,
          a8: v17,
          a9: v19,
          a10: v21,
          a11: v23);
  idStr::idStr(this: &v33, text: v10);
  v11 = idStrStatic<256>::idStrStatic<256>(this: &v34, text: &v33);
  ((void (__fastcall *)(idCommon *, int, idList<enum encounterGroupRole_t,5> *, idList<idVehicleState *,5> *, int, idStrStatic<256> *, _DWORD, _DWORD))common->AddDynamicDialog)(
    a1: common,
    a2: 60,
    a3: &v29,
    a4: &v27,
    a5: 1,
    a6: v11,
    a7: 0,
    a8: 0);
  idStr::FreeData(this: &v33);
  idStr::FreeData(this: &v31);
  idStr::FreeData(this: &v32);
  idList<idThread *,58>::Clear(this: &v27);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v29);
}


// ========================================================================
// __unwind$226078
// EA  : 0x82650200
// RVA : 0x00650200
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_226078()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4688 + 144));
}


// ========================================================================
// __unwind$226079
// EA  : 0x82650228
// RVA : 0x00650228
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_226079()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4688 + 112));
}


// ========================================================================
// __unwind$226081
// EA  : 0x82650250
// RVA : 0x00650250
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_226081()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4688 + 208));
}


// ========================================================================
// __unwind$226082
// EA  : 0x82650278
// RVA : 0x00650278
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_226082()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4688 + 176));
}


// ========================================================================
// __unwind$226083
// EA  : 0x826502A0
// RVA : 0x006502A0
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_226083()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4688 + 240));
}


// ========================================================================
// ?AddDialogInternal@idCommonLocal@@IAAXAAVidDialogInfo@@@Z
// EA  : 0x826505E0
// RVA : 0x006505E0
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall idCommonLocal::AddDialogInternal(idCommonLocal *this, idDialogInfo *info)
{
  idSWFScriptFunction *acceptCB; // r11
  idSWFScriptFunction *cancelCB; // r11
  idSWFScriptFunction *altCBOne; // r11
  idSWFScriptFunction *altCBTwo; // r11
  int num; // r11
  idDialogInfo *list; // r10
  dialogType_t type; // r11
  dialogType_t v11; // r11

  if ( !this->HasDialogMsg(this, a2: info->msg, a3: nullptr) )
  {
    if ( info->msg == GDM_STORAGE_REQUIRED )
    {
      if ( this->HasDialogMsg(this, a2: GDM_DELETE_SAVE, a3: nullptr) )
        this->ClearDialog(this, a2: GDM_DELETE_SAVE, a3: nullptr, a4: 0);
      if ( this->HasDialogMsg(this, a2: GDM_DELETE_AUTOSAVE, a3: nullptr) )
        this->ClearDialog(this, a2: GDM_DELETE_AUTOSAVE, a3: nullptr, a4: 0);
      if ( this->HasDialogMsg(this, a2: GDM_LOAD_DAMAGED_FILE, a3: nullptr) )
        this->ClearDialog(this, a2: GDM_LOAD_DAMAGED_FILE, a3: nullptr, a4: 0);
    }
    acceptCB = info->acceptCB;
    if ( acceptCB != nullptr )
      ((void (*)(void))acceptCB->AddRef)();
    cancelCB = info->cancelCB;
    if ( cancelCB != nullptr )
      ((void (*)(void))cancelCB->AddRef)();
    altCBOne = info->altCBOne;
    if ( altCBOne != nullptr )
      ((void (*)(void))altCBOne->AddRef)();
    altCBTwo = info->altCBTwo;
    if ( altCBTwo != nullptr )
      ((void (*)(void))altCBTwo->AddRef)();
    num = this->messageList.num;
    if ( num != 0 )
    {
      if ( (((num >= 0) + ((unsigned int)num >= 4)) & 1) == 0 )
        idList<idDialogInfo,5>::RemoveIndex(this: &this->messageList, index: 3);
      if ( this->messageList.num > 0 )
      {
        idLib::PrintfIf(
          condition: popupDialog_debug.valueInteger != 0,
          fmt: "[%s] msg: %s new dialog added over old\n",
          "idCommonLocal::AddDialogInternal",
          dialogStateToString[info->msg]);
        list = this->messageList.list;
        type = list->type;
        if ( type == DIALOG_QUICK_SAVE || type == DIALOG_CRAWL_SAVE || list->msg == GDM_CALCULATING_BENCHMARK )
        {
          this->dialogWingstickActive = false;
          renderSystem->EndAutomaticBackgroundSwaps(this: renderSystem);
        }
        idSWF::Activate(this: this->dialog, b: false);
        idList<idDialogInfo,5>::Insert(this: &this->messageList, obj: info, index: 0);
      }
    }
    else
    {
      idList<idDialogInfo,5>::Append(this: &this->messageList, obj: info);
    }
    v11 = info->type;
    if ( v11 == DIALOG_QUICK_SAVE
      || v11 == DIALOG_CRAWL_SAVE
      || this->messageList.list->msg == GDM_CALCULATING_BENCHMARK )
    {
      idCommonLocal::ShowNextDialog(this, waitForAtlas: false);
    }
    if ( !this->dialog->isActive && info->waitOnAtlas )
      idCommonLocal::ShowNextDialog(this, waitForAtlas: false);
  }
}


// ========================================================================
// ?AddDialog@idCommonLocal@@UAAXW4gameDialogMessages_t@@W4dialogType_t@@PAVidSWFScriptFunction@@2_NPBDH333@Z
// EA  : 0x82650900
// RVA : 0x00650900
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall idCommonLocal::AddDialog(
        idCommonLocal *this,
        gameDialogMessages_t msg,
        dialogType_t type,
        idSWFScriptFunction *acceptCallback,
        idSWFScriptFunction *cancelCallback,
        bool pause,
        const char *location,
        int lineNumber,
        bool leaveOnMapHeapReset,
        bool waitOnAtlas,
        bool renderDuringLoad,
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
        bool a28,
        int a29,
        bool a30,
        int a31,
        bool a32)
{
  const char *v40; // r8
  idDialogInfo v41; // [sp+50h] [-1B0h] BYREF

  idKeyInput::ClearStates();
  sys->ClearEvents(this: sys);
  if ( common->GetRecordState(this: common) == RECORD_NONE )
  {
    if ( location != nullptr )
      v40 = location;
    else
      v40 = "NULL";
    idLib::PrintfIf(
      condition: popupDialog_debug.valueInteger != 0,
      fmt: "[%s] msg: %s, pause: %d from: %s:%d\n",
      "idCommonLocal::AddDialog",
      dialogStateToString[msg],
      pause,
      v40,
      lineNumber);
    if ( this->dialog != nullptr )
    {
      idDialogInfo::idDialogInfo(this: &v41);
      v41.msg = msg;
      v41.type = type;
      v41.acceptCB = acceptCallback;
      v41.cancelCB = cancelCallback;
      v41.clear = false;
      v41.pause = pause;
      v41.startTime = Sys_Milliseconds();
      v41.killTime = 0;
      v41.leaveOnClear = a28;
      v41.waitOnAtlas = a30;
      v41.renderDuringLoad = a32;
      idCommonLocal::AddDialogInternal(this, info: &v41);
      idStr::FreeData(this: &v41.overrideMsg);
    }
  }
}


// ========================================================================
// __unwind$226330
// EA  : 0x82650A3C
// RVA : 0x00650A3C
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_226330()
{
  int v0; // r12

  idDialogInfo::~idDialogInfo(this: (idDialogInfo *)(v0 - 512 + 80));
}


// ========================================================================
// ?AddDynamicDialog@idCommonLocal@@UAAXW4gameDialogMessages_t@@ABV?$idStaticList@PAVidSWFScriptFunction@@$03@@ABV?$idStaticList@VidStrId@@$03@@_NV?$idStrStatic@$0BAA@@@333@Z
// EA  : 0x82650A70
// RVA : 0x00650A70
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall idCommonLocal::AddDynamicDialog(
        idCommonLocal *this,
        gameDialogMessages_t msg,
        const idStaticList<idSWFScriptFunction *,4> *callbacks,
        const idStaticList<idStrId,4> *optionText,
        bool pause,
        idStrStatic<256> *overrideMsg,
        bool leaveOnMapHeapReset,
        bool waitOnAtlas,
        bool renderDuringLoad,
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
        bool a28)
{
  idStrStatic<256> *v35; // r3
  int len; // r11
  size_t v37; // r5
  char *data; // r4
  int num; // r11
  int v40; // r9
  int index; // [sp+50h] [-1C0h]
  int v42; // [sp+50h] [-1C0h]
  int v43; // [sp+50h] [-1C0h]
  int v44; // [sp+50h] [-1C0h]
  idDialogInfo v45; // [sp+60h] [-1B0h] BYREF

  if ( this->dialog != nullptr )
  {
    v45.overrideMsg.baseBuffer[0] = 0;
    v45.overrideMsg.buffer[0] = 0;
    memset(&v45.txt1, 255, 16);
    v45.overrideMsg.data = v45.overrideMsg.buffer;
    memset(&v45.type, 0, 23);
    v45.startTime = 0;
    v45.killTime = 0;
    v45.leaveOnClear = false;
    v45.waitOnAtlas = false;
    v45.renderDuringLoad = false;
    v45.overrideMsg.allocedAndFlag = -2147483392;
    len = overrideMsg->len;
    v37 = overrideMsg->len + 1;
    v45.msg = msg;
    data = overrideMsg->data;
    v45.overrideMsg.len = len;
    memcpy(Dst: v45.overrideMsg.buffer, Src: data, Size: v37);
    num = callbacks->num;
    v45.pause = pause;
    v45.leaveOnClear = leaveOnMapHeapReset;
    v45.type = DIALOG_DYNAMIC;
    if ( num <= 0 )
      v45.acceptCB = nullptr;
    else
      v45.acceptCB = *callbacks->list;
    if ( num <= 1 )
      v45.cancelCB = nullptr;
    else
      v45.cancelCB = callbacks->list[1];
    if ( num <= 2 )
      v45.altCBOne = nullptr;
    else
      v45.altCBOne = callbacks->list[2];
    if ( num <= 3 )
      v45.altCBTwo = nullptr;
    else
      v45.altCBTwo = callbacks->list[3];
    v40 = optionText->num;
    if ( v40 <= 0 )
      index = -1;
    else
      index = optionText->list->index;
    v45.txt1.index = index;
    if ( v40 <= 1 )
      v42 = -1;
    else
      v42 = optionText->list[1].index;
    v45.txt2.index = v42;
    if ( v40 <= 2 )
      v43 = -1;
    else
      v43 = optionText->list[2].index;
    v45.txt3.index = v43;
    if ( v40 <= 3 )
      v44 = -1;
    else
      v44 = optionText->list[3].index;
    v45.waitOnAtlas = waitOnAtlas;
    v45.clear = false;
    v45.txt4.index = v44;
    v45.renderDuringLoad = a28;
    v45.startTime = Sys_Milliseconds();
    v45.killTime = 0;
    idCommonLocal::AddDialogInternal(this, info: &v45);
    idStr::FreeData(this: &v45.overrideMsg);
    v35 = overrideMsg;
  }
  else
  {
    v35 = overrideMsg;
  }
  idStr::FreeData(this: v35);
}


// ========================================================================
// __unwind$226397
// EA  : 0x82650CDC
// RVA : 0x00650CDC
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_226397()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 528 + 588));
}


// ========================================================================
// __unwind$226398
// EA  : 0x82650D04
// RVA : 0x00650D04
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_226398()
{
  int v0; // r12

  idDialogInfo::~idDialogInfo(this: (idDialogInfo *)(v0 - 528 + 96));
}


// ========================================================================
// ?RenderDialog@idCommonLocal@@QAAX_N@Z
// EA  : 0x82650D38
// RVA : 0x00650D38
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __fastcall idCommonLocal::RenderDialog(idCommonLocal *this, bool loading)
{
  idSWF **p_dialog; // r17
  bool *p_dialogPause; // r20
  idSWF *dialog; // r11
  idRenderModelGui **p_dialogGuiModel; // r19
  unsigned __int64 v8; // r6
  int *p_num; // r21
  char v10; // r22
  int v11; // r30
  int v12; // r29
  idDialogInfo *v13; // r11
  int v14; // r11
  idDialogInfo *list; // r11
  idStaticList<idDialogInfo,4> *p_messageList; // r29
  int v17; // r30
  int v18; // r30
  const char *LocalizedString; // r3
  __int64 v20; // r6
  __int64 v21; // r10
  __int64 v22; // r8
  va *v23; // r3
  int v24; // r29
  int v25; // r3
  __int128 v26; // r5
  double v27; // fp31
  int v28; // r29
  idSWF **p_saveIndicator; // r28
  idRenderModelGui **p_saveIndicatorGuiModel; // r29
  int v31; // r27
  int v32; // r3
  __int128 v33; // r5
  double v34; // fp31
  int v35; // r30
  int v36; // [sp+8h] [-1198h]
  int v37; // [sp+Ch] [-1194h]
  int v38; // [sp+10h] [-1190h]
  int v39; // [sp+14h] [-118Ch]
  int v40; // [sp+18h] [-1188h]
  int v41; // [sp+1Ch] [-1184h]
  int v42; // [sp+54h] [-114Ch]
  int v43; // [sp+54h] [-114Ch]
  idSWFScriptVar v44; // [sp+58h] [-1148h] BYREF
  idStrId v45[2]; // [sp+60h] [-1140h] BYREF
  idSWFScriptVar v46; // [sp+68h] [-1138h] BYREF
  idStaticList<idSWFScriptVar,16> v47; // [sp+70h] [-1130h] BYREF
  va v48; // [sp+100h] [-10A0h] BYREF

  p_dialog = &this->dialog;
  p_dialogPause = &this->dialogPause;
  dialog = this->dialog;
  this->dialogPause = false;
  if ( dialog != nullptr )
  {
    p_dialogGuiModel = &this->dialogGuiModel;
    if ( this->dialogGuiModel != nullptr )
    {
      idCommonLocal::RemoveWaitDialogs(this);
      p_num = &this->messageList.num;
      v10 = 0;
      v11 = 0;
      if ( this->messageList.num > 0 )
      {
        v12 = 0;
        do
        {
          v13 = &this->messageList.list[v12];
          if ( v13->clear )
          {
            idLib::PrintfIf(
              condition: popupDialog_debug.valueInteger != 0,
              fmt: "[%s] removing %s\n",
              "idCommonLocal::RenderDialog",
              dialogStateToString[v13->msg]);
            idCommonLocal::ReleaseCallBacks(this, index: v11);
            idList<idDialogInfo,5>::RemoveIndex(this: &this->messageList, index: v11--);
            --v12;
          }
          else if ( v13->pause && v10 == 0 )
          {
            v10 = 1;
          }
          ++v11;
          ++v12;
        }
        while ( v11 < *p_num );
      }
      v14 = *p_num;
      *p_dialogPause = v10;
      if ( v14 > 0 && !(*p_dialog)->isActive )
        idCommonLocal::ShowNextDialog(this, waitForAtlas: false);
      if ( *p_num == 0 && (*p_dialog)->isActive )
        idSWF::Activate(this: *p_dialog, b: false);
      if ( !this->dialogShowingSaveIndicatorRequested && this->saveIndicator->isActive )
        this->ShowSaveIndicator(this, a2: false, a3: false);
      if ( *p_num > 0 )
      {
        list = this->messageList.list;
        p_messageList = &this->messageList;
        if ( list->type == DIALOG_TIMER_ACCEPT_REVERT )
        {
          v17 = list->startTime + 20000;
          v18 = (v17 - Sys_Milliseconds()) / 1000;
          if ( v18 > 0 )
          {
            idStrId::Set(this: v45, key: "#str_online_mpstatus_time_remaining");
            LocalizedString = idStrId::GetLocalizedString(this: v45);
            HIDWORD(v20) = v18;
            v23 = va::va(
                    this: &v48,
                    fmt: LocalizedString,
                    a3: v20,
                    a4: v22,
                    a5: v21,
                    a6: v36,
                    a7: v37,
                    a8: v38,
                    a9: v39,
                    a10: v40,
                    a11: v41);
            v44.type = SWF_VAR_UNDEF;
            idSWFScriptVar::SetString(this: &v44, s: v23);
            idSWFScriptObject::Set(this: (*p_dialog)->globals, name: "countdownInfo", value: &v44);
            idSWFScriptVar::Free(this: &v44);
          }
          else
          {
            if ( p_messageList->list->cancelCB != nullptr )
            {
              idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v47);
              p_messageList->list->cancelCB->Call(
                this: (idSWFScriptFunction *)&v46,
                result: (idSWFScriptVar *)p_messageList->list->cancelCB,
                a3: nullptr,
                a4: (const idSWFParmList *)&v47);
              idSWFScriptVar::Free(this: &v46);
              idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v47);
            }
            p_messageList->list->clear = true;
          }
        }
      }
      if ( *p_num <= 0 || !loading || this->messageList.list->renderDuringLoad )
      {
        if ( (*p_dialog)->isActive )
        {
          idRenderModelGui::Clear(this: *p_dialogGuiModel, bits: v8);
          v24 = renderSystem->GetHeight(this: renderSystem);
          v25 = renderSystem->GetWidth(this: renderSystem);
          idRenderModelGui::SetViewport(this: *p_dialogGuiModel, x: 0, y: 0, width: v25, height: v24);
          *(_QWORD *)((char *)&v26 + 4) = ((__int64 (__fastcall *)(idRenderSystem *))renderSystem->GetWidth)(a1: renderSystem);
          LODWORD(v26) = DWORD1(v26);
          v27 = (float)(__int64)v26;
          v28 = renderSystem->GetHeight(this: renderSystem);
          v42 = (int)(float)(renderSystem->GetPixelAspect(this: renderSystem) * (float)v27);
          idRenderModelGui::SetVirtualSize(this: *p_dialogGuiModel, width: v42, height: v28);
          idSWF::Render(this: *p_dialog, gui: *p_dialogGuiModel, time: 0, isSplitscreen: false);
        }
        else if ( this->dialogWingstickActive )
        {
          this->dialogWingstickActive = false;
          renderSystem->EndAutomaticBackgroundSwaps(this: renderSystem);
        }
        p_saveIndicator = &this->saveIndicator;
        if ( this->saveIndicator != nullptr )
        {
          p_saveIndicatorGuiModel = &this->saveIndicatorGuiModel;
          if ( this->saveIndicatorGuiModel != nullptr && (*p_saveIndicator)->isActive )
          {
            idRenderModelGui::Clear(this: (idRenderModelGui *)HIDWORD(defaultExtraGLState), bits: v8);
            v31 = renderSystem->GetHeight(this: renderSystem);
            v32 = renderSystem->GetWidth(this: renderSystem);
            idRenderModelGui::SetViewport(this: *p_saveIndicatorGuiModel, x: 0, y: 0, width: v32, height: v31);
            *(_QWORD *)((char *)&v33 + 4) = ((__int64 (__fastcall *)(idRenderSystem *))renderSystem->GetWidth)(a1: renderSystem);
            LODWORD(v33) = DWORD1(v33);
            v34 = (float)(__int64)v33;
            v35 = renderSystem->GetHeight(this: renderSystem);
            v43 = (int)(float)(renderSystem->GetPixelAspect(this: renderSystem) * (float)v34);
            idRenderModelGui::SetVirtualSize(this: *p_saveIndicatorGuiModel, width: v43, height: v35);
            idSWF::Render(this: *p_saveIndicator, gui: *p_saveIndicatorGuiModel, time: 0, isSplitscreen: false);
          }
        }
      }
    }
  }
}


// ========================================================================
// __unwind$226728
// EA  : 0x82651260
// RVA : 0x00651260
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_226728()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 4512 + 112));
}


// ========================================================================
// __unwind$226730
// EA  : 0x82651288
// RVA : 0x00651288
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void _unwind_226730()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4512 + 88));
}


// ========================================================================
// `dynamic initializer for 'popupDialog_debug''
// EA  : 0x833383F8
// RVA : 0x013383F8
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__popupDialog_debug__()
{
  idCVar::idCVar(
    this: &popupDialog_debug,
    name: "popupDialog_debug",
    value: "0",
    flags: 1,
    description: "display debug spam",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__popupDialog_debug__);
}


// ========================================================================
// `dynamic initializer for 'dialog_saveClearLevel1''
// EA  : 0x83338450
// RVA : 0x01338450
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dialog_saveClearLevel1__()
{
  idCVar::idCVar(
    this: &dialog_saveClearLevel1,
    name: "dialog_saveClearLevel1",
    value: "1000",
    flags: 2,
    description: "Time required to show short message",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dialog_saveClearLevel1__);
}


// ========================================================================
// `dynamic initializer for 'dialog_saveClearLevel2''
// EA  : 0x833384A8
// RVA : 0x013384A8
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dialog_saveClearLevel2__()
{
  idCVar::idCVar(
    this: &dialog_saveClearLevel2,
    name: "dialog_saveClearLevel2",
    value: "3000",
    flags: 2,
    description: "Time required to show long message",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dialog_saveClearLevel2__);
}


// ========================================================================
// `dynamic initializer for 'commonDialogClear_v''
// EA  : 0x83338500
// RVA : 0x01338500
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__commonDialogClear_v__()
{
  return idCommandLink::idCommandLink(
           this: &commonDialogClear_v,
           cmdName: "commonDialogClear",
           function: commonDialogClear_f,
           description: "clears all dialogs that may be hung",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testShowDialog_v''
// EA  : 0x83338528
// RVA : 0x01338528
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testShowDialog_v__()
{
  return idCommandLink::idCommandLink(
           this: &testShowDialog_v,
           cmdName: "testShowDialog",
           function: testShowDialog_f,
           description: "show a dialog",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testShowDynamicDialog_v''
// EA  : 0x83338550
// RVA : 0x01338550
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testShowDynamicDialog_v__()
{
  return idCommandLink::idCommandLink(
           this: &testShowDynamicDialog_v,
           cmdName: "testShowDynamicDialog",
           function: testShowDynamicDialog_f,
           description: "show a dynamic dialog",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testShowDialogBug_v''
// EA  : 0x83338578
// RVA : 0x01338578
// PDB : w:\tech5\engine\framework\common_dialog.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testShowDialogBug_v__()
{
  return idCommandLink::idCommandLink(
           this: &testShowDialogBug_v,
           cmdName: "testShowDialogBug",
           function: testShowDialogBug_f,
           description: "show a dynamic dialog",
           argCompletion: nullptr);
}

