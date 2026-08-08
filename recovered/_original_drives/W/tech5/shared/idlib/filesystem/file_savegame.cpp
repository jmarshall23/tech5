
// ========================================================================
// ZlibAlloc
// EA  : 0x82F1ADD8
// RVA : 0x00F1ADD8
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void *__fastcall ZlibAlloc(void *opaque, unsigned int items, unsigned int size)
{
  return idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\filesystem\\File_SaveGame.cpp(55) : TAG_RESOURCE_BGL",
           size: items * size,
           tag: TAG_RESOURCE_BGL,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
}


// ========================================================================
// ?WriteBlock@idFile_SaveGamePipelined@@AAAXXZ
// EA  : 0x82F1AE08
// RVA : 0x00F1AE08
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall idFile_SaveGamePipelined::WriteBlock(idFile_SaveGamePipelined *this)
{
  unsigned int *p_bytesIO; // r31
  unsigned __int8 **p_dataIO; // r30
  idFile *nativeFile; // r7

  p_bytesIO = &this->bytesIO;
  p_dataIO = &this->dataIO;
  nativeFile = this->nativeFile;
  this->compressedLength += this->bytesIO;
  ((void (__fastcall *)(idFile *, unsigned __int8 *))nativeFile->Write)(a1: nativeFile, a2: this->dataIO);
  *p_dataIO = nullptr;
  *p_bytesIO = 0;
}


// ========================================================================
// ?ReadBlock@idFile_SaveGamePipelined@@AAAXXZ
// EA  : 0x82F1AE88
// RVA : 0x00F1AE88
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall idFile_SaveGamePipelined::ReadBlock(idFile_SaveGamePipelined *this)
{
  bool *p_nativeFileEndHit; // r31
  unsigned int *p_compressedProducedBytes; // r30
  unsigned int v3; // r3

  p_nativeFileEndHit = &this->nativeFileEndHit;
  if ( !this->nativeFileEndHit )
  {
    p_compressedProducedBytes = &this->compressedProducedBytes;
    v3 = this->nativeFile->Read(
           this: this->nativeFile,
           a2: &this->compressed[this->compressedProducedBytes & 0x3FFFF],
           a3: 0x20000u);
    *p_compressedProducedBytes += v3;
    if ( v3 != 0x20000 )
      *p_nativeFileEndHit = true;
  }
}


// ========================================================================
// ?Tell@idFile_SaveGamePipelined@@UBA_JXZ
// EA  : 0x82F1AF28
// RVA : 0x00F1AF28
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idFile_SaveGamePipelined::Tell(idFile_SaveGamePipelined *this)
{
  __int64 result; // r4 OVERLAPPED

  *(__int64 *)((char *)&result + 4) = this->ioPos;
  return result;
}


// ========================================================================
// ?Run@idSGFwriteThread@@UAAHXZ
// EA  : 0x82F1AF30
// RVA : 0x00F1AF30
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

int __fastcall idSGFwriteThread::Run(idSGFwriteThread *this)
{
  idFile_SaveGamePipelined::WriteBlock(this: this->sgf);
  return 0;
}


// ========================================================================
// ?Run@idSGFreadThread@@UAAHXZ
// EA  : 0x82F1AF58
// RVA : 0x00F1AF58
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

int __fastcall idSGFreadThread::Run(idSGFreadThread *this)
{
  idFile_SaveGamePipelined::ReadBlock(this: this->sgf);
  return 0;
}


// ========================================================================
// ?Abort@idFile_SaveGamePipelined@@QAAXXZ
// EA  : 0x82F1AF80
// RVA : 0x00F1AF80
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall idFile_SaveGamePipelined::Abort(idFile_SaveGamePipelined *this)
{
  idFile_SaveGamePipelined::mode_t mode; // r11
  idSGFcompressThread *compressThread; // r3
  idSysThread *writeThread; // r3
  idSysSignal *p_blockAvailable; // r3
  idSGFdecompressThread *decompressThread; // r3

  mode = this->mode;
  if ( mode == WRITE )
  {
    compressThread = this->compressThread;
    if ( compressThread != nullptr )
      idSysThread::WaitForThread(this: compressThread);
    writeThread = this->writeThread;
    if ( writeThread == nullptr )
    {
      if ( this->nativeFile == nullptr && !this->nativeFileEndHit )
      {
        Sys_SignalWait(handle: &this->blockRequested.handle, timeout: -1);
        p_blockAvailable = &this->blockAvailable;
LABEL_16:
        this->finished = true;
        this->dataIO = nullptr;
        this->bytesIO = 0;
        Sys_SignalRaise(handle: &p_blockAvailable->handle);
        Sys_SignalWait(handle: &this->blockFinished.handle, timeout: -1);
        goto LABEL_17;
      }
      goto LABEL_17;
    }
LABEL_12:
    idSysThread::WaitForThread(this: writeThread);
    goto LABEL_17;
  }
  if ( mode == READ )
  {
    decompressThread = this->decompressThread;
    if ( decompressThread != nullptr )
      idSysThread::WaitForThread(this: decompressThread);
    writeThread = this->readThread;
    if ( writeThread != nullptr )
      goto LABEL_12;
    if ( this->nativeFile == nullptr && !this->nativeFileEndHit )
    {
      Sys_SignalWait(handle: &this->blockAvailable.handle, timeout: -1);
      p_blockAvailable = &this->blockRequested;
      goto LABEL_16;
    }
  }
LABEL_17:
  this->mode = 0;
}


// ========================================================================
// ?OpenForWriting@idFile_SaveGamePipelined@@QAA_NQBD_N@Z
// EA  : 0x82F1B0F8
// RVA : 0x00F1B0F8
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

