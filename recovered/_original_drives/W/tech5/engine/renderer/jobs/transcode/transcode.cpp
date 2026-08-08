
// ========================================================================
// ?DrawPixelNumber@@YAXPAEHPBDHHHHH@Z
// EA  : 0x8292AA10
// RVA : 0x0092AA10
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode.cpp
// ========================================================================

void __fastcall DrawPixelNumber(
        unsigned __int8 *dest,
        int byteStride,
        const char *text,
        int scaleX,
        int scaleY,
        int pixelStride,
        int frontColor,
        int backColor)
{
  int i; // r11
  const char **v9; // r21
  int v10; // r23
  int v11; // r22
  int v12; // r26
  int v13; // r24
  int j; // r25
  int v15; // r30
  int v16; // ctr
  int v17; // r31
  unsigned __int8 *v18; // r11

  for ( i = *text; *text != 0; i = *text )
  {
    if ( i >= 48 && i <= 57 )
    {
      v9 = binFont;
      v10 = 0;
      do
      {
        v11 = 0;
        v12 = 0;
        do
        {
          v13 = backColor;
          if ( (*v9)[4 * *text - 192 + v11] != 32 )
            v13 = frontColor;
          for ( j = 0; j < scaleY; ++j )
          {
            v15 = 0;
            if ( scaleX > 0 )
            {
              v16 = scaleX;
              v17 = v13;
              do
              {
                v18 = &dest[(v12 + v15++) * pixelStride + (v10 + j) * byteStride];
                *v18 = mipBlends[v17][0];
                v18[1] = mipBlends[v17][1];
                v18[2] = mipBlends[v17][2];
                v18[3] = mipBlends[v17][3];
                --v16;
              }
              while ( v16 != 0 );
            }
          }
          ++v11;
          v12 += scaleX;
        }
        while ( v11 < 4 );
        ++v9;
        v10 += scaleY;
      }
      while ( (int)v9 < (int)sourceText );
    }
    ++text;
    dest += 4 * scaleX * pixelStride;
  }
}


// ========================================================================
// DrawText
// EA  : 0x8292AB40
// RVA : 0x0092AB40
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode.cpp
// ========================================================================

void __fastcall DrawText(
        unsigned __int8 *dest,
        int byteStride,
        const char **text,
        int scale,
        int pixelStride,
        int frontColor,
        int backColor)
{
  int v8; // r24
  int i; // r21
  int v10; // r23
  int v11; // r26
  int v12; // r11
  int v13; // r10
  int v14; // r31
  int j; // r25
  int v16; // r5
  int k; // ctr
  int v18; // r11
  unsigned __int8 *v19; // r11

  v8 = 0;
  for ( i = 8; i != 0; --i )
  {
    v10 = 0;
    if ( **text != 0 )
    {
      v11 = 0;
      do
      {
        v12 = backColor;
        if ( (*text)[v10] != 32 )
          v12 = frontColor;
        if ( scale > 0 )
        {
          v13 = v12;
          v14 = v8;
          for ( j = scale; j != 0; --j )
          {
            v16 = 0;
            for ( k = scale; k != 0; --k )
            {
              v18 = (v11 + v16++) * pixelStride;
              v19 = &dest[v18 + v14];
              *v19 = mipBlends[v13][0];
              v19[1] = mipBlends[v13][1];
              v19[2] = mipBlends[v13][2];
              v19[3] = mipBlends[v13][3];
            }
            v14 += byteStride;
          }
        }
        ++v10;
        v11 += scale;
      }
      while ( (*text)[v10] != 0 );
    }
    ++text;
    v8 += byteStride * scale;
  }
}


// ========================================================================
// itoa_0
// EA  : 0x8292AC28
// RVA : 0x0092AC28
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode.cpp
// ========================================================================

void __fastcall itoa_0(char *a, int i)
{
  char v2; // r11
  char v3; // r11
  char v4; // r11

  if ( i < 1000 )
    v2 = 32;
  else
    v2 = i % 10000 / 1000 + 48;
  *a = v2;
  if ( i < 100 )
    v3 = 32;
  else
    v3 = i % 1000 / 100 + 48;
  a[1] = v3;
  if ( i < 10 )
    v4 = 32;
  else
    v4 = i % 100 / 10 + 48;
  a[2] = v4;
  a[3] = i % 10 + 48;
}


// ========================================================================
// ?BrightColorForNumber@@YAXHAAE00@Z
// EA  : 0x8292AD28
// RVA : 0x0092AD28
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode.cpp
// ========================================================================

void __fastcall BrightColorForNumber(int number, unsigned __int8 *Y, unsigned __int8 *Co, unsigned __int8 *Cg)
{
  int v5; // r10
  int v6; // r10
  unsigned int v7; // r9
  unsigned int v8; // r10
  unsigned int v9; // r8
  int v10; // r10
  int v11; // r11
  int v12; // r11
  int v13; // r11

  do
  {
    do
    {
      v5 = 1103515245 * number + 12345;
      v7 = (unsigned __int8)(v5 >> 23);
      v6 = 1103515245 * v5 + 12345;
      number = 1103515245 * v6 + 12345;
      v8 = (unsigned __int8)(v6 >> 23);
      v9 = (unsigned __int8)(number >> 23);
    }
    while ( (int)(v7 + v8 + v9) < 255 );
  }
  while ( v7 < 0x80 && v8 < 0x80 && v9 < 0x80 );
  v10 = 2 * v8;
  v11 = (int)(v10 + v7 + v9 + 2) >> 2;
  if ( v11 >= 0 )
  {
    if ( v11 > 255 )
      LOBYTE(v11) = -1;
  }
  else
  {
    LOBYTE(v11) = 0;
  }
  *Y = v11;
  v12 = ((int)(2 * (v7 + 1) - 2 * v9) >> 2) + 128;
  if ( v12 >= 0 )
  {
    if ( v12 > 255 )
      LOBYTE(v12) = -1;
  }
  else
  {
    LOBYTE(v12) = 0;
  }
  *Co = v12;
  v13 = ((int)(v10 - v7 - v9 + 2) >> 2) + 128;
  if ( v13 >= 0 )
  {
    if ( v13 <= 255 )
      *Cg = v13;
    else
      *Cg = -1;
  }
  else
  {
    *Cg = 0;
  }
}


// ========================================================================
// ?DXT_Decompress@@YAXHHPBEHPAE@Z
// EA  : 0x8292AE48
// RVA : 0x0092AE48
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode.cpp
// ========================================================================

void __fastcall DXT_Decompress(
        const int pageHeaderSize,
        const int diskOffsetScale,
        const unsigned __int8 *src,
        int srcLen,
        unsigned __int8 *dest)
{
  int v5; // r10
  int v7; // r9
  const unsigned __int8 *v9; // r4
  idDxtDecoder v10[2]; // [sp+50h] [-30h] BYREF

  v5 = ~(diskOffsetScale - 1);
  v7 = (pageHeaderSize + diskOffsetScale + srcLen - 1) & v5;
  if ( v7 == ((pageHeaderSize + diskOffsetScale + 40959) & v5) )
  {
    idDxtDecoder::DecompressImageDXT1(this: v10, inBuf: src, outBuf: dest + 0x20000, width: 128, height: 128);
    idDxtDecoder::DecompressYCoCgDXT5(this: v10, inBuf: src + 0x2000, outBuf: dest, width: 128, height: 128);
    v9 = src + 24576;
  }
  else
  {
    if ( v7 != ((pageHeaderSize + diskOffsetScale + 49151) & v5) )
      return;
    idDxtDecoder::DecompressImageDXT5(this: v10, inBuf: src, outBuf: dest + 0x20000, width: 128, height: 128);
    idDxtDecoder::DecompressYCoCgDXT5(this: v10, inBuf: src + 0x4000, outBuf: dest, width: 128, height: 128);
    v9 = src + 0x8000;
  }
  idDxtDecoder::DecompressImageDXT5(this: v10, inBuf: v9, outBuf: dest + 0x10000, width: 128, height: 128);
}


// ========================================================================
// ?HDP_Decompress@@YAXPBUHDPHeader_t@@PBEHPAE@Z
// EA  : 0x8292AF48
// RVA : 0x0092AF48
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode.cpp
// ========================================================================

