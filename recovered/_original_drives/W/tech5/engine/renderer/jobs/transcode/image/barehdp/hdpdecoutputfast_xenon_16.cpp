
// ========================================================================
// ?HDPDecOutputMB_Mono_Xenon_16@@YA?AW4hdpError_t@@PAUhdpCodec_t@@PBUhdpImageBufferInfo_t@@@Z
// EA  : 0x828F3388
// RVA : 0x008F3388
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdecoutputfast_xenon_16.cpp
// ========================================================================

int __fastcall HDPDecOutputMB_Mono_Xenon_16(hdpCodec_t *codec, const hdpImageBufferInfo_t *bufferInfo)
{
  unsigned int currentMacroblockRow; // r11
  unsigned int v5; // r10
  unsigned int v10; // r6
  int v13; // ctr
  __int16 back_chain; // [sp+0h] [-40h] BYREF
  __int16 v25; // [sp+2h] [-3Eh] BYREF

  if ( codec == nullptr )
    return -5;
  if ( codec->codecParms.decodeFullFrame
    || (currentMacroblockRow = codec->currentMacroblockRow,
        v5 = codec->codecParms.tileMacroblockOffsetX[codec->currentTileColumn] + bufferInfo->macroblockIndex,
        16 * currentMacroblockRow >= codec->codecParms.fullImageROITopY)
    && 16 * (currentMacroblockRow - 1) <= codec->codecParms.fullImageROIBottomY
    && 16 * v5 + 16 >= codec->codecParms.fullImageROILeftX
    && 16 * v5 <= codec->codecParms.fullImageROIRightX )
  {
    _R9 = bufferInfo->byteStride;
    _R31 = 128;
    _R10 = (char *)bufferInfo->buffer;
    _R27 = 16;
    v10 = (bufferInfo->macroblockIndex << 8) + 64;
    _R4 = &back_chain;
    _R7 = &v25;
    __asm { lvlx      v0, r0, r4 }
    __asm { vsplth    v0, v0, 0 }
    v13 = 4;
    _R11 = &codec->macroBlockRowBuffer0[0][v10];
    __asm { lvlx      v13, r0, r7 }
    _R7 = 2 * _R9;
    _R6 = 3 * _R9;
    __asm { vsplth    v13, v13, 0 }
    _R4 = -128;
    _R3 = -112;
    _R28 = 144;
    _R29 = 256;
    _R30 = 272;
    _R8 = vmxi_byte_mono_perm2;
    do
    {
      __asm { lvx128    v9, r0, r11 }
      _R26 = -16;
      __asm
      {
        lvx128    v12, r11, r4
        vaddshs   v5, v9, v13
        lvx128    v7, r11, r27
        vaddshs   v10, v12, v13
        lvx128    v11, r11, r3
        vaddshs   v3, v7, v13
        lvx128    v4, r11, r31
        vaddshs   v8, v11, v13
        lvx128    v2, r11, r28
        vaddshs   v1, v4, v13
        lvx128    v31, r11, r29
        vaddshs   v30, v2, v13
        lvx128    v29, r11, r30
        vaddshs   v28, v31, v13
        vaddshs   v27, v29, v13
        lvx128    v6, r0, r8
        vsrah     v11, v5, v0
        lvx128    v7, r8, r26
        vsrah     v12, v10, v0
      }
      _R11 += 16;
      __asm
      {
        vsrah     v5, v3, v0
        vsrah     v8, v8, v0
        vsrah     v10, v1, v0
        vperm128  v61, v11, v11, v7
        vsrah     v4, v30, v0
        vperm128  v63, v12, v12, v7
        vsrah     v9, v28, v0
        vperm128  v60, v5, v5, v6
        vsrah     v3, v27, v0
        vperm128  v62, v8, v8, v6
        vperm128  v59, v10, v10, v7
        vperm128  v58, v4, v4, v6
        vperm128  v57, v9, v9, v7
        vperm128  v56, v3, v3, v6
        vpkshus128 v55, v95, v62
        vpkshus128 v54, v93, v60
        vpkshus128 v53, v91, v58
        vpkshus128 v52, v89, v56
        vmrghw128 v51, v87, v53
        vmrghw128 v50, v86, v52
        vmrglw128 v49, v87, v53
        vmrglw128 v48, v86, v52
        vmrghw128 v47, v83, v50
        vmrglw128 v46, v83, v50
        vmrghw128 v45, v81, v48
        vmrglw128 v44, v81, v48
        stvx128   v47, r0, r10
        stvx128   v46, r10, r9
        stvx128   v45, r7, r10
        stvx128   v44, r6, r10
      }
      _R10 += 4 * _R9;
      --v13;
    }
    while ( v13 != 0 );
  }
  return 0;
}


// ========================================================================
// ?HDPDecOutputMB_GrayScale_Xenon_16@@YA?AW4hdpError_t@@PAUhdpCodec_t@@PBUhdpImageBufferInfo_t@@@Z
// EA  : 0x828F3588
// RVA : 0x008F3588
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdecoutputfast_xenon_16.cpp
// ========================================================================

