
// ========================================================================
// ?_jxr_rbitstream_mark@@YAXPAUrbitstream@@@Z
// EA  : 0x82904F58
// RVA : 0x00904F58
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

void __fastcall _jxr_rbitstream_mark(rbitstream *str)
{
  const unsigned __int8 *cur_ptr; // r11
  const unsigned __int8 *data; // r9

  cur_ptr = str->cur_ptr;
  data = str->data;
  str->read_count = 0;
  str->mark_stream_position = cur_ptr - data;
}


// ========================================================================
// ?_jxr_rbitstream_seek@@YAXPAUrbitstream@@_K@Z
// EA  : 0x82904F78
// RVA : 0x00904F78
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

void __fastcall _jxr_rbitstream_seek(rbitstream *str, unsigned int a2, unsigned __int64 off)
{
  unsigned int mark_stream_position; // r9
  const unsigned __int8 *data; // r10

  mark_stream_position = str->mark_stream_position;
  data = str->data;
  str->read_count = a2;
  str->cur_ptr = &data[mark_stream_position + a2];
}


// ========================================================================
// ?_jxr_rbitstream_uint1@@YAHPAUrbitstream@@@Z
// EA  : 0x82904F98
// RVA : 0x00904F98
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

BOOL __fastcall _jxr_rbitstream_uint1(rbitstream *str)
{
  const unsigned __int8 *cur_ptr; // r11
  const unsigned __int8 *v2; // r10
  unsigned __int8 v3; // r11
  unsigned int read_count; // r10
  int byte; // r9
  int v6; // r11

  if ( str->bits_avail == 0 )
  {
    cur_ptr = str->cur_ptr;
    v2 = cur_ptr + 1;
    v3 = *cur_ptr;
    str->cur_ptr = v2;
    read_count = str->read_count;
    str->byte = v3;
    str->bits_avail = 8;
    str->read_count = read_count + 1;
  }
  byte = str->byte;
  v6 = str->bits_avail - 1;
  str->bits_avail = v6;
  return ((1 << v6) & byte) != 0;
}


// ========================================================================
// ?_jxr_rbitstream_uint2@@YAEPAUrbitstream@@@Z
// EA  : 0x82905000
// RVA : 0x00905000
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

int __fastcall _jxr_rbitstream_uint2(rbitstream *str)
{
  const unsigned __int8 *cur_ptr; // r11
  const unsigned __int8 *v2; // r10
  unsigned __int8 v3; // r11
  unsigned __int8 v4; // r10
  unsigned int read_count; // r11
  int byte; // r10
  int v7; // r11
  bool v8; // cr34
  int v9; // r10
  const unsigned __int8 *v10; // r11
  const unsigned __int8 *v11; // r7
  unsigned __int8 v12; // r11
  unsigned __int8 v13; // r7
  unsigned int v14; // r11
  int v15; // r8
  int v16; // r11

  if ( str->bits_avail == 0 )
  {
    cur_ptr = str->cur_ptr;
    v2 = cur_ptr + 1;
    v3 = *cur_ptr;
    str->cur_ptr = v2;
    v4 = v3;
    read_count = str->read_count;
    str->bits_avail = 8;
    str->byte = v4;
    str->read_count = read_count + 1;
  }
  byte = str->byte;
  v7 = str->bits_avail - 1;
  v8 = str->bits_avail == 1;
  str->bits_avail = v7;
  v9 = 2 * (((1 << v7) & byte) != 0);
  if ( v8 )
  {
    v10 = str->cur_ptr;
    v11 = v10 + 1;
    v12 = *v10;
    str->cur_ptr = v11;
    v13 = v12;
    v14 = str->read_count;
    str->bits_avail = 8;
    str->byte = v13;
    str->read_count = v14 + 1;
  }
  v15 = str->byte;
  v16 = str->bits_avail - 1;
  str->bits_avail = v16;
  return (((1 << v16) & v15) != 0) | v9;
}


// ========================================================================
// ?_jxr_rbitstream_uint3@@YAEPAUrbitstream@@@Z
// EA  : 0x829050C8
// RVA : 0x009050C8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

int __fastcall _jxr_rbitstream_uint3(rbitstream *str)
{
  const unsigned __int8 *cur_ptr; // r11
  const unsigned __int8 *v2; // r10
  unsigned __int8 v3; // r11
  unsigned __int8 v4; // r10
  unsigned int read_count; // r11
  int byte; // r10
  int v7; // r11
  bool v8; // cr34
  int v9; // r10
  const unsigned __int8 *v10; // r11
  const unsigned __int8 *v11; // r7
  unsigned __int8 v12; // r11
  unsigned __int8 v13; // r7
  unsigned int v14; // r11
  int v15; // r7
  int v16; // r11
  bool v17; // cr34
  int v18; // r10
  const unsigned __int8 *v19; // r11
  const unsigned __int8 *v20; // r7
  unsigned __int8 v21; // r11
  unsigned __int8 v22; // r7
  unsigned int v23; // r11
  int v24; // r8
  int v25; // r11

  if ( str->bits_avail == 0 )
  {
    cur_ptr = str->cur_ptr;
    v2 = cur_ptr + 1;
    v3 = *cur_ptr;
    str->cur_ptr = v2;
    v4 = v3;
    read_count = str->read_count;
    str->bits_avail = 8;
    str->byte = v4;
    str->read_count = read_count + 1;
  }
  byte = str->byte;
  v7 = str->bits_avail - 1;
  v8 = str->bits_avail == 1;
  str->bits_avail = v7;
  v9 = 2 * (((1 << v7) & byte) != 0);
  if ( v8 )
  {
    v10 = str->cur_ptr;
    v11 = v10 + 1;
    v12 = *v10;
    str->cur_ptr = v11;
    v13 = v12;
    v14 = str->read_count;
    str->bits_avail = 8;
    str->byte = v13;
    str->read_count = v14 + 1;
  }
  v15 = str->byte;
  v16 = str->bits_avail - 1;
  v17 = str->bits_avail == 1;
  str->bits_avail = v16;
  v18 = (2 * ((((1 << v16) & v15) != 0) | v9)) & 0xFE;
  if ( v17 )
  {
    v19 = str->cur_ptr;
    v20 = v19 + 1;
    v21 = *v19;
    str->cur_ptr = v20;
    v22 = v21;
    v23 = str->read_count;
    str->bits_avail = 8;
    str->byte = v22;
    str->read_count = v23 + 1;
  }
  v24 = str->byte;
  v25 = str->bits_avail - 1;
  str->bits_avail = v25;
  return (((1 << v25) & v24) != 0) | v18;
}


