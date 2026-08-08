
// ========================================================================
// ?Indent@idRenderLog@@QAAXW4renderLogIndentLabel_t@@@Z
// EA  : 0x828D9550
// RVA : 0x008D9550
// PDB : w:\tech5\engine\renderer\renderlog.h
// ========================================================================

void __fastcall idRenderLog::Indent(idRenderLog *this, renderLogIndentLabel_t label)
{
  int v2; // r10

  if ( this->logFile != nullptr )
  {
    this->indentLabel[this->indentLevel] = label;
    v2 = this->indentLevel + 1;
    this->indentLevel = v2;
    HIBYTE(this->indentLabel[v2 + 19]) = 32;
    BYTE1(this->indentLabel[this->indentLevel + 19]) = 32;
    BYTE2(this->indentLabel[this->indentLevel + 19]) = 32;
    LOBYTE(this->indentLabel[this->indentLevel + 19]) = 32;
    this->indentString[4 * this->indentLevel] = 0;
  }
}


// ========================================================================
// ?OpenBlock@idRenderLog@@QAAXPBDZZ
// EA  : 0x828D9F88
// RVA : 0x008D9F88
// PDB : w:\tech5\engine\renderer\renderlog.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idRenderLog::OpenBlock(
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
  if ( this->logFile != nullptr )
    idRenderLog::LogOpenBlock(this, label: RENDER_LOG_INDENT_BLOCK, fmt, args: va);
}

