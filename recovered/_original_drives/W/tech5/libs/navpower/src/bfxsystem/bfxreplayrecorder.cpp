
// ========================================================================
// ?WriteReplayHeader@bfx@@YAXPAVLogDevice@1@_N1@Z
// EA  : 0x832934E0
// RVA : 0x012934E0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::WriteReplayHeader(bfx::LogDevice *pLog, bool isBinary, bool omitMoverLogging)
{
  _exception *v6; // r3
  int started; // r27
  int v8; // r26
  unsigned int SerializeType; // r3
  int v10; // r31
  const char *PlatformName; // r3
  _exception *v12; // r3
  int v13; // r3
  int v14; // [sp+8h] [-4A8h]
  double Scale; // [sp+20h] [-490h]
  unsigned int v16; // [sp+60h] [-450h] BYREF
  unsigned int v17; // [sp+64h] [-44Ch] BYREF
  unsigned int v18; // [sp+68h] [-448h] BYREF
  char v19[1088]; // [sp+70h] [-440h] BYREF

  v6 = (_exception *)XGComparePixelShaders();
  started = idLobbyBackend360::StartArbitration(pexcept: v6);
  v8 = XGComparePixelShaders();
  SerializeType = idAnimator_TorsoTracker::GetSerializeType();
  sprintf_0(
    string: v19,
    format: "<bfx_replay version=\"%u\" NavPower_version=\"%d.%d.%d\" build_number=\"%d\" binary=\"%d\" beta=\"%d\">\n",
    1,
    SerializeType,
    v8,
    started,
    11998,
    isBinary,
    v14);
  bfx::WriteString(pLog, str: v19);
  bfx::GetUpAxis();
  Scale = bfx::GetScale();
  sprintf_0(string: v19, format: "<system_params scaleDist=%.15f upAxis=%d>\n", Scale, LODWORD(Scale));
  bfx::WriteString(pLog, str: v19);
  bfx::MemoryManager::GetStats(
    this: bfx::g_pCurInstance->m_pMemoryManager,
    allocatedBytes: &v18,
    freeBytes: &v17,
    totalBytes: &v16);
  sprintf_0(string: v19, format: "<memory heapSize=\"%u\">\n", v16);
  bfx::WriteString(pLog, str: v19);
  v10 = XGComparePixelShaders();
  PlatformName = bfx::GetPlatformName();
  sprintf_0(string: v19, format: "<platform name=%s type=%d pointer_size=%d>\n", PlatformName, v10, 32);
  bfx::WriteString(pLog, str: v19);
  v13 = idLobbyBackend360::StartArbitration(pexcept: v12);
  sprintf_0(string: v19, format: "<x87_floating_point_precision precision=%.8x>\n", v13);
  bfx::WriteString(pLog, str: v19);
  sprintf_0(string: v19, format: "<omitMoverLogging=%d>\n", omitMoverLogging);
  bfx::WriteString(pLog, str: v19);
}


// ========================================================================
// ?WriteLine@TextReplayLogOut@bfx@@AAAXPBD0ZZ
// EA  : 0x83293650
// RVA : 0x01293650
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void bfx::TextReplayLogOut::WriteLine(
        bfx::TextReplayLogOut *this,
        const char *label,
        __int64 fmt,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        ...)
{
  unsigned int m_tabs; // r10
  char *v16; // r31
  unsigned int v17; // r11
  const char *v18; // r11
  int v19; // r10
  char *v20; // r31
  int v21; // r3
  char *v22; // r31
  char v23[1022]; // [sp+60h] [-420h] BYREF
  _BYTE var22[70]; // [sp+45Eh] [-22h] BYREF
  const char *v25; // [sp+4A4h] [+24h]
  __int64 v26; // [sp+4A8h] [+28h] BYREF
  va_list va; // [sp+4A8h] [+28h]
  __int64 v28; // [sp+4B0h] [+30h]
  __int64 v29; // [sp+4B8h] [+38h]
  __int64 v30; // [sp+4C0h] [+40h]
  __int64 v31; // [sp+4C8h] [+48h]
  va_list va1; // [sp+4D0h] [+50h] BYREF

  va_start(va1, a13);
  va_start(va, a13);
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
  v26 = fmt;
  v28 = *(__int64 *)((char *)&a4 + 4);
  v29 = a4;
  v30 = *(__int64 *)((char *)&a5 + 4);
  v31 = a5;
  v25 = (const char *)HIDWORD(fmt);
  if ( this->m_pLogDevice != nullptr )
  {
    m_tabs = this->m_tabs;
    v16 = v23;
    if ( this->m_tabs != 0 )
    {
      LOBYTE(v17) = 0;
      do
      {
        *v16++ = 9;
        v17 = (unsigned __int8)(v17 + 1);
      }
      while ( v17 < m_tabs );
    }
    sprintf_0(string: v16, format: "%s: ", label);
    v18 = label;
    do
      v19 = *(unsigned __int8 *)v18++;
    while ( v19 != 0 );
    v20 = &v16[v18 - label + 1];
    v21 = vsnprintf(string: v20, count: var22 - v20, format: v25, ap: va);
    if ( v21 >= 0 )
    {
      v22 = &v20[v21];
      *v22 = 10;
      v22[1] = 0;
      bfx::WriteString(pLog: this->m_pLogDevice, str: v23);
    }
  }
}


// ========================================================================
// ?WriteAttrib@TextReplayLogOut@bfx@@UAAXPBDD@Z
// EA  : 0x83293748
// RVA : 0x01293748
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::TextReplayLogOut::WriteAttrib(
        bfx::TextReplayLogOut *this,
        const char *name,
        char val,
        int a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // r6
  int v7; // [sp+8h] [-78h]
  int v8; // [sp+Ch] [-74h]
  int v9; // [sp+10h] [-70h]
  int v10; // [sp+14h] [-6Ch]
  int v11; // [sp+18h] [-68h]
  int v12; // [sp+1Ch] [-64h]
  int v13; // [sp+20h] [-60h]
  int v14; // [sp+24h] [-5Ch]

  LODWORD(v6) = val;
  HIDWORD(v6) = "%d";
  bfx::TextReplayLogOut::WriteLine(
    this,
    label: name,
    fmt: v6,
    a4: a5,
    a5: a6,
    a6: v7,
    a7: v8,
    a8: v9,
    a9: v10,
    a10: v11,
    a11: v12,
    a12: v13,
    a13: v14);
}


