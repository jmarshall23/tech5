
// ========================================================================
// ?MakeSomeRoomInMemory@@YAXH@Z
// EA  : 0x829DB240
// RVA : 0x009DB240
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void __fastcall MakeSomeRoomInMemory(int freeMemoryInBytes)
{
  unsigned int v2; // r31

  idStreamFileCache::Flush(this: streamFileCache);
  if ( freeMemoryInBytes > 0 )
  {
    v2 = ((unsigned int)(freeMemoryInBytes - 1) >> 16) + 1;
    do
    {
      idStreamFileCache::OutOfMemoryCallback(this: streamFileCache);
      --v2;
    }
    while ( v2 != 0 );
  }
}


// ========================================================================
// ?Sys_ExecuteSavegameCommandAsyncImpl@@YAXPAVidSaveLoadParms@@@Z
// EA  : 0x829DB2A0
// RVA : 0x009DB2A0
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void __fastcall Sys_ExecuteSavegameCommandAsyncImpl(idSaveLoadParms *savegameParms)
{
  idSessionLocalXbox *v1; // r11
  idSaveGameManager *saveGameManager; // r10

  session->saveGameManager->saveThread.data.saveLoadParms = savegameParms;
  v1 = (idSessionLocalXbox *)session;
  saveGameManager = session->saveGameManager;
  if ( saveGameManager->saveThread.threadHandle == 0 )
  {
    idSysThread::StartWorkerThread(
      this: &saveGameManager->saveThread,
      name_: "Savegame",
      core: CORE_1B,
      priority: THREAD_NORMAL,
      stackSize: 0x20000);
    v1 = (idSessionLocalXbox *)session;
  }
  idSysThread::SignalWork(this: &v1->saveGameManager->saveThread);
}


// ========================================================================
// ?Sys_SaveGameCheck@@YAXAA_N0@Z
// EA  : 0x829DB318
// RVA : 0x009DB318
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void __fastcall Sys_SaveGameCheck(bool *exists, bool *autosaveExists)
{
  unsigned int v2; // r29
  char *data; // r27
  idLocalUser *MasterLocalUser; // r3
  unsigned int Myptr; // r30
  unsigned int v8; // r3
  unsigned int v9; // r5
  const char *v10; // r31
  unsigned int v11; // [sp+50h] [-13B0h] BYREF
  void *v12; // [sp+54h] [-13ACh] BYREF
  unsigned int v13; // [sp+58h] [-13A8h] BYREF
  idStr v14; // [sp+60h] [-13A0h] BYREF
  _BYTE v15[264]; // [sp+80h] [-1380h] BYREF
  char v16; // [sp+188h] [-1278h] BYREF

  v2 = 0;
  *exists = false;
  *autosaveExists = false;
  data = AddSaveFolderPrefix(result: &v14, folder: "AUTOSAVE", type: PACKAGE_GAME)->data;
  idStr::FreeData(this: &v14);
  MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: session->signInManager);
  if ( MasterLocalUser != nullptr )
  {
    Myptr = (unsigned int)MasterLocalUser[1].profileMgr.profileSaveProcessor._Myptr;
    v8 = MasterLocalUser->GetInputDevice(this: MasterLocalUser);
    if ( XContentCreateEnumerator(
           dwUserIndex: v8,
           DeviceID: Myptr,
           dwContentType: 1u,
           dwContentFlags: 0,
           cItem: 0x10u,
           pcbBuffer: &v13,
           phEnum: &v12) == 0 )
    {
      if ( XEnumerate(hEnum: v12, pvBuffer: v15, cbBuffer: 0x1340u, pcItemsReturned: &v11, pOverlapped: nullptr) == 0 )
      {
        v9 = v11;
        *exists = v11 != 0;
        idLib::PrintfIf(condition: saveGame_verbose.valueInteger != 0, fmt: "found %d savegames\n", v9);
        if ( v11 != 0 )
        {
          v10 = &v16;
          while ( 1 )
          {
            idLib::PrintfIf(condition: saveGame_verbose.valueInteger != 0, fmt: "found savegame: %s\n", v10);
            if ( idStr::Icmp(s1: v10, s2: data) == 0 )
              break;
            ++v2;
            v10 += 308;
            if ( v2 >= v11 )
              goto LABEL_10;
          }
          *autosaveExists = true;
        }
      }
LABEL_10:
      CloseHandle(hObject: v12);
    }
  }
}


