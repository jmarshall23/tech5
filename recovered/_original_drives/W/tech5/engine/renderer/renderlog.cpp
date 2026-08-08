
// ========================================================================
// ?Close@idRenderLog@@QAAXXZ
// EA  : 0x829445E8
// RVA : 0x009445E8
// PDB : w:\tech5\engine\renderer\renderlog.cpp
// ========================================================================

void __fastcall idRenderLog::Close(idRenderLog *this)
{
  _iobuf *logFile; // r3

  logFile = this->logFile;
  if ( logFile != nullptr )
  {
    fclose(stream: logFile);
    this->logFile = nullptr;
    this->lastMainBlock = MRB_NONE;
    this->activeLevel = 0;
    idLib::Printf(fmt: "Closed log file.\n");
  }
}


// ========================================================================
// ?Printf@idRenderLog@@QAAXPBDZZ
// EA  : 0x82944640
// RVA : 0x00944640
// PDB : w:\tech5\engine\renderer\renderlog.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idRenderLog::Printf(
        idRenderLog *this,
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
  _iobuf *logFile; // r3
  __int64 v14; // [sp+90h] [+20h] BYREF
  va_list va; // [sp+90h] [+20h]
  __int64 v16; // [sp+98h] [+28h]
  __int64 v17; // [sp+A0h] [+30h]
  __int64 v18; // [sp+A8h] [+38h]
  __int64 v19; // [sp+B0h] [+40h]
  __int64 v20; // [sp+B8h] [+48h]
  va_list va1; // [sp+C0h] [+50h] BYREF

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
  v14 = *(__int64 *)((char *)&a3 + 4);
  v16 = a3;
  v17 = *(__int64 *)((char *)&a4 + 4);
  v18 = a4;
  v19 = *(__int64 *)((char *)&a5 + 4);
  v20 = a5;
  if ( this->activeLevel > 1 )
  {
    logFile = this->logFile;
    if ( logFile != nullptr )
    {
      fprintf(str: logFile, format: "%s", this->indentString);
      vfprintf(str: this->logFile, format: fmt, ap: va);
      fflush(stream: this->logFile);
    }
  }
}


// ========================================================================
// ?LogOpenBlock@idRenderLog@@AAAXW4renderLogIndentLabel_t@@PBDPAD@Z
// EA  : 0x829446D0
// RVA : 0x009446D0
// PDB : w:\tech5\engine\renderer\renderlog.cpp
// ========================================================================

void __fastcall idRenderLog::LogOpenBlock(idRenderLog *this, renderLogIndentLabel_t label, const char *fmt, char *args)
{
  unsigned __int64 v7; // r4
  _iobuf *logFile; // r30
  unsigned __int64 v9; // r29
  int logLevel; // r4
  wrapperStats_t *CurrentStats; // r3
  char *v12; // r10
  int *p_c_drawVertices; // r11
  int i; // ctr
  int v15; // r8
  int v16; // r7
  double v17; // [sp+28h] [-B8h]
  char v18; // [sp+4Ch] [-94h] BYREF
  int v19; // [sp+68h] [-78h]
  int v20; // [sp+6Ch] [-74h]
  wrapperStats_t v21[2]; // [sp+80h] [-60h] BYREF

  HIDWORD(v9) = fmt;
  v7 = Sys_Microseconds();
  logFile = this->logFile;
  LODWORD(v9) = HIDWORD(v7);
  if ( logFile != nullptr )
  {
    HIDWORD(v7) -= LODWORD(this->closeBlockTime);
    if ( HIDWORD(v7) >= 0x3E8 )
    {
      v17 = (float)((float)_u64tod(a1: HIDWORD(v7), a2: v7) * (float)0.001);
      fprintf(str: logFile, format: "%s%1.1f msec gap from last closeblock\n", (const char *)HIDWORD(v17), v17);
    }
    fprintf(str: this->logFile, format: "%s", this->indentString);
    vfprintf(str: this->logFile, format: (const char *)HIDWORD(v9), ap: args);
    fprintf(str: this->logFile, format: " {\n");
  }
  idRenderLog::Indent(this, label);
  logLevel = this->logLevel;
  if ( logLevel >= 20 )
    idLib::Warning(fmt: "logLevel %d >= MAX_LOG_LEVELS", logLevel);
  CurrentStats = GL_GetCurrentStats(result: v21);
  v12 = &v18;
  p_c_drawVertices = &CurrentStats[-1].c_drawVertices;
  for ( i = 9; i != 0; --i )
  {
    ++p_c_drawVertices;
    v12 += 4;
    *(_DWORD *)v12 = *p_c_drawVertices;
  }
  v15 = v19;
  v16 = v20;
  this->logStats[this->logLevel % 20].startTiming = v9;
  this->logStats[this->logLevel % 20].startDraws = v15;
  this->logStats[this->logLevel++ % 20].startIndexes = v16;
}


