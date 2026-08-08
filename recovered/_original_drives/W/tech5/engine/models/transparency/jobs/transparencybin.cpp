
// ========================================================================
// ?SplitPolygon@@YAHABUpolygon_t@@ABVidPlane@@MPAVidTransparencyVert@@AAHAAU1@4@Z
// EA  : 0x82889DB8
// RVA : 0x00889DB8
// PDB : w:\tech5\engine\models\transparency\jobs\transparencybin.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall SplitPolygon(
        const polygon_t *polygon,
        const idPlane *plane,
        double epsilon,
        idTransparencyVert *binVerts,
        int *numBinVerts,
        polygon_t *front,
        polygon_t *back,
        _WORD *a8)
{
  unsigned int numPoints; // r23
  signed int v9; // r31
  double c; // fp0
  float *v11; // r10
  double b; // fp13
  char *v13; // r5
  double a; // fp11
  double d; // fp10
  double v16; // fp12
  unsigned __int16 *p_numPoints; // r11
  int v18; // r27
  float *v19; // r30
  int v20; // r25
  double v21; // fp4
  double v22; // fp7
  double v23; // fp6
  double v24; // fp5
  double v25; // fp7
  int v26; // r30
  int v27; // r19
  int v28; // r25
  float *v29; // r30
  double v30; // fp2
  double v31; // fp9
  double v32; // fp8
  int v33; // r30
  int v34; // r28
  int v35; // r28
  double v36; // fp0
  double v37; // fp13
  double v38; // fp12
  double v39; // fp11
  double v40; // fp10
  float *v41; // r4
  unsigned __int16 *v42; // r5
  unsigned int v43; // ctr
  float *v44; // r11
  double v45; // fp3
  int v46; // r11
  int v47; // r11
  int v48; // r31
  double v49; // fp0
  bool v50; // cr58
  int v51; // r11
  int v53; // r29
  float *v54; // r30 OVERLAPPED
  const polygon_t *v55; // r28
  __int64 v56; // r5
  char *v57; // r5
  int v58; // r11
  int v59; // r10
  int v60; // r31
  signed int v61; // r31
  int v62; // r5
  double v63; // fp0
  double v64; // fp13
  int v65; // r10
  int v66; // r10
  int *v67; // r11
  float v68; // r26
  int *v69; // r10
  float v70; // r25
  __int128 v71; // r26
  double v72; // fp0
  float v73; // r31
  double v74; // fp12
  double v75; // fp2
  double v76; // fp3
  int v77; // r31
  int v78; // r31
  int v79; // r31
  __int64 v80; // [sp+58h] [-148h] BYREF
  int v81; // [sp+60h] [-140h]
  int v83; // [sp+6Ch] [-134h]
  float v84; // [sp+70h] [-130h]
  int v85; // [sp+74h] [-12Ch]
  float v86; // [sp+78h] [-128h]
  float v87; // [sp+80h] [-120h]
  float v88; // [sp+84h] [-11Ch]
  float v89; // [sp+88h] [-118h]
  char v90; // [sp+8Fh] [-111h] BYREF
  char v91; // [sp+90h] [-110h] BYREF
  __int64 v92; // [sp+A8h] [-F8h]
  __int64 v93; // [sp+B0h] [-F0h]
  __int64 v94; // [sp+B8h] [-E8h]
  __int64 v95; // [sp+C0h] [-E0h]
  __int64 v96; // [sp+C8h] [-D8h]
  __int64 v97; // [sp+D0h] [-D0h]
  char v98; // [sp+DCh] [-C4h] BYREF
  float v99; // [sp+E0h] [-C0h] BYREF
  char v100; // [sp+E4h] [-BCh] BYREF

  numPoints = polygon->numPoints;
  v80 = 0;
  v9 = 0;
  v81 = 0;
  if ( numPoints >= 4 )
  {
    c = plane->c;
    v11 = (float *)&v98;
    b = plane->b;
    v13 = &v90;
    a = plane->a;
    d = plane->d;
    v16 = -epsilon;
    p_numPoints = &polygon[-1].numPoints;
    do
    {
      v18 = __ROL4__(p_numPoints[2], 5);
      v19 = (float *)((char *)numBinVerts + __ROL4__(p_numPoints[1], 5));
      v20 = __ROL4__(p_numPoints[3], 5);
      v21 = *(float *)((char *)numBinVerts + v20);
      v22 = (float)((float)(*(float *)((char *)numBinVerts + v20 + 4) * (float)b)
                  + (float)(*(float *)((char *)numBinVerts + v20 + 8) * (float)c));
      v23 = (float)((float)((float)a * *(float *)((char *)numBinVerts + v18))
                  + (float)((float)(*(float *)((char *)numBinVerts + v18 + 4) * (float)b)
                          + (float)(*(float *)((char *)numBinVerts + v18 + 8) * (float)c)));
      v24 = (float)((float)((float)((float)a * *v19) + (float)((float)(v19[1] * (float)b) + (float)(v19[2] * (float)c)))
                  + (float)d);
      v11[1] = (float)((float)((float)a * *v19) + (float)((float)(v19[1] * (float)b) + (float)(v19[2] * (float)c)))
             + (float)d;
      v11[2] = (float)v23 + (float)d;
      v25 = (float)((float)((float)((float)a * (float)v21) + (float)v22) + (float)d);
      v11[3] = v25;
      LOBYTE(v20) = COERCE_INT((float)v16 - (float)((float)v23 + (float)d)) >= 0;
      v26 = 4
          * (unsigned __int8)((2
                             * ((COERCE_INT((float)epsilon - (float)v24) >= 0)
                              ^ (COERCE_INT((float)v16 - (float)v24) >= 0)))
                            | (COERCE_INT((float)v16 - (float)v24) >= 0));
      v13[1] = (2 * ((COERCE_INT((float)epsilon - (float)v24) >= 0) ^ (COERCE_INT((float)v16 - (float)v24) >= 0)))
             | (COERCE_INT((float)v16 - (float)v24) >= 0);
      v27 = (unsigned __int8)((2 * ((COERCE_INT((float)epsilon - (float)((float)v23 + (float)d)) >= 0) ^ v20)) | v20);
      v28 = *(_DWORD *)((char *)&v80 + v26) + 1;
      v13[2] = v27;
      *(_DWORD *)((char *)&v80 + v26) = v28;
      p_numPoints += 4;
      v29 = (float *)((char *)numBinVerts + __ROL4__(*p_numPoints, 5));
      ++*(_DWORD *)((char *)&v80 + ((4 * v27) & 0x3C));
      v30 = (float)(v29[2] * (float)c);
      v31 = v29[1];
      v32 = *v29;
      v9 += 4;
      v33 = 4
          * (unsigned __int8)((2
                             * ((COERCE_INT((float)epsilon - (float)v25) >= 0)
                              ^ (COERCE_INT((float)v16 - (float)v25) >= 0)))
                            | (COERCE_INT((float)v16 - (float)v25) >= 0));
      v13[3] = (2 * ((COERCE_INT((float)epsilon - (float)v25) >= 0) ^ (COERCE_INT((float)v16 - (float)v25) >= 0)))
             | (COERCE_INT((float)v16 - (float)v25) >= 0);
      v34 = *(_DWORD *)((char *)&v80 + v33);
      v11 += 4;
      *v11 = (float)((float)((float)a * (float)v32) + (float)((float)((float)v31 * (float)b) + (float)v30)) + (float)d;
      LOBYTE(v18) = COERCE_INT(
                      (float)v16
                    - (float)((float)((float)((float)a * (float)v32)
                                    + (float)((float)((float)v31 * (float)b) + (float)v30))
                            + (float)d)) >= 0;
      *(_DWORD *)((char *)&v80 + v33) = v34 + 1;
      v35 = (unsigned __int8)((2
                             * ((COERCE_INT(
                                   (float)epsilon
                                 - (float)((float)((float)((float)a * (float)v32)
                                                 + (float)((float)((float)v31 * (float)b) + (float)v30))
                                         + (float)d)) >= 0)
                              ^ v18))
                            | v18);
      v13 += 4;
      *v13 = v35;
      ++*(_DWORD *)((char *)&v80 + ((4 * v35) & 0x3C));
    }
    while ( v9 < (int)(numPoints - 3) );
  }
  if ( v9 < (int)numPoints )
  {
    v36 = plane->c;
    v37 = plane->b;
    v38 = plane->a;
    v39 = plane->d;
    v40 = -epsilon;
    v41 = &v99 + v9 - 1;
    v42 = &polygon->points[v9 - 1];
    v43 = numPoints - v9;
    do
    {
      v44 = (float *)((char *)numBinVerts + __ROL4__(*++v42, 5));
      v45 = (float)((float)((float)((float)v38 * *v44)
                          + (float)((float)(v44[1] * (float)v37) + (float)(v44[2] * (float)v36)))
                  + (float)v39);
      *++v41 = (float)((float)((float)v38 * *v44) + (float)((float)(v44[1] * (float)v37) + (float)(v44[2] * (float)v36)))
             + (float)v39;
      v46 = 4
          * (unsigned __int8)((2
                             * ((COERCE_INT((float)epsilon - (float)v45) >= 0)
                              ^ (COERCE_INT((float)v40 - (float)v45) >= 0)))
                            | (COERCE_INT((float)v40 - (float)v45) >= 0));
      *(&v91 + v9++) = (2 * ((COERCE_INT((float)epsilon - (float)v45) >= 0) ^ (COERCE_INT((float)v40 - (float)v45) >= 0)))
                     | (COERCE_INT((float)v40 - (float)v45) >= 0);
      ++*(_DWORD *)((char *)&v80 + v46);
      --v43;
    }
    while ( v43 != 0 );
  }
  v47 = polygon->numPoints;
  v48 = __ROL4__(v47, 2);
  v49 = v99;
  v50 = HIDWORD(v80) == 0;
  *(&v91 + v47) = v91;
  v51 = v80;
  *(float *)((char *)&v99 + v48) = v49;
  if ( v50 )
  {
    if ( v51 != 0 )
    {
      memcpy(Dst: a8, Src: polygon, Size: 0x20u);
      return 1;
    }
    else
    {
      return 2;
    }
  }
  else if ( v51 != 0 )
  {
    back->numPoints = 0;
    v53 = 0;
    a8[15] = 0;
    if ( polygon->numPoints != 0 )
    {
      v54 = (float *)&v100;
      v55 = polygon;
      HIDWORD(v56) = 0xFFFF;
      do
      {
        v57 = &v91 + v53;
        v58 = v55->points[0];
        v59 = (unsigned __int8)*(&v91 + v53);
        if ( v59 == 2 )
        {
          *(unsigned __int16 *)((char *)back->points + __ROL4__(back->numPoints++, 1)) = v58;
          *(_WORD *)((char *)a8 + __ROL4__((unsigned __int16)a8[15]++, 1)) = v58;
        }
        else
        {
          if ( *(&v91 + v53) != 0 )
          {
            if ( v59 == 1 )
              *(_WORD *)((char *)a8 + __ROL4__((unsigned __int16)a8[15]++, 1)) = v58;
          }
          else
          {
            *(unsigned __int16 *)((char *)back->points + __ROL4__(back->numPoints++, 1)) = v58;
          }
          v60 = (unsigned __int8)v57[1];
          if ( v60 != 2 && v60 != v59 )
          {
            v61 = polygon->numPoints;
            v62 = (int)&v57[1 - (_DWORD)&v91];
            __twllei(v61, 0);
            __twlgei(v61 & ~(__ROL4__(v62, 1) - 1), 0xFFFFFFFF);
            LODWORD(v56) = polygon->points[v62 % v61];
            if ( v59 != 0 )
            {
              v65 = v58;
              v63 = *v54;
              v58 = v56;
              v64 = *(v54 - 1);
              LODWORD(v56) = v65;
            }
            else
            {
              v63 = *(v54 - 1);
              v64 = *v54;
            }
            v66 = *(_DWORD *)front->points;
            LODWORD(v56) = &numBinVerts[8 * v56];
            v67 = &numBinVerts[8 * v58];
            ++*(_DWORD *)front->points;
            v68 = *(float *)(v56 + 8);
            v69 = &numBinVerts[8 * v66];
            v70 = *(float *)(v56 + 4);
            DWORD1(v71) = v67[1];
            v84 = *(float *)v67;
            v72 = (float)((float)v63 / (float)((float)v63 - (float)v64));
            v73 = *((float *)v67 + 2);
            v74 = v84;
            v89 = v68;
            v85 = DWORD1(v71);
            v88 = v70;
            v87 = *(float *)v56;
            v86 = v73;
            v75 = (float)((float)(v70 - *((float *)&v71 + 1)) * (float)v72);
            *((float *)&v71 + 2) = v87;
            v76 = (float)((float)(v87 - v84) * (float)v72);
            *((float *)v69 + 2) = (float)((float)(v68 - v73) * (float)v72) + v73;
            *((float *)v69 + 1) = (float)v75 + *((float *)&v71 + 1);
            *(float *)v69 = (float)v76 + (float)v74;
            v77 = *((__int16 *)v67 + 6);
            LODWORD(v71) = *(__int16 *)(v56 + 12) - v77;
            v96 = v71;
            v83 = (int)(float)((float)((float)(__int64)v71 * (float)v72) + (float)*(__int64 *)(&v54 - 1));
            *((_WORD *)v69 + 6) = v83;
            v78 = *((__int16 *)v67 + 7);
            LODWORD(v71) = *(__int16 *)(v56 + 14) - v78;
            v95 = *(_QWORD *)(&v54 - 1);
            v93 = v71;
            v83 = (int)(float)((float)((float)(__int64)v71 * (float)v72) + (float)*(__int64 *)(&v54 - 1));
            *((_WORD *)v69 + 7) = v83;
            DWORD2(v71) = *((__int16 *)v67 + 8);
            v79 = *(__int16 *)(v56 + 16) - DWORD2(v71);
            v94 = *(_QWORD *)((char *)&v71 + 4);
            v92 = *(_QWORD *)(&v54 - 1);
            v83 = (int)(float)((float)((float)*(__int64 *)(&v54 - 1) * (float)v72)
                             + (float)*(__int64 *)((char *)&v71 + 4));
            *((_WORD *)v69 + 8) = v83;
            LODWORD(v56) = *(__int16 *)(v56 + 18) - *((__int16 *)v67 + 9);
            LODWORD(v71) = *((__int16 *)v67 + 9);
            v97 = v71;
            v80 = v56;
            v83 = (int)(float)((float)((float)v56 * (float)v72) + (float)(__int64)v71);
            *((_WORD *)v69 + 9) = v83;
            v69[5] = v67[5];
            v69[6] = v67[6];
            v69[7] = v67[7];
            *(unsigned __int16 *)((char *)back->points + __ROL4__(back->numPoints++, 1)) = *(_DWORD *)front->points - 1;
            *(_WORD *)((char *)a8 + __ROL4__((unsigned __int16)a8[15]++, 1)) = front->points[0] - 1;
          }
        }
        ++v53;
        v55 = (const polygon_t *)((char *)v55 + 2);
        ++v54;
      }
      while ( v53 < polygon->numPoints );
    }
    return 3;
  }
  else
  {
    *back = *polygon;
    return 0;
  }
}


