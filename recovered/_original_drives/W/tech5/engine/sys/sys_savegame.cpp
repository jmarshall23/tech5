
// ========================================================================
// ?savegamePrintErrors_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829BC910
// RVA : 0x009BC910
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall savegamePrintErrors_f(const idCmdArgs *args)
{
  int v1; // r30
  const char **v2; // r31

  idLib::Printf(fmt: "Bit  Description\n---  -----------\n");
  v1 = 0;
  v2 = saveGameErrorStrings;
  do
    idLib::Printf(fmt: "%03d  %s\n", v1++, *v2++);
  while ( (int)v2 < (int)&saveGameErrorStrings[14] );
}


// ========================================================================
// ?WriteDescriptorsToIniFile@idSaveGameDetails@@QBAXPAVidFile_SaveGame@@@Z
// EA  : 0x829BC970
// RVA : 0x009BC970
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

// attributes: thunk
void __fastcall idSaveGameDetails::WriteDescriptorsToIniFile(idSaveGameDetails *this, idFile_SaveGame *saveGameFile)
{
  idDict::WriteToIniFile(this: &this->descriptors, f: saveGameFile);
}


// ========================================================================
// ?SetDescriptorString@idSaveGameDetails@@QAAXPBD0@Z
// EA  : 0x829BC978
// RVA : 0x009BC978
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall idSaveGameDetails::SetDescriptorString(idSaveGameDetails *this, const char *key, const char *val)
{
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  idDict::Set(this: &this->descriptors, key, value: val);
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// ?ClearDescriptors@idSaveGameDetails@@QAAXXZ
// EA  : 0x829BC9C8
// RVA : 0x009BC9C8
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall idSaveGameDetails::ClearDescriptors(idSaveGameDetails *this)
{
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  idDict::Clear(this: &this->descriptors);
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// ?Sys_ExecuteSavegameCommandAsync@@YAXPAVidSaveLoadParms@@@Z
// EA  : 0x829BCA80
// RVA : 0x009BCA80
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall Sys_ExecuteSavegameCommandAsync(idSaveLoadParms *savegameParms)
{
  if ( savegameParms == nullptr )
    idLib::Error(fmt: "Programming Error with [%s]", "Sys_ExecuteSavegameCommandAsync");
  if ( saveGame_enable.valueInteger != 0 )
  {
    Sys_ExecuteSavegameCommandAsyncImpl(savegameParms);
  }
  else
  {
    idLib::Warning(fmt: "Savegames are disabled (saveGame_enable = 0). Skipping physical save to media.");
    savegameParms->errorCode = 1;
    Sys_SignalRaise(handle: &savegameParms->callbackSignal.handle);
  }
}


// ========================================================================
// ?SavegameReadDetailsFromFile@@YA_NPAVidFile@@AAVidSaveGameDetails@@@Z
// EA  : 0x829BCB10
// RVA : 0x009BCB10
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

int __fastcall SavegameReadDetailsFromFile(idFile *file, idSaveGameDetails *details)
{
  int v2; // r30
  const idKeyValue *Key; // r3
  const char *v6; // r3
  const idKeyValue *v8; // r3
  const char *data; // r3
  unsigned int v10; // r3

  v2 = 0;
  details->damaged = false;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  LOBYTE(file) = idDict::ReadFromIniFile(this: &details->descriptors, f: file);
  idMem::PopHeap(this: &mem);
  if ( (_BYTE)file == 0 )
    details->damaged = true;
  Key = idDict::FindKey(this: &details->descriptors, key: "ignore_checksum");
  if ( Key == nullptr || (v6 = Key->value.data) == nullptr || atol(nptr: v6) == 0 )
  {
    v8 = idDict::FindKey(this: &details->descriptors, key: "checksum");
    if ( v8 != nullptr )
    {
      data = v8->value.data;
      if ( data != nullptr )
        v2 = atol(nptr: data);
    }
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idDict::Delete(this: &details->descriptors, key: "checksum");
    idMem::PopHeap(this: &mem);
    v10 = idDict::Checksum(this: &details->descriptors);
    if ( v2 == 0 || v10 != v2 )
      details->damaged = true;
  }
  idMem::PopHeap(this: &mem);
  return 1;
}


// ========================================================================
// ?SetDescriptorInt@idSaveGameDetails@@QAAXPBDH@Z
// EA  : 0x829BCC40
// RVA : 0x009BCC40
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall idSaveGameDetails::SetDescriptorInt(idSaveGameDetails *this, const char *key, int val)
{
  __int64 v6; // r10
  __int64 v7; // r6
  __int64 v8; // r8
  va *v9; // r3
  int v10; // [sp+8h] [-1078h]
  int v11; // [sp+Ch] [-1074h]
  int v12; // [sp+10h] [-1070h]
  int v13; // [sp+14h] [-106Ch]
  int v14; // [sp+18h] [-1068h]
  int v15; // [sp+1Ch] [-1064h]
  va v16; // [sp+50h] [-1030h] BYREF

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  LODWORD(v6) = &unk_821F0000;
  HIDWORD(v7) = val;
  v9 = va::va(this: &v16, fmt: "%i", a3: v7, a4: v8, a5: v6, a6: v10, a7: v11, a8: v12, a9: v13, a10: v14, a11: v15);
  idDict::Set(this: &this->descriptors, key, value: v9->buffer);
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// ?CancelSaveGameFilePipelines@idSaveLoadParms@@QAAXXZ
// EA  : 0x829BCCA8
// RVA : 0x009BCCA8
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall idSaveLoadParms::CancelSaveGameFilePipelines(idSaveLoadParms *this)
{
  int v2; // r27
  int v3; // r31
  idFile_SaveGame *v4; // r10
  idFile_SaveGamePipelined *v5; // r3
  idFile_SaveGamePipelined::mode_t mode; // r11

  v2 = 0;
  if ( this->files.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->files.list[v3];
      if ( (v4->type & 8) != 0 )
      {
        v5 = (idFile_SaveGamePipelined *)_RTDynamicCast(
                                           inptr: v4,
                                           VfDelta: 0,
                                           SrcType: &idFile_SaveGame `RTTI Type Descriptor',
                                           TargetType: &idFile_SaveGamePipelined `RTTI Type Descriptor',
                                           isReference: 0);
        mode = v5->mode;
        if ( mode == WRITE )
        {
          idFile_SaveGamePipelined::NextWriteBlock(this: v5, block: nullptr);
        }
        else if ( mode == READ )
        {
          idFile_SaveGamePipelined::NextReadBlock(this: v5, block: nullptr, lastReadBytes: 0);
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->files.num );
  }
}


// ========================================================================
// ?AbortSaveGameFilePipeline@idSaveLoadParms@@QAAXXZ
// EA  : 0x829BCD58
// RVA : 0x009BCD58
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall idSaveLoadParms::AbortSaveGameFilePipeline(idSaveLoadParms *this)
{
  int v2; // r29
  int v3; // r31
  idFile_SaveGame *v4; // r10
  idFile_SaveGamePipelined *v5; // r3

  v2 = 0;
  if ( this->files.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->files.list[v3];
      if ( (v4->type & 8) != 0 )
      {
        v5 = (idFile_SaveGamePipelined *)_RTDynamicCast(
                                           inptr: v4,
                                           VfDelta: 0,
                                           SrcType: &idFile_SaveGame `RTTI Type Descriptor',
                                           TargetType: &idFile_SaveGamePipelined `RTTI Type Descriptor',
                                           isReference: 0);
        idFile_SaveGamePipelined::Abort(this: v5);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->files.num );
  }
}


// ========================================================================
// ?CancelWithHandle@idSaveGameManager@@QAAXABJ@Z
// EA  : 0x829BCDE0
// RVA : 0x009BCDE0
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall idSaveGameManager::CancelWithHandle(idSaveGameManager *this, int *handle)
{
  int v2; // r7
  idSaveGameProcessor *processor; // r11
  int num; // r8
  int v5; // r10
  idSaveGameProcessor **list; // r9
  int i; // r11
  idSaveGameProcessor *v8; // r9

  v2 = *handle;
  if ( *handle != 0 && this->lastExecutedProcessorHandle < v2 )
  {
    processor = this->processor;
    if ( this->processor != nullptr && processor->parms.handle == v2 )
    {
      processor->parms.cancelled = true;
      processor->parms.errorCode = 1;
    }
    else
    {
      num = this->processorQueue.num;
      v5 = 0;
      if ( num > 0 )
      {
        list = this->processorQueue.list;
        for ( i = 0; list[i]->parms.handle != v2; ++i )
        {
          if ( ++v5 >= num )
            return;
        }
        v8 = list[v5];
        v8->parms.cancelled = true;
        v8->parms.errorCode = 1;
      }
    }
  }
}


// ========================================================================
// ?StartNextProcessor@idSaveGameManager@@AAAXXZ
// EA  : 0x829BCE88
// RVA : 0x009BCE88
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall idSaveGameManager::StartNextProcessor(idSaveGameManager *this)
{
  int v2; // r29
  int v3; // r31
  int v4; // r30
  idSaveGameProcessor *v5; // r27
  int num; // r11
  int v7; // r11
  bool v8; // zf
  int v9; // r10
  idSaveGameProcessor **v10; // r9

  if ( !this->cancel )
  {
    v2 = 0;
    v3 = 0;
    if ( this->processorQueue.num > 0 )
    {
      v4 = 0;
      while ( !this->processorQueue.list[v4]->IsSimpleProcessor(this: this->processorQueue.list[v4]) )
      {
        ++v3;
        ++v4;
        if ( v3 >= this->processorQueue.num )
          goto LABEL_8;
      }
      v2 = v3;
    }
LABEL_8:
    if ( this->processorQueue.num > 0 )
    {
      v5 = this->processorQueue.list[v2];
      Sys_InterlockedIncrement(value: &this->executingProcessorHandle);
      if ( v2 >= 0 )
      {
        num = this->processorQueue.num;
        if ( v2 < num )
        {
          this->processorQueue.num = num - 1;
          v8 = v2 >= num - 1;
          v7 = v2;
          if ( !v8 )
          {
            v9 = v2;
            do
            {
              ++v7;
              v10 = &this->processorQueue.list[v9++];
              *v10 = v10[1];
            }
            while ( v7 < this->processorQueue.num );
          }
        }
      }
      this->processor = v5;
      Sys_SignalRaise(handle: &v5->parms.callbackSignal.handle);
      this->startTime = Sys_Milliseconds();
    }
  }
}


// ========================================================================
// ?FinishProcessor@idSaveGameManager@@AAAXPAVidSaveGameProcessor@@@Z
// EA  : 0x829BCF90
// RVA : 0x009BCF90
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall idSaveGameManager::FinishProcessor(idSaveGameManager *this, idSaveGameProcessor *localProcessor)
{
  bool v3; // r31
  int v4; // r30
  const char *v5; // r3
  int v6; // r31
  idStaticList<idFile_SaveGame *,10> *p_files; // r30
  int v8; // r29
  idFile_SaveGame *v9; // r3
  int num; // r11
  int v11; // r11

  v3 = saveGame_verbose.valueInteger != 0;
  v4 = Sys_Milliseconds() - this->startTime;
  v5 = (const char *)localProcessor->Name(this: localProcessor);
  idLib::PrintfIf(condition: v3, fmt: "[%s] : %s, %d ms\n", "idSaveGameManager::FinishProcessor", v5, v4);
  v6 = localProcessor->parms.files.num - 1;
  if ( v6 >= 0 )
  {
    p_files = &localProcessor->parms.files;
    v8 = v6;
    do
    {
      v9 = p_files->list[v8];
      if ( (v9->type & 0x40) != 0 )
      {
        if ( v9 != nullptr )
          ((void (__fastcall *)(idFile_SaveGame *, int))v9->dtr_idFile)(a1: v9, a2: 1);
        num = localProcessor->parms.files.num;
        if ( v6 < num )
        {
          v11 = num - 1;
          localProcessor->parms.files.num = v11;
          if ( v6 != v11 )
            p_files->list[v8] = p_files->list[v11];
        }
      }
      --v6;
      --v8;
    }
    while ( v6 >= 0 );
  }
  localProcessor->init = false;
}


// ========================================================================
// ?GotWork@idSaveGameManager@@QBA_NXZ
// EA  : 0x829BD090
// RVA : 0x009BD090
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

int __fastcall idSaveGameManager::GotWork(idSaveGameManager *this)
{
  unsigned __int8 v1; // r11

  if ( this->processor != nullptr )
    return 1;
  v1 = 0;
  if ( this->processorQueue.num != 0 )
    return 1;
  return v1;
}


// ========================================================================
// ?GetSaveGameErrorString@@YA?AVidStr@@H@Z
// EA  : 0x829BD1B8
// RVA : 0x009BD1B8
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

idStr *__fastcall GetSaveGameErrorString(idStr *result, int errorMask)
{
  int v3; // r27
  unsigned int v4; // r28
  char **v5; // r26
  int v6; // r29

  result->allocedAndFlag = 20;
  result->data = result->baseBuffer;
  result->len = 0;
  result->baseBuffer[0] = 0;
  v3 = 1;
  v4 = (-errorMask & (unsigned int)~errorMask) >> 31;
  v5 = (char **)saveGameErrorStrings;
  v6 = errorMask;
  do
  {
    if ( v4 == 0 )
      break;
    if ( (v3 & v6) != 0 )
    {
      v6 ^= v3;
      v4 = (-v6 & (unsigned int)~v6) >> 31;
      idStr::Append(this: result, text: *v5);
      if ( (-v6 & ~v6) < 0 )
        idStr::Append(this: result, text: ", ");
    }
    ++v5;
    v3 = __ROL4__(v3, 1);
  }
  while ( (int)v5 < (int)&dword_835CF754 );
  return result;
}


// ========================================================================
// __unwind$230026
// EA  : 0x829BD28C
// RVA : 0x009BD28C
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_230026()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 160;
  if ( (*(_DWORD *)(v0 - 160 + 84) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 84) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 180));
  }
}


// ========================================================================
// ?GetSaveFolder@@YAABVidStr@@W4packageType_t@idSaveGameManager@@@Z
// EA  : 0x829BD2D8
// RVA : 0x009BD2D8
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

idStrStatic<64> *__fastcall GetSaveFolder(idSaveGameManager::packageType_t type)
{
  idStr v3[2]; // [sp+50h] [-50h] BYREF

  if ( (_S13_31 & 1) == 0 )
  {
    _S13_31 |= 1u;
    `eh vector constructor iterator'(
      ptr: saveFolder,
      size: 0x60u,
      count: 3,
      pCtor: (void (__fastcall *)(void *))idStrStatic<64>::idStrStatic<64>,
      pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
    atexit(func: (void (__fastcall *)())_GetSaveFolder_::_2_::_dynamic_atexit_destructor_for__saveFolder__);
  }
  if ( !initialized )
  {
    initialized = true;
    idStr::idStr(this: v3, text: &byte_8200D768);
    idStr::Format(this: &saveFolder[1], fmt: "%s%s", v3[0].data, "GAME-");
    idStr::Format(this: &saveFolder[0], fmt: "%s%s", v3[0].data, &byte_8200D768);
    idStr::Format(this: &saveFolder[2], fmt: "%s%s", v3[0].data, &byte_8200D768);
    idStr::FreeData(this: v3);
  }
  return &saveFolder[type];
}


// ========================================================================
// __unwind$230072
// EA  : 0x829BD3D0
// RVA : 0x009BD3D0
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_230072()
{
  _S13_31 &= ~1u;
}


// ========================================================================
// __unwind$230073
// EA  : 0x829BD3F0
// RVA : 0x009BD3F0
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_230073()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?AddSaveFolderPrefix@@YA?AVidStr@@PBDW4packageType_t@idSaveGameManager@@@Z
// EA  : 0x829BD420
// RVA : 0x009BD420
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

idStr *__fastcall AddSaveFolderPrefix(idStr *result, char *folder, idSaveGameManager::packageType_t type)
{
  idStrStatic<64> *SaveFolder; // r3

  SaveFolder = GetSaveFolder(type);
  idStr::idStr(this: result, text: SaveFolder);
  idStr::Append(this: result, text: folder);
  return result;
}


// ========================================================================
// __unwind$230113
// EA  : 0x829BD478
// RVA : 0x009BD478
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_230113()
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
// ?RemoveSaveFolderPrefix@@YA?AVidStr@@PBDW4packageType_t@idSaveGameManager@@@Z
// EA  : 0x829BD4C8
// RVA : 0x009BD4C8
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

idStr *__fastcall RemoveSaveFolderPrefix(idStr *result, const char *folder, idSaveGameManager::packageType_t type)
{
  idStrStatic<64> *SaveFolder; // r3
  idStr v7[2]; // [sp+60h] [-40h] BYREF

  idStr::idStr(this: result, text: folder);
  SaveFolder = GetSaveFolder(type);
  idStr::idStr(this: v7, text: SaveFolder);
  idStr::StripLeading(this: result, string: v7[0].data);
  idStr::FreeData(this: v7);
  return result;
}


// ========================================================================
// __unwind$230131_0
// EA  : 0x829BD52C
// RVA : 0x009BD52C
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_230131_0()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 160;
  if ( (*(_DWORD *)(v0 - 160 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 180));
  }
}


// ========================================================================
// __unwind$230134
// EA  : 0x829BD570
// RVA : 0x009BD570
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_230134()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// ?CancelAllProcessors@idSaveGameManager@@QAAX_N@Z
// EA  : 0x829BD598
// RVA : 0x009BD598
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall idSaveGameManager::CancelAllProcessors(
        idSaveGameManager *this,
        const bool forceCancelInFlightProcessor)
{
  this->cancel = true;
  if ( forceCancelInFlightProcessor && this->processor != nullptr )
    Sys_SignalRaise(handle: &this->processor->parms.callbackSignal.handle);
  idSaveGameManager::Pump(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->processorQueue);
  this->cancel = false;
}


// ========================================================================
// ?AddCompletedCallback@idSaveGameProcessor@@QAAXABVidCallback@@@Z
// EA  : 0x829BD600
// RVA : 0x009BD600
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall idSaveGameProcessor::AddCompletedCallback(idSaveGameProcessor *this, const idCallback *callback)
{
  idCallback *v3; // [sp+50h] [-20h] BYREF

  v3 = callback->Clone(this: callback);
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->completedCallbacks,
    obj: (const encounterGroupRole_t *)&v3);
}


// ========================================================================
// ?ExecuteProcessor@idSaveGameManager@@QAAJPAVidSaveGameProcessor@@@Z
// EA  : 0x829BD650
// RVA : 0x009BD650
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

float *__fastcall idSaveGameManager::ExecuteProcessor(
        idSaveGameManager *this,
        idAFBody *processor,
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
        idAFBody *a14)
{
  idSaveGameProcessor_vtbl *v14; // r10
  bool v17; // r29
  const char *v18; // r3
  idAFBody **v20; // r29

  v14 = (idSaveGameProcessor_vtbl *)processor->__vftable;
  a14 = processor;
  v17 = saveGame_verbose.valueInteger != 0;
  v18 = v14->Name(this: (idSaveGameProcessor *)processor);
  idLib::PrintfIf(condition: v17, fmt: "[%s] : %s\n", "idSaveGameManager::ExecuteProcessor", v18);
  *((_BYTE *)&processor[3].J + 21) = 1;
  if ( this->processor == nullptr )
    goto LABEL_6;
  if ( (idAFBody *)this->processor == processor )
  {
    idLib::Warning(
      fmt: "[idSaveGameManager::ExecuteProcessor]:1 Someone is trying to execute this processor twice, this is really bad, lea"
      "rn patience padawan!");
    return processor[3].J.mat;
  }
  v20 = idList<idSaveGameProcessor *,5>::Find(this: (idList<idAFBody *,71> *)&this->processorQueue, obj: &a14);
  if ( v20 != nullptr )
  {
    idLib::Warning(
      fmt: "[idSaveGameManager::ExecuteProcessor]:2 Someone is trying to execute this processor twice, this is really bad, lea"
      "rn patience padawan!");
    return (*v20)[3].J.mat;
  }
  else
  {
LABEL_6:
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->processorQueue,
      obj: (const encounterGroupRole_t *)&a14);
    Sys_InterlockedIncrement(value: &this->submittedProcessorHandle);
    processor[3].J.mat = (float *)this->submittedProcessorHandle;
    return (float *)this->submittedProcessorHandle;
  }
}


// ========================================================================
// `idSaveGameManager::Pump'::`47'::idSWFScriptFunction_TryAgain::Call
// EA  : 0x829BD740
// RVA : 0x009BD740
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idSaveGameManager::Pump_::_47_::idSWFScriptFunction_TryAgain::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r10
  int v6; // r9
  int v7; // r8
  int v8; // r7
  int v9; // r6
  int v10; // r5
  int v12; // [sp+8h] [-68h]
  int v13; // [sp+Ch] [-64h]
  int v14; // [sp+10h] [-60h]
  int v15; // [sp+14h] [-5Ch]
  int v16; // [sp+18h] [-58h]
  idAFBody *v17; // [sp+1Ch] [-54h]

  common->ClearDialog(this: common, a2: GDM_ERROR_SAVING_SAVEGAME, a3: nullptr, a4: 0);
  idSaveGameManager::ExecuteProcessor(
    this: (idSaveGameManager *)thisObject->variables.num,
    processor: (idAFBody *)thisObject->variables.size,
    a3: v10,
    a4: v9,
    a5: v8,
    a6: v7,
    a7: v6,
    a8: v5,
    a9: v12,
    a10: v13,
    a11: v14,
    a12: v15,
    a13: v16,
    a14: v17);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ??0idSaveGameDetails@@QAA@XZ
// EA  : 0x829BD8A8
// RVA : 0x009BD8A8
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

idSaveGameDetails *__fastcall idSaveGameDetails::idSaveGameDetails(idSaveGameDetails *this)
{
  __int64 v2; // r29
  char *data; // r6

  idDict::idDict(this: &this->descriptors);
  LODWORD(v2) = 0;
  this->slotName.allocedAndFlag = 20;
  this->slotName.baseBuffer[0] = 0;
  this->slotName.data = this->slotName.buffer;
  this->slotName.buffer[0] = 0;
  this->slotName.len = 0;
  this->slotName.allocedAndFlag = -2147483584;
  HIDWORD(v2) = &mem;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  idDict::Clear(this: &this->descriptors);
  idMem::PopHeap(this: &mem);
  data = this->slotName.data;
  this->damaged = false;
  this->date = v2;
  *data = 0;
  return this;
}


// ========================================================================
// __unwind$230939
// EA  : 0x829BD934
// RVA : 0x009BD934
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_230939()
{
  int v0; // r12

  idDict::~idDict(this: *(idDict **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$230940
// EA  : 0x829BD95C
// RVA : 0x009BD95C
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_230940()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 64));
}


// ========================================================================
// ?Pump@idSaveGameManager@@QAAXXZ
// EA  : 0x829BD990
// RVA : 0x009BD990
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall idSaveGameManager::Pump(idSaveGameManager *this)
{
  idSaveGameProcessor *processor; // r11
  int delayStart; // r11
  char *data; // r28
  idSaveGameProcessor *v5; // r3
  idSaveGameProcessor_vtbl *v6; // r9
  int errorCode; // r27
  bool v8; // r29
  const char *v9; // r3
  int v10; // r28
  idLocalUser *v11; // r3
  int v12; // r27
  int v13; // r26
  idSaveGameDetails *v14; // r29
  bool v15; // r29
  const char *v16; // r3
  idSaveGameProcessor *v17; // r29
  int v18; // r27
  char *v19; // r28
  idSaveGameProcessor *v20; // r3
  bool v21; // r29
  int v22; // r27
  const char *v23; // r3
  bool v24; // r28
  const char *v25; // r3
  idSaveGameProcessor *v26; // r26
  int *v27; // r3
  int *v28; // r11
  idStrStatic<256> *v29; // r3
  int *p_errorCode; // [sp+60h] [-200h] BYREF
  idStrId v31[3]; // [sp+64h] [-1FCh] BYREF
  idList<idVehicleState *,5> v32; // [sp+70h] [-1F0h] BYREF
  _BYTE v33[16]; // [sp+80h] [-1E0h] BYREF
  idList<enum encounterGroupRole_t,5> v34; // [sp+90h] [-1D0h] BYREF
  int v35; // [sp+A0h] [-1C0h] BYREF
  idStr v36; // [sp+B0h] [-1B0h] BYREF
  idStr v37; // [sp+D0h] [-190h] BYREF
  idStrStatic<256> v38; // [sp+F0h] [-170h] BYREF

  processor = this->processor;
  if ( this->processor == nullptr )
  {
    delayStart = this->delayStart;
    if ( delayStart != 0 )
      this->delayStart = delayStart - 1;
    else
      idSaveGameManager::StartNextProcessor(this);
    processor = this->processor;
    if ( this->processor == nullptr )
      return;
    this->continueProcessing = true;
  }
  if ( this->cancel )
    idSaveLoadParms::AbortSaveGameFilePipeline(this: &processor->parms);
  if ( Sys_SignalWait(handle: &this->processor->parms.callbackSignal.handle, timeout: 0) )
  {
    data = GetSaveGameErrorString(result: &v37, errorMask: this->processor->parms.errorCode)->data;
    v5 = this->processor;
    v6 = this->processor->__vftable;
    errorCode = this->processor->parms.errorCode;
    p_errorCode = &this->processor->parms.errorCode;
    v8 = saveGame_verbose.valueInteger != 0;
    v9 = v6->Name(this: v5);
    idLib::PrintfIf(
      condition: v8,
      fmt: "%s waited on processor [%s], error = 0x%08X, %s\n",
      "idSaveGameManager::Pump",
      v9,
      errorCode,
      data);
    idStr::FreeData(this: &v37);
    v10 = 0;
    if ( !this->cancel && this->continueProcessing )
    {
      if ( common->GetMasterLocalUser(this: common) != nullptr )
      {
        v11 = common->GetMasterLocalUser(this: common);
        if ( !v11->IsStorageDeviceAvailable(this: v11) )
          this->processor->parms.errorCode = 8;
      }
      if ( this->processor->parms.errorCode == 0 || this->processor->ValidateLastError(this: this->processor) )
      {
        v19 = GetSaveGameErrorString(result: &v36, errorMask: this->processor->parms.errorCode)->data;
        v20 = this->processor;
        p_errorCode = &this->processor->parms.errorCode;
        v21 = saveGame_verbose.valueInteger != 0;
        v22 = v20->parms.errorCode;
        v23 = (const char *)v20->Name(this: v20);
        idLib::PrintfIf(
          condition: v21,
          fmt: "%s calling %s::Process(), error = 0x%08X, %s\n",
          "idSaveGameManager::Pump",
          v23,
          v22,
          v19);
        idStr::FreeData(this: &v36);
        this->continueProcessing = this->processor->Process(this: this->processor);
        return;
      }
      this->continueProcessing = false;
    }
    if ( !this->continueProcessing )
    {
      v12 = 0;
      if ( this->processor->parms.detailList.num > 0 )
      {
        v13 = 0;
        do
        {
          v14 = &this->processor->parms.detailList.list[v13];
          if ( v14->damaged )
          {
            idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
            idDict::Clear(this: &v14->descriptors);
            idMem::PopHeap(this: &mem);
          }
          ++v12;
          ++v13;
        }
        while ( v12 < this->processor->parms.detailList.num );
      }
      v15 = saveGame_verbose.valueInteger != 0;
      v16 = this->processor->Name(this: this->processor);
      idLib::PrintfIf(condition: v15, fmt: "%s calling %s::CompletedCallback()\n", "idSaveGameManager::Pump", v16);
      this->processor->working = false;
      v17 = this->processor;
      this->processor = nullptr;
      Sys_InterlockedIncrement(value: &this->lastExecutedProcessorHandle);
      if ( v17->completedCallbacks.num > 0 )
      {
        v18 = 0;
        do
        {
          v17->completedCallbacks.list[v18]->Call(this: v17->completedCallbacks.list[v18]);
          ++v10;
          ++v18;
        }
        while ( v10 < v17->completedCallbacks.num );
      }
      idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&v17->completedCallbacks);
      idSaveGameManager::FinishProcessor(this, localProcessor: v17);
    }
  }
  else if ( this->processor->ShouldTimeout(this: this->processor) )
  {
    v24 = saveGame_verbose.valueInteger != 0;
    v25 = this->processor->Name(this: this->processor);
    idLib::PrintfIf(condition: v24, fmt: "----- PROCESSOR TIMEOUT ----- (%s)\n", v25);
    v26 = this->processor;
    idSaveGameManager::CancelAllProcessors(this, forceCancelInFlightProcessor: true);
    *(_QWORD *)&v34.size = 0x400010501LL;
    v34.num = 0;
    v34.list = (encounterGroupRole_t *)&v35;
    *(_QWORD *)&v32.num = 4;
    v32.list = (idVehicleState **)v33;
    *(_DWORD *)&v32.granularity = 66817;
    memset(v33, 255, sizeof(v33));
    v27 = (int *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                   size: 0x10u,
                   tag: TAG_SWF,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
    if ( v27 != nullptr )
    {
      v27[2] = (int)this;
      v27[3] = (int)v26;
      v28 = v27;
      v27[1] = 0;
      *v27 = (int)&`idSaveGameManager::Pump'::`47'::idSWFScriptFunction_TryAgain::`vftable';
    }
    else
    {
      v28 = nullptr;
    }
    p_errorCode = v28;
    idList<idAnimWebBlendTree *,5>::Append(this: &v34, obj: (const encounterGroupRole_t *)&p_errorCode);
    idStrId::Set(this: v31, key: "#STR_SWF_RETRY");
    idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: (idList<idStrId,5> *)&v32, obj: v31);
    v29 = idStrStatic<256>::idStrStatic<256>(this: &v38, text: &byte_8200D768);
    ((void (__fastcall *)(idCommon *, int, idList<enum encounterGroupRole_t,5> *, idList<idVehicleState *,5> *, int, idStrStatic<256> *, _DWORD, _DWORD))common->AddDynamicDialog)(
      a1: common,
      a2: 91,
      a3: &v34,
      a4: &v32,
      a5: 1,
      a6: v29,
      a7: 0,
      a8: 0);
    idList<idThread *,58>::Clear(this: &v32);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v34);
  }
}


// ========================================================================
// __unwind$231037_0
// EA  : 0x829BDE7C
// RVA : 0x009BDE7C
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231037_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 208));
}


