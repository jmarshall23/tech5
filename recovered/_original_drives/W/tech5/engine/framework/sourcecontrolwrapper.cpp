
// ========================================================================
// ?Shutdown@idSourceControlWrapper@@UAAXXZ
// EA  : 0x8269F508
// RVA : 0x0069F508
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

void __fastcall idSourceControlWrapper::Shutdown(idSourceControlWrapper *this)
{
  idSourceControl *sc; // r3
  unsigned int dllHandle; // r3

  sc = this->sc;
  if ( sc != nullptr )
    sc->Shutdown(this: sc);
  dllHandle = this->dllHandle;
  if ( dllHandle != 0 )
    Sys_DLL_Unload(dllHandle);
  this->dllHandle = 0;
  this->sc = nullptr;
  this->loadFailed = false;
}


// ========================================================================
// ?SetSilentCheckOut@idSourceControlWrapper@@UAAX_N@Z
// EA  : 0x8269F570
// RVA : 0x0069F570
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

void __fastcall idSourceControlWrapper::SetSilentCheckOut(idSourceControlWrapper *this, BOOL set)
{
  if ( this->Init(this) )
    this->sc->SetSilentCheckOut(this: this->sc, a2: set);
}


// ========================================================================
// ?GetSilentCheckOut@idSourceControlWrapper@@UAA_NXZ
// EA  : 0x8269F5D8
// RVA : 0x0069F5D8
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

BOOL __fastcall idSourceControlWrapper::GetSilentCheckOut(idSourceControlWrapper *this)
{
  return this->Init(this) && this->sc->GetSilentCheckOut(this: this->sc);
}


// ========================================================================
// ?SetSilentCheckIn@idSourceControlWrapper@@UAAX_N@Z
// EA  : 0x8269F648
// RVA : 0x0069F648
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

void __fastcall idSourceControlWrapper::SetSilentCheckIn(idSourceControlWrapper *this, BOOL set)
{
  if ( this->Init(this) )
    this->sc->SetSilentCheckIn(this: this->sc, a2: set);
}


// ========================================================================
// ?GetSilentCheckIn@idSourceControlWrapper@@UAA_NXZ
// EA  : 0x8269F6B0
// RVA : 0x0069F6B0
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

BOOL __fastcall idSourceControlWrapper::GetSilentCheckIn(idSourceControlWrapper *this)
{
  return this->Init(this) && this->sc->GetSilentCheckIn(this: this->sc);
}


// ========================================================================
// ?IsConnected@idSourceControlWrapper@@UBA_NXZ
// EA  : 0x8269F720
// RVA : 0x0069F720
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

BOOL __fastcall idSourceControlWrapper::IsConnected(idSourceControlWrapper *this)
{
  idSourceControl *sc; // r11

  sc = this->sc;
  return sc != nullptr && ((bool (*)(void))sc->IsConnected)();
}


// ========================================================================
// ?IsInitialized@idSourceControlWrapper@@UBA_NXZ
// EA  : 0x8269F748
// RVA : 0x0069F748
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

BOOL __fastcall idSourceControlWrapper::IsInitialized(idSourceControlWrapper *this)
{
  idSourceControl *sc; // r11

  sc = this->sc;
  return sc != nullptr && ((bool (*)(void))sc->IsInitialized)();
}


// ========================================================================
// ?CheckOut@idSourceControlWrapper@@UAAHABV?$idList@VidStr@@$04@@@Z
// EA  : 0x8269F770
// RVA : 0x0069F770
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

int __fastcall idSourceControlWrapper::CheckOut(idSourceControlWrapper *this, const idList<idStr,5> *files)
{
  if ( this->Init(this) )
    return this->sc->CheckOut(this: this->sc, a2: files);
  else
    return 0;
}


// ========================================================================
// ?UndoCheckOut@idSourceControlWrapper@@UAAHABV?$idList@VidStr@@$04@@@Z
// EA  : 0x8269F7E0
// RVA : 0x0069F7E0
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

