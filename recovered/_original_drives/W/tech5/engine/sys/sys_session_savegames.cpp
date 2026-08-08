
// ========================================================================
// ?Process@idSaveGameProcessorLoadFiles@@UAA_NXZ
// EA  : 0x829CBA90
// RVA : 0x009CBA90
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

int __fastcall idSaveGameProcessorLoadFiles::Process(idSaveGameProcessorSaveFiles *this)
{
  Sys_ExecuteSavegameCommandAsync(savegameParms: &this->parms);
  return 0;
}


// ========================================================================
// ?testSaveGameCheck_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829CBAB8
// RVA : 0x009CBAB8
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __fastcall testSaveGameCheck_f(const idCmdArgs *args)
{
  bool v1; // [sp+50h] [-10h] BYREF
  bool v2; // [sp+51h] [-Fh] BYREF

  Sys_SaveGameCheck(exists: &v2, autosaveExists: &v1);
  idLib::Printf(fmt: "Savegame check: exists = %d, autosaveExists = %d\n", v2, v1);
}


// ========================================================================
// ?testSavegameGetCurrentSlot_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829CBAF8
// RVA : 0x009CBAF8
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __fastcall testSavegameGetCurrentSlot_f(const idCmdArgs *args)
{
  const char *v1; // r3

  if ( session != nullptr )
  {
    v1 = session->GetCurrentSaveSlot(this: session);
    idLib::Printf(fmt: "Current slot: %s\n", v1);
  }
  else
  {
    idLib::Printf(fmt: "Invalid session.\n");
  }
}


// ========================================================================
// ?Process@idSaveGameProcessorEnumerateGames@@UAA_NXZ
// EA  : 0x829CBCB0
// RVA : 0x009CBCB0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

int __fastcall idSaveGameProcessorEnumerateGames::Process(idSaveGameProcessorEnumerateGames *this)
{
  this->parms.mode = 272;
  Sys_ExecuteSavegameCommandAsync(savegameParms: &this->parms);
  return 0;
}


// ========================================================================
// `idSessionLocal::LoadGameSync'::`3'::local_t::~local_t
// EA  : 0x829CBCF0
// RVA : 0x009CBCF0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __fastcall _idSessionLocal::LoadGameSync_::_3_::local_t::~local_t(int a1)
{
  idGame *v2; // r3

  idCVar::SetBool(this: &resource_virtualTexturePreload, newValue: true, force: true);
  if ( common->Game(this: common) != nullptr )
  {
    v2 = common->Game(this: common);
    v2->OnLoadCompleted(this: v2, a2: *(idSaveLoadParms **)a1, a3: (const idStr *)(a1 + 4));
  }
  idStr::FreeData(this: (idStr *)(a1 + 4));
}


// ========================================================================
// __unwind$238864
// EA  : 0x829CBD78
// RVA : 0x009CBD78
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_238864()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ?testSavegameDeleteAll_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829CBE08
// RVA : 0x009CBE08
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __fastcall testSavegameDeleteAll_f(const idCmdArgs *args)
{
  idStr *SaveGameErrorString; // r3
  idStr v2; // [sp+50h] [-C00h] BYREF
  idSaveLoadParms v3; // [sp+70h] [-BE0h] BYREF

  if ( session != nullptr )
  {
    idSaveLoadParms::idSaveLoadParms(this: &v3);
    idSaveLoadParms::SetDefaults(this: &v3, newInputDevice: -1);
    v3.mode = 40;
    Sys_ExecuteSavegameCommandAsync(savegameParms: &v3);
    Sys_SignalWait(handle: &v3.callbackSignal.handle, timeout: -1);
    idLib::Printf(fmt: "Completed process.\n");
    SaveGameErrorString = GetSaveGameErrorString(result: &v2, errorMask: v3.errorCode);
    idLib::Printf(fmt: "Error = 0x%08X, %s\n", v3.errorCode, SaveGameErrorString->data);
    idStr::FreeData(this: &v2);
    idSaveLoadParms::~idSaveLoadParms(this: &v3);
  }
  else
  {
    idLib::Printf(fmt: "Invalid session.\n");
  }
}


// ========================================================================
// __unwind$238959
// EA  : 0x829CBEBC
// RVA : 0x009CBEBC
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_238959()
{
  int v0; // r12

  idSaveLoadParms::~idSaveLoadParms(this: (idSaveLoadParms *)(v0 - 3152 + 112));
}


// ========================================================================
// __unwind$238960
// EA  : 0x829CBEE4
// RVA : 0x009CBEE4
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_238960()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 3152 + 80));
}


// ========================================================================
// ?testSavegameSetCurrentSlot_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829CBF10
// RVA : 0x009CBF10
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __fastcall testSavegameSetCurrentSlot_f(const idCmdArgs *args)
{
  const char *v1; // r3

  if ( session != nullptr )
  {
    if ( args->argc == 2 )
    {
      ((void (*)(void))session->SetCurrentSaveSlot)();
      v1 = session->GetCurrentSaveSlot(this: session);
      idLib::Printf(fmt: "Current slot: %s\n", v1);
    }
    else
    {
      idLib::Printf(fmt: "Usage: testSavegameSetCurrentSlot name\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "Invalid session.\n");
  }
}


// ========================================================================
// ?savegameSetErrorBit_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829CBFD0
// RVA : 0x009CBFD0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __fastcall savegameSetErrorBit_f(const idCmdArgs *args)
{
  const char *v1; // r3
  char v2; // r3

  if ( args->argc <= 1 )
    v1 = &byte_8200D768;
  else
    v1 = args->argv[1];
  v2 = atol(nptr: v1);
  idCVar::SetInteger(this: &savegame_error, newValue: (1 << v2) | savegame_error.valueInteger, force: true);
}


// ========================================================================
// ?InitDelete@idSaveGameProcessorDelete@@QAA_NPBDW4packageType_t@idSaveGameManager@@@Z
// EA  : 0x829CC1A0
// RVA : 0x009CC1A0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

int __fastcall idSaveGameProcessorDelete::InitDelete(
        idSaveGameProcessorDelete *this,
        char *folder_,
        idSaveGameManager::packageType_t type)
{
  char *data; // r4
  size_t v8; // r5
  char *v9; // r3
  char *v10; // r4
  char *v11; // r4
  size_t v12; // r5
  char *v13; // r3
  idStr v14; // [sp+60h] [-110h] BYREF
  idStrStatic<64> v15; // [sp+80h] [-F0h] BYREF
  idStrStatic<64> v16; // [sp+E0h] [-90h] BYREF

  if ( (unsigned __int8)idSaveGameProcessor::Init(this) == 0 )
    return 0;
  idStrStatic<64>::idStrStatic<64>(this: &v15, text: folder_);
  data = v15.data;
  v8 = v15.len + 1;
  v9 = this->parms.description.slotName.data;
  this->parms.description.slotName.len = v15.len;
  memcpy(Dst: v9, Src: data, Size: v8);
  idStr::FreeData(this: &v15);
  v10 = AddSaveFolderPrefix(result: &v14, folder: folder_, type)->data;
  idStrStatic<64>::idStrStatic<64>(this: &v16, text: v10);
  v11 = v16.data;
  v12 = v16.len + 1;
  v13 = this->parms.directory.data;
  this->parms.directory.len = v16.len;
  memcpy(Dst: v13, Src: v11, Size: v12);
  idStr::FreeData(this: &v16);
  idStr::FreeData(this: &v14);
  this->parms.mode = 4;
  return 1;
}


// ========================================================================
// __unwind$239529
// EA  : 0x829CC268
// RVA : 0x009CC268
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_239529()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 96));
}


// ========================================================================
// ?IsEnumerating@idSessionLocal@@UBA_NXZ
// EA  : 0x829CC2A0
// RVA : 0x009CC2A0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

