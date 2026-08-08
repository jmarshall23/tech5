
// ========================================================================
// ?WriteOfs@idBGLRingBuffer@@QAAX_JPBXI@Z
// EA  : 0x8269DB90
// RVA : 0x0069DB90
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void __fastcall idBGLRingBuffer::WriteOfs(
        idBGLRingBuffer *this,
        int a2,
        __int64 dst,
        const void *src,
        unsigned int length)
{
  char *v7; // r28
  size_t i; // r30
  int size; // r11
  size_t v10; // r31
  int v11; // r10
  size_t v12; // r11

  v7 = (char *)HIDWORD(dst);
  for ( i = dst; i != 0; a2 += v10 )
  {
    size = this->size;
    v10 = i;
    v11 = (size - 1) & a2;
    v12 = size - v11;
    if ( i > v12 )
      v10 = v12;
    memcpy(Dst: &this->buffer[v11], Src: v7, Size: v10);
    i -= v10;
    v7 += v10;
  }
}


// ========================================================================
// ?ZlibAlloc@@YAPAXPAXII@Z
// EA  : 0x8269DC10
// RVA : 0x0069DC10
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void *__fastcall ZlibAlloc(void *opaque, unsigned int items, unsigned int size)
{
  return idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\engine\\framework\\ResourceManager_background.cpp(301) : TAG_RESOURCE_BGL",
           size: items * size,
           tag: TAG_RESOURCE_BGL,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
}


// ========================================================================
// ?ZlibFree@@YAXPAX0@Z
// EA  : 0x8269DC40
// RVA : 0x0069DC40
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void __fastcall ZlibFree(void *opaque, void *address)
{
  idMem::Free(this: &mem, ptr: address, align: ALIGN_16);
}


// ========================================================================
// ?BeginBackgroundLoads@idDecompressSpawnThread@@QAAXXZ
// EA  : 0x8269DC50
// RVA : 0x0069DC50
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void __fastcall idDecompressSpawnThread::BeginBackgroundLoads(
        idDecompressSpawnThread *this,
        int a2,
        int a3,
        int a4,
        int a5,
        __int64 a6)
{
  z_stream_s *p_z; // r29
  __int64 *p_uncompressedOffsetInCurrentEntry; // r11
  int i; // ctr
  char v10; // [sp+50h] [-30h] BYREF
  _BYTE v11[44]; // [sp+54h] [-2Ch] BYREF

  p_z = &this->z;
  LODWORD(a6) = 0;
  p_uncompressedOffsetInCurrentEntry = &this->uncompressedOffsetInCurrentEntry;
  for ( i = 7; i != 0; --i )
    *++p_uncompressedOffsetInCurrentEntry = a6;
  this->z.zalloc = ZlibAlloc;
  this->z.zfree = ZlibFree;
  if ( inflateInit2_(strm: &this->z, windowBits: -15, version: "1.2.3", stream_size: 56) != 0 )
    idLib::FatalError(fmt: "zlib inflateInit2 error");
  v11[1] = 0;
  v11[2] = 0;
  v11[3] = 0;
  p_z->next_in = v11;
  this->z.next_out = (unsigned __int8 *)&v10;
  this->z.avail_out = 1;
  this->z.avail_in = 7;
  v11[0] = 98;
  v11[4] = 0;
  v11[5] = -1;
  v11[6] = -1;
  v10 = 0;
  inflate(strm: p_z, flush: 4);
  this->z.total_out = 0;
  this->z.total_in = 0;
  p_z->next_in = nullptr;
  this->z.next_out = nullptr;
}


// ========================================================================
// ?Run@idReadSpawnThread@@UAAHXZ
// EA  : 0x8269DD30
// RVA : 0x0069DD30
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

int __fastcall idReadSpawnThread::Run(idReadSpawnThread *this)
{
  int v2; // r29
  __int128 v3; // r6
  idDecompressSpawnThread *decompressThread; // r3

  if ( !bgl.cancelToTerminate )
  {
    v2 = Sys_Milliseconds();
    LODWORD(v3) = *(unsigned __int8 **)((char *)bgl.readBuffers + ((4 * bgl.currentReadBuffer) & 4));
    *(_QWORD *)((char *)&v3 + 4) = *(__int64 *)((char *)bgl.readBufferOfs + ((8 * bgl.currentReadBuffer) & 8));
    idStreamFileCache::UncachedScheduledRead(
      this: streamFileCache,
      file: *(idFile *const *)((char *)bgl.readBufferOfs + ((8 * bgl.currentReadBuffer) & 8)),
      ofs: v3,
      dest: (void *const)0x10000,
      length: (const int)bgl.readBufferOfs);
    bgl.backgroundReadMsec = bgl.backgroundReadMsec - v2 + Sys_Milliseconds();
    decompressThread = this->decompressThread;
    if ( decompressThread != nullptr )
      idSysThread::SignalWork(this: decompressThread);
  }
  return 0;
}


// ========================================================================
// ?DestroyThreads@idBackgroundLoader@@QAAXXZ
// EA  : 0x8269DDC0
// RVA : 0x0069DDC0
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void __fastcall idBackgroundLoader::DestroyThreads(idBackgroundLoader *this)
{
  idReadSpawnThread *readSpawnThread; // r3
  idDecompressSpawnThread *decompressSpawnThread; // r3

  readSpawnThread = this->readSpawnThread;
  if ( readSpawnThread != nullptr )
    ((void (__fastcall *)(idReadSpawnThread *, int))readSpawnThread->dtr_idSysThread)(a1: readSpawnThread, a2: 1);
  decompressSpawnThread = this->decompressSpawnThread;
  this->readSpawnThread = nullptr;
  if ( decompressSpawnThread != nullptr )
    ((void (__fastcall *)(idDecompressSpawnThread *, int))decompressSpawnThread->dtr_idSysThread)(
      a1: decompressSpawnThread,
      a2: 1);
  this->decompressSpawnThread = nullptr;
}


// ========================================================================
// ??0idBGLRingBuffer@@QAA@H@Z
// EA  : 0x8269DE50
// RVA : 0x0069DE50
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