idFile *__fastcall idFile_SaveGamePipelined::OpenForWriting(
        idFile_SaveGamePipelined *this,
        const char *filename,
        bool useNativeFile)
{
  idFile **p_nativeFile; // r25
  idFile *result; // r3
  int v8; // r29
  int valueInteger; // r11
  idSysThread *v10; // r3
  idSGFcompressThread *v11; // r29
  idSGFcompressThread *v12; // r11
  idSysThread *v13; // r3
  idSGFwriteThread *v14; // r29
  idSGFwriteThread *v15; // r11

  idStr::operator=(this: &this->name, text: filename);
  idStr::operator=(this: &this->osPath, text: filename);
  p_nativeFile = &this->nativeFile;
  this->mode = WRITE;
  this->nativeFile = nullptr;
  this->numChecksums = 0;
  if ( !useNativeFile
    || (result = fileSystem->OpenFileWrite(this: fileSystem, a2: filename, a3: 0),
        *p_nativeFile = result,
        result != nullptr) )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    v8 = deflateInit2_(
           strm: &this->zStream,
           level: 1,
           method: 8,
           windowBits: sgf_windowBits.valueInteger,
           memLevel: 9,
           strategy: 0,
           version: "1.2.3",
           stream_size: 56);
    idMem::PopHeap(this: &mem);
    if ( v8 != 0 )
      idLib::FatalError(fmt: "idFile_SaveGamePipelined::OpenForWriting: deflateInit2() error %i", v8);
    this->zStream.avail_out = 0x20000;
    this->zStream.next_out = this->compressed;
    if ( sgf_checksums.valueInteger != 0 )
      this->zStream.avail_out = 131068;
    valueInteger = sgf_threads.valueInteger;
    if ( sgf_threads.valueInteger >= 1 )
    {
      v10 = (idSysThread *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                             size: 0x3Cu,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      v11 = (idSGFcompressThread *)v10;
      if ( v10 != nullptr )
      {
        idSysThread::idSysThread(this: v10);
        v12 = v11;
        v11->__vftable = (idSGFcompressThread_vtbl *)&idSGFcompressThread::`vftable';
      }
      else
      {
        v12 = nullptr;
      }
      this->compressThread = v12;
      v12->sgf = this;
      idSysThread::StartWorkerThread(
        this: this->compressThread,
        name_: "SGF_CompressThread",
        core: CORE_1B,
        priority: THREAD_NORMAL,
        stackSize: 0x20000);
      valueInteger = sgf_threads.valueInteger;
    }
    if ( *p_nativeFile != nullptr && valueInteger >= 2 )
    {
      v13 = (idSysThread *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                             size: 0x3Cu,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      v14 = (idSGFwriteThread *)v13;
      if ( v13 != nullptr )
      {
        idSysThread::idSysThread(this: v13);
        v15 = v14;
        v14->__vftable = (idSGFwriteThread_vtbl *)&idSGFwriteThread::`vftable';
      }
      else
      {
        v15 = nullptr;
      }
      this->writeThread = v15;
      v15->sgf = this;
      idSysThread::StartWorkerThread(
        this: this->writeThread,
        name_: "SGF_WriteThread",
        core: CORE_1A,
        priority: THREAD_NORMAL,
        stackSize: 0x20000);
    }
    return (idFile *)1;
  }
  return result;
}