// ========================================================================
// ?_jxr_rbitstream_uint4@@YAEPAUrbitstream@@@Z
// EA  : 0x829051E8
// RVA : 0x009051E8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

int __fastcall _jxr_rbitstream_uint4(rbitstream *str)
{
  const unsigned __int8 *cur_ptr; // r10
  const unsigned __int8 *v3; // r9
  unsigned __int8 v4; // r10
  unsigned __int8 v5; // r9
  unsigned int read_count; // r10
  int result; // r3
  const unsigned __int8 *v8; // r10
  const unsigned __int8 *v9; // r9
  unsigned __int8 v10; // r10
  unsigned __int8 v11; // r9
  unsigned int v12; // r10
  int byte; // r9
  int v14; // r10
  bool v15; // cr34
  int v16; // r9
  const unsigned __int8 *v17; // r10
  const unsigned __int8 *v18; // r6
  unsigned __int8 v19; // r10
  unsigned __int8 v20; // r6
  unsigned int v21; // r10
  int v22; // r6
  int v23; // r10
  bool v24; // cr34
  int v25; // r9
  const unsigned __int8 *v26; // r10
  const unsigned __int8 *v27; // r6
  unsigned __int8 v28; // r10
  unsigned __int8 v29; // r6
  unsigned int v30; // r10
  int v31; // r6
  int v32; // r10
  bool v33; // cr34
  int v34; // r9
  const unsigned __int8 *v35; // r10
  const unsigned __int8 *v36; // r6
  unsigned __int8 v37; // r10
  unsigned __int8 v38; // r6
  unsigned int v39; // r10
  int v40; // r7
  int v41; // r10

  if ( str->bits_avail == 0 )
  {
    cur_ptr = str->cur_ptr;
    v3 = cur_ptr + 1;
    v4 = *cur_ptr;
    str->cur_ptr = v3;
    v5 = v4;
    read_count = str->read_count;
    str->bits_avail = 8;
    str->byte = v5;
    str->read_count = read_count + 1;
  }
  if ( str->bits_avail == 4 )
  {
    result = str->byte & 0xF;
    str->bits_avail = 0;
  }
  else
  {
    if ( str->bits_avail == 0 )
    {
      v8 = str->cur_ptr;
      v9 = v8 + 1;
      v10 = *v8;
      str->cur_ptr = v9;
      v11 = v10;
      v12 = str->read_count;
      str->bits_avail = 8;
      str->byte = v11;
      str->read_count = v12 + 1;
    }
    byte = str->byte;
    v14 = str->bits_avail - 1;
    v15 = str->bits_avail == 1;
    str->bits_avail = v14;
    v16 = 2 * (((1 << v14) & byte) != 0);
    if ( v15 )
    {
      v17 = str->cur_ptr;
      v18 = v17 + 1;
      v19 = *v17;
      str->cur_ptr = v18;
      v20 = v19;
      v21 = str->read_count;
      str->bits_avail = 8;
      str->byte = v20;
      str->read_count = v21 + 1;
    }
    v22 = str->byte;
    v23 = str->bits_avail - 1;
    v24 = str->bits_avail == 1;
    str->bits_avail = v23;
    v25 = (2 * ((((1 << v23) & v22) != 0) | v16)) & 0xFE;
    if ( v24 )
    {
      v26 = str->cur_ptr;
      v27 = v26 + 1;
      v28 = *v26;
      str->cur_ptr = v27;
      v29 = v28;
      v30 = str->read_count;
      str->bits_avail = 8;
      str->byte = v29;
      str->read_count = v30 + 1;
    }
    v31 = str->byte;
    v32 = str->bits_avail - 1;
    v33 = str->bits_avail == 1;
    str->bits_avail = v32;
    v34 = (2 * ((((1 << v32) & v31) != 0) | v25)) & 0xFE;
    if ( v33 )
    {
      v35 = str->cur_ptr;
      v36 = v35 + 1;
      v37 = *v35;
      str->cur_ptr = v36;
      v38 = v37;
      v39 = str->read_count;
      str->bits_avail = 8;
      str->byte = v38;
      str->read_count = v39 + 1;
    }
    v40 = str->byte;
    v41 = str->bits_avail - 1;
    str->bits_avail = v41;
    return (((1 << v41) & v40) != 0) | v34;
  }
  return result;
}


// ========================================================================
// ?_jxr_rbitstream_uint6@@YAEPAUrbitstream@@@Z
// EA  : 0x829053C8
// RVA : 0x009053C8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

int __fastcall _jxr_rbitstream_uint6(rbitstream *str)
{
  int v2; // r10
  const unsigned __int8 *cur_ptr; // r11
  const unsigned __int8 *v4; // r9
  unsigned __int8 v5; // r11
  unsigned __int8 v6; // r9
  unsigned int read_count; // r11
  int byte; // r7
  int v9; // r11
  bool v10; // cr34
  int v11; // r10
  const unsigned __int8 *v12; // r11
  const unsigned __int8 *v13; // r7
  unsigned __int8 v14; // r11
  unsigned __int8 v15; // r7
  unsigned int v16; // r11
  int v17; // r8
  int v18; // r11

  v2 = (2 * _jxr_rbitstream_uint4(str)) & 0xFE;
  if ( str->bits_avail == 0 )
  {
    cur_ptr = str->cur_ptr;
    v4 = cur_ptr + 1;
    v5 = *cur_ptr;
    str->cur_ptr = v4;
    v6 = v5;
    read_count = str->read_count;
    str->bits_avail = 8;
    str->byte = v6;
    str->read_count = read_count + 1;
  }
  byte = str->byte;
  v9 = str->bits_avail - 1;
  v10 = str->bits_avail == 1;
  str->bits_avail = v9;
  v11 = (2 * ((((1 << v9) & byte) != 0) | v2)) & 0xFE;
  if ( v10 )
  {
    v12 = str->cur_ptr;
    v13 = v12 + 1;
    v14 = *v12;
    str->cur_ptr = v13;
    v15 = v14;
    v16 = str->read_count;
    str->bits_avail = 8;
    str->byte = v15;
    str->read_count = v16 + 1;
  }
  v17 = str->byte;
  v18 = str->bits_avail - 1;
  str->bits_avail = v18;
  return (((1 << v18) & v17) != 0) | v11;
}