void __fastcall HDP_Decompress(
        const HDPHeader_t *header,
        unsigned __int8 *src,
        unsigned int srcLen,
        unsigned __int8 *dest)
{
  int normalSize; // r11
  unsigned __int8 *v8; // r29
  unsigned __int8 *v9; // r28
  int v10; // r9
  unsigned int v11; // r10
  int v12; // r7
  int v13; // r8
  idBareHDP *v14; // r3
  int qualityNormal; // r5
  unsigned __int8 *v16; // r4
  unsigned int v17; // r8
  int v18; // r12
  int v19; // r7
  int v20; // r11
  unsigned __int8 *v21; // r4
  unsigned int specularSize; // r8
  int diffuseSize; // r10
  int v24; // r11
  unsigned int powerSize; // r8
  int v26; // r9
  const unsigned __int8 *v27; // r8
  int v28; // r10
  int i; // ctr
  int v30; // r7
  char v31; // r6
  int v32; // r11
  unsigned int alphaSize; // r8
  int v34; // r10
  int v35; // r11
  int v36; // r3
  int v37; // r4
  int j; // r10
  int v39; // r11
  int v40; // r9
  int k; // ctr
  unsigned __int8 v42; // r7
  int v43; // r8
  int m; // r7
  int v45; // r10
  int n; // ctr
  unsigned __int8 *v47; // r11
  int v48; // r8
  int v49; // r4
  int v50; // r5
  int v51; // r9
  int v52; // r3
  int v53; // r4
  int v54; // r27
  int v55; // r24
  int v56; // r23
  int v57; // r22
  int v58; // r21
  int v59; // r6
  int v60; // r5
  int v61; // r3
  int v62; // r4
  int ii; // r5
  int v64; // r6
  unsigned __int8 *v65; // r10
  int v66; // r7
  int jj; // ctr
  int v68; // r11
  int v69; // r9
  unsigned __int8 *v70; // r11
  unsigned int v71; // r8
  _DWORD back_chain[20]; // [sp+0h] [-170h]
  int v73; // [sp+50h] [-120h] BYREF
  idBareHDP v74; // [sp+60h] [-110h] BYREF

  normalSize = header->normalSize;
  v8 = dest + 0x20000;
  v9 = dest + 0x10000;
  if ( header->normalSize != 0
    && (v10 = header->specularSize, header->specularSize != 0)
    && (v11 = header->diffuseSize, header->diffuseSize != 0)
    && (v12 = header->powerSize, header->powerSize != 0) )
  {
    if ( v11 + normalSize <= srcLen && v11 + v10 + normalSize <= srcLen && v12 + v11 + v10 + normalSize <= srcLen )
    {
      v13 = header->flags & 8;
      if ( ((header->flags & 8) == 0 || (v13 << 8) + v12 + v11 + v10 + normalSize <= srcLen)
        && (header->alphaSize == 0 || (v13 << 8) + header->alphaSize + v12 + v11 + v10 + normalSize <= srcLen)
        && v11 <= srcLen )
      {
        v14 = idBareHDP::idBareHDP(this: &v74);
        ((void (__fastcall *)(idBareHDP *))RtlCheckStack12)(a1: v14);
        qualityNormal = header->qualityNormal;
        v16 = &src[header->diffuseSize];
        v17 = header->normalSize;
        *(_DWORD *)((char *)back_chain + v18) = back_chain[0];
        v74.tempBufferSize = 33792;
        v74.quality = qualityNormal;
        v74.tempBuffer = &v73;
        idBareHDP::DecompressImageNormalMap(
          this: &v74,
          inBuf: v16,
          outBuf: v9,
          width: 0x80u,
          height: 0x80u,
          inputBytes: v17,
          mipLevel: 0);
        v19 = header->flags & 4;
        v20 = header->normalSize + header->diffuseSize;
        v74.quality = header->qualitySpecular;
        v21 = &src[v20];
        specularSize = header->specularSize;
        if ( v19 != 0 )
          idBareHDP::DecompressImageGrayScale(
            this: &v74,
            inBuf: v21,
            outBuf: v8,
            width: 0x80u,
            height: 0x80u,
            inputBytes: specularSize,
            mipLevel: 0);
        else
          idBareHDP::DecompressImageRGB(
            this: &v74,
            inBuf: v21,
            outBuf: v8,
            width: 0x80u,
            height: 0x80u,
            inputBytes: specularSize,
            mipLevel: 0);
        diffuseSize = header->diffuseSize;
        v24 = header->specularSize + header->normalSize;
        powerSize = header->powerSize;
        v74.quality = header->qualityPower;
        idBareHDP::DecompressImageMono(
          this: &v74,
          inBuf: &src[v24 + diffuseSize],
          outBuf: dest,
          width: 0x20u,
          height: 0x20u,
          inputBytes: powerSize,
          mipLevel: 0);
        if ( (header->flags & 8) != 0 )
        {
          v26 = 0;
          v27 = &src[header->specularSize + header->normalSize + header->powerSize + header->diffuseSize];
          do
          {
            v28 = 0;
            for ( i = 128; i != 0; --i )
            {
              v30 = (v26 + v28) >> 3;
              v73 = v26 + v28;
              v31 = (v26 + v28) & 7;
              v32 = 4 * (v26 + v28++);
              v8[v32 + 3] = -((v27[v30] >> v31) & 1);
            }
            v26 += 128;
          }
          while ( v26 < 0x4000 );
        }
        alphaSize = header->alphaSize;
        if ( header->alphaSize != 0 )
        {
          v34 = header->specularSize;
          v35 = (header->flags << 8) & 0x800;
          v36 = header->normalSize;
          v37 = header->powerSize;
          v74.quality = header->qualityDiffuse;
          idBareHDP::DecompressImageMono(
            this: &v74,
            inBuf: &src[v35 + v34 + v36 + v37 + header->diffuseSize],
            outBuf: dest + 1024,
            width: 0x80u,
            height: 0x80u,
            inputBytes: alphaSize,
            mipLevel: 0);
          for ( j = 0; j < 0x4000; j += 128 )
          {
            v39 = 0;
            v40 = j;
            for ( k = 128; k != 0; --k )
            {
              v42 = dest[v40 + 1024];
              v43 = 4 * (j + v39++);
              v40 = j + v39;
              v8[v43 + 3] = v42;
            }
          }
        }
        for ( m = 0; m < 0x4000; m += 128 )
        {
          v45 = 0;
          for ( n = 32; n != 0; --n )
          {
            v47 = &v8[4 * m + 4 * v45];
            v48 = 4 * (m + v45 + 2);
            v49 = m + v45 + 3;
            v45 += 4;
            v50 = v47[1];
            v51 = 4 * v49;
            *v47 <<= header->flags & 3;
            v52 = v47[2];
            v54 = v47[5];
            v55 = v8[v48];
            v56 = v47[9];
            v57 = v8[4 * v49];
            v53 = v47[4];
            v58 = v47[13];
            v59 = v47[6];
            v47[1] = v50 << (header->flags & 3);
            v60 = v47[10];
            v47[2] = v52 << (header->flags & 3);
            v61 = v47[14];
            v47[4] = v53 << (header->flags & 3);
            v47[5] = v54 << (header->flags & 3);
            v47[6] = v59 << (header->flags & 3);
            v8[v48] = v55 << (header->flags & 3);
            v47[9] = v56 << (header->flags & 3);
            v47[10] = v60 << (header->flags & 3);
            v8[v51] = v57 << (header->flags & 3);
            v47[13] = v58 << (header->flags & 3);
            v47[14] = v61 << (header->flags & 3);
          }
        }
        v62 = 0;
        for ( ii = 0; ii < 128; ii += 4 )
        {
          v64 = 0;
          v65 = &dest[v62 / 4];
          do
          {
            v66 = 0;
            for ( jj = 4; jj != 0; --jj )
            {
              v68 = 32 * (ii + v66++);
              v69 = 4 * (v68 + v64);
              v70 = &v9[16 * v68 + 16 * v64];
              *v70 = *v65;
              v70[2] = 8 * ((1 << (header->flags & 3)) - 1);
              v70[4] = *v65;
              v70[6] = 8 * ((1 << (header->flags & 3)) - 1);
              v9[4 * v69 + 8] = *v65;
              v70[10] = 8 * ((1 << (header->flags & 3)) - 1);
              v9[4 * v69 + 12] = *v65;
              v70[14] = 8 * ((1 << (header->flags & 3)) - 1);
            }
            ++v64;
            ++v65;
          }
          while ( v64 < 32 );
          v62 += 128;
        }
        v71 = header->diffuseSize;
        v74.quality = header->qualityDiffuse;
        idBareHDP::DecompressImageYCoCg(
          this: &v74,
          inBuf: src,
          outBuf: dest,
          width: 0x80u,
          height: 0x80u,
          inputBytes: v71,
          mipLevel: 0);
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v74);
      }
    }
  }
  else
  {
    memset(Dst: dest + 0x20000, Val: 0, Size: 0x10000u);
    memset(Dst: dest, Val: 0, Size: 0x10000u);
    memset(Dst: v9, Val: 0, Size: 0x10000u);
  }
}


// ========================================================================
// __unwind$75593
// EA  : 0x8292B4DC
// RVA : 0x0092B4DC
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode.cpp
// ========================================================================

void _unwind_75593()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 368 + 96));
}


// ========================================================================
// ?JXR_Decompress@@YAXPBUJXRHeader_t@@PBEHPAE@Z
// EA  : 0x8292B510
// RVA : 0x0092B510
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode.cpp
// ========================================================================

void __fastcall JXR_Decompress(
        const JXRHeader_t *header,
        const unsigned __int8 *src,
        int srcLen,
        unsigned __int8 *dest)
{
  unsigned __int8 *v7; // r28
  unsigned __int8 *v8; // r29
  unsigned __int8 *v9; // r26
  idBareJXR *v10; // r3
  int qualityNormal; // r23
  const unsigned __int8 *v12; // r4
  unsigned int normalSize; // r8
  int v14; // r12
  int v15; // r7
  int v16; // r11
  const unsigned __int8 *v17; // r4
  unsigned int specularSize; // r8
  int diffuseSize; // r10
  int v20; // r11
  unsigned int powerSize; // r8
  int v22; // r9
  const unsigned __int8 *v23; // r8
  int v24; // r10
  int i; // ctr
  int v26; // r7
  char v27; // r6
  int v28; // r11
  unsigned int alphaSize; // r8
  int v30; // r10
  int v31; // r11
  int v32; // r3
  int v33; // r4
  int j; // r10
  int v35; // r11
  int v36; // r9
  int k; // ctr
  unsigned __int8 v38; // r7
  int v39; // r8
  int m; // r7
  int v41; // r10
  int n; // ctr
  unsigned __int8 *v43; // r11
  int v44; // r8
  int v45; // r4
  int v46; // r5
  int v47; // r9
  int v48; // r3
  int v49; // r4
  int v50; // r27
  int v51; // r26
  int v52; // r23
  int v53; // r22
  int v54; // r21
  int v55; // r6
  int v56; // r5
  int v57; // r3
  int v58; // r4
  int ii; // r5
  int v60; // r6
  unsigned __int8 *v61; // r10
  int v62; // r7
  int jj; // ctr
  int v64; // r11
  int v65; // r9
  unsigned __int8 *v66; // r11
  unsigned int v67; // r8
  _DWORD back_chain[20]; // [sp+0h] [-E0h]
  int v69; // [sp+50h] [-90h] BYREF
  idBareJXR v70[4]; // [sp+60h] [-80h] BYREF

  v7 = dest + 0x10000;
  v8 = dest + 0x20000;
  if ( header->normalSize != 0 && header->specularSize != 0 && header->diffuseSize != 0 && header->powerSize != 0 )
  {
    v9 = dest + 1024;
    v10 = idBareJXR::idBareJXR(this: v70);
    ((void (__fastcall *)(idBareJXR *))RtlCheckStack12)(a1: v10);
    qualityNormal = header->qualityNormal;
    v12 = &src[header->diffuseSize];
    v70[0].tempBufferSize = 0x20000;
    normalSize = header->normalSize;
    *(_DWORD *)((char *)back_chain + v14) = back_chain[0];
    v70[0].quality = qualityNormal;
    v70[0].tempBuffer = &v69;
    idBareJXR::DecompressImageNormalMap(
      this: v70,
      inBuf: v12,
      outBuf: v7,
      width: 128,
      height: 128,
      inputBytes: normalSize,
      mipLevel: 0);
    v15 = header->flags & 4;
    v16 = header->normalSize + header->diffuseSize;
    v70[0].quality = header->qualitySpecular;
    v17 = &src[v16];
    specularSize = header->specularSize;
    if ( v15 != 0 )
      idBareJXR::DecompressImageGrayScale(
        this: v70,
        inBuf: v17,
        outBuf: v8,
        width: 128,
        height: 128,
        inputBytes: specularSize,
        mipLevel: 0);
    else
      idBareJXR::DecompressImageRGB(
        this: v70,
        inBuf: v17,
        outBuf: v8,
        width: 128,
        height: 128,
        inputBytes: specularSize,
        mipLevel: 0);
    diffuseSize = header->diffuseSize;
    v20 = header->specularSize + header->normalSize;
    powerSize = header->powerSize;
    v70[0].quality = header->qualityPower;
    idBareJXR::DecompressImageMono(
      this: v70,
      inBuf: &src[v20 + diffuseSize],
      outBuf: dest,
      width: 32,
      height: 32,
      inputBytes: powerSize,
      mipLevel: 0);
    if ( (header->flags & 8) != 0 )
    {
      v22 = 0;
      v23 = &src[header->specularSize + header->normalSize + header->powerSize + header->diffuseSize];
      do
      {
        v24 = 0;
        for ( i = 128; i != 0; --i )
        {
          v26 = (v22 + v24) >> 3;
          v69 = v22 + v24;
          v27 = (v22 + v24) & 7;
          v28 = 4 * (v22 + v24++);
          v8[v28 + 3] = -((v23[v26] >> v27) & 1);
        }
        v22 += 128;
      }
      while ( v22 < 0x4000 );
    }
    alphaSize = header->alphaSize;
    if ( header->alphaSize != 0 )
    {
      v30 = header->specularSize;
      v31 = (header->flags << 8) & 0x800;
      v32 = header->normalSize;
      v33 = header->powerSize;
      v70[0].quality = header->qualityDiffuse;
      idBareJXR::DecompressImageMono(
        this: v70,
        inBuf: &src[v31 + v30 + v32 + v33 + header->diffuseSize],
        outBuf: v9,
        width: 128,
        height: 128,
        inputBytes: alphaSize,
        mipLevel: 0);
      for ( j = 0; j < 0x4000; j += 128 )
      {
        v35 = 0;
        v36 = j;
        for ( k = 128; k != 0; --k )
        {
          v38 = v9[v36];
          v39 = 4 * (j + v35++);
          v36 = j + v35;
          v8[v39 + 3] = v38;
        }
      }
    }
    for ( m = 0; m < 0x4000; m += 128 )
    {
      v41 = 0;
      for ( n = 32; n != 0; --n )
      {
        v43 = &v8[4 * m + 4 * v41];
        v44 = 4 * (m + v41 + 2);
        v45 = m + v41 + 3;
        v41 += 4;
        v46 = v43[1];
        v47 = 4 * v45;
        *v43 <<= header->flags & 3;
        v48 = v43[2];
        v50 = v43[5];
        v51 = v8[v44];
        v52 = v43[9];
        v53 = v8[4 * v45];
        v49 = v43[4];
        v54 = v43[13];
        v55 = v43[6];
        v43[1] = v46 << (header->flags & 3);
        v56 = v43[10];
        v43[2] = v48 << (header->flags & 3);
        v57 = v43[14];
        v43[4] = v49 << (header->flags & 3);
        v43[5] = v50 << (header->flags & 3);
        v43[6] = v55 << (header->flags & 3);
        v8[v44] = v51 << (header->flags & 3);
        v43[9] = v52 << (header->flags & 3);
        v43[10] = v56 << (header->flags & 3);
        v8[v47] = v53 << (header->flags & 3);
        v43[13] = v54 << (header->flags & 3);
        v43[14] = v57 << (header->flags & 3);
      }
    }
    v58 = 0;
    for ( ii = 0; ii < 128; ii += 4 )
    {
      v60 = 0;
      v61 = &dest[v58 / 4];
      do
      {
        v62 = 0;
        for ( jj = 4; jj != 0; --jj )
        {
          v64 = 32 * (ii + v62++);
          v65 = 4 * (v64 + v60);
          v66 = &v7[16 * v64 + 16 * v60];
          *v66 = *v61;
          v66[2] = 8 * ((1 << (header->flags & 3)) - 1);
          v66[4] = *v61;
          v66[6] = 8 * ((1 << (header->flags & 3)) - 1);
          v7[4 * v65 + 8] = *v61;
          v66[10] = 8 * ((1 << (header->flags & 3)) - 1);
          v7[4 * v65 + 12] = *v61;
          v66[14] = 8 * ((1 << (header->flags & 3)) - 1);
        }
        ++v60;
        ++v61;
      }
      while ( v60 < 32 );
      v58 += 128;
    }
    v67 = header->diffuseSize;
    v70[0].quality = header->qualityDiffuse;
    idBareJXR::DecompressImageYCoCg(
      this: v70,
      inBuf: src,
      outBuf: dest,
      width: 128,
      height: 128,
      inputBytes: v67,
      mipLevel: 0);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)v70);
  }
  else
  {
    memset(Dst: dest + 0x20000, Val: 0, Size: 0x10000u);
    memset(Dst: dest, Val: 0, Size: 0x10000u);
    memset(Dst: v7, Val: 0, Size: 0x10000u);
  }
}


