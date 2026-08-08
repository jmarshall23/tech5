
// ========================================================================
// ?MapVirtualAddressSpace@@YAXXZ
// EA  : 0x82F83028
// RVA : 0x00F83028
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall MapVirtualAddressSpace()
{
  int v0; // r29
  unsigned int i; // r30
  void *v2; // r3
  int v3; // r31
  const char *v4; // r6
  __int64 v5; // r4
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  int v9; // [sp+8h] [-118h]
  int v10; // [sp+Ch] [-114h]
  int v11; // [sp+10h] [-110h]
  int v12; // [sp+14h] [-10Ch]
  char v13[208]; // [sp+50h] [-D0h] BYREF

  v0 = 2;
  for ( i = 0x10000; i < 0xFFFF0000; i += 0x10000 )
  {
    v2 = VirtualAlloc(lpAddress: (void *)i, dwSize: 0x10000u, flAllocationType: 0x2000u, flProtect: 1u);
    v3 = v2 == (void *)i;
    if ( v2 != nullptr )
      VirtualFree(lpAddress: v2, dwSize: 0, dwFreeType: 0x8000u);
    if ( v3 != v0 )
    {
      v4 = "open";
      if ( v3 == 0 )
        v4 = "failed";
      sprintf_0(string: v13, format: "0x%08x : %s\n", i, v4);
      HIDWORD(v5) = v13;
      idLib::Printf(fmt: v5, a2: v8, a3: v7, a4: v6, a5: v9, a6: v10, a7: v11, a8: v12);
      v0 = v3;
    }
  }
}


// ========================================================================
// `Sys_WriteMemoryReport'::`9'::local_t::sort_allocationSize
// EA  : 0x82F830E0
// RVA : 0x00F830E0
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

int __fastcall _Sys_WriteMemoryReport_::_9_::local_t::sort_allocationSize(_DWORD *a, _DWORD *b)
{
  return allocationSize[*b][heap] - allocationSize[*a][heap];
}


// ========================================================================
// `Sys_DumpMemory'::`6'::local_t::sort_allocationSize
// EA  : 0x82F83120
// RVA : 0x00F83120
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

int __fastcall _Sys_DumpMemory_::_6_::local_t::sort_allocationSize(_DWORD *a, _DWORD *b)
{
  return allocationSize[*b][heap_0] - allocationSize[*a][heap_0];
}


// ========================================================================
// ?sys_clearmemory_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F83160
// RVA : 0x00F83160
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall sys_clearmemory_f(
        const idCmdArgs *args,
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
        int a12)
{
  __int64 v12; // r6
  __int64 v13; // r10
  __int64 v14; // r8
  int v15; // r11
  int i; // ctr
  __int64 v17; // r4

  LODWORD(v13) = 0;
  LODWORD(v12) = 0;
  HIDWORD(v13) = allocationTotal;
  LODWORD(v14) = allocationCurrent;
  HIDWORD(v14) = allocationSize;
  do
  {
    v15 = 0;
    for ( i = 2; i != 0; --i )
    {
      HIDWORD(v12) = v12 + v15;
      LODWORD(v17) = 4 * (v12 + v15++);
      *(volatile int *)((char *)allocationSize[0] + v17) = 0;
      *(volatile int *)((char *)allocationCurrent[0] + v17) = 0;
      *(volatile int *)((char *)allocationTotal[0] + v17) = 0;
    }
    LODWORD(v12) = v12 + 2;
  }
  while ( (int)v12 < 512 );
  HIDWORD(v17) = "Counts cleared.\n";
  idLib::Printf(fmt: v17, a2: v12, a3: v14, a4: v13, a5: a9, a6: a10, a7: a11, a8: a12);
}


// ========================================================================
// ?Sys_GetStreamFileCacheUsage@@YAIXZ
// EA  : 0x82F831C0
// RVA : 0x00F831C0
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

int __fastcall Sys_GetStreamFileCacheUsage()
{
  return allocationSize[50][1] + allocationSize[50][0];
}


// ========================================================================
// ?Sys_GetMemoryUsage@@YAIXZ
// EA  : 0x82F831D8
// RVA : 0x00F831D8
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

unsigned int __fastcall Sys_GetMemoryUsage()
{
  _MEMORYSTATUS v1; // [sp+50h] [-30h] BYREF

  GlobalMemoryStatus(lpBuffer: &v1);
  return v1.dwTotalPhys - v1.dwAvailPhys;
}


// ========================================================================
// ?Sys_GetFreeMemory@@YAIXZ
// EA  : 0x82F83208
// RVA : 0x00F83208
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

unsigned int __fastcall Sys_GetFreeMemory()
{
  _MEMORYSTATUS v1; // [sp+50h] [-30h] BYREF

  GlobalMemoryStatus(lpBuffer: &v1);
  return v1.dwAvailPhys;
}


// ========================================================================
// ?ReportPhysicalMemoryBlock@idPhysicalMemoryBlock@@QAAXXZ
// EA  : 0x82F83230
// RVA : 0x00F83230
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPhysicalMemoryBlock::ReportPhysicalMemoryBlock(
        idPhysicalMemoryBlock *this,
        int a2,
        int a3,
        int a4,
        __int64 a5)
{
  __int64 v5; // r10
  unsigned __int8 *reservedPhysicalMemoryBlock; // r31
  __int64 v8; // r4
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r10
  int commonBytes; // r11
  __int64 v13; // r4
  int v14; // r10 OVERLAPPED
  __int128 v15; // r9 OVERLAPPED
  __int64 v16; // r10
  __int128 v17; // r8
  __int64 v18; // r4
  __int64 v19; // r10
  __int128 v20; // r6
  int v21; // r11
  __int64 v22; // r8
  __int64 v23; // r10
  __int64 v24; // r8
  __int64 v25; // r6
  __int64 v26; // r4
  __int64 v27; // r10
  __int64 v28; // r8
  __int64 v29; // r6
  __int64 v30; // r4
  __int64 v31; // r10
  __int64 v32; // r8
  __int64 v33; // r6
  __int64 v34; // r10
  __int64 v35; // r4
  __int64 v36; // r8
  __int64 v37; // r6
  __int64 v38; // r10
  __int64 v39; // r4
  __int64 v40; // r8
  __int64 v41; // r6
  __int64 v42; // r8
  __int64 v43; // r4
  __int64 v44; // r10
  __int64 v45; // r6
  int v46; // [sp+8h] [-78h]
  int v47; // [sp+8h] [-78h]
  int v48; // [sp+8h] [-78h]
  int v49; // [sp+8h] [-78h]
  int v50; // [sp+8h] [-78h]
  int v51; // [sp+8h] [-78h]
  int v52; // [sp+8h] [-78h]
  int v53; // [sp+8h] [-78h]
  int v54; // [sp+8h] [-78h]
  int v55; // [sp+8h] [-78h]
  int v56; // [sp+Ch] [-74h]
  int v57; // [sp+Ch] [-74h]
  int v58; // [sp+Ch] [-74h]
  int v59; // [sp+Ch] [-74h]
  int v60; // [sp+Ch] [-74h]
  int v61; // [sp+Ch] [-74h]
  int v62; // [sp+Ch] [-74h]
  int v63; // [sp+Ch] [-74h]
  int v64; // [sp+Ch] [-74h]
  int v65; // [sp+Ch] [-74h]
  int v66; // [sp+10h] [-70h]
  int v67; // [sp+10h] [-70h]
  int v68; // [sp+10h] [-70h]
  int v69; // [sp+10h] [-70h]
  int v70; // [sp+10h] [-70h]
  int v71; // [sp+10h] [-70h]
  int v72; // [sp+10h] [-70h]
  int v73; // [sp+10h] [-70h]
  int v74; // [sp+10h] [-70h]
  int v75; // [sp+10h] [-70h]
  int v76; // [sp+14h] [-6Ch]
  int v77; // [sp+14h] [-6Ch]
  int v78; // [sp+14h] [-6Ch]
  int v79; // [sp+14h] [-6Ch]
  int v80; // [sp+14h] [-6Ch]
  int v81; // [sp+14h] [-6Ch]
  int v82; // [sp+14h] [-6Ch]
  int v83; // [sp+14h] [-6Ch]
  int v84; // [sp+14h] [-6Ch]
  int v85; // [sp+14h] [-6Ch]

  LODWORD(v5) = &unk_821C0000;
  reservedPhysicalMemoryBlock = this->reservedPhysicalMemoryBlock;
  HIDWORD(v5) = &unk_82390000;
  LODWORD(a5) = this->totalBlockSize;
  LODWORD(v8) = this->reservedPhysicalMemoryBlock;
  HIDWORD(v8) = "0x%08x - 0x%08x : %5.1f totalBlockSize\n";
  idLib::Printf(
    fmt: v8,
    a2: COERCE__INT64((float)((float)a5 * (float)0.00000095367432)),
    a3: a5,
    a4: v5,
    a5: v46,
    a6: v56,
    a7: v66,
    a8: v76);
  HIDWORD(v9) = &unk_82390000;
  LODWORD(v10) = this->commonBytes;
  idLib::Printf(
    fmt: __SPAIR64__("0x%08x - 0x%08x : %5.1f common resource region\n", (unsigned int)reservedPhysicalMemoryBlock),
    a2: COERCE__INT64((float)((float)v10 * (float)0.00000095367432)),
    a3: v9,
    a4: v11,
    a5: v47,
    a6: v57,
    a7: v67,
    a8: v77);
  commonBytes = this->commonBytes;
  LODWORD(v13) = &reservedPhysicalMemoryBlock[commonBytes];
  v14 = this->physicalBytesAllocated - commonBytes;
  HIDWORD(v13) = "0x%08x - 0x%08x : %5.1f map resource region\n";
  LODWORD(v15) = v14;
  idLib::Printf(
    fmt: v13,
    a2: COERCE__INT64((float)((float)(__int64)v15 * (float)0.00000095367432)),
    a3: *(__int64 *)((char *)&v15 + 4),
    a4: *(__int64 *)&v14,
    a5: v48,
    a6: v58,
    a7: v68,
    a8: v78);
  LODWORD(v16) = this->physicalBytesAllocated;
  LODWORD(v17) = &unk_82390000;
  DWORD2(v17) = this->cacheBytes;
  HIDWORD(v18) = "0x%08x - 0x%08x : %5.1f stream file cache region\n";
  LODWORD(v18) = &reservedPhysicalMemoryBlock[v16];
  idLib::Printf(
    fmt: v18,
    a2: COERCE__INT64((float)((float)*(__int64 *)((char *)&v17 + 4) * (float)0.00000095367432)),
    a3: v17,
    a4: v16,
    a5: v49,
    a6: v59,
    a7: v69,
    a8: v79);
  HIDWORD(v19) = this->physicalBytesAllocated;
  DWORD2(v20) = this->overlayBytes;
  HIDWORD(v20) = "0x%08x - 0x%08x : %5.1f overlay region\n";
  v21 = HIDWORD(v19) + this->cacheBytes;
  LODWORD(v19) = v21 + DWORD2(v20);
  *((double *)&v20 + 1) = (float)((float)*(__int64 *)((char *)&v20 + 4) * (float)0.00000095367432);
  DWORD1(v20) = &reservedPhysicalMemoryBlock[v21];
  idLib::Printf(fmt: *(__int64 *)&v20, a2: v20, a3: v22, a4: v19, a5: v50, a6: v60, a7: v70, a8: v80);
  overlayAllocator_t::Print(this: &oa, a2: (int)allocationCurrent[242], a3: v25, a4: v24, a5: v23);
  LODWORD(v26) = this->alignmentWaste;
  HIDWORD(v26) = "%9i alignmentWaste\n";
  idLib::Printf(fmt: v26, a2: v29, a3: v28, a4: v27, a5: v51, a6: v61, a7: v71, a8: v81);
  LODWORD(v30) = this->imageBytesAllocated;
  HIDWORD(v30) = "%9i imageBytesAllocated\n";
  idLib::Printf(fmt: v30, a2: v33, a3: v32, a4: v31, a5: v52, a6: v62, a7: v72, a8: v82);
  LODWORD(v34) = &unk_82390000;
  LODWORD(v35) = this->bufferBytesAllocated;
  HIDWORD(v35) = "%9i bufferBytesAllocated\n";
  idLib::Printf(fmt: v35, a2: v37, a3: v36, a4: v34, a5: v53, a6: v63, a7: v73, a8: v83);
  HIDWORD(v38) = &unk_82390000;
  LODWORD(v39) = this->otherBytesAllocated;
  HIDWORD(v39) = "%9i otherBytesAllocated\n";
  idLib::Printf(fmt: v39, a2: v41, a3: v40, a4: v38, a5: v54, a6: v64, a7: v74, a8: v84);
  LODWORD(v42) = &unk_82390000;
  LODWORD(v43) = this->bytesForcedOutsideBlock;
  HIDWORD(v43) = "%9i bytes forced outside block due to failed allocation\n";
  idLib::Printf(fmt: v43, a2: v45, a3: v42, a4: v44, a5: v55, a6: v65, a7: v75, a8: v85);
}


