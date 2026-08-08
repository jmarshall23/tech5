
// ========================================================================
// ?ObjectsSame@@YA_NAAUobjJobState_t@@0@Z
// EA  : 0x828A2D48
// RVA : 0x008A2D48
// PDB : w:\tech5\engine\network\snapshot_jobs.cpp
// ========================================================================

BOOL __fastcall ObjectsSame(objJobState_t *newState, objJobState_t *oldState)
{
  int size; // r9
  unsigned __int8 *data; // r10
  unsigned int v5; // r8
  unsigned __int8 *v6; // r11
  unsigned __int8 *v7; // r9
  int v8; // r7

  size = newState->size;
  if ( size != oldState->size )
    return false;
  data = oldState->data;
  v5 = 0;
  v6 = newState->data;
  if ( newState->size != 0 )
  {
    v7 = &v6[size];
    do
    {
      v8 = *data;
      v5 = *v6 - v8;
      if ( *v6 != v8 )
        break;
      ++v6;
      ++data;
    }
    while ( v6 != v7 );
  }
  return (_cntlzw(v5) & 0x20) != 0;
}


// ========================================================================
// FinishLZWStream
// EA  : 0x828A2DA8
// RVA : 0x008A2DA8
// PDB : w:\tech5\engine\network\snapshot_jobs.cpp
// ========================================================================

void __fastcall FinishLZWStream(lzwParm_t *parm, idLZWCompressor *lzwCompressor)
{
  lzwDelta_t *v4; // r31
  int bytesWritten; // r10

  if ( lzwCompressor->overflowed )
    idLZWCompressor::Restore(this: lzwCompressor);
  v4 = &parm->ioData->lzwDeltas[parm->ioData->numlzwDeltas];
  if ( idLZWCompressor::End(this: lzwCompressor) == -1 )
  {
    v4->offset = -1;
    v4->size = -1;
    v4->snapSequence = -1;
  }
  else
  {
    bytesWritten = lzwCompressor->lzwData->bytesWritten;
    v4->offset = parm->ioData->lzwBytes;
    v4->size = bytesWritten;
    v4->snapSequence = parm->ioData->snapSequence;
    parm->ioData->lzwBytes += bytesWritten;
  }
  ++parm->ioData->numlzwDeltas;
}


// ========================================================================
// ?SnapshotObjectJob@@YAXPAUobjParms_t@@@Z
// EA  : 0x828A2E68
// RVA : 0x008A2E68
// PDB : w:\tech5\engine\network\snapshot_jobs.cpp
// ========================================================================