// ========================================================================
// __unwind$75792
// EA  : 0x8292BA10
// RVA : 0x0092BA10
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode.cpp
// ========================================================================

void _unwind_75792()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 224 + 96));
}


// ========================================================================
// ?CopyUncompressed@@YAXQBQAEQBHHPBEH@Z
// EA  : 0x8292BA38
// RVA : 0x0092BA38
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode.cpp
// ========================================================================

void __fastcall CopyUncompressed(
        unsigned __int8 *const *targetImage,
        int *targetBytePitch,
        char imageFlags,
        const unsigned __int8 *src,
        int srcLength)
{
  int v9; // r24
  int v10; // r29
  int v11; // r25
  int v12; // r26
  int v13; // r27
  const unsigned __int8 *v14; // r30
  int v15; // r28
  int v16; // r24
  int v17; // r29
  const unsigned __int8 *v18; // r30
  int v19; // r25
  int v20; // r26
  int v21; // r27
  int v22; // r28
  int v23; // r24
  int v24; // r29
  int v25; // r25
  int v26; // r26
  int v27; // r27
  const unsigned __int8 *v28; // r30
  int v29; // r28

  if ( (imageFlags & 1) != 0 )
  {
    v9 = *targetBytePitch;
    v10 = 0;
    v11 = 4 * *targetBytePitch;
    v12 = 3 * *targetBytePitch;
    v13 = 2 * *targetBytePitch;
    v14 = src + 132096;
    v15 = 32;
    do
    {
      memcpy(Dst: &(*targetImage)[v10], Src: v14 - 1024, Size: 0x200u);
      memcpy(Dst: &(*targetImage)[v10 + v9], Src: v14 - 512, Size: 0x200u);
      memcpy(Dst: &(*targetImage)[v13], Src: v14, Size: 0x200u);
      memcpy(Dst: &(*targetImage)[v12], Src: v14 + 512, Size: 0x200u);
      --v15;
      v10 += v11;
      v13 += v11;
      v12 += v11;
      v14 += 2048;
    }
    while ( v15 != 0 );
  }
  if ( (imageFlags & 2) != 0 )
  {
    v16 = targetBytePitch[1];
    v17 = 0;
    v18 = src + 1024;
    v19 = 4 * v16;
    v20 = 3 * v16;
    v21 = 2 * v16;
    v22 = 32;
    do
    {
      memcpy(Dst: (void *)(v17 + *((_DWORD *)targetImage + 1)), Src: v18 - 1024, Size: 0x200u);
      memcpy(Dst: (void *)(v17 + v16 + *((_DWORD *)targetImage + 1)), Src: v18 - 512, Size: 0x200u);
      memcpy(Dst: (void *)(v21 + *((_DWORD *)targetImage + 1)), Src: v18, Size: 0x200u);
      memcpy(Dst: (void *)(v20 + *((_DWORD *)targetImage + 1)), Src: v18 + 512, Size: 0x200u);
      --v22;
      v17 += v19;
      v21 += v19;
      v20 += v19;
      v18 += 2048;
    }
    while ( v22 != 0 );
  }
  if ( (imageFlags & 4) != 0 )
  {
    v23 = targetBytePitch[2];
    v24 = 0;
    v25 = 4 * v23;
    v26 = 3 * v23;
    v27 = 2 * v23;
    v28 = src + 66560;
    v29 = 32;
    do
    {
      memcpy(Dst: (void *)(v24 + *((_DWORD *)targetImage + 2)), Src: v28 - 1024, Size: 0x200u);
      memcpy(Dst: (void *)(v24 + *((_DWORD *)targetImage + 2) + v23), Src: v28 - 512, Size: 0x200u);
      memcpy(Dst: (void *)(v27 + *((_DWORD *)targetImage + 2)), Src: v28, Size: 0x200u);
      memcpy(Dst: (void *)(v26 + *((_DWORD *)targetImage + 2)), Src: v28 + 512, Size: 0x200u);
      --v29;
      v24 += v25;
      v27 += v25;
      v26 += v25;
      v28 += 2048;
    }
    while ( v29 != 0 );
  }
}


// ========================================================================
// ?ConvertDXT5_DXT1Alpha@@YAXPAEHPBE@Z
// EA  : 0x8292BC30
// RVA : 0x0092BC30
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall ConvertDXT5_DXT1Alpha(unsigned __int8 *dst, int dstBytePitch, const unsigned __int8 *src)
{
  int v4; // r20
  const unsigned __int8 *v5; // r11
  unsigned __int8 *v6; // r23
  const unsigned __int8 *v7; // r24
  int i; // r18
  unsigned __int8 *v9; // r26
  __int64 v10; // r7
  int v11; // r11
  int v12; // ctr
  unsigned __int64 v13; // r10
  unsigned __int64 v14; // r6 OVERLAPPED
  int v15; // r8
  int v16; // r9
  char v17; // r7
  unsigned __int64 v18; // r31
  const unsigned __int8 *v19; // r11
  unsigned __int8 *v20; // r10
  int j; // ctr
  int v22; // r8
  unsigned int v23; // r31
  __int16 v24; // r3
  char v25; // r11
  char v26; // r8
  int k; // ctr
  unsigned int v28; // r7
  unsigned __int64 v29; // r10
  char v30; // r7
  int v31; // r9
  int v32; // r10
  char v33; // r7
  unsigned int v34; // r30
  int v35; // r7
  int v36; // r10
  int v37; // r7
  int v38; // r10
  unsigned int v39; // r9
  unsigned __int8 v40; // r6
  char back_chain; // [sp+0h] [-A0h] BYREF

  v4 = 0;
  v5 = src + 7;
  do
  {
    v6 = dst;
    v7 = v5;
    for ( i = 32; i != 0; --i )
    {
      v9 = (unsigned __int8 *)(v7 - 7);
      HIDWORD(v10) = *(v7 - 3);
      v11 = 6;
      v12 = 4;
      LODWORD(v10) = ((__ROL4__(*v7, 8) | *(v7 - 1)) << 8) | *(v7 - 2);
      v13 = v10 << 8;
      LODWORD(v10) = ((_DWORD)v10 << 8) | HIDWORD(v10);
      v14 = v10 << 8;
      LODWORD(v13) = v14 | HIDWORD(v13);
      LODWORD(v14) = (((unsigned int)v14 | HIDWORD(v13)) << 8) | (v13 >> 24);
      do
      {
        v15 = (v14 >> ((unsigned __int8)v11 - 3)) & 7;
        v16 = (v14 >> ((unsigned __int8)v11 - 6)) & 7;
        *(unsigned __int64 *)((char *)&v14 - 4) = v14 >> v11;
        v18 = v14 >> ((unsigned __int8)v11 + 3);
        v11 += 12;
        HIDWORD(v14) &= (unsigned __int8)*(&back_chain + (v18 & 7)) >= 0x80u
                      ? (*(unsigned __int8 *)((v17 & 7) + HIDWORD(v18)) >= 0x80u
                       ? ((unsigned __int8)*(&back_chain + v15) >= 0x80u
                        ? -((unsigned __int8)*(&back_chain + v16) >= 0x80u)
                        : 0)
                       : 0)
                      : 0;
        --v12;
      }
      while ( v12 != 0 );
      if ( BYTE3(v14) != 0 )
      {
        v19 = v7;
        v20 = v6 - 1;
        for ( j = 8; j != 0; --j )
          *++v20 = *++v19;
      }
      else
      {
        v22 = __ROL4__(v9[9], 8) | v9[8];
        v23 = (unsigned __int16)(__ROL4__(v9[11], 8) | v9[10]);
        v24 = v22;
        HIDWORD(v14) = (v9[15] | v9[14] | v9[13] | v9[12]) << v4;
        if ( (unsigned __int16)v22 > v23 )
        {
          v24 = v23;
          LOWORD(v23) = v22;
          HIDWORD(v14) = ~HIDWORD(v14);
        }
        v25 = 4;
        v26 = 6;
        for ( k = 4; k != 0; --k )
        {
          v29 = v14 >> (v26 - 6);
          v28 = (unsigned __int8)*(&back_chain + (v29 & 7));
          LODWORD(v29) = (HIDWORD(v14) >> (v25 - 4)) & 3;
          if ( v28 >= 0x80 )
          {
            if ( (_DWORD)v29 == 2 )
            {
              LODWORD(v29) = 1;
            }
            else if ( (_DWORD)v29 == 3 )
            {
              LODWORD(v29) = 2;
            }
          }
          else
          {
            LODWORD(v29) = 3;
          }
          *(unsigned __int64 *)((char *)&v14 - 4) = v14 >> (v26 - 3);
          v31 = ((_DWORD)v29 << (v25 - 4)) | HIDWORD(v29);
          v32 = (HIDWORD(v14) >> (v25 - 2)) & 3;
          if ( (unsigned __int8)*(&back_chain + (v30 & 7)) >= 0x80u )
          {
            if ( v32 == 2 )
            {
              v32 = 1;
            }
            else if ( v32 == 3 )
            {
              v32 = 2;
            }
          }
          else
          {
            v32 = 3;
          }
          *(unsigned __int64 *)((char *)&v14 - 4) = v14 >> v26;
          v34 = (unsigned __int8)*(&back_chain + (v33 & 7));
          v35 = (v32 << (v25 - 2)) | v31;
          v36 = (HIDWORD(v14) >> v25) & 3;
          if ( v34 >= 0x80 )
          {
            if ( v36 == 2 )
            {
              v36 = 1;
            }
            else if ( v36 == 3 )
            {
              v36 = 2;
            }
          }
          else
          {
            v36 = 3;
          }
          v37 = (v36 << v25) | v35;
          v38 = (HIDWORD(v14) >> (v25 + 2)) & 3;
          if ( (unsigned __int8)*(&back_chain + ((v14 >> (v26 + 3)) & 7)) >= 0x80u )
          {
            if ( v38 == 2 )
            {
              v38 = 1;
            }
            else if ( v38 == 3 )
            {
              v38 = 2;
            }
          }
          else
          {
            v38 = 3;
          }
          v39 = (v38 << (v25 + 2)) | v37;
          v26 += 12;
          v25 += 8;
        }
        *v6 = v24;
        v6[2] = v23;
        v40 = v39 >> v4;
        v6[1] = HIBYTE(v24);
        v6[3] = BYTE2(v23);
        v6[4] = v40;
        v6[5] = v40;
        v6[6] = v40;
        v6[7] = v40;
      }
      v7 += 16;
      v6 += 8;
    }
    v4 += 8;
    dst += dstBytePitch;
    v5 = v7;
  }
  while ( v4 < 256 );
}


