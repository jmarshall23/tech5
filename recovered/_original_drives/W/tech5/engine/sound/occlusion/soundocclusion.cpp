
// ========================================================================
// SoundTrace_i
// EA  : 0x82989090
// RVA : 0x00989090
// PDB : w:\tech5\engine\sound\occlusion\soundocclusion.cpp
// ========================================================================

int __fastcall SoundTrace_i(
        const flatSoundBSP_t *flatBSP,
        idSBSPNodeCache *nodeCache,
        idSBSPPlaneCache *planeCache,
        const idVec3 *start,
        const idVec3 *end)
{
  int v7; // r6
  int v9; // r11
  char *v12; // r7
  sbspNode_t *v14; // r11
  char v16; // cr56
  char v17; // cr57
  char v18; // cr58
  char v19; // cr59
  char v20; // r5
  unsigned __int8 v21; // cr58
  unsigned __int8 v22; // cr59
  BOOL v23; // r10
  __int16 v24; // r4
  char v26; // [sp+10h] [-1200h] BYREF
  __int64 v27; // [sp+210h] [-1000h] BYREF
  char v28; // [sp+220h] [-FF0h] BYREF

  _R10 = 16;
  __asm { lvlx128   v63, r0, r4 }
  __asm { lvlx128   v62, r0, r5 }
  v7 = 0;
  _R7 = &vmx_float_one_10;
  v9 = 1;
  __asm { lvrx128   v61, r10, r4 }
  _R9 = &v28;
  __asm
  {
    lvrx128   v60, r10, r5
    vor128    v0, v95, v61
    vor128    v63, v94, v60
  }
  _R8 = &v27;
  __asm { lvx128    v62, r0, r7 }
  v12 = &v26;
  __asm
  {
    vrlimi128 v0, v62, 1, 0
    vrlimi128 v63, v62, 1, 0
  }
  while ( 1 )
  {
    while ( v9 > 0 )
    {
      _R5 = flatBSP->planes;
      __asm { vspltisw128 v59, 0 }
      v14 = &flatBSP->nodes[v9];
      _R10 = 16 * v14->planeNum;
      __asm
      {
        lvx128    v58, r10, r5
        vmsum4fp128 v62, v90, v0
        vmsum4fp128 v61, v90, v63
        vcmpgefp128. v57, v94, v59
      }
      v20 = (v16 << 7) | (v17 << 6) | (32 * v18) | (16 * v19);
      __asm { vcmpgefp128. v56, v93, v59 }
      v23 = (v20 & 0x20) != 0;
      if ( v23 == (((32 * v21) & 0x20 | (16 * v22) & 0x20) != 0) )
      {
        v9 = v14->children[v23];
      }
      else
      {
        __asm
        {
          vsubfp128 v55, v94, v61
          stvx128   v63, r0, r9
          vsubfp128 v13, v95, v0
        }
        ++v7;
        _R9 += 32;
        v24 = v14->children[(v20 & 0x20) == 0];
        v9 = v14->children[v23];
        __asm { vrefp128  v54, v55 }
        *(_DWORD *)v12 = v24;
        v12 += 4;
        __asm
        {
          vmulfp128 v12, v94, v54
          vmr128    v63, v12
          vmaddcfp128 v63, v13, v63, v0
          stvx128   v63, r0, r8
        }
        _R8 += 4;
      }
    }
    if ( v9 == 0 )
      return 1;
    if ( v7 == 0 )
      break;
    _R8 -= 4;
    v12 -= 4;
    v9 = *(_DWORD *)v12;
    _R9 -= 32;
    --v7;
    __asm
    {
      lvx128    v0, r0, r8
      lvx128    v63, r0, r9
    }
  }
  return 0;
}


// ========================================================================
// ?ExternalSoundTrace@@YA_NABUflatSoundBSP_t@@ABVidVec3@@1@Z
// EA  : 0x829891E0
// RVA : 0x009891E0
// PDB : w:\tech5\engine\sound\occlusion\soundocclusion.cpp
// ========================================================================