// ========================================================================
// ?WriteAttrib@TextReplayLogOut@bfx@@UAAXPBDF@Z
// EA  : 0x83293778
// RVA : 0x01293778
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::TextReplayLogOut::WriteAttrib(
        bfx::TextReplayLogOut *this,
        const char *name,
        __int16 val,
        int a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // r6
  int v7; // [sp+8h] [-78h]
  int v8; // [sp+Ch] [-74h]
  int v9; // [sp+10h] [-70h]
  int v10; // [sp+14h] [-6Ch]
  int v11; // [sp+18h] [-68h]
  int v12; // [sp+1Ch] [-64h]
  int v13; // [sp+20h] [-60h]
  int v14; // [sp+24h] [-5Ch]

  LODWORD(v6) = val;
  HIDWORD(v6) = "%d";
  bfx::TextReplayLogOut::WriteLine(
    this,
    label: name,
    fmt: v6,
    a4: a5,
    a5: a6,
    a6: v7,
    a7: v8,
    a8: v9,
    a9: v10,
    a10: v11,
    a11: v12,
    a12: v13,
    a13: v14);
}


// ========================================================================
// ?WriteAttrib@TextReplayLogOut@bfx@@UAAXPBDH@Z
// EA  : 0x832937A8
// RVA : 0x012937A8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::TextReplayLogOut::WriteAttrib(
        bfx::TextReplayLogOut *this,
        const char *name,
        unsigned int val,
        int a4,
        __int64 a5,
        __int64 a6)
{
  int v6; // [sp+8h] [-78h]
  int v7; // [sp+Ch] [-74h]
  int v8; // [sp+10h] [-70h]
  int v9; // [sp+14h] [-6Ch]
  int v10; // [sp+18h] [-68h]
  int v11; // [sp+1Ch] [-64h]
  int v12; // [sp+20h] [-60h]
  int v13; // [sp+24h] [-5Ch]

  bfx::TextReplayLogOut::WriteLine(
    this,
    label: name,
    fmt: __SPAIR64__("%d", val),
    a4: a5,
    a5: a6,
    a6: v6,
    a7: v7,
    a8: v8,
    a9: v9,
    a10: v10,
    a11: v11,
    a12: v12,
    a13: v13);
}


// ========================================================================
// ?WriteAttrib@TextReplayLogOut@bfx@@UAAXPBDEW4TextFormat@ReplayLogOut@2@@Z
// EA  : 0x832937D8
// RVA : 0x012937D8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::TextReplayLogOut::WriteAttrib(
        bfx::TextReplayLogOut *this,
        const char *name,
        unsigned __int8 val,
        bfx::ReplayLogOut::TextFormat fmt,
        __int64 a5,
        __int64 a6)
{
  const char *v6; // r11
  __int64 v7; // r6
  int v8; // [sp+8h] [-78h]
  int v9; // [sp+Ch] [-74h]
  int v10; // [sp+10h] [-70h]
  int v11; // [sp+14h] [-6Ch]
  int v12; // [sp+18h] [-68h]
  int v13; // [sp+1Ch] [-64h]
  int v14; // [sp+20h] [-60h]
  int v15; // [sp+24h] [-5Ch]

  if ( fmt == FMT_HEX )
    v6 = "0x%x";
  else
    v6 = "%u";
  LODWORD(v7) = val;
  HIDWORD(v7) = v6;
  bfx::TextReplayLogOut::WriteLine(
    this,
    label: name,
    fmt: v7,
    a4: a5,
    a5: a6,
    a6: v8,
    a7: v9,
    a8: v10,
    a9: v11,
    a10: v12,
    a11: v13,
    a12: v14,
    a13: v15);
}


// ========================================================================
// ?WriteAttrib@TextReplayLogOut@bfx@@UAAXPBDGW4TextFormat@ReplayLogOut@2@@Z
// EA  : 0x83293820
// RVA : 0x01293820
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::TextReplayLogOut::WriteAttrib(
        bfx::TextReplayLogOut *this,
        const char *name,
        unsigned __int16 val,
        bfx::ReplayLogOut::TextFormat fmt,
        __int64 a5,
        __int64 a6)
{
  const char *v6; // r11
  __int64 v7; // r6
  int v8; // [sp+8h] [-78h]
  int v9; // [sp+Ch] [-74h]
  int v10; // [sp+10h] [-70h]
  int v11; // [sp+14h] [-6Ch]
  int v12; // [sp+18h] [-68h]
  int v13; // [sp+1Ch] [-64h]
  int v14; // [sp+20h] [-60h]
  int v15; // [sp+24h] [-5Ch]

  if ( fmt == FMT_HEX )
    v6 = "0x%x";
  else
    v6 = "%u";
  LODWORD(v7) = val;
  HIDWORD(v7) = v6;
  bfx::TextReplayLogOut::WriteLine(
    this,
    label: name,
    fmt: v7,
    a4: a5,
    a5: a6,
    a6: v8,
    a7: v9,
    a8: v10,
    a9: v11,
    a10: v12,
    a11: v13,
    a12: v14,
    a13: v15);
}


// ========================================================================
// ?WriteAttrib@TextReplayLogOut@bfx@@UAAXPBDIW4TextFormat@ReplayLogOut@2@@Z
// EA  : 0x83293868
// RVA : 0x01293868
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::TextReplayLogOut::WriteAttrib(
        bfx::TextReplayLogOut *this,
        const char *name,
        unsigned int val,
        bfx::ReplayLogOut::TextFormat fmt,
        __int64 a5,
        __int64 a6)
{
  const char *v6; // r11
  int v7; // [sp+8h] [-78h]
  int v8; // [sp+Ch] [-74h]
  int v9; // [sp+10h] [-70h]
  int v10; // [sp+14h] [-6Ch]
  int v11; // [sp+18h] [-68h]
  int v12; // [sp+1Ch] [-64h]
  int v13; // [sp+20h] [-60h]
  int v14; // [sp+24h] [-5Ch]

  if ( fmt == FMT_HEX )
    v6 = "0x%x";
  else
    v6 = "%u";
  bfx::TextReplayLogOut::WriteLine(
    this,
    label: name,
    fmt: __SPAIR64__((unsigned int)v6, val),
    a4: a5,
    a5: a6,
    a6: v7,
    a7: v8,
    a8: v9,
    a9: v10,
    a10: v11,
    a11: v12,
    a12: v13,
    a13: v14);
}


