
// ========================================================================
// ?PushWarningInfo@idLib@@SA_NPBD0@Z
// EA  : 0x82F2E798
// RVA : 0x00F2E798
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

int __fastcall idLib::PushWarningInfo(const char *type, const char *name)
{
  int v3; // r8

  if ( (unsigned int)numWarningInfo >= 0x20 )
    return 0;
  v3 = numWarningInfo++;
  warningInfo[v3].type = type;
  warningInfo[v3].name = name;
  return 1;
}


// ========================================================================
// ?PopWarningInfo@idLib@@SAXXZ
// EA  : 0x82F2E7E0
// RVA : 0x00F2E7E0
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

static void __fastcall idLib::PopWarningInfo()
{
  --numWarningInfo;
}


// ========================================================================
// ?RegisterFatalErrorHandler@idLib@@SAXP6AXPBD@Z@Z
// EA  : 0x82F2E7F8
// RVA : 0x00F2E7F8
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

void __fastcall idLib::RegisterFatalErrorHandler(void (__fastcall *error)(const char *))
{
  idLib::fatalErrorHandler = error;
}


// ========================================================================
// ?Printf@idLib@@SAXPBDZZ
// EA  : 0x82F2E808
// RVA : 0x00F2E808
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idLib::Printf(__int64 fmt, __int64 a2, __int64 a3, __int64 a4, int a5, int a6, int a7, int a8, ...)
{
  __int64 v8; // [sp+78h] [+18h] BYREF
  va_list va; // [sp+78h] [+18h]
  __int64 v10; // [sp+80h] [+20h]
  __int64 v11; // [sp+88h] [+28h]
  __int64 v12; // [sp+90h] [+30h]
  __int64 v13; // [sp+98h] [+38h]
  __int64 v14; // [sp+A0h] [+40h]
  __int64 v15; // [sp+A8h] [+48h]
  va_list va1; // [sp+B0h] [+50h] BYREF

  va_start(va1, a8);
  va_start(va, a8);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v8 = fmt;
  v10 = *(__int64 *)((char *)&a2 + 4);
  v11 = a2;
  v12 = *(__int64 *)((char *)&a3 + 4);
  v13 = a3;
  v14 = *(__int64 *)((char *)&a4 + 4);
  v15 = a4;
  idLib::VPrintf(sev: SEV_PRINT, fmt: (const char *)HIDWORD(fmt), args: va);
}


// ========================================================================
// ?RegisterPrintListener@idPrintListener@@QAAXXZ
// EA  : 0x82F2E860
// RVA : 0x00F2E860
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

void __fastcall idPrintListener::RegisterPrintListener(idPrintListener *this)
{
  if ( this->next == nullptr )
  {
    this->next = idLib::printListener;
    idLib::printListener = this;
  }
}


// ========================================================================
// ?VPrintf@idLib@@CAXW4printSeverity_t@@PBDPAD@Z
// EA  : 0x82F2E880
// RVA : 0x00F2E880
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

