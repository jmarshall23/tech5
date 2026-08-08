
// ========================================================================
// DecompressCover16x16
// EA  : 0x8292E2C8
// RVA : 0x0092E2C8
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall DecompressCover16x16(
        const unsigned __int8 *cover,
        int tileX,
        int tileY,
        unsigned __int8 *rgba,
        int byteStride)
{
  int v6; // r11

  __asm { vspltisb  v0, 0 }
  __asm { lvx128    v61, r0, r6 }
  v6 = (tileY << 7) + tileX;
  _R5 = vmxi_word_cover_mask2;
  _R4 = -32;
  _R11 = &cover[(2 * v6) & 0x1FFFFFFE];
  _R3 = 1;
  _R10 = 16;
  __asm { lvx128    v63, r0, r5 }
  _R31 = -16;
  __asm
  {
    vand128   v60, v93, v63
    lvx128    v62, r5, r4
  }
  _R9 = rgba + 16;
  __asm { lvlx      v13, r0, r11 }
  _R8 = rgba + 32;
  __asm { lvlx      v11, r3, r11 }
  _R4 = 17;
  __asm
  {
    vspltb    v12, v13, 0
    lvlx      v10, r10, r11
    lvx128    v61, r5, r31
    vspltb    v9, v11, 0
    vspltb    v8, v10, 0
    lvx128    v59, r0, r9
  }
  _R5 = rgba + 48;
  __asm
  {
    vand128   v58, v91, v63
    vand128   v7, v12, v62
    lvx128    v57, r0, r8
    vand128   v6, v12, v61
  }
  __asm
  {
    vand128   v5, v9, v62
    lvlx      v4, r4, r11
    vand128   v31, v9, v61
  }
  _R3 = 32;
  __asm
  {
    vcmpgtub  v3, v7, v0
    lvx128    v56, r0, r5
    vcmpgtub  v2, v6, v0
    vspltb    v1, v4, 0
    vand128   v29, v8, v62
    vand128   v53, v89, v63
    vor128    v55, v92, v3
    lvlx      v30, r3, r11
    vor128    v54, v90, v2
    vand128   v52, v88, v63
    vspltb    v28, v30, 0
    vcmpgtub  v27, v5, v0
    stvx128   v55, r0, r6
    vcmpgtub  v26, v31, v0
    lvx128    v51, r6, r7
    vcmpgtub  v25, v29, v0
    vand128   v50, v83, v63
    stvx128   v54, r0, r9
  }
  _R9 = &rgba[byteStride + 16];
  __asm
  {
    vor128    v49, v85, v27
    vor128    v48, v84, v26
    vor128    v47, v82, v25
    vand128   v24, v8, v61
    stvx128   v49, r0, r8
  }
  _R8 = &rgba[byteStride + 32];
  __asm
  {
    stvx128   v48, r0, r5
    vand128   v22, v1, v62
    stvx128   v47, r6, r7
  }
  __asm
  {
    lvx128    v46, r0, r9
    vcmpgtub  v23, v24, v0
    vand128   v45, v78, v63
  }
  _R10 = &rgba[byteStride + byteStride];
  _R6 = &rgba[byteStride + 48];
  __asm
  {
    vor128    v44, v77, v23
    vcmpgtub  v20, v22, v0
    vand128   v21, v1, v61
    vand128   v18, v28, v62
    stvx128   v44, r0, r9
    lvx128    v43, r0, r8
    vand128   v42, v75, v63
    vor128    v41, v74, v20
    vcmpgtub  v19, v21, v0
    stvx128   v41, r0, r8
    lvx128    v40, r0, r6
    vand128   v39, v72, v63
    vor128    v38, v71, v19
  }
  _R9 = _R10 + 16;
  __asm { vcmpgtub  v16, v18, v0 }
  _R5 = 33;
  __asm { vand128   v17, v28, v61 }
  _R8 = _R10 + 32;
  _R4 = 48;
  __asm { stvx128   v38, r0, r6 }
  _R6 = _R10 + 48;
  _R3 = 49;
  __asm
  {
    lvlx      v15, r5, r11
    vcmpgtub  v14, v17, v0
  }
  _R5 = 64;
  __asm
  {
    vspltb    v13, v15, 0
    lvlx      v12, r4, r11
  }
  _R31 = 65;
  __asm
  {
    vspltb    v10, v12, 0
    lvlx      v11, r3, r11
  }
  _R4 = 80;
  __asm
  {
    vand128   v5, v13, v62
    vspltb    v8, v11, 0
    vand128   v3, v13, v61
    lvlx      v9, r5, r11
    vand128   v31, v10, v62
    lvlx      v7, r31, r11
    vand128   v30, v10, v61
    vspltb    v6, v9, 0
    vcmpgtub  v2, v5, v0
    vspltb    v4, v7, 0
    vcmpgtub  v1, v3, v0
  }
  _R3 = 81;
  __asm { vcmpgtub  v29, v31, v0 }
  _R5 = 96;
  __asm
  {
    vcmpgtub  v28, v30, v0
    vand128   v27, v8, v62
    vand128   v25, v8, v61
    vand128   v24, v6, v62
    vand128   v21, v6, v61
    lvx128    v37, r0, r10
    vcmpgtub  v26, v27, v0
    vand128   v36, v69, v63
    vcmpgtub  v23, v25, v0
    vcmpgtub  v22, v24, v0
    vand128   v20, v4, v62
    vor128    v35, v68, v16
    vand128   v19, v4, v61
    stvx128   v35, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v34, r0, r9
    vand128   v33, v66, v63
    vor128    v32, v65, v14
    stvx128   v32, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v60, r0, r8
    vand128   v59, v92, v63
    vor128    v58, v91, v2
    stvx128   v58, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v57, r0, r6
    vand128   v56, v89, v63
    vor128    v55, v88, v1
    stvx128   v55, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v54, r0, r10
    vand128   v53, v86, v63
    vor128    v52, v85, v29
    stvx128   v52, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v51, r0, r9
    vand128   v50, v83, v63
    vor128    v49, v82, v28
    stvx128   v49, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v48, r0, r8
    vand128   v47, v80, v63
    vor128    v46, v79, v26
    stvx128   v46, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v45, r0, r6
    vand128   v44, v77, v63
    vor128    v43, v76, v23
    stvx128   v43, r0, r6
    vcmpgtub  v17, v21, v0
    lvx128    v42, r0, r10
    vand128   v41, v74, v63
    vor128    v40, v73, v22
  }
  _R6 = _R10 + 48;
  __asm
  {
    vcmpgtub  v15, v20, v0
    lvlx      v18, r4, r11
    vcmpgtub  v13, v19, v0
    lvlx      v16, r3, r11
    vspltb    v14, v18, 0
    lvlx      v11, r5, r11
    stvx128   v40, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v39, r0, r9
    vand128   v38, v71, v63
    vor128    v37, v70, v17
    vspltb    v12, v16, 0
    vand128   v8, v14, v62
    vspltb    v10, v11, 0
    vand128   v7, v14, v61
  }
  _R4 = 97;
  _R3 = 112;
  __asm { stvx128   v37, r0, r9 }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v36, r0, r8
    vand128   v35, v68, v63
    vor128    v34, v67, v15
    lvlx      v9, r4, r11
    vcmpgtub  v4, v8, v0
    lvlx      v24, r3, r11
    vcmpgtub  v3, v7, v0
    vspltb    v6, v9, 0
    vand128   v5, v12, v62
    vspltb    v22, v24, 0
    stvx128   v34, r0, r8
  }
  _R8 = _R10 + 32;
  __asm { vand128   v1, v12, v61 }
  _R5 = 113;
  __asm
  {
    vand128   v30, v10, v62
    vcmpgtub  v2, v5, v0
    vand128   v29, v10, v61
    vcmpgtub  v31, v1, v0
    vcmpgtub  v28, v30, v0
    vand128   v26, v6, v62
    vcmpgtub  v27, v29, v0
    vand128   v23, v6, v61
    vcmpgtub  v25, v26, v0
    lvx128    v33, r0, r6
    vand128   v32, v65, v63
    vor128    v60, v64, v13
    stvx128   v60, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v59, r0, r10
    vand128   v58, v91, v63
    vor128    v57, v90, v4
    stvx128   v57, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v56, r0, r9
    vand128   v55, v88, v63
    vor128    v54, v87, v3
    stvx128   v54, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v53, r0, r8
    vand128   v52, v85, v63
    vor128    v51, v84, v2
    stvx128   v51, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v50, r0, r6
    vand128   v49, v82, v63
    vor128    v48, v81, v31
    stvx128   v48, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v47, r0, r10
    vand128   v46, v79, v63
    vor128    v45, v78, v28
    stvx128   v45, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v44, r0, r9
    vand128   v43, v76, v63
    vor128    v42, v75, v27
    stvx128   v42, r0, r9
    vcmpgtub  v20, v23, v0
    vand128   v18, v22, v62
  }
  _R9 = _R10 + 16;
  __asm
  {
    vand128   v16, v22, v61
    lvlx      v21, r5, r11
  }
  _R4 = 128;
  __asm { vspltb    v19, v21, 0 }
  _R3 = 129;
  __asm { vcmpgtub  v13, v18, v0 }
  _R5 = 144;
  __asm { vcmpgtub  v12, v16, v0 }
  _R31 = 176;
  __asm
  {
    vand128   v10, v19, v62
    lvlx      v17, r4, r11
    vand128   v9, v19, v61
    lvlx      v14, r3, r11
    vspltb    v15, v17, 0
  }
  _R4 = 145;
  __asm { vspltb    v11, v14, 0 }
  _R3 = 160;
  __asm
  {
    vcmpgtub  v8, v10, v0
    lvlx      v29, r5, r11
    vcmpgtub  v7, v9, v0
  }
  _R5 = 161;
  __asm
  {
    vand128   v6, v15, v62
    lvlx      v22, r31, r11
    vand128   v5, v15, v61
    lvlx      v27, r4, r11
    vand128   v4, v11, v62
    vspltb    v28, v29, 0
    vand128   v3, v11, v61
  }
  _R4 = 177;
  __asm
  {
    vcmpgtub  v2, v6, v0
    lvlx      v24, r5, r11
    vcmpgtub  v1, v5, v0
    vspltb    v26, v27, 0
    lvx128    v41, r0, r8
    vcmpgtub  v31, v4, v0
    vand128   v40, v73, v63
    vcmpgtub  v30, v3, v0
    vor128    v39, v72, v25
    lvlx      v25, r3, r11
    vspltb    v23, v25, 0
    stvx128   v39, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v38, r0, r6
    vand128   v37, v70, v63
    vor128    v36, v69, v20
    stvx128   v36, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v35, r0, r10
    vand128   v34, v67, v63
    vor128    v33, v66, v13
    stvx128   v33, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v32, r0, r9
    vand128   v60, v64, v63
    vor128    v59, v92, v12
    stvx128   v59, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v58, r0, r8
    vand128   v57, v90, v63
    vor128    v56, v89, v8
    stvx128   v56, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v55, r0, r6
    vand128   v54, v87, v63
    vor128    v53, v86, v7
    stvx128   v53, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v52, r0, r10
    vand128   v51, v84, v63
    vor128    v50, v83, v2
    stvx128   v50, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v49, r0, r9
    vand128   v48, v81, v63
    vor128    v47, v80, v1
    stvx128   v47, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v46, r0, r8
    vand128   v21, v28, v62
    vand128   v45, v78, v63
    vspltb    v20, v24, 0
    vand128   v19, v28, v61
    vspltb    v18, v22, 0
    vand128   v15, v26, v62
  }
  _R3 = 192;
  __asm
  {
    vcmpgtub  v17, v21, v0
    lvlx      v1, r4, r11
    vor128    v44, v77, v31
  }
  _R5 = 193;
  __asm
  {
    vcmpgtub  v16, v19, v0
    vcmpgtub  v11, v15, v0
    vand128   v14, v26, v61
    lvlx      v29, r3, r11
    stvx128   v44, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v43, r0, r6
    vand128   v42, v75, v63
    vor128    v41, v74, v30
    vspltb    v30, v1, 0
    vcmpgtub  v10, v14, v0
    vspltb    v27, v29, 0
    vand128   v13, v23, v62
    vand128   v12, v23, v61
    stvx128   v41, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    vand128   v7, v20, v62
    vcmpgtub  v9, v13, v0
    vcmpgtub  v8, v12, v0
    vand128   v6, v20, v61
    vcmpgtub  v5, v7, v0
    vand128   v3, v18, v62
    vand128   v31, v18, v61
    vcmpgtub  v4, v6, v0
    vcmpgtub  v2, v3, v0
    vcmpgtub  v28, v31, v0
    lvx128    v40, r0, r10
    vand128   v39, v72, v63
    vor128    v38, v71, v17
    stvx128   v38, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v37, r0, r9
    vand128   v36, v69, v63
    vor128    v35, v68, v16
    stvx128   v35, r0, r9
  }
  _R9 = (int)(_R10 + 16);
  __asm
  {
    lvx128    v34, r0, r8
    vand128   v33, v66, v63
    vor128    v32, v65, v11
    stvx128   v32, r0, r8
  }
  _R8 = (int)(_R10 + 32);
  __asm
  {
    lvx128    v60, r0, r6
    vand128   v59, v92, v63
    vor128    v58, v91, v10
    stvx128   v58, r0, r6
  }
  _R6 = (int)(_R10 + 48);
  __asm
  {
    lvx128    v57, r0, r10
    vand128   v56, v89, v63
    vor128    v55, v88, v9
    stvx128   v55, r0, r10
  }
  _R10 = (int)&_R10[byteStride];
  __asm
  {
    lvx128    v54, r0, r9
    vand128   v53, v86, v63
    vor128    v52, v85, v8
    stvx128   v52, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v51, r0, r8
    vand128   v50, v83, v63
    vor128    v49, v82, v5
    stvx128   v49, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v48, r0, r6
    vand128   v47, v80, v63
    vor128    v46, v79, v4
    stvx128   v46, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v45, r0, r10
    vand128   v44, v77, v63
    vor128    v43, v76, v2
    stvx128   v43, r0, r10
    vand128   v26, v30, v62
    vand128   v24, v30, v61
  }
  _R10 = _R10 + byteStride;
  __asm
  {
    vand128   v17, v27, v62
    lvlx      v25, r5, r11
    vand128   v15, v27, v61
  }
  _R4 = 208;
  __asm
  {
    vcmpgtub  v21, v26, v0
    vspltb    v23, v25, 0
    vcmpgtub  v19, v24, v0
  }
  _R3 = 209;
  __asm { vcmpgtub  v14, v17, v0 }
  _R5 = 224;
  __asm
  {
    vcmpgtub  v13, v15, v0
    vand128   v12, v23, v62
    lvlx      v22, r4, r11
    vand128   v11, v23, v61
  }
  _R4 = 225;
  __asm
  {
    vspltb    v18, v22, 0
    lvlx      v20, r3, r11
  }
  _R3 = 240;
  __asm
  {
    lvlx      v3, r5, r11
    vcmpgtub  v9, v12, v0
    vspltb    v16, v20, 0
    vcmpgtub  v8, v11, v0
  }
  _R5 = 241;
  __asm
  {
    vand128   v10, v18, v62
    lvlx      v29, r4, r11
    vand128   v6, v18, v61
    vspltb    v31, v3, 0
    vand128   v5, v16, v62
    vspltb    v27, v29, 0
    vand128   v4, v16, v61
    vcmpgtub  v7, v10, v0
    lvlx      v26, r5, r11
    vcmpgtub  v2, v6, v0
    lvx128    v42, r0, r9
    vcmpgtub  v1, v5, v0
    vand128   v41, v74, v63
    vcmpgtub  v30, v4, v0
    vor128    v40, v73, v28
    lvlx      v28, r3, r11
    vspltb    v25, v28, 0
    stvx128   v40, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v39, r0, r8
    vand128   v38, v71, v63
    vor128    v37, v70, v21
    stvx128   v37, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v36, r0, r6
    vand128   v35, v68, v63
    vor128    v34, v67, v19
    stvx128   v34, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v33, r0, r10
    vand128   v32, v65, v63
    vor128    v60, v64, v14
    stvx128   v60, r0, r10
  }
  _R10 = _R10 + byteStride;
  _R11 = _R10 + byteStride;
  __asm
  {
    lvx128    v59, r0, r9
    vand128   v58, v91, v63
    vor128    v57, v90, v13
    stvx128   v57, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v56, r0, r8
    vand128   v55, v88, v63
    vor128    v54, v87, v9
    stvx128   v54, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v53, r0, r6
    vand128   v52, v85, v63
    vor128    v51, v84, v8
    stvx128   v51, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v50, r0, r10
    vand128   v49, v82, v63
    vor128    v48, v81, v7
    stvx128   v48, r0, r10
    lvx128    v47, r0, r9
    vand128   v23, v31, v62
    vand128   v46, v79, v63
  }
  __asm
  {
    vand128   v22, v31, v61
    vspltb    v24, v26, 0
    vand128   v21, v27, v62
    vcmpgtub  v20, v23, v0
    vor128    v45, v78, v2
    vcmpgtub  v19, v22, v0
    vcmpgtub  v17, v21, v0
    vand128   v18, v27, v61
    stvx128   v45, r0, r9
  }
  _R9 = _R10 + byteStride + 32;
  __asm
  {
    lvx128    v44, r0, r8
    vand128   v43, v76, v63
    vor128    v42, v75, v1
    vcmpgtub  v14, v18, v0
    vand128   v16, v25, v62
    vand128   v15, v25, v61
    stvx128   v42, r0, r8
  }
  _R8 = _R10 + byteStride + 48;
  __asm
  {
    lvx128    v41, r0, r6
    vand128   v40, v73, v63
    vor128    v39, v72, v30
    vcmpgtub  v13, v16, v0
    vcmpgtub  v12, v15, v0
    vand128   v11, v24, v62
    stvx128   v39, r0, r6
    vand128   v9, v24, v61
    lvx128    v38, r0, r11
    vand128   v37, v70, v63
    vor128    v36, v69, v20
    vcmpgtub  v10, v11, v0
    vcmpgtub  v8, v9, v0
    stvx128   v36, r0, r11
  }
  _R11 = _R10 + byteStride + byteStride;
  _R10 = _R10 + byteStride + 16;
  __asm
  {
    lvx128    v35, r0, r10
    vand128   v34, v67, v63
    vor128    v33, v66, v19
    stvx128   v33, r0, r10
  }
  _R10 = _R11 + 16;
  __asm
  {
    lvx128    v32, r0, r9
    vand128   v60, v64, v63
    vor128    v59, v92, v17
    stvx128   v59, r0, r9
  }
  _R9 = _R11 + 32;
  __asm
  {
    lvx128    v58, r0, r8
    vand128   v57, v90, v63
    vor128    v56, v89, v14
    stvx128   v56, r0, r8
  }
  _R8 = _R11 + 48;
  __asm
  {
    lvx128    v55, r0, r11
    vand128   v54, v87, v63
    vor128    v53, v86, v13
    stvx128   v53, r0, r11
    lvx128    v52, r0, r10
    vand128   v51, v84, v63
    vor128    v50, v83, v12
    stvx128   v50, r0, r10
    lvx128    v49, r0, r9
    vand128   v48, v81, v63
    vor128    v47, v80, v10
    stvx128   v47, r0, r9
    lvx128    v46, r0, r8
    vand128   v45, v78, v63
    vor128    v44, v77, v8
    stvx128   v44, r0, r8
  }
}