int __fastcall HDPDecOutputMB_GrayScale_Xenon_16(hdpCodec_t *codec, const hdpImageBufferInfo_t *bufferInfo)
{
  unsigned int currentMacroblockRow; // r11
  unsigned int v5; // r10
  __int16 *v6; // r25
  int v14; // ctr
  __int16 back_chain; // [sp+0h] [-A0h] BYREF
  __int16 v38; // [sp+2h] [-9Eh] BYREF

  if ( codec == nullptr )
    return -5;
  if ( codec->codecParms.decodeFullFrame
    || (currentMacroblockRow = codec->currentMacroblockRow,
        v5 = codec->codecParms.tileMacroblockOffsetX[codec->currentTileColumn] + bufferInfo->macroblockIndex,
        16 * currentMacroblockRow >= codec->codecParms.fullImageROITopY)
    && 16 * (currentMacroblockRow - 1) <= codec->codecParms.fullImageROIBottomY
    && 16 * v5 + 16 >= codec->codecParms.fullImageROILeftX
    && 16 * v5 <= codec->codecParms.fullImageROIRightX )
  {
    v6 = codec->macroBlockRowBuffer0[0];
    _R23 = 128;
    _R9 = bufferInfo->byteStride;
    _R24 = -144;
    _R11 = (char *)bufferInfo->buffer;
    _R7 = &v38;
    _R8 = _R9 + 16;
    _R3 = &back_chain;
    __asm { lvlx      v12, r0, r7 }
    v14 = 4;
    _R27 = 3 * (_R9 + 16);
    __asm
    {
      vsplth    v12, v12, 0
      lvlx      v0, r0, r3
    }
    _R6 = 3 * _R9;
    __asm { vsplth    v13, v0, 0 }
    _R10 = &v6[256 * bufferInfo->macroblockIndex + 72];
    _R4 = _R9 + 32;
    _R3 = _R9 + 48;
    _R31 = 2 * _R9;
    _R30 = 2 * (_R9 + 8);
    _R29 = 2 * (_R9 + 24);
    _R28 = 3 * _R9 + 32;
    _R25 = -128;
    _R17 = -16;
    _R18 = 112;
    _R19 = 256;
    _R20 = 240;
    _R5 = 16;
    _R21 = 32;
    _R22 = 48;
    _R7 = vmxi_byte_255_0;
    do
    {
      __asm { lvx128    v0, r10, r25 }
      _R16 = 64;
      __asm
      {
        lvx128    v11, r10, r24
        vaddshs   v10, v0, v12
        lvx128    v9, r0, r10
        vaddshs   v8, v11, v12
        lvx128    v7, r10, r17
        vaddshs   v5, v9, v12
        lvx128    v4, r10, r23
        vaddshs   v3, v7, v12
        lvx128    v2, r10, r18
        vaddshs   v1, v4, v12
        lvx128    v31, r10, r19
        vaddshs   v30, v2, v12
        lvx128    v29, r10, r20
        vaddshs   v28, v31, v12
        vaddshs   v27, v29, v12
        lvx128    v0, r0, r7
        vsrah     v26, v10, v13
      }
      _R15 = 80;
      __asm
      {
        vsrah     v25, v8, v13
        lvx128    v6, r7, r16
        vsrah     v24, v5, v13
      }
      _R16 = 2 * _R8;
      __asm { vsrah     v23, v3, v13 }
      _R14 = &_R11[_R6];
      __asm { vsrah     v22, v1, v13 }
      _R10 += 16;
      __asm
      {
        vsrah     v21, v30, v13
        vpkshus   v11, v25, v26
        vsrah     v20, v28, v13
        lvx128    v7, r7, r15
        vsrah     v19, v27, v13
        vpkshus   v10, v23, v24
        vpkshus   v9, v21, v22
        vmrghb    v31, v11, v0
        vpkshus   v8, v19, v20
        vmrghb    v30, v10, v0
        vmrghb    v29, v9, v0
        vmrghb    v5, v11, v11
        vmrglb    v4, v11, v11
        vmrghb    v3, v10, v10
        vmrglb    v2, v10, v10
        vmrghb    v1, v9, v9
        vmrghb    v25, v8, v0
        vmrglb    v28, v9, v9
        vmrghb    v27, v8, v8
        vmrglb    v11, v11, v0
        vmrglb    v10, v10, v0
        vmrglb    v9, v9, v0
        vmrglb    v26, v8, v8
        vmrglb    v0, v8, v0
        vperm128  v63, v3, v30, v6
        vperm128  v62, v1, v29, v6
        vperm128  v61, v27, v25, v6
        vperm128  v60, v5, v31, v6
        vperm128  v59, v5, v31, v7
        vperm128  v58, v3, v30, v7
        vperm128  v57, v1, v29, v7
        vperm128  v56, v27, v25, v7
        stvx128   v63, r11, r5
        vperm128  v55, v4, v11, v7
        stvx128   v62, r11, r21
        vperm128  v54, v2, v10, v7
        stvx128   v61, r11, r22
        vperm128  v53, v28, v9, v7
        stvx128   v60, r0, r11
        vperm128  v52, v26, v0, v7
        stvx128   v59, r11, r9
        vperm128  v51, v4, v11, v6
        stvx128   v58, r8, r11
        stvx128   v57, r4, r11
        vperm128  v50, v2, v10, v6
        stvx128   v56, r3, r11
        vperm128  v49, v28, v9, v6
        stvx128   v55, r31, r11
        vperm128  v48, v26, v0, v6
        stvx128   v54, r30, r11
        stvx128   v53, r16, r11
        stvx128   v52, r29, r11
        stvx128   v51, r6, r11
        stvx128   v49, r28, r11
        stvx128   v48, r27, r11
      }
      _R11 += 4 * _R9;
      __asm { stvx128   v50, r14, r5 }
      --v14;
    }
    while ( v14 != 0 );
  }
  return 0;
}