// ========================================================================
// ?WriteAttrib@TextReplayLogOut@bfx@@UAAXPBD_N@Z
// EA  : 0x832938B0
// RVA : 0x012938B0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::TextReplayLogOut::WriteAttrib(
        bfx::TextReplayLogOut *this,
        const char *name,
        bool val,
        int a4,
        __int64 a5)
{
  __int64 v5; // r10
  __int64 v6; // r6
  int v7; // [sp+8h] [-78h]
  int v8; // [sp+Ch] [-74h]
  int v9; // [sp+10h] [-70h]
  int v10; // [sp+14h] [-6Ch]
  int v11; // [sp+18h] [-68h]
  int v12; // [sp+1Ch] [-64h]
  int v13; // [sp+20h] [-60h]
  int v14; // [sp+24h] [-5Ch]

  HIDWORD(v5) = 0x82000000;
  LODWORD(v5) = val - 1;
  LODWORD(v6) = val;
  HIDWORD(v6) = "%d";
  bfx::TextReplayLogOut::WriteLine(
    this,
    label: name,
    fmt: v6,
    a4: a5,
    a5: v5,
    a6: v7,
    a7: v8,
    a8: v9,
    a9: v10,
    a10: v11,
    a11: v12,
    a12: v13,
    a13: v14);
}


// ========================================================================
// ?WriteAttrib@TextReplayLogOut@bfx@@UAAXPBDM@Z
// EA  : 0x832938E8
// RVA : 0x012938E8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::TextReplayLogOut::WriteAttrib(
        bfx::TextReplayLogOut *this,
        const char *name,
        double val,
        int a4,
        int a5,
        __int64 a6,
        __int64 a7)
{
  int v7; // [sp+8h] [-78h]
  int v8; // [sp+Ch] [-74h]
  int v9; // [sp+10h] [-70h]
  int v10; // [sp+14h] [-6Ch]
  int v11; // [sp+18h] [-68h]
  int v12; // [sp+1Ch] [-64h]
  int v13; // [sp+20h] [-60h]
  int v14; // [sp+24h] [-5Ch]

  bfx::TextReplayLogOut::WriteLine(
    this,
    label: name,
    fmt: __SPAIR64__("%.15f", LODWORD(val)),
    a4: a6,
    a5: a7,
    a6: v7,
    a7: v8,
    a8: v9,
    a9: v10,
    a10: v11,
    a11: v12,
    a12: v13,
    a13: v14);
}


// ========================================================================
// ?WriteAttrib@TextReplayLogOut@bfx@@UAAXPBDABVBoxExtents@2@@Z
// EA  : 0x83293918
// RVA : 0x01293918
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::TextReplayLogOut::WriteAttrib(
        bfx::TextReplayLogOut *this,
        const char *name,
        const bfx::BoxExtents *val,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r8
  int v8; // [sp+8h] [-88h]
  int v9; // [sp+Ch] [-84h]
  int v10; // [sp+10h] [-80h]
  int v11; // [sp+14h] [-7Ch]
  int v12; // [sp+18h] [-78h]
  int v13; // [sp+1Ch] [-74h]
  int v14; // [sp+20h] [-70h]
  int v15; // [sp+24h] [-6Ch]
  double m_width; // [sp+30h] [-60h]
  double m_height; // [sp+38h] [-58h]

  m_height = val->m_height;
  LODWORD(v7) = LODWORD(m_height);
  m_width = val->m_width;
  HIDWORD(v7) = LODWORD(m_width);
  bfx::TextReplayLogOut::WriteLine(
    this,
    label: name,
    fmt: COERCE__INT64(val->m_length),
    a4: v7,
    a5: a7,
    a6: v8,
    a7: v9,
    a8: v10,
    a9: v11,
    a10: v12,
    a11: v13,
    a12: v14,
    a13: v15);
}


// ========================================================================
// ?WriteAttrib@TextReplayLogOut@bfx@@UAAXPBDABVQuaternion@2@@Z
// EA  : 0x83293968
// RVA : 0x01293968
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::TextReplayLogOut::WriteAttrib(
        bfx::TextReplayLogOut *this,
        const char *name,
        const bfx::Color *val)
{
  __int64 v3; // r10
  double m_g; // fp2
  int v5; // [sp+8h] [-88h]
  int v6; // [sp+Ch] [-84h]
  int v7; // [sp+10h] [-80h]
  int v8; // [sp+14h] [-7Ch]
  int v9; // [sp+18h] [-78h]
  int v10; // [sp+1Ch] [-74h]
  int v11; // [sp+20h] [-70h]
  int v12; // [sp+24h] [-6Ch]
  double m_a; // [sp+40h] [-50h]

  LODWORD(v3) = &unk_82410000;
  m_g = val->m_g;
  m_a = val->m_a;
  HIDWORD(v3) = LODWORD(m_a);
  bfx::TextReplayLogOut::WriteLine(
    this,
    label: name,
    fmt: COERCE__INT64(val->m_r),
    a4: __SPAIR64__(LODWORD(m_g), COERCE_UNSIGNED_INT64(val->m_b)),
    a5: v3,
    a6: v5,
    a7: v6,
    a8: v7,
    a9: v8,
    a10: v9,
    a11: v10,
    a12: v11,
    a13: v12);
}


// ========================================================================
// ?WriteAttrib@TextReplayLogOut@bfx@@UAAXPBD_KW4TextFormat@ReplayLogOut@2@@Z
// EA  : 0x832939C8
// RVA : 0x012939C8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::TextReplayLogOut::WriteAttrib(
        bfx::TextReplayLogOut *this,
        const char *name,
        unsigned __int64 val,
        __int64 fmt,
        __int64 a5)
{
  const char *v5; // r11
  int v6; // [sp+8h] [-78h]
  int v7; // [sp+Ch] [-74h]
  int v8; // [sp+10h] [-70h]
  int v9; // [sp+14h] [-6Ch]
  int v10; // [sp+18h] [-68h]
  int v11; // [sp+1Ch] [-64h]
  int v12; // [sp+20h] [-60h]
  int v13; // [sp+24h] [-5Ch]

  if ( (_DWORD)val == 1 )
    v5 = "0x%I64x";
  else
    v5 = "%I64u";
  bfx::TextReplayLogOut::WriteLine(
    this,
    label: name,
    fmt: __SPAIR64__((unsigned int)v5, HIDWORD(val)),
    a4: fmt,
    a5,
    a6: v6,
    a7: v7,
    a8: v8,
    a9: v9,
    a10: v10,
    a11: v11,
    a12: v12,
    a13: v13);
}