// ========================================================================
// ?CopyDXTCompressed@@YAXQBQAEQBHHPBEHHH@Z
// EA  : 0x8292C0D0
// RVA : 0x0092C0D0
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode.cpp
// ========================================================================

void __fastcall CopyDXTCompressed(
        unsigned __int8 *const *targetImage,
        int *targetBytePitch,
        char imageFlags,
        const unsigned __int8 *src,
        int srcLength,
        int pageHeaderSize,
        int diskOffsetScale)
{
  int v8; // r10
  int v11; // r7
  int v13; // r10
  char *v14; // r29
  const unsigned __int8 *v15; // r30
  int v16; // r25
  int i; // r31
  char *v18; // r29
  const unsigned __int8 *v19; // r30
  int v20; // r25
  int j; // r31
  char *v22; // r29
  const unsigned __int8 *v23; // r30
  int v24; // r28
  int k; // r31
  char *v26; // r29
  const unsigned __int8 *v27; // r30
  int v28; // r25
  int m; // r31
  char *v30; // r29
  int v31; // r28
  int v32; // r31
  const unsigned __int8 *v33; // r30

  v8 = srcLength + pageHeaderSize + diskOffsetScale;
  v11 = ~(diskOffsetScale - 1);
  v13 = (v8 - 1) & v11;
  if ( v13 == ((pageHeaderSize + diskOffsetScale + 40959) & v11) )
  {
    if ( (imageFlags & 1) != 0 )
    {
      v14 = (char *)*targetImage;
      v15 = src;
      v16 = *targetBytePitch;
      for ( i = 32; i != 0; --i )
      {
        memcpy(Dst: v14, Src: v15, Size: 0x100u);
        v15 += 256;
        v14 += v16;
      }
    }
    if ( (imageFlags & 2) != 0 )
    {
      v18 = *((char **)targetImage + 1);
      v19 = src + 0x2000;
      v20 = targetBytePitch[1];
      for ( j = 32; j != 0; --j )
      {
        memcpy(Dst: v18, Src: v19, Size: 0x200u);
        v19 += 512;
        v18 += v20;
      }
    }
    if ( (imageFlags & 4) != 0 )
    {
      v22 = *((char **)targetImage + 2);
      v23 = src + 24576;
      v24 = targetBytePitch[2];
      for ( k = 32; k != 0; --k )
      {
        memcpy(Dst: v22, Src: v23, Size: 0x200u);
        v23 += 512;
        v22 += v24;
      }
    }
  }
  else if ( v13 == ((pageHeaderSize + diskOffsetScale + 49151) & v11) )
  {
    if ( (imageFlags & 1) != 0 )
      ConvertDXT5_DXT1Alpha(dst: *targetImage, dstBytePitch: *targetBytePitch, src);
    if ( (imageFlags & 2) != 0 )
    {
      v26 = *((char **)targetImage + 1);
      v27 = src + 0x4000;
      v28 = targetBytePitch[1];
      for ( m = 32; m != 0; --m )
      {
        memcpy(Dst: v26, Src: v27, Size: 0x200u);
        v27 += 512;
        v26 += v28;
      }
    }
    if ( (imageFlags & 4) != 0 )
    {
      v30 = *((char **)targetImage + 2);
      v31 = targetBytePitch[2];
      v32 = 32;
      v33 = src + 0x8000;
      do
      {
        memcpy(Dst: v30, Src: v33, Size: 0x200u);
        --v32;
        v33 += 512;
        v30 += v31;
      }
      while ( v32 != 0 );
    }
  }
}


// ========================================================================
// ?StripPageBorder@@YAXPAE@Z
// EA  : 0x8292C290
// RVA : 0x0092C290
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall StripPageBorder(unsigned __int8 *dst)
{
  __int64 v1; // r22 OVERLAPPED
  char *v3; // r30
  __int64 v4; // r9 OVERLAPPED
  unsigned __int8 *v5; // r11
  int v6; // r31
  double v7; // fp28
  unsigned __int8 *v8; // r5
  double v9; // fp2
  int v10; // r3
  float *v11; // r7
  double v12; // fp11
  int v13; // r6
  double v14; // fp10
  double v15; // fp9
  int v16; // r10
  double v17; // fp12
  double v18; // fp8
  __int64 v19; // r11
  double v20; // fp7
  double v21; // fp6
  double v22; // fp5
  int i; // ctr
  __int128 v24; // r28 OVERLAPPED
  __int64 v25; // r24
  char v26; // r10
  char v27; // r11
  char v28; // r11
  char v29; // r11
  float v30[3]; // [sp+B0h] [-F0h] BYREF
  float v31[35]; // [sp+BCh] [-E4h] BYREF

  v3 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\engine\\renderer\\jobs\\transcode\\Transcode.cpp(919) : TAG_VIRTUALTEXTURE",
                 size: 0x10000u,
                 tag: TAG_VIRTUALTEXTURE,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  memcpy(Dst: v3, Src: dst, Size: 0x10000u);
  HIDWORD(v4) = 0x82000000;
  v5 = dst + 2;
  v6 = 128;
  v7 = 4.0;
  do
  {
    LODWORD(v4) = (int)v7;
    v8 = v5;
    v9 = 4.0;
    v10 = 128;
    v30[0] = (float)((float)((float)((float)1.5 - (float)((float)((float)v7 - (float)v4) * (float)0.75))
                           * (float)((float)v7 - (float)v4))
                   - (float)0.75)
           * (float)((float)v7 - (float)v4);
    v30[1] = (float)((float)((float)((float)((float)((float)v7 - (float)v4) * (float)1.25) - (float)2.25)
                           * (float)((float)v7 - (float)v4))
                   * (float)((float)v7 - (float)v4))
           + (float)1.0;
    v30[2] = (float)((float)((float)((float)1.5 - (float)((float)((float)v7 - (float)v4) * (float)1.25))
                           * (float)((float)v7 - (float)v4))
                   + (float)0.75)
           * (float)((float)v7 - (float)v4);
    v31[0] = (float)((float)((float)((float)((float)v7 - (float)v4) * (float)0.75) - (float)0.75)
                   * (float)((float)v7 - (float)v4))
           * (float)((float)v7 - (float)v4);
    do
    {
      v11 = v30;
      v12 = 0.0;
      v13 = 4;
      v14 = 0.0;
      v15 = 0.0;
      v16 = (int)v9;
      HIDWORD(v4) = ((int)v7 << 7) + (int)v9 - 128;
      v17 = 0.0;
      v31[1] = (float)((float)((float)((float)1.5
                                     - (float)((float)((float)v9 - (float)*(__int64 *)((char *)&v4 - 4)) * (float)0.75))
                             * (float)((float)v9 - (float)*(__int64 *)((char *)&v4 - 4)))
                     - (float)0.75)
             * (float)((float)v9 - (float)*(__int64 *)((char *)&v4 - 4));
      v31[2] = (float)((float)((float)((float)((float)((float)v9 - (float)*(__int64 *)((char *)&v4 - 4)) * (float)1.25)
                                     - (float)2.25)
                             * (float)((float)v9 - (float)*(__int64 *)((char *)&v4 - 4)))
                     * (float)((float)v9 - (float)*(__int64 *)((char *)&v4 - 4)))
             + (float)1.0;
      v31[3] = (float)((float)((float)((float)1.5
                                     - (float)((float)((float)v9 - (float)*(__int64 *)((char *)&v4 - 4)) * (float)1.25))
                             * (float)((float)v9 - (float)*(__int64 *)((char *)&v4 - 4)))
                     + (float)0.75)
             * (float)((float)v9 - (float)*(__int64 *)((char *)&v4 - 4));
      v31[4] = (float)((float)((float)((float)((float)v9 - (float)*(__int64 *)((char *)&v4 - 4)) * (float)0.75)
                             - (float)0.75)
                     * (float)((float)v9 - (float)*(__int64 *)((char *)&v4 - 4)))
             * (float)((float)v9 - (float)*(__int64 *)((char *)&v4 - 4));
      do
      {
        LODWORD(v4) = v31;
        v18 = 0.0;
        HIDWORD(v19) = -1;
        v20 = 0.0;
        v21 = 0.0;
        v22 = 0.0;
        for ( i = 2; i != 0; --i )
        {
          LODWORD(v19) = 4 * (HIDWORD(v4) + HIDWORD(v19));
          HIDWORD(v19) += 2;
          LODWORD(v19) = &v3[v19];
          LODWORD(v24) = *(unsigned __int8 *)(v19 + 3);
          LODWORD(v1) = *(unsigned __int8 *)(v19 + 1);
          DWORD2(v24) = *(unsigned __int8 *)(v19 + 4);
          DWORD1(v24) = *(unsigned __int8 *)(v19 + 5);
          HIDWORD(v24) = *(unsigned __int8 *)(v19 + 6);
          LODWORD(v25) = *(unsigned __int8 *)(v19 + 7);
          HIDWORD(v25) = *(unsigned __int8 *)v19;
          LODWORD(v19) = *(unsigned __int8 *)(v19 + 2);
          v12 = (float)((float)((float)((float)v1 * *(float *)(v4 + 4)) * *v11) + (float)v12);
          v14 = (float)((float)((float)((float)v19 * *(float *)(v4 + 4)) * *v11) + (float)v14);
          v17 = (float)((float)((float)((float)*(__int64 *)((char *)&v1 - 4) * *(float *)(v4 + 4)) * *v11) + (float)v17);
          v15 = (float)((float)((float)((float)(__int64)v24 * *(float *)(v4 + 4)) * *v11) + (float)v15);
          LODWORD(v4) = v4 + 8;
          v18 = (float)((float)((float)((float)*(__int64 *)((char *)&v24 + 4) * *(float *)v4) * *v11) + (float)v18);
          v20 = (float)((float)((float)((float)*(__int64 *)&v24 * *(float *)v4) * *v11) + (float)v20);
          v21 = (float)((float)((float)((float)*(__int64 *)((char *)&v24 + 12) * *(float *)v4) * *v11) + (float)v21);
          v22 = (float)((float)((float)((float)v25 * *(float *)v4) * *v11) + (float)v22);
        }
        --v13;
        v15 = (float)((float)v22 + (float)v15);
        v14 = (float)((float)v21 + (float)v14);
        HIDWORD(v4) += 128;
        v12 = (float)((float)v20 + (float)v12);
        ++v11;
        v17 = (float)((float)v18 + (float)v17);
      }
      while ( v13 != 0 );
      if ( (int)v17 >= 0 )
      {
        v26 = -1;
        if ( (int)v17 <= 255 )
          v26 = (int)v17;
      }
      else
      {
        v26 = 0;
      }
      *(v8 - 2) = v26;
      if ( (int)v12 >= 0 )
      {
        if ( (int)v12 <= 255 )
          v27 = (int)v12;
        else
          v27 = -1;
      }
      else
      {
        v27 = 0;
      }
      *(v8 - 1) = v27;
      if ( (int)v14 >= 0 )
      {
        if ( (int)v14 <= 255 )
          v28 = (int)v14;
        else
          v28 = -1;
      }
      else
      {
        v28 = 0;
      }
      *v8 = v28;
      if ( (int)v15 >= 0 )
      {
        if ( (int)v15 <= 255 )
          v29 = (int)v15;
        else
          v29 = -1;
      }
      else
      {
        v29 = 0;
      }
      v8[1] = v29;
      --v10;
      v9 = (float)((float)v9 + (float)0.9375);
      v8 += 4;
    }
    while ( v10 != 0 );
    --v6;
    v7 = (float)((float)v7 + (float)0.9375);
    v5 = v8;
  }
  while ( v6 != 0 );
  idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
}


