
// ========================================================================
// ?TestTrmVertsInPolytope@idPolygonModelCollisionDetection@@CA_NPAVidTraceWork@@I@Z
// EA  : 0x825E9EE0
// RVA : 0x005E9EE0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_contents.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::TestTrmVertsInPolytope(idTraceWork *tw, int polytopeNum)
{
  unsigned __int8 *polytopeCheckCounts; // r9
  char v5; // r7
  int v6; // r5
  unsigned __int8 v11; // cr58
  unsigned __int8 v12; // cr59
  unsigned int numVerts; // r28
  int v14; // r29
  int numPlanes; // r30
  idVec4 *i; // r5
  int v17; // r3
  double v18; // fp9
  int v19; // r9
  int firstPlane; // r31
  idPlane *polytopePlanes; // r6
  int v22; // r7
  float *v23; // r10
  double v24; // fp0
  double v25; // fp0
  float *v26; // r10
  double v27; // fp0
  float *v28; // r10
  double v29; // fp0
  float *p_a; // r10
  double v31; // fp0
  float *p_fraction; // r9
  float *v34; // r10
  float *v35; // r10

  polytopeCheckCounts = tw->modelCheckCounts.polytopeCheckCounts;
  _R11 = tw;
  v5 = 1 << (polytopeNum & 7);
  v6 = (unsigned __int8)(polytopeCheckCounts[polytopeNum >> 3] & v5);
  polytopeCheckCounts[polytopeNum >> 3] |= v5;
  if ( v6 != 0 )
    return 0;
  _R8 = &tw->subModelPtrs.polytopes[polytopeNum];
  if ( (*(int *)((_BYTE *)&tw->subModelPtrs.materials->contentFlags + __ROL4__(_R8->material, 4)) & tw->contents) == 0 )
    return 0;
  __asm { lvx128    v63, r0, r8 }
  _R9 = 6176;
  _R7 = vmxi_half_bnds_intersect_perm2_3;
  _R6 = -16;
  __asm
  {
    lvx128    v62, r11, r9
    lvx128    v0, r0, r7
    lvx128    v7, r7, r6
    vperm128  v0, v94, v63, v0
    vperm128  v13, v94, v63, v7
    vcmpgtsh. v12, v13, v0
  }
  if ( ((32 * v11) & 0x20 | (16 * v12) & 0x20) == 0 )
    return 0;
  numVerts = tw->numVerts;
  v14 = 0;
  if ( numVerts == 0 )
    return 0;
  numPlanes = _R8->numPlanes;
  for ( i = tw->vertexPosition; ; ++i )
  {
    v17 = 0;
    v18 = -1.0e30;
    v19 = 0;
    if ( _R8->numPlanes < 4u )
    {
LABEL_21:
      if ( v19 >= numPlanes )
        break;
      do
      {
        p_a = &_R11->subModelPtrs.polytopePlanes[_R8->firstPlane + v19].a;
        v31 = (float)((float)((float)(i->x * *p_a) + (float)((float)(p_a[1] * i->y) + (float)(p_a[2] * i->z))) + p_a[3]);
        if ( v31 >= 0.0 )
          break;
        if ( v31 > v18 )
        {
          v18 = (float)((float)((float)(i->x * *p_a) + (float)((float)(p_a[1] * i->y) + (float)(p_a[2] * i->z))) + p_a[3]);
          v17 = v19;
        }
        ++v19;
      }
      while ( v19 < numPlanes );
    }
    else
    {
      firstPlane = _R8->firstPlane;
      polytopePlanes = _R11->subModelPtrs.polytopePlanes;
      while ( 1 )
      {
        v22 = firstPlane + v19;
        v23 = &polytopePlanes[firstPlane + v19].a;
        v24 = (float)((float)((float)(i->x * *v23) + (float)((float)(v23[2] * i->z) + (float)(v23[1] * i->y))) + v23[3]);
        if ( v24 >= 0.0 )
          break;
        if ( v24 > v18 )
        {
          v18 = (float)((float)((float)(i->x * *v23) + (float)((float)(v23[2] * i->z) + (float)(v23[1] * i->y))) + v23[3]);
          v17 = v19;
        }
        v25 = (float)((float)((float)(i->x * v23[4]) + (float)((float)(v23[6] * i->z) + (float)(v23[5] * i->y))) + v23[7]);
        if ( v25 >= 0.0 )
        {
          ++v19;
          break;
        }
        if ( v25 > v18 )
        {
          v18 = (float)((float)((float)(i->x * v23[4]) + (float)((float)(v23[6] * i->z) + (float)(v23[5] * i->y)))
                      + v23[7]);
          v17 = v19 + 1;
        }
        v26 = &polytopePlanes[v22 + 2].a;
        v27 = (float)((float)((float)(i->x * *v26) + (float)((float)(v26[2] * i->z) + (float)(v26[1] * i->y))) + v26[3]);
        if ( v27 >= 0.0 )
        {
          v19 += 2;
          break;
        }
        if ( v27 > v18 )
        {
          v18 = (float)((float)((float)(i->x * *v26) + (float)((float)(v26[2] * i->z) + (float)(v26[1] * i->y))) + v26[3]);
          v17 = v19 + 2;
        }
        v28 = &polytopePlanes[v22 + 3].a;
        v29 = (float)((float)((float)(i->x * *v28) + (float)((float)(v28[2] * i->z) + (float)(v28[1] * i->y))) + v28[3]);
        if ( v29 >= 0.0 )
        {
          v19 += 3;
          break;
        }
        if ( v29 > v18 )
        {
          v18 = (float)((float)((float)(i->x * *v28) + (float)((float)(v28[2] * i->z) + (float)(v28[1] * i->y))) + v28[3]);
          v17 = v19 + 3;
        }
        v19 += 4;
        if ( v19 >= numPlanes - 3 )
          goto LABEL_21;
      }
    }
    if ( v19 >= numPlanes )
      break;
    if ( ++v14 >= numVerts )
      return 0;
  }
  _R11->traceResult->fraction = 0.0;
  _R11->traceResult->c.type = CONTACT_TRMVERTEX;
  p_fraction = &_R11->traceResult->fraction;
  v34 = &_R11->subModelPtrs.polytopePlanes[_R8->firstPlane + v17].a;
  p_fraction[17] = *v34;
  p_fraction[18] = v34[1];
  p_fraction[19] = v34[2];
  _R11->traceResult->c.dist = -_R11->subModelPtrs.polytopePlanes[_R8->firstPlane + v17].d;
  _R11->traceResult->c.separation = 0.0;
  _R11->traceResult->c.contentFlags = *(int *)((char *)&_R11->subModelPtrs.materials->contentFlags
                                             + __ROL4__(_R8->material, 4));
  _R11->traceResult->c.surfaceFlags = *(int *)((char *)&_R11->subModelPtrs.materials->surfaceFlags
                                             + __ROL4__(_R8->material, 4));
  _R11->traceResult->c.surfaceType = *(int *)((char *)&_R11->subModelPtrs.materials->surfaceType
                                            + __ROL4__(_R8->material, 4));
  _R11->traceResult->c.surfaceColor[0] = _R11->subModelPtrs.materials->surfaceColor[__ROL4__(_R8->material, 4)];
  _R11->traceResult->c.surfaceColor[1] = _R11->subModelPtrs.materials->surfaceColor[__ROL4__(_R8->material, 4) + 1];
  _R11->traceResult->c.surfaceColor[2] = _R11->subModelPtrs.materials->surfaceColor[__ROL4__(_R8->material, 4) + 2];
  v35 = &_R11->traceResult->fraction;
  v35[14] = i->x;
  v35[15] = i->y;
  v35[16] = i->z;
  _R11->traceResult->c.modelFeature = (_R11->subModelNum << 16) & 0x1FFF0000
                                    | 0x80000000
                                    | (unsigned __int16)polytopeNum;
  _R11->traceResult->c.trmFeature = v14;
  _R11->traceResult->c.flags = 0;
  return 1;
}


