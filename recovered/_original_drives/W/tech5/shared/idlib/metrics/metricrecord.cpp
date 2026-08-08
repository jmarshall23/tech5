
// ========================================================================
// ??0idMetricRecord@@QAA@ABVidStr@@@Z
// EA  : 0x82F3C2C0
// RVA : 0x00F3C2C0
// PDB : w:\tech5\shared\idlib\metrics\metricrecord.cpp
// ========================================================================

idMetricRecord *__fastcall idMetricRecord::idMetricRecord(idMetricRecord *this, const idStr *_name)
{
  this->__vftable = (idMetricRecord_vtbl *)&idMetricRecord::`vftable';
  idStr::idStr(this: &this->name, text: _name);
  idStr::idStr(this: &this->baseName, text: _name);
  return this;
}


// ========================================================================
// __unwind$111148
// EA  : 0x82F3C308
// RVA : 0x00F3C308
// PDB : w:\tech5\shared\idlib\metrics\metricrecord.cpp
// ========================================================================

void _unwind_111148()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ?WriteHeader@idMetricRecord@@MBAXPAVidMetricFile@@@Z
// EA  : 0x82F3C338
// RVA : 0x00F3C338
// PDB : w:\tech5\shared\idlib\metrics\metricrecord.cpp
// ========================================================================

void __fastcall idMetricRecord::WriteHeader(idMetricRecord *this, idMetricFile *metricFile)
{
  unsigned __int64 v2; // r11
  idBitMsg v4; // [sp+50h] [-140h] BYREF
  _BYTE v5[256]; // [sp+80h] [-110h] BYREF

  LODWORD(v2) = 0;
  HIDWORD(v2) = v5;
  memset(&v4.curSize, 0, 18);
  v4.writeData = v5;
  v4.readData = v5;
  v4.maxSize = 256;
  v4.tempValue = v2;
  idBitMsg::WriteBits(this: &v4, value: 1, numBits: 32);
  idBitMsg::WriteString(this: &v4, s: "entryTime", maxLength: -1, make7Bit: true);
  idBitMsg::WriteBits(this: &v4, value: 0, numBits: 32);
  metricFile->fileHandle->Write(this: metricFile->fileHandle, a2: v4.writeData, a3: (v4.writeBit != 0) + v4.curSize);
}


// ========================================================================
// ?SerializeEntry@idMetricRecord@@MBAXPAVidMetricFile@@@Z
// EA  : 0x82F3C400
// RVA : 0x00F3C400
// PDB : w:\tech5\shared\idlib\metrics\metricrecord.cpp
// ========================================================================

void __fastcall idMetricRecord::SerializeEntry(idMetricRecord *this, idMetricFile *metricFile)
{
  unsigned __int64 v2; // r11
  int v4; // r3
  _BYTE v5[16]; // [sp+50h] [-50h] BYREF
  idBitMsg v6; // [sp+60h] [-40h] BYREF

  LODWORD(v2) = 0;
  HIDWORD(v2) = v5;
  memset(&v6.curSize, 0, 18);
  v6.writeData = v5;
  v6.readData = v5;
  v6.maxSize = 8;
  v6.tempValue = v2;
  v4 = idMetricsFramework::GetCurrentSystemTime(this: &metricsFrameworkLocal) >> 32;
  idBitMsg::WriteBits(this: &v6, value: v4 - LODWORD(metricFile->startTime), numBits: 32);
  metricFile->fileHandle->Write(this: metricFile->fileHandle, a2: v6.writeData, a3: (v6.writeBit != 0) + v6.curSize);
}


// ========================================================================
// ?AppendToName@idMetricRecord@@QAAXABVidStr@@@Z
// EA  : 0x82F3C4C0
// RVA : 0x00F3C4C0
// PDB : w:\tech5\shared\idlib\metrics\metricrecord.cpp
// ========================================================================

void __fastcall idMetricRecord::AppendToName(idMetricRecord *this, const idStr *_name)
{
  idStr *v4; // r27
  size_t len; // r29
  idStr v6[2]; // [sp+50h] [-50h] BYREF

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v4 = operator+(result: v6, a: &this->baseName, b: _name);
  len = v4->len;
  idStr::EnsureAlloced(this: &this->name, amount: v4->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->name.data, Src: v4->data, Size: len);
  this->name.data[len] = 0;
  this->name.len = len;
  idStr::FreeData(this: v6);
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$111255
// EA  : 0x82F3C550
// RVA : 0x00F3C550
// PDB : w:\tech5\shared\idlib\metrics\metricrecord.cpp
// ========================================================================

void _unwind_111255()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?WriteFileInfo@idMetricFile@@QAAXABVidStr@@@Z
// EA  : 0x82F3C578
// RVA : 0x00F3C578
// PDB : w:\tech5\shared\idlib\metrics\metricrecord.cpp
// ========================================================================

void __fastcall idMetricFile::WriteFileInfo(idMetricFile *this, const idStr *metricName)
{
  unsigned __int64 v2; // r11
  unsigned __int64 v5; // r3
  unsigned __int64 startTime; // r30
  idBitMsg v7; // [sp+50h] [-150h] BYREF
  _BYTE v8[264]; // [sp+80h] [-120h] BYREF

  LODWORD(v2) = 0;
  HIDWORD(v2) = v8;
  memset(&v7.curSize, 0, 18);
  v7.writeData = v8;
  v7.readData = v8;
  v7.maxSize = 256;
  v7.tempValue = v2;
  LODWORD(v5) = idMetricsFramework::GetCurrentSystemTime(this: &metricsFrameworkLocal) >> 32;
  this->startTime = v5;
  idBitMsg::WriteString(this: &v7, s: idMetricsFramework::METRIC_ID, maxLength: -1, make7Bit: true);
  idBitMsg::WriteBits(this: &v7, value: 1, numBits: 32);
  idBitMsg::WriteString(this: &v7, s: metricName->data, maxLength: -1, make7Bit: true);
  startTime = this->startTime;
  idBitMsg::WriteBits(this: &v7, value: this->startTime, numBits: 32);
  idBitMsg::WriteBits(this: &v7, value: SHIDWORD(startTime), numBits: 32);
  this->fileHandle->Write(this: this->fileHandle, a2: v7.writeData, a3: (v7.writeBit != 0) + v7.curSize);
}


// ========================================================================
// ?Serialize@idMetricRecord@@QAAXXZ
// EA  : 0x82F3C688
// RVA : 0x00F3C688
// PDB : w:\tech5\shared\idlib\metrics\metricrecord.cpp
// ========================================================================

void __fastcall idMetricRecord::Serialize(idMetricRecord *this)
{
  idMetricFile *FileHandle; // r3
  idMetricFile *v3; // r31

  if ( metricsFrameworkLocal.isRecording )
  {
    FileHandle = idMetricsFramework::GetFileHandle(this: &metricsFrameworkLocal, filename: &this->name);
    v3 = FileHandle;
    if ( FileHandle != nullptr && FileHandle->fileHandle != nullptr )
    {
      if ( !FileHandle->headerWritten )
      {
        FileHandle->headerWritten = true;
        idMetricFile::WriteFileInfo(this: FileHandle, metricName: &this->name);
        this->WriteHeader(this, a2: v3);
      }
      this->SerializeEntry(this, a2: v3);
    }
  }
}

