
// ========================================================================
// InvTransform4x4Stage1_4
// EA  : 0x828FCB40
// RVA : 0x008FCB40
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransforminv_xenon_16.cpp
// ========================================================================

void __fastcall InvTransform4x4Stage1_4(__int16 *p)
{
  _R11 = p + 16;
  __asm { lvx128    v0, r0, r3 }
  _R10 = p + 64;
  __asm { vspltish  v4, 1 }
  _R9 = p + 80;
  __asm { vspltish  v25, 2 }
  _R8 = p + 8;
  _R7 = p + 24;
  __asm { lvx128    v13, r0, r11 }
  _R6 = p + 72;
  __asm { lvx128    v12, r0, r10 }
  _R5 = p + 88;
  __asm
  {
    lvx128    v11, r0, r9
    vmrghh    v10, v0, v13
    vmrglh    v9, v0, v13
    lvx128    v0, r0, r8
    vmrghh    v8, v12, v11
    lvx128    v13, r0, r7
    vmrglh    v7, v12, v11
    lvx128    v12, r0, r6
    lvx128    v11, r0, r5
    vmrghh    v6, v0, v13
    vmrglw128 v62, v10, v9
  }
  __asm
  {
    vmrghw128 v63, v10, v9
    vmrghw128 v61, v8, v7
  }
  _R4 = vmxi_half_1;
  __asm
  {
    vmrglw128 v60, v8, v7
    vmrghh    v3, v12, v11
    vmrglh    v2, v12, v11
    vmrglh    v5, v0, v13
    vmrglw128 v13, v94, v60
    lvx128    v0, r0, r4
    vmrghw128 v11, v95, v61
    vmrghw128 v12, v94, v60
    vmrglw128 v10, v95, v61
    vmrghw128 v55, v3, v2
    vmr128    v49, v13
    vaddshs   v1, v11, v13
    vmrglw128 v54, v3, v2
    vmr128    v58, v11
    vmrghw128 v59, v6, v5
    vmr128    v56, v12
    vmrglw128 v57, v6, v5
    vsubshs   v31, v10, v12
    vmr       v3, v1
    vrlimi128 v58, v11, 0xC, 2
    vmrghw128 v52, v91, v55
    vrlimi128 v56, v12, 0xC, 2
    vmrglw128 v48, v91, v55
    vmr       v2, v31
    vmrghw128 v51, v89, v54
    vaddshs   v30, v3, v0
    vmrglw128 v50, v89, v54
    vmr128    v53, v10
    vor128    v28, v90, v58
    vor128    v7, v88, v56
    vsubshs   v29, v30, v2
    vrlimi128 v53, v10, 0xC, 2
    vrlimi128 v49, v13, 0xC, 2
    vrlimi128 v7, v48, 3, 2
    vrlimi128 v28, v52, 3, 2
    vsrah     v1, v29, v4
    vor128    v5, v84, v52
    vor128    v10, v83, v51
    vaddshs   v11, v28, v7
    vor128    v9, v82, v50
    vor128    v26, v85, v53
    vor128    v6, v81, v49
    vmr       v27, v12
    vspltish  v12, 4
    vsubshs   v8, v1, v13
    vspltish  v13, 3
    vrlimi128 v5, v52, 0xC, 2
    vrlimi128 v10, v51, 0xC, 2
    vrlimi128 v9, v50, 0xC, 2
    vrlimi128 v6, v50, 3, 2
    vrlimi128 v26, v51, 3, 2
    vor128    v24, v80, v48
    vaddshs   v23, v11, v11
    vsrah     v22, v11, v0
    vsubshs   v30, v26, v6
    vrlimi128 v24, v48, 0xC, 2
    vaddshs   v21, v23, v11
    vaddshs   v31, v5, v9
    vaddshs   v5, v30, v0
    vsubshs   v29, v24, v10
    vaddshs   v20, v21, v12
    vsubshs   v7, v7, v22
    vsrah     v19, v5, v0
    vsrah     v28, v29, v0
    vsrah     v18, v20, v13
    vaddshs   v17, v7, v7
    vaddshs   v16, v6, v19
    vaddshs   v6, v10, v28
    vsubshs   v10, v30, v18
    vaddshs   v15, v17, v7
    vaddshs   v14, v2, v8
    vaddshs   v5, v6, v6
    vaddshs   v2, v10, v10
    vaddshs   v30, v15, v12
    vaddshs   v26, v10, v0
    vaddshs   v24, v5, v6
    vaddshs   v23, v2, v10
    vsrah     v22, v30, v13
    vsrah     v21, v26, v0
    vaddshs   v19, v24, v13
    vaddshs   v20, v23, v12
    vsubshs   v5, v16, v22
    vsrah     v30, v31, v0
    vsrah     v15, v19, v13
    vsrah     v17, v20, v13
    vaddshs   v16, v5, v5
    vsubshs   v18, v9, v30
    vsubshs   v1, v1, v27
    vaddshs   v2, v11, v17
    vaddshs   v11, v16, v5
    vsubshs   v27, v3, v1
    vaddshs   v26, v2, v0
    vaddshs   v24, v11, v12
    vrlimi128 v8, v1, 3, 2
    vrlimi128 v27, v14, 3, 2
    vsrah     v23, v26, v0
    vsrah     v22, v24, v13
    vsubshs   v11, v5, v23
    vaddshs   v20, v7, v22
    vmr128    v47, v11
    vsubshs   v0, v21, v20
    vaddshs   v19, v2, v11
    vrlimi128 v47, v11, 0xC, 2
    vsubshs   v17, v10, v0
    vsubshs   v10, v18, v15
    vmr128    v46, v0
    vmr       v9, v19
    vmr       v7, v17
    vaddshs   v16, v10, v10
    vrlimi128 v46, v0, 0xC, 2
    vrlimi128 v0, v11, 3, 2
    vrlimi128 v7, v17, 0xC, 2
    vaddshs   v15, v16, v10
    vrlimi128 v9, v19, 0xC, 2
    vrlimi128 v19, v17, 3, 2
    vrlimi128 v7, v47, 3, 2
    vaddshs   v14, v15, v13
    vrlimi128 v9, v46, 3, 2
    vsubshs   v11, v0, v7
    vsrah     v5, v14, v25
    vsubshs   v3, v19, v9
    vaddshs   v6, v6, v5
    vaddshs   v2, v6, v6
    vsubshs   v0, v28, v6
    vaddshs   v6, v2, v6
    vsubshs   v29, v0, v29
    vaddshs   v1, v6, v12
    vsrah     v28, v1, v13
    vsubshs   v26, v10, v28
    vaddshs   v12, v30, v26
    vsubshs   v13, v31, v12
    vrlimi128 v0, v12, 3, 2
    vrlimi128 v13, v29, 3, 2
    vaddshs   v12, v8, v0
    vaddshs   v10, v27, v13
    vsubshs   v25, v12, v11
    vsubshs   v24, v10, v3
    vsrah     v8, v25, v4
    vsrah     v6, v24, v4
    vsubshs   v23, v8, v7
    vsubshs   v22, v6, v13
    vsubshs   v5, v6, v9
    vsubshs   v7, v8, v0
    vmr       v6, v23
    vmr       v9, v22
    vsubshs   v21, v10, v5
    vaddshs   v20, v11, v7
    vsubshs   v19, v12, v6
    vaddshs   v18, v3, v9
    vmr       v13, v21
    vmr       v12, v20
    vmr       v11, v19
    vmr       v0, v18
    vmr       v10, v5
    vmr       v8, v6
    vrlimi128 v13, v18, 3, 2
    vrlimi128 v12, v19, 0xC, 2
    vrlimi128 v11, v20, 3, 2
    vrlimi128 v0, v21, 0xC, 2
    vrlimi128 v10, v9, 0xC, 2
    vrlimi128 v8, v7, 0xC, 2
    vrlimi128 v9, v5, 3, 2
    vmrghh    v17, v11, v12
    vrlimi128 v7, v6, 3, 2
    vmrghh    v16, v13, v0
    vmrglh    v15, v13, v0
    vmrglh    v14, v11, v12
    vmrghh    v0, v9, v10
    vmrglh    v13, v9, v10
    vmrghh    v12, v7, v8
    vmrglh    v11, v7, v8
    vmrghw128 v45, v16, v15
    vmrghw128 v44, v17, v14
    vmrglw128 v43, v16, v15
    vmrglw128 v42, v17, v14
    vmrghw128 v40, v0, v13
    vmrglw128 v39, v0, v13
    vmrghw128 v38, v12, v11
    vmrglw128 v37, v12, v11
    vmrghw128 v41, v77, v44
    vmrglw128 v36, v77, v44
    vmrghw128 v35, v75, v42
    vmrglw128 v34, v75, v42
    vmrghw128 v33, v72, v38
    vmrglw128 v32, v72, v38
    vmrghw128 v63, v71, v37
    vmrglw128 v62, v71, v37
    stvx128   v41, r0, r3
    stvx128   v36, r0, r11
    stvx128   v35, r0, r10
    stvx128   v34, r0, r9
    stvx128   v33, r0, r8
    stvx128   v32, r0, r7
    stvx128   v63, r0, r6
    stvx128   v62, r0, r5
  }
}


// ========================================================================
// InvTransform4x4Stage1_8
// EA  : 0x828FCEC0
// RVA : 0x008FCEC0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransforminv_xenon_16.cpp
// ========================================================================