// ========================================================================
// ConstantScaleSpecular16x16
// EA  : 0x8292EB80
// RVA : 0x0092EB80
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall ConstantScaleSpecular16x16(
        unsigned __int8 *specularScale,
        int tileX,
        int tileY,
        unsigned __int8 *rgba,
        unsigned __int8 specularShift,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        unsigned __int8 a20)
{
  int v24; // ctr
  unsigned __int8 *v34; // r11
  int v35; // r7

  _R9 = &a20;
  a20 = specularShift;
  _R8 = vmxi_word_specular_shift_mask;
  _R11 = rgba + 32;
  __asm
  {
    lvlx      v0, r0, r9
    vspltb    v13, v0, 0
    lvx128    v63, r0, r8
  }
  v24 = 8;
  _R30 = -32;
  __asm { vand128   v0, v13, v63 }
  _R29 = -32;
  _R28 = -16;
  _R27 = -16;
  _R31 = 16;
  _R6 = 32;
  _R8 = 48;
  _R9 = 64;
  _R10 = 80;
  do
  {
    __asm
    {
      lvx128    v13, r11, r30
      lvx128    v12, r11, r28
      vslb      v11, v13, v0
      lvx128    v10, r0, r11
      vslb      v9, v12, v0
      lvx128    v8, r11, r31
      vslb      v7, v10, v0
      lvx128    v6, r11, r6
      vslb      v5, v8, v0
      lvx128    v4, r11, r8
      vslb      v3, v6, v0
      lvx128    v2, r11, r9
      vslb      v1, v4, v0
      lvx128    v31, r11, r10
      vslb      v30, v2, v0
      vslb      v29, v31, v0
      stvx128   v11, r11, r29
      stvx128   v9, r11, r27
      stvx128   v7, r0, r11
      stvx128   v5, r11, r31
      stvx128   v3, r11, r6
      stvx128   v1, r11, r8
      stvx128   v30, r11, r9
      stvx128   v29, r11, r10
    }
    _R11 += 128;
    --v24;
  }
  while ( v24 != 0 );
  v34 = &specularScale[4 * tileX + (tileY << 9 >> 2)];
  v35 = (((((((8 * ((1 << specularShift) + 255)) & 0xF8) << 8) | (8 * ((1 << specularShift) + 255)) & 0xF8) << 8)
        | (8 * ((1 << specularShift) + 255)) & 0xF8) << 8)
      | (8 * ((1 << specularShift) + 255)) & 0xF8;
  *(_DWORD *)v34 = v35;
  *((_DWORD *)v34 + 8) = v35;
  *((_DWORD *)v34 + 16) = v35;
  *((_DWORD *)v34 + 24) = v35;
}


// ========================================================================
// DynamicScaleSpecular16x16
// EA  : 0x8292EC98
// RVA : 0x0092EC98
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall DynamicScaleSpecular16x16(unsigned __int8 *specularScale, int tileX, int tileY, unsigned __int8 *rgba)
{
  int v8; // r25
  unsigned int v9; // r27
  unsigned int v10; // r26
  int i; // ctr

  __asm { vspltisb  v30, 2 }
  _R10 = 16;
  __asm { vspltisb  v12, 8 }
  _R9 = vmxi_byte_63;
  _R8 = 32;
  v8 = 4 * tileX;
  v9 = 0;
  v10 = tileY << 9;
  __asm
  {
    lvx128    v3, r0, r9
    lvx128    v2, r9, r10
    lvx128    v63, r9, r8
  }
  do
  {
    _R10 = 0;
    _R29 = &specularScale[(v10 >> 2) + v8];
    _R28 = _R29 + 1;
    for ( i = 2; i != 0; --i )
    {
      _R11 = &rgba[16 * v9 + 16 * _R10];
      _R9 = _R11 + 64;
      _R8 = _R11 + 128;
      _R7 = _R11 + 192;
      _R5 = _R11 + 16;
      __asm { lvx128    v11, r0, r11 }
      _R4 = _R11 + 80;
      _R31 = _R11 + 144;
      __asm { lvx128    v10, r0, r9 }
      _R30 = _R11 + 208;
      __asm
      {
        lvx128    v9, r0, r8
        lvx128    v8, r0, r7
        vmaxub    v0, v11, v10
        lvx128    v7, r0, r5
        vmaxub    v13, v9, v8
        lvx128    v6, r0, r4
        lvx128    v5, r0, r31
        vmaxub    v1, v7, v6
        lvx128    v4, r0, r30
        vmaxub    v31, v5, v4
        vmaxub    v0, v0, v13
        vmaxub    v13, v1, v31
        vsldoi    v29, v0, v0, v8
        vsldoi    v28, v13, v13, v8
        vmaxub    v0, v0, v29
        vmaxub    v13, v13, v28
        vsldoi    v27, v0, v0, v4
        vsldoi    v26, v13, v13, v4
        vmaxub    v0, v0, v27
        vmaxub    v13, v13, v26
        vsldoi    v25, v0, v0, v15
        vsldoi    v24, v13, v13, v15
        vmaxub    v0, v0, v25
        vmaxub    v13, v13, v24
        vsldoi    v23, v0, v0, v15
        vsldoi    v22, v13, v13, v15
        vmaxub    v21, v0, v23
        vmaxub    v20, v13, v22
        vspltb    v0, v21, 2
        vspltb    v13, v20, 2
        vcmpgtub  v19, v0, v3
        vcmpgtub  v18, v0, v2
        vcmpgtub  v17, v13, v3
        vcmpgtub  v16, v13, v2
        vaddsbs   v15, v30, v19
        vaddsbs   v14, v30, v17
        vaddsbs   v0, v15, v18
        vaddsbs   v13, v14, v16
        vslb      v1, v12, v0
        vand128   v0, v0, v63
        vslb      v31, v12, v13
        vand128   v13, v13, v63
        vsububs   v1, v1, v12
        vslb      v29, v11, v0
        vslb      v28, v10, v0
        vslb      v27, v9, v0
        vslb      v26, v8, v0
        vslb      v25, v7, v13
        stvx128   v29, r0, r11
        vslb      v24, v6, v13
        stvx128   v28, r0, r9
        vslb      v23, v5, v13
        stvx128   v27, r0, r8
        vslb      v22, v4, v13
        stvx128   v26, r0, r7
        vsububs   v21, v31, v12
        stvx128   v25, r0, r5
        stvx128   v24, r0, r4
        stvx128   v23, r0, r31
        stvx128   v22, r0, r30
        stvebx    v1, r29, r10
        stvebx    v21, r28, r10
      }
      _R10 += 2;
    }
    v9 += 16;
    v10 += 128;
  }
  while ( v9 < 0x40 );
}


// ========================================================================
// DecompressCover16x16_0
// EA  : 0x8292FB60
// RVA : 0x0092FB60
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall DecompressCover16x16_0(
        const unsigned __int8 *cover,
        int tileX,
        int tileY,
        unsigned __int8 *rgba,
        int byteStride)
{
  int v6; // r11

  __asm { vspltisb  v0, 0 }
  __asm { lvx128    v61, r0, r6 }
  v6 = (tileY << 7) + tileX;
  _R5 = vmxi_word_cover_mask2_0;
  _R4 = -32;
  _R11 = &cover[(2 * v6) & 0x1FFFFFFE];
  _R3 = 1;
  _R10 = 16;
  __asm { lvx128    v63, r0, r5 }
  _R31 = -16;
  __asm
  {
    vand128   v60, v93, v63
    lvx128    v62, r5, r4
  }
  _R9 = rgba + 16;
  __asm { lvlx      v13, r0, r11 }
  _R8 = rgba + 32;
  __asm { lvlx      v11, r3, r11 }
  _R4 = 17;
  __asm
  {
    vspltb    v12, v13, 0
    lvlx      v10, r10, r11
    lvx128    v61, r5, r31
    vspltb    v9, v11, 0
    vspltb    v8, v10, 0
    lvx128    v59, r0, r9
  }
  _R5 = rgba + 48;
  __asm
  {
    vand128   v58, v91, v63
    vand128   v7, v12, v62
    lvx128    v57, r0, r8
    vand128   v6, v12, v61
  }
  __asm
  {
    vand128   v5, v9, v62
    lvlx      v4, r4, r11
    vand128   v31, v9, v61
  }
  _R3 = 32;
  __asm
  {
    vcmpgtub  v3, v7, v0
    lvx128    v56, r0, r5
    vcmpgtub  v2, v6, v0
    vspltb    v1, v4, 0
    vand128   v29, v8, v62
    vand128   v53, v89, v63
    vor128    v55, v92, v3
    lvlx      v30, r3, r11
    vor128    v54, v90, v2
    vand128   v52, v88, v63
    vspltb    v28, v30, 0
    vcmpgtub  v27, v5, v0
    stvx128   v55, r0, r6
    vcmpgtub  v26, v31, v0
    lvx128    v51, r6, r7
    vcmpgtub  v25, v29, v0
    vand128   v50, v83, v63
    stvx128   v54, r0, r9
  }
  _R9 = &rgba[byteStride + 16];
  __asm
  {
    vor128    v49, v85, v27
    vor128    v48, v84, v26
    vor128    v47, v82, v25
    vand128   v24, v8, v61
    stvx128   v49, r0, r8
  }
  _R8 = &rgba[byteStride + 32];
  __asm
  {
    stvx128   v48, r0, r5
    vand128   v22, v1, v62
    stvx128   v47, r6, r7
  }
  __asm
  {
    lvx128    v46, r0, r9
    vcmpgtub  v23, v24, v0
    vand128   v45, v78, v63
  }
  _R10 = &rgba[byteStride + byteStride];
  _R6 = &rgba[byteStride + 48];
  __asm
  {
    vor128    v44, v77, v23
    vcmpgtub  v20, v22, v0
    vand128   v21, v1, v61
    vand128   v18, v28, v62
    stvx128   v44, r0, r9
    lvx128    v43, r0, r8
    vand128   v42, v75, v63
    vor128    v41, v74, v20
    vcmpgtub  v19, v21, v0
    stvx128   v41, r0, r8
    lvx128    v40, r0, r6
    vand128   v39, v72, v63
    vor128    v38, v71, v19
  }
  _R9 = _R10 + 16;
  __asm { vcmpgtub  v16, v18, v0 }
  _R5 = 33;
  __asm { vand128   v17, v28, v61 }
  _R8 = _R10 + 32;
  _R4 = 48;
  __asm { stvx128   v38, r0, r6 }
  _R6 = _R10 + 48;
  _R3 = 49;
  __asm
  {
    lvlx      v15, r5, r11
    vcmpgtub  v14, v17, v0
  }
  _R5 = 64;
  __asm
  {
    vspltb    v13, v15, 0
    lvlx      v12, r4, r11
  }
  _R31 = 65;
  __asm
  {
    vspltb    v10, v12, 0
    lvlx      v11, r3, r11
  }
  _R4 = 80;
  __asm
  {
    vand128   v5, v13, v62
    vspltb    v8, v11, 0
    vand128   v3, v13, v61
    lvlx      v9, r5, r11
    vand128   v31, v10, v62
    lvlx      v7, r31, r11
    vand128   v30, v10, v61
    vspltb    v6, v9, 0
    vcmpgtub  v2, v5, v0
    vspltb    v4, v7, 0
    vcmpgtub  v1, v3, v0
  }
  _R3 = 81;
  __asm { vcmpgtub  v29, v31, v0 }
  _R5 = 96;
  __asm
  {
    vcmpgtub  v28, v30, v0
    vand128   v27, v8, v62
    vand128   v25, v8, v61
    vand128   v24, v6, v62
    vand128   v21, v6, v61
    lvx128    v37, r0, r10
    vcmpgtub  v26, v27, v0
    vand128   v36, v69, v63
    vcmpgtub  v23, v25, v0
    vcmpgtub  v22, v24, v0
    vand128   v20, v4, v62
    vor128    v35, v68, v16
    vand128   v19, v4, v61
    stvx128   v35, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v34, r0, r9
    vand128   v33, v66, v63
    vor128    v32, v65, v14
    stvx128   v32, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v60, r0, r8
    vand128   v59, v92, v63
    vor128    v58, v91, v2
    stvx128   v58, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v57, r0, r6
    vand128   v56, v89, v63
    vor128    v55, v88, v1
    stvx128   v55, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v54, r0, r10
    vand128   v53, v86, v63
    vor128    v52, v85, v29
    stvx128   v52, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v51, r0, r9
    vand128   v50, v83, v63
    vor128    v49, v82, v28
    stvx128   v49, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v48, r0, r8
    vand128   v47, v80, v63
    vor128    v46, v79, v26
    stvx128   v46, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v45, r0, r6
    vand128   v44, v77, v63
    vor128    v43, v76, v23
    stvx128   v43, r0, r6
    vcmpgtub  v17, v21, v0
    lvx128    v42, r0, r10
    vand128   v41, v74, v63
    vor128    v40, v73, v22
  }
  _R6 = _R10 + 48;
  __asm
  {
    vcmpgtub  v15, v20, v0
    lvlx      v18, r4, r11
    vcmpgtub  v13, v19, v0
    lvlx      v16, r3, r11
    vspltb    v14, v18, 0
    lvlx      v11, r5, r11
    stvx128   v40, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v39, r0, r9
    vand128   v38, v71, v63
    vor128    v37, v70, v17
    vspltb    v12, v16, 0
    vand128   v8, v14, v62
    vspltb    v10, v11, 0
    vand128   v7, v14, v61
  }
  _R4 = 97;
  _R3 = 112;
  __asm { stvx128   v37, r0, r9 }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v36, r0, r8
    vand128   v35, v68, v63
    vor128    v34, v67, v15
    lvlx      v9, r4, r11
    vcmpgtub  v4, v8, v0
    lvlx      v24, r3, r11
    vcmpgtub  v3, v7, v0
    vspltb    v6, v9, 0
    vand128   v5, v12, v62
    vspltb    v22, v24, 0
    stvx128   v34, r0, r8
  }
  _R8 = _R10 + 32;
  __asm { vand128   v1, v12, v61 }
  _R5 = 113;
  __asm
  {
    vand128   v30, v10, v62
    vcmpgtub  v2, v5, v0
    vand128   v29, v10, v61
    vcmpgtub  v31, v1, v0
    vcmpgtub  v28, v30, v0
    vand128   v26, v6, v62
    vcmpgtub  v27, v29, v0
    vand128   v23, v6, v61
    vcmpgtub  v25, v26, v0
    lvx128    v33, r0, r6
    vand128   v32, v65, v63
    vor128    v60, v64, v13
    stvx128   v60, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v59, r0, r10
    vand128   v58, v91, v63
    vor128    v57, v90, v4
    stvx128   v57, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v56, r0, r9
    vand128   v55, v88, v63
    vor128    v54, v87, v3
    stvx128   v54, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v53, r0, r8
    vand128   v52, v85, v63
    vor128    v51, v84, v2
    stvx128   v51, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v50, r0, r6
    vand128   v49, v82, v63
    vor128    v48, v81, v31
    stvx128   v48, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v47, r0, r10
    vand128   v46, v79, v63
    vor128    v45, v78, v28
    stvx128   v45, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v44, r0, r9
    vand128   v43, v76, v63
    vor128    v42, v75, v27
    stvx128   v42, r0, r9
    vcmpgtub  v20, v23, v0
    vand128   v18, v22, v62
  }
  _R9 = _R10 + 16;
  __asm
  {
    vand128   v16, v22, v61
    lvlx      v21, r5, r11
  }
  _R4 = 128;
  __asm { vspltb    v19, v21, 0 }
  _R3 = 129;
  __asm { vcmpgtub  v13, v18, v0 }
  _R5 = 144;
  __asm { vcmpgtub  v12, v16, v0 }
  _R31 = 176;
  __asm
  {
    vand128   v10, v19, v62
    lvlx      v17, r4, r11
    vand128   v9, v19, v61
    lvlx      v14, r3, r11
    vspltb    v15, v17, 0
  }
  _R4 = 145;
  __asm { vspltb    v11, v14, 0 }
  _R3 = 160;
  __asm
  {
    vcmpgtub  v8, v10, v0
    lvlx      v29, r5, r11
    vcmpgtub  v7, v9, v0
  }
  _R5 = 161;
  __asm
  {
    vand128   v6, v15, v62
    lvlx      v22, r31, r11
    vand128   v5, v15, v61
    lvlx      v27, r4, r11
    vand128   v4, v11, v62
    vspltb    v28, v29, 0
    vand128   v3, v11, v61
  }
  _R4 = 177;
  __asm
  {
    vcmpgtub  v2, v6, v0
    lvlx      v24, r5, r11
    vcmpgtub  v1, v5, v0
    vspltb    v26, v27, 0
    lvx128    v41, r0, r8
    vcmpgtub  v31, v4, v0
    vand128   v40, v73, v63
    vcmpgtub  v30, v3, v0
    vor128    v39, v72, v25
    lvlx      v25, r3, r11
    vspltb    v23, v25, 0
    stvx128   v39, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v38, r0, r6
    vand128   v37, v70, v63
    vor128    v36, v69, v20
    stvx128   v36, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v35, r0, r10
    vand128   v34, v67, v63
    vor128    v33, v66, v13
    stvx128   v33, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v32, r0, r9
    vand128   v60, v64, v63
    vor128    v59, v92, v12
    stvx128   v59, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v58, r0, r8
    vand128   v57, v90, v63
    vor128    v56, v89, v8
    stvx128   v56, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v55, r0, r6
    vand128   v54, v87, v63
    vor128    v53, v86, v7
    stvx128   v53, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v52, r0, r10
    vand128   v51, v84, v63
    vor128    v50, v83, v2
    stvx128   v50, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v49, r0, r9
    vand128   v48, v81, v63
    vor128    v47, v80, v1
    stvx128   v47, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v46, r0, r8
    vand128   v21, v28, v62
    vand128   v45, v78, v63
    vspltb    v20, v24, 0
    vand128   v19, v28, v61
    vspltb    v18, v22, 0
    vand128   v15, v26, v62
  }
  _R3 = 192;
  __asm
  {
    vcmpgtub  v17, v21, v0
    lvlx      v1, r4, r11
    vor128    v44, v77, v31
  }
  _R5 = 193;
  __asm
  {
    vcmpgtub  v16, v19, v0
    vcmpgtub  v11, v15, v0
    vand128   v14, v26, v61
    lvlx      v29, r3, r11
    stvx128   v44, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v43, r0, r6
    vand128   v42, v75, v63
    vor128    v41, v74, v30
    vspltb    v30, v1, 0
    vcmpgtub  v10, v14, v0
    vspltb    v27, v29, 0
    vand128   v13, v23, v62
    vand128   v12, v23, v61
    stvx128   v41, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    vand128   v7, v20, v62
    vcmpgtub  v9, v13, v0
    vcmpgtub  v8, v12, v0
    vand128   v6, v20, v61
    vcmpgtub  v5, v7, v0
    vand128   v3, v18, v62
    vand128   v31, v18, v61
    vcmpgtub  v4, v6, v0
    vcmpgtub  v2, v3, v0
    vcmpgtub  v28, v31, v0
    lvx128    v40, r0, r10
    vand128   v39, v72, v63
    vor128    v38, v71, v17
    stvx128   v38, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v37, r0, r9
    vand128   v36, v69, v63
    vor128    v35, v68, v16
    stvx128   v35, r0, r9
  }
  _R9 = (int)(_R10 + 16);
  __asm
  {
    lvx128    v34, r0, r8
    vand128   v33, v66, v63
    vor128    v32, v65, v11
    stvx128   v32, r0, r8
  }
  _R8 = (int)(_R10 + 32);
  __asm
  {
    lvx128    v60, r0, r6
    vand128   v59, v92, v63
    vor128    v58, v91, v10
    stvx128   v58, r0, r6
  }
  _R6 = (int)(_R10 + 48);
  __asm
  {
    lvx128    v57, r0, r10
    vand128   v56, v89, v63
    vor128    v55, v88, v9
    stvx128   v55, r0, r10
  }
  _R10 = (int)&_R10[byteStride];
  __asm
  {
    lvx128    v54, r0, r9
    vand128   v53, v86, v63
    vor128    v52, v85, v8
    stvx128   v52, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v51, r0, r8
    vand128   v50, v83, v63
    vor128    v49, v82, v5
    stvx128   v49, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v48, r0, r6
    vand128   v47, v80, v63
    vor128    v46, v79, v4
    stvx128   v46, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v45, r0, r10
    vand128   v44, v77, v63
    vor128    v43, v76, v2
    stvx128   v43, r0, r10
    vand128   v26, v30, v62
    vand128   v24, v30, v61
  }
  _R10 = _R10 + byteStride;
  __asm
  {
    vand128   v17, v27, v62
    lvlx      v25, r5, r11
    vand128   v15, v27, v61
  }
  _R4 = 208;
  __asm
  {
    vcmpgtub  v21, v26, v0
    vspltb    v23, v25, 0
    vcmpgtub  v19, v24, v0
  }
  _R3 = 209;
  __asm { vcmpgtub  v14, v17, v0 }
  _R5 = 224;
  __asm
  {
    vcmpgtub  v13, v15, v0
    vand128   v12, v23, v62
    lvlx      v22, r4, r11
    vand128   v11, v23, v61
  }
  _R4 = 225;
  __asm
  {
    vspltb    v18, v22, 0
    lvlx      v20, r3, r11
  }
  _R3 = 240;
  __asm
  {
    lvlx      v3, r5, r11
    vcmpgtub  v9, v12, v0
    vspltb    v16, v20, 0
    vcmpgtub  v8, v11, v0
  }
  _R5 = 241;
  __asm
  {
    vand128   v10, v18, v62
    lvlx      v29, r4, r11
    vand128   v6, v18, v61
    vspltb    v31, v3, 0
    vand128   v5, v16, v62
    vspltb    v27, v29, 0
    vand128   v4, v16, v61
    vcmpgtub  v7, v10, v0
    lvlx      v26, r5, r11
    vcmpgtub  v2, v6, v0
    lvx128    v42, r0, r9
    vcmpgtub  v1, v5, v0
    vand128   v41, v74, v63
    vcmpgtub  v30, v4, v0
    vor128    v40, v73, v28
    lvlx      v28, r3, r11
    vspltb    v25, v28, 0
    stvx128   v40, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v39, r0, r8
    vand128   v38, v71, v63
    vor128    v37, v70, v21
    stvx128   v37, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v36, r0, r6
    vand128   v35, v68, v63
    vor128    v34, v67, v19
    stvx128   v34, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v33, r0, r10
    vand128   v32, v65, v63
    vor128    v60, v64, v14
    stvx128   v60, r0, r10
  }
  _R10 = _R10 + byteStride;
  _R11 = _R10 + byteStride;
  __asm
  {
    lvx128    v59, r0, r9
    vand128   v58, v91, v63
    vor128    v57, v90, v13
    stvx128   v57, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v56, r0, r8
    vand128   v55, v88, v63
    vor128    v54, v87, v9
    stvx128   v54, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v53, r0, r6
    vand128   v52, v85, v63
    vor128    v51, v84, v8
    stvx128   v51, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v50, r0, r10
    vand128   v49, v82, v63
    vor128    v48, v81, v7
    stvx128   v48, r0, r10
    lvx128    v47, r0, r9
    vand128   v23, v31, v62
    vand128   v46, v79, v63
  }
  __asm
  {
    vand128   v22, v31, v61
    vspltb    v24, v26, 0
    vand128   v21, v27, v62
    vcmpgtub  v20, v23, v0
    vor128    v45, v78, v2
    vcmpgtub  v19, v22, v0
    vcmpgtub  v17, v21, v0
    vand128   v18, v27, v61
    stvx128   v45, r0, r9
  }
  _R9 = _R10 + byteStride + 32;
  __asm
  {
    lvx128    v44, r0, r8
    vand128   v43, v76, v63
    vor128    v42, v75, v1
    vcmpgtub  v14, v18, v0
    vand128   v16, v25, v62
    vand128   v15, v25, v61
    stvx128   v42, r0, r8
  }
  _R8 = _R10 + byteStride + 48;
  __asm
  {
    lvx128    v41, r0, r6
    vand128   v40, v73, v63
    vor128    v39, v72, v30
    vcmpgtub  v13, v16, v0
    vcmpgtub  v12, v15, v0
    vand128   v11, v24, v62
    stvx128   v39, r0, r6
    vand128   v9, v24, v61
    lvx128    v38, r0, r11
    vand128   v37, v70, v63
    vor128    v36, v69, v20
    vcmpgtub  v10, v11, v0
    vcmpgtub  v8, v9, v0
    stvx128   v36, r0, r11
  }
  _R11 = _R10 + byteStride + byteStride;
  _R10 = _R10 + byteStride + 16;
  __asm
  {
    lvx128    v35, r0, r10
    vand128   v34, v67, v63
    vor128    v33, v66, v19
    stvx128   v33, r0, r10
  }
  _R10 = _R11 + 16;
  __asm
  {
    lvx128    v32, r0, r9
    vand128   v60, v64, v63
    vor128    v59, v92, v17
    stvx128   v59, r0, r9
  }
  _R9 = _R11 + 32;
  __asm
  {
    lvx128    v58, r0, r8
    vand128   v57, v90, v63
    vor128    v56, v89, v14
    stvx128   v56, r0, r8
  }
  _R8 = _R11 + 48;
  __asm
  {
    lvx128    v55, r0, r11
    vand128   v54, v87, v63
    vor128    v53, v86, v13
    stvx128   v53, r0, r11
    lvx128    v52, r0, r10
    vand128   v51, v84, v63
    vor128    v50, v83, v12
    stvx128   v50, r0, r10
    lvx128    v49, r0, r9
    vand128   v48, v81, v63
    vor128    v47, v80, v10
    stvx128   v47, r0, r9
    lvx128    v46, r0, r8
    vand128   v45, v78, v63
    vor128    v44, v77, v8
    stvx128   v44, r0, r8
  }
}


