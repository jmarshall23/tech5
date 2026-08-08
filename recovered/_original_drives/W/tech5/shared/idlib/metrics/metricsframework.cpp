
// ========================================================================
// ?GetCurrentSystemTime@idMetricsFramework@@QAA_KXZ
// EA  : 0x82F3CB98
// RVA : 0x00F3CB98
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

int __fastcall idMetricsFramework::GetCurrentSystemTime(idMetricsFramework *this)
{
  unsigned __int64 v1; // r3

  LODWORD(v1) = Sys_CurrentSystemTime() >> 32;
  return v1 / 0x2710 - 817260544;
}


// ========================================================================
// ?GetPushFrame@idMetricsFramework@@QAAHXZ
// EA  : 0x82F3CC50
// RVA : 0x00F3CC50
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

int __fastcall idMetricsFramework::GetPushFrame(idMetricsFramework *this)
{
  unsigned __int64 v2; // r3
  unsigned __int64 v3; // r6
  unsigned __int64 v4; // r11

  if ( idLib::frameNumber != this->lastCheckedPushFrame )
  {
    LODWORD(v2) = Sys_CurrentSystemTime() >> 32;
    LODWORD(v3) = 10000;
    HIDWORD(v3) = &com_logHeartbeat;
    LODWORD(v4) = v2 / v3 - 817260544;
    HIDWORD(v4) = com_logHeartbeat.valueInteger;
    if ( (unsigned int)(v4 - LODWORD(this->currentPushTime)) > com_logHeartbeat.valueInteger )
    {
      this->currentPushTime = v4;
      this->currentPushFrame = idLib::frameNumber;
    }
  }
  return this->currentPushFrame;
}


// ========================================================================
// ?MetricsRecord@idMetricsFramework@@QAAXXZ
// EA  : 0x82F3CDB0
// RVA : 0x00F3CDB0
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

void __fastcall idMetricsFramework::MetricsRecord(idMetricsFramework *this)
{
  idMetricRecord v1; // [sp+50h] [-60h] BYREF

  this->isRecording = true;
  idMetricsFramework::MachineInfo::MachineInfo(this: (idMetricsFramework::MachineInfo *)&v1);
  idMetricRecord::Serialize(this: &v1);
  idMetricRecord::~idMetricRecord(this: &v1);
}


// ========================================================================
// __unwind$111927
// EA  : 0x82F3CDFC
// RVA : 0x00F3CDFC
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

void _unwind_111927()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(v0 - 176 + 80));
}


// ========================================================================
// ?OpenMetricFile@idMetricsFramework@@AAAXABVidStr@@AAVidMetricFile@@@Z
// EA  : 0x82F3CE30
// RVA : 0x00F3CE30
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

void __fastcall idMetricsFramework::OpenMetricFile(
        idMetricsFramework *this,
        const idStr *filename,
        __int64 newMetricFile,
        __int64 a4,
        __int64 a5)
{
  _DWORD *v6; // r30
  char v7; // r28
  __int64 v8; // r4
  __int64 v9; // r4
  int v10; // [sp+8h] [-D8h]
  int v11; // [sp+Ch] [-D4h]
  int v12; // [sp+10h] [-D0h]
  int v13; // [sp+14h] [-CCh]
  _DWORD v14[4]; // [sp+50h] [-90h] BYREF
  idStr v15; // [sp+60h] [-80h] BYREF
  idStr v16[3]; // [sp+80h] [-60h] BYREF

  v6 = (_DWORD *)HIDWORD(newMetricFile);
  if ( filename->len != 0 )
  {
    v7 = 1;
    LODWORD(a5) = (unsigned __int8)*metrics_server.valueString.data;
    if ( *metrics_server.valueString.data != 0 )
      *(_DWORD *)HIDWORD(newMetricFile) = idFile_Metrics::OpenMetricsStream(name: filename->data);
    if ( *v6 != 0 )
      goto LABEL_7;
    v7 = 0;
    operator+(result: &v15, a: "metrics/", b: filename);
    idStr::idStr(this: v16, text: &v15);
    v14[0] = 0;
    fileSystem->GetNumberedFilename(
      this: fileSystem,
      a2: v14,
      a3: v16[0].data,
      a4: idMetricsFramework::EXTENSION_TYPE,
      a5: &v15,
      a6: true);
    *v6 = fileSystem->OpenFileWrite(this: fileSystem, a2: v15.data, a3: 2);
    idStr::FreeData(this: v16);
    idStr::FreeData(this: &v15);
    LODWORD(a4) = *v6;
    if ( *v6 != 0 )
    {
LABEL_7:
      if ( v7 != 0 )
      {
        HIDWORD(newMetricFile) = metrics_server.valueString.data;
        HIDWORD(v9) = "METRIC: Opening metric stream %s on server IP: %s\n";
      }
      else
      {
        HIDWORD(v9) = "METRIC: Opening metric stream %s\n";
      }
      LODWORD(v9) = filename->data;
      idLib::Printf(fmt: v9, a2: newMetricFile, a3: a4, a4: a5, a5: v10, a6: v11, a7: v12, a8: v13);
    }
    else
    {
      LODWORD(v8) = filename->data;
      HIDWORD(v8) = "METRIC: Failed to open metric stream %s";
      idLib::Warning(fmt: v8, a2: newMetricFile, a3: a4, a4: a5, a5: v10, a6: v11, a7: v12, a8: v13);
    }
  }
}


