
// ========================================================================
// ?DetachActiveReadSnapshotFile@idCommonLocal@@UAAPAVidFile@@XZ
// EA  : 0x8265C790
// RVA : 0x0065C790
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

idFile *__fastcall idCommonLocal::DetachActiveReadSnapshotFile(idCommonLocal *this)
{
  idCompressor *compressor; // r3
  idCompressor *compressor2; // r3
  idFile *result; // r3

  compressor = this->ssFileState[0].compressor;
  if ( compressor != nullptr )
    ((void (__fastcall *)(idCompressor *, int))compressor->dtr_idFile)(a1: compressor, a2: 1);
  compressor2 = this->ssFileState[0].compressor2;
  this->ssFileState[0].compressor = nullptr;
  if ( compressor2 != nullptr )
    ((void (__fastcall *)(idCompressor *, int))compressor2->dtr_idFile)(a1: compressor2, a2: 1);
  result = this->ssFileState[0].file;
  this->ssFileState[0].compressor2 = nullptr;
  this->ssFileState[0].file = nullptr;
  return result;
}


// ========================================================================
// ?DetachActiveWriteSnapshotFile@idCommonLocal@@UAAPAVidFile@@XZ
// EA  : 0x8265C818
// RVA : 0x0065C818
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

idFile *__fastcall idCommonLocal::DetachActiveWriteSnapshotFile(idCommonLocal *this)
{
  idCompressor *compressor; // r3
  idCompressor *compressor2; // r3
  idFile *result; // r3

  compressor = this->ssFileState[1].compressor;
  if ( compressor != nullptr )
    ((void (__fastcall *)(idCompressor *, int))compressor->dtr_idFile)(a1: compressor, a2: 1);
  compressor2 = this->ssFileState[1].compressor2;
  this->ssFileState[1].compressor = nullptr;
  if ( compressor2 != nullptr )
    ((void (__fastcall *)(idCompressor *, int))compressor2->dtr_idFile)(a1: compressor2, a2: 1);
  result = this->ssFileState[1].file;
  this->ssFileState[1].compressor2 = nullptr;
  this->ssFileState[1].file = nullptr;
  return result;
}


// ========================================================================
// ?RestartPassMainMenu_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265C8A0
// RVA : 0x0065C8A0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::RestartPassMainMenu_f(const idCmdArgs *args)
{
  commonLocal.game->RestartPassMainMenu(this: commonLocal.game, a2: args);
}


// ========================================================================
// ?IsInGame@idCommonLocal@@UBA_NXZ
// EA  : 0x8265C8C0
// RVA : 0x0065C8C0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

int __fastcall idCommonLocal::IsInGame(idCommonLocal *this)
{
  const idGame *v2; // r3
  bool v3; // r3
  unsigned __int8 v4; // r11

  if ( this->inConsoleCommand )
    return 0;
  if ( this->Game_2(this) == nullptr )
    return 0;
  v2 = this->Game_2(this);
  v3 = v2->IsGameActive(this: (idGame *)v2);
  v4 = 1;
  if ( !v3 )
    return 0;
  return v4;
}


// ========================================================================
// ?SnapshotState@idCommonLocal@@UBA?AW4snapshotState_t@@XZ
// EA  : 0x8265C948
// RVA : 0x0065C948
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

int __fastcall idCommonLocal::SnapshotState(idCommonLocal *this)
{
  idLobbyBase *v2; // r3
  idLobbyBase *v3; // r3
  idLobbyBase *v4; // r3
  idLobbyBase *v5; // r3

  if ( this->ssFileState[0].file != nullptr )
    return 1;
  v2 = session->GetActingGameStateLobbyBase(this: session);
  if ( v2->IsHost(this: v2) == 0 )
  {
    v3 = session->GetActingGameStateLobbyBase(this: session);
    if ( v3->HasActivePeers(this: v3) )
      return 1;
  }
  if ( this->ssFileState[1].file != nullptr )
    return 2;
  v4 = session->GetActingGameStateLobbyBase(this: session);
  if ( v4->IsHost(this: v4) != 0 )
  {
    v5 = session->GetActingGameStateLobbyBase(this: session);
    if ( v5->HasActivePeers(this: v5) )
      return 2;
  }
  return 0;
}


// ========================================================================
// ?IsToolActive@idCommonLocal@@UBA_NXZ
// EA  : 0x8265CA68
// RVA : 0x0065CA68
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

BOOL __fastcall idCommonLocal::IsToolActive(idCommonLocal *this)
{
  return com_editors != 0;
}


// ========================================================================
// ?LeaveGame_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265CA80
// RVA : 0x0065CA80
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::LeaveGame_f(const idCmdArgs *args)
{
  idLobbyBase *v1; // r3

  v1 = session->GetActingGameStateLobbyBase(this: session);
  if ( v1->IsHost(this: v1) != 0 )
    session->EndMatch(this: session, a2: false);
}


// ========================================================================
// ?QueueSnapshotMemFile@idCommonLocal@@UAAXPAVidFile_Memory@@I@Z
// EA  : 0x8265CAF0
// RVA : 0x0065CAF0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::QueueSnapshotMemFile(idCommonLocal *this, idFile_Memory *file, unsigned int tag)
{
  this->queuedSnapshotFile = file;
  this->queuedSnapshotFileTag = tag;
}


// ========================================================================
// ?ClearQueuedSnapshotFile@idCommonLocal@@UAAXXZ
// EA  : 0x8265CB00
// RVA : 0x0065CB00
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::ClearQueuedSnapshotFile(idCommonLocal *this)
{
  this->queuedSnapshotFile = nullptr;
  this->queuedSnapshotFileTag = 0;
}


// ========================================================================
// ?PlayQueuedSnapshotFile@idCommonLocal@@UAAXXZ
// EA  : 0x8265CB10
// RVA : 0x0065CB10
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::PlayQueuedSnapshotFile(idCommonLocal *this)
{
  this->PlaySnapshotFile(this, a2: this->queuedSnapshotFile, a3: this->queuedSnapshotFileTag);
  this->ClearQueuedSnapshotFile(this);
}


// ========================================================================
// ?CloseSnapshotFiles@idCommonLocal@@UAAXXZ
// EA  : 0x8265CB68
// RVA : 0x0065CB68
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::CloseSnapshotFiles(idCommonLocal *this)
{
  idGame *v2; // r3

  if ( this->demoMode != DEMO_NONE )
  {
    this->StopSnapshotFilePlayback(this);
    this->StopSnapshotFileRecord(this);
    v2 = this->Game(this);
    v2->OnCloseSnapshot(this: v2);
  }
}


// ========================================================================
// ?GetProfileFromMasterLocalUser@idCommonLocal@@UAAPAVidPlayerProfile@@XZ
// EA  : 0x8265CBE8
// RVA : 0x0065CBE8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::GetProfileFromMasterLocalUser(idCommonLocal *this)
{
  if ( session->GetProfileFromMasterLocalUser(this: session) == nullptr )
    idLib::Error(fmt: "MasterLocalUser profile is NULL");
}


// ========================================================================
// ?StopDemo_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265CC30
// RVA : 0x0065CC30
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::StopDemo_f(const idCmdArgs *args)
{
  idCommonLocal::CloseSnapshotFiles(this: &commonLocal);
}


// ========================================================================
// WaitOnSession
// EA  : 0x8265CD88
// RVA : 0x0065CD88
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall WaitOnSession(
        idSession::sessionState_t waitingOnState,
        double pacifierProgress,
        pacifierState_t pacifierState,
        int a4)
{
  int v7; // r4
  idSession::sessionState_t v8; // r3
  const char *v9; // r31
  const char *v10; // r3
  __int64 v11; // r8
  __int64 v12; // r10
  va *v13; // r3
  int v14; // [sp+8h] [-1098h]
  int v15; // [sp+Ch] [-1094h]
  int v16; // [sp+10h] [-1090h]
  int v17; // [sp+14h] [-108Ch]
  int v18; // [sp+18h] [-1088h]
  int v19; // [sp+1Ch] [-1084h]
  _BYTE v20[16]; // [sp+50h] [-1050h] BYREF
  va v21; // [sp+60h] [-1040h] BYREF

  while ( session->GetState(this: session) != waitingOnState )
  {
    if ( pacifierProgress < 0.0 )
    {
      session->UpdateSignInManager(this: session);
      session->Pump(this: session);
      session->ProcessSnapAckQueue(this: session);
    }
    else
    {
      ((void (__fastcall *)(idCommon *, int, int, int, int, double))common->UpdateLevelLoadPacifier)(
        a1: common,
        a2: v7,
        a3: a4,
        a4: 1,
        a5: 1,
        a6: pacifierProgress);
    }
    mgthread_sleep(ms: 10);
    v8 = session->GetState(this: session);
    if ( v8 != (PARTY_LOBBY|SEARCHING) && v8 != SEARCHING && v8 != CONNECTING && v8 != BUSY && v8 != waitingOnState )
    {
      v9 = session->GetStateString_2(this: session, a2: waitingOnState);
      v10 = session->GetStateString(this: session);
      HIDWORD(v11) = &unk_821D0000;
      v13 = va::va(
              this: &v21,
              fmt: "WaitOnSession: Invalid state (%s) while waiting on state (%s).",
              a3: __SPAIR64__((unsigned int)v10, (unsigned int)v9),
              a4: v11,
              a5: v12,
              a6: v14,
              a7: v15,
              a8: v16,
              a9: v17,
              a10: v18,
              a11: v19);
      strncpy(dest: idException::error, source: v13->buffer, count: 0x800u);
      CxxThrowException(pExceptionObject: v20, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidNetworkLoadException__);
    }
  }
}


// ========================================================================
// ?RestartLoadGame_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265CF30
// RVA : 0x0065CF30
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::RestartLoadGame_f(const idCmdArgs *args)
{
  int argc; // r11
  int v3; // r31
  char **argv; // r30
  const char *v5; // r6
  idGame *v6; // r3

  if ( args->argc == 3 )
  {
    idLib::PrintfIf(condition: discSwapper_verbose.valueInteger != 0, fmt: "[%s]:", "idCommonLocal::RestartLoadGame_f");
    argc = args->argc;
    v3 = 0;
    if ( args->argc > 0 )
    {
      argv = args->argv;
      do
      {
        if ( v3 < 0 || v3 >= argc )
          v5 = &byte_8200D768;
        else
          v5 = *argv;
        idLib::PrintfIf(condition: discSwapper_verbose.valueInteger != 0, fmt: "\targs[%d] = %s\n", v3, v5);
        argc = args->argc;
        ++v3;
        ++argv;
      }
      while ( v3 < args->argc );
    }
    if ( idDiscSwapManager::RebuildStateAfterSwap(this: discSwapMgr, command: DSC_LOAD, args) )
    {
      v6 = common->Game(this: common);
      v6->LoadGame(this: v6, a2: discSwapMgr->savegameFile.data);
    }
  }
  else
  {
    idLib::Warning(fmt: "syntax: restart_loadGame <swapSerializedUser> <savegame>");
  }
}


// ========================================================================
// ?RestartMapAfterSwap_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265D050
// RVA : 0x0065D050
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::RestartMapAfterSwap_f(const idCmdArgs *args)
{
  int argc; // r11
  int v3; // r31
  char **argv; // r30
  const char *v5; // r6

  idLib::PrintfIf(
    condition: discSwapper_verbose.valueInteger != 0,
    fmt: "[%s]:",
    "idCommonLocal::RestartMapAfterSwap_f");
  argc = args->argc;
  v3 = 0;
  if ( args->argc > 0 )
  {
    argv = args->argv;
    do
    {
      if ( v3 < 0 || v3 >= argc )
        v5 = &byte_8200D768;
      else
        v5 = *argv;
      idLib::PrintfIf(condition: discSwapper_verbose.valueInteger != 0, fmt: "\targs[%d] = %s\n", v3, v5);
      argc = args->argc;
      ++v3;
      ++argv;
    }
    while ( v3 < args->argc );
  }
  if ( idDiscSwapManager::RebuildStateAfterSwap(this: discSwapMgr, command: DSC_MAP, args)
    && idDiscSwapManager::Swap(this: discSwapMgr, command: DSC_MAP, forceDiscNumber: 0) == DSE_OK )
  {
    cmdSystem->AppendCommandText(this: cmdSystem, a2: discSwapMgr->additionalArguments.data);
    cmdSystem->ExecuteCommandBuffer(this: cmdSystem);
  }
}


// ========================================================================
// ?RestartMultiplayerInvite_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265D168
// RVA : 0x0065D168
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::RestartMultiplayerInvite_f(const idCmdArgs *args)
{
  if ( args->argc == 2 )
  {
    idLib::Printf(fmt: "Restarting with multiplayer invite\n");
    idDiscSwapManager::Reset(this: discSwapMgr);
    if ( idDiscSwapManager::RebuildStateAfterSwap(this: discSwapMgr, command: DSC_MULTIPLAYER_INVITE, args)
      && idDiscSwapManager::Swap(this: discSwapMgr, command: DSC_MULTIPLAYER_INVITE, forceDiscNumber: 3) == DSE_OK )
    {
      session->JoinAfterSwap(this: session, a2: &discSwapMgr->inviteInfo);
    }
  }
  else
  {
    idLib::Warning(fmt: "syntax: RestartMultiplayerInvite_f <swapDat_invite_stuff>");
  }
}


// ========================================================================
// ?NextMap_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265D220
// RVA : 0x0065D220
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::NextMap_f(const idCmdArgs *args)
{
  if ( commonLocal.game->IsGameActive(this: commonLocal.game) )
  {
    if ( args->argc == 7 )
      commonLocal.game->NextMap(this: commonLocal.game, a2: args);
    else
      idLib::Printf(
        fmt: "syntax: nextMap <shouldWeSave - 0, 1> <mapnameTarget> <spawnspotTarget> <saveSpawnInCurrentMap> <layersActive> <"
        "layersDeactive>\n");
  }
  else
  {
    idLib::Printf(fmt: "nextMap only works if a map is running!");
  }
}


// ========================================================================
// ?PrepareForMapChange@idCommonLocal@@QAAXXZ
// EA  : 0x8265D2C0
// RVA : 0x0065D2C0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::PrepareForMapChange(idCommonLocal *this)
{
  int i; // r31
  idJoystick *v3; // r3
  int v4; // r31
  int v5; // r30
  idMouse *v6; // r3

  this->CloseSnapshotFiles(this);
  if ( idLib::production == PROD_LOADED )
    idLib::production = PROD_PRODUCTION;
  console->Close(this: console, a2: true);
  cvarSystem->ReportModifiedCVars(this: cvarSystem);
  soundSystem->SetPlayingSoundWorld(this: soundSystem, a2: nullptr);
  for ( i = 0; i < 4; ++i )
  {
    v3 = sys->Joystick(this: sys);
    v3->SetRumble(this: v3, a2: i, a3: 0, a4: 0);
  }
  idRenderManager::Clear(this: &renderManager);
  gameSystem->FreeGame(this: gameSystem, a2: &this->game);
  v4 = 0;
  if ( this->mapChangeListeners.num > 0 )
  {
    v5 = 0;
    do
    {
      this->mapChangeListeners.list[v5]->MapDisconnected(this: this->mapChangeListeners.list[v5]);
      ++v4;
      ++v5;
    }
    while ( v4 < this->mapChangeListeners.num );
  }
  v6 = sys->Mouse(this: sys);
  v6->GrabCursor(this: v6, a2: false);
}


// ========================================================================
// ?StartNewMatch@idCommonLocal@@QAAXABVidMatchParameters@@@Z
// EA  : 0x8265D428
// RVA : 0x0065D428
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::StartNewMatch(idCommonLocal *this, const idMatchParameters *matchParms)
{
  pacifierState_t v3; // r4
  pacifierState_t v4; // r4

  session->ClearSessionOption(this: session, a2: OPTION_ALL);
  session->CreateMatch(this: session, a2: matchParms);
  WaitOnSession(waitingOnState: GAME_LOBBY, pacifierProgress: -1.0, pacifierState: v3, a4: 0);
  session->StartMatch(this: session);
  WaitOnSession(waitingOnState: PARTY_LOBBY|SEARCHING, pacifierProgress: -1.0, pacifierState: v4, a4: 0);
}


// ========================================================================
// ?StopSnapshotFileRecord@idCommonLocal@@UAAXXZ
// EA  : 0x8265D4D0
// RVA : 0x0065D4D0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::StopSnapshotFileRecord(idCommonLocal *this)
{
  unsigned __int64 v1; // r30
  idCompressor *compressor; // r3
  idCompressor *compressor2; // r3
  idFile *file; // r3
  idSnapShot *ss; // r29

  compressor = this->ssFileState[1].compressor;
  LODWORD(v1) = 0;
  this->snapPrevious.localTime = -1;
  this->snapCurrent.localTime = -1;
  this->snapPrevious.serverTime = -1;
  this->snapCurrent.serverTime = -1;
  this->snapTimeWrite = v1;
  if ( compressor != nullptr )
    ((void (__fastcall *)(idCompressor *, int))compressor->dtr_idFile)(a1: compressor, a2: 1);
  compressor2 = this->ssFileState[1].compressor2;
  this->ssFileState[1].compressor = nullptr;
  if ( compressor2 != nullptr )
    ((void (__fastcall *)(idCompressor *, int))compressor2->dtr_idFile)(a1: compressor2, a2: 1);
  file = this->ssFileState[1].file;
  this->ssFileState[1].compressor2 = nullptr;
  if ( file != nullptr )
    ((void (__fastcall *)(idFile *, int))file->dtr_idFile)(a1: file, a2: 1);
  ss = this->ssFileState[1].ss;
  this->ssFileState[1].file = nullptr;
  if ( ss != nullptr )
  {
    idSnapShot::~idSnapShot(this: ss);
    idMem::Free(this: &mem, ptr: ss, align: ALIGN_16);
  }
  this->ssFileState[1].ss = nullptr;
  this->ssFileState[1].resources = 0;
  this->demoMode = !this->TimeTrialPlaying(this) ? DEMO_NONE : DEMO_TIMETRIAL;
}


