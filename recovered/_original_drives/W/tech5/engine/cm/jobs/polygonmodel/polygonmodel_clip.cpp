
// ========================================================================
// ?ClipInPlace@idPolygonModelCollisionDetection@@CAHPAVidVec5@@HABVidPlane@@M_N@Z
// EA  : 0x825E7230
// RVA : 0x005E7230
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_clip.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::ClipInPlace(
        idVec5 *points,
        int numPoints,
        const idPlane *plane,
        double epsilon,
        const bool keepOn,
        char a6)
{
  int v6; // r10
  double c; // fp0
  float *v8; // r9
  double b; // fp13
  char *v10; // r8
  double a; // fp11
  double d; // fp10
  double v13; // fp12
  idVec5 *v14; // r11
  double v15; // fp6
  double v16; // fp7
  double x; // fp4
  double v18; // fp29
  double z; // fp2
  double v20; // fp31
  double v21; // fp30
  double v22; // fp28
  double v23; // fp3
  double v24; // fp8
  double v25; // fp6
  bool v26; // r31
  int v27; // r24
  int v28; // r31
  int v29; // r27
  int v30; // r29
  int v31; // r6
  int v32; // r31
  int v33; // r29
  double v34; // fp13
  double v35; // fp12
  double v36; // fp11
  double v37; // fp10
  double v38; // fp9
  float *v39; // r9
  idVec5 *v40; // r11
  int v41; // ctr
  double v42; // fp8
  double v43; // fp7
  double v44; // fp4
  int v45; // r6
  double v46; // fp0
  float v47; // r11
  int v49; // r28
  int v50; // r26
  int v51; // r29
  _BYTE *v52; // r31
  float *v53; // r30
  float *p_z; // r6
  int v55; // r27
  char *v56; // r7
  int v57; // r8
  float *v58; // r11
  _DWORD *v59; // r10
  int i; // ctr
  float *v61; // r11
  _DWORD *v62; // r10
  int j; // ctr
  int v64; // r11
  double v65; // fp0
  idVec5 *v66; // r11
  double v67; // fp13
  double v68; // fp0
  double v69; // fp0
  double s; // fp0
  double t; // fp10
  double v72; // fp9
  double v73; // fp8
  double v74; // fp0
  double v75; // fp0
  char *v76; // r11
  _DWORD *v77; // r10
  int v78; // ctr
  char v79; // [sp+5Ch] [-434h] BYREF
  float v80; // [sp+60h] [-430h] BYREF
  float v81; // [sp+64h] [-42Ch]
  float v82; // [sp+68h] [-428h]
  float v83; // [sp+6Ch] [-424h]
  float v84; // [sp+70h] [-420h]
  char v85; // [sp+7Fh] [-411h] BYREF
  char v86; // [sp+80h] [-410h] BYREF
  char v87; // [sp+ACh] [-3E4h] BYREF
  float v88; // [sp+B0h] [-3E0h] BYREF
  char v89; // [sp+B4h] [-3DCh] BYREF
  _BYTE v90[760]; // [sp+140h] [-350h] BYREF

  v81 = 0.0;
  v6 = 0;
  v80 = 0.0;
  v82 = 0.0;
  if ( numPoints >= 4 )
  {
    c = plane->c;
    v8 = (float *)&v87;
    b = plane->b;
    v10 = &v85;
    a = plane->a;
    d = plane->d;
    v13 = -epsilon;
    v14 = points - 1;
    do
    {
      v15 = (float)(v14[2].y * (float)b);
      v16 = (float)(v14[3].y * (float)b);
      x = v14[2].x;
      v18 = (float)(v14[4].y * (float)b);
      z = v14[2].z;
      v20 = v14[3].x;
      v21 = v14[3].z;
      v22 = v14[4].z;
      v23 = (float)((float)((float)b * v14[1].y) + (float)((float)(v14[1].z * (float)c) + (float)((float)a * v14[1].x)));
      v14 += 4;
      v24 = (float)((float)((float)c * (float)v22) + (float)((float)(v14->x * (float)a) + (float)v18));
      v8[1] = (float)v23 + (float)d;
      v25 = (float)((float)((float)((float)z * (float)c) + (float)((float)((float)x * (float)a) + (float)v15)) + (float)d);
      v8[2] = v25;
      v8[3] = (float)((float)((float)v21 * (float)c) + (float)((float)((float)v20 * (float)a) + (float)v16)) + (float)d;
      v26 = COERCE_INT((float)v13 - (float)((float)v23 + (float)d)) >= 0;
      v27 = (unsigned __int8)((2 * ((COERCE_INT((float)epsilon - (float)((float)v23 + (float)d)) >= 0) ^ v26)) | v26);
      v28 = (4 * v27) & 0x3C;
      v10[1] = v27;
      v29 = *(_DWORD *)((char *)&v80 + v28);
      v30 = 4
          * (unsigned __int8)((2
                             * ((COERCE_INT((float)epsilon - (float)v25) >= 0)
                              ^ (COERCE_INT((float)v13 - (float)v25) >= 0)))
                            | (COERCE_INT((float)v13 - (float)v25) >= 0));
      v10[2] = (2 * ((COERCE_INT((float)epsilon - (float)v25) >= 0) ^ (COERCE_INT((float)v13 - (float)v25) >= 0)))
             | (COERCE_INT((float)v13 - (float)v25) >= 0);
      LOBYTE(v27) = COERCE_INT(
                      (float)v13
                    - (float)((float)((float)((float)v21 * (float)c)
                                    + (float)((float)((float)v20 * (float)a) + (float)v16))
                            + (float)d)) >= 0;
      *(_DWORD *)((char *)&v80 + v28) = v29 + 1;
      v31 = *(_DWORD *)((char *)&v80 + v30);
      v8 += 4;
      *v8 = (float)v24 + (float)d;
      LOBYTE(v29) = COERCE_INT((float)v13 - (float)((float)v24 + (float)d)) >= 0;
      v32 = (unsigned __int8)((2
                             * ((COERCE_INT(
                                   (float)epsilon
                                 - (float)((float)((float)((float)v21 * (float)c)
                                                 + (float)((float)((float)v20 * (float)a) + (float)v16))
                                         + (float)d)) >= 0)
                              ^ v27))
                            | v27);
      v10[3] = v32;
      *(_DWORD *)((char *)&v80 + v30) = v31 + 1;
      v33 = (unsigned __int8)((2 * ((COERCE_INT((float)epsilon - (float)((float)v24 + (float)d)) >= 0) ^ v29)) | v29);
      v6 += 4;
      ++*(_DWORD *)((char *)&v80 + ((4 * v32) & 0x3C));
      v10 += 4;
      *v10 = v33;
      ++*(_DWORD *)((char *)&v80 + ((4 * v33) & 0x3C));
    }
    while ( v6 < numPoints - 3 );
  }
  if ( v6 < numPoints )
  {
    v34 = plane->c;
    v35 = plane->b;
    v36 = plane->a;
    v37 = plane->d;
    v38 = -epsilon;
    v39 = &v88 + v6 - 1;
    v40 = &points[v6 - 1];
    v41 = numPoints - v6;
    do
    {
      v42 = (float)((float)v35 * v40[1].y);
      v43 = v40[1].z;
      ++v40;
      v44 = (float)((float)((float)((float)v34 * (float)v43) + (float)((float)((float)v36 * v40->x) + (float)v42))
                  + (float)v37);
      *++v39 = (float)((float)((float)v34 * (float)v43) + (float)((float)((float)v36 * v40->x) + (float)v42))
             + (float)v37;
      v45 = 4
          * (unsigned __int8)((2
                             * ((COERCE_INT((float)epsilon - (float)v44) >= 0)
                              ^ (COERCE_INT((float)v38 - (float)v44) >= 0)))
                            | (COERCE_INT((float)v38 - (float)v44) >= 0));
      *(&v86 + v6++) = (2 * ((COERCE_INT((float)epsilon - (float)v44) >= 0) ^ (COERCE_INT((float)v38 - (float)v44) >= 0)))
                     | (COERCE_INT((float)v38 - (float)v44) >= 0);
      ++*(_DWORD *)((char *)&v80 + v45);
      --v41;
    }
    while ( v41 != 0 );
  }
  v46 = v88;
  *(&v86 + numPoints) = v86;
  v47 = v80;
  *(&v88 + numPoints) = v46;
  if ( a6 != 0 )
  {
    if ( v47 == 0.0 )
      return v81 == 0.0;
  }
  else if ( v47 == 0.0 )
  {
    return 0;
  }
  if ( v81 == 0.0 )
    return numPoints;
  v49 = 0;
  v50 = 0;
  if ( numPoints <= 0 )
    goto LABEL_66;
  v51 = 1 - (_DWORD)&v86;
  v52 = v90;
  v53 = (float *)&v89;
  p_z = &points->z;
  v55 = numPoints;
  do
  {
    v56 = &v86 + v50;
    v57 = (unsigned __int8)*(&v86 + v50);
    if ( v57 == 2 )
    {
      v58 = p_z - 3;
      v59 = v52 - 4;
      for ( i = 5; i != 0; --i )
        *++v59 = *(_DWORD *)++v58;
LABEL_62:
      v52 += 20;
      ++v49;
      goto LABEL_63;
    }
    if ( *(&v86 + v50) == 0 )
    {
      v61 = p_z - 3;
      v62 = v52 - 4;
      for ( j = 5; j != 0; --j )
        *++v62 = *(_DWORD *)++v61;
      ++v49;
      v52 += 20;
    }
    v64 = (unsigned __int8)v56[1];
    if ( v64 != 2 && v64 != v57 )
    {
      v65 = plane->a;
      __twllei(numPoints, 0);
      __twlgei(numPoints & ~(__ROL4__(&v56[v51], 1) - 1), 0xFFFFFFFF);
      v66 = &points[(int)&v56[v51] % numPoints];
      if ( v57 != 0 )
      {
        v67 = (float)(*v53 / (float)(*v53 - *(v53 - 1)));
        if ( v65 == 1.0 )
        {
          v80 = -plane->d;
        }
        else if ( v65 == -1.0 )
        {
          v80 = plane->d;
        }
        else
        {
          v80 = (float)((float)(*(p_z - 2) - v66->x) * (float)(*v53 / (float)(*v53 - *(v53 - 1)))) + v66->x;
        }
        v74 = plane->b;
        if ( v74 == 1.0 )
        {
          v81 = -plane->d;
        }
        else if ( v74 == -1.0 )
        {
          v81 = plane->d;
        }
        else
        {
          v81 = (float)((float)(*(p_z - 1) - v66->y) * (float)v67) + v66->y;
        }
        v75 = plane->c;
        if ( v75 == 1.0 )
        {
          v82 = -plane->d;
        }
        else if ( v75 == -1.0 )
        {
          v82 = plane->d;
        }
        else
        {
          v82 = (float)((float)(*p_z - v66->z) * (float)v67) + v66->z;
        }
        s = v66->s;
        t = v66->t;
        v72 = p_z[1];
        v73 = p_z[2];
      }
      else
      {
        v67 = (float)(*(v53 - 1) / (float)(*(v53 - 1) - *v53));
        if ( v65 == 1.0 )
        {
          v80 = -plane->d;
        }
        else if ( v65 == -1.0 )
        {
          v80 = plane->d;
        }
        else
        {
          v80 = (float)((float)(v66->x - *(p_z - 2)) * (float)(*(v53 - 1) / (float)(*(v53 - 1) - *v53))) + *(p_z - 2);
        }
        v68 = plane->b;
        if ( v68 == 1.0 )
        {
          v81 = -plane->d;
        }
        else if ( v68 == -1.0 )
        {
          v81 = plane->d;
        }
        else
        {
          v81 = (float)((float)(v66->y - *(p_z - 1)) * (float)v67) + *(p_z - 1);
        }
        v69 = plane->c;
        if ( v69 == 1.0 )
        {
          v82 = -plane->d;
          s = p_z[1];
          t = p_z[2];
          v72 = v66->s;
          v73 = v66->t;
        }
        else
        {
          if ( v69 == -1.0 )
          {
            v82 = plane->d;
            s = p_z[1];
            t = p_z[2];
          }
          else
          {
            t = p_z[2];
            v82 = (float)((float)(v66->z - *p_z) * (float)v67) + *p_z;
            s = p_z[1];
          }
          v72 = v66->s;
          v73 = v66->t;
        }
      }
      v76 = &v79;
      v77 = v52 - 4;
      v78 = 5;
      v84 = (float)((float)((float)v73 - (float)t) * (float)v67) + (float)t;
      v83 = (float)((float)((float)v72 - (float)s) * (float)v67) + (float)s;
      do
      {
        v76 += 4;
        *++v77 = *(_DWORD *)v76;
        --v78;
      }
      while ( v78 != 0 );
      goto LABEL_62;
    }
LABEL_63:
    --v55;
    ++v50;
    p_z += 5;
    ++v53;
  }
  while ( v55 != 0 );
  if ( v49 > 32 )
    v49 = 32;
LABEL_66:
  if ( v49 > 0 )
    blkmov(a1: points, a2: v90, a3: 20 * v49);
  return v49;
}