// ========================================================================
// ?HDPDecOutputMB_RGB_Xenon_16@@YA?AW4hdpError_t@@PAUhdpCodec_t@@PBUhdpImageBufferInfo_t@@@Z
// EA  : 0x828F3840
// RVA : 0x008F3840
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdecoutputfast_xenon_16.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall HDPDecOutputMB_RGB_Xenon_16(hdpCodec_t *codec, const hdpImageBufferInfo_t *bufferInfo)
{
  unsigned int currentMacroblockRow; // r11
  unsigned int v5; // r10
  unsigned int v9; // r10
  __int16 *v10; // r5
  __int16 *v11; // r30
  __int16 *v12; // r6
  int v17; // ctr
  int v52; // [sp+0h] [-160h] BYREF
  unsigned __int64 back_chain; // [sp+8h] [-158h] BYREF
  __int64 v54; // [sp+10h] [-150h]
  unsigned __int64 v55; // [sp+18h] [-148h]
  __int64 v56; // [sp+20h] [-140h]
  unsigned __int64 v57; // [sp+28h] [-138h]
  char v58; // [sp+30h] [-130h] BYREF
  char v59; // [sp+40h] [-120h] BYREF
  char v60; // [sp+50h] [-110h] BYREF
  char v61; // [sp+60h] [-100h] BYREF
  char v62; // [sp+70h] [-F0h] BYREF
  char v63; // [sp+80h] [-E0h] BYREF
  char v64; // [sp+90h] [-D0h] BYREF
  char v65; // [sp+A0h] [-C0h] BYREF
  char v66; // [sp+B0h] [-B0h] BYREF

  if ( codec == nullptr )
    return -5;
  if ( codec->codecParms.decodeFullFrame
    || (currentMacroblockRow = codec->currentMacroblockRow,
        v5 = codec->codecParms.tileMacroblockOffsetX[codec->currentTileColumn] + bufferInfo->macroblockIndex,
        16 * currentMacroblockRow >= codec->codecParms.fullImageROITopY)
    && 16 * (currentMacroblockRow - 1) <= codec->codecParms.fullImageROIBottomY
    && 16 * v5 + 16 >= codec->codecParms.fullImageROILeftX
    && 16 * v5 <= codec->codecParms.fullImageROIRightX )
  {
    _R31 = 128;
    _R7 = bufferInfo->byteStride;
    _R11 = (char *)bufferInfo->buffer;
    v9 = bufferInfo->macroblockIndex << 8;
    v10 = codec->macroBlockRowBuffer0[0];
    v11 = codec->macroBlockRowBuffer0[1];
    v12 = codec->macroBlockRowBuffer0[2];
    HIWORD(back_chain) = !codec->codecParms.useScaledArith ? 0 : 3;
    _R26 = &back_chain;
    _R4 = _R7 + 16;
    _R25 = &v52;
    _R19 = (char *)v12 - (char *)v11;
    v17 = 4;
    _R18 = (char *)v12 - (char *)v10;
    _R8 = &v12[v9 + 128];
    __asm { lvlx      v0, r0, r26 }
    __asm { lvlx      v12, r0, r25 }
    __asm { vsplth    v13, v0, 0 }
    __asm { vsplth    v12, v12, 0 }
    _R15 = vmxi_half_0;
    _R3 = 3 * _R7;
    HIDWORD(_R23) = 3 * (_R7 + 16);
    _R9 = &v10[v9 + 72];
    _R25 = 2 * (_R7 + 8);
    _R10 = &v11[v9 + 64];
    HIDWORD(_R21) = (char *)v10 - (char *)v11;
    _R24 = 2 * (_R7 + 24);
    _R28 = _R7 + 32;
    _R27 = _R7 + 48;
    _R26 = 2 * _R7;
    LODWORD(_R23) = 3 * _R7 + 32;
    LODWORD(_R21) = 4 * _R7;
    _R17 = 0xFFFFFF90FFFFFF80uLL;
    _R5 = 16;
    _R29 = 144;
    _R30 = 256;
    _R6 = vmxi_byte_255_0;
    while ( 1 )
    {
      v56 = _R21;
      LODWORD(_R21) = 112;
      v54 = *(unsigned __int64 *)((char *)&_R23 + 4);
      HIDWORD(_R23) = 240;
      _R14 = 272;
      __asm { lvx128    v0, r0, r15 }
      back_chain = _R23;
      LODWORD(_R23) = -240;
      _R15 = 16;
      __asm
      {
        lvx128    v11, r10, r17
        lvx128    v22, r9, r21
      }
      v55 = _R17;
      __asm { lvx128    v15, r9, r22 }
      HIDWORD(_R23) = &v63;
      __asm
      {
        vaddshs   v31, v22, v12
        lvx128    v6, r10, r29
      }
      LODWORD(_R17) = -144;
      __asm
      {
        lvx128    v10, r10, r16
        lvx128    v4, r10, r14
        vsubshs   v6, v0, v6
        lvx128    v9, r0, r10
      }
      _R14 = -128;
      __asm
      {
        lvx128    v8, r10, r5
        vsubshs   v11, v0, v11
        lvx128    v7, r10, r31
        vsubshs   v10, v0, v10
        lvx128    v5, r10, r30
        vsubshs   v9, v0, v9
        vsubshs   v8, v0, v8
        stvx128   v31, r0, r22
        vsubshs   v7, v0, v7
        lvx128    v31, r8, r23
        vsubshs   v5, v0, v5
      }
      v57 = *(unsigned __int64 *)((char *)&_R17 + 4);
      __asm
      {
        vsubshs   v4, v0, v4
        lvx128    v0, r6, r15
      }
      LODWORD(_R23) = &v58;
      __asm
      {
        lvx128    v3, r9, r17
        vsrah     v22, v6, v0
      }
      _R16 = -256;
      LODWORD(_R21) = &v61;
      __asm { lvx128    v27, r9, r14 }
      _R17 = &v65;
      __asm
      {
        vaddshs   v29, v3, v12
        vsrah     v20, v5, v0
        lvx128    v26, r20, r10
        vsrah     v19, v4, v0
        lvx128    v24, r0, r9
        vsrah     v30, v11, v0
        lvx128    v2, r18, r9
        vaddshs   v23, v27, v12
        lvx128    v17, r9, r31
        lvx128    v27, r9, r30
        vaddshs   v16, v26, v12
        stvx128   v22, r0, r23
        vaddshs   v26, v24, v12
        lvx128    v1, r8, r16
        vaddshs   v17, v17, v12
        lvx128    v3, r19, r10
        vaddshs   v15, v15, v12
        lvx128    v22, r0, r8
        vaddshs   v27, v27, v12
        lvx128    v21, r8, r5
        vsubshs   v30, v29, v30
        stvx128   v20, r0, r21
        vmr128    v63, v12
        stvx128   v19, r0, r17
        vmr128    v62, v31
        vmr128    v61, v2
        lvx128    v20, r8, r31
        lvx128    v19, r8, r29
        vaddshs   v28, v1, v0
        vsrah     v25, v10, v0
        vsrah     v18, v9, v0
        vsrah     v14, v8, v0
        vsrah     v24, v7, v0
        vaddshs   v29, v3, v0
        vaddshs   v12, v22, v0
        vaddshs   v31, v31, v0
        vaddshs   v2, v2, v0
        vmr128    v60, v21
      }
      _R14 = &v62;
      __asm { vsrah     v28, v28, v0 }
      _R16 = &v59;
      __asm { vaddshs   v21, v21, v0 }
      _R15 = &v60;
      __asm
      {
        vsrah     v12, v12, v0
        stvx128   v27, r0, r14
        vsubshs   v27, v26, v14
        lvx128    v14, r0, r22
        vsubshs   v26, v14, v24
        stvx128   v29, r0, r16
        lvx128    v14, r0, r16
        vsubshs   v29, v23, v25
        lvx128    v24, r0, r21
        vsubshs   v24, v15, v24
        stvx128   v28, r0, r15
        vsrah     v15, v31, v0
        lvx128    v31, r0, r15
        lvx128    v25, r0, r23
        vsubshs   v28, v16, v18
        vsubshs   v25, v17, v25
        lvx128    v23, r0, r17
        vaddshs   v17, v20, v0
        lvx128    v18, r0, r14
        vaddshs   v16, v19, v0
      }
      _R23 = &v64;
      __asm { vsubshs   v23, v18, v23 }
      _R15 = 64;
      __asm { vsrah     v18, v14, v0 }
      _R14 = 80;
      __asm
      {
        vsrah     v14, v2, v0
        vsrah     v2, v21, v0
        vsrah     v17, v17, v0
        vsrah     v16, v16, v0
        vsubshs   v0, v12, v26
        vsubshs   v31, v31, v30
        vsubshs   v18, v18, v28
        vsubshs   v14, v14, v27
        vsubshs   v15, v15, v29
        stvx128   v0, r0, r23
        vsubshs   v0, v11, v31
        vsubshs   v17, v17, v24
        vsubshs   v11, v9, v18
        lvx128    v18, r0, r23
        vsubshs   v16, v16, v23
      }
      _R23 = &v66;
      __asm
      {
        vsubshs   v8, v8, v14
        vsubshs   v9, v7, v18
        vsubshs   v7, v10, v15
        vsubshs   v10, v5, v17
        vsubshs   v12, v2, v25
        vsubshs   v5, v4, v16
        vsrah     v15, v30, v13
        vsrah     v4, v29, v13
        vsrah     v2, v8, v13
        vsrah     v30, v26, v13
        vsubshs   v6, v6, v12
        vsrah     v26, v0, v13
        vpkshus   v4, v15, v4
        vsrah     v25, v25, v13
        stvx128   v2, r0, r23
        vsrah     v29, v7, v13
        lvx128    v59, r0, r23
        vsrah     v15, v27, v13
        vsrah     v12, v11, v13
        vsrah     v28, v28, v13
        vor128    v31, v94, v62
        vor128    v2, v93, v61
        vsrah     v16, v9, v13
        vaddshs   v18, v1, v0
        vpkshus   v1, v30, v25
        vaddshs   v22, v22, v9
        vpkshus   v9, v26, v29
        vaddshs   v17, v3, v11
        vpkshus   v3, v28, v15
        vsrah     v14, v6, v13
        vpkshus128 v30, v12, v59
        vaddshs   v27, v20, v10
        vaddshs   v26, v31, v7
        vaddshs   v25, v2, v8
        vor128    v21, v92, v60
        vaddshs   v21, v21, v6
        vmrghb    v8, v30, v3
        vaddshs   v20, v19, v5
        vmrglb    v2, v30, v3
        vsrah     v19, v10, v13
        vpkshus   v10, v16, v14
        vsrah     v3, v27, v13
        lvx128    v0, r0, r6
        vsrah     v16, v5, v13
        vmrghb    v5, v9, v4
        vsrah     v15, v23, v13
        vmrglb    v4, v9, v4
        vsrah     v14, v24, v13
        vmrghb    v29, v10, v1
        vsrah     v30, v26, v13
        vmrglb    v1, v10, v1
        vsrah     v27, v25, v13
        vpkshus   v31, v19, v16
        vsrah     v28, v17, v13
        lvx128    v7, r6, r15
        vsrah     v26, v18, v13
        vpkshus   v11, v14, v15
        vsrah     v25, v21, v13
      }
      _R15 = 32;
      __asm { vsrah     v24, v22, v13 }
      _R23 = 2 * _R4;
      __asm
      {
        vsrah     v23, v20, v13
        vpkshus   v10, v28, v27
        vpkshus   v9, v26, v30
      }
      __asm { vmrghb    v28, v31, v11 }
      _R10 += 16;
      __asm { vpkshus   v6, v24, v25 }
      _R9 += 16;
      __asm { vpkshus   v3, v3, v23 }
      _R8 += 16;
      __asm
      {
        vmrglb    v11, v31, v11
        vmrghb    v30, v10, v0
        vmrghb    v27, v9, v0
        vmrghb    v26, v6, v0
        vmrghb    v31, v3, v0
        vmrglb    v9, v9, v0
        vmrglb    v10, v10, v0
        vmrglb    v6, v6, v0
        vmrglb    v3, v3, v0
        lvx128    v0, r6, r14
        vperm128  v58, v8, v30, v7
      }
      _R14 = 48;
      __asm
      {
        vperm128  v57, v5, v27, v7
        vperm128  v56, v29, v26, v7
        vperm128  v55, v28, v31, v7
        vperm128  v54, v5, v27, v0
        vperm128  v53, v8, v30, v0
        vperm128  v52, v29, v26, v0
        vperm128  v51, v28, v31, v0
        stvx128   v58, r11, r5
        vperm128  v48, v1, v6, v0
        stvx128   v57, r0, r11
        stvx128   v56, r11, r15
        vperm128  v50, v4, v9, v0
        stvx128   v55, r11, r14
        vperm128  v49, v2, v10, v0
        stvx128   v54, r11, r7
        vperm128  v47, v11, v3, v0
        stvx128   v53, r4, r11
        vperm128  v46, v4, v9, v7
        stvx128   v52, r28, r11
        vperm128  v45, v1, v6, v7
        stvx128   v51, r27, r11
        vperm128  v44, v11, v3, v7
        stvx128   v48, r23, r11
      }
      _R23 = __PAIR64__(v54, back_chain);
      __asm { stvx128   v50, r26, r11 }
      __asm
      {
        stvx128   v49, r25, r11
        stvx128   v47, r24, r11
        vperm128  v43, v2, v10, v7
        stvx128   v46, r3, r11
        stvx128   v45, r23, r11
        stvx128   v44, r22, r11
      }
      __asm { vor128    v12, v95, v63 }
      _R21 = v56;
      LODWORD(_R17) = v55;
      *(unsigned __int64 *)((char *)&_R17 + 4) = v57;
      _R11 += v56;
      __asm { stvx128   v43, r15, r5 }
      if ( --v17 == 0 )
        break;
      _R15 = vmxi_half_0;
    }
  }
  return 0;
}


