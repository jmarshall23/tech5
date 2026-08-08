
// ========================================================================
// ?_Release@objectBuffer_t@idSnapShot@@QAAXXZ
// EA  : 0x8289DBB0
// RVA : 0x0089DBB0
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __fastcall idSnapShot::objectBuffer_t::_Release(idSnapShot::objectBuffer_t *this)
{
  unsigned __int8 *data; // r11
  unsigned int size; // r10
  int v4; // r8

  data = this->data;
  if ( this->data != nullptr )
  {
    size = this->size;
    v4 = (unsigned __int8)(data[size] - 1);
    data[size] = v4;
    if ( v4 == 0 )
      idMem::Free(this: &mem, ptr: this->data, align: ALIGN_16);
    this->data = nullptr;
    this->size = 0;
  }
}


// ========================================================================
// ??4objectBuffer_t@idSnapShot@@QAAXABU01@@Z
// EA  : 0x8289DC20
// RVA : 0x0089DC20
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __fastcall idSnapShot::objectBuffer_t::operator=(
        idSnapShot::objectBuffer_t *this,
        const idSnapShot::objectBuffer_t *other)
{
  unsigned __int8 *data; // r10
  bool v5; // cr58
  unsigned int size; // r11

  if ( this != other )
  {
    idSnapShot::objectBuffer_t::_Release(this);
    data = other->data;
    v5 = other->data == nullptr;
    this->data = other->data;
    size = other->size;
    this->size = size;
    if ( !v5 )
      ++data[size];
  }
}


// ========================================================================
// ?SetSerializerLog@idSnapShot@@QAAXPAVidSerializerLog@@@Z
// EA  : 0x8289DC88
// RVA : 0x0089DC88
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __fastcall idSnapShot::SetSerializerLog(idSnapShot *this, idSerializerLog *log)
{
  idSerializerLog *serializeLog; // r3

  if ( log != nullptr )
    idSerializerLog::AddRef(this: log);
  serializeLog = this->serializeLog;
  if ( serializeLog != nullptr )
    idSerializerLog::Release(this: serializeLog);
  this->serializeLog = log;
}


// ========================================================================
// ?Print@objectState_t@idSnapShot@@QAAXPBD@Z
// EA  : 0x8289DE08
// RVA : 0x0089DE08
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __fastcall idSnapShot::objectState_t::Print(
        idSnapShot::objectState_t *this,
        const char *name,
        int a3,
        int a4,
        __int64 a5)
{
  __int64 v5; // r10
  __int64 v7; // r6
  unsigned int valueInteger; // r31
  unsigned int size; // r30
  va *v10; // r3
  int v11; // [sp+8h] [-1078h]
  int v12; // [sp+Ch] [-1074h]
  int v13; // [sp+10h] [-1070h]
  int v14; // [sp+14h] [-106Ch]
  int v15; // [sp+18h] [-1068h]
  int v16; // [sp+1Ch] [-1064h]
  va v17; // [sp+50h] [-1030h] BYREF

  LODWORD(v7) = this->buffer.size;
  LODWORD(v5) = &r_cuttablemodel_freecpudata.description;
  HIDWORD(v5) = &net_ssTemplateDebug_len;
  LODWORD(a5) = &net_ssTemplateDebug_start;
  HIDWORD(v7) = name;
  valueInteger = net_ssTemplateDebug_start.valueInteger;
  size = net_ssTemplateDebug_len.valueInteger + net_ssTemplateDebug_start.valueInteger;
  if ( (unsigned int)v7 < net_ssTemplateDebug_len.valueInteger + net_ssTemplateDebug_start.valueInteger )
    size = this->buffer.size;
  v10 = va::va(
          this: &v17,
          fmt: "%s: [sz %d]",
          a3: v7,
          a4: a5,
          a5: v5,
          a6: v11,
          a7: v12,
          a8: v13,
          a9: v14,
          a10: v15,
          a11: v16);
  idLib::Printf(fmt: "%25s: 0x", v10->buffer);
  for ( ; valueInteger < size; ++valueInteger )
    idLib::Printf(fmt: "%02X", this->buffer.data[valueInteger]);
  idLib::Printf(fmt: "\n");
}


// ========================================================================
// ?Alloc@objectBuffer_t@idSnapShot@@QAAXH@Z
// EA  : 0x8289DEB0
// RVA : 0x0089DEB0
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __fastcall idSnapShot::objectBuffer_t::Alloc(idSnapShot::objectBuffer_t *this, unsigned int s)
{
  unsigned __int8 *v4; // r3

  if ( s >= 0xFFFFFFFE )
    idLib::FatalError(fmt: "s >= SIZE_NOT_STALE");
  idSnapShot::objectBuffer_t::_Release(this);
  v4 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\engine\\network\\Snapshot.cpp(71) : TAG_NETWORKING",
                            size: s + 1,
                            tag: TAG_NETWORKING,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  this->size = s;
  this->data = v4;
  v4[s] = 1;
}


// ========================================================================
// ?SubmitLZWJob@idSnapShot@@AAAXABUsubmitDeltaJobsInfo_t@1@AAPAUobjParms_t@@1AAPAUlzwParm_t@@_N@Z
// EA  : 0x8289DF40
// RVA : 0x0089DF40
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __fastcall idSnapShot::SubmitLZWJob(
        idSnapShot *this,
        const idSnapShot::submitDeltaJobsInfo_t *writeDeltaInfo,
        objParms_t **baseObjParm,
        objParms_t **curObjParm,
        lzwParm_t **curlzwParm,
        bool saveDictionary)
{
  int v11; // r28
  int *v12; // r11
  int *p_csize; // r29
  int v14; // r4
  idParallelJobList *snapshotJobList; // r3

  v11 = *curObjParm - *baseObjParm;
  if ( v11 != 0 )
  {
    v12 = (int *)*curlzwParm;
    if ( *curlzwParm - writeDeltaInfo->lzwParms >= writeDeltaInfo->maxDeltaParms )
      idLib::Error(fmt: "SubmitLZWJob: Not enough lzwParams.\n");
    *v12 = v11;
    (*curlzwParm)->headers = writeDeltaInfo->headers;
    (*curlzwParm)->curTime = this->time;
    (*curlzwParm)->baseTime = writeDeltaInfo->oldSnap->time;
    (*curlzwParm)->baseSequence = writeDeltaInfo->baseSequence;
    (*curlzwParm)->fragmented = writeDeltaInfo->lzwParms != *curlzwParm;
    (*curlzwParm)->saveDictionary = saveDictionary;
    (*curlzwParm)->ioData = writeDeltaInfo->lzwInOutData;
    if ( this->serializeLog != nullptr && v11 > 0 )
    {
      p_csize = &writeDeltaInfo->headers[-1].csize;
      do
      {
        v14 = p_csize[6];
        p_csize += 8;
        idSerializerLog::AddCompressionLog(this: this->serializeLog, objID: v14, csize: *p_csize);
        --v11;
      }
      while ( v11 != 0 );
    }
    snapshotJobList = writeDeltaInfo->snapshotJobList;
    if ( snapshotJobList != nullptr )
    {
      idParallelJobList::InsertSyncPoint(this: snapshotJobList, syncType: SYNC_SIGNAL);
      idParallelJobList::InsertSyncPoint(this: writeDeltaInfo->snapshotJobList, syncType: SYNC_SYNCHRONIZE);
      idParallelJobList::AddJob(
        this: writeDeltaInfo->snapshotJobList,
        function: (void (__fastcall *)(void *))LZWJob,
        data: *curlzwParm);
      idParallelJobList::InsertSyncPoint(this: writeDeltaInfo->snapshotJobList, syncType: SYNC_SIGNAL);
      idParallelJobList::InsertSyncPoint(this: writeDeltaInfo->snapshotJobList, syncType: SYNC_SYNCHRONIZE);
    }
    else
    {
      LZWJob(parm: *curlzwParm);
    }
    ++*curlzwParm;
    *baseObjParm = *curObjParm;
  }
}


// ========================================================================
// ?GetObjectMsgByIndex@idSnapShot@@QAAHHAAVidBitMsg@@_N@Z
// EA  : 0x8289E0B0
// RVA : 0x0089E0B0
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