// ========================================================================
// ?WriteAttrib@TextReplayLogOut@bfx@@UAAXPBDABVString@2@@Z
// EA  : 0x83293A10
// RVA : 0x01293A10
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::TextReplayLogOut::WriteAttrib(
        bfx::TextReplayLogOut *this,
        const char *name,
        const bfx::String *val,
        int a4,
        __int64 a5)
{
  char *m_data; // r11
  int v6; // r10
  __int64 v7; // r10
  int v8; // [sp+8h] [-78h]
  int v9; // [sp+Ch] [-74h]
  int v10; // [sp+10h] [-70h]
  int v11; // [sp+14h] [-6Ch]
  int v12; // [sp+18h] [-68h]
  int v13; // [sp+1Ch] [-64h]
  int v14; // [sp+20h] [-60h]
  int v15; // [sp+24h] [-5Ch]

  HIDWORD(a5) = (bfx::String)val->m_data;
  m_data = val->m_data;
  do
    v6 = (unsigned __int8)*m_data++;
  while ( v6 != 0 );
  LODWORD(v7) = &unk_82410000;
  HIDWORD(v7) = &m_data[-HIDWORD(a5) - 1];
  bfx::TextReplayLogOut::WriteLine(
    this,
    label: name,
    fmt: __SPAIR64__("[ %d, '%s' ]", HIDWORD(v7)),
    a4: a5,
    a5: v7,
    a6: v8,
    a7: v9,
    a8: v10,
    a9: v11,
    a10: v12,
    a11: v13,
    a12: v14,
    a13: v15);
}


// ========================================================================
// ?WriteBinary@TextReplayLogOut@bfx@@UAAXPBXI@Z
// EA  : 0x83293A60
// RVA : 0x01293A60
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::TextReplayLogOut::WriteBinary(
        bfx::TextReplayLogOut *this,
        unsigned __int8 *src,
        unsigned int size)
{
  char *v6; // r11
  int v7; // r30
  unsigned int i; // r31
  unsigned int v9; // r8
  unsigned int v10; // r10
  char v11; // r10
  char v12; // r10
  _BYTE *v13; // r11
  char v14; // r10
  char v15[64]; // [sp+50h] [-1040h] BYREF

  v6 = v15;
  v7 = 0;
  for ( i = 0; i < size; ++i )
  {
    v9 = src[i];
    v10 = v9 >> 4;
    if ( v9 >> 4 >= 0xA )
      v11 = v10 + 87;
    else
      v11 = v10 + 48;
    *v6 = v11;
    v12 = v9 & 0xF;
    v13 = v6 + 1;
    if ( (v9 & 0xF) >= 0xA )
      v14 = v12 + 87;
    else
      v14 = v12 + 48;
    v7 += 2;
    *v13 = v14;
    v6 = v13 + 1;
    if ( v7 >= 128 || i == size - 1 )
    {
      *v6 = 10;
      v7 = 0;
      ++v6;
    }
    if ( (unsigned int)(v6 - v15) >= 0xFFC || i == size - 1 )
    {
      *v6 = 0;
      bfx::WriteString(pLog: this->m_pLogDevice, str: v15);
      v6 = v15;
    }
  }
}


// ========================================================================
// ?PushElement@TextReplayLogOut@bfx@@UAAXPBD@Z
// EA  : 0x83293B50
// RVA : 0x01293B50
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::TextReplayLogOut::PushElement(
        bfx::TextReplayLogOut *this,
        const char *name,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int v6; // [sp+8h] [-78h]
  int v7; // [sp+Ch] [-74h]
  int v8; // [sp+10h] [-70h]
  int v9; // [sp+14h] [-6Ch]
  int v10; // [sp+18h] [-68h]
  int v11; // [sp+1Ch] [-64h]
  int v12; // [sp+20h] [-60h]
  int v13; // [sp+24h] [-5Ch]

  HIDWORD(a3) = &byte_8200D768;
  bfx::TextReplayLogOut::WriteLine(
    this,
    label: name,
    fmt: a3,
    a4,
    a5,
    a6: v6,
    a7: v7,
    a8: v8,
    a9: v9,
    a10: v10,
    a11: v11,
    a12: v12,
    a13: v13);
  ++this->m_tabs;
}


// ========================================================================
// ?PopElement@TextReplayLogOut@bfx@@UAAXXZ
// EA  : 0x83293B90
// RVA : 0x01293B90
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::TextReplayLogOut::PopElement(bfx::TextReplayLogOut *this)
{
  --this->m_tabs;
}


// ========================================================================
// ?OpenLogEvent@TextReplayLogOut@bfx@@UAA_NW4ComponentID@2@GPBDI@Z
// EA  : 0x83293BA0
// RVA : 0x01293BA0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

int __fastcall bfx::TextReplayLogOut::OpenLogEvent(
        bfx::TextReplayLogOut *this,
        bfx::ComponentID componentID,
        unsigned __int16 eventID,
        const char *comment,
        unsigned int version)
{
  char *v9; // r31
  int v10; // r3
  double Time; // fp1
  int v13; // r3
  char v14; // [sp+50h] [-440h] BYREF
  char v15[1022]; // [sp+51h] [-43Fh] BYREF
  char v16; // [sp+44Fh] [-41h] BYREF

  v14 = 10;
  v9 = v15;
  if ( comment != nullptr && *comment != 0 )
  {
    v10 = snprintf_0(string: v15, count: 0x3FEu, format: "<!-- %s -->\n", comment);
    if ( v10 < 0 )
      return 0;
    v9 = &v15[v10];
    v15[v10] = 0;
  }
  Time = bfx::GetTime();
  v13 = snprintf_0(
          string: v9,
          count: &v16 - v9,
          format: "<event componentID=\"%1d\" eventID=\"%d\" version=\"%d\" time=\"%4.2f\">\n",
          componentID,
          eventID,
          version,
          (float)((float)Time - this->m_startTime));
  if ( v13 < 0 )
    return 0;
  v9[v13] = 0;
  bfx::WriteString(pLog: this->m_pLogDevice, str: &v14);
  return 1;
}


