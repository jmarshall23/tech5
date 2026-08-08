
// ========================================================================
// ?SetupSubModelPtrsFromData@idPolygonModelCollisionDetection@@SAXAAUcm_subModelPtrs_t@@PBUcm_subModelData_t@@@Z
// EA  : 0x825F0868
// RVA : 0x005F0868
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_trace.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(
        cm_subModelPtrs_t *subModelPtrs,
        const cm_subModelData_t *subModelData)
{
  subModelPtrs->isConvex = subModelData->isConvex;
  subModelPtrs->nodes = (cm_node_t *)((char *)subModelData + subModelData->nodeOffset);
  subModelPtrs->primitiveIndices = (unsigned __int16 *)((char *)subModelData + subModelData->primitiveIndexOffset);
  subModelPtrs->materials = (cm_material_t *)((char *)subModelData + subModelData->materialOffset);
  subModelPtrs->polygons = (cm_polygon_t *)((char *)subModelData + subModelData->polygonOffset);
  subModelPtrs->polygonEdges = (unsigned __int16 *)((char *)subModelData + subModelData->polygonEdgeOffset);
  subModelPtrs->edges = (cm_edge_t *)((char *)subModelData + subModelData->edgeOffset);
  subModelPtrs->vertices = (cm_vertex_t *)((char *)subModelData + subModelData->vertexOffset);
  subModelPtrs->polytopes = (cm_polytope_t *)((char *)subModelData + subModelData->polytopeOffset);
  subModelPtrs->polytopePlanes = (idPlane *)((char *)subModelData + subModelData->polytopePlaneOffset);
}


// ========================================================================
// ?SetupSubModelForBounds@idPolygonModelCollisionDetection@@SAPAUcm_subModelData_t@@PAEHABVidBounds@@@Z
// EA  : 0x825F08E0
// RVA : 0x005F08E0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_trace.cpp
// ========================================================================

