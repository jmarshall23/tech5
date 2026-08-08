
// ========================================================================
// ?WriteToMsg@idInnerPacketHeader@idPacketProcessor@@QAAXAAVidBitMsg@@@Z
// EA  : 0x8289B2D0
// RVA : 0x0089B2D0
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void __fastcall idPacketProcessor::idInnerPacketHeader::WriteToMsg(
        idPacketProcessor::idInnerPacketHeader *this,
        idBitMsg *msg)
{
  idBitMsg::WriteBits(this: msg, value: this->type, numBits: 2);
  idBitMsg::WriteBits(this: msg, value: this->userData, numBits: 6);
}


// ========================================================================
// ?ReadFromMsg@idInnerPacketHeader@idPacketProcessor@@QAAXAAVidBitMsg@@@Z
// EA  : 0x8289B328
// RVA : 0x0089B328
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void __fastcall idPacketProcessor::idInnerPacketHeader::ReadFromMsg(
        idPacketProcessor::idInnerPacketHeader *this,
        idBitMsg *msg)
{
  this->type = idBitMsg::ReadBits(this: msg, numBits: 2);
  this->userData = idBitMsg::ReadBits(this: msg, numBits: 6);
}


// ========================================================================
// ?Reset@idPacketProcessor@@QAAXXZ
// EA  : 0x829ABDF0
// RVA : 0x009ABDF0
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void __fastcall idPacketProcessor::Reset(idPacketProcessor *this)
{
  __int64 v1; // r30
  _QWORD *v2; // r10
  int v3; // ctr
  _QWORD *v4; // r11
  _QWORD v5[4]; // [sp+48h] [-22D8h] BYREF
  int v6; // [sp+68h] [-22B8h]
  __int16 v7; // [sp+6Ch] [-22B4h]
  __int64 v8; // [sp+70h] [-22B0h]
  idList<idVehicleState *,5> v9; // [sp+80h] [-22A0h] BYREF
  _DWORD v10[1188]; // [sp+90h] [-2290h] BYREF

  LODWORD(v1) = 0;
  this->msgWritePos = 0;
  this->fragmentSequence = 0;
  this->droppedFrags = 0;
  HIDWORD(v1) = this;
  this->fragmentedSend = false;
  *(_QWORD *)&v9.num = 63;
  v9.list = (idVehicleState **)v10;
  *(_DWORD *)&v9.granularity = 66817;
  v10[189] = 0;
  idDataQueue<63,8000>::operator=(this: &this->reliable, __that: (const idList<navSplineSegment_t,5> *)&v9);
  idList<idThread *,58>::Clear(this: &v9);
  *(_DWORD *)(HIDWORD(v1) + 16792) = 1;
  *(_QWORD *)(HIDWORD(v1) + 16796) = 0;
  v2 = (_QWORD *)(HIDWORD(v1) + 25304);
  *(_DWORD *)(HIDWORD(v1) + 25308) = -1;
  v3 = 5;
  memset(&v5[1], 0, 24);
  v4 = v5;
  v6 = 0;
  v7 = 0;
  v8 = v1;
  do
  {
    *++v2 = *++v4;
    --v3;
  }
  while ( v3 != 0 );
  *(_QWORD *)(HIDWORD(v1) + 33352) = 0;
  *(float *)(HIDWORD(v1) + 33360) = 0.0;
  *(_DWORD *)(HIDWORD(v1) + 33364) = 0;
  *(float *)(HIDWORD(v1) + 33368) = 0.0;
  *(_QWORD *)(HIDWORD(v1) + 33372) = 0;
  *(_QWORD *)(HIDWORD(v1) + 33380) = 0;
  *(_QWORD *)(HIDWORD(v1) + 33388) = 0;
  *(_QWORD *)(HIDWORD(v1) + 33396) = 0;
  *(_DWORD *)(HIDWORD(v1) + 34028) = 0;
}


// ========================================================================
// __unwind$232837
// EA  : 0x829ABF74
// RVA : 0x009ABF74
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_232837()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 8992 + 128));
}


// ========================================================================
// ??0idPacketProcessor@@QAA@XZ
// EA  : 0x829AC218
// RVA : 0x009AC218
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

