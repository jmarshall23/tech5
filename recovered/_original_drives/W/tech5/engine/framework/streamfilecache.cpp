
// ========================================================================
// ?CacheLineQuickSort@@YAXPAUcacheLineSort_t@@_J@Z
// EA  : 0x826A00D8
// RVA : 0x006A00D8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall CacheLineQuickSort(cacheLineSort_t *a, int a2, __int64 num)
{
  int v3; // r4
  int v4; // r4
  int v5; // r31 OVERLAPPED
  int v6; // r4
  __int64 i; // r10 OVERLAPPED
  int v8; // r11
  int v9; // r4
  __int64 sort; // r8 OVERLAPPED
  cacheLineSort_t *v11; // r7
  __int64 v12; // r29
  __int64 v13; // r27 OVERLAPPED
  int v14; // r30 OVERLAPPED
  __int64 v15; // r29
  int v16; // r4
  _BYTE *v17; // r8
  __int64 v18; // r6
  __int64 v19; // r8
  int v20; // r10
  int v21; // r6
  cacheLineSort_t *v22; // r9
  cacheLineSort_t *v23; // r9
  cacheLineSort_t *v24; // r10
  __int128 v25; // r9
  int v26; // r4
  int v27; // r4
  _QWORD v28[130]; // [sp+20h] [-840h] BYREF
  _QWORD v29[134]; // [sp+430h] [-430h] BYREF

  if ( v3 > 0 )
  {
    LODWORD(num) = v4 - 1;
    v5 = 0;
    v6 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        HIDWORD(i) = v5;
        v8 = num;
        if ( (int)num - v5 < 4 || v9 >= 127 )
          break;
        LODWORD(i) = num + v5;
        LODWORD(i) = ((unsigned __int64)i >> 63) + num + v5;
        sort = a[i >> 1].sort;
        do
        {
          v11 = &a[HIDWORD(i)];
          for ( i = v11->sort; (int)i > (int)sort; i = v11->sort )
            v11 = &a[HIDWORD(i) + 1];
          LODWORD(i) = &a[v8];
          for ( *(__int64 *)((char *)&num + 4) = *(_QWORD *)(i + 8);
                SHIDWORD(num) < (int)sort;
                *(__int64 *)((char *)&num + 4) = *(_QWORD *)(i + 8) )
          {
            LODWORD(i) = &a[--v8];
          }
          if ( SHIDWORD(i) > v8 )
            break;
          v12 = v11->sort;
          HIDWORD(v12) = v28;
          v13 = *(_QWORD *)i;
          ++HIDWORD(i);
          --v8;
          v28[0] = v11->index;
          v28[1] = v12;
          *(__int64 *)((char *)&num + 4) = v28[0];
          v14 = v12;
          v11->index = v13;
          v15 = *(_QWORD *)(i + 8);
          v11->sort = v15;
          *(_QWORD *)i = *(__int64 *)((char *)&num + 4);
          *(_QWORD *)(i + 8) = *(_QWORD *)&v14;
        }
        while ( SHIDWORD(i) < v8 );
        for ( ; LODWORD(a[v8].sort) == (_DWORD)sort; --v8 )
        {
          if ( v5 >= v8 )
            break;
        }
        for ( *(__int64 *)((char *)&num - 4) = a[HIDWORD(i)].sort;
              HIDWORD(sort) == (_DWORD)sort;
              *(__int64 *)((char *)&num - 4) = a[HIDWORD(i)].sort )
        {
          if ( SHIDWORD(i) >= (int)num )
            break;
          ++HIDWORD(i);
        }
        LODWORD(i) = 8 * v16;
        v17 = v29;
        ++v16;
        *(_QWORD *)((char *)v29 + i) = num;
        LODWORD(num) = v8;
        *(_QWORD *)((char *)&v28[2] + i) = *(__int64 *)((char *)&i + 4);
      }
      if ( v5 < (int)num )
      {
        HIDWORD(v18) = v5 + 1;
        do
        {
          HIDWORD(v19) = v5;
          v20 = HIDWORD(v18);
          if ( SHIDWORD(v18) <= v8 )
          {
            v21 = v8 - HIDWORD(v18) + 1;
            do
            {
              v22 = &a[HIDWORD(v19)];
              v19 = a[v20].sort;
              if ( SHIDWORD(v22->sort) < SLODWORD(v22->sort) )
                HIDWORD(v19) = v20;
              --v21;
              ++v20;
            }
            while ( v21 != 0 );
          }
          v23 = &a[HIDWORD(v19)];
          v24 = &a[v8--];
          DWORD1(v25) = HIDWORD(v23->index);
          v23->index = v24->index;
          v18 = v24->sort;
          v23->sort = v18;
          *((_QWORD *)&v25 + 1) = *(_QWORD *)(DWORD1(v25) + 8);
          v24->index = *(_QWORD *)((char *)&v25 + 4);
          v24->sort = v25;
        }
        while ( v8 > v5 );
      }
      if ( --v26 < 0 )
        break;
      *(_QWORD *)&v5 = v28[v27 + 2];
      num = v29[v27];
    }
  }
}


// ========================================================================
// ?Condense@idLocklessCacheLineMRU@@QAAXXZ
// EA  : 0x826A0338
// RVA : 0x006A0338
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idLocklessCacheLineMRU::Condense(idLocklessCacheLineMRU *this)
{
  volatile int *p_queueStart; // r27
  int queueEnd; // r28
  int v4; // r31
  idFileCacheLine *v5; // r30
  idFileCacheLine *v6; // r3

  p_queueStart = &this->queueStart;
  queueEnd = this->queueEnd;
  LOWORD(v4) = queueEnd;
  if ( queueEnd != this->queueStart )
  {
    do
    {
      v4 = ((_WORD)v4 - 1) & 0x1FFF;
      v5 = this->queue[v4];
      if ( v5 != nullptr )
      {
        v6 = (idFileCacheLine *)Sys_InterlockedExchangePointer(ptr: (void **)&this->queue[v4], exchange: nullptr);
        if ( v6 == v5 )
        {
          queueEnd = (queueEnd - 1) & 0x1FFF;
          v6->indexMRU = queueEnd;
          __lwsync();
          this->queue[queueEnd] = v6;
        }
      }
    }
    while ( v4 != *p_queueStart );
  }
  __lwsync();
  *p_queueStart = queueEnd;
}


// ========================================================================
// ?Find@idLocklessCacheLineHash@@QAAPAVidFileCacheLine@@HH@Z
// EA  : 0x826A03E0
// RVA : 0x006A03E0
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

idFileCacheLine *__fastcall idLocklessCacheLineHash::Find(idLocklessCacheLineHash *this, int fileID, int fileLine)
{
  int v3; // r10
  int v4; // r11
  int v5; // r9
  int v6; // r8
  int v7; // r11

  v3 = 0;
  v4 = (32 * (_WORD)fileID + (_WORD)fileLine) & 0xFFF;
  v5 = 4 * v4;
  v6 = this->numHashEntries[v4];
  if ( v6 <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = *(int *)((char *)this->hash + ((4 * (v3 + v5)) & 0xFFFC));
    if ( v7 != 0 && *(_DWORD *)(v7 + 12) == fileLine && *(_DWORD *)(v7 + 8) == fileID )
      break;
    if ( ++v3 >= v6 )
      return nullptr;
  }
  return *(idFileCacheLine **)((char *)this->hash + ((4 * (v3 + v5)) & 0xFFFC));
}


// ========================================================================
// ?Clear@hdCache_t@idStreamControlThread@@QAAX_N@Z
// EA  : 0x826A0450
// RVA : 0x006A0450
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamControlThread::hdCache_t::Clear(idStreamControlThread::hdCache_t *this, bool clearFileIDs)
{
  int v3; // r8
  unsigned __int8 *hdMRU; // r9
  int v5; // r11
  int i; // ctr
  int *v7; // r11
  int j; // ctr

  this->magic1 = 1346782003;
  if ( clearFileIDs )
    memset(Dst: this->cachedFiles, Val: 0, Size: sizeof(this->cachedFiles));
  this->lineSize = 0x10000;
  memset(Dst: this->hdLines, Val: 255, Size: sizeof(this->hdLines));
  v3 = 512;
  hdMRU = this->hdMRU;
  do
  {
    v5 = 0;
    for ( i = 32; i != 0; --i )
    {
      hdMRU[v5] = 31 - v5;
      ++v5;
    }
    --v3;
    hdMRU += 32;
  }
  while ( v3 != 0 );
  v7 = &this->hdLinesWritten[511];
  for ( j = 512; j != 0; --j )
  {
    *(v7 - 511) = 0;
    *++v7 = 0;
  }
  this->magic2 = 1346782003;
}


// ========================================================================
// ?Shutdown@idStreamControlThread@@QAAXXZ
// EA  : 0x826A0538
// RVA : 0x006A0538
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamControlThread::Shutdown(idStreamControlThread *this)
{
  idOpticalDiskStreamThread **p_opticalDiskThread; // r29
  idOpticalDiskStreamThread *opticalDiskThread; // r3
  idHardDiskStreamThread *hardDiskThread; // r3

  p_opticalDiskThread = &this->opticalDiskThread;
  opticalDiskThread = this->opticalDiskThread;
  if ( opticalDiskThread != nullptr )
    ((void (__fastcall *)(idOpticalDiskStreamThread *, int))opticalDiskThread->dtr_idSysThread)(
      a1: opticalDiskThread,
      a2: 1);
  *p_opticalDiskThread = nullptr;
  hardDiskThread = this->hardDiskThread;
  if ( hardDiskThread != nullptr )
    ((void (__fastcall *)(idHardDiskStreamThread *, int))hardDiskThread->dtr_idSysThread)(a1: hardDiskThread, a2: 1);
  this->hardDiskThread = nullptr;
  idMem::Free(this: &mem, ptr: this->hdcBuffer, align: ALIGN_16);
}


// ========================================================================
// ?WaitForCompletion@idStreamControlThread@@QAAXXZ
// EA  : 0x826A05C8
// RVA : 0x006A05C8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamControlThread::WaitForCompletion(idStreamControlThread *this)
{
  idSysThread **p_opticalDiskThread; // r19
  idSysThread **p_hardDiskThread; // r18
  volatile int *p_uncachedRequestQueueEnd; // r17
  volatile int *p_uncachedRequestQueueStart; // r16

  this->threadSignalled = false;
  __lwsync();
  p_opticalDiskThread = &this->opticalDiskThread;
  p_hardDiskThread = &this->hardDiskThread;
  p_uncachedRequestQueueEnd = &this->uncachedRequestQueueEnd;
  p_uncachedRequestQueueStart = &this->uncachedRequestQueueStart;
  while ( 1 )
  {
    idSysThread::WaitForThread(this);
    if ( *p_opticalDiskThread != nullptr )
      idSysThread::WaitForThread(this: *p_opticalDiskThread);
    if ( *p_hardDiskThread != nullptr )
      idSysThread::WaitForThread(this: *p_hardDiskThread);
    if ( *p_uncachedRequestQueueStart == *p_uncachedRequestQueueEnd
      && this->uncachedOpticalDiskRequestQueueStart == this->uncachedOpticalDiskRequestQueueEnd
      && this->uncachedHardDiskRequestQueueStart == this->uncachedHardDiskRequestQueueEnd
      && this->requestQueueStart == this->requestQueueEnd
      && this->opticalDiskReadQueue.queueStart == this->opticalDiskReadQueue.queueEnd
      && this->opticalDiskFinishedQueue.queueStart == this->opticalDiskFinishedQueue.queueEnd
      && this->hardDiskReadQueue.queueStart == this->hardDiskReadQueue.queueEnd
      && this->hardDiskWriteQueue.queueStart == this->hardDiskWriteQueue.queueEnd
      && this->hardDiskFinishedQueue.queueStart == this->hardDiskFinishedQueue.queueEnd
      && !this->threadSignalled )
    {
      break;
    }
    this->threadSignalled = false;
    idSysThread::SignalWork(this);
  }
}


// ========================================================================
// ?UncachedBackgroundRead@idStreamControlThread@@QAAXPAVidFile@@_JHPAPAXW4memTag_t@@PC_N@Z
// EA  : 0x826A0750
// RVA : 0x006A0750
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamControlThread::UncachedBackgroundRead(
        idStreamControlThread *this,
        idFile *cacheFile,
        __int64 ofs,
        int length,
        void **dest,
        memTag_t tag,
        volatile bool *completionFlag)
{
  volatile int *p_uncachedRequestQueueEnd; // r30
  volatile int *p_uncachedRequestQueueStart; // r28
  unsigned __int64 v13; // r27
  char *v15; // r31

  p_uncachedRequestQueueEnd = &this->uncachedRequestQueueEnd;
  p_uncachedRequestQueueStart = &this->uncachedRequestQueueStart;
  v13 = __PAIR64__(ofs, HIDWORD(ofs));
  if ( ((this->uncachedRequestQueueEnd + 1) & 0x7FF) == this->uncachedRequestQueueStart )
  {
    do
    {
      idLib::Warning(fmt: "idStreamControlThread::UncachedBackgroundRead: queue is full");
      mgthread_sleep(ms: 1);
    }
    while ( ((*p_uncachedRequestQueueEnd + 1) & 0x7FF) == *p_uncachedRequestQueueStart );
  }
  v15 = (char *)this + 32 * *p_uncachedRequestQueueEnd;
  *((_DWORD *)v15 + 1046) = cacheFile->GetDevice(this: cacheFile);
  *((_DWORD *)v15 + 1047) = cacheFile;
  *((_QWORD *)v15 + 524) = v13;
  *((_DWORD *)v15 + 1050) = HIDWORD(v13);
  *((_DWORD *)v15 + 1051) = length;
  *((_DWORD *)v15 + 1052) = dest;
  *((_DWORD *)v15 + 1053) = tag;
  __lwsync();
  *p_uncachedRequestQueueEnd = (*p_uncachedRequestQueueEnd + 1) & 0x7FF;
}


// ========================================================================
// ?BatchUncachedBackgroundRead@idStreamControlThread@@QAAXPAVidFile@@QA_JQAHQAPAPAXW4memTag_t@@QAPC_NH@Z
// EA  : 0x826A0830
// RVA : 0x006A0830
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamControlThread::BatchUncachedBackgroundRead(
        idStreamControlThread *this,
        idFile *cacheFile,
        __int64 *ofs,
        char *length,
        void ***dest,
        memTag_t tag,
        volatile bool **completionFlag,
        int numReads)
{
  fsDevice_t v16; // r20
  int v17; // r31
  volatile int *p_uncachedRequestQueueStart; // r23
  volatile int *p_uncachedRequestQueueEnd; // r29
  __int64 *v20; // r28
  int v21; // r26
  int v22; // r25
  int v23; // r11
  char *v24; // r11
  int v25; // r8

  v16 = cacheFile->GetDevice(this: cacheFile);
  v17 = 0;
  if ( numReads > 0 )
  {
    p_uncachedRequestQueueStart = &this->uncachedRequestQueueStart;
    p_uncachedRequestQueueEnd = &this->uncachedRequestQueueEnd;
    v20 = ofs - 1;
    v21 = length - (char *)dest;
    v22 = (char *)completionFlag - (char *)dest;
    do
    {
      while ( ((*p_uncachedRequestQueueEnd + v17 + 1) & 0x7FF) == *p_uncachedRequestQueueStart )
      {
        idLib::Warning(fmt: "idStreamControlThread::BatchUncachedBackgroundRead: queue is full");
        mgthread_sleep(ms: 1);
      }
      v23 = *p_uncachedRequestQueueEnd + v17++;
      v24 = (char *)this + ((32 * v23) & 0xFFE0);
      *((_DWORD *)v24 + 1046) = v16;
      *((_DWORD *)v24 + 1047) = cacheFile;
      *((_QWORD *)v24 + 524) = *++v20;
      *((_DWORD *)v24 + 1050) = *(void ***)((char *)dest + v21);
      *((_DWORD *)v24 + 1051) = *dest;
      *((_DWORD *)v24 + 1052) = tag;
      v25 = *(int *)((char *)dest++ + v22);
      *((_DWORD *)v24 + 1053) = v25;
    }
    while ( v17 < numReads );
  }
  __lwsync();
  this->uncachedRequestQueueEnd = (this->uncachedRequestQueueEnd + numReads) & 0x7FF;
}


// ========================================================================
// ?AddCacheLineRequest@idStreamControlThread@@AAAXPAVidFile@@HHHH@Z
// EA  : 0x826A0960
// RVA : 0x006A0960
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamControlThread::AddCacheLineRequest(
        idStreamControlThread *this,
        idStreamControlThread_vtbl *filePtr,
        idStreamControlThread_vtbl *fileID,
        idStreamControlThread_vtbl *fileLine,
        idStreamControlThread_vtbl *priority,
        idStreamControlThread_vtbl *persistence)
{
  volatile int *p_requestQueueEnd; // r31
  volatile int *p_requestQueueStart; // r29
  idStreamControlThread_vtbl **v14; // r10

  p_requestQueueEnd = &this->requestQueueEnd;
  p_requestQueueStart = &this->requestQueueStart;
  if ( ((this->requestQueueEnd + 1) & 0x1FFF) == this->requestQueueStart )
  {
    do
    {
      idLib::Warning(fmt: "idStreamControlThread::AddCacheLineRequest: queue is full");
      idSysThread::SignalWork(this);
      idSysThread::WaitForThread(this);
    }
    while ( ((*p_requestQueueEnd + 1) & 0x1FFF) == *p_requestQueueStart );
  }
  v14 = (idStreamControlThread_vtbl **)((char *)this + 20 * *p_requestQueueEnd);
  v14[50204] = filePtr;
  v14[50205] = fileID;
  v14[50206] = fileLine;
  v14[50207] = priority;
  v14[50208] = persistence;
  __lwsync();
  *p_requestQueueEnd = (*p_requestQueueEnd + 1) & 0x1FFF;
}


// ========================================================================
// ?BatchFreeMemory@idStreamControlThread@@QAAXQAPAXH@Z
// EA  : 0x826A0A30
// RVA : 0x006A0A30
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamControlThread::BatchFreeMemory(idStreamControlThread *this, void **block, int numBlocks)
{
  int v5; // r30
  void **v6; // r29
  __int16 v7; // r10

  v5 = 0;
  if ( numBlocks > 0 )
  {
    v6 = block - 1;
    do
    {
      while ( ((this->freeMemoryRequestQueueEnd + v5 + 1) & 0x3FF) == this->freeMemoryRequestQueueStart )
      {
        idLib::Warning(fmt: "idStreamControlThread::BatchFreeMemory: queue is full");
        mgthread_sleep(ms: 1);
      }
      ++v6;
      v7 = this->freeMemoryRequestQueueEnd + v5++;
      this->freeMemoryRequestQueue[v7 & 0x3FF].block = *v6;
    }
    while ( v5 < numBlocks );
  }
  __lwsync();
  this->freeMemoryRequestQueueEnd = (this->freeMemoryRequestQueueEnd + numBlocks) & 0x3FF;
}


// ========================================================================
// ?NewFrame@idStreamFileCache@@QAAXXZ
// EA  : 0x826A0AE8
// RVA : 0x006A0AE8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamFileCache::NewFrame(idStreamFileCache *this)
{
  this->controlThread->newFrame = true;
  idStreamFileLog::NoteFrame(this: &streamFileLog);
}


// ========================================================================
// ?ServiceBink@idStreamFileCache@@QAAXW4fsDevice_t@@@Z
// EA  : 0x826A0B00
// RVA : 0x006A0B00
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamFileCache::ServiceBink(idStreamFileCache *this, fsDevice_t source)
{
  volatile idStreamControlThread::serviceBink_t v2; // r10

  v2 = SERVICE_BINK_OPTICAL_DISK;
  if ( source != FS_DEVICE_OPTICAL_DISK_DRIVE )
    v2 = SERVICE_BINK_HARD_DISK;
  this->controlThread->serviceBink = v2;
}


// ========================================================================
// ?Next@idLocklessCacheLineQueueS@@QAAPAVidFileCacheLine@@XZ
// EA  : 0x826A0B20
// RVA : 0x006A0B20
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

idFileCacheLine *__fastcall idLocklessCacheLineQueueS::Next(idLocklessCacheLineQueueS *this)
{
  idFileCacheLine *v2; // r31

  if ( this->queueStart == this->queueEnd )
    return nullptr;
  v2 = this->queue[this->queueStart];
  this->queueStart = (this->queueStart + 1) & 0xFFF;
  __lwsync();
  Sys_InterlockedDecrement(value: &this->numLines.value);
  return v2;
}


// ========================================================================
// ?Add@idLocklessCacheLineQueueM@@QAAXPAVidFileCacheLine@@@Z
// EA  : 0x826A0B98
// RVA : 0x006A0B98
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idLocklessCacheLineQueueM::Add(idLocklessCacheLineQueueM *this, idFileCacheLine *line)
{
  volatile int queueEnd; // r31
  void **i; // r28
  char *j; // r31

  queueEnd = this->queueEnd;
  for ( i = (void **)&this->queueEnd;
        Sys_InterlockedCompareExchange(
          ptr: (void **)((char *)this->queue + ((4 * queueEnd) & 0x3FFC)),
          comparand: nullptr,
          exchange: line) != nullptr;
        ++queueEnd )
  {
    ;
  }
  for ( j = (char *)*i; *(idFileCacheLine **)((char *)this->queue + ((4 * (_DWORD)*i) & 0x3FFC)) != nullptr; j = (char *)*i )
  {
    if ( Sys_InterlockedCompareExchange(ptr: i, comparand: j, exchange: j + 1) != j )
      break;
  }
  Sys_InterlockedIncrement(value: &this->numLines.value);
}


// ========================================================================
// ?Next@idLocklessCacheLineQueueM@@QAAPAVidFileCacheLine@@XZ
// EA  : 0x826A0C40
// RVA : 0x006A0C40
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

idFileCacheLine *__fastcall idLocklessCacheLineQueueM::Next(idLocklessCacheLineQueueM *this)
{
  volatile int queueStart; // r31
  void **p_queueStart; // r29
  int v5; // r11
  int v6; // r31

  queueStart = this->queueStart;
  p_queueStart = (void **)&this->queueStart;
  if ( queueStart == this->queueEnd )
    return nullptr;
  while ( Sys_InterlockedCompareExchange(
            ptr: p_queueStart,
            comparand: (void *)queueStart,
            exchange: (void *)(queueStart + 1)) != (void *)queueStart )
  {
    queueStart = (volatile int)*p_queueStart;
    if ( *p_queueStart == (void *)this->queueEnd )
      return nullptr;
  }
  v5 = (4 * queueStart) & 0x3FFC;
  v6 = *(int *)((char *)this->queue + v5);
  *(idFileCacheLine **)((char *)this->queue + v5) = nullptr;
  Sys_InterlockedDecrement(value: &this->numLines.value);
  return (idFileCacheLine *)v6;
}


