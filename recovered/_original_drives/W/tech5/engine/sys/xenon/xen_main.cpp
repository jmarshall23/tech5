
// ========================================================================
// ?DebugConsoleCmdProcessor@@YAJPBDPADKPAU_DM_CMDCONT@@@Z
// EA  : 0x829DA2C0
// RVA : 0x009DA2C0
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

HRESULT __fastcall DebugConsoleCmdProcessor(
        const char *szCommand,
        char *szResponse,
        unsigned int cchResponse,
        _DM_CMDCONT *pdmcc)
{
  cmdSystem->AppendCommandText(this: cmdSystem, a2: szCommand);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: "\n");
  return 0;
}


// ========================================================================
// `main'::`2'::idSysPrint::Print
// EA  : 0x829DA320
// RVA : 0x009DA320
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void __fastcall _main_::_2_::idSysPrint::Print(const char *text, const char *a2)
{
  OutputDebugStringA(lpOutputString: a2);
}


// ========================================================================
// ?Sys_ReLaunch@@YAXPAXI@Z
// EA  : 0x829DA328
// RVA : 0x009DA328
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void __fastcall Sys_ReLaunch(void *data, DWORD dataSize)
{
  NTSTATUS v2; // r4

  if ( data != nullptr && dataSize < 0x3FC )
  {
    v2 = XSetLaunchData(launchData: data, cbLaunchData: dataSize);
    if ( v2 != 0 )
      idLib::Warning(fmt: "XSetLaunchData ret error: %d", v2);
  }
  xen.launchDetected = true;
}


// ========================================================================
// ?Sys_IsFileWritable@@YA_NPBD@Z
// EA  : 0x829DA380
// RVA : 0x009DA380
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

BOOL __fastcall Sys_IsFileWritable(const char *path)
{
  _stat64 v2; // [sp+50h] [-40h] BYREF

  return stat64(name: path, buf: &v2) == -1 || (v2.st_mode & 0x80) != 0;
}


// ========================================================================
// ?Sys_DefaultDevStoragePath@@YAPBDXZ
// EA  : 0x829DA3C8
// RVA : 0x009DA3C8
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

const char *__fastcall Sys_DefaultDevStoragePath()
{
  return "saves:\\";
}


// ========================================================================
// ?Sys_DefaultCachePath@@YAPBDXZ
// EA  : 0x829DA3D8
// RVA : 0x009DA3D8
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

const char *__fastcall Sys_DefaultCachePath()
{
  return "CACHE:\\";
}


// ========================================================================
// ?Sys_EXEPath@@YAPBDXZ
// EA  : 0x829DA3E8
// RVA : 0x009DA3E8
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

const char *__fastcall Sys_EXEPath()
{
  return "GAME:\\";
}


// ========================================================================
// ?Sys_IsFolder@@YA?AW4sysFolder_t@@PBD@Z
// EA  : 0x829DA3F8
// RVA : 0x009DA3F8
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

int __fastcall Sys_IsFolder(const char *path)
{
  _stat64i32 v2; // [sp+50h] [-40h] BYREF

  if ( stat64i32(name: path, buf: &v2) >= 0 )
    return (v2.st_mode & 0x4000) != 0;
  else
    return -1;
}


// ========================================================================
// ?Sys_DLL_Load@@YAIPBD@Z
// EA  : 0x829DA440
// RVA : 0x009DA440
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

// attributes: thunk
HINSTANCE__ *__fastcall Sys_DLL_Load(const char *dllName)
{
  return LoadLibraryA(lpLibFileName: dllName);
}


// ========================================================================
// ?Sys_DLL_GetProcAddress@@YAPAXIPBD@Z
// EA  : 0x829DA448
// RVA : 0x009DA448
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

// attributes: thunk
int (*__fastcall Sys_DLL_GetProcAddress(HINSTANCE__ *dllHandle, const char *procName))(...)
{
  return GetProcAddress(hModule: dllHandle, lpProcName: procName);
}


// ========================================================================
// ?Sys_DLL_Unload@@YAXI@Z
// EA  : 0x829DA450
// RVA : 0x009DA450
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void __fastcall Sys_DLL_Unload(HINSTANCE__ *dllHandle)
{
  if ( dllHandle != nullptr && FreeLibrary(hLibModule: dllHandle) == 0 )
    idLib::Error(fmt: "Sys_DLL_Unload: FreeLibrary failed");
}