int __fastcall idSnapShot::GetObjectMsgByIndex(idSnapShot *this, int i, idBitMsg *msg, bool ignoreIfStale)
{
  unsigned __int64 v4; // r11
  const unsigned __int8 *v5; // r9
  int v6; // r8

  if ( i < 0 )
    return -1;
  if ( i >= this->objectStates.num )
    return -1;
  HIDWORD(v4) = this->objectStates.list[i];
  if ( *(_BYTE *)(HIDWORD(v4) + 16) != 0 && ignoreIfStale )
    return -1;
  v5 = *(const unsigned __int8 **)(HIDWORD(v4) + 4);
  LODWORD(v4) = 0;
  v6 = *(_DWORD *)(HIDWORD(v4) + 8);
  msg->writeData = nullptr;
  msg->writeBit = 0;
  msg->readCount = 0;
  msg->readData = v5;
  msg->maxSize = v6;
  msg->curSize = v6;
  msg->readBit = 0;
  msg->allowOverflow = false;
  msg->overflowed = false;
  msg->tempValue = v4;
  return (unsigned __int16)*(_WORD *)HIDWORD(v4);
}


// ========================================================================
// ?ObjectChangedCountByIndex@idSnapShot@@QAAHH@Z
// EA  : 0x8289E130
// RVA : 0x0089E130
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

int __fastcall idSnapShot::ObjectChangedCountByIndex(idSnapShot *this, int i)
{
  if ( i < 0 || i >= this->objectStates.num )
    return 0;
  else
    return this->objectStates.list[i]->changedCount;
}


// ========================================================================
// ?BinarySearch@idSnapShot@@ABAHH@Z
// EA  : 0x8289E160
// RVA : 0x0089E160
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

int __fastcall idSnapShot::BinarySearch(idSnapShot *this, int objectNum)
{
  int num; // r9
  int v3; // r8
  int v4; // r11
  int v5; // r10

  num = this->objectStates.num;
  v3 = 0;
  if ( num == 0 )
    return num;
  while ( 1 )
  {
    v4 = (num + v3) >> 1;
    v5 = this->objectStates.list[v4]->objectNum;
    if ( v5 == objectNum )
      break;
    if ( v5 >= objectNum )
      num = (num + v3) >> 1;
    else
      v3 = v4 + 1;
    if ( num == v3 )
      return num;
  }
  return (num + v3) >> 1;
}


// ========================================================================
// ?FindObjectByID@idSnapShot@@QBAPAUobjectState_t@1@H@Z
// EA  : 0x8289E1B8
// RVA : 0x0089E1B8
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

idSnapShot::objectState_t *__fastcall idSnapShot::FindObjectByID(idSnapShot *this, int objectNum)
{
  _DWORD *v2; // r5
  int v3; // r4
  int v4; // r3
  idSnapShot::objectState_t *result; // r3

  v4 = idSnapShot::BinarySearch(this, objectNum);
  if ( v4 < 0 )
    return nullptr;
  if ( v4 >= v2[1] )
    return nullptr;
  result = *(idSnapShot::objectState_t **)(4 * v4 + *v2);
  if ( result->objectNum != v3 )
    return nullptr;
  return result;
}


// ========================================================================
// ?UpdateExpectedSeq@idSnapShot@@QAAXH@Z
// EA  : 0x8289E210
// RVA : 0x0089E210
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __fastcall idSnapShot::UpdateExpectedSeq(idSnapShot *this, int newSeq)
{
  int v2; // r9
  int v3; // r11
  idSnapShot::objectState_t *v4; // r10

  v2 = 0;
  if ( this->objectStates.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->objectStates.list[v3];
      if ( v4->expectedSequence == -2 )
        v4->expectedSequence = newSeq;
      ++v2;
      ++v3;
    }
    while ( v2 < this->objectStates.num );
  }
}


// ========================================================================
// ?ApplyToExistingState@idSnapShot@@QAAXHAAVidBitMsg@@@Z
// EA  : 0x8289E258
// RVA : 0x0089E258
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __fastcall idSnapShot::ApplyToExistingState(idSnapShot *this, int objId, idBitMsg *msg)
{
  int v5; // r6
  int v6; // r5
  int v7; // r4
  int v8; // r3
  idSnapShot::objectState_t *v9; // r27
  __int64 v10; // r8
  int v11; // r6
  int v12; // r5
  __int64 v13; // r8
  int v14; // r6
  int v15; // r5
  int v16; // r30
  int valueInteger; // r9
  char v18; // r11
  unsigned int i; // r10
  int writeBit; // r9
  __int64 v21; // r8
  unsigned int size; // r11
  unsigned int v23; // r9
  unsigned __int8 *v24; // r11
  unsigned __int8 v25; // r9

  v8 = idSnapShot::BinarySearch(this, objectNum: objId);
  if ( v8 >= 0 && v8 < this->objectStates.num )
  {
    v9 = this->objectStates.list[v8];
    if ( v9->objectNum == v7 && v9 != nullptr )
    {
      if ( v9->createdFromTemplate )
      {
        if ( net_ssTemplateDebug.valueInteger != 0 )
        {
          idLib::Printf(
            fmt: "\nApplyToExistingState[%d]. buffer size: %d msg size: %d\n",
            v7,
            v9->buffer.size,
            (msg->writeBit != 0) + msg->curSize);
          HIDWORD(v13) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
          idSnapShot::objectState_t::Print(this: v9, name: "DELTA STATE", a3: v15, a4: v14, a5: v13);
          idLib::Printf(fmt: "%25s: 0x", "SPAWN STATE");
          v16 = 0;
          if ( (msg->writeBit != 0) + msg->curSize > 0 )
          {
            valueInteger = net_ssTemplateDebug_start.valueInteger;
            do
            {
              if ( v16 < valueInteger || (v18 = 1, v16 >= net_ssTemplateDebug_len.valueInteger + valueInteger) )
                v18 = 0;
              if ( v18 != 0 )
              {
                idLib::Printf(fmt: "%02X", msg->readData[v16]);
                valueInteger = net_ssTemplateDebug_start.valueInteger;
              }
              ++v16;
            }
            while ( v16 < (msg->writeBit != 0) + msg->curSize );
          }
          idLib::Printf(fmt: "\n");
        }
        for ( i = 0; ; ++i )
        {
          writeBit = msg->writeBit;
          LODWORD(v21) = msg->curSize;
          HIDWORD(v21) = writeBit - 1;
          size = v9->buffer.size;
          v23 = (writeBit != 0) + (_DWORD)v21;
          if ( size >= v23 )
            size = v23;
          if ( i >= size )
            break;
          v24 = &v9->buffer.data[i];
          v25 = msg->readData[i];
          *v24 += v25;
        }
        if ( net_ssTemplateDebug.valueInteger != 0 )
        {
          idSnapShot::objectState_t::Print(this: v9, name: "NEW STATE", a3: v6, a4: v5, a5: v21);
          idLib::Printf(fmt: "\n");
        }
      }
      else if ( net_ssTemplateDebug.valueInteger != 0 )
      {
        idLib::Printf(
          fmt: "NOT ApplyToExistingState[%d] because object was created from existing base state. %d\n",
          v7,
          v9->expectedSequence);
        idSnapShot::objectState_t::Print(this: v9, name: "SS STATE", a3: v12, a4: v11, a5: v10);
      }
    }
  }
}


// ========================================================================
// ?PeekDeltaSequence@idSnapShot@@SAXPBDHAAH1@Z
// EA  : 0x8289E5A0
// RVA : 0x0089E5A0
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __fastcall idSnapShot::PeekDeltaSequence(
        const char *deltaMem,
        int deltaSize,
        int *sequence,
        int *baseSequence,
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
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27)
{
  __int64 v27; // r4
  int *v28; // r5
  int *v29; // r31
  int *v30; // r6
  int *v31; // r30

  v27 = ((__int64 (__fastcall *)(const char *, int, int *, int *))RtlCheckStack12)(
          a1: deltaMem,
          a2: deltaSize,
          a3: sequence,
          a4: baseSequence);
  v29 = v28;
  v31 = v30;
  STACK[0x10940] = (unsigned int)&a27;
  idLZWCompressor::Start(
    this: (idLZWCompressor *)&STACK[0x10940],
    data_: (unsigned __int8 *)HIDWORD(v27),
    maxSize_: v27,
    append: false);
  idLZWCompressor::ReadAgnostic<unsigned int>(this: (idLZWCompressor *)&STACK[0x10940], c: v29, ignoreOverflow: false);
  idLZWCompressor::ReadAgnostic<unsigned int>(this: (idLZWCompressor *)&STACK[0x10940], c: v31, ignoreOverflow: false);
}