cm_subModelData_t *__fastcall idPolygonModelCollisionDetection::SetupSubModelForBounds(
        cm_subModelData_t *data,
        int size,
        const idBounds *bounds)
{
  idVec3 *v3; // r8
  int v4; // r11
  double v5; // fp12
  int v6; // r11
  double v7; // fp12
  int v8; // r11
  double v9; // fp12
  int v10; // r11
  double v11; // fp12
  int v12; // r11
  double v13; // fp12
  __int16 v14; // r24
  float *v15; // r9
  _WORD *v16; // r7
  int polygonEdgeOffset; // r31
  char *v18; // r6
  int polygonOffset; // r4
  int edgeOffset; // r28
  int vertexOffset; // r11
  int polytopeOffset; // r26
  int polytopePlaneOffset; // r25
  float *v24; // r11
  char *v25; // r4
  char *v26; // r28
  char *v27; // r26
  _WORD *v28; // r9
  float *v29; // r31
  double z; // fp10
  double v31; // fp7
  double v32; // fp4
  double v33; // fp1
  __int16 v34; // r7
  int v35; // r6
  double v36; // fp10
  double v37; // fp7
  double v38; // fp4
  double v39; // fp1
  unsigned __int16 v40; // r30
  char *v41; // r11
  int v42; // r6
  __int16 v43; // r29
  _WORD *v44; // r11
  int v45; // ctr
  char *v46; // r7
  _WORD *v47; // r11
  _WORD *v48; // r7
  int i; // ctr
  _WORD *v50; // r11
  _WORD *v51; // r7
  int j; // ctr
  _WORD *v53; // r7
  _WORD *v54; // r6
  int k; // ctr
  _WORD *v56; // r7
  _WORD *v57; // r6
  int m; // ctr
  _WORD *v59; // r11
  _WORD *v60; // r7
  int n; // ctr
  int v62; // ctr
  _WORD *v63; // r11
  char *v64; // r9
  double v65; // fp10
  double v66; // fp6
  double v67; // fp4
  double v68; // fp2
  double x; // fp1
  _WORD v70[85]; // [sp+6h] [-AAh] BYREF

  data->numPolygonEdges = 28;
  data->nodeOffset = 112;
  data->materialOffset = 144;
  data->numMaterials = 1;
  data->numPolytopes = 1;
  data->primitiveIndexOffset = 128;
  data->polygonOffset = 160;
  data->polygonEdgeOffset = 256;
  data->vertexOffset = 368;
  data->polytopeOffset = 496;
  data->polytopePlaneOffset = 512;
  data->isConvex = 1;
  data->numNodes = 1;
  data->numPrimitiveIndices = 7;
  data->numPolygons = 6;
  data->numEdges = 12;
  data->numVertices = 8;
  data->numPolytopePlanes = 6;
  data->edgeOffset = 312;
  v3 = &bounds->b[1];
  *(_QWORD *)&v70[1] = 0x26000000000LL;
  *(_DWORD *)&v70[5] = 0;
  data->header.bounds = *bounds;
  data->header.loadedSize = 608;
  data->header.totalSize = 608;
  v4 = (int)(float)(bounds->b[0].x - (float)1.0);
  if ( v4 >= -32768 )
  {
    if ( v4 > 0x7FFF )
      LOWORD(v4) = 0x7FFF;
  }
  else
  {
    LOWORD(v4) = 0x8000;
  }
  v5 = (float)(v3->x + (float)1.0);
  v70[1] = v4;
  v6 = (int)v5;
  if ( (int)v5 >= -32768 )
  {
    if ( v6 > 0x7FFF )
      LOWORD(v6) = 0x7FFF;
  }
  else
  {
    LOWORD(v6) = 0x8000;
  }
  v7 = (float)(bounds->b[0].y - (float)1.0);
  v70[4] = v6;
  v8 = (int)v7;
  if ( (int)v7 >= -32768 )
  {
    if ( v8 > 0x7FFF )
      LOWORD(v8) = 0x7FFF;
  }
  else
  {
    LOWORD(v8) = 0x8000;
  }
  v9 = (float)(bounds->b[1].y + (float)1.0);
  v70[2] = v8;
  v10 = (int)v9;
  if ( (int)v9 >= -32768 )
  {
    if ( v10 > 0x7FFF )
      LOWORD(v10) = 0x7FFF;
  }
  else
  {
    LOWORD(v10) = 0x8000;
  }
  v11 = (float)(bounds->b[0].z - (float)1.0);
  v70[5] = v10;
  v12 = (int)v11;
  if ( (int)v11 >= -32768 )
  {
    if ( v12 > 0x7FFF )
      LOWORD(v12) = 0x7FFF;
  }
  else
  {
    LOWORD(v12) = 0x8000;
  }
  v13 = (float)(bounds->b[1].z + (float)1.0);
  v70[3] = v12;
  if ( (int)v13 >= -32768 )
  {
    v14 = 0x7FFF;
    if ( (int)v13 <= 0x7FFF )
      v14 = (int)v13;
  }
  else
  {
    v14 = 0x8000;
  }
  v15 = (float *)((char *)&data->header.totalSize + data->nodeOffset);
  v16 = (_WORD *)((char *)data + data->primitiveIndexOffset);
  polygonEdgeOffset = data->polygonEdgeOffset;
  v18 = (char *)data + data->materialOffset;
  polygonOffset = data->polygonOffset;
  edgeOffset = data->edgeOffset;
  vertexOffset = data->vertexOffset;
  polytopeOffset = data->polytopeOffset;
  polytopePlaneOffset = data->polytopePlaneOffset;
  v15[1] = 0.0;
  *v15 = NAN;
  *((_WORD *)v15 + 4) = 0;
  v24 = (float *)((char *)&data->header.totalSize + vertexOffset);
  *((_WORD *)v15 + 5) = 0;
  v25 = (char *)data + polygonOffset;
  *((_WORD *)v15 + 6) = 0;
  v26 = (char *)data + edgeOffset;
  *((_BYTE *)v15 + 14) = 6;
  v27 = (char *)data + polytopeOffset;
  *((_BYTE *)v15 + 15) = 1;
  v28 = (_WORD *)((char *)data + polygonEdgeOffset);
  *v16 = 0;
  v29 = (float *)((char *)&data->header.totalSize + polytopePlaneOffset);
  v16[1] = 1;
  v16[2] = 2;
  v16[3] = 3;
  v16[4] = 4;
  v16[5] = 5;
  v16[6] = 0;
  v18[14] = -1;
  *((_DWORD *)v18 + 2) = 0;
  *(_DWORD *)v18 = -1;
  *((_DWORD *)v18 + 1) = -1;
  v18[13] = -1;
  v18[12] = -1;
  v70[6] = v14;
  *v24 = bounds->b[0].x;
  v24[1] = bounds->b[0].y;
  z = bounds->b[0].z;
  *((_WORD *)v24 + 6) = 0;
  v24[2] = z;
  *((_WORD *)v24 + 7) = 0;
  v24[4] = v3->x;
  v24[5] = bounds->b[0].y;
  v31 = bounds->b[0].z;
  *((_WORD *)v24 + 14) = 0;
  v24[6] = v31;
  *((_WORD *)v24 + 15) = 0;
  v24[8] = v3->x;
  v24[9] = bounds->b[1].y;
  v32 = bounds->b[0].z;
  *((_WORD *)v24 + 22) = 0;
  v24[10] = v32;
  *((_WORD *)v24 + 23) = 0;
  v24[12] = bounds->b[0].x;
  v24[13] = bounds->b[1].y;
  v33 = bounds->b[0].z;
  *((_WORD *)v24 + 30) = 0;
  v24[14] = v33;
  *((_WORD *)v24 + 31) = 0;
  v24[16] = bounds->b[0].x;
  v34 = 0;
  v24[17] = bounds->b[0].y;
  v35 = 0;
  v36 = bounds->b[1].z;
  *((_WORD *)v24 + 38) = 0;
  v24[18] = v36;
  *((_WORD *)v24 + 39) = 0;
  v24[20] = v3->x;
  v24[21] = bounds->b[0].y;
  v37 = bounds->b[1].z;
  *((_WORD *)v24 + 46) = 0;
  v24[22] = v37;
  *((_WORD *)v24 + 47) = 0;
  v24[24] = v3->x;
  v24[25] = bounds->b[1].y;
  v38 = bounds->b[1].z;
  *((_WORD *)v24 + 54) = 0;
  v24[26] = v38;
  *((_WORD *)v24 + 55) = 0;
  v24[28] = bounds->b[0].x;
  v24[29] = bounds->b[1].y;
  v39 = bounds->b[1].z;
  *((_WORD *)v24 + 62) = 0;
  v24[30] = v39;
  *((_WORD *)v24 + 63) = 0;
  do
  {
    v40 = v35 + 1;
    v41 = &v26[4 * v35];
    v43 = (v35 + 1) & 3;
    *(_WORD *)v41 = v34;
    *(_WORD *)&v26[4 * v35 + 32] = v34;
    v34 = v35 + 1;
    v42 = v35 + 4;
    *((_WORD *)v41 + 1) = v43;
    *((_WORD *)v41 + 17) = v42;
    *(_WORD *)&v26[4 * v42] = v42;
    v35 = v40;
    *((_WORD *)v41 + 9) = v43 + 4;
  }
  while ( v40 < 4u );
  v44 = v70;
  v45 = 6;
  v46 = v25 - 2;
  do
  {
    ++v44;
    v46 += 2;
    *(_WORD *)v46 = *v44;
    --v45;
  }
  while ( v45 != 0 );
  v47 = v70;
  v25[12] = 0;
  v25[13] = 4;
  *((_WORD *)v25 + 7) = 0;
  v48 = v25 + 14;
  for ( i = 6; i != 0; --i )
    *++v48 = *++v47;
  v50 = v70;
  v25[28] = 0;
  v25[29] = 4;
  *((_WORD *)v25 + 15) = 4;
  v51 = v25 + 30;
  for ( j = 6; j != 0; --j )
    *++v51 = *++v50;
  v53 = v70;
  v25[44] = 0;
  v25[45] = 4;
  *((_WORD *)v25 + 23) = 8;
  v54 = v25 + 46;
  for ( k = 6; k != 0; --k )
    *++v54 = *++v53;
  v56 = v70;
  v25[60] = 0;
  v25[61] = 4;
  *((_WORD *)v25 + 31) = 12;
  v57 = v25 + 62;
  for ( m = 6; m != 0; --m )
    *++v57 = *++v56;
  v25[76] = 0;
  v59 = v70;
  v25[77] = 4;
  *((_WORD *)v25 + 39) = 16;
  v60 = v25 + 78;
  for ( n = 6; n != 0; --n )
    *++v60 = *++v59;
  v25[93] = 4;
  v25[92] = 0;
  v62 = 6;
  *((_WORD *)v25 + 47) = 20;
  v28[23] = -32757;
  v28[24] = -32757;
  v28[25] = -32757;
  v28[1] = -32766;
  *v28 = -32765;
  v28[2] = -32767;
  v28[3] = 0x8000;
  v28[4] = 4;
  v28[5] = 5;
  v28[9] = 9;
  v28[10] = -32764;
  v28[11] = -32760;
  v28[6] = 6;
  v28[7] = 7;
  v28[8] = 0;
  v63 = v70;
  v28[12] = 1;
  v28[13] = 10;
  v28[14] = -32763;
  v28[15] = -32759;
  v28[16] = 2;
  v28[17] = 11;
  v28[18] = -32762;
  v28[19] = -32758;
  v28[20] = 3;
  v28[21] = 8;
  v28[22] = -32761;
  v28[26] = -32757;
  v28[27] = -32757;
  v64 = v27 - 2;
  do
  {
    ++v63;
    v64 += 2;
    *(_WORD *)v64 = *v63;
    --v62;
  }
  while ( v62 != 0 );
  v27[12] = 0;
  v27[13] = 6;
  *((_WORD *)v27 + 7) = 0;
  v65 = -bounds->b[0].z;
  v29[2] = -1.0;
  *v29 = 0.0;
  v29[1] = 0.0;
  v29[3] = v65;
  v29[7] = -bounds->b[1].z;
  v29[6] = 1.0;
  v29[5] = 0.0;
  v29[4] = 0.0;
  v66 = -bounds->b[0].y;
  v29[10] = 0.0;
  v29[8] = 0.0;
  v29[9] = -1.0;
  v29[11] = v66;
  v67 = -bounds->b[1].y;
  v29[12] = 1.0;
  v29[15] = v67;
  v29[13] = 0.0;
  v29[14] = 0.0;
  v68 = -v3->x;
  v29[17] = 1.0;
  v29[16] = 0.0;
  v29[19] = v68;
  v29[18] = 0.0;
  x = bounds->b[0].x;
  v29[20] = -1.0;
  v29[21] = 0.0;
  v29[22] = 0.0;
  v29[23] = -x;
  return data;
}