// ========================================================================
// ?Save@idSaveGameThread@@AAAHXZ
// EA  : 0x829DB5E0
// RVA : 0x009DB5E0
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall idSaveGameThread::Save(idSaveGameThread *this)
{
  idSaveGameThread *v1; // r16
  saveGameThreadArgs_t *p_data; // r30
  idLocalUser *LocalUserByInputDevice; // r3
  unsigned int *v4; // r17
  int v6; // r18
  idSaveLoadParms *saveLoadParms; // r21
  idSaveLoadParms *Directory; // r3
  unsigned int v9; // r5
  int v10; // r30
  int v11; // r28
  int v12; // r29
  _DWORD *v13; // r26
  unsigned __int64 v14; // r4
  __int64 v15; // r6 OVERLAPPED
  int v16; // r4 OVERLAPPED
  idSaveLoadParms *v17; // r10
  unsigned int v18; // r22
  unsigned int v19; // r3
  unsigned int v20; // r3
  unsigned int v21; // r30
  idSaveLoadParms *v22; // r3
  char *data; // r5
  int v24; // r26
  unsigned int v25; // r3
  unsigned int v26; // r28
  const char *v27; // r6
  int v28; // r30
  unsigned int v29; // r3
  int num; // r11
  idCVar *v31; // r14
  _DWORD *v32; // r30
  int v33; // r3
  __int64 v34; // r10
  __int64 v35; // r8
  va *v36; // r3
  idFile_Permanent *v37; // r3
  idFile_Permanent *v38; // r28
  int v39; // r11
  idFile_SaveGamePipelined *v40; // r29
  int v41; // r3
  unsigned int LastError; // r3
  const void *v43; // r29
  unsigned int v44; // r3
  unsigned int v45; // r3
  idFile_Permanent_vtbl *v46; // r29
  const void *v47; // r14
  int v48; // r3
  int v49; // r29
  unsigned int v50; // r3
  _DWORD *v51; // r3
  bool v52; // r30
  int (__fastcall *v53)(_DWORD *); // ctr
  const char *v54; // r3
  char *v55; // r28
  unsigned int v56; // r3
  int v57; // r10
  idSaveLoadParms *v58; // r11
  unsigned int v59; // r3
  unsigned int v60; // r5
  int v61; // [sp+8h] [-13A8h]
  int v62; // [sp+Ch] [-13A4h]
  int v63; // [sp+10h] [-13A0h]
  int v64; // [sp+14h] [-139Ch]
  int v65; // [sp+18h] [-1398h]
  int v66; // [sp+1Ch] [-1394h]
  int v67; // [sp+50h] [-1360h]
  blockForIO_t v68; // [sp+58h] [-1358h] BYREF
  idCVar *v69; // [sp+60h] [-1350h]
  unsigned int *v70; // [sp+64h] [-134Ch]
  int v71; // [sp+68h] [-1348h]
  const char *i; // [sp+6Ch] [-1344h]
  idCVar *v73; // [sp+70h] [-1340h]
  _DWORD v74[3]; // [sp+74h] [-133Ch] BYREF
  idStr v75; // [sp+80h] [-1330h] BYREF
  _XCONTENT_DATA v76; // [sp+A0h] [-1310h] BYREF
  idSaveLoadParms v77; // [sp+1E0h] [-11D0h] BYREF

  v1 = this;
  p_data = &this->data;
  LocalUserByInputDevice = idSignInManagerBase::GetLocalUserByInputDevice(
                             this: session->signInManager,
                             index: this->data.saveLoadParms->inputDeviceId);
  v4 = (unsigned int *)LocalUserByInputDevice;
  v70 = (unsigned int *)LocalUserByInputDevice;
  if ( LocalUserByInputDevice == nullptr
    || LocalUserByInputDevice[1].localUserHandle.handle != LODWORD(p_data->saveLoadParms->userId) )
  {
    v1->data.saveLoadParms->errorCode = 1024;
    return -1;
  }
  v6 = 0;
  saveLoadParms = v1->data.saveLoadParms;
  memset(&v76, 0, sizeof(v76));
  Directory = idSaveLoadParms::GetDirectory(this: &v77, result: &saveLoadParms->directory);
  idStr::Copynz(dest: v76.szFileName, src: Directory->directory.data, destsize: 42);
  idStr::FreeData(this: &v77.directory);
  v76.szDisplayName[0] = 0;
  v10 = 0;
  v76.dwContentType = 1;
  v11 = 0;
  v76.DeviceID = v4[12];
  if ( saveLoadParms->files.num > 0 )
  {
    v12 = 0;
    do
    {
      v13 = &saveLoadParms->files.list[v12]->__vftable;
      v10 += (*(int (__fastcall **)(_DWORD *))(*v13 + 36))(a1: v13) + 4;
      if ( v13[83] == 8 )
        v10 += 0x200000;
      ++v11;
      ++v12;
    }
    while ( v11 < saveLoadParms->files.num );
  }
  LODWORD(v14) = 1;
  HIDWORD(v14) = v10;
  v16 = XContentCalculateSize(cbData: v14, cDirectories: v9) >> 32;
  v67 = 0;
  if ( v16 > 0 )
  {
    (*(void (__fastcall **)(unsigned int *, int, __int64 *))(*v4 + 52))(
      a1: v4,
      a2: v16,
      a3: &saveLoadParms->requiredSpaceInBytes);
    *(__int64 *)((char *)&v15 + 4) = saveLoadParms->requiredSpaceInBytes;
    if ( SHIDWORD(v15) > 0 )
    {
      idLib::Warning(fmt: "[%s]: Insufficient room, need %I64d bytes.", "idSaveGameThread::Save", v15);
      saveLoadParms->errorCode = 2;
      return -1;
    }
  }
  v17 = v1->data.saveLoadParms;
  v18 = 3;
  v69 = &saveGame_verbose;
  if ( (v17->mode & 0x200) == 0 )
  {
    v18 = 2;
    v19 = (*(int (__fastcall **)(unsigned int *, int))(*v4 + 28))(a1: v4, a2: v16);
    v20 = XContentDelete(dwUserIndex: v19, pContentData: &v76, pOverlapped: nullptr);
    v21 = v20;
    if ( v20 != 0 && v20 != 3 && v20 != 2 )
    {
      if ( v20 != 1317 )
      {
        idLib::Warning(fmt: "[%s]: XContentDelete failed (%d).", "idSaveGameThread::Save", v20);
        v1->data.saveLoadParms->errorCode = 16;
        return v21;
      }
      v22 = idSaveLoadParms::GetDirectory(
              this: (idSaveLoadParms *)&v77.pattern,
              result: &v1->data.saveLoadParms->directory);
      idLib::PrintfIf(
        condition: saveGame_verbose.valueInteger != 0,
        fmt: "No appropriate user for deletion user, file (%s)\n",
        v22->directory.data);
      idStr::FreeData(this: &v77.pattern);
      v1->data.saveLoadParms->errorCode = 1024;
    }
  }
  data = idSaveLoadParms::GetDirectory(
           this: (idSaveLoadParms *)&v77.description.descriptors.args.size,
           result: &saveLoadParms->directory)->directory.data;
  idLib::PrintfIf(condition: saveGame_verbose.valueInteger != 0, fmt: "Mounting: %s as %s:\\\n", data, "saves");
  idStr::FreeData(this: (idStr *)&v77.description.descriptors.args.size);
  v24 = 0;
  v25 = (*(int (__fastcall **)(unsigned int *))(*v4 + 28))(a1: v4);
  v26 = XContentCreate(
          dwUserIndex: v25,
          pszRootName: "saves",
          pContentData: &v76,
          dwContentFlags: v18,
          pdwDisposition: nullptr,
          pdwLicenseMask: nullptr,
          pOverlapped: nullptr);
  for ( i = &byte_8200D768;
        v26 != 0;
        v26 = XContentCreate(
                dwUserIndex: v29,
                pszRootName: "saves",
                pContentData: &v76,
                dwContentFlags: v18,
                pdwDisposition: nullptr,
                pdwLicenseMask: nullptr,
                pOverlapped: nullptr) )
  {
    v27 = "(ERROR_NO_SYSTEM_RESOURCES)";
    if ( v26 != 1450 )
      v27 = i;
    idLib::Warning(
      fmt: "[%s]: XContentCreate failed. Error = 0x%08x%s (retry count: %d)",
      "idSaveGameThread::Save",
      v26,
      v27,
      v24);
    v28 = 0;
    v68.bytes = (int)(float)(xen_saveGamePageFileCacheEvictionAmount.valueFloat * (float)1048576.0);
    idStreamFileCache::Flush(this: streamFileCache);
    if ( (int)v68.bytes > 0 )
    {
      do
      {
        idStreamFileCache::OutOfMemoryCallback(this: streamFileCache);
        v28 += 0x10000;
      }
      while ( v28 < (int)v68.bytes );
    }
    if ( v24 >= 2 )
      return v26;
    ++v24;
    v29 = (*(int (__fastcall **)(unsigned int *))(*v4 + 28))(a1: v4);
  }
  num = saveLoadParms->files.num;
  v71 = 0;
  if ( num <= 0 )
    goto LABEL_54;
  v31 = &saveGame_checksum;
  v73 = &saveGame_checksum;
  while ( v67 == 0 && !saveLoadParms->cancelled )
  {
    v32 = &saveLoadParms->files.list[v6]->__vftable;
    v33 = (*(int (__fastcall **)(_DWORD *))(*v32 + 4))(a1: v32);
    v36 = va::va(
            this: (va *)&v77.description.slotName.buffer[8],
            fmt: "%s:\\%s",
            a3: __SPAIR64__("saves", v33),
            a4: v35,
            a5: v34,
            a6: v61,
            a7: v62,
            a8: v63,
            a9: v64,
            a10: v65,
            a11: v66);
    idStr::idStr(this: &v75, text: v36);
    idLib::PrintfIf(condition: v69->valueInteger != 0, fmt: "Saving file: %s\n", v75.data);
    v37 = (idFile_Permanent *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x68u,
                                tag: TAG_FILE,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    v74[1] = v37;
    if ( v37 != nullptr )
      v38 = idFile_Permanent::idFile_Permanent(this: v37, relativePath: i, osPath: v75.data, m: FS_WRITE, create: false);
    else
      v38 = nullptr;
    if ( v38 != nullptr )
    {
      if ( idFile_Permanent::IsOpen(this: v38) )
      {
        v39 = v32[83];
        if ( (v39 & 8) != 0 )
        {
          v40 = (idFile_SaveGamePipelined *)_RTDynamicCast(
                                              inptr: v32,
                                              VfDelta: 0,
                                              SrcType: &idFile_SaveGame `RTTI Type Descriptor',
                                              TargetType: &idFile_SaveGamePipelined `RTTI Type Descriptor',
                                              isReference: 0);
          if ( idFile_SaveGamePipelined::NextWriteBlock(this: v40, block: &v68) )
          {
            while ( 1 )
            {
              v41 = v38->Write(this: v38, a2: v68.data, a3: v68.bytes);
              if ( v41 != v68.bytes )
                break;
              if ( !idFile_SaveGamePipelined::NextWriteBlock(this: v40, block: &v68) )
                goto LABEL_49;
            }
            LastError = GetLastError();
            idLib::Warning(fmt: "[%s]: Write failed. Error = %08x", "idSaveGameThread::Save", LastError);
            *((_BYTE *)v32 + 336) = 1;
            v67 = -1;
            saveLoadParms->errorCode = 2;
          }
        }
        else
        {
          if ( ((v39 & 2) != 0 || (v39 & 4) != 0) && v31->valueInteger != 0 )
          {
            v43 = (const void *)v32[80];
            v44 = (*(int (__fastcall **)(_DWORD *))(*v32 + 36))(a1: v32);
            v74[0] = MD5_BlockChecksum(data: v43, length: v44);
            if ( v38->Write(this: v38, a2: v74, a3: 4u) != 4 )
            {
              v45 = GetLastError();
              idLib::Warning(fmt: "[%s]: Write failed. Error = %08x", "idSaveGameThread::Save", v45);
              *((_BYTE *)v32 + 336) = 1;
              v67 = -1;
              saveLoadParms->errorCode = 2;
            }
          }
          v46 = v38->__vftable;
          v47 = (const void *)v32[80];
          v48 = (*(int (__fastcall **)(_DWORD *))(*v32 + 36))(a1: v32);
          v49 = v46->Write(this: v38, a2: v47, a3: v48);
          if ( v49 != (*(int (__fastcall **)(_DWORD *))(*v32 + 36))(a1: v32) )
          {
            v50 = GetLastError();
            idLib::Warning(fmt: "[%s]: Write failed. Error = %08x", "idSaveGameThread::Save", v50);
            *((_BYTE *)v32 + 336) = 1;
            v67 = -1;
            saveLoadParms->errorCode = 2;
          }
          v51 = v32;
          v53 = *(int (__fastcall **)(_DWORD *))(*v32 + 4);
          v52 = v69->valueInteger != 0;
          v54 = (const char *)v53(a1: v51);
          idLib::PrintfIf(condition: v52, fmt: "File %s written, length = %d.\n", v54, v49);
          v31 = v73;
        }
LABEL_49:
        ((void (__fastcall *)(idFile_Permanent *, int))v38->dtr_idFile)(a1: v38, a2: 1);
        idStr::FreeData(this: &v75);
        goto LABEL_52;
      }
      ((void (__fastcall *)(idFile_Permanent *, int))v38->dtr_idFile)(a1: v38, a2: 1);
    }
    v55 = v75.data;
    v56 = GetLastError();
    idLib::Warning(fmt: "[%s]: Couldn't open file for writing, %s. Error = %08x", "idSaveGameThread::Save", v55, v56);
    *((_BYTE *)v32 + 336) = 1;
    v67 = -1;
    saveLoadParms->errorCode = 16;
    idStr::FreeData(this: &v75);
LABEL_52:
    ++v6;
    v57 = saveLoadParms->files.num;
    if ( ++v71 >= v57 )
      break;
  }
  v4 = v70;
  v1 = this;
LABEL_54:
  XContentClose(pszRootName: "saves", pOverlapped: nullptr);
  v58 = v1->data.saveLoadParms;
  if ( v58->cancelled )
    v58->errorCode = 1;
  if ( saveLoadParms->errorCode != 0 )
  {
    v59 = (*(int (__fastcall **)(unsigned int *))(*v4 + 28))(a1: v4);
    v60 = XContentDelete(dwUserIndex: v59, pContentData: &v76, pOverlapped: nullptr);
    if ( v60 != 0 )
      idLib::Warning(
        fmt: "[%s]: XContentDelete failed trying to clean up incomplete save (%d).",
        "idSaveGameThread::Save",
        v60);
  }
  return v67;
}


// ========================================================================
// __unwind$228590
// EA  : 0x829DBE24
// RVA : 0x009DBE24
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_228590()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5040 + 480));
}


// ========================================================================
// __unwind$228591
// EA  : 0x829DBE4C
// RVA : 0x009DBE4C
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_228591()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5040 + 576));
}


// ========================================================================
// __unwind$228592
// EA  : 0x829DBE74
// RVA : 0x009DBE74
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_228592()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5040 + 672));
}


// ========================================================================
// __unwind$228593
// EA  : 0x829DBE9C
// RVA : 0x009DBE9C
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_228593()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5040 + 128));
}


// ========================================================================
// __unwind$228594
// EA  : 0x829DBEC4
// RVA : 0x009DBEC4
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_228594()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 5040 + 120), tag: TAG_FILE);
}


// ========================================================================
// ?Load@idSaveGameThread@@AAAHXZ
// EA  : 0x829DBEF8
// RVA : 0x009DBEF8
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

