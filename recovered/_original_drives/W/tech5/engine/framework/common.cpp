
// ========================================================================
// `idCommonLocal::UploadCrashDumps'::`2'::idCDWriter::Run
// EA  : 0x826424C0
// RVA : 0x006424C0
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

int __fastcall _idCommonLocal::UploadCrashDumps_::_2_::idCDWriter::Run(int a1)
{
  int v2; // r29
  int v3; // r3
  __int64 v4; // r11
  int v5; // r30
  int v6; // r3
  __int64 v7; // r11
  __int128 v8; // r8

  v2 = Sys_Microseconds() >> 32;
  v3 = (*(int (__fastcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(a1 + 88) + 16))(
         a1: *(_DWORD *)(a1 + 88),
         a2: *(_DWORD *)(a1 + 72),
         a3: *(_DWORD *)(a1 + 84));
  v4 = *(_QWORD *)(a1 + 80);
  v5 = v3;
  if ( v3 == (_DWORD)v4 )
  {
    *(_DWORD *)(a1 + 72) = 0;
    *(_BYTE *)(a1 + 92) = 1;
  }
  else
  {
    *(_BYTE *)(a1 + 92) = 0;
  }
  *(_QWORD *)(a1 + 80) = (unsigned int)(v4 - v3);
  v6 = Sys_Microseconds() >> 32;
  v7 = *(_QWORD *)(a1 + 64);
  LODWORD(v8) = v7 + v5;
  DWORD2(v8) = v6 + HIDWORD(v7) - v2;
  *(_QWORD *)(a1 + 64) = v8;
  *(_QWORD *)(a1 + 56) = *(_QWORD *)((char *)&v8 + 4);
  return 0;
}


// ========================================================================
// `idCommonLocal::UploadCrashDumps'::`2'::idCDWriter::Wait
// EA  : 0x82642560
// RVA : 0x00642560
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

int __fastcall _idCommonLocal::UploadCrashDumps_::_2_::idCDWriter::Wait(int a1)
{
  int v2; // r10
  unsigned __int8 v3; // r11

  idSysThread::WaitForThread(this: (idSysThread *)a1);
  v2 = *(unsigned __int8 *)(a1 + 92);
  v3 = 0;
  *(_DWORD *)(a1 + 88) = 0;
  if ( v2 != 0 && *(_DWORD *)(a1 + 72) == 0 )
    return *(_DWORD *)(a1 + 84) == 0;
  return v3;
}


// ========================================================================
// ?ActivateTool@idCommonLocal@@UAAX_N@Z
// EA  : 0x826425C0
// RVA : 0x006425C0
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall idCommonLocal::ActivateTool(idCommonLocal *this, bool active)
{
  idCVar::SetBool(this: &com_editorActive, newValue: active, force: true);
}


// ========================================================================
// ?IsInitialized@idCommonLocal@@UBA_NXZ
// EA  : 0x826425D0
// RVA : 0x006425D0
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

BOOL __fastcall idCommonLocal::IsInitialized(idCommonLocal *this)
{
  return this->com_fullyInitialized;
}


// ========================================================================
// ?BitmapConsoleFatalError@@YAXPBD@Z
// EA  : 0x826425D8
// RVA : 0x006425D8
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall __noreturn BitmapConsoleFatalError(const char *msg)
{
  mgthread_sleep(ms: 100);
  console->DrawBitmapConsole(this: console);
  while ( 1 )
    __trap();
}


// ========================================================================
// ?Quit@idCommonLocal@@UAAXH@Z
// EA  : 0x82642610
// RVA : 0x00642610
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall idCommonLocal::Quit(idCommonLocal *this, int exitCode)
{
  this->quitExitCode = exitCode;
  this->quitFlag = true;
}


// ========================================================================
// ?SetCommandLineCVars@idCommonLocal@@AAAXABVidCmdArgs@@_N@Z
// EA  : 0x82642938
// RVA : 0x00642938
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall idCommonLocal::SetCommandLineCVars(idCommonLocal *this, const idCmdArgs *args, bool init)
{
  int argc; // r9
  int v6; // r31
  int v7; // r28
  char **argv; // r29
  const char **v9; // r27
  char *v10; // r11
  char *v11; // r11
  const char *v12; // r30
  idCVar *v13; // r3
  const char *v14; // r4

  argc = args->argc;
  v6 = 0;
  if ( args->argc > 0 )
  {
    v7 = 1;
    argv = args->argv;
    v9 = (const char **)&args->argv[1];
    do
    {
      if ( v6 < 0 || v6 >= argc )
        v10 = &byte_8200D768;
      else
        v10 = *argv;
      if ( *v10 == 43 )
      {
        if ( v6 < 0 || v6 >= argc )
          v11 = &byte_8200D768;
        else
          v11 = *argv;
        v12 = v11 + 1;
        if ( v11[1] == 0 )
        {
          ++v6;
          ++argv;
          ++v9;
          ++v7;
          if ( v6 < 0 || v6 >= argc )
            v12 = &byte_8200D768;
          else
            v12 = *argv;
        }
        if ( idStr::Icmpn(s1: v12, s2: "set", n: 3) == 0 )
        {
          ++v6;
          ++argv;
          ++v9;
          ++v7;
          if ( v6 < 0 || v6 >= args->argc )
            v12 = &byte_8200D768;
          else
            v12 = *argv;
        }
        v13 = cvarSystem->Find(this: cvarSystem, a2: v12);
        if ( v13 != nullptr && ((v13->flags & 0x4000) == 0 || init) )
        {
          if ( v7 < 0 || v7 >= args->argc )
            v14 = &byte_8200D768;
          else
            v14 = *v9;
          idCVar::SetString(this: v13, newValue: v14, force: true);
          ++argv;
          ++v6;
          ++v9;
          ++v7;
        }
      }
      argc = args->argc;
      ++argv;
      ++v9;
      ++v7;
      ++v6;
    }
    while ( v6 < args->argc );
  }
}


// ========================================================================
// ?configVersion_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82642B40
// RVA : 0x00642B40
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall configVersion_f(const idCmdArgs *args)
{
  if ( args->argc == 1 )
  {
    idLib::Printf(fmt: "Current config version is %d.\n", 1);
  }
  else if ( args->argc >= 2 && atol(nptr: args->argv[1]) < 1 )
  {
    idLib::Warning(fmt: "Unsupported config version. Execution may create invalid or strange controller bindings.");
  }
}


// ========================================================================
// ?WriteSysEvent@idCommonLocal@@AAAXABUsysEvent_t@@@Z
// EA  : 0x82642BC0
// RVA : 0x00642BC0
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall idCommonLocal::WriteSysEvent(idCommonLocal *this, const sysEvent_t *ev)
{
  this->eventFile->Write(this: this->eventFile, a2: &ev->evPtrLength, a3: 4u);
  if ( ev->evPtrLength > 0 )
    ((void (__fastcall *)(idFile *, void *))this->eventFile->Write)(a1: this->eventFile, a2: ev->evPtr);
  this->eventFile->Write(this: this->eventFile, a2: ev, a3: 4u);
  this->eventFile->Write(this: this->eventFile, a2: &ev->evValue, a3: 4u);
  this->eventFile->Write(this: this->eventFile, a2: &ev->evValue2, a3: 4u);
  this->eventFile->Write(this: this->eventFile, a2: &ev->inputDevice, a3: 4u);
}


// ========================================================================
// ?SyncAllBackgroundOperations@idCommonLocal@@UAAX_N@Z
// EA  : 0x82642CA8
// RVA : 0x00642CA8
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall idCommonLocal::SyncAllBackgroundOperations(idCommonLocal *this, bool exceptSounds)
{
  idRenderManager::ClearAllGuiModels(this: &renderManager);
  idVirtualTexturePreloader::EndPreloading(this: &virtualTexturePreloader);
  renderSystem->SyncRenderThread(this: renderSystem, a2: true);
  idVirtualTextureSystem::FinishFeedback(this: &virtualTextureSystem, lockPages: false, maxWaitTimeInSeconds: 0);
  idCollisionModelManager::WaitForAllQueries(this: collisionModelManager);
  parallelJobManager->WaitForAllJobLists(this: parallelJobManager);
  if ( com_waitForSavegames.valueInteger != 0 )
  {
    session->UpdateSignInManager(this: session);
    idSaveGameManager::WaitForAllProcessors(this: session->saveGameManager, overrideSimpleProcessorCheck: false);
  }
  soundSystem->WaitForSoundThread(this: soundSystem);
  if ( !exceptSounds )
    soundSystem->StopAllSounds(this: soundSystem);
  idStreamFileCache::Flush(this: streamFileCache);
}


// ========================================================================
// ?ResetMapHeap@idCommonLocal@@AAAXXZ
// EA  : 0x82642DC8
// RVA : 0x00642DC8
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall idCommonLocal::ResetMapHeap(idCommonLocal *this)
{
  production_t v2; // r11

  this->SyncAllBackgroundOperations(this, a2: false);
  idCommonLocal::ResetNetworkingState(this);
  idRenderManager::Clear(this: &renderManager);
  idCommonLocal::KillDialog(this);
  console->ClearEditLine(this: console);
  this->ClearWarnings(this, a2: &byte_8200D768);
  videoManager->UnbindAll(this: videoManager);
  idVirtualTextureSystem::FreeLockedPages(this: &virtualTextureSystem);
  idVirtualTextureSystem::ClearFeedback(this: &virtualTextureSystem);
  if ( idLib::production != PROD_DEVELOPMENT && renderSystem->GetNumRenderWorlds(this: renderSystem) <= 0 )
  {
    idVirtualTextureSystem::FreeDynamicMedia(this: &virtualTextureSystem);
    session->ShutdownSoundRelatedSystems(this: session);
    soundSystem->Shutdown(this: soundSystem);
    idStreamFileCache::ClearMem(this: streamFileCache, releaseProvidedMemory: true);
    idAnimRecorder::KillInstance();
    idResourceList::FreeAllDynamicResources();
    animation->FreeDynamic(this: animation);
    declManager->FreeDynamic(this: declManager);
    idTypeInfoTools::ClearWarnings(this: typeInfoTools);
    idAnimRecorder::KillInstance();
    v2 = idLib::production;
    if ( idLib::production >= PROD_PRODUCTION )
    {
      idAtomicString::FreeDynamic();
      v2 = idLib::production;
    }
    if ( com_useMapHeap.valueInteger != 0 && v2 >= PROD_PRODUCTION )
      idMem::ResetMapHeap(this: &mem);
    soundSystem->Init(this: soundSystem);
    session->InitializeSoundRelatedSystems(this: session);
  }
  idCommonLocal::InitDialog(this);
}


// ========================================================================
// ?UnRegisterMapChangeListener@idCommonLocal@@UAAXPAVidMapChangeListener@@@Z
// EA  : 0x826433F8
// RVA : 0x006433F8
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall idCommonLocal::UnRegisterMapChangeListener(
        idCommonLocal *this,
        idMapChangeListener *mapChangeListener,
        int a3,
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
        idMapChangeListener *a14)
{
  a14 = mapChangeListener;
  idList<void *,108>::RemoveFast(this: &this->mapChangeListeners, obj: &a14);
}


// ========================================================================
// ?RecordPlayback@idCommonLocal@@UAAX_NPBD@Z
// EA  : 0x82643430
// RVA : 0x00643430
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall idCommonLocal::RecordPlayback(idCommonLocal *this, BOOL record, const char *fileName)
{
  idFile *eventFile; // r3
  idFile_vtbl *v7; // r11
  recordState_t recordState; // r27
  idRegressionLocal *p_regression; // r29
  idFileSystem_vtbl *v10; // r10
  idFile *v11; // r3
  recordState_t v12; // r5
  idFile_vtbl *v13; // r11
  idFile *v14; // r3
  unsigned int (__fastcall *Write)(idFile *, const void *, unsigned int); // r7
  idFile *v16; // r3
  idFile_vtbl *v17; // r11
  idFile *v18; // r3
  int v19; // [sp+54h] [-CCh] BYREF
  idFile *v20; // [sp+58h] [-C8h]
  idFile *v21; // [sp+5Ch] [-C4h]
  idStr v22; // [sp+60h] [-C0h] BYREF
  idStr v23; // [sp+80h] [-A0h] BYREF
  idStr v24[4]; // [sp+A0h] [-80h] BYREF

  eventFile = this->eventFile;
  if ( eventFile != nullptr )
  {
    v7 = eventFile->__vftable;
    v20 = eventFile;
    ((void (__fastcall *)(idFile *, int))v7->dtr_idFile)(a1: eventFile, a2: 1);
  }
  recordState = this->recordState;
  this->eventFile = nullptr;
  this->recordState = RECORD_NONE;
  idCVar::SetBool(this: &com_fixedTic, newValue: false, force: true);
  usercmdGen->RecordPlay(this: usercmdGen, a2: 0, a3: false, a4: nullptr);
  p_regression = &this->regression;
  this->regression.SetName(this: &this->regression, a2: &byte_8200D768);
  if ( !record || recordState != RECORD_MAKE )
  {
    if ( p_regression->GetTestInProgress(this: &this->regression) && recordState == RECORD_PLAY )
    {
      p_regression->NextTest(this: &this->regression);
    }
    else if ( fileName != nullptr )
    {
      idStr::idStr(this: v24, text: fileName);
      idStr::StripFileExtension(this: v24);
      idStr::idStr(this: &v23, text: "regression/events/");
      idStr::Append(this: &v23, text: v24);
      idStr::Append(this: &v23, text: ".cmds");
      idStr::idStr(this: &v22, text: "regression/events/");
      idStr::Append(this: &v22, text: v24);
      idStr::Append(this: &v22, text: ".events");
      v10 = fileSystem->__vftable;
      if ( record )
        v11 = (idFile *)((int (*)(void))v10->OpenFileWrite)();
      else
        v11 = (idFile *)((int (*)(void))v10->OpenFileRead)();
      this->eventFile = v11;
      if ( v11 != nullptr )
      {
        if ( usercmdGen->RecordPlay(this: usercmdGen, a2: 0, a3: record, a4: v23.data) )
        {
          this->recordState = ((_cntlzw(record) & 0x20) != 0) + 1;
          idCVar::SetBool(this: &com_fixedTic, newValue: true, force: true);
          p_regression->SetName(this: &this->regression, a2: v24[0].data);
          v12 = this->recordState;
          v13 = this->eventFile->__vftable;
          v21 = this->eventFile;
          if ( v12 == RECORD_MAKE )
          {
            ((void (*)(void))v13->Write)();
            v14 = this->eventFile;
            v19 = 1;
            Write = v14->Write;
            v21 = v14;
            Write(this: v14, a2: &v19, a3: 4u);
          }
          else
          {
            ((void (*)(void))v13->Read)();
            v16 = this->eventFile;
            if ( v20 == (idFile *)6172860 )
            {
              v17 = v16->__vftable;
              v21 = this->eventFile;
              v17->Read(this: v16, a2: &this->eventFileVersion, a3: 4u);
            }
            else
            {
              this->eventFileVersion = 0;
              v16->Seek(this: v16, a2: 0, a3: FS_SEEK_SET);
            }
          }
        }
        else
        {
          idLib::Warning(fmt: "Common::RecordPlayback could not open file %s", v23.data);
          v18 = this->eventFile;
          if ( v18 != nullptr )
            ((void (__fastcall *)(idFile *, int))v18->dtr_idFile)(a1: v18, a2: 1);
          this->eventFile = nullptr;
        }
      }
      else
      {
        idLib::Warning(fmt: "Common::RecordPlayback could not open file %s", v22.data);
      }
      idStr::FreeData(this: &v22);
      idStr::FreeData(this: &v23);
      idStr::FreeData(this: v24);
    }
  }
}


// ========================================================================
// __unwind$236348
// EA  : 0x82643784
// RVA : 0x00643784
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_236348()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 160));
}