// ========================================================================
// ?TestStuckInSubModelBounds@idPolygonModelCollisionDetection@@CA_NPAVidTraceWork@@ABVidBounds@@@Z
// EA  : 0x825F0FB8
// RVA : 0x005F0FB8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_trace.cpp
// ========================================================================

BOOL __fastcall idPolygonModelCollisionDetection::TestStuckInSubModelBounds(idTraceWork *tw, idBounds *subModelBounds)
{
  traceType_t traceType; // r11
  double v6; // fp3
  idVec4 *p_start; // r29
  double v8; // fp7
  double v9; // fp5
  double v10; // fp1
  double v11; // fp0
  unsigned int numVerts; // r8
  unsigned int v13; // r9
  double x; // fp11
  float *v15; // r10
  double v16; // fp0
  double v17; // fp12
  double v18; // fp13
  char v19; // r11
  double v20; // fp0
  double v21; // fp12
  double v22; // fp13
  char v23; // r11
  double v24; // fp0
  double v25; // fp12
  double v26; // fp13
  char v27; // r11
  double v28; // fp0
  double v29; // fp12
  double v30; // fp13
  char v31; // r11
  float *p_z; // r11
  double v33; // fp0
  double v34; // fp12
  double v35; // fp13
  char v36; // r10
  trace_t *traceResult; // r11
  trace_t *v38; // r11
  idBounds v39; // [sp+50h] [-40h] BYREF

  traceType = tw->traceType;
  if ( traceType <= TRACE_INVALID )
    return false;
  if ( traceType > TRACE_CONTACTS_OMNI_DIR )
    return traceType == TRACE_CLIP;
  v6 = (float)(tw->start.x + tw->trmBoundsMin.x);
  p_start = &tw->start;
  v8 = (float)(tw->trmBoundsMax.y + tw->start.y);
  v9 = (float)(tw->trmBoundsMax.z + tw->start.z);
  v10 = (float)(tw->trmBoundsMin.y + tw->start.y);
  v11 = (float)(tw->trmBoundsMin.z + tw->start.z);
  v39.b[1].x = tw->start.x + tw->trmBoundsMax.x;
  v39.b[0].x = v6;
  v39.b[1].y = v8;
  v39.b[1].z = v9;
  v39.b[0].y = v10;
  v39.b[0].z = v11;
  if ( (unsigned __int8)idBounds::IntersectsBounds(this: subModelBounds, a: &v39) == 0 )
    return false;
  numVerts = tw->numVerts;
  v13 = 0;
  if ( (int)numVerts < 4 )
  {
LABEL_41:
    if ( v13 < numVerts )
    {
      p_z = &tw->vertexPosition[v13].z;
      do
      {
        v33 = *(p_z - 2);
        if ( v33 >= subModelBounds->b[0].x )
        {
          v34 = *(p_z - 1);
          if ( v34 >= subModelBounds->b[0].y )
          {
            v35 = *p_z;
            if ( v35 >= subModelBounds->b[0].z && v33 <= subModelBounds->b[1].x && v34 <= subModelBounds->b[1].y )
            {
              v36 = 1;
              if ( v35 <= subModelBounds->b[1].z )
                goto LABEL_50;
            }
          }
        }
        v36 = 0;
LABEL_50:
        if ( v36 != 0 )
          break;
        ++v13;
        p_z += 4;
      }
      while ( v13 < numVerts );
      goto LABEL_56;
    }
    return false;
  }
  x = subModelBounds->b[0].x;
  v15 = &tw->vertexPosition[0].z;
  while ( 1 )
  {
    v16 = *(v15 - 2);
    if ( v16 < x
      || (v17 = *(v15 - 1)) < subModelBounds->b[0].y
      || (v18 = *v15) < subModelBounds->b[0].z
      || v16 > subModelBounds->b[1].x
      || v17 > subModelBounds->b[1].y
      || (v19 = 1, v18 > subModelBounds->b[1].z) )
    {
      v19 = 0;
    }
    if ( v19 != 0 )
      break;
    v20 = v15[2];
    if ( v20 < x
      || (v21 = v15[3]) < subModelBounds->b[0].y
      || (v22 = v15[4]) < subModelBounds->b[0].z
      || v20 > subModelBounds->b[1].x
      || v21 > subModelBounds->b[1].y
      || (v23 = 1, v22 > subModelBounds->b[1].z) )
    {
      v23 = 0;
    }
    if ( v23 != 0 )
    {
      ++v13;
      break;
    }
    v24 = v15[6];
    if ( v24 < x
      || (v25 = v15[7]) < subModelBounds->b[0].y
      || (v26 = v15[8]) < subModelBounds->b[0].z
      || v24 > subModelBounds->b[1].x
      || v25 > subModelBounds->b[1].y
      || (v27 = 1, v26 > subModelBounds->b[1].z) )
    {
      v27 = 0;
    }
    if ( v27 != 0 )
    {
      v13 += 2;
      break;
    }
    v28 = v15[10];
    if ( v28 < x
      || (v29 = v15[11]) < subModelBounds->b[0].y
      || (v30 = v15[12]) < subModelBounds->b[0].z
      || v28 > subModelBounds->b[1].x
      || v29 > subModelBounds->b[1].y
      || (v31 = 1, v30 > subModelBounds->b[1].z) )
    {
      v31 = 0;
    }
    if ( v31 != 0 )
    {
      v13 += 3;
      break;
    }
    v13 += 4;
    v15 += 16;
    if ( v13 >= numVerts - 3 )
      goto LABEL_41;
  }
LABEL_56:
  if ( v13 >= numVerts )
    return false;
  if ( tw->traceResult != nullptr )
  {
    tw->traceResult->fraction = 0.0;
    traceResult = tw->traceResult;
    traceResult->c.normal.x = 0.0;
    traceResult->c.normal.y = 0.0;
    traceResult->c.normal.z = 1.0;
    tw->traceResult->c.dist = tw->start.w;
    tw->traceResult->c.separation = 0.0;
    tw->traceResult->c.contentFlags = -1;
    tw->traceResult->c.surfaceFlags = 0;
    tw->traceResult->c.surfaceType = 0;
    tw->traceResult->c.surfaceColor[2] = -1;
    tw->traceResult->c.surfaceColor[1] = -1;
    tw->traceResult->c.surfaceColor[0] = -1;
    tw->traceResult->c.type = CONTACT_MODELVERTEX;
    tw->traceResult->c.modelFeature = (tw->subModelNum << 16) & 0x1FFF0000;
    tw->traceResult->c.trmFeature = 0;
    v38 = tw->traceResult;
    v38->c.point.x = p_start->x;
    v38->c.point.y = tw->start.y;
    v38->c.point.z = tw->start.z;
    tw->traceResult->c.flags = 1;
  }
  return true;
}