// ========================================================================
// ?ResetNetworkingState@idCommonLocal@@QAAXXZ
// EA  : 0x8265D5D0
// RVA : 0x0065D5D0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::ResetNetworkingState(idCommonLocal *this, int a2, int a3, int a4, unsigned __int64 a5)
{
  unsigned __int64 v5; // r29
  idArray<idSnapShot,16> *p_receivedSnaps; // r28
  int v8; // r30
  unsigned __int8 *p_vehicleThrottle; // r10
  int i; // ctr
  int *v11; // r11
  int j; // ctr

  LODWORD(v5) = 0;
  LODWORD(a5) = 100000;
  this->snapTime = v5;
  this->snapCurrentResidual = 0.0;
  this->snapTimeWrite = v5;
  this->snapTimeBuffered = 0.0;
  this->snapCurrentTime = v5;
  this->effectiveSnapRate = 0.0;
  this->totalBufferedTime = 0;
  this->optimalTimeBuffered = 0.0;
  p_receivedSnaps = &this->receivedSnaps;
  this->optimalPCTBuffer = 0.5;
  this->totalRecvTime = 0;
  this->optimalTimeBufferedWindow = 0.0;
  v8 = 16;
  this->readSnapshotIndex = 0;
  this->writeSnapshotIndex = 0;
  this->userCmdFrame = 0;
  this->snapRate = a5;
  do
  {
    idSnapShot::Clear(this: p_receivedSnaps->ptr);
    --v8;
    p_receivedSnaps = (idArray<idSnapShot,16> *)((char *)p_receivedSnaps + 52);
  }
  while ( v8 != 0 );
  memset(Dst: &this->userCmdMgr, Val: 0, Size: 0xB400u);
  p_vehicleThrottle = &this->userCmdMgr.cmdBuffer[127][5].vehicleThrottle;
  for ( i = 6; i != 0; --i )
  {
    p_vehicleThrottle += 4;
    *(_DWORD *)p_vehicleThrottle = 0;
  }
  v11 = &this->userCmdMgr.writeFrame[5];
  for ( j = 6; j != 0; --j )
    *++v11 = -1;
  this->snapCurrent.localTime = -1;
  this->snapPrevious.localTime = -1;
  this->snapCurrent.serverTime = -1;
  this->snapPrevious.serverTime = -1;
  idSnapShot::Clear(this: &this->oldss);
  idResourceList::ResetNetworkResources();
}


// ========================================================================
// ?GetMasterLocalUserInputDevice@idCommonLocal@@UBAHXZ
// EA  : 0x8265D6D0
// RVA : 0x0065D6D0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

int __fastcall idCommonLocal::GetMasterLocalUserInputDevice(idCommonLocal *this)
{
  idSignInManagerBase *signInManager; // r31
  const idLocalUser *MasterLocalUser; // r3

  signInManager = session->signInManager;
  if ( idSignInManagerBase::GetMasterLocalUser(this: signInManager) == nullptr )
    return -1;
  MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: signInManager);
  return MasterLocalUser->GetInputDevice(this: (idLocalUser *)MasterLocalUser);
}


// ========================================================================
// ?GetMasterLocalUserPlayerId@idCommonLocal@@UBAHXZ
// EA  : 0x8265D740
// RVA : 0x0065D740
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

int __fastcall idCommonLocal::GetMasterLocalUserPlayerId(idCommonLocal *this)
{
  idSignInManagerBase *signInManager; // r30
  const idLocalUser *MasterLocalUser; // r3
  int v4; // r30
  const idGame *v5; // r3
  int v6; // r3

  signInManager = session->signInManager;
  if ( idSignInManagerBase::GetMasterLocalUser(this: signInManager) != nullptr )
  {
    MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: signInManager);
    v4 = MasterLocalUser->GetInputDevice(this: (idLocalUser *)MasterLocalUser);
  }
  else
  {
    v4 = -1;
  }
  v5 = this->Game_2(this);
  v6 = v5->GetPlayerIndexFromInputDevice(this: (idGame *)v5, a2: v4);
  return v6 == -1 ? 0 : v6;
}


// ========================================================================
// ?GetMasterLocalUser@idCommonLocal@@UBAPAVidLocalUser@@XZ
// EA  : 0x8265D7E8
// RVA : 0x0065D7E8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

idLocalUser *__fastcall idCommonLocal::GetMasterLocalUser(idCommonLocal *this)
{
  return idSignInManagerBase::GetMasterLocalUser(this: session->signInManager);
}


// ========================================================================
// ?ResetPlayerInput@idCommonLocal@@UAAXH@Z
// EA  : 0x8265D7F8
// RVA : 0x0065D7F8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::ResetPlayerInput(idCommonLocal *this, int playerIndex)
{
  idUserCmdMgr::ResetPlayer(this: &this->userCmdMgr, playerIndex);
}


// ========================================================================
// ?UpdateBotUserCmds@idCommonLocal@@UAAXHABVusercmd_t@@@Z
// EA  : 0x8265D800
// RVA : 0x0065D800
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::UpdateBotUserCmds(idCommonLocal *this, int botPlayerIndex, const usercmd_t *cmds)
{
  idUserCmdMgr::PutUserCmdForPlayer(this: &this->userCmdMgr, playerIndex: botPlayerIndex, cmd: cmds);
}


// ========================================================================
// ?CompressFile_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265D810
// RVA : 0x0065D810
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
void __fastcall idCommonLocal::CompressFile_f(const idCmdArgs *args)
{
  __int64 v1; // r28
  int *v2; // r30
  __int64 v3; // r3
  int v4; // r9
  const char *v5; // r4
  idFile *v6; // r29
  const char *v7; // r4
  idFile *v8; // r25
  idCompressor *v9; // r30
  int v10; // r23
  double clockTicks; // fp31
  __int128 v12; // r4
  int v13[4]; // [sp+50h] [-100B0h] BYREF
  idStr v14; // [sp+60h] [-100A0h] BYREF
  idTimer v15; // [sp+80h] [-10080h] BYREF
  _BYTE v16[65536]; // [sp+A0h] [-10060h] BYREF

  LODWORD(v1) = 0;
  v14.len = 0;
  v14.allocedAndFlag = 20;
  v2 = (int *)((int (*)(void))RtlCheckStack12)();
  v14.data = v14.baseBuffer;
  v14.baseBuffer[0] = 0;
  v15.clockTicks = v1;
  v15.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  v15.state = TS_STARTED;
  LODWORD(v3) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  v4 = *v2;
  v15.start = v3;
  if ( v4 <= 1 )
    v5 = &byte_8200D768;
  else
    v5 = (const char *)v2[2];
  v6 = fileSystem->OpenFileRead(this: fileSystem, a2: v5, a3: 1, a4: 0);
  if ( v6 != nullptr )
  {
    if ( *v2 <= 1 )
      v7 = &byte_8200D768;
    else
      v7 = (const char *)v2[2];
    idStr::operator=(this: &v14, text: v7);
    idStr::SetFileExtension(this: &v14, extension: "zid");
    v8 = fileSystem->OpenFileWrite(this: fileSystem, a2: v14.data, a3: 2);
    if ( v8 != nullptr )
    {
      HIDWORD(v1) = idCompressor::AllocArithmetic();
      (*(void (__fastcall **)(_DWORD, idFile *, int, int))(*(_DWORD *)HIDWORD(v1) + 88))(
        a1: HIDWORD(v1),
        a2: v8,
        a3: 1,
        a4: 8);
      v9 = idCompressor::AllocLZSS_ByteAligned();
      v9->Init(this: v9, a2: (idFile *)HIDWORD(v1), a3: true, a4: 8);
      v10 = v6->Length(this: v6);
      v13[0] = v10;
      idFile::WriteLittle<int>(this: v9, c: v13);
      if ( v10 - 0x10000 > 0 )
      {
        do
        {
          v6->Read(this: v6, a2: v16, a3: 0x10000u);
          v9->Write(this: v9, a2: v16, a3: 0x10000u);
          LODWORD(v1) = v1 + 0x10000;
        }
        while ( (int)v1 < v10 - 0x10000 );
      }
      LODWORD(v1) = v10 - v1;
      v6->Read(this: v6, a2: v16, a3: v1);
      v9->Write(this: v9, a2: v16, a3: v1);
      ((void (__fastcall *)(idCompressor *, int))v9->dtr_idFile)(a1: v9, a2: 1);
      (**(void (__fastcall ***)(_DWORD, int))HIDWORD(v1))(a1: HIDWORD(v1), a2: 1);
      ((void (__fastcall *)(idFile *, int))v8->dtr_idFile)(a1: v8, a2: 1);
      ((void (__fastcall *)(idFile *, int))v6->dtr_idFile)(a1: v6, a2: 1);
      idTimer::Stop(this: &v15);
      clockTicks = (float)v15.clockTicks;
      DWORD2(v12) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
      *(_QWORD *)v13 = *(_QWORD *)((char *)&v12 + 4);
      *((double *)&v12 + 1) = (float)((float)clockTicks / (float)((float)*(__int64 *)((char *)&v12 + 4) * (float)0.001));
      idLib::Printf(fmt: (const char *)DWORD2(v12), (_DWORD)v12);
      v15.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
    }
    else
    {
      v15.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
    }
  }
  else
  {
    v15.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  }
  idStr::FreeData(this: &v14);
}


// ========================================================================
// __unwind$232410
// EA  : 0x8265DAE8
// RVA : 0x0065DAE8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_232410()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$232411
// EA  : 0x8265DB10
// RVA : 0x0065DB10
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_232411()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(v0 - 256 + 128));
}


// ========================================================================
// ?DecompressFile_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265DB40
// RVA : 0x0065DB40
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
void __fastcall idCommonLocal::DecompressFile_f(const idCmdArgs *args)
{
  __int64 v1; // r28
  int *v2; // r30
  __int64 v3; // r3
  int v4; // r9
  const char *v5; // r4
  idFile *v6; // r29
  const char *v7; // r4
  idFile *v8; // r25
  idCompressor *v9; // r30
  int v10; // r11
  double clockTicks; // fp31
  __int128 v12; // r4
  int v13[4]; // [sp+50h] [-100B0h] BYREF
  idStr v14; // [sp+60h] [-100A0h] BYREF
  idTimer v15; // [sp+80h] [-10080h] BYREF
  __int64 v16; // [sp+A0h] [-10060h]
  _BYTE v17[65536]; // [sp+B0h] [-10050h] BYREF

  LODWORD(v1) = 0;
  v14.len = 0;
  v14.allocedAndFlag = 20;
  v2 = (int *)((int (*)(void))RtlCheckStack12)();
  v14.data = v14.baseBuffer;
  v14.baseBuffer[0] = 0;
  v15.clockTicks = v1;
  v15.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  v15.state = TS_STARTED;
  LODWORD(v3) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  v4 = *v2;
  v15.start = v3;
  if ( v4 <= 1 )
    v5 = &byte_8200D768;
  else
    v5 = (const char *)v2[2];
  idStr::operator=(this: &v14, text: v5);
  idStr::SetFileExtension(this: &v14, extension: "zid");
  v6 = fileSystem->OpenFileRead(this: fileSystem, a2: v14.data, a3: 1, a4: 0);
  if ( v6 != nullptr )
  {
    if ( *v2 <= 1 )
      v7 = &byte_8200D768;
    else
      v7 = (const char *)v2[2];
    v8 = fileSystem->OpenFileWrite(this: fileSystem, a2: v7, a3: 2);
    if ( v8 != nullptr )
    {
      HIDWORD(v1) = idCompressor::AllocArithmetic();
      (*(void (__fastcall **)(_DWORD, idFile *, _DWORD, int))(*(_DWORD *)HIDWORD(v1) + 88))(
        a1: HIDWORD(v1),
        a2: v6,
        a3: 0,
        a4: 8);
      v9 = idCompressor::AllocLZSS_ByteAligned();
      v9->Init(this: v9, a2: (idFile *)HIDWORD(v1), a3: false, a4: 8);
      idFile::ReadLittle<float>(this: v9, c: v13);
      v10 = v13[0];
      if ( v13[0] - 0x10000 > 0 )
      {
        do
        {
          v6->Read(this: v6, a2: v17, a3: 0x10000u);
          v9->Write(this: v9, a2: v17, a3: 0x10000u);
          v10 = v13[0];
          LODWORD(v1) = v1 + 0x10000;
        }
        while ( (int)v1 < v13[0] - 0x10000 );
      }
      v6->Read(this: v6, a2: v17, a3: v10 - v1);
      v9->Write(this: v9, a2: v17, a3: v13[0] - v1);
      ((void (__fastcall *)(idCompressor *, int))v9->dtr_idFile)(a1: v9, a2: 1);
      (**(void (__fastcall ***)(_DWORD, int))HIDWORD(v1))(a1: HIDWORD(v1), a2: 1);
      ((void (__fastcall *)(idFile *, int))v8->dtr_idFile)(a1: v8, a2: 1);
      ((void (__fastcall *)(idFile *, int))v6->dtr_idFile)(a1: v6, a2: 1);
      idTimer::Stop(this: &v15);
      clockTicks = (float)v15.clockTicks;
      DWORD2(v12) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
      v16 = *(_QWORD *)((char *)&v12 + 4);
      *((double *)&v12 + 1) = (float)((float)clockTicks / (float)((float)*(__int64 *)((char *)&v12 + 4) * (float)0.001));
      idLib::Printf(fmt: (const char *)DWORD2(v12), (_DWORD)v12);
      v15.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
    }
    else
    {
      v15.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
    }
  }
  else
  {
    v15.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  }
  idStr::FreeData(this: &v14);
}


// ========================================================================
// __unwind$232531
// EA  : 0x8265DE08
// RVA : 0x0065DE08
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_232531()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$232532
// EA  : 0x8265DE30
// RVA : 0x0065DE30
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_232532()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(v0 - 256 + 128));
}


// ========================================================================
// ?Hitch_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265DE58
// RVA : 0x0065DE58
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::Hitch_f(const idCmdArgs *args)
{
  idSoundWorld *v2; // r29
  int v3; // r3

  v2 = soundSystem->GetPlayingSoundWorld(this: soundSystem);
  if ( v2 != nullptr )
  {
    soundSystem->SetMute(this: soundSystem, a2: true);
    Sys_MutexLock(handle: &mutexHitch.handle, blocking: true);
  }
  if ( args->argc == 2 )
    v3 = atol(nptr: args->argv[1]);
  else
    v3 = 100;
  mgthread_sleep(ms: v3);
  if ( v2 != nullptr )
  {
    Sys_MutexUnlock(handle: &mutexHitch.handle);
    soundSystem->SetMute(this: soundSystem, a2: false);
  }
}


// ========================================================================
// ?UpdateConsoleDisplay@idCommonLocal@@UAAX_N@Z
// EA  : 0x8265DF08
// RVA : 0x0065DF08
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::UpdateConsoleDisplay(idCommonLocal *this, bool drawGameGui)
{
  idMouse *v3; // r3

  if ( idLib::production != PROD_BUILDING
    && com_production.valueInteger <= 0
    && ((unsigned __int8 (__fastcall *)(idConsole *, bool))console->IsInitialized)(a1: console, a2: drawGameGui) != 0
    && !this->insideUpdateScreen )
  {
    this->insideUpdateScreen = true;
    v3 = sys->Mouse(this: sys);
    v3->GrabCursor(this: v3, a2: false);
    sys->GenerateEvents(this: sys);
    idRenderManager::UpdateConsole(this: &renderManager);
    soundSystem->Render(this: soundSystem, a2: false);
    this->insideUpdateScreen = false;
  }
}


// ========================================================================
// ?LoadGame_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265E308
// RVA : 0x0065E308
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::LoadGame_f(const idCmdArgs *args)
{
  const char *v1; // r4
  const char *v2; // r3
  idStr v3; // [sp+50h] [-40h] BYREF

  if ( args->argc <= 1 )
    v1 = &byte_8200D768;
  else
    v1 = args->argv[1];
  idStr::idStr(this: &v3, text: v1);
  if ( v3.len == 0 )
  {
    v2 = session->GetCurrentSaveSlot(this: session);
    idStr::operator=(this: &v3, text: v2);
  }
  idCVar::SetString(this: &si_spawnspot, newValue: &byte_8200D768, force: true);
  commonLocal.game->LoadGame(this: commonLocal.game, a2: v3.data);
  idStr::FreeData(this: &v3);
}


// ========================================================================
// __unwind$233729
// EA  : 0x8265E3CC
// RVA : 0x0065E3CC
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_233729()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?SaveGame_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265E400
// RVA : 0x0065E400
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::SaveGame_f(const idCmdArgs *args)
{
  const char *v1; // r4
  const char *v2; // r3
  idStr v3; // [sp+50h] [-30h] BYREF

  if ( args->argc <= 1 )
    v1 = &byte_8200D768;
  else
    v1 = args->argv[1];
  idStr::idStr(this: &v3, text: v1);
  if ( v3.len == 0 )
  {
    v2 = session->GetCurrentSaveSlot(this: session);
    idStr::operator=(this: &v3, text: v2);
  }
  commonLocal.game->SaveGame(this: commonLocal.game, a2: v3.data, a3: true, a4: false);
  idStr::FreeData(this: &v3);
}


// ========================================================================
// __unwind$233768
// EA  : 0x8265E4AC
// RVA : 0x0065E4AC
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_233768()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 128 + 80));
}


