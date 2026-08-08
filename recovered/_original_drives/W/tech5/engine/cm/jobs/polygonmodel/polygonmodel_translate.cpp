
// ========================================================================
// ?TranslationSetup@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@ABVidVec3@@11ABVidMat3@@12@Z
// EA  : 0x825F1FE8
// RVA : 0x005F1FE8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TranslationSetup(
        idTraceWork *tw,
        const idVec3 *start,
        const idVec3 *end,
        const idVec3 *offset,
        const idMat3 *trmAxis,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis)
{
  _R11 = 16;
  __asm { lvlx128   v63, r0, r6 }
  __asm { lvlx128   v62, r0, r7 }
  _R31 = trmAxis;
  __asm { lvlx128   v61, r0, r8 }
  _R27 = vmxi_word_perm_trm_transform2;
  __asm { lvlx128   v60, r0, r4 }
  _R28 = -144;
  __asm
  {
    lvlx128   v59, r0, r5
    lvrx128   v58, r11, r6
  }
  _R30 = modelOrigin;
  __asm { vor128    v57, v95, v58 }
  _R7 = 28;
  __asm { lvrx128   v56, r11, r31 }
  _R8 = 12;
  __asm { vor128    v55, v94, v56 }
  _R29 = modelAxis;
  __asm { lvx128    v63, r27, r28 }
  _R9 = 40;
  __asm { vand128   v52, v89, v63 }
  _R10 = 24;
  __asm
  {
    lvrx128   v54, r7, r31
    vspltisw128 v53, 0
    vand128   v50, v87, v63
    lvlx128   v51, r8, r31
    vor128    v48, v83, v54
    lvrx128   v49, r11, r30
    vspltw128 v44, v52, 0
    lvrx128   v47, r9, r31
    vspltw128 v11, v52, 1
    lvlx128   v46, r10, r31
    vor128    v43, v78, v47
    vspltw128 v10, v52, 2
    vand128   v0, v80, v63
    lvrx128   v42, r11, r4
    vmulfp128 v12, v82, v44
    vor128    v45, v93, v49
    lvrx128   v40, r11, r5
    vor128    v39, v92, v42
    vand128   v13, v75, v63
    lvrx128   v35, r7, r29
    vor128    v37, v91, v40
    lvlx128   v33, r8, r29
    vand128   v41, v77, v63
    lvlx128   v38, r0, r29
    vand128   v32, v71, v63
    lvrx128   v36, r11, r29
    lvrx128   v62, r9, r29
    vor128    v34, v70, v36
    vand128   v61, v69, v63
    lvlx128   v60, r10, r29
    vor128    v59, v65, v35
  }
  _R8 = -16;
  __asm
  {
    vor128    v58, v92, v62
    vsubfp128 v56, v64, v41
    vand128   v57, v66, v63
    lvx128    v6, r0, r27
  }
  _R7 = -208;
  __asm
  {
    vmaddfp   v12, v0, v12, v11
    vand128   v55, v91, v63
    vand128   v54, v90, v63
    lvx128    v7, r27, r8
  }
  _R6 = 5984;
  __asm { vmrghw128 v63, v82, v0 }
  _R5 = 6000;
  _R4 = 6016;
  __asm
  {
    vmaddfp   v12, v13, v12, v10
    vsubfp128 v52, v12, v41
    vaddfp128 v51, v64, v52
    vaddfp128 v49, v93, v52
    vmulfp128 v48, v89, v51
    vmulfp128 v47, v87, v51
    vmulfp128 v46, v86, v51
    vmulfp128 v45, v89, v49
    vmulfp128 v44, v87, v49
    vmulfp128 v43, v86, v49
    vmrghw128 v42, v79, v53
    vmrghw128 v41, v80, v46
    vmrghw128 v40, v76, v53
    vmrghw128 v39, v77, v43
    vmrghw128 v62, v13, v56
    lvx128    v61, r27, r7
    vmrglw128 v38, v73, v42
  }
  _R11 = 6032;
  __asm { vmrghw128 v37, v73, v42 }
  _R10 = 6048;
  __asm { vmrglw128 v36, v71, v40 }
  _R9 = 6064;
  __asm { vmrghw128 v34, v71, v40 }
  _R8 = 6080;
  __asm
  {
    vperm128  v60, v95, v62, v7
    vspltw128 v33, v57, 0
    vaddfp128 v35, v69, v38
    vspltw128 v32, v55, 0
    vspltw128 v59, v54, 0
    vaddfp128 v58, v66, v36
    vmrglw128 v56, v13, v56
    vmrglw128 v51, v80, v46
    vmulfp128 v13, v92, v33
    vmrglw128 v48, v77, v43
    vmulfp128 v10, v92, v32
    vmrglw128 v49, v76, v53
    vmulfp128 v8, v92, v59
    vmrglw128 v52, v79, v53
    vperm128  v12, v95, v62, v6
    vspltw128 v11, v57, 1
    vmrghw128 v46, v80, v49
    vmrghw128 v47, v83, v52
    vspltw128 v9, v55, 1
    vspltw128 v6, v54, 1
    vaddfp128 v43, v90, v46
    vmrglw128 v44, v82, v0
    vaddfp128 v45, v67, v47
    vspltw128 v5, v57, 2
    vmaddfp   v13, v12, v13, v11
    vspltw128 v4, v55, 2
    vmaddfp   v11, v12, v10, v9
    vspltw128 v3, v54, 2
    vmaddfp   v12, v12, v8, v6
    vperm128  v0, v76, v56, v7
    stvx128   v43, r3, r5
    vsubfp128 v42, v75, v45
    stvx128   v45, r3, r6
    vmaddfp   v13, v0, v13, v5
    vmaddfp   v11, v0, v11, v4
    vmaddfp   v0, v0, v12, v3
    vxor128   v41, v74, v61
    stvx128   v42, r3, r4
    stvx128   v13, r3, r10
    stvx128   v11, r3, r9
    stvx128   v0, r3, r8
    stvx128   v41, r3, r11
  }
}


// ========================================================================
// ?TranslationUsedPrimitives@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@ABVidVec3@@1PBVidTraceModel@@ABVidMat3@@@Z
// EA  : 0x825F2208
// RVA : 0x005F2208
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TranslationUsedPrimitives(
        idTraceWork *tw,
        const idVec3 *start,
        const idVec3 *end,
        const idTraceModel *trm,
        const idMat3 *trmAxis)
{
  unsigned int *p_numPolys; // r21
  unsigned int v23; // r22
  unsigned int *numPolyEdges; // r23
  bool v31; // cr58
  unsigned __int8 *v32; // r30
  unsigned __int8 *v33; // r8
  unsigned __int8 *v34; // r7
  unsigned int v35; // r29
  unsigned int v36; // r28
  unsigned int v37; // r26
  unsigned int v38; // r16
  int v39; // r4
  char *v40; // r5
  char *v41; // r28
  char *v42; // r29
  float back_chain; // [sp+0h] [-A0h] BYREF

  __asm { vspltisw  v11, 0 }
  _R11 = 5888;
  _R10 = 5904;
  _R9 = tw->edgeIsUsed;
  _R31 = 5936;
  __asm
  {
    stvx128   v11, r3, r11
    stvx128   v11, r3, r10
    stvx128   v11, r0, r9
    stvx128   v11, r3, r31
  }
  _R11 = 16;
  __asm
  {
    lvlx128   v63, r0, r4
    lvlx128   v62, r0, r5
  }
  _R10 = 28;
  _R17 = 24;
  __asm { lvlx128   v61, r0, r7 }
  _R8 = 12;
  _R30 = 40;
  __asm { lvrx128   v60, r11, r4 }
  _R29 = &back_chain;
  __asm
  {
    lvrx128   v59, r11, r5
    vor128    v58, v95, v60
    vor128    v57, v94, v59
    lvrx128   v56, r11, r7
    lvrx128   v55, r10, r7
    vor128    v54, v93, v56
    lvlx128   v53, r8, r7
  }
  __asm
  {
    lvrx128   v52, r30, r7
    vor128    v51, v85, v55
    vsubfp128 v50, v89, v58
    lvlx128   v49, r17, r7
    vor128    v48, v81, v52
  }
  _R7 = -64;
  _R4 = vmxi_word_trm_dir_bit;
  __asm { lvlx128   v47, r0, r29 }
  p_numPolys = &tw->numPolys;
  __asm
  {
    vspltw128 v62, v47, 0
    vmulfp128 v46, v86, v50
    lvx128    v61, r4, r7
    vmulfp128 v45, v83, v50
  }
  _R10 = 0;
  __asm { vmulfp128 v44, v80, v50 }
  __asm
  {
    vmrghw128 v43, v77, v46
    vmrghw128 v42, v78, v44
    vmrglw128 v41, v77, v46
    vmrglw128 v40, v78, v44
    vmrglw128 v39, v74, v43
    vmrghw128 v38, v74, v43
    vmrghw128 v37, v72, v41
    vaddfp128 v36, v70, v39
    vaddfp128 v60, v68, v37
  }
  if ( tw->numPolys != 0 )
  {
    __asm { vspltw128 v63, v60, 0 }
    _R8 = tw->polyIsUsed;
    __asm { vspltw128 v10, v60, 1 }
    _R11 = trm->polyPlaneY;
    __asm { vspltw128 v9, v60, 2 }
    _R5 = 64;
    do
    {
      __asm
      {
        lvx128    v35, r11, r7
        vmulfp128 v13, v67, v63
        lvx128    v0, r0, r11
        lvx128    v12, r11, r5
      }
      _R11 += 4;
      __asm
      {
        vmaddfp   v0, v0, v13, v10
        vmaddfp   v0, v12, v0, v9
        vcmpgtfp128 v34, v0, v62
        vand128   v33, v66, v61
        vpkswss128 v32, v65, v33
        vpkshss128 v60, v64, v32
        stvewx128 v60, r8, r10
      }
      _R10 += 4;
    }
    while ( _R10 < *p_numPolys );
  }
  v23 = 0;
  if ( *p_numPolys != 0 )
  {
    _R11 = -16;
    __asm { lvx128    v59, r0, r4 }
    _R25 = &tw->polys[0].numEdges;
    _R31 = trm->polyEdges[0];
    numPolyEdges = trm->numPolyEdges;
    __asm { lvx128    v60, r4, r11 }
    _R20 = 4;
    _R19 = 20;
    do
    {
      if ( tw->polyIsUsed[v23] != 0 )
      {
        __asm
        {
          lvx128    v58, r0, r31
          vmr128    v63, v11
        }
        _R11 = 0;
        __asm { vmr128    v62, v11 }
        v31 = *numPolyEdges == 0;
        __asm { stvx128   v58, r25, r20 }
        *_R25 = *numPolyEdges;
        if ( !v31 )
        {
          v32 = _R31 - 1024;
          v33 = _R31 - 1024;
          v34 = _R31 - 1024;
          do
          {
            v35 = _R31[_R11];
            __asm { lvlx      v0, r31, r11 }
            v36 = v33[1025];
            v37 = v34[1026];
            v38 = _R31[_R11 + 3];
            __asm { vmrghb    v13, v11, v0 }
            _R9[v35 & 0x7F] = 1;
            _R9[v36 & 0x7F] = 1;
            _R9[v37 & 0x7F] = 1;
            _R9[v38 & 0x7F] = 1;
            __asm { vmrghh    v12, v11, v13 }
            v39 = (v35 >> 7) + 2 * ((v35 & 0x7F) + 336);
            __asm { vand128   v57, v12, v60 }
            __asm { vsrw128   v56, v12, v59 }
            __asm { vslw128   v55, v93, v57 }
            __asm { vslw128   v54, v88, v57 }
            __asm { vor128    v63, v95, v55 }
            __asm { vor128    v62, v94, v54 }
            _R11 += 4;
            v40 = (char *)tw + trm->edges[v36 & 0x7F].v[v36 >> 7];
            v41 = (char *)tw + trm->edges[v37 & 0x7F].v[v37 >> 7];
            v42 = (char *)tw + trm->edges[v38 & 0x7F].v[v38 >> 7];
            tw->vertIsUsed[*((unsigned __int16 *)trm->vertsX + v39)] = 1;
            v34 = &v32[_R11];
            v40[5888] = 1;
            v41[5888] = 1;
            v33 = &v32[_R11];
            v42[5888] = 1;
          }
          while ( _R11 < *_R25 );
        }
        __asm
        {
          vpermwi128 v53, v63, 0xB1
          vpermwi128 v52, v62, 0xB1
          vor128    v51, v95, v53
          vor128    v50, v94, v52
          vpermwi128 v49, v51, 0x4E # 'N'
          vpermwi128 v48, v50, 0x4E # 'N'
          vor128    v47, v83, v49
          vor128    v46, v82, v48
          stvewx128 v47, r25, r19
          stvewx128 v46, r25, r17
        }
      }
      ++v23;
      ++numPolyEdges;
      _R31 += 16;
      _R25 += 16;
    }
    while ( v23 < *p_numPolys );
  }
}