// ========================================================================
// ?Sort@idLocklessCacheLineMRU@@QAAXXZ
// EA  : 0x826A0CC0
// RVA : 0x006A0CC0
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idLocklessCacheLineMRU::Sort(
        idLocklessCacheLineMRU *this,
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
        int a27)
{
  idLocklessCacheLineMRU *v27; // r29
  int value; // r28
  __int64 v29; // r6 OVERLAPPED
  __int64 v30; // r4 OVERLAPPED
  int *p_queueEnd; // r30
  int v32; // r31
  int queueStart; // r11
  __int64 v34; // r10
  __int64 v35; // r7
  int v36; // r5
  int v37; // r27
  int *v38; // r28
  void **v39; // r3
  idFileCacheLine *v40; // r30
  idFileCacheLine *v41; // r3

  v27 = (idLocklessCacheLineMRU *)((int (*)(void))RtlCheckStack12)();
  idLocklessCacheLineMRU::Condense(this: v27);
  value = v27->replacementCount.value;
  HIDWORD(v30) = Sys_Milliseconds();
  p_queueEnd = (int *)&v27->queueEnd;
  v32 = 0;
  queueStart = v27->queueStart;
  if ( queueStart != v27->queueEnd )
  {
    HIDWORD(v34) = &a25;
    LODWORD(v34) = 4 * queueStart;
    do
    {
      LODWORD(v34) = *(idFileCacheLine **)((char *)v27->queue + v34);
      if ( (_DWORD)v34 != 0 )
      {
        LODWORD(v35) = queueStart;
        HIDWORD(v35) = *(_DWORD *)(v34 + 36);
        ++v32;
        v36 = *(_DWORD *)(v34 + 32);
        LODWORD(v30) = value - *(_DWORD *)(v34 + 40);
        *(_QWORD *)(HIDWORD(v34) + 8) = v35;
        LODWORD(v29) = HIDWORD(v30) - HIDWORD(v35);
        HIDWORD(v29) = v36 - v30;
        v30 = *(__int64 *)((char *)&v29 + 4) << 32;
        LODWORD(v34) = v30 - v29;
        HIDWORD(v34) += 16;
        *(_QWORD *)HIDWORD(v34) = v34;
      }
      queueStart = ((_WORD)queueStart + 1) & 0x1FFF;
      LODWORD(v34) = 4 * queueStart;
    }
    while ( queueStart != *p_queueEnd );
  }
  CacheLineQuickSort(a: (cacheLineSort_t *)&a27, a2: v32, num: v29);
  *p_queueEnd = (*p_queueEnd + v32) & 0x1FFF;
  __lwsync();
  v37 = *p_queueEnd;
  if ( v32 > 0 )
  {
    v38 = &a27;
    do
    {
      v39 = (void **)&v27->queue[v38[1]];
      v40 = (idFileCacheLine *)*v39;
      if ( *v39 != nullptr )
      {
        v41 = (idFileCacheLine *)Sys_InterlockedExchangePointer(ptr: v39, exchange: nullptr);
        if ( v41 == v40 )
        {
          v37 = (v37 - 1) & 0x1FFF;
          v41->indexMRU = v37;
          __lwsync();
          v27->queue[v37] = v41;
        }
      }
      --v32;
      v38 += 4;
    }
    while ( v32 != 0 );
  }
  __lwsync();
  v27->queueStart = v37;
}


// ========================================================================
// ?AddMRU@idLocklessCacheLineMRU@@QAAXPAVidFileCacheLine@@@Z
// EA  : 0x826A0E18
// RVA : 0x006A0E18
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idLocklessCacheLineMRU::AddMRU(idLocklessCacheLineMRU *this, idFileCacheLine *line)
{
  volatile int *p_queueStart; // r11
  volatile int *p_queueEnd; // r31
  volatile int v6; // r10

  p_queueStart = &this->queueStart;
  p_queueEnd = &this->queueEnd;
  if ( this->queueStart != this->queueEnd )
  {
    do
    {
      if ( this->queue[*p_queueStart] != nullptr )
        break;
      *p_queueStart = (*p_queueStart + 1) & 0x1FFF;
    }
    while ( *p_queueStart != *p_queueEnd );
  }
  __lwsync();
  if ( *p_queueEnd + 4096 == *p_queueStart )
    goto LABEL_8;
  v6 = *p_queueEnd;
  if ( *p_queueEnd < *p_queueStart )
    v6 += 0x2000;
  if ( v6 - *p_queueStart > 2 * this->numLines.value )
LABEL_8:
    idLocklessCacheLineMRU::Condense(this);
  line->indexMRU = *p_queueEnd;
  this->queue[*p_queueEnd] = line;
  __lwsync();
  *p_queueEnd = (*p_queueEnd + 1) & 0x1FFF;
  Sys_InterlockedIncrement(value: &this->numLines.value);
}


// ========================================================================
// ?NextLRU@idLocklessCacheLineMRU@@QAAPAVidFileCacheLine@@W4memoryType_t@@@Z
// EA  : 0x826A0F10
// RVA : 0x006A0F10
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

idFileCacheLine *__fastcall idLocklessCacheLineMRU::NextLRU(idLocklessCacheLineMRU *this, memoryType_t memType)
{
  volatile int *p_queueEnd; // r24
  int queueStart; // r27
  idFileCacheLine *v6; // r31
  idFileCacheLine *v7; // r3
  idFileCacheLine *v8; // r30

  p_queueEnd = &this->queueEnd;
  queueStart = this->queueStart;
  if ( queueStart == this->queueEnd )
    return nullptr;
  while ( 1 )
  {
    v6 = this->queue[queueStart];
    if ( v6 != nullptr && (memType == MEMORY_TYPE_ANY || v6->memType == memType) )
    {
      if ( Sys_InterlockedIncrement(value: &v6->modifyLock.value) == 1 )
        break;
LABEL_9:
      Sys_InterlockedDecrement(value: &v6->modifyLock.value);
    }
    queueStart = (queueStart + 1) & 0x1FFF;
    if ( queueStart == *p_queueEnd )
      return nullptr;
  }
  if ( Sys_InterlockedDecrement(value: &v6->pinned.value) != -1
    || (v7 = (idFileCacheLine *)Sys_InterlockedCompareExchange(
                                  ptr: (void **)&this->queue[queueStart],
                                  comparand: v6,
                                  exchange: nullptr),
        v8 = v7,
        v7 != v6) )
  {
    Sys_InterlockedIncrement(value: &v6->pinned.value);
    goto LABEL_9;
  }
  v7->indexMRU = -1;
  Sys_InterlockedDecrement(value: &this->numLines.value);
  Sys_InterlockedIncrement(value: &this->replacementCount.value);
  return v8;
}


// ========================================================================
// ?CountMemType@idLocklessCacheLineMRU@@QBAHW4memoryType_t@@@Z
// EA  : 0x826A1010
// RVA : 0x006A1010
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

int __fastcall idLocklessCacheLineMRU::CountMemType(idLocklessCacheLineMRU *this, const memoryType_t memType)
{
  volatile int *p_queueEnd; // r8
  int result; // r3
  int queueStart; // r11
  volatile int queueEnd; // r7
  int v7; // r10
  idFileCacheLine *v8; // r10

  p_queueEnd = &this->queueEnd;
  queueStart = this->queueStart;
  queueEnd = this->queueEnd;
  result = 0;
  if ( queueStart != queueEnd )
  {
    v7 = queueStart;
    do
    {
      v8 = this->queue[v7];
      if ( v8 != nullptr && v8->memType == memType && v8->pinned.value <= 0 )
        ++result;
      queueStart = ((_WORD)queueStart + 1) & 0x1FFF;
      v7 = queueStart;
    }
    while ( queueStart != *p_queueEnd );
  }
  return result;
}


// ========================================================================
// ?MaxHashChain@idLocklessCacheLineHash@@QBAHXZ
// EA  : 0x826A1080
// RVA : 0x006A1080
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

int __fastcall idLocklessCacheLineHash::MaxHashChain(idLocklessCacheLineHash *this)
{
  int v1; // r11
  int *v2; // r9
  int i; // ctr

  v1 = 0;
  v2 = &this->numHashEntries[1];
  for ( i = 1024; i != 0; --i )
  {
    if ( v1 <= *(v2 - 1) )
      v1 = *(v2 - 1);
    if ( v1 <= *v2 )
      v1 = *v2;
    if ( v1 <= v2[1] )
      v1 = v2[1];
    if ( v1 <= v2[2] )
      v1 = v2[2];
    v2 += 4;
  }
  return v1;
}


// ========================================================================
// ?Condense@idLocklessCacheLineHash@@QAAXXZ
// EA  : 0x826A10E8
// RVA : 0x006A10E8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idLocklessCacheLineHash::Condense(idLocklessCacheLineHash *this)
{
  int *numHashEntries; // r26
  int v3; // r20
  int i; // r29
  int v5; // r24
  int v6; // r22
  int v7; // r23
  int v8; // r25
  int v9; // r9
  idFileCacheLine *v10; // r30

  numHashEntries = this->numHashEntries;
  v3 = 0;
  for ( i = 0; i < 4096; ++i )
  {
    v5 = i * 4;
    v6 = numHashEntries[i] - 1;
    if ( v6 < 0 )
      goto LABEL_17;
    v7 = i * 4 + v6;
    while ( 1 )
    {
      v8 = (4 * v7) & 0xFFFC;
      v9 = v7 & 0x3FFF;
      v10 = *(idFileCacheLine **)((char *)this->hash + v8);
      if ( v10 != nullptr )
        break;
      --numHashEntries[i];
LABEL_14:
      --v6;
      --v7;
      if ( v6 < 0 )
        goto LABEL_17;
    }
    if ( ((32 * v10->fileID + v10->fileLine) & 0xFFF) != v3 )
    {
      --numHashEntries[i];
      goto LABEL_14;
    }
    if ( v5 != v9 )
    {
      while ( this->hash[v5] != nullptr )
      {
        v5 = (v5 + 1) & 0x3FFF;
        if ( v5 == v9 )
          goto LABEL_17;
      }
      if ( Sys_InterlockedIncrement(value: &v10->modifyLock.value) == 1 )
      {
        *(idFileCacheLine **)((char *)this->hash + v8) = nullptr;
        this->hash[v5] = v10;
        __lwsync();
        --numHashEntries[i];
        Sys_InterlockedDecrement(value: &v10->modifyLock.value);
        goto LABEL_14;
      }
      Sys_InterlockedDecrement(value: &v10->modifyLock.value);
    }
LABEL_17:
    ++v3;
  }
}


// ========================================================================
// ?Remove@idLocklessCacheLineHash@@QAAXPAVidFileCacheLine@@@Z
// EA  : 0x826A1200
// RVA : 0x006A1200
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idLocklessCacheLineHash::Remove(idLocklessCacheLineHash *this, idFileCacheLine *line)
{
  int fileID; // r7
  int v3; // r10
  int fileLine; // r6
  int v5; // r11
  int v6; // r8
  int v7; // r5
  int v8; // r9
  int v9; // r11

  fileID = line->fileID;
  v3 = 0;
  fileLine = line->fileLine;
  v5 = (32 * (_WORD)fileID + (_WORD)fileLine) & 0xFFF;
  v6 = 4 * v5;
  v7 = this->numHashEntries[v5];
  if ( v7 > 0 )
  {
    while ( 1 )
    {
      v8 = (4 * (v3 + v6)) & 0xFFFC;
      v9 = *(int *)((char *)this->hash + v8);
      if ( v9 != 0 && *(_DWORD *)(v9 + 8) == fileID && *(_DWORD *)(v9 + 12) == fileLine )
        break;
      if ( ++v3 >= v7 )
        return;
    }
    *(idFileCacheLine **)((char *)this->hash + v8) = nullptr;
    Sys_InterlockedDecrement(value: &this->numLines.value);
  }
}


// ========================================================================
// ??0idStreamControlThread@@QAA@XZ
// EA  : 0x826A1280
// RVA : 0x006A1280
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