// ========================================================================
// ?Sys_GetProcessorId@@YA?AW4cpuid_t@@XZ
// EA  : 0x829DA490
// RVA : 0x009DA490
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

int __fastcall Sys_GetProcessorId()
{
  return 65552;
}


// ========================================================================
// ?Sys_GetProcessorString@@YAPBDXZ
// EA  : 0x829DA4A0
// RVA : 0x009DA4A0
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

const char *__fastcall Sys_GetProcessorString()
{
  return "Xenon";
}


// ========================================================================
// ?Xen_StartNotifications@@YAXXZ
// EA  : 0x829DA4B0
// RVA : 0x009DA4B0
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void __fastcall Xen_StartNotifications(unsigned __int64 a1)
{
  int v1; // [sp+50h] [-10h] BYREF

  HIDWORD(a1) = 239;
  v1 = 1;
  xenListener = XNotifyCreateListener(qwAreas: a1);
  if ( XMPTitleHasPlaybackControl(pfHasPlaybackControl: &v1) == 0 && v1 == 0 )
    soundSystem->MuteBackgroundMusic(this: soundSystem, a2: true);
}


// ========================================================================
// ?Sys_Milliseconds@@YAHXZ
// EA  : 0x829DA520
// RVA : 0x009DA520
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

unsigned int __fastcall Sys_Milliseconds()
{
  if ( (_S13_33 & 1) == 0 )
  {
    _S13_33 |= 1u;
    sys_timeBase = GetTickCount();
  }
  return GetTickCount() - sys_timeBase;
}


// ========================================================================
// ?Sys_Microseconds@@YA_KXZ
// EA  : 0x829DA578
// RVA : 0x009DA578
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned __int64 __fastcall Sys_Microseconds()
{
  unsigned __int64 v0; // r10
  unsigned __int64 v1; // r11
  int HighPart; // r9
  int v3; // r8
  unsigned __int64 v4; // r10
  int v5; // r11
  __int64 v6; // r5
  unsigned __int64 result; // r4 OVERLAPPED
  _LARGE_INTEGER v8; // [sp+50h] [-30h] BYREF
  _LARGE_INTEGER v9; // [sp+58h] [-28h] BYREF

  if ( (_DWORD)ticksPerMicrosecondTimes1024 == 0 )
  {
    QueryPerformanceFrequency(lpFrequency: &v8);
    HIDWORD(v0) = v8.LowPart;
    LODWORD(v0) = 1000000;
    ticksPerMicrosecondTimes1024 = (v8.QuadPart << 10) / v0;
    QueryPerformanceCounter(lpPerformanceCount: &v8);
    HIDWORD(v1) = v8.LowPart;
    LODWORD(v1) = __ROL4__(v8.HighPart, 32) - v8.HighPart + v8.LowPart;
    timeBase = v1;
  }
  QueryPerformanceCounter(lpPerformanceCount: &v9);
  HighPart = v9.HighPart;
  v3 = __ROL4__(v9.HighPart, 32);
  __tdllei(__PAIR64__(v9.HighPart, ticksPerMicrosecondTimes1024), 0);
  LODWORD(v4) = HIDWORD(timeBase);
  v5 = v3 - HighPart - timeBase;
  HIDWORD(v4) = v9.LowPart;
  LODWORD(v6) = v5 + v9.LowPart;
  result = v6 << 10;
  *(unsigned __int64 *)((char *)&result + 4) = result / v4;
  return result;
}


// ========================================================================
// ?Sys_CPUCount@@YAXAAH00@Z
// EA  : 0x829DA638
// RVA : 0x009DA638
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void __fastcall Sys_CPUCount(int *numLogicalCPUCores, int *numPhysicalCPUCores, int *numCPUPackages)
{
  *numPhysicalCPUCores = 3;
  *numLogicalCPUCores = 6;
  *numCPUPackages = 1;
}


// ========================================================================
// ?Sys_GetClockTicks@@YA_JXZ
// EA  : 0x829DA658
// RVA : 0x009DA658
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall Sys_GetClockTicks()
{
  __int128 v0; // r11
  __int64 v1; // r5
  __int64 result; // r4 OVERLAPPED
  _LARGE_INTEGER v3; // [sp+50h] [-10h] BYREF

  QueryPerformanceCounter(lpPerformanceCount: &v3);
  HIDWORD(v0) = __ROL4__(v3.HighPart, 32) - v3.HighPart;
  DWORD1(v0) = HIDWORD(cpuCyclesPerSecond);
  LODWORD(v1) = HIDWORD(v0) + HIDWORD(cpuCyclesPerSecond);
  *((_QWORD *)&v0 + 1) = clockTicksPerSecond;
  result = v1 * *(_QWORD *)((char *)&v0 + 4);
  DWORD2(v0) = __ROL4__(result, 1);
  *(__int64 *)((char *)&result + 4) = result / (__int64)v0;
  --DWORD2(v0);
  __tdllei(v0, 0);
  DWORD1(v0) = v0 & ~DWORD2(v0);
  __tdlgei(*(unsigned __int64 *)&v0, 0xFFFFFFFF);
  return result;
}