// ========================================================================
// ?SubmitObjectJob@idSnapShot@@AAAXABUsubmitDeltaJobsInfo_t@1@PAUobjectState_t@1@1AAPAUobjParms_t@@2AAPAUobjHeader_t@@AAPAEAAPAUlzwParm_t@@@Z
// EA  : 0x8289E620
// RVA : 0x0089E620
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __fastcall idSnapShot::SubmitObjectJob(
        idSnapShot *this,
        const idSnapShot::submitDeltaJobsInfo_t *submitDeltaJobsInfo,
        idSnapShot::objectState_t *newState,
        idSnapShot::objectState_t *oldState,
        objParms_t **baseObjParm,
        objParms_t **curObjParm,
        objHeader_t **curHeader,
        unsigned __int8 **curObjDest,
        lzwParm_t **curlzwParm,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        lzwParm_t **a28)
{
  objParms_t **v31; // r5
  bool v35; // zf
  unsigned int size; // r11
  unsigned int v37; // r25
  objParms_t *v38; // r11
  objParms_t *v39; // r11
  idParallelJobList *snapshotJobList; // r3

  v35 = newState == nullptr;
  v31 = baseObjParm;
  if ( v35 )
    size = 0;
  else
    size = newState->buffer.size;
  v37 = (size + 15) & 0xFFFFFFF0;
  if ( *curObjParm - submitDeltaJobsInfo->objParms >= submitDeltaJobsInfo->maxObjParms )
    idLib::Error(fmt: "Out of parms for snapshot jobs.\n");
  if ( (int)(*curObjDest - submitDeltaJobsInfo->objMemory + v37) >= submitDeltaJobsInfo->maxObjMemory
    || *curHeader - submitDeltaJobsInfo->headers >= submitDeltaJobsInfo->maxHeaders )
  {
    idSnapShot::SubmitLZWJob(
      this,
      writeDeltaInfo: submitDeltaJobsInfo,
      baseObjParm: v31,
      curObjParm,
      curlzwParm: a28,
      saveDictionary: true);
    *curHeader = submitDeltaJobsInfo->headers;
    *curObjDest = submitDeltaJobsInfo->objMemory;
  }
  (*curObjParm)->visIndex = submitDeltaJobsInfo->visIndex;
  (*curObjParm)->destHeader = *curHeader;
  (*curObjParm)->dest = *curObjDest;
  v38 = *curObjParm;
  *(_DWORD *)&v38->newState.valid = 0;
  v38->newState.data = nullptr;
  *(_DWORD *)&v38->newState.size = 0;
  v38->newState.visMask = 0;
  v39 = *curObjParm;
  *(_DWORD *)&v39->oldState.valid = 0;
  v39->oldState.data = nullptr;
  *(_DWORD *)&v39->oldState.size = 0;
  v39->oldState.visMask = 0;
  if ( newState != nullptr )
  {
    (*curObjParm)->newState.valid = 1;
    (*curObjParm)->newState.data = newState->buffer.data;
    (*curObjParm)->newState.size = newState->buffer.size;
    (*curObjParm)->newState.objectNum = newState->objectNum;
    (*curObjParm)->newState.visMask = newState->visMask;
  }
  if ( oldState != nullptr )
  {
    (*curObjParm)->oldState.valid = 1;
    (*curObjParm)->oldState.data = oldState->buffer.data;
    (*curObjParm)->oldState.size = oldState->buffer.size;
    (*curObjParm)->oldState.objectNum = oldState->objectNum;
    (*curObjParm)->oldState.visMask = oldState->visMask;
  }
  snapshotJobList = submitDeltaJobsInfo->snapshotJobList;
  if ( snapshotJobList != nullptr )
    idParallelJobList::AddJob(
      this: snapshotJobList,
      function: (void (__fastcall *)(void *))SnapshotObjectJob,
      data: *curObjParm);
  else
    SnapshotObjectJob(parms: *curObjParm);
  *curObjDest += v37;
  ++*curObjParm;
  ++*curHeader;
}


// ========================================================================
// ?FindObjectIndexByID@idSnapShot@@QBAHH@Z
// EA  : 0x8289E838
// RVA : 0x0089E838
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

int __fastcall idSnapShot::FindObjectIndexByID(idSnapShot *this, int objectNum)
{
  _DWORD *v2; // r5
  int v3; // r4
  int result; // r3

  result = idSnapShot::BinarySearch(this, objectNum);
  if ( result < 0 || result >= v2[1] || **(unsigned __int16 **)(4 * result + *v2) != v3 )
    return -1;
  return result;
}


// ========================================================================
// ??0idSnapShot@@QAA@XZ
// EA  : 0x8289E898
// RVA : 0x0089E898
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

idSnapShot *__fastcall idSnapShot::idSnapShot(idSnapShot *this)
{
  this->objectStates.list = nullptr;
  this->objectStates.granularity = 0;
  this->objectStates.memTag = 57;
  this->objectStates.listStatic = 0;
  this->objectStates.size = 0;
  this->objectStates.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->allocatedObjs.blocks = nullptr;
  this->allocatedObjs.free = nullptr;
  this->allocatedObjs.total = 0;
  this->allocatedObjs.active = 0;
  this->allocatedObjs.allowAllocs = true;
  this->allocatedObjs.clearAllocs = false;
  this->time = 0;
  this->recvTime = 0;
  this->isGlobalHeap = idMem::IsGlobalHeap(this: &mem);
  this->serializeLog = nullptr;
  return this;
}