// ========================================================================
// __unwind$236349
// EA  : 0x826437AC
// RVA : 0x006437AC
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_236349()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 128));
}


// ========================================================================
// __unwind$236350
// EA  : 0x826437D4
// RVA : 0x006437D4
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_236350()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 96));
}


// ========================================================================
// ?ReadSysEvent@idCommonLocal@@AAA_NAAUsysEvent_t@@@Z
// EA  : 0x82643800
// RVA : 0x00643800
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

int __fastcall idCommonLocal::ReadSysEvent(idCommonLocal *this, sysEvent_t *ev)
{
  int *p_evPtrLength; // r27
  unsigned int v5; // r3
  void *evPtr; // r4
  unsigned int v7; // r29
  unsigned int v8; // r29
  unsigned int v9; // r29
  unsigned int v10; // r28

  p_evPtrLength = &ev->evPtrLength;
  v5 = this->eventFile->Read(this: this->eventFile, a2: &ev->evPtrLength, a3: 4u);
  evPtr = ev->evPtr;
  v7 = v5;
  if ( evPtr != nullptr )
  {
    idMem::Free(this: &mem, ptr: evPtr, align: ALIGN_16);
    ev->evPtr = nullptr;
  }
  if ( *p_evPtrLength > 0 )
    v7 += ((int (__fastcall *)(idFile *, void *))this->eventFile->Read)(a1: this->eventFile, a2: ev->evPtr);
  v8 = this->eventFile->Read(this: this->eventFile, a2: ev, a3: 4u) + v7;
  if ( this->eventFileVersion < 1 && ev->evType == SE_KEY )
  {
    v9 = this->eventFile->Read(this: this->eventFile, a2: &ev->evValue, a3: 4u) + v8;
    idLib::Warning(
      fmt: "Events values are possibley in ascii format. These may not function on consoles. Try re-recording the event file.");
  }
  else
  {
    v9 = this->eventFile->Read(this: this->eventFile, a2: &ev->evValue, a3: 4u) + v8;
  }
  v10 = this->eventFile->Read(this: this->eventFile, a2: &ev->evValue2, a3: 4u);
  if ( this->eventFile->Read(this: this->eventFile, a2: &ev->inputDevice, a3: 4u) + v10 + v9 == *p_evPtrLength + 20 )
    return 1;
  this->RecordPlayback(this, a2: false, a3: nullptr);
  return 0;
}


// ========================================================================
// ?Shutdown@idCommonLocal@@UAAXH@Z
// EA  : 0x82643D68
// RVA : 0x00643D68
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall idCommonLocal::Shutdown(idCommonLocal *this, int exitCode)
{
  memTag_t v4; // r4
  bfx::BinaryReplayLogOut *v5; // r3

  if ( !this->shutdownExecuted )
  {
    this->shutdownExecuted = true;
    idMQGraphiteClient::StopMessageSystem(this: &analysisClient);
    renderSystem->SyncRenderThread(this: renderSystem, a2: false);
    if ( commonLocal.game != nullptr )
      commonLocal.game->Playtest_SaveAndClear(this: commonLocal.game);
    idCommonLocal::KillDialog(this);
    soundSystem->StopAllSounds(this: soundSystem);
    if ( renderSystem->BinkVideoIsLoaded(this: renderSystem) )
      renderSystem->FreeBinkVideo(this: renderSystem);
    session->MoveToPressStart(this: session);
    gameSystem->FreeGame(this: gameSystem, a2: &this->game);
    this->insideUpdateScreen = false;
    idList<idKeyValue,5>::~idList<idKeyValue,5>(this: &this->loadScreenInfo);
    idLoadScreen::Shutdown(this: &loadScreen);
    idVirtualTextureSystem::Shutdown(this: &virtualTextureSystem);
    session->ShutdownSoundRelatedSystems(this: session);
    soundSystem->Shutdown(this: soundSystem);
    animation->Shutdown(this: animation);
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    usercmdGen->Shutdown(this: usercmdGen);
    idCollisionModelManager::Shutdown(this: collisionModelManager, a2: v4);
    renderSystem->Shutdown(this: renderSystem);
    idStreamFileCache::Shutdown(this: streamFileCache);
    declManager->Shutdown(this: declManager);
    gameSystem->Shutdown(this: gameSystem);
    session->Shutdown(this: session);
    parallelJobManager->Shutdown(this: parallelJobManager);
    resourceManager->Shutdown(this: resourceManager);
    idCommonLocal::idLogFileWriter::CloseLogFile(this: &this->logFileWriter);
    this->sourceControl.Shutdown(this: &this->sourceControl);
    console->Shutdown(this: console);
    this->ClearWarnings(this, a2: "Tungsten shutdown");
    idStr::Clear(this: &this->warningList.caption);
    idPhysics_StaticMulti::UpdateTime(this: nullptr);
    idPhysics_StaticMulti::UpdateTime(this: v5);
    Sys_Quit(exitCode);
    idMem::PopHeap(this: &mem);
  }
}


// ========================================================================
// __unwind$237187
// EA  : 0x82644024
// RVA : 0x00644024
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_237187()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 160 + 80));
}