// ========================================================================
// ?Sys_ClockTicksPerSecond@@YA_JXZ
// EA  : 0x829DA6C0
// RVA : 0x009DA6C0
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

int __fastcall Sys_ClockTicksPerSecond()
{
  return cpuCyclesPerSecond;
}


// ========================================================================
// ?Sys_GetDriveFreeSpaceInBytes@@YA_JPBD@Z
// EA  : 0x829DA6D0
// RVA : 0x009DA6D0
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

unsigned int __fastcall Sys_GetDriveFreeSpaceInBytes(const char *path)
{
  unsigned int result; // r3
  bool v2; // zf
  _ULARGE_INTEGER v3; // [sp+50h] [-30h] BYREF
  _ULARGE_INTEGER v4; // [sp+58h] [-28h] BYREF
  _ULARGE_INTEGER v5[2]; // [sp+60h] [-20h] BYREF

  v2 = GetDiskFreeSpaceExA(
         lpDirectoryName: path,
         lpFreeBytesAvailableToCaller: &v3,
         lpTotalNumberOfBytes: v5,
         lpTotalNumberOfFreeBytes: &v4) != 0;
  result = v3.LowPart;
  if ( !v2 )
    return 0;
  return result;
}


// ========================================================================
// ?PrintStackTrace@idSysLocal@@UAAXXZ
// EA  : 0x829DA718
// RVA : 0x009DA718
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void __fastcall idSysLocal::PrintStackTrace(idSysLocal *this)
{
  int v1; // r31
  const void **v2; // r30
  PVOID v3[108]; // [sp+50h] [-1B0h] BYREF

  DmCaptureStackBackTrace(FramesToCapture: 0x64u, BackTrace: v3);
  idLib::Printf(fmt: "---------------- Stack Trace ----------------\n");
  v1 = 0;
  v2 = (const void **)v3;
  do
  {
    if ( *v2 == nullptr )
      break;
    idLib::Printf(fmt: "0x%p\n", *v2);
    ++v1;
    ++v2;
  }
  while ( v1 < 100 );
  idLib::Printf(fmt: "---------------- End stack trace ----------------\n");
}


// ========================================================================
// ?Sys_SetLanguageFromSystem@@YAXXZ
// EA  : 0x829DA788
// RVA : 0x009DA788
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void __fastcall Sys_SetLanguageFromSystem()
{
  int v0; // r3
  const char *v1; // r4

  v0 = XTLGetLanguage();
  switch ( v0 )
  {
    case 2:
      v1 = "japanese";
      break;
    case 11:
      v1 = "polish";
      break;
    case 4:
      v1 = "french";
      break;
    case 3:
      v1 = "german";
      break;
    case 5:
      v1 = "spanish";
      break;
    case 6:
      v1 = "italian";
      break;
    case 12:
      v1 = "russian";
      break;
    default:
      v1 = "english";
      break;
  }
  idCVar::SetString(this: &sys_lang, newValue: v1, force: true);
}