// ========================================================================
// __unwind$231038_1
// EA  : 0x829BDEA4
// RVA : 0x009BDEA4
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231038_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 176));
}


// ========================================================================
// __unwind$231039_1
// EA  : 0x829BDECC
// RVA : 0x009BDECC
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231039_1()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 608 + 144));
}


// ========================================================================
// __unwind$231040_0
// EA  : 0x829BDEF4
// RVA : 0x009BDEF4
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231040_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 608 + 112));
}


// ========================================================================
// ?ExecuteProcessorAndWait@idSaveGameManager@@QAAJPAVidSaveGameProcessor@@@Z
// EA  : 0x829BDFB0
// RVA : 0x009BDFB0
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

float *__fastcall idSaveGameManager::ExecuteProcessorAndWait(
        idSaveGameManager *this,
        idAFBody *processor,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  float *result; // r3
  int v10; // r31
  int v11; // [sp+8h] [-68h]
  int v12; // [sp+Ch] [-64h]
  int v13; // [sp+10h] [-60h]
  int v14; // [sp+14h] [-5Ch]
  int v15; // [sp+18h] [-58h]
  idAFBody *v16; // [sp+1Ch] [-54h]

  result = idSaveGameManager::ExecuteProcessor(
             this,
             processor,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9: v11,
             a10: v12,
             a11: v13,
             a12: v14,
             a13: v15,
             a14: v16);
  v10 = (int)result;
  if ( result != nullptr )
  {
    while ( this->lastExecutedProcessorHandle < v10 )
    {
      idSaveGameManager::Pump(this);
      mgthread_sleep(ms: 10);
    }
    return (float *)v10;
  }
  return result;
}