// ========================================================================
// ?BinPolygon_r@@YAXPAUdeferredTransparencyBinParms_t@@HABUpolygon_t@@@Z
// EA  : 0x8288A4F0
// RVA : 0x0088A4F0
// PDB : w:\tech5\engine\models\transparency\jobs\transparencybin.cpp
// ========================================================================

void __fastcall BinPolygon_r(deferredTransparencyBinParms_t *parms, int nodeNum, polygon_t *polygon)
{
  int v4; // r9
  bin_t *v5; // r11
  unsigned __int16 *v6; // r8
  int numIndices; // r10
  int v8; // r7
  unsigned int v9; // r10
  unsigned __int16 *v10; // r10
  int v11; // r6
  node_t *v12; // r30
  int v13; // r3
  int v14; // r4
  const polygon_t *v15; // r5
  polygon_t v16; // [sp+50h] [-60h] BYREF
  _WORD v17[20]; // [sp+70h] [-40h] BYREF

  if ( nodeNum >= 0 )
  {
    v12 = &parms->nodes[nodeNum];
    v13 = SplitPolygon(
            polygon,
            plane: &v12->plane,
            epsilon: 0.1,
            binVerts: (idTransparencyVert *)polygon,
            numBinVerts: (int *)parms->tempBinVerts,
            front: (polygon_t *)&parms->numBinVerts,
            back: &v16,
            a8: v17);
    switch ( v13 )
    {
      case 3:
        BinPolygon_r(parms, nodeNum: v12->children[0], polygon: &v16);
        v14 = v12->children[1];
        break;
      case 0:
        v15 = &v16;
        v14 = v12->children[0];
LABEL_14:
        BinPolygon_r(parms, nodeNum: v14, polygon: v15);
        return;
      case 1:
        v14 = v12->children[1];
        break;
      default:
        return;
    }
    v15 = (const polygon_t *)v17;
    goto LABEL_14;
  }
  if ( nodeNum != -1 )
  {
    v4 = 2;
    v5 = &parms->bins[-nodeNum - 2];
    if ( polygon->numPoints > 2u )
    {
      v6 = &polygon->points[1];
      do
      {
        numIndices = v5->numIndices;
        ++v4;
        v8 = ((unsigned __int64)(numIndices * (__int64)(int)"n graph") >> 32) + numIndices;
        v9 = numIndices - 126 * ((v8 >> 6) + ((unsigned int)v8 >> 31));
        v11 = v9 + 2;
        v10 = &v5->indices[v9];
        *v10 = polygon->points[0];
        v10[1] = *v6++;
        v5->indices[v11] = *v6;
        v5->numIndices += 3;
      }
      while ( v4 < polygon->numPoints );
    }
  }
}