// ========================================================================
// ?UploadCrashDumps@idCommonLocal@@AAAXXZ
// EA  : 0x82644328
// RVA : 0x00644328
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall idCommonLocal::UploadCrashDumps(idCommonLocal *this)
{
  _FILETIME v1; // r23
  idFileList *v2; // r16
  int v3; // r15
  const char *MachineName; // r3
  int v5; // r14
  idFile_Permanent *v6; // r3
  __int64 v7; // r19
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  va *v11; // r3
  __int64 v12; // r6
  __int64 v13; // r10
  va *v14; // r3
  char v15; // r20
  idFile *v16; // r21
  int v17; // r24
  __int64 v18; // r27
  int v19; // r25
  __int64 v20; // r10
  int v21; // r3
  unsigned int v22; // r30
  double v23; // r7
  _FILETIME v24; // r30
  __int64 v25; // r8
  int v26; // r11
  char v27; // r11
  int v28; // r3
  int v29; // r29
  idFile_Permanent *v30; // r3
  idFile_Permanent *v31; // r30
  int v32; // r25
  __int64 v33; // r7
  double v34; // r5
  double v35; // r7
  int v36; // [sp+8h] [-22D8h]
  int v37; // [sp+8h] [-22D8h]
  int v38; // [sp+Ch] [-22D4h]
  int v39; // [sp+Ch] [-22D4h]
  int v40; // [sp+10h] [-22D0h]
  int v41; // [sp+10h] [-22D0h]
  int v42; // [sp+14h] [-22CCh]
  int v43; // [sp+14h] [-22CCh]
  double v44; // [sp+18h] [-22C8h]
  int v45; // [sp+18h] [-22C8h]
  int v46; // [sp+1Ch] [-22C4h]
  int v47; // [sp+50h] [-2290h]
  __int64 v48; // [sp+58h] [-2288h]
  __int64 v49; // [sp+68h] [-2278h]
  int v50; // [sp+7Ch] [-2264h]
  _SYSTEMTIME v51; // [sp+B0h] [-2230h] BYREF
  idStr v52; // [sp+C0h] [-2220h] BYREF
  idSysThread v53; // [sp+E0h] [-2200h] BYREF
  __int64 v54; // [sp+118h] [-21C8h]
  __int64 v55; // [sp+120h] [-21C0h]
  int v56; // [sp+128h] [-21B8h]
  _FILETIME v57; // [sp+130h] [-21B0h]
  idFile *v58; // [sp+138h] [-21A8h]
  char v59; // [sp+13Ch] [-21A4h]
  _FILETIME v60[2]; // [sp+140h] [-21A0h] BYREF
  idStr v61; // [sp+150h] [-2190h] BYREF
  idList<unsigned char,37> v62; // [sp+170h] [-2170h] BYREF
  idList<unsigned char,37> v63; // [sp+180h] [-2160h] BYREF
  idStr v64; // [sp+190h] [-2150h] BYREF
  idStr v65; // [sp+1B0h] [-2130h] BYREF
  idStr v66; // [sp+1D0h] [-2110h] BYREF
  _QWORD v67[2]; // [sp+1F0h] [-20F0h] BYREF
  _FILETIME v68[4]; // [sp+200h] [-20E0h] BYREF
  va v69; // [sp+220h] [-20C0h] BYREF
  va v70; // [sp+1220h] [-10C0h] BYREF

  v2 = fileSystem->ListFilesTree(this: fileSystem, a2: "DEVKIT:\\dumps", a3: &byte_8200D768, a4: 0);
  if ( v2 != nullptr )
  {
    `eh vector constructor iterator'(
      ptr: &v62,
      size: 0x10u,
      count: 2,
      pCtor: (void (__fastcall *)(void *))idList<idVehicleKey *,5>::idList<idVehicleKey *,5>,
      pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
    v1.dwLowDateTime = 0;
    v3 = 0;
    MachineName = Sys_GetMachineName();
    idStr::idStr(this: &v65, text: MachineName);
    if ( v2->list.num > 0 )
    {
      v50 = Sys_Milliseconds();
      v49 = (__int64)v1;
      idSysThread::idSysThread(this: &v53);
      v54 = (__int64)v1;
      v55 = (__int64)v1;
      v56 = 0;
      v53.__vftable = (idSysThread_vtbl *)&`idCommonLocal::UploadCrashDumps'::`2'::idCDWriter::`vftable';
      v57 = v1;
      v58 = nullptr;
      v59 = 0;
      idSysThread::StartWorkerThread(
        this: &v53,
        name_: "CreashDump network writer",
        core: CORE_ANY,
        priority: THREAD_NORMAL,
        stackSize: 0x20000);
      idList<unsigned char,19>::SetNum(this: &v62, newNum: 0x100000);
      idList<unsigned char,19>::SetNum(this: &v63, newNum: 0x100000);
      if ( v2->list.num > 0 )
      {
        v47 = 0;
        v5 = 1;
        do
        {
          idStr::idStr(this: &v52, text: v2->list.list[v47].data);
          idStr::SlashesToBackSlashes(this: &v52);
          idStr::GetFileName(this: &v61, result: &v52);
          v6 = (idFile_Permanent *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                     size: 0x68u,
                                     tag: TAG_NEW,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
          if ( v6 != nullptr )
            HIDWORD(v7) = idFile_Permanent::idFile_Permanent(
                            this: v6,
                            relativePath: v52.data,
                            osPath: v52.data,
                            m: FS_READ,
                            create: false);
          else
            HIDWORD(v7) = 0;
          LODWORD(v7) = (*(int (__fastcall **)(_DWORD))(*(_DWORD *)HIDWORD(v7) + 36))(a1: HIDWORD(v7));
          if ( idFile_Permanent::IsOpen(this: (idFile_Permanent *)HIDWORD(v7)) && (_DWORD)v7 != 0 )
          {
            v67[0] = v1;
            v67[1] = v1;
            v68[0] = v1;
            v68[1] = v1;
            v68[2].dwHighDateTime = 0;
            GetFileAttributesExA(lpFileName: v52.data, fInfoLevelId: GetFileExInfoStandard, lpFileInformation: v67);
            FileTimeToLocalFileTime(lpFileTime: (const _FILETIME *)&v68[0].dwLowDateTime, lpLocalFileTime: v60);
            FileTimeToSystemTime(lpFileTime: v60, lpSystemTime: &v51);
            LODWORD(v8) = v51.wSecond;
            HIDWORD(v8) = v51.wMinute;
            LODWORD(v9) = v51.wHour;
            HIDWORD(v9) = v51.wDay;
            LODWORD(v10) = v51.wMonth;
            HIDWORD(v10) = v51.wYear;
            v11 = va::va(
                    this: &v69,
                    fmt: "%d.%02d.%02d-%02d.%02d.%02d",
                    a3: v10,
                    a4: v9,
                    a5: v8,
                    a6: v36,
                    a7: v38,
                    a8: v40,
                    a9: v42,
                    a10: SHIDWORD(v44),
                    a11: SLODWORD(v44));
            idStr::idStr(this: &v66, text: v11);
            HIDWORD(v12) = com_uploadDumpPath.valueString.data;
            LODWORD(v12) = "tungsten.xbox/";
            HIDWORD(v13) = v61.data;
            v14 = va::va(
                    this: &v70,
                    fmt: "%s%s%s_%s_%s",
                    a3: v12,
                    a4: __SPAIR64__((unsigned int)v66.data, (unsigned int)v65.data),
                    a5: v13,
                    a6: v37,
                    a7: v39,
                    a8: v41,
                    a9: v43,
                    a10: v45,
                    a11: v46);
            idStr::idStr(this: &v64, text: v14);
            v15 = 0;
            v16 = fileSystem->OpenFileWritePermanent(this: fileSystem, a2: v64.data, a3: 0);
            if ( v16 != nullptr )
            {
              v15 = 1;
              idLib::Printf(fmt: "Uploading crashdump %d/%d '%s' to fileserver\n", v5, v2->list.num, v61.data);
              v44 = (float)((float)v7 * (float)0.00000095367432);
              idLib::Printf(
                fmt: (const char *)HIDWORD(v44),
                LODWORD(v44),
                (unsigned int)COERCE_UNSIGNED_INT64((float)((float)v7 * (float)0.0000001)));
              console->DrawBitmapConsole(this: console);
              v17 = Sys_Milliseconds();
              LODWORD(v18) = 0;
              v48 = (__int64)v1;
              v1.dwHighDateTime = v17;
              if ( (int)v7 > 0 )
              {
                v19 = v7;
                while ( 1 )
                {
                  v21 = Sys_Milliseconds();
                  v22 = v21;
                  if ( (signed int)(v21 - v1.dwHighDateTime) > 4000 )
                  {
                    LODWORD(v20) = v21 - v17;
                    v23 = (float)((float)((float)v48 / (float)((float)v20 * (float)0.001)) * (float)0.00000095367432);
                    idLib::Printf(
                      fmt: "Uploading crashdump %d/%d: %.0f%% (%.1f MiB/s)\n",
                      v5,
                      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)((float)v48 / (float)v7) * (float)100.0))),
                      HIDWORD(v23),
                      LODWORD(v23));
                    console->DrawBitmapConsole(this: console);
                    v1.dwHighDateTime = v22;
                  }
                  v24.dwLowDateTime = v19;
                  if ( v19 >= 0x100000 )
                    v24.dwLowDateTime = 0x100000;
                  v24.dwHighDateTime = (unsigned int)&v62;
                  HIDWORD(v18) = Sys_Microseconds() >> 32;
                  if ( (*(int (__fastcall **)(_DWORD, _DWORD, unsigned int))(*(_DWORD *)HIDWORD(v7) + 12))(
                         a1: HIDWORD(v7),
                         a2: *((_DWORD *)&v62.list + 4 * v3),
                         a3: v24.dwLowDateTime) != v24.dwLowDateTime )
                  {
                    idLib::Printf(fmt: "Upload of %s failed, read error\n", v61.data);
                    goto LABEL_24;
                  }
                  LODWORD(v25) = (Sys_Microseconds() >> 32) + v49 - HIDWORD(v18);
                  v49 = v25;
                  if ( v58 != nullptr
                    && (unsigned __int8)_idCommonLocal::UploadCrashDumps_::_2_::idCDWriter::Wait(a1: (int)&v53) == 0 )
                  {
                    break;
                  }
                  v26 = *((_DWORD *)&v62.list + 4 * v3);
                  v58 = v16;
                  v57 = v24;
                  v59 = 0;
                  v56 = v26;
                  idSysThread::SignalWork(this: &v53);
                  LODWORD(v18) = v18 + 0x100000;
                  v3 ^= 1u;
                  v48 = v18;
                  v19 -= 0x100000;
                  if ( (int)v18 >= (int)v7 )
                    goto LABEL_25;
                }
                idLib::Printf(fmt: "Upload of %s failed, write error\n", v61.data);
LABEL_24:
                v15 = 0;
              }
LABEL_25:
              if ( v58 != nullptr )
              {
                idSysThread::WaitForThread(this: &v53);
                v58 = nullptr;
                if ( v59 == 0 || v56 != 0 || (v27 = 1, v57.dwLowDateTime != 0) )
                  v27 = 0;
                if ( v27 == 0 )
                {
                  idLib::Printf(fmt: "Upload of %s failed, write error\n", v61.data);
                  v15 = 0;
                }
              }
              ((void (__fastcall *)(idFile *, int))v16->dtr_idFile)(a1: v16, a2: 1);
            }
            (**(void (__fastcall ***)(_DWORD, int))HIDWORD(v7))(a1: HIDWORD(v7), a2: 1);
            v28 = fileSystem->GetFileLength(this: fileSystem, a2: v64.data);
            v29 = v28;
            if ( v15 != 0 )
            {
              if ( (_DWORD)v7 == v28 )
              {
                fileSystem->RemoveFile(this: fileSystem, a2: v52.data, a3: FSPATH_BASE);
              }
              else if ( v15 != 0 )
              {
                v30 = (idFile_Permanent *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                            size: 0x68u,
                                            tag: TAG_NEW,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
                if ( v30 != nullptr )
                  v31 = idFile_Permanent::idFile_Permanent(
                          this: v30,
                          relativePath: v52.data,
                          osPath: v52.data,
                          m: FS_READ,
                          create: false);
                else
                  v31 = nullptr;
                v32 = v31->Length(this: v31);
                ((void (__fastcall *)(idFile_Permanent *, int))v31->dtr_idFile)(a1: v31, a2: 1);
                idLib::Warning(
                  fmt: "Crashdump upload error, resulting file size error: uploaded: %lldB, local: %lldB, current local: %lldB",
                  v29,
                  (_DWORD)v7,
                  v32);
              }
            }
            idStr::FreeData(this: &v64);
            idStr::FreeData(this: &v66);
            idStr::FreeData(this: &v61);
          }
          else
          {
            (**(void (__fastcall ***)(_DWORD, int))HIDWORD(v7))(a1: HIDWORD(v7), a2: 1);
            idStr::FreeData(this: &v61);
          }
          idStr::FreeData(this: &v52);
          ++v5;
          ++v47;
        }
        while ( v5 - 1 < v2->list.num );
      }
      LODWORD(v33) = Sys_Milliseconds() - v50;
      HIDWORD(v33) = &unk_821C0000;
      idLib::Printf(
        fmt: "Upload done in %.1fs (%.1fMiB/s)\n",
        (double)v33 * 0.001,
        (double)v55 / ((double)v33 * 0.001) * 0.00000095367431640625);
      v34 = (double)v55 / ((double)v49 * 0.000001) * 0.00000095367431640625;
      v35 = (double)v55 / ((double)v54 * 0.000001) * 0.00000095367431640625;
      idLib::Printf(
        fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64((double)v49 * 0.001)),
        HIDWORD(v34),
        LODWORD(v34),
        HIDWORD(v35),
        LODWORD(v35));
      console->DrawBitmapConsole(this: console);
      idSysThread::~idSysThread(this: &v53);
    }
    idFileList::~idFileList(this: v2);
    idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
    idStr::FreeData(this: &v65);
    `eh vector destructor iterator'(
      ptr: &v62,
      size: 0x10u,
      count: 2,
      pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  }
}


