
// ========================================================================
// ?CreateSingleMipMultiChannel@idMipMap@@SA_NPBEHHHPAE@Z
// EA  : 0x828C6C28
// RVA : 0x008C6C28
// PDB : w:\tech5\engine\renderer\imagetools\filter\mipmap.cpp
// ========================================================================

int __fastcall idMipMap::CreateSingleMipMultiChannel(
        const unsigned __int8 *src,
        int width,
        int height,
        int channels,
        unsigned __int8 *dest)
{
  int v5; // r27
  int v6; // r10
  const unsigned __int8 *v7; // r4
  int v9; // r11
  int v10; // r23
  bool v11; // zf
  const unsigned __int8 *v12; // r31
  int v13; // r26
  int v14; // r4
  unsigned __int8 *v15; // r3
  int k; // r29
  int v17; // r11
  int v18; // ctr
  const unsigned __int8 *v19; // r9
  const unsigned __int8 *v20; // r8
  int v22; // r11
  int i; // r5
  int v24; // r11
  int j; // ctr

  if ( width < 1 || height < 1 || width + height == 2 )
    return 0;
  v5 = width >> 1;
  v6 = width * channels;
  v9 = height >> 1;
  v10 = 2 * channels;
  v11 = width >> 1 == 0;
  v7 = src;
  if ( v11 || v9 == 0 )
  {
    v22 = v5 + v9;
    if ( v22 > 0 )
    {
      for ( i = v22; i != 0; --i )
      {
        v24 = 0;
        if ( channels > 0 )
        {
          for ( j = channels; j != 0; --j )
          {
            dest[v24] = (v7[channels + v24] + v7[v24]) >> 1;
            ++v24;
          }
        }
        v7 += v10;
        dest += channels;
      }
    }
    return 1;
  }
  v12 = &src[v6];
  if ( v9 <= 0 )
    return 1;
  v13 = height >> 1;
  do
  {
    if ( v5 > 0 )
    {
      v14 = 0;
      v15 = dest;
      for ( k = v5; k != 0; --k )
      {
        v17 = 0;
        if ( channels > 0 )
        {
          v18 = channels;
          v19 = &v12[v14 - v6];
          v20 = v19;
          do
          {
            v15[v17] = (v20[channels] + v12[v14 + v17 + channels] + v19[v17] + v12[v14 + v17]) >> 2;
            v20 = &v19[++v17];
            --v18;
          }
          while ( v18 != 0 );
        }
        v14 += v10;
        v15 += channels;
      }
    }
    --v13;
    v12 += 2 * v6;
    dest += v5 * channels;
  }
  while ( v13 != 0 );
  return 1;
}


// ========================================================================
// ?CreateSingleMip@idMipMap@@SA_NPBEHHPAE@Z
// EA  : 0x828C6D88
// RVA : 0x008C6D88
// PDB : w:\tech5\engine\renderer\imagetools\filter\mipmap.cpp
// ========================================================================

int __fastcall idMipMap::CreateSingleMip(const unsigned __int8 *src, int width, int height, unsigned __int8 *dest)
{
  return idMipMap::CreateSingleMipMultiChannel(src, width, height, channels: 4, dest);
}

