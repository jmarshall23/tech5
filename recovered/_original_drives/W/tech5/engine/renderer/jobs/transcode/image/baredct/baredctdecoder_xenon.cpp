
// ========================================================================
// ?StoreMono_Xenon@idBareDctDecoder@@AAAXPIBFPIAEH@Z
// EA  : 0x828E52A0
// RVA : 0x008E52A0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder_xenon.cpp
// ========================================================================

void __fastcall idBareDctDecoder::StoreMono_Xenon(
        idBareDctDecoder *this,
        const __int16 *ms,
        unsigned __int8 *mono,
        int stride)
{
  __asm { lvx128    v13, r0, r4 }
  _R10 = 16;
  _R9 = vmxi_half_128;
  _R8 = 48;
  _R7 = 32;
  _R3 = 80;
  __asm { lvx128    v12, r4, r10 }
  _R11 = 64;
  __asm { lvx128    v0, r0, r9 }
  _R10 = 112;
  __asm
  {
    vaddshs   v11, v13, v0
    lvx128    v10, r4, r8
    vaddshs   v9, v12, v0
    lvx128    v8, r4, r7
    vaddshs   v7, v10, v0
  }
  _R9 = 96;
  __asm
  {
    vaddshs   v6, v8, v0
    lvx128    v4, r4, r11
    lvx128    v5, r4, r3
    vaddshs   v2, v4, v0
    vpkshus128 v63, v11, v9
    vaddshs   v3, v5, v0
    lvx128    v1, r4, r10
  }
  _R7 = 4;
  __asm
  {
    vpkshus128 v62, v6, v7
    lvx128    v31, r4, r9
  }
  __asm
  {
    vaddshs   v30, v1, v0
    vspltw128 v61, v63, 0
    vaddshs   v29, v31, v0
    vspltw128 v60, v63, 1
  }
  __asm { vspltw128 v59, v63, 2 }
  _R3 = stride + 4;
  __asm { vspltw128 v57, v63, 3 }
  _R11 = 3 * stride;
  __asm { vpkshus128 v58, v2, v3 }
  _R31 = 2 * stride;
  __asm { vspltw128 v56, v62, 0 }
  __asm { vspltw128 v55, v62, 1 }
  _R4 = 2 * (stride + 2);
  __asm
  {
    vspltw128 v54, v62, 2
    stvewx128 v61, r0, r5
    vspltw128 v52, v62, 3
    stvewx128 v60, r5, r7
    vpkshus128 v53, v29, v30
  }
  _R9 = 4 * stride;
  __asm { vspltw128 v51, v58, 0 }
  _R7 = 3 * stride + 4;
  __asm { stvewx128 v59, r5, r6 }
  __asm
  {
    vspltw128 v50, v58, 1
    stvewx128 v57, r5, r3
  }
  _R10 = 5 * stride;
  __asm
  {
    vspltw128 v49, v58, 2
    stvewx128 v56, r5, r31
  }
  _R3 = 4 * stride + 4;
  __asm
  {
    vspltw128 v48, v58, 3
    stvewx128 v55, r5, r4
  }
  _R8 = 6 * stride;
  __asm
  {
    vspltw128 v47, v53, 0
    stvewx128 v54, r5, r11
  }
  __asm { vspltw128 v46, v53, 1 }
  _R4 = 5 * stride + 4;
  __asm
  {
    stvewx128 v52, r5, r7
    vspltw128 v45, v53, 2
  }
  _R7 = 6 * stride + 4;
  __asm { stvewx128 v51, r5, r9 }
  _R11 = 7 * stride;
  __asm
  {
    stvewx128 v50, r5, r3
    vspltw128 v44, v53, 3
    stvewx128 v49, r5, r10
  }
  _R6 = 7 * stride + 4;
  __asm
  {
    stvewx128 v48, r5, r4
    stvewx128 v47, r5, r8
    stvewx128 v46, r5, r7
    stvewx128 v45, r5, r11
    stvewx128 v44, r5, r6
  }
}


// ========================================================================
// ?StoreGrayScale_Xenon@idBareDctDecoder@@AAAXPBFPAEH@Z
// EA  : 0x828E53F8
// RVA : 0x008E53F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder_xenon.cpp
// ========================================================================

void __fastcall idBareDctDecoder::StoreGrayScale_Xenon(
        idBareDctDecoder *this,
        const __int16 *ms,
        unsigned __int8 *rgb,
        int stride)
{
  __asm { lvx128    v12, r0, r4 }
  _R8 = -64;
  __asm { vspltisb  v0, -1 }
  _R9 = vmxi_byte_perm3;
  _R11 = 16;
  _R3 = 32;
  _R7 = 48;
  _R10 = -48;
  __asm { lvx128    v13, r9, r8 }
  _R8 = -16;
  __asm { lvx128    v11, r4, r11 }
  _R31 = -32;
  __asm
  {
    lvx128    v5, r4, r3
    vaddshs   v10, v12, v13
    vaddshs   v8, v11, v13
    lvx128    v9, r4, r7
    vaddshs   v2, v5, v13
    lvx128    v7, r9, r10
    lvx128    v5, r9, r8
    vaddshs   v3, v9, v13
  }
  _R8 = 112;
  __asm
  {
    lvx128    v6, r9, r31
    lvx128    v4, r0, r9
    vpkshus128 v63, v10, v8
  }
  _R3 = 80;
  _R9 = 64;
  __asm { vpkshus128 v62, v2, v3 }
  _R31 = 96;
  __asm
  {
    lvx128    v30, r4, r8
    vperm128  v61, v95, v0, v7
  }
  __asm
  {
    vperm128  v60, v95, v0, v6
    vperm128  v59, v95, v0, v4
  }
  __asm
  {
    lvx128    v1, r4, r3
    vperm128  v58, v95, v0, v5
    lvx128    v31, r4, r9
  }
  _R10 = &rgb[stride];
  __asm { lvx128    v29, r4, r31 }
  __asm { vperm128  v57, v94, v0, v7 }
  _R8 = 2 * stride;
  __asm
  {
    vaddshs   v28, v1, v13
    vaddshs   v27, v31, v13
  }
  __asm
  {
    vaddshs   v26, v30, v13
    vperm128  v56, v94, v0, v6
    vaddshs   v25, v29, v13
    stvx128   v61, r0, r5
    stvx128   v60, r5, r11
    vperm128  v55, v94, v0, v5
    stvx128   v59, r10, r11
  }
  _R3 = 2 * (stride + 8);
  _R10 = &rgb[3 * stride];
  __asm { stvx128   v58, r5, r6 }
  __asm
  {
    vpkshus128 v63, v27, v28
    vpkshus128 v61, v25, v26
    stvx128   v57, r8, r5
  }
  __asm { vperm128  v54, v94, v0, v4 }
  __asm { stvx128   v56, r3, r5 }
  __asm { vperm128  v53, v95, v0, v7 }
  __asm { vperm128  v52, v95, v0, v6 }
  _R31 = 4 * (stride + 4);
  __asm { vperm128  v51, v95, v0, v5 }
  _R3 = 4 * stride;
  __asm { vperm128  v50, v95, v0, v4 }
  _R9 = &rgb[5 * stride];
  __asm { vperm128  v49, v93, v0, v7 }
  _R8 = &rgb[6 * stride];
  __asm { vperm128  v48, v93, v0, v6 }
  __asm
  {
    vperm128  v47, v93, v0, v5
    stvx128   v55, r0, r10
    vperm128  v46, v93, v0, v4
  }
  _R7 = &rgb[7 * stride];
  __asm
  {
    stvx128   v54, r10, r11
    stvx128   v53, r3, r5
    stvx128   v52, r31, r5
    stvx128   v51, r0, r9
    stvx128   v50, r9, r11
    stvx128   v49, r0, r8
    stvx128   v48, r8, r11
    stvx128   v47, r0, r7
    stvx128   v46, r7, r11
  }
}


// ========================================================================
// ?YCoCgToRGB_Xenon@idBareDctDecoder@@AAAXPIBFPIAEH@Z
// EA  : 0x828E5570
// RVA : 0x008E5570
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder_xenon.cpp
// ========================================================================

void __fastcall idBareDctDecoder::YCoCgToRGB_Xenon(
        idBareDctDecoder *this,
        const __int16 *YCoCg,
        unsigned __int8 *rgb,
        int stride)
{
  const __int16 *v7; // r29
  const __int16 *v8; // r30
  int v9; // r28
  int i; // ctr

  __asm { vspltisb  v9, -1 }
  _R10 = rgb;
  _R9 = vmxi_half_128;
  v7 = YCoCg;
  v8 = YCoCg + 256;
  v9 = 2;
  _R4 = 128;
  __asm { lvx128    v11, r0, r9 }
  _R8 = 16;
  _R31 = 144;
  _R5 = 32;
  _R7 = 48;
  do
  {
    _R11 = v7;
    _R9 = v8;
    for ( i = 4; i != 0; --i )
    {
      __asm
      {
        lvx128    v0, r0, r9
        lvx128    v13, r9, r4
      }
      _R9 += 8;
      __asm
      {
        vmrghh    v8, v0, v0
        lvx128    v6, r11, r4
        vmrglh    v7, v0, v0
        lvx128    v10, r0, r11
        vmrghh    v12, v13, v13
        vaddshs   v10, v10, v11
        vmrglh    v0, v13, v13
        vaddshs   v13, v6, v11
        lvx128    v4, r11, r8
        lvx128    v3, r11, r31
      }
      _R11 += 16;
      __asm
      {
        vsubshs   v6, v8, v12
        vsubshs   v5, v7, v0
        vaddshs   v8, v8, v12
        vaddshs   v7, v7, v0
        vaddshs   v2, v13, v0
        vaddshs   v1, v10, v6
        vaddshs   v31, v10, v12
        vaddshs   v30, v13, v5
        vsubshs   v29, v13, v7
        vpkshus   v20, v2, v2
        vsubshs   v28, v10, v8
        vpkshus   v27, v1, v1
        vaddshs   v13, v4, v11
        vpkshus   v26, v31, v31
        vaddshs   v10, v3, v11
        vpkshus   v22, v30, v30
        vpkshus   v18, v29, v29
        vpkshus   v24, v28, v28
        vaddshs   v25, v13, v6
        vaddshs   v23, v13, v12
        vmrghb    v12, v27, v26
        vsubshs   v21, v13, v8
        vmrghb    v13, v18, v9
        vaddshs   v19, v10, v0
        vmrghb    v6, v24, v9
        vaddshs   v17, v10, v5
        vmrghb    v8, v22, v20
        vsubshs   v16, v10, v7
        vpkshus   v0, v23, v23
        vpkshus   v14, v25, v25
        vpkshus   v10, v21, v21
        vpkshus   v7, v17, v17
        vpkshus   v5, v19, v19
        vpkshus   v4, v16, v16
        vmrghh    v15, v12, v6
        vmrglh    v3, v12, v6
        vmrghh    v2, v8, v13
        vmrglh    v1, v8, v13
        vmrghb    v6, v14, v0
        vmrghb    v12, v10, v9
        vmrghb    v0, v7, v5
        vmrghb    v13, v4, v9
        stvx128   v15, r0, r10
        stvx128   v3, r10, r8
        vmrghh    v31, v6, v12
        stvx128   v2, r10, r5
        vmrglh    v30, v6, v12
        stvx128   v1, r10, r7
        vmrghh    v29, v0, v13
      }
      _R10 = &_R10[stride];
      __asm
      {
        vmrglh    v28, v0, v13
        stvx128   v31, r0, r10
        stvx128   v30, r10, r8
        stvx128   v29, r10, r5
        stvx128   v28, r10, r7
      }
      _R10 = &_R10[stride];
    }
    --v9;
    v8 += 32;
    v7 += 128;
  }
  while ( v9 != 0 );
}


