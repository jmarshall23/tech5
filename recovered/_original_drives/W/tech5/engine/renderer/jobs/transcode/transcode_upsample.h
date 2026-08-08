
// ========================================================================
// ?Sharpen4x4Center_Xenon@@YAXABU__vector4@@000U1@AAU1@222@Z
// EA  : 0x8292A7B8
// RVA : 0x0092A7B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_upsample.h
// ========================================================================

void __fastcall Sharpen4x4Center_Xenon(
        const __vector4 *b0,
        const __vector4 *b1,
        const __vector4 *b2,
        const __vector4 *b3,
        const __vector4 *amount,
        __vector4 *f0,
        __vector4 *f1,
        __vector4 *f2,
        __vector4 *f3)
{
  int v14; // [sp+0h] [-30h] BYREF
  int v15; // [sp+10h] [-20h] BYREF

  __asm { lvx128    v11, r0, r4 }
  __asm { lvx128    v10, r0, r5 }
  _R31 = f2;
  __asm { lvx128    v9, r0, r3 }
  __asm { lvx128    v8, r0, r6 }
  __asm { vpermwi128 v13, v11, 0x66 # 'f' }
  __asm { vpermwi128 v12, v10, 0x66 # 'f' }
  __asm
  {
    vsububs   v3, v13, v9
    vsububs   v7, v9, v13
  }
  _R5 = vector_byte_sharpen_threshold;
  _R11 = &v14;
  __asm { vsububs   v31, v12, v11 }
  _R10 = &v15;
  __asm
  {
    vsububs   v29, v12, v8
    vsububs   v6, v11, v12
    vor       v2, v3, v7
    lvx128    v0, r0, r5
    vsububs   v4, v8, v12
    vsububs   v30, v13, v10
    vsububs   v5, v10, v13
    vcmpgtub  v20, v2, v0
    vor       v24, v31, v6
    vsububm   v25, v3, v7
    vor       v23, v30, v5
    vsububm   v22, v30, v5
    vor       v21, v29, v4
    vcmpgtub  v16, v24, v0
    lvx128    v2, r0, r11
    vcmpgtub  v19, v23, v0
    vsububm   v18, v31, v6
    vperm     v9, v11, v9, v2
    vsububm   v17, v29, v4
    vperm     v28, v10, v11, v2
    lvx128    v29, r0, r7
    lvx128    v2, r0, r10
    vcmpgtub  v15, v21, v0
    vcmpgtub  v7, v7, v0
    vperm     v27, v10, v11, v2
    vsububs   v11, v9, v13
    vperm     v26, v8, v10, v2
    vsububs   v8, v13, v9
    vsububs   v2, v12, v28
    vsububs   v10, v28, v12
    vsububs   v9, v13, v27
    vsububs   v13, v27, v13
    vor       v14, v8, v11
    vsububm   v8, v8, v11
    vsububs   v3, v12, v26
    vor       v30, v9, v13
    vcmpgtub  v27, v14, v0
    vsububm   v28, v9, v13
    vcmpgtub  v31, v11, v0
    vcmpgtub  v24, v30, v0
    vcmpgtub  v30, v13, v0
    vor       v23, v2, v10
    vsububs   v12, v26, v12
    vcmpgtub  v5, v5, v0
    vand      v13, v25, v20
    vand      v11, v22, v19
    vand      v9, v8, v27
    vmrglb    v22, v7, v13
    vor       v21, v3, v12
    vmrghb    v20, v7, v13
    vand      v8, v28, v24
    vcmpgtub  v19, v23, v0
    vmrglb    v14, v5, v11
    vmrghb    v28, v5, v11
    vcmpgtub  v11, v6, v0
    vcmpgtub  v25, v21, v0
    vmrghb    v21, v31, v9
    vaddsws   v23, v20, v22
    vmrglb    v26, v30, v8
    vmrghb    v24, v30, v8
    vsububm   v3, v3, v12
    vmrglb    v22, v31, v9
    vaddsws   v20, v28, v14
    vcmpgtub  v8, v10, v0
    vsububm   v27, v2, v10
    vaddsws   v14, v24, v26
    vaddsws   v13, v21, v22
    vand      v10, v3, v25
    vcmpgtub  v7, v12, v0
    vaddsws   v6, v20, v14
    vaddsws   v5, v23, v13
    vcmpgtub  v9, v4, v0
    vand      v0, v18, v16
    vmrglb    v26, v7, v10
    vand      v12, v27, v19
    vmrghb    v24, v7, v10
    vaddsws   v3, v5, v6
    vand      v13, v17, v15
    vmrglb    v4, v11, v0
    vmrghb    v2, v11, v0
    vaddsws   v21, v24, v26
    vupkhsh128 v63, v3
    vmrglb    v31, v9, v13
    vmrghb    v30, v9, v13
    vmrglb    v28, v8, v12
    vaddsws   v25, v2, v4
    vcsxwfp128 v0, v63, 0
    vmrghb    v27, v8, v12
    vupklsh128 v62, v3
    vaddsws   v23, v30, v31
    vaddsws   v22, v27, v28
    vcsxwfp128 v13, v62, 0
    vaddsws   v19, v23, v21
    vaddsws   v20, v25, v22
    vmaddfp   v0, v0, v29, v1
    vaddsws   v18, v20, v19
    vupkhsh128 v61, v18
    vupklsh128 v60, v18
    vcsxwfp128 v12, v60, 0
    stvx128   v0, r0, r7
    lvx128    v0, r0, r8
    vmaddfp   v0, v13, v0, v1
    vcsxwfp128 v13, v61, 0
    stvx128   v0, r0, r8
    lvx128    v0, r0, r9
    vmaddfp   v0, v13, v0, v1
    stvx128   v0, r0, r9
    lvx128    v0, r0, r31
    vmaddfp   v0, v12, v0, v1
    stvx128   v0, r0, r31
  }
}


// ========================================================================
// UpSample16x16_Bicubic
// EA  : 0x8292C688
// RVA : 0x0092C688
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_upsample.h
// ========================================================================

void __fastcall UpSample16x16_Bicubic(
        unsigned __int8 *dst,
        unsigned int dstX,
        unsigned int dstY,
        unsigned int dstBytePitch,
        const unsigned __int8 *src,
        unsigned int srcX,
        unsigned int srcY,
        unsigned int srcMaskY,
        int upsampleLevel,
        int sharpenScale,
        int noiseScale,
        int a12,
        int a13,
        unsigned int a14,
        int a15,
        unsigned int a16,
        int a17,
        unsigned int a18,
        int a19,
        int a20,
        int a21,
        unsigned int a22,
        int a23,
        unsigned int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32)
{
  int v33; // r5
  unsigned int v36; // r9
  int v37; // r8
  unsigned int v43; // r18
  int v46; // r9
  unsigned int v56; // r9
  int v59; // r21
  unsigned int v60; // r16
  char v61; // r20
  int v62; // r19
  int v64; // r22
  unsigned int v77; // r15
  unsigned int v79; // r11
  unsigned int v80; // r7
  unsigned __int8 *v81; // r14
  unsigned int v82; // r29
  unsigned int v83; // r27
  unsigned int v84; // r26
  unsigned int v85; // r25
  unsigned int v86; // r24
  unsigned int v87; // r11
  unsigned int v88; // r23
  int v92; // r8
  unsigned int i; // r10
  unsigned int v113; // ctr
  __vector4 *v122; // [sp+8h] [-3B8h]
  unsigned int v123; // [sp+60h] [-360h]
  _BYTE v124[16]; // [sp+70h] [-350h] BYREF
  _BYTE v125[16]; // [sp+80h] [-340h] BYREF
  __vector4 v126; // [sp+90h] [-330h] BYREF
  __vector4 v127; // [sp+A0h] [-320h] BYREF
  __vector4 v128; // [sp+B0h] [-310h] BYREF
  __vector4 v129; // [sp+C0h] [-300h] BYREF
  __vector4 v130; // [sp+D0h] [-2F0h] BYREF
  __vector4 v131; // [sp+E0h] [-2E0h] BYREF
  _BYTE v132[16]; // [sp+F0h] [-2D0h] BYREF
  __vector4 v133; // [sp+100h] [-2C0h] BYREF
  _BYTE v134[16]; // [sp+110h] [-2B0h] BYREF
  __vector4 v135; // [sp+120h] [-2A0h] BYREF
  _BYTE v136[496]; // [sp+130h] [-290h] BYREF

  a14 = dstX;
  a16 = dstY;
  v33 = dstY + srcY;
  _R31 = &a28;
  a18 = dstBytePitch;
  __asm { lvlx128   v63, r0, r31 }
  _R28 = vector_int_one;
  v36 = 2 * (dstX + srcX) - (1 << a28);
  __asm { vspltw128 v13, v63, 0 }
  v37 = 2 * v33;
  _R5 = &a14;
  _R31 = &a16;
  __asm { lvx128    v0, r0, r28 }
  _R29 = &a30;
  __asm { vadduws   v8, v13, v0 }
  _R4 = &vector_int_zero;
  _R27 = &a32;
  __asm
  {
    lvlx128   v62, r0, r5
    lvlx128   v61, r0, r31
  }
  v43 = v36 + 1;
  __asm
  {
    vspltw128 v60, v62, 0
    vslw      v5, v0, v8
    vspltw128 v59, v61, 0
    lvlx      v12, r0, r29
    lvx128    v3, r0, r4
  }
  a22 = v43;
  __asm { lvlx      v11, r0, r27 }
  _R4 = 32;
  __asm
  {
    vmrghb    v10, v3, v12
    vcuxwfp128 v12, v60, 0
    vmrghb    v9, v3, v11
    vcuxwfp128 v11, v59, 0
  }
  _R5 = 64;
  __asm { vsubuws   v25, v5, v0 }
  v46 = v37 - (1 << a28);
  __asm
  {
    vmrghh    v7, v3, v10
    lvx128    v63, r28, r4
    vmrghh    v6, v3, v9
  }
  _R4 = 192;
  _R31 = 208;
  __asm
  {
    vslw128   v4, v8, v63
    lvx128    v0, r28, r5
  }
  _R8 = 48;
  __asm { vcuxwfp128 v58, v7, 0 }
  _R27 = &a22;
  __asm { vcuxwfp128 v109, v6, 0 }
  _R29 = v136;
  __asm { lvx128    v62, r28, r4 }
  _R4 = 224;
  __asm { lvx128    v63, r28, r31 }
  _R31 = v134;
  __asm { lvx128    v13, r28, r8 }
  _R8 = v132;
  __asm { vmaddfp   v0, v11, v12, v0 }
  _R5 = &a24;
  __asm { vsubuws   v24, v13, v4 }
  v56 = v46 + 1;
  __asm { lvx128    v61, r28, r4 }
  a24 = v56;
  __asm
  {
    stvx128   v25, r0, r31
    stvx128   v3, r0, r8
  }
  __asm { lvlx128   v57, r0, r27 }
  v59 = 1 << a28;
  __asm { lvlx128   v56, r0, r5 }
  v60 = 0;
  __asm
  {
    stvx128   v24, r0, r29
    vmulfp128 v99, v90, v63
  }
  v61 = a28 + 1;
  __asm { vmulfp128 v102, v109, v62 }
  v62 = (1 << a28) - 1;
  __asm
  {
    vspltw128 v98, v57, 0
    vaddfp128 v127, v0, v61
  }
  _R11 = 16;
  v64 = a30;
  _R10 = v124;
  __asm { vspltw128 v23, v56, 0 }
  _R8 = 256;
  _R7 = 240;
  _R5 = 272;
  __asm { lvx128    v55, r28, r11 }
  _R4 = 288;
  _R11 = 80;
  __asm
  {
    stvx128   v55, r0, r10
    lvx128    v113, r28, r8
  }
  _R10 = 112;
  __asm { lvx128    v112, r28, r7 }
  _R8 = 128;
  __asm { lvx128    v111, r28, r5 }
  _R7 = 176;
  __asm { lvx128    v110, r28, r4 }
  _R5 = 96;
  __asm { lvx128    v108, r28, r11 }
  _R4 = 144;
  _R11 = 160;
  __asm
  {
    lvx128    v126, r28, r10
    lvx128    v107, r28, r8
  }
  v77 = v43 >> 1;
  __asm { lvx128    v106, r28, r7 }
  _R30 = 16;
  __asm
  {
    lvx128    v105, r28, r5
    lvx128    v104, r28, r4
    lvx128    v103, r28, r11
  }
  while ( 1 )
  {
    v79 = (2 * v60 + v56) >> v61;
    if ( 16 - v60 >= v59 - ((v60 + (v56 >> 1)) & v62) )
    {
      v123 = v59 - ((v60 + (v56 >> 1)) & v62);
      v80 = v123;
    }
    else
    {
      v80 = 16 - v60;
      v123 = 16 - v60;
    }
    __asm { vmr128    v101, v98 }
    __asm { vmr128    v100, v23 }
    v81 = dst;
    v82 = 0;
    v83 = ((v79 - 1) & srcMaskY) << 7;
    v84 = (v79 & srcMaskY) << 7;
    v85 = ((v79 + 1) & srcMaskY) << 7;
    v86 = ((v79 + 2) & srcMaskY) << 7;
    do
    {
      v87 = (2 * v82 + v43) >> v61;
      v88 = 16 - v82;
      if ( 16 - v82 >= v59 - ((v82 + v77) & v62) )
        v88 = v59 - ((v82 + v77) & v62);
      _R9 = &src[4 * v87 - 4 + 4 * v85];
      _R10 = &src[4 * v87 - 4 + 4 * v84];
      _R4 = &v130;
      __asm { lvlx128   v54, r0, r9 }
      __asm { lvrx128   v53, r30, r9 }
      __asm
      {
        lvlx128   v52, r0, r10
        vor128    v12, v86, v53
        lvrx128   v51, r30, r10
      }
      v92 = 4 * (v87 + v86);
      __asm { vor128    v13, v84, v51 }
      _R11 = &src[4 * v87 - 4 + 4 * v83];
      __asm
      {
        vmrghb    v8, v3, v12
        stvx128   v12, r0, r4
        vmrglb    v12, v3, v12
      }
      _R10 = &src[v92 - 4];
      __asm { vmrghb    v10, v3, v13 }
      _R9 = &v133;
      __asm
      {
        vmrglb    v9, v3, v13
        lvlx128   v50, r0, r11
        lvrx128   v49, r30, r11
        vmrglh    v11, v3, v8
        vmrghh    v7, v3, v12
      }
      _R8 = &v131;
      __asm
      {
        vmrglh    v6, v3, v10
        vor128    v0, v82, v49
        vmrghh    v5, v3, v9
        lvlx128   v48, r0, r10
        lvrx128   v47, r30, r10
        vcfux     v27, v11, 0
        vcfux     v26, v7, 0
      }
      _R5 = &v135;
      __asm
      {
        vcfux     v29, v6, 0
        stvx128   v13, r0, r9
        vcfux     v28, v5, 0
        vor128    v11, v80, v47
        vmrghb    v13, v3, v0
        stvx128   v0, r0, r8
        vmrglb    v0, v3, v0
      }
      _R4 = &v129;
      _R3 = &v128;
      __asm { vmrghh    v4, v3, v10 }
      _R11 = &v127;
      __asm { vmrghb    v7, v3, v11 }
      _R10 = &v126;
      __asm
      {
        stvx128   v11, r0, r5
        vmrglb    v11, v3, v11
      }
      __asm
      {
        vmrghh    v2, v3, v13
        vcuxwfp128 v121, v4, 0
        vmrglh    v1, v3, v13
        vmrghh    v31, v3, v0
        stvx128   v27, r0, r11
        vmrglh    v30, v3, v0
        stvx128   v26, r0, r10
        vmrglh    v23, v3, v9
        stvx128   v29, r0, r4
        vmrghh    v22, v3, v8
        stvx128   v28, r0, r3
        vmrglh    v21, v3, v12
        vcuxwfp128 v125, v2, 0
        vcuxwfp128 v124, v1, 0
        vmrghh    v20, v3, v7
        vcuxwfp128 v123, v31, 0
        vmrglh    v19, v3, v7
        vcuxwfp128 v122, v30, 0
        vmrghh    v18, v3, v11
        vcuxwfp128 v120, v23, 0
        vmrglh    v17, v3, v11
        vcuxwfp128 v119, v22, 0
        vcuxwfp128 v118, v21, 0
        vcuxwfp128 v117, v20, 0
        vcuxwfp128 v116, v19, 0
        vcuxwfp128 v115, v18, 0
        vcuxwfp128 v114, v17, 0
      }
      if ( v64 != 0 )
      {
        __asm { vmr128    v1, v99 }
        Sharpen4x4Center_Xenon(
          b0: &v131,
          b1: &v133,
          b2: &v130,
          b3: &v135,
          amount: &v129,
          f0: &v128,
          f1: &v127,
          f2: &v126,
          f3: v122);
        _R11 = &v129;
        _R10 = &v128;
        v80 = v123;
        _R9 = &v127;
        dstBytePitch = a18;
        _R8 = &v126;
        _R5 = v132;
        _R4 = v134;
        __asm { lvx128    v29, r0, r11 }
        _R3 = v136;
        __asm
        {
          lvx128    v28, r0, r10
          lvx128    v27, r0, r9
          lvx128    v26, r0, r8
          lvx128    v3, r0, r5
          lvx128    v25, r0, r4
          lvx128    v24, r0, r3
        }
      }
      __asm { vmr128    v63, v101 }
      dst = v81;
      __asm { vmr128    v23, v100 }
      if ( v80 != 0 )
      {
        for ( i = v80; i != 0; --i )
        {
          __asm { vand128   v46, v23, v25 }
          _R11 = v124;
          __asm { vmr128    v12, v112 }
          _R9 = v125;
          __asm { vor128    v0, v95, v63 }
          __asm
          {
            vcuxwfp128 v45, v46, 0
            lvx128    v13, r0, r11
            vadduws   v23, v23, v13
            stvx128   v0, r0, r9
            vmulfp128 v13, v77, v24
            vmaddcfp128 v12, v13, v12, v113
            vmaddcfp128 v12, v13, v12, v111
            vmaddcfp128 v13, v12, v13, v110
          }
          if ( v88 != 0 )
          {
            __asm { vspltw    v2, v13, 0 }
            _R11 = 4 * v82;
            __asm { vspltw    v1, v13, 1 }
            v113 = v88;
            __asm
            {
              vspltw    v31, v13, 2
              vspltw    v30, v13, 3
            }
            while ( 1 )
            {
              __asm
              {
                vmulfp128 v9, v127, v108
                vand128   v43, v0, v25
              }
              _R9 = v124;
              __asm
              {
                vmr128    v8, v112
                vmr128    v13, v126
              }
              _R8 = v125;
              __asm
              {
                vmr128    v7, v105
                vcuxwfp128 v42, v43, 0
                vmr128    v10, v104
                vmr128    v11, v102
                lvx128    v12, r0, r9
                vadduws   v6, v0, v12
                vmaddcfp128 v7, v127, v7, v106
                stvx128   v6, r0, r8
                vmulfp128 v41, v9, v107
                vmulfp128 v0, v74, v24
                vrfiz128  v12, v41
                vmaddcfp128 v8, v0, v8, v113
                vnmsubfp  v9, v12, v9, v13
                vmr       v13, v0
                vmaddcfp128 v13, v8, v13, v111
                vmr128    v8, v126
                vmaddcfp128 v8, v9, v8, v7
                vmaddcfp128 v0, v13, v0, v110
                vmulfp128 v40, v8, v103
                vmr128    v127, v8
                vmr128    v39, v0
                vspltw128 v38, v39, 3
                vspltw128 v0, v39, 2
                vspltw128 v13, v39, 1
                vspltw128 v12, v39, 0
                vmulfp128 v4, v122, v38
                vmulfp128 v5, v120, v38
                vmulfp128 v6, v118, v38
                vmulfp128 v7, v114, v38
                vrfiz128  v9, v40
                vmaddfp128 v4, v123, v0, v4
                vmaddfp   v5, v28, v5, v0
                vmaddfp   v6, v26, v6, v0
                vmaddcfp128 v0, v115, v0, v7
                vmr       v7, v13
                vnmsubfp128 v127, v9, v10, v127
                vmr128    v9, v109
                vmaddcfp128 v7, v124, v7, v4
                vmaddfp   v10, v29, v5, v13
                vmaddfp   v8, v27, v6, v13
                vmaddcfp128 v13, v116, v13, v0
                vmr128    v0, v127
                vnmsubfp128 v9, v0, v11, v9
                vmr       v0, v12
                vmr       v11, v12
                vmaddcfp128 v0, v125, v0, v7
                vmaddfp128 v10, v121, v12, v10
                vmaddcfp128 v11, v119, v11, v8
                vmaddfp128 v13, v117, v12, v13
                vmaddfp   v0, v0, v9, v2
                vmaddfp   v0, v10, v0, v1
                vmaddfp   v0, v11, v0, v31
                vmaddfp   v0, v13, v0, v30
                vcfpuxws128 v37, v0, 0
                vpkswus128 v36, v69, v37
                vpkuhus128 v35, v68, v36
                stvewx128 v35, r3, r11
              }
              _R11 += 4;
              if ( --v113 == 0 )
                break;
              _R9 = 16;
              _R8 = v124;
              _R5 = v125;
              __asm
              {
                lvx128    v44, r28, r9
                stvx128   v44, r0, r8
                lvx128    v0, r0, r5
              }
            }
            _R11 = 16;
            _R9 = v124;
            __asm
            {
              lvx128    v34, r28, r11
              stvx128   v34, r0, r9
            }
          }
          dst += dstBytePitch;
        }
        _R11 = v125;
        __asm { lvx128    v101, r0, r11 }
      }
      v82 += v88;
    }
    while ( v82 < 0x10 );
    v60 += v80;
    if ( v60 >= 0x10 )
      break;
    v56 = a24;
  }
}


// ========================================================================
// UpSample16x16_Bicubic_0
// EA  : 0x829306C8
// RVA : 0x009306C8
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_upsample.h
// ========================================================================

void __fastcall UpSample16x16_Bicubic_0(
        unsigned __int8 *dst,
        unsigned int dstX,
        unsigned int dstY,
        unsigned int dstBytePitch,
        const unsigned __int8 *src,
        unsigned int srcX,
        unsigned int srcY,
        unsigned int srcMaskY,
        int upsampleLevel,
        int sharpenScale,
        int noiseScale,
        int a12,
        int a13,
        unsigned int a14,
        int a15,
        unsigned int a16,
        int a17,
        unsigned int a18,
        int a19,
        int a20,
        int a21,
        unsigned int a22,
        int a23,
        unsigned int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32)
{
  int v33; // r5
  unsigned int v36; // r9
  int v37; // r8
  unsigned int v43; // r18
  int v46; // r9
  unsigned int v56; // r9
  int v59; // r21
  unsigned int v60; // r16
  char v61; // r20
  int v62; // r19
  int v64; // r22
  unsigned int v77; // r15
  unsigned int v79; // r11
  unsigned int v80; // r7
  unsigned __int8 *v81; // r14
  unsigned int v82; // r29
  unsigned int v83; // r27
  unsigned int v84; // r26
  unsigned int v85; // r25
  unsigned int v86; // r24
  unsigned int v87; // r11
  unsigned int v88; // r23
  int v92; // r8
  unsigned int i; // r10
  unsigned int v113; // ctr
  __vector4 *v122; // [sp+8h] [-3B8h]
  unsigned int v123; // [sp+60h] [-360h]
  _BYTE v124[16]; // [sp+70h] [-350h] BYREF
  _BYTE v125[16]; // [sp+80h] [-340h] BYREF
  __vector4 v126; // [sp+90h] [-330h] BYREF
  __vector4 v127; // [sp+A0h] [-320h] BYREF
  __vector4 v128; // [sp+B0h] [-310h] BYREF
  __vector4 v129; // [sp+C0h] [-300h] BYREF
  __vector4 v130; // [sp+D0h] [-2F0h] BYREF
  __vector4 v131; // [sp+E0h] [-2E0h] BYREF
  _BYTE v132[16]; // [sp+F0h] [-2D0h] BYREF
  __vector4 v133; // [sp+100h] [-2C0h] BYREF
  _BYTE v134[16]; // [sp+110h] [-2B0h] BYREF
  __vector4 v135; // [sp+120h] [-2A0h] BYREF
  _BYTE v136[496]; // [sp+130h] [-290h] BYREF

  a14 = dstX;
  a16 = dstY;
  v33 = dstY + srcY;
  _R31 = &a28;
  a18 = dstBytePitch;
  __asm { lvlx128   v63, r0, r31 }
  _R28 = vector_int_one_0;
  v36 = 2 * (dstX + srcX) - (1 << a28);
  __asm { vspltw128 v13, v63, 0 }
  v37 = 2 * v33;
  _R5 = &a14;
  _R31 = &a16;
  __asm { lvx128    v0, r0, r28 }
  _R29 = &a30;
  __asm { vadduws   v8, v13, v0 }
  _R4 = &vector_int_zero_0;
  _R27 = &a32;
  __asm
  {
    lvlx128   v62, r0, r5
    lvlx128   v61, r0, r31
  }
  v43 = v36 + 1;
  __asm
  {
    vspltw128 v60, v62, 0
    vslw      v5, v0, v8
    vspltw128 v59, v61, 0
    lvlx      v12, r0, r29
    lvx128    v3, r0, r4
  }
  a22 = v43;
  __asm { lvlx      v11, r0, r27 }
  _R4 = 32;
  __asm
  {
    vmrghb    v10, v3, v12
    vcuxwfp128 v12, v60, 0
    vmrghb    v9, v3, v11
    vcuxwfp128 v11, v59, 0
  }
  _R5 = 64;
  __asm { vsubuws   v25, v5, v0 }
  v46 = v37 - (1 << a28);
  __asm
  {
    vmrghh    v7, v3, v10
    lvx128    v63, r28, r4
    vmrghh    v6, v3, v9
  }
  _R4 = 192;
  _R31 = 208;
  __asm
  {
    vslw128   v4, v8, v63
    lvx128    v0, r28, r5
  }
  _R8 = 48;
  __asm { vcuxwfp128 v58, v7, 0 }
  _R27 = &a22;
  __asm { vcuxwfp128 v109, v6, 0 }
  _R29 = v136;
  __asm { lvx128    v62, r28, r4 }
  _R4 = 224;
  __asm { lvx128    v63, r28, r31 }
  _R31 = v134;
  __asm { lvx128    v13, r28, r8 }
  _R8 = v132;
  __asm { vmaddfp   v0, v11, v12, v0 }
  _R5 = &a24;
  __asm { vsubuws   v24, v13, v4 }
  v56 = v46 + 1;
  __asm { lvx128    v61, r28, r4 }
  a24 = v56;
  __asm
  {
    stvx128   v25, r0, r31
    stvx128   v3, r0, r8
  }
  __asm { lvlx128   v57, r0, r27 }
  v59 = 1 << a28;
  __asm { lvlx128   v56, r0, r5 }
  v60 = 0;
  __asm
  {
    stvx128   v24, r0, r29
    vmulfp128 v99, v90, v63
  }
  v61 = a28 + 1;
  __asm { vmulfp128 v102, v109, v62 }
  v62 = (1 << a28) - 1;
  __asm
  {
    vspltw128 v98, v57, 0
    vaddfp128 v127, v0, v61
  }
  _R11 = 16;
  v64 = a30;
  _R10 = v124;
  __asm { vspltw128 v23, v56, 0 }
  _R8 = 256;
  _R7 = 240;
  _R5 = 272;
  __asm { lvx128    v55, r28, r11 }
  _R4 = 288;
  _R11 = 80;
  __asm
  {
    stvx128   v55, r0, r10
    lvx128    v113, r28, r8
  }
  _R10 = 112;
  __asm { lvx128    v112, r28, r7 }
  _R8 = 128;
  __asm { lvx128    v111, r28, r5 }
  _R7 = 176;
  __asm { lvx128    v110, r28, r4 }
  _R5 = 96;
  __asm { lvx128    v108, r28, r11 }
  _R4 = 144;
  _R11 = 160;
  __asm
  {
    lvx128    v126, r28, r10
    lvx128    v107, r28, r8
  }
  v77 = v43 >> 1;
  __asm { lvx128    v106, r28, r7 }
  _R30 = 16;
  __asm
  {
    lvx128    v105, r28, r5
    lvx128    v104, r28, r4
    lvx128    v103, r28, r11
  }
  while ( 1 )
  {
    v79 = (2 * v60 + v56) >> v61;
    if ( 16 - v60 >= v59 - ((v60 + (v56 >> 1)) & v62) )
    {
      v123 = v59 - ((v60 + (v56 >> 1)) & v62);
      v80 = v123;
    }
    else
    {
      v80 = 16 - v60;
      v123 = 16 - v60;
    }
    __asm { vmr128    v101, v98 }
    __asm { vmr128    v100, v23 }
    v81 = dst;
    v82 = 0;
    v83 = ((v79 - 1) & srcMaskY) << 7;
    v84 = (v79 & srcMaskY) << 7;
    v85 = ((v79 + 1) & srcMaskY) << 7;
    v86 = ((v79 + 2) & srcMaskY) << 7;
    do
    {
      v87 = (2 * v82 + v43) >> v61;
      v88 = 16 - v82;
      if ( 16 - v82 >= v59 - ((v82 + v77) & v62) )
        v88 = v59 - ((v82 + v77) & v62);
      _R9 = &src[4 * v87 - 4 + 4 * v85];
      _R10 = &src[4 * v87 - 4 + 4 * v84];
      _R4 = &v130;
      __asm { lvlx128   v54, r0, r9 }
      __asm { lvrx128   v53, r30, r9 }
      __asm
      {
        lvlx128   v52, r0, r10
        vor128    v12, v86, v53
        lvrx128   v51, r30, r10
      }
      v92 = 4 * (v87 + v86);
      __asm { vor128    v13, v84, v51 }
      _R11 = &src[4 * v87 - 4 + 4 * v83];
      __asm
      {
        vmrghb    v8, v3, v12
        stvx128   v12, r0, r4
        vmrglb    v12, v3, v12
      }
      _R10 = &src[v92 - 4];
      __asm { vmrghb    v10, v3, v13 }
      _R9 = &v133;
      __asm
      {
        vmrglb    v9, v3, v13
        lvlx128   v50, r0, r11
        lvrx128   v49, r30, r11
        vmrglh    v11, v3, v8
        vmrghh    v7, v3, v12
      }
      _R8 = &v131;
      __asm
      {
        vmrglh    v6, v3, v10
        vor128    v0, v82, v49
        vmrghh    v5, v3, v9
        lvlx128   v48, r0, r10
        lvrx128   v47, r30, r10
        vcfux     v27, v11, 0
        vcfux     v26, v7, 0
      }
      _R5 = &v135;
      __asm
      {
        vcfux     v29, v6, 0
        stvx128   v13, r0, r9
        vcfux     v28, v5, 0
        vor128    v11, v80, v47
        vmrghb    v13, v3, v0
        stvx128   v0, r0, r8
        vmrglb    v0, v3, v0
      }
      _R4 = &v129;
      _R3 = &v128;
      __asm { vmrghh    v4, v3, v10 }
      _R11 = &v127;
      __asm { vmrghb    v7, v3, v11 }
      _R10 = &v126;
      __asm
      {
        stvx128   v11, r0, r5
        vmrglb    v11, v3, v11
      }
      __asm
      {
        vmrghh    v2, v3, v13
        vcuxwfp128 v121, v4, 0
        vmrglh    v1, v3, v13
        vmrghh    v31, v3, v0
        stvx128   v27, r0, r11
        vmrglh    v30, v3, v0
        stvx128   v26, r0, r10
        vmrglh    v23, v3, v9
        stvx128   v29, r0, r4
        vmrghh    v22, v3, v8
        stvx128   v28, r0, r3
        vmrglh    v21, v3, v12
        vcuxwfp128 v125, v2, 0
        vcuxwfp128 v124, v1, 0
        vmrghh    v20, v3, v7
        vcuxwfp128 v123, v31, 0
        vmrglh    v19, v3, v7
        vcuxwfp128 v122, v30, 0
        vmrghh    v18, v3, v11
        vcuxwfp128 v120, v23, 0
        vmrglh    v17, v3, v11
        vcuxwfp128 v119, v22, 0
        vcuxwfp128 v118, v21, 0
        vcuxwfp128 v117, v20, 0
        vcuxwfp128 v116, v19, 0
        vcuxwfp128 v115, v18, 0
        vcuxwfp128 v114, v17, 0
      }
      if ( v64 != 0 )
      {
        __asm { vmr128    v1, v99 }
        Sharpen4x4Center_Xenon(
          b0: &v131,
          b1: &v133,
          b2: &v130,
          b3: &v135,
          amount: &v129,
          f0: &v128,
          f1: &v127,
          f2: &v126,
          f3: v122);
        _R11 = &v129;
        _R10 = &v128;
        v80 = v123;
        _R9 = &v127;
        dstBytePitch = a18;
        _R8 = &v126;
        _R5 = v132;
        _R4 = v134;
        __asm { lvx128    v29, r0, r11 }
        _R3 = v136;
        __asm
        {
          lvx128    v28, r0, r10
          lvx128    v27, r0, r9
          lvx128    v26, r0, r8
          lvx128    v3, r0, r5
          lvx128    v25, r0, r4
          lvx128    v24, r0, r3
        }
      }
      __asm { vmr128    v63, v101 }
      dst = v81;
      __asm { vmr128    v23, v100 }
      if ( v80 != 0 )
      {
        for ( i = v80; i != 0; --i )
        {
          __asm { vand128   v46, v23, v25 }
          _R11 = v124;
          __asm { vmr128    v12, v112 }
          _R9 = v125;
          __asm { vor128    v0, v95, v63 }
          __asm
          {
            vcuxwfp128 v45, v46, 0
            lvx128    v13, r0, r11
            vadduws   v23, v23, v13
            stvx128   v0, r0, r9
            vmulfp128 v13, v77, v24
            vmaddcfp128 v12, v13, v12, v113
            vmaddcfp128 v12, v13, v12, v111
            vmaddcfp128 v13, v12, v13, v110
          }
          if ( v88 != 0 )
          {
            __asm { vspltw    v2, v13, 0 }
            _R11 = 4 * v82;
            __asm { vspltw    v1, v13, 1 }
            v113 = v88;
            __asm
            {
              vspltw    v31, v13, 2
              vspltw    v30, v13, 3
            }
            while ( 1 )
            {
              __asm
              {
                vmulfp128 v9, v127, v108
                vand128   v43, v0, v25
              }
              _R9 = v124;
              __asm
              {
                vmr128    v8, v112
                vmr128    v13, v126
              }
              _R8 = v125;
              __asm
              {
                vmr128    v7, v105
                vcuxwfp128 v42, v43, 0
                vmr128    v10, v104
                vmr128    v11, v102
                lvx128    v12, r0, r9
                vadduws   v6, v0, v12
                vmaddcfp128 v7, v127, v7, v106
                stvx128   v6, r0, r8
                vmulfp128 v41, v9, v107
                vmulfp128 v0, v74, v24
                vrfiz128  v12, v41
                vmaddcfp128 v8, v0, v8, v113
                vnmsubfp  v9, v12, v9, v13
                vmr       v13, v0
                vmaddcfp128 v13, v8, v13, v111
                vmr128    v8, v126
                vmaddcfp128 v8, v9, v8, v7
                vmaddcfp128 v0, v13, v0, v110
                vmulfp128 v40, v8, v103
                vmr128    v127, v8
                vmr128    v39, v0
                vspltw128 v38, v39, 3
                vspltw128 v0, v39, 2
                vspltw128 v13, v39, 1
                vspltw128 v12, v39, 0
                vmulfp128 v4, v122, v38
                vmulfp128 v5, v120, v38
                vmulfp128 v6, v118, v38
                vmulfp128 v7, v114, v38
                vrfiz128  v9, v40
                vmaddfp128 v4, v123, v0, v4
                vmaddfp   v5, v28, v5, v0
                vmaddfp   v6, v26, v6, v0
                vmaddcfp128 v0, v115, v0, v7
                vmr       v7, v13
                vnmsubfp128 v127, v9, v10, v127
                vmr128    v9, v109
                vmaddcfp128 v7, v124, v7, v4
                vmaddfp   v10, v29, v5, v13
                vmaddfp   v8, v27, v6, v13
                vmaddcfp128 v13, v116, v13, v0
                vmr128    v0, v127
                vnmsubfp128 v9, v0, v11, v9
                vmr       v0, v12
                vmr       v11, v12
                vmaddcfp128 v0, v125, v0, v7
                vmaddfp128 v10, v121, v12, v10
                vmaddcfp128 v11, v119, v11, v8
                vmaddfp128 v13, v117, v12, v13
                vmaddfp   v0, v0, v9, v2
                vmaddfp   v0, v10, v0, v1
                vmaddfp   v0, v11, v0, v31
                vmaddfp   v0, v13, v0, v30
                vcfpuxws128 v37, v0, 0
                vpkswus128 v36, v69, v37
                vpkuhus128 v35, v68, v36
                stvewx128 v35, r3, r11
              }
              _R11 += 4;
              if ( --v113 == 0 )
                break;
              _R9 = 16;
              _R8 = v124;
              _R5 = v125;
              __asm
              {
                lvx128    v44, r28, r9
                stvx128   v44, r0, r8
                lvx128    v0, r0, r5
              }
            }
            _R11 = 16;
            _R9 = v124;
            __asm
            {
              lvx128    v34, r28, r11
              stvx128   v34, r0, r9
            }
          }
          dst += dstBytePitch;
        }
        _R11 = v125;
        __asm { lvx128    v101, r0, r11 }
      }
      v82 += v88;
    }
    while ( v82 < 0x10 );
    v60 += v80;
    if ( v60 >= 0x10 )
      break;
    v56 = a24;
  }
}


// ========================================================================
// UpSample16x16_Bicubic_1
// EA  : 0x82931BF0
// RVA : 0x00931BF0
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_upsample.h
// ========================================================================

void __fastcall UpSample16x16_Bicubic_1(
        unsigned __int8 *dst,
        unsigned int dstX,
        unsigned int dstY,
        unsigned int dstBytePitch,
        const unsigned __int8 *src,
        unsigned int srcX,
        unsigned int srcY,
        unsigned int srcMaskY,
        int upsampleLevel,
        int sharpenScale,
        int noiseScale,
        int a12,
        int a13,
        unsigned int a14,
        int a15,
        unsigned int a16,
        int a17,
        unsigned int a18,
        int a19,
        int a20,
        int a21,
        unsigned int a22,
        int a23,
        unsigned int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32)
{
  int v33; // r5
  unsigned int v36; // r9
  int v37; // r8
  unsigned int v43; // r18
  int v46; // r9
  unsigned int v56; // r9
  int v59; // r21
  unsigned int v60; // r16
  char v61; // r20
  int v62; // r19
  int v64; // r22
  unsigned int v77; // r15
  unsigned int v79; // r11
  unsigned int v80; // r7
  unsigned __int8 *v81; // r14
  unsigned int v82; // r29
  unsigned int v83; // r27
  unsigned int v84; // r26
  unsigned int v85; // r25
  unsigned int v86; // r24
  unsigned int v87; // r11
  unsigned int v88; // r23
  int v92; // r8
  unsigned int i; // r10
  unsigned int v113; // ctr
  __vector4 *v122; // [sp+8h] [-3B8h]
  unsigned int v123; // [sp+60h] [-360h]
  _BYTE v124[16]; // [sp+70h] [-350h] BYREF
  _BYTE v125[16]; // [sp+80h] [-340h] BYREF
  __vector4 v126; // [sp+90h] [-330h] BYREF
  __vector4 v127; // [sp+A0h] [-320h] BYREF
  __vector4 v128; // [sp+B0h] [-310h] BYREF
  __vector4 v129; // [sp+C0h] [-300h] BYREF
  __vector4 v130; // [sp+D0h] [-2F0h] BYREF
  __vector4 v131; // [sp+E0h] [-2E0h] BYREF
  _BYTE v132[16]; // [sp+F0h] [-2D0h] BYREF
  __vector4 v133; // [sp+100h] [-2C0h] BYREF
  _BYTE v134[16]; // [sp+110h] [-2B0h] BYREF
  __vector4 v135; // [sp+120h] [-2A0h] BYREF
  _BYTE v136[496]; // [sp+130h] [-290h] BYREF

  a14 = dstX;
  a16 = dstY;
  v33 = dstY + srcY;
  _R31 = &a28;
  a18 = dstBytePitch;
  __asm { lvlx128   v63, r0, r31 }
  _R28 = vector_int_one_1;
  v36 = 2 * (dstX + srcX) - (1 << a28);
  __asm { vspltw128 v13, v63, 0 }
  v37 = 2 * v33;
  _R5 = &a14;
  _R31 = &a16;
  __asm { lvx128    v0, r0, r28 }
  _R29 = &a30;
  __asm { vadduws   v8, v13, v0 }
  _R4 = &vector_int_zero_1;
  _R27 = &a32;
  __asm
  {
    lvlx128   v62, r0, r5
    lvlx128   v61, r0, r31
  }
  v43 = v36 + 1;
  __asm
  {
    vspltw128 v60, v62, 0
    vslw      v5, v0, v8
    vspltw128 v59, v61, 0
    lvlx      v12, r0, r29
    lvx128    v3, r0, r4
  }
  a22 = v43;
  __asm { lvlx      v11, r0, r27 }
  _R4 = 32;
  __asm
  {
    vmrghb    v10, v3, v12
    vcuxwfp128 v12, v60, 0
    vmrghb    v9, v3, v11
    vcuxwfp128 v11, v59, 0
  }
  _R5 = 64;
  __asm { vsubuws   v25, v5, v0 }
  v46 = v37 - (1 << a28);
  __asm
  {
    vmrghh    v7, v3, v10
    lvx128    v63, r28, r4
    vmrghh    v6, v3, v9
  }
  _R4 = 192;
  _R31 = 208;
  __asm
  {
    vslw128   v4, v8, v63
    lvx128    v0, r28, r5
  }
  _R8 = 48;
  __asm { vcuxwfp128 v58, v7, 0 }
  _R27 = &a22;
  __asm { vcuxwfp128 v109, v6, 0 }
  _R29 = v136;
  __asm { lvx128    v62, r28, r4 }
  _R4 = 224;
  __asm { lvx128    v63, r28, r31 }
  _R31 = v134;
  __asm { lvx128    v13, r28, r8 }
  _R8 = v132;
  __asm { vmaddfp   v0, v11, v12, v0 }
  _R5 = &a24;
  __asm { vsubuws   v24, v13, v4 }
  v56 = v46 + 1;
  __asm { lvx128    v61, r28, r4 }
  a24 = v56;
  __asm
  {
    stvx128   v25, r0, r31
    stvx128   v3, r0, r8
  }
  __asm { lvlx128   v57, r0, r27 }
  v59 = 1 << a28;
  __asm { lvlx128   v56, r0, r5 }
  v60 = 0;
  __asm
  {
    stvx128   v24, r0, r29
    vmulfp128 v99, v90, v63
  }
  v61 = a28 + 1;
  __asm { vmulfp128 v102, v109, v62 }
  v62 = (1 << a28) - 1;
  __asm
  {
    vspltw128 v98, v57, 0
    vaddfp128 v127, v0, v61
  }
  _R11 = 16;
  v64 = a30;
  _R10 = v124;
  __asm { vspltw128 v23, v56, 0 }
  _R8 = 256;
  _R7 = 240;
  _R5 = 272;
  __asm { lvx128    v55, r28, r11 }
  _R4 = 288;
  _R11 = 80;
  __asm
  {
    stvx128   v55, r0, r10
    lvx128    v113, r28, r8
  }
  _R10 = 112;
  __asm { lvx128    v112, r28, r7 }
  _R8 = 128;
  __asm { lvx128    v111, r28, r5 }
  _R7 = 176;
  __asm { lvx128    v110, r28, r4 }
  _R5 = 96;
  __asm { lvx128    v108, r28, r11 }
  _R4 = 144;
  _R11 = 160;
  __asm
  {
    lvx128    v126, r28, r10
    lvx128    v107, r28, r8
  }
  v77 = v43 >> 1;
  __asm { lvx128    v106, r28, r7 }
  _R30 = 16;
  __asm
  {
    lvx128    v105, r28, r5
    lvx128    v104, r28, r4
    lvx128    v103, r28, r11
  }
  while ( 1 )
  {
    v79 = (2 * v60 + v56) >> v61;
    if ( 16 - v60 >= v59 - ((v60 + (v56 >> 1)) & v62) )
    {
      v123 = v59 - ((v60 + (v56 >> 1)) & v62);
      v80 = v123;
    }
    else
    {
      v80 = 16 - v60;
      v123 = 16 - v60;
    }
    __asm { vmr128    v101, v98 }
    __asm { vmr128    v100, v23 }
    v81 = dst;
    v82 = 0;
    v83 = ((v79 - 1) & srcMaskY) << 7;
    v84 = (v79 & srcMaskY) << 7;
    v85 = ((v79 + 1) & srcMaskY) << 7;
    v86 = ((v79 + 2) & srcMaskY) << 7;
    do
    {
      v87 = (2 * v82 + v43) >> v61;
      v88 = 16 - v82;
      if ( 16 - v82 >= v59 - ((v82 + v77) & v62) )
        v88 = v59 - ((v82 + v77) & v62);
      _R9 = &src[4 * v87 - 4 + 4 * v85];
      _R10 = &src[4 * v87 - 4 + 4 * v84];
      _R4 = &v130;
      __asm { lvlx128   v54, r0, r9 }
      __asm { lvrx128   v53, r30, r9 }
      __asm
      {
        lvlx128   v52, r0, r10
        vor128    v12, v86, v53
        lvrx128   v51, r30, r10
      }
      v92 = 4 * (v87 + v86);
      __asm { vor128    v13, v84, v51 }
      _R11 = &src[4 * v87 - 4 + 4 * v83];
      __asm
      {
        vmrghb    v8, v3, v12
        stvx128   v12, r0, r4
        vmrglb    v12, v3, v12
      }
      _R10 = &src[v92 - 4];
      __asm { vmrghb    v10, v3, v13 }
      _R9 = &v133;
      __asm
      {
        vmrglb    v9, v3, v13
        lvlx128   v50, r0, r11
        lvrx128   v49, r30, r11
        vmrglh    v11, v3, v8
        vmrghh    v7, v3, v12
      }
      _R8 = &v131;
      __asm
      {
        vmrglh    v6, v3, v10
        vor128    v0, v82, v49
        vmrghh    v5, v3, v9
        lvlx128   v48, r0, r10
        lvrx128   v47, r30, r10
        vcfux     v27, v11, 0
        vcfux     v26, v7, 0
      }
      _R5 = &v135;
      __asm
      {
        vcfux     v29, v6, 0
        stvx128   v13, r0, r9
        vcfux     v28, v5, 0
        vor128    v11, v80, v47
        vmrghb    v13, v3, v0
        stvx128   v0, r0, r8
        vmrglb    v0, v3, v0
      }
      _R4 = &v129;
      _R3 = &v128;
      __asm { vmrghh    v4, v3, v10 }
      _R11 = &v127;
      __asm { vmrghb    v7, v3, v11 }
      _R10 = &v126;
      __asm
      {
        stvx128   v11, r0, r5
        vmrglb    v11, v3, v11
      }
      __asm
      {
        vmrghh    v2, v3, v13
        vcuxwfp128 v121, v4, 0
        vmrglh    v1, v3, v13
        vmrghh    v31, v3, v0
        stvx128   v27, r0, r11
        vmrglh    v30, v3, v0
        stvx128   v26, r0, r10
        vmrglh    v23, v3, v9
        stvx128   v29, r0, r4
        vmrghh    v22, v3, v8
        stvx128   v28, r0, r3
        vmrglh    v21, v3, v12
        vcuxwfp128 v125, v2, 0
        vcuxwfp128 v124, v1, 0
        vmrghh    v20, v3, v7
        vcuxwfp128 v123, v31, 0
        vmrglh    v19, v3, v7
        vcuxwfp128 v122, v30, 0
        vmrghh    v18, v3, v11
        vcuxwfp128 v120, v23, 0
        vmrglh    v17, v3, v11
        vcuxwfp128 v119, v22, 0
        vcuxwfp128 v118, v21, 0
        vcuxwfp128 v117, v20, 0
        vcuxwfp128 v116, v19, 0
        vcuxwfp128 v115, v18, 0
        vcuxwfp128 v114, v17, 0
      }
      if ( v64 != 0 )
      {
        __asm { vmr128    v1, v99 }
        Sharpen4x4Center_Xenon(
          b0: &v131,
          b1: &v133,
          b2: &v130,
          b3: &v135,
          amount: &v129,
          f0: &v128,
          f1: &v127,
          f2: &v126,
          f3: v122);
        _R11 = &v129;
        _R10 = &v128;
        v80 = v123;
        _R9 = &v127;
        dstBytePitch = a18;
        _R8 = &v126;
        _R5 = v132;
        _R4 = v134;
        __asm { lvx128    v29, r0, r11 }
        _R3 = v136;
        __asm
        {
          lvx128    v28, r0, r10
          lvx128    v27, r0, r9
          lvx128    v26, r0, r8
          lvx128    v3, r0, r5
          lvx128    v25, r0, r4
          lvx128    v24, r0, r3
        }
      }
      __asm { vmr128    v63, v101 }
      dst = v81;
      __asm { vmr128    v23, v100 }
      if ( v80 != 0 )
      {
        for ( i = v80; i != 0; --i )
        {
          __asm { vand128   v46, v23, v25 }
          _R11 = v124;
          __asm { vmr128    v12, v112 }
          _R9 = v125;
          __asm { vor128    v0, v95, v63 }
          __asm
          {
            vcuxwfp128 v45, v46, 0
            lvx128    v13, r0, r11
            vadduws   v23, v23, v13
            stvx128   v0, r0, r9
            vmulfp128 v13, v77, v24
            vmaddcfp128 v12, v13, v12, v113
            vmaddcfp128 v12, v13, v12, v111
            vmaddcfp128 v13, v12, v13, v110
          }
          if ( v88 != 0 )
          {
            __asm { vspltw    v2, v13, 0 }
            _R11 = 4 * v82;
            __asm { vspltw    v1, v13, 1 }
            v113 = v88;
            __asm
            {
              vspltw    v31, v13, 2
              vspltw    v30, v13, 3
            }
            while ( 1 )
            {
              __asm
              {
                vmulfp128 v9, v127, v108
                vand128   v43, v0, v25
              }
              _R9 = v124;
              __asm
              {
                vmr128    v8, v112
                vmr128    v13, v126
              }
              _R8 = v125;
              __asm
              {
                vmr128    v7, v105
                vcuxwfp128 v42, v43, 0
                vmr128    v10, v104
                vmr128    v11, v102
                lvx128    v12, r0, r9
                vadduws   v6, v0, v12
                vmaddcfp128 v7, v127, v7, v106
                stvx128   v6, r0, r8
                vmulfp128 v41, v9, v107
                vmulfp128 v0, v74, v24
                vrfiz128  v12, v41
                vmaddcfp128 v8, v0, v8, v113
                vnmsubfp  v9, v12, v9, v13
                vmr       v13, v0
                vmaddcfp128 v13, v8, v13, v111
                vmr128    v8, v126
                vmaddcfp128 v8, v9, v8, v7
                vmaddcfp128 v0, v13, v0, v110
                vmulfp128 v40, v8, v103
                vmr128    v127, v8
                vmr128    v39, v0
                vspltw128 v38, v39, 3
                vspltw128 v0, v39, 2
                vspltw128 v13, v39, 1
                vspltw128 v12, v39, 0
                vmulfp128 v4, v122, v38
                vmulfp128 v5, v120, v38
                vmulfp128 v6, v118, v38
                vmulfp128 v7, v114, v38
                vrfiz128  v9, v40
                vmaddfp128 v4, v123, v0, v4
                vmaddfp   v5, v28, v5, v0
                vmaddfp   v6, v26, v6, v0
                vmaddcfp128 v0, v115, v0, v7
                vmr       v7, v13
                vnmsubfp128 v127, v9, v10, v127
                vmr128    v9, v109
                vmaddcfp128 v7, v124, v7, v4
                vmaddfp   v10, v29, v5, v13
                vmaddfp   v8, v27, v6, v13
                vmaddcfp128 v13, v116, v13, v0
                vmr128    v0, v127
                vnmsubfp128 v9, v0, v11, v9
                vmr       v0, v12
                vmr       v11, v12
                vmaddcfp128 v0, v125, v0, v7
                vmaddfp128 v10, v121, v12, v10
                vmaddcfp128 v11, v119, v11, v8
                vmaddfp128 v13, v117, v12, v13
                vmaddfp   v0, v0, v9, v2
                vmaddfp   v0, v10, v0, v1
                vmaddfp   v0, v11, v0, v31
                vmaddfp   v0, v13, v0, v30
                vcfpuxws128 v37, v0, 0
                vpkswus128 v36, v69, v37
                vpkuhus128 v35, v68, v36
                stvewx128 v35, r3, r11
              }
              _R11 += 4;
              if ( --v113 == 0 )
                break;
              _R9 = 16;
              _R8 = v124;
              _R5 = v125;
              __asm
              {
                lvx128    v44, r28, r9
                stvx128   v44, r0, r8
                lvx128    v0, r0, r5
              }
            }
            _R11 = 16;
            _R9 = v124;
            __asm
            {
              lvx128    v34, r28, r11
              stvx128   v34, r0, r9
            }
          }
          dst += dstBytePitch;
        }
        _R11 = v125;
        __asm { lvx128    v101, r0, r11 }
      }
      v82 += v88;
    }
    while ( v82 < 0x10 );
    v60 += v80;
    if ( v60 >= 0x10 )
      break;
    v56 = a24;
  }
}


// ========================================================================
// UpSample16x16_Bicubic_2
// EA  : 0x829348E0
// RVA : 0x009348E0
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_upsample.h
// ========================================================================

void __fastcall UpSample16x16_Bicubic_2(
        unsigned __int8 *dst,
        unsigned int dstX,
        unsigned int dstY,
        unsigned int dstBytePitch,
        const unsigned __int8 *src,
        unsigned int srcX,
        unsigned int srcY,
        unsigned int srcMaskY,
        int upsampleLevel,
        int sharpenScale,
        int noiseScale,
        int a12,
        int a13,
        unsigned int a14,
        int a15,
        unsigned int a16,
        int a17,
        unsigned int a18,
        int a19,
        int a20,
        int a21,
        unsigned int a22,
        int a23,
        unsigned int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32)
{
  int v33; // r5
  unsigned int v36; // r9
  int v37; // r8
  unsigned int v43; // r18
  int v46; // r9
  unsigned int v56; // r9
  int v59; // r21
  unsigned int v60; // r16
  char v61; // r20
  int v62; // r19
  int v64; // r22
  unsigned int v77; // r15
  unsigned int v79; // r11
  unsigned int v80; // r7
  unsigned __int8 *v81; // r14
  unsigned int v82; // r29
  unsigned int v83; // r27
  unsigned int v84; // r26
  unsigned int v85; // r25
  unsigned int v86; // r24
  unsigned int v87; // r11
  unsigned int v88; // r23
  int v92; // r8
  unsigned int i; // r10
  unsigned int v113; // ctr
  __vector4 *v122; // [sp+8h] [-3B8h]
  unsigned int v123; // [sp+60h] [-360h]
  _BYTE v124[16]; // [sp+70h] [-350h] BYREF
  _BYTE v125[16]; // [sp+80h] [-340h] BYREF
  __vector4 v126; // [sp+90h] [-330h] BYREF
  __vector4 v127; // [sp+A0h] [-320h] BYREF
  __vector4 v128; // [sp+B0h] [-310h] BYREF
  __vector4 v129; // [sp+C0h] [-300h] BYREF
  __vector4 v130; // [sp+D0h] [-2F0h] BYREF
  __vector4 v131; // [sp+E0h] [-2E0h] BYREF
  _BYTE v132[16]; // [sp+F0h] [-2D0h] BYREF
  __vector4 v133; // [sp+100h] [-2C0h] BYREF
  _BYTE v134[16]; // [sp+110h] [-2B0h] BYREF
  __vector4 v135; // [sp+120h] [-2A0h] BYREF
  _BYTE v136[496]; // [sp+130h] [-290h] BYREF

  a14 = dstX;
  a16 = dstY;
  v33 = dstY + srcY;
  _R31 = &a28;
  a18 = dstBytePitch;
  __asm { lvlx128   v63, r0, r31 }
  _R28 = vector_int_one_2;
  v36 = 2 * (dstX + srcX) - (1 << a28);
  __asm { vspltw128 v13, v63, 0 }
  v37 = 2 * v33;
  _R5 = &a14;
  _R31 = &a16;
  __asm { lvx128    v0, r0, r28 }
  _R29 = &a30;
  __asm { vadduws   v8, v13, v0 }
  _R4 = &vector_int_zero_2;
  _R27 = &a32;
  __asm
  {
    lvlx128   v62, r0, r5
    lvlx128   v61, r0, r31
  }
  v43 = v36 + 1;
  __asm
  {
    vspltw128 v60, v62, 0
    vslw      v5, v0, v8
    vspltw128 v59, v61, 0
    lvlx      v12, r0, r29
    lvx128    v3, r0, r4
  }
  a22 = v43;
  __asm { lvlx      v11, r0, r27 }
  _R4 = 32;
  __asm
  {
    vmrghb    v10, v3, v12
    vcuxwfp128 v12, v60, 0
    vmrghb    v9, v3, v11
    vcuxwfp128 v11, v59, 0
  }
  _R5 = 64;
  __asm { vsubuws   v25, v5, v0 }
  v46 = v37 - (1 << a28);
  __asm
  {
    vmrghh    v7, v3, v10
    lvx128    v63, r28, r4
    vmrghh    v6, v3, v9
  }
  _R4 = 192;
  _R31 = 208;
  __asm
  {
    vslw128   v4, v8, v63
    lvx128    v0, r28, r5
  }
  _R8 = 48;
  __asm { vcuxwfp128 v58, v7, 0 }
  _R27 = &a22;
  __asm { vcuxwfp128 v109, v6, 0 }
  _R29 = v136;
  __asm { lvx128    v62, r28, r4 }
  _R4 = 224;
  __asm { lvx128    v63, r28, r31 }
  _R31 = v134;
  __asm { lvx128    v13, r28, r8 }
  _R8 = v132;
  __asm { vmaddfp   v0, v11, v12, v0 }
  _R5 = &a24;
  __asm { vsubuws   v24, v13, v4 }
  v56 = v46 + 1;
  __asm { lvx128    v61, r28, r4 }
  a24 = v56;
  __asm
  {
    stvx128   v25, r0, r31
    stvx128   v3, r0, r8
  }
  __asm { lvlx128   v57, r0, r27 }
  v59 = 1 << a28;
  __asm { lvlx128   v56, r0, r5 }
  v60 = 0;
  __asm
  {
    stvx128   v24, r0, r29
    vmulfp128 v99, v90, v63
  }
  v61 = a28 + 1;
  __asm { vmulfp128 v102, v109, v62 }
  v62 = (1 << a28) - 1;
  __asm
  {
    vspltw128 v98, v57, 0
    vaddfp128 v127, v0, v61
  }
  _R11 = 16;
  v64 = a30;
  _R10 = v124;
  __asm { vspltw128 v23, v56, 0 }
  _R8 = 256;
  _R7 = 240;
  _R5 = 272;
  __asm { lvx128    v55, r28, r11 }
  _R4 = 288;
  _R11 = 80;
  __asm
  {
    stvx128   v55, r0, r10
    lvx128    v113, r28, r8
  }
  _R10 = 112;
  __asm { lvx128    v112, r28, r7 }
  _R8 = 128;
  __asm { lvx128    v111, r28, r5 }
  _R7 = 176;
  __asm { lvx128    v110, r28, r4 }
  _R5 = 96;
  __asm { lvx128    v108, r28, r11 }
  _R4 = 144;
  _R11 = 160;
  __asm
  {
    lvx128    v126, r28, r10
    lvx128    v107, r28, r8
  }
  v77 = v43 >> 1;
  __asm { lvx128    v106, r28, r7 }
  _R30 = 16;
  __asm
  {
    lvx128    v105, r28, r5
    lvx128    v104, r28, r4
    lvx128    v103, r28, r11
  }
  while ( 1 )
  {
    v79 = (2 * v60 + v56) >> v61;
    if ( 16 - v60 >= v59 - ((v60 + (v56 >> 1)) & v62) )
    {
      v123 = v59 - ((v60 + (v56 >> 1)) & v62);
      v80 = v123;
    }
    else
    {
      v80 = 16 - v60;
      v123 = 16 - v60;
    }
    __asm { vmr128    v101, v98 }
    __asm { vmr128    v100, v23 }
    v81 = dst;
    v82 = 0;
    v83 = ((v79 - 1) & srcMaskY) << 7;
    v84 = (v79 & srcMaskY) << 7;
    v85 = ((v79 + 1) & srcMaskY) << 7;
    v86 = ((v79 + 2) & srcMaskY) << 7;
    do
    {
      v87 = (2 * v82 + v43) >> v61;
      v88 = 16 - v82;
      if ( 16 - v82 >= v59 - ((v82 + v77) & v62) )
        v88 = v59 - ((v82 + v77) & v62);
      _R9 = &src[4 * v87 - 4 + 4 * v85];
      _R10 = &src[4 * v87 - 4 + 4 * v84];
      _R4 = &v130;
      __asm { lvlx128   v54, r0, r9 }
      __asm { lvrx128   v53, r30, r9 }
      __asm
      {
        lvlx128   v52, r0, r10
        vor128    v12, v86, v53
        lvrx128   v51, r30, r10
      }
      v92 = 4 * (v87 + v86);
      __asm { vor128    v13, v84, v51 }
      _R11 = &src[4 * v87 - 4 + 4 * v83];
      __asm
      {
        vmrghb    v8, v3, v12
        stvx128   v12, r0, r4
        vmrglb    v12, v3, v12
      }
      _R10 = &src[v92 - 4];
      __asm { vmrghb    v10, v3, v13 }
      _R9 = &v133;
      __asm
      {
        vmrglb    v9, v3, v13
        lvlx128   v50, r0, r11
        lvrx128   v49, r30, r11
        vmrglh    v11, v3, v8
        vmrghh    v7, v3, v12
      }
      _R8 = &v131;
      __asm
      {
        vmrglh    v6, v3, v10
        vor128    v0, v82, v49
        vmrghh    v5, v3, v9
        lvlx128   v48, r0, r10
        lvrx128   v47, r30, r10
        vcfux     v27, v11, 0
        vcfux     v26, v7, 0
      }
      _R5 = &v135;
      __asm
      {
        vcfux     v29, v6, 0
        stvx128   v13, r0, r9
        vcfux     v28, v5, 0
        vor128    v11, v80, v47
        vmrghb    v13, v3, v0
        stvx128   v0, r0, r8
        vmrglb    v0, v3, v0
      }
      _R4 = &v129;
      _R3 = &v128;
      __asm { vmrghh    v4, v3, v10 }
      _R11 = &v127;
      __asm { vmrghb    v7, v3, v11 }
      _R10 = &v126;
      __asm
      {
        stvx128   v11, r0, r5
        vmrglb    v11, v3, v11
      }
      __asm
      {
        vmrghh    v2, v3, v13
        vcuxwfp128 v121, v4, 0
        vmrglh    v1, v3, v13
        vmrghh    v31, v3, v0
        stvx128   v27, r0, r11
        vmrglh    v30, v3, v0
        stvx128   v26, r0, r10
        vmrglh    v23, v3, v9
        stvx128   v29, r0, r4
        vmrghh    v22, v3, v8
        stvx128   v28, r0, r3
        vmrglh    v21, v3, v12
        vcuxwfp128 v125, v2, 0
        vcuxwfp128 v124, v1, 0
        vmrghh    v20, v3, v7
        vcuxwfp128 v123, v31, 0
        vmrglh    v19, v3, v7
        vcuxwfp128 v122, v30, 0
        vmrghh    v18, v3, v11
        vcuxwfp128 v120, v23, 0
        vmrglh    v17, v3, v11
        vcuxwfp128 v119, v22, 0
        vcuxwfp128 v118, v21, 0
        vcuxwfp128 v117, v20, 0
        vcuxwfp128 v116, v19, 0
        vcuxwfp128 v115, v18, 0
        vcuxwfp128 v114, v17, 0
      }
      if ( v64 != 0 )
      {
        __asm { vmr128    v1, v99 }
        Sharpen4x4Center_Xenon(
          b0: &v131,
          b1: &v133,
          b2: &v130,
          b3: &v135,
          amount: &v129,
          f0: &v128,
          f1: &v127,
          f2: &v126,
          f3: v122);
        _R11 = &v129;
        _R10 = &v128;
        v80 = v123;
        _R9 = &v127;
        dstBytePitch = a18;
        _R8 = &v126;
        _R5 = v132;
        _R4 = v134;
        __asm { lvx128    v29, r0, r11 }
        _R3 = v136;
        __asm
        {
          lvx128    v28, r0, r10
          lvx128    v27, r0, r9
          lvx128    v26, r0, r8
          lvx128    v3, r0, r5
          lvx128    v25, r0, r4
          lvx128    v24, r0, r3
        }
      }
      __asm { vmr128    v63, v101 }
      dst = v81;
      __asm { vmr128    v23, v100 }
      if ( v80 != 0 )
      {
        for ( i = v80; i != 0; --i )
        {
          __asm { vand128   v46, v23, v25 }
          _R11 = v124;
          __asm { vmr128    v12, v112 }
          _R9 = v125;
          __asm { vor128    v0, v95, v63 }
          __asm
          {
            vcuxwfp128 v45, v46, 0
            lvx128    v13, r0, r11
            vadduws   v23, v23, v13
            stvx128   v0, r0, r9
            vmulfp128 v13, v77, v24
            vmaddcfp128 v12, v13, v12, v113
            vmaddcfp128 v12, v13, v12, v111
            vmaddcfp128 v13, v12, v13, v110
          }
          if ( v88 != 0 )
          {
            __asm { vspltw    v2, v13, 0 }
            _R11 = 4 * v82;
            __asm { vspltw    v1, v13, 1 }
            v113 = v88;
            __asm
            {
              vspltw    v31, v13, 2
              vspltw    v30, v13, 3
            }
            while ( 1 )
            {
              __asm
              {
                vmulfp128 v9, v127, v108
                vand128   v43, v0, v25
              }
              _R9 = v124;
              __asm
              {
                vmr128    v8, v112
                vmr128    v13, v126
              }
              _R8 = v125;
              __asm
              {
                vmr128    v7, v105
                vcuxwfp128 v42, v43, 0
                vmr128    v10, v104
                vmr128    v11, v102
                lvx128    v12, r0, r9
                vadduws   v6, v0, v12
                vmaddcfp128 v7, v127, v7, v106
                stvx128   v6, r0, r8
                vmulfp128 v41, v9, v107
                vmulfp128 v0, v74, v24
                vrfiz128  v12, v41
                vmaddcfp128 v8, v0, v8, v113
                vnmsubfp  v9, v12, v9, v13
                vmr       v13, v0
                vmaddcfp128 v13, v8, v13, v111
                vmr128    v8, v126
                vmaddcfp128 v8, v9, v8, v7
                vmaddcfp128 v0, v13, v0, v110
                vmulfp128 v40, v8, v103
                vmr128    v127, v8
                vmr128    v39, v0
                vspltw128 v38, v39, 3
                vspltw128 v0, v39, 2
                vspltw128 v13, v39, 1
                vspltw128 v12, v39, 0
                vmulfp128 v4, v122, v38
                vmulfp128 v5, v120, v38
                vmulfp128 v6, v118, v38
                vmulfp128 v7, v114, v38
                vrfiz128  v9, v40
                vmaddfp128 v4, v123, v0, v4
                vmaddfp   v5, v28, v5, v0
                vmaddfp   v6, v26, v6, v0
                vmaddcfp128 v0, v115, v0, v7
                vmr       v7, v13
                vnmsubfp128 v127, v9, v10, v127
                vmr128    v9, v109
                vmaddcfp128 v7, v124, v7, v4
                vmaddfp   v10, v29, v5, v13
                vmaddfp   v8, v27, v6, v13
                vmaddcfp128 v13, v116, v13, v0
                vmr128    v0, v127
                vnmsubfp128 v9, v0, v11, v9
                vmr       v0, v12
                vmr       v11, v12
                vmaddcfp128 v0, v125, v0, v7
                vmaddfp128 v10, v121, v12, v10
                vmaddcfp128 v11, v119, v11, v8
                vmaddfp128 v13, v117, v12, v13
                vmaddfp   v0, v0, v9, v2
                vmaddfp   v0, v10, v0, v1
                vmaddfp   v0, v11, v0, v31
                vmaddfp   v0, v13, v0, v30
                vcfpuxws128 v37, v0, 0
                vpkswus128 v36, v69, v37
                vpkuhus128 v35, v68, v36
                stvewx128 v35, r3, r11
              }
              _R11 += 4;
              if ( --v113 == 0 )
                break;
              _R9 = 16;
              _R8 = v124;
              _R5 = v125;
              __asm
              {
                lvx128    v44, r28, r9
                stvx128   v44, r0, r8
                lvx128    v0, r0, r5
              }
            }
            _R11 = 16;
            _R9 = v124;
            __asm
            {
              lvx128    v34, r28, r11
              stvx128   v34, r0, r9
            }
          }
          dst += dstBytePitch;
        }
        _R11 = v125;
        __asm { lvx128    v101, r0, r11 }
      }
      v82 += v88;
    }
    while ( v82 < 0x10 );
    v60 += v80;
    if ( v60 >= 0x10 )
      break;
    v56 = a24;
  }
}


// ========================================================================
// UpSample16x16_Bicubic_3
// EA  : 0x82937C20
// RVA : 0x00937C20
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_upsample.h
// ========================================================================

void __fastcall UpSample16x16_Bicubic_3(
        unsigned __int8 *dst,
        unsigned int dstX,
        unsigned int dstY,
        unsigned int dstBytePitch,
        const unsigned __int8 *src,
        unsigned int srcX,
        unsigned int srcY,
        unsigned int srcMaskY,
        int upsampleLevel,
        int sharpenScale,
        int noiseScale,
        int a12,
        int a13,
        unsigned int a14,
        int a15,
        unsigned int a16,
        int a17,
        unsigned int a18,
        int a19,
        int a20,
        int a21,
        unsigned int a22,
        int a23,
        unsigned int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32)
{
  int v33; // r5
  unsigned int v36; // r9
  int v37; // r8
  unsigned int v43; // r18
  int v46; // r9
  unsigned int v56; // r9
  int v59; // r21
  unsigned int v60; // r16
  char v61; // r20
  int v62; // r19
  int v64; // r22
  unsigned int v77; // r15
  unsigned int v79; // r11
  unsigned int v80; // r7
  unsigned __int8 *v81; // r14
  unsigned int v82; // r29
  unsigned int v83; // r27
  unsigned int v84; // r26
  unsigned int v85; // r25
  unsigned int v86; // r24
  unsigned int v87; // r11
  unsigned int v88; // r23
  int v92; // r8
  unsigned int i; // r10
  unsigned int v113; // ctr
  __vector4 *v122; // [sp+8h] [-3B8h]
  unsigned int v123; // [sp+60h] [-360h]
  _BYTE v124[16]; // [sp+70h] [-350h] BYREF
  _BYTE v125[16]; // [sp+80h] [-340h] BYREF
  __vector4 v126; // [sp+90h] [-330h] BYREF
  __vector4 v127; // [sp+A0h] [-320h] BYREF
  __vector4 v128; // [sp+B0h] [-310h] BYREF
  __vector4 v129; // [sp+C0h] [-300h] BYREF
  __vector4 v130; // [sp+D0h] [-2F0h] BYREF
  __vector4 v131; // [sp+E0h] [-2E0h] BYREF
  _BYTE v132[16]; // [sp+F0h] [-2D0h] BYREF
  __vector4 v133; // [sp+100h] [-2C0h] BYREF
  _BYTE v134[16]; // [sp+110h] [-2B0h] BYREF
  __vector4 v135; // [sp+120h] [-2A0h] BYREF
  _BYTE v136[496]; // [sp+130h] [-290h] BYREF

  a14 = dstX;
  a16 = dstY;
  v33 = dstY + srcY;
  _R31 = &a28;
  a18 = dstBytePitch;
  __asm { lvlx128   v63, r0, r31 }
  _R28 = vector_int_one_3;
  v36 = 2 * (dstX + srcX) - (1 << a28);
  __asm { vspltw128 v13, v63, 0 }
  v37 = 2 * v33;
  _R5 = &a14;
  _R31 = &a16;
  __asm { lvx128    v0, r0, r28 }
  _R29 = &a30;
  __asm { vadduws   v8, v13, v0 }
  _R4 = &vector_int_zero_3;
  _R27 = &a32;
  __asm
  {
    lvlx128   v62, r0, r5
    lvlx128   v61, r0, r31
  }
  v43 = v36 + 1;
  __asm
  {
    vspltw128 v60, v62, 0
    vslw      v5, v0, v8
    vspltw128 v59, v61, 0
    lvlx      v12, r0, r29
    lvx128    v3, r0, r4
  }
  a22 = v43;
  __asm { lvlx      v11, r0, r27 }
  _R4 = 32;
  __asm
  {
    vmrghb    v10, v3, v12
    vcuxwfp128 v12, v60, 0
    vmrghb    v9, v3, v11
    vcuxwfp128 v11, v59, 0
  }
  _R5 = 64;
  __asm { vsubuws   v25, v5, v0 }
  v46 = v37 - (1 << a28);
  __asm
  {
    vmrghh    v7, v3, v10
    lvx128    v63, r28, r4
    vmrghh    v6, v3, v9
  }
  _R4 = 192;
  _R31 = 208;
  __asm
  {
    vslw128   v4, v8, v63
    lvx128    v0, r28, r5
  }
  _R8 = 48;
  __asm { vcuxwfp128 v58, v7, 0 }
  _R27 = &a22;
  __asm { vcuxwfp128 v109, v6, 0 }
  _R29 = v136;
  __asm { lvx128    v62, r28, r4 }
  _R4 = 224;
  __asm { lvx128    v63, r28, r31 }
  _R31 = v134;
  __asm { lvx128    v13, r28, r8 }
  _R8 = v132;
  __asm { vmaddfp   v0, v11, v12, v0 }
  _R5 = &a24;
  __asm { vsubuws   v24, v13, v4 }
  v56 = v46 + 1;
  __asm { lvx128    v61, r28, r4 }
  a24 = v56;
  __asm
  {
    stvx128   v25, r0, r31
    stvx128   v3, r0, r8
  }
  __asm { lvlx128   v57, r0, r27 }
  v59 = 1 << a28;
  __asm { lvlx128   v56, r0, r5 }
  v60 = 0;
  __asm
  {
    stvx128   v24, r0, r29
    vmulfp128 v99, v90, v63
  }
  v61 = a28 + 1;
  __asm { vmulfp128 v102, v109, v62 }
  v62 = (1 << a28) - 1;
  __asm
  {
    vspltw128 v98, v57, 0
    vaddfp128 v127, v0, v61
  }
  _R11 = 16;
  v64 = a30;
  _R10 = v124;
  __asm { vspltw128 v23, v56, 0 }
  _R8 = 256;
  _R7 = 240;
  _R5 = 272;
  __asm { lvx128    v55, r28, r11 }
  _R4 = 288;
  _R11 = 80;
  __asm
  {
    stvx128   v55, r0, r10
    lvx128    v113, r28, r8
  }
  _R10 = 112;
  __asm { lvx128    v112, r28, r7 }
  _R8 = 128;
  __asm { lvx128    v111, r28, r5 }
  _R7 = 176;
  __asm { lvx128    v110, r28, r4 }
  _R5 = 96;
  __asm { lvx128    v108, r28, r11 }
  _R4 = 144;
  _R11 = 160;
  __asm
  {
    lvx128    v126, r28, r10
    lvx128    v107, r28, r8
  }
  v77 = v43 >> 1;
  __asm { lvx128    v106, r28, r7 }
  _R30 = 16;
  __asm
  {
    lvx128    v105, r28, r5
    lvx128    v104, r28, r4
    lvx128    v103, r28, r11
  }
  while ( 1 )
  {
    v79 = (2 * v60 + v56) >> v61;
    if ( 16 - v60 >= v59 - ((v60 + (v56 >> 1)) & v62) )
    {
      v123 = v59 - ((v60 + (v56 >> 1)) & v62);
      v80 = v123;
    }
    else
    {
      v80 = 16 - v60;
      v123 = 16 - v60;
    }
    __asm { vmr128    v101, v98 }
    __asm { vmr128    v100, v23 }
    v81 = dst;
    v82 = 0;
    v83 = ((v79 - 1) & srcMaskY) << 7;
    v84 = (v79 & srcMaskY) << 7;
    v85 = ((v79 + 1) & srcMaskY) << 7;
    v86 = ((v79 + 2) & srcMaskY) << 7;
    do
    {
      v87 = (2 * v82 + v43) >> v61;
      v88 = 16 - v82;
      if ( 16 - v82 >= v59 - ((v82 + v77) & v62) )
        v88 = v59 - ((v82 + v77) & v62);
      _R9 = &src[4 * v87 - 4 + 4 * v85];
      _R10 = &src[4 * v87 - 4 + 4 * v84];
      _R4 = &v130;
      __asm { lvlx128   v54, r0, r9 }
      __asm { lvrx128   v53, r30, r9 }
      __asm
      {
        lvlx128   v52, r0, r10
        vor128    v12, v86, v53
        lvrx128   v51, r30, r10
      }
      v92 = 4 * (v87 + v86);
      __asm { vor128    v13, v84, v51 }
      _R11 = &src[4 * v87 - 4 + 4 * v83];
      __asm
      {
        vmrghb    v8, v3, v12
        stvx128   v12, r0, r4
        vmrglb    v12, v3, v12
      }
      _R10 = &src[v92 - 4];
      __asm { vmrghb    v10, v3, v13 }
      _R9 = &v133;
      __asm
      {
        vmrglb    v9, v3, v13
        lvlx128   v50, r0, r11
        lvrx128   v49, r30, r11
        vmrglh    v11, v3, v8
        vmrghh    v7, v3, v12
      }
      _R8 = &v131;
      __asm
      {
        vmrglh    v6, v3, v10
        vor128    v0, v82, v49
        vmrghh    v5, v3, v9
        lvlx128   v48, r0, r10
        lvrx128   v47, r30, r10
        vcfux     v27, v11, 0
        vcfux     v26, v7, 0
      }
      _R5 = &v135;
      __asm
      {
        vcfux     v29, v6, 0
        stvx128   v13, r0, r9
        vcfux     v28, v5, 0
        vor128    v11, v80, v47
        vmrghb    v13, v3, v0
        stvx128   v0, r0, r8
        vmrglb    v0, v3, v0
      }
      _R4 = &v129;
      _R3 = &v128;
      __asm { vmrghh    v4, v3, v10 }
      _R11 = &v127;
      __asm { vmrghb    v7, v3, v11 }
      _R10 = &v126;
      __asm
      {
        stvx128   v11, r0, r5
        vmrglb    v11, v3, v11
      }
      __asm
      {
        vmrghh    v2, v3, v13
        vcuxwfp128 v121, v4, 0
        vmrglh    v1, v3, v13
        vmrghh    v31, v3, v0
        stvx128   v27, r0, r11
        vmrglh    v30, v3, v0
        stvx128   v26, r0, r10
        vmrglh    v23, v3, v9
        stvx128   v29, r0, r4
        vmrghh    v22, v3, v8
        stvx128   v28, r0, r3
        vmrglh    v21, v3, v12
        vcuxwfp128 v125, v2, 0
        vcuxwfp128 v124, v1, 0
        vmrghh    v20, v3, v7
        vcuxwfp128 v123, v31, 0
        vmrglh    v19, v3, v7
        vcuxwfp128 v122, v30, 0
        vmrghh    v18, v3, v11
        vcuxwfp128 v120, v23, 0
        vmrglh    v17, v3, v11
        vcuxwfp128 v119, v22, 0
        vcuxwfp128 v118, v21, 0
        vcuxwfp128 v117, v20, 0
        vcuxwfp128 v116, v19, 0
        vcuxwfp128 v115, v18, 0
        vcuxwfp128 v114, v17, 0
      }
      if ( v64 != 0 )
      {
        __asm { vmr128    v1, v99 }
        Sharpen4x4Center_Xenon(
          b0: &v131,
          b1: &v133,
          b2: &v130,
          b3: &v135,
          amount: &v129,
          f0: &v128,
          f1: &v127,
          f2: &v126,
          f3: v122);
        _R11 = &v129;
        _R10 = &v128;
        v80 = v123;
        _R9 = &v127;
        dstBytePitch = a18;
        _R8 = &v126;
        _R5 = v132;
        _R4 = v134;
        __asm { lvx128    v29, r0, r11 }
        _R3 = v136;
        __asm
        {
          lvx128    v28, r0, r10
          lvx128    v27, r0, r9
          lvx128    v26, r0, r8
          lvx128    v3, r0, r5
          lvx128    v25, r0, r4
          lvx128    v24, r0, r3
        }
      }
      __asm { vmr128    v63, v101 }
      dst = v81;
      __asm { vmr128    v23, v100 }
      if ( v80 != 0 )
      {
        for ( i = v80; i != 0; --i )
        {
          __asm { vand128   v46, v23, v25 }
          _R11 = v124;
          __asm { vmr128    v12, v112 }
          _R9 = v125;
          __asm { vor128    v0, v95, v63 }
          __asm
          {
            vcuxwfp128 v45, v46, 0
            lvx128    v13, r0, r11
            vadduws   v23, v23, v13
            stvx128   v0, r0, r9
            vmulfp128 v13, v77, v24
            vmaddcfp128 v12, v13, v12, v113
            vmaddcfp128 v12, v13, v12, v111
            vmaddcfp128 v13, v12, v13, v110
          }
          if ( v88 != 0 )
          {
            __asm { vspltw    v2, v13, 0 }
            _R11 = 4 * v82;
            __asm { vspltw    v1, v13, 1 }
            v113 = v88;
            __asm
            {
              vspltw    v31, v13, 2
              vspltw    v30, v13, 3
            }
            while ( 1 )
            {
              __asm
              {
                vmulfp128 v9, v127, v108
                vand128   v43, v0, v25
              }
              _R9 = v124;
              __asm
              {
                vmr128    v8, v112
                vmr128    v13, v126
              }
              _R8 = v125;
              __asm
              {
                vmr128    v7, v105
                vcuxwfp128 v42, v43, 0
                vmr128    v10, v104
                vmr128    v11, v102
                lvx128    v12, r0, r9
                vadduws   v6, v0, v12
                vmaddcfp128 v7, v127, v7, v106
                stvx128   v6, r0, r8
                vmulfp128 v41, v9, v107
                vmulfp128 v0, v74, v24
                vrfiz128  v12, v41
                vmaddcfp128 v8, v0, v8, v113
                vnmsubfp  v9, v12, v9, v13
                vmr       v13, v0
                vmaddcfp128 v13, v8, v13, v111
                vmr128    v8, v126
                vmaddcfp128 v8, v9, v8, v7
                vmaddcfp128 v0, v13, v0, v110
                vmulfp128 v40, v8, v103
                vmr128    v127, v8
                vmr128    v39, v0
                vspltw128 v38, v39, 3
                vspltw128 v0, v39, 2
                vspltw128 v13, v39, 1
                vspltw128 v12, v39, 0
                vmulfp128 v4, v122, v38
                vmulfp128 v5, v120, v38
                vmulfp128 v6, v118, v38
                vmulfp128 v7, v114, v38
                vrfiz128  v9, v40
                vmaddfp128 v4, v123, v0, v4
                vmaddfp   v5, v28, v5, v0
                vmaddfp   v6, v26, v6, v0
                vmaddcfp128 v0, v115, v0, v7
                vmr       v7, v13
                vnmsubfp128 v127, v9, v10, v127
                vmr128    v9, v109
                vmaddcfp128 v7, v124, v7, v4
                vmaddfp   v10, v29, v5, v13
                vmaddfp   v8, v27, v6, v13
                vmaddcfp128 v13, v116, v13, v0
                vmr128    v0, v127
                vnmsubfp128 v9, v0, v11, v9
                vmr       v0, v12
                vmr       v11, v12
                vmaddcfp128 v0, v125, v0, v7
                vmaddfp128 v10, v121, v12, v10
                vmaddcfp128 v11, v119, v11, v8
                vmaddfp128 v13, v117, v12, v13
                vmaddfp   v0, v0, v9, v2
                vmaddfp   v0, v10, v0, v1
                vmaddfp   v0, v11, v0, v31
                vmaddfp   v0, v13, v0, v30
                vcfpuxws128 v37, v0, 0
                vpkswus128 v36, v69, v37
                vpkuhus128 v35, v68, v36
                stvewx128 v35, r3, r11
              }
              _R11 += 4;
              if ( --v113 == 0 )
                break;
              _R9 = 16;
              _R8 = v124;
              _R5 = v125;
              __asm
              {
                lvx128    v44, r28, r9
                stvx128   v44, r0, r8
                lvx128    v0, r0, r5
              }
            }
            _R11 = 16;
            _R9 = v124;
            __asm
            {
              lvx128    v34, r28, r11
              stvx128   v34, r0, r9
            }
          }
          dst += dstBytePitch;
        }
        _R11 = v125;
        __asm { lvx128    v101, r0, r11 }
      }
      v82 += v88;
    }
    while ( v82 < 0x10 );
    v60 += v80;
    if ( v60 >= 0x10 )
      break;
    v56 = a24;
  }
}


// ========================================================================
// `dynamic initializer for 'vector_int_zero''
// EA  : 0x83358058
// RVA : 0x01358058
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_upsample.h
// ========================================================================

void _dynamic_initializer_for__vector_int_zero__()
{
  __asm { vspltisw128 v63, 0 }
  _R10 = &vector_int_zero;
  __asm { stvx128   v63, r0, r10 }
}


// ========================================================================
// `dynamic initializer for 'vector_int_zero''_0
// EA  : 0x833580B0
// RVA : 0x013580B0
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_upsample.h
// ========================================================================

void _dynamic_initializer_for__vector_int_zero___0()
{
  __asm { vspltisw128 v63, 0 }
  _R10 = &vector_int_zero_0;
  __asm { stvx128   v63, r0, r10 }
}


// ========================================================================
// `dynamic initializer for 'vector_int_zero''_1
// EA  : 0x83358108
// RVA : 0x01358108
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_upsample.h
// ========================================================================

void _dynamic_initializer_for__vector_int_zero___1()
{
  __asm { vspltisw128 v63, 0 }
  _R10 = &vector_int_zero_1;
  __asm { stvx128   v63, r0, r10 }
}


// ========================================================================
// `dynamic initializer for 'vector_int_zero''_2
// EA  : 0x83358160
// RVA : 0x01358160
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_upsample.h
// ========================================================================

void _dynamic_initializer_for__vector_int_zero___2()
{
  __asm { vspltisw128 v63, 0 }
  _R10 = &vector_int_zero_2;
  __asm { stvx128   v63, r0, r10 }
}


// ========================================================================
// `dynamic initializer for 'vector_int_zero''_3
// EA  : 0x833581B8
// RVA : 0x013581B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_upsample.h
// ========================================================================

void _dynamic_initializer_for__vector_int_zero___3()
{
  __asm { vspltisw128 v63, 0 }
  _R10 = &vector_int_zero_3;
  __asm { stvx128   v63, r0, r10 }
}

