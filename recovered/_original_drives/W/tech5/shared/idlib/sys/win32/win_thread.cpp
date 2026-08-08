
// ========================================================================
// ?Sys_SetThreadName@@YAXKPBD@Z
// EA  : 0x82F82BB8
// RVA : 0x00F82BB8
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

void __fastcall Sys_SetThreadName(unsigned int threadID, const char *name)
{
  unsigned int v2[4]; // [sp+50h] [-20h] BYREF

  v2[1] = (unsigned int)name;
  v2[2] = threadID;
  v2[0] = 4096;
  v2[3] = 0;
  RaiseException(dwExceptionCode: 0x406D1388u, dwExceptionFlags: 0, nNumberOfArguments: 4u, lpArguments: v2);
}


// ========================================================================
// ?Sys_SetCurrentThreadName@@YAXPBD@Z
// EA  : 0x82F82C48
// RVA : 0x00F82C48
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

void __fastcall Sys_SetCurrentThreadName(const char *name)
{
  unsigned int CurrentThreadId; // r3

  CurrentThreadId = GetCurrentThreadId();
  Sys_SetThreadName(threadID: CurrentThreadId, name);
}


// ========================================================================
// ?Sys_CreateThread@@YAIP6AIPAX@Z0W4xthreadPriority@@PBDW4core_t@@H_N@Z
// EA  : 0x82F82C80
// RVA : 0x00F82C80
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

void *__fastcall Sys_CreateThread(
        unsigned int (__fastcall *function)(void *),
        void *parms,
        xthreadPriority priority,
        const char *name,
        unsigned int core,
        unsigned int stackSize,
        bool suspended)
{
  _DWORD *v14; // r3
  void *v15; // r31
  unsigned int LastError; // r3
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  int v20; // r4
  int v22; // [sp+8h] [-98h]
  int v23; // [sp+Ch] [-94h]
  int v24; // [sp+10h] [-90h]
  int v25; // [sp+14h] [-8Ch]
  unsigned int v26; // [sp+50h] [-50h] BYREF

  v14 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\shared\\idlib\\sys\\win32\\win_thread.cpp(68) : TAG_DEBUG",
          size: 0x20000u,
          tag: TAG_DEBUG,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  idMem::Free(this: &mem, ptr: v14, align: ALIGN_16);
  v15 = CreateThread(
          lpThreadAttributes: nullptr,
          dwStackSize: stackSize,
          lpStartAddress: function,
          lpParameter: parms,
          dwCreationFlags: !suspended ? 0 : 4,
          lpThreadId: &v26);
  if ( v15 == nullptr )
  {
    LastError = GetLastError();
    idLib::FatalError(
      fmt: __SPAIR64__("CreateThread error: %i", LastError),
      a2: v19,
      a3: v18,
      a4: v17,
      a5: v22,
      a6: v23,
      a7: v24,
      a8: v25);
  }
  Sys_SetThreadName(threadID: v26, name);
  switch ( priority )
  {
    case THREAD_HIGHEST:
      v20 = 2;
LABEL_11:
      SetThreadPriority(hThread: v15, nPriority: v20);
      break;
    case THREAD_ABOVE_NORMAL:
      v20 = 1;
      goto LABEL_11;
    case THREAD_BELOW_NORMAL:
      v20 = -1;
      goto LABEL_11;
    case THREAD_LOWEST:
      v20 = -2;
      goto LABEL_11;
    default:
      break;
  }
  XSetThreadProcessor(hThread: v15, dwProcessor: core);
  return v15;
}


// ========================================================================
// ?Sys_JoinThread@@YAXI@Z
// EA  : 0x82F82D98
// RVA : 0x00F82D98
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

void __fastcall Sys_JoinThread(void *threadHandle)
{
  if ( threadHandle != nullptr )
  {
    WaitForSingleObject(hHandle: threadHandle, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: threadHandle);
  }
}


// ========================================================================
// ?Sys_Yield@@YAXXZ
// EA  : 0x82F82DD8
// RVA : 0x00F82DD8
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

// attributes: thunk
int __fastcall Sys_Yield()
{
  return SwitchToThread();
}


// ========================================================================
// ?Sys_SignalCreate@@YAXAAPAX_N@Z
// EA  : 0x82F82DE0
// RVA : 0x00F82DE0
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

void __fastcall Sys_SignalCreate(void **handle, bool manualReset)
{
  *handle = CreateEventA(lpEventAttributes: nullptr, bManualReset: manualReset, bInitialState: 0, lpName: nullptr);
}


// ========================================================================
// ?Sys_SignalDestroy@@YAXAAPAX@Z
// EA  : 0x82F82E20
// RVA : 0x00F82E20
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

void __fastcall Sys_SignalDestroy(void **handle)
{
  CloseHandle(hObject: *handle);
}


// ========================================================================
// ?Sys_SignalRaise@@YAXAAPAX@Z
// EA  : 0x82F82E28
// RVA : 0x00F82E28
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

void __fastcall Sys_SignalRaise(void **handle)
{
  SetEvent(hEvent: *handle);
}


// ========================================================================
// ?Sys_SignalClear@@YAXAAPAX@Z
// EA  : 0x82F82E30
// RVA : 0x00F82E30
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

void __fastcall Sys_SignalClear(void **handle)
{
  ResetEvent(hEvent: *handle);
}