idStreamControlThread *__fastcall idStreamControlThread::idStreamControlThread(idStreamControlThread *this)
{
  idStreamControlThread::cachedFileID_t v2; // r31

  idSysThread::idSysThread(this);
  v2.id = 0;
  this->newFrame = false;
  this->threadSignalled = false;
  this->numFreeLRU = 0;
  this->freeMemoryRequestQueueStart = 0;
  this->freeMemoryRequestQueueEnd = 0;
  this->serviceBink = SERVICE_BINK_NONE;
  this->serviceBinkOpticalDisk = false;
  this->serviceBinkHardDisk = false;
  this->uncachedRequestQueueStart = 0;
  this->uncachedRequestQueueEnd = 0;
  this->uncachedOpticalDiskRequestQueueStart = 0;
  this->uncachedOpticalDiskRequestQueueEnd = 0;
  this->lastServiceTime = 0;
  this->uncachedHardDiskRequestQueueStart = 0;
  this->uncachedHardDiskRequestQueueEnd = 0;
  this->requestQueueStart = 0;
  this->__vftable = (idStreamControlThread_vtbl *)&idStreamControlThread::`vftable';
  this->requestQueueEnd = 0;
  memset(Dst: &this->opticalDiskReadQueue, Val: 0, Size: 0x4000u);
  this->opticalDiskReadQueue.queueStart = 0;
  this->opticalDiskReadQueue.queueEnd = 0;
  this->opticalDiskReadQueue.numLines.value = 0;
  memset(Dst: &this->opticalDiskFinishedQueue, Val: 0, Size: 0x4000u);
  this->opticalDiskFinishedQueue.queueStart = 0;
  this->opticalDiskFinishedQueue.queueEnd = 0;
  this->opticalDiskFinishedQueue.numLines.value = 0;
  memset(Dst: &this->hardDiskReadQueue, Val: 0, Size: 0x4000u);
  this->hardDiskReadQueue.queueStart = 0;
  this->hardDiskReadQueue.queueEnd = 0;
  this->hardDiskReadQueue.numLines.value = 0;
  memset(Dst: &this->hardDiskWriteQueue, Val: 0, Size: 0x4000u);
  this->hardDiskWriteQueue.queueStart = 0;
  this->hardDiskWriteQueue.queueEnd = 0;
  this->hardDiskWriteQueue.numLines.value = 0;
  memset(Dst: &this->hardDiskFinishedQueue, Val: 0, Size: 0x4000u);
  this->hardDiskFinishedQueue.queueStart = 0;
  this->hardDiskFinishedQueue.queueEnd = 0;
  this->hardDiskFinishedQueue.numLines.value = 0;
  this->cacheLineAlloc = nullptr;
  memset(Dst: &this->cacheLineFree, Val: 0, Size: 0x4000u);
  this->cacheLineFree.queueStart = 0;
  this->cacheLineFree.queueEnd = 0;
  this->cacheLineFree.numLines.value = 0;
  memset(Dst: &this->cacheLineMRU, Val: 0, Size: 0x8000u);
  this->cacheLineMRU.queueStart = 0;
  v2.uniqID = (unsigned int)&this->cacheLineHash;
  this->cacheLineMRU.queueEnd = 0;
  this->cacheLineMRU.numLines.value = 0;
  this->cacheLineMRU.replacementCount.value = 0;
  memset(Dst: &this->cacheLineHash, Val: 0, Size: 0x10000u);
  memset(Dst: this->cacheLineHash.numHashEntries, Val: 0, Size: sizeof(this->cacheLineHash.numHashEntries));
  this->cacheLineHash.numLines.value = 0;
  this->opticalDiskThread = nullptr;
  this->hardDiskThread = nullptr;
  this->totalUsedLineBuffers.value = 0;
  this->providedLineBuffersTotal.value = 0;
  this->providedLineBuffersUsed.value = 0;
  this->hdcHeaderFile = nullptr;
  this->providedLineBuffersMaxCommitted = -1;
  this->hdcHeaderSize = 0;
  this->hdcBuffer = nullptr;
  memset(Dst: this->hdcFiles, Val: 0, Size: sizeof(this->hdcFiles));
  this->hdc = nullptr;
  memset(Dst: this->hdcFileAccessed, Val: 0, Size: sizeof(this->hdcFileAccessed));
  this->cachedFileIDs[0] = v2;
  this->cachedFileIDs[1] = v2;
  this->cachedFileIDs[2] = v2;
  this->cachedFileIDs[3] = v2;
  this->cachedFileIDIndex = 0;
  return this;
}


// ========================================================================
// ?ShutdownHDC@idStreamControlThread@@QAAXXZ
// EA  : 0x826A1560
// RVA : 0x006A1560
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamControlThread::ShutdownHDC(idStreamControlThread *this)
{
  idFile **p_hdcHeaderFile; // r30
  int v3; // r30
  unsigned __int8 **p_hdcBuffer; // r31
  unsigned __int8 *v5; // r3

  p_hdcHeaderFile = &this->hdcHeaderFile;
  if ( this->hdcHeaderFile != nullptr )
  {
    idStreamControlThread::WaitForCompletion(this);
    idStreamControlThread::hdCache_t::Clear(this: this->hdc, clearFileIDs: false);
    if ( *p_hdcHeaderFile != nullptr )
      ((void (__fastcall *)(idFile *, int))(*p_hdcHeaderFile)->dtr_idFile)(a1: *p_hdcHeaderFile, a2: 1);
    *p_hdcHeaderFile = nullptr;
    v3 = 512;
    p_hdcBuffer = &this->hdcBuffer;
    do
    {
      v5 = p_hdcBuffer[1];
      if ( v5 != nullptr )
        (**(void (__fastcall ***)(unsigned __int8 *, int))v5)(a1: v5, a2: 1);
      --v3;
      *++p_hdcBuffer = nullptr;
    }
    while ( v3 != 0 );
  }
}


// ========================================================================
// ?FindHardDiskCacheLine@idStreamControlThread@@AAAHHH@Z
// EA  : 0x826A1608
// RVA : 0x006A1608
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

int __fastcall idStreamControlThread::FindHardDiskCacheLine(idStreamControlThread *this, int fileID, int fileLine)
{
  idStreamControlThread::hdCache_t **p_hdc; // r8
  int v4; // r11
  int v5; // r6
  int v7; // r9
  int i; // ctr

  if ( fc_useHdc.valueInteger == 0 || this->hdcHeaderFile == nullptr )
    return -1;
  p_hdc = &this->hdc;
  v4 = (32 * (16 * fileID + fileLine / 4)) & 0x3FE0;
  v5 = 0;
  while ( this->hdc->hdLines[v4 + v5] != ((fileID << 24) | fileLine) )
  {
    if ( ++v5 >= 32 )
      return -1;
  }
  v7 = 0;
  for ( i = 8; i != 0; --i )
  {
    if ( (*p_hdc)->hdMRU[v7 + v4] < (unsigned int)(*p_hdc)->hdMRU[v5 + v4] )
      ++(*p_hdc)->hdMRU[v7 + v4];
    if ( (*p_hdc)->hdMRU[v7 + 1 + v4] < (unsigned int)(*p_hdc)->hdMRU[v5 + v4] )
      ++(*p_hdc)->hdMRU[v7 + 1 + v4];
    if ( (*p_hdc)->hdMRU[v7 + 2 + v4] < (unsigned int)(*p_hdc)->hdMRU[v5 + v4] )
      ++(*p_hdc)->hdMRU[v7 + 2 + v4];
    if ( (*p_hdc)->hdMRU[v7 + 3 + v4] < (unsigned int)(*p_hdc)->hdMRU[v5 + v4] )
      ++(*p_hdc)->hdMRU[v7 + 3 + v4];
    v7 += 4;
  }
  (*p_hdc)->hdMRU[v5 + v4] = 0;
  return v5 + v4;
}


// ========================================================================
// ?AllocHardDiskCacheLine@idStreamControlThread@@AAAHHH@Z
// EA  : 0x826A17E8
// RVA : 0x006A17E8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

int __fastcall idStreamControlThread::AllocHardDiskCacheLine(idStreamControlThread *this, int fileID, int fileLine)
{
  int v4; // r10
  int v5; // ctr
  int result; // r3
  int v7; // r11
  idStreamControlThread::hdCache_t **p_hdc; // r9

  if ( fc_useHdc.valueInteger == 0 || this->hdcHeaderFile == nullptr )
    return -1;
  v4 = (32 * (16 * fileID + fileLine / 4)) & 0x3FE0;
  v5 = 8;
  result = v4;
  v7 = 0;
  p_hdc = &this->hdc;
  do
  {
    if ( (*p_hdc)->hdMRU[v7 + v4] == 31 )
      result = v7 + v4;
    else
      ++(*p_hdc)->hdMRU[v7 + v4];
    if ( (*p_hdc)->hdMRU[v7 + 1 + v4] == 31 )
      result = v7 + v4 + 1;
    else
      ++(*p_hdc)->hdMRU[v7 + 1 + v4];
    if ( (*p_hdc)->hdMRU[v7 + 2 + v4] == 31 )
      result = v7 + v4 + 2;
    else
      ++(*p_hdc)->hdMRU[v7 + 2 + v4];
    if ( (*p_hdc)->hdMRU[v7 + 3 + v4] == 31 )
      result = v7 + v4 + 3;
    else
      ++(*p_hdc)->hdMRU[v7 + 3 + v4];
    v7 += 4;
    --v5;
  }
  while ( v5 != 0 );
  (*p_hdc)->hdLines[result] = (fileID << 24) | fileLine;
  (*p_hdc)->hdMRU[result] = 0;
  return result;
}


// ========================================================================
// ?AllocProvidedLineBuffer@idStreamControlThread@@AAAPAEXZ
// EA  : 0x826A19B0
// RVA : 0x006A19B0
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

unsigned __int8 *__fastcall idStreamControlThread::AllocProvidedLineBuffer(idStreamControlThread *this)
{
  int v2; // r29
  void **i; // r31
  void *v4; // r30

  if ( this->providedLineBuffersTotal.value <= 0
    || this->providedLineBuffersMaxCommitted >= 0
    && this->providedLineBuffersUsed.value >= this->providedLineBuffersMaxCommitted )
  {
    return nullptr;
  }
  v2 = 0;
  for ( i = (void **)this->providedLineBuffers; ; ++i )
  {
    v4 = *i;
    if ( *i != nullptr && Sys_InterlockedCompareExchange(ptr: i, comparand: *i, exchange: nullptr) == v4 )
      break;
    if ( ++v2 >= 1024 )
      return nullptr;
  }
  Sys_InterlockedIncrement(value: &this->providedLineBuffersUsed.value);
  return (unsigned __int8 *)v4;
}


// ========================================================================
// ?FreeProvidedLineBuffer@idStreamControlThread@@AAAXPAE_N@Z
// EA  : 0x826A1A60
// RVA : 0x006A1A60
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamControlThread::FreeProvidedLineBuffer(
        idStreamControlThread *this,
        unsigned __int8 *ptr,
        bool freed)
{
  BOOL v3; // r27
  int v6; // r30
  void **i; // r31

  v3 = freed;
  if ( freed )
    Sys_InterlockedDecrement(value: &this->providedLineBuffersUsed.value);
  v6 = 0;
  for ( i = (void **)this->providedLineBuffers;
        *i != nullptr || Sys_InterlockedCompareExchange(ptr: i, comparand: nullptr, exchange: ptr) != nullptr;
        ++i )
  {
    if ( ++v6 >= 1024 )
    {
      if ( v3 )
        Sys_InterlockedDecrement(value: &this->providedLineBuffersTotal.value);
      return;
    }
  }
  if ( !v3 )
    Sys_InterlockedIncrement(value: &this->providedLineBuffersTotal.value);
}


// ========================================================================
// ?GetLineBufferLRU@idStreamControlThread@@AAAPAEW4memoryType_t@@AAW42@@Z
// EA  : 0x826A1B08
// RVA : 0x006A1B08
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

idFileCacheLine *__fastcall idStreamControlThread::GetLineBufferLRU(
        idStreamControlThread *this,
        memoryType_t requestedType,
        memoryType_t *returnedType)
{
  idFileCacheLine *result; // r3
  idFileCacheLine *v6; // r31
  unsigned __int8 *data; // r27

  result = idLocklessCacheLineMRU::NextLRU(this: &this->cacheLineMRU, memType: requestedType);
  v6 = result;
  if ( result != nullptr )
  {
    data = result->data;
    *returnedType = result->memType;
    result->data = nullptr;
    idLocklessCacheLineHash::Remove(this: &this->cacheLineHash, line: result);
    v6->state = CACHE_LINE_STATE_FREE;
    idLocklessCacheLineQueueM::Add(this: &this->cacheLineFree, line: v6);
    return (idFileCacheLine *)data;
  }
  else
  {
    *returnedType = MEMORY_TYPE_INVALID;
  }
  return result;
}


// ========================================================================
// ?AllocLineBuffer@idStreamControlThread@@AAAPAEAAW4memoryType_t@@@Z
// EA  : 0x826A1B88
// RVA : 0x006A1B88
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

unsigned __int8 *__fastcall idStreamControlThread::AllocLineBuffer(
        idStreamControlThread *this,
        memoryType_t *returnedType)
{
  idSysInterlockedInteger *p_totalUsedLineBuffers; // r29
  unsigned __int8 *result; // r3

  p_totalUsedLineBuffers = &this->totalUsedLineBuffers;
  if ( Sys_InterlockedIncrement(value: &this->totalUsedLineBuffers.value) << 16 > fc_maxCacheMemoryMB.valueInteger << 20 )
    goto LABEL_6;
  result = idStreamControlThread::AllocProvidedLineBuffer(this);
  if ( result != nullptr )
  {
    *returnedType = MEMORY_TYPE_PROVIDED;
    return result;
  }
  result = (unsigned __int8 *)XMemAlloc(dwSize: 0x10000u, dwAllocAttributes: 0xAC320000);
  if ( result != nullptr )
  {
    *returnedType = MEMORY_TYPE_ALLOCATED;
  }
  else
  {
LABEL_6:
    Sys_InterlockedDecrement(value: &p_totalUsedLineBuffers->value);
    return (unsigned __int8 *)idStreamControlThread::GetLineBufferLRU(
                                this,
                                requestedType: MEMORY_TYPE_ANY,
                                returnedType);
  }
  return result;
}


// ========================================================================
// ?CondenseCacheLineQueue@idStreamControlThread@@AAAHAAVidLocklessCacheLineQueueS@@H@Z
// EA  : 0x826A1C30
// RVA : 0x006A1C30
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

int __fastcall idStreamControlThread::CondenseCacheLineQueue(
        idStreamControlThread *this,
        idLocklessCacheLineQueueS *queue,
        volatile int timeOut)
{
  volatile int queueEnd; // r27
  int v7; // r29
  int v8; // r28
  idFileCacheLine *v9; // r31

  queueEnd = queue->queueEnd;
  v7 = 0;
  LOWORD(v8) = queueEnd;
  if ( queueEnd != queue->queueStart )
  {
    do
    {
      v8 = ((_WORD)v8 - 1) & 0xFFF;
      v9 = queue->queue[v8];
      queue->queue[v8] = nullptr;
      if ( v9 != nullptr )
      {
        if ( v9->time <= timeOut )
        {
          Sys_InterlockedDecrement(value: &queue->numLines.value);
          idLocklessCacheLineHash::Remove(this: &this->cacheLineHash, line: v9);
          v9->state = CACHE_LINE_STATE_FREE;
          idLocklessCacheLineQueueM::Add(this: &this->cacheLineFree, line: v9);
          ++v7;
        }
        else
        {
          queueEnd = (queueEnd - 1) & 0xFFF;
          queue->queue[queueEnd] = v9;
        }
      }
    }
    while ( v8 != queue->queueStart );
  }
  queue->queueStart = queueEnd;
  return v7;
}


// ========================================================================
// ?ProcessRequests@idStreamControlThread@@AAAXXZ
// EA  : 0x826A1CF8
// RVA : 0x006A1CF8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamControlThread::ProcessRequests(idStreamControlThread *this)
{
  __int64 v2; // r9
  char *v3; // r11
  volatile int *p_uncachedOpticalDiskRequestQueueEnd; // r10
  __int64 v5; // r5
  _QWORD *v6; // r3
  __int64 v7; // r5
  int v8; // r9
  int v9; // r8
  int v10; // r7
  int v11; // r6
  int v12; // r5
  idFileCacheLine *v13; // r4
  idFileCacheLine *v14; // r30
  idLocklessCacheLineQueueS *p_hardDiskFinishedQueue; // r31
  idFileCacheLine *v16; // r30
  idFileCacheLine *v17; // r30
  volatile int *p_requestQueueStart; // r24
  int v19; // r23
  idLocklessCacheLineHash *p_cacheLineHash; // r27
  int v21; // r9
  idStreamControlThread::requestedCacheLine_t *v22; // r30
  int fileID; // r10
  int fileLine; // r5
  int v25; // r11
  int v26; // r8
  int v27; // r11
  idFileCacheLine *v28; // r31
  idFileCacheLine *v29; // r31
  idFileCacheLine *LRU; // r3
  memoryType_t memType; // r11
  unsigned __int8 *data; // r3
  int priority; // r11
  int persistence; // r11
  volatile int indexMRU; // r11
  idFileCacheLine *v36; // r3
  idFileCacheLine *v37; // r28
  unsigned __int64 memoryCacheHits; // r11
  int v39; // r11
  int v40; // r6
  int v41; // r9
  __int16 v42; // r3
  int v43; // r10
  idFileCacheLine *v44; // r11
  int v45; // r9
  unsigned __int64 v46; // r4
  unsigned int v47; // r31
  int v48; // [sp+8h] [-F8h]
  int v49; // [sp+Ch] [-F4h]
  int v50; // [sp+10h] [-F0h]
  int v51; // [sp+14h] [-ECh]
  int v52; // [sp+18h] [-E8h]
  double v53; // [sp+18h] [-E8h]
  int v54; // [sp+1Ch] [-E4h]
  int v55; // [sp+20h] [-E0h]
  int v56; // [sp+24h] [-DCh]
  int v57; // [sp+28h] [-D8h]
  int v58; // [sp+2Ch] [-D4h]
  int v59; // [sp+30h] [-D0h]
  int v60; // [sp+34h] [-CCh]
  int v61; // [sp+38h] [-C8h]
  int v62; // [sp+3Ch] [-C4h]
  int v63; // [sp+40h] [-C0h]
  int v64; // [sp+44h] [-BCh]
  int v65; // [sp+48h] [-B8h]
  int v66; // [sp+4Ch] [-B4h]
  int v67; // [sp+50h] [-B0h]
  volatile int *p_requestQueueEnd; // [sp+50h] [-B0h]
  int i; // [sp+5Ch] [-A4h]

  this->lastServiceTime = Sys_Milliseconds();
  for ( i = Sys_Microseconds() >> 32;
        this->freeMemoryRequestQueueStart != this->freeMemoryRequestQueueEnd;
        this->freeMemoryRequestQueueStart = (this->freeMemoryRequestQueueStart + 1) & 0x3FF )
  {
    idMem::Free(this: &mem, ptr: this->freeMemoryRequestQueue[this->freeMemoryRequestQueueStart].block, align: ALIGN_16);
  }
  if ( this->serviceBink == SERVICE_BINK_OPTICAL_DISK )
  {
    this->serviceBinkOpticalDisk = true;
  }
  else if ( this->serviceBink == SERVICE_BINK_HARD_DISK )
  {
    this->serviceBinkHardDisk = true;
  }
  HIDWORD(v2) = &this->uncachedRequestQueueStart;
  this->serviceBink = SERVICE_BINK_NONE;
  if ( this->uncachedRequestQueueStart != this->uncachedRequestQueueEnd )
  {
    do
    {
      v3 = (char *)this + 32 * *(_DWORD *)HIDWORD(v2);
      if ( *((_DWORD *)v3 + 1046) == 1 )
      {
        p_uncachedOpticalDiskRequestQueueEnd = &this->uncachedOpticalDiskRequestQueueEnd;
        if ( ((this->uncachedOpticalDiskRequestQueueEnd + 1) & 0x7FF) == this->uncachedOpticalDiskRequestQueueStart )
          break;
        v5 = *((_QWORD *)v3 + 523);
        HIDWORD(v5) = *p_uncachedOpticalDiskRequestQueueEnd + 2179;
        v6 = (_QWORD *)((char *)this + 32 * HIDWORD(v5));
        *v6 = v5;
        v2 = *((_QWORD *)v3 + 524);
        v6[1] = v2;
        v6[2] = *((_QWORD *)v3 + 525);
        *(_QWORD *)(*((_DWORD *)v3 + 1052) + 24) = *((_QWORD *)v3 + 526);
      }
      else
      {
        p_uncachedOpticalDiskRequestQueueEnd = &this->uncachedHardDiskRequestQueueEnd;
        if ( ((this->uncachedHardDiskRequestQueueEnd + 1) & 0x7FF) == this->uncachedHardDiskRequestQueueStart )
          break;
        v7 = *((_QWORD *)v3 + 523);
        HIDWORD(v7) = (char *)this + 32 * *p_uncachedOpticalDiskRequestQueueEnd;
        *(_QWORD *)(HIDWORD(v7) + 135272) = v7;
        v2 = *((_QWORD *)v3 + 524);
        *(_QWORD *)(HIDWORD(v7) + 135280) = v2;
        *(_QWORD *)(HIDWORD(v7) + 135288) = *((_QWORD *)v3 + 525);
        *(_QWORD *)(*((_DWORD *)v3 + 1052) + 24) = *((_QWORD *)v3 + 526);
      }
      __lwsync();
      *p_uncachedOpticalDiskRequestQueueEnd = (*p_uncachedOpticalDiskRequestQueueEnd + 1) & 0x7FF;
      *(_DWORD *)HIDWORD(v2) = (*(_DWORD *)HIDWORD(v2) + 1) & 0x7FF;
    }
    while ( *(_DWORD *)HIDWORD(v2) != this->uncachedRequestQueueEnd );
  }
  v13 = idLocklessCacheLineQueueS::Next(this: &this->opticalDiskFinishedQueue);
  if ( v13 != nullptr )
  {
    do
    {
      idLocklessCacheLineMRU::AddMRU(this: &this->cacheLineMRU, line: v13);
      if ( this->opticalDiskFinishedQueue.queueStart == this->opticalDiskFinishedQueue.queueEnd )
        break;
      v14 = this->opticalDiskFinishedQueue.queue[this->opticalDiskFinishedQueue.queueStart];
      this->opticalDiskFinishedQueue.queueStart = (this->opticalDiskFinishedQueue.queueStart + 1) & 0xFFF;
      __lwsync();
      Sys_InterlockedDecrement(value: &this->opticalDiskFinishedQueue.numLines.value);
      v13 = v14;
    }
    while ( v14 != nullptr );
  }
  p_hardDiskFinishedQueue = &this->hardDiskFinishedQueue;
  if ( this->hardDiskFinishedQueue.queueStart != this->hardDiskFinishedQueue.queueEnd )
  {
    v16 = p_hardDiskFinishedQueue->queue[this->hardDiskFinishedQueue.queueStart];
    this->hardDiskFinishedQueue.queueStart = (this->hardDiskFinishedQueue.queueStart + 1) & 0xFFF;
    __lwsync();
    Sys_InterlockedDecrement(value: &this->hardDiskFinishedQueue.numLines.value);
    v13 = v16;
    if ( v16 != nullptr )
    {
      do
      {
        idLocklessCacheLineMRU::AddMRU(this: &this->cacheLineMRU, line: v13);
        if ( this->hardDiskFinishedQueue.queueStart == this->hardDiskFinishedQueue.queueEnd )
          break;
        v17 = p_hardDiskFinishedQueue->queue[this->hardDiskFinishedQueue.queueStart];
        this->hardDiskFinishedQueue.queueStart = (this->hardDiskFinishedQueue.queueStart + 1) & 0xFFF;
        __lwsync();
        Sys_InterlockedDecrement(value: &this->hardDiskFinishedQueue.numLines.value);
        v13 = v17;
      }
      while ( v17 != nullptr );
    }
  }
  if ( this->newFrame )
  {
    this->newFrame = false;
    idLocklessCacheLineMRU::Sort(
      this: &this->cacheLineMRU,
      a2: (int)v13,
      a3: v12,
      a4: v11,
      a5: v10,
      a6: v9,
      a7: v8,
      a8: 458752,
      a9: v48,
      a10: v49,
      a11: v50,
      a12: v51,
      a13: v52,
      a14: v54,
      a15: v55,
      a16: v56,
      a17: v57,
      a18: v58,
      a19: v59,
      a20: v60,
      a21: v61,
      a22: v62,
      a23: v63,
      a24: v64,
      a25: v65,
      a26: v66,
      a27: v67);
    idLocklessCacheLineHash::Condense(this: &this->cacheLineHash);
  }
  p_requestQueueStart = &this->requestQueueStart;
  p_requestQueueEnd = &this->requestQueueEnd;
  v19 = Sys_Milliseconds();
  if ( this->requestQueueStart != this->requestQueueEnd )
  {
    p_cacheLineHash = &this->cacheLineHash;
    while ( 1 )
    {
      v21 = 0;
      v22 = &this->requestQueue[*p_requestQueueStart];
      fileID = this->requestQueue[*p_requestQueueStart].fileID;
      fileLine = this->requestQueue[*p_requestQueueStart].fileLine;
      v25 = (32 * (_WORD)fileID + (_WORD)fileLine) & 0xFFF;
      v26 = 4 * v25;
      v27 = p_cacheLineHash->numHashEntries[v25];
      if ( v27 > 0 )
      {
        while ( 1 )
        {
          v28 = *(idFileCacheLine **)((char *)p_cacheLineHash->hash + ((4 * (v21 + v26)) & 0xFFFC));
          if ( v28 != nullptr && v28->fileLine == fileLine && v28->fileID == fileID )
            break;
          if ( ++v21 >= v27 )
            goto LABEL_30;
        }
        priority = this->requestQueue[*p_requestQueueStart].priority;
        if ( v28->priority > priority )
          priority = v28->priority;
        v28->priority = priority;
        persistence = v22->persistence;
        if ( v28->persistence > persistence )
          persistence = v28->persistence;
        v28->persistence = persistence;
        v28->time = v19;
        v28->replacements = this->cacheLineMRU.replacementCount.value;
        indexMRU = v28->indexMRU;
        if ( indexMRU != -1 )
        {
          v36 = (idFileCacheLine *)Sys_InterlockedExchangePointer(
                                     ptr: (void **)&this->cacheLineMRU.queue[indexMRU],
                                     exchange: nullptr);
          v37 = v36;
          if ( v36 == v28 )
          {
            v36->indexMRU = -1;
            Sys_InterlockedDecrement(value: &this->cacheLineMRU.numLines.value);
            idLocklessCacheLineMRU::AddMRU(this: &this->cacheLineMRU, line: v37);
          }
        }
        memoryCacheHits = this->currentStats.memoryCacheHits;
        LODWORD(memoryCacheHits) = memoryCacheHits + 1;
        this->currentStats.memoryCacheHits = memoryCacheHits;
        goto LABEL_54;
      }
LABEL_30:
      idStreamFileLog::NoteCacheLineRequest(
        this: &streamFileLog,
        f: this->requestQueue[*p_requestQueueStart].filePtr,
        fileLine,
        priority: this->requestQueue[*p_requestQueueStart].priority);
      v29 = idLocklessCacheLineQueueM::Next(this: &this->cacheLineFree);
      if ( v29 == nullptr )
        break;
LABEL_46:
      v39 = 0;
      v29->state = CACHE_LINE_STATE_READ_HARD_DISK;
      v40 = v22->fileID;
      v29->fileID = v40;
      v41 = v22->fileLine;
      v29->fileLine = v41;
      v42 = 32 * v40 + v41;
      v29->filePtr = v22->filePtr;
      v29->validLength = 0;
      v29->priority = v22->priority;
      v29->persistence = v22->persistence;
      v29->time = v19;
      v29->replacements = this->cacheLineMRU.replacementCount.value;
      while ( 1 )
      {
        v43 = (4 * (v39 + 4 * (v42 & 0xFFF))) & 0xFFFC;
        if ( *(idFileCacheLine **)((char *)p_cacheLineHash->hash + v43) == nullptr )
          break;
        if ( ++v39 >= 0x4000 )
          goto LABEL_53;
      }
      *(idFileCacheLine **)((char *)p_cacheLineHash->hash + v43) = v29;
      __lwsync();
      v44 = (idFileCacheLine *)(v39 + 1);
      v45 = (v42 & 0xFFF) + 0x4000;
      if ( (int)p_cacheLineHash->hash[v45] > (int)v44 )
        v44 = p_cacheLineHash->hash[v45];
      p_cacheLineHash->hash[v45] = v44;
      Sys_InterlockedIncrement(value: &this->cacheLineHash.numLines.value);
LABEL_53:
      this->hardDiskReadQueue.queue[this->hardDiskReadQueue.queueEnd] = v29;
      __lwsync();
      this->hardDiskReadQueue.queueEnd = (this->hardDiskReadQueue.queueEnd + 1) & 0xFFF;
      Sys_InterlockedIncrement(value: &this->hardDiskReadQueue.numLines.value);
LABEL_54:
      *p_requestQueueStart = (*p_requestQueueStart + 1) & 0x1FFF;
      if ( *p_requestQueueStart == *p_requestQueueEnd )
        goto LABEL_57;
    }
    LRU = idLocklessCacheLineMRU::NextLRU(this: &this->cacheLineMRU, memType: MEMORY_TYPE_ANY);
    v29 = LRU;
    if ( LRU == nullptr )
    {
      *p_requestQueueStart = *p_requestQueueEnd;
      goto LABEL_57;
    }
    memType = LRU->memType;
    data = LRU->data;
    if ( memType == MEMORY_TYPE_ALLOCATED )
    {
      XMemFree(pAddress: data, dwAllocAttributes: 0xAC320000);
    }
    else
    {
      if ( memType != MEMORY_TYPE_PROVIDED )
      {
LABEL_45:
        v29->data = nullptr;
        v29->memType = MEMORY_TYPE_INVALID;
        idLocklessCacheLineHash::Remove(this: p_cacheLineHash, line: v29);
        v29->state = CACHE_LINE_STATE_FREE;
        goto LABEL_46;
      }
      idStreamControlThread::FreeProvidedLineBuffer(this, ptr: data, freed: true);
    }
    Sys_InterlockedDecrement(value: &this->totalUsedLineBuffers.value);
    goto LABEL_45;
  }
LABEL_57:
  if ( this->hardDiskReadQueue.queueStart != this->hardDiskReadQueue.queueEnd
    || this->uncachedHardDiskRequestQueueStart != this->uncachedHardDiskRequestQueueEnd
    || this->serviceBinkHardDisk )
  {
    this->threadSignalled = true;
    idSysThread::SignalWork(this: this->hardDiskThread);
  }
  if ( this->uncachedOpticalDiskRequestQueueStart != this->uncachedOpticalDiskRequestQueueEnd
    || this->serviceBinkOpticalDisk )
  {
    this->threadSignalled = true;
    idSysThread::SignalWork(this: this->opticalDiskThread);
  }
  v46 = Sys_Microseconds();
  v47 = HIDWORD(v46) - i;
  if ( (unsigned int)(HIDWORD(v46) - i) > 0x1F4 )
    ((void (__fastcall *)(idConsole *, int, idColor *))console->AddTimeRange)(
      a1: console,
      a2: 12,
      a3: &idColor::colorRed);
  if ( v47 > 0xFA0 )
  {
    v53 = (float)((float)_u64tod(a1: v47, a2: v46) * (float)0.001);
    idLib::Printf(fmt: (const char *)HIDWORD(v53), LODWORD(v53));
  }
}


// ========================================================================
// ?Run@idStreamControlThread@@EAAHXZ
// EA  : 0x826A2448
// RVA : 0x006A2448
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

int __fastcall idStreamControlThread::Run(idStreamControlThread *this)
{
  volatile int *p_uncachedRequestQueueEnd; // r26
  volatile int *p_uncachedRequestQueueStart; // r25

  p_uncachedRequestQueueEnd = &this->uncachedRequestQueueEnd;
  p_uncachedRequestQueueStart = &this->uncachedRequestQueueStart;
  while ( *p_uncachedRequestQueueStart != *p_uncachedRequestQueueEnd
       || this->requestQueueStart != this->requestQueueEnd
       || this->opticalDiskFinishedQueue.queueStart != this->opticalDiskFinishedQueue.queueEnd
       || this->hardDiskFinishedQueue.queueStart != this->hardDiskFinishedQueue.queueEnd
       || this->serviceBink != SERVICE_BINK_NONE )
    idStreamControlThread::ProcessRequests(this);
  return 0;
}


// ========================================================================
// ?ProcessIO@idHardDiskStreamThread@@AAAXXZ
// EA  : 0x826A24F8
// RVA : 0x006A24F8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idHardDiskStreamThread::ProcessIO(idHardDiskStreamThread *this)
{
  idStreamControlThread *controlThread; // r11
  int v3; // r30
  int v4; // r28
  __int64 v5; // r10
  __int128 v6; // r8
  int v7; // r7
  unsigned __int64 v8; // r3
  idFileCacheLine *v9; // r3
  idFileCacheLine *v10; // r28
  int v11; // r3
  int v12; // r30
  idStreamControlThread *v13; // r10
  int v14; // r29
  const idFile *v15; // r27
  int v16; // r3
  int v17; // r26
  int v18; // r30
  __int64 v19; // r8
  unsigned int v20; // r10
  __int64 v21; // r8
  unsigned __int64 hardDiskCacheLinesWritten; // r11
  idStreamControlThread *v23; // r5
  unsigned __int64 v24; // r3
  _BYTE v25[12]; // r11
  idLocklessCacheLineQueueS *p_hardDiskFinishedQueue; // r11
  idStreamControlThread *v27; // r10
  int v28; // r30
  int queueStart; // r22
  volatile int queueEnd; // r8
  int v31; // r16
  int v32; // r21
  int v33; // r20
  int v34; // r27
  idFileCacheLine *v35; // r29
  int v36; // r26
  int v37; // r28
  int HardDiskCacheLine; // r3
  idStreamControlThread *v39; // r11
  idStreamControlThread *v40; // r9
  int opticalDiskOffset; // r10
  idLocklessCacheLineQueueS *p_opticalDiskReadQueue; // r11
  int v43; // r11
  int priority; // r10
  idStreamControlThread *v45; // r11
  int v46; // r10
  idStreamControlThread *v47; // r11
  int v48; // r3
  unsigned __int64 v49; // r5
  memoryType_t tempMemType; // r27
  unsigned __int8 *tempData; // r29
  idStreamControlThread *v52; // r10
  const idFile *v53; // r24
  int v54; // r3
  __int64 v55; // r10
  int v56; // r25
  __int64 v57; // r8
  int v58; // r24
  int v59; // r2 OVERLAPPED
  idStreamControlThread *v60; // r8
  unsigned __int64 v61; // r6
  __int64 v62; // r5
  unsigned __int64 v63; // r7
  int v64; // r3
  __int64 v65; // r11
  __int64 v66; // r9
  idStreamControlThread *v67; // r8
  int v68; // r7
  const idColor *v69; // r5
  int v70; // r6
  int v71; // r3
  int v72; // r26
  __int64 v73; // r10
  __int64 v74; // r4
  __int64 v75; // r28
  __int64 v76; // r8
  unsigned __int64 v77; // r4
  int v78; // r2 OVERLAPPED
  int v79; // r25
  idStreamControlThread *v80; // r8
  unsigned __int64 v81; // r6
  unsigned __int64 v82; // r7
  int v83; // r3
  __int64 v84; // r11
  __int64 v85; // r9
  idStreamControlThread *v86; // r8
  idStreamControlThread *v87; // r11
  int v88; // [sp+8h] [-F8h]
  int v89; // [sp+50h] [-B0h]
  int valueInteger; // [sp+54h] [-ACh]
  idCVar *v91; // [sp+58h] [-A8h] BYREF
  int v92; // [sp+5Ch] [-A4h]

  controlThread = this->controlThread;
  if ( controlThread->serviceBinkHardDisk )
  {
    controlThread->serviceBinkHardDisk = false;
    FillBinkBuffer();
    return;
  }
  if ( controlThread->uncachedHardDiskRequestQueueStart != controlThread->uncachedHardDiskRequestQueueEnd )
  {
    v3 = (int)&controlThread->uncachedHardDiskRequestQueue[controlThread->uncachedHardDiskRequestQueueStart];
    v4 = Sys_Microseconds() >> 32;
    if ( **(_DWORD **)(v3 + 20) == 0 )
      **(_DWORD **)(v3 + 20) = idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\engine\\framework\\StreamFileCache.cpp(2827) : request.tag",
                                 size: *(_DWORD *)(v3 + 16),
                                 tag: *(memTag_t *)(v3 + 24),
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_MAPHEAP);
    LODWORD(v5) = *(_DWORD *)(v3 + 16);
    HIDWORD(v5) = 99;
    *(_QWORD *)((char *)&v6 + 4) = *(_QWORD *)(v3 + 8);
    LODWORD(v6) = v5;
    idStreamFileLog::BeginIO(
      this: &streamFileLog,
      drive: SFL_HARD_DRIVE,
      io: SFL_READ,
      f: *(const idFile *const *)(v3 + 4),
      ofs: v6,
      len: v5,
      priority: v88);
    (*(void (__fastcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(v3 + 8) + 20))(
      a1: *(_DWORD *)(v3 + 8),
      a2: *(_DWORD *)(v3 + 12),
      a3: **(_DWORD **)(v3 + 20),
      a4: *(_DWORD *)(v3 + 16));
    idStreamFileLog::EndIO(this: &streamFileLog, drive: SFL_HARD_DRIVE);
    v7 = Sys_Microseconds() >> 32;
    **(_BYTE **)(v3 + 28) = 1;
    LODWORD(v8) = LODWORD(this->controlThread->currentStats.uncachedHardDiskReads) + 1;
    this->controlThread->currentStats.uncachedHardDiskReads = v8;
    LODWORD(v8) = HIDWORD(this->controlThread->currentStats.uncachedHardDiskReadSize)
                + LODWORD(this->controlThread->currentStats.uncachedHardDiskReadSize);
    this->controlThread->currentStats.uncachedHardDiskReadSize = v8;
    console->AddTimeRange(this: console, a2: RANGE_STREAM_HD, a3: &idColor::colorBlue, a4: v4, a5: v7);
    this->controlThread->uncachedHardDiskRequestQueueStart = (this->controlThread->uncachedHardDiskRequestQueueStart + 1)
                                                           & 0x7FF;
    return;
  }
  v9 = idLocklessCacheLineQueueS::Next(this: &controlThread->hardDiskWriteQueue);
  v10 = v9;
  if ( v9 != nullptr )
  {
    v11 = idStreamControlThread::AllocHardDiskCacheLine(
            this: this->controlThread,
            fileID: v9->fileID,
            fileLine: v9->fileLine);
    v12 = v11;
    if ( v11 != -1 )
    {
      v13 = this->controlThread;
      v14 = v11 >> 5;
      this->hardDiskOffset = v11 - 0x1000000 + 1;
      v15 = v13->hdcFiles[v11 >> 5];
      v16 = Sys_Microseconds() >> 32;
      v17 = (v12 << 16) & 0x1F0000;
      HIDWORD(v19) = v17;
      v18 = v16;
      LODWORD(v19) = 0x10000;
      idStreamFileLog::BeginIO(
        this: &streamFileLog,
        drive: SFL_HARD_DRIVE,
        io: SFL_WRITE,
        f: v15,
        ofs: v19,
        len: v20,
        priority: v88);
      v15->WriteOfs(this: (idFile *)v15, a2: v17, a3: v10->data, a4: 0x10000u);
      idStreamFileLog::EndIO(this: &streamFileLog, drive: SFL_HARD_DRIVE);
      HIDWORD(v21) = Sys_Microseconds() >> 32;
      ++this->controlThread->hdc->hdLinesWritten[v14];
      hardDiskCacheLinesWritten = this->controlThread->currentStats.hardDiskCacheLinesWritten;
      LODWORD(v21) = hardDiskCacheLinesWritten + 1;
      *(_QWORD *)HIDWORD(hardDiskCacheLinesWritten) = v21;
      v23 = this->controlThread;
      LODWORD(v24) = HIDWORD(v21) - v18 + LODWORD(v23->currentStats.hardDiskCacheTotalWriteTime);
      v23->currentStats.hardDiskCacheTotalWriteTime = v24;
      *(_DWORD *)&v25[8] = &this->controlThread->currentStats.hardDiskCacheMinWriteTime;
      *(_QWORD *)v25 = **(_QWORD **)&v25[8];
      if ( *(_DWORD *)&v25[4] >= *(_DWORD *)v25 )
        *(_DWORD *)&v25[4] = **(_DWORD **)&v25[8];
      **(_QWORD **)&v25[8] = *(_QWORD *)v25;
      *(_QWORD *)&v25[4] = this->controlThread->currentStats.hardDiskCacheMaxWriteTime;
      if ( *(_DWORD *)&v25[8] <= *(_DWORD *)v25 )
        *(_DWORD *)&v25[8] = *(_DWORD *)v25;
      **(_QWORD **)&v25[4] = *(_QWORD *)&v25[4];
      ((void (__fastcall *)(idConsole *, int, idColor *, int))console->AddTimeRange)(
        a1: console,
        a2: 13,
        a3: &idColor::colorYellow,
        a4: v18);
    }
    p_hardDiskFinishedQueue = &this->controlThread->hardDiskFinishedQueue;
    p_hardDiskFinishedQueue->queue[this->controlThread->hardDiskFinishedQueue.queueEnd] = v10;
    __lwsync();
    p_hardDiskFinishedQueue->queueEnd = (p_hardDiskFinishedQueue->queueEnd + 1) & 0xFFF;
    Sys_InterlockedIncrement(value: &p_hardDiskFinishedQueue->numLines.value);
    this->controlThread->threadSignalled = true;
    idSysThread::SignalWork(this: this->controlThread);
    return;
  }
  v27 = this->controlThread;
  v28 = 0;
  queueStart = v27->hardDiskReadQueue.queueStart;
  queueEnd = v27->hardDiskReadQueue.queueEnd;
  v31 = -1;
  v89 = 0;
  v32 = -1;
  valueInteger = fc_hardDiskNoSeekOffset.valueInteger;
  v33 = -1;
  v92 = fc_opticalDiskSkipOffset.valueInteger;
  if ( queueStart == queueEnd )
    goto LABEL_35;
  v91 = &fc_useHdc;
  do
  {
    v34 = 4 * (queueStart + 99364);
    v35 = *(idFileCacheLine **)((char *)&this->controlThread->__vftable + v34);
    if ( v35 == nullptr )
      goto LABEL_32;
    v36 = -1;
    v37 = (v35->fileID << 24) | v35->fileLine;
    if ( v35->filePtr->GetDevice(this: v35->filePtr) == FS_DEVICE_OPTICAL_DISK_DRIVE || v91->valueInteger == 2 )
    {
      HardDiskCacheLine = idStreamControlThread::FindHardDiskCacheLine(
                            this: this->controlThread,
                            fileID: v35->fileID,
                            fileLine: v35->fileLine);
      v39 = this->controlThread;
      v36 = HardDiskCacheLine;
      if ( HardDiskCacheLine == -1 )
      {
        *(idStreamControlThread_vtbl **)((char *)&v39->__vftable + v34) = nullptr;
        Sys_InterlockedDecrement(value: &this->controlThread->hardDiskReadQueue.numLines.value);
        v35->state = CACHE_LINE_STATE_READ_OPTICAL_DISK;
        v40 = this->controlThread;
        v40->opticalDiskReadQueue.queue[v40->opticalDiskReadQueue.queueEnd] = v35;
        __lwsync();
        v40->opticalDiskReadQueue.queueEnd = (v40->opticalDiskReadQueue.queueEnd + 1) & 0xFFF;
        Sys_InterlockedIncrement(value: &v40->opticalDiskReadQueue.numLines.value);
        goto LABEL_32;
      }
      opticalDiskOffset = v39->opticalDiskThread->opticalDiskOffset;
      if ( v37 >= opticalDiskOffset && v37 < opticalDiskOffset + v92 )
      {
        *(idStreamControlThread_vtbl **)((char *)&v39->__vftable + v34) = nullptr;
        Sys_InterlockedDecrement(value: &this->controlThread->hardDiskReadQueue.numLines.value);
        v35->state = CACHE_LINE_STATE_READ_OPTICAL_DISK_NO_WRITE_BACK;
        p_opticalDiskReadQueue = &this->controlThread->opticalDiskReadQueue;
        p_opticalDiskReadQueue->queue[this->controlThread->opticalDiskReadQueue.queueEnd] = v35;
        __lwsync();
        p_opticalDiskReadQueue->queueEnd = (p_opticalDiskReadQueue->queueEnd + 1) & 0xFFF;
        Sys_InterlockedIncrement(value: &p_opticalDiskReadQueue->numLines.value);
        goto LABEL_32;
      }
      v37 = HardDiskCacheLine - 0x1000000;
    }
    v43 = v37 - this->hardDiskOffset;
    priority = v35->priority;
    if ( (int)abs32(v43) <= valueInteger )
    {
      if ( v43 < 0 )
        priority = v43 - valueInteger + 0x7FFFFFFF;
      else
        priority = 0x7FFFFFFF - v43;
    }
    if ( priority > v33 )
    {
      v32 = queueStart;
      v89 = v37 - this->hardDiskOffset;
      v33 = priority;
      v31 = v36;
    }
LABEL_32:
    v45 = this->controlThread;
    queueStart = (queueStart + 1) & 0xFFF;
  }
  while ( queueStart != v45->hardDiskReadQueue.queueEnd );
  if ( v32 != -1 )
  {
    v46 = 4 * (v32 + 99364);
    v28 = *(int *)((char *)&v45->__vftable + v46);
    *(idStreamControlThread_vtbl **)((char *)&v45->__vftable + v46) = nullptr;
    Sys_InterlockedDecrement(value: &this->controlThread->hardDiskReadQueue.numLines.value);
  }
LABEL_35:
  v47 = this->controlThread;
  if ( v47->opticalDiskReadQueue.queueStart != v47->opticalDiskReadQueue.queueEnd )
  {
    v47->threadSignalled = true;
    idSysThread::SignalWork(this: this->controlThread->opticalDiskThread);
  }
  v48 = Sys_Milliseconds();
  idStreamControlThread::CondenseCacheLineQueue(
    this: this->controlThread,
    queue: &this->controlThread->hardDiskReadQueue,
    timeOut: v48 - fc_hardDiskRequestTimeOut.valueInteger);
  LODWORD(v49) = HIDWORD(this->controlThread->currentStats.hardDiskTimeOuts)
               + LODWORD(this->controlThread->currentStats.hardDiskTimeOuts);
  this->controlThread->currentStats.hardDiskTimeOuts = v49;
  if ( v28 != 0 )
  {
    tempMemType = this->tempMemType;
    tempData = this->tempData;
    this->tempData = nullptr;
    this->tempMemType = MEMORY_TYPE_INVALID;
    v91 = (idCVar *)tempMemType;
    if ( tempData == nullptr )
    {
      tempData = idStreamControlThread::AllocLineBuffer(this: this->controlThread, returnedType: (memoryType_t *)&v91);
      if ( tempData == nullptr )
      {
        idLocklessCacheLineHash::Remove(this: &this->controlThread->cacheLineHash, line: (idFileCacheLine *)v28);
        *(_DWORD *)v28 = 0;
        idLocklessCacheLineQueueM::Add(this: &this->controlThread->cacheLineFree, line: (idFileCacheLine *)v28);
        goto LABEL_58;
      }
      tempMemType = (memoryType_t)v91;
    }
    if ( v31 != -1 )
    {
      v52 = this->controlThread;
      this->hardDiskOffset = v31 - 0x1000000 + 1;
      v53 = v52->hdcFiles[v31 >> 5];
      v54 = Sys_Microseconds() >> 32;
      *(_DWORD *)(v28 + 20) = tempData;
      *(_DWORD *)(v28 + 24) = tempMemType;
      HIDWORD(v55) = *(_DWORD *)(v28 + 28);
      v56 = v54;
      HIDWORD(v57) = (v31 << 16) & 0x1F0000;
      LODWORD(v57) = 0x10000;
      idStreamFileLog::BeginIO(
        this: &streamFileLog,
        drive: SFL_HARD_DRIVE,
        io: SFL_READ,
        f: v53,
        ofs: v57,
        len: v55,
        priority: v88);
      *(_DWORD *)(v28 + 16) = v53->ReadOfs(
                                this: (idFile *)v53,
                                a2: (v31 << 16) & 0x1F0000,
                                a3: *(void **)(v28 + 20),
                                a4: 0x10000u);
      idStreamFileLog::EndIO(this: &streamFileLog, drive: SFL_HARD_DRIVE);
      *(_DWORD *)(v28 + 4) = 0;
      v58 = Sys_Microseconds() >> 32;
      if ( *(_DWORD *)(v28 + 16) == 0 )
      {
        *(_DWORD *)(v28 + 20) = 0;
        *(_DWORD *)(v28 + 24) = 0;
        idLocklessCacheLineHash::Remove(this: &this->controlThread->cacheLineHash, line: (idFileCacheLine *)v28);
        *(_DWORD *)v28 = 0;
        idLocklessCacheLineQueueM::Add(this: &this->controlThread->cacheLineFree, line: (idFileCacheLine *)v28);
        v60 = this->controlThread;
        LODWORD(v61) = LODWORD(v60->currentStats.hardDiskReadsFailed) + 1;
        v60->currentStats.hardDiskReadsFailed = v61;
        this->tempData = tempData;
        this->tempMemType = tempMemType;
        idLib::Warning(
          fmt: "failed to read cache line at %lld from the hard disk backing cache",
          (v31 << 16) & 0x1F0000);
        return;
      }
      HIDWORD(v62) = v89 >> 31;
      ++this->controlThread->hdc->hdLinesRead[v31 >> 5];
      HIDWORD(v63) = &this->controlThread->currentStats.hardDiskCacheHits;
      LODWORD(v62) = LODWORD(this->controlThread->currentStats.hardDiskCacheHits) + 1;
      *(_QWORD *)HIDWORD(v63) = v62;
      LODWORD(v65) = v58 - v56;
      LODWORD(v63) = HIDWORD(this->controlThread->currentStats.hardDiskSeeks)
                   + LODWORD(this->controlThread->currentStats.hardDiskSeeks);
      this->controlThread->currentStats.hardDiskSeeks = v63;
      v64 = LODWORD(this->controlThread->currentStats.hardDiskCacheTotalReadTime) - v56 + v58;
      this->controlThread->currentStats.hardDiskCacheTotalReadTime = *(_QWORD *)(&v59 - 1);
      HIDWORD(v65) = &this->controlThread->currentStats.hardDiskCacheMinReadTime;
      v66 = *(_QWORD *)HIDWORD(v65);
      if ( LODWORD(this->controlThread->currentStats.hardDiskCacheMinReadTime) >= v58 - v56 )
        LODWORD(v66) = v58 - v56;
      *(_QWORD *)HIDWORD(v65) = v66;
      if ( LODWORD(this->controlThread->currentStats.hardDiskCacheMaxReadTime) > (unsigned int)v65 )
        LODWORD(v65) = this->controlThread->currentStats.hardDiskCacheMaxReadTime;
      HIDWORD(v65) = &this->controlThread->currentStats.hardDiskCacheMaxReadTime;
      *(_QWORD *)HIDWORD(v65) = v65;
      *(_DWORD *)v28 = 4;
      Sys_InterlockedIncrement(value: (int *)(v28 + 56));
      Sys_InterlockedDecrement(value: (int *)(v28 + 48));
      v67 = this->controlThread;
      v67->hardDiskFinishedQueue.queue[v67->hardDiskFinishedQueue.queueEnd] = (idFileCacheLine *)v28;
      __lwsync();
      v67->hardDiskFinishedQueue.queueEnd = (v67->hardDiskFinishedQueue.queueEnd + 1) & 0xFFF;
      Sys_InterlockedIncrement(value: &v67->hardDiskFinishedQueue.numLines.value);
      v68 = v58;
      v69 = &idColor::colorRed;
      v70 = v56;
LABEL_57:
      console->AddTimeRange(this: console, a2: RANGE_STREAM_HD, a3: v69, a4: v70, a5: v68);
      goto LABEL_58;
    }
    this->hardDiskOffset = (*(_DWORD *)(v28 + 8) << 24) | (*(_DWORD *)(v28 + 12) + 1);
    v71 = Sys_Microseconds() >> 32;
    *(_DWORD *)(v28 + 20) = tempData;
    *(_DWORD *)(v28 + 24) = tempMemType;
    v72 = v71;
    HIDWORD(v73) = *(_DWORD *)(v28 + 28);
    LODWORD(v74) = *(_DWORD *)(v28 + 12);
    HIDWORD(v74) = &streamFileLog;
    v75 = v74 << 16;
    LODWORD(v76) = 0x10000;
    HIDWORD(v76) = (_DWORD)v74 << 16;
    idStreamFileLog::BeginIO(
      this: &streamFileLog,
      drive: SFL_HARD_DRIVE,
      io: SFL_READ,
      f: *(const idFile *const *)(v28 + 4),
      ofs: v76,
      len: v73,
      priority: v88);
    *(_DWORD *)(v28 + 16) = (*(int (__fastcall **)(_DWORD, _DWORD, _DWORD, int))(**(_DWORD **)(v28 + 4) + 20))(
                              a1: *(_DWORD *)(v28 + 4),
                              a2: v75,
                              a3: *(_DWORD *)(v28 + 20),
                              a4: 0x10000);
    idStreamFileLog::EndIO(this: &streamFileLog, drive: SFL_HARD_DRIVE);
    *(_DWORD *)(v28 + 4) = 0;
    HIDWORD(v77) = Sys_Microseconds() >> 32;
    v79 = HIDWORD(v77);
    if ( *(_DWORD *)(v28 + 16) != 0 )
    {
      HIDWORD(v82) = v89 ^ (v89 >> 31);
      LODWORD(v77) = LODWORD(this->controlThread->currentStats.hardDiskLinesRead) + 1;
      this->controlThread->currentStats.hardDiskLinesRead = v77;
      LODWORD(v84) = HIDWORD(v77) - v72;
      LODWORD(v82) = HIDWORD(this->controlThread->currentStats.hardDiskSeeks)
                   + LODWORD(this->controlThread->currentStats.hardDiskSeeks);
      this->controlThread->currentStats.hardDiskSeeks = v82;
      v83 = LODWORD(this->controlThread->currentStats.hardDiskLineTotalReadTime) - v72 + HIDWORD(v77);
      this->controlThread->currentStats.hardDiskLineTotalReadTime = *(_QWORD *)(&v78 - 1);
      HIDWORD(v84) = &this->controlThread->currentStats.hardDiskLineMinReadTime;
      v85 = *(_QWORD *)HIDWORD(v84);
      if ( LODWORD(this->controlThread->currentStats.hardDiskLineMinReadTime) >= v79 - v72 )
        LODWORD(v85) = v79 - v72;
      *(_QWORD *)HIDWORD(v84) = v85;
      if ( LODWORD(this->controlThread->currentStats.hardDiskLineMaxReadTime) > (unsigned int)v84 )
        LODWORD(v84) = this->controlThread->currentStats.hardDiskLineMaxReadTime;
      HIDWORD(v84) = &this->controlThread->currentStats.hardDiskLineMaxReadTime;
      *(_QWORD *)HIDWORD(v84) = v84;
      *(_DWORD *)v28 = 4;
      Sys_InterlockedIncrement(value: (int *)(v28 + 56));
      Sys_InterlockedDecrement(value: (int *)(v28 + 48));
      v86 = this->controlThread;
      v86->hardDiskFinishedQueue.queue[v86->hardDiskFinishedQueue.queueEnd] = (idFileCacheLine *)v28;
      __lwsync();
      v86->hardDiskFinishedQueue.queueEnd = (v86->hardDiskFinishedQueue.queueEnd + 1) & 0xFFF;
      Sys_InterlockedIncrement(value: &v86->hardDiskFinishedQueue.numLines.value);
      v68 = v79;
      v69 = &idColor::colorPurple;
      v70 = v72;
      goto LABEL_57;
    }
    *(_DWORD *)(v28 + 20) = 0;
    *(_DWORD *)(v28 + 24) = 0;
    idLocklessCacheLineHash::Remove(this: &this->controlThread->cacheLineHash, line: (idFileCacheLine *)v28);
    *(_DWORD *)v28 = 0;
    idLocklessCacheLineQueueM::Add(this: &this->controlThread->cacheLineFree, line: (idFileCacheLine *)v28);
    v80 = this->controlThread;
    LODWORD(v81) = LODWORD(v80->currentStats.hardDiskReadsFailed) + 1;
    v80->currentStats.hardDiskReadsFailed = v81;
    this->tempData = tempData;
    this->tempMemType = HIDWORD(v75);
    idLib::Warning(fmt: "failed to read cache line at %lld from the hard disk", (_DWORD)v75);
  }
  else
  {
LABEL_58:
    v87 = this->controlThread;
    if ( v87->hardDiskFinishedQueue.queueStart != v87->hardDiskFinishedQueue.queueEnd )
    {
      v87->threadSignalled = true;
      idSysThread::SignalWork(this: this->controlThread);
    }
  }
}


// ========================================================================
// ?Run@idHardDiskStreamThread@@UAAHXZ
// EA  : 0x826A3068
// RVA : 0x006A3068
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

int __fastcall idHardDiskStreamThread::Run(idHardDiskStreamThread *this)
{
  idStreamControlThread *controlThread; // r9
  idStreamControlThread *v3; // r11

  while ( 1 )
  {
    controlThread = this->controlThread;
    if ( controlThread->uncachedHardDiskRequestQueueStart == controlThread->uncachedHardDiskRequestQueueEnd )
    {
      v3 = this->controlThread;
      if ( controlThread->hardDiskReadQueue.queueStart == controlThread->hardDiskReadQueue.queueEnd
        && v3->hardDiskWriteQueue.queueStart == v3->hardDiskWriteQueue.queueEnd
        && !v3->serviceBinkHardDisk )
      {
        break;
      }
    }
    idHardDiskStreamThread::ProcessIO(this);
  }
  return 0;
}


// ========================================================================
// ?ProcessIO@idOpticalDiskStreamThread@@AAAXXZ
// EA  : 0x826A3108
// RVA : 0x006A3108
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idOpticalDiskStreamThread::ProcessIO(idOpticalDiskStreamThread *this)
{
  idStreamControlThread *controlThread; // r6
  idStreamControlThread::uncachedRequest_t *v3; // r30
  int v4; // r28
  __int64 v5; // r10
  __int128 v6; // r8
  int v7; // r7
  unsigned __int64 v8; // r3
  int queueStart; // r9
  idFileCacheLine *v10; // r30
  int valueInteger; // r18
  int *p_queueStart; // r28
  int v13; // r24
  int v14; // r3
  int v15; // r8
  idFileCacheLine *v16; // r11
  int priority; // r10
  int v18; // r11
  int v19; // r10
  idFileCacheLine *v20; // r11
  int v21; // r11
  int v22; // r11
  int v23; // r3
  unsigned __int64 v24; // r4
  memoryType_t tempMemType; // r27
  unsigned __int8 *tempData; // r29
  int opticalDiskOffset; // r24
  __int64 v28; // r10
  __int64 v29; // r8
  unsigned __int64 v30; // r7
  void (*AddTimeRange)(void); // ctr
  int v32; // r3
  int v33; // r26
  __int64 v34; // r10
  __int64 v35; // r4
  __int64 v36; // r28
  __int64 v37; // r8
  unsigned __int64 v38; // r6 OVERLAPPED
  int v39; // r3
  int v40; // r2 OVERLAPPED
  int v41; // r25
  idStreamControlThread *v42; // r8
  unsigned __int64 v43; // r6
  int v44; // r7
  int v45; // r3
  __int64 v46; // r11
  __int64 v47; // r9
  cacheLineState_t state; // r11
  bool v49; // r29
  idStreamControlThread *v50; // r11
  idLocklessCacheLineQueueS *p_hardDiskWriteQueue; // r11
  idStreamControlThread *v52; // r11
  idStreamControlThread *v53; // r11
  int v54; // [sp+8h] [-C8h]
  memoryType_t v55; // [sp+50h] [-80h] BYREF

  controlThread = this->controlThread;
  if ( controlThread->serviceBinkOpticalDisk )
  {
    controlThread->serviceBinkOpticalDisk = false;
    FillBinkBuffer();
    return;
  }
  if ( controlThread->uncachedOpticalDiskRequestQueueStart != controlThread->uncachedOpticalDiskRequestQueueEnd )
  {
    v3 = &controlThread->uncachedOpticalDiskRequestQueue[controlThread->uncachedOpticalDiskRequestQueueStart];
    v4 = Sys_Microseconds() >> 32;
    if ( *v3->dest == nullptr )
      *v3->dest = idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\engine\\framework\\StreamFileCache.cpp(3200) : request.tag",
                    size: v3->length,
                    tag: v3->tag,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_MAPHEAP);
    LODWORD(v5) = v3->length;
    HIDWORD(v5) = 99;
    *(_QWORD *)((char *)&v6 + 4) = v3->fileOfs;
    LODWORD(v6) = v5;
    idStreamFileLog::BeginIO(
      this: &streamFileLog,
      drive: SFL_OPTICAL_DRIVE,
      io: SFL_READ,
      f: v3->filePtr,
      ofs: v6,
      len: v5,
      priority: v54);
    (*(void (__fastcall **)(_DWORD, _DWORD, void *, int))(*(_DWORD *)HIDWORD(v3->fileOfs) + 20))(
      a1: HIDWORD(v3->fileOfs),
      a2: v3->fileOfs,
      a3: *v3->dest,
      a4: v3->length);
    idStreamFileLog::EndIO(this: &streamFileLog, drive: SFL_OPTICAL_DRIVE);
    v7 = Sys_Microseconds() >> 32;
    *v3->completionFlag = true;
    LODWORD(v8) = LODWORD(this->controlThread->currentStats.uncachedOpticalDiskReads) + 1;
    this->controlThread->currentStats.uncachedOpticalDiskReads = v8;
    LODWORD(v8) = HIDWORD(this->controlThread->currentStats.uncachedOpticalDiskReadSize)
                + LODWORD(this->controlThread->currentStats.uncachedOpticalDiskReadSize);
    this->controlThread->currentStats.uncachedOpticalDiskReadSize = v8;
    console->AddTimeRange(this: console, a2: RANGE_STREAM_OD, a3: &idColor::colorBlue, a4: v4, a5: v7);
    this->controlThread->uncachedOpticalDiskRequestQueueStart = (this->controlThread->uncachedOpticalDiskRequestQueueStart
                                                               + 1)
                                                              & 0x7FF;
    return;
  }
  queueStart = controlThread->opticalDiskReadQueue.queueStart;
  v10 = nullptr;
  valueInteger = fc_opticalDiskSkipOffset.valueInteger;
  p_queueStart = (int *)&controlThread->opticalDiskReadQueue.queueStart;
  v13 = 0;
  v14 = -1;
  v15 = -1;
  if ( queueStart != controlThread->opticalDiskReadQueue.queueEnd )
  {
    do
    {
      v16 = controlThread->opticalDiskReadQueue.queue[queueStart];
      if ( v16 != nullptr )
      {
        priority = v16->priority;
        v18 = ((v16->fileID << 24) | v16->fileLine) - this->opticalDiskOffset;
        if ( (int)abs32(v18) <= fc_opticalDiskNoSeekOffset.valueInteger )
        {
          if ( v18 < 0 )
            priority = v18 - fc_opticalDiskNoSeekOffset.valueInteger + 0x7FFFFFFF;
          else
            priority = 0x7FFFFFFF - v18;
        }
        if ( priority > v15 )
        {
          v14 = queueStart;
          v15 = priority;
          v13 = v18;
        }
      }
      queueStart = (queueStart + 1) & 0xFFF;
    }
    while ( queueStart != this->controlThread->opticalDiskReadQueue.queueEnd );
    if ( v13 < 0 )
      goto LABEL_18;
  }
  if ( v13 > fc_opticalDiskNoSeekOffset.valueInteger )
  {
LABEL_18:
    v19 = *p_queueStart;
    if ( *p_queueStart != controlThread->opticalDiskReadQueue.queueEnd )
    {
      do
      {
        v20 = controlThread->opticalDiskReadQueue.queue[v19];
        if ( v20 != nullptr )
        {
          v21 = ((v20->fileID << 24) | v20->fileLine) - this->opticalDiskOffset;
          if ( v21 < v13
            && v21 > v13 - fc_opticalDiskSkipOffset.valueInteger
            && (unsigned int)v21 >> 31 == (unsigned int)v13 >> 31 )
          {
            v14 = v19;
            v13 = v21;
            v19 = *p_queueStart + 4095;
          }
        }
        v19 = (v19 + 1) & 0xFFF;
      }
      while ( v19 != this->controlThread->opticalDiskReadQueue.queueEnd );
    }
  }
  if ( v14 != -1 )
  {
    v22 = 4 * (v14 + 91166);
    v10 = *(idFileCacheLine **)((char *)&controlThread->__vftable + v22);
    *(idStreamControlThread_vtbl **)((char *)&controlThread->__vftable + v22) = nullptr;
    Sys_InterlockedDecrement(value: &this->controlThread->opticalDiskReadQueue.numLines.value);
  }
  v23 = Sys_Milliseconds();
  HIDWORD(v24) = idStreamControlThread::CondenseCacheLineQueue(
                   this: this->controlThread,
                   queue: &this->controlThread->opticalDiskReadQueue,
                   timeOut: v23 - fc_opticalDiskRequestTimeOut.valueInteger);
  LODWORD(v24) = HIDWORD(this->controlThread->currentStats.opticalDiskTimeOuts)
               + LODWORD(this->controlThread->currentStats.opticalDiskTimeOuts);
  this->controlThread->currentStats.opticalDiskTimeOuts = v24;
  if ( v10 != nullptr )
  {
    tempMemType = this->tempMemType;
    tempData = this->tempData;
    this->tempData = nullptr;
    this->tempMemType = MEMORY_TYPE_INVALID;
    v55 = tempMemType;
    if ( tempData == nullptr )
    {
      tempData = idStreamControlThread::AllocLineBuffer(this: this->controlThread, returnedType: &v55);
      if ( tempData == nullptr )
      {
        idLocklessCacheLineHash::Remove(this: &this->controlThread->cacheLineHash, line: v10);
        v10->state = CACHE_LINE_STATE_FREE;
        idLocklessCacheLineQueueM::Add(this: &this->controlThread->cacheLineFree, line: v10);
        goto LABEL_46;
      }
      tempMemType = v55;
    }
    if ( v13 < 1 || v13 > valueInteger )
    {
      this->opticalDiskOffset = (v10->fileID << 24) | (v10->fileLine + 1);
      v32 = Sys_Microseconds() >> 32;
      v10->data = tempData;
      v10->memType = tempMemType;
      v33 = v32;
      HIDWORD(v34) = v10->priority;
      LODWORD(v35) = v10->fileLine;
      HIDWORD(v35) = &streamFileLog;
      v36 = v35 << 16;
      LODWORD(v37) = 0x10000;
      HIDWORD(v37) = (_DWORD)v35 << 16;
      idStreamFileLog::BeginIO(
        this: &streamFileLog,
        drive: SFL_OPTICAL_DRIVE,
        io: SFL_READ,
        f: v10->filePtr,
        ofs: v37,
        len: v34,
        priority: v54);
      v10->validLength = v10->filePtr->ReadOfs(this: v10->filePtr, a2: (unsigned int)v36, a3: tempData, a4: 0x10000u);
      idStreamFileLog::EndIO(this: &streamFileLog, drive: SFL_OPTICAL_DRIVE);
      v10->filePtr = nullptr;
      v39 = Sys_Microseconds() >> 32;
      v41 = v39;
      if ( v10->validLength == 0 )
      {
        v10->data = nullptr;
        v10->memType = MEMORY_TYPE_INVALID;
        idLocklessCacheLineHash::Remove(this: &this->controlThread->cacheLineHash, line: v10);
        v10->state = CACHE_LINE_STATE_FREE;
        idLocklessCacheLineQueueM::Add(this: &this->controlThread->cacheLineFree, line: v10);
        v42 = this->controlThread;
        LODWORD(v43) = LODWORD(v42->currentStats.opticalDiskReadsFailed) + 1;
        v42->currentStats.opticalDiskReadsFailed = v43;
        this->tempData = tempData;
        this->tempMemType = HIDWORD(v36);
        idLib::Warning(fmt: "failed to read cache line at %lld from the optical disk", (_DWORD)v36);
        return;
      }
      LODWORD(v38) = LODWORD(this->controlThread->currentStats.opticalDiskLinesRead) + 1;
      this->controlThread->currentStats.opticalDiskLinesRead = v38;
      LODWORD(v46) = v39 - v33;
      v44 = HIDWORD(this->controlThread->currentStats.opticalDiskSeeks)
          + LODWORD(this->controlThread->currentStats.opticalDiskSeeks);
      this->controlThread->currentStats.opticalDiskSeeks = *(unsigned __int64 *)((char *)&v38 - 4);
      v45 = LODWORD(this->controlThread->currentStats.opticalDiskLineTotalReadTime) - v33 + v39;
      this->controlThread->currentStats.opticalDiskLineTotalReadTime = *(_QWORD *)(&v40 - 1);
      HIDWORD(v46) = &this->controlThread->currentStats.opticalDiskLineMinReadTime;
      v47 = *(_QWORD *)HIDWORD(v46);
      if ( LODWORD(this->controlThread->currentStats.opticalDiskLineMinReadTime) >= v41 - v33 )
        LODWORD(v47) = v41 - v33;
      *(_QWORD *)HIDWORD(v46) = v47;
      if ( LODWORD(this->controlThread->currentStats.opticalDiskLineMaxReadTime) > (unsigned int)v46 )
        LODWORD(v46) = this->controlThread->currentStats.opticalDiskLineMaxReadTime;
      HIDWORD(v46) = &this->controlThread->currentStats.opticalDiskLineMaxReadTime;
      *(_QWORD *)HIDWORD(v46) = v46;
      state = v10->state;
      v10->state = CACHE_LINE_STATE_VALID;
      v49 = state != CACHE_LINE_STATE_READ_OPTICAL_DISK_NO_WRITE_BACK;
      Sys_InterlockedIncrement(value: &v10->pinned.value);
      Sys_InterlockedDecrement(value: &v10->modifyLock.value);
      v50 = this->controlThread;
      if ( v49 )
        p_hardDiskWriteQueue = &v50->hardDiskWriteQueue;
      else
        p_hardDiskWriteQueue = &v50->opticalDiskFinishedQueue;
      p_hardDiskWriteQueue->queue[p_hardDiskWriteQueue->queueEnd] = v10;
      __lwsync();
      p_hardDiskWriteQueue->queueEnd = (p_hardDiskWriteQueue->queueEnd + 1) & 0xFFF;
      Sys_InterlockedIncrement(value: &p_hardDiskWriteQueue->numLines.value);
      AddTimeRange = (void (*)(void))console->AddTimeRange;
    }
    else
    {
      opticalDiskOffset = this->opticalDiskOffset;
      this->opticalDiskOffset = opticalDiskOffset + 1;
      Sys_Microseconds();
      HIDWORD(v28) = v10->priority;
      opticalDiskOffset <<= 16;
      HIDWORD(v29) = opticalDiskOffset;
      LODWORD(v29) = 0x10000;
      idStreamFileLog::BeginIO(
        this: &streamFileLog,
        drive: SFL_OPTICAL_DRIVE,
        io: SFL_READ,
        f: v10->filePtr,
        ofs: v29,
        len: v28,
        priority: v54);
      v10->filePtr->ReadOfs(this: v10->filePtr, a2: opticalDiskOffset, a3: tempData, a4: 0x10000u);
      idStreamFileLog::EndIO(this: &streamFileLog, drive: SFL_OPTICAL_DRIVE);
      Sys_Microseconds();
      LODWORD(v30) = LODWORD(this->controlThread->currentStats.opticalDiskSkips) + 1;
      this->controlThread->currentStats.opticalDiskSkips = v30;
      this->tempData = tempData;
      this->tempMemType = tempMemType;
      this->controlThread->opticalDiskReadQueue.queueStart = (this->controlThread->opticalDiskReadQueue.queueStart - 1)
                                                           & 0xFFF;
      this->controlThread->opticalDiskReadQueue.queue[this->controlThread->opticalDiskReadQueue.queueStart] = v10;
      Sys_InterlockedIncrement(value: &this->controlThread->opticalDiskReadQueue.numLines.value);
      AddTimeRange = (void (*)(void))console->AddTimeRange;
    }
    AddTimeRange();
  }
LABEL_46:
  v52 = this->controlThread;
  if ( v52->hardDiskWriteQueue.queueStart != v52->hardDiskWriteQueue.queueEnd )
  {
    v52->threadSignalled = true;
    idSysThread::SignalWork(this: this->controlThread->hardDiskThread);
  }
  v53 = this->controlThread;
  if ( v53->opticalDiskFinishedQueue.queueStart != v53->opticalDiskFinishedQueue.queueEnd )
  {
    v53->threadSignalled = true;
    idSysThread::SignalWork(this: this->controlThread);
  }
}


// ========================================================================
// ?Run@idOpticalDiskStreamThread@@UAAHXZ
// EA  : 0x826A38F0
// RVA : 0x006A38F0
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

int __fastcall idOpticalDiskStreamThread::Run(idOpticalDiskStreamThread *this)
{
  idStreamControlThread *controlThread; // r9

  while ( 1 )
  {
    controlThread = this->controlThread;
    if ( controlThread->uncachedOpticalDiskRequestQueueStart == controlThread->uncachedOpticalDiskRequestQueueEnd
      && controlThread->opticalDiskReadQueue.queueStart == controlThread->opticalDiskReadQueue.queueEnd
      && !this->controlThread->serviceBinkOpticalDisk )
    {
      break;
    }
    idOpticalDiskStreamThread::ProcessIO(this);
  }
  return 0;
}


// ========================================================================
// ?ReleaseCacheLines@idStreamControlThread@@QAAXQAPAVidFileCacheLine@@H@Z
// EA  : 0x826A3970
// RVA : 0x006A3970
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamControlThread::ReleaseCacheLines(
        idStreamControlThread *this,
        idFileCacheLine **readLines,
        int numReadLines)
{
  idFileCacheLine **v3; // r30
  int i; // r31

  if ( numReadLines > 0 )
  {
    v3 = readLines - 1;
    for ( i = numReadLines; i != 0; --i )
      Sys_InterlockedDecrement(value: &(*++v3)->pinned.value);
  }
}


// ========================================================================
// ?ProvideCacheMemory@idStreamControlThread@@QAAXQAX_J@Z
// EA  : 0x826A39C0
// RVA : 0x006A39C0
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamControlThread::ProvideCacheMemory(idStreamControlThread *this, char *base, __int64 length)
{
  int v5; // r27
  int v6; // r29
  unsigned __int8 **providedLineBuffers; // r26
  int v8; // r30
  void **v9; // r31

  v5 = HIDWORD(length);
  v6 = 0;
  if ( SHIDWORD(length) > 0 )
  {
    providedLineBuffers = this->providedLineBuffers;
    do
    {
      v8 = 0;
      v9 = (void **)providedLineBuffers;
      while ( *v9 != nullptr
           || Sys_InterlockedCompareExchange(ptr: v9, comparand: nullptr, exchange: &base[v6]) != nullptr )
      {
        ++v8;
        ++v9;
        if ( v8 >= 1024 )
          goto LABEL_9;
      }
      Sys_InterlockedIncrement(value: &this->providedLineBuffersTotal.value);
LABEL_9:
      v6 += 0x10000;
    }
    while ( v6 < v5 );
  }
}


// ========================================================================
// ?FreeLRU@idStreamControlThread@@QAA_NXZ
// EA  : 0x826A3A58
// RVA : 0x006A3A58
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

int __fastcall idStreamControlThread::FreeLRU(idStreamControlThread *this)
{
  volatile int v1; // r9
  idFileCacheLine *LineBufferLRU; // r3
  memoryType_t v5[4]; // [sp+50h] [-20h] BYREF

  v1 = this->numFreeLRU + 1;
  v5[0] = MEMORY_TYPE_INVALID;
  this->numFreeLRU = v1;
  LineBufferLRU = idStreamControlThread::GetLineBufferLRU(this, requestedType: MEMORY_TYPE_ALLOCATED, returnedType: v5);
  if ( LineBufferLRU == nullptr )
    return 0;
  if ( v5[0] == MEMORY_TYPE_ALLOCATED )
  {
    XMemFree(pAddress: LineBufferLRU, dwAllocAttributes: 0xAC320000);
    Sys_InterlockedDecrement(value: &this->totalUsedLineBuffers.value);
    return 1;
  }
  else
  {
    if ( v5[0] == MEMORY_TYPE_PROVIDED )
    {
      idStreamControlThread::FreeProvidedLineBuffer(this, ptr: (unsigned __int8 *)LineBufferLRU, freed: true);
      Sys_InterlockedDecrement(value: &this->totalUsedLineBuffers.value);
    }
    return 1;
  }
}


// ========================================================================
// ?PrintStats@idStreamControlThread@@QAAXXZ
// EA  : 0x826A3B20
// RVA : 0x006A3B20
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idStreamControlThread::PrintStats(idStreamControlThread *this)
{
  int v2; // r8
  int v3; // ctr
  idStreamControlThread::hdCache_t *hdc; // r7
  unsigned int *v5; // r11
  int v6; // r11
  int v7; // r20
  int v8; // r9
  idFileCacheLine **p_cacheLineAlloc; // r7
  int i; // ctr
  idFileCacheLine *v11; // r11
  int value; // r6
  int v13; // r30
  int v14; // r29
  char *v15; // r11
  const char *v16; // r7
  unsigned int v17; // r11
  const char *v18; // r4
  unsigned __int64 *p_opticalDiskLinesRead; // r24
  unsigned __int64 v20; // r30
  int providedLineBuffersMaxCommitted; // r26
  __int64 v22; // r9
  int v23; // r23
  int v24; // r22
  int v25; // r28
  __int64 v26; // r5
  __int64 v27; // r11
  __int64 v28; // r8
  __int64 v29; // r5
  __int64 v30; // r9
  __int64 v31; // r10
  double v32; // r5
  int v33; // r3
  unsigned __int64 v34; // r9 OVERLAPPED
  __int128 v35; // r6 OVERLAPPED
  char *v36; // r8 OVERLAPPED
  __int128 v37; // r7 OVERLAPPED
  unsigned __int64 v38; // r11
  __int128 v39; // r5 OVERLAPPED
  unsigned __int64 v40; // r8
  unsigned __int64 v41; // r11
  unsigned __int64 v42; // r11 OVERLAPPED
  unsigned __int64 hardDiskLineTotalReadTime; // r4
  __int128 v44; // r9
  unsigned __int64 v45; // r11 OVERLAPPED
  __int128 v46; // r9 OVERLAPPED
  unsigned __int64 hardDiskCacheHits; // r11 OVERLAPPED
  __int128 v48; // r9 OVERLAPPED
  unsigned __int64 hardDiskCacheLinesWritten; // r11 OVERLAPPED
  __int128 v50; // r9 OVERLAPPED
  int v51; // r4
  double v52; // fp1
  int v53; // r4
  double v54; // [sp+20h] [-4C0h]
  _DWORD v55[128]; // [sp+60h] [-480h] BYREF
  _DWORD v56[130]; // [sp+260h] [-280h] BYREF

  idStreamControlThread::WaitForCompletion(this);
  memset(Dst: v55, Val: 0, Size: sizeof(v55));
  v2 = 33804;
  v3 = 4096;
  hdc = this->hdc;
  v5 = &hdc->hdLines[1];
  do
  {
    v6 = *((unsigned __int8 *)v5 - 4);
    if ( v6 < 128 )
      ++v55[v6];
    if ( *((unsigned __int8 *)&hdc->magic1 + v2) < 0x80u )
      ++v55[*((unsigned __int8 *)&hdc->magic1 + v2)];
    if ( (unsigned __int8)hdc->cachedFiles[0].name[v2] < 0x80u )
      ++v55[(unsigned __int8)hdc->cachedFiles[0].name[v2]];
    if ( (unsigned __int8)hdc->cachedFiles[0].name[v2 + 4] < 0x80u )
      ++v55[(unsigned __int8)hdc->cachedFiles[0].name[v2 + 4]];
    v2 += 16;
    v5 = (unsigned int *)((char *)hdc + v2);
    --v3;
  }
  while ( v3 != 0 );
  v7 = 0;
  memset(Dst: v56, Val: 0, Size: 0x200u);
  v8 = 0;
  p_cacheLineAlloc = &this->cacheLineAlloc;
  for ( i = 2048; i != 0; --i )
  {
    if ( (*p_cacheLineAlloc)[v8].indexMRU != -1 )
    {
      v11 = &(*p_cacheLineAlloc)[v8];
      value = v11->pinned.value;
      ++v56[v11->fileID];
      if ( value > 0 )
        ++v7;
    }
    ++v8;
  }
  idLib::Printf(fmt: "SRC     HDC      MEM  File\n");
  idLib::Printf(fmt: "------------------------------------\n");
  v13 = 0;
  v14 = 0;
  do
  {
    v15 = (char *)this->hdc + v13;
    v16 = v15 + 4;
    if ( v15[4] != 0 )
    {
      v17 = *((_DWORD *)v15 + 65);
      v18 = "?";
      if ( v17 <= 4 )
      {
        switch ( v17 )
        {
          case 1u:
            v18 = "ODD";
            break;
          case 2u:
            v18 = "SSD";
            break;
          case 3u:
LABEL_49:
            break;
          default:
            if ( v17 != 0 )
              v18 = "MEM";
            else
              v18 = "HDD";
            goto LABEL_49;
        }
      }
      idLib::Printf(fmt: "%s %7d  %7d  %s\n", v18, v55[v14], v56[v14], v16);
    }
    v13 += 264;
    ++v14;
  }
  while ( v13 < 33792 );
  idLib::Printf(fmt: "------------------------------------\n");
  HIDWORD(v20) = &this->currentStats.hardDiskLinesRead;
  p_opticalDiskLinesRead = &this->currentStats.opticalDiskLinesRead;
  LODWORD(v20) = HIDWORD(this->currentStats.memoryCacheHits)
               + LODWORD(this->currentStats.memoryCacheHits)
               + LODWORD(this->currentStats.hardDiskCacheHits)
               + LODWORD(this->currentStats.opticalDiskLinesRead);
  if ( (unsigned int)v20 <= 1 )
    LODWORD(v20) = 1;
  if ( this->providedLineBuffersMaxCommitted < 0 )
    providedLineBuffersMaxCommitted = this->providedLineBuffersTotal.value;
  else
    providedLineBuffersMaxCommitted = this->providedLineBuffersMaxCommitted;
  LODWORD(v22) = this->providedLineBuffersTotal.value << 16;
  HIDWORD(v22) = 0x80000;
  v23 = this->providedLineBuffersUsed.value;
  v24 = this->totalUsedLineBuffers.value;
  v25 = 2048 - this->cacheLineFree.numLines.value;
  idLib::Printf(
    fmt: "%8d provided line buffers total (%1.1f MB)\n",
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v22 * (float)0.00000095367432))),
    (float)((float)v22 * (float)0.00000095367432));
  LODWORD(v26) = providedLineBuffersMaxCommitted << 16;
  idLib::Printf(
    fmt: "%8d provided line buffers max commit (%1.1f MB)\n",
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v26 * (float)0.00000095367432))),
    (float)((float)v26 * (float)0.00000095367432));
  LODWORD(v27) = v23 << 16;
  idLib::Printf(
    fmt: "%8d provided line buffers used (%1.1f MB)\n",
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v27 * (float)0.00000095367432))),
    (float)((float)v27 * (float)0.00000095367432));
  LODWORD(v28) = (v24 - v23) << 16;
  idLib::Printf(
    fmt: "%8d allocated line buffers (%1.1f MB)\n",
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v28 * (float)0.00000095367432))),
    (float)((float)v28 * (float)0.00000095367432));
  LODWORD(v29) = v24 << 16;
  idLib::Printf(
    fmt: "%8d total used line buffers (%1.1f MB)\n",
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v29 * (float)0.00000095367432))),
    (float)((float)v29 * (float)0.00000095367432));
  idLib::Printf(fmt: "%8d max cache lines (%1.1f MB)\n", 2048, 128.0);
  LODWORD(v30) = v25 << 16;
  idLib::Printf(
    fmt: "%8d used cache lines (%1.1f MB)\n",
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v30 * (float)0.00000095367432))),
    (float)((float)v30 * (float)0.00000095367432));
  HIDWORD(v31) = 458752;
  LODWORD(v31) = this->cacheLineMRU.numLines.value << 16;
  v32 = (float)((float)v31 * (float)0.00000095367432);
  idLib::Printf(fmt: "%8d MRU cache lines (%1.1f MB, range spanned = %d)\n", HIDWORD(v32), v32, LODWORD(v32));
  v33 = idLocklessCacheLineHash::MaxHashChain(this: &this->cacheLineHash);
  idLib::Printf(fmt: "%8d hashed cache lines (max chain = %d)\n", this->cacheLineHash.numLines.value, v33);
  idLib::Printf(fmt: "%8d pinned cache lines\n", v7);
  __tdllei(v20, 0);
  idLib::Printf(fmt: (const char *)HIDWORD(this->currentStats.memoryCacheHits));
  LODWORD(v34) = 100 * LODWORD(this->currentStats.hardDiskCacheHits);
  *(_QWORD *)((char *)&v35 + 4) = v34 / v20;
  __tdllei(v20, 0);
  idLib::Printf(fmt: "%8lld hard disk cache hits (%lld%%)\n", (_QWORD)v35, *(unsigned __int64 *)((char *)&v34 + 4));
  v36 = "_AI_OBSTACLE";
  LODWORD(v37) = 100 * LODWORD(this->currentStats.hardDiskLinesRead);
  *(_QWORD *)&v37 = (unsigned __int64)v37 / v20;
  __tdllei(v20, 0);
  idLib::Printf(fmt: "%8lld hard disk source lines read (%lld%%)\n", *(_QWORD *)((char *)&v37 + 4), *(_QWORD *)&v36);
  idLib::Printf(
    fmt: (const char *)HIDWORD(this->currentStats.hardDiskCacheLinesWritten),
    LODWORD(this->currentStats.hardDiskCacheLinesWritten));
  LODWORD(v38) = HIDWORD(this->currentStats.hardDiskCacheHits) + LODWORD(this->currentStats.hardDiskCacheHits);
  if ( (unsigned int)v38 <= 1 )
    LODWORD(v38) = 1;
  HIDWORD(v38) = 0x80000;
  __tdllei(v38, 0);
  idLib::Printf(fmt: (const char *)HIDWORD(this->currentStats.hardDiskSeeks));
  idLib::Printf(
    fmt: (const char *)HIDWORD(this->currentStats.hardDiskTimeOuts),
    LODWORD(this->currentStats.hardDiskTimeOuts));
  idLib::Printf(
    fmt: (const char *)HIDWORD(this->currentStats.hardDiskReadsFailed),
    LODWORD(this->currentStats.hardDiskReadsFailed));
  *(_QWORD *)((char *)&v39 + 4) = *p_opticalDiskLinesRead;
  __tdllei(v20, 0);
  LODWORD(v40) = 100 * DWORD2(v39);
  *((_QWORD *)&v39 + 1) = v40 / v20;
  idLib::Printf(fmt: "%8lld optical disk source lines read (%lld%%)\n", *(_QWORD *)((char *)&v39 - 4), v40);
  v41 = *p_opticalDiskLinesRead;
  if ( LODWORD(this->currentStats.opticalDiskLinesRead) <= 1 )
    LODWORD(v41) = 1;
  HIDWORD(v41) = 0x80000;
  __tdllei(v41, 0);
  idLib::Printf(fmt: (const char *)HIDWORD(this->currentStats.opticalDiskSeeks));
  idLib::Printf(
    fmt: (const char *)HIDWORD(this->currentStats.opticalDiskSkips),
    LODWORD(this->currentStats.opticalDiskSkips));
  idLib::Printf(
    fmt: (const char *)HIDWORD(this->currentStats.opticalDiskTimeOuts),
    LODWORD(this->currentStats.opticalDiskTimeOuts));
  idLib::Printf(
    fmt: (const char *)HIDWORD(this->currentStats.opticalDiskReadsFailed),
    LODWORD(this->currentStats.opticalDiskReadsFailed));
  v42 = *(_QWORD *)HIDWORD(v20);
  if ( LODWORD(this->currentStats.hardDiskLinesRead) <= 1 )
    LODWORD(v42) = 1;
  HIDWORD(v42) = 0x80000;
  LODWORD(v20) = 1000;
  hardDiskLineTotalReadTime = this->currentStats.hardDiskLineTotalReadTime;
  HIDWORD(hardDiskLineTotalReadTime) = "_AI_OBSTACLE";
  __tdllei(v42, 0);
  *(unsigned __int64 *)((char *)&v42 + 4) = this->currentStats.hardDiskLineMaxReadTime;
  *((_QWORD *)&v44 + 1) = hardDiskLineTotalReadTime / v42;
  *(_QWORD *)((char *)&v44 + 4) = this->currentStats.hardDiskLineMinReadTime;
  idLib::Printf(
    fmt: (const char *)(((unsigned __int64)v44 / v20) >> 32),
    (unsigned int)((unsigned __int64)v44 / v20),
    (unsigned int)(*(_QWORD *)((char *)&v44 + 4) / v20),
    (unsigned int)(*(unsigned __int64 *)((char *)&v42 + 4) / v20));
  v45 = *p_opticalDiskLinesRead;
  if ( LODWORD(this->currentStats.opticalDiskLinesRead) <= 1 )
    LODWORD(v45) = 1;
  *(unsigned __int64 *)((char *)&v45 + 4) = this->currentStats.opticalDiskLineTotalReadTime;
  __tdllei(v45, 0);
  *((_QWORD *)&v46 + 1) = this->currentStats.opticalDiskLineMaxReadTime;
  *(_QWORD *)((char *)&v46 + 4) = *(unsigned __int64 *)((char *)&v45 + 4) / v45;
  *(_QWORD *)&v46 = this->currentStats.opticalDiskLineMinReadTime;
  *(_QWORD *)((char *)&v46 + 12) = (unsigned __int64)v46 / v20;
  idLib::Printf(
    fmt: (const char *)((*(_QWORD *)((char *)&v46 + 4) / v20) >> 32),
    (unsigned int)(*(_QWORD *)((char *)&v46 + 4) / v20),
    (unsigned int)(*(_QWORD *)&v46 / v20),
    (unsigned int)((unsigned __int64)v46 / v20));
  hardDiskCacheHits = this->currentStats.hardDiskCacheHits;
  if ( LODWORD(this->currentStats.hardDiskCacheHits) <= 1 )
    LODWORD(hardDiskCacheHits) = 1;
  *(unsigned __int64 *)((char *)&hardDiskCacheHits + 4) = this->currentStats.hardDiskCacheTotalReadTime;
  __tdllei(hardDiskCacheHits, 0);
  *((_QWORD *)&v48 + 1) = this->currentStats.hardDiskCacheMaxReadTime;
  *(_QWORD *)((char *)&v48 + 4) = *(unsigned __int64 *)((char *)&hardDiskCacheHits + 4) / hardDiskCacheHits;
  *(_QWORD *)&v48 = this->currentStats.hardDiskCacheMinReadTime;
  *(_QWORD *)((char *)&v48 + 12) = (unsigned __int64)v48 / v20;
  idLib::Printf(
    fmt: (const char *)((*(_QWORD *)((char *)&v48 + 4) / v20) >> 32),
    (unsigned int)(*(_QWORD *)((char *)&v48 + 4) / v20),
    (unsigned int)(*(_QWORD *)&v48 / v20),
    (unsigned int)((unsigned __int64)v48 / v20));
  hardDiskCacheLinesWritten = this->currentStats.hardDiskCacheLinesWritten;
  if ( LODWORD(this->currentStats.hardDiskCacheLinesWritten) <= 1 )
    LODWORD(hardDiskCacheLinesWritten) = 1;
  *(unsigned __int64 *)((char *)&hardDiskCacheLinesWritten + 4) = this->currentStats.hardDiskCacheTotalWriteTime;
  __tdllei(hardDiskCacheLinesWritten, 0);
  *((_QWORD *)&v50 + 1) = this->currentStats.hardDiskCacheMaxWriteTime;
  *(_QWORD *)((char *)&v50 + 4) = *(unsigned __int64 *)((char *)&hardDiskCacheLinesWritten + 4)
                                / hardDiskCacheLinesWritten;
  *(_QWORD *)&v50 = this->currentStats.hardDiskCacheMinWriteTime;
  *(_QWORD *)((char *)&v50 + 12) = (unsigned __int64)v50 / v20;
  idLib::Printf(
    fmt: (const char *)((*(_QWORD *)((char *)&v50 + 4) / v20) >> 32),
    (unsigned int)(*(_QWORD *)((char *)&v50 + 4) / v20),
    (unsigned int)(*(_QWORD *)&v50 / v20),
    (unsigned int)((unsigned __int64)v50 / v20));
  v52 = _u64tod(a1: this->currentStats.uncachedHardDiskReadSize, a2: v51);
  idLib::Printf(
    fmt: (const char *)HIDWORD(this->currentStats.uncachedHardDiskReads),
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v52 * (float)0.00000095367432))),
    (unsigned int)COERCE_UNSIGNED_INT64((float)((float)v52 * (float)0.00000095367432)));
  v54 = (float)((float)_u64tod(a1: this->currentStats.uncachedOpticalDiskReadSize, a2: v53) * (float)0.00000095367432);
  idLib::Printf(fmt: (const char *)HIDWORD(this->currentStats.uncachedOpticalDiskReads), HIDWORD(v54), LODWORD(v54));
}


// ========================================================================
// ?GetCurrentUsageLimit@idStreamControlThread@@QBA_JXZ
// EA  : 0x826A4368
// RVA : 0x006A4368
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

int __fastcall idStreamControlThread::GetCurrentUsageLimit(idStreamControlThread *this)
{
  double valueFloat; // fp31
  int value; // r31

  valueFloat = mem_reserveForSystem.valueFloat;
  value = this->totalUsedLineBuffers.value;
  return Sys_GetFreeMemory() + (value << 16) - (__int64)(float)((float)valueFloat * (float)1048576.0);
}


// ========================================================================
// ?Shutdown@idStreamFileCache@@QAAXXZ
// EA  : 0x826A43E8
// RVA : 0x006A43E8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamFileCache::Shutdown(idStreamFileCache *this)
{
  idStreamControlThread *controlThread; // r3
  idStreamControlThread *v3; // r3

  Sys_MutexLock(handle: &this->interfaceMutex.handle, blocking: true);
  controlThread = this->controlThread;
  if ( controlThread != nullptr )
  {
    idStreamControlThread::Shutdown(this: controlThread);
    v3 = this->controlThread;
    if ( v3 != nullptr )
      ((void (__fastcall *)(idStreamControlThread *, int))v3->dtr_idSysThread)(a1: v3, a2: 1);
    this->controlThread = nullptr;
  }
  Sys_MutexUnlock(handle: &this->interfaceMutex.handle);
}


// ========================================================================
// __unwind$224013
// EA  : 0x826A4468
// RVA : 0x006A4468
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_224013()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 112 + 80));
}


// ========================================================================
// ?Flush@idStreamFileCache@@QAAXXZ
// EA  : 0x826A4498
// RVA : 0x006A4498
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamFileCache::Flush(idStreamFileCache *this)
{
  Sys_MutexLock(handle: &this->interfaceMutex.handle, blocking: true);
  idStreamControlThread::WaitForCompletion(this: this->controlThread);
  Sys_MutexUnlock(handle: &this->interfaceMutex.handle);
}


// ========================================================================
// __unwind$224084
// EA  : 0x826A44E8
// RVA : 0x006A44E8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_224084()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 112 + 80));
}


// ========================================================================
// ?GetCurrentUsageLimit@idStreamFileCache@@QBA_JXZ
// EA  : 0x826A4510
// RVA : 0x006A4510
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

int __fastcall idStreamFileCache::GetCurrentUsageLimit(idStreamFileCache *this)
{
  return idStreamControlThread::GetCurrentUsageLimit(this: this->controlThread);
}


// ========================================================================
// ?Stats@idStreamFileCache@@QAAXXZ
// EA  : 0x826A4520
// RVA : 0x006A4520
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamFileCache::Stats(idStreamFileCache *this)
{
  Sys_MutexLock(handle: &this->interfaceMutex.handle, blocking: true);
  idStreamControlThread::PrintStats(this: this->controlThread);
  Sys_MutexUnlock(handle: &this->interfaceMutex.handle);
}


// ========================================================================
// __unwind$224121
// EA  : 0x826A4570
// RVA : 0x006A4570
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_224121()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 112 + 80));
}


// ========================================================================
// ?SignalWork@idStreamFileCache@@QAAXXZ
// EA  : 0x826A45A0
// RVA : 0x006A45A0
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamFileCache::SignalWork(idStreamFileCache *this)
{
  Sys_MutexLock(handle: &this->interfaceMutex.handle, blocking: true);
  idSysThread::SignalWork(this: this->controlThread);
  Sys_MutexUnlock(handle: &this->interfaceMutex.handle);
}


// ========================================================================
// __unwind$224156
// EA  : 0x826A45F0
// RVA : 0x006A45F0
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_224156()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 112 + 80));
}


// ========================================================================
// ?UncachedBackgroundRead@idStreamFileCache@@QAAXPAVidFile@@_JHPAPAXW4memTag_t@@PC_N@Z
// EA  : 0x826A4620
// RVA : 0x006A4620
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamFileCache::UncachedBackgroundRead(
        idStreamFileCache *this,
        idFile *cacheFile,
        __int64 ofs,
        int length,
        void **dest,
        memTag_t tag,
        volatile bool *completionFlag)
{
  unsigned int v9; // r28
  unsigned int v10; // r27
  volatile bool *v14; // r10

  v9 = HIDWORD(ofs);
  v10 = ofs;
  Sys_MutexLock(handle: &this->interfaceMutex.handle, blocking: true);
  idStreamControlThread::UncachedBackgroundRead(
    this: this->controlThread,
    cacheFile,
    ofs: __SPAIR64__(v9, v10),
    length,
    dest,
    tag,
    completionFlag: v14);
  Sys_MutexUnlock(handle: &this->interfaceMutex.handle);
}


// ========================================================================
// __unwind$224191
// EA  : 0x826A4688
// RVA : 0x006A4688
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_224191()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 160 + 80));
}


// ========================================================================
// ?BatchUncachedBackgroundRead@idStreamFileCache@@QAAXPAVidFile@@QA_JQAHQAPAPAXW4memTag_t@@QAPC_NH@Z
// EA  : 0x826A46B8
// RVA : 0x006A46B8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamFileCache::BatchUncachedBackgroundRead(
        idStreamFileCache *this,
        idFile *cacheFile,
        __int64 *ofs,
        char *length,
        void ***dest,
        memTag_t tag,
        volatile bool **completionFlag,
        int numReads)
{
  Sys_MutexLock(handle: &this->interfaceMutex.handle, blocking: true);
  idStreamControlThread::BatchUncachedBackgroundRead(
    this: this->controlThread,
    cacheFile,
    ofs,
    length,
    dest,
    tag,
    completionFlag,
    numReads);
  Sys_MutexUnlock(handle: &this->interfaceMutex.handle);
}


// ========================================================================
// __unwind$224227
// EA  : 0x826A4728
// RVA : 0x006A4728
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_224227()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 176 + 80));
}


// ========================================================================
// ?UncachedScheduledRead@idStreamFileCache@@QAAIQAVidFile@@_JQAXH@Z
// EA  : 0x826A4750
// RVA : 0x006A4750
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void *__fastcall idStreamFileCache::UncachedScheduledRead(
        idStreamFileCache *this,
        idFile *const file,
        __int64 ofs,
        void *const dest,
        const int length,
        int a6,
        volatile bool *a7)
{
  _BYTE v10[4]; // [sp+50h] [-20h] BYREF
  int v11; // [sp+54h] [-1Ch] BYREF

  v11 = ofs;
  v10[0] = 0;
  LODWORD(ofs) = dest;
  idStreamFileCache::UncachedBackgroundRead(
    this,
    cacheFile: file,
    ofs,
    length: (int)&v11,
    dest: (void **)0x32,
    tag: (memTag_t)v10,
    completionFlag: a7);
  idStreamFileCache::SignalWork(this);
  while ( v10[0] == 0 )
  {
    if ( this->cancelToTerminate )
      break;
    mgthread_sleep(ms: 1);
  }
  return dest;
}


// ========================================================================
// ?BatchFreeMemory@idStreamFileCache@@QAAXQAPAXH@Z
// EA  : 0x826A47E8
// RVA : 0x006A47E8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamFileCache::BatchFreeMemory(idStreamFileCache *this, void **block, int numBlocks)
{
  Sys_MutexLock(handle: &this->interfaceMutex.handle, blocking: true);
  idStreamControlThread::BatchFreeMemory(this: this->controlThread, block, numBlocks);
  Sys_MutexUnlock(handle: &this->interfaceMutex.handle);
}


// ========================================================================
// __unwind$224309
// EA  : 0x826A4830
// RVA : 0x006A4830
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_224309()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 128 + 80));
}


// ========================================================================
// ?ProvideCacheMemory@idStreamFileCache@@QAAXQAX_J@Z
// EA  : 0x826A4860
// RVA : 0x006A4860
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamFileCache::ProvideCacheMemory(idStreamFileCache *this, char *base, __int64 length)
{
  int v5; // r28
  __int64 v6; // r6

  v5 = HIDWORD(length);
  Sys_MutexLock(handle: &this->interfaceMutex.handle, blocking: true);
  HIDWORD(v6) = v5;
  idStreamControlThread::ProvideCacheMemory(this: this->controlThread, base, length: v6);
  Sys_MutexUnlock(handle: &this->interfaceMutex.handle);
}


// ========================================================================
// __unwind$224345
// EA  : 0x826A48A8
// RVA : 0x006A48A8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_224345()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 128 + 80));
}


// ========================================================================
// ?OutOfMemoryCallback@idStreamFileCache@@QAA_NXZ
// EA  : 0x826A48D0
// RVA : 0x006A48D0
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

idStreamControlThread *__fastcall idStreamFileCache::OutOfMemoryCallback(idStreamFileCache *this)
{
  idStreamControlThread *result; // r3

  result = this->controlThread;
  if ( result != nullptr )
    return (idStreamControlThread *)idStreamControlThread::FreeLRU(this: result);
  return result;
}


// ========================================================================
// ?GetAvailableMemory@idStreamFileCache@@QBAHXZ
// EA  : 0x826A48E8
// RVA : 0x006A48E8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

int __fastcall idStreamFileCache::GetAvailableMemory(idStreamFileCache *this)
{
  return idLocklessCacheLineMRU::CountMemType(this: &this->controlThread->cacheLineMRU, memType: MEMORY_TYPE_ALLOCATED) << 16;
}


// ========================================================================
// ?StaticOutOfMemoryCallback@@YA_NXZ
// EA  : 0x826A4920
// RVA : 0x006A4920
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

idStreamControlThread *__fastcall StaticOutOfMemoryCallback()
{
  idStreamControlThread *result; // r3

  result = streamFileCache->controlThread;
  if ( result != nullptr )
    return (idStreamControlThread *)idStreamControlThread::FreeLRU(this: result);
  return result;
}


// ========================================================================
// ?fc_stats_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826A4940
// RVA : 0x006A4940
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall fc_stats_f(const idCmdArgs *args)
{
  idStreamFileCache::Stats(this: streamFileCache);
}


// ========================================================================
// ?ClearMem@idStreamControlThread@@QAAX_N@Z
// EA  : 0x826A4950
// RVA : 0x006A4950
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamControlThread::ClearMem(idStreamControlThread *this, bool releaseProvidedMemory)
{
  void **p_cacheLineAlloc; // r29
  int v5; // r31
  char *v6; // r11
  void *v7; // r3
  int v8; // r11
  int i; // r31

  idStreamControlThread::WaitForCompletion(this);
  this->freeMemoryRequestQueueStart = this->freeMemoryRequestQueueEnd;
  this->uncachedRequestQueueStart = this->uncachedRequestQueueEnd;
  this->uncachedOpticalDiskRequestQueueStart = this->uncachedOpticalDiskRequestQueueEnd;
  this->uncachedHardDiskRequestQueueStart = this->uncachedHardDiskRequestQueueEnd;
  this->numFreeLRU = 0;
  this->requestQueueStart = this->requestQueueEnd;
  memset(Dst: &this->opticalDiskReadQueue, Val: 0, Size: 0x4000u);
  this->opticalDiskReadQueue.queueStart = 0;
  this->opticalDiskReadQueue.queueEnd = 0;
  this->opticalDiskReadQueue.numLines.value = 0;
  memset(Dst: &this->opticalDiskFinishedQueue, Val: 0, Size: 0x4000u);
  this->opticalDiskFinishedQueue.queueStart = 0;
  this->opticalDiskFinishedQueue.queueEnd = 0;
  this->opticalDiskFinishedQueue.numLines.value = 0;
  memset(Dst: &this->hardDiskReadQueue, Val: 0, Size: 0x4000u);
  this->hardDiskReadQueue.queueStart = 0;
  this->hardDiskReadQueue.queueEnd = 0;
  this->hardDiskReadQueue.numLines.value = 0;
  memset(Dst: &this->hardDiskWriteQueue, Val: 0, Size: 0x4000u);
  this->hardDiskWriteQueue.queueStart = 0;
  this->hardDiskWriteQueue.queueEnd = 0;
  this->hardDiskWriteQueue.numLines.value = 0;
  memset(Dst: &this->hardDiskFinishedQueue, Val: 0, Size: 0x4000u);
  this->hardDiskFinishedQueue.queueStart = 0;
  this->hardDiskFinishedQueue.queueEnd = 0;
  this->hardDiskFinishedQueue.numLines.value = 0;
  memset(Dst: &this->cacheLineFree, Val: 0, Size: 0x4000u);
  this->cacheLineFree.queueStart = 0;
  this->cacheLineFree.queueEnd = 0;
  this->cacheLineFree.numLines.value = 0;
  memset(Dst: &this->cacheLineMRU, Val: 0, Size: 0x8000u);
  this->cacheLineMRU.queueStart = 0;
  this->cacheLineMRU.queueEnd = 0;
  this->cacheLineMRU.numLines.value = 0;
  this->cacheLineMRU.replacementCount.value = 0;
  memset(Dst: &this->cacheLineHash, Val: 0, Size: 0x10000u);
  memset(Dst: this->cacheLineHash.numHashEntries, Val: 0, Size: sizeof(this->cacheLineHash.numHashEntries));
  p_cacheLineAlloc = (void **)&this->cacheLineAlloc;
  this->cacheLineHash.numLines.value = 0;
  if ( this->cacheLineAlloc != nullptr )
  {
    v5 = 0;
    while ( 1 )
    {
      v6 = (char *)*p_cacheLineAlloc + v5;
      v7 = *((void **)v6 + 5);
      if ( v7 != nullptr )
        break;
LABEL_11:
      v5 += 60;
      if ( v5 >= 122880 )
      {
        memset(Dst: *p_cacheLineAlloc, Val: 0, Size: 0x1E000u);
        goto LABEL_13;
      }
    }
    v8 = *((_DWORD *)v6 + 6);
    if ( v8 == 2 )
    {
      XMemFree(pAddress: v7, dwAllocAttributes: 0xAC320000);
    }
    else
    {
      if ( v8 != 3 )
      {
LABEL_10:
        *(_DWORD *)((char *)*p_cacheLineAlloc + v5 + 20) = 0;
        *(_DWORD *)((char *)*p_cacheLineAlloc + v5 + 24) = 0;
        goto LABEL_11;
      }
      idStreamControlThread::FreeProvidedLineBuffer(this, ptr: (unsigned __int8 *)v7, freed: true);
    }
    Sys_InterlockedDecrement(value: &this->totalUsedLineBuffers.value);
    goto LABEL_10;
  }
  *p_cacheLineAlloc = idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\engine\\framework\\StreamFileCache.cpp(1859) : TAG_PAGEFILECACHE",
                        size: 0x1E000u,
                        tag: TAG_PAGEFILECACHE,
                        zeroBuffer: true,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
LABEL_13:
  for ( i = 0; i < 122880; i += 60 )
  {
    *(_DWORD *)((char *)*p_cacheLineAlloc + i) = 0;
    *(_DWORD *)((char *)*p_cacheLineAlloc + i + 44) = -1;
    Sys_InterlockedIncrement(value: (int *)((char *)*p_cacheLineAlloc + i + 48));
    Sys_InterlockedDecrement(value: (int *)((char *)*p_cacheLineAlloc + i + 56));
    idLocklessCacheLineQueueM::Add(this: &this->cacheLineFree, line: (idFileCacheLine *)((char *)*p_cacheLineAlloc + i));
  }
  this->totalUsedLineBuffers.value = 0;
  if ( releaseProvidedMemory )
  {
    memset(Dst: this->providedLineBuffers, Val: 0, Size: sizeof(this->providedLineBuffers));
    this->providedLineBuffersTotal.value = 0;
  }
  this->providedLineBuffersUsed.value = 0;
  memset(Dst: &this->currentStats, Val: 0, Size: sizeof(this->currentStats));
  this->currentStats.hardDiskLineMinReadTime = 0x8E180000F4240LL;
  this->currentStats.opticalDiskLineMinReadTime = 0x8E180000F4240LL;
  this->currentStats.hardDiskCacheMinWriteTime = 0x8E180000F4240LL;
  this->currentStats.hardDiskCacheMinReadTime = 0x8E180000F4240LL;
}


// ========================================================================
// ?OpenCacheFile@@YAPAVidFile_Permanent@@PBD_N@Z
// EA  : 0x826A4CF8
// RVA : 0x006A4CF8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

idFile_Permanent *__fastcall OpenCacheFile(const char *fileName, bool create)
{
  const char *v4; // r3
  idFile_Permanent *v5; // r3
  idFile_Permanent *v6; // r30
  idStrStatic<256> v8; // [sp+60h] [-140h] BYREF

  v4 = fileSystem->GetBasePathStr(this: fileSystem, a2: 1);
  idStrStatic<256>::idStrStatic<256>(this: &v8, text: v4);
  idStr::AppendPath(this: &v8, text: fileName);
  v5 = (idFile_Permanent *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x68u,
                             tag: TAG_FILE,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v6 = idFile_Permanent::idFile_Permanent(this: v5, relativePath: fileName, osPath: v8.data, m: FS_READ_WRITE, create);
  else
    v6 = nullptr;
  if ( idFile_Permanent::IsOpen(this: v6) )
  {
    idStr::FreeData(this: &v8);
    return v6;
  }
  else
  {
    if ( v6 != nullptr )
      ((void (__fastcall *)(idFile_Permanent *, int))v6->dtr_idFile)(a1: v6, a2: 1);
    idStr::FreeData(this: &v8);
    return nullptr;
  }
}


// ========================================================================
// __unwind$224606
// EA  : 0x826A4DF0
// RVA : 0x006A4DF0
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_224606()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 96));
}


// ========================================================================
// __unwind$224607
// EA  : 0x826A4E18
// RVA : 0x006A4E18
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_224607()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_FILE);
}


// ========================================================================
// ?CreateNewHDC@idStreamControlThread@@QAA_NXZ
// EA  : 0x826A4E48
// RVA : 0x006A4E48
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

int __fastcall idStreamControlThread::CreateNewHDC(idStreamControlThread *this)
{
  idFile **p_hdcHeaderFile; // r24
  int v3; // r25
  idFile_Permanent *v4; // r3
  idFile_Permanent *v5; // r27
  idFile **hdcFiles; // r30
  int v7; // r29
  _DWORD *i; // r31
  idFile_Permanent *v9; // r3
  int v10; // r3
  const char *v11; // r3
  idFile **v13; // r31
  int j; // r30
  idFile *v15; // r3

  p_hdcHeaderFile = &this->hdcHeaderFile;
  if ( this->hdcHeaderFile != nullptr )
    return 0;
  v3 = Sys_Milliseconds();
  XUnmountUtilityDrive();
  XMountUtilityDrive(fFormatClean: 1, dwBytesPerCluster: 0x10000u, dwCacheSize: 0x40000u);
  XFlushUtilityDrive();
  v4 = OpenCacheFile(fileName: "FileCacheHeader.bin", create: true);
  v5 = v4;
  if ( v4 == nullptr )
  {
    idLib::Printf(fmt: "Couldn't create %s\n", "FileCacheHeader.bin");
    return 0;
  }
  v4->SetLength(this: v4, a2: this->hdcHeaderSize);
  hdcFiles = this->hdcFiles;
  v7 = 0;
  for ( i = hdcFiles; ; ++i )
  {
    idStr::snPrintf(dest: `CACHE_FILE_NAME'::`2'::fileName, size: 256, fmt: "FileCache%03d.bin", v7);
    v9 = OpenCacheFile(fileName: `CACHE_FILE_NAME'::`2'::fileName, create: true);
    *i = v9;
    if ( v9 != nullptr )
      v9->SetLength(this: v9, a2: 0x200000u);
    if ( *i == 0 )
      break;
    mgthread_sleep(ms: 16);
    if ( ++v7 >= 512 )
    {
      v10 = Sys_Milliseconds();
      idLib::Printf(fmt: "%d seconds to create hard disk backing cache\n", (v10 - v3) / 1000);
      *p_hdcHeaderFile = v5;
      v11 = v5->GetFullPath(this: v5);
      idLib::Printf(fmt: "Using hard drive cache: %s\n", v11);
      return 1;
    }
  }
  ((void (__fastcall *)(idFile_Permanent *, int))v5->dtr_idFile)(a1: v5, a2: 1);
  if ( v7 > 0 )
  {
    v13 = hdcFiles - 1;
    for ( j = v7; j != 0; --j )
    {
      v15 = v13[1];
      if ( v15 != nullptr )
        ((void (__fastcall *)(idFile *, int))v15->dtr_idFile)(a1: v15, a2: 1);
      *++v13 = nullptr;
    }
  }
  idStr::snPrintf(dest: `CACHE_FILE_NAME'::`2'::fileName, size: 256, fmt: "FileCache%03d.bin", v7);
  idLib::Printf(fmt: "Couldn't create %s\n", `CACHE_FILE_NAME'::`2'::fileName);
  return 0;
}


// ========================================================================
// ?GetHardDiskFileID@idStreamControlThread@@AAAHPAVidFile@@@Z
// EA  : 0x826A5040
// RVA : 0x006A5040
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

int __fastcall idStreamControlThread::GetHardDiskFileID(idStreamControlThread *this, idFile *cacheFile)
{
  idStreamControlThread::cachedFileID_t v2; // r23
  int *p_cachedFileIDIndex; // r18
  int i; // r9
  int v7; // r10
  const char *v8; // r3
  unsigned __int8 v9; // r9
  const char *v10; // r20
  int v11; // r24
  const char *v12; // r10
  int v13; // r21
  bool v14; // cr58
  int v15; // r30
  idStreamControlThread::hdCache_t **p_hdc; // r29
  int v17; // r27
  cachedFile_t *v18; // r25
  unsigned int v20; // r28
  int name; // r29
  int v22; // r11
  int v23; // r11

  v2.id = 0;
  p_cachedFileIDIndex = &this->cachedFileIDIndex;
  for ( i = 0; i < 4; ++i )
  {
    v7 = *p_cachedFileIDIndex & 3;
    if ( this->cachedFileIDs[v7].uniqID == cacheFile->uniqID )
      return this->cachedFileIDs[v7].id;
    ++*p_cachedFileIDIndex;
  }
  v8 = cacheFile->GetFullPath(this: cacheFile);
  v9 = *v8;
  v10 = v8;
  v11 = 0;
  if ( *v8 != 0 )
  {
    v12 = v8;
    do
    {
      ++v12;
      v11 = 31 * v11 + v9;
      v9 = *v12;
    }
    while ( *v12 != 0 );
  }
  v13 = 0;
  v2.uniqID = 584288;
  v14 = false;
  while ( 1 )
  {
    if ( v14 )
    {
      idLib::Warning(fmt: "cleaning hard disk cache");
      idStreamControlThread::ClearMem(this, releaseProvidedMemory: false);
      idStreamControlThread::hdCache_t::Clear(this: this->hdc, clearFileIDs: true);
      memset(Dst: this->hdcFileAccessed, Val: 0, Size: sizeof(this->hdcFileAccessed));
      *(idStreamControlThread::cachedFileID_t *)((char *)&this->__vftable + v2.uniqID) = v2;
      this->cachedFileIDs[1] = v2;
      this->cachedFileIDs[2] = v2;
      this->cachedFileIDs[3] = v2;
    }
    v15 = (v11 + v13) & 0x7F;
    p_hdc = &this->hdc;
    v17 = v15;
    v18 = &this->hdc->cachedFiles[v15];
    if ( idStr::Icmp(s1: v18->name, s2: v10) == 0 )
      break;
    if ( v18->name[0] == 0 )
    {
      strncpy(dest: v18->name, source: v10, count: 0xFFu);
      (*p_hdc)->cachedFiles[v17].device = cacheFile->GetDevice(this: cacheFile);
      if ( fc_checkHdcTimestamps.valueInteger != 0 )
        v2.id = cacheFile->Timestamp(this: cacheFile);
      (*p_hdc)->cachedFiles[v17].timestamp = v2.id;
      this->hdcFileAccessed[v15] = true;
      v23 = *p_cachedFileIDIndex + 1;
      *p_cachedFileIDIndex = v23;
      *(int *)((char *)&this->cachedFileIDs[0].id + ((8 * v23) & 0x18)) = v15;
      this->cachedFileIDs[*p_cachedFileIDIndex & 3].uniqID = cacheFile->uniqID;
      return (v11 + v13) & 0x7F;
    }
    v14 = ++v13 == 128;
    if ( v13 > 128 )
    {
      idLib::FatalError(fmt: "idStreamControlThread::GetHardDiskFileID: failed");
      return this->cachedFileIDs[v7].id;
    }
  }
  if ( !this->hdcFileAccessed[v15] && fc_checkHdcTimestamps.valueInteger != 0 )
  {
    v20 = cacheFile->Timestamp(this: cacheFile);
    if ( v18->timestamp != v20 )
    {
      idStreamControlThread::ClearMem(this, releaseProvidedMemory: false);
      idStreamControlThread::hdCache_t::Clear(this: *p_hdc, clearFileIDs: true);
      memset(Dst: this->hdcFileAccessed, Val: 0, Size: sizeof(this->hdcFileAccessed));
      *(idStreamControlThread::cachedFileID_t *)((char *)&this->__vftable + v2.uniqID) = v2;
      v15 = v11 & 0x7F;
      this->cachedFileIDs[1] = v2;
      this->cachedFileIDs[2] = v2;
      this->cachedFileIDs[3] = v2;
      name = (int)(*p_hdc)->cachedFiles[v15].name;
      strncpy(dest: (char *)name, source: v10, count: 0xFFu);
      *(_DWORD *)(name + 260) = v20;
    }
  }
  this->hdcFileAccessed[v15] = true;
  v22 = *p_cachedFileIDIndex + 1;
  *p_cachedFileIDIndex = v22;
  *(int *)((char *)&this->cachedFileIDs[0].id + ((8 * v22) & 0x18)) = v15;
  this->cachedFileIDs[*p_cachedFileIDIndex & 3].uniqID = cacheFile->uniqID;
  return v15;
}


// ========================================================================
// ?FetchCacheLines@idStreamControlThread@@QAAHPAVidFile@@_JH_NHHQAPAVidFileCacheLine@@@Z
// EA  : 0x826A5388
// RVA : 0x006A5388
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idStreamControlThread::FetchCacheLines(
        idStreamControlThread *this,
        idFile *cacheFile,
        __int64 ofs,
        int length,
        idStreamControlThread_vtbl *blockingRead,
        idStreamControlThread_vtbl *priority,
        int persistence,
        idFileCacheLine **readLines)
{
  int v10; // r31 OVERLAPPED
  int v11; // r26
  idStreamControlThread_vtbl *HardDiskFileID; // r24
  __int64 v16; // r9
  int v17; // r22
  __int64 v18; // r8
  int v19; // r26
  int v20; // r31
  int v21; // r28
  int v22; // r30
  _DWORD *v23; // r27
  idLocklessCacheLineHash *p_cacheLineHash; // r23
  idFileCacheLine *v25; // r3
  idFileCacheLine *v26; // r31
  int *p_value; // r29
  int v29; // r30
  int i; // r31

  v10 = HIDWORD(ofs);
  v11 = ofs;
  HardDiskFileID = (idStreamControlThread_vtbl *)idStreamControlThread::GetHardDiskFileID(this, cacheFile);
  LODWORD(v16) = v11 + v10 - 1;
  v17 = *(__int64 *)&v10 >> 16;
  v18 = v16 >> 16;
  v19 = v18;
  if ( blockingRead != (idStreamControlThread_vtbl *)-1 && priority != (idStreamControlThread_vtbl *)-1 )
  {
    v20 = *(__int64 *)&v10 >> 16;
    if ( v17 <= (int)v18 )
    {
      do
        idStreamControlThread::AddCacheLineRequest(
          this,
          filePtr: (idStreamControlThread_vtbl *)cacheFile,
          fileID: HardDiskFileID,
          fileLine: (idStreamControlThread_vtbl *)v20++,
          priority: blockingRead,
          persistence: priority);
      while ( v20 <= v19 );
    }
  }
  v21 = 0;
  v22 = v17;
  if ( v17 <= v19 )
  {
    v23 = (_DWORD *)(persistence - 4);
    p_cacheLineHash = &this->cacheLineHash;
    do
    {
      v25 = idLocklessCacheLineHash::Find(this: p_cacheLineHash, fileID: (int)HardDiskFileID, fileLine: v22);
      v26 = v25;
      if ( v25 == nullptr )
        break;
      p_value = &v25->fetchLock.value;
      if ( Sys_InterlockedIncrement(value: &v25->fetchLock.value) != 1 )
        goto LABEL_15;
      if ( Sys_InterlockedIncrement(value: &v26->pinned.value) <= 0
        || (idStreamControlThread_vtbl *)v26->fileID != HardDiskFileID
        || v26->fileLine != v22 )
      {
        Sys_InterlockedDecrement(value: &v26->pinned.value);
LABEL_15:
        Sys_InterlockedDecrement(value: p_value);
        break;
      }
      Sys_InterlockedDecrement(value: p_value);
      ++v22;
      *++v23 = v26;
      ++v21;
    }
    while ( v22 <= v19 );
  }
  if ( v21 == v19 - v17 + 1 )
    return v21;
  if ( v21 > 0 )
  {
    v29 = persistence - 4;
    for ( i = v21; i != 0; --i )
    {
      v29 += 4;
      Sys_InterlockedDecrement(value: (int *)(*(_DWORD *)v29 + 56));
    }
  }
  return 0;
}


// ========================================================================
// ?BatchRequestCacheLines@idStreamControlThread@@QAAXPBUcacheLineRequest_t@@H@Z
// EA  : 0x826A5510
// RVA : 0x006A5510
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamControlThread::BatchRequestCacheLines(
        idStreamControlThread *this,
        const cacheLineRequest_t *requests,
        int numRequests)
{
  int *p_persistence; // r31
  int i; // r30
  idStreamControlThread_vtbl *HardDiskFileID; // r3
  idStreamControlThread_vtbl *v7; // r4
  idStreamControlThread_vtbl *v8; // r6
  idStreamControlThread_vtbl *v9; // r7

  if ( numRequests > 0 )
  {
    p_persistence = &requests[-1].persistence;
    for ( i = numRequests; i != 0; --i )
    {
      HardDiskFileID = (idStreamControlThread_vtbl *)idStreamControlThread::GetHardDiskFileID(
                                                       this,
                                                       cacheFile: (idFile *)p_persistence[1]);
      v7 = (idStreamControlThread_vtbl *)p_persistence[1];
      v8 = (idStreamControlThread_vtbl *)p_persistence[2];
      v9 = (idStreamControlThread_vtbl *)p_persistence[3];
      p_persistence += 4;
      idStreamControlThread::AddCacheLineRequest(
        this,
        filePtr: v7,
        fileID: HardDiskFileID,
        fileLine: v8,
        priority: v9,
        persistence: (idStreamControlThread_vtbl *)*p_persistence);
    }
  }
}


// ========================================================================
// ?InitHDC@idStreamFileCache@@QAAXXZ
// EA  : 0x826A5570
// RVA : 0x006A5570
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamFileCache::InitHDC(idStreamFileCache *this)
{
  Sys_MutexLock(handle: &this->interfaceMutex.handle, blocking: true);
  idStreamControlThread::ShutdownHDC(this: this->controlThread);
  Sys_MutexUnlock(handle: &this->interfaceMutex.handle);
  idStreamControlThread::CreateNewHDC(this: this->controlThread);
}


// ========================================================================
// __unwind$224934
// EA  : 0x826A55C8
// RVA : 0x006A55C8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_224934()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 112 + 80));
}