BOOL __fastcall idSessionLocal::IsEnumerating(idSessionLocal *this)
{
  int v2; // [sp+50h] [-10h] BYREF

  v2 = *(_DWORD *)(*(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[2004] + 3028);
  return (_cntlzw(session->IsSaveGameCompletedFromHandle(this: session, a2: &v2)) & 0x20) != 0;
}


// ========================================================================
// ?GetEnumerationHandle@idSessionLocal@@UBAJXZ
// EA  : 0x829CC2F8
// RVA : 0x009CC2F8
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

int __fastcall idSessionLocal::GetEnumerationHandle(idSessionLocal *this)
{
  return *(_DWORD *)(*(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[2004] + 3028);
}


// ========================================================================
// ?IsDLCAvailable@idSessionLocal@@UAA_NPBD@Z
// EA  : 0x829CC310
// RVA : 0x009CC310
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

int __fastcall idSessionLocal::IsDLCAvailable(idSessionLocal *this, const char *mapName)
{
  if ( mapName != nullptr )
    idDeclInfo::FindWithInheritance(this: &idDeclMapInfo::resourceList, name: mapName, makeDefault: true);
  return 1;
}


// ========================================================================
// ?LoadGameCheckDescriptionFile@idSessionLocal@@QAA_NAAVidSaveLoadParms@@@Z
// EA  : 0x829CC348
// RVA : 0x009CC348
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

idFile_Memory **__fastcall idSessionLocal::LoadGameCheckDescriptionFile(idSessionLocal *this, idSaveLoadParms *parms)
{
  idFile_Memory **result; // r3
  idFile **v4; // r31
  int v5; // r11
  idGame *v6; // r3
  int v7; // r31

  result = FindFromGenericPtr<idFile_SaveGame *,char const [13],5>(
             list: &parms->files,
             other: (const char (*)[12])"game.details");
  v4 = result;
  if ( result == nullptr )
  {
    parms->errorCode = 256;
    return result;
  }
  idFile_Memory::MakeReadOnly(this: *result);
  if ( (unsigned __int8)SavegameReadDetailsFromFile(file: *v4, details: &parms->description) == 0 )
  {
    v5 = 4;
LABEL_7:
    parms->errorCode = v5;
    return (idFile_Memory **)((_cntlzw(parms->errorCode) & 0x20) != 0);
  }
  v6 = common->Game(this: common);
  v7 = v6->GetGameVersion(this: v6);
  if ( idSaveGameDetails::GetGameVersion(this: &parms->description) > v7 )
  {
    v5 = 0x2000;
    goto LABEL_7;
  }
  return (idFile_Memory **)((_cntlzw(parms->errorCode) & 0x20) != 0);
}


// ========================================================================
// ?testSavegameEnumerateFiles_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829CC410
// RVA : 0x009CC410
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __fastcall testSavegameEnumerateFiles_f(const idCmdArgs *args)
{
  const char *v2; // r3
  int v3; // r30
  int v4; // r29
  const char *v5; // r3
  idStr v6; // [sp+60h] [-C20h] BYREF
  idSaveLoadParms v7; // [sp+80h] [-C00h] BYREF

  if ( session != nullptr )
  {
    v2 = session->GetCurrentSaveSlot(this: session);
    idStr::idStr(this: &v6, text: v2);
    if ( args->argc > 1 )
      idStr::operator=(this: &v6, text: args->argv[1]);
    idLib::Printf(fmt: "Testing folder: %s\n\n", v6.data);
    idSaveLoadParms::idSaveLoadParms(this: &v7);
    idSaveLoadParms::SetDefaults(this: &v7, newInputDevice: -1);
    v7.mode = 64;
    Sys_ExecuteSavegameCommandAsync(savegameParms: &v7);
    Sys_SignalWait(handle: &v7.callbackSignal.handle, timeout: -1);
    v3 = 0;
    if ( v7.files.num > 0 )
    {
      v4 = 0;
      do
      {
        v5 = v7.files.list[v4]->GetName(this: v7.files.list[v4]);
        idLib::Printf(fmt: "^3\t%d: %s\n^0", v3++, v5);
        ++v4;
      }
      while ( v3 < v7.files.num );
    }
    idSaveLoadParms::~idSaveLoadParms(this: &v7);
    idStr::FreeData(this: &v6);
  }
  else
  {
    idLib::Printf(fmt: "Invalid session.\n");
  }
}


// ========================================================================
// __unwind$239770
// EA  : 0x829CC52C
// RVA : 0x009CC52C
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_239770()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 3200 + 96));
}


// ========================================================================
// __unwind$239771
// EA  : 0x829CC554
// RVA : 0x009CC554
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_239771()
{
  int v0; // r12

  idSaveLoadParms::~idSaveLoadParms(this: (idSaveLoadParms *)(v0 - 3200 + 128));
}


// ========================================================================
// ?testPrettyMapName_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829CC588
// RVA : 0x009CC588
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __fastcall testPrettyMapName_f(const idCmdArgs *args)
{
  const char *v1; // r4
  idGame *v2; // r3
  const char *v3; // r3
  idStrId *v4; // r3
  const char *LocalizedString; // r5
  idStr v6; // [sp+50h] [-30h] BYREF

  if ( args->argc <= 1 )
    v1 = &byte_8200D768;
  else
    v1 = args->argv[1];
  idStr::idStr(this: &v6, text: v1);
  if ( v6.len == 0 )
  {
    v2 = common->Game(this: common);
    v3 = v2->GetMapName(this: v2);
    idStr::operator=(this: &v6, text: v3);
  }
  if ( v6.data != nullptr )
    v4 = (idStrId *)idDeclInfo::FindWithInheritance(
                      this: &idDeclMapInfo::resourceList,
                      name: v6.data,
                      makeDefault: true);
  else
    v4 = nullptr;
  if ( v4[16].index >= 0 )
    LocalizedString = idStrId::GetLocalizedString(this: v4 + 16);
  else
    LocalizedString = (const char *)v4[2].index;
  idLib::Printf(fmt: "map: %s => ^2%s\n", v6.data, LocalizedString);
  idStr::FreeData(this: &v6);
}


// ========================================================================
// __unwind$239837
// EA  : 0x829CC674
// RVA : 0x009CC674
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_239837()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 128 + 80));
}


// ========================================================================
// ?LoadGameCheckDiscNumber@idSessionLocal@@UAA_NAAVidSaveLoadParms@@@Z
// EA  : 0x829CC890
// RVA : 0x009CC890
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

int __fastcall idSessionLocal::LoadGameCheckDiscNumber(idSessionLocal *this, idSaveLoadParms *parms)
{
  idDiscSwapManager *v3; // r10
  char *data; // r3
  idDiscSwapManager::error_t v5; // r3
  unsigned int v7; // r11
  BOOL v8; // r30
  idSaveGameDetails v9[2]; // [sp+50h] [-160h] BYREF

  idSaveGameDetails::GetMapName(this: v9, result: &parms->description.descriptors);
  idDiscSwapManager::Reset(this: discSwapMgr);
  idStrStatic<251>::idStrStatic<251>(
    this: (idStrStatic<251> *)&v9[0].descriptors.argHash.granularity,
    text: (const idStr *)v9);
  v3 = discSwapMgr;
  data = discSwapMgr->map.data;
  discSwapMgr->map.len = v9[0].descriptors.argHash.granularity;
  memcpy(Dst: data, Src: (const void *)v9[0].descriptors.argHash.hashMask, Size: v3->map.len + 1);
  idStr::FreeData(this: (idStr *)&v9[0].descriptors.argHash.granularity);
  v5 = idDiscSwapManager::Swap(this: discSwapMgr, command: DSC_LOAD, forceDiscNumber: nullptr);
  if ( v5 != DSE_OK )
  {
    if ( v5 == DSE_CANCEL )
    {
      v7 = 1;
    }
    else
    {
      v7 = 0;
      if ( v5 != DSE_CORRECT_DISC_ALREADY )
        v7 = 4096;
    }
    parms->errorCode = v7;
    v8 = (_cntlzw(v7) & 0x20) != 0;
    idStr::FreeData(this: (idStr *)v9);
    return v8;
  }
  else
  {
    idStr::FreeData(this: (idStr *)v9);
    return 1;
  }
}


// ========================================================================
// __unwind$240139
// EA  : 0x829CC960
// RVA : 0x009CC960
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_240139()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 80));
}


// ========================================================================
// ?OutputDetailList@@YAXABV?$idStaticList@VidSaveGameDetails@@$0BA@@@@Z
// EA  : 0x829CC990
// RVA : 0x009CC990
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __fastcall OutputDetailList(const idStaticList<idSaveGameDetails,16> *savegameList)
{
  int v2; // r26
  int v3; // r30
  idSaveGameDetails *v4; // r3
  const char *v5; // r27
  const idKeyValue *Key; // r3
  char *data; // r11
  const char *v8; // r29
  idStrStatic<64> *v9; // r4
  const char *num; // r19
  const char *v11; // r3
  idSaveGameDetails v12; // [sp+60h] [-D0h] BYREF

  v2 = 0;
  if ( savegameList->num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &savegameList->list[v3];
      if ( v4->damaged )
      {
        v5 = "?";
      }
      else
      {
        Key = idDict::FindKey(this: &v4->descriptors, key: "mapName");
        if ( Key != nullptr )
          data = Key->value.data;
        else
          data = &byte_8200D768;
        v5 = data;
      }
      v8 = "^1CORRUPT";
      v9 = (idStrStatic<64> *)&savegameList->list[v3];
      if ( v9->buffer[16] == 0 )
        v8 = "^2OK";
      num = (const char *)idSaveGameDetails::GetSlotName(this: &v12, result: v9)->descriptors.args.num;
      v11 = Sys_TimeStampToStr(timeStamp: savegameList->list[v3].date, padded: true);
      idLib::Printf(fmt: "^3\t%s - %s\n^0\t\tMap: %s\n\t\tTime: %s\n", num, v8, v5, v11);
      idStr::FreeData(this: (idStr *)&v12);
      ++v2;
      ++v3;
    }
    while ( v2 < savegameList->num );
  }
}


// ========================================================================
// __unwind$240206
// EA  : 0x829CCAA8
// RVA : 0x009CCAA8
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_240206()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 96));
}


// ========================================================================
// ?testSaveGameOutputEnumeratedSavegames_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829CCAD0
// RVA : 0x009CCAD0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __fastcall testSaveGameOutputEnumeratedSavegames_f(const idCmdArgs *args)
{
  if ( session != nullptr )
    OutputDetailList(savegameList: &session->saveGameManager->enumeratedSaveGames);
  else
    idLib::Printf(fmt: "Invalid session.\n");
}


