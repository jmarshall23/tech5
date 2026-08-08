
// ========================================================================
// ?TrySetPendingSnapshot@idSnapshotProcessor@@QAA_NAAVidSnapShot@@@Z
// EA  : 0x828A1A98
// RVA : 0x008A1A98
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

int __fastcall idSnapshotProcessor::TrySetPendingSnapshot(idSnapshotProcessor *this, idSnapShot *ss)
{
  bool *p_hasPendingSnap; // r31

  p_hasPendingSnap = &this->hasPendingSnap;
  if ( this->hasPendingSnap )
    return 0;
  idSnapShot::operator=(this: &this->pendingSnap, other: ss);
  *p_hasPendingSnap = true;
  return 1;
}


// ========================================================================
// ?IsBusyConfirmingPartialSnap@idSnapshotProcessor@@QAA_NXZ
// EA  : 0x828A1B00
// RVA : 0x008A1B00
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

int __fastcall idSnapshotProcessor::IsBusyConfirmingPartialSnap(idSnapshotProcessor *this)
{
  int partialBaseSequence; // r11
  int baseSequence; // r10
  int result; // r3

  partialBaseSequence = this->partialBaseSequence;
  if ( partialBaseSequence == -1 )
    return 0;
  baseSequence = this->baseSequence;
  result = 1;
  if ( baseSequence > partialBaseSequence )
    return 0;
  return result;
}


// ========================================================================
// ?SubmitPendingSnap@idSnapshotProcessor@@QAAXHPAEHPAUlzwCompressionData_t@@PAVidParallelJobList@@@Z
// EA  : 0x828A1B30
// RVA : 0x008A1B30
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void __fastcall idSnapshotProcessor::SubmitPendingSnap(
        idSnapshotProcessor *this,
        int visIndex,
        unsigned __int8 *objMemory,
        int objMemorySize,
        lzwCompressionData_t *lzwData,
        idParallelJobList *snapshotJobList)
{
  idSnapshotProcessor::jobMemory_t **p_jobMemory; // r27
  idSnapShot *p_submittedState; // r26
  idSnapshotProcessor::jobMemory_t *jobMemory; // r9
  int baseSequence; // r9
  lzwInOutData_t *p_lzwInOutData; // r8
  idSnapShot::submitDeltaJobsInfo_t v14; // [sp+50h] [-80h] BYREF

  p_jobMemory = &this->jobMemory;
  this->jobMemory->lzwInOutData.lzwDeltas = this->jobMemory->lzwDeltas.ptr;
  this->jobMemory->lzwInOutData.maxlzwDeltas = 1;
  this->jobMemory->lzwInOutData.lzwMem = this->jobMemory->lzwMem.ptr;
  this->jobMemory->lzwInOutData.maxlzwMem = 0x2000;
  this->jobMemory->lzwInOutData.lzwDmaOut = 0x2000;
  this->jobMemory->lzwInOutData.numlzwDeltas = 0;
  this->jobMemory->lzwInOutData.lzwBytes = 0;
  this->jobMemory->lzwInOutData.optimalLength = net_optimalSnapDeltaSize.valueInteger;
  this->jobMemory->lzwInOutData.snapSequence = this->snapSequence;
  this->jobMemory->lzwInOutData.lastObjId = 0;
  p_submittedState = &this->submittedState;
  this->jobMemory->lzwInOutData.lzwData = lzwData;
  jobMemory = this->jobMemory;
  v14.maxObjParms = 4096;
  v14.maxHeaders = 256;
  v14.objMemory = objMemory;
  v14.objParms = (objParms_t *)jobMemory;
  v14.headers = jobMemory->headers.ptr;
  v14.maxObjMemory = objMemorySize;
  v14.lzwParms = jobMemory->lzwParms.ptr;
  v14.maxDeltaParms = 32;
  idSnapShot::operator=(this: &this->submittedState, other: &this->baseState);
  idSnapShot::operator=(this: &this->submittedTemplateStates, other: &this->templateStates);
  baseSequence = this->baseSequence;
  p_lzwInOutData = &(*p_jobMemory)->lzwInOutData;
  v14.templateStates = &this->submittedTemplateStates;
  v14.oldSnap = p_submittedState;
  v14.visIndex = visIndex;
  v14.snapshotJobList = snapshotJobList;
  v14.lzwInOutData = p_lzwInOutData;
  v14.baseSequence = baseSequence;
  idSnapShot::SubmitWriteDeltaToJobs(this: &this->pendingSnap, submitDeltaJobInfo: &v14);
}


// ========================================================================
// ?SetDeltaSerializerLog@idSnapshotProcessor@@AAAXHPAVidSerializerLog@@@Z
// EA  : 0x828A1CD0
// RVA : 0x008A1CD0
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void __fastcall idSnapshotProcessor::SetDeltaSerializerLog(idSnapshotProcessor *this, int seq, idSerializerLog *log)
{
  int v5; // r31
  idSerializerLog *v6; // r3

  v5 = 4 * (seq % 64 + 16597);
  v6 = *(idSerializerLog **)((char *)&this->snapSequence + v5);
  if ( v6 != nullptr )
  {
    idSerializerLog::Release(this: v6);
    *(int *)((char *)&this->snapSequence + v5) = 0;
  }
  if ( log != nullptr )
  {
    idSerializerLog::AddRef(this: log);
    *(int *)((char *)&this->snapSequence + v5) = (int)log;
  }
}