// ========================================================================
// __unwind$221817
// EA  : 0x8289E920
// RVA : 0x0089E920
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void _unwind_221817()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$221818
// EA  : 0x8289E948
// RVA : 0x0089E948
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void _unwind_221818()
{
  int v0; // r12

  idBlockAlloc<idSnapShot::objectState_t,16,57>::~idBlockAlloc<idSnapShot::objectState_t,16,57>(this: (idBlockAlloc<idSnapShot::objectState_t,16,57> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// ?GetTemplateState@idSnapShot@@QAAPAUobjectState_t@1@HPAV1@PAU21@@Z
// EA  : 0x8289E978
// RVA : 0x0089E978
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

idSnapShot::objectState_t *__fastcall idSnapShot::GetTemplateState(
        idSnapShot *this,
        int objNum,
        idSnapShot *templateStates,
        idSnapShot::objectState_t *newState)
{
  _DWORD *v5; // r5
  int v6; // r4
  int v7; // r3
  idSnapShot::objectState_t *v8; // r31
  __int64 v9; // r8
  int v10; // r6
  int v11; // r5
  __int64 v12; // r8
  int v13; // r6
  int v14; // r5

  v7 = idSnapShot::BinarySearch(this: templateStates, objectNum: objNum);
  if ( v7 < 0 )
    return nullptr;
  if ( v7 >= v5[1] )
    return nullptr;
  v8 = *(idSnapShot::objectState_t **)(4 * v7 + *v5);
  if ( v8->objectNum != v6 )
    return nullptr;
  if ( net_ssTemplateDebug.valueInteger != 0 )
  {
    idLib::Printf(fmt: "\nGetTemplateState[%d]\n", v6);
    idSnapShot::objectState_t::Print(this: v8, name: "SPAWN STATE", a3: v11, a4: v10, a5: v9);
    if ( newState != nullptr )
      idSnapShot::objectState_t::Print(this: newState, name: "CUR STATE", a3: v14, a4: v13, a5: v12);
  }
  return v8;
}


// ========================================================================
// ?SubmitWriteDeltaToJobs@idSnapShot@@QAAXABUsubmitDeltaJobsInfo_t@1@@Z
// EA  : 0x8289EA20
// RVA : 0x0089EA20
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __fastcall idSnapShot::SubmitWriteDeltaToJobs(
        idSnapShot *this,
        const idSnapShot::submitDeltaJobsInfo_t *submitDeltaJobInfo)
{
  objParms_t *objParms; // r9
  lzwParm_t *lzwParms; // r8
  objHeader_t *headers; // r7
  int v7; // r28
  unsigned __int8 *objMemory; // r6
  int v9; // r24
  int num; // r10
  int v11; // r26
  int v12; // r25
  idSnapShot::objectState_t *v13; // r30
  idSnapShot::objectState_t *v14; // r3
  int v15; // r29
  unsigned int objectNum; // r4
  idSnapShot::objectState_t **list; // r11
  idSnapShot::objectState_t *v18; // r6
  idSnapShot::objectState_t *TemplateState; // r6
  idSnapShot::objectState_t *v20; // r3
  idSnapShot *oldSnap; // r11
  int v22; // r30
  idSnapShot::objectState_t *v23; // r6
  lzwParm_t **v24; // [sp+8h] [-C8h]
  int v25; // [sp+Ch] [-C4h]
  int v26; // [sp+10h] [-C0h]
  int v27; // [sp+14h] [-BCh]
  int v28; // [sp+18h] [-B8h]
  int v29; // [sp+1Ch] [-B4h]
  int v30; // [sp+20h] [-B0h]
  int v31; // [sp+24h] [-ACh]
  int v32; // [sp+28h] [-A8h]
  int v33; // [sp+2Ch] [-A4h]
  int v34; // [sp+30h] [-A0h]
  int v35; // [sp+34h] [-9Ch]
  int v36; // [sp+38h] [-98h]
  int v37; // [sp+3Ch] [-94h]
  int v38; // [sp+40h] [-90h]
  int v39; // [sp+44h] [-8Ch]
  int v40; // [sp+48h] [-88h]
  int v41; // [sp+4Ch] [-84h]
  int v42; // [sp+50h] [-80h]
  lzwParm_t *v43; // [sp+60h] [-70h] BYREF
  objParms_t *v44; // [sp+64h] [-6Ch] BYREF
  objParms_t *v45; // [sp+68h] [-68h] BYREF
  unsigned __int8 *v46; // [sp+6Ch] [-64h] BYREF
  objHeader_t *v47[24]; // [sp+70h] [-60h] BYREF

  objParms = submitDeltaJobInfo->objParms;
  lzwParms = submitDeltaJobInfo->lzwParms;
  headers = submitDeltaJobInfo->headers;
  v7 = 0;
  objMemory = submitDeltaJobInfo->objMemory;
  v9 = 0;
  submitDeltaJobInfo->lzwInOutData->numlzwDeltas = 0;
  submitDeltaJobInfo->lzwInOutData->lzwBytes = 0;
  submitDeltaJobInfo->lzwInOutData->fullSnap = false;
  num = this->objectStates.num;
  v11 = submitDeltaJobInfo->oldSnap->objectStates.num;
  v43 = lzwParms;
  v47[0] = headers;
  v46 = objMemory;
  v44 = objParms;
  v45 = objParms;
  if ( num > 0 )
  {
    v12 = 0;
    do
    {
      v13 = this->objectStates.list[v12];
      if ( v13->buffer.size != 0 )
      {
        if ( v7 < v11 )
        {
          v15 = v7;
          while ( 1 )
          {
            objectNum = v13->objectNum;
            list = submitDeltaJobInfo->oldSnap->objectStates.list;
            v18 = list[v15];
            if ( objectNum <= v18->objectNum )
              break;
            if ( (!v18->stale || v18->deleted) && v18->buffer.size != 0 )
              idSnapShot::SubmitObjectJob(
                this,
                submitDeltaJobsInfo: submitDeltaJobInfo,
                newState: nullptr,
                oldState: v18,
                baseObjParm: &v45,
                curObjParm: &v44,
                curHeader: v47,
                curObjDest: &v46,
                curlzwParm: v24,
                a10: v25,
                a11: v26,
                a12: v27,
                a13: v28,
                a14: v29,
                a15: v30,
                a16: v31,
                a17: v32,
                a18: v33,
                a19: v34,
                a20: v35,
                a21: v36,
                a22: v37,
                a23: v38,
                a24: v39,
                a25: v40,
                a26: v41,
                a27: v42,
                a28: &v43);
            ++v7;
            ++v15;
            if ( v7 >= v11 )
              goto LABEL_21;
          }
          if ( v7 < v11 )
          {
            TemplateState = list[v7];
            if ( objectNum == TemplateState->objectNum )
            {
              if ( TemplateState->buffer.size == 0 )
                TemplateState = idSnapShot::GetTemplateState(
                                  this,
                                  objNum: objectNum,
                                  templateStates: submitDeltaJobInfo->templateStates,
                                  newState: v13);
              idSnapShot::SubmitObjectJob(
                this,
                submitDeltaJobsInfo: submitDeltaJobInfo,
                newState: v13,
                oldState: TemplateState,
                baseObjParm: &v45,
                curObjParm: &v44,
                curHeader: v47,
                curObjDest: &v46,
                curlzwParm: v24,
                a10: v25,
                a11: v26,
                a12: v27,
                a13: v28,
                a14: v29,
                a15: v30,
                a16: v31,
                a17: v32,
                a18: v33,
                a19: v34,
                a20: v35,
                a21: v36,
                a22: v37,
                a23: v38,
                a24: v39,
                a25: v40,
                a26: v41,
                a27: v42,
                a28: &v43);
              ++v7;
            }
            else
            {
              v20 = idSnapShot::GetTemplateState(
                      this,
                      objNum: objectNum,
                      templateStates: submitDeltaJobInfo->templateStates,
                      newState: v13);
              idSnapShot::SubmitObjectJob(
                this,
                submitDeltaJobsInfo: submitDeltaJobInfo,
                newState: v13,
                oldState: v20,
                baseObjParm: &v45,
                curObjParm: &v44,
                curHeader: v47,
                curObjDest: &v46,
                curlzwParm: v24,
                a10: v25,
                a11: v26,
                a12: v27,
                a13: v28,
                a14: v29,
                a15: v30,
                a16: v31,
                a17: v32,
                a18: v33,
                a19: v34,
                a20: v35,
                a21: v36,
                a22: v37,
                a23: v38,
                a24: v39,
                a25: v40,
                a26: v41,
                a27: v42,
                a28: &v43);
            }
          }
        }
        else
        {
          v14 = idSnapShot::GetTemplateState(
                  this,
                  objNum: v13->objectNum,
                  templateStates: submitDeltaJobInfo->templateStates,
                  newState: this->objectStates.list[v12]);
          idSnapShot::SubmitObjectJob(
            this,
            submitDeltaJobsInfo: submitDeltaJobInfo,
            newState: v13,
            oldState: v14,
            baseObjParm: &v45,
            curObjParm: &v44,
            curHeader: v47,
            curObjDest: &v46,
            curlzwParm: v24,
            a10: v25,
            a11: v26,
            a12: v27,
            a13: v28,
            a14: v29,
            a15: v30,
            a16: v31,
            a17: v32,
            a18: v33,
            a19: v34,
            a20: v35,
            a21: v36,
            a22: v37,
            a23: v38,
            a24: v39,
            a25: v40,
            a26: v41,
            a27: v42,
            a28: &v43);
        }
      }
      else
      {
        idLib::Warning(fmt: "Snap obj [%d] state.size <= 0... skipping ", v13->objectNum);
      }
LABEL_21:
      ++v9;
      ++v12;
    }
    while ( v9 < this->objectStates.num );
  }
  oldSnap = submitDeltaJobInfo->oldSnap;
  if ( v7 < oldSnap->objectStates.num )
  {
    v22 = v7;
    do
    {
      v23 = oldSnap->objectStates.list[v22];
      if ( (!v23->stale || v23->deleted) && v23->buffer.size != 0 )
        idSnapShot::SubmitObjectJob(
          this,
          submitDeltaJobsInfo: submitDeltaJobInfo,
          newState: nullptr,
          oldState: v23,
          baseObjParm: &v45,
          curObjParm: &v44,
          curHeader: v47,
          curObjDest: &v46,
          curlzwParm: v24,
          a10: v25,
          a11: v26,
          a12: v27,
          a13: v28,
          a14: v29,
          a15: v30,
          a16: v31,
          a17: v32,
          a18: v33,
          a19: v34,
          a20: v35,
          a21: v36,
          a22: v37,
          a23: v38,
          a24: v39,
          a25: v40,
          a26: v41,
          a27: v42,
          a28: &v43);
      oldSnap = submitDeltaJobInfo->oldSnap;
      ++v7;
      ++v22;
    }
    while ( v7 < oldSnap->objectStates.num );
  }
  idSnapShot::SubmitLZWJob(
    this,
    writeDeltaInfo: submitDeltaJobInfo,
    baseObjParm: &v45,
    curObjParm: &v44,
    curlzwParm: &v43,
    saveDictionary: false);
}


// ========================================================================
// ?FindOrCreateObjectByID@idSnapShot@@AAAAAUobjectState_t@1@H@Z
// EA  : 0x8289ECF0
// RVA : 0x0089ECF0
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

idSnapShot::objectState_t *__fastcall idSnapShot::FindOrCreateObjectByID(idSnapShot *this, int objectNum)
{
  __int16 v3; // r29
  int v4; // r4
  int v5; // r3
  int v6; // r30
  idSnapShot::objectState_t *result; // r3
  idVec1 v8; // [sp+50h] [-30h] BYREF

  v3 = objectNum;
  v5 = idSnapShot::BinarySearch(this, objectNum);
  v6 = v5;
  if ( v5 < 0 || v5 >= this->objectStates.num || (result = this->objectStates.list[v5])->objectNum != v4 )
  {
    LODWORD(v8.x) = (idVec1)idBlockAlloc<idSnapShot::objectState_t,16,57>::Alloc(this: &this->allocatedObjs);
    *(_WORD *)v8.x = v3;
    idList<idVec1,116>::Insert((idList<idVec1,116> *)this, obj: &v8, index: v6);
    return this->objectStates.list[v6];
  }
  return result;
}


// ========================================================================
// ?Clear@idSnapShot@@QAAXXZ
// EA  : 0x8289ED70
// RVA : 0x0089ED70
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __fastcall idSnapShot::Clear(idSnapShot *this)
{
  int num; // r10
  int v3; // r26
  int v4; // r28
  idSnapShot::objectState_t *v5; // r10
  idSnapShot::objectBuffer_t *p_buffer; // r31
  unsigned __int8 *data; // r11
  unsigned int size; // r10
  int v9; // r8
  idSnapShot::objectState_t *v10; // r29
  unsigned __int8 *v11; // r11
  void **p_data; // r31
  unsigned int v13; // r10
  int v14; // r8
  int v15; // r10
  idSerializerLog *serializeLog; // r3

  num = this->objectStates.num;
  this->time = 0;
  v3 = 0;
  this->recvTime = 0;
  if ( num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = this->objectStates.list[v4];
      if ( v5 != nullptr )
      {
        p_buffer = &v5->buffer;
        data = v5->buffer.data;
        if ( data != nullptr )
        {
          size = v5->buffer.size;
          v9 = (unsigned __int8)(data[size] - 1);
          data[size] = v9;
          if ( v9 == 0 )
            idMem::Free(this: &mem, ptr: p_buffer->data, align: ALIGN_16);
          p_buffer->data = nullptr;
          p_buffer->size = 0;
        }
        v10 = this->objectStates.list[v4];
        if ( v10 != nullptr )
        {
          v11 = v10->buffer.data;
          p_data = (void **)&v10->buffer.data;
          if ( v11 != nullptr )
          {
            v13 = v10->buffer.size;
            v14 = (unsigned __int8)(v11[v13] - 1);
            v11[v13] = v14;
            if ( v14 == 0 )
              idMem::Free(this: &mem, ptr: *p_data, align: ALIGN_16);
            *p_data = nullptr;
            v10->buffer.size = 0;
          }
          *(_DWORD *)&v10->objectNum = this->allocatedObjs.free;
          v15 = this->allocatedObjs.active - 1;
          this->allocatedObjs.free = (idBlockAlloc<idSnapShot::objectState_t,16,57>::element_t *)v10;
          this->allocatedObjs.active = v15;
        }
        this->objectStates.list[v4] = nullptr;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->objectStates.num );
  }
  if ( this->objectStates.listStatic == 0 || this->objectStates.listStatic == 2 )
  {
    if ( this->objectStates.list != nullptr )
      idMem::Free(this: &mem, ptr: this->objectStates.list, align: ALIGN_16);
    this->objectStates.list = nullptr;
    this->objectStates.size = 0;
  }
  this->objectStates.num = 0;
  idBlockAlloc<idSnapShot::objectState_t,16,57>::Shutdown(this: &this->allocatedObjs);
  serializeLog = this->serializeLog;
  if ( serializeLog != nullptr )
  {
    idSerializerLog::Release(this: serializeLog);
    this->serializeLog = nullptr;
  }
}


// ========================================================================
// ??4idSnapShot@@QAAXABV0@@Z
// EA  : 0x8289EEE8
// RVA : 0x0089EEE8
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __fastcall idSnapShot::operator=(idSnapShot *this, const idSnapShot *other)
{
  int num; // r27
  int v5; // r29
  idSnapShot::objectState_t *v6; // r10
  idSnapShot::objectBuffer_t *p_buffer; // r31
  unsigned __int8 *data; // r11
  unsigned int size; // r10
  int v10; // r8
  idSnapShot::objectState_t *v11; // r30
  int v12; // r25
  int v13; // r26
  idSnapShot::objectState_t **v14; // r31
  idSnapShot::objectState_t *v15; // r29
  idSnapShot::objectBuffer_t *v16; // r27
  idSnapShot::objectState_t *v17; // r30
  void **p_data; // r31
  _BYTE *v19; // r11
  unsigned int v20; // r10
  int v21; // r8
  unsigned __int8 *v22; // r10
  bool v23; // cr58
  unsigned int v24; // r11
  idSerializerLog *serializeLog; // r31
  idSerializerLog *v26; // r3
  int v27; // [sp+50h] [-60h] BYREF

  if ( this != other )
  {
    num = other->objectStates.num;
    if ( num < this->objectStates.num )
    {
      v5 = num;
      do
      {
        v6 = this->objectStates.list[v5];
        if ( v6 != nullptr )
        {
          p_buffer = &v6->buffer;
          data = v6->buffer.data;
          if ( data != nullptr )
          {
            size = v6->buffer.size;
            v10 = (unsigned __int8)(data[size] - 1);
            data[size] = v10;
            if ( v10 == 0 )
              idMem::Free(this: &mem, ptr: p_buffer->data, align: ALIGN_16);
            p_buffer->data = nullptr;
            p_buffer->size = 0;
          }
          v11 = this->objectStates.list[v5];
          if ( v11 != nullptr )
          {
            idSnapShot::objectBuffer_t::_Release(this: &v11->buffer);
            *(_DWORD *)&v11->objectNum = this->allocatedObjs.free;
            this->allocatedObjs.free = (idBlockAlloc<idSnapShot::objectState_t,16,57>::element_t *)v11;
            --this->allocatedObjs.active;
          }
          this->objectStates.list[v5] = nullptr;
        }
        ++num;
        ++v5;
      }
      while ( num < this->objectStates.num );
    }
    v27 = 0;
    idList<idRenderModelCommitted *,5>::SetNum((idList<int,5> *)this, newNum: other->objectStates.num, initValue: &v27);
    v12 = 0;
    if ( this->objectStates.num > 0 )
    {
      v13 = 0;
      do
      {
        v15 = other->objectStates.list[v13];
        if ( this->objectStates.list[v13] == nullptr )
        {
          v14 = &this->objectStates.list[v13];
          *v14 = (idSnapShot::objectState_t *)idBlockAlloc<idSnapShot::objectState_t,16,57>::Alloc(this: &this->allocatedObjs);
        }
        v16 = &v15->buffer;
        v17 = this->objectStates.list[v13];
        p_data = (void **)&v17->buffer.data;
        v17->objectNum = v15->objectNum;
        if ( &v17->buffer != &v15->buffer )
        {
          v19 = *p_data;
          if ( *p_data != nullptr )
          {
            v20 = v17->buffer.size;
            v21 = (unsigned __int8)(v19[v20] - 1);
            v19[v20] = v21;
            if ( v21 == 0 )
              idMem::Free(this: &mem, ptr: *p_data, align: ALIGN_16);
            *p_data = nullptr;
            v17->buffer.size = 0;
          }
          v22 = v16->data;
          v23 = v16->data == nullptr;
          *p_data = v16->data;
          v24 = v15->buffer.size;
          v17->buffer.size = v24;
          if ( !v23 )
            ++v22[v24];
        }
        ++v12;
        ++v13;
        v17->visMask = v15->visMask;
        v17->stale = v15->stale;
        v17->deleted = v15->deleted;
        v17->changedCount = v15->changedCount;
        v17->expectedSequence = v15->expectedSequence;
        v17->createdFromTemplate = v15->createdFromTemplate;
      }
      while ( v12 < this->objectStates.num );
    }
    this->time = other->time;
    this->recvTime = other->recvTime;
    serializeLog = other->serializeLog;
    if ( serializeLog != nullptr )
    {
      idSerializerLog::AddRef(this: other->serializeLog);
      v26 = this->serializeLog;
      if ( v26 != nullptr )
        idSerializerLog::Release(this: v26);
      this->serializeLog = serializeLog;
    }
  }
}


// ========================================================================
// ?ReadDeltaForJob@idSnapShot@@QAA_NPBDHHPAV1@@Z
// EA  : 0x8289F130
// RVA : 0x0089F130
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
int __fastcall idSnapShot::ReadDeltaForJob(
        idSnapShot *this,
        const char *deltaMem,
        int deltaSize,
        int visIndex,
        idSnapShot *templateStates)
{
  __int64 v5; // r4
  int v6; // r5
  int v7; // r30
  char v8; // r6
  unsigned __int8 *v9; // r28
  idSnapShot *v10; // r7
  int v11; // r29
  int v12; // r15
  int v13; // r19
  float x; // r21
  idCVar *v15; // r26
  idCVar *v16; // r22
  int v17; // r30
  __int16 *v18; // r29
  __int64 v19; // r9
  int v20; // r3
  int v21; // r29
  idSnapShot *v22; // r28
  int v23; // r3
  int v24; // r30
  idSnapShot::objectState_t *v25; // r27
  unsigned int x_low; // r25
  int valueInteger; // r11
  unsigned int visMask; // r11
  int v29; // r10
  unsigned int v30; // r11
  _DWORD *v31; // r5
  int v32; // r3
  int v33; // r30
  char v34; // r24
  int v35; // r8
  __int64 v36; // r8
  int v37; // r6
  int v38; // r5
  unsigned int size; // r29
  unsigned __int8 *v40; // r26
  int v41; // r30
  unsigned __int8 v42; // r3
  char v43; // r11
  int v44; // r30
  int v45; // r10
  char v46; // r11
  void **p_data; // r30
  unsigned int v48; // r29
  _BYTE *v49; // r11
  unsigned int v50; // r10
  int v51; // r8
  __int64 v52; // r8
  int v53; // r6
  int v54; // r5
  int v55; // r10
  idVec1 v57; // [sp+50h] [-D970h] BYREF
  bool v58; // [sp+54h] [-D96Ch]
  idCVar *v59; // [sp+58h] [-D968h] BYREF
  __int64 v60; // [sp+60h] [-D960h] BYREF
  unsigned __int16 v61; // [sp+68h] [-D958h]
  __int16 v62; // [sp+6Ah] [-D956h] BYREF
  idMem *v63; // [sp+6Ch] [-D954h]
  const char *v64; // [sp+70h] [-D950h]
  const char *v65; // [sp+74h] [-D94Ch]
  const char *v66; // [sp+78h] [-D948h]
  const char *v67; // [sp+7Ch] [-D944h]
  const char *v68; // [sp+80h] [-D940h]
  const char *v69; // [sp+84h] [-D93Ch]
  const char *v70; // [sp+88h] [-D938h]
  const char *v71; // [sp+8Ch] [-D934h]
  const char *v72; // [sp+90h] [-D930h]
  const char *v73; // [sp+94h] [-D92Ch]
  const char *v74; // [sp+98h] [-D928h]
  const char *v75; // [sp+9Ch] [-D924h]
  idZeroRunLengthCompressor v76; // [sp+A0h] [-D920h] BYREF
  int v77; // [sp+C0h] [-D900h] BYREF
  idLZWCompressor v78; // [sp+30E0h] [-A8E0h] BYREF
  idSnapShot *v79; // [sp+D9D4h] [+14h]
  int v80; // [sp+D9E4h] [+24h]
  char v81; // [sp+D9EFh] [+2Fh]
  idSnapShot *v82; // [sp+D9F4h] [+34h]

  v5 = ((__int64 (*)(void))RtlCheckStack12)();
  v79 = (idSnapShot *)HIDWORD(v5);
  v80 = v6;
  v7 = HIDWORD(v5);
  v81 = v8;
  v9 = (unsigned __int8 *)v5;
  v82 = v10;
  v11 = v6;
  v58 = net_verboseSnapshotReport.valueInteger != 0;
  idCVar::SetBool(this: &net_verboseSnapshotReport, newValue: false, force: true);
  v76.zeroCount = 0;
  v76.destStart = nullptr;
  v78.lzwData = (lzwCompressionData_t *)&v77;
  idLZWCompressor::Start(this: &v78, data_: v9, maxSize_: v11, append: false);
  LODWORD(v57.x) = 0;
  v59 = nullptr;
  idLZWCompressor::ReadAgnostic<unsigned int>(this: &v78, c: (int *)&v57, ignoreOverflow: false);
  idLZWCompressor::ReadAgnostic<unsigned int>(this: &v78, c: (int *)&v59, ignoreOverflow: false);
  idLZWCompressor::ReadAgnostic<unsigned int>(this: &v78, c: (int *)(v7 + 40), ignoreOverflow: false);
  v61 = 0;
  v63 = &mem;
  v71 = "%25s: 0x";
  v70 = "    Obj %d Compressed: Size %d \n";
  v68 = "NEW STATE";
  v66 = "\n";
  v65 = "\nNew snapobject[%d] in snapshot %d/%d but no basestate found locally so creating new\n";
  v75 = "DELTA STATE";
  v64 = "SPAWN STATE";
  v73 = "Clearing old template state[%d] [%d<%d]\n";
  v12 = 12;
  v13 = 0;
  x = v57.x;
  v67 = "ERROR: unexpected not stale\n";
  v74 = "read delta: object %d no longer stale\n";
  v15 = &net_verboseSnapshot;
  v72 = "ERROR: unexpected already stale\n";
  v16 = v59;
  v69 = "read delta: object %d goes stale\n";
  v59 = &net_verboseSnapshot;
  while ( 1 )
  {
    v17 = 0;
    v18 = &v62;
    do
    {
      v20 = idLZWCompressor::ReadByte(this: &v78, ignoreOverflow: true);
      if ( v20 == -1 )
        return 0;
      ++v17;
      v18 = (__int16 *)((char *)v18 - 1);
      *(_BYTE *)v18 = v20;
    }
    while ( v17 < 2 );
    v21 = v12 + 2;
    v13 += v61;
    if ( v13 >= 0xFFFF )
      break;
    v22 = v79;
    v23 = idSnapShot::BinarySearch(this: v79, objectNum: v13);
    v24 = v23;
    if ( v23 >= 0 && v23 < v79->objectStates.num && v79->objectStates.list[v23]->objectNum == v13 )
    {
      v25 = v79->objectStates.list[v23];
    }
    else
    {
      LODWORD(v57.x) = (idVec1)idBlockAlloc<idSnapShot::objectState_t,16,57>::Alloc(this: &v79->allocatedObjs);
      *(_WORD *)v57.x = v13;
      idList<idVec1,116>::Insert(this: (idList<idVec1,116> *)v79, obj: &v57, index: v24);
      v25 = v79->objectStates.list[v24];
    }
    LODWORD(v57.x) = 0;
    idLZWCompressor::ReadAgnostic<unsigned int>(this: &v78, c: (int *)&v57, ignoreOverflow: false);
    v12 += 6;
    x_low = (unsigned int)LODWORD(v57.x);
    if ( LODWORD(v57.x) == -1 )
    {
      valueInteger = v15->valueInteger;
      if ( valueInteger > 0 )
      {
        idLib::Printf(fmt: v69, v13);
        valueInteger = v15->valueInteger;
      }
      if ( ((1 << v81) & v25->visMask) == 0 && valueInteger > 0 )
        idLib::Printf(fmt: v72);
      visMask = v25->visMask;
      v25->stale = true;
      v25->visMask = visMask & ~(1 << v81);
    }
    else
    {
      if ( LODWORD(v57.x) == -2 )
      {
        v29 = v15->valueInteger;
        if ( v29 > 0 )
        {
          idLib::Printf(fmt: v74, v13);
          v29 = v15->valueInteger;
        }
        if ( ((1 << v81) & v25->visMask) != 0 && v29 > 0 )
          idLib::Printf(fmt: v67);
        v30 = v25->visMask;
        v25->stale = false;
        v25->visMask = (1 << v81) | v30;
        idLZWCompressor::ReadAgnostic<unsigned int>(this: &v78, c: (int *)&v57, ignoreOverflow: false);
        v12 = v21 + 8;
        x_low = (unsigned int)LODWORD(v57.x);
      }
      v32 = idSnapShot::BinarySearch(this: v82, objectNum: v13);
      if ( v32 < 0 || v32 >= v31[1] || *(unsigned __int16 *)(v33 = *(_DWORD *)(4 * v32 + *v31)) != v13 )
        v33 = 0;
      if ( x_low != 0 )
      {
        v34 = 0;
        if ( v25->buffer.size != 0 )
        {
          v25->createdFromTemplate = false;
        }
        else
        {
          v25->createdFromTemplate = true;
          if ( v33 != 0 && *(_DWORD *)(v33 + 8) != 0 && (v35 = *(_DWORD *)(v33 + 24), SLODWORD(x) >= v35) )
          {
            idLib::PrintfIf(
              condition: net_ssTemplateDebug.valueInteger != 0,
              fmt: "\nAdding basestate for new object %d (for SS %d/%d. obj base created in ss %d) deltaSize: %d\n",
              v13,
              x,
              v16,
              v35,
              v80);
            idSnapShot::objectBuffer_t::operator=(
              this: &v25->buffer,
              other: (const idSnapShot::objectBuffer_t *)(v33 + 4));
            if ( net_ssTemplateDebug.valueInteger != 0 )
            {
              idSnapShot::objectState_t::Print(this: v25, name: v64, a3: v38, a4: v37, a5: v36);
              v34 = 1;
              idLib::Printf(fmt: v71, v75);
            }
          }
          else if ( net_ssTemplateDebug.valueInteger != 0 )
          {
            idLib::Printf(fmt: v65, v13, x, v16);
          }
        }
        LODWORD(v60) = x_low;
        HIDWORD(v60) = 0;
        idSnapShot::objectBuffer_t::Alloc(this: (idSnapShot::objectBuffer_t *)&v60, s: x_low);
        idZeroRunLengthCompressor::Start(this: &v76, dest_: nullptr, comp_: &v78, maxSize_: x_low);
        size = v25->buffer.size;
        if ( size >= x_low )
          size = x_low;
        v40 = (unsigned __int8 *)HIDWORD(v60);
        v41 = 0;
        if ( size != 0 )
        {
          do
          {
            v42 = idZeroRunLengthCompressor::ReadByte(this: &v76);
            v40[v41] = v25->buffer.data[v41] + v42;
            if ( v34 != 0 )
            {
              if ( v41 < net_ssTemplateDebug_start.valueInteger
                || (v43 = 1, v41 >= net_ssTemplateDebug_len.valueInteger + net_ssTemplateDebug_start.valueInteger) )
              {
                v43 = 0;
              }
              if ( v43 != 0 )
                idLib::Printf(fmt: "%02X", v42);
            }
            ++v41;
          }
          while ( v41 < size );
          v22 = v79;
        }
        if ( x_low > size )
        {
          idZeroRunLengthCompressor::ReadBytes(this: &v76, dest: &v40[size], count: x_low - size);
          if ( v34 != 0 )
          {
            v44 = size;
            if ( size < x_low )
            {
              v45 = net_ssTemplateDebug_start.valueInteger;
              do
              {
                if ( v44 < v45 || (v46 = 1, v44 >= net_ssTemplateDebug_len.valueInteger + v45) )
                  v46 = 0;
                if ( v46 != 0 )
                {
                  idLib::Printf(fmt: "%02X", v40[v44]);
                  v45 = net_ssTemplateDebug_start.valueInteger;
                }
                ++v44;
              }
              while ( v44 < x_low );
            }
          }
        }
        p_data = (void **)&v25->buffer.data;
        v48 = v60;
        if ( &v25->buffer != (idSnapShot::objectBuffer_t *)&v60 )
        {
          v49 = *p_data;
          if ( *p_data != nullptr )
          {
            v50 = v25->buffer.size;
            v51 = (unsigned __int8)(v49[v50] - 1);
            v49[v50] = v51;
            if ( v51 == 0 )
              idMem::Free(this: v63, ptr: *p_data, align: ALIGN_16);
            *p_data = nullptr;
            v25->buffer.size = 0;
          }
          *p_data = v40;
          v25->buffer.size = v48;
          if ( v40 != nullptr )
            ++v40[v48];
        }
        *(float *)&v25->changedCount = x;
        v12 += x_low;
        if ( v34 != 0 )
        {
          idLib::Printf(fmt: v66);
          idSnapShot::objectState_t::Print(this: v25, name: v68, a3: v54, a4: v53, a5: v52);
        }
        if ( v58 )
          idLib::Printf(fmt: v70, v13, v76.compressed);
        LODWORD(v57.x) = (idVec1)v22->serializeLog;
        if ( LODWORD(v57.x) != 0 )
          idSerializerLog::AddCompressionLog(this: (idSerializerLog *)v57.x, objID: v13, csize: v76.compressed);
        if ( v40 != nullptr )
        {
          v55 = (unsigned __int8)(v40[v48] - 1);
          v40[v48] = v55;
          if ( v55 == 0 )
            idMem::Free(this: v63, ptr: v40, align: ALIGN_16);
          HIDWORD(v60) = 0;
          LODWORD(v60) = 0;
        }
        v15 = v59;
      }
      else
      {
        v25->deleted = false;
        v25->stale = false;
        v25->changedCount = 0;
        v25->expectedSequence = 0;
        v25->visMask = 0;
        idSnapShot::objectBuffer_t::_Release(this: &v25->buffer);
        v25->createdFromTemplate = false;
        if ( v33 != 0 && *(_DWORD *)(v33 + 8) != 0 && *(_DWORD *)(v33 + 24) < (int)v16 )
        {
          idLib::PrintfIf(condition: net_ssTemplateDebug.valueInteger != 0, fmt: v73, v13);
          *(_BYTE *)(v33 + 17) = 0;
          *(_BYTE *)(v33 + 16) = 0;
          *(_DWORD *)(v33 + 20) = 0;
          *(_DWORD *)(v33 + 24) = 0;
          *(_DWORD *)(v33 + 12) = 0;
          idSnapShot::objectBuffer_t::_Release(this: (idSnapShot::objectBuffer_t *)(v33 + 4));
        }
      }
    }
  }
  if ( net_verboseSnapshotCompression.valueInteger != 0 )
  {
    LODWORD(v19) = v80;
    v60 = v19;
    idLib::Printf(
      fmt: "Snapshot (%d/%d). ReadSize: %d DeltaSize: %d Ratio: %.3f\n",
      x,
      v16,
      v12 + 2,
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v19
                                                  / (float)__SPAIR64__(
                                                             "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY",
                                                             v21)))),
      (float)((float)v19 / (float)__SPAIR64__("ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY", v21)));
  }
  return 1;
}