// ========================================================================
// ?LogCloseBlock@idRenderLog@@AAAXW4renderLogIndentLabel_t@@@Z
// EA  : 0x82944878
// RVA : 0x00944878
// PDB : w:\tech5\engine\renderer\renderlog.cpp
// ========================================================================

void __fastcall idRenderLog::LogCloseBlock(idRenderLog *this, renderLogIndentLabel_t label)
{
  unsigned __int64 v3; // r3
  _iobuf *logFile; // r9
  int v5; // r11
  idRenderLog::logStats_t *v6; // r30
  int indentLevel; // r11
  int v8; // r11
  int v9; // r4
  wrapperStats_t *CurrentStats; // r3
  char *v11; // r10
  int *p_c_drawVertices; // r11
  int i; // ctr
  unsigned __int64 closeBlockTime; // r29
  double v15; // fp30
  int v16; // r4
  double v17; // fp1
  char v18; // [sp+4Ch] [-94h] BYREF
  wrapperStats_t v19; // [sp+80h] [-60h] BYREF

  LODWORD(v3) = Sys_Microseconds() >> 32;
  logFile = this->logFile;
  v5 = this->logLevel - 1;
  this->closeBlockTime = v3;
  this->logLevel = v5;
  v6 = &this->logStats[v5 % 20];
  if ( logFile != nullptr )
  {
    indentLevel = this->indentLevel;
    if ( indentLevel > 0 )
    {
      v8 = indentLevel - 1;
      this->indentLevel = v8;
      this->indentString[4 * v8] = 0;
    }
  }
  if ( this->logFile != nullptr )
  {
    CurrentStats = GL_GetCurrentStats(result: &v19);
    v11 = &v18;
    p_c_drawVertices = &CurrentStats[-1].c_drawVertices;
    for ( i = 9; i != 0; --i )
    {
      ++p_c_drawVertices;
      v11 += 4;
      *(_DWORD *)v11 = *p_c_drawVertices;
    }
    closeBlockTime = this->closeBlockTime;
    v15 = (float)((float)_u64tod(a1: (int)closeBlockTime - LODWORD(v6->startTiming), a2: v9) * (float)0.001);
    v17 = _u64tod(a1: (int)closeBlockTime - LODWORD(this->frameStartTime), a2: v16);
    fprintf(
      str: this->logFile,
      format: "%s} %i  time: %1.1f  section msec: %1.1f  section draws: %i  section triangles: %i\n",
      this->indentString,
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v17 * (float)0.001))),
      (float)((float)v17 * (float)0.001),
      v15,
      (unsigned int)COERCE_UNSIGNED_INT64((float)((float)v17 * (float)0.001)),
      LODWORD(v15));
    fflush(stream: this->logFile);
  }
}


// ========================================================================
// ?StartFrame@idRenderLog@@QAAXXZ
// EA  : 0x829449D0
// RVA : 0x009449D0
// PDB : w:\tech5\engine\renderer\renderlog.cpp
// ========================================================================

