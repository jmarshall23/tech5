
// ========================================================================
// ?CommitPage@idMemoryMappedFile@@QAAXH@Z
// EA  : 0x8267A770
// RVA : 0x0067A770
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

void __fastcall idMemoryMappedFile::CommitPage(idMemoryMappedFile *this, int pageNum)
{
  idMemoryMappedFile::mmPage_t *v4; // r31
  unsigned __int8 *v5; // r28
  __int128 v6; // r7
  __int64 v7; // r11
  int v8; // r28
  int v9; // r4
  idMemoryMappedFile *v10; // r3

  v4 = &this->pages.buffer[pageNum];
  if ( v4->state != PGST_FULL )
  {
    v5 = &this->virtualBase[0x10000 * pageNum];
    if ( VirtualAlloc(lpAddress: v5, dwSize: 0x10000u, flAllocationType: 0x20001000u, flProtect: 4u) != nullptr )
    {
LABEL_5:
      AddTagStats(tag: 55, actualSize: 0x10000, dwSize: 0x10000, heap: 0);
      v4->state = PGST_READING;
      LODWORD(v6) = pageNum;
      v4->dest = v5;
      v7 = (_QWORD)v6 << 16;
      v4->completion = false;
      v8 = __PAIR64__(v6, v6) >> 16;
      DWORD2(v6) = 0x10000;
      DWORD1(v6) = v8;
      idStreamFileCache::UncachedBackgroundRead(
        this: streamFileCache,
        cacheFile: this->file,
        ofs: *(__int64 *)((char *)&v6 + 4),
        length: (int)v4,
        dest: (void **)0x30,
        tag: (memTag_t)&v4->completion,
        completionFlag: (volatile bool *)HIDWORD(v7));
      if ( mmf_debug.valueInteger != 0 )
        idLib::Printf(
          fmt: "idMemoryMappedFile: CommitPage( %i ), UncachedBackgroundRead( file 0x%08x -> mem 0x%08x )\n",
          pageNum,
          v8,
          v4->dest);
    }
    else
    {
      while ( idStreamFileCache::OutOfMemoryCallback(this: streamFileCache) )
      {
        if ( VirtualAlloc(lpAddress: v5, dwSize: 0x10000u, flAllocationType: 0x20001000u, flProtect: 4u) != nullptr )
          goto LABEL_5;
      }
      idLib::FatalError(fmt: "idMemoryMappedFile::CommitBlock: streamFileCache couldn't free more memory");
      idMemoryMappedFile::DecommitPage(this: v10, pageNum: v9);
    }
  }
}


// ========================================================================
// ?DecommitPage@idMemoryMappedFile@@QAAXH@Z
// EA  : 0x8267A8A0
// RVA : 0x0067A8A0
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

void __fastcall idMemoryMappedFile::DecommitPage(idMemoryMappedFile *this, int pageNum)
{
  int v4; // r30
  idMemoryMappedFile::pageState_t state; // r11

  if ( mmf_debug.valueInteger != 0 )
    idLib::Printf(fmt: "idMemoryMappedFile: DecommitPage( %i )\n", pageNum);
  v4 = pageNum;
  state = this->pages.buffer[pageNum].state;
  if ( state != PGST_UNCOMITTED )
  {
    if ( state == PGST_READING )
    {
      do
        mgthread_sleep(ms: 1);
      while ( this->pages.buffer[v4].state == PGST_READING );
    }
    if ( VirtualFree(lpAddress: &this->virtualBase[0x10000 * pageNum], dwSize: 0x10000u, dwFreeType: 0x4000u) == 0 )
      idLib::FatalError(fmt: "VirtualFree MEM_DECOMMIT failed");
    SubtractTagStats(tag: 55, actualSize: 0x10000, dwSize: 0x10000, heap: 0);
    this->pages.buffer[v4].state = PGST_UNCOMITTED;
  }
}


// ========================================================================
// ??1idMemoryMappedFile@@QAA@XZ
// EA  : 0x8267A978
// RVA : 0x0067A978
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