// ========================================================================
// ?StoreYCoCg420_Xenon@idBareDctDecoder@@AAAXPIBFPIAEH@Z
// EA  : 0x828E56F0
// RVA : 0x008E56F0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder_xenon.cpp
// ========================================================================

void __fastcall idBareDctDecoder::StoreYCoCg420_Xenon(
        idBareDctDecoder *this,
        const __int16 *YCoCg,
        unsigned __int8 *CoCg_Y,
        int stride)
{
  const __int16 *v7; // r29
  const __int16 *v8; // r30
  int v9; // r28
  int i; // ctr

  __asm { vspltisb  v11, 0 }
  _R10 = CoCg_Y;
  _R9 = vmxi_half_128;
  v7 = YCoCg;
  v8 = YCoCg + 256;
  v9 = 2;
  _R4 = 128;
  __asm { lvx128    v12, r0, r9 }
  _R8 = 16;
  _R31 = 144;
  _R5 = 32;
  _R7 = 48;
  do
  {
    _R11 = v7;
    _R9 = v8;
    for ( i = 4; i != 0; --i )
    {
      __asm
      {
        lvx128    v0, r0, r9
        lvx128    v13, r9, r4
      }
      _R9 += 8;
      __asm
      {
        lvx128    v10, r0, r11
        vmrghh    v9, v0, v0
        lvx128    v8, r11, r4
        vmrghh    v7, v13, v13
        vmrglh    v6, v0, v0
        vaddshs   v5, v10, v12
        vmrglh    v4, v13, v13
        vaddshs   v3, v8, v12
        lvx128    v2, r11, r8
        vpkshus   v31, v9, v9
        lvx128    v1, r11, r31
        vpkshus   v30, v7, v7
        vpkshus   v28, v6, v6
        vaddshs   v29, v2, v12
        vpkshus   v26, v4, v4
        vaddshs   v27, v1, v12
        vpkshus   v25, v5, v5
      }
      _R11 += 16;
      __asm
      {
        vpkshus   v24, v3, v3
        vmrghb    v0, v31, v30
        vmrghb    v13, v28, v26
        vmrghb    v10, v11, v25
        vmrghb    v9, v11, v24
        vpkshus   v23, v29, v29
        vpkshus   v22, v27, v27
        vmrghh    v21, v0, v10
        vmrglh    v20, v0, v10
        vmrghh    v19, v13, v9
        vmrglh    v18, v13, v9
        vmrghb    v8, v11, v23
        vmrghb    v7, v11, v22
        stvx128   v21, r0, r10
        vmrghh    v17, v0, v8
        stvx128   v20, r10, r8
        vmrglh    v16, v0, v8
        stvx128   v19, r10, r5
        vmrghh    v15, v13, v7
        stvx128   v18, r10, r7
        vmrglh    v14, v13, v7
      }
      _R10 = &_R10[stride];
      __asm
      {
        stvx128   v17, r0, r10
        stvx128   v16, r10, r8
        stvx128   v15, r10, r5
        stvx128   v14, r10, r7
      }
      _R10 = &_R10[stride];
    }
    --v9;
    v8 += 32;
    v7 += 128;
  }
  while ( v9 != 0 );
}


// ========================================================================
// ?StoreYCoCg444_Xenon@idBareDctDecoder@@AAAXPIBFPIAEH@Z
// EA  : 0x828E5818
// RVA : 0x008E5818
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder_xenon.cpp
// ========================================================================

void __fastcall idBareDctDecoder::StoreYCoCg444_Xenon(
        idBareDctDecoder *this,
        const __int16 *YCoCg,
        unsigned __int8 *CoCg_Y,
        int stride)
{
  int v8; // r21
  int v22; // ctr

  __asm { vspltisb  v13, 0 }
  _R10 = CoCg_Y;
  _R9 = vmxi_half_128;
  v8 = 2;
  _R24 = 128;
  __asm { lvx128    v0, r0, r9 }
  _R25 = 144;
  _R8 = 16;
  _R26 = 1152;
  _R27 = 1024;
  _R28 = 1168;
  _R29 = 1040;
  _R5 = 32;
  _R7 = 48;
  do
  {
    _R11 = YCoCg;
    _R4 = 640;
    _R3 = 512;
    _R31 = 656;
    v22 = 4;
    _R30 = 528;
    do
    {
      __asm { lvx128    v12, r0, r11 }
      _R9 = &_R10[stride];
      __asm
      {
        lvx128    v11, r11, r24
        vaddshs   v10, v12, v0
        lvx128    v8, r11, r25
        vaddshs   v9, v11, v0
        lvx128    v7, r11, r8
        vaddshs   v6, v8, v0
        lvx128    v63, r11, r4
        vaddshs   v5, v7, v0
        lvx128    v62, r11, r3
        lvx128    v61, r11, r26
        vpkshus   v10, v10, v9
        lvx128    v60, r11, r27
        vpkshus128 v12, v94, v63
        lvx128    v59, r11, r31
        vpkshus   v7, v5, v6
        lvx128    v58, r11, r30
        vpkshus128 v11, v92, v61
        lvx128    v57, r11, r28
        lvx128    v56, r11, r29
        vpkshus128 v9, v90, v59
        vmrghb    v4, v13, v7
      }
      _R11 += 16;
      __asm
      {
        vpkshus128 v8, v88, v57
        vmrghb    v6, v12, v11
        vmrglb    v12, v12, v11
        vmrghb    v11, v13, v10
        vmrghb    v5, v9, v8
        vmrglb    v10, v13, v10
        vmrglb    v9, v9, v8
        vmrglb    v8, v13, v7
        vmrghh    v3, v6, v11
        vmrglh    v2, v6, v11
        vmrghh    v1, v12, v10
        vmrglh    v31, v12, v10
        vmrghh    v30, v5, v4
        vmrglh    v29, v5, v4
        vmrghh    v28, v9, v8
        vmrglh    v27, v9, v8
        stvx128   v3, r0, r10
        stvx128   v2, r10, r8
        stvx128   v1, r10, r5
        stvx128   v31, r10, r7
        stvx128   v30, r10, r6
      }
      _R10 += 2 * stride;
      __asm
      {
        stvx128   v29, r9, r8
        stvx128   v28, r9, r5
        stvx128   v27, r9, r7
      }
      --v22;
    }
    while ( v22 != 0 );
    --v8;
    YCoCg += 128;
  }
  while ( v8 != 0 );
}


// ========================================================================
// ?StoreNormalMap_Xenon@idBareDctDecoder@@AAAXPIBFPIAEH@Z
// EA  : 0x828E5958
// RVA : 0x008E5958
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder_xenon.cpp
// ========================================================================

void __fastcall idBareDctDecoder::StoreNormalMap_Xenon(
        idBareDctDecoder *this,
        const __int16 *ms,
        unsigned __int8 *normalMap,
        int stride)
{
  __asm { lvx128    v12, r0, r4 }
  _R11 = 16;
  __asm { vspltisb  v13, -1 }
  _R8 = vmxi_half_128;
  _R9 = 144;
  _R7 = 128;
  _R3 = 48;
  _R10 = 32;
  __asm
  {
    lvx128    v11, r4, r11
    lvx128    v0, r0, r8
  }
  _R8 = 160;
  __asm
  {
    lvx128    v10, r4, r9
    vaddshs   v7, v11, v0
    lvx128    v9, r4, r7
    vaddshs   v6, v10, v0
    vaddshs   v5, v9, v0
  }
  _R9 = 176;
  __asm
  {
    vaddshs   v8, v12, v0
    lvx128    v3, r4, r10
    lvx128    v4, r4, r3
  }
  _R7 = 80;
  _R10 = 240;
  __asm { lvx128    v1, r4, r8 }
  _R31 = 64;
  __asm { vpkshus   v11, v5, v6 }
  _R30 = 208;
  __asm { vpkshus   v12, v8, v7 }
  _R29 = 192;
  __asm { lvx128    v2, r4, r9 }
  _R3 = 112;
  __asm { vaddshs   v31, v4, v0 }
  _R28 = 96;
  __asm { vaddshs   v30, v3, v0 }
  _R27 = 224;
  __asm
  {
    vaddshs   v28, v2, v0
    vaddshs   v26, v1, v0
    lvx128    v29, r4, r7
    lvx128    v17, r4, r10
    vmrghb    v7, v12, v11
    lvx128    v27, r4, r31
    vaddshs   v24, v29, v0
    lvx128    v25, r4, r30
    vaddshs   v22, v27, v0
    lvx128    v23, r4, r29
    vaddshs   v20, v25, v0
    lvx128    v21, r4, r3
    vaddshs   v18, v23, v0
    lvx128    v19, r4, r28
    vaddshs   v14, v17, v0
    lvx128    v15, r4, r27
    vaddshs   v16, v21, v0
    vaddshs   v5, v15, v0
    vpkshus   v10, v30, v31
    vaddshs   v4, v19, v0
    vpkshus   v8, v26, v28
    vmrghb    v3, v13, v7
  }
  __asm { vmrglb    v2, v13, v7 }
  _R9 = &normalMap[stride];
  __asm { vmrglb    v12, v12, v11 }
  __asm { vpkshus   v11, v5, v14 }
  __asm { vpkshus   v9, v22, v24 }
  __asm { vpkshus   v6, v18, v20 }
  __asm
  {
    vpkshus   v0, v4, v16
    vmrghb    v7, v10, v8
    stvx128   v3, r0, r5
    vmrglb    v10, v10, v8
    stvx128   v2, r5, r11
    vmrghb    v5, v9, v6
    vmrghb    v8, v0, v11
    vmrghb    v1, v13, v12
    vmrglb    v9, v9, v6
    vmrglb    v0, v0, v11
    vmrglb    v31, v13, v12
    vmrghb    v30, v13, v7
    vmrglb    v29, v13, v7
    vmrghb    v28, v13, v10
  }
  __asm { vmrglb    v27, v13, v10 }
  _R3 = 2 * stride;
  _R31 = 2 * (stride + 8);
  __asm { vmrghb    v26, v13, v5 }
  _R10 = &normalMap[3 * stride];
  __asm { vmrglb    v25, v13, v5 }
  __asm { stvx128   v1, r5, r6 }
  _R4 = 5 * stride;
  __asm { vmrghb    v24, v13, v9 }
  __asm { vmrglb    v23, v13, v9 }
  __asm { stvx128   v31, r9, r11 }
  _R7 = 7 * stride;
  __asm
  {
    vmrghb    v22, v13, v8
    vmrglb    v21, v13, v8
  }
  _R30 = 4 * (stride + 4);
  __asm
  {
    stvx128   v30, r3, r5
    stvx128   v29, r31, r5
    vmrghb    v20, v13, v0
    vmrglb    v19, v13, v0
  }
  _R9 = &normalMap[5 * stride];
  __asm { stvx128   v28, r0, r10 }
  _R8 = &normalMap[6 * stride];
  __asm { stvx128   v27, r10, r11 }
  _R10 = &normalMap[7 * stride];
  _R6 = 4 * stride;
  __asm
  {
    stvx128   v26, r6, r5
    stvx128   v25, r30, r5
    stvx128   v24, r4, r5
    stvx128   v23, r9, r11
    stvx128   v22, r0, r8
    stvx128   v21, r8, r11
    stvx128   v20, r7, r5
    stvx128   v19, r10, r11
  }
}