void __fastcall idRenderLog::StartFrame(idRenderLog *this)
{
  _iobuf *logFile; // r3
  _iobuf *v3; // r3
  const tm *v4; // r3
  const char *v5; // r3
  unsigned __int64 v6; // r3
  __int64 v7; // r10
  __int64 v8; // r8
  int v9; // [sp+8h] [-178h]
  int v10; // [sp+Ch] [-174h]
  int v11; // [sp+10h] [-170h]
  int v12; // [sp+14h] [-16Ch]
  int v13; // [sp+18h] [-168h]
  int v14; // [sp+1Ch] [-164h]
  __int64 v15[2]; // [sp+50h] [-130h] BYREF
  char v16[264]; // [sp+60h] [-120h] BYREF

  if ( r_logFile.valueInteger != 0 )
  {
    this->indentLevel = 0;
    this->indentString[0] = 0;
    this->activeLevel = r_logLevel.valueInteger;
    sprintf_0(string: v16, format: "DEVKIT:\\renderlog_%04i.txt", r_logFile.valueInteger);
    common->SetRefreshOnPrint(this: common, a2: false);
    logFile = this->logFile;
    if ( logFile != nullptr )
    {
      fclose(stream: logFile);
      this->logFile = nullptr;
    }
    v3 = fopen(file: v16, mode: "wt");
    this->logFile = v3;
    if ( v3 != nullptr )
    {
      idLib::Printf(fmt: "Opened log file %s\n", v16);
      time64(timeptr: v15);
      v4 = localtime64(ptime: v15);
      v5 = asctime(tb: v4);
      fprintf(str: this->logFile, format: "// %s", v5);
      fprintf(str: this->logFile, format: "// %s\n\n", com_version.valueString.data);
      LODWORD(v6) = Sys_Microseconds() >> 32;
      this->frameStartTime = v6;
      this->closeBlockTime = __PAIR64__("Mips", v6);
      idRenderLog::OpenBlock(
        this,
        fmt: "Frame",
        a3: __SPAIR64__("Mips", v6),
        a4: v8,
        a5: v7,
        a6: v9,
        a7: v10,
        a8: v11,
        a9: v12,
        a10: v13,
        a11: v14);
    }
    else
    {
      idLib::Warning(fmt: "Failed to open logfile %s", v16);
    }
  }
}


// ========================================================================
// ?EndFrame@idRenderLog@@QAAXXZ
// EA  : 0x82944B18
// RVA : 0x00944B18
// PDB : w:\tech5\engine\renderer\renderlog.cpp
// ========================================================================

void __fastcall idRenderLog::EndFrame(idRenderLog *this)
{
  int valueInteger; // r11

  if ( this->logFile != nullptr )
  {
    idRenderLog::LogCloseBlock(this, label: RENDER_LOG_INDENT_BLOCK);
    valueInteger = r_logFile.valueInteger;
    if ( r_logFile.valueInteger == 1 )
    {
      idRenderLog::Close(this);
      valueInteger = r_logFile.valueInteger;
    }
    idCVar::SetInteger(this: &r_logFile, newValue: valueInteger - 1, force: true);
    idLib::Printf(fmt: "Frame logged (%d).\n", r_logFile.valueInteger);
  }
}


// ========================================================================
// ?OpenMainBlock@idRenderLog@@QAAXW4renderLogMainBlock_t@@@Z
// EA  : 0x82944BA0
// RVA : 0x00944BA0
// PDB : w:\tech5\engine\renderer\renderlog.cpp
// ========================================================================

void __fastcall idRenderLog::OpenMainBlock(idRenderLog *this, renderLogMainBlock_t block)
{
  _iobuf *logFile; // r11

  logFile = this->logFile;
  this->lastMainBlock = block;
  if ( logFile != nullptr )
    idRenderLog::LogOpenBlock(
      this,
      label: RENDER_LOG_INDENT_MAIN_BLOCK,
      fmt: renderLogMainBlockLabels[block],
      args: nullptr);
}


// ========================================================================
// ?CloseMainBlock@idRenderLog@@QAAXXZ
// EA  : 0x82944BD0
// RVA : 0x00944BD0
// PDB : w:\tech5\engine\renderer\renderlog.cpp
// ========================================================================

void __fastcall idRenderLog::CloseMainBlock(idRenderLog *this)
{
  _iobuf *logFile; // r11

  logFile = this->logFile;
  this->lastMainBlock = MRB_NONE;
  if ( logFile != nullptr )
    idRenderLog::LogCloseBlock(this, label: RENDER_LOG_INDENT_MAIN_BLOCK);
}


// ========================================================================
// `dynamic initializer for 'r_logLevel''
// EA  : 0x8335AE40
// RVA : 0x0135AE40
// PDB : w:\tech5\engine\renderer\renderlog.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_logLevel__()
{
  idCVar::idCVar(
    this: &r_logLevel,
    name: "r_logLevel",
    value: "2",
    flags: 2,
    description: "1 = blocks only, 2 = everything",
    valueMin: 1.0,
    valueMax: 2.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))off_82010000,
    a9: (int)"Mips",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_logLevel__);
}