void __fastcall InvTransform4x4Stage1_8(__int16 *p0, __int16 *p1)
{
  _R11 = p0 + 16;
  __asm { lvx128    v0, r0, r3 }
  _R10 = p0 + 64;
  __asm { lvx128    v13, r0, r4 }
  _R9 = p0 + 80;
  _R8 = p1 + 16;
  _R7 = p1 + 64;
  _R6 = p1 + 80;
  __asm
  {
    lvx128    v12, r0, r11
    lvx128    v11, r0, r10
  }
  _R28 = p1 + 8;
  __asm
  {
    lvx128    v10, r0, r9
    vmrglh    v30, v0, v12
    lvx128    v9, r0, r8
  }
  _R27 = p1 + 24;
  __asm
  {
    lvx128    v8, r0, r7
    vmrglh    v31, v11, v10
    lvx128    v7, r0, r6
    vmrglh    v2, v13, v9
  }
  _R5 = p0 + 8;
  __asm
  {
    vmrghh    v5, v13, v9
    vmrglh    v3, v8, v7
  }
  _R31 = p0 + 24;
  _R30 = p0 + 72;
  __asm { vmrghh    v6, v0, v12 }
  _R29 = p0 + 88;
  __asm { vmrglw128 v62, v30, v2 }
  _R26 = p1 + 72;
  __asm { vmrghw128 v59, v30, v2 }
  _R25 = p1 + 88;
  __asm
  {
    vmrglw128 v60, v31, v3
    vmrghw128 v58, v31, v3
    lvx128    v13, r0, r28
    lvx128    v9, r0, r27
    vmrghh    v4, v8, v7
    vmrghh    v1, v11, v10
    lvx128    v11, r0, r5
    lvx128    v8, r0, r26
    vmrghh    v29, v13, v9
    lvx128    v10, r0, r31
    vmrglh    v28, v13, v9
    lvx128    v0, r0, r30
  }
  __asm
  {
    lvx128    v12, r0, r29
    vmrghh    v25, v11, v10
    lvx128    v7, r0, r25
    vmrghw128 v9, v94, v60
    vmrghh    v23, v0, v12
  }
  _R24 = vmxi_half_1;
  __asm
  {
    vmrghh    v27, v8, v7
    vmrghw128 v21, v91, v58
    vmrglh    v24, v11, v10
    vmrglh    v26, v8, v7
    vmrghw128 v57, v6, v5
    vmrglh    v22, v0, v12
    vaddshs   v11, v21, v9
    vmrglw128 v63, v6, v5
    lvx128    v0, r0, r24
    vmrghw128 v56, v1, v4
    vmrglw128 v61, v1, v4
    vmrghw128 v55, v25, v29
    vaddshs   v19, v11, v11
    vmrghw128 v51, v23, v27
    vsrah     v15, v11, v0
    vmrglw128 v8, v94, v60
    vmrglw128 v20, v91, v58
    vmrghw128 v5, v95, v61
    vmrglw128 v4, v95, v61
    vmrglw128 v54, v25, v29
    vmrghw128 v53, v24, v28
    vsubshs   v6, v20, v8
    vmrglw128 v52, v24, v28
    vmrglw128 v50, v23, v27
    vmrghw128 v49, v22, v26
    vspltish  v12, 4
    vspltish  v13, 3
    vmrghw128 v18, v89, v56
    vmrglw128 v17, v89, v56
    vmrglw128 v3, v87, v51
    vmrghw128 v16, v87, v51
    vspltish  v10, 1
    vsubshs   v7, v9, v15
    vmrglw128 v48, v22, v26
    vaddshs   v14, v19, v11
    vmrglw128 v2, v86, v50
    vaddshs   v28, v6, v0
    vmrghw128 v27, v86, v50
    vaddshs   v1, v18, v4
    vmrglw128 v24, v85, v49
    vaddshs   v19, v7, v7
    vmrghw128 v31, v84, v48
    vaddshs   v23, v14, v12
    vmrghw128 v22, v85, v49
    vsrah     v21, v28, v0
    vmrglw128 v30, v84, v48
    vsubshs   v29, v17, v5
    vspltish  v20, 2
    vaddshs   v14, v19, v7
    vsrah     v18, v23, v13
    vaddshs   v15, v1, v0
    vaddshs   v17, v8, v21
    vaddshs   v26, v14, v12
    vsubshs   v8, v6, v18
    vsubshs   v6, v15, v29
    vaddshs   v9, v16, v3
    vsrah     v21, v26, v13
    vaddshs   v25, v8, v8
    vsrah     v28, v6, v10
    vaddshs   v23, v9, v9
    vsubshs   v6, v17, v21
    vaddshs   v19, v25, v8
    vsubshs   v16, v28, v4
    vaddshs   v4, v23, v9
    vsubshs   v27, v27, v2
    vsrah     v18, v9, v0
    vaddshs   v14, v6, v6
    vaddshs   v15, v19, v12
    vsubshs   v28, v28, v5
    vsubshs   v5, v3, v18
    vaddshs   v26, v14, v6
    vaddshs   v25, v27, v0
    vaddshs   v23, v4, v12
    vsrah     v3, v15, v13
    vaddshs   v19, v26, v12
    vaddshs   v21, v5, v5
    vsrah     v17, v23, v13
    vsrah     v18, v25, v0
    vsubshs   v25, v24, v31
    vaddshs   v4, v11, v3
    vsubshs   v11, v27, v17
    vaddshs   v14, v21, v5
    vsrah     v3, v19, v13
    vsrah     v27, v25, v0
    vaddshs   v24, v22, v30
    vaddshs   v15, v4, v0
    vaddshs   v22, v14, v12
    vaddshs   v21, v7, v3
    vaddshs   v17, v11, v11
    vaddshs   v7, v31, v27
    vaddshs   v26, v8, v0
    vsrah     v23, v15, v0
    vmr       v3, v16
    vsrah     v16, v22, v13
    vaddshs   v18, v2, v18
    vaddshs   v15, v17, v11
    vaddshs   v14, v7, v7
    vsrah     v19, v26, v0
    vsubshs   v26, v6, v23
    vsubshs   v6, v18, v16
    vaddshs   v22, v15, v12
    vaddshs   v18, v14, v7
    vsrah     v23, v24, v0
    vaddshs   v17, v6, v6
    vsrah     v15, v22, v13
    vaddshs   v16, v11, v0
    vaddshs   v14, v18, v13
    vsubshs   v2, v19, v21
    vaddshs   v31, v9, v15
    vsubshs   v30, v30, v23
    vsrah     v22, v16, v0
    vaddshs   v9, v17, v6
    vsrah     v21, v14, v13
    vaddshs   v18, v31, v0
    vaddshs   v17, v9, v12
    vsubshs   v9, v30, v21
    vsubshs   v19, v1, v28
    vsrah     v15, v18, v0
    vsrah     v14, v17, v13
    vaddshs   v0, v9, v9
    vaddshs   v30, v29, v3
    vsubshs   v6, v6, v15
    vaddshs   v5, v5, v14
    vaddshs   v1, v0, v9
    vsubshs   v8, v8, v2
    vaddshs   v16, v4, v26
    vsubshs   v5, v22, v5
    vaddshs   v29, v1, v13
    vaddshs   v4, v31, v6
    vsubshs   v1, v11, v5
    vsrah     v22, v29, v20
    vsubshs   v29, v8, v5
    vsubshs   v31, v16, v4
    vsubshs   v2, v2, v1
    vaddshs   v0, v7, v22
    vaddshs   v21, v0, v0
    vsubshs   v20, v27, v0
    vsubshs   v27, v26, v6
    vaddshs   v7, v21, v0
    vmr       v0, v20
    vaddshs   v18, v7, v12
    vsubshs   v11, v0, v25
    vaddshs   v3, v3, v0
    vsrah     v17, v18, v13
    vaddshs   v30, v30, v11
    vsubshs   v16, v3, v2
    vsubshs   v15, v9, v17
    vsubshs   v14, v30, v29
    vsrah     v26, v16, v10
    vaddshs   v13, v23, v15
    vsrah     v8, v14, v10
    vsubshs   v23, v26, v1
    vsubshs   v0, v26, v0
    vsubshs   v12, v24, v13
    vaddshs   v28, v28, v13
    vsubshs   v22, v8, v11
    vaddshs   v2, v2, v0
    vaddshs   v7, v19, v12
    vsubshs   v21, v28, v27
    vsubshs   v20, v7, v31
    vsrah     v25, v21, v10
    vsrah     v9, v20, v10
    vsubshs   v19, v25, v6
    vmr       v10, v22
    vsubshs   v11, v9, v4
    vsubshs   v12, v9, v12
    vsubshs   v9, v8, v5
    vsubshs   v8, v25, v13
    vsubshs   v6, v7, v11
    vmr       v13, v23
    vsubshs   v4, v30, v9
    vmr       v7, v19
    vmrglh    v30, v0, v8
    vaddshs   v5, v31, v12
    vaddshs   v1, v29, v10
    vmrghh    v29, v11, v9
    vmrghh    v18, v6, v4
    vsubshs   v3, v3, v13
    vsubshs   v31, v28, v7
    vmrglh    v16, v6, v4
    vaddshs   v6, v27, v8
    vmrglh    v28, v11, v9
    vmrghh    v17, v5, v1
    vmrglh    v15, v5, v1
    vmrghh    v14, v3, v31
    vmrglh    v5, v3, v31
    vmrghh    v4, v2, v6
    vmrglh    v3, v2, v6
    vmrghh    v2, v12, v10
    vmrglh    v1, v12, v10
    vmrghh    v31, v0, v8
    vmrghh    v27, v13, v7
    vmrglh    v26, v13, v7
    vmrghw128 v47, v18, v17
    vmrglw128 v46, v18, v17
    vmrghw128 v45, v16, v15
    vmrglw128 v44, v16, v15
    vmrghw128 v43, v14, v4
    vmrglw128 v42, v14, v4
    vmrghw128 v41, v5, v3
    vmrglw128 v40, v5, v3
    vmrghw128 v39, v2, v29
    vmrglw128 v38, v2, v29
    vmrghw128 v37, v1, v28
    vmrglw128 v36, v1, v28
    vmrghw128 v35, v31, v27
    vmrglw128 v34, v31, v27
    vmrghw128 v33, v30, v26
    vmrglw128 v32, v30, v26
    vmrghw128 v63, v79, v43
    vmrglw128 v62, v79, v43
    vmrghw128 v61, v78, v42
    vmrglw128 v60, v78, v42
    vmrghw128 v59, v77, v41
    vmrglw128 v58, v77, v41
    vmrghw128 v57, v76, v40
    vmrglw128 v56, v76, v40
    stvx128   v63, r0, r3
    vmrghw128 v55, v71, v35
    stvx128   v62, r0, r11
    vmrglw128 v54, v71, v35
    stvx128   v61, r0, r10
    vmrghw128 v53, v70, v34
    stvx128   v60, r0, r9
    vmrglw128 v52, v70, v34
    stvx128   v59, r0, r4
    vmrghw128 v51, v69, v33
    stvx128   v58, r0, r8
    vmrglw128 v50, v69, v33
    stvx128   v57, r0, r7
    vmrghw128 v49, v68, v32
    stvx128   v56, r0, r6
    vmrglw128 v48, v68, v32
    stvx128   v55, r0, r5
    stvx128   v54, r0, r31
    stvx128   v53, r0, r30
    stvx128   v52, r0, r29
    stvx128   v51, r0, r28
    stvx128   v50, r0, r27
    stvx128   v49, r0, r26
    stvx128   v48, r0, r25
  }
}


// ========================================================================
// InvTransform4x4Stage2
// EA  : 0x828FD358
// RVA : 0x008FD358
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransforminv_xenon_16.cpp
// ========================================================================