// ========================================================================
// ?RemoveDeltasForOldBaseSequence@idSnapshotProcessor@@QAAXXZ
// EA  : 0x828A1E78
// RVA : 0x008A1E78
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void __fastcall idSnapshotProcessor::RemoveDeltasForOldBaseSequence(
        idSnapshotProcessor *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int baseSequence)
{
  int v8; // r27
  idDataQueue<64,65536> *p_deltas; // r31
  int i; // r30
  int v11; // [sp+8h] [-88h]
  int v12; // [sp+Ch] [-84h]
  int v13; // [sp+10h] [-80h]
  int v14; // [sp+14h] [-7Ch]
  int v15; // [sp+18h] [-78h]
  int v16; // [sp+1Ch] [-74h]
  int v17; // [sp+20h] [-70h]
  int v18; // [sp+24h] [-6Ch]
  int v19; // [sp+28h] [-68h]
  int v20; // [sp+2Ch] [-64h]
  int v21; // [sp+30h] [-60h]
  int v22; // [sp+34h] [-5Ch]
  int v23; // [sp+38h] [-58h]
  int v24; // [sp+3Ch] [-54h]
  int v25; // [sp+40h] [-50h]
  int v26; // [sp+44h] [-4Ch]
  int v27; // [sp+48h] [-48h]
  int v28; // [sp+4Ch] [-44h]
  int v29; // [sp+50h] [-40h] BYREF
  int v30; // [sp+54h] [-3Ch] BYREF

  v8 = this->deltas.items.num - 1;
  if ( v8 >= 0 )
  {
    p_deltas = &this->deltas;
    for ( i = v8; ; --i )
    {
      v30 = 0;
      idSnapShot::PeekDeltaSequence(
        deltaMem: (const char *)&p_deltas->data[p_deltas->items.list[i].dataOffset],
        deltaSize: p_deltas->items.list[i].length,
        sequence: &v30,
        baseSequence: &v29,
        a5,
        a6,
        a7: baseSequence,
        a8: (int)&p_deltas->items.list[i],
        a9: v11,
        a10: v12,
        a11: v13,
        a12: v14,
        a13: v15,
        a14: v16,
        a15: v17,
        a16: v18,
        a17: v19,
        a18: v20,
        a19: v21,
        a20: v22,
        a21: v23,
        a22: v24,
        a23: v25,
        a24: v26,
        a25: v27,
        a26: v28,
        a27: 0);
      baseSequence = this->baseSequence;
      a6 = v29;
      if ( v29 < baseSequence )
        break;
      if ( --v8 < 0 )
        return;
    }
    idDataQueue<64,65536>::RemoveOlderThan(this: p_deltas, sequence: p_deltas->items.list[v8].sequence + 1);
  }
}


// ========================================================================
// ?SanityCheckDeltas@idSnapshotProcessor@@QAAXXZ
// EA  : 0x828A1F28
// RVA : 0x008A1F28
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void __fastcall idSnapshotProcessor::SanityCheckDeltas(
        idSnapshotProcessor *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6)
{
  int num; // r11
  int v7; // r31
  int v9; // r29
  idDataQueue<64,65536> *p_deltas; // r30
  int v11; // [sp+8h] [-78h]
  int v12; // [sp+Ch] [-74h]
  int v13; // [sp+10h] [-70h]
  int v14; // [sp+14h] [-6Ch]
  int v15; // [sp+18h] [-68h]
  int v16; // [sp+1Ch] [-64h]
  int v17; // [sp+20h] [-60h]
  int v18; // [sp+24h] [-5Ch]
  int v19; // [sp+28h] [-58h]
  int v20; // [sp+2Ch] [-54h]
  int v21; // [sp+30h] [-50h]
  int v22; // [sp+34h] [-4Ch]
  int v23; // [sp+38h] [-48h]
  int v24; // [sp+3Ch] [-44h]
  int v25; // [sp+40h] [-40h]
  int v26; // [sp+44h] [-3Ch]
  int v27; // [sp+48h] [-38h]
  int v28; // [sp+4Ch] [-34h]
  int v29; // [sp+50h] [-30h] BYREF
  int v30; // [sp+54h] [-2Ch] BYREF

  num = this->deltas.items.num;
  v7 = 0;
  v30 = 0;
  v9 = 0;
  v29 = 0;
  if ( num > 0 )
  {
    p_deltas = &this->deltas;
    do
    {
      idSnapShot::PeekDeltaSequence(
        deltaMem: (const char *)&p_deltas->data[p_deltas->items.list[v7].dataOffset],
        deltaSize: p_deltas->items.list[v7].length,
        sequence: &v30,
        baseSequence: &v29,
        a5,
        a6,
        a7: (int)&p_deltas->items.list[v7],
        a8: (int)&p_deltas->items.list[v7],
        a9: v11,
        a10: v12,
        a11: v13,
        a12: v14,
        a13: v15,
        a14: v16,
        a15: v17,
        a16: v18,
        a17: v19,
        a18: v20,
        a19: v21,
        a20: v22,
        a21: v23,
        a22: v24,
        a23: v25,
        a24: v26,
        a25: v27,
        a26: v28,
        a27: v29);
      a6 = this->deltas.items.num;
      ++v9;
      ++v7;
    }
    while ( v9 < a6 );
  }
}