// ========================================================================
// ?_jxr_rbitstream_uint8@@YAEPAUrbitstream@@@Z
// EA  : 0x829054C0
// RVA : 0x009054C0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

int __fastcall _jxr_rbitstream_uint8(rbitstream *str)
{
  const unsigned __int8 *cur_ptr; // r10
  const unsigned __int8 *v3; // r9
  unsigned int read_count; // r10
  int result; // r3
  int i; // ctr
  const unsigned __int8 *v7; // r10
  const unsigned __int8 *v8; // r6
  unsigned int v9; // r10
  int byte; // r6
  int v11; // r10
  bool v12; // cr34
  int v13; // r9
  const unsigned __int8 *v14; // r10
  const unsigned __int8 *v15; // r6
  unsigned int v16; // r10
  int v17; // r6
  int v18; // r10
  bool v19; // cr34
  int v20; // r9
  const unsigned __int8 *v21; // r10
  const unsigned __int8 *v22; // r6
  unsigned int v23; // r10
  int v24; // r6
  int v25; // r10
  bool v26; // cr34
  int v27; // r9
  const unsigned __int8 *v28; // r10
  const unsigned __int8 *v29; // r6
  unsigned int v30; // r10
  int v31; // r6
  int v32; // r10

  if ( str->bits_avail == 0 )
  {
    cur_ptr = str->cur_ptr;
    v3 = cur_ptr + 1;
    LOBYTE(cur_ptr) = *cur_ptr;
    str->cur_ptr = v3;
    LOBYTE(v3) = (_BYTE)cur_ptr;
    read_count = str->read_count;
    str->bits_avail = 8;
    str->byte = (unsigned __int8)v3;
    str->read_count = read_count + 1;
  }
  if ( str->bits_avail == 8 )
  {
    result = str->byte;
    str->bits_avail = 0;
  }
  else
  {
    result = 0;
    for ( i = 2; i != 0; --i )
    {
      if ( str->bits_avail == 0 )
      {
        v7 = str->cur_ptr;
        v8 = v7 + 1;
        LOBYTE(v7) = *v7;
        str->cur_ptr = v8;
        LOBYTE(v8) = (_BYTE)v7;
        v9 = str->read_count;
        str->bits_avail = 8;
        str->byte = (unsigned __int8)v8;
        str->read_count = v9 + 1;
      }
      byte = str->byte;
      v11 = str->bits_avail - 1;
      v12 = str->bits_avail == 1;
      str->bits_avail = v11;
      v13 = (2 * ((((1 << v11) & byte) != 0) | (2 * result) & 0xFE)) & 0xFE;
      if ( v12 )
      {
        v14 = str->cur_ptr;
        v15 = v14 + 1;
        LOBYTE(v14) = *v14;
        str->cur_ptr = v15;
        LOBYTE(v15) = (_BYTE)v14;
        v16 = str->read_count;
        str->bits_avail = 8;
        str->byte = (unsigned __int8)v15;
        str->read_count = v16 + 1;
      }
      v17 = str->byte;
      v18 = str->bits_avail - 1;
      v19 = str->bits_avail == 1;
      str->bits_avail = v18;
      v20 = (2 * ((((1 << v18) & v17) != 0) | v13)) & 0xFE;
      if ( v19 )
      {
        v21 = str->cur_ptr;
        v22 = v21 + 1;
        LOBYTE(v21) = *v21;
        str->cur_ptr = v22;
        LOBYTE(v22) = (_BYTE)v21;
        v23 = str->read_count;
        str->bits_avail = 8;
        str->byte = (unsigned __int8)v22;
        str->read_count = v23 + 1;
      }
      v24 = str->byte;
      v25 = str->bits_avail - 1;
      v26 = str->bits_avail == 1;
      str->bits_avail = v25;
      v27 = (2 * ((((1 << v25) & v24) != 0) | v20)) & 0xFE;
      if ( v26 )
      {
        v28 = str->cur_ptr;
        v29 = v28 + 1;
        LOBYTE(v28) = *v28;
        str->cur_ptr = v29;
        LOBYTE(v29) = (_BYTE)v28;
        v30 = str->read_count;
        str->bits_avail = 8;
        str->byte = (unsigned __int8)v29;
        str->read_count = v30 + 1;
      }
      v31 = str->byte;
      v32 = str->bits_avail - 1;
      str->bits_avail = v32;
      result = (((1 << v32) & v31) != 0) | v27;
    }
  }
  return result;
}


// ========================================================================
// ?_jxr_rbitstream_uint12@@YAGPAUrbitstream@@@Z
// EA  : 0x829056B0
// RVA : 0x009056B0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

int __fastcall _jxr_rbitstream_uint12(rbitstream *str)
{
  int v2; // r30

  v2 = (16 * _jxr_rbitstream_uint8(str)) & 0xFF0;
  return (unsigned __int8)_jxr_rbitstream_uint4(str) | v2;
}


// ========================================================================
// ?_jxr_rbitstream_uint15@@YAGPAUrbitstream@@@Z
// EA  : 0x829056F8
// RVA : 0x009056F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

int __fastcall _jxr_rbitstream_uint15(rbitstream *str)
{
  int v2; // r30
  int v3; // r10

  v2 = (16 * _jxr_rbitstream_uint8(str)) & 0xFF0;
  v3 = (unsigned __int8)_jxr_rbitstream_uint4(str) | v2;
  return (unsigned __int8)_jxr_rbitstream_uint3(str) | (8 * v3) & 0xFFF8;
}