// ========================================================================
// ?ReportUntouchedPhysicalMemory@idPhysicalMemoryBlock@@QAAXXZ
// EA  : 0x82F83410
// RVA : 0x00F83410
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall idPhysicalMemoryBlock::ReportUntouchedPhysicalMemory(
        idPhysicalMemoryBlock *this,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  int physicalBytesAllocated; // r11
  int v10; // r11
  int v11; // ctr
  __int64 v12; // r4

  physicalBytesAllocated = this->physicalBytesAllocated;
  LODWORD(a4) = 0;
  LODWORD(a5) = physicalBytesAllocated >> 2;
  v10 = physicalBytesAllocated / 4;
  if ( v10 > 0 )
  {
    v11 = v10;
    HIDWORD(a5) = this->reservedPhysicalMemoryBlock;
    LODWORD(a5) = 0;
    do
    {
      HIDWORD(a4) = *(_DWORD *)(a5 + HIDWORD(a5));
      if ( HIDWORD(a4) == -17958194 )
        LODWORD(a4) = a4 + 1;
      LODWORD(a5) = a5 + 4;
      --v11;
    }
    while ( v11 != 0 );
  }
  LODWORD(v12) = 2 * a4;
  HIDWORD(v12) = "%9i untouched in allocated area\n";
  idLib::Printf(fmt: v12, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
}


// ========================================================================
// ?AddressIsInReservedPhysicalMemoryBlock@idPhysicalMemoryBlock@@QAA_NPAX@Z
// EA  : 0x82F83460
// RVA : 0x00F83460
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

int __fastcall idPhysicalMemoryBlock::AddressIsInReservedPhysicalMemoryBlock(
        idPhysicalMemoryBlock *this,
        unsigned __int8 *pAddress)
{
  unsigned __int8 v2; // r11

  if ( pAddress < this->reservedPhysicalMemoryBlock )
    return 0;
  v2 = 1;
  if ( pAddress >= &this->reservedPhysicalMemoryBlock[this->totalBlockSize] )
    return 0;
  return v2;
}


// ========================================================================
// ?AddressIsInOverlayPhysicalMemoryBlock@idPhysicalMemoryBlock@@QAA_NPAX@Z
// EA  : 0x82F83490
// RVA : 0x00F83490
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

int __fastcall idPhysicalMemoryBlock::AddressIsInOverlayPhysicalMemoryBlock(
        idPhysicalMemoryBlock *this,
        unsigned __int8 *pAddress)
{
  unsigned __int8 v2; // r11

  if ( pAddress < &this->reservedPhysicalMemoryBlock[this->physicalBytesAllocated] )
    return 0;
  v2 = 1;
  if ( pAddress >= &this->reservedPhysicalMemoryBlock[this->totalBlockSize] )
    return 0;
  return v2;
}


// ========================================================================
// ?BeginResourceLoads@idPhysicalMemoryBlock@@QAAXXZ
// EA  : 0x82F834C8
// RVA : 0x00F834C8
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall idPhysicalMemoryBlock::BeginResourceLoads(idPhysicalMemoryBlock *this)
{
  unsigned int cacheBytes; // r4
  int commonBytes; // r11

  cacheBytes = this->cacheBytes;
  this->insideResourceBlockLoad = true;
  if ( cacheBytes != 0 )
    XPhysicalProtect(
      lpAddress: &this->reservedPhysicalMemoryBlock[this->physicalBytesAllocated],
      dwSize: cacheBytes,
      flNewProtect: 0x404u);
  commonBytes = this->commonBytes;
  if ( commonBytes != 0 && this->physicalBytesAllocated != commonBytes )
  {
    this->physicalBytesAllocated = commonBytes;
    RD_DestroyGPUHeaps();
    RD_CreateGPUHeaps(
      gpuMemPtr: this->reservedPhysicalMemoryBlock,
      gpuInitialSize: this->totalBlockSize,
      sysMemPtr: nullptr,
      sysInitialSize: 0);
    RD_MemAlloc(memPtr: this->reservedPhysicalMemoryBlock, size: this->commonBytes, waste: 0, heapEnum: 2);
  }
  this->bytesForcedOutsideBlock = 0;
  this->imageBytesAllocated = 0;
  this->bufferBytesAllocated = 0;
  this->otherBytesAllocated = 0;
  idStreamFileCache::ClearMem(this: streamFileCache, releaseProvidedMemory: true);
}


// ========================================================================
// ?MapVirtualAddressSpace_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F83588
// RVA : 0x00F83588
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

// attributes: thunk
void __fastcall MapVirtualAddressSpace_f(const idCmdArgs *args)
{
  MapVirtualAddressSpace();
}


// ========================================================================
// ?TestHeapBit_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F83590
// RVA : 0x00F83590
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall TestHeapBit_f(const idCmdArgs *args)
{
  _DWORD *v1; // r30
  _DWORD *v2; // r29
  _DWORD *v3; // r28
  _DWORD *v4; // r27

  v1 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\sys\\xenon\\xen_mem.cpp(1240) : TAG_RESOURCE",
         size: 0xAu,
         tag: TAG_RESOURCE,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  v2 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\sys\\xenon\\xen_mem.cpp(1241) : TAG_RESOURCE",
         size: 0x989680u,
         tag: TAG_RESOURCE,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v3 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\sys\\xenon\\xen_mem.cpp(1245) : TAG_RESOURCE",
         size: 0xAu,
         tag: TAG_RESOURCE,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  v4 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\sys\\xenon\\xen_mem.cpp(1246) : TAG_RESOURCE",
         size: 0x989680u,
         tag: TAG_RESOURCE,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  idMem::PopHeap(this: &mem);
  idMem::Free(this: &mem, ptr: v1, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
}


// ========================================================================
// ?ReportPEheader_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F836A8
// RVA : 0x00F836A8
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall ReportPEheader_f(
        const idCmdArgs *args,
        int a2,
        __int64 a3,
        __int64 a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10)
{
  __int64 v10; // r10
  __int64 v11; // r4

  LODWORD(v10) = &unk_82390000;
  HIDWORD(v10) = &swappedNtHeader;
  HIDWORD(v11) = "numSections: %i\n";
  LODWORD(v11) = swappedNtHeader.FileHeader.NumberOfSections;
  idLib::Printf(fmt: v11, a2: a3, a3: a4, a4: v10, a5: a7, a6: a8, a7: a9, a8: a10);
}


// ========================================================================
// ?Sys_WriteMemoryReport@@YAXPBD0@Z
// EA  : 0x82F83740
// RVA : 0x00F83740
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall Sys_WriteMemoryReport(const char *mapName, const char *version)
{
  __int64 v3; // r6
  __int64 v4; // r10
  __int64 v5; // r8
  va *v6; // r3
  __int64 v7; // r6
  __int64 v8; // r10
  __int64 v9; // r8
  va *v10; // r3
  __int64 v11; // r6
  __int64 v12; // r10
  __int64 v13; // r8
  va *v14; // r3
  char *v15; // r10
  int v16; // r11
  int i; // ctr
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r6
  int v21; // r24
  int v22; // r23
  int *v23; // r17
  int j; // r15
  int v25; // r26
  int v26; // r29
  int v27; // r11
  __int64 v28; // r6
  __int64 v29; // r10
  __int64 v30; // r8
  va *v31; // r3
  const char *MemTagName; // r3
  __int64 v33; // r10
  __int64 v34; // r6
  __int64 v35; // r8
  va *v36; // r3
  __int64 v37; // r10
  __int64 v38; // r8
  __int64 v39; // r6
  va *v40; // r3
  va *v41; // r3
  __int64 v42; // r6
  __int64 v43; // r10
  __int64 v44; // r8
  va *v45; // r3
  int v46; // [sp+8h] [-1528h]
  int v47; // [sp+8h] [-1528h]
  int v48; // [sp+8h] [-1528h]
  int v49; // [sp+8h] [-1528h]
  int v50; // [sp+8h] [-1528h]
  int v51; // [sp+8h] [-1528h]
  int v52; // [sp+Ch] [-1524h]
  int v53; // [sp+Ch] [-1524h]
  int v54; // [sp+Ch] [-1524h]
  int v55; // [sp+Ch] [-1524h]
  int v56; // [sp+Ch] [-1524h]
  int v57; // [sp+Ch] [-1524h]
  int v58; // [sp+10h] [-1520h]
  int v59; // [sp+10h] [-1520h]
  int v60; // [sp+10h] [-1520h]
  int v61; // [sp+10h] [-1520h]
  int v62; // [sp+10h] [-1520h]
  int v63; // [sp+10h] [-1520h]
  int v64; // [sp+14h] [-151Ch]
  int v65; // [sp+14h] [-151Ch]
  int v66; // [sp+14h] [-151Ch]
  int v67; // [sp+14h] [-151Ch]
  int v68; // [sp+14h] [-151Ch]
  int v69; // [sp+14h] [-151Ch]
  int v70; // [sp+18h] [-1518h]
  int v71; // [sp+18h] [-1518h]
  int v72; // [sp+18h] [-1518h]
  int v73; // [sp+18h] [-1518h]
  int v74; // [sp+18h] [-1518h]
  int v75; // [sp+18h] [-1518h]
  int v76; // [sp+1Ch] [-1514h]
  int v77; // [sp+1Ch] [-1514h]
  int v78; // [sp+1Ch] [-1514h]
  int v79; // [sp+1Ch] [-1514h]
  int v80; // [sp+1Ch] [-1514h]
  int v81; // [sp+1Ch] [-1514h]
  idXMLWriter v82; // [sp+50h] [-14E0h] BYREF
  const char *v83; // [sp+64h] [-14CCh]
  idStr v84; // [sp+70h] [-14C0h] BYREF
  _BYTE v85[1024]; // [sp+90h] [-14A0h] BYREF
  va v86; // [sp+490h] [-10A0h] BYREF

  v84.len = 0;
  v84.allocedAndFlag = 20;
  v84.data = v84.baseBuffer;
  v84.baseBuffer[0] = 0;
  idStr::Format(this: &v84, fmt: "testoutput/%s/360/%s_memory.xml", version, mapName);
  idXMLWriter::idXMLWriter(this: &v82);
  if ( idXMLWriter::OpenFile(this: &v82, relativePath: v84.data, overwrite: true, savepath: true) )
  {
    idXMLWriter::OpenElement(this: &v82, name: "MemoryReport");
    idXMLWriter::WriteElement(this: &v82, name: "Version", value: version);
    HIDWORD(v3) = -1;
    v6 = va::va(this: &v86, fmt: "%d", a3: v3, a4: v5, a5: v4, a6: v46, a7: v52, a8: v58, a9: v64, a10: v70, a11: v76);
    idXMLWriter::WriteElement(this: &v82, name: "HeapBlocks", value: v6->buffer);
    HIDWORD(v7) = -1;
    v10 = va::va(this: &v86, fmt: "%d", a3: v7, a4: v9, a5: v8, a6: v47, a7: v53, a8: v59, a9: v65, a10: v71, a11: v77);
    idXMLWriter::WriteElement(this: &v82, name: "DataCount", value: v10->buffer);
    HIDWORD(v11) = -1;
    v14 = va::va(
            this: &v86,
            fmt: "%d",
            a3: v11,
            a4: v13,
            a5: v12,
            a6: v48,
            a7: v54,
            a8: v60,
            a9: v66,
            a10: v72,
            a11: v78);
    idXMLWriter::WriteElement(this: &v82, name: "OverheadCount", value: v14->buffer);
  }
  heap = 0;
  v83 = "TotalCount";
  do
  {
    v15 = &v84.baseBuffer[16];
    v16 = 0;
    for ( i = 256; i != 0; --i )
    {
      v15 += 4;
      *(_DWORD *)v15 = v16++;
    }
    qsort(
      base: v85,
      num: 0x100u,
      width: 4u,
      comp: (int (__fastcall *)(const void *, const void *))_Sys_WriteMemoryReport_::_9_::local_t::sort_allocationSize);
    v21 = 0;
    v22 = 0;
    v23 = (int *)v85;
    for ( j = 256; j != 0; --j )
    {
      v25 = *v23;
      v26 = 2 * *v23;
      v27 = v26 + heap;
      LODWORD(v18) = allocationSize[0][v27];
      if ( (_DWORD)v18 != 0 )
      {
        LODWORD(v18) = allocationSize[0][v27];
        HIDWORD(v18) = allocationCurrent[0][v27];
        LODWORD(v19) = v82.xmlFile;
        v21 += v18;
        v22 += allocationTotal[0][v27];
        if ( v82.xmlFile != nullptr )
        {
          idXMLWriter::OpenElement(this: &v82, name: "AllocRecord");
          HIDWORD(v28) = heap;
          v31 = va::va(
                  this: &v86,
                  fmt: "%d",
                  a3: v28,
                  a4: v30,
                  a5: v29,
                  a6: v46,
                  a7: v52,
                  a8: v58,
                  a9: v64,
                  a10: v70,
                  a11: v76);
          idXMLWriter::WriteElement(this: &v82, name: "Heap", value: v31->buffer);
          MemTagName = GetMemTagName(tagNum: v25);
          idXMLWriter::WriteElement(this: &v82, name: "Tag", value: MemTagName);
          LODWORD(v33) = 4 * (v26 + heap);
          HIDWORD(v34) = *(volatile int *)((char *)allocationTotal[0] + v33);
          v36 = va::va(
                  this: &v86,
                  fmt: "%d",
                  a3: v34,
                  a4: v35,
                  a5: v33,
                  a6: v49,
                  a7: v55,
                  a8: v61,
                  a9: v67,
                  a10: v73,
                  a11: v79);
          idXMLWriter::WriteElement(this: &v82, name: "Count", value: v36->buffer);
          HIDWORD(v37) = v26 + heap;
          LODWORD(v38) = 4 * (v26 + heap);
          HIDWORD(v39) = *(volatile int *)((char *)allocationSize[0] + v38);
          v40 = va::va(
                  this: &v86,
                  fmt: "%d",
                  a3: v39,
                  a4: v38,
                  a5: v37,
                  a6: v50,
                  a7: v56,
                  a8: v62,
                  a9: v68,
                  a10: v74,
                  a11: v80);
          idXMLWriter::WriteElement(this: &v82, name: "Size", value: v40->buffer);
          idXMLWriter::CloseElement(this: &v82);
        }
      }
      ++v23;
    }
    HIDWORD(v20) = v22;
    v41 = va::va(
            this: &v86,
            fmt: "%d",
            a3: v20,
            a4: v19,
            a5: v18,
            a6: v46,
            a7: v52,
            a8: v58,
            a9: v64,
            a10: v70,
            a11: v76);
    idXMLWriter::WriteElement(this: &v82, name: v83, value: v41->buffer);
    HIDWORD(v42) = v21;
    v45 = va::va(
            this: &v86,
            fmt: "%d",
            a3: v42,
            a4: v44,
            a5: v43,
            a6: v51,
            a7: v57,
            a8: v63,
            a9: v69,
            a10: v75,
            a11: v81);
    idXMLWriter::WriteElement(this: &v82, name: "TotalSize", value: v45->buffer);
    ++heap;
  }
  while ( heap < 2 );
  idXMLWriter::CloseDocument(this: &v82);
  idXMLWriter::CloseFile(this: &v82);
  idStr::FreeData(this: &v84);
}


// ========================================================================
// __unwind$115771_0
// EA  : 0x82F83A54
// RVA : 0x00F83A54
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void _unwind_115771_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5424 + 112));
}


