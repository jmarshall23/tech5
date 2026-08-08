
// ========================================================================
// ?FindDCTQualityForRatio@@YAXPBEHPAEHH@Z
// EA  : 0x828B9968
// RVA : 0x008B9968
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall FindDCTQualityForRatio(
        const unsigned __int8 *uncompressed,
        int uncompressedSize,
        unsigned __int8 *customDCT,
        int maxCompressedSize,
        int ratio)
{
  int v7; // r31 OVERLAPPED
  int v8; // r15
  int v12; // r14
  int v13; // r27
  int v14; // r30 OVERLAPPED
  unsigned __int64 v15; // r29
  unsigned __int64 v16; // r25
  unsigned __int64 v17; // r11 OVERLAPPED
  __int128 v18; // r9 OVERLAPPED
  int v19; // r11
  unsigned __int64 v20; // r7 OVERLAPPED
  int v22; // [sp+50h] [-100h]
  int v23; // [sp+54h] [-FCh]
  int v24; // [sp+58h] [-F8h]
  int v25; // [sp+5Ch] [-F4h]
  int v26; // [sp+60h] [-F0h]
  compressionStats_t v27; // [sp+70h] [-E0h] BYREF

  v26 = 8;
  v7 = 0;
  v8 = 100;
  v22 = 0;
  v24 = 0;
  v23 = 100;
  v25 = 100;
  v12 = 0;
  v13 = 50;
  v14 = 50;
  v15 = 0x320000C000LL;
  LODWORD(v16) = 0x8000;
  HIDWORD(v16) = &vt_qualityDCTNormal;
  do
  {
    idCVar::SetInteger(this: &vt_qualityDCTSpecular, newValue: v13, force: true);
    idCVar::SetInteger(this: &vt_qualityDCTLuma, newValue: v14, force: true);
    idCVar::SetInteger(this: &vt_qualityDCTChroma, newValue: v14, force: true);
    idCVar::SetInteger(this: &vt_qualityDCTNormal, newValue: SHIDWORD(v15), force: true);
    v27.headerBytes = *(_QWORD *)&v7;
    v27.specularBytes = *(_QWORD *)&v7;
    v27.diffuseBytes = *(_QWORD *)&v7;
    v27.normalBytes = *(_QWORD *)&v7;
    v27.powerBytes = *(_QWORD *)&v7;
    v27.coverBytes = *(_QWORD *)&v7;
    v27.wastedBytes = *(_QWORD *)&v7;
    v27.diskOffsetScale = 64;
    DCT_Compress(
      src: uncompressed,
      length: uncompressedSize,
      dest: customDCT,
      maxDestLength: maxCompressedSize,
      storeCover: false,
      storeAlpha: false,
      stats: &v27);
    v17 = __PAIR64__(v27.diffuseBytes, v27.specularBytes);
    LODWORD(v18) = v27.normalBytes;
    *(_QWORD *)((char *)&v18 + 4) = v15 / __PAIR64__(v27.diffuseBytes, v27.specularBytes);
    __tdllei(__PAIR64__(v27.diffuseBytes, v27.specularBytes), 0);
    v20 = v15 / *(unsigned __int64 *)((char *)&v17 + 4);
    v19 = v15 / v17;
    *(unsigned __int64 *)((char *)&v20 + 4) = v16 / (unsigned __int64)v18;
    __tdllei(*(unsigned __int64 *)((char *)&v17 + 4), 0);
    __tdllei(v18, 0);
    if ( v19 <= ratio )
    {
      if ( v19 < ratio )
      {
        v23 = v13;
        v13 -= (v13 - v22 + 1) >> 1;
      }
    }
    else
    {
      v22 = v13;
      v13 += (v23 - v13 + 1) >> 1;
    }
    if ( (int)v20 <= ratio )
    {
      if ( (int)v20 < ratio )
      {
        v25 = v14;
        v14 -= (v14 - v24 + 1) >> 1;
      }
    }
    else
    {
      v24 = v14;
      v14 += (v25 - v14 + 1) >> 1;
    }
    if ( SHIDWORD(v20) <= ratio )
    {
      if ( SHIDWORD(v20) < ratio )
      {
        v8 = HIDWORD(v15);
        HIDWORD(v15) -= (HIDWORD(v15) - v12 + 1) >> 1;
      }
    }
    else
    {
      v12 = HIDWORD(v15);
      HIDWORD(v15) += (v8 - HIDWORD(v15) + 1) >> 1;
    }
  }
  while ( v26-- != 1 );
}


// ========================================================================
// ?FindDCTQualityForSize@@YAXPBEHPAEHH@Z
// EA  : 0x828B9B70
// RVA : 0x008B9B70
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall FindDCTQualityForSize(
        const unsigned __int8 *uncompressed,
        int uncompressedSize,
        unsigned __int8 *customDCT,
        int maxCompressedSize,
        int size)
{
  int v6; // r7
  int v9; // r27
  int v10; // r31 OVERLAPPED
  int v11; // r21
  int v12; // r23
  int v13; // r25
  int v14; // r22
  int v15; // r24
  int v16; // r26
  int v17; // r28
  int v18; // r30 OVERLAPPED
  int v19; // r29
  int v20; // r3
  signed int v22; // r11
  int v23; // [sp+50h] [-100h]
  int v24; // [sp+54h] [-FCh]
  int v25; // [sp+58h] [-F8h]
  int v26; // [sp+5Ch] [-F4h]
  int i; // [sp+60h] [-F0h]
  int v28; // [sp+64h] [-ECh]
  compressionStats_t v29; // [sp+70h] [-E0h] BYREF
  int v31; // [sp+184h] [+34h]

  v31 = size + 16;
  v6 = 5 * (size + 16);
  v28 = 4 * v6 / 100;
  v25 = 0x100000;
  v26 = -1;
  v9 = 2 * v6 / 100;
  v10 = 0;
  v23 = 67 * v31 / 100;
  for ( i = 0; i < 20; ++i )
  {
    v11 = 0;
    v12 = 0;
    v24 = 8;
    v13 = 0;
    v14 = 100;
    v15 = 100;
    v16 = 100;
    v17 = 50;
    v18 = 50;
    v19 = 50;
    do
    {
      idCVar::SetInteger(this: &vt_qualityDCTSpecular, newValue: v17, force: true);
      idCVar::SetInteger(this: &vt_qualityDCTLuma, newValue: v18, force: true);
      idCVar::SetInteger(this: &vt_qualityDCTChroma, newValue: v18, force: true);
      idCVar::SetInteger(this: &vt_qualityDCTNormal, newValue: v19, force: true);
      v29.headerBytes = *(_QWORD *)&v10;
      v29.specularBytes = *(_QWORD *)&v10;
      v29.diffuseBytes = *(_QWORD *)&v10;
      v29.normalBytes = *(_QWORD *)&v10;
      v29.powerBytes = *(_QWORD *)&v10;
      v29.coverBytes = *(_QWORD *)&v10;
      v29.wastedBytes = *(_QWORD *)&v10;
      v29.diskOffsetScale = 64;
      v20 = DCT_Compress(
              src: uncompressed,
              length: uncompressedSize,
              dest: customDCT,
              maxDestLength: maxCompressedSize,
              storeCover: false,
              storeAlpha: false,
              stats: &v29);
      if ( SLODWORD(v29.specularBytes) >= v9 )
      {
        if ( SLODWORD(v29.specularBytes) > v9 )
        {
          v14 = v17;
          v17 -= (v17 - v11 + 1) >> 1;
        }
      }
      else
      {
        v11 = v17;
        v17 += (v14 - v17 + 1) >> 1;
      }
      if ( SLODWORD(v29.diffuseBytes) >= v23 )
      {
        if ( SLODWORD(v29.diffuseBytes) > v23 )
        {
          v15 = v18;
          v18 -= (v18 - v12 + 1) >> 1;
        }
      }
      else
      {
        v12 = v18;
        v18 += (v15 - v18 + 1) >> 1;
      }
      if ( SLODWORD(v29.normalBytes) >= v28 )
      {
        if ( SLODWORD(v29.normalBytes) > v28 )
        {
          v16 = v19;
          v19 -= (v19 - v13 + 1) >> 1;
        }
      }
      else
      {
        v13 = v19;
        v19 += (v16 - v19 + 1) >> 1;
      }
    }
    while ( v24-- != 1 );
    if ( v23 == v26 )
      break;
    v22 = abs32(v20 - v31);
    if ( v22 > v25 )
    {
      v23 = v26;
    }
    else
    {
      v25 = v22;
      v26 = v23;
      v23 += (v31 - v20) / 2;
    }
  }
}


// ========================================================================
// ?FindHDPQualityForRatio@@YAXPBEHPAEHH@Z
// EA  : 0x828B9DF8
// RVA : 0x008B9DF8
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall FindHDPQualityForRatio(
        const unsigned __int8 *uncompressed,
        int uncompressedSize,
        unsigned __int8 *customHDP,
        int maxCompressedSize,
        int ratio)
{
  int v6; // r31 OVERLAPPED
  int v7; // r14
  int v12; // r15
  int v13; // r16
  int v14; // r27
  int v15; // r28
  unsigned __int64 v16; // r30 OVERLAPPED
  unsigned __int64 v17; // r25
  unsigned __int64 v18; // r11 OVERLAPPED
  __int128 v19; // r9 OVERLAPPED
  int v20; // r11
  unsigned __int64 v21; // r7 OVERLAPPED
  int v23; // [sp+50h] [-F0h]
  int v24; // [sp+54h] [-ECh]
  int v25; // [sp+58h] [-E8h]
  int v26; // [sp+5Ch] [-E4h]
  compressionStats_t v27; // [sp+60h] [-E0h] BYREF

  v26 = 9;
  v6 = 0;
  v7 = 176;
  v23 = 0;
  v24 = 176;
  v25 = 0;
  v12 = 0;
  v13 = 176;
  v14 = 88;
  v15 = 88;
  v16 = 0x580000C000LL;
  LODWORD(v17) = 0x8000;
  HIDWORD(v17) = &vt_qualityHDPNormal;
  do
  {
    idCVar::SetInteger(this: &vt_qualityHDPSpecular, newValue: v14, force: true);
    idCVar::SetInteger(this: &vt_qualityHDPDiffuse, newValue: v15, force: true);
    idCVar::SetInteger(this: &vt_qualityHDPNormal, newValue: SHIDWORD(v16), force: true);
    v27.headerBytes = *(_QWORD *)&v6;
    v27.specularBytes = *(_QWORD *)&v6;
    v27.diffuseBytes = *(_QWORD *)&v6;
    v27.normalBytes = *(_QWORD *)&v6;
    v27.powerBytes = *(_QWORD *)&v6;
    v27.coverBytes = *(_QWORD *)&v6;
    v27.wastedBytes = *(_QWORD *)&v6;
    v27.diskOffsetScale = 64;
    HDP_Compress(
      src: uncompressed,
      length: uncompressedSize,
      dest: customHDP,
      maxDestLength: maxCompressedSize,
      storeCover: false,
      storeAlpha: false,
      stats: &v27);
    v18 = __PAIR64__(v27.diffuseBytes, v27.specularBytes);
    LODWORD(v19) = v27.normalBytes;
    *(_QWORD *)((char *)&v19 + 4) = v16 / __PAIR64__(v27.diffuseBytes, v27.specularBytes);
    __tdllei(__PAIR64__(v27.diffuseBytes, v27.specularBytes), 0);
    v21 = v16 / *(unsigned __int64 *)((char *)&v18 + 4);
    v20 = v16 / v18;
    *(unsigned __int64 *)((char *)&v21 + 4) = v17 / (unsigned __int64)v19;
    __tdllei(*(unsigned __int64 *)((char *)&v18 + 4), 0);
    __tdllei(v19, 0);
    if ( v20 >= ratio )
    {
      if ( v20 > ratio )
      {
        v24 = v14;
        v14 -= (v14 - v23 + 1) >> 1;
      }
    }
    else
    {
      v23 = v14;
      v14 += (v24 - v14 + 1) >> 1;
    }
    if ( (int)v21 >= ratio )
    {
      if ( (int)v21 > ratio )
      {
        v7 = v15;
        v15 -= (v15 - v25 + 1) >> 1;
      }
    }
    else
    {
      v25 = v15;
      v15 += (v7 - v15 + 1) >> 1;
    }
    if ( SHIDWORD(v21) >= ratio )
    {
      if ( SHIDWORD(v21) > ratio )
      {
        v13 = HIDWORD(v16);
        HIDWORD(v16) -= (HIDWORD(v16) - v12 + 1) >> 1;
      }
    }
    else
    {
      v12 = HIDWORD(v16);
      HIDWORD(v16) += (v13 - HIDWORD(v16) + 1) >> 1;
    }
  }
  while ( v26-- != 1 );
}


// ========================================================================
// ?FindHDPQualityForSize@@YAXPBEHPAEHH@Z
// EA  : 0x828B9FE0
// RVA : 0x008B9FE0
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall FindHDPQualityForSize(
        const unsigned __int8 *uncompressed,
        int uncompressedSize,
        unsigned __int8 *customHDP,
        int maxCompressedSize,
        int size)
{
  int v9; // r21
  int v10; // r31 OVERLAPPED
  int v11; // r22
  int v12; // r24
  int v13; // r26
  int v14; // r23
  int v15; // r25
  int v16; // r27
  int v17; // r28
  int v18; // r29
  int v19; // r30 OVERLAPPED
  int v20; // r3
  signed int v22; // r11
  int v23; // [sp+50h] [-100h]
  int v24; // [sp+54h] [-FCh]
  int v25; // [sp+58h] [-F8h]
  int v26; // [sp+5Ch] [-F4h]
  int v27; // [sp+60h] [-F0h]
  int v28; // [sp+64h] [-ECh]
  compressionStats_t v29; // [sp+70h] [-E0h] BYREF
  int v30; // [sp+184h] [+34h]

  v30 = size + 16;
  v26 = -1;
  v23 = 67 * (size + 16) / 100;
  v9 = 10 * (size + 16) / 100;
  v28 = 20 * (size + 16) / 100;
  v10 = 0;
  v27 = 0;
  v25 = 0x100000;
  do
  {
    v11 = 0;
    v12 = 0;
    v24 = 9;
    v13 = 0;
    v14 = 176;
    v15 = 176;
    v16 = 176;
    v17 = 88;
    v18 = 88;
    v19 = 88;
    do
    {
      idCVar::SetInteger(this: &vt_qualityHDPSpecular, newValue: v17, force: true);
      idCVar::SetInteger(this: &vt_qualityHDPDiffuse, newValue: v18, force: true);
      idCVar::SetInteger(this: &vt_qualityHDPNormal, newValue: v19, force: true);
      v29.headerBytes = *(_QWORD *)&v10;
      v29.specularBytes = *(_QWORD *)&v10;
      v29.diffuseBytes = *(_QWORD *)&v10;
      v29.normalBytes = *(_QWORD *)&v10;
      v29.powerBytes = *(_QWORD *)&v10;
      v29.coverBytes = *(_QWORD *)&v10;
      v29.wastedBytes = *(_QWORD *)&v10;
      v29.diskOffsetScale = 64;
      v20 = HDP_Compress(
              src: uncompressed,
              length: uncompressedSize,
              dest: customHDP,
              maxDestLength: maxCompressedSize,
              storeCover: false,
              storeAlpha: false,
              stats: &v29);
      if ( SLODWORD(v29.specularBytes) <= v9 )
      {
        if ( SLODWORD(v29.specularBytes) < v9 )
        {
          v14 = v17;
          v17 -= (v17 - v11 + 1) >> 1;
        }
      }
      else
      {
        v11 = v17;
        v17 += (v14 - v17 + 1) >> 1;
      }
      if ( SLODWORD(v29.diffuseBytes) <= v23 )
      {
        if ( SLODWORD(v29.diffuseBytes) < v23 )
        {
          v15 = v18;
          v18 -= (v18 - v12 + 1) >> 1;
        }
      }
      else
      {
        v12 = v18;
        v18 += (v15 - v18 + 1) >> 1;
      }
      if ( SLODWORD(v29.normalBytes) <= v28 )
      {
        if ( SLODWORD(v29.normalBytes) < v28 )
        {
          v16 = v19;
          v19 -= (v19 - v13 + 1) >> 1;
        }
      }
      else
      {
        v13 = v19;
        v19 += (v16 - v19 + 1) >> 1;
      }
    }
    while ( v24-- != 1 );
    if ( v23 == v26 )
      break;
    v22 = abs32(v20 - v30);
    if ( v22 > v25 )
    {
      v23 = v26;
    }
    else
    {
      v25 = v22;
      v26 = v23;
      v23 += (v30 - v20) / 2;
    }
    ++v27;
  }
  while ( v27 < 20 );
}