// ========================================================================
// ?HuffmanDecode_Xenon@idBareDctDecoder@@AAAXPIAFABVidBareDCTHuffmanTable@@1PIAH@Z
// EA  : 0x828E5B40
// RVA : 0x008E5B40
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder_xenon.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idBareDctDecoder::HuffmanDecode_Xenon(idBareDctDecoder *this, unsigned __int64 dctbl, __int64 lastDC)
{
  signed __int64 bitCnt; // r11 OVERLAPPED
  unsigned __int8 *v8; // r9 OVERLAPPED
  int v14; // r31
  int v15; // r29
  BOOL v16; // r28
  unsigned int v17; // r8
  int v18; // r28
  const unsigned __int8 *v19; // r9
  __int64 v20; // r31
  unsigned int v21; // r8
  int v22; // r28
  const unsigned __int8 *v23; // r9
  unsigned int v24; // r8
  int v25; // r8
  int v26; // r9
  int v27; // r9
  int v28; // r31
  const unsigned __int8 *data; // r9
  BOOL v30; // r29
  int v31; // r28
  unsigned int v32; // r8
  int v33; // r29
  const unsigned __int8 *v34; // r9
  __int64 v35; // r31
  unsigned int v36; // r8
  int v37; // r29
  const unsigned __int8 *v38; // r9
  int v39; // r8
  int v40; // r8
  int v41; // r9
  unsigned __int64 v42; // r9
  int v43; // r29
  bool (__fastcall **v44)(idAIEvent *__hidden, const struct idEntity *, int); // r9 OVERLAPPED
  unsigned __int64 v45; // r29
  signed __int64 v46; // r30
  signed __int64 v47; // r30
  const unsigned __int8 *v48; // r8
  BOOL v49; // r27
  unsigned int v50; // r9
  const unsigned __int8 *v51; // r31
  int v52; // r9
  int v53; // r8
  int v54; // r27
  unsigned int v55; // r31
  const unsigned __int8 *v56; // r31
  int v57; // r27
  __int128 v58; // r9
  unsigned int v59; // r25
  BOOL v60; // r26
  int v61; // r9
  unsigned int v62; // r31
  int v63; // r30
  int v64; // r9 OVERLAPPED
  __int128 v65; // r8 OVERLAPPED
  const unsigned __int8 *v66; // r9
  BOOL v67; // r5
  int v68; // r29
  unsigned int v69; // r8
  const unsigned __int8 *v70; // r8
  int v71; // r5
  const unsigned __int8 *v72; // r9
  BOOL v73; // r27
  unsigned int v74; // r8
  int v75; // r27
  int v76; // r29
  int v77; // r9
  int v78; // r9
  int v79; // r9 OVERLAPPED
  int v80; // r9
  unsigned __int64 v81; // r5
  const unsigned __int8 *v82; // r8
  BOOL v83; // r29
  unsigned int v84; // r9
  const unsigned __int8 *v85; // r27
  int v86; // r29
  BOOL v87; // r25
  const unsigned __int8 *v88; // r7
  int v89; // r27
  BOOL v90; // r26
  int v91; // r29
  int v92; // r9
  __int128 v93; // r9
  int v94; // r9
  __int64 v95; // r26
  unsigned __int64 v96; // r8
  unsigned int v97; // r31
  signed __int64 v98; // r29
  const unsigned __int8 *v99; // r9
  BOOL v100; // r26
  unsigned int v101; // r8
  const unsigned __int8 *v102; // r27
  int v103; // r26
  BOOL v104; // r24
  int v105; // r25
  const unsigned __int8 *v106; // r8
  int v107; // r25
  int v108; // r24
  const unsigned __int8 *v109; // r9
  int v110; // r9
  int v111; // r9

  _R9 = this->data;
  __asm
  {
    dcbt      0, r9
    vspltisb  v0, 0
  }
  _R8 = 16;
  bitCnt = this->bitCnt;
  _R31 = 32;
  *(signed __int64 *)((char *)&bitCnt + 4) = this->bitBuff;
  _R30 = 48;
  _R29 = 64;
  _R28 = 80;
  _R27 = 96;
  _R26 = 112;
  __asm { stvx128   v0, r0, r4 }
  __asm
  {
    stvx128   v0, r4, r8
    stvx128   v0, r4, r31
    stvx128   v0, r4, r30
    stvx128   v0, r4, r29
    stvx128   v0, r4, r28
    stvx128   v0, r4, r27
    stvx128   v0, r4, r26
  }
  if ( (unsigned int)bitCnt < 8 )
  {
    v14 = HIDWORD(bitCnt) << 8;
    LODWORD(bitCnt) = bitCnt + 48;
    HIDWORD(bitCnt) = this->dataBytes - 2;
    this->dataBytes = HIDWORD(bitCnt);
    v15 = *v8;
    v16 = bitCnt >= 0;
    v17 = ((unsigned int)-HIDWORD(bitCnt) >> 30) & 2;
    HIDWORD(bitCnt) -= 2;
    v18 = v8[v16];
    v19 = &v8[v17];
    this->data = v19;
    this->dataBytes = HIDWORD(bitCnt);
    LODWORD(v20) = v14 | v15;
    HIDWORD(v20) = v19[bitCnt >= 0];
    v21 = ((unsigned int)-HIDWORD(bitCnt) >> 30) & 2;
    HIDWORD(bitCnt) -= 2;
    v20 <<= 8;
    LODWORD(v20) = v18 | v20;
    v22 = *v19;
    v23 = &v19[v21];
    this->data = v23;
    this->dataBytes = HIDWORD(bitCnt);
    v20 <<= 8;
    v24 = ((unsigned int)v20 | v22) << 8;
    LODWORD(v20) = v23[bitCnt >= 0];
    v25 = HIDWORD(v20) | v24;
    HIDWORD(v20) = *v23;
    this->data = &v23[((unsigned int)-HIDWORD(bitCnt) >> 30) & 2];
    HIDWORD(bitCnt) = v20 | (((v25 << 8) | HIDWORD(v20)) << 8);
  }
  v26 = bitCnt - 8;
  *(__int64 *)((char *)&lastDC - 4) = *(unsigned __int64 *)((char *)&bitCnt + 4) >> v26;
  v27 = (unsigned __int8)(*(unsigned __int64 *)((char *)&bitCnt + 4) >> v26) + (_DWORD)dctbl;
  if ( *(_BYTE *)(v27 + 1280) != 0 )
  {
    LODWORD(dctbl) = *(unsigned __int8 *)(v27 + 1536);
    LODWORD(bitCnt) = bitCnt - *(unsigned __int8 *)(v27 + 1280);
  }
  else
  {
    if ( (unsigned int)bitCnt < 0x10 )
    {
      v28 = HIDWORD(bitCnt) << 8;
      data = this->data;
      LODWORD(bitCnt) = bitCnt + 48;
      HIDWORD(bitCnt) = this->dataBytes - 2;
      this->dataBytes = HIDWORD(bitCnt);
      v30 = bitCnt >= 0;
      v31 = *data;
      v32 = ((unsigned int)-HIDWORD(bitCnt) >> 30) & 2;
      HIDWORD(bitCnt) -= 2;
      v33 = data[v30];
      v34 = &data[v32];
      this->data = v34;
      this->dataBytes = HIDWORD(bitCnt);
      LODWORD(v35) = v28 | v31;
      HIDWORD(v35) = v34[bitCnt >= 0];
      v36 = ((unsigned int)-HIDWORD(bitCnt) >> 30) & 2;
      HIDWORD(bitCnt) -= 2;
      v35 <<= 8;
      LODWORD(v35) = v33 | v35;
      v37 = *v34;
      v38 = &v34[v36];
      this->data = v38;
      this->dataBytes = HIDWORD(bitCnt);
      v35 <<= 8;
      v39 = v35 | v37;
      LODWORD(v35) = v38[bitCnt >= 0];
      *(__int64 *)((char *)&lastDC - 4) <<= 8;
      v40 = HIDWORD(v35) | v39;
      HIDWORD(v35) = *v38;
      this->data = &v38[((unsigned int)-HIDWORD(bitCnt) >> 30) & 2];
      HIDWORD(bitCnt) = v35 | (((v40 << 8) | HIDWORD(v35)) << 8);
    }
    v41 = bitCnt - 16;
    v42 = *(unsigned __int64 *)((char *)&bitCnt + 4) >> v41;
    v43 = (unsigned __int16)v42;
    LODWORD(v42) = ((unsigned __int16)v42 - HIDWORD(v42) >= 0)
                 + ((unsigned __int16)v42 - *(_DWORD *)(dctbl + 2104) >= 0)
                 + ((unsigned __int16)v42 - *(_DWORD *)(dctbl + 2100) >= 0)
                 + ((unsigned __int16)v42 - *(_DWORD *)(dctbl + 2096) >= 0)
                 + ((unsigned __int16)v42 - *(_DWORD *)(dctbl + 2092) >= 0)
                 + (v43 - *(_DWORD *)(dctbl + 2088) >= 0)
                 + (v43 - *(_DWORD *)(dctbl + 2084) >= 0)
                 + 9;
    LODWORD(bitCnt) = bitCnt - v42;
    LODWORD(dctbl) = *(unsigned __int8 *)((unsigned __int8)((v43 >> (16 - v42))
                                                          - *(_DWORD *)(4 * (v42 + 528) + dctbl)
                                                          + *(_DWORD *)(4 * (v42 + 563) + dctbl))
                                        + (_DWORD)dctbl
                                        + 1792);
  }
  v44 = &off_82230000;
  HIDWORD(v45) = dct_natural_order_0;
  if ( (_DWORD)dctbl != 0 )
  {
    HIDWORD(v46) = dctbl;
    if ( (unsigned int)bitCnt < (unsigned int)dctbl )
    {
      v47 = *(signed __int64 *)((char *)&bitCnt + 4) << 8;
      v48 = this->data;
      LODWORD(bitCnt) = bitCnt + 48;
      HIDWORD(bitCnt) = this->dataBytes - 2;
      this->dataBytes = HIDWORD(bitCnt);
      v49 = bitCnt >= 0;
      v50 = ((unsigned int)-HIDWORD(bitCnt) >> 30) & 2;
      HIDWORD(bitCnt) -= 2;
      v51 = &v48[v50];
      v52 = HIDWORD(bitCnt) - 2;
      LODWORD(v47) = v47 | *v48;
      v53 = v48[v49];
      this->data = v51;
      this->dataBytes = HIDWORD(bitCnt);
      v54 = bitCnt >= 0;
      v46 = v47 << 8;
      v55 = ((unsigned int)-HIDWORD(bitCnt) >> 30) & 2;
      HIDWORD(bitCnt) = this->data;
      v56 = (const unsigned __int8 *)(v55 + HIDWORD(bitCnt));
      v57 = *(unsigned __int8 *)(v54 + HIDWORD(bitCnt));
      DWORD2(v58) = ((v53 | (unsigned int)v46) << 8) | (unsigned __int8)*(_BYTE *)HIDWORD(bitCnt);
      this->dataBytes = v52;
      DWORD2(v58) <<= 8;
      this->data = v56;
      v59 = -v52;
      v60 = v52 >= 0;
      LODWORD(v58) = v57 | DWORD2(v58);
      *(_QWORD *)((char *)&v58 + 4) = (_QWORD)v58 << 8;
      DWORD2(v58) |= *v56;
      LODWORD(v58) = v56[v60];
      *(__int64 *)((char *)&lastDC - 4) = *(_QWORD *)((char *)&v58 + 4) << 8;
      this->data = &v56[(v59 >> 30) & 2];
      HIDWORD(bitCnt) = v58 | DWORD2(v58);
    }
    v61 = 4 * dctbl;
    LODWORD(bitCnt) = bitCnt - HIDWORD(v46);
    LODWORD(dctbl) = (((int)(((*(unsigned __int64 *)((char *)&bitCnt + 4) >> bitCnt) & maskTable[(_DWORD)dctbl])
                           - (shiftTable[(_DWORD)dctbl] >> 1)) >> 31)
                    & (1 - shiftTable[(_DWORD)dctbl]))
                   + ((*(unsigned __int64 *)((char *)&bitCnt + 4) >> bitCnt) & maskTable[(_DWORD)dctbl]);
  }
  v62 = 1;
  v63 = HIDWORD(lastDC) + 1280;
  v64 = *(_DWORD *)lastDC + dctbl;
  *(_DWORD *)lastDC = v64;
  *(_WORD *)HIDWORD(dctbl) = v64;
  do
  {
    if ( (unsigned int)bitCnt < 8 )
    {
      *(_QWORD *)((char *)&v65 + 4) = *(signed __int64 *)((char *)&bitCnt + 4) << 8;
      v66 = this->data;
      LODWORD(bitCnt) = bitCnt + 48;
      HIDWORD(bitCnt) = this->dataBytes - 2;
      this->dataBytes = HIDWORD(bitCnt);
      v67 = bitCnt >= 0;
      v68 = *v66;
      v69 = ((unsigned int)-HIDWORD(bitCnt) >> 30) & 2;
      HIDWORD(bitCnt) -= 2;
      v70 = &v66[v69];
      v71 = v66[v67];
      this->data = v70;
      DWORD2(v65) |= v68;
      v72 = v70;
      this->dataBytes = HIDWORD(bitCnt);
      v73 = bitCnt >= 0;
      *(_QWORD *)((char *)&v65 + 4) <<= 8;
      v74 = ((unsigned int)-HIDWORD(bitCnt) >> 30) & 2;
      HIDWORD(bitCnt) -= 2;
      HIDWORD(v65) = v71 | DWORD2(v65);
      DWORD2(v65) = v72[v73];
      v75 = *v72;
      this->dataBytes = HIDWORD(bitCnt);
      this->data = &v72[v74];
      v76 = bitCnt >= 0;
      HIDWORD(bitCnt) = this->data;
      LODWORD(v65) = (HIDWORD(v65) << 8) | v75;
      dctbl = (_QWORD)v65 << 8;
      DWORD2(v65) |= (_DWORD)v65 << 8;
      LODWORD(v65) = *(unsigned __int8 *)(v76 + HIDWORD(bitCnt));
      LODWORD(dctbl) = (unsigned __int8)*(_BYTE *)HIDWORD(bitCnt);
      this->data = (const unsigned __int8 *)(*(_QWORD *)((char *)&v65 + 4) >> 24);
      v77 = (DWORD2(v65) << 8) | dctbl;
      lastDC = *(_QWORD *)((char *)&v65 - 4) << 8;
      HIDWORD(bitCnt) = v65 | (v77 << 8);
    }
    v78 = bitCnt - 8;
    v79 = (unsigned __int8)(*(unsigned __int64 *)((char *)&bitCnt + 4) >> v78);
    if ( *(_BYTE *)(v63 + v79) != 0 )
    {
      LODWORD(bitCnt) = bitCnt - *(unsigned __int8 *)(v63 + v79);
      v80 = *(unsigned __int8 *)(v79 + HIDWORD(lastDC) + 1536);
    }
    else
    {
      if ( (unsigned int)bitCnt < 0x10 )
      {
        v81 = *(signed __int64 *)((char *)&bitCnt + 4) << 8;
        v82 = this->data;
        LODWORD(bitCnt) = bitCnt + 48;
        HIDWORD(bitCnt) = this->dataBytes - 2;
        this->dataBytes = HIDWORD(bitCnt);
        v83 = bitCnt >= 0;
        v84 = ((unsigned int)-HIDWORD(bitCnt) >> 30) & 2;
        HIDWORD(bitCnt) -= 2;
        v85 = &v82[v84];
        LODWORD(v81) = v81 | *v82;
        v86 = v82[v83];
        this->data = &v82[v84];
        this->dataBytes = HIDWORD(bitCnt);
        v87 = bitCnt >= 0;
        v88 = &v82[v84 + (((unsigned int)-HIDWORD(bitCnt) >> 30) & 2)];
        *(signed __int64 *)((char *)&bitCnt + 4) = v81 << 8;
        v90 = ((v81 >> 24) & 0x80000000) == 0LL;
        LODWORD(v81) = v86 | ((_DWORD)v81 << 8);
        v91 = *v85;
        v89 = v85[v87];
        this->dataBytes = v92;
        this->data = v88;
        DWORD2(v93) = ((_DWORD)v81 << 8) | v91;
        LODWORD(v81) = v88[v90];
        DWORD1(v93) = *v88;
        this->data = (const unsigned __int8 *)(*(_QWORD *)((char *)&v93 + 4) >> 24);
        LODWORD(v93) = v89 | (DWORD2(v93) << 8);
        HIDWORD(bitCnt) = v81 | ((((_DWORD)v93 << 8) | (unsigned int)((unsigned __int64)v93 >> 24)) << 8);
      }
      v94 = bitCnt - 16;
      dctbl = *(unsigned __int64 *)((char *)&bitCnt + 4) >> v94;
      LODWORD(dctbl) = (unsigned __int16)(*(unsigned __int64 *)((char *)&bitCnt + 4) >> v94);
      v95 = *(_QWORD *)(HIDWORD(lastDC) + 2084);
      LODWORD(bitCnt) = bitCnt
                      - (((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2108) >= 0)
                       + ((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2104) >= 0)
                       + ((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2100) >= 0)
                       + ((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2096) >= 0)
                       + ((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2092) >= 0)
                       + ((int)dctbl - (int)v95 >= 0)
                       + ((int)dctbl - HIDWORD(v95) >= 0)
                       + 9);
      v80 = *(unsigned __int8 *)((unsigned __int8)(((int)dctbl >> (16
                                                                 - (((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2108) >= 0)
                                                                  + ((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2104) >= 0)
                                                                  + ((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2100) >= 0)
                                                                  + ((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2096) >= 0)
                                                                  + ((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2092) >= 0)
                                                                  + ((int)dctbl - (int)v95 >= 0)
                                                                  + ((int)dctbl - HIDWORD(v95) >= 0)
                                                                  + 9)))
                                                 - *(_DWORD *)(4
                                                             * (((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2108) >= 0)
                                                              + ((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2104) >= 0)
                                                              + ((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2100) >= 0)
                                                              + ((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2096) >= 0)
                                                              + ((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2092) >= 0)
                                                              + ((int)dctbl - (int)v95 >= 0)
                                                              + ((int)dctbl - HIDWORD(v95) >= 0)
                                                              + 537)
                                                             + HIDWORD(lastDC))
                                                 + *(_DWORD *)(4
                                                             * (((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2108) >= 0)
                                                              + ((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2104) >= 0)
                                                              + ((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2100) >= 0)
                                                              + ((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2096) >= 0)
                                                              + ((int)dctbl - *(_DWORD *)(HIDWORD(lastDC) + 2092) >= 0)
                                                              + ((int)dctbl - (int)v95 >= 0)
                                                              + ((int)dctbl - HIDWORD(v95) >= 0)
                                                              + 572)
                                                             + HIDWORD(lastDC)))
                               + HIDWORD(lastDC)
                               + 1792);
    }
    HIDWORD(v96) = v80 & 0xF;
    v64 = v80 >> 4;
    v97 = v64 + v62;
    if ( HIDWORD(v96) != 0 )
    {
      LODWORD(dctbl) = HIDWORD(v96);
      if ( (unsigned int)bitCnt < HIDWORD(v96) )
      {
        v98 = *(signed __int64 *)((char *)&bitCnt + 4) << 8;
        v99 = this->data;
        LODWORD(bitCnt) = bitCnt + 48;
        HIDWORD(bitCnt) = this->dataBytes - 2;
        this->dataBytes = HIDWORD(bitCnt);
        v100 = bitCnt >= 0;
        v101 = ((unsigned int)-HIDWORD(bitCnt) >> 30) & 2;
        HIDWORD(bitCnt) -= 2;
        v103 = v99[v100];
        v104 = bitCnt >= 0;
        v105 = *v99;
        v102 = &v99[v101];
        this->data = &v99[v101];
        this->dataBytes = HIDWORD(bitCnt);
        LODWORD(v98) = v98 | v105;
        v106 = &v99[v101 + (((unsigned int)-HIDWORD(bitCnt) >> 30) & 2)];
        v98 <<= 8;
        HIDWORD(bitCnt) -= 2;
        LODWORD(v98) = v103 | v98;
        v107 = v102[v104];
        v45 = v98 << 8;
        v108 = *v102;
        this->data = v106;
        this->dataBytes = HIDWORD(bitCnt);
        v96 = (unsigned __int64)(v107 | (((unsigned int)v45 | v108) << 8)) << 8;
        v109 = this->data;
        LODWORD(v96) = v96 | *v109;
        HIDWORD(bitCnt) = v109[bitCnt >= 0];
        this->data = v109;
        HIDWORD(bitCnt) |= (_DWORD)v96 << 8;
      }
      v110 = 4 * HIDWORD(v96);
      LODWORD(bitCnt) = bitCnt - dctbl;
      LODWORD(v96) = HIDWORD(v45) + 472;
      HIDWORD(v96) = *(_DWORD *)(4 * HIDWORD(v96) + HIDWORD(v45) + 400);
      v45 = *(unsigned __int64 *)((char *)&bitCnt + 4) >> bitCnt;
      v111 = (*(unsigned __int64 *)((char *)&bitCnt + 4) >> bitCnt) & *(_DWORD *)(v110 + v96);
      v64 = (((v111 - (SHIDWORD(v96) >> 1)) >> 31) & (1 - HIDWORD(v96))) + v111;
      *(_WORD *)(2 * *(_DWORD *)(4 * v97 + HIDWORD(v45)) + HIDWORD(dctbl)) = v64;
    }
    else if ( v64 != 15 )
    {
      break;
    }
    v62 = v97 + 1;
  }
  while ( v62 < 0x40 );
  this->bitBuff = *(signed __int64 *)((char *)&bitCnt + 4);
  this->bitCnt = bitCnt;
}


