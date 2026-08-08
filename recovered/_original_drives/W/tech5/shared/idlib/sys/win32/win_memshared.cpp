
// ========================================================================
// ?Sys_AllocWillUseMapHeap@@YA_NXZ
// EA  : 0x82F82700
// RVA : 0x00F82700
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

int __fastcall Sys_AllocWillUseMapHeap()
{
  int result; // r3
  bool v1; // zf

  if ( (unsigned __int8)idLib::IsMainThread() == 0 )
    return 0;
  if ( memLocal.currentHeap == nullptr )
    return 0;
  v1 = memLocal.currentHeap != GetProcessHeap();
  result = 1;
  if ( !v1 )
    return 0;
  return result;
}


// ========================================================================
// ?Sys_ReportHeaps@@YAXXZ
// EA  : 0x82F82760
// RVA : 0x00F82760
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

void __fastcall Sys_ReportHeaps(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // r4
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r4
  __int64 v12; // r4
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  int v16; // [sp+8h] [-68h]
  int v17; // [sp+8h] [-68h]
  int v18; // [sp+8h] [-68h]
  int v19; // [sp+8h] [-68h]
  int v20; // [sp+Ch] [-64h]
  int v21; // [sp+Ch] [-64h]
  int v22; // [sp+Ch] [-64h]
  int v23; // [sp+Ch] [-64h]
  int v24; // [sp+10h] [-60h]
  int v25; // [sp+10h] [-60h]
  int v26; // [sp+10h] [-60h]
  int v27; // [sp+10h] [-60h]
  int v28; // [sp+14h] [-5Ch]
  int v29; // [sp+14h] [-5Ch]
  int v30; // [sp+14h] [-5Ch]
  int v31; // [sp+14h] [-5Ch]

  HIDWORD(a1) = "Global heap: ";
  idLib::Printf(fmt: a1, a2, a3, a4, a5: v16, a6: v20, a7: v24, a8: v28);
  GetProcessHeap();
  HIDWORD(v4) = "Can't HeapWalk() in this configuration\n";
  idLib::Printf(fmt: v4, a2: v7, a3: v6, a4: v5, a5: v17, a6: v21, a7: v25, a8: v29);
  if ( memLocal.currentHeap != nullptr && memLocal.currentHeap != GetProcessHeap() )
  {
    HIDWORD(v11) = "Map heap   : ";
    idLib::Printf(fmt: v11, a2: v10, a3: v9, a4: v8, a5: v18, a6: v22, a7: v26, a8: v30);
    HIDWORD(v12) = "Can't HeapWalk() in this configuration\n";
    idLib::Printf(fmt: v12, a2: v15, a3: v14, a4: v13, a5: v19, a6: v23, a7: v27, a8: v31);
  }
}


// ========================================================================
// ?reportHeaps_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F827E8
// RVA : 0x00F827E8
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

// attributes: thunk
void __fastcall reportHeaps_f(__int64 args, __int64 a2, __int64 a3, __int64 a4)
{
  Sys_ReportHeaps(a1: args, a2, a3, a4);
}


// ========================================================================
// ?PushHeap@idMemLocal@@QAAXW4heapType_t@@@Z
// EA  : 0x82F827F0
// RVA : 0x00F827F0
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

void __fastcall idMemLocal::PushHeap(idMemLocal *this, const heapType_t heapType)
{
  if ( (unsigned __int8)idLib::IsMainThread() != 0 )
  {
    if ( this->mem_heapStack == 0 )
    {
      this->pushedHeap = this->currentHeap;
      if ( heapType != HEAP_SYSTEMHEAP )
        this->currentHeap = this->mapHeap;
      else
        this->currentHeap = GetProcessHeap();
    }
    ++this->mem_heapStack;
  }
}


// ========================================================================
// ?PopHeap@idMemLocal@@QAAXXZ
// EA  : 0x82F82870
// RVA : 0x00F82870
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

void __fastcall idMemLocal::PopHeap(idMemLocal *this)
{
  int v2; // r11
  void *pushedHeap; // r11

  if ( (unsigned __int8)idLib::IsMainThread() != 0 )
  {
    v2 = this->mem_heapStack - 1;
    this->mem_heapStack = v2;
    if ( v2 == 0 )
    {
      pushedHeap = this->pushedHeap;
      this->pushedHeap = nullptr;
      this->currentHeap = pushedHeap;
    }
  }
}


// ========================================================================
// ?ReportGlobalMemoryStatus@@YAXXZ
// EA  : 0x82F828C8
// RVA : 0x00F828C8
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