unsigned int __fastcall idSaveGameThread::Load(idSaveGameThread *this)
{
  idSaveGameThread *v1; // r25
  saveGameThreadArgs_t *p_data; // r29
  idLocalUser *LocalUserByInputDevice; // r3
  unsigned int *v4; // r30
  int v6; // r17
  idSaveLoadParms *saveLoadParms; // r27
  idSaveLoadParms *Directory; // r3
  char *data; // r6
  idCVar *v10; // r28
  unsigned int v11; // r3
  unsigned int v12; // r30
  int num; // r11
  int v14; // r15
  idFile_SaveGame *v15; // r30
  int v16; // r3
  __int64 v17; // r10
  __int64 v18; // r8
  va *v19; // r3
  idFile_Permanent *v20; // r3
  idFile_Permanent *v21; // r28
  idFile_SaveGamePipelined *v22; // r30
  int v23; // r5
  unsigned int v24; // r5
  unsigned int v25; // r3
  unsigned int v26; // r29
  int type; // r11
  int v28; // r11
  char *filePtr; // r29
  unsigned int v30; // r3
  unsigned int v31; // r3
  char *v32; // r29
  unsigned int LastError; // r3
  int v34; // r11
  int v35; // r10
  idSaveLoadParms *v36; // r11
  int v37; // [sp+8h] [-1338h]
  int v38; // [sp+Ch] [-1334h]
  int v39; // [sp+10h] [-1330h]
  int v40; // [sp+14h] [-132Ch]
  int v41; // [sp+18h] [-1328h]
  int v42; // [sp+1Ch] [-1324h]
  blockForIO_t v43; // [sp+50h] [-12F0h] BYREF
  int v44; // [sp+58h] [-12E8h]
  int v45; // [sp+5Ch] [-12E4h] BYREF
  const char *v46; // [sp+60h] [-12E0h]
  const char *v47; // [sp+64h] [-12DCh]
  idCVar *v48; // [sp+68h] [-12D8h]
  struct idFile_SaveGamePipelined *v49; // [sp+6Ch] [-12D4h]
  struct idFile_SaveGame *v50; // [sp+70h] [-12D0h]
  idFile_Permanent *v51; // [sp+74h] [-12CCh]
  idStr v52; // [sp+80h] [-12C0h] BYREF
  _XCONTENT_DATA v53; // [sp+A0h] [-12A0h] BYREF
  idSaveLoadParms v54; // [sp+1E0h] [-1160h] BYREF

  v1 = this;
  p_data = &this->data;
  LocalUserByInputDevice = idSignInManagerBase::GetLocalUserByInputDevice(
                             this: session->signInManager,
                             index: this->data.saveLoadParms->inputDeviceId);
  v4 = (unsigned int *)LocalUserByInputDevice;
  if ( LocalUserByInputDevice == nullptr
    || LocalUserByInputDevice[1].localUserHandle.handle != LODWORD(p_data->saveLoadParms->userId) )
  {
    v1->data.saveLoadParms->errorCode = 1024;
    return -1;
  }
  v6 = 0;
  saveLoadParms = v1->data.saveLoadParms;
  memset(&v53, 0, sizeof(v53));
  Directory = idSaveLoadParms::GetDirectory(this: (idSaveLoadParms *)&v54.pattern, result: &saveLoadParms->directory);
  idStr::Copynz(dest: v53.szFileName, src: Directory->directory.data, destsize: 42);
  idStr::FreeData(this: &v54.pattern);
  v53.szDisplayName[0] = 0;
  v53.dwContentType = 1;
  v53.DeviceID = v4[12];
  data = idSaveLoadParms::GetDirectory(this: &v54, result: &saveLoadParms->directory)->directory.data;
  v10 = &saveGame_verbose;
  v48 = &saveGame_verbose;
  idLib::PrintfIf(
    condition: saveGame_verbose.valueInteger != 0,
    fmt: "[%s] Mounting: %s as %s:\\\n",
    "idSaveGameThread::Load",
    data,
    "saves");
  idStr::FreeData(this: &v54.directory);
  v43.bytes = (int)(float)(xen_saveGamePageFileCacheEvictionAmount.valueFloat * (float)1048576.0);
  MakeSomeRoomInMemory(freeMemoryInBytes: v43.bytes);
  v11 = (*(int (__fastcall **)(unsigned int *))(*v4 + 28))(a1: v4);
  v12 = XContentCreate(
          dwUserIndex: v11,
          pszRootName: "saves",
          pContentData: &v53,
          dwContentFlags: 3u,
          pdwDisposition: nullptr,
          pdwLicenseMask: nullptr,
          pOverlapped: nullptr);
  if ( v12 != 0 )
  {
    idLib::Warning(fmt: "[%s]: XContentCreate failed. Error = %08x", "idSaveGameThread::Load", v12);
    return v12;
  }
  num = saveLoadParms->files.num;
  v44 = 0;
  if ( num <= 0 )
    goto LABEL_41;
  v50 = &idFile_SaveGame `RTTI Type Descriptor';
  v49 = &idFile_SaveGamePipelined `RTTI Type Descriptor';
  v14 = 0;
  v46 = "[%s] Error, couldn't open: %s, GetLastError() = 0x%08X";
  v47 = &byte_8200D768;
  while ( v6 == 0 && !saveLoadParms->cancelled )
  {
    v15 = saveLoadParms->files.list[v14];
    v16 = (int)v15->GetName(this: v15);
    v19 = va::va(
            this: (va *)&v54.description.descriptors.args.size,
            fmt: "%s:\\%s",
            a3: __SPAIR64__("saves", v16),
            a4: v18,
            a5: v17,
            a6: v37,
            a7: v38,
            a8: v39,
            a9: v40,
            a10: v41,
            a11: v42);
    idStr::idStr(this: &v52, text: v19);
    idLib::PrintfIf(condition: v10->valueInteger != 0, fmt: "Loading file: %s\n", v52.data);
    v20 = (idFile_Permanent *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x68u,
                                tag: TAG_FILE,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    v51 = v20;
    if ( v20 != nullptr )
      v21 = idFile_Permanent::idFile_Permanent(
              this: v20,
              relativePath: v47,
              osPath: v52.data,
              m: FS_READ,
              create: false);
    else
      v21 = nullptr;
    if ( v21 != nullptr )
    {
      if ( idFile_Permanent::IsOpen(this: v21) )
      {
        if ( (v15->type & 8) != 0 )
        {
          v22 = (idFile_SaveGamePipelined *)_RTDynamicCast(
                                              inptr: v15,
                                              VfDelta: 0,
                                              SrcType: v50,
                                              TargetType: v49,
                                              isReference: 0);
          if ( idFile_SaveGamePipelined::NextReadBlock(this: v22, block: &v43, lastReadBytes: 0) )
          {
            while ( 1 )
            {
              v24 = v21->Read(this: v21, a2: v43.data, a3: v43.bytes);
              if ( v24 != v43.bytes )
                break;
              if ( !idFile_SaveGamePipelined::NextReadBlock(this: v22, block: &v43, lastReadBytes: v24) )
                goto LABEL_34;
            }
            idFile_SaveGamePipelined::NextReadBlock(this: v22, block: nullptr, lastReadBytes: v24);
          }
        }
        else
        {
          v25 = v21->Length(this: v21);
          v26 = v25;
          v45 = 0;
          type = v15->type;
          if ( ((type & 2) != 0 || (type & 4) != 0) && saveGame_checksum.valueInteger != 0 && v25 >= 4 )
          {
            v21->Read(this: v21, a2: &v45, a3: 4u);
            v26 -= 4;
          }
          v15->SetLength(this: v15, a2: v26);
          v23 = v21->Read(this: v21, a2: v15->filePtr, a3: v26);
          if ( v23 != v26 )
          {
            idLib::Warning(fmt: "[%s] Error, read %d bytes, expected %d.", "idSaveGameThread::Load", v23, v26);
            v15->error = true;
            v6 = -1;
            saveLoadParms->errorCode = 4;
          }
          v28 = v15->type;
          if ( ((v28 & 2) != 0 || (v28 & 4) != 0) && saveGame_checksum.valueInteger != 0 )
          {
            filePtr = v15->filePtr;
            v30 = v15->Length(this: v15);
            v31 = MD5_BlockChecksum(data: filePtr, length: v30);
            v23 = v31;
            if ( v31 != v45 )
            {
              idLib::Warning(fmt: "[%s] Checksum error, %d != %d.", "idSaveGameThread::Load", v31, v45);
              v15->error = true;
              v6 = -1;
              saveLoadParms->errorCode = 4;
            }
          }
        }
LABEL_34:
        ((void (__fastcall *)(idFile_Permanent *, int, int))v21->dtr_idFile)(a1: v21, a2: 1, a3: v23);
        goto LABEL_37;
      }
      ((void (__fastcall *)(idFile_Permanent *, int))v21->dtr_idFile)(a1: v21, a2: 1);
    }
    v32 = v52.data;
    LastError = GetLastError();
    idLib::Warning(fmt: v46, "idSaveGameThread::Load", v32, LastError);
    v34 = v15->type;
    v15->error = true;
    if ( (v34 & 0x80) == 0 )
    {
      saveLoadParms->errorCode = 4;
      idStr::FreeData(this: &v52);
      break;
    }
LABEL_37:
    idStr::FreeData(this: &v52);
    v35 = saveLoadParms->files.num;
    ++v14;
    if ( ++v44 >= v35 )
      break;
    v10 = v48;
  }
  v1 = this;
LABEL_41:
  XContentClose(pszRootName: "saves", pOverlapped: nullptr);
  v36 = v1->data.saveLoadParms;
  if ( v36->cancelled )
    v36->errorCode = 1;
  return v6;
}


// ========================================================================
// __unwind$228901_0
// EA  : 0x829DC484
// RVA : 0x009DC484
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_228901_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4928 + 576));
}


// ========================================================================
// __unwind$228902
// EA  : 0x829DC4AC
// RVA : 0x009DC4AC
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_228902()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4928 + 480));
}


// ========================================================================
// __unwind$228903
// EA  : 0x829DC4D4
// RVA : 0x009DC4D4
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_228903()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4928 + 128));
}


// ========================================================================
// __unwind$228904
// EA  : 0x829DC4FC
// RVA : 0x009DC4FC
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_228904()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 4928 + 116), tag: TAG_FILE);
}


// ========================================================================
// ?Delete@idSaveGameThread@@AAAHXZ
// EA  : 0x829DC530
// RVA : 0x009DC530
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

unsigned int __fastcall idSaveGameThread::Delete(idSaveGameThread *this)
{
  saveGameThreadArgs_t *p_data; // r28
  idLocalUser *LocalUserByInputDevice; // r3
  unsigned int *v4; // r30
  idSaveLoadParms *Directory; // r3
  unsigned int v7; // r3
  unsigned int v8; // r3
  unsigned int v9; // r30
  idSaveLoadParms *v10; // r3
  int v11; // r7
  idSaveLoadParms *v12; // r3
  idSaveLoadParms *v13; // r3
  _XCONTENT_DATA v14; // [sp+50h] [-2F0h] BYREF
  idStr v15[3]; // [sp+190h] [-1B0h] BYREF
  idStr v16[3]; // [sp+1F0h] [-150h] BYREF
  idStr v17[3]; // [sp+250h] [-F0h] BYREF
  idStr v18[4]; // [sp+2B0h] [-90h] BYREF

  p_data = &this->data;
  LocalUserByInputDevice = idSignInManagerBase::GetLocalUserByInputDevice(
                             this: session->signInManager,
                             index: this->data.saveLoadParms->inputDeviceId);
  v4 = (unsigned int *)LocalUserByInputDevice;
  if ( LocalUserByInputDevice == nullptr
    || LocalUserByInputDevice[1].localUserHandle.handle != LODWORD(p_data->saveLoadParms->userId) )
  {
    this->data.saveLoadParms->errorCode = 1024;
    return -1;
  }
  memset(&v14, 0, sizeof(v14));
  Directory = idSaveLoadParms::GetDirectory(this: (idSaveLoadParms *)v17, result: &this->data.saveLoadParms->directory);
  idStr::Copynz(dest: v14.szFileName, src: Directory->directory.data, destsize: 42);
  idStr::FreeData(this: v17);
  v14.szDisplayName[0] = 0;
  v14.dwContentType = 1;
  v14.DeviceID = v4[12];
  v7 = (*(int (__fastcall **)(unsigned int *))(*v4 + 28))(a1: v4);
  v8 = XContentDelete(dwUserIndex: v7, pContentData: &v14, pOverlapped: nullptr);
  v9 = v8;
  switch ( v8 )
  {
    case 0u:
      return 0;
    case 3u:
      v10 = idSaveLoadParms::GetDirectory(this: (idSaveLoadParms *)v18, result: &this->data.saveLoadParms->directory);
      idLib::PrintfIf(
        condition: saveGame_verbose.valueInteger != 0,
        fmt: "Folder (%s) not found, might be benign deletion error.\n",
        v10->directory.data);
      idStr::FreeData(this: v18);
      v11 = 128;
_M229248_1:
      this->data.saveLoadParms->errorCode = v11;
      return 0;
    case 2u:
      v12 = idSaveLoadParms::GetDirectory(this: (idSaveLoadParms *)v15, result: &this->data.saveLoadParms->directory);
      idLib::PrintfIf(
        condition: saveGame_verbose.valueInteger != 0,
        fmt: "File (%s) not found, might be benign deletion error.\n",
        v12->directory.data);
      idStr::FreeData(this: v15);
      v11 = 256;
      goto _M229248_1;
    case 0x525u:
      v13 = idSaveLoadParms::GetDirectory(this: (idSaveLoadParms *)v16, result: &this->data.saveLoadParms->directory);
      idLib::PrintfIf(
        condition: saveGame_verbose.valueInteger != 0,
        fmt: "No appropriate user for deletion user, file (%s)\n",
        v13->directory.data);
      idStr::FreeData(this: v16);
      v11 = 1024;
      goto _M229248_1;
    default:
      break;
  }
  idLib::Warning(fmt: "[%s]: XContentDelete failed (%d).", "idSaveGameThread::Delete", v8);
  return v9;
}