void __fastcall SnapshotObjectJob(objParms_t *parms)
{
  objHeader_t *destHeader; // r28
  int visIndex; // r10
  objJobState_t *p_newState; // r31
  unsigned __int8 *dest; // r25
  objJobState_t *p_oldState; // r26
  int size; // r11
  char v7; // r30
  unsigned __int8 v8; // r27
  int valid; // r29
  BOOL v10; // r11
  bool v11; // r10
  unsigned __int16 objectNum; // r11
  int v13; // r3
  unsigned int flags; // r10
  int v15; // r11
  unsigned int v16; // r10
  int v17; // r29
  int i; // r30
  int v19; // r5
  int v20; // r3
  int v21; // r11
  int j; // ctr
  unsigned __int8 v23; // r8
  unsigned __int8 v24; // r7
  signed int v25; // r5
  idZeroRunLengthCompressor v26[4]; // [sp+50h] [-60h] BYREF

  destHeader = parms->destHeader;
  visIndex = parms->visIndex;
  p_newState = &parms->newState;
  dest = parms->dest;
  p_oldState = &parms->oldState;
  destHeader->flags = 0;
  if ( parms->newState.valid != 0 )
    size = parms->newState.size;
  else
    size = 0;
  destHeader->size = size;
  destHeader->data = dest;
  destHeader->csize = 0;
  destHeader->objID = -1;
  v7 = 0;
  destHeader->tag = -1414664179;
  v8 = 0;
  valid = p_newState->valid;
  v26[0].zeroCount = 0;
  v26[0].destStart = nullptr;
  if ( valid != 0 )
  {
    if ( p_oldState->valid == 0 )
    {
LABEL_19:
      objectNum = p_newState->objectNum;
      goto LABEL_21;
    }
    if ( visIndex > 0 )
    {
      v10 = (parms->oldState.visMask & (1 << visIndex)) != 0;
      v11 = ((_cntlzw(parms->oldState.size) & 0x20) != 0) != ((_cntlzw(parms->newState.size) & 0x20) != 0)
         || (parms->newState.visMask & (1 << visIndex)) != 0;
      if ( v10 )
      {
        if ( v11 )
          goto LABEL_17;
        v8 = 0;
      }
      else
      {
        if ( !v11 )
        {
LABEL_9:
          destHeader->flags |= 0x20u;
          return;
        }
        if ( !v11 )
          goto LABEL_17;
        v8 = 1;
      }
      v7 = 1;
    }
LABEL_17:
    if ( v7 == 0 && ObjectsSame(newState: p_newState, oldState: p_oldState) )
      goto LABEL_9;
    goto LABEL_19;
  }
  objectNum = parms->oldState.objectNum;
LABEL_21:
  destHeader->objID = objectNum;
  if ( p_newState->valid != 0 )
  {
    if ( p_oldState->valid != 0 )
    {
      v15 = destHeader->flags | 0x10;
      destHeader->flags = v15;
      if ( v7 == 0 || (destHeader->flags = (((_cntlzw(v8) & 0x20) == 0) + 1) | v15, v8 != 0) )
      {
        v16 = p_oldState->size;
        if ( p_newState->size < v16 )
          LOWORD(v16) = p_newState->size;
        v17 = (unsigned __int16)v16;
        idZeroRunLengthCompressor::Start(
          this: v26,
          dest_: dest,
          comp_: nullptr,
          maxSize_: (p_newState->size + 15) & 0x1FFF0);
        for ( i = 0; i < v17; ++i )
          idZeroRunLengthCompressor::WriteByte(this: v26, value: p_newState->data[i] - p_oldState->data[i]);
        v19 = p_newState->size - v17;
        if ( v19 > 0 )
          idZeroRunLengthCompressor::WriteBytes(this: v26, src: &p_newState->data[v17], count: v19);
        v20 = idZeroRunLengthCompressor::End(this: v26);
        destHeader->csize = v20;
        if ( v20 == -1 )
        {
          v21 = 0;
          if ( v17 > 0 )
          {
            for ( j = v17; j != 0; --j )
            {
              v23 = p_oldState->data[v21];
              v24 = p_newState->data[v21++];
              *dest++ = v24 - v23;
            }
          }
          v25 = p_newState->size - v17;
          if ( v25 > 0 )
            memcpy(Dst: dest, Src: &p_newState->data[v17], Size: v25);
        }
      }
    }
    else
    {
      idZeroRunLengthCompressor::Start(
        this: v26,
        dest_: dest,
        comp_: nullptr,
        maxSize_: (p_newState->size + 15) & 0x1FFF0);
      idZeroRunLengthCompressor::WriteBytes(this: v26, src: p_newState->data, count: p_newState->size);
      v13 = idZeroRunLengthCompressor::End(this: v26);
      flags = destHeader->flags;
      destHeader->csize = v13;
      destHeader->flags = flags | 4;
      if ( v13 == -1 )
        memcpy(Dst: dest, Src: p_newState->data, Size: p_newState->size);
    }
  }
  else
  {
    destHeader->flags |= 8u;
  }
}


// ========================================================================
// NewLZWStream
// EA  : 0x828A31C0
// RVA : 0x008A31C0
// PDB : w:\tech5\engine\network\snapshot_jobs.cpp
// ========================================================================