// ========================================================================
// __unwind$111948
// EA  : 0x82F3CF68
// RVA : 0x00F3CF68
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

void _unwind_111948()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$111949
// EA  : 0x82F3CF90
// RVA : 0x00F3CF90
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

void _unwind_111949()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// ?WriteHeader@MachineInfo@idMetricsFramework@@UBAXPAVidMetricFile@@@Z
// EA  : 0x82F3CFB8
// RVA : 0x00F3CFB8
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

void __fastcall idMetricsFramework::MachineInfo::WriteHeader(
        idMetricsFramework::MachineInfo *this,
        idMetricFile *metricFile)
{
  unsigned __int64 v3; // r11
  idBitMsg v4; // [sp+50h] [-C0h] BYREF
  _BYTE v5[128]; // [sp+80h] [-90h] BYREF

  if ( metricFile->fileHandle != nullptr )
  {
    idMetricRecord::WriteHeader(this, metricFile);
    LODWORD(v3) = 0;
    HIDWORD(v3) = v5;
    memset(&v4.curSize, 0, 18);
    v4.writeData = v5;
    v4.readData = v5;
    v4.maxSize = 128;
    v4.tempValue = v3;
    idBitMsg::WriteString(this: &v4, s: "BuildInfo", maxLength: -1, make7Bit: true);
    idBitMsg::WriteBits(this: &v4, value: 6, numBits: 32);
    metricFile->fileHandle->Write(this: metricFile->fileHandle, a2: v4.writeData, a3: (v4.writeBit != 0) + v4.curSize);
  }
}


// ========================================================================
// ?SerializeEntry@MachineInfo@idMetricsFramework@@UBAXPAVidMetricFile@@@Z
// EA  : 0x82F3D080
// RVA : 0x00F3D080
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

void __fastcall idMetricsFramework::MachineInfo::SerializeEntry(
        idMetricsFramework::MachineInfo *this,
        idMetricFile *metricFile)
{
  unsigned __int64 v3; // r11
  idBitMsg v4; // [sp+50h] [-240h] BYREF
  _BYTE v5[512]; // [sp+80h] [-210h] BYREF

  if ( metricFile->fileHandle != nullptr )
  {
    idMetricRecord::SerializeEntry(this, metricFile);
    LODWORD(v3) = 0;
    HIDWORD(v3) = v5;
    memset(&v4.curSize, 0, 18);
    v4.writeData = v5;
    v4.readData = v5;
    v4.maxSize = 512;
    v4.tempValue = v3;
    idBitMsg::WriteString(this: &v4, s: com_version.valueString.data, maxLength: -1, make7Bit: true);
    metricFile->fileHandle->Write(this: metricFile->fileHandle, a2: v4.writeData, a3: (v4.writeBit != 0) + v4.curSize);
  }
}


// ========================================================================
// ?MetricsStop@idMetricsFramework@@QAAXXZ
// EA  : 0x82F3D420
// RVA : 0x00F3D420
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

