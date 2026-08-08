
// ========================================================================
// ?GetClockTicks@idSysLocal@@UAA_JXZ
// EA  : 0x829BA2A8
// RVA : 0x009BA2A8
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

// attributes: thunk
__int64 __fastcall idSysLocal::GetClockTicks(idSysLocal *this)
{
  return Sys_GetClockTicks();
}


// ========================================================================
// ?ClockTicksPerSecond@idSysLocal@@UAA_JXZ
// EA  : 0x829BA2B0
// RVA : 0x009BA2B0
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

// attributes: thunk
__int64 __fastcall idSysLocal::ClockTicksPerSecond(idSysLocal *this)
{
  return Sys_ClockTicksPerSecond();
}


// ========================================================================
// ?GetProcessorId@idSysLocal@@UAA?AW4cpuid_t@@XZ
// EA  : 0x829BA2B8
// RVA : 0x009BA2B8
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

// attributes: thunk
cpuid_t __fastcall idSysLocal::GetProcessorId(idSysLocal *this)
{
  return Sys_GetProcessorId();
}


// ========================================================================
// ?GetProcessorString@idSysLocal@@UAAPBDXZ
// EA  : 0x829BA2C0
// RVA : 0x009BA2C0
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

// attributes: thunk
const char *__fastcall idSysLocal::GetProcessorString(idSysLocal *this)
{
  return Sys_GetProcessorString();
}


// ========================================================================
// ?FPU_GetState@idSysLocal@@UAAPBDXZ
// EA  : 0x829BA2C8
// RVA : 0x009BA2C8
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

// attributes: thunk
const char *__fastcall idSysLocal::FPU_GetState(idSysLocal *this, int a2)
{
  return idSession::GetContentPackagePath((idSession *)this, contentIndex: a2);
}


// ========================================================================
// ?FPU_StackIsEmpty@idSysLocal@@UAA_NXZ
// EA  : 0x829BA2D0
// RVA : 0x009BA2D0
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

// attributes: thunk
int __fastcall idSysLocal::FPU_StackIsEmpty(idSysLocal *this)
{
  return XGComparePixelShaders();
}


// ========================================================================
// ?DLL_Load@idSysLocal@@UAAIPBD@Z
// EA  : 0x829BA2D8
// RVA : 0x009BA2D8
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

unsigned int __fastcall idSysLocal::DLL_Load(idSysLocal *this, const char *dllName)
{
  return Sys_DLL_Load(dllName);
}


// ========================================================================
// ?DLL_GetProcAddress@idSysLocal@@UAAPAXIPBD@Z
// EA  : 0x829BA2E0
// RVA : 0x009BA2E0
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

void *__fastcall idSysLocal::DLL_GetProcAddress(idSysLocal *this, unsigned int dllHandle, const char *procName)
{
  return Sys_DLL_GetProcAddress(dllHandle, procName);
}


// ========================================================================
// ?DLL_Unload@idSysLocal@@UAAXI@Z
// EA  : 0x829BA2F0
// RVA : 0x009BA2F0
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

void __fastcall idSysLocal::DLL_Unload(idSysLocal *this, unsigned int dllHandle)
{
  Sys_DLL_Unload(dllHandle);
}


// ========================================================================
// ?DLL_GetFileName@idSysLocal@@UAAXPBDPADH@Z
// EA  : 0x829BA2F8
// RVA : 0x009BA2F8
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

void __fastcall idSysLocal::DLL_GetFileName(idSysLocal *this, const char *baseName, char *dllName, int maxLength)
{
  idStr::snPrintf(dest: dllName, size: maxLength, fmt: "%s.xex", baseName);
}


// ========================================================================
// ?SetClipboardData@idSysLocal@@UAAXPBD@Z
// EA  : 0x829BA318
// RVA : 0x009BA318
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

void __fastcall idSysLocal::SetClipboardData(idSysLocal *this, bfx::BinaryReplayLogOut *data)
{
  idPhysics_StaticMulti::UpdateTime(this: data);
}


// ========================================================================
// ?Milliseconds@idSysLocal@@UAAHXZ
// EA  : 0x829BA320
// RVA : 0x009BA320
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