// ========================================================================
// ?RecordSnapshotFile@idCommonLocal@@UAAXPAVidFile@@I@Z
// EA  : 0x8265E4E0
// RVA : 0x0065E4E0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::RecordSnapshotFile(
        idCommonLocal *this,
        idFile *file,
        unsigned int tag,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        unsigned int a16)
{
  const char *v18; // r3
  idGame *v19; // r3
  int v20; // r3
  unsigned __int64 v21; // r24
  idLobbyBase *v22; // r3
  idLobbyBase *v23; // r3
  idCommonLocal::demoMode_t v24; // r11
  idSnapShot *v25; // r3
  idSnapShot *v26; // r3
  idCompressor *v27; // r3
  idCompressor *v28; // r3
  idGame *v29; // r3
  int v30; // r29
  idCompressor *compressor; // r3
  int v32; // r27
  int v33; // r26
  idCompressor *v34; // r25
  unsigned int *v35; // r28
  char v36; // r8
  char v37; // r10
  idCompressor *v38; // r3
  _DWORD *v39; // r26
  int v40; // r27
  int v41; // r28
  _DWORD *v42; // r25
  idCompressor *v43; // r22
  unsigned int *v44; // r29
  char v45; // r10
  char v46; // r7
  idLobbyBase *v47; // r3
  const idMatchParameters *v48; // r29
  idCompressor *v49; // r3
  unsigned int v50; // [sp+50h] [-80h] BYREF
  unsigned int v51; // [sp+54h] [-7Ch] BYREF
  int v52; // [sp+58h] [-78h] BYREF
  int v53; // [sp+5Ch] [-74h] BYREF
  int gameMap; // [sp+60h] [-70h] BYREF
  _DWORD v55[27]; // [sp+64h] [-6Ch] BYREF

  a16 = tag;
  if ( file == nullptr )
    idLib::Error(fmt: "Snapshot record failed because of NULL file.");
  v18 = file->GetName(this: file);
  idLib::Printf(fmt: "Recording %s\n", v18);
  v19 = this->Game(this);
  v20 = (int)v19->GetRenderWorld(this: v19);
  (*(void (__fastcall **)(int))(*(_DWORD *)v20 + 168))(a1: v20);
  HIDWORD(v21) = &joystick.joyAxis[0][2];
  if ( a16 == 1145392463 )
  {
    v22 = session->GetActingGameStateLobbyBase(this: session);
    if ( v22->IsHost(this: v22) != 0
      || (v23 = session->GetActingGameStateLobbyBase(this: session), !v23->HasActivePeers(this: v23)) )
    {
      v24 = DEMO_RECORD;
    }
    else
    {
      v24 = DEMO_RECORD_CLIENT;
    }
  }
  else
  {
    v24 = DEMO_TIMETRIAL;
  }
  this->demoMode = v24;
  v25 = (idSnapShot *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x34u,
                        tag: TAG_NETWORKING,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v55[1] = v25;
  LODWORD(v21) = 0;
  if ( v25 != nullptr )
    v26 = idSnapShot::idSnapShot(this: v25);
  else
    v26 = nullptr;
  this->ssFileState[1].ss = v26;
  this->ssFileState[1].file = file;
  this->ssFileState[1].resources = 0;
  v27 = idCompressor::AllocLZW();
  this->ssFileState[1].compressor2 = v27;
  v27->Init(this: v27, a2: this->ssFileState[1].file, a3: true, a4: 8);
  v28 = idCompressor::AllocRunLength_ZeroBased();
  this->ssFileState[1].compressor = v28;
  v28->Init(this: v28, a2: this->ssFileState[1].compressor2, a3: true, a4: 8);
  this->ssFileState[1].compressor->Write(this: this->ssFileState[1].compressor, a2: &a16, a3: 4u);
  this->ssFileState[1].compressor->Write(this: this->ssFileState[1].compressor, a2: &DEMO_VERSION, a3: 4u);
  v29 = this->Game(this);
  v30 = (int)v29->GetGameSpawnInfo(this: v29);
  idFile::WriteString(this: this->ssFileState[1].compressor, string: (const idStr *)(v30 + 4));
  idFile::WriteString(this: this->ssFileState[1].compressor, string: (const idStr *)(v30 + 85136));
  this->ssFileState[1].compressor->Write(this: this->ssFileState[1].compressor, a2: (const void *)(v30 + 86192), a3: 4u);
  this->ssFileState[1].compressor->Write(this: this->ssFileState[1].compressor, a2: (const void *)(v30 + 85124), a3: 1u);
  this->ssFileState[1].compressor->Write(this: this->ssFileState[1].compressor, a2: (const void *)(v30 + 85125), a3: 1u);
  this->ssFileState[1].compressor->Write(this: this->ssFileState[1].compressor, a2: (const void *)(v30 + 85132), a3: 4u);
  compressor = this->ssFileState[1].compressor;
  v52 = *(_DWORD *)(v30 + 3176);
  compressor->Write(this: compressor, a2: &v52, a3: 4u);
  v32 = 0;
  if ( *(int *)(v30 + 3176) > 0 )
  {
    v33 = 0;
    do
    {
      v34 = this->ssFileState[1].compressor;
      v35 = (unsigned int *)(v33 + *(_DWORD *)(v30 + 3172));
      v50 = *v35;
      v36 = BYTE1(v50);
      v37 = HIBYTE(v50);
      BYTE1(v50) = BYTE2(v50);
      HIBYTE(v50) = v50;
      LOBYTE(v50) = v37;
      BYTE2(v50) = v36;
      v34->Write(this: v34, a2: &v50, a3: 4u);
      v34->Write(this: v34, a2: (const void *)v35[1], a3: *v35);
      ++v32;
      v33 += 160;
    }
    while ( v32 < *(_DWORD *)(v30 + 3176) );
  }
  v38 = this->ssFileState[1].compressor;
  v39 = (_DWORD *)(v30 + 44152);
  v53 = *(_DWORD *)(v30 + 44152);
  v38->Write(this: v38, a2: &v53, a3: 4u);
  v40 = 0;
  if ( *(int *)(v30 + 44152) > 0 )
  {
    v41 = 0;
    v42 = (_DWORD *)(v30 + 44148);
    do
    {
      v43 = this->ssFileState[1].compressor;
      v44 = (unsigned int *)(*v42 + v41);
      v51 = *v44;
      v45 = BYTE1(v51);
      v46 = HIBYTE(v51);
      BYTE1(v51) = BYTE2(v51);
      BYTE2(v51) = v45;
      HIBYTE(v51) = v51;
      LOBYTE(v51) = v46;
      v43->Write(this: v43, a2: &v51, a3: 4u);
      v43->Write(this: v43, a2: (const void *)v44[1], a3: *v44);
      ++v40;
      v41 += 160;
    }
    while ( v40 < *v39 );
  }
  this->ssFileState[1].compressor->Write(this: this->ssFileState[1].compressor, a2: &this->snapRate, a3: 8u);
  v47 = session->GetActingGameStateLobbyBase(this: session);
  v48 = v47->GetMatchParms(this: v47);
  v49 = this->ssFileState[1].compressor;
  gameMap = v48->gameMap;
  v49->Write(this: v49, a2: &gameMap, a3: 4u);
  v55[0] = v48->gameMode;
  this->ssFileState[1].compressor->Write(this: this->ssFileState[1].compressor, a2: v55, a3: 4u);
  this->snapCurrentTime = v21;
  this->snapCurrentResidual = 0.0;
  this->snapTime = v21;
}


// ========================================================================
// $LN103_1
// EA  : 0x8265E9B8
// RVA : 0x0065E9B8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _LN103_1()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 208 + 104), tag: TAG_NETWORKING);
}


// ========================================================================
// ?StopSnapshotFilePlayback@idCommonLocal@@UAAXXZ
// EA  : 0x8265E9E8
// RVA : 0x0065E9E8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::StopSnapshotFilePlayback(idCommonLocal *this)
{
  unsigned __int64 v1; // r30
  idCompressor *compressor; // r3
  idCompressor *compressor2; // r3
  idFile *file; // r3
  idSnapShot *ss; // r29

  compressor = this->ssFileState[0].compressor;
  LODWORD(v1) = 0;
  this->snapPrevious.localTime = -1;
  this->snapCurrent.localTime = -1;
  this->snapPrevious.serverTime = -1;
  this->snapCurrent.serverTime = -1;
  this->snapTime = v1;
  if ( compressor != nullptr )
    ((void (__fastcall *)(idCompressor *, int))compressor->dtr_idFile)(a1: compressor, a2: 1);
  compressor2 = this->ssFileState[0].compressor2;
  this->ssFileState[0].compressor = nullptr;
  if ( compressor2 != nullptr )
    ((void (__fastcall *)(idCompressor *, int))compressor2->dtr_idFile)(a1: compressor2, a2: 1);
  file = this->ssFileState[0].file;
  this->ssFileState[0].compressor2 = nullptr;
  if ( file != nullptr )
    ((void (__fastcall *)(idFile *, int))file->dtr_idFile)(a1: file, a2: 1);
  ss = this->ssFileState[0].ss;
  this->ssFileState[0].file = nullptr;
  if ( ss != nullptr )
  {
    idSnapShot::~idSnapShot(this: ss);
    idMem::Free(this: &mem, ptr: ss, align: ALIGN_16);
  }
  this->ssFileState[0].ss = nullptr;
  this->ssFileState[0].resources = 0;
  this->demoMode = !this->TimeTrialRecording(this) ? DEMO_NONE : DEMO_TIMETRIAL;
  if ( com_captureFrames.valueInteger != 0 )
    idCVar::SetInteger(this: &com_captureFrames, newValue: 0, force: true);
  if ( com_captureSounds.valueInteger != 0 )
  {
    idCVar::SetInteger(this: &com_captureSounds, newValue: 0, force: true);
    ((void (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->SetCVarFloat)(
      a1: cvarSystem,
      a2: "s_volume_db",
      a3: 0.0);
  }
}


// ========================================================================
// ?RecordDemo_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265EB58
// RVA : 0x0065EB58
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::RecordDemo_f(const idCmdArgs *args)
{
  const char *v1; // r4
  idStr *v2; // r27
  size_t len; // r28
  idFile *v4; // r3
  int v5; // r10
  int v6; // r9
  int v7; // r8
  int v8; // r7
  int v9; // r6
  idLobbyBase *v10; // r3
  idLobbyBase *v11; // r3
  bool v12; // r3
  idCommonLocal::demoMode_t v13; // r11
  int v14; // [sp+8h] [-C8h]
  int v15; // [sp+Ch] [-C4h]
  int v16; // [sp+10h] [-C0h]
  int v17; // [sp+14h] [-BCh]
  int v18; // [sp+18h] [-B8h]
  int v19; // [sp+1Ch] [-B4h]
  int v20; // [sp+20h] [-B0h]
  unsigned int v21; // [sp+24h] [-ACh]
  _DWORD v22[4]; // [sp+50h] [-80h] BYREF
  idStr v23; // [sp+60h] [-70h] BYREF
  idStr v24[2]; // [sp+80h] [-50h] BYREF

  if ( args->argc <= 1 )
    v1 = &byte_8200D768;
  else
    v1 = args->argv[1];
  idStr::idStr(this: &v23, text: v1);
  if ( v23.len != 0 )
  {
    v2 = operator+(result: v24, a: "demos/", b: &v23);
    len = v2->len;
    idStr::EnsureAlloced(this: &v23, amount: v2->len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v23.data, Src: v2->data, Size: len);
    v23.data[len] = 0;
    v23.len = len;
    idStr::FreeData(this: v24);
  }
  else
  {
    v22[0] = 0;
    fileSystem->GetNumberedFilename(this: fileSystem, a2: v22, a3: "demos/demo", a4: "demo", a5: &v23, a6: true);
  }
  idStr::SetFileExtension(this: &v23, extension: "demo");
  idCommonLocal::CloseSnapshotFiles(this: &commonLocal);
  v4 = fileSystem->OpenFileWrite(this: fileSystem, a2: v23.data, a3: 2);
  idCommonLocal::RecordSnapshotFile(
    this: &commonLocal,
    file: v4,
    tag: 0x44454D4Fu,
    a4: v9,
    a5: v8,
    a6: v7,
    a7: v6,
    a8: v5,
    a9: v14,
    a10: v15,
    a11: v16,
    a12: v17,
    a13: v18,
    a14: v19,
    a15: v20,
    a16: v21);
  v10 = session->GetActingGameStateLobbyBase(this: session);
  if ( v10->IsHost(this: v10) != 0
    || (v11 = session->GetActingGameStateLobbyBase(this: session),
        v12 = v11->HasActivePeers(this: v11),
        v13 = DEMO_RECORD_CLIENT,
        !v12) )
  {
    v13 = DEMO_RECORD;
  }
  commonLocal.demoMode = v13;
  idStr::FreeData(this: &v23);
}


// ========================================================================
// __unwind$234173
// EA  : 0x8265ED00
// RVA : 0x0065ED00
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_234173()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$234174
// EA  : 0x8265ED28
// RVA : 0x0065ED28
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_234174()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 128));
}


// ========================================================================
// ?TimeTrialPlayQueued_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265ED50
// RVA : 0x0065ED50
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::TimeTrialPlayQueued_f(const idCmdArgs *args)
{
  idCommonLocal::StopSnapshotFilePlayback(this: &commonLocal);
  idCommonLocal::StopSnapshotFileRecord(this: &commonLocal);
  commonLocal.PlaySnapshotFile(
    this: &commonLocal,
    a2: commonLocal.queuedSnapshotFile,
    a3: commonLocal.queuedSnapshotFileTag);
  commonLocal.ClearQueuedSnapshotFile(this: &commonLocal);
}


// ========================================================================
// ?TimeTrialRecord_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265EDD0
// RVA : 0x0065EDD0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::TimeTrialRecord_f(const idCmdArgs *args)
{
  idFile_Memory *v1; // r3
  idFile_Memory *v2; // r30
  int v3; // r10
  int v4; // r9
  int v5; // r8
  int v6; // r7
  int v7; // r6
  int v8; // [sp+8h] [-78h]
  int v9; // [sp+Ch] [-74h]
  int v10; // [sp+10h] [-70h]
  int v11; // [sp+14h] [-6Ch]
  int v12; // [sp+18h] [-68h]
  int v13; // [sp+1Ch] [-64h]
  int v14; // [sp+20h] [-60h]
  unsigned int v15; // [sp+24h] [-5Ch]

  idCommonLocal::StopSnapshotFileRecord(this: &commonLocal);
  v1 = (idFile_Memory *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x14Cu,
                          tag: TAG_FILE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    v2 = idFile_Memory::idFile_Memory(this: v1);
  else
    v2 = nullptr;
  idFile_Memory::MakeWritable(this: v2);
  idCommonLocal::RecordSnapshotFile(
    this: &commonLocal,
    file: v2,
    tag: 0x5454524Cu,
    a4: v7,
    a5: v6,
    a6: v5,
    a7: v4,
    a8: v3,
    a9: v8,
    a10: v9,
    a11: v10,
    a12: v11,
    a13: v12,
    a14: v13,
    a15: v14,
    a16: v15);
}


// ========================================================================
// __unwind$234242
// EA  : 0x8265EE58
// RVA : 0x0065EE58
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_234242()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_FILE);
}


// ========================================================================
// ?TimeTrialStop_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265EE88
// RVA : 0x0065EE88
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::TimeTrialStop_f(const idCmdArgs *args)
{
  idCommonLocal::StopSnapshotFilePlayback(this: &commonLocal);
  idCommonLocal::StopSnapshotFileRecord(this: &commonLocal);
}


// ========================================================================
// ?DeleteGenerated_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265EEC8
// RVA : 0x0065EEC8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::DeleteGenerated_f(const idCmdArgs *args)
{
  idFileList *v1; // r30
  int v2; // r29
  int v3; // r31

  v1 = fileSystem->ListFilesTree(this: fileSystem, a2: "generated", a3: "*.*", a4: 0);
  idLib::Printf(fmt: "Removing generated files...\n");
  v2 = 0;
  if ( v1->list.num > 0 )
  {
    v3 = 0;
    do
    {
      idLib::Printf(fmt: "Deleting %s\n", v1->list.list[v3].data);
      fileSystem->RemoveFile(this: fileSystem, a2: v1->list.list[v3].data, a3: FSPATH_BASE);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->list.num );
  }
  idLib::Printf(fmt: "done.\n");
  fileSystem->FreeFileList(this: fileSystem, a2: v1);
}


// ========================================================================
// ?RecordDemo_Playtest_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265F2F8
// RVA : 0x0065F2F8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::RecordDemo_Playtest_f(const idCmdArgs *args)
{
  char *v2; // r4
  idStr v3; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v3, text: "demorecord playtest/");
  idStr::Append(this: &v3, text: playtest_sessionName.valueString.data);
  if ( args->argc <= 1 )
    v2 = &byte_8200D768;
  else
    v2 = args->argv[1];
  idStr::Append(this: &v3, text: v2);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: v3.data);
  idStr::FreeData(this: &v3);
}