// ========================================================================
// ?TestTrmInPolygon@idPolygonModelCollisionDetection@@CA_NPAVidTraceWork@@I@Z
// EA  : 0x825EA310
// RVA : 0x005EA310
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_contents.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::TestTrmInPolygon(idTraceWork *tw, int polygonNum)
{
  unsigned __int16 v3; // r24
  int v4; // r6
  int v5; // r5
  idModelCheckCounts *p_modelCheckCounts; // r22
  unsigned __int8 v12; // cr58
  unsigned __int8 v13; // cr59
  cm_subModelPtrs_t *p_subModelPtrs; // r29
  int v15; // r3
  unsigned int v17; // r28
  _WORD *v18; // r29
  int v19; // r10
  int v20; // r5
  int v21; // r4
  _WORD *v22; // r6
  unsigned int v23; // r7
  double v24; // fp10
  float *v25; // r9
  int v26; // r8
  unsigned int v27; // r11
  float *v28; // r10
  double v29; // fp0
  unsigned int numEdges; // r11
  unsigned int v31; // r8
  float *p_side; // r9
  unsigned int v33; // r6
  cm_vertex_t *vertices; // r10
  cm_edge_t *v35; // r11
  int v36; // r6
  float *v37; // r11
  float *v38; // r10
  unsigned int v39; // r4
  cm_sideCache_t *p_polygonSideCache; // r3
  float *v41; // r6
  unsigned int v42; // r8
  unsigned int v43; // r10
  int v44; // r9
  float *v45; // r11
  int v46; // r7
  unsigned int v47; // r5
  cm_sideCache_t *v48; // r4
  unsigned int v49; // r9
  unsigned int v50; // r11
  int v51; // r10
  unsigned int numPolys; // r29
  unsigned int v53; // r8
  float *v54; // r7
  double v55; // fp0
  double v56; // fp13
  float *p_b; // r8
  double v58; // fp12
  int v59; // r7
  double d; // fp0
  unsigned int v61; // r10
  double c; // fp13
  double b; // fp12
  double a; // fp11
  unsigned int numVerts; // r7
  float *p_z; // r11
  float *p_d; // r8
  unsigned int v68; // r9
  unsigned __int16 *vertexNum; // r4
  unsigned int v70; // r8
  unsigned int v71; // r5
  unsigned int v72; // r11
  cm_sideCache_t *polygonEdgeSideCache; // r10
  int v74; // r4
  cm_sideCache_t *i; // r27
  unsigned __int8 *edgeCheckCounts; // r8
  unsigned __int16 v77; // r5
  int v78; // r11
  char v79; // r6
  int v80; // r7
  int v81; // r8
  int v82; // r29
  unsigned int v83; // r9
  unsigned int side; // r3
  unsigned int *p_numEdges; // r5
  unsigned int v86; // r6
  unsigned int v87; // r10
  unsigned int j; // r11
  float *v89; // r11
  float *v90; // r10
  double v91; // fp9
  double v92; // fp11
  float *v93; // r11
  int v94; // r9
  float *p_x; // r11
  float *p_fraction; // r10
  float *v97; // r10
  float *p_a; // r11
  int v99; // r4
  float *v100; // r10
  double v101; // fp12
  double v102; // fp11
  float *v103; // r10
  float *v104; // r11
  idPlane v105[15]; // [sp+50h] [-F0h] BYREF

  v3 = polygonNum;
  v4 = tw->modelCheckCounts.polygonCheckCounts[polygonNum >> 3];
  v5 = (unsigned __int8)(1 << (polygonNum & 7));
  _R31 = tw;
  p_modelCheckCounts = &tw->modelCheckCounts;
  tw->modelCheckCounts.polygonCheckCounts[polygonNum >> 3] = v4 | v5;
  if ( (v4 & v5) != 0 )
    return 0;
  _R30 = &tw->subModelPtrs.polygons[polygonNum];
  if ( (*(int *)((_BYTE *)&tw->subModelPtrs.materials->contentFlags + __ROL4__(_R30->material, 4)) & tw->contents) == 0 )
    return 0;
  __asm { lvx128    v63, r0, r30 }
  _R10 = 6176;
  _R9 = vmxi_half_bnds_intersect_perm2_3;
  _R8 = -16;
  __asm
  {
    lvx128    v62, r31, r10
    lvx128    v0, r0, r9
    lvx128    v7, r9, r8
    vperm128  v0, v94, v63, v0
    vperm128  v13, v94, v63, v7
    vcmpgtsh. v12, v13, v0
  }
  if ( ((32 * v12) & 0x20 | (16 * v13) & 0x20) == 0 )
    return 0;
  p_subModelPtrs = &tw->subModelPtrs;
  CM_GetPolygonPlane(subModel: &tw->subModelPtrs, polygon: _R30, plane: v105);
  v15 = CM_BoundsPlaneSide(boundsMin: &_R31->traceBoundsMin, boundsMax: &_R31->traceBoundsMax, plane: v105);
  if ( v15 != 3 )
  {
    if ( v15 == 0 && p_subModelPtrs->isConvex != 0 )
    {
      _R31->quickExit = true;
      return 1;
    }
    return 0;
  }
  if ( !_R31->isConvex || (v17 = 0, _R30->numEdges == 0) )
  {
LABEL_23:
    numEdges = _R30->numEdges;
    v31 = 0;
    if ( _R30->numEdges != 0 )
    {
      p_side = (float *)&_R31->polygonVertexSideCache[19].side;
      do
      {
        v33 = _R30->firstEdge + v31;
        vertices = _R31->subModelPtrs.vertices;
        ++v31;
        v35 = &_R31->subModelPtrs.edges[_R31->subModelPtrs.polygonEdges[v33] & 0x3FFF];
        v36 = v35->vertexNum[0];
        v37 = (float *)((char *)&vertices->p.x + __ROL4__(v35->vertexNum[1], 4));
        v38 = (float *)((char *)&vertices->p.x + __ROL4__(v36, 4));
        p_side[1] = (float)(v37[1] * *v38) - (float)(v38[1] * *v37);
        p_side[2] = (float)(*v38 * v37[2]) - (float)(v38[2] * *v37);
        p_side[3] = *v38 - *v37;
        p_side[4] = (float)(v38[1] * v37[2]) - (float)(v37[1] * v38[2]);
        p_side[5] = v38[2] - v37[2];
        p_side += 6;
        *p_side = v37[1] - v38[1];
        numEdges = _R30->numEdges;
      }
      while ( v31 < numEdges );
    }
    v39 = 0;
    if ( numEdges != 0 )
    {
      p_polygonSideCache = &_R31->polygonSideCache;
      v41 = &_R31->polygonEdgePlueckerCache[0].p[2];
      do
      {
        v42 = 0;
        v43 = 0;
        v44 = 1;
        if ( _R31->numEdges != 0 )
        {
          v45 = &_R31->edgePluecker[0].p[3];
          do
          {
            v46 = v44;
            if ( (float)((float)(*v45 * *v41)
                       + (float)((float)(v45[2] * *(v41 - 1))
                               + (float)((float)(*(v45 - 2) * v41[3])
                                       + (float)((float)(*(v45 - 1) * v41[1])
                                               + (float)((float)(v45[1] * *(v41 - 2)) + (float)(*(v45 - 3) * v41[2])))))) >= 0.0 )
              v46 = 0;
            ++v43;
            v42 |= v46;
            v45 += 6;
            v44 *= 2;
          }
          while ( v43 < _R31->numEdges );
        }
        ++v39;
        ++p_polygonSideCache;
        p_polygonSideCache->side = v42;
        numEdges = _R30->numEdges;
        v41 += 6;
      }
      while ( v39 < numEdges );
    }
    v47 = 0;
    if ( numEdges != 0 )
    {
      v48 = &_R31->polygonEdgeSideCache[19];
      do
      {
        v49 = 0;
        v50 = 0;
        v51 = 1;
        numPolys = _R31->numPolys;
        v53 = _R31->subModelPtrs.polygonEdges[_R30->firstEdge + v47];
        v54 = (float *)((char *)&_R31->subModelPtrs.vertices->p.x
                      + __ROL4__(_R31->subModelPtrs.edges->vertexNum[(v53 >> 15) + ((2 * v53) & 0x7FFE)], 4));
        if ( numPolys != 0 )
        {
          v55 = v54[2];
          v56 = v54[1];
          p_b = &_R31->polys[0].plane.b;
          v58 = *v54;
          do
          {
            v59 = v51;
            if ( (float)((float)((float)((float)v55 * p_b[1])
                               + (float)((float)((float)v58 * *(p_b - 1)) + (float)((float)v56 * *p_b)))
                       + p_b[2]) >= 0.0 )
              v59 = 0;
            ++v50;
            v49 |= v59;
            p_b += 16;
            v51 *= 2;
          }
          while ( v50 < numPolys );
        }
        ++v47;
        ++v48;
        v48->side = v49;
        numEdges = _R30->numEdges;
      }
      while ( v47 < numEdges );
    }
    d = v105[0].d;
    v61 = 0;
    c = v105[0].c;
    b = v105[0].b;
    a = v105[0].a;
    _R31->polygonVertexSideCache[numEdges].side = _R31->polygonVertexSideCache[0].side;
    numVerts = _R31->numVerts;
    if ( numVerts != 0 )
    {
      p_z = &_R31->vertexPosition[0].z;
      p_d = &v105[0].d;
      do
      {
        ++v61;
        *(_DWORD *)++p_d = (float)((float)((float)((float)a * *(p_z - 2))
                                         + (float)((float)((float)c * *p_z) + (float)((float)b * *(p_z - 1))))
                                 + (float)d) < 0.0;
        p_z += 4;
      }
      while ( v61 < numVerts );
    }
    v68 = 0;
    if ( _R31->numEdges != 0 )
    {
      vertexNum = _R31->edges[0].vertexNum;
      while ( 1 )
      {
        v70 = *(_DWORD *)((char *)&v105[1].a + __ROL4__(*vertexNum, 2));
        if ( v70 != *(_DWORD *)((char *)&v105[1].a + __ROL4__(vertexNum[1], 2)) )
        {
          v71 = _R30->numEdges;
          v72 = 0;
          if ( _R30->numEdges != 0 )
          {
            polygonEdgeSideCache = _R31->polygonEdgeSideCache;
            do
            {
              if ( ((_R31->subModelPtrs.polygonEdges[_R30->firstEdge + v72] >> 15)
                  ^ (polygonEdgeSideCache->side >> v68)
                  & 1
                  ^ v70) != 0 )
                break;
              ++v72;
              ++polygonEdgeSideCache;
            }
            while ( v72 < v71 );
          }
          if ( v72 >= v71 )
            break;
        }
        ++v68;
        vertexNum += 8;
        if ( v68 >= _R31->numEdges )
          goto LABEL_54;
      }
      v94 = _R31->edges[v68].vertexNum[(_cntlzw(v70) & 0x20) != 0];
      _R31->traceResult->fraction = 0.0;
      p_x = &_R31->vertexPosition[v94].x;
      _R31->traceResult->c.type = CONTACT_TRMVERTEX;
      p_fraction = &_R31->traceResult->fraction;
      p_fraction[18] = b;
      p_fraction[17] = a;
      p_fraction[19] = c;
      _R31->traceResult->c.dist = -d;
      _R31->traceResult->c.separation = 0.0;
      _R31->traceResult->c.contentFlags = *(int *)((char *)&_R31->subModelPtrs.materials->contentFlags
                                                 + __ROL4__(_R30->material, 4));
      _R31->traceResult->c.surfaceFlags = *(int *)((char *)&_R31->subModelPtrs.materials->surfaceFlags
                                                 + __ROL4__(_R30->material, 4));
      _R31->traceResult->c.surfaceType = *(int *)((char *)&_R31->subModelPtrs.materials->surfaceType
                                                + __ROL4__(_R30->material, 4));
      _R31->traceResult->c.surfaceColor[0] = _R31->subModelPtrs.materials->surfaceColor[__ROL4__(_R30->material, 4)];
      _R31->traceResult->c.surfaceColor[1] = _R31->subModelPtrs.materials->surfaceColor[__ROL4__(_R30->material, 4) + 1];
      _R31->traceResult->c.surfaceColor[2] = _R31->subModelPtrs.materials->surfaceColor[__ROL4__(_R30->material, 4) + 2];
      v97 = &_R31->traceResult->fraction;
      v97[14] = *p_x;
      v97[15] = p_x[1];
      v97[16] = p_x[2];
      _R31->traceResult->c.modelFeature = (_R31->subModelNum << 16) & 0x1FFF0000 | 0x60000000 | v3;
      _R31->traceResult->c.trmFeature = v94;
      _R31->traceResult->c.flags = 0;
      return 1;
    }
LABEL_54:
    v74 = 0;
    if ( _R30->numEdges != 0 )
    {
      for ( i = _R31->polygonEdgeSideCache; ; ++i )
      {
        edgeCheckCounts = p_modelCheckCounts->edgeCheckCounts;
        v77 = _R31->subModelPtrs.polygonEdges[_R30->firstEdge + v74];
        v78 = (v77 & 0x3FFF) >> 3;
        v79 = 1 << (v77 & 7);
        v80 = (unsigned __int8)(edgeCheckCounts[v78] & v79);
        edgeCheckCounts[v78] |= v79;
        if ( v80 == 0 )
        {
          v81 = 2 * (((~v77 & 0x8000) != 0) + v74 + 1620);
          v82 = (int)&_R31->subModelPtrs.edges[v77 & 0x3FFF];
          v83 = 0;
          if ( _R31->numPolys != 0 )
            break;
        }
LABEL_65:
        if ( ++v74 >= (unsigned int)_R30->numEdges )
          return 0;
      }
      side = _R31->polygonVertexSideCache[(v77 >> 15) + v74].side;
      p_numEdges = &_R31->polys[0].numEdges;
      while ( 1 )
      {
        if ( (((*(_DWORD *)&_R31->verts[0].bounds.b[0][v81] ^ side) >> v83) & 1) != 0 )
        {
          v86 = *p_numEdges;
          v87 = (side >> v83) & 1;
          for ( j = 0; j < v86; ++j )
          {
            if ( ((i->side >> (*((_BYTE *)p_numEdges + j + 4) & 0x7F))
                & 1
                ^ (*((unsigned __int8 *)p_numEdges + j + 4) >> 7)
                ^ v87) != 0 )
              break;
          }
          if ( j >= v86 )
            break;
        }
        ++v83;
        p_numEdges += 16;
        if ( v83 >= _R31->numPolys )
          goto LABEL_65;
      }
      p_a = &_R31->polys[v83].plane.a;
      v99 = *(unsigned __int16 *)(((_cntlzw(v87) >> 4) & 2) + v82);
      _R31->traceResult->fraction = 0.0;
      _R31->traceResult->c.type = CONTACT_MODELVERTEX;
      v100 = &_R31->traceResult->fraction;
      v101 = -p_a[2];
      v102 = *p_a;
      v100[18] = -p_a[1];
      v100[19] = v101;
      v100[17] = -v102;
      _R31->traceResult->c.dist = _R31->polys[v83].plane.d;
      _R31->traceResult->c.separation = 0.0;
      _R31->traceResult->c.contentFlags = *(int *)((char *)&_R31->subModelPtrs.materials->contentFlags
                                                 + __ROL4__(_R30->material, 4));
      _R31->traceResult->c.surfaceFlags = *(int *)((char *)&_R31->subModelPtrs.materials->surfaceFlags
                                                 + __ROL4__(_R30->material, 4));
      _R31->traceResult->c.surfaceType = *(int *)((char *)&_R31->subModelPtrs.materials->surfaceType
                                                + __ROL4__(_R30->material, 4));
      _R31->traceResult->c.surfaceColor[0] = _R31->subModelPtrs.materials->surfaceColor[__ROL4__(_R30->material, 4)];
      _R31->traceResult->c.surfaceColor[1] = _R31->subModelPtrs.materials->surfaceColor[__ROL4__(_R30->material, 4) + 1];
      _R31->traceResult->c.surfaceColor[2] = _R31->subModelPtrs.materials->surfaceColor[__ROL4__(_R30->material, 4) + 2];
      v103 = &_R31->traceResult->fraction;
      v104 = (float *)((char *)&_R31->subModelPtrs.vertices->p.x + __ROL4__(v99, 4));
      v103[14] = *v104;
      v103[15] = v104[1];
      v103[16] = v104[2];
      _R31->traceResult->c.modelFeature = (_R31->subModelNum << 16) & 0x1FFF0000 | 0x20000000 | v99;
      _R31->traceResult->c.trmFeature = v83;
      _R31->traceResult->c.flags = 0;
      return 1;
    }
    return 0;
  }
  v18 = (unsigned __int16 *)((char *)_R31->subModelPtrs.polygonEdges + __ROL4__(_R30->firstEdge, 1));
  while ( 1 )
  {
    v19 = *v18 & 0x3FFF;
    if ( ((1 << (*v18 & 7)) & _R31->modelCheckCounts.edgeCheckCounts[v19 >> 3]) == 0 )
      break;
LABEL_22:
    ++v17;
    ++v18;
    if ( v17 >= _R30->numEdges )
      goto LABEL_23;
  }
  v20 = 0;
  v21 = (int)&_R31->subModelPtrs.edges[v19];
  v22 = (_WORD *)v21;
  while ( 1 )
  {
    if ( ((1 << (*v22 & 7)) & _R31->modelCheckCounts.vertexCheckCounts[(int)(unsigned __int16)*v22 >> 3]) == 0 )
    {
      v23 = _R31->numPolys;
      v24 = -1.0e30;
      v25 = &_R31->subModelPtrs.vertices[(unsigned __int16)*v22].p.x;
      v26 = 0;
      v27 = 0;
      if ( v23 != 0 )
      {
        v28 = &_R31->polys[0].plane.b;
        do
        {
          v29 = (float)((float)((float)(*v25 * *(v28 - 1)) + (float)((float)(v25[2] * v28[1]) + (float)(v25[1] * *v28)))
                      + v28[2]);
          if ( v29 >= 0.0 )
            break;
          if ( v29 > v24 )
          {
            v24 = (float)((float)((float)(*v25 * *(v28 - 1)) + (float)((float)(v25[2] * v28[1]) + (float)(v25[1] * *v28)))
                        + v28[2]);
            v26 = v27;
          }
          ++v27;
          v28 += 16;
        }
        while ( v27 < _R31->numPolys );
      }
      if ( v27 >= v23 )
        break;
    }
    ++v20;
    ++v22;
    if ( v20 >= 2 )
      goto LABEL_22;
  }
  v89 = &_R31->polys[v26].plane.a;
  _R31->traceResult->fraction = 0.0;
  _R31->traceResult->c.type = CONTACT_MODELVERTEX;
  v90 = &_R31->traceResult->fraction;
  v91 = -v89[1];
  v92 = v89[2];
  v90[17] = -*v89;
  v90[18] = v91;
  v90[19] = -v92;
  _R31->traceResult->c.dist = _R31->polys[v26].plane.d;
  _R31->traceResult->c.separation = 0.0;
  _R31->traceResult->c.contentFlags = *(int *)((char *)&_R31->subModelPtrs.materials->contentFlags
                                             + __ROL4__(_R30->material, 4));
  _R31->traceResult->c.surfaceFlags = *(int *)((char *)&_R31->subModelPtrs.materials->surfaceFlags
                                             + __ROL4__(_R30->material, 4));
  _R31->traceResult->c.surfaceType = *(int *)((char *)&_R31->subModelPtrs.materials->surfaceType
                                            + __ROL4__(_R30->material, 4));
  _R31->traceResult->c.surfaceColor[0] = _R31->subModelPtrs.materials->surfaceColor[__ROL4__(_R30->material, 4)];
  _R31->traceResult->c.surfaceColor[1] = _R31->subModelPtrs.materials->surfaceColor[__ROL4__(_R30->material, 4) + 1];
  _R31->traceResult->c.surfaceColor[2] = _R31->subModelPtrs.materials->surfaceColor[__ROL4__(_R30->material, 4) + 2];
  v93 = &_R31->traceResult->fraction;
  v93[14] = *v25;
  v93[15] = v25[1];
  v93[16] = v25[2];
  _R31->traceResult->c.modelFeature = (_R31->subModelNum << 16) & 0x1FFF0000
                                    | 0x20000000
                                    | *(unsigned __int16 *)(2 * v20 + v21);
  _R31->traceResult->c.trmFeature = v26;
  _R31->traceResult->c.flags = 0;
  return 1;
}


