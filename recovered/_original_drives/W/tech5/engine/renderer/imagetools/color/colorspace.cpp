
// ========================================================================
// ?ConvertRGBToCoCg_Y@idColorSpace@@YAXPAEPBEHH@Z
// EA  : 0x828C6A68
// RVA : 0x008C6A68
// PDB : w:\tech5\engine\renderer\imagetools\color\colorspace.cpp
// ========================================================================

void __fastcall idColorSpace::ConvertRGBToCoCg_Y(
        unsigned __int8 *dst,
        const unsigned __int8 *src,
        int width,
        int height)
{
  int v4; // r11
  unsigned __int8 *v5; // r5
  int v6; // ctr
  const unsigned __int8 *v7; // r6
  int v8; // r3
  int v9; // r9
  int v10; // r8
  int v11; // r7
  int v12; // r11
  char v13; // r10
  int v14; // r10
  int v15; // r11

  v4 = width * height;
  if ( width * height > 0 )
  {
    v5 = dst - 1;
    v6 = v4;
    v7 = src + 2;
    v8 = dst - src;
    do
    {
      v9 = *(v7 - 2);
      v10 = *v7;
      v11 = *(v7 - 1);
      v12 = ((2 * (v9 + 1) - __ROL4__(v10, 1)) >> 2) + 128;
      if ( v12 >= 0 )
      {
        v13 = -1;
        if ( v12 <= 255 )
          v13 = v12;
      }
      else
      {
        v13 = 0;
      }
      v5[1] = v13;
      v14 = ((2 * v11 - v10 - v9 + 2) >> 2) + 128;
      if ( v14 >= 0 )
      {
        if ( v14 > 255 )
          LOBYTE(v14) = -1;
      }
      else
      {
        LOBYTE(v14) = 0;
      }
      v7[v8] = 0;
      v5[2] = v14;
      v15 = (2 * v11 + v10 + v9 + 2) >> 2;
      if ( v15 >= 0 )
      {
        if ( v15 > 255 )
          LOBYTE(v15) = -1;
      }
      else
      {
        LOBYTE(v15) = 0;
      }
      v7 += 4;
      v5 += 4;
      *v5 = v15;
      --v6;
    }
    while ( v6 != 0 );
  }
}


// ========================================================================
// ?ConvertCoCg_YToRGB@idColorSpace@@YAXPAEPBEHH@Z
// EA  : 0x828C6B50
// RVA : 0x008C6B50
// PDB : w:\tech5\engine\renderer\imagetools\color\colorspace.cpp
// ========================================================================

void __fastcall idColorSpace::ConvertCoCg_YToRGB(
        unsigned __int8 *dst,
        const unsigned __int8 *src,
        int width,
        int height)
{
  int v4; // r11
  unsigned __int8 *v5; // r5
  int v6; // ctr
  const unsigned __int8 *v7; // r11
  int v8; // r3
  int v9; // r8
  int v10; // r7
  int v11; // r9
  unsigned __int8 v12; // r4
  int v13; // r6
  int v14; // r10
  int v15; // r10
  int v16; // r10

  v4 = width * height;
  if ( width * height > 0 )
  {
    v5 = dst - 1;
    v6 = v4;
    v7 = src + 2;
    v8 = dst - src;
    do
    {
      v9 = v7[1];
      v10 = *(v7 - 1) - 128;
      v11 = *(v7 - 2) - 128;
      v12 = *v7;
      v13 = v9 - v10;
      v14 = v9 - v10 + v11;
      if ( v14 >= 0 )
      {
        if ( v14 > 255 )
          LOBYTE(v14) = -1;
      }
      else
      {
        LOBYTE(v14) = 0;
      }
      v5[1] = v14;
      v15 = v9 + v10;
      if ( v9 + v10 >= 0 )
      {
        if ( v15 > 255 )
          LOBYTE(v15) = -1;
      }
      else
      {
        LOBYTE(v15) = 0;
      }
      v5[2] = v15;
      v16 = v13 - v11;
      if ( v13 - v11 >= 0 )
      {
        if ( v16 > 255 )
          LOBYTE(v16) = -1;
      }
      else
      {
        LOBYTE(v16) = 0;
      }
      v7[v8] = v16;
      v7 += 4;
      v5 += 4;
      *v5 = v12;
      --v6;
    }
    while ( v6 != 0 );
  }
}