// ========================================================================
// ConstantScaleSpecular16x16_0
// EA  : 0x82930418
// RVA : 0x00930418
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall ConstantScaleSpecular16x16_0(
        unsigned __int8 *specularScale,
        int tileX,
        int tileY,
        unsigned __int8 *rgba,
        unsigned __int8 specularShift,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        unsigned __int8 a20)
{
  int v24; // ctr
  unsigned __int8 *v34; // r11
  int v35; // r7

  _R9 = &a20;
  a20 = specularShift;
  _R8 = vmxi_word_specular_shift_mask_0;
  _R11 = rgba + 32;
  __asm
  {
    lvlx      v0, r0, r9
    vspltb    v13, v0, 0
    lvx128    v63, r0, r8
  }
  v24 = 8;
  _R30 = -32;
  __asm { vand128   v0, v13, v63 }
  _R29 = -32;
  _R28 = -16;
  _R27 = -16;
  _R31 = 16;
  _R6 = 32;
  _R8 = 48;
  _R9 = 64;
  _R10 = 80;
  do
  {
    __asm
    {
      lvx128    v13, r11, r30
      lvx128    v12, r11, r28
      vslb      v11, v13, v0
      lvx128    v10, r0, r11
      vslb      v9, v12, v0
      lvx128    v8, r11, r31
      vslb      v7, v10, v0
      lvx128    v6, r11, r6
      vslb      v5, v8, v0
      lvx128    v4, r11, r8
      vslb      v3, v6, v0
      lvx128    v2, r11, r9
      vslb      v1, v4, v0
      lvx128    v31, r11, r10
      vslb      v30, v2, v0
      vslb      v29, v31, v0
      stvx128   v11, r11, r29
      stvx128   v9, r11, r27
      stvx128   v7, r0, r11
      stvx128   v5, r11, r31
      stvx128   v3, r11, r6
      stvx128   v1, r11, r8
      stvx128   v30, r11, r9
      stvx128   v29, r11, r10
    }
    _R11 += 128;
    --v24;
  }
  while ( v24 != 0 );
  v34 = &specularScale[4 * tileX + (tileY << 9 >> 2)];
  v35 = (((((((8 * ((1 << specularShift) + 255)) & 0xF8) << 8) | (8 * ((1 << specularShift) + 255)) & 0xF8) << 8)
        | (8 * ((1 << specularShift) + 255)) & 0xF8) << 8)
      | (8 * ((1 << specularShift) + 255)) & 0xF8;
  *(_DWORD *)v34 = v35;
  *((_DWORD *)v34 + 8) = v35;
  *((_DWORD *)v34 + 16) = v35;
  *((_DWORD *)v34 + 24) = v35;
}


// ========================================================================
// DynamicScaleSpecular16x16_0
// EA  : 0x82930530
// RVA : 0x00930530
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall DynamicScaleSpecular16x16_0(
        unsigned __int8 *specularScale,
        int tileX,
        int tileY,
        unsigned __int8 *rgba)
{
  int v8; // r25
  unsigned int v9; // r27
  unsigned int v10; // r26
  int i; // ctr

  __asm { vspltisb  v30, 2 }
  _R10 = 16;
  __asm { vspltisb  v12, 8 }
  _R9 = vmxi_byte_63_0;
  _R8 = 32;
  v8 = 4 * tileX;
  v9 = 0;
  v10 = tileY << 9;
  __asm
  {
    lvx128    v3, r0, r9
    lvx128    v2, r9, r10
    lvx128    v63, r9, r8
  }
  do
  {
    _R10 = 0;
    _R29 = &specularScale[(v10 >> 2) + v8];
    _R28 = _R29 + 1;
    for ( i = 2; i != 0; --i )
    {
      _R11 = &rgba[16 * v9 + 16 * _R10];
      _R9 = _R11 + 64;
      _R8 = _R11 + 128;
      _R7 = _R11 + 192;
      _R5 = _R11 + 16;
      __asm { lvx128    v11, r0, r11 }
      _R4 = _R11 + 80;
      _R31 = _R11 + 144;
      __asm { lvx128    v10, r0, r9 }
      _R30 = _R11 + 208;
      __asm
      {
        lvx128    v9, r0, r8
        lvx128    v8, r0, r7
        vmaxub    v0, v11, v10
        lvx128    v7, r0, r5
        vmaxub    v13, v9, v8
        lvx128    v6, r0, r4
        lvx128    v5, r0, r31
        vmaxub    v1, v7, v6
        lvx128    v4, r0, r30
        vmaxub    v31, v5, v4
        vmaxub    v0, v0, v13
        vmaxub    v13, v1, v31
        vsldoi    v29, v0, v0, v8
        vsldoi    v28, v13, v13, v8
        vmaxub    v0, v0, v29
        vmaxub    v13, v13, v28
        vsldoi    v27, v0, v0, v4
        vsldoi    v26, v13, v13, v4
        vmaxub    v0, v0, v27
        vmaxub    v13, v13, v26
        vsldoi    v25, v0, v0, v15
        vsldoi    v24, v13, v13, v15
        vmaxub    v0, v0, v25
        vmaxub    v13, v13, v24
        vsldoi    v23, v0, v0, v15
        vsldoi    v22, v13, v13, v15
        vmaxub    v21, v0, v23
        vmaxub    v20, v13, v22
        vspltb    v0, v21, 2
        vspltb    v13, v20, 2
        vcmpgtub  v19, v0, v3
        vcmpgtub  v18, v0, v2
        vcmpgtub  v17, v13, v3
        vcmpgtub  v16, v13, v2
        vaddsbs   v15, v30, v19
        vaddsbs   v14, v30, v17
        vaddsbs   v0, v15, v18
        vaddsbs   v13, v14, v16
        vslb      v1, v12, v0
        vand128   v0, v0, v63
        vslb      v31, v12, v13
        vand128   v13, v13, v63
        vsububs   v1, v1, v12
        vslb      v29, v11, v0
        vslb      v28, v10, v0
        vslb      v27, v9, v0
        vslb      v26, v8, v0
        vslb      v25, v7, v13
        stvx128   v29, r0, r11
        vslb      v24, v6, v13
        stvx128   v28, r0, r9
        vslb      v23, v5, v13
        stvx128   v27, r0, r8
        vslb      v22, v4, v13
        stvx128   v26, r0, r7
        vsububs   v21, v31, v12
        stvx128   v25, r0, r5
        stvx128   v24, r0, r4
        stvx128   v23, r0, r31
        stvx128   v22, r0, r30
        stvebx    v1, r29, r10
        stvebx    v21, r28, r10
      }
      _R10 += 2;
    }
    v9 += 16;
    v10 += 128;
  }
  while ( v9 < 0x40 );
}