// ========================================================================
// ?TranslationHeartPlanes@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@@Z
// EA  : 0x825F2510
// RVA : 0x005F2510
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TranslationHeartPlanes(idTraceWork *tw)
{
  _R11 = 6016;
  _R8 = &vmx_float_zero_0;
  _R7 = &vmx_float_firstOnePlusTwoUlps_6;
  __asm { lvx128    v13, r3, r11 }
  _R6 = 272;
  __asm { vmulfp128 v59, v13, v13 }
  _R5 = 64;
  _R4 = 48;
  __asm
  {
    vpermwi128 v58, v13, 0x4F # 'O'
    lvx128    v62, r0, r8
  }
  _R11 = 160;
  __asm
  {
    lvx128    v61, r0, r7
    vpermwi128 v57, v13, 0x63 # 'c'
    lvx128    v0, r8, r6
  }
  _R7 = 5984;
  __asm { lvx128    v60, r8, r5 }
  _R6 = 144;
  __asm { lvx128    v12, r8, r4 }
  _R10 = &tw->heartPlane2;
  __asm { lvx128    v63, r8, r11 }
  _R11 = &tw->heartPlane1;
  __asm { vxor128   v56, v90, v63 }
  _R9 = 12;
  __asm
  {
    lvx128    v55, r3, r7
    lvx128    v63, r8, r6
    vxor128   v53, v87, v63
    vspltw128 v54, v59, 1
    vspltw128 v52, v59, 0
    vspltw128 v51, v59, 2
    vaddfp128 v50, v84, v54
    vcmpeqfp128 v49, v82, v62
    vaddfp128 v48, v82, v51
    vand128   v47, v81, v61
    vor128    v46, v82, v47
    vor128    v45, v88, v47
    vperm128  v44, v78, v48, v0
    vrsqrtefp128 v0, v44
    vmulfp128 v11, v76, v0
    vmulfp128 v43, v0, v60
    vmaddfp   v0, v11, v12, v0
    vmulfp128 v42, v75, v0
    vspltw128 v41, v42, 0
    vspltw128 v40, v42, 2
    vmulfp128 v39, v77, v41
    vmulfp128 v12, v71, v57
    vpermwi128 v0, v39, 0x63 # 'c'
    vmsum3fp128 v38, v71, v53
    stvx128   v39, r0, r11
    vnmsubfp  v12, v13, v12, v0
    vmulfp128 v37, v12, v40
    vpermwi128 v36, v37, 0x63 # 'c'
    vmsum3fp128 v35, v68, v53
    stvx128   v36, r0, r10
    stvewx128 v38, r11, r9
    stvewx128 v35, r10, r9
  }
}


// ========================================================================
// ?TranslationVerts@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@PIBVidTraceModel@@@Z
// EA  : 0x825F25F8
// RVA : 0x005F25F8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TranslationVerts(idTraceWork *tw, const idTraceModel *trm)
{
  unsigned int v13; // r8

  __asm { vspltisw128 v59, 0 }
  _R10 = 6016;
  _R24 = vmxi_word_clear_last_1;
  _R8 = -64;
  __asm { vor128    v56, v91, v59 }
  __asm { vor128    v55, v91, v59 }
  _R5 = &vmx_float_posInfinity_6;
  __asm { lvx128    v63, r3, r10 }
  _R11 = &vmx_float_negInfinity_6;
  __asm { lvx128    v62, r24, r8 }
  _R8 = 6208;
  __asm { vxor128   v62, v95, v62 }
  _R10 = 6192;
  _R7 = 6048;
  __asm
  {
    vspltw128 v58, v63, 1
    lvx128    v54, r0, r5
  }
  _R6 = 6064;
  _R5 = 6080;
  __asm
  {
    lvx128    v53, r0, r11
    vspltw128 v49, v62, 2
    lvx128    v60, r3, r8
    vspltw128 v52, v62, 0
    lvx128    v61, r3, r10
    lvx128    v57, r3, r7
  }
  v13 = 0;
  __asm { lvx128    v51, r3, r6 }
  __asm
  {
    lvx128    v50, r3, r5
    vmrghw128 v62, v81, v58
  }
  if ( tw->numVerts != 0 )
  {
    _R9 = trm->vertsZ;
    __asm { vspltw128 v27, v51, 3 }
    _R4 = -32;
    __asm
    {
      vspltw128 v26, v51, 0
      vspltw128 v25, v51, 1
    }
    _R11 = &tw->vertexPosition[1];
    __asm { vspltw128 v24, v51, 2 }
    _R10 = &tw->vertexPluecker[0].p[4];
    __asm { vspltw128 v23, v50, 3 }
    _R26 = -256;
    __asm { vspltw128 v22, v50, 0 }
    _R25 = -128;
    __asm { vspltw128 v21, v50, 1 }
    _R5 = -16;
    __asm { vspltw128 v20, v50, 2 }
    _R6 = 16;
    __asm { vspltw128 v31, v57, 3 }
    _R7 = 32;
    __asm { vspltw128 v30, v57, 0 }
    _R27 = 48;
    __asm { vspltw128 v29, v57, 1 }
    _R28 = 64;
    __asm
    {
      vspltw128 v28, v57, 2
      lvx128    v57, r24, r4
      vspltw128 v19, v61, 3
    }
    _R29 = 496;
    __asm { vspltw128 v18, v61, 0 }
    _R30 = 512;
    __asm { vspltw128 v17, v61, 1 }
    _R31 = 528;
    __asm { vspltw128 v16, v61, 2 }
    _R4 = 544;
    __asm
    {
      vspltw128 v15, v60, 3
      vspltw128 v14, v60, 0
      vspltw128 v51, v60, 1
      vspltw128 v50, v60, 2
      vspltw128 v61, v63, 0
      vspltw128 v60, v63, 2
    }
    do
    {
      __asm
      {
        lvx128    v0, r9, r26
        vor128    v10, v93, v61
        vmaddfp   v11, v0, v31, v30
        lvx128    v13, r9, r25
        vmaddfp   v9, v0, v27, v26
        lvx128    v12, r0, r9
        vmaddfp   v0, v0, v23, v22
        vor128    v8, v93, v61
        vor128    v6, v90, v58
      }
      v13 += 4;
      _R9 += 4;
      __asm
      {
        vmaddfp   v11, v13, v11, v29
        vmaddfp   v9, v13, v9, v25
        vmaddfp   v7, v13, v0, v21
        vmaddfp   v0, v12, v11, v28
        vmaddfp   v13, v12, v9, v24
        vmaddfp   v12, v12, v7, v20
        vmulfp128 v3, v0, v58
        vmulfp128 v2, v0, v60
        vmrghw128 v46, v13, v59
        vmulfp128 v1, v13, v60
        vmr       v7, v12
        vmaddfp   v5, v0, v19, v18
        vmrghw128 v48, v0, v12
        vmaddfp   v4, v0, v15, v14
        vmrglw128 v47, v0, v12
        vor128    v0, v83, v51
        vmrglw128 v45, v13, v59
        vmrghw128 v44, v80, v46
        vmrglw128 v43, v80, v46
        vmrghw128 v42, v79, v45
        vmrglw128 v41, v79, v45
        vminfp128 v40, v86, v44
        vnmsubfp  v3, v13, v3, v10
        vnmsubfp  v11, v12, v2, v8
        vnmsubfp  v10, v7, v1, v6
        vmaddfp   v9, v13, v5, v17
        vmaddcfp128 v0, v13, v0, v4
        vmaxfp128 v39, v85, v44
        vaddfp128 v38, v76, v63
        vaddfp128 v37, v75, v63
        vaddfp128 v36, v74, v63
        vaddfp128 v35, v73, v63
        vminfp128 v32, v72, v43
        vmrghw128 v34, v3, v52
        vmrglw128 v33, v3, v52
        vmrghw128 v54, v11, v10
        vmrglw128 v49, v11, v10
        vmaddfp   v13, v12, v9, v16
        vmaddfp128 v0, v12, v50, v0
        vmaxfp128 v53, v71, v43
        vmrglw128 v48, v66, v54
        vmrglw128 v47, v65, v49
        vmrghw128 v45, v65, v49
        vmrghw128 v46, v66, v54
        vsldoi128 v40, v94, v48, 8
        vsldoi128 v39, v80, v62, 8
        vminfp128 v48, v64, v42
        vsldoi128 v33, v94, v47, 8
        vsldoi128 v49, v79, v62, 8
        vand128   v34, v13, v57
        stvx128   v45, r10, r7
        vand128   v54, v0, v57
        stvx128   v46, r10, r5
        stvx128   v40, r0, r10
        vmaxfp128 v47, v85, v42
        stvx128   v39, r10, r6
        stvx128   v33, r10, r27
        vmaxfp128 v56, v88, v34
        stvx128   v49, r10, r28
        vmaxfp128 v55, v87, v54
        stvx128   v44, r11, r5
      }
      _R10 += 24;
      __asm
      {
        stvx128   v43, r0, r11
        stvx128   v42, r11, r6
        stvx128   v41, r11, r7
        stvx128   v38, r11, r29
        stvx128   v37, r11, r30
        stvx128   v36, r11, r31
        stvx128   v35, r11, r4
      }
      _R11 += 4;
      __asm { vminfp128 v54, v80, v41 }
      __asm { vmaxfp128 v53, v79, v41 }
    }
    while ( v13 < tw->numVerts );
  }
  _R11 = -128;
  _R10 = 6224;
  _R9 = 6228;
  _R8 = 5984;
  _R7 = 6096;
  __asm { lvx128    v63, r24, r11 }
  _R6 = 6112;
  __asm
  {
    vaddfp128 v46, v88, v63
    vaddfp128 v45, v87, v63
    vpermwi128 v44, v46, 0xB1
    vpermwi128 v43, v45, 0xB1
    vmaxfp128 v42, v78, v44
    vmaxfp128 v41, v77, v43
    vpermwi128 v40, v42, 0x4E # 'N'
    vpermwi128 v39, v41, 0x4E # 'N'
    vmaxfp128 v38, v74, v40
    vmaxfp128 v37, v73, v39
    stvewx128 v38, r3, r10
    stvewx128 v37, r3, r9
    lvx128    v63, r0, r24
    lvx128    v36, r3, r8
    vsubfp128 v35, v86, v36
    vsubfp128 v34, v85, v36
    vand128   v33, v67, v63
    stvx128   v33, r3, r7
    vand128   v32, v66, v63
    stvx128   v32, r3, r6
  }
}


// ========================================================================
// ?TranslationEdges@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@PIBVidTraceModel@@@Z
// EA  : 0x825F28E8
// RVA : 0x005F28E8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TranslationEdges(idTraceWork *tw, const idTraceModel *trm)
{
  unsigned int v6; // r8
  int v19; // r21
  int v20; // r4
  unsigned __int16 v21; // r20
  unsigned __int16 v22; // r7
  int v23; // r16
  int v24; // r17
  int v25; // r19
  int v26; // r18
  int v27; // r14
  int v31; // r4

  _R11 = 6048;
  _R9 = 6064;
  __asm { vspltisw128 v62, 0 }
  _R7 = 6080;
  v6 = 0;
  __asm
  {
    lvx128    v63, r3, r11
    lvx128    v59, r3, r9
    lvx128    v58, r3, r7
  }
  if ( tw->numEdges != 0 )
  {
    __asm
    {
      vspltw128 v60, v59, 0
      vspltw128 v3, v59, 1
    }
    _R9 = &tw->edgePluecker[0].p[4];
    _R6 = &vmx_float_cm_clip_epsilon;
    __asm
    {
      vspltw128 v2, v59, 2
      vspltw128 v61, v63, 0
    }
    _R11 = &tw->edges[0].vertexNum[1];
    __asm { vspltw128 v5, v63, 1 }
    _R10 = (unsigned __int16 *)trm->edges + 1;
    __asm { vspltw128 v4, v63, 2 }
    _R22 = 32;
    __asm { vspltw128 v59, v58, 0 }
    _R23 = 16;
    __asm
    {
      lvx128    v63, r0, r6
      vspltw128 v1, v58, 1
      vspltw128 v31, v58, 2
    }
    _R24 = 48;
    _R25 = 64;
    _R26 = 4850;
    _R27 = 4866;
    _R28 = 4882;
    _R29 = 4898;
    do
    {
      v19 = _R10[1];
      v20 = *_R10;
      v21 = _R10[2];
      v22 = _R10[4];
      v23 = *(_R10 - 1);
      _R11[7] = v19;
      v24 = v20 + 128;
      v25 = _R10[5];
      *_R11 = v20;
      _R11[8] = v21;
      v26 = _R10[6];
      v27 = _R10[3];
      _R5 = 16 * (v21 + 128);
      _R20 = 16 * (v25 + 128);
      *(_R11 - 1) = v23;
      _R11[16] = v22;
      _R11[15] = v27;
      v31 = v22 + 128;
      _R7 = 16 * (v23 + 128);
      _R11[23] = v25;
      _R11[24] = v26;
      __asm { lvx128    v57, r5, r3 }
      __asm { lvx128    v54, r7, r3 }
      _R5 = 16 * v24;
      _R7 = 16 * v31;
      __asm { lvx128    v56, r20, r3 }
      _R30 = 16 * (v19 + 128);
      _R31 = 16 * (v26 + 128);
      __asm { lvx128    v52, r5, r3 }
      _R5 = -834;
      __asm { lvx128    v51, r7, r3 }
      __asm { lvx128    v58, r30, r3 }
      _R4 = -706;
      __asm { lvx128    v55, r31, r3 }
      _R6 = 16 * (v27 + 128);
      __asm
      {
        lvx128    v53, r6, r3
        vmrghw128 v49, v86, v53
        vmrghw128 v50, v84, v51
      }
      _R6 = -962;
      __asm
      {
        vmrghw128 v48, v90, v56
        vmrghw128 v47, v89, v55
        vmrglw128 v46, v89, v55
        vmrglw128 v45, v84, v51
        vmrghw128 v44, v81, v48
        vmrglw128 v43, v82, v47
        vmrglw128 v42, v81, v48
        vmrghw128 v41, v77, v46
        vmrglw128 v40, v90, v56
        vmulfp128 v8, v76, v43
        vmrglw128 v39, v86, v53
        vmrghw128 v12, v82, v47
        vor128    v13, v74, v42
        vmulfp128 v7, v76, v41
        vor128    v10, v75, v43
        vmulfp128 v6, v74, v41
        vmrghw128 v9, v71, v40
        vsubfp128 v37, v75, v42
        vsubfp128 v38, v76, v12
        vsubfp128 v36, v9, v41
        vnmsubfp  v8, v12, v8, v13
        vnmsubfp  v0, v12, v7, v9
        vnmsubfp  v13, v10, v6, v9
        vmrghw128 v35, v8, v38
        vmrglw128 v33, v8, v38
        vmrghw128 v34, v0, v13
        lvx128    v56, r10, r6
        vmrglw128 v32, v0, v13
        vmulfp128 v12, v88, v61
        lvx128    v0, r10, r5
        vmulfp128 v11, v88, v60
        lvx128    v13, r10, r4
        vmulfp128 v10, v88, v59
        vmrghw128 v58, v68, v37
        vmrglw128 v57, v68, v37
      }
      _R7 = -16;
      __asm { vmrglw128 v55, v67, v34 }
      v6 += 4;
      __asm { vmrglw128 v54, v65, v32 }
      _R10 += 8;
      __asm
      {
        vsldoi128 v53, v90, v58, 8
        vsldoi128 v52, v89, v57, 8
        vmrghw128 v51, v67, v34
        vmrghw128 v50, v65, v32
        vsldoi128 v49, v85, v55, 8
        vsldoi128 v48, v87, v53, 8
        vmaddfp   v12, v0, v12, v5
        vsldoi128 v47, v84, v54, 8
        vmaddfp   v11, v0, v11, v3
        vsldoi128 v46, v86, v52, 8
        vmaddfp   v0, v0, v10, v1
        stvx128   v46, r9, r25
        stvx128   v51, r9, r7
        stvx128   v50, r9, r22
        stvx128   v49, r0, r9
        stvx128   v48, r9, r23
        stvx128   v47, r9, r24
      }
      _R9 += 24;
      __asm
      {
        vmaddfp   v12, v13, v12, v4
        vmaddfp   v11, v13, v11, v2
        vmaddfp   v0, v13, v0, v31
        vmulfp128 v45, v12, v63
        vmulfp128 v44, v11, v63
        vmulfp128 v43, v0, v63
        vmrghw128 v42, v76, v62
        vmrghw128 v41, v77, v43
        vmrglw128 v40, v77, v43
        vmrglw128 v39, v76, v62
        vmrghw128 v38, v73, v42
        vmrglw128 v37, v73, v42
        vmrghw128 v36, v72, v39
        vmrglw128 v35, v72, v39
        stvx128   v38, r11, r26
        stvx128   v37, r11, r27
        stvx128   v36, r11, r28
        stvx128   v35, r11, r29
      }
      _R11 += 32;
    }
    while ( v6 < tw->numEdges );
  }
}