// ========================================================================
// ?CloseLogEvent@TextReplayLogOut@bfx@@UAAXXZ
// EA  : 0x83293C70
// RVA : 0x01293C70
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::TextReplayLogOut::CloseLogEvent(bfx::TextReplayLogOut *this)
{
  bfx::WriteString(pLog: this->m_pLogDevice, str: "</event>\n");
}


// ========================================================================
// ?WriteBinaryHeader@bfx@@YAXPAVLogDevice@1@@Z
// EA  : 0x83293C80
// RVA : 0x01293C80
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::WriteBinaryHeader(bfx::LogDevice *pLog, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r11
  int i; // ctr
  _BYTE v8[264]; // [sp+50h] [-110h] BYREF

  v6 = 0;
  for ( i = 256; i != 0; --i )
  {
    v8[v6] = v6;
    ++v6;
  }
  ((void (__fastcall *)(bfx::LogDevice *, _BYTE *, int, int, int, int, _BYTE *))pLog->WriteBuf)(
    a1: pLog,
    a2: v8,
    a3: 256,
    a4,
    a5,
    a6,
    a7: v8);
}


// ========================================================================
// ??0TextReplayLogOut@bfx@@QAA@PAVLogDevice@1@_N@Z
// EA  : 0x83293D60
// RVA : 0x01293D60
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

bfx::TextReplayLogOut *__fastcall bfx::TextReplayLogOut::TextReplayLogOut(
        bfx::TextReplayLogOut *this,
        bfx::LogDevice *pLog,
        bool omitMoverLogging)
{
  this->m_pLogDevice = pLog;
  this->m_tabs = 1;
  this->__vftable = (bfx::TextReplayLogOut_vtbl *)&bfx::TextReplayLogOut::`vftable';
  this->m_startTime = bfx::GetTime();
  bfx::WriteReplayHeader(pLog: this->m_pLogDevice, isBinary: false, omitMoverLogging);
  return this;
}


// ========================================================================
// __unwind$11454
// EA  : 0x83293DB8
// RVA : 0x01293DB8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void _unwind_11454()
{
  int v0; // r12

  bfx::ReplayListener::~ReplayListener(this: *(bfx::ReplayListener **)(v0 - 112 + 132));
}


// ========================================================================
// ??0BinaryReplayLogOut@bfx@@QAA@PAVLogDevice@1@_N@Z
// EA  : 0x83293ED0
// RVA : 0x01293ED0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

bfx::BinaryReplayLogOut *__fastcall bfx::BinaryReplayLogOut::BinaryReplayLogOut(
        bfx::BinaryReplayLogOut *this,
        bfx::LogDevice *pLog,
        bool omitMoverLogging)
{
  bfx::bfxMemTag v6; // r10
  int v7; // r8
  int v8; // r7
  int v9; // r6
  int v10; // r5
  int v11; // r4

  this->m_pLogDevice = pLog;
  this->__vftable = (bfx::BinaryReplayLogOut_vtbl *)&bfx::BinaryReplayLogOut::`vftable';
  this->m_startTime = bfx::GetTime();
  v6 = bfx::MEM_REPLAY;
  this->m_buf.m_data = nullptr;
  this->m_buf.m_size = 0;
  this->m_buf.m_cap = 0;
  this->m_buf.m_tag = v6;
  bfx::WriteReplayHeader(pLog, isBinary: true, omitMoverLogging);
  bfx::WriteBinaryHeader(pLog, a2: v11, a3: v10, a4: v9, a5: v8, a6: v7);
  return this;
}


// ========================================================================
// __unwind$11697
// EA  : 0x83293F50
// RVA : 0x01293F50
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void _unwind_11697()
{
  int v0; // r12

  bfx::ReplayListener::~ReplayListener(this: *(bfx::ReplayListener **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$11698
// EA  : 0x83293F78
// RVA : 0x01293F78
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void _unwind_11698()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 12));
}


// ========================================================================
// ??1BinaryReplayLogOut@bfx@@UAA@XZ
// EA  : 0x83293FB0
// RVA : 0x01293FB0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::BinaryReplayLogOut::~BinaryReplayLogOut(bfx::BinaryReplayLogOut *this)
{
  unsigned __int8 *m_data; // r4

  this->__vftable = (bfx::BinaryReplayLogOut_vtbl *)&bfx::BinaryReplayLogOut::`vftable';
  m_data = this->m_buf.m_data;
  this->m_buf.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)m_data);
    this->m_buf.m_data = nullptr;
  }
  this->m_buf.m_cap = 0;
  this->__vftable = (bfx::BinaryReplayLogOut_vtbl *)&bfx::ReplayListener::`vftable';
}


// ========================================================================
// __unwind$11741
// EA  : 0x83294014
// RVA : 0x01294014
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void _unwind_11741()
{
  int v0; // r12

  bfx::ReplayListener::~ReplayListener(this: *(bfx::ReplayListener **)(v0 - 112 + 132));
}


// ========================================================================
// ?Write64BitInt@BinaryReplayLogOut@bfx@@AAAXTBinary64BitVal@12@@Z
// EA  : 0x83294040
// RVA : 0x01294040
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::BinaryReplayLogOut::Write64BitInt(
        bfx::BinaryReplayLogOut *this,
        bfx::BinaryReplayLogOut::Binary64BitVal *val,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  int v11; // r3
  bfx::Array<unsigned char> *v12; // r31

  a11 = *(_QWORD *)&val;
  v12 = (bfx::Array<unsigned char> *)(v11 + 12);
  bfx::Array<unsigned char>::push_back(this: (bfx::Array<unsigned char> *)(v11 + 12), val: (unsigned __int8 *)&a11);
  bfx::Array<unsigned char>::push_back(this: v12, val: (unsigned __int8 *)&a11 + 1);
  bfx::Array<unsigned char>::push_back(this: v12, val: (unsigned __int8 *)&a11 + 2);
  bfx::Array<unsigned char>::push_back(this: v12, val: (unsigned __int8 *)&a11 + 3);
  bfx::Array<unsigned char>::push_back(this: v12, val: (unsigned __int8 *)&a11 + 4);
  bfx::Array<unsigned char>::push_back(this: v12, val: (unsigned __int8 *)&a11 + 5);
  bfx::Array<unsigned char>::push_back(this: v12, val: (unsigned __int8 *)&a11 + 6);
  bfx::Array<unsigned char>::push_back(this: v12, val: (unsigned __int8 *)&a11 + 7);
}