void __fastcall idLib::VPrintf(int sev, const char *fmt, char *args)
{
  int v6; // r3
  unsigned int StreamFileCacheUsage; // r31
  unsigned int MemoryUsage; // r3
  signed int v9; // r3
  int v10; // r5
  _BYTE *v11; // r11
  _BYTE *v12; // r11
  _BYTE *v13; // r11
  _BYTE *v14; // r11
  __int64 v15; // r8
  __int64 v16; // r6
  __int64 v17; // r10
  int v18; // r11
  __int64 v19; // r4
  int v20; // r8
  int v21; // r31
  const char **p_name; // r30
  const char *v23; // r5
  char IsMainThread; // r29
  idPrintListener *i; // r31
  idPrintListener *j; // r31
  int v27; // [sp+8h] [-10B8h]
  int v28; // [sp+Ch] [-10B4h]
  int v29; // [sp+10h] [-10B0h]
  int v30; // [sp+14h] [-10ACh]
  _BYTE v31[16]; // [sp+70h] [-1050h] BYREF
  _QWORD v32[520]; // [sp+80h] [-1040h] BYREF

  memset(v32, 0, 4096);
  v6 = 0;
  if ( com_memStampPrints.valueInteger != 0 )
  {
    StreamFileCacheUsage = Sys_GetStreamFileCacheUsage();
    MemoryUsage = Sys_GetMemoryUsage();
    v6 = sprintf_0(
           string: (char *)v32,
           format: "[%i/%i] ",
           (MemoryUsage - StreamFileCacheUsage) >> 20,
           StreamFileCacheUsage >> 20);
  }
  else if ( com_timeStampPrints.valueInteger != 0 )
  {
    v9 = Sys_Milliseconds();
    v10 = v9;
    if ( com_timeStampPrints.valueInteger == 1 )
      v10 = v9 / 1000;
    v6 = sprintf_0(string: (char *)v32, format: "[%i] ", v10);
  }
  else if ( com_frameStampPrints.valueInteger != 0 )
  {
    sprintf_0(string: (char *)v32, format: "[%i] ", idLib::frameNumber);
    v6 = 0;
    if ( HIBYTE(v32[0]) != 0 )
    {
      v11 = v32;
      do
      {
        ++v11;
        ++v6;
      }
      while ( *v11 != 0 );
    }
  }
  switch ( sev )
  {
    case 2:
      strcpy((char *)v32 + v6, "^3WARNING: ^1");
      v6 = 0;
      if ( HIBYTE(v32[0]) != 0 )
      {
        v12 = v32;
        do
        {
          ++v12;
          ++v6;
        }
        while ( *v12 != 0 );
      }
      break;
    case 3:
      strcpy((char *)v32 + v6, "^3ERROR: ^1");
      v6 = 0;
      if ( HIBYTE(v32[0]) != 0 )
      {
        v13 = v32;
        do
        {
          ++v13;
          ++v6;
        }
        while ( *v13 != 0 );
      }
      break;
    case 4:
      strcpy((char *)v32 + v6, "^3FATAL ERROR: ^1");
      v6 = 0;
      if ( HIBYTE(v32[0]) != 0 )
      {
        v14 = v32;
        do
        {
          ++v14;
          ++v6;
        }
        while ( *v14 != 0 );
      }
      break;
    default:
      break;
  }
  if ( idStr::vsnPrintf(dest: (char *)v32 + v6, size: 4095 - v6, fmt, argptr: args) < 0 )
  {
    HIDWORD(v17) = 10;
    v18 = 0;
    strcpy((char *)&v32[511] + 6, "\n");
    if ( HIBYTE(v32[0]) != 0 )
    {
      LODWORD(v17) = v32;
      do
      {
        LODWORD(v17) = v17 + 1;
        HIDWORD(v17) = *(unsigned __int8 *)v17;
        ++v18;
      }
      while ( *(_BYTE *)v17 != 0 );
    }
    LODWORD(v17) = &unk_82380000;
    LODWORD(v19) = v18 - 1;
    HIDWORD(v19) = "The following message was truncated to %d characters:\n";
    idLib::Printf(fmt: v19, a2: v16, a3: v15, a4: v17, a5: v27, a6: v28, a7: v29, a8: v30);
  }
  if ( sev < 2 )
    goto LABEL_39;
  v20 = numWarningInfo;
  v21 = numWarningInfo - 1;
  if ( numWarningInfo - 1 >= 0 )
  {
    p_name = &warningInfo[v21 + 1].name;
    while ( 1 )
    {
      v23 = " ^7while loading ";
      if ( v21 != v20 - 1 )
        v23 = " ^8from ";
      idStr::Append(dest: (char *)v32, size: 4096, src: v23);
      idStr::Append(dest: (char *)v32, size: 4096, src: *(p_name - 3));
      idStr::Append(dest: (char *)v32, size: 4096, src: " ");
      p_name -= 2;
      idStr::Append(dest: (char *)v32, size: 4096, src: *p_name);
      if ( --v21 < 0 )
        break;
      v20 = numWarningInfo;
    }
  }
  idStr::Append(dest: (char *)v32, size: 4096, src: "\n");
  if ( sev != 2 || (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)&warningsFilter) == 0 )
  {
LABEL_39:
    IsMainThread = idLib::IsMainThread();
    for ( i = idLib::printListener; i != nullptr; i = i->next )
    {
      if ( i->wantColor && (IsMainThread != 0 || i->threadSafe) && sev >= i->minSeverity )
        i->Print(this: i, a2: (const char *)v32);
    }
    idStr::RemoveColors(string: (char *)v32);
    for ( j = idLib::printListener; j != nullptr; j = j->next )
    {
      if ( !j->wantColor && (IsMainThread != 0 || j->threadSafe) && sev >= j->minSeverity )
        j->Print(this: j, a2: (const char *)v32);
    }
    if ( sev >= 3 )
    {
      if ( sev >= 4 )
      {
        if ( idLib::fatalErrorHandler != nullptr )
          idLib::fatalErrorHandler(a1: (const char *)v32);
        strncpy(dest: idException::error, source: (const char *)v32, count: 0x800u);
        CxxThrowException(pExceptionObject: v31, pThrowInfo: (const _s__ThrowInfo *)&TI1_AVidFatalException__);
      }
      strncpy(dest: idException::error, source: (const char *)v32, count: 0x800u);
      CxxThrowException(pExceptionObject: v31, pThrowInfo: (const _s__ThrowInfo *)&TI1_AVidException__);
    }
  }
}