void __fastcall idMetricsFramework::MetricsStop(idMetricsFramework *this)
{
  __int64 v2; // r8
  __int64 v3; // r6
  __int64 v4; // r4
  __int64 v5; // r10
  int i; // r28
  idMetricFile *Index; // r30
  int v8; // r3
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  int v12; // [sp+8h] [-98h]
  int v13; // [sp+8h] [-98h]
  int v14; // [sp+Ch] [-94h]
  int v15; // [sp+Ch] [-94h]
  int v16; // [sp+10h] [-90h]
  int v17; // [sp+10h] [-90h]
  int v18; // [sp+14h] [-8Ch]
  int v19; // [sp+14h] [-8Ch]

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  if ( this->isRecording )
  {
    HIDWORD(v5) = &unk_82390000;
    LODWORD(v5) = this->fileTable.numEntries;
    HIDWORD(v4) = "Closing metrics streams\n";
    LODWORD(v2) = v5 + this->baseHandle;
    this->baseHandle = v2;
    idLib::Printf(fmt: v4, a2: v3, a3: v2, a4: v5, a5: v12, a6: v14, a7: v16, a8: v18);
    for ( i = 0; i < this->fileTable.numEntries; ++i )
    {
      Index = idHashTableT<char const *,idMetricFile>::GetIndex(this: &this->fileTable, index: i);
      if ( Index->fileHandle != nullptr )
      {
        v8 = (int)Index->fileHandle->GetName(this: Index->fileHandle);
        idLib::Printf(
          fmt: __SPAIR64__("METRIC: Closing metric stream %s\n", v8),
          a2: v11,
          a3: v10,
          a4: v9,
          a5: v13,
          a6: v15,
          a7: v17,
          a8: v19);
        if ( Index->fileHandle != nullptr )
          ((void (__fastcall *)(idFile *, int))Index->fileHandle->dtr_idFile)(a1: Index->fileHandle, a2: 1);
        Index->fileHandle = nullptr;
      }
    }
    idHashTableT<char const *,idMetricFile>::Clear(this: &this->fileTable);
    this->isRecording = false;
  }
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$112284
// EA  : 0x82F3D520
// RVA : 0x00F3D520
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

void _unwind_112284()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetFileHandle@idMetricsFramework@@QAAPAVidMetricFile@@ABVidStr@@@Z
// EA  : 0x82F3D550
// RVA : 0x00F3D550
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

idMetricFile *__fastcall idMetricsFramework::GetFileHandle(idMetricsFramework *this, const idStr *filename)
{
  unsigned __int64 v4; // r28
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  idMetricFile *v9; // r30
  idMetricFile *v10; // [sp+50h] [-60h] BYREF
  const char *v11[3]; // [sp+54h] [-5Ch] BYREF
  idMetricFile v12[5]; // [sp+60h] [-50h] BYREF

  HIDWORD(v4) = &this->fileTable;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  LODWORD(v4) = 0;
  v11[0] = filename->data;
  v10 = nullptr;
  LODWORD(v5) = (unsigned __int8)idHashTableT<char const *,idMetricFile>::Get(
                                   this: &this->fileTable,
                                   key: v11,
                                   value: &v10);
  if ( (_DWORD)v5 != 0 )
  {
    v9 = v10;
  }
  else
  {
    v12[0].fileHandle = nullptr;
    HIDWORD(v7) = v12;
    v12[0].headerWritten = false;
    v12[0].startTime = v4;
    idMetricsFramework::OpenMetricFile(this, filename, newMetricFile: v7, a4: v6, a5: v5);
    if ( v12[0].fileHandle == nullptr )
    {
      idMem::PopHeap(this: &mem);
      return nullptr;
    }
    v11[0] = filename->data;
    v9 = idHashTableT<char const *,idMetricFile>::Set(this: &this->fileTable, key: v11, value: v12);
  }
  idMem::PopHeap(this: &mem);
  return v9;
}


// ========================================================================
// __unwind$112330
// EA  : 0x82F3D61C
// RVA : 0x00F3D61C
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

void _unwind_112330()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 176 + 112));
}


// ========================================================================
// ?MetricsRecord_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F3D648
// RVA : 0x00F3D648
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

void __fastcall MetricsRecord_f(const idCmdArgs *args)
{
  if ( metricsFrameworkLocal.isRecording )
    idMetricsFramework::MetricsStop(this: &metricsFrameworkLocal);
  idMetricsFramework::MetricsRecord(this: &metricsFrameworkLocal);
}


// ========================================================================
// ?MetricsStop_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F3D690
// RVA : 0x00F3D690
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