// ========================================================================
// ?WaitForAllProcessors@idSaveGameManager@@QAAX_N@Z
// EA  : 0x829BE028
// RVA : 0x009BE028
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall idSaveGameManager::WaitForAllProcessors(idSaveGameManager *this, bool overrideSimpleProcessorCheck)
{
  idSaveGameProcessor *processor; // r3

  while ( 1 )
  {
    processor = this->processor;
    if ( this->processor == nullptr && this->processorQueue.num <= 0 )
      break;
    if ( !overrideSimpleProcessorCheck
      && (processor != nullptr
        ? !processor->IsSimpleProcessor(this: processor)
        : (*(unsigned __int8 (__fastcall **)(idSaveGameProcessor *))(**(_DWORD **)this->processorQueue.list + 20))(a1: *this->processorQueue.list) == 0) )
    {
      break;
    }
    idSysThread::WaitForThread(this: &this->saveThread);
    idSaveGameManager::Pump(this);
  }
}


// ========================================================================
// ?Init@idSaveLoadParms@@QAAXXZ
// EA  : 0x829BE0E0
// RVA : 0x009BE0E0
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall idSaveLoadParms::Init(idSaveLoadParms *this)
{
  __int64 v2; // r30
  char *data; // r4
  size_t v4; // r5
  char *v5; // r3
  char *v6; // r4
  size_t v7; // r5
  char *v8; // r3
  char *v9; // r4
  size_t v10; // r5
  char *v11; // r3
  char *v12; // r9
  idStr *list; // r3
  idStrStatic<8> v14; // [sp+50h] [-F0h] BYREF
  idStrStatic<8> v15; // [sp+80h] [-C0h] BYREF
  idStrStatic<64> v16; // [sp+B0h] [-90h] BYREF

  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->files);
  LODWORD(v2) = 0;
  this->mode = 0;
  HIDWORD(v2) = &byte_8200D768;
  idStrStatic<64>::idStrStatic<64>(this: &v16, text: &byte_8200D768);
  data = v16.data;
  v4 = v16.len + 1;
  v5 = this->directory.data;
  this->directory.len = v16.len;
  memcpy(Dst: v5, Src: data, Size: v4);
  idStr::FreeData(this: &v16);
  idStrStatic<8>::idStrStatic<8>(this: &v15, text: &byte_8200D768);
  v6 = v15.data;
  v7 = v15.len + 1;
  v8 = this->pattern.data;
  this->pattern.len = v15.len;
  memcpy(Dst: v8, Src: v6, Size: v7);
  idStr::FreeData(this: &v15);
  idStrStatic<8>::idStrStatic<8>(this: &v14, text: &byte_8200D768);
  v9 = v14.data;
  v10 = v14.len + 1;
  v11 = this->postPattern.data;
  this->postPattern.len = v14.len;
  memcpy(Dst: v11, Src: v9, Size: v10);
  idStr::FreeData(this: &v14);
  this->requiredSpaceInBytes = v2;
  HIDWORD(v2) = &this->description;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  idDict::Clear(this: &this->description.descriptors);
  idMem::PopHeap(this: &mem);
  v12 = this->description.slotName.data;
  this->description.damaged = false;
  this->description.date = v2;
  *v12 = 0;
  if ( this->detailList.listStatic == 0 || this->detailList.listStatic == 2 )
  {
    list = (idStr *)this->detailList.list;
    if ( list != nullptr )
      idListArrayDelete<idSaveGameDetails>(ptr: list, num: this->detailList.size);
    this->detailList.list = nullptr;
    this->detailList.size = 0;
  }
  this->detailList.num = 0;
  Sys_SignalClear(handle: &this->callbackSignal.handle);
  this->errorCode = 0;
  this->inputDeviceId = -1;
  this->skipErrorDialogMask = 0;
}