// ========================================================================
// ?Sys_DumpMemory@@YAXXZ
// EA  : 0x82F83A80
// RVA : 0x00F83A80
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall Sys_DumpMemory()
{
  char *v0; // r10
  int v1; // r11
  int i; // ctr
  __int64 v3; // r10
  __int64 v4; // r8
  __int64 v5; // r6
  __int64 v6; // r4
  __int64 v7; // r4
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r10
  int v12; // r31
  int v13; // r30
  unsigned int v14; // r29
  int v15; // r28
  const int *v16; // r21
  int j; // r20
  int v18; // r11
  __int64 v19; // r8
  int v20; // r14
  const char *MemTagName; // r3
  int v22; // r6
  __int64 v23; // r8
  int v24; // r11
  __int64 v25; // r4
  __int64 v26; // r10
  __int64 v27; // r6
  __int64 v28; // r6
  __int64 v29; // r10
  __int64 v30; // r8
  __int64 v31; // r6
  __int64 v32; // r10
  __int64 v33; // r6
  __int64 v34; // r8
  int v35; // [sp+8h] [-4E8h]
  int v36; // [sp+8h] [-4E8h]
  int v37; // [sp+8h] [-4E8h]
  int v38; // [sp+8h] [-4E8h]
  int v39; // [sp+Ch] [-4E4h]
  int v40; // [sp+Ch] [-4E4h]
  int v41; // [sp+Ch] [-4E4h]
  int v42; // [sp+Ch] [-4E4h]
  int v43; // [sp+10h] [-4E0h]
  int v44; // [sp+10h] [-4E0h]
  int v45; // [sp+10h] [-4E0h]
  int v46; // [sp+10h] [-4E0h]
  int v47; // [sp+14h] [-4DCh]
  int v48; // [sp+14h] [-4DCh]
  int v49; // [sp+14h] [-4DCh]
  int v50; // [sp+14h] [-4DCh]
  char v51; // [sp+4Ch] [-4A4h] BYREF
  _BYTE v52[1184]; // [sp+50h] [-4A0h] BYREF

  heap_0 = 0;
  do
  {
    v0 = &v51;
    v1 = 0;
    for ( i = 256; i != 0; --i )
    {
      v0 += 4;
      *(_DWORD *)v0 = v1++;
    }
    qsort(
      base: v52,
      num: 0x100u,
      width: 4u,
      comp: (int (__fastcall *)(const void *, const void *))_Sys_DumpMemory_::_6_::local_t::sort_allocationSize);
    HIDWORD(v6) = "SYSTEM HEAP\n";
    if ( heap_0 != 0 )
      HIDWORD(v6) = "MAP HEAP\n";
    idLib::Printf(fmt: v6, a2: v5, a3: v4, a4: v3, a5: v35, a6: v39, a7: v43, a8: v47);
    HIDWORD(v7) = "Ever     : Current  : Size    : Waste\n";
    idLib::Printf(fmt: v7, a2: v10, a3: v9, a4: v8, a5: v36, a6: v40, a7: v44, a8: v48);
    LODWORD(v11) = heap_0;
    v12 = 0;
    v13 = 0;
    v14 = 0;
    v15 = 0;
    v16 = (const int *)v52;
    for ( j = 256; j != 0; --j )
    {
      HIDWORD(v11) = 2 * *v16;
      v18 = HIDWORD(v11) + v11;
      LODWORD(v19) = allocationSize[0][v18];
      if ( (_DWORD)v19 != 0 )
      {
        v12 += allocationSize[0][v18];
        v13 += allocationCurrent[0][v18];
        v14 += allocationTotal[0][v18];
        v15 += allocationWaste[0][v18];
        v20 = HIDWORD(v11) + v11;
        MemTagName = GetMemTagName(tagNum: *v16);
        v22 = allocationWaste[0][v20];
        LODWORD(v23) = MemTagName;
        v24 = allocationSize[0][v20];
        HIDWORD(v25) = "%8d : %8d : %6dk : %6dk %s\n";
        LODWORD(v26) = v22 >> 10;
        HIDWORD(v27) = allocationCurrent[0][v20];
        LODWORD(v25) = allocationTotal[0][v20];
        HIDWORD(v23) = v22 / 1024;
        HIDWORD(v26) = v24 >> 10;
        LODWORD(v27) = v24 / 1024;
        idLib::Printf(fmt: v25, a2: v27, a3: v23, a4: v26, a5: v37, a6: v41, a7: v45, a8: v49);
        LODWORD(v11) = heap_0;
      }
      ++v16;
    }
    HIDWORD(v19) = v15 / 1024;
    LODWORD(v11) = v12 >> 10;
    HIDWORD(v28) = v13;
    LODWORD(v28) = v12 / 1024;
    idLib::Printf(
      fmt: __SPAIR64__("%8d : %8d : %6dk : %6dk Total\n", v14),
      a2: v28,
      a3: v19,
      a4: v11,
      a5: v37,
      a6: v41,
      a7: v45,
      a8: v49);
    idLib::Printf(
      fmt: __SPAIR64__("Tag sum total     : 0x%08x\n", v12),
      a2: v31,
      a3: v30,
      a4: v29,
      a5: v38,
      a6: v42,
      a7: v46,
      a8: v50);
    ++heap_0;
  }
  while ( heap_0 < 2 );
  ReportGlobalMemoryStatus();
  LODWORD(v32) = allocationCurrent[242];
  HIDWORD(v32) = &unk_82390000;
  HIDWORD(v33) = totalFrees;
  LODWORD(v33) = totalAllocs - totalFrees;
  idLib::Printf(
    fmt: __SPAIR64__("%i total allocs - %i total frees = %i current\n", totalAllocs),
    a2: v33,
    a3: v34,
    a4: v32,
    a5: v35,
    a6: v39,
    a7: v43,
    a8: v47);
}


