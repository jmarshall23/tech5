
// ========================================================================
// ?EmitColorAlphaIndices_Xenon@idDxtEncoder@@AAAXABU__vector4@@00000PAE@Z
// EA  : 0x82926030
// RVA : 0x00926030
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder_xenon.cpp
// ========================================================================

void __fastcall idDxtEncoder::EmitColorAlphaIndices_Xenon(
        idDxtEncoder *this,
        const __vector4 *block0,
        const __vector4 *block1,
        const __vector4 *block2,
        const __vector4 *block3,
        const __vector4 *minColor,
        const __vector4 *maxColor,
        unsigned __int8 *outPtr)
{
  __asm { lvx128    v62, r0, r8 }
  _R8 = 16;
  __asm { lvx128    v61, r0, r9 }
  _R3 = vmxi_byte_perm_565_colors;
  __asm { vspltisw128 v59, 5 }
  _R11 = -48;
  __asm { vspltisw128 v58, 3 }
  _R9 = -64;
  __asm { vspltisb  v0, 0 }
  _R31 = -80;
  __asm { vspltish  v4, 1 }
  _R30 = -32;
  __asm
  {
    vspltisb  v31, 2
    lvx128    v7, r3, r8
  }
  _R8 = -16;
  __asm { lvx128    v63, r3, r11 }
  _R11 = 144;
  __asm
  {
    vperm128  v13, v93, v62, v7
    lvx128    v62, r3, r9
    lvx128    v60, r3, r31
  }
  _R9 = 160;
  __asm { lvx128    v5, r0, r3 }
  _R31 = 128;
  __asm { lvx128    v61, r3, r30 }
  _R30 = 176;
  __asm
  {
    vand128   v57, v13, v63
    lvx128    v12, r3, r8
    vand128   v56, v13, v62
  }
  _R8 = -112;
  __asm { vand128   v55, v13, v60 }
  _R29 = 4;
  __asm
  {
    vand128   v54, v13, v61
    vspltisb  v30, 1
    vslw128   v53, v89, v59
    vslw128   v52, v88, v58
    vsrb      v29, v13, v12
    vor128    v51, v84, v53
    vor128    v13, v86, v29
    vor128    v63, v87, v51
    vmrghb    v12, v0, v13
    vspltb    v11, v13, 4
    vspltb    v10, v13, 0
    vperm128  v50, v95, v63, v5
    vpermwi128 v28, v12, 0xB1
    vspltb    v8, v13, 1
    vspltb    v9, v13, 5
    vspltb    v7, v13, 6
    vadduhs   v27, v12, v28
    vspltb    v6, v13, 2
    stvewx128 v50, r0, r10
    lvx128    v61, r0, r6
    lvx128    v60, r0, r4
    vsrh      v13, v27, v4
    lvx128    v2, r3, r11
    lvx128    v1, r3, r9
    lvx128    v63, r0, r7
    lvx128    v62, r0, r5
    vspltb    v4, v13, 3
    lvx128    v5, r3, r31
    vperm128  v49, v94, v63, v5
    vperm128  v48, v92, v61, v5
    vspltb    v5, v13, 1
    vspltb    v3, v13, 5
    vperm128  v47, v94, v63, v2
    vmrghw128 v13, v80, v49
    vperm128  v46, v92, v61, v1
    vperm128  v45, v94, v63, v1
    vperm128  v44, v92, v61, v2
    vsububs   v24, v10, v13
    vmrghw128 v12, v78, v47
    vsububs   v23, v13, v10
    vsububs   v26, v11, v13
    vsububs   v25, v13, v11
    vmrghw128 v11, v76, v45
    vsububs   v22, v5, v13
    vsububs   v21, v13, v5
    vsububs   v20, v8, v12
    vsububs   v19, v12, v8
    vsububs   v18, v4, v12
    vor       v13, v23, v24
    vsububs   v17, v12, v4
    lvx128    v5, r3, r30
    vsububs   v16, v9, v12
    vmrghb    v14, v0, v13
    vsububs   v15, v12, v9
    vmrglb    v2, v0, v13
    vperm128  v43, v94, v63, v5
    vor       v8, v19, v20
    vperm128  v42, v92, v61, v5
    vor       v13, v25, v26
    vor       v5, v17, v18
    lvx128    v4, r3, r8
    vor       v12, v15, v16
  }
  _R7 = 688;
  __asm
  {
    vor       v10, v21, v22
    vmrghb    v17, v0, v8
    vsububs   v20, v7, v11
    vmrghb    v25, v0, v13
    vsububs   v18, v11, v7
    vmrglb    v23, v0, v13
    vsububs   v28, v6, v11
    vmrghb    v21, v0, v12
    vsububs   v26, v11, v6
    vmrglb    v19, v0, v12
    vsububs   v24, v3, v11
    vmrghb    v29, v0, v10
    vsububs   v22, v11, v3
    vmrglb    v27, v0, v10
    vmrglb    v12, v0, v5
    vor       v13, v18, v20
    vmrghb    v16, v0, v5
    vor       v10, v26, v28
    vmrglb    v15, v0, v8
    vadduhs   v11, v25, v21
    vor       v9, v22, v24
    vmrghw128 v1, v74, v43
    vadduhs   v28, v27, v12
    vmrghb    v25, v0, v13
    vadduhs   v5, v29, v16
    vmrghb    v8, v0, v10
    vmrglb    v29, v0, v13
    vadduhs   v26, v23, v19
    vmrghb    v6, v0, v9
    vadduhs   v7, v14, v17
    vmrglb    v3, v0, v10
    vadduhs   v2, v2, v15
    vmrglb    v27, v0, v9
    vadduhs   v0, v11, v25
    vadduhs   v11, v26, v29
  }
  _R6 = 32;
  __asm
  {
    vadduhs   v12, v7, v8
    vspltisw128 v41, 6
    vadduhs   v13, v5, v6
    vspltisw128 v40, 4
    vadduhs   v10, v2, v3
    vspltisw128 v39, 0xE
    vadduhs   v9, v28, v27
    lvx128    v63, r3, r7
    vcmpgtuh  v21, v12, v0
    vcmpgtuh  v22, v13, v0
    lvx128    v0, r3, r6
    vcmpgtuh  v23, v13, v12
    vcmpgtuh  v20, v9, v10
    vcmpgtuh  v19, v9, v11
    vcmpgtuh  v18, v10, v11
    vcmpgtub  v24, v1, v4
    vpkuhus128 v38, v23, v20
    vpkuhus128 v37, v22, v19
    vpkuhus128 v36, v21, v18
    vnot128   v35, v24
    vand128   v34, v69, v38
    vxor128   v33, v70, v36
    vor128    v32, v66, v35
    vor128    v62, v65, v35
    vand128   v61, v64, v31
    vand128   v60, v94, v30
    vor128    v59, v92, v61
    vsrw128   v58, v91, v63
    vslw128   v57, v91, v41
    vsrw128   v56, v91, v40
    vsrw128   v55, v91, v39
    vor128    v54, v88, v57
    vor128    v53, v90, v55
    vor128    v63, v85, v54
    vperm128  v52, v95, v63, v0
    stvewx128 v52, r10, r29
  }
}


// ========================================================================
// ?EmitGreenIndices_Xenon@idDxtEncoder@@AAAXABU__vector4@@00000PAE@Z
// EA  : 0x829262D8
// RVA : 0x009262D8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder_xenon.cpp
// ========================================================================

void __fastcall idDxtEncoder::EmitGreenIndices_Xenon(
        idDxtEncoder *this,
        const __vector4 *block0,
        const __vector4 *block1,
        const __vector4 *block2,
        const __vector4 *block3,
        const __vector4 *minGreen,
        const __vector4 *maxGreen,
        unsigned __int8 *outPtr)
{
  __asm
  {
    lvx128    v63, r0, r9
    lvx128    v62, r0, r8
  }
  _R9 = 16;
  _R8 = vmxi_byte_perm_565_colors;
  __asm { vspltisw128 v58, 5 }
  _R3 = -48;
  __asm { vspltisw128 v57, 3 }
  _R11 = -64;
  __asm { vspltisb  v0, 0 }
  _R31 = 192;
  __asm { vspltisw128 v56, 7 }
  _R30 = -80;
  __asm
  {
    vspltisw128 v55, 9
    lvx128    v7, r8, r9
  }
  _R9 = 800;
  __asm { lvx128    v61, r8, r3 }
  _R3 = 816;
  __asm
  {
    vperm128  v54, v94, v63, v7
    lvx128    v60, r8, r11
    lvx128    v7, r8, r31
  }
  _R11 = 720;
  __asm
  {
    lvx128    v59, r8, r30
    vspltisw128 v53, 1
    vperm128  v13, v95, v0, v7
    lvx128    v63, r8, r9
    vand128   v51, v86, v61
    lvx128    v6, r0, r8
    vand128   v50, v86, v60
    vperm128  v0, v94, v0, v7
    vand128   v49, v86, v59
    lvx128    v62, r8, r3
    vslw128   v10, v13, v63
    lvx128    v11, r8, r11
    vslw128   v48, v83, v58
  }
  _R9 = 144;
  __asm
  {
    vslw128   v46, v82, v57
    vspltisw128 v52, 0xC
    vslw128   v8, v0, v62
  }
  _R3 = 4;
  __asm
  {
    vadduws   v4, v10, v13
    vspltisb  v12, 1
    vspltisb  v9, 3
  }
  _R11 = 688;
  __asm
  {
    vor128    v43, v78, v48
    vspltisb  v5, 2
    vadduws   v3, v8, v0
    vspltisw128 v47, 6
    vadduws   v2, v4, v11
    vspltisw128 v45, 4
    vspltisw128 v44, 0xE
    vor128    v63, v81, v43
    vadduws   v0, v2, v3
    vperm128  v42, v95, v63, v6
    vslw128   v1, v0, v57
    vslw128   v31, v0, v58
    vslw128   v30, v0, v56
    vslw128   v29, v0, v55
    vslw128   v28, v0, v53
    stvewx128 v42, r0, r10
    vadduws   v27, v31, v1
    lvx128    v39, r0, r7
    lvx128    v38, r0, r5
    vadduws   v26, v29, v30
    vadduws   v25, v28, v0
    lvx128    v7, r8, r9
    lvx128    v41, r0, r6
    lvx128    v40, r0, r4
    vperm128  v36, v72, v41, v7
    vadduws   v24, v26, v27
    vperm128  v37, v70, v39, v7
    vadduws   v23, v24, v25
    vmrghw128 v13, v68, v37
    vsrw128   v0, v23, v52
    vspltb    v22, v0, 6
    vspltb    v21, v0, 2
    vspltb    v20, v0, 0xA
    vcmpgtub  v19, v22, v13
    vcmpgtub  v18, v21, v13
    vcmpgtub  v17, v20, v13
    vaddsbs   v16, v18, v19
    vaddsbs   v15, v16, v17
    lvx128    v63, r8, r11
  }
  _R9 = 32;
  __asm
  {
    vsubsbs   v14, v12, v15
    lvx128    v7, r8, r9
    vand      v0, v14, v9
    vcmpgtub  v13, v5, v0
    vand128   v35, v13, v12
    vxor128   v34, v0, v35
    vsrw128   v33, v66, v63
    vsrw128   v63, v66, v45
    vslw128   v32, v66, v47
    vsrw128   v62, v66, v44
    vor128    v61, v95, v32
    vor128    v60, v65, v62
    vor128    v63, v92, v61
    vperm128  v59, v95, v63, v7
    stvewx128 v59, r10, r3
  }
}


