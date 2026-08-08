
// ========================================================================
// ?SetupCollisionSpherePtrs@idSphereModelCollisionDetection@@SAHPBUcm_sphereModel_t@@AAUcm_sphereModelPtrs_t@@@Z
// EA  : 0x825F4E10
// RVA : 0x005F4E10
// PDB : w:\tech5\engine\cm\jobs\spheremodel\spheremodel.cpp
// ========================================================================

int __fastcall idSphereModelCollisionDetection::SetupCollisionSpherePtrs(
        const cm_sphereModel_t *csData,
        cm_sphereModelPtrs_t *csPtrs)
{
  csPtrs->joint = (unsigned __int8 *)csData + csData->jointOffset;
  csPtrs->offsetX = (float *)((char *)&csData->totalSize + csData->offsetXOffset);
  csPtrs->offsetY = (float *)((char *)&csData->totalSize + csData->offsetYOffset);
  csPtrs->offsetZ = (float *)((char *)&csData->totalSize + csData->offsetZOffset);
  csPtrs->radius = (float *)((char *)&csData->totalSize + csData->radiusOffset);
  csPtrs->surfType = (unsigned __int8 *)csData + csData->surfTypeOffset;
  return csData->numSpheres;
}


// ========================================================================
// ?TraceThroughModel@idSphereModelCollisionDetection@@SAXAAUtrace_t@@PBUcm_sphereModel_t@@ABVidVec3@@2MABVidMat3@@PBVidJointMat@@23HHHHH@Z
// EA  : 0x825F4E60
// RVA : 0x005F4E60
// PDB : w:\tech5\engine\cm\jobs\spheremodel\spheremodel.cpp
// ========================================================================