// ========================================================================
// ?AddSnapObjTemplate@idSnapshotProcessor@@QAAXHAAVidBitMsg@@@Z
// EA  : 0x828A1FA0
// RVA : 0x008A1FA0
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void __fastcall idSnapshotProcessor::AddSnapObjTemplate(idSnapshotProcessor *this, int objID, idBitMsg *msg)
{
  idSnapShot::objectState_t *v5; // r3
  idSnapShot::objectState_t *v6; // r31
  __int64 v7; // r8
  int v8; // r6
  int v9; // r5

  v5 = idSnapShot::S_AddObject(
         this: &this->templateStates,
         objectNum: objID,
         visMask: 0xFFFFFFFF,
         data: (const char *)msg->readData,
         _size: (msg->writeBit != 0) + msg->curSize,
         tag: nullptr);
  v6 = v5;
  if ( v5 != nullptr )
  {
    if ( net_ssTemplateDebug.valueInteger != 0 )
    {
      idLib::PrintfIf(condition: true, fmt: "InjectingSnapObjBaseState[%d] size: %d\n", objID, v5->buffer.size);
      idSnapShot::objectState_t::Print(this: v6, name: "BASE STATE", a3: v9, a4: v8, a5: v7);
    }
    v6->expectedSequence = this->snapSequence;
  }
}


// ========================================================================
// ?Reset@idSnapshotProcessor@@QAAX_N@Z
// EA  : 0x828A2040
// RVA : 0x008A2040
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void __fastcall idSnapshotProcessor::Reset(idSnapshotProcessor *this, bool cstor)
{
  BOOL v2; // r29
  int v4; // r29
  idArray<idSerializerLog *,64> *p_deltaLogs; // r30
  idSnapshotProcessor::jobMemory_t *jobMemory; // r6
  int v7; // ctr
  unsigned __int8 *v8; // r11

  this->baseSequence = -1;
  this->lastFullSnapBaseSequence = -1;
  v2 = cstor;
  this->snapSequence = 42;
  this->hasPendingSnap = false;
  if ( !cstor && net_debugBaseStates.valueInteger != 0 )
    idLib::Printf(fmt: "NET: Reset snapshot base");
  idSnapShot::Clear(this: &this->baseState);
  idSnapShot::Clear(this: &this->submittedState);
  idSnapShot::Clear(this: &this->pendingSnap);
  this->deltas.dataLength = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->deltas);
  memset(Dst: this->deltas.data, Val: 0, Size: sizeof(this->deltas.data));
  if ( v2 )
  {
    memset(Dst: &this->deltaLogs, Val: 0, Size: sizeof(this->deltaLogs));
  }
  else
  {
    v4 = 64;
    p_deltaLogs = &this->deltaLogs;
    do
    {
      if ( p_deltaLogs->ptr[0] != nullptr )
      {
        idSerializerLog::Release(this: p_deltaLogs->ptr[0]);
        p_deltaLogs->ptr[0] = nullptr;
      }
      --v4;
      p_deltaLogs = (idArray<idSerializerLog *,64> *)((char *)p_deltaLogs + 4);
    }
    while ( v4 != 0 );
  }
  jobMemory = this->jobMemory;
  this->partialBaseSequence = -1;
  v7 = 6;
  v8 = &jobMemory->lzwMem.ptr[8184];
  do
  {
    v8 += 8;
    *(_QWORD *)v8 = 0x1048C00000000LL;
    --v7;
  }
  while ( v7 != 0 );
}


// ========================================================================
// ?ApplySnapshotDelta@idSnapshotProcessor@@QAA_NHH@Z
// EA  : 0x828A2170
// RVA : 0x008A2170
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