// ========================================================================
// __unwind$237419
// EA  : 0x82644B60
// RVA : 0x00644B60
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_237419()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(v0 - 8928 + 368),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$237420
// EA  : 0x82644B98
// RVA : 0x00644B98
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_237420()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8928 + 432));
}


// ========================================================================
// __unwind$237421
// EA  : 0x82644BC0
// RVA : 0x00644BC0
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_237421()
{
  int v0; // r12

  idSaveGameThread::~idSaveGameThread(this: (idCommonLocal::UploadCrashDumps::__l2::idCDWriter *)(v0 - 8928 + 224));
}


// ========================================================================
// __unwind$237422
// EA  : 0x82644BE8
// RVA : 0x00644BE8
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_237422()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8928 + 192));
}


// ========================================================================
// __unwind$237423
// EA  : 0x82644C10
// RVA : 0x00644C10
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_237423()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8928 + 336));
}


// ========================================================================
// __unwind$237424
// EA  : 0x82644C38
// RVA : 0x00644C38
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall _unwind_237424(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 8928 + 88), tag: a2);
}


// ========================================================================
// __unwind$237425
// EA  : 0x82644C60
// RVA : 0x00644C60
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_237425()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8928 + 464));
}


// ========================================================================
// __unwind$237426
// EA  : 0x82644C88
// RVA : 0x00644C88
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_237426()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8928 + 400));
}


// ========================================================================
// __unwind$237427
// EA  : 0x82644CB0
// RVA : 0x00644CB0
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall _unwind_237427(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 8928 + 88), tag: a2);
}


// ========================================================================
// ?RegisterMapChangeListener@idCommonLocal@@UAAXPAVidMapChangeListener@@@Z
// EA  : 0x82644CD8
// RVA : 0x00644CD8
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall idCommonLocal::RegisterMapChangeListener(
        idCommonLocal *this,
        idMapChangeListener *mapChangeListener,
        int a3,
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
        idMapChangeListener *a14)
{
  idList<enum encounterGroupRole_t,5> *p_mapChangeListeners; // r3
  int v15; // r10
  int num; // r9
  int v17; // r11

  p_mapChangeListeners = (idList<enum encounterGroupRole_t,5> *)&this->mapChangeListeners;
  a14 = mapChangeListener;
  v15 = 0;
  num = p_mapChangeListeners->num;
  if ( num <= 0 )
    goto LABEL_7;
  v17 = 0;
  while ( (idMapChangeListener *)p_mapChangeListeners->list[v17] != mapChangeListener )
  {
    ++v15;
    ++v17;
    if ( v15 >= num )
      goto LABEL_7;
  }
  if ( v15 < 0 )
LABEL_7:
    idList<idAnimWebBlendTree *,5>::Append(this: p_mapChangeListeners, obj: (const encounterGroupRole_t *)&a14);
}