// ========================================================================
// ?ClearMem@idStreamFileCache@@QAAX_N@Z
// EA  : 0x826A55F8
// RVA : 0x006A55F8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamFileCache::ClearMem(idStreamFileCache *this, bool releaseProvidedMemory)
{
  Sys_MutexLock(handle: &this->interfaceMutex.handle, blocking: true);
  idStreamControlThread::ClearMem(this: this->controlThread, releaseProvidedMemory);
  idMD6PhaseTrack::idMD6PhaseTrack(this: &streamFileLog);
  Sys_MutexUnlock(handle: &this->interfaceMutex.handle);
}


// ========================================================================
// __unwind$224969
// EA  : 0x826A5644
// RVA : 0x006A5644
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_224969()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 128 + 80));
}


// ========================================================================
// ?ClearHDC@idStreamFileCache@@QAAXXZ
// EA  : 0x826A5678
// RVA : 0x006A5678
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamFileCache::ClearHDC(idStreamFileCache *this)
{
  Sys_MutexLock(handle: &this->interfaceMutex.handle, blocking: true);
  idStreamControlThread::ClearMem(this: this->controlThread, releaseProvidedMemory: false);
  idMD6PhaseTrack::idMD6PhaseTrack(this: &streamFileLog);
  idStreamControlThread::ShutdownHDC(this: this->controlThread);
  Sys_MutexUnlock(handle: &this->interfaceMutex.handle);
  idStreamControlThread::CreateNewHDC(this: this->controlThread);
}