int __fastcall idSnapshotProcessor::ApplySnapshotDelta(
        idSnapshotProcessor *this,
        int visIndex,
        __int64 snapshotNumber,
        __int64 a4,
        __int64 a5)
{
  int v7; // r29
  va *v8; // r3
  idDataQueue<64,65536> *p_deltas; // r31
  int v10; // r9
  int v11; // r8
  int v12; // r7
  idDataQueue<64,65536>::msgItem_t *v13; // r11
  int list; // r10
  char DeltaForJob; // r3
  int v16; // r11
  int v17; // r9
  int v18; // r8
  int v19; // r7
  int v20; // r6
  int v21; // r5
  int v22; // r4
  int v23; // r8
  int v24; // r7
  int v25; // r6
  int v26; // r5
  int v27; // r4
  int valueInteger; // r11
  int v30; // r29
  int i; // r27
  int v32; // [sp+8h] [-1098h]
  int v33; // [sp+Ch] [-1094h]
  int v34; // [sp+10h] [-1090h]
  int v35; // [sp+14h] [-108Ch]
  int v36; // [sp+18h] [-1088h]
  int v37; // [sp+1Ch] [-1084h]
  int v38; // [sp+20h] [-1080h]
  int v39; // [sp+24h] [-107Ch]
  int v40; // [sp+28h] [-1078h]
  int v41; // [sp+2Ch] [-1074h]
  int v42; // [sp+30h] [-1070h]
  int v43; // [sp+34h] [-106Ch]
  int v44; // [sp+38h] [-1068h]
  int v45; // [sp+3Ch] [-1064h]
  int v46; // [sp+40h] [-1060h]
  int v47; // [sp+44h] [-105Ch]
  int v48; // [sp+48h] [-1058h]
  int v49; // [sp+4Ch] [-1054h]
  int v50; // [sp+50h] [-1050h] BYREF
  int v51[3]; // [sp+54h] [-104Ch] BYREF
  va v52; // [sp+60h] [-1040h] BYREF

  v7 = HIDWORD(snapshotNumber);
  if ( net_verboseSnapshot.valueInteger >= 6 )
  {
    v8 = va::va(
           this: &v52,
           fmt: "idSnapshotProcessor::ApplySnapshotDelta snapshotNumber: %d\n",
           a3: snapshotNumber,
           a4,
           a5,
           a6: v32,
           a7: v33,
           a8: v34,
           a9: v35,
           a10: v36,
           a11: v37);
    idLib::Printf(fmt: v8->buffer);
  }
  idSnapshotProcessor::SanityCheckDeltas(
    this,
    a2: visIndex,
    a3: SHIDWORD(snapshotNumber),
    a4: snapshotNumber,
    a5: SHIDWORD(a4),
    a6: a4);
  p_deltas = &this->deltas;
  idDataQueue<64,65536>::RemoveOlderThan(this: &this->deltas, sequence: v7);
  if ( this->deltas.items.num != 0 && (v13 = p_deltas->items.list, p_deltas->items.list->sequence == v7) )
  {
    list = (int)p_deltas->items.list;
    v51[0] = 0;
    idSnapShot::PeekDeltaSequence(
      deltaMem: (const char *)&p_deltas->data[v13->dataOffset],
      deltaSize: v13->length,
      sequence: &v50,
      baseSequence: v51,
      a5: v12,
      a6: v11,
      a7: v10,
      a8: list,
      a9: v32,
      a10: v33,
      a11: v34,
      a12: v35,
      a13: v36,
      a14: v37,
      a15: v38,
      a16: v39,
      a17: v40,
      a18: v41,
      a19: v42,
      a20: v43,
      a21: v44,
      a22: v45,
      a23: v46,
      a24: v47,
      a25: v48,
      a26: v49,
      a27: 0);
    if ( this->baseSequence != v51[0] )
      idLib::Error(fmt: "ApplySnapshotDelta: baseSequence != deltaBaseSequence");
    DeltaForJob = idSnapShot::ReadDeltaForJob(
                    this: &this->baseState,
                    deltaMem: (const char *)&p_deltas->data[p_deltas->items.list->dataOffset],
                    deltaSize: p_deltas->items.list->length,
                    visIndex,
                    templateStates: &this->templateStates);
    v16 = v50;
    if ( DeltaForJob != 0 )
      this->lastFullSnapBaseSequence = v50;
    this->baseSequence = v16;
    idSnapShot::SetSerializerLog(this: &this->baseState, log: this->deltaLogs.ptr[v16 % 64]);
    idSnapshotProcessor::RemoveDeltasForOldBaseSequence(
      this,
      a2: v22,
      a3: v21,
      a4: v20,
      a5: v19,
      a6: v18,
      baseSequence: v17);
    idSnapshotProcessor::SanityCheckDeltas(this, a2: v27, a3: v26, a4: v25, a5: v24, a6: v23);
    return 1;
  }
  else
  {
    if ( !common->IsServer(this: common) )
    {
      valueInteger = net_verboseSnapshot.valueInteger;
      if ( this->deltas.items.num != 0 )
      {
        if ( net_verboseSnapshot.valueInteger > 0 )
        {
          idLib::Printf(
            fmt: "NET: Got snapshot but ignored... deltas.ItemSequence( 0 ): %d != snapshotNumber: %d \n   ",
            p_deltas->items.list->sequence,
            v7);
          valueInteger = net_verboseSnapshot.valueInteger;
        }
        v30 = 0;
        for ( i = 0; i < this->deltas.items.num; ++v30 )
        {
          if ( valueInteger > 0 )
          {
            idLib::Printf(fmt: "%d ", p_deltas->items.list[v30].sequence);
            valueInteger = net_verboseSnapshot.valueInteger;
          }
          ++i;
        }
        if ( valueInteger > 0 )
          idLib::Printf(fmt: "\n");
      }
      else if ( net_verboseSnapshot.valueInteger > 0 )
      {
        idLib::Printf(fmt: "NET: Got snapshot but ignored... deltas.Num(): %d snapshotNumber: %d \n", 0, v7);
        return 0;
      }
    }
    return 0;
  }
}


