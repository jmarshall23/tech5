
// ========================================================================
// ??0idDialogInfo@@QAA@XZ
// EA  : 0x826428A8
// RVA : 0x006428A8
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

idDialogInfo *__fastcall idDialogInfo::idDialogInfo(idDialogInfo *this)
{
  this->overrideMsg.allocedAndFlag = 20;
  this->overrideMsg.baseBuffer[0] = 0;
  this->overrideMsg.buffer[0] = 0;
  this->overrideMsg.data = this->overrideMsg.buffer;
  this->overrideMsg.len = 0;
  this->overrideMsg.allocedAndFlag = -2147483392;
  this->txt1.index = -1;
  this->txt2.index = -1;
  this->txt3.index = -1;
  this->txt4.index = -1;
  this->msg = GDM_INVALID;
  this->type = DIALOG_ACCEPT;
  this->acceptCB = nullptr;
  this->cancelCB = nullptr;
  this->altCBOne = nullptr;
  this->altCBTwo = nullptr;
  this->clear = false;
  this->waitClear = false;
  this->pause = false;
  this->startTime = 0;
  this->killTime = 0;
  this->leaveOnClear = false;
  this->waitOnAtlas = false;
  this->renderDuringLoad = false;
  return this;
}


// ========================================================================
// ??0idWarningList@idCommonLocal@@QAA@XZ
// EA  : 0x82645C60
// RVA : 0x00645C60
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