// ========================================================================
// ?AddTagStats@@YAXHHHH@Z
// EA  : 0x82F83C48
// RVA : 0x00F83C48
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall AddTagStats(int tag, int actualSize, int dwSize, int heap)
{
  int v4; // r11
  char v9; // cr34
  char v14; // cr34
  char v19; // cr34
  char v23; // cr34
  char v27; // cr34

  if ( mem_interlocked.valueInteger != 0 )
  {
    v4 = 4 * (2 * tag + heap);
    _R6 = (char *)allocationWaste + v4;
    do
    {
      __asm
      {
        mfmsr     r3
        mtmsree   r13
        lwarx     r9, 0, r6
      }
      _R8 = actualSize - dwSize + _R9;
      __asm
      {
        stwcx.    r8, 0, r6
        mtmsree   r3
      }
    }
    while ( v9 == 0 );
    _R8 = &bytesCurrentlyAllocated;
    do
    {
      __asm
      {
        mfmsr     r9
        mtmsree   r13
        lwarx     r5, (_bytesCurrentlyAllocated__3JC - 0x8382F064), r8# long volatile bytesCurrentlyAllocated
      }
      _R3 = actualSize + _R5;
      __asm
      {
        stwcx.    r3, (_bytesCurrentlyAllocated__3JC - 0x8382F064), r8# long volatile bytesCurrentlyAllocated
        mtmsree   r9
      }
    }
    while ( v14 == 0 );
    _R9 = (char *)allocationSize + v4;
    do
    {
      __asm
      {
        mfmsr     r3
        mtmsree   r13
        lwarx     r7, 0, r9
      }
      _R5 = actualSize + _R7;
      __asm
      {
        stwcx.    r5, 0, r9
        mtmsree   r3
      }
    }
    while ( v19 == 0 );
    _R5 = (char *)allocationCurrent + v4;
    do
    {
      __asm
      {
        mfmsr     r7
        mtmsree   r13
        lwarx     r8, 0, r5
      }
      ++_R8;
      __asm
      {
        stwcx.    r8, 0, r5
        mtmsree   r7
      }
    }
    while ( v23 == 0 );
    _R8 = (char *)allocationTotal + v4;
    do
    {
      __asm
      {
        mfmsr     r3
        mtmsree   r13
        lwarx     r4, 0, r8
      }
      ++_R4;
      __asm
      {
        stwcx.    r4, 0, r8
        mtmsree   r3
      }
    }
    while ( v27 == 0 );
    if ( bytesCurrentlyAllocated > maxBytesEverAllocated )
      maxBytesEverAllocated = bytesCurrentlyAllocated;
  }
}


// ========================================================================
// ?SubtractTagStats@@YAXHHHH@Z
// EA  : 0x82F83D58
// RVA : 0x00F83D58
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall SubtractTagStats(int tag, int actualSize, int dwSize, int heap)
{
  int v4; // r11
  char v9; // cr34
  int v10; // r8
  char v15; // cr34
  char v20; // cr34
  char v24; // cr34

  if ( mem_interlocked.valueInteger != 0 )
  {
    v4 = 4 * (2 * tag + heap);
    _R6 = (char *)allocationWaste + v4;
    do
    {
      __asm
      {
        mfmsr     r3
        mtmsree   r13
        lwarx     r9, 0, r6
      }
      _R8 = dwSize - actualSize + _R9;
      __asm
      {
        stwcx.    r8, 0, r6
        mtmsree   r3
      }
    }
    while ( v9 == 0 );
    v10 = -actualSize;
    _R7 = &bytesCurrentlyAllocated;
    do
    {
      __asm
      {
        mfmsr     r9
        mtmsree   r13
        lwarx     r5, (_bytesCurrentlyAllocated__3JC - 0x8382F064), r7# long volatile bytesCurrentlyAllocated
      }
      _R3 = _R5 - actualSize;
      __asm
      {
        stwcx.    r3, (_bytesCurrentlyAllocated__3JC - 0x8382F064), r7# long volatile bytesCurrentlyAllocated
        mtmsree   r9
      }
    }
    while ( v15 == 0 );
    _R10 = (char *)allocationSize + v4;
    do
    {
      __asm
      {
        mfmsr     r3
        mtmsree   r13
        lwarx     r6, 0, r10
      }
      _R4 = v10 + _R6;
      __asm
      {
        stwcx.    r4, 0, r10
        mtmsree   r3
      }
    }
    while ( v20 == 0 );
    _R6 = (char *)allocationCurrent + v4;
    do
    {
      __asm
      {
        mfmsr     r8
        mtmsree   r13
        lwarx     r9, 0, r6
      }
      --_R9;
      __asm
      {
        stwcx.    r9, 0, r6
        mtmsree   r8
      }
    }
    while ( v24 == 0 );
  }
}


// ========================================================================
// ?ReportPhysicalMemoryBlock_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F83E20
// RVA : 0x00F83E20
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall ReportPhysicalMemoryBlock_f(const idCmdArgs *args, int a2, int a3, int a4, __int64 a5)
{
  idPhysicalMemoryBlock::ReportPhysicalMemoryBlock(this: &physicalMemoryBlock, a2, a3, a4, a5);
}


// ========================================================================
// ?ReportUntouchedPhysicalMemory_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F83E30
// RVA : 0x00F83E30
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall ReportUntouchedPhysicalMemory_f(
        const idCmdArgs *args,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  idPhysicalMemoryBlock::ReportUntouchedPhysicalMemory(this: &physicalMemoryBlock, a2, a3, a4, a5, a6, a7, a8, a9);
}


// ========================================================================
// ?SetNewBase@overlayAllocator_t@@QAAXPAX@Z
// EA  : 0x82F83E48
// RVA : 0x00F83E48
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall overlayAllocator_t::SetNewBase(overlayAllocator_t *this, void *base)
{
  idSysMutex *p_mutex; // r29
  __int64 v5; // r10
  unsigned __int8 *v6; // r11
  __int64 v7; // r8
  __int64 v8; // r6
  int v9; // r4

  p_mutex = &this->mutex;
  Sys_MutexLock(handle: (PRTL_CRITICAL_SECTION *)&this->mutex, blocking: true);
  HIDWORD(v5) = ((unsigned int)base + 0xFFFF) & 0xFFFF0000;
  v6 = this->blocks[0].base;
  LODWORD(v5) = this->blocks[0].numBytes - HIDWORD(v5);
  this->blocks[0].base = (unsigned __int8 *)HIDWORD(v5);
  LODWORD(v7) = &v6[v5];
  this->blocks[0].numBytes = (int)&v6[v5];
  overlayAllocator_t::Print(this, a2: v9, a3: v8, a4: v7, a5: v5);
  Sys_MutexUnlock(handle: (PRTL_CRITICAL_SECTION *)p_mutex);
}


// ========================================================================
// __unwind$115908
// EA  : 0x82F83EB0
// RVA : 0x00F83EB0
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void _unwind_115908()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 128 + 80));
}


// ========================================================================
// ?OverlayAlloc@idPhysicalMemoryBlock@@QAAPAXHPBD@Z
// EA  : 0x82F83EE0
// RVA : 0x00F83EE0
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

