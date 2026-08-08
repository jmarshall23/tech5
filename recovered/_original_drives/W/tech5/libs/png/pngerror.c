
// ========================================================================
// png_format_buffer
// EA  : 0x83228008
// RVA : 0x01228008
// PDB : w:\tech5\libs\png\pngerror.c
// ========================================================================

void __fastcall png_format_buffer(png_struct_def *png_ptr, char *buffer, const char *error_message)
{
  unsigned __int8 *chunk_name; // r3
  int v6; // ctr
  int v7; // r10
  int v8; // r5
  int v9; // r9
  int v10; // r10
  int v11; // r10
  char *v12; // r31

  chunk_name = png_ptr->chunk_name;
  v6 = 4;
  v7 = 0;
  v8 = 0;
  do
  {
    v9 = chunk_name[v8++];
    if ( (unsigned int)v9 < 0x41 || v9 > 122 || v9 > 90 && v9 < 97 )
    {
      buffer[v7] = 91;
      v10 = v7 + 1;
      buffer[v10] = png_digit[(v9 >> 4) & 0xF];
      buffer[++v10] = png_digit[v9 & 0xF];
      v7 = v10 + 1;
      buffer[v7] = 93;
    }
    else
    {
      buffer[v7] = v9;
    }
    ++v7;
    --v6;
  }
  while ( v6 != 0 );
  if ( error_message != nullptr )
  {
    buffer[v7] = 58;
    v11 = v7 + 1;
    buffer[v11] = 32;
    v12 = &buffer[v11 + 1];
    memcpy(Dst: v12, Src: error_message, Size: 0x40u);
    v12[63] = 0;
  }
  else
  {
    buffer[v7] = 0;
  }
}


// ========================================================================
// png_default_warning
// EA  : 0x83228110
// RVA : 0x01228110
// PDB : w:\tech5\libs\png\pngerror.c
// ========================================================================

void __fastcall png_default_warning(png_struct_def *png_ptr, const char *warning_message)
{
  int v3; // r30
  char *v4; // r9
  int v5; // r8
  int v6; // r7
  int v7; // r6
  int v8; // r5
  int v9; // r4
  char v10; // r10
  char *v11; // r11
  int v12; // r3
  bool v13; // cr58
  char v14; // r10
  bool v15; // cr58
  char v16; // r10
  bool v17; // cr58
  char v18; // r10
  _iobuf *v19; // r3
  _iobuf *v20; // r3
  char v21; // [sp+50h] [-30h] BYREF
  char v22; // [sp+51h] [-2Fh] BYREF
  char v23; // [sp+52h] [-2Eh] BYREF
  char v24; // [sp+53h] [-2Dh] BYREF
  char v25; // [sp+54h] [-2Ch] BYREF

  if ( HIBYTE(png_ptr->jmpbuf[0].floats[0]) != 35 )
    goto LABEL_17;
  v3 = 0;
  v4 = (char *)png_ptr->jmpbuf[0].floats + 1;
  v5 = &v21 - (char *)png_ptr;
  v6 = &v22 - (char *)png_ptr;
  v7 = &v23 - (char *)png_ptr;
  v8 = &v24 - (char *)png_ptr;
  v9 = &v25 - (char *)png_ptr;
  do
  {
    v10 = v4[v3];
    v11 = (char *)png_ptr + v3;
    v12 = *((unsigned __int8 *)png_ptr->jmpbuf[0].floats + v3);
    *((_BYTE *)png_ptr->jmpbuf[0].floats + v3 + v5) = v10;
    if ( v12 == 32 )
      break;
    v13 = v10 == 32;
    v14 = *((_BYTE *)png_ptr->jmpbuf[0].floats + v3 + 2);
    v11[v6] = v14;
    if ( v13 )
    {
      ++v3;
      break;
    }
    v15 = v14 == 32;
    v16 = *((_BYTE *)png_ptr->jmpbuf[0].floats + v3 + 3);
    v11[v7] = v16;
    if ( v15 )
    {
      v3 += 2;
      break;
    }
    v17 = v16 == 32;
    v18 = *((_BYTE *)&png_ptr->jmpbuf[0].floats[1] + v3);
    v11[v8] = v18;
    if ( v17 )
    {
      v3 += 3;
      break;
    }
    v11[v9] = *((_BYTE *)&png_ptr->jmpbuf[0].floats[1] + v3 + 1);
    if ( v18 == 32 )
    {
      v3 += 4;
      break;
    }
    v3 += 5;
  }
  while ( v3 < 15 );
  if ( v3 > 1 && v3 < 15 )
  {
    *(&v21 + v3 - 1) = 0;
    v19 = _iob_func();
    fprintf(str: v19 + 2, format: "libpng warning no. %s: %s\n", &v21, (const char *)png_ptr + v3);
  }
  else
  {
LABEL_17:
    v20 = _iob_func();
    fprintf(str: v20 + 2, format: "libpng warning: %s\n", (const char *)png_ptr);
  }
}