// attributes: thunk
int __fastcall ExternalSoundTrace(
        const flatSoundBSP_t *flatBSP,
        idSBSPNodeCache *start,
        idSBSPPlaneCache *end,
        const idVec3 *a4,
        const idVec3 *a5)
{
  return SoundTrace_i(flatBSP, nodeCache: start, planeCache: end, start: a4, end: a5);
}


// ========================================================================
// SoundFaceIntersection
// EA  : 0x829891E8
// RVA : 0x009891E8
// PDB : w:\tech5\engine\sound\occlusion\soundocclusion.cpp
// ========================================================================

idVec3 *__fastcall SoundFaceIntersection(
        idVec3 *result,
        const flatSoundBSP_t *flatBSP,
        idSBSPPlaneCache *planeCache,
        const sbspFace_t *face,
        const idVec3 *lineStart,
        const idVec3 *lineEnd)
{
  const idVec3 *v9; // r23
  int v10; // r11
  int *v11; // r10
  idVec3 *vertices; // r5
  int v13; // ctr
  char *v14; // r4
  double v17; // fp12
  double v18; // fp0
  double v19; // fp17
  double v20; // fp16
  double v21; // fp15
  float v22; // r29
  float v23; // r30
  float v24; // r28
  double v25; // fp18
  char v26; // r31
  char v27; // r26
  float *v28; // r6
  float v29; // r4
  float v30; // r3
  int v31; // r25
  double v32; // fp23
  double v33; // fp24
  double v34; // fp25
  const idVec3 **v35; // r27
  double z; // fp26
  double y; // fp27
  double x; // fp28
  const idVec3 *v39; // r6
  double v40; // fp22
  double v41; // fp21
  double v42; // fp31
  double v43; // fp20
  double v44; // fp30
  double v45; // fp29
  double v46; // fp0
  idVec3 *v47; // r3
  float v48; // r10
  float v49; // r9
  float v50; // [sp+50h] [-1B0h]
  float v51; // [sp+54h] [-1ACh]
  float v52; // [sp+58h] [-1A8h]
  idVec3 v53; // [sp+60h] [-1A0h] BYREF
  float v54; // [sp+70h] [-190h]
  float v55; // [sp+74h] [-18Ch]
  float v56; // [sp+78h] [-188h]
  idPlane v57; // [sp+80h] [-180h] BYREF
  _DWORD v58[72]; // [sp+90h] [-170h] BYREF

  _R8 = flatBSP->vertIndex;
  v9 = (const idVec3 *)((char *)flatBSP->planes + __ROL4__(*(unsigned __int16 *)&planeCache->gap0[6], 4));
  v10 = *(unsigned __int16 *)&planeCache->gap0[8];
  _R5 = __ROL4__(*(unsigned __int16 *)&planeCache->gap0[10], 2);
  v11 = (int *)((char *)_R8 + _R5);
  __asm { dcbt      r5, r8 }
  vertices = flatBSP->vertices;
  v58[32] = v10;
  if ( v10 > 0 )
  {
    v13 = v10;
    v14 = (char *)((char *)v58 - (char *)v11);
    do
    {
      _R3 = v58;
      _R9 = abs32(*v11);
      __asm { dcbt      r9, r3 }
      *(int *)((char *)v11++ + (_DWORD)v14) = (int)&vertices[_R9];
      --v13;
    }
    while ( v13 != 0 );
  }
  v17 = (float)((float)((float)(v9->z * *(float *)&face->numVerts)
                      + (float)((float)(*(float *)face->center * v9->x) + (float)(v9->y * *(float *)&face->center[2])))
              + v9[1].x);
  v18 = (float)((float)((float)(lineStart->z * v9->z)
                      + (float)((float)(lineStart->x * v9->x) + (float)(lineStart->y * v9->y)))
              + v9[1].x);
  if ( (v17 >= 0.0 || v18 >= 0.0)
    && (v17 <= 0.0 || v18 <= 0.0)
    && __fabs((float)((float)((float)((float)(v9->z * *(float *)&face->numVerts)
                                    + (float)((float)(*(float *)face->center * v9->x)
                                            + (float)(v9->y * *(float *)&face->center[2])))
                            + v9[1].x)
                    - (float)((float)((float)(lineStart->z * v9->z)
                                    + (float)((float)(lineStart->x * v9->x) + (float)(lineStart->y * v9->y)))
                            + v9[1].x))) >= idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    v19 = (float)(*(float *)face->center
                + (float)((float)(lineStart->x - *(float *)face->center)
                        * (float)((float)((float)((float)(v9->z * *(float *)&face->numVerts)
                                                + (float)((float)(*(float *)face->center * v9->x)
                                                        + (float)(v9->y * *(float *)&face->center[2])))
                                        + v9[1].x)
                                / (float)((float)((float)((float)(v9->z * *(float *)&face->numVerts)
                                                        + (float)((float)(*(float *)face->center * v9->x)
                                                                + (float)(v9->y * *(float *)&face->center[2])))
                                                + v9[1].x)
                                        - (float)((float)((float)(lineStart->z * v9->z)
                                                        + (float)((float)(lineStart->x * v9->x)
                                                                + (float)(lineStart->y * v9->y)))
                                                + v9[1].x)))));
    v20 = (float)(*(float *)&face->center[2]
                + (float)((float)(lineStart->y - *(float *)&face->center[2])
                        * (float)((float)((float)((float)(v9->z * *(float *)&face->numVerts)
                                                + (float)((float)(*(float *)face->center * v9->x)
                                                        + (float)(v9->y * *(float *)&face->center[2])))
                                        + v9[1].x)
                                / (float)((float)((float)((float)(v9->z * *(float *)&face->numVerts)
                                                        + (float)((float)(*(float *)face->center * v9->x)
                                                                + (float)(v9->y * *(float *)&face->center[2])))
                                                + v9[1].x)
                                        - (float)((float)((float)(lineStart->z * v9->z)
                                                        + (float)((float)(lineStart->x * v9->x)
                                                                + (float)(lineStart->y * v9->y)))
                                                + v9[1].x)))));
    v21 = (float)(*(float *)&face->numVerts
                + (float)((float)(lineStart->z - *(float *)&face->numVerts)
                        * (float)((float)((float)((float)(v9->z * *(float *)&face->numVerts)
                                                + (float)((float)(*(float *)face->center * v9->x)
                                                        + (float)(v9->y * *(float *)&face->center[2])))
                                        + v9[1].x)
                                / (float)((float)((float)((float)(v9->z * *(float *)&face->numVerts)
                                                        + (float)((float)(*(float *)face->center * v9->x)
                                                                + (float)(v9->y * *(float *)&face->center[2])))
                                                + v9[1].x)
                                        - (float)((float)((float)(lineStart->z * v9->z)
                                                        + (float)((float)(lineStart->x * v9->x)
                                                                + (float)(lineStart->y * v9->y)))
                                                + v9[1].x)))));
  }
  else
  {
    v19 = (float)(lineStart->x
                - (float)(v9->x
                        * (float)((float)((float)(lineStart->z * v9->z)
                                        + (float)((float)(lineStart->x * v9->x) + (float)(lineStart->y * v9->y)))
                                + v9[1].x)));
    v20 = (float)(lineStart->y
                - (float)(v9->y
                        * (float)((float)((float)(lineStart->z * v9->z)
                                        + (float)((float)(lineStart->x * v9->x) + (float)(lineStart->y * v9->y)))
                                + v9[1].x)));
    v21 = (float)(lineStart->z
                - (float)((float)((float)((float)(lineStart->z * v9->z)
                                        + (float)((float)(lineStart->x * v9->x) + (float)(lineStart->y * v9->y)))
                                + v9[1].x)
                        * v9->z));
  }
  v51 = v20;
  v22 = v51;
  v50 = v19;
  v23 = v50;
  v52 = v21;
  v24 = v52;
  v25 = 1.0e30;
  v26 = 0;
  v27 = 0;
  v54 = v50;
  v55 = v51;
  v28 = (float *)v58[v10 - 1];
  v56 = v52;
  v29 = v28[1];
  v30 = v28[2];
  v53.x = *v28;
  v53.y = v29;
  v53.z = v30;
  if ( v10 > 0 )
  {
    v31 = v10;
    v32 = v52;
    v33 = v51;
    v34 = v50;
    v35 = (const idVec3 **)v58;
    z = v53.z;
    y = v53.y;
    x = v53.x;
    do
    {
      if ( (float)((float)((float)((float)x - (float)v19) * (float)((float)x - (float)v19))
                 + (float)((float)((float)((float)z - (float)v21) * (float)((float)z - (float)v21))
                         + (float)((float)((float)y - (float)v20) * (float)((float)y - (float)v20)))) < v25 )
      {
        v54 = x;
        v25 = (float)((float)((float)((float)x - (float)v19) * (float)((float)x - (float)v19))
                    + (float)((float)((float)((float)z - (float)v21) * (float)((float)z - (float)v21))
                            + (float)((float)((float)y - (float)v20) * (float)((float)y - (float)v20))));
        v55 = y;
        v56 = z;
      }
      v39 = *v35;
      v40 = (*v35)->x;
      v41 = (*v35)->y;
      v42 = (float)((*v35)->x - (float)x);
      v43 = (*v35)->z;
      v44 = (float)((*v35)->y - (float)y);
      v45 = (float)((*v35)->z - (float)z);
      v53.x = (*v35)->x - (float)x;
      v53.y = v44;
      v53.z = v45;
      idPlane::FromVecs(this: &v57, dir1: &v53, dir2: v9, p: v39, fixDegenerate: true);
      v46 = (float)((float)((float)((float)v34 * v57.a)
                          + (float)((float)(v57.b * (float)v33) + (float)(v57.c * (float)v32)))
                  + v57.d);
      if ( v46 < 0.0 )
      {
        v26 = 1;
        v34 = (float)((float)v34
                    - (float)(v57.a
                            * (float)((float)((float)((float)v34 * v57.a)
                                            + (float)((float)(v57.b * (float)v33) + (float)(v57.c * (float)v32)))
                                    + v57.d)));
        v50 = v34;
        v33 = (float)((float)v33 - (float)(v57.b * (float)v46));
        v51 = v33;
        v32 = (float)((float)v32 - (float)(v57.c * (float)v46));
        v46 = 0.0;
        v52 = v32;
      }
      if ( __fabs(v46) < 0.1
        && (float)((float)((float)((float)v34 - (float)x) * (float)v42)
                 + (float)((float)((float)((float)v32 - (float)z) * (float)v45)
                         + (float)((float)((float)v33 - (float)y) * (float)v44))) >= 0.0
        && (float)((float)((float)((float)v34 - (float)v40) * (float)v42)
                 + (float)((float)((float)((float)v32 - (float)v43) * (float)v45)
                         + (float)((float)((float)v33 - (float)v41) * (float)v44))) <= 0.0 )
      {
        v27 = 1;
      }
      --v31;
      x = v40;
      y = v41;
      ++v35;
      z = v43;
    }
    while ( v31 != 0 );
  }
  v47 = result;
  if ( v26 != 0 )
  {
    if ( v27 != 0 )
    {
      result->x = v50;
      result->y = v51;
      result->z = v52;
    }
    else
    {
      v48 = v55;
      v49 = v56;
      result->x = v54;
      result->y = v48;
      result->z = v49;
    }
  }
  else
  {
    result->x = v23;
    result->y = v22;
    result->z = v24;
  }
  return v47;
}