void __fastcall idMemoryMappedFile::~idMemoryMappedFile(idMemoryMappedFile *this)
{
  unsigned int v2; // r29
  int v3; // r28
  idMemoryMappedFile::mmPage_t *buffer; // r4

  v2 = 0;
  if ( this->pages.num != 0 )
  {
    v3 = 0;
    do
    {
      if ( this->pages.buffer[v3].state == PGST_FULL )
        idMemoryMappedFile::DecommitPage(this, pageNum: v2);
      ++v2;
      ++v3;
    }
    while ( v2 < this->pages.num );
  }
  VirtualFree(lpAddress: this->virtualBase, dwSize: 0, dwFreeType: 0x8000u);
  currentMemoryMappedFile = nullptr;
  buffer = this->pages.buffer;
  if ( buffer != nullptr )
    idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
}


// ========================================================================
// __unwind$219869
// EA  : 0x8267AA24
// RVA : 0x0067AA24
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

void _unwind_219869()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(*(_DWORD *)(v0 - 128 + 148) + 28));
}


// ========================================================================
// ?Print@idMemoryMappedFile@@QAAXXZ
// EA  : 0x8267AA50
// RVA : 0x0067AA50
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

void __fastcall idMemoryMappedFile::Print(idMemoryMappedFile *this)
{
  int v1; // r30
  int v2; // r29
  int v3; // r11
  unsigned int num; // ctr
  idMemoryMappedFile::mmPage_t *buffer; // r10
  idMemoryMappedFile::pageState_t state; // r10
  __int128 v7; // r28
  const char *v8; // r3
  __int64 v9; // r5

  v1 = 0;
  v2 = 0;
  if ( this->pages.num != 0 )
  {
    v3 = 0;
    num = this->pages.num;
    buffer = this->pages.buffer;
    do
    {
      state = buffer->state;
      if ( state != PGST_UNCOMITTED )
      {
        ++v1;
        if ( state == PGST_READING )
          ++v2;
      }
      buffer = &this->pages.buffer[++v3];
      --num;
    }
    while ( num != 0 );
  }
  *((_QWORD *)&v7 + 1) = this->alignedLength;
  *(_QWORD *)((char *)&v7 + 4) = this->alignedFileOffset;
  v8 = (const char *)((int (*)(void))this->file->GetName)();
  idLib::Printf(fmt: "%s 0x%08x:0x%08x\n", v8, DWORD2(v7), (_DWORD)v7);
  LODWORD(v9) = v1 << 16;
  HIDWORD(v9) = &unk_821D0000;
  idLib::Printf(
    fmt: "%i reading / %i committed / %i reserved pages (%5.1f MB committed)\n",
    v2,
    v1,
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v9 * (float)0.00000095367432))),
    (float)((float)v9 * (float)0.00000095367432));
}