// ========================================================================
// ?HDPDecOutputMB_CoCg_Y_Xenon_16@@YA?AW4hdpError_t@@PAUhdpCodec_t@@PBUhdpImageBufferInfo_t@@@Z
// EA  : 0x828F3DB8
// RVA : 0x008F3DB8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdecoutputfast_xenon_16.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall HDPDecOutputMB_CoCg_Y_Xenon_16(hdpCodec_t *codec, const hdpImageBufferInfo_t *bufferInfo)
{
  unsigned int currentMacroblockRow; // r11
  unsigned int v5; // r10
  unsigned int v9; // r10
  __int16 *v10; // r30
  __int16 *v11; // r31
  __int16 *v12; // r3
  int v14; // ctr
  int back_chain; // [sp+0h] [-D0h] BYREF
  int v50; // [sp+4h] [-CCh] BYREF
  __int64 v51; // [sp+8h] [-C8h]
  __int64 v52; // [sp+10h] [-C0h]
  __int64 v53; // [sp+18h] [-B8h]
  __int64 v54; // [sp+20h] [-B0h]
  __int64 v55; // [sp+28h] [-A8h]

  if ( codec == nullptr )
    return -5;
  if ( codec->codecParms.decodeFullFrame
    || (currentMacroblockRow = codec->currentMacroblockRow,
        v5 = codec->codecParms.tileMacroblockOffsetX[codec->currentTileColumn] + bufferInfo->macroblockIndex,
        16 * currentMacroblockRow >= codec->codecParms.fullImageROITopY)
    && 16 * (currentMacroblockRow - 1) <= codec->codecParms.fullImageROIBottomY
    && 16 * v5 + 16 >= codec->codecParms.fullImageROILeftX
    && 16 * v5 <= codec->codecParms.fullImageROIRightX )
  {
    _R5 = 128;
    _R7 = bufferInfo->byteStride;
    _R11 = (char *)bufferInfo->buffer;
    v9 = bufferInfo->macroblockIndex << 8;
    v10 = codec->macroBlockRowBuffer0[0];
    v11 = codec->macroBlockRowBuffer0[1];
    v12 = codec->macroBlockRowBuffer0[2];
    _R6 = _R7 + 16;
    v14 = 4;
    _R26 = &back_chain;
    HIDWORD(_R22) = 3 * (_R7 + 16);
    _R17 = (char *)v12 - (char *)v11;
    _R9 = &v11[v9 + 64];
    HIDWORD(_R20) = (char *)v11 - (char *)v10;
    __asm { lvlx      v0, r0, r26 }
    _R25 = &v50;
    __asm { vsplth    v0, v0, 0 }
    _R18 = (char *)v12 - (char *)v10;
    _R8 = &v12[v9 + 136];
    __asm { lvlx      v13, r0, r25 }
    _R14 = vmxi_byte_0;
    __asm { vsplth    v13, v13, 0 }
    _R4 = 3 * _R7;
    _R10 = &v10[v9 + 72];
    _R27 = _R7 + 32;
    _R26 = _R7 + 48;
    _R25 = 2 * _R7;
    _R24 = 2 * (_R7 + 8);
    _R23 = 2 * (_R7 + 24);
    LODWORD(_R22) = 3 * _R7 + 32;
    LODWORD(_R20) = 4 * _R7;
    LODWORD(_R16) = -128;
    _R28 = -16;
    _R29 = 112;
    _R30 = 256;
    _R3 = vmxi_byte_rgba_perm2;
    _R31 = 16;
    while ( 1 )
    {
      HIDWORD(_R16) = -112;
      v51 = _R22;
      __asm { lvx128    v12, r10, r16 }
      v54 = _R16;
      _R16 = -128;
      __asm { lvx128    v10, r19, r10 }
      v53 = _R20;
      v55 = *(__int64 *)((char *)&_R20 + 4);
      _R20 = -256;
      _R19 = -272;
      v52 = *(__int64 *)((char *)&_R22 + 4);
      _R21 = 240;
      __asm
      {
        lvx128    v8, r10, r28
        lvx128    v6, r9, r16
      }
      _R15 = -144;
      _R16 = 272;
      __asm
      {
        lvx128    v27, r10, r30
        lvx128    v5, r8, r20
        vaddshs   v2, v6, v13
        lvx128    v4, r8, r19
        vaddshs   v31, v5, v13
        lvx128    v25, r10, r21
        vaddshs   v29, v4, v13
        lvx128    v1, r10, r15
        vaddshs   v20, v8, v13
        lvx128    v21, r9, r5
        vaddshs   v8, v25, v13
        lvx128    v11, r0, r10
        vaddshs   v15, v27, v13
        lvx128    v28, r10, r29
        vaddshs   v24, v1, v13
        lvx128    v19, r9, r16
        vaddshs   v25, v21, v13
        lvx128    v17, r9, r30
        vaddshs   v22, v11, v13
        lvx128    v9, r0, r9
        vaddshs   v1, v10, v13
        lvx128    v30, r10, r5
        vaddshs   v26, v12, v13
        vaddshs   v16, v28, v13
        lvx128    v14, r18, r10
        vaddshs   v21, v17, v13
        lvx128    v4, r17, r9
      }
      _R22 = -112;
      __asm
      {
        vaddshs   v18, v30, v13
        vaddshs   v28, v9, v13
        lvx128    v30, r0, r8
        vsrah     v17, v2, v0
        lvx128    v12, r0, r14
        vsrah     v11, v31, v0
        vsrah     v10, v29, v0
        lvx128    v7, r9, r22
      }
      _R22 = 144;
      __asm
      {
        vaddshs   v3, v7, v13
        vsrah     v9, v26, v0
        vsrah     v5, v24, v0
        vpkshus   v6, v10, v11
        vsrah     v2, v20, v0
        lvx128    v23, r9, r22
        vsrah     v31, v18, v0
        vaddshs   v27, v23, v13
        vaddshs   v23, v19, v13
        vpkshus   v11, v5, v9
        vsrah     v19, v3, v0
        vsrah     v3, v22, v0
        vsrah     v29, v16, v0
        vsrah     v22, v1, v0
        vpkshus   v7, v17, v19
        vsrah     v26, v15, v0
        vsrah     v24, v8, v0
        vpkshus   v10, v2, v3
        vsrah     v20, v28, v0
        vpkshus   v9, v29, v31
        vsrah     v19, v27, v0
        vmrghb    v1, v7, v6
        vsrah     v18, v25, v0
        vpkshus   v8, v24, v26
        vsrah     v17, v23, v0
        vsrah     v16, v21, v0
        vpkshus   v5, v20, v22
        lvx128    v29, r8, r28
        vaddshs   v15, v14, v13
        vaddshs   v14, v4, v13
        lvx128    v24, r8, r5
        lvx128    v22, r8, r29
        vaddshs   v2, v30, v13
        vaddshs   v23, v29, v13
        vpkshus   v4, v18, v19
        vaddshs   v21, v24, v13
        vpkshus   v3, v16, v17
        vaddshs   v20, v22, v13
      }
      _R15 = -16;
      __asm
      {
        vsrah     v31, v15, v0
        vmrghb    v27, v12, v11
        vsrah     v30, v14, v0
        vmrghb    v26, v12, v9
        vsrah     v25, v2, v0
        vmrglb    v2, v7, v6
        vsrah     v19, v23, v0
        vmrglb    v9, v12, v9
        vsrah     v18, v21, v0
        lvx128    v6, r3, r15
        vsrah     v17, v20, v0
        vpkshus   v7, v30, v31
        vmrghb    v30, v12, v10
      }
      _R14 = 32;
      __asm { vpkshus   v31, v19, v25 }
      _R15 = 48;
      __asm { vperm128  v61, v1, v27, v6 }
      _R22 = 2 * _R6;
      __asm { vpkshus   v29, v17, v18 }
      __asm { vmrghb    v28, v5, v7 }
      __asm { vmrghb    v25, v4, v31 }
      __asm { vmrglb    v4, v4, v31 }
      LODWORD(_R20) = HIDWORD(v52);
      __asm { vmrghb    v31, v3, v29 }
      _R10 += 16;
      __asm { vmrglb    v3, v3, v29 }
      _R9 += 16;
      __asm { vmrghb    v29, v12, v8 }
      _R8 += 16;
      __asm
      {
        vmrglb    v5, v5, v7
        lvx128    v7, r0, r3
        vperm128  v63, v28, v30, v6
        stvx128   v61, r0, r11
        vperm128  v62, v25, v26, v6
        vperm128  v60, v31, v29, v6
        vperm128  v59, v1, v27, v7
        vperm128  v58, v28, v30, v7
        vperm128  v57, v25, v26, v7
        vperm128  v56, v31, v29, v7
        vmrglb    v11, v12, v11
        stvx128   v63, r11, r31
        vmrglb    v10, v12, v10
        stvx128   v62, r11, r14
        vperm128  v53, v4, v9, v7
        stvx128   v60, r11, r15
        vmrglb    v12, v12, v8
        stvx128   v59, r11, r7
        vperm128  v55, v2, v11, v7
        stvx128   v58, r6, r11
        vperm128  v54, v5, v10, v7
        stvx128   v57, r27, r11
        stvx128   v56, r26, r11
        vperm128  v51, v2, v11, v6
        vperm128  v52, v3, v12, v7
        vperm128  v50, v4, v9, v6
        vperm128  v49, v3, v12, v6
        stvx128   v53, r22, r11
      }
      _R22 = v51;
      __asm
      {
        vperm128  v48, v5, v10, v6
        stvx128   v55, r25, r11
        stvx128   v54, r24, r11
        stvx128   v52, r23, r11
        stvx128   v51, r4, r11
        stvx128   v50, r22, r11
        stvx128   v49, r21, r11
      }
      _R11 += HIDWORD(v52);
      _R16 = v54;
      *(__int64 *)((char *)&_R20 + 4) = v55;
      __asm { stvx128   v48, r15, r31 }
      if ( --v14 == 0 )
        break;
      _R14 = vmxi_byte_0;
    }
  }
  return 0;
}