// ========================================================================
// ?FindJXRQualityForRatio@@YAXPBEHPAEHH@Z
// EA  : 0x828BA250
// RVA : 0x008BA250
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall FindJXRQualityForRatio(
        const unsigned __int8 *uncompressed,
        int uncompressedSize,
        unsigned __int8 *customJXR,
        int maxCompressedSize,
        int ratio)
{
  int v6; // r31 OVERLAPPED
  int v7; // r14
  int v12; // r15
  int v13; // r16
  int v14; // r27
  int v15; // r28
  unsigned __int64 v16; // r30 OVERLAPPED
  unsigned __int64 v17; // r25
  unsigned __int64 v18; // r11 OVERLAPPED
  __int128 v19; // r9 OVERLAPPED
  int v20; // r11
  unsigned __int64 v21; // r7 OVERLAPPED
  int v23; // [sp+50h] [-F0h]
  int v24; // [sp+54h] [-ECh]
  int v25; // [sp+58h] [-E8h]
  int v26; // [sp+5Ch] [-E4h]
  compressionStats_t v27; // [sp+60h] [-E0h] BYREF

  v26 = 9;
  v6 = 0;
  v7 = 176;
  v23 = 0;
  v24 = 176;
  v25 = 0;
  v12 = 0;
  v13 = 176;
  v14 = 88;
  v15 = 88;
  v16 = 0x580000C000LL;
  LODWORD(v17) = 0x8000;
  HIDWORD(v17) = &vt_qualityJXRNormal;
  do
  {
    idCVar::SetInteger(this: &vt_qualityJXRSpecular, newValue: v14, force: true);
    idCVar::SetInteger(this: &vt_qualityJXRDiffuse, newValue: v15, force: true);
    idCVar::SetInteger(this: &vt_qualityJXRNormal, newValue: SHIDWORD(v16), force: true);
    v27.headerBytes = *(_QWORD *)&v6;
    v27.specularBytes = *(_QWORD *)&v6;
    v27.diffuseBytes = *(_QWORD *)&v6;
    v27.normalBytes = *(_QWORD *)&v6;
    v27.powerBytes = *(_QWORD *)&v6;
    v27.coverBytes = *(_QWORD *)&v6;
    v27.wastedBytes = *(_QWORD *)&v6;
    v27.diskOffsetScale = 64;
    JXR_Compress(
      src: uncompressed,
      length: uncompressedSize,
      dest: customJXR,
      maxDestLength: maxCompressedSize,
      storeCover: false,
      storeAlpha: false,
      stats: &v27);
    v18 = __PAIR64__(v27.diffuseBytes, v27.specularBytes);
    LODWORD(v19) = v27.normalBytes;
    *(_QWORD *)((char *)&v19 + 4) = v16 / __PAIR64__(v27.diffuseBytes, v27.specularBytes);
    __tdllei(__PAIR64__(v27.diffuseBytes, v27.specularBytes), 0);
    v21 = v16 / *(unsigned __int64 *)((char *)&v18 + 4);
    v20 = v16 / v18;
    *(unsigned __int64 *)((char *)&v21 + 4) = v17 / (unsigned __int64)v19;
    __tdllei(*(unsigned __int64 *)((char *)&v18 + 4), 0);
    __tdllei(v19, 0);
    if ( v20 >= ratio )
    {
      if ( v20 > ratio )
      {
        v24 = v14;
        v14 -= (v14 - v23 + 1) >> 1;
      }
    }
    else
    {
      v23 = v14;
      v14 += (v24 - v14 + 1) >> 1;
    }
    if ( (int)v21 >= ratio )
    {
      if ( (int)v21 > ratio )
      {
        v7 = v15;
        v15 -= (v15 - v25 + 1) >> 1;
      }
    }
    else
    {
      v25 = v15;
      v15 += (v7 - v15 + 1) >> 1;
    }
    if ( SHIDWORD(v21) >= ratio )
    {
      if ( SHIDWORD(v21) > ratio )
      {
        v13 = HIDWORD(v16);
        HIDWORD(v16) -= (HIDWORD(v16) - v12 + 1) >> 1;
      }
    }
    else
    {
      v12 = HIDWORD(v16);
      HIDWORD(v16) += (v13 - HIDWORD(v16) + 1) >> 1;
    }
  }
  while ( v26-- != 1 );
}


// ========================================================================
// ?FindJXRQualityForSize@@YAXPBEHPAEHH@Z
// EA  : 0x828BA438
// RVA : 0x008BA438
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall FindJXRQualityForSize(
        const unsigned __int8 *uncompressed,
        int uncompressedSize,
        unsigned __int8 *customJXR,
        int maxCompressedSize,
        int size)
{
  int v9; // r21
  int v10; // r31 OVERLAPPED
  int v11; // r22
  int v12; // r24
  int v13; // r26
  int v14; // r23
  int v15; // r25
  int v16; // r27
  int v17; // r28
  int v18; // r29
  int v19; // r30 OVERLAPPED
  int v20; // r3
  signed int v22; // r11
  int v23; // [sp+50h] [-100h]
  int v24; // [sp+54h] [-FCh]
  int v25; // [sp+58h] [-F8h]
  int v26; // [sp+5Ch] [-F4h]
  int v27; // [sp+60h] [-F0h]
  int v28; // [sp+64h] [-ECh]
  compressionStats_t v29; // [sp+70h] [-E0h] BYREF
  int v30; // [sp+184h] [+34h]

  v30 = size + 16;
  v26 = -1;
  v23 = 67 * (size + 16) / 100;
  v9 = 10 * (size + 16) / 100;
  v28 = 20 * (size + 16) / 100;
  v10 = 0;
  v27 = 0;
  v25 = 0x100000;
  do
  {
    v11 = 0;
    v12 = 0;
    v24 = 9;
    v13 = 0;
    v14 = 176;
    v15 = 176;
    v16 = 176;
    v17 = 88;
    v18 = 88;
    v19 = 88;
    do
    {
      idCVar::SetInteger(this: &vt_qualityJXRSpecular, newValue: v17, force: true);
      idCVar::SetInteger(this: &vt_qualityJXRDiffuse, newValue: v18, force: true);
      idCVar::SetInteger(this: &vt_qualityJXRNormal, newValue: v19, force: true);
      v29.headerBytes = *(_QWORD *)&v10;
      v29.specularBytes = *(_QWORD *)&v10;
      v29.diffuseBytes = *(_QWORD *)&v10;
      v29.normalBytes = *(_QWORD *)&v10;
      v29.powerBytes = *(_QWORD *)&v10;
      v29.coverBytes = *(_QWORD *)&v10;
      v29.wastedBytes = *(_QWORD *)&v10;
      v29.diskOffsetScale = 64;
      v20 = JXR_Compress(
              src: uncompressed,
              length: uncompressedSize,
              dest: customJXR,
              maxDestLength: maxCompressedSize,
              storeCover: false,
              storeAlpha: false,
              stats: &v29);
      if ( SLODWORD(v29.specularBytes) <= v9 )
      {
        if ( SLODWORD(v29.specularBytes) < v9 )
        {
          v14 = v17;
          v17 -= (v17 - v11 + 1) >> 1;
        }
      }
      else
      {
        v11 = v17;
        v17 += (v14 - v17 + 1) >> 1;
      }
      if ( SLODWORD(v29.diffuseBytes) <= v23 )
      {
        if ( SLODWORD(v29.diffuseBytes) < v23 )
        {
          v15 = v18;
          v18 -= (v18 - v12 + 1) >> 1;
        }
      }
      else
      {
        v12 = v18;
        v18 += (v15 - v18 + 1) >> 1;
      }
      if ( SLODWORD(v29.normalBytes) <= v28 )
      {
        if ( SLODWORD(v29.normalBytes) < v28 )
        {
          v16 = v19;
          v19 -= (v19 - v13 + 1) >> 1;
        }
      }
      else
      {
        v13 = v19;
        v19 += (v16 - v19 + 1) >> 1;
      }
    }
    while ( v24-- != 1 );
    if ( v23 == v26 )
      break;
    v22 = abs32(v20 - v30);
    if ( v22 > v25 )
    {
      v23 = v26;
    }
    else
    {
      v25 = v22;
      v26 = v23;
      v23 += (v30 - v20) / 2;
    }
    ++v27;
  }
  while ( v27 < 20 );
}


// ========================================================================
// DescaleSpecular
// EA  : 0x828BA6A8
// RVA : 0x008BA6A8
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