// ========================================================================
// ?IsBlockFullyCommitted@idMemoryMappedFile@@QAA_N_J0@Z
// EA  : 0x8267AB30
// RVA : 0x0067AB30
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idMemoryMappedFile::IsBlockFullyCommitted(
        idMemoryMappedFile *this,
        int a2,
        const __int64 fileOffset,
        const __int64 length,
        __int64 a5)
{
  int v5; // r11
  int v6; // r8
  char *v7; // r11

  v5 = a2 - LODWORD(this->alignedFileOffset);
  LODWORD(a5) = v5 + HIDWORD(fileOffset) - 1;
  v6 = a5 >> 16;
  LODWORD(a5) = *(__int64 *)((char *)&a5 - 4) >> 16;
  if ( (int)a5 > v6 )
    return 1;
  HIDWORD(a5) = 12 * a5;
  while ( 1 )
  {
    v7 = (char *)this->pages.buffer + HIDWORD(a5);
    if ( *((_DWORD *)v7 + 2) == 1 && v7[4] != 0 )
      *((_DWORD *)v7 + 2) = 2;
    if ( *((_DWORD *)v7 + 2) != 2 )
      break;
    LODWORD(a5) = a5 + 1;
    HIDWORD(a5) += 12;
    if ( (int)a5 > v6 )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?CommitBlock@idMemoryMappedFile@@QAAX_J0@Z
// EA  : 0x8267ABB8
// RVA : 0x0067ABB8
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMemoryMappedFile::CommitBlock(
        idMemoryMappedFile *this,
        int a2,
        const __int64 fileOffset,
        const __int64 length,
        __int64 a5)
{
  int v7; // r30
  int v8; // r11
  int v9; // r20
  int v10; // r29
  int v11; // r24
  int v12; // r22
  idMemoryMappedFile::mmPage_t *v13; // r31
  unsigned __int8 *v14; // r30
  __int128 v15; // r11
  int v16; // r30
  __int64 v17; // r6

  v7 = HIDWORD(fileOffset);
  if ( mmf_debug.valueInteger != 0 )
    idLib::Printf(fmt: "idMemoryMappedFile: CommitBlock( file 0x%08x - 0x%08x )\n", a2, HIDWORD(fileOffset) + a2);
  v8 = a2 - LODWORD(this->alignedFileOffset);
  LODWORD(a5) = v8 + v7 - 1;
  v9 = a5 >> 16;
  v10 = *(__int64 *)((char *)&a5 - 4) >> 16;
  if ( v10 <= v9 )
  {
    v11 = v10 << 16;
    v12 = v10;
    do
    {
      v13 = &this->pages.buffer[v12];
      if ( v13->state != PGST_FULL )
      {
        v14 = &this->virtualBase[v11];
        while ( VirtualAlloc(lpAddress: v14, dwSize: 0x10000u, flAllocationType: 0x20001000u, flProtect: 4u) == nullptr )
        {
          if ( !idStreamFileCache::OutOfMemoryCallback(this: streamFileCache) )
          {
            idLib::FatalError(fmt: "idMemoryMappedFile::CommitBlock: streamFileCache couldn't free more memory");
            JUMPOUT(0x8267AD5C);
          }
        }
        AddTagStats(tag: 55, actualSize: 0x10000, dwSize: 0x10000, heap: 0);
        v13->state = PGST_READING;
        *(_QWORD *)((char *)&v15 + 4) = this->alignedFileOffset;
        LODWORD(v15) = v10;
        v13->dest = v14;
        v13->completion = false;
        *((_QWORD *)&v15 + 1) = (_QWORD)v15 << 16;
        v16 = v15 + DWORD2(v15);
        LODWORD(v17) = 0x10000;
        HIDWORD(v17) = v15 + DWORD2(v15);
        idStreamFileCache::UncachedBackgroundRead(
          this: streamFileCache,
          cacheFile: this->file,
          ofs: v17,
          length: (int)v13,
          dest: (void **)0x30,
          tag: (memTag_t)&v13->completion,
          completionFlag: (volatile bool *)DWORD2(v15));
        if ( mmf_debug.valueInteger != 0 )
          idLib::Printf(
            fmt: "idMemoryMappedFile: CommitPage( %i ), UncachedBackgroundRead( file 0x%08x -> mem 0x%08x )\n",
            v10,
            v16,
            v13->dest);
      }
      ++v10;
      ++v12;
      v11 += 0x10000;
    }
    while ( v10 <= v9 );
  }
  idStreamFileCache::SignalWork(this: streamFileCache);
}


// ========================================================================
// ?DecommitBlock@idMemoryMappedFile@@QAAX_J0@Z
// EA  : 0x8267AD60
// RVA : 0x0067AD60
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMemoryMappedFile::DecommitBlock(
        idMemoryMappedFile *this,
        int a2,
        const __int64 fileOffset,
        const __int64 length,
        __int64 a5)
{
  int v6; // r11
  int v7; // r27
  int v8; // r29
  int v9; // r28
  int v10; // r31
  idMemoryMappedFile::pageState_t state; // r11

  v6 = a2 - LODWORD(this->alignedFileOffset);
  LODWORD(a5) = v6 + HIDWORD(fileOffset) - 1;
  v7 = a5 >> 16;
  v8 = *(__int64 *)((char *)&a5 - 4) >> 16;
  if ( v8 <= v7 )
  {
    v9 = v8 << 16;
    v10 = v8;
    do
    {
      if ( mmf_debug.valueInteger != 0 )
        idLib::Printf(fmt: "idMemoryMappedFile: DecommitPage( %i )\n", v8);
      state = this->pages.buffer[v10].state;
      if ( state != PGST_UNCOMITTED )
      {
        if ( state == PGST_READING )
        {
          do
            mgthread_sleep(ms: 1);
          while ( this->pages.buffer[v10].state == PGST_READING );
        }
        if ( VirtualFree(lpAddress: &this->virtualBase[v9], dwSize: 0x10000u, dwFreeType: 0x4000u) == 0 )
        {
          idLib::FatalError(fmt: "VirtualFree MEM_DECOMMIT failed");
          JUMPOUT(0x8267AE74);
        }
        SubtractTagStats(tag: 55, actualSize: 0x10000, dwSize: 0x10000, heap: 0);
        this->pages.buffer[v10].state = PGST_UNCOMITTED;
      }
      ++v8;
      ++v10;
      v9 += 0x10000;
    }
    while ( v8 <= v7 );
  }
}


// ========================================================================
// ?reportMemoryMappedFile_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8267AE78
// RVA : 0x0067AE78
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

void __fastcall reportMemoryMappedFile_f(const idCmdArgs *args)
{
  if ( currentMemoryMappedFile != nullptr )
    idMemoryMappedFile::Print(this: currentMemoryMappedFile);
}


// ========================================================================
// ??0idMemoryMappedFile@@QAA@AAVidFile@@_J1@Z
// EA  : 0x8267AF00
// RVA : 0x0067AF00
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

idMemoryMappedFile *__fastcall idMemoryMappedFile::idMemoryMappedFile(
        idMemoryMappedFile *this,
        idFile *file_,
        const __int64 fileOffset,
        const __int64 length)
{
  __int64 v4; // r11
  __int64 v5; // r8
  unsigned __int8 *v7; // r3
  __int64 alignedLength; // r10
  unsigned int v9; // r11

  this->file = file_;
  HIDWORD(v4) = HIDWORD(fileOffset) + fileOffset;
  LODWORD(v5) = HIDWORD(fileOffset) & 0xFFFF0000;
  HIDWORD(v5) = HIDWORD(fileOffset) + fileOffset + 0xFFFF;
  this->alignedFileOffset = v5;
  LODWORD(v4) = (HIDWORD(v5) & 0xFFFF0000) - (HIDWORD(fileOffset) & 0xFFFF0000);
  this->alignedLength = v4;
  v7 = (unsigned __int8 *)VirtualAlloc(lpAddress: nullptr, dwSize: v4, flAllocationType: 0x20002000u, flProtect: 4u);
  alignedLength = this->alignedLength;
  this->virtualBase = v7;
  this->pages.buffer = nullptr;
  v9 = (__int64)(unsigned int)alignedLength >> 16;
  this->pages.num = v9;
  this->pages.buffer = (idMemoryMappedFile::mmPage_t *)idMem::AllocWithLocation(
                                                         this: &mem,
                                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                                                         size: 12 * v9,
                                                         tag: TAG_TEMP,
                                                         zeroBuffer: false,
                                                         align: ALIGN_16,
                                                         heap: HEAP_DEFAULTHEAP);
  if ( this->virtualBase == nullptr )
    idLib::FatalError(fmt: "idMemoryMappedFile: failed to virtual alloc %i bytes", LODWORD(this->alignedLength));
  memset(Dst: this->pages.buffer, Val: 0, Size: 12 * this->pages.num);
  currentMemoryMappedFile = this;
  if ( mmf_debug.valueInteger != 0 )
    idLib::Printf(
      fmt: "idMemoryMappedFile: reserve VirtualAlloc( mem 0x%08x to 0x%08x )\n",
      this->virtualBase,
      &this->virtualBase[LODWORD(this->alignedLength)]);
  return this;
}


// ========================================================================
// $LN21_0
// EA  : 0x8267B038
// RVA : 0x0067B038
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

void _LN21_0()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(*(_DWORD *)(v0 - 128 + 148) + 28));
}