// ========================================================================
// __unwind$225005
// EA  : 0x826A56E8
// RVA : 0x006A56E8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_225005()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 112 + 80));
}


// ========================================================================
// ?ReadCachedData@idStreamFileCache@@QAAHPAVidFile@@_JHPAX_NHHW4pfcRequest_t@@@Z
// EA  : 0x826A5718
// RVA : 0x006A5718
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

unsigned int __fastcall idStreamFileCache::ReadCachedData(
        idStreamFileCache *this,
        idFile *cacheFile,
        __int64 ofs,
        unsigned __int8 *length,
        int dest,
        idStreamControlThread_vtbl *blockingRead,
        idStreamControlThread_vtbl *priority,
        int persistence,
        pfcRequest_t pfc)
{
  int v11; // r27
  unsigned int v12; // r26
  const char *v17; // r3
  const char *v19; // r3
  int CacheLines; // r3
  int v21; // r23
  idFileCacheLine **v22; // r29
  int i; // r30
  idFileCacheLine *v24; // r7
  int v25; // r9
  int v26; // r11
  signed int v27; // r8
  int v28; // r9
  signed int v29; // r10
  char *buffer; // r30
  char *v31; // r10
  unsigned __int8 *v32; // r11
  int v33; // r9
  int v34; // r7
  idFileCacheLine **v35; // [sp+8h] [-C8h]
  idFileCacheLine **v36; // [sp+8h] [-C8h]
  idTempArray<char> v37; // [sp+58h] [-78h] BYREF
  idFileCacheLine *v38[28]; // [sp+60h] [-70h] BYREF

  v11 = HIDWORD(ofs);
  v12 = ofs;
  if ( ofs >= 0 )
  {
    if ( (int)ofs > 0 )
    {
      Sys_MutexLock(handle: &this->interfaceMutex.handle, blocking: true);
      CacheLines = idStreamControlThread::FetchCacheLines(
                     this: this->controlThread,
                     cacheFile,
                     ofs: __SPAIR64__(v11, v12),
                     length: dest,
                     blockingRead,
                     priority,
                     persistence: (int)v38,
                     readLines: v35);
      v21 = CacheLines;
      if ( (_BYTE)dest != 0 && CacheLines == 0 )
      {
        do
        {
          idStreamControlThread::WaitForCompletion(this: this->controlThread);
          v21 = idStreamControlThread::FetchCacheLines(
                  this: this->controlThread,
                  cacheFile,
                  ofs: __SPAIR64__(v11, v12),
                  length: dest,
                  blockingRead,
                  priority,
                  persistence: (int)v38,
                  readLines: v36);
        }
        while ( v21 == 0 );
      }
      if ( length != nullptr && v21 > 0 )
      {
        v22 = v38;
        for ( i = v21; i != 0; --i )
        {
          v24 = *v22;
          v25 = (*v22)->fileLine << 16;
          v26 = v11 - v25;
          if ( v11 - v25 <= 0 )
            v26 = 0;
          v27 = v24->validLength - v26;
          if ( v27 <= 0 )
            v27 = 0;
          v28 = v25 - v11;
          if ( v28 <= 0 )
            v28 = 0;
          v29 = v12 - v28;
          if ( (int)(v12 - v28) <= 0 )
            v29 = 0;
          if ( v27 >= v29 )
            v27 = v29;
          memcpy(Dst: &length[v28], Src: &v24->data[v26], Size: v27);
          ++v22;
        }
        if ( fc_verifyCacheReadData.valueInteger != 0 )
        {
          idTempArray<char>::idTempArray<char>(this: &v37, num: v12);
          buffer = v37.buffer;
          cacheFile->ReadOfs(this: cacheFile, a2: v11, a3: v37.buffer, a4: v12);
          v31 = buffer;
          v32 = length;
          v33 = 0;
          if ( v12 != 0 )
          {
            do
            {
              v34 = (unsigned __int8)*v31;
              v33 = *v32 - v34;
              if ( *v32 != v34 )
                break;
              ++v32;
              ++v31;
            }
            while ( v32 != &length[v12] );
          }
          if ( v33 != 0 )
            idLib::Error(fmt: "idStreamFileCache::ReadCachedData: data compare failed");
          if ( buffer != nullptr )
            idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
        }
      }
      idStreamControlThread::ReleaseCacheLines(this: this->controlThread, readLines: v38, numReadLines: v21);
      Sys_MutexUnlock(handle: &this->interfaceMutex.handle);
      return v21 == 0 ? 0 : v12;
    }
    else
    {
      v19 = cacheFile->GetFullPath(this: cacheFile);
      idLib::Warning(fmt: "idStreamFileCache::ReadCachedData: length = %d for %s", v12, v19);
      return 0;
    }
  }
  else
  {
    v17 = cacheFile->GetFullPath(this: cacheFile);
    idLib::Warning(fmt: "idStreamFileCache::ReadCachedData: ofs = %lld for %s", v11, v17);
    return 0;
  }
}