void __fastcall DescaleSpecular(unsigned __int8 *specularImage, unsigned __int8 *normalImage, int width, int height)
{
  int v4; // ctr
  unsigned __int8 *v5; // r11
  int v6; // r10
  int v7; // r8
  unsigned int v8; // r3
  unsigned int v9; // r8
  unsigned int v10; // r5
  char v11; // r6

  if ( width * height > 0 )
  {
    v4 = width * height;
    v5 = specularImage + 2;
    v6 = normalImage - specularImage;
    do
    {
      v7 = v5[v6];
      v5[v6] = 0;
      v8 = *(v5 - 2);
      v10 = *(v5 - 1);
      v11 = (v7 >> 3) & ~(unsigned __int8)(v7 >> 4);
      v9 = *v5;
      v5[1] = 0;
      *(v5 - 1) = v10 >> v11;
      *(v5 - 2) = v8 >> v11;
      *v5 = v9 >> v11;
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}


// ========================================================================
// ImagesAreEqual
// EA  : 0x828BA710
// RVA : 0x008BA710
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

int __fastcall ImagesAreEqual(const unsigned __int8 *image1, const unsigned __int8 *image2, int width, int height)
{
  int v4; // r7
  int v5; // r8
  int v6; // r9
  int v7; // r11
  const unsigned __int8 *v8; // r10
  const unsigned __int8 *v9; // r11
  int v10; // r31

  v4 = 0;
  if ( height <= 0 )
    return 1;
  v5 = 0;
  while ( 1 )
  {
    v6 = 0;
    if ( width > 0 )
      break;
LABEL_9:
    ++v4;
    v5 += width;
    if ( v4 >= height )
      return 1;
  }
  while ( 1 )
  {
    v7 = 4 * (v5 + v6);
    v8 = &image1[v7];
    v10 = image1[v7];
    v9 = &image2[v7];
    if ( v10 != *v9 || v8[1] != v9[1] || v8[2] != v9[2] || v8[3] != v9[3] )
      return 0;
    if ( ++v6 >= width )
      goto LABEL_9;
  }
}


// ========================================================================
// CountDiffs
// EA  : 0x828BA7C0
// RVA : 0x008BA7C0
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall CountDiffs(const int *diffs, __int64 stats, long double a3)
{
  int v3; // r30
  int v4; // r31
  int v5; // r10
  const int *v6; // r11
  double v7; // fp0
  double v8; // fp13
  int v9; // r9
  int v10; // r6
  int v11; // r9
  int v12; // r6
  int v13; // r9
  int v14; // r6
  int v15; // r9
  int v16; // r6
  int v17; // r9
  int v18; // r6
  long double v19; // fp2

  v3 = stats;
  v4 = 0;
  v5 = 3;
  v6 = diffs + 3;
  v7 = 0.0;
  v8 = 0.0;
  do
  {
    v9 = *(v6 - 2);
    if ( v9 > 0 )
    {
      v4 = v5 - 2;
      LODWORD(stats) = (v5 - 2) * v9;
      v10 = stats * (v5 - 2);
      v7 = (float)((float)*(__int64 *)((char *)&stats - 4) + (float)v7);
      v8 = (float)((float)stats + (float)v8);
    }
    v11 = *(v6 - 1);
    if ( v11 > 0 )
    {
      v4 = v5 - 1;
      v12 = (v5 - 1) * v11 * (v5 - 1);
      LODWORD(stats) = (v5 - 1) * v11;
      v7 = (float)((float)*(__int64 *)((char *)&stats - 4) + (float)v7);
      v8 = (float)((float)stats + (float)v8);
    }
    v13 = *v6;
    if ( *v6 > 0 )
    {
      v4 = v5;
      LODWORD(stats) = v5 * v13;
      v14 = v5 * v13 * v5;
      v7 = (float)((float)*(__int64 *)((char *)&stats - 4) + (float)v7);
      v8 = (float)((float)stats + (float)v8);
    }
    v15 = v6[1];
    if ( v15 > 0 )
    {
      v4 = v5 + 1;
      v16 = (v5 + 1) * v15;
      LODWORD(stats) = v16 * (v5 + 1);
      v8 = (float)((float)*(__int64 *)((char *)&stats - 4) + (float)v8);
      v7 = (float)((float)stats + (float)v7);
    }
    v17 = v6[2];
    if ( v17 > 0 )
    {
      v4 = v5 + 2;
      v18 = (v5 + 2) * v17;
      LODWORD(stats) = v18 * (v5 + 2);
      v8 = (float)((float)*(__int64 *)((char *)&stats - 4) + (float)v8);
      v7 = (float)((float)stats + (float)v7);
    }
    v5 += 5;
    v6 += 5;
  }
  while ( v5 - 2 < 256 );
  *(float *)(v3 + 4) = (float)((float)1.0 / (float)__SPAIR64__(0x82000000, HIDWORD(stats))) * (float)v7;
  *(float *)v3 = (float)((float)1.0 / (float)__SPAIR64__(0x82000000, HIDWORD(stats))) * (float)v8;
  *(double *)&a3 = 255.0 / (float)((float)((float)1.0 / (float)__SPAIR64__(0x82000000, HIDWORD(stats))) * (float)v7);
  v19 = log10(x: a3);
  *(_DWORD *)(v3 + 12) = v4;
  *(float *)(v3 + 8) = *(double *)&v19 * 20.0;
}


// ========================================================================
// CompareImagesCoCg_Y
// EA  : 0x828BA9F0
// RVA : 0x008BA9F0
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

void __fastcall CompareImagesCoCg_Y(
        const unsigned __int8 *image1,
        const unsigned __int8 *image2,
        int width,
        int height,
        imageStats_t *stats)
{
  __int64 v10; // r6
  long double v11; // fp2
  int v12; // r3
  const unsigned __int8 *v13; // r11
  const unsigned __int8 *v14; // r10
  int i; // ctr
  int v16; // r31
  int v17; // r6
  int v18; // r4
  unsigned int v19; // r6
  unsigned int v20; // r4
  unsigned int v21; // r31
  int v22[268]; // [sp+50h] [-430h] BYREF

  memset(Dst: v22, Val: 0, Size: 0x400u);
  if ( height > 0 )
  {
    v12 = height;
    v13 = image2 - 1;
    v14 = image1 - 1;
    do
    {
      if ( width > 0 )
      {
        for ( i = width; i != 0; --i )
        {
          v16 = v14[2];
          v17 = v14[1] - v13[1];
          v18 = v13[2];
          v13 += 4;
          v14 += 4;
          v19 = abs32(v17);
          v20 = abs32(v16 - v18);
          v21 = abs32(*v14 - *v13);
          ++v22[v19];
          ++v22[v20];
          LODWORD(v10) = v22[v21] + 1;
          v22[v21] = v10;
        }
      }
      --v12;
    }
    while ( v12 != 0 );
  }
  HIDWORD(v10) = stats;
  CountDiffs(diffs: v22, stats: v10, a3: v11);
}


// ========================================================================
// CompareImagesRGB_
// EA  : 0x828BAAF0
// RVA : 0x008BAAF0
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

void __fastcall CompareImagesRGB_(
        const unsigned __int8 *image1,
        const unsigned __int8 *image2,
        int width,
        int height,
        imageStats_t *stats)
{
  __int64 v10; // r6
  long double v11; // fp2
  int v12; // r3
  const unsigned __int8 *v13; // r11
  const unsigned __int8 *v14; // r10
  int i; // ctr
  int v16; // r31
  int v17; // r6
  int v18; // r4
  unsigned int v19; // r6
  unsigned int v20; // r4
  unsigned int v21; // r31
  int v22[268]; // [sp+50h] [-430h] BYREF

  memset(Dst: v22, Val: 0, Size: 0x400u);
  if ( height > 0 )
  {
    v12 = height;
    v13 = image2 - 2;
    v14 = image1 - 2;
    do
    {
      if ( width > 0 )
      {
        for ( i = width; i != 0; --i )
        {
          v16 = v14[3];
          v17 = v14[2] - v13[2];
          v18 = v13[3];
          v13 += 4;
          v14 += 4;
          v19 = abs32(v17);
          v20 = abs32(v16 - v18);
          v21 = abs32(*v14 - *v13);
          ++v22[v19];
          ++v22[v20];
          LODWORD(v10) = v22[v21] + 1;
          v22[v21] = v10;
        }
      }
      --v12;
    }
    while ( v12 != 0 );
  }
  HIDWORD(v10) = stats;
  CountDiffs(diffs: v22, stats: v10, a3: v11);
}


// ========================================================================
// CompareImagesNormal_Y_X
// EA  : 0x828BABF0
// RVA : 0x008BABF0
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall CompareImagesNormal_Y_X(
        const unsigned __int8 *image1,
        const unsigned __int8 *image2,
        int width,
        int height,
        imageStats_t *stats)
{
  _BYTE v10[12]; // r5 OVERLAPPED
  long double v11; // fp2
  const unsigned __int8 *v12; // r11
  const unsigned __int8 *v13; // r10
  int i; // ctr
  int v15; // r3
  unsigned int v16; // r8
  unsigned int v17; // r6
  double v18; // fp0
  double v19; // fp13
  int v20; // r31
  int v21; // r7
  int v22; // r11
  int *v23; // r8
  int v24; // r9
  int v25; // r10
  int v26; // r6
  int v27; // r9
  int v28; // r9
  int v29; // r6
  int v30; // r9
  int v31; // r9
  int v32; // r6
  long double v33; // fp2
  _BYTE v34[1072]; // [sp+A0h] [-430h] BYREF

  *(_DWORD *)v10 = memset(Dst: v34, Val: 0, Size: 0x400u);
  if ( height > 0 )
  {
    *(_DWORD *)&v10[4] = height;
    v12 = image2 - 1;
    v13 = image1 - 1;
    do
    {
      if ( width > 0 )
      {
        for ( i = width; i != 0; --i )
        {
          v15 = v13[2];
          v13 += 4;
          *(_DWORD *)&v10[8] = v15 - v12[2];
          v12 += 4;
          v16 = 4 * abs32(*(int *)&v10[8]);
          v17 = 4 * abs32(*v13 - *v12);
          *(_DWORD *)v10 = *(_DWORD *)&v34[v16] + 1;
          *(_DWORD *)&v34[v16] = *(_DWORD *)v10;
          ++*(_DWORD *)&v34[v17];
        }
      }
      --*(_DWORD *)&v10[4];
    }
    while ( *(_DWORD *)&v10[4] != 0 );
  }
  v18 = 0.0;
  v19 = 0.0;
  v20 = 0;
  v21 = 3 * width * height;
  v22 = 3;
  v23 = (int *)&v34[8];
  do
  {
    v24 = *(v23 - 1);
    if ( v24 > 0 )
    {
      *(_DWORD *)&v10[4] = (v22 - 2) * v24;
      *(_DWORD *)&v10[8] = *(_DWORD *)&v10[4] * (v22 - 2);
      v20 = v22 - 2;
      v18 = (float)((float)*(__int64 *)&v10[4] + (float)v18);
      v19 = (float)((float)*(__int64 *)v10 + (float)v19);
    }
    if ( *v23 > 0 )
    {
      *(_DWORD *)&v10[8] = (v22 - 1) * *v23 * (v22 - 1);
      *(_DWORD *)&v10[4] = (v22 - 1) * *v23;
      v20 = v22 - 1;
      v18 = (float)((float)*(__int64 *)&v10[4] + (float)v18);
      v19 = (float)((float)*(__int64 *)v10 + (float)v19);
    }
    v25 = v23[1];
    if ( v25 > 0 )
    {
      *(_DWORD *)&v10[8] = v25 * v22;
      v26 = v22 * v25 * v22;
      v20 = v22;
      v18 = (float)((float)*(__int64 *)&v10[-4] + (float)v18);
      v19 = (float)((float)*(__int64 *)&v10[4] + (float)v19);
    }
    v27 = v23[2];
    if ( v27 > 0 )
    {
      v28 = (v22 + 1) * v27;
      *(_DWORD *)&v10[8] = (v22 + 1) * v28;
      *(_DWORD *)&v10[4] = *(_DWORD *)&v10[8];
      v29 = v28;
      v20 = v22 + 1;
      v19 = (float)((float)*(__int64 *)&v10[-4] + (float)v19);
      v18 = (float)((float)*(__int64 *)v10 + (float)v18);
    }
    v30 = v23[3];
    if ( v30 > 0 )
    {
      v31 = (v22 + 2) * v30;
      *(_DWORD *)&v10[8] = (v22 + 2) * v31;
      v32 = v31;
      *(_DWORD *)&v10[4] = *(_DWORD *)&v10[8];
      v20 = v22 + 2;
      v19 = (float)((float)*(__int64 *)&v10[-4] + (float)v19);
      v18 = (float)((float)*(__int64 *)v10 + (float)v18);
    }
    v22 += 5;
    v23 += 5;
  }
  while ( v22 - 2 < 256 );
  stats->MSE = (float)((float)1.0 / (float)__SPAIR64__(0x82000000, v21)) * (float)v18;
  stats->ME = (float)((float)1.0 / (float)__SPAIR64__(0x82000000, v21)) * (float)v19;
  *(double *)&v11 = 255.0 / (float)((float)((float)1.0 / (float)__SPAIR64__(0x82000000, v21)) * (float)v18);
  v33 = log10(x: v11);
  stats->Max = v20;
  stats->PSNR = *(double *)&v33 * 20.0;
}


// ========================================================================
// ?vt_testTranscodePerformance_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828BAEB8
// RVA : 0x008BAEB8
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall vt_testTranscodePerformance_f(const idCmdArgs *args)
{
  int argc; // r11
  unsigned __int64 v2; // r21
  unsigned __int8 v4; // r19
  int v5; // r17
  int v6; // r18
  int v7; // r30
  const char **v8; // r29
  char *v9; // r31
  int v10; // r11
  const char *v11; // r3
  int v12; // r2 OVERLAPPED
  int v13; // r11
  int v14; // ctr
  unsigned __int8 *v15; // r10
  unsigned __int8 v16; // r8
  unsigned __int8 v17; // r7
  unsigned __int8 v18; // r6
  unsigned __int8 v19; // r8
  unsigned __int8 v20; // r4
  unsigned __int8 *v21; // r9
  unsigned __int8 v22; // r6
  unsigned __int8 v23; // r7
  unsigned __int8 v24; // r8
  int v25; // r11
  __int64 v26; // r6 OVERLAPPED
  int i; // ctr
  __int64 v28; // r4
  __int64 v29; // r7 OVERLAPPED
  unsigned __int8 v30; // r10
  int v31; // r8
  unsigned __int8 v32; // r10
  __int64 v33; // r4
  __int64 v34; // r7 OVERLAPPED
  unsigned __int8 v35; // r10
  int v36; // r8
  unsigned __int8 v37; // r10
  int v38; // r8
  unsigned __int8 *v39; // r10
  int v40; // r4
  int v41; // r3
  double v42; // fp12
  unsigned __int8 v43; // r10
  int v44; // r7
  unsigned __int8 v45; // r10
  int v46; // r4
  int v47; // r3 OVERLAPPED
  unsigned __int8 v48; // r10
  int v49; // r7
  unsigned __int8 v50; // r10
  int v51; // r4
  int v52; // r3 OVERLAPPED
  unsigned __int8 v53; // r10
  int v54; // r7
  unsigned __int8 v55; // r10
  int v56; // r4
  int v57; // r3 OVERLAPPED
  unsigned __int8 v58; // r10
  int v59; // r7
  unsigned __int8 v60; // r10
  __int64 v61; // r4 OVERLAPPED
  unsigned __int8 v62; // r10
  int v63; // r7
  unsigned __int8 v64; // r10
  __int64 v65; // r7 OVERLAPPED
  unsigned __int8 v66; // r10
  int v67; // r8
  unsigned __int8 v68; // r10
  idMem *v69; // r28
  char *v70; // r30
  unsigned __int8 *v71; // r3
  int v72; // r29
  unsigned __int8 *v73; // r19
  bool v74; // zf
  unsigned __int8 *v75; // r3
  unsigned __int8 *v76; // r20
  int v77; // r3
  unsigned __int8 *v78; // r3
  unsigned __int8 *v79; // r23
  int v80; // r3
  int v81; // r30
  void *v82; // r26
  void *v83; // r25
  const transcodeParms_t **v84; // r24
  unsigned int j; // r22
  unsigned int v86; // r11
  int v87; // r10
  int v88; // r9
  int v89; // r8
  const transcodeParms_t *v90; // r11
  pageCompression_t inPageCompression; // r7
  unsigned __int16 *inPageHeader; // r8
  int v93; // r28
  int v94; // r26
  int v95; // r25
  int v96; // r4
  int v97; // r19
  int v98; // r20
  int v99; // r23
  int v100; // r8
  void (__fastcall *v101)(const transcodeParms_t *); // r30
  const transcodeParms_t *v102; // r10
  pageCompression_t v103; // r11
  int k; // r31
  __int64 v105; // r8
  const char *v106; // r3
  __int64 v107; // r10
  __int64 v108; // r6
  unsigned int LastError; // r3
  double v110; // fp1
  double v111; // fp31
  double v112; // fp30
  int v113; // r8
  signed int v114; // r7
  int v115; // r31
  const char *v116; // r6
  const transcodeParms_t *v117; // r26
  int inPageDataLength; // r25
  pageCompression_t outPageCompression; // r3
  __int64 v120; // r7
  double v121; // r7
  int v122; // [sp+8h] [-12D8h]
  int v123; // [sp+Ch] [-12D4h]
  int v124; // [sp+10h] [-12D0h]
  int v125; // [sp+14h] [-12CCh]
  double v126; // [sp+18h] [-12C8h]
  unsigned __int8 *v127; // [sp+70h] [-1270h] BYREF
  unsigned __int8 *v128; // [sp+74h] [-126Ch] BYREF
  unsigned __int8 *v129; // [sp+78h] [-1268h]
  int v130; // [sp+7Ch] [-1264h]
  char v131; // [sp+80h] [-1260h]
  unsigned __int8 v132; // [sp+81h] [-125Fh]
  char v133; // [sp+82h] [-125Eh]
  unsigned __int8 *v134; // [sp+84h] [-125Ch] BYREF
  char *v135; // [sp+88h] [-1258h]
  int v136; // [sp+8Ch] [-1254h] BYREF
  int v137[2]; // [sp+90h] [-1250h] BYREF
  __int64 v138; // [sp+98h] [-1248h]
  unsigned int v139[2]; // [sp+A0h] [-1240h] BYREF
  __int64 v140; // [sp+A8h] [-1238h]
  __int64 v141; // [sp+B0h] [-1230h]
  __int64 v142; // [sp+B8h] [-1228h]
  __int64 v143; // [sp+C0h] [-1220h]
  __int64 v144; // [sp+C8h] [-1218h]
  __int64 v145; // [sp+D0h] [-1210h]
  __int64 v146; // [sp+D8h] [-1208h]
  __int64 v147; // [sp+E0h] [-1200h]
  __int64 v148; // [sp+E8h] [-11F8h]
  __int64 v149; // [sp+F0h] [-11F0h]
  __int64 v150; // [sp+F8h] [-11E8h]
  __int64 v151; // [sp+100h] [-11E0h]
  __int64 v152; // [sp+108h] [-11D8h]
  __int64 v153; // [sp+110h] [-11D0h]
  __int64 v154; // [sp+118h] [-11C8h]
  int v155; // [sp+120h] [-11C0h] BYREF
  int v156; // [sp+124h] [-11BCh] BYREF
  int v157; // [sp+128h] [-11B8h] BYREF
  _DWORD v158[29]; // [sp+12Ch] [-11B4h] BYREF
  __int64 v159; // [sp+1A0h] [-1140h]
  __int64 v160; // [sp+1A8h] [-1138h]
  __int64 v161; // [sp+1B0h] [-1130h]
  __int64 v162; // [sp+1B8h] [-1128h]
  __int64 v163; // [sp+1C0h] [-1120h]
  __int64 v164; // [sp+1C8h] [-1118h]
  __int64 v165; // [sp+1D0h] [-1110h]
  __int64 v166; // [sp+1D8h] [-1108h]
  compressionStats_t v167; // [sp+1E0h] [-1100h] BYREF
  va v168; // [sp+220h] [-10C0h] BYREF

  argc = args->argc;
  LODWORD(v2) = 0;
  HIDWORD(v2) = &byte_8200D768;
  v131 = 0;
  v132 = 0;
  v4 = 0;
  v133 = 0;
  v5 = 0;
  v135 = &byte_8200D768;
  v6 = 0;
  v7 = 1;
  if ( argc > 1 )
  {
    v8 = (const char **)&args->argv[1];
    do
    {
      if ( v7 < 0 || v7 >= argc )
        v9 = &byte_8200D768;
      else
        v9 = (char *)*v8;
      v10 = *v9;
      if ( v10 == 45 || v10 == 43 )
        ++v9;
      if ( idStr::Icmp(s1: v9, s2: "trace") != 0 )
      {
        if ( idStr::Icmp(s1: v9, s2: "spu") != 0 )
        {
          if ( idStr::Icmp(s1: v9, s2: "cuda") != 0 )
          {
            if ( idStr::Icmp(s1: v9, s2: "lossless") != 0 )
            {
              if ( idStr::Icmp(s1: v9, s2: "ratio") != 0 )
              {
                if ( idStr::Icmp(s1: v9, s2: "size") != 0 )
                {
                  idLib::Printf(fmt: "vt_testTranscodePerformance [trace|spu|cuda|lossless|ratio <x>|size <x>]\n");
                  return;
                }
                ++v7;
                ++v8;
                if ( v7 < 0 || v7 >= args->argc )
                  v11 = &byte_8200D768;
                else
                  v11 = *v8;
                v6 = atol(nptr: v11);
              }
              else
              {
                ++v7;
                ++v8;
                if ( v7 < 0 || v7 >= args->argc )
                  v5 = atol(nptr: &byte_8200D768);
                else
                  v5 = atol(nptr: *v8);
              }
            }
            else
            {
              v4 = 1;
            }
          }
          else
          {
            v133 = 1;
          }
        }
        else
        {
          v132 = 1;
        }
      }
      else
      {
        v131 = 1;
      }
      argc = args->argc;
      ++v7;
      ++v8;
    }
    while ( v7 < args->argc );
  }
  v167.headerBytes = v2;
  v167.specularBytes = v2;
  v167.diffuseBytes = v2;
  v167.normalBytes = v2;
  v167.powerBytes = v2;
  v167.coverBytes = v2;
  v167.wastedBytes = v2;
  v167.diskOffsetScale = 64;
  if ( R_LoadTGA(name: "textures/mre/test_specular.tga", pic: &v128, width: v137, height: &v136, timestamp: v139)
    && R_LoadTGA(name: "textures/mre/test_diffuse.tga", pic: &v134, width: v137, height: &v136, timestamp: v139)
    && R_LoadTGA(name: "textures/mre/test_normal.tga", pic: &v127, width: v137, height: &v136, timestamp: v139) )
  {
    idColorSpace::ConvertRGBToCoCg_Y(dst: v134, src: v134, width: 128, height: 128);
    v13 = 0;
    v14 = 4096;
    v15 = v128;
    do
    {
      v15[3] = 0;
      v16 = v127[v13 + 1];
      v17 = v127[v13];
      v127[v13] = 0;
      v127[v13 + 1] = v16;
      v127[v13 + 2] = 0;
      v127[v13 + 3] = v17;
      v128[v13 + 7] = 0;
      v18 = v127[v13 + 5];
      v19 = v127[v13 + 4];
      v127[v13 + 4] = 0;
      v127[v13 + 5] = v18;
      v127[v13 + 6] = 0;
      v127[v13 + 7] = v19;
      v128[v13 + 11] = 0;
      v20 = v127[v13 + 9];
      v21 = &v127[v13 + 12];
      v22 = *(v21 - 4);
      *(v21 - 4) = 0;
      v127[v13 + 9] = v20;
      v127[v13 + 10] = 0;
      v127[v13 + 11] = v22;
      v128[v13 + 15] = 0;
      v23 = v127[v13 + 12];
      v24 = v127[v13 + 13];
      v127[v13 + 12] = 0;
      v127[v13 + 13] = v24;
      v127[v13 + 14] = 0;
      v127[v13 + 15] = v23;
      v13 += 16;
      v15 = &v128[v13];
      --v14;
    }
    while ( v14 != 0 );
    if ( v6 != 0 )
    {
      v25 = 0;
      HIDWORD(v26) = 6;
      for ( i = 2048; i != 0; --i )
      {
        HIDWORD(v29) = (unsigned __int8)((2 * (v128[v25 + 2] + v128[v25 + 1] + v128[v25]) + 3) / 6) >> 3;
        v128[v25] = BYTE3(v29);
        LODWORD(v28) = HIDWORD(v29);
        HIDWORD(v28) = &v128[v25];
        *(_BYTE *)(HIDWORD(v28) + 1) = BYTE3(v29);
        v128[v25 + 2] = BYTE3(v29);
        v141 = v28;
        LODWORD(v29) = v127[v25 + 1];
        v150 = v29;
        v130 = (int)(float)((float)((float)((float)v29 - (float)128.0) * (float)((float)v28 * (float)0.0039215689))
                          + (float)128.0);
        v30 = v130;
        if ( v130 >= 0 )
        {
          if ( v130 > 255 )
            v30 = -1;
        }
        else
        {
          v30 = 0;
        }
        v127[v25 + 1] = v30;
        v31 = v127[v25 + 3];
        v146 = *(__int64 *)((char *)&v29 - 4);
        v130 = (int)(float)((float)((float)((float)*(__int64 *)((char *)&v29 - 4) - (float)128.0)
                                  * (float)((float)v28 * (float)0.0039215689))
                          + (float)128.0);
        v32 = v130;
        if ( v130 >= 0 )
        {
          if ( v130 > 255 )
            v32 = -1;
        }
        else
        {
          v32 = 0;
        }
        v127[v25 + 3] = v32;
        HIDWORD(v34) = (unsigned __int8)((2 * (v128[v25 + 6] + v128[v25 + 5] + v128[v25 + 4]) + 3) / 6) >> 3;
        v128[v25 + 4] = BYTE3(v34);
        LODWORD(v33) = HIDWORD(v34);
        HIDWORD(v33) = &v128[v25];
        v143 = v33;
        *(_BYTE *)(HIDWORD(v33) + 5) = BYTE3(v34);
        v128[v25 + 6] = BYTE3(v34);
        LODWORD(v34) = v127[v25 + 5];
        v149 = v34;
        v130 = (int)(float)((float)((float)((float)v34 - (float)128.0) * (float)((float)v33 * (float)0.0039215689))
                          + (float)128.0);
        v35 = v130;
        if ( v130 >= 0 )
        {
          if ( v130 > 255 )
            v35 = -1;
        }
        else
        {
          v35 = 0;
        }
        v127[v25 + 5] = v35;
        v36 = v127[v25 + 7];
        v151 = *(__int64 *)((char *)&v34 - 4);
        v130 = (int)(float)((float)((float)((float)*(__int64 *)((char *)&v34 - 4) - (float)128.0)
                                  * (float)((float)v33 * (float)0.0039215689))
                          + (float)128.0);
        v37 = v130;
        if ( v130 >= 0 )
        {
          if ( v130 > 255 )
            v37 = -1;
        }
        else
        {
          v37 = 0;
        }
        v127[v25 + 7] = v37;
        v38 = v25 + 12;
        v39 = &v128[v25 + 12];
        v40 = (unsigned __int8)((2 * (v128[v25 + 10] + v128[v25 + 9] + *(v39 - 4)) + 3) / 6) >> 3;
        *(v39 - 4) = v40;
        v41 = v40;
        v128[v25 + 9] = v40;
        v140 = *(_QWORD *)(&v12 - 1);
        v128[v25 + 10] = v40;
        LODWORD(v26) = v127[v25 + 9];
        v153 = v26;
        v42 = (float)((float)v140 * (float)0.0039215689);
        v130 = (int)(float)((float)((float)((float)v26 - (float)128.0) * (float)((float)v140 * (float)0.0039215689))
                          + (float)128.0);
        v43 = v130;
        if ( v130 >= 0 )
        {
          if ( v130 > 255 )
            v43 = -1;
        }
        else
        {
          v43 = 0;
        }
        v127[v25 + 9] = v43;
        v44 = v127[v25 + 11];
        v144 = *(__int64 *)((char *)&v26 - 4);
        v130 = (int)(float)((float)((float)((float)*(__int64 *)((char *)&v26 - 4) - (float)128.0) * (float)v42)
                          + (float)128.0);
        v45 = v130;
        if ( v130 >= 0 )
        {
          if ( v130 > 255 )
            v45 = -1;
        }
        else
        {
          v45 = 0;
        }
        v127[v25 + 11] = v45;
        v46 = (unsigned __int8)((2 * (v128[v25 + 14] + v128[v25 + 13] + v128[v38]) + 3) / 6) >> 3;
        v128[v38] = v46;
        v47 = v46;
        v128[v25 + 13] = v46;
        v154 = *(_QWORD *)(&v12 - 1);
        v128[v25 + 14] = v46;
        LODWORD(v26) = v127[v25 + 13];
        v152 = v26;
        v130 = (int)(float)((float)((float)((float)v26 - (float)128.0)
                                  * (float)((float)*(__int64 *)(&v12 - 1) * (float)0.0039215689))
                          + (float)128.0);
        v48 = v130;
        if ( v130 >= 0 )
        {
          if ( v130 > 255 )
            v48 = -1;
        }
        else
        {
          v48 = 0;
        }
        v127[v25 + 13] = v48;
        v49 = v127[v25 + 15];
        v142 = *(__int64 *)((char *)&v26 - 4);
        v130 = (int)(float)((float)((float)((float)*(__int64 *)((char *)&v26 - 4) - (float)128.0)
                                  * (float)((float)*(__int64 *)(&v12 - 1) * (float)0.0039215689))
                          + (float)128.0);
        v50 = v130;
        if ( v130 >= 0 )
        {
          if ( v130 > 255 )
            v50 = -1;
        }
        else
        {
          v50 = 0;
        }
        v127[v25 + 15] = v50;
        v51 = (unsigned __int8)((2 * (v128[v25 + 18] + v128[v25 + 17] + v128[v38 + 4]) + 3) / 6) >> 3;
        v128[v38 + 4] = v51;
        v52 = v51;
        v128[v25 + 17] = v51;
        v128[v25 + 18] = v51;
        v148 = *(_QWORD *)(&v12 - 1);
        LODWORD(v26) = v127[v25 + 17];
        v147 = v26;
        v130 = (int)(float)((float)((float)((float)v26 - (float)128.0)
                                  * (float)((float)*(__int64 *)(&v12 - 1) * (float)0.0039215689))
                          + (float)128.0);
        v53 = v130;
        if ( v130 >= 0 )
        {
          if ( v130 > 255 )
            v53 = -1;
        }
        else
        {
          v53 = 0;
        }
        v127[v25 + 17] = v53;
        v54 = v127[v25 + 19];
        v138 = *(__int64 *)((char *)&v26 - 4);
        v130 = (int)(float)((float)((float)((float)*(__int64 *)((char *)&v26 - 4) - (float)128.0)
                                  * (float)((float)*(__int64 *)(&v12 - 1) * (float)0.0039215689))
                          + (float)128.0);
        v55 = v130;
        if ( v130 >= 0 )
        {
          if ( v130 > 255 )
            v55 = -1;
        }
        else
        {
          v55 = 0;
        }
        v127[v25 + 19] = v55;
        v56 = (unsigned __int8)((2 * (v128[v25 + 22] + v128[v25 + 21] + v128[v38 + 8]) + 3) / 6) >> 3;
        v128[v38 + 8] = v56;
        v57 = v56;
        v159 = *(_QWORD *)(&v12 - 1);
        v128[v25 + 21] = v56;
        v128[v25 + 22] = v56;
        LODWORD(v26) = v127[v25 + 21];
        v162 = v26;
        v130 = (int)(float)((float)((float)((float)v26 - (float)128.0)
                                  * (float)((float)*(__int64 *)(&v12 - 1) * (float)0.0039215689))
                          + (float)128.0);
        v58 = v130;
        if ( v130 >= 0 )
        {
          if ( v130 > 255 )
            v58 = -1;
        }
        else
        {
          v58 = 0;
        }
        v127[v25 + 21] = v58;
        v59 = v127[v25 + 23];
        v165 = *(__int64 *)((char *)&v26 - 4);
        v130 = (int)(float)((float)((float)((float)*(__int64 *)((char *)&v26 - 4) - (float)128.0)
                                  * (float)((float)*(__int64 *)(&v12 - 1) * (float)0.0039215689))
                          + (float)128.0);
        v60 = v130;
        if ( v130 >= 0 )
        {
          if ( v130 > 255 )
            v60 = -1;
        }
        else
        {
          v60 = 0;
        }
        v127[v25 + 23] = v60;
        LODWORD(v61) = (unsigned __int8)((2 * (v128[v25 + 26] + v128[v25 + 25] + v128[v38 + 12]) + 3) / 6) >> 3;
        v128[v38 + 12] = v61;
        HIDWORD(v61) = v61;
        v128[v25 + 25] = v61;
        v161 = *(_QWORD *)(&v12 - 1);
        v128[v25 + 26] = v61;
        LODWORD(v26) = v127[v25 + 25];
        v166 = v26;
        v130 = (int)(float)((float)((float)((float)v26 - (float)128.0)
                                  * (float)((float)*(__int64 *)(&v12 - 1) * (float)0.0039215689))
                          + (float)128.0);
        v62 = v130;
        if ( v130 >= 0 )
        {
          if ( v130 > 255 )
            v62 = -1;
        }
        else
        {
          v62 = 0;
        }
        v127[v25 + 25] = v62;
        v63 = v127[v25 + 27];
        v163 = *(__int64 *)((char *)&v26 - 4);
        v130 = (int)(float)((float)((float)((float)*(__int64 *)((char *)&v26 - 4) - (float)128.0)
                                  * (float)((float)*(__int64 *)(&v12 - 1) * (float)0.0039215689))
                          + (float)128.0);
        v64 = v130;
        if ( v130 >= 0 )
        {
          if ( v130 > 255 )
            v64 = -1;
        }
        else
        {
          v64 = 0;
        }
        v127[v25 + 27] = v64;
        HIDWORD(v65) = (unsigned __int8)((2 * (v128[v25 + 30] + v128[v25 + 29] + v128[v38 + 16]) + 3) / 6) >> 3;
        v128[v38 + 16] = BYTE3(v65);
        LODWORD(v61) = HIDWORD(v65);
        v164 = v61;
        v128[v25 + 29] = BYTE3(v65);
        v128[v25 + 30] = BYTE3(v65);
        LODWORD(v65) = v127[v25 + 29];
        v160 = v65;
        v130 = (int)(float)((float)((float)((float)v65 - (float)128.0) * (float)((float)v61 * (float)0.0039215689))
                          + (float)128.0);
        v66 = v130;
        if ( v130 >= 0 )
        {
          if ( v130 > 255 )
            v66 = -1;
        }
        else
        {
          v66 = 0;
        }
        v127[v25 + 29] = v66;
        v67 = v127[v25 + 31];
        v145 = *(__int64 *)((char *)&v65 - 4);
        v130 = (int)(float)((float)((float)((float)*(__int64 *)((char *)&v65 - 4) - (float)128.0)
                                  * (float)((float)v61 * (float)0.0039215689))
                          + (float)128.0);
        v68 = v130;
        if ( v130 >= 0 )
        {
          if ( v130 > 255 )
            v68 = -1;
        }
        else
        {
          v68 = 0;
        }
        v127[v25 + 31] = v68;
        v25 += 32;
      }
    }
    R_WriteTGA(
      filename: "textures/mre/actual_specular.tga",
      data: v128,
      width: 128,
      height: 128,
      depth: 4,
      flipVertical: false,
      swapRGB: true,
      basePath: FSPATH_BASE);
    R_WriteTGA(
      filename: "textures/mre/actual_diffuse.tga",
      data: v134,
      width: 128,
      height: 128,
      depth: 4,
      flipVertical: false,
      swapRGB: true,
      basePath: FSPATH_BASE);
    R_WriteTGA(
      filename: "textures/mre/actual_normal.tga",
      data: v127,
      width: 128,
      height: 128,
      depth: 4,
      flipVertical: false,
      swapRGB: true,
      basePath: FSPATH_BASE);
    v69 = &mem;
    HIDWORD(v149) = &mem;
    v70 = (char *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\engine\\renderer\\development\\VirtualTextureSystemTest.cpp(2186) : TAG_VIRTUALTEXTURE",
                    size: 0x30000u,
                    tag: TAG_VIRTUALTEXTURE,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    memcpy(Dst: v70, Src: v128, Size: 0x10000u);
    memcpy(Dst: v70 + 0x10000, Src: v134, Size: 0x10000u);
    memcpy(Dst: v70 + 0x20000, Src: v127, Size: 0x10000u);
    idMem::Free(this: &mem, ptr: v128, align: ALIGN_16);
    idMem::Free(this: &mem, ptr: v134, align: ALIGN_16);
    idMem::Free(this: &mem, ptr: v127, align: ALIGN_16);
    v71 = (unsigned __int8 *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\engine\\renderer\\development\\VirtualTextureSystemTest.cpp(2195) : TAG_VIRTUALTEXTURE",
                               size: 0x30000u,
                               tag: TAG_VIRTUALTEXTURE,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    v72 = v4;
    HIDWORD(v141) = v71;
    v74 = v4 == 0;
    v73 = v71;
    if ( v74 )
    {
      if ( v5 != 0 )
      {
        FindDCTQualityForRatio(
          uncompressed: (const unsigned __int8 *)v70,
          uncompressedSize: 196608,
          customDCT: v71,
          maxCompressedSize: 196608,
          ratio: v5);
      }
      else if ( v6 != 0 )
      {
        FindDCTQualityForSize(
          uncompressed: (const unsigned __int8 *)v70,
          uncompressedSize: 196608,
          customDCT: v71,
          maxCompressedSize: 196608,
          size: v6);
      }
    }
    else
    {
      idCVar::SetInteger(this: &vt_qualityDCTSpecular, newValue: 100, force: true);
      idCVar::SetInteger(this: &vt_qualityDCTLuma, newValue: 100, force: true);
      idCVar::SetInteger(this: &vt_qualityDCTChroma, newValue: 100, force: true);
      idCVar::SetInteger(this: &vt_qualityDCTNormal, newValue: 100, force: true);
    }
    testTranscodeParmsCustomDCT.inPageDataLength = DCT_Compress(
                                                     src: v70,
                                                     length: 196608,
                                                     dest: v73,
                                                     maxDestLength: 196608,
                                                     storeCover: false,
                                                     storeAlpha: false,
                                                     stats: &v167)
                                                 - 16;
    testTranscodeParmsCustomDCT.inPageHeader = v73;
    testTranscodeParmsCustomDCT.inPageData = v73 + 16;
    v75 = (unsigned __int8 *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\engine\\renderer\\development\\VirtualTextureSystemTest.cpp(2214) : TAG_VIRTUALTEXTURE",
                               size: 0x30000u,
                               tag: TAG_VIRTUALTEXTURE,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    v76 = v75;
    HIDWORD(v150) = v75;
    if ( v72 != 0 )
    {
      idCVar::SetInteger(this: &vt_qualityHDPSpecular, newValue: 0, force: true);
      idCVar::SetInteger(this: &vt_qualityHDPDiffuse, newValue: 0, force: true);
      idCVar::SetInteger(this: &vt_qualityHDPNormal, newValue: 0, force: true);
    }
    else if ( v5 != 0 )
    {
      FindHDPQualityForRatio(
        uncompressed: (const unsigned __int8 *)v70,
        uncompressedSize: 196608,
        customHDP: v75,
        maxCompressedSize: 196608,
        ratio: v5);
    }
    else if ( v6 != 0 )
    {
      FindHDPQualityForSize(
        uncompressed: (const unsigned __int8 *)v70,
        uncompressedSize: 196608,
        customHDP: v75,
        maxCompressedSize: 196608,
        size: v6);
    }
    v77 = HDP_Compress(
            src: v70,
            length: 196608,
            dest: v76,
            maxDestLength: 196608,
            storeCover: false,
            storeAlpha: false,
            stats: &v167);
    testTranscodeParmsCustomHDP.inPageHeader = v76;
    testTranscodeParmsCustomHDP.inPageDataLength = v77 - 16;
    testTranscodeParmsCustomHDP.inPageData = v76 + 16;
    v78 = (unsigned __int8 *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\engine\\renderer\\development\\VirtualTextureSystemTest.cpp(2232) : TAG_VIRTUALTEXTURE",
                               size: 0x30000u,
                               tag: TAG_VIRTUALTEXTURE,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    v79 = v78;
    v129 = v78;
    if ( v72 != 0 )
    {
      idCVar::SetInteger(this: &vt_qualityJXRSpecular, newValue: 0, force: true);
      idCVar::SetInteger(this: &vt_qualityJXRDiffuse, newValue: 0, force: true);
      idCVar::SetInteger(this: &vt_qualityJXRNormal, newValue: 0, force: true);
    }
    else if ( v5 != 0 )
    {
      FindJXRQualityForRatio(
        uncompressed: (const unsigned __int8 *)v70,
        uncompressedSize: 196608,
        customJXR: v78,
        maxCompressedSize: 196608,
        ratio: v5);
    }
    else if ( v6 != 0 )
    {
      FindJXRQualityForSize(
        uncompressed: (const unsigned __int8 *)v70,
        uncompressedSize: 196608,
        customJXR: v78,
        maxCompressedSize: 196608,
        size: v6);
    }
    v80 = JXR_Compress(
            src: v70,
            length: 196608,
            dest: v79,
            maxDestLength: 196608,
            storeCover: false,
            storeAlpha: false,
            stats: &v167);
    testTranscodeParmsCustomJXR.inPageHeader = v79;
    testTranscodeParmsCustomJXR.inPageDataLength = v80 - 16;
    testTranscodeParmsCustomJXR.inPageData = v79 + 16;
    idMem::Free(this: &mem, ptr: v70, align: ALIGN_16);
    HIDWORD(v154) = &virtualTextureSystem;
    if ( virtualTextureSystem.physicalPagesPool[1].pageImageCompressed )
      v81 = 40960;
    else
      v81 = 196608;
    v82 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\engine\\renderer\\development\\VirtualTextureSystemTest.cpp(2258) : TAG_VIRTUALTEXTURE",
            size: 0x30080u,
            tag: TAG_VIRTUALTEXTURE,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    HIDWORD(v146) = v82;
    v83 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\engine\\renderer\\development\\VirtualTextureSystemTest.cpp(2259) : TAG_VIRTUALTEXTURE",
            size: v81 + 128,
            tag: TAG_VIRTUALTEXTURE,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    HIDWORD(v143) = v83;
    idRenderSystemLocal::SyncRenderThread(this: &tr, syncGPU: false);
    HIDWORD(v138) = 0;
    v84 = (const transcodeParms_t **)testTranscodeParms;
    HIDWORD(v153) = "BeginTraceRecording: error %d\n";
    HIDWORD(v151) = "%1.2f msec to %s -> %s transcode a %1.1f kB (%d bytes) page (%d clocks per texel - %1.1f MP/s) (0x%0"
                    "8X / 0x%08X / 0x%08X)\n";
    HIDWORD(v140) = "%1.2f msec (%1.1f MP/s) to %s%s (%d:1)\n";
    HIDWORD(v144) = "e:\\trnscd %d %s%s.pix2";
    HIDWORD(v142) = "DXT5 Normal Map compress";
    HIDWORD(v148) = "DXT5 YCoCg compress";
    HIDWORD(v147) = "DXT1 Specular compress";
    for ( j = 0; j < 8; HIDWORD(v138) = j )
    {
      if ( j == 3 || j == 7 )
      {
        v86 = ((unsigned int)v83 + 127) & 0xFFFFFF80;
        v87 = 0;
        (*v84)->tempData = (unsigned __int8 *)(((unsigned int)v82 + 127) & 0xFFFFFF80);
        v88 = 0;
        v89 = 0;
        (*v84)->targetImage[0] = (unsigned __int8 *)(v86 + 0x8000);
        (*v84)->targetImage[1] = (unsigned __int8 *)v86;
        (*v84)->targetImage[2] = (unsigned __int8 *)(v86 + 0x4000);
        v90 = *v84;
        inPageCompression = (*v84)->inPageCompression;
        if ( inPageCompression == COMP_DCT || inPageCompression == COMP_HDP || inPageCompression == COMP_JXR )
        {
          inPageHeader = (unsigned __int16 *)v90->inPageHeader;
          v87 = inPageHeader[5];
          v88 = inPageHeader[3];
          v89 = inPageHeader[4];
        }
        v93 = 9;
        v158[21] = v90->imageFlags;
        HIDWORD(v152) = 20;
        v155 = 9;
        v156 = 49152;
        v94 = 0;
        v158[0] = HIDWORD(v147);
        v95 = 0;
        v157 = 0x2000;
        v158[1] = 10;
        v158[2] = 49152;
        v158[3] = 0x4000;
        v158[4] = HIDWORD(v148);
        v158[5] = 12;
        v158[6] = 0x8000;
        v158[7] = 0x4000;
        v158[8] = HIDWORD(v142);
        v158[9] = 17;
        v158[10] = 49152;
        v158[11] = v87;
        v158[12] = " Specular decompress";
        v158[13] = 18;
        v158[14] = 49152;
        v158[15] = v88;
        v158[16] = " YCoCg decompress";
        v158[17] = 20;
        v158[18] = 0x8000;
        v158[19] = v89;
        v158[20] = " Normal Map decompress";
        v158[22] = 0;
        v158[23] = 0;
        v158[24] = v135;
        memset(&v158[25], 0, 12);
        v158[28] = v135;
        idLib::Printf(fmt: "------------------------------------\n");
        v97 = v132;
        v98 = 0;
        v99 = 0;
        do
        {
          v100 = HIDWORD(v154);
          v101 = TranscodePage;
          (*v84)->imageFlags = v93;
          if ( *(_BYTE *)(v100 + 49632) != 0 )
          {
            v102 = *v84;
            if ( !(*v84)->stripPageBorders
              && (*((_BYTE *)v102 + 94) & 0x80) == 0
              && (*((_BYTE *)v102 + 94) & 0x40) == 0
              && (*((_BYTE *)v102 + 94) & 0x20) == 0
              && (*((_BYTE *)v102 + 94) & 0x10) == 0
              && (*((_BYTE *)v102 + 94) & 8) == 0
              && v102->dbgShowPageMips == 0
              && v102->dbgShowPageSizes == 0
              && v102->dbgShowPageUsage == 0 )
            {
              v103 = v102->inPageCompression;
              switch ( v103 )
              {
                case COMP_DXT:
                  v101 = TranscodePage_DXT_DXT;
                  break;
                case COMP_DCT:
                  if ( (v102->imageFlags & 0x18) != 0 )
                    v101 = TestPerformance_DCT_DXT;
                  else
                    v101 = TranscodePage_DCT_DXT;
                  break;
                case COMP_HDP:
                  if ( (v102->imageFlags & 0x18) != 0 )
                    v101 = TestPerformance_HDP_DXT;
                  else
                    v101 = TranscodePage_HDP_DXT;
                  break;
                case COMP_JXR:
                  if ( (v102->imageFlags & 0x18) != 0 )
                    v101 = TestPerformance_JXR_DXT;
                  else
                    v101 = TranscodePage_JXR_DXT;
                  break;
                default:
                  break;
              }
            }
          }
          if ( (v97 == 0
             || v101 != TranscodePage_DXT_DXT
             && v101 != TranscodePage_DCT_DXT
             && v101 != TestPerformance_DCT_DXT
             && v101 != TranscodePage_HDP_DXT
             && v101 != TestPerformance_HDP_DXT
             && v101 != TranscodePage_JXR_DXT
             && v101 != TestPerformance_JXR_DXT)
            && (v133 == 0 || v101 != TranscodePage_DCT_DXT) )
          {
            for ( k = 8; k != 0; --k )
              v101(parms: *v84);
            if ( v131 != 0 )
            {
              v106 = StringForPageCompression(c: (*v84)->inPageCompression);
              LODWORD(v107) = v93 & 0x10;
              LODWORD(v108) = v106;
              if ( (v93 & 0x10) == 0 )
              {
                LODWORD(v107) = v158[v99];
                HIDWORD(v107) = *(unsigned __int8 *)v107;
                if ( *(_BYTE *)v107 != 0 )
                  LODWORD(v108) = v135;
              }
              HIDWORD(v108) = HIDWORD(v138);
              HIDWORD(v105) = v158[v99];
              va::va(
                this: &v168,
                fmt: (const char *)HIDWORD(v144),
                a3: v108,
                a4: v105,
                a5: v107,
                a6: v122,
                a7: v123,
                a8: v124,
                a9: v125,
                a10: SHIDWORD(v126),
                a11: SLODWORD(v126));
              LastError = GetLastError();
              idLib::Printf(fmt: (const char *)HIDWORD(v153), LastError);
            }
            v94 = Sys_Microseconds() >> 32;
            v101(parms: *v84);
            v95 = Sys_Microseconds() >> 32;
            v96 = Sys_ClockTicksPerSecond();
          }
          v110 = _u64tod(a1: v95 - v94, a2: v96);
          v111 = (float)((float)v110 * (float)0.001);
          v112 = (float)((float)16.384001 / (float)((float)v110 * (float)0.001));
          if ( (v93 & 0x18) != 0 )
          {
            v113 = *(int *)((char *)&v156 + v99 * 4);
            v114 = v158[v99 - 1];
            v115 = v113 / v114;
            __twllei(v114, 0);
            __twlgei(v114 & ~(__ROL4__(v113, 1) - 1), 0xFFFFFFFF);
            if ( (v93 & 0x10) != 0 )
              v116 = StringForPageCompression(c: (*v84)->inPageCompression);
            else
              v116 = v135;
            v126 = v111;
            idLib::Printf(
              fmt: (const char *)HIDWORD(v111),
              LODWORD(v111),
              LODWORD(v112),
              v116,
              v158[v99],
              v115,
              v111,
              v112);
          }
          ++v98;
          v99 = 4 * v98;
          v93 = *(&v155 + 4 * v98);
        }
        while ( v93 != 0 );
        MD5_BlockChecksum(data: (*v84)->targetImage[0], length: 0x2000u);
        MD5_BlockChecksum(data: (*v84)->targetImage[1], length: 0x4000u);
        MD5_BlockChecksum(data: (*v84)->targetImage[2], length: 0x4000u);
        v117 = *v84;
        inPageDataLength = (*v84)->inPageDataLength;
        outPageCompression = (*v84)->outPageCompression;
        LODWORD(v120) = inPageDataLength;
        v145 = v120;
        StringForPageCompression(c: outPageCompression);
        StringForPageCompression(c: v117->inPageCompression);
        v126 = v111;
        v121 = (float)((float)v145 * (float)0.0009765625);
        idLib::Printf(
          fmt: (const char *)HIDWORD(v151),
          LODWORD(v111),
          HIDWORD(v111),
          HIDWORD(v121),
          LODWORD(v121),
          inPageDataLength,
          v112,
          v111);
        v69 = (idMem *)HIDWORD(v149);
        j = HIDWORD(v138);
        v83 = (void *)HIDWORD(v143);
        v82 = (void *)HIDWORD(v146);
        v79 = v129;
        v76 = (unsigned __int8 *)HIDWORD(v150);
        v73 = (unsigned __int8 *)HIDWORD(v141);
      }
      ++j;
      ++v84;
    }
    idMem::Free(this: v69, ptr: v82, align: ALIGN_16);
    idMem::Free(this: v69, ptr: v83, align: ALIGN_16);
    idMem::Free(this: v69, ptr: v73, align: ALIGN_16);
    idMem::Free(this: v69, ptr: v76, align: ALIGN_16);
    idMem::Free(this: v69, ptr: v79, align: ALIGN_16);
  }
}


// ========================================================================
// ConvertGlobalMapToReflectionMap
// EA  : 0x828BC698
// RVA : 0x008BC698
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall ConvertGlobalMapToReflectionMap(unsigned __int8 *globalMap, int width, int height)
{
  int v3; // r27
  __int64 v4; // r8 OVERLAPPED
  int v5; // r29
  int v6; // r31
  int v7; // ctr
  __int64 v8; // r10
  double v9; // fp7
  unsigned __int8 *v10; // r6
  double v11; // fp6
  int v12; // r11
  __int64 v13; // r10
  double v14; // fp5
  double v15; // fp4
  double v16; // fp3
  double v19; // fp2
  double v20; // fp1
  double v21; // fp1
  double v22; // fp13
  double v23; // fp5
  int v24; // r10
  int v25; // r10
  int v26; // r10
  __int64 v27; // [sp+10h] [-60h]

  v3 = 0;
  if ( height > 0 )
  {
    HIDWORD(v4) = 0x82000000;
    v5 = 0;
    do
    {
      v6 = 0;
      if ( width > 0 )
      {
        v7 = width;
        LODWORD(v8) = v3;
        HIDWORD(v8) = width / 2;
        LODWORD(v4) = width / 2;
        v9 = (float)v8;
        v10 = globalMap + 1;
        v11 = (float)v4;
        HIDWORD(v4) = globalMap + 2;
        do
        {
          LODWORD(v8) = v6;
          v27 = v8;
          v12 = 4 * (v5 + v6);
          LODWORD(v4) = globalMap[v12];
          HIDWORD(v13) = *(unsigned __int8 *)(HIDWORD(v4) + v12);
          LODWORD(v13) = v10[v12];
          v14 = (float)((float)v27
                      - (float)((float)((float)((float)((float)v13 * (float)0.0078431377) - (float)1.0)
                                      * (float)((float)((float)v9
                                                      * (float)((float)((float)v4 * (float)0.0078431377) - (float)1.0))
                                              + (float)((float)((float)((float)((float)v13 * (float)0.0078431377)
                                                                      - (float)1.0)
                                                              * (float)v27)
                                                      + (float)((float)((float)((float)*(__int64 *)((char *)&v4 - 4)
                                                                              * (float)0.0078431377)
                                                                      - (float)1.0)
                                                              * (float)v11))))
                              * (float)2.0));
          v15 = (float)((float)v11
                      - (float)((float)((float)((float)((float)*(__int64 *)((char *)&v4 - 4) * (float)0.0078431377)
                                              - (float)1.0)
                                      * (float)((float)((float)v9
                                                      * (float)((float)((float)v4 * (float)0.0078431377) - (float)1.0))
                                              + (float)((float)((float)((float)((float)v13 * (float)0.0078431377)
                                                                      - (float)1.0)
                                                              * (float)v27)
                                                      + (float)((float)((float)((float)*(__int64 *)((char *)&v4 - 4)
                                                                              * (float)0.0078431377)
                                                                      - (float)1.0)
                                                              * (float)v11))))
                              * (float)2.0));
          v16 = (float)((float)v9
                      - (float)((float)((float)((float)((float)v4 * (float)0.0078431377) - (float)1.0)
                                      * (float)((float)((float)v9
                                                      * (float)((float)((float)v4 * (float)0.0078431377) - (float)1.0))
                                              + (float)((float)((float)((float)((float)v13 * (float)0.0078431377)
                                                                      - (float)1.0)
                                                              * (float)v27)
                                                      + (float)((float)((float)((float)*(__int64 *)((char *)&v4 - 4)
                                                                              * (float)0.0078431377)
                                                                      - (float)1.0)
                                                              * (float)v11))))
                              * (float)2.0));
          _FP1 = (float)((float)((float)((float)v16 * (float)v16)
                               + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f13, f1, f2, f13 }
          v19 = __frsqrte(_FP13);
          v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                              * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5))
                                                                                      * (float)v19)
                                                                              - (float)1.5)
                                                              * (float)v19)
                                                      * (float)((float)((float)((float)v16 * (float)v16)
                                                                      + (float)((float)((float)v15 * (float)v15)
                                                                              + (float)((float)v14 * (float)v14)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v19
                                                              * (float)((float)((float)((float)v16 * (float)v16)
                                                                              + (float)((float)((float)v15 * (float)v15)
                                                                                      + (float)((float)v14 * (float)v14)))
                                                                      * (float)0.5))
                                                      * (float)v19)
                                              - (float)1.5)
                              * (float)v19));
          v21 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5)) * (float)v19) - (float)1.5) * (float)v19)
                                                                                              * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5)) * (float)v19) - (float)1.5)
                                                                                              * (float)v19))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5))
                                                                                              * (float)v19)
                                                                                      - (float)1.5)
                                                                      * (float)v19))
                                                      * (float)((float)((float)((float)v16 * (float)v16)
                                                                      + (float)((float)((float)v15 * (float)v15)
                                                                              + (float)((float)v14 * (float)v14)))
                                                              * (float)0.5))
                                              * (float)v20)
                                      - (float)1.5)
                      * (float)v20);
          v22 = (float)((float)((float)v27
                              - (float)((float)((float)((float)((float)v13 * (float)0.0078431377) - (float)1.0)
                                              * (float)((float)((float)v9
                                                              * (float)((float)((float)v4 * (float)0.0078431377)
                                                                      - (float)1.0))
                                                      + (float)((float)((float)((float)((float)v13 * (float)0.0078431377)
                                                                              - (float)1.0)
                                                                      * (float)v27)
                                                              + (float)((float)((float)((float)*(__int64 *)((char *)&v4 - 4)
                                                                                      * (float)0.0078431377)
                                                                              - (float)1.0)
                                                                      * (float)v11))))
                                      * (float)2.0))
                      * (float)v21);
          v23 = (float)((float)((float)v11
                              - (float)((float)((float)((float)((float)*(__int64 *)((char *)&v4 - 4)
                                                              * (float)0.0078431377)
                                                      - (float)1.0)
                                              * (float)((float)((float)v9
                                                              * (float)((float)((float)v4 * (float)0.0078431377)
                                                                      - (float)1.0))
                                                      + (float)((float)((float)((float)((float)v13 * (float)0.0078431377)
                                                                              - (float)1.0)
                                                                      * (float)v27)
                                                              + (float)((float)((float)((float)*(__int64 *)((char *)&v4 - 4)
                                                                                      * (float)0.0078431377)
                                                                              - (float)1.0)
                                                                      * (float)v11))))
                                      * (float)2.0))
                      * (float)v21);
          v24 = (int)(float)((float)((float)((float)((float)((float)v9
                                                           - (float)((float)((float)((float)((float)v4
                                                                                           * (float)0.0078431377)
                                                                                   - (float)1.0)
                                                                           * (float)((float)((float)v9
                                                                                           * (float)((float)((float)v4 * (float)0.0078431377) - (float)1.0))
                                                                                   + (float)((float)((float)((float)((float)v13 * (float)0.0078431377) - (float)1.0) * (float)v27)
                                                                                           + (float)((float)((float)((float)*(__int64 *)((char *)&v4 - 4) * (float)0.0078431377) - (float)1.0) * (float)v11))))
                                                                   * (float)2.0))
                                                   * (float)v21)
                                           + (float)1.0)
                                   * (float)127.5)
                           + (float)0.5);
          if ( v24 >= 0 )
          {
            if ( v24 > 255 )
              LOBYTE(v24) = -1;
          }
          else
          {
            LOBYTE(v24) = 0;
          }
          globalMap[v12] = v24;
          v25 = (int)(float)((float)((float)((float)v22 + (float)1.0) * (float)127.5) + (float)0.5);
          if ( v25 >= 0 )
          {
            if ( v25 > 255 )
              LOBYTE(v25) = -1;
          }
          else
          {
            LOBYTE(v25) = 0;
          }
          v10[v12] = v25;
          v26 = (int)(float)((float)((float)((float)v23 + (float)1.0) * (float)127.5) + (float)0.5);
          if ( v26 >= 0 )
          {
            if ( v26 > 255 )
              LOBYTE(v26) = -1;
          }
          else
          {
            LOBYTE(v26) = 0;
          }
          *(_BYTE *)(HIDWORD(v4) + v12) = v26;
          ++v6;
          HIDWORD(v8) = 2 * ((unsigned __int8)v26 + globalMap[v12] + v10[v12]) + 3;
          LOBYTE(v8) = SHIDWORD(v8) / 6;
          *(_BYTE *)(HIDWORD(v4) + v12) = v8;
          v10[v12] = v8;
          globalMap[v12] = v8;
          --v7;
        }
        while ( v7 != 0 );
      }
      ++v3;
      v5 += width;
    }
    while ( v3 < height );
  }
}