// attributes: thunk
int __fastcall idSysLocal::Milliseconds(idSysLocal *this)
{
  return Sys_Milliseconds();
}


// ========================================================================
// ?GetLocalUserName@idSession@@UBAPBDH@Z
// EA  : 0x829BA328
// RVA : 0x009BA328
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

// attributes: thunk
const char *__fastcall idSession::GetLocalUserName(idSysLocal *this)
{
  return Sys_GetOSUserName();
}


// ========================================================================
// ?GetMachineName@idSysLocal@@UAAPBDXZ
// EA  : 0x829BA330
// RVA : 0x009BA330
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

// attributes: thunk
const char *__fastcall idSysLocal::GetMachineName(idSysLocal *this)
{
  return Sys_GetMachineName();
}


// ========================================================================
// ?QueueEvent@idSysLocal@@UAAXW4sysEventType_t@@HHHPAXH@Z
// EA  : 0x829BA338
// RVA : 0x009BA338
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

void __fastcall idSysLocal::QueueEvent(
        idSysLocal *this,
        sysEventType_t type,
        int value,
        int value2,
        int ptrLength,
        void *ptr,
        int inputDeviceNum)
{
  int v9; // r11
  _DWORD *v14; // r31
  void *v15; // r4

  v9 = eventHead;
  v14 = (_DWORD *)((char *)eventQue + 8 * (eventHead & 0x127) + 8 * ((2 * (_WORD)eventHead) & 0x24E));
  if ( eventHead - eventTail >= 296 )
  {
    idLib::Printf(fmt: "idSysLocal::QueueEvent: overflow\n");
    v15 = (void *)v14[4];
    if ( v15 != nullptr )
    {
      idMem::Free(this: &mem, ptr: v15, align: ALIGN_16);
      v14[4] = 0;
    }
    v9 = eventHead;
    ++eventTail;
  }
  *v14 = type;
  v14[1] = value;
  eventHead = v9 + 1;
  v14[2] = value2;
  v14[3] = ptrLength;
  v14[4] = ptr;
  v14[5] = inputDeviceNum;
}


// ========================================================================
// ?ClearEvents@idSysLocal@@UAAXXZ
// EA  : 0x829BA408
// RVA : 0x009BA408
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

void __fastcall idSysLocal::ClearEvents(idSysLocal *this)
{
  eventTail = 0;
  eventHead = 0;
}


// ========================================================================
// ?GetEvent@idSysLocal@@UAA?AUsysEvent_t@@XZ
// EA  : 0x829BA428
// RVA : 0x009BA428
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

idSysLocal *__fastcall idSysLocal::GetEvent(idSysLocal *this, sysEvent_t *result)
{
  idSysLocal *v2; // r7
  int v3; // ctr
  int *p_inputDevice; // r11
  int v5; // r11
  __int64 v6; // r11
  int i; // ctr
  char back_chain; // [sp+0h] [-20h] BYREF
  __int64 v10; // [sp+8h] [-18h]
  __int64 v11; // [sp+10h] [-10h]

  if ( eventHead <= eventTail )
  {
    v5 = 0;
    HIDWORD(v6) = this - 1;
    v10 = v6;
    v11 = v6;
    LODWORD(v6) = &back_chain - 4;
    for ( i = 6; i != 0; --i )
    {
      LODWORD(v6) = v6 + 4;
      HIDWORD(v6) += 4;
      *(_DWORD *)HIDWORD(v6) = *(_DWORD *)v6;
    }
  }
  else
  {
    ++eventTail;
    v2 = this - 1;
    v3 = 6;
    p_inputDevice = &eventQue[((eventTail - 1) & 0x127) - 1].inputDevice;
    do
    {
      ++p_inputDevice;
      ++v2;
      v2->__vftable = (idSysLocal_vtbl *)*p_inputDevice;
      --v3;
    }
    while ( v3 != 0 );
  }
  return this;
}


// ========================================================================
// `dynamic initializer for 'sysLocal''
// EA  : 0x83362B70
// RVA : 0x01362B70
// PDB : w:\tech5\engine\sys\sys_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__sysLocal__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__sysLocal__);
}