idPacketProcessor *__fastcall idPacketProcessor::idPacketProcessor(idPacketProcessor *this)
{
  unsigned __int64 v1; // r11
  idStr v4; // [sp+60h] [-1A0h] BYREF
  idStr v5; // [sp+80h] [-180h] BYREF
  idStr v6; // [sp+A0h] [-160h] BYREF
  idStr v7; // [sp+C0h] [-140h] BYREF
  idStr v8; // [sp+E0h] [-120h] BYREF
  idStr v9; // [sp+100h] [-100h] BYREF
  idStr v10; // [sp+120h] [-E0h] BYREF
  idStr v11; // [sp+140h] [-C0h] BYREF
  idStr v12; // [sp+160h] [-A0h] BYREF
  idStr v13; // [sp+180h] [-80h] BYREF
  idStr v14; // [sp+1A0h] [-60h] BYREF
  idStr v15; // [sp+1C0h] [-40h] BYREF

  LODWORD(v1) = 0;
  this->reliable.items.num = 0;
  this->reliable.items.granularity = 1;
  this->reliable.items.size = 63;
  this->reliable.items.memTag = 5;
  this->reliable.items.list = this->reliable.items.staticList;
  this->reliable.items.listStatic = 1;
  this->reliable.dataLength = 0;
  this->unsentMsg.writeData = nullptr;
  this->unsentMsg.readData = nullptr;
  this->unsentMsg.maxSize = 0;
  HIDWORD(v1) = &this->unsentMsg;
  this->unsentMsg.curSize = 0;
  this->unsentMsg.writeBit = 0;
  this->unsentMsg.readCount = 0;
  this->unsentMsg.readBit = 0;
  this->unsentMsg.allowOverflow = false;
  this->unsentMsg.overflowed = false;
  this->unsentMsg.tempValue = v1;
  idStr::idStr(this: &v6, text: "size of outgoing packets");
  idStr::idStr(this: &v10, text: "outgoingPacketSize");
  idGaugeMetric::idGaugeMetric(this: &this->outgoingPacketSize, _shortName: &v10, _description: &v6);
  idStr::FreeData(this: &v10);
  idStr::FreeData(this: &v6);
  idStr::idStr(this: &v8, text: "size of incoming packets");
  idStr::idStr(this: &v14, text: "incomingPacketSize");
  idGaugeMetric::idGaugeMetric(this: &this->incomingPacketSize, _shortName: &v14, _description: &v8);
  idStr::FreeData(this: &v14);
  idStr::FreeData(this: &v8);
  idStr::idStr(this: &v4, text: "size of handled reliable msgs");
  idStr::idStr(this: &v12, text: "handledReliableSize");
  idGaugeMetric::idGaugeMetric(this: &this->handledReliableMsgSize, _shortName: &v12, _description: &v4);
  idStr::FreeData(this: &v12);
  idStr::FreeData(this: &v4);
  idStr::idStr(this: &v7, text: "size of queued reliable msgs");
  idStr::idStr(this: &v5, text: "queuedReliableSize");
  idGaugeMetric::idGaugeMetric(this: &this->queuedReliableMsgSize, _shortName: &v5, _description: &v7);
  idStr::FreeData(this: &v5);
  idStr::FreeData(this: &v7);
  idStr::idStr(this: &v11, text: "size of fragmented packets");
  idStr::idStr(this: &v9, text: "fragmentedPacketSize");
  idGaugeMetric::idGaugeMetric(this: &this->fragmentedPacketSize, _shortName: &v9, _description: &v11);
  idStr::FreeData(this: &v9);
  idStr::FreeData(this: &v11);
  idStr::idStr(this: &v15, text: "size of sent snapshots");
  idStr::idStr(this: &v13, text: "sentSnapShotSize");
  idGaugeMetric::idGaugeMetric(this: &this->sentSnapShotSize, _shortName: &v13, _description: &v15);
  idStr::FreeData(this: &v13);
  idStr::FreeData(this: &v15);
  idPacketProcessor::Reset(this);
  return this;
}


// ========================================================================
// __unwind$232994
// EA  : 0x829AC458
// RVA : 0x009AC458
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_232994()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 512 + 532) + 8016));
}


// ========================================================================
// __unwind$232995
// EA  : 0x829AC484
// RVA : 0x009AC484
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_232995()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 160));
}


// ========================================================================
// __unwind$232996_0
// EA  : 0x829AC4AC
// RVA : 0x009AC4AC
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_232996_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 288));
}


// ========================================================================
// __unwind$232997
// EA  : 0x829AC4D4
// RVA : 0x009AC4D4
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_232997()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 512 + 532) + 33404));
}


// ========================================================================
// __unwind$232998
// EA  : 0x829AC508
// RVA : 0x009AC508
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_232998()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 224));
}


// ========================================================================
// __unwind$232999
// EA  : 0x829AC530
// RVA : 0x009AC530
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_232999()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 416));
}


// ========================================================================
// __unwind$233000
// EA  : 0x829AC558
// RVA : 0x009AC558
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_233000()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 512 + 532) + 33508));
}


// ========================================================================
// __unwind$233001
// EA  : 0x829AC58C
// RVA : 0x009AC58C
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_233001()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 96));
}


// ========================================================================
// __unwind$233002
// EA  : 0x829AC5B4
// RVA : 0x009AC5B4
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_233002()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 352));
}


// ========================================================================
// __unwind$233003
// EA  : 0x829AC5DC
// RVA : 0x009AC5DC
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_233003()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 512 + 532) + 33612));
}


// ========================================================================
// __unwind$233004
// EA  : 0x829AC610
// RVA : 0x009AC610
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_233004()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 192));
}


// ========================================================================
// __unwind$233005
// EA  : 0x829AC638
// RVA : 0x009AC638
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_233005()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 128));
}


// ========================================================================
// __unwind$233006
// EA  : 0x829AC660
// RVA : 0x009AC660
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_233006()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 512 + 532) + 33716));
}


// ========================================================================
// __unwind$233007
// EA  : 0x829AC694
// RVA : 0x009AC694
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_233007()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 320));
}


// ========================================================================
// __unwind$233008
// EA  : 0x829AC6BC
// RVA : 0x009AC6BC
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_233008()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 256));
}


// ========================================================================
// __unwind$233009
// EA  : 0x829AC6E4
// RVA : 0x009AC6E4
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_233009()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 512 + 532) + 33820));
}


// ========================================================================
// __unwind$233010
// EA  : 0x829AC718
// RVA : 0x009AC718
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_233010()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 448));
}


// ========================================================================
// __unwind$233011
// EA  : 0x829AC740
// RVA : 0x009AC740
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_233011()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 384));
}


// ========================================================================
// __unwind$233012
// EA  : 0x829AC768
// RVA : 0x009AC768
// PDB : w:\tech5\engine\network\packetprocessor.h
// ========================================================================

void _unwind_233012()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 512 + 532) + 33924));
}