// ========================================================================
// ?WriteAttrib@BinaryReplayLogOut@bfx@@UAAXPBDABVString@2@@Z
// EA  : 0x832940D0
// RVA : 0x012940D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::BinaryReplayLogOut::WriteAttrib(
        bfx::BinaryReplayLogOut *this,
        const char *__formal,
        const bfx::String *val)
{
  char *m_data; // r11
  int v6; // r9
  unsigned int v7; // r29
  unsigned __int8 *v8; // r4
  unsigned __int8 v9[48]; // [sp+50h] [-30h] BYREF

  m_data = val->m_data;
  do
    v6 = (unsigned __int8)*m_data++;
  while ( v6 != 0 );
  v7 = m_data - val->m_data - 1;
  *(_DWORD *)v9 = v7;
  bfx::Array<unsigned char>::push_back(this: &this->m_buf, val: v9);
  bfx::Array<unsigned char>::push_back(this: &this->m_buf, val: &v9[1]);
  bfx::Array<unsigned char>::push_back(this: &this->m_buf, val: &v9[2]);
  bfx::Array<unsigned char>::push_back(this: &this->m_buf, val: &v9[3]);
  this->m_pLogDevice->WriteBuf(this: this->m_pLogDevice, a2: (const char *)this->m_buf.m_data, a3: this->m_buf.m_size);
  v8 = this->m_buf.m_data;
  this->m_buf.m_size = 0;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v8);
  this->m_buf.m_data = nullptr;
  this->m_buf.m_cap = 0;
  this->m_pLogDevice->WriteBuf(this: this->m_pLogDevice, a2: val->m_data, a3: v7 + 1);
}


// ========================================================================
// ?WriteBinary@BinaryReplayLogOut@bfx@@UAAXPBXI@Z
// EA  : 0x832941A8
// RVA : 0x012941A8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::BinaryReplayLogOut::WriteBinary(bfx::BinaryReplayLogOut *this, const char *src, int size)
{
  bfx::Array<unsigned char> *p_m_buf; // r30
  unsigned __int8 *m_data; // r4
  unsigned __int8 v8[48]; // [sp+50h] [-30h] BYREF

  *(_DWORD *)v8 = size;
  p_m_buf = &this->m_buf;
  bfx::Array<unsigned char>::push_back(this: &this->m_buf, val: v8);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: &v8[1]);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: &v8[2]);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: &v8[3]);
  this->m_pLogDevice->WriteBuf(this: this->m_pLogDevice, a2: (const char *)this->m_buf.m_data, a3: this->m_buf.m_size);
  m_data = this->m_buf.m_data;
  this->m_buf.m_size = 0;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)m_data);
  this->m_buf.m_data = nullptr;
  this->m_buf.m_cap = 0;
  this->m_pLogDevice->WriteBuf(this: this->m_pLogDevice, a2: src, a3: size);
}


// ========================================================================
// ?CloseLogEvent@BinaryReplayLogOut@bfx@@UAAXXZ
// EA  : 0x83294260
// RVA : 0x01294260
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::BinaryReplayLogOut::CloseLogEvent(bfx::BinaryReplayLogOut *this)
{
  bfx::Array<unsigned char> *p_m_buf; // r30
  unsigned __int8 *m_data; // r4
  unsigned __int8 v4[8]; // [sp+50h] [-20h] BYREF

  p_m_buf = &this->m_buf;
  *(_WORD *)v4 = 17767;
  bfx::Array<unsigned char>::push_back(this: &this->m_buf, val: v4);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: &v4[1]);
  this->m_pLogDevice->WriteBuf(this: this->m_pLogDevice, a2: (const char *)this->m_buf.m_data, a3: this->m_buf.m_size);
  m_data = this->m_buf.m_data;
  this->m_buf.m_size = 0;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)m_data);
  this->m_buf.m_data = nullptr;
  this->m_buf.m_cap = 0;
}


// ========================================================================
// ?Start@ReplayRecorder@bfx@@QAA_NPAVLogDevice@2@_N1@Z
// EA  : 0x83294300
// RVA : 0x01294300
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

int __fastcall bfx::ReplayRecorder::Start(
        bfx::ReplayRecorder *this,
        bfx::LogDevice *pLogDevice,
        bool binaryOut,
        bool omitMoverLogging)
{
  bfx::BinaryReplayLogOut *v7; // r3
  bfx::BinaryReplayLogOut *v8; // r11
  bfx::TextReplayLogOut *v9; // r3
  bfx::ReplayLogListenerEntry v11; // [sp+50h] [-30h] BYREF

  this->m_omitMoverLogging = omitMoverLogging;
  if ( binaryOut )
  {
    v7 = (bfx::BinaryReplayLogOut *)bfx::MemoryManager::Malloc(
                                      this: bfx::g_pCurInstance->m_pMemoryManager,
                                      size: 0x1Cu,
                                      tag: bfx::MEM_REPLAY);
    v11.m_pListener = v7;
    if ( v7 != nullptr )
      v8 = bfx::BinaryReplayLogOut::BinaryReplayLogOut(this: v7, pLog: pLogDevice, omitMoverLogging);
    else
      v8 = nullptr;
  }
  else
  {
    v9 = (bfx::TextReplayLogOut *)bfx::MemoryManager::Malloc(
                                    this: bfx::g_pCurInstance->m_pMemoryManager,
                                    size: 0x10u,
                                    tag: bfx::MEM_REPLAY);
    v11.m_pListener = v9;
    if ( v9 != nullptr )
      v8 = (bfx::BinaryReplayLogOut *)bfx::TextReplayLogOut::TextReplayLogOut(
                                        this: v9,
                                        pLog: pLogDevice,
                                        omitMoverLogging);
    else
      v8 = nullptr;
  }
  if ( v8 == nullptr )
    return 0;
  v11.m_pListener = v8;
  v11.m_clientOwned = false;
  v11.m_commandIsOpen = false;
  bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(this: &this->m_pLogListeners.m_pList, val: &v11);
  return 1;
}