// ========================================================================
// ?_jxr_rbitstream_uint16@@YAGPAUrbitstream@@@Z
// EA  : 0x82905758
// RVA : 0x00905758
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

int __fastcall _jxr_rbitstream_uint16(rbitstream *str)
{
  int v2; // r30

  v2 = (_jxr_rbitstream_uint8(str) << 8) & 0xFF00;
  return (unsigned __int8)_jxr_rbitstream_uint8(str) | v2;
}


// ========================================================================
// ?_jxr_rbitstream_uint32@@YAIPAUrbitstream@@@Z
// EA  : 0x829057A0
// RVA : 0x009057A0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

int __fastcall _jxr_rbitstream_uint32(rbitstream *str)
{
  int v2; // r30
  int v3; // r30
  int v4; // r29

  v2 = (_jxr_rbitstream_uint8(str) << 8) & 0xFF00;
  v3 = (unsigned __int8)_jxr_rbitstream_uint8(str) | v2;
  v4 = (_jxr_rbitstream_uint8(str) << 8) & 0xFF00;
  return (unsigned __int8)_jxr_rbitstream_uint8(str) | (v3 << 16) | v4;
}


// ========================================================================
// ?_jxr_rbitstream_uintN@@YAIPAUrbitstream@@H@Z
// EA  : 0x829057F8
// RVA : 0x009057F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

unsigned int __fastcall _jxr_rbitstream_uintN(rbitstream *str, int N)
{
  unsigned int result; // r3
  int i; // ctr
  const unsigned __int8 *cur_ptr; // r10
  const unsigned __int8 *v6; // r9
  unsigned int read_count; // r9
  int byte; // r9
  int v9; // r10

  result = 0;
  if ( N > 0 )
  {
    for ( i = N; i != 0; --i )
    {
      if ( str->bits_avail == 0 )
      {
        cur_ptr = str->cur_ptr;
        v6 = cur_ptr + 1;
        LOBYTE(cur_ptr) = *cur_ptr;
        str->cur_ptr = v6;
        read_count = str->read_count;
        str->bits_avail = 8;
        str->byte = (unsigned __int8)cur_ptr;
        str->read_count = read_count + 1;
      }
      byte = str->byte;
      v9 = str->bits_avail - 1;
      str->bits_avail = v9;
      result = (((1 << v9) & byte) != 0) | (2 * result);
    }
  }
  return result;
}


// ========================================================================
// ?_jxr_rbitstream_intE@@YAHPAUrbitstream@@HPBEPBC@Z
// EA  : 0x82905880
// RVA : 0x00905880
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

int __fastcall _jxr_rbitstream_intE(rbitstream *str, char code_size, const unsigned __int8 *codeb, const char *codev)
{
  int v4; // r10
  int v5; // r11
  int v6; // r8
  const unsigned __int8 *cur_ptr; // r10
  const unsigned __int8 *v8; // r9
  unsigned __int8 v9; // r10
  unsigned int read_count; // r9
  int byte; // r9
  int v12; // r10

  v4 = 0;
  v5 = 0;
  if ( *codeb != 0 )
  {
    do
    {
      v6 = 2 * v4;
      if ( str->bits_avail == 0 )
      {
        cur_ptr = str->cur_ptr;
        v8 = cur_ptr + 1;
        v9 = *cur_ptr;
        str->cur_ptr = v8;
        read_count = str->read_count;
        str->bits_avail = 8;
        str->byte = v9;
        str->read_count = read_count + 1;
      }
      ++v5;
      byte = str->byte;
      v12 = str->bits_avail - 1;
      str->bits_avail = v12;
      v4 = (((1 << v12) & byte) != 0) | v6;
    }
    while ( codeb[v4 << (code_size - v5)] != v5 );
  }
  return codev[v4 << (code_size - v5)];
}


// ========================================================================
// ?_jxr_rbitstream_intVLW@@YA_JPAUrbitstream@@@Z
// EA  : 0x82905940
// RVA : 0x00905940
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

int __fastcall _jxr_rbitstream_intVLW(rbitstream *str)
{
  unsigned __int8 v2; // r3

  v2 = _jxr_rbitstream_uint8(str);
  if ( v2 < 0xFBu )
    return (unsigned __int8)_jxr_rbitstream_uint8(str) + (v2 << 8);
  if ( v2 == 251 )
    return _jxr_rbitstream_uint32(str);
  if ( v2 != 252 )
    return 0;
  _jxr_rbitstream_uint32(str);
  return _jxr_rbitstream_uint32(str);
}


// ========================================================================
// ?_jxr_wbitstream_bitpos@@YAIPAUwbitstream@@@Z
// EA  : 0x829059E0
// RVA : 0x009059E0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

unsigned int __fastcall _jxr_wbitstream_bitpos(wbitstream *str)
{
  return 8 * (str->mark_stream_position + str->write_count) + str->bits_ready;
}


// ========================================================================
// ?_jxr_wbitstream_syncbyte@@YAXPAUwbitstream@@@Z
// EA  : 0x82905A00
// RVA : 0x00905A00
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

void __fastcall _jxr_wbitstream_syncbyte(wbitstream *str)
{
  if ( str->bits_ready > 0 )
    str->bits_ready = 8;
}


// ========================================================================
// ?_jxr_wbitstream_flush@@YAXPAUwbitstream@@@Z
// EA  : 0x82905A18
// RVA : 0x00905A18
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

void __fastcall _jxr_wbitstream_flush(wbitstream *str)
{
  unsigned __int8 *v1; // r7
  unsigned int v2; // r8

  if ( str->bits_ready > 0 )
    str->bits_ready = 8;
  if ( str->bits_ready > 0 )
  {
    *str->cur_ptr = str->byte;
    v1 = str->cur_ptr + 1;
    v2 = str->write_count + 1;
    str->byte = 0;
    str->bits_ready = 0;
    str->write_count = v2;
    str->cur_ptr = v1;
  }
}