// ========================================================================
// __unwind$229120
// EA  : 0x829DC718
// RVA : 0x009DC718
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229120()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 832 + 592));
}


// ========================================================================
// __unwind$229121
// EA  : 0x829DC740
// RVA : 0x009DC740
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229121()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 832 + 688));
}


// ========================================================================
// __unwind$229122
// EA  : 0x829DC768
// RVA : 0x009DC768
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229122()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 832 + 400));
}


// ========================================================================
// __unwind$229123
// EA  : 0x829DC790
// RVA : 0x009DC790
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229123()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 832 + 496));
}


// ========================================================================
// ?DeleteAll@idSaveGameThread@@AAAHXZ
// EA  : 0x829DC7C0
// RVA : 0x009DC7C0
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

int __fastcall idSaveGameThread::DeleteAll(idSaveGameThread *this)
{
  saveGameThreadArgs_t *p_data; // r28
  idLocalUser *LocalUserByInputDevice; // r3
  idLocalUser *v4; // r24
  unsigned int Myptr; // r29
  int v7; // r18
  unsigned int v8; // r3
  unsigned int v9; // r29
  unsigned int v10; // r3
  unsigned int v11; // r19
  const _XCONTENT_DATA *v12; // r21
  unsigned int v13; // r3
  unsigned int v14; // r3
  unsigned int v15; // r29
  idSaveLoadParms *saveLoadParms; // r4
  idSaveLoadParms *Directory; // r3
  idSaveLoadParms *v18; // r3
  idSaveLoadParms *v19; // r3
  idSaveLoadParms *v20; // r3
  idSaveLoadParms *v21; // r11
  void *v22; // [sp+50h] [-210h] BYREF
  unsigned int v23; // [sp+54h] [-20Ch] BYREF
  unsigned int v24; // [sp+58h] [-208h] BYREF
  idStr v25[3]; // [sp+60h] [-200h] BYREF
  idStr v26[3]; // [sp+C0h] [-1A0h] BYREF
  idStr v27[3]; // [sp+120h] [-140h] BYREF
  idStr v28[7]; // [sp+180h] [-E0h] BYREF

  p_data = &this->data;
  LocalUserByInputDevice = idSignInManagerBase::GetLocalUserByInputDevice(
                             this: session->signInManager,
                             index: this->data.saveLoadParms->inputDeviceId);
  v4 = LocalUserByInputDevice;
  if ( LocalUserByInputDevice == nullptr
    || LocalUserByInputDevice[1].localUserHandle.handle != LODWORD(p_data->saveLoadParms->userId) )
  {
    this->data.saveLoadParms->errorCode = 1024;
    return -1;
  }
  Myptr = (unsigned int)LocalUserByInputDevice[1].profileMgr.profileSaveProcessor._Myptr;
  v7 = 0;
  v8 = LocalUserByInputDevice->GetInputDevice(this: LocalUserByInputDevice);
  v9 = XContentCreateEnumerator(
         dwUserIndex: v8,
         DeviceID: Myptr,
         dwContentType: 1u,
         dwContentFlags: 0,
         cItem: 0x10u,
         pcbBuffer: &v24,
         phEnum: &v22);
  if ( v9 != 0 )
  {
    idLib::Warning(fmt: "[%s]: XContentCreateEnumerator failed (%d).", "idSaveGameThread::DeleteAll", v9);
    this->data.saveLoadParms->errorCode = 8;
LABEL_22:
    v7 = v9;
    goto LABEL_23;
  }
  v10 = XEnumerate(hEnum: v22, pvBuffer: p_data, cbBuffer: 0x1340u, pcItemsReturned: &v23, pOverlapped: nullptr);
  v9 = v10;
  if ( v10 == 0 )
  {
    v11 = 0;
    if ( v23 != 0 )
    {
      v12 = (const _XCONTENT_DATA *)p_data;
      while ( !this->data.saveLoadParms->cancelled )
      {
        v13 = v4->GetInputDevice(this: v4);
        v14 = XContentDelete(dwUserIndex: v13, pContentData: v12, pOverlapped: nullptr);
        v15 = v14;
        if ( v14 != 0 )
        {
          saveLoadParms = this->data.saveLoadParms;
          switch ( v14 )
          {
            case 3u:
              Directory = idSaveLoadParms::GetDirectory(this: (idSaveLoadParms *)v25, result: &saveLoadParms->directory);
              idLib::PrintfIf(
                condition: saveGame_verbose.valueInteger != 0,
                fmt: "Folder (%s) not found, might be benign deletion error.\n",
                Directory->directory.data);
              idStr::FreeData(this: v25);
              this->data.saveLoadParms->errorCode = 128;
              break;
            case 2u:
              v18 = idSaveLoadParms::GetDirectory(this: (idSaveLoadParms *)v27, result: &saveLoadParms->directory);
              idLib::PrintfIf(
                condition: saveGame_verbose.valueInteger != 0,
                fmt: "File (%s) not found, might be benign deletion error.\n",
                v18->directory.data);
              idStr::FreeData(this: v27);
              this->data.saveLoadParms->errorCode = 256;
              break;
            case 0x525u:
              v19 = idSaveLoadParms::GetDirectory(this: (idSaveLoadParms *)v26, result: &saveLoadParms->directory);
              idLib::Warning(
                fmt: "ERROR_NO_SUCH_USER error while deleting folder (%s), are you signed in?",
                v19->directory.data);
              idStr::FreeData(this: v26);
              this->data.saveLoadParms->errorCode = 1024;
              break;
            default:
              v20 = idSaveLoadParms::GetDirectory(this: (idSaveLoadParms *)v28, result: &saveLoadParms->directory);
              idLib::PrintfIf(
                condition: saveGame_verbose.valueInteger != 0,
                fmt: "Error deleting folder (%s), errorcode = %d.\n",
                v20->directory.data,
                v15);
              idStr::FreeData(this: v28);
              idLib::Warning(fmt: "[%s]: XContentDelete failed (%d).", "idSaveGameThread::DeleteAll", v15);
              v7 = -1;
              this->data.saveLoadParms->errorCode = 16;
              goto LABEL_23;
          }
        }
        ++v11;
        ++v12;
        if ( v11 >= v23 )
          goto LABEL_23;
      }
    }
    goto LABEL_23;
  }
  if ( v10 != 18 )
  {
    idLib::Warning(fmt: "[%s]: XEnumerate failed (%d).", "idSaveGameThread::DeleteAll", v10);
    goto LABEL_22;
  }
LABEL_23:
  CloseHandle(hObject: v22);
  v21 = this->data.saveLoadParms;
  if ( v21->cancelled )
    v21->errorCode = 1;
  return v7;
}


// ========================================================================
// __unwind$229283
// EA  : 0x829DCA9C
// RVA : 0x009DCA9C
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229283()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 96));
}


// ========================================================================
// __unwind$229284
// EA  : 0x829DCAC4
// RVA : 0x009DCAC4
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229284()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 288));
}


// ========================================================================
// __unwind$229285
// EA  : 0x829DCAEC
// RVA : 0x009DCAEC
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229285()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 192));
}


// ========================================================================
// __unwind$229286
// EA  : 0x829DCB14
// RVA : 0x009DCB14
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229286()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 384));
}


// ========================================================================
// ?DeleteFiles@idSaveGameThread@@AAAHXZ
// EA  : 0x829DCB48
// RVA : 0x009DCB48
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