// ========================================================================
// ??1idSnapshotProcessor@@QAA@XZ
// EA  : 0x828A23B0
// RVA : 0x008A23B0
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void __fastcall idSnapshotProcessor::~idSnapshotProcessor(idSnapshotProcessor *this)
{
  idMem::Free(this: &mem, ptr: this->jobMemory, align: ALIGN_16);
  idSnapShot::~idSnapShot(this: &this->submittedTemplateStates);
  idSnapShot::~idSnapShot(this: &this->templateStates);
  idSnapShot::~idSnapShot(this: &this->submittedState);
  idSnapShot::~idSnapShot(this: &this->pendingSnap);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->deltas);
  idSnapShot::~idSnapShot(this: &this->baseState);
}


// ========================================================================
// __unwind$220300
// EA  : 0x828A2444
// RVA : 0x008A2444
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void _unwind_220300()
{
  int v0; // r12

  idSnapShot::~idSnapShot(this: (idSnapShot *)(*(_DWORD *)(v0 - 112 + 132) + 12));
}


// ========================================================================
// __unwind$220301
// EA  : 0x828A2470
// RVA : 0x008A2470
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void _unwind_220301()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}


// ========================================================================
// __unwind$220302_0
// EA  : 0x828A249C
// RVA : 0x008A249C
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void _unwind_220302_0()
{
  int v0; // r12

  idSnapShot::~idSnapShot(this: (idSnapShot *)(*(_DWORD *)(v0 - 112 + 132) + 66644));
}


// ========================================================================
// __unwind$220303_0
// EA  : 0x828A24D0
// RVA : 0x008A24D0
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void _unwind_220303_0()
{
  int v0; // r12

  idSnapShot::~idSnapShot(this: (idSnapShot *)(*(_DWORD *)(v0 - 112 + 132) + 66704));
}


// ========================================================================
// __unwind$220304_0
// EA  : 0x828A2504
// RVA : 0x008A2504
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void _unwind_220304_0()
{
  int v0; // r12

  idSnapShot::~idSnapShot(this: (idSnapShot *)(*(_DWORD *)(v0 - 112 + 132) + 66756));
}


// ========================================================================
// __unwind$220305_0
// EA  : 0x828A2538
// RVA : 0x008A2538
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void _unwind_220305_0()
{
  int v0; // r12

  idSnapShot::~idSnapShot(this: (idSnapShot *)(*(_DWORD *)(v0 - 112 + 132) + 66808));
}


// ========================================================================
// ??0idSnapshotProcessor@@QAA@XZ
// EA  : 0x828A2578
// RVA : 0x008A2578
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

idSnapshotProcessor *__fastcall idSnapshotProcessor::idSnapshotProcessor(idSnapshotProcessor *this)
{
  idSnapShot::idSnapShot(this: &this->baseState);
  this->deltas.items.num = 0;
  this->deltas.items.granularity = 1;
  this->deltas.items.size = 64;
  this->deltas.items.list = this->deltas.items.staticList;
  this->deltas.items.memTag = 5;
  this->deltas.items.listStatic = 1;
  this->deltas.dataLength = 0;
  idSnapShot::idSnapShot(this: &this->pendingSnap);
  idSnapShot::idSnapShot(this: &this->submittedState);
  idSnapShot::idSnapShot(this: &this->templateStates);
  idSnapShot::idSnapShot(this: &this->submittedTemplateStates);
  this->jobMemory = (idSnapshotProcessor::jobMemory_t *)idMem::AllocWithLocation(
                                                          this: &mem,
                                                          location: "w:\\tech5\\engine\\network\\SnapshotProcessor.cpp(23) : TAG_NETWORKING",
                                                          size: 0x34440u,
                                                          tag: TAG_NETWORKING,
                                                          zeroBuffer: false,
                                                          align: ALIGN_16,
                                                          heap: HEAP_DEFAULTHEAP);
  idSnapshotProcessor::Reset(this, cstor: true);
  return this;
}


// ========================================================================
// __unwind$220394
// EA  : 0x828A2664
// RVA : 0x008A2664
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void _unwind_220394()
{
  int v0; // r12

  idSnapShot::~idSnapShot(this: (idSnapShot *)(*(_DWORD *)(v0 - 112 + 132) + 12));
}


// ========================================================================
// __unwind$220395
// EA  : 0x828A2690
// RVA : 0x008A2690
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void _unwind_220395()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}