// ========================================================================
// ?LocalExtentsFromUnTransformedBounds@idPolygonModelCollisionDetection@@SA?AVidVec3@@ABVidBounds@@ABV2@1ABVidMat3@@@Z
// EA  : 0x825F13B8
// RVA : 0x005F13B8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_trace.cpp
// ========================================================================

idVec3 *__fastcall idPolygonModelCollisionDetection::LocalExtentsFromUnTransformedBounds(
        idVec3 *result,
        const idBounds *globalBounds,
        const idVec3 *globalStart,
        const idVec3 *globalEnd,
        const idMat3 *modelAxis)
{
  double v14; // fp1
  double v15; // fp13
  double v16; // fp4
  double v17; // fp30
  double v18; // fp3
  double v19; // fp8
  double v20; // fp10
  double v21; // fp4
  double v22; // fp2
  double v23; // fp1

  _FP9 = (float)(globalEnd->y - globalStart->y);
  _FP8 = (float)(globalEnd->z - globalStart->z);
  _FP4 = (float)(globalEnd->x - globalStart->x);
  __asm { fsel      f12, f9, f0, f9 }
  __asm { fsel      f31, f8, f0, f8 }
  __asm { fsel      f8, f8, f8, f0 }
  __asm { fsel      f9, f9, f9, f0 }
  __asm { fsel      f29, f4, f0, f4 }
  __asm { fsel      f4, f4, f4, f0 }
  v14 = (float)((float)((float)((float)(globalBounds->b[0].z - globalStart->z) - (float)_FP31)
                      + (float)((float)(globalBounds->b[1].z - globalStart->z) - (float)_FP8))
              * (float)0.5);
  v15 = (float)((float)((float)((float)(globalBounds->b[0].x - globalStart->x) - (float)_FP29)
                      + (float)((float)(globalBounds->b[1].x - globalStart->x) - (float)_FP4))
              * (float)0.5);
  v16 = (float)((float)((float)(globalBounds->b[1].x - globalStart->x) - (float)_FP4)
              - (float)((float)((float)((float)(globalBounds->b[0].x - globalStart->x) - (float)_FP29)
                              + (float)((float)(globalBounds->b[1].x - globalStart->x) - (float)_FP4))
                      * (float)0.5));
  v17 = __fabs((float)((float)((float)((float)(globalBounds->b[1].z - globalStart->z) - (float)_FP8)
                             - (float)((float)((float)((float)(globalBounds->b[0].z - globalStart->z) - (float)_FP31)
                                             + (float)((float)(globalBounds->b[1].z - globalStart->z) - (float)_FP8))
                                     * (float)0.5))
                     * modelAxis->mat[1].z));
  v18 = (float)((float)((float)__fabs((float)((float)((float)((float)(globalBounds->b[1].z - globalStart->z)
                                                            - (float)_FP8)
                                                    - (float)((float)((float)((float)(globalBounds->b[0].z
                                                                                    - globalStart->z)
                                                                            - (float)_FP31)
                                                                    + (float)((float)(globalBounds->b[1].z
                                                                                    - globalStart->z)
                                                                            - (float)_FP8))
                                                            * (float)0.5))
                                            * modelAxis->mat[0].z))
                      + (float)__fabs((float)((float)((float)((float)(globalBounds->b[1].y - globalStart->y)
                                                            - (float)_FP9)
                                                    - (float)((float)((float)((float)(globalBounds->b[0].y
                                                                                    - globalStart->y)
                                                                            - (float)_FP12)
                                                                    + (float)((float)(globalBounds->b[1].y
                                                                                    - globalStart->y)
                                                                            - (float)_FP9))
                                                            * (float)0.5))
                                            * modelAxis->mat[0].y)))
              + (float)__fabs((float)((float)v16 * modelAxis->mat[0].x)));
  v19 = (float)((float)((float)__fabs((float)((float)((float)((float)(globalBounds->b[1].z - globalStart->z)
                                                            - (float)_FP8)
                                                    - (float)((float)((float)((float)(globalBounds->b[0].z
                                                                                    - globalStart->z)
                                                                            - (float)_FP31)
                                                                    + (float)((float)(globalBounds->b[1].z
                                                                                    - globalStart->z)
                                                                            - (float)_FP8))
                                                            * (float)0.5))
                                            * modelAxis->mat[2].z))
                      + (float)__fabs((float)((float)((float)((float)(globalBounds->b[1].y - globalStart->y)
                                                            - (float)_FP9)
                                                    - (float)((float)((float)((float)(globalBounds->b[0].y
                                                                                    - globalStart->y)
                                                                            - (float)_FP12)
                                                                    + (float)((float)(globalBounds->b[1].y
                                                                                    - globalStart->y)
                                                                            - (float)_FP9))
                                                            * (float)0.5))
                                            * modelAxis->mat[2].y)))
              + (float)__fabs((float)((float)v16 * modelAxis->mat[2].x)));
  v20 = (float)((float)((float)v17
                      + (float)__fabs((float)((float)((float)((float)(globalBounds->b[1].y - globalStart->y)
                                                            - (float)_FP9)
                                                    - (float)((float)((float)((float)(globalBounds->b[0].y
                                                                                    - globalStart->y)
                                                                            - (float)_FP12)
                                                                    + (float)((float)(globalBounds->b[1].y
                                                                                    - globalStart->y)
                                                                            - (float)_FP9))
                                                            * (float)0.5))
                                            * modelAxis->mat[1].y)))
              + (float)__fabs((float)((float)v16 * modelAxis->mat[1].x)));
  v21 = (float)((float)((float)v15 * modelAxis->mat[0].x)
              + (float)((float)((float)v14 * modelAxis->mat[0].z)
                      + (float)((float)((float)((float)((float)(globalBounds->b[0].y - globalStart->y) - (float)_FP12)
                                              + (float)((float)(globalBounds->b[1].y - globalStart->y) - (float)_FP9))
                                      * (float)0.5)
                              * modelAxis->mat[0].y)));
  v22 = (float)((float)((float)v15 * modelAxis->mat[1].x)
              + (float)((float)((float)v14 * modelAxis->mat[1].z)
                      + (float)((float)((float)((float)((float)(globalBounds->b[0].y - globalStart->y) - (float)_FP12)
                                              + (float)((float)(globalBounds->b[1].y - globalStart->y) - (float)_FP9))
                                      * (float)0.5)
                              * modelAxis->mat[1].y)));
  v23 = (float)((float)((float)v15 * modelAxis->mat[2].x)
              + (float)((float)((float)v14 * modelAxis->mat[2].z)
                      + (float)((float)((float)((float)((float)(globalBounds->b[0].y - globalStart->y) - (float)_FP12)
                                              + (float)((float)(globalBounds->b[1].y - globalStart->y) - (float)_FP9))
                                      * (float)0.5)
                              * modelAxis->mat[2].y)));
  _FP12 = (float)((float)__fabs((float)((float)v21 - (float)v18)) - (float)__fabs((float)((float)v21 + (float)v18)));
  _FP11 = (float)((float)__fabs((float)((float)v22 - (float)v20)) - (float)__fabs((float)((float)v20 + (float)v22)));
  _FP10 = (float)((float)__fabs((float)((float)v23 - (float)v19)) - (float)__fabs((float)((float)v19 + (float)v23)));
  __asm
  {
    fsel      f9, f12, f4, f5
    fsel      f8, f11, f3, f1
    fsel      f7, f10, f2, f13
  }
  result->x = (float)_FP9 + (float)1.0;
  result->y = (float)_FP8 + (float)1.0;
  result->z = (float)_FP7 + (float)1.0;
  return result;
}