// ========================================================================
// ?Sys_SignalWait@@YA_NAAPAXH@Z
// EA  : 0x82F82E38
// RVA : 0x00F82E38
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

BOOL __fastcall Sys_SignalWait(void **handle, unsigned int timeout)
{
  if ( timeout == -1 )
    timeout = -1;
  return (_cntlzw(WaitForSingleObject(hHandle: *handle, dwMilliseconds: timeout)) & 0x20) != 0;
}


// ========================================================================
// ?Sys_MutexDestroy@@YAXAAPAX@Z
// EA  : 0x82F82E70
// RVA : 0x00F82E70
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

void __fastcall Sys_MutexDestroy(void **handle)
{
  if ( *handle != nullptr )
    *handle = nullptr;
}


// ========================================================================
// ?Sys_MutexLock@@YA_NAAPAX_N@Z
// EA  : 0x82F82E88
// RVA : 0x00F82E88
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

DWORD __fastcall Sys_MutexLock(PRTL_CRITICAL_SECTION *handle, bool blocking)
{
  DWORD result; // r3

  result = RtlTryEnterCriticalSection(CriticalSection: *handle);
  if ( result == 0 )
  {
    if ( !blocking )
      return result;
    RtlEnterCriticalSection(CriticalSection: *handle);
  }
  return 1;
}


// ========================================================================
// ?Sys_MutexUnlock@@YAXAAPAX@Z
// EA  : 0x82F82EE8
// RVA : 0x00F82EE8
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

void __fastcall Sys_MutexUnlock(PRTL_CRITICAL_SECTION *handle)
{
  RtlLeaveCriticalSection(CriticalSection: *handle);
}


// ========================================================================
// ?Sys_InterlockedAdd@@YAJAAJJ@Z
// EA  : 0x82F82EF0
// RVA : 0x00F82EF0
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

int __fastcall Sys_InterlockedAdd(int *value, int i)
{
  char v5; // cr34

  do
  {
    __asm
    {
      mfmsr     r9
      mtmsree   r13
      lwarx     r11, 0, r3
    }
    _R10 = i + _R11;
    __asm
    {
      stwcx.    r10, 0, r3
      mtmsree   r9
    }
  }
  while ( v5 == 0 );
  return _R11 + i;
}


// ========================================================================
// ?Sys_InterlockedCompareExchange@@YAJAAJJJ@Z
// EA  : 0x82F82F18
// RVA : 0x00F82F18
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

void *__fastcall Sys_InterlockedCompareExchange(void **ptr, void *comparand, void *exchange)
{
  char v5; // cr34

  while ( 1 )
  {
    __asm
    {
      mfmsr     r10
      mtmsree   r13
      lwarx     r11, 0, r3
    }
    if ( _R11 != comparand )
      break;
    __asm
    {
      stwcx.    r5, 0, r3
      mtmsree   r10
    }
    if ( v5 != 0 )
      return _R11;
  }
  __asm
  {
    stwcx.    r11, 0, r3
    mtmsree   r10
  }
  return _R11;
}


// ========================================================================
// ?Sys_InterlockedExchangePointer@@YAPAXAAPAXPAX@Z
// EA  : 0x82F82F50
// RVA : 0x00F82F50
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

void *__fastcall Sys_InterlockedExchangePointer(void **ptr, void *exchange)
{
  char v4; // cr34

  do
  {
    __asm
    {
      mfmsr     r10
      mtmsree   r13
      lwarx     r11, 0, r3
      stwcx.    r4, 0, r3
      mtmsree   r10
    }
  }
  while ( v4 == 0 );
  return (void *)_R11;
}


// ========================================================================
// ?Sys_MutexCreate@@YAXAAPAX@Z
// EA  : 0x82F82F70
// RVA : 0x00F82F70
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

void __fastcall Sys_MutexCreate(_RTL_CRITICAL_SECTION **handle)
{
  _RTL_CRITICAL_SECTION *v2; // r30

  v2 = (_RTL_CRITICAL_SECTION *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                  size: 0x1Cu,
                                  tag: TAG_NEW,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  RtlInitializeCriticalSection(CriticalSection: v2);
  *handle = v2;
}


// ========================================================================
// ?Sys_InterlockedIncrement@@YAJAAJ@Z
// EA  : 0x82F82FD8
// RVA : 0x00F82FD8
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

int __fastcall Sys_InterlockedIncrement(int *value)
{
  char v4; // cr34

  do
  {
    __asm
    {
      mfmsr     r10
      mtmsree   r13
      lwarx     r11, 0, r3
    }
    _R11 = _R11 + 1;
    __asm
    {
      stwcx.    r11, 0, r3
      mtmsree   r10
    }
  }
  while ( v4 == 0 );
  __lwsync();
  return _R11;
}


// ========================================================================
// ?Sys_InterlockedDecrement@@YAJAAJ@Z
// EA  : 0x82F83000
// RVA : 0x00F83000
// PDB : w:\tech5\shared\idlib\sys\win32\win_thread.cpp
// ========================================================================

int __fastcall Sys_InterlockedDecrement(int *value)
{
  char v4; // cr34

  __lwsync();
  do
  {
    __asm
    {
      mfmsr     r10
      mtmsree   r13
      lwarx     r11, 0, r3
    }
    _R11 = _R11 - 1;
    __asm
    {
      stwcx.    r11, 0, r3
      mtmsree   r10
    }
  }
  while ( v4 == 0 );
  return _R11;
}