// ========================================================================
// ?Init@idCommonLocal@@UAAXHPAPBDPBD@Z
// EA  : 0x82644D50
// RVA : 0x00644D50
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall idCommonLocal::Init(idCommonLocal *this, int argc, const char **argv, const char *cmdline)
{
  int v8; // r11
  const char **v9; // r30
  int v10; // r30
  char **v11; // r29
  const char *v12; // r3
  idSession *v13; // r3
  int v14; // r4
  const char *v15; // r3
  const char *v16; // r3
  const char *ContentPackagePath; // r3
  bfx::BinaryReplayLogOut *v18; // r3
  int v19; // r6
  int v20; // r29
  BOOL v21; // r16
  char **v22; // r22
  char *v23; // r30
  int i; // r30
  int v25; // r26
  int v26; // r28
  unsigned int v27; // r30
  __int64 v28; // r10
  __int64 v29; // r8
  const char *v30; // r30
  va *v31; // r5
  idCmdSystem_vtbl *v32; // r30
  const char *ScriptP; // r3
  const char *v34; // r30
  idCVar *v35; // r29
  int v36; // r3
  int v37; // r3
  const char *v38; // r3
  idResourceManager *v39; // r3
  int *v40; // r3
  int v41; // r29
  int v42; // r3
  char *v43; // r3
  idSubtitles_VideoOverlay *v44; // r3
  int v45; // r10
  char v46; // r27
  char v47; // r28
  int v48; // r29
  const char *v49; // r22
  const char *v50; // r23
  char **v51; // r26
  const char *v52; // r30
  idCVar *v53; // r3
  char v54; // r11
  int v55; // [sp+8h] [-1C08h]
  int v56; // [sp+Ch] [-1C04h]
  int v57; // [sp+10h] [-1C00h]
  int v58; // [sp+14h] [-1BFCh]
  int v59; // [sp+18h] [-1BF8h]
  int v60; // [sp+1Ch] [-1BF4h]
  char *v61; // [sp+50h] [-1BC0h] BYREF
  const char *v62; // [sp+54h] [-1BBCh]
  const char *v63; // [sp+58h] [-1BB8h]
  idStr v64; // [sp+60h] [-1BB0h] BYREF
  idToken v65; // [sp+80h] [-1B90h] BYREF
  char v66; // [sp+C8h] [-1B48h] BYREF
  idLexer v67; // [sp+1D0h] [-1A40h] BYREF
  idCmdArgs v68; // [sp+260h] [-19B0h] BYREF
  va v69; // [sp+B70h] [-10A0h] BYREF

  idLib::Init();
  idLib::RegisterFatalErrorHandler(error: (void (__fastcall *)(const char *))BitmapConsoleFatalError);
  idParser::SetupGlobalDefines();
  v64.len = 0;
  v64.baseBuffer[0] = 0;
  v64.allocedAndFlag = 20;
  v64.data = v64.baseBuffer;
  v8 = 0;
  v68.argc = 0;
  v63 = " ";
  if ( cmdline != nullptr )
  {
    idStr::operator=(this: &v64, text: cmdline);
    idCmdArgs::TokenizeString(this: &v68, text: cmdline, keepAsStrings: true);
  }
  else
  {
    if ( argc <= 0 )
      goto LABEL_7;
    v9 = argv - 1;
    do
    {
      idStr::Append(this: &v64, text: " ");
      idStr::Append(this: &v64, text: (char *)v9[1]);
      idCmdArgs::AppendArg(this: &v68, text: *++v9);
      --argc;
    }
    while ( argc != 0 );
  }
  v8 = v68.argc;
LABEL_7:
  v10 = 0;
  v62 = &byte_8200D768;
  if ( v8 > 0 )
  {
    v11 = v68.argv;
    while ( 1 )
    {
      v12 = v10 < 0 || v10 >= v8 ? &byte_8200D768 : *v11;
      if ( idStr::Icmp(s1: v12, s2: "+rgraph_enable") == 0 )
        break;
      v8 = v68.argc;
      ++v10;
      ++v11;
      if ( v10 >= v68.argc )
        goto LABEL_17;
    }
    idPhysics_StaticMulti::UpdateTime(this: nullptr);
  }
LABEL_17:
  idPhysics_StaticMulti::UpdateTime(this: nullptr);
  Sys_SetLanguageFromSystem();
  this->ClearWarnings(this, a2: "Tungsten initialization");
  cmdSystem->Init(this: cmdSystem);
  idCVar::RegisterStaticVars();
  idCommonLocal::SetCommandLineCVars(this, args: &v68, init: true);
  idLib::headless = com_headless.valueInteger != 0;
  console->Init(this: console);
  idPrintListener::RegisterPrintListener(this: &this->warningList);
  idPrintListener::RegisterPrintListener(this: &this->refreshOnPrint);
  idLib::Printf(fmt: "%s\n", versionInfo.fullVersion);
  idLib::Printf(fmt: "%s\n", versionInfo.netVersion);
  v14 = (unsigned __int8)*fs_savepath.valueString.data;
  if ( *fs_savepath.valueString.data == 0 )
  {
    v15 = Sys_DefaultDevStoragePath();
    idCVar::SetString(this: &fs_savepath, newValue: v15, force: true);
  }
  if ( *fs_cachepath.valueString.data == 0 )
  {
    v16 = Sys_DefaultCachePath();
    idCVar::SetString(this: &fs_cachepath, newValue: v16, force: true);
  }
  if ( *fs_installpath.valueString.data == 0 )
  {
    ContentPackagePath = idSession::GetContentPackagePath(this: v13, contentIndex: v14);
    idCVar::SetString(this: &fs_installpath, newValue: ContentPackagePath, force: true);
  }
  fileSystem->Init(this: fileSystem);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&warningsFilter);
  idReportData::Init(this: &reportData);
  idLib::sourceControl = &this->sourceControl;
  idPrintListener::RegisterPrintListener(this: &this->logFileWriter);
  parallelJobManager->Init(this: parallelJobManager);
  v18 = (bfx::BinaryReplayLogOut *)&idDeclReachIK::resourceList.hashTable[243];
  v19 = v68.argc;
  v20 = 0;
  v21 = com_skipIntroVideo.valueInteger != 0;
  if ( v68.argc > 0 )
  {
    v22 = v68.argv;
    do
    {
      if ( v20 < 0 || v20 >= v19 )
        v23 = &byte_8200D768;
      else
        v23 = *v22;
      if ( *v23 == 43 )
        ++v23;
      if ( idStr::Icmp(s1: v23, s2: "idstudio") == 0 )
        com_editors |= 2u;
      if ( idStr::Icmp(s1: v23, s2: "fromGameRestart") == 0 )
        v21 = true;
      if ( idStr::Icmp(s1: v23, s2: "renderbump") == 0
        || idStr::Icmp(s1: v23, s2: "idstudio") == 0
        || (v18 = (bfx::BinaryReplayLogOut *)idStr::Icmp(s1: v23, s2: "dmap")) == nullptr )
      {
        v18 = (bfx::BinaryReplayLogOut *)((int (__fastcall *)(idCVarSystem *, const char *, _DWORD, _DWORD))cvarSystem->SetCVarBool)(
                                           a1: cvarSystem,
                                           a2: "r_fullscreen",
                                           a3: 0,
                                           a4: 0);
      }
      v19 = v68.argc;
      ++v20;
      ++v22;
    }
    while ( v20 < v68.argc );
  }
  idPhysics_StaticMulti::UpdateTime(this: v18);
  Sys_InitNetworking();
  for ( i = 0; i < 4; ++i )
  {
    idKeyInput::SetUserDeviceNumForBind(inputDeviceNum: i);
    cmdSystem->AppendCommandText(this: cmdSystem, a2: "exec default.cfg -s\n");
    idLib::Printf(fmt: "Executing default.cfg for device #%d...\n", i);
    cmdSystem->ExecuteCommandBuffer(this: cmdSystem);
  }
  resourceManager->Init(this: resourceManager);
  idKeyInput::SetUserDeviceNumForBind(inputDeviceNum: 0);
  v25 = 0;
  while ( 1 )
  {
    v26 = -1;
    v27 = fileSystem->ReadFile(this: fileSystem, a2: "tungstenConfigXenon.cfg", a3: (void **)&v61, a4: nullptr);
    if ( v61 == nullptr )
      break;
    idLexer::idLexer(this: &v67, flags_: 0);
    if ( idLexer::LoadMemory(this: &v67, ptr: v61, length_: v27, name: "tungstenConfigXenon.cfg") )
    {
      v65.floatvalue = -3.4028235e38;
      v65.allocedAndFlag = -2147483392;
      v65.baseBuffer[0] = 0;
      v65.intvalue = 0;
      memset(&v65.whiteSpaceStart_p, 0, 12);
      v66 = 0;
      v65.data = &v66;
      v65.len = 0;
      idLexer::ReadToken(this: &v67, token: &v65);
      if ( v65.type == 4 && idStr::Icmp(s1: v65.data, s2: "configVersion") == 0 )
      {
        idLexer::ReadToken(this: &v67, token: &v65);
        if ( v65.type == 3 && v65.subtype == 3 )
        {
          v26 = atol(nptr: v65.data);
          if ( v26 == 1 )
          {
            v32 = cmdSystem->__vftable;
            ScriptP = (const char *)idLexer::GetScriptP(this: (idCollisionModelLocal *)&v67);
            v32->AppendCommandText(this: cmdSystem, a2: ScriptP);
            cmdSystem->ExecuteCommandBuffer(this: cmdSystem);
            idStr::FreeData(this: &v65);
            idLexer::~idLexer(this: &v67);
            goto LABEL_62;
          }
        }
      }
      idStr::FreeData(this: &v65);
    }
    fileSystem->FreeFile(this: fileSystem, a2: v61);
    idLexer::~idLexer(this: &v67);
    v30 = ", removing from FSPATH_SAVE";
    if ( v25 != 0 )
      v30 = v62;
    if ( v26 == -1 )
      v31 = (va *)"missing";
    else
      v31 = va::va(
              this: &v69,
              fmt: "mismatch (Expecting %d, found %d)",
              a3: (unsigned int)v26 | 0x100000000LL,
              a4: v29,
              a5: v28,
              a6: v55,
              a7: v56,
              a8: v57,
              a9: v58,
              a10: v59,
              a11: v60);
    idLib::Warning(fmt: "Config \"%s\" version number %s%s", "tungstenConfigXenon.cfg", v31->buffer, v30);
    if ( v25 == 0 )
      fileSystem->RemoveFile(this: fileSystem, a2: "tungstenConfigXenon.cfg", a3: FSPATH_SAVE);
    if ( ++v25 >= 2 )
      goto LABEL_62;
  }
  idLib::Warning(fmt: "Config file \"%s\" not found", "tungstenConfigXenon.cfg");
LABEL_62:
  idCommonLocal::SetCommandLineCVars(this, args: &v68, init: false);
  idLib::Printf(fmt: "Command line is: %s\n", v64.data);
  v34 = (const char *)&joystick.joyAxis[0][2];
  renderSystem->Init(this: renderSystem);
  if ( com_uploadDumps.valueInteger != 0 )
    idCommonLocal::UploadCrashDumps(this);
  cvarSystem->ClearModifiedFlags(this: cvarSystem, a2: 0x10000);
  v35 = &sys_lang;
  v36 = idStr::Icmp(s1: sys_lang.valueString.data, s2: "japanese");
  idCVar::SetBool(this: &sys_langJapanese, newValue: v36 == 0, force: true);
  v37 = idStr::Icmp(s1: sys_lang.valueString.data, s2: "polish");
  idCVar::SetBool(this: &sys_langPolish, newValue: v37 == 0, force: true);
  if ( !idLib::headless
    && idLib::production != PROD_PRODUCTION
    && fileSystem->GetTimestamp(this: fileSystem, a2: "default.cfg", a3: false) == -1 )
  {
    v34 = v62;
    v35 = (idCVar *)cvarSystem->GetCVarString(this: cvarSystem, a2: "fs_savepath", a3: v62);
    v38 = cvarSystem->GetCVarString(this: cvarSystem, a2: "fs_basepath", a3: v34);
    idLib::FatalError(
      fmt: "Could not find default.cfg. Check paths.\nfs_basepath = '%s'\nfs_savepath = '%s'",
      v38,
      (const char *)v35);
  }
  console->InitGuiModel(this: console);
  soundSystem->Init(this: soundSystem);
  declManager->Init(this: declManager);
  gameSystem->Init(this: gameSystem);
  animation->Initialize(this: animation);
  resourceManager->SetFileHook(this: resourceManager);
  idCommonLocal::InitLanguageDict(this);
  v39 = resourceManager;
  v35->flags &= ~0x20000u;
  v39->ReleaseFileHook(this: v39);
  usercmdGen->Init(this: usercmdGen);
  Sys_InitInput();
  resourceManager->SetFileHook(this: resourceManager);
  idCodeRenderParm::ResolveIRenderParmResources();
  resourceManager->ReleaseFileHook(this: resourceManager);
  resourceManager->Init2(this: resourceManager, a2: v21);
  v40 = *((int **)v34 - 4454);
  v41 = *v40;
  v42 = (*(int (__fastcall **)(int *))(*v40 + 132))(a1: v40);
  (*(void (__fastcall **)(_DWORD, int))(v41 + 152))(a1: *((_DWORD *)v34 - 4454), a2: v42);
  idParmState::Init(this: renderThreadParmState);
  idMaterial::InitCompatibleGenericMaterials();
  (*(void (__fastcall **)(_DWORD))(**((_DWORD **)v34 - 4454) + 8))(a1: *((_DWORD *)v34 - 4454));
  console->LoadGraphics(this: console);
  idCommonLocal::InitCommands(this);
  debugMenu->Init(this: debugMenu);
  idCollisionModelManager::Init(this: collisionModelManager);
  idMem::SetOutOfMemoryCallback(this: &mem, func: StaticOutOfMemoryCallback);
  session->Initialize(this: session);
  session->InitializeSoundRelatedSystems(this: session);
  this->PrintWarnings(this);
  v43 = (char *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                  size: 0x20u,
                  tag: TAG_NEW,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  v61 = v43;
  if ( v43 != nullptr )
    v44 = idSubtitles_VideoOverlay::idSubtitles_VideoOverlay(this: (idSubtitles_VideoOverlay *)v43);
  else
    v44 = nullptr;
  this->videoOverlay = v44;
  idResourceList::MarkAllStaticResources();
  declManager->MarkStatic(this: declManager);
  idAtomicString::MarkStatic();
  idAnalysisClient::StartMessageSystem(this: &analysisClient);
  idLoadScreen::Init(this: &loadScreen);
  idCommonLocal::LoadMainMenu(this);
  if ( this->IsMultiplayer(this) )
    declManager->PrintMultiplayerDeclOverrides(this: declManager);
  console->ClearNotifyLines(this: console);
  idConsoleHistory::LoadHistoryFile(this: &consoleHistory);
  v45 = v68.argc;
  v46 = 0;
  v47 = 1;
  v48 = 0;
  if ( v68.argc > 0 )
  {
    v49 = v62;
    v50 = v63;
    v51 = v68.argv;
    do
    {
      if ( v48 < 0 || v48 >= v45 )
        v52 = v49;
      else
        v52 = *v51;
      if ( *v52 == 43 )
      {
        if ( *++v52 == 0 )
        {
          ++v48;
          ++v51;
          if ( v48 < 0 || v48 >= v45 )
            v52 = v49;
          else
            v52 = *v51;
        }
        if ( idStr::Icmp(s1: v52, s2: "set") == 0
          || (v53 = cvarSystem->Find(this: cvarSystem, a2: v52), v54 = 0, v53 != nullptr) )
        {
          v54 = 1;
        }
        v47 = v54;
        if ( v46 != 0 )
          cmdSystem->AppendCommandText(this: cmdSystem, a2: "\n");
      }
      if ( v47 == 0 )
      {
        cmdSystem->AppendCommandText(this: cmdSystem, a2: v52);
        cmdSystem->AppendCommandText(this: cmdSystem, a2: v50);
        v46 = 1;
      }
      v45 = v68.argc;
      ++v48;
      ++v51;
    }
    while ( v48 < v68.argc );
  }
  if ( v46 != 0 )
  {
    cmdSystem->AppendCommandText(this: cmdSystem, a2: "\n");
  }
  else if ( !idLib::headless )
  {
    this->game->Shell_Show(this: this->game, a2: true);
  }
  this->com_fullyInitialized = true;
  resourceManager->StartupComplete(this: resourceManager);
  cvarSystem->ClearModifiedCVars(this: cvarSystem);
  idStr::FreeData(this: &v64);
}