// ========================================================================
// __unwind$222383
// EA  : 0x8289F950
// RVA : 0x0089F950
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void _unwind_222383()
{
  idSnapShot::objectBuffer_t *v0; // r12

  idSnapShot::objectBuffer_t::~objectBuffer_t(this: v0 + 1236);
}


// ========================================================================
// ?S_AddObject@idSnapShot@@QAAPAUobjectState_t@1@HIPBDH0@Z
// EA  : 0x8289F980
// RVA : 0x0089F980
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

idSnapShot::objectState_t *__fastcall idSnapShot::S_AddObject(
        idSnapShot *this,
        int objectNum,
        unsigned int visMask,
        const char *data,
        size_t _size,
        const char *tag)
{
  idSnapShot::objectState_t *ObjectByID; // r3
  unsigned int size; // r11
  idSnapShot::objectState_t *v11; // r28
  unsigned __int8 *v12; // r3
  unsigned __int8 *v13; // r29
  unsigned int v14; // r11
  idSnapShot::objectBuffer_t v16[8]; // [sp+50h] [-40h] BYREF

  ObjectByID = idSnapShot::FindOrCreateObjectByID(this, objectNum);
  size = ObjectByID->buffer.size;
  v11 = ObjectByID;
  ObjectByID->visMask = visMask;
  if ( size == _size && (v12 = ObjectByID->buffer.data) != nullptr && v12[v11->buffer.size] == 1 )
  {
    memcpy(Dst: v12, Src: data, Size: _size);
  }
  else
  {
    v16[0].size = _size;
    v16[0].data = nullptr;
    idSnapShot::objectBuffer_t::Alloc(this: v16, s: _size);
    v13 = v16[0].data;
    memcpy(Dst: v16[0].data, Src: data, Size: _size);
    if ( &v11->buffer != v16 )
    {
      idSnapShot::objectBuffer_t::_Release(this: &v11->buffer);
      v14 = v16[0].size;
      v11->buffer.data = v13;
      v11->buffer.size = v14;
      if ( v13 != nullptr )
        ++v13[v14];
    }
    idSnapShot::objectBuffer_t::_Release(this: v16);
  }
  return v11;
}