// ========================================================================
// ?SetDefaults@idSaveLoadParms@@QAAXH@Z
// EA  : 0x829BE220
// RVA : 0x009BE220
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall idSaveLoadParms::SetDefaults(idSaveLoadParms *this, int newInputDevice)
{
  idLocalUser *MasterLocalUser; // r3

  idSaveLoadParms::Init(this);
  if ( newInputDevice == -1 )
  {
    if ( session == nullptr )
      return;
    MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: session->signInManager);
  }
  else
  {
    MasterLocalUser = idSignInManagerBase::GetLocalUserByInputDevice(
                        this: session->signInManager,
                        index: newInputDevice);
  }
  if ( MasterLocalUser != nullptr )
  {
    this->userId = *(_QWORD *)MasterLocalUser[1].joiningLobby;
    this->inputDeviceId = MasterLocalUser->GetInputDevice(this: MasterLocalUser);
  }
}


// ========================================================================
// ?Init@idSaveGameProcessor@@UAA_NXZ
// EA  : 0x829BE2B0
// RVA : 0x009BE2B0
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

int __fastcall idSaveGameProcessor::Init(idSaveGameProcessor *this)
{
  const char *v2; // r3
  unsigned __int64 *MasterLocalUser; // r3

  if ( this->working )
  {
    v2 = (const char *)this->Name(this);
    idLib::Warning(fmt: "[%s] Someone is trying to execute this processor twice, this is really bad!", v2);
    return 0;
  }
  else
  {
    this->parms.cancelled = false;
    idSaveLoadParms::Init(this: &this->parms);
    if ( session != nullptr )
    {
      MasterLocalUser = (unsigned __int64 *)idSignInManagerBase::GetMasterLocalUser(this: session->signInManager);
      if ( MasterLocalUser != nullptr )
      {
        this->parms.userId = MasterLocalUser[5];
        this->parms.inputDeviceId = (*(int (__fastcall **)(unsigned __int64 *))(*(_DWORD *)MasterLocalUser + 28))(a1: MasterLocalUser);
      }
    }
    this->savegameLogicTestIterator = 0;
    this->working = false;
    this->init = true;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->completedCallbacks);
    return 1;
  }
}