// ========================================================================
// ?TranslationPolys@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@PIBVidTraceModel@@@Z
// EA  : 0x825F2B98
// RVA : 0x005F2B98
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TranslationPolys(idTraceWork *tw, const idTraceModel *trm)
{
  unsigned int v6; // r9

  _R11 = 6048;
  _R8 = 6064;
  _R7 = 6080;
  v6 = 0;
  __asm
  {
    lvx128    v60, r3, r11
    lvx128    v59, r3, r8
    lvx128    v58, r3, r7
  }
  if ( tw->numPolys != 0 )
  {
    __asm { vspltw128 v63, v60, 0 }
    _R7 = -64;
    __asm { vspltw128 v5, v60, 1 }
    _R6 = 64;
    __asm { vspltw128 v4, v60, 2 }
    _R10 = &tw->polys[1];
    __asm { vspltw128 v62, v59, 0 }
    _R11 = trm->polyPlaneY;
    __asm { vspltw128 v3, v59, 1 }
    _R8 = 128;
    __asm
    {
      vspltw128 v2, v59, 2
      vspltw128 v61, v58, 0
      vspltw128 v1, v58, 1
      vspltw128 v31, v58, 2
      vspltw128 v60, v60, 3
      vspltw128 v59, v59, 3
      vspltw128 v58, v58, 3
    }
    do
    {
      __asm
      {
        lvx128    v57, r11, r7
        vor128    v10, v92, v60
        vmulfp128 v9, v89, v63
        lvx128    v0, r0, r11
        vmulfp128 v7, v89, v62
        lvx128    v13, r11, r6
        vmulfp128 v6, v89, v61
        lvx128    v8, r11, r8
        vor128    v11, v91, v59
      }
      v6 += 4;
      __asm { vor128    v12, v90, v58 }
      _R11 += 4;
      __asm
      {
        vmaddfp   v9, v0, v9, v5
        vmaddfp   v7, v0, v7, v3
        vmaddfp   v0, v0, v6, v1
        vmaddfp   v9, v13, v9, v4
        vmaddfp   v7, v13, v7, v2
        vmaddfp   v0, v13, v0, v31
        vnmsubfp  v8, v9, v8, v10
        vmr128    v56, v9
        vmr128    v55, v0
        vmrghw128 v54, v88, v55
        vmrglw128 v53, v88, v55
        vnmsubfp  v10, v7, v8, v11
        vnmsubfp  v13, v0, v10, v12
        vmrghw128 v52, v7, v13
        vmrglw128 v51, v7, v13
        vmrghw128 v50, v86, v52
        vmrglw128 v49, v86, v52
        vmrghw128 v48, v85, v51
        vmrglw128 v47, v85, v51
        stvx128   v50, r10, r7
        stvx128   v49, r0, r10
        stvx128   v48, r10, r6
        stvx128   v47, r10, r8
      }
      _R10 += 4;
    }
    while ( v6 < tw->numPolys );
  }
}


// ========================================================================
// ?TranslationBounds@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@@Z
// EA  : 0x825F2CA8
// RVA : 0x005F2CA8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TranslationBounds(idTraceWork *tw)
{
  _R11 = 5984;
  _R10 = 6000;
  _R9 = 6096;
  _R8 = 6112;
  __asm { lvx128    v63, r3, r11 }
  _R6 = -80;
  __asm { lvx128    v62, r3, r10 }
  _R5 = vmxi_float_abs_mask_6;
  __asm
  {
    vminfp128 v60, v95, v62
    lvx128    v59, r3, r9
    vmaxfp128 v58, v95, v62
    lvx128    v57, r3, r8
  }
  _R4 = -48;
  _R11 = 48;
  __asm { lvx128    v63, r5, r6 }
  _R10 = 112;
  __asm { lvx128    v62, r0, r5 }
  _R9 = 6144;
  __asm { vand128   v56, v89, v62 }
  _R8 = 6160;
  __asm
  {
    lvx128    v61, r5, r4
    vand128   v55, v91, v62
    lvx128    v0, r5, r11
  }
  _R7 = 6176;
  __asm { lvx128    v7, r5, r10 }
  _R6 = 6128;
  __asm
  {
    vmaxfp128 v54, v87, v56
    vaddfp128 v53, v92, v59
    vaddfp128 v52, v90, v57
    vaddfp128 v51, v86, v63
    vsubfp128 v50, v85, v63
    vaddfp128 v49, v84, v63
    vaddfp128 v48, v82, v61
    stvx128   v50, r3, r9
    vsubfp128 v47, v81, v61
    stvx128   v49, r3, r8
    vcfpsxws128 v13, v48, 0
    vcfpsxws128 v12, v47, 0
    vsubsws   v11, v13, v0
    vaddsws   v10, v12, v0
    vpkswss128 v63, v11, v10
    vperm128  v46, v95, v63, v7
    stvx128   v46, r3, r7
    stvx128   v51, r3, r6
  }
}


// ========================================================================
// ?TranslationUpdateBounds@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@@Z
// EA  : 0x825F2D60
// RVA : 0x005F2D60
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TranslationUpdateBounds(idTraceWork *tw)
{
  _R11 = &tw->fraction;
  _R10 = 5984;
  _R9 = 6016;
  _R8 = 6096;
  _R7 = 6112;
  __asm { lvsl      v0, 0, r11 }
  __asm { lvewx128  v63, r0, r11 }
  _R5 = -192;
  __asm
  {
    vspltw    v7, v0, 0
    lvx128    v0, r3, r10
    lvx128    v12, r3, r9
  }
  _R4 = vmxi_word_perm_bounds_short_3;
  __asm { lvx128    v61, r3, r8 }
  _R11 = -160;
  __asm { lvx128    v60, r3, r7 }
  _R10 = -64;
  __asm { vperm128  v13, v95, v63, v7 }
  _R9 = 6144;
  _R8 = 6160;
  __asm { lvx128    v63, r4, r5 }
  _R7 = 6176;
  __asm
  {
    lvx128    v62, r4, r11
    vmaddfp   v12, v13, v0, v12
    lvx128    v13, r4, r10
    lvx128    v7, r0, r4
    vminfp128 v59, v0, v12
    vmaxfp128 v58, v0, v12
    vaddfp128 v57, v91, v61
    vaddfp128 v56, v90, v60
    vsubfp128 v55, v89, v63
    vaddfp128 v54, v88, v63
    vaddfp128 v53, v87, v62
    stvx128   v55, r3, r9
    vsubfp128 v52, v86, v62
    stvx128   v54, r3, r8
    vcfpsxws128 v6, v53, 0
    vcfpsxws128 v5, v52, 0
    vsubsws   v4, v6, v13
    vaddsws   v3, v5, v13
    vpkswss128 v63, v4, v3
    vperm128  v51, v95, v63, v7
    stvx128   v51, r3, r7
  }
}