// ========================================================================
// ?Debugf@idLib@@SAXPBDZZ
// EA  : 0x82F2ED00
// RVA : 0x00F2ED00
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idLib::Debugf(__int64 fmt, __int64 a2, __int64 a3, __int64 a4, int a5, int a6, int a7, int a8, ...)
{
  __int64 v8; // [sp+78h] [+18h] BYREF
  va_list va; // [sp+78h] [+18h]
  __int64 v10; // [sp+80h] [+20h]
  __int64 v11; // [sp+88h] [+28h]
  __int64 v12; // [sp+90h] [+30h]
  __int64 v13; // [sp+98h] [+38h]
  __int64 v14; // [sp+A0h] [+40h]
  __int64 v15; // [sp+A8h] [+48h]
  va_list va1; // [sp+B0h] [+50h] BYREF

  va_start(va1, a8);
  va_start(va, a8);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v8 = fmt;
  v10 = *(__int64 *)((char *)&a2 + 4);
  v11 = a2;
  v12 = *(__int64 *)((char *)&a3 + 4);
  v13 = a3;
  v14 = *(__int64 *)((char *)&a4 + 4);
  v15 = a4;
  idLib::VPrintf(sev: 0, fmt: (const char *)HIDWORD(fmt), args: va);
}


// ========================================================================
// ?PrintfIf@idLib@@SAX_NPBDZZ
// EA  : 0x82F2ED58
// RVA : 0x00F2ED58
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idLib::PrintfIf(
        bool condition,
        const char *fmt,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        ...)
{
  __int64 v11; // [sp+80h] [+20h] BYREF
  va_list va; // [sp+80h] [+20h]
  __int64 v13; // [sp+88h] [+28h]
  __int64 v14; // [sp+90h] [+30h]
  __int64 v15; // [sp+98h] [+38h]
  __int64 v16; // [sp+A0h] [+40h]
  __int64 v17; // [sp+A8h] [+48h]
  va_list va1; // [sp+B0h] [+50h] BYREF

  va_start(va1, a11);
  va_start(va, a11);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v11 = *(__int64 *)((char *)&a3 + 4);
  v13 = a3;
  v14 = *(__int64 *)((char *)&a4 + 4);
  v15 = a4;
  v16 = *(__int64 *)((char *)&a5 + 4);
  v17 = a5;
  if ( condition )
    idLib::VPrintf(sev: 1, fmt, args: va);
}


// ========================================================================
// ?VPrintf@idLib@@SAXPBDPAD@Z
// EA  : 0x82F2EDB8
// RVA : 0x00F2EDB8
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

void __fastcall idLib::VPrintf(const char *fmt, char *args)
{
  idLib::VPrintf(sev: 1, fmt, args);
}