// ========================================================================
// ??0idSaveLoadParms@@QAA@XZ
// EA  : 0x829BE558
// RVA : 0x009BE558
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

idSaveLoadParms *__fastcall idSaveLoadParms::idSaveLoadParms(idSaveLoadParms *this)
{
  this->directory.allocedAndFlag = 20;
  this->directory.baseBuffer[0] = 0;
  this->directory.data = this->directory.buffer;
  this->directory.buffer[0] = 0;
  this->directory.len = 0;
  this->directory.allocedAndFlag = -2147483584;
  this->pattern.allocedAndFlag = 20;
  this->pattern.baseBuffer[0] = 0;
  this->pattern.buffer[0] = 0;
  this->pattern.data = this->pattern.buffer;
  this->pattern.len = 0;
  this->pattern.allocedAndFlag = -2147483640;
  this->postPattern.allocedAndFlag = 20;
  this->postPattern.baseBuffer[0] = 0;
  this->postPattern.buffer[0] = 0;
  this->postPattern.data = this->postPattern.buffer;
  this->postPattern.len = 0;
  this->postPattern.allocedAndFlag = -2147483640;
  idSaveGameDetails::idSaveGameDetails(this: &this->description);
  this->files.num = 0;
  this->files.granularity = 1;
  this->files.size = 10;
  this->files.list = this->files.staticList;
  this->files.memTag = 5;
  this->files.listStatic = 1;
  idStaticList<idSaveGameDetails,16>::idStaticList<idSaveGameDetails,16>(this: &this->detailList);
  Sys_SignalCreate(handle: &this->callbackSignal.handle, manualReset: false);
  this->cancelled = false;
  idSaveLoadParms::Init(this);
  return this;
}