// ========================================================================
// ?DecompressOneTileGrayScale_Xenon@idBareDctDecoder@@AAAXPIAEH@Z
// EA  : 0x828E6320
// RVA : 0x008E6320
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder_xenon.cpp
// ========================================================================

void __fastcall idBareDctDecoder::DecompressOneTileGrayScale_Xenon(
        idBareDctDecoder *this,
        unsigned __int8 *rgb,
        int stride,
        int a4,
        __int64 a5)
{
  int *p_dcY; // r29
  __int64 v9; // r8
  idBareDctDecoder *v10; // r3
  __int64 v11; // r8
  idBareDctDecoder *v12; // r3
  __int64 v13; // r8
  idBareDctDecoder *v14; // r3
  int v15; // r3
  const unsigned __int16 *v16; // r29
  int v17; // r6
  int v18; // r6
  int v19; // r6
  __int16 v20[64]; // [sp+50h] [-230h] BYREF
  __int16 v21[64]; // [sp+D0h] [-1B0h] BYREF
  __int16 v22[64]; // [sp+150h] [-130h] BYREF
  __int16 v23[88]; // [sp+1D0h] [-B0h] BYREF

  p_dcY = &this->dcY;
  HIDWORD(a5) = &this->dcY;
  idBareDctDecoder::HuffmanDecode_Xenon(this, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: a5);
  HIDWORD(v9) = p_dcY;
  idBareDctDecoder::HuffmanDecode_Xenon(this: v10, dctbl: *(_QWORD *)&v10->pHuffTableYDC, lastDC: v9);
  HIDWORD(v11) = p_dcY;
  idBareDctDecoder::HuffmanDecode_Xenon(this: v12, dctbl: *(_QWORD *)&v12->pHuffTableYDC, lastDC: v11);
  HIDWORD(v13) = p_dcY;
  idBareDctDecoder::HuffmanDecode_Xenon(this: v14, dctbl: *(_QWORD *)&v14->pHuffTableYDC, lastDC: v13);
  v16 = (const unsigned __int16 *)(v15 + 16);
  IDCT_AP922_float_Xenon(coeff: v20, quant: (const unsigned __int16 *)(v15 + 16), dest: v20);
  IDCT_AP922_float_Xenon(coeff: v21, quant: v16, dest: v21);
  IDCT_AP922_float_Xenon(coeff: v22, quant: v16, dest: v22);
  IDCT_AP922_float_Xenon(coeff: v23, quant: v16, dest: v23);
  idBareDctDecoder::StoreGrayScale_Xenon(this, ms: v20, rgb, stride);
  idBareDctDecoder::StoreGrayScale_Xenon(this, ms: v21, rgb: rgb + 32, stride: v17);
  idBareDctDecoder::StoreGrayScale_Xenon(this, ms: v22, rgb: &rgb[8 * stride], stride: v18);
  idBareDctDecoder::StoreGrayScale_Xenon(this, ms: v23, rgb: &rgb[8 * stride + 32], stride: v19);
}