// ========================================================================
// ?TraceThroughSubModelTree@idPolygonModelCollisionDetection@@CAXPAVidTraceWork@@@Z
// EA  : 0x825F15B0
// RVA : 0x005F15B0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_trace.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TraceThroughSubModelTree(
        idTraceWork *tw,
        double a2,
        double a3,
        double a4,
        double a5,
        double fraction,
        double a7,
        double a8,
        double a9)
{
  BOOL quickExit; // r9
  double x; // fp30
  double y; // fp29
  double z; // fp28
  int v14; // r25
  double v15; // fp27
  int v16; // r11
  double v17; // fp31
  double v18; // fp26
  double v19; // fp24
  double v20; // fp25
  float *v21; // r27
  float *v22; // r28
  char *v23; // r26
  cm_node_t *v24; // r31
  traceType_t traceType; // r10
  int v26; // r29
  int v27; // r29
  int v28; // r29
  int v29; // r29
  int v30; // r29
  int v31; // r29
  int v32; // r29
  int v33; // r29
  int v34; // r29
  int planeType; // r11
  double v36; // fp11
  double v37; // fp10
  double v38; // fp0
  BOOL v40; // r11
  double v50; // fp0
  double v51; // fp8
  float v52; // [sp+50h] [-540h] BYREF
  float v53; // [sp+54h] [-53Ch]
  float v54; // [sp+58h] [-538h]
  float v55; // [sp+5Ch] [-534h]
  float v56; // [sp+60h] [-530h] BYREF
  float v57; // [sp+64h] [-52Ch]
  float v58; // [sp+68h] [-528h]
  float v59; // [sp+6Ch] [-524h]
  char v60; // [sp+70h] [-520h] BYREF
  char v61; // [sp+F0h] [-4A0h] BYREF
  char v62; // [sp+100h] [-490h] BYREF

  quickExit = tw->quickExit;
  x = tw->start.x;
  y = tw->start.y;
  z = tw->start.z;
  v14 = 0;
  v15 = tw->end.x;
  v16 = 0;
  v17 = 0.0;
  v18 = tw->end.y;
  v19 = 1.0;
  v20 = tw->end.z;
  v56 = tw->start.x;
  v57 = y;
  v58 = z;
  v52 = v15;
  v53 = v18;
  v54 = v20;
  v59 = 0.0;
  v55 = 1.0;
  if ( quickExit )
    return;
  v21 = (float *)&v62;
  v22 = (float *)&v61;
  v23 = &v60;
  while ( 1 )
  {
    v24 = &tw->subModelPtrs.nodes[v16];
    if ( v24->numPolygons == 0 )
    {
      if ( v24->numPolytopes == 0 )
        goto LABEL_50;
      traceType = tw->traceType;
      if ( traceType != TRACE_CONTENTS && traceType != TRACE_CONTENTS_POINT )
        goto LABEL_50;
    }
    if ( (unsigned int)(tw->traceType - 1) > 8 )
      goto LABEL_50;
    if ( tw->traceType == TRACE_TRANSLATION_POINT )
      break;
    switch ( tw->traceType )
    {
      case TRACE_ROTATION:
      case TRACE_ROTATION_POINT:
        v28 = 0;
        if ( v24->numPolygons != 0 )
        {
          while ( !idPolygonModelCollisionDetection::RotateTrmThroughPolygon(
                     tw,
                     polygonNum: tw->subModelPtrs.primitiveIndices[v24->firstPrimitive + v28],
                     a3: a2,
                     a4: a3,
                     a5: a4,
                     a6: a5,
                     a7: fraction,
                     a8: a7,
                     a9: a8,
                     a10: a9) )
          {
            if ( ++v28 >= (unsigned int)v24->numPolygons )
              goto LABEL_50;
          }
          return;
        }
        break;
      case TRACE_CONTENTS:
        v31 = 0;
        if ( v24->numPolytopes != 0 )
        {
          while ( (unsigned __int8)idPolygonModelCollisionDetection::TestTrmVertsInPolytope(
                                     tw,
                                     polytopeNum: tw->subModelPtrs.primitiveIndices[v24->numPolygons + v24->firstPrimitive + v31]) == 0 )
          {
            if ( ++v31 >= (unsigned int)v24->numPolytopes )
              goto LABEL_39;
          }
          return;
        }
LABEL_39:
        v32 = 0;
        if ( v24->numPolygons != 0 )
        {
          while ( (unsigned __int8)idPolygonModelCollisionDetection::TestTrmInPolygon(
                                     tw,
                                     polygonNum: tw->subModelPtrs.primitiveIndices[v24->firstPrimitive + v32]) == 0 )
          {
            if ( ++v32 >= (unsigned int)v24->numPolygons )
              goto LABEL_50;
          }
          return;
        }
        break;
      case TRACE_CONTENTS_POINT:
        v33 = 0;
        if ( v24->numPolytopes != 0 )
        {
          while ( (unsigned __int8)idPolygonModelCollisionDetection::TestTrmVertsInPolytope(
                                     tw,
                                     polytopeNum: tw->subModelPtrs.primitiveIndices[v24->numPolygons + v24->firstPrimitive + v33]) == 0 )
          {
            if ( ++v33 >= (unsigned int)v24->numPolytopes )
              goto LABEL_50;
          }
          return;
        }
        break;
      case TRACE_CONTACTS_UNI_DIR:
        v29 = 0;
        if ( v24->numPolygons != 0 )
        {
          while ( !idPolygonModelCollisionDetection::TranslateTrmThroughPolygon(
                     tw,
                     polygonNum: tw->subModelPtrs.primitiveIndices[v24->firstPrimitive + v29]) )
          {
            if ( ++v29 >= (unsigned int)v24->numPolygons )
              goto LABEL_50;
          }
          return;
        }
        break;
      case TRACE_CONTACTS_OMNI_DIR:
        v30 = 0;
        if ( v24->numPolygons != 0 )
        {
          while ( (unsigned __int8)idPolygonModelCollisionDetection::TestTrmInContactWithPolygon(
                                     tw,
                                     polygonNum: tw->subModelPtrs.primitiveIndices[v24->firstPrimitive + v30]) == 0 )
          {
            if ( ++v30 >= (unsigned int)v24->numPolygons )
              goto LABEL_50;
          }
          return;
        }
        break;
      case TRACE_TRANSLATION:
        v26 = 0;
        if ( v24->numPolygons != 0 )
        {
          while ( !idPolygonModelCollisionDetection::TranslateTrmThroughPolygon(
                     tw,
                     polygonNum: tw->subModelPtrs.primitiveIndices[v24->firstPrimitive + v26]) )
          {
            if ( ++v26 >= (unsigned int)v24->numPolygons )
              goto LABEL_50;
          }
          return;
        }
        break;
      default:
        v34 = 0;
        if ( v24->numPolygons != 0 )
        {
          while ( (unsigned __int8)idPolygonModelCollisionDetection::ClipPolygonWithTrm(
                                     tw,
                                     polygonNum: tw->subModelPtrs.primitiveIndices[v24->firstPrimitive + v34]) == 0 )
          {
            if ( ++v34 >= (unsigned int)v24->numPolygons )
              goto LABEL_50;
          }
          return;
        }
        break;
    }
LABEL_50:
    planeType = v24->planeType;
    if ( v24->planeType == -1 || (fraction = tw->fraction) <= v17 )
    {
      if ( v14 == 0 )
        return;
      v22 -= 8;
      x = *v22;
      v23 -= 4;
      v16 = *(_DWORD *)v23;
      v21 -= 8;
      v15 = *v21;
      --v14;
      y = v22[1];
      z = v22[2];
      v17 = v22[3];
      v18 = v21[1];
      v20 = v21[2];
      v19 = v21[3];
      v57 = v22[1];
      v56 = x;
      v58 = z;
      v59 = v17;
      goto LABEL_65;
    }
    v36 = (float)(*(&v56 + planeType) - v24->planeDist);
    v37 = *(&tw->trmExtents.x + planeType);
    v38 = (float)(*(&v52 + planeType) - v24->planeDist);
    if ( v36 < v37 || v38 < v37 )
    {
      if ( v36 >= -v37 || v38 >= -v37 )
      {
        _FP12 = (float)((float)(*(&v56 + planeType) - v24->planeDist) - (float)(*(&v52 + planeType) - v24->planeDist));
        v40 = false;
        _FP13 = 1.0;
        _FP0 = 0.0;
        if ( __fabs(_FP12) >= idMath::FLT_SMALLEST_NON_DENORMAL )
        {
          __asm { fsel      f13, f12, f10, f9 }
          v40 = _FP12 < 0.0;
          _FP10 = (float)((float)((float)_FP13 + (float)v36) * (float)((float)1.0 / (float)_FP12));
          _FP9 = (float)((float)((float)v36 - (float)_FP13) * (float)((float)1.0 / (float)_FP12));
          __asm
          {
            fsel      f8, f10, f10, f22
            fsel      f7, f9, f9, f22
          }
          _FP6 = (float)((float)_FP8 - (float)1.0);
          _FP4 = (float)((float)_FP7 - (float)1.0);
          __asm
          {
            fsel      f13, f6, f23, f8
            fsel      f0, f4, f23, f7
          }
        }
        a5 = (float)((float)((float)v20 - (float)z) * (float)_FP0);
        v51 = (float)((float)((float)((float)v15 - (float)x) * (float)_FP0) + (float)x);
        a8 = (float)((float)((float)((float)v18 - (float)y) * (float)_FP0) + (float)y);
        a7 = (float)((float)((float)((float)v20 - (float)z) * (float)_FP0) + (float)z);
        v50 = (float)((float)((float)((float)v19 - (float)v17) * (float)_FP0) + (float)v17);
        if ( fraction > v50 )
        {
          *v22 = v51;
          v22[1] = a8;
          ++v14;
          v22[2] = a7;
          v22[3] = v50;
          v22 += 8;
          *v21 = v15;
          v21[1] = v18;
          v21[2] = v20;
          v21[3] = v19;
          v21 += 8;
          *(_DWORD *)v23 = v24->children[!v40];
          v23 += 4;
        }
        a9 = (float)((float)((float)v18 - (float)y) * (float)_FP13);
        v16 = v24->children[v40];
        v19 = (float)((float)((float)((float)v19 - (float)v17) * (float)_FP13) + (float)v17);
        v15 = (float)((float)((float)((float)v15 - (float)x) * (float)_FP13) + (float)x);
        v20 = (float)((float)((float)((float)v20 - (float)z) * (float)_FP13) + (float)z);
        v18 = (float)((float)((float)((float)v18 - (float)y) * (float)_FP13) + (float)y);
LABEL_65:
        v55 = v19;
        v54 = v20;
        v53 = v18;
        v52 = v15;
        goto LABEL_66;
      }
      v16 = v24->children[1];
    }
    else
    {
      v16 = v24->children[0];
    }
LABEL_66:
    if ( tw->quickExit )
      return;
  }
  v27 = 0;
  if ( v24->numPolygons == 0 )
    goto LABEL_50;
  while ( !idPolygonModelCollisionDetection::TranslatePointThroughPolygon(
             tw,
             polygonNum: tw->subModelPtrs.primitiveIndices[v24->firstPrimitive + v27]) )
  {
    if ( ++v27 >= (unsigned int)v24->numPolygons )
      goto LABEL_50;
  }
}