// ========================================================================
// ?PointerForFileBlock@idMemoryMappedFile@@QAAPBE_J0@Z
// EA  : 0x8267B068
// RVA : 0x0067B068
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

unsigned __int8 *__fastcall idMemoryMappedFile::PointerForFileBlock(
        idMemoryMappedFile *this,
        int a2,
        __int64 fileOffset,
        __int64 length,
        __int64 a5)
{
  int v6; // r4

  if ( (unsigned __int8)idMemoryMappedFile::IsBlockFullyCommitted(this, a2, fileOffset, length, a5) != 0 )
    return &this->virtualBase[v6 - LODWORD(this->alignedFileOffset)];
  else
    return nullptr;
}


// ========================================================================
// ?SetBatchState@idMemoryMappedFile@@QAA_NPBUfileRange_t@1@H@Z
// EA  : 0x8267B0D8
// RVA : 0x0067B0D8
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idMemoryMappedFile::SetBatchState(
        idMemoryMappedFile *this,
        const idMemoryMappedFile::fileRange_t *ranges,
        const int numRanges)
{
  unsigned int num; // r26
  void *v6; // r27
  __int64 v7; // r6 OVERLAPPED
  __int64 v8; // r4 OVERLAPPED
  __int64 alignedFileOffset; // r9
  int v10; // r7
  int v11; // r10
  int v12; // ctr
  unsigned int v13; // r30
  int v14; // r29
  unsigned int v15; // r30
  int v16; // r29

  num = this->pages.num;
  v6 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
         size: num,
         tag: TAG_TEMP,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  HIDWORD(v8) = memset(Dst: v6, Val: 0, Size: num);
  if ( numRanges > 0 )
  {
    do
    {
      alignedFileOffset = this->alignedFileOffset;
      *(__int64 *)((char *)&v7 - 4) = *(_QWORD *)(HIDWORD(alignedFileOffset) + 8);
      LODWORD(v7) = *(_DWORD *)(HIDWORD(alignedFileOffset) + 4) - alignedFileOffset;
      *(__int64 *)((char *)&v7 + 4) = v7 >> 16;
      LODWORD(v8) = v10 - alignedFileOffset + *(_DWORD *)(HIDWORD(alignedFileOffset) + 4) - 1;
      *(__int64 *)((char *)&v8 + 4) = v8 >> 16;
      if ( SHIDWORD(v7) <= SHIDWORD(v8) )
      {
        v11 = (int)v6 + HIDWORD(v7) - 1;
        if ( HIDWORD(v8) - HIDWORD(v7) != -1 )
        {
          v12 = HIDWORD(v8) - HIDWORD(v7) + 1;
          do
          {
            *(_BYTE *)++v11 = 1;
            --v12;
          }
          while ( v12 != 0 );
        }
      }
      --numRanges;
    }
    while ( numRanges != 0 );
  }
  v13 = 0;
  if ( num != 0 )
  {
    v14 = 0;
    do
    {
      if ( *((_BYTE *)v6 + v13) == 0 && this->pages.buffer[v14].state == PGST_FULL )
        idMemoryMappedFile::DecommitPage(this, pageNum: v13);
      ++v13;
      ++v14;
    }
    while ( v13 < num );
  }
  v15 = 0;
  if ( num != 0 )
  {
    v16 = 0;
    do
    {
      if ( *((_BYTE *)v6 + v15) != 0 && this->pages.buffer[v16].state == PGST_UNCOMITTED )
        idMemoryMappedFile::CommitPage(this, pageNum: v15);
      ++v15;
      ++v16;
    }
    while ( v15 < num );
  }
  idStreamFileCache::SignalWork(this: streamFileCache);
  if ( v6 != nullptr )
    idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
  return 0;
}