// ========================================================================
// ?TranslationPlueckerCache@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@PIBUcm_polygon_t@@@Z
// EA  : 0x825F2E10
// RVA : 0x005F2E10
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TranslationPlueckerCache(
        idTraceWork *tw,
        const cm_polygon_t *polygon)
{
  int v5; // r5
  unsigned int v12; // ctr
  unsigned __int16 *polygonEdges; // r8
  cm_edge_t *edges; // r10
  unsigned __int16 *v18; // r9
  unsigned int v19; // r23
  unsigned int v20; // r22
  unsigned int v21; // r21
  unsigned int v22; // r24
  unsigned __int16 *v23; // r9
  unsigned __int16 *v24; // r8
  unsigned __int16 *v25; // r7
  unsigned __int16 *v26; // r10
  int back_chain; // [sp+0h] [-A0h]

  _R9 = 6016;
  __asm { vspltisw128 v59, 0 }
  _R8 = vmxi_float_sign_bit_6;
  v5 = 0;
  __asm
  {
    lvx128    v62, r3, r9
    lvx128    v63, r0, r8
    vxor128   v60, v94, v63
    vspltw128 v61, v62, 2
    vspltw128 v58, v62, 0
    vspltw128 v62, v60, 1
    vmrghw128 v63, v93, v62
  }
  if ( polygon->numEdges != 0 )
  {
    __asm { vspltw128 v61, v60, 0 }
    _R6 = tw->polygonVertexSideCache;
    __asm { vspltw128 v60, v60, 2 }
    _R26 = 384;
    back_chain = polygon->firstEdge;
    _R27 = 400;
    _R28 = 416;
    _R29 = 432;
    v12 = (((unsigned int)polygon->numEdges - 1) >> 2) + 1;
    _R11 = &tw->polygonEdgePlueckerCache[0].p[4];
    _R30 = 448;
    _R31 = -80;
    do
    {
      polygonEdges = tw->subModelPtrs.polygonEdges;
      edges = tw->subModelPtrs.edges;
      _R25 = tw->subModelPtrs.vertices;
      v18 = &polygonEdges[back_chain + v5];
      v19 = *v18;
      v20 = v18[1];
      v21 = polygonEdges[back_chain + 2 + v5];
      v22 = polygonEdges[back_chain + 3 + v5];
      v23 = (unsigned __int16 *)((char *)edges + ((4 * v19) & 0xFFFC));
      v24 = (unsigned __int16 *)((char *)edges + ((4 * v20) & 0xFFFC));
      v25 = (unsigned __int16 *)((char *)edges + ((4 * v21) & 0xFFFC));
      v26 = (unsigned __int16 *)((char *)edges + ((4 * v22) & 0xFFFC));
      _R20 = __ROL4__(v23[1], 4);
      _R4 = __ROL4__(*v23, 4);
      _R19 = __ROL4__(*v24, 4);
      _R18 = __ROL4__(v24[1], 4);
      __asm { lvx128    v57, r4, r25 }
      _R17 = __ROL4__(*v25, 4);
      _R16 = __ROL4__(v25[1], 4);
      __asm { lvx128    v56, r20, r25 }
      _R4 = __ROL4__(v26[1], 4);
      __asm { lvx128    v55, r19, r25 }
      _R15 = __ROL4__(*v26, 4);
      __asm { lvx128    v54, r18, r25 }
      _R20 = 16;
      __asm
      {
        lvx128    v53, r17, r25
        lvx128    v52, r16, r25
        lvx128    v49, r4, r25
        vmrghw128 v50, v89, v53
        lvx128    v51, r15, r25
        vmrghw128 v48, v88, v52
        vmrghw128 v46, v86, v49
      }
      _R4 = -16;
      __asm { vmrghw128 v47, v87, v51 }
      _R25 = 32;
      __asm
      {
        vmrglw128 v44, v88, v52
        vmrglw128 v45, v86, v49
        vmrglw128 v42, v80, v46
        vmrghw128 v43, v82, v47
        vmrglw128 v41, v82, v47
        vmrghw128 v40, v76, v45
        vmrglw128 v39, v87, v51
        vor128    v10, v74, v42
        vmulfp128 v8, v75, v42
        vmrglw128 v38, v89, v53
        vmrghw128 v12, v80, v46
        vor128    v13, v73, v41
        vmulfp128 v7, v75, v40
        vmulfp128 v6, v73, v40
        vmrghw128 v9, v70, v39
        vsubfp128 v37, v74, v41
        vsubfp128 v36, v75, v12
        vsubfp128 v35, v9, v40
        vnmsubfp  v8, v12, v8, v13
        vnmsubfp  v0, v12, v7, v9
        vnmsubfp  v13, v10, v6, v9
        vmrghw128 v56, v67, v37
        vmrglw128 v55, v67, v37
        vmrghw128 v34, v8, v36
        vmrglw128 v33, v8, v36
        vmrghw128 v32, v0, v13
        vmrglw128 v57, v0, v13
        vmrglw128 v54, v66, v32
      }
      _R19 = 48;
      __asm { vmrglw128 v53, v65, v57 }
      _R18 = 64;
      __asm { vsldoi128 v52, v88, v56, 8 }
      __asm { vsldoi128 v51, v87, v55, 8 }
      __asm { vmrghw128 v50, v66, v32 }
      __asm { vmrghw128 v49, v65, v57 }
      __asm
      {
        vsldoi128 v48, v84, v54, 8
        vor128    v13, v93, v61
        vsldoi128 v47, v86, v52, 8
      }
      __asm { vsldoi128 v46, v83, v53, 8 }
      __asm { vsldoi128 v45, v85, v51, 8 }
      _R9 = __ROL4__(*(unsigned __int16 *)((char *)v23 + ((v19 >> 14) & 2)), 4);
      __asm { stvx128   v50, r11, r4 }
      _R8 = __ROL4__(*(unsigned __int16 *)((char *)v24 + ((v20 >> 14) & 2)), 4);
      __asm { stvx128   v49, r11, r25 }
      _R4 = __ROL4__(*(unsigned __int16 *)((char *)v26 + ((v22 >> 14) & 2)), 4);
      __asm { stvx128   v48, r0, r11 }
      _R7 = __ROL4__(*(unsigned __int16 *)((char *)v25 + ((v21 >> 14) & 2)), 4);
      __asm
      {
        stvx128   v47, r11, r20
        vor128    v11, v93, v61
        stvx128   v46, r11, r19
        vor128    v9, v94, v62
        stvx128   v45, r11, r18
      }
      _R25 = tw->subModelPtrs.vertices;
      _R10 = 368;
      v5 += 4;
      __asm
      {
        lvx128    v44, r9, r25
        lvx128    v43, r8, r25
        lvx128    v42, r7, r25
        lvx128    v41, r4, r25
        vmrghw128 v40, v76, v42
        vmrghw128 v39, v75, v41
        vmrglw128 v38, v75, v41
        vmrglw128 v37, v76, v42
        vmrghw128 v36, v72, v39
        vmrglw128 v35, v72, v39
        vmrghw128 v10, v69, v38
        vmulfp128 v8, v68, v62
        vmulfp128 v7, v68, v60
        vor128    v0, v67, v35
        vmulfp128 v6, v67, v60
        vmr       v12, v10
        vnmsubfp  v8, v0, v8, v13
        vnmsubfp  v0, v12, v7, v11
        vnmsubfp  v13, v10, v6, v9
        vmrghw128 v34, v8, v58
        vmrglw128 v33, v8, v58
        vmrghw128 v32, v0, v13
        vmrglw128 v57, v0, v13
        vmrglw128 v56, v66, v32
        vmrglw128 v54, v65, v57
        vmrghw128 v55, v66, v32
        vmrghw128 v53, v65, v57
        vsldoi128 v52, v95, v56, 8
        vsldoi128 v51, v88, v63, 8
        vsldoi128 v50, v95, v54, 8
        vsldoi128 v49, v86, v63, 8
        stvx128   v55, r11, r10
        stvx128   v53, r11, r28
        stvx128   v52, r11, r26
        stvx128   v51, r11, r27
        stvx128   v50, r11, r29
        stvx128   v49, r11, r30
      }
      _R11 += 24;
      __asm
      {
        stvx128   v59, r6, r31
        stvx128   v59, r0, r6
      }
      _R6 += 4;
      --v12;
    }
    while ( v12 != 0 );
  }
}


// ========================================================================
// ?TranslationEdgePlueckerCache@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@PIBUcm_polygon_t@@@Z
// EA  : 0x825F3118
// RVA : 0x005F3118
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TranslationEdgePlueckerCache(
        idTraceWork *tw,
        const cm_polygon_t *polygon)
{
  int v2; // r8
  int numEdges; // ctr
  int firstEdge; // r5
  cm_sideCache_t *p_polygonSideCache; // r7
  float *p_side; // r11
  int v7; // r4
  cm_vertex_t *vertices; // r9
  cm_edge_t *v9; // r10
  int v10; // r4
  float *v11; // r10
  float *v12; // r9
  double v13; // fp13
  double v14; // fp0
  double v15; // fp9
  double v16; // fp10
  double v17; // fp11
  double v18; // fp8
  double v19; // fp7
  double v20; // fp6
  double v21; // fp5

  v2 = 0;
  if ( polygon->numEdges != 0 )
  {
    numEdges = polygon->numEdges;
    firstEdge = polygon->firstEdge;
    p_polygonSideCache = &tw->polygonSideCache;
    p_side = (float *)&tw->polygonVertexSideCache[19].side;
    do
    {
      v7 = firstEdge + v2++;
      vertices = tw->subModelPtrs.vertices;
      v9 = &tw->subModelPtrs.edges[tw->subModelPtrs.polygonEdges[v7] & 0x3FFF];
      v10 = v9->vertexNum[0];
      v11 = (float *)((char *)&vertices->p.x + __ROL4__(v9->vertexNum[1], 4));
      v12 = (float *)((char *)&vertices->p.x + __ROL4__(v10, 4));
      v13 = v12[1];
      v14 = v11[1];
      v15 = (float)(*v11 * v12[1]);
      v16 = v12[2];
      v17 = (float)(v11[1] - v12[1]);
      v18 = (float)(v12[2] * *v11);
      v19 = *v12;
      v20 = (float)(v12[2] * v11[1]);
      v21 = v11[2];
      p_side[3] = *v12 - *v11;
      p_side[5] = (float)v16 - (float)v21;
      p_side[1] = (float)((float)v19 * (float)v14) - (float)v15;
      p_side[2] = (float)((float)v21 * (float)v19) - (float)v18;
      p_side[4] = (float)((float)v21 * (float)v13) - (float)v20;
      p_side += 6;
      *p_side = v17;
      ++p_polygonSideCache;
      p_polygonSideCache->side = 0;
      --numEdges;
    }
    while ( numEdges != 0 );
  }
}


// ========================================================================
// ?TranslationSideCache@idPolygonModelCollisionDetection@@CAXPIBVidPluecker@@PBEI0PIAUcm_sideCache_t@@I@Z
// EA  : 0x825F31E8
// RVA : 0x005F31E8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TranslationSideCache(
        const idPluecker *pluecker,
        const unsigned __int8 *used,
        unsigned int count,
        const idPluecker *plueckerCache,
        cm_sideCache_t *sideCache,
        const unsigned int cacheSize)
{
  unsigned int v7; // r26
  unsigned int v18; // ctr

  __asm { vspltisw128 v58, 1 }
  v7 = 0;
  __asm { vor128    v60, v90, v58 }
  if ( count != 0 )
  {
    _R29 = pluecker;
    _R30 = 16;
    _R24 = 24;
    _R25 = 8;
    _R27 = 48;
    _R28 = 32;
    do
    {
      if ( used[v7] != 0 )
      {
        __asm { lvlx128   v63, r0, r29 }
        __asm
        {
          lvrx128   v62, r30, r29
          vor128    v61, v95, v62
          lvrx128   v59, r24, r29
          lvlx128   v57, r25, r29
          vor128    v56, v89, v59
          vor128    v63, v93, v61
          vpermwi128 v62, v61, 0xE1
          vpermwi128 v61, v56, 0xB4
          vrlimi128 v63, v56, 3, 0
        }
        if ( cacheSize != 0 )
        {
          __asm { vspltisw128 v59, 0 }
          _R10 = sideCache;
          _R11 = (char *)&plueckerCache[1].p[2];
          _R9 = -32;
          _R3 = -16;
          v18 = ((cacheSize - 1) >> 2) + 1;
          do
          {
            __asm
            {
              lvx128    v55, r11, r9
              lvx128    v54, r0, r11
              vmulfp128 v53, v87, v61
              lvx128    v52, r11, r30
              vmulfp128 v51, v86, v62
              lvx128    v50, r11, r27
              vmulfp128 v49, v84, v61
              vmulfp128 v48, v82, v62
              lvx128    v47, r11, r3
              lvx128    v46, r11, r28
              vmulfp128 v45, v79, v63
              vmulfp128 v44, v78, v63
              lvx128    v43, r0, r10
            }
            _R11 += 96;
            __asm
            {
              vmrglw128 v42, v85, v49
              vmrghw128 v41, v85, v49
              vmrglw128 v40, v83, v48
              vmrghw128 v39, v83, v48
              vmrghw128 v38, v77, v44
              vaddfp128 v37, v73, v42
              vmrglw128 v36, v77, v44
              vaddfp128 v35, v71, v40
              vmrglw128 v34, v70, v36
              vmrghw128 v33, v70, v36
              vaddfp128 v32, v65, v34
              vmrglw128 v57, v69, v35
              vmrghw128 v56, v69, v35
              vaddfp128 v55, v88, v57
              vaddfp128 v54, v87, v32
              vcmpgefp128 v53, v91, v54
              vand128   v52, v85, v60
              vor128    v51, v75, v52
              stvx128   v51, r0, r10
            }
            _R10 += 4;
            --v18;
          }
          while ( v18 != 0 );
        }
      }
      ++v7;
      __asm { vslw128   v60, v92, v58 }
      ++_R29;
    }
    while ( v7 < count );
  }
}


// ========================================================================
// ?TranslationPolygonSideCache@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@PIBUcm_polygon_t@@@Z
// EA  : 0x825F3320
// RVA : 0x005F3320
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TranslationPolygonSideCache(
        idTraceWork *tw,
        const cm_polygon_t *polygon)
{
  int numEdges; // r9
  int v3; // r11
  int firstEdge; // r8
  cm_sideCache_t *p_polygonSideCache; // r10
  unsigned __int16 *polygonEdges; // r7
  int i; // ctr
  int v8; // r4

  numEdges = polygon->numEdges;
  v3 = 0;
  tw->polygonSideCache.side = 0;
  if ( numEdges != 0 )
  {
    firstEdge = polygon->firstEdge;
    p_polygonSideCache = &tw->polygonSideCache;
    polygonEdges = tw->subModelPtrs.polygonEdges;
    for ( i = numEdges; i != 0; --i )
    {
      ++p_polygonSideCache;
      v8 = firstEdge + v3++;
      tw->polygonSideCache.side |= -(polygonEdges[v8] >> 15) ^ p_polygonSideCache->side;
    }
  }
}


// ========================================================================
// ?AddContact@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@@Z
// EA  : 0x825F3378
// RVA : 0x005F3378
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::AddContact(idTraceWork *tw)
{
  contactsResult_t *contactsResult; // r9
  contactsResult_t *v3; // r10
  trace_t *traceResult; // r9

  contactsResult = tw->contactsResult;
  if ( contactsResult->numContacts < 12 )
  {
    contactInfo_t::operator=(this: &contactsResult->contacts[contactsResult->numContacts], __that: &tw->traceResult->c);
    v3 = tw->contactsResult;
    traceResult = tw->traceResult;
    tw->fraction = 1.0;
    ++v3->numContacts;
    traceResult->fraction = 1.0;
  }
}


// ========================================================================
// ?TranslateEdgeThroughEdge@idPolygonModelCollisionDetection@@CAMABVidPluecker@@0ABVidVec3@@@Z
// EA  : 0x825F33F0
// RVA : 0x005F33F0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