void __fastcall InvTransform4x4Stage2(__int16 *p)
{
  _R25 = 448;
  __asm { lvx128    v11, r0, r3 }
  _R26 = 352;
  __asm { vspltish  v0, 1 }
  __asm { vspltish  v12, 3 }
  _R29 = 160;
  __asm { vspltish  v10, 5 }
  _R10 = vmxi_half_1;
  __asm
  {
    vspltish  v24, 6
    lvx128    v8, r3, r25
  }
  _R9 = 128;
  __asm { lvx128    v23, r3, r26 }
  _R8 = 96;
  __asm { vsubshs   v1, v23, v8 }
  _R30 = 32;
  __asm { lvx128    v4, r3, r29 }
  _R31 = 128;
  __asm
  {
    lvx128    v13, r0, r10
    vaddshs   v30, v11, v4
    lvx128    v63, r10, r9
  }
  _R4 = 224;
  __asm
  {
    vsrah     v29, v1, v13
    lvx128    v11, r10, r8
  }
  _R5 = 416;
  __asm
  {
    lvx128    v3, r3, r30
    vaddshs   v6, v30, v13
    lvx128    v22, r3, r31
  }
  _R27 = 320;
  __asm
  {
    vsubshs   v9, v22, v3
    vaddshs   v7, v8, v29
  }
  _R28 = 480;
  __asm { lvx128    v17, r3, r4 }
  _R6 = 96;
  __asm
  {
    vand      v20, v6, v0
    lvx128    v16, r3, r5
    vsrah     v18, v6, v0
  }
  _R7 = 384;
  __asm
  {
    vand128   v8, v7, v63
    lvx128    v5, r3, r27
    vsrah     v6, v7, v11
    lvx128    v19, r3, r28
    vmrghh    v25, v16, v17
    vaddshs   v31, v19, v5
    vand      v15, v9, v0
    vspltish  v21, 2
    vaddshs   v14, v8, v8
    lvx128    v23, r3, r6
    vaddshs   v22, v6, v6
    lvx128    v19, r3, r7
    vsrah     v28, v31, v13
  }
  _R8 = 192;
  __asm { vsrah     v2, v9, v0 }
  _R9 = 288;
  __asm { vaddshs   v27, v14, v8 }
  _R10 = 64;
  __asm { vaddshs   v26, v22, v6 }
  _R11 = 256;
  __asm
  {
    vsubshs   v22, v20, v15
    vsubshs   v20, v5, v28
    vaddshs   v17, v27, v12
    vslh      v16, v26, v10
    vsubshs   v15, v18, v2
    vsrah     v14, v22, v0
    vsrah     v8, v17, v12
    vaddshs   v2, v15, v14
    vaddshs   v6, v16, v8
    vsubshs   v27, v2, v4
    vsubshs   v6, v20, v6
    vsubshs   v26, v2, v3
    vaddshs   v22, v9, v27
    vspltish  v9, 4
    vand128   v8, v6, v63
    vsrah     v5, v6, v11
    vaddshs   v4, v8, v8
    vaddshs   v3, v5, v5
    vaddshs   v2, v4, v8
    vaddshs   v20, v3, v5
    vaddshs   v18, v2, v12
    vslh      v17, v20, v24
    vsrah     v16, v18, v21
    vsubshs   v5, v30, v26
    vmrghh    v30, v27, v26
    vaddshs   v26, v17, v16
    vmrghh    v15, v19, v23
    lvx128    v14, r3, r8
    lvx128    v4, r3, r9
    vmrghh    v20, v5, v22
    lvx128    v27, r3, r10
    vaddshs   v7, v7, v26
    vmrghh    v24, v4, v14
    vaddshs   v8, v15, v25
    lvx128    v23, r3, r11
    vmrghw    v18, v20, v30
    vand128   v5, v7, v63
    vmrghh    v21, v23, v27
    vsrah     v4, v7, v11
    vsrah     v19, v8, v13
    vand128   v3, v8, v63
    vaddshs   v15, v5, v5
    vaddshs   v14, v4, v4
    vsrah     v2, v8, v11
    vaddshs   v17, v3, v3
    vaddshs   v30, v15, v5
    vsubshs   v5, v25, v19
    vaddshs   v27, v14, v4
    vaddshs   v16, v2, v2
    vaddshs   v25, v30, v9
    vaddshs   v3, v17, v3
    vslh      v22, v27, v10
    vaddshs   v2, v16, v2
    vsrah     v19, v25, v12
    vaddshs   v26, v3, v9
    vsubshs   v3, v29, v7
    vslh      v20, v2, v10
    vaddshs   v15, v22, v19
    vsrah     v17, v26, v12
    vsubshs   v23, v21, v24
    vsubshs   v16, v3, v1
    vsubshs   v4, v6, v15
    vand128   v6, v5, v63
    vaddshs   v14, v20, v17
    vaddshs   v2, v23, v13
    vaddshs   v4, v28, v4
    vaddshs   v1, v6, v6
    vsubshs   v7, v23, v14
    vsrah     v2, v2, v13
    vsubshs   v28, v31, v4
    vmrghh    v27, v3, v4
    vsrah     v4, v5, v11
    vaddshs   v26, v1, v6
    vand128   v6, v7, v63
    vmrghh    v25, v28, v16
    vaddshs   v29, v24, v2
    vaddshs   v23, v4, v4
    vaddshs   v22, v26, v9
    vaddshs   v21, v6, v6
    vaddshs   v30, v7, v13
    vmrghw    v3, v25, v27
    vaddshs   v20, v23, v4
    vsrah     v4, v7, v11
    vsrah     v19, v22, v12
    vaddshs   v17, v21, v6
    vslh      v16, v20, v10
    vaddshs   v15, v4, v4
    vsrah     v24, v30, v13
    vaddshs   v14, v17, v9
    vaddshs   v6, v16, v19
    vaddshs   v4, v15, v4
    vsrah     v2, v14, v12
    vsubshs   v6, v29, v6
    vslh      v1, v4, v10
    vand128   v4, v6, v63
    vsrah     v11, v6, v11
    vaddshs   v31, v1, v2
    vaddshs   v30, v4, v4
    vaddshs   v29, v11, v11
    vaddshs   v2, v8, v31
    vaddshs   v8, v18, v3
    vaddshs   v28, v30, v4
    vaddshs   v27, v29, v11
    vaddshs   v26, v28, v9
    vsrah     v21, v26, v12
    vslh      v25, v27, v10
    vaddshs   v23, v2, v13
    vand      v22, v8, v0
    vsrah     v20, v8, v0
    vaddshs   v18, v25, v21
    vsrah     v19, v23, v13
    vaddshs   v17, v5, v18
    vsubshs   v13, v6, v19
    vsubshs   v12, v24, v17
    vaddshs   v16, v2, v13
    vsubshs   v15, v7, v12
    vmrghh    v13, v12, v13
    vmrghh    v12, v16, v15
    vmrghh    v14, v12, v13
    vmrghw    v12, v12, v13
    vmr       v13, v14
    vrlimi128 v13, v14, 0xC, 2
    vsubshs   v11, v12, v13
    vand      v10, v11, v0
    vsrah     v9, v11, v0
    vsubshs   v7, v22, v10
    vsubshs   v6, v20, v9
    vsrah     v5, v7, v0
    vaddshs   v0, v6, v5
    vsubshs   v4, v0, v13
    vsubshs   v13, v0, v3
    vmr       v0, v4
    vsplth    v3, v13, 0
    vsplth    v2, v13, 1
    vsplth    v1, v13, 2
    vsubshs   v12, v8, v0
    vsplth    v31, v0, 0
    vsplth    v30, v0, 1
    vsplth    v29, v0, 2
    vsplth    v28, v0, 3
    vaddshs   v0, v11, v13
    vsplth    v27, v12, 0
    vsplth    v26, v12, 1
    vsplth    v25, v12, 2
    vsplth    v24, v12, 3
    vsplth    v23, v0, 0
    vsplth    v22, v0, 1
    vsplth    v21, v0, 2
    vsplth    v20, v0, 3
    stvehx    v27, 0, r3
    stvehx    v26, r3, r31
    vsplth    v19, v13, 3
    stvehx    v25, r3, r30
    stvehx    v24, r3, r29
    stvehx    v23, r3, r7
    stvehx    v22, r3, r11
    stvehx    v21, r3, r5
    stvehx    v20, r3, r9
    stvehx    v3, r3, r6
    stvehx    v2, r3, r4
    stvehx    v1, r3, r10
    stvehx    v19, r3, r8
    stvehx    v31, r3, r28
    stvehx    v30, r3, r26
    stvehx    v29, r3, r25
    stvehx    v28, r3, r27
  }
}


// ========================================================================
// PostFilter4x4Stage1
// EA  : 0x828FD6E8
// RVA : 0x008FD6E8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransforminv_xenon_16.cpp
// ========================================================================

void __fastcall PostFilter4x4Stage1(__int16 *p0, __int16 *p1, __int16 *p2, __int16 *p3)
{
  __asm
  {
    lvlx      v13, r0, r5
    vspltish  v9, 1
    lvlx      v12, r0, r6
  }
  __asm { lvlx      v8, r0, r3 }
  _R10 = 80;
  __asm
  {
    lvlx      v7, r0, r4
    vaddshs   v11, v8, v12
    vsubshs   v10, v7, v13
  }
  _R9 = vmxi_half_1;
  _R8 = 32;
  _R7 = 16;
  _R31 = 48;
  __asm { vsubshs   v6, v11, v10 }
  _R30 = 96;
  __asm { lvx128    v0, r0, r9 }
  _R29 = 64;
  __asm { lvx128    v27, r9, r10 }
  _R11 = 4;
  __asm
  {
    lvx128    v30, r9, r8
    vsrah     v9, v6, v9
    lvx128    v29, r9, r7
    vsubshs   v13, v9, v13
    vsubshs   v12, v9, v12
    vsplth    v31, v13, 3
    vsubshs   v28, v11, v13
    vsplth    v9, v13, 1
    vaddshs   v11, v10, v12
    vsplth    v26, v13, 2
    vsplth    v8, v12, 3
    vaddshs   v7, v31, v13
    vsplth    v10, v12, 1
    vsplth    v1, v12, 2
    vsubshs   v6, v26, v9
    vsplth    v4, v11, 3
    vaddshs   v25, v8, v0
    vsplth    v5, v11, 2
    vsrah     v3, v7, v0
    vsplth    v23, v11, 1
    vaddshs   v24, v10, v0
    vsrah     v2, v6, v0
    vsrah     v18, v25, v0
    vsubshs   v20, v13, v3
    vsrah     v21, v24, v0
    vaddshs   v13, v9, v2
    vaddshs   v19, v4, v0
    vsubshs   v1, v1, v18
    vsubshs   v31, v12, v21
    vaddshs   v16, v13, v13
    vsrah     v17, v19, v0
    vaddshs   v22, v5, v0
    vaddshs   v12, v1, v0
    vaddshs   v14, v16, v13
    vsubshs   v9, v23, v17
    vsrah     v15, v22, v0
    vsrah     v21, v12, v0
    vaddshs   v25, v14, v27
    lvx128    v27, r9, r29
    vaddshs   v26, v9, v0
    vsubshs   v11, v11, v15
    vaddshs   v15, v8, v21
    vsrah     v19, v25, v30
    vsrah     v18, v26, v0
    vmrghh    v23, v11, v9
    vaddshs   v24, v11, v0
    vaddshs   v22, v31, v0
    lvx128    v11, r9, r31
    vsubshs   v12, v20, v19
    vsrah     v16, v24, v0
    vsrah     v17, v22, v0
    vaddshs   v14, v12, v12
    vaddshs   v9, v14, v12
    vaddshs   v8, v9, v29
    vsrah     v26, v8, v29
    lvx128    v29, r9, r30
    vaddshs   v13, v13, v26
    vaddshs   v25, v13, v13
    vsubshs   v24, v13, v2
    vaddshs   v9, v25, v13
    vmr       v13, v24
    vaddshs   v22, v9, v11
    vaddshs   v19, v10, v17
    vmrghh    v21, v1, v15
    vsrah     v17, v22, v30
    vaddshs   v20, v6, v13
    vaddshs   v16, v5, v16
    vmrghh    v15, v31, v19
    vaddshs   v18, v4, v18
    vsubshs   v14, v12, v17
    vmrghh    v10, v16, v18
    vaddshs   v12, v14, v3
    vmrghw    v9, v15, v21
    vmrghw    v8, v23, v10
    vsubshs   v7, v7, v12
    vmrghh    v6, v12, v13
    vsubshs   v10, v8, v9
    vmrghh    v5, v20, v7
    vsrah     v4, v10, v0
    vmrghw    v13, v6, v5
    vaddshs   v12, v28, v13
    vsrah     v3, v12, v0
    vsubshs   v13, v3, v13
    vaddshs   v2, v13, v13
    vaddshs   v1, v2, v13
    vaddshs   v31, v1, v29
    vsrah     v30, v31, v11
    vaddshs   v12, v12, v30
    vaddshs   v28, v12, v12
    vaddshs   v26, v28, v12
    vaddshs   v25, v26, v11
    vsrah     v24, v25, v27
    vaddshs   v13, v13, v24
    vaddshs   v23, v13, v13
    vsubshs   v22, v13, v4
    vaddshs   v21, v23, v13
    vaddshs   v20, v21, v29
    vsrah     v19, v20, v11
    vaddshs   v12, v12, v19
    vsubshs   v18, v12, v10
    vsrah     v17, v18, v0
    vmr       v0, v22
    vsubshs   v13, v17, v9
    vaddshs   v16, v10, v0
    vspltw128 v63, v0, 0
    vspltw128 v62, v0, 1
    vsubshs   v15, v12, v13
    vspltw128 v61, v13, 0
    vspltw128 v59, v16, 0
    vspltw128 v58, v16, 1
    vspltw128 v60, v13, 1
    vspltw128 v57, v15, 0
    vspltw128 v56, v15, 1
    stvewx128 v57, r0, r3
    stvewx128 v56, r3, r11
    stvewx128 v59, r0, r4
    stvewx128 v58, r4, r11
    stvewx128 v63, r0, r5
    stvewx128 v62, r5, r11
    stvewx128 v61, r0, r6
    stvewx128 v60, r6, r11
  }
}


// ========================================================================
// PostFilter4x4Stage1_4
// EA  : 0x828FD928
// RVA : 0x008FD928
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransforminv_xenon_16.cpp
// ========================================================================