// ========================================================================
// ?ClipPolygonWithTrm@idPolygonModelCollisionDetection@@CA_NPAVidTraceWork@@I@Z
// EA  : 0x825E7918
// RVA : 0x005E7918
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_clip.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idPolygonModelCollisionDetection::ClipPolygonWithTrm(idTraceWork *tw, int polygonNum)
{
  int v2; // r2 OVERLAPPED
  int v5; // r9
  int v6; // r8
  unsigned __int8 v11; // cr58
  unsigned __int8 v12; // cr59
  unsigned __int16 *polygonEdges; // r6
  unsigned int numEdges; // r28
  __int64 v15; // r5
  unsigned int v16; // r9
  float *v17; // r11
  int firstEdge; // r30 OVERLAPPED
  cm_edge_t *edges; // r8
  cm_vertex_t *vertices; // r7
  int v21; // r26
  unsigned int v22; // r24
  float *v23; // r10
  int v24; // r31
  __int64 v25; // r25
  double v26; // fp12
  double v27; // fp11
  float *v28; // r10
  __int64 v29; // fp9
  double v30; // fp7
  int v31; // r31
  double v32; // fp12
  double v33; // fp5
  double v34; // fp4
  double v35; // fp10
  double v36; // fp1
  double v37; // fp9
  float *v38; // r10
  double v39; // fp7
  double v40; // fp6
  int v41; // r31
  double v42; // fp5
  int v43; // r10
  float *v44; // r10
  double v45; // fp4
  int v46; // r31
  double v47; // fp3
  double v48; // fp2
  double v49; // fp10
  __int64 v50; // r8
  cm_vertex_t *v51; // r31
  float *p_z; // r10
  unsigned int v53; // ctr
  float *v54; // r11
  float *v55; // r10
  int v56; // r3
  double v57; // fp12
  double v58; // fp11
  unsigned int numPolys; // r29
  unsigned int v60; // r30
  float *p_c; // r31
  double v62; // fp10
  double v63; // fp8
  double v64; // fp7
  int v65; // ctr
  idVec5 *v66; // r8
  __int16 *v67; // r5
  clipResult_t *clipResult; // r7
  int v69; // r9
  int numVerts; // r6
  int v71; // r10
  float *v72; // r11
  clipResult_t *v74; // r10
  double x; // fp0
  double y; // fp13
  double z; // fp12
  int v78; // r6
  int v79; // r9
  float *v80; // r11
  int v81; // r26
  __int16 v82; // r29
  __int16 *i; // r28
  clipResult_t *v84; // r10
  int numIndices; // r3
  __int16 v86; // r31
  __int16 v87; // r30
  int v88; // r5
  int v89; // r11
  int v90; // r8
  char *v91; // r9
  int v92; // r9
  bool v93; // cr58
  idPlane v95; // [sp+50h] [-360h] BYREF
  __int64 v96; // [sp+60h] [-350h]
  __int64 v97; // [sp+68h] [-348h]
  __int64 v98; // [sp+70h] [-340h]
  __int64 v99; // [sp+78h] [-338h]
  __int64 v100; // [sp+80h] [-330h]
  __int64 v101; // [sp+88h] [-328h]
  __int64 v102; // [sp+90h] [-320h]
  __int16 v103; // [sp+A0h] [-310h] BYREF
  char v104; // [sp+A4h] [-30Ch] BYREF
  char v105; // [sp+DCh] [-2D4h] BYREF
  idVec5 v106[32]; // [sp+E0h] [-2D0h] BYREF

  _R27 = tw;
  v5 = (unsigned __int8)(1 << (polygonNum & 7));
  v6 = tw->modelCheckCounts.polygonCheckCounts[polygonNum >> 3];
  tw->modelCheckCounts.polygonCheckCounts[polygonNum >> 3] = v6 | v5;
  if ( (v6 & v5) != 0 )
    return 0;
  _R3 = &tw->subModelPtrs.polygons[polygonNum];
  if ( (*(int *)((_BYTE *)&_R27->subModelPtrs.materials->contentFlags + __ROL4__(_R3->material, 4)) & _R27->contents) == 0 )
    return 0;
  __asm { lvx128    v63, r0, r3 }
  _R10 = 6176;
  _R9 = vmxi_half_bnds_intersect_perm2_1;
  _R8 = -16;
  __asm
  {
    lvx128    v62, r27, r10
    lvx128    v0, r0, r9
    lvx128    v7, r9, r8
    vperm128  v0, v94, v63, v0
    vperm128  v13, v94, v63, v7
    vcmpgtsh. v12, v13, v0
  }
  LOBYTE(polygonEdges) = ((32 * v11) & 0x20 | (16 * v12) & 0x20) != 0;
  if ( ((32 * v11) & 0x20 | (16 * v12) & 0x20) == 0 )
    return 0;
  numEdges = _R3->numEdges;
  HIDWORD(v15) = 0;
  v16 = 0;
  if ( numEdges >= 4 )
  {
    v17 = (float *)&v105;
    firstEdge = _R3->firstEdge;
    polygonEdges = _R27->subModelPtrs.polygonEdges;
    edges = _R27->subModelPtrs.edges;
    vertices = _R27->subModelPtrs.vertices;
    do
    {
      LODWORD(v15) = &polygonEdges[firstEdge + v16];
      v21 = firstEdge + v16 + 3;
      v22 = polygonEdges[firstEdge + 2 + v16];
      v23 = (float *)((char *)&vertices->p.x
                    + __ROL4__(
                        edges->vertexNum[((2 * *(unsigned __int16 *)v15) & 0x7FFE) + (*(unsigned __int16 *)v15 >> 15)],
                        4));
      LODWORD(v15) = __ROL4__(
                       edges->vertexNum[((2 * *(unsigned __int16 *)(v15 + 2)) & 0x7FFE)
                                      + (*(unsigned __int16 *)(v15 + 2) >> 15)],
                       4);
      v24 = edges->vertexNum[((2 * v22) & 0x7FFE) + (v22 >> 15)];
      LODWORD(v25) = *((unsigned __int16 *)v23 + 6);
      v26 = v23[1];
      HIDWORD(v25) = *((unsigned __int16 *)v23 + 7);
      v27 = v23[2];
      v17[1] = *v23;
      v28 = (float *)((char *)&vertices->p.x + v15);
      v98 = v25;
      v29 = v25;
      LODWORD(v15) = HIDWORD(v25);
      v17[2] = v26;
      v17[3] = v27;
      v102 = v15;
      v30 = (double)v15;
      HIDWORD(v25) = *((unsigned __int16 *)v28 + 6);
      LODWORD(v25) = *((unsigned __int16 *)v28 + 7);
      LODWORD(v15) = __ROL4__(v24, 4);
      v31 = HIDWORD(v25);
      v100 = v25;
      v99 = *(_QWORD *)(&firstEdge - 1);
      v32 = v28[2];
      v33 = (float)v29;
      v34 = *v28;
      v35 = (float)v30;
      v36 = v28[1];
      v37 = (float)*(__int64 *)(&firstEdge - 1);
      v38 = (float *)((char *)&vertices->p.x + v15);
      v39 = *(float *)((char *)&vertices->p.x + v15);
      v40 = *(float *)((char *)&vertices->p.y + v15);
      v41 = *(unsigned __int16 *)((char *)&vertices->st[1] + v15);
      LODWORD(v15) = *(unsigned __int16 *)((char *)vertices->st + v15);
      v17[4] = (float)v33 * (float)0.000015259022;
      v17[5] = (float)v35 * (float)0.000015259022;
      v17[6] = v34;
      v17[7] = v36;
      v17[8] = v32;
      v17[9] = (float)v37 * (float)0.000015259022;
      v17[10] = (float)v25 * (float)0.000015259022;
      v17[11] = v39;
      v42 = v38[2];
      v17[12] = v40;
      v17[13] = v42;
      v101 = v15;
      v97 = *(_QWORD *)(&firstEdge - 1);
      v16 += 4;
      v43 = edges->vertexNum[((2 * polygonEdges[v21]) & 0x7FFE) + (polygonEdges[v21] >> 15)];
      v17[14] = (float)v15 * (float)0.000015259022;
      HIDWORD(v15) += 4;
      v44 = (float *)((char *)&vertices->p.x + __ROL4__(v43, 4));
      LODWORD(v15) = *((unsigned __int16 *)v44 + 7);
      v45 = *v44;
      v47 = (float)((float)*(__int64 *)(&firstEdge - 1) * (float)0.000015259022);
      v46 = *((unsigned __int16 *)v44 + 6);
      v17[15] = v47;
      v48 = v44[1];
      v96 = v15;
      *(_QWORD *)&v95.a = *(_QWORD *)(&firstEdge - 1);
      v17[16] = v45;
      v49 = v44[2];
      v17[17] = v48;
      v17[18] = v49;
      v17[19] = (float)*(__int64 *)(&firstEdge - 1) * (float)0.000015259022;
      v17 += 20;
      *v17 = (float)v15 * (float)0.000015259022;
    }
    while ( v16 < numEdges - 3 );
  }
  if ( v16 < numEdges )
  {
    HIDWORD(v50) = _R3->firstEdge;
    polygonEdges = _R27->subModelPtrs.polygonEdges;
    LODWORD(v15) = _R27->subModelPtrs.edges;
    v51 = _R27->subModelPtrs.vertices;
    p_z = &v106[HIDWORD(v15)].z;
    HIDWORD(v15) += numEdges - v16;
    v53 = numEdges - v16;
    v54 = p_z - 3;
    do
    {
      LODWORD(v50) = 2 * (v16 + HIDWORD(v50));
      ++v16;
      v55 = (float *)((char *)&v51->p.x
                    + __ROL4__(
                        *(unsigned __int16 *)(2
                                            * (((2 * *(unsigned __int16 *)((char *)polygonEdges + v50)) & 0x7FFE)
                                             + (*(unsigned __int16 *)((char *)polygonEdges + v50) >> 15))
                                            + v15),
                        4));
      LODWORD(v50) = *((unsigned __int16 *)v55 + 7);
      v56 = *((unsigned __int16 *)v55 + 6);
      v57 = v55[1];
      v58 = v55[2];
      v54[1] = *v55;
      *(_QWORD *)&v95.a = v50;
      v96 = *(_QWORD *)(&v2 - 1);
      v54[2] = v57;
      v54[3] = v58;
      v54[4] = (float)*(__int64 *)(&v2 - 1) * (float)0.000015259022;
      v54 += 5;
      *v54 = (float)v50 * (float)0.000015259022;
      --v53;
    }
    while ( v53 != 0 );
  }
  numPolys = _R27->numPolys;
  v60 = 0;
  if ( numPolys == 0 )
  {
LABEL_14:
    if ( SHIDWORD(v15) > 0 )
    {
      v65 = HIDWORD(v15);
      v66 = v106;
      v67 = &v103;
      do
      {
        clipResult = _R27->clipResult;
        v69 = 0;
        *v67 = -1;
        numVerts = clipResult->numVerts;
        if ( clipResult->numVerts > 0 )
        {
          v71 = 0;
          while ( 1 )
          {
            v72 = (float *)((char *)&clipResult->numVerts + v71 * 12);
            if ( __fabs((float)(v66->x - clipResult->verts[v71].x)) <= 0.1
              && __fabs((float)(v66->y - v72[5])) <= 0.1
              && __fabs((float)(v66->z - v72[6])) <= 0.1 )
            {
              break;
            }
            ++v69;
            ++v71;
            if ( v69 >= numVerts )
              goto LABEL_27;
          }
          *v67 = v69;
        }
LABEL_27:
        if ( (unsigned __int16)*v67 == 0xFFFF && numVerts < 32 )
        {
          v74 = _R27->clipResult;
          x = v66->x;
          y = v66->y;
          z = v66->z;
          v78 = 3 * v74->numVerts;
          v79 = v74->numVerts++;
          *v67 = v79;
          v80 = (float *)(&v74->numVerts + v78);
          v80[4] = x;
          v80[5] = y;
          v80[6] = z;
        }
        ++v67;
        ++v66;
        --v65;
      }
      while ( v65 != 0 );
    }
    v81 = 0;
    if ( HIDWORD(v15) - 2 <= 0 )
      return 0;
    v82 = v103;
    for ( i = (__int16 *)&v104; ; ++i )
    {
      v84 = _R27->clipResult;
      numIndices = v84->numIndices;
      if ( numIndices + 3 >= 264 )
        return 0;
      v86 = *(i - 1);
      v87 = *i;
      if ( v82 != -1 && v86 != -1 && v87 != -1 )
      {
        v88 = 0;
        if ( numIndices > 0 )
        {
          v89 = 400;
          do
          {
            v90 = *(__int16 *)((char *)&v84->numVerts + v89);
            v91 = (char *)v84 + v89;
            if ( v82 == v90 )
            {
              if ( v86 == *((__int16 *)v91 + 1) )
              {
                v92 = *(__int16 *)((char *)&v84->numIndices + v89);
LABEL_47:
                v93 = v87 == v92;
LABEL_48:
                if ( v93 )
                  break;
              }
            }
            else
            {
              v92 = *((__int16 *)v91 + 1);
              if ( v82 == v92 )
              {
                if ( v86 == *(__int16 *)((char *)&v84->numIndices + v89) )
                {
                  v93 = v87 == v90;
                  goto LABEL_48;
                }
              }
              else if ( v82 == *(__int16 *)((char *)&v84->numIndices + v89) && v86 == v90 )
              {
                goto LABEL_47;
              }
            }
            v88 += 3;
            v89 += 6;
          }
          while ( v88 < numIndices );
        }
        if ( v88 >= numIndices )
        {
          _R27->clipResult->indices[_R27->clipResult->numIndices] = v82;
          _R27->clipResult->indices[_R27->clipResult->numIndices + 1] = v86;
          _R27->clipResult->indices[_R27->clipResult->numIndices + 2] = v87;
          _R27->clipResult->numIndices += 3;
        }
      }
      if ( ++v81 >= HIDWORD(v15) - 2 )
        return 0;
    }
  }
  p_c = &_R27->polys[0].plane.c;
  while ( 1 )
  {
    v62 = -*(p_c - 1);
    v63 = -*p_c;
    v64 = -p_c[1];
    v95.a = -*(p_c - 2);
    v95.b = v62;
    v95.c = v63;
    v95.d = v64;
    HIDWORD(v15) = idPolygonModelCollisionDetection::ClipInPlace(
                     points: v106,
                     numPoints: SHIDWORD(v15),
                     plane: &v95,
                     epsilon: 0.1,
                     keepOn: (const bool)polygonEdges,
                     a6: 0);
    if ( HIDWORD(v15) == 0 )
      return 0;
    ++v60;
    p_c += 16;
    if ( v60 >= numPolys )
      goto LABEL_14;
  }
}