// ========================================================================
// ?_jxr_wbitstream_uint1@@YAXPAUwbitstream@@H@Z
// EA  : 0x82905A70
// RVA : 0x00905A70
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

void __fastcall _jxr_wbitstream_uint1(wbitstream *str, int val)
{
  unsigned __int8 *v2; // r7
  unsigned int v3; // r8

  if ( str->bits_ready == 8 )
  {
    *str->cur_ptr = str->byte;
    v2 = str->cur_ptr + 1;
    v3 = str->write_count + 1;
    str->byte = 0;
    str->bits_ready = 0;
    str->write_count = v3;
    str->cur_ptr = v2;
  }
  if ( val != 0 )
    str->byte |= 128 >> str->bits_ready;
  ++str->bits_ready;
}


// ========================================================================
// ?_jxr_wbitstream_uint2@@YAXPAUwbitstream@@E@Z
// EA  : 0x82905AE0
// RVA : 0x00905AE0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

void __fastcall _jxr_wbitstream_uint2(wbitstream *str, unsigned __int8 val)
{
  unsigned __int8 *v2; // r7
  unsigned int v3; // r8
  int v4; // r11
  unsigned __int8 *v5; // r6
  unsigned int write_count; // r11

  if ( str->bits_ready == 8 )
  {
    *str->cur_ptr = str->byte;
    v2 = str->cur_ptr + 1;
    v3 = str->write_count + 1;
    str->byte = 0;
    str->bits_ready = 0;
    str->write_count = v3;
    str->cur_ptr = v2;
  }
  if ( (val & 2) != 0 )
    str->byte |= 128 >> str->bits_ready;
  v4 = str->bits_ready + 1;
  str->bits_ready = v4;
  if ( v4 == 8 )
  {
    *str->cur_ptr = str->byte;
    v5 = str->cur_ptr + 1;
    write_count = str->write_count;
    str->byte = 0;
    str->bits_ready = 0;
    str->cur_ptr = v5;
    str->write_count = write_count + 1;
  }
  if ( (val & 1) != 0 )
    str->byte |= 128 >> str->bits_ready;
  ++str->bits_ready;
}


// ========================================================================
// ?_jxr_wbitstream_uint3@@YAXPAUwbitstream@@E@Z
// EA  : 0x82905BB8
// RVA : 0x00905BB8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

void __fastcall _jxr_wbitstream_uint3(wbitstream *str, unsigned __int8 val)
{
  unsigned __int8 *v2; // r7
  unsigned int v3; // r8
  int v4; // r10
  unsigned __int8 *v5; // r6
  unsigned int write_count; // r10
  int v7; // r10
  unsigned __int8 *cur_ptr; // r10

  if ( str->bits_ready == 8 )
  {
    *str->cur_ptr = str->byte;
    v2 = str->cur_ptr + 1;
    v3 = str->write_count + 1;
    str->byte = 0;
    str->bits_ready = 0;
    str->write_count = v3;
    str->cur_ptr = v2;
  }
  if ( (val & 4) != 0 )
    str->byte |= 128 >> str->bits_ready;
  v4 = str->bits_ready + 1;
  str->bits_ready = v4;
  if ( v4 == 8 )
  {
    *str->cur_ptr = str->byte;
    v5 = str->cur_ptr + 1;
    write_count = str->write_count;
    str->byte = 0;
    str->bits_ready = 0;
    str->cur_ptr = v5;
    str->write_count = write_count + 1;
  }
  if ( (val & 2) != 0 )
    str->byte |= 128 >> str->bits_ready;
  v7 = str->bits_ready + 1;
  str->bits_ready = v7;
  if ( v7 == 8 )
  {
    *str->cur_ptr = str->byte;
    cur_ptr = str->cur_ptr;
    str->byte = 0;
    str->bits_ready = 0;
    ++str->write_count;
    str->cur_ptr = cur_ptr + 1;
  }
  if ( (val & 1) != 0 )
    str->byte |= 128 >> str->bits_ready;
  ++str->bits_ready;
}


// ========================================================================
// ?_jxr_wbitstream_uint4@@YAXPAUwbitstream@@E@Z
// EA  : 0x82905CF0
// RVA : 0x00905CF0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

void __fastcall _jxr_wbitstream_uint4(wbitstream *str, unsigned __int8 val)
{
  unsigned __int8 *v2; // r7
  unsigned int v3; // r8
  int v4; // r10
  unsigned __int8 *v5; // r6
  unsigned int write_count; // r10
  int v7; // r10
  unsigned int v8; // r6
  unsigned __int8 *v9; // r5
  int v10; // r10
  unsigned int v11; // r10

  if ( str->bits_ready == 8 )
  {
    *str->cur_ptr = str->byte;
    v2 = str->cur_ptr + 1;
    v3 = str->write_count + 1;
    str->byte = 0;
    str->bits_ready = 0;
    str->write_count = v3;
    str->cur_ptr = v2;
  }
  if ( (val & 8) != 0 )
    str->byte |= 128 >> str->bits_ready;
  v4 = str->bits_ready + 1;
  str->bits_ready = v4;
  if ( v4 == 8 )
  {
    *str->cur_ptr = str->byte;
    v5 = str->cur_ptr + 1;
    write_count = str->write_count;
    str->byte = 0;
    str->bits_ready = 0;
    str->cur_ptr = v5;
    str->write_count = write_count + 1;
  }
  if ( (val & 4) != 0 )
    str->byte |= 128 >> str->bits_ready;
  v7 = str->bits_ready + 1;
  str->bits_ready = v7;
  if ( v7 == 8 )
  {
    *str->cur_ptr = str->byte;
    v8 = str->write_count + 1;
    v9 = str->cur_ptr + 1;
    str->byte = 0;
    str->bits_ready = 0;
    str->write_count = v8;
    str->cur_ptr = v9;
  }
  if ( (val & 2) != 0 )
    str->byte |= 128 >> str->bits_ready;
  v10 = str->bits_ready + 1;
  str->bits_ready = v10;
  if ( v10 == 8 )
  {
    *str->cur_ptr = str->byte;
    str->byte = 0;
    str->bits_ready = 0;
    v11 = str->write_count;
    ++str->cur_ptr;
    str->write_count = v11 + 1;
  }
  if ( (val & 1) != 0 )
    str->byte |= 128 >> str->bits_ready;
  ++str->bits_ready;
}