// ========================================================================
// DecompressCover16x16_1
// EA  : 0x82932658
// RVA : 0x00932658
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall DecompressCover16x16_1(
        const unsigned __int8 *cover,
        int tileX,
        int tileY,
        unsigned __int8 *rgba,
        int byteStride)
{
  int v6; // r11

  __asm { vspltisb  v0, 0 }
  __asm { lvx128    v61, r0, r6 }
  v6 = (tileY << 7) + tileX;
  _R5 = vmxi_word_cover_mask2_1;
  _R4 = -32;
  _R11 = &cover[(2 * v6) & 0x1FFFFFFE];
  _R3 = 1;
  _R10 = 16;
  __asm { lvx128    v63, r0, r5 }
  _R31 = -16;
  __asm
  {
    vand128   v60, v93, v63
    lvx128    v62, r5, r4
  }
  _R9 = rgba + 16;
  __asm { lvlx      v13, r0, r11 }
  _R8 = rgba + 32;
  __asm { lvlx      v11, r3, r11 }
  _R4 = 17;
  __asm
  {
    vspltb    v12, v13, 0
    lvlx      v10, r10, r11
    lvx128    v61, r5, r31
    vspltb    v9, v11, 0
    vspltb    v8, v10, 0
    lvx128    v59, r0, r9
  }
  _R5 = rgba + 48;
  __asm
  {
    vand128   v58, v91, v63
    vand128   v7, v12, v62
    lvx128    v57, r0, r8
    vand128   v6, v12, v61
  }
  __asm
  {
    vand128   v5, v9, v62
    lvlx      v4, r4, r11
    vand128   v31, v9, v61
  }
  _R3 = 32;
  __asm
  {
    vcmpgtub  v3, v7, v0
    lvx128    v56, r0, r5
    vcmpgtub  v2, v6, v0
    vspltb    v1, v4, 0
    vand128   v29, v8, v62
    vand128   v53, v89, v63
    vor128    v55, v92, v3
    lvlx      v30, r3, r11
    vor128    v54, v90, v2
    vand128   v52, v88, v63
    vspltb    v28, v30, 0
    vcmpgtub  v27, v5, v0
    stvx128   v55, r0, r6
    vcmpgtub  v26, v31, v0
    lvx128    v51, r6, r7
    vcmpgtub  v25, v29, v0
    vand128   v50, v83, v63
    stvx128   v54, r0, r9
  }
  _R9 = &rgba[byteStride + 16];
  __asm
  {
    vor128    v49, v85, v27
    vor128    v48, v84, v26
    vor128    v47, v82, v25
    vand128   v24, v8, v61
    stvx128   v49, r0, r8
  }
  _R8 = &rgba[byteStride + 32];
  __asm
  {
    stvx128   v48, r0, r5
    vand128   v22, v1, v62
    stvx128   v47, r6, r7
  }
  __asm
  {
    lvx128    v46, r0, r9
    vcmpgtub  v23, v24, v0
    vand128   v45, v78, v63
  }
  _R10 = &rgba[byteStride + byteStride];
  _R6 = &rgba[byteStride + 48];
  __asm
  {
    vor128    v44, v77, v23
    vcmpgtub  v20, v22, v0
    vand128   v21, v1, v61
    vand128   v18, v28, v62
    stvx128   v44, r0, r9
    lvx128    v43, r0, r8
    vand128   v42, v75, v63
    vor128    v41, v74, v20
    vcmpgtub  v19, v21, v0
    stvx128   v41, r0, r8
    lvx128    v40, r0, r6
    vand128   v39, v72, v63
    vor128    v38, v71, v19
  }
  _R9 = _R10 + 16;
  __asm { vcmpgtub  v16, v18, v0 }
  _R5 = 33;
  __asm { vand128   v17, v28, v61 }
  _R8 = _R10 + 32;
  _R4 = 48;
  __asm { stvx128   v38, r0, r6 }
  _R6 = _R10 + 48;
  _R3 = 49;
  __asm
  {
    lvlx      v15, r5, r11
    vcmpgtub  v14, v17, v0
  }
  _R5 = 64;
  __asm
  {
    vspltb    v13, v15, 0
    lvlx      v12, r4, r11
  }
  _R31 = 65;
  __asm
  {
    vspltb    v10, v12, 0
    lvlx      v11, r3, r11
  }
  _R4 = 80;
  __asm
  {
    vand128   v5, v13, v62
    vspltb    v8, v11, 0
    vand128   v3, v13, v61
    lvlx      v9, r5, r11
    vand128   v31, v10, v62
    lvlx      v7, r31, r11
    vand128   v30, v10, v61
    vspltb    v6, v9, 0
    vcmpgtub  v2, v5, v0
    vspltb    v4, v7, 0
    vcmpgtub  v1, v3, v0
  }
  _R3 = 81;
  __asm { vcmpgtub  v29, v31, v0 }
  _R5 = 96;
  __asm
  {
    vcmpgtub  v28, v30, v0
    vand128   v27, v8, v62
    vand128   v25, v8, v61
    vand128   v24, v6, v62
    vand128   v21, v6, v61
    lvx128    v37, r0, r10
    vcmpgtub  v26, v27, v0
    vand128   v36, v69, v63
    vcmpgtub  v23, v25, v0
    vcmpgtub  v22, v24, v0
    vand128   v20, v4, v62
    vor128    v35, v68, v16
    vand128   v19, v4, v61
    stvx128   v35, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v34, r0, r9
    vand128   v33, v66, v63
    vor128    v32, v65, v14
    stvx128   v32, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v60, r0, r8
    vand128   v59, v92, v63
    vor128    v58, v91, v2
    stvx128   v58, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v57, r0, r6
    vand128   v56, v89, v63
    vor128    v55, v88, v1
    stvx128   v55, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v54, r0, r10
    vand128   v53, v86, v63
    vor128    v52, v85, v29
    stvx128   v52, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v51, r0, r9
    vand128   v50, v83, v63
    vor128    v49, v82, v28
    stvx128   v49, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v48, r0, r8
    vand128   v47, v80, v63
    vor128    v46, v79, v26
    stvx128   v46, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v45, r0, r6
    vand128   v44, v77, v63
    vor128    v43, v76, v23
    stvx128   v43, r0, r6
    vcmpgtub  v17, v21, v0
    lvx128    v42, r0, r10
    vand128   v41, v74, v63
    vor128    v40, v73, v22
  }
  _R6 = _R10 + 48;
  __asm
  {
    vcmpgtub  v15, v20, v0
    lvlx      v18, r4, r11
    vcmpgtub  v13, v19, v0
    lvlx      v16, r3, r11
    vspltb    v14, v18, 0
    lvlx      v11, r5, r11
    stvx128   v40, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v39, r0, r9
    vand128   v38, v71, v63
    vor128    v37, v70, v17
    vspltb    v12, v16, 0
    vand128   v8, v14, v62
    vspltb    v10, v11, 0
    vand128   v7, v14, v61
  }
  _R4 = 97;
  _R3 = 112;
  __asm { stvx128   v37, r0, r9 }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v36, r0, r8
    vand128   v35, v68, v63
    vor128    v34, v67, v15
    lvlx      v9, r4, r11
    vcmpgtub  v4, v8, v0
    lvlx      v24, r3, r11
    vcmpgtub  v3, v7, v0
    vspltb    v6, v9, 0
    vand128   v5, v12, v62
    vspltb    v22, v24, 0
    stvx128   v34, r0, r8
  }
  _R8 = _R10 + 32;
  __asm { vand128   v1, v12, v61 }
  _R5 = 113;
  __asm
  {
    vand128   v30, v10, v62
    vcmpgtub  v2, v5, v0
    vand128   v29, v10, v61
    vcmpgtub  v31, v1, v0
    vcmpgtub  v28, v30, v0
    vand128   v26, v6, v62
    vcmpgtub  v27, v29, v0
    vand128   v23, v6, v61
    vcmpgtub  v25, v26, v0
    lvx128    v33, r0, r6
    vand128   v32, v65, v63
    vor128    v60, v64, v13
    stvx128   v60, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v59, r0, r10
    vand128   v58, v91, v63
    vor128    v57, v90, v4
    stvx128   v57, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v56, r0, r9
    vand128   v55, v88, v63
    vor128    v54, v87, v3
    stvx128   v54, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v53, r0, r8
    vand128   v52, v85, v63
    vor128    v51, v84, v2
    stvx128   v51, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v50, r0, r6
    vand128   v49, v82, v63
    vor128    v48, v81, v31
    stvx128   v48, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v47, r0, r10
    vand128   v46, v79, v63
    vor128    v45, v78, v28
    stvx128   v45, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v44, r0, r9
    vand128   v43, v76, v63
    vor128    v42, v75, v27
    stvx128   v42, r0, r9
    vcmpgtub  v20, v23, v0
    vand128   v18, v22, v62
  }
  _R9 = _R10 + 16;
  __asm
  {
    vand128   v16, v22, v61
    lvlx      v21, r5, r11
  }
  _R4 = 128;
  __asm { vspltb    v19, v21, 0 }
  _R3 = 129;
  __asm { vcmpgtub  v13, v18, v0 }
  _R5 = 144;
  __asm { vcmpgtub  v12, v16, v0 }
  _R31 = 176;
  __asm
  {
    vand128   v10, v19, v62
    lvlx      v17, r4, r11
    vand128   v9, v19, v61
    lvlx      v14, r3, r11
    vspltb    v15, v17, 0
  }
  _R4 = 145;
  __asm { vspltb    v11, v14, 0 }
  _R3 = 160;
  __asm
  {
    vcmpgtub  v8, v10, v0
    lvlx      v29, r5, r11
    vcmpgtub  v7, v9, v0
  }
  _R5 = 161;
  __asm
  {
    vand128   v6, v15, v62
    lvlx      v22, r31, r11
    vand128   v5, v15, v61
    lvlx      v27, r4, r11
    vand128   v4, v11, v62
    vspltb    v28, v29, 0
    vand128   v3, v11, v61
  }
  _R4 = 177;
  __asm
  {
    vcmpgtub  v2, v6, v0
    lvlx      v24, r5, r11
    vcmpgtub  v1, v5, v0
    vspltb    v26, v27, 0
    lvx128    v41, r0, r8
    vcmpgtub  v31, v4, v0
    vand128   v40, v73, v63
    vcmpgtub  v30, v3, v0
    vor128    v39, v72, v25
    lvlx      v25, r3, r11
    vspltb    v23, v25, 0
    stvx128   v39, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v38, r0, r6
    vand128   v37, v70, v63
    vor128    v36, v69, v20
    stvx128   v36, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v35, r0, r10
    vand128   v34, v67, v63
    vor128    v33, v66, v13
    stvx128   v33, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v32, r0, r9
    vand128   v60, v64, v63
    vor128    v59, v92, v12
    stvx128   v59, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v58, r0, r8
    vand128   v57, v90, v63
    vor128    v56, v89, v8
    stvx128   v56, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v55, r0, r6
    vand128   v54, v87, v63
    vor128    v53, v86, v7
    stvx128   v53, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v52, r0, r10
    vand128   v51, v84, v63
    vor128    v50, v83, v2
    stvx128   v50, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v49, r0, r9
    vand128   v48, v81, v63
    vor128    v47, v80, v1
    stvx128   v47, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v46, r0, r8
    vand128   v21, v28, v62
    vand128   v45, v78, v63
    vspltb    v20, v24, 0
    vand128   v19, v28, v61
    vspltb    v18, v22, 0
    vand128   v15, v26, v62
  }
  _R3 = 192;
  __asm
  {
    vcmpgtub  v17, v21, v0
    lvlx      v1, r4, r11
    vor128    v44, v77, v31
  }
  _R5 = 193;
  __asm
  {
    vcmpgtub  v16, v19, v0
    vcmpgtub  v11, v15, v0
    vand128   v14, v26, v61
    lvlx      v29, r3, r11
    stvx128   v44, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v43, r0, r6
    vand128   v42, v75, v63
    vor128    v41, v74, v30
    vspltb    v30, v1, 0
    vcmpgtub  v10, v14, v0
    vspltb    v27, v29, 0
    vand128   v13, v23, v62
    vand128   v12, v23, v61
    stvx128   v41, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    vand128   v7, v20, v62
    vcmpgtub  v9, v13, v0
    vcmpgtub  v8, v12, v0
    vand128   v6, v20, v61
    vcmpgtub  v5, v7, v0
    vand128   v3, v18, v62
    vand128   v31, v18, v61
    vcmpgtub  v4, v6, v0
    vcmpgtub  v2, v3, v0
    vcmpgtub  v28, v31, v0
    lvx128    v40, r0, r10
    vand128   v39, v72, v63
    vor128    v38, v71, v17
    stvx128   v38, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v37, r0, r9
    vand128   v36, v69, v63
    vor128    v35, v68, v16
    stvx128   v35, r0, r9
  }
  _R9 = (int)(_R10 + 16);
  __asm
  {
    lvx128    v34, r0, r8
    vand128   v33, v66, v63
    vor128    v32, v65, v11
    stvx128   v32, r0, r8
  }
  _R8 = (int)(_R10 + 32);
  __asm
  {
    lvx128    v60, r0, r6
    vand128   v59, v92, v63
    vor128    v58, v91, v10
    stvx128   v58, r0, r6
  }
  _R6 = (int)(_R10 + 48);
  __asm
  {
    lvx128    v57, r0, r10
    vand128   v56, v89, v63
    vor128    v55, v88, v9
    stvx128   v55, r0, r10
  }
  _R10 = (int)&_R10[byteStride];
  __asm
  {
    lvx128    v54, r0, r9
    vand128   v53, v86, v63
    vor128    v52, v85, v8
    stvx128   v52, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v51, r0, r8
    vand128   v50, v83, v63
    vor128    v49, v82, v5
    stvx128   v49, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v48, r0, r6
    vand128   v47, v80, v63
    vor128    v46, v79, v4
    stvx128   v46, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v45, r0, r10
    vand128   v44, v77, v63
    vor128    v43, v76, v2
    stvx128   v43, r0, r10
    vand128   v26, v30, v62
    vand128   v24, v30, v61
  }
  _R10 = _R10 + byteStride;
  __asm
  {
    vand128   v17, v27, v62
    lvlx      v25, r5, r11
    vand128   v15, v27, v61
  }
  _R4 = 208;
  __asm
  {
    vcmpgtub  v21, v26, v0
    vspltb    v23, v25, 0
    vcmpgtub  v19, v24, v0
  }
  _R3 = 209;
  __asm { vcmpgtub  v14, v17, v0 }
  _R5 = 224;
  __asm
  {
    vcmpgtub  v13, v15, v0
    vand128   v12, v23, v62
    lvlx      v22, r4, r11
    vand128   v11, v23, v61
  }
  _R4 = 225;
  __asm
  {
    vspltb    v18, v22, 0
    lvlx      v20, r3, r11
  }
  _R3 = 240;
  __asm
  {
    lvlx      v3, r5, r11
    vcmpgtub  v9, v12, v0
    vspltb    v16, v20, 0
    vcmpgtub  v8, v11, v0
  }
  _R5 = 241;
  __asm
  {
    vand128   v10, v18, v62
    lvlx      v29, r4, r11
    vand128   v6, v18, v61
    vspltb    v31, v3, 0
    vand128   v5, v16, v62
    vspltb    v27, v29, 0
    vand128   v4, v16, v61
    vcmpgtub  v7, v10, v0
    lvlx      v26, r5, r11
    vcmpgtub  v2, v6, v0
    lvx128    v42, r0, r9
    vcmpgtub  v1, v5, v0
    vand128   v41, v74, v63
    vcmpgtub  v30, v4, v0
    vor128    v40, v73, v28
    lvlx      v28, r3, r11
    vspltb    v25, v28, 0
    stvx128   v40, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v39, r0, r8
    vand128   v38, v71, v63
    vor128    v37, v70, v21
    stvx128   v37, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v36, r0, r6
    vand128   v35, v68, v63
    vor128    v34, v67, v19
    stvx128   v34, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v33, r0, r10
    vand128   v32, v65, v63
    vor128    v60, v64, v14
    stvx128   v60, r0, r10
  }
  _R10 = _R10 + byteStride;
  _R11 = _R10 + byteStride;
  __asm
  {
    lvx128    v59, r0, r9
    vand128   v58, v91, v63
    vor128    v57, v90, v13
    stvx128   v57, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v56, r0, r8
    vand128   v55, v88, v63
    vor128    v54, v87, v9
    stvx128   v54, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v53, r0, r6
    vand128   v52, v85, v63
    vor128    v51, v84, v8
    stvx128   v51, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v50, r0, r10
    vand128   v49, v82, v63
    vor128    v48, v81, v7
    stvx128   v48, r0, r10
    lvx128    v47, r0, r9
    vand128   v23, v31, v62
    vand128   v46, v79, v63
  }
  __asm
  {
    vand128   v22, v31, v61
    vspltb    v24, v26, 0
    vand128   v21, v27, v62
    vcmpgtub  v20, v23, v0
    vor128    v45, v78, v2
    vcmpgtub  v19, v22, v0
    vcmpgtub  v17, v21, v0
    vand128   v18, v27, v61
    stvx128   v45, r0, r9
  }
  _R9 = _R10 + byteStride + 32;
  __asm
  {
    lvx128    v44, r0, r8
    vand128   v43, v76, v63
    vor128    v42, v75, v1
    vcmpgtub  v14, v18, v0
    vand128   v16, v25, v62
    vand128   v15, v25, v61
    stvx128   v42, r0, r8
  }
  _R8 = _R10 + byteStride + 48;
  __asm
  {
    lvx128    v41, r0, r6
    vand128   v40, v73, v63
    vor128    v39, v72, v30
    vcmpgtub  v13, v16, v0
    vcmpgtub  v12, v15, v0
    vand128   v11, v24, v62
    stvx128   v39, r0, r6
    vand128   v9, v24, v61
    lvx128    v38, r0, r11
    vand128   v37, v70, v63
    vor128    v36, v69, v20
    vcmpgtub  v10, v11, v0
    vcmpgtub  v8, v9, v0
    stvx128   v36, r0, r11
  }
  _R11 = _R10 + byteStride + byteStride;
  _R10 = _R10 + byteStride + 16;
  __asm
  {
    lvx128    v35, r0, r10
    vand128   v34, v67, v63
    vor128    v33, v66, v19
    stvx128   v33, r0, r10
  }
  _R10 = _R11 + 16;
  __asm
  {
    lvx128    v32, r0, r9
    vand128   v60, v64, v63
    vor128    v59, v92, v17
    stvx128   v59, r0, r9
  }
  _R9 = _R11 + 32;
  __asm
  {
    lvx128    v58, r0, r8
    vand128   v57, v90, v63
    vor128    v56, v89, v14
    stvx128   v56, r0, r8
  }
  _R8 = _R11 + 48;
  __asm
  {
    lvx128    v55, r0, r11
    vand128   v54, v87, v63
    vor128    v53, v86, v13
    stvx128   v53, r0, r11
    lvx128    v52, r0, r10
    vand128   v51, v84, v63
    vor128    v50, v83, v12
    stvx128   v50, r0, r10
    lvx128    v49, r0, r9
    vand128   v48, v81, v63
    vor128    v47, v80, v10
    stvx128   v47, r0, r9
    lvx128    v46, r0, r8
    vand128   v45, v78, v63
    vor128    v44, v77, v8
    stvx128   v44, r0, r8
  }
}


// ========================================================================
// ConstantScaleSpecular16x16_1
// EA  : 0x82932F10
// RVA : 0x00932F10
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall ConstantScaleSpecular16x16_1(
        unsigned __int8 *specularScale,
        int tileX,
        int tileY,
        unsigned __int8 *rgba,
        unsigned __int8 specularShift,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        unsigned __int8 a20)
{
  int v24; // ctr
  unsigned __int8 *v34; // r11
  int v35; // r7

  _R9 = &a20;
  a20 = specularShift;
  _R8 = vmxi_word_specular_shift_mask_1;
  _R11 = rgba + 32;
  __asm
  {
    lvlx      v0, r0, r9
    vspltb    v13, v0, 0
    lvx128    v63, r0, r8
  }
  v24 = 8;
  _R30 = -32;
  __asm { vand128   v0, v13, v63 }
  _R29 = -32;
  _R28 = -16;
  _R27 = -16;
  _R31 = 16;
  _R6 = 32;
  _R8 = 48;
  _R9 = 64;
  _R10 = 80;
  do
  {
    __asm
    {
      lvx128    v13, r11, r30
      lvx128    v12, r11, r28
      vslb      v11, v13, v0
      lvx128    v10, r0, r11
      vslb      v9, v12, v0
      lvx128    v8, r11, r31
      vslb      v7, v10, v0
      lvx128    v6, r11, r6
      vslb      v5, v8, v0
      lvx128    v4, r11, r8
      vslb      v3, v6, v0
      lvx128    v2, r11, r9
      vslb      v1, v4, v0
      lvx128    v31, r11, r10
      vslb      v30, v2, v0
      vslb      v29, v31, v0
      stvx128   v11, r11, r29
      stvx128   v9, r11, r27
      stvx128   v7, r0, r11
      stvx128   v5, r11, r31
      stvx128   v3, r11, r6
      stvx128   v1, r11, r8
      stvx128   v30, r11, r9
      stvx128   v29, r11, r10
    }
    _R11 += 128;
    --v24;
  }
  while ( v24 != 0 );
  v34 = &specularScale[4 * tileX + (tileY << 9 >> 2)];
  v35 = (((((((8 * ((1 << specularShift) + 255)) & 0xF8) << 8) | (8 * ((1 << specularShift) + 255)) & 0xF8) << 8)
        | (8 * ((1 << specularShift) + 255)) & 0xF8) << 8)
      | (8 * ((1 << specularShift) + 255)) & 0xF8;
  *(_DWORD *)v34 = v35;
  *((_DWORD *)v34 + 8) = v35;
  *((_DWORD *)v34 + 16) = v35;
  *((_DWORD *)v34 + 24) = v35;
}


// ========================================================================
// DynamicScaleSpecular16x16_1
// EA  : 0x82933028
// RVA : 0x00933028
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall DynamicScaleSpecular16x16_1(
        unsigned __int8 *specularScale,
        int tileX,
        int tileY,
        unsigned __int8 *rgba)
{
  int v8; // r25
  unsigned int v9; // r27
  unsigned int v10; // r26
  int i; // ctr

  __asm { vspltisb  v30, 2 }
  _R10 = 16;
  __asm { vspltisb  v12, 8 }
  _R9 = vmxi_byte_63_1;
  _R8 = 32;
  v8 = 4 * tileX;
  v9 = 0;
  v10 = tileY << 9;
  __asm
  {
    lvx128    v3, r0, r9
    lvx128    v2, r9, r10
    lvx128    v63, r9, r8
  }
  do
  {
    _R10 = 0;
    _R29 = &specularScale[(v10 >> 2) + v8];
    _R28 = _R29 + 1;
    for ( i = 2; i != 0; --i )
    {
      _R11 = &rgba[16 * v9 + 16 * _R10];
      _R9 = _R11 + 64;
      _R8 = _R11 + 128;
      _R7 = _R11 + 192;
      _R5 = _R11 + 16;
      __asm { lvx128    v11, r0, r11 }
      _R4 = _R11 + 80;
      _R31 = _R11 + 144;
      __asm { lvx128    v10, r0, r9 }
      _R30 = _R11 + 208;
      __asm
      {
        lvx128    v9, r0, r8
        lvx128    v8, r0, r7
        vmaxub    v0, v11, v10
        lvx128    v7, r0, r5
        vmaxub    v13, v9, v8
        lvx128    v6, r0, r4
        lvx128    v5, r0, r31
        vmaxub    v1, v7, v6
        lvx128    v4, r0, r30
        vmaxub    v31, v5, v4
        vmaxub    v0, v0, v13
        vmaxub    v13, v1, v31
        vsldoi    v29, v0, v0, v8
        vsldoi    v28, v13, v13, v8
        vmaxub    v0, v0, v29
        vmaxub    v13, v13, v28
        vsldoi    v27, v0, v0, v4
        vsldoi    v26, v13, v13, v4
        vmaxub    v0, v0, v27
        vmaxub    v13, v13, v26
        vsldoi    v25, v0, v0, v15
        vsldoi    v24, v13, v13, v15
        vmaxub    v0, v0, v25
        vmaxub    v13, v13, v24
        vsldoi    v23, v0, v0, v15
        vsldoi    v22, v13, v13, v15
        vmaxub    v21, v0, v23
        vmaxub    v20, v13, v22
        vspltb    v0, v21, 2
        vspltb    v13, v20, 2
        vcmpgtub  v19, v0, v3
        vcmpgtub  v18, v0, v2
        vcmpgtub  v17, v13, v3
        vcmpgtub  v16, v13, v2
        vaddsbs   v15, v30, v19
        vaddsbs   v14, v30, v17
        vaddsbs   v0, v15, v18
        vaddsbs   v13, v14, v16
        vslb      v1, v12, v0
        vand128   v0, v0, v63
        vslb      v31, v12, v13
        vand128   v13, v13, v63
        vsububs   v1, v1, v12
        vslb      v29, v11, v0
        vslb      v28, v10, v0
        vslb      v27, v9, v0
        vslb      v26, v8, v0
        vslb      v25, v7, v13
        stvx128   v29, r0, r11
        vslb      v24, v6, v13
        stvx128   v28, r0, r9
        vslb      v23, v5, v13
        stvx128   v27, r0, r8
        vslb      v22, v4, v13
        stvx128   v26, r0, r7
        vsububs   v21, v31, v12
        stvx128   v25, r0, r5
        stvx128   v24, r0, r4
        stvx128   v23, r0, r31
        stvx128   v22, r0, r30
        stvebx    v1, r29, r10
        stvebx    v21, r28, r10
      }
      _R10 += 2;
    }
    v9 += 16;
    v10 += 128;
  }
  while ( v9 < 0x40 );
}