// ========================================================================
// ?SoundOcclusionJob@@YAXAAUsoundOcclusionParms_t@@@Z
// EA  : 0x829895A0
// RVA : 0x009895A0
// PDB : w:\tech5\engine\sound\occlusion\soundocclusion.cpp
// ========================================================================

void __fastcall SoundOcclusionJob(idSBSPPlaneCache *parms)
{
  int v1; // r11
  int *v2; // r6
  double v3; // fp12
  sbspArea_t *v5; // r7
  int door; // r5
  sbspFace_t *v7; // r8
  int v8; // r10
  __int16 v9; // r9
  int v10; // r11
  sbspArea_t *v11; // r10
  int v12; // r9
  idVec3 *v13; // r29
  double v14; // fp12
  double v15; // fp9
  double v16; // fp6
  double v17; // fp31
  const idVec3 *v18; // r6
  int v19; // r11
  int v20; // r10
  int v21; // r30
  idSBSPPlaneCache *v22; // r28
  idVec3 *v23; // r3
  double y; // fp13
  double z; // fp12
  const idVec3 *v26; // r7
  const idVec3 *v27; // r6
  idVec3 *v28; // r9
  double v29; // fp13
  double v30; // fp12
  double v31; // fp11
  int v32; // r11
  float *p_x; // r11
  double v34; // fp10
  double v35; // fp8
  double v36; // fp6
  double v37; // fp1
  double v38; // fp0
  double v39; // fp7
  double v40; // fp5
  __int16 v41; // r7
  int v42; // r3
  double v43; // fp9
  double v44; // fp8
  double v45; // fp7
  int v46; // r30
  double v47; // fp10
  float v48; // r7
  double v49; // fp0
  double v50; // fp4
  double v51; // fp1
  double v52; // fp6
  double v53; // fp2
  double v54; // fp5
  double v55; // fp10
  double v56; // fp3
  double v57; // fp0
  idVec3 *v58; // r9
  int v59; // r11
  float *v60; // r11
  double v61; // fp13
  double v62; // fp11
  double v63; // fp9
  float x; // [sp+50h] [-70h] BYREF
  float v65; // [sp+54h] [-6Ch]
  float v66; // [sp+58h] [-68h]
  idVec3 v67[2]; // [sp+60h] [-60h] BYREF

  *(float *)parms->gap0 = *(float *)&parms->gap0[124];
  v1 = *(_DWORD *)&parms->gap0[120];
  *(float *)&parms->gap0[4] = *(float *)parms[1].gap0;
  v2 = *(int **)&parms->gap0[88];
  v3 = *(float *)&parms[1].gap0[4];
  *(_DWORD *)&parms->gap0[28] = 1;
  *(float *)&parms->gap0[8] = v3;
  *(float *)&parms->gap0[12] = 0.0;
  if ( v2[v1] != 0 || v1 == *(_DWORD *)&parms->gap0[104] )
  {
    v5 = *(sbspArea_t **)&parms->gap0[52];
    door = v5[v1].door;
    if ( v1 != *(_DWORD *)&parms->gap0[104] )
    {
      v7 = *(sbspFace_t **)&parms->gap0[44];
      v8 = v1;
      do
      {
        v9 = v7[abs32(v2[v8])].faceAreas[v2[v8] >= 0];
        v10 = v9;
        if ( v9 < 0 )
        {
          v10 = -v9;
          v11 = &v5[-v9];
          v12 = v11->door;
          if ( v12 >= 0 && v12 != door )
          {
            *(float *)&parms->gap0[12] = *(float *)(4 * v11->door + *(_DWORD *)&parms->gap0[96])
                                       + *(float *)&parms->gap0[12];
            door = v11->door;
          }
        }
        v8 = v10;
      }
      while ( v10 != *(_DWORD *)&parms->gap0[104] );
    }
    v13 = (idVec3 *)&parms->gap0[108];
    v14 = (float)(*(float *)&parms->gap0[8] - *(float *)&parms->gap0[116]);
    v15 = (float)(*(float *)&parms->gap0[4] - *(float *)&parms->gap0[112]);
    v16 = (float)(*(float *)parms->gap0 - *(float *)&parms->gap0[108]);
    v17 = (float)(*(float *)&parms[1].gap0[8] * *(float *)&parms[1].gap0[8]);
    if ( (float)((float)(*(float *)&parms->gap0[12] * *(float *)&parms->gap0[12])
               + (float)((float)((float)v16 * (float)v16)
                       + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)))) <= v17
      && (unsigned __int8)SoundTrace_i(
                            flatBSP: (const flatSoundBSP_t *)&parms->gap0[32],
                            nodeCache: (idSBSPNodeCache *)&parms->gap0[108],
                            planeCache: parms,
                            start: (const idVec3 *)v2,
                            end: (const idVec3 *)v5) != 0 )
    {
      v19 = *(_DWORD *)&parms->gap0[120];
      if ( v19 != *(_DWORD *)&parms->gap0[104] )
      {
        v20 = 4 * v19;
        while ( 1 )
        {
          v21 = *(_DWORD *)(v20 + *(_DWORD *)&parms->gap0[88]);
          v22 = (idSBSPPlaneCache *)(16 * abs32(v21) + *(_DWORD *)&parms->gap0[44]);
          v23 = SoundFaceIntersection(
                  result: v67,
                  flatBSP: (const flatSoundBSP_t *)&parms->gap0[32],
                  planeCache: v22,
                  face: (const sbspFace_t *)&parms->gap0[108],
                  lineStart: (const idVec3 *)parms,
                  lineEnd: (const idVec3 *)(v21 >> 31));
          y = v23->y;
          z = v23->z;
          x = v23->x;
          v65 = y;
          v66 = z;
          if ( (unsigned __int8)SoundTrace_i(
                                  flatBSP: (const flatSoundBSP_t *)&parms->gap0[32],
                                  nodeCache: (idSBSPNodeCache *)&parms->gap0[108],
                                  planeCache: (idSBSPPlaneCache *)&x,
                                  start: v27,
                                  end: v26) == 0 )
            break;
          v28 = *(idVec3 **)&parms->gap0[16];
          v29 = v66;
          v30 = v65;
          v31 = x;
          if ( v28 != nullptr )
          {
            v32 = *(_DWORD *)&parms->gap0[20];
            if ( v32 < *(_DWORD *)&parms->gap0[24] )
            {
              *(_DWORD *)&parms->gap0[20] = v32 + 1;
              p_x = &v28[v32].x;
              *p_x = v31;
              p_x[1] = v30;
              p_x[2] = v29;
            }
          }
          v34 = (float)(*(float *)&parms->gap0[4] - (float)v30);
          v35 = (float)(*(float *)&parms->gap0[8] - (float)v29);
          v36 = (float)(*(float *)parms->gap0 - (float)v31);
          *(float *)parms->gap0 = v31;
          *(float *)&parms->gap0[4] = v30;
          *(float *)&parms->gap0[8] = v29;
          v37 = __fsqrts((float)((float)((float)v36 * (float)v36)
                               + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34))));
          v38 = (float)((float)v37 + *(float *)&parms->gap0[12]);
          *(float *)&parms->gap0[12] = (float)v37 + *(float *)&parms->gap0[12];
          v39 = (float)((float)v30 - *(float *)&parms->gap0[112]);
          v40 = (float)((float)v29 - *(float *)&parms->gap0[116]);
          if ( (float)((float)((float)v38 * (float)v38)
                     + (float)((float)((float)((float)v31 - v13->x) * (float)((float)v31 - v13->x))
                             + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39)))) > v17 )
            return;
          v41 = *(_WORD *)&v22->gap0[2 * (v21 >= 0) + 12];
          v18 = (const idVec3 *)v41;
          v42 = abs16(v41);
          v20 = 4 * v42;
          if ( v42 == *(_DWORD *)&parms->gap0[104] )
            goto LABEL_23;
        }
      }
      v29 = v66;
      v30 = v65;
      v31 = x;