// ========================================================================
// ?DecompressOneTileRGB_Xenon@idBareDctDecoder@@AAAXPIAEH@Z
// EA  : 0x828E6428
// RVA : 0x008E6428
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder_xenon.cpp
// ========================================================================

void __fastcall idBareDctDecoder::DecompressOneTileRGB_Xenon(
        idBareDctDecoder *this,
        unsigned __int8 *rgb,
        int stride,
        int a4,
        __int64 a5)
{
  int *p_dcY; // r30
  __int64 v9; // r8
  idBareDctDecoder *v10; // r3
  __int64 v11; // r8
  idBareDctDecoder *v12; // r3
  __int64 v13; // r8
  idBareDctDecoder *v14; // r3
  int v15; // r3
  __int64 v16; // r8
  int v17; // r3
  __int64 v18; // r8
  int v19; // r3
  const unsigned __int16 *v20; // r30
  __int16 v21[64]; // [sp+50h] [-330h] BYREF
  __int16 v22[64]; // [sp+D0h] [-2B0h] BYREF
  __int16 v23[64]; // [sp+150h] [-230h] BYREF
  __int16 v24[64]; // [sp+1D0h] [-1B0h] BYREF
  __int16 v25[64]; // [sp+250h] [-130h] BYREF
  __int16 v26[88]; // [sp+2D0h] [-B0h] BYREF

  p_dcY = &this->dcY;
  HIDWORD(a5) = &this->dcY;
  idBareDctDecoder::HuffmanDecode_Xenon(this, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: a5);
  HIDWORD(v9) = p_dcY;
  idBareDctDecoder::HuffmanDecode_Xenon(this: v10, dctbl: *(_QWORD *)&v10->pHuffTableYDC, lastDC: v9);
  HIDWORD(v11) = p_dcY;
  idBareDctDecoder::HuffmanDecode_Xenon(this: v12, dctbl: *(_QWORD *)&v12->pHuffTableYDC, lastDC: v11);
  HIDWORD(v13) = p_dcY;
  idBareDctDecoder::HuffmanDecode_Xenon(this: v14, dctbl: *(_QWORD *)&v14->pHuffTableYDC, lastDC: v13);
  HIDWORD(v16) = v15 + 412;
  idBareDctDecoder::HuffmanDecode_Xenon(this: (idBareDctDecoder *)v15, dctbl: *(_QWORD *)(v15 + 456), lastDC: v16);
  HIDWORD(v18) = v17 + 416;
  idBareDctDecoder::HuffmanDecode_Xenon(this: (idBareDctDecoder *)v17, dctbl: *(_QWORD *)(v17 + 456), lastDC: v18);
  v20 = (const unsigned __int16 *)(v19 + 16);
  IDCT_AP922_float_Xenon(coeff: v21, quant: (const unsigned __int16 *)(v19 + 16), dest: v21);
  IDCT_AP922_float_Xenon(coeff: v22, quant: v20, dest: v22);
  IDCT_AP922_float_Xenon(coeff: v23, quant: v20, dest: v23);
  IDCT_AP922_float_Xenon(coeff: v24, quant: v20, dest: v24);
  IDCT_AP922_float_Xenon(coeff: v25, quant: this->quantTableCoCg, dest: v25);
  IDCT_AP922_float_Xenon(coeff: v26, quant: this->quantTableCoCg, dest: v26);
  idBareDctDecoder::YCoCgToRGB_Xenon(this, YCoCg: v21, rgb, stride);
}


// ========================================================================
// ?DecompressOneTileYCoCg_Xenon@idBareDctDecoder@@AAAXPIAEH@Z
// EA  : 0x828E6540
// RVA : 0x008E6540
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder_xenon.cpp
// ========================================================================