// ========================================================================
// ?TraceThroughSubModel@idPolygonModelCollisionDetection@@SAXPAVidTraceWork@@PBUcm_subModelData_t@@H@Z
// EA  : 0x825F1B48
// RVA : 0x005F1B48
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_trace.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TraceThroughSubModel(
        idTraceWork *tw,
        cm_subModelData_t *subModelData,
        int subModelNum)
{
  cm_subModelData_t *v4; // r31
  idBounds *p_bounds; // r31
  double v7; // fp8
  double v8; // fp7
  double v9; // fp6
  double v10; // fp5
  double v11; // fp4
  double v12; // fp3
  double v13; // fp2
  double v14; // fp1
  trace_t *traceResult; // r11

  v4 = subModelData;
  if ( subModelData->header.loadedSize == 32 )
  {
    p_bounds = &subModelData->header.bounds;
    if ( idPolygonModelCollisionDetection::TestStuckInSubModelBounds(tw, subModelBounds: &subModelData->header.bounds) )
      return;
    v4 = idPolygonModelCollisionDetection::SetupSubModelForBounds(
           data: (cm_subModelData_t *)tw->subModelDataForBounds,
           size: 768,
           bounds: p_bounds);
  }
  tw->subModelPtrs.isConvex = v4->isConvex;
  tw->subModelPtrs.nodes = (cm_node_t *)((char *)v4 + v4->nodeOffset);
  tw->subModelPtrs.primitiveIndices = (unsigned __int16 *)((char *)v4 + v4->primitiveIndexOffset);
  tw->subModelPtrs.materials = (cm_material_t *)((char *)v4 + v4->materialOffset);
  tw->subModelPtrs.polygons = (cm_polygon_t *)((char *)v4 + v4->polygonOffset);
  tw->subModelPtrs.polygonEdges = (unsigned __int16 *)((char *)v4 + v4->polygonEdgeOffset);
  tw->subModelPtrs.edges = (cm_edge_t *)((char *)v4 + v4->edgeOffset);
  tw->subModelPtrs.vertices = (cm_vertex_t *)((char *)v4 + v4->vertexOffset);
  tw->subModelPtrs.polytopes = (cm_polytope_t *)((char *)v4 + v4->polytopeOffset);
  tw->subModelPtrs.polytopePlanes = (idPlane *)((char *)v4 + v4->polytopePlaneOffset);
  idModelCheckCounts::SetupForSubModel(this: &tw->modelCheckCounts, subModelData: v4);
  tw->subModelNum = subModelNum;
  idPolygonModelCollisionDetection::TraceThroughSubModelTree(
    tw,
    a2: v14,
    a3: v13,
    a4: v12,
    a5: v11,
    fraction: v10,
    a7: v9,
    a8: v8,
    a9: v7);
  if ( v4->header.loadedSize == 32 )
  {
    traceResult = tw->traceResult;
    if ( traceResult != nullptr && traceResult->fraction < 1.0 )
      traceResult->c.flags |= 1u;
  }
}