float __fastcall idPolygonModelCollisionDetection::TranslateEdgeThroughEdge(
        const idPluecker *l1,
        const idPluecker *l2,
        const idVec3 *dir)
{
  double v3; // fp1

  if ( (float)((float)((float)((float)(dir->y * l1->p[4]) + (float)(dir->z * l1->p[5])) * l2->p[2])
             + (float)((float)((float)-(float)((float)(dir->x * l1->p[5]) - (float)-(float)(l1->p[2] * dir->y))
                             * l2->p[4])
                     + (float)((float)((float)(dir->x * l1->p[4]) - (float)(l1->p[2] * dir->z)) * l2->p[5]))) == 0.0 )
    v3 = -1.0;
  else
    v3 = (float)((float)((float)(l1->p[4] * l2->p[0])
                       + (float)((float)(l1->p[0] * l2->p[4])
                               + (float)((float)(l2->p[1] * l1->p[5])
                                       + (float)((float)(l1->p[3] * l2->p[2])
                                               + (float)((float)(l1->p[1] * l2->p[5]) + (float)(l2->p[3] * l1->p[2]))))))
               / (float)((float)((float)((float)(dir->y * l1->p[4]) + (float)(dir->z * l1->p[5])) * l2->p[2])
                       + (float)((float)((float)-(float)((float)(dir->x * l1->p[5]) - (float)-(float)(l1->p[2] * dir->y))
                                       * l2->p[4])
                               + (float)((float)((float)(dir->x * l1->p[4]) - (float)(l1->p[2] * dir->z)) * l2->p[5]))));
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?TranslateTrmEdgesThroughPolygon@idPolygonModelCollisionDetection@@CA_NPIAVidTraceWork@@PIBUcm_polygon_t@@@Z
// EA  : 0x825F34A0
// RVA : 0x005F34A0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::TranslateTrmEdgesThroughPolygon(
        idTraceWork *tw,
        const cm_polygon_t *poly)
{
  unsigned int v4; // r18
  float *p_z; // r17
  float *i; // r20
  unsigned int v7; // r22
  idPluecker *polygonEdgePlueckerCache; // r16
  cm_sideCache_t *polygonEdgeSideCache; // r14
  unsigned int v10; // r6
  int v11; // r24
  unsigned __int16 v12; // r23
  unsigned int v13; // r30
  BOOL v14; // r29
  int v15; // r28
  int v16; // r27
  double v17; // fp30
  double v18; // fp12
  double v19; // fp10
  double v20; // fp9
  double v21; // fp11
  double v22; // fp6
  double v23; // fp5
  double v24; // fp4
  double v25; // fp3
  double v26; // fp1
  trace_t *traceResult; // r9
  cm_vertex_t *vertices; // r10
  cm_edge_t *v29; // r11
  int v30; // r6
  idVec4 *v31; // r29
  int v32; // r11
  int v33; // r8
  idVec4 *v34; // r27
  float *v35; // r30
  float *v36; // r28
  double v37; // fp0
  double v38; // fp13
  double v39; // fp12
  double v40; // fp11
  double v41; // fp10
  double v42; // fp8
  trace_t *v43; // r11
  double z; // fp0
  double y; // fp13
  double x; // fp12
  double v47; // fp4
  double v48; // fp2
  double v49; // fp4
  char *v50; // r10
  double v51; // fp2
  traceType_t traceType; // r5
  double v53; // fp3
  double v54; // fp10
  int v55; // r4
  double v56; // fp8
  double v57; // fp7
  double v58; // fp1
  double v59; // fp11
  double v60; // fp1
  double v61; // fp10
  double v62; // fp6
  double v63; // fp3
  double v64; // fp0
  double v65; // fp2
  double v66; // fp5
  double v67; // fp3
  double v68; // fp9
  double v69; // fp8
  int v71; // [sp+50h] [-E0h]
  idPluecker v72; // [sp+60h] [-D0h] BYREF

  v71 = 1;
  v4 = 0;
  if ( tw->numEdges == 0 )
    return 0;
  p_z = &tw->edgeNormal[0].z;
  for ( i = &tw->edgePluecker[0].p[2]; ; i += 6 )
  {
    if ( tw->edgeIsUsed[v4] != 0 )
    {
      v7 = 0;
      if ( poly->numEdges != 0 )
        break;
    }
LABEL_22:
    ++v4;
    p_z += 4;
    v71 *= 2;
    if ( v4 >= tw->numEdges )
      return 0;
  }
  polygonEdgePlueckerCache = tw->polygonEdgePlueckerCache;
  polygonEdgeSideCache = tw->polygonEdgeSideCache;
  while ( 1 )
  {
    v10 = tw->subModelPtrs.polygonEdges[poly->firstEdge + v7];
    v11 = v10 & 0x3FFF;
    v12 = tw->subModelPtrs.polygonEdges[poly->firstEdge + v7];
    if ( ((1 << (v10 & 7)) & tw->modelCheckCounts.edgeCheckCounts[v11 >> 3]) != 0 )
      goto LABEL_21;
    if ( (v10 & 0x4000) != 0 )
      goto LABEL_21;
    v13 = v10 >> 15;
    v14 = (~(_WORD)v10 & 0x8000) != 0;
    if ( ((tw->polygonVertexSideCache[(v10 >> 15) + v7].side ^ tw->polygonVertexSideCache[v14 + v7].side) & v71) == 0 )
      goto LABEL_21;
    v15 = *((unsigned __int16 *)p_z - 2429);
    v16 = *((unsigned __int16 *)p_z - 2430);
    if ( (((polygonEdgeSideCache->side >> v16) ^ (polygonEdgeSideCache->side >> v15)) & 1) == 0 )
      goto LABEL_21;
    v17 = idPolygonModelCollisionDetection::TranslateEdgeThroughEdge(
            l1: polygonEdgePlueckerCache,
            l2: (const idPluecker *)(i - 2),
            dir: (const idVec3 *)&tw->negDir);
    if ( v17 < 0.0 )
      goto LABEL_21;
    v18 = (float)(*i * *(p_z - 1));
    v19 = i[2];
    v20 = *(p_z - 2);
    v21 = i[3];
    v22 = (float)-(float)((float)(*(p_z - 2) * i[2]) - *(i - 1));
    v23 = (float)-(float)((float)(*(p_z - 1) * i[2]) - i[1]);
    v24 = *p_z;
    v25 = *(i - 2);
    v72.p[2] = *i;
    v72.p[5] = v21;
    v72.p[4] = v19;
    v72.p[1] = (float)((float)v24 * v72.p[2]) + (float)v22;
    v72.p[3] = -(float)((float)((float)v24 * (float)v21) - (float)v23);
    v72.p[0] = (float)((float)((float)v20 * (float)v21) + (float)v18) + (float)v25;
    v26 = idPolygonModelCollisionDetection::TranslateEdgeThroughEdge(
            l1: polygonEdgePlueckerCache,
            l2: &v72,
            dir: (const idVec3 *)&tw->negDir);
    if ( v26 > 1.0 || v17 < v26 )
      goto LABEL_21;
    if ( v26 < 0.0 )
      v26 = 0.0;
    traceResult = tw->traceResult;
    if ( v26 >= traceResult->fraction )
      goto LABEL_21;
    vertices = tw->subModelPtrs.vertices;
    v29 = &tw->subModelPtrs.edges[v11];
    tw->fraction = v26;
    v30 = v29->vertexNum[v14];
    v31 = &tw->vertexPosition[v16];
    v32 = __ROL4__(v29->vertexNum[v13], 4);
    traceResult->fraction = v26;
    v33 = __ROL4__(v30, 4);
    v34 = &tw->vertexPosition[v15];
    v35 = (float *)((char *)&vertices->p.x + v32);
    v36 = (float *)((char *)&vertices->p.x + v33);
    v37 = (float)(v34->x - v31->x);
    v38 = (float)(v34->z - v31->z);
    v39 = (float)(*(float *)((char *)&vertices->p.y + v32) - *(float *)((char *)&vertices->p.y + v33));
    v40 = (float)(*(float *)((char *)&vertices->p.z + v32) - *(float *)((char *)&vertices->p.z + v33));
    v41 = (float)((float)(v34->z - v31->z)
                * (float)(*(float *)((char *)&vertices->p.x + v32) - *(float *)((char *)&vertices->p.x + v33)));
    v42 = (float)((float)(*(float *)((char *)&vertices->p.z + v32) - *(float *)((char *)&vertices->p.z + v33))
                * (float)(v34->y - v31->y));
    traceResult->c.normal.z = (float)((float)(v34->y - v31->y)
                                    * (float)(*(float *)((char *)&vertices->p.x + v32)
                                            - *(float *)((char *)&vertices->p.x + v33)))
                            - (float)((float)(*(float *)((char *)&vertices->p.y + v32)
                                            - *(float *)((char *)&vertices->p.y + v33))
                                    * (float)(v34->x - v31->x));
    traceResult->c.normal.y = (float)((float)v40 * (float)v37) - (float)v41;
    traceResult->c.normal.x = (float)((float)v39 * (float)v38) - (float)v42;
    idVec3::NormalizeFast(this: &traceResult->c.normal);
    v43 = tw->traceResult;
    z = tw->dir.z;
    y = tw->dir.y;
    x = tw->dir.x;
    v47 = v43->c.normal.z;
    v48 = v43->c.normal.y;
    if ( (float)((float)(tw->dir.x * v43->c.normal.x)
               + (float)((float)(v43->c.normal.y * tw->dir.y) + (float)(v43->c.normal.z * tw->dir.z))) > 0.0 )
    {
      v43->c.normal.x = -v43->c.normal.x;
      v43->c.normal.y = -v48;
      v43->c.normal.z = -v47;
    }
    v49 = v31->y;
    v50 = (char *)tw->subModelPtrs.materials + __ROL4__(poly->material, 4);
    v51 = v31->x;
    traceType = tw->traceType;
    v53 = v31->z;
    v54 = (float)(v34->x - v31->x);
    v55 = (tw->subModelNum << 16) & 0x1FFF0000 | 0x40000000 | v12 & 0x3FFF;
    v56 = (float)(v34->y - v31->y);
    v57 = (float)(v34->z - v31->z);
    v58 = (float)((float)z * (float)(v34->x - v31->x));
    v59 = (float)((float)(*v35 * v43->c.normal.x)
                + (float)((float)(v43->c.normal.y * v35[1]) + (float)(v43->c.normal.z * v35[2])));
    v43->c.dist = (float)(*v35 * v43->c.normal.x)
                + (float)((float)(v43->c.normal.y * v35[1]) + (float)(v43->c.normal.z * v35[2]));
    v60 = (float)((float)((float)x * (float)v57) - (float)v58);
    v61 = (float)((float)((float)y * (float)v54) - (float)((float)x * (float)v56));
    v43->c.separation = (float)((float)(v43->c.normal.x * (float)v51)
                              + (float)((float)(v43->c.normal.z * (float)v53) + (float)(v43->c.normal.y * (float)v49)))
                      - (float)v59;
    v62 = (float)((float)((float)z * (float)v56) - (float)((float)y * (float)v57));
    v43->c.contentFlags = *(_DWORD *)v50;
    v43->c.surfaceFlags = *((_DWORD *)v50 + 1);
    v63 = (float)((float)((float)((float)((float)z * (float)v56) - (float)((float)y * (float)v57)) * (float)v51)
                + (float)((float)((float)v61 * (float)v53) + (float)((float)v60 * (float)v49)));
    v43->c.surfaceType = *((_DWORD *)v50 + 2);
    v43->c.surfaceColor[0] = v50[12];
    v43->c.surfaceColor[1] = v50[13];
    v43->c.surfaceColor[2] = v50[14];
    v43->c.type = CONTACT_EDGE;
    v43->c.modelFeature = v55;
    v43->c.trmFeature = v4;
    v43->c.flags = 0;
    v65 = v35[2];
    v66 = (float)((float)((float)((float)((float)((float)z * (float)v56) - (float)((float)y * (float)v57)) * *v35)
                        + (float)((float)((float)v60 * v35[1]) + (float)((float)v61 * v35[2])))
                - (float)v63);
    v64 = v35[1];
    v67 = (float)((float)((float)((float)((float)v62 * *v35)
                                + (float)((float)((float)v60 * v35[1]) + (float)((float)v61 * v35[2])))
                        - (float)v63)
                - (float)((float)((float)((float)v62 * *v36)
                                + (float)((float)((float)v60 * v36[1]) + (float)((float)v61 * v36[2])))
                        - (float)v63));
    v68 = (float)((float)(v36[1] - v35[1]) * (float)((float)v66 / (float)v67));
    v69 = (float)((float)(v36[2] - v35[2]) * (float)((float)v66 / (float)v67));
    v43->c.point.x = (float)((float)(*v36 - *v35) * (float)((float)v66 / (float)v67)) + *v35;
    v43->c.point.y = (float)v68 + (float)v64;
    v43->c.point.z = (float)v69 + (float)v65;
    if ( traceType != TRACE_CONTACTS_UNI_DIR )
      break;
    idPolygonModelCollisionDetection::AddContact(tw);
LABEL_21:
    ++v7;
    ++polygonEdgeSideCache;
    ++polygonEdgePlueckerCache;
    if ( v7 >= poly->numEdges )
      goto LABEL_22;
  }
  if ( tw->fraction != 0.0 )
    goto LABEL_21;
  return 1;
}


// ========================================================================
// ?TranslatePointThroughPlane@idPolygonModelCollisionDetection@@CAMABVidPlane@@ABVidVec3@@1@Z
// EA  : 0x825F3990
// RVA : 0x005F3990
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

