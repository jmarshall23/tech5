
// ========================================================================
// ?DecodeBasePoseRST@idMD6Blend@@CAXIPIBM00PIAM11@Z
// EA  : 0x8281B6F0
// RVA : 0x0081B6F0
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMD6Blend::DecodeBasePoseRST(
        unsigned int numJoints,
        __int64 inS,
        const float *inT,
        float *outR,
        float *outS,
        float *outT)
{
  unsigned int v7; // ctr
  int back_chain; // [sp+0h] [-110h]
  int v46; // [sp+38h] [-D8h]
  int v47; // [sp+3Ch] [-D4h]
  int v48; // [sp+44h] [-CCh]
  char *v49; // [sp+48h] [-C8h]
  int v50; // [sp+4Ch] [-C4h]
  __int64 v51; // [sp+50h] [-C0h]
  __int64 v52; // [sp+58h] [-B8h]
  __int64 v53; // [sp+60h] [-B0h]
  __int64 v54; // [sp+70h] [-A0h]

  if ( numJoints != 0 )
  {
    back_chain = 112 - (_DWORD)outR;
    v7 = ((numJoints - 1) >> 3) + 1;
    v46 = HIDWORD(inS) - (_DWORD)outR;
    v47 = (char *)outS - (char *)outR;
    LODWORD(_R30) = outT + 20;
    v48 = (char *)outT - (char *)outR;
    v49 = (char *)outT - HIDWORD(inS);
    v50 = (char *)outT - (char *)outS;
    _R9 = vmxi_word_mask_clear_last;
    _R31 = outS + 16;
    HIDWORD(_R11) = outR + 4;
    __asm { lvx128    v63, r0, r9 }
    _R15 = -48;
    HIDWORD(_R30) = inS;
    LODWORD(_R11) = inT + 12;
    _R3 = HIDWORD(inS) + 48;
    _R7 = 16;
    _R8 = 32;
    _R17 = 48;
    _R16 = 64;
    do
    {
      _R9 = back_chain + HIDWORD(_R11);
      __asm
      {
        dcbt      r9, r4
        dcbt      r9, r5
        dcbt      r9, r6
      }
      _R26 = inS - (_DWORD)inT;
      _R14 = -48;
      __asm { lvx128    v62, r0, r29 }
      __asm { vand128   v50, v94, v63 }
      __asm
      {
        lvx128    v39, r0, r3
        lvx128    v61, r11, r26
      }
      _R26 = _R11 + -24 - (_DWORD)inT;
      _R25 = _R11 + 4 - (_DWORD)inT;
      _R24 = _R11 + -12 - (_DWORD)inT;
      _R23 = _R11 + 28 - (_DWORD)inT;
      _R22 = 12 - (_DWORD)inT + _R11;
      _R21 = 40 - (_DWORD)inT + _R11;
      __asm { lvx128    v60, r3, r14 }
      __asm { lvlx128   v56, r26, r5 }
      _R9 = _R11 + -20 - (_DWORD)inT;
      _R28 = _R11 + -36 - (_DWORD)inT;
      _R20 = 24 - (_DWORD)inT + _R11;
      _R19 = 52 - (_DWORD)inT + _R11;
      __asm { lvrx128   v55, r25, r5 }
      _R27 = _R11 + -8 - (_DWORD)inT;
      __asm
      {
        lvlx128   v54, r24, r5
        lvrx128   v59, r9, r5
      }
      v54 = inS;
      __asm { lvlx128   v58, r28, r5 }
      __asm { lvrx128   v53, r23, r5 }
      HIDWORD(inS) = -16;
      __asm
      {
        lvlx128   v52, r22, r5
        vor128    v48, v90, v59
        lvrx128   v57, r27, r5
        vor128    v45, v86, v55
        lvrx128   v51, r21, r5
        vor128    v47, v88, v57
        lvlx128   v49, r20, r5
        vor128    v43, v84, v53
        lvrx128   v46, r19, r5
        vor128    v41, v81, v51
      }
      v53 = *(__int64 *)((char *)&_R30 + 4);
      __asm { vand128   v38, v93, v63 }
      v52 = _R30;
      __asm { lvx128    v40, r3, r4 }
      v51 = _R11;
      __asm
      {
        lvx128    v37, r3, r7
        lvx128    v35, r3, r8
      }
      __asm { lvx128    v33, r3, r17 }
      _R30 = 96;
      __asm
      {
        lvx128    v62, r3, r16
        vand128   v36, v80, v63
        vand128   v34, v79, v63
        vand128   v32, v77, v63
        vand128   v61, v75, v63
      }
      __asm { vand128   v59, v73, v63 }
      _R14 = -16;
      _R18 = 36 - (_DWORD)inT + _R11;
      LODWORD(_R11) = -64;
      __asm
      {
        stvx128   v60, r10, r14
        lvlx128   v44, r18, r5
      }
      _R5 = v46;
      __asm
      {
        lvx128    v42, r5, r10
        stvx128   v50, r31, r11
      }
      _R11 = v51;
      __asm
      {
        lvrx128   v57, r9, r6
        vor128    v58, v76, v46
        lvlx128   v56, r28, r6
      }
      _R9 = v47;
      __asm
      {
        lvrx128   v55, r27, r6
        vor128    v54, v88, v57
        lvlx128   v53, r26, r6
      }
      __asm
      {
        lvrx128   v52, r25, r6
        vor128    v51, v85, v55
        lvlx128   v50, r24, r6
      }
      _R27 = v48;
      __asm
      {
        lvrx128   v49, r23, r6
        vor128    v48, v82, v52
        lvlx128   v47, r22, r6
      }
      _R26 = v49;
      __asm
      {
        lvrx128   v46, r21, r6
        vor128    v45, v79, v49
        lvlx128   v44, r20, r6
      }
      _R25 = v50;
      __asm { lvrx128   v43, r19, r6 }
      _R24 = -32;
      __asm { lvlx128   v41, r18, r6 }
      _R23 = -80;
      __asm
      {
        stvx128   v42, r0, r10
        vor128    v42, v76, v46
        stvx128   v40, r10, r7
        vor128    v40, v73, v43
        stvx128   v39, r10, r8
        vand128   v60, v83, v63
        stvx128   v37, r10, r17
        vand128   v56, v77, v63
        lvx128    v39, r11, r15
        vand128   v55, v74, v63
        lvx128    v37, r0, r11
      }
      __asm { stvx128   v62, r10, r30 }
      _R30 = v52;
      __asm
      {
        stvx128   v35, r10, r16
        vand128   v35, v90, v63
        stvx128   v33, r10, r29
        vand128   v62, v86, v63
        vand128   v33, v71, v63
      }
      _R28 = HIDWORD(v53);
      __asm
      {
        vand128   v58, v80, v63
        stvx128   v36, r9, r10
        vand128   v57, v69, v63
        stvx128   v34, r31, r24
        vand128   v54, v72, v63
        stvx128   v32, r3, r28
        stvx128   v38, r0, r31
      }
      inS = v54;
      __asm { stvx128   v61, r31, r7 }
      HIDWORD(_R30) = v53 + 96;
      __asm { stvx128   v59, r31, r8 }
      LODWORD(_R11) = v51 + 96;
      __asm
      {
        stvx128   v35, r31, r17
        stvx128   v33, r30, r23
        stvx128   v62, r27, r10
      }
      HIDWORD(_R11) = HIDWORD(v51) + 128;
      __asm
      {
        stvx128   v60, r30, r15
        stvx128   v58, r3, r26
      }
      _R3 += 128;
      __asm { stvx128   v57, r31, r25 }
      _R31 += 32;
      __asm
      {
        stvx128   v56, r0, r30
        stvx128   v55, r30, r7
        stvx128   v54, r30, r8
      }
      LODWORD(_R30) = v52 + 128;
      --v7;
    }
    while ( v7 != 0 );
  }
}


// ========================================================================
// ?DecodeBasePoseU@idMD6Blend@@SAXIPIBMPIAM@Z
// EA  : 0x8281BA48
// RVA : 0x0081BA48
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::DecodeBasePoseU(unsigned int numUserChannels, const float *inU, float *outU)
{
  unsigned int v8; // ctr

  _R10 = inU;
  if ( numUserChannels != 0 )
  {
    _R8 = (char *)inU - (char *)outU;
    _R11 = outU + 4;
    _R7 = -16;
    v8 = ((numUserChannels - 1) >> 3) + 1;
    do
    {
      __asm
      {
        lvx128    v63, r8, r11
        lvx128    v62, r0, r10
      }
      _R10 += 8;
      __asm
      {
        stvx128   v62, r11, r7
        stvx128   v63, r0, r11
      }
      _R11 += 8;
      --v8;
    }
    while ( v8 != 0 );
  }
}


// ========================================================================
// ?DecodeConstantR@idMD6Blend@@CAXPIBEIPIBFPIAM@Z
// EA  : 0x8281BA90
// RVA : 0x0081BA90
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::DecodeConstantR(
        const unsigned __int8 *jointsR,
        unsigned int numJointsR,
        const __int16 *inR,
        float *outR)
{
  unsigned int v6; // ctr
  int v9; // r10
  unsigned int v22; // ctr

  _R10 = 128;
  if ( 6 * numJointsR > 0x80 )
  {
    v6 = ((6 * numJointsR - 129) >> 7) + 1;
    do
    {
      __asm { dcbt      r10, r5 }
      _R10 += 128;
      --v6;
    }
    while ( v6 != 0 );
  }
  _R9 = 4;
  _R29 = &quatScale;
  v9 = 0;
  __asm
  {
    lvlx128   v63, r0, r29
    lvlx128   v62, r29, r9
    vspltw128 v8, v63, 0
    vspltw128 v7, v62, 0
  }
  if ( numJointsR != 0 )
  {
    _R28 = 432;
    _R27 = 544;
    _R26 = 560;
    _R25 = 96;
    _R24 = 112;
    _R23 = 128;
    __asm { lvx128    v57, r29, r28 }
    __asm
    {
      lvx128    v5, r29, r27
      lvx128    v56, r29, r26
    }
    _R28 = 144;
    __asm { lvx128    v61, r29, r25 }
    __asm { lvx128    v60, r29, r24 }
    _R27 = 160;
    __asm { lvx128    v59, r29, r23 }
    _R26 = 176;
    _R25 = 192;
    _R24 = 304;
    __asm { lvx128    v58, r29, r28 }
    _R23 = 320;
    v22 = ((numJointsR - 1) >> 2) + 1;
    _R11 = 22;
    __asm
    {
      lvx128    v55, r29, r27
      lvx128    v13, r29, r26
    }
    __asm { lvx128    v62, r29, r25 }
    __asm { lvx128    v54, r29, r24 }
    __asm { lvx128    v53, r29, r23 }
    _R9 = 16;
    _R8 = 0;
    _R7 = 6;
    do
    {
      __asm { lvrx128   v51, r9, r5 }
      _R29 = _R11 + 6;
      __asm { lvlx128   v50, r8, r5 }
      _R9 = _R11 + 12;
      _R8 = _R11 - 4;
      __asm { lvlx128   v49, r7, r5 }
      _R28 = _R11 - 10;
      __asm
      {
        lvrx128   v52, r11, r5
        vor128    v48, v82, v51
      }
      __asm
      {
        lvrx128   v47, r29, r5
        vor128    v46, v81, v52
        lvrx128   v44, r9, r5
      }
      __asm { lvlx128   v42, r8, r5 }
      __asm
      {
        lvlx128   v45, r28, r5
        vor128    v40, v74, v44
        vor128    v43, v77, v47
      }
      _R8 = __ROL4__(jointsR[v9 + 3], 4);
      __asm { vand128   v41, v80, v62 }
      _R7 = __ROL4__(jointsR[v9 + 2], 4);
      __asm { vand128   v39, v78, v62 }
      _R9 = __ROL4__(jointsR[v9 + 1], 4);
      __asm
      {
        vand128   v35, v72, v62
        vmrghw128 v34, v78, v40
        vand128   v38, v75, v62
        vmrghw128 v37, v80, v43
        vupkhsh128 v36, v41
      }
      __asm { vupkhsh128 v33, v39 }
      _R11 += 24;
      __asm { vupkhsh128 v63, v35 }
      _R29 = __ROL4__(jointsR[v9], 4);
      __asm
      {
        vupkhsh128 v32, v38
        vcsxwfp128 v0, v36, 0
        vmrghw128 v52, v69, v34
        vcsxwfp128 v10, v33, 0
        vcsxwfp128 v12, v63, 0
        vcsxwfp128 v9, v32, 0
        vand128   v51, v84, v55
        vsrw128   v50, v83, v53
        vsrw128   v49, v83, v54
        vmaddfp   v11, v0, v7, v8
        vmaddfp   v10, v10, v7, v8
        vor128    v0, v81, v50
        vmaddfp   v12, v12, v7, v8
        vmaddfp   v9, v9, v7, v8
        vspltb    v4, v0, 0xB
        vspltb    v6, v0, 0xF
        vspltb    v3, v0, 7
        vspltb    v2, v0, 3
        vaddubm   v0, v4, v13
        vaddubm   v1, v6, v13
        vaddubm   v6, v3, v13
        vmsum3fp128 v48, v11, v11
        vaddubm   v4, v2, v13
        vmsum3fp128 v47, v10, v10
        vperm128  v2, v91, v59, v0
        vmsum3fp128 v45, v12, v12
        vperm128  v3, v90, v58, v1
        vmsum3fp128 v46, v9, v9
        vperm128  v1, v92, v60, v6
        vperm128  v4, v93, v61, v4
        vmrghw128 v43, v79, v45
        vmrghw128 v44, v80, v46
        vmrghw128 v42, v76, v43
        vsubfp128 v0, v89, v42
        vrsqrtefp128 v41, v0
        vmulfp128 v6, v73, v41
        vmulfp128 v40, v73, v56
        vmaddfp   v6, v0, v5, v6
        vmulfp128 v39, v72, v6
        vmulfp128 v63, v71, v0
        vperm128  v38, v12, v63, v3
        vperm128  v37, v9, v63, v2
        vperm128  v36, v10, v63, v1
        vperm128  v35, v11, v63, v4
        stvx128   v38, r8, r6
        stvx128   v37, r7, r6
        stvx128   v36, r9, r6
      }
      v9 += 4;
      __asm { stvx128   v35, r29, r6 }
      _R9 = _R11 - 6;
      _R8 = _R11 - 22;
      _R7 = _R11 - 16;
      --v22;
    }
    while ( v22 != 0 );
  }
}


// ========================================================================
// ?DecodeConstantST@idMD6Blend@@CAXPIBEIPIBMPIAM@Z
// EA  : 0x8281BCE0
// RVA : 0x0081BCE0
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::DecodeConstantST(
        const unsigned __int8 *joints,
        unsigned int numJoints,
        const float *in,
        float *out)
{
  unsigned int v6; // ctr
  int v7; // r10
  unsigned int v10; // ctr

  _R10 = 128;
  if ( 12 * numJoints > 0x80 )
  {
    v6 = ((12 * numJoints - 129) >> 7) + 1;
    do
    {
      __asm { dcbt      r10, r5 }
      _R10 += 128;
      --v6;
    }
    while ( v6 != 0 );
  }
  v7 = 0;
  if ( numJoints != 0 )
  {
    _R11 = 36;
    _R9 = 52;
    v10 = ((numJoints - 1) >> 2) + 1;
    _R31 = vmxi_word_mask_clear_last;
    __asm { lvx128    v63, r0, r31 }
    do
    {
      __asm { lvrx128   v62, r9, r5 }
      _R31 = _R11 + 4;
      _R9 = _R11 - 12;
      __asm { lvlx128   v61, r11, r5 }
      _R30 = _R11 - 8;
      __asm { vor128    v60, v93, v62 }
      _R29 = _R11 - 24;
      _R27 = _R11 - 20;
      _R25 = _R11 - 36;
      __asm
      {
        lvrx128   v59, r31, r5
        lvlx128   v58, r9, r5
      }
      __asm
      {
        lvrx128   v57, r30, r5
        vor128    v56, v90, v59
        lvlx128   v55, r29, r5
      }
      __asm
      {
        lvrx128   v54, r27, r5
        vor128    v53, v87, v57
        lvlx128   v52, r25, r5
      }
      _R30 = __ROL4__(joints[v7 + 3], 4);
      __asm { vor128    v51, v84, v54 }
      _R29 = __ROL4__(joints[v7 + 2], 4);
      __asm { vand128   v50, v92, v63 }
      _R28 = __ROL4__(joints[v7 + 1], 4);
      __asm { vand128   v49, v88, v63 }
      _R31 = __ROL4__(joints[v7], 4);
      __asm { vand128   v48, v85, v63 }
      _R11 += 48;
      __asm { vand128   v47, v83, v63 }
      v7 += 4;
      __asm { stvx128   v50, r30, r6 }
      _R9 = _R11 + 16;
      __asm
      {
        stvx128   v49, r29, r6
        stvx128   v48, r28, r6
        stvx128   v47, r31, r6
      }
      --v10;
    }
    while ( v10 != 0 );
  }
}


// ========================================================================
// ?DecodeConstantU@idMD6Blend@@SAXPIBEIPIBMPIAM@Z
// EA  : 0x8281BDF8
// RVA : 0x0081BDF8
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::DecodeConstantU(
        const unsigned __int8 *channelsU,
        unsigned int numUserChannels,
        const float *inU,
        float *outU)
{
  int v4; // r10
  unsigned int v7; // ctr

  v4 = 0;
  if ( numUserChannels != 0 )
  {
    _R11 = 8;
    _R9 = 12;
    v7 = ((numUserChannels - 1) >> 2) + 1;
    do
    {
      __asm { lvewx128  v63, r9, r5 }
      _R9 = _R11 - 4;
      _R31 = __ROL4__(channelsU[v4 + 3], 2);
      _R30 = _R11 - 8;
      __asm { stvewx128 v63, r6, r31 }
      __asm { lvewx128  v62, r11, r5 }
      _R31 = __ROL4__(channelsU[v4 + 2], 2);
      __asm { stvewx128 v62, r6, r31 }
      __asm { lvewx128  v61, r9, r5 }
      _R9 = __ROL4__(channelsU[v4 + 1], 2);
      __asm { stvewx128 v61, r6, r9 }
      __asm { lvewx128  v60, r30, r5 }
      _R9 = __ROL4__(channelsU[v4], 2);
      _R11 += 16;
      __asm { stvewx128 v60, r6, r9 }
      v4 += 4;
      _R9 = _R11 + 4;
      --v7;
    }
    while ( v7 != 0 );
  }
}


// ========================================================================
// ?CountLeadingZeros32x4@@YA?AU__vector4@@ABU1@@Z
// EA  : 0x8281BE98
// RVA : 0x0081BE98
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

__vector4 *__fastcall CountLeadingZeros32x4(__vector4 *result, const __vector4 *bits)
{
  int v9; // [sp+0h] [-30h] BYREF
  _DWORD back_chain[4]; // [sp+10h] [-20h] BYREF
  _DWORD v11[4]; // [sp+20h] [-10h] BYREF

  __asm { lvx128    v63, r0, r3 }
  _R3 = (__vector4 *)back_chain;
  _R11 = v11;
  back_chain[0] = 1199570943;
  back_chain[1] = 1199570943;
  _R5 = &v9;
  back_chain[2] = 1199570943;
  back_chain[3] = 1199570943;
  __asm { lvx128    v12, r0, r3 }
  _R10 = v11;
  _R6 = v11;
  __asm { lvx128    v59, r0, r5 }
  __asm { vsrw128   v58, v95, v59 }
  __asm { lvx128    v62, r0, r11 }
  _R7 = v11;
  __asm { vcuxwfp128 v9, v58, 0 }
  __asm { lvx128    v0, r0, r6 }
  __asm
  {
    lvx128    v61, r0, r10
    vand128   v60, v95, v61
  }
  v11[0] = 1333788671;
  __asm { vcuxwfp128 v13, v60, 0 }
  v11[1] = 1333788671;
  v11[2] = 1333788671;
  __asm { vsubuwm   v8, v12, v9 }
  v11[3] = 1333788671;
  __asm
  {
    lvx128    v11, r0, r7
    vsubuwm   v10, v11, v13
    vminuw    v7, v8, v10
    vsrw128   v6, v7, v62
    vminuw    v1, v6, v0
  }
  return _R3;
}


// ========================================================================
// ?CountBitsSet64x4@@YA?AU__vector4@@ABU1@0@Z
// EA  : 0x8281BF78
// RVA : 0x0081BF78
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

__vector4 *__fastcall CountBitsSet64x4(__vector4 *result, const __vector4 *bits1, const __vector4 *bits2)
{
  int back_chain; // [sp+0h] [-10h] BYREF

  __asm { lvx128    v63, r0, r4 }
  _R10 = &back_chain;
  __asm { lvx128    v62, r0, r3 }
  _R9 = &back_chain;
  __asm
  {
    vspltisb  v0, 4
    vmrghw128 v61, v94, v63
  }
  _R5 = &back_chain;
  __asm { vmrglw128 v60, v94, v63 }
  __asm { lvx128    v59, r0, r10 }
  __asm { vmrghw128 v6, v93, v60 }
  __asm { vmrglw128 v7, v93, v60 }
  __asm { lvx128    v58, r0, r9 }
  __asm { vsrb      v5, v6, v0 }
  _R4 = &back_chain;
  __asm { vsrb      v4, v7, v0 }
  __asm
  {
    lvx128    v63, r0, r5
    vperm128  v3, v95, v63, v5
  }
  __asm { vperm128  v2, v95, v63, v6 }
  __asm
  {
    lvx128    v63, r0, r4
    vperm128  v1, v95, v63, v4
    vperm128  v31, v95, v63, v7
    vadduwm   v0, v2, v3
    vadduwm   v13, v31, v1
    vsldoi    v30, v0, v0, v15
    vsldoi    v29, v13, v13, v15
    vadduwm   v0, v0, v30
    vadduwm   v13, v13, v29
    vsldoi    v28, v0, v0, v14
    vsldoi    v27, v13, v13, v14
    vadduwm   v26, v0, v28
    vadduwm   v25, v13, v27
    vand128   v24, v26, v58
    vand128   v23, v25, v59
    vadduwm   v1, v23, v24
  }
  return result;
}


// ========================================================================
// ?DecodeFrameOffsets@idMD6Blend@@CAIIIIIPIBX00PIBEAAUframeOffsets_t@1@I@Z
// EA  : 0x8281C060
// RVA : 0x0081C060
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

unsigned int __fastcall idMD6Blend::DecodeFrameOffsets(
        unsigned int numJoints,
        unsigned int frame,
        unsigned int numFrames,
        unsigned int stride,
        const void *firstKeys,
        const void *rangeKeys,
        const void *nextKeys,
        const unsigned __int8 *frameBits,
        idMD6Blend::frameOffsets_t *offsets,
        unsigned int pad,
        int a11,
        int a12,
        int a13,
        unsigned int a14,
        int a15,
        unsigned int a16,
        int a17,
        unsigned int a18,
        int a19,
        const void *a20,
        int a21,
        const void *a22,
        int a23,
        const void *a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30)
{
  unsigned int v49; // r17
  unsigned int v52; // r28
  int v56; // r25
  const __vector4 *v80; // r5
  const __vector4 *v81; // r5
  int v91; // r4
  unsigned int v92; // r10
  unsigned int v93; // r11
  int v94; // r5
  _BYTE *v95; // r9
  int v96; // r7
  int v97; // r6
  _WORD *v98; // r10
  __vector4 v100; // [sp+60h] [-240h] BYREF
  __vector4 v101; // [sp+70h] [-230h] BYREF
  __vector4 v102; // [sp+80h] [-220h] BYREF
  __vector4 v103; // [sp+90h] [-210h] BYREF
  __vector4 v104; // [sp+A0h] [-200h] BYREF
  _DWORD v105[4]; // [sp+B0h] [-1F0h] BYREF
  __vector4 v106; // [sp+C0h] [-1E0h] BYREF
  _BYTE v107[16]; // [sp+D0h] [-1D0h] BYREF
  _BYTE v108[16]; // [sp+E0h] [-1C0h] BYREF
  _BYTE v109[16]; // [sp+F0h] [-1B0h] BYREF
  _BYTE v110[16]; // [sp+100h] [-1A0h] BYREF
  _BYTE v111[256]; // [sp+110h] [-190h] BYREF

  a22 = rangeKeys;
  _R3 = &a18;
  a18 = stride;
  _R8 = &a14;
  a14 = frame;
  a20 = firstKeys;
  _R11 = &a20;
  a16 = numFrames;
  _R7 = &a24;
  a24 = nextKeys;
  _R4 = &a22;
  __asm { lvlx128   v56, r0, r3 }
  _R3 = &a16;
  __asm { lvlx      v13, r0, r8 }
  __asm { lvlx128   v59, r0, r11 }
  _R6 = -80;
  __asm { lvlx128   v58, r0, r7 }
  _R7 = vmxi_word_2_2_1_1;
  __asm { lvlx128   v57, r0, r4 }
  _R4 = -64;
  __asm
  {
    lvlx      v10, r0, r3
    vspltw128 v63, v56, 0
    lvx128    v62, r7, r4
  }
  _R11 = 16;
  __asm
  {
    lvx128    v0, r7, r6
    vsrw128   v123, v95, v62
    vadduwm   v11, v13, v0
  }
  _R9 = -112;
  __asm
  {
    vand128   v55, v95, v62
    lvx128    v60, r0, r7
    vspltb    v12, v10, 3
    vslw128   v4, v95, v60
    vand128   v54, v123, v62
    lvx128    v61, r7, r11
    vspltb    v11, v11, 3
    vslw128   v9, v95, v61
    lvx128    v10, r7, r9
    vspltw128 v13, v59, 0
    vsr       v7, v10, v12
    vspltw128 v8, v58, 0
    vor128    v53, v87, v54
    vspltw128 v6, v57, 0
    vsr       v5, v10, v11
  }
  _R4 = v111;
  __asm { vsubuwm   v10, v4, v9 }
  _R3 = v109;
  __asm { vsro128   v52, v7, v12 }
  _R11 = v108;
  __asm { vsrw128   v51, v85, v0 }
  _R9 = v107;
  __asm { vsro128   v50, v5, v11 }
  __asm { vsubuwm   v3, v8, v13 }
  _R8 = -96;
  _R6 = -16;
  __asm
  {
    vpermwi128 v125, v52, 0x11
    vxor128   v49, v83, v123
  }
  v49 = (numJoints + 3) & 0xFFFFFFFC;
  __asm
  {
    vsubuwm   v2, v6, v13
    vpermwi128 v124, v50, 0x11
    vadduwm   v1, v10, v3
  }
  _R26 = a28;
  __asm
  {
    lvx128    v119, r7, r8
    lvx128    v127, r7, r6
  }
  _R30 = frameBits;
  __asm { stvx128   v63, r0, r4 }
  v52 = (numFrames + 7) >> 3;
  __asm { stvx128   v10, r0, r3 }
  _R31 = 0;
  __asm { stvx128   v2, r0, r11 }
  _R27 = 0;
  __asm { stvx128   v1, r0, r9 }
  __asm
  {
    vnot128   v122, v125
    vnot128   v121, v124
    vor128    v120, v85, v49
  }
  if ( v49 != 0 )
  {
    __asm { vslw128   v48, v95, v62 }
    _R5 = v110;
    *(_QWORD *)v100.vector4_f32 = 0x7FFFFFFF7FFFFFFFLL;
    *(_QWORD *)&v100.u[2] = 0x7FFFFFFF7FFFFFFFLL;
    *(_QWORD *)v102.vector4_f32 = 0x1F0000001FLL;
    __asm { stvx128   v48, r0, r5 }
    *(_QWORD *)&v102.u[2] = 0x1F0000001FLL;
    v56 = 3 * v52;
    *(_QWORD *)v103.vector4_f32 = 0x2000000020LL;
    _R6 = &v101;
    _R5 = &v102;
    *(_QWORD *)&v103.u[2] = 0x2000000020LL;
    _R4 = &v104;
    *(_QWORD *)v101.vector4_f32 = 0x1700000017LL;
    *(_QWORD *)&v101.u[2] = 0x1700000017LL;
    _R7 = &v100;
    __asm { lvx128    v116, r0, r6 }
    *(_QWORD *)v104.vector4_f32 = 0x2000000020LL;
    _R19 = a28 + 256;
    _R24 = a28 + 512;
    *(_QWORD *)&v104.u[2] = 0x2000000020LL;
    __asm { lvx128    v114, r0, r4 }
    _R23 = a28 + 1024;
    *(_QWORD *)v106.vector4_f32 = 0x2000000020LL;
    _R29 = 0;
    *(_QWORD *)&v106.u[2] = 0x2000000020LL;
    _R11 = &v103;
    v105[0] = 1333788671;
    __asm { lvx128    v117, r0, r7 }
    v105[1] = 1333788671;
    _R9 = v52;
    v105[2] = 1333788671;
    _R8 = 16;
    v105[3] = 1333788671;
    __asm { lvx128    v115, r0, r5 }
    _R10 = v52 + 16;
    __asm { lvx128    v118, r0, r11 }
    do
    {
      __asm
      {
        lvrx128   v47, r10, r30
        lvlx128   v46, r9, r30
      }
      _R10 = v56 + _R31;
      __asm { lvrx128   v45, r8, r30 }
      _R9 = v56 + _R31 + 16;
      _R8 = 2 * (v52 + 8) + _R31;
      __asm { lvlx128   v44, r31, r30 }
      _R7 = 2 * v52 + _R31;
      __asm
      {
        vor128    v43, v78, v47
        vor128    v42, v76, v45
        vspltisw  v11, 0
        lvlx128   v41, r10, r30
      }
      _R6 = &v104;
      __asm { lvrx128   v40, r9, r30 }
      _R5 = v105;
      __asm
      {
        lvrx128   v39, r8, r30
        vor128    v38, v73, v40
        lvlx128   v37, r7, r30
        vrlimi128 v42, v43, 3, 2
        vor128    v36, v69, v39
      }
      _R4 = &v106;
      _R11 = &v103;
      __asm { lvx128    v10, r0, r5 }
      _R10 = &v100;
      __asm { vand128   v35, v74, v124 }
      _R9 = &v101;
      __asm { vrlimi128 v36, v38, 3, 2 }
      _R8 = &v102;
      __asm
      {
        vand128   v63, v74, v121
        lvx128    v9, r0, r4
        vand128   v34, v74, v122
      }
      __asm
      {
        vor128    v33, v67, v125
        vand128   v32, v68, v124
        vand128   v62, v68, v121
        stvx128   v63, r0, r9
        vand128   v61, v68, v122
        stvx128   v34, r0, r11
        vor128    v60, v64, v125
        vmrghw128 v59, v95, v62
        stvx128   v62, r0, r8
        vmrglw128 v58, v95, v62
        stvx128   v61, r0, r10
        vmrghw128 v57, v65, v60
        vmrglw128 v56, v65, v60
        vmrglw128 v55, v91, v58
        vmrghw128 v0, v89, v56
        vmrglw128 v13, v89, v56
        vcmpequw128 v126, v0, v11
        vmr128    v12, v126
        vsel128   v12, v0, v13, v12
        vmrghw128 v13, v91, v58
        vor128    v0, v87, v55
        stvx128   v12, r0, r6
        vcmpequw128 v12, v87, v11
        vandc128  v8, v118, v12
        vsel      v12, v0, v13, v12
        vsubuwm   v7, v11, v12
        vand128   v54, v12, v7
        vcuxwfp128 v53, v54, 0
        vand128   v6, v85, v117
        vsubuwm   v5, v10, v6
        vsrw128   v4, v5, v116
        vminuw    v3, v4, v9
        vand128   v2, v3, v115
        vadduwm   v1, v2, v8
        vmr128    v113, v1
      }
      CountLeadingZeros32x4(result: &v104, bits: &v106);
      __asm
      {
        vand128   v31, v114, v126
        vpkuwum128 v52, v113, v113
      }
      __asm
      {
        vadduwm   v30, v1, v31
        vpkuhum128 v51, v84, v52
        vpkuwum128 v50, v30, v30
        stvewx128 v51, r26, r27
        vpkuhum128 v49, v82, v50
        stvewx128 v49, r19, r27
      }
      CountBitsSet64x4(result: &v101, bits1: &v102, bits2: v80);
      __asm { vmr128    v126, v1 }
      CountBitsSet64x4(result: &v103, bits1: &v100, bits2: v81);
      __asm
      {
        vslw128   v27, v1, v120
        vslw128   v26, v1, v123
      }
      _R7 = v109;
      _R6 = v107;
      __asm { vslw128   v29, v126, v120 }
      _R5 = v110;
      __asm { vslw128   v28, v126, v123 }
      _R4 = v108;
      __asm { vadduwm   v13, v26, v27 }
      _R3 = v111;
      __asm { lvx128    v12, r0, r7 }
      _R10 = v109;
      __asm
      {
        lvx128    v11, r0, r6
        vadduwm   v0, v28, v29
        lvx128    v10, r0, r5
      }
      _R9 = v107;
      __asm
      {
        vadduwm   v23, v12, v10
        lvx128    v25, r0, r4
        vadduwm   v22, v11, v10
        lvx128    v24, r0, r3
        vsro128   v10, v13, v127
      }
      _R7 = v108;
      __asm { vcmpequw128 v8, v0, v119 }
      _R11 = _R29 + 4;
      __asm
      {
        vcmpequw  v7, v13, v0
        stvx128   v23, r0, r10
        stvx128   v22, r0, r9
      }
      _R31 += 4 * v52;
      __asm { vadduwm   v21, v25, v10 }
      _R27 += 4;
      __asm { vsro128   v10, v10, v127 }
      _R10 = v52 + 16 + _R31;
      _R9 = _R31 + v52;
      _R8 = _R31 + 16;
      __asm
      {
        vsro128   v20, v10, v127
        vadduwm   v19, v21, v10
        vadduwm   v10, v19, v20
        vadduwm   v9, v10, v0
        vadduwm   v18, v10, v13
        vsubuwm   v0, v9, v24
        vmr       v13, v9
        vspltw128 v48, v18, 3
        vsel      v10, v0, v12, v8
        vsel      v0, v13, v11, v7
        vpkuwum128 v47, v10, v10
        stvx128   v48, r0, r7
        vpkuwum128 v46, v0, v0
        vspltw128 v45, v47, 0
        vspltw128 v44, v47, 1
        vspltw128 v43, v46, 0
        vspltw128 v42, v46, 1
        stvewx128 v45, r24, r29
        stvewx128 v44, r24, r11
        stvewx128 v43, r23, r29
      }
      _R29 += 8;
      __asm { stvewx128 v42, r23, r11 }
    }
    while ( _R27 < v49 );
  }
  v91 = a30;
  v92 = numJoints - 1;
  v93 = numJoints;
  v94 = a30 - 1;
  if ( ((a30 - 1) & numJoints) != 0 )
  {
    v95 = (_BYTE *)(v92 + _R26);
    v96 = 2 * (v92 + 256);
    v97 = 2 * (v92 + 512);
    v98 = (_WORD *)(2 * (numJoints + 511) + _R26);
    do
    {
      *(_BYTE *)(v93 + _R26) = *v95;
      *(_BYTE *)(_R26 + 256 + v93++) = v95[256];
      *(v98 - 255) = *(_WORD *)(v96 + _R26);
      *++v98 = *(_WORD *)(v97 + _R26);
    }
    while ( (v93 & v94) != 0 );
  }
  return (numJoints + v91 - 1) & ~v94;
}


// ========================================================================
// ?DecodeFrameSetR@idMD6Blend@@CAXPIBEIIIMPIBF110PIAM@Z
// EA  : 0x8281C570
// RVA : 0x0081C570
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::DecodeFrameSetR(
        const unsigned __int8 *joints,
        unsigned int numJoints,
        unsigned int frame,
        unsigned int numFrames,
        double fraction,
        const __int16 *firstKeys,
        const __int16 *rangeKeys,
        const __int16 *nextKeys,
        const unsigned __int8 *frameBits,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        float *out,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        unsigned int a24,
        int a25,
        int a26,
        int a27,
        float a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        const unsigned __int8 *a36,
        int a37,
        int a38)
{
  unsigned int v40; // r3
  unsigned int v55; // r11
  unsigned int v62; // ctr
  unsigned __int16 *v64; // r11
  idMD6Blend::frameOffsets_t *v86; // [sp+8h] [-6F8h]
  unsigned int v87; // [sp+Ch] [-6F4h]
  int v88; // [sp+10h] [-6F0h]
  int v89; // [sp+14h] [-6ECh]
  int v90; // [sp+18h] [-6E8h]
  unsigned int v91; // [sp+1Ch] [-6E4h]
  int v92; // [sp+20h] [-6E0h]
  unsigned int v93; // [sp+24h] [-6DCh]
  int v94; // [sp+28h] [-6D8h]
  unsigned int v95; // [sp+2Ch] [-6D4h]
  int v96; // [sp+30h] [-6D0h]
  const void *v97; // [sp+34h] [-6CCh]
  int v98; // [sp+38h] [-6C8h]
  const void *v99; // [sp+3Ch] [-6C4h]
  int v100; // [sp+40h] [-6C0h]
  const void *v101; // [sp+44h] [-6BCh]
  int v102; // [sp+48h] [-6B8h]
  int v103; // [sp+4Ch] [-6B4h]
  int v104; // [sp+50h] [-6B0h]
  int v105; // [sp+58h] [-6A8h]
  char v106; // [sp+60h] [-6A0h] BYREF
  char v107; // [sp+70h] [-690h] BYREF
  char v108; // [sp+80h] [-680h] BYREF
  char v109; // [sp+90h] [-670h] BYREF
  char v110; // [sp+A0h] [-660h] BYREF
  _BYTE v111[256]; // [sp+B0h] [-650h] BYREF
  char v112; // [sp+1B0h] [-550h] BYREF
  char v113; // [sp+4AEh] [-252h] BYREF

  a24 = frame;
  a28 = fraction;
  _R31 = rangeKeys;
  if ( numJoints != 0 )
  {
    v40 = idMD6Blend::DecodeFrameOffsets(
            numJoints,
            frame,
            numFrames,
            stride: 6u,
            firstKeys: rangeKeys,
            rangeKeys: nextKeys,
            nextKeys: frameBits,
            frameBits: a36,
            offsets: v86,
            pad: v87,
            a11: v88,
            a12: v89,
            a13: v90,
            a14: v91,
            a15: v92,
            a16: v93,
            a17: v94,
            a18: v95,
            a19: v96,
            a20: v97,
            a21: v98,
            a22: v99,
            a23: v100,
            a24: v101,
            a25: v102,
            a26: v103,
            a27: v104,
            a28: (int)v111,
            a29: v105,
            a30: 4);
    _R6 = &a24;
    _R5 = &a28;
    _R4 = 4;
    _R8 = &quatScale;
    __asm { lvlx128   v63, r0, r6 }
    _R10 = 0;
    __asm { lvlx128   v61, r0, r5 }
    __asm
    {
      vspltw128 v62, v63, 0
      lvlx128   v60, r0, r8
      vspltw128 v59, v61, 0
      lvlx128   v58, r8, r4
      vspltw128 v13, v60, 0
      vspltw128 v12, v58, 0
      vcuxwfp128 v57, v62, 0
      vaddfp128 v51, v89, v59
    }
    if ( v40 != 0 )
    {
      _R7 = 416;
      _R6 = 432;
      _R5 = 384;
      _R4 = 544;
      __asm { lvx128    v9, r8, r7 }
      __asm { lvx128    v28, r8, r6 }
      _R30 = 96;
      _R7 = 112;
      _R6 = 128;
      __asm { lvx128    v60, r8, r5 }
      v55 = (v40 - 1) >> 2;
      _R3 = 560;
      __asm
      {
        lvx128    v27, r8, r4
        lvx128    v55, r8, r3
      }
      _R5 = 144;
      __asm { lvx128    v59, r8, r30 }
      __asm { lvx128    v58, r8, r7 }
      _R4 = 160;
      __asm { lvx128    v57, r8, r6 }
      _R3 = 176;
      _R30 = 192;
      _R7 = 304;
      __asm { lvx128    v56, r8, r5 }
      _R6 = 320;
      v62 = v55 + 1;
      _R9 = a38;
      __asm
      {
        lvx128    v54, r8, r4
        lvx128    v0, r8, r3
      }
      __asm { lvx128    v63, r8, r30 }
      __asm { lvx128    v53, r8, r7 }
      __asm { lvx128    v52, r8, r6 }
      v64 = (unsigned __int16 *)&v113;
      _R24 = v111;
      _R23 = &v112;
      do
      {
        __asm { lvlx      v11, r10, r24 }
        _R8 = *(v64 - 255);
        __asm { lvlx      v10, r10, r23 }
        _R7 = *(v64 - 254);
        __asm { vmrghb    v8, v9, v11 }
        _R6 = *(v64 - 253);
        __asm { vmrghb    v7, v9, v10 }
        _R5 = *(v64 - 252);
        _R4 = v64[1];
        __asm { lvlx128   v50, r8, r31 }
        _R3 = v64[2];
        __asm
        {
          vmrghh    v6, v9, v8
          lvlx128   v47, r7, r31
          vmrghh    v5, v9, v7
        }
        _R8 += 16;
        _R7 += 16;
        __asm
        {
          lvlx128   v46, r6, r31
          lvlx128   v45, r5, r31
        }
        _R30 = v64[3];
        __asm { vcuxwfp128 v49, v6, 0 }
        _R6 += 16;
        __asm { vcuxwfp128 v48, v5, 0 }
        _R5 += 16;
        v64 += 4;
        _R29 = *v64;
        __asm
        {
          lvlx128   v44, r4, r31
          lvlx128   v43, r3, r31
        }
        _R4 += 16;
        __asm { lvrx128   v40, r8, r31 }
        _R3 += 16;
        __asm { lvrx128   v39, r7, r31 }
        _R8 = _R30 + 16;
        _R7 = _R29 + 16;
        __asm
        {
          lvrx128   v38, r6, r31
          lvrx128   v36, r5, r31
          vor128    v33, v78, v38
          vor128    v62, v82, v40
          lvrx128   v35, r4, r31
          lvlx128   v42, r30, r31
          lvlx128   v41, r29, r31
          lvrx128   v34, r3, r31
          vsubfp128 v37, v83, v49
          lvrx128   v32, r8, r31
          vsubfp128 v8, v80, v49
          vor128    v48, v79, v39
          vor128    v47, v77, v36
          lvrx128   v61, r7, r31
          vor128    v49, v76, v35
          vmrghw128 v46, v94, v33
          vor128    v45, v75, v34
          vor128    v44, v73, v61
          vor128    v50, v74, v32
          vmrghw128 v41, v80, v47
          vand128   v39, v94, v63
          vand128   v42, v65, v63
          vmrghw128 v38, v77, v44
          vand128   v34, v80, v63
          vmrghw128 v43, v81, v50
          vand128   v36, v81, v63
          vmrghw128 v35, v78, v41
          vand128   v40, v82, v63
          vupkhsh128 v41, v39
          vrefp     v11, v8
          vupkhsh128 v39, v42
          vmrghw128 v33, v75, v38
          vand128   v43, v79, v63
          vand128   v32, v67, v54
          vand128   v38, v77, v63
          vand128   v35, v76, v63
          vand128   v62, v65, v54
          vsrw128   v33, v64, v52
          vnmsubfp  v7, v11, v28, v8
          vcsxwfp128 v8, v41, 0
          vmaddfp   v11, v7, v11, v11
          vmulfp128 v61, v69, v11
          vupkhsh128 v37, v34
          vupkhsh128 v34, v36
          vspltw128 v50, v61, 0
          vspltw128 v49, v61, 1
          vspltw128 v48, v61, 2
          vspltw128 v46, v61, 3
          vupkhsh128 v61, v43
          vcsxwfp128 v1, v61, 0
          vupkhsh128 v47, v40
          vsrw128   v43, v64, v53
          vcsxwfp128 v7, v39, 0
          vsrw128   v42, v94, v52
          vcsxwfp128 v2, v37, 0
          vsrw128   v41, v94, v53
          vupkhsh128 v44, v35
          vcsxwfp128 v3, v47, 0
          vupkhsh128 v45, v38
          vor128    v11, v75, v33
          vcsxwfp128 v4, v34, 0
          vmaddfp   v6, v8, v12, v13
        }
        _R8 = &v110;
        __asm
        {
          vor128    v10, v73, v42
          vcsxwfp128 v30, v44, 0
          vcsxwfp128 v31, v45, 0
        }
        _R7 = &v108;
        __asm { vspltb    v25, v11, 0xB }
        _R6 = &v106;
        __asm
        {
          vspltb    v29, v11, 3
          vspltb    v24, v11, 0xF
          vmaddfp   v1, v1, v12, v13
          vspltb    v26, v11, 7
          vmaddfp   v5, v7, v12, v13
          vor128    v11, v82, v50
          vaddubm   v7, v29, v0
          vspltb    v29, v10, 3
          vmaddfp   v2, v2, v12, v13
          vspltb    v23, v10, 0xF
          vmaddfp   v3, v3, v12, v13
          vmaddfp   v4, v4, v12, v13
          vmsum3fp128 v36, v6, v6
          vperm128  v7, v91, v59, v7
          vmaddfp   v30, v30, v12, v13
          vmaddfp   v31, v31, v12, v13
          vmr128    v39, v1
          vaddubm   v1, v25, v0
          vmsum3fp128 v35, v5, v5
          stvx128   v7, r0, r6
          vspltb    v25, v10, 7
          vmsum3fp128 v34, v2, v2
          vmr128    v40, v3
          vmr128    v38, v1
          vmsum3fp128 v33, v4, v4
          vaddubm   v1, v24, v0
          vspltb    v24, v10, 0xB
          vaddubm   v3, v26, v0
          vmsum3fp128 v47, v30, v30
          vmsum3fp128 v61, v31, v31
          vmr128    v37, v1
          vaddubm   v1, v29, v0
          vperm128  v3, v90, v58, v3
          stvx128   v1, r0, r8
          vor128    v1, v71, v39
          vmrghw128 v45, v68, v35
          stvx128   v3, r0, r7
          vor128    v3, v72, v40
          vmsum3fp128 v32, v1, v1
          vmsum3fp128 v62, v3, v3
          vmrghw128 v42, v93, v47
          vmrghw128 v44, v66, v32
          vmrghw128 v43, v65, v62
          vmrghw128 v41, v77, v44
          vmrghw128 v40, v75, v42
          vsubfp128 v8, v28, v41
          vsubfp128 v7, v28, v40
          vrsqrtefp128 v39, v8
          vrsqrtefp128 v36, v7
          vmulfp128 v29, v71, v39
          vmulfp128 v35, v71, v55
          vmulfp128 v26, v68, v36
          vmulfp128 v34, v68, v55
          vmaddfp   v29, v8, v27, v29
          vmaddfp   v26, v7, v27, v26
          vmulfp128 v33, v67, v29
          vmulfp128 v32, v66, v26
          vmulfp128 v62, v65, v8
          vmulfp128 v61, v64, v7
          lvx128    v7, r0, r6
          vperm128  v8, v6, v62, v7
          vmr128    v45, v4
          lvx128    v7, r0, r7
          vaddubm   v4, v25, v0
          vnmsubfp  v26, v11, v8, v8
          vmr128    v47, v3
          vperm128  v7, v2, v62, v7
          vor128    v3, v70, v38
        }
        _R5 = &v107;
        __asm { vor128    v10, v81, v49 }
        _R3 = &v109;
        __asm { vmr128    v44, v4 }
        __asm { vor128    v4, v69, v37 }
        __asm
        {
          vperm128  v3, v89, v57, v3
          vaddubm   v6, v23, v0
          vnmsubfp  v25, v10, v7, v7
          vmr128    v42, v0
          vor128    v29, v78, v46
          vperm128  v4, v88, v56, v4
          vperm128  v11, v5, v62, v3
          stvx128   v6, r0, r5
          vor128    v3, v79, v47
          vor128    v6, v80, v48
          vmr128    v43, v4
          vaddubm   v4, v24, v0
          lvx128    v0, r0, r8
        }
        _R8 = __ROL4__(joints[_R10], 4);
        __asm { vperm128  v0, v91, v59, v0 }
        _R6 = __ROL4__(joints[_R10 + 2], 4);
        __asm
        {
          vor128    v5, v75, v43
          vperm128  v10, v1, v62, v5
          vor128    v5, v76, v44
          vperm128  v1, v89, v57, v4
          vor128    v4, v77, v45
          vperm128  v2, v90, v58, v5
          lvx128    v5, r0, r5
          vperm128  v5, v88, v56, v5
        }
        __asm
        {
          stvx128   v5, r0, r3
          vperm128  v5, v4, v61, v0
          vperm128  v4, v31, v61, v2
          lvx128    v2, r0, r3
          vperm128  v3, v3, v61, v1
          vnmsubfp  v1, v6, v11, v11
          vperm128  v2, v30, v61, v2
          vnmsubfp  v6, v29, v10, v10
          vmsum4fp128 v39, v11, v3
        }
        __asm { vmsum4fp128 v38, v10, v2 }
        _R7 = __ROL4__(joints[_R10 + 1], 4);
        __asm { vmsum4fp128 v41, v8, v5 }
        _R5 = __ROL4__(joints[_R10 + 3], 4);
        __asm { vmsum4fp128 v40, v7, v4 }
        _R10 += 4;
        __asm
        {
          vand128   v35, v71, v60
          vand128   v34, v70, v60
          vand128   v37, v73, v60
          vand128   v36, v72, v60
          vxor128   v10, v80, v35
          vxor128   v11, v78, v34
          vxor128   v7, v82, v37
          vxor128   v8, v81, v36
          vmaddfp   v10, v10, v1, v3
          vmaddfp   v11, v11, v6, v2
          vmaddfp   v7, v7, v26, v5
          vmaddfp   v8, v8, v25, v4
          vmr128    v33, v10
          vmr128    v32, v11
          vmsum4fp128 v62, v7, v7
          vmsum4fp128 v61, v8, v8
          vmsum4fp128 v50, v65, v33
          vmsum4fp128 v49, v64, v32
          vmrghw128 v48, v94, v50
          vmrghw128 v47, v93, v49
          vmrghw128 v11, v80, v47
          vrsqrtefp128 v46, v11
          vmulfp128 v10, v78, v46
          vmulfp128 v45, v78, v55
          vmaddfp   v11, v11, v27, v10
          vmulfp128 v44, v77, v11
          vspltw128 v43, v44, 0
          vor128    v0, v74, v42
          vspltw128 v41, v44, 1
          vspltw128 v40, v44, 2
          vspltw128 v39, v44, 3
          vmulfp128 v38, v75, v7
          vmulfp128 v37, v73, v8
          vmulfp128 v36, v72, v33
          vmulfp128 v35, v71, v32
          stvx128   v38, r8, r9
          stvx128   v37, r7, r9
          stvx128   v36, r6, r9
          stvx128   v35, r5, r9
        }
        --v62;
      }
      while ( v62 != 0 );
    }
  }
}


// ========================================================================
// ?DecodeFrameSetST@idMD6Blend@@CAXPIBEIIIMPIBM110PIAM@Z
// EA  : 0x8281CAB8
// RVA : 0x0081CAB8
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::DecodeFrameSetST(
        const unsigned __int8 *joints,
        unsigned int numJoints,
        unsigned int frame,
        unsigned int numFrames,
        double fraction,
        const float *firstKeys,
        const float *rangeKeys,
        const float *nextKeys,
        const unsigned __int8 *frameBits,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        float *out,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        unsigned int a24,
        int a25,
        int a26,
        int a27,
        float a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        const unsigned __int8 *a36,
        int a37,
        int a38)
{
  unsigned int v40; // r3
  unsigned int v48; // ctr
  unsigned __int16 *v50; // r11
  int v69; // r26
  int v72; // r8
  idMD6Blend::frameOffsets_t *v75; // [sp+8h] [-698h]
  unsigned int v76; // [sp+Ch] [-694h]
  int v77; // [sp+10h] [-690h]
  int v78; // [sp+14h] [-68Ch]
  int v79; // [sp+18h] [-688h]
  unsigned int v80; // [sp+1Ch] [-684h]
  int v81; // [sp+20h] [-680h]
  unsigned int v82; // [sp+24h] [-67Ch]
  int v83; // [sp+28h] [-678h]
  unsigned int v84; // [sp+2Ch] [-674h]
  int v85; // [sp+30h] [-670h]
  const void *v86; // [sp+34h] [-66Ch]
  int v87; // [sp+38h] [-668h]
  const void *v88; // [sp+3Ch] [-664h]
  int v89; // [sp+40h] [-660h]
  const void *v90; // [sp+44h] [-65Ch]
  int v91; // [sp+48h] [-658h]
  int v92; // [sp+4Ch] [-654h]
  int v93; // [sp+50h] [-650h]
  int v94; // [sp+58h] [-648h]
  _BYTE v95[256]; // [sp+60h] [-640h] BYREF
  char v96; // [sp+160h] [-540h] BYREF
  char v97; // [sp+45Eh] [-242h] BYREF

  a24 = frame;
  a28 = fraction;
  _R31 = rangeKeys;
  if ( numJoints != 0 )
  {
    v40 = idMD6Blend::DecodeFrameOffsets(
            numJoints,
            frame,
            numFrames,
            stride: 0xCu,
            firstKeys: rangeKeys,
            rangeKeys: nextKeys,
            nextKeys: frameBits,
            frameBits: a36,
            offsets: v75,
            pad: v76,
            a11: v77,
            a12: v78,
            a13: v79,
            a14: v80,
            a15: v81,
            a16: v82,
            a17: v83,
            a18: v84,
            a19: v85,
            a20: v86,
            a21: v87,
            a22: v88,
            a23: v89,
            a24: v90,
            a25: v91,
            a26: v92,
            a27: v93,
            a28: (int)v95,
            a29: v94,
            a30: 4);
    _R6 = &a24;
    _R5 = &a28;
    _R10 = 0;
    __asm
    {
      lvlx128   v63, r0, r6
      lvlx128   v62, r0, r5
      vspltw128 v61, v63, 0
      vspltw128 v60, v62, 0
      vcuxwfp128 v59, v61, 0
      vaddfp128 v62, v91, v60
    }
    if ( v40 != 0 )
    {
      _R6 = vmxi_word_mask_clear_last;
      _R7 = 192;
      _R8 = 208;
      __asm { lvx128    v63, r0, r6 }
      v48 = ((v40 - 1) >> 2) + 1;
      _R9 = a38;
      __asm { lvx128    v0, r6, r7 }
      __asm { lvx128    v31, r6, r8 }
      v50 = (unsigned __int16 *)&v97;
      _R29 = v95;
      _R28 = &v96;
      do
      {
        __asm { lvlx      v13, r10, r29 }
        _R8 = *(v50 - 255);
        __asm { lvlx      v12, r10, r28 }
        _R7 = *(v50 - 254);
        __asm { vmrghb    v11, v0, v13 }
        _R27 = _R8 + 16;
        __asm { vmrghb    v10, v0, v12 }
        _R26 = _R7 + 16;
        _R6 = v50[1];
        __asm { lvlx128   v58, r8, r31 }
        _R25 = v50[2];
        __asm
        {
          vmrghh    v9, v0, v11
          lvlx128   v57, r7, r31
          vmrghh    v8, v0, v10
          lvrx128   v56, r27, r31
          lvrx128   v54, r26, r31
          vor128    v52, v90, v56
          vor128    v51, v89, v54
        }
        _R7 = _R6 + 16;
        __asm { vcuxwfp128 v55, v9, 0 }
        _R27 = _R25 + 16;
        __asm
        {
          vcuxwfp128 v53, v8, 0
          lvlx128   v50, r6, r31
          vand128   v9, v84, v63
          lvlx128   v48, r25, r31
          vand128   v8, v83, v63
        }
        __asm { lvrx128   v49, r7, r31 }
        __asm
        {
          lvrx128   v47, r27, r31
          vor128    v46, v82, v49
          vor128    v45, v80, v47
        }
        _R8 = *(v50 - 253);
        _R7 = *(v50 - 252);
        _R6 = _R8 + 16;
        __asm { vand128   v1, v78, v63 }
        _R26 = _R7 + 16;
        __asm
        {
          vand128   v3, v77, v63
          lvlx128   v43, r8, r31
        }
        __asm
        {
          vsubfp128 v44, v94, v55
          lvrx128   v42, r6, r31
          vsubfp128 v10, v85, v55
        }
        _R6 = __ROL4__(joints[_R10], 4);
        _R27 = __ROL4__(joints[_R10 + 1], 4);
        __asm
        {
          lvlx128   v40, r7, r31
          lvrx128   v39, r26, r31
          vor128    v41, v75, v42
        }
        _R8 = v50[3];
        __asm { vor128    v38, v72, v39 }
        v50 += 4;
        _R7 = *v50;
        v69 = joints[_R10 + 3];
        __asm
        {
          vand128   v11, v73, v63
          vand128   v7, v70, v63
          lvlx128   v36, r8, r31
          lvlx128   v35, r7, r31
          vrefp     v13, v10
          vnmsubfp  v6, v13, v31, v10
          vmaddfp   v13, v6, v13, v13
          vmulfp128 v37, v76, v13
          vspltw128 v10, v37, 0
          vspltw128 v6, v37, 1
          vspltw128 v5, v37, 2
          vspltw128 v4, v37, 3
          vnmsubfp  v2, v10, v9, v9
          vnmsubfp  v13, v6, v8, v8
          vmaddfp   v12, v10, v2, v1
          vmr       v10, v5
          vmaddfp   v13, v6, v13, v3
          vnmsubfp  v9, v10, v11, v11
          vnmsubfp  v11, v4, v7, v7
          stvx128   v12, r6, r9
        }
        _R6 = _R8 + 16;
        __asm { stvx128   v13, r27, r9 }
        _R27 = _R7 + 16;
        v72 = joints[_R10 + 2];
        _R10 += 4;
        _R7 = __ROL4__(v72, 4);
        __asm
        {
          lvrx128   v34, r6, r31
          lvrx128   v33, r27, r31
          vor128    v32, v68, v34
        }
        _R6 = __ROL4__(v69, 4);
        __asm
        {
          vor128    v61, v67, v33
          vand128   v12, v64, v63
          vand128   v13, v93, v63
          vmaddfp   v12, v5, v9, v12
          vmaddfp   v13, v4, v11, v13
          stvx128   v12, r7, r9
          stvx128   v13, r6, r9
        }
        --v48;
      }
      while ( v48 != 0 );
    }
  }
}


// ========================================================================
// ?DecodeFrameSetU@idMD6Blend@@CAXPIBEIIIMPIBM110PIAM@Z
// EA  : 0x8281CCF8
// RVA : 0x0081CCF8
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::DecodeFrameSetU(
        const unsigned __int8 *channelsU,
        unsigned int numUserChannels,
        unsigned int frame,
        unsigned int numFrames,
        double fraction,
        const float *firstKeys,
        const float *rangeKeys,
        const float *nextKeys,
        const unsigned __int8 *frameBits,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        float *out,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        unsigned int a24,
        int a25,
        int a26,
        int a27,
        float a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        const unsigned __int8 *a36,
        int a37,
        int a38)
{
  unsigned int v40; // r3
  unsigned int v47; // ctr
  unsigned __int16 *v49; // r11
  idMD6Blend::frameOffsets_t *v64; // [sp+8h] [-6A8h]
  unsigned int v65; // [sp+Ch] [-6A4h]
  int v66; // [sp+10h] [-6A0h]
  int v67; // [sp+14h] [-69Ch]
  int v68; // [sp+18h] [-698h]
  unsigned int v69; // [sp+1Ch] [-694h]
  int v70; // [sp+20h] [-690h]
  unsigned int v71; // [sp+24h] [-68Ch]
  int v72; // [sp+28h] [-688h]
  unsigned int v73; // [sp+2Ch] [-684h]
  int v74; // [sp+30h] [-680h]
  const void *v75; // [sp+34h] [-67Ch]
  int v76; // [sp+38h] [-678h]
  const void *v77; // [sp+3Ch] [-674h]
  int v78; // [sp+40h] [-670h]
  const void *v79; // [sp+44h] [-66Ch]
  int v80; // [sp+48h] [-668h]
  int v81; // [sp+4Ch] [-664h]
  int v82; // [sp+50h] [-660h]
  int v83; // [sp+58h] [-658h]
  _BYTE v84[256]; // [sp+60h] [-650h] BYREF
  char v85; // [sp+160h] [-550h] BYREF
  char v86; // [sp+45Eh] [-252h] BYREF

  a24 = frame;
  a28 = fraction;
  _R31 = rangeKeys;
  if ( numUserChannels != 0 )
  {
    v40 = idMD6Blend::DecodeFrameOffsets(
            numJoints: numUserChannels,
            frame,
            numFrames,
            stride: 4u,
            firstKeys: rangeKeys,
            rangeKeys: nextKeys,
            nextKeys: frameBits,
            frameBits: a36,
            offsets: v64,
            pad: v65,
            a11: v66,
            a12: v67,
            a13: v68,
            a14: v69,
            a15: v70,
            a16: v71,
            a17: v72,
            a18: v73,
            a19: v74,
            a20: v75,
            a21: v76,
            a22: v77,
            a23: v78,
            a24: v79,
            a25: v80,
            a26: v81,
            a27: v82,
            a28: (int)v84,
            a29: v83,
            a30: 4);
    _R6 = &a24;
    _R5 = &a28;
    _R10 = 0;
    __asm
    {
      lvlx128   v63, r0, r6
      lvlx128   v62, r0, r5
      vspltw128 v61, v63, 0
      vspltw128 v60, v62, 0
      vcuxwfp128 v59, v61, 0
      vaddfp128 v63, v91, v60
    }
    if ( v40 != 0 )
    {
      _R8 = &vmx_float_one_8;
      _R29 = -16;
      __asm { lvx128    v7, r0, r8 }
      v47 = ((v40 - 1) >> 2) + 1;
      _R9 = a38;
      __asm { lvx128    v0, r8, r29 }
      v49 = (unsigned __int16 *)&v86;
      _R4 = v84;
      _R3 = &v85;
      do
      {
        __asm { lvlx      v13, r10, r4 }
        _R29 = *(v49 - 253);
        __asm { lvlx      v12, r10, r3 }
        _R28 = *(v49 - 254);
        __asm { vmrghb    v11, v0, v13 }
        _R27 = *(v49 - 252);
        __asm { vmrghb    v10, v0, v12 }
        _R24 = *(v49 - 255);
        _R26 = v49[1];
        __asm { lvlx128   v54, r29, r31 }
        _R23 = v49[2];
        __asm
        {
          vmrghh    v9, v0, v11
          lvlx128   v58, r28, r31
          vmrghh    v8, v0, v10
          lvlx128   v56, r27, r31
          lvlx128   v53, r24, r31
        }
        _R25 = v49[3];
        __asm { vmrghw128 v52, v90, v56 }
        v49 += 4;
        _R8 = *v49;
        __asm
        {
          vcuxwfp128 v57, v9, 0
          vmrghw128 v50, v85, v54
          vcuxwfp128 v55, v8, 0
          lvlx128   v48, r23, r31
          lvlx128   v47, r26, r31
        }
        __asm { lvlx128   v51, r25, r31 }
        __asm
        {
          vmrghw128 v10, v82, v52
          lvlx128   v49, r8, r31
          vmrghw128 v44, v79, v51
        }
        _R27 = __ROL4__(channelsU[_R10], 2);
        __asm { vmrghw128 v46, v80, v49 }
        __asm
        {
          vmrghw128 v8, v76, v46
          vsubfp128 v45, v95, v57
          vsubfp128 v11, v87, v57
          vrefp     v13, v11
          vnmsubfp  v9, v13, v7, v11
          vmaddfp   v13, v9, v13, v13
          vmulfp128 v12, v77, v13
          vnmsubfp  v11, v12, v10, v10
          vmaddfp   v13, v12, v11, v8
          vspltw128 v43, v13, 0
          vspltw128 v42, v13, 1
          vspltw128 v41, v13, 2
          vspltw128 v40, v13, 3
          stvewx128 v43, r9, r27
        }
        _R8 = __ROL4__(channelsU[_R10 + 1], 2);
        __asm { stvewx128 v42, r9, r8 }
        _R8 = __ROL4__(channelsU[_R10 + 2], 2);
        __asm { stvewx128 v41, r9, r8 }
        _R8 = __ROL4__(channelsU[_R10 + 3], 2);
        __asm { stvewx128 v40, r9, r8 }
        _R10 += 4;
        --v47;
      }
      while ( v47 != 0 );
    }
  }
}


// ========================================================================
// ?LerpRST@idMD6Blend@@CAXIMPIBEPIBM1101110PIAM22PIAE@Z
// EA  : 0x8281CEB0
// RVA : 0x0081CEB0
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::LerpRST(
        unsigned int numJoints,
        double alpha,
        const unsigned __int8 *filter,
        const float *aR,
        const float *aS,
        const float *aT,
        const unsigned __int8 *aW,
        const float *bR,
        const float *bS,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        const float *bT,
        const unsigned __int8 *bW,
        float *outR,
        float *outS,
        float *outT,
        float outW,
        int a23,
        const float *a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        const float *a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        const float *bS_0,
        int a45,
        const float *bTa,
        int a47,
        const unsigned __int8 *bWa)
{
  unsigned int v45; // ctr
  int v108; // [sp+0h] [-150h]
  const unsigned __int8 *v109; // [sp+4h] [-14Ch]
  int v110; // [sp+8h] [-148h]
  const unsigned __int8 *v111; // [sp+Ch] [-144h]
  int v112; // [sp+18h] [-138h]
  int v113; // [sp+24h] [-12Ch]
  int v114; // [sp+28h] [-128h]
  int v115; // [sp+2Ch] [-124h]
  int v116; // [sp+30h] [-120h]
  int v117; // [sp+34h] [-11Ch]
  int v118; // [sp+38h] [-118h]
  int v119; // [sp+40h] [-110h]
  int v120; // [sp+48h] [-108h]
  int v121; // [sp+4Ch] [-104h]
  int back_chain; // [sp+50h] [-100h]
  int v123; // [sp+58h] [-F8h]
  int v124; // [sp+5Ch] [-F4h]
  int v125; // [sp+60h] [-F0h]
  int v126; // [sp+64h] [-ECh]
  int v127; // [sp+70h] [-E0h]
  int v128; // [sp+74h] [-DCh]
  int v129; // [sp+78h] [-D8h]
  int v130; // [sp+80h] [-D0h]
  const unsigned __int8 *v131; // [sp+88h] [-C8h]
  int v132; // [sp+8Ch] [-C4h]
  char *v133; // [sp+90h] [-C0h]
  __int64 v134; // [sp+98h] [-B8h]
  int v135; // [sp+A4h] [-ACh]
  unsigned __int64 v136; // [sp+A8h] [-A8h]

  _R11 = &outW;
  outW = alpha;
  a24 = aR;
  _R28 = 0;
  a32 = bR;
  __asm
  {
    lvlx128   v63, r0, r11
    vspltw128 v29, v63, 0
  }
  if ( numJoints != 0 )
  {
    back_chain = (char *)bS - (char *)aS;
    v110 = (char *)aT - (char *)aS;
    _R26 = bTa;
    v118 = a42 - (_DWORD)aS;
    v127 = aW - (const unsigned __int8 *)aS;
    v45 = ((numJoints - 1) >> 3) + 1;
    v123 = a36 - (_DWORD)aS;
    v130 = (char *)bS_0 - (char *)aS;
    v113 = a38 - (_DWORD)aS;
    v129 = (char *)aT - (char *)bS;
    v124 = (char *)bTa - (char *)aS;
    v132 = a42 - (_DWORD)bS;
    v112 = a36 - (_DWORD)bS;
    v117 = a38 - (_DWORD)bS;
    v116 = (char *)bS_0 - (char *)bS;
    v120 = aW - (const unsigned __int8 *)bS;
    v126 = (char *)bTa - (char *)bS;
    v133 = (char *)aT - a42;
    v131 = &aW[-a42];
    v125 = a36 - (_DWORD)aT;
    v121 = (char *)bS_0 - (char *)aT;
    v128 = (char *)bTa - (char *)aT;
    v108 = aW - (const unsigned __int8 *)aT;
    v115 = a38 - (_DWORD)aT;
    _R4 = bS + 12;
    v119 = aW - (const unsigned __int8 *)bS_0;
    v111 = &aW[-a36];
    _R31 = aT + 20;
    _R27 = a38 + 96;
    _R29 = a36 + 112;
    _R30 = bS_0 + 4;
    _R3 = a42 + 64;
    _R11 = aS + 8;
    _R25 = (unsigned int)bWa | 0xFFFFFFF000000000uLL;
    v109 = &aW[-a38];
    v114 = aW - (const unsigned __int8 *)bTa;
    _R6 = &vmx_float_rsqrt_c1_2;
    _R7 = -128;
    _R21 = -176;
    _R20 = -16;
    _R10 = -144;
    _R19 = &vmx_float_smallest_non_denorm_0;
    __asm
    {
      lvx128    v61, r0, r6
      lvx128    v13, r6, r7
    }
    __asm { lvx128    v62, r6, r21 }
    __asm { lvx128    v20, r6, r20 }
    _R8 = 0x1000000020LL;
    __asm { lvx128    v0, r6, r10 }
    _R6 = 48;
    __asm { lvx128    v63, r0, r19 }
    _R20 = 80;
    _R21 = -48;
    while ( 1 )
    {
      _R23 = a40;
      __asm
      {
        lvlx      v10, r28, r5
        lvlx      v12, r28, r9
      }
      _R10 = _R28 + 4;
      __asm { vmrghb    v7, v0, v10 }
      _R22 = -32;
      __asm
      {
        vmrghb    v9, v0, v12
        lvlx      v11, r28, r23
        vmrghh    v1, v0, v7
        vaddubs   v4, v12, v11
        vmrghb    v3, v0, v11
        lvlx      v11, r10, r23
        vmrghh    v2, v0, v9
        lvlx      v12, r10, r9
        vaddubs   v28, v12, v11
        vmrghb    v26, v0, v11
        vcuxwfp128 v59, v1, 0
        vmrghb    v27, v0, v12
        vmrghh    v30, v0, v3
        lvlx      v31, r10, r5
        vcuxwfp128 v60, v2, 0
        vspltw128 v57, v4, 0
        vmrghb    v25, v0, v31
      }
      _R5 = 64;
      __asm { vmrghh    v23, v0, v26 }
      _R9 = back_chain;
      __asm
      {
        vcuxwfp128 v58, v30, 0
        vmrghh    v24, v0, v27
        vspltw128 v56, v28, 0
      }
      _R23 = 64;
      __asm
      {
        vmrghh    v22, v0, v25
        vcuxwfp128 v54, v23, 0
        vcuxwfp128 v55, v24, 0
        stvewx128 v57, r25, r28
        vcuxwfp128 v53, v22, 0
        stvewx128 v56, r25, r10
        vmulfp128 v12, v92, v59
        lvx128    v46, r11, r8
        lvx128    v45, r11, r6
        lvx128    v43, r11, r20
        vmulfp128 v11, v90, v59
        lvx128    v41, r11, r5
        vmulfp128 v9, v86, v53
        vmulfp128 v10, v87, v53
        vcmpgtfp128 v31, v12, v63
        vcmpgtfp128 v30, v11, v63
        vmaddfp   v1, v12, v11, v29
        vcmpgtfp  v26, v11, v12
        vmulfp128 v52, v11, v29
        vcmpgtfp128 v27, v9, v63
        vcmpgtfp128 v28, v10, v63
        vcmpgtfp  v25, v9, v10
        vsel      v31, v13, v12, v31
        vmulfp128 v42, v9, v29
        vsel      v8, v13, v11, v30
        vsubfp128 v50, v1, v12
        vmr       v1, v31
        vrefp     v12, v31
        vmr128    v51, v8
        vsel      v7, v13, v9, v27
        vsel      v8, v13, v10, v28
        vrefp128  v11, v51
        vor128    v31, v83, v51
        vmr128    v48, v7
        vmr128    v49, v8
        vnmsubfp  v4, v12, v13, v1
        vrefp128  v7, v48
        vor128    v5, v81, v49
        vrefp128  v8, v49
        vnmsubfp  v6, v11, v13, v31
        vmaddfp   v12, v4, v12, v12
        vmaddfp   v11, v6, v11, v11
        vmulfp128 v12, v84, v12
        vmulfp128 v11, v82, v11
        vsel      v6, v12, v11, v26
        vmaddfp   v12, v10, v9, v29
        vor128    v11, v80, v48
        vmr128    v47, v6
        vnmsubfp  v4, v7, v13, v11
        vnmsubfp  v11, v8, v13, v5
        vsubfp128 v44, v12, v10
        vmaddfp   v12, v11, v8, v8
        lvx128    v40, r4, r21
        vmaddfp   v9, v4, v7, v7
        lvx128    v39, r4, r22
        lvx128    v38, r9, r11
        vmrghw128 v55, v78, v41
        lvx128    v33, r4, r23
        vmrghw128 v54, v77, v43
        lvx128    v32, r11, r22
        vmrghw128 v53, v72, v38
        lvx128    v60, r0, r11
        vor128    v3, v79, v47
        lvx128    v59, r11, r24
        vmrglw128 v45, v77, v43
        lvx128    v37, r0, r4
        vmrghw128 v56, v64, v60
        lvx128    v36, r4, r7
        vmrghw128 v8, v87, v54
        lvx128    v35, r4, r8
        vmrghw128 v52, v71, v37
        lvx128    v34, r4, r6
        vmrglw128 v7, v87, v54
        lvx128    v58, r11, r7
        vmrghw128 v50, v67, v33
        vmulfp128 v12, v74, v12
        vmrghw128 v51, v68, v34
        vmulfp128 v11, v76, v9
        vmrghw128 v57, v91, v58
        vmrghw128 v28, v85, v52
        vor128    v4, v79, v47
        vmrglw128 v27, v85, v52
      }
      _R9 = v110;
      __asm { vmrghw128 v24, v83, v50 }
      _R5 = v129;
      __asm { vmrglw128 v23, v83, v50 }
      HIDWORD(_R25) = a36 - (_DWORD)bS_0;
      __asm { vmrglw128 v49, v64, v60 }
      _R22 = v123;
      __asm { vmrglw128 v48, v91, v58 }
      _R21 = v112;
      __asm
      {
        vmulfp128 v15, v8, v24
        vmrglw128 v46, v78, v41
        vmrglw128 v43, v72, v38
      }
      _R19 = v133;
      __asm { vmrglw128 v42, v71, v37 }
      _R23 = -80;
      __asm { vmrglw128 v9, v81, v48 }
      _R10 = -64;
      __asm { vmrglw128 v41, v68, v34 }
      _R20 = -112;
      __asm
      {
        vsel      v10, v12, v11, v25
        vmrghw128 v12, v88, v57
        vmrglw128 v11, v88, v57
        vmrglw128 v40, v67, v33
        vmr       v2, v9
        vmrglw128 v5, v78, v45
        vmr128    v60, v9
        vmulfp128 v16, v12, v28
        vmr128    v44, v10
        vnmsubfp  v18, v3, v11, v11
        vmrghw128 v10, v81, v48
        vmrghw128 v6, v78, v45
        vnmsubfp  v19, v4, v12, v12
        vmaddfp   v15, v7, v15, v23
        vmrghw128 v26, v75, v42
        vor128    v1, v76, v44
        vmrghw128 v22, v73, v40
        vor128    v3, v76, v44
        vmrglw128 v25, v75, v42
        vmrglw128 v21, v73, v40
        vnmsubfp  v14, v4, v10, v10
        vnmsubfp  v17, v1, v8, v8
        vor128    v8, v79, v47
        vnmsubfp  v31, v3, v7, v7
        vmaddfp   v16, v11, v16, v27
        vor128    v11, v76, v44
        vnmsubfp128 v60, v8, v2, v60
        vnmsubfp  v2, v1, v6, v6
        vmaddfp   v12, v6, v15, v22
        vnmsubfp  v3, v11, v5, v5
        vmaddfp   v11, v10, v16, v26
        vmaddfp   v11, v9, v11, v25
        vmr       v9, v25
        vmaddfp   v12, v5, v12, v21
        lvx128    v39, r30, r24
        lvx128    v38, r22, r11
      }
      _R18 = a36 - a42;
      __asm { lvx128    v37, r4, r21 }
      HIDWORD(_R25) = -16;
      __asm
      {
        lvx128    v36, r29, r20
        lvx128    v35, r3, r18
        vand128   v34, v11, v62
        vand128   v33, v12, v62
        vxor128   v12, v79, v34
        vxor128   v11, v76, v33
        vmaddfp   v4, v12, v19, v28
        vmaddfp   v5, v11, v17, v24
        vmaddcfp128 v9, v12, v9, v60
        vmaddfp   v6, v12, v18, v27
        vmaddfp   v7, v12, v14, v26
        vmaddfp   v12, v11, v3, v21
        vmaddfp   v8, v11, v31, v23
        vmaddfp   v10, v11, v2, v22
        lvx128    v2, r0, r31
        vmr128    v32, v4
        vmr128    v60, v5
        vmulfp128 v5, v64, v32
        vmulfp128 v11, v92, v60
        vmaddfp   v5, v6, v5, v6
        vmaddfp   v11, v8, v11, v8
        vmaddfp   v5, v7, v5, v7
        vmaddfp   v11, v10, v11, v10
        vmaddfp   v5, v9, v5, v9
        vmaddfp   v11, v12, v11, v12
        vrsqrtefp128 v59, v5
        vrsqrtefp128 v58, v11
        vmulfp128 v3, v91, v59
        vmulfp128 v4, v90, v58
        vmulfp128 v57, v91, v61
        vmulfp128 v56, v90, v61
        vmaddfp   v5, v5, v20, v3
        vspltw128 v3, v44, 0
        vmaddfp   v11, v11, v20, v4
        lvx128    v4, r3, r19
        vsubfp128 v31, v67, v4
        vmulfp128 v55, v89, v5
        lvx128    v5, r4, r5
        vmulfp128 v54, v88, v11
        lvx128    v11, r9, r11
        vsubfp128 v28, v70, v11
      }
      _R9 = v125;
      __asm { vsubfp128 v30, v69, v5 }
      _R5 = v114;
      __asm { lvx128    v41, r31, r9 }
      _R9 = -96;
      __asm
      {
        vmulfp128 v53, v7, v55
        lvx128    v7, r31, r23
        vmulfp128 v52, v9, v55
        lvx128    v9, r31, r10
        vmulfp128 v50, v10, v54
        vspltw128 v10, v47, 1
        vmulfp128 v46, v6, v55
        vspltw128 v6, v47, 3
        vmulfp128 v45, v92, v54
        vmulfp128 v48, v64, v55
        vsubfp128 v27, v71, v9
        vsubfp128 v26, v68, v7
        vmulfp128 v51, v8, v54
        vspltw128 v8, v47, 2
        vmulfp128 v49, v12, v54
        vspltw128 v12, v47, 0
        vmaddfp   v30, v6, v5, v30
        vsubfp128 v60, v73, v2
        vmaddfp   v28, v8, v11, v28
        vmrghw128 v40, v78, v52
        vmrglw128 v39, v78, v52
        vmrghw128 v43, v80, v53
        vmaddfp   v27, v10, v9, v27
        vmrglw128 v42, v80, v53
        vmaddfp   v26, v12, v7, v26
        vmrghw128 v38, v77, v50
        vmrglw128 v37, v77, v50
      }
      __asm { vspltw128 v11, v44, 1 }
      v135 = _R6;
      __asm { vmrghw128 v34, v75, v40 }
      v134 = _R8;
      __asm
      {
        vmaddfp   v31, v3, v4, v31
        lvx128    v7, r31, r8
      }
      _R6 = v111;
      __asm
      {
        vmaddcfp128 v60, v11, v60, v2
        lvx128    v2, r26, r5
      }
      __asm
      {
        lvx128    v9, r31, r7
        lvx128    v52, r27, r9
      }
      _R8 = a38 - (_DWORD)bS_0;
      __asm
      {
        lvx128    v54, r29, r24
        vmrghw128 v36, v83, v49
        lvx128    v53, r0, r29
        vmrglw128 v35, v83, v49
        vsubfp128 v14, v86, v9
      }
      _R20 = (char *)bS_0 - a42;
      __asm { vsubfp128 v15, v85, v7 }
      v136 = _R25;
      __asm
      {
        vsubfp128 v16, v84, v2
        stvx128   v34, r3, r10
      }
      _R17 = v119;
      __asm { vmrglw128 v33, v75, v40 }
      _R16 = v127;
      __asm { vmrghw128 v32, v74, v39 }
      LODWORD(_R25) = v109;
      __asm { vmrglw128 v59, v74, v39 }
      _R10 = v113;
      __asm
      {
        vmrghw128 v58, v70, v36
        vmrglw128 v57, v70, v36
      }
      _R23 = v130;
      __asm { vmrghw128 v56, v69, v35 }
      _R22 = v116;
      __asm
      {
        vmrglw128 v55, v69, v35
        lvx128    v51, r30, r8
        lvx128    v25, r6, r29
      }
      _R19 = v118;
      _R18 = v132;
      _R21 = -48;
      _R15 = v120;
      __asm { vspltw128 v5, v44, 2 }
      _R14 = v131;
      __asm { vspltw128 v4, v44, 3 }
      _R8 = v134;
      __asm { stvx128   v26, r30, r24 }
      _R6 = v135;
      __asm { stvx128   v31, r3, r20 }
      _R5 = v108;
      __asm { lvx128    v1, r30, r17 }
      _R9 = v115;
      __asm
      {
        lvx128    v31, r16, r11
        lvx128    v26, r25, r27
      }
      _R28 += 8;
      __asm
      {
        lvx128    v50, r0, r27
        vsubfp128 v17, v83, v1
        lvx128    v49, r11, r10
        vsubfp128 v23, v82, v26
        stvx128   v27, r0, r30
        vmaddfp   v16, v12, v2, v16
        lvx128    v27, r31, r5
      }
      _R5 = v117;
      __asm { stvx128   v28, r23, r11 }
      _R23 = a38 - a42;
      __asm { stvx128   v30, r4, r22 }
      _R22 = a38 - a36;
      __asm
      {
        lvx128    v30, r4, r15
        vmaddfp   v15, v4, v7, v15
        lvx128    v28, r3, r14
        vmaddfp   v14, v5, v9, v14
        lvx128    v48, r31, r9
        vsubfp128 v18, v81, v31
        stvx128   v33, r3, r21
        stvx128   v32, r19, r11
        stvx128   v59, r4, r18
        stvx128   v58, r0, r3
        stvx128   v57, r3, r7
        stvx128   v56, r3, r8
        stvx128   v55, r3, r6
        lvx128    v47, r4, r5
        vsubfp128 v22, v80, v27
        lvx128    v46, r3, r23
        vsubfp128 v19, v79, v30
        lvx128    v45, r22, r29
        vsubfp128 v21, v78, v28
        vsubfp128 v24, v77, v25
      }
      _R10 = v121;
      __asm { vmaddfp   v2, v10, v1, v17 }
      _R9 = (char *)bTa - (char *)bS_0;
      __asm { vmaddfp   v7, v8, v31, v18 }
      _R5 = v124;
      _R22 = v126;
      _R20 = 80;
      _R19 = (char *)bTa - a42;
      _R23 = 96;
      __asm { stvx128   v60, r31, r10 }
      _R18 = v128;
      _R10 = (char *)bTa - a38;
      __asm { stvx128   v16, r0, r26 }
      _R17 = (char *)bTa - a36;
      _R26 += 32;
      __asm { stvx128   v14, r30, r20 }
      _R25 = v136;
      __asm
      {
        vmaddfp   v10, v11, v27, v22
        stvx128   v15, r30, r23
        vmaddfp   v8, v6, v30, v19
        vmaddfp   v9, v3, v28, v21
        vmaddfp   v11, v5, v26, v23
        vmaddfp   v12, v4, v25, v24
        stvx128   v2, r30, r9
        stvx128   v7, r11, r5
      }
      _R30 += 32;
      _R11 += 32;
      __asm { stvx128   v10, r31, r18 }
      _R31 += 32;
      __asm { stvx128   v8, r4, r22 }
      _R4 += 32;
      __asm { stvx128   v9, r3, r19 }
      _R3 += 128;
      __asm { stvx128   v11, r10, r27 }
      _R27 += 128;
      __asm { stvx128   v12, r17, r29 }
      _R29 += 128;
      if ( --v45 == 0 )
        break;
      bR = a32;
      aR = a24;
    }
  }
}


// ========================================================================
// ?LerpU@idMD6Blend@@CAXIMPIBEPIBM010PIAMPIAE@Z
// EA  : 0x8281D668
// RVA : 0x0081D668
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::LerpU(
        unsigned int numUserChannels,
        double alpha,
        const unsigned __int8 *filter,
        const float *aU,
        const unsigned __int8 *aW,
        const float *bU,
        const unsigned __int8 *bW,
        float *outU,
        unsigned __int8 *outW,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        float a17,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22,
        float a23,
        float a24,
        float a25,
        float a26,
        float a27,
        float a28,
        float a29,
        float a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35,
        int a36)
{
  unsigned int v40; // r31
  unsigned int v42; // r29
  unsigned int v47; // ctr

  _R4 = &a22;
  a22 = alpha;
  _R11 = 0;
  __asm
  {
    lvlx128   v63, r0, r4
    vspltw128 v1, v63, 0
  }
  if ( numUserChannels != 0 )
  {
    _R30 = outW - bW;
    v40 = (numUserChannels - 1) >> 3;
    _R3 = outW;
    v42 = v40 + 1;
    _R31 = aW - bW;
    _R6 = aW - outW;
    _R28 = -16;
    _R10 = &vmx_float_one_8;
    v47 = v42;
    _R4 = bW + 16;
    _R8 = a36;
    _R29 = -16;
    __asm
    {
      lvx128    v0, r10, r28
      lvx128    v13, r0, r10
    }
    do
    {
      __asm { lvlx      v12, r11, r7 }
      _R10 = _R11 + 4;
      __asm
      {
        lvlx      v10, r11, r5
        lvlx      v11, r11, r9
        vmrghb    v9, v0, v12
        vmrghb    v8, v0, v10
        vaddubs   v5, v12, v11
        vmrghb    v4, v0, v11
        lvlx      v12, r10, r7
        vmrghh    v31, v0, v9
        lvlx      v30, r10, r5
        vmrghh    v29, v0, v8
        lvlx      v11, r10, r9
        vmrghh    v28, v0, v4
        vaddubs   v27, v12, v11
        vmrghb    v26, v0, v12
        vcuxwfp128 v62, v31, 0
        vmrghb    v25, v0, v30
        vcuxwfp128 v61, v29, 0
        vmrghb    v24, v0, v11
        vcuxwfp128 v60, v28, 0
        vspltw128 v58, v27, 0
        vmrghh    v23, v0, v26
        vmrghh    v22, v0, v25
        vmrghh    v21, v0, v24
        vspltw128 v59, v5, 0
        vcuxwfp128 v57, v23, 0
        vcuxwfp128 v56, v22, 0
        vcuxwfp128 v55, v21, 0
        vmulfp128 v12, v94, v61
        stvewx128 v59, r8, r11
        vmulfp128 v11, v92, v61
        stvewx128 v58, r8, r10
      }
      _R11 += 8;
      __asm
      {
        vmulfp128 v10, v89, v56
        vmulfp128 v9, v87, v56
        vcmpgtfp  v31, v12, v0
        vcmpgtfp  v25, v11, v0
        vmaddfp   v27, v12, v11, v1
        vcmpgtfp  v30, v11, v12
        vmulfp128 v54, v11, v1
        vcmpgtfp  v28, v10, v0
        vcmpgtfp  v29, v9, v0
        vmulfp128 v53, v9, v1
        vsel      v26, v13, v12, v31
        vcmpgtfp  v31, v9, v10
        vsel      v6, v13, v11, v25
        vsubfp128 v52, v27, v12
        vrefp     v12, v26
        vrefp     v11, v6
        vsel      v2, v13, v10, v28
        vsel      v5, v13, v9, v29
        vmr128    v51, v2
        vmr128    v50, v5
        vrefp128  v8, v51
        vnmsubfp  v2, v12, v13, v26
        vnmsubfp  v4, v11, v13, v6
        vrefp128  v7, v50
        vmaddfp   v6, v2, v12, v12
        vmaddfp   v12, v4, v11, v11
        vmaddfp   v2, v10, v9, v1
        vmulfp128 v11, v86, v6
        vor128    v6, v82, v50
        vmulfp128 v12, v84, v12
        vsubfp128 v49, v2, v10
        lvx128    v10, r6, r3
        vnmsubfp  v3, v7, v13, v6
        vsel      v4, v11, v12, v30
        vor128    v12, v83, v51
        vmaddfp   v11, v3, v7, v7
        lvx128    v7, r4, r29
        vnmsubfp  v6, v8, v13, v12
        lvx128    v12, r31, r4
        vmulfp128 v11, v81, v11
        vmaddfp   v5, v6, v8, v8
        lvx128    v8, r0, r4
        vnmsubfp  v6, v4, v10, v10
        vmulfp128 v10, v85, v5
        vmaddfp   v7, v4, v6, v7
        vsel      v9, v10, v11, v31
        stvx128   v7, r0, r3
        vmr       v11, v9
      }
      _R3 += 32;
      __asm
      {
        vnmsubfp  v10, v11, v12, v12
        vmaddfp   v12, v9, v10, v8
        stvx128   v12, r30, r4
      }
      _R4 += 32;
      --v47;
    }
    while ( v47 != 0 );
  }
}


// ========================================================================
// ?AddRST@idMD6Blend@@CAXIMPIBEPIBM1101PBM10PIAM33PIAE@Z
// EA  : 0x8281D830
// RVA : 0x0081D830
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::AddRST(
        const unsigned int numJoints,
        double alpha,
        const unsigned __int8 *filter,
        const float *aR,
        const float *aS,
        const float *aT,
        const unsigned __int8 *aW,
        const float *bR,
        const float *bS,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        const float *bT,
        const unsigned __int8 *bW,
        float *outR,
        float *outS,
        float *outT,
        float outW,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        const float *a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        const float *bS_0,
        int a45,
        const float *bTa,
        int a47,
        const unsigned __int8 *bWa)
{
  unsigned int v47; // ctr
  int v111; // [sp+0h] [-140h]
  int v112; // [sp+4h] [-13Ch]
  int v113; // [sp+Ch] [-134h]
  int v114; // [sp+10h] [-130h]
  const unsigned __int8 *v115; // [sp+14h] [-12Ch]
  int v116; // [sp+18h] [-128h]
  int v117; // [sp+24h] [-11Ch]
  int v118; // [sp+28h] [-118h]
  const unsigned __int8 *v119; // [sp+2Ch] [-114h]
  int v120; // [sp+30h] [-110h]
  int v121; // [sp+38h] [-108h]
  int v122; // [sp+3Ch] [-104h]
  const unsigned __int8 *v123; // [sp+40h] [-100h]
  int v124; // [sp+44h] [-FCh]
  int v125; // [sp+48h] [-F8h]
  int v126; // [sp+50h] [-F0h]
  char *v127; // [sp+58h] [-E8h]
  int v128; // [sp+5Ch] [-E4h]
  int v129; // [sp+60h] [-E0h]
  int v130; // [sp+64h] [-DCh]
  int v131; // [sp+68h] [-D8h]
  __int64 v132; // [sp+70h] [-D0h]
  int back_chain; // [sp+78h] [-C8h]
  int v134; // [sp+7Ch] [-C4h]
  int v135; // [sp+80h] [-C0h]
  int v136; // [sp+90h] [-B0h]
  int v137; // [sp+98h] [-A8h]

  _R4 = &outW;
  outW = alpha;
  a32 = bR;
  _R31 = 16;
  _R19 = &vmx_float_rsqrt_c1_2;
  _R28 = 0;
  __asm
  {
    lvlx128   v63, r0, r4
    vspltw128 v62, v63, 0
    lvx128    v53, r19, r31
  }
  __asm { vmulfp128 v52, v94, v53 }
  if ( numJoints != 0 )
  {
    back_chain = (char *)bS - (char *)aS;
    v126 = (char *)aT - (char *)aS;
    _R26 = bTa;
    v118 = a42 - (_DWORD)aS;
    v125 = aW - (const unsigned __int8 *)aS;
    v47 = ((numJoints - 1) >> 3) + 1;
    v137 = a36 - (_DWORD)aS;
    v122 = (char *)bS_0 - (char *)aS;
    v111 = a38 - (_DWORD)aS;
    v114 = (char *)aT - (char *)bS;
    v128 = (char *)bTa - (char *)aS;
    v129 = a42 - (_DWORD)bS;
    v116 = a36 - (_DWORD)bS;
    v113 = a38 - (_DWORD)bS;
    v124 = (char *)bS_0 - (char *)bS;
    v112 = aW - (const unsigned __int8 *)bS;
    v134 = (char *)bTa - (char *)bS;
    v127 = (char *)aT - a42;
    v115 = &aW[-a42];
    v135 = a36 - (_DWORD)aT;
    v130 = (char *)bS_0 - (char *)aT;
    v117 = (char *)bTa - (char *)aT;
    v121 = aW - (const unsigned __int8 *)aT;
    v131 = a38 - (_DWORD)aT;
    _R4 = bS + 12;
    v136 = aW - (const unsigned __int8 *)bS_0;
    v119 = &aW[-a36];
    _R31 = aT + 20;
    _R27 = a38 + 96;
    _R29 = a36 + 112;
    _R30 = bS_0 + 4;
    _R3 = a42 + 64;
    _R11 = aS + 8;
    _R24 = bWa;
    v123 = &aW[-a38];
    _R10 = -336;
    v120 = aW - (const unsigned __int8 *)bTa;
    _R8 = 0x10FFFFFF70LL;
    _R6 = -176;
    _R23 = a40;
    _R22 = -16;
    __asm { lvx128    v61, r0, r19 }
    _R25 = -16;
    __asm { lvx128    v63, r19, r10 }
    __asm { lvx128    v0, r19, r8 }
    LODWORD(_R8) = 32;
    __asm { lvx128    v62, r19, r6 }
    _R6 = 48;
    __asm { lvx128    v15, r19, r22 }
    _R20 = 64;
    _R21 = 80;
    _R22 = -64;
    while ( 1 )
    {
      __asm { lvlx128   v60, r28, r9 }
      _R19 = -48;
      _R10 = _R28 + 4;
      _R18 = back_chain;
      __asm { vspltw128 v59, v60, 0 }
      _R17 = -32;
      _R16 = -32;
      __asm
      {
        stvewx128 v59, r24, r28
        lvlx128   v58, r10, r9
        vspltw128 v57, v58, 0
        stvewx128 v57, r24, r10
        lvlx      v10, r28, r5
        lvlx      v12, r28, r23
        lvlx      v11, r10, r23
        lvx128    v56, r11, r25
        lvx128    v55, r11, r7
        lvx128    v54, r11, r17
        lvx128    v51, r0, r11
        lvx128    v50, r11, r20
      }
      _R20 = 64;
      __asm
      {
        lvx128    v49, r11, r8
        lvx128    v48, r11, r6
        lvx128    v47, r11, r21
        lvx128    v46, r4, r16
        lvx128    v45, r0, r4
        lvx128    v44, r4, r7
        lvx128    v43, r4, r6
        lvx128    v39, r4, r19
        lvx128    v38, r18, r11
        lvlx      v13, r10, r5
        vmrghb    v8, v0, v13
        vmrghb    v9, v0, v10
        lvx128    v42, r4, r8
        vmrghh    v4, v0, v8
        lvx128    v41, r4, r20
        vmrghb    v6, v0, v12
        vmrghb    v5, v0, v11
        vmrghh    v7, v0, v9
        vcuxwfp128 v37, v4, 0
        vmrghw128 v36, v86, v51
        vmrghh    v3, v0, v6
        vmrghh    v2, v0, v5
        vcuxwfp128 v40, v7, 0
        vmrghw128 v35, v88, v55
        vmrglw128 v59, v86, v51
        vmrglw128 v58, v88, v55
        vcuxwfp128 v34, v3, 0
        vcuxwfp128 v32, v2, 0
        vmrghw128 v33, v81, v50
        vmrghw128 v60, v80, v47
        vmrglw128 v57, v81, v50
        vmrglw128 v56, v80, v47
        vmrghw128 v50, v78, v45
        vmrglw128 v47, v78, v45
        vmulfp128 v51, v69, v53
        vmrghw128 v46, v76, v43
        vmrglw128 v45, v76, v43
        vmrglw128 v48, v71, v38
        vmulfp128 v55, v72, v53
        vmrghw128 v54, v71, v38
        vmrghw128 v13, v68, v35
        vmrglw128 v12, v68, v35
        vmrghw128 v9, v65, v60
        vmrglw128 v38, v80, v47
        vmrghw128 v11, v91, v58
        vmr       v29, v13
        vmr       v26, v12
        vmrglw128 v10, v91, v58
        vmr       v27, v9
        vmrglw128 v8, v65, v60
        vmrghw128 v7, v89, v56
        vmulfp128 v21, v70, v13
        vmulfp128 v44, v64, v51
        vmrglw128 v6, v89, v56
        vmrghw128 v43, v74, v41
        vmulfp128 v49, v66, v55
        vmrglw128 v39, v74, v41
        vmrghw128 v5, v86, v50
        vmulfp128 v37, v76, v52
        vmrglw128 v4, v86, v50
        vmulfp128 v40, v81, v52
        vmulfp128 v19, v70, v12
        vmrglw128 v36, v77, v39
        vmulfp128 v17, v70, v11
        vmr128    v60, v10
        vmaddfp   v14, v5, v21, v10
        vmrghw128 v2, v78, v43
        vmulfp128 v58, v70, v10
        vmrghw128 v3, v80, v47
        vmulfp128 v54, v68, v6
        vmr128    v59, v10
        vmr       v30, v5
        vmulfp128 v57, v68, v9
        vmr       v28, v2
        vmulfp128 v56, v68, v8
        vmulfp128 v55, v68, v7
        vmrglw128 v1, v78, v43
        vmrghw128 v31, v77, v39
        vmr       v23, v4
        vmr       v21, v3
      }
      _R9 = -112;
      __asm { vmr       v22, v13 }
      _R21 = a36 - (_DWORD)bS_0;
      __asm { vmr       v20, v11 }
      _R10 = -80;
      __asm
      {
        vmaddcfp128 v60, v4, v60, v19
        vmr       v16, v9
        vmaddcfp128 v59, v3, v59, v17
        vmr       v17, v7
        lvx128    v35, r29, r9
      }
      _R9 = v126;
      __asm
      {
        vnmsubfp128 v58, v30, v29, v58
        vmr       v30, v8
        vnmsubfp128 v54, v28, v27, v54
        vmr       v29, v1
        vmaddfp   v27, v4, v14, v11
        vmr       v14, v13
        vmaddfp128 v57, v2, v6, v57
        vmr       v28, v7
        vmaddfp128 v56, v1, v6, v56
        vmaddfp128 v55, v31, v6, v55
        vmaddcfp128 v14, v3, v14, v60
        vmr128    v60, v12
        vmaddcfp128 v60, v5, v60, v59
        vor128    v59, v90, v58
        vmr128    v58, v9
        vnmsubfp128 v59, v4, v26, v59
        vmr       v4, v7
        vmaddcfp128 v58, v31, v58, v56
        vor128    v56, v86, v54
        vmaddcfp128 v4, v1, v4, v57
        vmr128    v57, v8
        vnmsubfp128 v56, v1, v30, v56
        vor128    v1, v72, v40
        vnmsubfp  v30, v3, v27, v12
        vor128    v3, v72, v40
        vnmsubfp  v27, v5, v14, v11
        vmaddcfp128 v57, v2, v57, v55
        vor128    v26, v92, v60
        vnmsubfp  v19, v1, v11, v11
        vnmsubfp  v18, v3, v12, v12
        vor128    v25, v91, v59
        vnmsubfp128 v26, v23, v22, v26
        vor128    v23, v90, v58
        vnmsubfp  v24, v31, v4, v8
        vnmsubfp128 v25, v21, v20, v25
        vor128    v21, v88, v56
        vmulfp128 v20, v13, v30
        vnmsubfp128 v23, v2, v17, v23
        vor128    v2, v69, v37
        vor128    v22, v89, v57
        vnmsubfp  v17, v1, v13, v13
        vnmsubfp128 v21, v31, v28, v21
        vnmsubfp  v1, v2, v9, v9
        vnmsubfp128 v22, v29, v16, v22
        vnmsubfp  v2, v3, v10, v10
        vmulfp128 v29, v9, v24
        vor128    v9, v69, v37
        vmaddfp   v28, v12, v20, v27
        vor128    v12, v69, v37
        vnmsubfp  v3, v12, v8, v8
        vmaddfp   v31, v8, v29, v23
        vnmsubfp  v5, v12, v6, v6
        lvx128    v34, r30, r21
        vmaddfp   v12, v11, v28, v26
      }
      _R19 = v114;
      __asm { vmaddfp   v13, v7, v31, v22 }
      _R21 = v127;
      __asm { vnmsubfp  v4, v9, v7, v7 }
      _R18 = v135;
      __asm
      {
        vmaddfp   v12, v10, v12, v25
        vmaddfp   v13, v6, v13, v21
        vand128   v33, v12, v62
        vand128   v32, v13, v62
        vxor128   v13, v72, v33
        vxor128   v12, v69, v32
        lvx128    v32, r18, r31
        vmaddfp   v8, v13, v17, v30
        vmaddfp   v9, v12, v1, v24
        vspltw128 v24, v40, 1
        vmaddfp   v29, v12, v3, v23
        vspltw128 v23, v40, 2
        vmaddfp   v30, v12, v4, v22
        vmaddfp   v31, v12, v5, v21
        vmaddfp   v10, v13, v18, v27
        vmaddfp   v11, v13, v19, v26
        vmaddfp   v7, v13, v2, v25
        vspltw128 v25, v40, 0
        vmr128    v60, v8
        vmr128    v59, v9
        vmulfp128 v12, v92, v60
        vmulfp128 v13, v91, v59
        vmaddfp   v12, v10, v12, v10
        vmaddfp   v13, v29, v13, v29
        vmaddfp   v12, v11, v12, v11
        vmaddfp   v13, v30, v13, v30
        vmaddfp   v12, v7, v12, v7
        vmaddfp   v13, v31, v13, v31
        vrsqrtefp128 v58, v12
        vrsqrtefp128 v57, v13
        vmulfp128 v8, v90, v58
        vmulfp128 v56, v90, v61
        vmulfp128 v9, v89, v57
        vmulfp128 v55, v89, v61
        vmaddfp   v12, v12, v15, v8
        lvx128    v8, r0, r31
        vmaddfp   v6, v13, v15, v9
        vand128   v9, v66, v63
        lvx128    v13, r31, r10
      }
      _R10 = v137;
      __asm
      {
        lvx128    v42, r10, r11
        vand128   v4, v74, v63
        vmulfp128 v54, v88, v12
        lvx128    v12, r31, r22
        vnmsubfp  v1, v12, v12, v9
        lvx128    v9, r3, r21
        vmulfp128 v51, v87, v6
      }
      _R21 = v129;
      __asm
      {
        vmulfp128 v49, v11, v54
        vand128   v11, v67, v63
        vmulfp128 v50, v10, v54
        lvx128    v10, r19, r4
        vmulfp128 v48, v92, v54
      }
      _R19 = a36 - a42;
      __asm
      {
        vmulfp128 v47, v7, v54
        vnmsubfp  v3, v13, v13, v11
        lvx128    v11, r9, r11
      }
      _R9 = v116;
      __asm
      {
        vmulfp128 v46, v29, v51
        vmulfp128 v45, v30, v51
        lvx128    v34, r3, r19
        vmulfp128 v44, v31, v51
        vmulfp128 v43, v91, v51
        vnmsubfp  v12, v1, v12, v24
        lvx128    v41, r9, r4
      }
      _R9 = v118;
      __asm
      {
        vmrghw128 v39, v80, v49
        vmrghw128 v36, v82, v47
        vnmsubfp  v13, v3, v13, v25
        vmrglw128 v38, v80, v49
        vmrglw128 v35, v82, v47
        vmrghw128 v33, v71, v36
        vmrglw128 v60, v71, v36
        stvx128   v12, r0, r30
        vand128   v12, v73, v63
        stvx128   v13, r30, r25
        vand128   v13, v66, v63
        vmrghw128 v54, v70, v35
        lvx128    v57, r29, r25
        vmrglw128 v51, v70, v35
        vnmsubfp  v26, v11, v11, v4
        vmrghw128 v59, v78, v44
        vnmsubfp  v27, v10, v10, v12
        vmrglw128 v55, v78, v44
        lvx128    v46, r0, r29
        vnmsubfp  v28, v9, v9, v13
        vand128   v4, v64, v63
      }
      _R19 = v120;
      __asm
      {
        vand128   v12, v89, v63
        vmrghw128 v58, v75, v45
      }
      _R17 = -96;
      __asm
      {
        vand128   v13, v78, v63
        lvx128    v7, r31, r7
        lvx128    v6, r31, r8
        vnmsubfp  v29, v8, v8, v4
        stvx128   v54, r9, r11
      }
      _R9 = v121;
      __asm { stvx128   v51, r4, r21 }
      _R21 = v131;
      __asm
      {
        vmrghw128 v50, v90, v59
        vnmsubfp  v30, v7, v7, v12
        vmrglw128 v49, v90, v59
        vnmsubfp  v1, v6, v6, v13
        vmrglw128 v56, v75, v45
        lvx128    v59, r26, r19
        lvx128    v58, r27, r17
        vspltw128 v22, v40, 3
        vmaddcfp128 v58, v25, v58, v59
        vmr128    v57, v11
        vmr128    v59, v10
        lvx128    v11, r31, r9
        lvx128    v10, r31, r21
      }
      _R10 = -48;
      __asm { vmrghw128 v48, v88, v55 }
      _R18 = v136;
      __asm { vmrglw128 v47, v88, v55 }
      _R17 = a38 - (_DWORD)bS_0;
      _R9 = v125;
      __asm { vspltw128 v20, v37, 1 }
      _R21 = v111;
      __asm
      {
        vmr       v3, v22
        vspltw128 v21, v37, 0
        vmr       v2, v23
        vspltw128 v19, v37, 2
        stvx128   v60, r3, r10
        vspltw128 v18, v37, 3
        lvx128    v14, r30, r18
        lvx128    v60, r17, r30
        vnmsubfp128 v59, v27, v3, v59
        lvx128    v17, r9, r11
        vnmsubfp  v4, v29, v8, v20
        lvx128    v16, r21, r11
        vmaddfp   v13, v10, v11, v20
      }
      __asm { lvx128    v11, r0, r27 }
      _R18 = v123;
      __asm { stvx128   v33, r3, r22 }
      _R16 = v112;
      __asm { stvx128   v50, r0, r3 }
      _R17 = v113;
      __asm { stvx128   v49, r3, r7 }
      _R15 = v115;
      __asm { stvx128   v48, r3, r8 }
      _R14 = a38 - a42;
      __asm { stvx128   v47, r3, r6 }
      _R10 = v117;
      _R19 = 96;
      _R9 = v119;
      __asm { vnmsubfp  v27, v28, v9, v21 }
      __asm
      {
        vnmsubfp  v8, v30, v7, v19
        vmr       v25, v24
        vnmsubfp128 v57, v26, v2, v57
        vnmsubfp  v12, v1, v6, v18
      }
      __asm
      {
        lvx128    v2, r3, r14
        stvx128   v12, r30, r19
        vmaddcfp128 v25, v92, v25, v14
        lvx128    v12, r18, r27
        vmaddfp   v28, v16, v17, v23
        stvx128   v13, r31, r10
        vmaddfp   v11, v11, v12, v19
        lvx128    v26, r17, r4
      }
      _R17 = v122;
      __asm { lvx128    v31, r16, r4 }
      _R10 = (char *)bTa - a42;
      __asm
      {
        lvx128    v3, r3, r15
        vmaddfp   v5, v26, v31, v22
        lvx128    v13, r9, r29
        vmaddfp   v9, v2, v3, v21
      }
      _R16 = v124;
      _R21 = 80;
      __asm { stvx128   v57, r17, r11 }
      _R15 = (char *)bTa - (char *)bS_0;
      _R19 = (char *)bS_0 - a42;
      __asm { stvx128   v58, r0, r26 }
      _R18 = v128;
      _R28 += 8;
      _R9 = v130;
      _R26 += 32;
      _R17 = (char *)bTa - a36;
      __asm
      {
        stvx128   v59, r16, r4
        stvx128   v25, r15, r30
        stvx128   v27, r3, r19
        stvx128   v28, r11, r18
      }
      _R11 += 32;
      __asm { stvx128   v4, r9, r31 }
      _R31 += 32;
      __asm { stvx128   v8, r30, r21 }
      _R30 += 32;
      __asm { stvx128   v9, r10, r3 }
      _R14 = a38 - a36;
      _R3 += 128;
      v132 = _R8;
      _R8 = (char *)bTa - a38;
      __asm { lvx128    v12, r14, r29 }
      _R14 = v134;
      __asm
      {
        vmaddfp   v13, v12, v13, v18
        stvx128   v11, r8, r27
      }
      _R8 = v132;
      _R27 += 128;
      __asm { stvx128   v5, r14, r4 }
      _R4 += 32;
      __asm { stvx128   v13, r17, r29 }
      _R29 += 128;
      if ( --v47 == 0 )
        break;
      bR = a32;
    }
  }
}


// ========================================================================
// ?SubRST@idMD6Blend@@CAXIMPIBEPIBM1101110PIAM22PIAE@Z
// EA  : 0x8281E008
// RVA : 0x0081E008
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMD6Blend::SubRST(
        unsigned int numJoints,
        double alpha,
        __int64 aR,
        const float *aS,
        const float *aT,
        const unsigned __int8 *aW,
        const float *bR,
        const float *bS,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        const float *bT,
        const unsigned __int8 *bW,
        float *outR,
        float *outS,
        float *outT,
        float outW,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        const float *a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        unsigned int a39,
        int a40,
        int a41,
        int a42,
        const float *bS_0,
        int a44,
        const float *bTa,
        int a46,
        const unsigned __int8 *bWa)
{
  unsigned int v46; // ctr
  int back_chain; // [sp+4h] [-14Ch]
  int v108; // [sp+8h] [-148h]
  int v109; // [sp+Ch] [-144h]
  int v110; // [sp+14h] [-13Ch]
  int v111; // [sp+18h] [-138h]
  int v112; // [sp+1Ch] [-134h]
  int v113; // [sp+20h] [-130h]
  int v114; // [sp+24h] [-12Ch]
  const unsigned __int8 *v115; // [sp+28h] [-128h]
  int v116; // [sp+2Ch] [-124h]
  int v117; // [sp+34h] [-11Ch]
  const unsigned __int8 *v118; // [sp+3Ch] [-114h]
  int v119; // [sp+40h] [-110h]
  int v120; // [sp+44h] [-10Ch]
  int v121; // [sp+48h] [-108h]
  int v122; // [sp+4Ch] [-104h]
  int v123; // [sp+54h] [-FCh]
  int v124; // [sp+58h] [-F8h]
  int v125; // [sp+5Ch] [-F4h]
  int v126; // [sp+60h] [-F0h]
  int v127; // [sp+64h] [-ECh]
  int v128; // [sp+6Ch] [-E4h]
  int v129; // [sp+74h] [-DCh]
  int v130; // [sp+80h] [-D0h]
  const unsigned __int8 *v131; // [sp+84h] [-CCh]
  char *v132; // [sp+8Ch] [-C4h]
  __int64 v133; // [sp+90h] [-C0h]
  __int64 v134; // [sp+A0h] [-B0h]
  __int64 v135; // [sp+A8h] [-A8h]
  unsigned __int64 v136; // [sp+B0h] [-A0h]

  _R4 = &outW;
  a31 = bR;
  outW = alpha;
  _R31 = 16;
  _R9 = &vmx_float_rsqrt_c1_2;
  _R28 = 0;
  __asm
  {
    lvlx128   v63, r0, r4
    vspltw128 v62, v63, 0
    lvx128    v52, r9, r31
  }
  __asm { vmulfp128 v51, v94, v52 }
  if ( numJoints != 0 )
  {
    back_chain = (char *)bS - (char *)aS;
    v125 = (char *)aT - (char *)aS;
    _R26 = bTa;
    v114 = a41 - (_DWORD)aS;
    v130 = aW - (const unsigned __int8 *)aS;
    v46 = ((numJoints - 1) >> 3) + 1;
    v123 = a35 - (_DWORD)aS;
    v117 = (char *)bS_0 - (char *)aS;
    v120 = a37 - (_DWORD)aS;
    v112 = (char *)aT - (char *)bS;
    v119 = (char *)bTa - (char *)aS;
    v127 = a41 - (_DWORD)bS;
    v109 = a35 - (_DWORD)bS;
    v122 = a37 - (_DWORD)bS;
    v116 = (char *)bS_0 - (char *)bS;
    v129 = aW - (const unsigned __int8 *)bS;
    v121 = (char *)bTa - (char *)bS;
    v132 = (char *)aT - a41;
    v131 = &aW[-a41];
    v110 = a35 - (_DWORD)aT;
    v124 = (char *)bS_0 - (char *)aT;
    v126 = (char *)bTa - (char *)aT;
    v111 = aW - (const unsigned __int8 *)aT;
    v113 = a37 - (_DWORD)aT;
    HIDWORD(aR) = bS + 12;
    v115 = &aW[-a35];
    v108 = aW - (const unsigned __int8 *)bS_0;
    _R31 = aT + 20;
    _R27 = a37 + 16;
    _R29 = bS_0 + 28;
    _R30 = a35 + 96;
    _R3 = a41 + 64;
    _R11 = aS + 8;
    __asm { lvx128    v58, r0, r9 }
    v118 = &aW[-a37];
    _R10 = -336;
    v128 = aW - (const unsigned __int8 *)bTa;
    _R8 = -112;
    _R7 = -144;
    _R25 = __PAIR64__(a39, (unsigned int)bWa);
    _R6 = -128;
    _R23 = -176;
    _R22 = -16;
    __asm
    {
      lvx128    v63, r9, r10
      lvx128    v62, r9, r8
    }
    __asm { lvx128    v0, r9, r7 }
    _R8 = 0x2000000010LL;
    __asm { lvx128    v13, r9, r6 }
    __asm { lvx128    v60, r9, r23 }
    _R6 = 48;
    __asm { lvx128    v59, r9, r22 }
    _R20 = 64;
    _R21 = -48;
    _R22 = -80;
    _R23 = -64;
    do
    {
      _R9 = a31;
      _R19 = -16;
      _R10 = _R28 + 4;
      _R18 = back_chain;
      _R17 = -32;
      _R16 = 80;
      _R15 = -32;
      __asm
      {
        lvlx128   v61, r28, r9
        vspltw128 v57, v61, 0
        stvewx128 v57, r25, r28
        lvlx128   v56, r10, r9
        vspltw128 v55, v56, 0
        stvewx128 v55, r25, r10
        lvlx      v9, r28, r5
        lvlx      v11, r28, r24
        lvlx      v10, r10, r24
        lvx128    v54, r11, r19
        lvx128    v53, r11, r8
        lvx128    v50, r11, r17
        lvx128    v49, r0, r11
        lvx128    v48, r11, r20
      }
      _R20 = 64;
      __asm
      {
        lvx128    v32, r11, r7
        lvx128    v47, r11, r6
        lvx128    v46, r11, r16
        lvx128    v43, r11, r18
        lvx128    v42, r0, r4
        lvx128    v45, r4, r21
        lvx128    v44, r4, r15
        lvlx      v12, r10, r5
        vmrghb    v7, v0, v12
        vmrghb    v8, v0, v9
        lvx128    v37, r4, r7
        lvx128    v36, r4, r20
        vmrghh    v4, v0, v7
        vmrghb    v5, v0, v11
        lvx128    v39, r4, r6
        vmrghb    v3, v0, v10
        lvx128    v40, r4, r8
        vmrghh    v6, v0, v8
        vcuxwfp128 v38, v4, 0
        vmrglw128 v33, v86, v53
        vmrghh    v2, v0, v5
        vmrghh    v1, v0, v3
        vcuxwfp128 v41, v6, 0
        vmrghw128 v56, v86, v53
        vmrglw128 v35, v82, v49
        vcuxwfp128 v34, v2, 0
        vmrghw128 v61, v82, v49
        vcuxwfp128 v57, v1, 0
        vmrghw128 v55, v64, v48
        vmrglw128 v50, v64, v48
        vmrghw128 v49, v79, v46
        vmrglw128 v48, v79, v46
        vmrghw128 v47, v77, v43
        vmrghw128 v46, v76, v42
        vmulfp128 v53, v70, v52
        vmrglw128 v45, v77, v43
        vmrglw128 v44, v76, v42
        vmrglw128 v9, v67, v33
        vmulfp128 v54, v73, v52
        vmrghw128 v41, v72, v39
        vmulfp128 v43, v66, v54
        vmrglw128 v38, v69, v36
        vmulfp128 v42, v89, v53
        vmrglw128 v40, v72, v39
        vmrghw128 v39, v69, v36
        vmr       v24, v9
        vmrghw128 v10, v67, v33
        vmrghw128 v12, v93, v56
        vmrglw128 v11, v93, v56
        vmrghw128 v8, v87, v49
        vmrglw128 v7, v87, v49
        vmrghw128 v6, v82, v48
        vmrglw128 v5, v82, v48
        vmrglw128 v37, v77, v44
        vmrghw128 v4, v79, v46
        vmrglw128 v3, v79, v46
        vmulfp128 v36, v75, v51
        vmulfp128 v35, v74, v51
        vmrglw128 v34, v72, v38
        vmulfp128 v17, v69, v12
        vmrghw128 v1, v73, v39
        vmulfp128 v56, v66, v8
        vmr       v22, v5
        vmulfp128 v54, v66, v6
        vmrghw128 v30, v72, v38
        vmulfp128 v14, v69, v11
        vmrghw128 v2, v77, v44
        vmr       v23, v1
        vmulfp128 v61, v69, v10
        vmulfp128 v55, v66, v7
        vmrglw128 v31, v73, v39
        vmr       v18, v5
        vmulfp128 v57, v69, v9
        vmr       v19, v30
        vmulfp128 v53, v66, v5
        vmr       v25, v2
      }
      _R9 = v123;
      __asm { vmr       v21, v31 }
      _R21 = v109;
      __asm { vmr       v20, v5 }
      _R19 = a35 - a41;
      __asm
      {
        vmr       v27, v4
        lvx128    v33, r30, r22
        vnmsubfp  v15, v4, v17, v9
        vmr       v26, v11
        vnmsubfp128 v56, v23, v22, v56
        vmr       v22, v8
        vnmsubfp128 v54, v19, v18, v54
        vmr       v23, v30
        vnmsubfp  v14, v3, v14, v9
        vmr       v17, v11
        vnmsubfp128 v61, v25, v24, v61
        vmr       v25, v31
        vnmsubfp128 v55, v21, v20, v55
        vmr       v24, v6
        vmaddfp128 v57, v4, v12, v57
        vmr       v21, v1
        vmr       v20, v7
      }
      _R18 = v110;
      _R10 = -96;
      __asm
      {
        vnmsubfp  v19, v3, v15, v10
        vor128    v16, v88, v56
        vnmsubfp  v18, v2, v14, v12
        vor128    v29, v93, v61
        vnmsubfp128 v16, v25, v24, v16
        vor128    v15, v87, v55
        vmaddcfp128 v17, v3, v17, v57
        vnmsubfp128 v29, v27, v26, v29
        vnmsubfp128 v15, v23, v22, v15
        vor128    v22, v86, v54
        vmaddfp   v28, v2, v19, v11
        vnmsubfp128 v22, v21, v20, v22
        vmr       v21, v8
        vmaddfp   v27, v4, v18, v10
        vor128    v4, v68, v36
        vmaddfp   v24, v30, v16, v7
        vmaddcfp128 v21, v1, v21, v53
        vmaddfp   v25, v2, v17, v10
        vor128    v2, v68, v36
        vmaddfp   v26, v3, v29, v12
        vor128    v3, v68, v36
        vmaddfp   v23, v1, v15, v6
        vnmsubfp  v20, v4, v12, v12
        vor128    v4, v67, v35
        vnmsubfp  v1, v2, v9, v9
        vmulfp128 v16, v12, v28
        vor128    v12, v68, v36
        vnmsubfp  v19, v3, v11, v11
        vor128    v3, v67, v35
        vmaddfp   v22, v31, v22, v8
        vnmsubfp  v17, v4, v8, v8
        vnmsubfp  v18, v12, v10, v10
        vmulfp128 v15, v8, v24
        vnmsubfp  v2, v3, v7, v7
        vmaddfp   v31, v31, v21, v7
        vnmsubfp  v3, v4, v6, v6
        vmaddfp   v16, v11, v16, v27
        vor128    v11, v67, v35
        vnmsubfp  v4, v11, v5, v5
        vmaddfp   v21, v7, v15, v23
        vmaddfp   v12, v10, v16, v26
        lvx128    v32, r11, r9
        vmaddfp   v8, v30, v31, v6
        lvx128    v61, r4, r21
        vmaddfp   v11, v6, v21, v22
        lvx128    v57, r3, r19
        vand128   v56, v65, v63
        lvx128    v55, r30, r10
        vand128   v54, v64, v63
        lvx128    v53, r18, r31
        vand128   v49, v93, v63
      }
      _R17 = v125;
      __asm { vand128   v48, v89, v63 }
      _R16 = v112;
      __asm { vand128   v50, v87, v63 }
      _R9 = v132;
      __asm
      {
        vand128   v47, v85, v63
        vspltw128 v46, v36, 0
        vor128    v29, v80, v62
        vmaddfp   v12, v9, v12, v25
        vmaddfp   v11, v5, v11, v8
        vand128   v45, v12, v60
        vand128   v44, v11, v60
        vxor128   v12, v68, v45
        vxor128   v11, v67, v44
        vmaddfp   v6, v12, v20, v28
        vor128    v28, v86, v62
        vmaddfp   v9, v12, v19, v27
        vor128    v27, v88, v62
        vmaddfp   v4, v11, v4, v8
        vmaddfp   v7, v11, v17, v24
        vor128    v17, v81, v62
        vmaddfp   v10, v12, v18, v26
        vor128    v26, v82, v62
        vmaddfp   v2, v11, v2, v23
        vmaddfp   v3, v11, v3, v22
        vmaddfp   v12, v12, v1, v25
        vrefp     v1, v17
        vmr128    v43, v6
        vmr128    v42, v7
        vmulfp128 v8, v75, v43
        vmulfp128 v11, v74, v42
        vmaddfp   v8, v9, v8, v9
        vmaddfp   v11, v2, v11, v2
        vmaddfp   v8, v10, v8, v10
        vmaddfp   v11, v3, v11, v3
        vmaddfp   v8, v12, v8, v12
        vmaddfp   v11, v4, v11, v4
        vrsqrtefp128 v41, v8
        vrsqrtefp128 v40, v11
        vmulfp128 v6, v73, v41
        vmulfp128 v39, v73, v58
        vmulfp128 v7, v72, v40
        vmulfp128 v38, v72, v58
        vmaddcfp128 v8, v6, v8, v59
        vmaddcfp128 v11, v7, v11, v59
        vmulfp128 v37, v71, v8
        lvx128    v8, r3, r9
        vmulfp128 v34, v70, v11
        lvx128    v11, r31, r22
        vmulfp128 v33, v9, v37
        lvx128    v9, r4, r16
        vmulfp128 v32, v10, v37
        lvx128    v10, r31, r23
        vmulfp128 v61, v12, v37
        lvx128    v12, r11, r17
        vmulfp128 v57, v75, v37
        vmulfp128 v43, v2, v34
        vmulfp128 v41, v3, v34
        vmulfp128 v40, v4, v34
        vmulfp128 v39, v74, v34
        vrefp     v4, v26
        vrefp     v3, v27
        vrefp     v2, v28
        vmrghw128 v55, v65, v61
        vmrghw128 v53, v89, v32
        vmrglw128 v45, v89, v32
        vmrglw128 v44, v65, v61
        vmrghw128 v38, v85, v55
        vmrglw128 v37, v85, v55
        vmrghw128 v34, v77, v44
        vrefp     v31, v29
        vor128    v47, v79, v62
        vmr       v15, v2
        vmrglw128 v33, v77, v44
        vmr128    v55, v13
        vmrghw128 v49, v75, v40
        vmr128    v61, v4
        vmrghw128 v48, v71, v41
        vrefp128  v30, v47
        vmr128    v53, v13
        vmr       v14, v3
        vmrglw128 v45, v71, v41
        vnmsubfp128 v55, v15, v28, v55
        vmr       v16, v1
        vmr128    v54, v13
        vmrglw128 v44, v75, v40
        vmr128    v56, v13
        vnmsubfp128 v53, v93, v26, v53
        vmr128    v57, v13
      }
      _R9 = v114;
      __asm
      {
        vmr128    v61, v13
        vmrglw128 v41, v80, v49
        vnmsubfp128 v54, v14, v27, v54
        vmrghw128 v42, v80, v49
        vmr       v18, v31
        vnmsubfp128 v56, v16, v17, v56
        vmr       v16, v2
        vmrghw128 v40, v77, v44
        vmrglw128 v39, v77, v44
      }
      _R19 = v127;
      __asm
      {
        lvx128    v48, r0, r30
        vspltw128 v32, v36, 1
        vnmsubfp128 v57, v18, v29, v57
        vmr       v17, v30
        vor128    v18, v79, v47
        vspltw128 v50, v36, 2
        vspltw128 v43, v36, 3
        stvx128   v34, r11, r9
        vmaddcfp128 v16, v87, v16, v2
      }
      _R21 = -48;
      __asm
      {
        vmr       v14, v4
        vspltw128 v36, v35, 0
        vnmsubfp128 v61, v17, v18, v61
        vmr       v15, v3
        vmr       v2, v1
        lvx128    v44, r30, r8
        vmr       v17, v31
        lvx128    v6, r31, r8
        vand128   v34, v80, v63
        stvx128   v33, r4, r19
        vspltw128 v49, v35, 1
        stvx128   v41, r3, r8
        vspltw128 v45, v35, 2
        vmaddcfp128 v14, v85, v14, v4
      }
      v133 = _R8;
      __asm
      {
        lvx128    v7, r0, r31
        lvx128    v5, r31, r7
      }
      _R9 = v116;
      _R19 = (char *)bS_0 - a41;
      __asm { vspltw128 v35, v35, 3 }
      _R18 = v117;
      __asm { stvx128   v38, r3, r23 }
      _R16 = v128;
      __asm { stvx128   v37, r3, r21 }
      _R15 = v118;
      __asm { stvx128   v42, r0, r3 }
      _R14 = v130;
      __asm { stvx128   v40, r3, r7 }
      LODWORD(_R8) = v120;
      __asm
      {
        vor128    v24, v78, v46
        stvx128   v39, r3, r6
        vor128    v25, v64, v32
        vor128    v26, v82, v50
      }
      _R17 = -112;
      __asm
      {
        vor128    v27, v75, v43
        vmaddcfp128 v15, v86, v15, v3
        vor128    v28, v68, v36
        vmaddcfp128 v2, v88, v2, v1
        vand128   v33, v76, v63
        vmaddcfp128 v17, v89, v17, v31
        vor128    v53, v66, v62
        vnmsubfp  v18, v11, v11, v14
        vor128    v48, v65, v62
        vnmsubfp  v1, v9, v9, v2
        lvx128    v55, r26, r16
        vnmsubfp  v20, v10, v10, v15
        lvx128    v56, r27, r15
        vnmsubfp  v31, v12, v12, v16
        vmr128    v54, v13
        vnmsubfp  v2, v8, v8, v17
        vor128    v22, v64, v32
        vrefp128  v4, v53
        lvx128    v21, r0, r27
        vrefp128  v3, v48
      }
      v135 = *(__int64 *)((char *)&_R8 + 4);
      HIDWORD(_R8) = v129;
      __asm { lvx128    v57, r11, r14 }
      __asm { vor128    v29, v81, v49 }
      _R6 = v122;
      _R28 += 8;
      v134 = aR;
      v136 = _R25;
      __asm { vnmsubfp  v23, v18, v11, v24 }
      LODWORD(aR) = v131;
      __asm
      {
        vnmsubfp  v11, v1, v9, v27
        vmr       v1, v30
        vnmsubfp  v24, v20, v10, v25
        vor128    v20, v78, v46
        vnmsubfp  v10, v31, v12, v26
      }
      _R25 = a37 - a41;
      __asm
      {
        vnmsubfp  v12, v2, v8, v28
        vor128    v26, v75, v43
        vmaddcfp128 v1, v93, v1, v30
        lvx128    v61, r7, r4
        vmr       v2, v3
        lvx128    v25, r6, r4
        lvx128    v14, r3, r5
        vor128    v31, v81, v49
        lvx128    v27, r25, r3
        vor128    v8, v67, v35
        stvx128   v23, r29, r17
      }
      _R17 = v113;
      __asm
      {
        stvx128   v11, r9, r4
        vor128    v11, v85, v53
        stvx128   v24, r29, r10
      }
      _R10 = -16;
      _R9 = v108;
      __asm
      {
        vor128    v24, v82, v50
        stvx128   v12, r3, r19
        vor128    v12, v80, v48
        vnmsubfp  v18, v4, v13, v11
      }
      _R19 = a37 - (_DWORD)bS_0;
      __asm
      {
        lvx128    v23, r11, r8
        vnmsubfp  v17, v7, v7, v1
        lvx128    v19, r27, r10
        vor128    v11, v77, v45
        vnmsubfp128 v55, v19, v20, v55
        vor128    v19, v88, v56
        vnmsubfp128 v54, v2, v12, v54
        lvx128    v20, r9, r29
        stvx128   v10, r11, r18
      }
      _R18 = v111;
      _R9 = v115;
      __asm
      {
        lvx128    v30, r31, r17
        vnmsubfp128 v19, v21, v22, v19
        vor128    v22, v89, v57
      }
      _R17 = v119;
      __asm
      {
        vor128    v12, v67, v35
        vor128    v2, v77, v45
        lvx128    v15, r31, r18
      }
      _R18 = (char *)bTa - a37;
      __asm
      {
        vnmsubfp128 v22, v23, v24, v22
        vor128    v24, v93, v61
        vmaddfp   v18, v18, v4, v4
        lvx128    v4, r19, r29
      }
      _R19 = a37 - a35;
      __asm { lvx128    v16, r30, r9 }
      _R9 = v121;
      __asm
      {
        vnmsubfp128 v24, v25, v26, v24
        vmaddfp128 v3, v86, v3, v3
        lvx128    v1, r30, r19
        vnmsubfp  v26, v27, v14, v28
      }
      _R8 = (char *)bTa - (char *)bS_0;
      __asm { vnmsubfp  v28, v17, v7, v29 }
      __asm { vnmsubfp  v7, v4, v20, v8 }
      _R19 = (char *)bTa - a41;
      __asm { vnmsubfp  v8, v6, v6, v18 }
      _R16 = v124;
      __asm { vnmsubfp  v10, v5, v5, v3 }
      _R15 = v126;
      __asm { vnmsubfp  v29, v30, v15, v31 }
      _R14 = (char *)bTa - a35;
      __asm
      {
        vnmsubfp  v31, v1, v16, v2
        stvx128   v55, r0, r26
        stvx128   v19, r27, r18
      }
      __asm { stvx128   v22, r11, r17 }
      aR = v134;
      __asm { stvx128   v24, r9, r4 }
      _R25 = v136;
      _R27 += 128;
      _R26 += 32;
      __asm { stvx128   v26, r19, r3 }
      _R11 += 32;
      __asm { stvx128   v28, r16, r31 }
      HIDWORD(aR) = HIDWORD(v134) + 128;
      __asm { stvx128   v7, r29, r8 }
      _R8 = v133;
      __asm { vnmsubfp  v9, v8, v6, v11 }
      _R3 += 128;
      __asm
      {
        vnmsubfp  v11, v10, v5, v12
        stvx128   v29, r31, r15
      }
      _R31 += 32;
      __asm
      {
        stvx128   v31, r30, r14
        stvx128   v9, r30, r7
      }
      *(__int64 *)((char *)&_R8 + 4) = v135;
      __asm { stvx128   v11, r0, r29 }
      _R30 += 128;
      _R29 += 32;
      --v46;
    }
    while ( v46 != 0 );
  }
}


// ========================================================================
// ?AddSubU@idMD6Blend@@CAXIMPIBEPIBM010PIAMPIAE@Z
// EA  : 0x8281E8F8
// RVA : 0x0081E8F8
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::AddSubU(
        const unsigned int numUserChannels,
        double alpha,
        const unsigned __int8 *filter,
        const float *aU,
        const unsigned __int8 *aW,
        const float *bU,
        const unsigned __int8 *bW,
        float *outU,
        unsigned __int8 *outW,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        float a17,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22,
        float a23,
        float a24,
        float a25,
        float a26,
        float a27,
        float a28,
        float a29,
        float a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35,
        int a36)
{
  unsigned int v47; // ctr

  _R4 = &a22;
  a22 = alpha;
  _R31 = 160;
  _R28 = &vmx_float_zero_1;
  _R11 = 0;
  __asm
  {
    lvlx128   v63, r0, r4
    vspltw128 v62, v63, 0
    lvx128    v63, r28, r31
  }
  __asm { vmulfp128 v62, v94, v63 }
  if ( numUserChannels != 0 )
  {
    __asm { lvx128    v0, r0, r28 }
    _R30 = outW - bW;
    _R4 = bW + 16;
    _R31 = aW - bW;
    _R8 = a36;
    _R6 = aW - outW;
    v47 = ((numUserChannels - 1) >> 3) + 1;
    _R3 = outW;
    _R29 = -16;
    do
    {
      __asm { lvlx128   v61, r11, r7 }
      _R10 = _R11 + 4;
      __asm
      {
        vspltw128 v60, v61, 0
        stvewx128 v60, r8, r11
        lvlx128   v59, r10, r7
        vspltw128 v58, v59, 0
        stvewx128 v58, r8, r10
        lvlx      v7, r11, r5
        lvlx      v10, r11, r9
      }
      _R11 += 8;
      __asm
      {
        lvlx      v8, r10, r9
        lvlx      v13, r10, r5
        vmrghb    v5, v0, v13
        vmrghb    v6, v0, v7
        lvx128    v9, r6, r3
        vmrghh    v1, v0, v5
        lvx128    v12, r31, r4
        vmrghb    v3, v0, v10
        lvx128    v11, r0, r4
        vmrghb    v2, v0, v8
        lvx128    v8, r4, r29
        vmrghh    v4, v0, v6
        vcuxwfp128 v56, v1, 0
        vmrghh    v31, v0, v3
        vmrghh    v30, v0, v2
        vcuxwfp128 v57, v4, 0
        vcuxwfp128 v55, v31, 0
        vcuxwfp128 v54, v30, 0
        vmulfp128 v52, v88, v63
        vmulfp128 v53, v89, v63
        vmulfp128 v50, v86, v52
        vmulfp128 v51, v87, v53
        vmulfp128 v13, v82, v62
        vmulfp128 v10, v83, v62
        vmaddfp   v13, v11, v12, v13
        vmaddfp   v10, v8, v9, v10
        stvx128   v13, r30, r4
      }
      _R4 += 32;
      __asm { stvx128   v10, r0, r3 }
      _R3 += 32;
      --v47;
    }
    while ( v47 != 0 );
  }
}


// ========================================================================
// ?RetargetAdditiveRST@idMD6Blend@@CAXPIBVidMD6SkelData@@PIAM11I@Z
// EA  : 0x8281EA08
// RVA : 0x0081EA08
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMD6Blend::RetargetAdditiveRST(
        const idMD6SkelData *skeleton,
        float *outR,
        float *outS,
        float *outT,
        const unsigned int numJoints)
{
  int v5; // r2 OVERLAPPED
  int basePoseOffset; // r11
  char *v8; // r27
  int v9; // r9
  unsigned int v13; // ctr
  float *v14; // r3 OVERLAPPED
  int v57; // [sp+30h] [-D0h]
  int v58; // [sp+34h] [-CCh]
  __int64 v59; // [sp+48h] [-B8h]

  basePoseOffset = skeleton->basePoseOffset;
  v8 = (char *)skeleton + basePoseOffset;
  v9 = (skeleton->numJoints + 7) & 0xFFF8;
  _R31 = (char *)skeleton + 16 * v9 + basePoseOffset;
  _R10 = (char *)skeleton + 28 * v9 + basePoseOffset;
  if ( numJoints != 0 )
  {
    _R15 = (char *)((char *)outT - v8);
    v13 = ((numJoints - 1) >> 3) + 1;
    v14 = outT + 20;
    v58 = (char *)outT - (char *)outS;
    v57 = (char *)outT - (char *)outR;
    _R17 = (char *)((char *)outR - v8);
    _R14 = (char *)outS - (char *)outR;
    _R11 = outR + 12;
    _R16 = (char *)((char *)outS - v8);
    _R8 = v8 + 32;
    _R27 = &vmx_float_rsqrt_c1_2;
    _R4 = -336;
    _R26 = -128;
    _R25 = -176;
    _R24 = -16;
    _R7 = outS + 16;
    __asm
    {
      lvx128    v60, r0, r27
      lvx128    v63, r27, r4
    }
    _R29 = 16;
    __asm { lvx128    v62, r27, r26 }
    _R30 = 32;
    __asm { lvx128    v61, r27, r25 }
    _R28 = _R31;
    __asm { lvx128    v22, r27, r24 }
    _R9 = _R10 + 48;
    _R5 = -48;
    _R6 = 48;
    _R18 = 64;
    _R4 = -64;
    do
    {
      _R27 = -32;
      __asm { lvx128    v59, r0, r8 }
      _R19 = -32;
      __asm
      {
        lvx128    v58, r17, r8
        lvx128    v57, r11, r5
      }
      _R26 = 80;
      __asm
      {
        lvx128    v55, r0, r11
        vmrglw128 v54, v89, v58
        lvx128    v51, r8, r6
        lvx128    v53, r8, r27
      }
      _R27 = -16;
      __asm
      {
        lvx128    v56, r11, r19
        vmrghw128 v46, v89, v58
        vmrghw128 v50, v85, v59
        lvx128    v49, r8, r18
        vmrglw128 v52, v88, v55
        lvx128    v47, r8, r26
        vmrglw128 v48, v85, v59
        lvx128    v45, r11, r29
        lvx128    v44, r8, r27
      }
      _R27 = 16;
      __asm
      {
        vmrghw128 v41, v88, v55
        lvx128    v42, r11, r30
        vmrglw128 v43, v86, v52
        lvx128    v40, r11, r6
        vmrghw128 v6, v86, v52
        lvx128    v39, r11, r18
        vmrghw128 v38, v83, v47
        lvx128    v37, r8, r27
        vmrghw128 v5, v78, v41
        vmrglw128 v4, v78, v41
      }
      _R27 = 32;
      __asm
      {
        vmrghw128 v36, v76, v37
        vmrglw128 v35, v76, v37
        vmrglw128 v58, v77, v40
        vmrglw128 v57, v74, v39
        vmrghw128 v0, v82, v36
        lvx128    v34, r8, r27
        vmrglw128 v11, v80, v35
      }
      __asm
      {
        vmrglw128 v13, v82, v36
        vmrghw128 v12, v80, v35
        vmulfp128 v10, v75, v0
        vmrghw128 v32, v66, v49
        vmrglw128 v54, v90, v57
        vmulfp128 v21, v75, v11
        vmulfp128 v9, v75, v13
        vmrglw128 v33, v83, v47
        vmulfp128 v8, v75, v12
        vmrglw128 v59, v66, v49
        vmrghw128 v56, v77, v40
        vmrghw128 v55, v74, v39
        vmrghw128 v1, v90, v57
        vmrglw128 v7, v91, v33
        vmrghw128 v3, v88, v55
        vmrglw128 v2, v88, v55
        vmulfp128 v16, v86, v7
        vmaddfp   v25, v5, v10, v11
        vmrghw128 v10, v64, v38
        vnmsubfp  v21, v5, v21, v0
        vmaddfp   v24, v4, v9, v11
        vmrglw128 v9, v64, v38
        vmaddfp   v23, v6, v8, v11
        vmrghw128 v8, v91, v33
        vmulfp128 v26, v86, v10
        vmulfp128 v17, v86, v8
        vmaddfp   v25, v4, v25, v12
        vmaddfp   v24, v6, v24, v0
        vmaddfp   v23, v5, v23, v13
        vmaddfp   v20, v3, v26, v7
        vnmsubfp  v25, v6, v25, v13
        vnmsubfp  v31, v5, v24, v12
        vmr       v24, v12
        vnmsubfp  v30, v4, v23, v0
        vmr       v23, v9
        vmr128    v53, v25
        vmulfp128 v25, v86, v9
        vmulfp128 v18, v85, v53
        vmulfp128 v15, v0, v53
        vmaddfp   v19, v2, v25, v7
        vmaddfp   v18, v31, v18, v31
        vnmsubfp  v5, v4, v21, v13
        vmr       v28, v8
        vmaddfp   v27, v2, v20, v8
        vmr       v25, v9
        vmaddfp   v13, v13, v15, v31
        vmr       v29, v8
        vmaddfp   v20, v30, v18, v30
      }
      __asm { vmaddfp   v21, v1, v19, v10 }
      __asm { vmaddfp   v17, v1, v17, v7 }
      __asm { vnmsubfp  v16, v3, v16, v10 }
      _R27 = &_R9[-20 - (_DWORD)_R10];
      _R26 = &_R9[-36 - (_DWORD)_R10];
      __asm { lvx128    v52, r7, r4 }
      _R25 = &_R9[-8 - (_DWORD)_R10];
      __asm { lvx128    v49, r7, r5 }
      _R24 = &_R9[-24 - (_DWORD)_R10];
      __asm
      {
        lvx128    v48, r16, r8
        vand128   v47, v84, v63
      }
      __asm
      {
        lvrx128   v51, r27, r31
        vand128   v54, v81, v63
        vnmsubfp  v5, v6, v5, v24
        lvlx128   v50, r26, r31
        vnmsubfp  v27, v1, v27, v23
        lvrx128   v58, r25, r31
        vmaddfp   v26, v12, v13, v30
        lvlx128   v57, r24, r31
        vor128    v46, v82, v51
      }
      __asm
      {
        vnmsubfp  v12, v3, v21, v28
        vor128    v52, v89, v58
        vmaddfp   v19, v3, v17, v9
        lvx128    v51, r0, r28
        vnmsubfp  v18, v2, v16, v25
      }
      _R23 = &_R9[4 - (_DWORD)_R10];
      _R22 = &_R9[-12 - (_DWORD)_R10];
      __asm
      {
        vmaddfp   v6, v5, v20, v5
        vmulfp128 v4, v27, v27
        vmaddfp   v3, v11, v26, v5
        vmulfp128 v11, v10, v27
        vnmsubfp  v13, v2, v19, v10
        vnmsubfp  v0, v1, v18, v29
        vrsqrtefp128 v45, v6
        vmaddfp   v4, v12, v4, v12
        vand128   v44, v3, v61
        vmaddfp   v10, v9, v11, v12
        vxor128   v43, v94, v44
        vmulfp128 v11, v77, v45
        vmaddfp   v4, v13, v4, v13
        vmulfp128 v42, v77, v60
        vmaddfp   v10, v8, v10, v13
        vmulfp128 v45, v83, v47
        vmaddfp   v9, v6, v22, v11
        vmaddfp   v11, v0, v4, v0
        vmaddfp   v10, v7, v10, v0
        vmulfp128 v41, v74, v9
        vrsqrtefp128 v40, v11
        vand128   v39, v10, v61
        vxor128   v37, v94, v39
        vmulfp128 v38, v73, v43
        vmulfp128 v10, v72, v40
        vmulfp128 v36, v72, v60
        vmulfp128 v35, v85, v38
        vand128   v53, v80, v63
        vmulfp128 v34, v31, v38
        vmulfp128 v33, v30, v38
        vmulfp128 v32, v5, v38
        vmaddfp   v11, v11, v22, v10
        vmulfp128 v48, v78, v54
        vmulfp128 v44, v84, v53
        vmrghw128 v56, v67, v33
        vmrghw128 v55, v66, v32
        vmulfp128 v59, v68, v11
        vmrglw128 v50, v67, v33
        vmrglw128 v46, v66, v32
        vmrglw128 v49, v88, v55
        vmulfp128 v41, v91, v37
        vmrghw128 v43, v88, v55
        stvx128   v49, r11, r19
      }
      _R21 = &_R9[28 - (_DWORD)_R10];
      __asm { lvrx128   v38, r23, r31 }
      _R20 = &_R9[12 - (_DWORD)_R10];
      __asm
      {
        lvlx128   v36, r22, r31
        lvx128    v54, r7, r29
        vor128    v32, v68, v38
        vand128   v38, v86, v63
        lvx128    v59, r0, r7
      }
      v59 = *(_QWORD *)(&v5 - 1);
      __asm
      {
        lvx128    v52, r7, r30
        lvrx128   v58, r21, r31
      }
      __asm { lvlx128   v56, r20, r31 }
      __asm { vor128    v36, v88, v58 }
      __asm { lvx128    v39, r14, r11 }
      __asm
      {
        vand128   v57, v91, v63
        vmulfp128 v51, v13, v41
      }
      __asm
      {
        vmulfp128 v49, v0, v41
        lvrx128   v35, r27, r10
        vmulfp128 v55, v27, v41
        lvlx128   v34, r26, r10
        vmulfp128 v53, v12, v41
        lvrx128   v33, r25, r10
        vmrghw128 v42, v82, v46
        vand128   v59, v84, v63
        vmrglw128 v40, v82, v46
        stvx128   v48, r7, r5
        vand128   v37, v71, v63
      }
      _R26 = &_R9[52 - (_DWORD)_R10];
      _R27 = &_R9[24 - (_DWORD)_R10];
      __asm { stvx128   v45, r7, r4 }
      _R25 = &_R9[36 - (_DWORD)_R10];
      __asm { lvlx128   v50, r24, r10 }
      _R19 = &_R9[40 - (_DWORD)_R10];
      __asm
      {
        vmulfp128 v41, v64, v37
        lvx128    v32, r7, r6
        lvrx128   v39, r26, r31
      }
      _R24 = v57;
      __asm { lvlx128   v46, r27, r31 }
      _R3 = _R31 - _R10;
      __asm
      {
        lvlx128   v37, r25, r31
        vand128   v32, v64, v63
        vmrghw128 v56, v87, v51
        lvrx128   v47, r19, r31
        vmrghw128 v54, v85, v49
        lvrx128   v58, r23, r10
        vmrglw128 v55, v87, v51
        lvlx128   v45, r22, r10
        vmrglw128 v53, v85, v49
        stvx128   v43, r11, r5
        stvx128   v42, r17, r8
      }
      _R23 = v58;
      __asm
      {
        vmrghw128 v52, v88, v54
        stvx128   v40, r0, r11
        vmrglw128 v51, v88, v54
        stvx128   v44, r16, r8
        vmrghw128 v49, v87, v53
        lvrx128   v44, r21, r10
        vmrglw128 v48, v87, v53
        lvlx128   v43, r20, r10
        lvrx128   v40, r19, r10
      }
      _R22 = -80;
      __asm
      {
        lvlx128   v56, r27, r10
        vor128    v42, v78, v47
        lvrx128   v54, r26, r10
        vor128    v55, v69, v39
        stvx128   v52, r11, r29
        vor128    v53, v66, v35
        stvx128   v51, r11, r30
        stvx128   v49, r11, r6
        stvx128   v48, r11, r18
        lvx128    v49, r3, r9
      }
      *(_QWORD *)(&v5 - 1) = v59;
      __asm
      {
        lvlx128   v52, r25, r10
        vor128    v51, v82, v33
        lvx128    v37, r24, r11
        vor128    v50, v77, v58
        vmulfp128 v39, v81, v57
        vor128    v48, v75, v44
        vmulfp128 v34, v74, v59
        vor128    v46, v88, v40
        lvx128    v43, r3, r4
        vor128    v44, v84, v54
        lvx128    v40, r15, r8
        vmulfp128 v32, v87, v32
        lvx128    v47, r9, r5
        lvx128    v45, r3, r22
        vaddfp128 v56, v75, v53
        lvx128    v35, r0, r9
        vaddfp128 v54, v72, v51
        lvx128    v33, r23, r7
        vaddfp128 v53, v69, v50
        lvx128    v59, r0, r3
        vmulfp128 v36, v68, v38
        lvx128    v57, r3, r29
        vaddfp128 v58, v77, v47
        lvx128    v55, r3, r30
        vaddfp128 v52, v65, v35
        vaddfp128 v51, v91, v48
      }
      __asm
      {
        vaddfp128 v50, v89, v46
        stvx128   v41, r14, r11
        vaddfp128 v49, v87, v44
        stvx128   v39, r0, r7
        stvx128   v34, r7, r30
      }
      _R28 += 96;
      _R9 += 96;
      __asm
      {
        stvx128   v32, r7, r6
        stvx128   v56, r3, r4
        stvx128   v54, r15, r8
      }
      _R8 += 128;
      __asm { stvx128   v53, r24, r11 }
      _R11 += 32;
      __asm
      {
        stvx128   v36, r7, r29
        stvx128   v58, r3, r22
        stvx128   v52, r23, r7
      }
      _R7 += 32;
      __asm
      {
        stvx128   v51, r0, r3
        stvx128   v50, r3, r29
        stvx128   v49, r3, r30
      }
      v14 = (float *)(v59 + 128);
      --v13;
    }
    while ( v13 != 0 );
  }
}


// ========================================================================
// ?RetargetAdditiveU@idMD6Blend@@CAXPIBVidMD6SkelData@@PIAMI@Z
// EA  : 0x8281EFD8
// RVA : 0x0081EFD8
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::RetargetAdditiveU(
        const idMD6SkelData *skeleton,
        float *outU,
        const unsigned int numUserChannels)
{
  unsigned int v9; // ctr

  _R10 = (char *)skeleton + 40 * ((skeleton->numJoints + 7) & 0xFFF8) + skeleton->basePoseOffset;
  if ( numUserChannels != 0 )
  {
    _R8 = _R10 - (char *)outU;
    _R11 = outU + 4;
    _R7 = -16;
    _R6 = -16;
    v9 = ((numUserChannels - 1) >> 3) + 1;
    do
    {
      __asm { lvx128    v63, r0, r10 }
      _R10 += 32;
      __asm
      {
        lvx128    v62, r11, r7
        lvx128    v61, r8, r11
        vaddfp128 v60, v94, v63
        lvx128    v59, r0, r11
        vaddfp128 v58, v91, v61
        stvx128   v60, r11, r6
        stvx128   v58, r0, r11
      }
      _R11 += 8;
      --v9;
    }
    while ( v9 != 0 );
  }
}


// ========================================================================
// ClearOriginTransform
// EA  : 0x8281F058
// RVA : 0x0081F058
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall ClearOriginTransform(
        const idMD6AnimData *animData,
        float *poseR,
        float *poseT,
        float *curRot,
        float *curTrans,
        const unsigned __int16 frameFlags)
{
  double v6; // fp12
  double v7; // fp29
  double v8; // fp0
  double v9; // fp30
  double v10; // fp13
  double v11; // fp10
  double v12; // fp8
  double v13; // fp6
  double v14; // fp7
  double v15; // fp4
  double v16; // fp5
  double v17; // fp3
  double v18; // fp1
  double v19; // fp31

  if ( (frameFlags & 4) != 0 )
  {
    v6 = animData->endDelta[0];
    v7 = animData->endDelta[1];
    v8 = poseR[3];
    v9 = animData->endDelta[2];
    v10 = poseR[2];
    v11 = (float)(animData->endDelta[0] * poseR[3]);
    v12 = (float)(animData->endDelta[1] * poseR[3]);
    v13 = *poseR;
    v14 = (float)(animData->endDelta[2] * poseR[3]);
    v15 = poseR[1];
    v16 = (float)(animData->endDelta[2] * poseR[2]);
    v17 = animData->endDelta[3];
    v18 = poseT[1];
    v19 = poseT[2];
    *poseT = *poseT - animData->endDelta[0];
    poseT[1] = (float)v18 - (float)v7;
    poseT[2] = (float)v19 - (float)v9;
    *poseR = (float)((float)v9 * (float)v15)
           - (float)((float)((float)v7 * (float)v10) - (float)((float)((float)v17 * (float)v13) - (float)v11));
    poseR[1] = (float)((float)v6 * (float)v10)
             - (float)((float)((float)v9 * (float)v13) - (float)((float)((float)v17 * (float)v15) - (float)v12));
    poseR[2] = (float)((float)v7 * (float)v13)
             - (float)((float)((float)v6 * (float)v15) - (float)((float)((float)v17 * (float)v10) - (float)v14));
    poseR[3] = (float)((float)v6 * (float)v13)
             + (float)((float)((float)v17 * (float)v8) + (float)((float)((float)v7 * (float)v15) + (float)v16));
  }
  *(_OWORD *)curRot = *(_OWORD *)poseR;
  *(_OWORD *)curTrans = *(_OWORD *)poseT;
  if ( (frameFlags & 8) != 0 )
  {
    if ( (animData->flags & 2) != 0 )
      *poseT = 0.0;
    else
      *curTrans = 0.0;
    if ( (animData->flags & 4) != 0 )
      poseT[1] = 0.0;
    else
      curTrans[1] = 0.0;
    if ( (animData->flags & 8) != 0 )
      poseT[2] = 0.0;
    else
      curTrans[2] = 0.0;
    if ( (animData->flags & 0x10) != 0 )
    {
      poseR[2] = 0.0;
      poseR[1] = 0.0;
      *poseR = 0.0;
      poseR[3] = 1065353216;
    }
    else
    {
      curRot[2] = 0.0;
      curRot[1] = 0.0;
      *curRot = 0.0;
      curRot[3] = 1065353216;
    }
  }
}


// ========================================================================
// ?DecodeSkeletonFrame@idMD6Blend@@CAXPIBVidMD6SkelData@@PIAM111@Z
// EA  : 0x8281F228
// RVA : 0x0081F228
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::DecodeSkeletonFrame(
        const idMD6SkelData *skeleton,
        const float *stackR,
        float *stackS,
        float *stackT,
        float *stackU)
{
  int basePoseOffset; // r11
  unsigned int v8; // r3
  float *v10; // r10
  __int64 v12; // r6
  unsigned int v18; // ctr

  basePoseOffset = skeleton->basePoseOffset;
  v8 = (skeleton->numJoints + 7) & 0xFFF8;
  v10 = (float *)(28 * v8 + basePoseOffset);
  LODWORD(v12) = (char *)skeleton + (_DWORD)v10;
  HIDWORD(v12) = (char *)skeleton + 16 * v8 + basePoseOffset;
  idMD6Blend::DecodeBasePoseRST(numJoints: v8, inS: v12, inT: stackR, outR: stackS, outS: stackT, outT: v10);
  if ( stackU != nullptr )
  {
    _R10 = (char *)skeleton + 40 * ((skeleton->numJoints + 7) & 0xFFF8) + skeleton->basePoseOffset;
    if ( ((skeleton->numUserChannels + 7) & 0xFFF8) != 0 )
    {
      _R8 = _R10 - (char *)stackU;
      _R11 = stackU + 4;
      _R7 = -16;
      v18 = ((((skeleton->numUserChannels + 7) & 0xFFF8u) - 1) >> 3) + 1;
      do
      {
        __asm { lvx128    v63, r0, r10 }
        _R10 += 32;
        __asm
        {
          lvx128    v62, r8, r11
          stvx128   v63, r11, r7
          stvx128   v62, r0, r11
        }
        _R11 += 8;
        --v18;
      }
      while ( v18 != 0 );
    }
  }
}


// ========================================================================
// ?TransformLocalJointToModelJoint@idMD6Blend@@CAXPIBFHPIBM11PIAM22@Z
// EA  : 0x8281F310
// RVA : 0x0081F310
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::TransformLocalJointToModelJoint(
        const __int16 *parentTable,
        int joint,
        const float *inR,
        const float *inS,
        const float *inT,
        float *outR,
        float *outS,
        float *outT)
{
  __int16 v15; // r10
  const float *v16; // r10
  const float *v17; // r9
  const float *v18; // r8
  double v19; // fp13
  double v20; // fp12
  double v21; // fp11
  double v22; // fp10
  double v23; // fp9
  double v24; // fp8
  double v25; // fp7
  double v26; // fp6
  double v27; // fp5
  double v28; // fp9
  double v29; // fp8
  const float *v30; // r9
  double v31; // fp7
  const float *v32; // r10
  double v33; // fp13
  const float *v34; // r8
  double v35; // fp3
  double v36; // fp1
  double v37; // fp2
  double v38; // fp12
  double v39; // fp29
  double v40; // fp11
  double v41; // fp23
  double v42; // fp5
  double v43; // fp0
  double v44; // fp6
  double v45; // fp4
  double v46; // fp31
  double v47; // fp26
  double v48; // fp27
  double v49; // fp30
  double v50; // fp28
  double v51; // fp24
  double v52; // fp7
  double v53; // fp31
  double v54; // fp29
  double v55; // fp11
  double v56; // fp1
  double v57; // fp9
  double v58; // fp6
  double v59; // fp12
  double v60; // fp11
  float v61[4]; // [sp+50h] [-C0h] BYREF
  float v62[4]; // [sp+60h] [-B0h] BYREF
  float v63[24]; // [sp+70h] [-A0h] BYREF

  if ( joint >= 0 )
  {
    v15 = parentTable[joint];
    if ( v15 >= 0 )
    {
      idMD6Blend::TransformLocalJointToModelJoint(
        parentTable,
        joint: v15,
        inR,
        inS,
        inT,
        outR: v61,
        outS: v62,
        outT: v63);
      v28 = v62[0];
      v29 = v62[1];
      v30 = &inT[4 * joint];
      v31 = v62[2];
      v32 = &inR[4 * joint];
      v33 = v61[2];
      v34 = &inS[4 * joint];
      outS[3] = 0.0;
      outT[3] = 0.0;
      v35 = (float)(v30[1] * (float)v29);
      v36 = v32[3];
      v37 = (float)(v30[2] * (float)v31);
      v38 = v61[1];
      v39 = (float)(v32[3] * (float)v33);
      v40 = v61[3];
      v41 = (float)((float)(v30[1] * (float)v29) * (float)v33);
      v42 = (float)(*v30 * (float)v28);
      v43 = v61[0];
      v44 = *v32;
      v45 = (float)(v32[3] * v61[0]);
      v46 = (float)(*v32 * (float)v33);
      v47 = *v34;
      v48 = (float)(*v32 * v61[0]);
      outS[1] = v34[1] * (float)v29;
      v49 = v32[1];
      outS[2] = v34[2] * (float)v31;
      *outS = (float)v47 * (float)v28;
      v50 = v32[2];
      v51 = v63[1];
      v52 = (float)((float)(v32[2] * (float)v38) + (float)((float)((float)v44 * (float)v40) + (float)v45));
      outR[2] = -(float)((float)((float)v44 * (float)v38)
                       - (float)((float)(v32[2] * (float)v40) + (float)((float)((float)v49 * (float)v43) + (float)v39)));
      v54 = (float)((float)((float)v42 * (float)v40) + (float)((float)((float)v37 * (float)v38) - (float)v41));
      *outR = -(float)((float)((float)v49 * (float)v33) - (float)v52);
      outR[1] = -(float)((float)((float)v50 * (float)v43)
                       - (float)((float)((float)v36 * (float)v38)
                               + (float)((float)((float)v49 * (float)v40) + (float)v46)));
      outR[3] = -(float)((float)((float)v50 * (float)v33)
                       - (float)-(float)((float)((float)v49 * (float)v38)
                                       - (float)((float)((float)v36 * (float)v40) - (float)v48)));
      v53 = (float)((float)((float)v37 * (float)v40)
                  + (float)((float)((float)v35 * (float)v43) - (float)((float)v42 * (float)v38)));
      v56 = (float)((float)((float)((float)v37 * (float)v40)
                          + (float)((float)((float)v35 * (float)v43) - (float)((float)v42 * (float)v38)))
                  * (float)v43);
      v57 = (float)((float)((float)((float)v42 * (float)v40) + (float)((float)((float)v37 * (float)v38) - (float)v41))
                  * (float)v38);
      v55 = (float)((float)((float)v35 * (float)v40)
                  + (float)((float)((float)v42 * (float)v33) - (float)((float)v37 * (float)v43)));
      v58 = (float)((float)((float)v55 * (float)v43) - (float)v57);
      v60 = (float)((float)((float)((float)((float)v53 * (float)v38) - (float)((float)v55 * (float)v33)) * (float)2.0)
                  + v63[0]);
      v59 = (float)((float)((float)v58 * (float)2.0) + v63[2]);
      outT[1] = (float)((float)((float)((float)((float)v54 * (float)v33) - (float)v56) * (float)2.0) + (float)v51)
              + (float)v35;
      outT[2] = (float)v59 + (float)v37;
      *outT = (float)v60 + (float)v42;
    }
    else
    {
      v16 = &inR[4 * joint];
      v17 = &inS[4 * joint];
      v18 = &inT[4 * joint];
      v19 = *v17;
      v20 = v16[1];
      v21 = v16[2];
      v22 = v16[3];
      v23 = v17[1];
      v24 = v17[2];
      v25 = *v18;
      v26 = v18[1];
      v27 = v18[2];
      *outR = *v16;
      outR[1] = v20;
      outR[2] = v21;
      outR[3] = v22;
      *outS = v19;
      outS[1] = v23;
      outS[2] = v24;
      *outT = v25;
      outT[1] = v26;
      outT[2] = v27;
    }
  }
  else
  {
    outR[2] = 0.0;
    outR[1] = 0.0;
    *outR = 0.0;
    outR[3] = 1.0;
    outS[3] = 1.0;
    outS[2] = 1.0;
    outS[1] = 1.0;
    *outS = 1.0;
    outT[3] = 0.0;
    outT[2] = 0.0;
    outT[1] = 0.0;
    *outT = 0.0;
  }
}


// ========================================================================
// `idMD6Blend::ExecuteCommandsInternal'::`2'::local_t::SubD
// EA  : 0x8281F598
// RVA : 0x0081F598
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall _idMD6Blend::ExecuteCommandsInternal_::_2_::local_t::SubD(const float *a, const float *b, float *r)
{
  double v3; // fp10

  *r = (float)(b[2] * a[1]) - (float)((float)(b[1] * a[2]) - (float)((float)(*a * b[3]) - (float)(a[3] * *b)));
  r[1] = (float)(a[2] * *b) - (float)((float)(b[2] * *a) - (float)((float)(a[1] * b[3]) - (float)(a[3] * b[1])));
  r[2] = (float)(b[1] * *a) - (float)((float)(a[1] * *b) - (float)((float)(a[2] * b[3]) - (float)(a[3] * b[2])));
  r[3] = (float)(b[1] * a[1]) + (float)((float)(b[2] * a[2]) + (float)((float)(*a * *b) + (float)(a[3] * b[3])));
  r[4] = a[4] / b[4];
  r[5] = a[5] / b[5];
  v3 = (float)(a[6] / b[6]);
  r[7] = 1.0;
  r[6] = v3;
  r[8] = a[8] - b[8];
  r[9] = a[9] - b[9];
  r[10] = a[10] - b[10];
  r[11] = 0.0;
}


// ========================================================================
// `idMD6Blend::ExecuteCommandsInternal'::`2'::local_t::AddD
// EA  : 0x8281F6E8
// RVA : 0x0081F6E8
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall _idMD6Blend::ExecuteCommandsInternal_::_2_::local_t::AddD(const float *a, const float *b, float *r)
{
  double v3; // fp10

  *r = -(float)((float)(b[2] * a[1]) - (float)((float)(a[3] * *b) + (float)((float)(b[3] * *a) + (float)(b[1] * a[2]))));
  r[1] = -(float)((float)(*b * a[2]) - (float)((float)(a[3] * b[1]) + (float)((float)(b[3] * a[1]) + (float)(b[2] * *a))));
  r[2] = -(float)((float)(*a * b[1]) - (float)((float)(a[3] * b[2]) + (float)((float)(a[1] * *b) + (float)(b[3] * a[2]))));
  r[3] = -(float)((float)(b[2] * a[2])
                - (float)-(float)((float)(a[1] * b[1]) - (float)((float)(b[3] * a[3]) - (float)(*a * *b))));
  r[4] = a[4] * b[4];
  r[5] = a[5] * b[5];
  v3 = (float)(a[6] * b[6]);
  r[7] = 1.0;
  r[6] = v3;
  r[8] = a[8] + b[8];
  r[9] = a[9] + b[9];
  r[10] = a[10] + b[10];
  r[11] = 0.0;
}


// ========================================================================
// `idMD6Blend::TransformLocalJointsToModelMatrices'::`30'::local_t::QuatMult
// EA  : 0x8281F838
// RVA : 0x0081F838
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall _idMD6Blend::TransformLocalJointsToModelMatrices_::_30_::local_t::QuatMult(
        const float *a,
        const float *b,
        float *out)
{
  double v3; // fp2
  double v4; // fp3
  double v5; // fp1
  double v6; // fp11
  double v7; // fp4
  double v8; // fp8
  double v9; // fp7
  double v12; // fp13
  double v13; // fp12
  double v14; // fp8
  double v15; // fp2
  double v16; // fp13

  v3 = (float)-(float)((float)(b[2] * a[1])
                     - (float)((float)(a[3] * *b) + (float)((float)(b[3] * *a) + (float)(b[1] * a[2]))));
  *out = -(float)((float)(b[2] * a[1]) - (float)((float)(a[3] * *b) + (float)((float)(b[3] * *a) + (float)(b[1] * a[2]))));
  v4 = v3;
  v5 = (float)-(float)((float)(*b * a[2])
                     - (float)((float)(a[3] * b[1]) + (float)((float)(b[3] * a[1]) + (float)(b[2] * *a))));
  out[1] = -(float)((float)(*b * a[2])
                  - (float)((float)(a[3] * b[1]) + (float)((float)(b[3] * a[1]) + (float)(b[2] * *a))));
  v6 = (float)-(float)((float)(*a * b[1])
                     - (float)((float)(a[3] * b[2]) + (float)((float)(a[1] * *b) + (float)(b[3] * a[2]))));
  out[2] = -(float)((float)(*a * b[1])
                  - (float)((float)(a[3] * b[2]) + (float)((float)(a[1] * *b) + (float)(b[3] * a[2]))));
  v7 = v6;
  v8 = (float)-(float)((float)(b[2] * a[2])
                     - (float)-(float)((float)(a[1] * b[1]) - (float)((float)(b[3] * a[3]) - (float)(*a * *b))));
  out[3] = -(float)((float)(b[2] * a[2])
                  - (float)-(float)((float)(a[1] * b[1]) - (float)((float)(b[3] * a[3]) - (float)(*a * *b))));
  v9 = v8;
  _FP5 = (float)((float)((float)((float)v8 * (float)v8)
                       + (float)((float)((float)v7 * (float)v7)
                               + (float)((float)((float)v4 * (float)v4) + (float)((float)v5 * (float)v5))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f5, f6, f13 }
  v12 = (float)((float)((float)((float)v8 * (float)v8)
                      + (float)((float)((float)v7 * (float)v7)
                              + (float)((float)((float)v4 * (float)v4) + (float)((float)v5 * (float)v5))))
              * (float)0.5);
  v13 = __frsqrte(_FP2);
  v14 = (float)((float)-(float)((float)((float)((float)v13
                                              * (float)((float)((float)((float)v8 * (float)v8)
                                                              + (float)((float)((float)v7 * (float)v7)
                                                                      + (float)((float)((float)v4 * (float)v4)
                                                                              + (float)((float)v5 * (float)v5))))
                                                      * (float)0.5))
                                      * (float)v13)
                              - (float)1.5)
              * (float)v13);
  v15 = (float)((float)-(float)((float)((float)((float)v14 * (float)v12) * (float)v14) - (float)1.5) * (float)v14);
  v16 = (float)((float)((float)-(float)((float)((float)((float)v14 * (float)v12) * (float)v14) - (float)1.5) * (float)v14)
              * (float)v12);
  *out = (float)v4 * (float)((float)-(float)((float)((float)v16 * (float)v15) - (float)1.5) * (float)v15);
  out[1] = (float)v5 * (float)((float)-(float)((float)((float)v16 * (float)v15) - (float)1.5) * (float)v15);
  out[2] = (float)v6 * (float)((float)-(float)((float)((float)v16 * (float)v15) - (float)1.5) * (float)v15);
  out[3] = (float)v9 * (float)((float)-(float)((float)((float)v16 * (float)v15) - (float)1.5) * (float)v15);
}


// ========================================================================
// `idMD6Blend::TransformLocalJointsToModelMatrices'::`30'::local_t::RotateVector
// EA  : 0x8281F998
// RVA : 0x0081F998
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall _idMD6Blend::TransformLocalJointsToModelMatrices_::_30_::local_t::RotateVector(
        const float *quat,
        const float *vec,
        float *out)
{
  double v3; // fp7
  double v4; // fp1
  double v5; // fp30
  double v6; // fp10
  double v7; // fp3
  double v8; // fp0
  double v9; // fp8

  v3 = (float)((float)((float)(quat[3] * quat[2]) * (float)2.0) + (float)((float)(quat[1] * *quat) * (float)2.0));
  v4 = (float)((float)((float)(quat[2] * *quat) * (float)2.0) - (float)((float)(quat[1] * quat[3]) * (float)2.0));
  v5 = (float)((float)((float)(quat[1] * quat[2]) * (float)2.0) - (float)((float)(quat[3] * *quat) * (float)2.0));
  v6 = (float)((float)((float)(quat[1] * quat[2]) * (float)2.0) + (float)((float)(quat[3] * *quat) * (float)2.0));
  v7 = (float)((float)((float)((float)(quat[1] * quat[1]) - (float)(*quat * *quat)) - (float)(quat[2] * quat[2]))
             + (float)(quat[3] * quat[3]));
  v8 = (float)((float)((float)(quat[3] * quat[3]) - (float)((float)(quat[1] * quat[1]) + (float)(*quat * *quat)))
             + (float)(quat[2] * quat[2]));
  *out = (float)((float)((float)((float)(quat[1] * quat[3]) * (float)2.0)
                       + (float)((float)(quat[2] * *quat) * (float)2.0))
               * vec[2])
       + (float)((float)((float)((float)((float)((float)(*quat * *quat) - (float)(quat[1] * quat[1]))
                                       - (float)(quat[2] * quat[2]))
                               + (float)(quat[3] * quat[3]))
                       * *vec)
               + (float)((float)((float)((float)(quat[1] * *quat) * (float)2.0)
                               - (float)((float)(quat[3] * quat[2]) * (float)2.0))
                       * vec[1]));
  out[1] = (float)((float)v5 * vec[2]) + (float)((float)((float)v7 * vec[1]) + (float)((float)v3 * *vec));
  v9 = (float)((float)((float)v6 * vec[1]) + (float)((float)((float)v8 * vec[2]) + (float)((float)v4 * *vec)));
  out[3] = 0.0;
  out[2] = v9;
}


// ========================================================================
// `idMD6Blend::TransformLocalJointsToModelMatrices'::`30'::local_t::QuatFromMat
// EA  : 0x8281FAA8
// RVA : 0x0081FAA8
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall _idMD6Blend::TransformLocalJointsToModelMatrices_::_30_::local_t::QuatFromMat(
        float *res,
        const float *mat)
{
  double v2; // fp0
  double v5; // fp7
  double v6; // fp13
  double v7; // fp7
  int v8; // r9
  unsigned int v9; // r7
  int v10; // r11
  int v11; // r10
  int v12; // r5
  int v13; // r31
  double v16; // fp8
  double v17; // fp1
  double v18; // fp13

  v2 = (float)((float)(*mat + mat[5]) + mat[10]);
  if ( v2 <= 0.0 )
  {
    v8 = mat[5] > (double)*mat;
    if ( mat[10] > (double)mat[5 * v8] )
      v8 = 2;
    v9 = 4 * v8;
    v10 = next_0[v8];
    v11 = next_0[v10];
    v12 = 4 * v11 + v10;
    v13 = 4 * v10 + v11;
    _FP1 = (float)((float)((float)(mat[5 * v8] - (float)(mat[5 * v11] + mat[5 * v10])) + (float)1.0)
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f9, f1, f0, f12 }
    v16 = __frsqrte(_FP9);
    v17 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16
                                                                                        * (float)((float)((float)(mat[5 * v8] - (float)(mat[5 * v11] + mat[5 * v10])) + (float)1.0)
                                                                                                * (float)0.5))
                                                                                * (float)v16)
                                                                        - (float)1.5)
                                                        * (float)v16)
                                                * (float)((float)((float)(mat[5 * v8]
                                                                        - (float)(mat[5 * v11] + mat[5 * v10]))
                                                                + (float)1.0)
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v16
                                                                                * (float)((float)((float)(mat[5 * v8] - (float)(mat[5 * v11] + mat[5 * v10]))
                                                                                                + (float)1.0)
                                                                                        * (float)0.5))
                                                                        * (float)v16)
                                                                - (float)1.5)
                                                * (float)v16))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v16
                                                        * (float)((float)((float)(mat[5 * v8]
                                                                                - (float)(mat[5 * v11] + mat[5 * v10]))
                                                                        + (float)1.0)
                                                                * (float)0.5))
                                                * (float)v16)
                                        - (float)1.5)
                        * (float)v16));
    v18 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)(mat[5 * v8] - (float)(mat[5 * v11] + mat[5 * v10])) + (float)1.0) * (float)0.5)) * (float)v16) - (float)1.5) * (float)v16)
                                                                                                * (float)((float)((float)(mat[5 * v8] - (float)(mat[5 * v11] + mat[5 * v10])) + (float)1.0) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)(mat[5 * v8] - (float)(mat[5 * v11] + mat[5 * v10])) + (float)1.0) * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                                * (float)v16))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)(mat[5 * v8] - (float)(mat[5 * v11] + mat[5 * v10])) + (float)1.0) * (float)0.5))
                                                                                                * (float)v16)
                                                                                        - (float)1.5)
                                                                        * (float)v16))
                                                        * (float)((float)((float)(mat[5 * v8]
                                                                                - (float)(mat[5 * v11] + mat[5 * v10]))
                                                                        + (float)1.0)
                                                                * (float)0.5))
                                                * (float)v17)
                                        - (float)1.5)
                        * (float)v17)
                * (float)0.5);
    if ( (float)(mat[v12] - mat[v13]) < 0.0 )
      v18 = -v18;
    res[v9 / 4] = (float)v18 * (float)((float)(mat[5 * v8] - (float)(mat[5 * v11] + mat[5 * v10])) + (float)1.0);
    res[3] = (float)(mat[v12] - mat[v13]) * (float)v18;
    res[v10] = (float)(mat[4 * v10 + v8] + mat[v9 + v10]) * (float)v18;
    res[v11] = (float)(mat[4 * v11 + v8] + mat[v9 + v11]) * (float)v18;
  }
  else
  {
    _FP10 = (float)((float)((float)((float)(*mat + mat[5]) + mat[10]) + (float)1.0) - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f8, f10, f11, f13 }
    v5 = __frsqrte(_FP8);
    v6 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5
                                                                                       * (float)((float)((float)v2 + (float)1.0)
                                                                                               * (float)0.5))
                                                                               * (float)v5)
                                                                       - (float)1.5)
                                                       * (float)v5)
                                               * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                       * (float)((float)-(float)((float)((float)((float)v5
                                                                               * (float)((float)((float)v2 + (float)1.0)
                                                                                       * (float)0.5))
                                                                       * (float)v5)
                                                               - (float)1.5)
                                               * (float)v5))
                               - (float)1.5)
               * (float)((float)-(float)((float)((float)((float)v5
                                                       * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                               * (float)v5)
                                       - (float)1.5)
                       * (float)v5));
    v7 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)v2 + (float)1.0) * (float)0.5)) * (float)v5) - (float)1.5) * (float)v5)
                                                                                               * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)v2 + (float)1.0) * (float)0.5)) * (float)v5) - (float)1.5)
                                                                                               * (float)v5))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                                                                               * (float)v5)
                                                                                       - (float)1.5)
                                                                       * (float)v5))
                                                       * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)v2 + (float)1.0) * (float)0.5)) * (float)v5) - (float)1.5)
                                                                                               * (float)v5)
                                                                                       * (float)((float)((float)v2 + (float)1.0)
                                                                                               * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)v2 + (float)1.0) * (float)0.5)) * (float)v5) - (float)1.5)
                                                                                       * (float)v5))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v5
                                                                                               * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                                                                       * (float)v5)
                                                                               - (float)1.5)
                                                               * (float)v5)))
                                       - (float)1.5)
                       * (float)v6)
               * (float)0.5);
    res[3] = (float)v7 * (float)((float)((float)(*mat + mat[5]) + mat[10]) + (float)1.0);
    *res = (float)(mat[9] - mat[6]) * (float)v7;
    res[1] = (float)(mat[2] - mat[8]) * (float)v7;
    res[2] = (float)(mat[4] - mat[1]) * (float)v7;
  }
}


// ========================================================================
// ?TransformModelMatrices@idMD6Blend@@SAXPBVidMD6SkelData@@PBEPIBM22PIAM_NPAM@Z
// EA  : 0x8281FCF0
// RVA : 0x0081FCF0
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::TransformModelMatrices(
        const idMD6SkelData *skeleton,
        const unsigned __int8 *remap,
        const float *inMatrices1,
        const float *inMatrices2,
        const float *invertedRefPoseQuat,
        float *outMatrices,
        bool useDualQuat,
        float *quatTemp)
{
  int v9; // r9
  int v10; // r11
  unsigned int v15; // ctr

  if ( !useDualQuat )
  {
    v9 = 0;
    v10 = (skeleton->numJoints + 7) & 0xFFF8;
    if ( ((skeleton->numJoints + 7) & 0xFFF8) != 0 )
    {
      _R10 = inMatrices2 + 8;
      _R3 = outMatrices + 4;
      _R31 = outMatrices + 8;
      v15 = ((unsigned int)(v10 - 1) >> 1) + 1;
      _R11 = inMatrices1 + 8;
      _R24 = (char *)inMatrices2 - (char *)inMatrices1 - 32;
      _R6 = vmxi_word_mask_keep_last;
      _R23 = -32;
      _R26 = -16;
      _R27 = 16;
      _R28 = 32;
      __asm { lvx128    v63, r0, r6 }
      _R29 = 48;
      do
      {
        __asm { lvx128    v62, r11, r23 }
        __asm
        {
          lvx128    v61, r0, r11
          vand128   v4, v94, v63
          lvx128    v60, r11, r26
          vspltw128 v5, v62, 0
          lvx128    v59, r11, r27
          vand128   v6, v93, v63
          lvx128    v58, r11, r28
          vspltw128 v30, v61, 0
          lvx128    v57, r11, r29
          vand128   v31, v92, v63
          vspltw128 v3, v60, 0
          vand128   v10, v91, v63
          vspltw128 v7, v59, 0
          vand128   v11, v90, v63
          vspltw128 v8, v58, 0
          lvx128    v0, r24, r11
          vand128   v12, v89, v63
          vspltw128 v9, v57, 0
          lvx128    v13, r10, r27
          vmaddfp   v1, v5, v4, v0
          vmaddfp   v26, v3, v31, v0
          vspltw128 v2, v61, 1
          vmaddfp   v27, v30, v6, v0
          vspltw128 v3, v59, 1
          vmaddfp   v28, v7, v10, v13
          vspltw128 v10, v62, 1
          vmaddfp   v29, v8, v11, v13
          vspltw128 v11, v60, 1
          vmaddfp   v30, v9, v12, v13
          vspltw128 v4, v58, 1
          lvx128    v0, r10, r26
          vspltw128 v5, v57, 1
          lvx128    v13, r10, r28
          vspltw128 v6, v62, 2
          vspltw128 v7, v60, 2
          lvx128    v12, r0, r10
          vspltw128 v8, v61, 2
        }
        __asm { vspltw128 v9, v59, 2 }
        __asm
        {
          vmaddfp   v31, v10, v1, v0
          vspltw128 v10, v58, 2
          vmaddfp   v1, v11, v26, v0
          vspltw128 v11, v57, 2
          vmaddfp   v2, v2, v27, v0
          lvx128    v0, r10, r29
          vmaddfp   v3, v3, v28, v13
        }
        __asm { vmaddfp   v4, v4, v29, v13 }
        __asm { vmaddfp   v5, v5, v30, v13 }
        _R5 = 16 * (remap[v9] + __ROL4__(remap[v9], 1));
        _R7 = 16 * (remap[v9 + 1] + __ROL4__(remap[v9 + 1], 1));
        v9 += 2;
        _R11 += 24;
        _R10 += 24;
        __asm
        {
          vmaddfp   v6, v6, v31, v12
          vmaddfp   v7, v7, v1, v12
          vmaddfp   v8, v8, v2, v12
          vmaddfp   v12, v9, v3, v0
          vmaddfp   v13, v10, v4, v0
          vmaddfp   v0, v11, v5, v0
          stvx128   v6, r5, r8
          stvx128   v7, r3, r5
          stvx128   v8, r31, r5
          stvx128   v12, r7, r8
          stvx128   v13, r3, r7
          stvx128   v0, r31, r7
        }
        --v15;
      }
      while ( v15 != 0 );
    }
  }
}


// ========================================================================
// ?GetAnimMapIndex@idMD6Blend@@SAHPBVidMD6AnimData@@V?$idHandle@GW4invalidCrc_t@@$0PPPP@@@@Z
// EA  : 0x8281FE90
// RVA : 0x0081FE90
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

int __fastcall idMD6Blend::GetAnimMapIndex(
        const idMD6AnimData *animData,
        const idHandle<unsigned short,enum invalidCrc_t,65535> *targetParentTableCRC)
{
  int numAnimMaps; // r10
  const idMD6AnimData *v3; // r11
  int result; // r3

  numAnimMaps = animData->numAnimMaps;
  v3 = animData + 1;
  result = 0;
  if ( numAnimMaps == 0 )
    return -1;
  while ( HIWORD(v3->totalSize) != (unsigned __int16)targetParentTableCRC )
  {
    ++result;
    v3 = (const idMD6AnimData *)((char *)v3 + 2);
    if ( result >= numAnimMaps )
      return -1;
  }
  return result;
}


// ========================================================================
// ?DecodeRLE@idMD6Blend@@SAIPBEGPAE@Z
// EA  : 0x8281FED0
// RVA : 0x0081FED0
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

signed int __fastcall idMD6Blend::DecodeRLE(
        const unsigned __int8 *RLE,
        const unsigned __int16 sentinel,
        unsigned __int8 *indices)
{
  unsigned int v3; // r11
  unsigned int v4; // r6
  signed int result; // r3
  signed int v7; // r11
  bool v8; // zf
  const unsigned __int8 *v9; // r4
  char v10; // r10
  unsigned __int8 v11; // r10
  unsigned int v12; // r8
  unsigned __int8 v13; // r9
  unsigned int v14; // r10
  unsigned int v15; // r9
  unsigned int v16; // r10
  signed int v17; // r10
  int v18; // r10
  unsigned __int8 *v19; // r11
  int i; // ctr

  v3 = *RLE;
  v4 = (unsigned __int8)sentinel;
  if ( v3 >= (unsigned __int8)sentinel )
    LOBYTE(v3) = sentinel;
  result = (unsigned __int8)v3;
  v8 = (unsigned __int8)v3 == 0;
  v7 = 0;
  if ( !v8 )
  {
    v9 = RLE;
    do
    {
      v10 = *++v9;
      v8 = v10 < 0;
      v11 = v10 & 0x7F;
      if ( v8 )
      {
        v15 = v11;
        if ( v11 != 0 )
        {
          LOBYTE(v16) = 0;
          do
          {
            indices[v7++] = v4;
            v16 = (unsigned __int8)(v16 + 1);
          }
          while ( v16 < v15 );
        }
      }
      else
      {
        v12 = v11;
        v13 = *++v9;
        v8 = v11 == 0;
        LOBYTE(v14) = 0;
        if ( !v8 )
        {
          while ( v13 < v4 )
          {
            indices[v7++] = v13++;
            v14 = (unsigned __int8)(v14 + 1);
            if ( v14 >= v12 )
              goto LABEL_16;
          }
          if ( (unsigned __int8)v14 < v12 )
          {
            do
            {
              indices[v7++] = v4;
              v14 = (unsigned __int8)(v14 + 1);
            }
            while ( v14 < v12 );
          }
        }
      }
LABEL_16:
      ;
    }
    while ( v7 < result );
  }
  v17 = (result + 7) & 0xFFFFFFF8;
  if ( result < v17 )
  {
    v18 = v17 - result;
    v19 = &indices[result - 1];
    if ( v18 != 0 )
    {
      for ( i = v18; i != 0; --i )
        *++v19 = v4;
    }
  }
  return result;
}


// ========================================================================
// ?DecodeAnimFrame@idMD6Blend@@CAXPIBVidMD6SkelData@@GPIBVidMD6AnimData@@PIBUframeSetData_t@@HMPIAM333@Z
// EA  : 0x8281FFE8
// RVA : 0x0081FFE8
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::DecodeAnimFrame(
        const idMD6SkelData *skeleton,
        unsigned __int16 numPaddedJoints,
        const idMD6AnimData *animData,
        const frameSetData_t *frameSetData,
        unsigned int frame,
        double frameFraction,
        float *stackR,
        float *stackS,
        float *stackT,
        float *stackU,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        float *a29,
        int a30,
        float *a31)
{
  unsigned __int16 flags; // r5
  unsigned __int16 v39; // r28
  unsigned __int16 v40; // r16
  int v41; // ctr
  float *v42; // r9
  float *v43; // r10
  float *v44; // r11
  unsigned int v45; // r17
  float *v46; // r9
  int v47; // ctr
  float *v48; // r10
  float *v49; // r11
  float *v50; // r25
  float *v51; // r11
  int v52; // ctr
  int basePoseOffset; // r11
  int v54; // r7
  float *v55; // r10
  __int64 v56; // r6
  unsigned int v62; // ctr
  int numAnimMaps; // r10
  const idMD6AnimData *v64; // r11
  int v65; // r29
  signed int v66; // r3
  int v67; // r29
  unsigned int v68; // r27
  unsigned int v69; // r26
  unsigned int v70; // r24
  unsigned int v71; // r23
  unsigned int v72; // r27
  unsigned int v73; // r26
  unsigned int v74; // r28
  double v75; // fp8
  double v76; // fp7
  double v77; // fp6
  double v78; // fp5
  double v79; // fp4
  double v80; // fp3
  double v81; // fp2
  unsigned int v82; // r24
  unsigned int frameRange; // r29
  const float *v84; // r7
  double v85; // fp8
  double v86; // fp7
  double v87; // fp6
  double v88; // fp5
  double v89; // fp4
  double v90; // fp3
  double v91; // fp2
  const float *v92; // r7
  double v93; // fp8
  double v94; // fp7
  double v95; // fp6
  double v96; // fp5
  double v97; // fp4
  double v98; // fp3
  double v99; // fp2
  double v100; // fp8
  double v101; // fp7
  double v102; // fp6
  double v103; // fp5
  double v104; // fp4
  double v105; // fp3
  double v106; // fp2
  unsigned int numJoints; // r10
  unsigned int v108; // r9
  unsigned int v109; // r7
  float *v110; // r11
  float *v111; // r9
  float *v112; // r10
  unsigned int v113; // ctr
  float *v114; // r11
  float *v115; // [sp+8h] [-538h]
  float *v116; // [sp+8h] [-538h]
  float *v117; // [sp+8h] [-538h]
  float *v118; // [sp+8h] [-538h]
  int v119; // [sp+Ch] [-534h]
  int v120; // [sp+Ch] [-534h]
  int v121; // [sp+Ch] [-534h]
  int v122; // [sp+Ch] [-534h]
  int v123; // [sp+10h] [-530h]
  int v124; // [sp+10h] [-530h]
  int v125; // [sp+10h] [-530h]
  int v126; // [sp+10h] [-530h]
  int v127; // [sp+14h] [-52Ch]
  int v128; // [sp+14h] [-52Ch]
  int v129; // [sp+14h] [-52Ch]
  int v130; // [sp+14h] [-52Ch]
  int v131; // [sp+18h] [-528h]
  int v132; // [sp+18h] [-528h]
  int v133; // [sp+18h] [-528h]
  int v134; // [sp+18h] [-528h]
  int v135; // [sp+1Ch] [-524h]
  int v136; // [sp+1Ch] [-524h]
  int v137; // [sp+1Ch] [-524h]
  int v138; // [sp+1Ch] [-524h]
  int v139; // [sp+20h] [-520h]
  int v140; // [sp+20h] [-520h]
  int v141; // [sp+20h] [-520h]
  int v142; // [sp+20h] [-520h]
  unsigned int v143; // [sp+24h] [-51Ch]
  unsigned int v144; // [sp+24h] [-51Ch]
  unsigned int v145; // [sp+24h] [-51Ch]
  unsigned int v146; // [sp+24h] [-51Ch]
  int v147; // [sp+28h] [-518h]
  int v148; // [sp+28h] [-518h]
  int v149; // [sp+28h] [-518h]
  int v150; // [sp+28h] [-518h]
  int v151; // [sp+2Ch] [-514h]
  int v152; // [sp+2Ch] [-514h]
  int v153; // [sp+2Ch] [-514h]
  int v154; // [sp+2Ch] [-514h]
  int v155; // [sp+30h] [-510h]
  int v156; // [sp+30h] [-510h]
  int v157; // [sp+30h] [-510h]
  int v158; // [sp+30h] [-510h]
  float v159; // [sp+34h] [-50Ch]
  float v160; // [sp+34h] [-50Ch]
  float v161; // [sp+34h] [-50Ch]
  float v162; // [sp+34h] [-50Ch]
  int v163; // [sp+38h] [-508h]
  int v164; // [sp+38h] [-508h]
  int v165; // [sp+38h] [-508h]
  int v166; // [sp+38h] [-508h]
  int v167; // [sp+3Ch] [-504h]
  int v168; // [sp+3Ch] [-504h]
  int v169; // [sp+3Ch] [-504h]
  int v170; // [sp+3Ch] [-504h]
  int v171; // [sp+40h] [-500h]
  int v172; // [sp+40h] [-500h]
  int v173; // [sp+40h] [-500h]
  int v174; // [sp+40h] [-500h]
  int v175; // [sp+44h] [-4FCh]
  int v176; // [sp+44h] [-4FCh]
  int v177; // [sp+44h] [-4FCh]
  int v178; // [sp+44h] [-4FCh]
  int v179; // [sp+48h] [-4F8h]
  int v180; // [sp+48h] [-4F8h]
  int v181; // [sp+48h] [-4F8h]
  int v182; // [sp+48h] [-4F8h]
  int v183; // [sp+4Ch] [-4F4h]
  int v184; // [sp+4Ch] [-4F4h]
  int v185; // [sp+4Ch] [-4F4h]
  int v186; // [sp+4Ch] [-4F4h]
  int v187; // [sp+50h] [-4F0h]
  int v188; // [sp+50h] [-4F0h]
  int v189; // [sp+50h] [-4F0h]
  int v190; // [sp+50h] [-4F0h]
  int v191; // [sp+58h] [-4E8h]
  int v192; // [sp+58h] [-4E8h]
  int v193; // [sp+58h] [-4E8h]
  int v194; // [sp+58h] [-4E8h]
  unsigned __int8 v195[272]; // [sp+60h] [-4E0h] BYREF
  unsigned __int8 v196[272]; // [sp+170h] [-3D0h] BYREF
  unsigned __int8 v197[272]; // [sp+280h] [-2C0h] BYREF
  unsigned __int8 v198[272]; // [sp+390h] [-1B0h] BYREF

  flags = animData->flags;
  v39 = numPaddedJoints;
  v40 = (skeleton->numUserChannels + 7) & 0xFFF8;
  if ( (flags & 0x400) == 0 )
  {
    if ( numPaddedJoints != 0 )
    {
      v41 = numPaddedJoints;
      v42 = a29 - 4;
      v43 = stackT + 2;
      v44 = stackS + 1;
      do
      {
        v44[1] = 0.0;
        *v44 = 0.0;
        *(v44 - 1) = 0.0;
        v44[2] = 1.0;
        v43[1] = 1.0;
        *v43 = 1.0;
        *(float *)((char *)v44 + (char *)stackT - (char *)stackS) = 1.0;
        *(v43 - 2) = 1.0;
        v42[7] = 0.0;
        *(float *)((char *)v43 + (char *)a29 - (char *)stackT) = 0.0;
        v43 += 4;
        *(float *)((char *)v44 + (char *)a29 - (char *)stackS) = 0.0;
        v44 += 4;
        v42 += 4;
        *v42 = 0.0;
        --v41;
      }
      while ( v41 != 0 );
    }
    v39 = 0;
  }
  v45 = v39;
  if ( (flags & 0x101) != 0 )
  {
    if ( v39 != 0 )
    {
      v46 = a29 - 4;
      v47 = v39;
      v48 = stackT + 2;
      v49 = stackS + 1;
      do
      {
        v49[1] = 0.0;
        *v49 = 0.0;
        *(v49 - 1) = 0.0;
        v49[2] = 1.0;
        v48[1] = 1.0;
        *v48 = 1.0;
        *(float *)((char *)v49 + (char *)stackT - (char *)stackS) = 1.0;
        *(v48 - 2) = 1.0;
        v46[7] = 0.0;
        *(float *)((char *)v48 + (char *)a29 - (char *)stackT) = 0.0;
        v48 += 4;
        *(float *)((char *)v49 + (char *)a29 - (char *)stackS) = 0.0;
        v49 += 4;
        v46 += 4;
        *v46 = 0.0;
        --v47;
      }
      while ( v47 != 0 );
    }
    v50 = a31;
    if ( a31 != nullptr && v40 != 0 )
    {
      v51 = a31 - 1;
      v52 = v40;
      do
      {
        *++v51 = 0.0;
        --v52;
      }
      while ( v52 != 0 );
    }
  }
  else
  {
    basePoseOffset = skeleton->basePoseOffset;
    v54 = (skeleton->numJoints + 7) & 0xFFF8;
    v55 = (float *)(28 * v54 + basePoseOffset);
    LODWORD(v56) = (char *)skeleton + (_DWORD)v55;
    HIDWORD(v56) = (char *)skeleton + 16 * v54 + basePoseOffset;
    idMD6Blend::DecodeBasePoseRST(numJoints: v39, inS: v56, inT: stackS, outR: stackT, outS: a29, outT: v55);
    v50 = a31;
    if ( a31 != nullptr )
    {
      _R10 = (char *)skeleton + 40 * ((skeleton->numJoints + 7) & 0xFFF8) + skeleton->basePoseOffset;
      if ( v40 != 0 )
      {
        _R8 = (char *)(_R10 - (char *)a31);
        _R11 = a31 + 4;
        _R7 = -16;
        v62 = (((unsigned int)v40 - 1) >> 3) + 1;
        do
        {
          __asm { lvx128    v63, r0, r10 }
          _R10 += 32;
          __asm
          {
            lvx128    v62, r8, r11
            stvx128   v63, r11, r7
            stvx128   v62, r0, r11
          }
          _R11 += 8;
          --v62;
        }
        while ( v62 != 0 );
      }
    }
  }
  numAnimMaps = animData->numAnimMaps;
  v64 = animData + 1;
  v65 = 0;
  if ( animData->numAnimMaps == 0 )
    goto LABEL_24;
  while ( HIWORD(v64->totalSize) != skeleton->parentTblCrc.value )
  {
    ++v65;
    v64 = (const idMD6AnimData *)((char *)v64 + 2);
    if ( v65 >= numAnimMaps )
      goto LABEL_24;
  }
  if ( v65 <= 0 )
LABEL_24:
    v65 = 0;
  v66 = idMD6Blend::DecodeRLE(
          RLE: (const unsigned __int8 *)animData + *((unsigned __int16 *)&animData[1].totalSize + 8 * v65 + numAnimMaps),
          sentinel: v39,
          indices: v197);
  v67 = 8 * v65;
  v68 = v66;
  v69 = idMD6Blend::DecodeRLE(
          RLE: (const unsigned __int8 *)animData
        + *((unsigned __int16 *)&animData[1].totalSize + animData->numAnimMaps + v67 + 1),
          sentinel: v39,
          indices: v195);
  v70 = idMD6Blend::DecodeRLE(
          RLE: (const unsigned __int8 *)animData + *(&animData[1].size + animData->numAnimMaps + v67),
          sentinel: v39,
          indices: v196);
  if ( v50 != nullptr )
    v71 = idMD6Blend::DecodeRLE(
            RLE: (const unsigned __int8 *)animData + *(&animData[1].flags + animData->numAnimMaps + v67),
            sentinel: v40,
            indices: v198);
  else
    v71 = 0;
  idMD6Blend::DecodeConstantR(
    jointsR: v197,
    numJointsR: v68,
    inR: (const __int16 *)((char *)animData + animData->constROffset),
    outR: stackS);
  idMD6Blend::DecodeConstantST(
    joints: v195,
    numJoints: v69,
    in: (const float *)((char *)&animData->totalSize + animData->constSOffset),
    out: stackT);
  idMD6Blend::DecodeConstantST(
    joints: v196,
    numJoints: v70,
    in: (const float *)((char *)&animData->totalSize + animData->constTOffset),
    out: a29);
  if ( v50 != nullptr )
    idMD6Blend::DecodeConstantU(
      channelsU: v198,
      numUserChannels: v71,
      inU: (const float *)((char *)&animData->totalSize + animData->constUOffset),
      outU: v50);
  v72 = idMD6Blend::DecodeRLE(
          RLE: (const unsigned __int8 *)animData + *(&animData[1].numFrames + animData->numAnimMaps + v67),
          sentinel: v39,
          indices: v197);
  v73 = idMD6Blend::DecodeRLE(
          RLE: (const unsigned __int8 *)animData + *(&animData[1].frameRate + animData->numAnimMaps + v67),
          sentinel: v39,
          indices: v195);
  v74 = idMD6Blend::DecodeRLE(
          RLE: (const unsigned __int8 *)animData + *(&animData[1].numFrameSets + animData->numAnimMaps + v67),
          sentinel: v39,
          indices: v196);
  if ( v50 != nullptr )
    v82 = idMD6Blend::DecodeRLE(
            RLE: (const unsigned __int8 *)animData + *(&animData[1].frameSetTblOffset + animData->numAnimMaps + v67),
            sentinel: v40,
            indices: v198);
  else
    v82 = 0;
  frameRange = frameSetData->frameRange;
  idMD6Blend::DecodeFrameSetR(
    joints: v197,
    numJoints: v72,
    frame,
    numFrames: frameRange,
    fraction: frameFraction,
    firstKeys: (const __int16 *)((char *)frameSetData + frameSetData->RBitsOffset),
    rangeKeys: (const __int16 *)((char *)frameSetData + frameSetData->firstROffset),
    nextKeys: (const __int16 *)((char *)frameSetData + frameSetData->rangeROffset),
    frameBits: (const unsigned __int8 *)frameSetData + frameSetData->nextROffset,
    a10: v81,
    a11: v80,
    a12: v79,
    a13: v78,
    a14: v77,
    a15: v76,
    a16: v75,
    out: v115,
    a18: v119,
    a19: v123,
    a20: v127,
    a21: v131,
    a22: v135,
    a23: v139,
    a24: v143,
    a25: v147,
    a26: v151,
    a27: v155,
    a28: v159,
    a29: v163,
    a30: v167,
    a31: v171,
    a32: v175,
    a33: v179,
    a34: v183,
    a35: v187,
    a36: (const unsigned __int8 *)frameSetData + frameSetData->RBitsOffset,
    a37: v191,
    a38: (int)stackS);
  idMD6Blend::DecodeFrameSetST(
    joints: v195,
    numJoints: v73,
    frame,
    numFrames: frameRange,
    fraction: frameFraction,
    firstKeys: v84,
    rangeKeys: (const float *)((char *)&frameSetData->firstROffset + frameSetData->firstSOffset),
    nextKeys: (const float *)((char *)&frameSetData->firstROffset + frameSetData->rangeSOffset),
    frameBits: (const unsigned __int8 *)frameSetData + frameSetData->nextSOffset,
    a10: v91,
    a11: v90,
    a12: v89,
    a13: v88,
    a14: v87,
    a15: v86,
    a16: v85,
    out: v116,
    a18: v120,
    a19: v124,
    a20: v128,
    a21: v132,
    a22: v136,
    a23: v140,
    a24: v144,
    a25: v148,
    a26: v152,
    a27: v156,
    a28: v160,
    a29: v164,
    a30: v168,
    a31: v172,
    a32: v176,
    a33: v180,
    a34: v184,
    a35: v188,
    a36: (const unsigned __int8 *)frameSetData + frameSetData->SBitsOffset,
    a37: v192,
    a38: (int)stackT);
  idMD6Blend::DecodeFrameSetST(
    joints: v196,
    numJoints: v74,
    frame,
    numFrames: frameRange,
    fraction: frameFraction,
    firstKeys: v92,
    rangeKeys: (const float *)((char *)&frameSetData->firstROffset + frameSetData->firstTOffset),
    nextKeys: (const float *)((char *)&frameSetData->firstROffset + frameSetData->rangeTOffset),
    frameBits: (const unsigned __int8 *)frameSetData + frameSetData->nextTOffset,
    a10: v99,
    a11: v98,
    a12: v97,
    a13: v96,
    a14: v95,
    a15: v94,
    a16: v93,
    out: v117,
    a18: v121,
    a19: v125,
    a20: v129,
    a21: v133,
    a22: v137,
    a23: v141,
    a24: v145,
    a25: v149,
    a26: v153,
    a27: v157,
    a28: v161,
    a29: v165,
    a30: v169,
    a31: v173,
    a32: v177,
    a33: v181,
    a34: v185,
    a35: v189,
    a36: (const unsigned __int8 *)frameSetData + frameSetData->TBitsOffset,
    a37: v193,
    a38: (int)a29);
  if ( v50 != nullptr )
    idMD6Blend::DecodeFrameSetU(
      channelsU: v198,
      numUserChannels: v82,
      frame,
      numFrames: frameRange,
      fraction: frameFraction,
      firstKeys: (const float *)((char *)&frameSetData->firstROffset + frameSetData->UBitsOffset),
      rangeKeys: (const float *)((char *)&frameSetData->firstROffset + frameSetData->firstUOffset),
      nextKeys: (const float *)((char *)&frameSetData->firstROffset + frameSetData->rangeUOffset),
      frameBits: (const unsigned __int8 *)frameSetData + frameSetData->nextUOffset,
      a10: v106,
      a11: v105,
      a12: v104,
      a13: v103,
      a14: v102,
      a15: v101,
      a16: v100,
      out: v118,
      a18: v122,
      a19: v126,
      a20: v130,
      a21: v134,
      a22: v138,
      a23: v142,
      a24: v146,
      a25: v150,
      a26: v154,
      a27: v158,
      a28: v162,
      a29: v166,
      a30: v170,
      a31: v174,
      a32: v178,
      a33: v182,
      a34: v186,
      a35: v190,
      a36: (const unsigned __int8 *)frameSetData + frameSetData->UBitsOffset,
      a37: v194,
      a38: (int)v50);
  numJoints = skeleton->numJoints;
  v108 = (numJoints + 7) & 0xFFF8;
  if ( numJoints < v108 )
  {
    v109 = v108 - numJoints;
    v110 = &stackS[4 * numJoints];
    v111 = &a29[4 * numJoints - 4];
    v112 = &stackT[4 * numJoints + 2];
    v113 = v109;
    v114 = v110 + 1;
    do
    {
      v114[1] = 0.0;
      *v114 = 0.0;
      *(v114 - 1) = 0.0;
      v114[2] = 1.0;
      v112[1] = 1.0;
      *v112 = 1.0;
      *(float *)((char *)v114 + (char *)stackT - (char *)stackS) = 1.0;
      *(v112 - 2) = 1.0;
      v111[7] = 0.0;
      *(float *)((char *)v112 + (char *)a29 - (char *)stackT) = 0.0;
      v112 += 4;
      *(float *)((char *)v114 + (char *)a29 - (char *)stackS) = 0.0;
      v114 += 4;
      v111 += 4;
      *v111 = 0.0;
      --v113;
    }
    while ( v113 != 0 );
  }
  if ( (animData->flags & 0x100) != 0 )
  {
    idMD6Blend::RetargetAdditiveRST(skeleton, outR: stackS, outS: stackT, outT: a29, numJoints: v45);
    if ( v50 != nullptr )
      idMD6Blend::RetargetAdditiveU(skeleton, outU: v50, numUserChannels: v40);
  }
}


// ========================================================================
// ?DecodeAnimFrameU@idMD6Blend@@CAXPIBVidMD6SkelData@@PIBVidMD6AnimData@@PIBUframeSetData_t@@ABUmd6FrameInfo_t@@PIAM@Z
// EA  : 0x82820610
// RVA : 0x00820610
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::DecodeAnimFrameU(
        const idMD6SkelData *skeleton,
        const idMD6AnimData *animData,
        const frameSetData_t *frameSetData,
        const md6FrameInfo_t *frameInfo,
        float *stackU)
{
  unsigned __int16 numUserChannels; // r11
  unsigned __int16 v9; // r27
  float *v13; // r11
  int i; // ctr
  unsigned int v19; // ctr
  int numAnimMaps; // r11
  const idMD6AnimData *v21; // r9
  int v22; // r10
  int v23; // r29
  unsigned int v24; // r3
  unsigned int v25; // r3
  double v26; // fp8
  double v27; // fp7
  double v28; // fp6
  double v29; // fp5
  double v30; // fp4
  double v31; // fp3
  double v32; // fp2
  float *v33; // [sp+8h] [-1B8h]
  int v34; // [sp+Ch] [-1B4h]
  int v35; // [sp+10h] [-1B0h]
  int v36; // [sp+14h] [-1ACh]
  int v37; // [sp+18h] [-1A8h]
  int v38; // [sp+1Ch] [-1A4h]
  int v39; // [sp+20h] [-1A0h]
  unsigned int v40; // [sp+24h] [-19Ch]
  int v41; // [sp+28h] [-198h]
  int v42; // [sp+2Ch] [-194h]
  int v43; // [sp+30h] [-190h]
  float v44; // [sp+34h] [-18Ch]
  int v45; // [sp+38h] [-188h]
  int v46; // [sp+3Ch] [-184h]
  int v47; // [sp+40h] [-180h]
  int v48; // [sp+44h] [-17Ch]
  int v49; // [sp+48h] [-178h]
  int v50; // [sp+4Ch] [-174h]
  int v51; // [sp+50h] [-170h]
  int v52; // [sp+58h] [-168h]
  unsigned __int8 v53[352]; // [sp+60h] [-160h] BYREF

  numUserChannels = skeleton->numUserChannels;
  v9 = (numUserChannels + 7) & 0xFFF8;
  if ( (animData->flags & 0x101) != 0 )
  {
    if ( ((numUserChannels + 7) & 0xFFF8) != 0 )
    {
      v13 = stackU - 1;
      if ( v9 != 0 )
      {
        for ( i = v9; i != 0; --i )
          *++v13 = 0.0;
      }
    }
  }
  else
  {
    _R10 = (char *)skeleton + 40 * ((skeleton->numJoints + 7) & 0xFFF8) + skeleton->basePoseOffset;
    if ( ((numUserChannels + 7) & 0xFFF8) != 0 )
    {
      _R8 = _R10 - (char *)stackU;
      _R11 = stackU + 4;
      _R7 = -16;
      v19 = (((unsigned int)v9 - 1) >> 3) + 1;
      do
      {
        __asm { lvx128    v63, r0, r10 }
        _R10 += 32;
        __asm
        {
          lvx128    v62, r8, r11
          stvx128   v63, r11, r7
          stvx128   v62, r0, r11
        }
        _R11 += 8;
        --v19;
      }
      while ( v19 != 0 );
    }
  }
  numAnimMaps = animData->numAnimMaps;
  v21 = animData + 1;
  v22 = 0;
  if ( animData->numAnimMaps == 0 )
    goto LABEL_15;
  while ( HIWORD(v21->totalSize) != skeleton->parentTblCrc.value )
  {
    ++v22;
    v21 = (const idMD6AnimData *)((char *)v21 + 2);
    if ( v22 >= numAnimMaps )
      goto LABEL_15;
  }
  if ( v22 <= 0 )
LABEL_15:
    v22 = 0;
  v23 = 8 * v22;
  v24 = idMD6Blend::DecodeRLE(
          RLE: (const unsigned __int8 *)animData + *(&animData[1].flags + 8 * v22 + numAnimMaps),
          sentinel: v9,
          indices: v53);
  idMD6Blend::DecodeConstantU(
    channelsU: v53,
    numUserChannels: v24,
    inU: (const float *)((char *)&animData->totalSize + animData->constUOffset),
    outU: stackU);
  v25 = idMD6Blend::DecodeRLE(
          RLE: (const unsigned __int8 *)animData + *(&animData[1].frameSetTblOffset + animData->numAnimMaps + v23),
          sentinel: v9,
          indices: v53);
  idMD6Blend::DecodeFrameSetU(
    channelsU: v53,
    numUserChannels: v25,
    frame: frameInfo->frameSetFrame,
    numFrames: frameSetData->frameRange,
    fraction: frameInfo->frameFraction,
    firstKeys: (const float *)((char *)&frameSetData->firstROffset + frameSetData->UBitsOffset),
    rangeKeys: (const float *)((char *)&frameSetData->firstROffset + frameSetData->firstUOffset),
    nextKeys: (const float *)((char *)&frameSetData->firstROffset + frameSetData->rangeUOffset),
    frameBits: (const unsigned __int8 *)frameSetData + frameSetData->nextUOffset,
    a10: v32,
    a11: v31,
    a12: v30,
    a13: v29,
    a14: v28,
    a15: v27,
    a16: v26,
    out: v33,
    a18: v34,
    a19: v35,
    a20: v36,
    a21: v37,
    a22: v38,
    a23: v39,
    a24: v40,
    a25: v41,
    a26: v42,
    a27: v43,
    a28: v44,
    a29: v45,
    a30: v46,
    a31: v47,
    a32: v48,
    a33: v49,
    a34: v50,
    a35: v51,
    a36: (const unsigned __int8 *)frameSetData + frameSetData->UBitsOffset,
    a37: v52,
    a38: (int)stackU);
  if ( (animData->flags & 0x100) != 0 )
    idMD6Blend::RetargetAdditiveU(skeleton, outU: stackU, numUserChannels: v9);
}


// ========================================================================
// ?DecodeUserChannelsForAnimFrame@idMD6Blend@@SAXPIBVidMD6SkelData@@PIBVidMD6AnimData@@MPIAMI@Z
// EA  : 0x828207F8
// RVA : 0x008207F8
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::DecodeUserChannelsForAnimFrame(
        const idMD6SkelData *skeleton,
        const idMD6AnimData *animData,
        double frame,
        float *outUserChannels,
        float *outUserChannelsSize)
{
  __int64 v5; // r11
  const frameSetData_t *v6; // r5
  md6FrameInfo_t v7; // [sp+60h] [-40h] BYREF

  HIDWORD(v5) = &v7;
  LODWORD(v5) = 0;
  *(_QWORD *)HIDWORD(v5) = v5;
  *(_QWORD *)(HIDWORD(v5) + 8) = v5;
  *(_QWORD *)(HIDWORD(v5) + 16) = v5;
  *(_QWORD *)(HIDWORD(v5) + 24) = v5;
  *(_QWORD *)(HIDWORD(v5) + 32) = v5;
  v7.originFrameSetData = nullptr;
  if ( frame >= 0.0 )
  {
    LODWORD(v5) = animData->numFrames;
    if ( frame < (float)v5 )
    {
      LODWORD(v5) = (__int16)(int)frame;
      v7.frameFraction = (float)frame - (float)v5;
    }
    else
    {
      v7.frameFraction = 0.0;
      LOWORD(v5) = v5 - 1;
    }
  }
  else
  {
    v7.frameFraction = 0.0;
  }
  v7.frame = v5;
  v6 = (const frameSetData_t *)((char *)animData
                              + 16
                              * *(unsigned int *)((char *)&animData->totalSize
                                                + __ROL4__(
                                                    *((unsigned __int8 *)&animData->totalSize
                                                    + animData->frameSetTblOffset
                                                    + (__int16)v5),
                                                    2)
                                                + animData->frameSetOffsetTblOffset));
  v7.frameSetFrame = v5 - v6->frameStart;
  idMD6Blend::DecodeAnimFrameU(skeleton, animData, frameSetData: v6, frameInfo: &v7, stackU: outUserChannelsSize);
}


// ========================================================================
// ?ApplyAnimMods@idMD6Blend@@CAXPIBVidMD6SkelData@@PIBUjointMod_t@1@IPIAM222@Z
// EA  : 0x828208F0
// RVA : 0x008208F0
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::ApplyAnimMods(
        const idMD6SkelData *skeleton,
        const idMD6Blend::jointMod_t *animMods,
        unsigned int numAnimMods,
        const float *R,
        const float *S,
        const float *T,
        float *U)
{
  unsigned int v12; // ctr
  float *v13; // r10
  float *v14; // r11
  double v15; // fp0
  double v16; // fp13
  double v17; // fp12
  double v18; // fp0
  double v19; // fp6
  double v20; // fp4
  double v21; // fp3
  double v22; // fp2
  double v23; // fp11
  double v24; // fp5
  double v25; // fp2
  double v26; // fp8
  double v27; // fp5
  double v28; // fp3
  double v29; // fp0
  double v30; // fp13
  double v31; // fp2
  double v32; // fp0
  double v33; // fp9
  double v34; // fp3
  double v35; // fp7
  double v36; // fp8
  double v37; // fp0
  double v38; // fp13
  double v39; // fp2
  double v40; // fp0
  double v41; // fp8
  double v42; // fp0
  double v43; // fp13
  double v44; // fp2
  double v45; // fp0
  double v46; // fp13
  double v47; // fp12
  double v48; // fp11
  double v49; // fp9
  double v50; // fp8
  double v51; // fp0
  const __int16 *v52; // r3
  float *v53; // r31
  idIndex<short,enum invalidJointIndex_t> *p_joint; // r26
  unsigned int i; // r22
  __int16 value; // r27
  int v57; // r10
  float *v58; // r30
  float *v59; // r29
  float *v60; // r28
  float *v61; // r11
  double v62; // fp11
  double v63; // fp0
  double v64; // fp13
  double v65; // fp12
  double v66; // fp1
  double v67; // fp10
  double v68; // fp9
  double v69; // fp8
  double v70; // fp3
  double v71; // fp6
  double v72; // fp4
  double v73; // fp3
  double v74; // fp9
  double v75; // fp8
  double v76; // fp7
  double v77; // fp6
  double v78; // fp3
  double v79; // fp2
  double v80; // fp1
  double v81; // fp10
  double v82; // fp9
  double v83; // fp8
  double v84; // fp7
  double v85; // fp6
  double v86; // fp5
  double v87; // fp4
  double v88; // fp10
  double v89; // fp9
  double v90; // fp10
  double v91; // fp9
  double v92; // fp8
  double v93; // fp7
  double v94; // fp1
  double v95; // fp10
  double v96; // fp7
  double v97; // fp5
  double v98; // fp6
  double v99; // fp9
  double v100; // fp3
  double v101; // fp1
  double v102; // fp9
  double v103; // fp2
  double v104; // fp10
  double v105; // fp9
  double v106; // fp10
  double v107; // fp4
  double v108; // fp9
  double v109; // fp8
  double v110; // fp1
  double v111; // fp3
  double v112; // fp27
  double v113; // fp26
  double v114; // fp2
  double v115; // fp7
  double v116; // fp6
  double v117; // fp5
  double v118; // fp25
  double v119; // fp25
  double v120; // fp27
  double v121; // fp2
  double v122; // fp4
  double v123; // fp3
  double v124; // fp2
  double v125; // fp7
  double v126; // fp6
  double v127; // fp5
  double v128; // fp4
  double v129; // fp1
  double v130; // fp10
  double v131; // fp3
  double v132; // fp2
  double v133; // fp13
  double v134; // fp12
  double v135; // fp11
  double v136; // fp13
  double v137; // fp12
  double v138; // fp11
  double v139; // fp13
  double v140; // fp12
  double v141; // fp11
  double v142; // fp13
  double v143; // fp12
  double v144; // fp7
  double v145; // fp6
  double v146; // fp4
  double v147; // fp3
  double v148; // fp1
  double v149; // fp12
  double v150; // fp11
  double v151; // fp10
  double v152; // fp5
  double v153; // fp7
  double v154; // fp5
  double v155; // fp6
  double v156; // fp4
  double v157; // fp3
  double v158; // fp6
  double v159; // fp4
  double v160; // fp3
  double v161; // fp7
  double v162; // fp6
  float v163; // [sp+50h] [-3100h] BYREF
  float v164; // [sp+54h] [-30FCh]
  float v165; // [sp+58h] [-30F8h]
  float v166; // [sp+5Ch] [-30F4h]
  float v167; // [sp+60h] [-30F0h] BYREF
  float v168; // [sp+64h] [-30ECh]
  float v169; // [sp+68h] [-30E8h]
  float v170; // [sp+70h] [-30E0h] BYREF
  float v171; // [sp+74h] [-30DCh]
  float v172; // [sp+78h] [-30D8h]
  char v173; // [sp+7Ch] [-30D4h] BYREF
  char v174; // [sp+88h] [-30C8h] BYREF

  if ( numAnimMods != 0 )
  {
    v12 = numAnimMods;
    v13 = (float *)&v173;
    v14 = &animMods[-1].mat[11];
    do
    {
      if ( (*((_WORD *)v14 + 41) & 2) != 0 )
      {
        v15 = v14[15];
        v16 = v14[10];
        v17 = v14[5];
        if ( (float)((float)(v14[10] + v14[15]) + v14[5]) <= 0.0 )
        {
          if ( v17 <= v16 || v17 <= v15 )
          {
            v33 = v14[13];
            v34 = (float)(v14[14] + v14[11]);
            v35 = v14[7];
            if ( v16 <= v15 )
            {
              v41 = (float)(v14[9] - v14[6]);
              v43 = (float)((float)((float)(v14[15] - (float)(v14[10] + v14[5])) + (float)1.0) * (float)0.5);
              v42 = __frsqrte((float)((float)(v14[15] - (float)(v14[10] + v14[5])) + (float)1.0));
              v44 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v42
                                                                                                  * (float)v43)
                                                                                          * (float)v42)
                                                                                  - (float)1.5)
                                                                  * (float)v42)
                                                          * (float)v43)
                                                  * (float)((float)-(float)((float)((float)((float)v42 * (float)v43)
                                                                                  * (float)v42)
                                                                          - (float)1.5)
                                                          * (float)v42))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v42 * (float)v43) * (float)v42) - (float)1.5)
                                  * (float)v42));
              v45 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v42 * (float)v43)
                                                                                                  * (float)v42)
                                                                                          - (float)1.5)
                                                                          * (float)v42)
                                                                  * (float)v43)
                                                          * (float)((float)-(float)((float)((float)((float)v42
                                                                                                  * (float)v43)
                                                                                          * (float)v42)
                                                                                  - (float)1.5)
                                                                  * (float)v42))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)((float)v42 * (float)v43) * (float)v42)
                                                          - (float)1.5)
                                          * (float)v42))
                          * (float)v43);
              v13[3] = (float)((float)((float)-(float)((float)((float)v45 * (float)v44) - (float)1.5) * (float)v44)
                             * (float)0.5)
                     * (float)((float)(v14[15] - (float)(v14[10] + v14[5])) + (float)1.0);
              v13[4] = (float)v41
                     * (float)((float)((float)-(float)((float)((float)v45 * (float)v44) - (float)1.5) * (float)v44)
                             * (float)0.5);
              v13[1] = (float)((float)v33 + (float)v35)
                     * (float)((float)((float)-(float)((float)((float)v45 * (float)v44) - (float)1.5) * (float)v44)
                             * (float)0.5);
              v13[2] = (float)v34
                     * (float)((float)((float)-(float)((float)((float)v45 * (float)v44) - (float)1.5) * (float)v44)
                             * (float)0.5);
            }
            else
            {
              v36 = (float)(v14[9] + v14[6]);
              v38 = (float)((float)((float)((float)(v14[10] - v14[5]) - v14[15]) + (float)1.0) * (float)0.5);
              v37 = __frsqrte((float)((float)((float)(v14[10] - v14[5]) - v14[15]) + (float)1.0));
              v39 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v37
                                                                                                  * (float)v38)
                                                                                          * (float)v37)
                                                                                  - (float)1.5)
                                                                  * (float)v37)
                                                          * (float)v38)
                                                  * (float)((float)-(float)((float)((float)((float)v37 * (float)v38)
                                                                                  * (float)v37)
                                                                          - (float)1.5)
                                                          * (float)v37))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v37 * (float)v38) * (float)v37) - (float)1.5)
                                  * (float)v37));
              v40 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v37 * (float)v38)
                                                                                                  * (float)v37)
                                                                                          - (float)1.5)
                                                                          * (float)v37)
                                                                  * (float)v38)
                                                          * (float)((float)-(float)((float)((float)((float)v37
                                                                                                  * (float)v38)
                                                                                          * (float)v37)
                                                                                  - (float)1.5)
                                                                  * (float)v37))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)((float)v37 * (float)v38) * (float)v37)
                                                          - (float)1.5)
                                          * (float)v37))
                          * (float)v38);
              v13[2] = (float)((float)((float)-(float)((float)((float)v40 * (float)v39) - (float)1.5) * (float)v39)
                             * (float)0.5)
                     * (float)((float)((float)(v14[10] - v14[5]) - v14[15]) + (float)1.0);
              v13[1] = (float)v36
                     * (float)((float)((float)-(float)((float)((float)v40 * (float)v39) - (float)1.5) * (float)v39)
                             * (float)0.5);
              v13[4] = (float)((float)v35 - (float)v33)
                     * (float)((float)((float)-(float)((float)((float)v40 * (float)v39) - (float)1.5) * (float)v39)
                             * (float)0.5);
              v13[3] = (float)v34
                     * (float)((float)((float)-(float)((float)((float)v40 * (float)v39) - (float)1.5) * (float)v39)
                             * (float)0.5);
            }
          }
          else
          {
            v26 = (float)(v14[9] + v14[6]);
            v27 = (float)(v14[13] + v14[7]);
            v28 = (float)(v14[14] - v14[11]);
            v30 = (float)((float)((float)((float)(v14[5] - v14[10]) - v14[15]) + (float)1.0) * (float)0.5);
            v29 = __frsqrte((float)((float)((float)(v14[5] - v14[10]) - v14[15]) + (float)1.0));
            v31 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29 * (float)v30)
                                                                                        * (float)v29)
                                                                                - (float)1.5)
                                                                * (float)v29)
                                                        * (float)v30)
                                                * (float)((float)-(float)((float)((float)((float)v29 * (float)v30)
                                                                                * (float)v29)
                                                                        - (float)1.5)
                                                        * (float)v29))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v29 * (float)v30) * (float)v29) - (float)1.5)
                                * (float)v29));
            v32 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29 * (float)v30)
                                                                                                * (float)v29)
                                                                                        - (float)1.5)
                                                                        * (float)v29)
                                                                * (float)v30)
                                                        * (float)((float)-(float)((float)((float)((float)v29 * (float)v30)
                                                                                        * (float)v29)
                                                                                - (float)1.5)
                                                                * (float)v29))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)v29 * (float)v30) * (float)v29)
                                                        - (float)1.5)
                                        * (float)v29))
                        * (float)v30);
            v13[1] = (float)((float)((float)-(float)((float)((float)v32 * (float)v31) - (float)1.5) * (float)v31)
                           * (float)0.5)
                   * (float)((float)((float)(v14[5] - v14[10]) - v14[15]) + (float)1.0);
            v13[2] = (float)v26
                   * (float)((float)((float)-(float)((float)((float)v32 * (float)v31) - (float)1.5) * (float)v31)
                           * (float)0.5);
            v13[3] = (float)v27
                   * (float)((float)((float)-(float)((float)((float)v32 * (float)v31) - (float)1.5) * (float)v31)
                           * (float)0.5);
            v13[4] = (float)v28
                   * (float)((float)((float)-(float)((float)((float)v32 * (float)v31) - (float)1.5) * (float)v31)
                           * (float)0.5);
          }
        }
        else
        {
          v18 = (float)((float)((float)(v14[10] + v14[15]) + v14[5]) + (float)1.0);
          v19 = (float)(v14[7] - v14[13]);
          v20 = (float)(v14[14] - v14[11]);
          v21 = __frsqrte(v18);
          v22 = (float)((float)((float)((float)(v14[10] + v14[15]) + v14[5]) + (float)1.0) * (float)0.5);
          v23 = (float)((float)-(float)((float)((float)((float)v21
                                                      * (float)((float)((float)((float)(v14[10] + v14[15]) + v14[5])
                                                                      + (float)1.0)
                                                              * (float)0.5))
                                              * (float)v21)
                                      - (float)1.5)
                      * (float)v21);
          v24 = (float)((float)-(float)((float)((float)((float)v23
                                                      * (float)((float)((float)((float)(v14[10] + v14[15]) + v14[5])
                                                                      + (float)1.0)
                                                              * (float)0.5))
                                              * (float)v23)
                                      - (float)1.5)
                      * (float)v23);
          v25 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)v22)
                                                                              * (float)v23)
                                                                      - (float)1.5)
                                                      * (float)v23)
                                              * (float)v22)
                                      * (float)((float)-(float)((float)((float)((float)v23 * (float)v22) * (float)v23)
                                                              - (float)1.5)
                                              * (float)v23))
                              - (float)1.5);
          v13[3] = (float)(v14[9] - v14[6])
                 * (float)((float)((float)v25
                                 * (float)((float)-(float)((float)((float)((float)v23
                                                                         * (float)((float)((float)((float)(v14[10] + v14[15])
                                                                                                 + v14[5])
                                                                                         + (float)1.0)
                                                                                 * (float)0.5))
                                                                 * (float)v23)
                                                         - (float)1.5)
                                         * (float)v23))
                         * (float)0.5);
          v13[4] = (float)((float)((float)v25 * (float)v24) * (float)0.5) * (float)v18;
          v13[2] = (float)v19 * (float)((float)((float)v25 * (float)v24) * (float)0.5);
          v13[1] = (float)v20 * (float)((float)((float)v25 * (float)v24) * (float)0.5);
        }
      }
      else
      {
        v13[1] = 0.0;
        v13[2] = 0.0;
        v13[3] = 0.0;
        v13[4] = 1.0;
      }
      v46 = v14[17];
      v47 = v14[18];
      v48 = v14[19];
      v49 = v14[8];
      v50 = v14[12];
      v14 += 16;
      v51 = *v14;
      v13[5] = v46;
      v13[6] = v47;
      v13[7] = v48;
      v13[8] = 0.0;
      v13[9] = v49;
      v13[10] = v50;
      v13[11] = v51;
      v13 += 12;
      *v13 = 0.0;
      --v12;
    }
    while ( v12 != 0 );
  }
  v52 = (const __int16 *)((char *)skeleton + skeleton->parentTblOffset);
  if ( numAnimMods != 0 )
  {
    v53 = (float *)&v174;
    p_joint = &animMods->joint;
    for ( i = numAnimMods; i != 0; --i )
    {
      value = p_joint[1].value;
      v57 = p_joint->value;
      if ( v57 >= 0 && ((((skeleton->numJoints ^ v57) >= 0) + (v57 >= (unsigned int)skeleton->numJoints)) & 1) != 0 )
      {
        v58 = (float *)&R[4 * v57];
        v59 = (float *)&S[4 * v57];
        v60 = (float *)&T[4 * v57];
        v61 = &U[v57];
        if ( (value & 1) != 0 )
        {
          idMD6Blend::TransformLocalJointToModelJoint(
            parentTable: v52,
            joint: v52[v57],
            inR: R,
            inS: S,
            inT: T,
            outR: &v163,
            outS: &v167,
            outT: &v170);
          v62 = v166;
          v63 = v165;
          v64 = v164;
          v65 = v163;
          if ( (value & 0x20) != 0 )
          {
            if ( (value & 2) != 0 )
            {
              v66 = (float)((float)(v164 * *(v53 - 2))
                          - (float)((float)(v163 * *(v53 - 1)) - (float)((float)(v166 * *v53) - (float)(v165 * v53[1]))));
              v67 = (float)((float)(v163 * *(v53 - 2))
                          + (float)((float)(v164 * *(v53 - 1)) + (float)((float)(v166 * v53[1]) + (float)(v165 * *v53))));
              v68 = (float)((float)(v163 * *v53)
                          - (float)((float)(v165 * *(v53 - 2))
                                  - (float)((float)(v166 * *(v53 - 1)) - (float)(v164 * v53[1]))));
              v69 = (float)((float)(v165 * *(v53 - 1))
                          - (float)((float)(v164 * *v53) - (float)((float)(v166 * *(v53 - 2)) - (float)(v163 * v53[1]))));
              v70 = __frsqrte((float)((float)((float)v69 * (float)v69)
                                    + (float)((float)((float)v68 * (float)v68)
                                            + (float)((float)((float)v67 * (float)v67) + (float)((float)v66 * (float)v66)))));
              v71 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v70
                                                                                                  * (float)((float)((float)((float)v69 * (float)v69) + (float)((float)((float)v68 * (float)v68) + (float)((float)((float)v67 * (float)v67) + (float)((float)v66 * (float)v66)))) * (float)0.5))
                                                                                          * (float)v70)
                                                                                  - (float)1.5)
                                                                  * (float)v70)
                                                          * (float)((float)((float)((float)v69 * (float)v69)
                                                                          + (float)((float)((float)v68 * (float)v68)
                                                                                  + (float)((float)((float)v67
                                                                                                  * (float)v67)
                                                                                          + (float)((float)v66
                                                                                                  * (float)v66))))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v70
                                                                                          * (float)((float)((float)((float)v69 * (float)v69) + (float)((float)((float)v68 * (float)v68) + (float)((float)((float)v67 * (float)v67) + (float)((float)v66 * (float)v66))))
                                                                                                  * (float)0.5))
                                                                                  * (float)v70)
                                                                          - (float)1.5)
                                                          * (float)v70))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v70
                                                                  * (float)((float)((float)((float)v69 * (float)v69)
                                                                                  + (float)((float)((float)v68
                                                                                                  * (float)v68)
                                                                                          + (float)((float)((float)v67 * (float)v67)
                                                                                                  + (float)((float)v66 * (float)v66))))
                                                                          * (float)0.5))
                                                          * (float)v70)
                                                  - (float)1.5)
                                  * (float)v70));
              v72 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v70 * (float)((float)((float)((float)v69 * (float)v69) + (float)((float)((float)v68 * (float)v68) + (float)((float)((float)v67 * (float)v67) + (float)((float)v66 * (float)v66)))) * (float)0.5)) * (float)v70) - (float)1.5)
                                                                                                  * (float)v70)
                                                                                          * (float)((float)((float)((float)v69 * (float)v69) + (float)((float)((float)v68 * (float)v68) + (float)((float)((float)v67 * (float)v67) + (float)((float)v66 * (float)v66))))
                                                                                                  * (float)0.5))
                                                                                  * (float)((float)-(float)((float)((float)((float)v70 * (float)((float)((float)((float)v69 * (float)v69) + (float)((float)((float)v68 * (float)v68) + (float)((float)((float)v67 * (float)v67) + (float)((float)v66 * (float)v66)))) * (float)0.5)) * (float)v70) - (float)1.5)
                                                                                          * (float)v70))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)((float)v70
                                                                                                  * (float)((float)((float)((float)v69 * (float)v69) + (float)((float)((float)v68 * (float)v68) + (float)((float)((float)v67 * (float)v67) + (float)((float)v66 * (float)v66)))) * (float)0.5))
                                                                                          * (float)v70)
                                                                                  - (float)1.5)
                                                                  * (float)v70))
                                                  * (float)((float)((float)((float)v69 * (float)v69)
                                                                  + (float)((float)((float)v68 * (float)v68)
                                                                          + (float)((float)((float)v67 * (float)v67)
                                                                                  + (float)((float)v66 * (float)v66))))
                                                          * (float)0.5))
                                          * (float)v71)
                                  - (float)1.5);
              v73 = (float)((float)v72
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v70 * (float)((float)((float)((float)v69 * (float)v69) + (float)((float)((float)v68 * (float)v68) + (float)((float)((float)v67 * (float)v67) + (float)((float)v66 * (float)v66)))) * (float)0.5))
                                                                                                  * (float)v70)
                                                                                          - (float)1.5)
                                                                          * (float)v70)
                                                                  * (float)((float)((float)((float)v69 * (float)v69)
                                                                                  + (float)((float)((float)v68
                                                                                                  * (float)v68)
                                                                                          + (float)((float)((float)v67 * (float)v67)
                                                                                                  + (float)((float)v66 * (float)v66))))
                                                                          * (float)0.5))
                                                          * (float)((float)-(float)((float)((float)((float)v70
                                                                                                  * (float)((float)((float)((float)v69 * (float)v69) + (float)((float)((float)v68 * (float)v68) + (float)((float)((float)v67 * (float)v67) + (float)((float)v66 * (float)v66)))) * (float)0.5))
                                                                                          * (float)v70)
                                                                                  - (float)1.5)
                                                                  * (float)v70))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)((float)v70
                                                                          * (float)((float)((float)((float)v69
                                                                                                  * (float)v69)
                                                                                          + (float)((float)((float)v68 * (float)v68)
                                                                                                  + (float)((float)((float)v67 * (float)v67) + (float)((float)v66 * (float)v66))))
                                                                                  * (float)0.5))
                                                                  * (float)v70)
                                                          - (float)1.5)
                                          * (float)v70)));
              *v58 = (float)((float)(v165 * *(v53 - 1))
                           - (float)((float)(v164 * *v53) - (float)((float)(v166 * *(v53 - 2)) - (float)(v163 * v53[1]))))
                   * (float)v73;
              v58[1] = (float)v68 * (float)v73;
              v58[2] = (float)v66 * (float)v73;
              v58[3] = (float)v67 * (float)v73;
            }
            if ( (value & 4) != 0 )
            {
              v74 = v53[3];
              v75 = v53[4];
              v76 = v53[5];
              *v59 = v53[2];
              v59[1] = v74;
              v59[2] = v75;
              v59[3] = v76;
            }
            if ( (value & 8) != 0 )
            {
              v77 = (float)(v53[6] - v170);
              v78 = (float)(v53[7] - v171);
              v79 = (float)(v53[8] - v172);
              v80 = v167;
              v81 = v168;
              v82 = v169;
              v60[3] = 0.0;
              v83 = (float)((float)v77 / (float)v80);
              v84 = (float)((float)v78 / (float)v81);
              v86 = (float)((float)((float)v77 / (float)v80) * (float)v63);
              v85 = (float)((float)v79 / (float)v82);
              v87 = (float)((float)((float)v78 / (float)v81) * (float)v65);
              v88 = (float)((float)((float)((float)v78 / (float)v81) * (float)v63)
                          - (float)((float)((float)v79 / (float)v82) * (float)v64));
              v89 = (float)((float)((float)v84 * (float)v62)
                          + (float)((float)((float)((float)v79 / (float)v82) * (float)v65) - (float)v86));
              v60[2] = (float)((float)((float)((float)((float)((float)v83 * (float)v62) + (float)v88) * (float)v64)
                                     - (float)((float)v89 * (float)v65))
                             * (float)2.0)
                     + (float)v85;
              *v60 = (float)((float)((float)((float)v89 * (float)v63)
                                   - (float)((float)((float)((float)v85 * (float)v62)
                                                   + (float)((float)((float)v83 * (float)v64) - (float)v87))
                                           * (float)v64))
                           * (float)2.0)
                   + (float)v83;
              v60[1] = (float)((float)((float)((float)((float)((float)v85 * (float)v62)
                                                     + (float)((float)((float)v83 * (float)v64) - (float)v87))
                                             * (float)v65)
                                     - (float)((float)((float)((float)v83 * (float)v62) + (float)v88) * (float)v63))
                             * (float)2.0)
                     + (float)v84;
            }
          }
          else
          {
            if ( (value & 2) != 0 )
            {
              v90 = (float)-(float)((float)(*v53
                                          * (float)-(float)((float)(*v58 * v164)
                                                          - (float)((float)(v58[2] * v166)
                                                                  + (float)((float)(v58[1] * v163)
                                                                          + (float)(v58[3] * v165)))))
                                  - (float)-(float)((float)(*(v53 - 1)
                                                          * (float)-(float)((float)(v58[2] * v163)
                                                                          - (float)((float)(v58[3] * v164)
                                                                                  + (float)((float)(*v58 * v165)
                                                                                          + (float)(v58[1] * v166)))))
                                                  - (float)((float)(v53[1]
                                                                  * (float)-(float)((float)(v58[2] * v165)
                                                                                  - (float)-(float)((float)(v58[1] * v164)
                                                                                                  - (float)((float)(v58[3] * v166) - (float)(*v58 * v163)))))
                                                          - (float)(*(v53 - 2)
                                                                  * (float)-(float)((float)(v58[1] * v165)
                                                                                  - (float)((float)(v58[3] * v163)
                                                                                          + (float)((float)(*v58 * v166)
                                                                                                  + (float)(v58[2] * v164))))))));
              v91 = (float)-(float)((float)(*(v53 - 2)
                                          * (float)-(float)((float)(*v58 * v164)
                                                          - (float)((float)(v58[2] * v166)
                                                                  + (float)((float)(v58[1] * v163)
                                                                          + (float)(v58[3] * v165)))))
                                  - (float)((float)(*v53
                                                  * (float)-(float)((float)(v58[1] * v165)
                                                                  - (float)((float)(v58[3] * v163)
                                                                          + (float)((float)(*v58 * v166)
                                                                                  + (float)(v58[2] * v164)))))
                                          + (float)((float)(*(v53 - 1)
                                                          * (float)-(float)((float)(v58[2] * v165)
                                                                          - (float)-(float)((float)(v58[1] * v164)
                                                                                          - (float)((float)(v58[3] * v166)
                                                                                                  - (float)(*v58 * v163)))))
                                                  + (float)(v53[1]
                                                          * (float)-(float)((float)(v58[2] * v163)
                                                                          - (float)((float)(v58[3] * v164)
                                                                                  + (float)((float)(*v58 * v165)
                                                                                          + (float)(v58[1] * v166))))))));
              v92 = (float)-(float)((float)(*v53
                                          * (float)-(float)((float)(v58[2] * v163)
                                                          - (float)((float)(v58[3] * v164)
                                                                  + (float)((float)(*v58 * v165) + (float)(v58[1] * v166)))))
                                  - (float)((float)(v53[1]
                                                  * (float)-(float)((float)(v58[1] * v165)
                                                                  - (float)((float)(v58[3] * v163)
                                                                          + (float)((float)(*v58 * v166)
                                                                                  + (float)(v58[2] * v164)))))
                                          + (float)((float)(*(v53 - 2)
                                                          * (float)-(float)((float)(v58[2] * v165)
                                                                          - (float)-(float)((float)(v58[1] * v164)
                                                                                          - (float)((float)(v58[3] * v166)
                                                                                                  - (float)(*v58 * v163)))))
                                                  + (float)(*(v53 - 1)
                                                          * (float)-(float)((float)(*v58 * v164)
                                                                          - (float)((float)(v58[2] * v166)
                                                                                  + (float)((float)(v58[1] * v163)
                                                                                          + (float)(v58[3] * v165))))))));
              v93 = (float)-(float)((float)(*(v53 - 1)
                                          * (float)-(float)((float)(v58[1] * v165)
                                                          - (float)((float)(v58[3] * v163)
                                                                  + (float)((float)(*v58 * v166) + (float)(v58[2] * v164)))))
                                  - (float)((float)(*(v53 - 2)
                                                  * (float)-(float)((float)(v58[2] * v163)
                                                                  - (float)((float)(v58[3] * v164)
                                                                          + (float)((float)(*v58 * v165)
                                                                                  + (float)(v58[1] * v166)))))
                                          + (float)((float)(*v53
                                                          * (float)-(float)((float)(v58[2] * v165)
                                                                          - (float)-(float)((float)(v58[1] * v164)
                                                                                          - (float)((float)(v58[3] * v166)
                                                                                                  - (float)(*v58 * v163)))))
                                                  + (float)(v53[1]
                                                          * (float)-(float)((float)(*v58 * v164)
                                                                          - (float)((float)(v58[2] * v166)
                                                                                  + (float)((float)(v58[1] * v163)
                                                                                          + (float)(v58[3] * v165))))))));
              v94 = (float)((float)((float)v90 * v166)
                          + (float)((float)((float)v93 * v165)
                                  + (float)((float)-(float)((float)(*(v53 - 2)
                                                                  * (float)-(float)((float)(*v58 * v164)
                                                                                  - (float)((float)(v58[2] * v166)
                                                                                          + (float)((float)(v58[1] * v163)
                                                                                                  + (float)(v58[3] * v165)))))
                                                          - (float)((float)(*v53
                                                                          * (float)-(float)((float)(v58[1] * v165)
                                                                                          - (float)((float)(v58[3] * v163)
                                                                                                  + (float)((float)(*v58 * v166) + (float)(v58[2] * v164)))))
                                                                  + (float)((float)(*(v53 - 1)
                                                                                  * (float)-(float)((float)(v58[2] * v165)
                                                                                                  - (float)-(float)((float)(v58[1] * v164) - (float)((float)(v58[3] * v166) - (float)(*v58 * v163)))))
                                                                          + (float)(v53[1]
                                                                                  * (float)-(float)((float)(v58[2] * v163)
                                                                                                  - (float)((float)(v58[3] * v164) + (float)((float)(*v58 * v165) + (float)(v58[1] * v166))))))))
                                          * v164)));
              v95 = (float)((float)((float)v93 * v163)
                          - (float)((float)((float)v92 * v165)
                                  - (float)((float)((float)v91 * v166)
                                          - (float)((float)-(float)((float)(*v53
                                                                          * (float)-(float)((float)(*v58 * v164)
                                                                                          - (float)((float)(v58[2] * v166)
                                                                                                  + (float)((float)(v58[1] * v163) + (float)(v58[3] * v165)))))
                                                                  - (float)-(float)((float)(*(v53 - 1)
                                                                                          * (float)-(float)((float)(v58[2] * v163) - (float)((float)(v58[3] * v164) + (float)((float)(*v58 * v165) + (float)(v58[1] * v166)))))
                                                                                  - (float)((float)(v53[1]
                                                                                                  * (float)-(float)((float)(v58[2] * v165) - (float)-(float)((float)(v58[1] * v164) - (float)((float)(v58[3] * v166) - (float)(*v58 * v163)))))
                                                                                          - (float)(*(v53 - 2)
                                                                                                  * (float)-(float)((float)(v58[1] * v165) - (float)((float)(v58[3] * v163) + (float)((float)(*v58 * v166) + (float)(v58[2] * v164))))))))
                                                  * v164))));
              v97 = (float)((float)((float)-(float)((float)(*v53
                                                          * (float)-(float)((float)(v58[2] * v163)
                                                                          - (float)((float)(v58[3] * v164)
                                                                                  + (float)((float)(*v58 * v165)
                                                                                          + (float)(v58[1] * v166)))))
                                                  - (float)((float)(v53[1]
                                                                  * (float)-(float)((float)(v58[1] * v165)
                                                                                  - (float)((float)(v58[3] * v163)
                                                                                          + (float)((float)(*v58 * v166)
                                                                                                  + (float)(v58[2] * v164)))))
                                                          + (float)((float)(*(v53 - 2)
                                                                          * (float)-(float)((float)(v58[2] * v165)
                                                                                          - (float)-(float)((float)(v58[1] * v164) - (float)((float)(v58[3] * v166) - (float)(*v58 * v163)))))
                                                                  + (float)(*(v53 - 1)
                                                                          * (float)-(float)((float)(*v58 * v164)
                                                                                          - (float)((float)(v58[2] * v166)
                                                                                                  + (float)((float)(v58[1] * v163) + (float)(v58[3] * v165))))))))
                                  * v163)
                          + (float)v94);
              v98 = (float)((float)((float)v91 * v165)
                          - (float)((float)((float)v93 * v164)
                                  - (float)((float)((float)v92 * v166)
                                          - (float)((float)-(float)((float)(*v53
                                                                          * (float)-(float)((float)(*v58 * v164)
                                                                                          - (float)((float)(v58[2] * v166)
                                                                                                  + (float)((float)(v58[1] * v163) + (float)(v58[3] * v165)))))
                                                                  - (float)-(float)((float)(*(v53 - 1)
                                                                                          * (float)-(float)((float)(v58[2] * v163) - (float)((float)(v58[3] * v164) + (float)((float)(*v58 * v165) + (float)(v58[1] * v166)))))
                                                                                  - (float)((float)(v53[1]
                                                                                                  * (float)-(float)((float)(v58[2] * v165) - (float)-(float)((float)(v58[1] * v164) - (float)((float)(v58[3] * v166) - (float)(*v58 * v163)))))
                                                                                          - (float)(*(v53 - 2)
                                                                                                  * (float)-(float)((float)(v58[1] * v165) - (float)((float)(v58[3] * v163) + (float)((float)(*v58 * v166) + (float)(v58[2] * v164))))))))
                                                  * v163))));
              v96 = (float)((float)((float)v92 * v164)
                          - (float)((float)((float)v91 * v163)
                                  - (float)((float)((float)v93 * v166)
                                          - (float)((float)-(float)((float)(*v53
                                                                          * (float)-(float)((float)(*v58 * v164)
                                                                                          - (float)((float)(v58[2] * v166)
                                                                                                  + (float)((float)(v58[1] * v163) + (float)(v58[3] * v165)))))
                                                                  - (float)-(float)((float)(*(v53 - 1)
                                                                                          * (float)-(float)((float)(v58[2] * v163) - (float)((float)(v58[3] * v164) + (float)((float)(*v58 * v165) + (float)(v58[1] * v166)))))
                                                                                  - (float)((float)(v53[1]
                                                                                                  * (float)-(float)((float)(v58[2] * v165) - (float)-(float)((float)(v58[1] * v164) - (float)((float)(v58[3] * v166) - (float)(*v58 * v163)))))
                                                                                          - (float)(*(v53 - 2)
                                                                                                  * (float)-(float)((float)(v58[1] * v165) - (float)((float)(v58[3] * v163) + (float)((float)(*v58 * v166) + (float)(v58[2] * v164))))))))
                                                  * v165))));
              v99 = __frsqrte((float)((float)((float)v97 * (float)v97)
                                    + (float)((float)((float)v98 * (float)v98)
                                            + (float)((float)((float)v96 * (float)v96) + (float)((float)v95 * (float)v95)))));
              v100 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v99 * (float)((float)((float)((float)v97 * (float)v97) + (float)((float)((float)v98 * (float)v98) + (float)((float)((float)v96 * (float)v96) + (float)((float)v95 * (float)v95)))) * (float)0.5))
                                                                                           * (float)v99)
                                                                                   - (float)1.5)
                                                                   * (float)v99)
                                                           * (float)((float)((float)((float)v97 * (float)v97)
                                                                           + (float)((float)((float)v98 * (float)v98)
                                                                                   + (float)((float)((float)v96 * (float)v96)
                                                                                           + (float)((float)v95 * (float)v95))))
                                                                   * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)((float)v99
                                                                                           * (float)((float)((float)((float)v97 * (float)v97) + (float)((float)((float)v98 * (float)v98) + (float)((float)((float)v96 * (float)v96) + (float)((float)v95 * (float)v95)))) * (float)0.5))
                                                                                   * (float)v99)
                                                                           - (float)1.5)
                                                           * (float)v99))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)v99
                                                                   * (float)((float)((float)((float)v97 * (float)v97)
                                                                                   + (float)((float)((float)v98 * (float)v98)
                                                                                           + (float)((float)((float)v96 * (float)v96) + (float)((float)v95 * (float)v95))))
                                                                           * (float)0.5))
                                                           * (float)v99)
                                                   - (float)1.5)
                                   * (float)v99));
              v101 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v99 * (float)((float)((float)((float)v97 * (float)v97) + (float)((float)((float)v98 * (float)v98) + (float)((float)((float)v96 * (float)v96) + (float)((float)v95 * (float)v95)))) * (float)0.5)) * (float)v99) - (float)1.5) * (float)v99)
                                                                                           * (float)((float)((float)((float)v97 * (float)v97) + (float)((float)((float)v98 * (float)v98) + (float)((float)((float)v96 * (float)v96) + (float)((float)v95 * (float)v95)))) * (float)0.5))
                                                                                   * (float)((float)-(float)((float)((float)((float)v99 * (float)((float)((float)((float)v97 * (float)v97) + (float)((float)((float)v98 * (float)v98) + (float)((float)((float)v96 * (float)v96) + (float)((float)v95 * (float)v95)))) * (float)0.5)) * (float)v99) - (float)1.5)
                                                                                           * (float)v99))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v99 * (float)((float)((float)((float)v97 * (float)v97) + (float)((float)((float)v98 * (float)v98) + (float)((float)((float)v96 * (float)v96) + (float)((float)v95 * (float)v95)))) * (float)0.5))
                                                                                           * (float)v99)
                                                                                   - (float)1.5)
                                                                   * (float)v99))
                                                   * (float)((float)((float)((float)v97 * (float)v97)
                                                                   + (float)((float)((float)v98 * (float)v98)
                                                                           + (float)((float)((float)v96 * (float)v96)
                                                                                   + (float)((float)v95 * (float)v95))))
                                                           * (float)0.5))
                                           * (float)v100)
                                   - (float)1.5);
              v102 = (float)((float)v101
                           * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v99 * (float)((float)((float)((float)v97 * (float)v97) + (float)((float)((float)v98 * (float)v98) + (float)((float)((float)v96 * (float)v96) + (float)((float)v95 * (float)v95)))) * (float)0.5)) * (float)v99)
                                                                                           - (float)1.5)
                                                                           * (float)v99)
                                                                   * (float)((float)((float)((float)v97 * (float)v97)
                                                                                   + (float)((float)((float)v98 * (float)v98)
                                                                                           + (float)((float)((float)v96 * (float)v96) + (float)((float)v95 * (float)v95))))
                                                                           * (float)0.5))
                                                           * (float)((float)-(float)((float)((float)((float)v99 * (float)((float)((float)((float)v97 * (float)v97) + (float)((float)((float)v98 * (float)v98) + (float)((float)((float)v96 * (float)v96) + (float)((float)v95 * (float)v95)))) * (float)0.5))
                                                                                           * (float)v99)
                                                                                   - (float)1.5)
                                                                   * (float)v99))
                                                   - (float)1.5)
                                   * (float)((float)-(float)((float)((float)((float)v99
                                                                           * (float)((float)((float)((float)v97 * (float)v97)
                                                                                           + (float)((float)((float)v98 * (float)v98) + (float)((float)((float)v96 * (float)v96) + (float)((float)v95 * (float)v95))))
                                                                                   * (float)0.5))
                                                                   * (float)v99)
                                                           - (float)1.5)
                                           * (float)v99)));
              *v58 = (float)v98 * (float)v102;
              v58[1] = (float)v95 * (float)v102;
              v58[2] = (float)v96 * (float)v102;
              v58[3] = (float)v102 * (float)v97;
            }
            if ( (value & 4) != 0 )
            {
              v103 = (float)(v53[3] * v59[1]);
              v104 = (float)(v53[4] * v59[2]);
              v105 = (float)(v53[5] * v59[3]);
              *v59 = v53[2] * *v59;
              v59[1] = v103;
              v59[2] = v104;
              v59[3] = v105;
            }
            if ( (value & 8) != 0 )
            {
              v106 = v167;
              v107 = (float)(*v60 * v167);
              v108 = v168;
              v109 = v169;
              v110 = (float)(v60[1] * v168);
              v111 = (float)(v60[2] * v169);
              v112 = v53[7];
              v113 = v53[8];
              v114 = v53[6];
              v115 = v171;
              v116 = v172;
              v117 = v170;
              v118 = (float)((float)(*v60 * v167) * (float)v64);
              v60[3] = 0.0;
              v119 = (float)((float)((float)v111 * (float)v62) + (float)((float)((float)v110 * (float)v65) - (float)v118));
              v120 = (float)((float)((float)((float)((float)((float)((float)v107 * (float)v62)
                                                           + (float)((float)((float)v111 * (float)v64)
                                                                   - (float)((float)v110 * (float)v63)))
                                                   * (float)v63)
                                           - (float)((float)v119 * (float)v65))
                                   * (float)2.0)
                           + (float)v112);
              v121 = (float)((float)((float)((float)((float)((float)v119 * (float)v64)
                                                   - (float)((float)((float)((float)v110 * (float)v62)
                                                                   + (float)((float)((float)v107 * (float)v63)
                                                                           - (float)((float)v111 * (float)v65)))
                                                           * (float)v63))
                                           * (float)2.0)
                                   + (float)v114)
                           + (float)v107);
              v122 = (float)((float)((float)((float)((float)((float)((float)((float)((float)v110 * (float)v62)
                                                                           + (float)((float)((float)v107 * (float)v63)
                                                                                   - (float)((float)v111 * (float)v65)))
                                                                   * (float)v65)
                                                           - (float)((float)((float)((float)v107 * (float)v62)
                                                                           + (float)((float)((float)v111 * (float)v64)
                                                                                   - (float)((float)v110 * (float)v63)))
                                                                   * (float)v64))
                                                   * (float)2.0)
                                           + (float)v113)
                                   + (float)v111)
                           + (float)v116);
              v123 = (float)((float)v121 + (float)v117);
              v124 = (float)((float)((float)((float)v120 + (float)v110) + (float)v115) - (float)v115);
              v125 = (float)((float)v123 - (float)v117);
              v127 = (float)((float)((float)v122 - (float)v116) / (float)v109);
              v126 = (float)((float)v124 / (float)v108);
              v128 = (float)((float)v125 / (float)v106);
              v129 = (float)((float)((float)v125 / (float)v106) * (float)v63);
              v131 = (float)((float)((float)((float)v125 / (float)v106) * (float)v62)
                           + (float)((float)((float)((float)v124 / (float)v108) * (float)v63)
                                   - (float)((float)v127 * (float)v64)));
              v130 = (float)((float)((float)((float)v125 / (float)v106) * (float)v64)
                           - (float)((float)((float)v124 / (float)v108) * (float)v65));
              v132 = (float)((float)((float)((float)v124 / (float)v108) * (float)v62)
                           + (float)((float)((float)v127 * (float)v65) - (float)v129));
              *v60 = (float)((float)((float)((float)v132 * (float)v63)
                                   - (float)((float)((float)((float)v127 * (float)v62) + (float)v130) * (float)v64))
                           * (float)2.0)
                   + (float)v128;
              v60[1] = (float)((float)((float)((float)((float)((float)v127 * (float)v62) + (float)v130) * (float)v65)
                                     - (float)((float)v131 * (float)v63))
                             * (float)2.0)
                     + (float)v126;
              v60[2] = (float)((float)((float)((float)v131 * (float)v64) - (float)((float)v132 * (float)v65))
                             * (float)2.0)
                     + (float)v127;
            }
          }
        }
        else if ( (value & 0x20) != 0 )
        {
          if ( (value & 2) != 0 )
          {
            v133 = *(v53 - 1);
            v134 = *v53;
            v135 = v53[1];
            *v58 = *(v53 - 2);
            v58[1] = v133;
            v58[2] = v134;
            v58[3] = v135;
          }
          if ( (value & 4) != 0 )
          {
            v136 = v53[3];
            v137 = v53[4];
            v138 = v53[5];
            *v59 = v53[2];
            v59[1] = v136;
            v59[2] = v137;
            v59[3] = v138;
          }
          if ( (value & 8) != 0 )
          {
            v139 = v53[7];
            v140 = v53[8];
            v141 = v53[9];
            *v60 = v53[6];
            v60[1] = v139;
            v60[2] = v140;
            v60[3] = v141;
          }
          if ( (value & 0x10) != 0 )
          {
            v142 = v61[1];
            v143 = v61[2];
            v144 = (float)(*(float *)&p_joint[-4].value - v61[1]);
            v145 = (float)(*(float *)&p_joint[-2].value - v61[2]);
            v146 = *(float *)&p_joint[-28].value;
            v147 = *(float *)&p_joint[-26].value;
            *v61 = (float)((float)(*(float *)&p_joint[-6].value - *v61) * *(float *)&p_joint[-30].value) + *v61;
            v61[1] = (float)((float)v144 * (float)v146) + (float)v142;
            v61[2] = (float)((float)v145 * (float)v147) + (float)v143;
          }
        }
        else
        {
          if ( (value & 2) != 0 )
          {
            v148 = (float)-(float)((float)(*v58 * *(v53 - 1))
                                 - (float)((float)(v58[3] * *v53)
                                         + (float)((float)(v58[2] * v53[1]) + (float)(v58[1] * *(v53 - 2)))));
            v149 = (float)-(float)((float)(v58[2] * *v53)
                                 - (float)-(float)((float)(v58[1] * *(v53 - 1))
                                                 - (float)((float)(v58[3] * v53[1]) - (float)(*v58 * *(v53 - 2)))));
            v150 = (float)-(float)((float)(v58[2] * *(v53 - 2))
                                 - (float)((float)(v58[3] * *(v53 - 1))
                                         + (float)((float)(*v58 * *v53) + (float)(v58[1] * v53[1]))));
            v151 = (float)-(float)((float)(v58[1] * *v53)
                                 - (float)((float)(v58[3] * *(v53 - 2))
                                         + (float)((float)(*v58 * v53[1]) + (float)(v58[2] * *(v53 - 1)))));
            v152 = __frsqrte((float)((float)((float)v151 * (float)v151)
                                   + (float)((float)((float)v150 * (float)v150)
                                           + (float)((float)((float)v149 * (float)v149)
                                                   + (float)((float)v148 * (float)v148)))));
            v153 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v152
                                                                                                 * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)v150 * (float)v150) + (float)((float)((float)v149 * (float)v149) + (float)((float)v148 * (float)v148)))) * (float)0.5))
                                                                                         * (float)v152)
                                                                                 - (float)1.5)
                                                                 * (float)v152)
                                                         * (float)((float)((float)((float)v151 * (float)v151)
                                                                         + (float)((float)((float)v150 * (float)v150)
                                                                                 + (float)((float)((float)v149
                                                                                                 * (float)v149)
                                                                                         + (float)((float)v148
                                                                                                 * (float)v148))))
                                                                 * (float)0.5))
                                                 * (float)((float)-(float)((float)((float)((float)v152
                                                                                         * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)v150 * (float)v150) + (float)((float)((float)v149 * (float)v149) + (float)((float)v148 * (float)v148))))
                                                                                                 * (float)0.5))
                                                                                 * (float)v152)
                                                                         - (float)1.5)
                                                         * (float)v152))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v152
                                                                 * (float)((float)((float)((float)v151 * (float)v151)
                                                                                 + (float)((float)((float)v150
                                                                                                 * (float)v150)
                                                                                         + (float)((float)((float)v149 * (float)v149)
                                                                                                 + (float)((float)v148 * (float)v148))))
                                                                         * (float)0.5))
                                                         * (float)v152)
                                                 - (float)1.5)
                                 * (float)v152));
            v154 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v152 * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)v150 * (float)v150) + (float)((float)((float)v149 * (float)v149) + (float)((float)v148 * (float)v148)))) * (float)0.5)) * (float)v152) - (float)1.5)
                                                                                                 * (float)v152)
                                                                                         * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)v150 * (float)v150) + (float)((float)((float)v149 * (float)v149) + (float)((float)v148 * (float)v148))))
                                                                                                 * (float)0.5))
                                                                                 * (float)((float)-(float)((float)((float)((float)v152 * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)v150 * (float)v150) + (float)((float)((float)v149 * (float)v149) + (float)((float)v148 * (float)v148)))) * (float)0.5)) * (float)v152) - (float)1.5)
                                                                                         * (float)v152))
                                                                         - (float)1.5)
                                                         * (float)((float)-(float)((float)((float)((float)v152
                                                                                                 * (float)((float)((float)((float)v151 * (float)v151) + (float)((float)((float)v150 * (float)v150) + (float)((float)((float)v149 * (float)v149) + (float)((float)v148 * (float)v148)))) * (float)0.5))
                                                                                         * (float)v152)
                                                                                 - (float)1.5)
                                                                 * (float)v152))
                                                 * (float)((float)((float)((float)v151 * (float)v151)
                                                                 + (float)((float)((float)v150 * (float)v150)
                                                                         + (float)((float)((float)v149 * (float)v149)
                                                                                 + (float)((float)v148 * (float)v148))))
                                                         * (float)0.5))
                                         * (float)v153)
                                 - (float)1.5);
            *v58 = (float)((float)v154 * (float)v153)
                 * (float)-(float)((float)(v58[1] * *v53)
                                 - (float)((float)(v58[3] * *(v53 - 2))
                                         + (float)((float)(*v58 * v53[1]) + (float)(v58[2] * *(v53 - 1)))));
            v58[1] = (float)((float)v154 * (float)v153) * (float)v150;
            v58[2] = (float)((float)v154 * (float)v153) * (float)v148;
            v58[3] = (float)((float)v154 * (float)v153) * (float)v149;
          }
          if ( (value & 4) != 0 )
          {
            v155 = (float)(v53[3] * v59[1]);
            v156 = (float)(v53[4] * v59[2]);
            v157 = (float)(v53[5] * v59[3]);
            *v59 = v53[2] * *v59;
            v59[1] = v155;
            v59[2] = v156;
            v59[3] = v157;
          }
          if ( (value & 8) != 0 )
          {
            v158 = (float)(v53[7] + v60[1]);
            v159 = (float)(v53[8] + v60[2]);
            v160 = (float)(v53[9] + v60[3]);
            *v60 = v53[6] + *v60;
            v60[1] = v158;
            v60[2] = v159;
            v60[3] = v160;
          }
          if ( (value & 0x10) != 0 )
          {
            v161 = (float)(*(float *)&p_joint[-4].value + v61[1]);
            v162 = (float)(*(float *)&p_joint[-2].value + v61[2]);
            *v61 = *(float *)&p_joint[-6].value + *v61;
            v61[1] = v161;
            v61[2] = v162;
          }
        }
      }
      v53 += 12;
      p_joint += 32;
    }
  }
}


// ========================================================================
// ?CalculatePoseBounds@idMD6Blend@@CAXPIBVidMD6SkelData@@PBMV?$idIndex@FW4invalidJointIndex_t@@@@PAUmd6OriginDelta_t@@@Z
// EA  : 0x82821390
// RVA : 0x00821390
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::CalculatePoseBounds(
        const idMD6SkelData *skeleton,
        const float *finalPose,
        const idIndex<short,enum invalidJointIndex_t> *boundsSkipJoint,
        md6OriginDelta_t *originDelta)
{
  int v7; // r10
  int numJoints; // ctr

  _R9 = -16;
  _R8 = &vmx_float_neg_infinity;
  v7 = 0;
  __asm
  {
    lvx128    v63, r8, r9
    lvx128    v62, r0, r8
    vor128    v61, v95, v63
    vor128    v59, v94, v62
    vor128    v60, v95, v63
    vor128    v58, v94, v62
  }
  if ( skeleton->numJoints != 0 )
  {
    numJoints = skeleton->numJoints;
    _R11 = finalPose + 8;
    _R8 = -32;
    do
    {
      if ( v7 != (__int16)boundsSkipJoint )
      {
        __asm
        {
          lvx128    v57, r0, r11
          lvx128    v56, r11, r8
          vminfp128 v63, v95, v57
          lvx128    v55, r11, r9
          vmaxfp128 v62, v94, v57
          vminfp128 v61, v93, v56
          vminfp128 v60, v92, v55
          vmaxfp128 v59, v91, v56
          vmaxfp128 v58, v90, v55
        }
      }
      ++v7;
      _R11 += 12;
      --numJoints;
    }
    while ( numJoints != 0 );
  }
  __asm { vspltw128 v54, v61, 3 }
  _R11 = originDelta->jointBounds;
  __asm { vspltw128 v53, v60, 3 }
  _R10 = 4;
  __asm { vspltw128 v52, v63, 3 }
  _R9 = 8;
  __asm { vspltw128 v51, v59, 3 }
  _R8 = 12;
  __asm { vspltw128 v50, v58, 3 }
  _R7 = 16;
  __asm { vspltw128 v49, v62, 3 }
  _R6 = 20;
  __asm
  {
    stvewx128 v54, r0, r11
    stvewx128 v53, r11, r10
    stvewx128 v52, r11, r9
    stvewx128 v51, r11, r8
    stvewx128 v50, r11, r7
    stvewx128 v49, r11, r6
  }
}


// ========================================================================
// ?TransformLocalJointsToModelMatrices@idMD6Blend@@SAXPIBVidMD6SkelData@@PIAXIPIBUjointMod_t@1@IIPBM_NPIBM55PIAM6@Z
// EA  : 0x82821458
// RVA : 0x00821458
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::TransformLocalJointsToModelMatrices(
        const idMD6SkelData *skeleton,
        char *temp,
        unsigned int tempSize,
        const idMD6Blend::jointMod_t *mods,
        unsigned int numMods,
        __int64 originOffset,
        bool addOffset,
        const float *inR,
        const float *inS,
        const float *inT,
        float *outMatrices,
        float *quatTemp,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        float *a27,
        int a28,
        int a29,
        int a30,
        float *a31,
        int a32,
        float *a33,
        int a34,
        float *inRa)
{
  float *v36; // r16
  bool v37; // r15
  unsigned int v38; // r22
  char *v39; // r10
  const idMD6SkelData *v40; // r17
  int v41; // ctr
  char *v42; // r14
  unsigned int v43; // r3
  char *v44; // r31
  idIndex<short,enum invalidJointIndex_t> *p_joint; // r4
  int v46; // r30
  unsigned int i; // r29
  int value; // r7
  idIndex<short,enum invalidJointIndex_t> *v49; // r11
  char *v50; // r10
  int j; // ctr
  unsigned int v52; // r11
  __int16 *v53; // r10
  int v54; // r9
  __int16 *v55; // r10
  __int16 v56; // r7
  bool v57; // zf
  char *v58; // r7
  char *v59; // r10
  char *v60; // r9
  int k; // ctr
  __int64 v62; // r6
  idIndex<short,enum invalidJointIndex_t> *v63; // r9
  int m; // ctr
  __int64 v65; // r11
  unsigned __int16 numJoints; // r9
  unsigned int v67; // r19
  double v68; // fp10
  char *v69; // r20
  double v70; // fp9
  double v71; // fp8
  double v72; // fp0
  double v73; // fp13
  double v74; // fp12
  double v75; // fp7
  double v76; // fp6
  double v77; // fp13
  double v78; // fp12
  int v79; // r30
  char *v80; // r28
  int v81; // r27
  int v82; // r31
  float *v83; // r6
  char *v84; // r29
  int v85; // r8
  int v86; // r8
  const float *v87; // r7
  const float *v88; // r6
  float *v89; // r7
  float *v90; // r8
  double v91; // fp11
  int v92; // r6
  double v93; // fp8
  float *v94; // r25
  float *v95; // r29
  double v96; // fp0
  float *v97; // r31
  double v98; // fp12
  double v99; // fp11
  double v100; // fp10
  double v101; // fp9
  float *v102; // r26
  double v103; // fp8
  __int16 v104; // r27
  double v105; // fp13
  double v106; // fp12
  double v107; // fp7
  double v108; // fp6
  double v109; // fp13
  double v110; // fp12
  double v111; // fp11
  double v112; // fp9
  double v113; // fp8
  double v114; // fp7
  __int16 v115; // r11
  double v116; // fp3
  double v117; // fp0
  __int16 v118; // r26
  double v119; // fp13
  double v120; // fp12
  double v121; // fp7
  double v122; // fp6
  unsigned __int16 v123; // r24
  unsigned int v141; // ctr
  unsigned int v156; // r27
  double v157; // fp7
  double v158; // fp6
  double v159; // fp13
  double v160; // fp12
  unsigned int v164; // r31
  char *v165; // r29
  int v166; // r11
  int v169; // r3
  int v174; // ctr
  char *v176; // r7
  int v178; // r8
  int v181; // r10
  __int16 v186; // r10
  __int16 v188; // r10
  char *v190; // [sp+50h] [-120h]
  unsigned int v191; // [sp+54h] [-11Ch]
  float v192; // [sp+60h] [-110h] BYREF
  float v193; // [sp+64h] [-10Ch]
  float v194; // [sp+68h] [-108h]
  float v195; // [sp+6Ch] [-104h]
  float v196[4]; // [sp+70h] [-100h] BYREF
  float v197[2]; // [sp+80h] [-F0h] BYREF
  char v198; // [sp+88h] [-E8h] BYREF
  char v199; // [sp+90h] [-E0h] BYREF
  float v200; // [sp+C0h] [-B0h]
  float v201; // [sp+C4h] [-ACh]
  float v202; // [sp+C8h] [-A8h]
  __int16 v203; // [sp+CCh] [-A4h]
  __int16 v204; // [sp+CEh] [-A2h]
  float *v206; // [sp+1B4h] [+44h]

  v206 = (float *)originOffset;
  v36 = (float *)originOffset;
  v37 = addOffset;
  v38 = 0;
  v39 = &v198;
  v203 = -1;
  v40 = skeleton;
  v204 = 0;
  v41 = 6;
  LODWORD(originOffset) = 0;
  do
  {
    v39 += 8;
    *(_QWORD *)v39 = originOffset;
    --v41;
  }
  while ( v41 != 0 );
  v42 = temp;
  v202 = 0.0;
  v201 = 0.0;
  v200 = 0.0;
  if ( temp == nullptr )
    v42 = &v199;
  v190 = v42;
  v43 = 0;
  if ( numMods != 0 )
  {
    v44 = v42;
    p_joint = &mods->joint;
    v46 = v42 - (char *)mods;
    for ( i = numMods; i != 0; --i )
    {
      value = (unsigned __int16)p_joint[1].value;
      if ( (value & HIDWORD(originOffset)) != 0 )
      {
        v49 = p_joint - 34;
        v50 = v44 - 8;
        for ( j = 8; j != 0; --j )
        {
          v49 += 4;
          originOffset = *(_QWORD *)&v49->value;
          v50 += 8;
          *(_QWORD *)v50 = *(_QWORD *)&v49->value;
        }
        v52 = 0;
        if ( v43 != 0 )
        {
          v53 = (__int16 *)(v42 + 60);
          v54 = p_joint->value;
          while ( v54 > *v53 )
          {
            ++v52;
            v53 += 32;
            if ( v52 >= v43 )
              goto LABEL_29;
          }
          v55 = (__int16 *)&v42[64 * v52 + 60];
          v57 = (value & 1) != 0;
          v56 = *v55;
          if ( v57 )
          {
            if ( v54 == v56 )
            {
              do
              {
                v55 += 32;
                ++v52;
              }
              while ( v54 == *v55 );
            }
          }
          else if ( v54 == v56 )
          {
            do
            {
              if ( (*(__int16 *)((_BYTE *)&p_joint[1].value + v46) & 1) != 0 )
                break;
              v55 += 32;
              ++v52;
            }
            while ( v54 == *v55 );
          }
          if ( v43 > v52 )
          {
            v58 = v44;
            do
            {
              v59 = v58 - 72;
              v60 = v58 - 8;
              for ( k = 8; k != 0; --k )
              {
                v59 += 8;
                v62 = *(_QWORD *)v59;
                v60 += 8;
                *(_QWORD *)v60 = *(_QWORD *)v59;
              }
              v58 -= 64;
            }
            while ( HIDWORD(v62) != 1 );
          }
          v63 = p_joint - 34;
          for ( m = 8; m != 0; --m )
          {
            v63 += 4;
            v65 = *(_QWORD *)&v63->value;
            HIDWORD(v65) = *(_DWORD *)&v63->value + 8;
            *(_QWORD *)HIDWORD(v65) = v65;
          }
        }
LABEL_29:
        ++v43;
        v44 += 64;
      }
      p_joint += 32;
    }
  }
  numJoints = v40->numJoints;
  v67 = v43 + 1;
  v191 = v43 + 1;
  *(_WORD *)&v42[64 * v43 + 60] = numJoints;
  if ( inRa != nullptr )
  {
    v68 = a27[1];
    v69 = (char *)v40 + v40->parentTblOffset;
    v70 = a27[2];
    v71 = a27[3];
    v72 = *a31;
    v73 = a31[1];
    v74 = a31[2];
    *inRa = *a27;
    inRa[1] = v68;
    inRa[2] = v70;
    inRa[3] = v71;
    inRa[4] = v72;
    inRa[5] = v73;
    inRa[6] = v74;
    inRa[7] = 0.0;
    if ( v37 )
    {
      v75 = (float)(v36[1] + (float)v73);
      v76 = (float)(v36[2] + (float)v74);
      inRa[4] = *v36 + (float)v72;
      inRa[5] = v75;
      inRa[6] = v76;
    }
    else
    {
      v77 = v36[1];
      v78 = v36[2];
      inRa[4] = *v36;
      inRa[5] = v77;
      inRa[6] = v78;
    }
    v79 = 1;
    if ( v43 != -1 )
    {
      v80 = v42;
      v81 = *((__int16 *)v42 + 30);
      do
      {
        if ( v79 < v81 )
        {
          v82 = v81 - v79;
          v83 = &a31[4 * v79];
          v84 = &v69[2 * v79 - 2];
          v85 = (int)&inRa[8 * v79 + 6];
          v79 = v81;
          do
          {
            v84 += 2;
            _idMD6Blend::TransformLocalJointsToModelMatrices_::_30_::local_t::QuatMult(
              a: (float *)((char *)v83 + (char *)a27 - (char *)a31),
              b: &inRa[8 * *(__int16 *)v84],
              out: (float *)(v85 - 24));
            _idMD6Blend::TransformLocalJointsToModelMatrices_::_30_::local_t::RotateVector(
              quat: v87,
              vec: v88,
              out: (float *)(v86 - 8));
            --v82;
            v91 = *(v90 - 1);
            *(v90 - 2) = v89[4] + *(v90 - 2);
            v83 = (float *)(v92 + 16);
            v93 = *v90;
            *(v90 - 1) = (float)v91 + v89[5];
            *v90 = v89[6] + (float)v93;
            v90[1] = 0.0;
            v85 = (int)(v90 + 8);
          }
          while ( v82 != 0 );
        }
        if ( v79 >= v40->numJoints )
          break;
        v94 = &a27[4 * v79];
        v95 = &inRa[8 * v79];
        v96 = a31[4 * v79];
        v97 = v95 + 4;
        v98 = v94[1];
        v99 = v94[2];
        v100 = v94[3];
        v101 = a31[4 * v79 + 1];
        v102 = &inRa[8 * *(__int16 *)&v69[2 * v79]];
        v103 = a31[4 * v79 + 2];
        *v95 = *v94;
        v95[1] = v98;
        v95[2] = v99;
        v95[3] = v100;
        v95[4] = v96;
        v95[5] = v101;
        v95[6] = v103;
        v95[7] = 0.0;
        if ( v81 == v79 )
        {
          do
          {
            v104 = *((_WORD *)v80 + 31);
            if ( (v104 & 1) != 0 )
              break;
            if ( (v104 & 0x20) != 0 )
            {
              if ( (v104 & 2) != 0 )
                _idMD6Blend::TransformLocalJointsToModelMatrices_::_30_::local_t::QuatFromMat(
                  res: &inRa[8 * v79],
                  mat: (const float *)v80);
              if ( (v104 & 8) != 0 )
              {
                v105 = *((float *)v80 + 7);
                v106 = *((float *)v80 + 11);
                *v97 = *((float *)v80 + 3);
                v95[5] = v105;
                v95[6] = v106;
              }
            }
            else
            {
              if ( (v104 & 2) != 0 )
              {
                _idMD6Blend::TransformLocalJointsToModelMatrices_::_30_::local_t::QuatFromMat(
                  res: v196,
                  mat: (const float *)v80);
                _idMD6Blend::TransformLocalJointsToModelMatrices_::_30_::local_t::QuatMult(
                  a: &a27[4 * v79],
                  b: v196,
                  out: &inRa[8 * v79]);
              }
              if ( (v104 & 8) != 0 )
              {
                v107 = (float)(*((float *)v80 + 7) + v95[5]);
                v108 = (float)(*((float *)v80 + 11) + v95[6]);
                *v97 = *((float *)v80 + 3) + *v97;
                v95[5] = v107;
                v95[6] = v108;
              }
            }
            v80 = &v42[64 * ++v38];
          }
          while ( *((__int16 *)v80 + 30) == v79 );
        }
        v109 = v95[1];
        v110 = v95[2];
        v111 = v95[3];
        v192 = *v95;
        v193 = v109;
        v194 = v110;
        v195 = v111;
        _idMD6Blend::TransformLocalJointsToModelMatrices_::_30_::local_t::QuatMult(
          a: &v192,
          b: v102,
          out: &inRa[8 * v79]);
        v112 = v95[5];
        v113 = v95[6];
        v114 = v95[7];
        v192 = *v97;
        v193 = v112;
        v194 = v113;
        v195 = v114;
        _idMD6Blend::TransformLocalJointsToModelMatrices_::_30_::local_t::RotateVector(
          quat: v102,
          vec: &v192,
          out: v95 + 4);
        v115 = *((_WORD *)v80 + 30);
        v116 = v95[5];
        *v97 = *v97 + v102[4];
        v81 = v115;
        v117 = v95[6];
        v95[5] = v102[5] + (float)v116;
        v95[6] = v102[6] + (float)v117;
        for ( v95[7] = 0.0; v81 == v79; v81 = *((__int16 *)v80 + 30) )
        {
          v118 = *((_WORD *)v80 + 31);
          if ( (v118 & 1) == 0 )
            break;
          if ( (v118 & 0x20) != 0 )
          {
            if ( (v118 & 2) != 0 )
              _idMD6Blend::TransformLocalJointsToModelMatrices_::_30_::local_t::QuatFromMat(
                res: &inRa[8 * v79],
                mat: (const float *)v80);
            if ( (v118 & 8) != 0 )
            {
              v119 = *((float *)v80 + 7);
              v120 = *((float *)v80 + 11);
              *v97 = *((float *)v80 + 3);
              v95[5] = v119;
              v95[6] = v120;
            }
          }
          else
          {
            if ( (v118 & 2) != 0 )
            {
              _idMD6Blend::TransformLocalJointsToModelMatrices_::_30_::local_t::QuatFromMat(
                res: v197,
                mat: (const float *)v80);
              _idMD6Blend::TransformLocalJointsToModelMatrices_::_30_::local_t::QuatMult(
                a: &a27[4 * v79],
                b: v197,
                out: &inRa[8 * v79]);
            }
            if ( (v118 & 8) != 0 )
            {
              v121 = (float)(*((float *)v80 + 7) + v95[5]);
              v122 = (float)(*((float *)v80 + 11) + v95[6]);
              *v97 = *((float *)v80 + 3) + *v97;
              v95[5] = v121;
              v95[6] = v122;
            }
          }
          v80 = &v42[64 * ++v38];
        }
        ++v79;
      }
      while ( v38 < v67 );
    }
  }
  v123 = v40->numJoints;
  _R22 = a33;
  _R19 = -32;
  _R18 = -16;
  _R4 = 16;
  _R20 = 32;
  _R8 = &vmx_float_rsqrt_c1_2;
  if ( ((v123 + 7) & 0xFFF8) != 0 )
  {
    _R31 = -160;
    _R30 = -96;
    _R29 = -80;
    _R28 = -544;
    __asm { lvx128    v63, r8, r31 }
    _R27 = -528;
    __asm
    {
      lvx128    v0, r8, r30
      lvx128    v13, r8, r29
    }
    _R26 = -512;
    __asm { lvx128    v7, r8, r28 }
    _R31 = -496;
    _R30 = -480;
    __asm { lvx128    v6, r8, r27 }
    _R29 = -64;
    _R28 = -48;
    __asm { lvx128    v5, r8, r26 }
    _R9 = a31 + 12;
    v141 = ((((v40->numJoints + 7) & 0xFFF8u) - 1) >> 2) + 1;
    _R7 = (char *)a31 - (char *)a27;
    __asm { lvx128    v4, r8, r31 }
    _R23 = -32;
    __asm
    {
      lvx128    v3, r8, r30
      lvx128    v12, r8, r29
    }
    _R11 = a33 + 8;
    __asm { lvx128    v11, r8, r28 }
    _R10 = a27 + 8;
    _R6 = -32;
    _R5 = -16;
    __asm { lvx128    v10, r8, r23 }
    _R3 = -48;
    _R25 = 48;
    _R26 = 64;
    _R27 = 80;
    _R28 = 96;
    _R29 = 112;
    _R30 = 128;
    _R31 = 144;
    do
    {
      __asm
      {
        lvx128    v2, r10, r6
        vaddfp128 v61, v2, v2
        lvx128    v60, r10, r5
        vaddfp128 v58, v92, v60
        lvx128    v1, r0, r10
        vpermwi128 v57, v2, 0x41 # 'A'
        lvx128    v56, r10, r4
        vaddfp128 v59, v1, v1
        vpermwi128 v53, v60, 0x41 # 'A'
        vaddfp128 v55, v88, v56
        vpermwi128 v18, v2, 0xBF
        vpermwi128 v54, v1, 0x41 # 'A'
        vor128    v30, v92, v60
        vxor128   v28, v89, v63
        vpermwi128 v52, v56, 0x41 # 'A'
        vxor128   v20, v85, v63
        vpermwi128 v19, v60, 0xBF
        vor128    v8, v88, v56
        vpermwi128 v21, v1, 0xBF
        vxor128   v22, v86, v63
        vpermwi128 v23, v56, 0xBF
        vxor128   v24, v84, v63
        lvx128    v62, r9, r3
        lvx128    v60, r7, r10
      }
      _R10 += 16;
      __asm
      {
        vpermwi128 v29, v61, 0x5A # 'Z'
        vor128    v9, v93, v61
        vpermwi128 v26, v61, 0xA4
        vor128    v31, v90, v58
        vpermwi128 v27, v58, 0x5A # 'Z'
        lvx128    v61, r9, r19
        vmaddfp   v25, v28, v0, v29
        vpermwi128 v28, v59, 0x5A # 'Z'
        vnmsubfp  v16, v2, v0, v9
        vor128    v2, v91, v59
        vmaddfp   v26, v18, v13, v26
        vpermwi128 v29, v55, 0x5A # 'Z'
        vmaddfp   v27, v20, v0, v27
        vpermwi128 v20, v58, 0xA4
        vnmsubfp  v17, v30, v0, v31
        vor128    v9, v87, v55
        vnmsubfp  v30, v1, v0, v2
        vmaddfp   v28, v22, v0, v28
        vpermwi128 v22, v59, 0xA4
        vmaddfp   v29, v24, v0, v29
        vpermwi128 v24, v55, 0xA4
        vmaddfp   v2, v19, v13, v20
        lvx128    v59, r0, r9
        vnmsubfp  v18, v8, v0, v9
      }
      _R9 += 16;
      __asm
      {
        vmaddfp   v8, v21, v13, v22
        vmaddfp   v9, v23, v13, v24
        vperm     v1, v25, v16, v7
        vmaddfp   v22, v26, v25, v12
        vperm     v25, v25, v26, v6
        vperm     v31, v27, v17, v7
        vmaddfp   v23, v26, v1, v11
        vperm     v30, v28, v30, v7
        vmaddfp   v25, v25, v1, v10
        vmaddfp   v20, v2, v27, v12
        vperm     v26, v27, v2, v6
        vmaddfp   v21, v2, v31, v11
        vperm     v24, v29, v18, v7
        vperm     v27, v28, v8, v6
        vperm     v2, v29, v9, v6
        vmaddfp   v1, v9, v29, v12
        vperm128  v51, v22, v62, v5
        vmaddfp   v22, v8, v28, v12
        vmaddfp   v28, v26, v31, v10
        vmaddfp   v31, v27, v30, v10
        vperm128  v50, v23, v62, v4
        vmaddfp   v23, v8, v30, v11
        vmaddfp   v8, v9, v24, v11
        vmaddfp   v9, v2, v24, v10
        vperm128  v49, v20, v61, v5
        stvx128   v51, r11, r19
        vperm128  v48, v21, v61, v4
        stvx128   v50, r11, r18
        vperm128  v47, v22, v60, v5
        stvx128   v49, r11, r4
        vperm128  v46, v23, v60, v4
        vperm128  v45, v25, v62, v3
        stvx128   v48, r11, r20
        vperm128  v44, v28, v61, v3
        stvx128   v47, r11, r26
        vperm128  v43, v31, v60, v3
        stvx128   v46, r11, r27
        vperm128  v42, v1, v59, v5
        vperm128  v41, v8, v59, v4
        vperm128  v40, v9, v59, v3
        stvx128   v45, r0, r11
        stvx128   v44, r11, r25
        stvx128   v43, r11, r28
        stvx128   v42, r11, r29
        stvx128   v41, r11, r30
        stvx128   v40, r11, r31
      }
      _R11 += 48;
      --v141;
    }
    while ( v141 != 0 );
    v42 = v190;
    v40 = skeleton;
    v36 = v206;
    v37 = addOffset;
  }
  v156 = v191;
  if ( v37 )
  {
    v157 = (float)(v36[1] + a33[7]);
    v158 = (float)(v36[2] + a33[11]);
    a33[3] = *v36 + a33[3];
    a33[7] = v157;
    a33[11] = v158;
  }
  else
  {
    v159 = v36[1];
    v160 = v36[2];
    a33[3] = *v36;
    a33[7] = v159;
    a33[11] = v160;
  }
  _R30 = a29;
  _R10 = -336;
  _R9 = -112;
  __asm { lvx128    v39, r0, r22 }
  v164 = 0;
  __asm { lvx128    v38, r22, r4 }
  v165 = (char *)v40 + v40->parentTblOffset;
  __asm { lvx128    v37, r22, r20 }
  v166 = 1;
  __asm { lvx128    v36, r0, r30 }
  __asm
  {
    lvx128    v12, r8, r10
    vspltw128 v35, v36, 0
    lvx128    v58, r8, r9
    vspltw128 v34, v36, 1
    vspltw128 v33, v36, 2
    vand128   v32, v67, v12
    vand128   v63, v66, v12
    vand128   v62, v65, v12
    vor128    v61, v64, v58
    vor128    v60, v95, v58
    vor128    v59, v94, v58
    vmulfp128 v63, v71, v61
    vmulfp128 v0, v70, v60
    vmulfp128 v13, v69, v59
  }
  if ( v156 != 0 )
  {
    _R7 = -352;
    _R5 = -144;
    __asm { lvx128    v53, r0, r8 }
    v169 = *((__int16 *)v42 + 30);
    _R26 = -16;
    _R6 = &vmx_float_smallest_non_denorm_0;
    __asm { lvx128    v9, r8, r7 }
    _R10 = -128;
    __asm { lvx128    v56, r8, r5 }
    _R9 = v42;
    __asm
    {
      lvx128    v27, r8, r26
      lvx128    v54, r0, r6
      lvx128    v55, r8, r10
    }
    do
    {
      if ( v166 < v169 )
      {
        v174 = v169 - v166;
        _R6 = 16 * v166 + a29;
        v176 = &v165[2 * v166];
        _R10 = (int)&a33[12 * v166 + 8];
        do
        {
          v178 = *(__int16 *)v176;
          v57 = v178 == v166 - 1;
          _R8 = &a33[12 * v178];
          if ( !v57 )
          {
            __asm
            {
              lvx128    v63, r0, r8
              lvx128    v0, r8, r4
              lvx128    v13, r8, r20
            }
          }
          __asm
          {
            lvx128    v57, r0, r6
            vand      v1, v0, v9
            lvx128    v52, r10, r19
            vspltw    v31, v0, 0
            vspltw128 v51, v57, 0
            vand128   v30, v95, v9
            vspltw128 v50, v57, 1
            vand      v3, v13, v9
            vspltw    v5, v0, 1
            lvx128    v49, r10, r18
            vspltw    v8, v0, 2
            lvx128    v48, r0, r10
            vand128   v47, v83, v12
            vspltw128 v46, v57, 2
            vand128   v45, v82, v12
            vspltw128 v29, v63, 0
            vspltw    v2, v13, 0
          }
          ++v166;
          __asm { vspltw    v6, v13, 1 }
          v176 += 2;
          __asm
          {
            vor128    v44, v79, v58
            vspltw    v10, v13, 2
            vor128    v43, v77, v58
            vspltw128 v4, v63, 1
            vand128   v42, v78, v12
            vspltw128 v7, v63, 2
          }
          _R6 += 16;
          __asm
          {
            vmulfp128 v0, v84, v44
            vmulfp128 v13, v81, v43
            vor128    v41, v74, v58
            vmulfp128 v11, v80, v41
            vmaddfp   v30, v29, v30, v0
            vmaddfp   v1, v31, v1, v0
            vmaddfp   v3, v2, v3, v0
            vmr128    v63, v11
            vmaddfp   v4, v4, v30, v13
            vmaddfp   v0, v5, v1, v13
            vmaddfp   v13, v6, v3, v13
            vmaddcfp128 v63, v7, v63, v4
            vmaddfp   v0, v8, v0, v11
            vmaddfp   v13, v10, v13, v11
            stvx128   v63, r10, r19
            stvx128   v0, r10, r18
            stvx128   v13, r0, r10
          }
          _R10 += 48;
          --v174;
        }
        while ( v174 != 0 );
      }
      if ( v166 >= v123 )
        break;
      _R8 = 16 * v166 + a29;
      v181 = *(__int16 *)&v165[2 * v166];
      _R6 = &a33[12 * v166];
      __asm { lvx128    v57, r0, r8 }
      _R5 = _R6 + 4;
      _R7 = _R6 + 8;
      __asm { lvx128    v62, r0, r6 }
      __asm { lvx128    v11, r0, r5 }
      __asm { lvx128    v10, r0, r7 }
      v57 = v181 == v166 - 1;
      _R10 = &a33[12 * v181];
      if ( !v57 )
      {
        __asm
        {
          lvx128    v63, r0, r10
          lvx128    v0, r10, r4
          lvx128    v13, r10, r20
        }
      }
      if ( v169 == v166 )
      {
        do
        {
          v186 = *((_WORD *)_R9 + 31);
          if ( (v186 & 1) != 0 )
            break;
          __asm
          {
            lvx128    v61, r0, r9
            lvx128    v60, r9, r4
          }
          _R8 = _R9 + 48;
          __asm { lvx128    v59, r9, r20 }
          if ( (v186 & 0x20) != 0 )
          {
            if ( (v186 & 2) != 0 )
            {
              __asm
              {
                vor128    v5, v94, v62
                vor128    v6, v93, v61
                vmr128    v62, v12
                vor128    v7, v92, v60
                vor128    v8, v91, v59
                vsel128   v62, v5, v6, v62
                vsel      v11, v11, v7, v12
                vsel      v10, v10, v8, v12
              }
            }
            if ( (v186 & 8) != 0 )
            {
              __asm
              {
                vor128    v8, v94, v62
                vmr128    v62, v9
                vmr       v7, v9
                vsel128   v62, v8, v61, v62
                vmr       v8, v9
                vsel128   v7, v11, v60, v7
                vsel128   v8, v10, v59, v8
                vmr       v11, v7
                vmr       v10, v8
              }
            }
            if ( (v186 & 4) != 0 )
            {
              __asm
              {
                lvx128    v40, r0, r8
                vand128   v39, v72, v12
                vor128    v57, v71, v58
              }
            }
          }
          else
          {
            if ( (v186 & 2) != 0 )
            {
              __asm
              {
                vspltw128 v38, v60, 0
                vmr       v6, v11
                vspltw128 v37, v59, 0
                vor128    v5, v94, v62
                vspltw128 v36, v61, 0
                vspltw128 v28, v60, 1
                vmulfp128 v29, v70, v62
                vspltw128 v30, v59, 1
                vmulfp128 v31, v69, v62
                vspltw128 v1, v61, 1
                vmulfp128 v2, v68, v62
                vspltw128 v4, v61, 2
                vspltw128 v3, v60, 2
                vmr128    v62, v12
                vspltw128 v8, v59, 2
                vmaddfp   v29, v28, v29, v11
                vmaddfp   v31, v30, v31, v11
                vmaddfp   v11, v1, v2, v11
                vmaddfp   v3, v3, v29, v10
                vmaddfp   v8, v8, v31, v10
                vmaddfp   v11, v4, v11, v10
                vsel      v10, v10, v8, v12
                vsel128   v62, v5, v11, v62
                vsel      v11, v6, v3, v12
              }
            }
            if ( (v186 & 8) != 0 )
            {
              __asm
              {
                vand128   v35, v93, v9
                vand128   v34, v92, v9
                vand128   v33, v91, v9
                vaddfp128 v62, v94, v35
                vaddfp128 v11, v11, v34
                vaddfp128 v10, v10, v33
              }
            }
            if ( (v186 & 4) != 0 )
            {
              __asm
              {
                lvx128    v32, r0, r8
                vand128   v61, v64, v12
                vor128    v60, v93, v58
                vmulfp128 v57, v89, v60
              }
            }
          }
          _R9 = &v42[64 * ++v164];
        }
        while ( *((__int16 *)_R9 + 30) == v166 );
      }
      __asm
      {
        vspltw128 v59, v57, 0
        vand      v31, v0, v9
        vspltw128 v52, v57, 1
        vand128   v29, v95, v9
        vspltw128 v51, v57, 2
        vand      v2, v13, v9
        vspltw    v30, v0, 0
      }
      __asm
      {
        vand128   v50, v91, v12
        vspltw    v4, v0, 1
        vspltw    v7, v0, 2
        vand128   v49, v84, v12
        vand128   v48, v83, v12
        vspltw128 v28, v63, 0
        vspltw    v1, v13, 0
      }
      v169 = *((__int16 *)_R9 + 30);
      __asm
      {
        vor128    v47, v82, v58
        vspltw    v5, v13, 1
        vor128    v46, v81, v58
        vspltw    v8, v13, 2
        vor128    v45, v80, v58
        vspltw128 v3, v63, 1
        vspltw128 v6, v63, 2
      }
      __asm
      {
        vmulfp128 v0, v94, v47
        vmulfp128 v13, v11, v46
        vmulfp128 v11, v10, v45
        vmaddfp   v10, v28, v29, v0
        vmaddfp   v31, v30, v31, v0
        vmaddfp   v2, v1, v2, v0
        vmr128    v63, v11
        vmaddfp   v10, v3, v10, v13
        vmaddfp   v0, v4, v31, v13
        vmaddfp   v13, v5, v2, v13
        vmaddcfp128 v63, v6, v63, v10
        vmaddfp   v0, v7, v0, v11
        vmaddfp   v13, v8, v13, v11
      }
      for ( ; v169 == v166; v169 = *((__int16 *)_R9 + 30) )
      {
        v188 = *((_WORD *)_R9 + 31);
        if ( (v188 & 1) == 0 )
          break;
        __asm
        {
          lvx128    v62, r0, r9
          lvx128    v61, r9, r4
        }
        _R8 = _R9 + 48;
        __asm { lvx128    v60, r9, r20 }
        if ( (v188 & 0x20) != 0 )
        {
          if ( (v188 & 2) != 0 )
          {
            __asm
            {
              vor128    v7, v95, v63
              vor128    v8, v94, v62
              vmr128    v63, v12
              vor128    v10, v93, v61
              vor128    v11, v92, v60
              vsel128   v63, v7, v8, v63
              vsel      v0, v0, v10, v12
              vsel      v13, v13, v11, v12
            }
          }
          if ( (v188 & 8) != 0 )
          {
            __asm
            {
              vor128    v11, v95, v63
              vmr128    v63, v9
              vmr       v10, v9
              vsel128   v63, v11, v62, v63
              vmr       v11, v9
              vsel128   v10, v0, v61, v10
              vsel128   v11, v13, v60, v11
              vmr       v0, v10
              vmr       v13, v11
            }
          }
          if ( (v188 & 4) != 0 )
          {
            __asm
            {
              vmulfp128 v44, v95, v63
              vor128    v10, v87, v55
              vmulfp128 v43, v0, v0
              lvx128    v42, r0, r8
              vmulfp128 v41, v13, v13
              vmrghw128 v40, v75, v56
              vmrghw128 v39, v76, v41
              vmrglw128 v38, v76, v41
              vmrglw128 v37, v75, v56
              vmrglw128 v36, v71, v40
              vmrghw128 v35, v71, v40
              vmrghw128 v34, v70, v37
              vaddfp128 v33, v68, v34
              vaddfp128 v11, v67, v33
              vcmpgtfp128 v8, v11, v54
              vsel      v8, v10, v11, v8
              vrsqrtefp128 v32, v8
              vmulfp128 v11, v64, v32
              vmulfp128 v62, v64, v53
              vmaddfp   v11, v8, v27, v11
              vmulfp128 v61, v94, v11
              vmulfp128 v60, v74, v61
              vspltw128 v59, v60, 0
              vspltw128 v57, v60, 1
              vspltw128 v52, v60, 2
              vand128   v51, v91, v12
              vand128   v50, v89, v12
              vand128   v49, v84, v12
              vor128    v48, v83, v58
              vor128    v47, v82, v58
              vor128    v46, v81, v58
              vmulfp128 v63, v95, v48
              vmulfp128 v0, v0, v47
              vmulfp128 v13, v13, v46
            }
          }
        }
        else
        {
          if ( (v188 & 2) != 0 )
          {
            __asm
            {
              vspltw128 v45, v61, 0
              vmr       v8, v0
              vspltw128 v44, v60, 0
              vor128    v7, v95, v63
              vspltw128 v43, v62, 0
              vspltw128 v30, v61, 1
              vmulfp128 v31, v77, v63
              vspltw128 v1, v60, 1
              vmulfp128 v2, v76, v63
              vspltw128 v3, v62, 1
              vmulfp128 v4, v75, v63
              vspltw128 v6, v62, 2
              vspltw128 v5, v61, 2
              vmr128    v63, v12
              vspltw128 v11, v60, 2
              vmaddfp   v31, v30, v31, v0
              vmaddfp   v2, v1, v2, v0
              vmaddfp   v0, v3, v4, v0
              vmaddfp   v5, v5, v31, v13
              vmaddfp   v11, v11, v2, v13
              vmaddfp   v0, v6, v0, v13
              vsel      v13, v13, v11, v12
              vsel128   v63, v7, v0, v63
              vsel      v0, v8, v5, v12
            }
          }
          if ( (v188 & 8) != 0 )
          {
            __asm
            {
              vand128   v42, v94, v9
              vand128   v41, v93, v9
              vand128   v40, v92, v9
              vaddfp128 v63, v95, v42
              vaddfp128 v0, v0, v41
              vaddfp128 v13, v13, v40
            }
          }
          if ( (v188 & 4) != 0 )
          {
            __asm
            {
              lvx128    v39, r0, r8
              vspltw128 v38, v39, 0
              vspltw128 v37, v39, 1
              vspltw128 v36, v39, 2
              vand128   v35, v70, v12
              vand128   v34, v69, v12
              vand128   v33, v68, v12
              vor128    v32, v67, v58
              vor128    v62, v66, v58
              vor128    v61, v65, v58
              vmulfp128 v63, v95, v32
              vmulfp128 v0, v0, v62
              vmulfp128 v13, v13, v61
            }
          }
        }
        _R9 = &v42[64 * ++v164];
      }
      __asm { stvx128   v63, r0, r6 }
      ++v166;
      __asm { stvx128   v0, r0, r5 }
      __asm { stvx128   v13, r0, r7 }
    }
    while ( v164 < v156 );
  }
}


// ========================================================================
// ?DecodeBasePose@idMD6Blend@@SAXPIBVidMD6SkelData@@PIAXIPIBM_NPIAM@Z
// EA  : 0x828223C8
// RVA : 0x008223C8
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::DecodeBasePose(
        const idMD6SkelData *skeleton,
        const float *temp,
        const unsigned int tempSize,
        const float *originOffset,
        unsigned int offsetAdd,
        float *outPose)
{
  float *basePoseOffset; // r10
  __int16 v9; // r8
  unsigned int v13; // r3
  float *v14; // r27
  float *v15; // r26
  const float *v16; // r29
  __int64 v17; // r6
  char *v18; // r28
  unsigned int v24; // ctr
  bool v25; // [sp+Bh] [-C5h]
  const float *v26; // [sp+Ch] [-C4h]
  const float *v27; // [sp+10h] [-C0h]
  const float *v28; // [sp+14h] [-BCh]
  float *v29; // [sp+18h] [-B8h]
  float *v30; // [sp+1Ch] [-B4h]
  int v31; // [sp+20h] [-B0h]
  int v32; // [sp+24h] [-ACh]
  int v33; // [sp+28h] [-A8h]
  int v34; // [sp+2Ch] [-A4h]
  int v35; // [sp+30h] [-A0h]
  int v36; // [sp+34h] [-9Ch]
  int v37; // [sp+38h] [-98h]
  int v38; // [sp+3Ch] [-94h]
  int v39; // [sp+40h] [-90h]
  int v40; // [sp+44h] [-8Ch]
  int v41; // [sp+48h] [-88h]
  int v42; // [sp+4Ch] [-84h]
  int v43; // [sp+50h] [-80h]
  float *v44; // [sp+58h] [-78h]
  int v45; // [sp+60h] [-70h]
  float *v46; // [sp+68h] [-68h]
  float *v47; // [sp+70h] [-60h]
  float *v48; // [sp+78h] [-58h]

  basePoseOffset = (float *)skeleton->basePoseOffset;
  v9 = skeleton->numJoints + 7;
  v13 = v9 & 0xFFF8;
  v14 = (float *)&temp[4 * v13 + 4];
  v15 = (float *)&temp[8 * v13 + 8];
  v16 = &temp[12 * v13 + 12];
  LODWORD(v17) = (char *)&basePoseOffset[7 * v13] + (_DWORD)skeleton;
  HIDWORD(v17) = (char *)&basePoseOffset[4 * v13] + (_DWORD)skeleton;
  v18 = (char *)&basePoseOffset[10 * v13] + (_DWORD)skeleton;
  idMD6Blend::DecodeBasePoseRST(numJoints: v13, inS: v17, inT: temp, outR: v14, outS: v15, outT: basePoseOffset);
  if ( ((skeleton->numUserChannels + 7) & 0xFFF8) != 0 )
  {
    _R10 = v18;
    _R11 = (char *)(v16 + 4);
    _R7 = -16;
    v24 = ((((skeleton->numUserChannels + 7) & 0xFFF8u) - 1) >> 3) + 1;
    _R8 = v18 - (char *)v16;
    do
    {
      __asm { lvx128    v63, r0, r10 }
      _R10 += 32;
      __asm
      {
        lvx128    v62, r8, r11
        stvx128   v63, r11, r7
        stvx128   v62, r0, r11
      }
      _R11 += 32;
      --v24;
    }
    while ( v24 != 0 );
  }
  idMD6Blend::TransformLocalJointsToModelMatrices(
    skeleton,
    temp: nullptr,
    tempSize: 0,
    mods: nullptr,
    numMods: 0,
    originOffset: __SPAIR64__((unsigned int)originOffset, offsetAdd),
    addOffset: v25,
    inR: v26,
    inS: v27,
    inT: v28,
    outMatrices: v29,
    quatTemp: v30,
    a13: v31,
    a14: v32,
    a15: v33,
    a16: v34,
    a17: v35,
    a18: v36,
    a19: v37,
    a20: v38,
    a21: v39,
    a22: v40,
    a23: v41,
    a24: v42,
    a25: v43,
    a26: (int)temp,
    a27: v44,
    a28: (int)v14,
    a29: v45,
    a30: (int)v15,
    a31: v46,
    a32: (int)outPose,
    a33: v47,
    a34: 0,
    inRa: v48);
}


// ========================================================================
// ?DecodeSingleFrame@idMD6Blend@@SAXPIBVidMD6SkelData@@PIAXIPIBVidMD6AnimData@@HH_NPIBM_NPIAM6@Z
// EA  : 0x82822508
// RVA : 0x00822508
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMD6Blend::DecodeSingleFrame(
        const idMD6SkelData *skeleton,
        float *temp,
        unsigned int tempSize,
        const idMD6AnimData *animData,
        __int64 ticksPerSec,
        const bool clearOriginTransform,
        const float *originOffset,
        bool offsetAdd,
        float *outPose,
        float *outUserChannels,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        unsigned __int8 a27,
        int a28,
        int a29,
        int a30,
        void *a31)
{
  __int64 v33; // r10 OVERLAPPED
  double v37; // fp13
  double v38; // fp0
  __int64 v39; // r10
  __int64 v40; // r11
  float *v41; // r8
  int v42; // r6
  int v43; // r10
  float *v44; // r27
  const frameSetData_t *v45; // r6
  float *v46; // r29
  float *v47; // r26
  __int64 v48; // r10
  float *v49; // [sp+8h] [-F8h]
  bool v50; // [sp+Bh] [-F5h]
  int v51; // [sp+Ch] [-F4h]
  const float *v52; // [sp+Ch] [-F4h]
  int v53; // [sp+10h] [-F0h]
  const float *v54; // [sp+10h] [-F0h]
  int v55; // [sp+14h] [-ECh]
  const float *v56; // [sp+14h] [-ECh]
  int v57; // [sp+18h] [-E8h]
  float *v58; // [sp+18h] [-E8h]
  int v59; // [sp+1Ch] [-E4h]
  float *v60; // [sp+1Ch] [-E4h]
  int v61; // [sp+20h] [-E0h]
  int v62; // [sp+20h] [-E0h]
  int v63; // [sp+24h] [-DCh]
  int v64; // [sp+24h] [-DCh]
  int v65; // [sp+28h] [-D8h]
  int v66; // [sp+28h] [-D8h]
  int v67; // [sp+2Ch] [-D4h]
  int v68; // [sp+2Ch] [-D4h]
  int v69; // [sp+30h] [-D0h]
  int v70; // [sp+30h] [-D0h]
  int v71; // [sp+34h] [-CCh]
  int v72; // [sp+34h] [-CCh]
  int v73; // [sp+38h] [-C8h]
  int v74; // [sp+38h] [-C8h]
  int v75; // [sp+3Ch] [-C4h]
  int v76; // [sp+3Ch] [-C4h]
  int v77; // [sp+40h] [-C0h]
  int v78; // [sp+40h] [-C0h]
  int v79; // [sp+44h] [-BCh]
  int v80; // [sp+44h] [-BCh]
  int v81; // [sp+48h] [-B8h]
  int v82; // [sp+48h] [-B8h]
  int v83; // [sp+4Ch] [-B4h]
  int v84; // [sp+4Ch] [-B4h]
  int v85; // [sp+50h] [-B0h]
  int v86; // [sp+50h] [-B0h]
  int v87; // [sp+58h] [-A8h]
  float *v88; // [sp+58h] [-A8h]
  int v89; // [sp+60h] [-A0h]
  float *v90; // [sp+68h] [-98h]
  float *v91; // [sp+70h] [-90h]
  float *v92; // [sp+78h] [-88h]
  float v93[4]; // [sp+90h] [-70h] BYREF
  float v94[24]; // [sp+A0h] [-60h] BYREF

  LODWORD(v33) = HIDWORD(ticksPerSec);
  HIDWORD(v33) = ticksPerSec;
  LODWORD(ticksPerSec) = animData->frameRate;
  v37 = 0.0;
  v38 = (float)((float)((float)((float)1.0 / (float)*(__int64 *)((char *)&ticksPerSec - 4)) * (float)ticksPerSec)
              * (float)v33);
  if ( v38 >= 0.0 )
  {
    LODWORD(v40) = animData->numFrames;
    if ( v38 < (float)*(__int64 *)((char *)&v33 - 4) )
    {
      LODWORD(v39) = (__int16)(int)v38;
      HIDWORD(v39) = animData->numFrames;
      v37 = (float)((float)v38 - (float)v39);
    }
    else
    {
      LOWORD(v39) = v40 - 1;
    }
  }
  else
  {
    LOWORD(v39) = 0;
  }
  v41 = (float *)(__int16)v39;
  v42 = *((unsigned __int8 *)&animData->totalSize + animData->frameSetTblOffset + (__int16)v39);
  v43 = ((skeleton->numJoints + 7) & 0xFFF8) + 1;
  v44 = &temp[4 * v43];
  v45 = (const frameSetData_t *)((char *)animData
                               + 16
                               * *(unsigned int *)((char *)&animData->totalSize
                                                 + __ROL4__(v42, 2)
                                                 + animData->frameSetOffsetTblOffset));
  v46 = &temp[8 * v43];
  v47 = &temp[12 * v43];
  idMD6Blend::DecodeAnimFrame(
    skeleton,
    numPaddedJoints: (skeleton->numJoints + 7) & 0xFFF8,
    animData,
    frameSetData: v45,
    frame: (__int16)((_WORD)v41 - v45->frameStart),
    frameFraction: v37,
    stackR: v41,
    stackS: temp,
    stackT: v44,
    stackU: v49,
    a11: v51,
    a12: v53,
    a13: v55,
    a14: v57,
    a15: v59,
    a16: v61,
    a17: v63,
    a18: v65,
    a19: v67,
    a20: v69,
    a21: v71,
    a22: v73,
    a23: v75,
    a24: v77,
    a25: v79,
    a26: v81,
    a27: v83,
    a28: v85,
    a29: v46,
    a30: v87,
    a31: v47);
  if ( clearOriginTransform )
    ClearOriginTransform(animData, poseR: temp, poseT: v46, curRot: v93, curTrans: v94, frameFlags: 8u);
  HIDWORD(v48) = originOffset;
  LODWORD(v48) = a27;
  idMD6Blend::TransformLocalJointsToModelMatrices(
    skeleton,
    temp: nullptr,
    tempSize: 0,
    mods: nullptr,
    numMods: 0,
    originOffset: v48,
    addOffset: v50,
    inR: v52,
    inS: v54,
    inT: v56,
    outMatrices: v58,
    quatTemp: v60,
    a13: v62,
    a14: v64,
    a15: v66,
    a16: v68,
    a17: v70,
    a18: v72,
    a19: v74,
    a20: v76,
    a21: v78,
    a22: v80,
    a23: v82,
    a24: v84,
    a25: v86,
    a26: (int)temp,
    a27: v88,
    a28: (int)v44,
    a29: v89,
    a30: (int)v46,
    a31: v90,
    a32: a29,
    a33: v91,
    a34: 0,
    inRa: v92);
  if ( a31 != nullptr )
    memcpy(Dst: a31, Src: v47, Size: __ROL4__(skeleton->numUserChannels, 2));
}


// ========================================================================
// ?DecodeSingleFrameWithOriginDeltaScale@idMD6Blend@@SAXPIBVidMD6SkelData@@PIAXIPIBVidMD6AnimData@@HH_NPIBM_NPIAM64@Z
// EA  : 0x82822710
// RVA : 0x00822710
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMD6Blend::DecodeSingleFrameWithOriginDeltaScale(
        const idMD6SkelData *skeleton,
        float *temp,
        unsigned int tempSize,
        const idMD6AnimData *animData,
        __int64 ticksPerSec,
        const bool clearOriginTransform,
        const float *originOffset,
        bool offsetAdd,
        float *outPose,
        float *outUserChannels,
        const float *originDeltaScale,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        unsigned __int8 a27,
        int a28,
        int a29,
        int a30,
        void *a31,
        int a32,
        float *a33)
{
  __int64 v35; // r10 OVERLAPPED
  double v39; // fp13
  double v40; // fp0
  __int64 v41; // r10
  __int64 v42; // r11
  int v43; // r4
  float *v44; // r27
  float *v45; // r26
  const frameSetData_t *v46; // r6
  float *v47; // r30
  double v48; // fp12
  __int64 v49; // r10
  double v50; // fp9
  double v51; // fp7
  float *v52; // [sp+8h] [-F8h]
  bool v53; // [sp+Bh] [-F5h]
  int v54; // [sp+Ch] [-F4h]
  const float *v55; // [sp+Ch] [-F4h]
  int v56; // [sp+10h] [-F0h]
  const float *v57; // [sp+10h] [-F0h]
  int v58; // [sp+14h] [-ECh]
  const float *v59; // [sp+14h] [-ECh]
  int v60; // [sp+18h] [-E8h]
  float *v61; // [sp+18h] [-E8h]
  int v62; // [sp+1Ch] [-E4h]
  float *v63; // [sp+1Ch] [-E4h]
  int v64; // [sp+20h] [-E0h]
  int v65; // [sp+20h] [-E0h]
  int v66; // [sp+24h] [-DCh]
  int v67; // [sp+24h] [-DCh]
  int v68; // [sp+28h] [-D8h]
  int v69; // [sp+28h] [-D8h]
  int v70; // [sp+2Ch] [-D4h]
  int v71; // [sp+2Ch] [-D4h]
  int v72; // [sp+30h] [-D0h]
  int v73; // [sp+30h] [-D0h]
  int v74; // [sp+34h] [-CCh]
  int v75; // [sp+34h] [-CCh]
  int v76; // [sp+38h] [-C8h]
  int v77; // [sp+38h] [-C8h]
  int v78; // [sp+3Ch] [-C4h]
  int v79; // [sp+3Ch] [-C4h]
  int v80; // [sp+40h] [-C0h]
  int v81; // [sp+40h] [-C0h]
  int v82; // [sp+44h] [-BCh]
  int v83; // [sp+44h] [-BCh]
  int v84; // [sp+48h] [-B8h]
  int v85; // [sp+48h] [-B8h]
  int v86; // [sp+4Ch] [-B4h]
  int v87; // [sp+4Ch] [-B4h]
  int v88; // [sp+50h] [-B0h]
  int v89; // [sp+50h] [-B0h]
  int v90; // [sp+58h] [-A8h]
  float *v91; // [sp+58h] [-A8h]
  int v92; // [sp+60h] [-A0h]
  float *v93; // [sp+68h] [-98h]
  float *v94; // [sp+70h] [-90h]
  float *v95; // [sp+78h] [-88h]
  float v96[4]; // [sp+90h] [-70h] BYREF
  float v97[24]; // [sp+A0h] [-60h] BYREF

  LODWORD(v35) = HIDWORD(ticksPerSec);
  HIDWORD(v35) = ticksPerSec;
  LODWORD(ticksPerSec) = animData->frameRate;
  v39 = 0.0;
  v40 = (float)((float)((float)((float)1.0 / (float)*(__int64 *)((char *)&ticksPerSec - 4)) * (float)ticksPerSec)
              * (float)v35);
  if ( v40 >= 0.0 )
  {
    LODWORD(v42) = animData->numFrames;
    if ( v40 < (float)*(__int64 *)((char *)&v35 - 4) )
    {
      LODWORD(v41) = (__int16)(int)v40;
      HIDWORD(v41) = animData->numFrames;
      v39 = (float)((float)v40 - (float)v41);
    }
    else
    {
      LOWORD(v41) = v42 - 1;
    }
  }
  else
  {
    LOWORD(v41) = 0;
  }
  HIDWORD(v41) = temp;
  v43 = (skeleton->numJoints + 7) & 0xFFF8;
  v44 = &temp[4 * v43 + 4];
  v45 = &temp[12 * v43 + 12];
  v46 = (const frameSetData_t *)((char *)animData
                               + 16
                               * *(unsigned int *)((char *)&animData->totalSize
                                                 + __ROL4__(
                                                     *((unsigned __int8 *)&animData->totalSize
                                                     + animData->frameSetTblOffset
                                                     + (__int16)v41),
                                                     2)
                                                 + animData->frameSetOffsetTblOffset));
  v47 = &temp[8 * v43 + 8];
  idMD6Blend::DecodeAnimFrame(
    skeleton,
    numPaddedJoints: v43,
    animData,
    frameSetData: v46,
    frame: (__int16)(v41 - v46->frameStart),
    frameFraction: v39,
    stackR: (float *)(__int16)v41,
    stackS: (float *)HIDWORD(v41),
    stackT: v44,
    stackU: v52,
    a11: v54,
    a12: v56,
    a13: v58,
    a14: v60,
    a15: v62,
    a16: v64,
    a17: v66,
    a18: v68,
    a19: v70,
    a20: v72,
    a21: v74,
    a22: v76,
    a23: v78,
    a24: v80,
    a25: v82,
    a26: v84,
    a27: v86,
    a28: v88,
    a29: v47,
    a30: v90,
    a31: v45);
  if ( clearOriginTransform )
    ClearOriginTransform(animData, poseR: temp, poseT: v47, curRot: v96, curTrans: v97, frameFlags: 8u);
  v48 = v47[2];
  HIDWORD(v49) = originOffset;
  LODWORD(v49) = a27;
  v50 = a33[2];
  v51 = (float)(a33[1] * v47[1]);
  *v47 = *v47 * *a33;
  v47[1] = v51;
  v47[2] = (float)v50 * (float)v48;
  idMD6Blend::TransformLocalJointsToModelMatrices(
    skeleton,
    temp: nullptr,
    tempSize: 0,
    mods: nullptr,
    numMods: 0,
    originOffset: v49,
    addOffset: v53,
    inR: v55,
    inS: v57,
    inT: v59,
    outMatrices: v61,
    quatTemp: v63,
    a13: v65,
    a14: v67,
    a15: v69,
    a16: v71,
    a17: v73,
    a18: v75,
    a19: v77,
    a20: v79,
    a21: v81,
    a22: v83,
    a23: v85,
    a24: v87,
    a25: v89,
    a26: (int)temp,
    a27: v91,
    a28: (int)v44,
    a29: v92,
    a30: (int)v47,
    a31: v93,
    a32: a29,
    a33: v94,
    a34: 0,
    inRa: v95);
  if ( a31 != nullptr )
    memcpy(Dst: a31, Src: v45, Size: __ROL4__(skeleton->numUserChannels, 2));
}


// ========================================================================
// ?ExecuteCommandsInternal@idMD6Blend@@CAXPIBVidMD6SkelData@@PIAXAAUdoubleStack_t@1@PIBUmd6AnimCommand_t@@I_NV?$idIndex@FW4invalidJointIndex_t@@@@PIBM_NPIBUjointMod_t@1@IPBEAA_NPIAMPIAUmd6OriginDelta_t@@PIAMI@Z
// EA  : 0x82822940
// RVA : 0x00822940
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::ExecuteCommandsInternal(
        const idMD6SkelData *skeleton,
        unsigned int temp,
        idMD6Blend::doubleStack_t *stack,
        const md6AnimCommand_t *cmds,
        unsigned int numCmds,
        const bool clearOriginTransform,
        const idIndex<short,enum invalidJointIndex_t> *boundsSkipJoint,
        const float *originOffset,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        bool addOffset,
        const idMD6Blend::jointMod_t *jointMods,
        unsigned int numJointMods,
        const unsigned __int8 *jointRemap,
        bool *generatedReferencePose,
        float *refPose,
        md6OriginDelta_t *originDelta,
        float *userChannels,
        unsigned int dmaTag,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        unsigned __int8 a36,
        int a37,
        const idMD6Blend::jointMod_t *a38,
        int a39,
        unsigned int a40,
        int a41,
        int a42,
        int a43,
        _BYTE *a44,
        int a45,
        const idMD6Blend::jointMod_t *jointModsa,
        int a47,
        _OWORD *numJointModsa,
        int a49,
        unsigned __int8 *jointRemapa)
{
  const md6AnimCommand_t *v50; // r25
  md6AnimCommand_t::<unnamed_type_op> op; // r8
  int v52; // r10
  int v53; // r20
  int v54; // r17
  int v55; // r18
  int v56; // r15
  int v57; // r16
  int v58; // r14
  int v59; // r6
  const unsigned __int8 *v60; // r4
  int v61; // r26
  const unsigned __int8 *v62; // r7
  int filterGroup; // r10
  char *v64; // r30
  const float *v65; // r31
  const unsigned __int8 *v66; // r28
  unsigned __int8 *v67; // r27
  const float *v68; // r26
  const float *v69; // r25
  const unsigned __int8 *v70; // r24
  const float *v71; // r29
  const float *v72; // r19
  const float *v73; // r23
  float *v74; // r22
  const float *v75; // r21
  const unsigned __int8 *v76; // r18
  const unsigned __int8 *v77; // r17
  const float *v78; // r16
  const float *v79; // r15
  const unsigned __int8 *v80; // r14
  const float *v81; // r20
  int v82; // r11
  const float *v83; // r11
  bool v84; // zf
  double currentAlpha; // fp29
  double v86; // fp28
  __int64 v87; // r10
  char *v88; // r4
  const unsigned __int8 *v89; // r4
  double v90; // fp8
  double v91; // fp7
  double v92; // fp6
  double v93; // fp5
  double v94; // fp4
  double v95; // fp3
  double v96; // fp2
  double v97; // fp1
  const unsigned __int8 *v98; // r4
  double v99; // fp8
  double v100; // fp7
  double v101; // fp6
  double v102; // fp5
  double v103; // fp4
  double v104; // fp3
  double v105; // fp2
  const unsigned __int8 *v106; // r4
  double v107; // fp8
  double v108; // fp7
  double v109; // fp6
  double v110; // fp5
  double v111; // fp4
  double v112; // fp3
  double v113; // fp2
  double v114; // fp1
  const unsigned __int8 *v115; // r4
  double v116; // fp8
  double v117; // fp7
  double v118; // fp6
  double v119; // fp5
  double v120; // fp4
  double v121; // fp3
  double v122; // fp2
  const unsigned __int8 *v123; // r4
  double v124; // fp8
  double v125; // fp7
  double v126; // fp6
  double v127; // fp5
  double v128; // fp4
  double v129; // fp3
  double v130; // fp2
  double v131; // fp1
  const unsigned __int8 *v132; // r4
  double v133; // fp8
  double v134; // fp7
  double v135; // fp6
  double v136; // fp5
  double v137; // fp4
  double v138; // fp3
  double v139; // fp2
  const unsigned __int8 *v140; // r4
  double v141; // fp8
  double v142; // fp7
  double v143; // fp6
  double v144; // fp5
  double v145; // fp4
  double v146; // fp3
  double v147; // fp2
  double v148; // fp8
  double v149; // fp7
  double v150; // fp6
  double v151; // fp5
  double v152; // fp4
  double v153; // fp3
  double v154; // fp2
  const unsigned __int8 *v155; // r4
  double v156; // fp8
  double v157; // fp7
  double v158; // fp6
  double v159; // fp5
  double v160; // fp4
  double v161; // fp3
  double v162; // fp2
  double v163; // fp8
  double v164; // fp7
  double v165; // fp6
  double v166; // fp5
  double v167; // fp4
  double v168; // fp3
  double v169; // fp2
  char *bot; // r27
  const float *v171; // r19
  int v172; // r11
  char *v173; // r29
  float *v174; // r24
  float *v175; // r23
  const float *v176; // r11
  unsigned __int16 *animData; // r31
  const idMD6Blend::jointMod_t *animMods; // r4
  const frameSetData_t *frameSetData; // r30
  int v180; // r7
  unsigned __int16 v181; // r25
  int v182; // r11
  char *v183; // r11
  int v184; // ctr
  int v185; // r10
  int v186; // r9
  unsigned int v187; // r26
  unsigned int frameRange; // r22
  unsigned int v189; // r28
  const __int16 *v190; // r18
  const __int16 *v191; // r20
  const unsigned __int8 *v192; // r16
  const float *v193; // r15
  const unsigned __int8 *v194; // r17
  unsigned int frameStart; // r21
  const __int16 *v196; // r7
  unsigned int v197; // r29
  const float *v198; // r14
  int v199; // r11
  double v200; // fp29
  int v201; // ctr
  float *v202; // r9
  float *v203; // r10
  float *v204; // r11
  int v205; // r29
  unsigned __int16 *v206; // r11
  int v207; // r28
  signed int v208; // r3
  int v209; // r28
  unsigned int v210; // r26
  int v211; // r29
  signed int v212; // r3
  unsigned int v213; // r29
  int v214; // r11
  int v215; // r29
  signed int v216; // r3
  int v217; // r6
  const float *v218; // r7
  double v219; // fp8
  double v220; // fp7
  double v221; // fp6
  double v222; // fp5
  double v223; // fp4
  double v224; // fp3
  double v225; // fp2
  double v226; // fp8
  double v227; // fp7
  double v228; // fp6
  double v229; // fp5
  double v230; // fp4
  double v231; // fp3
  double v232; // fp2
  double v233; // fp8
  double v234; // fp7
  double v235; // fp6
  double v236; // fp5
  double v237; // fp4
  double v238; // fp3
  double v239; // fp2
  char *end; // r10
  char *v241; // r31
  char *v242; // r28
  char *v243; // r29
  int v244; // ctr
  char *v245; // r30
  float *v246; // r19
  float *v247; // r23
  float *v248; // r18
  char *v249; // r15
  char *v250; // r17
  char *v251; // r22
  unsigned __int8 *v252; // r14
  float *v253; // r9
  float *v254; // r10
  float *v255; // r11
  float *v256; // r8
  int v257; // r7
  char *v258; // r6
  unsigned __int16 flags; // r11
  const idMD6AnimData *v260; // r24
  BOOL v261; // r16
  size_t v262; // r21
  const idMD6SkelData *v263; // r20
  const md6AnimCommand_t *v264; // r27
  const frameSetData_t *originFrameSetData; // r6
  BOOL v266; // r27
  const frameSetData_t *v267; // r26
  __int16 frame; // r9
  int originFrame; // r10
  double v270; // fp13
  double v271; // fp12
  double v272; // fp11
  double v273; // fp10
  double v274; // fp9
  double v275; // fp8
  double v276; // fp7
  double v277; // fp6
  double v278; // fp5
  double v279; // fp4
  double v280; // fp3
  const float *startDelta; // r4
  const float *endDelta; // r3
  const float *v283; // r4
  const float *v284; // r3
  unsigned __int16 v285; // r11
  int weightGroup; // r29
  int v287; // r9
  unsigned __int8 *v288; // r30
  char v289; // r10
  char *v290; // r9
  size_t v291; // ctr
  unsigned __int8 *v292; // r11
  unsigned __int8 v293; // r3
  int v294; // r10
  char *v295; // r4
  char *v296; // r4
  size_t v297; // r5
  char *v298; // r3
  int v299; // r28
  int v300; // r3
  int v301; // r30
  char *v302; // r4
  char *v303; // r11
  char v304; // r8
  int v305; // r7
  const idMD6Blend::jointMod_t *v306; // r29
  unsigned int v307; // r30
  idIndex<short,enum invalidJointIndex_t> *p_joint; // r11
  unsigned int i; // ctr
  char v310; // r10
  unsigned int v311; // r30
  float *v312; // [sp+8h] [-5E8h]
  float v313; // [sp+8h] [-5E8h]
  const float *v314; // [sp+8h] [-5E8h]
  float v315; // [sp+8h] [-5E8h]
  const float *v316; // [sp+8h] [-5E8h]
  float v317; // [sp+8h] [-5E8h]
  const float *v318; // [sp+8h] [-5E8h]
  float v319; // [sp+8h] [-5E8h]
  const float *v320; // [sp+8h] [-5E8h]
  float v321; // [sp+8h] [-5E8h]
  const float *v322; // [sp+8h] [-5E8h]
  float *v323; // [sp+8h] [-5E8h]
  float *v324; // [sp+8h] [-5E8h]
  const float *v325; // [sp+8h] [-5E8h]
  const float *v326; // [sp+Ch] [-5E4h]
  float v327; // [sp+Ch] [-5E4h]
  const unsigned __int8 *v328; // [sp+Ch] [-5E4h]
  float v329; // [sp+Ch] [-5E4h]
  const unsigned __int8 *v330; // [sp+Ch] [-5E4h]
  float v331; // [sp+Ch] [-5E4h]
  const unsigned __int8 *v332; // [sp+Ch] [-5E4h]
  float v333; // [sp+Ch] [-5E4h]
  const float *v334; // [sp+Ch] [-5E4h]
  float v335; // [sp+Ch] [-5E4h]
  const float *v336; // [sp+Ch] [-5E4h]
  int v337; // [sp+Ch] [-5E4h]
  int v338; // [sp+Ch] [-5E4h]
  const unsigned __int8 *v339; // [sp+Ch] [-5E4h]
  float *v340; // [sp+10h] [-5E0h]
  float v341; // [sp+10h] [-5E0h]
  float *v342; // [sp+10h] [-5E0h]
  float v343; // [sp+10h] [-5E0h]
  float *v344; // [sp+10h] [-5E0h]
  float v345; // [sp+10h] [-5E0h]
  float *v346; // [sp+10h] [-5E0h]
  float v347; // [sp+10h] [-5E0h]
  const unsigned __int8 *v348; // [sp+10h] [-5E0h]
  float v349; // [sp+10h] [-5E0h]
  const unsigned __int8 *v350; // [sp+10h] [-5E0h]
  int v351; // [sp+10h] [-5E0h]
  int v352; // [sp+10h] [-5E0h]
  float *v353; // [sp+10h] [-5E0h]
  float *v354; // [sp+14h] [-5DCh]
  float v355; // [sp+14h] [-5DCh]
  float *v356; // [sp+14h] [-5DCh]
  float v357; // [sp+14h] [-5DCh]
  float *v358; // [sp+14h] [-5DCh]
  float v359; // [sp+14h] [-5DCh]
  float *v360; // [sp+14h] [-5DCh]
  float v361; // [sp+14h] [-5DCh]
  float *v362; // [sp+14h] [-5DCh]
  float v363; // [sp+14h] [-5DCh]
  float *v364; // [sp+14h] [-5DCh]
  int v365; // [sp+14h] [-5DCh]
  int v366; // [sp+14h] [-5DCh]
  float *v367; // [sp+14h] [-5DCh]
  float *v368; // [sp+18h] [-5D8h]
  float v369; // [sp+18h] [-5D8h]
  float *v370; // [sp+18h] [-5D8h]
  float v371; // [sp+18h] [-5D8h]
  float *v372; // [sp+18h] [-5D8h]
  float v373; // [sp+18h] [-5D8h]
  float *v374; // [sp+18h] [-5D8h]
  float v375; // [sp+18h] [-5D8h]
  float *v376; // [sp+18h] [-5D8h]
  float v377; // [sp+18h] [-5D8h]
  float *v378; // [sp+18h] [-5D8h]
  int v379; // [sp+18h] [-5D8h]
  int v380; // [sp+18h] [-5D8h]
  float *v381; // [sp+18h] [-5D8h]
  float *v382; // [sp+1Ch] [-5D4h]
  float v383; // [sp+1Ch] [-5D4h]
  float v384; // [sp+1Ch] [-5D4h]
  float v385; // [sp+1Ch] [-5D4h]
  float v386; // [sp+1Ch] [-5D4h]
  float v387; // [sp+1Ch] [-5D4h]
  float v388; // [sp+1Ch] [-5D4h]
  float v389; // [sp+1Ch] [-5D4h]
  float *v390; // [sp+1Ch] [-5D4h]
  float v391; // [sp+1Ch] [-5D4h]
  float *v392; // [sp+1Ch] [-5D4h]
  int v393; // [sp+1Ch] [-5D4h]
  int v394; // [sp+1Ch] [-5D4h]
  float v395; // [sp+1Ch] [-5D4h]
  int v396; // [sp+20h] [-5D0h]
  float v397; // [sp+20h] [-5D0h]
  int v398; // [sp+20h] [-5D0h]
  float v399; // [sp+20h] [-5D0h]
  int v400; // [sp+20h] [-5D0h]
  float v401; // [sp+20h] [-5D0h]
  int v402; // [sp+20h] [-5D0h]
  float v403; // [sp+20h] [-5D0h]
  float v404; // [sp+20h] [-5D0h]
  float v405; // [sp+20h] [-5D0h]
  float v406; // [sp+20h] [-5D0h]
  int v407; // [sp+20h] [-5D0h]
  int v408; // [sp+20h] [-5D0h]
  int v409; // [sp+20h] [-5D0h]
  const float *v410; // [sp+24h] [-5CCh]
  float v411; // [sp+24h] [-5CCh]
  const float *v412; // [sp+24h] [-5CCh]
  float v413; // [sp+24h] [-5CCh]
  int v414; // [sp+24h] [-5CCh]
  float v415; // [sp+24h] [-5CCh]
  int v416; // [sp+24h] [-5CCh]
  float v417; // [sp+24h] [-5CCh]
  int v418; // [sp+24h] [-5CCh]
  float v419; // [sp+24h] [-5CCh]
  int v420; // [sp+24h] [-5CCh]
  unsigned int v421; // [sp+24h] [-5CCh]
  unsigned int v422; // [sp+24h] [-5CCh]
  int v423; // [sp+24h] [-5CCh]
  int v424; // [sp+28h] [-5C8h]
  float v425; // [sp+28h] [-5C8h]
  int v426; // [sp+28h] [-5C8h]
  float v427; // [sp+28h] [-5C8h]
  int v428; // [sp+28h] [-5C8h]
  float v429; // [sp+28h] [-5C8h]
  int v430; // [sp+28h] [-5C8h]
  float v431; // [sp+28h] [-5C8h]
  int v432; // [sp+28h] [-5C8h]
  float v433; // [sp+28h] [-5C8h]
  int v434; // [sp+28h] [-5C8h]
  int v435; // [sp+28h] [-5C8h]
  int v436; // [sp+28h] [-5C8h]
  int v437; // [sp+28h] [-5C8h]
  int v438; // [sp+2Ch] [-5C4h]
  float v439; // [sp+2Ch] [-5C4h]
  int v440; // [sp+2Ch] [-5C4h]
  float v441; // [sp+2Ch] [-5C4h]
  int v442; // [sp+2Ch] [-5C4h]
  float v443; // [sp+2Ch] [-5C4h]
  int v444; // [sp+2Ch] [-5C4h]
  float v445; // [sp+2Ch] [-5C4h]
  int v446; // [sp+2Ch] [-5C4h]
  float v447; // [sp+2Ch] [-5C4h]
  int v448; // [sp+2Ch] [-5C4h]
  int v449; // [sp+2Ch] [-5C4h]
  int v450; // [sp+2Ch] [-5C4h]
  int v451; // [sp+2Ch] [-5C4h]
  int v452; // [sp+30h] [-5C0h]
  float v453; // [sp+30h] [-5C0h]
  int v454; // [sp+30h] [-5C0h]
  float v455; // [sp+30h] [-5C0h]
  int v456; // [sp+30h] [-5C0h]
  float v457; // [sp+30h] [-5C0h]
  int v458; // [sp+30h] [-5C0h]
  float v459; // [sp+30h] [-5C0h]
  int v460; // [sp+30h] [-5C0h]
  float v461; // [sp+30h] [-5C0h]
  int v462; // [sp+30h] [-5C0h]
  int v463; // [sp+30h] [-5C0h]
  int v464; // [sp+30h] [-5C0h]
  int v465; // [sp+30h] [-5C0h]
  int v466; // [sp+34h] [-5BCh]
  float v467; // [sp+34h] [-5BCh]
  int v468; // [sp+34h] [-5BCh]
  float v469; // [sp+34h] [-5BCh]
  int v470; // [sp+34h] [-5BCh]
  float v471; // [sp+34h] [-5BCh]
  int v472; // [sp+34h] [-5BCh]
  float v473; // [sp+34h] [-5BCh]
  int v474; // [sp+34h] [-5BCh]
  float v475; // [sp+34h] [-5BCh]
  int v476; // [sp+34h] [-5BCh]
  float v477; // [sp+34h] [-5BCh]
  float v478; // [sp+34h] [-5BCh]
  int v479; // [sp+34h] [-5BCh]
  int v480; // [sp+38h] [-5B8h]
  float v481; // [sp+38h] [-5B8h]
  int v482; // [sp+38h] [-5B8h]
  float v483; // [sp+38h] [-5B8h]
  int v484; // [sp+38h] [-5B8h]
  float v485; // [sp+38h] [-5B8h]
  int v486; // [sp+38h] [-5B8h]
  float v487; // [sp+38h] [-5B8h]
  int v488; // [sp+38h] [-5B8h]
  float v489; // [sp+38h] [-5B8h]
  int v490; // [sp+38h] [-5B8h]
  int v491; // [sp+38h] [-5B8h]
  int v492; // [sp+38h] [-5B8h]
  int v493; // [sp+38h] [-5B8h]
  int v494; // [sp+3Ch] [-5B4h]
  float v495; // [sp+3Ch] [-5B4h]
  int v496; // [sp+3Ch] [-5B4h]
  float v497; // [sp+3Ch] [-5B4h]
  int v498; // [sp+3Ch] [-5B4h]
  float v499; // [sp+3Ch] [-5B4h]
  int v500; // [sp+3Ch] [-5B4h]
  float v501; // [sp+3Ch] [-5B4h]
  int v502; // [sp+3Ch] [-5B4h]
  float v503; // [sp+3Ch] [-5B4h]
  int v504; // [sp+3Ch] [-5B4h]
  int v505; // [sp+3Ch] [-5B4h]
  int v506; // [sp+3Ch] [-5B4h]
  int v507; // [sp+3Ch] [-5B4h]
  int v508; // [sp+40h] [-5B0h]
  float v509; // [sp+40h] [-5B0h]
  int v510; // [sp+40h] [-5B0h]
  float v511; // [sp+40h] [-5B0h]
  int v512; // [sp+40h] [-5B0h]
  float v513; // [sp+40h] [-5B0h]
  int v514; // [sp+40h] [-5B0h]
  float v515; // [sp+40h] [-5B0h]
  int v516; // [sp+40h] [-5B0h]
  float v517; // [sp+40h] [-5B0h]
  int v518; // [sp+40h] [-5B0h]
  int v519; // [sp+40h] [-5B0h]
  int v520; // [sp+40h] [-5B0h]
  int v521; // [sp+40h] [-5B0h]
  const float *v522; // [sp+44h] [-5ACh]
  float v523; // [sp+44h] [-5ACh]
  const float *v524; // [sp+44h] [-5ACh]
  float v525; // [sp+44h] [-5ACh]
  const float *v526; // [sp+44h] [-5ACh]
  float v527; // [sp+44h] [-5ACh]
  const float *v528; // [sp+44h] [-5ACh]
  float v529; // [sp+44h] [-5ACh]
  int v530; // [sp+44h] [-5ACh]
  float v531; // [sp+44h] [-5ACh]
  int v532; // [sp+44h] [-5ACh]
  int v533; // [sp+44h] [-5ACh]
  int v534; // [sp+44h] [-5ACh]
  const float *v535; // [sp+44h] [-5ACh]
  const float *v536; // [sp+48h] [-5A8h]
  float v537; // [sp+48h] [-5A8h]
  int v538; // [sp+48h] [-5A8h]
  float v539; // [sp+48h] [-5A8h]
  int v540; // [sp+48h] [-5A8h]
  float v541; // [sp+48h] [-5A8h]
  int v542; // [sp+48h] [-5A8h]
  float v543; // [sp+48h] [-5A8h]
  const float *v544; // [sp+48h] [-5A8h]
  float v545; // [sp+48h] [-5A8h]
  const float *v546; // [sp+48h] [-5A8h]
  int v547; // [sp+48h] [-5A8h]
  int v548; // [sp+48h] [-5A8h]
  int v549; // [sp+48h] [-5A8h]
  int v550; // [sp+4Ch] [-5A4h]
  float v551; // [sp+4Ch] [-5A4h]
  int v552; // [sp+4Ch] [-5A4h]
  float v553; // [sp+4Ch] [-5A4h]
  int v554; // [sp+4Ch] [-5A4h]
  float v555; // [sp+4Ch] [-5A4h]
  int v556; // [sp+4Ch] [-5A4h]
  float v557; // [sp+4Ch] [-5A4h]
  int v558; // [sp+4Ch] [-5A4h]
  float v559; // [sp+4Ch] [-5A4h]
  int v560; // [sp+4Ch] [-5A4h]
  int v561; // [sp+4Ch] [-5A4h]
  int v562; // [sp+4Ch] [-5A4h]
  int v563; // [sp+4Ch] [-5A4h]
  int v564; // [sp+50h] [-5A0h]
  float v565; // [sp+50h] [-5A0h]
  int v566; // [sp+50h] [-5A0h]
  float v567; // [sp+50h] [-5A0h]
  int v568; // [sp+50h] [-5A0h]
  float v569; // [sp+50h] [-5A0h]
  int v570; // [sp+50h] [-5A0h]
  float v571; // [sp+50h] [-5A0h]
  int v572; // [sp+50h] [-5A0h]
  float v573; // [sp+50h] [-5A0h]
  int v574; // [sp+50h] [-5A0h]
  int v575; // [sp+50h] [-5A0h]
  int v576; // [sp+50h] [-5A0h]
  int v577; // [sp+50h] [-5A0h]
  float *v578; // [sp+58h] [-598h]
  int v579; // [sp+58h] [-598h]
  int v580; // [sp+58h] [-598h]
  int v581; // [sp+58h] [-598h]
  int v582; // [sp+58h] [-598h]
  int v583; // [sp+58h] [-598h]
  int v584; // [sp+58h] [-598h]
  int v585; // [sp+58h] [-598h]
  int v586; // [sp+58h] [-598h]
  int v587; // [sp+60h] [-590h]
  int v588; // [sp+60h] [-590h]
  int v589; // [sp+60h] [-590h]
  int v590; // [sp+60h] [-590h]
  int v591; // [sp+60h] [-590h]
  int v592; // [sp+60h] [-590h]
  float *v593; // [sp+68h] [-588h]
  int v594; // [sp+68h] [-588h]
  int v595; // [sp+68h] [-588h]
  int v596; // [sp+68h] [-588h]
  unsigned int v597; // [sp+68h] [-588h]
  unsigned int v598; // [sp+68h] [-588h]
  float *v599; // [sp+70h] [-580h]
  int v600; // [sp+70h] [-580h]
  int v601; // [sp+70h] [-580h]
  int v602; // [sp+70h] [-580h]
  int v603; // [sp+70h] [-580h]
  int v604; // [sp+70h] [-580h]
  float *v605; // [sp+78h] [-578h]
  int v606; // [sp+78h] [-578h]
  int v607; // [sp+78h] [-578h]
  int v608; // [sp+78h] [-578h]
  const float *v609; // [sp+78h] [-578h]
  const float *v610; // [sp+78h] [-578h]
  const float *v611; // [sp+80h] [-570h]
  int v612; // [sp+80h] [-570h]
  int v613; // [sp+80h] [-570h]
  int v614; // [sp+80h] [-570h]
  const float *v615; // [sp+80h] [-570h]
  const float *v616; // [sp+80h] [-570h]
  const unsigned __int8 *v617; // [sp+88h] [-568h]
  const unsigned __int8 *v618; // [sp+88h] [-568h]
  const unsigned __int8 *v619; // [sp+88h] [-568h]
  unsigned __int16 v620; // [sp+90h] [-560h]
  const float *v621; // [sp+94h] [-55Ch]
  char v622; // [sp+94h] [-55Ch]
  char v623; // [sp+95h] [-55Bh]
  const md6AnimCommand_t *v624; // [sp+98h] [-558h]
  int v625; // [sp+9Ch] [-554h]
  const float *v626; // [sp+A0h] [-550h]
  int v627; // [sp+A0h] [-550h]
  const float *v628; // [sp+A4h] [-54Ch]
  const float *v629; // [sp+A4h] [-54Ch]
  float *v630; // [sp+A8h] [-548h]
  float *v631; // [sp+A8h] [-548h]
  int v632; // [sp+ACh] [-544h]
  int v633; // [sp+B0h] [-540h]
  int v634; // [sp+B4h] [-53Ch]
  unsigned int v635; // [sp+B8h] [-538h]
  int v636; // [sp+BCh] [-534h]
  int v637; // [sp+C0h] [-530h]
  int v638; // [sp+C4h] [-52Ch]
  int v639; // [sp+C8h] [-528h]
  const float *v640; // [sp+D0h] [-520h]
  const unsigned __int8 *v641; // [sp+D4h] [-51Ch]
  int v642; // [sp+D8h] [-518h]
  const float *v643; // [sp+DCh] [-514h]
  const unsigned __int8 *v644; // [sp+E0h] [-510h]
  const unsigned __int8 *v645; // [sp+E4h] [-50Ch]
  const unsigned __int8 *v646; // [sp+E8h] [-508h]
  unsigned int v647; // [sp+ECh] [-504h]
  const float *v648; // [sp+F0h] [-500h]
  int v649; // [sp+F4h] [-4FCh]
  const float *v650; // [sp+F8h] [-4F8h]
  const unsigned __int8 *v651; // [sp+FCh] [-4F4h]
  const unsigned __int8 *v652; // [sp+104h] [-4ECh]
  const float *v653; // [sp+108h] [-4E8h]
  const unsigned __int8 *v654; // [sp+10Ch] [-4E4h]
  float v655[12]; // [sp+110h] [-4E0h] BYREF
  _QWORD v656[6]; // [sp+140h] [-4B0h] BYREF
  _QWORD v657[6]; // [sp+170h] [-480h] BYREF
  float v658[12]; // [sp+1A0h] [-450h] BYREF
  float v659[12]; // [sp+1D0h] [-420h] BYREF
  unsigned __int8 v660[272]; // [sp+200h] [-3F0h] BYREF
  unsigned __int8 v661[272]; // [sp+310h] [-2E0h] BYREF
  unsigned __int8 v662[312]; // [sp+420h] [-1D0h] BYREF
  const idMD6SkelData *v663; // [sp+604h] [+14h]
  idMD6Blend::doubleStack_t *v665; // [sp+614h] [+24h]

  v50 = cmds;
  op = cmds->op;
  v663 = skeleton;
  v665 = stack;
  v620 = (skeleton->numJoints + 7) & 0xFFF8;
  v52 = (16 * v620) & 0xFFFF0;
  v625 = (skeleton->numUserChannels + 7) & 0xFFF8;
  v624 = cmds;
  v53 = v52 + 16;
  v649 = v52 + 16;
  v642 = v52 + v52 + 16 + 16;
  v54 = v52 + v642 + 16;
  v637 = v54;
  v638 = 4 * (v625 + 4) + v54;
  v55 = v642;
  v56 = v638 + 144;
  v639 = v638 + 144;
  v57 = v638;
  v58 = v638 + 288;
  v636 = v638 + 288;
  v60 = (const unsigned __int8 *)(((v620 + 15) & 0x1FFF0) + v638 + 432);
  v651 = v60;
  v61 = (int)&v60[((v625 + 15) & 0x1FFF0) + 16];
  v644 = &v60[(v625 + 15) & 0x1FFF0];
  v62 = v644;
  v634 = v61;
  v59 = v638 + 432;
  if ( op != OP_END )
  {
    while ( 1 )
    {
      globalDebugCommand = v50->debugCommand;
      if ( op == OP_DECODE_AND_PUSH )
        break;
      if ( op == OP_DECODE_FACECOMPOSITE_AND_BLEND )
      {
        bot = stack->bot;
        v171 = (const float *)&bot[-v61];
        v647 = (v61 + 15) & 0xFFFFFFF0;
        v172 = skeleton->jointWeightOffsets[v50->blendInfo.filterGroup];
        stack->bot = &bot[v647];
        v643 = (const float *)&bot[v53 - v61];
        v173 = &bot[v59];
        v641 = (const unsigned __int8 *)&bot[v55 - v61];
        v631 = (float *)&bot[v54 - v61];
        v174 = (float *)&bot[v53];
        v640 = (const float *)&bot[v59 - v61];
        v175 = (float *)&bot[v55];
        v645 = (const unsigned __int8 *)&bot[v59];
        v84 = v172 != 0;
        v176 = (const float *)((char *)&skeleton->size + v172);
        if ( !v84 )
          v176 = nullptr;
        animData = (unsigned __int16 *)v50->frameInfo.animData;
        v629 = v176;
        if ( animData != nullptr )
        {
          animMods = v50->frameInfo.animMods;
          if ( animMods != nullptr )
          {
            idMD6Blend::ApplyAnimMods(
              skeleton: v663,
              animMods,
              numAnimMods: v624->frameInfo.animModsSize >> 6,
              R: (const float *)bot,
              S: (const float *)&bot[v53],
              T: (const float *)&bot[v55],
              U: v631);
            skeleton = v663;
            stack = v665;
            v50 = v624;
          }
          frameSetData = v50->frameInfo.frameSetData;
          v180 = 2 * (v50->frameInfo.weightGroup + 10);
          v181 = (skeleton->numJoints + 7) & 0xFFF8;
          v182 = *(unsigned __int16 *)((char *)&skeleton->size + v180);
          v84 = v182 != 0;
          v183 = (char *)skeleton + v182;
          if ( !v84 )
            v183 = nullptr;
          if ( animData[15] != 0 )
          {
            v632 = (skeleton->numJoints + 7) & 0xFFF8;
            if ( ((skeleton->numJoints + 7) & 0xFFF8) != 0 )
            {
              v184 = (skeleton->numJoints + 7) & 0xFFF8;
              v185 = (char *)animData + animData[15] - v183;
              v186 = v173 - v183;
              do
              {
                v183[v186] = (unsigned __int16)((unsigned __int8)v183[v185] * (unsigned __int8)*v183) >> 8;
                ++v183;
                --v184;
              }
              while ( v184 != 0 );
            }
          }
          else
          {
            v632 = (skeleton->numJoints + 7) & 0xFFF8;
            memcpy(Dst: v173, Src: v183, Size: v632);
            skeleton = v663;
            stack = v665;
          }
          v187 = 0;
          frameRange = frameSetData->frameRange;
          v189 = 0;
          v190 = (const __int16 *)((char *)frameSetData + frameSetData->rangeROffset);
          v191 = (const __int16 *)((char *)frameSetData + frameSetData->firstROffset);
          v192 = (const unsigned __int8 *)frameSetData + frameSetData->RBitsOffset;
          v193 = (const float *)((char *)&frameSetData->firstROffset + frameSetData->firstSOffset);
          v194 = (const unsigned __int8 *)frameSetData + frameSetData->nextROffset;
          frameStart = (__int16)frameSetData->frameStart;
          v652 = (const unsigned __int8 *)frameSetData + frameSetData->nextSOffset;
          v633 = (__int16)(frameStart + frameRange);
          v196 = (const __int16 *)((char *)frameSetData + frameSetData->rangeTOffset);
          v654 = (const unsigned __int8 *)frameSetData + frameSetData->nextTOffset;
          v197 = 0;
          v627 = (__int16)frameStart;
          v198 = (const float *)((char *)&frameSetData->firstROffset + frameSetData->rangeSOffset);
          v646 = (const unsigned __int8 *)frameSetData + frameSetData->SBitsOffset;
          v653 = (const float *)((char *)&frameSetData->firstROffset + frameSetData->firstTOffset);
          v650 = (const float *)v196;
          v648 = (const float *)((char *)&frameSetData->firstROffset + frameSetData->TBitsOffset);
          v622 = 0;
          if ( (__int16)frameStart < v633 )
          {
            v199 = frameStart;
            do
            {
              v200 = v631[v199];
              if ( v200 > 0.00000011920929 )
              {
                frameStart = v627 - frameSetData->frameStart;
                if ( v622 == 0 )
                {
                  v622 = 1;
                  if ( ((v663->numJoints + 7) & 0xFFF8) != 0 )
                  {
                    v201 = (v663->numJoints + 7) & 0xFFF8;
                    v202 = v175 - 4;
                    v203 = v174 + 2;
                    v204 = (float *)(bot + 4);
                    do
                    {
                      v204[1] = 0.0;
                      *v204 = 0.0;
                      *(v204 - 1) = 0.0;
                      v204[2] = 1.0;
                      v203[1] = 1.0;
                      *v203 = 1.0;
                      *(float *)((char *)v204 + (char *)v174 - bot) = 1.0;
                      *(v203 - 2) = 1.0;
                      v202[7] = 0.0;
                      *(float *)((char *)v203 + (char *)v175 - (char *)v174) = 0.0;
                      v203 += 4;
                      *(float *)((char *)v204 + (char *)v175 - bot) = 0.0;
                      v204 += 4;
                      v202 += 4;
                      *v202 = 0.0;
                      --v201;
                    }
                    while ( v201 != 0 );
                  }
                  v205 = animData[9];
                  v206 = animData + 64;
                  v207 = 0;
                  if ( animData[9] == 0 )
                    goto LABEL_54;
                  while ( *v206 != v663->parentTblCrc.value )
                  {
                    ++v207;
                    ++v206;
                    if ( v207 >= v205 )
                      goto LABEL_54;
                  }
                  if ( v207 <= 0 )
LABEL_54:
                    v207 = 0;
                  v208 = idMD6Blend::DecodeRLE(
                           RLE: (const unsigned __int8 *)animData + animData[8 * v207 + 64 + v205],
                           sentinel: v181,
                           indices: v660);
                  v209 = 8 * v207;
                  v210 = v208;
                  v211 = v209 + v205;
                  v212 = idMD6Blend::DecodeRLE(
                           RLE: (const unsigned __int8 *)animData + animData[v211 + 65],
                           sentinel: v181,
                           indices: v661);
                  v214 = animData[v211 + 66];
                  v213 = v212;
                  v635 = idMD6Blend::DecodeRLE(
                           RLE: (const unsigned __int8 *)animData + v214,
                           sentinel: v181,
                           indices: v662);
                  idMD6Blend::DecodeConstantR(
                    jointsR: v660,
                    numJointsR: v210,
                    inR: (const __int16 *)((char *)animData + animData[10]),
                    outR: (float *)bot);
                  idMD6Blend::DecodeConstantST(
                    joints: v661,
                    numJoints: v213,
                    in: (const float *)((char *)animData + animData[11]),
                    out: v174);
                  idMD6Blend::DecodeConstantST(
                    joints: v662,
                    numJoints: v635,
                    in: (const float *)((char *)animData + animData[12]),
                    out: v175);
                  v215 = animData[9] + v209;
                  v189 = idMD6Blend::DecodeRLE(
                           RLE: (const unsigned __int8 *)animData + animData[v215 + 68],
                           sentinel: v181,
                           indices: v660);
                  v216 = idMD6Blend::DecodeRLE(
                           RLE: (const unsigned __int8 *)animData + animData[v215 + 69],
                           sentinel: v181,
                           indices: v661);
                  v217 = v215 + 70;
                  v197 = v216;
                  v187 = idMD6Blend::DecodeRLE(
                           RLE: (const unsigned __int8 *)animData + animData[v217],
                           sentinel: v181,
                           indices: v662);
                }
                idMD6Blend::DecodeFrameSetR(
                  joints: v660,
                  numJoints: v189,
                  frame: frameStart,
                  numFrames: frameRange,
                  fraction: 0.0,
                  firstKeys: v196,
                  rangeKeys: v191,
                  nextKeys: v190,
                  frameBits: v194,
                  a10,
                  a11,
                  a12,
                  a13,
                  a14,
                  a15,
                  a16,
                  out: v312,
                  a18: (int)v326,
                  a19: (int)v340,
                  a20: (int)v354,
                  a21: (int)v368,
                  a22: (int)v382,
                  a23: v396,
                  a24: (unsigned int)v410,
                  a25: v424,
                  a26: v438,
                  a27: v452,
                  a28: *(float *)&v466,
                  a29: v480,
                  a30: v494,
                  a31: v508,
                  a32: (int)v522,
                  a33: (int)v536,
                  a34: v550,
                  a35: v564,
                  a36: v192,
                  a37: (int)v578,
                  a38: (int)bot);
                idMD6Blend::DecodeFrameSetST(
                  joints: v661,
                  numJoints: v197,
                  frame: frameStart,
                  numFrames: frameRange,
                  fraction: 0.0,
                  firstKeys: v218,
                  rangeKeys: v193,
                  nextKeys: v198,
                  frameBits: v652,
                  a10: v225,
                  a11: v224,
                  a12: v223,
                  a13: v222,
                  a14: v221,
                  a15: v220,
                  a16: v219,
                  out: v323,
                  a18: v337,
                  a19: v351,
                  a20: v365,
                  a21: v379,
                  a22: v393,
                  a23: v407,
                  a24: v421,
                  a25: v435,
                  a26: v449,
                  a27: v463,
                  a28: v477,
                  a29: v491,
                  a30: v505,
                  a31: v519,
                  a32: v533,
                  a33: v547,
                  a34: v561,
                  a35: v575,
                  a36: v646,
                  a37: v584,
                  a38: (int)v174);
                idMD6Blend::DecodeFrameSetST(
                  joints: v662,
                  numJoints: v187,
                  frame: frameStart,
                  numFrames: frameRange,
                  fraction: 0.0,
                  firstKeys: v648,
                  rangeKeys: v653,
                  nextKeys: v650,
                  frameBits: v654,
                  a10: v232,
                  a11: v231,
                  a12: v230,
                  a13: v229,
                  a14: v228,
                  a15: v227,
                  a16: v226,
                  out: v324,
                  a18: v338,
                  a19: v352,
                  a20: v366,
                  a21: v380,
                  a22: v394,
                  a23: v408,
                  a24: v422,
                  a25: v436,
                  a26: v450,
                  a27: v464,
                  a28: v478,
                  a29: v492,
                  a30: v506,
                  a31: v520,
                  a32: v534,
                  a33: v548,
                  a34: v562,
                  a35: v576,
                  a36: (const unsigned __int8 *)v648,
                  a37: v585,
                  a38: (int)v175);
                idMD6Blend::AddRST(
                  numJoints: v632,
                  alpha: v200,
                  filter: v645,
                  aR: v629,
                  aS: v171,
                  aT: v643,
                  aW: v641,
                  bR: v640,
                  bS: (const float *)bot,
                  a10: v239,
                  a11: v238,
                  a12: v237,
                  a13: v236,
                  a14: v235,
                  a15: v234,
                  a16: v233,
                  bT: v325,
                  bW: v339,
                  outR: v353,
                  outS: v367,
                  outT: v381,
                  outW: v395,
                  a23: v409,
                  a24: v423,
                  a25: v437,
                  a26: v451,
                  a27: v465,
                  a28: v479,
                  a29: v493,
                  a30: v507,
                  a31: v521,
                  a32: v535,
                  a33: v549,
                  a34: v563,
                  a35: v577,
                  a36: (int)v174,
                  a37: v586,
                  a38: (int)v175,
                  a39: v587,
                  a40: (int)v645,
                  a41: (int)v593,
                  a42: (int)v171,
                  a43: (int)v599,
                  bS_0: v643,
                  a45: (int)v605,
                  bTa: (const float *)v641,
                  a47: (int)v611,
                  bWa: (const unsigned __int8 *)v640);
                skeleton = v663;
                stack = v665;
                LOWORD(frameStart) = v627;
              }
              v627 = (__int16)(frameStart + 1);
              LOWORD(frameStart) = v627;
              v199 = v627;
            }
            while ( v627 < v633 );
          }
        }
        end = stack->end;
        stack->bot -= v647;
        stack->top = end;
      }
      else if ( op == OP_POP_AND_BLEND )
      {
        filterGroup = v50->blendInfo.filterGroup;
        v64 = &stack->bot[-((v61 + 15) & 0xFFFFFFF0)];
        stack->bot = v64;
        v65 = (const float *)&v64[-v61];
        v628 = (const float *)&v64[v59];
        v626 = (const float *)&v62[(_DWORD)v64];
        v66 = (const unsigned __int8 *)&v64[v55 - v61];
        v67 = (unsigned __int8 *)&v64[v54 - v61];
        v630 = (float *)&v60[(_DWORD)v64];
        v69 = (const float *)&v64[v56 - v61];
        v70 = (const unsigned __int8 *)&v64[v58 - v61];
        v71 = (const float *)&v64[v53 - v61];
        v72 = (const float *)&v64[v53];
        v73 = (const float *)&v64[v59 - v61];
        v74 = (float *)&v64[(_DWORD)v60 - v61];
        v75 = (const float *)&v64[(_DWORD)v62 - v61];
        v68 = (const float *)&v64[v57 - v61];
        v76 = (const unsigned __int8 *)&v64[v55];
        v77 = (const unsigned __int8 *)&v64[v54];
        v78 = (const float *)&v64[v57];
        v79 = (const float *)&v64[v56];
        v80 = (const unsigned __int8 *)&v64[v58];
        v81 = (const float *)((char *)&skeleton->size + skeleton->jointWeightOffsets[filterGroup]);
        if ( skeleton->jointWeightOffsets[filterGroup] == 0 )
          v81 = nullptr;
        if ( v625 == 0
          || (v82 = skeleton->userWeightOffsets[filterGroup],
              v84 = v82 != 0,
              v83 = (const float *)((char *)&skeleton->size + v82),
              !v84) )
        {
          v83 = nullptr;
        }
        v621 = v83;
        currentAlpha = v624->blendInfo.currentAlpha;
        v86 = currentAlpha;
        if ( v624->blendInfo.originBlend != 0 )
          v86 = idMD6Blend::originBlendAlphas[v624->blendInfo.originBlend];
        if ( (unsigned int)v624->blendInfo.op - 1 <= 8 )
        {
          switch ( v624->blendInfo.op )
          {
            case 1u:
              goto LABEL_25;
            case 2u:
              if ( *a44 == 0 )
              {
                HIDWORD(v87) = originOffset;
                v88 = v665->top - 0x2000;
                v665->top = v88;
                LODWORD(v87) = a36;
                idMD6Blend::TransformLocalJointsToModelMatrices(
                  skeleton: v663,
                  temp: v88,
                  tempSize: 0x2000u,
                  mods: a38,
                  numMods: a40,
                  originOffset: v87,
                  addOffset: (bool)v312,
                  inR: v326,
                  inS: v340,
                  inT: v354,
                  outMatrices: v368,
                  quatTemp: v382,
                  a13: v396,
                  a14: (int)v410,
                  a15: v424,
                  a16: v438,
                  a17: v452,
                  a18: v466,
                  a19: v480,
                  a20: v494,
                  a21: v508,
                  a22: (int)v522,
                  a23: (int)v536,
                  a24: v550,
                  a25: v564,
                  a26: (int)v65,
                  a27: v578,
                  a28: (int)v71,
                  a29: v587,
                  a30: (int)v66,
                  a31: v593,
                  a32: (int)jointModsa,
                  a33: v599,
                  a34: 0,
                  inRa: v605);
                v665->top = v665->end;
                *a44 = 1;
              }
LABEL_25:
              idMD6Blend::LerpRST(
                numJoints: v620,
                alpha: currentAlpha,
                filter: v60,
                aR: v81,
                aS: v65,
                aT: v71,
                aW: v66,
                bR: v73,
                bS: (const float *)v64,
                a10,
                a11,
                a12,
                a13,
                a14,
                a15,
                a16,
                bT: v312,
                bW: (const unsigned __int8 *)v326,
                outR: v340,
                outS: v354,
                outT: v368,
                outW: *(float *)&v382,
                a23: v396,
                a24: v410,
                a25: v424,
                a26: v438,
                a27: v452,
                a28: v466,
                a29: v480,
                a30: v494,
                a31: v508,
                a32: v522,
                a33: (int)v536,
                a34: v550,
                a35: v564,
                a36: (int)v72,
                a37: (int)v578,
                a38: (int)v76,
                a39: v587,
                a40: (int)v628,
                a41: (int)v593,
                a42: (int)v65,
                a43: (int)v599,
                bS_0: v71,
                a45: (int)v605,
                bTa: (const float *)v66,
                a47: (int)v611,
                bWa: (const unsigned __int8 *)v73);
              idMD6Blend::LerpU(
                numUserChannels: v625,
                alpha: v97,
                filter: v89,
                aU: v621,
                aW: v67,
                bU: v74,
                bW: v77,
                outU: v630,
                outW: v67,
                a10: v96,
                a11: v95,
                a12: v94,
                a13: v93,
                a14: v92,
                a15: v91,
                a16: v90,
                a17: v313,
                a18: v327,
                a19: v341,
                a20: v355,
                a21: v369,
                a22: v383,
                a23: v397,
                a24: v411,
                a25: v425,
                a26: v439,
                a27: v453,
                a28: v467,
                a29: v481,
                a30: v495,
                a31: v509,
                a32: v523,
                a33: v537,
                a34: v551,
                a35: v565,
                a36: (int)v74);
              idMD6Blend::LerpRST(
                numJoints: 2u,
                alpha: v86,
                filter: v98,
                aR: v81,
                aS: v68,
                aT: v69,
                aW: v70,
                bR: v75,
                bS: v78,
                a10: v105,
                a11: v104,
                a12: v103,
                a13: v102,
                a14: v101,
                a15: v100,
                a16: v99,
                bT: v314,
                bW: v328,
                outR: v342,
                outS: v356,
                outT: v370,
                outW: v384,
                a23: v398,
                a24: v412,
                a25: v426,
                a26: v440,
                a27: v454,
                a28: v468,
                a29: v482,
                a30: v496,
                a31: v510,
                a32: v524,
                a33: v538,
                a34: v552,
                a35: v566,
                a36: (int)v79,
                a37: v579,
                a38: (int)v80,
                a39: v588,
                a40: (int)v626,
                a41: v594,
                a42: (int)v68,
                a43: v600,
                bS_0: v69,
                a45: v606,
                bTa: (const float *)v70,
                a47: v612,
                bWa: (const unsigned __int8 *)v75);
              break;
            case 3u:
              idMD6Blend::AddRST(
                numJoints: v620,
                alpha: currentAlpha,
                filter: v60,
                aR: v81,
                aS: (const float *)v64,
                aT: v72,
                aW: v76,
                bR: v628,
                bS: v65,
                a10,
                a11,
                a12,
                a13,
                a14,
                a15,
                a16,
                bT: v312,
                bW: (const unsigned __int8 *)v326,
                outR: v340,
                outS: v354,
                outT: v368,
                outW: *(float *)&v382,
                a23: v396,
                a24: (int)v410,
                a25: v424,
                a26: v438,
                a27: v452,
                a28: v466,
                a29: v480,
                a30: v494,
                a31: v508,
                a32: v522,
                a33: (int)v536,
                a34: v550,
                a35: v564,
                a36: (int)v71,
                a37: (int)v578,
                a38: (int)v66,
                a39: v587,
                a40: (int)v73,
                a41: (int)v593,
                a42: (int)v65,
                a43: (int)v599,
                bS_0: v71,
                a45: (int)v605,
                bTa: (const float *)v66,
                a47: (int)v611,
                bWa: (const unsigned __int8 *)v73);
              idMD6Blend::AddSubU(
                numUserChannels: v625,
                alpha: v114,
                filter: v106,
                aU: v621,
                aW: v77,
                bU: v630,
                bW: v67,
                outU: v74,
                outW: v67,
                a10: v113,
                a11: v112,
                a12: v111,
                a13: v110,
                a14: v109,
                a15: v108,
                a16: v107,
                a17: v315,
                a18: v329,
                a19: v343,
                a20: v357,
                a21: v371,
                a22: v385,
                a23: v399,
                a24: v413,
                a25: v427,
                a26: v441,
                a27: v455,
                a28: v469,
                a29: v483,
                a30: v497,
                a31: v511,
                a32: v525,
                a33: v539,
                a34: v553,
                a35: v567,
                a36: (int)v74);
              idMD6Blend::AddRST(
                numJoints: 2u,
                alpha: v86,
                filter: v115,
                aR: v81,
                aS: v78,
                aT: v79,
                aW: v80,
                bR: v626,
                bS: v68,
                a10: v122,
                a11: v121,
                a12: v120,
                a13: v119,
                a14: v118,
                a15: v117,
                a16: v116,
                bT: v316,
                bW: v330,
                outR: v344,
                outS: v358,
                outT: v372,
                outW: v386,
                a23: v400,
                a24: v414,
                a25: v428,
                a26: v442,
                a27: v456,
                a28: v470,
                a29: v484,
                a30: v498,
                a31: v512,
                a32: v526,
                a33: v540,
                a34: v554,
                a35: v568,
                a36: (int)v69,
                a37: v580,
                a38: (int)v70,
                a39: v589,
                a40: (int)v75,
                a41: v595,
                a42: (int)v68,
                a43: v601,
                bS_0: v69,
                a45: v607,
                bTa: (const float *)v70,
                a47: v613,
                bWa: (const unsigned __int8 *)v75);
              break;
            case 4u:
              goto LABEL_27;
            case 5u:
              idMD6Blend::SubRST(
                numJoints: v620,
                alpha: currentAlpha,
                aR: __SPAIR64__((unsigned int)v81, (unsigned int)v64),
                aS: v72,
                aT: (const float *)v76,
                aW: (const unsigned __int8 *)v628,
                bR: v65,
                bS: v312,
                a9: a10,
                a10: a11,
                a11: a12,
                a12: a13,
                a13: a14,
                a14: a15,
                a15: a16,
                bT: v326,
                bW: (const unsigned __int8 *)v340,
                outR: v354,
                outS: v368,
                outT: v382,
                outW: *(float *)&v396,
                a22: (int)v410,
                a23: v424,
                a24: v438,
                a25: v452,
                a26: v466,
                a27: v480,
                a28: v494,
                a29: v508,
                a30: (int)v522,
                a31: v536,
                a32: v550,
                a33: v564,
                a34: (int)v71,
                a35: (int)v578,
                a36: (int)v66,
                a37: v587,
                a38: (int)v73,
                a39: (unsigned int)v593,
                a40: (int)v65,
                a41: (int)v599,
                a42: (int)v71,
                bS_0: v605,
                a44: (int)v66,
                bTa: v611,
                a46: (int)v73,
                bWa: v617);
              idMD6Blend::AddSubU(
                numUserChannels: v625,
                alpha: -currentAlpha,
                filter: v140,
                aU: v621,
                aW: v77,
                bU: v630,
                bW: v67,
                outU: v74,
                outW: v67,
                a10: v147,
                a11: v146,
                a12: v145,
                a13: v144,
                a14: v143,
                a15: v142,
                a16: v141,
                a17: v319,
                a18: v333,
                a19: v347,
                a20: v361,
                a21: v375,
                a22: v389,
                a23: v403,
                a24: v417,
                a25: v431,
                a26: v445,
                a27: v459,
                a28: v473,
                a29: v487,
                a30: v501,
                a31: v515,
                a32: v529,
                a33: v543,
                a34: v557,
                a35: v571,
                a36: (int)v74);
              idMD6Blend::SubRST(
                numJoints: 2u,
                alpha: v86,
                aR: __SPAIR64__((unsigned int)v81, (unsigned int)v78),
                aS: v79,
                aT: (const float *)v80,
                aW: (const unsigned __int8 *)v626,
                bR: v68,
                bS: v320,
                a9: v154,
                a10: v153,
                a11: v152,
                a12: v151,
                a13: v150,
                a14: v149,
                a15: v148,
                bT: v334,
                bW: v348,
                outR: v362,
                outS: v376,
                outT: v390,
                outW: v404,
                a22: v418,
                a23: v432,
                a24: v446,
                a25: v460,
                a26: v474,
                a27: v488,
                a28: v502,
                a29: v516,
                a30: v530,
                a31: v544,
                a32: v558,
                a33: v572,
                a34: (int)v69,
                a35: v582,
                a36: (int)v70,
                a37: v591,
                a38: (int)v75,
                a39: v597,
                a40: (int)v68,
                a41: v603,
                a42: (int)v69,
                bS_0: v609,
                a44: (int)v70,
                bTa: v615,
                a46: (int)v75,
                bWa: v618);
              break;
            case 6u:
              idMD6Blend::SubRST(
                numJoints: v620,
                alpha: currentAlpha,
                aR: __SPAIR64__((unsigned int)v81, (unsigned int)v65),
                aS: v71,
                aT: (const float *)v66,
                aW: (const unsigned __int8 *)v73,
                bR: (const float *)v64,
                bS: v312,
                a9: a10,
                a10: a11,
                a11: a12,
                a12: a13,
                a13: a14,
                a14: a15,
                a15: a16,
                bT: v326,
                bW: (const unsigned __int8 *)v340,
                outR: v354,
                outS: v368,
                outT: v382,
                outW: *(float *)&v396,
                a22: (int)v410,
                a23: v424,
                a24: v438,
                a25: v452,
                a26: v466,
                a27: v480,
                a28: v494,
                a29: v508,
                a30: (int)v522,
                a31: v536,
                a32: v550,
                a33: v564,
                a34: (int)v72,
                a35: (int)v578,
                a36: (int)v76,
                a37: v587,
                a38: (int)v628,
                a39: (unsigned int)v593,
                a40: (int)v65,
                a41: (int)v599,
                a42: (int)v71,
                bS_0: v605,
                a44: (int)v66,
                bTa: v611,
                a46: (int)v73,
                bWa: v617);
              idMD6Blend::AddSubU(
                numUserChannels: v625,
                alpha: -currentAlpha,
                filter: v155,
                aU: v621,
                aW: v67,
                bU: v74,
                bW: v77,
                outU: v630,
                outW: v67,
                a10: v162,
                a11: v161,
                a12: v160,
                a13: v159,
                a14: v158,
                a15: v157,
                a16: v156,
                a17: v321,
                a18: v335,
                a19: v349,
                a20: v363,
                a21: v377,
                a22: v391,
                a23: v405,
                a24: v419,
                a25: v433,
                a26: v447,
                a27: v461,
                a28: v475,
                a29: v489,
                a30: v503,
                a31: v517,
                a32: v531,
                a33: v545,
                a34: v559,
                a35: v573,
                a36: (int)v74);
              idMD6Blend::SubRST(
                numJoints: 2u,
                alpha: v86,
                aR: __SPAIR64__((unsigned int)v81, (unsigned int)v68),
                aS: v69,
                aT: (const float *)v70,
                aW: (const unsigned __int8 *)v75,
                bR: v78,
                bS: v322,
                a9: v169,
                a10: v168,
                a11: v167,
                a12: v166,
                a13: v165,
                a14: v164,
                a15: v163,
                bT: v336,
                bW: v350,
                outR: v364,
                outS: v378,
                outT: v392,
                outW: v406,
                a22: v420,
                a23: v434,
                a24: v448,
                a25: v462,
                a26: v476,
                a27: v490,
                a28: v504,
                a29: v518,
                a30: v532,
                a31: v546,
                a32: v560,
                a33: v574,
                a34: (int)v79,
                a35: v583,
                a36: (int)v80,
                a37: v592,
                a38: (int)v626,
                a39: v598,
                a40: (int)v68,
                a41: v604,
                a42: (int)v69,
                bS_0: v610,
                a44: (int)v70,
                bTa: v616,
                a46: (int)v75,
                bWa: v619);
              break;
            case 8u:
LABEL_27:
              idMD6Blend::AddRST(
                numJoints: v620,
                alpha: currentAlpha,
                filter: v60,
                aR: v81,
                aS: v65,
                aT: v71,
                aW: v66,
                bR: v73,
                bS: (const float *)v64,
                a10,
                a11,
                a12,
                a13,
                a14,
                a15,
                a16,
                bT: v312,
                bW: (const unsigned __int8 *)v326,
                outR: v340,
                outS: v354,
                outT: v368,
                outW: *(float *)&v382,
                a23: v396,
                a24: (int)v410,
                a25: v424,
                a26: v438,
                a27: v452,
                a28: v466,
                a29: v480,
                a30: v494,
                a31: v508,
                a32: v522,
                a33: (int)v536,
                a34: v550,
                a35: v564,
                a36: (int)v72,
                a37: (int)v578,
                a38: (int)v76,
                a39: v587,
                a40: (int)v628,
                a41: (int)v593,
                a42: (int)v65,
                a43: (int)v599,
                bS_0: v71,
                a45: (int)v605,
                bTa: (const float *)v66,
                a47: (int)v611,
                bWa: (const unsigned __int8 *)v73);
              idMD6Blend::AddSubU(
                numUserChannels: v625,
                alpha: v131,
                filter: v123,
                aU: v621,
                aW: v67,
                bU: v74,
                bW: v77,
                outU: v630,
                outW: v67,
                a10: v130,
                a11: v129,
                a12: v128,
                a13: v127,
                a14: v126,
                a15: v125,
                a16: v124,
                a17: v317,
                a18: v331,
                a19: v345,
                a20: v359,
                a21: v373,
                a22: v387,
                a23: v401,
                a24: v415,
                a25: v429,
                a26: v443,
                a27: v457,
                a28: v471,
                a29: v485,
                a30: v499,
                a31: v513,
                a32: v527,
                a33: v541,
                a34: v555,
                a35: v569,
                a36: (int)v74);
              idMD6Blend::AddRST(
                numJoints: 2u,
                alpha: v86,
                filter: v132,
                aR: v81,
                aS: v68,
                aT: v69,
                aW: v70,
                bR: v75,
                bS: v78,
                a10: v139,
                a11: v138,
                a12: v137,
                a13: v136,
                a14: v135,
                a15: v134,
                a16: v133,
                bT: v318,
                bW: v332,
                outR: v346,
                outS: v360,
                outT: v374,
                outW: v388,
                a23: v402,
                a24: v416,
                a25: v430,
                a26: v444,
                a27: v458,
                a28: v472,
                a29: v486,
                a30: v500,
                a31: v514,
                a32: v528,
                a33: v542,
                a34: v556,
                a35: v570,
                a36: (int)v79,
                a37: v581,
                a38: (int)v80,
                a39: v590,
                a40: (int)v626,
                a41: v596,
                a42: (int)v68,
                a43: v602,
                bS_0: v69,
                a45: v608,
                bTa: (const float *)v70,
                a47: v614,
                bWa: (const unsigned __int8 *)v75);
              break;
            default:
              goto LABEL_25;
          }
LABEL_124:
          stack = v665;
          skeleton = v663;
        }
      }
      v50 = v624 + 1;
      op = v624[1].op;
      ++v624;
      if ( op == OP_END )
        goto LABEL_126;
      v62 = v644;
      v60 = v651;
      v59 = v638 + 432;
      v61 = v634;
      v57 = v638;
      v58 = v638 + 288;
      v55 = v642;
      v54 = v637;
      v53 = v649;
      v56 = v638 + 144;
    }
    v241 = stack->bot;
    v242 = &v241[v57];
    v243 = &v241[v56];
    v244 = 2;
    v245 = &v241[v58];
    stack->bot = &v241[(v61 + 15) & 0xFFFFFFF0];
    v246 = (float *)&v241[v57 + 4];
    v247 = (float *)&v241[v55];
    v248 = (float *)&v241[v54];
    v250 = (char *)&v62[(_DWORD)v241];
    v251 = &v241[v53];
    v253 = (float *)&v241[v58 - 16];
    v254 = (float *)&v241[v56 + 8];
    v255 = v246;
    v256 = (float *)(v56 - v57);
    v249 = &v241[v59];
    v257 = v58 - v57;
    v258 = (char *)(&v241[v58] - v243);
    v252 = (unsigned __int8 *)&v60[(_DWORD)v241];
    do
    {
      v255[1] = 0.0;
      *v255 = 0.0;
      *(v255 - 1) = 0.0;
      v255[2] = 1.0;
      v254[1] = 1.0;
      *v254 = 1.0;
      *(float *)((char *)v255 + (_DWORD)v256) = 1.0;
      *(v254 - 2) = 1.0;
      v253[7] = 0.0;
      *(float *)((char *)v254 + (_DWORD)v258) = 0.0;
      v254 += 4;
      *(float *)((char *)v255 + v257) = 0.0;
      v255 += 4;
      v253 += 4;
      *v253 = 0.0;
      --v244;
    }
    while ( v244 != 0 );
    flags = v50->frameInfo.flags;
    v260 = v50->frameInfo.animData;
    v623 = flags;
    if ( v260 == nullptr )
    {
      if ( (flags & 1) != 0 && (v296 = &v241[-v61], (unsigned int)&v241[-v61] >= temp) )
      {
        v297 = v634;
        v298 = v241;
      }
      else
      {
        idMD6Blend::DecodeSkeletonFrame(
          skeleton: v663,
          stackR: (const float *)v241,
          stackS: (float *)&v241[v53],
          stackT: v247,
          stackU: v248);
        v299 = v624->frameInfo.weightGroup >= 8u ? 0 : v624->frameInfo.weightGroup;
        v300 = 2 * (v299 + 10);
        v301 = *(unsigned __int16 *)((char *)&v663->size + v300);
        v302 = (char *)v663 + v301;
        if ( *(unsigned __int16 *)((char *)&v663->size + v300) == 0 )
          v302 = nullptr;
        memcpy(Dst: v249, Src: v302, Size: v620);
        v303 = (char *)v663 + v301;
        if ( v301 == 0 )
          v303 = nullptr;
        v304 = v303[1];
        v305 = 2 * (v299 + 18);
        *v250 = *v303;
        v250[1] = v304;
        v296 = (char *)v663 + *(unsigned __int16 *)((char *)&v663->size + v305);
        if ( *(unsigned __int16 *)((char *)&v663->size + v305) == 0 )
          v296 = nullptr;
        v297 = v625;
        v298 = (char *)v252;
      }
      memcpy(Dst: v298, Src: v296, Size: v297);
      goto LABEL_117;
    }
    v261 = (flags & 0x20) != 0;
    if ( (flags & 0x20) == 0 )
    {
      idMD6Blend::DecodeAnimFrame(
        skeleton: v663,
        numPaddedJoints: v620,
        animData: v260,
        frameSetData: v624->frameInfo.frameSetData,
        frame: v624->frameInfo.frameSetFrame,
        frameFraction: v624->frameInfo.frameFraction,
        stackR: (float *)(unsigned __int16)v624->frameInfo.frameSetFrame,
        stackS: (float *)v241,
        stackT: (float *)&v241[v53],
        stackU: v312,
        a11: (int)v326,
        a12: (int)v340,
        a13: (int)v354,
        a14: (int)v368,
        a15: (int)v382,
        a16: v396,
        a17: (int)v410,
        a18: v424,
        a19: v438,
        a20: v452,
        a21: v466,
        a22: v480,
        a23: v494,
        a24: v508,
        a25: (int)v522,
        a26: (int)v536,
        a27: v550,
        a28: v564,
        a29: v247,
        a30: (int)v578,
        a31: v248);
      v262 = v620;
      v263 = v663;
      v264 = v624;
LABEL_93:
      weightGroup = v264->frameInfo.weightGroup;
      v287 = 2 * (weightGroup + 10);
      v288 = (unsigned __int8 *)v263 + *(unsigned __int16 *)((char *)&v263->size + v287);
      if ( *(unsigned __int16 *)((char *)&v263->size + v287) == 0 )
        v288 = nullptr;
      if ( v260->jointWeightsOffset != 0 )
      {
        v290 = (char *)v260 + v260->jointWeightsOffset;
        if ( v262 != 0 )
        {
          v291 = v262;
          v292 = v288;
          do
          {
            v293 = (unsigned __int16)(v292[v290 - (char *)v288] * *v292) >> 8;
            v292[v249 - (char *)v288] = v293;
            (v292++)[v250 - (char *)v288] = v293;
            --v291;
          }
          while ( v291 != 0 );
        }
      }
      else
      {
        memcpy(Dst: v249, Src: v288, Size: v262);
        v289 = v288[1];
        *v250 = *v288;
        v250[1] = v289;
      }
      if ( v625 != 0 )
      {
        v294 = 2 * (weightGroup + 18);
        v295 = (char *)v263 + *(unsigned __int16 *)((char *)&v263->size + v294);
        if ( *(unsigned __int16 *)((char *)&v263->size + v294) == 0 )
          v295 = nullptr;
        memcpy(Dst: v252, Src: v295, Size: v625);
      }
      if ( !v261 )
      {
        v250[1] = 0;
        *v250 = 0;
      }
LABEL_117:
      v306 = v624->frameInfo.animMods;
      if ( v306 != nullptr )
      {
        v307 = v624->frameInfo.animModsSize >> 6;
        idMD6Blend::ApplyAnimMods(
          skeleton: v663,
          animMods: v624->frameInfo.animMods,
          numAnimMods: v307,
          R: (const float *)v241,
          S: (const float *)v251,
          T: v247,
          U: v248);
        if ( (v623 & 2) != 0 )
        {
          memset(Dst: v249, Val: 0, Size: v620);
          if ( v307 != 0 )
          {
            p_joint = &v306[-1].joint;
            for ( i = v307; i != 0; --i )
            {
              p_joint += 32;
              v249[p_joint->value] = -1;
            }
          }
          v310 = v249[1];
          *v250 = *v249;
          v250[1] = v310;
        }
      }
      v665->top = v665->end;
      goto LABEL_124;
    }
    originFrameSetData = v50->frameInfo.originFrameSetData;
    v266 = (_cntlzw((unsigned int)originFrameSetData) & 0x20) != 0;
    if ( !v266 )
    {
      idMD6Blend::DecodeAnimFrame(
        skeleton: v663,
        numPaddedJoints: 8u,
        animData: v260,
        frameSetData: originFrameSetData,
        frame: v624->frameInfo.originFrame - originFrameSetData->frameStart,
        frameFraction: v624->frameInfo.originFrameFraction,
        stackR: (float *)originFrameSetData->frameStart,
        stackS: (float *)v242,
        stackT: (float *)v243,
        stackU: v312,
        a11: (int)v326,
        a12: (int)v340,
        a13: (int)v354,
        a14: (int)v368,
        a15: (int)v382,
        a16: v396,
        a17: (int)v410,
        a18: v424,
        a19: v438,
        a20: v452,
        a21: v466,
        a22: v480,
        a23: v494,
        a24: v508,
        a25: (int)v522,
        a26: (int)v536,
        a27: v550,
        a28: v564,
        a29: (float *)v245,
        a30: (int)v578,
        a31: nullptr);
      *(_OWORD *)v656 = *(_OWORD *)v242;
      *(_OWORD *)&v656[2] = *(_OWORD *)v243;
      *(_OWORD *)&v656[4] = *(_OWORD *)v245;
      v50 = v624;
    }
    v267 = v50->frameInfo.frameSetData;
    v263 = v663;
    v84 = !v266;
    v264 = v624;
    if ( !v84 )
    {
      idMD6Blend::DecodeAnimFrame(
        skeleton: v663,
        numPaddedJoints: 8u,
        animData: v260,
        frameSetData: v267,
        frame: v624->frameInfo.originFrame - v267->frameStart,
        frameFraction: v624->frameInfo.originFrameFraction,
        stackR: (float *)v267->frameStart,
        stackS: (float *)v242,
        stackT: (float *)v243,
        stackU: v312,
        a11: (int)v326,
        a12: (int)v340,
        a13: (int)v354,
        a14: (int)v368,
        a15: (int)v382,
        a16: v396,
        a17: (int)v410,
        a18: v424,
        a19: v438,
        a20: v452,
        a21: v466,
        a22: v480,
        a23: v494,
        a24: v508,
        a25: (int)v522,
        a26: (int)v536,
        a27: v550,
        a28: v564,
        a29: (float *)v245,
        a30: (int)v578,
        a31: nullptr);
      *(_OWORD *)v656 = *(_OWORD *)v242;
      *(_OWORD *)&v656[2] = *(_OWORD *)v243;
      *(_OWORD *)&v656[4] = *(_OWORD *)v245;
    }
    v262 = v620;
    idMD6Blend::DecodeAnimFrame(
      skeleton: v663,
      numPaddedJoints: v620,
      animData: v260,
      frameSetData: v267,
      frame: v624->frameInfo.frameSetFrame,
      frameFraction: v624->frameInfo.frameFraction,
      stackR: v256,
      stackS: (float *)v241,
      stackT: (float *)v251,
      stackU: v312,
      a11: (int)v326,
      a12: (int)v340,
      a13: (int)v354,
      a14: (int)v368,
      a15: (int)v382,
      a16: v396,
      a17: (int)v410,
      a18: v424,
      a19: v438,
      a20: v452,
      a21: v466,
      a22: v480,
      a23: v494,
      a24: v508,
      a25: (int)v522,
      a26: (int)v536,
      a27: v550,
      a28: v564,
      a29: v247,
      a30: (int)v578,
      a31: v248);
    *((_OWORD *)v242 + 1) = *(_OWORD *)v241;
    *((_OWORD *)v243 + 1) = *(_OWORD *)v251;
    *((_OWORD *)v245 + 1) = *(_OWORD *)v247;
    frame = v624->frameInfo.frame;
    originFrame = v624->frameInfo.originFrame;
    v270 = *(float *)v251;
    v271 = *((float *)v251 + 1);
    v272 = *((float *)v251 + 2);
    v273 = *((float *)v241 + 1);
    v274 = *((float *)v241 + 2);
    v275 = *((float *)v241 + 3);
    v276 = *((float *)v251 + 3);
    v277 = *v247;
    v278 = v247[1];
    v279 = v247[2];
    v280 = v247[3];
    v655[0] = *(float *)v241;
    v655[4] = v270;
    v655[5] = v271;
    v655[6] = v272;
    v655[1] = v273;
    v655[2] = v274;
    v655[3] = v275;
    v655[7] = v276;
    v655[8] = v277;
    v655[9] = v278;
    v655[10] = v279;
    v655[11] = v280;
    if ( originFrame > frame )
    {
      if ( (v623 & 0x40) == 0 )
      {
        _idMD6Blend::ExecuteCommandsInternal_::_2_::local_t::SubD(a: v260->endDelta, b: (const float *)v656, r: v658);
        startDelta = v260->startDelta;
        endDelta = v655;
LABEL_78:
        _idMD6Blend::ExecuteCommandsInternal_::_2_::local_t::SubD(a: endDelta, b: startDelta, r: v659);
        _idMD6Blend::ExecuteCommandsInternal_::_2_::local_t::AddD(a: v659, b: v658, r: (float *)v657);
LABEL_81:
        *(_OWORD *)v242 = *(_OWORD *)v657;
        *(_OWORD *)v243 = *(_OWORD *)&v657[2];
        *(_OWORD *)v245 = *(_OWORD *)&v657[4];
        v285 = v260->flags;
        if ( (v285 & 2) != 0 )
        {
          *v247 = 0.0;
        }
        else
        {
          *((float *)v245 + 4) = 0.0;
          *(float *)v245 = 0.0;
        }
        if ( (v285 & 4) != 0 )
        {
          v247[1] = 0.0;
        }
        else
        {
          *((float *)v245 + 5) = 0.0;
          *((float *)v245 + 1) = 0.0;
        }
        if ( (v285 & 8) != 0 )
        {
          v247[2] = 0.0;
        }
        else
        {
          *((float *)v245 + 6) = 0.0;
          *((float *)v245 + 2) = 0.0;
        }
        if ( (v285 & 0x10) != 0 )
        {
          *((float *)v241 + 2) = 0.0;
          *((float *)v241 + 1) = 0.0;
          *(float *)v241 = 0.0;
          *((float *)v241 + 3) = 1.0;
        }
        else
        {
          *((float *)v242 + 6) = 0.0;
          *((float *)v242 + 5) = 0.0;
          *((float *)v242 + 4) = 0.0;
          *((float *)v242 + 7) = 1.0;
          *((float *)v242 + 2) = 0.0;
          *v246 = 0.0;
          *(float *)v242 = 0.0;
          *((float *)v242 + 3) = 1.0;
        }
        goto LABEL_93;
      }
      goto LABEL_79;
    }
    if ( frame != 0 )
    {
      if ( (v623 & 0x40) != 0 )
      {
        if ( originFrame < frame )
        {
          _idMD6Blend::ExecuteCommandsInternal_::_2_::local_t::SubD(
            a: (const float *)v656,
            b: v260->startDelta,
            r: v658);
          startDelta = v655;
          endDelta = v260->endDelta;
          goto LABEL_78;
        }
        goto LABEL_79;
      }
      v283 = (const float *)v656;
      v284 = v655;
    }
    else
    {
      if ( (v623 & 0x40) != 0 )
      {
LABEL_79:
        v284 = (const float *)v656;
        v283 = v655;
        goto LABEL_80;
      }
      v283 = (const float *)v656;
      v284 = v655;
    }
LABEL_80:
    _idMD6Blend::ExecuteCommandsInternal_::_2_::local_t::SubD(a: v284, b: v283, r: (float *)v657);
    goto LABEL_81;
  }
LABEL_126:
  v311 = (unsigned int)&v665->bot[-((v634 + 15) & 0xFFFFFFF0)];
  v665->bot = (char *)v311;
  *numJointModsa = *(_OWORD *)(v311 + v638);
  numJointModsa[1] = *(_OWORD *)(v311 + v639);
  numJointModsa[2] = *(_OWORD *)(v311 + v636);
  numJointModsa[3] = *(_OWORD *)(v311 + v638 + 16);
  numJointModsa[4] = *(_OWORD *)(v311 + v639 + 16);
  numJointModsa[5] = *(_OWORD *)(v311 + v636 + 16);
  if ( jointRemapa != nullptr )
    memcpy(Dst: jointRemapa, Src: (const void *)(v311 + v637), Size: 4 * v625);
}


// ========================================================================
// ?ExecuteCommands@idMD6Blend@@SAXPIBVidMD6SkelData@@PIAXIPIBUmd6AnimCommand_t@@I_NV?$idIndex@FW4invalidJointIndex_t@@@@_NPIBM5PIBUjointMod_t@1@I66PBEPIAM99PIAUmd6OriginDelta_t@@9I@Z
// EA  : 0x82823C80
// RVA : 0x00823C80
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::ExecuteCommands(
        const idMD6SkelData *skeleton,
        char *temp,
        unsigned int tempSize,
        const md6AnimCommand_t *cmds,
        unsigned int numCmds,
        bool clearOriginTransform,
        const idIndex<short,enum invalidJointIndex_t> *boundsSkipJoint,
        bool useDualquat,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        const float *originOffset,
        bool addOffset,
        const idMD6Blend::jointMod_t *jointMods,
        unsigned int numJointMods,
        const float *invertedBasePose,
        const float *invertedBasePoseQuat,
        const unsigned __int8 *jointRemap,
        float *refPose,
        float *finalPose,
        float *renderPose,
        md6OriginDelta_t *originDelta,
        float *userChannels,
        unsigned int dmaTag,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        const float *a36,
        int a37,
        unsigned __int8 a38,
        int a39,
        const idMD6Blend::jointMod_t *a40,
        int a41,
        unsigned int a42,
        int a43,
        const float *originOffseta,
        int a45,
        const float *a46,
        int a47,
        const unsigned __int8 *jointModsa,
        int a49,
        const idMD6Blend::jointMod_t *numJointModsa,
        int a51,
        const float *invertedBasePosea,
        int a53,
        float *invertedBasePoseQuata,
        int a55,
        unsigned __int8 *jointRemapa,
        int a57,
        float *refPosea)
{
  char *bot; // r30
  char *v62; // r24
  int v63; // r11
  int v64; // r10
  char *v65; // r23
  int v66; // r16
  char *v67; // r22
  const idMD6SkelData *v68; // r3
  bool v69; // [sp+Bh] [-145h]
  bool v70; // [sp+Bh] [-145h]
  const idMD6Blend::jointMod_t *v71; // [sp+Ch] [-144h]
  const float *v72; // [sp+Ch] [-144h]
  unsigned int v73; // [sp+10h] [-140h]
  const float *v74; // [sp+10h] [-140h]
  const unsigned __int8 *v75; // [sp+14h] [-13Ch]
  const float *v76; // [sp+14h] [-13Ch]
  bool *v77; // [sp+18h] [-138h]
  float *v78; // [sp+18h] [-138h]
  float *v79; // [sp+1Ch] [-134h]
  float *v80; // [sp+1Ch] [-134h]
  md6OriginDelta_t *v81; // [sp+20h] [-130h]
  int v82; // [sp+20h] [-130h]
  float *v83; // [sp+24h] [-12Ch]
  int v84; // [sp+24h] [-12Ch]
  unsigned int v85; // [sp+28h] [-128h]
  int v86; // [sp+28h] [-128h]
  int v87; // [sp+2Ch] [-124h]
  int v88; // [sp+2Ch] [-124h]
  int v89; // [sp+30h] [-120h]
  int v90; // [sp+30h] [-120h]
  int v91; // [sp+34h] [-11Ch]
  int v92; // [sp+34h] [-11Ch]
  int v93; // [sp+38h] [-118h]
  int v94; // [sp+38h] [-118h]
  int v95; // [sp+3Ch] [-114h]
  int v96; // [sp+3Ch] [-114h]
  int v97; // [sp+40h] [-110h]
  int v98; // [sp+40h] [-110h]
  int v99; // [sp+44h] [-10Ch]
  int v100; // [sp+44h] [-10Ch]
  int v101; // [sp+48h] [-108h]
  int v102; // [sp+48h] [-108h]
  int v103; // [sp+4Ch] [-104h]
  int v104; // [sp+4Ch] [-104h]
  int v105; // [sp+50h] [-100h]
  int v106; // [sp+50h] [-100h]
  int v107; // [sp+58h] [-F8h]
  float *v108; // [sp+58h] [-F8h]
  int v109; // [sp+60h] [-F0h]
  int v110; // [sp+60h] [-F0h]
  int v111; // [sp+68h] [-E8h]
  float *v112; // [sp+68h] [-E8h]
  int v113; // [sp+70h] [-E0h]
  float *v114; // [sp+70h] [-E0h]
  int v115; // [sp+78h] [-D8h]
  float *v116; // [sp+78h] [-D8h]
  int v117; // [sp+80h] [-D0h]
  int v118; // [sp+88h] [-C8h]
  _BYTE v119[16]; // [sp+A0h] [-B0h] BYREF
  idMD6Blend::doubleStack_t v120; // [sp+B0h] [-A0h] BYREF

  v120.bot = temp;
  v120.start = temp;
  v120.top = &temp[tempSize];
  v120.end = &temp[tempSize];
  v119[0] = 0;
  idMD6Blend::ExecuteCommandsInternal(
    skeleton,
    (unsigned int)temp,
    stack: &v120,
    cmds,
    numCmds,
    clearOriginTransform,
    boundsSkipJoint,
    originOffset: a36,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    a15,
    a16,
    addOffset: v69,
    jointMods: v71,
    numJointMods: v73,
    jointRemap: v75,
    generatedReferencePose: v77,
    refPose: v79,
    originDelta: v81,
    userChannels: v83,
    dmaTag: v85,
    a26: v87,
    a27: v89,
    a28: v91,
    a29: v93,
    a30: v95,
    a31: v97,
    a32: v99,
    a33: v101,
    a34: v103,
    a35: v105,
    a36: a38,
    a37: v107,
    a38: a40,
    a39: v109,
    a40: a42,
    a41: v111,
    a42: (int)jointModsa,
    a43: v113,
    a44: v119,
    a45: v115,
    jointModsa: numJointModsa,
    a47: v117,
    numJointModsa: jointRemapa,
    a49: v118,
    jointRemapa: (unsigned __int8 *)refPosea);
  bot = v120.bot;
  v62 = v120.top - 0x2000;
  v63 = 16 * (((skeleton->numJoints + 7) & 0xFFF8) + 1);
  v64 = 32 * (((skeleton->numJoints + 7) & 0xFFF8) + 1);
  v65 = &v120.bot[v63];
  v66 = v64 + v63;
  v67 = &v120.bot[v64];
  if ( v119[0] == 0 )
    idMD6Blend::TransformLocalJointsToModelMatrices(
      skeleton,
      temp: v120.top - 0x2000,
      tempSize: 0x2000u,
      mods: a40,
      numMods: a42,
      originOffset: __SPAIR64__((unsigned int)a36, a38),
      addOffset: v70,
      inR: v72,
      inS: v74,
      inT: v76,
      outMatrices: v78,
      quatTemp: v80,
      a13: v82,
      a14: v84,
      a15: v86,
      a16: v88,
      a17: v90,
      a18: v92,
      a19: v94,
      a20: v96,
      a21: v98,
      a22: v100,
      a23: v102,
      a24: v104,
      a25: v106,
      a26: (int)v120.bot,
      a27: v108,
      a28: (int)&v120.bot[v63],
      a29: v110,
      a30: (int)v67,
      a31: v112,
      a32: (int)numJointModsa,
      a33: v114,
      a34: 0,
      inRa: v116);
  idMD6Blend::TransformLocalJointsToModelMatrices(
    skeleton,
    temp: v62,
    tempSize: 0x2000u,
    mods: a40,
    numMods: a42,
    originOffset: __SPAIR64__((unsigned int)a36, a38),
    addOffset: v70,
    inR: v72,
    inS: v74,
    inT: v76,
    outMatrices: v78,
    quatTemp: v80,
    a13: v82,
    a14: v84,
    a15: v86,
    a16: v88,
    a17: v90,
    a18: v92,
    a19: v94,
    a20: v96,
    a21: v98,
    a22: v100,
    a23: v102,
    a24: v104,
    a25: v106,
    a26: (int)bot,
    a27: v108,
    a28: (int)v65,
    a29: v110,
    a30: (int)v67,
    a31: v112,
    a32: (int)invertedBasePosea,
    a33: v114,
    a34: (int)&bot[v66],
    inRa: v116);
  idMD6Blend::CalculatePoseBounds(
    skeleton,
    finalPose: invertedBasePosea,
    boundsSkipJoint,
    originDelta: (md6OriginDelta_t *)jointRemapa);
  idMD6Blend::TransformModelMatrices(
    skeleton: v68,
    remap: jointModsa,
    inMatrices1: invertedBasePosea,
    inMatrices2: originOffseta,
    invertedRefPoseQuat: a46,
    outMatrices: invertedBasePoseQuata,
    useDualQuat: useDualquat,
    quatTemp: (float *)&bot[v66]);
}


// ========================================================================
// ?ExecuteCommandsToRSTU@idMD6Blend@@SAXPIBVidMD6SkelData@@PIAXIPIBUmd6AnimCommand_t@@I_NV?$idIndex@FW4invalidJointIndex_t@@@@PIBM_NPIBUjointMod_t@1@IPBEPIAM999PIAUmd6OriginDelta_t@@9I@Z
// EA  : 0x82823E00
// RVA : 0x00823E00
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blend.cpp
// ========================================================================

void __fastcall idMD6Blend::ExecuteCommandsToRSTU(
        const idMD6SkelData *skeleton,
        char *temp,
        unsigned int tempSize,
        const md6AnimCommand_t *cmds,
        unsigned int numCmds,
        bool clearOriginTransform,
        const idIndex<short,enum invalidJointIndex_t> *boundsSkipJoint,
        const float *originOffset,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        bool addOffset,
        const idMD6Blend::jointMod_t *jointMods,
        unsigned int numJointMods,
        const unsigned __int8 *jointRemap,
        float *finalPose,
        float *localR,
        float *localS,
        float *localT,
        md6OriginDelta_t *originDelta,
        float *userChannels,
        unsigned int dmaTag,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        unsigned __int8 a36,
        int a37,
        const idMD6Blend::jointMod_t *a38,
        int a39,
        unsigned int a40,
        int a41,
        int a42,
        int a43,
        const float *a44,
        int a45,
        const idMD6Blend::jointMod_t *jointModsa,
        int a47,
        void *numJointModsa,
        int a49,
        unsigned __int8 *jointRemapa,
        int a51,
        float *finalPosea,
        int a53,
        float *localRa)
{
  size_t v57; // r31
  char *bot; // r29
  char *v59; // r30
  char *v60; // r28
  bool v61; // [sp+Bh] [-125h]
  bool v62; // [sp+Bh] [-125h]
  const idMD6Blend::jointMod_t *v63; // [sp+Ch] [-124h]
  const float *v64; // [sp+Ch] [-124h]
  unsigned int v65; // [sp+10h] [-120h]
  const float *v66; // [sp+10h] [-120h]
  const unsigned __int8 *v67; // [sp+14h] [-11Ch]
  const float *v68; // [sp+14h] [-11Ch]
  bool *v69; // [sp+18h] [-118h]
  float *v70; // [sp+18h] [-118h]
  float *v71; // [sp+1Ch] [-114h]
  float *v72; // [sp+1Ch] [-114h]
  md6OriginDelta_t *v73; // [sp+20h] [-110h]
  int v74; // [sp+20h] [-110h]
  float *v75; // [sp+24h] [-10Ch]
  int v76; // [sp+24h] [-10Ch]
  unsigned int v77; // [sp+28h] [-108h]
  int v78; // [sp+28h] [-108h]
  int v79; // [sp+2Ch] [-104h]
  int v80; // [sp+2Ch] [-104h]
  int v81; // [sp+30h] [-100h]
  int v82; // [sp+30h] [-100h]
  int v83; // [sp+34h] [-FCh]
  int v84; // [sp+34h] [-FCh]
  int v85; // [sp+38h] [-F8h]
  int v86; // [sp+38h] [-F8h]
  int v87; // [sp+3Ch] [-F4h]
  int v88; // [sp+3Ch] [-F4h]
  int v89; // [sp+40h] [-F0h]
  int v90; // [sp+40h] [-F0h]
  int v91; // [sp+44h] [-ECh]
  int v92; // [sp+44h] [-ECh]
  int v93; // [sp+48h] [-E8h]
  int v94; // [sp+48h] [-E8h]
  int v95; // [sp+4Ch] [-E4h]
  int v96; // [sp+4Ch] [-E4h]
  int v97; // [sp+50h] [-E0h]
  int v98; // [sp+50h] [-E0h]
  int v99; // [sp+58h] [-D8h]
  float *v100; // [sp+58h] [-D8h]
  int v101; // [sp+60h] [-D0h]
  int v102; // [sp+60h] [-D0h]
  int v103; // [sp+68h] [-C8h]
  float *v104; // [sp+68h] [-C8h]
  int v105; // [sp+70h] [-C0h]
  float *v106; // [sp+70h] [-C0h]
  int v107; // [sp+78h] [-B8h]
  float *v108; // [sp+78h] [-B8h]
  int v109; // [sp+80h] [-B0h]
  int v110; // [sp+88h] [-A8h]
  char v111[16]; // [sp+A0h] [-90h] BYREF
  idMD6Blend::doubleStack_t v112; // [sp+B0h] [-80h] BYREF

  v112.bot = temp;
  v112.start = temp;
  v112.top = &temp[tempSize];
  v112.end = &temp[tempSize];
  v111[0] = 1;
  idMD6Blend::ExecuteCommandsInternal(
    skeleton,
    (unsigned int)temp,
    stack: &v112,
    cmds,
    numCmds,
    clearOriginTransform,
    boundsSkipJoint,
    originOffset,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    a15,
    a16,
    addOffset: v61,
    jointMods: v63,
    numJointMods: v65,
    jointRemap: v67,
    generatedReferencePose: v69,
    refPose: v71,
    originDelta: v73,
    userChannels: v75,
    dmaTag: v77,
    a26: v79,
    a27: v81,
    a28: v83,
    a29: v85,
    a30: v87,
    a31: v89,
    a32: v91,
    a33: v93,
    a34: v95,
    a35: v97,
    a36,
    a37: v99,
    a38,
    a39: v101,
    a40,
    a41: v103,
    a42,
    a43: v105,
    a44: v111,
    a45: v107,
    jointModsa: nullptr,
    a47: v109,
    numJointModsa: finalPosea,
    a49: v110,
    jointRemapa: (unsigned __int8 *)localRa);
  v57 = 16 * (((skeleton->numJoints + 7) & 0xFFF8) + 1);
  bot = v112.bot;
  v59 = &v112.bot[v57];
  v60 = &v112.bot[v57 + v57];
  idMD6Blend::TransformLocalJointsToModelMatrices(
    skeleton,
    temp: v112.top - 0x2000,
    tempSize: 0x2000u,
    mods: a38,
    numMods: a40,
    originOffset: __SPAIR64__((unsigned int)originOffset, a36),
    addOffset: v62,
    inR: v64,
    inS: v66,
    inT: v68,
    outMatrices: v70,
    quatTemp: v72,
    a13: v74,
    a14: v76,
    a15: v78,
    a16: v80,
    a17: v82,
    a18: v84,
    a19: v86,
    a20: v88,
    a21: v90,
    a22: v92,
    a23: v94,
    a24: v96,
    a25: v98,
    a26: (int)v112.bot,
    a27: v100,
    a28: (int)&v112.bot[v57],
    a29: v102,
    a30: (int)v60,
    a31: v104,
    a32: (int)a44,
    a33: v106,
    a34: 0,
    inRa: v108);
  idMD6Blend::CalculatePoseBounds(
    skeleton,
    finalPose: a44,
    boundsSkipJoint,
    originDelta: (md6OriginDelta_t *)finalPosea);
  memcpy(Dst: (void *)jointModsa, Src: bot, Size: v57);
  memcpy(Dst: numJointModsa, Src: v59, Size: v57);
  memcpy(Dst: jointRemapa, Src: v60, Size: v57);
}