// ========================================================================
// DecompressCover16x16_2
// EA  : 0x82933D78
// RVA : 0x00933D78
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall DecompressCover16x16_2(
        const unsigned __int8 *cover,
        int tileX,
        int tileY,
        unsigned __int8 *rgba,
        int byteStride)
{
  int v6; // r11

  __asm { vspltisb  v0, 0 }
  __asm { lvx128    v61, r0, r6 }
  v6 = (tileY << 7) + tileX;
  _R5 = vmxi_word_cover_mask2_2;
  _R4 = -32;
  _R11 = &cover[(2 * v6) & 0x1FFFFFFE];
  _R3 = 1;
  _R10 = 16;
  __asm { lvx128    v63, r0, r5 }
  _R31 = -16;
  __asm
  {
    vand128   v60, v93, v63
    lvx128    v62, r5, r4
  }
  _R9 = rgba + 16;
  __asm { lvlx      v13, r0, r11 }
  _R8 = rgba + 32;
  __asm { lvlx      v11, r3, r11 }
  _R4 = 17;
  __asm
  {
    vspltb    v12, v13, 0
    lvlx      v10, r10, r11
    lvx128    v61, r5, r31
    vspltb    v9, v11, 0
    vspltb    v8, v10, 0
    lvx128    v59, r0, r9
  }
  _R5 = rgba + 48;
  __asm
  {
    vand128   v58, v91, v63
    vand128   v7, v12, v62
    lvx128    v57, r0, r8
    vand128   v6, v12, v61
  }
  __asm
  {
    vand128   v5, v9, v62
    lvlx      v4, r4, r11
    vand128   v31, v9, v61
  }
  _R3 = 32;
  __asm
  {
    vcmpgtub  v3, v7, v0
    lvx128    v56, r0, r5
    vcmpgtub  v2, v6, v0
    vspltb    v1, v4, 0
    vand128   v29, v8, v62
    vand128   v53, v89, v63
    vor128    v55, v92, v3
    lvlx      v30, r3, r11
    vor128    v54, v90, v2
    vand128   v52, v88, v63
    vspltb    v28, v30, 0
    vcmpgtub  v27, v5, v0
    stvx128   v55, r0, r6
    vcmpgtub  v26, v31, v0
    lvx128    v51, r6, r7
    vcmpgtub  v25, v29, v0
    vand128   v50, v83, v63
    stvx128   v54, r0, r9
  }
  _R9 = &rgba[byteStride + 16];
  __asm
  {
    vor128    v49, v85, v27
    vor128    v48, v84, v26
    vor128    v47, v82, v25
    vand128   v24, v8, v61
    stvx128   v49, r0, r8
  }
  _R8 = &rgba[byteStride + 32];
  __asm
  {
    stvx128   v48, r0, r5
    vand128   v22, v1, v62
    stvx128   v47, r6, r7
  }
  __asm
  {
    lvx128    v46, r0, r9
    vcmpgtub  v23, v24, v0
    vand128   v45, v78, v63
  }
  _R10 = &rgba[byteStride + byteStride];
  _R6 = &rgba[byteStride + 48];
  __asm
  {
    vor128    v44, v77, v23
    vcmpgtub  v20, v22, v0
    vand128   v21, v1, v61
    vand128   v18, v28, v62
    stvx128   v44, r0, r9
    lvx128    v43, r0, r8
    vand128   v42, v75, v63
    vor128    v41, v74, v20
    vcmpgtub  v19, v21, v0
    stvx128   v41, r0, r8
    lvx128    v40, r0, r6
    vand128   v39, v72, v63
    vor128    v38, v71, v19
  }
  _R9 = _R10 + 16;
  __asm { vcmpgtub  v16, v18, v0 }
  _R5 = 33;
  __asm { vand128   v17, v28, v61 }
  _R8 = _R10 + 32;
  _R4 = 48;
  __asm { stvx128   v38, r0, r6 }
  _R6 = _R10 + 48;
  _R3 = 49;
  __asm
  {
    lvlx      v15, r5, r11
    vcmpgtub  v14, v17, v0
  }
  _R5 = 64;
  __asm
  {
    vspltb    v13, v15, 0
    lvlx      v12, r4, r11
  }
  _R31 = 65;
  __asm
  {
    vspltb    v10, v12, 0
    lvlx      v11, r3, r11
  }
  _R4 = 80;
  __asm
  {
    vand128   v5, v13, v62
    vspltb    v8, v11, 0
    vand128   v3, v13, v61
    lvlx      v9, r5, r11
    vand128   v31, v10, v62
    lvlx      v7, r31, r11
    vand128   v30, v10, v61
    vspltb    v6, v9, 0
    vcmpgtub  v2, v5, v0
    vspltb    v4, v7, 0
    vcmpgtub  v1, v3, v0
  }
  _R3 = 81;
  __asm { vcmpgtub  v29, v31, v0 }
  _R5 = 96;
  __asm
  {
    vcmpgtub  v28, v30, v0
    vand128   v27, v8, v62
    vand128   v25, v8, v61
    vand128   v24, v6, v62
    vand128   v21, v6, v61
    lvx128    v37, r0, r10
    vcmpgtub  v26, v27, v0
    vand128   v36, v69, v63
    vcmpgtub  v23, v25, v0
    vcmpgtub  v22, v24, v0
    vand128   v20, v4, v62
    vor128    v35, v68, v16
    vand128   v19, v4, v61
    stvx128   v35, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v34, r0, r9
    vand128   v33, v66, v63
    vor128    v32, v65, v14
    stvx128   v32, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v60, r0, r8
    vand128   v59, v92, v63
    vor128    v58, v91, v2
    stvx128   v58, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v57, r0, r6
    vand128   v56, v89, v63
    vor128    v55, v88, v1
    stvx128   v55, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v54, r0, r10
    vand128   v53, v86, v63
    vor128    v52, v85, v29
    stvx128   v52, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v51, r0, r9
    vand128   v50, v83, v63
    vor128    v49, v82, v28
    stvx128   v49, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v48, r0, r8
    vand128   v47, v80, v63
    vor128    v46, v79, v26
    stvx128   v46, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v45, r0, r6
    vand128   v44, v77, v63
    vor128    v43, v76, v23
    stvx128   v43, r0, r6
    vcmpgtub  v17, v21, v0
    lvx128    v42, r0, r10
    vand128   v41, v74, v63
    vor128    v40, v73, v22
  }
  _R6 = _R10 + 48;
  __asm
  {
    vcmpgtub  v15, v20, v0
    lvlx      v18, r4, r11
    vcmpgtub  v13, v19, v0
    lvlx      v16, r3, r11
    vspltb    v14, v18, 0
    lvlx      v11, r5, r11
    stvx128   v40, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v39, r0, r9
    vand128   v38, v71, v63
    vor128    v37, v70, v17
    vspltb    v12, v16, 0
    vand128   v8, v14, v62
    vspltb    v10, v11, 0
    vand128   v7, v14, v61
  }
  _R4 = 97;
  _R3 = 112;
  __asm { stvx128   v37, r0, r9 }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v36, r0, r8
    vand128   v35, v68, v63
    vor128    v34, v67, v15
    lvlx      v9, r4, r11
    vcmpgtub  v4, v8, v0
    lvlx      v24, r3, r11
    vcmpgtub  v3, v7, v0
    vspltb    v6, v9, 0
    vand128   v5, v12, v62
    vspltb    v22, v24, 0
    stvx128   v34, r0, r8
  }
  _R8 = _R10 + 32;
  __asm { vand128   v1, v12, v61 }
  _R5 = 113;
  __asm
  {
    vand128   v30, v10, v62
    vcmpgtub  v2, v5, v0
    vand128   v29, v10, v61
    vcmpgtub  v31, v1, v0
    vcmpgtub  v28, v30, v0
    vand128   v26, v6, v62
    vcmpgtub  v27, v29, v0
    vand128   v23, v6, v61
    vcmpgtub  v25, v26, v0
    lvx128    v33, r0, r6
    vand128   v32, v65, v63
    vor128    v60, v64, v13
    stvx128   v60, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v59, r0, r10
    vand128   v58, v91, v63
    vor128    v57, v90, v4
    stvx128   v57, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v56, r0, r9
    vand128   v55, v88, v63
    vor128    v54, v87, v3
    stvx128   v54, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v53, r0, r8
    vand128   v52, v85, v63
    vor128    v51, v84, v2
    stvx128   v51, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v50, r0, r6
    vand128   v49, v82, v63
    vor128    v48, v81, v31
    stvx128   v48, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v47, r0, r10
    vand128   v46, v79, v63
    vor128    v45, v78, v28
    stvx128   v45, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v44, r0, r9
    vand128   v43, v76, v63
    vor128    v42, v75, v27
    stvx128   v42, r0, r9
    vcmpgtub  v20, v23, v0
    vand128   v18, v22, v62
  }
  _R9 = _R10 + 16;
  __asm
  {
    vand128   v16, v22, v61
    lvlx      v21, r5, r11
  }
  _R4 = 128;
  __asm { vspltb    v19, v21, 0 }
  _R3 = 129;
  __asm { vcmpgtub  v13, v18, v0 }
  _R5 = 144;
  __asm { vcmpgtub  v12, v16, v0 }
  _R31 = 176;
  __asm
  {
    vand128   v10, v19, v62
    lvlx      v17, r4, r11
    vand128   v9, v19, v61
    lvlx      v14, r3, r11
    vspltb    v15, v17, 0
  }
  _R4 = 145;
  __asm { vspltb    v11, v14, 0 }
  _R3 = 160;
  __asm
  {
    vcmpgtub  v8, v10, v0
    lvlx      v29, r5, r11
    vcmpgtub  v7, v9, v0
  }
  _R5 = 161;
  __asm
  {
    vand128   v6, v15, v62
    lvlx      v22, r31, r11
    vand128   v5, v15, v61
    lvlx      v27, r4, r11
    vand128   v4, v11, v62
    vspltb    v28, v29, 0
    vand128   v3, v11, v61
  }
  _R4 = 177;
  __asm
  {
    vcmpgtub  v2, v6, v0
    lvlx      v24, r5, r11
    vcmpgtub  v1, v5, v0
    vspltb    v26, v27, 0
    lvx128    v41, r0, r8
    vcmpgtub  v31, v4, v0
    vand128   v40, v73, v63
    vcmpgtub  v30, v3, v0
    vor128    v39, v72, v25
    lvlx      v25, r3, r11
    vspltb    v23, v25, 0
    stvx128   v39, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v38, r0, r6
    vand128   v37, v70, v63
    vor128    v36, v69, v20
    stvx128   v36, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v35, r0, r10
    vand128   v34, v67, v63
    vor128    v33, v66, v13
    stvx128   v33, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v32, r0, r9
    vand128   v60, v64, v63
    vor128    v59, v92, v12
    stvx128   v59, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v58, r0, r8
    vand128   v57, v90, v63
    vor128    v56, v89, v8
    stvx128   v56, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v55, r0, r6
    vand128   v54, v87, v63
    vor128    v53, v86, v7
    stvx128   v53, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v52, r0, r10
    vand128   v51, v84, v63
    vor128    v50, v83, v2
    stvx128   v50, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v49, r0, r9
    vand128   v48, v81, v63
    vor128    v47, v80, v1
    stvx128   v47, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v46, r0, r8
    vand128   v21, v28, v62
    vand128   v45, v78, v63
    vspltb    v20, v24, 0
    vand128   v19, v28, v61
    vspltb    v18, v22, 0
    vand128   v15, v26, v62
  }
  _R3 = 192;
  __asm
  {
    vcmpgtub  v17, v21, v0
    lvlx      v1, r4, r11
    vor128    v44, v77, v31
  }
  _R5 = 193;
  __asm
  {
    vcmpgtub  v16, v19, v0
    vcmpgtub  v11, v15, v0
    vand128   v14, v26, v61
    lvlx      v29, r3, r11
    stvx128   v44, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v43, r0, r6
    vand128   v42, v75, v63
    vor128    v41, v74, v30
    vspltb    v30, v1, 0
    vcmpgtub  v10, v14, v0
    vspltb    v27, v29, 0
    vand128   v13, v23, v62
    vand128   v12, v23, v61
    stvx128   v41, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    vand128   v7, v20, v62
    vcmpgtub  v9, v13, v0
    vcmpgtub  v8, v12, v0
    vand128   v6, v20, v61
    vcmpgtub  v5, v7, v0
    vand128   v3, v18, v62
    vand128   v31, v18, v61
    vcmpgtub  v4, v6, v0
    vcmpgtub  v2, v3, v0
    vcmpgtub  v28, v31, v0
    lvx128    v40, r0, r10
    vand128   v39, v72, v63
    vor128    v38, v71, v17
    stvx128   v38, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v37, r0, r9
    vand128   v36, v69, v63
    vor128    v35, v68, v16
    stvx128   v35, r0, r9
  }
  _R9 = (int)(_R10 + 16);
  __asm
  {
    lvx128    v34, r0, r8
    vand128   v33, v66, v63
    vor128    v32, v65, v11
    stvx128   v32, r0, r8
  }
  _R8 = (int)(_R10 + 32);
  __asm
  {
    lvx128    v60, r0, r6
    vand128   v59, v92, v63
    vor128    v58, v91, v10
    stvx128   v58, r0, r6
  }
  _R6 = (int)(_R10 + 48);
  __asm
  {
    lvx128    v57, r0, r10
    vand128   v56, v89, v63
    vor128    v55, v88, v9
    stvx128   v55, r0, r10
  }
  _R10 = (int)&_R10[byteStride];
  __asm
  {
    lvx128    v54, r0, r9
    vand128   v53, v86, v63
    vor128    v52, v85, v8
    stvx128   v52, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v51, r0, r8
    vand128   v50, v83, v63
    vor128    v49, v82, v5
    stvx128   v49, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v48, r0, r6
    vand128   v47, v80, v63
    vor128    v46, v79, v4
    stvx128   v46, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v45, r0, r10
    vand128   v44, v77, v63
    vor128    v43, v76, v2
    stvx128   v43, r0, r10
    vand128   v26, v30, v62
    vand128   v24, v30, v61
  }
  _R10 = _R10 + byteStride;
  __asm
  {
    vand128   v17, v27, v62
    lvlx      v25, r5, r11
    vand128   v15, v27, v61
  }
  _R4 = 208;
  __asm
  {
    vcmpgtub  v21, v26, v0
    vspltb    v23, v25, 0
    vcmpgtub  v19, v24, v0
  }
  _R3 = 209;
  __asm { vcmpgtub  v14, v17, v0 }
  _R5 = 224;
  __asm
  {
    vcmpgtub  v13, v15, v0
    vand128   v12, v23, v62
    lvlx      v22, r4, r11
    vand128   v11, v23, v61
  }
  _R4 = 225;
  __asm
  {
    vspltb    v18, v22, 0
    lvlx      v20, r3, r11
  }
  _R3 = 240;
  __asm
  {
    lvlx      v3, r5, r11
    vcmpgtub  v9, v12, v0
    vspltb    v16, v20, 0
    vcmpgtub  v8, v11, v0
  }
  _R5 = 241;
  __asm
  {
    vand128   v10, v18, v62
    lvlx      v29, r4, r11
    vand128   v6, v18, v61
    vspltb    v31, v3, 0
    vand128   v5, v16, v62
    vspltb    v27, v29, 0
    vand128   v4, v16, v61
    vcmpgtub  v7, v10, v0
    lvlx      v26, r5, r11
    vcmpgtub  v2, v6, v0
    lvx128    v42, r0, r9
    vcmpgtub  v1, v5, v0
    vand128   v41, v74, v63
    vcmpgtub  v30, v4, v0
    vor128    v40, v73, v28
    lvlx      v28, r3, r11
    vspltb    v25, v28, 0
    stvx128   v40, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v39, r0, r8
    vand128   v38, v71, v63
    vor128    v37, v70, v21
    stvx128   v37, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v36, r0, r6
    vand128   v35, v68, v63
    vor128    v34, v67, v19
    stvx128   v34, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v33, r0, r10
    vand128   v32, v65, v63
    vor128    v60, v64, v14
    stvx128   v60, r0, r10
  }
  _R10 = _R10 + byteStride;
  _R11 = _R10 + byteStride;
  __asm
  {
    lvx128    v59, r0, r9
    vand128   v58, v91, v63
    vor128    v57, v90, v13
    stvx128   v57, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v56, r0, r8
    vand128   v55, v88, v63
    vor128    v54, v87, v9
    stvx128   v54, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v53, r0, r6
    vand128   v52, v85, v63
    vor128    v51, v84, v8
    stvx128   v51, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v50, r0, r10
    vand128   v49, v82, v63
    vor128    v48, v81, v7
    stvx128   v48, r0, r10
    lvx128    v47, r0, r9
    vand128   v23, v31, v62
    vand128   v46, v79, v63
  }
  __asm
  {
    vand128   v22, v31, v61
    vspltb    v24, v26, 0
    vand128   v21, v27, v62
    vcmpgtub  v20, v23, v0
    vor128    v45, v78, v2
    vcmpgtub  v19, v22, v0
    vcmpgtub  v17, v21, v0
    vand128   v18, v27, v61
    stvx128   v45, r0, r9
  }
  _R9 = _R10 + byteStride + 32;
  __asm
  {
    lvx128    v44, r0, r8
    vand128   v43, v76, v63
    vor128    v42, v75, v1
    vcmpgtub  v14, v18, v0
    vand128   v16, v25, v62
    vand128   v15, v25, v61
    stvx128   v42, r0, r8
  }
  _R8 = _R10 + byteStride + 48;
  __asm
  {
    lvx128    v41, r0, r6
    vand128   v40, v73, v63
    vor128    v39, v72, v30
    vcmpgtub  v13, v16, v0
    vcmpgtub  v12, v15, v0
    vand128   v11, v24, v62
    stvx128   v39, r0, r6
    vand128   v9, v24, v61
    lvx128    v38, r0, r11
    vand128   v37, v70, v63
    vor128    v36, v69, v20
    vcmpgtub  v10, v11, v0
    vcmpgtub  v8, v9, v0
    stvx128   v36, r0, r11
  }
  _R11 = _R10 + byteStride + byteStride;
  _R10 = _R10 + byteStride + 16;
  __asm
  {
    lvx128    v35, r0, r10
    vand128   v34, v67, v63
    vor128    v33, v66, v19
    stvx128   v33, r0, r10
  }
  _R10 = _R11 + 16;
  __asm
  {
    lvx128    v32, r0, r9
    vand128   v60, v64, v63
    vor128    v59, v92, v17
    stvx128   v59, r0, r9
  }
  _R9 = _R11 + 32;
  __asm
  {
    lvx128    v58, r0, r8
    vand128   v57, v90, v63
    vor128    v56, v89, v14
    stvx128   v56, r0, r8
  }
  _R8 = _R11 + 48;
  __asm
  {
    lvx128    v55, r0, r11
    vand128   v54, v87, v63
    vor128    v53, v86, v13
    stvx128   v53, r0, r11
    lvx128    v52, r0, r10
    vand128   v51, v84, v63
    vor128    v50, v83, v12
    stvx128   v50, r0, r10
    lvx128    v49, r0, r9
    vand128   v48, v81, v63
    vor128    v47, v80, v10
    stvx128   v47, r0, r9
    lvx128    v46, r0, r8
    vand128   v45, v78, v63
    vor128    v44, v77, v8
    stvx128   v44, r0, r8
  }
}