void __fastcall idSphereModelCollisionDetection::TraceThroughModel(
        trace_t *trace,
        const cm_sphereModel_t *csData,
        const idVec3 *start,
        const idVec3 *end,
        double radius,
        const idMat3 *trmAxis,
        const idJointMat *modelJoints,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        int modelEntityNum,
        int modelPhysicsId,
        int modelBodyId,
        int selfId,
        int modelContentsOverride,
        int a22,
        int a23,
        int a24,
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
        float *a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        const idMat3 *modelAxis_0,
        int a45,
        int modelEntityNuma)
{
  idVec3 *p_endpos; // r22
  int numSpheres; // r25
  int offsetXOffset; // r10
  int jointOffset; // r11
  int offsetYOffset; // r7
  int offsetZOffset; // r4
  int radiusOffset; // r3
  int surfTypeOffset; // r26
  char *v70; // r28
  char *v71; // r5
  char *v73; // r7
  char *v74; // r4
  char *v75; // r3
  char *v76; // r26
  char v77; // cr56
  int v81; // r10
  unsigned int v83; // r11
  unsigned int v85; // r26
  unsigned int v91; // ctr
  unsigned __int8 v100; // cr56
  unsigned __int8 v101; // cr57
  int v102; // r9
  int v104; // r24
  double v105; // fp5
  float *v107; // r11
  double v108; // fp29
  double v109; // fp1
  double v110; // fp11
  double v111; // fp4
  double v112; // fp5
  double v113; // fp10
  int contents; // r7
  double v115; // fp13
  bool v116; // cr58
  double z; // fp6
  double y; // fp8
  double v121; // fp12
  double v122; // fp11
  double v123; // fp1
  double v124; // fp0
  int v125; // r11
  int v126; // r8
  int v127; // r7
  int v128; // r6
  const idMat3 *v129; // r5
  int v130; // r4
  int v131; // [sp+50h] [-140h] BYREF
  float v132; // [sp+54h] [-13Ch] BYREF
  char *v133; // [sp+64h] [-12Ch]
  char *v134; // [sp+68h] [-128h]
  char *v135; // [sp+6Ch] [-124h]
  char *v136; // [sp+70h] [-120h]
  char *v137; // [sp+74h] [-11Ch]

  a28 = radius;
  p_endpos = &trace->endpos;
  _R21 = start;
  trace->fraction = 1.0;
  trace->endpos = *end;
  _R27 = end;
  trace->endAxis.mat[0].x = modelJoints->mat[0];
  trace->endAxis.mat[0].y = modelJoints->mat[1];
  _R20 = modelAxis;
  trace->endAxis.mat[0].z = modelJoints->mat[2];
  trace->endAxis.mat[1] = *(idVec3 *)&modelJoints->mat[3];
  trace->endAxis.mat[2] = *(idVec3 *)&modelJoints->mat[6];
  memset(Dst: &trace->c, Val: 0, Size: sizeof(trace->c));
  _R9 = 16;
  _R8 = a36;
  numSpheres = csData->numSpheres;
  _R4 = 12;
  __asm { lvlx128   v63, r0, r20 }
  _R3 = 40;
  __asm { lvlx128   v61, r0, r21 }
  _R28 = 24;
  offsetXOffset = csData->offsetXOffset;
  _R5 = 28;
  __asm { lvrx128   v60, r9, r20 }
  _R6 = vmxi_word_four;
  jointOffset = csData->jointOffset;
  _R24 = -48;
  __asm
  {
    lvlx128   v55, r4, r8
    lvrx128   v54, r3, r8
    vor128    v59, v95, v60
    lvlx128   v53, r28, r8
  }
  offsetYOffset = csData->offsetYOffset;
  __asm { lvrx128   v58, r9, r8 }
  offsetZOffset = csData->offsetZOffset;
  __asm { lvlx128   v57, r0, r8 }
  radiusOffset = csData->radiusOffset;
  __asm { lvrx128   v56, r5, r8 }
  surfTypeOffset = csData->surfTypeOffset;
  __asm
  {
    lvrx128   v52, r9, r21
    vspltisw128 v63, 0
    lvx128    v62, r6, r24
  }
  v132 = *(float *)&numSpheres;
  __asm
  {
    lvlx128   v51, r0, r27
    vor128    v50, v89, v58
    vor128    v49, v87, v56
  }
  v70 = (char *)csData + jointOffset;
  __asm
  {
    vor128    v48, v85, v54
    lvrx128   v45, r9, r27
    vor128    v47, v93, v52
    vor128    v43, v83, v45
  }
  __asm { vand128   v46, v91, v62 }
  v71 = (char *)csData + offsetXOffset;
  __asm { vand128   v42, v82, v62 }
  _R11 = &vmx_float_smallest_non_denorm;
  __asm { vand128   v44, v79, v62 }
  v73 = (char *)csData + offsetYOffset;
  __asm { vand128   v38, v75, v62 }
  v74 = (char *)csData + offsetZOffset;
  __asm { vand128   v41, v81, v62 }
  v75 = (char *)csData + radiusOffset;
  __asm { vand128   v39, v80, v62 }
  v76 = (char *)csData + surfTypeOffset;
  __asm
  {
    vsubfp128 v40, v76, v46
    lvx128    v60, r0, r11
    vsubfp128 v37, v70, v46
  }
  v133 = (char *)csData + offsetXOffset;
  v134 = v73;
  v135 = v74;
  v136 = v75;
  v137 = v76;
  __asm
  {
    vmulfp128 v36, v74, v40
    vmulfp128 v35, v73, v40
    vmulfp128 v34, v71, v40
    vmulfp128 v33, v74, v37
    vmulfp128 v32, v73, v37
    vmulfp128 v62, v71, v37
    vmrghw128 v61, v67, v63
    vmrghw128 v59, v68, v34
    vmrglw128 v57, v68, v34
    vmrghw128 v56, v64, v63
    vmrghw128 v55, v65, v62
    vmrglw128 v54, v91, v61
    vmrghw128 v53, v91, v61
    vmrglw128 v58, v67, v63
    vmrglw128 v51, v87, v56
    vmrghw128 v50, v87, v56
    vaddfp128 v49, v85, v54
    vmrglw128 v52, v64, v63
    vmrglw128 v48, v65, v62
    vmrghw128 v47, v89, v58
    vaddfp128 v46, v82, v51
    vmrghw128 v45, v80, v52
    vaddfp128 v44, v81, v47
    vaddfp128 v43, v78, v45
    vspltw128 v56, v44, 0
    vspltw128 v55, v44, 1
    vspltw128 v54, v44, 2
    vsubfp128 v42, v75, v44
    vmulfp128 v41, v74, v42
    vspltw128 v29, v42, 0
    vspltw128 v28, v42, 1
    vspltw128 v53, v42, 2
    vspltw128 v40, v41, 1
    vspltw128 v39, v41, 0
    vspltw128 v38, v41, 2
    vaddfp128 v37, v71, v40
    vaddfp128 v61, v69, v38
    vcmpgtfp128. v36, v93, v60
  }
  if ( v77 != 0 )
  {
    __asm { vrefp128  v35, v61 }
    _R24 = -16;
    _R11 = -32;
    _R23 = -112;
    v81 = 0;
    __asm
    {
      lvx128    v27, r6, r24
      lvx128    v6, r6, r11
      vmr       v9, v27
      lvx128    v7, r6, r23
      vmulfp128 v34, v93, v35
      vaddfp128 v33, v67, v35
      vmulfp128 v32, v66, v35
      vsubfp128 v62, v65, v32
    }
    if ( numSpheres > 0 )
    {
      __asm { lvx128    v30, r0, r6 }
      v83 = (unsigned int)(numSpheres - 1) >> 2;
      _R25 = &a28;
      _R16 = v71 - v73;
      v85 = v83 + 1;
      _R15 = v74 - v73;
      _R14 = v75 - v73;
      __asm { lvlx128   v59, r0, r25 }
      _R11 = v73;
      _R7 = -96;
      __asm { vspltw128 v57, v59, 0 }
      _R5 = -80;
      v91 = v85;
      _R4 = -64;
      __asm { lvx128    v31, r6, r7 }
      __asm { lvx128    v59, r6, r5 }
      _R3 = 32;
      __asm { lvx128    v58, r6, r4 }
      do
      {
        __asm { lvx128    v52, r14, r11 }
        __asm { vaddfp128 v51, v84, v57 }
        __asm { lvx128    v0, r16, r11 }
        __asm { lvx128    v13, r0, r11 }
        __asm { lvx128    v12, r15, r11 }
        _R7 = (char *)modelOrigin + 16 * (unsigned __int8)v70[v81] + 16 * __ROL4__((unsigned __int8)v70[v81], 1);
        _R6 = (char *)modelOrigin + 16 * (unsigned __int8)v70[v81 + 1] + 16 * __ROL4__((unsigned __int8)v70[v81 + 1], 1);
        _R5 = (char *)modelOrigin + 16 * (unsigned __int8)v70[v81 + 2] + 16 * __ROL4__((unsigned __int8)v70[v81 + 2], 1);
        _R4 = (char *)modelOrigin + 16 * (unsigned __int8)v70[v81 + 3] + 16 * __ROL4__((unsigned __int8)v70[v81 + 3], 1);
        v81 += 4;
        __asm { lvx128    v50, r0, r7 }
        _R11 += 16;
        __asm
        {
          lvx128    v49, r0, r6
          lvx128    v48, r0, r5
          lvx128    v47, r0, r4
          lvx128    v46, r7, r9
          vmrghw128 v45, v82, v48
          lvx128    v44, r6, r9
          vmrglw128 v43, v82, v48
          lvx128    v42, r5, r9
          vmrghw128 v41, v81, v47
          lvx128    v40, r4, r9
          vmrglw128 v39, v81, v47
          lvx128    v38, r7, r3
          vmrghw128 v37, v78, v42
          lvx128    v36, r6, r3
          vmrglw128 v35, v78, v42
          lvx128    v34, r5, r3
          vmrghw128 v33, v76, v40
          lvx128    v32, r4, r3
          vmrglw128 v52, v76, v40
          vmrghw128 v50, v70, v34
          vmrglw128 v49, v70, v34
          vmrghw128 v48, v68, v32
          vmrglw128 v47, v68, v32
          vmrglw128 v10, v75, v39
          vmrghw128 v11, v77, v41
          vmrglw128 v5, v67, v52
          vmrghw128 v8, v69, v33
          vmrglw128 v3, v81, v47
          vmrghw128 v4, v82, v48
          vmaddfp   v11, v11, v10, v0
          vmrglw128 v2, v77, v41
          vmaddfp   v10, v8, v5, v0
          vmrglw128 v8, v69, v33
          vmrglw128 v5, v82, v48
          vmaddfp   v0, v4, v3, v0
          vmrghw128 v4, v75, v39
          vmrghw128 v3, v67, v52
          vmrghw128 v1, v81, v47
          vmaddfp   v11, v2, v11, v13
          vmaddfp   v10, v8, v10, v13
          vmr       v8, v6
          vmaddfp   v0, v5, v0, v13
          vmaddfp   v13, v4, v11, v12
          vmaddfp   v11, v3, v10, v12
          vor128    v10, v93, v61
          vmaddfp   v12, v1, v0, v12
          vsubfp128 v0, v88, v13
          vsubfp128 v13, v87, v11
          vor128    v11, v83, v51
          vsubfp128 v46, v86, v12
          vor128    v12, v83, v51
          vmulfp128 v5, v85, v46
          vmulfp128 v4, v78, v46
          vmaddfp   v5, v28, v5, v13
          vaddsws   v6, v6, v30
          vmaddfp   v13, v13, v4, v13
          vmaddfp   v5, v29, v5, v0
          vmaddfp   v0, v0, v13, v0
          vmulfp128 v13, v5, v5
          vxor128   v45, v5, v58
          vnmsubfp  v0, v12, v0, v11
          vnmsubfp  v13, v0, v13, v10
          vmaxfp128 v44, v13, v60
          vcmpgtfp128 v43, v13, v63
          vrsqrtefp128 v0, v44
          vmulfp128 v13, v76, v0
          vmulfp128 v42, v0, v59
          vmaddfp   v0, v13, v31, v0
          vmulfp128 v41, v74, v0
          vmulfp128 v40, v73, v44
          vaddfp128 v39, v77, v40
          vsubfp128 v38, v77, v40
          vmulfp128 v37, v71, v62
          vmulfp128 v36, v70, v62
          vminfp128 v35, v69, v36
          vmulfp128 v34, v69, v36
          vcmpgefp128 v33, v67, v63
          vor128    v0, v67, v35
          vcmpgefp128 v32, v67, v7
          vcmpgtfp128 v52, v95, v34
          vand128   v51, v75, v33
          vandc128  v50, v83, v32
          vor128    v13, v82, v52
          vsel      v12, v9, v8, v13
          vsel      v13, v7, v0, v13
          vmr       v9, v12
          vmr       v7, v13
        }
        --v91;
      }
      while ( v91 != 0 );
      v76 = v137;
      v75 = v136;
      v74 = v135;
      v73 = v134;
      v71 = v133;
      *(float *)&numSpheres = v132;
    }
    __asm { vpermwi128 v49, v7, 0x4E # 'N' }
    _R11 = &v131;
    __asm { vpermwi128 v13, v9, 0x4E # 'N' }
    _R10 = &v132;
    __asm
    {
      vminfp128 v48, v7, v49
      vcmpgtfp128 v12, v7, v49
      vpermwi128 v47, v48, 0xB1
      vsel      v12, v9, v13, v12
      vcmpgtfp128 v11, v80, v47
      vminfp128 v46, v80, v47
      vpermwi128 v13, v12, 0xB1
      vsel      v0, v12, v13, v11
      stvewx    v0, 0, r11
      vcmpgtsw. v0, v0, v27
      stvewx128 v46, r0, r10
    }
    if ( (((v100 << 7) | (v101 << 6)) & 0x80) != 0 )
    {
      v102 = v131;
      _FP0 = v132;
      v104 = 4 * v131;
      v105 = *(float *)&v74[4 * v131];
      __asm { fsel      f2, f0, f0, f13 }
      v107 = &modelOrigin->x + 4 * (unsigned __int8)v70[v131] + 4 * __ROL4__((unsigned __int8)v70[v131], 1);
      v108 = (float)(_R21->x + (float)((float)(_R27->x - _R21->x) * (float)_FP2));
      v109 = (float)(_R21->z + (float)((float)(_R27->z - _R21->z) * (float)_FP2));
      v110 = (float)(_R21->y + (float)((float)(_R27->y - _R21->y) * (float)_FP2));
      v111 = (float)((float)(_R21->z + (float)((float)(_R27->z - _R21->z) * (float)_FP2))
                   - (float)(_R20->mat[0].z
                           + (float)((float)(a36[2]
                                           * (float)((float)((float)(*v107 * *(float *)&v71[4 * v131])
                                                           + (float)((float)(v107[2] * (float)v105)
                                                                   + (float)(v107[1] * *(float *)&v73[4 * v131])))
                                                   + v107[3]))
                                   + (float)((float)(a36[8]
                                                   * (float)((float)((float)(v107[8] * *(float *)&v71[4 * v131])
                                                                   + (float)((float)(v107[10] * (float)v105)
                                                                           + (float)(v107[9] * *(float *)&v73[4 * v131])))
                                                           + v107[11]))
                                           + (float)(a36[5]
                                                   * (float)((float)((float)(v107[4] * *(float *)&v71[4 * v131])
                                                                   + (float)((float)(v107[6] * (float)v105)
                                                                           + (float)(v107[5] * *(float *)&v73[4 * v131])))
                                                           + v107[7]))))));
      v113 = (float)((float)(_R21->x + (float)((float)(_R27->x - _R21->x) * (float)_FP2))
                   - (float)(_R20->mat[0].x
                           + (float)((float)(*a36
                                           * (float)((float)((float)(*v107 * *(float *)&v71[4 * v131])
                                                           + (float)((float)(v107[2] * (float)v105)
                                                                   + (float)(v107[1] * *(float *)&v73[4 * v131])))
                                                   + v107[3]))
                                   + (float)((float)(a36[6]
                                                   * (float)((float)((float)(v107[8] * *(float *)&v71[4 * v131])
                                                                   + (float)((float)(v107[10] * (float)v105)
                                                                           + (float)(v107[9] * *(float *)&v73[4 * v131])))
                                                           + v107[11]))
                                           + (float)(a36[3]
                                                   * (float)((float)((float)(v107[4] * *(float *)&v71[4 * v131])
                                                                   + (float)((float)(v107[6] * (float)v105)
                                                                           + (float)(v107[5] * *(float *)&v73[4 * v131])))
                                                           + v107[7]))))));
      v112 = (float)((float)(_R21->y + (float)((float)(_R27->y - _R21->y) * (float)_FP2))
                   - (float)(_R20->mat[0].y
                           + (float)((float)(a36[1]
                                           * (float)((float)((float)(*v107 * *(float *)&v71[4 * v131])
                                                           + (float)((float)(v107[2] * (float)v105)
                                                                   + (float)(v107[1] * *(float *)&v73[4 * v131])))
                                                   + v107[3]))
                                   + (float)((float)(a36[7]
                                                   * (float)((float)((float)(v107[8] * *(float *)&v71[4 * v131])
                                                                   + (float)((float)(v107[10] * (float)v105)
                                                                           + (float)(v107[9] * *(float *)&v73[4 * v131])))
                                                           + v107[11]))
                                           + (float)(a36[4]
                                                   * (float)((float)((float)(v107[4] * *(float *)&v71[4 * v131])
                                                                   + (float)((float)(v107[6] * (float)v105)
                                                                           + (float)(v107[5] * *(float *)&v73[4 * v131])))
                                                           + v107[7]))))));
      contents = modelEntityNuma;
      v115 = idMath::FLT_SMALLEST_NON_DENORMAL;
      v116 = modelEntityNuma == 0;
      trace->fraction = _FP2;
      p_endpos->z = v109;
      p_endpos->y = v110;
      p_endpos->x = v108;
      trace->c.type = CONTACT_SPHERE;
      z = p_endpos->z;
      y = p_endpos->y;
      _FP3 = (float)((float)((float)((float)v113 * (float)v113)
                           + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112)))
                   - (float)v115);
      __asm { fsel      f13, f3, f7, f13 }
      v121 = __frsqrte(_FP13);
      v122 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v121
                                                                                           * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5))
                                                                                   * (float)v121)
                                                                           - (float)1.5)
                                                           * (float)v121)
                                                   * (float)((float)((float)((float)v113 * (float)v113)
                                                                   + (float)((float)((float)v111 * (float)v111)
                                                                           + (float)((float)v112 * (float)v112)))
                                                           * (float)0.5))
                                           * (float)((float)-(float)((float)((float)((float)v121
                                                                                   * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112)))
                                                                                           * (float)0.5))
                                                                           * (float)v121)
                                                                   - (float)1.5)
                                                   * (float)v121))
                                   - (float)1.5)
                   * (float)((float)-(float)((float)((float)((float)v121
                                                           * (float)((float)((float)((float)v113 * (float)v113)
                                                                           + (float)((float)((float)v111 * (float)v111)
                                                                                   + (float)((float)v112 * (float)v112)))
                                                                   * (float)0.5))
                                                   * (float)v121)
                                           - (float)1.5)
                           * (float)v121));
      v123 = (float)((float)v113
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121) * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121)
                                                                                           - (float)1.5)
                                                                           * (float)v121))
                                                           * (float)((float)((float)((float)v113 * (float)v113)
                                                                           + (float)((float)((float)v111 * (float)v111)
                                                                                   + (float)((float)v112 * (float)v112)))
                                                                   * (float)0.5))
                                                   * (float)v122)
                                           - (float)1.5)
                           * (float)v122));
      v124 = (float)((float)v112
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121) * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121)
                                                                                           - (float)1.5)
                                                                           * (float)v121))
                                                           * (float)((float)((float)((float)v113 * (float)v113)
                                                                           + (float)((float)((float)v111 * (float)v111)
                                                                                   + (float)((float)v112 * (float)v112)))
                                                                   * (float)0.5))
                                                   * (float)v122)
                                           - (float)1.5)
                           * (float)v122));
      trace->c.point.x = p_endpos->x
                       - (float)((float)((float)v113
                                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121) * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121)) - (float)1.5)
                                                                                       * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5)
                                                                                               * (float)v121))
                                                                               * (float)((float)((float)((float)v113 * (float)v113)
                                                                                               + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112)))
                                                                                       * (float)0.5))
                                                                       * (float)v122)
                                                               - (float)1.5)
                                               * (float)v122))
                               * (float)radius);
      trace->c.point.z = (float)z
                       - (float)((float)((float)v111
                                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121) * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121)) - (float)1.5)
                                                                                       * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5)
                                                                                               * (float)v121))
                                                                               * (float)((float)((float)((float)v113 * (float)v113)
                                                                                               + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112)))
                                                                                       * (float)0.5))
                                                                       * (float)v122)
                                                               - (float)1.5)
                                               * (float)v122))
                               * (float)radius);
      trace->c.point.y = (float)y
                       - (float)((float)((float)v112
                                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121) * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121)) - (float)1.5)
                                                                                       * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5)
                                                                                               * (float)v121))
                                                                               * (float)((float)((float)((float)v113 * (float)v113)
                                                                                               + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112)))
                                                                                       * (float)0.5))
                                                                       * (float)v122)
                                                               - (float)1.5)
                                               * (float)v122))
                               * (float)radius);
      trace->c.normal.z = (float)v111
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121) * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121)
                                                                                                - (float)1.5)
                                                                                * (float)v121))
                                                                * (float)((float)((float)((float)v113 * (float)v113)
                                                                                + (float)((float)((float)v111
                                                                                                * (float)v111)
                                                                                        + (float)((float)v112
                                                                                                * (float)v112)))
                                                                        * (float)0.5))
                                                        * (float)v122)
                                                - (float)1.5)
                                * (float)v122);
      trace->c.normal.x = (float)v113
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121) * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121)
                                                                                                - (float)1.5)
                                                                                * (float)v121))
                                                                * (float)((float)((float)((float)v113 * (float)v113)
                                                                                + (float)((float)((float)v111
                                                                                                * (float)v111)
                                                                                        + (float)((float)v112
                                                                                                * (float)v112)))
                                                                        * (float)0.5))
                                                        * (float)v122)
                                                - (float)1.5)
                                * (float)v122);
      trace->c.normal.y = (float)v112
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121) * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121)
                                                                                                - (float)1.5)
                                                                                * (float)v121))
                                                                * (float)((float)((float)((float)v113 * (float)v113)
                                                                                + (float)((float)((float)v111
                                                                                                * (float)v111)
                                                                                        + (float)((float)v112
                                                                                                * (float)v112)))
                                                                        * (float)0.5))
                                                        * (float)v122)
                                                - (float)1.5)
                                * (float)v122);
      trace->c.dist = (float)((float)v123 * trace->c.point.x)
                    + (float)((float)((float)((float)v111
                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121) * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121)) - (float)1.5)
                                                                                            * (float)((float)-(float)((float)((float)((float)v121 * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112))) * (float)0.5)) * (float)v121) - (float)1.5) * (float)v121))
                                                                                    * (float)((float)((float)((float)v113 * (float)v113) + (float)((float)((float)v111 * (float)v111) + (float)((float)v112 * (float)v112)))
                                                                                            * (float)0.5))
                                                                            * (float)v122)
                                                                    - (float)1.5)
                                                    * (float)v122))
                                    * trace->c.point.z)
                            + (float)((float)v124 * trace->c.point.y));
      trace->c.separation = *(float *)&v75[v104];
      if ( v116 )
        contents = csData->contents;
      v125 = numSpheres - 1;
      trace->c.contentFlags = contents;
      trace->c.surfaceType = (unsigned __int8)v76[v102];
      trace->c.surfaceFlags = 0;
      if ( v102 < numSpheres - 1 )
        v125 = v102;
      v126 = a38;
      v127 = a40;
      v128 = a42;
      v129 = modelAxis_0;
      trace->c.modelFeature = v125;
      v130 = (unsigned __int8)v70[v102];
      trace->c.entityNum = v126;
      trace->c.physicsId = v127;
      trace->c.bodyId = v128;
      trace->c.selfId = (int)v129;
      trace->c.trmFeature = v130;
      trace->c.flags = 0;
    }
  }
}