// ========================================================================
// ?GetSubModelsForTrace@idPolygonModelCollisionDetection@@SAHABUcm_polygonModel_t@@ABVidVec3@@11PAH@Z
// EA  : 0x825F1C68
// RVA : 0x005F1C68
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_trace.cpp
// ========================================================================

unsigned int __fastcall idPolygonModelCollisionDetection::GetSubModelsForTrace(
        const cm_polygonModel_t *model,
        const idVec3 *start,
        const idVec3 *end,
        const idVec3 *extents,
        int *subModelNums)
{
  int numModelTreeNodes; // r11
  int numSubModels; // r10
  int *v9; // r9
  unsigned int result; // r3
  int v17; // r11
  int v18; // r5
  int *v21; // r4
  int *v22; // r30
  int planeType; // r11
  char v29; // cr56
  char v30; // cr56
  BOOL v31; // r11
  char v32; // cr56
  char v33; // cr56
  char v34; // cr57
  int v35; // r7
  _DWORD v36[4]; // [sp+10h] [-500h] BYREF
  _DWORD v37[4]; // [sp+20h] [-4F0h] BYREF
  _DWORD v38[12]; // [sp+30h] [-4E0h] BYREF
  char v39; // [sp+60h] [-4B0h] BYREF
  char v40; // [sp+E0h] [-430h] BYREF
  char v41; // [sp+F0h] [-420h] BYREF

  numModelTreeNodes = model->numModelTreeNodes;
  if ( model->numModelTreeNodes != 0 )
  {
    _R9 = 16;
    __asm { lvlx128   v63, r0, r4 }
    __asm { lvlx128   v62, r0, r5 }
    v36[3] = 0;
    memset(v36, 255, 12);
    __asm { lvrx128   v61, r9, r4 }
    __asm { lvrx128   v60, r9, r5 }
    _R9 = &_vmx_00000000000000000000000000000000;
    v37[2] = 0x7FFFFFFF;
    _R8 = &_vmx_3f8000003f8000003f8000003f800000;
    v37[0] = 0x7FFFFFFF;
    _R28 = v36;
    v37[1] = 0x7FFFFFFF;
    __asm { vor128    v58, v95, v61 }
    _R5 = &_vmx_2edbe6ff2edbe6ff2edbe6ff2edbe6ff;
    __asm
    {
      vor128    v56, v94, v60
      lvx128    v59, r0, r8
    }
    _R8 = v37;
    __asm { lvx128    v61, r0, r9 }
    v37[3] = 0x7FFFFFFF;
    v38[0] = -1;
    result = 0;
    v38[5] = -1;
    v17 = 0;
    __asm { lvx128    v57, r0, r5 }
    memset(&v38[1], 0, 16);
    v18 = 0;
    _R10 = &v41;
    _R9 = &v40;
    memset(&v38[6], 0, 16);
    v21 = (int *)&v39;
    v22 = subModelNums - 1;
    v38[10] = -1;
    v38[11] = 0;
    __asm { lvx128    v63, r0, r28 }
    _R28 = 4;
    __asm
    {
      vand128   v8, v90, v63
      vand128   v58, v88, v63
      lvx128    v56, r0, r8
    }
    while ( 1 )
    {
      while ( v17 >= 0 )
      {
        _R8 = &model->modelTreeNodes[v17];
        planeType = _R8->planeType;
        if ( _R8->planeType == -1 )
        {
          if ( v18 == 0 )
            return result;
          _R9 -= 32;
          v17 = *--v21;
          _R10 -= 32;
          --v18;
          __asm
          {
            lvx128    v8, r0, r9
            lvx128    v58, r0, r10
          }
        }
        else
        {
          _R7 = 16 * planeType;
          __asm { lvlx128   v55, r8, r28 }
          _R27 = v38;
          __asm
          {
            vspltisw128 v60, 0
            vspltw128 v54, v55, 0
          }
          _R11 = 4 * planeType;
          __asm
          {
            lvx128    v53, r7, r27
            vand128   v52, v8, v53
            lvlx128   v51, r11, r6
            vand128   v50, v90, v53
            vspltw128 v0, v51, 0
            vsldoi128 v49, v84, v52, 4
            vsldoi128 v48, v82, v50, 4
            vor128    v47, v84, v49
            vor128    v46, v82, v48
            vsldoi128 v45, v79, v47, 8
            vsldoi128 v44, v78, v46, 8
            vor128    v43, v79, v45
            vor128    v42, v78, v44
            vsubfp128 v62, v75, v54
            vsubfp128 v63, v74, v54
            vcmpgtfp128 v41, v94, v0
            vcmpgtfp128 v40, v95, v0
            vand128   v39, v73, v40
            vcmpequw128. v38, v71, v60
          }
          if ( v29 )
          {
            __asm
            {
              vsubfp128 v13, v93, v0
              vcmpgtfp128 v37, v13, v63
              vcmpgtfp128 v36, v13, v62
              vand128   v35, v68, v37
              vcmpequw128. v34, v67, v60
            }
            if ( v30 )
            {
              __asm
              {
                vsubfp128 v63, v94, v63
                vor128    v12, v91, v59
                vor128    v11, v93, v61
              }
              v31 = false;
              __asm
              {
                vand128   v33, v95, v56
                vcmpgtfp128. v32, v65, v57
              }
              if ( v32 != 0 )
              {
                __asm
                {
                  vrefp128  v55, v63
                  vcmpgtfp128 v10, v93, v63
                  vcmpgtfp128. v54, v92, v63
                  vaddfp128 v9, v87, v55
                  vor128    v11, v87, v55
                  vmulfp128 v12, v95, v55
                  vsel      v10, v0, v13, v10
                  vnmsubfp  v0, v12, v9, v11
                }
                __asm { vaddfp128 v53, v94, v10 }
                v31 = (unsigned __int8)((v33 << 7) | (v34 << 6) & 0x80) != 0;
                __asm
                {
                  vsubfp128 v52, v94, v10
                  vmulfp128 v51, v85, v0
                  vmulfp128 v50, v84, v0
                  vmaxfp128 v49, v83, v61
                  vmaxfp128 v48, v82, v61
                  vminfp128 v12, v81, v59
                  vminfp128 v11, v80, v59
                }
              }
              __asm { vsubfp128 v0, v90, v8 }
              __asm { stvx128   v58, r0, r10 }
              v35 = 4 * (!v31 + 2);
              ++v18;
              _R10 += 32;
              v17 = _R8->children[v31];
              __asm
              {
                vmaddfp   v13, v0, v8, v11
                vmaddfp   v0, v0, v8, v12
              }
              *v21++ = *(int *)((char *)&_R8->planeType + v35);
              __asm { stvx128   v13, r0, r9 }
              _R9 += 32;
              __asm { vmr128    v58, v0 }
            }
            else
            {
              v17 = _R8->children[1];
            }
          }
          else
          {
            v17 = _R8->children[0];
          }
        }
      }
      if ( result >= 0x80 )
        break;
      ++result;
      *++v22 = -1 - v17;
      if ( v18 == 0 )
        break;
      _R9 -= 32;
      v17 = *--v21;
      _R10 -= 32;
      --v18;
      __asm
      {
        lvx128    v8, r0, r9
        lvx128    v58, r0, r10
      }
    }
  }
  else
  {
    numSubModels = model->numSubModels;
    if ( numSubModels > 0 )
    {
      v9 = subModelNums - 1;
      do
      {
        if ( numModelTreeNodes >= 128 )
          break;
        *++v9 = numModelTreeNodes++;
        numSubModels = model->numSubModels;
      }
      while ( numModelTreeNodes < numSubModels );
    }
    return numSubModels;
  }
  return result;
}