// ========================================================================
// ConstantScaleSpecular16x16_2
// EA  : 0x82934630
// RVA : 0x00934630
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall ConstantScaleSpecular16x16_2(
        unsigned __int8 *specularScale,
        int tileX,
        int tileY,
        unsigned __int8 *rgba,
        unsigned __int8 specularShift,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        unsigned __int8 a20)
{
  int v24; // ctr
  unsigned __int8 *v34; // r11
  int v35; // r7

  _R9 = &a20;
  a20 = specularShift;
  _R8 = vmxi_word_specular_shift_mask_2;
  _R11 = rgba + 32;
  __asm
  {
    lvlx      v0, r0, r9
    vspltb    v13, v0, 0
    lvx128    v63, r0, r8
  }
  v24 = 8;
  _R30 = -32;
  __asm { vand128   v0, v13, v63 }
  _R29 = -32;
  _R28 = -16;
  _R27 = -16;
  _R31 = 16;
  _R6 = 32;
  _R8 = 48;
  _R9 = 64;
  _R10 = 80;
  do
  {
    __asm
    {
      lvx128    v13, r11, r30
      lvx128    v12, r11, r28
      vslb      v11, v13, v0
      lvx128    v10, r0, r11
      vslb      v9, v12, v0
      lvx128    v8, r11, r31
      vslb      v7, v10, v0
      lvx128    v6, r11, r6
      vslb      v5, v8, v0
      lvx128    v4, r11, r8
      vslb      v3, v6, v0
      lvx128    v2, r11, r9
      vslb      v1, v4, v0
      lvx128    v31, r11, r10
      vslb      v30, v2, v0
      vslb      v29, v31, v0
      stvx128   v11, r11, r29
      stvx128   v9, r11, r27
      stvx128   v7, r0, r11
      stvx128   v5, r11, r31
      stvx128   v3, r11, r6
      stvx128   v1, r11, r8
      stvx128   v30, r11, r9
      stvx128   v29, r11, r10
    }
    _R11 += 128;
    --v24;
  }
  while ( v24 != 0 );
  v34 = &specularScale[4 * tileX + (tileY << 9 >> 2)];
  v35 = (((((((8 * ((1 << specularShift) + 255)) & 0xF8) << 8) | (8 * ((1 << specularShift) + 255)) & 0xF8) << 8)
        | (8 * ((1 << specularShift) + 255)) & 0xF8) << 8)
      | (8 * ((1 << specularShift) + 255)) & 0xF8;
  *(_DWORD *)v34 = v35;
  *((_DWORD *)v34 + 8) = v35;
  *((_DWORD *)v34 + 16) = v35;
  *((_DWORD *)v34 + 24) = v35;
}


// ========================================================================
// DynamicScaleSpecular16x16_2
// EA  : 0x82934748
// RVA : 0x00934748
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall DynamicScaleSpecular16x16_2(
        unsigned __int8 *specularScale,
        int tileX,
        int tileY,
        unsigned __int8 *rgba)
{
  int v8; // r25
  unsigned int v9; // r27
  unsigned int v10; // r26
  int i; // ctr

  __asm { vspltisb  v30, 2 }
  _R10 = 16;
  __asm { vspltisb  v12, 8 }
  _R9 = vmxi_byte_63_2;
  _R8 = 32;
  v8 = 4 * tileX;
  v9 = 0;
  v10 = tileY << 9;
  __asm
  {
    lvx128    v3, r0, r9
    lvx128    v2, r9, r10
    lvx128    v63, r9, r8
  }
  do
  {
    _R10 = 0;
    _R29 = &specularScale[(v10 >> 2) + v8];
    _R28 = _R29 + 1;
    for ( i = 2; i != 0; --i )
    {
      _R11 = &rgba[16 * v9 + 16 * _R10];
      _R9 = _R11 + 64;
      _R8 = _R11 + 128;
      _R7 = _R11 + 192;
      _R5 = _R11 + 16;
      __asm { lvx128    v11, r0, r11 }
      _R4 = _R11 + 80;
      _R31 = _R11 + 144;
      __asm { lvx128    v10, r0, r9 }
      _R30 = _R11 + 208;
      __asm
      {
        lvx128    v9, r0, r8
        lvx128    v8, r0, r7
        vmaxub    v0, v11, v10
        lvx128    v7, r0, r5
        vmaxub    v13, v9, v8
        lvx128    v6, r0, r4
        lvx128    v5, r0, r31
        vmaxub    v1, v7, v6
        lvx128    v4, r0, r30
        vmaxub    v31, v5, v4
        vmaxub    v0, v0, v13
        vmaxub    v13, v1, v31
        vsldoi    v29, v0, v0, v8
        vsldoi    v28, v13, v13, v8
        vmaxub    v0, v0, v29
        vmaxub    v13, v13, v28
        vsldoi    v27, v0, v0, v4
        vsldoi    v26, v13, v13, v4
        vmaxub    v0, v0, v27
        vmaxub    v13, v13, v26
        vsldoi    v25, v0, v0, v15
        vsldoi    v24, v13, v13, v15
        vmaxub    v0, v0, v25
        vmaxub    v13, v13, v24
        vsldoi    v23, v0, v0, v15
        vsldoi    v22, v13, v13, v15
        vmaxub    v21, v0, v23
        vmaxub    v20, v13, v22
        vspltb    v0, v21, 2
        vspltb    v13, v20, 2
        vcmpgtub  v19, v0, v3
        vcmpgtub  v18, v0, v2
        vcmpgtub  v17, v13, v3
        vcmpgtub  v16, v13, v2
        vaddsbs   v15, v30, v19
        vaddsbs   v14, v30, v17
        vaddsbs   v0, v15, v18
        vaddsbs   v13, v14, v16
        vslb      v1, v12, v0
        vand128   v0, v0, v63
        vslb      v31, v12, v13
        vand128   v13, v13, v63
        vsububs   v1, v1, v12
        vslb      v29, v11, v0
        vslb      v28, v10, v0
        vslb      v27, v9, v0
        vslb      v26, v8, v0
        vslb      v25, v7, v13
        stvx128   v29, r0, r11
        vslb      v24, v6, v13
        stvx128   v28, r0, r9
        vslb      v23, v5, v13
        stvx128   v27, r0, r8
        vslb      v22, v4, v13
        stvx128   v26, r0, r7
        vsububs   v21, v31, v12
        stvx128   v25, r0, r5
        stvx128   v24, r0, r4
        stvx128   v23, r0, r31
        stvx128   v22, r0, r30
        stvebx    v1, r29, r10
        stvebx    v21, r28, r10
      }
      _R10 += 2;
    }
    v9 += 16;
    v10 += 128;
  }
  while ( v9 < 0x40 );
}


// ========================================================================
// DecompressCover16x16_3
// EA  : 0x829359B8
// RVA : 0x009359B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall DecompressCover16x16_3(
        const unsigned __int8 *cover,
        int tileX,
        int tileY,
        unsigned __int8 *rgba,
        int byteStride)
{
  int v6; // r11

  __asm { vspltisb  v0, 0 }
  __asm { lvx128    v61, r0, r6 }
  v6 = (tileY << 7) + tileX;
  _R5 = vmxi_word_cover_mask2_3;
  _R4 = -32;
  _R11 = &cover[(2 * v6) & 0x1FFFFFFE];
  _R3 = 1;
  _R10 = 16;
  __asm { lvx128    v63, r0, r5 }
  _R31 = -16;
  __asm
  {
    vand128   v60, v93, v63
    lvx128    v62, r5, r4
  }
  _R9 = rgba + 16;
  __asm { lvlx      v13, r0, r11 }
  _R8 = rgba + 32;
  __asm { lvlx      v11, r3, r11 }
  _R4 = 17;
  __asm
  {
    vspltb    v12, v13, 0
    lvlx      v10, r10, r11
    lvx128    v61, r5, r31
    vspltb    v9, v11, 0
    vspltb    v8, v10, 0
    lvx128    v59, r0, r9
  }
  _R5 = rgba + 48;
  __asm
  {
    vand128   v58, v91, v63
    vand128   v7, v12, v62
    lvx128    v57, r0, r8
    vand128   v6, v12, v61
  }
  __asm
  {
    vand128   v5, v9, v62
    lvlx      v4, r4, r11
    vand128   v31, v9, v61
  }
  _R3 = 32;
  __asm
  {
    vcmpgtub  v3, v7, v0
    lvx128    v56, r0, r5
    vcmpgtub  v2, v6, v0
    vspltb    v1, v4, 0
    vand128   v29, v8, v62
    vand128   v53, v89, v63
    vor128    v55, v92, v3
    lvlx      v30, r3, r11
    vor128    v54, v90, v2
    vand128   v52, v88, v63
    vspltb    v28, v30, 0
    vcmpgtub  v27, v5, v0
    stvx128   v55, r0, r6
    vcmpgtub  v26, v31, v0
    lvx128    v51, r6, r7
    vcmpgtub  v25, v29, v0
    vand128   v50, v83, v63
    stvx128   v54, r0, r9
  }
  _R9 = &rgba[byteStride + 16];
  __asm
  {
    vor128    v49, v85, v27
    vor128    v48, v84, v26
    vor128    v47, v82, v25
    vand128   v24, v8, v61
    stvx128   v49, r0, r8
  }
  _R8 = &rgba[byteStride + 32];
  __asm
  {
    stvx128   v48, r0, r5
    vand128   v22, v1, v62
    stvx128   v47, r6, r7
  }
  __asm
  {
    lvx128    v46, r0, r9
    vcmpgtub  v23, v24, v0
    vand128   v45, v78, v63
  }
  _R10 = &rgba[byteStride + byteStride];
  _R6 = &rgba[byteStride + 48];
  __asm
  {
    vor128    v44, v77, v23
    vcmpgtub  v20, v22, v0
    vand128   v21, v1, v61
    vand128   v18, v28, v62
    stvx128   v44, r0, r9
    lvx128    v43, r0, r8
    vand128   v42, v75, v63
    vor128    v41, v74, v20
    vcmpgtub  v19, v21, v0
    stvx128   v41, r0, r8
    lvx128    v40, r0, r6
    vand128   v39, v72, v63
    vor128    v38, v71, v19
  }
  _R9 = _R10 + 16;
  __asm { vcmpgtub  v16, v18, v0 }
  _R5 = 33;
  __asm { vand128   v17, v28, v61 }
  _R8 = _R10 + 32;
  _R4 = 48;
  __asm { stvx128   v38, r0, r6 }
  _R6 = _R10 + 48;
  _R3 = 49;
  __asm
  {
    lvlx      v15, r5, r11
    vcmpgtub  v14, v17, v0
  }
  _R5 = 64;
  __asm
  {
    vspltb    v13, v15, 0
    lvlx      v12, r4, r11
  }
  _R31 = 65;
  __asm
  {
    vspltb    v10, v12, 0
    lvlx      v11, r3, r11
  }
  _R4 = 80;
  __asm
  {
    vand128   v5, v13, v62
    vspltb    v8, v11, 0
    vand128   v3, v13, v61
    lvlx      v9, r5, r11
    vand128   v31, v10, v62
    lvlx      v7, r31, r11
    vand128   v30, v10, v61
    vspltb    v6, v9, 0
    vcmpgtub  v2, v5, v0
    vspltb    v4, v7, 0
    vcmpgtub  v1, v3, v0
  }
  _R3 = 81;
  __asm { vcmpgtub  v29, v31, v0 }
  _R5 = 96;
  __asm
  {
    vcmpgtub  v28, v30, v0
    vand128   v27, v8, v62
    vand128   v25, v8, v61
    vand128   v24, v6, v62
    vand128   v21, v6, v61
    lvx128    v37, r0, r10
    vcmpgtub  v26, v27, v0
    vand128   v36, v69, v63
    vcmpgtub  v23, v25, v0
    vcmpgtub  v22, v24, v0
    vand128   v20, v4, v62
    vor128    v35, v68, v16
    vand128   v19, v4, v61
    stvx128   v35, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v34, r0, r9
    vand128   v33, v66, v63
    vor128    v32, v65, v14
    stvx128   v32, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v60, r0, r8
    vand128   v59, v92, v63
    vor128    v58, v91, v2
    stvx128   v58, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v57, r0, r6
    vand128   v56, v89, v63
    vor128    v55, v88, v1
    stvx128   v55, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v54, r0, r10
    vand128   v53, v86, v63
    vor128    v52, v85, v29
    stvx128   v52, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v51, r0, r9
    vand128   v50, v83, v63
    vor128    v49, v82, v28
    stvx128   v49, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v48, r0, r8
    vand128   v47, v80, v63
    vor128    v46, v79, v26
    stvx128   v46, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v45, r0, r6
    vand128   v44, v77, v63
    vor128    v43, v76, v23
    stvx128   v43, r0, r6
    vcmpgtub  v17, v21, v0
    lvx128    v42, r0, r10
    vand128   v41, v74, v63
    vor128    v40, v73, v22
  }
  _R6 = _R10 + 48;
  __asm
  {
    vcmpgtub  v15, v20, v0
    lvlx      v18, r4, r11
    vcmpgtub  v13, v19, v0
    lvlx      v16, r3, r11
    vspltb    v14, v18, 0
    lvlx      v11, r5, r11
    stvx128   v40, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v39, r0, r9
    vand128   v38, v71, v63
    vor128    v37, v70, v17
    vspltb    v12, v16, 0
    vand128   v8, v14, v62
    vspltb    v10, v11, 0
    vand128   v7, v14, v61
  }
  _R4 = 97;
  _R3 = 112;
  __asm { stvx128   v37, r0, r9 }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v36, r0, r8
    vand128   v35, v68, v63
    vor128    v34, v67, v15
    lvlx      v9, r4, r11
    vcmpgtub  v4, v8, v0
    lvlx      v24, r3, r11
    vcmpgtub  v3, v7, v0
    vspltb    v6, v9, 0
    vand128   v5, v12, v62
    vspltb    v22, v24, 0
    stvx128   v34, r0, r8
  }
  _R8 = _R10 + 32;
  __asm { vand128   v1, v12, v61 }
  _R5 = 113;
  __asm
  {
    vand128   v30, v10, v62
    vcmpgtub  v2, v5, v0
    vand128   v29, v10, v61
    vcmpgtub  v31, v1, v0
    vcmpgtub  v28, v30, v0
    vand128   v26, v6, v62
    vcmpgtub  v27, v29, v0
    vand128   v23, v6, v61
    vcmpgtub  v25, v26, v0
    lvx128    v33, r0, r6
    vand128   v32, v65, v63
    vor128    v60, v64, v13
    stvx128   v60, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v59, r0, r10
    vand128   v58, v91, v63
    vor128    v57, v90, v4
    stvx128   v57, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v56, r0, r9
    vand128   v55, v88, v63
    vor128    v54, v87, v3
    stvx128   v54, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v53, r0, r8
    vand128   v52, v85, v63
    vor128    v51, v84, v2
    stvx128   v51, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v50, r0, r6
    vand128   v49, v82, v63
    vor128    v48, v81, v31
    stvx128   v48, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v47, r0, r10
    vand128   v46, v79, v63
    vor128    v45, v78, v28
    stvx128   v45, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v44, r0, r9
    vand128   v43, v76, v63
    vor128    v42, v75, v27
    stvx128   v42, r0, r9
    vcmpgtub  v20, v23, v0
    vand128   v18, v22, v62
  }
  _R9 = _R10 + 16;
  __asm
  {
    vand128   v16, v22, v61
    lvlx      v21, r5, r11
  }
  _R4 = 128;
  __asm { vspltb    v19, v21, 0 }
  _R3 = 129;
  __asm { vcmpgtub  v13, v18, v0 }
  _R5 = 144;
  __asm { vcmpgtub  v12, v16, v0 }
  _R31 = 176;
  __asm
  {
    vand128   v10, v19, v62
    lvlx      v17, r4, r11
    vand128   v9, v19, v61
    lvlx      v14, r3, r11
    vspltb    v15, v17, 0
  }
  _R4 = 145;
  __asm { vspltb    v11, v14, 0 }
  _R3 = 160;
  __asm
  {
    vcmpgtub  v8, v10, v0
    lvlx      v29, r5, r11
    vcmpgtub  v7, v9, v0
  }
  _R5 = 161;
  __asm
  {
    vand128   v6, v15, v62
    lvlx      v22, r31, r11
    vand128   v5, v15, v61
    lvlx      v27, r4, r11
    vand128   v4, v11, v62
    vspltb    v28, v29, 0
    vand128   v3, v11, v61
  }
  _R4 = 177;
  __asm
  {
    vcmpgtub  v2, v6, v0
    lvlx      v24, r5, r11
    vcmpgtub  v1, v5, v0
    vspltb    v26, v27, 0
    lvx128    v41, r0, r8
    vcmpgtub  v31, v4, v0
    vand128   v40, v73, v63
    vcmpgtub  v30, v3, v0
    vor128    v39, v72, v25
    lvlx      v25, r3, r11
    vspltb    v23, v25, 0
    stvx128   v39, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v38, r0, r6
    vand128   v37, v70, v63
    vor128    v36, v69, v20
    stvx128   v36, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v35, r0, r10
    vand128   v34, v67, v63
    vor128    v33, v66, v13
    stvx128   v33, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v32, r0, r9
    vand128   v60, v64, v63
    vor128    v59, v92, v12
    stvx128   v59, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v58, r0, r8
    vand128   v57, v90, v63
    vor128    v56, v89, v8
    stvx128   v56, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v55, r0, r6
    vand128   v54, v87, v63
    vor128    v53, v86, v7
    stvx128   v53, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v52, r0, r10
    vand128   v51, v84, v63
    vor128    v50, v83, v2
    stvx128   v50, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v49, r0, r9
    vand128   v48, v81, v63
    vor128    v47, v80, v1
    stvx128   v47, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v46, r0, r8
    vand128   v21, v28, v62
    vand128   v45, v78, v63
    vspltb    v20, v24, 0
    vand128   v19, v28, v61
    vspltb    v18, v22, 0
    vand128   v15, v26, v62
  }
  _R3 = 192;
  __asm
  {
    vcmpgtub  v17, v21, v0
    lvlx      v1, r4, r11
    vor128    v44, v77, v31
  }
  _R5 = 193;
  __asm
  {
    vcmpgtub  v16, v19, v0
    vcmpgtub  v11, v15, v0
    vand128   v14, v26, v61
    lvlx      v29, r3, r11
    stvx128   v44, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v43, r0, r6
    vand128   v42, v75, v63
    vor128    v41, v74, v30
    vspltb    v30, v1, 0
    vcmpgtub  v10, v14, v0
    vspltb    v27, v29, 0
    vand128   v13, v23, v62
    vand128   v12, v23, v61
    stvx128   v41, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    vand128   v7, v20, v62
    vcmpgtub  v9, v13, v0
    vcmpgtub  v8, v12, v0
    vand128   v6, v20, v61
    vcmpgtub  v5, v7, v0
    vand128   v3, v18, v62
    vand128   v31, v18, v61
    vcmpgtub  v4, v6, v0
    vcmpgtub  v2, v3, v0
    vcmpgtub  v28, v31, v0
    lvx128    v40, r0, r10
    vand128   v39, v72, v63
    vor128    v38, v71, v17
    stvx128   v38, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v37, r0, r9
    vand128   v36, v69, v63
    vor128    v35, v68, v16
    stvx128   v35, r0, r9
  }
  _R9 = (int)(_R10 + 16);
  __asm
  {
    lvx128    v34, r0, r8
    vand128   v33, v66, v63
    vor128    v32, v65, v11
    stvx128   v32, r0, r8
  }
  _R8 = (int)(_R10 + 32);
  __asm
  {
    lvx128    v60, r0, r6
    vand128   v59, v92, v63
    vor128    v58, v91, v10
    stvx128   v58, r0, r6
  }
  _R6 = (int)(_R10 + 48);
  __asm
  {
    lvx128    v57, r0, r10
    vand128   v56, v89, v63
    vor128    v55, v88, v9
    stvx128   v55, r0, r10
  }
  _R10 = (int)&_R10[byteStride];
  __asm
  {
    lvx128    v54, r0, r9
    vand128   v53, v86, v63
    vor128    v52, v85, v8
    stvx128   v52, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v51, r0, r8
    vand128   v50, v83, v63
    vor128    v49, v82, v5
    stvx128   v49, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v48, r0, r6
    vand128   v47, v80, v63
    vor128    v46, v79, v4
    stvx128   v46, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v45, r0, r10
    vand128   v44, v77, v63
    vor128    v43, v76, v2
    stvx128   v43, r0, r10
    vand128   v26, v30, v62
    vand128   v24, v30, v61
  }
  _R10 = _R10 + byteStride;
  __asm
  {
    vand128   v17, v27, v62
    lvlx      v25, r5, r11
    vand128   v15, v27, v61
  }
  _R4 = 208;
  __asm
  {
    vcmpgtub  v21, v26, v0
    vspltb    v23, v25, 0
    vcmpgtub  v19, v24, v0
  }
  _R3 = 209;
  __asm { vcmpgtub  v14, v17, v0 }
  _R5 = 224;
  __asm
  {
    vcmpgtub  v13, v15, v0
    vand128   v12, v23, v62
    lvlx      v22, r4, r11
    vand128   v11, v23, v61
  }
  _R4 = 225;
  __asm
  {
    vspltb    v18, v22, 0
    lvlx      v20, r3, r11
  }
  _R3 = 240;
  __asm
  {
    lvlx      v3, r5, r11
    vcmpgtub  v9, v12, v0
    vspltb    v16, v20, 0
    vcmpgtub  v8, v11, v0
  }
  _R5 = 241;
  __asm
  {
    vand128   v10, v18, v62
    lvlx      v29, r4, r11
    vand128   v6, v18, v61
    vspltb    v31, v3, 0
    vand128   v5, v16, v62
    vspltb    v27, v29, 0
    vand128   v4, v16, v61
    vcmpgtub  v7, v10, v0
    lvlx      v26, r5, r11
    vcmpgtub  v2, v6, v0
    lvx128    v42, r0, r9
    vcmpgtub  v1, v5, v0
    vand128   v41, v74, v63
    vcmpgtub  v30, v4, v0
    vor128    v40, v73, v28
    lvlx      v28, r3, r11
    vspltb    v25, v28, 0
    stvx128   v40, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v39, r0, r8
    vand128   v38, v71, v63
    vor128    v37, v70, v21
    stvx128   v37, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v36, r0, r6
    vand128   v35, v68, v63
    vor128    v34, v67, v19
    stvx128   v34, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v33, r0, r10
    vand128   v32, v65, v63
    vor128    v60, v64, v14
    stvx128   v60, r0, r10
  }
  _R10 = _R10 + byteStride;
  _R11 = _R10 + byteStride;
  __asm
  {
    lvx128    v59, r0, r9
    vand128   v58, v91, v63
    vor128    v57, v90, v13
    stvx128   v57, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v56, r0, r8
    vand128   v55, v88, v63
    vor128    v54, v87, v9
    stvx128   v54, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v53, r0, r6
    vand128   v52, v85, v63
    vor128    v51, v84, v8
    stvx128   v51, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v50, r0, r10
    vand128   v49, v82, v63
    vor128    v48, v81, v7
    stvx128   v48, r0, r10
    lvx128    v47, r0, r9
    vand128   v23, v31, v62
    vand128   v46, v79, v63
  }
  __asm
  {
    vand128   v22, v31, v61
    vspltb    v24, v26, 0
    vand128   v21, v27, v62
    vcmpgtub  v20, v23, v0
    vor128    v45, v78, v2
    vcmpgtub  v19, v22, v0
    vcmpgtub  v17, v21, v0
    vand128   v18, v27, v61
    stvx128   v45, r0, r9
  }
  _R9 = _R10 + byteStride + 32;
  __asm
  {
    lvx128    v44, r0, r8
    vand128   v43, v76, v63
    vor128    v42, v75, v1
    vcmpgtub  v14, v18, v0
    vand128   v16, v25, v62
    vand128   v15, v25, v61
    stvx128   v42, r0, r8
  }
  _R8 = _R10 + byteStride + 48;
  __asm
  {
    lvx128    v41, r0, r6
    vand128   v40, v73, v63
    vor128    v39, v72, v30
    vcmpgtub  v13, v16, v0
    vcmpgtub  v12, v15, v0
    vand128   v11, v24, v62
    stvx128   v39, r0, r6
    vand128   v9, v24, v61
    lvx128    v38, r0, r11
    vand128   v37, v70, v63
    vor128    v36, v69, v20
    vcmpgtub  v10, v11, v0
    vcmpgtub  v8, v9, v0
    stvx128   v36, r0, r11
  }
  _R11 = _R10 + byteStride + byteStride;
  _R10 = _R10 + byteStride + 16;
  __asm
  {
    lvx128    v35, r0, r10
    vand128   v34, v67, v63
    vor128    v33, v66, v19
    stvx128   v33, r0, r10
  }
  _R10 = _R11 + 16;
  __asm
  {
    lvx128    v32, r0, r9
    vand128   v60, v64, v63
    vor128    v59, v92, v17
    stvx128   v59, r0, r9
  }
  _R9 = _R11 + 32;
  __asm
  {
    lvx128    v58, r0, r8
    vand128   v57, v90, v63
    vor128    v56, v89, v14
    stvx128   v56, r0, r8
  }
  _R8 = _R11 + 48;
  __asm
  {
    lvx128    v55, r0, r11
    vand128   v54, v87, v63
    vor128    v53, v86, v13
    stvx128   v53, r0, r11
    lvx128    v52, r0, r10
    vand128   v51, v84, v63
    vor128    v50, v83, v12
    stvx128   v50, r0, r10
    lvx128    v49, r0, r9
    vand128   v48, v81, v63
    vor128    v47, v80, v10
    stvx128   v47, r0, r9
    lvx128    v46, r0, r8
    vand128   v45, v78, v63
    vor128    v44, v77, v8
    stvx128   v44, r0, r8
  }
}