void __fastcall idBareDctDecoder::DecompressOneTileYCoCg_Xenon(
        idBareDctDecoder *this,
        unsigned __int8 *rgb,
        int stride,
        int a4,
        __int64 a5)
{
  int *p_dcY; // r30
  unsigned __int64 v8; // r6
  __int64 v10; // r8
  idBareDctDecoder *v11; // r3
  __int64 v12; // r8
  idBareDctDecoder *v13; // r3
  __int64 v14; // r8
  idBareDctDecoder *v15; // r3
  int v16; // r3
  __int64 v17; // r8
  int v18; // r3
  __int64 v19; // r8
  int v20; // r3
  const unsigned __int16 *v21; // r30
  __int64 v22; // r8
  __int64 v23; // r8
  idBareDctDecoder *v24; // r3
  __int64 v25; // r8
  idBareDctDecoder *v26; // r3
  __int64 v27; // r8
  idBareDctDecoder *v28; // r3
  __int64 v29; // r8
  idBareDctDecoder *v30; // r3
  __int64 v31; // r8
  idBareDctDecoder *v32; // r3
  __int64 v33; // r8
  idBareDctDecoder *v34; // r3
  __int64 v35; // r8
  idBareDctDecoder *v36; // r3
  __int64 v37; // r8
  idBareDctDecoder *v38; // r3
  __int64 v39; // r8
  idBareDctDecoder *v40; // r3
  __int64 v41; // r8
  idBareDctDecoder *v42; // r3
  __int16 v43[64]; // [sp+50h] [-630h] BYREF
  __int16 v44[64]; // [sp+D0h] [-5B0h] BYREF
  __int16 v45[64]; // [sp+150h] [-530h] BYREF
  __int16 v46[64]; // [sp+1D0h] [-4B0h] BYREF
  __int16 v47[64]; // [sp+250h] [-430h] BYREF
  __int16 v48[64]; // [sp+2D0h] [-3B0h] BYREF
  __int16 v49[64]; // [sp+350h] [-330h] BYREF
  __int16 v50[64]; // [sp+3D0h] [-2B0h] BYREF
  __int16 v51[64]; // [sp+450h] [-230h] BYREF
  __int16 v52[64]; // [sp+4D0h] [-1B0h] BYREF
  __int16 v53[64]; // [sp+550h] [-130h] BYREF
  __int16 v54[88]; // [sp+5D0h] [-B0h] BYREF

  p_dcY = &this->dcY;
  v8 = *(_QWORD *)&this->pHuffTableYDC;
  HIDWORD(a5) = &this->dcY;
  if ( this->sampleMode == SAMPLE_420 )
  {
    idBareDctDecoder::HuffmanDecode_Xenon(this, dctbl: v8, lastDC: a5);
    HIDWORD(v10) = p_dcY;
    idBareDctDecoder::HuffmanDecode_Xenon(this: v11, dctbl: *(_QWORD *)&v11->pHuffTableYDC, lastDC: v10);
    HIDWORD(v12) = p_dcY;
    idBareDctDecoder::HuffmanDecode_Xenon(this: v13, dctbl: *(_QWORD *)&v13->pHuffTableYDC, lastDC: v12);
    HIDWORD(v14) = p_dcY;
    idBareDctDecoder::HuffmanDecode_Xenon(this: v15, dctbl: *(_QWORD *)&v15->pHuffTableYDC, lastDC: v14);
    HIDWORD(v17) = v16 + 412;
    idBareDctDecoder::HuffmanDecode_Xenon(this: (idBareDctDecoder *)v16, dctbl: *(_QWORD *)(v16 + 456), lastDC: v17);
    HIDWORD(v19) = v18 + 416;
    idBareDctDecoder::HuffmanDecode_Xenon(this: (idBareDctDecoder *)v18, dctbl: *(_QWORD *)(v18 + 456), lastDC: v19);
    v21 = (const unsigned __int16 *)(v20 + 16);
    IDCT_AP922_float_Xenon(coeff: v43, quant: (const unsigned __int16 *)(v20 + 16), dest: v43);
    IDCT_AP922_float_Xenon(coeff: v44, quant: v21, dest: v44);
    IDCT_AP922_float_Xenon(coeff: v45, quant: v21, dest: v45);
    IDCT_AP922_float_Xenon(coeff: v46, quant: v21, dest: v46);
    IDCT_AP922_float_Xenon(coeff: v47, quant: this->quantTableCoCg, dest: v47);
    IDCT_AP922_float_Xenon(coeff: v48, quant: this->quantTableCoCg, dest: v48);
    idBareDctDecoder::StoreYCoCg420_Xenon(this, YCoCg: v43, CoCg_Y: rgb, stride);
  }
  else
  {
    idBareDctDecoder::HuffmanDecode_Xenon(this, dctbl: v8, lastDC: a5);
    HIDWORD(v22) = p_dcY;
    idBareDctDecoder::HuffmanDecode_Xenon(this, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v22);
    HIDWORD(v23) = p_dcY;
    idBareDctDecoder::HuffmanDecode_Xenon(this: v24, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v23);
    HIDWORD(v25) = p_dcY;
    idBareDctDecoder::HuffmanDecode_Xenon(this: v26, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v25);
    HIDWORD(v27) = &this->dcCo;
    idBareDctDecoder::HuffmanDecode_Xenon(this: v28, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v27);
    HIDWORD(v29) = &this->dcCo;
    idBareDctDecoder::HuffmanDecode_Xenon(this: v30, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v29);
    HIDWORD(v31) = &this->dcCo;
    idBareDctDecoder::HuffmanDecode_Xenon(this: v32, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v31);
    HIDWORD(v33) = &this->dcCo;
    idBareDctDecoder::HuffmanDecode_Xenon(this: v34, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v33);
    HIDWORD(v35) = &this->dcCg;
    idBareDctDecoder::HuffmanDecode_Xenon(this: v36, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v35);
    HIDWORD(v37) = &this->dcCg;
    idBareDctDecoder::HuffmanDecode_Xenon(this: v38, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v37);
    HIDWORD(v39) = &this->dcCg;
    idBareDctDecoder::HuffmanDecode_Xenon(this: v40, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v39);
    HIDWORD(v41) = &this->dcCg;
    idBareDctDecoder::HuffmanDecode_Xenon(this: v42, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v41);
    IDCT_AP922_float_Xenon(coeff: v43, quant: this->quantTableY, dest: v43);
    IDCT_AP922_float_Xenon(coeff: v44, quant: this->quantTableY, dest: v44);
    IDCT_AP922_float_Xenon(coeff: v45, quant: this->quantTableY, dest: v45);
    IDCT_AP922_float_Xenon(coeff: v46, quant: this->quantTableY, dest: v46);
    IDCT_AP922_float_Xenon(coeff: v47, quant: this->quantTableCoCg, dest: v47);
    IDCT_AP922_float_Xenon(coeff: v48, quant: this->quantTableCoCg, dest: v48);
    IDCT_AP922_float_Xenon(coeff: v49, quant: this->quantTableCoCg, dest: v49);
    IDCT_AP922_float_Xenon(coeff: v50, quant: this->quantTableCoCg, dest: v50);
    IDCT_AP922_float_Xenon(coeff: v51, quant: this->quantTableCoCg, dest: v51);
    IDCT_AP922_float_Xenon(coeff: v52, quant: this->quantTableCoCg, dest: v52);
    IDCT_AP922_float_Xenon(coeff: v53, quant: this->quantTableCoCg, dest: v53);
    IDCT_AP922_float_Xenon(coeff: v54, quant: this->quantTableCoCg, dest: v54);
    idBareDctDecoder::StoreYCoCg444_Xenon(this, YCoCg: v43, CoCg_Y: rgb, stride);
  }
}


// ========================================================================
// ?DecompressOneTileNormalMap_Xenon@idBareDctDecoder@@AAAXPIAEH@Z
// EA  : 0x828E6838
// RVA : 0x008E6838
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder_xenon.cpp
// ========================================================================

void __fastcall idBareDctDecoder::DecompressOneTileNormalMap_Xenon(
        idBareDctDecoder *this,
        unsigned __int8 *normalMap,
        int stride,
        int a4,
        __int64 a5)
{
  int *p_dcY; // r30
  __int64 v9; // r8
  idBareDctDecoder *v10; // r3
  __int64 v11; // r8
  idBareDctDecoder *v12; // r3
  __int64 v13; // r8
  idBareDctDecoder *v14; // r3
  int v15; // r3
  int v16; // r30
  __int64 v17; // r8
  __int64 v18; // r8
  idBareDctDecoder *v19; // r3
  __int64 v20; // r8
  idBareDctDecoder *v21; // r3
  __int64 v22; // r8
  idBareDctDecoder *v23; // r3
  int v24; // r3
  const unsigned __int16 *v25; // r30
  __int16 v26[64]; // [sp+50h] [-430h] BYREF
  __int16 v27[64]; // [sp+D0h] [-3B0h] BYREF
  __int16 v28[64]; // [sp+150h] [-330h] BYREF
  __int16 v29[64]; // [sp+1D0h] [-2B0h] BYREF
  __int16 v30[64]; // [sp+250h] [-230h] BYREF
  __int16 v31[64]; // [sp+2D0h] [-1B0h] BYREF
  __int16 v32[64]; // [sp+350h] [-130h] BYREF
  __int16 v33[88]; // [sp+3D0h] [-B0h] BYREF

  p_dcY = &this->dcY;
  HIDWORD(a5) = &this->dcY;
  idBareDctDecoder::HuffmanDecode_Xenon(this, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: a5);
  HIDWORD(v9) = p_dcY;
  idBareDctDecoder::HuffmanDecode_Xenon(this: v10, dctbl: *(_QWORD *)&v10->pHuffTableYDC, lastDC: v9);
  HIDWORD(v11) = p_dcY;
  idBareDctDecoder::HuffmanDecode_Xenon(this: v12, dctbl: *(_QWORD *)&v12->pHuffTableYDC, lastDC: v11);
  HIDWORD(v13) = p_dcY;
  idBareDctDecoder::HuffmanDecode_Xenon(this: v14, dctbl: *(_QWORD *)&v14->pHuffTableYDC, lastDC: v13);
  v16 = v15 + 420;
  HIDWORD(v17) = v15 + 420;
  idBareDctDecoder::HuffmanDecode_Xenon(this: (idBareDctDecoder *)v15, dctbl: *(_QWORD *)(v15 + 448), lastDC: v17);
  HIDWORD(v18) = v16;
  idBareDctDecoder::HuffmanDecode_Xenon(this: v19, dctbl: *(_QWORD *)&v19->pHuffTableYDC, lastDC: v18);
  HIDWORD(v20) = v16;
  idBareDctDecoder::HuffmanDecode_Xenon(this: v21, dctbl: *(_QWORD *)&v21->pHuffTableYDC, lastDC: v20);
  HIDWORD(v22) = v16;
  idBareDctDecoder::HuffmanDecode_Xenon(this: v23, dctbl: *(_QWORD *)&v23->pHuffTableYDC, lastDC: v22);
  v25 = (const unsigned __int16 *)(v24 + 16);
  IDCT_AP922_float_Xenon(coeff: v26, quant: (const unsigned __int16 *)(v24 + 16), dest: v26);
  IDCT_AP922_float_Xenon(coeff: v27, quant: v25, dest: v27);
  IDCT_AP922_float_Xenon(coeff: v28, quant: v25, dest: v28);
  IDCT_AP922_float_Xenon(coeff: v29, quant: v25, dest: v29);
  IDCT_AP922_float_Xenon(coeff: v30, quant: v25, dest: v30);
  IDCT_AP922_float_Xenon(coeff: v31, quant: v25, dest: v31);
  IDCT_AP922_float_Xenon(coeff: v32, quant: v25, dest: v32);
  IDCT_AP922_float_Xenon(coeff: v33, quant: v25, dest: v33);
  idBareDctDecoder::StoreNormalMap_Xenon(this, ms: v26, normalMap, stride);
  idBareDctDecoder::StoreNormalMap_Xenon(this, ms: v28, normalMap: normalMap + 32, stride);
  idBareDctDecoder::StoreNormalMap_Xenon(this, ms: v30, normalMap: &normalMap[8 * stride], stride);
  idBareDctDecoder::StoreNormalMap_Xenon(this, ms: v32, normalMap: &normalMap[8 * stride + 32], stride);
}


// ========================================================================
// ?DecompressImageMono_Xenon@idBareDctDecoder@@AAA_NPBEPAEHHH@Z
// EA  : 0x828E69E0
// RVA : 0x008E69E0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder_xenon.cpp
// ========================================================================