// ========================================================================
// DeriveNormalZ
// EA  : 0x828BC928
// RVA : 0x008BC928
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

void __fastcall DeriveNormalZ(unsigned __int8 *normalImage, int width, int height)
{
  int v3; // ctr
  unsigned __int8 *v4; // r11
  __int64 v5; // r6
  __int64 v6; // r10
  double v7; // fp3
  double v8; // fp4
  int v9; // r10

  if ( width * height > 0 )
  {
    v3 = width * height;
    v4 = normalImage + 3;
    do
    {
      LODWORD(v5) = *(v4 - 2);
      v6 = *v4;
      HIDWORD(v5) = *v4;
      *(v4 - 3) = v6;
      v7 = (float)((float)((float)v6 * (float)0.0078431377) - (float)1.0);
      v8 = (float)((float)((float)v5 * (float)0.0078431377) - (float)1.0);
      v9 = (int)(float)((float)((float)((float)__fsqrts(__fabs((float)-(float)((float)((float)v8 * (float)v8)
                                                                             - (float)-(float)((float)((float)v7 * (float)v7)
                                                                                             - (float)1.0))))
                                      + (float)1.0)
                              * (float)127.5)
                      + (float)0.5);
      if ( v9 >= 0 )
      {
        if ( v9 > 255 )
          LOBYTE(v9) = -1;
      }
      else
      {
        LOBYTE(v9) = 0;
      }
      *(v4 - 1) = v9;
      *v4 = 0;
      v4 += 4;
      --v3;
    }
    while ( v3 != 0 );
  }
}