void __fastcall PostFilter4x4Stage1_4(
        __int16 *p0,
        __int16 *p1,
        __int16 *p2,
        __int16 *p3,
        __int16 *p4,
        __int16 *p5,
        __int16 *p6,
        __int16 *p7)
{
  _R31 = p5;
  __asm { vspltish  v10, 1 }
  _R30 = p6;
  _R29 = p7;
  _R10 = 8;
  _R8 = 128;
  _R11 = 24;
  _R9 = 144;
  __asm { lvlx128   v63, r10, r6 }
  _R27 = 80;
  __asm { lvlx      v0, r10, r4 }
  _R28 = vmxi_half_1;
  __asm
  {
    lvlx128   v62, r8, r6
    vrlimi128 v0, v63, 3, 2
    lvlx      v13, r8, r4
  }
  _R26 = 32;
  __asm
  {
    lvlx128   v61, r11, r5
    vrlimi128 v13, v62, 3, 2
    lvlx      v9, r11, r3
    lvlx128   v60, r9, r5
    vrlimi128 v9, v61, 3, 2
    lvlx      v8, r9, r3
    lvlx128   v59, r10, r29
    vrlimi128 v8, v60, 3, 2
    lvlx      v12, r10, r31
    lvlx128   v58, r8, r29
    vrlimi128 v12, v59, 3, 2
    lvlx      v11, r8, r31
    vaddshs   v9, v9, v13
    lvlx128   v57, r11, r30
    vrlimi128 v11, v58, 3, 2
    lvlx      v7, r11, r7
    vsubshs   v8, v8, v0
    lvlx128   v56, r9, r30
    vrlimi128 v7, v57, 3, 2
    lvlx      v6, r9, r7
    vrlimi128 v6, v56, 3, 2
    lvx128    v3, r28, r27
    vsubshs   v5, v9, v8
    lvx128    v28, r28, r26
    vaddshs   v7, v7, v11
    vsubshs   v6, v6, v12
    vsrah     v5, v5, v10
    vsubshs   v4, v7, v6
    vsubshs   v2, v5, v13
    vsubshs   v13, v5, v0
    vsrah     v10, v4, v10
    vmr       v0, v2
    vsubshs   v26, v9, v13
    vsubshs   v1, v10, v11
    vsubshs   v11, v10, v12
    vaddshs   v10, v8, v0
    vmr       v12, v1
    vsubshs   v25, v7, v11
    vmrghh    v8, v13, v11
    vmrglh    v7, v13, v11
    vaddshs   v9, v6, v12
    vmrghh    v4, v0, v12
    vmrglh    v12, v0, v12
    lvx128    v0, r0, r28
    vmrghh    v13, v8, v7
    vmrglh    v6, v8, v7
    vmrghh    v11, v10, v9
    vmrglh    v10, v10, v9
    vmrghh    v5, v4, v12
    vmrglh    v4, v4, v12
    vmr       v31, v6
    vmrglh    v12, v11, v10
    vmrghh    v7, v11, v10
    vmr       v11, v13
    vmr       v9, v5
    vrlimi128 v31, v6, 0xC, 2
    vmr       v8, v4
    vrlimi128 v11, v13, 0xC, 2
    vmr       v10, v12
    vaddshs   v29, v12, v0
    vrlimi128 v9, v5, 0xC, 2
    vsubshs   v1, v6, v11
    vrlimi128 v8, v4, 0xC, 2
    vaddshs   v2, v31, v13
    vsrah     v30, v1, v0
  }
  _R9 = 16;
  __asm { vaddshs   v23, v8, v0 }
  _R8 = 48;
  __asm { vsrah     v31, v2, v0 }
  _R27 = 96;
  __asm
  {
    vaddshs   v22, v9, v0
    vaddshs   v11, v11, v30
    vsrah     v20, v23, v0
    lvx128    v27, r28, r9
    vsrah     v24, v29, v0
    vrlimi128 v10, v12, 0xC, 2
    vaddshs   v21, v11, v11
    vsubshs   v6, v4, v20
    vsubshs   v19, v13, v31
    lvx128    v13, r28, r8
    vmr       v18, v7
    vaddshs   v17, v21, v11
    vsrah     v16, v22, v0
    vsubshs   v15, v7, v24
    vaddshs   v29, v10, v0
    vaddshs   v14, v17, v3
    lvx128    v3, r28, r27
    vrlimi128 v18, v7, 0xC, 2
    vsubshs   v5, v5, v16
    vmr       v7, v15
    vsrah     v4, v14, v28
    vsrah     v22, v29, v0
    vaddshs   v23, v5, v0
    vaddshs   v24, v7, v0
    vsubshs   v4, v19, v4
    vsubshs   v29, v18, v22
    vsrah     v21, v23, v0
    vsrah     v20, v24, v0
    vaddshs   v19, v4, v4
    vaddshs   v16, v29, v0
    vaddshs   v18, v9, v21
    vaddshs   v9, v12, v20
    vaddshs   v17, v19, v4
    vsrah     v12, v16, v0
    vrlimi128 v5, v18, 3, 2
    vaddshs   v15, v6, v0
    vaddshs   v14, v17, v27
    vaddshs   v22, v10, v12
    vrlimi128 v7, v29, 3, 2
    vsrah     v24, v15, v0
    vsrah     v23, v14, v27
    vrlimi128 v9, v22, 3, 2
    vaddshs   v21, v8, v24
    vaddshs   v12, v11, v23
    vrlimi128 v6, v21, 3, 2
    vaddshs   v20, v12, v12
    vsubshs   v10, v12, v30
    vmrghh    v8, v5, v6
    vaddshs   v12, v20, v12
    vmrglh    v6, v5, v6
    vaddshs   v11, v1, v10
    vmrghh    v5, v7, v9
    vmrglh    v9, v7, v9
    vaddshs   v19, v12, v13
    vmrghh    v1, v8, v6
    vmrglh    v6, v8, v6
    vmrghh    v17, v5, v9
    vsrah     v18, v19, v28
    vsubshs   v8, v17, v1
    vsubshs   v16, v4, v18
    vaddshs   v12, v16, v31
    vmrglh    v31, v5, v9
    vsubshs   v15, v2, v12
    vrlimi128 v12, v10, 3, 2
    vrlimi128 v11, v15, 3, 2
    vmrghh    v10, v12, v11
    vmrglh    v12, v12, v11
    vmrghh    v11, v10, v12
    vmrglh    v10, v10, v12
    vaddshs   v4, v26, v11
    vaddshs   v2, v25, v10
    vsrah     v14, v4, v0
    vsubshs   v12, v14, v11
    vaddshs   v11, v12, v12
    vaddshs   v7, v11, v12
    vsrah     v28, v2, v0
  }
  _R27 = 64;
  __asm { vaddshs   v30, v7, v3 }
  _R8 = 152;
  __asm { vsrah     v29, v8, v0 }
  _R9 = 136;
  __asm
  {
    vsubshs   v7, v31, v6
    vsubshs   v10, v28, v10
    vsrah     v27, v30, v13
    lvx128    v5, r28, r27
    vsrah     v26, v7, v0
    vaddshs   v25, v10, v10
    vaddshs   v11, v4, v27
    vaddshs   v23, v25, v10
    vaddshs   v24, v11, v11
    vaddshs   v21, v23, v3
    vaddshs   v22, v24, v11
    vsrah     v19, v21, v13
    vaddshs   v20, v22, v13
    vaddshs   v9, v2, v19
    vsrah     v18, v20, v5
    vaddshs   v17, v9, v9
    vaddshs   v12, v12, v18
    vaddshs   v14, v17, v9
    vaddshs   v16, v12, v12
    vsubshs   v15, v12, v29
    vaddshs   v4, v14, v13
    vaddshs   v12, v16, v12
    vsrah     v31, v4, v5
    vaddshs   v2, v12, v3
    vaddshs   v12, v10, v31
    vsrah     v30, v2, v13
    vaddshs   v29, v12, v12
    vsubshs   v27, v12, v26
    vaddshs   v5, v11, v30
    vaddshs   v26, v29, v12
    vmr       v12, v15
    vsubshs   v28, v5, v8
    vaddshs   v24, v26, v3
    vaddshs   v23, v8, v12
    vsldoi128 v55, v12, v12, 8
    vsrah     v25, v28, v0
    vsrah     v22, v24, v13
    vsldoi128 v53, v23, v23, 8
    vsubshs   v11, v25, v1
    vaddshs   v10, v9, v22
    vsubshs   v21, v5, v11
    vsldoi128 v54, v11, v11, 8
    vsubshs   v20, v10, v7
    vsldoi128 v52, v21, v21, 8
    stvlx     v21, r3, r11
    vsrah     v19, v20, v0
    vmr       v0, v27
    vsubshs   v13, v19, v6
    vaddshs   v18, v7, v0
    stvlx128  v52, r5, r11
    stvrx128  v53, r3, r8
    vsldoi128 v51, v0, v0, 8
    stvrx     v23, r5, r8
    vsubshs   v17, v10, v13
    stvlx     v12, r4, r10
    vsldoi128 v49, v18, v18, 8
    stvlx128  v55, r6, r10
    stvrx128  v54, r4, r9
    vsldoi128 v50, v13, v13, 8
    stvrx     v11, r6, r9
    vsldoi128 v48, v17, v17, 8
    stvlx     v17, r7, r11
    stvlx128  v48, r30, r11
    stvrx128  v49, r7, r8
    stvrx     v18, r30, r8
    stvlx     v0, r31, r10
    stvlx128  v51, r29, r10
    stvrx128  v50, r31, r9
    stvrx     v13, r29, r9
  }
}


// ========================================================================
// PostFilter4x4Stage1_8
// EA  : 0x828FDCE8
// RVA : 0x008FDCE8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransforminv_xenon_16.cpp
// ========================================================================