// ========================================================================
// __unwind$234949
// EA  : 0x8265F398
// RVA : 0x0065F398
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_234949()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?Map_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x8265FB90
// RVA : 0x0065FB90
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::Map_f(const idCmdArgs *args)
{
  bool v2; // r21
  bool v3; // r20
  idSignInManagerBase *signInManager; // r11
  int argc; // r11
  int v6; // r30
  bool v7; // cr57
  const char **v8; // r29
  const char *v9; // r3
  const char *v10; // r3
  bool v11; // cr56
  const char *v12; // r4
  idStr *v13; // r3
  BOOL v14; // r30
  idDiscSwapManager *v15; // r10
  char *data; // r3
  const char *v17; // r3
  char *v18; // r3
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  va *v22; // r3
  __int64 v23; // r10
  __int64 v24; // r8
  __int64 v25; // r6
  idStr *v26; // r3
  va *v27; // r3
  __int64 v28; // r10
  __int64 v29; // r6
  __int64 v30; // r8
  va *v31; // r3
  idStr *v32; // r3
  idStr *v33; // r19
  size_t len; // r28
  const char *v35; // r3
  char *v36; // r3
  idStr *v37; // r3
  pacifierState_t v38; // r4
  pacifierState_t v39; // r4
  const idStr *v40; // [sp+8h] [-4AE8h]
  const idStr *v41; // [sp+Ch] [-4AE4h]
  const idStr *v42; // [sp+10h] [-4AE0h]
  const idStr *v43; // [sp+14h] [-4ADCh]
  int v44; // [sp+18h] [-4AD8h]
  int v45; // [sp+1Ch] [-4AD4h]
  int v46; // [sp+20h] [-4AD0h]
  bool v47; // [sp+27h] [-4AC9h]
  bool v48; // [sp+2Bh] [-4AC5h]
  bool v49; // [sp+2Fh] [-4AC1h]
  bool v50; // [sp+33h] [-4ABDh]
  bool v51; // [sp+37h] [-4AB9h]
  int v52; // [sp+38h] [-4AB8h]
  int v53; // [sp+3Ch] [-4AB4h]
  int v54; // [sp+40h] [-4AB0h]
  int v55; // [sp+44h] [-4AACh]
  int v56; // [sp+48h] [-4AA8h]
  int v57; // [sp+4Ch] [-4AA4h]
  int v58; // [sp+50h] [-4AA0h]
  int v59; // [sp+58h] [-4A98h]
  int v60; // [sp+60h] [-4A90h]
  int v61; // [sp+68h] [-4A88h]
  int v62; // [sp+70h] [-4A80h]
  int v63; // [sp+78h] [-4A78h]
  const idStr *v64; // [sp+7Ch] [-4A74h]
  int v65; // [sp+80h] [-4A70h]
  const idStr *v66; // [sp+84h] [-4A6Ch]
  int v67; // [sp+88h] [-4A68h]
  int v68; // [sp+90h] [-4A60h]
  int v69; // [sp+98h] [-4A58h]
  int v70; // [sp+A0h] [-4A50h]
  int v71; // [sp+A8h] [-4A48h]
  int v72; // [sp+B0h] [-4A40h]
  int v73; // [sp+B8h] [-4A38h]
  idStrStatic<128> v74; // [sp+C0h] [-4A30h] BYREF
  idStr v75; // [sp+170h] [-4980h] BYREF
  idStr v76; // [sp+190h] [-4960h] BYREF
  idStr v77; // [sp+1B0h] [-4940h] BYREF
  idStr v78; // [sp+1D0h] [-4920h] BYREF
  idStrStatic<2048> v79; // [sp+1F0h] [-4900h] BYREF
  va v80; // [sp+1820h] [-32D0h] BYREF
  va v81; // [sp+2820h] [-22D0h] BYREF
  idMatchParameters v82; // [sp+3820h] [-12D0h] BYREF

  v2 = false;
  v3 = false;
  if ( idSignInManagerBase::GetMasterLocalUser(this: session->signInManager) == nullptr )
  {
    signInManager = session->signInManager;
    signInManager->minDesiredLocalUsers = 1;
    signInManager->maxDesiredLocalUsers = 1;
    session->signInManager->Pump(this: session->signInManager);
  }
  argc = args->argc;
  v6 = 2;
  v7 = args->argc > 2;
  *(_DWORD *)v74.buffer = args->argc;
  if ( v7 )
  {
    v8 = (const char **)&args->argv[2];
    do
    {
      if ( v6 < 0 || v6 >= argc )
        v9 = &byte_8200D768;
      else
        v9 = *v8;
      if ( idStr::Icmp(s1: v9, s2: "combo") == 0 )
        v2 = true;
      if ( v6 < 0 || v6 >= args->argc )
        v10 = &byte_8200D768;
      else
        v10 = *v8;
      if ( idStr::Icmp(s1: v10, s2: "dev") == 0 )
        v3 = true;
      argc = args->argc;
      ++v6;
      ++v8;
      v11 = v6 < args->argc;
      *(_DWORD *)v74.buffer = args->argc;
    }
    while ( v11 );
  }
  if ( commonLocal.game != nullptr )
    commonLocal.game->Playtest_SaveAndClear(this: commonLocal.game);
  idStr::idStr(this: (idStr *)&v74.buffer[112], text: "map");
  if ( args->argc <= 1 )
    v12 = &byte_8200D768;
  else
    v12 = args->argv[1];
  idStr::idStr(this: &v74, text: v12);
  idStr::ToLower(this: &v74);
  v13 = idStr::Right(this: (idStr *)&v79.buffer[128], result: &v74, len: 8);
  v14 = (_cntlzw(idStr::Cmp(s1: v13->data, s2: "entities")) & 0x20) != 0;
  idStr::FreeData(this: (idStr *)&v79.buffer[128]);
  if ( v14 )
    idStr::operator=(this: (idStr *)&v74.buffer[112], text: "entities");
  else
    idStr::StripFileExtension(this: &v74);
  idDiscSwapManager::Reset(this: discSwapMgr);
  idStrStatic<251>::idStrStatic<251>(this: (idStrStatic<251> *)&v79.buffer[224], text: &v74);
  v15 = discSwapMgr;
  data = discSwapMgr->map.data;
  discSwapMgr->map.len = *(_DWORD *)&v79.buffer[224];
  memcpy(Dst: data, Src: *(const void **)&v79.buffer[228], Size: v15->map.len + 1);
  idStr::FreeData(this: (idStr *)&v79.buffer[224]);
  v17 = idCmdArgs::Args(this: args, start: 0, end: -1, quoteArgs: false, escapeArgs: false);
  v79.buffer[524] = 0;
  v79.buffer[544] = 0;
  *(_DWORD *)&v79.buffer[512] = 0;
  *(_DWORD *)&v79.buffer[516] = &v79.buffer[544];
  *(_DWORD *)&v79.buffer[520] = -2147482648;
  idStr::operator=(this: (idStr *)&v79.buffer[512], text: v17);
  v18 = discSwapMgr->additionalArguments.data;
  discSwapMgr->additionalArguments.len = *(_DWORD *)&v79.buffer[512];
  memcpy(Dst: v18, Src: *(const void **)&v79.buffer[516], Size: *(_DWORD *)&v79.buffer[512] + 1);
  idStr::FreeData(this: (idStr *)&v79.buffer[512]);
  if ( idDiscSwapManager::Swap(this: discSwapMgr, command: DSC_MAP, forceDiscNumber: 0) != DSE_OK )
  {
    idStr::FreeData(this: &v74);
    goto LABEL_48;
  }
  if ( idLib::production == PROD_DEVELOPMENT )
  {
    HIDWORD(v21) = v74.data;
    v22 = va::va(
            this: &v81,
            fmt: "maps/%s",
            a3: v21,
            a4: v20,
            a5: v19,
            a6: (int)v40,
            a7: (int)v41,
            a8: (int)v42,
            a9: (int)v43,
            a10: v44,
            a11: v45);
    idStr::idStr(this: (idStr *)&v74.buffer[80], text: v22);
    idStr::SetFileExtension(this: (idStr *)&v74.buffer[80], extension: *(const char **)&v74.buffer[116]);
    HIDWORD(v23) = fileSystem->FileExists(this: fileSystem, a2: *(const char **)&v74.buffer[84], a3: false);
    if ( HIDWORD(v23) == 0 )
    {
      idLib::Printf(fmt: "Can't find map '%s'\n", *(const char **)&v74.buffer[84]);
      if ( idStr::Cmp(s1: *(const char **)&v74.buffer[116], s2: "entities") == 0 )
        idLib::Printf(fmt: "Use the writeEntitiesFile command to convert the map to an entities file.\n");
      idStr::FreeData(this: (idStr *)&v74.buffer[80]);
      idStr::FreeData(this: &v74);
      goto LABEL_48;
    }
    if ( v2 )
    {
      idStr::idStr(this: &v75, text: &v74);
      idStr::StripFileExtension(this: &v75);
      idStr::StripPath(this: &v75);
      idStr::Format(this: (idStr *)&v74.buffer[80], fmt: "maps/%s/_combo/%s.proc", v74.data, v75.data);
      if ( !fileSystem->FileExists(this: fileSystem, a2: *(const char **)&v74.buffer[84], a3: false) )
        idLib::Error(fmt: "You need to build the combo map for: %s", v74.data);
      v26 = &v75;
    }
    else
    {
      HIDWORD(v25) = v74.data;
      v27 = va::va(
              this: (va *)&v79.buffer[1552],
              fmt: "maps/%s",
              a3: v25,
              a4: v24,
              a5: v23,
              a6: (int)v40,
              a7: (int)v41,
              a8: (int)v42,
              a9: (int)v43,
              a10: v44,
              a11: v45);
      idStr::idStr(this: &v76, text: v27);
      idStr::StripFileExtension(this: &v76);
      idStr::Append(this: &v76, text: "_region.map");
      if ( fileSystem->FileExists(this: fileSystem, a2: v76.data, a3: false) )
      {
        idLib::Printf(fmt: "Loading region map: %s\n", v74.data);
        LODWORD(v28) = &unk_821D0000;
        HIDWORD(v29) = v74.data;
        v31 = va::va(
                this: &v80,
                fmt: "%s_region",
                a3: v29,
                a4: v30,
                a5: v28,
                a6: (int)v40,
                a7: (int)v41,
                a8: (int)v42,
                a9: (int)v43,
                a10: v44,
                a11: v45);
        idStr::operator=(this: &v74, text: v31);
      }
      v26 = &v76;
    }
    idStr::FreeData(this: v26);
    idStr::FreeData(this: (idStr *)&v74.buffer[80]);
  }
  idStr::idStr(this: (idStr *)&v74.buffer[48], text: playtest_sessionType.valueString.data);
  if ( idStr::Icmp(s1: *(const char **)&v74.buffer[52], s2: "direct") == 0 )
  {
    idStr::idStr(this: &v77, text: &v74);
    idStr::StripPath(this: &v77);
    idStr::StripFileExtension(this: &v77);
    v32 = operator+(result: (idStr *)&v79.buffer[96], a: (const idStr *)&v74.buffer[48], b: "_");
    v33 = operator+(result: (idStr *)&v79.buffer[192], a: v32, b: &v77);
    len = v33->len;
    idStr::EnsureAlloced(this: (idStr *)&v74.buffer[48], amount: v33->len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: *(void **)&v74.buffer[52], Src: v33->data, Size: len);
    *(_BYTE *)(*(_DWORD *)&v74.buffer[52] + len) = 0;
    *(_DWORD *)&v74.buffer[48] = len;
    idStr::FreeData(this: (idStr *)&v79.buffer[192]);
    idStr::FreeData(this: (idStr *)&v79.buffer[96]);
    idStr::FreeData(this: &v77);
  }
  v35 = sys->GetMachineName(this: sys);
  idStr::idStr(this: (idStr *)&v74.buffer[16], text: v35);
  if ( *(_DWORD *)&v74.buffer[16] == 0 )
    idStr::operator=(this: (idStr *)&v74.buffer[16], text: "nomachinename");
  idStr::Append(this: (idStr *)&v74.buffer[16], text: "_");
  v36 = (char *)Sys_DateStr(padded: true);
  idStr::Append(this: (idStr *)&v74.buffer[16], text: v36);
  idStr::ReplaceChar(this: (idStr *)&v74.buffer[16], oldChar: 32, newChar: 95);
  idStr::ReplaceChar(this: (idStr *)&v74.buffer[16], oldChar: 47, newChar: 95);
  idStr::ReplaceChar(this: (idStr *)&v74.buffer[16], oldChar: 92, newChar: 95);
  idStr::ReplaceChar(this: (idStr *)&v74.buffer[16], oldChar: 9, newChar: 95);
  idStr::ReplaceChar(this: (idStr *)&v74.buffer[16], oldChar: 58, newChar: 95);
  v37 = operator+(result: (idStr *)&v79.buffer[160], a: (const idStr *)&v74.buffer[48], b: "/");
  operator+(result: (idStr *)&v79.buffer[64], a: v37, b: (const idStr *)&v74.buffer[16]);
  idStr::FreeData(this: (idStr *)&v79.buffer[160]);
  idCVar::SetString(this: &playtest_sessionName, newValue: *(const char **)&v79.buffer[68], force: true);
  idCVar::SetString(this: &playtest_sessionType, newValue: "direct", force: true);
  if ( commonLocal.game != nullptr )
    commonLocal.game->Playtest_CreateMeta(this: commonLocal.game);
  idStr::idStr(this: (idStr *)v79.buffer, text: si_jobDebugName.valueString.data);
  idStr::idStr(this: &v78, text: si_spawnspot.valueString.data);
  idStr::idStr(this: (idStr *)&v79.buffer[32], text: si_nextlayerdeactive.valueString.data);
  idStr::idStr(this: &v79, text: si_nextlayeractive.valueString.data);
  idMatchParameters::idMatchParameters(
    this: &v82,
    gameMode_: -1,
    searchMode_: -1,
    gameMap_: -1,
    gameType_: 0,
    numSlots_: 6,
    matchFlags_: 0,
    mapName_: &v74,
    minRespawnDelay_: si_minRespawnDelay.valueFloat,
    timeLimit_: si_timeLimit.valueFloat,
    layersActive_: v40,
    layersDeactive_: v41,
    spawnSpot_: v42,
    debugJobName_: v43,
    debugJobState_: v44,
    scoreLimit_: v45,
    teamCount_: v46,
    swapTeams_: v47,
    stopWatch_: v48,
    comboMap_: v49,
    devmap_: v50,
    isTransitionalMapRequest_: v51,
    a23: v52,
    a24: v53,
    a25: v54,
    a26: v55,
    a27: v56,
    a28: v57,
    a29: v58,
    a30: &v79,
    a31: v59,
    a32: (const idStrStatic<2048> *)&v79.buffer[32],
    a33: v60,
    a34: &v78,
    a35: v61,
    a36: (const idStrStatic<128> *)v79.buffer,
    a37: v62,
    layersActive_a: (const idStr *)si_jobDebugState.valueInteger,
    a39: v63,
    layersDeactive_a: v64,
    a41: v65,
    spawnSpot_a: v66,
    a43: v67,
    debugJobName_a: (const idStr *)si_scoreLimit.valueInteger,
    a45: v68,
    debugJobState_a: si_teamCount.valueInteger,
    a47: v69,
    a48: si_swapTeams.valueInteger != 0,
    a49: v70,
    a50: si_stopWatch.valueInteger != 0,
    a51: v71,
    scoreLimit__3: v2,
    a53: v72,
    teamCount__3: v3,
    a55: v73,
    swapTeams_a: false);
  idStr::FreeData(this: &v79);
  idStr::FreeData(this: (idStr *)&v79.buffer[32]);
  idStr::FreeData(this: &v78);
  idStr::FreeData(this: (idStr *)v79.buffer);
  session->ClearSessionOption(this: session, a2: OPTION_ALL);
  session->CreateMatch(this: session, a2: &v82);
  WaitOnSession(waitingOnState: GAME_LOBBY, pacifierProgress: -1.0, pacifierState: v38, a4: 0);
  session->StartMatch(this: session);
  WaitOnSession(waitingOnState: PARTY_LOBBY|SEARCHING, pacifierProgress: -1.0, pacifierState: v39, a4: 0);
  idCVar::SetString(this: &si_nextlayeractive, newValue: &byte_8200D768, force: true);
  idCVar::SetString(this: &si_nextlayerdeactive, newValue: &byte_8200D768, force: true);
  idCVar::SetString(this: &si_jobDebugName, newValue: &byte_8200D768, force: true);
  idCVar::SetInteger(this: &si_jobDebugState, newValue: 0, force: true);
  idCVar::SetString(this: &si_spawnspot, newValue: "player_start", force: true);
  fileSystem->ClearZipCache(this: fileSystem);
  idMatchParameters::~idMatchParameters(this: &v82);
  idStr::FreeData(this: (idStr *)&v79.buffer[64]);
  idStr::FreeData(this: (idStr *)&v74.buffer[16]);
  idStr::FreeData(this: (idStr *)&v74.buffer[48]);
  idStr::FreeData(this: &v74);
LABEL_48:
  idStr::FreeData(this: (idStr *)&v74.buffer[112]);
}


// ========================================================================
// $LN254
// EA  : 0x82660430
// RVA : 0x00660430
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _LN254()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 336));
}


// ========================================================================
// __unwind$235507
// EA  : 0x82660458
// RVA : 0x00660458
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235507()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 192));
}


// ========================================================================
// __unwind$235508
// EA  : 0x82660480
// RVA : 0x00660480
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235508()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 656));
}


// ========================================================================
// __unwind$235604
// EA  : 0x826604A8
// RVA : 0x006604A8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235604()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 1040));
}


// ========================================================================
// __unwind$235511
// EA  : 0x826604D0
// RVA : 0x006604D0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235511()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 304));
}


// ========================================================================
// __unwind$235512
// EA  : 0x826604F8
// RVA : 0x006604F8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235512()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 368));
}


// ========================================================================
// __unwind$235513
// EA  : 0x82660520
// RVA : 0x00660520
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235513()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 400));
}


// ========================================================================
// __unwind$235514
// EA  : 0x82660548
// RVA : 0x00660548
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235514()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 272));
}


// ========================================================================
// __unwind$235515
// EA  : 0x82660570
// RVA : 0x00660570
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235515()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 432));
}


// ========================================================================
// __unwind$235516
// EA  : 0x82660598
// RVA : 0x00660598
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235516()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 624));
}


// ========================================================================
// __unwind$235517
// EA  : 0x826605C0
// RVA : 0x006605C0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235517()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 720));
}


// ========================================================================
// __unwind$235518
// EA  : 0x826605E8
// RVA : 0x006605E8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235518()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 240));
}


// ========================================================================
// __unwind$235519
// EA  : 0x82660610
// RVA : 0x00660610
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235519()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 688));
}


// ========================================================================
// __unwind$235520
// EA  : 0x82660638
// RVA : 0x00660638
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235520()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 592));
}


// ========================================================================
// __unwind$235521
// EA  : 0x82660660
// RVA : 0x00660660
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235521()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 528));
}


// ========================================================================
// __unwind$235522
// EA  : 0x82660688
// RVA : 0x00660688
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235522()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 464));
}


// ========================================================================
// __unwind$235523
// EA  : 0x826606B0
// RVA : 0x006606B0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235523()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 560));
}


// ========================================================================
// __unwind$235524
// EA  : 0x826606D8
// RVA : 0x006606D8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235524()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19184 + 496));
}


// ========================================================================
// __unwind$235525
// EA  : 0x82660700
// RVA : 0x00660700
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_235525()
{
  int v0; // r12

  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(v0 - 19184 + 14368));
}


// ========================================================================
// ?DevMap_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x82660728
// RVA : 0x00660728
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::DevMap_f(const idCmdArgs *args)
{
  idCmdArgs v1; // [sp+50h] [-910h] BYREF

  idCmdArgs::idCmdArgs(this: &v1, other: args);
  idCmdArgs::AppendArg(this: &v1, text: "dev");
  idCommonLocal::Map_f(args: &v1);
}


// ========================================================================
// ?ComboMap_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x82660768
// RVA : 0x00660768
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::ComboMap_f(const idCmdArgs *args)
{
  idCmdArgs v1; // [sp+50h] [-910h] BYREF

  idCmdArgs::idCmdArgs(this: &v1, other: args);
  idCmdArgs::AppendArg(this: &v1, text: "combo");
  idCommonLocal::Map_f(args: &v1);
}