void __fastcall ReportGlobalMemoryStatus()
{
  __int64 v0; // r10
  unsigned int v1; // r31
  __int64 v2; // r8
  __int64 v3; // r6
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  __int64 v7; // r8
  __int64 v8; // r10
  __int64 v9; // r6
  __int64 v10; // r8
  __int64 v11; // r4
  __int64 v12; // r10
  int v13; // [sp+8h] [-78h]
  int v14; // [sp+8h] [-78h]
  int v15; // [sp+8h] [-78h]
  int v16; // [sp+8h] [-78h]
  int v17; // [sp+Ch] [-74h]
  int v18; // [sp+Ch] [-74h]
  int v19; // [sp+Ch] [-74h]
  int v20; // [sp+Ch] [-74h]
  int v21; // [sp+10h] [-70h]
  int v22; // [sp+10h] [-70h]
  int v23; // [sp+10h] [-70h]
  int v24; // [sp+10h] [-70h]
  int v25; // [sp+14h] [-6Ch]
  int v26; // [sp+14h] [-6Ch]
  int v27; // [sp+14h] [-6Ch]
  int v28; // [sp+14h] [-6Ch]
  _MEMORYSTATUS v29; // [sp+50h] [-30h] BYREF

  GlobalMemoryStatus(lpBuffer: &v29);
  LODWORD(v0) = v29.dwAvailPhys;
  v1 = v29.dwTotalPhys - v29.dwAvailPhys;
  idLib::Printf(
    fmt: __SPAIR64__("GlobalMemoryStatus: 0x%08x dwTotalPhys\n", v29.dwTotalPhys),
    a2: v3,
    a3: v2,
    a4: v0,
    a5: v13,
    a6: v17,
    a7: v21,
    a8: v25);
  HIDWORD(v4) = &unk_82390000;
  idLib::Printf(
    fmt: __SPAIR64__("GlobalMemoryStatus: 0x%08x dwAvailPhys\n", v29.dwAvailPhys),
    a2: v6,
    a3: v5,
    a4: v4,
    a5: v14,
    a6: v18,
    a7: v22,
    a8: v26);
  LODWORD(v7) = &unk_82390000;
  idLib::Printf(
    fmt: __SPAIR64__("GlobalMemoryStatus: 0x%08x used phys\n", v1),
    a2: v9,
    a3: v7,
    a4: v8,
    a5: v15,
    a6: v19,
    a7: v23,
    a8: v27);
  HIDWORD(v10) = &unk_82390000;
  HIDWORD(v11) = "GlobalMemoryStatus: 0x%08x used virtual\n";
  LODWORD(v11) = v29.dwTotalVirtual - v29.dwAvailVirtual;
  idLib::Printf(fmt: v11, a2: *(__int64 *)&v29.dwTotalVirtual, a3: v10, a4: v12, a5: v16, a6: v20, a7: v24, a8: v28);
}


// ========================================================================
// ?ReportStalePointers_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F82948
// RVA : 0x00F82948
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

void __fastcall ReportStalePointers_f(const idCmdArgs *args)
{
  testMapHeap = idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\sys\\win32\\win_memShared.cpp(414) : TAG_RESOURCE",
                  size: 0x10u,
                  tag: TAG_RESOURCE,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  strncpy(dest: (char *)testMapHeap, source: "find this!", count: 0x10u);
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  testGlobalHeap = idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\sys\\win32\\win_memShared.cpp(417) : TAG_RESOURCE",
                     size: 0x10u,
                     tag: TAG_RESOURCE,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
  idMem::PopHeap(this: &mem);
  *(_DWORD *)testGlobalHeap = testMapHeap;
}


// ========================================================================
// ?ResetMapHeap@idMemLocal@@QAAXXZ
// EA  : 0x82F829F0
// RVA : 0x00F829F0
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMemLocal::ResetMapHeap(idMemLocal *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // r4
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r4
  void *currentHeap; // r30
  void *v12; // r3
  int v13; // [sp+8h] [-68h]
  int v14; // [sp+Ch] [-64h]
  int v15; // [sp+10h] [-60h]
  int v16; // [sp+14h] [-5Ch]

  HIDWORD(v6) = "---------- ResetMapHeap ----------\n";
  idLib::Printf(fmt: v6, a2: a3, a3: a4, a4: a5, a5: v13, a6: v14, a7: v15, a8: v16);
  Sys_ReportHeaps(a1: v10, a2: v9, a3: v8, a4: v7);
  currentHeap = this->currentHeap;
  if ( currentHeap != GetProcessHeap() )
  {
    HeapDestroy(hHeap: currentHeap);
    RD_DestroyMapHeap();
  }
  v12 = HeapCreate(flOptions: 0, dwInitialSize: 0x100000u, dwMaximumSize: 0);
  this->mapHeap = v12;
  this->currentHeap = v12;
  RD_CreateMapHeap();
  ReportGlobalMemoryStatus();
}


// ========================================================================
// ?TestPoisonAllocs_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F82A78
// RVA : 0x00F82A78
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