// ========================================================================
// ?InitLoadFiles@idSaveGameProcessorLoadFiles@@UAA_NPBDABV?$idStaticList@PAVidFile_SaveGame@@$09@@W4packageType_t@idSaveGameManager@@@Z
// EA  : 0x829CCB90
// RVA : 0x009CCB90
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

int __fastcall idSaveGameProcessorLoadFiles::InitLoadFiles(
        idSaveGameProcessorLoadFiles *this,
        char *folder_,
        const idStaticList<idFile_SaveGame *,10> *files,
        idSaveGameManager::packageType_t type)
{
  char *data; // r4
  char *v10; // r4
  size_t v11; // r5
  char *v12; // r3
  char *v13; // r4
  size_t v14; // r5
  char *v15; // r3
  int v16; // r29
  idList<enum encounterGroupRole_t,5> *p_files; // r27
  int v18; // r30
  idStr v19; // [sp+60h] [-110h] BYREF
  idStrStatic<64> v20; // [sp+80h] [-F0h] BYREF
  idStrStatic<64> v21; // [sp+E0h] [-90h] BYREF

  if ( (unsigned __int8)idSaveGameProcessor::Init(this) == 0 )
    return 0;
  data = AddSaveFolderPrefix(result: &v19, folder: folder_, type)->data;
  idStrStatic<64>::idStrStatic<64>(this: &v20, text: data);
  v10 = v20.data;
  v11 = v20.len + 1;
  v12 = this->parms.directory.data;
  this->parms.directory.len = v20.len;
  memcpy(Dst: v12, Src: v10, Size: v11);
  idStr::FreeData(this: &v20);
  idStr::FreeData(this: &v19);
  idStrStatic<64>::idStrStatic<64>(this: &v21, text: folder_);
  v13 = v21.data;
  v14 = v21.len + 1;
  v15 = this->parms.description.slotName.data;
  this->parms.description.slotName.len = v21.len;
  memcpy(Dst: v15, Src: v13, Size: v14);
  idStr::FreeData(this: &v21);
  v16 = 0;
  this->parms.mode = 1;
  if ( files->num > 0 )
  {
    p_files = (idList<enum encounterGroupRole_t,5> *)&this->parms.files;
    v18 = 0;
    do
    {
      idList<idAnimWebBlendTree *,5>::Append(this: p_files, obj: (const encounterGroupRole_t *)&files->list[v18]);
      ++v16;
      ++v18;
    }
    while ( v16 < files->num );
  }
  return 1;
}


// ========================================================================
// __unwind$240396
// EA  : 0x829CCC98
// RVA : 0x009CCC98
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_240396()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 96));
}


// ========================================================================
// ?InitSave@idSaveGameProcessorSaveFiles@@QAA_NPBDABV?$idStaticList@PAVidFile_SaveGame@@$09@@ABVidSaveGameDetails@@W4packageType_t@idSaveGameManager@@@Z
// EA  : 0x829CCCC8
// RVA : 0x009CCCC8
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

int __fastcall idSaveGameProcessorSaveFiles::InitSave(
        idSaveGameProcessorSaveFiles *this,
        char *folder,
        const idStaticList<idFile_SaveGame *,10> *files,
        const idSaveGameDetails *descriptionForPS3,
        idSaveGameManager::packageType_t type)
{
  char *data; // r4
  char *v12; // r4
  size_t v13; // r5
  char *v14; // r3
  int v15; // r28
  int v16; // r29
  char *v17; // r3
  int len; // r11
  char *v19; // r4
  size_t v20; // r5
  char *v21; // r3
  idStr v22; // [sp+60h] [-130h] BYREF
  idStrStatic<64> v23; // [sp+80h] [-110h] BYREF
  idStrStatic<64> v24; // [sp+E0h] [-B0h] BYREF

  if ( (unsigned __int8)idSaveGameProcessor::Init(this) == 0 )
    return 0;
  if ( files->num == 0 )
  {
    idLib::Warning(fmt: "No files to save.");
    return 0;
  }
  data = AddSaveFolderPrefix(result: &v22, folder, type)->data;
  idStrStatic<64>::idStrStatic<64>(this: &v23, text: data);
  v12 = v23.data;
  v13 = v23.len + 1;
  v14 = this->parms.directory.data;
  this->parms.directory.len = v23.len;
  memcpy(Dst: v14, Src: v12, Size: v13);
  idStr::FreeData(this: &v23);
  idStr::FreeData(this: &v22);
  v15 = 0;
  this->parms.mode = 2;
  if ( files->num > 0 )
  {
    v16 = 0;
    do
    {
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&this->parms.files,
        obj: (const encounterGroupRole_t *)&files->list[v16]);
      ++v15;
      ++v16;
    }
    while ( v15 < files->num );
  }
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  idDict::operator=(this: &this->parms.description.descriptors, other: &descriptionForPS3->descriptors);
  this->parms.description.damaged = descriptionForPS3->damaged;
  this->parms.description.date = descriptionForPS3->date;
  v17 = this->parms.description.slotName.data;
  len = descriptionForPS3->slotName.len;
  this->parms.description.slotName.len = len;
  memcpy(Dst: v17, Src: descriptionForPS3->slotName.data, Size: len + 1);
  idMem::PopHeap(this: &mem);
  idStrStatic<64>::idStrStatic<64>(this: &v24, text: folder);
  v19 = v24.data;
  v20 = v24.len + 1;
  v21 = this->parms.description.slotName.data;
  this->parms.description.slotName.len = v24.len;
  memcpy(Dst: v21, Src: v19, Size: v20);
  idStr::FreeData(this: &v24);
  return 1;
}


// ========================================================================
// __unwind$240510
// EA  : 0x829CCE50
// RVA : 0x009CCE50
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_240510()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 96));
}


// ========================================================================
// ?OnDeleteCompleted@idSessionLocal@@QAAXPAVidSaveLoadParms@@@Z
// EA  : 0x829CCE78
// RVA : 0x009CCE78
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __fastcall idSessionLocal::OnDeleteCompleted(idSessionLocal *this, idSaveLoadParms *parms)
{
  idStaticList<idSaveGameDetails,16> *p_enumeratedSaveGames; // r31
  int Index; // r4
  idGame *v5; // r3

  common->ShowSaveIndicator(this: common, a2: false, a3: false);
  if ( parms->errorCode == 0 )
  {
    p_enumeratedSaveGames = &session->saveGameManager->enumeratedSaveGames;
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    Index = idList<idSaveGameDetails,5>::FindIndex(this: p_enumeratedSaveGames, obj: &parms->description, startIndex: 0);
    if ( Index >= 0 )
      idList<idSaveGameDetails,5>::RemoveIndex(this: p_enumeratedSaveGames, index: Index);
    idMem::PopHeap(this: &mem);
  }
  if ( common->Game(this: common) != nullptr )
  {
    v5 = common->Game(this: common);
    v5->OnDeleteCompleted(this: v5, a2: parms);
  }
}


// ========================================================================
// ?DeleteSaveGameSync@idSessionLocal@@UAAJPBD@Z
// EA  : 0x829CD0C0
// RVA : 0x009CD0C0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

float *__fastcall idSessionLocal::DeleteSaveGameSync(idSessionLocal *this, char *name)
{
  char *v2; // r28
  float *v4; // r30
  idSaveGameProcessor *v5; // r30
  idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *> *v6; // r3
  idAFBody *v7; // r4
  idSaveGameManager *saveGameManager; // r3
  int v9; // r8
  int v10; // r7
  int v11; // r6
  int v12; // r5
  idSaveLoadParms *v13; // r4
  idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *> v15; // [sp+60h] [-40h] BYREF

  v2 = &this->stubLobby.fakeParms.layersDeactive.buffer[2000];
  v4 = nullptr;
  if ( (unsigned __int8)idSaveGameProcessorDelete::InitDelete(
                          this: *(idSaveGameProcessorDelete **)&this->stubLobby.fakeParms.layersDeactive.buffer[2000],
                          folder_: name,
                          type: PACKAGE_GAME) == 0
    || (v5 = *(idSaveGameProcessor **)v2,
        v6 = MakeCallback<idSessionLocal,idSaveLoadParms *>(
               result: &v15,
               t: this,
               f: idSessionLocal::OnDeleteCompleted,
               a1: (idSaveLoadParms *)(*(_DWORD *)v2 + 8)),
        idSaveGameProcessor::AddCompletedCallback(this: v5, callback: v6),
        v7 = *(idAFBody **)v2,
        saveGameManager = this->saveGameManager,
        v15.__vftable = (idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *>_vtbl *)&idCallback::`vftable',
        (v4 = idSaveGameManager::ExecuteProcessorAndWait(
                this: saveGameManager,
                processor: v7,
                a3: v12,
                a4: v11,
                a5: v10,
                a6: v9,
                a7: (int)&idCallback::`vftable',
                a8: 0x82000000)) == nullptr) )
  {
    v13 = (idSaveLoadParms *)(*(_DWORD *)v2 + 8);
    *(_DWORD *)(*(_DWORD *)v2 + 2984) = 16;
    idSessionLocal::OnDeleteCompleted(this, parms: v13);
  }
  return v4;
}