// ========================================================================
// ?DevComboMap_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x826607A8
// RVA : 0x006607A8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::DevComboMap_f(const idCmdArgs *args)
{
  idCmdArgs v1; // [sp+50h] [-910h] BYREF

  idCmdArgs::idCmdArgs(this: &v1, other: args);
  idCmdArgs::AppendArg(this: &v1, text: "dev");
  idCmdArgs::AppendArg(this: &v1, text: "combo");
  idCommonLocal::Map_f(args: &v1);
}


// ========================================================================
// ?LoadMainMenu@idCommonLocal@@QAAXXZ
// EA  : 0x826608E8
// RVA : 0x006608E8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
void __fastcall idCommonLocal::LoadMainMenu(idCommonLocal *this)
{
  idCommonLocal *v1; // r30
  const idGameSpawnInfo *v2; // r3
  idGame **p_game; // r29
  idCommonLocal *v4; // r3
  idGame_vtbl *v5; // r30
  bool (__fastcall *IsInGame)(struct idCommonLocal *); // ctr
  int v7; // r3
  idGameSpawnInfo v8; // [sp+50h] [-150E0h] BYREF

  v1 = (idCommonLocal *)((int (*)(void))RtlCheckStack12)();
  idCommonLocal::ResetMapHeap(this: v1);
  idPhysicalMemoryBlock::BeginResourceLoads(this: &physicalMemoryBlock);
  idPhysicalMemoryBlock::EndResourceLoads(this: &physicalMemoryBlock, neverFreeAllocatedData: false);
  idRenderManager::RenderFrameAndBeginAutomaticBackgroundSwaps(this: &renderManager);
  soundSystem->InitStreamBuffers(this: soundSystem);
  v2 = idGameSpawnInfo::idGameSpawnInfo(this: &v8, mapName_: &byte_8200D768, gameFlags_: 1);
  p_game = &v1->game;
  gameSystem->AllocGame(this: gameSystem, a2: &v1->game, a3: v2, a4: nullptr);
  idGameSpawnInfo::~idGameSpawnInfo(this: &v8);
  if ( !idLib::headless || com_production.valueInteger == 1 )
    v1->GetProfileFromMasterLocalUser(this: v1);
  v4 = v1;
  IsInGame = v1->IsInGame;
  v5 = (*p_game)->__vftable;
  v7 = ((int (__fastcall *)(idCommonLocal *))IsInGame)(a1: v4);
  v5->Shell_CreateMenu(this: *p_game, a2: v7);
  renderSystem->EndAutomaticBackgroundSwaps(this: renderSystem);
}


// ========================================================================
// __unwind$236415
// EA  : 0x82660A20
// RVA : 0x00660A20
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_236415()
{
  int v0; // r12

  idGameSpawnInfo::~idGameSpawnInfo(this: (idGameSpawnInfo *)(v0 - 20784 + 80));
}


// ========================================================================
// ?LeaveGame@idCommonLocal@@QAAX_N@Z
// EA  : 0x82660C58
// RVA : 0x00660C58
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::LeaveGame(idCommonLocal *this, bool cancelProcessors)
{
  int i; // r30
  idJoystick *v5; // r3
  int v6; // r6
  int v7; // r5
  int v8; // r4
  unsigned __int64 v9; // r8
  int v10; // r30
  int v11; // r29

  this->CloseSnapshotFiles(this);
  this->insideUpdateScreen = false;
  idRenderManager::Clear(this: &renderManager);
  this->SyncAllBackgroundOperations(this, a2: false);
  if ( cancelProcessors )
    idSaveGameManager::CancelAllProcessors(this: session->saveGameManager, forceCancelInFlightProcessor: true);
  for ( i = 0; i < 4; ++i )
  {
    v5 = sys->Joystick(this: sys);
    v5->SetRumble(this: v5, a2: i, a3: 0, a4: 0);
  }
  idCommonLocal::StopLevelLoad(this, loadVirtualTextures: false);
  gameSystem->FreeGame(this: gameSystem, a2: &this->game);
  LODWORD(v9) = this->mapChangeListeners.num;
  v10 = 0;
  if ( (int)v9 > 0 )
  {
    v11 = 0;
    do
    {
      this->mapChangeListeners.list[v11]->MapDisconnected(this: this->mapChangeListeners.list[v11]);
      LODWORD(v9) = this->mapChangeListeners.num;
      ++v10;
      ++v11;
    }
    while ( v10 < (int)v9 );
  }
  idCommonLocal::ResetNetworkingState(this, a2: v8, a3: v7, a4: v6, a5: v9);
  idCommonLocal::LoadMainMenu(this);
}


// ========================================================================
// ?Disconnect@idCommonLocal@@QAAX_N@Z
// EA  : 0x82660D90
// RVA : 0x00660D90
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::Disconnect(idCommonLocal *this, bool cancelAllProcessors)
{
  bool v4; // r29

  v4 = console->IsActive(this: console);
  session->MoveToPressStart(this: session);
  idCommonLocal::LeaveGame(this, cancelProcessors: cancelAllProcessors);
  if ( v4 )
    cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "activateConsole 0.5");
}


// ========================================================================
// ?Disconnect_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x82660E18
// RVA : 0x00660E18
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::Disconnect_f(const idCmdArgs *args)
{
  if ( commonLocal.game != nullptr )
    commonLocal.game->Playtest_SaveAndClear(this: commonLocal.game);
  idCommonLocal::Disconnect(this: &commonLocal, cancelAllProcessors: true);
}


// ========================================================================
// ?FinalizeMapChange@idCommonLocal@@QAAXABVidGameSpawnInfo@@PAVidFile@@@Z
// EA  : 0x82660E78
// RVA : 0x00660E78
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::FinalizeMapChange(
        idCommonLocal *this,
        const idGameSpawnInfo *gameSpawnInfo,
        idFile *saveGameFile)
{
  __int64 v6; // r4
  int v7; // r15
  unsigned __int64 v8; // r8
  int v9; // r6
  int v10; // r5
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r10
  va *v14; // r3
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r6
  va *v18; // r3
  int v19; // r17
  char *data; // r22
  idResource *v21; // r24
  __int64 v22; // r8
  __int64 v23; // r6
  idGame **i; // r26
  char v25; // r27
  const char *v26; // r29
  unsigned int v27; // r30
  char v28; // r28
  int j; // r30
  char v30; // r11
  __int64 v31; // r10
  va *v32; // r3
  bool v33; // r30
  int v34; // r3
  bool v35; // r30
  idLobbyBase *v36; // r3
  int k; // r28
  idDeclInfo *v38; // r29
  int m; // r30
  idResource *v40; // r3
  int n; // r30
  idResource *v42; // r3
  idGame *v43; // r3
  idLobbyBase *v44; // r3
  pacifierState_t v45; // r4
  double v46; // fp0
  idLobbyBase *v47; // r3
  idLobbyBase *v48; // r3
  idGame *v49; // r3
  idLobbyBase *v50; // r3
  BOOL v51; // r4
  idLobbyBase *v52; // r3
  idLobbyBase *v53; // r3
  int v54; // r4
  idGame *v55; // r3
  idGame *v56; // r3
  int v57; // r29
  int v58; // r30
  idGame *v59; // r3
  idMapChangeListener *v60; // r28
  idMapChangeListener_vtbl *v61; // r27
  int v62; // r3
  __int64 v63; // r10
  __int64 v64; // r8
  __int64 v65; // r6
  va *v66; // r3
  const char *v67; // r3
  __int64 v68; // r10
  __int64 v69; // r6
  __int64 v70; // r8
  va *v71; // r3
  int v72; // [sp+8h] [-43C8h]
  int v73; // [sp+8h] [-43C8h]
  int v74; // [sp+Ch] [-43C4h]
  int v75; // [sp+Ch] [-43C4h]
  int v76; // [sp+10h] [-43C0h]
  int v77; // [sp+10h] [-43C0h]
  int v78; // [sp+14h] [-43BCh]
  int v79; // [sp+14h] [-43BCh]
  int v80; // [sp+18h] [-43B8h]
  int v81; // [sp+18h] [-43B8h]
  double v82; // [sp+18h] [-43B8h]
  int v83; // [sp+1Ch] [-43B4h]
  int v84; // [sp+1Ch] [-43B4h]
  char v85[3]; // [sp+50h] [-4380h] BYREF
  char v86; // [sp+53h] [-437Dh] BYREF
  char v87; // [sp+54h] [-437Ch]
  unsigned __int64 v88; // [sp+58h] [-4378h]
  idSnapShot v89; // [sp+70h] [-4360h] BYREF
  idStr v90; // [sp+B0h] [-4320h] BYREF
  char v91[128]; // [sp+D0h] [-4300h] BYREF
  idStr v92; // [sp+150h] [-4280h] BYREF
  char v93; // [sp+170h] [-4260h] BYREF
  idStr v94; // [sp+270h] [-4160h] BYREF
  char v95; // [sp+290h] [-4140h] BYREF
  idStrStatic<128> v96; // [sp+390h] [-4040h] BYREF
  char v97[256]; // [sp+430h] [-3FA0h] BYREF
  va v98; // [sp+530h] [-3EA0h] BYREF
  gameReturn_t v99; // [sp+1530h] [-2EA0h] BYREF

  v6 = ((__int64 (__fastcall *)(idSession *))session->GetLoadingID)(a1: session);
  v7 = HIDWORD(v6);
  idCommonLocal::ResetNetworkingState(this, a2: v6, a3: v10, a4: v9, a5: v8);
  resourceManager->SetFileHook(this: resourceManager);
  HIDWORD(v11) = &unk_821D0000;
  HIDWORD(v12) = gameSpawnInfo->mapName.data;
  v14 = va::va(
          this: &v98,
          fmt: "maps/%s/_combo/world.bcm",
          a3: v12,
          a4: v11,
          a5: v13,
          a6: v72,
          a7: v74,
          a8: v76,
          a9: v78,
          a10: v80,
          a11: v83);
  LODWORD(v15) = fileSystem->FileExists(this: fileSystem, a2: (const char *)v14, a3: true);
  if ( (_DWORD)v15 == 0 )
  {
    HIDWORD(v17) = gameSpawnInfo->mapName.data;
    v18 = va::va(
            this: &v98,
            fmt: "%s/_combo/world.bcm",
            a3: v17,
            a4: v16,
            a5: v15,
            a6: v73,
            a7: v75,
            a8: v77,
            a9: v79,
            a10: v81,
            a11: v84);
    if ( !fileSystem->FileExists(this: fileSystem, a2: (const char *)v18, a3: true) )
    {
      idLib::Printf(fmt: "Map '%s' does not exist", gameSpawnInfo->mapName.data);
      resourceManager->ReleaseFileHook(this: resourceManager);
      idCommonLocal::Disconnect(this, cancelAllProcessors: true);
      return;
    }
  }
  resourceManager->ReleaseFileHook(this: resourceManager);
  v19 = Sys_Milliseconds();
  v92.baseBuffer[0] = 0;
  v93 = 0;
  data = nullptr;
  v92.len = 0;
  v92.data = &v93;
  v92.allocedAndFlag = -2147483392;
  v90.baseBuffer[0] = 0;
  v91[0] = 0;
  v90.data = v91;
  v90.allocedAndFlag = -2147483520;
  idStrStatic<128>::idStrStatic<128>(this: &v96, text: (const idStrStatic<128> *)&gameSpawnInfo->mapName);
  v90.len = v96.len;
  memcpy(Dst: v91, Src: v96.data, Size: v96.len + 1);
  idStr::FreeData(this: &v96);
  v21 = idResourceList::Load(this: &idDeclMapInfo::resourceList, name: v91, makeDefault: false, skipStaleCheck: false);
  if ( v21 == nullptr )
    goto _M237252;
  for ( i = nullptr; (int)i < (int)v21[2].name.str; i = (idGame **)((char *)i + 1) )
  {
    v25 = 1;
    v26 = *(const char **)(v21[2].trackedMemory + 8 * (_DWORD)i);
    while ( v26 != nullptr && *v26 != 0 )
    {
      v27 = idStr::Find(str: v26, c: 44, start: 0, end: -1);
      if ( v27 == -1 )
      {
        strncpy(dest: v97, source: v26, count: 0x100u);
        v26 = nullptr;
        v97[255] = 0;
      }
      else
      {
        strncpy(dest: v97, source: v26, count: v27);
        v26 += v27 + 1;
        v97[v27] = 0;
      }
      v28 = 0;
      for ( j = 0; j < gameSpawnInfo->layersActive.num; ++j )
      {
        if ( idStr::Icmp(s1: gameSpawnInfo->layersActive.list[j].data, s2: v97) == 0 )
        {
          v28 = 1;
          break;
        }
      }
      if ( v25 == 0 || (v30 = 1, v28 == 0) )
        v30 = 0;
      v25 = v30;
    }
    if ( v25 != 0 )
    {
      LODWORD(v31) = v21[2].trackedMemory;
      HIDWORD(v31) = &unk_821D0000;
      HIDWORD(v23) = *(_DWORD *)(v31 + 8 * (_DWORD)i + 4);
      v32 = va::va(
              this: &v98,
              fmt: "bink/%s",
              a3: v23,
              a4: v22,
              a5: v31,
              a6: v73,
              a7: v75,
              a8: v77,
              a9: v79,
              a10: v81,
              a11: v84);
      v94.baseBuffer[0] = 0;
      v95 = 0;
      v94.len = 0;
      v94.data = &v95;
      v94.allocedAndFlag = -2147483392;
      idStr::operator=(this: &v94, text: v32->buffer);
      v92.len = v94.len;
      memcpy(Dst: v92.data, Src: v94.data, Size: v94.len + 1);
      idStr::FreeData(this: &v94);
      data = v92.data;
      break;
    }
_LN339:
    ;
  }
_M237252:
  i = &this->game;
  if ( !resourceManager->AllocGameWithResourceFile(
          this: resourceManager,
          a2: &this->game,
          a3: gameSpawnInfo,
          a4: saveGameFile,
          a5: !gameSpawnInfo->useLoadingVideo ? nullptr : data) )
  {
    idCommonLocal::StopLevelLoad(this, loadVirtualTextures: false);
    gameSystem->MinimalGameCleanup(this: gameSystem, a2: &this->game);
    idLib::Error(fmt: "Unable to allocate game");
    goto _LN339;
  }
  (*i)->Shell_CreateMenu(this: *i, a2: true);
  if ( idStr::Cmp(s1: gameSpawnInfo->mapName.data, s2: "outro") != 0 )
  {
    v34 = Sys_Milliseconds();
    v88 = __PAIR64__((idDeclInfoTemplate<idDeclReachIK> *)&idDeclReachIK::resourceList.hashTable[243], v34 - v19);
    time_mapLoadMS = v34 - v19;
    v82 = (float)((float)__SPAIR64__(
                           (idDeclInfoTemplate<idDeclReachIK> *)&idDeclReachIK::resourceList.hashTable[243],
                           v34 - v19)
                * (float)0.001);
    idLib::Printf(fmt: (const char *)HIDWORD(v82), LODWORD(v82), gameSpawnInfo->mapName.data);
    idStr::FreeData(this: &v90);
    idStr::FreeData(this: &v92);
    v35 = this->ssFileState[0].compressor != nullptr;
    if ( idResourceList::ShouldPerformNetworkResourceExchange() )
    {
      idResourceList::ResetNetworkResources();
      v36 = session->GetActingGameStateLobbyBase(this: session);
      if ( v36->IsHost(this: v36) != 0 && this->IsMultiplayer(this) && !v35 )
      {
        for ( k = 0; k < declManager->GetNumDeclTypes(this: declManager); ++k )
        {
          v38 = declManager->GetDeclType_2(this: declManager, a2: k);
          for ( m = 0; m < v38->num; ++m )
          {
            v40 = idResourceList::Index(this: v38, index: m);
            idResource::GetNetworkID(this: v40, alloc: true);
          }
        }
        for ( n = 0; n < idMD6Anim::resourceList.num; ++n )
        {
          v42 = idResourceList::Index(this: &idMD6Anim::resourceList, index: n);
          idResource::GetNetworkID(this: v42, alloc: true);
        }
      }
    }
    v43 = this->Game(this);
    v43->GenerateInputToPlayerIndexRouting(this: v43);
    if ( session->GetState(this: session) != (PARTY_LOBBY|SEARCHING) || session->GetLoadingID(this: session) != v7 )
    {
      idCommonLocal::StopLevelLoad(this, loadVirtualTextures: false);
      gameSystem->FreeGame(this: gameSystem, a2: &this->game);
      idCommonLocal::LoadMainMenu(this);
      if ( session->GetLoadingID(this: session) != v7 )
      {
        v66 = va::va(
                this: &v98,
                fmt: "FinalizeMapChange: Started loading a new map from within an existing map load.",
                a3: v65,
                a4: v64,
                a5: v63,
                a6: v73,
                a7: v75,
                a8: v77,
                a9: v79,
                a10: SHIDWORD(v82),
                a11: SLODWORD(v82));
        strncpy(dest: idException::error, source: v66->buffer, count: 0x800u);
        v86 = v87;
        CxxThrowException(pExceptionObject: &v86, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidNetworkLoadException__);
      }
      v67 = session->GetStateString(this: session);
      HIDWORD(v68) = &unk_821D0000;
      HIDWORD(v69) = v67;
      v71 = va::va(
              this: &v98,
              fmt: "FinalizeMapChange: State was %s but expected LOADING.",
              a3: v69,
              a4: v70,
              a5: v68,
              a6: v73,
              a7: v75,
              a8: v77,
              a9: v79,
              a10: SHIDWORD(v82),
              a11: SLODWORD(v82));
      strncpy(dest: idException::error, source: v71->buffer, count: 0x800u);
      v85[0] = v87;
      CxxThrowException(pExceptionObject: v85, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidNetworkLoadException__);
    }
    session->LoadingFinished(this: session);
    v44 = session->GetActingGameStateLobbyBase(this: session);
    if ( v44->HasActivePeers(this: v44) )
      v46 = 1.0;
    else
      v46 = -1.0;
    WaitOnSession(waitingOnState: INGAME, pacifierProgress: v46, pacifierState: v45, a4: 18);
    v47 = session->GetActingGameStateLobbyBase(this: session);
    if ( v47->IsHost(this: v47) != 0 )
    {
      v48 = session->GetActingGameStateLobbyBase(this: session);
      if ( v48->HasActivePeers(this: v48) )
      {
        gameReturn_t::gameReturn_t(this: &v99);
        idSnapShot::idSnapShot(this: &v89);
        v49 = this->Game(this);
        v49->RunFrame(this: v49, a2: nullptr, a3: &v99, a4: true);
        common->PrepareSnapshot(this: common, a2: &v89, a3: &v99, a4: nullptr);
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v89);
        session->SendSnapshot(this: session, a2: &v89);
        v50 = session->GetActingGameStateLobbyBase(this: session);
        v51 = v50->EnsureAllPeersHaveBaseState(this: v50);
        if ( !v51 )
        {
          do
          {
            ((void (__fastcall *)(idCommon *, BOOL, int, int, int, double))common->UpdateLevelLoadPacifier)(
              a1: common,
              a2: v51,
              a3: 18,
              a4: 1,
              a5: 1,
              a6: 1.0);
            mgthread_sleep(ms: 10);
            v52 = session->GetActingGameStateLobbyBase(this: session);
          }
          while ( !v52->EnsureAllPeersHaveBaseState(this: v52) );
        }
        idSnapShot::~idSnapShot(this: &v89);
        gameReturn_t::~gameReturn_t(this: &v99);
      }
    }
    v53 = session->GetActingGameStateLobbyBase(this: session);
    if ( v53->HasActivePeers(this: v53) )
      ((void (__fastcall *)(idCommon *, int, _DWORD, int, _DWORD, double))common->UpdateLevelLoadPacifier)(
        a1: common,
        a2: v54,
        a3: 0,
        a4: 1,
        a5: 0,
        a6: 1.0);
    if ( com_newLoadScreen.valueInteger != 0 )
    {
      gameReturn_t::gameReturn_t(this: &v99);
      v55 = this->Game(this);
      v55->RunFrame(this: v55, a2: nullptr, a3: &v99, a4: true);
      idLoadScreen::LevelLoadCompleted(this: &loadScreen, gameRet: &v99);
      gameReturn_t::~gameReturn_t(this: &v99);
    }
    console->ClearNotifyLines(this: console);
    sys->ClearEvents(this: sys);
    fileSystem->ClearZipCache(this: fileSystem);
    if ( !common->IsMultiplayer(this: common) && !gameSpawnInfo->isTransitionalMapRequest )
    {
      v56 = this->Game(this);
      v56->SaveGame(this: v56, a2: "AUTOSAVE", a3: true, a4: true);
    }
    v57 = 0;
    if ( this->mapChangeListeners.num > 0 )
    {
      v58 = 0;
      do
      {
        v59 = this->Game(this);
        v60 = this->mapChangeListeners.list[v58];
        v61 = v60->__vftable;
        v62 = (int)v59->GetLevelMap(this: v59);
        v61->MapLoaded(this: v60, a2: (idMapFile *)v62);
        ++v57;
        ++v58;
      }
      while ( v57 < this->mapChangeListeners.num );
    }
  }
  else
  {
    v33 = console->IsActive(this: console);
    session->MoveToPressStart(this: session);
    idCommonLocal::LeaveGame(this, cancelProcessors: false);
    if ( v33 )
      cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "activateConsole 0.5");
    idStr::FreeData(this: &v90);
    idStr::FreeData(this: &v92);
  }
}


