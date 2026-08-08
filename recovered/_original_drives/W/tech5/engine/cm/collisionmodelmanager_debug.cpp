
// ========================================================================
// ContentsFromString
// EA  : 0x825D9CD8
// RVA : 0x005D9CD8
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

int __fastcall ContentsFromString(const char *string)
{
  int v2; // r26
  unsigned int v3; // r5
  int v4; // r30
  const char **v5; // r11
  idToken v7; // [sp+50h] [-120h] BYREF
  idLexer v8; // [sp+A0h] [-D0h] BYREF

  v2 = 0;
  idLexer::idLexer(this: &v8, flags_: 0);
  v3 = 0;
  if ( *string != 0 )
  {
    do
      ++v3;
    while ( string[v3] != 0 );
  }
  idLexer::LoadMemory(this: &v8, ptr: string, length_: v3, name: "ContentsFromString");
  v7.len = 0;
  v7.baseBuffer[0] = 0;
  v7.allocedAndFlag = 20;
  v7.data = v7.baseBuffer;
  v7.intvalue = 0;
  v7.floatvalue = -3.4028235e38;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  while ( idLexer::ReadToken(this: &v8, token: &v7) )
  {
    if ( idStr::Cmp(s1: v7.data, s2: ",") != 0 )
    {
      v4 = 0;
      if ( cm_contentsNameByIndex[0] != nullptr )
      {
        v5 = cm_contentsNameByIndex;
        while ( idStr::Icmp(s1: v7.data, s2: *v5) != 0 )
        {
          v5 = &cm_contentsNameByIndex[++v4];
          if ( *v5 == nullptr )
            goto LABEL_11;
        }
        v2 |= cm_contentsFlagByIndex[v4];
      }
    }
LABEL_11:
    ;
  }
  idStr::FreeData(this: &v7);
  idLexer::~idLexer(this: &v8);
  return v2;
}


// ========================================================================
// __unwind$223831
// EA  : 0x825D9E30
// RVA : 0x005D9E30
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void _unwind_223831()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 368 + 160));
}


// ========================================================================
// __unwind$223832
// EA  : 0x825D9E58
// RVA : 0x005D9E58
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void _unwind_223832()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 80));
}


// ========================================================================
// DrawEdge
// EA  : 0x825D9E80
// RVA : 0x005D9E80
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __fastcall DrawEdge(
        const cm_subModelPtrs_t *subModelPtrs,
        unsigned int edgeNum,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *viewOrigin,
        const idMat3 *viewAxis,
        double radius,
        int lifeTime)
{
  int v8; // r24
  cm_vertex_t *vertices; // r10
  char *v10; // r26
  double x; // fp11
  double y; // fp10
  double z; // fp9
  double v15; // fp8
  double v16; // fp7
  double v17; // fp6
  double v18; // fp5
  unsigned int v19; // r23
  double v20; // fp4
  double v21; // fp3
  float *v22; // r11
  double v23; // fp2
  double v24; // fp1
  double v26; // fp30
  int v27; // r30
  double v28; // fp12
  double v29; // fp13
  float *v30; // r11
  double v31; // fp4
  double v32; // fp3
  double v33; // fp30
  double v34; // fp29
  double v35; // fp28
  int (*RW)(void); // ctr
  int v37; // r3
  int v38; // r3
  int v39; // r7
  idVec4 *v40; // r4
  int (*v41)(void); // ctr
  int v42; // r3
  idRenderWorld *v43; // r3
  __int64 v44; // r10
  double v45; // fp9
  __int64 v46; // r8
  idRenderWorld *v47; // r20
  __int64 v48; // r6
  double valueFloat; // fp27
  double v50; // fp7
  bool v51; // r25
  va *v52; // r3
  idRenderWorld *v53; // r3
  double v54; // fp0
  __int64 v55; // r8
  idRenderWorld *v56; // r20
  double v57; // fp30
  bool v58; // r25
  double v59; // fp9
  __int64 v60; // r6
  __int64 v61; // r10
  va *v62; // r3
  idRenderWorld *v63; // r3
  double v64; // fp3
  double v65; // fp2
  idRenderWorld *v66; // r28
  __int64 v67; // r10
  double v68; // fp31
  bool v69; // r29
  __int64 v70; // r6
  __int64 v71; // r8
  va *v72; // r3
  int v73; // [sp+8h] [-1138h]
  int v74; // [sp+8h] [-1138h]
  int v75; // [sp+8h] [-1138h]
  int v76; // [sp+Ch] [-1134h]
  int v77; // [sp+Ch] [-1134h]
  int v78; // [sp+Ch] [-1134h]
  int v79; // [sp+10h] [-1130h]
  int v80; // [sp+10h] [-1130h]
  int v81; // [sp+10h] [-1130h]
  int v82; // [sp+14h] [-112Ch]
  int v83; // [sp+14h] [-112Ch]
  int v84; // [sp+14h] [-112Ch]
  int v85; // [sp+18h] [-1128h]
  int v86; // [sp+18h] [-1128h]
  int v87; // [sp+18h] [-1128h]
  int v88; // [sp+1Ch] [-1124h]
  int v89; // [sp+1Ch] [-1124h]
  int v90; // [sp+1Ch] [-1124h]
  float v91; // [sp+60h] [-10E0h] BYREF
  float v92; // [sp+64h] [-10DCh]
  float v93; // [sp+68h] [-10D8h]
  float v94; // [sp+70h] [-10D0h] BYREF
  float v95; // [sp+74h] [-10CCh]
  float v96; // [sp+78h] [-10C8h]
  float v97[4]; // [sp+80h] [-10C0h] BYREF
  float v98[4]; // [sp+90h] [-10B0h] BYREF
  float v99[4]; // [sp+A0h] [-10A0h] BYREF
  va v100; // [sp+B0h] [-1090h] BYREF

  v8 = (edgeNum >> 14) & 2;
  vertices = subModelPtrs->vertices;
  v10 = (char *)subModelPtrs->edges + ((4 * edgeNum) & 0xFFFC);
  x = axis->mat[1].x;
  y = axis->mat[1].y;
  z = axis->mat[1].z;
  v15 = axis->mat[0].x;
  v16 = axis->mat[0].y;
  v17 = axis->mat[0].z;
  v18 = axis->mat[2].x;
  v19 = ((unsigned int)~(unsigned __int16)edgeNum >> 14) & 2;
  v20 = axis->mat[2].y;
  v21 = axis->mat[2].z;
  v22 = (float *)((char *)&vertices->p.x + __ROL4__(*(unsigned __int16 *)&v10[v8], 4));
  v23 = origin->x;
  v24 = origin->y;
  v26 = origin->z;
  v27 = edgeNum & 0x3FFF;
  v28 = (float)((float)(axis->mat[2].z * v22[2])
              + (float)((float)(axis->mat[0].z * *v22) + (float)(axis->mat[1].z * v22[1])));
  v29 = (float)(origin->y
              + (float)((float)(axis->mat[2].y * v22[2])
                      + (float)((float)(axis->mat[0].y * *v22) + (float)(axis->mat[1].y * v22[1]))));
  v91 = origin->x
      + (float)((float)(axis->mat[2].x * v22[2])
              + (float)((float)(*v22 * axis->mat[0].x) + (float)(axis->mat[1].x * v22[1])));
  v92 = v29;
  v93 = (float)v26 + (float)v28;
  v30 = (float *)((char *)&vertices->p.x + __ROL4__(*(unsigned __int16 *)&v10[v19], 4));
  v31 = (float)((float)(v30[2] * (float)v20) + (float)((float)(*v30 * (float)v16) + (float)(v30[1] * (float)y)));
  v32 = (float)((float)(v30[2] * (float)v21) + (float)((float)(*v30 * (float)v17) + (float)(v30[1] * (float)z)));
  v94 = (float)v23
      + (float)((float)(v30[2] * (float)v18) + (float)((float)(*v30 * (float)v15) + (float)(v30[1] * (float)x)));
  v95 = (float)v24 + (float)v31;
  v96 = (float)v26 + (float)v32;
  v34 = (float)((float)(v95 + (float)v29) * (float)0.5);
  v35 = (float)((float)(v96 + v93) * (float)0.5);
  v33 = (float)((float)(v94 + v91) * (float)0.5);
  if ( (edgeNum & 0x4000) != 0 )
  {
    if ( cm_drawInternal.valueInteger == 0 )
      goto LABEL_10;
    RW = (int (*)(void))common->RW;
    if ( cm_drawArrows.valueInteger != 0 )
    {
      v37 = RW();
      (*(void (__fastcall **)(int, idColor *, float *, float *, int, const idMat3 *, bool, double))(*(_DWORD *)v37 + 180))(
        a1: v37,
        a2: &idColor::colorGreen,
        a3: &v91,
        a4: &v94,
        a5: cm_depthTest.valueInteger - 1,
        a6: viewAxis,
        a7: cm_depthTest.valueInteger != 0,
        a8: 1.0);
      goto LABEL_10;
    }
    v38 = RW();
    v39 = 1;
    v40 = (idVec4 *)&idColor::colorGreen;
  }
  else
  {
    v41 = (int (*)(void))common->RW;
    if ( cm_drawArrows.valueInteger != 0 )
    {
      v42 = v41();
      (*(void (__fastcall **)(int, idVec4 *, float *, float *, int, const idMat3 *, bool, double))(*(_DWORD *)v42 + 180))(
        a1: v42,
        a2: &cm_color,
        a3: &v91,
        a4: &v94,
        a5: cm_depthTest.valueInteger - 1,
        a6: viewAxis,
        a7: cm_depthTest.valueInteger != 0,
        a8: 1.0);
      goto LABEL_10;
    }
    v38 = v41();
    v39 = (int)viewAxis;
    v40 = &cm_color;
  }
  (*(void (__fastcall **)(int, idVec4 *, float *, float *, int, bool))(*(_DWORD *)v38 + 176))(
    a1: v38,
    a2: v40,
    a3: &v91,
    a4: &v94,
    a5: v39,
    a6: cm_depthTest.valueInteger != 0);
LABEL_10:
  if ( cm_drawIndices.valueInteger != 0 )
  {
    v43 = common->RW(this: common);
    HIDWORD(v44) = &idDeclReachIK::resourceList.hashTable[243];
    v45 = (float)(viewOrigin[2].z * (float)0.5);
    LODWORD(v46) = 0x82000000;
    v47 = v43;
    HIDWORD(v46) = cm_depthTest.valueInteger - 1;
    HIDWORD(v48) = v27;
    valueFloat = cm_drawIndexScale.valueFloat;
    v50 = (float)((float)(viewOrigin[2].y * (float)0.5) + (float)v34);
    v97[0] = (float)(viewOrigin[2].x * (float)0.5) + (float)v33;
    v97[1] = v50;
    v97[2] = (float)v45 + (float)v35;
    LODWORD(v44) = viewOrigin + 2;
    v51 = cm_depthTest.valueInteger != 0;
    v52 = va::va(
            this: &v100,
            fmt: "%d",
            a3: v48,
            a4: v46,
            a5: v44,
            a6: v73,
            a7: v76,
            a8: v79,
            a9: v82,
            a10: v85,
            a11: v88);
    ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, idColor *, const idVec3 *, const idMat3 *, bool, double))v47->DebugText_2)(
      a1: v47,
      a2: v52,
      a3: v97,
      a4: v47->__vftable,
      a5: &idColor::colorWhite,
      a6: viewOrigin,
      a7: viewAxis,
      a8: v51,
      a9: valueFloat);
    v53 = common->RW(this: common);
    v54 = (float)(viewOrigin[2].z * (float)0.5);
    LODWORD(v55) = cm_depthTest.valueInteger - 1;
    v56 = v53;
    v57 = cm_drawIndexScale.valueFloat;
    v58 = cm_depthTest.valueInteger != 0;
    v59 = (float)((float)(viewOrigin[2].y * (float)0.5) + v92);
    v99[0] = (float)(viewOrigin[2].x * (float)0.5) + v91;
    v99[1] = v59;
    v99[2] = (float)v54 + v93;
    HIDWORD(v60) = *(unsigned __int16 *)&v10[v8];
    v62 = va::va(
            this: &v100,
            fmt: "%d",
            a3: v60,
            a4: v55,
            a5: v61,
            a6: v74,
            a7: v77,
            a8: v80,
            a9: v83,
            a10: v86,
            a11: v89);
    ((void (__fastcall *)(idRenderWorld *, va *, float *, char *, idColor *, const idVec3 *, const idMat3 *, bool, double))v56->DebugText_2)(
      a1: v56,
      a2: v62,
      a3: v99,
      a4: &aAvSsobjectVCom[20],
      a5: &idColor::colorYellow,
      a6: viewOrigin,
      a7: viewAxis,
      a8: v58,
      a9: v57);
    v63 = common->RW(this: common);
    v64 = (float)(viewOrigin[2].y * (float)0.5);
    v65 = (float)(viewOrigin[2].z * (float)0.5);
    v66 = v63;
    LODWORD(v67) = cm_depthTest.valueInteger - 1;
    v69 = cm_depthTest.valueInteger != 0;
    v68 = cm_drawIndexScale.valueFloat;
    v98[0] = (float)(viewOrigin[2].x * (float)0.5) + v94;
    v98[1] = (float)v64 + v95;
    v98[2] = (float)v65 + v96;
    HIDWORD(v70) = *(unsigned __int16 *)&v10[v19];
    v72 = va::va(
            this: &v100,
            fmt: "%d",
            a3: v70,
            a4: v71,
            a5: v67,
            a6: v75,
            a7: v78,
            a8: v81,
            a9: v84,
            a10: v87,
            a11: v90);
    ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, idColor *, const idVec3 *, const idMat3 *, bool, double))v66->DebugText_2)(
      a1: v66,
      a2: v72,
      a3: v98,
      a4: v66->__vftable,
      a5: &idColor::colorYellow,
      a6: viewOrigin,
      a7: viewAxis,
      a8: v69,
      a9: v68);
  }
}