// ========================================================================
// TransformLocalMapToGlobalMap
// EA  : 0x828BC9F8
// RVA : 0x008BC9F8
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall TransformLocalMapToGlobalMap(
        const unsigned __int8 *localMap,
        int width,
        int height,
        const char *modelName,
        const char *materialName,
        unsigned __int8 *globalMap)
{
  unsigned int v6; // r30
  int v7; // r26
  int v8; // r24
  const char *v10; // r23
  idMem *v12; // r25
  idStaticModel *v13; // r3
  idStaticModel *v14; // r28
  char *buffer; // r17
  int v16; // r2 OVERLAPPED
  int v17; // r27
  double v18; // fp29
  double v19; // fp22
  double v20; // fp23
  double v21; // fp25
  int v22; // r29
  _DWORD *v23; // r30
  __int64 v24; // r9
  int v25; // r25
  int v26; // r11
  unsigned __int16 *v27; // r14
  double v28; // fp24
  double v29; // fp9
  double v30; // fp11
  double v31; // fp13
  int v32; // r9
  double v33; // fp12
  double v34; // fp0
  int v35; // r11
  int v36; // r10
  double v37; // fp5
  double v38; // fp4
  double v39; // fp3
  double v40; // fp2
  double v41; // fp1
  double v42; // fp31
  float *v43; // r9
  _BYTE v44[12]; // r8
  float *v45; // r11
  int v46; // ctr
  int v47; // r18
  int v48; // r16
  int v49; // r4
  int v50; // r15
  double v51; // fp13
  double v52; // fp0
  float *v53; // r10
  double v54; // fp8
  double v57; // fp12
  double v58; // fp11
  double v59; // fp12
  double v60; // fp11
  double v61; // fp8
  double v62; // fp14
  int v63; // r23
  double v64; // fp7
  double v65; // fp6
  double v66; // fp15
  int v67; // r24
  int v68; // r26
  int v69; // r27
  __int64 v70; // r10
  int v71; // r11
  double v72; // fp0
  double v73; // fp13
  double v74; // fp12
  double v75; // fp11
  double v76; // fp10
  double v77; // fp10
  double v78; // fp0
  double v79; // fp29
  double v80; // fp23
  unsigned __int16 *v81; // r29
  double v82; // fp25
  unsigned int *p_num; // r28
  double v84; // fp24
  int v85; // r30
  double v86; // fp20
  double v87; // fp22
  double v88; // fp21
  double v89; // fp17
  double v90; // fp18
  double v91; // fp19
  double v92; // fp31
  __int64 v93; // r5
  int v94; // r9
  int v95; // r3
  double v96; // fp9
  int v97; // r9
  double v98; // fp11
  double v99; // fp2
  double v100; // fp10
  double v101; // fp8
  double v102; // fp5
  double v103; // fp3
  double v107; // fp0
  double v108; // fp0
  double v109; // fp9
  double v110; // fp1
  double v112; // fp9
  double v113; // fp12
  double v114; // fp9
  idDrawVert *BiTangent; // r3
  double v116; // fp12
  __int64 v117; // r4 OVERLAPPED
  double v118; // fp8
  double v119; // fp6
  double v120; // fp5
  double v123; // fp11
  double v124; // fp1
  double v125; // fp11
  int v126; // r11
  int v127; // r11
  int v128; // r11
  int v129; // [sp+58h] [-258h]
  float v130; // [sp+60h] [-250h]
  int v131; // [sp+68h] [-248h]
  int v132; // [sp+6Ch] [-244h]
  idStaticModel *v133; // [sp+70h] [-240h]
  _DWORD *v134; // [sp+74h] [-23Ch]
  int v135; // [sp+78h] [-238h] BYREF
  float v136; // [sp+80h] [-230h] BYREF
  float v137; // [sp+84h] [-22Ch]
  float v138; // [sp+88h] [-228h]
  float v139; // [sp+8Ch] [-224h]
  float v140; // [sp+90h] [-220h]
  float v141; // [sp+94h] [-21Ch]
  float v142; // [sp+98h] [-218h]
  float v143; // [sp+9Ch] [-214h]
  float v144; // [sp+A0h] [-210h]
  float v145; // [sp+A4h] [-20Ch]
  float v146; // [sp+A8h] [-208h]
  float v147; // [sp+ACh] [-204h]
  float v148; // [sp+B0h] [-200h]
  idMem *v149; // [sp+B4h] [-1FCh]
  float v150; // [sp+B8h] [-1F8h]
  float v151; // [sp+BCh] [-1F4h]
  float v152; // [sp+C0h] [-1F0h]
  float v153; // [sp+C4h] [-1ECh]
  idTempArray<char> v154; // [sp+C8h] [-1E8h] BYREF
  float v155; // [sp+D0h] [-1E0h]
  float v156; // [sp+D4h] [-1DCh]
  float v157; // [sp+D8h] [-1D8h]
  float v158[37]; // [sp+DCh] [-1D4h] BYREF
  idDrawVert v159[5]; // [sp+170h] [-140h] BYREF

  v6 = width * height;
  v7 = width;
  v8 = height;
  v10 = materialName;
  memset(Dst: globalMap, Val: 0, Size: 4 * width * height);
  v12 = &mem;
  v149 = &mem;
  v13 = (idStaticModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                           size: 0x194u,
                           tag: TAG_NEW,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v13 != nullptr )
    v14 = idStaticModel::idStaticModel(this: v13);
  else
    v14 = nullptr;
  v133 = v14;
  idResource::SetName(this: v14, _name: modelName);
  v14->LoadResource(this: v14);
  if ( v14->resourceError != nullptr )
  {
    ((void (__fastcall *)(idStaticModel *, int))v14->dtr_idResource)(a1: v14, a2: 1);
    idLib::Warning(fmt: "Couldn't load model: %s", modelName);
    return;
  }
  idTempArray<char>::idTempArray<char>(this: &v154, num: v6);
  buffer = v154.buffer;
  memset(Dst: v154.buffer, Val: 255, Size: v154.num);
  v17 = 0;
  v131 = 0;
  if ( v14->surfaces.num > 0 )
  {
    v18 = -4.0;
    v19 = 4.5;
    v20 = -99999.0;
    v21 = 99999.0;
    v22 = 0;
    v132 = 0;
    v147 = 127.5;
    v152 = 1.01;
    v144 = 0.99000001;
    v142 = -4.0;
    v145 = 4.5;
    v150 = -99999.0;
    v146 = 99999.0;
    do
    {
      v23 = (const idMaterial **)((char *)&v14->surfaces.list->material + v22);
      v134 = v23;
      if ( *(_DWORD *)(*v23 + 268) != 1 && (v10 == nullptr || idStr::Icmp(s1: *(const char **)(*v23 + 8), s2: v10) == 0) )
      {
        LODWORD(v24) = v23[4];
        v129 = 0;
        HIDWORD(v24) = *(_DWORD *)(v24 + 28);
        v25 = *(_DWORD *)(v24 + 88);
        v26 = *(_DWORD *)(v24 + 92);
        if ( SHIDWORD(v24) > 0 )
        {
          LODWORD(v24) = v7;
          *(_QWORD *)&v158[23] = v24;
          *(_QWORD *)&v158[35] = __PAIR64__(v7, v8);
          v27 = (unsigned __int16 *)(v26 + 4);
          v28 = (float)__SPAIR64__(v7, v8);
          v143 = (float)__SPAIR64__(v7, v8);
          v29 = (float)v24;
          v148 = (float)v24;
          do
          {
            v30 = v21;
            v31 = v21;
            v32 = __ROL4__(*(v27 - 2), 5) + v25;
            v33 = v20;
            v34 = v20;
            v35 = __ROL4__(*(v27 - 1), 5) + v25;
            v36 = __ROL4__(*v27, 5) + v25;
            v37 = (float)((float)((float)v29 * *(float *)(v32 + 12)) - (float)0.5);
            v38 = (float)((float)(*(float *)(v32 + 16) * (float)v28) - (float)0.5);
            v39 = (float)((float)((float)v29 * *(float *)(v35 + 12)) - (float)0.5);
            v40 = (float)((float)((float)v29 * *(float *)(v36 + 12)) - (float)0.5);
            v41 = (float)((float)(*(float *)(v35 + 16) * (float)v28) - (float)0.5);
            v42 = (float)((float)(*(float *)(v36 + 16) * (float)v28) - (float)0.5);
            v138 = (float)((float)v29 * *(float *)(v35 + 12)) - (float)0.5;
            v140 = v40;
            v139 = v41;
            v141 = v42;
            v136 = v37;
            v137 = v38;
            if ( v37 < v21 )
              v30 = v37;
            if ( v37 > v20 )
              v33 = v37;
            if ( v39 < v30 )
              v30 = v39;
            if ( v39 > v33 )
              v33 = v39;
            if ( v40 < v30 )
              v30 = v40;
            if ( v40 > v33 )
              v33 = v40;
            if ( v38 < v21 )
              v31 = v38;
            if ( v38 > v20 )
              v34 = v38;
            if ( v41 < v31 )
              v31 = v41;
            if ( v41 > v34 )
              v34 = v41;
            if ( v42 < v31 )
              v31 = v42;
            if ( v42 > v34 )
              v34 = v42;
            v43 = (float *)&v135;
            *(_DWORD *)&v44[4] = 0;
            v45 = v158;
            v46 = 3;
            v47 = (int)(float)((float)v33 + (float)v19);
            v48 = (int)(float)((float)v34 + (float)v19);
            v49 = (int)(float)((float)v31 - (float)4.0);
            v50 = (int)(float)((float)v30 - (float)4.0);
            do
            {
              v51 = v43[3];
              v43 += 2;
              v52 = *v43;
              *(_DWORD *)&v44[8] = (unsigned __int64)(1431655766LL * ++*(_DWORD *)&v44[4]) >> 32;
              *(_DWORD *)v44 = *(_DWORD *)&v44[4] - 3 * (*(_DWORD *)&v44[8] + (*(_DWORD *)&v44[8] >> 31));
              v53 = &v136 + 2 * *(_DWORD *)v44;
              v54 = (float)(v53[1] - (float)v51);
              _FP12 = (float)((float)((float)((float)(*v43 - *v53) * (float)(*v43 - *v53))
                                    + (float)((float)v54 * (float)v54))
                            - idMath::FLT_SMALLEST_NON_DENORMAL);
              __asm { fsel      f7, f12, f7, f11 }
              v57 = __frsqrte(_FP7);
              v58 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57
                                                                                                  * (float)((float)((float)((float)(*v43 - *v53) * (float)(*v43 - *v53)) + (float)((float)v54 * (float)v54)) * (float)0.5))
                                                                                          * (float)v57)
                                                                                  - (float)1.5)
                                                                  * (float)v57)
                                                          * (float)((float)((float)((float)(*v43 - *v53)
                                                                                  * (float)(*v43 - *v53))
                                                                          + (float)((float)v54 * (float)v54))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v57
                                                                                          * (float)((float)((float)((float)(*v43 - *v53) * (float)(*v43 - *v53)) + (float)((float)v54 * (float)v54))
                                                                                                  * (float)0.5))
                                                                                  * (float)v57)
                                                                          - (float)1.5)
                                                          * (float)v57))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v57
                                                                  * (float)((float)((float)((float)(*v43 - *v53)
                                                                                          * (float)(*v43 - *v53))
                                                                                  + (float)((float)v54 * (float)v54))
                                                                          * (float)0.5))
                                                          * (float)v57)
                                                  - (float)1.5)
                                  * (float)v57));
              v59 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)((float)((float)((float)(*v43 - *v53) * (float)(*v43 - *v53)) + (float)((float)v54 * (float)v54)) * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57)
                                                                                                  * (float)((float)((float)((float)(*v43 - *v53) * (float)(*v43 - *v53)) + (float)((float)v54 * (float)v54)) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)((float)((float)(*v43 - *v53) * (float)(*v43 - *v53)) + (float)((float)v54 * (float)v54)) * (float)0.5)) * (float)v57) - (float)1.5)
                                                                                                  * (float)v57))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)((float)((float)(*v43 - *v53) * (float)(*v43 - *v53)) + (float)((float)v54 * (float)v54)) * (float)0.5))
                                                                                                  * (float)v57)
                                                                                          - (float)1.5)
                                                                          * (float)v57))
                                                          * (float)((float)((float)((float)(*v43 - *v53)
                                                                                  * (float)(*v43 - *v53))
                                                                          + (float)((float)v54 * (float)v54))
                                                                  * (float)0.5))
                                                  * (float)v58)
                                          - (float)1.5)
                          * (float)v58);
              v60 = (float)((float)(*v43 - *v53) * (float)v59);
              v45[2] = (float)(*v43 - *v53) * (float)v59;
              v45[1] = (float)v54 * (float)v59;
              v45 += 3;
              *v45 = -(float)((float)((float)((float)v54 * (float)v59) * (float)v52) + (float)((float)v60 * (float)v51));
              --v46;
            }
            while ( v46 != 0 );
            v61 = (float)((float)v40 - (float)v37);
            v153 = (float)v40 - (float)v37;
            v62 = (float)((float)v41 - (float)v38);
            v63 = v49;
            v64 = (float)((float)v39 - (float)v37);
            v130 = (float)v39 - (float)v37;
            v65 = (float)((float)v42 - (float)v38);
            v151 = (float)v42 - (float)v38;
            v66 = (float)((float)1.0 / (float)((float)(v151 * v130) - (float)(v153 * (float)((float)v41 - (float)v38))));
            if ( v49 < v48 )
            {
              v67 = v49 * width;
              do
              {
                if ( v63 >= 0 && v63 < height )
                {
                  v68 = v50;
                  if ( v50 < v47 )
                  {
                    while ( 1 )
                    {
                      if ( v68 >= 0 && v68 < width )
                      {
                        v69 = 4 * (v67 + v68);
                        HIDWORD(v70) = v69 >> 2;
                        v71 = (unsigned __int8)buffer[v69 >> 2];
                        if ( v71 != 1 )
                        {
                          LODWORD(v70) = v63;
                          *(_DWORD *)&v44[8] = v68;
                          *(_QWORD *)&v158[25] = v70;
                          *(_QWORD *)&v158[33] = *(_QWORD *)&v44[4];
                          v74 = (float)((float)((float)(v158[2] * (float)((float)v70 + (float)0.5))
                                              + (float)(v158[1] * (float)((float)*(__int64 *)&v44[4] + (float)0.5)))
                                      + v158[3]);
                          v73 = (float)((float)v70 + (float)0.5);
                          v75 = (float)((float)((float)(v158[5] * (float)((float)v70 + (float)0.5))
                                              + (float)(v158[4] * (float)((float)*(__int64 *)&v44[4] + (float)0.5)))
                                      + v158[6]);
                          v76 = (float)((float)((float)(v158[8] * (float)((float)v70 + (float)0.5))
                                              + (float)(v158[7] * (float)((float)*(__int64 *)&v44[4] + (float)0.5)))
                                      + v158[9]);
                          if ( v74 >= v18 && v75 >= v18 && v76 >= v18 )
                            goto LABEL_58;
                          if ( v74 <= 4.0 && v75 <= 4.0 && v76 <= 4.0 )
                          {
LABEL_58:
                            if ( v74 >= 0.0 && v75 >= 0.0 && v76 >= 0.0 || v74 <= 0.0 && v75 <= 0.0 && v76 <= 0.0 )
                            {
                              LOBYTE(v70) = 1;
LABEL_61:
                              v77 = v144;
                              buffer[HIDWORD(v70)] = (unsigned __int8)v70 != 0;
                              v157 = (float)((float)((float)((float)v73 - (float)v38) * (float)v64)
                                           - (float)((float)((float)((float)*(__int64 *)&v44[4] + (float)0.5)
                                                           - (float)v37)
                                                   * (float)v62))
                                   * (float)v66;
                              v156 = (float)((float)((float)v65
                                                   * (float)((float)((float)*(__int64 *)&v44[4] + (float)0.5)
                                                           - (float)v37))
                                           - (float)((float)v61 * (float)((float)v73 - (float)v38)))
                                   * (float)v66;
                              v72 = (float)((float)*(__int64 *)&v44[4] + (float)0.5);
                              v155 = (float)((float)((float)((float)v42 - (float)v73) * (float)((float)v39 - (float)v72))
                                           - (float)((float)((float)v40 - (float)v72) * (float)((float)v41 - (float)v73)))
                                   * (float)v66;
                              v78 = (float)((float)(v157 + v156) + v155);
                              if ( v78 >= v77 && v78 <= v152 )
                              {
                                v79 = idMath::FLT_SMALLEST_NON_DENORMAL;
                                v80 = 0.0;
                                v81 = v27 - 3;
                                v82 = 0.0;
                                p_num = &v154.num;
                                v84 = 0.0;
                                v85 = 3;
                                v86 = 0.0;
                                v87 = 0.0;
                                v88 = 0.0;
                                v89 = 0.0;
                                v90 = 0.0;
                                v91 = 0.0;
                                do
                                {
                                  ++v81;
                                  v92 = *(float *)++p_num;
                                  HIDWORD(v93) = __ROL4__(*v81, 5) + v25;
                                  *(_DWORD *)&v44[4] = *(unsigned __int8 *)(HIDWORD(v93) + 22);
                                  LODWORD(v93) = *(unsigned __int8 *)(HIDWORD(v93) + 20);
                                  v94 = *(unsigned __int8 *)(HIDWORD(v93) + 21);
                                  v95 = *(unsigned __int8 *)(HIDWORD(v93) + 24);
                                  *(_DWORD *)&v44[8] = *(unsigned __int8 *)(HIDWORD(v93) + 26);
                                  *(_QWORD *)&v158[15] = *(_QWORD *)v44;
                                  *(_QWORD *)&v158[27] = v93;
                                  *(_QWORD *)&v158[19] = *(_QWORD *)&v44[-4];
                                  v96 = (double)*(__int64 *)&v44[-4];
                                  *(_QWORD *)&v158[29] = *(_QWORD *)(&v16 - 1);
                                  *(_QWORD *)&v158[31] = *(_QWORD *)&v44[4];
                                  v97 = *(unsigned __int8 *)(HIDWORD(v93) + 25);
                                  *(_QWORD *)&v158[11] = *(_QWORD *)&v44[-4];
                                  v98 = (float)((float)((float)v96 * (float)0.0078431377) - (float)1.0);
                                  v99 = (float)((float)((float)v93 * (float)0.0078431377) - (float)1.0);
                                  v100 = (float)((float)((float)*(__int64 *)v44 * (float)0.0078431377) - (float)1.0);
                                  v101 = (float)((float)((float)*(__int64 *)&v44[-4] * (float)0.0078431377) - (float)1.0);
                                  v102 = (float)((float)((float)*(__int64 *)(&v16 - 1) * (float)0.0078431377)
                                               - (float)1.0);
                                  v103 = (float)((float)((float)*(__int64 *)&v44[4] * (float)0.0078431377) - (float)1.0);
                                  _FP9 = (float)((float)((float)((float)v100 * (float)v100)
                                                       + (float)((float)((float)v99 * (float)v99)
                                                               + (float)((float)v98 * (float)v98)))
                                               - (float)v79);
                                  __asm { fsel      f1, f9, f13, f29 }
                                  _FP4 = (float)((float)((float)((float)v103 * (float)v103)
                                                       + (float)((float)((float)v102 * (float)v102)
                                                               + (float)((float)v101 * (float)v101)))
                                               - (float)v79);
                                  v107 = __frsqrte(_FP1);
                                  v108 = (float)((float)-(float)((float)((float)((float)v107
                                                                               * (float)((float)((float)((float)v100 * (float)v100)
                                                                                               + (float)((float)((float)v99 * (float)v99) + (float)((float)v98 * (float)v98)))
                                                                                       * (float)0.5))
                                                                       * (float)v107)
                                                               - (float)1.5)
                                               * (float)v107);
                                  v109 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v108 * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v99 * (float)v99) + (float)((float)v98 * (float)v98))) * (float)0.5)) * (float)v108) - (float)1.5)
                                                                                       * (float)v108)
                                                                               * (float)((float)((float)((float)v100 * (float)v100)
                                                                                               + (float)((float)((float)v99 * (float)v99) + (float)((float)v98 * (float)v98)))
                                                                                       * (float)0.5))
                                                                       * (float)((float)-(float)((float)((float)((float)v108 * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v99 * (float)v99) + (float)((float)v98 * (float)v98))) * (float)0.5)) * (float)v108)
                                                                                               - (float)1.5)
                                                                               * (float)v108))
                                                               - (float)1.5)
                                               * (float)((float)-(float)((float)((float)((float)v108
                                                                                       * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v99 * (float)v99) + (float)((float)v98 * (float)v98)))
                                                                                               * (float)0.5))
                                                                               * (float)v108)
                                                                       - (float)1.5)
                                                       * (float)v108));
                                  v110 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v108 * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v99 * (float)v99) + (float)((float)v98 * (float)v98))) * (float)0.5)) * (float)v108) - (float)1.5)
                                                                                               * (float)v108)
                                                                                       * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v99 * (float)v99) + (float)((float)v98 * (float)v98)))
                                                                                               * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)v108 * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v99 * (float)v99) + (float)((float)v98 * (float)v98))) * (float)0.5)) * (float)v108) - (float)1.5)
                                                                                       * (float)v108))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v108
                                                                                               * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v99 * (float)v99) + (float)((float)v98 * (float)v98))) * (float)0.5))
                                                                                       * (float)v108)
                                                                               - (float)1.5)
                                                               * (float)v108))
                                               * (float)v100);
                                  __asm { fsel      f10, f4, f12, f29 }
                                  v84 = (float)((float)v84 + (float)((float)v110 * (float)v92));
                                  v80 = (float)((float)((float)((float)v109
                                                              * (float)((float)((float)v93 * (float)0.0078431377)
                                                                      - (float)1.0))
                                                      * (float)v92)
                                              + (float)v80);
                                  v82 = (float)((float)v82 + (float)((float)((float)v109 * (float)v98) * (float)v92));
                                  v112 = __frsqrte(_FP10);
                                  v113 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v112 * (float)((float)((float)((float)v103 * (float)v103) + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101))) * (float)0.5)) * (float)v112) - (float)1.5)
                                                                                       * (float)v112)
                                                                               * (float)((float)((float)((float)v103 * (float)v103)
                                                                                               + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101)))
                                                                                       * (float)0.5))
                                                                       * (float)((float)-(float)((float)((float)((float)v112 * (float)((float)((float)((float)v103 * (float)v103) + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101))) * (float)0.5)) * (float)v112)
                                                                                               - (float)1.5)
                                                                               * (float)v112))
                                                               - (float)1.5)
                                               * (float)((float)-(float)((float)((float)((float)v112
                                                                                       * (float)((float)((float)((float)v103 * (float)v103) + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101)))
                                                                                               * (float)0.5))
                                                                               * (float)v112)
                                                                       - (float)1.5)
                                                       * (float)v112));
                                  v114 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v112 * (float)((float)((float)((float)v103 * (float)v103) + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101))) * (float)0.5)) * (float)v112) - (float)1.5) * (float)v112) * (float)((float)((float)((float)v103 * (float)v103) + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v112 * (float)((float)((float)((float)v103 * (float)v103) + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101))) * (float)0.5)) * (float)v112) - (float)1.5) * (float)v112)) - (float)1.5)
                                                                                       * (float)((float)-(float)((float)((float)((float)v112 * (float)((float)((float)((float)v103 * (float)v103) + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101))) * (float)0.5)) * (float)v112) - (float)1.5)
                                                                                               * (float)v112))
                                                                               * (float)((float)((float)((float)v103 * (float)v103)
                                                                                               + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101)))
                                                                                       * (float)0.5))
                                                                       * (float)v113)
                                                               - (float)1.5)
                                               * (float)v113);
                                  v86 = (float)((float)((float)((float)v114
                                                              * (float)((float)((float)*(__int64 *)(&v16 - 1)
                                                                              * (float)0.0078431377)
                                                                      - (float)1.0))
                                                      * (float)v92)
                                              + (float)v86);
                                  v88 = (float)((float)v88
                                              + (float)((float)((float)v114
                                                              * (float)((float)((float)*(__int64 *)&v44[4]
                                                                              * (float)0.0078431377)
                                                                      - (float)1.0))
                                                      * (float)v92));
                                  v87 = (float)((float)v87
                                              + (float)((float)((float)v114
                                                              * (float)((float)((float)*(__int64 *)&v44[-4]
                                                                              * (float)0.0078431377)
                                                                      - (float)1.0))
                                                      * (float)v92));
                                  BiTangent = idDrawVert::GetBiTangent(
                                                this: v159,
                                                result: (const idVec3 *)HIDWORD(v93),
                                                a3: v93,
                                                a4: *(int *)v44,
                                                a5: *(__int64 *)&v44[4]);
                                  --v85;
                                  v89 = (float)((float)(BiTangent->xyz.x * (float)v92) + (float)v89);
                                  v91 = (float)((float)v91 + (float)(BiTangent->xyz.z * (float)v92));
                                  v90 = (float)((float)v90 + (float)(BiTangent->xyz.y * (float)v92));
                                }
                                while ( v85 != 0 );
                                v116 = v147;
                                *(_DWORD *)v44 = localMap[v69];
                                HIDWORD(v117) = localMap[v69 + 1];
                                LODWORD(v117) = localMap[v69 + 2];
                                *(_QWORD *)&v158[13] = *(_QWORD *)&v44[8];
                                *(_QWORD *)&v158[21] = *(_QWORD *)(&v16 - 1);
                                *(_QWORD *)&v158[17] = v117;
                                v118 = (float)((float)((float)v87
                                                     * (float)((float)((float)*(__int64 *)&v44[8] * (float)0.0078431377)
                                                             - (float)1.0))
                                             + (float)((float)((float)((float)((float)*(__int64 *)(&v16 - 1)
                                                                             * (float)0.0078431377)
                                                                     - (float)1.0)
                                                             * (float)v90)
                                                     + (float)((float)((float)((float)v117 * (float)0.0078431377)
                                                                     - (float)1.0)
                                                             * (float)v82)));
                                v120 = (float)((float)((float)v88
                                                     * (float)((float)((float)*(__int64 *)&v44[8] * (float)0.0078431377)
                                                             - (float)1.0))
                                             + (float)((float)((float)((float)((float)*(__int64 *)(&v16 - 1)
                                                                             * (float)0.0078431377)
                                                                     - (float)1.0)
                                                             * (float)v91)
                                                     + (float)((float)((float)((float)v117 * (float)0.0078431377)
                                                                     - (float)1.0)
                                                             * (float)v84)));
                                v119 = (float)((float)((float)((float)((float)*(__int64 *)&v44[8] * (float)0.0078431377)
                                                             - (float)1.0)
                                                     * (float)v86)
                                             + (float)((float)((float)((float)((float)*(__int64 *)(&v16 - 1)
                                                                             * (float)0.0078431377)
                                                                     - (float)1.0)
                                                             * (float)v89)
                                                     + (float)((float)((float)((float)v117 * (float)0.0078431377)
                                                                     - (float)1.0)
                                                             * (float)v80)));
                                _FP1 = (float)((float)((float)((float)v120 * (float)v120)
                                                     + (float)((float)((float)v119 * (float)v119)
                                                             + (float)((float)v118 * (float)v118)))
                                             - (float)v79);
                                __asm { fsel      f13, f1, f2, f29 }
                                v123 = __frsqrte(_FP13);
                                v124 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v123 * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5)) * (float)v123) - (float)1.5)
                                                                                     * (float)v123)
                                                                             * (float)((float)((float)((float)v120 * (float)v120)
                                                                                             + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118)))
                                                                                     * (float)0.5))
                                                                     * (float)((float)-(float)((float)((float)((float)v123 * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5)) * (float)v123)
                                                                                             - (float)1.5)
                                                                             * (float)v123))
                                                             - (float)1.5)
                                             * (float)((float)-(float)((float)((float)((float)v123
                                                                                     * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118)))
                                                                                             * (float)0.5))
                                                                             * (float)v123)
                                                                     - (float)1.5)
                                                     * (float)v123));
                                v125 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v123 * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5)) * (float)v123) - (float)1.5) * (float)v123) * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v123 * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5)) * (float)v123) - (float)1.5) * (float)v123)) - (float)1.5)
                                                                                     * (float)((float)-(float)((float)((float)((float)v123 * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5)) * (float)v123) - (float)1.5)
                                                                                             * (float)v123))
                                                                             * (float)((float)((float)((float)v120 * (float)v120)
                                                                                             + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118)))
                                                                                     * (float)0.5))
                                                                     * (float)v124)
                                                             - (float)1.5)
                                             * (float)v124);
                                v126 = (int)(float)((float)((float)((float)((float)((float)((float)((float)((float)*(__int64 *)&v44[8] * (float)0.0078431377)
                                                                                                  - (float)1.0)
                                                                                          * (float)v86)
                                                                                  + (float)((float)((float)((float)((float)*(__int64 *)(&v16 - 1) * (float)0.0078431377) - (float)1.0)
                                                                                                  * (float)v89)
                                                                                          + (float)((float)((float)((float)v117 * (float)0.0078431377) - (float)1.0)
                                                                                                  * (float)v80)))
                                                                          * (float)v125)
                                                                  + (float)1.0)
                                                          * v147)
                                                  + (float)0.5);
                                if ( v126 >= 0 )
                                {
                                  if ( v126 > 255 )
                                    LOBYTE(v126) = -1;
                                }
                                else
                                {
                                  LOBYTE(v126) = 0;
                                }
                                globalMap[v69] = v126;
                                v127 = (int)(float)((float)((float)((float)((float)((float)((float)v87
                                                                                          * (float)((float)((float)*(__int64 *)&v44[8] * (float)0.0078431377)
                                                                                                  - (float)1.0))
                                                                                  + (float)((float)((float)((float)((float)*(__int64 *)(&v16 - 1) * (float)0.0078431377) - (float)1.0)
                                                                                                  * (float)v90)
                                                                                          + (float)((float)((float)((float)v117 * (float)0.0078431377) - (float)1.0)
                                                                                                  * (float)v82)))
                                                                          * (float)v125)
                                                                  + (float)1.0)
                                                          * (float)v116)
                                                  + (float)0.5);
                                if ( v127 >= 0 )
                                {
                                  if ( v127 > 255 )
                                    LOBYTE(v127) = -1;
                                }
                                else
                                {
                                  LOBYTE(v127) = 0;
                                }
                                globalMap[v69 + 1] = v127;
                                v128 = (int)(float)((float)((float)((float)((float)((float)((float)v88
                                                                                          * (float)((float)((float)*(__int64 *)&v44[8] * (float)0.0078431377)
                                                                                                  - (float)1.0))
                                                                                  + (float)((float)((float)((float)((float)*(__int64 *)(&v16 - 1) * (float)0.0078431377) - (float)1.0)
                                                                                                  * (float)v91)
                                                                                          + (float)((float)((float)((float)v117 * (float)0.0078431377) - (float)1.0)
                                                                                                  * (float)v84)))
                                                                          * (float)v125)
                                                                  + (float)1.0)
                                                          * (float)v116)
                                                  + (float)0.5);
                                if ( v128 >= 0 )
                                {
                                  if ( v128 > 255 )
                                    LOBYTE(v128) = -1;
                                }
                                else
                                {
                                  LOBYTE(v128) = 0;
                                }
                                v65 = v151;
                                v61 = v153;
                                v64 = v130;
                                v42 = v141;
                                v41 = v139;
                                v38 = v137;
                                globalMap[v69 + 2] = v128;
                                v40 = v140;
                                v39 = v138;
                                v18 = v142;
                                v37 = v136;
                              }
                              goto LABEL_78;
                            }
                            LOBYTE(v70) = 0;
                            if ( v71 != 0 )
                              goto LABEL_61;
                          }
                        }
                      }