// ========================================================================
// __unwind$222849
// EA  : 0x8289FA58
// RVA : 0x0089FA58
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void _unwind_222849()
{
  int v0; // r12

  idSnapShot::objectBuffer_t::~objectBuffer_t(this: (idSnapShot::objectBuffer_t *)(v0 - 144 + 80));
}


// ========================================================================
// ?CopyObject@idSnapShot@@QAA_NABV1@H_N@Z
// EA  : 0x8289FA80
// RVA : 0x0089FA80
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

int __fastcall idSnapShot::CopyObject(idSnapShot *this, idSnapShot *oldss, int objectNum, bool forceStale)
{
  int v7; // r5
  int v8; // r4
  int v9; // r3
  idSnapShot::objectState_t *v10; // r31
  idSnapShot::objectState_t *ObjectByID; // r30

  v9 = idSnapShot::BinarySearch(this: oldss, objectNum);
  if ( v9 < 0 )
    return 0;
  if ( v9 >= oldss->objectStates.num )
    return 0;
  v10 = oldss->objectStates.list[v9];
  if ( v10->objectNum != v7 )
    return 0;
  ObjectByID = idSnapShot::FindOrCreateObjectByID(this, objectNum: v8);
  idSnapShot::objectBuffer_t::operator=(this: &ObjectByID->buffer, other: &v10->buffer);
  ObjectByID->visMask = v10->visMask;
  ObjectByID->stale = v10->stale;
  ObjectByID->deleted = v10->deleted;
  ObjectByID->changedCount = v10->changedCount;
  ObjectByID->expectedSequence = v10->expectedSequence;
  ObjectByID->createdFromTemplate = v10->createdFromTemplate;
  if ( forceStale )
    ObjectByID->visMask = 0;
  return 1;
}