// ========================================================================
// $LN61_0
// EA  : 0x826A59C8
// RVA : 0x006A59C8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _LN61_0()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 208 + 80));
}


// ========================================================================
// __unwind$225044
// EA  : 0x826A59F0
// RVA : 0x006A59F0
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_225044()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 208 + 88));
}


// ========================================================================
// ?BatchRequestCacheLines@idStreamFileCache@@QAAXPBUcacheLineRequest_t@@H@Z
// EA  : 0x826A5A20
// RVA : 0x006A5A20
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamFileCache::BatchRequestCacheLines(
        idStreamFileCache *this,
        const cacheLineRequest_t *requests,
        int numRequests)
{
  Sys_MutexLock(handle: &this->interfaceMutex.handle, blocking: true);
  idStreamControlThread::BatchRequestCacheLines(this: this->controlThread, requests, numRequests);
  Sys_MutexUnlock(handle: &this->interfaceMutex.handle);
}


// ========================================================================
// __unwind$225281_0
// EA  : 0x826A5A68
// RVA : 0x006A5A68
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_225281_0()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 128 + 80));
}


// ========================================================================
// ?fc_clearMem_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826A5A90
// RVA : 0x006A5A90
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall fc_clearMem_f(const idCmdArgs *args)
{
  idStreamFileCache::ClearMem(this: streamFileCache, releaseProvidedMemory: false);
}