// ========================================================================
// $LN33_12
// EA  : 0x82F1B364
// RVA : 0x00F1B364
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall _LN33_12(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// __unwind$112757
// EA  : 0x82F1B38C
// RVA : 0x00F1B38C
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall _unwind_112757(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// ?NextWriteBlock@idFile_SaveGamePipelined@@QAA_NPAUblockForIO_t@@@Z
// EA  : 0x82F1B3B8
// RVA : 0x00F1B3B8
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

int __fastcall idFile_SaveGamePipelined::NextWriteBlock(idFile_SaveGamePipelined *this, blockForIO_t *block)
{
  idSysSignal *p_blockRequested; // r29
  bool *p_nativeFileEndHit; // r28
  unsigned __int8 *dataIO; // r6

  p_blockRequested = &this->blockRequested;
  p_nativeFileEndHit = &this->nativeFileEndHit;
  Sys_SignalRaise(handle: &this->blockRequested.handle);
  if ( !this->nativeFileEndHit )
  {
    Sys_SignalWait(handle: &this->blockAvailable.handle, timeout: -1);
    if ( !this->finished && block != nullptr )
    {
      dataIO = this->dataIO;
      this->compressedLength += this->bytesIO;
      block->data = dataIO;
      block->bytes = this->bytesIO;
      this->dataIO = nullptr;
      this->bytesIO = 0;
      return 1;
    }
    *p_nativeFileEndHit = true;
    Sys_SignalRaise(handle: &p_blockRequested->handle);
    Sys_SignalRaise(handle: &this->blockFinished.handle);
  }
  return 0;
}


// ========================================================================
// ?FlushCompressedBlock@idFile_SaveGamePipelined@@AAAXXZ
// EA  : 0x82F1B490
// RVA : 0x00F1B490
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall idFile_SaveGamePipelined::FlushCompressedBlock(idFile_SaveGamePipelined *this)
{
  idSGFwriteThread **p_writeThread; // r30
  idSGFwriteThread *writeThread; // r3
  idSysThread *v4; // r3
  unsigned int compressedConsumedBytes; // r5
  unsigned int compressedProducedBytes; // r8
  bool v7; // cr58

  p_writeThread = &this->writeThread;
  writeThread = this->writeThread;
  if ( writeThread != nullptr )
    idSysThread::WaitForThread(this: writeThread);
  if ( this->nativeFile == nullptr && !this->nativeFileEndHit )
    Sys_SignalWait(handle: &this->blockRequested.handle, timeout: -1);
  v4 = *p_writeThread;
  compressedConsumedBytes = this->compressedConsumedBytes;
  compressedProducedBytes = this->compressedProducedBytes;
  v7 = *p_writeThread == nullptr;
  this->bytesIO = compressedProducedBytes - compressedConsumedBytes;
  this->compressedConsumedBytes = compressedProducedBytes;
  this->dataIO = &this->compressed[compressedConsumedBytes & 0x3FFFF];
  if ( v7 )
  {
    if ( this->nativeFile != nullptr )
      idFile_SaveGamePipelined::WriteBlock(this);
    else
      Sys_SignalRaise(handle: &this->blockAvailable.handle);
  }
  else
  {
    idSysThread::SignalWork(this: v4);
  }
}


// ========================================================================
// ?CompressBlock@idFile_SaveGamePipelined@@AAAXXZ
// EA  : 0x82F1B580
// RVA : 0x00F1B580
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall idFile_SaveGamePipelined::CompressBlock(idFile_SaveGamePipelined *this)
{
  z_stream_s *p_zStream; // r18
  unsigned __int8 *dataZlib; // r8
  unsigned int *p_avail_in; // r16
  unsigned int bytesZlib; // r7
  unsigned int v6; // r3
  unsigned int v7; // r25
  unsigned int *p_avail_out; // r24
  unsigned int v9; // r4
  unsigned int v10; // r3
  unsigned int compressedProducedBytes; // r11

  p_zStream = &this->zStream;
  dataZlib = this->dataZlib;
  p_avail_in = &this->zStream.avail_in;
  bytesZlib = this->bytesZlib;
  this->dataZlib = nullptr;
  this->bytesZlib = 0;
  this->zStream.next_in = dataZlib;
  this->zStream.avail_in = bytesZlib;
  while ( *p_avail_in != 0 || this->zLibFlushType == 4 )
  {
    v6 = deflate(strm: p_zStream, flush: this->zLibFlushType);
    v7 = v6;
    if ( v6 > 1 )
    {
      idLib::FatalError(fmt: "idFile_SaveGamePipelined::CompressBlock: deflate() returned %i", v6);
_LN23_4:
      this->zStreamEndHit = true;
      return;
    }
    p_avail_out = &this->zStream.avail_out;
    if ( this->zStream.avail_out == 0 || this->zLibFlushType == 4 )
    {
      if ( sgf_checksums.valueInteger != 0 )
      {
        v9 = 4 * this->numChecksums - this->compressedProducedBytes + this->zStream.total_out;
        v10 = MD5_BlockChecksum(data: &this->zStream.next_out[-v9], length: v9);
        *this->zStream.next_out = v10;
        this->zStream.next_out[1] = BYTE2(v10);
        this->zStream.next_out[2] = BYTE1(v10);
        this->zStream.next_out[3] = HIBYTE(v10);
        ++this->numChecksums;
      }
      this->compressedProducedBytes = 4 * this->numChecksums + this->zStream.total_out;
      idFile_SaveGamePipelined::FlushCompressedBlock(this);
      if ( v7 == 1 )
        goto _LN23_4;
      compressedProducedBytes = this->compressedProducedBytes;
      *p_avail_out = 0x20000;
      this->zStream.next_out = &this->compressed[compressedProducedBytes & 0x3FFFF];
      if ( sgf_checksums.valueInteger != 0 )
        *p_avail_out = 131068;
    }
  }
}


// ========================================================================
// ?FlushUncompressedBlock@idFile_SaveGamePipelined@@AAAXXZ
// EA  : 0x82F1B758
// RVA : 0x00F1B758
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall idFile_SaveGamePipelined::FlushUncompressedBlock(idFile_SaveGamePipelined *this)
{
  idSGFcompressThread **p_compressThread; // r30
  idSGFcompressThread *compressThread; // r3
  idSysThread *v4; // r3
  unsigned int uncompressedConsumedBytes; // r5
  unsigned int uncompressedProducedBytes; // r8
  bool v7; // cr58

  p_compressThread = &this->compressThread;
  compressThread = this->compressThread;
  if ( compressThread != nullptr )
    idSysThread::WaitForThread(this: compressThread);
  v4 = *p_compressThread;
  uncompressedConsumedBytes = this->uncompressedConsumedBytes;
  uncompressedProducedBytes = this->uncompressedProducedBytes;
  v7 = *p_compressThread == nullptr;
  this->bytesZlib = uncompressedProducedBytes - uncompressedConsumedBytes;
  this->uncompressedConsumedBytes = uncompressedProducedBytes;
  this->dataZlib = &this->uncompressed[uncompressedConsumedBytes & 0x7FFFF];
  if ( v7 )
    idFile_SaveGamePipelined::CompressBlock(this);
  else
    idSysThread::SignalWork(this: v4);
}


// ========================================================================
// ?Write@idFile_SaveGamePipelined@@UAAIPBXI@Z
// EA  : 0x82F1B800
// RVA : 0x00F1B800
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

unsigned int __fastcall idFile_SaveGamePipelined::Write(
        idFile_SaveGamePipelined *this,
        char *buffer,
        unsigned int length)
{
  unsigned int v6; // r30
  char *v7; // r27
  unsigned __int8 *uncompressed; // r26
  unsigned int *p_uncompressedProducedBytes; // r28
  size_t v10; // r31
  int v11; // r10
  int v12; // r29
  __int128 v13; // r11

  if ( buffer == nullptr || length == 0 )
    return 0;
  if ( idFile_SaveGamePipelined::cancelToTerminate )
  {
    if ( this->mode != 0 )
      idFile_SaveGamePipelined::Abort(this);
    return 0;
  }
  v6 = length;
  v7 = buffer;
  uncompressed = this->uncompressed;
  p_uncompressedProducedBytes = &this->uncompressedProducedBytes;
  do
  {
    v10 = v6;
    v11 = *p_uncompressedProducedBytes & 0x3FFFF;
    v12 = 0x40000 - v11;
    if ( v6 >= 0x40000 - v11 )
      v10 = 0x40000 - v11;
    memcpy(Dst: &uncompressed[*p_uncompressedProducedBytes & 0x7FFFF], Src: v7, Size: v10);
    v7 += v10;
    v6 -= v10;
    *p_uncompressedProducedBytes += v10;
    if ( v10 == v12 )
      idFile_SaveGamePipelined::FlushUncompressedBlock(this);
  }
  while ( v6 != 0 );
  *(_QWORD *)((char *)&v13 + 4) = this->ioPos;
  LODWORD(v13) = length + DWORD2(v13);
  this->ioPos = v13;
  return length;
}


// ========================================================================
// ?OpenForReading@idFile_SaveGamePipelined@@QAA_NQBD_N@Z
// EA  : 0x82F1B8E8
// RVA : 0x00F1B8E8
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

idFile *__fastcall idFile_SaveGamePipelined::OpenForReading(
        idFile_SaveGamePipelined *this,
        const char *filename,
        bool useNativeFile)
{
  idFile **p_nativeFile; // r25
  idFile *result; // r3
  int v8; // r29
  int valueInteger; // r11
  idSysThread *v10; // r3
  idSGFdecompressThread *v11; // r29
  idSGFdecompressThread *v12; // r11
  idSysThread *v13; // r3
  idSGFreadThread *v14; // r29
  idSGFreadThread *v15; // r11

  idStr::operator=(this: &this->name, text: filename);
  idStr::operator=(this: &this->osPath, text: filename);
  p_nativeFile = &this->nativeFile;
  this->mode = READ;
  this->nativeFile = nullptr;
  this->numChecksums = 0;
  if ( !useNativeFile
    || (result = fileSystem->OpenFileRead(this: fileSystem, a2: filename, a3: 1, a4: 0),
        *p_nativeFile = result,
        result != nullptr) )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    v8 = inflateInit2_(strm: &this->zStream, windowBits: sgf_windowBits.valueInteger, version: "1.2.3", stream_size: 56);
    idMem::PopHeap(this: &mem);
    if ( v8 != 0 )
      idLib::FatalError(fmt: "idFile_SaveGamePipelined::OpenForReading: inflateInit2() error %i", v8);
    valueInteger = sgf_threads.valueInteger;
    if ( sgf_threads.valueInteger >= 1 )
    {
      v10 = (idSysThread *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                             size: 0x3Cu,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      v11 = (idSGFdecompressThread *)v10;
      if ( v10 != nullptr )
      {
        idSysThread::idSysThread(this: v10);
        v12 = v11;
        v11->__vftable = (idSGFdecompressThread_vtbl *)&idSGFdecompressThread::`vftable';
      }
      else
      {
        v12 = nullptr;
      }
      this->decompressThread = v12;
      v12->sgf = this;
      idSysThread::StartWorkerThread(
        this: this->decompressThread,
        name_: "SGF_DecompressThread",
        core: CORE_1B,
        priority: THREAD_NORMAL,
        stackSize: 0x20000);
      valueInteger = sgf_threads.valueInteger;
    }
    if ( *p_nativeFile != nullptr && valueInteger >= 2 )
    {
      v13 = (idSysThread *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                             size: 0x3Cu,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      v14 = (idSGFreadThread *)v13;
      if ( v13 != nullptr )
      {
        idSysThread::idSysThread(this: v13);
        v15 = v14;
        v14->__vftable = (idSGFreadThread_vtbl *)&idSGFreadThread::`vftable';
      }
      else
      {
        v15 = nullptr;
      }
      this->readThread = v15;
      v15->sgf = this;
      idSysThread::StartWorkerThread(
        this: this->readThread,
        name_: "SGF_ReadThread",
        core: CORE_1A,
        priority: THREAD_NORMAL,
        stackSize: 0x20000);
    }
    return (idFile *)1;
  }
  return result;
}


// ========================================================================
// $LN30_5
// EA  : 0x82F1BB04
// RVA : 0x00F1BB04
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall _LN30_5(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// __unwind$112933
// EA  : 0x82F1BB2C
// RVA : 0x00F1BB2C
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall _unwind_112933(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// ?NextReadBlock@idFile_SaveGamePipelined@@QAA_NPAUblockForIO_t@@I@Z
// EA  : 0x82F1BB58
// RVA : 0x00F1BB58
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

int __fastcall idFile_SaveGamePipelined::NextReadBlock(
        idFile_SaveGamePipelined *this,
        blockForIO_t *block,
        unsigned int lastReadBytes)
{
  unsigned int *p_compressedProducedBytes; // r30
  idSysSignal *p_blockAvailable; // r28
  bool *p_nativeFileEndHit; // r27
  int v9; // r11

  p_compressedProducedBytes = &this->compressedProducedBytes;
  p_blockAvailable = &this->blockAvailable;
  this->compressedProducedBytes += lastReadBytes;
  p_nativeFileEndHit = &this->nativeFileEndHit;
  Sys_SignalRaise(handle: &this->blockAvailable.handle);
  if ( !this->nativeFileEndHit )
  {
    Sys_SignalWait(handle: &this->blockRequested.handle, timeout: -1);
    if ( !this->finished && block != nullptr )
    {
      v9 = *p_compressedProducedBytes & 0x3FFFF;
      block->bytes = 0x20000;
      block->data = &this->compressed[v9];
      return 1;
    }
    *p_nativeFileEndHit = true;
    Sys_SignalRaise(handle: &p_blockAvailable->handle);
    Sys_SignalRaise(handle: &this->blockFinished.handle);
  }
  return 0;
}


// ========================================================================
// ?PumpCompressedBlock@idFile_SaveGamePipelined@@AAAXXZ
// EA  : 0x82F1BC28
// RVA : 0x00F1BC28
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall idFile_SaveGamePipelined::PumpCompressedBlock(idFile_SaveGamePipelined *this)
{
  idSGFreadThread **p_readThread; // r30
  idSGFreadThread *readThread; // r3
  idSysThread *v4; // r3
  unsigned int compressedConsumedBytes; // r5
  unsigned int compressedProducedBytes; // r8
  bool v7; // cr58

  p_readThread = &this->readThread;
  readThread = this->readThread;
  if ( readThread != nullptr )
  {
    idSysThread::WaitForThread(this: readThread);
  }
  else if ( this->nativeFile == nullptr && !this->nativeFileEndHit )
  {
    Sys_SignalWait(handle: &this->blockAvailable.handle, timeout: -1);
  }
  v4 = *p_readThread;
  compressedConsumedBytes = this->compressedConsumedBytes;
  compressedProducedBytes = this->compressedProducedBytes;
  v7 = *p_readThread == nullptr;
  this->bytesIO = compressedProducedBytes - compressedConsumedBytes;
  this->compressedConsumedBytes = compressedProducedBytes;
  this->dataIO = &this->compressed[compressedConsumedBytes & 0x3FFFF];
  if ( v7 )
  {
    if ( this->nativeFile != nullptr )
      idFile_SaveGamePipelined::ReadBlock(this);
    else
      Sys_SignalRaise(handle: &this->blockRequested.handle);
  }
  else
  {
    idSysThread::SignalWork(this: v4);
  }
}


// ========================================================================
// ?DecompressBlock@idFile_SaveGamePipelined@@AAAXXZ
// EA  : 0x82F1BD20
// RVA : 0x00F1BD20
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall idFile_SaveGamePipelined::DecompressBlock(idFile_SaveGamePipelined *this)
{
  bool *p_zStreamEndHit; // r16
  unsigned int *p_uncompressedProducedBytes; // r19
  unsigned int *p_avail_out; // r17
  char *v5; // r11
  unsigned int *p_avail_in; // r28
  unsigned int *p_bytesIO; // r29
  unsigned __int8 *dataIO; // r10
  z_stream_s *p_zStream; // r30
  unsigned __int8 *next_in; // r3
  unsigned int v11; // r4
  unsigned int v12; // r3
  unsigned __int8 *v13; // r11
  int v14; // r3

  p_zStreamEndHit = &this->zStreamEndHit;
  if ( !this->zStreamEndHit )
  {
    p_uncompressedProducedBytes = &this->uncompressedProducedBytes;
    p_avail_out = &this->zStream.avail_out;
    v5 = (char *)this + (this->uncompressedProducedBytes & 0x7FFFF);
    this->zStream.avail_out = 0x40000;
    this->zStream.next_out = (unsigned __int8 *)(v5 + 88);
    p_avail_in = &this->zStream.avail_in;
    while ( 1 )
    {
      if ( *p_avail_in == 0 )
      {
        p_bytesIO = &this->bytesIO;
        while ( 1 )
        {
          idFile_SaveGamePipelined::PumpCompressedBlock(this);
          if ( *p_bytesIO != 0 )
            break;
          if ( this->nativeFileEndHit )
            goto LABEL_7;
        }
        dataIO = this->dataIO;
        p_zStream = &this->zStream;
        *p_avail_in = *p_bytesIO;
        this->dataIO = nullptr;
        *p_bytesIO = 0;
        this->zStream.next_in = dataIO;
        if ( sgf_checksums.valueInteger != 0 )
        {
          if ( sgf_testCorruption.valueInteger == this->numChecksums )
            *p_zStream->next_in = ~*p_zStream->next_in;
          next_in = p_zStream->next_in;
          v11 = *p_avail_in - 4;
          *p_avail_in = v11;
          v12 = MD5_BlockChecksum(data: next_in, length: v11);
          v13 = &p_zStream->next_in[*p_avail_in];
          if ( *v13 != (unsigned __int8)v12
            || __PAIR64__(v13[1], v13[2]) != __PAIR64__(BYTE2(v12), BYTE1(v12))
            || v13[3] != HIBYTE(v12) )
          {
LABEL_7:
            *p_zStreamEndHit = true;
            return;
          }
          ++this->numChecksums;
        }
      }
      v14 = inflate(strm: &this->zStream, flush: 2);
      *p_uncompressedProducedBytes = this->zStream.total_out;
      if ( v14 == 1 )
        goto LABEL_7;
      if ( v14 != 0 )
        break;
      if ( *p_avail_out == 0 )
        return;
    }
    idLib::Warning(fmt: "idFile_SaveGamePipelined::DecompressBlock: inflate() returned %i", v14);
    *p_zStreamEndHit = true;
  }
}


// ========================================================================
// ?Read@idFile_SaveGamePipelined@@UAAIPAXI@Z
// EA  : 0x82F1BF10
// RVA : 0x00F1BF10
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

int __fastcall idFile_SaveGamePipelined::Read(idFile_SaveGamePipelined *this, char *buffer, unsigned int length)
{
  int v4; // r21
  unsigned int v5; // r23
  char *v6; // r22
  unsigned int *p_bytesZlib; // r28
  size_t v8; // r31
  unsigned int *p_uncompressedProducedBytes; // r25
  unsigned int *p_uncompressedConsumedBytes; // r29
  idSysThread **p_decompressThread; // r27
  unsigned int v12; // r9
  idSysThread *v13; // r3
  char *v14; // r11
  __int64 ioPos; // r10
  __int64 v16; // r8
  unsigned int v17; // r6

  if ( buffer == nullptr || length == 0 )
    return 0;
  v4 = 0;
  v5 = length;
  v6 = buffer;
  p_bytesZlib = &this->bytesZlib;
  while ( 1 )
  {
    v8 = *p_bytesZlib;
    if ( *p_bytesZlib == 0 )
      break;
LABEL_14:
    if ( v5 < v8 )
      v8 = v5;
    memcpy(Dst: v6, Src: this->dataZlib, Size: v8);
    ioPos = this->ioPos;
    HIDWORD(v16) = *p_bytesZlib;
    LODWORD(v16) = v8 + ioPos;
    v17 = *p_bytesZlib - v8;
    this->dataZlib = (unsigned __int8 *)(HIDWORD(ioPos) + v8);
    v5 -= v8;
    this->ioPos = v16;
    v6 += v8;
    *p_bytesZlib = v17;
    v4 += v8;
    if ( v5 == 0 )
      return v4;
  }
  p_uncompressedProducedBytes = &this->uncompressedProducedBytes;
  p_uncompressedConsumedBytes = &this->uncompressedConsumedBytes;
  p_decompressThread = &this->decompressThread;
  while ( 1 )
  {
    if ( *p_decompressThread != nullptr )
      idSysThread::WaitForThread(this: *p_decompressThread);
    v12 = *p_uncompressedProducedBytes;
    v13 = *p_decompressThread;
    v14 = (char *)this + (*p_uncompressedConsumedBytes & 0x7FFFF);
    *p_bytesZlib = *p_uncompressedProducedBytes - *p_uncompressedConsumedBytes;
    *p_uncompressedConsumedBytes = v12;
    this->dataZlib = (unsigned __int8 *)(v14 + 88);
    if ( v13 != nullptr )
      idSysThread::SignalWork(this: v13);
    else
      idFile_SaveGamePipelined::DecompressBlock(this);
    v8 = *p_bytesZlib;
    if ( *p_bytesZlib == 0 && this->zStreamEndHit )
      return v4;
    if ( *p_bytesZlib != 0 )
      goto LABEL_14;
  }
}


// ========================================================================
// ?TestCompressionSpeeds_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F1C070
// RVA : 0x00F1C070
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall TestCompressionSpeeds_f(const idCmdArgs *args)
{
  __int64 v1; // r26
  int v2; // r28
  int v3; // r27
  idCompressor_LZW *v4; // r30
  idFile_Memory *v5; // r3
  idFile_Memory *v6; // r29
  __int64 v7; // r6
  const void *v8; // [sp+50h] [-50h] BYREF
  __int64 v9; // [sp+58h] [-48h]

  idLib::Printf(fmt: "Processing %s:\n", "-colorMap.tga");
  v2 = fileSystem->ReadFile(this: fileSystem, a2: "-colorMap.tga", a3: (void **)&v8, a4: nullptr);
  v3 = Sys_Microseconds() >> 32;
  v4 = idCompressor::AllocLZW();
  v5 = (idFile_Memory *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x14Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  HIDWORD(v9) = v5;
  if ( v5 != nullptr )
    v6 = idFile_Memory::idFile_Memory(this: v5, name: "junk/lzwTest.bin");
  else
    v6 = nullptr;
  v4->Init(this: v4, a2: v6, a3: true, a4: 8);
  v4->Write(this: v4, a2: v8, a3: v2);
  LODWORD(v1) = v6->Tell(this: v6);
  ((void (__fastcall *)(idCompressor_LZW *, int))v4->dtr_idFile)(a1: v4, a2: 1);
  ((void (__fastcall *)(idFile_Memory *, int))v6->dtr_idFile)(a1: v6, a2: 1);
  LODWORD(v7) = (Sys_Microseconds() >> 32) - v3;
  v9 = v7;
  idLib::Printf(
    fmt: "%i microseconds to compress %i bytes to %i written bytes = %4.1f MB/s\n",
    (_DWORD)v7,
    v2,
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v1 / (float)v7))),
    (float)((float)v1 / (float)v7));
}


// ========================================================================
// __unwind$113111
// EA  : 0x82F1C200
// RVA : 0x00F1C200
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall _unwind_113111(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 88), tag: a2);
}