int __fastcall idSourceControlWrapper::UndoCheckOut(idSourceControlWrapper *this, const idList<idStr,5> *files)
{
  if ( this->Init(this) )
    return this->sc->UndoCheckOut(this: this->sc, a2: files);
  else
    return 0;
}


// ========================================================================
// ?Import@idSourceControlWrapper@@UAAHABV?$idList@VidStr@@$04@@_N1W4scFileType_t@@@Z
// EA  : 0x8269F850
// RVA : 0x0069F850
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

int __fastcall idSourceControlWrapper::Import(
        idSourceControlWrapper *this,
        const idList<idStr,5> *files,
        BOOL bKeepCheckedOut,
        BOOL submit,
        scFileType_t fileType)
{
  if ( this->Init(this) )
    return this->sc->Import(this: this->sc, a2: files, a3: bKeepCheckedOut, a4: submit, a5: fileType);
  else
    return 0;
}


// ========================================================================
// ?GetLatest@idSourceControlWrapper@@UAAHABV?$idList@VidStr@@$04@@_N@Z
// EA  : 0x8269F8C8
// RVA : 0x0069F8C8
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

int __fastcall idSourceControlWrapper::GetLatest(
        idSourceControlWrapper *this,
        const idList<idStr,5> *files,
        BOOL force)
{
  if ( this->Init(this) )
    return this->sc->GetLatest(this: this->sc, a2: files, a3: force);
  else
    return 0;
}


// ========================================================================
// ?CheckIn@idSourceControlWrapper@@UAAHABV?$idList@VidStr@@$04@@ABVidStr@@_N@Z
// EA  : 0x8269F930
// RVA : 0x0069F930
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

int __fastcall idSourceControlWrapper::CheckIn(
        idSourceControlWrapper *this,
        const idList<idStr,5> *files,
        const idStr *comment,
        BOOL bKeepCheckedOut)
{
  if ( this->Init(this) )
    return this->sc->CheckIn(this: this->sc, a2: files, a3: comment, a4: bKeepCheckedOut);
  else
    return 0;
}


// ========================================================================
// ?Delete@idSourceControlWrapper@@UAAHABV?$idList@VidStr@@$04@@@Z
// EA  : 0x8269F9A0
// RVA : 0x0069F9A0
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

int __fastcall idSourceControlWrapper::Delete(idSourceControlWrapper *this, const idList<idStr,5> *files)
{
  if ( this->Init(this) )
    return this->sc->Delete(this: this->sc, a2: files);
  else
    return 0;
}


// ========================================================================
// ?GetFileStatus@idSourceControlWrapper@@UAA?AW4scFileStatus_t@@ABVidStr@@@Z
// EA  : 0x8269FA10
// RVA : 0x0069FA10
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

scFileStatus_t __fastcall idSourceControlWrapper::GetFileStatus(idSourceControlWrapper *this, const idStr *filename)
{
  if ( this->Init(this) )
    return this->sc->GetFileStatus(this: this->sc, a2: filename);
  else
    return SCF_NOTMANAGED;
}


// ========================================================================
// ?GetFileVersion@idSourceControlWrapper@@UAA_NABVidStr@@AAH1@Z
// EA  : 0x8269FA80
// RVA : 0x0069FA80
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

int __fastcall idSourceControlWrapper::GetFileVersion(
        idSourceControlWrapper *this,
        const idStr *filename,
        int *localVersion,
        int *serverVersion)
{
  if ( this->Init(this) )
    return ((int (__fastcall *)(idSourceControl *, const idStr *, int *, int *))this->sc->GetFileVersion)(
             a1: this->sc,
             a2: filename,
             a3: localVersion,
             a4: serverVersion);
  else
    return 0;
}


// ========================================================================
// ?GetNumCheckOutUsers@idSourceControlWrapper@@UAAHABVidStr@@@Z
// EA  : 0x8269FAF0
// RVA : 0x0069FAF0
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