int __fastcall idBareDctDecoder::DecompressImageMono_Xenon(
        idBareDctDecoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        __int64 inputBytes)
{
  unsigned __int64 v5; // r23
  int v6; // r21
  int v9; // r20
  int *p_dcY; // r28
  int v11; // r22
  int v12; // r26
  int i; // r27
  int imageWidth; // r19
  unsigned __int8 *v15; // r29
  __int64 v16; // r8
  idBareDctDecoder *v17; // r3
  __int64 v18; // r8
  idBareDctDecoder *v19; // r3
  __int64 v20; // r8
  idBareDctDecoder *v21; // r3
  int v22; // r5
  __int16 v24[64]; // [sp+50h] [-270h] BYREF
  __int16 v25[64]; // [sp+D0h] [-1F0h] BYREF
  __int16 v26[64]; // [sp+150h] [-170h] BYREF
  __int16 v27[120]; // [sp+1D0h] [-F0h] BYREF

  this->imageHeight = HIDWORD(inputBytes);
  LODWORD(v5) = 0;
  this->data = inBuf;
  this->dataBytes = inputBytes;
  v6 = (width + 15) >> 4;
  this->bitCnt = v5;
  this->bitBuff = v5;
  this->dcA = 0;
  v9 = (HIDWORD(inputBytes) + 15) >> 4;
  this->dcCg = 0;
  p_dcY = &this->dcY;
  this->dcCo = 0;
  this->dcY = 0;
  v11 = 0;
  for ( this->imageWidth = width; v11 < v9; ++v11 )
  {
    if ( v6 > 0 )
    {
      v12 = 0;
      for ( i = v6; i != 0; --i )
      {
        imageWidth = this->imageWidth;
        HIDWORD(inputBytes) = p_dcY;
        v15 = &outBuf[16 * v11 * imageWidth + v12];
        idBareDctDecoder::HuffmanDecode_Xenon(this, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: inputBytes);
        HIDWORD(v16) = p_dcY;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v17, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v16);
        HIDWORD(v18) = p_dcY;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v19, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v18);
        HIDWORD(v20) = p_dcY;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v21, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v20);
        IDCT_AP922_float_Xenon(coeff: v24, quant: this->quantTableY, dest: v24);
        IDCT_AP922_float_Xenon(coeff: v25, quant: this->quantTableY, dest: v25);
        IDCT_AP922_float_Xenon(coeff: v26, quant: this->quantTableY, dest: v26);
        IDCT_AP922_float_Xenon(coeff: v27, quant: this->quantTableY, dest: v27);
        idBareDctDecoder::StoreMono_Xenon(this, ms: v24, mono: v15, stride: imageWidth);
        idBareDctDecoder::StoreMono_Xenon(this, ms: v25, mono: v15 + 8, stride: imageWidth);
        idBareDctDecoder::StoreMono_Xenon(this, ms: v26, mono: &v15[8 * imageWidth], stride: imageWidth);
        idBareDctDecoder::StoreMono_Xenon(this, ms: v27, mono: (unsigned __int8 *)(v22 + 8), stride: imageWidth);
        v12 += 16;
      }
    }
  }
  return 1;
}


// ========================================================================
// ?DecompressImageGrayScale_Xenon@idBareDctDecoder@@AAA_NPBEPAEHHH@Z
// EA  : 0x828E6B70
// RVA : 0x008E6B70
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder_xenon.cpp
// ========================================================================

int __fastcall idBareDctDecoder::DecompressImageGrayScale_Xenon(
        idBareDctDecoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        __int64 inputBytes)
{
  unsigned __int64 v5; // r22
  int v6; // r24
  int v9; // r21
  int *p_dcY; // r27
  int v11; // r25
  int i; // r26
  int imageWidth; // r20
  unsigned __int8 *v14; // r29
  __int64 v15; // r8
  idBareDctDecoder *v16; // r3
  __int64 v17; // r8
  idBareDctDecoder *v18; // r3
  __int64 v19; // r8
  idBareDctDecoder *v20; // r3
  int v21; // r6
  int v22; // r6
  int v23; // r6
  __int16 v25[64]; // [sp+50h] [-270h] BYREF
  __int16 v26[64]; // [sp+D0h] [-1F0h] BYREF
  __int16 v27[64]; // [sp+150h] [-170h] BYREF
  __int16 v28[120]; // [sp+1D0h] [-F0h] BYREF

  this->imageHeight = HIDWORD(inputBytes);
  LODWORD(v5) = 0;
  this->data = inBuf;
  this->dataBytes = inputBytes;
  v6 = (width + 15) >> 4;
  this->bitCnt = v5;
  this->bitBuff = v5;
  this->dcA = 0;
  v9 = (HIDWORD(inputBytes) + 15) >> 4;
  this->dcCg = 0;
  p_dcY = &this->dcY;
  this->dcCo = 0;
  this->dcY = 0;
  v11 = 0;
  for ( this->imageWidth = width; v11 < v9; ++v11 )
  {
    for ( i = 0; i < v6; ++i )
    {
      imageWidth = this->imageWidth;
      HIDWORD(inputBytes) = p_dcY;
      v14 = &outBuf[64 * (imageWidth * v11 + i)];
      idBareDctDecoder::HuffmanDecode_Xenon(this, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: inputBytes);
      HIDWORD(v15) = p_dcY;
      idBareDctDecoder::HuffmanDecode_Xenon(this: v16, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v15);
      HIDWORD(v17) = p_dcY;
      idBareDctDecoder::HuffmanDecode_Xenon(this: v18, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v17);
      HIDWORD(v19) = p_dcY;
      idBareDctDecoder::HuffmanDecode_Xenon(this: v20, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v19);
      IDCT_AP922_float_Xenon(coeff: v25, quant: this->quantTableY, dest: v25);
      IDCT_AP922_float_Xenon(coeff: v26, quant: this->quantTableY, dest: v26);
      IDCT_AP922_float_Xenon(coeff: v27, quant: this->quantTableY, dest: v27);
      IDCT_AP922_float_Xenon(coeff: v28, quant: this->quantTableY, dest: v28);
      idBareDctDecoder::StoreGrayScale_Xenon(this, ms: v25, rgb: v14, stride: 4 * imageWidth);
      idBareDctDecoder::StoreGrayScale_Xenon(this, ms: v26, rgb: v14 + 32, stride: v21);
      idBareDctDecoder::StoreGrayScale_Xenon(this, ms: v27, rgb: &v14[32 * imageWidth], stride: v22);
      idBareDctDecoder::StoreGrayScale_Xenon(this, ms: v28, rgb: &v14[32 * imageWidth + 32], stride: v23);
    }
  }
  return 1;
}


// ========================================================================
// ?DecompressImageRGB_Xenon@idBareDctDecoder@@AAA_NPBEPAEHHH@Z
// EA  : 0x828E6D00
// RVA : 0x008E6D00
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder_xenon.cpp
// ========================================================================

int __fastcall idBareDctDecoder::DecompressImageRGB_Xenon(
        idBareDctDecoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        __int64 inputBytes)
{
  unsigned __int64 v5; // r20
  int v6; // r24
  int v9; // r19
  int *p_dcCg; // r23
  int *p_dcCo; // r22
  int *p_dcY; // r29
  int i; // r25
  int j; // r28
  int imageWidth; // r10
  int v16; // r18
  unsigned __int8 *v17; // r26
  __int64 v18; // r8
  idBareDctDecoder *v19; // r3
  __int64 v20; // r8
  idBareDctDecoder *v21; // r3
  __int64 v22; // r8
  idBareDctDecoder *v23; // r3
  __int64 v24; // r8
  idBareDctDecoder *v25; // r3
  __int64 v26; // r8
  idBareDctDecoder *v27; // r3
  __int16 v29[64]; // [sp+50h] [-380h] BYREF
  __int16 v30[64]; // [sp+D0h] [-300h] BYREF
  __int16 v31[64]; // [sp+150h] [-280h] BYREF
  __int16 v32[64]; // [sp+1D0h] [-200h] BYREF
  __int16 v33[64]; // [sp+250h] [-180h] BYREF
  __int16 v34[128]; // [sp+2D0h] [-100h] BYREF

  this->imageHeight = HIDWORD(inputBytes);
  LODWORD(v5) = 0;
  this->data = inBuf;
  this->dataBytes = inputBytes;
  v6 = (width + 15) >> 4;
  this->bitCnt = v5;
  this->bitBuff = v5;
  this->dcA = 0;
  v9 = (HIDWORD(inputBytes) + 15) >> 4;
  this->dcCg = 0;
  p_dcCg = &this->dcCg;
  this->dcCo = 0;
  p_dcCo = &this->dcCo;
  this->dcY = 0;
  p_dcY = &this->dcY;
  this->imageWidth = width;
  for ( i = 0; i < v9; ++i )
  {
    for ( j = 0; j < v6; ++j )
    {
      imageWidth = this->imageWidth;
      HIDWORD(inputBytes) = p_dcY;
      v16 = 4 * imageWidth;
      v17 = &outBuf[64 * (imageWidth * i + j)];
      idBareDctDecoder::HuffmanDecode_Xenon(this, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: inputBytes);
      HIDWORD(v18) = p_dcY;
      idBareDctDecoder::HuffmanDecode_Xenon(this: v19, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v18);
      HIDWORD(v20) = p_dcY;
      idBareDctDecoder::HuffmanDecode_Xenon(this: v21, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v20);
      HIDWORD(v22) = p_dcY;
      idBareDctDecoder::HuffmanDecode_Xenon(this: v23, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v22);
      HIDWORD(v24) = p_dcCo;
      idBareDctDecoder::HuffmanDecode_Xenon(this: v25, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v24);
      HIDWORD(v26) = p_dcCg;
      idBareDctDecoder::HuffmanDecode_Xenon(this: v27, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v26);
      IDCT_AP922_float_Xenon(coeff: v29, quant: this->quantTableY, dest: v29);
      IDCT_AP922_float_Xenon(coeff: v30, quant: this->quantTableY, dest: v30);
      IDCT_AP922_float_Xenon(coeff: v31, quant: this->quantTableY, dest: v31);
      IDCT_AP922_float_Xenon(coeff: v32, quant: this->quantTableY, dest: v32);
      IDCT_AP922_float_Xenon(coeff: v33, quant: this->quantTableCoCg, dest: v33);
      IDCT_AP922_float_Xenon(coeff: v34, quant: this->quantTableCoCg, dest: v34);
      idBareDctDecoder::YCoCgToRGB_Xenon(this, YCoCg: v29, rgb: v17, stride: v16);
    }
  }
  return 1;
}


// ========================================================================
// ?DecompressImageYCoCg_Xenon@idBareDctDecoder@@AAA_NPBEPAEHHH@Z
// EA  : 0x828E6EA8
// RVA : 0x008E6EA8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder_xenon.cpp
// ========================================================================