LABEL_23:
      v43 = (float)(*(float *)&parms->gap0[4] - (float)v30);
      v44 = (float)(*(float *)&parms->gap0[8] - (float)v29);
      v45 = (float)(*(float *)parms->gap0 - (float)v31);
      v46 = 0;
      v47 = 0.25;
      v48 = v66;
      v49 = 0.5;
      v50 = v66;
      v51 = 16.0;
      v52 = x;
      v53 = (float)((float)((float)(*(float *)parms->gap0 - (float)v31) * (float)(*(float *)parms->gap0 - (float)v31))
                  + (float)((float)((float)v44 * (float)v44) + (float)((float)v43 * (float)v43)));
      v54 = v65;
      do
      {
        if ( (float)((float)v47 * (float)v53) <= v51 )
          break;
        x = (float)((float)v45 * (float)v49) + (float)v31;
        v65 = (float)((float)v43 * (float)v49) + (float)v30;
        v66 = (float)((float)v44 * (float)v49) + (float)v29;
        if ( (unsigned __int8)SoundTrace_i(
                                flatBSP: (const flatSoundBSP_t *)&parms->gap0[32],
                                nodeCache: (idSBSPNodeCache *)&parms->gap0[108],
                                planeCache: (idSBSPPlaneCache *)&x,
                                start: v18,
                                end: (const idVec3 *)LODWORD(v48)) != 0 )
        {
          v49 = (float)((float)v57 - (float)v55);
        }
        else
        {
          v52 = x;
          v49 = (float)((float)v57 + (float)v55);
          v54 = v65;
          v50 = v66;
        }
        ++v46;
        v47 = (float)((float)v55 * (float)v56);
      }
      while ( v46 < 8 );
      v58 = *(idVec3 **)&parms->gap0[16];
      if ( v58 != nullptr )
      {
        v59 = *(_DWORD *)&parms->gap0[20];
        if ( v59 < *(_DWORD *)&parms->gap0[24] )
        {
          *(_DWORD *)&parms->gap0[20] = v59 + 1;
          v60 = &v58[v59].x;
          *v60 = v52;
          v60[1] = v54;
          v60[2] = v50;
        }
      }
      v61 = (float)(*(float *)&parms->gap0[4] - (float)v54);
      v62 = (float)(*(float *)&parms->gap0[8] - (float)v50);
      v63 = (float)(*(float *)parms->gap0 - (float)v52);
      *(float *)parms->gap0 = v52;
      *(float *)&parms->gap0[4] = v54;
      *(float *)&parms->gap0[8] = v50;
      *(float *)&parms->gap0[12] = (float)__fsqrts((float)((float)((float)v63 * (float)v63)
                                                         + (float)((float)((float)v62 * (float)v62)
                                                                 + (float)((float)v61 * (float)v61))))
                                 + *(float *)&parms->gap0[12];
    }
  }
  else
  {
    *(float *)&parms->gap0[12] = *(float *)&parms[1].gap0[8] * (float)2.0;
  }
}


// ========================================================================
// `dynamic initializer for 'register_SoundOcclusionJob''
// EA  : 0x833600D0
// RVA : 0x013600D0
// PDB : w:\tech5\engine\sound\occlusion\soundocclusion.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_SoundOcclusionJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_SoundOcclusionJob,
           function: (void (__fastcall *)(void *))SoundOcclusionJob,
           name: "SoundOcclusionJob");
}