// ========================================================================
// ?StartClip@idPolygonModelCollisionDetection@@SAXPAVidTraceWork@@PAUclipResult_t@@ABVidVec3@@PBVidTraceModel@@ABVidMat3@@H24@Z
// EA  : 0x825E7FE8
// RVA : 0x005E7FE8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_clip.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::StartClip(
        idTraceWork *tw,
        clipResult_t *result,
        const idVec3 *start,
        const idTraceModel *trm,
        const idMat3 *trmAxis,
        int contentMask,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis)
{
  bool v11; // r9
  double x; // fp2
  double y; // fp13
  double v17; // fp7
  double v18; // fp8
  double v19; // fp3
  double z; // fp10
  double v21; // fp4
  double v22; // fp5
  double v23; // fp6
  double v24; // fp3
  double v25; // fp2
  double v26; // fp9
  double v27; // fp8
  double v28; // fp0
  double v29; // fp13
  double v30; // fp6
  double v31; // fp1
  double v32; // fp10
  double v33; // fp11
  double v34; // fp4
  double v35; // fp5
  double v36; // fp7
  double v37; // fp2
  double v38; // fp1
  double v39; // fp13
  double v40; // fp11
  double v41; // fp10
  double v42; // fp9
  unsigned int numVerts; // r11
  unsigned int v44; // r9
  float *vertsZ; // r10
  float *p_z; // r11
  double v47; // fp31
  double v48; // fp0
  unsigned int v49; // r9
  double v50; // fp12
  double w; // fp3
  double v52; // fp3
  double v53; // fp12
  unsigned int numEdges; // r11
  _WORD *v55; // r10
  unsigned int *v56; // r11
  __int16 v57; // r7
  unsigned int numPolys; // r11
  unsigned int v59; // r5
  float *v60; // r9
  unsigned __int8 *v61; // r7
  float *p_b; // r11
  int v63; // r8
  unsigned int v64; // r10
  float *v65; // r8
  unsigned __int8 v66; // r4
  double v67; // fp12
  double v68; // fp3
  double v69; // fp1
  double v70; // fp0
  double v71; // fp2
  double v72; // fp1
  double v73; // fp0
  float *p_x; // r10
  idMat3x4 v84; // [sp+50h] [-80h] BYREF

  _R31 = tw;
  tw->contents = contentMask;
  tw->clipResult = result;
  tw->isConvex = true;
  tw->contactDepth = 0.0;
  tw->traceResult = nullptr;
  tw->fraction = 1.0;
  tw->traceType = TRACE_CLIP;
  tw->quickExit = false;
  tw->contactsResult = nullptr;
  _R30 = &tw->start;
  _R28 = &tw->trmBoundsMin;
  _R27 = &tw->trmBoundsMax;
  x = start->x;
  y = start->y;
  v17 = (float)((float)(trm->offset.z * trmAxis->mat[2].x)
              + (float)((float)(trmAxis->mat[1].x * trm->offset.y) + (float)(trmAxis->mat[0].x * trm->offset.x)));
  v18 = modelOrigin->y;
  v19 = (float)((float)(trmAxis->mat[2].z * trm->offset.z)
              + (float)((float)(trmAxis->mat[0].z * trm->offset.x) + (float)(trmAxis->mat[1].z * trm->offset.y)));
  z = start->z;
  v21 = modelOrigin->x;
  v22 = (float)((float)(trm->offset.z * trmAxis->mat[2].y)
              + (float)((float)(trmAxis->mat[0].y * trm->offset.x) + (float)(trm->offset.y * trmAxis->mat[1].y)));
  v23 = modelOrigin->z;
  tw->start.w = 0.0;
  tw->start.y = (float)((float)y + (float)v22) - (float)v18;
  tw->start.x = (float)((float)x + (float)v17) - (float)v21;
  tw->start.z = (float)((float)z + (float)v19) - (float)v23;
  tw->end.x = (float)((float)x + (float)v17) - (float)v21;
  tw->end.y = tw->start.y;
  tw->end.z = tw->start.z;
  tw->end.w = tw->start.w;
  tw->dir.w = 0.0;
  tw->dir.z = 0.0;
  tw->dir.y = 0.0;
  tw->dir.x = 0.0;
  tw->isConvex = trm->isConvex;
  tw->trmBoundsMin.x = 1.0e30;
  tw->trmBoundsMin.y = 1.0e30;
  tw->trmBoundsMin.z = 1.0e30;
  tw->trmBoundsMin.w = 0.0;
  tw->trmBoundsMax.w = 0.0;
  tw->trmBoundsMax.x = -1.0e30;
  tw->trmBoundsMax.y = -1.0e30;
  tw->trmBoundsMax.z = -1.0e30;
  v24 = (float)(start->z - modelOrigin->z);
  v25 = (float)(start->y - modelOrigin->y);
  v26 = trmAxis->mat[2].y;
  v27 = trmAxis->mat[1].y;
  v28 = modelAxis->mat[0].x;
  v29 = trmAxis->mat[2].z;
  v30 = trmAxis->mat[2].x;
  v31 = (float)(start->x - modelOrigin->x);
  v11 = true;
  v32 = trmAxis->mat[0].z;
  v33 = trmAxis->mat[1].z;
  v34 = trmAxis->mat[0].x;
  v35 = trmAxis->mat[1].x;
  v36 = trmAxis->mat[0].y;
  v84.mat[5] = trmAxis->mat[1].y;
  v84.mat[6] = v26;
  v84.mat[8] = v32;
  v84.mat[9] = v33;
  v84.mat[10] = v29;
  v84.mat[3] = v31;
  v84.mat[0] = v34;
  v84.mat[7] = v25;
  v84.mat[1] = v35;
  v84.mat[11] = v24;
  v84.mat[2] = v30;
  v84.mat[4] = v36;
  if ( v28 == 1.0 && modelAxis->mat[1].y == 1.0 )
    v11 = modelAxis->mat[2].z != 1.0;
  if ( v11 )
  {
    v37 = _R30->x;
    v38 = modelAxis->mat[1].x;
    v39 = modelAxis->mat[2].x;
    v40 = (float)((float)(modelAxis->mat[1].y * tw->start.y) + (float)(modelAxis->mat[1].z * tw->start.z));
    v41 = (float)((float)(modelAxis->mat[2].y * tw->start.y) + (float)(modelAxis->mat[2].z * tw->start.z));
    v42 = (float)((float)(tw->start.x * (float)v28)
                + (float)((float)(modelAxis->mat[0].y * tw->start.y) + (float)(modelAxis->mat[0].z * tw->start.z)));
    tw->start.x = (float)(tw->start.x * (float)v28)
                + (float)((float)(modelAxis->mat[0].y * tw->start.y) + (float)(modelAxis->mat[0].z * tw->start.z));
    tw->start.y = (float)((float)v38 * (float)v37) + (float)v40;
    tw->start.z = (float)((float)v39 * (float)v37) + (float)v41;
    tw->end.x = v42;
    tw->end.y = tw->start.y;
    tw->end.z = tw->start.z;
    idMat3x4::LeftTransposeMultiply(this: &v84, m: modelAxis);
    v24 = v84.mat[11];
    v29 = v84.mat[10];
    v33 = v84.mat[9];
    v32 = v84.mat[8];
    v25 = v84.mat[7];
    v26 = v84.mat[6];
    v27 = v84.mat[5];
    v36 = v84.mat[4];
    v31 = v84.mat[3];
    v30 = v84.mat[2];
    v35 = v84.mat[1];
    v34 = v84.mat[0];
  }
  numVerts = trm->numVerts;
  v44 = 0;
  _R31->numVerts = numVerts;
  if ( numVerts != 0 )
  {
    vertsZ = trm->vertsZ;
    p_z = &_R31->vertexPosition[0].z;
    do
    {
      v47 = (float)((float)(*(vertsZ - 32) * (float)v27)
                  + (float)((float)((float)v36 * *(vertsZ - 64)) + (float)(*vertsZ * (float)v26)));
      v48 = (float)((float)(*(vertsZ - 32) * (float)v33)
                  + (float)((float)((float)v32 * *(vertsZ - 64)) + (float)(*vertsZ * (float)v29)));
      *(p_z - 2) = (float)((float)(*(vertsZ - 32) * (float)v35)
                         + (float)((float)(*(vertsZ - 64) * (float)v34) + (float)(*vertsZ * (float)v30)))
                 + (float)v31;
      *(p_z - 1) = (float)v47 + (float)v25;
      *p_z = (float)v48 + (float)v24;
      if ( *(p_z - 2) < (double)_R28->x )
        _R28->x = *(p_z - 2);
      if ( *(p_z - 1) < (double)_R28->y )
        _R28->y = *(p_z - 1);
      if ( *p_z < (double)_R28->z )
        _R28->z = *p_z;
      if ( *(p_z - 2) > (double)_R27->x )
        _R27->x = *(p_z - 2);
      if ( *(p_z - 1) > (double)_R27->y )
        _R27->y = *(p_z - 1);
      if ( *p_z > (double)_R27->z )
        _R27->z = *p_z;
      ++v44;
      p_z += 4;
      ++vertsZ;
    }
    while ( v44 < _R31->numVerts );
  }
  v49 = 0;
  _R28->x = _R28->x - _R30->x;
  v50 = _R28->z;
  w = _R28->w;
  _R28->y = _R28->y - _R30->y;
  _R28->z = (float)v50 - _R30->z;
  _R28->w = (float)w - _R30->w;
  _R27->x = _R27->x - _R30->x;
  v52 = _R27->w;
  v53 = _R27->z;
  _R27->y = _R27->y - _R30->y;
  _R27->z = (float)v53 - _R30->z;
  _R27->w = (float)v52 - _R30->w;
  numEdges = trm->numEdges;
  _R31->numEdges = numEdges;
  if ( numEdges != 0 )
  {
    v55 = (_WORD *)&_R31->verts[31].pad + 1;
    v56 = &trm->numPolyEdges[15];
    do
    {
      v57 = *((_WORD *)v56 + 3);
      ++v49;
      v55[7] = *(_WORD *)++v56;
      v55 += 8;
      *v55 = v57;
    }
    while ( v49 < _R31->numEdges );
  }
  numPolys = trm->numPolys;
  v59 = 0;
  _R31->numPolys = numPolys;
  if ( numPolys != 0 )
  {
    v60 = &trm->polyPlaneY[15];
    v61 = trm->polyEdges[0];
    p_b = &_R31->polys[0].plane.b;
    do
    {
      v63 = *((_DWORD *)v60 + 97);
      v64 = 0;
      *((_DWORD *)p_b + 6) = v63;
      if ( v63 != 0 )
      {
        v65 = p_b - 257;
        do
        {
          v66 = v61[v64++];
          *((_BYTE *)v65 + 1056) = v66;
          v65 = (float *)((char *)p_b + v64 - 1028);
        }
        while ( v64 < *((_DWORD *)p_b + 6) );
      }
      v67 = *(v60 - 31);
      ++v59;
      v68 = *(v60 - 15);
      v61 += 16;
      v69 = (float)((float)(*++v60 * (float)v29) + (float)((float)v68 * (float)v33));
      v70 = (float)((float)((float)v67 * (float)v34) + (float)(*v60 * (float)v30));
      v71 = (float)((float)((float)v36 * (float)v67)
                  + (float)((float)(*v60 * (float)v26) + (float)((float)v68 * (float)v27)));
      *p_b = (float)((float)v36 * (float)v67) + (float)((float)(*v60 * (float)v26) + (float)((float)v68 * (float)v27));
      v72 = (float)((float)((float)v32 * (float)v67) + (float)v69);
      p_b[1] = v72;
      v73 = (float)((float)((float)v68 * (float)v35) + (float)v70);
      *(p_b - 1) = v73;
      p_x = &_R31->vertexPosition[_R31->edges[(_BYTE)p_b[7] & 0x7F].vertexNum[0]].x;
      p_b[2] = -(float)((float)((float)v73 * *p_x) + (float)((float)((float)v72 * p_x[2]) + (float)(p_x[1] * (float)v71)));
      p_b += 16;
    }
    while ( v59 < _R31->numPolys );
  }
  __asm { lvx128    v63, r0, r30 }
  __asm { lvx128    v61, r0, r28 }
  _R10 = -48;
  __asm
  {
    lvx128    v60, r0, r27
    vaddfp128 v59, v95, v61
    vaddfp128 v58, v95, v60
  }
  _R9 = vmxi_float_abs_mask_1;
  _R8 = -32;
  _R7 = 6144;
  _R6 = 6160;
  _R5 = 16;
  __asm { lvx128    v63, r9, r10 }
  _R4 = 32;
  __asm { lvx128    v62, r9, r8 }
  _R3 = 6176;
  _R11 = 6128;
  __asm
  {
    vsubfp128 v57, v91, v63
    vaddfp128 v56, v90, v63
    vaddfp128 v55, v89, v62
    stvx128   v57, r31, r7
    vsubfp128 v54, v88, v62
    stvx128   v56, r31, r6
    vcfpsxws128 v13, v55, 0
    vcfpsxws128 v12, v54, 0
    lvx128    v0, r9, r5
    lvx128    v7, r9, r4
    vsubsws   v11, v13, v0
    vaddsws   v10, v12, v0
    vpkswss128 v62, v11, v10
    vperm128  v53, v94, v62, v7
    stvx128   v53, r31, r3
    lvx128    v62, r0, r9
    vand128   v52, v92, v62
    vand128   v51, v93, v62
    vmaxfp128 v50, v83, v52
    vaddfp128 v49, v82, v63
    stvx128   v49, r31, r11
  }
}