int __fastcall idBareDctDecoder::DecompressImageYCoCg_Xenon(
        idBareDctDecoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height,
        int inputBytes)
{
  unsigned __int64 v6; // r20
  int v9; // r18
  int *p_dcCg; // r27
  int *p_dcCo; // r26
  int *p_dcY; // r28
  int i; // r22
  int j; // r23
  int imageWidth; // r10
  unsigned __int64 v16; // r6
  __int64 v17; // r8
  int v18; // r25
  unsigned __int8 *v19; // r24
  __int64 v20; // r8
  idBareDctDecoder *v21; // r3
  __int64 v22; // r8
  idBareDctDecoder *v23; // r3
  __int64 v24; // r8
  idBareDctDecoder *v25; // r3
  __int64 v26; // r8
  idBareDctDecoder *v27; // r3
  __int64 v28; // r8
  idBareDctDecoder *v29; // r3
  __int64 v30; // r8
  __int64 v31; // r8
  idBareDctDecoder *v32; // r3
  __int64 v33; // r8
  idBareDctDecoder *v34; // r3
  __int64 v35; // r8
  idBareDctDecoder *v36; // r3
  __int64 v37; // r8
  idBareDctDecoder *v38; // r3
  __int64 v39; // r8
  idBareDctDecoder *v40; // r3
  __int64 v41; // r8
  idBareDctDecoder *v42; // r3
  __int64 v43; // r8
  idBareDctDecoder *v44; // r3
  __int64 v45; // r8
  idBareDctDecoder *v46; // r3
  __int64 v47; // r8
  idBareDctDecoder *v48; // r3
  __int64 v49; // r8
  idBareDctDecoder *v50; // r3
  __int16 v52[64]; // [sp+50h] [-680h] BYREF
  __int16 v53[64]; // [sp+D0h] [-600h] BYREF
  __int16 v54[64]; // [sp+150h] [-580h] BYREF
  __int16 v55[64]; // [sp+1D0h] [-500h] BYREF
  __int16 v56[64]; // [sp+250h] [-480h] BYREF
  __int16 v57[64]; // [sp+2D0h] [-400h] BYREF
  __int16 v58[64]; // [sp+350h] [-380h] BYREF
  __int16 v59[64]; // [sp+3D0h] [-300h] BYREF
  __int16 v60[64]; // [sp+450h] [-280h] BYREF
  __int16 v61[64]; // [sp+4D0h] [-200h] BYREF
  __int16 v62[64]; // [sp+550h] [-180h] BYREF
  __int16 v63[128]; // [sp+5D0h] [-100h] BYREF

  this->imageHeight = height;
  LODWORD(v6) = 0;
  this->data = inBuf;
  this->dataBytes = inputBytes;
  HIDWORD(v6) = (width + 15) >> 4;
  this->bitCnt = v6;
  this->bitBuff = v6;
  this->dcA = 0;
  v9 = (height + 15) >> 4;
  this->dcCg = 0;
  p_dcCg = &this->dcCg;
  this->dcCo = 0;
  p_dcCo = &this->dcCo;
  this->dcY = 0;
  p_dcY = &this->dcY;
  this->imageWidth = width;
  for ( i = 0; i < v9; ++i )
  {
    for ( j = 0; j < SHIDWORD(v6); ++j )
    {
      imageWidth = this->imageWidth;
      HIDWORD(v17) = p_dcY;
      v16 = *(_QWORD *)&this->pHuffTableYDC;
      LODWORD(v17) = imageWidth * i + j;
      v18 = 4 * imageWidth;
      v19 = &outBuf[64 * (_DWORD)v17];
      if ( this->sampleMode == SAMPLE_420 )
      {
        idBareDctDecoder::HuffmanDecode_Xenon(this, dctbl: v16, lastDC: v17);
        HIDWORD(v20) = p_dcY;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v21, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v20);
        HIDWORD(v22) = p_dcY;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v23, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v22);
        HIDWORD(v24) = p_dcY;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v25, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v24);
        HIDWORD(v26) = p_dcCo;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v27, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v26);
        HIDWORD(v28) = p_dcCg;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v29, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v28);
        IDCT_AP922_float_Xenon(coeff: v52, quant: this->quantTableY, dest: v52);
        IDCT_AP922_float_Xenon(coeff: v53, quant: this->quantTableY, dest: v53);
        IDCT_AP922_float_Xenon(coeff: v54, quant: this->quantTableY, dest: v54);
        IDCT_AP922_float_Xenon(coeff: v55, quant: this->quantTableY, dest: v55);
        IDCT_AP922_float_Xenon(coeff: v56, quant: this->quantTableCoCg, dest: v56);
        IDCT_AP922_float_Xenon(coeff: v57, quant: this->quantTableCoCg, dest: v57);
        idBareDctDecoder::StoreYCoCg420_Xenon(this, YCoCg: v52, CoCg_Y: v19, stride: v18);
      }
      else
      {
        idBareDctDecoder::HuffmanDecode_Xenon(this, dctbl: v16, lastDC: v17);
        HIDWORD(v30) = p_dcY;
        idBareDctDecoder::HuffmanDecode_Xenon(this, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v30);
        HIDWORD(v31) = p_dcY;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v32, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v31);
        HIDWORD(v33) = p_dcY;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v34, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v33);
        HIDWORD(v35) = p_dcCo;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v36, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v35);
        HIDWORD(v37) = p_dcCo;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v38, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v37);
        HIDWORD(v39) = p_dcCo;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v40, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v39);
        HIDWORD(v41) = p_dcCo;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v42, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v41);
        HIDWORD(v43) = p_dcCg;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v44, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v43);
        HIDWORD(v45) = p_dcCg;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v46, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v45);
        HIDWORD(v47) = p_dcCg;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v48, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v47);
        HIDWORD(v49) = p_dcCg;
        idBareDctDecoder::HuffmanDecode_Xenon(this: v50, dctbl: *(_QWORD *)&this->pHuffTableCoCgDC, lastDC: v49);
        IDCT_AP922_float_Xenon(coeff: v52, quant: this->quantTableY, dest: v52);
        IDCT_AP922_float_Xenon(coeff: v53, quant: this->quantTableY, dest: v53);
        IDCT_AP922_float_Xenon(coeff: v54, quant: this->quantTableY, dest: v54);
        IDCT_AP922_float_Xenon(coeff: v55, quant: this->quantTableY, dest: v55);
        IDCT_AP922_float_Xenon(coeff: v56, quant: this->quantTableCoCg, dest: v56);
        IDCT_AP922_float_Xenon(coeff: v57, quant: this->quantTableCoCg, dest: v57);
        IDCT_AP922_float_Xenon(coeff: v58, quant: this->quantTableCoCg, dest: v58);
        IDCT_AP922_float_Xenon(coeff: v59, quant: this->quantTableCoCg, dest: v59);
        IDCT_AP922_float_Xenon(coeff: v60, quant: this->quantTableCoCg, dest: v60);
        IDCT_AP922_float_Xenon(coeff: v61, quant: this->quantTableCoCg, dest: v61);
        IDCT_AP922_float_Xenon(coeff: v62, quant: this->quantTableCoCg, dest: v62);
        IDCT_AP922_float_Xenon(coeff: v63, quant: this->quantTableCoCg, dest: v63);
        idBareDctDecoder::StoreYCoCg444_Xenon(this, YCoCg: v52, CoCg_Y: v19, stride: v18);
      }
    }
  }
  return 1;
}


// ========================================================================
// ?DecompressImageNormalMap_Xenon@idBareDctDecoder@@AAA_NPBEPAEHHH@Z
// EA  : 0x828E7218
// RVA : 0x008E7218
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder_xenon.cpp
// ========================================================================

int __fastcall idBareDctDecoder::DecompressImageNormalMap_Xenon(
        idBareDctDecoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        __int64 inputBytes)
{
  unsigned __int64 v5; // r21
  int v6; // r23
  int v9; // r20
  int *p_dcA; // r27
  int *p_dcY; // r26
  int v12; // r24
  int i; // r25
  int imageWidth; // r19
  unsigned __int8 *v15; // r28
  __int64 v16; // r8
  idBareDctDecoder *v17; // r3
  __int64 v18; // r8
  idBareDctDecoder *v19; // r3
  __int64 v20; // r8
  idBareDctDecoder *v21; // r3
  __int64 v22; // r8
  idBareDctDecoder *v23; // r3
  __int64 v24; // r8
  idBareDctDecoder *v25; // r3
  __int64 v26; // r8
  idBareDctDecoder *v27; // r3
  __int64 v28; // r8
  idBareDctDecoder *v29; // r3
  __int16 v31[64]; // [sp+50h] [-470h] BYREF
  __int16 v32[64]; // [sp+D0h] [-3F0h] BYREF
  __int16 v33[64]; // [sp+150h] [-370h] BYREF
  __int16 v34[64]; // [sp+1D0h] [-2F0h] BYREF
  __int16 v35[64]; // [sp+250h] [-270h] BYREF
  __int16 v36[64]; // [sp+2D0h] [-1F0h] BYREF
  __int16 v37[64]; // [sp+350h] [-170h] BYREF
  __int16 v38[120]; // [sp+3D0h] [-F0h] BYREF

  this->imageHeight = HIDWORD(inputBytes);
  LODWORD(v5) = 0;
  this->data = inBuf;
  this->dataBytes = inputBytes;
  v6 = (width + 15) >> 4;
  this->bitCnt = v5;
  this->bitBuff = v5;
  this->dcA = 0;
  v9 = (HIDWORD(inputBytes) + 15) >> 4;
  this->dcCg = 0;
  p_dcA = &this->dcA;
  this->dcCo = 0;
  p_dcY = &this->dcY;
  this->dcY = 0;
  v12 = 0;
  for ( this->imageWidth = width; v12 < v9; ++v12 )
  {
    for ( i = 0; i < v6; ++i )
    {
      imageWidth = this->imageWidth;
      HIDWORD(inputBytes) = p_dcY;
      v15 = &outBuf[64 * (imageWidth * v12 + i)];
      idBareDctDecoder::HuffmanDecode_Xenon(this, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: inputBytes);
      HIDWORD(v16) = p_dcY;
      idBareDctDecoder::HuffmanDecode_Xenon(this: v17, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v16);
      HIDWORD(v18) = p_dcY;
      idBareDctDecoder::HuffmanDecode_Xenon(this: v19, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v18);
      HIDWORD(v20) = p_dcY;
      idBareDctDecoder::HuffmanDecode_Xenon(this: v21, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v20);
      HIDWORD(v22) = p_dcA;
      idBareDctDecoder::HuffmanDecode_Xenon(this: v23, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v22);
      HIDWORD(v24) = p_dcA;
      idBareDctDecoder::HuffmanDecode_Xenon(this: v25, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v24);
      HIDWORD(v26) = p_dcA;
      idBareDctDecoder::HuffmanDecode_Xenon(this: v27, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v26);
      HIDWORD(v28) = p_dcA;
      idBareDctDecoder::HuffmanDecode_Xenon(this: v29, dctbl: *(_QWORD *)&this->pHuffTableYDC, lastDC: v28);
      IDCT_AP922_float_Xenon(coeff: v31, quant: this->quantTableY, dest: v31);
      IDCT_AP922_float_Xenon(coeff: v32, quant: this->quantTableY, dest: v32);
      IDCT_AP922_float_Xenon(coeff: v33, quant: this->quantTableY, dest: v33);
      IDCT_AP922_float_Xenon(coeff: v34, quant: this->quantTableY, dest: v34);
      IDCT_AP922_float_Xenon(coeff: v35, quant: this->quantTableY, dest: v35);
      IDCT_AP922_float_Xenon(coeff: v36, quant: this->quantTableY, dest: v36);
      IDCT_AP922_float_Xenon(coeff: v37, quant: this->quantTableY, dest: v37);
      IDCT_AP922_float_Xenon(coeff: v38, quant: this->quantTableY, dest: v38);
      idBareDctDecoder::StoreNormalMap_Xenon(this, ms: v31, normalMap: v15, stride: 4 * imageWidth);
      idBareDctDecoder::StoreNormalMap_Xenon(this, ms: v33, normalMap: v15 + 32, stride: 4 * imageWidth);
      idBareDctDecoder::StoreNormalMap_Xenon(this, ms: v35, normalMap: &v15[32 * imageWidth], stride: 4 * imageWidth);
      idBareDctDecoder::StoreNormalMap_Xenon(
        this,
        ms: v37,
        normalMap: &v15[32 * imageWidth + 32],
        stride: 4 * imageWidth);
    }
  }
  return 1;
}

