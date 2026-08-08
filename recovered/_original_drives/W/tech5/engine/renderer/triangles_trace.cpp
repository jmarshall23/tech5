
// ========================================================================
// ?GetSurfaceArea@idTriangles@@QBAMXZ
// EA  : 0x82976300
// RVA : 0x00976300
// PDB : w:\tech5\engine\renderer\triangles_trace.cpp
// ========================================================================

float __fastcall idTriangles::GetSurfaceArea(idTriangles *this)
{
  double v2; // fp1
  double v3; // fp31
  int v4; // r29
  int v5; // r31

  if ( this->indexes != nullptr )
  {
    v3 = 0.0;
    v4 = 0;
    if ( this->numIndexes > 0 )
    {
      v5 = 0;
      do
      {
        v4 += 3;
        v3 = (float)(idGeometry::AreaOfTriangle(
                       a: (const idVec3 *)((char *)&this->verts->xyz + __ROL4__(this->indexes[v5], 5)),
                       b: (const idVec3 *)((char *)&this->verts->xyz + __ROL4__(this->indexes[v5 + 1], 5)),
                       c: (const idVec3 *)((char *)&this->verts->xyz + __ROL4__(this->indexes[v5 + 2], 5)))
                   + (float)v3);
        v5 += 3;
      }
      while ( v4 < this->numIndexes );
    }
    v2 = v3;
  }
  else
  {
    v2 = 0.0;
  }
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?TracePointCull@idTriangles@@SAXPAEAAEMPBVidPlane@@PBVidDrawVert@@H@Z
// EA  : 0x829763B0
// RVA : 0x009763B0
// PDB : w:\tech5\engine\renderer\triangles_trace.cpp
// ========================================================================

void __fastcall idTriangles::TracePointCull(
        unsigned __int8 *cullBits,
        unsigned __int8 *totalOr,
        double radius,
        const idPlane *planes,
        const idDrawVert *verts,
        const int numVerts,
        int a7)
{
  unsigned __int8 v7; // r9
  int v8; // r10
  int v9; // ctr
  float *v10; // r11
  double v11; // fp13
  double v12; // fp12
  float v13; // r28
  unsigned int v14; // r31
  unsigned int v15; // r30
  char v16; // r8

  v7 = 0;
  v8 = 0;
  if ( a7 > 0 )
  {
    v9 = a7;
    v10 = (float *)(numVerts - 32);
    do
    {
      v11 = v10[10];
      v12 = v10[9];
      v10 += 8;
      v13 = (float)((float)((float)((float)v11 * verts[1].xyz.z)
                          + (float)((float)(*v10 * verts[1].xyz.x) + (float)((float)v12 * verts[1].xyz.y)))
                  + verts[1].st.x)
          - (float)radius;
      v14 = (COERCE_UNSIGNED_INT(
               (float)((float)((float)(*(float *)verts->tangent * (float)v11)
                             + (float)((float)(*v10 * verts->st.y) + (float)((float)v12 * *(float *)verts->normal)))
                     + *(float *)verts->color)
             - (float)radius) >> 26)
          & 0x20;
      v15 = HIBYTE(
              COERCE_UNSIGNED_INT(
                (float)((float)((float)(*(float *)verts[1].tangent * (float)v11)
                              + (float)((float)(*v10 * verts[1].st.y) + (float)((float)v12 * *(float *)verts[1].normal)))
                      + *(float *)verts[1].color)
              - (float)radius))
          & 0x80;
      v16 = v15
          | (LODWORD(v13) >> 25) & 0x40
          | v14
          | (COERCE_UNSIGNED_INT(
               (float)((float)((float)(verts->xyz.z * (float)v11)
                             + (float)((float)((float)v12 * verts->xyz.y) + (float)(*v10 * verts->xyz.x)))
                     + verts->st.x)
             - (float)radius) >> 27)
          & 0x10
          | (COERCE_UNSIGNED_INT(
               (float)((float)((float)(*(float *)verts[1].tangent * (float)v11)
                             + (float)((float)(*v10 * verts[1].st.y) + (float)((float)v12 * *(float *)verts[1].normal)))
                     + *(float *)verts[1].color)
             + (float)radius) >> 28)
          & 8
          | (COERCE_UNSIGNED_INT(
               (float)((float)((float)((float)v11 * verts[1].xyz.z)
                             + (float)((float)(*v10 * verts[1].xyz.x) + (float)((float)v12 * verts[1].xyz.y)))
                     + verts[1].st.x)
             + (float)radius) >> 29)
          & 4
          | (COERCE_UNSIGNED_INT(
               (float)((float)((float)(*(float *)verts->tangent * (float)v11)
                             + (float)((float)(*v10 * verts->st.y) + (float)((float)v12 * *(float *)verts->normal)))
                     + *(float *)verts->color)
             + (float)radius) >> 30)
          & 2
          | (COERCE_INT(
               (float)((float)((float)(verts->xyz.z * (float)v11)
                             + (float)((float)((float)v12 * verts->xyz.y) + (float)(*v10 * verts->xyz.x)))
                     + verts->st.x)
             + (float)radius) < 0);
      cullBits[v8] = v16 ^ 0xF;
      v7 |= v16 ^ 0xF;
      ++v8;
      --v9;
    }
    while ( v9 != 0 );
  }
  *totalOr = v7;
}


// ========================================================================
// ?TriangleTrace@idTriangles@@QBA?AUlocalTrace_t@@ABVidVec3@@0M_N@Z
// EA  : 0x82976550
// RVA : 0x00976550
// PDB : w:\tech5\engine\renderer\triangles_trace.cpp
// ========================================================================

idTriangles *__fastcall idTriangles::TriangleTrace(
        idTriangles *this,
        idTriangles *result,
        const idVec3 *start,
        const idVec3 *end,
        double radius,
        bool twoSided,
        char a7)
{
  int numVerts; // r10
  double y; // fp27
  double v15; // fp11
  double x; // fp26
  double v17; // fp25
  double z; // fp24
  double v19; // fp8
  double v22; // fp1
  double v23; // fp4
  double v24; // fp2
  double v25; // fp1
  double v26; // fp30
  double v27; // fp29
  double v28; // fp28
  double v29; // fp13
  double v30; // fp12
  double v31; // fp10
  double v32; // fp8
  double v33; // fp3
  double v34; // fp0
  double v35; // fp12
  double v36; // fp11
  const idPlane *v37; // r5
  float v38; // r27
  int v39; // r25
  int v40; // r28
  int v41; // r8
  int v42; // r10
  unsigned __int16 *v43; // r9
  int v44; // ctr
  int v45; // r11
  int v46; // r11
  int v47; // r24
  int v48; // r30
  char *buffer; // r22
  const idPlane *v50; // r5
  double v51; // fp30
  double v52; // fp23
  double v53; // fp29
  double v54; // fp16
  double v55; // fp22
  double v56; // fp21
  double v57; // fp19
  double v58; // fp20
  double v59; // fp18
  double v60; // fp17
  unsigned __int16 *v61; // r23
  unsigned int v62; // r21
  float v63; // r27
  float v64; // r26
  float v65; // r25
  char v66; // r8
  char v67; // r7
  char v68; // r6
  unsigned int v69; // r11
  const idVec3 *v70; // r28
  const idVec3 *v71; // r29
  const idVec3 *v72; // r30
  double v73; // fp0
  double v74; // fp13
  double v75; // fp24
  double v76; // fp13
  double v77; // fp11
  double v78; // fp9
  double v79; // fp8
  double v80; // fp7
  double v81; // fp30
  double v82; // fp29
  double v83; // fp12
  double v84; // fp5
  double v85; // fp0
  double v86; // fp13
  double v87; // fp3
  double v88; // fp4
  double v89; // fp10
  double v90; // fp9
  double v91; // fp11
  double v92; // fp6
  double v93; // fp9
  double v94; // fp8
  double v95; // fp7
  double v96; // fp11
  double v97; // fp11
  double v98; // fp10
  double v99; // fp9
  double v100; // fp11
  double v101; // fp10
  double v102; // fp11
  double v103; // fp10
  double v104; // fp9
  double v105; // fp6
  double v106; // fp8
  double v107; // fp7
  double v108; // fp15
  double v109; // fp8
  double v110; // fp2
  double v111; // fp1
  double v112; // fp6
  double v113; // fp7
  double v114; // fp8
  double v115; // fp8
  double v116; // fp7
  bool v117; // cr57
  double v118; // fp0
  double v119; // fp13
  double v120; // fp0
  double v121; // fp13
  double v122; // fp12
  double v123; // fp6
  double v124; // fp13
  double v125; // fp8
  double v126; // fp7
  double v127; // fp0
  double v128; // fp0
  double v129; // fp13
  double v130; // fp12
  double v131; // fp0
  double v132; // fp13
  unsigned __int8 v134[8]; // [sp+50h] [-2B0h] BYREF
  idTempArray<char> v135; // [sp+58h] [-2A8h] BYREF
  float v136; // [sp+60h] [-2A0h]
  idVec3 v137; // [sp+68h] [-298h] BYREF
  float v138; // [sp+74h] [-28Ch]
  float v139[11]; // [sp+80h] [-280h] BYREF
  idDrawVert v140; // [sp+B0h] [-250h] BYREF
  float v141; // [sp+D0h] [-230h]
  float v142; // [sp+D4h] [-22Ch]
  float v143; // [sp+D8h] [-228h]
  float v144; // [sp+DCh] [-224h]
  float v145; // [sp+E0h] [-220h]
  float v146; // [sp+E4h] [-21Ch]
  float v147; // [sp+E8h] [-218h]
  float v148; // [sp+ECh] [-214h]
  idPlane v149; // [sp+F0h] [-210h] BYREF
  float v150[100]; // [sp+100h] [-200h] BYREF

  numVerts = result->numVerts;
  v139[0] = 1.0;
  if ( numVerts == 0 )
    goto LABEL_2;
  y = end->y;
  v15 = (float)(end->y - start->y);
  x = end->x;
  v17 = start->x;
  z = end->z;
  v19 = (float)(end->z - start->z);
  _FP4 = (float)((float)((float)((float)v19 * (float)v19)
                       + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
                               + (float)((float)v15 * (float)v15)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f4, f5, f13 }
  v22 = __frsqrte(_FP2);
  v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                      * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v15 * (float)v15)))
                                                                                              * (float)0.5))
                                                                              * (float)v22)
                                                                      - (float)1.5)
                                                      * (float)v22)
                                              * (float)((float)((float)((float)v19 * (float)v19)
                                                              + (float)((float)((float)(end->x - start->x)
                                                                              * (float)(end->x - start->x))
                                                                      + (float)((float)v15 * (float)v15)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v22
                                                                              * (float)((float)((float)((float)v19 * (float)v19)
                                                                                              + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v15 * (float)v15)))
                                                                                      * (float)0.5))
                                                                      * (float)v22)
                                                              - (float)1.5)
                                              * (float)v22))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v22
                                                      * (float)((float)((float)((float)v19 * (float)v19)
                                                                      + (float)((float)((float)(end->x - start->x)
                                                                                      * (float)(end->x - start->x))
                                                                              + (float)((float)v15 * (float)v15)))
                                                              * (float)0.5))
                                              * (float)v22)
                                      - (float)1.5)
                      * (float)v22));
  v24 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                      * (float)v22)
                                                                              * (float)((float)((float)((float)v19 * (float)v19)
                                                                                              + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v15 * (float)v15)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v22)
                                                                                              - (float)1.5)
                                                                              * (float)v22))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v22
                                                                                      * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v15 * (float)v15)))
                                                                                              * (float)0.5))
                                                                              * (float)v22)
                                                                      - (float)1.5)
                                                      * (float)v22))
                                      * (float)((float)((float)((float)v19 * (float)v19)
                                                      + (float)((float)((float)(end->x - start->x)
                                                                      * (float)(end->x - start->x))
                                                              + (float)((float)v15 * (float)v15)))
                                              * (float)0.5))
                              * (float)v23)
                      - (float)1.5);
  v25 = (float)((float)v24
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                              * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                      * (float)v22)
                                                                              - (float)1.5)
                                                              * (float)v22)
                                                      * (float)((float)((float)((float)v19 * (float)v19)
                                                                      + (float)((float)((float)(end->x - start->x)
                                                                                      * (float)(end->x - start->x))
                                                                              + (float)((float)v15 * (float)v15)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v22
                                                                                      * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v15 * (float)v15)))
                                                                                              * (float)0.5))
                                                                              * (float)v22)
                                                                      - (float)1.5)
                                                      * (float)v22))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v22
                                                              * (float)((float)((float)((float)v19 * (float)v19)
                                                                              + (float)((float)((float)(end->x - start->x)
                                                                                              * (float)(end->x - start->x))
                                                                                      + (float)((float)v15 * (float)v15)))
                                                                      * (float)0.5))
                                                      * (float)v22)
                                              - (float)1.5)
                              * (float)v22)));
  v26 = (float)((float)(end->x - start->x) * (float)v25);
  v27 = (float)((float)(end->y - start->y) * (float)v25);
  v137.x = (float)(end->x - start->x) * (float)v25;
  v137.y = (float)v15 * (float)v25;
  v28 = (float)((float)v19 * (float)v25);
  v137.z = (float)v19 * (float)v25;
  idVec3::NormalVectors(this: &v137, left: &v140.xyz, down: (idVec3 *)&v140.st.y);
  v29 = -start->z;
  v30 = start->y;
  v146 = -v27;
  v142 = v27;
  v136 = -v30;
  v143 = v28;
  v31 = result->bounds.b[0].x;
  v32 = result->bounds.b[0].y;
  v141 = v26;
  v145 = -v26;
  v147 = -v28;
  v33 = result->bounds.b[0].z;
  v34 = result->bounds.b[1].z;
  v35 = result->bounds.b[1].y;
  v36 = result->bounds.b[1].x;
  v150[0] = v31;
  v144 = (float)((float)-v17 * (float)v26) + (float)((float)((float)v27 * v136) + (float)((float)v28 * (float)v29));
  v150[1] = v32;
  v148 = (float)((float)-z * v147) + (float)((float)((float)-x * v145) + (float)((float)-y * v146));
  v140.st.x = (float)((float)-v17 * v140.xyz.x) + (float)((float)(v140.xyz.y * v136) + (float)(v140.xyz.z * (float)v29));
  *(float *)v140.color = (float)(*(float *)v140.tangent * (float)v29)
                       + (float)((float)(v140.st.y * (float)-v17) + (float)(*(float *)v140.normal * v136));
  v150[8] = v31;
  v150[2] = v33;
  v150[9] = v32;
  v150[10] = v34;
  v150[16] = v31;
  v150[17] = v35;
  v150[18] = v33;
  v150[24] = v31;
  v150[25] = v35;
  v150[26] = v34;
  v150[32] = v36;
  v150[33] = v32;
  v150[34] = v33;
  v150[40] = v36;
  v150[41] = v32;
  v150[42] = v34;
  v150[48] = v36;
  v150[49] = v35;
  v150[50] = v33;
  v150[56] = v36;
  v150[57] = v35;
  v150[58] = v34;
  idTriangles::TracePointCull(
    cullBits: (unsigned __int8 *)&v137,
    totalOr: v134,
    radius,
    planes: v37,
    verts: &v140,
    numVerts: (const int)v150,
    a7: 8);
  if ( (((v134[0] >> 4) ^ v134[0]) & 3) != 0 || (((v134[0] >> 1) ^ v134[0]) & 4) != 0 )
  {
LABEL_2:
    memcpy(Dst: this, Src: v139, Size: 0x2Cu);
  }
  else
  {
    idAutoStandardTriangles::idAutoStandardTriangles(this: (idAutoStandardTriangles *)&v137, tri: result);
    v38 = v137.x;
    v39 = *(_DWORD *)(LODWORD(v137.x) + 92);
    if ( v39 == 0 )
    {
LABEL_6:
      memcpy(Dst: this, Src: v139, Size: 0x2Cu);
      idAutoStandardTriangles::~idAutoStandardTriangles(this: (idAutoStandardTriangles *)&v137);
      return this;
    }
    v40 = *(_DWORD *)(LODWORD(v137.x) + 28);
    v41 = 0;
    v42 = 0xFFFF;
    if ( v40 > 0 )
    {
      v43 = *(unsigned __int16 **)(LODWORD(v137.x) + 92);
      v44 = *(_DWORD *)(LODWORD(v137.x) + 28);
      do
      {
        v45 = *v43;
        if ( v45 < v42 )
          v42 = *v43;
        if ( v45 > v41 )
          v41 = *v43;
        ++v43;
        --v44;
      }
      while ( v44 != 0 );
    }
    v46 = *(_DWORD *)(LODWORD(v137.x) + 32);
    if ( v42 < v46 && v41 < v46 )
    {
      v47 = *(_DWORD *)(LODWORD(v137.x) + 88);
      v48 = v41 + 1;
      if ( v47 == 0 )
        goto LABEL_6;
      idTempArray<char>::idTempArray<char>(this: &v135, num: v41 + 1);
      buffer = v135.buffer;
      idTriangles::TracePointCull(
        cullBits: (unsigned __int8 *)v135.buffer,
        totalOr: v134,
        radius,
        planes: v50,
        verts: &v140,
        numVerts: v47,
        a7: v48);
      if ( (((v134[0] >> 4) ^ v134[0]) & 3) != 0 )
      {
        memcpy(Dst: this, Src: v139, Size: 0x2Cu);
        if ( buffer != nullptr )
          idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
LABEL_71:
        idAutoStandardTriangles::~idAutoStandardTriangles(this: (idAutoStandardTriangles *)&v137);
        return this;
      }
      if ( (((v134[0] >> 1) ^ v134[0]) & 4) != 0 )
      {
        memcpy(Dst: this, Src: v139, Size: 0x2Cu);
        if ( buffer != nullptr )
          idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
        goto LABEL_71;
      }
      v51 = end->y;
      v52 = (float)((float)radius * (float)radius);
      v53 = end->x;
      v54 = end->z;
      v55 = start->z;
      v56 = start->y;
      v57 = (float)(end->z - start->z);
      v58 = start->x;
      v59 = (float)(end->y - start->y);
      v60 = (float)(end->x - start->x);
      v138 = end->y;
      v136 = v53;
      if ( v40 <= 0 )
      {
LABEL_69:
        memcpy(Dst: this, Src: v139, Size: 0x2Cu);
        if ( buffer != nullptr )
          idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
        goto LABEL_71;
      }
      v61 = (unsigned __int16 *)(v39 + 4);
      v62 = (v40 - 1) / 3u + 1;
      while ( 1 )
      {
        LODWORD(v63) = *(v61 - 1);
        LODWORD(v64) = *(v61 - 2);
        LODWORD(v65) = *v61;
        v66 = buffer[LODWORD(v63)];
        v67 = buffer[LODWORD(v64)];
        v68 = buffer[LODWORD(v65)];
        v69 = (unsigned __int8)(v67 | v66 | v68);
        if ( ((((unsigned __int8)(v67 | v66 | v68) >> 4) ^ v69) & 3) != 0 )
          goto LABEL_68;
        if ( (((v69 >> 1) ^ v69) & 4) != 0 )
          goto LABEL_68;
        v70 = (const idVec3 *)(32 * LODWORD(v65) + v47);
        v71 = (const idVec3 *)(32 * LODWORD(v63) + v47);
        v72 = (const idVec3 *)(32 * LODWORD(v64) + v47);
        idPlane::FromPoints(this: &v149, p1: v72, p2: v71, p3: v70, fixDegenerate: false);
        v73 = (float)((float)((float)(v149.a * (float)v58)
                            + (float)((float)(v149.b * (float)v56) + (float)(v149.c * (float)v55)))
                    + v149.d);
        v74 = (float)((float)((float)(v149.a * (float)v53)
                            + (float)((float)(v149.b * (float)v51) + (float)(v149.c * (float)v54)))
                    + v149.d);
        if ( v73 == 0.0 || v74 == 0.0 || a7 == 0 && v73 <= v74 )
          goto LABEL_68;
        if ( v73 < 0.0 == v74 < 0.0 )
          goto LABEL_68;
        v75 = (float)((float)((float)((float)(v149.a * (float)v58)
                                    + (float)((float)(v149.b * (float)v56) + (float)(v149.c * (float)v55)))
                            + v149.d)
                    / (float)((float)((float)((float)(v149.a * (float)v58)
                                            + (float)((float)(v149.b * (float)v56) + (float)(v149.c * (float)v55)))
                                    + v149.d)
                            - (float)((float)((float)(v149.a * (float)v53)
                                            + (float)((float)(v149.b * (float)v51) + (float)(v149.c * (float)v54)))
                                    + v149.d)));
        if ( v75 < 0.0 || v75 >= v139[0] )
          goto LABEL_68;
        v76 = v71->x;
        v77 = v72->y;
        v78 = v72->x;
        v79 = v71->z;
        v135.buffer = (char *)(32 * LODWORD(v64) + v47);
        v80 = v71->y;
        v135.buffer = (char *)(32 * LODWORD(v63) + v47);
        v83 = (float)((float)v76
                    - (float)((float)((float)v60
                                    * (float)((float)((float)((float)(v149.a * (float)v58)
                                                            + (float)((float)(v149.b * (float)v56)
                                                                    + (float)(v149.c * (float)v55)))
                                                    + v149.d)
                                            / (float)((float)((float)((float)(v149.a * (float)v58)
                                                                    + (float)((float)(v149.b * (float)v56)
                                                                            + (float)(v149.c * (float)v55)))
                                                            + v149.d)
                                                    - (float)((float)((float)(v149.a * (float)v53)
                                                                    + (float)((float)(v149.b * (float)v51)
                                                                            + (float)(v149.c * (float)v54)))
                                                            + v149.d))))
                            + (float)v58));
        v84 = (float)((float)v77
                    - (float)((float)((float)v59
                                    * (float)((float)((float)((float)(v149.a * (float)v58)
                                                            + (float)((float)(v149.b * (float)v56)
                                                                    + (float)(v149.c * (float)v55)))
                                                    + v149.d)
                                            / (float)((float)((float)((float)(v149.a * (float)v58)
                                                                    + (float)((float)(v149.b * (float)v56)
                                                                            + (float)(v149.c * (float)v55)))
                                                            + v149.d)
                                                    - (float)((float)((float)(v149.a * (float)v53)
                                                                    + (float)((float)(v149.b * (float)v51)
                                                                            + (float)(v149.c * (float)v54)))
                                                            + v149.d))))
                            + (float)v56));
        v85 = (float)((float)v79
                    - (float)((float)((float)v57
                                    * (float)((float)((float)((float)(v149.a * (float)v58)
                                                            + (float)((float)(v149.b * (float)v56)
                                                                    + (float)(v149.c * (float)v55)))
                                                    + v149.d)
                                            / (float)((float)((float)((float)(v149.a * (float)v58)
                                                                    + (float)((float)(v149.b * (float)v56)
                                                                            + (float)(v149.c * (float)v55)))
                                                            + v149.d)
                                                    - (float)((float)((float)(v149.a * (float)v53)
                                                                    + (float)((float)(v149.b * (float)v51)
                                                                            + (float)(v149.c * (float)v54)))
                                                            + v149.d))))
                            + (float)v55));
        v87 = (float)((float)v78
                    - (float)((float)((float)v60
                                    * (float)((float)((float)((float)(v149.a * (float)v58)
                                                            + (float)((float)(v149.b * (float)v56)
                                                                    + (float)(v149.c * (float)v55)))
                                                    + v149.d)
                                            / (float)((float)((float)((float)(v149.a * (float)v58)
                                                                    + (float)((float)(v149.b * (float)v56)
                                                                            + (float)(v149.c * (float)v55)))
                                                            + v149.d)
                                                    - (float)((float)((float)(v149.a * (float)v53)
                                                                    + (float)((float)(v149.b * (float)v51)
                                                                            + (float)(v149.c * (float)v54)))
                                                            + v149.d))))
                            + (float)v58));
        v88 = (float)(v72->z
                    - (float)((float)((float)v57
                                    * (float)((float)((float)((float)(v149.a * (float)v58)
                                                            + (float)((float)(v149.b * (float)v56)
                                                                    + (float)(v149.c * (float)v55)))
                                                    + v149.d)
                                            / (float)((float)((float)((float)(v149.a * (float)v58)
                                                                    + (float)((float)(v149.b * (float)v56)
                                                                            + (float)(v149.c * (float)v55)))
                                                            + v149.d)
                                                    - (float)((float)((float)(v149.a * (float)v53)
                                                                    + (float)((float)(v149.b * (float)v51)
                                                                            + (float)(v149.c * (float)v54)))
                                                            + v149.d))))
                            + (float)v55));
        v89 = (float)((float)((float)((float)v80 - (float)((float)((float)v59 * (float)v75) + (float)v56))
                            * (float)((float)v78 - (float)((float)((float)v60 * (float)v75) + (float)v58)))
                    - (float)((float)((float)v76 - (float)((float)((float)v60 * (float)v75) + (float)v58))
                            * (float)((float)v77 - (float)((float)((float)v59 * (float)v75) + (float)v56))));
        v90 = (float)((float)((float)((float)v76 - (float)((float)((float)v60 * (float)v75) + (float)v58))
                            * (float)(v72->z - (float)((float)((float)v57 * (float)v75) + (float)v55)))
                    - (float)((float)((float)v79 - (float)((float)((float)v57 * (float)v75) + (float)v55))
                            * (float)((float)v78 - (float)((float)((float)v60 * (float)v75) + (float)v58))));
        v86 = (float)((float)v80
                    - (float)((float)((float)v59
                                    * (float)((float)((float)((float)(v149.a * (float)v58)
                                                            + (float)((float)(v149.b * (float)v56)
                                                                    + (float)(v149.c * (float)v55)))
                                                    + v149.d)
                                            / (float)((float)((float)((float)(v149.a * (float)v58)
                                                                    + (float)((float)(v149.b * (float)v56)
                                                                            + (float)(v149.c * (float)v55)))
                                                            + v149.d)
                                                    - (float)((float)((float)(v149.a * (float)v53)
                                                                    + (float)((float)(v149.b * (float)v51)
                                                                            + (float)(v149.c * (float)v54)))
                                                            + v149.d))))
                            + (float)v56));
        v91 = (float)((float)((float)((float)v79 - (float)((float)((float)v57 * (float)v75) + (float)v55))
                            * (float)((float)v77 - (float)((float)((float)v59 * (float)v75) + (float)v56)))
                    - (float)((float)((float)v80 - (float)((float)((float)v59 * (float)v75) + (float)v56))
                            * (float)(v72->z - (float)((float)((float)v57 * (float)v75) + (float)v55))));
        if ( (float)((float)((float)v91 * v149.a) + (float)((float)(v149.b * (float)v90) + (float)(v149.c * (float)v89))) > 0.0 )
        {
          if ( v52 <= 0.0 )
            goto LABEL_68;
          v92 = (float)((float)v90 * (float)v90);
          v93 = (float)(v72->y - v71->y);
          v135.buffer = (char *)(32 * LODWORD(v63) + v47);
          v94 = (float)(v72->x - v71->x);
          v135.buffer = (char *)(32 * LODWORD(v64) + v47);
          v95 = (float)(v72->z - v71->z);
          if ( (float)((float)((float)v89 * (float)v89) + (float)((float)((float)v91 * (float)v91) + (float)v92)) > (double)(float)((float)((float)((float)v95 * (float)v95) + (float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93))) * (float)((float)radius * (float)radius)) )
            goto LABEL_68;
          v96 = (float)((float)((float)(v72->z - v71->z) * (float)v88)
                      + (float)((float)((float)v94 * (float)v87) + (float)((float)v93 * (float)v84)));
          if ( v96 >= 0.0 )
          {
            if ( v96 <= (float)((float)((float)v95 * (float)v95)
                              + (float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93))) )
              goto LABEL_47;
            v100 = v71->y;
            v135.buffer = (char *)(32 * LODWORD(v65) + v47);
            v101 = (float)((float)((float)v100 - v70->y) * (float)v86);
            v135.buffer = (char *)(32 * LODWORD(v63) + v47);
            if ( (float)((float)((float)(v71->z - v70->z) * (float)v85)
                       + (float)((float)((float)(v71->x - v70->x) * (float)v83) + (float)v101)) >= 0.0 )
              goto LABEL_47;
            v99 = (float)((float)((float)v85 * (float)v85)
                        + (float)((float)((float)v83 * (float)v83) + (float)((float)v86 * (float)v86)));
          }
          else
          {
            v97 = v72->y;
            v135.buffer = (char *)(32 * LODWORD(v65) + v47);
            v98 = (float)((float)((float)v97 - v70->y) * (float)v84);
            v135.buffer = (char *)(32 * LODWORD(v64) + v47);
            if ( (float)((float)((float)(v72->z - v70->z) * (float)v88)
                       + (float)((float)((float)(v72->x - v70->x) * (float)v87) + (float)v98)) >= 0.0 )
              goto LABEL_47;
            v99 = (float)((float)((float)v88 * (float)v88)
                        + (float)((float)((float)v87 * (float)v87) + (float)((float)v84 * (float)v84)));
          }
          if ( v99 > v52 )
            goto LABEL_68;
        }
LABEL_47:
        v102 = (float)(v70->x
                     - (float)((float)((float)v60
                                     * (float)((float)((float)((float)(v149.a * (float)v58)
                                                             + (float)((float)(v149.b * (float)v56)
                                                                     + (float)(v149.c * (float)v55)))
                                                     + v149.d)
                                             / (float)((float)((float)((float)(v149.a * (float)v58)
                                                                     + (float)((float)(v149.b * (float)v56)
                                                                             + (float)(v149.c * (float)v55)))
                                                             + v149.d)
                                                     - (float)((float)((float)(v149.a * (float)v53)
                                                                     + (float)((float)(v149.b * (float)v51)
                                                                             + (float)(v149.c * (float)v54)))
                                                             + v149.d))))
                             + (float)v58));
        v135.buffer = (char *)(32 * LODWORD(v65) + v47);
        v103 = (float)(v70->z
                     - (float)((float)((float)v57
                                     * (float)((float)((float)((float)(v149.a * (float)v58)
                                                             + (float)((float)(v149.b * (float)v56)
                                                                     + (float)(v149.c * (float)v55)))
                                                     + v149.d)
                                             / (float)((float)((float)((float)(v149.a * (float)v58)
                                                                     + (float)((float)(v149.b * (float)v56)
                                                                             + (float)(v149.c * (float)v55)))
                                                             + v149.d)
                                                     - (float)((float)((float)(v149.a * (float)v53)
                                                                     + (float)((float)(v149.b * (float)v51)
                                                                             + (float)(v149.c * (float)v54)))
                                                             + v149.d))))
                             + (float)v55));
        v104 = (float)(v70->y
                     - (float)((float)((float)v59
                                     * (float)((float)((float)((float)(v149.a * (float)v58)
                                                             + (float)((float)(v149.b * (float)v56)
                                                                     + (float)(v149.c * (float)v55)))
                                                     + v149.d)
                                             / (float)((float)((float)((float)(v149.a * (float)v58)
                                                                     + (float)((float)(v149.b * (float)v56)
                                                                             + (float)(v149.c * (float)v55)))
                                                             + v149.d)
                                                     - (float)((float)((float)(v149.a * (float)v53)
                                                                     + (float)((float)(v149.b * (float)v51)
                                                                             + (float)(v149.c * (float)v54)))
                                                             + v149.d))))
                             + (float)v56));
        v105 = (float)((float)((float)(v70->y
                                     - (float)((float)((float)v59
                                                     * (float)((float)((float)((float)(v149.a * (float)v58)
                                                                             + (float)((float)(v149.b * (float)v56)
                                                                                     + (float)(v149.c * (float)v55)))
                                                                     + v149.d)
                                                             / (float)((float)((float)((float)(v149.a * (float)v58)
                                                                                     + (float)((float)(v149.b * (float)v56)
                                                                                             + (float)(v149.c * (float)v55)))
                                                                             + v149.d)
                                                                     - (float)((float)((float)(v149.a * (float)v53)
                                                                                     + (float)((float)(v149.b * (float)v51)
                                                                                             + (float)(v149.c * (float)v54)))
                                                                             + v149.d))))
                                             + (float)v56))
                             * (float)v83)
                     - (float)((float)v102 * (float)v86));
        v107 = (float)((float)((float)(v70->z - (float)((float)((float)v57 * (float)v75) + (float)v55)) * (float)v86)
                     - (float)((float)(v70->y - (float)((float)((float)v59 * (float)v75) + (float)v56)) * (float)v85));
        v81 = (float)((float)((float)v59
                            * (float)((float)((float)((float)(v149.a * (float)v58)
                                                    + (float)((float)(v149.b * (float)v56) + (float)(v149.c * (float)v55)))
                                            + v149.d)
                                    / (float)((float)((float)((float)(v149.a * (float)v58)
                                                            + (float)((float)(v149.b * (float)v56)
                                                                    + (float)(v149.c * (float)v55)))
                                                    + v149.d)
                                            - (float)((float)((float)(v149.a * (float)v53)
                                                            + (float)((float)(v149.b * (float)v51)
                                                                    + (float)(v149.c * (float)v54)))
                                                    + v149.d))))
                    + (float)v56);
        v82 = (float)((float)((float)v57 * (float)v75) + (float)v55);
        if ( (float)((float)((float)((float)((float)(v70->z - (float)v82) * (float)v86)
                                   - (float)((float)(v70->y - (float)v81) * (float)v85))
                           * v149.a)
                   + (float)((float)(v149.b
                                   * (float)((float)((float)v102 * (float)v85)
                                           - (float)((float)(v70->z - (float)v82) * (float)v83)))
                           + (float)(v149.c
                                   * (float)((float)((float)(v70->y - (float)v81) * (float)v83)
                                           - (float)((float)v102 * (float)v86))))) <= 0.0 )
          goto LABEL_57;
        if ( v52 <= 0.0 )
          goto LABEL_68;
        v106 = (float)((float)((float)v102 * (float)v85)
                     - (float)((float)(v70->z - (float)((float)((float)v57 * (float)v75) + (float)v55)) * (float)v83));
        v108 = (float)((float)v106 * (float)v106);
        v109 = (float)(v71->y - v70->y);
        v135.buffer = (char *)(32 * LODWORD(v65) + v47);
        v110 = (float)(v71->x - v70->x);
        v135.buffer = (char *)(32 * LODWORD(v63) + v47);
        v111 = (float)(v71->z - v70->z);
        v112 = (float)((float)((float)v105 * (float)v105) + (float)((float)((float)v107 * (float)v107) + (float)v108));
        v113 = (float)((float)((float)v111 * (float)v111)
                     + (float)((float)((float)v110 * (float)v110) + (float)((float)v109 * (float)v109)));
        if ( v112 > (float)((float)((float)((float)v111 * (float)v111)
                                  + (float)((float)((float)v110 * (float)v110) + (float)((float)v109 * (float)v109)))
                          * (float)((float)radius * (float)radius)) )
          goto LABEL_68;
        v114 = (float)((float)((float)(v71->z - v70->z) * (float)v85)
                     + (float)((float)((float)v110 * (float)v83) + (float)((float)v109 * (float)v86)));
        if ( v114 >= 0.0 )
        {
          if ( v114 <= v113 )
            goto LABEL_57;
          v118 = v70->y;
          v135.buffer = (char *)(32 * LODWORD(v64) + v47);
          v119 = (float)((float)((float)v118 - v72->y) * (float)v104);
          v135.buffer = (char *)(32 * LODWORD(v65) + v47);
          if ( (float)((float)((float)(v70->z - v72->z) * (float)v103)
                     + (float)((float)((float)(v70->x - v72->x) * (float)v102) + (float)v119)) >= 0.0 )
            goto LABEL_57;
          v117 = (float)((float)((float)v103 * (float)v103)
                       + (float)((float)((float)v102 * (float)v102) + (float)((float)v104 * (float)v104))) > v52;
        }
        else
        {
          v115 = v71->y;
          v135.buffer = (char *)(32 * LODWORD(v64) + v47);
          v116 = (float)((float)((float)v115 - v72->y) * (float)v86);
          v135.buffer = (char *)(32 * LODWORD(v63) + v47);
          if ( (float)((float)((float)(v71->z - v72->z) * (float)v85)
                     + (float)((float)((float)(v71->x - v72->x) * (float)v83) + (float)v116)) >= 0.0 )
            goto LABEL_57;
          v117 = (float)((float)((float)v85 * (float)v85)
                       + (float)((float)((float)v83 * (float)v83) + (float)((float)v86 * (float)v86))) > v52;
        }
        if ( v117 )
          goto LABEL_68;
LABEL_57:
        if ( (float)((float)((float)((float)((float)v104 * (float)v88) - (float)((float)v103 * (float)v84)) * v149.a)
                   + (float)((float)(v149.b
                                   * (float)((float)((float)v103 * (float)v87) - (float)((float)v102 * (float)v88)))
                           + (float)(v149.c
                                   * (float)((float)((float)v102 * (float)v84) - (float)((float)v104 * (float)v87))))) <= 0.0 )
          goto LABEL_67;
        if ( v52 > 0.0 )
        {
          v121 = (float)((float)((float)v103 * (float)v87) - (float)((float)v102 * (float)v88));
          v123 = (float)((float)v121 * (float)v121);
          v124 = (float)(v70->y - v72->y);
          v135.buffer = (char *)(32 * LODWORD(v64) + v47);
          v125 = (float)(v70->x - v72->x);
          v135.buffer = (char *)(32 * LODWORD(v65) + v47);
          v126 = (float)(v70->z - v72->z);
          v122 = (float)((float)((float)v104 * (float)v88) - (float)((float)v103 * (float)v84));
          v120 = (float)((float)((float)v102 * (float)v84) - (float)((float)v104 * (float)v87));
          if ( (float)((float)((float)v120 * (float)v120) + (float)((float)((float)v122 * (float)v122) + (float)v123)) <= (double)(float)((float)((float)((float)v126 * (float)v126) + (float)((float)((float)v125 * (float)v125) + (float)((float)v124 * (float)v124))) * (float)((float)radius * (float)radius)) )
          {
            v127 = (float)((float)((float)(v70->z - v72->z) * (float)v103)
                         + (float)((float)((float)v125 * (float)v102) + (float)((float)v124 * (float)v104)));
            if ( v127 >= 0.0 )
            {
              if ( v127 > (float)((float)((float)v126 * (float)v126)
                                + (float)((float)((float)v125 * (float)v125) + (float)((float)v124 * (float)v124))) )
              {
                v131 = v72->y;
                v135.buffer = (char *)(32 * LODWORD(v63) + v47);
                v132 = v71->y;
                v135.buffer = (char *)(32 * LODWORD(v64) + v47);
                if ( (float)((float)((float)(v72->z - v71->z) * (float)v88)
                           + (float)((float)((float)(v72->x - v71->x) * (float)v87)
                                   + (float)((float)((float)v131 - (float)v132) * (float)v84))) < 0.0 )
                {
                  v130 = (float)((float)((float)v88 * (float)v88)
                               + (float)((float)((float)v87 * (float)v87) + (float)((float)v84 * (float)v84)));
                  goto LABEL_66;
                }
              }
            }
            else
            {
              v128 = v70->y;
              v135.buffer = (char *)(32 * LODWORD(v63) + v47);
              v129 = v71->y;
              v135.buffer = (char *)(32 * LODWORD(v65) + v47);
              if ( (float)((float)((float)(v70->z - v71->z) * (float)v103)
                         + (float)((float)((float)(v70->x - v71->x) * (float)v102)
                                 + (float)((float)((float)v128 - (float)v129) * (float)v104))) < 0.0 )
              {
                v130 = (float)((float)((float)v103 * (float)v103)
                             + (float)((float)((float)v102 * (float)v102) + (float)((float)v104 * (float)v104)));
LABEL_66:
                if ( v130 > v52 )
                  goto LABEL_68;
              }
            }
LABEL_67:
            v139[0] = v75;
            v139[8] = v64;
            v139[4] = v149.a;
            v139[9] = v63;
            v139[5] = v149.b;
            v139[10] = v65;
            v139[6] = v149.c;
            v139[1] = (float)((float)v60 * (float)v75) + (float)v58;
            v139[2] = (float)((float)v59 * (float)v75) + (float)v56;
            v139[3] = (float)((float)v57 * (float)v75) + (float)v55;
          }
        }
LABEL_68:
        --v62;
        v61 += 3;
        if ( v62 == 0 )
          goto LABEL_69;
        v51 = v138;
        v53 = v136;
      }
    }
    if ( result->indexBuffer.size < 0 )
      idIndexBuffer::UnmapBuffer(this: &result->indexBuffer);
    memcpy(Dst: this, Src: v139, Size: 0x2Cu);
    if ( HIBYTE(v137.y) != 0 )
    {
      idTriangles::~idTriangles(this: (idTriangles *)LODWORD(v38));
      idMem::Free(this: &mem, ptr: (void *)LODWORD(v38), align: ALIGN_16);
    }
  }
  return this;
}


// ========================================================================
// __unwind$230012
// EA  : 0x82976FD4
// RVA : 0x00976FD4
// PDB : w:\tech5\engine\renderer\triangles_trace.cpp
// ========================================================================

void _unwind_230012()
{
  int v0; // r12

  idAutoStandardTriangles::~idAutoStandardTriangles(this: (idAutoStandardTriangles *)(v0 - 768 + 104));
}


// ========================================================================
// __unwind$230013_0
// EA  : 0x82976FFC
// RVA : 0x00976FFC
// PDB : w:\tech5\engine\renderer\triangles_trace.cpp
// ========================================================================

void _unwind_230013_0()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 768 + 88));
}