// ========================================================================
// ?TraceThroughModel@idPolygonModelCollisionDetection@@SAXPAVidTraceWork@@PBUcm_polygonModel_t@@@Z
// EA  : 0x825F1F58
// RVA : 0x005F1F58
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_trace.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TraceThroughModel(idTraceWork *tw, const cm_polygonModel_t *model)
{
  signed int SubModelsForTrace; // r3
  signed int v5; // r30
  int *v6; // r28
  int v7; // r31
  const cm_subModel_t *v8; // r29
  cm_subModelData_t *v9; // r25
  int v10; // [sp+4Ch] [-244h] BYREF
  int v11; // [sp+50h] [-240h] BYREF

  SubModelsForTrace = idPolygonModelCollisionDetection::GetSubModelsForTrace(
                        model,
                        start: (const idVec3 *)&tw->start,
                        end: (const idVec3 *)&tw->end,
                        extents: (const idVec3 *)&tw->trmExtents,
                        subModelNums: &v11);
  if ( SubModelsForTrace > 0 )
  {
    v5 = SubModelsForTrace;
    v6 = &v10;
    do
    {
      v7 = *++v6;
      v8 = &model->subModels[*v6];
      v9 = (cm_subModelData_t *)AcquireSubModelData(subModel: v8);
      idPolygonModelCollisionDetection::TraceThroughSubModel(tw, subModelData: v9, subModelNum: v7);
      ReleaseSubModelData(subModel: (const cm_subModelData_t *)v8, data: v9);
      --v5;
    }
    while ( v5 != 0 );
  }
}