// ========================================================================
// __unwind$220150
// EA  : 0x8267B274
// RVA : 0x0067B274
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

void _unwind_220150()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 160 + 80));
}


// ========================================================================
// ?testMemoryMappedFile_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8267B2A8
// RVA : 0x0067B2A8
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

void __fastcall testMemoryMappedFile_f(const idCmdArgs *args)
{
  double v1; // r4
  idFile *v2; // r3
  __int64 v3; // r8
  __int64 v4; // r4
  double v5; // r4
  __int64 v6; // r6
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r11
  double v10; // r4
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r10
  double v18; // r4
  __int64 v19; // r8
  double v20; // r4
  idMemoryMappedFile v21; // [sp+60h] [-50h] BYREF

  v1 = (float)((float)__SPAIR64__(&unk_821C0000, Sys_GetMemoryUsage()) * (float)0.00000095367432);
  idLib::Printf(fmt: (const char *)HIDWORD(v1), LODWORD(v1));
  idLib::Printf(fmt: "Reserve\n");
  v2 = resourceManager->GetCacheFile(this: resourceManager);
  idMemoryMappedFile::idMemoryMappedFile(this: &v21, file_: v2, fileOffset: 0x2000000, length: v3);
  idMemoryMappedFile::Print(this: &v21);
  HIDWORD(v4) = Sys_GetMemoryUsage();
  LODWORD(v4) = HIDWORD(v4);
  v5 = (float)((float)v4 * (float)0.00000095367432);
  idLib::Printf(fmt: (const char *)HIDWORD(v5), LODWORD(v5));
  idLib::Printf(fmt: "Commit\n");
  HIDWORD(v6) = 0x100000;
  idMemoryMappedFile::CommitBlock(this: &v21, a2: 0x10000, fileOffset: v6, length: v8, a5: v7);
  idMemoryMappedFile::Print(this: &v21);
  LODWORD(v9) = Sys_GetMemoryUsage();
  v10 = (float)((float)v9 * (float)0.00000095367432);
  idLib::Printf(fmt: (const char *)HIDWORD(v10), LODWORD(v10));
  do
  {
    do
      HIDWORD(v13) = 0x100000;
    while ( (unsigned __int8)idMemoryMappedFile::IsBlockFullyCommitted(
                               this: &v21,
                               a2: 0x10000,
                               fileOffset: v13,
                               length: v12,
                               a5: v11) == 0 );
    v11 = __PAIR64__(v21.alignedFileOffset, (unsigned int)v21.virtualBase);
    LODWORD(v12) = &v21.virtualBase[-LODWORD(v21.alignedFileOffset)];
    HIDWORD(v12) = &v21.virtualBase[-LODWORD(v21.alignedFileOffset) + 0x10000];
  }
  while ( &v21.virtualBase[-LODWORD(v21.alignedFileOffset)] == (unsigned __int8 *const)-65536 );
  idLib::Printf(fmt: "Decommit\n");
  HIDWORD(v14) = 0x1000000;
  idMemoryMappedFile::DecommitBlock(this: &v21, a2: 0x10000, fileOffset: v14, length: v16, a5: v15);
  idMemoryMappedFile::Print(this: &v21);
  LODWORD(v17) = Sys_GetMemoryUsage();
  v18 = (float)((float)v17 * (float)0.00000095367432);
  idLib::Printf(fmt: (const char *)HIDWORD(v18), LODWORD(v18));
  idLib::Printf(fmt: "Free\n");
  idMemoryMappedFile::~idMemoryMappedFile(this: &v21);
  LODWORD(v19) = Sys_GetMemoryUsage();
  v20 = (float)((float)v19 * (float)0.00000095367432);
  idLib::Printf(fmt: (const char *)HIDWORD(v20), LODWORD(v20));
}