// ========================================================================
// ?EmitAlphaIndices_Xenon@idDxtEncoder@@AAAXABU__vector4@@00000PAE@Z
// EA  : 0x82926478
// RVA : 0x00926478
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder_xenon.cpp
// ========================================================================

void __fastcall idDxtEncoder::EmitAlphaIndices_Xenon(
        idDxtEncoder *this,
        const __vector4 *block0,
        const __vector4 *block1,
        const __vector4 *block2,
        const __vector4 *block3,
        const __vector4 *minColor,
        const __vector4 *maxColor,
        unsigned __int8 *outPtr)
{
  __asm { lvx128    v58, r0, r8 }
  _R8 = 608;
  __asm { lvx128    v57, r0, r9 }
  _R3 = vmxi_byte_perm_alpha_dst2;
  __asm { vspltisw  v11, 7 }
  _R11 = 688;
  __asm { vspltisw128 v56, 2 }
  _R9 = 672;
  __asm { vspltisw128 v55, 5 }
  _R31 = 656;
  __asm { vspltisw128 v54, 8 }
  _R30 = 640;
  __asm
  {
    vspltisw128 v53, 0xB
    lvx128    v63, r3, r8
  }
  _R8 = -32;
  __asm
  {
    vand128   v13, v90, v63
    lvx128    v62, r3, r11
    vand128   v12, v89, v63
    lvx128    v63, r3, r9
    lvx128    v61, r3, r31
    vspltisw128 v52, 0xF
    lvx128    v60, r3, r30
    vspltisb  v10, 1
    vslw128   v9, v13, v62
    lvx128    v0, r3, r8
    vslw128   v8, v13, v63
    lvx128    v51, r0, r6
    vslw128   v7, v12, v61
    lvx128    v50, r0, r4
    vslw128   v6, v12, v60
    lvx128    v49, r0, r7
    vslw128   v5, v13, v61
    lvx128    v48, r0, r5
    vslw128   v4, v13, v60
    vperm128  v47, v82, v51, v0
    vslw128   v3, v12, v62
    vperm128  v46, v80, v49, v0
    vslw128   v2, v12, v63
    vspltisb  v1, 7
    vadduws   v31, v8, v9
    vadduws   v30, v6, v7
    vadduws   v29, v4, v5
    vmrglw128 v0, v78, v47
    vadduws   v28, v2, v3
    vsubuws   v27, v31, v13
    vadduws   v26, v30, v12
    vadduws   v25, v29, v13
    vsubuws   v24, v28, v12
    vadduws   v23, v26, v27
    vadduws   v22, v24, v25
    vadduws   v13, v23, v11
    vadduws   v12, v22, v11
    vslw128   v21, v13, v56
    vslw128   v20, v13, v55
    vslw128   v19, v13, v54
    vslw128   v18, v13, v53
    vslw128   v17, v12, v56
    vslw128   v16, v12, v55
    vslw128   v15, v12, v54
    vslw128   v14, v12, v53
    vadduws   v11, v20, v21
    vadduws   v9, v18, v19
    vadduws   v8, v16, v17
    vadduws   v7, v14, v15
    vadduws   v6, v9, v11
    vadduws   v5, v7, v8
    vadduws   v4, v6, v13
    vadduws   v3, v5, v12
    vsrw128   v12, v4, v52
    vsrw128   v13, v3, v52
    vspltb    v2, v12, 7
    vspltb    v31, v12, 0xB
    vspltb    v30, v13, 0xB
    vspltb    v29, v13, 7
    vspltb    v28, v13, 3
    vcmpgtub  v27, v2, v0
    vspltb    v26, v12, 0xF
    vcmpgtub  v25, v31, v0
    vspltb    v24, v13, 0xF
    vcmpgtub  v23, v30, v0
    vcmpgtub  v22, v29, v0
    vspltisb  v21, 2
    vcmpgtub  v20, v28, v0
    vspltisw128 v45, 0xA
    vcmpgtub  v19, v26, v0
  }
  _R7 = 736;
  __asm { vcmpgtub  v18, v24, v0 }
  _R6 = 784;
  __asm { vaddsbs   v17, v22, v23 }
  _R5 = 768;
  __asm { vaddsbs   v16, v27, v20 }
  _R4 = 752;
  __asm { vaddsbs   v15, v19, v25 }
  _R11 = 800;
  __asm
  {
    lvx128    v63, r3, r7
    vspltisb  v14, 4
    vaddsbs   v0, v17, v18
    lvx128    v62, r3, r6
    lvx128    v61, r3, r5
  }
  _R9 = -16;
  __asm
  {
    vaddsbs   v13, v15, v16
    lvx128    v60, r3, r4
    lvx128    v59, r3, r11
    vmrglw128 v44, v90, v57
  }
  _R8 = 4;
  __asm
  {
    vaddsbs   v12, v13, v0
    lvx128    v7, r3, r9
    vsubsbs   v11, v10, v12
    vand      v0, v11, v1
    vcmpgtub  v9, v21, v0
    vand128   v43, v9, v10
    vxor128   v42, v0, v43
    vsrw128   v41, v74, v52
    vsrw128   v40, v74, v45
    vsrw128   v39, v74, v55
    vand128   v38, v74, v63
    vand128   v37, v73, v62
    vand128   v36, v72, v61
    vand128   v35, v71, v60
    vor128    v34, v68, v37
    vor128    v33, v70, v35
    vor128    v32, v65, v34
    vslw128   v8, v64, v59
    vsr       v0, v8, v14
    vperm128  v63, v76, v0, v7
    stvewx128 v63, r0, r10
    lvx128    v7, r0, r3
    vperm128  v62, v0, v0, v7
    stvewx128 v62, r10, r8
  }
}


// ========================================================================
// ?CompressImageDXT1Fast_Xenon@idDxtEncoder@@QAAXPIBEPIAEHH@Z
// EA  : 0x82926698
// RVA : 0x00926698
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder_xenon.cpp
// ========================================================================