// ========================================================================
// $LN202
// EA  : 0x82645A44
// RVA : 0x00645A44
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _LN202()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 96));
}


// ========================================================================
// __unwind$237772
// EA  : 0x82645A6C
// RVA : 0x00645A6C
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_237772()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 7184 + 464));
}


// ========================================================================
// __unwind$237773
// EA  : 0x82645A94
// RVA : 0x00645A94
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_237773()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 128));
}


// ========================================================================
// __unwind$237774
// EA  : 0x82645ABC
// RVA : 0x00645ABC
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall _unwind_237774(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 7184 + 80), tag: a2);
}


// ========================================================================
// ??0idCommonLocal@@QAA@XZ
// EA  : 0x82645E78
// RVA : 0x00645E78
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

idCommonLocal *__fastcall idCommonLocal::idCommonLocal(idCommonLocal *this)
{
  unsigned __int64 v2; // r10
  double valueFloat; // fp13
  bool v4; // r11
  double v5; // fp12
  double v6; // fp11
  double v7; // fp13
  double v8; // fp12
  bool v9; // r11
  double v10; // fp11
  double v11; // fp13
  double v12; // fp12
  bool v13; // r11
  double v14; // fp11
  double v15; // fp13
  bool v16; // r11
  double v17; // fp12
  double v18; // fp11
  idStr v20; // [sp+60h] [-70h] BYREF
  idStr v21; // [sp+80h] [-50h] BYREF

  this->__vftable = (idCommonLocal_vtbl *)&idCommonLocal::`vftable';
  this->logFileWriter.next = nullptr;
  this->logFileWriter.threadSafe = false;
  this->logFileWriter.__vftable = (idCommonLocal::idLogFileWriter_vtbl *)&idCommonLocal::idLogFileWriter::`vftable';
  this->logFileWriter.minSeverity = SEV_PRINT;
  this->logFileWriter.logFile = nullptr;
  this->logFileWriter.recursing = false;
  this->logFileWriter.wantColor = false;
  idCommonLocal::idWarningList::idWarningList(this: &this->warningList);
  this->refreshOnPrint.next = nullptr;
  this->refreshOnPrint.threadSafe = false;
  this->refreshOnPrint.minSeverity = SEV_PRINT;
  this->refreshOnPrint.__vftable = (idCommonLocal::idRefreshOnPrint_vtbl *)&idCommonLocal::idRefreshOnPrint::`vftable';
  this->refreshOnPrint.cl = nullptr;
  this->refreshOnPrint.set = false;
  this->refreshOnPrint.wantColor = false;
  *(_WORD *)&this->com_fullyInitialized = 0;
  this->insideUpdateScreen = false;
  idSourceControlWrapper::idSourceControlWrapper(this: &this->sourceControl);
  *(_QWORD *)&this->game = 0;
  idRegressionLocal::idRegressionLocal(this: &this->regression);
  this->eventFileVersion = 0;
  LODWORD(v2) = 100000;
  this->demoMode = DEMO_NONE;
  this->snapTime = 0x100000000LL;
  this->snapRate = v2;
  this->snapCurrentTime = 0x100000000LL;
  gameReturn_t::gameReturn_t(this: &this->snapCurrent);
  gameReturn_t::gameReturn_t(this: &this->snapPrevious);
  this->queuedSnapshotFile = nullptr;
  this->queuedSnapshotFileTag = 0;
  this->shutdownExecuted = false;
  this->quitFlag = false;
  this->quitExitCode = 0;
  this->snapCurrentResidual = 0.0;
  this->autosavesEnabled = true;
  this->focusDevice = 0;
  this->pauseMenuDevice = 0;
  idStr::idStr(this: &v21, text: "Time between successive snapshots");
  idStr::idStr(this: &v20, text: "snapDeltaTime");
  idGaugeMetric::idGaugeMetric(this: &this->snapDeltaTime, _shortName: &v20, _description: &v21);
  idStr::FreeData(this: &v20);
  idStr::FreeData(this: &v21);
  this->terminationThread = nullptr;
  this->readSnapshotIndex = 0;
  this->writeSnapshotIndex = 0;
  `eh vector constructor iterator'(
    ptr: &this->receivedSnaps,
    size: 0x34u,
    count: 16,
    pCtor: (void (__fastcall *)(void *))idSnapShot::idSnapShot,
    pDtor: (void (__fastcall *)(void *))idSnapShot::~idSnapShot);
  this->optimalTimeBuffered = 0.0;
  this->userCmdFrame = 0;
  this->optimalTimeBufferedWindow = 0.0;
  this->optimalPCTBuffer = 0.5;
  idSnapShot::idSnapShot(this: &this->oldss);
  this->mapChangeListeners.list = nullptr;
  this->mapChangeListeners.granularity = 0;
  this->mapChangeListeners.memTag = 5;
  this->mapChangeListeners.listStatic = 0;
  this->mapChangeListeners.size = 0;
  this->mapChangeListeners.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->mapChangeListeners);
  valueFloat = m_sensitivity.valueFloat;
  v4 = in_invertLook.valueInteger != 0;
  v5 = joy_yawSpeed.valueFloat;
  v6 = joy_pitchSpeed.valueFloat;
  this->inputSettings[0].bindset = BIND_DEFAULT;
  this->inputSettings[0].lookInvert = v4;
  this->inputSettings[0].mouseSensScale = 1.0;
  this->inputSettings[0].absoluteAngles = false;
  this->inputSettings[0].joySensScale = 1.0;
  this->inputSettings[0].joyPitchSpeed = v6;
  this->inputSettings[0].joyYawSpeed = v5;
  this->inputSettings[0].mouseSens = valueFloat;
  v7 = m_sensitivity.valueFloat;
  v8 = joy_yawSpeed.valueFloat;
  v9 = in_invertLook.valueInteger != 0;
  v10 = joy_pitchSpeed.valueFloat;
  this->inputSettings[1].bindset = BIND_DEFAULT;
  this->inputSettings[1].joyPitchSpeed = v10;
  this->inputSettings[1].lookInvert = v9;
  this->inputSettings[1].mouseSensScale = 1.0;
  this->inputSettings[1].absoluteAngles = false;
  this->inputSettings[1].joySensScale = 1.0;
  this->inputSettings[1].joyYawSpeed = v8;
  this->inputSettings[1].mouseSens = v7;
  v11 = m_sensitivity.valueFloat;
  v12 = joy_yawSpeed.valueFloat;
  v13 = in_invertLook.valueInteger != 0;
  v14 = joy_pitchSpeed.valueFloat;
  this->inputSettings[2].bindset = BIND_DEFAULT;
  this->inputSettings[2].joyPitchSpeed = v14;
  this->inputSettings[2].lookInvert = v13;
  this->inputSettings[2].mouseSensScale = 1.0;
  this->inputSettings[2].absoluteAngles = false;
  this->inputSettings[2].joySensScale = 1.0;
  this->inputSettings[2].joyYawSpeed = v12;
  this->inputSettings[2].mouseSens = v11;
  v15 = m_sensitivity.valueFloat;
  v16 = in_invertLook.valueInteger != 0;
  v17 = joy_yawSpeed.valueFloat;
  v18 = joy_pitchSpeed.valueFloat;
  this->inputSettings[3].bindset = BIND_DEFAULT;
  this->inputSettings[3].mouseSensScale = 1.0;
  this->inputSettings[3].absoluteAngles = false;
  this->inputSettings[3].joySensScale = 1.0;
  this->inputSettings[3].lookInvert = v16;
  this->inputSettings[3].joyPitchSpeed = v18;
  this->inputSettings[3].joyYawSpeed = v17;
  this->inputSettings[3].mouseSens = v15;
  idUserCmdMgr::idUserCmdMgr(this: &this->userCmdMgr);
  this->levelLoadInProgress = 0;
  this->lastPacifierGuiTime = 0;
  this->dialogWingstickActive = false;
  this->lastPacifierSessionTime = 0;
  this->lastPacifierTooltipTime = 0;
  this->dialogPause = false;
  this->dialog = nullptr;
  this->saveIndicator = nullptr;
  this->videoOverlay = nullptr;
  this->dialogGuiModel = nullptr;
  this->saveIndicatorGuiModel = nullptr;
  this->dialogShowingSaveIndicatorRequested = false;
  this->dialogShowingSaveIndicatorTimeRemaining = 0;
  idStaticList<idDialogInfo,4>::idStaticList<idDialogInfo,4>(this: &this->messageList);
  idStaticList<idLoadScreenInfo,16>::idStaticList<idLoadScreenInfo,16>(this: &this->loadScreenInfo);
  this->savegameCheckpointFolder[0] = 0;
  this->askedToLoadFromCheckpoint = false;
  this->showedErrorLoadingGameDialog = false;
  this->savegameCheckpointPreviousDeviceId = 0;
  this->startSaveTime = 0;
  this->stopSaveTime = 0;
  this->ssFileState[0].compressor = nullptr;
  this->ssFileState[0].compressor2 = nullptr;
  this->ssFileState[0].file = nullptr;
  this->ssFileState[0].ss = nullptr;
  this->ssFileState[0].resources = 0;
  this->ssFileState[1].compressor = nullptr;
  this->ssFileState[1].compressor2 = nullptr;
  this->ssFileState[1].file = nullptr;
  this->ssFileState[1].ss = nullptr;
  this->ssFileState[1].resources = 0;
  this->snapTimeBuffered = 0.0;
  this->effectiveSnapRate = 0.0;
  this->snapCurrent.localTime = -1;
  this->snapPrevious.localTime = -1;
  this->snapCurrent.serverTime = -1;
  this->snapPrevious.serverTime = -1;
  this->totalBufferedTime = 0;
  this->totalRecvTime = 0;
  this->graph = nullptr;
  this->graphSnapRate = nullptr;
  this->purgeOverlays = false;
  this->dialogInUse = false;
  return this;
}