// ========================================================================
// ?BuildBinTree_r@@YAHPAUdeferredTransparencyBinParms_t@@PBVidVec3@@HHHH@Z
// EA  : 0x8288A658
// RVA : 0x0088A658
// PDB : w:\tech5\engine\models\transparency\jobs\transparencybin.cpp
// ========================================================================

int __fastcall BuildBinTree_r(
        deferredTransparencyBinParms_t *parms,
        const idVec3 *screenVerts,
        int offsetX,
        int partitionsX,
        int offsetY,
        int partitionsY)
{
  double v12; // fp13
  int v13; // r24
  double v14; // fp7
  double v15; // fp11
  int v16; // r27
  double v17; // fp4
  double v18; // fp12
  int v19; // r22
  __int64 v20; // r9
  double v21; // fp6
  double v22; // fp5
  double v23; // fp3
  double v24; // fp9
  node_t *v25; // r23
  double z; // fp11
  int v28; // r24
  double x; // fp13
  double v30; // fp4
  double v31; // fp2
  int numNodes; // r27
  double y; // fp12
  double v34; // fp7
  __int64 v35; // r9
  double v36; // fp10
  double v37; // fp9
  double v38; // fp1
  node_t *v39; // r23
  int v40; // r11
  idVec3 v41; // [sp+50h] [-90h] BYREF
  idVec3 v42; // [sp+60h] [-80h] BYREF
  idVec3 v43; // [sp+70h] [-70h] BYREF

  if ( partitionsX <= 1 )
  {
    if ( partitionsY <= 1 )
    {
      v40 = ((1280 * (offsetY / 16)) >> 5) + offsetX / 32;
      parms->bins[v40].numIndices = 0;
      return -2 - v40;
    }
    else
    {
      z = screenVerts->z;
      v28 = partitionsY / 2;
      x = screenVerts->x;
      v30 = (float)(screenVerts[2].z - screenVerts->z);
      v31 = (float)(screenVerts[1].x - screenVerts->x);
      numNodes = parms->numNodes;
      y = screenVerts->y;
      v34 = (float)(screenVerts[2].x - screenVerts->x);
      LODWORD(v35) = 16 * (partitionsY / 2) + offsetY;
      v36 = (float)(screenVerts[1].y - screenVerts->y);
      v37 = screenVerts[2].y;
      HIDWORD(v35) = numNodes + 1;
      *(_QWORD *)&v41.x = v35;
      v38 = screenVerts[1].z;
      parms->numNodes = numNodes + 1;
      v39 = &parms->nodes[numNodes];
      v42.x = (float)x + (float)((float)v34 * (float)((float)v35 * (float)0.0013888889));
      v42.y = (float)y + (float)((float)((float)v37 - (float)y) * (float)((float)v35 * (float)0.0013888889));
      v42.z = (float)z + (float)((float)v30 * (float)((float)v35 * (float)0.0013888889));
      v43.x = (float)v31 + v42.x;
      v43.y = (float)v36 + v42.y;
      v43.z = (float)((float)v38 - (float)z) + v42.z;
      idPlane::FromPoints(this: &v39->plane, p1: &parms->viewOrigin, p2: &v43, p3: &v42, fixDegenerate: true);
      v39->children[0] = BuildBinTree_r(
                           parms,
                           screenVerts,
                           offsetX,
                           partitionsX,
                           offsetY: 16 * (partitionsY / 2) + offsetY,
                           partitionsY: partitionsY - v28);
      v39->children[1] = BuildBinTree_r(parms, screenVerts, offsetX, partitionsX, offsetY, partitionsY: partitionsY / 2);
      return numNodes;
    }
  }
  else
  {
    v12 = screenVerts->x;
    v13 = partitionsX / 2;
    v14 = (float)(screenVerts[1].x - screenVerts->x);
    v15 = screenVerts->z;
    v16 = parms->numNodes;
    v17 = (float)(screenVerts[1].z - screenVerts->z);
    v18 = screenVerts->y;
    v19 = 32 * (partitionsX / 2) + offsetX;
    HIDWORD(v20) = v16 + 1;
    LODWORD(v20) = v19;
    v21 = (float)(screenVerts[1].y - screenVerts->y);
    v22 = screenVerts[2].x;
    *(_QWORD *)&v41.x = v20;
    v23 = screenVerts[2].y;
    v24 = screenVerts[2].z;
    parms->numNodes = v16 + 1;
    v25 = &parms->nodes[v16];
    v41.x = (float)v12 + (float)((float)v14 * (float)((float)v20 * (float)0.00078125001));
    v41.y = (float)v18 + (float)((float)v21 * (float)((float)v20 * (float)0.00078125001));
    v41.z = (float)v15 + (float)((float)((float)v20 * (float)0.00078125001) * (float)v17);
    v42.x = (float)((float)v22 - (float)v12) + v41.x;
    v42.y = (float)((float)v23 - (float)v18) + v41.y;
    v42.z = (float)((float)v24 - (float)v15) + v41.z;
    idPlane::FromPoints(this: &v25->plane, p1: &parms->viewOrigin, p2: &v41, p3: &v42, fixDegenerate: true);
    v25->children[0] = BuildBinTree_r(
                         parms,
                         screenVerts,
                         offsetX: v19,
                         partitionsX: partitionsX - v13,
                         offsetY,
                         partitionsY);
    v25->children[1] = BuildBinTree_r(parms, screenVerts, offsetX, partitionsX: v13, offsetY, partitionsY);
    return v16;
  }
}