// ========================================================================
// $M237308
// EA  : 0x82661A24
// RVA : 0x00661A24
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _M237308()
{
  int v0; // r12
  int v1; // r31
  idCommonLocal *v2; // r29
  idGame **p_game; // r4
  _exception *v4; // r3

  v1 = v0 - 17360;
  if ( renderSystem->BinkVideoIsLoaded(this: renderSystem) )
    renderSystem->FreeBinkVideo(this: renderSystem);
  renderSystem->EndAutomaticBackgroundSwaps(this: renderSystem);
  idSaveGameManager::CancelAllProcessors(this: session->saveGameManager, forceCancelInFlightProcessor: true);
  v2 = *(idCommonLocal **)(v1 + 17380);
  idCommonLocal::StopLevelLoad(this: v2, loadVirtualTextures: false);
  p_game = &v2->game;
  if ( v2->game != nullptr )
    gameSystem->FreeGame(this: gameSystem, a2: p_game);
  v4 = (_exception *)((int (__fastcall *)(idSession *, idGame **))session->QuitMatchToTitle)(a1: session, a2: p_game);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: v4) == 0 )
    idCommonLocal::LoadMainMenu(this: v2);
  *(_BYTE *)(v1 + 82) = **(_BYTE **)(v1 + 96);
  CxxThrowException(pExceptionObject: (void *)(v1 + 82), pThrowInfo: (const _s__ThrowInfo *)&TI1_AVidException__);
}


// ========================================================================
// $M237311
// EA  : 0x82661B1C
// RVA : 0x00661B1C
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _M237311()
{
  int v0; // r12
  int v1; // r31
  idCommonLocal *v2; // r30

  v1 = v0 - 17360;
  renderSystem->EndAutomaticBackgroundSwaps(this: renderSystem);
  idSaveGameManager::CancelAllProcessors(this: session->saveGameManager, forceCancelInFlightProcessor: true);
  v2 = *(idCommonLocal **)(v1 + 17380);
  idCommonLocal::StopLevelLoad(this: v2, loadVirtualTextures: false);
  gameSystem->FreeGame(this: gameSystem, a2: &v2->game);
  idCommonLocal::LoadMainMenu(this: v2);
  *(_BYTE *)(v1 + 81) = **(_BYTE **)(v1 + 100);
  CxxThrowException(
    pExceptionObject: (void *)(v1 + 81),
    pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidNetworkLoadException__);
}


// ========================================================================
// $LN343
// EA  : 0x82661BA8
// RVA : 0x00661BA8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _LN343()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 17360 + 336));
}


// ========================================================================
// __unwind$236830
// EA  : 0x82661BD0
// RVA : 0x00661BD0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_236830()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 17360 + 176));
}


// ========================================================================
// __unwind$237032
// EA  : 0x82661BF8
// RVA : 0x00661BF8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_237032()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 17360 + 624));
}


// ========================================================================
// __unwind$236833
// EA  : 0x82661C20
// RVA : 0x00661C20
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_236833()
{
  int v0; // r12

  gameReturn_t::~gameReturn_t(this: (gameReturn_t *)(v0 - 17360 + 5424));
}


// ========================================================================
// __unwind$236834
// EA  : 0x82661C48
// RVA : 0x00661C48
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_236834()
{
  int v0; // r12

  idSnapShot::~idSnapShot(this: (idSnapShot *)(v0 - 17360 + 112));
}


// ========================================================================
// __unwind$236835
// EA  : 0x82661C70
// RVA : 0x00661C70
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_236835()
{
  int v0; // r12

  gameReturn_t::~gameReturn_t(this: (gameReturn_t *)(v0 - 17360 + 5424));
}


// ========================================================================
// ?ExecuteMapChangeForSnapshotFile@idCommonLocal@@QAAXABVidGameSpawnInfo@@PAVidFile@@@Z
// EA  : 0x82661CA0
// RVA : 0x00661CA0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::ExecuteMapChangeForSnapshotFile(
        idCommonLocal *this,
        const idGameSpawnInfo *gameSpawnInfo,
        idFile *saveGameFile)
{
  idCompressor *compressor; // r3
  idLobbyBase *v7; // r3
  const idMatchParameters *v8; // r3
  char *data; // r4
  int v10; // [sp+50h] [-1330h] BYREF
  int v11[3]; // [sp+54h] [-132Ch] BYREF
  idStrStatic<128> v12; // [sp+60h] [-1320h] BYREF
  idMatchParameters v13; // [sp+100h] [-1280h] BYREF

  idCommonLocal::PrepareForMapChange(this);
  this->ClearWarnings(this, a2: gameSpawnInfo->mapName.data);
  if ( session->GetState(this: session) != (PARTY_LOBBY|SEARCHING) )
  {
    compressor = this->ssFileState[0].compressor;
    v11[0] = -1;
    v10 = -1;
    compressor->Read(this: compressor, a2: v11, a3: 4u);
    this->ssFileState[0].compressor->Read(this: this->ssFileState[0].compressor, a2: &v10, a3: 4u);
    v7 = session->GetActingGameStateLobbyBase(this: session);
    v8 = v7->GetMatchParms(this: v7);
    idMatchParameters::idMatchParameters(this: &v13, __that: v8);
    data = gameSpawnInfo->mapName.data;
    v13.gameMap = v11[0];
    v13.numSlots = gameSpawnInfo->numPlayers;
    v13.gameMode = v10;
    idStrStatic<128>::idStrStatic<128>(this: &v12, text: data);
    v13.mapName.len = v12.len;
    memcpy(Dst: v13.mapName.data, Src: v12.data, Size: v12.len + 1);
    idStr::FreeData(this: &v12);
    idCommonLocal::StartNewMatch(this, matchParms: &v13);
    idMatchParameters::~idMatchParameters(this: &v13);
  }
  idCommonLocal::FinalizeMapChange(this, gameSpawnInfo, saveGameFile);
}


// ========================================================================
// __unwind$237351
// EA  : 0x82661DE8
// RVA : 0x00661DE8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_237351()
{
  int v0; // r12

  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(v0 - 4992 + 256));
}


// ========================================================================
// ?ExecuteMapChange@idCommonLocal@@UAAXABVidGameSpawnInfo@@PAVidFile@@@Z
// EA  : 0x82661E18
// RVA : 0x00661E18
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::ExecuteMapChange(
        idCommonLocal *this,
        const idGameSpawnInfo *gameSpawnInfo,
        idFile *saveGameFile)
{
  pacifierState_t v6; // r4
  pacifierState_t v7; // r4
  idGame *game; // r11
  idGame *v9; // r11
  bool v10; // r30
  idGame *v11; // r11
  const idStr *v12; // [sp+8h] [-13B8h]
  const idStr *v13; // [sp+Ch] [-13B4h]
  const idStr *v14; // [sp+10h] [-13B0h]
  const idStr *v15; // [sp+14h] [-13ACh]
  int v16; // [sp+18h] [-13A8h]
  int v17; // [sp+1Ch] [-13A4h]
  int v18; // [sp+20h] [-13A0h]
  bool v19; // [sp+27h] [-1399h]
  bool v20; // [sp+2Bh] [-1395h]
  bool v21; // [sp+2Fh] [-1391h]
  bool v22; // [sp+33h] [-138Dh]
  bool v23; // [sp+37h] [-1389h]
  int v24; // [sp+38h] [-1388h]
  int v25; // [sp+3Ch] [-1384h]
  int v26; // [sp+40h] [-1380h]
  int v27; // [sp+44h] [-137Ch]
  int v28; // [sp+48h] [-1378h]
  int v29; // [sp+4Ch] [-1374h]
  int v30; // [sp+50h] [-1370h]
  int v31; // [sp+58h] [-1368h]
  int v32; // [sp+60h] [-1360h]
  int v33; // [sp+68h] [-1358h]
  int v34; // [sp+70h] [-1350h]
  int v35; // [sp+78h] [-1348h]
  const idStr *v36; // [sp+7Ch] [-1344h]
  int v37; // [sp+80h] [-1340h]
  const idStr *v38; // [sp+84h] [-133Ch]
  int v39; // [sp+88h] [-1338h]
  int v40; // [sp+90h] [-1330h]
  int v41; // [sp+98h] [-1328h]
  int v42; // [sp+A0h] [-1320h]
  int v43; // [sp+A8h] [-1318h]
  int v44; // [sp+B0h] [-1310h]
  int v45; // [sp+B8h] [-1308h]
  idStrStatic<2048> v46[2]; // [sp+D0h] [-12F0h] BYREF

  if ( session->GetState(this: session) == INGAME && common->IsMultiplayer(this: common) )
  {
    session->EndMatch(this: session, a2: false);
    WaitOnSession(waitingOnState: GAME_LOBBY, pacifierProgress: -1.0, pacifierState: v6, a4: 0);
    session->StartMatch(this: session);
    WaitOnSession(waitingOnState: PARTY_LOBBY|SEARCHING, pacifierProgress: -1.0, pacifierState: v7, a4: 0);
  }
  else
  {
    ++idResourceList::staleCount;
    if ( saveGameFile == nullptr )
    {
      game = this->game;
      if ( game != nullptr )
      {
        ((void (*)(void))game->GetGameDifficultySettingsForTransition)();
        this->game->SetPlayerLoadedGameDifficulty(this: this->game, a2: false);
      }
    }
    idCommonLocal::PrepareForMapChange(this);
    this->ClearWarnings(this, a2: gameSpawnInfo->mapName.data);
    idAnalysisClient::SetCurrentMap(this: &analysisClient, mapName: gameSpawnInfo->mapName.data);
    if ( session->GetState(this: session) != (PARTY_LOBBY|SEARCHING) )
    {
      *(_DWORD *)v46[0].buffer = 0;
      *(_DWORD *)&v46[0].buffer[8] = 20;
      *(_DWORD *)&v46[0].buffer[4] = &v46[0].buffer[12];
      v46[0].buffer[12] = 0;
      v46[0].allocedAndFlag = 20;
      v46[0].data = v46[0].baseBuffer;
      v46[0].len = 0;
      v46[0].baseBuffer[0] = 0;
      idGameSpawnInfo::WriteLayersToCommaSeparatedStrings(
        this: gameSpawnInfo,
        activeString: (idStr *)v46[0].buffer,
        deactiveString: &v46[0]);
      idMatchParameters::idMatchParameters(
        this: (idMatchParameters *)&v46[0].buffer[32],
        gameMode_: -1,
        searchMode_: -1,
        gameMap_: -1,
        gameType_: 0,
        numSlots_: gameSpawnInfo->numPlayers,
        matchFlags_: 0,
        mapName_: (const idStrStatic<128> *)&gameSpawnInfo->mapName,
        minRespawnDelay_: si_minRespawnDelay.valueFloat,
        timeLimit_: si_timeLimit.valueFloat,
        layersActive_: v12,
        layersDeactive_: v13,
        spawnSpot_: v14,
        debugJobName_: v15,
        debugJobState_: v16,
        scoreLimit_: v17,
        teamCount_: v18,
        swapTeams_: v19,
        stopWatch_: v20,
        comboMap_: v21,
        devmap_: v22,
        isTransitionalMapRequest_: v23,
        a23: v24,
        a24: v25,
        a25: v26,
        a26: v27,
        a27: v28,
        a28: v29,
        a29: v30,
        a30: (const idStrStatic<2048> *)v46[0].buffer,
        a31: v31,
        a32: v46,
        a33: v32,
        a34: &gameSpawnInfo->spawnSpot,
        a35: v33,
        a36: (const idStrStatic<128> *)&gameSpawnInfo->debugJobName,
        a37: v34,
        layersActive_a: (const idStr *)gameSpawnInfo->debugJobState,
        a39: v35,
        layersDeactive_a: v36,
        a41: v37,
        spawnSpot_a: v38,
        a43: v39,
        debugJobName_a: (const idStr *)si_scoreLimit.valueInteger,
        a45: v40,
        debugJobState_a: si_teamCount.valueInteger,
        a47: v41,
        a48: si_swapTeams.valueInteger != 0,
        a49: v42,
        a50: si_stopWatch.valueInteger != 0,
        a51: v43,
        scoreLimit__3: gameSpawnInfo->comboMap,
        a53: v44,
        teamCount__3: gameSpawnInfo->devmap,
        a55: v45,
        swapTeams_a: gameSpawnInfo->isTransitionalMapRequest);
      idCommonLocal::StartNewMatch(this, matchParms: (const idMatchParameters *)&v46[0].buffer[32]);
      idMatchParameters::~idMatchParameters(this: (idMatchParameters *)&v46[0].buffer[32]);
      idStr::FreeData(this: &v46[0]);
      idStr::FreeData(this: (idStr *)v46[0].buffer);
    }
    idCommonLocal::FinalizeMapChange(this, gameSpawnInfo, saveGameFile);
    if ( saveGameFile == nullptr )
    {
      v9 = this->game;
      v10 = true;
      if ( v9 != nullptr )
        v10 = ((unsigned __int8 (*)(void))v9->GetPlayerLoadedGameDifficulty)() == 0;
      if ( v10 )
      {
        v11 = this->game;
        if ( v11 != nullptr )
          ((void (*)(void))v11->SetGameDifficultySettingsForTransition)();
      }
    }
  }
}


// ========================================================================
// __unwind$237454
// EA  : 0x82662170
// RVA : 0x00662170
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_237454()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5056 + 240));
}


// ========================================================================
// __unwind$237455
// EA  : 0x82662198
// RVA : 0x00662198
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_237455()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5056 + 208));
}


// ========================================================================
// __unwind$237456
// EA  : 0x826621C0
// RVA : 0x006621C0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_237456()
{
  int v0; // r12

  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(v0 - 5056 + 272));
}


