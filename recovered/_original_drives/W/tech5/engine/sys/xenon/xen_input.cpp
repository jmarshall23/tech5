
// ========================================================================
// Sys_InputThread
// EA  : 0x829D1798
// RVA : 0x009D1798
// PDB : w:\tech5\engine\sys\xenon\xen_input.cpp
// ========================================================================

void __fastcall Sys_InputThread(void *parm)
{
  Sys_Milliseconds();
  while ( !xen.systemShuttingDown )
  {
    if ( WaitForSingleObject(hHandle: hInputTimer, dwMilliseconds: 0x64u) != 0 )
      idLib::Printf(fmt: "Sys_InputThread: bad wait return");
    Xen_AsyncInputPoll();
  }
}


// ========================================================================
// ?Sys_StartInputThread@@YAXXZ
// EA  : 0x829D17F8
// RVA : 0x009D17F8
// PDB : w:\tech5\engine\sys\xenon\xen_input.cpp
// ========================================================================

void __fastcall Sys_StartInputThread()
{
  void *WaitableTimerA; // r3
  _LARGE_INTEGER v1; // [sp+50h] [-20h] BYREF

  WaitableTimerA = CreateWaitableTimerA(lpTimerAttributes: nullptr, bManualReset: 0, lpTimerName: nullptr);
  hInputTimer = WaitableTimerA;
  if ( WaitableTimerA == nullptr )
    idLib::Error(fmt: "Sys_StartInputThread: CreateWaitableTimer failed");
  v1.QuadPart = 0;
  SetWaitableTimer(
    hTimer: WaitableTimerA,
    lpDueTime: &v1,
    lPeriod: 8,
    pfnCompletionRoutine: nullptr,
    lpArgToCompletionRoutine: nullptr,
    fResume: 1);
  inputThreadHandle = Sys_CreateThread(
                        function: (unsigned int (__fastcall *)(void *))Sys_InputThread,
                        parms: nullptr,
                        priority: THREAD_ABOVE_NORMAL,
                        name: "Keyboard Input Thread",
                        core: CORE_0B,
                        stackSize: 0x40000,
                        suspended: false);
  if ( inputThreadHandle == 0 )
    idLib::Error(fmt: "Sys_StartInputThread: failed");
}


// ========================================================================
// ?Sys_InitInput@@YAXXZ
// EA  : 0x829D18B0
// RVA : 0x009D18B0
// PDB : w:\tech5\engine\sys\xenon\xen_input.cpp
// ========================================================================

// attributes: thunk
void __fastcall Sys_InitInput()
{
  Sys_StartInputThread();
}


// ========================================================================
// ?Mouse@idSysLocal@@UAAAAVidMouse@@XZ
// EA  : 0x829D18B8
// RVA : 0x009D18B8
// PDB : w:\tech5\engine\sys\xenon\xen_input.cpp
// ========================================================================

idMouse *__fastcall idSysLocal::Mouse(idSysLocal *this)
{
  return &mouse;
}


// ========================================================================
// `dynamic initializer for 'mouse''
// EA  : 0x83363B70
// RVA : 0x01363B70
// PDB : w:\tech5\engine\sys\xenon\xen_input.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mouse__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mouse__);
}