// ========================================================================
// __unwind$231604
// EA  : 0x829BE644
// RVA : 0x009BE644
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231604()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$231605
// EA  : 0x829BE66C
// RVA : 0x009BE66C
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231605()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 96));
}


// ========================================================================
// __unwind$231606
// EA  : 0x829BE698
// RVA : 0x009BE698
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231606()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$231607
// EA  : 0x829BE6C4
// RVA : 0x009BE6C4
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231607()
{
  int v0; // r12

  idSaveGameDetails::~idSaveGameDetails(this: (idSaveGameDetails *)(*(_DWORD *)(v0 - 112 + 132) + 184));
}


// ========================================================================
// __unwind$231608
// EA  : 0x829BE6F0
// RVA : 0x009BE6F0
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231608()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 344));
}


// ========================================================================
// __unwind$231609
// EA  : 0x829BE71C
// RVA : 0x009BE71C
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231609()
{
  int v0; // r12

  idStaticList<idSaveGameDetails,16>::~idStaticList<idSaveGameDetails,16>(this: (idStaticList<idSaveGameDetails,16> *)(*(_DWORD *)(v0 - 112 + 132) + 400));
}


// ========================================================================
// __unwind$231610
// EA  : 0x829BE748
// RVA : 0x009BE748
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231610()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 112 + 132) + 2996));
}