// ========================================================================
// ?FinishClip@idPolygonModelCollisionDetection@@SAXPAVidTraceWork@@HABVidVec3@@ABVidMat3@@@Z
// EA  : 0x825E8608
// RVA : 0x005E8608
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_clip.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::FinishClip(
        idTraceWork *tw,
        int firstClipVert,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis)
{
  int v4; // r9
  char v5; // r11
  clipResult_t *clipResult; // r7
  int v7; // r8
  int v8; // r10
  float *v9; // r11
  double x; // fp8
  double y; // fp3
  double v12; // fp1
  double z; // fp0
  double v14; // fp12
  double v15; // fp11
  clipResult_t *v16; // r8
  int v17; // r10
  float *v18; // r11
  double v19; // fp11
  double v20; // fp8

  v4 = firstClipVert;
  if ( modelAxis->mat[0].x != 1.0 || modelAxis->mat[1].y != 1.0 || (v5 = 0, modelAxis->mat[2].z != 1.0) )
    v5 = 1;
  if ( v5 != 0 )
  {
    clipResult = tw->clipResult;
    v7 = firstClipVert;
    if ( firstClipVert < clipResult->numVerts )
    {
      v8 = firstClipVert;
      do
      {
        v9 = (float *)((char *)&clipResult->numVerts + v8 * 12);
        ++v7;
        x = clipResult->verts[v8].x;
        y = clipResult->verts[v8].y;
        v12 = modelAxis->mat[1].y;
        z = modelAxis->mat[0].z;
        v14 = (float)((float)(modelAxis->mat[2].y * clipResult->verts[v8].z)
                    + (float)(modelAxis->mat[0].y * clipResult->verts[v8].x));
        v15 = (float)((float)(clipResult->verts[v8].y * modelAxis->mat[1].z)
                    + (float)(modelAxis->mat[2].z * clipResult->verts[v8].z));
        v9[4] = (float)(modelAxis->mat[1].x * clipResult->verts[v8].y)
              + (float)((float)(clipResult->verts[v8].x * modelAxis->mat[0].x)
                      + (float)(modelAxis->mat[2].x * clipResult->verts[v8].z));
        ++v8;
        v9[5] = (float)((float)y * (float)v12) + (float)v14;
        v9[6] = (float)((float)z * (float)x) + (float)v15;
      }
      while ( v7 < clipResult->numVerts );
    }
  }
  if ( ((LODWORD(modelOrigin->y) | LODWORD(modelOrigin->z) | LODWORD(modelOrigin->x)) & 0x7FFFFFFF) != 0 )
  {
    v16 = tw->clipResult;
    if ( firstClipVert < v16->numVerts )
    {
      v17 = firstClipVert;
      do
      {
        v18 = (float *)((char *)&v16->numVerts + v17 * 12);
        ++v4;
        v19 = v16->verts[v17].y;
        v18[4] = v16->verts[v17].x + modelOrigin->x;
        v20 = v16->verts[v17++].z;
        v18[5] = (float)v19 + modelOrigin->y;
        v18[6] = modelOrigin->z + (float)v20;
      }
      while ( v4 < v16->numVerts );
    }
  }
}