// ========================================================================
// ?PlaySnapshotFile@idCommonLocal@@UAAXPAVidFile@@I@Z
// EA  : 0x826621F0
// RVA : 0x006621F0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
void __fastcall idCommonLocal::PlaySnapshotFile(idCommonLocal *this, idFile *file, unsigned int tag)
{
  __int64 v3; // r4
  int v4; // r30
  int v5; // r24
  int v6; // r5
  __int64 v7; // r27
  const char *v8; // r3
  idCompressor *v9; // r3
  idCompressor *v10; // r3
  int v11; // r4
  int v12; // r5
  int v13; // r3
  int v14; // r4
  int v15; // r29
  int v16; // r28
  int v17; // r28
  int v18; // r29
  __int64 *v19; // r29
  int v20; // r11
  __int64 v21; // r8
  idSnapShot *v22; // r3
  idSnapShot *v23; // r3
  __int64 v24; // r11
  idCVar *v25; // r9
  const char *v26; // r3
  int v27; // [sp+50h] [-15250h] BYREF
  int v28; // [sp+54h] [-1524Ch] BYREF
  _DWORD v29[2]; // [sp+58h] [-15248h] BYREF
  idStr v30; // [sp+60h] [-15240h] BYREF
  idStr v31; // [sp+80h] [-15220h] BYREF
  char v32[256]; // [sp+A0h] [-15200h] BYREF
  idGameSpawnInfo v33; // [sp+1A0h] [-15100h] BYREF

  v3 = ((__int64 (*)(void))RtlCheckStack12)();
  v4 = HIDWORD(v3);
  *(_DWORD *)(HIDWORD(v3) + 1576) = v3;
  v5 = v3;
  HIDWORD(v7) = v6;
  if ( (_DWORD)v3 == 0 )
  {
    idLib::Printf(fmt: "PlaySnapshotFile: invalid file\n");
    return;
  }
  v8 = (const char *)(*(int (__fastcall **)(_DWORD))(*(_DWORD *)v3 + 4))(a1: v3);
  idLib::Printf(fmt: "Playing %s\n", v8);
  v9 = idCompressor::AllocLZW();
  *(_DWORD *)(v4 + 1572) = v9;
  v9->Init(this: v9, a2: *(idFile **)(v4 + 1576), a3: false, a4: 8);
  v10 = idCompressor::AllocRunLength_ZeroBased();
  *(_DWORD *)(v4 + 1568) = v10;
  v10->Init(this: v10, a2: *(idFile **)(v4 + 1572), a3: false, a4: 8);
  (*(void (__fastcall **)(_DWORD, _DWORD *, int))(**(_DWORD **)(v4 + 1568) + 12))(
    a1: *(_DWORD *)(v4 + 1568),
    a2: v29,
    a3: 4);
  if ( v29[0] != HIDWORD(v7) )
  {
    (*(void (__fastcall **)(int))(*(_DWORD *)v4 + 272))(a1: v4);
    (*(void (__fastcall **)(int))(*(_DWORD *)v4 + 276))(a1: v4);
    *(_DWORD *)(v4 + 25240) = 0;
    idLib::Error(fmt: "invalid demo TAG %i", HIDWORD(v7));
  }
  (*(void (__fastcall **)(_DWORD, int *, int))(**(_DWORD **)(v4 + 1568) + 12))(
    a1: *(_DWORD *)(v4 + 1568),
    a2: &v28,
    a3: 4);
  if ( v28 != 3 )
  {
    (*(void (__fastcall **)(int))(*(_DWORD *)v4 + 272))(a1: v4);
    (*(void (__fastcall **)(int))(*(_DWORD *)v4 + 276))(a1: v4);
    v11 = v28;
    *(_DWORD *)(v4 + 25240) = 0;
    idLib::Error(fmt: "incompatible demo version: %d, should be %d", v11, 3);
  }
  v12 = 64;
  if ( HIDWORD(v7) != 1145392463 )
    v12 = 28;
  idGameSpawnInfo::idGameSpawnInfo(this: &v33, mapName_: &byte_8200D768, gameFlags_: v12);
  idFile::ReadString(this: *(idFile **)(v4 + 1568), string: &v33.mapName);
  idFile::ReadString(this: *(idFile **)(v4 + 1568), string: &v33.debugJobName);
  (*(void (__fastcall **)(_DWORD, int *, int))(**(_DWORD **)(v4 + 1568) + 12))(
    a1: *(_DWORD *)(v4 + 1568),
    a2: &v33.debugJobState,
    a3: 4);
  (*(void (__fastcall **)(_DWORD, bool *, int))(**(_DWORD **)(v4 + 1568) + 12))(
    a1: *(_DWORD *)(v4 + 1568),
    a2: &v33.comboMap,
    a3: 1);
  (*(void (__fastcall **)(_DWORD, bool *, int))(**(_DWORD **)(v4 + 1568) + 12))(
    a1: *(_DWORD *)(v4 + 1568),
    a2: &v33.devmap,
    a3: 1);
  (*(void (__fastcall **)(_DWORD, int *, int))(**(_DWORD **)(v4 + 1568) + 12))(
    a1: *(_DWORD *)(v4 + 1568),
    a2: &v33.numPlayers,
    a3: 4);
  v13 = *(_DWORD *)(v4 + 1568);
  LODWORD(v7) = 0;
  v27 = 0;
  (*(void (__fastcall **)(int, int *, int))(*(_DWORD *)v13 + 12))(a1: v13, a2: &v27, a3: 4);
  idList<idStrStatic<128>,5>::SetNum(this: &v33.layersActive, newNum: v27);
  v14 = v27;
  v15 = 0;
  if ( v27 > 0 )
  {
    v16 = 0;
    do
    {
      idFile::ReadString(this: *(idFile **)(v4 + 1568), string: &v33.layersActive.list[v16]);
      v14 = v27;
      ++v15;
      ++v16;
    }
    while ( v15 < v27 );
  }
  idList<idStrStatic<128>,5>::SetNum(this: &v33.layersDeactive, newNum: v14);
  v17 = 0;
  if ( v27 > 0 )
  {
    v18 = 0;
    do
    {
      idFile::ReadString(this: *(idFile **)(v4 + 1568), string: &v33.layersDeactive.list[v18]);
      ++v17;
      ++v18;
    }
    while ( v17 < v27 );
  }
  v19 = (__int64 *)(v4 + 1608);
  (*(void (__fastcall **)(_DWORD, int, int))(**(_DWORD **)(v4 + 1568) + 12))(
    a1: *(_DWORD *)(v4 + 1568),
    a2: v4 + 1608,
    a3: 8);
  idCommonLocal::ExecuteMapChangeForSnapshotFile(this: (idCommonLocal *)v4, gameSpawnInfo: &v33, saveGameFile: nullptr);
  if ( HIDWORD(v7) == 1145392463 )
  {
    v20 = 3;
LABEL_19:
    *(_DWORD *)(v4 + 1564) = v20;
    goto LABEL_20;
  }
  if ( HIDWORD(v7) == 1414812236 )
  {
    v20 = 4;
    goto LABEL_19;
  }
LABEL_20:
  v22 = (idSnapShot *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x34u,
                        tag: TAG_NETWORKING,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v29[1] = v22;
  if ( v22 != nullptr )
    v23 = idSnapShot::idSnapShot(this: v22);
  else
    v23 = nullptr;
  v24 = *v19;
  v25 = (idCVar *)(*(_DWORD *)v19 - 12696);
  *(_DWORD *)(v4 + 1580) = v23;
  LODWORD(v21) = v24 + 1;
  *(_DWORD *)(v4 + 1584) = 0;
  *(_QWORD *)(v4 + 1624) = v7;
  *(_QWORD *)(v4 + 1648) = v21;
  *(_QWORD *)(v4 + 1616) = v24;
  if ( v25->valueInteger != 0 )
  {
    idStr::idStr(this: &v30, text: "screenshots/");
    idStr::Append(this: &v30, text: com_capturePath.valueString.data);
    v26 = (const char *)(*(int (__fastcall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
    idStr::idStr(this: &v31, text: v26);
    idStr::StripPath(this: &v31);
    idStr::AppendPath(this: &v30, text: v31.data);
    idStr::StripFileExtension(this: &v30);
    idStr::SetFileExtension(this: &v30, extension: "wav");
    fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: v30.data, a3: v32, a4: 256, a5: FSPATH_SAVE);
    fileSystem->CreateOSPath(this: fileSystem, a2: v32);
    idCVar::SetString(this: &com_capturePath, newValue: v32, force: true);
    idStr::FreeData(this: &v31);
    idStr::FreeData(this: &v30);
  }
  idGameSpawnInfo::~idGameSpawnInfo(this: &v33);
}


// ========================================================================
// $LN87
// EA  : 0x826626B4
// RVA : 0x006626B4
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _LN87()
{
  int v0; // r12

  idGameSpawnInfo::~idGameSpawnInfo(this: (idGameSpawnInfo *)(v0 - 21152 + 416));
}


// ========================================================================
// __unwind$237589
// EA  : 0x826626DC
// RVA : 0x006626DC
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_237589()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 21152 + 92), tag: TAG_NETWORKING);
}


// ========================================================================
// __unwind$237590
// EA  : 0x82662708
// RVA : 0x00662708
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_237590()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 21152 + 96));
}


// ========================================================================
// __unwind$237591
// EA  : 0x82662730
// RVA : 0x00662730
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_237591()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 21152 + 128));
}


// ========================================================================
// ?TimeTrialPlay_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x82662760
// RVA : 0x00662760
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::TimeTrialPlay_f(const idCmdArgs *args)
{
  const char *v1; // r4
  idFile *v2; // r3
  idStr v3; // [sp+50h] [-40h] BYREF

  if ( args->argc <= 1 )
    v1 = &byte_8200D768;
  else
    v1 = args->argv[1];
  idStr::idStr(this: &v3, text: v1);
  if ( v3.len != 0 )
  {
    idStr::DefaultFileExtension(this: &v3, extension: "tt");
    idCommonLocal::StopSnapshotFilePlayback(this: &commonLocal);
    idCommonLocal::StopSnapshotFileRecord(this: &commonLocal);
    v2 = fileSystem->OpenFileRead(this: fileSystem, a2: v3.data, a3: 1, a4: 0);
    idCommonLocal::PlaySnapshotFile(this: &commonLocal, file: v2, tag: 0x5454524Cu);
  }
  else
  {
    idLib::Printf(fmt: "Syntax: ttplay <name>\n");
  }
  idStr::FreeData(this: &v3);
}


// ========================================================================
// __unwind$237770
// EA  : 0x82662838
// RVA : 0x00662838
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_237770()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?PlayDemo_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x82662868
// RVA : 0x00662868
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::PlayDemo_f(const idCmdArgs *args)
{
  const char *v1; // r4
  idFile *v2; // r3
  idStr v3; // [sp+50h] [-40h] BYREF

  if ( args->argc <= 1 )
    v1 = &byte_8200D768;
  else
    v1 = args->argv[1];
  idStr::idStr(this: &v3, text: v1);
  if ( v3.len != 0 )
  {
    idStr::DefaultFileExtension(this: &v3, extension: "demo");
    idCommonLocal::CloseSnapshotFiles(this: &commonLocal);
    v2 = fileSystem->OpenFileRead(this: fileSystem, a2: v3.data, a3: 1, a4: 0);
    idCommonLocal::PlaySnapshotFile(this: &commonLocal, file: v2, tag: 0x44454D4Fu);
  }
  else
  {
    idLib::Printf(fmt: "Syntax: playDemo <demoName>\n");
  }
  idStr::FreeData(this: &v3);
}


// ========================================================================
// __unwind$237810
// EA  : 0x82662938
// RVA : 0x00662938
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_237810()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?CaptureDemoSounds_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x82662968
// RVA : 0x00662968
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::CaptureDemoSounds_f(const idCmdArgs *args)
{
  const char *v2; // r4
  const char *v3; // r4
  idStr *v4; // r3
  idFile *v5; // r3
  idStr v6; // [sp+60h] [-80h] BYREF
  idStr v7; // [sp+80h] [-60h] BYREF
  idStr v8[2]; // [sp+A0h] [-40h] BYREF

  if ( args->argc >= 3 )
  {
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    idStr::idStr(this: &v6, text: v2);
    if ( args->argc <= 2 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[2];
    idStr::idStr(this: &v7, text: v3);
    idStr::DefaultFileExtension(this: &v6, extension: "demo");
    cvarSystem->SetCVarInteger(this: cvarSystem, a2: "r_windowWidth", a3: 320, a4: 0);
    cvarSystem->SetCVarInteger(this: cvarSystem, a2: "r_windowHeight", a3: 240, a4: 0);
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "r_fullscreen", a3: false, a4: 0);
    cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "vid_restart");
    idCVar::SetInteger(this: &com_captureFrames, newValue: 0, force: true);
    idCVar::SetInteger(this: &com_captureSounds, newValue: 1, force: true);
    v4 = operator+(result: v8, a: &v7, b: "/sound/");
    cvarSystem->SetCVarString(this: cvarSystem, a2: "com_capturePath", a3: v4->data, a4: 0);
    idStr::FreeData(this: v8);
    cvarSystem->SetCVarInteger(this: cvarSystem, a2: "ai_debugLevel", a3: 0, a4: 0);
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "con_noPrint", a3: true, a4: 0);
    ((void (__fastcall *)(idCVarSystem *, const char *, void *, _DWORD, double))cvarSystem->SetCVarFloat)(
      a1: cvarSystem,
      a2: "s_volume_db",
      a3: &unk_821D0000,
      a4: 0,
      a5: -10.0);
    idCommonLocal::CloseSnapshotFiles(this: &commonLocal);
    v5 = fileSystem->OpenFileRead(this: fileSystem, a2: v6.data, a3: 1, a4: 0);
    idCommonLocal::PlaySnapshotFile(this: &commonLocal, file: v5, tag: 0x44454D4Fu);
    idStr::FreeData(this: &v7);
    idStr::FreeData(this: &v6);
  }
  else
  {
    idLib::Printf(fmt: "Syntax: captureDemoSounds demo outname");
  }
}


// ========================================================================
// __unwind$237851
// EA  : 0x82662BBC
// RVA : 0x00662BBC
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_237851()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$237852
// EA  : 0x82662BE4
// RVA : 0x00662BE4
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_237852()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// __unwind$237853
// EA  : 0x82662C0C
// RVA : 0x00662C0C
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_237853()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 160));
}


// ========================================================================
// ?CaptureDemoFrames_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x82662C40
// RVA : 0x00662C40
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __fastcall idCommonLocal::CaptureDemoFrames_f(const idCmdArgs *args)
{
  const char *v2; // r4
  const char *v3; // r4
  const char *v4; // r4
  unsigned int v5; // r28
  char *v6; // r5
  idStr *v7; // r3
  idFile *v8; // r3
  idStr v9; // [sp+60h] [-B0h] BYREF
  idStr v10; // [sp+80h] [-90h] BYREF
  idStr v11; // [sp+A0h] [-70h] BYREF
  idStr v12[2]; // [sp+C0h] [-50h] BYREF

  if ( args->argc >= 3 )
  {
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    idStr::idStr(this: &v9, text: v2);
    if ( args->argc <= 2 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[2];
    idStr::idStr(this: &v10, text: v3);
    if ( args->argc <= 3 )
      v4 = &byte_8200D768;
    else
      v4 = args->argv[3];
    idStr::idStr(this: &v11, text: v4);
    v5 = (_cntlzw(idStr::Icmp(s1: v11.data, s2: "fast")) & 0x20) != 0;
    idStr::StripFileExtension(this: &v10);
    idStr::DefaultFileExtension(this: &v9, extension: "demo");
    cvarSystem->SetCVarInteger(this: cvarSystem, a2: "r_windowWidth", a3: v5 == 0 ? 1280 : 424, a4: 0);
    cvarSystem->SetCVarInteger(this: cvarSystem, a2: "r_windowHeight", a3: v5 == 0 ? 720 : 240, a4: 0);
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "r_fullscreen", a3: false, a4: 0);
    cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "vid_restart");
    idCVar::SetInteger(this: &com_captureFrames, newValue: 1, force: true);
    idCVar::SetInteger(this: &com_captureSounds, newValue: 0, force: true);
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "com_captureTGA", a3: (_cntlzw(v5) & 0x20) != 0, a4: 0);
    if ( v5 != 0 )
      v6 = "/fast/";
    else
      v6 = "/frames/";
    v7 = operator+(result: v12, a: &v10, b: v6);
    cvarSystem->SetCVarString(this: cvarSystem, a2: "com_capturePath", a3: v7->data, a4: 0);
    idStr::FreeData(this: v12);
    cvarSystem->SetCVarInteger(this: cvarSystem, a2: "ai_debugLevel", a3: 0, a4: 0);
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "con_noPrint", a3: true, a4: 0);
    idCommonLocal::CloseSnapshotFiles(this: &commonLocal);
    v8 = fileSystem->OpenFileRead(this: fileSystem, a2: v9.data, a3: 1, a4: 0);
    idCommonLocal::PlaySnapshotFile(this: &commonLocal, file: v8, tag: 0x44454D4Fu);
    idStr::FreeData(this: &v11);
    idStr::FreeData(this: &v10);
    idStr::FreeData(this: &v9);
  }
  else
  {
    idLib::Printf(fmt: "Syntax: captureDemoFrames demo outpath [fast]");
  }
}


// ========================================================================
// __unwind$237931
// EA  : 0x82662F18
// RVA : 0x00662F18
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_237931()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$237932
// EA  : 0x82662F40
// RVA : 0x00662F40
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_237932()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 128));
}


// ========================================================================
// __unwind$237933
// EA  : 0x82662F68
// RVA : 0x00662F68
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_237933()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 160));
}


// ========================================================================
// __unwind$237934
// EA  : 0x82662F90
// RVA : 0x00662F90
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_237934()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 192));
}


// ========================================================================
// ?RestartMap_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x82662FC0
// RVA : 0x00662FC0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
void __fastcall idCommonLocal::RestartMap_f(const idCmdArgs *args)
{
  const idGameSpawnInfo *v1; // r3
  idFile_SaveGame *v2; // r3
  idFile_SaveGame *v3; // r3
  idStrStatic<1024> v4; // [sp+50h] [-154F0h] BYREF
  idGameSpawnInfo v5; // [sp+470h] [-150D0h] BYREF

  ((void (__fastcall *)(const idCmdArgs *))RtlCheckStack12)(a1: args);
  if ( commonLocal.game->IsGameActive(this: commonLocal.game) )
  {
    if ( commonLocal.game != nullptr )
      commonLocal.game->Playtest_SaveAndClear(this: commonLocal.game);
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "g_stopTime", a3: false, a4: 0);
    v1 = commonLocal.game->GetGameSpawnInfo(this: commonLocal.game);
    idGameSpawnInfo::idGameSpawnInfo(this: &v5, __that: v1);
    idStrStatic<1024>::idStrStatic<1024>(this: &v4, text: &byte_8200D768);
    v5.spawnSpotOverride.len = v4.len;
    memcpy(Dst: v5.spawnSpotOverride.data, Src: v4.data, Size: v4.len + 1);
    idStr::FreeData(this: &v4);
    if ( commonLocal.game->GetMapStartInfoFile(this: commonLocal.game) != nullptr )
    {
      v2 = commonLocal.game->GetMapStartInfoFile(this: commonLocal.game);
      idFile_Memory::MakeReadOnly(this: v2);
    }
    v5.isTransitionalMapRequest = true;
    v3 = commonLocal.game->GetMapStartInfoFile(this: commonLocal.game);
    idCommonLocal::ExecuteMapChange(this: &commonLocal, gameSpawnInfo: &v5, saveGameFile: v3);
    idGameSpawnInfo::~idGameSpawnInfo(this: &v5);
  }
  else
  {
    idLib::Printf(fmt: "restartMap only works if a map is running!");
  }
}