// ========================================================================
// __unwind$220248
// EA  : 0x8267B48C
// RVA : 0x0067B48C
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

void _unwind_220248()
{
  int v0; // r12

  idMemoryMappedFile::~idMemoryMappedFile(this: (idMemoryMappedFile *)(v0 - 176 + 96));
}


// ========================================================================
// `dynamic initializer for 'mmf_debug''
// EA  : 0x8333BAB0
// RVA : 0x0133BAB0
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mmf_debug__()
{
  idCVar::idCVar(
    this: &mmf_debug,
    name: "mmf_debug",
    value: "0",
    flags: 1,
    description: "print during operation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mmf_debug__);
}


// ========================================================================
// `dynamic initializer for 'reportMemoryMappedFile_v''
// EA  : 0x8333BB08
// RVA : 0x0133BB08
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__reportMemoryMappedFile_v__()
{
  return idCommandLink::idCommandLink(
           this: &reportMemoryMappedFile_v,
           cmdName: "reportMemoryMappedFile",
           function: reportMemoryMappedFile_f,
           description: "dump the current memory mapped file",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testMemoryMappedFile_v''
// EA  : 0x8333BB30
// RVA : 0x0133BB30
// PDB : w:\tech5\engine\framework\memorymappedfile.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testMemoryMappedFile_v__()
{
  return idCommandLink::idCommandLink(
           this: &testMemoryMappedFile_v,
           cmdName: "testMemoryMappedFile",
           function: testMemoryMappedFile_f,
           description: "test idMemoryMappedFile",
           argCompletion: nullptr);
}