// ========================================================================
// ?_jxr_wbitstream_uint6@@YAXPAUwbitstream@@E@Z
// EA  : 0x82905E88
// RVA : 0x00905E88
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

void __fastcall _jxr_wbitstream_uint6(wbitstream *str, unsigned __int8 val)
{
  unsigned __int8 *v2; // r7
  unsigned int v3; // r8
  int v4; // r10
  unsigned __int8 *v5; // r6
  unsigned int write_count; // r10
  int v7; // r10
  unsigned int v8; // r6
  unsigned __int8 *v9; // r5
  int v10; // r10
  unsigned __int8 *v11; // r5
  int v12; // r10
  unsigned int v13; // r5
  unsigned __int8 *cur_ptr; // r9
  int v15; // r10
  unsigned int v16; // r5

  if ( str->bits_ready == 8 )
  {
    *str->cur_ptr = str->byte;
    v2 = str->cur_ptr + 1;
    v3 = str->write_count + 1;
    str->byte = 0;
    str->bits_ready = 0;
    str->write_count = v3;
    str->cur_ptr = v2;
  }
  if ( (val & 0x20) != 0 )
    str->byte |= 128 >> str->bits_ready;
  v4 = str->bits_ready + 1;
  str->bits_ready = v4;
  if ( v4 == 8 )
  {
    *str->cur_ptr = str->byte;
    v5 = str->cur_ptr + 1;
    write_count = str->write_count;
    str->byte = 0;
    str->bits_ready = 0;
    str->cur_ptr = v5;
    str->write_count = write_count + 1;
  }
  if ( (val & 0x10) != 0 )
    str->byte |= 128 >> str->bits_ready;
  v7 = str->bits_ready + 1;
  str->bits_ready = v7;
  if ( v7 == 8 )
  {
    *str->cur_ptr = str->byte;
    v8 = str->write_count + 1;
    v9 = str->cur_ptr + 1;
    str->byte = 0;
    str->bits_ready = 0;
    str->write_count = v8;
    str->cur_ptr = v9;
  }
  if ( (val & 8) != 0 )
    str->byte |= 128 >> str->bits_ready;
  v10 = str->bits_ready + 1;
  str->bits_ready = v10;
  if ( v10 == 8 )
  {
    *str->cur_ptr = str->byte;
    str->byte = 0;
    str->bits_ready = 0;
    v11 = str->cur_ptr + 1;
    ++str->write_count;
    str->cur_ptr = v11;
  }
  if ( (val & 4) != 0 )
    str->byte |= 128 >> str->bits_ready;
  v12 = str->bits_ready + 1;
  str->bits_ready = v12;
  if ( v12 == 8 )
  {
    *str->cur_ptr = str->byte;
    v13 = str->write_count + 1;
    cur_ptr = str->cur_ptr;
    str->byte = 0;
    str->bits_ready = 0;
    str->write_count = v13;
    str->cur_ptr = cur_ptr + 1;
  }
  if ( (val & 2) != 0 )
    str->byte |= 128 >> str->bits_ready;
  v15 = str->bits_ready + 1;
  str->bits_ready = v15;
  if ( v15 == 8 )
  {
    *str->cur_ptr = str->byte;
    str->byte = 0;
    str->bits_ready = 0;
    v16 = str->write_count + 1;
    ++str->cur_ptr;
    str->write_count = v16;
  }
  if ( (val & 1) != 0 )
    str->byte |= 128 >> str->bits_ready;
  ++str->bits_ready;
}


// ========================================================================
// ?_jxr_wbitstream_uint8@@YAXPAUwbitstream@@E@Z
// EA  : 0x829060E0
// RVA : 0x009060E0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

void __fastcall _jxr_wbitstream_uint8(wbitstream *str, unsigned __int8 val)
{
  unsigned __int8 *v2; // r7
  unsigned int v3; // r8
  int v4; // r6
  int v5; // r7
  unsigned int v6; // r5
  unsigned __int8 *cur_ptr; // r10
  int v8; // r11
  unsigned int v9; // r4
  unsigned __int8 *v10; // r5
  int v11; // r11
  unsigned __int8 *v12; // r4
  int v13; // r11
  unsigned int v14; // r4

  if ( str->bits_ready == 8 )
  {
    *str->cur_ptr = str->byte;
    v2 = str->cur_ptr + 1;
    v3 = str->write_count + 1;
    str->byte = 0;
    str->bits_ready = 0;
    str->write_count = v3;
    str->cur_ptr = v2;
  }
  if ( str->bits_ready != 0 )
  {
    v4 = val;
    v5 = 2;
    do
    {
      if ( str->bits_ready == 8 )
      {
        *str->cur_ptr = str->byte;
        v6 = str->write_count + 1;
        cur_ptr = str->cur_ptr;
        str->byte = 0;
        str->bits_ready = 0;
        str->write_count = v6;
        str->cur_ptr = cur_ptr + 1;
      }
      if ( ((128 >> (v5 - 2)) & v4) != 0 )
        str->byte |= 128 >> str->bits_ready;
      v8 = str->bits_ready + 1;
      str->bits_ready = v8;
      if ( v8 == 8 )
      {
        *str->cur_ptr = str->byte;
        v9 = str->write_count + 1;
        v10 = str->cur_ptr + 1;
        str->byte = 0;
        str->bits_ready = 0;
        str->cur_ptr = v10;
        str->write_count = v9;
      }
      if ( ((128 >> (v5 - 1)) & v4) != 0 )
        str->byte |= 128 >> str->bits_ready;
      v11 = str->bits_ready + 1;
      str->bits_ready = v11;
      if ( v11 == 8 )
      {
        *str->cur_ptr = str->byte;
        str->byte = 0;
        str->bits_ready = 0;
        v12 = str->cur_ptr + 1;
        ++str->write_count;
        str->cur_ptr = v12;
      }
      if ( ((128 >> v5) & v4) != 0 )
        str->byte |= 128 >> str->bits_ready;
      v13 = str->bits_ready + 1;
      str->bits_ready = v13;
      if ( v13 == 8 )
      {
        *str->cur_ptr = str->byte;
        str->byte = 0;
        str->bits_ready = 0;
        v14 = str->write_count + 1;
        ++str->cur_ptr;
        str->write_count = v14;
      }
      if ( ((128 >> (v5 + 1)) & v4) != 0 )
        str->byte |= 128 >> str->bits_ready;
      v5 += 4;
      ++str->bits_ready;
    }
    while ( v5 - 2 < 8 );
  }
  else
  {
    str->byte = val;
    str->bits_ready = 8;
  }
}