// ========================================================================
// ?Warning@idLib@@SAXPBDZZ
// EA  : 0x82F2EDC8
// RVA : 0x00F2EDC8
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idLib::Warning(__int64 fmt, __int64 a2, __int64 a3, __int64 a4, int a5, int a6, int a7, int a8, ...)
{
  __int64 v8; // [sp+78h] [+18h] BYREF
  va_list va; // [sp+78h] [+18h]
  __int64 v10; // [sp+80h] [+20h]
  __int64 v11; // [sp+88h] [+28h]
  __int64 v12; // [sp+90h] [+30h]
  __int64 v13; // [sp+98h] [+38h]
  __int64 v14; // [sp+A0h] [+40h]
  __int64 v15; // [sp+A8h] [+48h]
  va_list va1; // [sp+B0h] [+50h] BYREF

  va_start(va1, a8);
  va_start(va, a8);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v8 = fmt;
  v10 = *(__int64 *)((char *)&a2 + 4);
  v11 = a2;
  v12 = *(__int64 *)((char *)&a3 + 4);
  v13 = a3;
  v14 = *(__int64 *)((char *)&a4 + 4);
  v15 = a4;
  idLib::VPrintf(sev: 2, fmt: (const char *)HIDWORD(fmt), args: va);
}


// ========================================================================
// ?WarningIf@idLib@@SAX_NPBDZZ
// EA  : 0x82F2EE20
// RVA : 0x00F2EE20
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idLib::WarningIf(
        bool condition,
        const char *fmt,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        ...)
{
  __int64 v11; // [sp+80h] [+20h] BYREF
  va_list va; // [sp+80h] [+20h]
  __int64 v13; // [sp+88h] [+28h]
  __int64 v14; // [sp+90h] [+30h]
  __int64 v15; // [sp+98h] [+38h]
  __int64 v16; // [sp+A0h] [+40h]
  __int64 v17; // [sp+A8h] [+48h]
  va_list va1; // [sp+B0h] [+50h] BYREF

  va_start(va1, a11);
  va_start(va, a11);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v11 = *(__int64 *)((char *)&a3 + 4);
  v13 = a3;
  v14 = *(__int64 *)((char *)&a4 + 4);
  v15 = a4;
  v16 = *(__int64 *)((char *)&a5 + 4);
  v17 = a5;
  if ( condition )
    idLib::VPrintf(sev: 2, fmt, args: va);
}


// ========================================================================
// ?Error@idLib@@SAXPBDZZ
// EA  : 0x82F2EE80
// RVA : 0x00F2EE80
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idLib::Error(__int64 fmt, __int64 a2, __int64 a3, __int64 a4, int a5, int a6, int a7, int a8, ...)
{
  __int64 v8; // [sp+78h] [+18h] BYREF
  va_list va; // [sp+78h] [+18h]
  __int64 v10; // [sp+80h] [+20h]
  __int64 v11; // [sp+88h] [+28h]
  __int64 v12; // [sp+90h] [+30h]
  __int64 v13; // [sp+98h] [+38h]
  __int64 v14; // [sp+A0h] [+40h]
  __int64 v15; // [sp+A8h] [+48h]
  va_list va1; // [sp+B0h] [+50h] BYREF

  va_start(va1, a8);
  va_start(va, a8);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v8 = fmt;
  v10 = *(__int64 *)((char *)&a2 + 4);
  v11 = a2;
  v12 = *(__int64 *)((char *)&a3 + 4);
  v13 = a3;
  v14 = *(__int64 *)((char *)&a4 + 4);
  v15 = a4;
  idLib::VPrintf(sev: 3, fmt: (const char *)HIDWORD(fmt), args: va);
}


// ========================================================================
// ?FatalError@idLib@@SAXPBDZZ
// EA  : 0x82F2EED8
// RVA : 0x00F2EED8
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idLib::FatalError(__int64 fmt, __int64 a2, __int64 a3, __int64 a4, int a5, int a6, int a7, int a8, ...)
{
  __int64 v8; // [sp+78h] [+18h] BYREF
  va_list va; // [sp+78h] [+18h]
  __int64 v10; // [sp+80h] [+20h]
  __int64 v11; // [sp+88h] [+28h]
  __int64 v12; // [sp+90h] [+30h]
  __int64 v13; // [sp+98h] [+38h]
  __int64 v14; // [sp+A0h] [+40h]
  __int64 v15; // [sp+A8h] [+48h]
  va_list va1; // [sp+B0h] [+50h] BYREF

  va_start(va1, a8);
  va_start(va, a8);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v8 = fmt;
  v10 = *(__int64 *)((char *)&a2 + 4);
  v11 = a2;
  v12 = *(__int64 *)((char *)&a3 + 4);
  v13 = a3;
  v14 = *(__int64 *)((char *)&a4 + 4);
  v15 = a4;
  idLib::VPrintf(sev: 4, fmt: (const char *)HIDWORD(fmt), args: va);
}