void __fastcall TestPoisonAllocs_f(const idCmdArgs *args)
{
  _DWORD *v1; // r26
  int i; // r24
  unsigned int v3; // r30
  _DWORD *v4; // r29
  int v5; // r23
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  _DWORD **v9; // r29
  int j; // r30
  int v11; // [sp+8h] [-A8h]
  int v12; // [sp+Ch] [-A4h]
  int v13; // [sp+10h] [-A0h]
  int v14; // [sp+14h] [-9Ch]

  v1 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
         size: 0x9C40u,
         tag: TAG_TEMP,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  for ( i = 4; i != 0; --i )
  {
    v3 = 0;
    v4 = v1;
    do
    {
      v5 = Sys_Microseconds() >> 32;
      *v4 = idMem::AllocWithLocation(
              this: &mem,
              location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
              size: 0x3E8u,
              tag: TAG_NEW,
              zeroBuffer: false,
              align: ALIGN_16,
              heap: HEAP_DEFAULTHEAP);
      HIDWORD(v8) = (Sys_Microseconds() >> 32) - v5;
      if ( SHIDWORD(v8) > 1000 )
        idLib::Printf(
          fmt: __SPAIR64__("Alloc %i = %i microseconds\n", v3),
          a2: v8,
          a3: v7,
          a4: v6,
          a5: v11,
          a6: v12,
          a7: v13,
          a8: v14);
      ++v3;
      ++v4;
    }
    while ( v3 < 0x2710 );
    v9 = (_DWORD **)(v1 - 1);
    for ( j = 10000; j != 0; --j )
      idMem::Free(this: &mem, ptr: *++v9, align: ALIGN_16);
  }
  if ( v1 != nullptr )
    idMem::Free(this: &mem, ptr: v1, align: ALIGN_16);
}


// ========================================================================
// __unwind$118164
// EA  : 0x82F82B88
// RVA : 0x00F82B88
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

void _unwind_118164()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 176 + 80));
}


// ========================================================================
// `dynamic initializer for 'mem_guardMapHeap''
// EA  : 0x83396E28
// RVA : 0x01396E28
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mem_guardMapHeap__()
{
  idCVar::idCVar(
    this: &mem_guardMapHeap,
    name: "mem_guardMapHeap",
    value: "0",
    flags: 1,
    description: "Don't destroy map heaps on exit, guard them instead (64 bit build required)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mem_guardMapHeap__);
}


// ========================================================================
// `dynamic initializer for 'mem_findStalePointers''
// EA  : 0x83396E80
// RVA : 0x01396E80
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mem_findStalePointers__()
{
  idCVar::idCVar(
    this: &mem_findStalePointers,
    name: "mem_findStalePointers",
    value: "0",
    flags: 1,
    description: "Run the heap pointer checking before resetMapHeap",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mem_findStalePointers__);
}


// ========================================================================
// `dynamic initializer for 'mem_printAllocsOnMapHeapDestroy''
// EA  : 0x83396ED8
// RVA : 0x01396ED8
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mem_printAllocsOnMapHeapDestroy__()
{
  idCVar::idCVar(
    this: &mem_printAllocsOnMapHeapDestroy,
    name: "mem_printAllocsOnMapHeapDestroy",
    value: "0",
    flags: 1,
    description: "Print out any unfreed allocations on map heap destroy",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mem_printAllocsOnMapHeapDestroy__);
}


// ========================================================================
// `dynamic initializer for 'reportHeaps_v''
// EA  : 0x83396F30
// RVA : 0x01396F30
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__reportHeaps_v__()
{
  return idCommandLink::idCommandLink(
           this: &reportHeaps_v,
           cmdName: "reportHeaps",
           function: (void (__fastcall *)(const idCmdArgs *))reportHeaps_f,
           description: "reports the allocations in the global and map heaps",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ReportStalePointers_v''
// EA  : 0x83396F58
// RVA : 0x01396F58
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ReportStalePointers_v__()
{
  return idCommandLink::idCommandLink(
           this: &ReportStalePointers_v,
           cmdName: "ReportStalePointers",
           function: ReportStalePointers_f,
           description: "Looks for global heap pointers to the map heap",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'dumpHeapEntries_v''
// EA  : 0x83396F80
// RVA : 0x01396F80
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__dumpHeapEntries_v__()
{
  return idCommandLink::idCommandLink(
           this: &dumpHeapEntries_v,
           cmdName: "dumpHeapEntries",
           function: (void (__fastcall *)(const idCmdArgs *))idPhysics_StaticMulti::UpdateTime,
           description: "Walks the heap in debug builds",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'reportTagStrings_v''
// EA  : 0x83396FA8
// RVA : 0x01396FA8
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__reportTagStrings_v__()
{
  return idCommandLink::idCommandLink(
           this: &reportTagStrings_v,
           cmdName: "reportTagStrings",
           function: (void (__fastcall *)(const idCmdArgs *))idPhysics_StaticMulti::UpdateTime,
           description: "Walks the heap in debug builds",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestPoisonAllocs_v''
// EA  : 0x83396FD0
// RVA : 0x01396FD0
// PDB : w:\tech5\shared\idlib\sys\win32\win_memshared.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestPoisonAllocs_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestPoisonAllocs_v,
           cmdName: "TestPoisonAllocs",
           function: TestPoisonAllocs_f,
           description: "Check for extremely bad allocation times",
           argCompletion: nullptr);
}