// ========================================================================
// __unwind$238327
// EA  : 0x8264629C
// RVA : 0x0064629C
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238327()
{
  int v0; // r12

  idCommon::~idCommon(this: *(idCommon **)(v0 - 208 + 228));
}


// ========================================================================
// __unwind$238328
// EA  : 0x826462C4
// RVA : 0x006462C4
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238328()
{
  int v0; // r12

  idPrintListener::~idPrintListener(this: (idCommonLocal::idRefreshOnPrint *)(*(_DWORD *)(v0 - 208 + 228) + 4));
}


// ========================================================================
// __unwind$238329
// EA  : 0x826462F0
// RVA : 0x006462F0
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238329()
{
  int v0; // r12

  idCommonLocal::idWarningList::~idWarningList(this: (idCommonLocal::idWarningList *)(*(_DWORD *)(v0 - 208 + 228) + 28));
}


// ========================================================================
// __unwind$238330
// EA  : 0x8264631C
// RVA : 0x0064631C
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238330()
{
  int v0; // r12

  idPrintListener::~idPrintListener(this: (idCommonLocal::idRefreshOnPrint *)(*(_DWORD *)(v0 - 208 + 228) + 252));
}


// ========================================================================
// __unwind$238331
// EA  : 0x82646348
// RVA : 0x00646348
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238331()
{
  int v0; // r12

  idSourceControlWrapper::~idSourceControlWrapper(this: (idSourceControlWrapper *)(*(_DWORD *)(v0 - 208 + 228) + 284));
}


// ========================================================================
// __unwind$238332
// EA  : 0x82646374
// RVA : 0x00646374
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238332()
{
  int v0; // r12

  idRegressionLocal::~idRegressionLocal(this: (idRegressionLocal *)(*(_DWORD *)(v0 - 208 + 228) + 384));
}


// ========================================================================
// __unwind$238333
// EA  : 0x826463A0
// RVA : 0x006463A0
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238333()
{
  int v0; // r12

  gameReturn_t::~gameReturn_t(this: (gameReturn_t *)(*(_DWORD *)(v0 - 208 + 228) + 1664));
}


// ========================================================================
// __unwind$238334
// EA  : 0x826463CC
// RVA : 0x006463CC
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238334()
{
  int v0; // r12

  gameReturn_t::~gameReturn_t(this: (gameReturn_t *)(*(_DWORD *)(v0 - 208 + 228) + 13440));
}


// ========================================================================
// __unwind$238335
// EA  : 0x826463F8
// RVA : 0x006463F8
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238335()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 128));
}


// ========================================================================
// __unwind$238336
// EA  : 0x82646420
// RVA : 0x00646420
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238336()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$238337
// EA  : 0x82646448
// RVA : 0x00646448
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238337()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 208 + 228) + 25268));
}


// ========================================================================
// __unwind$238338
// EA  : 0x82646474
// RVA : 0x00646474
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238338()
{
  int v0; // r12

  idArray<idSnapShot,16>::~idArray<idSnapShot,16>(this: (idArray<idSnapShot,16> *)(*(_DWORD *)(v0 - 208 + 228) + 25388));
}


// ========================================================================
// __unwind$238339
// EA  : 0x826464A0
// RVA : 0x006464A0
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238339()
{
  int v0; // r12

  idSnapShot::~idSnapShot(this: (idSnapShot *)(*(_DWORD *)(v0 - 208 + 228) + 26244));
}


// ========================================================================
// __unwind$238340
// EA  : 0x826464CC
// RVA : 0x006464CC
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238340()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 26296));
}


// ========================================================================
// __unwind$238341
// EA  : 0x826464F8
// RVA : 0x006464F8
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238341()
{
  int v0; // r12

  idStaticList<idDialogInfo,4>::~idStaticList<idDialogInfo,4>(this: (idStaticList<idDialogInfo,4> *)(*(_DWORD *)(v0 - 208 + 228) + 72608));
}


// ========================================================================
// ??1idCommonLocal@@UAA@XZ
// EA  : 0x826466E0
// RVA : 0x006466E0
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __fastcall idCommonLocal::~idCommonLocal(idCommonLocal *this)
{
  idDebugGraph *graph; // r29
  idDebugGraph *graphSnapRate; // r29
  idRenderModelGui *guiModel; // r3
  idSWF *loadingGui; // r29
  idSubtitles_VideoOverlay *videoOverlay; // r3

  this->__vftable = (idCommonLocal_vtbl *)&idCommonLocal::`vftable';
  graph = this->graph;
  if ( graph != nullptr )
  {
    idDebugGraph::~idDebugGraph(this: this->graph);
    idMem::Free(this: &mem, ptr: graph, align: ALIGN_16);
    this->graph = nullptr;
    graphSnapRate = this->graphSnapRate;
    if ( graphSnapRate != nullptr )
    {
      idDebugGraph::~idDebugGraph(this: this->graphSnapRate);
      idMem::Free(this: &mem, ptr: graphSnapRate, align: ALIGN_16);
    }
    this->graphSnapRate = nullptr;
  }
  guiModel = this->guiModel;
  if ( guiModel != nullptr )
  {
    ((void (__fastcall *)(idRenderModelGui *, int))guiModel->dtr_idRenderModel)(a1: guiModel, a2: 1);
    this->guiModel = nullptr;
  }
  loadingGui = this->loadingGui;
  if ( loadingGui != nullptr )
  {
    idSWF::~idSWF(this: this->loadingGui);
    idMem::Free(this: &mem, ptr: loadingGui, align: ALIGN_16);
    this->loadingGui = nullptr;
  }
  videoOverlay = this->videoOverlay;
  if ( videoOverlay != nullptr )
  {
    ((void (__fastcall *)(idSubtitles_VideoOverlay *, int))videoOverlay->dtr_idRenderVideoOverlay)(
      a1: videoOverlay,
      a2: 1);
    this->videoOverlay = nullptr;
  }
  idStaticList<idLoadScreenInfo,16>::~idStaticList<idLoadScreenInfo,16>(this: &this->loadScreenInfo);
  idStaticList<idDialogInfo,4>::~idStaticList<idDialogInfo,4>(this: &this->messageList);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->mapChangeListeners);
  idSnapShot::~idSnapShot(this: &this->oldss);
  `eh vector destructor iterator'(
    ptr: &this->receivedSnaps,
    size: 0x34u,
    count: 16,
    pDtor: (void (__fastcall *)(void *))idSnapShot::~idSnapShot);
  idMetricRecord::~idMetricRecord(this: &this->snapDeltaTime);
  gameReturn_t::~gameReturn_t(this: &this->snapPrevious);
  gameReturn_t::~gameReturn_t(this: &this->snapCurrent);
  idRegressionLocal::~idRegressionLocal(this: &this->regression);
  idSourceControlWrapper::~idSourceControlWrapper(this: &this->sourceControl);
  this->refreshOnPrint.__vftable = (idCommonLocal::idRefreshOnPrint_vtbl *)&idPrintListener::`vftable';
  idPrintListener::UnRegisterPrintListener(this: &this->refreshOnPrint);
  idCommonLocal::idWarningList::~idWarningList(this: &this->warningList);
  this->logFileWriter.__vftable = (idCommonLocal::idLogFileWriter_vtbl *)&idPrintListener::`vftable';
  idPrintListener::UnRegisterPrintListener(this: &this->logFileWriter);
  this->__vftable = (idCommonLocal_vtbl *)&idCommon::`vftable';
}


// ========================================================================
// __unwind$238619
// EA  : 0x8264689C
// RVA : 0x0064689C
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238619()
{
  int v0; // r12

  idCommon::~idCommon(this: *(idCommon **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$238620
// EA  : 0x826468C4
// RVA : 0x006468C4
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238620()
{
  int v0; // r12

  idPrintListener::~idPrintListener(this: (idCommonLocal::idRefreshOnPrint *)(*(_DWORD *)(v0 - 144 + 164) + 4));
}


// ========================================================================
// __unwind$238621
// EA  : 0x826468F0
// RVA : 0x006468F0
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238621()
{
  int v0; // r12

  idCommonLocal::idWarningList::~idWarningList(this: (idCommonLocal::idWarningList *)(*(_DWORD *)(v0 - 144 + 164) + 28));
}


// ========================================================================
// __unwind$238622
// EA  : 0x8264691C
// RVA : 0x0064691C
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238622()
{
  int v0; // r12

  idPrintListener::~idPrintListener(this: (idCommonLocal::idRefreshOnPrint *)(*(_DWORD *)(v0 - 144 + 164) + 252));
}


// ========================================================================
// __unwind$238623
// EA  : 0x82646948
// RVA : 0x00646948
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238623()
{
  int v0; // r12

  idSourceControlWrapper::~idSourceControlWrapper(this: (idSourceControlWrapper *)(*(_DWORD *)(v0 - 144 + 164) + 284));
}


// ========================================================================
// __unwind$238624
// EA  : 0x82646974
// RVA : 0x00646974
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238624()
{
  int v0; // r12

  idRegressionLocal::~idRegressionLocal(this: (idRegressionLocal *)(*(_DWORD *)(v0 - 144 + 164) + 384));
}


// ========================================================================
// __unwind$238625
// EA  : 0x826469A0
// RVA : 0x006469A0
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238625()
{
  int v0; // r12

  gameReturn_t::~gameReturn_t(this: (gameReturn_t *)(*(_DWORD *)(v0 - 144 + 164) + 1664));
}


// ========================================================================
// __unwind$238626
// EA  : 0x826469CC
// RVA : 0x006469CC
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238626()
{
  int v0; // r12

  gameReturn_t::~gameReturn_t(this: (gameReturn_t *)(*(_DWORD *)(v0 - 144 + 164) + 13440));
}


// ========================================================================
// __unwind$238627
// EA  : 0x826469F8
// RVA : 0x006469F8
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238627()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 144 + 164) + 25268));
}


// ========================================================================
// __unwind$238628
// EA  : 0x82646A24
// RVA : 0x00646A24
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238628()
{
  int v0; // r12

  idArray<idSnapShot,16>::~idArray<idSnapShot,16>(this: (idArray<idSnapShot,16> *)(*(_DWORD *)(v0 - 144 + 164) + 25388));
}


// ========================================================================
// __unwind$238629
// EA  : 0x82646A50
// RVA : 0x00646A50
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238629()
{
  int v0; // r12

  idSnapShot::~idSnapShot(this: (idSnapShot *)(*(_DWORD *)(v0 - 144 + 164) + 26244));
}


// ========================================================================
// __unwind$238630
// EA  : 0x82646A7C
// RVA : 0x00646A7C
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238630()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 26296));
}


// ========================================================================
// __unwind$238631
// EA  : 0x82646AA8
// RVA : 0x00646AA8
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238631()
{
  int v0; // r12

  idStaticList<idDialogInfo,4>::~idStaticList<idDialogInfo,4>(this: (idStaticList<idDialogInfo,4> *)(*(_DWORD *)(v0 - 144 + 164) + 72608));
}


// ========================================================================
// __unwind$238632
// EA  : 0x82646ADC
// RVA : 0x00646ADC
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void _unwind_238632()
{
  int v0; // r12

  idStaticList<idLoadScreenInfo,16>::~idStaticList<idLoadScreenInfo,16>(this: (idStaticList<idLoadScreenInfo,16> *)(*(_DWORD *)(v0 - 144 + 164) + 74000));
}


// ========================================================================
// `dynamic initializer for 'com_safemode''
// EA  : 0x83337830
// RVA : 0x01337830
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_safemode__()
{
  idCVar::idCVar(
    this: &com_safemode,
    name: "com_safemode",
    value: "0",
    flags: 17,
    description: "deletes the video.cfg & rageConfig.cfg and reverts video settings to game default",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_safemode__);
}