// ========================================================================
// ConstantScaleSpecular16x16_3
// EA  : 0x82936270
// RVA : 0x00936270
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall ConstantScaleSpecular16x16_3(
        unsigned __int8 *specularScale,
        int tileX,
        int tileY,
        unsigned __int8 *rgba,
        unsigned __int8 specularShift,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        unsigned __int8 a20)
{
  int v24; // ctr
  unsigned __int8 *v34; // r11
  int v35; // r7

  _R9 = &a20;
  a20 = specularShift;
  _R8 = vmxi_word_specular_shift_mask_3;
  _R11 = rgba + 32;
  __asm
  {
    lvlx      v0, r0, r9
    vspltb    v13, v0, 0
    lvx128    v63, r0, r8
  }
  v24 = 8;
  _R30 = -32;
  __asm { vand128   v0, v13, v63 }
  _R29 = -32;
  _R28 = -16;
  _R27 = -16;
  _R31 = 16;
  _R6 = 32;
  _R8 = 48;
  _R9 = 64;
  _R10 = 80;
  do
  {
    __asm
    {
      lvx128    v13, r11, r30
      lvx128    v12, r11, r28
      vslb      v11, v13, v0
      lvx128    v10, r0, r11
      vslb      v9, v12, v0
      lvx128    v8, r11, r31
      vslb      v7, v10, v0
      lvx128    v6, r11, r6
      vslb      v5, v8, v0
      lvx128    v4, r11, r8
      vslb      v3, v6, v0
      lvx128    v2, r11, r9
      vslb      v1, v4, v0
      lvx128    v31, r11, r10
      vslb      v30, v2, v0
      vslb      v29, v31, v0
      stvx128   v11, r11, r29
      stvx128   v9, r11, r27
      stvx128   v7, r0, r11
      stvx128   v5, r11, r31
      stvx128   v3, r11, r6
      stvx128   v1, r11, r8
      stvx128   v30, r11, r9
      stvx128   v29, r11, r10
    }
    _R11 += 128;
    --v24;
  }
  while ( v24 != 0 );
  v34 = &specularScale[4 * tileX + (tileY << 9 >> 2)];
  v35 = (((((((8 * ((1 << specularShift) + 255)) & 0xF8) << 8) | (8 * ((1 << specularShift) + 255)) & 0xF8) << 8)
        | (8 * ((1 << specularShift) + 255)) & 0xF8) << 8)
      | (8 * ((1 << specularShift) + 255)) & 0xF8;
  *(_DWORD *)v34 = v35;
  *((_DWORD *)v34 + 8) = v35;
  *((_DWORD *)v34 + 16) = v35;
  *((_DWORD *)v34 + 24) = v35;
}


// ========================================================================
// DynamicScaleSpecular16x16_3
// EA  : 0x82936388
// RVA : 0x00936388
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall DynamicScaleSpecular16x16_3(
        unsigned __int8 *specularScale,
        int tileX,
        int tileY,
        unsigned __int8 *rgba)
{
  int v8; // r25
  unsigned int v9; // r27
  unsigned int v10; // r26
  int i; // ctr

  __asm { vspltisb  v30, 2 }
  _R10 = 16;
  __asm { vspltisb  v12, 8 }
  _R9 = vmxi_byte_63_3;
  _R8 = 32;
  v8 = 4 * tileX;
  v9 = 0;
  v10 = tileY << 9;
  __asm
  {
    lvx128    v3, r0, r9
    lvx128    v2, r9, r10
    lvx128    v63, r9, r8
  }
  do
  {
    _R10 = 0;
    _R29 = &specularScale[(v10 >> 2) + v8];
    _R28 = _R29 + 1;
    for ( i = 2; i != 0; --i )
    {
      _R11 = &rgba[16 * v9 + 16 * _R10];
      _R9 = _R11 + 64;
      _R8 = _R11 + 128;
      _R7 = _R11 + 192;
      _R5 = _R11 + 16;
      __asm { lvx128    v11, r0, r11 }
      _R4 = _R11 + 80;
      _R31 = _R11 + 144;
      __asm { lvx128    v10, r0, r9 }
      _R30 = _R11 + 208;
      __asm
      {
        lvx128    v9, r0, r8
        lvx128    v8, r0, r7
        vmaxub    v0, v11, v10
        lvx128    v7, r0, r5
        vmaxub    v13, v9, v8
        lvx128    v6, r0, r4
        lvx128    v5, r0, r31
        vmaxub    v1, v7, v6
        lvx128    v4, r0, r30
        vmaxub    v31, v5, v4
        vmaxub    v0, v0, v13
        vmaxub    v13, v1, v31
        vsldoi    v29, v0, v0, v8
        vsldoi    v28, v13, v13, v8
        vmaxub    v0, v0, v29
        vmaxub    v13, v13, v28
        vsldoi    v27, v0, v0, v4
        vsldoi    v26, v13, v13, v4
        vmaxub    v0, v0, v27
        vmaxub    v13, v13, v26
        vsldoi    v25, v0, v0, v15
        vsldoi    v24, v13, v13, v15
        vmaxub    v0, v0, v25
        vmaxub    v13, v13, v24
        vsldoi    v23, v0, v0, v15
        vsldoi    v22, v13, v13, v15
        vmaxub    v21, v0, v23
        vmaxub    v20, v13, v22
        vspltb    v0, v21, 2
        vspltb    v13, v20, 2
        vcmpgtub  v19, v0, v3
        vcmpgtub  v18, v0, v2
        vcmpgtub  v17, v13, v3
        vcmpgtub  v16, v13, v2
        vaddsbs   v15, v30, v19
        vaddsbs   v14, v30, v17
        vaddsbs   v0, v15, v18
        vaddsbs   v13, v14, v16
        vslb      v1, v12, v0
        vand128   v0, v0, v63
        vslb      v31, v12, v13
        vand128   v13, v13, v63
        vsububs   v1, v1, v12
        vslb      v29, v11, v0
        vslb      v28, v10, v0
        vslb      v27, v9, v0
        vslb      v26, v8, v0
        vslb      v25, v7, v13
        stvx128   v29, r0, r11
        vslb      v24, v6, v13
        stvx128   v28, r0, r9
        vslb      v23, v5, v13
        stvx128   v27, r0, r8
        vslb      v22, v4, v13
        stvx128   v26, r0, r7
        vsububs   v21, v31, v12
        stvx128   v25, r0, r5
        stvx128   v24, r0, r4
        stvx128   v23, r0, r31
        stvx128   v22, r0, r30
        stvebx    v1, r29, r10
        stvebx    v21, r28, r10
      }
      _R10 += 2;
    }
    v9 += 16;
    v10 += 128;
  }
  while ( v9 < 0x40 );
}