unsigned __int8 *__fastcall idPhysicalMemoryBlock::OverlayAlloc(
        idPhysicalMemoryBlock *this,
        unsigned int bytes,
        const char *name)
{
  void *v6; // r30
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r4
  signed int v12; // r28
  __int64 v13; // r6
  int v14; // r4
  int numOverlayBlocks; // r11
  __int64 v16; // r8
  __int64 v17; // r10
  overlayBlock_t *v18; // r29
  __int64 v19; // r6
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r8
  int v23; // r6
  int v24; // r5
  int v25; // r4
  int v26; // r5
  overlayBlock_t *v27; // r11
  overlayBlock_t *v28; // r6
  int *p_numBytes; // r9
  int *v30; // r11
  int i; // ctr
  int v32; // r8
  int v33; // r6
  int v34; // r11
  __int64 v35; // r6
  __int64 v36; // r4
  __int64 v37; // r10
  __int64 v38; // r8
  __int64 v39; // r8
  int v40; // r6
  int v41; // r5
  int v42; // r4
  unsigned __int8 *base; // r29
  int v44; // [sp+8h] [-88h]
  int v45; // [sp+Ch] [-84h]
  int v46; // [sp+10h] [-80h]
  int v47; // [sp+14h] [-7Ch]

  if ( this->reservedPhysicalMemoryBlock == nullptr )
  {
    v6 = XMemAllocDefault(dwSize: bytes, dwAllocAttributes: 0x8C230000);
    LODWORD(v10) = bytes;
    if ( v6 == nullptr )
    {
      HIDWORD(v10) = "idPhysicalMemoryBlock::OverlayAlloc: alloc failed for overlay memory with %d bytes";
      idLib::FatalError(fmt: v10, a2: v9, a3: v8, a4: v7, a5: v44, a6: v45, a7: v46, a8: v47);
    }
    RD_MemAlloc(memPtr: v6, size: v10, waste: 0, heapEnum: 0);
    return (unsigned __int8 *)v6;
  }
  v12 = (bytes + 0xFFFF) & 0xFFFF0000;
  Sys_MutexLock(handle: (PRTL_CRITICAL_SECTION *)&oa.mutex, blocking: true);
  numOverlayBlocks = oa.numOverlayBlocks;
  LODWORD(v16) = oa.numOverlayBlocks - 1;
  if ( oa.numOverlayBlocks - 1 < 0 )
  {
LABEL_10:
    idPhysicalMemoryBlock::ReportPhysicalMemoryBlock(this, a2: v14, a3: SHIDWORD(v13), a4: v13, a5: v16);
    HIDWORD(v19) = v12;
    idLib::Warning(
      fmt: __SPAIR64__("Couldn't allocate overlay image %s at %d bytes", (unsigned int)name),
      a2: v19,
      a3: v21,
      a4: v20,
      a5: v44,
      a6: v45,
      a7: v46,
      a8: v47);
LABEL_11:
    Sys_MutexUnlock(handle: (PRTL_CRITICAL_SECTION *)&oa.mutex);
    return nullptr;
  }
  LODWORD(v17) = &oa.blocks[v16];
  while ( 1 )
  {
    v18 = (overlayBlock_t *)v17;
    if ( *(_BYTE *)v17 == 0 )
    {
      HIDWORD(v17) = *(_DWORD *)(v17 + 36);
      if ( SHIDWORD(v17) >= v12 )
        break;
    }
    LODWORD(v16) = v16 - 1;
    LODWORD(v17) = v17 - 40;
    if ( (int)v16 < 0 )
      goto LABEL_10;
  }
  if ( SHIDWORD(v17) > v12 )
  {
    if ( oa.numOverlayBlocks == 32 )
    {
      idLib::Warning(
        fmt: __SPAIR64__("Could not alloc overlay image %s, MAX OVERLAY BLOCKS exceeded", (unsigned int)name),
        a2: v13,
        a3: v16,
        a4: v17,
        a5: v44,
        a6: v45,
        a7: v46,
        a8: v47);
      idPhysicalMemoryBlock::ReportPhysicalMemoryBlock(this, a2: v25, a3: v24, a4: v23, a5: v22);
      goto LABEL_11;
    }
    if ( oa.numOverlayBlocks > (int)v16 )
    {
      v26 = oa.numOverlayBlocks - v16;
      v27 = &oa.blocks[oa.numOverlayBlocks];
      do
      {
        v28 = v27 - 1;
        p_numBytes = &v27[-1].numBytes;
        v30 = &v27[-2].numBytes;
        for ( i = 10; i != 0; --i )
          *++p_numBytes = *++v30;
        --v26;
        v27 = v28;
      }
      while ( v26 != 0 );
      numOverlayBlocks = oa.numOverlayBlocks;
    }
    oa.numOverlayBlocks = numOverlayBlocks + 1;
    v33 = *(_DWORD *)(v17 + 32);
    v34 = v16;
    v32 = *(_DWORD *)(v17 + 36);
    oa.blocks[v34 + 1].numBytes = v12;
    oa.blocks[v34 + 1].base = (unsigned __int8 *)(v33 - v12 + v32);
    v18 = &oa.blocks[v34 + 1];
    *(_DWORD *)(v17 + 36) -= v12;
  }
  strncpy(dest: v18->name, source: name, count: 0x1Fu);
  LODWORD(v35) = v18;
  LODWORD(v36) = v18->numBytes;
  HIDWORD(v36) = "Allocating %i bytes at 0x%08p for %s\n";
  HIDWORD(v35) = v18->base;
  idLib::Printf(fmt: v36, a2: v35, a3: v38, a4: v37, a5: v44, a6: v45, a7: v46, a8: v47);
  if ( mem_debugOverlay.valueInteger == 1 )
    idPhysicalMemoryBlock::ReportPhysicalMemoryBlock(this, a2: v42, a3: v41, a4: v40, a5: v39);
  base = v18->base;
  Sys_MutexUnlock(handle: (PRTL_CRITICAL_SECTION *)&oa.mutex);
  return base;
}


// ========================================================================
// $LN40_6
// EA  : 0x82F84100
// RVA : 0x00F84100
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void _LN40_6()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 144 + 80));
}


// ========================================================================
// ?OverlayFree@idPhysicalMemoryBlock@@QAAXPAX@Z
// EA  : 0x82F84130
// RVA : 0x00F84130
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall idPhysicalMemoryBlock::OverlayFree(idPhysicalMemoryBlock *this, void *buf)
{
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  __int64 v7; // r4
  int v8; // r29
  overlayBlock_t *blocks; // r28
  __int64 v10; // r4
  __int64 v11; // r8
  int v12; // r6
  int v13; // r5
  int v14; // r4
  int v15; // r11
  int v16; // r10
  overlayBlock_t *v17; // r9
  int *p_numBytes; // r10
  int *v19; // r8
  int i; // ctr
  int v21; // r11
  int v22; // r7
  int v23; // r11
  overlayBlock_t *v24; // r10
  int *v25; // r11
  int *v26; // r9
  int j; // ctr
  int v28; // [sp+8h] [-88h]
  int v29; // [sp+Ch] [-84h]
  int v30; // [sp+10h] [-80h]
  int v31; // [sp+14h] [-7Ch]

  if ( this->reservedPhysicalMemoryBlock != nullptr )
  {
    Sys_MutexLock(handle: (PRTL_CRITICAL_SECTION *)&oa.mutex, blocking: true);
    v8 = 0;
    if ( oa.numOverlayBlocks <= 0 )
    {
LABEL_7:
      HIDWORD(v7) = "idPhysicalMemoryBlock::OverlayFree: block not found (may just be the load screen)\n";
      idLib::Printf(fmt: v7, a2: v6, a3: v5, a4: v4, a5: v28, a6: v29, a7: v30, a8: v31);
    }
    else
    {
      blocks = oa.blocks;
      while ( 1 )
      {
        HIDWORD(v6) = blocks->base;
        if ( (void *)HIDWORD(v6) == buf )
          break;
        ++v8;
        ++blocks;
        if ( v8 >= oa.numOverlayBlocks )
          goto LABEL_7;
      }
      LODWORD(v10) = blocks->numBytes;
      LODWORD(v6) = blocks;
      HIDWORD(v10) = "Freeing %i bytes at 0x%08x for %s\n";
      idLib::Printf(fmt: v10, a2: v6, a3: v5, a4: v4, a5: v28, a6: v29, a7: v30, a8: v31);
      if ( mem_debugOverlay.valueInteger == 1 )
        idPhysicalMemoryBlock::ReportPhysicalMemoryBlock(this, a2: v14, a3: v13, a4: v12, a5: v11);
      blocks->name[0] = 0;
      if ( v8 < oa.numOverlayBlocks - 1 && oa.blocks[v8 + 1].name[0] == 0 )
      {
        v15 = v8 + 1;
        blocks->numBytes += oa.blocks[v8 + 1].numBytes;
        v16 = oa.numOverlayBlocks - 1;
        if ( v8 + 1 < oa.numOverlayBlocks - 1 )
        {
          v17 = &oa.blocks[v15];
          do
          {
            p_numBytes = &v17->numBytes;
            v19 = &v17[-1].numBytes;
            for ( i = 10; i != 0; --i )
              *++v19 = *++p_numBytes;
            ++v15;
            ++v17;
            v16 = oa.numOverlayBlocks - 1;
          }
          while ( v15 < oa.numOverlayBlocks - 1 );
        }
        oa.numOverlayBlocks = v16;
      }
      v21 = v8 - 1;
      if ( v8 - 1 >= 0 && oa.blocks[v21].name[0] == 0 )
      {
        v22 = v8;
        oa.blocks[v21].numBytes += blocks->numBytes;
        v23 = oa.numOverlayBlocks - 1;
        if ( v8 < oa.numOverlayBlocks - 1 )
        {
          v24 = &oa.blocks[v8];
          do
          {
            v25 = &v24->numBytes;
            v26 = &v24[-1].numBytes;
            for ( j = 10; j != 0; --j )
              *++v26 = *++v25;
            ++v22;
            ++v24;
            v23 = oa.numOverlayBlocks - 1;
          }
          while ( v22 < oa.numOverlayBlocks - 1 );
        }
        oa.numOverlayBlocks = v23;
      }
    }
    Sys_MutexUnlock(handle: (PRTL_CRITICAL_SECTION *)&oa.mutex);
  }
  else
  {
    XMemFreeDefault(pBaseAddress: buf, dwAllocAttributes: 0xA07C0000);
  }
}


// ========================================================================
// __unwind$116025
// EA  : 0x82F84340
// RVA : 0x00F84340
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void _unwind_116025()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 144 + 80));
}