// ========================================================================
// __unwind$12723
// EA  : 0x832943EC
// RVA : 0x012943EC
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void _unwind_12723()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 128 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// __unwind$12724
// EA  : 0x83294418
// RVA : 0x01294418
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void _unwind_12724()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 128 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?IsOn@ReplayRecorder@bfx@@QBA_NXZ
// EA  : 0x83294448
// RVA : 0x01294448
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

int __fastcall bfx::ReplayRecorder::IsOn(bfx::ReplayRecorder *this)
{
  bfx::ReplayLogListenerEntry *m_data; // r11
  bfx::ReplayLogListenerEntry *v2; // r10

  m_data = this->m_pLogListeners.m_pList.m_data;
  v2 = &m_data[this->m_pLogListeners.m_pList.m_size];
  if ( m_data == v2 )
    return 0;
  while ( m_data->m_pListener == nullptr || m_data->m_clientOwned )
  {
    if ( ++m_data == v2 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?Stop@ReplayRecorder@bfx@@QAAXXZ
// EA  : 0x83294498
// RVA : 0x01294498
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::ReplayRecorder::Stop(bfx::ReplayRecorder *this)
{
  bfx::Array<bfx::ReplayLogListenerEntry> *p_m_pList; // r30
  bfx::ReplayLogListenerEntry *m_data; // r31
  bfx::ReplayLogListenerEntry *v3; // r11
  unsigned int v4; // r11

  p_m_pList = &this->m_pLogListeners.m_pList;
  m_data = this->m_pLogListeners.m_pList.m_data;
  v3 = &m_data[this->m_pLogListeners.m_pList.m_size];
  if ( m_data != v3 )
  {
    while ( m_data->m_clientOwned )
    {
      if ( ++m_data == v3 )
        return;
    }
    if ( m_data->m_pListener != nullptr )
      ((void (__fastcall *)(bfx::ReplayListener *, int))m_data->m_pListener->dtr_ReplayListener)(
        a1: m_data->m_pListener,
        a2: 1);
    m_data->m_pListener = nullptr;
    m_data->m_clientOwned = true;
    v4 = (unsigned int)&p_m_pList->m_data[p_m_pList->m_size - 1];
    if ( (unsigned int)m_data < v4 )
      blkmov(a1: m_data, a2: &m_data[1], a3: 8 * (((v4 - (unsigned int)m_data - 1) >> 3) + 1));
    --p_m_pList->m_size;
  }
}


// ========================================================================
// ?OpenLogEvent@ReplayRecorder@bfx@@QAAPAVReplayLogOut@2@W4ComponentID@2@GPBDI@Z
// EA  : 0x83294578
// RVA : 0x01294578
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

bfx::ReplayRecorder *__fastcall bfx::ReplayRecorder::OpenLogEvent(
        bfx::ReplayRecorder *this,
        bfx::ComponentID componentID,
        int eventID,
        const char *comment,
        unsigned int version)
{
  bfx::Array<bfx::ReplayLogListenerEntry> *p_m_pList; // r30
  bfx::ReplayLogListenerEntry *m_data; // r31

  if ( this->m_omitMoverLogging && (componentID == COMPONENTID_SURFACE_MOVER || componentID == COMPONENTID_VOLUME_MOVER)
    || this->m_pLogListeners.m_pList.m_size == 0
    || this->m_openEvent )
  {
    return nullptr;
  }
  p_m_pList = &this->m_pLogListeners.m_pList;
  m_data = this->m_pLogListeners.m_pList.m_data;
  if ( m_data != &m_data[this->m_pLogListeners.m_pList.m_size] )
  {
    do
    {
      if ( m_data->m_pListener != nullptr )
        m_data->m_commandIsOpen = m_data->m_pListener->OpenLogEvent(
                                    this: m_data->m_pListener,
                                    a2: componentID,
                                    a3: eventID,
                                    a4: comment,
                                    a5: version);
      ++m_data;
    }
    while ( m_data != &p_m_pList->m_data[this->m_pLogListeners.m_pList.m_size] );
  }
  this->m_openEvent = true;
  return this;
}


// ========================================================================
// ?CloseLogEvent@ReplayRecorder@bfx@@QAAXXZ
// EA  : 0x83294658
// RVA : 0x01294658
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::ReplayRecorder::CloseLogEvent(bfx::ReplayRecorder *this)
{
  bfx::ReplayLogListenerEntry *m_data; // r31
  bfx::Array<bfx::ReplayLogListenerEntry> *p_m_pList; // r30

  if ( this->m_pLogListeners.m_pList.m_size != 0 && this->m_openEvent )
  {
    m_data = this->m_pLogListeners.m_pList.m_data;
    p_m_pList = &this->m_pLogListeners.m_pList;
    this->m_openEvent = false;
    if ( m_data != &m_data[this->m_pLogListeners.m_pList.m_size] )
    {
      do
      {
        if ( m_data->m_pListener != nullptr && m_data->m_commandIsOpen )
        {
          m_data->m_pListener->CloseLogEvent(this: m_data->m_pListener);
          m_data->m_commandIsOpen = false;
        }
        ++m_data;
      }
      while ( m_data != &p_m_pList->m_data[p_m_pList->m_size] );
    }
  }
}


// ========================================================================
// ?WriteAttrib@BinaryReplayLogOut@bfx@@UAAXPBDGW4TextFormat@ReplayLogOut@2@@Z
// EA  : 0x832946F8
// RVA : 0x012946F8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::BinaryReplayLogOut::WriteAttrib(
        bfx::BinaryReplayLogOut *this,
        const char *__formal,
        unsigned __int16 val,
        bfx::ReplayLogOut::TextFormat a4)
{
  bfx::Array<unsigned char> *p_m_buf; // r31
  unsigned __int8 v5[16]; // [sp+50h] [-20h] BYREF

  *(_WORD *)v5 = val;
  p_m_buf = &this->m_buf;
  bfx::Array<unsigned char>::push_back(this: &this->m_buf, val: v5);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: &v5[1]);
}


// ========================================================================
// ?WriteAttrib@BinaryReplayLogOut@bfx@@UAAXPBDIW4TextFormat@ReplayLogOut@2@@Z
// EA  : 0x83294740
// RVA : 0x01294740
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::BinaryReplayLogOut::WriteAttrib(
        bfx::BinaryReplayLogOut *this,
        const char *__formal,
        unsigned int val,
        bfx::ReplayLogOut::TextFormat a4)
{
  bfx::Array<unsigned char> *p_m_buf; // r31
  unsigned __int8 v5[16]; // [sp+50h] [-20h] BYREF

  *(_DWORD *)v5 = val;
  p_m_buf = &this->m_buf;
  bfx::Array<unsigned char>::push_back(this: &this->m_buf, val: v5);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: &v5[1]);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: &v5[2]);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: &v5[3]);
}