// ========================================================================
// ?fc_clearHDC_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826A5AA0
// RVA : 0x006A5AA0
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall fc_clearHDC_f(const idCmdArgs *args)
{
  idStreamFileCache::ClearHDC(this: streamFileCache);
}


// ========================================================================
// ?fc_testCacheDrive_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826A5AB8
// RVA : 0x006A5AB8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall fc_testCacheDrive_f(const idCmdArgs *args)
{
  const char *v2; // r3
  int v3; // r15
  const char *v4; // r3
  signed int v5; // r28
  signed int v6; // r30
  signed int v7; // r29
  const char *v8; // r3
  void *v9; // r19
  unsigned int v10; // r5
  idFile **v11; // r16
  __int64 v12; // r8
  __int64 v13; // r6
  int v14; // r26
  __int64 v15; // r10
  idFile **v16; // r27
  va *v17; // r3
  idFile *v18; // r3
  int v19; // r29
  signed int i; // r30
  unsigned __int64 v21; // r22 OVERLAPPED
  unsigned __int64 v22; // r24 OVERLAPPED
  int v23; // r30
  signed int v24; // r29
  int j; // r20 OVERLAPPED
  int v26; // r10
  idFile *v27; // r26
  int v28; // r27
  unsigned __int64 v29; // r4
  int v30; // r26
  idFile **v31; // r30
  int k; // r29
  unsigned __int64 v33; // r11
  idStreamFileCache *v34; // r29
  int v35; // [sp+8h] [-10F8h]
  int v36; // [sp+Ch] [-10F4h]
  int v37; // [sp+10h] [-10F0h]
  int v38; // [sp+14h] [-10ECh]
  int v39; // [sp+18h] [-10E8h]
  int v40; // [sp+1Ch] [-10E4h]
  int v41; // [sp+58h] [-10A8h]
  int v42; // [sp+5Ch] [-10A4h]
  va v43; // [sp+60h] [-10A0h] BYREF

  if ( args->argc <= 1 )
    v2 = &byte_8200D768;
  else
    v2 = args->argv[1];
  v3 = atol(nptr: v2);
  if ( v3 <= 0 )
    v3 = 1;
  if ( args->argc <= 2 )
    v4 = &byte_8200D768;
  else
    v4 = args->argv[2];
  v5 = atol(nptr: v4);
  if ( v5 <= 0 )
    v5 = 128;
  idLib::Printf(fmt: "%4d files\n", v3);
  idLib::Printf(fmt: "%4d blocks per file\n", v5);
  idLib::Printf(fmt: "%4d kB block size\n", 64);
  idStreamFileCache::Flush(this: streamFileCache);
  v6 = 0x40000;
  v7 = 0x10000;
  if ( args->argc > 3 )
  {
    v7 = atol(nptr: args->argv[3]) << 10;
    if ( v7 < 4096 )
      v7 = 4096;
    if ( args->argc <= 4 )
      v8 = &byte_8200D768;
    else
      v8 = args->argv[4];
    v6 = atol(nptr: v8) << 10;
    if ( v6 < 0x10000 )
      v6 = 0x10000;
  }
  idLib::Printf(fmt: "%4d kB cluster size\n", v7 >> 10);
  idLib::Printf(fmt: "%4d kB cache size\n", v6 >> 10);
  XUnmountUtilityDrive();
  XMountUtilityDrive(fFormatClean: 1, dwBytesPerCluster: v7, dwCacheSize: v6);
  v9 = XMemAlloc(dwSize: 0x10000u, dwAllocAttributes: 0xAC320000);
  v10 = 4 * v3;
  if ( (unsigned int)v3 > 0x3FFFFFFF )
    v10 = -1;
  v11 = (idFile **)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                     size: v10,
                     tag: TAG_NEW,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
  v14 = 0;
  LODWORD(v15) = "_AI_OBSTACLE";
  v16 = v11;
  do
  {
    HIDWORD(v13) = v14;
    v17 = va::va(
            this: &v43,
            fmt: "test%d.bin",
            a3: v13,
            a4: v12,
            a5: v15,
            a6: v35,
            a7: v36,
            a8: v37,
            a9: v38,
            a10: v39,
            a11: v40);
    v18 = fileSystem->OpenFileReadWrite(this: fileSystem, a2: v17, a3: 1, a4: 1);
    *v16 = v18;
    if ( v18 != nullptr )
    {
      v18->SetLength(this: v18, a2: v5 << 16);
      v19 = 0;
      for ( i = v5; i != 0; --i )
      {
        (*v16)->WriteOfs(this: *v16, a2: v19, a3: v9, a4: 0x10000u);
        v19 += 0x10000;
      }
    }
    else
    {
      idLib::Warning(fmt: "couldn't open file");
    }
    ++v14;
    ++v16;
  }
  while ( v14 < v3 );
  XFlushUtilityDrive();
  v21 = 1000;
  v22 = 0x3E800000000LL;
  v23 = 0;
  v24 = v5 * v3;
  for ( j = 1000; j != 0; --j )
  {
    v23 = 1103515245 * v23 + 12345;
    __twllei(v24, 0);
    __twllei(v5, 0);
    v26 = (v23 >> 16) & 0x7FFF;
    __twllei(v5, 0);
    v27 = v11[v26 % v24 / v5];
    __twlgei(v24 & ~(__ROL4__(v26, 1) - 1), 0xFFFFFFFF);
    __twlgei(v5 & ~(__ROL4__(v26 % v24, 1) - 1), 0xFFFFFFFF);
    v42 = v26 % v24 % v5;
    __twlgei(v5 & ~(__ROL4__(v26 % v24, 1) - 1), 0xFFFFFFFF);
    v28 = Sys_Microseconds() >> 32;
    v41 = v27->ReadOfs(this: v27, a2: v42 << 16, a3: v9, a4: 0x10000u);
    v29 = Sys_Microseconds();
    v30 = HIDWORD(v29);
    if ( v41 != 0x10000 )
      idLib::Warning(fmt: "failed to read", (_DWORD)v29);
    LODWORD(v22) = v30 - v28 + v22;
    if ( HIDWORD(v22) >= v30 - v28 )
      HIDWORD(v22) = v30 - v28;
    if ( HIDWORD(v21) <= v30 - v28 )
      HIDWORD(v21) = v30 - v28;
  }
  v31 = v11;
  for ( k = v3; k != 0; --k )
  {
    if ( *v31 != nullptr )
      ((void (__fastcall *)(idFile *, int))(*v31)->dtr_idFile)(a1: *v31, a2: 1);
    ++v31;
  }
  idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
  XMemFree(pAddress: v9, dwAllocAttributes: 0xAC320000);
  v33 = v22 / v21;
  HIDWORD(v33) = "_AI_OBSTACLE";
  idLib::Printf(
    fmt: (const char *)((v33 / v21) >> 32),
    (unsigned int)(v33 / v21),
    (unsigned int)(*(unsigned __int64 *)((char *)&v22 + 4) / v21),
    (unsigned int)(*(unsigned __int64 *)((char *)&v21 + 4) / v21));
  v34 = streamFileCache;
  Sys_MutexLock(handle: &streamFileCache->interfaceMutex.handle, blocking: true);
  idStreamControlThread::ClearMem(this: v34->controlThread, releaseProvidedMemory: false);
  idMD6PhaseTrack::idMD6PhaseTrack(this: &streamFileLog);
  idStreamControlThread::ShutdownHDC(this: v34->controlThread);
  Sys_MutexUnlock(handle: &v34->interfaceMutex.handle);
  idStreamControlThread::CreateNewHDC(this: v34->controlThread);
}


