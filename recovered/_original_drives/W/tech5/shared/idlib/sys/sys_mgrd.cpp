
// ========================================================================
// ?RD_Init@@YAXXZ
// EA  : 0x82F81838
// RVA : 0x00F81838
// PDB : w:\tech5\shared\idlib\sys\sys_mgrd.cpp
// ========================================================================

void __fastcall RD_Init()
{
  const char *CommandLineA; // r3
  int v1; // r29
  void *ProcessHeap; // r3

  if ( rdInit == 0 )
  {
    CommandLineA = GetCommandLineA();
    if ( strstr(str1: CommandLineA, str2: "-mgrd") != nullptr && rdInit == 0 )
    {
      rdInit = 1;
      v1 = rdHeapSizeMB;
      ProcessHeap = GetProcessHeap();
      RtlAllocateHeap(HeapHandle: ProcessHeap, Flags: 0, Size: v1 << 20);
    }
    rdInit = 2;
  }
}


// ========================================================================
// ?RD_CreateGPUHeaps@@YAXPBXI0I@Z
// EA  : 0x82F81908
// RVA : 0x00F81908
// PDB : w:\tech5\shared\idlib\sys\sys_mgrd.cpp
// ========================================================================

void __fastcall RD_CreateGPUHeaps(
        void *gpuMemPtr,
        unsigned int gpuInitialSize,
        void *sysMemPtr,
        unsigned int sysInitialSize)
{
  RD_Init();
  if ( rdInit == 1 )
  {
    rd_mem_heap_create(heap: &heapinfoGPU, parent: nullptr, name: "GPU", mem: gpuMemPtr, size: gpuInitialSize);
    rd_mem_heap_create(heap: &heapinfoGPUSys, parent: nullptr, name: "GPU Sys", mem: sysMemPtr, size: sysInitialSize);
  }
}


// ========================================================================
// ?RD_DestroyGPUHeaps@@YAXXZ
// EA  : 0x82F81980
// RVA : 0x00F81980
// PDB : w:\tech5\shared\idlib\sys\sys_mgrd.cpp
// ========================================================================

void __fastcall RD_DestroyGPUHeaps()
{
  unsigned __int64 v0; // r10

  RD_Init();
  if ( rdInit == 1 && LODWORD(heapinfoGPU.id) != 0 )
  {
    rd_mem_heap_destroy(heap: &heapinfoGPU);
    rd_mem_heap_destroy(heap: &heapinfoGPUSys);
    LODWORD(v0) = 0;
    heapinfoGPU.id = 0;
    heapinfoGPUSys.id = v0;
  }
}


// ========================================================================
// ?RD_CreateMapHeap@@YAXXZ
// EA  : 0x82F819E8
// RVA : 0x00F819E8
// PDB : w:\tech5\shared\idlib\sys\sys_mgrd.cpp
// ========================================================================

void __fastcall RD_CreateMapHeap()
{
  RD_Init();
  if ( rdInit == 1 )
    rd_mem_heap_create(heap: &heapinfoMap, parent: nullptr, name: "Map", mem: nullptr, size: 0);
}


// ========================================================================
// ?RD_DestroyMapHeap@@YAXXZ
// EA  : 0x82F81A38
// RVA : 0x00F81A38
// PDB : w:\tech5\shared\idlib\sys\sys_mgrd.cpp
// ========================================================================

void __fastcall RD_DestroyMapHeap()
{
  unsigned __int64 v0; // r11

  RD_Init();
  if ( rdInit == 1 && LODWORD(heapinfoMap.id) != 0 )
  {
    rd_mem_heap_destroy(heap: &heapinfoMap);
    LODWORD(v0) = 0;
    heapinfoMap.id = v0;
  }
}


// ========================================================================
// ?RD_MemAlloc@@YAXPAXIIH@Z
// EA  : 0x82F81A90
// RVA : 0x00F81A90
// PDB : w:\tech5\shared\idlib\sys\sys_mgrd.cpp
// ========================================================================