// ========================================================================
// ?Init@idPhysicalMemoryBlock@@QAAXH@Z
// EA  : 0x82F84368
// RVA : 0x00F84368
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall idPhysicalMemoryBlock::Init(idPhysicalMemoryBlock *this, int bytesToAlloc)
{
  unsigned int v3; // r3
  unsigned __int8 *v4; // r3
  int v5; // r4
  __int64 v6; // r6
  int v7; // r11
  __int64 v8; // r8
  int v9; // r10

  if ( this->reservedPhysicalMemoryBlock == nullptr )
  {
    v3 = (bytesToAlloc + 0xFFFF) & 0xFFFF0000;
    this->totalBlockSize = v3;
    v4 = (unsigned __int8 *)XMemAllocDefault(dwSize: v3, dwAllocAttributes: 0x8F7C0000);
    this->reservedPhysicalMemoryBlock = v4;
    RD_MemAlloc(memPtr: v4, size: this->totalBlockSize, waste: 0, heapEnum: 0);
    RD_CreateGPUHeaps(
      gpuMemPtr: this->reservedPhysicalMemoryBlock,
      gpuInitialSize: this->totalBlockSize,
      sysMemPtr: nullptr,
      sysInitialSize: 0);
    if ( this->reservedPhysicalMemoryBlock != nullptr )
      v5 = XMemSizeDefault(pAddress: this->reservedPhysicalMemoryBlock, dwAllocAttributes: 0x8F7C0000);
    else
      v5 = 0;
    AddTagStats(tag: 124, actualSize: v5, dwSize: this->totalBlockSize, heap: 0);
    v7 = 0;
    LODWORD(v8) = this->totalBlockSize / 4;
    if ( (int)v8 > 0 )
    {
      v9 = 0;
      do
      {
        LODWORD(v8) = this->reservedPhysicalMemoryBlock;
        ++v7;
        *(_DWORD *)&this->reservedPhysicalMemoryBlock[v9] = -17958194;
        v9 += 4;
        HIDWORD(v8) = this->totalBlockSize;
        LODWORD(v6) = SHIDWORD(v8) >> 2;
      }
      while ( v7 < SHIDWORD(v8) / 4 );
    }
    this->physicalBytesAllocated = 0;
    this->imageBytesAllocated = 0;
    this->bufferBytesAllocated = 0;
    this->otherBytesAllocated = 0;
    HIDWORD(v6) = this->totalBlockSize;
    overlayAllocator_t::Init(this: &oa, base: this->reservedPhysicalMemoryBlock, numBytes: v6, a4: v8);
  }
}


// ========================================================================
// ?RevertToDiscreteAllocations@idPhysicalMemoryBlock@@QAAXXZ
// EA  : 0x82F84480
// RVA : 0x00F84480
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPhysicalMemoryBlock::RevertToDiscreteAllocations(
        idPhysicalMemoryBlock *this,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v6; // r4
  int v7; // [sp+8h] [-58h]
  int v8; // [sp+Ch] [-54h]
  int v9; // [sp+10h] [-50h]
  int v10; // [sp+14h] [-4Ch]

  if ( this->physicalBytesAllocated > 0 )
  {
    HIDWORD(v6) = "idPhysicalMemoryBlock::RevertToDiscreteAllocations: can't because of existing allocations";
    idLib::FatalError(fmt: v6, a2: a3, a3: a4, a4: a5, a5: v7, a6: v8, a7: v9, a8: v10);
  }
  SubtractTagStats(tag: 124, actualSize: this->totalBlockSize, dwSize: this->totalBlockSize, heap: 0);
  XMemFreeDefault(pBaseAddress: this->reservedPhysicalMemoryBlock, dwAllocAttributes: 0x8F7C0000);
  RD_MemFree(memPtr: this->reservedPhysicalMemoryBlock, heapEnum: 0);
  this->reservedPhysicalMemoryBlock = nullptr;
  this->totalBlockSize = 0;
}


// ========================================================================
// ?PhysicalAlloc@idPhysicalMemoryBlock@@QAAPAXHHW4memTag_t@@@Z
// EA  : 0x82F844F8
// RVA : 0x00F844F8
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

unsigned __int8 *__fastcall idPhysicalMemoryBlock::PhysicalAlloc(
        idPhysicalMemoryBlock *this,
        unsigned int bytes,
        int alignment,
        memTag_t tag)
{
  int physicalBytesAllocated; // r11
  int v7; // r29
  int v8; // r28
  void *v9; // r31
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  unsigned __int8 *reservedPhysicalMemoryBlock; // r11
  int v15; // [sp+8h] [-78h]
  int v16; // [sp+Ch] [-74h]
  int v17; // [sp+10h] [-70h]
  int v18; // [sp+14h] [-6Ch]

  physicalBytesAllocated = this->physicalBytesAllocated;
  v7 = (physicalBytesAllocated + alignment - 1) & ~(alignment - 1);
  if ( alignment > 16 )
    this->alignmentWaste = this->alignmentWaste - physicalBytesAllocated + v7;
  v8 = v7 + bytes;
  if ( (signed int)(v7 + bytes) <= this->totalBlockSize )
  {
    if ( tag == TAG_DXIMAGE )
    {
      this->imageBytesAllocated += bytes;
    }
    else if ( tag == TAG_DXBUFFER )
    {
      this->bufferBytesAllocated += bytes;
    }
    else
    {
      this->otherBytesAllocated += bytes;
    }
    RD_MemAlloc(memPtr: &this->reservedPhysicalMemoryBlock[v7], size: bytes, waste: this->alignmentWaste, heapEnum: 2);
    reservedPhysicalMemoryBlock = this->reservedPhysicalMemoryBlock;
    this->physicalBytesAllocated = v8;
    return &reservedPhysicalMemoryBlock[v7];
  }
  else
  {
    this->bytesForcedOutsideBlock += bytes;
    v9 = XMemAllocDefault(dwSize: bytes, dwAllocAttributes: 0x8C230000);
    if ( v9 == nullptr )
    {
      Sys_DumpMemory();
      idLib::FatalError(
        fmt: __SPAIR64__("idPhysicalMemoryBlock::PhysicalAlloc: alloc failed for %d bytes", bytes),
        a2: v12,
        a3: v11,
        a4: v10,
        a5: v15,
        a6: v16,
        a7: v17,
        a8: v18);
    }
    RD_MemAlloc(memPtr: v9, size: bytes, waste: 0, heapEnum: 0);
    return (unsigned __int8 *)v9;
  }
}


// ========================================================================
// XMemAlloc
// EA  : 0x82F84608
// RVA : 0x00F84608
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

unsigned __int8 *__fastcall XMemAlloc(unsigned int dwSize, int dwAllocAttributes)
{
  unsigned int v2; // r27
  int v3; // r20
  int v4; // r28
  __int64 v5; // r11
  int v6; // r11
  int v7; // r11
  int v8; // r5
  double v10; // fp30
  __int64 v11; // r10
  void *ProcessHeap; // r3
  void *currentHeap; // r31
  int v14; // r31
  char v15; // r30
  unsigned __int8 (*OutOfMemoryCallback)(void); // r3
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  int v23; // r30
  int v24; // [sp+8h] [-F8h]
  int v25; // [sp+Ch] [-F4h]
  int v26; // [sp+10h] [-F0h]
  int v27; // [sp+14h] [-ECh]
  _MEMORYSTATUS v28; // [sp+60h] [-A0h] BYREF

  v2 = dwSize;
  v3 = BYTE1(dwAllocAttributes);
  v4 = dwAllocAttributes;
  if ( BYTE1(dwAllocAttributes) == 1 )
    __trap();
  if ( (dwAllocAttributes & 0x4000) != 0 )
    v4 = dwAllocAttributes & 0xFFFFBFFF;
  HIDWORD(v5) = 0x80000000;
  if ( (v4 & 0x80000000) == 0x80000000 )
  {
    v6 = ((unsigned int)v4 >> 28) & 3;
    if ( (v6 == 3 || v6 == 0) && physicalMemoryBlock.insideResourceBlockLoad )
    {
      v7 = HIBYTE(v4) & 0xF;
      if ( v7 != 0 )
        v8 = 1 << v7;
      else
        v8 = 4096;
      return idPhysicalMemoryBlock::PhysicalAlloc(
               this: &physicalMemoryBlock,
               bytes: dwSize,
               alignment: v8,
               tag: (memTag_t)BYTE1(dwAllocAttributes));
    }
  }
  LODWORD(v5) = dwSize;
  v10 = (float)v5;
  do
  {
    GlobalMemoryStatus(lpBuffer: &v28);
    LODWORD(v11) = v28.dwAvailPhys;
    if ( (float)v11 > (double)(float)((float)(mem_reserveForSystem.valueFloat * (float)1048576.0) + (float)v10) )
    {
      if ( v4 >= 0 )
      {
        if ( (unsigned __int8)idLib::IsMainThread() != 0 )
        {
          currentHeap = memLocal.currentHeap;
          if ( memLocal.currentHeap != nullptr )
            goto LABEL_21;
          ProcessHeap = GetProcessHeap();
          memLocal.currentHeap = ProcessHeap;
        }
        else
        {
          ProcessHeap = GetProcessHeap();
        }
        currentHeap = ProcessHeap;
LABEL_21:
        if ( currentHeap != GetProcessHeap() )
          v4 |= 0x4000u;
        if ( (v4 & 0xF000000u) > 0x4000000 )
          ++badAlignment;
        RtlAllocateHeap(HeapHandle: currentHeap, Flags: 0, Size: v2);
      }
      v14 = (int)XMemAllocDefault(dwSize: v2, dwAllocAttributes: v4);
      if ( v14 != 0 )
        goto _LN58_6;
    }
    if ( idMem::GetOutOfMemoryCallback(this: &mem) == nullptr )
      return nullptr;
    v15 = 0;
    v14 = 0;
    while ( 1 )
    {
      OutOfMemoryCallback = (unsigned __int8 (*)(void))idMem::GetOutOfMemoryCallback(this: &mem);
      if ( OutOfMemoryCallback() != 0 )
        break;
      idLib::Printf(
        fmt: __SPAIR64__("sleeping while freeing cache lines %d\n", v14),
        a2: v19,
        a3: v18,
        a4: v17,
        a5: v24,
        a6: v25,
        a7: v26,
        a8: v27);
      mgthread_sleep(ms: 10);
      if ( ++v14 >= 1000 )
        goto LABEL_33;
    }
    v15 = 1;
LABEL_33:
    ;
  }
  while ( v15 != 0 );
  Sys_DumpMemory();
  idStreamFileCache::Stats(this: streamFileCache);
  LODWORD(v20) = &unk_82390000;
  idLib::FatalError(
    fmt: __SPAIR64__("Out of memory for allocation %d, couldn't free anything else", v2),
    a2: v22,
    a3: v21,
    a4: v20,
    a5: v24,
    a6: v25,
    a7: v26,
    a8: v27);
_LN58_6:
  ++totalAllocs;
  if ( (unsigned int)v4 >> 31 == 1 )
  {
    v23 = XMemSizeDefault(pAddress: (void *)v14, dwAllocAttributes: v4);
    v2 = v23;
  }
  else
  {
    v23 = ((v2 + 15) & 0xFFFFFFF0) + 16;
  }
  if ( v4 >= 0 )
    XSetAttributesOnHeapAlloc(pBaseAddress: (void *)v14, dwAllocAttributes: v4);
  RD_MemAlloc(memPtr: (void *)v14, size: v2, waste: v23 - v2, heapEnum: 0);
  AddTagStats(tag: v3, actualSize: v23, dwSize: v2, heap: 0);
  return (unsigned __int8 *)v14;
}