// ========================================================================
// __unwind$220396
// EA  : 0x828A26BC
// RVA : 0x008A26BC
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void _unwind_220396()
{
  int v0; // r12

  idSnapShot::~idSnapShot(this: (idSnapShot *)(*(_DWORD *)(v0 - 112 + 132) + 66644));
}


// ========================================================================
// __unwind$220397
// EA  : 0x828A26F0
// RVA : 0x008A26F0
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void _unwind_220397()
{
  int v0; // r12

  idSnapShot::~idSnapShot(this: (idSnapShot *)(*(_DWORD *)(v0 - 112 + 132) + 66704));
}


// ========================================================================
// __unwind$220398
// EA  : 0x828A2724
// RVA : 0x008A2724
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void _unwind_220398()
{
  int v0; // r12

  idSnapShot::~idSnapShot(this: (idSnapShot *)(*(_DWORD *)(v0 - 112 + 132) + 66756));
}


// ========================================================================
// __unwind$220399
// EA  : 0x828A2758
// RVA : 0x008A2758
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void _unwind_220399()
{
  int v0; // r12

  idSnapShot::~idSnapShot(this: (idSnapShot *)(*(_DWORD *)(v0 - 112 + 132) + 66808));
}


// ========================================================================
// ?GetPendingSnapDelta@idSnapshotProcessor@@QAAHPAEH@Z
// EA  : 0x828A2858
// RVA : 0x008A2858
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

int __fastcall idSnapshotProcessor::GetPendingSnapDelta(
        idSnapshotProcessor *this,
        unsigned __int8 *outBuffer,
        int maxLength,
        int a4,
        int a5)
{
  idSnapshotProcessor::jobMemory_t **p_jobMemory; // r25
  lzwInOutData_t *p_lzwInOutData; // r11
  idSnapshotProcessor::jobMemory_t *v11; // r11
  int size; // r31
  int offset; // r10
  const char *v14; // r28
  __int64 v15; // r8
  __int64 v16; // r6
  bool v17; // cr56
  const char *snapSequence; // r4
  idDataQueue<64,65536> *p_deltas; // r29
  int num; // r11
  signed int length; // r31
  __int64 v22; // r10
  va *v23; // r3
  idSerializerLog *serializeLog; // r11
  int v25; // [sp+8h] [-10A8h]
  int v26; // [sp+8h] [-10A8h]
  int v27; // [sp+Ch] [-10A4h]
  int v28; // [sp+Ch] [-10A4h]
  int v29; // [sp+10h] [-10A0h]
  int v30; // [sp+10h] [-10A0h]
  int v31; // [sp+14h] [-109Ch]
  int v32; // [sp+14h] [-109Ch]
  int v33; // [sp+18h] [-1098h]
  int v34; // [sp+18h] [-1098h]
  int v35; // [sp+1Ch] [-1094h]
  int v36; // [sp+1Ch] [-1094h]
  int v37; // [sp+20h] [-1090h]
  int v38; // [sp+24h] [-108Ch]
  int v39; // [sp+28h] [-1088h]
  int v40; // [sp+2Ch] [-1084h]
  int v41; // [sp+30h] [-1080h]
  int v42; // [sp+34h] [-107Ch]
  int v43; // [sp+38h] [-1078h]
  int v44; // [sp+3Ch] [-1074h]
  int v45; // [sp+40h] [-1070h]
  int v46; // [sp+44h] [-106Ch]
  int v47; // [sp+48h] [-1068h]
  int v48; // [sp+4Ch] [-1064h]
  int v49; // [sp+50h] [-1060h] BYREF
  int v50[3]; // [sp+54h] [-105Ch] BYREF
  va v51; // [sp+60h] [-1050h] BYREF

  p_jobMemory = &this->jobMemory;
  p_lzwInOutData = &this->jobMemory->lzwInOutData;
  if ( p_lzwInOutData->numlzwDeltas == 1 )
  {
    p_lzwInOutData->numlzwDeltas = 0;
    v11 = *p_jobMemory;
    size = (*p_jobMemory)->lzwDeltas.ptr[0].size;
    if ( size == -1 )
      idLib::Error(fmt: "GetPendingSnapDelta: Delta failed.");
    offset = v11->lzwDeltas.ptr[0].offset;
    v50[0] = 0;
    v14 = (const char *)&v11->lzwMem.ptr[offset];
    idSnapShot::PeekDeltaSequence(
      deltaMem: v14,
      deltaSize: size,
      sequence: v50,
      baseSequence: &v49,
      a5,
      a6: (int)v11 + offset,
      a7: 205824,
      a8: offset,
      a9: v25,
      a10: v27,
      a11: v29,
      a12: v31,
      a13: v33,
      a14: v35,
      a15: v37,
      a16: v38,
      a17: v39,
      a18: v40,
      a19: v41,
      a20: v42,
      a21: v43,
      a22: v44,
      a23: v45,
      a24: v46,
      a25: v47,
      a26: v48,
      a27: 0);
    if ( maxLength < size )
      idLib::Error(fmt: "GetPendingSnapDelta: Size overflow.");
    memcpy(Dst: outBuffer, Src: v14, Size: size);
    HIDWORD(v15) = *p_jobMemory;
    LODWORD(v15) = 205832;
    LODWORD(v16) = this->baseSequence;
    v17 = v49 < (int)v16;
    snapSequence = (const char *)(*p_jobMemory)->lzwDeltas.ptr[0].snapSequence;
    this->snapSequence = (int)snapSequence;
    if ( !v17 )
    {
      p_deltas = &this->deltas;
      if ( (unsigned __int8)idDataQueue<64,65536>::Append(
                              this: &this->deltas,
                              sequence: snapSequence,
                              b1: (const unsigned __int8 *)v14,
                              b1Len: size,
                              b2: nullptr,
                              b2Len: 0) == 0 )
      {
        num = this->deltas.items.num;
        length = p_deltas->items.list[num - 1].length;
        if ( maxLength < length )
          idLib::Error(fmt: "GetPendingSnapDelta: Size overflow for resend.", maxLength - length);
        memcpy(Dst: outBuffer, Src: &p_deltas->data[p_deltas->items.list[num - 1].dataOffset], Size: length);
        size = -length;
      }
      idSnapshotProcessor::SetDeltaSerializerLog(this, seq: this->snapSequence, log: this->pendingSnap.serializeLog);
    }
    if ( (*p_jobMemory)->lzwInOutData.fullSnap )
    {
      LODWORD(v22) = &net_verboseSnapshot;
      if ( net_verboseSnapshot.valueInteger >= 5 )
      {
        HIDWORD(v22) = (*p_jobMemory)->lzwInOutData.fullSnap;
        v23 = va::va(
                this: &v51,
                fmt: "  wrote enough deltas to a full snapshot\n",
                a3: v16,
                a4: v15,
                a5: v22,
                a6: v26,
                a7: v28,
                a8: v30,
                a9: v32,
                a10: v34,
                a11: v36);
        idLib::Printf(fmt: v23->buffer);
      }
      this->hasPendingSnap = false;
      this->partialBaseSequence = -1;
    }
    else
    {
      this->partialBaseSequence = v49;
    }
    serializeLog = this->pendingSnap.serializeLog;
    if ( serializeLog != nullptr && !serializeLog->fragmented )
    {
      serializeLog->fragmented = (_cntlzw((*p_jobMemory)->lzwInOutData.fullSnap) & 0x20) != 0;
      this->pendingSnap.serializeLog->finalCompressedSize = size;
    }
    return size;
  }
  else
  {
    p_lzwInOutData->numlzwDeltas = 0;
    return 0;
  }
}