// ========================================================================
// ??1idSaveLoadParms@@QAA@XZ
// EA  : 0x829BE780
// RVA : 0x009BE780
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall idSaveLoadParms::~idSaveLoadParms(idSaveLoadParms *this)
{
  int v2; // r28
  int v3; // r29
  idFile_SaveGame *v4; // r3
  idFile_SaveGame **list; // r4

  v2 = 0;
  if ( this->files.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->files.list[v3];
      if ( (v4->type & 0x40) != 0 && v4 != nullptr )
        ((void (__fastcall *)(idFile_SaveGame *, int))v4->dtr_idFile)(a1: v4, a2: 1);
      ++v2;
      ++v3;
    }
    while ( v2 < this->files.num );
  }
  Sys_SignalDestroy(handle: &this->callbackSignal.handle);
  idStaticList<idSaveGameDetails,16>::~idStaticList<idSaveGameDetails,16>(this: &this->detailList);
  if ( this->files.listStatic == 0 || this->files.listStatic == 2 )
  {
    list = this->files.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->files.list = nullptr;
    this->files.size = 0;
  }
  this->files.num = 0;
  idStr::FreeData(this: &this->description.slotName);
  idDict::~idDict(this: &this->description.descriptors);
  idStr::FreeData(this: &this->postPattern);
  idStr::FreeData(this: &this->pattern);
  idStr::FreeData(this: &this->directory);
}


// ========================================================================
// __unwind$231829
// EA  : 0x829BE880
// RVA : 0x009BE880
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231829()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$231830
// EA  : 0x829BE8A8
// RVA : 0x009BE8A8
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231830()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 96));
}


// ========================================================================
// __unwind$231831
// EA  : 0x829BE8D4
// RVA : 0x009BE8D4
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231831()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 136));
}


// ========================================================================
// __unwind$231832
// EA  : 0x829BE900
// RVA : 0x009BE900
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231832()
{
  int v0; // r12

  idSaveGameDetails::~idSaveGameDetails(this: (idSaveGameDetails *)(*(_DWORD *)(v0 - 144 + 164) + 184));
}


