
// ========================================================================
// ?CheckPushState@idGaugeMetric@@QAA_NXZ
// EA  : 0x82F3C728
// RVA : 0x00F3C728
// PDB : w:\tech5\shared\idlib\metrics\metrics.cpp
// ========================================================================

int __fastcall idGaugeMetric::CheckPushState(idGaugeMetric *this)
{
  int PushFrame; // r30

  PushFrame = idMetricsFramework::GetPushFrame(this: &metricsFrameworkLocal);
  if ( PushFrame <= this->lastPushFrame || this->count == 0 )
    return 0;
  idMetricRecord::Serialize(this);
  this->lastPushFrame = PushFrame;
  this->count = 0;
  this->min = 0.0;
  this->max = 0.0;
  this->mean = 0.0;
  this->mean2 = 0.0;
  this->m2 = 0.0;
  return 1;
}


// ========================================================================
// ??0idGaugeMetric@@QAA@ABVidStr@@0@Z
// EA  : 0x82F3C7C0
// RVA : 0x00F3C7C0
// PDB : w:\tech5\shared\idlib\metrics\metrics.cpp
// ========================================================================

idGaugeMetric *__fastcall idGaugeMetric::idGaugeMetric(
        idGaugeMetric *this,
        const idStr *_shortName,
        const idStr *_description)
{
  idMetricRecord::idMetricRecord(this, _name: _shortName);
  this->handle = -1;
  this->lastPushFrame = 0;
  this->min = 0.0;
  this->__vftable = (idGaugeMetric_vtbl *)&idGaugeMetric::`vftable';
  this->max = 0.0;
  this->gameState = -1;
  this->mean = 0.0;
  this->count = 0;
  this->mean2 = 0.0;
  this->m2 = 0.0;
  return this;
}


// ========================================================================
// ?Log@idGaugeMetric@@QAAXM_N@Z
// EA  : 0x82F3C830
// RVA : 0x00F3C830
// PDB : w:\tech5\shared\idlib\metrics\metrics.cpp
// ========================================================================

void __fastcall idGaugeMetric::Log(idGaugeMetric *this, double x, bool skipPush, unsigned __int8 a4)
{
  int count; // r11
  double mean; // fp0
  double v6; // fp13
  double m2; // fp12
  __int64 v8; // r10

  count = this->count;
  if ( count == 0 )
  {
    this->max = x;
LABEL_6:
    this->min = x;
    goto LABEL_7;
  }
  if ( x > this->max )
    this->max = x;
  if ( x < this->min )
    goto LABEL_6;
LABEL_7:
  mean = this->mean;
  v6 = (float)((float)x - this->mean);
  m2 = this->m2;
  LODWORD(v8) = count + 1;
  HIDWORD(v8) = a4;
  this->mean2 = (float)((float)x * (float)x) + this->mean2;
  this->count = count + 1;
  this->mean = (float)((float)v6 / (float)v8) + (float)mean;
  this->m2 = (float)((float)((float)x - (float)((float)((float)v6 / (float)v8) + (float)mean)) * (float)v6) + (float)m2;
  if ( a4 == 0 )
    idGaugeMetric::CheckPushState(this);
}


// ========================================================================
// ?WriteHeader@idGaugeMetric@@MBAXPAVidMetricFile@@@Z
// EA  : 0x82F3C8E0
// RVA : 0x00F3C8E0
// PDB : w:\tech5\shared\idlib\metrics\metrics.cpp
// ========================================================================

void __fastcall idGaugeMetric::WriteHeader(idGaugeMetric *this, idMetricFile *metricFile)
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
    idBitMsg::WriteBits(this: &v4, value: 5, numBits: 32);
    idBitMsg::WriteString(this: &v4, s: "count", maxLength: -1, make7Bit: true);
    idBitMsg::WriteBits(this: &v4, value: 0, numBits: 32);
    idBitMsg::WriteString(this: &v4, s: "min", maxLength: -1, make7Bit: true);
    idBitMsg::WriteBits(this: &v4, value: 1, numBits: 32);
    idBitMsg::WriteString(this: &v4, s: "max", maxLength: -1, make7Bit: true);
    idBitMsg::WriteBits(this: &v4, value: 1, numBits: 32);
    idBitMsg::WriteString(this: &v4, s: "mean", maxLength: -1, make7Bit: true);
    idBitMsg::WriteBits(this: &v4, value: 1, numBits: 32);
    idBitMsg::WriteString(this: &v4, s: "stdDev", maxLength: -1, make7Bit: true);
    idBitMsg::WriteBits(this: &v4, value: 1, numBits: 32);
    metricFile->fileHandle->Write(this: metricFile->fileHandle, a2: v4.writeData, a3: (v4.writeBit != 0) + v4.curSize);
  }
}


// ========================================================================
// ?SerializeEntry@idGaugeMetric@@MBAXPAVidMetricFile@@@Z
// EA  : 0x82F3CA58
// RVA : 0x00F3CA58
// PDB : w:\tech5\shared\idlib\metrics\metrics.cpp
// ========================================================================

void __fastcall idGaugeMetric::SerializeEntry(idGaugeMetric *this, idMetricFile *metricFile)
{
  int count; // r4
  unsigned __int64 v5; // r11
  double mean2; // fp0
  __int64 v7; // r7
  double v8; // fp31
  int v9; // [sp+50h] [-E0h]
  idBitMsg v10; // [sp+60h] [-D0h] BYREF
  _BYTE v11[128]; // [sp+90h] [-A0h] BYREF

  if ( metricFile->fileHandle != nullptr )
  {
    idMetricRecord::SerializeEntry(this, metricFile);
    count = this->count;
    LODWORD(v5) = 0;
    mean2 = this->mean2;
    LODWORD(v7) = count;
    HIDWORD(v5) = v11;
    memset(&v10.curSize, 0, 18);
    v10.writeData = v11;
    v10.readData = v11;
    v10.maxSize = 128;
    v10.tempValue = v5;
    v8 = __fsqrts((float)((float)mean2 / (float)v7));
    idBitMsg::WriteBits(this: &v10, value: count, numBits: 32);
    idBitMsg::WriteBits(this: &v10, value: COERCE_INT(this->min), numBits: 32);
    idBitMsg::WriteBits(this: &v10, value: COERCE_INT(this->max), numBits: 32);
    idBitMsg::WriteBits(this: &v10, value: COERCE_INT(this->mean), numBits: 32);
    *(float *)&v9 = v8;
    idBitMsg::WriteBits(this: &v10, value: v9, numBits: 32);
    metricFile->fileHandle->Write(
      this: metricFile->fileHandle,
      a2: v10.writeData,
      a3: (v10.writeBit != 0) + v10.curSize);
  }
}