LABEL_78:
                      if ( ++v68 >= v47 )
                      {
                        v21 = v146;
                        v20 = v150;
                        v29 = v148;
                        v28 = v143;
                        break;
                      }
                    }
                  }
                }
                ++v63;
                v67 += width;
              }
              while ( v63 < v48 );
              v19 = v145;
            }
            v27 += 3;
            v129 += 3;
          }
          while ( v129 < *(_DWORD *)(v134[4] + 28) );
          v22 = v132;
          v17 = v131;
          v14 = v133;
          v8 = height;
          v10 = materialName;
          v7 = width;
        }
      }
      ++v17;
      v22 += 72;
      v131 = v17;
      v132 = v22;
    }
    while ( v17 < v14->surfaces.num );
    v12 = v149;
  }
  ((void (__fastcall *)(idStaticModel *, int))v14->dtr_idResource)(a1: v14, a2: 1);
  if ( buffer != nullptr )
    idMem::Free(this: v12, ptr: buffer, align: ALIGN_16);
}


// ========================================================================
// __unwind$234145
// EA  : 0x828BD4C4
// RVA : 0x008BD4C4
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

void __fastcall _unwind_234145(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 688 + 116), tag: a2);
}


// ========================================================================
// __unwind$234146
// EA  : 0x828BD4EC
// RVA : 0x008BD4EC
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