// ========================================================================
// ?ReceiveSnapshotDelta@idSnapshotProcessor@@QAA_NPBEHHAAH1AAVidSnapShot@@AA_N@Z
// EA  : 0x828A2AC0
// RVA : 0x008A2AC0
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

int __fastcall idSnapshotProcessor::ReceiveSnapshotDelta(
        idSnapshotProcessor *this,
        const char *deltaData,
        size_t deltaLength,
        int visIndex,
        int *outSeq,
        int *outBaseSeq,
        idSnapShot *outSnap,
        bool *fullSnap)
{
  int v8; // r30
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  int num; // r4
  int valueInteger; // r11
  int i; // r28
  int v24; // r5
  int baseSequence; // r4
  unsigned __int8 DeltaForJob; // r3
  idSerializerLog *serializeLog; // r11
  int v28; // [sp+8h] [-C8h]
  int v29; // [sp+Ch] [-C4h]
  int v30; // [sp+10h] [-C0h]
  int v31; // [sp+14h] [-BCh]
  int v32; // [sp+18h] [-B8h]
  int v33; // [sp+1Ch] [-B4h]
  int v34; // [sp+20h] [-B0h]
  int v35; // [sp+24h] [-ACh]
  int v36; // [sp+28h] [-A8h]
  int v37; // [sp+2Ch] [-A4h]
  int v38; // [sp+30h] [-A0h]
  int v39; // [sp+34h] [-9Ch]
  int v40; // [sp+38h] [-98h]
  int v41; // [sp+3Ch] [-94h]
  int v42; // [sp+40h] [-90h]
  int v43; // [sp+44h] [-8Ch]
  int v44; // [sp+48h] [-88h]
  int v45; // [sp+4Ch] [-84h]
  const char *v46; // [sp+50h] [-80h] BYREF
  int v47; // [sp+54h] [-7Ch] BYREF

  v8 = 0;
  *fullSnap = false;
  v47 = 0;
  idSnapShot::PeekDeltaSequence(
    deltaMem: deltaData,
    deltaSize: deltaLength,
    sequence: (int *)&v46,
    baseSequence: &v47,
    a5: (int)outSeq,
    a6: (int)outBaseSeq,
    a7: (int)outSnap,
    a8: (int)fullSnap,
    a9: v28,
    a10: v29,
    a11: v30,
    a12: v31,
    a13: v32,
    a14: v33,
    a15: v34,
    a16: v35,
    a17: v36,
    a18: v37,
    a19: v38,
    a20: v39,
    a21: v40,
    a22: v41,
    a23: v42,
    a24: v43,
    a25: v44,
    a26: v45,
    a27: 0);
  if ( (int)v46 <= this->snapSequence )
  {
    if ( net_verboseSnapshot.valueInteger > 0 )
    {
      idLib::Printf(fmt: "Rejecting old delta: %d (snapSequence: %d \n", v46, this->snapSequence);
      return 0;
    }
    return 0;
  }
  HIDWORD(v19) = v47;
  idSnapshotProcessor::ApplySnapshotDelta(this, visIndex, snapshotNumber: v19, a4: v18, a5: v17);
  if ( net_skipClientDeltaAppend.valueInteger != 0
    || (unsigned __int8)idDataQueue<64,65536>::Append(
                          this: &this->deltas,
                          sequence: v46,
                          b1: (const unsigned __int8 *)deltaData,
                          b1Len: deltaLength,
                          b2: nullptr,
                          b2Len: 0) == 0 )
  {
    idLib::Printf(fmt: "NET: ReceiveSnapshotDelta: No room to append delta %d/%d \n", v46, v47);
    return 0;
  }
  num = this->deltas.items.num;
  this->snapSequence = (int)v46;
  if ( num > 10 )
  {
    valueInteger = net_verboseSnapshot.valueInteger;
    if ( net_verboseSnapshot.valueInteger > 0 )
    {
      idLib::Printf(fmt: "NET: ReceiveSnapshotDelta: deltas.Num() > 10: %d\n   ", num);
      valueInteger = net_verboseSnapshot.valueInteger;
    }
    for ( i = 0; i < this->deltas.items.num; ++v8 )
    {
      if ( valueInteger > 0 )
      {
        idLib::Printf(fmt: "%d ", this->deltas.items.list[v8].sequence);
        valueInteger = net_verboseSnapshot.valueInteger;
      }
      ++i;
    }
    if ( valueInteger > 0 )
      idLib::Printf(fmt: "\n");
  }
  v24 = v47;
  if ( this->baseSequence != v47 )
    idLib::Error(fmt: "ReceiveSnapshotDelta: baseSequence != deltaBaseSequence");
  *outSeq = (int)v46;
  *outBaseSeq = v24;
  baseSequence = this->baseSequence;
  if ( baseSequence < 50 && net_debugBaseStates.valueInteger != 0 )
    idLib::Printf(fmt: "NET: Proper basestate...  baseSequence: %d  deltaBaseSequence: %d \n", baseSequence, v24);
  idSnapshotProcessor::SetDeltaSerializerLog(this, seq: *outSeq, log: outSnap->serializeLog);
  idSnapShot::operator=(this: outSnap, other: &this->baseState);
  idSnapShot::SetSerializerLog(this: outSnap, log: this->deltaLogs.ptr[*outSeq % 64]);
  DeltaForJob = idSnapShot::ReadDeltaForJob(
                  this: outSnap,
                  deltaMem: deltaData,
                  deltaSize: deltaLength,
                  visIndex,
                  templateStates: &this->templateStates);
  *fullSnap = DeltaForJob;
  serializeLog = outSnap->serializeLog;
  if ( serializeLog != nullptr && !serializeLog->fragmented )
  {
    serializeLog->fragmented = (_cntlzw(DeltaForJob) & 0x20) != 0;
    outSnap->serializeLog->finalCompressedSize = deltaLength;
  }
  return 1;
}