int __fastcall idSourceControlWrapper::GetNumCheckOutUsers(idSourceControlWrapper *this, const idStr *filename)
{
  if ( this->Init(this) )
    return this->sc->GetNumCheckOutUsers(this: this->sc, a2: filename);
  else
    return 0;
}


// ========================================================================
// ?UpdateFolder@idSourceControlWrapper@@UAAHPBD@Z
// EA  : 0x8269FB60
// RVA : 0x0069FB60
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

int __fastcall idSourceControlWrapper::UpdateFolder(idSourceControlWrapper *this, const char *path)
{
  if ( this->Init(this) )
    return this->sc->UpdateFolder(this: this->sc, a2: path);
  else
    return 0;
}


// ========================================================================
// ?GetCheckOutUser@idSourceControlWrapper@@UAAXABVidStr@@HPADH@Z
// EA  : 0x8269FBD0
// RVA : 0x0069FBD0
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

void __fastcall idSourceControlWrapper::GetCheckOutUser(
        idSourceControlWrapper *this,
        const idStr *filename,
        int userIdx,
        char *userName,
        int maxLen)
{
  if ( this->Init(this) )
    this->sc->GetCheckOutUser(this: this->sc, a2: filename, a3: userIdx, a4: userName, a5: maxLen);
}


// ========================================================================
// ?GetUsernameForFileVersion@idSourceControlWrapper@@UAAXABVidStr@@HAAV2@@Z
// EA  : 0x8269FC38
// RVA : 0x0069FC38
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

void __fastcall idSourceControlWrapper::GetUsernameForFileVersion(
        idSourceControlWrapper *this,
        const idStr *filename,
        int fileVersion,
        idStr *username)
{
  if ( this->Init(this) )
    this->sc->GetUsernameForFileVersion(this: this->sc, a2: filename, a3: fileVersion, a4: username);
}


// ========================================================================
// ?GetCurrentWorkspace@idSourceControlWrapper@@UAAXAAVidSourceControlWorkspace@idSourceControl@@@Z
// EA  : 0x8269FC98
// RVA : 0x0069FC98
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

void __fastcall idSourceControlWrapper::GetCurrentWorkspace(
        idSourceControlWrapper *this,
        idSourceControl::idSourceControlWorkspace *workspace)
{
  if ( this->Init(this) )
    this->sc->GetCurrentWorkspace(this: this->sc, a2: workspace);
}


// ========================================================================
// ?GetAvailableWorkspaces@idSourceControlWrapper@@UAAXAAV?$idList@VidSourceControlWorkspace@idSourceControl@@$04@@@Z
// EA  : 0x8269FD00
// RVA : 0x0069FD00
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

void __fastcall idSourceControlWrapper::GetAvailableWorkspaces(
        idSourceControlWrapper *this,
        struct idList<idSourceControl::idSourceControlWorkspace,5> *workspaces)
{
  if ( this->Init(this) )
    this->sc->GetAvailableWorkspaces(this: this->sc, a2: workspaces);
}


// ========================================================================
// ?SetWorkspace@idSourceControlWrapper@@UAAXAAVidSourceControlWorkspace@idSourceControl@@@Z
// EA  : 0x8269FD68
// RVA : 0x0069FD68
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

void __fastcall idSourceControlWrapper::SetWorkspace(
        idSourceControlWrapper *this,
        idSourceControl::idSourceControlWorkspace *workspace)
{
  if ( this->Init(this) )
    this->sc->SetWorkspace_2(this: this->sc, a2: workspace);
}


// ========================================================================
// ?SetWorkspace@idSourceControlWrapper@@UAAXPBD@Z
// EA  : 0x8269FDD0
// RVA : 0x0069FDD0
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

void __fastcall idSourceControlWrapper::SetWorkspace(idSourceControlWrapper *this, const char *name)
{
  if ( this->Init(this) )
    this->sc->SetWorkspace(this: this->sc, a2: name);
}