void __fastcall PostFilter4x4Stage1_8(
        __int16 *p0,
        __int16 *p1,
        __int16 *p2,
        __int16 *p3,
        __int16 *p4,
        __int16 *p5,
        __int16 *p6,
        __int16 *p7,
        int ofs,
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
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  _R31 = p1 + 4;
  _R30 = p0 + 12;
  __asm { vspltish  v0, 1 }
  _R22 = 2 * a28;
  _R4 = p1 + 64;
  _R3 = p0 + 72;
  __asm { lvlx      v13, r0, r31 }
  _R29 = p3 + 4;
  __asm { lvlx      v10, r0, r30 }
  _R28 = p2 + 12;
  __asm { lvlx128   v61, r22, r30 }
  _R6 = p3 + 64;
  __asm
  {
    lvlx128   v62, r22, r4
    vrlimi128 v10, v61, 3, 2
    lvlx      v12, r0, r4
  }
  _R5 = p2 + 72;
  __asm
  {
    lvlx128   v63, r22, r31
    vrlimi128 v12, v62, 3, 2
    lvlx128   v60, r22, r3
    vrlimi128 v13, v63, 3, 2
    lvlx      v9, r0, r3
  }
  _R27 = p5 + 4;
  __asm
  {
    vrlimi128 v9, v60, 3, 2
    lvlx128   v59, r22, r29
    vaddshs   v5, v10, v12
    lvlx      v11, r0, r29
    lvlx128   v58, r22, r6
    vrlimi128 v11, v59, 3, 2
    lvlx      v10, r0, r6
  }
  _R26 = p7 + 4;
  __asm
  {
    lvlx128   v57, r22, r28
    vsubshs   v4, v9, v13
    lvlx      v8, r0, r28
    vrlimi128 v10, v58, 3, 2
    lvlx128   v56, r22, r5
    vrlimi128 v8, v57, 3, 2
    lvlx      v7, r0, r5
  }
  _R25 = p4 + 12;
  __asm { vrlimi128 v7, v56, 3, 2 }
  _R24 = p6 + 12;
  __asm { vsubshs   v6, v5, v4 }
  _R8 = p5 + 64;
  __asm { vaddshs   v3, v8, v10 }
  _R10 = p7 + 64;
  _R7 = p4 + 72;
  __asm
  {
    lvlx128   v55, r22, r27
    vsubshs   v2, v7, v11
  }
  _R9 = p6 + 72;
  __asm
  {
    vsrah     v1, v6, v0
    lvlx      v9, r0, r27
    lvlx128   v54, r22, r8
    vrlimi128 v9, v55, 3, 2
    lvlx      v8, r0, r8
    vsubshs   v31, v3, v2
    lvlx128   v53, r22, r26
    vsubshs   v30, v1, v12
    lvlx      v7, r0, r26
    vsubshs   v12, v1, v13
    lvlx128   v52, r22, r10
    lvlx      v6, r0, r10
    vrlimi128 v8, v54, 3, 2
    vsrah     v1, v31, v0
    lvlx128   v51, r22, r25
    vmr       v13, v30
    lvlx      v29, r0, r25
    lvlx128   v50, r22, r7
    vrlimi128 v7, v53, 3, 2
    lvlx      v28, r0, r7
    vrlimi128 v6, v52, 3, 2
    vsubshs   v10, v1, v10
    lvlx128   v49, r22, r24
    lvlx      v27, r0, r24
    vaddshs   v4, v4, v13
    lvlx128   v48, r22, r9
    vsubshs   v26, v5, v12
    vsubshs   v11, v1, v11
    vrlimi128 v29, v51, 3, 2
    vrlimi128 v28, v50, 3, 2
    vaddshs   v31, v2, v10
    vrlimi128 v27, v49, 3, 2
    lvlx      v25, r0, r9
    vaddshs   v1, v27, v6
    vrlimi128 v25, v48, 3, 2
    vmrghh    v24, v13, v10
    vaddshs   v5, v29, v8
    vmrglh    v23, v13, v10
    vsubshs   v2, v28, v9
    vmrghh    v20, v12, v11
    vmrglh    v18, v12, v11
  }
  __asm
  {
    vsubshs   v30, v25, v7
    vmrghh    v22, v4, v31
    vsubshs   v25, v3, v11
    vmrghw128 v47, v24, v23
    vsubshs   v19, v5, v2
    vmrglw128 v46, v24, v23
    vmrglh    v21, v4, v31
  }
  _R11 = vmxi_half_1;
  __asm
  {
    vsubshs   v17, v1, v30
    vmrghw128 v43, v20, v18
    vmrglw128 v42, v20, v18
  }
  _R21 = 80;
  __asm { vsrah     v13, v19, v0 }
  _R20 = 32;
  __asm { vmrglw128 v45, v22, v21 }
  _R19 = 96;
  __asm
  {
    vsrah     v10, v17, v0
    vmrghw128 v44, v22, v21
    vsubshs   v0, v13, v8
    lvx128    v29, r11, r21
    vsubshs   v13, v13, v9
  }
  _R21 = 16;
  __asm
  {
    vsubshs   v16, v10, v6
    vsubshs   v9, v10, v7
    vaddshs   v8, v2, v0
    vsubshs   v24, v5, v13
    vmr       v10, v16
    vmrghh    v15, v13, v9
    vsubshs   v23, v1, v9
    vmrglh    v14, v13, v9
    vaddshs   v7, v30, v10
    vmrglh    v12, v0, v10
    vmrghh    v13, v0, v10
    lvx128    v0, r0, r11
    vmrghw128 v41, v15, v14
    lvx128    v30, r11, r20
    vmrglw128 v40, v15, v14
  }
  _R20 = 48;
  __asm
  {
    vmrghh    v11, v8, v7
    vmrglh    v10, v8, v7
    vmrglw128 v37, v13, v12
    vmrghw128 v38, v13, v12
    vmr128    v39, v11
    vmrghw128 v9, v74, v40
    vmrglw128 v11, v75, v41
    vmrglw128 v5, v78, v37
    vmrglw128 v6, v79, v38
    vmrglw128 v36, v71, v10
    vmrghw128 v35, v71, v10
    vsubshs   v3, v9, v11
    vaddshs   v1, v5, v0
    vmrghw128 v4, v75, v41
    vaddshs   v8, v6, v0
    vmrglw128 v19, v74, v40
    vmrglw128 v7, v77, v36
    vmrghw128 v10, v77, v36
    vmrglw128 v2, v76, v35
    vsrah     v18, v1, v0
    vmrghw128 v20, v76, v35
    vsrah     v27, v8, v0
    vaddshs   v28, v7, v0
    vmrghw128 v17, v78, v37
    vaddshs   v31, v10, v0
    vmrghw128 v16, v79, v38
    vsrah     v1, v3, v0
    vsrah     v21, v28, v0
    vsrah     v22, v31, v0
    vsubshs   v8, v17, v18
    vsubshs   v12, v2, v21
    vsubshs   v9, v20, v22
    vaddshs   v2, v19, v4
    vaddshs   v11, v11, v1
    vmrghh    v14, v9, v12
    vaddshs   v15, v9, v0
    vmrglh    v9, v9, v12
    vaddshs   v28, v8, v0
    vsrah     v31, v2, v0
    vaddshs   v22, v11, v11
    vsrah     v21, v15, v0
    vmrghw128 v34, v14, v9
    vsrah     v19, v28, v0
    vmrglw128 v33, v14, v9
    vsubshs   v20, v4, v31
    vaddshs   v18, v22, v11
    vaddshs   v4, v10, v21
    vsubshs   v13, v16, v27
    vaddshs   v16, v12, v0
    lvx128    v12, r11, r19
    vaddshs   v17, v18, v29
    vaddshs   v5, v5, v19
    vaddshs   v15, v13, v0
    vsrah     v22, v16, v0
    vsrah     v28, v17, v30
    vmrghh    v29, v8, v5
    vmrglh    v27, v8, v5
    lvx128    v8, r11, r21
    vsrah     v21, v15, v0
  }
  _R21 = 64;
  __asm
  {
    vsubshs   v10, v20, v28
    vaddshs   v7, v7, v22
    vmrghw128 v32, v29, v27
    vaddshs   v6, v6, v21
    vmrglw128 v63, v29, v27
    vaddshs   v20, v10, v10
    vmrghh    v19, v4, v7
    vmrglh    v15, v4, v7
    vmrghh    v18, v13, v6
    vaddshs   v16, v20, v10
    vmrglh    v17, v13, v6
    lvx128    v13, r11, r20
    vmrghw128 v60, v19, v15
    vmrglw128 v59, v19, v15
    vaddshs   v14, v16, v8
    vmrghw128 v62, v18, v17
    vmrglw128 v61, v18, v17
    vmrghw128 v7, v66, v60
    vmrglw128 v18, v66, v60
    vsrah     v9, v14, v8
    vmrglw128 v29, v94, v32
    vmrghw128 v28, v93, v63
    vmrghw128 v17, v65, v59
    vmrglw128 v27, v93, v63
    vaddshs   v11, v11, v9
    vaddshs   v6, v11, v11
    vsubshs   v5, v11, v1
    vmrghw128 v1, v94, v32
    vaddshs   v8, v6, v11
    vmr       v11, v5
    vsubshs   v4, v7, v1
    vaddshs   v22, v8, v13
    vaddshs   v9, v3, v11
    vsubshs   v3, v18, v29
    vsrah     v19, v4, v0
    vsrah     v21, v22, v30
    vsrah     v22, v3, v0
    vsubshs   v20, v10, v21
    vaddshs   v10, v20, v31
    vsubshs   v8, v2, v10
    vmrghh    v16, v10, v11
    vmrglh    v15, v10, v11
    vsubshs   v2, v17, v28
    vmrglh    v11, v9, v8
    vmrghh    v14, v9, v8
    lvx128    v9, r11, r21
    vmrghw128 v58, v16, v15
    vsrah     v21, v2, v0
    vmrglw128 v57, v16, v15
    vmrghw128 v56, v14, v11
    vmrglw128 v55, v14, v11
    vmrghw128 v11, v90, v56
    vmrglw128 v8, v90, v56
    vmrghw128 v7, v89, v55
    vaddshs   v10, v26, v11
    vmrglw128 v31, v89, v55
    vaddshs   v6, v25, v8
  }
  __asm { vaddshs   v5, v24, v7 }
  _R11 = 8;
  _R23 = 2 * (a28 + 4);
  __asm
  {
    vsrah     v20, v10, v0
    vsrah     v18, v6, v0
    vsrah     v17, v5, v0
    vsubshs   v11, v20, v11
    vsubshs   v8, v18, v8
    vsubshs   v7, v17, v7
    vaddshs   v16, v11, v11
    vaddshs   v15, v8, v8
    vaddshs   v14, v7, v7
    vaddshs   v30, v16, v11
    vaddshs   v26, v15, v8
    vaddshs   v25, v14, v7
    vaddshs   v24, v30, v12
    vaddshs   v20, v26, v12
    vaddshs   v18, v25, v12
    vsrah     v17, v24, v13
    vsrah     v16, v20, v13
    vsrah     v15, v18, v13
    vaddshs   v10, v10, v17
    vaddshs   v6, v6, v16
    vaddshs   v5, v5, v15
    vaddshs   v14, v10, v10
    vaddshs   v30, v6, v6
    vaddshs   v26, v5, v5
    vaddshs   v25, v14, v10
    vaddshs   v24, v30, v6
    vaddshs   v20, v26, v5
    vaddshs   v18, v25, v13
    vaddshs   v17, v24, v13
    vaddshs   v16, v20, v13
    vsrah     v15, v18, v9
    vsrah     v14, v17, v9
    vsrah     v30, v16, v9
    vaddshs   v11, v11, v15
    vaddshs   v8, v8, v14
    vaddshs   v7, v7, v30
    vaddshs   v26, v11, v11
    vsubshs   v25, v11, v19
    vaddshs   v24, v8, v8
    vaddshs   v20, v7, v7
    vaddshs   v19, v26, v11
    vmr       v11, v25
    vaddshs   v18, v24, v8
    vaddshs   v17, v20, v7
    vaddshs   v16, v19, v12
    vaddshs   v15, v4, v11
    vsldoi128 v54, v11, v11, 8
    vaddshs   v26, v18, v12
    vaddshs   v25, v17, v12
    vsrah     v14, v16, v13
    vsldoi128 v51, v15, v15, 8
    vsubshs   v8, v8, v22
    vsrah     v20, v26, v13
    vsrah     v19, v25, v13
    vaddshs   v30, v10, v14
    vaddshs   v5, v5, v19
    vsubshs   v10, v30, v4
    vsubshs   v16, v5, v2
    vsrah     v4, v10, v0
    vsubshs   v10, v4, v1
    vsubshs   v1, v30, v10
    vsldoi128 v53, v10, v10, 8
    vaddshs   v30, v23, v31
    vmrglw128 v23, v65, v59
    vsldoi128 v52, v1, v1, 8
    stvlx     v1, r0, r30
    vsrah     v24, v30, v0
    vaddshs   v1, v6, v20
    vsubshs   v4, v23, v27
    vsubshs   v18, v24, v31
    vsubshs   v17, v1, v3
    stvlx128  v52, r30, r22
    vmr       v6, v18
    vaddshs   v14, v6, v6
    vsrah     v26, v16, v0
    stvrx128  v51, r3, r11
    vaddshs   v25, v14, v6
    stvrx     v15, r3, r23
    stvlx     v11, r0, r31
    vsrah     v31, v17, v0
    stvlx128  v54, r31, r22
    vsubshs   v7, v7, v21
    vsubshs   v24, v26, v28
    stvrx128  v53, r4, r11
    vaddshs   v23, v25, v12
    stvrx     v10, r4, r23
    vsubshs   v11, v31, v29
    vsldoi128 v50, v8, v8, 8
    vaddshs   v17, v2, v7
    vsldoi128 v48, v7, v7, 8
    vmr       v10, v24
    vsrah     v22, v23, v13
    vsubshs   v21, v1, v11
    vsldoi128 v49, v11, v11, 8
    vaddshs   v18, v3, v8
    vsldoi128 v44, v17, v17, 8
    vsubshs   v20, v5, v10
    vsldoi128 v43, v10, v10, 8
    vaddshs   v5, v30, v22
    vsrah     v19, v4, v0
    vsldoi128 v47, v21, v21, 8
    vsldoi128 v45, v18, v18, 8
    stvlx     v21, r0, r28
    vsldoi128 v46, v20, v20, 8
    vaddshs   v16, v5, v5
    vaddshs   v15, v16, v5
    stvlx128  v47, r28, r22
    stvrx128  v45, r5, r11
    stvrx     v18, r5, r23
    stvlx     v8, r0, r29
    vaddshs   v14, v15, v13
    stvlx128  v50, r29, r22
    stvrx128  v49, r6, r11
    stvrx     v11, r6, r23
    stvlx     v20, r0, r25
    vsrah     v9, v14, v9
    stvlx128  v46, r25, r22
    stvrx128  v44, r7, r11
    stvrx     v17, r7, r23
    stvlx     v7, r0, r27
    vaddshs   v9, v6, v9
    stvlx128  v48, r27, r22
    stvrx128  v43, r8, r11
    stvrx     v10, r8, r23
    vaddshs   v6, v9, v9
    vsubshs   v3, v9, v19
    vaddshs   v2, v6, v9
    vaddshs   v1, v2, v12
    vsrah     v31, v1, v13
    vaddshs   v12, v5, v31
    vsubshs   v30, v12, v4
    vsrah     v29, v30, v0
    vmr       v0, v3
    vsubshs   v13, v29, v27
    vaddshs   v27, v4, v0
    vsldoi128 v42, v0, v0, 8
    vsubshs   v28, v12, v13
    vsldoi128 v41, v13, v13, 8
    vsldoi128 v39, v27, v27, 8
    vsldoi128 v40, v28, v28, 8
    stvlx     v28, r0, r24
    stvlx128  v40, r24, r22
    stvrx128  v39, r9, r11
    stvrx     v27, r9, r23
    stvlx     v0, r0, r26
    stvlx128  v42, r26, r22
    stvrx128  v41, r10, r11
    stvrx     v13, r10, r23
  }
}