// ========================================================================
// ?UnRegisterPrintListener@idLib@@SAXPAVidPrintListener@@@Z
// EA  : 0x82F2EF30
// RVA : 0x00F2EF30
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

void __fastcall idLib::UnRegisterPrintListener(__int64 unreg, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // r11
  int v5; // [sp+8h] [-58h]
  int v6; // [sp+Ch] [-54h]
  int v7; // [sp+10h] [-50h]
  int v8; // [sp+14h] [-4Ch]

  LODWORD(a4) = idLib::printListener;
  if ( idLib::printListener == (idPrintListener *)HIDWORD(unreg) )
  {
    idLib::printListener = *(idPrintListener **)(HIDWORD(unreg) + 4);
    *(_DWORD *)(HIDWORD(unreg) + 4) = 0;
  }
  else
  {
    if ( idLib::printListener != nullptr )
    {
      while ( 1 )
      {
        v4 = *(_DWORD *)(a4 + 4);
        if ( v4 == HIDWORD(unreg) )
          break;
        LODWORD(a4) = *(_DWORD *)(a4 + 4);
        if ( v4 == 0 )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      HIDWORD(unreg) = "UnRegisterPrintListener: listener not found in list";
      idLib::FatalError(fmt: unreg, a2, a3, a4, a5: v5, a6: v6, a7: v7, a8: v8);
    }
    *(_DWORD *)(a4 + 4) = *(_DWORD *)(HIDWORD(unreg) + 4);
    *(_DWORD *)(HIDWORD(unreg) + 4) = 0;
  }
}


// ========================================================================
// ?UnRegisterPrintListener@idPrintListener@@QAAXXZ
// EA  : 0x82F2EFB8
// RVA : 0x00F2EFB8
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPrintListener::UnRegisterPrintListener(
        idPrintListener *this,
        int r4_0,
        __int64 a2,
        __int64 a3,
        __int64 a4)
{
  if ( this->next != nullptr )
    idLib::UnRegisterPrintListener(unreg: *(_QWORD *)(&this - 1), a2, a3, a4);
}


// ========================================================================
// `dynamic initializer for 'com_timeStampPrints''
// EA  : 0x83395650
// RVA : 0x01395650
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_timeStampPrints__()
{
  idCVar::idCVar(
    this: &com_timeStampPrints,
    name: "com_timeStampPrints",
    value: "0",
    flags: 2,
    description: "print time with each console print, 1 = sec, 2 = msec",
    valueMin: 0.0,
    valueMax: 2.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&unk_82380000,
    a9: (int)&loc_82660000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,2>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_timeStampPrints__);
}


// ========================================================================
// `dynamic initializer for 'com_memStampPrints''
// EA  : 0x833956B8
// RVA : 0x013956B8
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_memStampPrints__()
{
  idCVar::idCVar(
    this: &com_memStampPrints,
    name: "com_memStampPrints",
    value: "0",
    flags: 1,
    description: "print total memory usage on each console print",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_memStampPrints__);
}


// ========================================================================
// `dynamic initializer for 'com_frameStampPrints''
// EA  : 0x83395710
// RVA : 0x01395710
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_frameStampPrints__()
{
  idCVar::idCVar(
    this: &com_frameStampPrints,
    name: "com_frameStampPrints",
    value: "0",
    flags: 1,
    description: "print frame number on each console print",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_frameStampPrints__);
}


// ========================================================================
// `dynamic initializer for 'com_production''
// EA  : 0x83395768
// RVA : 0x01395768
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_production__()
{
  idCVar::idCVar(
    this: &com_production,
    name: "com_production",
    value: "0",
    flags: 2,
    description: "Used to enable and/or inhibit specific behaviour during production building mode. All demo and retail builds are bui"
    "lt with this on.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_production__);
}


// ========================================================================
// `dynamic initializer for 'com_exitProcessOnError''
// EA  : 0x833957C0
// RVA : 0x013957C0
// PDB : w:\tech5\shared\idlib\lib_print.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_exitProcessOnError__()
{
  idCVar::idCVar(
    this: &com_exitProcessOnError,
    name: "com_exitProcessOnError",
    value: "0",
    flags: 1,
    description: "Exits the process on a com_error.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_exitProcessOnError__);
}