void __fastcall MetricsStop_f(const idCmdArgs *args)
{
  idMetricsFramework::MetricsStop(this: &metricsFrameworkLocal);
}


// ========================================================================
// ??1idMetricsFramework@@QAA@XZ
// EA  : 0x82F3D700
// RVA : 0x00F3D700
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

void __fastcall idMetricsFramework::~idMetricsFramework(idMetricsFramework *this)
{
  idMetricsFramework::MetricsStop(this);
  idHashTableT<char const *,idMetricFile>::Clear(this: &this->fileTable);
  idMem::Free(this: &mem, ptr: this->fileTable.heads, align: ALIGN_16);
  this->fileTable.heads = nullptr;
  this->fileTable.tableSize = 0;
  this->fileTable.tableSizeMask = 0;
  this->fileTable.numEntries = 0;
}


// ========================================================================
// __unwind$112426
// EA  : 0x82F3D76C
// RVA : 0x00F3D76C
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

void _unwind_112426()
{
  int v0; // r12

  idHashTable<idMetricFile>::~idHashTable<idMetricFile>(this: (idHashTable<idMetricFile> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                          + 36));
}


// ========================================================================
// ??0idMetricsFramework@@QAA@XZ
// EA  : 0x82F3D798
// RVA : 0x00F3D798
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

idMetricsFramework *__fastcall idMetricsFramework::idMetricsFramework(idMetricsFramework *this)
{
  unsigned __int64 v1; // r31
  void *v2; // r3

  HIDWORD(v1) = this;
  LODWORD(v1) = 0;
  this->currentPushTime = v1;
  this->currentWriteTime = v1;
  this->currentPushFrame = 0;
  this->lastCheckedPushFrame = 0;
  this->currentState = 0;
  this->baseHandle = 0;
  this->isRecording = false;
  this->fileTable.tableSize = 256;
  v2 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
         size: 0x400u,
         tag: TAG_HASHTABLE,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  *(_DWORD *)(HIDWORD(v1) + 36) = v2;
  memset(Dst: v2, Val: 0, Size: 0x400u);
  *(_QWORD *)(HIDWORD(v1) + 44) = 255;
  *(_DWORD *)(HIDWORD(v1) + 56) = 0;
  *(_BYTE *)(HIDWORD(v1) + 60) = 0;
  *(_QWORD *)(HIDWORD(v1) + 64) = v1;
  return (idMetricsFramework *)HIDWORD(v1);
}


// ========================================================================
// `dynamic initializer for 'metricsFrameworkLocal''
// EA  : 0x83395E38
// RVA : 0x01395E38
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__metricsFrameworkLocal__()
{
  idMetricsFramework::idMetricsFramework(this: &metricsFrameworkLocal);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__metricsFrameworkLocal__);
}


// ========================================================================
// `dynamic initializer for 'com_logHeartbeat''
// EA  : 0x83395E70
// RVA : 0x01395E70
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_logHeartbeat__()
{
  idCVar::idCVar(
    this: &com_logHeartbeat,
    name: "com_logHeartbeat",
    value: "250",
    flags: 2,
    description: "time between log saves to buffer",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_logHeartbeat__);
}


// ========================================================================
// `dynamic initializer for 'com_logWriteTime''
// EA  : 0x83395EC8
// RVA : 0x01395EC8
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_logWriteTime__()
{
  idCVar::idCVar(
    this: &com_logWriteTime,
    name: "com_logWriteTime",
    value: "1000",
    flags: 2,
    description: "time between log writes to fs_savepath",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_logWriteTime__);
}


// ========================================================================
// `dynamic initializer for 'MetricsRecord_v''
// EA  : 0x83395F20
// RVA : 0x01395F20
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__MetricsRecord_v__()
{
  return idCommandLink::idCommandLink(
           this: &MetricsRecord_v,
           cmdName: "MetricsRecord",
           function: MetricsRecord_f,
           description: "record performance metrics",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'MetricsStop_v''
// EA  : 0x83395F48
// RVA : 0x01395F48
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__MetricsStop_v__()
{
  return idCommandLink::idCommandLink(
           this: &MetricsStop_v,
           cmdName: "MetricsStop",
           function: MetricsStop_f,
           description: "stop performance metrics recording",
           argCompletion: nullptr);
}