idCommonLocal::idWarningList *__fastcall idCommonLocal::idWarningList::idWarningList(
        idCommonLocal::idWarningList *this)
{
  this->next = nullptr;
  this->wantColor = true;
  this->threadSafe = false;
  this->minSeverity = SEV_PRINT;
  this->__vftable = (idCommonLocal::idWarningList_vtbl *)&idCommonLocal::idWarningList::`vftable';
  this->list.granularity = 0;
  this->list.memTag = 3;
  this->list.listStatic = 0;
  this->list.list = nullptr;
  this->list.size = 0;
  this->list.num = 0;
  this->hash.memTag = TAG_DEBUG;
  idHashIndex::InternalInit(this: &this->hash, initialHashSize: 1024, initialIndexSize: 1024);
  this->caption.allocedAndFlag = 20;
  this->caption.baseBuffer[0] = 0;
  this->caption.data = this->caption.buffer;
  this->caption.buffer[0] = 0;
  this->caption.len = 0;
  this->caption.allocedAndFlag = -2147483520;
  this->minSeverity = SEV_WARNING;
  return this;
}


// ========================================================================
// __unwind$238164
// EA  : 0x82645D14
// RVA : 0x00645D14
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

void _unwind_238164()
{
  int v0; // r12

  idPrintListener::~idPrintListener(this: *(idCommonLocal::idRefreshOnPrint **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$238165
// EA  : 0x82645D3C
// RVA : 0x00645D3C
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

void _unwind_238165()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                         + 16));
}


// ========================================================================
// ?IsMainMenuActive@idCommonLocal@@UBA_NXZ
// EA  : 0x82646530
// RVA : 0x00646530
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

BOOL __fastcall idCommonLocal::IsMainMenuActive(idCommonLocal *this)
{
  return this->game->Shell_IsActive(this: this->game);
}


// ========================================================================
// ?IsGamePaused@idCommonLocal@@UBA_NXZ
// EA  : 0x82646548
// RVA : 0x00646548
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

BOOL __fastcall idCommonLocal::IsGamePaused(idCommonLocal *this)
{
  return this->game->GetGamePaused(this: this->game);
}


// ========================================================================
// ?GetRecentInputDevice@idCommonLocal@@UAAHXZ
// EA  : 0x82646560
// RVA : 0x00646560
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

int __fastcall idCommonLocal::GetRecentInputDevice(idCommonLocal *this)
{
  return this->recentInputDevice;
}


// ========================================================================
// ?GetFocusDeviceNum@idCommonLocal@@UBAHXZ
// EA  : 0x82646568
// RVA : 0x00646568
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

int __fastcall idCommonLocal::GetFocusDeviceNum(idCommonLocal *this)
{
  return this->focusDevice;
}


// ========================================================================
// ?SetFocusDeviceNum@idCommonLocal@@UAAXH@Z
// EA  : 0x82646570
// RVA : 0x00646570
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

void __fastcall idCommonLocal::SetFocusDeviceNum(idCommonLocal *this, int index)
{
  this->focusDevice = index;
}


// ========================================================================
// ?GetPauseMenuDeviceNum@idCommonLocal@@UBAHXZ
// EA  : 0x82646578
// RVA : 0x00646578
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

int __fastcall idCommonLocal::GetPauseMenuDeviceNum(idCommonLocal *this)
{
  return this->pauseMenuDevice;
}


// ========================================================================
// ?SetPauseMenuDeviceNum@idCommonLocal@@UAAXH@Z
// EA  : 0x82646580
// RVA : 0x00646580
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

void __fastcall idCommonLocal::SetPauseMenuDeviceNum(idCommonLocal *this, int index)
{
  this->pauseMenuDevice = index;
}


// ========================================================================
// ?GetAutosaveEnabled@idCommonLocal@@UAA_NXZ
// EA  : 0x82646588
// RVA : 0x00646588
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

BOOL __fastcall idCommonLocal::GetAutosaveEnabled(idCommonLocal *this)
{
  return this->autosavesEnabled;
}


// ========================================================================
// ?EnableAutosaves@idCommonLocal@@UAAX_N@Z
// EA  : 0x82646590
// RVA : 0x00646590
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

void __fastcall idCommonLocal::EnableAutosaves(idCommonLocal *this, bool enable)
{
  this->autosavesEnabled = enable;
}


// ========================================================================
// ?VideoOverlay@idCommonLocal@@UAAPAVidRenderVideoOverlay@@XZ
// EA  : 0x82646598
// RVA : 0x00646598
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

idSubtitles_VideoOverlay *__fastcall idCommonLocal::VideoOverlay(idCommonLocal *this)
{
  return this->videoOverlay;
}


// ========================================================================
// ?Game@idCommonLocal@@UBAPBVidGame@@XZ
// EA  : 0x826465A8
// RVA : 0x006465A8
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

const idGame *__fastcall idCommonLocal::Game(idCommonLocal *this)
{
  return this->game;
}


// ========================================================================
// ?RW@idCommonLocal@@UAAPAVidRenderWorld@@XZ
// EA  : 0x826465B0
// RVA : 0x006465B0
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

idRenderWorld *__fastcall idCommonLocal::RW(idCommonLocal *this)
{
  return this->game->GetRenderWorld(this: this->game);
}


// ========================================================================
// ?SW@idCommonLocal@@UAAPAVidSoundWorld@@XZ
// EA  : 0x826465C8
// RVA : 0x006465C8
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

idSoundWorld *__fastcall idCommonLocal::SW(idCommonLocal *this)
{
  return this->game->GetSoundWorld(this: this->game);
}


// ========================================================================
// ?GetRecordState@idCommonLocal@@UAA?AW4recordState_t@@XZ
// EA  : 0x826465E0
// RVA : 0x006465E0
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

recordState_t __fastcall idCommonLocal::GetRecordState(idCommonLocal *this)
{
  return this->recordState;
}


// ========================================================================
// ?GetRegression@idCommonLocal@@UAAPAVidRegression@@XZ
// EA  : 0x826465E8
// RVA : 0x006465E8
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

idRegressionLocal *__fastcall idCommonLocal::GetRegression(idCommonLocal *this)
{
  return &this->regression;
}


// ========================================================================
// ?SnapshotsAreStalled@idCommonLocal@@UBA_NXZ
// EA  : 0x826465F0
// RVA : 0x006465F0
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

int __fastcall idCommonLocal::SnapshotsAreStalled(idCommonLocal *this)
{
  unsigned __int8 v1; // r11

  if ( LODWORD(this->snapCurrentTime) < LODWORD(this->snapRate) )
    return 0;
  v1 = 1;
  if ( this->readSnapshotIndex != this->writeSnapshotIndex )
    return 0;
  return v1;
}


// ========================================================================
// ?DemoPlaying@idCommonLocal@@UBA_NXZ
// EA  : 0x82646620
// RVA : 0x00646620
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

BOOL __fastcall idCommonLocal::DemoPlaying(idCommonLocal *this)
{
  return (_cntlzw(this->demoMode - 3) & 0x20) != 0;
}


// ========================================================================
// ?DemoRecording@idCommonLocal@@UBA_NXZ
// EA  : 0x82646638
// RVA : 0x00646638
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

BOOL __fastcall idCommonLocal::DemoRecording(idCommonLocal *this)
{
  return (_cntlzw(this->demoMode - 1) & 0x20) != 0;
}


// ========================================================================
// ?TimeTrialPlaying@idCommonLocal@@UBA_NXZ
// EA  : 0x82646650
// RVA : 0x00646650
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

int __fastcall idCommonLocal::TimeTrialPlaying(idCommonLocal *this)
{
  unsigned __int8 v1; // r11

  if ( this->demoMode != DEMO_TIMETRIAL )
    return 0;
  v1 = 1;
  if ( this->ssFileState[0].file == nullptr )
    return 0;
  return v1;
}


// ========================================================================
// ?TimeTrialRecording@idCommonLocal@@UBA_NXZ
// EA  : 0x82646678
// RVA : 0x00646678
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

int __fastcall idCommonLocal::TimeTrialRecording(idCommonLocal *this)
{
  unsigned __int8 v1; // r11

  if ( this->demoMode != DEMO_TIMETRIAL )
    return 0;
  v1 = 1;
  if ( this->ssFileState[1].file == nullptr )
    return 0;
  return v1;
}


// ========================================================================
// ?GetSnapRate@idCommonLocal@@EAAHXZ
// EA  : 0x826466A0
// RVA : 0x006466A0
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

int __fastcall idCommonLocal::GetSnapRate(idCommonLocal *this)
{
  return this->snapRate;
}


// ========================================================================
// ?IsDialogPausing@idCommonLocal@@UAA_NXZ
// EA  : 0x826466B0
// RVA : 0x006466B0
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

BOOL __fastcall idCommonLocal::IsDialogPausing(idCommonLocal *this)
{
  return this->dialogPause;
}


// ========================================================================
// ?IsMultiplayer@idCommonLocal@@UBA_NXZ
// EA  : 0x826466C0
// RVA : 0x006466C0
// PDB : w:\tech5\engine\framework\common_local.h
// ========================================================================

BOOL __fastcall idCommonLocal::IsMultiplayer(idCommonLocal *this)
{
  return com_multiplayer.valueInteger != 0;
}