// ========================================================================
// XMemFree
// EA  : 0x82F84918
// RVA : 0x00F84918
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall XMemFree(unsigned __int8 *pAddress, unsigned int dwAllocAttributes)
{
  unsigned int mapHeap; // r30
  unsigned int v4; // r26
  char v5; // r11
  int v6; // r27
  int v7; // r28
  int v8; // r29
  unsigned int v9; // r3
  int v10; // r4
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  __int64 v14; // r4
  int v15; // [sp+8h] [-88h]
  int v16; // [sp+Ch] [-84h]
  int v17; // [sp+10h] [-80h]
  int v18; // [sp+14h] [-7Ch]

  mapHeap = dwAllocAttributes;
  if ( pAddress != nullptr )
  {
    v4 = dwAllocAttributes >> 31;
    if ( dwAllocAttributes >> 31 != 1 )
      goto LABEL_7;
    if ( pAddress < physicalMemoryBlock.reservedPhysicalMemoryBlock
      || (v5 = 1, pAddress >= &physicalMemoryBlock.reservedPhysicalMemoryBlock[physicalMemoryBlock.totalBlockSize]) )
    {
      v5 = 0;
    }
    if ( v5 == 0 )
    {
LABEL_7:
      v6 = BYTE1(dwAllocAttributes);
      ++totalFrees;
      v7 = XMemSizeDefault(pAddress, dwAllocAttributes);
      if ( v4 == 1 )
      {
        v8 = XMemSizeDefault(pAddress, dwAllocAttributes: mapHeap);
        v7 = v8;
      }
      else
      {
        v8 = ((XMemSizeDefault(pAddress, dwAllocAttributes: mapHeap) + 15) & 0xFFFFFFF0) + 16;
      }
      if ( v4 != 0 )
        goto _LN34_7;
      v9 = XGetAttributesOnHeapAlloc(pBaseAddress: pAddress);
      if ( v9 != mapHeap )
        LOWORD(mapHeap) = v9;
      if ( (mapHeap & 0x4000) != 0 )
      {
        mapHeap = (unsigned int)memLocal.mapHeap;
        SubtractTagStats(tag: v6, actualSize: v8, dwSize: v7, heap: 1);
        v10 = 1;
      }
      else
      {
        mapHeap = (unsigned int)GetProcessHeap();
        SubtractTagStats(tag: v6, actualSize: v8, dwSize: v7, heap: 0);
        v10 = 0;
      }
      RD_MemFree(memPtr: pAddress, heapEnum: v10);
      if ( RtlFreeHeap(HeapHandle: (void *)mapHeap, Flags: 0, BaseAddress: pAddress) == 0 )
      {
        HIDWORD(v14) = "HeapFree failed";
        idLib::FatalError(fmt: v14, a2: v13, a3: v12, a4: v11, a5: v15, a6: v16, a7: v17, a8: v18);
_LN34_7:
        SubtractTagStats(tag: v6, actualSize: v8, dwSize: v7, heap: 0);
        XMemFreeDefault(pBaseAddress: pAddress, dwAllocAttributes: mapHeap);
        RD_MemFree(memPtr: pAddress, heapEnum: 0);
      }
    }
  }
}


// ========================================================================
// ?xboxListTestAllocations_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F84AA0
// RVA : 0x00F84AA0
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall xboxListTestAllocations_f(const idCmdArgs *args, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // r8
  int v6; // r31
  __int64 v7; // r10
  int v8; // r30
  __int64 v9; // r6
  testAlloc_t *v10; // r11
  __int64 v11; // r4
  int v12; // [sp+8h] [-88h]
  int v13; // [sp+8h] [-88h]
  int v14; // [sp+Ch] [-84h]
  int v15; // [sp+Ch] [-84h]
  int v16; // [sp+10h] [-80h]
  int v17; // [sp+10h] [-80h]
  int v18; // [sp+14h] [-7Ch]
  int v19; // [sp+14h] [-7Ch]

  LODWORD(a5) = &unk_82390000;
  idLib::Printf(
    fmt: __SPAIR64__("%i test allocations\n", testAllocs.num),
    a2: a3,
    a3: a4,
    a4: a5,
    a5: v12,
    a6: v14,
    a7: v16,
    a8: v18);
  v6 = 0;
  if ( testAllocs.num > 0 )
  {
    HIDWORD(v7) = &unk_82390000;
    v8 = 0;
    do
    {
      LODWORD(v9) = "map";
      v10 = &testAllocs.list[v8];
      if ( !testAllocs.list[v8].mapHeap )
        LODWORD(v9) = "sys";
      HIDWORD(v11) = "\t%i bytes at %x in %s heap\n";
      HIDWORD(v9) = v10->ptr;
      LODWORD(v11) = v10->size;
      LODWORD(v7) = testAllocs.list[v8].mapHeap;
      idLib::Printf(fmt: v11, a2: v9, a3: v5, a4: v7, a5: v13, a6: v15, a7: v17, a8: v19);
      ++v6;
      ++v8;
    }
    while ( v6 < testAllocs.num );
  }
}


// ========================================================================
// ?xboxFreeTestAllocation_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F84B38
// RVA : 0x00F84B38
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall xboxFreeTestAllocation_f(__int64 args, __int64 a2, __int64 a3, __int64 a4)
{
  testAlloc_t *v4; // r31
  __int64 v5; // r10
  __int64 v6; // r6
  __int64 v7; // r4
  int v8; // [sp+8h] [-68h]
  int v9; // [sp+Ch] [-64h]
  int v10; // [sp+10h] [-60h]
  int v11; // [sp+14h] [-5Ch]

  if ( testAllocs.num != 0 )
  {
    v4 = &testAllocs.list[testAllocs.num];
    if ( v4[-1].mapHeap )
      LODWORD(v6) = "map";
    else
      LODWORD(v6) = "sys";
    HIDWORD(v6) = v4[-1].ptr;
    LODWORD(v7) = v4[-1].size;
    HIDWORD(v7) = "Removing allocation of %i bytes at %x from %s heap\n";
    LODWORD(v5) = v4[-1].mapHeap;
    HIDWORD(v5) = 2 * testAllocs.num;
    idLib::Printf(fmt: v7, a2: v6, a3, a4: v5, a5: v8, a6: v9, a7: v10, a8: v11);
    idMem::Free(this: &mem, ptr: (_DWORD *)v4[-1].ptr, align: ALIGN_16);
    idList<idLobbyBackend360::pendingTask_t,5>::RemoveIndex(
      this: (idList<idLobbyBackend360::pendingTask_t,5> *)&testAllocs,
      index: testAllocs.num - 1);
  }
  else
  {
    HIDWORD(args) = "No allocations to remove";
    idLib::Printf(fmt: args, a2, a3, a4, a5: v8, a6: v9, a7: v10, a8: v11);
  }
}


// ========================================================================
// ?Sys_Alloc@@YAPAXIW4memTag_t@@W4align_t@@W4heapType_t@@@Z
// EA  : 0x82F84BF8
// RVA : 0x00F84BF8
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

unsigned __int8 *__fastcall Sys_Alloc(unsigned int size, memTag_t tag, align_t align, heapType_t overrideHeap)
{
  return XMemAlloc(dwSize: size, dwAllocAttributes: (tag << 16) | 0x24002000);
}


// ========================================================================
// ?Sys_Free@@YAXPAX@Z
// EA  : 0x82F84C08
// RVA : 0x00F84C08
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall Sys_Free(void *ptr)
{
  unsigned int v2; // r3

  v2 = XGetAttributesOnHeapAlloc(pBaseAddress: ptr);
  XMemFree(pAddress: (unsigned __int8 *)ptr, dwAllocAttributes: v2);
}


// ========================================================================
// ?EndResourceLoads@idPhysicalMemoryBlock@@QAAX_N@Z
// EA  : 0x82F84C40
// RVA : 0x00F84C40
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPhysicalMemoryBlock::EndResourceLoads(idPhysicalMemoryBlock *this, bool neverFreeAllocatedData)
{
  int physicalBytesAllocated; // r10
  unsigned int v4; // r10
  int v5; // r7
  __int64 v6; // r10 OVERLAPPED
  __int64 v7; // r6
  signed int v8; // r11
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r11 OVERLAPPED
  __int64 v12; // r8 OVERLAPPED
  __int64 v13; // r8
  int v14; // r6
  int v15; // r5
  int cacheBytes; // r4
  unsigned __int8 *v17; // r30
  __int64 v18; // r6
  int v19; // [sp+8h] [-78h]
  int v20; // [sp+8h] [-78h]
  int v21; // [sp+Ch] [-74h]
  int v22; // [sp+Ch] [-74h]
  int v23; // [sp+10h] [-70h]
  int v24; // [sp+10h] [-70h]
  int v25; // [sp+14h] [-6Ch]
  int v26; // [sp+14h] [-6Ch]

  physicalBytesAllocated = this->physicalBytesAllocated;
  this->insideResourceBlockLoad = false;
  v4 = (physicalBytesAllocated + 0xFFFF) & 0xFFFF0000;
  this->physicalBytesAllocated = v4;
  if ( neverFreeAllocatedData )
    this->commonBytes = v4;
  HIDWORD(v6) = this->totalBlockSize;
  v5 = this->physicalBytesAllocated;
  LODWORD(v6) = HIDWORD(v6) - v5;
  HIDWORD(v7) = mem_overlayMegs.valueInteger << 20;
  v8 = ((mem_overlayMegs.valueInteger << 20) + 0xFFFF) & 0xFFFF0000;
  if ( HIDWORD(v6) - v5 < v8 )
    v8 = HIDWORD(v6) - v5;
  *(__int64 *)((char *)&v6 + 4) = __PAIR64__(&unk_821C0000, v8);
  this->overlayBytes = v8;
  HIDWORD(v9) = &unk_82390000;
  LODWORD(v7) = v6 - v8;
  this->cacheBytes = v6 - v8;
  idLib::Printf(
    fmt: COERCE__INT64((float)((float)__SPAIR64__(&unk_821C0000, v8) * (float)0.00000095367432)),
    a2: v7,
    a3: v9,
    a4: v6,
    a5: v19,
    a6: v21,
    a7: v23,
    a8: v25);
  HIDWORD(v10) = &unk_82390000;
  LODWORD(v11) = this->cacheBytes;
  idLib::Printf(
    fmt: COERCE__INT64((float)((float)v11 * (float)0.00000095367432)),
    a2: v10,
    a3: v12,
    a4: *(__int64 *)((char *)&v11 + 4),
    a5: v20,
    a6: v22,
    a7: v24,
    a8: v26);
  overlayAllocator_t::SetNewBase(
    this: &oa,
    base: &this->reservedPhysicalMemoryBlock[this->cacheBytes + this->physicalBytesAllocated]);
  cacheBytes = this->cacheBytes;
  if ( cacheBytes > 0 )
  {
    v17 = &this->reservedPhysicalMemoryBlock[this->physicalBytesAllocated];
    XPhysicalProtect(lpAddress: v17, dwSize: cacheBytes, flNewProtect: 4u);
    HIDWORD(v18) = this->cacheBytes;
    idStreamFileCache::ProvideCacheMemory(this: streamFileCache, base: (char *)v17, length: v18);
  }
  idPhysicalMemoryBlock::ReportPhysicalMemoryBlock(
    this: &physicalMemoryBlock,
    a2: cacheBytes,
    a3: v15,
    a4: v14,
    a5: v13);
}