// ========================================================================
// ?Xen_HandleNotifications@@YAXXZ
// EA  : 0x829DA8B8
// RVA : 0x009DA8B8
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void __fastcall Xen_HandleNotifications()
{
  unsigned int v0; // [sp+50h] [-20h] BYREF
  unsigned int v1[3]; // [sp+54h] [-1Ch] BYREF

  if ( xenListener != nullptr )
  {
    if ( XNotifyGetNext(hNotification: xenListener, dwMsgFilter: 0, pdwId: v1, pParam: &v0) )
    {
      if ( v1[0] > 0x2000002 )
      {
        switch ( v1[0] )
        {
          case 0x2000007u:
            Xen_HandleContentInstalled();
            break;
          case 0xA000003u:
            soundSystem->MuteBackgroundMusic(this: soundSystem, a2: (_cntlzw(v0) & 0x20) != 0);
            break;
          case 0xE040002u:
            idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)1);
            break;
          default:
            break;
        }
      }
      else if ( v1[0] == 33554434 )
      {
        Xen_SessionHandleInvite(param: v0);
      }
      else if ( v1[0] > 0xB )
      {
        if ( v1[0] == 33554433 )
          Xen_HandleConnectionChanged(param: v0);
      }
      else
      {
        switch ( v1[0] )
        {
          case 0xBu:
            Xen_HandleDeviceChange();
            break;
          case 9u:
            Xen_SessionHandleSysUI(param: v0);
            break;
          case 0xAu:
            xen_signInTimeToWait = Sys_Milliseconds() + 1100;
            break;
          default:
            break;
        }
      }
    }
    if ( xen_signInTimeToWait > 0 && (int)Sys_Milliseconds() > xen_signInTimeToWait )
    {
      Xen_SessionHandleSignInChangeOccured(param: 0);
      xen_signInTimeToWait = 0;
    }
  }
}


// ========================================================================
// main
// EA  : 0x829DAA20
// RVA : 0x009DAA20
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