// ========================================================================
// png_set_error_fn
// EA  : 0x83228278
// RVA : 0x01228278
// PDB : w:\tech5\libs\png\pngerror.c
// ========================================================================

void __fastcall png_set_error_fn(
        png_struct_def *png_ptr,
        void *error_ptr,
        void (__fastcall *error_fn)(png_struct_def *, const char *),
        void (__fastcall *warning_fn)(png_struct_def *, const char *))
{
  if ( png_ptr != nullptr )
  {
    png_ptr->error_ptr = error_ptr;
    png_ptr->error_fn = error_fn;
    png_ptr->warning_fn = warning_fn;
  }
}


// ========================================================================
// png_error
// EA  : 0x83228290
// RVA : 0x01228290
// PDB : w:\tech5\libs\png\pngerror.c
// ========================================================================

void __fastcall png_error(png_struct_def *png_ptr, const char *error_message)
{
  const char *v3; // r31
  unsigned int flags; // r10
  int v5; // r11
  int v6; // r10
  int v7; // r11
  bool v8; // zf
  int v9; // ctr
  void (__fastcall *error_fn)(png_struct_def *, const char *); // r11
  int i; // r30
  char v12; // r10
  int v13; // r3
  bool v14; // cr58
  char v15; // r10
  bool v16; // cr58
  char v17; // r10
  bool v18; // cr58
  char v19; // r10
  _iobuf *v20; // r3
  _iobuf *v21; // r3
  _iobuf *v22; // r3
  char v23[16]; // [sp+50h] [-50h] BYREF
  char v24[64]; // [sp+60h] [-40h] BYREF

  v3 = error_message;
  if ( png_ptr == nullptr )
    goto LABEL_21;
  flags = png_ptr->flags;
  if ( (flags & 0xC0000) != 0 )
  {
    if ( *error_message == 35 )
    {
      v5 = 1;
      while ( error_message[v5] != 32 )
      {
        if ( error_message[v5 + 1] == 32 )
        {
          ++v5;
          break;
        }
        v5 += 2;
        if ( v5 >= 15 )
          break;
      }
      if ( (flags & 0x80000) == 0 )
      {
        v3 = &error_message[v5];
        goto LABEL_19;
      }
      v6 = v5 - 1;
      v8 = v5 - 1 <= 0;
      v7 = 0;
      if ( !v8 )
      {
        v9 = v6;
        do
        {
          v24[v7] = error_message[v7 + 1];
          ++v7;
          --v9;
        }
        while ( v9 != 0 );
      }
      v24[v7] = 0;
    }
    else
    {
      if ( (flags & 0x80000) == 0 )
        goto LABEL_19;
      strcpy(v24, "0");
    }
    v3 = v24;
  }
LABEL_19:
  error_fn = png_ptr->error_fn;
  if ( error_fn != nullptr )
    error_fn(a1: png_ptr, a2: v3);
LABEL_21:
  if ( *v3 == 35 )
  {
    for ( i = 0; i < 15; i += 5 )
    {
      v12 = v3[i + 1];
      v13 = (unsigned __int8)v3[i];
      v23[i] = v12;
      if ( v13 == 32 )
        break;
      v14 = v12 == 32;
      v15 = v3[i + 2];
      v23[i + 1] = v15;
      if ( v14 )
      {
        ++i;
        break;
      }
      v16 = v15 == 32;
      v17 = v3[i + 3];
      v23[i + 2] = v17;
      if ( v16 )
      {
        i += 2;
        break;
      }
      v18 = v17 == 32;
      v19 = v3[i + 4];
      v23[i + 3] = v19;
      if ( v18 )
      {
        i += 3;
        break;
      }
      v23[i + 4] = v3[i + 5];
      if ( v19 == 32 )
      {
        i += 4;
        break;
      }
    }
    if ( i <= 1 || i >= 15 )
    {
      v21 = _iob_func();
      fprintf(str: v21 + 2, format: "libpng error: %s, offset=%d\n", v3, i);
    }
    else
    {
      v23[i - 1] = 0;
      v20 = _iob_func();
      fprintf(str: v20 + 2, format: "libpng error no. %s: %s\n", v23, &v3[i]);
    }
  }
  else
  {
    v22 = _iob_func();
    fprintf(str: v22 + 2, format: "libpng error: %s\n", v3);
  }
  if ( png_ptr != nullptr )
    longjmp(Buf: png_ptr->jmpbuf, Value: 1);
}