void __fastcall NewLZWStream(lzwParm_t *parm, idLZWCompressor *lzwCompressor)
{
  int v4; // r29
  unsigned __int16 *p_lastObjId; // r28
  int v6; // r29
  bool *p_saveDictionary; // r28
  int i; // r31
  int *p_baseTime; // r29

  idLZWCompressor::Start(
    this: lzwCompressor,
    data_: &parm->ioData->lzwMem[parm->ioData->lzwBytes],
    maxSize_: parm->ioData->maxlzwMem - parm->ioData->lzwBytes,
    append: false);
  v4 = 0;
  parm->ioData->lastObjId = 0;
  ++parm->ioData->snapSequence;
  p_lastObjId = &parm->ioData->lastObjId;
  do
  {
    if ( lzwCompressor->overflowed )
      break;
    p_lastObjId = (unsigned __int16 *)((char *)p_lastObjId - 1);
    idLZWCompressor::WriteByte(this: lzwCompressor, value: *(_BYTE *)p_lastObjId);
    ++v4;
  }
  while ( v4 < 4 );
  v6 = 0;
  p_saveDictionary = &parm->saveDictionary;
  do
  {
    if ( lzwCompressor->overflowed )
      break;
    idLZWCompressor::WriteByte(this: lzwCompressor, value: *--p_saveDictionary);
    ++v6;
  }
  while ( v6 < 4 );
  p_baseTime = &parm->baseTime;
  for ( i = 0; i < 4; ++i )
  {
    if ( lzwCompressor->overflowed )
      break;
    p_baseTime = (int *)((char *)p_baseTime - 1);
    idLZWCompressor::WriteByte(this: lzwCompressor, value: *(_BYTE *)p_baseTime);
  }
}


// ========================================================================
// ?LZWJobInternal@@YAXPAUlzwParm_t@@I@Z
// EA  : 0x828A32B0
// RVA : 0x008A32B0
// PDB : w:\tech5\engine\network\snapshot_jobs.cpp
// ========================================================================