// ========================================================================
// ?StartContents@idPolygonModelCollisionDetection@@SAXPAVidTraceWork@@PAUtrace_t@@ABVidVec3@@PBVidTraceModel@@ABVidMat3@@H24@Z
// EA  : 0x825EAEA0
// RVA : 0x005EAEA0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_contents.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::StartContents(
        idTraceWork *tw,
        trace_t *result,
        const idVec3 *start,
        const idTraceModel *trm,
        const idMat3 *trmAxis,
        int contentMask,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis)
{
  double y; // fp5
  double z; // fp30
  double v20; // fp29
  double v21; // fp28
  double v22; // fp11
  double v23; // fp9
  double v24; // fp7
  double x; // fp0
  double v26; // fp6
  double v27; // fp7
  double v28; // fp8
  double v29; // fp9
  double v30; // fp11
  double v31; // fp12
  double v32; // fp3
  double v33; // fp5
  double v34; // fp2
  double v35; // fp10
  double v36; // fp13
  double v37; // fp4
  char v38; // r10
  double v39; // fp4
  double v40; // fp2
  double v41; // fp13
  double v42; // fp11
  double v43; // fp10
  double v44; // fp9
  unsigned int v47; // r9
  unsigned int numVerts; // r10
  float *vertsZ; // r10
  float *p_z; // r11
  double v51; // fp0
  double v52; // fp31
  double v53; // fp0
  unsigned int v54; // r6
  double v55; // fp1
  double w; // fp0
  double v57; // fp1
  double v58; // fp0
  unsigned int numEdges; // r11
  _WORD *v60; // r7
  unsigned __int16 *v61; // r8
  float *v62; // r9
  int v63; // r29
  __int16 v64; // r11
  int v65; // r5
  float *p_x; // r11
  float *v67; // r10
  unsigned int numPolys; // r11
  unsigned int v69; // r5
  float *v70; // r9
  unsigned __int8 *v71; // r7
  float *p_b; // r11
  int v73; // r8
  unsigned int v74; // r10
  float *v75; // r8
  unsigned __int8 v76; // r29
  double v77; // fp4
  double v78; // fp3
  double v79; // fp1
  double v80; // fp0
  double v81; // fp2
  double v82; // fp1
  double v83; // fp0
  float *v84; // r10
  idMat3x4 v94; // [sp+50h] [-A0h] BYREF

  _R31 = tw;
  result->fraction = 1.0;
  result->endpos = *start;
  result->endAxis = *trmAxis;
  XMemSet(dest: &result->c, c: 0, count: 0x4Cu);
  _R31->traceResult = result;
  _R31->fraction = 1.0;
  _R31->contactsResult = nullptr;
  _R31->clipResult = nullptr;
  _R30 = &_R31->start.x;
  _R31->contents = contentMask;
  _R31->isConvex = trm->isConvex;
  _R31->traceType = TRACE_CONTENTS;
  _R31->quickExit = false;
  _R31->contactsResult = nullptr;
  y = start->y;
  z = start->z;
  v20 = modelOrigin->y;
  v21 = modelOrigin->z;
  v22 = (float)((float)(trmAxis->mat[2].y * trm->offset.z)
              + (float)((float)(trm->offset.x * trmAxis->mat[0].y) + (float)(trmAxis->mat[1].y * trm->offset.y)));
  v23 = (float)((float)(trmAxis->mat[2].z * trm->offset.z)
              + (float)((float)(trmAxis->mat[0].z * trm->offset.x) + (float)(trmAxis->mat[1].z * trm->offset.y)));
  v24 = (float)((float)(start->x
                      + (float)((float)(trm->offset.y * trmAxis->mat[1].x)
                              + (float)((float)(trmAxis->mat[0].x * trm->offset.x)
                                      + (float)(trmAxis->mat[2].x * trm->offset.z))))
              - modelOrigin->x);
  _R31->start.x = (float)(start->x
                        + (float)((float)(trm->offset.y * trmAxis->mat[1].x)
                                + (float)((float)(trmAxis->mat[0].x * trm->offset.x)
                                        + (float)(trmAxis->mat[2].x * trm->offset.z))))
                - modelOrigin->x;
  _R31->start.w = 0.0;
  _R31->start.y = (float)((float)v22 + (float)y) - (float)v20;
  _R31->start.z = (float)((float)v23 + (float)z) - (float)v21;
  _R31->end.x = v24;
  _R31->end.y = _R31->start.y;
  _R31->end.z = _R31->start.z;
  _R31->end.w = _R31->start.w;
  x = modelAxis->mat[0].x;
  v26 = trmAxis->mat[1].x;
  v27 = trmAxis->mat[2].x;
  v28 = trmAxis->mat[0].y;
  v29 = trmAxis->mat[1].y;
  v30 = trmAxis->mat[0].z;
  v31 = trmAxis->mat[1].z;
  v32 = (float)(start->z - modelOrigin->z);
  v33 = trmAxis->mat[0].x;
  v34 = (float)(start->y - modelOrigin->y);
  v35 = trmAxis->mat[2].y;
  v36 = trmAxis->mat[2].z;
  v37 = (float)(start->x - modelOrigin->x);
  v94.mat[0] = trmAxis->mat[0].x;
  v94.mat[1] = v26;
  v94.mat[7] = v34;
  v94.mat[2] = v27;
  v94.mat[4] = v28;
  v94.mat[5] = v29;
  v94.mat[6] = v35;
  v94.mat[8] = v30;
  v94.mat[9] = v31;
  v94.mat[10] = v36;
  v94.mat[3] = v37;
  v94.mat[11] = v32;
  if ( x != 1.0 || modelAxis->mat[1].y != 1.0 || (v38 = 0, modelAxis->mat[2].z != 1.0) )
    v38 = 1;
  if ( v38 != 0 )
  {
    v39 = *_R30;
    v40 = modelAxis->mat[1].x;
    v41 = modelAxis->mat[2].x;
    v42 = (float)((float)(modelAxis->mat[1].y * _R31->start.y) + (float)(modelAxis->mat[1].z * _R31->start.z));
    v43 = (float)((float)(modelAxis->mat[2].y * _R31->start.y) + (float)(modelAxis->mat[2].z * _R31->start.z));
    v44 = (float)((float)((float)x * _R31->start.x)
                + (float)((float)(modelAxis->mat[0].y * _R31->start.y) + (float)(modelAxis->mat[0].z * _R31->start.z)));
    _R31->start.x = (float)((float)x * _R31->start.x)
                  + (float)((float)(modelAxis->mat[0].y * _R31->start.y) + (float)(modelAxis->mat[0].z * _R31->start.z));
    _R31->start.y = (float)((float)v40 * (float)v39) + (float)v42;
    _R31->start.z = (float)((float)v41 * (float)v39) + (float)v43;
    _R31->end.x = v44;
    _R31->end.y = _R31->start.y;
    _R31->end.z = _R31->start.z;
    idMat3x4::LeftTransposeMultiply(this: &v94, m: modelAxis);
    v32 = v94.mat[11];
    v36 = v94.mat[10];
    v31 = v94.mat[9];
    v30 = v94.mat[8];
    v34 = v94.mat[7];
    v35 = v94.mat[6];
    v29 = v94.mat[5];
    v28 = v94.mat[4];
    v37 = v94.mat[3];
    v27 = v94.mat[2];
    v26 = v94.mat[1];
    v33 = v94.mat[0];
  }
  _R4 = &_R31->trmBoundsMin.x;
  _R3 = &_R31->trmBoundsMax.x;
  v47 = 0;
  _R31->trmBoundsMin.y = 1.0e30;
  _R31->trmBoundsMin.z = 1.0e30;
  _R31->trmBoundsMin.x = 1.0e30;
  _R31->trmBoundsMin.w = 0.0;
  _R31->trmBoundsMax.w = 0.0;
  _R31->trmBoundsMax.x = -1.0e30;
  _R31->trmBoundsMax.y = -1.0e30;
  _R31->trmBoundsMax.z = -1.0e30;
  numVerts = trm->numVerts;
  _R31->numVerts = numVerts;
  if ( numVerts != 0 )
  {
    vertsZ = trm->vertsZ;
    p_z = &_R31->vertexPosition[0].z;
    do
    {
      v51 = (float)((float)(*(vertsZ - 32) * (float)v26)
                  + (float)((float)(*(vertsZ - 64) * (float)v33) + (float)(*vertsZ * (float)v27)));
      v52 = (float)((float)((float)v28 * *(vertsZ - 64))
                  + (float)((float)(*vertsZ * (float)v35) + (float)(*(vertsZ - 32) * (float)v29)));
      *p_z = (float)((float)((float)v30 * *(vertsZ - 64))
                   + (float)((float)(*vertsZ * (float)v36) + (float)(*(vertsZ - 32) * (float)v31)))
           + (float)v32;
      v53 = (float)((float)v51 + (float)v37);
      *(p_z - 2) = v53;
      *(p_z - 1) = (float)v52 + (float)v34;
      if ( v53 < *_R4 )
        *_R4 = v53;
      if ( *(p_z - 1) < (double)_R31->trmBoundsMin.y )
        _R31->trmBoundsMin.y = *(p_z - 1);
      if ( *p_z < (double)_R31->trmBoundsMin.z )
        _R31->trmBoundsMin.z = *p_z;
      if ( *(p_z - 2) > (double)*_R3 )
        *_R3 = *(p_z - 2);
      if ( *(p_z - 1) > (double)_R31->trmBoundsMax.y )
        _R31->trmBoundsMax.y = *(p_z - 1);
      if ( *p_z > (double)_R31->trmBoundsMax.z )
        _R31->trmBoundsMax.z = *p_z;
      ++v47;
      p_z += 4;
      ++vertsZ;
    }
    while ( v47 < _R31->numVerts );
  }
  v54 = 0;
  *_R4 = *_R4 - *_R30;
  v55 = _R31->trmBoundsMin.z;
  w = _R31->trmBoundsMin.w;
  _R31->trmBoundsMin.y = _R31->trmBoundsMin.y - _R31->start.y;
  _R31->trmBoundsMin.z = (float)v55 - _R31->start.z;
  _R31->trmBoundsMin.w = (float)w - _R31->start.w;
  v57 = _R31->trmBoundsMax.z;
  *_R3 = *_R3 - *_R30;
  v58 = _R31->trmBoundsMax.w;
  _R31->trmBoundsMax.y = _R31->trmBoundsMax.y - _R31->start.y;
  _R31->trmBoundsMax.z = (float)v57 - _R31->start.z;
  _R31->trmBoundsMax.w = (float)v58 - _R31->start.w;
  numEdges = trm->numEdges;
  _R31->numEdges = numEdges;
  if ( numEdges != 0 )
  {
    v60 = (_WORD *)&_R31->verts[31].pad + 1;
    v61 = (unsigned __int16 *)&trm->numPolyEdges[15] + 1;
    v62 = &_R31->vertexPluecker[31].p[5];
    do
    {
      v63 = v61[1];
      ++v54;
      v61 += 2;
      v64 = *v61;
      v65 = *v61;
      v60[7] = v63;
      v60 += 8;
      *v60 = v64;
      p_x = &_R31->vertexPosition[v63].x;
      v67 = &_R31->vertexPosition[v65].x;
      v62[1] = (float)(v67[1] * *p_x) - (float)(p_x[1] * *v67);
      v62[2] = (float)(*p_x * v67[2]) - (float)(p_x[2] * *v67);
      v62[3] = *p_x - *v67;
      v62[4] = (float)(p_x[1] * v67[2]) - (float)(v67[1] * p_x[2]);
      v62[5] = p_x[2] - v67[2];
      v62 += 6;
      *v62 = v67[1] - p_x[1];
    }
    while ( v54 < _R31->numEdges );
  }
  numPolys = trm->numPolys;
  v69 = 0;
  _R31->numPolys = numPolys;
  if ( numPolys != 0 )
  {
    v70 = &trm->polyPlaneY[15];
    v71 = trm->polyEdges[0];
    p_b = &_R31->polys[0].plane.b;
    do
    {
      v73 = *((_DWORD *)v70 + 97);
      v74 = 0;
      *((_DWORD *)p_b + 6) = v73;
      if ( v73 != 0 )
      {
        v75 = p_b - 257;
        do
        {
          v76 = v71[v74++];
          *((_BYTE *)v75 + 1056) = v76;
          v75 = (float *)((char *)p_b + v74 - 1028);
        }
        while ( v74 < *((_DWORD *)p_b + 6) );
      }
      v77 = *(v70 - 31);
      ++v69;
      v78 = *(v70 - 15);
      v71 += 16;
      v79 = (float)((float)(*++v70 * (float)v36) + (float)((float)v78 * (float)v31));
      v80 = (float)((float)((float)v77 * (float)v33) + (float)(*v70 * (float)v27));
      v81 = (float)((float)((float)v28 * (float)v77)
                  + (float)((float)(*v70 * (float)v35) + (float)((float)v78 * (float)v29)));
      *p_b = (float)((float)v28 * (float)v77) + (float)((float)(*v70 * (float)v35) + (float)((float)v78 * (float)v29));
      v82 = (float)((float)((float)v30 * (float)v77) + (float)v79);
      p_b[1] = v82;
      v83 = (float)((float)((float)v78 * (float)v26) + (float)v80);
      *(p_b - 1) = v83;
      v84 = &_R31->vertexPosition[_R31->edges[(_BYTE)p_b[7] & 0x7F].vertexNum[0]].x;
      p_b[2] = -(float)((float)(v84[1] * (float)v81) + (float)((float)(v84[2] * (float)v82) + (float)((float)v83 * *v84)));
      p_b += 16;
    }
    while ( v69 < _R31->numPolys );
  }
  __asm { lvx128    v63, r0, r30 }
  __asm { lvx128    v61, r0, r4 }
  _R10 = -48;
  __asm
  {
    lvx128    v60, r0, r3
    vaddfp128 v59, v95, v61
    vaddfp128 v58, v95, v60
  }
  _R9 = vmxi_float_abs_mask_3;
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
// ?StartContentsPoint@idPolygonModelCollisionDetection@@SAXPAVidTraceWork@@PAUtrace_t@@ABVidVec3@@H2ABVidMat3@@@Z
// EA  : 0x825EB5D0
// RVA : 0x005EB5D0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_contents.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::StartContentsPoint(
        idTraceWork *tw,
        trace_t *result,
        const idVec3 *start,
        int contentMask,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis)
{
  double y; // fp9
  double v14; // fp8
  double v15; // fp7
  double x; // fp6
  double v17; // fp5
  double z; // fp4
  double v19; // fp3
  double v20; // fp2
  double v21; // fp1
  double v22; // fp0
  double v23; // fp13
  double v24; // fp12
  double v25; // fp11

  result->endpos = *start;
  _R31 = tw;
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
  _R31->fraction = 1.0;
  _R31->traceResult = result;
  _R31->clipResult = nullptr;
  _R31->contents = contentMask;
  _R31->isConvex = true;
  _R6 = -48;
  _R31->traceType = TRACE_CONTENTS_POINT;
  _R31->quickExit = false;
  _R31->contactsResult = nullptr;
  y = modelAxis->mat[0].y;
  v14 = modelAxis->mat[1].y;
  v15 = modelAxis->mat[2].y;
  x = start->x;
  v17 = modelOrigin->x;
  z = modelAxis->mat[0].z;
  v19 = modelAxis->mat[1].z;
  v20 = modelAxis->mat[2].z;
  v21 = modelAxis->mat[1].x;
  v22 = modelAxis->mat[2].x;
  v23 = modelAxis->mat[0].x;
  v24 = (float)(start->y - modelOrigin->y);
  v25 = (float)(start->z - modelOrigin->z);
  _R31->start.w = 0.0;
  _R31->start.x = (float)((float)v23 * (float)((float)x - (float)v17))
                + (float)((float)((float)z * (float)v25) + (float)((float)y * (float)v24));
  _R31->start.y = (float)((float)v21 * (float)((float)x - (float)v17))
                + (float)((float)((float)v19 * (float)v25) + (float)((float)v14 * (float)v24));
  _R31->start.z = (float)((float)v22 * (float)((float)x - (float)v17))
                + (float)((float)((float)v20 * (float)v25) + (float)((float)v15 * (float)v24));
  _R31->end.x = (float)((float)v23 * (float)((float)x - (float)v17))
              + (float)((float)((float)z * (float)v25) + (float)((float)y * (float)v24));
  _R31->end.y = _R31->start.y;
  _R31->end.z = _R31->start.z;
  _R31->end.w = _R31->start.w;
  _R11 = &_R31->traceBoundsMin;
  _R31->trmExtents.w = 0.0;
  _R5 = vmxi_word_max_ushort_3;
  _R31->trmExtents.z = 0.0;
  _R10 = &_R31->traceBoundsMax;
  _R31->trmExtents.y = 0.0;
  __asm { vspltisw128 v62, 0 }
  _R31->trmExtents.x = 0.0;
  _R31->numVerts = 1;
  _R4 = 6176;
  __asm { lvx128    v63, r5, r6 }
  _R31->vertexPosition[0].x = _R31->start.x;
  _R31->vertexPosition[0].y = _R31->start.y;
  _R31->vertexPosition[0].z = _R31->start.z;
  _R31->traceBoundsMin = _R31->start;
  _R31->traceBoundsMax = _R31->start;
  __asm
  {
    lvx128    v59, r0, r11
    lvx128    v0, r0, r5
    lvx128    v61, r0, r10
    vsubfp128 v60, v93, v63
    vaddfp128 v58, v91, v63
    vcfpsxws128 v13, v60, 0
    vcfpsxws128 v12, v58, 0
    vaddsws   v11, v13, v0
    vpkswss128 v57, v11, v62
    vsldoi128 v55, v94, v57, 0xA
    vsubsws   v10, v12, v0
    vpkswss128 v56, v10, v62
    vor128    v54, v88, v55
    stvx128   v54, r31, r4
  }
}