// ========================================================================
// png_warning
// EA  : 0x832284F0
// RVA : 0x012284F0
// PDB : w:\tech5\libs\png\pngerror.c
// ========================================================================

void __fastcall png_warning(png_struct_def *png_ptr, png_struct_def *warning_message)
{
  int i; // r11
  void (*warning_fn)(void); // r10

  if ( png_ptr != nullptr )
  {
    if ( (png_ptr->flags & 0xC0000) != 0 && HIBYTE(warning_message->jmpbuf[0].floats[0]) == 35 )
    {
      for ( i = 1; i < 15; i += 2 )
      {
        if ( *((_BYTE *)warning_message->jmpbuf[0].floats + i) == 32 )
          break;
        if ( *((_BYTE *)warning_message->jmpbuf[0].floats + i + 1) == 32 )
          break;
      }
    }
    warning_fn = (void (*)(void))png_ptr->warning_fn;
    if ( warning_fn != nullptr )
      warning_fn();
  }
  else
  {
    png_default_warning(png_ptr: warning_message, (const char *)warning_message);
  }
}


// ========================================================================
// png_chunk_error
// EA  : 0x83228570
// RVA : 0x01228570
// PDB : w:\tech5\libs\png\pngerror.c
// ========================================================================

void __fastcall png_chunk_error(png_struct_def *png_ptr, const char *error_message)
{
  png_struct_def *v2; // r31
  char v3[96]; // [sp+50h] [-70h] BYREF

  v2 = png_ptr;
  if ( png_ptr != nullptr )
  {
    png_format_buffer(png_ptr, buffer: v3, error_message);
    error_message = v3;
    png_ptr = v2;
  }
  png_error(png_ptr, error_message);
}


// ========================================================================
// png_chunk_warning
// EA  : 0x832285C0
// RVA : 0x012285C0
// PDB : w:\tech5\libs\png\pngerror.c
// ========================================================================

void __fastcall png_chunk_warning(png_struct_def *png_ptr, char *warning_message)
{
  png_struct_def *v2; // r31
  char v3[96]; // [sp+50h] [-70h] BYREF

  v2 = png_ptr;
  if ( png_ptr != nullptr )
  {
    png_format_buffer(png_ptr, buffer: v3, error_message: warning_message);
    warning_message = v3;
    png_ptr = v2;
  }
  png_warning(png_ptr, (png_struct_def *)warning_message);
}