float __fastcall idPolygonModelCollisionDetection::TranslatePointThroughPlane(
        const idPlane *plane,
        const idVec3 *start,
        const idVec3 *end)
{
  double v3; // fp9
  double v4; // fp1
  double v5; // fp0

  v3 = (float)((float)((float)(plane->a * end->x) + (float)((float)(end->y * plane->b) + (float)(end->z * plane->c)))
             + plane->d);
  if ( v3 >= 0.25
    || (v5 = (float)((float)((float)(start->x * plane->a)
                           + (float)((float)(start->y * plane->b) + (float)(start->z * plane->c)))
                   + plane->d)) < 0.0
    || v5 <= v3 )
  {
    v4 = 1.0;
  }
  else
  {
    v4 = (float)((float)((float)v5 - (float)0.25)
               / (float)((float)v5
                       - (float)((float)((float)(plane->a * end->x)
                                       + (float)((float)(end->y * plane->b) + (float)(end->z * plane->c)))
                               + plane->d)));
  }
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?TranslateTrmVertsThroughPolygon@idPolygonModelCollisionDetection@@CA_NPIAVidTraceWork@@PIBUcm_polygon_t@@ABVidPlane@@@Z
// EA  : 0x825F3A20
// RVA : 0x005F3A20
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::TranslateTrmVertsThroughPolygon(
        idTraceWork *tw,
        const cm_polygon_t *poly,
        const idPlane *polygonPlane)
{
  int v6; // r23
  unsigned int v7; // r27
  unsigned __int8 *vertIsUsed; // r22
  const idVec3 *i; // r29
  float *p_y; // r28
  double v11; // fp1
  trace_t *traceResult; // r11
  int material; // r9
  cm_material_t *materials; // r10
  cm_polygon_t *polygons; // r8
  char *v16; // r10
  int subModelNum; // r6
  double x; // fp11
  double z; // fp7
  traceType_t traceType; // r9
  double v21; // fp5
  double v22; // fp13
  double y; // fp12
  double v24; // fp10
  double v25; // fp3
  double v26; // fp2

  v6 = 1;
  v7 = 0;
  if ( tw->numVerts == 0 )
    return 0;
  vertIsUsed = tw->vertIsUsed;
  for ( i = (const idVec3 *)&tw->vertexPosition[0].z; ; i = (const idVec3 *)((char *)i + 16) )
  {
    if ( vertIsUsed[v7] == 0 )
      goto LABEL_11;
    if ( (tw->polygonSideCache.side & v6) != 0 )
      goto LABEL_11;
    p_y = &i[-1].y;
    v11 = idPolygonModelCollisionDetection::TranslatePointThroughPlane(
            plane: polygonPlane,
            start: (const idVec3 *)((char *)i - 8),
            end: i + 42);
    traceResult = tw->traceResult;
    if ( v11 >= traceResult->fraction )
      goto LABEL_11;
    if ( v11 < 0.0 )
      v11 = 0.0;
    traceResult->fraction = v11;
    material = poly->material;
    materials = tw->subModelPtrs.materials;
    traceResult->c.normal.x = polygonPlane->a;
    polygons = tw->subModelPtrs.polygons;
    traceResult->c.normal.y = polygonPlane->b;
    v16 = (char *)materials + __ROL4__(material, 4);
    traceResult->c.normal.z = polygonPlane->c;
    subModelNum = tw->subModelNum;
    tw->fraction = v11;
    x = i->x;
    traceResult->c.dist = -polygonPlane->d;
    z = i[-1].z;
    traceType = tw->traceType;
    v21 = *p_y;
    v22 = tw->dir.x;
    y = tw->dir.y;
    v24 = tw->dir.z;
    traceResult->c.separation = (float)((float)(*p_y * polygonPlane->a)
                                      + (float)((float)(i[-1].z * polygonPlane->b) + (float)((float)x * polygonPlane->c)))
                              + polygonPlane->d;
    traceResult->c.contentFlags = *(_DWORD *)v16;
    traceResult->c.surfaceFlags = *((_DWORD *)v16 + 1);
    traceResult->c.surfaceType = *((_DWORD *)v16 + 2);
    traceResult->c.surfaceColor[0] = v16[12];
    traceResult->c.surfaceColor[1] = v16[13];
    traceResult->c.surfaceColor[2] = v16[14];
    traceResult->c.type = CONTACT_TRMVERTEX;
    traceResult->c.modelFeature = (unsigned __int16)(poly - polygons) | (subModelNum << 16) & 0x1FFF0000 | 0x60000000;
    traceResult->c.trmFeature = v7;
    v25 = (float)((float)y * traceResult->fraction);
    v26 = (float)((float)v24 * traceResult->fraction);
    traceResult->c.point.x = (float)v21 + (float)((float)v22 * traceResult->fraction);
    traceResult->c.point.y = (float)z + (float)v25;
    traceResult->c.point.z = (float)x + (float)v26;
    traceResult->c.flags = 0;
    if ( traceType != TRACE_CONTACTS_UNI_DIR )
      break;
    idPolygonModelCollisionDetection::AddContact(tw);
LABEL_11:
    ++v7;
    v6 *= 2;
    if ( v7 >= tw->numVerts )
      return 0;
  }
  if ( v11 != 0.0 )
    goto LABEL_11;
  return 1;
}


// ========================================================================
// ?TranslatePolygonVertsThroughTrm@idPolygonModelCollisionDetection@@CA_NPIAVidTraceWork@@PIBUcm_polygon_t@@@Z
// EA  : 0x825F3C10
// RVA : 0x005F3C10
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::TranslatePolygonVertsThroughTrm(
        idTraceWork *tw,
        const cm_polygon_t *poly)
{
  int v4; // r14
  idModelCheckCounts *p_modelCheckCounts; // r15
  unsigned __int8 *edgeCheckCounts; // r11
  unsigned __int16 v7; // r7
  int v8; // r10
  int v9; // r4
  int v10; // r3
  cm_sideCache_t *v11; // r17
  unsigned int v12; // r20
  cm_edge_t *v13; // r19
  int v14; // r18
  unsigned __int8 *vertexCheckCounts; // r11
  int v16; // r26
  int v17; // r6
  int v18; // r5
  cm_vertex_t *v19; // r11
  double x; // fp12
  double y; // fp13
  double z; // fp0
  char v23; // r11
  unsigned int v24; // r27
  float *p_c; // r29
  double v26; // fp13
  cm_vertex_t *v27; // r31
  double v28; // fp12
  double v29; // fp6
  double v30; // fp1
  trace_t *traceResult; // r11
  double v32; // fp13
  cm_material_t *materials; // r10
  double v34; // fp12
  int v35; // r9
  double v36; // fp0
  char *v37; // r10
  traceType_t traceType; // r5
  int v39; // r4
  double v40; // fp10
  cm_sideCache_t *i; // [sp+50h] [-C0h]
  idVec3 v43; // [sp+58h] [-B8h] BYREF

  v4 = 0;
  if ( poly->numEdges == 0 )
    return 0;
  p_modelCheckCounts = &tw->modelCheckCounts;
  for ( i = tw->polygonVertexSideCache; ; ++i )
  {
    edgeCheckCounts = p_modelCheckCounts->edgeCheckCounts;
    v7 = tw->subModelPtrs.polygonEdges[poly->firstEdge + v4];
    v8 = (v7 & 0x3FFF) >> 3;
    v9 = edgeCheckCounts[v8];
    v10 = (unsigned __int8)(1 << (v7 & 7));
    edgeCheckCounts[v8] = v9 | v10;
    if ( (v9 & v10) == 0 && (v7 & 0x4000) == 0 )
      break;
LABEL_27:
    if ( ++v4 >= (unsigned int)poly->numEdges )
      return 0;
  }
  v11 = i;
  v12 = 0;
  v13 = &tw->subModelPtrs.edges[v7 & 0x3FFF];
  v14 = v7 >> 15;
  while ( 1 )
  {
    vertexCheckCounts = p_modelCheckCounts->vertexCheckCounts;
    v16 = v13->vertexNum[v14 ^ v12];
    v17 = vertexCheckCounts[v16 >> 3];
    v18 = (unsigned __int8)(1 << (v16 & 7));
    vertexCheckCounts[v16 >> 3] = v17 | v18;
    if ( (v17 & v18) == 0 )
    {
      v19 = &tw->subModelPtrs.vertices[v16];
      x = v19->p.x;
      if ( tw->traceBoundsMin.x > x
        || (y = v19->p.y, tw->traceBoundsMin.y > y)
        || (z = v19->p.z, tw->traceBoundsMin.z > z)
        || x > tw->traceBoundsMax.x
        || y > tw->traceBoundsMax.y
        || (v23 = 1, z > tw->traceBoundsMax.z) )
      {
        v23 = 0;
      }
      if ( v23 != 0 )
      {
        v24 = 0;
        if ( tw->numPolys != 0 )
          break;
      }
    }
LABEL_26:
    ++v12;
    ++v11;
    if ( v12 >= 2 )
      goto LABEL_27;
  }
  p_c = &tw->polys[0].plane.c;
  while ( 1 )
  {
    if ( tw->polyIsUsed[v24] == 0 )
      goto LABEL_25;
    if ( ((_DWORD)p_c[10] & v11->side) != *((_DWORD *)p_c + 11) )
      goto LABEL_25;
    v26 = tw->dir.y;
    v27 = &tw->subModelPtrs.vertices[v16];
    v28 = tw->dir.z;
    v43.x = v27->p.x - tw->dir.x;
    v29 = (float)(v27->p.z - (float)v28);
    v43.y = v27->p.y - (float)v26;
    v43.z = v29;
    v30 = idPolygonModelCollisionDetection::TranslatePointThroughPlane(
            plane: (const idPlane *)(p_c - 2),
            start: &v27->p,
            end: &v43);
    traceResult = tw->traceResult;
    if ( v30 >= traceResult->fraction )
      goto LABEL_25;
    if ( v30 < 0.0 )
      v30 = 0.0;
    tw->fraction = v30;
    v32 = *(p_c - 2);
    materials = tw->subModelPtrs.materials;
    v34 = *(p_c - 1);
    v35 = __ROL4__(poly->material, 4);
    v36 = *p_c;
    traceResult->fraction = v30;
    traceResult->c.normal.x = -v32;
    traceResult->c.normal.y = -v34;
    traceResult->c.normal.z = -v36;
    v37 = (char *)materials + v35;
    traceType = tw->traceType;
    v39 = (tw->subModelNum << 16) & 0x1FFF0000 | 0x20000000 | (unsigned __int16)v16;
    v40 = p_c[1];
    traceResult->c.dist = (float)(v27->p.x * (float)-v32)
                        + (float)((float)((float)-v36 * v27->p.z) + (float)((float)-v34 * v27->p.y));
    traceResult->c.separation = (float)((float)(v27->p.z * (float)v36)
                                      + (float)((float)(v27->p.y * (float)v34) + (float)(v27->p.x * (float)v32)))
                              + (float)v40;
    traceResult->c.contentFlags = *(_DWORD *)v37;
    traceResult->c.surfaceFlags = *((_DWORD *)v37 + 1);
    traceResult->c.surfaceType = *((_DWORD *)v37 + 2);
    traceResult->c.surfaceColor[0] = v37[12];
    traceResult->c.surfaceColor[1] = v37[13];
    traceResult->c.surfaceColor[2] = v37[14];
    traceResult->c.type = CONTACT_MODELVERTEX;
    traceResult->c.modelFeature = v39;
    traceResult->c.trmFeature = v24;
    traceResult->c.point.x = v27->p.x;
    traceResult->c.point.y = v27->p.y;
    traceResult->c.point.z = v27->p.z;
    traceResult->c.flags = 0;
    if ( traceType != TRACE_CONTACTS_UNI_DIR )
      break;
    idPolygonModelCollisionDetection::AddContact(tw);
LABEL_25:
    ++v24;
    p_c += 16;
    if ( v24 >= tw->numPolys )
      goto LABEL_26;
  }
  if ( v30 != 0.0 )
    goto LABEL_25;
  return 1;
}


// ========================================================================
// ?TranslateTrmThroughPolygon@idPolygonModelCollisionDetection@@CA_NPIAVidTraceWork@@I@Z
// EA  : 0x825F3FB0
// RVA : 0x005F3FB0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::TranslateTrmThroughPolygon(
        idTraceWork *tw,
        int polygonNum,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int8 *polygonCheckCounts; // r10
  int v13; // r7
  int v14; // r6
  unsigned __int8 v19; // cr58
  unsigned __int8 v20; // cr59
  double v21; // fp8
  double v22; // fp7
  double v23; // fp6
  double v24; // fp5
  double v25; // fp4
  double v26; // fp3
  double v27; // fp2
  int v28; // r3
  unsigned int numEdges; // r29
  unsigned int v31; // r8
  double fraction; // fp31
  idTraceWork *v33; // r3
  float v34; // [sp+8h] [-88h]
  float v35; // [sp+8h] [-88h]
  float v36; // [sp+Ch] [-84h]
  float v37; // [sp+Ch] [-84h]
  float v38; // [sp+10h] [-80h]
  float v39; // [sp+10h] [-80h]
  float v40; // [sp+14h] [-7Ch]
  float v41; // [sp+14h] [-7Ch]
  float v42; // [sp+18h] [-78h]
  float v43; // [sp+18h] [-78h]
  float v44; // [sp+1Ch] [-74h]
  float v45; // [sp+1Ch] [-74h]
  float v46; // [sp+20h] [-70h]
  float v47; // [sp+20h] [-70h]
  float v48; // [sp+24h] [-6Ch]
  float v49; // [sp+24h] [-6Ch]
  idPlane v50; // [sp+50h] [-40h] BYREF

  polygonCheckCounts = tw->modelCheckCounts.polygonCheckCounts;
  _R31 = tw;
  v13 = polygonCheckCounts[polygonNum >> 3];
  v14 = (unsigned __int8)(1 << (polygonNum & 7));
  polygonCheckCounts[polygonNum >> 3] = v13 | v14;
  if ( (v13 & v14) == 0 )
  {
    _R30 = &tw->subModelPtrs.polygons[polygonNum];
    if ( (*(int *)((_BYTE *)&tw->subModelPtrs.materials->contentFlags + __ROL4__(_R30->material, 4)) & tw->contents) != 0 )
    {
      __asm { lvx128    v63, r0, r30 }
      _R10 = 6176;
      _R9 = vmxi_half_bnds_intersect_perm2_6;
      _R8 = -16;
      __asm
      {
        lvx128    v62, r31, r10
        lvx128    v0, r0, r9
        lvx128    v7, r9, r8
        vperm128  v0, v95, v62, v0
        vperm128  v13, v95, v62, v7
        vcmpgtsh. v12, v13, v0
      }
      if ( ((32 * v19) & 0x20 | (16 * v20) & 0x20) != 0
        && !CM_BoundsShortPlaneCull(
              bs: &_R30->bounds,
              plane: &tw->heartPlane1,
              cmpdist: tw->maxDistFromHeartPlane1,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              a11: v34,
              a12: v36,
              a13: v38,
              a14: v40,
              a15: v42,
              a16: v44,
              a17: v46,
              a18: v48)
        && !CM_BoundsShortPlaneCull(
              bs: &_R30->bounds,
              plane: &_R31->heartPlane2,
              cmpdist: _R31->maxDistFromHeartPlane2,
              a4: v27,
              a5: v26,
              a6: v25,
              a7: v24,
              a8: v23,
              a9: v22,
              a10: v21,
              a11: v35,
              a12: v37,
              a13: v39,
              a14: v41,
              a15: v43,
              a16: v45,
              a17: v47,
              a18: v49) )
      {
        CM_GetPolygonPlane(subModel: &_R31->subModelPtrs, polygon: _R30, plane: &v50);
        if ( (float)((float)(_R31->dir.x * v50.a) + (float)((float)(_R31->dir.y * v50.b) + (float)(_R31->dir.z * v50.c))) <= 0.0 )
        {
          v28 = CM_BoundsPlaneSide(boundsMin: &_R31->traceBoundsMin, boundsMax: &_R31->traceBoundsMax, plane: &v50);
          if ( v28 == 3 )
          {
            idPolygonModelCollisionDetection::TranslationPlueckerCache(tw: _R31, polygon: _R30);
            numEdges = _R30->numEdges;
            idPolygonModelCollisionDetection::TranslationSideCache(
              pluecker: _R31->edgePluecker,
              used: _R31->edgeIsUsed,
              count: _R31->numEdges,
              plueckerCache: _R31->polygonVertexPlueckerCache,
              sideCache: _R31->polygonVertexSideCache,
              cacheSize: numEdges);
            idPolygonModelCollisionDetection::TranslationSideCache(
              pluecker: _R31->vertexPluecker,
              used: _R31->vertIsUsed,
              count: _R31->numVerts,
              plueckerCache: _R31->polygonEdgePlueckerCache,
              sideCache: _R31->polygonEdgeSideCache,
              cacheSize: v31);
            idPolygonModelCollisionDetection::TranslationPolygonSideCache(tw: _R31, polygon: _R30);
            _R31->polygonVertexSideCache[numEdges].side = _R31->polygonVertexSideCache[0].side;
            fraction = _R31->traceResult->fraction;
            if ( (unsigned __int8)idPolygonModelCollisionDetection::TranslateTrmVertsThroughPolygon(
                                    tw: v33,
                                    poly: _R30,
                                    polygonPlane: &v50) != 0
              || (unsigned __int8)idPolygonModelCollisionDetection::TranslateTrmEdgesThroughPolygon(
                                    tw: _R31,
                                    poly: _R30) != 0
              || (unsigned __int8)idPolygonModelCollisionDetection::TranslatePolygonVertsThroughTrm(
                                    tw: _R31,
                                    poly: _R30) != 0 )
            {
              return 1;
            }
            if ( _R31->traceResult->fraction < fraction && _R31->traceType != TRACE_CONTACTS_UNI_DIR )
              idPolygonModelCollisionDetection::TranslationUpdateBounds(tw: _R31);
          }
          else if ( v28 == 0 && _R31->subModelPtrs.isConvex != 0 )
          {
            _R31->quickExit = true;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// ?StartTranslation@idPolygonModelCollisionDetection@@SA_NPAVidTraceWork@@PAUtrace_t@@PAUcontactsResult_t@@ABVidVec3@@3PBVidTraceModel@@ABVidMat3@@H35@Z
// EA  : 0x825F4220
// RVA : 0x005F4220
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::StartTranslation(
        idTraceWork *tw,
        trace_t *result,
        contactsResult_t *contacts,
        const idVec3 *start,
        const idVec3 *end,
        const idTraceModel *trm,
        const idMat3 *trmAxis,
        int contentMask,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis,
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
        const idVec3 *a28,
        int a29,
        const idMat3 *a30)
{
  char v38; // r11
  idTraceWork *v40; // r3
  idTraceWork *v41; // r3
  idTraceWork *v42; // r3
  idTraceWork *v43; // r3
  idTraceWork *v44; // r3
  idTraceWork *v45; // r3

  result->fraction = 1.0;
  result->endpos = *start;
  result->endAxis = *trmAxis;
  XMemSet(dest: &result->c, c: 0, count: 0x4Cu);
  if ( start->x != end->x || start->y != end->y || (v38 = 1, start->z != end->z) )
    v38 = 0;
  tw->contactsResult = contacts;
  if ( v38 != 0 )
    return 0;
  tw->fraction = 1.0;
  tw->traceResult = result;
  tw->clipResult = nullptr;
  tw->contents = contentMask;
  tw->traceType = contacts == nullptr ? TRACE_TRANSLATION : TRACE_CONTACTS_UNI_DIR;
  tw->isConvex = trm->isConvex;
  tw->quickExit = false;
  tw->numVerts = trm->numVerts;
  tw->numEdges = trm->numEdges;
  tw->numPolys = trm->numPolys;
  idPolygonModelCollisionDetection::TranslationSetup(
    tw,
    start,
    end,
    offset: &trm->offset,
    trmAxis,
    modelOrigin: a28,
    modelAxis: a30);
  idPolygonModelCollisionDetection::TranslationUsedPrimitives(tw: v40, start, end, trm, trmAxis);
  idPolygonModelCollisionDetection::TranslationHeartPlanes(tw: v41);
  idPolygonModelCollisionDetection::TranslationVerts(tw: v42, trm);
  idPolygonModelCollisionDetection::TranslationEdges(tw: v43, trm);
  idPolygonModelCollisionDetection::TranslationPolys(tw: v44, trm);
  idPolygonModelCollisionDetection::TranslationBounds(tw: v45);
  return 1;
}


// ========================================================================
// ?TranslatePointThroughPolygon@idPolygonModelCollisionDetection@@CA_NPIAVidTraceWork@@I@Z
// EA  : 0x825F43D8
// RVA : 0x005F43D8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::TranslatePointThroughPolygon(
        idTraceWork *tw,
        int polygonNum,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int16 v10; // r26
  int v12; // r9
  int v13; // r3
  unsigned __int8 *polygonCheckCounts; // r10
  cm_polygon_t *polygons; // r10
  double v18; // fp8
  double v19; // fp7
  double v20; // fp6
  double v21; // fp5
  double v22; // fp4
  double v23; // fp3
  double v24; // fp2
  unsigned __int8 v29; // cr58
  unsigned __int8 v30; // cr59
  double b; // fp30
  double c; // fp29
  double a; // fp28
  double fraction; // fp27
  double v35; // fp31
  float *p_fraction; // r11
  double d; // fp0
  double v38; // fp13
  unsigned __int8 v39; // r27
  float *v40; // r11
  float *v41; // r7
  double v42; // fp13
  double y; // fp12
  double v44; // fp9
  double z; // fp10
  float v46; // [sp+8h] [-C8h]
  float v47; // [sp+8h] [-C8h]
  float v48; // [sp+Ch] [-C4h]
  float v49; // [sp+Ch] [-C4h]
  float v50; // [sp+10h] [-C0h]
  float v51; // [sp+10h] [-C0h]
  float v52; // [sp+14h] [-BCh]
  float v53; // [sp+14h] [-BCh]
  float v54; // [sp+18h] [-B8h]
  float v55; // [sp+18h] [-B8h]
  float v56; // [sp+1Ch] [-B4h]
  float v57; // [sp+1Ch] [-B4h]
  float v58; // [sp+20h] [-B0h]
  float v59; // [sp+20h] [-B0h]
  float v60; // [sp+24h] [-ACh]
  float v61; // [sp+24h] [-ACh]
  idPlane v62[4]; // [sp+50h] [-80h] BYREF

  v10 = polygonNum;
  _R31 = tw;
  v12 = tw->modelCheckCounts.polygonCheckCounts[polygonNum >> 3];
  polygonCheckCounts = tw->modelCheckCounts.polygonCheckCounts;
  v13 = (unsigned __int8)(1 << (polygonNum & 7));
  polygonCheckCounts[polygonNum >> 3] = v12 | v13;
  if ( (v12 & v13) != 0 )
    return 0;
  polygons = _R31->subModelPtrs.polygons;
  _R30 = &polygons[polygonNum];
  if ( (*(int *)((_BYTE *)&_R31->subModelPtrs.materials->contentFlags + __ROL4__(_R30->material, 4)) & _R31->contents) == 0 )
    return 0;
  if ( CM_BoundsShortPlaneCull(
         bs: &polygons[polygonNum].bounds,
         plane: &_R31->heartPlane1,
         cmpdist: _R31->maxDistFromHeartPlane1,
         a4,
         a5,
         a6,
         a7,
         a8,
         a9,
         a10,
         a11: v46,
         a12: v48,
         a13: v50,
         a14: v52,
         a15: v54,
         a16: v56,
         a17: v58,
         a18: v60) )
  {
    return 0;
  }
  if ( CM_BoundsShortPlaneCull(
         bs: &_R30->bounds,
         plane: &_R31->heartPlane2,
         cmpdist: _R31->maxDistFromHeartPlane2,
         a4: v24,
         a5: v23,
         a6: v22,
         a7: v21,
         a8: v20,
         a9: v19,
         a10: v18,
         a11: v47,
         a12: v49,
         a13: v51,
         a14: v53,
         a15: v55,
         a16: v57,
         a17: v59,
         a18: v61) )
  {
    return 0;
  }
  __asm { lvx128    v63, r0, r30 }
  _R10 = 6176;
  _R9 = vmxi_half_bnds_intersect_perm2_6;
  _R8 = -16;
  __asm
  {
    lvx128    v62, r31, r10
    lvx128    v0, r0, r9
    lvx128    v7, r9, r8
    vperm128  v0, v95, v62, v0
    vperm128  v13, v95, v62, v7
    vcmpgtsh. v12, v13, v0
  }
  if ( ((32 * v29) & 0x20 | (16 * v30) & 0x20) == 0 )
    return 0;
  CM_GetPolygonPlane(subModel: &_R31->subModelPtrs, polygon: _R30, plane: v62);
  b = v62[0].b;
  c = v62[0].c;
  a = v62[0].a;
  if ( (float)((float)(_R31->dir.x * v62[0].a)
             + (float)((float)(_R31->dir.z * v62[0].c) + (float)(_R31->dir.y * v62[0].b))) > 0.0 )
    return 0;
  fraction = _R31->traceResult->fraction;
  v35 = idPolygonModelCollisionDetection::TranslatePointThroughPlane(
          plane: v62,
          start: (const idVec3 *)_R31->vertexPosition,
          end: (const idVec3 *)_R31->vertexEndPosition);
  if ( v35 >= fraction )
    return 0;
  idPolygonModelCollisionDetection::TranslationEdgePlueckerCache(tw: _R31, polygon: _R30);
  idPolygonModelCollisionDetection::TranslationSideCache(
    pluecker: _R31->vertexPluecker,
    used: _R31->vertIsUsed,
    count: 1u,
    plueckerCache: _R31->polygonEdgePlueckerCache,
    sideCache: _R31->polygonEdgeSideCache,
    cacheSize: _R30->numEdges);
  idPolygonModelCollisionDetection::TranslationPolygonSideCache(tw: _R31, polygon: _R30);
  if ( (_R31->polygonSideCache.side & 1) != 0 )
    return 0;
  if ( v35 < 0.0 )
    v35 = 0.0;
  p_fraction = &_R31->traceResult->fraction;
  _R31->fraction = v35;
  d = v62[0].d;
  v38 = -v62[0].d;
  v39 = 0;
  *p_fraction = v35;
  v40 = &_R31->traceResult->fraction;
  v40[17] = a;
  v40[18] = b;
  v40[19] = c;
  _R31->traceResult->c.dist = v38;
  _R31->traceResult->c.separation = (float)((float)(_R31->vertexPosition[0].y * (float)b)
                                          + (float)((float)(_R31->vertexPosition[0].x * (float)a)
                                                  + (float)((float)c * _R31->vertexPosition[0].z)))
                                  + (float)d;
  _R31->traceResult->c.contentFlags = *(int *)((char *)&_R31->subModelPtrs.materials->contentFlags
                                             + __ROL4__(_R30->material, 4));
  _R31->traceResult->c.surfaceFlags = *(int *)((char *)&_R31->subModelPtrs.materials->surfaceFlags
                                             + __ROL4__(_R30->material, 4));
  _R31->traceResult->c.surfaceType = *(int *)((char *)&_R31->subModelPtrs.materials->surfaceType
                                            + __ROL4__(_R30->material, 4));
  _R31->traceResult->c.surfaceColor[0] = _R31->subModelPtrs.materials->surfaceColor[__ROL4__(_R30->material, 4)];
  _R31->traceResult->c.surfaceColor[1] = _R31->subModelPtrs.materials->surfaceColor[__ROL4__(_R30->material, 4) + 1];
  _R31->traceResult->c.surfaceColor[2] = _R31->subModelPtrs.materials->surfaceColor[__ROL4__(_R30->material, 4) + 2];
  _R31->traceResult->c.type = CONTACT_TRMVERTEX;
  _R31->traceResult->c.modelFeature = (_R31->subModelNum << 16) & 0x1FFF0000 | 0x60000000 | v10;
  _R31->traceResult->c.trmFeature = 0;
  v41 = &_R31->traceResult->fraction;
  v42 = (float)(_R31->dir.y * *v41);
  y = _R31->vertexPosition[0].y;
  v44 = (float)(_R31->dir.z * *v41);
  z = _R31->vertexPosition[0].z;
  v41[14] = _R31->vertexPosition[0].x + (float)(_R31->dir.x * *v41);
  v41[15] = (float)y + (float)v42;
  v41[16] = (float)v44 + (float)z;
  _R31->traceResult->c.flags = 0;
  if ( _R31->traceResult->fraction < fraction )
    idPolygonModelCollisionDetection::TranslationUpdateBounds(tw: _R31);
  if ( _R31->traceResult->fraction == 0.0 )
    return 1;
  return v39;
}


// ========================================================================
// ?StartTranslationPoint@idPolygonModelCollisionDetection@@SA_NPAVidTraceWork@@PAUtrace_t@@ABVidVec3@@2H2ABVidMat3@@@Z
// EA  : 0x825F4768
// RVA : 0x005F4768
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::StartTranslationPoint(
        idTraceWork *tw,
        trace_t *result,
        const idVec3 *start,
        const idVec3 *end,
        int contentMask,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis)
{
  char v14; // r10
  char v15; // r11
  idVec4 *p_start; // r30
  idVec4 *p_end; // r11
  double z; // fp10
  double v20; // fp9
  double v21; // fp6
  double v22; // fp7
  double y; // fp3
  double v24; // fp2
  double v25; // fp11
  double v26; // fp13
  double x; // fp0
  double v28; // fp13
  double v29; // fp6
  double v30; // fp11
  double v31; // fp9
  double v32; // fp8
  double v33; // fp8
  double v34; // fp11
  double v35; // fp10
  double v36; // fp3
  double v37; // fp0
  double v38; // fp9
  double v39; // fp11
  double v40; // fp8
  double v41; // fp5
  double v42; // fp3
  double v43; // fp8
  double v44; // fp7
  double v45; // fp6
  double w; // fp5
  double v47; // fp10
  double v48; // fp8
  double v49; // fp0
  idTraceWork *v50; // r3

  result->fraction = 1.0;
  result->endpos = *start;
  result->endAxis.mat[2].z = 1.0;
  result->endAxis.mat[1].y = 1.0;
  result->endAxis.mat[0].x = 1.0;
  result->endAxis.mat[1].z = 0.0;
  result->endAxis.mat[0].z = 0.0;
  result->endAxis.mat[0].y = 0.0;
  result->endAxis.mat[2].y = 0.0;
  result->endAxis.mat[2].x = 0.0;
  result->endAxis.mat[1].x = 0.0;
  XMemSet(dest: &result->c, c: 0, count: 0x4Cu);
  v14 = 0;
  if ( start->x != end->x || start->y != end->y || (v15 = 1, start->z != end->z) )
    v15 = 0;
  if ( v15 != 0 )
    return 0;
  tw->traceResult = result;
  tw->fraction = 1.0;
  tw->contactsResult = nullptr;
  tw->clipResult = nullptr;
  p_start = &tw->start;
  tw->contents = contentMask;
  p_end = &tw->end;
  tw->traceType = TRACE_TRANSLATION_POINT;
  tw->isConvex = true;
  tw->quickExit = false;
  tw->numVerts = 1;
  tw->numEdges = 0;
  tw->numPolys = 0;
  z = modelOrigin->z;
  v20 = start->z;
  v21 = (float)(start->x - modelOrigin->x);
  v22 = (float)(start->y - modelOrigin->y);
  tw->start.w = 0.0;
  tw->start.x = v21;
  tw->start.y = v22;
  tw->start.z = (float)v20 - (float)z;
  y = end->y;
  v24 = modelOrigin->y;
  v25 = (float)(end->x - modelOrigin->x);
  v26 = (float)(end->z - modelOrigin->z);
  tw->end.w = 0.0;
  tw->end.x = v25;
  tw->end.y = (float)y - (float)v24;
  tw->end.z = v26;
  x = modelAxis->mat[0].x;
  if ( x != 1.0 || modelAxis->mat[1].y != 1.0 || modelAxis->mat[2].z != 1.0 )
    v14 = 1;
  if ( v14 != 0 )
  {
    v28 = tw->start.z;
    v29 = p_start->x;
    v30 = modelAxis->mat[1].z;
    v31 = (float)((float)(tw->start.x * modelAxis->mat[1].x) + (float)(tw->start.y * modelAxis->mat[1].y));
    v32 = (float)((float)(modelAxis->mat[0].z * tw->start.z) + (float)(modelAxis->mat[0].y * tw->start.y));
    tw->start.z = (float)(tw->start.y * modelAxis->mat[2].y)
                + (float)((float)(modelAxis->mat[2].x * tw->start.x) + (float)(modelAxis->mat[2].z * tw->start.z));
    tw->start.y = (float)((float)v28 * (float)v30) + (float)v31;
    p_start->x = (float)((float)x * (float)v29) + (float)v32;
    v33 = p_end->x;
    v34 = modelAxis->mat[0].x;
    v35 = modelAxis->mat[1].z;
    v36 = tw->end.z;
    v37 = (float)((float)(tw->end.x * modelAxis->mat[1].x) + (float)(tw->end.y * modelAxis->mat[1].y));
    v38 = (float)((float)(modelAxis->mat[0].z * tw->end.z) + (float)(modelAxis->mat[0].y * tw->end.y));
    tw->end.z = (float)(tw->end.y * modelAxis->mat[2].y)
              + (float)((float)(modelAxis->mat[2].x * tw->end.x) + (float)(modelAxis->mat[2].z * tw->end.z));
    tw->end.y = (float)((float)v36 * (float)v35) + (float)v37;
    p_end->x = (float)((float)v33 * (float)v34) + (float)v38;
  }
  v39 = (float)(p_end->x - p_start->x);
  v40 = (float)(tw->end.y - tw->start.y);
  v41 = (float)(tw->end.z - tw->start.z);
  v42 = (float)(tw->end.w - tw->start.w);
  tw->dir.x = p_end->x - p_start->x;
  tw->dir.y = v40;
  tw->dir.z = v41;
  tw->dir.w = v42;
  tw->negDir.x = -v39;
  tw->negDir.y = -v40;
  tw->negDir.z = -v41;
  tw->negDir.w = -v42;
  idPolygonModelCollisionDetection::TranslationHeartPlanes(tw);
  tw->maxDistFromHeartPlane1 = 1.0;
  tw->maxDistFromHeartPlane2 = 1.0;
  tw->vertIsUsed[0] = 1;
  v43 = p_start->x;
  tw->vertexPosition[0].x = p_start->x;
  v44 = tw->start.y;
  tw->vertexPosition[0].y = tw->start.y;
  v45 = tw->start.z;
  tw->vertexPosition[0].z = tw->start.z;
  w = tw->start.w;
  tw->vertexPosition[0].w = tw->start.w;
  v47 = (float)((float)v43 + tw->dir.x);
  v48 = (float)(tw->dir.z + (float)v45);
  v49 = (float)(tw->dir.w + (float)w);
  tw->vertexEndPosition[0].y = tw->dir.y + (float)v44;
  tw->vertexEndPosition[0].x = v47;
  tw->vertexEndPosition[0].z = v48;
  tw->vertexEndPosition[0].w = v49;
  tw->vertexPluecker[0].p[0] = (float)(tw->dir.y * tw->vertexPosition[0].x)
                             - (float)(tw->vertexPosition[0].y * tw->dir.x);
  tw->vertexPluecker[0].p[1] = (float)(tw->dir.z * tw->vertexPosition[0].x)
                             - (float)(tw->dir.x * tw->vertexPosition[0].z);
  tw->vertexPluecker[0].p[2] = -tw->dir.x;
  tw->vertexPluecker[0].p[3] = (float)(tw->dir.z * tw->vertexPosition[0].y)
                             - (float)(tw->dir.y * tw->vertexPosition[0].z);
  tw->vertexPluecker[0].p[4] = -tw->dir.z;
  tw->vertexPluecker[0].p[5] = tw->dir.y;
  tw->trmBoundsMin.w = 0.0;
  tw->trmBoundsMin.z = 0.0;
  tw->trmBoundsMin.y = 0.0;
  tw->trmBoundsMin.x = 0.0;
  tw->trmBoundsMax.w = 0.0;
  tw->trmBoundsMax.z = 0.0;
  tw->trmBoundsMax.y = 0.0;
  tw->trmBoundsMax.x = 0.0;
  idPolygonModelCollisionDetection::TranslationBounds(tw: v50);
  return 1;
}


// ========================================================================
// ?FinishTranslation@idPolygonModelCollisionDetection@@SAXPAVidTraceWork@@ABVidVec3@@11ABVidMat3@@HHHHH@Z
// EA  : 0x825F4B80
// RVA : 0x005F4B80
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_translate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::FinishTranslation(
        idTraceWork *tw,
        const idVec3 *start,
        const idVec3 *end,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis,
        int modelEntityNum,
        int modelPhysicsId,
        int modelBodyId,
        int selfId,
        int modelContentsOverride,
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
        int a29,
        int a30)
{
  trace_t *traceResult; // r11
  double y; // fp12
  double z; // fp11
  double v33; // fp2
  double v34; // fp1
  char v35; // r5
  char v36; // r11
  trace_t *v37; // r11
  double v38; // fp8
  double v39; // fp1
  double v40; // fp0
  double v41; // fp11
  double v42; // fp10
  double x; // fp13
  double v44; // fp0
  double v45; // fp12
  double v46; // fp10
  double v47; // fp3
  double v48; // fp2
  trace_t *v49; // r11

  traceResult = tw->traceResult;
  y = start->y;
  z = start->z;
  v33 = (float)((float)(end->y - start->y) * traceResult->fraction);
  v34 = (float)((float)(end->z - start->z) * traceResult->fraction);
  traceResult->endpos.x = start->x + (float)((float)(end->x - start->x) * traceResult->fraction);
  traceResult->endpos.y = (float)y + (float)v33;
  traceResult->endpos.z = (float)z + (float)v34;
  if ( traceResult->fraction < 1.0 )
  {
    if ( traceResult->fraction > 0.0 )
    {
      if ( traceResult->endpos.x != start->x
        || traceResult->endpos.y != start->y
        || (v35 = 1, traceResult->endpos.z != start->z) )
      {
        v35 = 0;
      }
      if ( v35 != 0 )
        traceResult->fraction = 0.0;
    }
    if ( modelAxis->mat[0].x != 1.0 || modelAxis->mat[1].y != 1.0 || (v36 = 0, modelAxis->mat[2].z != 1.0) )
      v36 = 1;
    if ( v36 != 0 )
    {
      v37 = tw->traceResult;
      v38 = v37->c.normal.z;
      v39 = modelAxis->mat[2].y;
      v40 = modelAxis->mat[2].z;
      v41 = (float)((float)(v37->c.normal.x * modelAxis->mat[0].z) + (float)(v37->c.normal.y * modelAxis->mat[1].z));
      v42 = (float)((float)(v37->c.normal.y * modelAxis->mat[1].y) + (float)(v37->c.normal.x * modelAxis->mat[0].y));
      v37->c.normal.x = (float)(v37->c.normal.x * modelAxis->mat[0].x)
                      + (float)((float)(v37->c.normal.y * modelAxis->mat[1].x)
                              + (float)(modelAxis->mat[2].x * v37->c.normal.z));
      v37->c.normal.z = (float)((float)v40 * (float)v38) + (float)v41;
      v37->c.normal.y = (float)((float)v38 * (float)v39) + (float)v42;
      x = v37->c.point.x;
      v44 = v37->c.point.y;
      v45 = modelAxis->mat[1].x;
      v46 = modelAxis->mat[0].z;
      v47 = (float)((float)(modelAxis->mat[0].x * v37->c.point.x) + (float)(v37->c.point.z * modelAxis->mat[2].x));
      v48 = (float)((float)(v37->c.point.y * modelAxis->mat[1].z) + (float)(v37->c.point.z * modelAxis->mat[2].z));
      v37->c.point.y = (float)(v37->c.point.y * modelAxis->mat[1].y)
                     + (float)((float)(v37->c.point.x * modelAxis->mat[0].y)
                             + (float)(v37->c.point.z * modelAxis->mat[2].y));
      v37->c.point.x = (float)((float)v44 * (float)v45) + (float)v47;
      v37->c.point.z = (float)((float)x * (float)v46) + (float)v48;
    }
    if ( ((LODWORD(modelOrigin->x) | LODWORD(modelOrigin->y) | LODWORD(modelOrigin->z)) & 0x7FFFFFFF) != 0 )
    {
      v49 = tw->traceResult;
      v49->c.point.x = modelOrigin->x + v49->c.point.x;
      v49->c.point.y = modelOrigin->y + v49->c.point.y;
      v49->c.point.z = modelOrigin->z + v49->c.point.z;
      v49->c.dist = (float)((float)(modelOrigin->x * v49->c.normal.x)
                          + (float)((float)(v49->c.normal.y * modelOrigin->y) + (float)(v49->c.normal.z * modelOrigin->z)))
                  + v49->c.dist;
    }
    tw->traceResult->c.entityNum = modelEntityNum;
    tw->traceResult->c.physicsId = modelPhysicsId;
    tw->traceResult->c.bodyId = modelBodyId;
    tw->traceResult->c.selfId = a28;
    if ( a30 != 0 )
      tw->traceResult->c.contentFlags = a30;
  }
}