// ========================================================================
// ?BinQuads@@YAXPAUdeferredTransparencyBinParms_t@@@Z
// EA  : 0x8288A938
// RVA : 0x0088A938
// PDB : w:\tech5\engine\models\transparency\jobs\transparencybin.cpp
// ========================================================================

void __fastcall BinQuads(deferredTransparencyBinParms_t *parms)
{
  int numNodes; // r11
  double y; // fp7
  double v3; // fp8
  double x; // fp3
  double v5; // fp4
  double v6; // fp9
  double v7; // fp6
  double v8; // fp1
  double v9; // fp2
  double v10; // fp11
  double z; // fp5
  double v12; // fp13
  double v13; // fp10
  idVec3 *p_viewOrigin; // r30
  double v15; // fp0
  node_t *v16; // r29
  double v17; // fp12
  int v19; // r3
  node_t *nodes; // r9
  int v21; // r11
  node_t *v22; // r29
  int v23; // r3
  node_t *v24; // r9
  int v25; // r11
  double v26; // fp5
  double v27; // fp4
  double v28; // fp3
  double v29; // fp2
  double v30; // fp1
  node_t *v31; // r29
  int v32; // r7
  int v33; // r11
  double v34; // fp6
  double v35; // fp5
  node_t *v36; // r9
  double v37; // fp4
  double v38; // fp3
  double v39; // fp2
  node_t *v40; // r29
  int v41; // r11
  int numIndices; // r8
  int v43; // r24
  int numBinVerts; // r11
  int v45; // r26
  int v46; // r7
  const idTransparencyVert *verts; // r8
  idTransparencyVert *v48; // r11
  int v49; // r9
  const idTransparencyVert *v50; // r10
  int v51; // r8
  const idTransparencyVert *v52; // r11
  idTransparencyVert *v53; // r10
  int v54; // r9
  int v55; // r11
  int v56; // r4
  float *v57; // r11
  idTransparencyVert *v58; // r10
  int v59; // r8
  float *v60; // r11
  idTransparencyVert *v61; // r10
  __int16 v62; // r3
  int v63; // r7
  int v64; // r30
  int v65; // r26
  int v66; // r29
  int v67; // r27
  int v68; // r9
  int i; // r9
  int v70; // r28
  bin_t *bins; // r10
  int *vertexRemap; // r8
  int v73; // r11
  unsigned int v74; // r11
  int v75; // r6
  unsigned __int16 *v76; // r11
  int v77; // r6
  int v78; // r7
  int v79; // r11
  int v80; // r10
  int *v81; // r11
  int v82; // r8
  int v83; // r7
  unsigned __int16 v84; // r5
  int *v85; // r8
  int v86; // r11
  int maxBinIndices; // r7
  int v88; // r11
  int v89; // r6
  int v90; // r7
  int v91; // r8
  int v92; // r10
  idTransparencyVert *v93; // r11
  idTransparencyVert *v94; // r10
  idVec3 v95; // [sp+50h] [-130h] BYREF
  polygon_t v96; // [sp+60h] [-120h] BYREF
  idVec3 v97; // [sp+80h] [-100h] BYREF
  idVec3 v98; // [sp+8Ch] [-F4h] BYREF
  idVec3 v99[13]; // [sp+98h] [-E8h] BYREF

  numNodes = parms->numNodes;
  y = parms->viewAxis.mat[1].y;
  v3 = (float)(parms->fovX * (float)128.0);
  x = parms->viewOrigin.x;
  v5 = (float)(parms->viewAxis.mat[0].y * (float)128.0);
  v6 = parms->viewAxis.mat[1].x;
  v7 = (float)(parms->viewAxis.mat[0].x * (float)128.0);
  v8 = parms->viewOrigin.y;
  v9 = (float)(parms->viewAxis.mat[0].z * (float)128.0);
  v10 = (float)(parms->fovY * (float)128.0);
  z = parms->viewAxis.mat[1].z;
  v12 = parms->viewOrigin.z;
  v13 = parms->viewAxis.mat[2].x;
  p_viewOrigin = &parms->viewOrigin;
  v15 = parms->viewAxis.mat[2].y;
  v16 = &parms->nodes[numNodes];
  v17 = parms->viewAxis.mat[2].z;
  parms->numNodes = numNodes + 1;
  v97.x = (float)((float)((float)x + (float)v7) - (float)((float)v6 * (float)v3)) - (float)((float)v13 * (float)v10);
  v97.y = (float)((float)((float)v8 + (float)v5) - (float)((float)y * (float)v3)) - (float)((float)v15 * (float)v10);
  v97.z = (float)((float)((float)v12 + (float)v9) - (float)((float)z * (float)v3)) - (float)((float)v17 * (float)v10);
  v98.x = (float)((float)((float)x + (float)v7) + (float)((float)v6 * (float)v3)) - (float)((float)v13 * (float)v10);
  v98.y = (float)((float)((float)v8 + (float)v5) + (float)((float)y * (float)v3)) - (float)((float)v15 * (float)v10);
  v98.z = (float)((float)((float)v12 + (float)v9) + (float)((float)z * (float)v3)) - (float)((float)v17 * (float)v10);
  v99[0].x = (float)((float)((float)x + (float)v7) - (float)((float)v6 * (float)v3)) + (float)((float)v13 * (float)v10);
  v99[0].y = (float)((float)((float)v5 + (float)v8) - (float)((float)y * (float)v3)) + (float)((float)v15 * (float)v10);
  v99[0].z = (float)((float)((float)v9 + (float)v12) - (float)((float)z * (float)v3)) + (float)((float)v17 * (float)v10);
  idPlane::FromPoints(this: &v16->plane, p1: &parms->viewOrigin, p2: &v98, p3: &v97, fixDegenerate: true);
  v19 = parms->numNodes;
  v16->children[1] = -1;
  v16->children[0] = v19;
  nodes = parms->nodes;
  v21 = parms->numNodes;
  parms->numNodes = v21 + 1;
  v22 = &nodes[v21];
  idPlane::FromPoints(this: &v22->plane, p1: p_viewOrigin, p2: &v97, p3: v99, fixDegenerate: true);
  v23 = parms->numNodes;
  v22->children[1] = -1;
  v22->children[0] = v23;
  v24 = parms->nodes;
  v25 = parms->numNodes;
  v26 = v97.x;
  v27 = (float)(v98.y + v99[0].y);
  v28 = v97.y;
  v29 = (float)(v98.z + v99[0].z);
  v30 = v97.z;
  parms->numNodes = v25 + 1;
  v95.x = (float)(v99[0].x + v98.x) - (float)v26;
  v95.y = (float)v27 - (float)v28;
  v95.z = (float)v29 - (float)v30;
  v31 = &v24[v25];
  idPlane::FromPoints(this: &v31->plane, p1: p_viewOrigin, p2: v99, p3: &v95, fixDegenerate: true);
  v32 = parms->numNodes;
  v31->children[1] = -1;
  v31->children[0] = v32;
  v33 = parms->numNodes;
  v34 = v99[0].y;
  v35 = v98.y;
  v36 = parms->nodes;
  v37 = v99[0].z;
  v38 = (float)(v99[0].x + v98.x);
  v39 = v98.z;
  parms->numNodes = v33 + 1;
  v95.x = (float)v38 - v97.x;
  v40 = &v36[v33];
  v95.y = (float)((float)v35 + (float)v34) - v97.y;
  v95.z = (float)((float)v39 + (float)v37) - v97.z;
  idPlane::FromPoints(this: &v40->plane, p1: p_viewOrigin, p2: &v95, p3: &v98, fixDegenerate: true);
  v41 = parms->numNodes;
  v40->children[1] = -1;
  v40->children[0] = v41;
  BuildBinTree_r(parms, screenVerts: &v97, offsetX: 0, partitionsX: 40, offsetY: 0, partitionsY: 45);
  numIndices = parms->numIndices;
  v43 = 0;
  parms->numBins = 1800;
  if ( numIndices > 0 )
  {
    numBinVerts = parms->numBinVerts;
    v45 = 0;
    do
    {
      v46 = numBinVerts + 1;
      verts = parms->verts;
      v48 = &parms->tempBinVerts[numBinVerts];
      v49 = parms->indices[v45];
      parms->numBinVerts = v46;
      v50 = &verts[v49 + 2];
      v48->xyz.x = v50->xyz.x;
      v48->xyz.y = v50->xyz.y;
      v48->xyz.z = v50->xyz.z;
      v48->st[0] = v50->st[0];
      v48->st[1] = v50->st[1];
      v48->st1[0] = v50->st1[0];
      v48->st1[1] = v50->st1[1];
      v48->normal[0] = v50->normal[0];
      v48->normal[1] = v50->normal[1];
      v48->normal[2] = v50->normal[2];
      v48->normal[3] = v50->normal[3];
      v48->tangent[0] = v50->tangent[0];
      v48->tangent[1] = v50->tangent[1];
      v48->tangent[2] = v50->tangent[2];
      v48->tangent[3] = v50->tangent[3];
      v48->color[0] = v50->color[0];
      v48->color[1] = v50->color[1];
      v48->color[2] = v50->color[2];
      v48->color[3] = v50->color[3];
      v51 = parms->numBinVerts;
      v52 = &parms->verts[v49 + 3];
      v53 = &parms->tempBinVerts[v51];
      parms->numBinVerts = v51 + 1;
      v53->xyz.x = v52->xyz.x;
      v53->xyz.y = v52->xyz.y;
      v53->xyz.z = v52->xyz.z;
      v53->st[0] = v52->st[0];
      v53->st[1] = v52->st[1];
      v53->st1[0] = v52->st1[0];
      v53->st1[1] = v52->st1[1];
      v53->normal[0] = v52->normal[0];
      v53->normal[1] = v52->normal[1];
      v53->normal[2] = v52->normal[2];
      v53->normal[3] = v52->normal[3];
      v54 = __ROL4__(v49, 5);
      v53->tangent[0] = v52->tangent[0];
      v53->tangent[1] = v52->tangent[1];
      v53->tangent[2] = v52->tangent[2];
      v53->tangent[3] = v52->tangent[3];
      v53->color[0] = v52->color[0];
      v53->color[1] = v52->color[1];
      v53->color[2] = v52->color[2];
      v53->color[3] = v52->color[3];
      v55 = parms->numBinVerts;
      v56 = v55 + 1;
      v58 = &parms->tempBinVerts[v55];
      v57 = (float *)((char *)&parms->verts->xyz.x + v54);
      parms->numBinVerts = v56;
      v58->xyz.x = v57[8];
      v58->xyz.y = v57[9];
      v58->xyz.z = v57[10];
      v58->st[0] = *((_WORD *)v57 + 22);
      v58->st[1] = *((_WORD *)v57 + 23);
      v58->st1[0] = *((_WORD *)v57 + 24);
      v58->st1[1] = *((_WORD *)v57 + 25);
      v58->normal[0] = *((_BYTE *)v57 + 52);
      v58->normal[1] = *((_BYTE *)v57 + 53);
      v58->normal[2] = *((_BYTE *)v57 + 54);
      v58->normal[3] = *((_BYTE *)v57 + 55);
      v58->tangent[0] = *((_BYTE *)v57 + 56);
      v58->tangent[1] = *((_BYTE *)v57 + 57);
      v58->tangent[2] = *((_BYTE *)v57 + 58);
      v58->tangent[3] = *((_BYTE *)v57 + 59);
      v58->color[0] = *((_BYTE *)v57 + 60);
      v58->color[1] = *((_BYTE *)v57 + 61);
      v58->color[2] = *((_BYTE *)v57 + 62);
      v58->color[3] = *((_BYTE *)v57 + 63);
      v59 = parms->numBinVerts;
      v60 = (float *)((char *)&parms->verts->xyz.x + v54);
      v61 = &parms->tempBinVerts[v59];
      parms->numBinVerts = v59 + 1;
      v61->xyz.x = *v60;
      v61->xyz.y = v60[1];
      v61->xyz.z = v60[2];
      v61->st[0] = *((_WORD *)v60 + 6);
      v62 = *((_WORD *)v60 + 7);
      v96.numPoints = 4;
      v61->st[1] = v62;
      v61->st1[0] = *((_WORD *)v60 + 8);
      v61->st1[1] = *((_WORD *)v60 + 9);
      v61->normal[0] = *((_BYTE *)v60 + 20);
      v61->normal[1] = *((_BYTE *)v60 + 21);
      v61->normal[2] = *((_BYTE *)v60 + 22);
      v61->normal[3] = *((_BYTE *)v60 + 23);
      v61->tangent[0] = *((_BYTE *)v60 + 24);
      v61->tangent[1] = *((_BYTE *)v60 + 25);
      v61->tangent[2] = *((_BYTE *)v60 + 26);
      v61->tangent[3] = *((_BYTE *)v60 + 27);
      v61->color[0] = *((_BYTE *)v60 + 28);
      v61->color[1] = *((_BYTE *)v60 + 29);
      v61->color[2] = *((_BYTE *)v60 + 30);
      v61->color[3] = *((_BYTE *)v60 + 31);
      v63 = parms->numBinVerts;
      v96.points[0] = v63 - 4;
      v96.points[1] = v63 - 3;
      v96.points[2] = v63 - 2;
      v96.points[3] = v63 - 1;
      BinPolygon_r(parms, nodeNum: 0, polygon: &v96);
      numBinVerts = parms->numBinVerts;
      if ( numBinVerts >= parms->maxBinVerts - 1724 )
        break;
      v43 += 6;
      v45 += 6;
    }
    while ( v43 < parms->numIndices );
  }
  v64 = 0;
  memset(Dst: parms->vertexRemap, Val: -1, Size: 4 * parms->numBinVerts);
  v65 = 0;
  if ( parms->numBins > 0 )
  {
    v66 = 0;
    v67 = 0;
    do
    {
      v68 = parms->bins[v67].numIndices;
      v70 = __CFADD__(v68 - 126, 0x80000000) ? 0 : v68 - 126;
      for ( i = v68 - 3; i >= v70; i -= 3 )
      {
        bins = parms->bins;
        vertexRemap = parms->vertexRemap;
        v73 = ((unsigned __int64)(i * (__int64)(int)"n graph") >> 32) + i;
        v74 = i - 126 * ((v73 >> 6) + ((unsigned int)v73 >> 31));
        v75 = v66 * 128 + 2 + v74;
        v76 = &bins[v66].indices[v74];
        v77 = bins->indices[v75];
        v78 = v76[1];
        v79 = __ROL4__(*v76, 2);
        v80 = *(int *)((char *)vertexRemap + v79);
        if ( v80 == -1 )
        {
          *(int *)((char *)vertexRemap + v79) = v64;
          LOWORD(v80) = v64++;
        }
        v81 = parms->vertexRemap;
        v82 = v78;
        v83 = v81[v78];
        if ( v83 == -1 )
        {
          v81[v82] = v64;
          v84 = v64++;
        }
        else
        {
          v84 = v83;
        }
        v85 = parms->vertexRemap;
        v86 = v85[v77];
        if ( v86 == -1 )
        {
          v85[v77] = v64;
          LOWORD(v86) = v64++;
        }
        parms->binIndices[parms->numBinIndices] = v80;
        parms->binIndices[parms->numBinIndices + 1] = v84;
        parms->binIndices[parms->numBinIndices + 2] = v86;
        maxBinIndices = parms->maxBinIndices;
        v88 = parms->numBinIndices + 3;
        parms->numBinIndices = v88;
        if ( v88 >= maxBinIndices )
          break;
      }
      if ( parms->numBinIndices >= parms->maxBinIndices )
        break;
      ++v65;
      ++v67;
      ++v66;
    }
    while ( v65 < parms->numBins );
  }
  v89 = 0;
  if ( parms->numBinVerts > 0 )
  {
    v90 = 0;
    v91 = 0;
    do
    {
      v92 = parms->vertexRemap[v90];
      if ( v92 != -1 )
      {
        v93 = &parms->tempBinVerts[v91];
        v94 = &parms->binVerts[v92];
        v94->xyz.x = v93->xyz.x;
        v94->xyz.y = v93->xyz.y;
        v94->xyz.z = v93->xyz.z;
        v94->st[0] = v93->st[0];
        v94->st[1] = v93->st[1];
        v94->st1[0] = v93->st1[0];
        v94->st1[1] = v93->st1[1];
        v94->normal[0] = v93->normal[0];
        v94->normal[1] = v93->normal[1];
        v94->normal[2] = v93->normal[2];
        v94->normal[3] = v93->normal[3];
        v94->tangent[0] = v93->tangent[0];
        v94->tangent[1] = v93->tangent[1];
        v94->tangent[2] = v93->tangent[2];
        v94->tangent[3] = v93->tangent[3];
        v94->color[0] = v93->color[0];
        v94->color[1] = v93->color[1];
        v94->color[2] = v93->color[2];
        v94->color[3] = v93->color[3];
      }
      ++v89;
      ++v91;
      ++v90;
    }
    while ( v89 < parms->numBinVerts );
  }
}