// ========================================================================
// PostFilter2x4Stage1
// EA  : 0x828FE330
// RVA : 0x008FE330
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransforminv_xenon_16.cpp
// ========================================================================

void __fastcall PostFilter2x4Stage1(__int16 *pa, __int16 *pb)
{
  _R11 = 8;
  __asm { lvlx128   v63, r0, r4 }
  __asm { vpkuwum128 v13, v95, v63 }
  _R9 = 112;
  _R8 = vmxi_half_1;
  __asm { vsldoi128 v62, v95, v63, 0xE }
  _R7 = 64;
  __asm { lvlx128   v61, r11, r3 }
  _R6 = 96;
  _R5 = 48;
  __asm { vpkuwum128 v9, v93, v61 }
  _R10 = 12;
  __asm
  {
    vsldoi128 v60, v93, v61, 0xE
    lvx128    v0, r0, r8
    vpkuwum128 v10, v94, v63
    lvx128    v12, r8, r9
    lvx128    v11, r8, r7
  }
  _R9 = 4;
  __asm
  {
    vaddshs   v9, v9, v13
    lvx128    v5, r8, r6
    vpkuwum128 v8, v92, v61
    lvx128    v4, r8, r5
    vaddshs   v7, v9, v0
    vaddshs   v8, v8, v10
    vsrah     v7, v7, v0
    vaddshs   v3, v8, v0
    vsubshs   v6, v13, v7
    vsrah     v13, v3, v0
    vaddshs   v2, v6, v0
    vsubshs   v1, v10, v13
    vsrah     v31, v2, v0
    vsubshs   v10, v1, v31
    vaddshs   v30, v10, v0
    vaddshs   v13, v10, v13
    vsrah     v29, v30, v0
    vaddshs   v28, v13, v13
    vaddshs   v27, v6, v29
    vaddshs   v26, v28, v13
    vaddshs   v0, v27, v7
    vaddshs   v25, v26, v12
    vaddshs   v24, v0, v0
    vsrah     v23, v25, v11
    vaddshs   v22, v24, v0
    vsubshs   v21, v13, v23
    vaddshs   v20, v22, v12
    vsubshs   v10, v8, v21
    vsrah     v19, v20, v11
    vaddshs   v18, v10, v10
    vsubshs   v17, v0, v19
    vaddshs   v16, v18, v10
    vsubshs   v9, v9, v17
    vaddshs   v15, v16, v5
    vaddshs   v14, v9, v9
    vsrah     v8, v15, v4
    vaddshs   v7, v14, v9
    vaddshs   v13, v13, v8
    vaddshs   v6, v7, v5
    vaddshs   v5, v13, v13
    vsrah     v4, v6, v4
    vaddshs   v3, v5, v13
    vaddshs   v0, v0, v4
    vaddshs   v2, v3, v12
    vaddshs   v1, v0, v0
    vmrghh    v31, v13, v0
    vsrah     v30, v2, v11
    vaddshs   v29, v1, v0
    vspltw128 v59, v31, 0
    vaddshs   v28, v10, v30
    vspltw128 v58, v31, 1
    vaddshs   v27, v29, v12
    vsrah     v26, v27, v11
    vaddshs   v25, v9, v26
    vmrghh    v24, v28, v25
    vspltw128 v57, v24, 0
    vspltw128 v56, v24, 1
    stvewx128 v57, r3, r11
    stvewx128 v56, r3, r10
    stvewx128 v59, r0, r4
    stvewx128 v58, r4, r9
  }
}


// ========================================================================
// PostFilter2x4Stage1_4
// EA  : 0x828FE478
// RVA : 0x008FE478
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransforminv_xenon_16.cpp
// ========================================================================

void __fastcall PostFilter2x4Stage1_4(
        __int16 *pa,
        __int16 *pb,
        __int16 *pc,
        __int16 *pd,
        __int16 *pe,
        __int16 *pf,
        __int16 *pg,
        __int16 *ph)
{
  _R30 = ph;
  __asm { lvlx128   v63, r0, r6 }
  _R11 = 8;
  __asm { lvlx      v13, r0, r4 }
  _R31 = pg;
  __asm
  {
    lvlx      v12, r0, r8
    vrlimi128 v13, v63, 3, 2
  }
  _R9 = 112;
  __asm { lvlx128   v62, r0, r30 }
  _R29 = vmxi_half_1;
  __asm
  {
    lvlx128   v61, r11, r5
    vrlimi128 v12, v62, 3, 2
    lvlx      v11, r11, r3
  }
  _R10 = 64;
  __asm
  {
    lvlx128   v60, r11, r31
    vrlimi128 v11, v61, 3, 2
    lvlx      v10, r11, r7
  }
  _R28 = 96;
  __asm
  {
    vrlimi128 v10, v60, 3, 2
    vmrghh    v8, v13, v12
    vmrglh    v13, v13, v12
    lvx128    v0, r0, r29
    lvx128    v12, r29, r9
  }
  _R27 = 48;
  __asm { lvx128    v9, r29, r10 }
  _R9 = 12;
  __asm { vmrglh    v7, v11, v10 }
  _R10 = 4;
  __asm
  {
    vmrghh    v11, v11, v10
    vmrghh    v10, v8, v13
    vmrglh    v13, v8, v13
    vmrglh    v8, v11, v7
    vmrghh    v11, v11, v7
    vmrglh    v7, v10, v13
    vmrghh    v13, v10, v13
    vmrglh    v10, v11, v8
    vmrghh    v8, v11, v8
    vaddshs   v10, v10, v7
    vaddshs   v11, v8, v13
    vaddshs   v6, v10, v0
    vaddshs   v5, v11, v0
    vsrah     v8, v6, v0
    vsrah     v6, v5, v0
    vsubshs   v7, v7, v8
    vsubshs   v4, v13, v6
    vaddshs   v3, v7, v0
    vsrah     v2, v3, v0
    vsubshs   v13, v4, v2
    vaddshs   v1, v13, v0
    vaddshs   v13, v13, v6
    vsrah     v31, v1, v0
    vaddshs   v30, v13, v13
    vaddshs   v29, v7, v31
    lvx128    v7, r29, r27
    vaddshs   v28, v30, v13
    vaddshs   v0, v29, v8
    lvx128    v8, r29, r28
    vaddshs   v27, v28, v12
    vaddshs   v26, v0, v0
    vsrah     v25, v27, v9
    vaddshs   v24, v26, v0
    vsubshs   v23, v13, v25
    vaddshs   v22, v24, v12
    vsubshs   v11, v11, v23
    vsrah     v21, v22, v9
    vaddshs   v20, v11, v11
    vsubshs   v19, v0, v21
    vaddshs   v18, v20, v11
    vsubshs   v10, v10, v19
    vaddshs   v17, v18, v8
    vaddshs   v16, v10, v10
    vsrah     v15, v17, v7
    vaddshs   v14, v16, v10
    vaddshs   v13, v13, v15
    vaddshs   v8, v14, v8
    vaddshs   v6, v13, v13
    vsrah     v5, v8, v7
    vaddshs   v4, v6, v13
    vaddshs   v0, v0, v5
    vaddshs   v3, v4, v12
    vaddshs   v2, v0, v0
    vmrghh    v1, v13, v0
    vsrah     v29, v3, v9
    vmrglh    v30, v13, v0
    vaddshs   v31, v2, v0
    vspltw128 v59, v1, 0
    vaddshs   v13, v11, v29
    vspltw128 v58, v1, 1
    vspltw128 v57, v1, 2
    vspltw128 v56, v1, 3
    vaddshs   v28, v31, v12
    vspltw128 v55, v30, 0
    vspltw128 v54, v30, 1
    vspltw128 v53, v30, 2
    vspltw128 v52, v30, 3
    vsrah     v27, v28, v9
    vaddshs   v0, v10, v27
    vmrghh    v26, v13, v0
    vmrglh    v25, v13, v0
    vspltw128 v51, v26, 0
    vspltw128 v50, v26, 1
    vspltw128 v49, v26, 2
    vspltw128 v48, v26, 3
    vspltw128 v47, v25, 0
    vspltw128 v46, v25, 1
    vspltw128 v45, v25, 2
    vspltw128 v44, v25, 3
    stvewx128 v51, r3, r11
    stvewx128 v50, r3, r9
    stvewx128 v49, r5, r11
    stvewx128 v48, r5, r9
    stvewx128 v47, r7, r11
    stvewx128 v46, r7, r9
    stvewx128 v45, r31, r11
    stvewx128 v44, r31, r9
    stvewx128 v59, r0, r4
    stvewx128 v58, r4, r10
    stvewx128 v57, r0, r6
    stvewx128 v56, r6, r10
    stvewx128 v55, r0, r8
    stvewx128 v54, r8, r10
    stvewx128 v53, r0, r30
    stvewx128 v52, r30, r10
  }
}


// ========================================================================
// PostFilter4x2Stage1
// EA  : 0x828FE678
// RVA : 0x008FE678
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransforminv_xenon_16.cpp
// ========================================================================