// ========================================================================
// ?_jxr_wbitstream_uint12@@YAXPAUwbitstream@@G@Z
// EA  : 0x829062F8
// RVA : 0x009062F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

void __fastcall _jxr_wbitstream_uint12(wbitstream *str, unsigned __int16 val)
{
  int v2; // r7
  int v3; // r8
  unsigned __int8 *v4; // r11
  unsigned int v5; // r4
  int v6; // r11
  unsigned __int8 *v7; // r4
  unsigned int v8; // r11
  int v9; // r11
  unsigned __int8 *v10; // r4
  int v11; // r11
  unsigned int v12; // r4
  unsigned __int8 *v13; // r11
  int v14; // r11
  unsigned int v15; // r11
  unsigned __int8 *cur_ptr; // r10
  int v17; // r11
  unsigned int v18; // r11
  unsigned __int8 *v19; // r10

  v2 = val;
  v3 = 2;
  do
  {
    if ( str->bits_ready == 8 )
    {
      *str->cur_ptr = str->byte;
      v4 = str->cur_ptr + 1;
      v5 = str->write_count + 1;
      str->byte = 0;
      str->bits_ready = 0;
      str->write_count = v5;
      str->cur_ptr = v4;
    }
    if ( ((2048 >> (v3 - 2)) & v2) != 0 )
      str->byte |= 128 >> str->bits_ready;
    v6 = str->bits_ready + 1;
    str->bits_ready = v6;
    if ( v6 == 8 )
    {
      *str->cur_ptr = str->byte;
      v7 = str->cur_ptr + 1;
      v8 = str->write_count + 1;
      str->byte = 0;
      str->bits_ready = 0;
      str->cur_ptr = v7;
      str->write_count = v8;
    }
    if ( ((2048 >> (v3 - 1)) & v2) != 0 )
      str->byte |= 128 >> str->bits_ready;
    v9 = str->bits_ready + 1;
    str->bits_ready = v9;
    if ( v9 == 8 )
    {
      *str->cur_ptr = str->byte;
      str->byte = 0;
      str->bits_ready = 0;
      v10 = str->cur_ptr + 1;
      ++str->write_count;
      str->cur_ptr = v10;
    }
    if ( ((2048 >> v3) & v2) != 0 )
      str->byte |= 128 >> str->bits_ready;
    v11 = str->bits_ready + 1;
    str->bits_ready = v11;
    if ( v11 == 8 )
    {
      *str->cur_ptr = str->byte;
      v12 = str->write_count + 1;
      v13 = str->cur_ptr + 1;
      str->byte = 0;
      str->bits_ready = 0;
      str->write_count = v12;
      str->cur_ptr = v13;
    }
    if ( ((2048 >> (v3 + 1)) & v2) != 0 )
      str->byte |= 128 >> str->bits_ready;
    v14 = str->bits_ready + 1;
    str->bits_ready = v14;
    if ( v14 == 8 )
    {
      *str->cur_ptr = str->byte;
      v15 = str->write_count + 1;
      cur_ptr = str->cur_ptr;
      str->byte = 0;
      str->bits_ready = 0;
      str->write_count = v15;
      str->cur_ptr = cur_ptr + 1;
    }
    if ( ((2048 >> (v3 + 2)) & v2) != 0 )
      str->byte |= 128 >> str->bits_ready;
    v17 = str->bits_ready + 1;
    str->bits_ready = v17;
    if ( v17 == 8 )
    {
      *str->cur_ptr = str->byte;
      v18 = str->write_count + 1;
      v19 = str->cur_ptr;
      str->byte = 0;
      str->bits_ready = 0;
      str->write_count = v18;
      str->cur_ptr = v19 + 1;
    }
    if ( ((2048 >> (v3 + 3)) & v2) != 0 )
      str->byte |= 128 >> str->bits_ready;
    v3 += 6;
    ++str->bits_ready;
  }
  while ( v3 - 2 < 12 );
}


// ========================================================================
// ?_jxr_wbitstream_uint15@@YAXPAUwbitstream@@G@Z
// EA  : 0x82906590
// RVA : 0x00906590
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