// ========================================================================
// DrawPolygon
// EA  : 0x825DA4E8
// RVA : 0x005DA4E8
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall DrawPolygon(
        const cm_subModelPtrs_t *subModelPtrs,
        const cm_polygon_t *p,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *viewOrigin,
        const idMat3 *viewAxis,
        double radius,
        const idMat3 *lifeTime)
{
  int v15; // r2 OVERLAPPED
  double v16; // fp1
  double c; // fp30
  double b; // fp29
  double a; // fp28
  float *v20; // r11
  int numEdges; // r5
  double v22; // fp12
  double v23; // fp13
  double v24; // fp0
  __int64 v25; // r11
  int firstEdge; // r9
  unsigned __int16 *polygonEdges; // r8
  cm_edge_t *edges; // r7
  cm_vertex_t *vertices; // r6
  int v30; // r4
  double z; // fp9
  double y; // fp5
  double v33; // fp2
  double v34; // fp23
  double v35; // fp22
  double v36; // fp13
  double v37; // fp12
  double v38; // fp4
  double v39; // fp0
  double v40; // fp5
  double v41; // fp8
  double v42; // fp10
  double v43; // fp9
  double v44; // fp7
  int (*RW)(void); // ctr
  int v46; // r3
  int v47; // r3
  int v48; // r29
  unsigned int v49; // r6
  double x; // fp3
  float *v51; // r11
  double v52; // fp6
  double v53; // fp4
  __int64 v54; // r7
  __int64 v55; // r5
  unsigned __int8 *v56; // r11
  int v57; // r3
  idRenderWorld *v58; // r3
  int v59; // r29
  unsigned int v60; // r4
  unsigned __int8 *edgeCheckCounts; // r10
  int v62; // r11
  char v63; // r7
  int v64; // r5
  __int64 v65; // r11
  int v66; // r3
  double v67; // fp12
  double v68; // fp13
  double v69; // fp0
  int v70; // r4
  unsigned __int16 *v71; // r7
  cm_vertex_t *v72; // r9
  unsigned int v73; // ctr
  int v74; // r5
  unsigned __int16 *v75; // r6
  int v76; // r8
  int v77; // r27
  float *v78; // r8
  float *v79; // r8
  float *v80; // r8
  float *v81; // r8
  int v82; // r8
  unsigned __int16 *v83; // r7
  cm_edge_t *v84; // r6
  cm_vertex_t *v85; // r5
  int v86; // ctr
  int v87; // r9
  double v88; // fp10
  double v89; // fp26
  double v90; // fp25
  double v91; // fp13
  double v92; // fp0
  double v93; // fp12
  double v94; // fp11
  double v95; // fp6
  double v96; // fp13
  double v97; // fp2
  double v98; // fp1
  idRenderWorld *v99; // r3
  __int64 v100; // r8
  __int64 v101; // r10
  __int64 v102; // r6
  idRenderWorld *v103; // r29
  bool v104; // r30
  double valueFloat; // fp31
  va *v106; // r3
  int v107; // [sp+8h] [-1698h]
  int v108; // [sp+Ch] [-1694h]
  int v109; // [sp+10h] [-1690h]
  int v110; // [sp+14h] [-168Ch]
  int v111; // [sp+18h] [-1688h]
  int v112; // [sp+1Ch] [-1684h]
  float v113; // [sp+60h] [-1640h] BYREF
  float v114; // [sp+64h] [-163Ch]
  float v115; // [sp+68h] [-1638h]
  idVec3 v116; // [sp+70h] [-1630h] BYREF
  float v117; // [sp+80h] [-1620h] BYREF
  float v118; // [sp+84h] [-161Ch]
  float v119; // [sp+88h] [-1618h]
  float v120[4]; // [sp+90h] [-1610h] BYREF
  idVec4 v121; // [sp+A0h] [-1600h] BYREF
  idPlane v122; // [sp+B0h] [-15F0h] BYREF
  idWinding v123; // [sp+C0h] [-15E0h] BYREF
  int v124; // [sp+D0h] [-15D0h] BYREF
  va v125; // [sp+5D0h] [-10D0h] BYREF

  CM_GetPolygonPlane(subModel: subModelPtrs, polygon: p, plane: &v122);
  c = v122.c;
  b = v122.b;
  a = v122.a;
  if ( cm_backFaceCull.valueInteger == 0
    || (float)((float)((float)(*(v20 = (float *)((char *)&subModelPtrs->vertices->p.x
                                               + __ROL4__(
                                                   *(unsigned __int16 *)((char *)subModelPtrs->edges->vertexNum
                                                                       + ((4
                                                                         * *(unsigned __int16 *)((char *)subModelPtrs->polygonEdges
                                                                                               + __ROL4__(
                                                                                                   p->firstEdge,
                                                                                                   1)))
                                                                        & 0xFFFC)),
                                                   4)))
                             - viewOrigin->x)
                     * v122.a)
             + (float)((float)(v122.b * (float)(v20[1] - viewOrigin->y))
                     + (float)(v122.c * (float)(v20[2] - viewOrigin->z)))) <= 0.0 )
  {
    if ( cm_drawNormals.valueFloat != 0.0 )
    {
      numEdges = p->numEdges;
      v119 = 0.0;
      v118 = 0.0;
      v22 = 0.0;
      v117 = 0.0;
      v23 = 0.0;
      v24 = 0.0;
      HIDWORD(v25) = 0;
      if ( numEdges > 0 )
      {
        firstEdge = p->firstEdge;
        polygonEdges = subModelPtrs->polygonEdges;
        edges = subModelPtrs->edges;
        vertices = subModelPtrs->vertices;
        do
        {
          v30 = firstEdge + HIDWORD(v25)++;
          LODWORD(v25) = (char *)vertices
                       + __ROL4__(
                           *(unsigned __int16 *)((char *)edges->vertexNum
                                               + ((4 * polygonEdges[v30]) & 0xFFFC)
                                               + ((polygonEdges[v30] >> 14) & 2)),
                           4);
          v24 = (float)((float)v24 + *(float *)v25);
          v117 = v24;
          v23 = (float)(*(float *)(v25 + 4) + (float)v23);
          v118 = v23;
          v22 = (float)(*(float *)(v25 + 8) + (float)v22);
          v119 = v22;
        }
        while ( SHIDWORD(v25) < numEdges );
      }
      LODWORD(v25) = numEdges;
      z = axis->mat[1].z;
      y = axis->mat[1].y;
      v33 = (float)(v122.b * axis->mat[1].z);
      *(_QWORD *)&v116.x = v25;
      v34 = origin->z;
      v35 = origin->y;
      v36 = (float)((float)v23 * (float)((float)1.0 / (float)v25));
      v37 = (float)((float)v22 * (float)((float)1.0 / (float)v25));
      v38 = (float)((float)((float)1.0 / (float)v25) * (float)v24);
      v41 = (float)((float)((float)(axis->mat[0].x * v122.a)
                          + (float)((float)(v122.c * axis->mat[2].x) + (float)(v122.b * axis->mat[1].x)))
                  * cm_drawNormals.valueFloat);
      v42 = (float)((float)(axis->mat[0].z * (float)((float)((float)1.0 / (float)v25) * (float)v24))
                  + (float)((float)((float)v37 * axis->mat[2].z) + (float)((float)v36 * (float)z)));
      v43 = (float)((float)(axis->mat[0].y * (float)((float)((float)1.0 / (float)v25) * (float)v24))
                  + (float)((float)((float)v37 * axis->mat[2].y) + (float)((float)v36 * (float)y)));
      v39 = (float)((float)(axis->mat[0].y * v122.a)
                  + (float)((float)(v122.c * axis->mat[2].y) + (float)(v122.b * (float)y)));
      v40 = (float)((float)((float)(axis->mat[0].z * v122.a) + (float)((float)(v122.c * axis->mat[2].z) + (float)v33))
                  * cm_drawNormals.valueFloat);
      v44 = (float)(origin->x
                  + (float)((float)(axis->mat[0].x * (float)v38)
                          + (float)((float)((float)v37 * axis->mat[2].x) + (float)((float)v36 * axis->mat[1].x))));
      v117 = origin->x
           + (float)((float)(axis->mat[0].x * (float)v38)
                   + (float)((float)((float)v37 * axis->mat[2].x) + (float)((float)v36 * axis->mat[1].x)));
      v119 = (float)v34 + (float)v42;
      v118 = (float)v35 + (float)v43;
      v120[0] = (float)v41 + (float)v44;
      v120[2] = (float)v40 + v119;
      v120[1] = (float)((float)v39 * cm_drawNormals.valueFloat) + v118;
      RW = (int (*)(void))common->RW;
      if ( cm_drawArrows.valueInteger != 0 )
      {
        v46 = RW();
        (*(void (__fastcall **)(int, idColor *, float *, float *, double))(*(_DWORD *)v46 + 180))(
          a1: v46,
          a2: &idColor::colorMagenta,
          a3: &v117,
          a4: v120,
          a5: 1.0);
      }
      else
      {
        v47 = RW();
        (*(void (__fastcall **)(int, idColor *, float *, float *, const idMat3 *, bool))(*(_DWORD *)v47 + 176))(
          a1: v47,
          a2: &idColor::colorMagenta,
          a3: &v117,
          a4: v120,
          a5: lifeTime,
          a6: cm_depthTest.valueInteger != 0);
      }
    }
    if ( cm_drawFilled.valueInteger != 0 )
    {
      v123.numPoints = 0;
      v123.p = (idVec5 *)&v124;
      v123.__vftable = (idWinding_vtbl *)&idFixedWinding::`vftable';
      v123.allocedSize = 64;
      v48 = p->numEdges - 1;
      if ( p->numEdges != 0 )
      {
        do
        {
          v49 = subModelPtrs->polygonEdges[p->firstEdge + v48];
          x = origin->x;
          v51 = (float *)((char *)&subModelPtrs->vertices->p.x
                        + __ROL4__(
                            *(unsigned __int16 *)((char *)subModelPtrs->edges->vertexNum
                                                + ((4 * v49) & 0xFFFC)
                                                + ((v49 >> 14) & 2)),
                            4));
          v52 = (float)((float)(axis->mat[2].x * v51[2])
                      + (float)((float)(axis->mat[0].x * *v51) + (float)(axis->mat[1].x * v51[1])));
          v53 = (float)(origin->y
                      + (float)((float)(v51[2] * axis->mat[2].y)
                              + (float)((float)(*v51 * axis->mat[0].y) + (float)(v51[1] * axis->mat[1].y))));
          v116.z = origin->z
                 + (float)((float)(axis->mat[2].z * v51[2])
                         + (float)((float)(axis->mat[0].z * *v51) + (float)(axis->mat[1].z * v51[1])));
          v116.y = v53;
          v116.x = (float)x + (float)v52;
          idWinding::AddPoint(this: &v123, v: &v116);
          --v48;
        }
        while ( v48 >= 0 );
      }
      *(float *)&v54 = cm_color.x;
      v55 = __PAIR64__(LODWORD(cm_color.z), LODWORD(cm_color.y));
      v121 = cm_color;
      if ( cm_drawSurfaceColor.valueInteger != 0 )
      {
        v56 = (unsigned __int8 *)subModelPtrs->materials + __ROL4__(p->material, 4);
        LODWORD(v54) = v56[12];
        *(_QWORD *)&v116.x = v54;
        v121.x = (float)v54 * (float)0.0039215689;
        LODWORD(v55) = v56[13];
        *(_QWORD *)&v116.x = v55;
        v121.y = (float)v55 * (float)0.0039215689;
        v57 = v56[14];
        v121.w = 1.0;
        *(_QWORD *)&v116.x = *(_QWORD *)(&v15 - 1);
        v121.z = (float)*(__int64 *)(&v15 - 1) * (float)0.0039215689;
      }
      v58 = common->RW(this: common);
      v58->DebugFilledPolygon(
        this: v58,
        a2: &v121,
        a3: &v123,
        a4: (const int)lifeTime,
        a5: cm_depthTest.valueInteger != 0);
      v123.p = nullptr;
      v123.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
      idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
      v123.p = nullptr;
    }
    else
    {
      v59 = 0;
      if ( p->numEdges != 0 )
      {
        do
        {
          v60 = subModelPtrs->polygonEdges[p->firstEdge + v59];
          edgeCheckCounts = baseTraceWork->modelCheckCounts.edgeCheckCounts;
          v62 = (int)(v60 & 0x3FFF) >> 3;
          v63 = 1 << (v60 & 7);
          v64 = (unsigned __int8)(edgeCheckCounts[v62] & v63);
          edgeCheckCounts[v62] |= v63;
          if ( v64 == 0 )
            DrawEdge(
              subModelPtrs,
              edgeNum: v60,
              origin,
              axis,
              viewOrigin: viewAxis->mat,
              viewAxis: lifeTime,
              radius: v16,
              lifeTime: v64 != 0);
          ++v59;
        }
        while ( v59 < p->numEdges );
      }
    }
    HIDWORD(v65) = &cm_drawIndices;
    if ( cm_drawIndices.valueInteger != 0 )
    {
      v66 = p->numEdges;
      v115 = 0.0;
      v114 = 0.0;
      v67 = 0.0;
      LODWORD(v65) = v66 - 1;
      v113 = 0.0;
      v68 = 0.0;
      v69 = 0.0;
      if ( v66 != 0 )
      {
        HIDWORD(v65) = v66;
        if ( v66 >= 4 )
        {
          v70 = p->firstEdge;
          v71 = subModelPtrs->polygonEdges;
          v72 = subModelPtrs->vertices;
          v73 = (unsigned int)v66 >> 2;
          HIDWORD(v65) = subModelPtrs->edges;
          do
          {
            v74 = v65 + v70 - 2;
            v75 = &v71[v65 + v70];
            v76 = v65 + v70 - 3;
            LODWORD(v65) = v65 - 4;
            v77 = v76;
            v78 = (float *)((char *)&v72->p.x
                          + __ROL4__(
                              *(unsigned __int16 *)(2 * (((2 * *v75) & 0x7FFE) + (*v75 >> 15)) + HIDWORD(v65)),
                              4));
            v113 = (float)v69 + *v78;
            v114 = v78[1] + (float)v68;
            v115 = v78[2] + (float)v67;
            v79 = (float *)((char *)&v72->p.x
                          + __ROL4__(
                              *(unsigned __int16 *)(2 * (((2 * *(v75 - 1)) & 0x7FFE) + (*(v75 - 1) >> 15)) + HIDWORD(v65)),
                              4));
            v113 = v113 + *v79;
            v114 = v79[1] + v114;
            v115 = v79[2] + v115;
            v80 = (float *)((char *)&v72->p.x
                          + __ROL4__(
                              *(unsigned __int16 *)(2 * (((2 * v71[v74]) & 0x7FFE) + (v71[v74] >> 15)) + HIDWORD(v65)),
                              4));
            v113 = v113 + *v80;
            v114 = v80[1] + v114;
            v115 = v80[2] + v115;
            v81 = (float *)((char *)&v72->p.x
                          + __ROL4__(
                              *(unsigned __int16 *)(2 * (((2 * v71[v77]) & 0x7FFE) + (v71[v77] >> 15)) + HIDWORD(v65)),
                              4));
            v69 = (float)(v113 + *v81);
            v113 = v113 + *v81;
            v68 = (float)(v81[1] + v114);
            v114 = v81[1] + v114;
            v67 = (float)(v81[2] + v115);
            v115 = v81[2] + v115;
            --v73;
          }
          while ( v73 != 0 );
        }
        if ( (int)v65 >= 0 )
        {
          v82 = p->firstEdge;
          v83 = subModelPtrs->polygonEdges;
          v84 = subModelPtrs->edges;
          v85 = subModelPtrs->vertices;
          v86 = v65 + 1;
          do
          {
            v87 = v65 + v82;
            LODWORD(v65) = v65 - 1;
            HIDWORD(v65) = (char *)v85 + __ROL4__(v84->vertexNum[((2 * v83[v87]) & 0x7FFE) + (v83[v87] >> 15)], 4);
            v69 = (float)((float)v69 + *(float *)HIDWORD(v65));
            v113 = v69;
            v68 = (float)(*(float *)(HIDWORD(v65) + 4) + (float)v68);
            v114 = v68;
            v67 = (float)(*(float *)(HIDWORD(v65) + 8) + (float)v67);
            v115 = v67;
            --v86;
          }
          while ( v86 != 0 );
        }
      }
      LODWORD(v65) = v66;
      v88 = axis->mat[2].x;
      *(_QWORD *)&v116.x = v65;
      v89 = origin->y;
      v90 = origin->z;
      v91 = (float)((float)v68 * (float)((float)1.0 / (float)v65));
      v92 = (float)((float)((float)1.0 / (float)v65) * (float)v69);
      v93 = (float)((float)v67 * (float)((float)1.0 / (float)v65));
      v94 = (float)((float)((float)((float)v93 * (float)c)
                          + (float)((float)((float)v92 * (float)a) + (float)((float)v91 * (float)b)))
                  + v122.d);
      v95 = (float)((float)v93
                  - (float)((float)c
                          * (float)((float)((float)((float)v93 * (float)c)
                                          + (float)((float)((float)v92 * (float)a) + (float)((float)v91 * (float)b)))
                                  + v122.d)));
      v96 = (float)((float)v91
                  - (float)((float)b
                          * (float)((float)((float)((float)v93 * (float)c)
                                          + (float)((float)((float)v92 * (float)a) + (float)((float)v91 * (float)b)))
                                  + v122.d)));
      v97 = (float)((float)(axis->mat[0].y * (float)((float)v92 - (float)((float)v94 * (float)a)))
                  + (float)((float)(axis->mat[1].y * (float)v96) + (float)(axis->mat[2].y * (float)v95)));
      v98 = (float)((float)(axis->mat[0].z * (float)((float)v92 - (float)((float)v94 * (float)a)))
                  + (float)((float)(axis->mat[1].z * (float)v96) + (float)(axis->mat[2].z * (float)v95)));
      v113 = origin->x
           + (float)((float)(axis->mat[0].x * (float)((float)v92 - (float)((float)v94 * (float)a)))
                   + (float)((float)(axis->mat[1].x * (float)v96) + (float)((float)v88 * (float)v95)));
      v114 = (float)v89 + (float)v97;
      v115 = (float)v90 + (float)v98;
      v99 = common->RW(this: common);
      LODWORD(v100) = &idDeclReachIK::resourceList.hashTable[243];
      HIDWORD(v100) = subModelPtrs->polygons;
      LODWORD(v101) = &cm_drawIndexScale;
      LODWORD(v102) = 0x82000000;
      HIDWORD(v101) = (char *)p - HIDWORD(v100);
      v103 = v99;
      v104 = cm_depthTest.valueInteger != 0;
      valueFloat = cm_drawIndexScale.valueFloat;
      HIDWORD(v102) = ((int)p - HIDWORD(v100)) >> 4;
      v106 = va::va(
               this: &v125,
               fmt: "%d",
               a3: v102,
               a4: v100,
               a5: v101,
               a6: v107,
               a7: v108,
               a8: v109,
               a9: v110,
               a10: v111,
               a11: v112);
      ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, idColor *, const idMat3 *, const idMat3 *, bool, double))v103->DebugText_2)(
        a1: v103,
        a2: v106,
        a3: &v113,
        a4: v103->__vftable,
        a5: &idColor::colorMagenta,
        a6: viewAxis,
        a7: lifeTime,
        a8: v104,
        a9: valueFloat);
    }
  }
}


// ========================================================================
// __unwind$224809
// EA  : 0x825DADE4
// RVA : 0x005DADE4
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void _unwind_224809()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 5792 + 192));
}


// ========================================================================
// DrawNodePolygons
// EA  : 0x825DAE10
// RVA : 0x005DAE10
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __fastcall DrawNodePolygons(
        const cm_subModelPtrs_t *subModelPtrs,
        __int64 origin,
        const idMat3 *axis,
        const idVec3 *viewOrigin,
        const idMat3 *viewAxis,
        double radius,
        int lifeTime,
        const idMat3 *a8)
{
  float *v11; // r29
  const idVec3 *v12; // r25
  int v16; // r27
  int v17; // r8
  const cm_polygon_t *v18; // r30
  int v19; // r9
  const idVec3 *v20; // r10
  const cm_polygon_t *v21; // r11
  unsigned __int8 *polygonCheckCounts; // r11
  double v23; // fp13

  v11 = (float *)HIDWORD(origin);
  v12 = (const idVec3 *)origin;
  while ( 1 )
  {
    v16 = 0;
    if ( *((_BYTE *)v11 + 14) != 0 )
    {
      do
      {
        v17 = subModelPtrs->primitiveIndices[*((unsigned __int16 *)v11 + 6) + v16];
        v18 = (cm_polygon_t *)((char *)subModelPtrs->polygons + __ROL4__(v17, 4));
        if ( radius == 0.0 )
        {
LABEL_10:
          LODWORD(origin) = (unsigned __int8)(1 << (v17 & 7));
          polygonCheckCounts = baseTraceWork->modelCheckCounts.polygonCheckCounts;
          HIDWORD(origin) = polygonCheckCounts[v17 >> 3];
          polygonCheckCounts[v17 >> 3] |= origin;
          if ( (HIDWORD(origin) & (unsigned int)origin) == 0 )
          {
            if ( (cm_drawMask.flags & 0x20000) != 0 )
            {
              dword_835A9580 = ContentsFromString(string: cm_drawMask.valueString.data);
              cm_drawMask.flags &= ~0x20000u;
            }
            if ( (*(int *)((_BYTE *)&subModelPtrs->materials->contentFlags + __ROL4__(v18->material, 4)) & dword_835A9580) != 0 )
              DrawPolygon(subModelPtrs, p: v18, origin: v12, axis, viewOrigin, viewAxis, radius, lifeTime: a8);
          }
        }
        else
        {
          v19 = 0;
          v20 = viewOrigin;
          v21 = v18;
          while ( 1 )
          {
            LODWORD(origin) = v21->bounds.b[0][0];
            if ( (float)origin > (double)(float)(v20->x + (float)radius) )
              break;
            LODWORD(origin) = v21->bounds.b[1][0];
            if ( (float)origin < (double)(float)(v20->x - (float)radius) )
              break;
            ++v19;
            v21 = (const cm_polygon_t *)((char *)v21 + 2);
            v20 = (const idVec3 *)((char *)v20 + 4);
            if ( v19 >= 3 )
              goto LABEL_10;
          }
        }
        ++v16;
      }
      while ( v16 < *((unsigned __int8 *)v11 + 14) );
    }
    if ( *(_DWORD *)v11 == -1 )
      break;
    if ( radius == 0.0 )
      goto LABEL_22;
    v23 = *(&viewOrigin->x + *(_DWORD *)v11);
    if ( v23 <= (float)(v11[1] + (float)radius) )
    {
      if ( v23 >= (float)(v11[1] - (float)radius) )
      {
LABEL_22:
        DrawNodePolygons(
          subModelPtrs,
          node: (const cm_node_t *)((char *)subModelPtrs->nodes + __ROL4__(*((unsigned __int16 *)v11 + 5), 4)),
          origin: v12,
          axis,
          viewOrigin,
          viewAxis,
          radius,
          lifeTime: (int)subModelPtrs->nodes);
        v11 = (float *)((char *)&subModelPtrs->nodes->planeType + __ROL4__(*((unsigned __int16 *)v11 + 4), 4));
      }
      else
      {
        v11 = (float *)((char *)&subModelPtrs->nodes->planeType + __ROL4__(*((unsigned __int16 *)v11 + 5), 4));
      }
    }
    else
    {
      v11 = (float *)((char *)&subModelPtrs->nodes->planeType + __ROL4__(*((unsigned __int16 *)v11 + 4), 4));
    }
  }
}


// ========================================================================
// ?DrawCollisionModel@idCollisionModelManager@@QAAXPAVidCollisionModel@@PBVidJointMat@@ABVidVec3@@ABVidMat3@@23MH@Z
// EA  : 0x825DB088
// RVA : 0x005DB088
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __fastcall idCollisionModelManager::DrawCollisionModel(
        idCollisionModelManager *this,
        idCollisionModel *model,
        const idJointMat *modelJoints,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis,
        const idVec3 *viewOrigin,
        const idMat3 *viewAxis,
        double radius,
        int lifeTime,
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
        int a28,
        int a29)
{
  int v36; // r3
  double v37; // fp5
  double v38; // fp10
  double v39; // fp7
  double v40; // fp3
  double v41; // fp2
  int v42; // r12
  int SubModelsForTrace; // r3
  int v44; // r20
  int *v45; // r28
  int i; // r29
  idRenderWorld *v47; // r3
  idMat3 *v48; // r26
  int j; // r24
  const cm_subModel_t *v50; // r28
  const cm_subModelData_t *v51; // r3
  const cm_subModelData_t *v52; // r29
  const idMat3 *v53; // r9
  double v54; // fp1
  int v55; // r23
  int v56; // r29
  int v57; // r28
  unsigned __int8 *v58; // r11
  __int64 v59; // r9
  double y; // fp0
  double x; // fp13
  double z; // fp12
  double v63; // fp11
  double v64; // fp10
  float *v65; // r11
  double v66; // fp9
  double v67; // fp8
  double v68; // fp7
  double v69; // fp6
  double v70; // fp3
  double v71; // fp4
  double v72; // fp1
  double v73; // fp11
  double v74; // fp2
  __int64 v75; // r6
  double v76; // fp28
  double v77; // fp29
  double v78; // fp30
  double v79; // fp27
  double v80; // fp26
  double v81; // fp25
  double v82; // fp3
  double v83; // fp1
  double v84; // fp4
  double v85; // fp5
  double v86; // fp11
  double v87; // fp2
  double v88; // fp24
  double v89; // fp28
  double v90; // fp22
  double v91; // fp10
  double v92; // fp9
  double v93; // fp3
  double v94; // fp0
  double v95; // fp8
  idRenderWorld *v96; // r3
  const idMat3 *back_chain[19]; // [sp+0h] [-1D0h]
  int v98; // [sp+4Ch] [-184h] BYREF
  idMat3 v99; // [sp+50h] [-180h] BYREF
  float v100; // [sp+74h] [-15Ch]
  float v101; // [sp+78h] [-158h]
  float v102; // [sp+7Ch] [-154h]
  float v103[4]; // [sp+80h] [-150h] BYREF
  cm_sphereModelPtrs_t v104; // [sp+90h] [-140h] BYREF
  __int64 v105; // [sp+A8h] [-128h]
  __int64 v106; // [sp+B0h] [-120h]
  __int64 v107; // [sp+B8h] [-118h]
  idBox v108[2]; // [sp+C0h] [-110h] BYREF

  if ( common->Game(this: common) != nullptr && common->RW(this: common) != nullptr )
  {
    if ( (cm_drawColor.flags & 0x20000) != 0 )
    {
      v36 = sscanf(
              string: cm_drawColor.valueString.data,
              format: "%f %f %f %f",
              &cm_color,
              &cm_color.y,
              &cm_color.z,
              &cm_color.w);
      cm_drawColor.flags &= ~0x20000u;
      ignoredReturnValue = v36;
    }
    if ( model->GetModelType(this: model) != CM_POLYGONMODEL )
    {
      if ( model->GetModelType(this: model) == CM_SPHEREMODEL )
      {
        v55 = idSphereModelCollisionDetection::SetupCollisionSpherePtrs(
                csData: *((const cm_sphereModel_t **)&model[2].idResource + 8),
                csPtrs: &v104);
        if ( v55 > 0 )
        {
          v56 = 1;
          v57 = 0;
          v58 = v104.joint + 1;
          do
          {
            HIDWORD(v59) = v104.offsetY;
            y = modelAxis->mat[0].y;
            x = modelAxis->mat[1].x;
            z = modelAxis->mat[1].z;
            v63 = v104.offsetY[v57];
            v64 = v104.offsetZ[v57];
            LODWORD(v59) = (-(v56 & 1) & ~(v56 & 1u)) >> 31;
            v65 = &modelJoints->mat[4 * *(v58 - 1) + 4 * __ROL4__(*(v58 - 1), 1)];
            v66 = v104.offsetX[v57];
            v107 = v59;
            v67 = modelAxis->mat[1].y;
            v68 = modelAxis->mat[2].x;
            v69 = modelAxis->mat[2].z;
            v70 = (float)(v65[1] * (float)v63);
            v71 = (float)(v65[5] * (float)v63);
            v72 = v65[2];
            v73 = (float)(v65[9] * (float)v63);
            v74 = v65[6];
            HIDWORD(v75) = -(v56 & 2) & ~(v56 & 2);
            v76 = v65[10];
            HIDWORD(v59) = -(v56 & 4) & ~(v56 & 4);
            v77 = *v65;
            LODWORD(v59) = HIDWORD(v75) >> 31;
            v78 = v65[4];
            v79 = v65[3];
            v106 = v59;
            v80 = v65[7];
            LODWORD(v75) = HIDWORD(v59) >> 31;
            v81 = v65[8];
            v82 = (float)((float)((float)v72 * (float)v64) + (float)v70);
            v83 = v65[11];
            v84 = (float)((float)((float)v74 * (float)v64) + (float)v71);
            v85 = modelAxis->mat[2].y;
            v86 = (float)((float)((float)v76 * (float)v64) + (float)v73);
            v102 = v104.radius[v57];
            v87 = modelAxis->mat[0].x;
            v88 = modelAxis->mat[0].z;
            v89 = modelOrigin->x;
            v90 = modelOrigin->z;
            v91 = (float)((float)((float)v78 * (float)v66) + (float)v84);
            v93 = (float)((float)((float)((float)v77 * (float)v66) + (float)v82) + (float)v79);
            v94 = (float)((float)((float)v67
                                * (float)((float)((float)((float)v78 * (float)v66) + (float)v84) + (float)v80))
                        + (float)((float)y * (float)v93));
            v92 = (float)((float)((float)v81 * (float)v66) + (float)v86);
            v95 = (float)(modelOrigin->y + (float)((float)((float)v85 * (float)((float)v92 + (float)v83)) + (float)v94));
            v103[0] = (float)v107;
            v105 = v75;
            v100 = v95;
            v99.mat[2].z = (float)v89
                         + (float)((float)((float)v87 * (float)v93)
                                 + (float)((float)((float)((float)v92 + (float)v83) * (float)v68)
                                         + (float)((float)x * (float)((float)v91 + (float)v80))));
            v101 = (float)v90
                 + (float)((float)((float)v93 * (float)v88)
                         + (float)((float)((float)v69 * (float)((float)v92 + (float)v83))
                                 + (float)((float)z * (float)((float)v91 + (float)v80))));
            v103[3] = 1.0;
            v103[1] = (float)v59;
            v103[2] = (float)v75;
            v96 = common->RW(this: common);
            v96->DebugSphere(
              this: v96,
              a2: (const idVec4 *)v103,
              a3: (const idSphere *)&v99.mat[2].z,
              a4: 12,
              a5: a29,
              a6: cm_depthTest.valueInteger != 0);
            ++v56;
            ++v57;
            v58 = &v104.joint[v56];
          }
          while ( v56 - 1 < v55 );
        }
      }
    }
    else
    {
      v37 = (float)(viewOrigin->x - modelOrigin->x);
      v38 = modelAxis->mat[2].x;
      v39 = modelAxis->mat[1].x;
      v40 = (float)((float)((float)(viewOrigin->y - modelOrigin->y) * modelAxis->mat[1].y)
                  + (float)((float)(viewOrigin->z - modelOrigin->z) * modelAxis->mat[1].z));
      v41 = (float)((float)((float)(viewOrigin->y - modelOrigin->y) * modelAxis->mat[2].y)
                  + (float)((float)(viewOrigin->z - modelOrigin->z) * modelAxis->mat[2].z));
      v99.mat[0].x = (float)((float)(viewOrigin->z - modelOrigin->z) * modelAxis->mat[0].z)
                   + (float)((float)((float)(viewOrigin->x - modelOrigin->x) * modelAxis->mat[0].x)
                           + (float)((float)(viewOrigin->y - modelOrigin->y) * modelAxis->mat[0].y));
      v99.mat[0].y = (float)((float)v37 * (float)v39) + (float)v40;
      v99.mat[0].z = (float)((float)v37 * (float)v38) + (float)v41;
      ((void (*)(void))RtlCheckStack12)();
      v99.mat[1].y = radius;
      v99.mat[1].z = radius;
      v99.mat[2].x = radius;
      *(const idMat3 **)((char *)back_chain + v42) = back_chain[0];
      SubModelsForTrace = idPolygonModelCollisionDetection::GetSubModelsForTrace(
                            model: (const cm_polygonModel_t *)&model[2].nextOnHashChain,
                            start: v99.mat,
                            end: v99.mat,
                            extents: (const idVec3 *)&v99.mat[1].y,
                            subModelNums: (int *)&v99);
      v44 = SubModelsForTrace;
      if ( cm_drawSubModelBounds.valueInteger != 0 )
      {
        if ( SubModelsForTrace <= 0 )
          return;
        v45 = &v98;
        for ( i = SubModelsForTrace; i != 0; --i )
        {
          idBox::idBox(
            this: v108,
            bounds: (const idBounds *)(48 * *++v45 + model[2].networkID + 8),
            origin: modelOrigin,
            axis: modelAxis);
          v47 = common->RW(this: common);
          v47->DebugBox(
            this: v47,
            a2: (const idVec4 *)&idColor::colorYellow,
            a3: v108,
            a4: a29,
            a5: cm_depthTest.valueInteger != 0);
        }
      }
      if ( v44 > 0 )
      {
        v48 = &v99;
        for ( j = v44; j != 0; --j )
        {
          v50 = (const cm_subModel_t *)(48 * LODWORD(v48->mat[0].x) + model[2].networkID);
          v51 = AcquireSubModelData(subModel: v50);
          v52 = v51;
          if ( v51->header.loadedSize != 32 )
          {
            idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(
              subModelPtrs: &baseTraceWork->subModelPtrs,
              subModelData: v51);
            idModelCheckCounts::SetupForSubModel(this: &baseTraceWork->modelCheckCounts, subModelData: v52);
            if ( radius <= 0.0 )
              v54 = 1.0e30;
            else
              v54 = radius;
            DrawNodePolygons(
              subModelPtrs: &baseTraceWork->subModelPtrs,
              origin: __SPAIR64__((unsigned int)modelOrigin, (unsigned int)modelAxis),
              axis: &v99,
              viewOrigin: viewAxis->mat,
              viewAxis: v53,
              radius: v54,
              lifeTime: a29,
              a8: back_chain[2]);
          }
          ReleaseSubModelData(subModel: (const cm_subModelData_t *)v50, data: v52);
          v48 = (idMat3 *)((char *)v48 + 4);
        }
      }
    }
  }
}


// ========================================================================
// SpeedTest
// EA  : 0x825DB5F0
// RVA : 0x005DB5F0
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall SpeedTest(const idVec3 *origin)
{
  __int64 v1; // r20
  idVec3 *v3; // r3
  __int64 v4; // r8 OVERLAPPED
  __int64 v5; // r10
  double x; // fp1
  double y; // fp2
  __int64 v8; // r6
  va *v9; // r3
  idMat3 *v10; // r3
  int v11; // r25
  __int64 v12; // r7
  int v13; // r9
  int valueInteger; // r10
  float *v15; // r11
  int v16; // r8
  float *p_z; // r11
  __int64 v18; // r10
  __int64 v19; // r5
  int v20; // r9
  double v21; // fp0
  float *v22; // r11
  double v23; // fp12
  idResource *v24; // r3
  int v25; // r2 OVERLAPPED
  __int64 v26; // r3
  int v27; // r27
  int v28; // r26
  int v29; // r3
  __int64 v30; // r10
  __int64 v31; // r11
  double clockTicks; // fp27
  __int64 v33; // r3
  double v34; // fp8
  int v35; // r27
  __int64 v36; // r4
  __int64 v37; // r5 OVERLAPPED
  int v38; // r11
  __int64 v39; // r10
  int v40; // r11
  int v41; // r6
  double v42; // fp10
  int v43; // r11
  float *v44; // r10
  int v45; // r8
  float *v46; // r11
  int v47; // r9
  int v48; // r3
  int v49; // r9
  __int64 v50; // r6
  int v51; // r3
  __int64 v52; // r3
  int i; // r30
  int v54; // r3
  __int64 v55; // r10
  __int64 v56; // r11
  double v57; // fp31
  __int64 v58; // r3
  double v59; // fp8
  int v60; // r30
  __int64 v61; // r4
  const idMat3 *v62; // [sp+8h] [-19B8h]
  int v63; // [sp+Ch] [-19B4h]
  const idPositionedCollisionModel *v64; // [sp+10h] [-19B0h]
  int v65; // [sp+14h] [-19ACh]
  const char *v66; // [sp+18h] [-19A8h]
  int v67; // [sp+1Ch] [-19A4h]
  double v68; // [sp+20h] [-19A0h]
  double v69; // [sp+28h] [-1998h]
  double z; // [sp+30h] [-1990h]
  double v71; // [sp+38h] [-1988h]
  int v72; // [sp+40h] [-1980h]
  int v73; // [sp+44h] [-197Ch]
  int v74; // [sp+48h] [-1978h]
  int v75; // [sp+4Ch] [-1974h]
  int v76; // [sp+50h] [-1970h]
  int v77; // [sp+58h] [-1968h]
  int v78; // [sp+60h] [-1960h]
  int v79; // [sp+68h] [-1958h]
  __int64 v80; // [sp+80h] [-1940h] BYREF
  __int64 v81; // [sp+88h] [-1938h]
  __int64 v82; // [sp+90h] [-1930h]
  idTimer v83; // [sp+A0h] [-1920h] BYREF
  idTraceModel *v84; // [sp+C0h] [-1900h] BYREF
  idMem *v85; // [sp+C4h] [-18FCh]
  idMat3 v86; // [sp+C8h] [-18F8h] BYREF
  idVec3 v87[3]; // [sp+ECh] [-18D4h]
  idBounds v88; // [sp+110h] [-18B0h] BYREF
  idRotation v89; // [sp+130h] [-1890h] BYREF
  float v90[16]; // [sp+180h] [-1840h] BYREF
  __int64 v91; // [sp+1C0h] [-1800h]
  __int64 v92; // [sp+1C8h] [-17F8h]
  char v93[128]; // [sp+1D0h] [-17F0h] BYREF
  idAngles v94[4]; // [sp+250h] [-1770h] BYREF
  trace_t v95; // [sp+280h] [-1740h] BYREF
  idTraceModel v96; // [sp+300h] [-16C0h] BYREF
  va v97; // [sp+900h] [-10C0h] BYREF

  if ( cm_testCollision.valueInteger == 0 )
    return;
  v85 = &mem;
  v3 = (idVec3 *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\engine\\cm\\CollisionModelManager_debug.cpp(517) : TAG_COLLISION",
                   size: 12 * cm_testTimes.valueInteger,
                   tag: TAG_COLLISION,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
  LODWORD(v4) = &consoleFont[21088];
  testend = v3;
  LODWORD(v1) = 0;
  if ( cm_testReset.valueInteger != 0 )
  {
    dword_8364AE20 = 0;
    dword_8364AE1C = 0;
    num_rotation = 0;
    num_translation = 0;
    min_rotation = 999999;
    min_translation = 999999;
    max_rotation = -999999;
    max_translation = -999999;
    idCVar::SetBool(this: &cm_testReset, newValue: false, force: true);
    LODWORD(v5) = cm_testWalk.valueInteger;
  }
  else
  {
    LODWORD(v5) = cm_testWalk.valueInteger;
    if ( cm_testWalk.valueInteger == 0 )
    {
LABEL_8:
      ignoredReturnValue = sscanf(
                             string: cm_testOrigin.valueString.data,
                             format: "%f %f %f",
                             &start,
                             &start.y,
                             &start.z);
      goto LABEL_9;
    }
    HIDWORD(v5) = 1;
  }
  if ( (_DWORD)v5 == 0 )
    goto LABEL_8;
  x = origin->x;
  start.x = origin->x;
  y = origin->y;
  start.y = origin->y;
  v68 = x;
  z = origin->z;
  v69 = y;
  HIDWORD(v8) = HIDWORD(y);
  *(double *)((char *)&v4 + 4) = z;
  start.z = origin->z;
  v9 = va::va(
         this: &v97,
         fmt: (const char *)HIDWORD(x),
         a3: v8,
         a4: v4,
         a5: v5,
         a6: (int)v62,
         a7: v63,
         a8: (int)v64,
         a9: v65,
         a10: (int)v66,
         a11: v67);
  idCVar::SetString(this: &cm_testOrigin, newValue: v9->buffer, force: true);
LABEL_9:
  ignoredReturnValue += sscanf(
                          string: cm_testBox.valueString.data,
                          format: "%f %f %f %f %f %f",
                          &v88,
                          &v88.b[0].y,
                          &v88.b[0].z,
                          &v88.b[1],
                          &v88.b[1].y,
                          &v88.b[1].z);
  ignoredReturnValue += sscanf(
                          string: cm_testBoxRotation.valueString.data,
                          format: "%f %f %f",
                          &v86,
                          &v86.mat[0].y,
                          &v86.mat[0].z);
  v10 = idAngles::ToMat3(this: v94, result: &v86);
  HIDWORD(v82) = &v10->mat[1];
  v86.mat[2].x = v10->mat[0].x;
  HIDWORD(v82) = &v10->mat[2];
  v86.mat[2].y = v10->mat[0].y;
  v86.mat[2].z = v10->mat[0].z;
  v87[0] = v10->mat[1];
  v87[1] = v10->mat[2];
  idTraceModel::InitBox(this: &v96);
  idTraceModel::SetupBox(this: &v96, boxBounds: &v88);
  v83.state = TS_STOPPED;
  v83.clockTicks = v1;
  v84 = &v96;
  v11 = 0;
  v83.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  HIDWORD(v12) = testend;
  HIDWORD(v1) = &cm_testRandomMany;
  if ( cm_testRandomMany.valueInteger != 0 )
  {
    v13 = 1;
    v11 = -1492899873;
    testend->x = start.x - cm_testLength.valueFloat;
    *(float *)(HIDWORD(v12) + 4) = (float)(cm_testLength.valueFloat * (float)0.31034273) + start.y;
    *(float *)(HIDWORD(v12) + 8) = -(float)((float)(cm_testLength.valueFloat * (float)0.39036226) - start.z);
    valueInteger = cm_testTimes.valueInteger;
    if ( cm_testTimes.valueInteger > 1 )
    {
      v15 = (float *)(HIDWORD(v12) + 8);
      do
      {
        ++v13;
        v15[1] = *(float *)HIDWORD(v12);
        v15[2] = *(float *)(HIDWORD(v12) + 4);
        v15 += 3;
        *v15 = *(float *)(HIDWORD(v12) + 8);
        valueInteger = cm_testTimes.valueInteger;
      }
      while ( v13 < cm_testTimes.valueInteger );
    }
  }
  else
  {
    valueInteger = cm_testTimes.valueInteger;
    v16 = 0;
    if ( cm_testTimes.valueInteger > 0 )
    {
      p_z = &testend[-1].z;
      HIDWORD(v18) = &cm_testLength;
      do
      {
        LODWORD(v18) = 1103515245 * v11 + 12345;
        ++v16;
        HIDWORD(v19) = ((int)v18 >> 16) & 0x7FFF;
        LODWORD(v18) = 1103515245 * v18 + 12345;
        v11 = 1103515245 * v18 + 12345;
        LODWORD(v19) = ((int)v18 >> 16) & 0x7FFF;
        LODWORD(v12) = HIDWORD(v19);
        v82 = v19;
        LODWORD(v18) = (v11 >> 16) & 0x7FFF;
        v80 = v12;
        v81 = v18;
        p_z[1] = (float)((float)((float)((float)v12 * (float)0.000061037019) - (float)1.0) * cm_testLength.valueFloat)
               + start.x;
        p_z[2] = (float)((float)((float)((float)v19 * (float)0.000061037019) - (float)1.0) * cm_testLength.valueFloat)
               + start.y;
        p_z += 3;
        *p_z = (float)((float)((float)((float)v18 * (float)0.000061037019) - (float)1.0) * cm_testLength.valueFloat)
             + start.z;
        valueInteger = cm_testTimes.valueInteger;
      }
      while ( v16 < cm_testTimes.valueInteger );
    }
  }
  v20 = 0;
  v21 = 0.0;
  start.x = 0.0;
  start.y = 0.0;
  start.z = 10.0;
  if ( valueInteger > 0 )
  {
    v22 = (float *)(HIDWORD(v12) - 4);
    while ( 1 )
    {
      v22[1] = v21;
      ++v20;
      v22[2] = start.y;
      v23 = (float)(start.z - (float)10.0);
      v22[3] = start.z;
      v22 += 3;
      *v22 = v23;
      if ( v20 >= cm_testTimes.valueInteger )
        break;
      v21 = start.x;
    }
  }
  v92 = v1;
  v24 = idResourceList::Index(this: &idCollisionModelLocal::resourceList, index: cm_testModel.valueInteger);
  v90[4] = 0.0;
  v90[3] = 0.0;
  v90[2] = 0.0;
  v90[5] = 1.0;
  v90[6] = 0.0;
  v90[7] = 0.0;
  v90[8] = 0.0;
  v90[9] = 1.0;
  v90[10] = 0.0;
  LODWORD(v90[0]) = v24;
  v90[11] = 0.0;
  v90[14] = 0.0;
  v90[12] = 0.0;
  v90[13] = 1.0;
  v91 = 0;
  if ( cm_testTranslation.valueInteger != 0 )
  {
    v83.clockTicks = v1;
    v83.state = TS_STARTED;
    LODWORD(v26) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v83.start = v26;
    v27 = 0;
    if ( cm_testTimes.valueInteger > 0 )
    {
      v28 = 0;
      do
      {
        idCollisionModelManager::Translation(
          this: (idCollisionModelManager *)&v80,
          result: (idCollisionQuery *)collisionModelManager,
          a3: &v95,
          start: &start,
          end: &testend[v28],
          globalBounds: &bounds_zero,
          trms: (const idTraceModel **)&v84,
          numTrms: 1,
          trmAxis: v62,
          contentMask: v63,
          models: v64,
          numModels: v65,
          userName: v66,
          a14: v67,
          a15: SHIDWORD(v68),
          a16: SLODWORD(v68),
          a17: SHIDWORD(v69),
          a18: SLODWORD(v69),
          a19: SHIDWORD(z),
          a20: SLODWORD(z),
          a21: SHIDWORD(v71),
          a22: SLODWORD(v71),
          a23: v72,
          a24: v73,
          a25: v74,
          a26: v75,
          a27: v76,
          a28: (idMat3 *)&v86.mat[2],
          a29: v77,
          a30: 9,
          a31: v78,
          a32: (int)v90,
          a33: v79,
          a34: 1);
        ++v27;
        ++v28;
      }
      while ( v27 < cm_testTimes.valueInteger );
    }
    v29 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    HIDWORD(v30) = LODWORD(v83.clockTicks) - LODWORD(v83.start);
    LODWORD(v30) = v29 + LODWORD(v83.clockTicks) - LODWORD(v83.start);
    v83.clockTicks = v30;
    if ( (float)idTimer::base < 0.0 )
      idTimer::InitBaseClockTicks(this: &v83);
    HIDWORD(v31) = HIDWORD(idTimer::base);
    if ( SHIDWORD(idTimer::base) > (int)idTimer::base )
    {
      LODWORD(v31) = HIDWORD(idTimer::base) - idTimer::base;
      v83.clockTicks = v31;
    }
    v83.state = TS_STOPPED;
    clockTicks = (float)v83.clockTicks;
    LODWORD(v33) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
    v34 = (float)((float)clockTicks / (float)((float)v33 * (float)0.001));
    LODWORD(v80) = (int)v34;
    v35 = (int)v34;
    if ( (int)v34 < min_translation )
      min_translation = (int)v34;
    if ( v35 > max_translation )
      max_translation = (int)v34;
    ++num_translation;
    dword_8364AE20 += v35;
    if ( cm_testTimes.valueInteger <= 9999 )
      HIDWORD(v36) = sprintf_0(string: v93, format: "%4d", cm_testTimes.valueInteger);
    else
      HIDWORD(v36) = sprintf_0(string: v93, format: "%3dK", cm_testTimes.valueInteger / 1000);
    LODWORD(v36) = num_translation;
    v81 = __PAIR64__(max_translation, dword_8364AE20);
    v80 = v36;
    v71 = (float)((float)__SPAIR64__(max_translation, dword_8364AE20) / (float)v36);
    idLib::Printf(
      fmt: "%s translations: %4d milliseconds, (min = %d, max = %d, av = %1.1f)\n",
      v93,
      v35,
      min_translation,
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)__SPAIR64__(max_translation, dword_8364AE20) / (float)v80))),
      (float)((float)__SPAIR64__(max_translation, dword_8364AE20) / (float)v80));
  }
  HIDWORD(v37) = testend;
  if ( cm_testRandomMany.valueInteger != 0 )
  {
    v38 = 1103515245 * v11 + 12345;
    HIDWORD(v39) = &idDeclReachIK::resourceList.hashTable[243];
    v41 = (v38 >> 16) & 0x7FFF;
    v40 = 1103515245 * v38 + 12345;
    LODWORD(v37) = v40 >> 16;
    v81 = *(__int64 *)((char *)&v37 - 4);
    LODWORD(v39) = (v40 >> 16) & 0x7FFF;
    v42 = (double)*(__int64 *)((char *)&v37 - 4);
    v82 = v39;
    LODWORD(v37) = ((1103515245 * v40 + 12345) >> 16) & 0x7FFF;
    v43 = 1;
    v80 = v37;
    testend->x = (float)((float)((float)((float)v42 * (float)0.000061037019) - (float)1.0) * cm_testRadius.valueFloat)
               + start.x;
    *(float *)(HIDWORD(v37) + 4) = (float)((float)((float)((float)v39 * (float)0.000061037019) - (float)1.0)
                                         * cm_testRadius.valueFloat)
                                 + start.y;
    *(float *)(HIDWORD(v37) + 8) = (float)((float)((float)((float)v37 * (float)0.000061037019) - (float)1.0)
                                         * cm_testRadius.valueFloat)
                                 + start.z;
    if ( cm_testTimes.valueInteger > 1 )
    {
      v44 = (float *)(HIDWORD(v37) + 8);
      do
      {
        ++v43;
        v44[1] = *(float *)HIDWORD(v37);
        v44[2] = *(float *)(HIDWORD(v37) + 4);
        v44 += 3;
        *v44 = *(float *)(HIDWORD(v37) + 8);
      }
      while ( v43 < cm_testTimes.valueInteger );
    }
  }
  else
  {
    v45 = 0;
    if ( cm_testTimes.valueInteger > 0 )
    {
      v46 = &testend[-1].z;
      do
      {
        v47 = 1103515245 * v11 + 12345;
        ++v45;
        v48 = (v47 >> 16) & 0x7FFF;
        v49 = 1103515245 * v47 + 12345;
        v80 = *(_QWORD *)(&v25 - 1);
        HIDWORD(v50) = (v49 >> 16) & 0x7FFF;
        v11 = 1103515245 * v49 + 12345;
        v51 = HIDWORD(v50);
        v81 = *(_QWORD *)(&v25 - 1);
        LODWORD(v50) = (v11 >> 16) & 0x7FFF;
        v82 = v50;
        v46[1] = (float)((float)((float)((float)v80 * (float)0.000061037019) - (float)1.0) * cm_testRadius.valueFloat)
               + start.x;
        v46[2] = (float)((float)((float)((float)*(__int64 *)(&v25 - 1) * (float)0.000061037019) - (float)1.0)
                       * cm_testRadius.valueFloat)
               + start.y;
        v46 += 3;
        *v46 = (float)((float)((float)((float)v50 * (float)0.000061037019) - (float)1.0) * cm_testRadius.valueFloat)
             + start.z;
      }
      while ( v45 < cm_testTimes.valueInteger );
    }
  }
  if ( cm_testRotation.valueInteger != 0 )
  {
    v89.origin.y = 0.0;
    v89.origin.z = 0.0;
    v89.vec.x = 0.0;
    v89.vec.y = 1.0;
    v89.vec.z = 0.0;
    v89.axisValid = false;
    v83.clockTicks = v1;
    v83.state = TS_STARTED;
    v89.axis.mat[0].x = mat3_identity.mat[0].x;
    v89.axis.mat[0].y = mat3_identity.mat[0].y;
    v89.axis.mat[0].z = mat3_identity.mat[0].z;
    v89.axis.mat[1].x = mat3_identity.mat[1].x;
    v89.axis.mat[1].y = mat3_identity.mat[1].y;
    v89.axis.mat[1].z = mat3_identity.mat[1].z;
    v89.axis.mat[2].x = mat3_identity.mat[2].x;
    v89.axis.mat[2].y = mat3_identity.mat[2].y;
    v89.axis.mat[2].z = mat3_identity.mat[2].z;
    v89.origin.x = 30.0;
    v89.angle = 90.0;
    start.x = 30.0;
    start.y = 0.0;
    start.z = 0.0;
    LODWORD(v52) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v83.start = v52;
    for ( i = 0; i < cm_testTimes.valueInteger; ++i )
      idCollisionModelManager::Rotation(
        this: (idCollisionModelManager *)&v80,
        result: (idCollisionQuery *)collisionModelManager,
        a3: &v95,
        start: (const idMat3 *)&start,
        rotation: &v89,
        globalBounds: &bounds_zero,
        trms: (const idMat3 **)&v84,
        numTrms: 1,
        trmAxis: v62,
        contentMask: v63,
        models: v64,
        numModels: v65,
        userName: v66,
        a14: v67,
        a15: SHIDWORD(v68),
        a16: SLODWORD(v68),
        a17: SHIDWORD(v69),
        a18: SLODWORD(v69),
        a19: SHIDWORD(z),
        a20: SLODWORD(z),
        a21: SHIDWORD(v71),
        a22: SLODWORD(v71),
        a23: v72,
        a24: v73,
        a25: v74,
        a26: v75,
        a27: v76,
        a28: (const idMat3 *)&v86.mat[2],
        a29: v77,
        a30: (const idVec3 *)9,
        a31: v78,
        a32: (int)v90,
        a33: v79,
        a34: 1);
    v54 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    HIDWORD(v55) = LODWORD(v83.clockTicks) - LODWORD(v83.start);
    LODWORD(v55) = v54 + LODWORD(v83.clockTicks) - LODWORD(v83.start);
    v83.clockTicks = v55;
    if ( (float)idTimer::base < 0.0 )
      idTimer::InitBaseClockTicks(this: &v83);
    HIDWORD(v56) = HIDWORD(idTimer::base);
    if ( SHIDWORD(idTimer::base) > (int)idTimer::base )
    {
      LODWORD(v56) = HIDWORD(idTimer::base) - idTimer::base;
      v83.clockTicks = v56;
    }
    v83.state = TS_STOPPED;
    v57 = (float)v83.clockTicks;
    LODWORD(v58) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
    v59 = (float)((float)v57 / (float)((float)v58 * (float)0.001));
    LODWORD(v80) = (int)v59;
    v60 = (int)v59;
    if ( (int)v59 < min_rotation )
      min_rotation = (int)v59;
    if ( v60 > max_rotation )
      max_rotation = (int)v59;
    ++num_rotation;
    dword_8364AE1C += v60;
    if ( cm_testTimes.valueInteger <= 9999 )
      HIDWORD(v61) = sprintf_0(string: v93, format: "%4d", cm_testTimes.valueInteger);
    else
      HIDWORD(v61) = sprintf_0(string: v93, format: "%3dK", cm_testTimes.valueInteger / 1000);
    LODWORD(v61) = num_rotation;
    v80 = __PAIR64__(max_rotation, dword_8364AE1C);
    v81 = v61;
    idLib::Printf(
      fmt: "%s rotation: %4d milliseconds, (min = %d, max = %d, av = %1.1f)\n",
      v93,
      v60,
      min_rotation,
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)__SPAIR64__(max_rotation, dword_8364AE1C) / (float)v81))),
      (float)((float)__SPAIR64__(max_rotation, dword_8364AE1C) / (float)v81));
    HIDWORD(v37) = testend;
  }
  idMem::Free(this: v85, ptr: (void *)HIDWORD(v37), align: ALIGN_16);
  testend = nullptr;
}


// ========================================================================
// __unwind$225794
// EA  : 0x825DC15C
// RVA : 0x005DC15C
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void _unwind_225794()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(v0 - 6592 + 160));
}


// ========================================================================
// DebugTranslationFailure
// EA  : 0x825DC188
// RVA : 0x005DC188
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __fastcall DebugTranslationFailure(const idVec3 *viewOrigin, const idMat3 *viewAxis)
{
  int v4; // r10
  int v5; // r10
  int v6; // [sp+8h] [-228h]
  int v7; // [sp+8h] [-228h]
  const idMat3 *v8; // [sp+8h] [-228h]
  int v9; // [sp+8h] [-228h]
  int v10; // [sp+8h] [-228h]
  int v11; // [sp+Ch] [-224h]
  int v12; // [sp+Ch] [-224h]
  int v13; // [sp+Ch] [-224h]
  const idPositionedCollisionModel *v14; // [sp+Ch] [-224h]
  int v15; // [sp+Ch] [-224h]
  int v16; // [sp+10h] [-220h]
  int v17; // [sp+10h] [-220h]
  const idPositionedCollisionModel *v18; // [sp+10h] [-220h]
  int v19; // [sp+10h] [-220h]
  int v20; // [sp+10h] [-220h]
  int v21; // [sp+14h] [-21Ch]
  int v22; // [sp+14h] [-21Ch]
  int v23; // [sp+14h] [-21Ch]
  const char *v24; // [sp+14h] [-21Ch]
  int v25; // [sp+14h] [-21Ch]
  int v26; // [sp+18h] [-218h]
  int v27; // [sp+18h] [-218h]
  const char *v28; // [sp+18h] [-218h]
  int v29; // [sp+18h] [-218h]
  int v30; // [sp+18h] [-218h]
  int v31; // [sp+1Ch] [-214h]
  int v32; // [sp+1Ch] [-214h]
  int v33; // [sp+1Ch] [-214h]
  int v34; // [sp+1Ch] [-214h]
  int v35; // [sp+1Ch] [-214h]
  int v36; // [sp+20h] [-210h]
  int v37; // [sp+20h] [-210h]
  int v38; // [sp+20h] [-210h]
  int v39; // [sp+20h] [-210h]
  int v40; // [sp+20h] [-210h]
  int v41; // [sp+24h] [-20Ch]
  int v42; // [sp+24h] [-20Ch]
  int v43; // [sp+24h] [-20Ch]
  int v44; // [sp+24h] [-20Ch]
  int v45; // [sp+24h] [-20Ch]
  int v46; // [sp+28h] [-208h]
  int v47; // [sp+28h] [-208h]
  int v48; // [sp+28h] [-208h]
  int v49; // [sp+28h] [-208h]
  int v50; // [sp+28h] [-208h]
  int v51; // [sp+2Ch] [-204h]
  int v52; // [sp+2Ch] [-204h]
  int v53; // [sp+2Ch] [-204h]
  int v54; // [sp+2Ch] [-204h]
  int v55; // [sp+2Ch] [-204h]
  int v56; // [sp+30h] [-200h]
  int v57; // [sp+30h] [-200h]
  int v58; // [sp+30h] [-200h]
  int v59; // [sp+30h] [-200h]
  int v60; // [sp+30h] [-200h]
  int v61; // [sp+34h] [-1FCh]
  int v62; // [sp+34h] [-1FCh]
  int v63; // [sp+34h] [-1FCh]
  int v64; // [sp+34h] [-1FCh]
  int v65; // [sp+34h] [-1FCh]
  int v66; // [sp+38h] [-1F8h]
  int v67; // [sp+38h] [-1F8h]
  int v68; // [sp+38h] [-1F8h]
  int v69; // [sp+38h] [-1F8h]
  int v70; // [sp+38h] [-1F8h]
  int v71; // [sp+3Ch] [-1F4h]
  int v72; // [sp+3Ch] [-1F4h]
  int v73; // [sp+3Ch] [-1F4h]
  int v74; // [sp+3Ch] [-1F4h]
  int v75; // [sp+3Ch] [-1F4h]
  int v76; // [sp+40h] [-1F0h]
  int v77; // [sp+40h] [-1F0h]
  int v78; // [sp+40h] [-1F0h]
  int v79; // [sp+40h] [-1F0h]
  int v80; // [sp+40h] [-1F0h]
  int v81; // [sp+44h] [-1ECh]
  int v82; // [sp+44h] [-1ECh]
  int v83; // [sp+44h] [-1ECh]
  int v84; // [sp+44h] [-1ECh]
  int v85; // [sp+44h] [-1ECh]
  int v86; // [sp+48h] [-1E8h]
  int v87; // [sp+48h] [-1E8h]
  int v88; // [sp+48h] [-1E8h]
  int v89; // [sp+48h] [-1E8h]
  int v90; // [sp+48h] [-1E8h]
  int v91; // [sp+4Ch] [-1E4h]
  int v92; // [sp+4Ch] [-1E4h]
  int v93; // [sp+4Ch] [-1E4h]
  int v94; // [sp+4Ch] [-1E4h]
  int v95; // [sp+4Ch] [-1E4h]
  int v96; // [sp+50h] [-1E0h]
  int v97; // [sp+50h] [-1E0h]
  int v98; // [sp+50h] [-1E0h]
  int v99; // [sp+50h] [-1E0h]
  int v100; // [sp+50h] [-1E0h]
  int v101; // [sp+58h] [-1D8h]
  int v102; // [sp+58h] [-1D8h]
  int v103; // [sp+60h] [-1D0h]
  int v104; // [sp+60h] [-1D0h]
  int v105; // [sp+68h] [-1C8h]
  idVec3 v106; // [sp+80h] [-1B0h] BYREF
  idCollisionModelManager v107[16]; // [sp+90h] [-1A0h] BYREF
  idBounds v108; // [sp+A0h] [-190h] BYREF
  trace_t v109; // [sp+C0h] [-170h] BYREF
  trace_t v110; // [sp+140h] [-F0h] BYREF

  if ( translationFailure.valid && cm_debugTranslation.valueInteger != 0 && cm_debugSetParms.valueInteger == 0 )
  {
    cm_color.x = 1.0;
    cm_color.y = 0.0;
    cm_color.z = 0.0;
    cm_color.w = 0.5;
    idCollisionModelManager::DrawCollisionModel(
      this: collisionModelManager,
      model: translationFailure.trmModel,
      modelJoints: nullptr,
      modelOrigin: &translationFailure.start,
      modelAxis: &translationFailure.trmAxis,
      viewOrigin,
      viewAxis,
      radius: 1024.0,
      lifeTime: 0x82000000,
      a10: v6,
      a11: v11,
      a12: v16,
      a13: v21,
      a14: v26,
      a15: v31,
      a16: v36,
      a17: v41,
      a18: v46,
      a19: v51,
      a20: v56,
      a21: v61,
      a22: v66,
      a23: v71,
      a24: v76,
      a25: v81,
      a26: v86,
      a27: v91,
      a28: v96,
      a29: 0);
    idCollisionModelManager::DrawCollisionModel(
      this: collisionModelManager,
      model: translationFailure.model.model,
      modelJoints: nullptr,
      modelOrigin: &translationFailure.model.modelOrigin,
      modelAxis: &translationFailure.model.modelAxis,
      viewOrigin,
      viewAxis,
      radius: 1024.0,
      lifeTime: v4,
      a10: v7,
      a11: v12,
      a12: v17,
      a13: v22,
      a14: v27,
      a15: v32,
      a16: v37,
      a17: v42,
      a18: v47,
      a19: v52,
      a20: v57,
      a21: v62,
      a22: v67,
      a23: v72,
      a24: v77,
      a25: v82,
      a26: v87,
      a27: v92,
      a28: v97,
      a29: 0);
    v106.x = translationFailure.end.x - translationFailure.start.x;
    v106.y = translationFailure.end.y - translationFailure.start.y;
    v106.z = translationFailure.end.z - translationFailure.start.z;
    idBounds::FromBoundsTranslation(
      this: &v108,
      bounds: &translationFailure.trms[0]->bounds,
      boundsOrigin: &translationFailure.start,
      boundsAxis: &translationFailure.trmAxis,
      translation: &v106);
    idCollisionModelManager::Translation(
      this: v107,
      result: (idCollisionQuery *)collisionModelManager,
      a3: &v109,
      start: &translationFailure.start,
      end: &translationFailure.end,
      globalBounds: &v108,
      trms: translationFailure.trms,
      numTrms: 1,
      trmAxis: v8,
      contentMask: v13,
      models: v18,
      numModels: v23,
      userName: v28,
      a14: v33,
      a15: v38,
      a16: v43,
      a17: v48,
      a18: v53,
      a19: v58,
      a20: v63,
      a21: v68,
      a22: v73,
      a23: v78,
      a24: v83,
      a25: v88,
      a26: v93,
      a27: v98,
      a28: &translationFailure.trmAxis,
      a29: v101,
      a30: translationFailure.contentMask,
      a31: v103,
      a32: (int)&translationFailure.model,
      a33: v105,
      a34: 1);
    idCollisionModelManager::Contents(
      this: v107,
      result: (idCollisionQuery *)collisionModelManager,
      a3: &v110,
      start: &v109.endpos,
      globalBounds: &v108,
      trms: translationFailure.trms,
      numTrms: 1,
      trmAxis: &v109.endAxis,
      contentMask: v9,
      models: v14,
      numModels: v19,
      userName: v24,
      a13: v29,
      a14: v34,
      a15: v39,
      a16: v44,
      a17: v49,
      a18: v54,
      a19: v59,
      a20: v64,
      a21: v69,
      a22: v74,
      a23: v79,
      a24: v84,
      a25: v89,
      a26: v94,
      a27: v99,
      a28: -1,
      a29: v102,
      a30: (int)&translationFailure.model,
      a31: v104,
      a32: 1);
    cm_color.x = 1.0;
    cm_color.y = 1.0;
    cm_color.z = 1.0;
    cm_color.w = 0.5;
    idCollisionModelManager::DrawCollisionModel(
      this: collisionModelManager,
      model: translationFailure.trmModel,
      modelJoints: nullptr,
      modelOrigin: &v109.endpos,
      modelAxis: &v109.endAxis,
      viewOrigin,
      viewAxis,
      radius: 1024.0,
      lifeTime: v5,
      a10: v10,
      a11: v15,
      a12: v20,
      a13: v25,
      a14: v30,
      a15: v35,
      a16: v40,
      a17: v45,
      a18: v50,
      a19: v55,
      a20: v60,
      a21: v65,
      a22: v70,
      a23: v75,
      a24: v80,
      a25: v85,
      a26: v90,
      a27: v95,
      a28: v100,
      a29: 0);
    cm_color.x = 1.0;
    cm_color.y = 0.0;
    cm_color.z = 0.0;
    cm_color.w = 0.5;
  }
}


// ========================================================================
// ?DebugRotationFailure@@YAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x825DC398
// RVA : 0x005DC398
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __fastcall DebugRotationFailure(const idVec3 *viewOrigin, const idMat3 *viewAxis)
{
  int v4; // r10
  int v5; // r10
  int v6; // [sp+8h] [-218h]
  int v7; // [sp+8h] [-218h]
  const idMat3 *v8; // [sp+8h] [-218h]
  int v9; // [sp+8h] [-218h]
  int v10; // [sp+8h] [-218h]
  int v11; // [sp+Ch] [-214h]
  int v12; // [sp+Ch] [-214h]
  int v13; // [sp+Ch] [-214h]
  const idPositionedCollisionModel *v14; // [sp+Ch] [-214h]
  int v15; // [sp+Ch] [-214h]
  int v16; // [sp+10h] [-210h]
  int v17; // [sp+10h] [-210h]
  const idPositionedCollisionModel *v18; // [sp+10h] [-210h]
  int v19; // [sp+10h] [-210h]
  int v20; // [sp+10h] [-210h]
  int v21; // [sp+14h] [-20Ch]
  int v22; // [sp+14h] [-20Ch]
  int v23; // [sp+14h] [-20Ch]
  const char *v24; // [sp+14h] [-20Ch]
  int v25; // [sp+14h] [-20Ch]
  int v26; // [sp+18h] [-208h]
  int v27; // [sp+18h] [-208h]
  const char *v28; // [sp+18h] [-208h]
  int v29; // [sp+18h] [-208h]
  int v30; // [sp+18h] [-208h]
  int v31; // [sp+1Ch] [-204h]
  int v32; // [sp+1Ch] [-204h]
  int v33; // [sp+1Ch] [-204h]
  int v34; // [sp+1Ch] [-204h]
  int v35; // [sp+1Ch] [-204h]
  int v36; // [sp+20h] [-200h]
  int v37; // [sp+20h] [-200h]
  int v38; // [sp+20h] [-200h]
  int v39; // [sp+20h] [-200h]
  int v40; // [sp+20h] [-200h]
  int v41; // [sp+24h] [-1FCh]
  int v42; // [sp+24h] [-1FCh]
  int v43; // [sp+24h] [-1FCh]
  int v44; // [sp+24h] [-1FCh]
  int v45; // [sp+24h] [-1FCh]
  int v46; // [sp+28h] [-1F8h]
  int v47; // [sp+28h] [-1F8h]
  int v48; // [sp+28h] [-1F8h]
  int v49; // [sp+28h] [-1F8h]
  int v50; // [sp+28h] [-1F8h]
  int v51; // [sp+2Ch] [-1F4h]
  int v52; // [sp+2Ch] [-1F4h]
  int v53; // [sp+2Ch] [-1F4h]
  int v54; // [sp+2Ch] [-1F4h]
  int v55; // [sp+2Ch] [-1F4h]
  int v56; // [sp+30h] [-1F0h]
  int v57; // [sp+30h] [-1F0h]
  int v58; // [sp+30h] [-1F0h]
  int v59; // [sp+30h] [-1F0h]
  int v60; // [sp+30h] [-1F0h]
  int v61; // [sp+34h] [-1ECh]
  int v62; // [sp+34h] [-1ECh]
  int v63; // [sp+34h] [-1ECh]
  int v64; // [sp+34h] [-1ECh]
  int v65; // [sp+34h] [-1ECh]
  int v66; // [sp+38h] [-1E8h]
  int v67; // [sp+38h] [-1E8h]
  int v68; // [sp+38h] [-1E8h]
  int v69; // [sp+38h] [-1E8h]
  int v70; // [sp+38h] [-1E8h]
  int v71; // [sp+3Ch] [-1E4h]
  int v72; // [sp+3Ch] [-1E4h]
  int v73; // [sp+3Ch] [-1E4h]
  int v74; // [sp+3Ch] [-1E4h]
  int v75; // [sp+3Ch] [-1E4h]
  int v76; // [sp+40h] [-1E0h]
  int v77; // [sp+40h] [-1E0h]
  int v78; // [sp+40h] [-1E0h]
  int v79; // [sp+40h] [-1E0h]
  int v80; // [sp+40h] [-1E0h]
  int v81; // [sp+44h] [-1DCh]
  int v82; // [sp+44h] [-1DCh]
  int v83; // [sp+44h] [-1DCh]
  int v84; // [sp+44h] [-1DCh]
  int v85; // [sp+44h] [-1DCh]
  int v86; // [sp+48h] [-1D8h]
  int v87; // [sp+48h] [-1D8h]
  int v88; // [sp+48h] [-1D8h]
  int v89; // [sp+48h] [-1D8h]
  int v90; // [sp+48h] [-1D8h]
  int v91; // [sp+4Ch] [-1D4h]
  int v92; // [sp+4Ch] [-1D4h]
  int v93; // [sp+4Ch] [-1D4h]
  int v94; // [sp+4Ch] [-1D4h]
  int v95; // [sp+4Ch] [-1D4h]
  int v96; // [sp+50h] [-1D0h]
  int v97; // [sp+50h] [-1D0h]
  int v98; // [sp+50h] [-1D0h]
  int v99; // [sp+50h] [-1D0h]
  int v100; // [sp+50h] [-1D0h]
  int v101; // [sp+58h] [-1C8h]
  int v102; // [sp+58h] [-1C8h]
  int v103; // [sp+60h] [-1C0h]
  int v104; // [sp+60h] [-1C0h]
  int v105; // [sp+68h] [-1B8h]
  idCollisionModelManager v106[16]; // [sp+80h] [-1A0h] BYREF
  idBounds v107; // [sp+90h] [-190h] BYREF
  trace_t v108; // [sp+B0h] [-170h] BYREF
  trace_t v109; // [sp+130h] [-F0h] BYREF

  if ( rotationFailure.valid && cm_debugRotation.valueInteger != 0 && cm_debugSetParms.valueInteger == 0 )
  {
    cm_color.x = 1.0;
    cm_color.y = 0.0;
    cm_color.z = 0.0;
    cm_color.w = 0.5;
    idCollisionModelManager::DrawCollisionModel(
      this: collisionModelManager,
      model: rotationFailure.trmModel,
      modelJoints: nullptr,
      modelOrigin: &rotationFailure.start,
      modelAxis: &rotationFailure.trmAxis,
      viewOrigin,
      viewAxis,
      radius: 1024.0,
      lifeTime: 0x82000000,
      a10: v6,
      a11: v11,
      a12: v16,
      a13: v21,
      a14: v26,
      a15: v31,
      a16: v36,
      a17: v41,
      a18: v46,
      a19: v51,
      a20: v56,
      a21: v61,
      a22: v66,
      a23: v71,
      a24: v76,
      a25: v81,
      a26: v86,
      a27: v91,
      a28: v96,
      a29: 0);
    idCollisionModelManager::DrawCollisionModel(
      this: collisionModelManager,
      model: rotationFailure.model.model,
      modelJoints: nullptr,
      modelOrigin: &rotationFailure.model.modelOrigin,
      modelAxis: &rotationFailure.model.modelAxis,
      viewOrigin,
      viewAxis,
      radius: 1024.0,
      lifeTime: v4,
      a10: v7,
      a11: v12,
      a12: v17,
      a13: v22,
      a14: v27,
      a15: v32,
      a16: v37,
      a17: v42,
      a18: v47,
      a19: v52,
      a20: v57,
      a21: v62,
      a22: v67,
      a23: v72,
      a24: v77,
      a25: v82,
      a26: v87,
      a27: v92,
      a28: v97,
      a29: 0);
    idBounds::FromBoundsRotation(
      this: &v107,
      bounds: &rotationFailure.trms[0]->bounds,
      boundsOrigin: &rotationFailure.start,
      boundsAxis: &rotationFailure.trmAxis,
      rotation: &rotationFailure.rotation);
    idCollisionModelManager::Rotation(
      this: v106,
      result: (idCollisionQuery *)collisionModelManager,
      a3: &v108,
      start: (const idMat3 *)&rotationFailure.start,
      rotation: &rotationFailure.rotation,
      globalBounds: &v107,
      trms: (const idMat3 **)rotationFailure.trms,
      numTrms: 1,
      trmAxis: v8,
      contentMask: v13,
      models: v18,
      numModels: v23,
      userName: v28,
      a14: v33,
      a15: v38,
      a16: v43,
      a17: v48,
      a18: v53,
      a19: v58,
      a20: v63,
      a21: v68,
      a22: v73,
      a23: v78,
      a24: v83,
      a25: v88,
      a26: v93,
      a27: v98,
      a28: &rotationFailure.trmAxis,
      a29: v101,
      a30: (const idVec3 *)rotationFailure.contentMask,
      a31: v103,
      a32: (int)&rotationFailure.model,
      a33: v105,
      a34: 1);
    idCollisionModelManager::Contents(
      this: v106,
      result: (idCollisionQuery *)collisionModelManager,
      a3: &v109,
      start: &v108.endpos,
      globalBounds: &v107,
      trms: rotationFailure.trms,
      numTrms: 1,
      trmAxis: &v108.endAxis,
      contentMask: v9,
      models: v14,
      numModels: v19,
      userName: v24,
      a13: v29,
      a14: v34,
      a15: v39,
      a16: v44,
      a17: v49,
      a18: v54,
      a19: v59,
      a20: v64,
      a21: v69,
      a22: v74,
      a23: v79,
      a24: v84,
      a25: v89,
      a26: v94,
      a27: v99,
      a28: -1,
      a29: v102,
      a30: (int)&rotationFailure.model,
      a31: v104,
      a32: 1);
    cm_color.x = 1.0;
    cm_color.y = 1.0;
    cm_color.z = 1.0;
    cm_color.w = 0.5;
    idCollisionModelManager::DrawCollisionModel(
      this: collisionModelManager,
      model: rotationFailure.trmModel,
      modelJoints: nullptr,
      modelOrigin: &v108.endpos,
      modelAxis: &v108.endAxis,
      viewOrigin,
      viewAxis,
      radius: 1024.0,
      lifeTime: v5,
      a10: v10,
      a11: v15,
      a12: v20,
      a13: v25,
      a14: v30,
      a15: v35,
      a16: v40,
      a17: v45,
      a18: v50,
      a19: v55,
      a20: v60,
      a21: v65,
      a22: v70,
      a23: v75,
      a24: v80,
      a25: v85,
      a26: v90,
      a27: v95,
      a28: v100,
      a29: 0);
    cm_color.x = 1.0;
    cm_color.y = 0.0;
    cm_color.z = 0.0;
    cm_color.w = 0.5;
  }
}


// ========================================================================
// DebugFailedQuery
// EA  : 0x825DC578
// RVA : 0x005DC578
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __fastcall DebugFailedQuery(const idMat3 *viewOrigin, const idMat3 *viewAxis)
{
  const cm_polygonModel_t *model; // r7
  int v5; // r23
  int v6; // r27
  const cm_subModel_t *v7; // r24
  const cm_subModelData_t *v8; // r3
  const cm_subModelData_t *v9; // r30
  __int64 v10; // r6
  const idMat3 *v11; // r9
  int v12; // r10
  __int64 v13; // r6
  const idMat3 *v14; // r9
  int v15; // [sp+8h] [-4A8h]
  const idMat3 *v16; // [sp+8h] [-4A8h]
  int v17; // [sp+Ch] [-4A4h]
  int v18; // [sp+Ch] [-4A4h]
  int v19; // [sp+10h] [-4A0h]
  int v20; // [sp+10h] [-4A0h]
  int v21; // [sp+14h] [-49Ch]
  int v22; // [sp+14h] [-49Ch]
  int v23; // [sp+18h] [-498h]
  int v24; // [sp+18h] [-498h]
  int v25; // [sp+1Ch] [-494h]
  int v26; // [sp+1Ch] [-494h]
  int v27; // [sp+20h] [-490h]
  int v28; // [sp+20h] [-490h]
  int v29; // [sp+24h] [-48Ch]
  int v30; // [sp+24h] [-48Ch]
  int v31; // [sp+28h] [-488h]
  int v32; // [sp+28h] [-488h]
  int v33; // [sp+2Ch] [-484h]
  int v34; // [sp+2Ch] [-484h]
  int v35; // [sp+30h] [-480h]
  int v36; // [sp+30h] [-480h]
  int v37; // [sp+34h] [-47Ch]
  int v38; // [sp+34h] [-47Ch]
  int v39; // [sp+38h] [-478h]
  int v40; // [sp+38h] [-478h]
  int v41; // [sp+3Ch] [-474h]
  int v42; // [sp+3Ch] [-474h]
  int v43; // [sp+40h] [-470h]
  int v44; // [sp+40h] [-470h]
  int v45; // [sp+44h] [-46Ch]
  int v46; // [sp+44h] [-46Ch]
  int v47; // [sp+48h] [-468h]
  int v48; // [sp+48h] [-468h]
  int v49; // [sp+4Ch] [-464h]
  int v50; // [sp+4Ch] [-464h]
  int v51; // [sp+50h] [-460h]
  int v52; // [sp+50h] [-460h]
  queryResults_t v53; // [sp+60h] [-450h] BYREF

  if ( cdQuery.failedQuery.valid )
  {
    cm_color.x = 1.0;
    cm_color.y = 0.0;
    cm_color.z = 0.0;
    cm_color.w = 0.5;
    idCollisionModelManager::DrawCollisionModel(
      this: collisionModelManager,
      model: cdQuery.failedQuery.trmModel,
      modelJoints: nullptr,
      modelOrigin: &cdQuery.failedQuery.parms.start,
      modelAxis: &cdQuery.failedQuery.parms.trmAxis,
      viewOrigin: viewOrigin->mat,
      viewAxis,
      radius: 1024.0,
      lifeTime: (int)&off_82040000,
      a10: v15,
      a11: v17,
      a12: v19,
      a13: v21,
      a14: v23,
      a15: v25,
      a16: v27,
      a17: v29,
      a18: v31,
      a19: v33,
      a20: v35,
      a21: v37,
      a22: v39,
      a23: v41,
      a24: v43,
      a25: v45,
      a26: v47,
      a27: v49,
      a28: v51,
      a29: 0);
    model = cdQuery.failedQuery.model;
    if ( cdQuery.failedQuery.model != nullptr )
    {
      v5 = 0;
      if ( cdQuery.failedQuery.model->numSubModels > 0 )
      {
        v6 = 0;
        do
        {
          v7 = &model->subModels[v6];
          v8 = AcquireSubModelData(subModel: v7);
          v9 = v8;
          if ( v8->header.loadedSize != 32 )
          {
            idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(
              subModelPtrs: &baseTraceWork->subModelPtrs,
              subModelData: v8);
            idModelCheckCounts::SetupForSubModel(this: &baseTraceWork->modelCheckCounts, subModelData: v9);
            LODWORD(v10) = &cdQuery.failedQuery.parms.modelAxis;
            HIDWORD(v10) = &cdQuery.failedQuery.parms.modelOrigin;
            DrawNodePolygons(
              subModelPtrs: &baseTraceWork->subModelPtrs,
              origin: v10,
              axis: viewOrigin,
              viewOrigin: viewAxis->mat,
              viewAxis: v11,
              radius: 1024.0,
              lifeTime: 0,
              a8: v16);
          }
          ReleaseSubModelData(subModel: (const cm_subModelData_t *)v7, data: v9);
          model = cdQuery.failedQuery.model;
          ++v5;
          ++v6;
        }
        while ( v5 < cdQuery.failedQuery.model->numSubModels );
      }
      idCollisionQueryExecute::ExecutePolygonModelQuery(
        tw: baseTraceWork,
        results: &v53,
        parms: &cdQuery.failedQuery.parms,
        trm: cdQuery.failedQuery.trm,
        polygonModel: model);
    }
    else
    {
      idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(
        subModelPtrs: &baseTraceWork->subModelPtrs,
        subModelData: cdQuery.failedQuery.subModelData);
      idModelCheckCounts::SetupForSubModel(
        this: &baseTraceWork->modelCheckCounts,
        subModelData: cdQuery.failedQuery.subModelData);
      LODWORD(v13) = &cdQuery.failedQuery.parms.modelAxis;
      HIDWORD(v13) = &cdQuery.failedQuery.parms.modelOrigin;
      DrawNodePolygons(
        subModelPtrs: &baseTraceWork->subModelPtrs,
        origin: v13,
        axis: viewOrigin,
        viewOrigin: viewAxis->mat,
        viewAxis: v14,
        radius: 1024.0,
        lifeTime: 0,
        a8: v16);
      idCollisionQueryExecute::ExecuteSubModelQuery(
        tw: baseTraceWork,
        results: &v53,
        parms: &cdQuery.failedQuery.parms,
        trm: cdQuery.failedQuery.trm,
        subModelData: cdQuery.failedQuery.subModelData,
        subModelNum: cdQuery.failedQuery.subModelNum);
    }
    cm_color.y = 1.0;
    cm_color.x = 1.0;
    cm_color.z = 1.0;
    cm_color.w = 0.5;
    idCollisionModelManager::DrawCollisionModel(
      this: collisionModelManager,
      model: cdQuery.failedQuery.trmModel,
      modelJoints: nullptr,
      modelOrigin: (const idVec3 *)&cdQuery.failedQuery.results.data[4],
      modelAxis: (const idMat3 *)&cdQuery.failedQuery.results.data[16],
      viewOrigin: viewOrigin->mat,
      viewAxis,
      radius: 1024.0,
      lifeTime: v12,
      a10: (int)v16,
      a11: v18,
      a12: v20,
      a13: v22,
      a14: v24,
      a15: v26,
      a16: v28,
      a17: v30,
      a18: v32,
      a19: v34,
      a20: v36,
      a21: v38,
      a22: v40,
      a23: v42,
      a24: v44,
      a25: v46,
      a26: v48,
      a27: v50,
      a28: v52,
      a29: 0);
    cm_color.x = 1.0;
    cm_color.y = 0.0;
    cm_color.z = 0.0;
    cm_color.w = 0.5;
  }
}


// ========================================================================
// ?DebugOutput@idCollisionModelManager@@QAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x825DC798
// RVA : 0x005DC798
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __fastcall idCollisionModelManager::DebugOutput(
        idCollisionModelManager *this,
        const idMat3 *viewOrigin,
        const idMat3 *viewAxis)
{
  SpeedTest(origin: viewOrigin->mat);
  DebugTranslationFailure(viewOrigin: viewOrigin->mat, viewAxis);
  DebugRotationFailure(viewOrigin: viewOrigin->mat, viewAxis);
  DebugFailedQuery(viewOrigin, viewAxis);
}


// ========================================================================
// `dynamic initializer for 'cm_drawMask''
// EA  : 0x833353B8
// RVA : 0x013353B8
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_drawMask__()
{
  idCVar::idCVar(
    this: &cm_drawMask,
    name: "cm_drawMask",
    value: "none",
    flags: 0,
    description: "collision mask",
    valueStrings: cm_contentsNameByIndex,
    valueCompletion: idCmdSystem::ArgCompletion_String<&char const * * cm_contentsNameByIndex>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_drawMask__);
}


// ========================================================================
// `dynamic initializer for 'cm_drawColor''
// EA  : 0x83335418
// RVA : 0x01335418
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_drawColor__()
{
  idCVar::idCVar(
    this: &cm_drawColor,
    name: "cm_drawColor",
    value: "1 0 0 .5",
    flags: 0,
    description: "color used to draw the collision models",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_drawColor__);
}


// ========================================================================
// `dynamic initializer for 'cm_drawSurfaceColor''
// EA  : 0x83335470
// RVA : 0x01335470
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_drawSurfaceColor__()
{
  idCVar::idCVar(
    this: &cm_drawSurfaceColor,
    name: "cm_drawSurfaceColor",
    value: "0",
    flags: 1,
    description: "draw filled polygons with the surface color stored on the material",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_drawSurfaceColor__);
}


// ========================================================================
// `dynamic initializer for 'cm_drawFilled''
// EA  : 0x833354C8
// RVA : 0x013354C8
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_drawFilled__()
{
  idCVar::idCVar(
    this: &cm_drawFilled,
    name: "cm_drawFilled",
    value: "0",
    flags: 1,
    description: "draw filled polygons",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_drawFilled__);
}


// ========================================================================
// `dynamic initializer for 'cm_drawInternal''
// EA  : 0x83335520
// RVA : 0x01335520
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_drawInternal__()
{
  idCVar::idCVar(
    this: &cm_drawInternal,
    name: "cm_drawInternal",
    value: "1",
    flags: 1,
    description: "draw internal edges green",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_drawInternal__);
}


// ========================================================================
// `dynamic initializer for 'cm_drawNormals''
// EA  : 0x83335578
// RVA : 0x01335578
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_drawNormals__()
{
  idCVar::idCVar(
    this: &cm_drawNormals,
    name: "cm_drawNormals",
    value: "0",
    flags: 4,
    description: "draw polygon and edge normals",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_drawNormals__);
}


// ========================================================================
// `dynamic initializer for 'cm_drawIndices''
// EA  : 0x833355D0
// RVA : 0x013355D0
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_drawIndices__()
{
  idCVar::idCVar(
    this: &cm_drawIndices,
    name: "cm_drawIndices",
    value: "0",
    flags: 1,
    description: "draw primitive indices",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_drawIndices__);
}


// ========================================================================
// `dynamic initializer for 'cm_drawIndexScale''
// EA  : 0x83335628
// RVA : 0x01335628
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_drawIndexScale__()
{
  idCVar::idCVar(
    this: &cm_drawIndexScale,
    name: "cm_drawIndexScale",
    value: "0.02",
    flags: 4,
    description: "scale of primitive indices",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_drawIndexScale__);
}


// ========================================================================
// `dynamic initializer for 'cm_drawSubModelBounds''
// EA  : 0x83335680
// RVA : 0x01335680
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_drawSubModelBounds__()
{
  idCVar::idCVar(
    this: &cm_drawSubModelBounds,
    name: "cm_drawSubModelBounds",
    value: "0",
    flags: 1,
    description: "draw sub model bounds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_drawSubModelBounds__);
}


// ========================================================================
// `dynamic initializer for 'cm_backFaceCull''
// EA  : 0x833356D8
// RVA : 0x013356D8
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_backFaceCull__()
{
  idCVar::idCVar(
    this: &cm_backFaceCull,
    name: "cm_backFaceCull",
    value: "0",
    flags: 1,
    description: "cull back facing polygons",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_backFaceCull__);
}


// ========================================================================
// `dynamic initializer for 'cm_debugCollision''
// EA  : 0x83335730
// RVA : 0x01335730
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_debugCollision__()
{
  idCVar::idCVar(
    this: &cm_debugCollision,
    name: "cm_debugCollision",
    value: "0",
    flags: 1,
    description: "debug the collision detection",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_debugCollision__);
}


// ========================================================================
// `dynamic initializer for 'cm_debugSetParms''
// EA  : 0x83335788
// RVA : 0x01335788
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_debugSetParms__()
{
  idCVar::idCVar(
    this: &cm_debugSetParms,
    name: "cm_debugSetParms",
    value: "1",
    flags: 1,
    description: "debug set parameters",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_debugSetParms__);
}


// ========================================================================
// `dynamic initializer for 'cm_debugTranslation''
// EA  : 0x833357E0
// RVA : 0x013357E0
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_debugTranslation__()
{
  idCVar::idCVar(
    this: &cm_debugTranslation,
    name: "cm_debugTranslation",
    value: "1",
    flags: 1,
    description: "debug translation failure",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_debugTranslation__);
}


// ========================================================================
// `dynamic initializer for 'cm_debugRotation''
// EA  : 0x83335838
// RVA : 0x01335838
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_debugRotation__()
{
  idCVar::idCVar(
    this: &cm_debugRotation,
    name: "cm_debugRotation",
    value: "1",
    flags: 1,
    description: "debug rotation failure",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_debugRotation__);
}


// ========================================================================
// `dynamic initializer for 'cm_drawArrows''
// EA  : 0x83335890
// RVA : 0x01335890
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_drawArrows__()
{
  idCVar::idCVar(
    this: &cm_drawArrows,
    name: "cm_drawArrows",
    value: "0",
    flags: 1,
    description: "1 = draw edges as arrows, 0 = draw edges as lines",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_drawArrows__);
}


// ========================================================================
// `dynamic initializer for 'cm_depthTest''
// EA  : 0x833358E8
// RVA : 0x013358E8
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_depthTest__()
{
  idCVar::idCVar(
    this: &cm_depthTest,
    name: "cm_depthTest",
    value: "0",
    flags: 1,
    description: "depth test the collision model primitives",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_depthTest__);
}


// ========================================================================
// `dynamic initializer for 'cm_testCollision''
// EA  : 0x83335940
// RVA : 0x01335940
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_testCollision__()
{
  idCVar::idCVar(
    this: &cm_testCollision,
    name: "cm_testCollision",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_testCollision__);
}


// ========================================================================
// `dynamic initializer for 'cm_testTranslation''
// EA  : 0x83335998
// RVA : 0x01335998
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_testTranslation__()
{
  idCVar::idCVar(
    this: &cm_testTranslation,
    name: "cm_testTranslation",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_testTranslation__);
}


// ========================================================================
// `dynamic initializer for 'cm_testRotation''
// EA  : 0x833359F0
// RVA : 0x013359F0
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_testRotation__()
{
  idCVar::idCVar(
    this: &cm_testRotation,
    name: "cm_testRotation",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_testRotation__);
}


// ========================================================================
// `dynamic initializer for 'cm_testModel''
// EA  : 0x83335A48
// RVA : 0x01335A48
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_testModel__()
{
  idCVar::idCVar(
    this: &cm_testModel,
    name: "cm_testModel",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_testModel__);
}


// ========================================================================
// `dynamic initializer for 'cm_testTimes''
// EA  : 0x83335AA0
// RVA : 0x01335AA0
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_testTimes__()
{
  idCVar::idCVar(
    this: &cm_testTimes,
    name: "cm_testTimes",
    value: "1000",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_testTimes__);
}


// ========================================================================
// `dynamic initializer for 'cm_testRandomMany''
// EA  : 0x83335AF8
// RVA : 0x01335AF8
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_testRandomMany__()
{
  idCVar::idCVar(
    this: &cm_testRandomMany,
    name: "cm_testRandomMany",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_testRandomMany__);
}


// ========================================================================
// `dynamic initializer for 'cm_testOrigin''
// EA  : 0x83335B50
// RVA : 0x01335B50
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_testOrigin__()
{
  idCVar::idCVar(
    this: &cm_testOrigin,
    name: "cm_testOrigin",
    value: "0 0 0",
    flags: 0,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_testOrigin__);
}


// ========================================================================
// `dynamic initializer for 'cm_testReset''
// EA  : 0x83335BA8
// RVA : 0x01335BA8
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_testReset__()
{
  idCVar::idCVar(
    this: &cm_testReset,
    name: "cm_testReset",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_testReset__);
}


// ========================================================================
// `dynamic initializer for 'cm_testBox''
// EA  : 0x83335C00
// RVA : 0x01335C00
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_testBox__()
{
  idCVar::idCVar(
    this: &cm_testBox,
    name: "cm_testBox",
    value: "-16 -16 0 16 16 64",
    flags: 0,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_testBox__);
}


// ========================================================================
// `dynamic initializer for 'cm_testBoxRotation''
// EA  : 0x83335C58
// RVA : 0x01335C58
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_testBoxRotation__()
{
  idCVar::idCVar(
    this: &cm_testBoxRotation,
    name: "cm_testBoxRotation",
    value: "0 0 0",
    flags: 0,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_testBoxRotation__);
}


// ========================================================================
// `dynamic initializer for 'cm_testWalk''
// EA  : 0x83335CB0
// RVA : 0x01335CB0
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_testWalk__()
{
  idCVar::idCVar(
    this: &cm_testWalk,
    name: "cm_testWalk",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_testWalk__);
}


// ========================================================================
// `dynamic initializer for 'cm_testLength''
// EA  : 0x83335D08
// RVA : 0x01335D08
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_testLength__()
{
  idCVar::idCVar(
    this: &cm_testLength,
    name: "cm_testLength",
    value: "1024",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_testLength__);
}


// ========================================================================
// `dynamic initializer for 'cm_testRadius''
// EA  : 0x83335D60
// RVA : 0x01335D60
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_testRadius__()
{
  idCVar::idCVar(
    this: &cm_testRadius,
    name: "cm_testRadius",
    value: "64",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_testRadius__);
}


// ========================================================================
// `dynamic initializer for 'cm_testAngle''
// EA  : 0x83335DB8
// RVA : 0x01335DB8
// PDB : w:\tech5\engine\cm\collisionmodelmanager_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_testAngle__()
{
  idCVar::idCVar(
    this: &cm_testAngle,
    name: "cm_testAngle",
    value: "60",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_testAngle__);
}