void __fastcall idDxtEncoder::CompressImageDXT1Fast_Xenon(
        idDxtEncoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height)
{
  int srcPadding; // r29
  int dstPadding; // r27
  unsigned int v11; // r3
  unsigned int v34; // ctr
  _BYTE v45[16]; // [sp+0h] [-C0h] BYREF
  _BYTE back_chain[16]; // [sp+10h] [-B0h] BYREF
  _BYTE v47[16]; // [sp+20h] [-A0h] BYREF
  _BYTE v48[16]; // [sp+30h] [-90h] BYREF
  _BYTE v49[16]; // [sp+40h] [-80h] BYREF
  char v50; // [sp+50h] [-70h] BYREF
  char v51; // [sp+60h] [-60h] BYREF
  char v52; // [sp+70h] [-50h] BYREF

  if ( height > 0 )
  {
    srcPadding = this->srcPadding;
    dstPadding = this->dstPadding;
    _R10 = 16;
    _R8 = 144;
    v11 = ((unsigned int)(height - 1) >> 2) + 1;
    _R5 = 32;
    _R9 = vmxi_byte_perm_565_colors;
    _R30 = back_chain;
    _R7 = 160;
    _R11 = v48;
    _R25 = -32;
    __asm { lvx128    v63, r9, r10 }
    _R10 = v45;
    __asm { lvx128    v2, r9, r8 }
    _R8 = v49;
    __asm { lvx128    v61, r9, r5 }
    _R5 = 448;
    __asm { lvx128    v62, r9, r7 }
    _R7 = v47;
    __asm { stvx128   v2, r0, r30 }
    _R30 = 128;
    __asm { lvx128    v52, r9, r25 }
    _R25 = -48;
    __asm { stvx128   v63, r0, r11 }
    _R11 = -16;
    __asm { lvx128    v25, r9, r5 }
    _R5 = -64;
    __asm { stvx128   v62, r0, r10 }
    _R10 = 688;
    __asm { stvx128   v61, r0, r8 }
    _R8 = -80;
    __asm { lvx128    v60, r0, r9 }
    __asm { lvx128    v1, r9, r30 }
    __asm { lvx128    v24, r9, r11 }
    _R30 = 4;
    __asm
    {
      lvx128    v51, r9, r10
      lvx128    v50, r9, r8
      lvx128    v49, r9, r5
      lvx128    v48, r9, r25
      stvx128   v60, r0, r7
    }
    do
    {
      if ( width > 0 )
      {
        __asm { vspltisw128 v60, 0xB }
        __asm { vspltisw128 v59, 1 }
        __asm { vspltisw128 v63, 3 }
        __asm { vspltisw128 v62, 5 }
        __asm { vspltisw128 v58, 7 }
        _R9 = 4 * width;
        __asm { vspltisw128 v57, 9 }
        _R8 = 8 * width;
        __asm { vspltisb  v0, 0 }
        _R7 = 12 * width;
        __asm
        {
          vspltisb  v27, 2
          vspltisb  v26, 1
        }
        _R10 = outBuf;
        __asm { vspltisw128 v55, 6 }
        _R11 = inBuf;
        __asm { vspltisw128 v54, 4 }
        v34 = ((unsigned int)(width - 1) >> 2) + 1;
        __asm { vspltisw128 v53, 0xE }
        while ( 1 )
        {
          __asm { lvx128    v10, r0, r11 }
          _R5 = v48;
          __asm { lvx128    v9, r11, r9 }
          _R25 = v47;
          __asm
          {
            lvx128    v8, r11, r8
            vmaxub    v13, v10, v9
            lvx128    v7, r11, r7
            vminub    v12, v10, v9
            vmaxub    v11, v8, v7
            vperm128  v47, v10, v8, v2
            vminub    v6, v8, v7
            vperm128  v46, v9, v7, v2
            lvx128    v5, r0, r5
          }
          _R5 = &v50;
          __asm
          {
            lvx128    v4, r0, r25
            vperm128  v45, v9, v7, v1
            vmaxub    v13, v13, v11
            vperm128  v44, v10, v8, v1
            vminub    v12, v12, v6
            stvx128   v4, r0, r5
            vpermwi128 v3, v13, 0xB1
            lvx128    v6, r0, r5
            vpermwi128 v2, v12, 0xB1
            vmaxub    v13, v13, v3
            vminub    v12, v12, v2
            vpermwi128 v31, v13, 0x44 # 'D'
            vpermwi128 v30, v12, 0x44 # 'D'
            vmaxub    v29, v13, v31
            vminub    v28, v12, v30
            vmrghb    v13, v0, v29
            vmrghb    v12, v0, v28
            vsubuhs   v23, v13, v12
            vsrh      v11, v23, v25
            vsubuhs   v22, v13, v11
            vadduhs   v21, v12, v11
            vpkuhus128 v61, v22, v22
            vpkuhus128 v56, v21, v21
            vperm128  v13, v88, v61, v5
            vsrb      v20, v13, v24
            vand128   v43, v13, v52
            vand128   v42, v13, v48
            vand128   v41, v13, v49
            vand128   v40, v13, v50
            vor128    v11, v75, v20
            vslw128   v39, v74, v62
            vslw128   v38, v73, v63
            vmrghb    v13, v0, v11
            vspltb    v19, v11, 4
            vor128    v37, v70, v39
            vspltb    v3, v11, 5
            vspltb    v2, v11, 0
            vadduhs   v18, v13, v13
            vpermwi128 v17, v13, 0xB1
            vmr       v4, v19
            vor128    v61, v72, v37
            vadduhs   v12, v17, v18
            vperm128  v36, v93, v61, v6
            vmrghh    v13, v0, v12
            stvewx128 v36, r0, r10
            vmrglh    v12, v0, v12
            vslw128   v5, v13, v63
            vslw128   v31, v13, v62
            vslw128   v30, v13, v58
            vslw128   v29, v13, v57
            vslw128   v28, v12, v63
            vslw128   v23, v12, v62
            vslw128   v22, v12, v58
            vslw128   v21, v12, v57
            vslw128   v20, v13, v59
            vadduws   v19, v31, v5
            vadduws   v18, v29, v30
            vslw128   v17, v12, v59
            vadduws   v14, v20, v13
            vadduws   v16, v23, v28
            vadduws   v15, v21, v22
            vadduws   v13, v18, v19
            vadduws   v12, v17, v12
            vadduws   v6, v15, v16
            vadduws   v5, v13, v14
            vadduws   v31, v6, v12
            vsrw128   v6, v5, v60
            vmrghw128 v13, v76, v45
          }
          _R5 = v45;
          _R25 = v45;
          __asm
          {
            vmrghw128 v12, v79, v46
            vmr128    v35, v1
            vspltb    v30, v11, 6
            vsrw128   v5, v31, v60
            vspltb    v31, v11, 1
            vsububs   v28, v4, v13
          }
          _R11 += 16;
          __asm
          {
            vsububs   v23, v13, v4
            lvx128    v1, r0, r5
            lvx128    v4, r0, r25
            vsububs   v22, v3, v12
            vperm128  v34, v9, v7, v1
            vsububs   v21, v12, v3
            vperm128  v33, v10, v8, v4
            vsububs   v20, v2, v13
            vsububs   v19, v13, v2
            vspltb    v10, v11, 2
            vspltb    v3, v6, 3
            vsububs   v18, v31, v12
            vor       v8, v21, v22
            vspltb    v29, v5, 7
            vmrghw128 v11, v65, v34
            vsububs   v17, v12, v31
            vor       v7, v19, v20
            vspltb    v4, v5, 3
            vor       v9, v23, v28
            vspltb    v28, v6, 7
            vspltb    v2, v6, 0xB
            vsububs   v16, v3, v13
            vsububs   v15, v30, v11
            vmrglb    v20, v0, v8
            vsububs   v31, v11, v30
            vmrghb    v30, v0, v8
            vsububs   v19, v13, v3
            vmrghb    v22, v0, v7
            vmrglb    v8, v0, v7
            vsububs   v3, v12, v29
            vor       v6, v17, v18
          }
          _R25 = &v52;
          __asm
          {
            vsububs   v7, v29, v12
            vspltb    v5, v5, 0xB
            vsububs   v23, v10, v11
          }
          _R5 = &v51;
          __asm
          {
            vsububs   v21, v11, v10
            vmrghb    v14, v0, v9
            vsububs   v29, v4, v13
            vmrghb    v17, v0, v6
            vsububs   v18, v13, v4
            vmrglb    v9, v0, v9
            vsububs   v10, v28, v12
            vmrglb    v6, v0, v6
            vsububs   v4, v12, v28
            vsububs   v12, v2, v11
            vsububs   v13, v11, v5
            vsububs   v28, v5, v11
            vsububs   v2, v11, v2
            stvx128   v12, r0, r25
            vor       v11, v3, v7
            lvx128    v61, r0, r25
            vor       v5, v4, v10
            stvx128   v13, r0, r5
            vor       v13, v18, v29
            vor       v10, v31, v15
            lvx128    v32, r0, r5
            vor       v31, v21, v23
            vmrghb    v29, v0, v11
            vor       v12, v19, v16
            vmrglb    v11, v0, v11
            vmrghb    v23, v0, v13
            vadduhs   v21, v14, v30
            vadduhs   v18, v22, v17
            vmrghb    v17, v0, v5
            vmrghb    v16, v0, v10
            vor128    v4, v64, v28
            vmrghb    v19, v0, v12
            vor128    v3, v2, v61
            vmrghb    v15, v0, v31
            vadduhs   v14, v23, v29
            vmrglb    v29, v0, v13
            vadduhs   v7, v19, v17
            vmrglb    v28, v0, v5
            vadduhs   v22, v9, v20
            vmrglb    v23, v0, v12
            vadduhs   v2, v21, v16
            vadduhs   v30, v18, v15
            vmrglb    v20, v0, v10
            vadduhs   v19, v29, v11
            vmrghb    v18, v0, v4
            vadduhs   v21, v8, v6
            vmrghb    v16, v0, v3
            vadduhs   v17, v23, v28
            vmrglb    v15, v0, v31
            vmrglb    v11, v0, v4
            vadduhs   v9, v22, v20
            vmrglb    v10, v0, v3
            vadduhs   v13, v14, v18
            vadduhs   v12, v7, v16
          }
          _R5 = v49;
          __asm
          {
            vadduhs   v8, v21, v15
            vadduhs   v11, v19, v11
            vadduhs   v10, v17, v10
            vcmpgtuh  v6, v2, v12
            vcmpgtuh  v5, v30, v12
            lvx128    v7, r0, r5
            vcmpgtuh  v4, v9, v11
            vcmpgtuh  v3, v9, v10
            vcmpgtuh  v31, v8, v10
            vcmpgtuh  v29, v2, v13
            vcmpgtuh  v28, v8, v11
            vcmpgtuh  v23, v30, v13
            vpkuhus128 v56, v6, v3
            vpkuhus128 v47, v5, v31
            vcmpgtuh  v22, v11, v10
            vpkuhus128 v46, v29, v4
            vcmpgtuh  v21, v13, v12
            vor128    v1, v67, v35
            vpkuhus128 v45, v23, v28
            vand128   v44, v88, v47
            vpkuhus128 v43, v21, v22
            vand128   v42, v77, v46
            vand128   v41, v88, v43
            vor128    v40, v74, v44
            vand128   v39, v73, v26
            vand128   v38, v72, v27
            vor128    v37, v71, v38
            vsrw128   v36, v69, v51
            vslw128   v34, v69, v55
            vsrw128   v33, v69, v54
            vsrw128   v32, v69, v53
            vor128    v61, v65, v34
            vor128    v56, v68, v32
            vor128    v61, v88, v61
            vperm128  v47, v93, v61, v7
            stvewx128 v47, r10, r30
          }
          _R10 += 8;
          if ( --v34 == 0 )
            break;
          _R5 = back_chain;
          __asm { lvx128    v2, r0, r5 }
        }
        _R11 = back_chain;
        __asm { lvx128    v2, r0, r11 }
      }
      --v11;
      inBuf += 16 * width + srcPadding;
      outBuf += 2 * width + dstPadding;
    }
    while ( v11 != 0 );
  }
}


// ========================================================================
// ?CompressImageDXT1AlphaFast_Xenon@idDxtEncoder@@QAAXPIBEPIAEHH@Z
// EA  : 0x82926B68
// RVA : 0x00926B68
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder_xenon.cpp
// ========================================================================