// ========================================================================
// ?IsWorkspaceValid@idSourceControlWrapper@@UAA_NXZ
// EA  : 0x8269FE38
// RVA : 0x0069FE38
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

BOOL __fastcall idSourceControlWrapper::IsWorkspaceValid(idSourceControlWrapper *this)
{
  return this->Init(this) && this->sc->IsWorkspaceValid(this: this->sc);
}


// ========================================================================
// ??0idSourceControlWrapper@@QAA@XZ
// EA  : 0x8269FF10
// RVA : 0x0069FF10
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

idSourceControlWrapper *__fastcall idSourceControlWrapper::idSourceControlWrapper(idSourceControlWrapper *this)
{
  this->sc = nullptr;
  this->__vftable = (idSourceControlWrapper_vtbl *)&idSourceControlWrapper::`vftable';
  this->dllHandle = 0;
  *(_WORD *)&this->loadFailed = 1;
  return this;
}


// ========================================================================
// ??1idSourceControlWrapper@@UAA@XZ
// EA  : 0x8269FF40
// RVA : 0x0069FF40
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

void __fastcall idSourceControlWrapper::~idSourceControlWrapper(idSourceControlWrapper *this)
{
  idSourceControl *sc; // r3
  unsigned int dllHandle; // r3

  this->__vftable = (idSourceControlWrapper_vtbl *)&idSourceControlWrapper::`vftable';
  sc = this->sc;
  if ( sc != nullptr )
    sc->Shutdown(this: sc);
  dllHandle = this->dllHandle;
  if ( dllHandle != 0 )
    Sys_DLL_Unload(dllHandle);
  this->dllHandle = 0;
  this->sc = nullptr;
  this->loadFailed = false;
  this->__vftable = (idSourceControlWrapper_vtbl *)&idSourceControl::`vftable';
}


// ========================================================================
// __unwind$219528
// EA  : 0x8269FFCC
// RVA : 0x0069FFCC
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

void _unwind_219528()
{
  int v0; // r12

  idSourceControl::~idSourceControl(this: *(idSourceControl **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetUsername@idSourceControlWrapper@@UAA?AVidStr@@XZ
// EA  : 0x826A0058
// RVA : 0x006A0058
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

idSourceControlWrapper *__fastcall idSourceControlWrapper::GetUsername(idSourceControlWrapper *this, idStr *result)
{
  if ( (*(unsigned __int8 (__fastcall **)(idStr *))(result->len + 4))(a1: result) != 0 )
    (*(void (__fastcall **)(idSourceControlWrapper *))(*(_DWORD *)result->data + 104))(a1: this);
  else
    idStr::idStr((idStr *)this, text: "*unknown*");
  return this;
}


// ========================================================================
// `dynamic initializer for 'com_sourceControl''
// EA  : 0x8333C820
// RVA : 0x0133C820
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_sourceControl__()
{
  idCVar::idCVar(
    this: &com_sourceControl,
    name: "com_sourceControl",
    value: "perforce",
    flags: 0,
    description: "name of the source control dll to load",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_sourceControl__);
}


// ========================================================================
// `dynamic initializer for 'sc_maxVerbosity''
// EA  : 0x8333C878
// RVA : 0x0133C878
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__sc_maxVerbosity__()
{
  idCVar::idCVar(
    this: &sc_maxVerbosity,
    name: "sc_maxVerbosity",
    value: "1",
    flags: 2,
    description: "0 = errors only, 1 = minimal output, 2 = maximum verbosity from perforce api commands",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__sc_maxVerbosity__);
}


// ========================================================================
// `dynamic initializer for 'sc_serverAddress''
// EA  : 0x8333C8D0
// RVA : 0x0133C8D0
// PDB : w:\tech5\engine\framework\sourcecontrolwrapper.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__sc_serverAddress__()
{
  idCVar::idCVar(
    this: &sc_serverAddress,
    name: "sc_serverAddress",
    value: "perforce:1666",
    flags: 0,
    description: "address used to access perforce server",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__sc_serverAddress__);
}