unsigned int __fastcall idSaveGameThread::DeleteFiles(idSaveGameThread *this)
{
  int v1; // r21
  saveGameThreadArgs_t *p_data; // r29
  int v4; // r27
  idLocalUser *LocalUserByInputDevice; // r3
  idLocalUser *v6; // r30
  idSaveLoadParms *saveLoadParms; // r28
  idSaveLoadParms *Directory; // r3
  idSaveLoadParms *v10; // r3
  unsigned int v11; // r3
  unsigned int v12; // r3
  unsigned int v13; // r30
  int v14; // r11
  int v15; // r25
  int v16; // r29
  idFile_SaveGame *v17; // r18
  bool v18; // r30
  const char *v19; // r3
  const char *v20; // r3
  unsigned int LastError; // r3
  __int64 v22; // r6
  __int64 v23; // r10
  __int64 v24; // r8
  va *v25; // r3
  void *FirstFileA; // r3
  void *v27; // r24
  bool v28; // r3
  bool v29; // zf
  char *data; // r4
  int v31; // r5
  int v32; // r3
  char v33; // r11
  char v34; // r30
  __int64 v35; // r10
  __int64 v36; // r8
  idSaveLoadParms *PostPattern; // r18
  int len; // r5
  idStr *v39; // r3
  const char *v40; // r4
  int v41; // r5
  int v42; // r3
  char v43; // r11
  char v44; // r30
  va *v45; // r3
  char *v46; // r29
  bool v47; // r30
  unsigned int v48; // r3
  idSaveLoadParms *v49; // r11
  int v50; // [sp+8h] [-25B8h]
  int v51; // [sp+8h] [-25B8h]
  int v52; // [sp+Ch] [-25B4h]
  int v53; // [sp+Ch] [-25B4h]
  int v54; // [sp+10h] [-25B0h]
  int v55; // [sp+10h] [-25B0h]
  int v56; // [sp+14h] [-25ACh]
  int v57; // [sp+14h] [-25ACh]
  int v58; // [sp+18h] [-25A8h]
  int v59; // [sp+18h] [-25A8h]
  int v60; // [sp+1Ch] [-25A4h]
  int v61; // [sp+1Ch] [-25A4h]
  idStr v62; // [sp+60h] [-2560h] BYREF
  idStr v63; // [sp+80h] [-2540h] BYREF
  idStr v64; // [sp+A0h] [-2520h] BYREF
  idStr v65; // [sp+C0h] [-2500h] BYREF
  idSaveLoadParms v66; // [sp+E0h] [-24E0h] BYREF
  va v67; // [sp+1540h] [-1080h] BYREF

  v1 = 0;
  p_data = &this->data;
  v4 = 0;
  LocalUserByInputDevice = idSignInManagerBase::GetLocalUserByInputDevice(
                             this: session->signInManager,
                             index: this->data.saveLoadParms->inputDeviceId);
  v6 = LocalUserByInputDevice;
  if ( LocalUserByInputDevice == nullptr
    || LocalUserByInputDevice[1].localUserHandle.handle != LODWORD(p_data->saveLoadParms->userId) )
  {
    this->data.saveLoadParms->errorCode = 1024;
    return -1;
  }
  saveLoadParms = this->data.saveLoadParms;
  memset(&v66.description.slotName.buffer[8], 0, 308);
  Directory = idSaveLoadParms::GetDirectory(
                this: (idSaveLoadParms *)&v66.detailList.staticList[1].descriptors.argHash.granularity,
                result: &saveLoadParms->directory);
  idStr::Copynz(dest: &v66.detailList.staticList[0].slotName.buffer[40], src: Directory->directory.data, destsize: 42);
  idStr::FreeData(this: (idStr *)&v66.detailList.staticList[1].descriptors.argHash.granularity);
  *(_WORD *)&v66.description.slotName.buffer[16] = 0;
  *(_DWORD *)&v66.description.slotName.buffer[12] = 1;
  *(_DWORD *)&v66.description.slotName.buffer[8] = v6[1].profileMgr.profileSaveProcessor._Myptr;
  v10 = idSaveLoadParms::GetDirectory(
          this: (idSaveLoadParms *)&v66.detailList.staticList[1].slotName.buffer[32],
          result: &saveLoadParms->directory);
  idLib::PrintfIf(
    condition: saveGame_verbose.valueInteger != 0,
    fmt: "Mounting: %s:\\%s\n",
    "saves",
    v10->directory.data);
  idStr::FreeData(this: (idStr *)&v66.detailList.staticList[1].slotName.buffer[32]);
  MakeSomeRoomInMemory(freeMemoryInBytes: (int)(float)(xen_saveGamePageFileCacheEvictionAmount.valueFloat
                                                     * (float)1048576.0));
  v11 = v6->GetInputDevice(this: v6);
  v12 = XContentCreate(
          dwUserIndex: v11,
          pszRootName: "saves",
          pContentData: (const _XCONTENT_DATA *)&v66.description.slotName.buffer[8],
          dwContentFlags: 3u,
          pdwDisposition: nullptr,
          pdwLicenseMask: nullptr,
          pOverlapped: nullptr);
  v13 = v12;
  if ( v12 != 0 )
  {
    v14 = 4;
    if ( v12 != 1392 )
      v14 = 128;
    saveLoadParms->errorCode = v14;
    idLib::Warning(fmt: "[%s]: XContentCreate failed (%d).", "idSaveGameThread::DeleteFiles", v12);
    return v13;
  }
  v15 = 0;
  if ( saveLoadParms->files.num > 0 )
  {
    v16 = 0;
    do
    {
      if ( saveLoadParms->cancelled )
        break;
      v17 = saveLoadParms->files.list[v16];
      v18 = saveGame_verbose.valueInteger != 0;
      v19 = v17->GetName(this: v17);
      idLib::PrintfIf(condition: v18, fmt: "Trying to delete file %s explicitly\n", v19);
      v20 = v17->GetName(this: v17);
      if ( DeleteFileA(lpFileName: v20) == 0 )
      {
        LastError = GetLastError();
        idLib::PrintfIf(condition: saveGame_verbose.valueInteger != 0, fmt: "Error deleting file: %d\n", LastError);
      }
      ++v15;
      ++v16;
    }
    while ( v15 < saveLoadParms->files.num );
  }
  LODWORD(v22) = idSaveLoadParms::GetPattern(
                   this: (idSaveLoadParms *)&v66.directory.buffer[16],
                   result: (idStrStatic<8> *)saveLoadParms)->directory.data;
  HIDWORD(v22) = "saves";
  v25 = va::va(
          this: (va *)&v66.detailList.staticList[4].slotName,
          fmt: "%s:\\%s*",
          a3: v22,
          a4: v24,
          a5: v23,
          a6: v50,
          a7: v52,
          a8: v54,
          a9: v56,
          a10: v58,
          a11: v60);
  idStr::idStr(this: &v64, text: v25);
  idStr::FreeData(this: (idStr *)&v66.directory.buffer[16]);
  idLib::PrintfIf(condition: saveGame_verbose.valueInteger != 0, fmt: "searching for pattern: %s\n", v64.data);
  FirstFileA = FindFirstFileA(
                 lpFileName: v64.data,
                 lpFindFileData: (_WIN32_FIND_DATAA *)&v66.detailList.staticList[2].slotName);
  v27 = FirstFileA;
  if ( saveGame_verbose.valueInteger == 0 || (v29 = FirstFileA == (void *)-1, v28 = true, !v29) )
    v28 = false;
  idLib::PrintfIf(condition: v28, fmt: "FindFirstFile failed.\n");
  if ( v27 == (void *)-1 )
    goto LABEL_49;
  while ( 1 )
  {
    idStr::idStr(this: &v62, text: &v66.detailList.staticList[2].slotName.buffer[12]);
    idLib::PrintfIf(condition: saveGame_verbose.valueInteger != 0, fmt: "Found: %s.\n", v62.data);
    v4 |= 1u;
    if ( idSaveLoadParms::GetPattern(
           this: (idSaveLoadParms *)&v66.postPattern.allocedAndFlag,
           result: (idStrStatic<8> *)saveLoadParms)->directory.len == 0 )
      goto LABEL_22;
    data = idSaveLoadParms::GetPattern(
             this: (idSaveLoadParms *)&v66.description.date,
             result: (idStrStatic<8> *)saveLoadParms)->directory.data;
    v4 |= 2u;
    v31 = 0;
    if ( *data != 0 )
    {
      do
        ++v31;
      while ( data[v31] != 0 );
    }
    v32 = idStr::Icmpn(s1: v62.data, s2: data, n: v31);
    v33 = 0;
    if ( v32 != 0 )
LABEL_22:
      v33 = 1;
    v34 = v33;
    if ( (v4 & 2) != 0 )
    {
      v4 &= ~2u;
      idStr::FreeData(this: (idStr *)&v66.description.date);
    }
    if ( (v4 & 1) != 0 )
    {
      v4 &= ~1u;
      idStr::FreeData(this: (idStr *)&v66.postPattern.allocedAndFlag);
    }
    if ( v34 != 0 )
      goto LABEL_44;
    v4 |= 4u;
    if ( idSaveLoadParms::GetPostPattern(
           this: (idSaveLoadParms *)&v66.description.descriptors.args.size,
           result: (idStrStatic<8> *)saveLoadParms)->directory.len == 0 )
      goto LABEL_32;
    PostPattern = idSaveLoadParms::GetPostPattern(
                    this: (idSaveLoadParms *)&v66.pattern,
                    result: (idStrStatic<8> *)saveLoadParms);
    len = idSaveLoadParms::GetPostPattern(this: &v66, result: (idStrStatic<8> *)saveLoadParms)->directory.len;
    v39 = idStr::Right(this: &v65, result: &v62, len);
    v40 = PostPattern->directory.data;
    v41 = 0;
    v4 |= 0x38u;
    if ( *v40 != 0 )
    {
      do
        ++v41;
      while ( v40[v41] != 0 );
    }
    v42 = idStr::Icmpn(s1: v39->data, s2: v40, n: v41);
    v43 = 0;
    if ( v42 != 0 )
LABEL_32:
      v43 = 1;
    v44 = v43;
    if ( (v4 & 0x20) != 0 )
    {
      v4 &= ~0x20u;
      idStr::FreeData(this: &v65);
    }
    if ( (v4 & 0x10) != 0 )
    {
      v4 &= ~0x10u;
      idStr::FreeData(this: &v66.directory);
    }
    if ( (v4 & 8) != 0 )
    {
      v4 &= ~8u;
      idStr::FreeData(this: &v66.pattern);
    }
    if ( (v4 & 4) != 0 )
    {
      v4 &= ~4u;
      idStr::FreeData(this: (idStr *)&v66.description.descriptors.args.size);
    }
    if ( v44 == 0 )
    {
      v45 = va::va(
              this: &v67,
              fmt: "%s:\\%s",
              a3: __SPAIR64__("saves", (unsigned int)v62.data),
              a4: v36,
              a5: v35,
              a6: v51,
              a7: v53,
              a8: v55,
              a9: v57,
              a10: v59,
              a11: v61);
      idStr::idStr(this: &v63, text: v45);
      idLib::PrintfIf(condition: saveGame_verbose.valueInteger != 0, fmt: "Deleting file %s.\n", v63.data);
      if ( DeleteFileA(lpFileName: v63.data) == 0 )
        break;
      idStr::FreeData(this: &v63);
    }
LABEL_44:
    idStr::FreeData(this: &v62);
    if ( FindNextFileA(hFindFile: v27, lpFindFileData: (_WIN32_FIND_DATAA *)&v66.detailList.staticList[2].slotName) == 0
      || saveLoadParms->cancelled )
    {
      goto LABEL_48;
    }
  }
  saveLoadParms->errorCode = 16;
  v46 = v63.data;
  v47 = saveGame_verbose.valueInteger != 0;
  v48 = GetLastError();
  idLib::PrintfIf(condition: v47, fmt: "Error deleting file %s (%d)\n", v46, v48);
  v1 = -1;
  idStr::FreeData(this: &v63);
  idStr::FreeData(this: &v62);
LABEL_48:
  CloseHandle(hObject: v27);
LABEL_49:
  XContentClose(pszRootName: "saves", pOverlapped: nullptr);
  v49 = this->data.saveLoadParms;
  if ( v49->cancelled )
    v49->errorCode = 1;
  idStr::FreeData(this: &v64);
  return v1;
}


// ========================================================================
// __unwind$229483
// EA  : 0x829DD150
// RVA : 0x009DD150
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229483()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9664 + 832));
}


// ========================================================================
// __unwind$229484
// EA  : 0x829DD178
// RVA : 0x009DD178
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229484()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9664 + 928));
}


// ========================================================================
// __unwind$229485
// EA  : 0x829DD1A0
// RVA : 0x009DD1A0
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229485()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9664 + 272));
}


// ========================================================================
// __unwind$229486
// EA  : 0x829DD1C8
// RVA : 0x009DD1C8
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229486()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9664 + 160));
}


// ========================================================================
// __unwind$229487
// EA  : 0x829DD1F0
// RVA : 0x009DD1F0
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229487()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9664 + 96));
}


// ========================================================================
// __unwind$229489_0
// EA  : 0x829DD218
// RVA : 0x009DD218
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229489_0()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 9664;
  if ( (*(_DWORD *)(v0 - 9664 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 368));
  }
}


// ========================================================================
// __unwind$229491
// EA  : 0x829DD25C
// RVA : 0x009DD25C
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229491()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 9664;
  if ( (*(_DWORD *)(v0 - 9664 + 80) & 2) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~2u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 464));
  }
}


// ========================================================================
// __unwind$229495
// EA  : 0x829DD2A0
// RVA : 0x009DD2A0
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229495()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 9664;
  if ( (*(_DWORD *)(v0 - 9664 + 80) & 4) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~4u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 416));
  }
}


// ========================================================================
// __unwind$229497
// EA  : 0x829DD2E4
// RVA : 0x009DD2E4
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229497()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 9664;
  if ( (*(_DWORD *)(v0 - 9664 + 80) & 8) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~8u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 320));
  }
}


// ========================================================================
// __unwind$229499
// EA  : 0x829DD328
// RVA : 0x009DD328
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229499()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 9664;
  if ( (*(_DWORD *)(v0 - 9664 + 80) & 0x10) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~0x10u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 224));
  }
}


// ========================================================================
// __unwind$229501
// EA  : 0x829DD36C
// RVA : 0x009DD36C
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229501()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 9664;
  if ( (*(_DWORD *)(v0 - 9664 + 80) & 0x20) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~0x20u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 192));
  }
}