// ========================================================================
// ?WriteAttrib@BinaryReplayLogOut@bfx@@UAAXPBDEW4TextFormat@ReplayLogOut@2@@Z
// EA  : 0x832947A0
// RVA : 0x012947A0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::BinaryReplayLogOut::WriteAttrib(
        bfx::BinaryReplayLogOut *this,
        const char *__formal,
        unsigned __int8 val,
        bfx::ReplayLogOut::TextFormat a4)
{
  unsigned __int8 v4[8]; // [sp+50h] [-10h] BYREF

  v4[0] = val;
  bfx::Array<unsigned char>::push_back(this: &this->m_buf, val: v4);
}


// ========================================================================
// ?WriteAttrib@BinaryReplayLogOut@bfx@@UAAXPBD_KW4TextFormat@ReplayLogOut@2@@Z
// EA  : 0x832947D0
// RVA : 0x012947D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::BinaryReplayLogOut::WriteAttrib(
        bfx::BinaryReplayLogOut *this,
        const char *__formal,
        unsigned __int64 val,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10)
{
  bfx::BinaryReplayLogOut::Write64BitInt(
    this,
    val: (bfx::BinaryReplayLogOut::Binary64BitVal *)HIDWORD(val),
    a3: SHIDWORD(val),
    a4: val,
    a5: a4,
    a6: a5,
    a7: a6,
    a8: a7,
    a9: a8,
    a10: a9,
    a11: a10);
}


// ========================================================================
// ?WriteAttrib@BinaryReplayLogOut@bfx@@UAAXPBD_N@Z
// EA  : 0x832947D8
// RVA : 0x012947D8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::BinaryReplayLogOut::WriteAttrib(
        bfx::BinaryReplayLogOut *this,
        const char *__formal,
        unsigned __int8 val)
{
  unsigned __int8 v3[8]; // [sp+50h] [-10h] BYREF

  v3[0] = val != 0;
  bfx::Array<unsigned char>::push_back(this: &this->m_buf, val: v3);
}


// ========================================================================
// ?WriteAttrib@BinaryReplayLogOut@bfx@@UAAXPBDM@Z
// EA  : 0x83294810
// RVA : 0x01294810
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::BinaryReplayLogOut::WriteAttrib(bfx::BinaryReplayLogOut *this, const char *__formal, double val)
{
  bfx::Array<unsigned char> *p_m_buf; // r31
  float v4[4]; // [sp+50h] [-20h] BYREF

  v4[0] = val;
  p_m_buf = &this->m_buf;
  bfx::Array<unsigned char>::push_back(this: &this->m_buf, val: (unsigned __int8 *)v4);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v4 + 1);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v4 + 2);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v4 + 3);
}


// ========================================================================
// ?OpenLogEvent@BinaryReplayLogOut@bfx@@UAA_NW4ComponentID@2@GPBDI@Z
// EA  : 0x832948D0
// RVA : 0x012948D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

int __fastcall bfx::BinaryReplayLogOut::OpenLogEvent(
        bfx::BinaryReplayLogOut *this,
        bfx::ComponentID componentID,
        unsigned __int16 eventID,
        const char *__formal,
        unsigned int a5)
{
  bfx::Array<unsigned char> *p_m_buf; // r31
  __int16 v7; // r29
  float v10[12]; // [sp+50h] [-30h] BYREF

  p_m_buf = &this->m_buf;
  HIWORD(v10[0]) = 291;
  v7 = componentID;
  bfx::Array<unsigned char>::push_back(this: &this->m_buf, val: (unsigned __int8 *)v10);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v10 + 1);
  HIWORD(v10[0]) = v7;
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v10);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v10 + 1);
  HIWORD(v10[0]) = eventID;
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v10);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v10 + 1);
  v10[0] = bfx::GetTime() - this->m_startTime;
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v10);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v10 + 1);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v10 + 2);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v10 + 3);
  return 1;
}


// ========================================================================
// ?WriteAttrib@BinaryReplayLogOut@bfx@@UAAXPBDABVVector3@2@@Z
// EA  : 0x83294990
// RVA : 0x01294990
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::BinaryReplayLogOut::WriteAttrib(
        bfx::BinaryReplayLogOut *this,
        const char *__formal,
        const bfx::BoxExtents *val)
{
  bfx::Array<unsigned char> *p_m_buf; // r31
  float v5[2]; // [sp+50h] [-20h] BYREF

  p_m_buf = &this->m_buf;
  v5[0] = val->m_length;
  bfx::Array<unsigned char>::push_back(this: &this->m_buf, val: (unsigned __int8 *)v5);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 1);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 2);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 3);
  v5[0] = val->m_width;
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 1);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 2);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 3);
  v5[0] = val->m_height;
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 1);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 2);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 3);
}


// ========================================================================
// ?WriteAttrib@BinaryReplayLogOut@bfx@@UAAXPBDABVQuaternion@2@@Z
// EA  : 0x83294A70
// RVA : 0x01294A70
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayrecorder.cpp
// ========================================================================

void __fastcall bfx::BinaryReplayLogOut::WriteAttrib(
        bfx::BinaryReplayLogOut *this,
        const char *__formal,
        const bfx::Color *val)
{
  bfx::Array<unsigned char> *p_m_buf; // r31
  float v5[2]; // [sp+50h] [-20h] BYREF

  p_m_buf = &this->m_buf;
  v5[0] = val->m_r;
  bfx::Array<unsigned char>::push_back(this: &this->m_buf, val: (unsigned __int8 *)v5);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 1);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 2);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 3);
  v5[0] = val->m_g;
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 1);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 2);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 3);
  v5[0] = val->m_b;
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 1);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 2);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 3);
  v5[0] = val->m_a;
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 1);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 2);
  bfx::Array<unsigned char>::push_back(this: p_m_buf, val: (unsigned __int8 *)v5 + 3);
}