idBGLRingBuffer *__fastcall idBGLRingBuffer::idBGLRingBuffer(idBGLRingBuffer *this, unsigned int numBytes)
{
  __int64 v2; // r29
  unsigned __int8 *v5; // r3

  HIDWORD(v2) = &this->freeSignal;
  Sys_SignalCreate(handle: &this->freeSignal.handle, manualReset: false);
  Sys_SignalCreate(handle: &this->dataSignal.handle, manualReset: false);
  this->size = numBytes;
  v5 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\engine\\framework\\ResourceManager_background.cpp(71) : TAG_RESOURCE_BGL_RING",
                            size: numBytes,
                            tag: TAG_RESOURCE_BGL_RING,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  LODWORD(v2) = 0;
  this->buffer = v5;
  this->tail = v2;
  this->commitHead = v2;
  this->cancelToTerminate = false;
  Sys_SignalClear(handle: (void **)HIDWORD(v2));
  this->lastFreeSignalTail = v2;
  Sys_SignalClear(handle: &this->dataSignal.handle);
  this->lastDataSignalHead = v2;
  this->freeWaituS = 0;
  this->numFreeWaits = 0;
  this->dataWaituS = 0;
  this->numDataWaits = 0;
  return this;
}


// ========================================================================
// __unwind$239015
// EA  : 0x8269DF08
// RVA : 0x0069DF08
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void _unwind_239015()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 144 + 164) + 28));
}


// ========================================================================
// __unwind$239016
// EA  : 0x8269DF34
// RVA : 0x0069DF34
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void _unwind_239016()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 144 + 164) + 40));
}


// ========================================================================
// ??1idBGLRingBuffer@@QAA@XZ
// EA  : 0x8269DF68
// RVA : 0x0069DF68
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void __fastcall idBGLRingBuffer::~idBGLRingBuffer(idBGLRingBuffer *this)
{
  idMem::Free(this: &mem, ptr: this->buffer, align: ALIGN_16);
  this->buffer = nullptr;
  Sys_SignalDestroy(handle: &this->dataSignal.handle);
  Sys_SignalDestroy(handle: &this->freeSignal.handle);
}


// ========================================================================
// __unwind$239053
// EA  : 0x8269DFCC
// RVA : 0x0069DFCC
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void _unwind_239053()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 112 + 132) + 28));
}


// ========================================================================
// __unwind$239054
// EA  : 0x8269DFF8
// RVA : 0x0069DFF8
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void _unwind_239054()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 112 + 132) + 40));
}


// ========================================================================
// ?CheckSpaceAndWait@idBGLRingBuffer@@QAA_J_JH@Z
// EA  : 0x8269E028
// RVA : 0x0069E028
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

int __fastcall idBGLRingBuffer::CheckSpaceAndWait(idBGLRingBuffer *this, int a2, __int64 offset, int minBytes)
{
  int v6; // r30
  int v7; // r11
  idSysSignal *p_freeSignal; // r28
  int v9; // r27
  int v10; // r3
  BOOL cancelToTerminate; // r8

  v6 = HIDWORD(offset);
  v7 = LODWORD(this->tail) - a2 + this->size;
  if ( v7 >= SHIDWORD(offset) )
    return v7;
  p_freeSignal = &this->freeSignal;
  while ( 1 )
  {
    ++this->numFreeWaits;
    v9 = Sys_Microseconds() >> 32;
    Sys_SignalWait(handle: &p_freeSignal->handle, timeout: -1);
    v10 = Sys_Microseconds() >> 32;
    cancelToTerminate = this->cancelToTerminate;
    this->freeWaituS = v10 + this->freeWaituS - v9;
    if ( cancelToTerminate )
      break;
    v7 = LODWORD(this->tail) - a2 + this->size;
    if ( v7 >= v6 )
      return v7;
  }
  return -1;
}


// ========================================================================
// ?Free@idBGLRingBuffer@@QAAX_JH@Z
// EA  : 0x8269E0E0
// RVA : 0x0069E0E0
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void __fastcall idBGLRingBuffer::Free(idBGLRingBuffer *this, int a2, __int64 base, int numBytes)
{
  __int64 v4; // r29
  idSysSignal *p_dataSignal; // r30
  int v7; // r3
  BOOL cancelToTerminate; // r7

  LODWORD(v4) = HIDWORD(base) + a2;
  if ( HIDWORD(base) + a2 <= SLODWORD(this->commitHead) )
  {
LABEL_5:
    if ( (int)v4 > SLODWORD(this->tail) )
      this->tail = v4;
    if ( LODWORD(this->tail) - LODWORD(this->lastFreeSignalTail) > 0x10000 )
    {
      Sys_SignalRaise(handle: &this->freeSignal.handle);
      this->lastFreeSignalTail = this->tail;
    }
  }
  else
  {
    p_dataSignal = &this->dataSignal;
    while ( 1 )
    {
      ++this->numDataWaits;
      HIDWORD(v4) = Sys_Microseconds() >> 32;
      Sys_SignalWait(handle: &p_dataSignal->handle, timeout: -1);
      v7 = Sys_Microseconds() >> 32;
      cancelToTerminate = this->cancelToTerminate;
      this->dataWaituS += v7 - HIDWORD(v4);
      if ( cancelToTerminate )
        break;
      if ( (int)v4 <= SLODWORD(this->commitHead) )
        goto LABEL_5;
    }
  }
}


// ========================================================================
// ??0idFile_RingBuffer@@QAA@PBDPAVidBGLRingBuffer@@_JH@Z
// EA  : 0x8269E1A8
// RVA : 0x0069E1A8
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