// ========================================================================
// __unwind$225396_0
// EA  : 0x826A5F10
// RVA : 0x006A5F10
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_225396_0()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 4352 + 80));
}


// ========================================================================
// ?Init@idStreamControlThread@@QAAXXZ
// EA  : 0x826A5F40
// RVA : 0x006A5F40
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamControlThread::Init(idStreamControlThread *this)
{
  unsigned __int8 *v2; // r3
  idStreamControlThread::hdCache_t *v3; // r3
  idSysThread *v4; // r3
  idOpticalDiskStreamThread *v5; // r29
  idOpticalDiskStreamThread *v6; // r11
  idSysThread *v7; // r3
  idHardDiskStreamThread *v8; // r29
  idHardDiskStreamThread *v9; // r11

  idStreamControlThread::ClearMem(this, releaseProvidedMemory: true);
  this->hdcHeaderSize = 0x20000;
  v2 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\engine\\framework\\StreamFileCache.cpp(1786) : TAG_PAGEFILECACHE",
                            size: 0x24000u,
                            tag: TAG_PAGEFILECACHE,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  this->hdcBuffer = v2;
  v3 = (idStreamControlThread::hdCache_t *)((unsigned int)(v2 + 0x3FFF) & 0xFFFFC000);
  this->hdc = v3;
  idStreamControlThread::hdCache_t::Clear(this: v3, clearFileIDs: true);
  v4 = (idSysThread *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x48u,
                        tag: TAG_PAGEFILECACHE,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v5 = (idOpticalDiskStreamThread *)v4;
  if ( v4 != nullptr )
  {
    idSysThread::idSysThread(this: v4);
    v5->controlThread = nullptr;
    v6 = v5;
    v5->__vftable = (idOpticalDiskStreamThread_vtbl *)&idOpticalDiskStreamThread::`vftable';
    v5->opticalDiskOffset = 0;
    v5->tempData = nullptr;
    v5->tempMemType = MEMORY_TYPE_INVALID;
  }
  else
  {
    v6 = nullptr;
  }
  this->opticalDiskThread = v6;
  v6->controlThread = this;
  idSysThread::StartWorkerThread(
    this: this->opticalDiskThread,
    name_: "OpticalDiskStream",
    core: CORE_0A,
    priority: THREAD_HIGHEST,
    stackSize: 0x20000);
  v7 = (idSysThread *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x48u,
                        tag: TAG_PAGEFILECACHE,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v8 = (idHardDiskStreamThread *)v7;
  if ( v7 != nullptr )
  {
    idSysThread::idSysThread(this: v7);
    v8->controlThread = nullptr;
    v9 = v8;
    v8->hardDiskOffset = 0;
    v8->tempData = nullptr;
    v8->__vftable = (idHardDiskStreamThread_vtbl *)&idHardDiskStreamThread::`vftable';
    v8->tempMemType = MEMORY_TYPE_INVALID;
  }
  else
  {
    v9 = nullptr;
  }
  this->hardDiskThread = v9;
  v9->controlThread = this;
  idSysThread::StartWorkerThread(
    this: this->hardDiskThread,
    name_: "HardDiskStream",
    core: CORE_0B,
    priority: THREAD_HIGHEST,
    stackSize: 0x20000);
}


// ========================================================================
// __unwind$225460
// EA  : 0x826A60F0
// RVA : 0x006A60F0
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_225460()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_PAGEFILECACHE);
}


// ========================================================================
// __unwind$225461
// EA  : 0x826A611C
// RVA : 0x006A611C
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_225461()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_PAGEFILECACHE);
}


// ========================================================================
// ?Init@idStreamFileCache@@QAAXXZ
// EA  : 0x826A6150
// RVA : 0x006A6150
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __fastcall idStreamFileCache::Init(idStreamFileCache *this)
{
  idStreamControlThread *v2; // r3
  idStreamControlThread *v3; // r3

  Sys_MutexLock(handle: &this->interfaceMutex.handle, blocking: true);
  v2 = (idStreamControlThread *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x8EA88u,
                                  tag: TAG_PAGEFILECACHE,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idStreamControlThread::idStreamControlThread(this: v2);
  else
    v3 = nullptr;
  this->controlThread = v3;
  idSysThread::StartWorkerThread(
    this: v3,
    name_: "StreamControl",
    core: CORE_1B,
    priority: THREAD_NORMAL,
    stackSize: 0x20000);
  idStreamControlThread::Init(this: this->controlThread);
  this->cancelToTerminate = false;
  Sys_MutexUnlock(handle: &this->interfaceMutex.handle);
}


// ========================================================================
// __unwind$225505_0
// EA  : 0x826A6208
// RVA : 0x006A6208
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_225505_0()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 112 + 80));
}


// ========================================================================
// __unwind$225506_0
// EA  : 0x826A6230
// RVA : 0x006A6230
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void _unwind_225506_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 84), tag: TAG_PAGEFILECACHE);
}


// ========================================================================
// `dynamic initializer for 'StreamFileCacheLocal''
// EA  : 0x8333C928
// RVA : 0x0133C928
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__StreamFileCacheLocal__()
{
  Sys_MutexCreate(handle: (_RTL_CRITICAL_SECTION **)&StreamFileCacheLocal);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__StreamFileCacheLocal__);
}


// ========================================================================
// `dynamic initializer for 'fc_maxCacheMemoryMB''
// EA  : 0x8333C960
// RVA : 0x0133C960
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fc_maxCacheMemoryMB__()
{
  idCVar::idCVar(
    this: &fc_maxCacheMemoryMB,
    name: "fc_maxCacheMemoryMB",
    value: "64",
    flags: 2,
    description: "Maximum cache size in megabytes",
    valueMin: 1.0,
    valueMax: 96.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"_AI_OBSTACLE",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fc_maxCacheMemoryMB__);
}


// ========================================================================
// `dynamic initializer for 'fc_useHdc''
// EA  : 0x8333C9C8
// RVA : 0x0133C9C8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fc_useHdc__()
{
  idCVar::idCVar(
    this: &fc_useHdc,
    name: "fc_useHdc",
    value: "1",
    flags: 2,
    description: "1 = enable hard hard cache, 2 = force hard disk cache",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fc_useHdc__);
}


// ========================================================================
// `dynamic initializer for 'fc_checkHdcTimestamps''
// EA  : 0x8333CA20
// RVA : 0x0133CA20
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fc_checkHdcTimestamps__()
{
  idCVar::idCVar(
    this: &fc_checkHdcTimestamps,
    name: "fc_checkHdcTimestamps",
    value: "0",
    flags: 1,
    description: "If zero, don't clear the hard disk cache when timestamps are dirty",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fc_checkHdcTimestamps__);
}


// ========================================================================
// `dynamic initializer for 'fc_hardDiskRequestTimeOut''
// EA  : 0x8333CA78
// RVA : 0x0133CA78
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fc_hardDiskRequestTimeOut__()
{
  idCVar::idCVar(
    this: &fc_hardDiskRequestTimeOut,
    name: "fc_hardDiskRequestTimeOut",
    value: "24",
    flags: 2,
    description: "milliseconds after which a request times out",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fc_hardDiskRequestTimeOut__);
}


// ========================================================================
// `dynamic initializer for 'fc_opticalDiskRequestTimeOut''
// EA  : 0x8333CAD0
// RVA : 0x0133CAD0
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fc_opticalDiskRequestTimeOut__()
{
  idCVar::idCVar(
    this: &fc_opticalDiskRequestTimeOut,
    name: "fc_opticalDiskRequestTimeOut",
    value: "48",
    flags: 2,
    description: "milliseconds after which a request times out",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fc_opticalDiskRequestTimeOut__);
}


// ========================================================================
// `dynamic initializer for 'fc_hardDiskNoSeekOffset''
// EA  : 0x8333CB28
// RVA : 0x0133CB28
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fc_hardDiskNoSeekOffset__()
{
  idCVar::idCVar(
    this: &fc_hardDiskNoSeekOffset,
    name: "fc_hardDiskNoSeekOffset",
    value: "16",
    flags: 2,
    description: "number of cache lines that can be skipped without seeking",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fc_hardDiskNoSeekOffset__);
}


// ========================================================================
// `dynamic initializer for 'fc_opticalDiskNoSeekOffset''
// EA  : 0x8333CB80
// RVA : 0x0133CB80
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fc_opticalDiskNoSeekOffset__()
{
  idCVar::idCVar(
    this: &fc_opticalDiskNoSeekOffset,
    name: "fc_opticalDiskNoSeekOffset",
    value: "16",
    flags: 2,
    description: "number of cache lines that can be skipped without seeking",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fc_opticalDiskNoSeekOffset__);
}


// ========================================================================
// `dynamic initializer for 'fc_opticalDiskSkipOffset''
// EA  : 0x8333CBD8
// RVA : 0x0133CBD8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fc_opticalDiskSkipOffset__()
{
  idCVar::idCVar(
    this: &fc_opticalDiskSkipOffset,
    name: "fc_opticalDiskSkipOffset",
    value: "5",
    flags: 2,
    description: "keep on reading if the next cache line is less than this many lines ahead",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fc_opticalDiskSkipOffset__);
}


// ========================================================================
// `dynamic initializer for 'fc_verifyCacheReadData''
// EA  : 0x8333CC30
// RVA : 0x0133CC30
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fc_verifyCacheReadData__()
{
  idCVar::idCVar(
    this: &fc_verifyCacheReadData,
    name: "fc_verifyCacheReadData",
    value: "0",
    flags: 1,
    description: "Compare every cache read with an actual ReadOfs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fc_verifyCacheReadData__);
}


// ========================================================================
// `dynamic initializer for 'fc_clearMem_v''
// EA  : 0x8333CC88
// RVA : 0x0133CC88
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__fc_clearMem_v__()
{
  return idCommandLink::idCommandLink(
           this: &fc_clearMem_v,
           cmdName: "fc_clearMem",
           function: fc_clearMem_f,
           description: "Clear the memory cache but leave the hard disk backing cache.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'fc_clearHDC_v''
// EA  : 0x8333CCB0
// RVA : 0x0133CCB0
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__fc_clearHDC_v__()
{
  return idCommandLink::idCommandLink(
           this: &fc_clearHDC_v,
           cmdName: "fc_clearHDC",
           function: fc_clearHDC_f,
           description: "Clear both the memory cache and hard drive backing cache.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'fc_stats_v''
// EA  : 0x8333CCD8
// RVA : 0x0133CCD8
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__fc_stats_v__()
{
  return idCommandLink::idCommandLink(
           this: &fc_stats_v,
           cmdName: "fc_stats",
           function: fc_stats_f,
           description: "Reports file cache statistics.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'fc_testCacheDrive_v''
// EA  : 0x8333CD00
// RVA : 0x0133CD00
// PDB : w:\tech5\engine\framework\streamfilecache.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__fc_testCacheDrive_v__()
{
  return idCommandLink::idCommandLink(
           this: &fc_testCacheDrive_v,
           cmdName: "fc_testCacheDrive",
           function: fc_testCacheDrive_f,
           description: &byte_8200D768,
           argCompletion: nullptr);
}