// ========================================================================
// ?DCT_Decompress@@YAXPBUDCTHeader_t@@PBEHPAE@Z
// EA  : 0x8292CCA8
// RVA : 0x0092CCA8
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode.cpp
// ========================================================================

void __fastcall DCT_Decompress(
        const DCTHeader_t *header,
        const unsigned __int8 *src,
        unsigned int srcLen,
        unsigned __int8 *dest)
{
  int normalSize; // r10
  unsigned int diffuseSize; // r11
  unsigned __int8 *v9; // r29
  unsigned __int8 *v10; // r28
  unsigned __int8 *v11; // r27
  int specularSize; // r9
  int powerSize; // r8
  int v14; // r7
  __int64 v15; // r8
  const unsigned __int8 *v16; // r4
  int v17; // r9
  const unsigned __int8 *v18; // r8
  int v19; // r10
  int i; // ctr
  int v21; // r7
  char v22; // r6
  int v23; // r11
  int j; // r10
  int v25; // r11
  int v26; // r9
  int k; // ctr
  unsigned __int8 v28; // r7
  int v29; // r8
  int m; // r7
  int v31; // r10
  int n; // ctr
  unsigned __int8 *v33; // r11
  int v34; // r8
  int v35; // r4
  int v36; // r5
  int v37; // r9
  int v38; // r3
  int v39; // r4
  int v40; // r27
  int v41; // r24
  int v42; // r23
  int v43; // r22
  int v44; // r21
  int v45; // r6
  int v46; // r5
  int v47; // r3
  int v48; // r4
  int ii; // r5
  int v50; // r6
  unsigned __int8 *v51; // r10
  int v52; // r7
  int jj; // ctr
  int v54; // r11
  int v55; // r9
  unsigned __int8 *v56; // r11
  idBareDctDecoder v57; // [sp+60h] [-2680h] BYREF
  idBareDCTHuffmanTable v58; // [sp+240h] [-24A0h] BYREF
  idBareDCTHuffmanTable v59; // [sp+B50h] [-1B90h] BYREF
  idBareDCTHuffmanTable v60; // [sp+1460h] [-1280h] BYREF
  idBareDCTHuffmanTable v61; // [sp+1D70h] [-970h] BYREF

  normalSize = header->normalSize;
  diffuseSize = header->diffuseSize;
  v9 = dest + 0x20000;
  v10 = dest + 0x10000;
  v11 = dest + 1024;
  if ( diffuseSize + normalSize <= srcLen )
  {
    specularSize = header->specularSize;
    if ( specularSize + diffuseSize + normalSize <= srcLen )
    {
      powerSize = header->powerSize;
      if ( powerSize + specularSize + diffuseSize + normalSize <= srcLen )
      {
        v14 = header->flags & 8;
        if ( ((header->flags & 8) == 0 || (v14 << 8) + powerSize + specularSize + diffuseSize + normalSize <= srcLen)
          && (header->alphaSize == 0
           || (v14 << 8) + header->alphaSize + powerSize + specularSize + diffuseSize + normalSize <= srcLen)
          && (header->diffuseSize == 0 || diffuseSize <= srcLen) )
        {
          idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &v61, huffmanType: 0, encode: false);
          idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &v59, huffmanType: 1u, encode: false);
          idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &v60, huffmanType: 2u, encode: false);
          idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &v58, huffmanType: 3u, encode: false);
          idBareDctDecoder::idBareDctDecoder(this: &v57);
          idBareDctDecoder::SetHuffmanTables(
            this: &v57,
            tableYDC: &v61,
            tableYAC: &v59,
            tableCoCgDC: &v60,
            tableCoCgAC: &v58,
            tableADC: nullptr,
            tableAAC: nullptr);
          idBareDctBase::SetQuality_Xenon(
            this: &v57,
            luminanceQuality: header->qualityNormal,
            chrominanceQuality: header->qualityNormal,
            alphaQuality: header->qualityNormal);
          idBareDctDecoder::DecompressImageNormalMap_Xenon(
            this: &v57,
            inBuf: &src[header->diffuseSize],
            outBuf: v10,
            width: 128,
            inputBytes: header->normalSize | 0x8000000000LL);
          idBareDctBase::SetQuality_Xenon(
            this: &v57,
            luminanceQuality: header->qualitySpecular,
            chrominanceQuality: header->qualitySpecular,
            alphaQuality: header->qualitySpecular);
          v15 = header->specularSize | 0x8000000000LL;
          v16 = &src[header->normalSize + header->diffuseSize];
          if ( (header->flags & 4) != 0 )
            idBareDctDecoder::DecompressImageGrayScale_Xenon(
              this: &v57,
              inBuf: v16,
              outBuf: v9,
              width: 128,
              inputBytes: v15);
          else
            idBareDctDecoder::DecompressImageRGB_Xenon(this: &v57, inBuf: v16, outBuf: v9, width: 128, inputBytes: v15);
          idBareDctBase::SetQuality_Xenon(
            this: &v57,
            luminanceQuality: header->qualityPower,
            chrominanceQuality: header->qualityPower,
            alphaQuality: header->qualityPower);
          idBareDctDecoder::DecompressImageMono_Xenon(
            this: &v57,
            inBuf: &src[header->normalSize + header->diffuseSize + header->specularSize],
            outBuf: dest,
            width: 32,
            inputBytes: header->powerSize | 0x2000000000LL);
          if ( (header->flags & 8) != 0 )
          {
            v17 = 0;
            v18 = &src[header->normalSize + header->diffuseSize + header->specularSize + header->powerSize];
            do
            {
              v19 = 0;
              for ( i = 128; i != 0; --i )
              {
                v21 = (v17 + v19) >> 3;
                v22 = (v17 + v19) & 7;
                v23 = 4 * (v17 + v19++);
                v9[v23 + 3] = -((v18[v21] >> v22) & 1);
              }
              v17 += 128;
            }
            while ( v17 < 0x4000 );
          }
          if ( header->alphaSize != 0 )
          {
            idBareDctBase::SetQuality_Xenon(
              this: &v57,
              luminanceQuality: header->qualityLuma,
              chrominanceQuality: header->qualityLuma,
              alphaQuality: header->qualityLuma);
            idBareDctDecoder::DecompressImageMono_Xenon(
              this: &v57,
              inBuf: &src[((header->flags << 8) & 0x800)
                 + header->normalSize
                 + header->diffuseSize
                 + header->specularSize
                 + header->powerSize],
              outBuf: v11,
              width: 128,
              inputBytes: header->alphaSize | 0x8000000000LL);
            for ( j = 0; j < 0x4000; j += 128 )
            {
              v25 = 0;
              v26 = j;
              for ( k = 128; k != 0; --k )
              {
                v28 = v11[v26];
                v29 = 4 * (j + v25++);
                v26 = j + v25;
                v9[v29 + 3] = v28;
              }
            }
          }
          for ( m = 0; m < 0x4000; m += 128 )
          {
            v31 = 0;
            for ( n = 32; n != 0; --n )
            {
              v33 = &v9[4 * m + 4 * v31];
              v34 = 4 * (m + v31 + 2);
              v35 = m + v31 + 3;
              v31 += 4;
              v36 = v33[1];
              v37 = 4 * v35;
              *v33 <<= header->flags & 3;
              v38 = v33[2];
              v40 = v33[5];
              v41 = v9[v34];
              v42 = v33[9];
              v43 = v9[4 * v35];
              v39 = v33[4];
              v44 = v33[13];
              v45 = v33[6];
              v33[1] = v36 << (header->flags & 3);
              v46 = v33[10];
              v33[2] = v38 << (header->flags & 3);
              v47 = v33[14];
              v33[4] = v39 << (header->flags & 3);
              v33[5] = v40 << (header->flags & 3);
              v33[6] = v45 << (header->flags & 3);
              v9[v34] = v41 << (header->flags & 3);
              v33[9] = v42 << (header->flags & 3);
              v33[10] = v46 << (header->flags & 3);
              v9[v37] = v43 << (header->flags & 3);
              v33[13] = v44 << (header->flags & 3);
              v33[14] = v47 << (header->flags & 3);
            }
          }
          v48 = 0;
          for ( ii = 0; ii < 128; ii += 4 )
          {
            v50 = 0;
            v51 = &dest[v48 / 4];
            do
            {
              v52 = 0;
              for ( jj = 4; jj != 0; --jj )
              {
                v54 = 32 * (ii + v52++);
                v55 = 4 * (v54 + v50);
                v56 = &v10[16 * v54 + 16 * v50];
                *v56 = *v51;
                v56[2] = 8 * ((1 << (header->flags & 3)) - 1);
                v56[4] = *v51;
                v56[6] = 8 * ((1 << (header->flags & 3)) - 1);
                v10[4 * v55 + 8] = *v51;
                v56[10] = 8 * ((1 << (header->flags & 3)) - 1);
                v10[4 * v55 + 12] = *v51;
                v56[14] = 8 * ((1 << (header->flags & 3)) - 1);
              }
              ++v50;
              ++v51;
            }
            while ( v50 < 32 );
            v48 += 128;
          }
          idBareDctBase::SetQuality_Xenon(
            this: &v57,
            luminanceQuality: header->qualityLuma,
            chrominanceQuality: header->qualityChroma,
            alphaQuality: header->qualityLuma);
          idBareDctDecoder::DecompressImageYCoCg_Xenon(
            this: &v57,
            inBuf: src,
            outBuf: dest,
            width: 128,
            height: 128,
            inputBytes: header->diffuseSize);
          idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v57);
        }
      }
    }
  }
}


// ========================================================================
// __unwind$76504
// EA  : 0x8292D28C
// RVA : 0x0092D28C
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode.cpp
// ========================================================================

void _unwind_76504()
{
  int v0; // r12

  bfx::Planner3DInstance::Stop(this: (bfx::Planner3DInstance *)(v0 - 9952 + 96));
}


// ========================================================================
// ?TranscodePage@@YAXABUtranscodeParms_t@@@Z
// EA  : 0x8292D2B8
// RVA : 0x0092D2B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode.cpp
// ========================================================================