// ========================================================================
// `dynamic initializer for 'net_optimalSnapDeltaSize''
// EA  : 0x83346160
// RVA : 0x01346160
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_optimalSnapDeltaSize__()
{
  idCVar::idCVar(
    this: &net_optimalSnapDeltaSize,
    name: "net_optimalSnapDeltaSize",
    value: "1000",
    flags: 2,
    description: "Optimal size of snapshot delta msgs.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_optimalSnapDeltaSize__);
}


// ========================================================================
// `dynamic initializer for 'net_debugBaseStates''
// EA  : 0x833461B8
// RVA : 0x013461B8
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_debugBaseStates__()
{
  idCVar::idCVar(
    this: &net_debugBaseStates,
    name: "net_debugBaseStates",
    value: "0",
    flags: 1,
    description: "Log out base state information",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_debugBaseStates__);
}


// ========================================================================
// `dynamic initializer for 'net_skipClientDeltaAppend''
// EA  : 0x83346210
// RVA : 0x01346210
// PDB : w:\tech5\engine\network\snapshotprocessor.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_skipClientDeltaAppend__()
{
  idCVar::idCVar(
    this: &net_skipClientDeltaAppend,
    name: "net_skipClientDeltaAppend",
    value: "0",
    flags: 1,
    description: "Simulate delta receive buffer overflowing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_skipClientDeltaAppend__);
}