// ========================================================================
// __unwind$241011
// EA  : 0x829CD170
// RVA : 0x009CD170
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241011()
{
  int v0; // r12

  idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(this: (idCallback *)(v0 - 160 + 96));
}


// ========================================================================
// ?DeleteSaveGameAsync@idSessionLocal@@UAAJPBD@Z
// EA  : 0x829CD1A0
// RVA : 0x009CD1A0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

float *__fastcall idSessionLocal::DeleteSaveGameAsync(idSessionLocal *this, char *name)
{
  idAFBody **v2; // r28
  float *v4; // r30
  idSaveGameProcessor *v5; // r30
  idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *> *v6; // r3
  int v7; // r10
  int v8; // r9
  int v9; // r8
  int v10; // r7
  int v11; // r6
  int v12; // r5
  idSaveLoadParms *v13; // r4
  int v15; // [sp+8h] [-98h]
  int v16; // [sp+Ch] [-94h]
  int v17; // [sp+10h] [-90h]
  int v18; // [sp+14h] [-8Ch]
  int v19; // [sp+18h] [-88h]
  idAFBody *v20; // [sp+1Ch] [-84h]
  idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *> v21; // [sp+60h] [-40h] BYREF

  v2 = (idAFBody **)&this->stubLobby.fakeParms.layersDeactive.buffer[2000];
  v4 = nullptr;
  if ( (unsigned __int8)idSaveGameProcessorDelete::InitDelete(
                          this: *(idSaveGameProcessorDelete **)&this->stubLobby.fakeParms.layersDeactive.buffer[2000],
                          folder_: name,
                          type: PACKAGE_GAME) == 0
    || (v5 = (idSaveGameProcessor *)*v2,
        v6 = MakeCallback<idSessionLocal,idSaveLoadParms *>(
               result: &v21,
               t: this,
               f: idSessionLocal::OnDeleteCompleted,
               a1: (idSaveLoadParms *)(&(*v2)->__vftable + 2)),
        idSaveGameProcessor::AddCompletedCallback(this: v5, callback: v6),
        v21.__vftable = (idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *>_vtbl *)&idCallback::`vftable',
        common->ShowSaveIndicator(this: common, a2: true, a3: false),
        (v4 = idSaveGameManager::ExecuteProcessor(
                this: this->saveGameManager,
                processor: *v2,
                a3: v12,
                a4: v11,
                a5: v10,
                a6: v9,
                a7: v8,
                a8: v7,
                a9: v15,
                a10: v16,
                a11: v17,
                a12: v18,
                a13: v19,
                a14: v20)) == nullptr) )
  {
    v13 = (idSaveLoadParms *)(&(*v2)->__vftable + 2);
    (*v2)[3].I.numRows = 16;
    idSessionLocal::OnDeleteCompleted(this, parms: v13);
  }
  return v4;
}


// ========================================================================
// __unwind$241097
// EA  : 0x829CD270
// RVA : 0x009CD270
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241097()
{
  int v0; // r12

  idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(this: (idCallback *)(v0 - 160 + 96));
}


// ========================================================================
// ?LoadGameSync@idSessionLocal@@UAAJPBDAAV?$idStaticList@PAVidFile_SaveGame@@$09@@@Z
// EA  : 0x829CD2A0
// RVA : 0x009CD2A0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
float *__fastcall idSessionLocal::LoadGameSync(
        idSessionLocal *this,
        const char *name,
        idStaticList<idFile_SaveGame *,10> *files)
{
  __int64 v3; // r4
  idAFBody **v4; // r28
  __int64 v5; // kr00_8
  const idList<idMD6Node *,5> *v6; // r5
  const idList<idMD6Node *,5> *v7; // r30
  int v8; // r11
  float *v9; // r25
  idSaveLoadParms *v10; // r29
  idFile_Memory *v11; // r3
  encounterGroupRole_t v12; // r30
  int v13; // r10
  int v14; // r9
  int v15; // r8
  int v16; // r7
  int v17; // r6
  int v18; // r5
  idGame *v19; // r3
  idGame *v20; // r3
  idSaveGameDetails *MapName; // r3
  BOOL v22; // r28
  idGame *v23; // r3
  idGame *v24; // r3
  idGame *v25; // r3
  idGame *v26; // r3
  idGame *v28; // r3
  idFile *v29; // [sp+50h] [-15200h] BYREF
  encounterGroupRole_t v30[3]; // [sp+54h] [-151FCh] BYREF
  idSaveLoadParms *v31; // [sp+60h] [-151F0h]
  idStrStatic<64> v32; // [sp+64h] [-151ECh] BYREF
  idStaticList<idFile_SaveGame *,10> v33; // [sp+D0h] [-15180h] BYREF
  idSaveGameDetails v34[532]; // [sp+110h] [-15140h] BYREF
  char v35; // [sp+14DB6h] [-49Ah]

  v3 = ((__int64 (*)(void))RtlCheckStack12)();
  v4 = (idAFBody **)(HIDWORD(v3) + 45352);
  v5 = v3;
  v7 = v6;
  v8 = *(_DWORD *)(HIDWORD(v3) + 45352);
  v9 = nullptr;
  v29 = nullptr;
  v10 = (idSaveLoadParms *)(v8 + 8);
  idGameSpawnInfo::idGameSpawnInfo(
    this: (idGameSpawnInfo *)&v34[0].descriptors.argHash.granularity,
    mapName_: &byte_8200D768,
    gameFlags_: 0);
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v31 = v10;
  idStrStatic<64>::idStrStatic<64>(this: &v32, text: (const char *)v5);
  idCVar::SetBool(this: &resource_virtualTexturePreload, newValue: false, force: true);
  idStaticList<idFile_SaveGame *,10>::idStaticList<idFile_SaveGame *,10>(this: &v33, other: v7);
  v11 = (idFile_Memory *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x154u,
                           tag: TAG_SAVEGAMES,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v12 = (encounterGroupRole_t)v11;
  v30[0] = (encounterGroupRole_t)v11;
  if ( v11 != nullptr )
  {
    idFile_Memory::idFile_Memory(this: v11, name: "game.details");
    *(_DWORD *)(v12 + 332) = 1;
    *(_BYTE *)(v12 + 336) = 0;
    *(_DWORD *)v12 = &idFile_SaveGame::`vftable';
  }
  else
  {
    v12 = ROLE_NONE;
  }
  v30[1] = v12;
  v30[0] = v12;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v33, obj: v30);
  v14 = ((unsigned __int8 (__fastcall *)(idAFBody *, _DWORD, idStaticList<idFile_SaveGame *,10> *, int))(*v4)->__vftable[3].Serialize)(
          a1: *v4,
          a2: v5,
          a3: &v33,
          a4: 1);
  if ( v14 == 0
    || (v9 = idSaveGameManager::ExecuteProcessorAndWait(
               this: *(idSaveGameManager **)(HIDWORD(v5) + 4696),
               processor: *v4,
               a3: v18,
               a4: v17,
               a5: v16,
               a6: v15,
               a7: v14,
               a8: v13)) == nullptr )
  {
    v10->errorCode = 16;
  }
  if ( v10->errorCode != 0 )
  {
    if ( v12 != ROLE_NONE )
      (**(void (__fastcall ***)(encounterGroupRole_t, int))v12)(a1: v12, a2: 1);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v33);
    idCVar::SetBool(this: &resource_virtualTexturePreload, newValue: true, force: true);
    if ( common->Game(this: common) != nullptr )
    {
      v19 = common->Game(this: common);
      v19->OnLoadCompleted(this: v19, a2: v31, a3: &v32);
    }
LABEL_37:
    idStr::FreeData(this: &v32);
    idMem::PopHeap(this: &mem);
    idGameSpawnInfo::~idGameSpawnInfo(this: (idGameSpawnInfo *)&v34[0].descriptors.argHash.granularity);
    return nullptr;
  }
  if ( (unsigned __int8)idSessionLocal::LoadGameCheckDescriptionFile(this: (idSessionLocal *)HIDWORD(v5), parms: v10) == 0 )
  {
    if ( v12 != ROLE_NONE )
      (**(void (__fastcall ***)(encounterGroupRole_t, int))v12)(a1: v12, a2: 1);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v33);
    idCVar::SetBool(this: &resource_virtualTexturePreload, newValue: true, force: true);
    if ( common->Game(this: common) != nullptr )
    {
      v20 = common->Game(this: common);
      v20->OnLoadCompleted(this: v20, a2: v31, a3: &v32);
    }
    goto LABEL_37;
  }
  MapName = idSaveGameDetails::GetMapName(this: v34, result: &v10->description.descriptors);
  v22 = (_cntlzw(
           (*(unsigned __int8 (__fastcall **)(_DWORD, int))(*(_DWORD *)HIDWORD(v5) + 400))(
             a1: HIDWORD(v5),
             a2: MapName->descriptors.args.num))
       & 0x20) != 0;
  idStr::FreeData(this: (idStr *)v34);
  if ( v22 )
  {
    v10->errorCode = 512;
    if ( v12 != ROLE_NONE )
      (**(void (__fastcall ***)(encounterGroupRole_t, int))v12)(a1: v12, a2: 1);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v33);
    idCVar::SetBool(this: &resource_virtualTexturePreload, newValue: true, force: true);
    if ( common->Game(this: common) != nullptr )
    {
      v23 = common->Game(this: common);
      v23->OnLoadCompleted(this: v23, a2: v31, a3: &v32);
    }
    goto LABEL_37;
  }
  if ( (*(unsigned __int8 (__fastcall **)(_DWORD, idSaveLoadParms *))(*(_DWORD *)HIDWORD(v5) + 404))(
         a1: HIDWORD(v5),
         a2: v10) == 0
    && discSwapper_enable.valueInteger != 0 )
  {
    if ( v12 != ROLE_NONE )
      (**(void (__fastcall ***)(encounterGroupRole_t, int))v12)(a1: v12, a2: 1);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v33);
    idCVar::SetBool(this: &resource_virtualTexturePreload, newValue: true, force: true);
    if ( common->Game(this: common) != nullptr )
    {
      v24 = common->Game(this: common);
      v24->OnLoadCompleted(this: v24, a2: v31, a3: &v32);
    }
    goto LABEL_37;
  }
  v25 = common->Game(this: common);
  if ( !v25->GetGameStartInfoFromSaveLoadParms(
          this: v25,
          a2: v10,
          a3: &v29,
          a4: (idGameSpawnInfo *)&v34[0].descriptors.argHash.granularity) )
  {
    v10->errorCode = 16;
    if ( v12 != ROLE_NONE )
      (**(void (__fastcall ***)(encounterGroupRole_t, int))v12)(a1: v12, a2: 1);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v33);
    idCVar::SetBool(this: &resource_virtualTexturePreload, newValue: true, force: true);
    if ( common->Game(this: common) != nullptr )
    {
      v26 = common->Game(this: common);
      v26->OnLoadCompleted(this: v26, a2: v31, a3: &v32);
    }
    goto LABEL_37;
  }
  if ( v12 != ROLE_NONE )
    (**(void (__fastcall ***)(encounterGroupRole_t, int))v12)(a1: v12, a2: 1);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v33);
  idCVar::SetBool(this: &resource_virtualTexturePreload, newValue: true, force: true);
  if ( common->Game(this: common) != nullptr )
  {
    v28 = common->Game(this: common);
    v28->OnLoadCompleted(this: v28, a2: v31, a3: &v32);
  }
  idStr::FreeData(this: &v32);
  idMem::PopHeap(this: &mem);
  v35 = 1;
  common->ExecuteMapChange(this: common, a2: (const idGameSpawnInfo *)&v34[0].descriptors.argHash.granularity, a3: v29);
  idGameSpawnInfo::~idGameSpawnInfo(this: (idGameSpawnInfo *)&v34[0].descriptors.argHash.granularity);
  return v9;
}