void __fastcall RD_MemAlloc(void *memPtr, unsigned int size, unsigned int waste, int heapEnum)
{
  RD_HEAP *v8; // r3

  RD_Init();
  v8 = &heapinfoDefault;
  if ( rdInit == 1 )
  {
    if ( heapEnum != 0 )
    {
      switch ( heapEnum )
      {
        case 1:
          v8 = &heapinfoMap;
          break;
        case 2:
          v8 = &heapinfoGPU;
          break;
        case 3:
          v8 = &heapinfoGPUSys;
          break;
        default:
          break;
      }
    }
    rd_mem_alloc(heap: v8, ptr: memPtr, size, waste);
  }
}


// ========================================================================
// ?RD_MemFree@@YAXPAXH@Z
// EA  : 0x82F81B10
// RVA : 0x00F81B10
// PDB : w:\tech5\shared\idlib\sys\sys_mgrd.cpp
// ========================================================================

void __fastcall RD_MemFree(void *memPtr, int heapEnum)
{
  RD_HEAP *v4; // r3

  RD_Init();
  v4 = &heapinfoDefault;
  if ( rdInit == 1 )
  {
    if ( heapEnum != 0 )
    {
      switch ( heapEnum )
      {
        case 1:
          v4 = &heapinfoMap;
          break;
        case 2:
          v4 = &heapinfoGPU;
          break;
        case 3:
          v4 = &heapinfoGPUSys;
          break;
        default:
          break;
      }
    }
    rd_mem_free(heap: v4, ptr: memPtr);
  }
}


// ========================================================================
// ?RD_EventBegin@@YAXPBD@Z
// EA  : 0x82F81B98
// RVA : 0x00F81B98
// PDB : w:\tech5\shared\idlib\sys\sys_mgrd.cpp
// ========================================================================

void __fastcall RD_EventBegin(const char *name)
{
  RD_Init();
  if ( rdInit == 1 )
    rd_event_begin(name);
}


// ========================================================================
// ?RD_EventEnd@@YAXXZ
// EA  : 0x82F81BE0
// RVA : 0x00F81BE0
// PDB : w:\tech5\shared\idlib\sys\sys_mgrd.cpp
// ========================================================================

void __fastcall RD_EventEnd()
{
  RD_Init();
  if ( rdInit == 1 )
    rd_event_end();
}


// ========================================================================
// ?RD_Syncpoint@@YAXPBD@Z
// EA  : 0x82F81C18
// RVA : 0x00F81C18
// PDB : w:\tech5\shared\idlib\sys\sys_mgrd.cpp
// ========================================================================

void __fastcall RD_Syncpoint(const char *name)
{
  RD_Init();
  if ( rdInit == 1 )
    rd_event_oneshot(name);
}


// ========================================================================
// ?Print@idRDPrintListener@@UAAXPBD@Z
// EA  : 0x82F81C60
// RVA : 0x00F81C60
// PDB : w:\tech5\shared\idlib\sys\sys_mgrd.cpp
// ========================================================================

void __fastcall idRDPrintListener::Print(idRDPrintListener *this, const char *msg)
{
  if ( rdInit == 1 )
    rd_msg(text: msg);
}


// ========================================================================
// `dynamic initializer for 'rdPrintListener''
// EA  : 0x83396C00
// RVA : 0x01396C00
// PDB : w:\tech5\shared\idlib\sys\sys_mgrd.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rdPrintListener__()
{
  idPrintListener::RegisterPrintListener(this: &rdPrintListener);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rdPrintListener__);
}


// ========================================================================
// __unwind$114048
// EA  : 0x83396C40
// RVA : 0x01396C40
// PDB : w:\tech5\shared\idlib\sys\sys_mgrd.cpp
// ========================================================================

void _unwind_114048()
{
  idPrintListener::~idPrintListener(this: (idCommonLocal::idRefreshOnPrint *)&rdPrintListener);
}