// ========================================================================
// ?CompareObject@idSnapShot@@QAAHPBV1@HHHH@Z
// EA  : 0x8289FB50
// RVA : 0x0089FB50
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

unsigned int __fastcall idSnapShot::CompareObject(
        idSnapShot *this,
        idSnapShot *oldss,
        int objectNum,
        int start,
        int end,
        int oldStart)
{
  unsigned int result; // r3
  int v12; // r5
  int v13; // r3
  idSnapShot::objectState_t *v14; // r7
  unsigned int size; // r6
  int v16; // r9
  unsigned int v17; // r8
  int v18; // r11
  int v19; // r11
  int v20; // ctr
  char v21; // r10

  if ( oldss == nullptr )
    return 0;
  idSnapShot::FindOrCreateObjectByID(this, objectNum);
  v13 = idSnapShot::BinarySearch(this: oldss, objectNum);
  if ( v13 >= 0 && v13 < oldss->objectStates.num && (v14 = oldss->objectStates.list[v13])->objectNum == objectNum )
  {
    size = v14->buffer.size;
    v16 = oldStart - start;
    v17 = *(_DWORD *)(v12 + 8);
    result = 0;
    v18 = size - (oldStart - start);
    if ( v17 <= v18 )
      v18 = *(_DWORD *)(v12 + 8);
    if ( end != 0 )
    {
      if ( v18 < end )
        end = v18;
    }
    else
    {
      end = v18;
      if ( v17 <= size )
        result = 0;
      else
        result = v17 - size;
    }
    v19 = start;
    if ( start < end )
    {
      v20 = end - start;
      do
      {
        if ( v19 < 0 || v19 >= (int)v17 || v19 + v16 < 0 || (v21 = 1, v19 + v16 >= (int)size) )
          v21 = 0;
        if ( v21 != 0 )
          result += v14->buffer.data[v19 + v16] != *(unsigned __int8 *)(*(_DWORD *)(v12 + 4) + v19);
        ++v19;
        --v20;
      }
      while ( v20 != 0 );
    }
  }
  else if ( end != 0 )
  {
    return end - start;
  }
  else
  {
    return *(_DWORD *)(v12 + 8);
  }
  return result;
}