// ========================================================================
// `dynamic initializer for 'com_skipIntroVideo''
// EA  : 0x83337888
// RVA : 0x01337888
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_skipIntroVideo__()
{
  idCVar::idCVar(
    this: &com_skipIntroVideo,
    name: "com_skipIntroVideo",
    value: "0",
    flags: 1,
    description: "skips the intro video",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_skipIntroVideo__);
}


// ========================================================================
// `dynamic initializer for 'com_waitForSavegames''
// EA  : 0x833378E0
// RVA : 0x013378E0
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_waitForSavegames__()
{
  idCVar::idCVar(
    this: &com_waitForSavegames,
    name: "com_waitForSavegames",
    value: "1",
    flags: 1,
    description: "during map heap reset, wait for the savegames to complete",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_waitForSavegames__);
}


// ========================================================================
// `dynamic initializer for 'com_headless''
// EA  : 0x83337938
// RVA : 0x01337938
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_headless__()
{
  idCVar::idCVar(
    this: &com_headless,
    name: "com_headless",
    value: "0",
    flags: 1,
    description: "run without graphics",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_headless__);
}


// ========================================================================
// `dynamic initializer for 'com_speeds''
// EA  : 0x83337990
// RVA : 0x01337990
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_speeds__()
{
  idCVar::idCVar(
    this: &com_speeds,
    name: "com_speeds",
    value: "0",
    flags: 2,
    description: "show engine timings. 1 = print on console, 2 = print on screen, 3 = also show graph, 4 = only logging to metrics stream",
    valueMin: 0.0,
    valueMax: 4.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)&unk_821C0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_speeds__);
}


// ========================================================================
// `dynamic initializer for 'com_timescale''
// EA  : 0x833379F8
// RVA : 0x013379F8
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_timescale__()
{
  idCVar::idCVar(
    this: &com_timescale,
    name: "timescale",
    value: "1",
    flags: 4,
    description: "scales the time",
    valueMin: 0.1,
    valueMax: 10.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)&unk_821C0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_timescale__);
}


// ========================================================================
// `dynamic initializer for 'com_slowmoscale''
// EA  : 0x83337A60
// RVA : 0x01337A60
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_slowmoscale__()
{
  idCVar::idCVar(
    this: &com_slowmoscale,
    name: "slowmoscale",
    value: "1",
    flags: 4,
    description: "puts the game in slowmo",
    valueMin: 0.1,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)&unk_821C0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_slowmoscale__);
}


// ========================================================================
// `dynamic initializer for 'com_editorActive''
// EA  : 0x83337AC8
// RVA : 0x01337AC8
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_editorActive__()
{
  idCVar::idCVar(
    this: &com_editorActive,
    name: "com_editorActive",
    value: "0",
    flags: 17,
    description: "1 when an editor has focus",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_editorActive__);
}


// ========================================================================
// `dynamic initializer for 'com_captureSamples''
// EA  : 0x83337B20
// RVA : 0x01337B20
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_captureSamples__()
{
  idCVar::idCVar(
    this: &com_captureSamples,
    name: "com_captureSamples",
    value: "1",
    flags: 2,
    description: "set to number of samples for screenshots",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_captureSamples__);
}


// ========================================================================
// `dynamic initializer for 'com_capturePath''
// EA  : 0x83337B78
// RVA : 0x01337B78
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_capturePath__()
{
  idCVar::idCVar(
    this: &com_capturePath,
    name: "com_capturePath",
    value: &byte_8200D768,
    flags: 0,
    description: "optional outpath for screenshots, this path is appended to screeenshots/",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_capturePath__);
}


// ========================================================================
// `dynamic initializer for 'com_captureTGA''
// EA  : 0x83337BD0
// RVA : 0x01337BD0
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_captureTGA__()
{
  idCVar::idCVar(
    this: &com_captureTGA,
    name: "com_captureTGA",
    value: "0",
    flags: 2,
    description: "format for capture screenshots, 0 = JPG, 1 = TGA, 2 = PNG",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_captureTGA__);
}


// ========================================================================
// `dynamic initializer for 'com_capturePrimes''
// EA  : 0x83337C28
// RVA : 0x01337C28
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_capturePrimes__()
{
  idCVar::idCVar(
    this: &com_capturePrimes,
    name: "com_capturePrimes",
    value: "0",
    flags: 2,
    description: "number of prime screens to use during capturing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_capturePrimes__);
}


// ========================================================================
// `dynamic initializer for 'net_usePlatformBackend''
// EA  : 0x83337C80
// RVA : 0x01337C80
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_usePlatformBackend__()
{
  idCVar::idCVar(
    this: &net_usePlatformBackend,
    name: "net_usePlatformBackend",
    value: "1",
    flags: 1,
    description: "Depending on the platform this will use the backend rather then direct connection. (Steam on PC, Live on xbox360, psn on ps3)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_usePlatformBackend__);
}


// ========================================================================
// `dynamic initializer for 'com_multiplayer''
// EA  : 0x83337CD8
// RVA : 0x01337CD8
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_multiplayer__()
{
  idCVar::idCVar(
    this: &com_multiplayer,
    name: "com_multiplayer",
    value: "0",
    flags: 1,
    description: "enable multiplayer code paths (decls and gamecode)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_multiplayer__);
}


// ========================================================================
// `dynamic initializer for 'com_uploadDumps''
// EA  : 0x83337D30
// RVA : 0x01337D30
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_uploadDumps__()
{
  idCVar::idCVar(
    this: &com_uploadDumps,
    name: "com_uploadDumps",
    value: "1",
    flags: 1,
    description: "Upload crashdumps on boot",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_uploadDumps__);
}


// ========================================================================
// `dynamic initializer for 'com_uploadDumpPath''
// EA  : 0x83337D88
// RVA : 0x01337D88
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_uploadDumpPath__()
{
  idCVar::idCVar(
    this: &com_uploadDumpPath,
    name: "com_writeDumpPath",
    value: "nfs:4@mgfiles01.ad.machinegames.com/crashdumps/",
    flags: 0,
    description: "Path to write dumps to",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_uploadDumpPath__);
}


// ========================================================================
// `dynamic initializer for 'com_fixedTic''
// EA  : 0x83337DE0
// RVA : 0x01337DE0
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_fixedTic__()
{
  idCVar::idCVar(
    this: &com_fixedTic,
    name: "com_fixedTic",
    value: "1",
    flags: 1,
    description: "run a single game frame per render frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_fixedTic__);
}


// ========================================================================
// `dynamic initializer for 'com_traceFrame''
// EA  : 0x83337E38
// RVA : 0x01337E38
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_traceFrame__()
{
  idCVar::idCVar(
    this: &com_traceFrame,
    name: "com_traceFrame",
    value: "0",
    flags: 2,
    description: "PIX trace a full frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_traceFrame__);
}


// ========================================================================
// `dynamic initializer for 'com_useMapHeap''
// EA  : 0x83337E90
// RVA : 0x01337E90
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_useMapHeap__()
{
  idCVar::idCVar(
    this: &com_useMapHeap,
    name: "com_useMapHeap",
    value: "1",
    flags: 1,
    description: "Use a separate heap for each map load",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_useMapHeap__);
}


// ========================================================================
// `dynamic initializer for 'com_showMapLoadStatus''
// EA  : 0x83337EE8
// RVA : 0x01337EE8
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_showMapLoadStatus__()
{
  idCVar::idCVar(
    this: &com_showMapLoadStatus,
    name: "com_showMapLoadStatus",
    value: "0",
    flags: 1,
    description: "show level load pacifier text",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_showMapLoadStatus__);
}


// ========================================================================
// `dynamic initializer for 'commonLocal''
// EA  : 0x83337F40
// RVA : 0x01337F40
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__commonLocal__()
{
  idCommonLocal::idCommonLocal(this: &commonLocal);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__commonLocal__);
}


// ========================================================================
// `dynamic initializer for 'configVersion_v''
// EA  : 0x83337F78
// RVA : 0x01337F78
// PDB : w:\tech5\engine\framework\common.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__configVersion_v__()
{
  return idCommandLink::idCommandLink(
           this: &configVersion_v,
           cmdName: "configVersion",
           function: configVersion_f,
           description: "just a placeholder so we can exec config files that have versioning in them",
           argCompletion: nullptr);
}