// ========================================================================
// __unwind$241488
// EA  : 0x829CD8EC
// RVA : 0x009CD8EC
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241488()
{
  int v0; // r12

  idGameSpawnInfo::~idGameSpawnInfo(this: (idGameSpawnInfo *)(v0 - 21072 + 304));
}


// ========================================================================
// __unwind$241489
// EA  : 0x829CD914
// RVA : 0x009CD914
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241489()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 21072 + 86504));
}


// ========================================================================
// __unwind$241511
// EA  : 0x829CD944
// RVA : 0x009CD944
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241511()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 21072 + 100));
}


// ========================================================================
// __unwind$241490
// EA  : 0x829CD970
// RVA : 0x009CD970
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241490()
{
  int v0; // r12

  _idSessionLocal::LoadGameSync_::_3_::local_t::~local_t(a1: v0 - 21072 + 96);
}


// ========================================================================
// __unwind$241491
// EA  : 0x829CD998
// RVA : 0x009CD998
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241491()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 21072 + 208));
}


// ========================================================================
// __unwind$241492
// EA  : 0x829CD9C0
// RVA : 0x009CD9C0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241492()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 21072 + 84), tag: TAG_SAVEGAMES);
}


// ========================================================================
// __unwind$241493
// EA  : 0x829CD9EC
// RVA : 0x009CD9EC
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241493()
{
  int v0; // r12

  idLoadScreen::Shutdown(this: (idLoadScreen *)(v0 - 21072 + 88));
}


// ========================================================================
// __unwind$241571
// EA  : 0x829CDA14
// RVA : 0x009CDA14
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241571()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 21072 + 100));
}


// ========================================================================
// __unwind$241613_0
// EA  : 0x829CDA40
// RVA : 0x009CDA40
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241613_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 21072 + 100));
}


// ========================================================================
// __unwind$241494
// EA  : 0x829CDA6C
// RVA : 0x009CDA6C
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241494()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 21072 + 272));
}


// ========================================================================
// __unwind$241674
// EA  : 0x829CDA94
// RVA : 0x009CDA94
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241674()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 21072 + 100));
}


// ========================================================================
// __unwind$241719
// EA  : 0x829CDAC0
// RVA : 0x009CDAC0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241719()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 21072 + 100));
}


// ========================================================================
// __unwind$241764
// EA  : 0x829CDAEC
// RVA : 0x009CDAEC
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241764()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 21072 + 100));
}


// ========================================================================
// __unwind$241806
// EA  : 0x829CDB18
// RVA : 0x009CDB18
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241806()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 21072 + 100));
}