void __fastcall TranscodePage(const transcodeParms_t *parms)
{
  pageCompression_t inPageCompression; // r10
  char v3; // r11
  unsigned __int8 *v4; // r14
  unsigned __int8 *inPageData; // r4
  unsigned __int8 *tempData; // r21
  BOOL v7; // r17
  pageCompression_t v8; // r11
  int pageLevel; // r10
  signed int v10; // r8
  int v11; // r11
  unsigned __int8 v12; // r31
  unsigned __int8 *v13; // r8
  int i; // r29
  unsigned __int8 v15; // r30
  int j; // r7
  int v17; // r11
  int v18; // r10
  int k; // ctr
  int v20; // r3
  unsigned __int8 *v21; // r27
  unsigned int v22; // r29
  unsigned int v23; // r30
  int v24; // r9
  int m; // r11
  int v26; // r10
  int v27; // r10
  unsigned int v28; // r26
  int upsampleSharpen; // r24
  unsigned int v30; // r28
  int v31; // r23
  unsigned int n; // r31
  int v33; // r26
  unsigned int ii; // r28
  unsigned int jj; // r31
  unsigned int v36; // r26
  unsigned int kk; // r28
  unsigned int mm; // r31
  int v39; // r6
  _BYTE *v40; // r11
  unsigned __int8 v41; // r9
  unsigned __int8 v42; // r8
  int v43; // ctr
  unsigned __int8 v44; // r7
  unsigned __int8 *v45; // r11
  int nn; // ctr
  unsigned __int8 *v47; // r11
  int i1; // ctr
  int v49; // r9
  int numLevels; // r11
  signed int v51; // r11
  int v52; // r10
  int v53; // r8
  int v54; // r10
  unsigned __int8 v55; // r8
  int v56; // r10
  unsigned __int8 v57; // r11
  int v58; // r9
  int v59; // r10
  unsigned int v60; // r11
  int v61; // r10
  char v62; // r7
  int v63; // r11
  char v64; // r8
  int v65; // r11
  char v66; // r9
  _BYTE *v67; // r11
  int i2; // ctr
  char *v69; // r11
  int i3; // ctr
  unsigned __int8 *v71; // r11
  int i4; // ctr
  int v73; // r4
  _BYTE *v74; // r11
  int i5; // ctr
  unsigned __int8 v76; // r9
  unsigned __int8 v77; // r8
  unsigned __int8 *v78; // r11
  int v79; // ctr
  unsigned __int8 v80; // r10
  unsigned __int8 *v81; // r11
  int i6; // ctr
  int dbgShowPageUsage; // r10
  int v84; // r9
  unsigned int v85; // r11
  int v86; // r10
  char v87; // r7
  int v88; // r11
  char v89; // r8
  int v90; // r11
  char v91; // r9
  _BYTE *v92; // r11
  int i7; // ctr
  char *v94; // r11
  int i8; // ctr
  unsigned __int8 *v96; // r11
  int i9; // ctr
  int inPageDataLength; // r9
  int v99; // r11
  unsigned __int8 v100; // r10
  int v101; // r11
  int v102; // r9
  int v103; // r10
  int v104; // r8
  int v105; // r11
  int v106; // r10
  char v107; // r7
  int v108; // r11
  char v109; // r8
  int v110; // r11
  char v111; // r9
  _BYTE *v112; // r11
  int i10; // ctr
  char *v114; // r11
  int i11; // ctr
  unsigned __int8 *v116; // r11
  int i12; // ctr
  int v118; // r8
  int v119; // r7
  int v120; // r6
  int v121; // r4
  int v122; // r10
  int v123; // r8
  int v124; // r7
  int v125; // r6
  int v126; // r4
  int v127; // r29
  int v128; // r4
  int v129; // r8
  int v130; // r7
  int v131; // r6
  int v132; // r4
  int v133; // r10
  int v134; // r8
  int v135; // r7
  int v136; // r6
  int v137; // r4
  int v138; // r7
  int v139; // r6
  int v140; // r4
  int v141; // r9
  int v142; // r7
  int v143; // r6
  int v144; // r4
  int v145; // r8
  int v146; // r7
  int v147; // r6
  int v148; // r4
  int v149; // r10
  int v150; // r8
  int v151; // r7
  int v152; // r6
  int v153; // r4
  int v154; // r6
  int v155; // r4
  int v156; // r7
  int v157; // r6
  int v158; // r4
  int v159; // r9
  int v160; // r7
  int v161; // r6
  int v162; // r4
  int v163; // r8
  int v164; // r7
  int v165; // r6
  int v166; // r4
  int v167; // r10
  int v168; // r8
  int v169; // r7
  int v170; // r6
  int v171; // r4
  const char **v172; // r31
  int v173; // r6
  int v174; // r4
  int v175; // r7
  int v176; // r6
  int v177; // r4
  int v178; // r9
  int v179; // r7
  int v180; // r6
  int v181; // r4
  const char **v182; // r31
  int v183; // r7
  int v184; // r6
  int v185; // r7
  int v186; // r6
  int v187; // r4
  int v188; // r9
  int v189; // r7
  int v190; // r6
  int v191; // r4
  int v192; // r11
  _DWORD *v193; // r6
  int v194; // ctr
  _DWORD *v195; // r8
  _DWORD *v196; // r10
  int v197; // r11
  _DWORD *v198; // r10
  _DWORD *v199; // r8
  _DWORD *v200; // r6
  int i13; // ctr
  int v202; // r11
  _DWORD *v203; // r9
  _DWORD *v204; // r8
  int v205; // ctr
  _DWORD *v206; // r10
  pageCompression_t outPageCompression; // r11
  int v208; // r10
  unsigned __int8 *v209; // r5
  unsigned __int8 *v210; // r5
  unsigned __int8 *v211; // r5
  int v212; // [sp+8h] [-1C8h]
  int v213; // [sp+Ch] [-1C4h]
  int v214; // [sp+10h] [-1C0h]
  int v215; // [sp+14h] [-1BCh]
  int v216; // [sp+18h] [-1B8h]
  unsigned int v217; // [sp+1Ch] [-1B4h]
  int v218; // [sp+20h] [-1B0h]
  unsigned int v219; // [sp+24h] [-1ACh]
  int v220; // [sp+28h] [-1A8h]
  unsigned int v221; // [sp+2Ch] [-1A4h]
  int v222; // [sp+30h] [-1A0h]
  int v223; // [sp+34h] [-19Ch]
  int v224; // [sp+38h] [-198h]
  unsigned int v225; // [sp+3Ch] [-194h]
  int v226; // [sp+40h] [-190h]
  unsigned int v227; // [sp+44h] [-18Ch]
  int v228; // [sp+48h] [-188h]
  int v229; // [sp+4Ch] [-184h]
  int v230; // [sp+50h] [-180h]
  int v231; // [sp+58h] [-178h]
  int v232; // [sp+60h] [-170h]
  unsigned __int8 v233; // [sp+70h] [-160h] BYREF
  unsigned __int8 v234; // [sp+71h] [-15Fh] BYREF
  unsigned __int8 v235[6]; // [sp+72h] [-15Eh] BYREF
  char v236[5]; // [sp+78h] [-158h] BYREF
  char v237[19]; // [sp+7Dh] [-153h] BYREF
  idDxtEncoder v238; // [sp+90h] [-140h] BYREF
  char v239[288]; // [sp+B0h] [-120h] BYREF

  inPageCompression = parms->inPageCompression;
  if ( parms->outPageCompression != inPageCompression
    || parms->stripPageBorders
    || (*((_BYTE *)parms + 94) & 0x80) != 0
    || (*((_BYTE *)parms + 94) & 0x40) != 0
    || (*((_BYTE *)parms + 94) & 0x20) != 0
    || (*((_BYTE *)parms + 94) & 0x10) != 0
    || (*((_BYTE *)parms + 94) & 8) != 0
    || parms->dbgShowPageMips != 0
    || parms->dbgShowPageSizes != 0
    || parms->dbgShowPageUsage != 0
    || parms->inPageData == nullptr
    || (v3 = 1, parms->upsampleLevel != 0) )
  {
    v3 = 0;
  }
  if ( v3 != 0 )
  {
    if ( inPageCompression == COMP_NONE )
    {
      CopyUncompressed(
        targetImage: parms->targetImage,
        targetBytePitch: parms->targetBytePitch,
        imageFlags: parms->imageFlags,
        src: parms->inPageData,
        srcLength: parms->inPageDataLength);
    }
    else if ( inPageCompression == COMP_DXT )
    {
      CopyDXTCompressed(
        targetImage: parms->targetImage,
        targetBytePitch: parms->targetBytePitch,
        imageFlags: parms->imageFlags,
        src: parms->inPageData,
        srcLength: parms->inPageDataLength,
        pageHeaderSize: parms->pageHeaderSize,
        diskOffsetScale: parms->diskOffsetScale);
    }
  }
  else
  {
    v4 = nullptr;
    if ( parms->tempData == nullptr )
    {
      v4 = (unsigned __int8 *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\engine\\renderer\\jobs\\transcode\\Transcode.cpp(1030) : TAG_VIRTUALTEXTURE",
                                size: parms->tempSize,
                                tag: TAG_VIRTUALTEXTURE,
                                zeroBuffer: false,
                                align: ALIGN_128,
                                heap: HEAP_DEFAULTHEAP);
      parms->tempData = v4;
    }
    inPageData = (unsigned __int8 *)parms->inPageData;
    tempData = parms->tempData;
    v7 = false;
    if ( inPageData != nullptr && (v8 = parms->inPageCompression) != 0 )
    {
      switch ( v8 )
      {
        case COMP_NONE:
          memcpy(Dst: parms->tempData, Src: inPageData, Size: 0x30000u);
          break;
        case COMP_DXT:
          DXT_Decompress(
            pageHeaderSize: parms->pageHeaderSize,
            diskOffsetScale: parms->diskOffsetScale,
            src: parms->inPageData,
            srcLen: parms->inPageDataLength,
            dest: parms->tempData);
          v7 = false;
          break;
        case COMP_DCT:
          DCT_Decompress(
            header: (const DCTHeader_t *)parms->inPageHeader,
            src: inPageData,
            srcLen: parms->inPageDataLength,
            dest: parms->tempData);
          v7 = (parms->inPageHeader[5] & 4) != 0;
          break;
        case COMP_HDP:
          HDP_Decompress(
            header: (const HDPHeader_t *)parms->inPageHeader,
            src: inPageData,
            srcLen: parms->inPageDataLength,
            dest: parms->tempData);
          v7 = (parms->inPageHeader[4] & 4) != 0;
          break;
        case COMP_JXR:
          JXR_Decompress(
            header: (const JXRHeader_t *)parms->inPageHeader,
            src: inPageData,
            srcLen: parms->inPageDataLength,
            dest: parms->tempData);
          v7 = (parms->inPageHeader[4] & 4) != 0;
          break;
        default:
          break;
      }
    }
    else
    {
      pageLevel = parms->pageLevel;
      v10 = parms->numLevels - 1;
      __twllei(v10, 0);
      v11 = 255 * pageLevel / v10;
      __twlgei(v10 & ~(__ROL4__(255 * pageLevel, 1) - 1), 0xFFFFFFFF);
      if ( v11 >= 0 )
      {
        if ( v11 > 255 )
          LOBYTE(v11) = -1;
      }
      else
      {
        LOBYTE(v11) = 0;
      }
      v12 = v11;
      v13 = tempData + 2;
      for ( i = 3; i != 0; --i )
      {
        v15 = 0;
        for ( j = 0; j < 0x4000; j += 128 )
        {
          v17 = 0;
          v18 = 0;
          for ( k = 128; k != 0; --k )
          {
            v20 = 4 * (j + v17++);
            v13[v20 - 2] = v18;
            v18 += 2;
            v13[v20 - 1] = v15;
            v13[v20] = v12;
            v13[v20 + 1] = -1;
          }
          v15 += 2;
        }
        v13 += 0x10000;
      }
    }
    if ( parms->upsampleLevel != 0 )
    {
      v21 = (unsigned __int8 *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\engine\\renderer\\jobs\\transcode\\Transcode.cpp(1084) : TAG_VIRTUALTEXTURE",
                                 size: 0x30000u,
                                 tag: TAG_VIRTUALTEXTURE,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
      v22 = 0;
      v23 = 0;
      v24 = 0;
      for ( m = 1; v24 < parms->upsampleLevel; m *= 2 )
      {
        v26 = 124 * m;
        if ( (parms->upsampleX & m) == 0 )
          v26 = 4 * m;
        v22 += v26;
        v27 = 124 * m;
        if ( (parms->upsampleY & m) == 0 )
          v27 = 4 * m;
        ++v24;
        v23 += v27;
      }
      v28 = 0;
      upsampleSharpen = parms->upsampleSharpen;
      v30 = 2048;
      v31 = parms->upsampleNoise >> parms->pageLevel;
      do
      {
        for ( n = 0; n < 8; ++n )
          UpSample16x16_Bicubic(
            dst: &v21[64 * (v30 + n)],
            dstX: 16 * n,
            dstY: v28,
            dstBytePitch: 0x200u,
            src: tempData + 0x20000,
            srcX: v22,
            srcY: v23,
            srcMaskY: 0x7Fu,
            upsampleLevel: v212,
            sharpenScale: v213,
            noiseScale: v214,
            a12: v215,
            a13: v216,
            a14: v217,
            a15: v218,
            a16: v219,
            a17: v220,
            a18: v221,
            a19: v222,
            a20: v223,
            a21: v224,
            a22: v225,
            a23: v226,
            a24: v227,
            a25: v228,
            a26: v229,
            a27: v230,
            a28: parms->upsampleLevel,
            a29: v231,
            a30: 0,
            a31: v232,
            a32: 0);
        v30 += 128;
        v28 += 16;
      }
      while ( v30 < 0xC00 );
      v33 = 0;
      for ( ii = 0; ii < 0x80; ii += 16 )
      {
        for ( jj = 0; jj < 8; ++jj )
          UpSample16x16_Bicubic(
            dst: &v21[64 * (v33 + jj)],
            dstX: 16 * jj,
            dstY: ii,
            dstBytePitch: 0x200u,
            src: tempData,
            srcX: v22,
            srcY: v23,
            srcMaskY: 0x7Fu,
            upsampleLevel: v212,
            sharpenScale: v213,
            noiseScale: v214,
            a12: v215,
            a13: v216,
            a14: v217,
            a15: v218,
            a16: v219,
            a17: v220,
            a18: v221,
            a19: v222,
            a20: v223,
            a21: v224,
            a22: v225,
            a23: v226,
            a24: v227,
            a25: v228,
            a26: v229,
            a27: v230,
            a28: parms->upsampleLevel,
            a29: v231,
            a30: upsampleSharpen,
            a31: v232,
            a32: v31);
        v33 += 128;
      }
      v36 = 0;
      for ( kk = 1024; kk < 0x800; kk += 128 )
      {
        for ( mm = 0; mm < 8; ++mm )
          UpSample16x16_Bicubic(
            dst: &v21[64 * (kk + mm)],
            dstX: 16 * mm,
            dstY: v36,
            dstBytePitch: 0x200u,
            src: tempData + 0x10000,
            srcX: v22,
            srcY: v23,
            srcMaskY: 0x7Fu,
            upsampleLevel: v212,
            sharpenScale: v213,
            noiseScale: v214,
            a12: v215,
            a13: v216,
            a14: v217,
            a15: v218,
            a16: v219,
            a17: v220,
            a18: v221,
            a19: v222,
            a20: v223,
            a21: v224,
            a22: v225,
            a23: v226,
            a24: v227,
            a25: v228,
            a26: v229,
            a27: v230,
            a28: parms->upsampleLevel,
            a29: v231,
            a30: 0,
            a31: v232,
            a32: 0);
        v36 += 16;
      }
      memcpy(Dst: tempData, Src: v21, Size: 0x30000u);
      idMem::Free(this: &mem, ptr: v21, align: ALIGN_16);
    }
    if ( (*((_BYTE *)parms + 94) & 0x80) != 0 )
    {
      v39 = (4 * parms->pageSource) & 0x1C;
      v40 = tempData + 0x1FFFF;
      v41 = mipBlends[0][v39];
      v42 = mipBlends[0][v39 + 1];
      v43 = 0x4000;
      v44 = mipBlends[0][v39 + 3];
      do
      {
        v40[1] = 0;
        v40[2] = 0;
        v40[3] = 0;
        v40 += 4;
        *v40 = 0;
        --v43;
      }
      while ( v43 != 0 );
      v45 = tempData - 1;
      for ( nn = 0x4000; nn != 0; --nn )
      {
        v45[1] = v41;
        v45[2] = v42;
        v45[3] = 0;
        v45 += 4;
        *v45 = v44;
      }
      v47 = tempData + 0xFFFF;
      for ( i1 = 0x4000; i1 != 0; --i1 )
      {
        *(_WORD *)(v47 + 1) = 255;
        v47[3] = 0;
        v47 += 4;
        *v47 = -1;
      }
    }
    if ( parms->dbgShowPageMips != 0 )
    {
      v49 = parms->pageLevel;
      if ( v49 >= parms->dbgShowPageMips - 1 )
      {
        numLevels = parms->numLevels;
        v52 = numLevels - v49 - 1;
        v51 = numLevels - 1;
        __twllei(v51, 0);
        v53 = __ROL4__(255 * v52, 1);
        v54 = 255 * v52 / v51;
        __twlgei(v51 & ~(v53 - 1), 0xFFFFFFFF);
        if ( v54 >= 0 )
        {
          if ( v54 > 255 )
            LOBYTE(v54) = -1;
        }
        else
        {
          LOBYTE(v54) = 0;
        }
        v55 = v54;
        __twllei(v51, 0);
        v56 = 255 * v49 / v51;
        __twlgei(v51 & ~(__ROL4__(255 * v49, 1) - 1), 0xFFFFFFFF);
        if ( v56 >= 0 )
        {
          v57 = -1;
          if ( v56 <= 255 )
            v57 = v56;
        }
        else
        {
          v57 = 0;
        }
        v58 = v55;
        v59 = v57;
        v60 = ((2 * (v55 + 1)) >> 2) + 128;
        if ( v60 > 0xFF )
          LOBYTE(v60) = -1;
        v61 = (2 * v59) & 0x1FE;
        v62 = v60;
        v63 = ((v61 - v55 + 2) >> 2) + 128;
        if ( v63 >= 0 )
        {
          if ( v63 > 255 )
            LOBYTE(v63) = -1;
        }
        else
        {
          LOBYTE(v63) = 0;
        }
        v64 = v63;
        v65 = (v61 + v58 + 2) >> 2;
        if ( v65 >= 0 )
        {
          v66 = -1;
          if ( v65 <= 255 )
            v66 = v65;
        }
        else
        {
          v66 = 0;
        }
        v67 = tempData + 0x1FFFF;
        for ( i2 = 0x4000; i2 != 0; --i2 )
        {
          v67[1] = 0;
          v67[2] = 0;
          v67[3] = 0;
          v67 += 4;
          *v67 = 0;
        }
        v69 = (char *)(tempData - 1);
        for ( i3 = 0x4000; i3 != 0; --i3 )
        {
          v69[1] = v62;
          v69[2] = v64;
          v69[3] = 0;
          v69 += 4;
          *v69 = v66;
        }
        v71 = tempData + 0xFFFF;
        for ( i4 = 0x4000; i4 != 0; --i4 )
        {
          *(_WORD *)(v71 + 1) = 255;
          v71[3] = 0;
          v71 += 4;
          *v71 = -1;
        }
      }
    }
    if ( (*((_BYTE *)parms + 94) & 0x40) != 0 )
    {
      v73 = parms->numLevels - parms->pageLevel;
      BrightColorForNumber(
        number: (357913941 >> (2 * (15 - v73))) + (parms->pageY << v73) + parms->pageX,
        Y: &v233,
        Co: &v234,
        Cg: v235);
      v74 = tempData + 0x1FFFF;
      for ( i5 = 0x4000; i5 != 0; --i5 )
      {
        v74[1] = 0;
        v74[2] = 0;
        v74[3] = 0;
        v74 += 4;
        *v74 = 0;
      }
      v76 = v234;
      v77 = v233;
      v78 = tempData - 1;
      v79 = 0x4000;
      v80 = v235[0];
      do
      {
        v78[1] = v76;
        v78[2] = v80;
        v78[3] = 0;
        v78 += 4;
        *v78 = v77;
        --v79;
      }
      while ( v79 != 0 );
      v81 = tempData + 0xFFFF;
      for ( i6 = 0x4000; i6 != 0; --i6 )
      {
        *(_WORD *)(v81 + 1) = 255;
        v81[3] = 0;
        v81 += 4;
        *v81 = -1;
      }
    }
    dbgShowPageUsage = parms->dbgShowPageUsage;
    if ( parms->dbgShowPageUsage != 0 )
    {
      v84 = (unsigned __int8)(-1 - dbgShowPageUsage);
      v85 = ((2 * (v84 + 1)) >> 2) + 128;
      if ( v85 > 0xFF )
        LOBYTE(v85) = -1;
      v86 = (2 * dbgShowPageUsage) & 0x1FE;
      v87 = v85;
      v88 = ((v86 - v84 + 2) >> 2) + 128;
      if ( v88 >= 0 )
      {
        if ( v88 > 255 )
          LOBYTE(v88) = -1;
      }
      else
      {
        LOBYTE(v88) = 0;
      }
      v89 = v88;
      v90 = (v86 + v84 + 2) >> 2;
      if ( v90 >= 0 )
      {
        v91 = -1;
        if ( v90 <= 255 )
          v91 = v90;
      }
      else
      {
        v91 = 0;
      }
      v92 = tempData + 0x1FFFF;
      for ( i7 = 0x4000; i7 != 0; --i7 )
      {
        v92[1] = 0;
        v92[2] = 0;
        v92[3] = 0;
        v92 += 4;
        *v92 = 0;
      }
      v94 = (char *)(tempData - 1);
      for ( i8 = 0x4000; i8 != 0; --i8 )
      {
        v94[1] = v87;
        v94[2] = v89;
        v94[3] = 0;
        v94 += 4;
        *v94 = v91;
      }
      v96 = tempData + 0xFFFF;
      for ( i9 = 0x4000; i9 != 0; --i9 )
      {
        *(_WORD *)(v96 + 1) = 255;
        v96[3] = 0;
        v96 += 4;
        *v96 = -1;
      }
    }
    if ( parms->dbgShowPageSizes != 0 )
    {
      if ( parms->dbgShowPageSizes == 2 )
      {
        inPageDataLength = parms->inPageDataLength;
        v99 = 255 * inPageDataLength / 0x4000;
        if ( v99 >= 0 )
        {
          v100 = -1;
          if ( v99 <= 255 )
            v100 = v99;
        }
        else
        {
          v100 = 0;
        }
        v101 = 255 * (0x4000 - inPageDataLength) / 0x4000;
        if ( v101 >= 0 )
        {
          if ( v101 > 255 )
            LOBYTE(v101) = -1;
        }
        else
        {
          LOBYTE(v101) = 0;
        }
        v102 = v100;
        v104 = 2 * (v100 + 1);
        v103 = (unsigned __int8)v101;
        v105 = (v104 >> 2) + 128;
        if ( v105 > 255 )
          LOBYTE(v105) = -1;
        v106 = (2 * v103) & 0x1FE;
        v107 = v105;
        v108 = ((v106 - v102 + 2) >> 2) + 128;
        if ( v108 >= 0 )
        {
          if ( v108 > 255 )
            LOBYTE(v108) = -1;
        }
        else
        {
          LOBYTE(v108) = 0;
        }
        v109 = v108;
        v110 = (v106 + v102 + 2) >> 2;
        if ( v110 >= 0 )
        {
          v111 = -1;
          if ( v110 <= 255 )
            v111 = v110;
        }
        else
        {
          v111 = 0;
        }
        v112 = tempData + 0x1FFFF;
        for ( i10 = 0x4000; i10 != 0; --i10 )
        {
          v112[1] = 0;
          v112[2] = 0;
          v112[3] = 0;
          v112 += 4;
          *v112 = 0;
        }
        v114 = (char *)(tempData - 1);
        for ( i11 = 0x4000; i11 != 0; --i11 )
        {
          v114[1] = v107;
          v114[2] = v109;
          v114[3] = 0;
          v114 += 4;
          *v114 = v111;
        }
        v116 = tempData + 0xFFFF;
        for ( i12 = 0x4000; i12 != 0; --i12 )
        {
          *(_WORD *)(v116 + 1) = 255;
          v116[3] = 0;
          v116 += 4;
          *v116 = -1;
        }
      }
      sprintf_0(string: v239, format: "%d", parms->inPageDataLength);
      DrawPixelNumber(
        dest: tempData + 172160,
        byteStride: 512,
        text: v239,
        scaleX: 2,
        scaleY: 2,
        pixelStride: 4,
        frontColor: 10,
        backColor: 10);
      DrawPixelNumber(
        dest: tempData + 41088,
        byteStride: v121,
        text: v239,
        scaleX: v120,
        scaleY: v119,
        pixelStride: v118,
        frontColor: parms->pageLevel,
        backColor: 8);
      DrawPixelNumber(
        dest: tempData + 106624,
        byteStride: v126,
        text: v239,
        scaleX: v125,
        scaleY: v124,
        pixelStride: v123,
        frontColor: parms->pageLevel,
        backColor: v122);
    }
    if ( (*((_BYTE *)parms + 94) & 0x20) != 0 || parms->inPageData == nullptr )
    {
      v127 = parms->pageLevel;
      itoa_0(a: v236, i: parms->pageX << v127);
      v128 = parms->pageY << v127;
      v236[4] = 32;
      itoa_0(a: v237, i: v128);
      v237[4] = 0;
      DrawPixelNumber(
        dest: tempData + 159872,
        byteStride: 512,
        text: v236,
        scaleX: 2,
        scaleY: 2,
        pixelStride: 4,
        frontColor: 10,
        backColor: 10);
      DrawPixelNumber(
        dest: tempData + 28800,
        byteStride: v132,
        text: v236,
        scaleX: v131,
        scaleY: v130,
        pixelStride: v129,
        frontColor: parms->pageLevel,
        backColor: 8);
      DrawPixelNumber(
        dest: tempData + 94336,
        byteStride: v137,
        text: v236,
        scaleX: v136,
        scaleY: v135,
        pixelStride: v134,
        frontColor: parms->pageLevel,
        backColor: v133);
    }
    if ( (*((_BYTE *)parms + 94) & 0x10) != 0 || parms->inPageData == nullptr )
    {
      DrawText(
        dest: tempData + 139312,
        byteStride: 512,
        text: sourceText,
        scale: 2,
        pixelStride: 4,
        frontColor: 10,
        backColor: 10);
      DrawText(
        dest: tempData + 8240,
        byteStride: v140,
        text: sourceText,
        scale: v139,
        pixelStride: v138,
        frontColor: parms->pageLevel,
        backColor: 8);
      DrawText(
        dest: tempData + 73776,
        byteStride: v144,
        text: sourceText,
        scale: v143,
        pixelStride: v142,
        frontColor: parms->pageLevel,
        backColor: v141);
      sprintf_0(string: v239, format: "%d", parms->pageSource);
      DrawPixelNumber(
        dest: tempData + 139640,
        byteStride: 512,
        text: v239,
        scaleX: 2,
        scaleY: 2,
        pixelStride: 4,
        frontColor: 10,
        backColor: 10);
      DrawPixelNumber(
        dest: tempData + 8568,
        byteStride: v148,
        text: v239,
        scaleX: v147,
        scaleY: v146,
        pixelStride: v145,
        frontColor: parms->pageLevel,
        backColor: 8);
      DrawPixelNumber(
        dest: tempData + 74104,
        byteStride: v153,
        text: v239,
        scaleX: v152,
        scaleY: v151,
        pixelStride: v150,
        frontColor: parms->pageLevel,
        backColor: v149);
      DrawText(
        dest: tempData + 151600,
        byteStride: v155,
        text: layoutText,
        scale: v154,
        pixelStride: 4,
        frontColor: 10,
        backColor: 10);
      DrawText(
        dest: tempData + 20528,
        byteStride: v158,
        text: layoutText,
        scale: v157,
        pixelStride: v156,
        frontColor: parms->pageLevel,
        backColor: 8);
      DrawText(
        dest: tempData + 86064,
        byteStride: v162,
        text: layoutText,
        scale: v161,
        pixelStride: v160,
        frontColor: parms->pageLevel,
        backColor: v159);
      sprintf_0(string: v239, format: "%d", parms->layoutVersion);
      DrawPixelNumber(
        dest: tempData + 151928,
        byteStride: 512,
        text: v239,
        scaleX: 2,
        scaleY: 2,
        pixelStride: 4,
        frontColor: 10,
        backColor: 10);
      DrawPixelNumber(
        dest: tempData + 20856,
        byteStride: v166,
        text: v239,
        scaleX: v165,
        scaleY: v164,
        pixelStride: v163,
        frontColor: parms->pageLevel,
        backColor: 8);
      DrawPixelNumber(
        dest: tempData + 86392,
        byteStride: v171,
        text: v239,
        scaleX: v170,
        scaleY: v169,
        pixelStride: v168,
        frontColor: parms->pageLevel,
        backColor: v167);
      v172 = pageType[parms->inPageCompression];
      DrawText(
        dest: tempData + 163888,
        byteStride: v174,
        text: v172,
        scale: v173,
        pixelStride: 4,
        frontColor: 10,
        backColor: 10);
      DrawText(
        dest: tempData + 32816,
        byteStride: v177,
        text: v172,
        scale: v176,
        pixelStride: v175,
        frontColor: parms->pageLevel,
        backColor: 8);
      DrawText(
        dest: tempData + 98352,
        byteStride: v181,
        text: v172,
        scale: v180,
        pixelStride: v179,
        frontColor: parms->pageLevel,
        backColor: v178);
      v182 = (const char **)((char *)specularType[0] + ((32 * v7) & 0x1FE0));
      DrawText(
        dest: tempData + 176176,
        byteStride: 512,
        text: v182,
        scale: v184,
        pixelStride: v183,
        frontColor: 10,
        backColor: 10);
      DrawText(
        dest: tempData + 45104,
        byteStride: v187,
        text: v182,
        scale: v186,
        pixelStride: v185,
        frontColor: parms->pageLevel,
        backColor: 8);
      DrawText(
        dest: tempData + 110640,
        byteStride: v191,
        text: v182,
        scale: v190,
        pixelStride: v189,
        frontColor: parms->pageLevel,
        backColor: v188);
    }
    if ( (*((_BYTE *)parms + 94) & 0x80) != 0
      || (*((_BYTE *)parms + 94) & 0x20) != 0
      || (*((_BYTE *)parms + 94) & 0x10) != 0
      || (*((_BYTE *)parms + 94) & 8) != 0
      || parms->dbgShowPageMips != 0
      || parms->dbgShowPageSizes != 0
      || parms->inPageData == nullptr )
    {
      v192 = *(_DWORD *)&mipBlends[10][0];
      v193 = tempData + 132624;
      v194 = 120;
      v195 = tempData + 194060;
      v196 = tempData + 133100;
      do
      {
        v193 += 128;
        *v193 = v192;
        v196 += 128;
        *v196 = v192;
        *(v195 - 15231) = v192;
        *++v195 = v192;
        --v194;
      }
      while ( v194 != 0 );
      v197 = *(_DWORD *)&mipBlends[9][0];
      v198 = tempData + 62988;
      v199 = tempData + 1552;
      v200 = tempData + 2028;
      for ( i13 = 120; i13 != 0; --i13 )
      {
        v199 += 128;
        *v199 = v197;
        v200 += 128;
        *v200 = v197;
        *(v198 - 15231) = v197;
        *++v198 = v197;
      }
      v202 = *(_DWORD *)&mipBlends[9][0];
      v203 = tempData + 128524;
      v204 = tempData + 67088;
      v205 = 120;
      v206 = tempData + 67564;
      do
      {
        v204 += 128;
        *v204 = v202;
        v206 += 128;
        *v206 = v202;
        *(v203 - 15231) = v202;
        *++v203 = v202;
        --v205;
      }
      while ( v205 != 0 );
    }
    if ( parms->stripPageBorders )
    {
      StripPageBorder(dst: tempData + 0x20000);
      StripPageBorder(dst: tempData);
      StripPageBorder(dst: tempData + 0x10000);
    }
    outPageCompression = parms->outPageCompression;
    if ( outPageCompression == COMP_NONE )
    {
      CopyUncompressed(
        targetImage: parms->targetImage,
        targetBytePitch: parms->targetBytePitch,
        imageFlags: parms->imageFlags,
        src: tempData,
        srcLength: 196608);
    }
    else if ( outPageCompression == COMP_DXT )
    {
      v208 = parms->imageFlags & 1;
      v238.dstPadding = 0;
      v238.srcPadding = 0;
      if ( v208 != 0 )
      {
        v209 = parms->targetImage[0];
        v238.dstPadding = parms->targetBytePitch[0] - 256;
        idDxtEncoder::CompressImageDXT1AlphaFast_Xenon(
          this: &v238,
          inBuf: tempData + 0x20000,
          outBuf: v209,
          width: 128,
          height: 128);
      }
      if ( (parms->imageFlags & 2) != 0 )
      {
        v210 = parms->targetImage[1];
        v238.dstPadding = parms->targetBytePitch[1] - 512;
        idDxtEncoder::CompressYCoCgDXT5Fast_Xenon(this: &v238, inBuf: tempData, outBuf: v210, width: 128, height: 128);
      }
      if ( (parms->imageFlags & 4) != 0 )
      {
        v211 = parms->targetImage[2];
        v238.dstPadding = parms->targetBytePitch[2] - 512;
        idDxtEncoder::CompressNormalMapDXT5Fast_Xenon(
          this: &v238,
          inBuf: tempData + 0x10000,
          outBuf: v211,
          width: 128,
          height: 128);
      }
    }
    if ( v4 != nullptr )
      idMem::Free(this: &mem, ptr: v4, align: ALIGN_128);
  }
}


// ========================================================================
// `dynamic initializer for 'register_TranscodePage''
// EA  : 0x83358070
// RVA : 0x01358070
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_TranscodePage__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_TranscodePage,
           function: (void (__fastcall *)(void *))TranscodePage,
           name: "TranscodePage");
}