// ========================================================================
// __unwind$231833
// EA  : 0x829BE92C
// RVA : 0x009BE92C
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231833()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 344));
}


// ========================================================================
// __unwind$231834
// EA  : 0x829BE958
// RVA : 0x009BE958
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231834()
{
  int v0; // r12

  idStaticList<idSaveGameDetails,16>::~idStaticList<idSaveGameDetails,16>(this: (idStaticList<idSaveGameDetails,16> *)(*(_DWORD *)(v0 - 144 + 164) + 400));
}


// ========================================================================
// __unwind$231835
// EA  : 0x829BE984
// RVA : 0x009BE984
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231835()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 144 + 164) + 2996));
}


// ========================================================================
// __unwind$231903
// EA  : 0x829BE9B0
// RVA : 0x009BE9B0
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_231903()
{
  int v0; // r12

  idDict::~idDict(this: *(idDict **)(v0 - 144 + 80));
}


// ========================================================================
// ??0idSaveGameProcessor@@QAA@XZ
// EA  : 0x829BE9D8
// RVA : 0x009BE9D8
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

idSaveGameProcessor *__fastcall idSaveGameProcessor::idSaveGameProcessor(idSaveGameProcessor *this)
{
  this->__vftable = (idSaveGameProcessor_vtbl *)&idSaveGameProcessor::`vftable';
  idSaveLoadParms::idSaveLoadParms(this: &this->parms);
  this->init = false;
  this->working = false;
  this->completedCallbacks.size = 5;
  this->completedCallbacks.num = 0;
  this->completedCallbacks.granularity = 1;
  this->completedCallbacks.list = this->completedCallbacks.staticList;
  this->completedCallbacks.memTag = 5;
  this->completedCallbacks.listStatic = 1;
  return this;
}


// ========================================================================
// ??0idSaveGameManager@@QAA@XZ
// EA  : 0x829BEA58
// RVA : 0x009BEA58
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

idSaveGameManager *__fastcall idSaveGameManager::idSaveGameManager(idSaveGameManager *this)
{
  this->processor = nullptr;
  this->processorQueue.num = 0;
  this->processorQueue.size = 4;
  this->processorQueue.granularity = 1;
  this->processorQueue.list = this->processorQueue.staticList;
  this->processorQueue.memTag = 5;
  this->processorQueue.listStatic = 1;
  this->cancel = false;
  idSysThread::idSysThread(this: &this->saveThread);
  this->saveThread.__vftable = (idSaveGameThread_vtbl *)&idSaveGameThread::`vftable';
  this->saveThread.data.saveLoadParms = nullptr;
  this->saveThread.cancel = false;
  this->delayStart = 0;
  this->startTime = 0;
  this->continueProcessing = false;
  this->submittedProcessorHandle = 0;
  this->executingProcessorHandle = 0;
  this->lastExecutedProcessorHandle = 0;
  idStaticList<idSaveGameDetails,16>::idStaticList<idSaveGameDetails,16>(this: &this->enumeratedSaveGames);
  this->storageAvailable = false;
  return this;
}


// ========================================================================
// __unwind$232034
// EA  : 0x829BEB00
// RVA : 0x009BEB00
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_232034()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$232035
// EA  : 0x829BEB2C
// RVA : 0x009BEB2C
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_232035()
{
  int v0; // r12

  idSaveGameThread::~idSaveGameThread(this: (idCommonLocal::UploadCrashDumps::__l2::idCDWriter *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                                + 40));
}


// ========================================================================
// ??1idSaveGameManager@@QAA@XZ
// EA  : 0x829BEB60
// RVA : 0x009BEB60
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __fastcall idSaveGameManager::~idSaveGameManager(idSaveGameManager *this)
{
  this->processor = nullptr;
  idStaticList<idSaveGameDetails,16>::~idStaticList<idSaveGameDetails,16>(this: &this->enumeratedSaveGames);
  idSysThread::~idSysThread(this: &this->saveThread);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->processorQueue);
}


// ========================================================================
// __unwind$232078
// EA  : 0x829BEBB8
// RVA : 0x009BEBB8
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_232078()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$232079
// EA  : 0x829BEBE4
// RVA : 0x009BEBE4
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _unwind_232079()
{
  int v0; // r12

  idSaveGameThread::~idSaveGameThread(this: (idCommonLocal::UploadCrashDumps::__l2::idCDWriter *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                                + 40));
}


// ========================================================================
// `dynamic initializer for 'saveGame_verbose''
// EA  : 0x83362BD8
// RVA : 0x01362BD8
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__saveGame_verbose__()
{
  idCVar::idCVar(
    this: &saveGame_verbose,
    name: "saveGame_verbose",
    value: "0",
    flags: 1,
    description: "debug spam",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__saveGame_verbose__);
}


// ========================================================================
// `dynamic initializer for 'saveGame_checksum''
// EA  : 0x83362C30
// RVA : 0x01362C30
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__saveGame_checksum__()
{
  idCVar::idCVar(
    this: &saveGame_checksum,
    name: "saveGame_checksum",
    value: "1",
    flags: 1,
    description: "data integrity check",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__saveGame_checksum__);
}


// ========================================================================
// `dynamic initializer for 'saveGame_enable''
// EA  : 0x83362C88
// RVA : 0x01362C88
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__saveGame_enable__()
{
  idCVar::idCVar(
    this: &saveGame_enable,
    name: "saveGame_enable",
    value: "1",
    flags: 1,
    description: "are savegames enabled",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__saveGame_enable__);
}


// ========================================================================
// `dynamic initializer for 'saveGameErrorStrings''
// EA  : 0x83362CE0
// RVA : 0x01362CE0
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

void _dynamic_initializer_for__saveGameErrorStrings__()
{
  saveGameErrorStrings[14] = nullptr;
}


// ========================================================================
// `dynamic initializer for 'savegamePrintErrors_v''
// EA  : 0x83362CF8
// RVA : 0x01362CF8
// PDB : w:\tech5\engine\sys\sys_savegame.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__savegamePrintErrors_v__()
{
  return idCommandLink::idCommandLink(
           this: &savegamePrintErrors_v,
           cmdName: "savegamePrintErrors",
           function: savegamePrintErrors_f,
           description: "Prints error code corresponding to each bit",
           argCompletion: nullptr);
}