// ========================================================================
// ?HDPDecOutputMB_Normal_Y_X_Xenon_16@@YA?AW4hdpError_t@@PAUhdpCodec_t@@PBUhdpImageBufferInfo_t@@@Z
// EA  : 0x828F41E0
// RVA : 0x008F41E0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdecoutputfast_xenon_16.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall HDPDecOutputMB_Normal_Y_X_Xenon_16(hdpCodec_t *codec, const hdpImageBufferInfo_t *bufferInfo)
{
  unsigned int currentMacroblockRow; // r11
  unsigned int v5; // r10
  unsigned int macroblockIndex; // r7
  __int16 *v11; // r6
  __int16 *v12; // r30
  int v13; // r29
  int v14; // r28
  int v16; // ctr
  __int16 v44; // [sp+0h] [-C0h] BYREF
  __int16 back_chain; // [sp+2h] [-BEh] BYREF
  unsigned __int64 v46; // [sp+8h] [-B8h]
  __int64 v47; // [sp+10h] [-B0h]
  __int64 v48; // [sp+18h] [-A8h]

  if ( codec == nullptr )
    return -5;
  if ( codec->codecParms.decodeFullFrame
    || (currentMacroblockRow = codec->currentMacroblockRow,
        v5 = codec->codecParms.tileMacroblockOffsetX[codec->currentTileColumn] + bufferInfo->macroblockIndex,
        16 * currentMacroblockRow >= codec->codecParms.fullImageROITopY)
    && 16 * (currentMacroblockRow - 1) <= codec->codecParms.fullImageROIBottomY
    && 16 * v5 + 16 >= codec->codecParms.fullImageROILeftX
    && 16 * v5 <= codec->codecParms.fullImageROIRightX )
  {
    _R8 = bufferInfo->byteStride;
    _R31 = 128;
    macroblockIndex = bufferInfo->macroblockIndex;
    _R11 = (char *)bufferInfo->buffer;
    _R26 = &back_chain;
    v11 = codec->macroBlockRowBuffer0[1];
    v12 = codec->macroBlockRowBuffer0[0];
    v13 = (macroblockIndex << 8) + 72;
    v14 = (macroblockIndex << 8) + 64;
    _R7 = _R8 + 16;
    v16 = 4;
    _R3 = &v44;
    _R5 = 3 * _R8;
    __asm { lvlx      v12, r0, r26 }
    __asm { vsplth    v12, v12, 0 }
    __asm { lvlx      v0, r0, r3 }
    _R23 = 3 * (_R8 + 16);
    _R9 = &v11[v14];
    __asm { vsplth    v13, v0, 0 }
    _R10 = &v12[v13];
    _R30 = (char *)v11 - (char *)v12;
    _R26 = 2 * (_R8 + 8);
    _R25 = 2 * (_R8 + 24);
    _R29 = _R8 + 32;
    _R28 = _R8 + 48;
    _R27 = 2 * _R8;
    _R24 = 3 * _R8 + 32;
    LODWORD(_R22) = 4 * _R8;
    HIDWORD(_R22) = -128;
    _R20 = 0x30FFFFFF70LL;
    _R3 = 256;
    _R6 = vmxi_byte_255_0;
    _R16 = 144;
    _R17 = 272;
    _R4 = 16;
    _R18 = 32;
    do
    {
      _R15 = -16;
      __asm { lvx128    v0, r10, r21 }
      _R14 = 112;
      __asm
      {
        lvx128    v11, r10, r20
        vaddshs   v6, v11, v12
      }
      v47 = *(unsigned __int64 *)((char *)&_R22 + 4);
      __asm { vaddshs   v8, v0, v12 }
      HIDWORD(_R22) = 240;
      v48 = _R20;
      __asm { lvx128    v10, r0, r10 }
      v46 = _R22;
      __asm
      {
        lvx128    v7, r10, r15
        lvx128    v5, r10, r14
      }
      _R20 = -112;
      LODWORD(_R22) = -128;
      __asm
      {
        lvx128    v9, r10, r31
        vaddshs   v4, v10, v12
        lvx128    v31, r10, r21
        vaddshs   v3, v7, v12
        lvx128    v2, r10, r3
        vaddshs   v30, v5, v12
        lvx128    v26, r30, r10
        vsrah     v27, v8, v13
        lvx128    v29, r9, r20
        vaddshs   v1, v9, v12
        lvx128    v28, r9, r22
        vsrah     v25, v6, v13
        lvx128    v24, r0, r9
        lvx128    v22, r9, r16
        vsrah     v17, v30, v13
        lvx128    v20, r9, r31
        vsrah     v23, v4, v13
        lvx128    v18, r9, r17
        vsrah     v21, v3, v13
        lvx128    v16, r9, r3
        vaddshs   v14, v31, v12
        vpkshus   v11, v25, v27
        vaddshs   v8, v29, v12
        vaddshs   v7, v28, v12
        lvx128    v0, r0, r6
        vsrah     v19, v1, v13
        vpkshus   v10, v21, v23
        vaddshs   v31, v26, v12
      }
      _R15 = 64;
      __asm
      {
        vaddshs   v30, v24, v12
        vmrghb    v6, v0, v11
        vaddshs   v15, v2, v12
        vmrglb    v5, v0, v11
        vaddshs   v29, v22, v12
        vpkshus   v9, v17, v19
        vaddshs   v28, v20, v12
        vmrghb    v4, v0, v10
        vaddshs   v27, v18, v12
        vmrglb    v3, v0, v10
        vaddshs   v26, v16, v12
      }
      _R14 = 80;
      __asm
      {
        vsrah     v23, v8, v13
        vmrghb    v2, v0, v9
        vsrah     v22, v7, v13
        vmrglb    v1, v0, v9
        vsrah     v21, v31, v13
        vsrah     v20, v30, v13
        vsrah     v25, v15, v13
        vsrah     v24, v14, v13
        vpkshus   v11, v22, v23
        vsrah     v19, v29, v13
        vsrah     v18, v28, v13
        vpkshus   v10, v20, v21
        vsrah     v17, v27, v13
        vsrah     v16, v26, v13
        vpkshus   v8, v24, v25
        vmrghb    v27, v0, v11
        vpkshus   v9, v18, v19
        vmrghb    v30, v0, v10
        vpkshus   v7, v16, v17
        vmrghb    v31, v0, v8
        vmrghb    v29, v0, v9
        vmrglb    v8, v0, v8
        vmrghb    v28, v0, v7
        vmrglb    v11, v0, v11
        vmrglb    v10, v0, v10
        vmrglb    v26, v0, v7
        lvx128    v7, r6, r14
        vmrglb    v9, v0, v9
        lvx128    v0, r6, r15
        vperm128  v59, v27, v6, v7
      }
      _R15 = 2 * _R7;
      __asm { vperm128  v63, v30, v4, v0 }
      _R14 = &_R11[_R5];
      __asm { vperm128  v62, v29, v2, v0 }
      _R22 = __PAIR64__(v47, v46);
      __asm { vperm128  v61, v28, v31, v0 }
      __asm { vperm128  v60, v27, v6, v0 }
      _R20 = v48;
      __asm { vperm128  v58, v30, v4, v7 }
      _R10 += 16;
      __asm { vperm128  v57, v29, v2, v7 }
      _R9 += 16;
      __asm
      {
        vperm128  v56, v28, v31, v7
        vperm128  v55, v11, v5, v7
        stvx128   v63, r11, r4
        vperm128  v54, v10, v3, v7
        stvx128   v62, r11, r18
        vperm128  v53, v9, v1, v7
        stvx128   v61, r11, r19
        vperm128  v52, v26, v8, v7
        stvx128   v60, r0, r11
        vperm128  v51, v11, v5, v0
        stvx128   v59, r11, r8
        vperm128  v50, v9, v1, v0
        stvx128   v58, r7, r11
        vperm128  v49, v26, v8, v0
        stvx128   v57, r29, r11
        vperm128  v48, v10, v3, v0
        stvx128   v56, r28, r11
        stvx128   v55, r27, r11
        stvx128   v54, r26, r11
        stvx128   v53, r15, r11
        stvx128   v52, r25, r11
        stvx128   v51, r5, r11
        stvx128   v50, r24, r11
        stvx128   v49, r23, r11
      }
      _R11 += v46;
      __asm { stvx128   v48, r14, r4 }
      --v16;
    }
    while ( v16 != 0 );
  }
  return 0;
}