// ========================================================================
// ??1idSnapShot@@QAA@XZ
// EA  : 0x8289FCC8
// RVA : 0x0089FCC8
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __fastcall idSnapShot::~idSnapShot(idSnapShot *this)
{
  idSnapShot::Clear(this);
  idBlockAlloc<idSnapShot::objectState_t,16,57>::Shutdown(this: &this->allocatedObjs);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$223177
// EA  : 0x8289FD14
// RVA : 0x0089FD14
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void _unwind_223177()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$223178
// EA  : 0x8289FD3C
// RVA : 0x0089FD3C
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void _unwind_223178()
{
  int v0; // r12

  idBlockAlloc<idSnapShot::objectState_t,16,57>::~idBlockAlloc<idSnapShot::objectState_t,16,57>(this: (idBlockAlloc<idSnapShot::objectState_t,16,57> *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// `dynamic initializer for 'net_visMaxDistance''
// EA  : 0x83345A70
// RVA : 0x01345A70
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_visMaxDistance__()
{
  idCVar::idCVar(
    this: &net_visMaxDistance,
    name: "net_visMaxDistance",
    value: "0",
    flags: 4,
    description: "distance based visibility (developer use)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_visMaxDistance__);
}


// ========================================================================
// `dynamic initializer for 'net_verboseSnapshot''
// EA  : 0x83345AC8
// RVA : 0x01345AC8
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_verboseSnapshot__()
{
  idCVar::idCVar(
    this: &net_verboseSnapshot,
    name: "net_verboseSnapshot",
    value: "0",
    flags: 2,
    description: "Verbose snapshot code to help debug snapshot problems. Greater the number greater the spam",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_verboseSnapshot__);
}


// ========================================================================
// `dynamic initializer for 'net_verboseSnapshotCompression''
// EA  : 0x83345B20
// RVA : 0x01345B20
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_verboseSnapshotCompression__()
{
  idCVar::idCVar(
    this: &net_verboseSnapshotCompression,
    name: "net_verboseSnapshotCompression",
    value: "0",
    flags: 2,
    description: "Verbose snapshot code to help debug snapshot problems. Greater the number greater the spam",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_verboseSnapshotCompression__);
}


// ========================================================================
// `dynamic initializer for 'net_verboseSnapshotReport''
// EA  : 0x83345B78
// RVA : 0x01345B78
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_verboseSnapshotReport__()
{
  idCVar::idCVar(
    this: &net_verboseSnapshotReport,
    name: "net_verboseSnapshotReport",
    value: "0",
    flags: 2,
    description: "Verbose snapshot code to help debug snapshot problems. Greater the number greater the spam",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_verboseSnapshotReport__);
}


// ========================================================================
// `dynamic initializer for 'net_ssTemplateDebug''
// EA  : 0x83345BD0
// RVA : 0x01345BD0
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_ssTemplateDebug__()
{
  idCVar::idCVar(
    this: &net_ssTemplateDebug,
    name: "net_ssTemplateDebug",
    value: "0",
    flags: 1,
    description: "Debug snapshot template states",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_ssTemplateDebug__);
}


// ========================================================================
// `dynamic initializer for 'net_ssTemplateDebug_len''
// EA  : 0x83345C28
// RVA : 0x01345C28
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_ssTemplateDebug_len__()
{
  idCVar::idCVar(
    this: &net_ssTemplateDebug_len,
    name: "net_ssTemplateDebug_len",
    value: "32",
    flags: 2,
    description: "Offset to start template state debugging",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_ssTemplateDebug_len__);
}


// ========================================================================
// `dynamic initializer for 'net_ssTemplateDebug_start''
// EA  : 0x83345C80
// RVA : 0x01345C80
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_ssTemplateDebug_start__()
{
  idCVar::idCVar(
    this: &net_ssTemplateDebug_start,
    name: "net_ssTemplateDebug_start",
    value: "0",
    flags: 2,
    description: "length of template state to print in debugging",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_ssTemplateDebug_start__);
}


// ========================================================================
// `dynamic initializer for 'register_SnapshotObjectJob''
// EA  : 0x83345CD8
// RVA : 0x01345CD8
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_SnapshotObjectJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_SnapshotObjectJob,
           function: (void (__fastcall *)(void *))SnapshotObjectJob,
           name: "SnapshotObjectJob");
}


// ========================================================================
// `dynamic initializer for 'register_LZWJob''
// EA  : 0x83345CF8
// RVA : 0x01345CF8
// PDB : w:\tech5\engine\network\snapshot.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_LZWJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_LZWJob,
           function: (void (__fastcall *)(void *))LZWJob,
           name: "LZWJob");
}