void __fastcall idDxtEncoder::CompressImageDXT1AlphaFast_Xenon(
        idDxtEncoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height)
{
  unsigned int v12; // r22
  int *p_srcPadding; // r21
  int *p_dstPadding; // r20
  int v18; // r19
  int v19; // r18
  unsigned __int8 v38; // cr56
  unsigned __int8 v39; // cr57
  unsigned __int8 *v54; // r10
  unsigned __int8 *v68; // [sp+54h] [-16Ch]
  __int64 v69; // [sp+58h] [-168h]
  _BYTE v70[16]; // [sp+60h] [-160h] BYREF
  __int64 v71; // [sp+70h] [-150h]
  _BYTE v72[16]; // [sp+80h] [-140h] BYREF
  _BYTE v73[16]; // [sp+90h] [-130h] BYREF
  _BYTE v74[16]; // [sp+A0h] [-120h] BYREF
  _BYTE v75[16]; // [sp+B0h] [-110h] BYREF
  __vector4 v76; // [sp+C0h] [-100h] BYREF
  __vector4 v77; // [sp+D0h] [-F0h] BYREF
  __vector4 v78; // [sp+E0h] [-E0h] BYREF
  __vector4 v79; // [sp+F0h] [-D0h] BYREF
  __vector4 v80; // [sp+100h] [-C0h] BYREF
  __vector4 v81[11]; // [sp+110h] [-B0h] BYREF

  *(_DWORD *)&_R30[4] = width;
  if ( height > 0 )
  {
    _R10 = 16;
    _R9 = 144;
    v12 = ((unsigned int)(height - 1) >> 2) + 1;
    _R8 = 160;
    _R31 = vmxi_byte_perm_565_colors;
    _R7 = 32;
    p_srcPadding = &this->srcPadding;
    p_dstPadding = &this->dstPadding;
    v18 = 16 * width;
    __asm { lvx128    v63, r31, r10 }
    v19 = 2 * width;
    __asm { lvx128    v62, r31, r9 }
    _R6 = v74;
    __asm { lvx128    v61, r31, r8 }
    _R5 = v70;
    __asm { lvx128    v60, r31, r7 }
    _R4 = v72;
    _R3 = v73;
    __asm { lvx128    v59, r0, r31 }
    _R11 = v75;
    _R10 = -112;
    __asm { stvx128   v63, r0, r6 }
    _R9 = 448;
    __asm { stvx128   v62, r0, r5 }
    _R8 = -16;
    __asm { stvx128   v61, r0, r4 }
    _R7 = 128;
    __asm { stvx128   v60, r0, r3 }
    _R16 = 4;
    __asm
    {
      stvx128   v59, r0, r11
      lvx128    v23, r31, r10
      lvx128    v22, r31, r9
      lvx128    v24, r31, r8
      lvx128    v1, r31, r7
    }
    do
    {
      if ( *(int *)&_R30[4] > 0 )
      {
        _R25 = 4 * *(_DWORD *)&_R30[4];
        _R24 = 8 * *(_DWORD *)&_R30[4];
        _R23 = 12 * *(_DWORD *)&_R30[4];
        _R10 = outBuf;
        *(_DWORD *)&_R30[8] = inBuf;
        *(_DWORD *)_R30 = ((unsigned int)(*(_DWORD *)&_R30[4] - 1) >> 2) + 1;
        do
        {
          __asm { lvx128    v10, r0, r30 }
          _R11 = v81;
          __asm { lvx128    v9, r30, r25 }
          _R9 = &v79;
          __asm
          {
            lvx128    v8, r30, r24
            vminub    v0, v10, v9
            lvx128    v7, r30, r23
            vmaxub    v13, v10, v9
            vminub    v12, v8, v7
          }
          _R8 = &v77;
          __asm { vmaxub    v11, v8, v7 }
          _R7 = &v80;
          __asm
          {
            stvx128   v10, r0, r11
            stvx128   v9, r0, r9
            vminub    v0, v0, v12
            vmaxub    v13, v13, v11
            stvx128   v8, r0, r8
            stvx128   v7, r0, r7
            vpermwi128 v6, v0, 0xB1
            vpermwi128 v5, v13, 0xB1
            vminub    v0, v0, v6
            vmaxub    v13, v13, v5
            vpermwi128 v4, v0, 0x44 # 'D'
            vminub    v12, v0, v4
            vspltb    v3, v12, 3
            vcmpgtub. v23, v3, v23
          }
          __asm { vpermwi128 v31, v13, 0x44 # 'D' }
          _R5 = &v78;
          __asm { vspltisb  v0, 0 }
          _R4 = &v76;
          __asm { vmaxub    v30, v13, v31 }
          __asm
          {
            vmrghb    v12, v0, v12
            vmrghb    v13, v0, v30
            vsubuhs   v29, v13, v12
            vsrh      v11, v29, v22
            vsubuhs   v28, v13, v11
            vadduhs   v27, v12, v11
            vpkuhus128 v63, v28, v28
            vpkuhus128 v62, v27, v27
            stvx128   v63, r0, r5
            stvx128   v62, r0, r4
          }
          if ( (((v38 << 7) | (v39 << 6)) & 0x80) != 0 )
          {
            _R11 = v74;
            __asm { vspltisw128 v58, 5 }
            _R9 = -48;
            __asm { vspltisw128 v57, 3 }
            _R8 = -64;
            __asm { vspltisw128 v56, 7 }
            _R7 = -80;
            __asm { vspltisw128 v55, 9 }
            _R6 = -32;
            __asm
            {
              vspltisw128 v54, 1
              lvx128    v6, r0, r11
            }
            _R5 = v75;
            __asm { lvx128    v53, r31, r9 }
            _R3 = v70;
            __asm
            {
              vperm128  v13, v94, v63, v6
              lvx128    v52, r31, r8
              lvx128    v51, r31, r7
            }
            _R4 = v70;
            __asm
            {
              lvx128    v49, r31, r6
              vspltisw128 v50, 0xB
              lvx128    v4, r0, r5
              vperm128  v48, v9, v7, v1
              vand128   v47, v13, v53
              vperm128  v46, v10, v8, v1
              vand128   v45, v13, v52
              vand128   v44, v13, v51
              vsrb      v3, v13, v24
              vslw128   v43, v79, v58
              vslw128   v42, v77, v57
              vand128   v41, v13, v49
              vmr128    v38, v1
              vor128    v40, v74, v43
              vor128    v13, v73, v3
              vor128    v63, v76, v40
              vspltb    v2, v13, 6
              vmrghb    v12, v0, v13
              vspltb    v6, v13, 4
              vperm128  v39, v95, v63, v4
              vmr128    v37, v2
              vspltb    v5, v13, 0
              vadduhs   v31, v12, v12
              vpermwi128 v30, v12, 0xB1
              vspltb    v4, v13, 5
              vspltb    v3, v13, 1
              vadduhs   v12, v30, v31
              vspltb    v31, v13, 2
              stvewx128 v39, r0, r10
              lvx128    v2, r0, r3
              lvx128    v1, r0, r4
              vperm128  v35, v10, v8, v1
              vmrghh    v13, v0, v12
              vmrglh    v12, v0, v12
              vperm128  v36, v9, v7, v2
              vslw128   v29, v13, v57
              vslw128   v28, v13, v58
              vslw128   v27, v13, v56
              vslw128   v26, v13, v55
              vslw128   v25, v12, v57
              vslw128   v21, v12, v58
              vslw128   v20, v12, v56
              vslw128   v19, v12, v55
              vadduws   v15, v26, v27
              vadduws   v16, v28, v29
              vslw128   v18, v13, v54
              vslw128   v17, v12, v54
              vadduws   v14, v21, v25
              vadduws   v11, v19, v20
              vadduws   v30, v18, v13
              vmrghw128 v13, v78, v48
              vadduws   v29, v17, v12
              vadduws   v28, v15, v16
              vadduws   v27, v11, v14
              vadduws   v26, v28, v30
              vadduws   v25, v27, v29
              vsrw128   v12, v26, v50
              vsrw128   v11, v25, v50
              vspltb    v30, v12, 3
              vspltb    v29, v12, 7
              vspltb    v28, v11, 3
              vspltb    v27, v11, 7
              vspltb    v26, v11, 0xB
            }
            _R11 = v72;
            __asm { vspltb    v25, v12, 0xB }
            _R9 = v72;
            __asm
            {
              vmrghw128 v12, v67, v36
              vsububs   v19, v6, v13
              vsububs   v18, v13, v6
              vsububs   v21, v5, v13
              lvx128    v6, r0, r11
              vsububs   v17, v4, v12
              lvx128    v2, r0, r9
              vsububs   v16, v12, v4
              vperm128  v34, v9, v7, v6
              vsububs   v20, v13, v5
              vperm128  v33, v10, v8, v2
              vsububs   v7, v12, v3
              vsububs   v8, v3, v12
              vsububs   v5, v28, v13
              vsububs   v15, v30, v13
              vsububs   v14, v13, v30
              vmrghw128 v11, v65, v34
              vsububs   v6, v27, v12
              vsububs   v4, v12, v27
              vsububs   v28, v13, v28
              vsububs   v3, v29, v12
              vsububs   v30, v12, v29
              vor       v9, v16, v17
              vor       v8, v7, v8
              vor128    v2, v69, v37
              vor       v10, v28, v5
              vor       v7, v4, v6
              vor       v5, v30, v3
              vmrglb    v30, v0, v9
              vor       v6, v14, v15
              vmrghb    v15, v0, v9
              vor       v13, v18, v19
              vmrghb    v4, v0, v8
              vor       v12, v20, v21
              vmrglb    v9, v0, v8
              vsububs   v16, v31, v11
              vmrghb    v19, v0, v10
              vsububs   v14, v11, v31
              vmrglb    v17, v0, v10
              vsububs   v20, v2, v11
              vmrghb    v29, v0, v13
              vsububs   v18, v11, v2
              vmrglb    v28, v0, v13
              vsububs   v3, v25, v11
              vmrghb    v27, v0, v12
              vsububs   v31, v11, v25
              vmrglb    v21, v0, v12
              vsububs   v25, v26, v11
              vmrghb    v2, v0, v7
              vsububs   v8, v11, v26
              vmrghb    v26, v0, v6
              vor       v13, v18, v20
              vmrghb    v20, v0, v5
              vor       v12, v14, v16
              vmrglb    v18, v0, v7
              vor       v10, v31, v3
              vmrglb    v16, v0, v5
              vor       v11, v8, v25
              vmrglb    v14, v0, v6
              vmrghb    v8, v0, v13
              vadduhs   v7, v29, v15
              vadduhs   v5, v27, v4
              vmrghb    v6, v0, v12
              vmrglb    v4, v0, v13
              vadduhs   v3, v19, v2
              vadduhs   v31, v26, v20
              vmrghb    v29, v0, v11
              vadduhs   v28, v28, v30
              vmrghb    v27, v0, v10
              vadduhs   v26, v21, v9
              vmrglb    v2, v0, v12
              vadduhs   v9, v7, v8
              vmrglb    v25, v0, v11
              vadduhs   v8, v5, v6
              vmrglb    v21, v0, v10
              vadduhs   v13, v3, v29
              vadduhs   v12, v31, v27
              vadduhs   v7, v28, v4
              vadduhs   v20, v17, v18
              vspltisb  v18, 2
              vadduhs   v19, v14, v16
              vspltisb  v17, 1
              vadduhs   v4, v26, v2
            }
            _R8 = 688;
            __asm
            {
              vcmpgtuh  v16, v9, v12
              vspltisw128 v63, 4
              vadduhs   v0, v20, v25
              vspltisw128 v32, 6
              vadduhs   v11, v19, v21
              vspltisw128 v62, 0xE
              vcmpgtuh  v14, v9, v13
            }
            _R7 = v73;
            __asm
            {
              vcmpgtuh  v15, v8, v12
              lvx128    v61, r31, r8
              vcmpgtuh  v10, v8, v13
              vcmpgtuh  v9, v7, v0
              vcmpgtuh  v8, v4, v0
              vcmpgtuh  v6, v4, v11
              lvx128    v3, r0, r7
              vcmpgtuh  v7, v7, v11
              vcmpgtuh  v5, v13, v12
              vpkuhus128 v60, v14, v9
              vpkuhus128 v59, v10, v8
              vcmpgtuh  v4, v0, v11
              vpkuhus128 v57, v15, v6
              vor128    v1, v70, v38
              vpkuhus128 v58, v16, v7
              vand128   v56, v91, v60
              vpkuhus128 v55, v5, v4
              vand128   v54, v90, v57
              vand128   v53, v90, v55
              vor128    v52, v88, v54
              vand128   v51, v85, v17
              vand128   v50, v84, v18
              vor128    v49, v83, v50
              vsrw128   v46, v81, v63
              vsrw128   v48, v81, v61
              vslw128   v47, v81, v32
              vsrw128   v45, v81, v62
              vor128    v44, v78, v47
              vor128    v43, v80, v45
              vor128    v63, v75, v44
              vperm128  v42, v95, v63, v3
              stvewx128 v42, r10, r16
            }
          }
          else
          {
            idDxtEncoder::EmitColorAlphaIndices_Xenon(
              this,
              block0: v81,
              block1: &v79,
              block2: &v77,
              block3: &v80,
              minColor: &v76,
              maxColor: &v78,
              outPtr: _R10);
            v68 = v54;
            v71 = *(_QWORD *)&_R30[4];
            _R10 = 448;
            v69 = *(_QWORD *)_R30;
            _R30 = -16;
            _R29 = 128;
            __asm { lvx128    v37, r0, r31 }
            _R11 = 16;
            _R9 = 144;
            _R8 = 160;
            __asm { lvx128    v22, r31, r10 }
            _R7 = 32;
            __asm { lvx128    v24, r31, r30 }
            _R6 = v74;
            __asm { lvx128    v1, r31, r29 }
            _R5 = v70;
            __asm { lvx128    v41, r31, r11 }
            _R4 = v72;
            __asm { lvx128    v40, r31, r9 }
            _R3 = v73;
            __asm { lvx128    v39, r31, r8 }
            _R15 = v75;
            __asm { lvx128    v38, r31, r7 }
            _R14 = -112;
            _R10 = v68;
            *(_DWORD *)&_R30[8] = v71;
            __asm { stvx128   v41, r0, r6 }
            *(_QWORD *)_R30 = v69;
            __asm
            {
              stvx128   v40, r0, r5
              stvx128   v39, r0, r4
              stvx128   v38, r0, r3
              lvx128    v23, r31, r14
              stvx128   v37, r0, r15
            }
          }
          --*(_DWORD *)_R30;
          *(_DWORD *)&_R30[8] += 16;
          _R10 += 8;
        }
        while ( *(_DWORD *)_R30 != 0 );
      }
      --v12;
      inBuf += v18 + *p_srcPadding;
      outBuf += v19 + *p_dstPadding;
    }
    while ( v12 != 0 );
  }
}


// ========================================================================
// ?CompressImageDXT5Fast_Xenon@idDxtEncoder@@QAAXPIBEPIAEHH@Z
// EA  : 0x82927128
// RVA : 0x00927128
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder_xenon.cpp
// ========================================================================

void __fastcall idDxtEncoder::CompressImageDXT5Fast_Xenon(
        idDxtEncoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height)
{
  int *p_srcPadding; // r18
  int *p_dstPadding; // r17
  unsigned int v12; // r21
  int v13; // r16
  unsigned int v24; // r28
  __vector4 v51; // [sp+60h] [-1D0h] BYREF
  __vector4 v52; // [sp+70h] [-1C0h] BYREF
  _BYTE v53[16]; // [sp+80h] [-1B0h] BYREF
  __vector4 v54; // [sp+90h] [-1A0h] BYREF
  __vector4 v55; // [sp+A0h] [-190h] BYREF
  __vector4 v56; // [sp+B0h] [-180h] BYREF
  _BYTE v57[16]; // [sp+C0h] [-170h] BYREF
  __vector4 v58; // [sp+D0h] [-160h] BYREF
  _BYTE v59[192]; // [sp+E0h] [-150h] BYREF

  if ( height > 0 )
  {
    p_srcPadding = &this->srcPadding;
    p_dstPadding = &this->dstPadding;
    v12 = ((unsigned int)(height - 1) >> 2) + 1;
    v13 = 16 * width;
    _R24 = 4 * width;
    _R19 = 4;
    _R31 = vmxi_byte_perm_565_colors;
    do
    {
      if ( width > 0 )
      {
        __asm { vspltisb  v10, 0 }
        __asm { vspltisb  v0, 2 }
        _R10 = v53;
        __asm { vspltisb  v13, 1 }
        _R9 = v59;
        _R8 = v57;
        __asm { vspltisw128 v125, 0xB }
        __asm { vspltisw128 v124, 1 }
        __asm { vspltisw128 v127, 3 }
        __asm { vspltisw128 v126, 5 }
        _R27 = 8 * width;
        __asm { vspltisw128 v123, 7 }
        _R26 = 12 * width;
        __asm
        {
          vspltisw128 v122, 9
          stvx128   v10, r0, r10
        }
        _R30 = inBuf;
        __asm { stvx128   v0, r0, r9 }
        _R29 = outBuf + 8;
        __asm { stvx128   v13, r0, r8 }
        v24 = ((unsigned int)(width - 1) >> 2) + 1;
        __asm
        {
          vspltisw128 v119, 6
          vspltisw128 v118, 4
          vspltisw128 v117, 0xE
        }
        while ( 1 )
        {
          __asm { lvx128    v11, r0, r30 }
          _R11 = &v54;
          __asm { lvx128    v12, r30, r24 }
          _R10 = &v52;
          __asm
          {
            lvx128    v13, r30, r27
            vmaxub    v9, v11, v12
            lvx128    v0, r30, r26
            vminub    v8, v11, v12
            vmaxub    v7, v13, v0
          }
          _R9 = 448;
          __asm
          {
            vminub    v6, v13, v0
            stvx128   v13, r0, r11
            stvx128   v0, r0, r10
          }
          _R8 = &v51;
          _R7 = &v55;
          __asm { vmaxub    v0, v9, v7 }
          _R11 = &v56;
          __asm
          {
            vminub    v13, v8, v6
            lvx128    v9, r31, r9
          }
          _R15 = &v58;
          __asm { stvx128   v12, r0, r8 }
          __asm
          {
            vpermwi128 v5, v0, 0xB1
            stvx128   v11, r0, r7
            vpermwi128 v4, v13, 0xB1
          }
          __asm { vmaxub    v0, v0, v5 }
          __asm { vminub    v13, v13, v4 }
          __asm
          {
            vpermwi128 v3, v0, 0x44 # 'D'
            vpermwi128 v2, v13, 0x44 # 'D'
            vmaxub    v1, v0, v3
            vminub    v31, v13, v2
            vmrghb    v0, v10, v1
            vmrghb    v13, v10, v31
            vsubuhs   v30, v0, v13
            vsrh      v12, v30, v9
            vsubuhs   v29, v0, v12
            vadduhs   v28, v13, v12
            vpkuhus128 v121, v29, v29
            vpkuhus128 v120, v28, v28
            stvx128   v121, r0, r11
            stvx128   v120, r0, r15
          }
          idDxtEncoder::EmitAlphaIndices_Xenon(
            this,
            block0: &v55,
            block1: &v51,
            block2: &v54,
            block3: &v52,
            minColor: &v58,
            maxColor: &v56,
            outPtr: _R29 - 8);
          _R10 = 16;
          _R9 = -48;
          __asm { lvx128    v7, r0, r31 }
          _R8 = -64;
          _R5 = -80;
          _R7 = -16;
          __asm { lvx128    v0, r31, r10 }
          _R6 = -32;
          __asm { lvx128    v62, r31, r9 }
          _R4 = v53;
          __asm
          {
            vperm128  v0, v120, v121, v0
            lvx128    v61, r31, r8
            lvx128    v60, r31, r5
          }
          _R3 = &v55;
          __asm
          {
            lvx128    v13, r31, r7
            lvx128    v63, r31, r6
            vand128   v62, v0, v62
            vand128   v61, v0, v61
            vand128   v56, v0, v60
            vand128   v59, v0, v63
            vslw128   v58, v94, v126
            vslw128   v57, v93, v127
            vsrb      v27, v0, v13
            lvx128    v0, r0, r4
            vor128    v55, v89, v58
            vor128    v13, v91, v27
            vor128    v63, v88, v55
            vmrghb    v12, v0, v13
            vperm128  v54, v95, v63, v7
            vadduhs   v26, v12, v12
            vpermwi128 v25, v12, 0xB1
            stvewx128 v54, r0, r29
            vadduhs   v12, v25, v26
          }
          _R11 = &v54;
          _R8 = &v51;
          __asm { lvx128    v60, r0, r3 }
          _R7 = &v52;
          __asm { vspltb    v9, v13, 5 }
          _R10 = 160;
          __asm
          {
            vspltb    v8, v13, 6
            vmrghh    v11, v0, v12
          }
          _R9 = 128;
          __asm { vmrglh    v10, v0, v12 }
          _R6 = 144;
          __asm
          {
            lvx128    v62, r0, r11
            vspltb    v5, v13, 4
            lvx128    v61, r0, r8
            vspltb    v4, v13, 0
            vslw128   v20, v11, v127
            lvx128    v6, r31, r10
            vslw128   v24, v10, v127
            lvx128    v3, r31, r9
            vslw128   v23, v10, v126
            lvx128    v63, r0, r7
            vslw128   v22, v10, v123
            lvx128    v7, r31, r6
            vslw128   v21, v10, v122
            vperm128  v51, v93, v63, v6
            vslw128   v19, v11, v126
            vperm128  v53, v93, v63, v7
            vslw128   v18, v11, v123
            vperm128  v52, v92, v62, v7
            vslw128   v17, v11, v122
            vperm128  v50, v92, v62, v6
            vperm128  v49, v93, v63, v3
            vslw128   v16, v10, v124
            vperm128  v48, v92, v62, v3
            vadduws   v14, v19, v20
            vadduws   v6, v23, v24
            vspltb    v2, v13, 1
            vadduws   v7, v17, v18
            vspltb    v1, v13, 2
            vadduws   v3, v21, v22
            vmrghw128 v13, v84, v53
            vslw128   v15, v11, v124
            vmrghw128 v12, v82, v51
            vadduws   v31, v16, v10
          }
          _R5 = 688;
          __asm
          {
            vadduws   v29, v7, v14
            vadduws   v28, v3, v6
            vadduws   v30, v15, v11
            vmrghw128 v11, v80, v49
            vsububs   v27, v9, v13
            vsububs   v26, v13, v9
            vadduws   v24, v28, v31
            vadduws   v25, v29, v30
            vsububs   v23, v8, v12
            vsububs   v22, v12, v8
            vsrw128   v9, v24, v125
            vsrw128   v10, v25, v125
            vsububs   v21, v5, v11
            vsububs   v20, v11, v5
            vsububs   v19, v4, v11
            vspltb    v6, v9, 3
            vsububs   v18, v11, v4
            vspltb    v8, v10, 3
            vor       v4, v26, v27
            vspltb    v5, v9, 7
            vspltb    v7, v10, 7
            vsububs   v17, v2, v13
            vspltb    v10, v10, 0xB
            vsububs   v15, v6, v11
            vsububs   v16, v8, v11
            vspltb    v9, v9, 0xB
            vsububs   v14, v11, v6
            vmrghb    v3, v0, v4
            vsububs   v31, v11, v8
            vmrglb    v30, v0, v4
            vsububs   v29, v13, v2
            vsububs   v28, v5, v13
            vsububs   v27, v13, v5
            vsububs   v26, v7, v13
            vsububs   v25, v13, v7
            vor       v13, v20, v21
          }
          _R4 = 32;
          __asm
          {
            vor       v4, v25, v26
            lvx128    v63, r31, r5
            vor       v11, v18, v19
          }
          _R3 = v57;
          __asm { vor       v8, v14, v15 }
          _R11 = v59;
          __asm
          {
            vor       v5, v27, v28
            vmrghb    v19, v0, v13
            vor       v7, v31, v16
            vmrghb    v14, v0, v4
            vor       v6, v29, v17
            vmrglb    v2, v0, v13
            vsububs   v24, v9, v12
            vmrghb    v29, v0, v8
            vsububs   v21, v12, v9
            vmrghb    v9, v0, v11
            vsububs   v20, v10, v12
            vmrglb    v17, v0, v7
            vsububs   v18, v12, v10
            vmrghb    v15, v0, v5
            vsububs   v28, v1, v12
            vmrglb    v31, v0, v11
            vsububs   v26, v12, v1
            vmrglb    v25, v0, v8
            vmrglb    v4, v0, v4
            vor       v11, v21, v24
            vmrghb    v27, v0, v7
            vor       v13, v22, v23
            vmrghb    v16, v0, v6
            vor       v10, v18, v20
            vmrglb    v8, v0, v6
            vor       v12, v26, v28
            vmrglb    v6, v0, v5
            vadduhs   v7, v19, v3
            vadduhs   v3, v29, v15
            vmrghb    v1, v0, v13
            vadduhs   v20, v17, v4
            vmrghb    v26, v0, v10
            vadduhs   v29, v27, v14
            vmrghb    v17, v0, v11
            vmrglb    v18, v0, v10
            vadduhs   v5, v9, v16
            vmrghb    v28, v0, v12
            vadduhs   v27, v2, v30
            vmrglb    v23, v0, v13
            vadduhs   v24, v31, v8
            vmrglb    v21, v0, v12
            vadduhs   v22, v25, v6
            vmrglb    v19, v0, v11
            vadduhs   v10, v7, v1
            vadduhs   v0, v3, v17
          }
          --v24;
          __asm { vadduhs   v13, v29, v26 }
          _R30 += 16;
          __asm
          {
            vadduhs   v11, v20, v18
            vadduhs   v12, v22, v19
            vadduhs   v9, v5, v28
            vadduhs   v8, v27, v23
            vadduhs   v7, v24, v21
            vcmpgtuh  v14, v10, v0
            vcmpgtuh  v16, v10, v13
            vcmpgtuh  v10, v9, v0
            vcmpgtuh  v15, v8, v11
            vcmpgtuh  v6, v7, v11
            vcmpgtuh  v5, v9, v13
            vcmpgtuh  v4, v8, v12
            vcmpgtuh  v3, v7, v12
            vpkuhus128 v47, v16, v15
            vcmpgtuh  v2, v0, v13
            lvx128    v0, r31, r4
            vpkuhus128 v46, v5, v6
            vcmpgtuh  v1, v12, v11
            vpkuhus128 v45, v14, v4
            vpkuhus128 v44, v10, v3
            vand128   v43, v79, v46
            vpkuhus128 v42, v2, v1
            vand128   v41, v76, v45
            vand128   v40, v79, v42
            vor128    v39, v73, v43
            lvx128    v38, r0, r3
            lvx128    v37, r0, r11
            vand128   v36, v72, v38
            vand128   v35, v71, v37
            vor128    v34, v68, v35
            vsrw128   v33, v66, v63
            vsrw128   v63, v66, v118
            vslw128   v32, v66, v119
            vsrw128   v62, v66, v117
            vor128    v61, v95, v32
            vor128    v60, v65, v62
            vor128    v63, v92, v61
            vperm128  v59, v95, v63, v0
            stvewx128 v59, r29, r19
          }
          _R29 += 16;
          if ( v24 == 0 )
            break;
          _R11 = v53;
          __asm { lvx128    v10, r0, r11 }
        }
      }
      --v12;
      inBuf += v13 + *p_srcPadding;
      outBuf += _R24 + *p_dstPadding;
    }
    while ( v12 != 0 );
  }
}


// ========================================================================
// ?CompressYCoCgDXT5Fast_Xenon@idDxtEncoder@@QAAXPIBEPIAEHH@Z
// EA  : 0x82927638
// RVA : 0x00927638
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder_xenon.cpp
// ========================================================================

void __fastcall idDxtEncoder::CompressYCoCgDXT5Fast_Xenon(
        idDxtEncoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height)
{
  int *p_srcPadding; // r18
  int *p_dstPadding; // r17
  unsigned int v12; // r21
  int v13; // r16
  unsigned int v24; // r28
  __vector4 v67; // [sp+60h] [-1D0h] BYREF
  __vector4 v68; // [sp+70h] [-1C0h] BYREF
  _BYTE v69[16]; // [sp+80h] [-1B0h] BYREF
  __vector4 v70; // [sp+90h] [-1A0h] BYREF
  __vector4 v71; // [sp+A0h] [-190h] BYREF
  _BYTE v72[16]; // [sp+B0h] [-180h] BYREF
  __vector4 v73; // [sp+C0h] [-170h] BYREF
  __vector4 v74; // [sp+D0h] [-160h] BYREF
  _BYTE v75[192]; // [sp+E0h] [-150h] BYREF

  if ( height > 0 )
  {
    p_srcPadding = &this->srcPadding;
    p_dstPadding = &this->dstPadding;
    v12 = ((unsigned int)(height - 1) >> 2) + 1;
    v13 = 16 * width;
    _R24 = 4 * width;
    _R19 = 4;
    _R31 = vmxi_byte_perm_565_colors;
    do
    {
      if ( width > 0 )
      {
        __asm { vspltisb  v12, 0 }
        __asm { vspltisb  v0, 2 }
        _R10 = v72;
        __asm { vspltisb  v7, 1 }
        _R9 = v75;
        _R8 = v69;
        __asm { vspltisw128 v124, 0xB }
        __asm { vspltisw128 v123, 1 }
        __asm { vspltisw128 v127, 3 }
        __asm { vspltisw128 v126, 5 }
        _R27 = 8 * width;
        __asm { vspltisw128 v122, 7 }
        _R26 = 12 * width;
        __asm { vspltisw128 v121, 9 }
        _R30 = inBuf;
        __asm { stvx128   v12, r0, r10 }
        _R29 = outBuf + 8;
        __asm { stvx128   v0, r0, r9 }
        v24 = ((unsigned int)(width - 1) >> 2) + 1;
        __asm
        {
          stvx128   v7, r0, r8
          vspltisw128 v119, 6
          vspltisw128 v118, 4
          vspltisw128 v117, 0xE
        }
        while ( 1 )
        {
          _R11 = 112;
          __asm
          {
            lvx128    v11, r0, r30
            lvx128    v10, r24, r30
          }
          _R10 = 432;
          __asm
          {
            lvx128    v9, r27, r30
            vmaxub    v6, v11, v10
            lvx128    v8, r26, r30
            vminub    v5, v11, v10
            vmaxub    v4, v9, v8
          }
          _R9 = 400;
          __asm
          {
            vminub    v3, v9, v8
            lvx128    v0, r31, r11
            vaddubm   v2, v11, v0
            lvx128    v13, r31, r10
            vaddubm   v1, v10, v0
          }
          _R8 = 416;
          __asm { vmaxub    v11, v6, v4 }
          _R7 = 256;
          __asm
          {
            vminub    v10, v5, v3
            lvx128    v6, r31, r9
            vaddubm   v31, v9, v0
          }
          _R6 = 272;
          __asm { vaddubm   v30, v8, v0 }
          _R5 = &v67;
          __asm
          {
            vpermwi128 v29, v11, 0xB1
            lvx128    v5, r31, r8
            vpermwi128 v28, v10, 0xB1
            lvx128    v62, r31, r7
          }
          _R4 = &v71;
          __asm { lvx128    v63, r31, r6 }
          _R3 = 288;
          __asm { vmaxub    v11, v11, v29 }
          _R11 = 320;
          __asm { vminub    v10, v10, v28 }
          _R10 = 304;
          __asm
          {
            vpermwi128 v27, v11, 0x44 # 'D'
            vpermwi128 v26, v10, 0x44 # 'D'
            vmaxub    v11, v11, v27
            vminub    v10, v10, v26
            vmrghb    v9, v12, v11
            vaddubm   v25, v11, v0
            vmrghb    v11, v12, v10
            vaddubm   v24, v10, v0
            vsubshs   v23, v9, v13
            vsubshs   v22, v11, v13
            vsubshs   v21, v13, v11
            vsubshs   v20, v13, v9
            vmaxsh    v19, v21, v22
            vmaxsh    v18, v20, v23
            vmaxsh    v13, v19, v18
            vsplth    v17, v13, 1
            vmaxsh    v16, v13, v17
            vsplth    v13, v16, 0
            vcmpgtuh  v15, v13, v5
            vcmpgtuh  v14, v13, v6
            vandc     v11, v7, v15
            vandc     v13, v7, v14
            vaddubs   v11, v11, v13
            vaddubs   v10, v11, v13
            vand128   v13, v11, v62
            vspltisb  v11, 3
            vand128   v9, v10, v63
            vslb      v8, v24, v13
            vslb      v6, v25, v13
            vslb      v5, v2, v13
            vslb      v4, v1, v13
            vsububm   v3, v8, v0
            vslb      v1, v9, v11
            vsububm   v2, v6, v0
            vslb      v31, v31, v13
            vandc128  v62, v3, v63
            vsububm   v5, v5, v0
            vandc128  v61, v2, v63
            vsububm   v8, v4, v0
            vor128    v29, v94, v1
            vslb      v30, v30, v13
            stvx128   v5, r0, r5
            vor128    v28, v93, v1
            stvx128   v8, r0, r4
            vsububm   v10, v31, v0
            vmrghb    v13, v12, v29
            vmrghb    v12, v12, v28
            lvx128    v4, r31, r3
            vsububm   v11, v30, v0
            lvx128    v0, r31, r11
            lvx128    v62, r31, r10
            vslh      v27, v13, v0
          }
          _R9 = 48;
          __asm { vsubshs   v26, v12, v13 }
          _R8 = 224;
          __asm { vslh      v25, v12, v0 }
          _R7 = &v68;
          _R6 = 240;
          _R5 = &v70;
          __asm
          {
            vsubshs   v24, v26, v4
            lvx128    v6, r31, r9
            lvx128    v63, r31, r8
          }
          _R4 = -128;
          __asm
          {
            vperm128  v60, v5, v10, v6
            stvx128   v10, r0, r7
            lvx128    v9, r31, r6
            vperm128  v59, v8, v11, v6
            vand128   v13, v24, v62
            stvx128   v11, r0, r5
          }
          _R11 = -144;
          __asm { lvx128    v61, r31, r4 }
          _R15 = -160;
          __asm { vmrghw128 v12, v91, v60 }
          _R7 = -96;
          __asm
          {
            vaddshs   v23, v27, v13
            vmrglw128 v11, v91, v60
            vsubshs   v22, v25, v13
          }
          __asm
          {
            vsrah     v21, v23, v0
            lvx128    v62, r31, r7
            vsrah     v20, v22, v0
          }
          __asm { vpkshus128 v58, v21, v21 }
          __asm { vpkshus128 v57, v20, v20 }
          __asm
          {
            vand128   v0, v90, v63
            vand128   v10, v89, v63
            lvx128    v63, r31, r11
          }
          _R11 = &v73;
          __asm
          {
            vsrb      v19, v0, v9
            vsrb      v18, v10, v9
            vor       v13, v0, v19
            vor       v0, v10, v18
            vspltb    v9, v13, 0
            vavgub    v10, v13, v0
            vspltb    v17, v0, 0
            vxor128   v56, v13, v0
            vspltb    v16, v10, 1
            vcmpequb  v15, v9, v17
            vspltb    v14, v10, 0
            vmaxub    v13, v11, v16
            vmaxub    v10, v12, v14
            vcmpequb  v9, v13, v11
            vcmpequb  v8, v10, v12
            vspltisb  v12, 8
            vxor128   v55, v8, v9
            vand128   v13, v87, v7
            vslo128   v7, v13, v61
            vaddubs   v13, v13, v7
            vslo128   v6, v13, v63
            lvx128    v63, r31, r15
          }
          _R15 = &v74;
          __asm
          {
            vaddubs   v13, v13, v6
            vslo128   v5, v13, v63
            vaddubs   v13, v13, v5
            vsro      v4, v13, v12
            vaddubs   v3, v13, v4
            vcmpgtub  v2, v3, v12
            vandc128  v54, v2, v15
            vand128   v53, v86, v62
            vand128   v52, v85, v56
            vxor128   v125, v0, v52
            vxor128   v120, v88, v125
            stvx128   v125, r0, r11
            stvx128   v120, r0, r15
          }
          idDxtEncoder::EmitAlphaIndices_Xenon(
            this,
            block0: &v67,
            block1: &v71,
            block2: &v68,
            block3: &v70,
            minColor: &v74,
            maxColor: &v73,
            outPtr: _R29 - 8);
          _R10 = 16;
          _R7 = -48;
          __asm { lvx128    v7, r0, r31 }
          _R6 = -64;
          _R5 = -80;
          _R8 = -32;
          __asm { lvx128    v0, r31, r10 }
          _R9 = -16;
          __asm { lvx128    v62, r31, r7 }
          _R4 = v72;
          __asm
          {
            vperm128  v0, v120, v125, v0
            lvx128    v61, r31, r6
            lvx128    v60, r31, r5
          }
          _R3 = &v71;
          __asm { lvx128    v63, r31, r8 }
          _R11 = &v70;
          __asm { lvx128    v13, r31, r9 }
          _R9 = 144;
          __asm { vand128   v50, v0, v61 }
          _R10 = 128;
          __asm { vand128   v49, v0, v62 }
          _R8 = 160;
          __asm { vand128   v48, v0, v60 }
          _R7 = &v67;
          __asm { vand128   v51, v0, v63 }
          _R6 = &v68;
          __asm
          {
            vslw128   v47, v82, v127
            vslw128   v46, v81, v126
            vsrb      v1, v0, v13
            lvx128    v0, r0, r4
            vor128    v45, v79, v46
            vor128    v13, v83, v1
            vor128    v63, v80, v45
            vmrghb    v12, v0, v13
            vspltb    v9, v13, 4
            vspltb    v8, v13, 0
            vperm128  v44, v95, v63, v7
            vadduhs   v30, v12, v12
            vpermwi128 v29, v12, 0xB1
            vspltb    v31, v13, 5
            vspltb    v28, v13, 1
            vspltb    v5, v13, 6
            vadduhs   v12, v29, v30
            vspltb    v27, v13, 2
            stvewx128 v44, r0, r29
            lvx128    v4, r31, r9
            vmrghh    v13, v0, v12
            lvx128    v61, r0, r3
            vmrglh    v12, v0, v12
            lvx128    v63, r0, r11
            lvx128    v6, r31, r10
            vperm128  v43, v93, v63, v6
            vslw128   v26, v13, v127
            vperm128  v42, v93, v63, v4
            vslw128   v25, v13, v126
            vslw128   v24, v13, v122
            vslw128   v23, v13, v121
            vslw128   v22, v12, v127
            vslw128   v21, v12, v126
            vslw128   v20, v12, v122
            vslw128   v19, v12, v121
            vslw128   v18, v13, v123
            vadduws   v17, v25, v26
            vadduws   v16, v23, v24
            vadduws   v11, v19, v20
            vslw128   v15, v12, v123
            vadduws   v14, v21, v22
            vadduws   v10, v18, v13
            vadduws   v7, v16, v17
            vadduws   v3, v15, v12
            vadduws   v2, v11, v14
            vadduws   v1, v7, v10
            vadduws   v30, v2, v3
            vsrw128   v11, v1, v124
            lvx128    v1, r31, r8
            vperm128  v41, v93, v63, v1
            vsrw128   v10, v30, v124
            lvx128    v60, r0, r7
            vmr       v7, v31
            lvx128    v62, r0, r6
            vspltb    v3, v11, 3
            vspltb    v31, v10, 3
          }
          _R5 = 688;
          __asm
          {
            vperm128  v40, v92, v62, v6
            vmr       v6, v28
            vperm128  v39, v92, v62, v4
            vmr       v4, v27
            vspltb    v30, v10, 7
          }
          _R4 = 32;
          __asm
          {
            vspltb    v2, v11, 7
            vmrghw128 v13, v72, v43
            lvx128    v63, r31, r5
            vmrghw128 v12, v71, v42
            vperm128  v38, v92, v62, v1
            vspltb    v29, v11, 0xB
            vsububs   v28, v9, v13
            vspltb    v10, v10, 0xB
            vsububs   v27, v13, v9
            vsububs   v26, v8, v13
            vmrghw128 v11, v70, v41
            vsububs   v25, v13, v8
            vsububs   v24, v3, v13
            vsububs   v23, v13, v3
            vsububs   v22, v31, v13
            vsububs   v21, v13, v31
            vor       v13, v27, v28
            vsububs   v20, v30, v12
            vsububs   v19, v12, v30
            vsububs   v18, v7, v12
            vsububs   v17, v12, v7
            vmrghb    v16, v0, v13
            vmrglb    v14, v0, v13
            vsububs   v1, v2, v12
            vor       v13, v19, v20
            vsububs   v31, v12, v2
            vsububs   v15, v6, v12
            vsububs   v8, v12, v6
            vor       v6, v17, v18
            vmrghb    v19, v0, v13
            vor       v2, v31, v1
            vmrglb    v18, v0, v13
            vsububs   v13, v29, v11
            vsububs   v1, v11, v29
            vsububs   v27, v10, v11
            vmrglb    v31, v0, v6
            vsububs   v20, v11, v10
            vor       v9, v25, v26
            vor       v3, v8, v15
            vsububs   v30, v5, v11
            vsububs   v28, v11, v5
            vmrghb    v5, v0, v6
            vor       v7, v23, v24
            vmrghb    v17, v0, v9
            vsububs   v29, v4, v11
            vmrglb    v26, v0, v9
            vsububs   v25, v11, v4
            vmrglb    v9, v0, v2
            vor       v10, v1, v13
            vor       v8, v21, v22
            vmrghb    v15, v0, v7
            vor       v13, v20, v27
            vmrghb    v22, v0, v3
            vor       v12, v28, v30
            vmrghb    v20, v0, v2
            vor       v11, v25, v29
            vmrglb    v24, v0, v7
            vmrghb    v23, v0, v8
            vadduhs   v27, v14, v31
            vmrglb    v21, v0, v3
            vadduhs   v3, v16, v5
            vmrglb    v8, v0, v8
            vadduhs   v1, v17, v22
            vmrghb    v7, v0, v12
            vadduhs   v29, v15, v20
            vmrghb    v4, v0, v11
            vmrglb    v2, v0, v12
            vmrglb    v30, v0, v11
            vmrglb    v28, v0, v10
            vadduhs   v22, v26, v21
            vmrghb    v25, v0, v13
            vmrglb    v21, v0, v13
            vadduhs   v20, v24, v9
            vmrghb    v17, v0, v10
            vadduhs   v15, v8, v18
            vadduhs   v16, v23, v19
          }
          _R3 = v69;
          __asm { vadduhs   v10, v3, v7 }
          _R11 = v75;
          __asm
          {
            vadduhs   v13, v20, v28
            lvx128    v6, r31, r4
            vadduhs   v0, v29, v17
          }
          --v24;
          __asm { vadduhs   v9, v1, v4 }
          _R30 += 16;
          __asm
          {
            vadduhs   v12, v16, v25
            lvx128    v37, r0, r3
            vadduhs   v11, v15, v21
            lvx128    v36, r0, r11
            vadduhs   v8, v27, v2
            vadduhs   v7, v22, v30
            vcmpgtuh  v14, v10, v0
            vcmpgtuh  v5, v9, v0
            vcmpgtuh  v4, v8, v13
            vcmpgtuh  v3, v7, v13
            vcmpgtuh  v2, v10, v12
            vcmpgtuh  v1, v8, v11
            vcmpgtuh  v31, v7, v11
            vpkuhus128 v35, v14, v4
            vcmpgtuh  v30, v9, v12
            vpkuhus128 v34, v5, v3
            vcmpgtuh  v29, v11, v13
            vpkuhus128 v33, v2, v1
            vcmpgtuh  v28, v12, v0
            vpkuhus128 v32, v30, v31
            vand128   v62, v67, v34
            vpkuhus128 v61, v28, v29
            vand128   v60, v64, v33
            vand128   v59, v67, v61
            vor128    v58, v92, v62
            vand128   v57, v91, v37
            vand128   v56, v90, v36
            vor128    v55, v89, v56
            vsrw128   v54, v87, v63
            vslw128   v53, v87, v119
            vsrw128   v52, v87, v118
            vsrw128   v51, v87, v117
            vor128    v50, v84, v53
            vor128    v49, v86, v51
            vor128    v63, v81, v50
            vperm128  v48, v95, v63, v6
            stvewx128 v48, r29, r19
          }
          _R29 += 16;
          if ( v24 == 0 )
            break;
          _R11 = v72;
          _R10 = v69;
          __asm
          {
            lvx128    v12, r0, r11
            lvx128    v7, r0, r10
          }
        }
      }
      --v12;
      inBuf += v13 + *p_srcPadding;
      outBuf += _R24 + *p_dstPadding;
    }
    while ( v12 != 0 );
  }
}


// ========================================================================
// ?CompressNormalMapDXT5Fast_Xenon@idDxtEncoder@@QAAXPBEPAEHH@Z
// EA  : 0x82927D30
// RVA : 0x00927D30
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder_xenon.cpp
// ========================================================================

void __fastcall idDxtEncoder::CompressNormalMapDXT5Fast_Xenon(
        idDxtEncoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height)
{
  int v10; // r19
  unsigned int v12; // r20
  unsigned int v17; // r29
  int v31; // r10
  __vector4 v32; // [sp+50h] [-F0h] BYREF
  __vector4 v33; // [sp+60h] [-E0h] BYREF
  __vector4 v34; // [sp+70h] [-D0h] BYREF
  __vector4 v35; // [sp+80h] [-C0h] BYREF
  __vector4 v36; // [sp+90h] [-B0h] BYREF
  __vector4 v37[10]; // [sp+A0h] [-A0h] BYREF

  if ( height > 0 )
  {
    v10 = 16 * width;
    _R22 = 4 * width;
    v12 = ((unsigned int)(height - 1) >> 2) + 1;
    _R30 = vmxi_byte_565BitRepShift;
    do
    {
      if ( width > 0 )
      {
        _R27 = 8 * width;
        _R26 = 12 * width;
        _R31 = inBuf;
        v17 = ((unsigned int)(width - 1) >> 2) + 1;
        do
        {
          __asm { lvx128    v13, r0, r31 }
          _R11 = &v36;
          __asm { lvx128    v12, r31, r22 }
          _R10 = v37;
          __asm
          {
            lvx128    v11, r31, r27
            vminub    v0, v13, v12
            lvx128    v10, r31, r26
            vmaxub    v8, v13, v12
            vminub    v7, v11, v10
            vspltw128 v60, v13, 0
            vmaxub    v6, v11, v10
            stvx128   v12, r0, r11
            stvx128   v13, r0, r10
          }
          _R9 = 96;
          _R8 = 128;
          __asm
          {
            lvx128    v9, r0, r30
            vminub    v12, v0, v7
          }
          _R7 = 112;
          __asm { vmaxub    v13, v8, v6 }
          _R6 = -16;
          _R5 = -32;
          __asm { lvx128    v8, r30, r9 }
          _R11 = &v33;
          __asm
          {
            vpermwi128 v5, v12, 0xB1
            lvx128    v0, r30, r8
            vpermwi128 v4, v13, 0xB1
            lvx128    v61, r30, r7
            lvx128    v62, r30, r6
          }
          _R17 = &v32;
          __asm { lvx128    v63, r30, r5 }
          _R18 = &v33;
          __asm { vminub    v12, v12, v5 }
          _R9 = &v35;
          __asm { vmaxub    v13, v13, v4 }
          _R8 = &v34;
          __asm { vandc128  v59, v92, v63 }
          _R16 = &v32;
          __asm { vpermwi128 v3, v12, 0x44 # 'D' }
          __asm
          {
            vpermwi128 v2, v13, 0x44 # 'D'
            stvx128   v11, r0, r9
            stvx128   v10, r0, r8
          }
          __asm
          {
            vminub    v1, v12, v3
            vspltisb  v12, 0
            vmaxub    v31, v13, v2
          }
          __asm
          {
            vmrghb    v13, v12, v31
            vmrghb    v12, v12, v1
            vslh      v30, v13, v0
            vsubshs   v29, v13, v12
            vslh      v28, v12, v0
            vsubshs   v27, v29, v8
            vand128   v13, v27, v61
            vaddshs   v26, v28, v13
            vsubshs   v25, v30, v13
            vsrah     v24, v26, v0
            vsrah     v23, v25, v0
            vpkshus128 v58, v24, v24
            vpkshus128 v57, v23, v23
            vand128   v0, v90, v62
            vand128   v13, v89, v62
            vsrb      v22, v0, v9
            stvx128   v0, r0, r11
            vsrb      v21, v13, v9
            stvx128   v13, r0, r17
            vor128    v56, v0, v22
            vor128    v55, v13, v21
            vand128   v54, v88, v63
            vand128   v53, v87, v63
            vor128    v52, v86, v59
            vor128    v51, v85, v59
            stvx128   v52, r0, r18
            stvx128   v51, r0, r16
          }
          idDxtEncoder::EmitAlphaIndices_Xenon(
            this,
            block0: v37,
            block1: &v36,
            block2: &v35,
            block3: &v34,
            minColor: &v33,
            maxColor: &v32,
            outPtr: (unsigned __int8 *)&_R31[outBuf - inBuf]);
          idDxtEncoder::EmitGreenIndices_Xenon(
            this,
            block0: v37,
            block1: &v36,
            block2: &v35,
            block3: &v34,
            minGreen: &v33,
            maxGreen: &v32,
            outPtr: (unsigned __int8 *)(v31 + 8));
          --v17;
          _R31 += 16;
        }
        while ( v17 != 0 );
      }
      --v12;
      inBuf += v10 + this->srcPadding;
      outBuf += _R22 + this->dstPadding;
    }
    while ( v12 != 0 );
  }
}