// ========================================================================
// ?HDPDecOutputMBRowFast_Xenon_16@@YA?AW4hdpError_t@@PAUhdpCodec_t@@PBUhdpImageBufferInfo_t@@@Z
// EA  : 0x828F4548
// RVA : 0x008F4548
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdecoutputfast_xenon_16.cpp
// ========================================================================

int __fastcall HDPDecOutputMBRowFast_Xenon_16(hdpCodec_t *codec, const hdpImageBufferInfo_t *bufferInfo)
{
  void *buffer; // r9
  unsigned int lineCount; // r7
  unsigned int v6; // r31
  unsigned int macroblockIndex; // r6
  unsigned int byteStride; // r5
  unsigned int bitsPerUnit; // r4
  unsigned __int32 v10; // r10
  unsigned int v11; // r28
  unsigned int imageWidth; // r11
  char *v13; // r27
  unsigned int v14; // r29
  char *v15; // r27
  unsigned int v16; // r29
  char *v17; // r27
  unsigned int v18; // r29
  char *v19; // r27
  unsigned int v20; // r29
  char *v21; // r27
  unsigned int v22; // r29
  hdpImageBufferInfo_t v23[4]; // [sp+50h] [-40h] BYREF

  if ( codec == nullptr )
    return -5;
  buffer = bufferInfo->buffer;
  lineCount = bufferInfo->lineCount;
  v6 = 0;
  macroblockIndex = bufferInfo->macroblockIndex;
  byteStride = bufferInfo->byteStride;
  bitsPerUnit = codec->imageInfo.bitsPerUnit;
  v10 = codec->imageInfo.colorFormat - 7;
  v23[0].buffer = buffer;
  v23[0].lineCount = lineCount;
  v11 = (2 * bitsPerUnit) & 0xFFFFFFF0;
  v23[0].macroblockIndex = macroblockIndex;
  v23[0].byteStride = byteStride;
  imageWidth = codec->imageInfo.imageWidth;
  v23[0].macroblockIndex = 0;
  if ( v10 > 6 )
    return 0;
  if ( v10 != 0 )
  {
    switch ( v10 )
    {
      case 1u:
      case 2u:
        return 0;
      case 3u:
        if ( imageWidth == 0 )
          return 0;
        v13 = (char *)v23[0].buffer;
        v14 = ((imageWidth - 1) >> 4) + 1;
        do
        {
          HDPDecOutputMB_Mono_Xenon_16(codec, bufferInfo: v23);
          v13 += v11;
          ++v6;
          --v14;
          v23[0].buffer = v13;
          v23[0].macroblockIndex = v6;
        }
        while ( v14 != 0 );
        return 0;
      case 4u:
        if ( imageWidth == 0 )
          return 0;
        v15 = (char *)v23[0].buffer;
        v16 = ((imageWidth - 1) >> 4) + 1;
        do
        {
          HDPDecOutputMB_GrayScale_Xenon_16(codec, bufferInfo: v23);
          v15 += v11;
          ++v6;
          --v16;
          v23[0].buffer = v15;
          v23[0].macroblockIndex = v6;
        }
        while ( v16 != 0 );
        return 0;
      case 5u:
        if ( imageWidth != 0 )
        {
          v19 = (char *)v23[0].buffer;
          v20 = ((imageWidth - 1) >> 4) + 1;
          do
          {
            HDPDecOutputMB_CoCg_Y_Xenon_16(codec, bufferInfo: v23);
            v19 += v11;
            ++v6;
            --v20;
            v23[0].buffer = v19;
            v23[0].macroblockIndex = v6;
          }
          while ( v20 != 0 );
          return 0;
        }
        return 0;
      default:
        if ( imageWidth != 0 )
        {
          v21 = (char *)v23[0].buffer;
          v22 = ((imageWidth - 1) >> 4) + 1;
          do
          {
            HDPDecOutputMB_Normal_Y_X_Xenon_16(codec, bufferInfo: v23);
            v21 += v11;
            ++v6;
            --v22;
            v23[0].buffer = v21;
            v23[0].macroblockIndex = v6;
          }
          while ( v22 != 0 );
        }
        return 0;
    }
  }
  else
  {
    if ( imageWidth == 0 )
      return 0;
    v17 = (char *)v23[0].buffer;
    v18 = ((imageWidth - 1) >> 4) + 1;
    do
    {
      HDPDecOutputMB_RGB_Xenon_16(codec, bufferInfo: v23);
      v17 += v11;
      ++v6;
      --v18;
      v23[0].buffer = v17;
      v23[0].macroblockIndex = v6;
    }
    while ( v18 != 0 );
    return 0;
  }
}

