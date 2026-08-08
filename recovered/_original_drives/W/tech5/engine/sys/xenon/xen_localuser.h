
// ========================================================================
// ?IsXuidValid@idLocalUserXbox@@QBA_NXZ
// EA  : 0x829E6AE8
// RVA : 0x009E6AE8
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.h
// ========================================================================

BOOL __fastcall idLocalUserXbox::IsXuidValid(idLocalUserXbox *this)
{
  return LODWORD(this->xuid) != 0;
}


// ========================================================================
// ??0idLocalUserXbox@@QAA@XZ
// EA  : 0x829E6EC0
// RVA : 0x009E6EC0
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.h
// ========================================================================

idLocalUserXbox *__fastcall idLocalUserXbox::idLocalUserXbox(idLocalUserXbox *this)
{
  idLocalUser::idLocalUser(this);
  this->xuid = 0xFFFFFFFF00000000uLL;
  this->inputDevice = -1;
  this->__vftable = (idLocalUserXbox_vtbl *)&idLocalUserXbox::`vftable';
  *(_QWORD *)&this->deviceId = 0;
  this->deviceResult = DEVICE_SAVE_UNKNOWN;
  *(_WORD *)&this->saveSettingsRequested = 0;
  this->offline_xuid = 0xFFFFFFFF00000000uLL;
  *(_WORD *)&this->hasProfile = 0;
  *(_WORD *)&this->isOnline = 0;
  *(_WORD *)&this->hasXuidChanged = 0;
  *(_QWORD *)&this->canPlayOnline = 0;
  *(_QWORD *)&this->canCommunicateFriendsOnly = 0;
  *(_QWORD *)&this->canViewProfilesFriendsOnly = 0;
  this->initialXuidObtained = false;
  this->currentPresence = -1;
  *(_QWORD *)this->gamertag = 0xFFFFFFFF00000000uLL;
  *(_QWORD *)&this->gamertag[8] = 0xFFFFFFFF00000000uLL;
  return this;
}


// ========================================================================
// ?IsPersistent@idLocalUserXbox@@UBA_NXZ
// EA  : 0x829E6F68
// RVA : 0x009E6F68
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.h
// ========================================================================

BOOL __fastcall idLocalUserXbox::IsPersistent(idLocalUserXbox *this)
{
  return this->isPersistent;
}


// ========================================================================
// ?IsProfileReady@idLocalUserXbox@@UBA_NXZ
// EA  : 0x829E6F70
// RVA : 0x009E6F70
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.h
// ========================================================================

BOOL __fastcall idLocalUserXbox::IsProfileReady(idLocalUserXbox *this)
{
  return this->hasProfile;
}


// ========================================================================
// ?IsOnline@idLocalUserXbox@@UBA_NXZ
// EA  : 0x829E6F78
// RVA : 0x009E6F78
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.h
// ========================================================================

BOOL __fastcall idLocalUserXbox::IsOnline(idLocalUserXbox *this)
{
  return this->isOnline;
}


// ========================================================================
// ?HasOwnerChanged@idLocalUserXbox@@UBA_NXZ
// EA  : 0x829E6F80
// RVA : 0x009E6F80
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.h
// ========================================================================

BOOL __fastcall idLocalUserXbox::HasOwnerChanged(idLocalUserXbox *this)
{
  return this->hasXuidChanged;
}