// ========================================================================
// ?xboxAllocateTestMemory_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F84DB8
// RVA : 0x00F84DB8
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __fastcall xboxAllocateTestMemory_f(__int64 args, __int64 a2, __int64 a3, __int64 a4)
{
  const char *v4; // r29
  const char *v5; // r11
  unsigned int v6; // r31
  const char *v7; // r30
  heapType_t v8; // r9
  const char *v9; // r4
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r4
  int v14; // [sp+8h] [-78h]
  int v15; // [sp+Ch] [-74h]
  int v16; // [sp+10h] [-70h]
  int v17; // [sp+14h] [-6Ch]
  aas2Edge_t v18; // [sp+50h] [-30h] BYREF

  LODWORD(a4) = *(_DWORD *)HIDWORD(args);
  if ( (int)*(_DWORD *)HIDWORD(args) > 2 )
  {
    v4 = &byte_8200D768;
    if ( (int)a4 <= 1 )
      v5 = &byte_8200D768;
    else
      v5 = *(const char **)(HIDWORD(args) + 8);
    if ( ((int)a4 <= 2 || (v4 = *(const char **)(HIDWORD(args) + 12)) != nullptr) && v5 != nullptr )
    {
      v6 = atol(nptr: v5) << 20;
      v7 = "map";
      v18.vertexNum[1] = v6;
      if ( idStr::Cmp(s1: v4, s2: "map") != 0 )
      {
        v9 = "w:\\tech5\\shared\\idlib\\sys\\xenon\\xen_mem.cpp(1307) : TAG_FILE";
        HIBYTE(v18.flags) = 0;
        v8 = HEAP_SYSTEMHEAP;
        v7 = "sys";
      }
      else
      {
        v8 = HEAP_MAPHEAP;
        v9 = "w:\\tech5\\shared\\idlib\\sys\\xenon\\xen_mem.cpp(1303) : TAG_FILE";
        HIBYTE(v18.flags) = 1;
      }
      HIDWORD(v12) = idMem::AllocWithLocation(
                       this: &mem,
                       location: v9,
                       size: v6,
                       tag: TAG_FILE,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: v8);
      v18.vertexNum[0] = HIDWORD(v12);
      if ( HIDWORD(v12) != 0 )
      {
        LODWORD(v12) = v7;
        idLib::Printf(
          fmt: __SPAIR64__("Adding allocation of %i bytes at %x from %s heap\n", v6),
          a2: v12,
          a3: v11,
          a4: v10,
          a5: v14,
          a6: v15,
          a7: v16,
          a8: v17);
        idList<idRenderModelEffects::deferredStage_t,5>::Append(this: (idList<aas2Edge_t,37> *)&testAllocs, obj: &v18);
      }
      else
      {
        HIDWORD(v13) = "Failed to allocate\n";
        idLib::Printf(fmt: v13, a2: (unsigned int)v12, a3: v11, a4: v10, a5: v14, a6: v15, a7: v16, a8: v17);
      }
    }
  }
  else
  {
    HIDWORD(args) = "syntax: xboxAllocateTestMemory <numMegs> <map|sys>\n";
    idLib::Printf(fmt: args, a2, a3, a4, a5: v14, a6: v15, a7: v16, a8: v17);
  }
}


// ========================================================================
// `dynamic initializer for 'mem_overlayMegs''
// EA  : 0x83396FF8
// RVA : 0x01396FF8
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mem_overlayMegs__()
{
  idCVar::idCVar(
    this: &mem_overlayMegs,
    name: "mem_overlayMegs",
    value: "20",
    flags: 2,
    description: "Remainder of physical memory block after this goes to stream file cache",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mem_overlayMegs__);
}


// ========================================================================
// `dynamic initializer for 'mem_interlocked''
// EA  : 0x83397050
// RVA : 0x01397050
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mem_interlocked__()
{
  idCVar::idCVar(
    this: &mem_interlocked,
    name: "mem_interlocked",
    value: "1",
    flags: 1,
    description: "Use interlocked tag stats",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mem_interlocked__);
}


// ========================================================================
// `dynamic initializer for 'mem_debugOverlay''
// EA  : 0x833970A8
// RVA : 0x013970A8
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mem_debugOverlay__()
{
  idCVar::idCVar(
    this: &mem_debugOverlay,
    name: "mem_debugOverlay",
    value: "0",
    flags: 2,
    description: "Debug overlay memory",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mem_debugOverlay__);
}


// ========================================================================
// `dynamic initializer for 'mem_reserveForSystem''
// EA  : 0x83397100
// RVA : 0x01397100
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mem_reserveForSystem__()
{
  idCVar::idCVar(
    this: &mem_reserveForSystem,
    name: "mem_reserveForSystem",
    value: "0.5",
    flags: 4,
    description: "Amount of phys ram in MiB to keep free for system",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mem_reserveForSystem__);
}


// ========================================================================
// `dynamic initializer for 'sys_clearmemory_v''
// EA  : 0x83397158
// RVA : 0x01397158
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__sys_clearmemory_v__()
{
  return idCommandLink::idCommandLink(
           this: &sys_clearmemory_v,
           cmdName: "sys_clearmemory",
           function: (void (__fastcall *)(const idCmdArgs *))sys_clearmemory_f,
           description: "clears memory allocation totals",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ReportPhysicalMemoryBlock_v''
// EA  : 0x83397180
// RVA : 0x01397180
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ReportPhysicalMemoryBlock_v__()
{
  return idCommandLink::idCommandLink(
           this: &ReportPhysicalMemoryBlock_v,
           cmdName: "ReportPhysicalMemoryBlock",
           function: (void (__fastcall *)(const idCmdArgs *))ReportPhysicalMemoryBlock_f,
           description: "Reports information on the packed physical block",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ReportUntouchedPhysicalMemory_v''
// EA  : 0x833971A8
// RVA : 0x013971A8
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ReportUntouchedPhysicalMemory_v__()
{
  return idCommandLink::idCommandLink(
           this: &ReportUntouchedPhysicalMemory_v,
           cmdName: "ReportUntouchedPhysicalMemory",
           function: (void (__fastcall *)(const idCmdArgs *))ReportUntouchedPhysicalMemory_f,
           description: "Scans for memory that was never written over",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'MapVirtualAddressSpace_v''
// EA  : 0x833971D0
// RVA : 0x013971D0
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__MapVirtualAddressSpace_v__()
{
  return idCommandLink::idCommandLink(
           this: &MapVirtualAddressSpace_v,
           cmdName: "MapVirtualAddressSpace",
           function: MapVirtualAddressSpace_f,
           description: "Try to allocate blocks everywhere",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestHeapBit_v''
// EA  : 0x833971F8
// RVA : 0x013971F8
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestHeapBit_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestHeapBit_v,
           cmdName: "TestHeapBit",
           function: TestHeapBit_f,
           description: "Test the stolen attribute bit for big and small allocations",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ReportPEheader_v''
// EA  : 0x83397220
// RVA : 0x01397220
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ReportPEheader_v__()
{
  return idCommandLink::idCommandLink(
           this: &ReportPEheader_v,
           cmdName: "ReportPEheader",
           function: (void (__fastcall *)(const idCmdArgs *))ReportPEheader_f,
           description: "reports the exe header information",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testAllocs''
// EA  : 0x83397248
// RVA : 0x01397248
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__testAllocs__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__testAllocs__);
}


// ========================================================================
// `dynamic initializer for 'xboxAllocateTestMemory_v''
// EA  : 0x83397258
// RVA : 0x01397258
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__xboxAllocateTestMemory_v__()
{
  return idCommandLink::idCommandLink(
           this: &xboxAllocateTestMemory_v,
           cmdName: "xboxAllocateTestMemory",
           function: (void (__fastcall *)(const idCmdArgs *))xboxAllocateTestMemory_f,
           description: "allocates memory for testing",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'xboxListTestAllocations_v''
// EA  : 0x83397280
// RVA : 0x01397280
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__xboxListTestAllocations_v__()
{
  return idCommandLink::idCommandLink(
           this: &xboxListTestAllocations_v,
           cmdName: "xboxListTestAllocations",
           function: (void (__fastcall *)(const idCmdArgs *))xboxListTestAllocations_f,
           description: "lists allocated testing memory",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'xboxFreeTestAllocation_v''
// EA  : 0x833972A8
// RVA : 0x013972A8
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_mem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__xboxFreeTestAllocation_v__()
{
  return idCommandLink::idCommandLink(
           this: &xboxFreeTestAllocation_v,
           cmdName: "xboxFreeTestAllocation",
           function: (void (__fastcall *)(const idCmdArgs *))xboxFreeTestAllocation_f,
           description: "frees memory for testing",
           argCompletion: nullptr);
}