void __fastcall LZWJobInternal(
        lzwParm_t *parm,
        unsigned int dmaTag,
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
        unsigned int size,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39)
{
  lzwParm_t *v39; // r3
  int *p_numlzwDeltas; // r11
  lzwParm_t *v41; // r28
  BOOL fragmented; // r10
  int v43; // r26
  int v44; // r22
  int v45; // r25
  objHeader_t *v46; // r29
  int objID; // r11
  int v48; // r31
  char *v49; // r30
  unsigned int flags; // r11
  int v51; // r31
  int *v52; // r30
  unsigned int v53; // r11
  int v54; // r31
  int *v55; // r30
  int csize; // r5
  unsigned __int8 *data; // r31
  int v58; // r31
  char *v59; // r30

  v39 = (lzwParm_t *)((int (*)(void))RtlCheckStack12)();
  p_numlzwDeltas = &v39->ioData->numlzwDeltas;
  v41 = v39;
  if ( *p_numlzwDeltas <= 0 )
  {
    fragmented = v39->fragmented;
    a39 = p_numlzwDeltas[11];
    if ( fragmented )
      idLZWCompressor::Start(
        this: (idLZWCompressor *)&a39,
        data_: &v39->ioData->lzwMem[v39->ioData->lzwBytes],
        maxSize_: v39->ioData->maxlzwMem - v39->ioData->lzwBytes,
        append: true);
    else
      NewLZWStream(parm: v39, lzwCompressor: (idLZWCompressor *)&a39);
    v43 = 0;
    v44 = 0;
    if ( v41->numObjects <= 0 )
    {
LABEL_32:
      if ( v41->saveDictionary )
      {
        v41->ioData->lzwDmaOut = v41->ioData->lzwBytes + *(_DWORD *)(a39 + 12316);
      }
      else
      {
        v58 = 0;
        v59 = (char *)&size + 2;
        HIWORD(size) = -1 - v41->ioData->lastObjId;
        do
        {
          if ( HIBYTE(STACK[0xD1B0]) != 0 )
            break;
          idLZWCompressor::WriteByte(this: (idLZWCompressor *)&a39, value: *--v59);
          ++v58;
        }
        while ( v58 < 2 );
        FinishLZWStream(parm: v41, lzwCompressor: (idLZWCompressor *)&a39);
        v41->ioData->lzwDmaOut = v41->ioData->lzwBytes;
        v41->ioData->fullSnap = true;
      }
    }
    else
    {
      v45 = 0;
      while ( HIBYTE(STACK[0xD1B0]) == 0 && *(_DWORD *)(a39 + 12316) < v41->ioData->optimalLength )
      {
        if ( v43 > 0 )
          idLZWCompressor::Save(this: (idLZWCompressor *)&a39);
        v46 = &v41->headers[v45];
        objID = v46->objID;
        if ( objID != -1 )
        {
          ++v43;
          v48 = 0;
          v49 = (char *)&size + 2;
          HIWORD(size) = objID - v41->ioData->lastObjId;
          do
          {
            if ( HIBYTE(STACK[0xD1B0]) != 0 )
              break;
            idLZWCompressor::WriteByte(this: (idLZWCompressor *)&a39, value: *--v49);
            ++v48;
          }
          while ( v48 < 2 );
          v41->ioData->lastObjId = v46->objID;
          flags = v46->flags;
          if ( (flags & 3) != 0 )
          {
            v51 = 0;
            v52 = &a28;
            size = flags | 0xFFFFFFFE;
            do
            {
              if ( HIBYTE(STACK[0xD1B0]) != 0 )
                break;
              v52 = (int *)((char *)v52 - 1);
              idLZWCompressor::WriteByte(this: (idLZWCompressor *)&a39, value: *(_BYTE *)v52);
              ++v51;
            }
            while ( v51 < 4 );
          }
          v53 = v46->flags;
          if ( (v53 & 1) == 0 )
          {
            v54 = 0;
            v55 = &a28;
            if ( (v53 & 8) != 0 )
            {
              size = 0;
              do
              {
                if ( HIBYTE(STACK[0xD1B0]) != 0 )
                  break;
                v55 = (int *)((char *)v55 - 1);
                idLZWCompressor::WriteByte(this: (idLZWCompressor *)&a39, value: *(_BYTE *)v55);
                ++v54;
              }
              while ( v54 < 4 );
            }
            else
            {
              size = v46->size;
              do
              {
                if ( HIBYTE(STACK[0xD1B0]) != 0 )
                  break;
                v55 = (int *)((char *)v55 - 1);
                idLZWCompressor::WriteByte(this: (idLZWCompressor *)&a39, value: *(_BYTE *)v55);
                ++v54;
              }
              while ( v54 < 4 );
              csize = v46->csize;
              data = v46->data;
              if ( csize == -1 )
              {
                a31 = 0;
                a33 = 0;
                idZeroRunLengthCompressor::Start(
                  this: (idZeroRunLengthCompressor *)&a31,
                  dest_: nullptr,
                  comp_: (idLZWCompressor *)&a39,
                  maxSize_: 0xFFFF);
                idZeroRunLengthCompressor::WriteBytes(
                  this: (idZeroRunLengthCompressor *)&a31,
                  src: data,
                  count: v46->size);
                idZeroRunLengthCompressor::End(this: (idZeroRunLengthCompressor *)&a31);
              }
              else
              {
                idLZWCompressor::Write(this: (idLZWCompressor *)&a39, data: v46->data, length: csize);
              }
            }
          }
        }
        ++v44;
        ++v45;
        if ( v44 >= v41->numObjects )
          goto LABEL_32;
      }
      FinishLZWStream(parm: v41, lzwCompressor: (idLZWCompressor *)&a39);
      v41->ioData->lzwDmaOut = v41->ioData->lzwBytes;
    }
  }
}


// ========================================================================
// ?LZWJob@@YAXPAUlzwParm_t@@@Z
// EA  : 0x828A35C0
// RVA : 0x008A35C0
// PDB : w:\tech5\engine\network\snapshot_jobs.cpp
// ========================================================================

void __fastcall LZWJob(
        lzwParm_t *parm,
        int a2,
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
        unsigned int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39)
{
  LZWJobInternal(
    parm,
    dmaTag: 0,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    a15,
    a16,
    a17,
    a18,
    a19,
    a20,
    a21,
    a22,
    a23,
    a24,
    a25,
    a26,
    size: a27,
    a28,
    a29,
    a30,
    a31,
    a32,
    a33,
    a34,
    a35,
    a36,
    a37,
    a38,
    a39);
}