// ========================================================================
// DecompressCover16x16_4
// EA  : 0x829370B8
// RVA : 0x009370B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall DecompressCover16x16_4(
        const unsigned __int8 *cover,
        int tileX,
        int tileY,
        unsigned __int8 *rgba,
        int byteStride)
{
  int v6; // r11

  __asm { vspltisb  v0, 0 }
  __asm { lvx128    v61, r0, r6 }
  v6 = (tileY << 7) + tileX;
  _R5 = vmxi_word_cover_mask2_4;
  _R4 = -32;
  _R11 = &cover[(2 * v6) & 0x1FFFFFFE];
  _R3 = 1;
  _R10 = 16;
  __asm { lvx128    v63, r0, r5 }
  _R31 = -16;
  __asm
  {
    vand128   v60, v93, v63
    lvx128    v62, r5, r4
  }
  _R9 = rgba + 16;
  __asm { lvlx      v13, r0, r11 }
  _R8 = rgba + 32;
  __asm { lvlx      v11, r3, r11 }
  _R4 = 17;
  __asm
  {
    vspltb    v12, v13, 0
    lvlx      v10, r10, r11
    lvx128    v61, r5, r31
    vspltb    v9, v11, 0
    vspltb    v8, v10, 0
    lvx128    v59, r0, r9
  }
  _R5 = rgba + 48;
  __asm
  {
    vand128   v58, v91, v63
    vand128   v7, v12, v62
    lvx128    v57, r0, r8
    vand128   v6, v12, v61
  }
  __asm
  {
    vand128   v5, v9, v62
    lvlx      v4, r4, r11
    vand128   v31, v9, v61
  }
  _R3 = 32;
  __asm
  {
    vcmpgtub  v3, v7, v0
    lvx128    v56, r0, r5
    vcmpgtub  v2, v6, v0
    vspltb    v1, v4, 0
    vand128   v29, v8, v62
    vand128   v53, v89, v63
    vor128    v55, v92, v3
    lvlx      v30, r3, r11
    vor128    v54, v90, v2
    vand128   v52, v88, v63
    vspltb    v28, v30, 0
    vcmpgtub  v27, v5, v0
    stvx128   v55, r0, r6
    vcmpgtub  v26, v31, v0
    lvx128    v51, r6, r7
    vcmpgtub  v25, v29, v0
    vand128   v50, v83, v63
    stvx128   v54, r0, r9
  }
  _R9 = &rgba[byteStride + 16];
  __asm
  {
    vor128    v49, v85, v27
    vor128    v48, v84, v26
    vor128    v47, v82, v25
    vand128   v24, v8, v61
    stvx128   v49, r0, r8
  }
  _R8 = &rgba[byteStride + 32];
  __asm
  {
    stvx128   v48, r0, r5
    vand128   v22, v1, v62
    stvx128   v47, r6, r7
  }
  __asm
  {
    lvx128    v46, r0, r9
    vcmpgtub  v23, v24, v0
    vand128   v45, v78, v63
  }
  _R10 = &rgba[byteStride + byteStride];
  _R6 = &rgba[byteStride + 48];
  __asm
  {
    vor128    v44, v77, v23
    vcmpgtub  v20, v22, v0
    vand128   v21, v1, v61
    vand128   v18, v28, v62
    stvx128   v44, r0, r9
    lvx128    v43, r0, r8
    vand128   v42, v75, v63
    vor128    v41, v74, v20
    vcmpgtub  v19, v21, v0
    stvx128   v41, r0, r8
    lvx128    v40, r0, r6
    vand128   v39, v72, v63
    vor128    v38, v71, v19
  }
  _R9 = _R10 + 16;
  __asm { vcmpgtub  v16, v18, v0 }
  _R5 = 33;
  __asm { vand128   v17, v28, v61 }
  _R8 = _R10 + 32;
  _R4 = 48;
  __asm { stvx128   v38, r0, r6 }
  _R6 = _R10 + 48;
  _R3 = 49;
  __asm
  {
    lvlx      v15, r5, r11
    vcmpgtub  v14, v17, v0
  }
  _R5 = 64;
  __asm
  {
    vspltb    v13, v15, 0
    lvlx      v12, r4, r11
  }
  _R31 = 65;
  __asm
  {
    vspltb    v10, v12, 0
    lvlx      v11, r3, r11
  }
  _R4 = 80;
  __asm
  {
    vand128   v5, v13, v62
    vspltb    v8, v11, 0
    vand128   v3, v13, v61
    lvlx      v9, r5, r11
    vand128   v31, v10, v62
    lvlx      v7, r31, r11
    vand128   v30, v10, v61
    vspltb    v6, v9, 0
    vcmpgtub  v2, v5, v0
    vspltb    v4, v7, 0
    vcmpgtub  v1, v3, v0
  }
  _R3 = 81;
  __asm { vcmpgtub  v29, v31, v0 }
  _R5 = 96;
  __asm
  {
    vcmpgtub  v28, v30, v0
    vand128   v27, v8, v62
    vand128   v25, v8, v61
    vand128   v24, v6, v62
    vand128   v21, v6, v61
    lvx128    v37, r0, r10
    vcmpgtub  v26, v27, v0
    vand128   v36, v69, v63
    vcmpgtub  v23, v25, v0
    vcmpgtub  v22, v24, v0
    vand128   v20, v4, v62
    vor128    v35, v68, v16
    vand128   v19, v4, v61
    stvx128   v35, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v34, r0, r9
    vand128   v33, v66, v63
    vor128    v32, v65, v14
    stvx128   v32, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v60, r0, r8
    vand128   v59, v92, v63
    vor128    v58, v91, v2
    stvx128   v58, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v57, r0, r6
    vand128   v56, v89, v63
    vor128    v55, v88, v1
    stvx128   v55, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v54, r0, r10
    vand128   v53, v86, v63
    vor128    v52, v85, v29
    stvx128   v52, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v51, r0, r9
    vand128   v50, v83, v63
    vor128    v49, v82, v28
    stvx128   v49, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v48, r0, r8
    vand128   v47, v80, v63
    vor128    v46, v79, v26
    stvx128   v46, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v45, r0, r6
    vand128   v44, v77, v63
    vor128    v43, v76, v23
    stvx128   v43, r0, r6
    vcmpgtub  v17, v21, v0
    lvx128    v42, r0, r10
    vand128   v41, v74, v63
    vor128    v40, v73, v22
  }
  _R6 = _R10 + 48;
  __asm
  {
    vcmpgtub  v15, v20, v0
    lvlx      v18, r4, r11
    vcmpgtub  v13, v19, v0
    lvlx      v16, r3, r11
    vspltb    v14, v18, 0
    lvlx      v11, r5, r11
    stvx128   v40, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v39, r0, r9
    vand128   v38, v71, v63
    vor128    v37, v70, v17
    vspltb    v12, v16, 0
    vand128   v8, v14, v62
    vspltb    v10, v11, 0
    vand128   v7, v14, v61
  }
  _R4 = 97;
  _R3 = 112;
  __asm { stvx128   v37, r0, r9 }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v36, r0, r8
    vand128   v35, v68, v63
    vor128    v34, v67, v15
    lvlx      v9, r4, r11
    vcmpgtub  v4, v8, v0
    lvlx      v24, r3, r11
    vcmpgtub  v3, v7, v0
    vspltb    v6, v9, 0
    vand128   v5, v12, v62
    vspltb    v22, v24, 0
    stvx128   v34, r0, r8
  }
  _R8 = _R10 + 32;
  __asm { vand128   v1, v12, v61 }
  _R5 = 113;
  __asm
  {
    vand128   v30, v10, v62
    vcmpgtub  v2, v5, v0
    vand128   v29, v10, v61
    vcmpgtub  v31, v1, v0
    vcmpgtub  v28, v30, v0
    vand128   v26, v6, v62
    vcmpgtub  v27, v29, v0
    vand128   v23, v6, v61
    vcmpgtub  v25, v26, v0
    lvx128    v33, r0, r6
    vand128   v32, v65, v63
    vor128    v60, v64, v13
    stvx128   v60, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v59, r0, r10
    vand128   v58, v91, v63
    vor128    v57, v90, v4
    stvx128   v57, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v56, r0, r9
    vand128   v55, v88, v63
    vor128    v54, v87, v3
    stvx128   v54, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v53, r0, r8
    vand128   v52, v85, v63
    vor128    v51, v84, v2
    stvx128   v51, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v50, r0, r6
    vand128   v49, v82, v63
    vor128    v48, v81, v31
    stvx128   v48, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v47, r0, r10
    vand128   v46, v79, v63
    vor128    v45, v78, v28
    stvx128   v45, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v44, r0, r9
    vand128   v43, v76, v63
    vor128    v42, v75, v27
    stvx128   v42, r0, r9
    vcmpgtub  v20, v23, v0
    vand128   v18, v22, v62
  }
  _R9 = _R10 + 16;
  __asm
  {
    vand128   v16, v22, v61
    lvlx      v21, r5, r11
  }
  _R4 = 128;
  __asm { vspltb    v19, v21, 0 }
  _R3 = 129;
  __asm { vcmpgtub  v13, v18, v0 }
  _R5 = 144;
  __asm { vcmpgtub  v12, v16, v0 }
  _R31 = 176;
  __asm
  {
    vand128   v10, v19, v62
    lvlx      v17, r4, r11
    vand128   v9, v19, v61
    lvlx      v14, r3, r11
    vspltb    v15, v17, 0
  }
  _R4 = 145;
  __asm { vspltb    v11, v14, 0 }
  _R3 = 160;
  __asm
  {
    vcmpgtub  v8, v10, v0
    lvlx      v29, r5, r11
    vcmpgtub  v7, v9, v0
  }
  _R5 = 161;
  __asm
  {
    vand128   v6, v15, v62
    lvlx      v22, r31, r11
    vand128   v5, v15, v61
    lvlx      v27, r4, r11
    vand128   v4, v11, v62
    vspltb    v28, v29, 0
    vand128   v3, v11, v61
  }
  _R4 = 177;
  __asm
  {
    vcmpgtub  v2, v6, v0
    lvlx      v24, r5, r11
    vcmpgtub  v1, v5, v0
    vspltb    v26, v27, 0
    lvx128    v41, r0, r8
    vcmpgtub  v31, v4, v0
    vand128   v40, v73, v63
    vcmpgtub  v30, v3, v0
    vor128    v39, v72, v25
    lvlx      v25, r3, r11
    vspltb    v23, v25, 0
    stvx128   v39, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v38, r0, r6
    vand128   v37, v70, v63
    vor128    v36, v69, v20
    stvx128   v36, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v35, r0, r10
    vand128   v34, v67, v63
    vor128    v33, v66, v13
    stvx128   v33, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v32, r0, r9
    vand128   v60, v64, v63
    vor128    v59, v92, v12
    stvx128   v59, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v58, r0, r8
    vand128   v57, v90, v63
    vor128    v56, v89, v8
    stvx128   v56, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v55, r0, r6
    vand128   v54, v87, v63
    vor128    v53, v86, v7
    stvx128   v53, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v52, r0, r10
    vand128   v51, v84, v63
    vor128    v50, v83, v2
    stvx128   v50, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v49, r0, r9
    vand128   v48, v81, v63
    vor128    v47, v80, v1
    stvx128   v47, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v46, r0, r8
    vand128   v21, v28, v62
    vand128   v45, v78, v63
    vspltb    v20, v24, 0
    vand128   v19, v28, v61
    vspltb    v18, v22, 0
    vand128   v15, v26, v62
  }
  _R3 = 192;
  __asm
  {
    vcmpgtub  v17, v21, v0
    lvlx      v1, r4, r11
    vor128    v44, v77, v31
  }
  _R5 = 193;
  __asm
  {
    vcmpgtub  v16, v19, v0
    vcmpgtub  v11, v15, v0
    vand128   v14, v26, v61
    lvlx      v29, r3, r11
    stvx128   v44, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v43, r0, r6
    vand128   v42, v75, v63
    vor128    v41, v74, v30
    vspltb    v30, v1, 0
    vcmpgtub  v10, v14, v0
    vspltb    v27, v29, 0
    vand128   v13, v23, v62
    vand128   v12, v23, v61
    stvx128   v41, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    vand128   v7, v20, v62
    vcmpgtub  v9, v13, v0
    vcmpgtub  v8, v12, v0
    vand128   v6, v20, v61
    vcmpgtub  v5, v7, v0
    vand128   v3, v18, v62
    vand128   v31, v18, v61
    vcmpgtub  v4, v6, v0
    vcmpgtub  v2, v3, v0
    vcmpgtub  v28, v31, v0
    lvx128    v40, r0, r10
    vand128   v39, v72, v63
    vor128    v38, v71, v17
    stvx128   v38, r0, r10
  }
  _R10 = &_R10[byteStride];
  __asm
  {
    lvx128    v37, r0, r9
    vand128   v36, v69, v63
    vor128    v35, v68, v16
    stvx128   v35, r0, r9
  }
  _R9 = (int)(_R10 + 16);
  __asm
  {
    lvx128    v34, r0, r8
    vand128   v33, v66, v63
    vor128    v32, v65, v11
    stvx128   v32, r0, r8
  }
  _R8 = (int)(_R10 + 32);
  __asm
  {
    lvx128    v60, r0, r6
    vand128   v59, v92, v63
    vor128    v58, v91, v10
    stvx128   v58, r0, r6
  }
  _R6 = (int)(_R10 + 48);
  __asm
  {
    lvx128    v57, r0, r10
    vand128   v56, v89, v63
    vor128    v55, v88, v9
    stvx128   v55, r0, r10
  }
  _R10 = (int)&_R10[byteStride];
  __asm
  {
    lvx128    v54, r0, r9
    vand128   v53, v86, v63
    vor128    v52, v85, v8
    stvx128   v52, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v51, r0, r8
    vand128   v50, v83, v63
    vor128    v49, v82, v5
    stvx128   v49, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v48, r0, r6
    vand128   v47, v80, v63
    vor128    v46, v79, v4
    stvx128   v46, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v45, r0, r10
    vand128   v44, v77, v63
    vor128    v43, v76, v2
    stvx128   v43, r0, r10
    vand128   v26, v30, v62
    vand128   v24, v30, v61
  }
  _R10 = _R10 + byteStride;
  __asm
  {
    vand128   v17, v27, v62
    lvlx      v25, r5, r11
    vand128   v15, v27, v61
  }
  _R4 = 208;
  __asm
  {
    vcmpgtub  v21, v26, v0
    vspltb    v23, v25, 0
    vcmpgtub  v19, v24, v0
  }
  _R3 = 209;
  __asm { vcmpgtub  v14, v17, v0 }
  _R5 = 224;
  __asm
  {
    vcmpgtub  v13, v15, v0
    vand128   v12, v23, v62
    lvlx      v22, r4, r11
    vand128   v11, v23, v61
  }
  _R4 = 225;
  __asm
  {
    vspltb    v18, v22, 0
    lvlx      v20, r3, r11
  }
  _R3 = 240;
  __asm
  {
    lvlx      v3, r5, r11
    vcmpgtub  v9, v12, v0
    vspltb    v16, v20, 0
    vcmpgtub  v8, v11, v0
  }
  _R5 = 241;
  __asm
  {
    vand128   v10, v18, v62
    lvlx      v29, r4, r11
    vand128   v6, v18, v61
    vspltb    v31, v3, 0
    vand128   v5, v16, v62
    vspltb    v27, v29, 0
    vand128   v4, v16, v61
    vcmpgtub  v7, v10, v0
    lvlx      v26, r5, r11
    vcmpgtub  v2, v6, v0
    lvx128    v42, r0, r9
    vcmpgtub  v1, v5, v0
    vand128   v41, v74, v63
    vcmpgtub  v30, v4, v0
    vor128    v40, v73, v28
    lvlx      v28, r3, r11
    vspltb    v25, v28, 0
    stvx128   v40, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v39, r0, r8
    vand128   v38, v71, v63
    vor128    v37, v70, v21
    stvx128   v37, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v36, r0, r6
    vand128   v35, v68, v63
    vor128    v34, v67, v19
    stvx128   v34, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v33, r0, r10
    vand128   v32, v65, v63
    vor128    v60, v64, v14
    stvx128   v60, r0, r10
  }
  _R10 = _R10 + byteStride;
  _R11 = _R10 + byteStride;
  __asm
  {
    lvx128    v59, r0, r9
    vand128   v58, v91, v63
    vor128    v57, v90, v13
    stvx128   v57, r0, r9
  }
  _R9 = _R10 + 16;
  __asm
  {
    lvx128    v56, r0, r8
    vand128   v55, v88, v63
    vor128    v54, v87, v9
    stvx128   v54, r0, r8
  }
  _R8 = _R10 + 32;
  __asm
  {
    lvx128    v53, r0, r6
    vand128   v52, v85, v63
    vor128    v51, v84, v8
    stvx128   v51, r0, r6
  }
  _R6 = _R10 + 48;
  __asm
  {
    lvx128    v50, r0, r10
    vand128   v49, v82, v63
    vor128    v48, v81, v7
    stvx128   v48, r0, r10
    lvx128    v47, r0, r9
    vand128   v23, v31, v62
    vand128   v46, v79, v63
  }
  __asm
  {
    vand128   v22, v31, v61
    vspltb    v24, v26, 0
    vand128   v21, v27, v62
    vcmpgtub  v20, v23, v0
    vor128    v45, v78, v2
    vcmpgtub  v19, v22, v0
    vcmpgtub  v17, v21, v0
    vand128   v18, v27, v61
    stvx128   v45, r0, r9
  }
  _R9 = _R10 + byteStride + 32;
  __asm
  {
    lvx128    v44, r0, r8
    vand128   v43, v76, v63
    vor128    v42, v75, v1
    vcmpgtub  v14, v18, v0
    vand128   v16, v25, v62
    vand128   v15, v25, v61
    stvx128   v42, r0, r8
  }
  _R8 = _R10 + byteStride + 48;
  __asm
  {
    lvx128    v41, r0, r6
    vand128   v40, v73, v63
    vor128    v39, v72, v30
    vcmpgtub  v13, v16, v0
    vcmpgtub  v12, v15, v0
    vand128   v11, v24, v62
    stvx128   v39, r0, r6
    vand128   v9, v24, v61
    lvx128    v38, r0, r11
    vand128   v37, v70, v63
    vor128    v36, v69, v20
    vcmpgtub  v10, v11, v0
    vcmpgtub  v8, v9, v0
    stvx128   v36, r0, r11
  }
  _R11 = _R10 + byteStride + byteStride;
  _R10 = _R10 + byteStride + 16;
  __asm
  {
    lvx128    v35, r0, r10
    vand128   v34, v67, v63
    vor128    v33, v66, v19
    stvx128   v33, r0, r10
  }
  _R10 = _R11 + 16;
  __asm
  {
    lvx128    v32, r0, r9
    vand128   v60, v64, v63
    vor128    v59, v92, v17
    stvx128   v59, r0, r9
  }
  _R9 = _R11 + 32;
  __asm
  {
    lvx128    v58, r0, r8
    vand128   v57, v90, v63
    vor128    v56, v89, v14
    stvx128   v56, r0, r8
  }
  _R8 = _R11 + 48;
  __asm
  {
    lvx128    v55, r0, r11
    vand128   v54, v87, v63
    vor128    v53, v86, v13
    stvx128   v53, r0, r11
    lvx128    v52, r0, r10
    vand128   v51, v84, v63
    vor128    v50, v83, v12
    stvx128   v50, r0, r10
    lvx128    v49, r0, r9
    vand128   v48, v81, v63
    vor128    v47, v80, v10
    stvx128   v47, r0, r9
    lvx128    v46, r0, r8
    vand128   v45, v78, v63
    vor128    v44, v77, v8
    stvx128   v44, r0, r8
  }
}


// ========================================================================
// ConstantScaleSpecular16x16_4
// EA  : 0x82937970
// RVA : 0x00937970
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall ConstantScaleSpecular16x16_4(
        unsigned __int8 *specularScale,
        int tileX,
        int tileY,
        unsigned __int8 *rgba,
        unsigned __int8 specularShift,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        unsigned __int8 a20)
{
  int v24; // ctr
  unsigned __int8 *v34; // r11
  int v35; // r7

  _R9 = &a20;
  a20 = specularShift;
  _R8 = vmxi_word_specular_shift_mask_4;
  _R11 = rgba + 32;
  __asm
  {
    lvlx      v0, r0, r9
    vspltb    v13, v0, 0
    lvx128    v63, r0, r8
  }
  v24 = 8;
  _R30 = -32;
  __asm { vand128   v0, v13, v63 }
  _R29 = -32;
  _R28 = -16;
  _R27 = -16;
  _R31 = 16;
  _R6 = 32;
  _R8 = 48;
  _R9 = 64;
  _R10 = 80;
  do
  {
    __asm
    {
      lvx128    v13, r11, r30
      lvx128    v12, r11, r28
      vslb      v11, v13, v0
      lvx128    v10, r0, r11
      vslb      v9, v12, v0
      lvx128    v8, r11, r31
      vslb      v7, v10, v0
      lvx128    v6, r11, r6
      vslb      v5, v8, v0
      lvx128    v4, r11, r8
      vslb      v3, v6, v0
      lvx128    v2, r11, r9
      vslb      v1, v4, v0
      lvx128    v31, r11, r10
      vslb      v30, v2, v0
      vslb      v29, v31, v0
      stvx128   v11, r11, r29
      stvx128   v9, r11, r27
      stvx128   v7, r0, r11
      stvx128   v5, r11, r31
      stvx128   v3, r11, r6
      stvx128   v1, r11, r8
      stvx128   v30, r11, r9
      stvx128   v29, r11, r10
    }
    _R11 += 128;
    --v24;
  }
  while ( v24 != 0 );
  v34 = &specularScale[4 * tileX + (tileY << 9 >> 2)];
  v35 = (((((((8 * ((1 << specularShift) + 255)) & 0xF8) << 8) | (8 * ((1 << specularShift) + 255)) & 0xF8) << 8)
        | (8 * ((1 << specularShift) + 255)) & 0xF8) << 8)
      | (8 * ((1 << specularShift) + 255)) & 0xF8;
  *(_DWORD *)v34 = v35;
  *((_DWORD *)v34 + 8) = v35;
  *((_DWORD *)v34 + 16) = v35;
  *((_DWORD *)v34 + 24) = v35;
}


// ========================================================================
// DynamicScaleSpecular16x16_4
// EA  : 0x82937A88
// RVA : 0x00937A88
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_support.h
// ========================================================================

void __fastcall DynamicScaleSpecular16x16_4(
        unsigned __int8 *specularScale,
        int tileX,
        int tileY,
        unsigned __int8 *rgba)
{
  int v8; // r25
  unsigned int v9; // r27
  unsigned int v10; // r26
  int i; // ctr

  __asm { vspltisb  v30, 2 }
  _R10 = 16;
  __asm { vspltisb  v12, 8 }
  _R9 = vmxi_byte_63_4;
  _R8 = 32;
  v8 = 4 * tileX;
  v9 = 0;
  v10 = tileY << 9;
  __asm
  {
    lvx128    v3, r0, r9
    lvx128    v2, r9, r10
    lvx128    v63, r9, r8
  }
  do
  {
    _R10 = 0;
    _R29 = &specularScale[(v10 >> 2) + v8];
    _R28 = _R29 + 1;
    for ( i = 2; i != 0; --i )
    {
      _R11 = &rgba[16 * v9 + 16 * _R10];
      _R9 = _R11 + 64;
      _R8 = _R11 + 128;
      _R7 = _R11 + 192;
      _R5 = _R11 + 16;
      __asm { lvx128    v11, r0, r11 }
      _R4 = _R11 + 80;
      _R31 = _R11 + 144;
      __asm { lvx128    v10, r0, r9 }
      _R30 = _R11 + 208;
      __asm
      {
        lvx128    v9, r0, r8
        lvx128    v8, r0, r7
        vmaxub    v0, v11, v10
        lvx128    v7, r0, r5
        vmaxub    v13, v9, v8
        lvx128    v6, r0, r4
        lvx128    v5, r0, r31
        vmaxub    v1, v7, v6
        lvx128    v4, r0, r30
        vmaxub    v31, v5, v4
        vmaxub    v0, v0, v13
        vmaxub    v13, v1, v31
        vsldoi    v29, v0, v0, v8
        vsldoi    v28, v13, v13, v8
        vmaxub    v0, v0, v29
        vmaxub    v13, v13, v28
        vsldoi    v27, v0, v0, v4
        vsldoi    v26, v13, v13, v4
        vmaxub    v0, v0, v27
        vmaxub    v13, v13, v26
        vsldoi    v25, v0, v0, v15
        vsldoi    v24, v13, v13, v15
        vmaxub    v0, v0, v25
        vmaxub    v13, v13, v24
        vsldoi    v23, v0, v0, v15
        vsldoi    v22, v13, v13, v15
        vmaxub    v21, v0, v23
        vmaxub    v20, v13, v22
        vspltb    v0, v21, 2
        vspltb    v13, v20, 2
        vcmpgtub  v19, v0, v3
        vcmpgtub  v18, v0, v2
        vcmpgtub  v17, v13, v3
        vcmpgtub  v16, v13, v2
        vaddsbs   v15, v30, v19
        vaddsbs   v14, v30, v17
        vaddsbs   v0, v15, v18
        vaddsbs   v13, v14, v16
        vslb      v1, v12, v0
        vand128   v0, v0, v63
        vslb      v31, v12, v13
        vand128   v13, v13, v63
        vsububs   v1, v1, v12
        vslb      v29, v11, v0
        vslb      v28, v10, v0
        vslb      v27, v9, v0
        vslb      v26, v8, v0
        vslb      v25, v7, v13
        stvx128   v29, r0, r11
        vslb      v24, v6, v13
        stvx128   v28, r0, r9
        vslb      v23, v5, v13
        stvx128   v27, r0, r8
        vslb      v22, v4, v13
        stvx128   v26, r0, r7
        vsububs   v21, v31, v12
        stvx128   v25, r0, r5
        stvx128   v24, r0, r4
        stvx128   v23, r0, r31
        stvx128   v22, r0, r30
        stvebx    v1, r29, r10
        stvebx    v21, r28, r10
      }
      _R10 += 2;
    }
    v9 += 16;
    v10 += 128;
  }
  while ( v9 < 0x40 );
}