void __fastcall PostFilter4x2Stage1(__int16 *pa, __int16 *pb)
{
  _R11 = 16;
  __asm { lvlx128   v63, r0, r4 }
  __asm { vpermwi128 v13, v63, 0x55 # 'U' }
  _R9 = 112;
  _R8 = vmxi_half_1;
  __asm { vpermwi128 v10, v63, 0 }
  _R7 = 64;
  __asm { lvlx128   v62, r11, r3 }
  _R6 = 96;
  _R5 = 48;
  __asm { vpermwi128 v9, v62, 0x55 # 'U' }
  _R10 = 20;
  __asm
  {
    lvx128    v0, r0, r8
    vpermwi128 v8, v62, 0
    lvx128    v12, r8, r9
  }
  _R9 = 4;
  __asm
  {
    lvx128    v11, r8, r7
    vaddshs   v9, v9, v13
    lvx128    v4, r8, r6
    vaddshs   v8, v8, v10
    lvx128    v3, r8, r5
    vaddshs   v7, v9, v0
    vaddshs   v6, v8, v0
    vsrah     v7, v7, v0
    vsrah     v6, v6, v0
    vsubshs   v5, v13, v7
    vsubshs   v2, v10, v6
    vaddshs   v1, v5, v0
    vsrah     v31, v1, v0
    vsubshs   v13, v2, v31
    vaddshs   v30, v13, v0
    vaddshs   v13, v13, v6
    vsrah     v29, v30, v0
    vaddshs   v28, v13, v13
    vaddshs   v27, v5, v29
    vaddshs   v26, v28, v13
    vaddshs   v0, v27, v7
    vaddshs   v25, v26, v12
    vaddshs   v24, v0, v0
    vsrah     v23, v25, v11
    vaddshs   v22, v24, v0
    vsubshs   v21, v13, v23
    vaddshs   v20, v22, v12
    vsubshs   v10, v8, v21
    vsrah     v19, v20, v11
    vaddshs   v18, v10, v10
    vsubshs   v17, v0, v19
    vaddshs   v16, v18, v10
    vsubshs   v9, v9, v17
    vaddshs   v15, v16, v4
    vaddshs   v14, v9, v9
    vsrah     v8, v15, v3
    vaddshs   v7, v14, v9
    vaddshs   v13, v13, v8
    vaddshs   v6, v7, v4
    vaddshs   v5, v13, v13
    vsrah     v4, v6, v3
    vaddshs   v3, v5, v13
    vaddshs   v0, v0, v4
    vaddshs   v2, v3, v12
    vaddshs   v1, v0, v0
    vmrghw128 v61, v13, v0
    vsrah     v31, v2, v11
    vaddshs   v30, v1, v0
    vspltw128 v60, v61, 0
    vaddshs   v29, v10, v31
    vspltw128 v59, v61, 1
    vaddshs   v28, v30, v12
    vsrah     v27, v28, v11
    vaddshs   v26, v9, v27
    vmrghw128 v58, v29, v26
    vspltw128 v57, v58, 0
    vspltw128 v56, v58, 1
    stvewx128 v57, r3, r11
    stvewx128 v56, r3, r10
    stvewx128 v60, r0, r4
    stvewx128 v59, r4, r9
  }
}


// ========================================================================
// PostFilter4x2Stage1_4
// EA  : 0x828FE7B8
// RVA : 0x008FE7B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransforminv_xenon_16.cpp
// ========================================================================

void __fastcall PostFilter4x2Stage1_4(
        __int16 *pa,
        __int16 *pb,
        __int16 *pc,
        __int16 *pd,
        __int16 *pe,
        __int16 *pf,
        __int16 *pg,
        __int16 *ph)
{
  _R30 = ph;
  __asm { lvlx128   v63, r0, r6 }
  _R11 = 16;
  __asm { lvlx128   v62, r0, r4 }
  _R31 = pg;
  __asm
  {
    lvlx128   v60, r0, r8
    vrlimi128 v62, v63, 3, 2
  }
  _R9 = 112;
  __asm { lvlx128   v61, r0, r30 }
  _R29 = vmxi_half_1;
  __asm
  {
    lvlx128   v59, r11, r5
    vrlimi128 v60, v61, 3, 2
    lvlx128   v58, r11, r3
  }
  _R10 = 64;
  __asm
  {
    lvlx128   v57, r11, r31
    vrlimi128 v58, v59, 3, 2
    lvlx128   v56, r11, r7
  }
  _R28 = 96;
  __asm
  {
    vrlimi128 v56, v57, 3, 2
    vmrghw128 v55, v94, v60
    vmrglw128 v54, v94, v60
    lvx128    v0, r0, r29
    lvx128    v12, r29, r9
  }
  _R27 = 48;
  __asm { lvx128    v11, r29, r10 }
  _R9 = 20;
  __asm
  {
    vmrghw128 v53, v90, v56
    lvx128    v4, r29, r28
    vmrglw128 v52, v90, v56
  }
  _R10 = 4;
  __asm
  {
    vmrglw128 v13, v87, v54
    vmrghw128 v10, v87, v54
    lvx128    v3, r29, r27
    vmrglw128 v9, v85, v52
    vmrghw128 v8, v85, v52
    vaddshs   v9, v9, v13
    vaddshs   v8, v8, v10
    vaddshs   v7, v9, v0
    vaddshs   v6, v8, v0
    vsrah     v7, v7, v0
    vsrah     v6, v6, v0
    vsubshs   v5, v13, v7
    vsubshs   v2, v10, v6
    vaddshs   v1, v5, v0
    vsrah     v31, v1, v0
    vsubshs   v13, v2, v31
    vaddshs   v30, v13, v0
    vaddshs   v13, v13, v6
    vsrah     v29, v30, v0
    vaddshs   v28, v13, v13
    vaddshs   v27, v5, v29
    vaddshs   v26, v28, v13
    vaddshs   v0, v27, v7
    vaddshs   v25, v26, v12
    vaddshs   v24, v0, v0
    vsrah     v23, v25, v11
    vaddshs   v22, v24, v0
    vsubshs   v21, v13, v23
    vaddshs   v20, v22, v12
    vsubshs   v10, v8, v21
    vsrah     v19, v20, v11
    vaddshs   v18, v10, v10
    vsubshs   v17, v0, v19
    vaddshs   v16, v18, v10
    vsubshs   v9, v9, v17
    vaddshs   v15, v16, v4
    vaddshs   v14, v9, v9
    vsrah     v8, v15, v3
    vaddshs   v7, v14, v9
    vaddshs   v13, v13, v8
    vaddshs   v6, v7, v4
    vaddshs   v5, v13, v13
    vsrah     v4, v6, v3
    vaddshs   v3, v5, v13
    vaddshs   v0, v0, v4
    vaddshs   v2, v3, v12
    vaddshs   v1, v0, v0
    vmrghw128 v51, v13, v0
    vmrglw128 v50, v13, v0
    vaddshs   v31, v1, v0
    vaddshs   v29, v31, v12
    vspltw128 v49, v51, 0
    vsrah     v30, v2, v11
    vspltw128 v48, v51, 1
    vspltw128 v47, v51, 2
    vspltw128 v46, v51, 3
    vsrah     v27, v29, v11
    vspltw128 v45, v50, 0
    vaddshs   v28, v10, v30
    vspltw128 v44, v50, 1
    vspltw128 v43, v50, 2
    vspltw128 v42, v50, 3
    vaddshs   v26, v9, v27
    vmrghw128 v41, v28, v26
    vmrglw128 v40, v28, v26
    vspltw128 v39, v41, 0
    vspltw128 v38, v41, 1
    vspltw128 v37, v41, 2
    vspltw128 v36, v41, 3
    vspltw128 v35, v40, 0
    vspltw128 v34, v40, 1
    vspltw128 v33, v40, 2
    vspltw128 v32, v40, 3
    stvewx128 v39, r3, r11
    stvewx128 v38, r3, r9
    stvewx128 v37, r5, r11
    stvewx128 v36, r5, r9
    stvewx128 v35, r7, r11
    stvewx128 v34, r7, r9
    stvewx128 v33, r31, r11
    stvewx128 v32, r31, r9
    stvewx128 v49, r0, r4
    stvewx128 v48, r4, r10
    stvewx128 v47, r0, r6
    stvewx128 v46, r6, r10
    stvewx128 v45, r0, r8
    stvewx128 v44, r8, r10
    stvewx128 v43, r0, r30
    stvewx128 v42, r30, r10
  }
}


// ========================================================================
// PostFilter2x2Stage1
// EA  : 0x828FE9A8
// RVA : 0x008FE9A8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransforminv_xenon_16.cpp
// ========================================================================

void __fastcall PostFilter2x2Stage1(__int16 *p)
{
  __asm { lvlx      v13, r0, r3 }
  _R10 = 112;
  __asm { vsplth    v10, v13, 3 }
  _R9 = vmxi_half_1;
  __asm { vsplth    v9, v13, 2 }
  _R8 = 64;
  __asm { vsplth    v7, v13, 1 }
  _R7 = 96;
  _R6 = 48;
  __asm { vaddshs   v8, v13, v10 }
  _R5 = 4;
  __asm
  {
    lvx128    v0, r0, r9
    vaddshs   v7, v7, v9
    lvx128    v12, r9, r10
    lvx128    v11, r9, r8
    vaddshs   v13, v8, v0
    lvx128    v5, r9, r7
    lvx128    v4, r9, r6
    vaddshs   v3, v7, v0
    vsrah     v6, v13, v0
    vsrah     v13, v3, v0
    vsubshs   v10, v10, v6
    vsubshs   v2, v9, v13
    vaddshs   v1, v10, v0
    vsrah     v31, v1, v0
    vsubshs   v9, v2, v31
    vaddshs   v30, v9, v0
    vaddshs   v13, v9, v13
    vsrah     v29, v30, v0
    vaddshs   v28, v13, v13
    vaddshs   v27, v10, v29
    vaddshs   v26, v28, v13
    vaddshs   v0, v27, v6
    vaddshs   v25, v26, v12
    vaddshs   v24, v0, v0
    vsrah     v23, v25, v11
    vaddshs   v22, v24, v0
    vsubshs   v21, v13, v23
    vaddshs   v20, v22, v12
    vsubshs   v10, v7, v21
    vsrah     v19, v20, v11
    vaddshs   v18, v10, v10
    vsubshs   v17, v0, v19
    vaddshs   v16, v18, v10
    vsubshs   v9, v8, v17
    vaddshs   v15, v16, v5
    vaddshs   v14, v9, v9
    vsrah     v8, v15, v4
    vaddshs   v7, v14, v9
    vaddshs   v13, v13, v8
    vaddshs   v6, v7, v5
    vaddshs   v5, v13, v13
    vsrah     v4, v6, v4
    vaddshs   v3, v5, v13
    vaddshs   v0, v0, v4
    vaddshs   v2, v3, v12
    vaddshs   v1, v0, v0
    vsrah     v31, v2, v11
    vaddshs   v30, v1, v0
    vaddshs   v29, v10, v31
    vaddshs   v28, v30, v12
    vmrghh    v0, v29, v0
    vsrah     v27, v28, v11
    vaddshs   v26, v9, v27
    vmrghh    v13, v26, v13
    vmrghh    v0, v13, v0
    vspltw128 v63, v0, 0
    vspltw128 v62, v0, 1
    stvewx128 v63, r0, r3
    stvewx128 v62, r3, r5
  }
}


// ========================================================================
// ?InvTransformMacroblock_Xenon_16@@YAXPAUhdpCodec_t@@@Z
// EA  : 0x828FEAC8
// RVA : 0x008FEAC8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransforminv_xenon_16.cpp
// ========================================================================

void __fastcall InvTransformMacroblock_Xenon_16(hdpCodec_t *codec)
{
  unsigned int currentMacroblockRow; // r11
  unsigned int currentMacroblockColumn; // r9
  char v3; // r8
  hdpColorFormat_t colorFormat; // r7
  char v5; // r6
  BOOL v6; // r11
  bool v7; // r9
  BOOL v8; // r10
  bool v9; // r8
  unsigned __int8 v10; // r6
  unsigned int v11; // r22
  unsigned int numChannels; // r11
  unsigned int thumbnailScale; // r21
  int v14; // r24
  __int16 **macroBlockColumnPtr1; // r26
  unsigned int v16; // r23
  __int16 *v20; // r3
  __int16 *v21; // r3
  __int16 *v22; // r3
  __int16 *v23; // r7
  __int16 *v24; // r5
  __int16 *v25; // r3
  __int16 *v26; // r10
  __int16 *v27; // r9
  __int16 *v28; // r8
  __int16 *v29; // r6
  __int16 *v30; // r4
  __int16 *v31; // r29
  __int16 *v32; // r28
  __int16 *v33; // r31
  __int16 *v34; // r8
  __int16 *v35; // r4
  int v36; // [sp+8h] [-B8h]
  int v37; // [sp+8h] [-B8h]
  int v38; // [sp+Ch] [-B4h]
  int v39; // [sp+Ch] [-B4h]
  int v40; // [sp+10h] [-B0h]
  int v41; // [sp+10h] [-B0h]
  int v42; // [sp+14h] [-ACh]
  int v43; // [sp+14h] [-ACh]
  int v44; // [sp+18h] [-A8h]
  int v45; // [sp+18h] [-A8h]
  int v46; // [sp+1Ch] [-A4h]
  int v47; // [sp+1Ch] [-A4h]
  int v48; // [sp+20h] [-A0h]
  int v49; // [sp+20h] [-A0h]
  int v50; // [sp+24h] [-9Ch]
  int v51; // [sp+24h] [-9Ch]
  int v52; // [sp+28h] [-98h]
  int v53; // [sp+28h] [-98h]
  int v54; // [sp+2Ch] [-94h]
  int v55; // [sp+2Ch] [-94h]
  int v56; // [sp+30h] [-90h]
  int v57; // [sp+30h] [-90h]
  int v58; // [sp+34h] [-8Ch]
  int v59; // [sp+34h] [-8Ch]
  int v60; // [sp+38h] [-88h]
  int v61; // [sp+38h] [-88h]
  int v62; // [sp+3Ch] [-84h]
  int v63; // [sp+3Ch] [-84h]
  int v64; // [sp+40h] [-80h]
  int v65; // [sp+40h] [-80h]
  int v66; // [sp+44h] [-7Ch]
  int v67; // [sp+44h] [-7Ch]
  int v68; // [sp+48h] [-78h]
  int v69; // [sp+48h] [-78h]
  int v70; // [sp+4Ch] [-74h]
  int v71; // [sp+4Ch] [-74h]
  int v72; // [sp+50h] [-70h]
  int v73; // [sp+50h] [-70h]

  currentMacroblockRow = codec->currentMacroblockRow;
  currentMacroblockColumn = codec->currentMacroblockColumn;
  v3 = _cntlzw(currentMacroblockRow);
  colorFormat = codec->codecParms.colorFormat;
  v5 = _cntlzw(codec->widthInMacroblocks - currentMacroblockColumn);
  v6 = (_cntlzw(codec->heightInMacroblocks - currentMacroblockRow) & 0x20) != 0;
  v7 = (_cntlzw(currentMacroblockColumn) & 0x20) != 0;
  v8 = (v5 & 0x20) != 0;
  v9 = (v3 & 0x20) != 0;
  if ( v6 || (v10 = 0, v8) )
    v10 = 1;
  v11 = 3 * (((_cntlzw(v9 || v6) & 0x20) != 0) + 2 * v6) + ((_cntlzw(v7 || v8) & 0x20) != 0) + ((2 * v8) & 0x1FE);
  if ( colorFormat == CF_YUV_420 || colorFormat == CF_YUV_422 )
    numChannels = 1;
  else
    numChannels = codec->codecParms.numChannels;
  thumbnailScale = codec->codecParms.thumbnailScale;
  if ( thumbnailScale < 0x10 && numChannels != 0 )
  {
    v14 = v10;
    macroBlockColumnPtr1 = codec->macroBlockColumnPtr1;
    v16 = numChannels;
    _R25 = 128;
    while ( 1 )
    {
      _R31 = *(macroBlockColumnPtr1 - 16);
      _R30 = *macroBlockColumnPtr1;
      __asm { dcbt      0, r30 }
      __asm
      {
        dcbt      r25, r30
        dcbt      0, r31
      }
      __asm { dcbt      r25, r31 }
      if ( v14 == 0 )
        InvTransform4x4Stage2(p: *macroBlockColumnPtr1);
      if ( thumbnailScale >= 4 || v11 > 8 )
        goto LABEL_34;
      if ( v11 == 1 )
        break;
      switch ( v11 )
      {
        case 2u:
          InvTransform4x4Stage1_4(p: _R30 - 128);
          PostFilter2x2Stage1(p: _R30 - 60);
          PostFilter2x4Stage1(pa: _R30 - 192, pb: _R30 - 128);
          PostFilter2x4Stage1(pa: _R30 - 128, pb: _R30 - 64);
          PostFilter4x2Stage1(pa: _R30 - 60, pb: _R30 - 44);
          PostFilter4x4Stage1(p0: _R30 - 180, p1: _R30 - 120, p2: _R30 - 172, p3: _R30 - 112);
          PostFilter4x4Stage1(p0: _R30 - 116, p1: _R30 - 56, p2: _R30 - 108, p3: _R30 - 48);
          break;
        case 3u:
          v31 = _R31 + 32;
          InvTransform4x4Stage1_8(p0: _R31 + 32, p1: _R30);
          v32 = _R31 + 48;
          v34 = _R31 + 48;
          v33 = _R31 + 16;
          PostFilter4x2Stage1_4(pa: _R30, pb: _R30 + 16, pc: v32, pd: _R30, pe: v31, pf: v34, pg: v33, ph: v31);
          v26 = v35;
          v23 = v32;
          v24 = v31;
          v29 = v32;
          v30 = v31;
          v25 = v33;
          goto LABEL_32;
        case 4u:
          InvTransform4x4Stage1_8(p0: _R31 - 96, p1: _R31 + 32);
          InvTransform4x4Stage1_8(p0: _R30 - 128, p1: _R30);
          PostFilter4x4Stage1_8(
            p0: _R31 - 176,
            p1: _R31 - 160,
            p2: _R31 - 160,
            p3: _R31 - 144,
            p4: _R31 - 144,
            p5: _R30 - 192,
            p6: _R30 - 192,
            p7: _R30 - 176,
            ofs: v36,
            a10: v38,
            a11: v40,
            a12: v42,
            a13: v44,
            a14: v46,
            a15: v48,
            a16: v50,
            a17: v52,
            a18: v54,
            a19: v56,
            a20: v58,
            a21: v60,
            a22: v62,
            a23: v64,
            a24: v66,
            a25: v68,
            a26: v70,
            a27: v72,
            a28: 64);
          PostFilter4x4Stage1_8(
            p0: _R31 - 48,
            p1: _R31 - 32,
            p2: _R31 - 32,
            p3: _R31 - 16,
            p4: _R31 - 16,
            p5: _R30 - 64,
            p6: _R30 - 64,
            p7: _R30 - 48,
            ofs: v37,
            a10: v39,
            a11: v41,
            a12: v43,
            a13: v45,
            a14: v47,
            a15: v49,
            a16: v51,
            a17: v53,
            a18: v55,
            a19: v57,
            a20: v59,
            a21: v61,
            a22: v63,
            a23: v65,
            a24: v67,
            a25: v69,
            a26: v71,
            a27: v73,
            a28: 64);
          break;
        case 5u:
          InvTransform4x4Stage1_8(p0: _R31 - 96, p1: _R30 - 128);
          PostFilter4x2Stage1_4(
            pa: _R30 - 60,
            pb: _R30 - 44,
            pc: _R31 - 12,
            pd: _R30 - 60,
            pe: _R31 - 28,
            pf: _R31 - 12,
            pg: _R31 - 44,
            ph: _R31 - 28);
          PostFilter4x4Stage1_8(
            p0: _R31 - 176,
            p1: _R31 - 160,
            p2: _R31 - 160,
            p3: _R31 - 144,
            p4: _R31 - 144,
            p5: _R30 - 192,
            p6: _R30 - 192,
            p7: _R30 - 176,
            ofs: v36,
            a10: v38,
            a11: v40,
            a12: v42,
            a13: v44,
            a14: v46,
            a15: v48,
            a16: v50,
            a17: v52,
            a18: v54,
            a19: v56,
            a20: v58,
            a21: v60,
            a22: v62,
            a23: v64,
            a24: v66,
            a25: v68,
            a26: v70,
            a27: v72,
            a28: 64);
          break;
        case 6u:
          InvTransform4x4Stage1_4(p: _R31 + 32);
          PostFilter2x2Stage1(p: _R31 + 56);
          PostFilter4x2Stage1(pa: _R31 + 16, pb: _R31 + 32);
          PostFilter4x2Stage1(pa: _R31 + 32, pb: _R31 + 48);
          PostFilter2x4Stage1(pa: _R31 + 56, pb: _R31 + 120);
          PostFilter4x4Stage1(p0: _R31 + 28, p1: _R31 + 88, p2: _R31 + 36, p3: _R31 + 96);
          PostFilter4x4Stage1(p0: _R31 + 44, p1: _R31 + 104, p2: _R31 + 52, p3: _R31 + 112);
          break;
        case 7u:
          InvTransform4x4Stage1_8(p0: _R31 - 96, p1: _R31 + 32);
          PostFilter2x4Stage1_4(
            pa: _R31 - 136,
            pb: _R31 - 72,
            pc: _R31 - 72,
            pd: _R31 - 8,
            pe: _R31 - 8,
            pf: _R31 + 56,
            pg: _R31 + 56,
            ph: _R31 + 120);
          PostFilter4x4Stage1_8(
            p0: _R31 - 176,
            p1: _R31 - 160,
            p2: _R31 - 160,
            p3: _R31 - 144,
            p4: _R31 - 112,
            p5: _R31 - 96,
            p6: _R31 - 96,
            p7: _R31 - 80,
            ofs: v36,
            a10: v38,
            a11: v40,
            a12: v42,
            a13: v44,
            a14: v46,
            a15: v48,
            a16: v50,
            a17: v52,
            a18: v54,
            a19: v56,
            a20: v58,
            a21: v60,
            a22: v62,
            a23: v64,
            a24: v66,
            a25: v68,
            a26: v70,
            a27: v72,
            a28: 128);
          break;
        case 0u:
          InvTransform4x4Stage1_4(p: _R30);
          PostFilter2x2Stage1(p: v20);
          PostFilter4x2Stage1(pa: v21, pb: _R30 + 16);
          PostFilter2x4Stage1(pa: v22, pb: _R30 + 64);
          PostFilter4x4Stage1(p0: _R30 + 12, p1: _R30 + 72, p2: _R30 + 20, p3: _R30 + 80);
          break;
        default:
          _R30 = _R31 - 96;
          InvTransform4x4Stage1_4(p: _R31 - 96);
          PostFilter2x2Stage1(p: _R31 - 4);
          PostFilter4x2Stage1(pa: _R31 - 44, pb: _R31 - 28);
          PostFilter4x2Stage1(pa: _R31 - 28, pb: _R31 - 12);
          PostFilter2x4Stage1(pa: _R31 - 136, pb: _R31 - 72);
          PostFilter2x4Stage1(pa: _R31 - 72, pb: _R31 - 8);
          v24 = _R31 - 160;
          v26 = _R31 - 80;
          v23 = _R31 - 112;
          v29 = _R31 - 144;
          v30 = _R31 - 160;
          v25 = _R31 - 176;
LABEL_32:
          v27 = _R30;
          v28 = _R30;
LABEL_33:
          PostFilter4x4Stage1_4(p0: v25, p1: v30, p2: v24, p3: v29, p4: v23, p5: v28, p6: v27, p7: v26);
          break;
      }
LABEL_34:
      --v16;
      ++macroBlockColumnPtr1;
      if ( v16 == 0 )
        return;
    }
    InvTransform4x4Stage1_8(p0: _R30 - 128, p1: _R30);
    PostFilter2x4Stage1_4(
      pa: _R30 - 192,
      pb: _R30 - 128,
      pc: _R30 - 128,
      pd: _R30 - 64,
      pe: _R30 - 64,
      pf: _R30,
      pg: _R30,
      ph: _R30 + 64);
    v26 = _R30 + 16;
    v27 = _R30;
    v28 = _R30 - 48;
    v29 = _R30 - 112;
    v30 = _R30 - 176;
    goto LABEL_33;
  }
}