// ========================================================================
// ?testSavegameDelete_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829CDB50
// RVA : 0x009CDB50
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __fastcall testSavegameDelete_f(const idCmdArgs *args)
{
  const char *v1; // r4
  int v2; // r10
  int v3; // r9
  int v4; // r8
  int v5; // r7
  int v6; // r6
  int v7; // r5
  idStr *SaveGameErrorString; // r3
  idStr v9; // [sp+60h] [-C60h] BYREF
  idStr v10; // [sp+80h] [-C40h] BYREF
  idSaveGameProcessor v11; // [sp+A0h] [-C20h] BYREF

  if ( session != nullptr )
  {
    if ( args->argc == 2 )
    {
      if ( args->argc <= 1 )
        v1 = &byte_8200D768;
      else
        v1 = args->argv[1];
      idStr::idStr(this: &v9, text: v1);
      idSaveGameProcessor::idSaveGameProcessor(this: &v11);
      v11.__vftable = (idSaveGameProcessor_vtbl *)&idSaveGameProcessorDelete::`vftable';
      v3 = (unsigned __int8)idSaveGameProcessorDelete::InitDelete(
                              this: (idSaveGameProcessorDelete *)&v11,
                              folder_: v9.data,
                              type: PACKAGE_GAME);
      if ( v3 != 0 )
        idSaveGameManager::ExecuteProcessorAndWait(
          this: session->saveGameManager,
          processor: (idAFBody *)&v11,
          a3: v7,
          a4: v6,
          a5: v5,
          a6: v4,
          a7: v3,
          a8: v2);
      idLib::Printf(fmt: "Completed process.\n");
      SaveGameErrorString = GetSaveGameErrorString(result: &v10, errorMask: v11.parms.errorCode);
      idLib::Printf(fmt: "Error = 0x%08X, %s\n", v11.parms.errorCode, SaveGameErrorString->data);
      idStr::FreeData(this: &v10);
      idSaveGameProcessor::~idSaveGameProcessor(this: &v11);
      idStr::FreeData(this: &v9);
    }
    else
    {
      idLib::Printf(fmt: "Usage: testSavegameDelete <folder (without 'GAMES-')>\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "Invalid session.\n");
  }
}


// ========================================================================
// __unwind$241950
// EA  : 0x829CDC64
// RVA : 0x009CDC64
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241950()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 3264 + 96));
}


// ========================================================================
// __unwind$241951
// EA  : 0x829CDC8C
// RVA : 0x009CDC8C
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241951()
{
  int v0; // r12

  idSaveGameProcessorDelete::~idSaveGameProcessorDelete(this: (idSaveGameProcessorDelete *)(v0 - 3264 + 160));
}


// ========================================================================
// __unwind$241952
// EA  : 0x829CDCB4
// RVA : 0x009CDCB4
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_241952()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 3264 + 128));
}


// ========================================================================
// ?OnSaveCompleted@idSessionLocal@@QAAXPAVidSaveLoadParms@@@Z
// EA  : 0x829CE688
// RVA : 0x009CE688
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __fastcall idSessionLocal::OnSaveCompleted(idSessionLocal *this, idSaveLoadParms *parms)
{
  idLocalUser *MasterLocalUser; // r3
  idPlayerProfile *v4; // r3
  idStaticList<idSaveGameDetails,16> *p_enumeratedSaveGames; // r30
  idSaveGameDetails *v6; // r29
  idSaveGameDetails *p_description; // r4
  idGame *v8; // r3

  common->ShowSaveIndicator(this: common, a2: false, a3: false);
  if ( parms->errorCode == 0 )
  {
    MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: session->signInManager);
    if ( MasterLocalUser != nullptr )
    {
      v4 = MasterLocalUser->GetProfile(this: MasterLocalUser);
      idPlayerProfile::SaveSettings(this: v4);
    }
    p_enumeratedSaveGames = &session->saveGameManager->enumeratedSaveGames;
    v6 = idList<idSaveGameDetails,5>::Find(this: p_enumeratedSaveGames, obj: &parms->description);
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    p_description = &parms->description;
    if ( v6 != nullptr )
      idSaveGameDetails::operator=(this: v6, __that: p_description);
    else
      idList<idSaveGameDetails,5>::Append(this: p_enumeratedSaveGames, obj: p_description);
    idMem::PopHeap(this: &mem);
  }
  if ( common->Game(this: common) != nullptr )
  {
    v8 = common->Game(this: common);
    v8->OnSaveCompleted(this: v8, a2: parms);
  }
}


// ========================================================================
// ?OnEnumerationCompleted@idSessionLocal@@QAAXPAVidSaveLoadParms@@@Z
// EA  : 0x829CE7A0
// RVA : 0x009CE7A0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __fastcall idSessionLocal::OnEnumerationCompleted(idSessionLocal *this, idSaveLoadParms *parms)
{
  __int64 v3; // r10
  int v4; // r8
  int v5; // r7
  int v6; // r6
  idSaveGameDetails *list; // r4
  unsigned int num; // r5
  idStaticList<idSaveGameDetails,16> *p_enumeratedSaveGames; // r29
  int v10; // r28
  int v11; // r27
  idSaveGameDetails *v12; // r30
  idSaveGameDetails *SlotName; // r3
  idStr *v14; // r3
  char *data; // r3
  idGame *v16; // r3
  idSort_Quick<idSaveGameDetails,idSort_EnumeratedSavegames> v17; // [sp+50h] [-130h] BYREF
  idSaveGameDetails *p_slotName; // [sp+54h] [-12Ch]
  idStr v19; // [sp+60h] [-120h] BYREF
  idStrStatic<64> v20; // [sp+80h] [-100h] BYREF
  idSaveGameDetails v21; // [sp+E0h] [-A0h] BYREF

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v17.__vftable = (idSort_Quick<idSaveGameDetails,idSort_EnumeratedSavegames>_vtbl *)&idSort_EnumeratedSavegames::`vftable';
  list = parms->detailList.list;
  if ( list != nullptr )
  {
    num = parms->detailList.num;
    p_slotName = parms->detailList.list;
    idSort_Quick<idSaveGameDetails,idSort_EnumeratedSavegames>::Sort(
      this: &v17,
      base: list,
      num,
      a4: v6,
      a5: v5,
      a6: v4,
      a7: v3);
  }
  v17.__vftable = (idSort_Quick<idSaveGameDetails,idSort_EnumeratedSavegames>_vtbl *)&idSort<idSaveGameDetails>::`vftable';
  idMem::PopHeap(this: &mem);
  if ( parms->errorCode == 0 )
  {
    p_enumeratedSaveGames = &session->saveGameManager->enumeratedSaveGames;
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idStaticList<idSaveGameDetails,16>::operator=(this: p_enumeratedSaveGames, __that: &parms->detailList);
    idMem::PopHeap(this: &mem);
    v10 = 0;
    if ( p_enumeratedSaveGames->num > 0 )
    {
      v11 = 0;
      do
      {
        v12 = &p_enumeratedSaveGames->list[v11];
        SlotName = idSaveGameDetails::GetSlotName(this: &v21, result: (idStrStatic<64> *)v12);
        v14 = RemoveSaveFolderPrefix(
                result: &v19,
                folder: (const char *)SlotName->descriptors.args.num,
                type: PACKAGE_GAME);
        idStrStatic<64>::idStrStatic<64>(this: &v20, text: v14->data);
        data = v12->slotName.data;
        p_slotName = (idSaveGameDetails *)&v12->slotName;
        v12->slotName.len = v20.len;
        memcpy(Dst: data, Src: v20.data, Size: v20.len + 1);
        idStr::FreeData(this: &v20);
        idStr::FreeData(this: &v19);
        idStr::FreeData(this: (idStr *)&v21);
        ++v10;
        ++v11;
      }
      while ( v10 < p_enumeratedSaveGames->num );
    }
    if ( saveGame_verbose.valueInteger != 0 )
      OutputDetailList(savegameList: p_enumeratedSaveGames);
  }
  if ( common->Game(this: common) != nullptr )
  {
    v16 = common->Game(this: common);
    v16->OnEnumerationCompleted(this: v16, a2: parms);
  }
}


// ========================================================================
// __unwind$242428
// EA  : 0x829CE94C
// RVA : 0x009CE94C
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_242428()
{
  int v0; // r12

  idSort_EnumeratedSavegames::~idSort_EnumeratedSavegames(this: (idSort_EnumeratedSavegames *)(v0 - 384 + 80));
}


// ========================================================================
// __unwind$242429
// EA  : 0x829CE974
// RVA : 0x009CE974
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_242429()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 224));
}


// ========================================================================
// __unwind$242430
// EA  : 0x829CE99C
// RVA : 0x009CE99C
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_242430()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 96));
}


// ========================================================================
// ?testSavegameEnumerate_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829CE9D0
// RVA : 0x009CE9D0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __fastcall testSavegameEnumerate_f(const idCmdArgs *args)
{
  idStaticList<idSaveGameDetails,16> v1; // [sp+50h] [-A30h] BYREF

  if ( session != nullptr )
  {
    if ( session->EnumerateSaveGamesSync(this: session) != 0 )
    {
      idStaticList<idSaveGameDetails,16>::idStaticList<idSaveGameDetails,16>(
        this: &v1,
        other: &session->saveGameManager->enumeratedSaveGames);
      idLib::Printf(fmt: "Savegames found: %d\n\n", v1.num);
      OutputDetailList(savegameList: &v1);
      idStaticList<idSaveGameDetails,16>::~idStaticList<idSaveGameDetails,16>(this: &v1);
    }
    else
    {
      idLib::Printf(fmt: "Error enumerating.\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "Invalid session.\n");
  }
}


// ========================================================================
// __unwind$242600
// EA  : 0x829CEA7C
// RVA : 0x009CEA7C
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_242600()
{
  int v0; // r12

  idStaticList<idSaveGameDetails,16>::~idStaticList<idSaveGameDetails,16>(this: (idStaticList<idSaveGameDetails,16> *)(v0 - 2688 + 80));
}


// ========================================================================
// ?SaveGameSync@idSessionLocal@@UAAJPBDABV?$idStaticList@PAVidFile_SaveGame@@$09@@ABVidSaveGameDetails@@@Z
// EA  : 0x829CEAB0
// RVA : 0x009CEAB0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

float *__fastcall idSessionLocal::SaveGameSync(
        idSessionLocal *this,
        char *name,
        const idList<idMD6Node *,5> *files,
        idSaveGameDetails *description)
{
  float *v7; // r25
  idFile_Memory *v8; // r3
  idFile_SaveGame *v9; // r30
  idAFBody **v10; // r29
  idSaveGameProcessor *v11; // r30
  idSaveLoadParms *v12; // r6
  idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *> *v13; // r3
  int v14; // r10
  int v15; // r9
  int v16; // r8
  int v17; // r7
  int v18; // r6
  int v19; // r5
  idSaveLoadParms *v20; // r4
  idSaveGameProcessor *v22; // [sp+50h] [-A0h] BYREF
  idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *> v23; // [sp+60h] [-90h] BYREF
  idStaticList<idFile_SaveGame *,10> v24[2]; // [sp+70h] [-80h] BYREF

  v7 = nullptr;
  idStaticList<idFile_SaveGame *,10>::idStaticList<idFile_SaveGame *,10>(this: v24, other: files);
  v8 = (idFile_Memory *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x154u,
                          tag: TAG_SAVEGAMES,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v9 = (idFile_SaveGame *)v8;
  v22 = (idSaveGameProcessor *)v8;
  if ( v8 != nullptr )
  {
    idFile_Memory::idFile_Memory(this: v8, name: "game.details");
    v9->error = false;
    v9->type = 65;
    v9->__vftable = (idFile_SaveGame_vtbl *)&idFile_SaveGame::`vftable';
  }
  else
  {
    v9 = nullptr;
  }
  v22 = (idSaveGameProcessor *)v9;
  idFile_Memory::MakeWritable(this: v9);
  idSaveGameDetails::WriteDescriptorsToIniFile(this: description, saveGameFile: v9);
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)v24,
    obj: (const encounterGroupRole_t *)&v22);
  v10 = (idAFBody **)&this->stubLobby.fakeParms.layersDeactive.buffer[1992];
  if ( (unsigned __int8)idSaveGameProcessorSaveFiles::InitSave(
                          this: *(idSaveGameProcessorSaveFiles **)&this->stubLobby.fakeParms.layersDeactive.buffer[1992],
                          folder: name,
                          files: v24,
                          descriptionForPS3: description,
                          type: PACKAGE_GAME) == 0 )
    goto LABEL_6;
  v12 = (idSaveLoadParms *)(&(*v10)->__vftable + 2);
  v22 = (idSaveGameProcessor *)*v10;
  v11 = v22;
  v13 = MakeCallback<idSessionLocal,idSaveLoadParms *>(
          result: &v23,
          t: this,
          f: idSessionLocal::OnSaveCompleted,
          a1: v12);
  v22 = v11;
  idSaveGameProcessor::AddCompletedCallback(this: v11, callback: v13);
  v23.__vftable = (idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *>_vtbl *)&idCallback::`vftable';
  common->ShowSaveIndicator(this: common, a2: true, a3: false);
  v7 = idSaveGameManager::ExecuteProcessorAndWait(
         this: this->saveGameManager,
         processor: *v10,
         a3: v19,
         a4: v18,
         a5: v17,
         a6: v16,
         a7: v15,
         a8: v14);
  if ( v7 == nullptr )
  {
LABEL_6:
    v20 = (idSaveLoadParms *)(&(*v10)->__vftable + 2);
    (*v10)[3].I.numRows = 16;
    idSessionLocal::OnSaveCompleted(this, parms: v20);
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v24);
  return v7;
}


// ========================================================================
// __unwind$242633
// EA  : 0x829CEC30
// RVA : 0x009CEC30
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_242633()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$242634_0
// EA  : 0x829CEC58
// RVA : 0x009CEC58
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_242634_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 240 + 80), tag: TAG_SAVEGAMES);
}


// ========================================================================
// __unwind$242635_0
// EA  : 0x829CEC84
// RVA : 0x009CEC84
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_242635_0()
{
  int v0; // r12

  idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(this: (idCallback *)(v0 - 240 + 96));
}


// ========================================================================
// ?SaveGameAsync@idSessionLocal@@UAAJPBDABV?$idStaticList@PAVidFile_SaveGame@@$09@@ABVidSaveGameDetails@@@Z
// EA  : 0x829CECB8
// RVA : 0x009CECB8
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

float *__fastcall idSessionLocal::SaveGameAsync(
        idSessionLocal *this,
        char *name,
        const idList<idMD6Node *,5> *files,
        idSaveGameDetails *description)
{
  float *v7; // r25
  idFile_Memory *v8; // r3
  idFile_SaveGame *v9; // r30
  idAFBody **v10; // r29
  idSaveGameProcessor *v11; // r30
  idSaveLoadParms *v12; // r6
  idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *> *v13; // r3
  int v14; // r10
  int v15; // r9
  int v16; // r8
  int v17; // r7
  int v18; // r6
  int v19; // r5
  idSaveLoadParms *v20; // r4
  int v22; // [sp+8h] [-E8h]
  int v23; // [sp+Ch] [-E4h]
  int v24; // [sp+10h] [-E0h]
  int v25; // [sp+14h] [-DCh]
  int v26; // [sp+18h] [-D8h]
  idAFBody *v27; // [sp+1Ch] [-D4h]
  idSaveGameProcessor *v28; // [sp+50h] [-A0h] BYREF
  idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *> v29; // [sp+60h] [-90h] BYREF
  idStaticList<idFile_SaveGame *,10> v30[2]; // [sp+70h] [-80h] BYREF

  v7 = nullptr;
  idStaticList<idFile_SaveGame *,10>::idStaticList<idFile_SaveGame *,10>(this: v30, other: files);
  v8 = (idFile_Memory *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x154u,
                          tag: TAG_SAVEGAMES,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v9 = (idFile_SaveGame *)v8;
  v28 = (idSaveGameProcessor *)v8;
  if ( v8 != nullptr )
  {
    idFile_Memory::idFile_Memory(this: v8, name: "game.details");
    v9->error = false;
    v9->type = 65;
    v9->__vftable = (idFile_SaveGame_vtbl *)&idFile_SaveGame::`vftable';
  }
  else
  {
    v9 = nullptr;
  }
  v28 = (idSaveGameProcessor *)v9;
  idFile_Memory::MakeWritable(this: v9);
  idSaveGameDetails::WriteDescriptorsToIniFile(this: description, saveGameFile: v9);
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)v30,
    obj: (const encounterGroupRole_t *)&v28);
  v10 = (idAFBody **)&this->stubLobby.fakeParms.layersDeactive.buffer[1992];
  if ( (unsigned __int8)idSaveGameProcessorSaveFiles::InitSave(
                          this: *(idSaveGameProcessorSaveFiles **)&this->stubLobby.fakeParms.layersDeactive.buffer[1992],
                          folder: name,
                          files: v30,
                          descriptionForPS3: description,
                          type: PACKAGE_GAME) == 0 )
    goto LABEL_6;
  v12 = (idSaveLoadParms *)(&(*v10)->__vftable + 2);
  v28 = (idSaveGameProcessor *)*v10;
  v11 = v28;
  v13 = MakeCallback<idSessionLocal,idSaveLoadParms *>(
          result: &v29,
          t: this,
          f: idSessionLocal::OnSaveCompleted,
          a1: v12);
  v28 = v11;
  idSaveGameProcessor::AddCompletedCallback(this: v11, callback: v13);
  v29.__vftable = (idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *>_vtbl *)&idCallback::`vftable';
  common->ShowSaveIndicator(this: common, a2: true, a3: false);
  v7 = idSaveGameManager::ExecuteProcessor(
         this: this->saveGameManager,
         processor: *v10,
         a3: v19,
         a4: v18,
         a5: v17,
         a6: v16,
         a7: v15,
         a8: v14,
         a9: v22,
         a10: v23,
         a11: v24,
         a12: v25,
         a13: v26,
         a14: v27);
  if ( v7 == nullptr )
  {
LABEL_6:
    v20 = (idSaveLoadParms *)(&(*v10)->__vftable + 2);
    (*v10)[3].I.numRows = 16;
    idSessionLocal::OnSaveCompleted(this, parms: v20);
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v30);
  return v7;
}


// ========================================================================
// __unwind$242748
// EA  : 0x829CEE38
// RVA : 0x009CEE38
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_242748()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$242749
// EA  : 0x829CEE60
// RVA : 0x009CEE60
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_242749()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 240 + 80), tag: TAG_SAVEGAMES);
}


// ========================================================================
// __unwind$242750
// EA  : 0x829CEE8C
// RVA : 0x009CEE8C
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_242750()
{
  int v0; // r12

  idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(this: (idCallback *)(v0 - 240 + 96));
}


// ========================================================================
// ?EnumerateSaveGamesSync@idSessionLocal@@UAAJXZ
// EA  : 0x829CEEC0
// RVA : 0x009CEEC0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

float *__fastcall idSessionLocal::EnumerateSaveGamesSync(idSessionLocal *this)
{
  idSaveGameManager *saveGameManager; // r30
  float *v3; // r28
  idStr *list; // r3
  char *v5; // r30
  idSaveGameProcessor *v6; // r28
  idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *> *v7; // r3
  idAFBody *v8; // r4
  idSaveGameManager *v9; // r3
  int v10; // r8
  int v11; // r7
  int v12; // r6
  int v13; // r5
  idSaveLoadParms *v14; // r4
  idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *> v16; // [sp+60h] [-40h] BYREF

  saveGameManager = this->saveGameManager;
  v3 = nullptr;
  if ( saveGameManager->enumeratedSaveGames.listStatic == 0 || saveGameManager->enumeratedSaveGames.listStatic == 2 )
  {
    list = (idStr *)saveGameManager->enumeratedSaveGames.list;
    if ( list != nullptr )
      idListArrayDelete<idSaveGameDetails>(ptr: list, num: saveGameManager->enumeratedSaveGames.size);
    saveGameManager->enumeratedSaveGames.list = nullptr;
    saveGameManager->enumeratedSaveGames.size = 0;
  }
  saveGameManager->enumeratedSaveGames.num = 0;
  v5 = &this->stubLobby.fakeParms.layersDeactive.buffer[2004];
  if ( (*(unsigned __int8 (__fastcall **)(_DWORD))(**(_DWORD **)&this->stubLobby.fakeParms.layersDeactive.buffer[2004]
                                                 + 8))(a1: *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[2004]) == 0
    || (v6 = *(idSaveGameProcessor **)v5,
        v7 = MakeCallback<idSessionLocal,idSaveLoadParms *>(
               result: &v16,
               t: this,
               f: idSessionLocal::OnEnumerationCompleted,
               a1: (idSaveLoadParms *)(*(_DWORD *)v5 + 8)),
        idSaveGameProcessor::AddCompletedCallback(this: v6, callback: v7),
        v8 = *(idAFBody **)v5,
        v9 = this->saveGameManager,
        v16.__vftable = (idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *>_vtbl *)&idCallback::`vftable',
        (v3 = idSaveGameManager::ExecuteProcessorAndWait(
                this: v9,
                processor: v8,
                a3: v13,
                a4: v12,
                a5: v11,
                a6: v10,
                a7: (int)&idCallback::`vftable',
                a8: 0x82000000)) == nullptr) )
  {
    v14 = (idSaveLoadParms *)(*(_DWORD *)v5 + 8);
    *(_DWORD *)(*(_DWORD *)v5 + 2984) = 16;
    idSessionLocal::OnEnumerationCompleted(this, parms: v14);
  }
  return v3;
}


// ========================================================================
// __unwind$242877
// EA  : 0x829CEFB0
// RVA : 0x009CEFB0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_242877()
{
  int v0; // r12

  idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(this: (idCallback *)(v0 - 160 + 96));
}


// ========================================================================
// ?EnumerateSaveGamesAsync@idSessionLocal@@UAAJXZ
// EA  : 0x829CEFE0
// RVA : 0x009CEFE0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

float *__fastcall idSessionLocal::EnumerateSaveGamesAsync(idSessionLocal *this)
{
  idSaveGameManager *saveGameManager; // r30
  float *v3; // r28
  idStr *list; // r3
  char *v5; // r30
  idSaveGameProcessor *v6; // r28
  idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *> *v7; // r3
  idAFBody *v8; // r4
  idSaveGameManager *v9; // r3
  int v10; // r8
  int v11; // r7
  int v12; // r6
  int v13; // r5
  idSaveLoadParms *v14; // r4
  int v16; // [sp+8h] [-98h]
  int v17; // [sp+Ch] [-94h]
  int v18; // [sp+10h] [-90h]
  int v19; // [sp+14h] [-8Ch]
  int v20; // [sp+18h] [-88h]
  idAFBody *v21; // [sp+1Ch] [-84h]
  idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *> v22; // [sp+60h] [-40h] BYREF

  saveGameManager = this->saveGameManager;
  v3 = nullptr;
  if ( saveGameManager->enumeratedSaveGames.listStatic == 0 || saveGameManager->enumeratedSaveGames.listStatic == 2 )
  {
    list = (idStr *)saveGameManager->enumeratedSaveGames.list;
    if ( list != nullptr )
      idListArrayDelete<idSaveGameDetails>(ptr: list, num: saveGameManager->enumeratedSaveGames.size);
    saveGameManager->enumeratedSaveGames.list = nullptr;
    saveGameManager->enumeratedSaveGames.size = 0;
  }
  saveGameManager->enumeratedSaveGames.num = 0;
  v5 = &this->stubLobby.fakeParms.layersDeactive.buffer[2004];
  if ( (*(unsigned __int8 (__fastcall **)(_DWORD))(**(_DWORD **)&this->stubLobby.fakeParms.layersDeactive.buffer[2004]
                                                 + 8))(a1: *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[2004]) == 0
    || (v6 = *(idSaveGameProcessor **)v5,
        v7 = MakeCallback<idSessionLocal,idSaveLoadParms *>(
               result: &v22,
               t: this,
               f: idSessionLocal::OnEnumerationCompleted,
               a1: (idSaveLoadParms *)(*(_DWORD *)v5 + 8)),
        idSaveGameProcessor::AddCompletedCallback(this: v6, callback: v7),
        v8 = *(idAFBody **)v5,
        v9 = this->saveGameManager,
        v22.__vftable = (idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *>_vtbl *)&idCallback::`vftable',
        (v3 = idSaveGameManager::ExecuteProcessor(
                this: v9,
                processor: v8,
                a3: v13,
                a4: v12,
                a5: v11,
                a6: v10,
                a7: (int)&idCallback::`vftable',
                a8: 0x82000000,
                a9: v16,
                a10: v17,
                a11: v18,
                a12: v19,
                a13: v20,
                a14: v21)) == nullptr) )
  {
    v14 = (idSaveLoadParms *)(*(_DWORD *)v5 + 8);
    *(_DWORD *)(*(_DWORD *)v5 + 2984) = 16;
    idSessionLocal::OnEnumerationCompleted(this, parms: v14);
  }
  return v3;
}


// ========================================================================
// __unwind$242977
// EA  : 0x829CF0D0
// RVA : 0x009CF0D0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void _unwind_242977()
{
  int v0; // r12

  idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(this: (idCallback *)(v0 - 160 + 96));
}


// ========================================================================
// `dynamic initializer for 'savegame_levelTransitionTimeoutMs''
// EA  : 0x83363828
// RVA : 0x01363828
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__savegame_levelTransitionTimeoutMs__()
{
  idCVar::idCVar(
    this: &savegame_levelTransitionTimeoutMs,
    name: "savegame_levelTransitionTimeoutMs",
    value: "30000",
    flags: 2,
    description: "(ms) timeout value for nextMap testing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__savegame_levelTransitionTimeoutMs__);
}


// ========================================================================
// `dynamic initializer for 'savegame_saveTimeoutMs''
// EA  : 0x83363880
// RVA : 0x01363880
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__savegame_saveTimeoutMs__()
{
  idCVar::idCVar(
    this: &savegame_saveTimeoutMs,
    name: "savegame_saveTimeoutMs",
    value: "60000",
    flags: 2,
    description: "(ms) timeout value for save testing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__savegame_saveTimeoutMs__);
}


// ========================================================================
// `dynamic initializer for 'savegame_error''
// EA  : 0x833638D8
// RVA : 0x013638D8
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__savegame_error__()
{
  idCVar::idCVar(
    this: &savegame_error,
    name: "savegame_error",
    value: "0",
    flags: 2,
    description: "Combination of bits that will simulate and error, see 'savegamePrintErrors'.  0 = no error",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__savegame_error__);
}


// ========================================================================
// `dynamic initializer for 'testSavegameDeleteAll_v''
// EA  : 0x83363930
// RVA : 0x01363930
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testSavegameDeleteAll_v__()
{
  return idCommandLink::idCommandLink(
           this: &testSavegameDeleteAll_v,
           cmdName: "testSavegameDeleteAll",
           function: testSavegameDeleteAll_f,
           description: "delete all savegames without confirmation",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testSavegameDelete_v''
// EA  : 0x83363958
// RVA : 0x01363958
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testSavegameDelete_v__()
{
  return idCommandLink::idCommandLink(
           this: &testSavegameDelete_v,
           cmdName: "testSavegameDelete",
           function: testSavegameDelete_f,
           description: "deletes a savegames without confirmation",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testSavegameEnumerateFiles_v''
// EA  : 0x83363980
// RVA : 0x01363980
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testSavegameEnumerateFiles_v__()
{
  return idCommandLink::idCommandLink(
           this: &testSavegameEnumerateFiles_v,
           cmdName: "testSavegameEnumerateFiles",
           function: testSavegameEnumerateFiles_f,
           description: "enumerates all the files in a folder (blank for 'current slot' folder, use 'autosave' for the autosave slot)",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testSavegameEnumerate_v''
// EA  : 0x833639A8
// RVA : 0x013639A8
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testSavegameEnumerate_v__()
{
  return idCommandLink::idCommandLink(
           this: &testSavegameEnumerate_v,
           cmdName: "testSavegameEnumerate",
           function: testSavegameEnumerate_f,
           description: "enumerates the savegames available",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testPrettyMapName_v''
// EA  : 0x833639D0
// RVA : 0x013639D0
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testPrettyMapName_v__()
{
  return idCommandLink::idCommandLink(
           this: &testPrettyMapName_v,
           cmdName: "testPrettyMapName",
           function: testPrettyMapName_f,
           description: "returns the pretty map name of string passed in or current map",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testSaveGameCheck_v''
// EA  : 0x833639F8
// RVA : 0x013639F8
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testSaveGameCheck_v__()
{
  return idCommandLink::idCommandLink(
           this: &testSaveGameCheck_v,
           cmdName: "testSaveGameCheck",
           function: testSaveGameCheck_f,
           description: "tests existence of savegame",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testSaveGameOutputEnumeratedSavegames_v''
// EA  : 0x83363A20
// RVA : 0x01363A20
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testSaveGameOutputEnumeratedSavegames_v__()
{
  return idCommandLink::idCommandLink(
           this: &testSaveGameOutputEnumeratedSavegames_v,
           cmdName: "testSaveGameOutputEnumeratedSavegames",
           function: testSaveGameOutputEnumeratedSavegames_f,
           description: "outputs the list of savegames already enumerated, this does not re-enumerate",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testSavegameGetCurrentSlot_v''
// EA  : 0x83363A48
// RVA : 0x01363A48
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testSavegameGetCurrentSlot_v__()
{
  return idCommandLink::idCommandLink(
           this: &testSavegameGetCurrentSlot_v,
           cmdName: "testSavegameGetCurrentSlot",
           function: testSavegameGetCurrentSlot_f,
           description: "returns the current slot in use",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testSavegameSetCurrentSlot_v''
// EA  : 0x83363A70
// RVA : 0x01363A70
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testSavegameSetCurrentSlot_v__()
{
  return idCommandLink::idCommandLink(
           this: &testSavegameSetCurrentSlot_v,
           cmdName: "testSavegameSetCurrentSlot",
           function: testSavegameSetCurrentSlot_f,
           description: "returns the current slot in use",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'savegameSetErrorBit_v''
// EA  : 0x83363A98
// RVA : 0x01363A98
// PDB : w:\tech5\engine\sys\sys_session_savegames.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__savegameSetErrorBit_v__()
{
  return idCommandLink::idCommandLink(
           this: &savegameSetErrorBit_v,
           cmdName: "savegameSetErrorBit",
           function: savegameSetErrorBit_f,
           description: "Allows you to set savegame_error by bit instead of integer value",
           argCompletion: nullptr);
}