// ========================================================================
// __unwind$238039
// EA  : 0x82663140
// RVA : 0x00663140
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_238039()
{
  int v0; // r12

  idGameSpawnInfo::~idGameSpawnInfo(this: (idGameSpawnInfo *)(v0 - 21824 + 1136));
}


// ========================================================================
// ?RestartMapFromStart_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82663170
// RVA : 0x00663170
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
void __fastcall RestartMapFromStart_f(const idCmdArgs *args)
{
  idFile_SaveGame *v1; // r3
  idGame *game; // r29
  idGame_vtbl *v3; // r28
  idFile_SaveGame *v4; // r3
  idFile_SaveGame *v5; // r3
  idFile_SaveGame *v6; // r3
  idGameSpawnInfo v7; // [sp+50h] [-150E0h] BYREF

  ((void (*)(void))RtlCheckStack12)();
  if ( commonLocal.game->IsGameActive(this: commonLocal.game) )
  {
    if ( commonLocal.game != nullptr )
      commonLocal.game->Playtest_SaveAndClear(this: commonLocal.game);
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "g_stopTime", a3: false, a4: 0);
    idGameSpawnInfo::idGameSpawnInfo(this: &v7, mapName_: &byte_8200D768, gameFlags_: 0);
    if ( commonLocal.game->GetMapStartInfoFile(this: commonLocal.game) != nullptr )
    {
      v1 = commonLocal.game->GetMapStartInfoFile(this: commonLocal.game);
      idFile_Memory::MakeReadOnly(this: v1);
      game = commonLocal.game;
      v3 = commonLocal.game->__vftable;
      v4 = commonLocal.game->GetMapStartInfoFile(this: commonLocal.game);
      v3->LoadCheckpointInfo(this: game, a2: v4, a3: &v7);
      v5 = commonLocal.game->GetMapStartInfoFile(this: commonLocal.game);
      idFile_Memory::MakeReadOnly(this: v5);
    }
    v7.isTransitionalMapRequest = true;
    v6 = commonLocal.game->GetMapStartInfoFile(this: commonLocal.game);
    idCommonLocal::ExecuteMapChange(this: &commonLocal, gameSpawnInfo: &v7, saveGameFile: v6);
    idGameSpawnInfo::~idGameSpawnInfo(this: &v7);
  }
  else
  {
    idLib::Printf(fmt: "restartMap only works if a map is running!");
  }
}


// ========================================================================
// __unwind$238102_0
// EA  : 0x826632E8
// RVA : 0x006632E8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_238102_0()
{
  int v0; // r12

  idGameSpawnInfo::~idGameSpawnInfo(this: (idGameSpawnInfo *)(v0 - 20784 + 80));
}


// ========================================================================
// ?RestartMapFromMemoryCheckpoint_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82663318
// RVA : 0x00663318
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
void __fastcall RestartMapFromMemoryCheckpoint_f(const idCmdArgs *args)
{
  idFile_SaveGame *v1; // r3
  idGame *game; // r29
  idGame_vtbl *v3; // r28
  idFile_SaveGame *v4; // r3
  idFile_SaveGame *v5; // r3
  idFile_SaveGame *v6; // r3
  idGameSpawnInfo v7; // [sp+50h] [-150E0h] BYREF

  ((void (*)(void))RtlCheckStack12)();
  if ( commonLocal.game->IsGameActive(this: commonLocal.game) )
  {
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "g_stopTime", a3: false, a4: 0);
    idGameSpawnInfo::idGameSpawnInfo(this: &v7, mapName_: &byte_8200D768, gameFlags_: 0);
    if ( commonLocal.game->GetCheckpointInfoFile(this: commonLocal.game) != nullptr )
    {
      v1 = commonLocal.game->GetCheckpointInfoFile(this: commonLocal.game);
      idFile_Memory::MakeReadOnly(this: v1);
      game = commonLocal.game;
      v3 = commonLocal.game->__vftable;
      v4 = commonLocal.game->GetCheckpointInfoFile(this: commonLocal.game);
      v3->LoadCheckpointInfo(this: game, a2: v4, a3: &v7);
      v5 = commonLocal.game->GetCheckpointInfoFile(this: commonLocal.game);
      idFile_Memory::MakeReadOnly(this: v5);
    }
    v7.isTransitionalMapRequest = true;
    v7.useLoadingVideo = false;
    v6 = commonLocal.game->GetCheckpointInfoFile(this: commonLocal.game);
    idCommonLocal::ExecuteMapChange(this: &commonLocal, gameSpawnInfo: &v7, saveGameFile: v6);
    idGameSpawnInfo::~idGameSpawnInfo(this: &v7);
  }
  else
  {
    idLib::Printf(fmt: "restartMap only works if a map is running!");
  }
}


// ========================================================================
// __unwind$238156
// EA  : 0x82663484
// RVA : 0x00663484
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_238156()
{
  int v0; // r12

  idGameSpawnInfo::~idGameSpawnInfo(this: (idGameSpawnInfo *)(v0 - 20784 + 80));
}


// ========================================================================
// ?RestartMapHere_f@idCommonLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x826634B8
// RVA : 0x006634B8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
void __fastcall idCommonLocal::RestartMapHere_f(const idCmdArgs *args)
{
  const idGameSpawnInfo *v1; // r3
  idFile_SaveGame *v2; // r3
  idFile_SaveGame *v3; // r3
  idGameLock v4[4]; // [sp+50h] [-15E10h] BYREF
  idStrStatic<1024> v5; // [sp+60h] [-15E00h] BYREF
  idCmdArgs v6; // [sp+480h] [-159E0h] BYREF
  idGameSpawnInfo v7; // [sp+D90h] [-150D0h] BYREF

  ((void (__fastcall *)(const idCmdArgs *))RtlCheckStack12)(a1: args);
  if ( commonLocal.game->IsGameActive(this: commonLocal.game) )
  {
    if ( commonLocal.game != nullptr )
      commonLocal.game->Playtest_SaveAndClear(this: commonLocal.game);
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "g_stopTime", a3: false, a4: 0);
    v6.argc = 0;
    Cmd_GetViewpos_f(args: &v6);
    v1 = commonLocal.game->GetGameSpawnInfo(this: commonLocal.game);
    idGameSpawnInfo::idGameSpawnInfo(this: &v7, __that: v1);
    idStrStatic<1024>::idStrStatic<1024>(this: &v5, text: &byte_8200D768);
    v7.spawnSpotOverride.len = v5.len;
    memcpy(Dst: v7.spawnSpotOverride.data, Src: v5.data, Size: v5.len + 1);
    idStr::FreeData(this: &v5);
    if ( commonLocal.game->GetMapStartInfoFile(this: commonLocal.game) != nullptr )
    {
      v2 = commonLocal.game->GetMapStartInfoFile(this: commonLocal.game);
      idFile_Memory::MakeReadOnly(this: v2);
    }
    v7.isTransitionalMapRequest = true;
    v3 = commonLocal.game->GetMapStartInfoFile(this: commonLocal.game);
    idCommonLocal::ExecuteMapChange(this: &commonLocal, gameSpawnInfo: &v7, saveGameFile: v3);
    idGameLock::idGameLock(this: v4, newGame: commonLocal.game);
    idCmdArgs::AppendArg(this: &v6, text: "setviewpos");
    idCmdArgs::AppendArg(this: &v6, text: "last");
    Cmd_SetViewpos_f(args: &v6);
    idGameLock::~idGameLock(this: v4);
    idGameSpawnInfo::~idGameSpawnInfo(this: &v7);
  }
  else
  {
    idLib::Printf(fmt: "restartMapHere only works if a map is running!");
  }
}


// ========================================================================
// __unwind$238203
// EA  : 0x82663684
// RVA : 0x00663684
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_238203()
{
  int v0; // r12

  idGameSpawnInfo::~idGameSpawnInfo(this: (idGameSpawnInfo *)(v0 - 24160 + 3472));
}


// ========================================================================
// __unwind$238205
// EA  : 0x826636AC
// RVA : 0x006636AC
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void _unwind_238205()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 24160 + 80));
}


// ========================================================================
// `dynamic initializer for 'si_timeLimit''
// EA  : 0x8333A0E0
// RVA : 0x0133A0E0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_timeLimit__()
{
  idCVar::idCVar(
    this: &si_timeLimit,
    name: "si_timeLimit",
    value: "0",
    flags: 4,
    description: "Time limit",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_timeLimit__);
}


// ========================================================================
// `dynamic initializer for 'si_scoreLimit''
// EA  : 0x8333A138
// RVA : 0x0133A138
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_scoreLimit__()
{
  idCVar::idCVar(
    this: &si_scoreLimit,
    name: "si_scoreLimit",
    value: "0",
    flags: 2,
    description: "Score limit",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_scoreLimit__);
}


// ========================================================================
// `dynamic initializer for 'si_teamCount''
// EA  : 0x8333A190
// RVA : 0x0133A190
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_teamCount__()
{
  idCVar::idCVar(
    this: &si_teamCount,
    name: "si_teamCount",
    value: "2",
    flags: 2,
    description: "How many teams, 0 for FFA",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_teamCount__);
}


// ========================================================================
// `dynamic initializer for 'si_minRespawnDelay''
// EA  : 0x8333A1E8
// RVA : 0x0133A1E8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_minRespawnDelay__()
{
  idCVar::idCVar(
    this: &si_minRespawnDelay,
    name: "si_minRespawnDelay",
    value: "5",
    flags: 4,
    description: "Minimum respawn delay after player death in MP game",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_minRespawnDelay__);
}


// ========================================================================
// `dynamic initializer for 'si_swapTeams''
// EA  : 0x8333A240
// RVA : 0x0133A240
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_swapTeams__()
{
  idCVar::idCVar(
    this: &si_swapTeams,
    name: "si_swapTeams",
    value: "0",
    flags: 1,
    description: "Swap teams and do two rounds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_swapTeams__);
}


// ========================================================================
// `dynamic initializer for 'si_stopWatch''
// EA  : 0x8333A298
// RVA : 0x0133A298
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_stopWatch__()
{
  idCVar::idCVar(
    this: &si_stopWatch,
    name: "si_stopWatch",
    value: "0",
    flags: 1,
    description: "If swap teams is enabled, do stopwatch as well",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_stopWatch__);
}


// ========================================================================
// `dynamic initializer for 'si_oneFlagCTF''
// EA  : 0x8333A2F0
// RVA : 0x0133A2F0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_oneFlagCTF__()
{
  idCVar::idCVar(
    this: &si_oneFlagCTF,
    name: "si_oneFlagCTF",
    value: "0",
    flags: 1,
    description: "If swap teams is enabled and is CTF, it will do one flag",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_oneFlagCTF__);
}


// ========================================================================
// `dynamic initializer for 'com_profileLevelLoad''
// EA  : 0x8333A348
// RVA : 0x0133A348
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_profileLevelLoad__()
{
  idCVar::idCVar(
    this: &com_profileLevelLoad,
    name: "com_profileLevelLoad",
    value: "0",
    flags: 0,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_profileLevelLoad__);
}


// ========================================================================
// `dynamic initializer for 'si_spawnspot''
// EA  : 0x8333A3A0
// RVA : 0x0133A3A0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_spawnspot__()
{
  idCVar::idCVar(
    this: &si_spawnspot,
    name: "si_spawnspot",
    value: "player_start",
    flags: 0,
    description: "name of the spawn spot to use with the map command",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_spawnspot__);
}


// ========================================================================
// `dynamic initializer for 'si_nextlayeractive''
// EA  : 0x8333A3F8
// RVA : 0x0133A3F8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_nextlayeractive__()
{
  idCVar::idCVar(
    this: &si_nextlayeractive,
    name: "si_nextlayeractive",
    value: &byte_8200D768,
    flags: 0,
    description: "game play layers to use with map the map command",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_nextlayeractive__);
}


// ========================================================================
// `dynamic initializer for 'si_nextlayerdeactive''
// EA  : 0x8333A450
// RVA : 0x0133A450
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_nextlayerdeactive__()
{
  idCVar::idCVar(
    this: &si_nextlayerdeactive,
    name: "si_nextlayerdeactive",
    value: &byte_8200D768,
    flags: 0,
    description: "game play layers to use with map the map command",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_nextlayerdeactive__);
}


// ========================================================================
// `dynamic initializer for 'si_checkpointName''
// EA  : 0x8333A4A8
// RVA : 0x0133A4A8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_checkpointName__()
{
  idCVar::idCVar(
    this: &si_checkpointName,
    name: "si_checkpointName",
    value: &byte_8200D768,
    flags: 0,
    description: "name of the checkpoint to load with the map commnd",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_checkpointName__);
}


// ========================================================================
// `dynamic initializer for 'si_jobDebugName''
// EA  : 0x8333A500
// RVA : 0x0133A500
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_jobDebugName__()
{
  idCVar::idCVar(
    this: &si_jobDebugName,
    name: "si_jobDebugName",
    value: &byte_8200D768,
    flags: 0,
    description: "if not empty, name of job to get debug information from for main menu job debug tool",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_jobDebugName__);
}


// ========================================================================
// `dynamic initializer for 'si_jobDebugState''
// EA  : 0x8333A558
// RVA : 0x0133A558
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_jobDebugState__()
{
  idCVar::idCVar(
    this: &si_jobDebugState,
    name: "si_jobDebugState",
    value: "0",
    flags: 2,
    description: "if si_jobDebugName is set, this is the state to set it to.  0 is accepted, 1 is ready, 2 is complete, 3 is for race",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_jobDebugState__);
}


// ========================================================================
// `dynamic initializer for 'si_jobDebugName_Error''
// EA  : 0x8333A5B0
// RVA : 0x0133A5B0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_jobDebugName_Error__()
{
  idCVar::idCVar(
    this: &si_jobDebugName_Error,
    name: "si_jobDebugName_Error",
    value: "0",
    flags: 1,
    description: "if set and we don't find the requested si_jobDebugName error instead of warn",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_jobDebugName_Error__);
}


// ========================================================================
// `dynamic initializer for 'si_loadAllJobsOnBuild''
// EA  : 0x8333A608
// RVA : 0x0133A608
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_loadAllJobsOnBuild__()
{
  idCVar::idCVar(
    this: &si_loadAllJobsOnBuild,
    name: "si_loadAllJobsOnBuild",
    value: "0",
    flags: 1,
    description: "if true the jobmanager will load all possible jobs on a build game.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_loadAllJobsOnBuild__);
}


// ========================================================================
// `dynamic initializer for 'si_giveSPInventoryOnBuild''
// EA  : 0x8333A660
// RVA : 0x0133A660
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_giveSPInventoryOnBuild__()
{
  idCVar::idCVar(
    this: &si_giveSPInventoryOnBuild,
    name: "si_giveSPInventoryOnBuild",
    value: "0",
    flags: 1,
    description: "if true the jobmanager will give the list of possible single player items.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_giveSPInventoryOnBuild__);
}


// ========================================================================
// `dynamic initializer for 'saveGame_allowOlderVersions''
// EA  : 0x8333A6B8
// RVA : 0x0133A6B8
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__saveGame_allowOlderVersions__()
{
  idCVar::idCVar(
    this: &saveGame_allowOlderVersions,
    name: "saveGame_allowOlderVersions",
    value: "0",
    flags: 2,
    description: "allows loading of savegames from previous versions of the game",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__saveGame_allowOlderVersions__);
}


// ========================================================================
// `dynamic initializer for 'com_useEntitiesFiles''
// EA  : 0x8333A710
// RVA : 0x0133A710
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_useEntitiesFiles__()
{
  idCVar::idCVar(
    this: &com_useEntitiesFiles,
    name: "com_useEntitiesFiles",
    value: "1",
    flags: 1,
    description: "if set use .entities files instead of .map files for production and buildgame loads",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_useEntitiesFiles__);
}


// ========================================================================
// `dynamic initializer for 'com_useExpandedEntityDefs''
// EA  : 0x8333A768
// RVA : 0x0133A768
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_useExpandedEntityDefs__()
{
  idCVar::idCVar(
    this: &com_useExpandedEntityDefs,
    name: "com_useExpandedEntityDefs",
    value: "1",
    flags: 1,
    description: "if set use entity defs with expanded inheritance for production and buildgame loads",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_useExpandedEntityDefs__);
}


// ========================================================================
// `dynamic initializer for 'si_multiplayerTestWeapons''
// EA  : 0x8333A7C0
// RVA : 0x0133A7C0
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_multiplayerTestWeapons__()
{
  idCVar::idCVar(
    this: &si_multiplayerTestWeapons,
    name: "si_multiPlayerTestWeapons",
    value: "0",
    flags: 1,
    description: "when true starts with with devmap equipment",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_multiplayerTestWeapons__);
}


// ========================================================================
// `dynamic initializer for 'RestartMapFromStart_v''
// EA  : 0x8333A818
// RVA : 0x0133A818
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__RestartMapFromStart_v__()
{
  return idCommandLink::idCommandLink(
           this: &RestartMapFromStart_v,
           cmdName: "RestartMapFromStart",
           function: RestartMapFromStart_f,
           description: "Restarts the map from the start of the level for the end user",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'RestartMapFromMemoryCheckpoint_v''
// EA  : 0x8333A840
// RVA : 0x0133A840
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__RestartMapFromMemoryCheckpoint_v__()
{
  return idCommandLink::idCommandLink(
           this: &RestartMapFromMemoryCheckpoint_v,
           cmdName: "RestartMapFromMemoryCheckpoint",
           function: RestartMapFromMemoryCheckpoint_f,
           description: "Restarts the map from the start of the level for the end user",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'mutexHitch''
// EA  : 0x8333A868
// RVA : 0x0133A868
// PDB : w:\tech5\engine\framework\common_session.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mutexHitch__()
{
  Sys_MutexCreate(handle: (_RTL_CRITICAL_SECTION **)&mutexHitch);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mutexHitch__);
}