void __fastcall _jxr_wbitstream_uint15(wbitstream *str, unsigned __int16 val)
{
  int v2; // r7
  int v3; // r8
  unsigned __int8 *v4; // r11
  unsigned int v5; // r4
  int v6; // r11
  unsigned __int8 *v7; // r4
  unsigned int v8; // r11
  int v9; // r11
  unsigned __int8 *v10; // r4
  int v11; // r11
  unsigned int v12; // r4
  unsigned __int8 *v13; // r11
  int v14; // r11
  unsigned int v15; // r11
  unsigned __int8 *cur_ptr; // r10

  v2 = val;
  v3 = 2;
  do
  {
    if ( str->bits_ready == 8 )
    {
      *str->cur_ptr = str->byte;
      v4 = str->cur_ptr + 1;
      v5 = str->write_count + 1;
      str->byte = 0;
      str->bits_ready = 0;
      str->write_count = v5;
      str->cur_ptr = v4;
    }
    if ( ((0x4000 >> (v3 - 2)) & v2) != 0 )
      str->byte |= 128 >> str->bits_ready;
    v6 = str->bits_ready + 1;
    str->bits_ready = v6;
    if ( v6 == 8 )
    {
      *str->cur_ptr = str->byte;
      v7 = str->cur_ptr + 1;
      v8 = str->write_count + 1;
      str->byte = 0;
      str->bits_ready = 0;
      str->cur_ptr = v7;
      str->write_count = v8;
    }
    if ( ((0x4000 >> (v3 - 1)) & v2) != 0 )
      str->byte |= 128 >> str->bits_ready;
    v9 = str->bits_ready + 1;
    str->bits_ready = v9;
    if ( v9 == 8 )
    {
      *str->cur_ptr = str->byte;
      str->byte = 0;
      str->bits_ready = 0;
      v10 = str->cur_ptr + 1;
      ++str->write_count;
      str->cur_ptr = v10;
    }
    if ( ((0x4000 >> v3) & v2) != 0 )
      str->byte |= 128 >> str->bits_ready;
    v11 = str->bits_ready + 1;
    str->bits_ready = v11;
    if ( v11 == 8 )
    {
      *str->cur_ptr = str->byte;
      v12 = str->write_count + 1;
      v13 = str->cur_ptr + 1;
      str->byte = 0;
      str->bits_ready = 0;
      str->write_count = v12;
      str->cur_ptr = v13;
    }
    if ( ((0x4000 >> (v3 + 1)) & v2) != 0 )
      str->byte |= 128 >> str->bits_ready;
    v14 = str->bits_ready + 1;
    str->bits_ready = v14;
    if ( v14 == 8 )
    {
      *str->cur_ptr = str->byte;
      v15 = str->write_count + 1;
      cur_ptr = str->cur_ptr;
      str->byte = 0;
      str->bits_ready = 0;
      str->write_count = v15;
      str->cur_ptr = cur_ptr + 1;
    }
    if ( ((0x4000 >> (v3 + 2)) & v2) != 0 )
      str->byte |= 128 >> str->bits_ready;
    v3 += 5;
    ++str->bits_ready;
  }
  while ( v3 - 2 < 15 );
}


// ========================================================================
// ?_jxr_wbitstream_uint16@@YAXPAUwbitstream@@G@Z
// EA  : 0x829067C0
// RVA : 0x009067C0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

void __fastcall _jxr_wbitstream_uint16(wbitstream *str, unsigned __int16 val)
{
  unsigned __int8 v2; // r30
  wbitstream *v3; // r3

  v2 = val;
  _jxr_wbitstream_uint8(str, val: HIBYTE(val));
  _jxr_wbitstream_uint8(str: v3, val: v2);
}


// ========================================================================
// ?_jxr_wbitstream_uint32@@YAXPAUwbitstream@@I@Z
// EA  : 0x82906808
// RVA : 0x00906808
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

void __fastcall _jxr_wbitstream_uint32(wbitstream *str, unsigned int val)
{
  wbitstream *v3; // r3
  wbitstream *v4; // r3
  wbitstream *v5; // r3

  _jxr_wbitstream_uint8(str, val: HIBYTE(val));
  _jxr_wbitstream_uint8(str: v3, val: BYTE1(val));
  _jxr_wbitstream_uint8(str: v4, val: BYTE2(val));
  _jxr_wbitstream_uint8(str: v5, val);
}


// ========================================================================
// ?_jxr_wbitstream_uintN@@YAXPAUwbitstream@@IH@Z
// EA  : 0x82906860
// RVA : 0x00906860
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

void __fastcall _jxr_wbitstream_uintN(wbitstream *str, unsigned int val, int N)
{
  int i; // ctr
  unsigned __int8 *v4; // r6
  unsigned int v5; // r7

  if ( N > 0 )
  {
    for ( i = N; i != 0; --i )
    {
      if ( str->bits_ready == 8 )
      {
        *str->cur_ptr = str->byte;
        v4 = str->cur_ptr + 1;
        v5 = str->write_count + 1;
        str->byte = 0;
        str->bits_ready = 0;
        str->write_count = v5;
        str->cur_ptr = v4;
      }
      if ( ((val >> (N - 1)) & 1) != 0 )
        str->byte |= 128 >> str->bits_ready;
      LOBYTE(N) = N - 1;
      ++str->bits_ready;
    }
  }
}


// ========================================================================
// ?_jxr_wbitstream_intVLW@@YAXPAUwbitstream@@_K@Z
// EA  : 0x829068F0
// RVA : 0x009068F0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

void __fastcall _jxr_wbitstream_intVLW(wbitstream *str, unsigned int a2, unsigned __int64 val)
{
  unsigned int v3; // r30
  wbitstream *v5; // r3
  wbitstream *v6; // r3

  if ( a2 != 0 )
  {
    if ( a2 >= 0xFB00 )
    {
      _jxr_wbitstream_uint8(str, val: 0xFCu);
      _jxr_wbitstream_uint32(str: nullptr, val: v3);
      _jxr_wbitstream_uint32(str: v6, val: a2);
    }
    else
    {
      _jxr_wbitstream_uint8(str, val: BYTE2(a2));
      _jxr_wbitstream_uint8(str: v5, val: a2);
    }
  }
  else
  {
    _jxr_wbitstream_uint8(str, val: 0xFEu);
  }
}


// ========================================================================
// ?_jxr_wbitstream_mark@@YAXPAUwbitstream@@@Z
// EA  : 0x829069A0
// RVA : 0x009069A0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\io.cpp
// ========================================================================

void __fastcall _jxr_wbitstream_mark(wbitstream *str)
{
  unsigned __int8 *v1; // r7
  unsigned int v2; // r8
  unsigned int write_count; // r10

  if ( str->bits_ready == 8 )
  {
    *str->cur_ptr = str->byte;
    v1 = str->cur_ptr + 1;
    v2 = str->write_count + 1;
    str->byte = 0;
    str->bits_ready = 0;
    str->write_count = v2;
    str->cur_ptr = v1;
  }
  write_count = str->write_count;
  str->write_count = 0;
  str->mark_stream_position = write_count;
}