// ========================================================================
// ?FinishContents@idPolygonModelCollisionDetection@@SAXPAVidTraceWork@@ABVidVec3@@ABVidMat3@@HHHHH@Z
// EA  : 0x825EB7F8
// RVA : 0x005EB7F8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_contents.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::FinishContents(
        idTraceWork *tw,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis,
        int modelEntityNum,
        int modelPhysicsId,
        int modelId,
        int selfId,
        int modelContentsOverride)
{
  char v8; // r11
  trace_t *traceResult; // r11
  double y; // fp6
  double x; // fp4
  double v12; // fp1
  double z; // fp0
  double v14; // fp12
  double v15; // fp11
  double v16; // fp1
  double v17; // fp2
  double v18; // fp0
  double v19; // fp12
  double v20; // fp5
  double v21; // fp4
  trace_t *v22; // r11
  trace_t *v23; // r11

  if ( tw->traceResult->fraction < 1.0 )
  {
    if ( modelAxis->mat[0].x != 1.0 || modelAxis->mat[1].y != 1.0 || (v8 = 0, modelAxis->mat[2].z != 1.0) )
      v8 = 1;
    if ( v8 != 0 )
    {
      traceResult = tw->traceResult;
      y = traceResult->c.normal.y;
      x = traceResult->c.normal.x;
      v12 = modelAxis->mat[1].y;
      z = modelAxis->mat[0].z;
      v14 = (float)((float)(traceResult->c.normal.x * modelAxis->mat[0].y)
                  + (float)(traceResult->c.normal.z * modelAxis->mat[2].y));
      v15 = (float)((float)(traceResult->c.normal.y * modelAxis->mat[1].z)
                  + (float)(modelAxis->mat[2].z * traceResult->c.normal.z));
      traceResult->c.normal.x = (float)(modelAxis->mat[1].x * traceResult->c.normal.y)
                              + (float)((float)(traceResult->c.normal.x * modelAxis->mat[0].x)
                                      + (float)(modelAxis->mat[2].x * traceResult->c.normal.z));
      traceResult->c.normal.y = (float)((float)v12 * (float)y) + (float)v14;
      traceResult->c.normal.z = (float)((float)z * (float)x) + (float)v15;
      v16 = traceResult->c.point.x;
      v17 = traceResult->c.point.y;
      v18 = modelAxis->mat[1].x;
      v19 = modelAxis->mat[0].z;
      v20 = (float)((float)(modelAxis->mat[0].x * traceResult->c.point.x)
                  + (float)(modelAxis->mat[2].x * traceResult->c.point.z));
      v21 = (float)((float)(traceResult->c.point.y * modelAxis->mat[1].z)
                  + (float)(modelAxis->mat[2].z * traceResult->c.point.z));
      traceResult->c.point.y = (float)(modelAxis->mat[1].y * traceResult->c.point.y)
                             + (float)((float)(traceResult->c.point.x * modelAxis->mat[0].y)
                                     + (float)(traceResult->c.point.z * modelAxis->mat[2].y));
      traceResult->c.point.x = (float)((float)v18 * (float)v17) + (float)v20;
      traceResult->c.point.z = (float)((float)v19 * (float)v16) + (float)v21;
    }
    if ( ((LODWORD(modelOrigin->x) | LODWORD(modelOrigin->z) | LODWORD(modelOrigin->y)) & 0x7FFFFFFF) != 0 )
    {
      v22 = tw->traceResult;
      v22->c.point.x = modelOrigin->x + v22->c.point.x;
      v22->c.point.y = v22->c.point.y + modelOrigin->y;
      v22->c.point.z = modelOrigin->z + v22->c.point.z;
      v22->c.dist = (float)((float)(modelOrigin->x * v22->c.normal.x)
                          + (float)((float)(v22->c.normal.z * modelOrigin->z) + (float)(v22->c.normal.y * modelOrigin->y)))
                  + v22->c.dist;
    }
    tw->traceResult->c.entityNum = modelEntityNum;
    tw->traceResult->c.physicsId = modelPhysicsId;
    tw->traceResult->c.bodyId = modelId;
    tw->traceResult->c.selfId = selfId;
    if ( modelContentsOverride != 0 )
    {
      v23 = tw->traceResult;
      if ( v23->c.contentFlags != 0 )
        v23->c.contentFlags = modelContentsOverride;
    }
  }
}