int __fastcall main()
{
  idCrashHandler *v0; // r3
  idCrashHandler *v1; // r3
  const char *v2; // r3
  int i; // r4
  const char *CommandLineA; // r3
  signed __int64 v5; // r4
  DWORD v7; // [sp+50h] [-480h] BYREF
  unsigned int v8; // [sp+54h] [-47Ch] BYREF
  unsigned int v9; // [sp+58h] [-478h] BYREF
  unsigned int v10; // [sp+5Ch] [-474h] BYREF
  DWORD v11[4]; // [sp+60h] [-470h] BYREF
  idPrintListener v12; // [sp+70h] [-460h] BYREF
  _LARGE_INTEGER v13; // [sp+80h] [-450h] BYREF
  char v14[1088]; // [sp+90h] [-440h] BYREF

  XMountUtilityDrive(fFormatClean: 1, dwBytesPerCluster: 0x10000u, dwCacheSize: 0x40000u);
  DmMapDevkitDrive();
  CreateDirectoryA(lpPathName: "saves:\\", lpSecurityAttributes: nullptr);
  Sys_SetCurrentThreadName(name: "Tungsten");
  QueryPerformanceFrequency(lpFrequency: &v13);
  clockTicksPerSecond = __PAIR64__(
                          (idSessionLocalXbox *)&sessionLocal.partyLobby.parms.layersDeactive.buffer[332],
                          v13.LowPart);
  if ( (_S13_33 & 1) == 0 )
  {
    _S13_33 |= 1u;
    sys_timeBase = GetTickCount();
  }
  GetTickCount();
  XEnableGuestSignin(fEnable: 0);
  v0 = (idCrashHandler *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                           size: 8u,
                           tag: TAG_NEW,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v13.HighPart = (int)v0;
  if ( v0 != nullptr )
    v1 = idCrashHandler::idCrashHandler(this: v0);
  else
    v1 = nullptr;
  v12.next = nullptr;
  v12.wantColor = false;
  v12.minSeverity = SEV_DEBUG;
  v12.__vftable = (idPrintListener_vtbl *)&`main'::`2'::idSysPrint::`vftable';
  v12.threadSafe = true;
  xen.crashHandler = v1;
  idPrintListener::RegisterPrintListener(this: &v12);
  v11[0] = 0;
  v7 = 0;
  v10 = 0;
  v9 = 0;
  v8 = 0;
  idLib::Printf(fmt: "====================================\n");
  idLib::Printf(fmt: "360 Initialization Configuration \n");
  if ( DmGetConsoleType(pdwConsoleType: v11) < 0 )
    idLib::Printf(fmt: "DmGetConsoleType Failed!\n");
  if ( DmGetConsoleFeatures(pdwConsoleFeatures: &v7) < 0 )
    idLib::Printf(fmt: "DmGetConsoleFeatures Failed!\n");
  if ( v11[0] == 0 )
  {
    if ( (v7 & 5) != 0 )
      v2 = "%25s: 1GB XDK-GB Dev Kit\n";
    else
      v2 = "%25s: 512Mb Standard Dev Kit\n";
LABEL_20:
    idLib::Printf(fmt: v2, "Console Type");
    goto LABEL_21;
  }
  if ( v11[0] != 1 )
  {
    if ( v11[0] >= 3 )
      goto LABEL_21;
    v2 = "%25s: 512Mb Standard Demo/Retail Kit\n";
    goto LABEL_20;
  }
  if ( (v7 & 4) != 0 )
    idLib::Printf(fmt: "%25s: 1GB XDK-GB Test Kit\n", "Console Type");
  else
    idLib::Printf(fmt: "%25s: 512Mb Standard Test Kit\n", "Console Type");
LABEL_21:
  if ( (v7 & 4) != 0 )
  {
    if ( DmGetConsoleDebugMemoryStatus(pdwConsoleMemConfig: &v10) < 0 )
      idLib::Printf(fmt: "DmGetConsoleDebugMemoryStatus Failed!\n");
    if ( v10 == 2 )
    {
      idLib::Printf(fmt: "%25s: ENABLED\n", "Additional Debug Memory");
      if ( DmGetDebugMemorySize(pdwDebugMemorySize: &v8) >= 0 )
        idLib::Printf(fmt: "%25s: %dMB\n", "Debug Memory Size", v8);
      else
        idLib::Printf(fmt: "DmGetDebugMemorySize Failed!\n");
      if ( DmGetAdditionalTitleMemorySetting(pdwAdditionalTitleMemory: &v9) >= 0 )
        idLib::Printf(fmt: "%25s: %dMB\n", "Additional Title Memory", v9);
      else
        idLib::Printf(fmt: "DmGetAdditionalTitleMemorySetting Failed!\n");
    }
    else
    {
      idLib::Printf(fmt: "%25s: DISABLED\n", "Additional Debug Memory");
    }
  }
  idLib::Printf(fmt: "====================================\n");
  ConvertThreadToFiber(lpParameter: nullptr);
  memset(v14, 0, 1020);
  XGetLaunchData(launchData: v14, cbLaunchData: 0x3FCu);
  for ( i = 0; v14[i] != 0; ++i )
    ;
  idLib::Printf(fmt: "360 launch data, size = %d: %s\n", i, v14);
  if ( v14[0] != 0 )
  {
    common->Init(this: common, a2: 0, a3: nullptr, a4: v14);
  }
  else
  {
    CommandLineA = GetCommandLineA();
    common->Init(this: common, a2: 0, a3: nullptr, a4: CommandLineA);
  }
  HIDWORD(v5) = DmRegisterCommandProcessor(szProcessor: "XCMD", pfn: DebugConsoleCmdProcessor);
  if ( v5 < 0 )
    idLib::Warning(fmt: "Error registering command processor");
  Xen_StartNotifications(a1: v5);
  DmSetProfilingOptions(dwFlags: 1u);
  do
    common->Frame(this: common);
  while ( !xen.launchDetected );
  XLaunchNewImage(pszImagePath: "Default.xex", dwFlags: 0);
  v12.__vftable = (idPrintListener_vtbl *)&idPrintListener::`vftable';
  idPrintListener::UnRegisterPrintListener(this: &v12);
  return 0;
}


// ========================================================================
// $M230673
// EA  : 0x829DAE74
// RVA : 0x009DAE74
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void __noreturn _M230673()
{
  BitmapConsoleFatalError(msg: idException::error);
}


// ========================================================================
// $M230676
// EA  : 0x829DAEAC
// RVA : 0x009DAEAC
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void __noreturn _M230676()
{
  BitmapConsoleFatalError(msg: idException::error);
}


// ========================================================================
// $LN75_0
// EA  : 0x829DAEDC
// RVA : 0x009DAEDC
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void __fastcall _LN75_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 1232 + 128), tag: a2);
}


// ========================================================================
// __unwind$230576
// EA  : 0x829DAF04
// RVA : 0x009DAF04
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void _unwind_230576()
{
  int v0; // r12

  idPrintListener::~idPrintListener(this: (idCommonLocal::idRefreshOnPrint *)(v0 - 1232 + 112));
}


// ========================================================================
// ?Sys_Quit@@YAXH@Z
// EA  : 0x829DAF30
// RVA : 0x009DAF30
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void __fastcall Sys_Quit(bfx::BinaryReplayLogOut *exitCode)
{
  idCrashHandler *crashHandler; // r30

  xen.systemShuttingDown = true;
  crashHandler = xen.crashHandler;
  if ( xen.crashHandler != nullptr )
  {
    idCrashHandler::~idCrashHandler(this: xen.crashHandler);
    idMem::Free(this: &mem, ptr: crashHandler, align: ALIGN_16);
    xen.crashHandler = nullptr;
  }
  idPhysics_StaticMulti::UpdateTime(this: exitCode);
  if ( xenListener != nullptr )
  {
    CloseHandle(hObject: xenListener);
    xenListener = nullptr;
  }
  DmReboot(dwFlags: 0);
}


// ========================================================================
// ?Sys_Mkdir@@YA_NPBD@Z
// EA  : 0x829DAFD0
// RVA : 0x009DAFD0
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

int __fastcall Sys_Mkdir(const char *path)
{
  idStr v2; // [sp+50h] [-30h] BYREF

  idStr::idStr(this: &v2, text: path);
  idStr::SlashesToBackSlashes(this: &v2);
  if ( CreateDirectoryA(lpPathName: v2.data, lpSecurityAttributes: nullptr) != 0 )
  {
    idStr::FreeData(this: &v2);
    return 1;
  }
  else
  {
    idStr::FreeData(this: &v2);
    return 0;
  }
}


// ========================================================================
// __unwind$230721
// EA  : 0x829DB03C
// RVA : 0x009DB03C
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void _unwind_230721()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 128 + 80));
}


// ========================================================================
// ?Sys_ListFiles@@YAXPBD0AAV?$idList@VidStr@@$04@@@Z
// EA  : 0x829DB070
// RVA : 0x009DB070
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void __fastcall Sys_ListFiles(const char *directory, char *extension, idList<idStr,5> *list)
{
  char *v3; // r30
  int v5; // r27
  void *FirstFileA; // r30
  idStr v7; // [sp+50h] [-1B0h] BYREF
  idStr v8; // [sp+70h] [-190h] BYREF
  _WIN32_FIND_DATAA v9; // [sp+90h] [-170h] BYREF

  v7.len = 0;
  v3 = extension;
  v7.allocedAndFlag = 20;
  v7.data = v7.baseBuffer;
  v7.baseBuffer[0] = 0;
  v8.allocedAndFlag = 20;
  v8.data = v8.baseBuffer;
  v8.len = 0;
  v8.baseBuffer[0] = 0;
  if ( extension == nullptr )
    v3 = &byte_8200D768;
  if ( *v3 != 47 || v3[1] != 0 )
  {
    v5 = 16;
  }
  else
  {
    v3 = &byte_8200D768;
    v5 = 0;
  }
  idStr::operator=(this: &v7, text: directory);
  idStr::SlashesToBackSlashes(this: &v7);
  idStr::Append(this: &v7, text: "\\*");
  idStr::Append(this: &v7, text: v3);
  if ( list->listStatic == 0 || list->listStatic == 2 )
  {
    if ( list->list != nullptr )
      idListArrayDelete<idStr>(ptr: list->list, num: list->size);
    list->list = nullptr;
    list->size = 0;
  }
  list->num = 0;
  FirstFileA = FindFirstFileA(lpFileName: v7.data, lpFindFileData: &v9);
  if ( FirstFileA == (void *)-1 )
  {
    GetLastError();
    idStr::FreeData(this: &v8);
  }
  else
  {
    do
    {
      if ( (v9.dwFileAttributes & 0x10) != v5 )
      {
        idStr::operator=(this: &v8, text: v9.cFileName);
        idStr::ToLower(this: &v8);
        idStr::BackSlashesToSlashes(this: &v8);
        idList<idStr,5>::Append(this: list, obj: &v8);
      }
    }
    while ( FindNextFileA(hFindFile: FirstFileA, lpFindFileData: &v9) != 0 );
    CloseHandle(hObject: FirstFileA);
    idStr::FreeData(this: &v8);
  }
  idStr::FreeData(this: &v7);
}


// ========================================================================
// __unwind$230824
// EA  : 0x829DB1F0
// RVA : 0x009DB1F0
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void _unwind_230824()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 80));
}


// ========================================================================
// __unwind$230825
// EA  : 0x829DB218
// RVA : 0x009DB218
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void _unwind_230825()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 112));
}


// ========================================================================
// `dynamic initializer for 'xen_fastCapMS''
// EA  : 0x83363E38
// RVA : 0x01363E38
// PDB : w:\tech5\engine\sys\xenon\xen_main.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__xen_fastCapMS__()
{
  idCVar::idCVar(
    this: &xen_fastCapMS,
    name: "xen_fastCapMS",
    value: "0",
    flags: 2,
    description: "When a frame time goes beyond this threshold, in MS, the frame profile info is dumped.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__xen_fastCapMS__);
}