// ========================================================================
// ?Run@idSGFcompressThread@@UAAHXZ
// EA  : 0x82F1C2C8
// RVA : 0x00F1C2C8
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

int __fastcall idSGFcompressThread::Run(idSGFcompressThread *this)
{
  idFile_SaveGamePipelined::CompressBlock(this: this->sgf);
  return 0;
}


// ========================================================================
// ?Run@idSGFdecompressThread@@UAAHXZ
// EA  : 0x82F1C2F0
// RVA : 0x00F1C2F0
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

int __fastcall idSGFdecompressThread::Run(idSGFdecompressThread *this)
{
  idFile_SaveGamePipelined::DecompressBlock(this: this->sgf);
  return 0;
}


// ========================================================================
// ??0idFile_SaveGamePipelined@@QAA@XZ
// EA  : 0x82F1C320
// RVA : 0x00F1C320
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

idFile_SaveGamePipelined *__fastcall idFile_SaveGamePipelined::idFile_SaveGamePipelined(idFile_SaveGamePipelined *this)
{
  __int64 v1; // r29
  __int64 v3; // r29
  int v4; // ctr
  unsigned __int8 **p_dataIO; // r10

  idFile::idFile(this);
  LODWORD(v1) = 0;
  this->ioPos = v1;
  this->__vftable = (idFile_SaveGamePipelined_vtbl *)&idFile_SaveGamePipelined::`vftable';
  this->name.allocedAndFlag = 20;
  this->name.data = this->name.baseBuffer;
  this->name.len = 0;
  this->name.baseBuffer[0] = 0;
  this->osPath.allocedAndFlag = 20;
  this->osPath.len = 0;
  this->osPath.data = this->osPath.baseBuffer;
  this->osPath.baseBuffer[0] = 0;
  this->mode = 0;
  this->compressedLength = 0;
  this->uncompressedProducedBytes = 0;
  this->uncompressedConsumedBytes = 0;
  this->compressedProducedBytes = 0;
  this->compressedConsumedBytes = 0;
  HIDWORD(v3) = 786432;
  this->dataZlib = nullptr;
  this->bytesZlib = 0;
  this->dataIO = nullptr;
  this->bytesIO = 0;
  this->zLibFlushType = 0;
  this->zStreamEndHit = false;
  this->numChecksums = 0;
  this->nativeFile = nullptr;
  this->nativeFileEndHit = false;
  this->finished = false;
  this->readThread = nullptr;
  this->writeThread = nullptr;
  this->decompressThread = nullptr;
  this->compressThread = nullptr;
  Sys_SignalCreate(handle: &this->blockRequested.handle, manualReset: false);
  Sys_SignalCreate(handle: &this->blockAvailable.handle, manualReset: false);
  Sys_SignalCreate(handle: &this->blockFinished.handle, manualReset: true);
  idStrStatic<32>::idStrStatic<32>(this: &this->buildVersion, text: &byte_8200D768);
  v4 = 7;
  p_dataIO = &this->dataIO;
  this->saveFormatVersion = 0;
  do
  {
    p_dataIO += 2;
    *(_QWORD *)p_dataIO = v3;
    --v4;
  }
  while ( v4 != 0 );
  memset(Dst: this->compressed, Val: 0, Size: sizeof(this->compressed));
  memset(Dst: this->uncompressed, Val: 0, Size: sizeof(this->uncompressed));
  this->zStream.zalloc = ZlibAlloc;
  this->zStream.zfree = ZlibFree;
  return this;
}


// ========================================================================
// __unwind$113270
// EA  : 0x82F1C528
// RVA : 0x00F1C528
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void _unwind_113270()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 192 + 212));
}


// ========================================================================
// __unwind$113271
// EA  : 0x82F1C550
// RVA : 0x00F1C550
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void _unwind_113271()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 16));
}


// ========================================================================
// __unwind$113272
// EA  : 0x82F1C57C
// RVA : 0x00F1C57C
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void _unwind_113272()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 48));
}


// ========================================================================
// __unwind$113273
// EA  : 0x82F1C5A8
// RVA : 0x00F1C5A8
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void _unwind_113273()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 192 + 212) + 786644));
}


// ========================================================================
// __unwind$113274
// EA  : 0x82F1C5DC
// RVA : 0x00F1C5DC
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void _unwind_113274()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 192 + 212) + 786648));
}


// ========================================================================
// __unwind$113275
// EA  : 0x82F1C610
// RVA : 0x00F1C610
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void _unwind_113275()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 192 + 212) + 786652));
}


// ========================================================================
// ?Finish@idFile_SaveGamePipelined@@QAAXXZ
// EA  : 0x82F1C650
// RVA : 0x00F1C650
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall idFile_SaveGamePipelined::Finish(idFile_SaveGamePipelined *this)
{
  idFile_SaveGamePipelined::mode_t mode; // r11
  idSysThread **p_compressThread; // r30
  idSGFcompressThread *compressThread; // r3
  idSGFwriteThread *writeThread; // r3
  idSGFdecompressThread *decompressThread; // r3
  idSGFreadThread *readThread; // r3

  mode = this->mode;
  if ( mode == WRITE )
  {
    p_compressThread = &this->compressThread;
    compressThread = this->compressThread;
    if ( compressThread != nullptr )
      idSysThread::WaitForThread(this: compressThread);
    this->zLibFlushType = 4;
    idFile_SaveGamePipelined::FlushUncompressedBlock(this);
    if ( *p_compressThread != nullptr )
      idSysThread::WaitForThread(this: *p_compressThread);
    writeThread = this->writeThread;
    if ( writeThread != nullptr )
    {
      idSysThread::WaitForThread(this: writeThread);
      deflateEnd(strm: &this->zStream);
    }
    else
    {
      if ( this->nativeFile == nullptr && !this->nativeFileEndHit )
      {
        Sys_SignalWait(handle: &this->blockRequested.handle, timeout: -1);
        this->finished = true;
        Sys_SignalRaise(handle: &this->blockAvailable.handle);
        Sys_SignalWait(handle: &this->blockFinished.handle, timeout: -1);
      }
      deflateEnd(strm: &this->zStream);
    }
  }
  else if ( mode == READ )
  {
    decompressThread = this->decompressThread;
    if ( decompressThread != nullptr )
      idSysThread::WaitForThread(this: decompressThread);
    readThread = this->readThread;
    if ( readThread != nullptr )
    {
      idSysThread::WaitForThread(this: readThread);
    }
    else if ( this->nativeFile == nullptr && !this->nativeFileEndHit )
    {
      Sys_SignalWait(handle: &this->blockAvailable.handle, timeout: -1);
      this->finished = true;
      Sys_SignalRaise(handle: &this->blockRequested.handle);
      Sys_SignalWait(handle: &this->blockFinished.handle, timeout: -1);
    }
    inflateEnd(strm: &this->zStream);
  }
  this->mode = 0;
}


// ========================================================================
// TestProcessFile
// EA  : 0x82F1C828
// RVA : 0x00F1C828
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall TestProcessFile(const char *filename)
{
  __int64 v1; // r30
  idFile_SaveGamePipelined *v2; // r3
  int v3; // r24
  unsigned __int64 v4; // r4
  double v5; // fp1
  __int128 v6; // r7
  int v7; // r8
  _BYTE *v8; // r24
  int v9; // r26
  idFile_SaveGamePipelined *v10; // r3
  unsigned __int64 v11; // r4
  __int64 v12; // r7
  double v13; // fp1
  __int64 v14; // r6
  int v15; // r4
  unsigned __int8 *v16; // r11
  double v17; // [sp+20h] [-90h]
  unsigned __int8 *v18; // [sp+50h] [-60h] BYREF
  __int64 v19; // [sp+58h] [-58h]

  LODWORD(v1) = filename;
  idLib::Printf(fmt: "Processing %s:\n", filename);
  HIDWORD(v1) = fileSystem->ReadFile(this: fileSystem, a2: (const char *)v1, a3: (void **)&v18, a4: nullptr);
  v2 = (idFile_SaveGamePipelined *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                     size: 0xC0128u,
                                     tag: TAG_NEW,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  HIDWORD(v19) = v2;
  if ( v2 != nullptr )
    LODWORD(v1) = idFile_SaveGamePipelined::idFile_SaveGamePipelined(this: v2);
  else
    LODWORD(v1) = 0;
  idFile_SaveGamePipelined::OpenForWriting(
    this: (idFile_SaveGamePipelined *)v1,
    filename: "junk/savegameTest.bin",
    useNativeFile: true);
  v3 = Sys_Microseconds() >> 32;
  (*(void (__fastcall **)(_DWORD, unsigned __int8 *, _DWORD))(*(_DWORD *)v1 + 16))(a1: v1, a2: v18, a3: HIDWORD(v1));
  (**(void (__fastcall ***)(_DWORD, int))v1)(a1: v1, a2: 1);
  LODWORD(v1) = fileSystem->GetFileLength(this: fileSystem, a2: "junk/savegameTest.bin");
  v4 = Sys_Microseconds();
  v19 = v1;
  v5 = _u64tod(a1: HIDWORD(v4) - v3, a2: v4);
  DWORD1(v6) = HIDWORD(v1);
  *((double *)&v6 + 1) = (float)((float)v19 / (float)v5);
  idLib::Printf(
    fmt: "%lld microseconds to compress %i bytes to %i written bytes = %4.1f MB/s\n",
    *(_QWORD *)((char *)&v6 + 4),
    (_DWORD)v6,
    v7,
    *((double *)&v6 + 1));
  v8 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\filesystem\\File_SaveGame.cpp(962) : TAG_SAVEGAMES",
         size: HIDWORD(v1),
         tag: TAG_SAVEGAMES,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  v9 = Sys_Microseconds() >> 32;
  v10 = (idFile_SaveGamePipelined *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                      size: 0xC0128u,
                                      tag: TAG_NEW,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  HIDWORD(v19) = v10;
  if ( v10 != nullptr )
    LODWORD(v1) = idFile_SaveGamePipelined::idFile_SaveGamePipelined(this: v10);
  else
    LODWORD(v1) = 0;
  idFile_SaveGamePipelined::OpenForReading(
    this: (idFile_SaveGamePipelined *)v1,
    filename: "junk/savegameTest.bin",
    useNativeFile: true);
  (*(void (__fastcall **)(_DWORD, _BYTE *, _DWORD))(*(_DWORD *)v1 + 12))(a1: v1, a2: v8, a3: HIDWORD(v1));
  (**(void (__fastcall ***)(_DWORD, int))v1)(a1: v1, a2: 1);
  v11 = Sys_Microseconds();
  LODWORD(v12) = HIDWORD(v1);
  v19 = v12;
  v13 = _u64tod(a1: HIDWORD(v11) - v9, a2: v11);
  LODWORD(v14) = &unk_82380000;
  v17 = (float)((float)v19 / (float)v13);
  HIDWORD(v14) = LODWORD(v17);
  idLib::Printf(fmt: "%lld microseconds to decompress = %4.1f MB/s\n", v14, v17);
  v15 = 0;
  if ( SHIDWORD(v1) > 0 )
  {
    v16 = v18;
    do
    {
      if ( v16[v8 - v18] != *v16 )
        break;
      ++v15;
      ++v16;
    }
    while ( v15 < SHIDWORD(v1) );
  }
  if ( v15 == HIDWORD(v1) )
    idLib::Printf(fmt: "Compare succeeded.\n");
  else
    idLib::Printf(fmt: "Compare failed at %i.\n", v15);
  idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: v18, align: ALIGN_16);
}


// ========================================================================
// __unwind$113490
// EA  : 0x82F1CAF8
// RVA : 0x00F1CAF8
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall _unwind_113490(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 176 + 88), tag: a2);
}


// ========================================================================
// __unwind$113491
// EA  : 0x82F1CB20
// RVA : 0x00F1CB20
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall _unwind_113491(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 176 + 88), tag: a2);
}


// ========================================================================
// ?TestSaveGameFile_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F1CB48
// RVA : 0x00F1CB48
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall TestSaveGameFile_f(const idCmdArgs *args)
{
  TestProcessFile(filename: "maps/game/wasteland1/wasteland1.map");
}


// ========================================================================
// ??1idFile_SaveGamePipelined@@UAA@XZ
// EA  : 0x82F1CB60
// RVA : 0x00F1CB60
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __fastcall idFile_SaveGamePipelined::~idFile_SaveGamePipelined(idFile_SaveGamePipelined *this)
{
  idSGFcompressThread *compressThread; // r3
  idSGFdecompressThread *decompressThread; // r3
  idSGFreadThread *readThread; // r3
  idSGFwriteThread *writeThread; // r3
  idFile *nativeFile; // r3

  this->__vftable = (idFile_SaveGamePipelined_vtbl *)&idFile_SaveGamePipelined::`vftable';
  idFile_SaveGamePipelined::Finish(this);
  compressThread = this->compressThread;
  if ( compressThread != nullptr )
  {
    ((void (__fastcall *)(idSGFcompressThread *, int))compressThread->dtr_idSysThread)(a1: compressThread, a2: 1);
    this->compressThread = nullptr;
  }
  decompressThread = this->decompressThread;
  if ( decompressThread != nullptr )
  {
    ((void (__fastcall *)(idSGFdecompressThread *, int))decompressThread->dtr_idSysThread)(a1: decompressThread, a2: 1);
    this->decompressThread = nullptr;
  }
  readThread = this->readThread;
  if ( readThread != nullptr )
  {
    ((void (__fastcall *)(idSGFreadThread *, int))readThread->dtr_idSysThread)(a1: readThread, a2: 1);
    this->readThread = nullptr;
  }
  writeThread = this->writeThread;
  if ( writeThread != nullptr )
  {
    ((void (__fastcall *)(idSGFwriteThread *, int))writeThread->dtr_idSysThread)(a1: writeThread, a2: 1);
    this->writeThread = nullptr;
  }
  nativeFile = this->nativeFile;
  if ( nativeFile != nullptr )
  {
    ((void (__fastcall *)(idFile *, int))nativeFile->dtr_idFile)(a1: nativeFile, a2: 1);
    this->nativeFile = nullptr;
  }
  this->dataZlib = nullptr;
  this->dataIO = nullptr;
  idStr::FreeData(this: &this->buildVersion);
  Sys_SignalDestroy(handle: &this->blockFinished.handle);
  Sys_SignalDestroy(handle: &this->blockAvailable.handle);
  Sys_SignalDestroy(handle: &this->blockRequested.handle);
  idStr::FreeData(this: &this->osPath);
  idStr::FreeData(this: &this->name);
  this->__vftable = (idFile_SaveGamePipelined_vtbl *)&idFile::`vftable';
}


// ========================================================================
// __unwind$113547
// EA  : 0x82F1CCE8
// RVA : 0x00F1CCE8
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void _unwind_113547()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$113548
// EA  : 0x82F1CD10
// RVA : 0x00F1CD10
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void _unwind_113548()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$113549
// EA  : 0x82F1CD3C
// RVA : 0x00F1CD3C
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void _unwind_113549()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 48));
}


// ========================================================================
// __unwind$113550
// EA  : 0x82F1CD68
// RVA : 0x00F1CD68
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void _unwind_113550()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 128 + 148) + 786644));
}


// ========================================================================
// __unwind$113551
// EA  : 0x82F1CD9C
// RVA : 0x00F1CD9C
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void _unwind_113551()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 128 + 148) + 786648));
}


// ========================================================================
// __unwind$113552
// EA  : 0x82F1CDD0
// RVA : 0x00F1CDD0
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void _unwind_113552()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 128 + 148) + 786652));
}


// ========================================================================
// __unwind$113553
// EA  : 0x82F1CE04
// RVA : 0x00F1CE04
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void _unwind_113553()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 786656));
}


// ========================================================================
// `dynamic initializer for 'sgf_threads''
// EA  : 0x83395278
// RVA : 0x01395278
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__sgf_threads__()
{
  idCVar::idCVar(
    this: &sgf_threads,
    name: "sgf_threads",
    value: "2",
    flags: 2,
    description: "0 = all foreground, 1 = background write, 2 = background write + compress",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__sgf_threads__);
}


// ========================================================================
// `dynamic initializer for 'sgf_checksums''
// EA  : 0x833952D0
// RVA : 0x013952D0
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__sgf_checksums__()
{
  idCVar::idCVar(
    this: &sgf_checksums,
    name: "sgf_checksums",
    value: "1",
    flags: 1,
    description: "enable save game file checksums",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__sgf_checksums__);
}


// ========================================================================
// `dynamic initializer for 'sgf_testCorruption''
// EA  : 0x83395328
// RVA : 0x01395328
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__sgf_testCorruption__()
{
  idCVar::idCVar(
    this: &sgf_testCorruption,
    name: "sgf_testCorruption",
    value: "-1",
    flags: 2,
    description: "test corruption at the 128 kB compressed block",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__sgf_testCorruption__);
}


// ========================================================================
// `dynamic initializer for 'sgf_windowBits''
// EA  : 0x83395380
// RVA : 0x01395380
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__sgf_windowBits__()
{
  idCVar::idCVar(
    this: &sgf_windowBits,
    name: "sgf_windowBits",
    value: "-15",
    flags: 2,
    description: "zlib window bits",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__sgf_windowBits__);
}


// ========================================================================
// `dynamic initializer for 'TestSaveGameFile_v''
// EA  : 0x833953D8
// RVA : 0x013953D8
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestSaveGameFile_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestSaveGameFile_v,
           cmdName: "TestSaveGameFile",
           function: TestSaveGameFile_f,
           description: "Exercises the pipelined savegame code",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestCompressionSpeeds_v''
// EA  : 0x83395400
// RVA : 0x01395400
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestCompressionSpeeds_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestCompressionSpeeds_v,
           cmdName: "TestCompressionSpeeds",
           function: TestCompressionSpeeds_f,
           description: "Compares zlib and our code",
           argCompletion: nullptr);
}

