
// ========================================================================
// ?StaticTransparencyGenJob@@YAXPBUstaticTransparencyGenParms_t@@@Z
// EA  : 0x82866618
// RVA : 0x00866618
// PDB : w:\tech5\engine\models\static\jobs\statictransparencygen.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall StaticTransparencyGenJob(const staticTransparencyGenParms_t *parms)
{
  int v1; // r2 OVERLAPPED
  int numInputVerts; // r10
  double v4; // fp22
  idVec3 *p_viewOrg; // r27
  idVec3 *p_viewDir; // r26
  int v7; // r15
  __int64 v8; // r6
  double v9; // fp28
  float *p_axis; // r28
  double v11; // fp29
  idVec3 *p_origin; // r25
  idVec4 *v13; // r24
  idVec4 *v14; // r23
  idVec4 *v15; // r22
  idVec4 *v16; // r21
  idVec4 *v17; // r20
  idVec4 *channelLighting; // r19
  approximateLighting_t *p_lighting; // r18
  idVec4 *p_primeLightColor; // r17
  float *v21; // r14
  int v22; // r16
  char *v23; // r30
  int v24; // r29
  const idDrawVert *v25; // r11
  __int64 v26; // r4
  double v27; // fp26
  double v28; // fp3
  double v29; // fp5
  double v30; // fp2
  double v33; // fp0
  double v34; // fp0
  double v35; // fp0
  double v36; // fp0
  double v37; // fp27
  double v38; // fp0
  double v39; // fp12
  double v40; // fp10
  double v41; // fp9
  double v42; // fp12
  double v43; // fp11
  double v44; // fp6
  double v45; // fp25
  double v46; // fp8
  double v47; // fp17
  double v48; // fp7
  double z; // fp20
  double v50; // fp9
  double v51; // fp0
  double v52; // fp14
  double v53; // fp11
  double v54; // fp15
  double x; // fp10
  double y; // fp19
  double v57; // fp16
  double v58; // fp29
  double v59; // fp28
  double v60; // fp1
  double v61; // fp12
  double v62; // fp11
  double v63; // fp3
  double v64; // fp8
  double v65; // fp2
  double v66; // fp4
  double v67; // fp13
  double v68; // fp11
  double v69; // fp26
  double v70; // fp23
  double v71; // fp0
  double v72; // fp12
  double v73; // fp15
  double v74; // fp20
  double v75; // fp17
  double v76; // fp26
  double v77; // fp18
  double v78; // fp25
  double v79; // fp5
  double v80; // fp4
  long double v81; // fp2
  double v82; // fp27
  double v83; // fp26
  double v84; // fp25
  double v85; // fp23
  long double v86; // fp2
  int v87; // r11
  const idDrawVert *v88; // r7
  long double v90; // fp2
  int v91; // r11
  int v92; // r11
  int v93; // r11
  int v94; // r11
  int v95; // r11
  int v96; // ctr
  bool v101; // cr34
  double v102; // [sp+50h] [-220h]
  idTransparencyVert **p_verts; // [sp+58h] [-218h]
  int v104; // [sp+5Ch] [-214h]
  float *v105; // [sp+60h] [-210h]
  float *p_z; // [sp+64h] [-20Ch]
  int v107; // [sp+68h] [-208h]
  float *v108; // [sp+6Ch] [-204h]
  float **p_quadDepth; // [sp+70h] [-200h]
  float *p_y; // [sp+74h] [-1FCh]
  int v111; // [sp+80h] [-1F0h]
  float *p_w; // [sp+84h] [-1ECh]
  float v113; // [sp+88h] [-1E8h]
  double v114; // [sp+98h] [-1D8h]
  char v115; // [sp+BFh] [-1B1h] BYREF
  float v116[4]; // [sp+C0h] [-1B0h] BYREF
  _BYTE v117[16]; // [sp+D0h] [-1A0h] BYREF
  float v118; // [sp+E0h] [-190h]
  float v119; // [sp+E4h] [-18Ch]
  float v120; // [sp+E8h] [-188h]
  float v121; // [sp+100h] [-170h]
  float v122; // [sp+104h] [-16Ch]
  float v123; // [sp+108h] [-168h]
  float v124; // [sp+120h] [-150h]
  float v125; // [sp+124h] [-14Ch]
  float v126; // [sp+128h] [-148h]

  numInputVerts = parms->numInputVerts;
  v4 = (float)((float)1.0 / (float)(parms->fadeMaxDist - parms->fadeStartDist));
  v111 = numInputVerts / 4;
  if ( numInputVerts / 4 <= 0 )
  {
    *parms->quadsUsed = numInputVerts / 4;
  }
  else
  {
    v107 = numInputVerts / 4;
    p_viewOrg = &parms->viewOrg;
    p_y = &parms->transSortScaleBias.y;
    p_viewDir = &parms->viewDir;
    p_w = &parms->transSortScaleBias.w;
    p_verts = &parms->verts;
    p_z = &parms->viewOrg.z;
    v105 = &parms->viewDir.z;
    v108 = &parms->viewDir.y;
    p_quadDepth = &parms->quadDepth;
    v7 = 0;
    HIDWORD(v8) = &idMath::FLT_SMALLEST_NON_DENORMAL;
    v9 = 1.5;
    p_axis = (float *)&parms->axis;
    v11 = 0.0078431377;
    p_origin = &parms->origin;
    v113 = 255.0;
    v104 = 0;
    v13 = &parms->lighting.channelLighting[5];
    v14 = &parms->lighting.channelLighting[4];
    v15 = &parms->lighting.channelLighting[3];
    v16 = &parms->lighting.channelLighting[2];
    v17 = &parms->lighting.channelLighting[1];
    channelLighting = parms->lighting.channelLighting;
    p_lighting = &parms->lighting;
    p_primeLightColor = &parms->lighting.primeLightColor;
    v21 = &parms->viewOrg.y;
    do
    {
      v22 = 0;
      v23 = &v115;
      do
      {
        v24 = v7 * 4 + v22;
        v25 = &parms->inputVerts[v24];
        LODWORD(v8) = v25->normal[0];
        LODWORD(v26) = v25->normal[1];
        HIDWORD(v26) = v25->normal[2];
        v27 = (float)((float)((float)*(__int64 *)(&v1 - 1) * (float)v11) - (float)1.0);
        v28 = (float)((float)((float)v8 * (float)v11) - (float)1.0);
        v29 = (float)((float)((float)(p_axis[6] * v25->xyz.z)
                            + (float)((float)(*p_axis * v25->xyz.x) + (float)(p_axis[3] * v25->xyz.y)))
                    + p_origin->x);
        v30 = (float)((float)((float)v26 * (float)v11) - (float)1.0);
        _FP21 = (float)((float)((float)((float)v30 * (float)v30)
                              + (float)((float)((float)v28 * (float)v28) + (float)((float)v27 * (float)v27)))
                      - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f0, f21, f27, f0 }
        v33 = __frsqrte(_FP0);
        v34 = (float)((float)-(float)((float)((float)((float)v33
                                                    * (float)((float)((float)((float)v30 * (float)v30)
                                                                    + (float)((float)((float)v28 * (float)v28)
                                                                            + (float)((float)v27 * (float)v27)))
                                                            * (float)0.5))
                                            * (float)v33)
                                    - (float)v9)
                    * (float)v33);
        v35 = (float)((float)-(float)((float)((float)((float)v34
                                                    * (float)((float)((float)((float)v30 * (float)v30)
                                                                    + (float)((float)((float)v28 * (float)v28)
                                                                            + (float)((float)v27 * (float)v27)))
                                                            * (float)0.5))
                                            * (float)v34)
                                    - (float)v9)
                    * (float)v34);
        v36 = (float)((float)-(float)((float)((float)((float)v35
                                                    * (float)((float)((float)((float)v30 * (float)v30)
                                                                    + (float)((float)((float)v28 * (float)v28)
                                                                            + (float)((float)v27 * (float)v27)))
                                                            * (float)0.5))
                                            * (float)v35)
                                    - (float)v9)
                    * (float)v35);
        v37 = (float)((float)((float)((float)*(__int64 *)(&v1 - 1) * (float)v11) - (float)1.0) * (float)v36);
        v39 = (float)((float)(p_axis[8]
                            * (float)((float)((float)((float)*(__int64 *)(&v1 - 1) * (float)v11) - (float)1.0)
                                    * (float)v36))
                    + (float)(p_axis[5] * (float)((float)((float)((float)v26 * (float)v11) - (float)1.0) * (float)v36)));
        v40 = (float)(p_axis[4] * (float)((float)((float)((float)v26 * (float)v11) - (float)1.0) * (float)v36));
        v41 = (float)((float)(p_axis[6]
                            * (float)((float)((float)((float)*(__int64 *)(&v1 - 1) * (float)v11) - (float)1.0)
                                    * (float)v36))
                    + (float)(p_axis[3] * (float)((float)((float)((float)v26 * (float)v11) - (float)1.0) * (float)v36)));
        v38 = (float)((float)v36 * (float)((float)((float)v8 * (float)v11) - (float)1.0));
        v42 = (float)((float)(p_axis[2] * (float)v38) + (float)v39);
        v43 = (float)((float)(*p_axis * (float)v38) + (float)v41);
        v44 = (float)(p_origin->z
                    + (float)((float)(p_axis[8] * v25->xyz.z)
                            + (float)((float)(p_axis[2] * v25->xyz.x) + (float)(p_axis[5] * v25->xyz.y))));
        v45 = (float)(v16->y + v15->y);
        v46 = (float)((float)(p_axis[1] * (float)v38) + (float)((float)(p_axis[7] * (float)v37) + (float)v40));
        v47 = __fabs(v43);
        v48 = (float)(v15->z + v16->z);
        z = v13->z;
        v50 = v14->z;
        v51 = (float)(v14->x + v13->x);
        v52 = *p_z;
        v53 = (float)((float)(p_lighting->primeLightDir.x * (float)v43)
                    + (float)(p_lighting->primeLightDir.z * (float)v42));
        v114 = v11;
        v102 = v9;
        v54 = __fabs(v46);
        x = p_primeLightColor->x;
        y = p_primeLightColor->y;
        v57 = p_primeLightColor->z;
        v58 = *v21;
        v59 = *v105;
        v60 = (float)(p_origin->y
                    + (float)((float)(p_axis[7] * v25->xyz.z)
                            + (float)((float)(p_axis[1] * v25->xyz.x) + (float)(p_axis[4] * v25->xyz.y))));
        v61 = (float)((float)__fabs(v42) * (float)0.5);
        v62 = (float)((float)(p_lighting->primeLightDir.y * (float)v46) + (float)v53);
        v63 = (float)((float)v54 * (float)0.5);
        v64 = (float)((float)((float)v47 * (float)0.5) * (float)(v17->x + channelLighting->x));
        v65 = (float)((float)(v17->y + channelLighting->y) * (float)((float)v47 * (float)0.5));
        v66 = (float)((float)(v17->z + channelLighting->z) * (float)((float)v47 * (float)0.5));
        v67 = (float)((float)((float)v54 * (float)0.5) * (float)(v15->x + v16->x));
        v68 = (float)((float)__fabs(v62) * (float)0.5);
        v69 = p_viewOrg->x;
        v70 = (float)((float)(v13->y + v14->y) * (float)v61);
        *(float *)(v23 + 1) = (float)((float)(p_axis[6] * v25->xyz.z)
                                    + (float)((float)(*p_axis * v25->xyz.x) + (float)(p_axis[3] * v25->xyz.y)))
                            + p_origin->x;
        v71 = (float)((float)v61 * (float)v51);
        *(float *)(v23 + 5) = v60;
        v72 = (float)((float)((float)z + (float)v50) * (float)v61);
        v74 = v25->st.x;
        v75 = parms->transSortScaleBias.x;
        v76 = (float)((float)v29 - (float)v69);
        v77 = p_viewDir->x;
        v78 = (float)((float)v45 * (float)((float)v54 * (float)0.5));
        v73 = *v108;
        *(float *)(v23 + 9) = v44;
        v79 = (float)((float)((float)v68 * (float)v57) + (float)v66);
        v80 = (float)((float)((float)v77 * (float)v76)
                    + (float)((float)((float)v73 * (float)((float)v60 - (float)v58))
                            + (float)((float)v59 * (float)((float)v44 - (float)v52))));
        *(double *)&v81 = (float)((float)((float)((float)((float)((float)v75 * (float)v74) + parms->transSortScaleBias.z)
                                                - (float)0.5)
                                        * (float)65534.0)
                                + (float)0.5);
        *((double *)&v81 + 1) = (float)((float)((float)((float)v68 * (float)y) + (float)v65) + (float)v78);
        v82 = (float)((float)((float)((float)((float)x * (float)v68) + (float)v64) + (float)v67) + (float)v71);
        v83 = (float)((float)*((double *)&v81 + 1) + (float)v70);
        v84 = (float)((float)((float)v79 + (float)((float)v48 * (float)v63)) + (float)v72);
        v85 = (float)-(float)((float)((float)((float)v80 - parms->fadeStartDist) * (float)v4) - (float)1.0);
        v86 = floor(x: v81);
        v11 = v114;
        v9 = v102;
        v87 = (int)(float)*(double *)&v86;
        if ( v87 >= -32768 )
        {
          if ( v87 > 0x7FFF )
            LOWORD(v87) = 0x7FFF;
        }
        else
        {
          LOWORD(v87) = 0x8000;
        }
        v88 = &parms->inputVerts[v24];
        *(_WORD *)(v23 + 17) = v87;
        *(_WORD *)(v23 + 13) = v87;
        *(double *)&v86 = (float)((float)((float)((float)((float)(*p_y * v88->st.y) + *p_w) - (float)0.5)
                                        * (float)65534.0)
                                + (float)0.5);
        v90 = floor(x: v86);
        v91 = (int)(float)*(double *)&v90;
        if ( v91 >= -32768 )
        {
          if ( v91 > 0x7FFF )
            LOWORD(v91) = 0x7FFF;
        }
        else
        {
          LOWORD(v91) = 0x8000;
        }
        *(_WORD *)(v23 + 19) = v91;
        *(_WORD *)(v23 + 15) = v91;
        v23[21] = 0;
        v23[22] = 0;
        v23[23] = 0;
        *((_WORD *)v23 + 12) = 255;
        v23[26] = 0;
        v23[27] = 0;
        v92 = (int)(float)((float)v82 * v113);
        v23[28] = -1;
        if ( v92 >= 0 )
        {
          if ( v92 > 255 )
            LOBYTE(v92) = -1;
        }
        else
        {
          LOBYTE(v92) = 0;
        }
        v23[29] = v92;
        v93 = (int)(float)((float)v83 * v113);
        if ( v93 >= 0 )
        {
          if ( v93 > 255 )
            LOBYTE(v93) = -1;
        }
        else
        {
          LOBYTE(v93) = 0;
        }
        v23[30] = v93;
        v94 = (int)(float)((float)v84 * v113);
        if ( v94 >= 0 )
        {
          if ( v94 > 255 )
            LOBYTE(v94) = -1;
        }
        else
        {
          LOBYTE(v94) = 0;
        }
        v23[31] = v94;
        v95 = (int)(float)((float)v85 * v113);
        if ( v95 >= 0 )
        {
          if ( v95 > 255 )
            LOBYTE(v95) = -1;
        }
        else
        {
          LOBYTE(v95) = 0;
        }
        ++v22;
        v23 += 32;
        *v23 = v95;
      }
      while ( v22 < 4 );
      v96 = 4;
      _R11 = &(*p_verts)[v104];
      _R9 = (char *)((char *)v116 - (char *)_R11);
      _R10 = (_BYTE *)(v117 - (_BYTE *)_R11);
      _R8 = 16;
      do
      {
        __asm
        {
          lvx128    v63, r9, r11
          stvx128   v63, r0, r11
          lvx128    v62, r10, r11
          stvx128   v62, r11, r8
        }
        ++_R11;
        --v96;
      }
      while ( v96 != 0 );
      HIDWORD(v8) = v107;
      v101 = v107 == 1;
      v104 += 4;
      (*p_quadDepth)[v7++] = (float)(p_viewDir->x
                                   * (float)((float)((float)((float)((float)(v118 + v116[0]) + v121) + v124)
                                                   * (float)0.25)
                                           - p_viewOrg->x))
                           + (float)((float)(*v108
                                           * (float)((float)((float)((float)((float)(v119 + v116[1]) + v122) + v125)
                                                           * (float)0.25)
                                                   - *v21))
                                   + (float)(*v105
                                           * (float)((float)((float)((float)((float)(v116[2] + v120) + v123) + v126)
                                                           * (float)0.25)
                                                   - *p_z)));
      --v107;
    }
    while ( !v101 );
    *parms->quadsUsed = v111;
  }
}


// ========================================================================
// `dynamic initializer for 'register_StaticTransparencyGenJob''
// EA  : 0x83344AB8
// RVA : 0x01344AB8
// PDB : w:\tech5\engine\models\static\jobs\statictransparencygen.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_StaticTransparencyGenJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_StaticTransparencyGenJob,
           function: (void (__fastcall *)(void *))StaticTransparencyGenJob,
           name: "StaticTransparencyGenJob");
}