idFile_RingBuffer *__fastcall idFile_RingBuffer::idFile_RingBuffer(
        idFile_RingBuffer *this,
        const char *_name,
        idBGLRingBuffer *rb,
        unsigned int a4,
        __int64 ofs,
        int length)
{
  __int64 v7; // r29
  __int64 v9; // r26

  HIDWORD(v7) = _name;
  v9 = __PAIR64__(HIDWORD(ofs), a4);
  LODWORD(v7) = 0;
  idFile::idFile(this);
  this->__vftable = (idFile_RingBuffer_vtbl *)&idFile_RingBuffer::`vftable';
  this->name.len = 0;
  this->name.data = this->name.baseBuffer;
  this->name.allocedAndFlag = 20;
  this->name.baseBuffer[0] = 0;
  idStr::operator=(this: &this->name, text: (const char *)HIDWORD(v7));
  this->ringBuffer = rb;
  this->baseOffset = v9;
  this->currOffset = v7;
  this->fileSize = HIDWORD(v9);
  return this;
}


// ========================================================================
// __unwind$239131
// EA  : 0x8269E228
// RVA : 0x0069E228
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void _unwind_239131()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$239132
// EA  : 0x8269E250
// RVA : 0x0069E250
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void _unwind_239132()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 12));
}


// ========================================================================
// ?Tell@idFile_RingBuffer@@UBA_JXZ
// EA  : 0x8269E280
// RVA : 0x0069E280
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idFile_RingBuffer::Tell(idFile_RingBuffer *this)
{
  __int64 result; // r4 OVERLAPPED

  *(__int64 *)((char *)&result + 4) = this->currOffset;
  return result;
}


// ========================================================================
// ?Seek@idFile_RingBuffer@@UAAH_JW4fsOrigin_t@@@Z
// EA  : 0x8269E288
// RVA : 0x0069E288
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idFile_RingBuffer::Seek(idFile_RingBuffer *this, int a2, __int64 offset, fsOrigin_t origin)
{
  __int64 v4; // r11
  __int64 currOffset; // r30 OVERLAPPED
  const char *v7; // r3

  if ( HIDWORD(offset) == 2 )
  {
    currOffset = this->currOffset;
    if ( a2 < (int)currOffset )
    {
      HIDWORD(currOffset) = this->fileSize;
      v7 = this->GetName(this);
      idLib::Error(
        fmt: "idFile_RingBuffer(%s) does not support seeking backwards due to streaming. old offset: %lli, new: %lli, len: %i",
        v7,
        (_DWORD)currOffset,
        a2,
        HIDWORD(currOffset));
    }
    this->currOffset = *(_QWORD *)&a2;
    return a2;
  }
  else
  {
    if ( HIDWORD(offset) != 0 )
      LODWORD(v4) = this->fileSize;
    else
      v4 = this->currOffset;
    LODWORD(v4) = v4 + a2;
    this->currOffset = v4;
    return v4;
  }
}


// ========================================================================
// ?ReadOfs@idBGLRingBuffer@@QAAI_JPAXI@Z
// EA  : 0x8269E318
// RVA : 0x0069E318
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

int __fastcall idBGLRingBuffer::ReadOfs(idBGLRingBuffer *this, int a2, __int64 src, void *dst, unsigned int length)
{
  int v7; // r26
  __int64 v8; // r28
  int size; // r10
  int v10; // r9
  int v11; // r8
  signed int v12; // r31
  signed int v13; // r10
  __int64 v14; // r6
  int v15; // r7
  int v16; // r31
  int v17; // r3
  BOOL cancelToTerminate; // r8

  v7 = src;
  v8 = src;
  if ( (_DWORD)src == 0 )
    return v7;
  while ( 1 )
  {
    size = this->size;
    v10 = LODWORD(this->commitHead) - a2;
    v11 = (size - 1) & a2;
    if ( v10 >= (int)v8 )
      v10 = v8;
    v12 = v10;
    v13 = size - v11;
    if ( v10 > v13 )
      v12 = v13;
    if ( v12 <= 0 )
      break;
    memcpy(Dst: (void *)HIDWORD(v8), Src: &this->buffer[v11], Size: v12);
    HIDWORD(v14) = v12;
    idBGLRingBuffer::Free(this, a2, base: v14, numBytes: v15);
    LODWORD(v8) = v8 - v12;
    a2 += v12;
    HIDWORD(v8) += v12;
LABEL_9:
    if ( (_DWORD)v8 == 0 )
      return v7;
  }
  ++this->numDataWaits;
  v16 = Sys_Microseconds() >> 32;
  Sys_SignalWait(handle: &this->dataSignal.handle, timeout: -1);
  v17 = Sys_Microseconds() >> 32;
  cancelToTerminate = this->cancelToTerminate;
  this->dataWaituS = v17 + this->dataWaituS - v16;
  if ( !cancelToTerminate )
    goto LABEL_9;
  return 0;
}


// ========================================================================
// ?GetCount@idInventoryItem@@UBAHXZ
// EA  : 0x8269E428
// RVA : 0x0069E428
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

int __fastcall idInventoryItem::GetCount(XGRAPHICS::IRInst *this)
{
  return this->num_outputs;
}


// ========================================================================
// ?Read@idFile_RingBuffer@@UAAIPAXI@Z
// EA  : 0x8269E430
// RVA : 0x0069E430
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

int __fastcall idFile_RingBuffer::Read(idFile_RingBuffer *this, void *buffer, __int64 len)
{
  __int64 currOffset; // r11
  void *v5; // r7
  int result; // r3
  __int128 v7; // r11

  currOffset = this->currOffset;
  HIDWORD(currOffset) = this->fileSize;
  v5 = (void *)(HIDWORD(len) + currOffset);
  LODWORD(len) = HIDWORD(len);
  if ( HIDWORD(len) + (int)currOffset > SHIDWORD(currOffset) )
    LODWORD(len) = HIDWORD(currOffset) - currOffset;
  HIDWORD(len) = buffer;
  result = idBGLRingBuffer::ReadOfs(
             this: this->ringBuffer,
             a2: LODWORD(this->baseOffset) + currOffset,
             src: len,
             dst: v5,
             length: HIDWORD(currOffset));
  *(_QWORD *)((char *)&v7 + 4) = this->currOffset;
  LODWORD(v7) = result + DWORD2(v7);
  this->currOffset = v7;
  return result;
}


// ========================================================================
// ?SkipPastResource@idBackgroundLoader@@QAAXPBVidResource@@@Z
// EA  : 0x8269E4A8
// RVA : 0x0069E4A8
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void __fastcall idBackgroundLoader::SkipPastResource(idBackgroundLoader *this, idResource *r)
{
  idResourceFileEntry *v4; // r30
  const char *ResourceTypeName; // r3
  int v6; // r7
  __int64 v7; // r6
  int returnedIndex; // r11
  idBackgroundLoader::bgrEntry_t *list; // r10
  int v10; // r11

  if ( this->resourceFile == nullptr )
    idLib::FatalError(fmt: "idBackgroundLoader::SkipPastResource() called ouside a background load");
  while ( this->returnedIndex != this->fileTable->num )
  {
    v4 = &this->fileTable->list[this->returnedIndex];
    if ( idStr::Cmp(s1: v4->resourceName.data, s2: r->name.str) != 0 )
      break;
    ResourceTypeName = idResource::GetResourceTypeName(this: r);
    if ( idStr::Cmp(s1: v4->typeName.data, s2: ResourceTypeName) != 0 )
      break;
    if ( this->decompressIndex <= this->returnedIndex )
    {
      while ( !this->cancelToTerminate )
      {
        mgthread_sleep(ms: 1);
        if ( this->decompressIndex > this->returnedIndex )
          goto LABEL_9;
      }
      return;
    }
LABEL_9:
    returnedIndex = this->returnedIndex;
    list = this->bgrEntries.list;
    this->returnedIndex = returnedIndex + 1;
    v10 = returnedIndex;
    HIDWORD(v7) = v4->uncompressedLength;
    if ( HIDWORD(v7) != 0 )
      idBGLRingBuffer::Free(this: this->decompressBuffer, a2: list[v10].ringBufferOffset, base: v7, numBytes: v6);
  }
}


// ========================================================================
// ?DetermineNextReadBlock@idBackgroundLoader@@AAAXXZ
// EA  : 0x8269E5A8
// RVA : 0x0069E5A8
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void __fastcall idBackgroundLoader::DetermineNextReadBlock(idBackgroundLoader *this)
{
  int currentReadBuffer; // r7
  __int64 v2; // r9
  int v3; // r11
  int v4; // r10
  idReadSpawnThread *readSpawnThread; // r3

  currentReadBuffer = this->currentReadBuffer;
  HIDWORD(v2) = this->fileTable;
  LODWORD(v2) = LODWORD(this->readBufferOfs[currentReadBuffer & 1]) + 0x10000;
  if ( this->readIndex < *(_DWORD *)(HIDWORD(v2) + 4) )
  {
    while ( 1 )
    {
      v3 = 1144 * this->readIndex + *(_DWORD *)HIDWORD(v2);
      v4 = *(_DWORD *)(v3 + 648);
      if ( (int)v2 < *(_DWORD *)(v3 + 652) + v4 )
        break;
      if ( ++this->readIndex >= this->fileTable->num )
        return;
    }
    if ( (int)v2 + 0x10000 < v4 )
    {
      LODWORD(v2) = v4 & 0xFFFF0000;
      ++this->backgroundSeeks;
    }
    this->currentReadBuffer = currentReadBuffer + 1;
    this->readBufferOfs[(currentReadBuffer + 1) & 1] = v2;
    readSpawnThread = this->readSpawnThread;
    if ( readSpawnThread != nullptr )
      idSysThread::SignalWork(this: readSpawnThread);
  }
}


// ========================================================================
// ?SpawnThreads@idBackgroundLoader@@QAAXXZ
// EA  : 0x8269E678
// RVA : 0x0069E678
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void __fastcall idBackgroundLoader::SpawnThreads(idBackgroundLoader *this)
{
  __int64 v1; // r27
  idSysThread *v2; // r3
  idSysThread *v3; // r30
  idSysThread *v4; // r11
  idSysThread *v5; // r3
  idSysThread *v6; // r30
  char **p_data; // r11
  __int64 v8; // r9
  int i; // ctr
  int v10; // r11

  HIDWORD(v1) = this;
  v2 = (idSysThread *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x3Cu,
                        tag: TAG_RESOURCE_BGL,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v3 = v2;
  if ( v2 != nullptr )
  {
    idSysThread::idSysThread(this: v2);
    LODWORD(v1) = 0;
    v3[1].__vftable = nullptr;
    v4 = v3;
    v3->__vftable = (idSysThread_vtbl *)&idReadSpawnThread::`vftable';
  }
  else
  {
    LODWORD(v1) = 0;
    v4 = nullptr;
  }
  *(_DWORD *)(HIDWORD(v1) + 76) = v4;
  v5 = (idSysThread *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x80u,
                        tag: TAG_RESOURCE_BGL,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v6 = v5;
  if ( v5 != nullptr )
  {
    idSysThread::idSysThread(this: v5);
    *(_QWORD *)&v6[1].__vftable = v1;
    *(_QWORD *)&v6[1].name.data = v1;
    p_data = &v6[1].name.data;
    v6->__vftable = (idSysThread_vtbl *)&idDecompressSpawnThread::`vftable';
    LODWORD(v8) = 0;
    for ( i = 7; i != 0; --i )
    {
      p_data += 2;
      *(_QWORD *)p_data = v8;
    }
  }
  else
  {
    v6 = nullptr;
  }
  v10 = *(_DWORD *)(HIDWORD(v1) + 76);
  *(_DWORD *)(HIDWORD(v1) + 80) = v6;
  *(_DWORD *)(v10 + 56) = v6;
  idSysThread::StartWorkerThread(
    this: *(idSysThread **)(HIDWORD(v1) + 76),
    name_: "BGL_ReadThread",
    core: CORE_1A,
    priority: THREAD_HIGHEST,
    stackSize: 0x20000);
  idSysThread::StartWorkerThread(
    this: *(idSysThread **)(HIDWORD(v1) + 80),
    name_: "BGL_DecompressThread",
    core: CORE_1B,
    priority: THREAD_HIGHEST,
    stackSize: 0x20000);
}


// ========================================================================
// __unwind$239354
// EA  : 0x8269E7AC
// RVA : 0x0069E7AC
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void _unwind_239354()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_RESOURCE_BGL);
}


// ========================================================================
// __unwind$239355
// EA  : 0x8269E7D8
// RVA : 0x0069E7D8
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void _unwind_239355()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_RESOURCE_BGL);
}


// ========================================================================
// ??1idFile_RingBuffer@@UAA@XZ
// EA  : 0x8269E810
// RVA : 0x0069E810
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void __fastcall idFile_RingBuffer::~idFile_RingBuffer(idFile_RingBuffer *this, int a2, __int64 a3, int a4)
{
  __int64 currOffset; // r11

  this->__vftable = (idFile_RingBuffer_vtbl *)&idFile_RingBuffer::`vftable';
  currOffset = this->currOffset;
  if ( HIDWORD(currOffset) - (int)currOffset > 128 )
    idLib::Warning(
      fmt: "idFile_RingBuffer file '%s' skipping %d bytes of stream data",
      this->name.data,
      HIDWORD(currOffset) - (_DWORD)currOffset);
  HIDWORD(a3) = this->fileSize;
  idBGLRingBuffer::Free(this: this->ringBuffer, a2: this->baseOffset, base: a3, numBytes: a4);
  idStr::FreeData(this: &this->name);
  this->__vftable = (idFile_RingBuffer_vtbl *)&idFile::`vftable';
}


// ========================================================================
// __unwind$239510
// EA  : 0x8269E8A4
// RVA : 0x0069E8A4
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void _unwind_239510()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$239511
// EA  : 0x8269E8CC
// RVA : 0x0069E8CC
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void _unwind_239511()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 12));
}


// ========================================================================
// ?EndBackgroundLoads@idBackgroundLoader@@QAAXXZ
// EA  : 0x8269E958
// RVA : 0x0069E958
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void __fastcall idBackgroundLoader::EndBackgroundLoads(idBackgroundLoader *this)
{
  idDecompressSpawnThread *decompressSpawnThread; // r11
  int v3; // r30
  int v4; // r29
  __int64 v5; // r9
  __int64 v6; // r11
  idBGLRingBuffer **p_decompressBuffer; // r29
  int i; // r30
  idBGLRingBuffer *decompressBuffer; // r30
  idBackgroundLoader::bgrEntry_t *list; // r4

  decompressSpawnThread = this->decompressSpawnThread;
  if ( decompressSpawnThread != nullptr )
    inflateEnd(strm: &decompressSpawnThread->z);
  v3 = Sys_Milliseconds();
  v4 = this->currentReadBuffer << 16;
  idLib::Printf(fmt: "--------- EndBackgroundLoads() ----------\n");
  LODWORD(v5) = v4;
  LODWORD(v6) = this->backgroundReadMsec;
  idLib::Printf(
    fmt: "IO: %i seeks, %i reads, %3.0fMB, %5.1fMB/s\n",
    this->backgroundSeeks,
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v5 * (float)0.000001))),
    (float)((float)v5 * (float)0.000001),
    (float)((float)((float)v5 * (float)0.001) / (float)v6));
  idLib::Printf(fmt: "Read       sleep msec: %5i\n", this->backgroundSleepMsec);
  idLib::Printf(fmt: "Decompress sleep msec: %5i\n", this->decompressSleepMsec);
  idLib::Printf(fmt: "Foreground sleep msec: %5i\n", this->foregroundSleepMsec);
  idLib::Printf(fmt: "Decompress work msec: %5i\n", this->decompressWorkMsec);
  idLib::Printf(
    fmt: "Ringbuf: freeWait %i/%i, dataWait %i/%i\n",
    this->decompressBuffer->freeWaituS / 1000,
    this->decompressBuffer->numFreeWaits,
    this->decompressBuffer->dataWaituS / 1000,
    this->decompressBuffer->numDataWaits);
  idLib::Printf(fmt: "Total            msec: %5i\n", v3 - this->startForegroundTime);
  idMem::InitMapHeap(this: &mem);
  p_decompressBuffer = &this->decompressBuffer;
  for ( i = 2; i != 0; --i )
  {
    idMem::Free(this: &mem, ptr: p_decompressBuffer[1], align: ALIGN_16);
    *++p_decompressBuffer = nullptr;
  }
  decompressBuffer = this->decompressBuffer;
  if ( decompressBuffer != nullptr )
  {
    idBGLRingBuffer::~idBGLRingBuffer(this: this->decompressBuffer);
    idMem::Free(this: &mem, ptr: decompressBuffer, align: ALIGN_16);
  }
  this->decompressBuffer = nullptr;
  idMem::InitMapHeap(this: &mem);
  if ( this->bgrEntries.listStatic == 0 || this->bgrEntries.listStatic == 2 )
  {
    list = this->bgrEntries.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->bgrEntries.list = nullptr;
    this->bgrEntries.size = 0;
  }
  this->bgrEntries.num = 0;
  this->fileTable = nullptr;
  this->resourceFile = nullptr;
}


// ========================================================================
// ?GetFile@idBackgroundLoader@@QAAPAVidFile@@PBD@Z
// EA  : 0x8269EB40
// RVA : 0x0069EB40
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

idFile_RingBuffer *__fastcall idBackgroundLoader::GetFile(idBackgroundLoader *this, const char *filename)
{
  int v4; // r11
  int v5; // r10
  int v6; // r10
  volatile int returnedIndex; // r28
  volatile int v8; // r29
  idResourceFileEntry *v9; // r26
  int v10; // r4
  idFile_RingBuffer *v11; // r30
  idBackgroundLoader::bgrEntry_t *list; // r29
  int v14; // r29
  int v15; // r9
  __int64 v16; // r8
  idFile_RingBuffer *v17; // r3
  idStr v18; // [sp+60h] [-70h] BYREF

  if ( this->resourceFile == nullptr )
    idLib::FatalError(fmt: "idBackgroundLoader::GetFile() called ouside a background load");
  if ( this->cancelToTerminate )
    return nullptr;
  idStr::idStr(this: &v18, text: filename);
  idStr::MakeNameCanonical(this: &v18);
  v4 = 0;
  v5 = *filename;
  if ( *filename != 0 )
  {
    do
      ++v4;
    while ( filename[v4] != 0 );
    if ( v4 > 5 && (v5 == 47 || v5 == 92 || filename[1] == 58) )
    {
      v6 = idStr::Find(searchIn: v18.data, searchFor: "/base/", casesensitive: true, start: 0, end: v18.len);
      if ( v6 >= 0 )
        idStr::operator=(this: &v18, text: &v18.data[v6 + 6]);
    }
  }
  idStr::StripLeading(this: &v18, c: 47);
  returnedIndex = this->returnedIndex;
  if ( returnedIndex >= this->fileTable->num )
  {
LABEL_16:
    v11 = (idFile_RingBuffer *)resourceManager->LoadCacheFile(this: resourceManager, a2: filename);
  }
  else
  {
    v8 = returnedIndex;
    while ( 1 )
    {
      v9 = &this->fileTable->list[v8];
      if ( idStr::Cmp(s1: v9->filename.data, s2: v18.data) == 0 )
        break;
      ++returnedIndex;
      ++v8;
      if ( returnedIndex >= this->fileTable->num )
        goto LABEL_16;
    }
    while ( 1 )
    {
      if ( this->decompressIndex >= returnedIndex )
      {
        list = this->bgrEntries.list;
        if ( LODWORD(list[returnedIndex].ringBufferOffset) != -1 && v9->uncompressedLength != 0 )
          break;
      }
      ((void (__fastcall *)(idCommon *, int, int, int, _DWORD, double))common->UpdateLevelLoadPacifier)(
        a1: common,
        a2: v10,
        a3: 1,
        a4: 1,
        a5: 0,
        a6: 0.0);
      if ( this->cancelToTerminate )
      {
        idStr::FreeData(this: &v18);
        return nullptr;
      }
      v14 = Sys_Milliseconds();
      Sys_SignalWait(handle: &this->entryStartedSignal.handle, timeout: 10);
      this->foregroundSleepMsec = Sys_Milliseconds() + this->foregroundSleepMsec - v14;
    }
    this->returnedIndex = returnedIndex + 1;
    if ( v9->uncompressedLength == 0 )
    {
      idStr::FreeData(this: &v18);
      return nullptr;
    }
    v17 = (idFile_RingBuffer *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x40u,
                                 tag: TAG_RESOURCE_BGL,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
    if ( v17 != nullptr )
    {
      HIDWORD(v16) = v9->uncompressedLength;
      v11 = idFile_RingBuffer::idFile_RingBuffer(
              this: v17,
              _name: filename,
              rb: this->decompressBuffer,
              a4: list[returnedIndex].ringBufferOffset,
              ofs: v16,
              length: v15);
    }
    else
    {
      v11 = nullptr;
    }
  }
  idStr::FreeData(this: &v18);
  return v11;
}


// ========================================================================
// $LN63
// EA  : 0x8269EDD0
// RVA : 0x0069EDD0
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void _LN63()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$239620
// EA  : 0x8269EDF8
// RVA : 0x0069EDF8
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void _unwind_239620()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 208 + 80), tag: TAG_RESOURCE_BGL);
}


// ========================================================================
// ?Run@idDecompressSpawnThread@@UAAHXZ
// EA  : 0x8269EE28
// RVA : 0x0069EE28
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idDecompressSpawnThread::Run(idDecompressSpawnThread *this)
{
  int v2; // r29
  int v3; // r3
  int v4; // r19
  _BYTE v5[12]; // r18 OVERLAPPED
  int v6; // r7
  __int64 v7; // r6
  idResourceFileEntry *v8; // r22
  __int64 compressedOffsetInCurrentEntry; // r11
  idBackgroundLoader::bgrEntry_t *list; // r26
  int v11; // r27
  unsigned int decompressIndex; // r25
  __int128 v13; // r11
  int v14; // r23
  int v15; // r4
  int v16; // r11
  int v17; // r3
  signed int v18; // r29
  __int64 v19; // r8 OVERLAPPED
  int v20; // r3
  __int64 uncompressedOffsetInCurrentEntry; // r11 OVERLAPPED
  int v22; // r21
  signed int v23; // r28
  __int64 v24; // r6
  __int64 v25; // r10
  __int64 ringBufferOffset; // r10
  int size; // r11
  int v28; // r11
  int v29; // r9
  int v30; // r4
  bool v31; // r11
  idBGLRingBuffer *decompressBuffer; // r29
  idBGLRingBuffer *v34; // r31
  idSysSignal *p_freeSignal; // r3

  if ( bgl.cancelToTerminate )
    return 0;
  v2 = Sys_Milliseconds();
  v3 = Sys_Milliseconds();
  if ( bgl.decompressIndex != 0 )
    bgl.decompressSleepMsec = bgl.decompressSleepMsec - v2 + v3;
  if ( bgl.decompressIndex >= bgl.fileTable->num )
    idLib::FatalError(fmt: "idBackgroundLoader::DecompressThread: decompressIndex >= fileTable->Num()");
  v4 = *(int *)((char *)bgl.readBuffers + ((4 * bgl.currentReadBuffer) & 4));
  *(_QWORD *)v5 = *(__int64 *)((char *)bgl.readBufferOfs + ((8 * bgl.currentReadBuffer) & 8));
  idBackgroundLoader::DetermineNextReadBlock(this: &bgl);
  LODWORD(v7) = bgl.decompressIndex;
  if ( bgl.decompressIndex >= bgl.bgrEntries.num )
    return 0;
  *(_DWORD *)&v5[8] = 0;
  while ( 1 )
  {
    v8 = &bgl.fileTable->list[bgl.decompressIndex];
    if ( v8->uncompressedLength != 0 )
      break;
    ++bgl.decompressIndex;
LABEL_47:
    if ( bgl.decompressIndex >= bgl.bgrEntries.num )
      return 0;
  }
  compressedOffsetInCurrentEntry = this->compressedOffsetInCurrentEntry;
  list = bgl.bgrEntries.list;
  v11 = HIDWORD(compressedOffsetInCurrentEntry) - *(_DWORD *)&v5[4] + compressedOffsetInCurrentEntry;
  decompressIndex = bgl.decompressIndex;
  if ( v11 >= 0x10000 )
    return 0;
  if ( (_DWORD)compressedOffsetInCurrentEntry == 0 )
  {
    bgl.bgrEntries.list[decompressIndex].ringBufferOffset = bgl.decompressBuffer->commitHead;
    Sys_SignalRaise(handle: &bgl.entryStartedSignal.handle);
  }
  *((_QWORD *)&v13 + 1) = this->uncompressedOffsetInCurrentEntry;
  *(idBackgroundLoader::bgrEntry_t *)((char *)&v13 + 4) = list[decompressIndex];
  v14 = DWORD1(v13) - v13;
  v15 = DWORD2(v13) + v13;
  v16 = DWORD1(v13) - v13;
  if ( v16 >= 0x40000 )
    v16 = 0x40000;
  HIDWORD(v7) = v16;
  v17 = idBGLRingBuffer::CheckSpaceAndWait(this: bgl.decompressBuffer, a2: v15, offset: v7, minBytes: v6);
  if ( v14 < v17 )
    v17 = v14;
  v18 = v17;
  if ( bgl.cancelToTerminate )
    return 0;
  v20 = Sys_Milliseconds();
  HIDWORD(uncompressedOffsetInCurrentEntry) = v8->compressedLength;
  v22 = v20;
  v23 = HIDWORD(uncompressedOffsetInCurrentEntry) - LODWORD(this->compressedOffsetInCurrentEntry);
  if ( v23 + v11 > 0x10000 )
    v23 = 0x10000 - v11;
  if ( HIDWORD(uncompressedOffsetInCurrentEntry) == v8->uncompressedLength )
  {
    if ( v23 >= v18 )
      v23 = v18;
    LODWORD(v24) = v23;
    HIDWORD(v24) = v11 + v4;
    idBGLRingBuffer::WriteOfs(
      this: bgl.decompressBuffer,
      a2: LODWORD(list[decompressIndex].ringBufferOffset) + LODWORD(this->uncompressedOffsetInCurrentEntry),
      dst: v24,
      src: (const void *)HIDWORD(v19),
      length: HIDWORD(this->uncompressedOffsetInCurrentEntry));
    v25 = this->compressedOffsetInCurrentEntry;
    HIDWORD(v25) += v23;
    LODWORD(v19) = v25 + v23;
    this->uncompressedOffsetInCurrentEntry = *(__int64 *)((char *)&v19 - 4);
    this->compressedOffsetInCurrentEntry = v19;
    goto LABEL_41;
  }
  this->z.avail_in = v23;
  this->z.next_in = (unsigned __int8 *)(v11 + v4);
  if ( v23 != 0 )
  {
    do
    {
      if ( v18 == 0 && v14 != 0 )
        break;
      if ( bgl.cancelToTerminate )
        return 0;
      ringBufferOffset = list[decompressIndex].ringBufferOffset;
      *(__int64 *)((char *)&v19 - 4) = this->uncompressedOffsetInCurrentEntry;
      size = bgl.decompressBuffer->size;
      this->z.avail_out = v18;
      HIDWORD(v19) = size - 1;
      v28 = (ringBufferOffset + HIDWORD(ringBufferOffset)) & (size - 1);
      this->z.next_out = &bgl.decompressBuffer->buffer[v28];
      HIDWORD(uncompressedOffsetInCurrentEntry) = bgl.decompressBuffer;
      LODWORD(uncompressedOffsetInCurrentEntry) = bgl.decompressBuffer->size - v28;
      if ( (int)uncompressedOffsetInCurrentEntry >= v18 )
        break;
      this->z.avail_out = uncompressedOffsetInCurrentEntry;
      if ( inflate(strm: &this->z, flush: 0) != 0 )
        goto LABEL_49;
      uncompressedOffsetInCurrentEntry = this->uncompressedOffsetInCurrentEntry;
      HIDWORD(uncompressedOffsetInCurrentEntry) = this->z.total_out;
      v29 = this->uncompressedOffsetInCurrentEntry;
      this->uncompressedOffsetInCurrentEntry = *(__int64 *)((char *)&uncompressedOffsetInCurrentEntry + 4);
      v18 += uncompressedOffsetInCurrentEntry - HIDWORD(uncompressedOffsetInCurrentEntry);
      HIDWORD(v19) = this->z.avail_in;
    }
    while ( HIDWORD(v19) != 0 );
  }
  if ( this->z.avail_in == 0 || v18 == 0 && v14 != 0 )
  {
LABEL_40:
    LODWORD(uncompressedOffsetInCurrentEntry) = this->z.total_in;
    this->compressedOffsetInCurrentEntry = uncompressedOffsetInCurrentEntry;
LABEL_41:
    v31 = LODWORD(this->uncompressedOffsetInCurrentEntry) == v8->uncompressedLength;
    decompressBuffer = bgl.decompressBuffer;
    LODWORD(v19) = LODWORD(list[decompressIndex].ringBufferOffset) + HIDWORD(list[decompressIndex].ringBufferOffset);
    bgl.decompressBuffer->commitHead = v19;
    if ( v31 || (int)v19 - LODWORD(decompressBuffer->lastDataSignalHead) > 0x10000 )
    {
      Sys_SignalRaise(handle: &decompressBuffer->dataSignal.handle);
      decompressBuffer->lastDataSignalHead = decompressBuffer->commitHead;
    }
    if ( LODWORD(this->compressedOffsetInCurrentEntry) == v8->compressedLength )
    {
      this->compressedOffsetInCurrentEntry = *(_QWORD *)&v5[4];
      this->uncompressedOffsetInCurrentEntry = *(_QWORD *)&v5[4];
      this->z.total_out = 0;
      this->z.total_in = 0;
      ++bgl.decompressIndex;
    }
    bgl.decompressWorkMsec = Sys_Milliseconds() + bgl.decompressWorkMsec - v22;
    goto LABEL_47;
  }
  if ( v23 + LODWORD(this->compressedOffsetInCurrentEntry) != v8->compressedLength
    || (v30 = 4, v18 + LODWORD(this->uncompressedOffsetInCurrentEntry) != v8->uncompressedLength) )
  {
    v30 = 0;
  }
  if ( inflate(strm: &this->z, flush: v30) == 0
    || (HIDWORD(uncompressedOffsetInCurrentEntry) = v8->uncompressedLength,
        this->z.total_out == HIDWORD(uncompressedOffsetInCurrentEntry)) )
  {
    LODWORD(uncompressedOffsetInCurrentEntry) = this->z.total_out;
    this->uncompressedOffsetInCurrentEntry = uncompressedOffsetInCurrentEntry;
    goto LABEL_40;
  }
LABEL_49:
  idLib::Warning(fmt: "zlib inflate error");
  inflateEnd(strm: &this->z);
  bgl.cancelToTerminate = true;
  v34 = bgl.decompressBuffer;
  p_freeSignal = &bgl.decompressBuffer->freeSignal;
  bgl.decompressBuffer->cancelToTerminate = true;
  Sys_SignalRaise(handle: &p_freeSignal->handle);
  Sys_SignalRaise(handle: &v34->dataSignal.handle);
  return 0;
}


// ========================================================================
// ?BeginBackgroundLoads@idBackgroundLoader@@QAAXAAVidFile@@ABV?$idList@VidResourceFileEntry@@$0GF@@@@Z
// EA  : 0x8269F2F0
// RVA : 0x0069F2F0
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void __fastcall idBackgroundLoader::BeginBackgroundLoads(
        idBackgroundLoader *this,
        idFile *resourceFile_,
        const idList<idResourceFileEntry,101> *fileTable_)
{
  __int64 v3; // r24
  unsigned __int8 **readBuffers; // r26
  idBGLRingBuffer **p_decompressBuffer; // r27
  int v9; // r29
  idBGLRingBuffer *v10; // r3
  idBGLRingBuffer *v11; // r3
  __int64 v12; // r10
  int v13; // r7
  __int64 v14; // r6
  int v15; // r4
  idDecompressSpawnThread *decompressSpawnThread; // r3
  const idList<idResourceFileEntry,101> *fileTable; // r11
  int num; // r29
  int size; // r11
  int v20; // r11
  int v21; // r10
  int v22; // r9
  idResourceFileEntry *v23; // r8

  this->startForegroundTime = Sys_Milliseconds();
  this->fileTable = fileTable_;
  this->resourceFile = resourceFile_;
  idMem::InitMapHeap(this: &mem);
  readBuffers = this->readBuffers;
  p_decompressBuffer = &this->decompressBuffer;
  v9 = 2;
  LODWORD(v3) = -65536;
  do
  {
    *++p_decompressBuffer = (idBGLRingBuffer *)idMem::AllocWithLocation(
                                                 this: &mem,
                                                 location: "w:\\tech5\\engine\\framework\\ResourceManager_background.cpp(400) : TAG_RESOURCE_BGL",
                                                 size: 0x10000u,
                                                 tag: TAG_RESOURCE_BGL,
                                                 zeroBuffer: false,
                                                 align: ALIGN_16,
                                                 heap: HEAP_DEFAULTHEAP);
    --v9;
    readBuffers += 2;
    *(_QWORD *)readBuffers = v3;
  }
  while ( v9 != 0 );
  idMem::InitMapHeap(this: &mem);
  this->currentReadBuffer = 0;
  idMem::InitMapHeap(this: &mem);
  v10 = (idBGLRingBuffer *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x48u,
                             tag: TAG_RESOURCE_BGL_RING,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v10 != nullptr )
    v11 = idBGLRingBuffer::idBGLRingBuffer(this: v10, numBytes: 0x1000000u);
  else
    v11 = nullptr;
  this->decompressBuffer = v11;
  idMem::InitMapHeap(this: &mem);
  decompressSpawnThread = this->decompressSpawnThread;
  if ( decompressSpawnThread != nullptr )
    idDecompressSpawnThread::BeginBackgroundLoads(
      this: decompressSpawnThread,
      a2: v15,
      a3: SHIDWORD(v14),
      a4: v14,
      a5: v13,
      a6: v12);
  fileTable = this->fileTable;
  num = fileTable->num;
  if ( num <= this->bgrEntries.size
    || idList<idBackgroundLoader::bgrEntry_t,101>::Resize(this: &this->bgrEntries, newsize: fileTable->num) )
  {
    size = this->bgrEntries.size;
    if ( num < size )
      size = num;
    this->bgrEntries.num = size;
  }
  v20 = 0;
  if ( this->fileTable->num <= 0 )
  {
LABEL_18:
    this->readIndex = 0;
    this->decompressIndex = 0;
    this->returnedIndex = 0;
    this->backgroundSeeks = 0;
    this->backgroundReadMsec = 0;
    this->backgroundSleepMsec = 0;
    this->foregroundSleepMsec = 0;
    this->decompressSleepMsec = 0;
    this->decompressWorkMsec = 0;
    this->cancelToTerminate = false;
    idBackgroundLoader::DetermineNextReadBlock(this);
  }
  else
  {
    v21 = 0;
    v22 = 0;
    LODWORD(v14) = -1;
    while ( 1 )
    {
      if ( v20 > 0 )
      {
        v23 = &this->fileTable->list[v21];
        HIDWORD(v14) = v23->offset;
        if ( HIDWORD(v14) < v23[-1].offset )
          break;
      }
      this->bgrEntries.list[v22].ringBufferOffset = v14;
      ++v20;
      ++v22;
      ++v21;
      if ( v20 >= this->fileTable->num )
        goto LABEL_18;
    }
    idLib::FatalError(fmt: "idBackgroundLoader::BeginBackgroundLoads: FileTable is out of order");
    _LN49();
  }
}


// ========================================================================
// $LN49
// EA  : 0x8269F4D8
// RVA : 0x0069F4D8
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void _LN49()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_RESOURCE_BGL_RING);
}


// ========================================================================
// `dynamic initializer for 'bgl_debug''
// EA  : 0x8333C710
// RVA : 0x0133C710
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bgl_debug__()
{
  idCVar::idCVar(
    this: &bgl_debug,
    name: "bgl_debug",
    value: "0",
    flags: 2,
    description: "Set to 1 for console spew",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bgl_debug__);
}


// ========================================================================
// `dynamic initializer for 'bgl''
// EA  : 0x8333C770
// RVA : 0x0133C770
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bgl__()
{
  __int64 v0; // r29

  LODWORD(v0) = 0;
  bgl.readIndex = 0;
  bgl.decompressIndex = 0;
  bgl.cancelToTerminate = false;
  Sys_SignalCreate(handle: &bgl.entryStartedSignal.handle, manualReset: false);
  bgl.decompressBuffer = nullptr;
  bgl.currentReadBuffer = 0;
  bgl.readSpawnThread = nullptr;
  bgl.decompressSpawnThread = nullptr;
  bgl.foregroundSleepMsec = 0;
  bgl.backgroundSeeks = 0;
  bgl.decompressSleepMsec = 0;
  bgl.startForegroundTime = 0;
  bgl.readBuffers[0] = nullptr;
  bgl.readBuffers[1] = nullptr;
  bgl.readBufferOfs[0] = v0;
  bgl.readBufferOfs[1] = v0;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bgl__);
}


// ========================================================================
// __unwind$240011
// EA  : 0x8333C7F4
// RVA : 0x0133C7F4
// PDB : w:\tech5\engine\framework\resourcemanager_background.cpp
// ========================================================================

void _unwind_240011()
{
  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)&bgl.bgrEntries);
}