// ========================================================================
// __unwind$229507
// EA  : 0x829DD3B0
// RVA : 0x009DD3B0
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229507()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9664 + 128));
}


// ========================================================================
// ?EnumerateFiles@idSaveGameThread@@AAAHXZ
// EA  : 0x829DD3E0
// RVA : 0x009DD3E0
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

unsigned int __fastcall idSaveGameThread::EnumerateFiles(idSaveGameThread *this)
{
  idSaveGameThread *v1; // r26
  saveGameThreadArgs_t *p_data; // r29
  int v3; // r27
  idLocalUser *LocalUserByInputDevice; // r3
  int *v5; // r30
  idSaveLoadParms *saveLoadParms; // r28
  idSaveLoadParms *Directory; // r3
  idSaveLoadParms *v9; // r3
  unsigned int v10; // r3
  unsigned int v11; // r3
  unsigned int v12; // r30
  int v13; // r11
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  va *v17; // r3
  idSaveLoadParms *FirstFileA; // r3
  idSaveLoadParms *v19; // r29
  bool v20; // r3
  bool v21; // zf
  int v22; // r14
  int len; // r5
  idStr *v24; // r3
  int v25; // r5
  const char *data; // r4
  int v27; // r3
  char v28; // r11
  char v29; // r30
  __int64 v30; // r10
  __int64 v31; // r8
  va *v32; // r3
  idFile_Permanent *v33; // r3
  idFile_Permanent *v34; // r30
  idSaveLoadParms *v35; // r3
  idFile_Memory *v36; // r3
  idFile_Memory *v37; // r30
  idSaveLoadParms *v38; // r11
  idSaveLoadParms *v39; // r11
  int v40; // [sp+8h] [-25D8h]
  int v41; // [sp+8h] [-25D8h]
  int v42; // [sp+Ch] [-25D4h]
  int v43; // [sp+Ch] [-25D4h]
  int v44; // [sp+10h] [-25D0h]
  int v45; // [sp+10h] [-25D0h]
  int v46; // [sp+14h] [-25CCh]
  int v47; // [sp+14h] [-25CCh]
  int v48; // [sp+18h] [-25C8h]
  int v49; // [sp+18h] [-25C8h]
  int v50; // [sp+1Ch] [-25C4h]
  int v51; // [sp+1Ch] [-25C4h]
  idSaveLoadParms *PostPattern; // [sp+54h] [-258Ch] BYREF
  idSaveLoadParms *v53; // [sp+58h] [-2588h]
  int v54; // [sp+5Ch] [-2584h]
  idStr v55; // [sp+60h] [-2580h] BYREF
  idStr v56; // [sp+80h] [-2560h] BYREF
  idStr v57; // [sp+A0h] [-2540h] BYREF
  idStr v58; // [sp+C0h] [-2520h] BYREF
  idSaveLoadParms v59; // [sp+E0h] [-2500h] BYREF
  va v60; // [sp+1540h] [-10A0h] BYREF

  v1 = this;
  p_data = &this->data;
  v3 = 0;
  LocalUserByInputDevice = idSignInManagerBase::GetLocalUserByInputDevice(
                             this: session->signInManager,
                             index: this->data.saveLoadParms->inputDeviceId);
  v5 = (int *)LocalUserByInputDevice;
  if ( LocalUserByInputDevice != nullptr
    && LocalUserByInputDevice[1].localUserHandle.handle == LODWORD(p_data->saveLoadParms->userId) )
  {
    saveLoadParms = v1->data.saveLoadParms;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&saveLoadParms->files);
    memset(&v59.description.descriptors.args.size, 0, 308);
    Directory = idSaveLoadParms::GetDirectory(
                  this: (idSaveLoadParms *)&v59.detailList.staticList[1].slotName.buffer[32],
                  result: &saveLoadParms->directory);
    idStr::Copynz(
      dest: (char *)&v59.detailList.staticList[0].descriptors.argHash.lookupMask,
      src: Directory->directory.data,
      destsize: 42);
    idStr::FreeData(this: (idStr *)&v59.detailList.staticList[1].slotName.buffer[32]);
    HIWORD(v59.description.descriptors.argHash.hash) = 0;
    *(_DWORD *)&v59.description.descriptors.args.granularity = 1;
    v59.description.descriptors.args.size = v5[12];
    v9 = idSaveLoadParms::GetDirectory(
           this: (idSaveLoadParms *)v59.detailList.staticList[0].slotName.buffer,
           result: &saveLoadParms->directory);
    idLib::PrintfIf(
      condition: saveGame_verbose.valueInteger != 0,
      fmt: "Mounting: %s:\\%s\n",
      "saves",
      v9->directory.data);
    idStr::FreeData(this: (idStr *)v59.detailList.staticList[0].slotName.buffer);
    v54 = (int)(float)(xen_saveGamePageFileCacheEvictionAmount.valueFloat * (float)1048576.0);
    MakeSomeRoomInMemory(freeMemoryInBytes: v54);
    v10 = (*(int (__fastcall **)(int *))(*v5 + 28))(a1: v5);
    v11 = XContentCreate(
            dwUserIndex: v10,
            pszRootName: "saves",
            pContentData: (const _XCONTENT_DATA *)&v59.description.descriptors.args.size,
            dwContentFlags: 3u,
            pdwDisposition: nullptr,
            pdwLicenseMask: nullptr,
            pOverlapped: nullptr);
    v12 = v11;
    if ( v11 != 0 )
    {
      v13 = 4;
      if ( v11 != 1392 )
        v13 = 128;
      saveLoadParms->errorCode = v13;
      idLib::Warning(fmt: "[%s]: XContentCreate failed (%d).", "idSaveGameThread::EnumerateFiles", v11);
      return v12;
    }
    else
    {
      LODWORD(v14) = idSaveLoadParms::GetPattern(
                       this: (idSaveLoadParms *)&v59.postPattern.allocedAndFlag,
                       result: (idStrStatic<8> *)saveLoadParms)->directory.data;
      HIDWORD(v14) = "saves";
      v17 = va::va(
              this: (va *)&v59.detailList.staticList[4].slotName,
              fmt: "%s:\\%s*",
              a3: v14,
              a4: v16,
              a5: v15,
              a6: v40,
              a7: v42,
              a8: v44,
              a9: v46,
              a10: v48,
              a11: v50);
      idStr::idStr(this: &v56, text: v17);
      idStr::FreeData(this: (idStr *)&v59.postPattern.allocedAndFlag);
      idLib::PrintfIf(condition: saveGame_verbose.valueInteger != 0, fmt: "searching for pattern: %s\n", v56.data);
      FirstFileA = (idSaveLoadParms *)FindFirstFileA(
                                        lpFileName: v56.data,
                                        lpFindFileData: (_WIN32_FIND_DATAA *)&v59.detailList.staticList[2].slotName);
      v19 = FirstFileA;
      v53 = FirstFileA;
      if ( saveGame_verbose.valueInteger == 0 || (v21 = FirstFileA == (idSaveLoadParms *)-1, v20 = true, !v21) )
        v20 = false;
      idLib::PrintfIf(condition: v20, fmt: "FindFirstFile failed.\n");
      v22 = 0;
      if ( v19 != (idSaveLoadParms *)-1 )
      {
        do
        {
          idStr::idStr(this: &v55, text: &v59.detailList.staticList[2].slotName.buffer[12]);
          idLib::PrintfIf(condition: saveGame_verbose.valueInteger != 0, fmt: "Found: %s.\n", v55.data);
          v3 |= 1u;
          if ( idSaveLoadParms::GetPostPattern(
                 this: (idSaveLoadParms *)&v59.pattern,
                 result: (idStrStatic<8> *)saveLoadParms)->directory.len == 0 )
            goto LABEL_16;
          PostPattern = idSaveLoadParms::GetPostPattern(
                          this: (idSaveLoadParms *)&v59.directory.buffer[16],
                          result: (idStrStatic<8> *)saveLoadParms);
          len = idSaveLoadParms::GetPostPattern(this: &v59, result: (idStrStatic<8> *)saveLoadParms)->directory.len;
          v24 = idStr::Right(this: &v58, result: &v55, len);
          v25 = 0;
          v3 |= 0xEu;
          data = PostPattern->directory.data;
          if ( *data != 0 )
          {
            do
              ++v25;
            while ( data[v25] != 0 );
          }
          v27 = idStr::Icmpn(s1: v24->data, s2: data, n: v25);
          v28 = 1;
          if ( v27 == 0 )
LABEL_16:
            v28 = 0;
          v29 = v28;
          if ( (v3 & 8) != 0 )
          {
            v3 &= ~8u;
            idStr::FreeData(this: &v58);
          }
          if ( (v3 & 4) != 0 )
          {
            v3 &= ~4u;
            idStr::FreeData(this: &v59.directory);
          }
          if ( (v3 & 2) != 0 )
          {
            v3 &= ~2u;
            idStr::FreeData(this: (idStr *)&v59.directory.buffer[16]);
          }
          if ( (v3 & 1) != 0 )
          {
            v3 &= ~1u;
            idStr::FreeData(this: &v59.pattern);
          }
          if ( v29 == 0 )
          {
            if ( (saveLoadParms->mode & 0x100) != 0 && idStr::Cmp(s1: v55.data, s2: "game.details") == 0 )
            {
              v32 = va::va(
                      this: &v60,
                      fmt: "%s:\\%s",
                      a3: __SPAIR64__("saves", (unsigned int)v55.data),
                      a4: v31,
                      a5: v30,
                      a6: v41,
                      a7: v43,
                      a8: v45,
                      a9: v47,
                      a10: v49,
                      a11: v51);
              idStr::idStr(this: &v57, text: v32);
              v33 = (idFile_Permanent *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                          size: 0x68u,
                                          tag: TAG_FILE,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
              PostPattern = (idSaveLoadParms *)v33;
              if ( v33 != nullptr )
                v34 = idFile_Permanent::idFile_Permanent(
                        this: v33,
                        relativePath: &byte_8200D768,
                        osPath: v57.data,
                        m: FS_READ,
                        create: false);
              else
                v34 = nullptr;
              if ( v34 != nullptr )
              {
                if ( (unsigned __int8)SavegameReadDetailsFromFile(file: v34, details: &saveLoadParms->description) == 0 )
                  v22 = -1;
                ((void (__fastcall *)(idFile_Permanent *, int))v34->dtr_idFile)(a1: v34, a2: 1);
              }
              else
              {
                saveLoadParms->description.damaged = true;
              }
              v35 = idSaveLoadParms::GetDirectory(
                      this: (idSaveLoadParms *)&v59.detailList.staticList[1].descriptors.argHash.granularity,
                      result: &saveLoadParms->directory);
              idSaveGameDetails::SetSlotName(this: &saveLoadParms->description, slotName_: v35->directory.data);
              idStr::FreeData(this: (idStr *)&v59.detailList.staticList[1].descriptors.argHash.granularity);
              idStr::FreeData(this: &v57);
              v19 = v53;
            }
            v36 = (idFile_Memory *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x154u,
                                     tag: TAG_SAVEGAMES,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
            v37 = v36;
            PostPattern = (idSaveLoadParms *)v36;
            if ( v36 != nullptr )
            {
              idFile_Memory::idFile_Memory(this: v36, name: v55.data);
              v37->__vftable = (idFile_Memory_vtbl *)&idFile_SaveGame::`vftable';
              v38 = (idSaveLoadParms *)v37;
              v37[1].__vftable = (idFile_Memory_vtbl *)64;
              HIBYTE(v37[1].uniqID) = 0;
            }
            else
            {
              v38 = nullptr;
            }
            PostPattern = v38;
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&saveLoadParms->files,
              obj: (const encounterGroupRole_t *)&PostPattern);
          }
          idStr::FreeData(this: &v55);
        }
        while ( FindNextFileA(
                  hFindFile: v19,
                  lpFindFileData: (_WIN32_FIND_DATAA *)&v59.detailList.staticList[2].slotName) != 0
             && v22 == 0
             && !saveLoadParms->cancelled );
        CloseHandle(hObject: v19);
        v1 = this;
      }
      v39 = v1->data.saveLoadParms;
      if ( v39->cancelled )
      {
        v53 = v1->data.saveLoadParms;
        v39->errorCode = 1;
      }
      XContentClose(pszRootName: "saves", pOverlapped: nullptr);
      idStr::FreeData(this: &v56);
      return v22;
    }
  }
  else
  {
    v1->data.saveLoadParms->errorCode = 1024;
    return -1;
  }
}


// ========================================================================
// __unwind$229977
// EA  : 0x829DD998
// RVA : 0x009DD998
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229977()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9696 + 928));
}


// ========================================================================
// __unwind$229978
// EA  : 0x829DD9C0
// RVA : 0x009DD9C0
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229978()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9696 + 736));
}


// ========================================================================
// __unwind$229979
// EA  : 0x829DD9E8
// RVA : 0x009DD9E8
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229979()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9696 + 368));
}


// ========================================================================
// __unwind$229980
// EA  : 0x829DDA10
// RVA : 0x009DDA10
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229980()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9696 + 128));
}


// ========================================================================
// __unwind$229981
// EA  : 0x829DDA38
// RVA : 0x009DDA38
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229981()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9696 + 96));
}


// ========================================================================
// __unwind$229983
// EA  : 0x829DDA60
// RVA : 0x009DDA60
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229983()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 9696;
  if ( (*(_DWORD *)(v0 - 9696 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 320));
  }
}


// ========================================================================
// __unwind$229985
// EA  : 0x829DDAA4
// RVA : 0x009DDAA4
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229985()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 9696;
  if ( (*(_DWORD *)(v0 - 9696 + 80) & 2) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~2u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 272));
  }
}


// ========================================================================
// __unwind$229987
// EA  : 0x829DDAE8
// RVA : 0x009DDAE8
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229987()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 9696;
  if ( (*(_DWORD *)(v0 - 9696 + 80) & 4) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~4u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 224));
  }
}


// ========================================================================
// __unwind$229989
// EA  : 0x829DDB2C
// RVA : 0x009DDB2C
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229989()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 9696;
  if ( (*(_DWORD *)(v0 - 9696 + 80) & 8) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~8u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 192));
  }
}


// ========================================================================
// __unwind$229995
// EA  : 0x829DDB70
// RVA : 0x009DDB70
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229995()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9696 + 160));
}


// ========================================================================
// __unwind$229996_0
// EA  : 0x829DDB98
// RVA : 0x009DDB98
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229996_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 9696 + 84), tag: TAG_FILE);
}


// ========================================================================
// __unwind$229997
// EA  : 0x829DDBC4
// RVA : 0x009DDBC4
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229997()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9696 + 832));
}


// ========================================================================
// __unwind$229998
// EA  : 0x829DDBEC
// RVA : 0x009DDBEC
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_229998()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 9696 + 84), tag: TAG_SAVEGAMES);
}


// ========================================================================
// ?Enumerate@idSaveGameThread@@AAAHXZ
// EA  : 0x829DDC20
// RVA : 0x009DDC20
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

int __fastcall idSaveGameThread::Enumerate(idSaveGameThread *this)
{
  idSaveGameThread *v1; // r26
  saveGameThreadArgs_t *p_data; // r29
  idLocalUser *LocalUserByInputDevice; // r3
  idLocalUser *v4; // r24
  idList<idSaveGameDetails,5> *saveLoadParms; // r28
  unsigned int Myptr; // r30
  int (__fastcall *GetInputDevice)(idLocalUser *); // r10
  unsigned int v9; // r3
  unsigned int v10; // r30
  unsigned int v11; // r3
  unsigned int v12; // r30
  const char *szFileName; // r25
  idList<idSaveGameDetails,5> *v14; // r29
  unsigned int v15; // r3
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  va *v19; // r3
  __int64 v20; // r6
  __int64 v21; // r10
  __int64 v22; // r8
  va *v23; // r3
  __int64 v24; // r10
  __int64 v25; // r8
  __int64 v26; // r6
  idFile_Permanent *v27; // r3
  idFile_Permanent *v28; // r30
  __int64 v29; // r9
  va *v30; // r3
  _FILETIME ftLastWriteTime; // r30
  __int64 v32; // r10
  __int64 v33; // r8
  __int64 v34; // r6
  va *v35; // r3
  unsigned __int64 v36; // r9
  unsigned __int64 v37; // r11
  idLocalUser_vtbl *v38; // r10
  unsigned int v39; // r3
  unsigned __int64 v40; // r9
  unsigned __int64 v41; // r11
  idSaveLoadParms *v42; // r11
  int v43; // [sp+8h] [-43F8h]
  int v44; // [sp+8h] [-43F8h]
  int v45; // [sp+Ch] [-43F4h]
  int v46; // [sp+Ch] [-43F4h]
  int v47; // [sp+10h] [-43F0h]
  int v48; // [sp+10h] [-43F0h]
  int v49; // [sp+14h] [-43ECh]
  int v50; // [sp+14h] [-43ECh]
  int v51; // [sp+18h] [-43E8h]
  int v52; // [sp+18h] [-43E8h]
  int v53; // [sp+1Ch] [-43E4h]
  int v54; // [sp+1Ch] [-43E4h]
  int v55; // [sp+50h] [-43B0h]
  int v56; // [sp+58h] [-43A8h] BYREF
  int v57; // [sp+5Ch] [-43A4h]
  unsigned int v58; // [sp+60h] [-43A0h]
  unsigned int v59; // [sp+64h] [-439Ch] BYREF
  void *v60; // [sp+68h] [-4398h] BYREF
  _SYSTEMTIME v61; // [sp+70h] [-4390h] BYREF
  _SYSTEMTIME v62; // [sp+80h] [-4380h] BYREF
  idList<idSaveGameDetails,5> *v63; // [sp+90h] [-4370h]
  idList<idSaveGameDetails,5> *v64; // [sp+94h] [-436Ch]
  const char *v65; // [sp+98h] [-4368h]
  const char *v66; // [sp+9Ch] [-4364h]
  _FILETIME v67; // [sp+A0h] [-4360h] BYREF
  _FILETIME v68; // [sp+A8h] [-4358h] BYREF
  unsigned int v69[4]; // [sp+B0h] [-4350h] BYREF
  _BY_HANDLE_FILE_INFORMATION v70; // [sp+C0h] [-4340h] BYREF
  idStr v71; // [sp+100h] [-4300h] BYREF
  idStr v72; // [sp+120h] [-42E0h] BYREF
  idStr v73; // [sp+140h] [-42C0h] BYREF
  idStr v74; // [sp+160h] [-42A0h] BYREF
  idSaveGameDetails v75; // [sp+180h] [-4280h] BYREF
  _WIN32_FIND_DATAA v76; // [sp+220h] [-41E0h] BYREF
  va v77; // [sp+360h] [-40A0h] BYREF
  va v78; // [sp+1360h] [-30A0h] BYREF
  va v79; // [sp+2360h] [-20A0h] BYREF
  va v80; // [sp+3360h] [-10A0h] BYREF

  v1 = this;
  p_data = &this->data;
  LocalUserByInputDevice = idSignInManagerBase::GetLocalUserByInputDevice(
                             this: session->signInManager,
                             index: this->data.saveLoadParms->inputDeviceId);
  v4 = LocalUserByInputDevice;
  if ( LocalUserByInputDevice != nullptr
    && LocalUserByInputDevice[1].localUserHandle.handle == LODWORD(p_data->saveLoadParms->userId) )
  {
    saveLoadParms = (idList<idSaveGameDetails,5> *)v1->data.saveLoadParms;
    Myptr = (unsigned int)LocalUserByInputDevice[1].profileMgr.profileSaveProcessor._Myptr;
    GetInputDevice = LocalUserByInputDevice->GetInputDevice;
    v64 = saveLoadParms;
    v9 = GetInputDevice(this: LocalUserByInputDevice);
    v10 = XContentCreateEnumerator(
            dwUserIndex: v9,
            DeviceID: Myptr,
            dwContentType: 1u,
            dwContentFlags: 0,
            cItem: 0x10u,
            pcbBuffer: v69,
            phEnum: &v60);
    v55 = 0;
    if ( v10 != 0 )
    {
      idLib::Warning(fmt: "[%s]: XContentCreateEnumerator failed (%d).", "idSaveGameThread::Enumerate", v10);
      v55 = v10;
      saveLoadParms[186].list = (idSaveGameDetails *)8;
    }
    else
    {
      v63 = saveLoadParms + 25;
      idList<idSaveGameDetails,5>::Clear(this: saveLoadParms + 25);
      v11 = XEnumerate(hEnum: v60, pvBuffer: p_data, cbBuffer: 0x1340u, pcItemsReturned: &v59, pOverlapped: nullptr);
      v12 = v11;
      if ( v11 != 0 )
      {
        if ( v11 != 18 )
        {
          idLib::Warning(fmt: "[%s]: XEnumerate failed (%d).", "idSaveGameThread::Enumerate", v11);
          v55 = v12;
        }
      }
      else
      {
        v58 = 0;
        if ( v59 != 0 )
        {
          szFileName = v1->data.contentData[0].szFileName;
          v66 = "%s:\\*";
          v65 = &byte_8200D768;
          do
          {
            if ( v55 != 0 )
              break;
            v14 = v64;
            if ( HIBYTE(v64[187].size) != 0 )
              break;
            idSaveGameDetails::idSaveGameDetails(this: &v75);
            v75.damaged = true;
            v57 = (int)(float)(xen_saveGamePageFileCacheEvictionAmount.valueFloat * (float)1048576.0);
            MakeSomeRoomInMemory(freeMemoryInBytes: v57);
            v15 = v4->GetInputDevice(this: v4);
            if ( XContentCreate(
                   dwUserIndex: v15,
                   pszRootName: "saves",
                   pContentData: (const _XCONTENT_DATA *)(szFileName - 264),
                   dwContentFlags: 3u,
                   pdwDisposition: nullptr,
                   pdwLicenseMask: nullptr,
                   pOverlapped: nullptr) != 0 )
            {
              v38 = v4->__vftable;
              v56 = -1;
              v39 = v38->GetInputDevice(this: v4);
              if ( XContentOpenPackage(
                     dwUserIndex: v39,
                     pContentData: (const _XCONTENT_DATA *)(szFileName - 264),
                     phPackageFile: (void **)&v56) == 0 )
              {
                if ( GetFileInformationByHandle(hFile: (void *)v56, lpFileInformation: &v70) != 0 )
                {
                  v62.wYear = 1970;
                  v62.wMonth = 1;
                  v62.wDayOfWeek = 0;
                  v62.wDay = 1;
                  v62.wHour = 0;
                  v62.wMinute = 0;
                  v62.wSecond = 0;
                  v62.wMilliseconds = 0;
                  if ( SystemTimeToFileTime(lpSystemTime: &v62, lpFileTime: &v68) != 0 )
                    LODWORD(v41) = v70.ftLastWriteTime.dwLowDateTime - v68.dwLowDateTime;
                  else
                    LODWORD(v41) = v70.ftLastWriteTime.dwLowDateTime + 717324288;
                  HIDWORD(v41) = 9961472;
                  LODWORD(v40) = 10000000;
                  v75.date = v41 / v40;
                }
                LFCloseSemaphore(handle: (void *)v56);
              }
            }
            else
            {
              HIDWORD(v18) = "saves";
              v19 = va::va(
                      this: &v79,
                      fmt: "%s:\\",
                      a3: v18,
                      a4: v17,
                      a5: v16,
                      a6: v43,
                      a7: v45,
                      a8: v47,
                      a9: v49,
                      a10: v51,
                      a11: v53);
              idStr::idStr(this: &v74, text: v19);
              LODWORD(v20) = "game.details";
              HIDWORD(v20) = "saves";
              v23 = va::va(
                      this: &v77,
                      fmt: "%s:\\%s",
                      a3: v20,
                      a4: v22,
                      a5: v21,
                      a6: v44,
                      a7: v46,
                      a8: v48,
                      a9: v50,
                      a10: v52,
                      a11: v54);
              idStr::idStr(this: &v73, text: v23);
              if ( ((int)v14[11].list & 0x100) != 0 )
              {
                v27 = (idFile_Permanent *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0x68u,
                                            tag: TAG_FILE,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
                v56 = (int)v27;
                v28 = v27 != nullptr
                    ? idFile_Permanent::idFile_Permanent(
                        this: v27,
                        relativePath: v65,
                        osPath: v73.data,
                        m: FS_READ,
                        create: false)
                    : nullptr;
                if ( v28 != nullptr && idFile_Permanent::IsOpen(this: v28) )
                {
                  if ( (unsigned __int8)SavegameReadDetailsFromFile(file: v28, details: &v75) == 0 )
                    v55 = -1;
                  LODWORD(v29) = v28->Timestamp(this: v28);
                  v75.date = v29;
                  ((void (__fastcall *)(idFile_Permanent *, int))v28->dtr_idFile)(a1: v28, a2: 1);
                }
              }
              LODWORD(v24) = v75.damaged;
              if ( v75.damaged )
              {
                HIDWORD(v26) = "saves";
                v30 = va::va(
                        this: &v78,
                        fmt: v66,
                        a3: v26,
                        a4: v25,
                        a5: v24,
                        a6: v43,
                        a7: v45,
                        a8: v47,
                        a9: v49,
                        a10: v51,
                        a11: v53);
                idStr::idStr(this: &v71, text: v30);
                ftLastWriteTime.dwHighDateTime = (unsigned int)FindFirstFileA(
                                                                 lpFileName: v71.data,
                                                                 lpFindFileData: &v76);
                if ( ftLastWriteTime.dwHighDateTime != -1 )
                {
                  do
                  {
                    HIDWORD(v34) = "saves";
                    LODWORD(v34) = v76.cFileName;
                    v35 = va::va(
                            this: &v80,
                            fmt: "%s:\\%s",
                            a3: v34,
                            a4: v33,
                            a5: v32,
                            a6: v43,
                            a7: v45,
                            a8: v47,
                            a9: v49,
                            a10: v51,
                            a11: v53);
                    idStr::idStr(this: &v72, text: v35);
                    if ( GetFileAttributesExA(
                           lpFileName: v72.data,
                           fInfoLevelId: GetFileExInfoStandard,
                           lpFileInformation: &v70) == 1 )
                    {
                      v61.wYear = 1970;
                      v61.wMonth = 1;
                      v61.wDayOfWeek = 0;
                      v61.wDay = 1;
                      v61.wHour = 0;
                      v61.wMinute = 0;
                      v61.wSecond = 0;
                      v61.wMilliseconds = 0;
                      ftLastWriteTime = v70.ftLastWriteTime;
                      if ( SystemTimeToFileTime(lpSystemTime: &v61, lpFileTime: &v67) != 0 )
                        LODWORD(v37) = ftLastWriteTime.dwLowDateTime - v67.dwLowDateTime;
                      else
                        LODWORD(v37) = ftLastWriteTime.dwLowDateTime + 717324288;
                      HIDWORD(v37) = 9961472;
                      LODWORD(v36) = 10000000;
                      v75.date = v37 / v36;
                    }
                    idStr::FreeData(this: &v72);
                  }
                  while ( FindNextFileA(hFindFile: (void *)ftLastWriteTime.dwHighDateTime, lpFindFileData: &v76) != 0 );
                  CloseHandle(hObject: (void *)ftLastWriteTime.dwHighDateTime);
                }
                idStr::FreeData(this: &v71);
              }
              XContentClose(pszRootName: "saves", pOverlapped: nullptr);
              idStr::FreeData(this: &v73);
              idStr::FreeData(this: &v74);
            }
            idLib::PrintfIf(condition: saveGame_verbose.valueInteger != 0, fmt: "Savegame package: %s\n", szFileName);
            idSaveGameDetails::SetSlotName(this: &v75, slotName_: szFileName);
            idList<idSaveGameDetails,5>::Append(this: v63, obj: &v75);
            idSaveGameDetails::~idSaveGameDetails(this: &v75);
            szFileName += 308;
            ++v58;
          }
          while ( v58 < v59 );
          v1 = this;
        }
      }
      CloseHandle(hObject: v60);
    }
    v42 = v1->data.saveLoadParms;
    if ( v42->cancelled )
      v42->errorCode = 1;
    return v55;
  }
  else
  {
    v1->data.saveLoadParms->errorCode = 1024;
    return -1;
  }
}


// ========================================================================
// __unwind$230573
// EA  : 0x829DE1CC
// RVA : 0x009DE1CC
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_230573()
{
  int v0; // r12

  idSaveGameDetails::~idSaveGameDetails(this: (idSaveGameDetails *)(v0 - 17408 + 384));
}


// ========================================================================
// __unwind$230574
// EA  : 0x829DE1F4
// RVA : 0x009DE1F4
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_230574()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 17408 + 352));
}


// ========================================================================
// __unwind$230575
// EA  : 0x829DE21C
// RVA : 0x009DE21C
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_230575()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 17408 + 320));
}


// ========================================================================
// __unwind$230576_0
// EA  : 0x829DE244
// RVA : 0x009DE244
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_230576_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 17408 + 88), tag: TAG_FILE);
}


// ========================================================================
// __unwind$230577
// EA  : 0x829DE270
// RVA : 0x009DE270
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void _unwind_230577()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 17408 + 256));
}


// ========================================================================
// ?Run@idSaveGameThread@@UAAHXZ
// EA  : 0x829DE2A0
// RVA : 0x009DE2A0
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

int __fastcall idSaveGameThread::Run(idSaveGameThread *this)
{
  int v1; // r27
  saveGameThreadArgs_t *p_data; // r30
  idLocalUser *LocalUserByInputDevice; // r3
  idLocalUserXbox *v5; // r29
  char IsStorageDeviceIdValid; // r3
  idSaveLoadParms *saveLoadParms; // r11
  int mode; // r11
  unsigned int v9; // r3
  int v10; // r10
  idSaveLoadParms *v11; // r3

  v1 = 0;
  p_data = &this->data;
  LocalUserByInputDevice = idSignInManagerBase::GetLocalUserByInputDevice(
                             this: session->signInManager,
                             index: this->data.saveLoadParms->inputDeviceId);
  v5 = (idLocalUserXbox *)LocalUserByInputDevice;
  if ( LocalUserByInputDevice != nullptr
    && LocalUserByInputDevice[1].localUserHandle.handle == LODWORD(p_data->saveLoadParms->userId) )
  {
    memset(Dst: p_data, Val: 0, Size: 0x134u);
    IsStorageDeviceIdValid = idLocalUserXbox::IsStorageDeviceIdValid(this: v5);
    saveLoadParms = this->data.saveLoadParms;
    if ( IsStorageDeviceIdValid == 0 )
    {
      v10 = 8;
      goto LABEL_25;
    }
    mode = saveLoadParms->mode;
    if ( (mode & 2) != 0 )
    {
      v9 = idSaveGameThread::Save(this);
    }
    else if ( (mode & 1) != 0 )
    {
      v9 = idSaveGameThread::Load(this);
    }
    else if ( (mode & 0x10) != 0 )
    {
      v9 = idSaveGameThread::Enumerate(this);
    }
    else if ( (mode & 4) != 0 )
    {
      v9 = idSaveGameThread::Delete(this);
    }
    else if ( (mode & 8) != 0 )
    {
      v9 = idSaveGameThread::DeleteAll(this);
    }
    else if ( (mode & 0x80) != 0 )
    {
      v9 = idSaveGameThread::DeleteFiles(this);
    }
    else
    {
      if ( (mode & 0x40) == 0 )
        goto LABEL_26;
      v9 = idSaveGameThread::EnumerateFiles(this);
    }
    v1 = v9;
    if ( v9 == 112 )
    {
      saveLoadParms = this->data.saveLoadParms;
      v10 = 2;
      goto LABEL_25;
    }
    if ( v9 == 0 )
      goto LABEL_26;
  }
  else
  {
    v1 = -1;
    this->data.saveLoadParms->errorCode = 1024;
  }
  saveLoadParms = this->data.saveLoadParms;
  if ( saveLoadParms->errorCode == 0 )
  {
    v10 = 16;
LABEL_25:
    saveLoadParms->errorCode = v10;
  }
LABEL_26:
  v11 = this->data.saveLoadParms;
  if ( v11->errorCode != 0 )
    idSaveLoadParms::CancelSaveGameFilePipelines(this: v11);
  Sys_SignalRaise(handle: &this->data.saveLoadParms->callbackSignal.handle);
  return v1;
}


// ========================================================================
// $M230856_1
// EA  : 0x829DE4A8
// RVA : 0x009DE4A8
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void *_M230856_1()
{
  int v0; // r12

  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v0 - 144 + 164) + 4984) + 2976) = 16;
  return &_LN28_0;
}


// ========================================================================
// `dynamic initializer for 'xen_saveGamePageFileCacheEvictionAmount''
// EA  : 0x83363E90
// RVA : 0x01363E90
// PDB : w:\tech5\engine\sys\xenon\xen_savegame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__xen_saveGamePageFileCacheEvictionAmount__()
{
  idCVar::idCVar(
    this: &xen_saveGamePageFileCacheEvictionAmount,
    name: "xen_saveGamePageFileCacheEvictionAmount",
    value: "1.5",
    flags: 4,
    description: "(float) amount of MB we will evict from the pagefilecache right before we call XContentCreate",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__xen_saveGamePageFileCacheEvictionAmount__);
}