void _unwind_234146()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 688 + 200));
}


// ========================================================================
// __unwind$234663
// EA  : 0x828BFAA0
// RVA : 0x008BFAA0
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

void _unwind_234663()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(v0 + 15904),
    size: 0x20u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
}


// ========================================================================
// __unwind$234664
// EA  : 0x828BFAD8
// RVA : 0x008BFAD8
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

void _unwind_234664()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 15632));
}


// ========================================================================
// __unwind$234669
// EA  : 0x828BFB00
// RVA : 0x008BFB00
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

void _unwind_234669()
{
  bfx::BinaryReplayLogOut *v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: v0 + 560);
}


// ========================================================================
// __unwind$234670
// EA  : 0x828BFB28
// RVA : 0x008BFB28
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

void _unwind_234670()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 + 16000));
}


// ========================================================================
// `dynamic initializer for 'vt_testTranscodePerformance_v''
// EA  : 0x8334BA40
// RVA : 0x0134BA40
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__vt_testTranscodePerformance_v__()
{
  return idCommandLink::idCommandLink(
           this: &vt_testTranscodePerformance_v,
           cmdName: "vt_testTranscodePerformance",
           function: vt_testTranscodePerformance_f,
           description: "test the performance of the transcoder.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'vt_testTranscodeQuality_v''
// EA  : 0x8334BA68
// RVA : 0x0134BA68
// PDB : w:\tech5\engine\renderer\development\virtualtexturesystemtest.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__vt_testTranscodeQuality_v__()
{
  return idCommandLink::idCommandLink(
           this: &vt_testTranscodeQuality_v,
           cmdName: "vt_testTranscodeQuality",
           function: vt_testTranscodeQuality_f,
           description: "test the quality of the transcoder.",
           argCompletion: nullptr);
}

