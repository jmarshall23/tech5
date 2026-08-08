
// ========================================================================
// ?TestTrmEdgeInContactWithPolygon@idPolygonModelCollisionDetection@@CAXPAVidTraceWork@@PBUcm_polygon_t@@H@Z
// EA  : 0x825E8780
// RVA : 0x005E8780
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_contacts.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TestTrmEdgeInContactWithPolygon(
        idTraceWork *tw,
        const cm_polygon_t *poly,
        const int trmEdgeNum)
{
  unsigned int i; // r21
  int v7; // r6
  unsigned __int16 v8; // r25
  cm_vertex_t *vertices; // r10
  cm_edge_t *v10; // r11
  cm_trmEdge_t *v11; // r26
  float *v12; // r28
  float *v13; // r11
  int v14; // r9
  idVec4 *v15; // r27
  float *v16; // r10
  double v17; // fp7
  double v18; // fp6
  double v19; // fp5
  double v20; // fp8
  double v21; // fp12
  double v22; // fp3
  double v23; // fp2
  double v24; // fp12
  double v25; // fp12
  double v26; // fp11
  double v27; // fp13
  double v28; // fp12
  double v29; // fp31
  double v30; // fp10
  double v31; // fp30
  double v32; // fp29
  double v33; // fp9
  double v34; // fp8
  double v35; // fp3
  double v36; // fp11
  double v37; // fp3
  double v38; // fp0
  double v39; // fp12
  contactsResult_t *contactsResult; // r11
  char *v41; // r31
  double v42; // fp6
  int v43; // r3

  for ( i = 0; i < poly->numEdges; ++i )
  {
    v7 = tw->subModelPtrs.polygonEdges[poly->firstEdge + i];
    v8 = tw->subModelPtrs.polygonEdges[poly->firstEdge + i];
    if ( ((1 << (v7 & 7)) & tw->modelCheckCounts.edgeCheckCounts[(v7 & 0x3FFF) >> 3]) == 0 && (v7 & 0x4000) == 0 )
    {
      v10 = &tw->subModelPtrs.edges[v7 & 0x3FFF];
      vertices = tw->subModelPtrs.vertices;
      v11 = &tw->edges[trmEdgeNum];
      v12 = (float *)((char *)&vertices->p.x
                    + __ROL4__(
                        *(unsigned __int16 *)((char *)v10->vertexNum
                                            + ((tw->subModelPtrs.polygonEdges[poly->firstEdge + i] >> 14) & 2)),
                        4));
      v13 = (float *)((char *)&vertices->p.x
                    + __ROL4__(*(unsigned __int16 *)((char *)v10->vertexNum + (((unsigned int)~v7 >> 14) & 2)), 4));
      v14 = v11->vertexNum[1] + 128;
      v15 = &tw->vertexPosition[v11->vertexNum[0]];
      v16 = (float *)((char *)tw + v14 * 16);
      v17 = (float)((float)((float)(v13[1] - v12[1]) * (float)(*(float *)&tw->verts[v14].bounds.b[1][1] - v15->z))
                  - (float)((float)(v13[2] - v12[2]) * (float)(*(float *)&tw->verts[v14].bounds.b[0][2] - v15->y)));
      v18 = (float)((float)((float)(v13[2] - v12[2]) * (float)(*(float *)&tw->verts[v14].bounds.b[0][0] - v15->x))
                  - (float)((float)(*(float *)&tw->verts[v14].bounds.b[1][1] - v15->z) * (float)(*v13 - *v12)));
      v19 = (float)((float)((float)(*(float *)&tw->verts[v14].bounds.b[0][2] - v15->y) * (float)(*v13 - *v12))
                  - (float)((float)(v13[1] - v12[1]) * (float)(*(float *)&tw->verts[v14].bounds.b[0][0] - v15->x)));
      v20 = (float)((float)((float)(v13[2] - v12[2])
                          * (float)((float)((float)(v13[2] - v12[2])
                                          * (float)(*(float *)&tw->verts[v14].bounds.b[0][0] - v15->x))
                                  - (float)((float)(*(float *)&tw->verts[v14].bounds.b[1][1] - v15->z)
                                          * (float)(*v13 - *v12))))
                  - (float)((float)(v13[1] - v12[1])
                          * (float)((float)((float)(*(float *)&tw->verts[v14].bounds.b[0][2] - v15->y)
                                          * (float)(*v13 - *v12))
                                  - (float)((float)(v13[1] - v12[1])
                                          * (float)(*(float *)&tw->verts[v14].bounds.b[0][0] - v15->x)))));
      v21 = (float)((float)(v12[2]
                          * (float)((float)((float)(v13[1] - v12[1])
                                          * (float)((float)((float)(v13[1] - v12[1])
                                                          * (float)(*(float *)&tw->verts[v14].bounds.b[1][1] - v15->z))
                                                  - (float)((float)(v13[2] - v12[2])
                                                          * (float)(*(float *)&tw->verts[v14].bounds.b[0][2] - v15->y))))
                                  - (float)((float)((float)((float)(v13[2] - v12[2])
                                                          * (float)(*(float *)&tw->verts[v14].bounds.b[0][0] - v15->x))
                                                  - (float)((float)(*(float *)&tw->verts[v14].bounds.b[1][1] - v15->z)
                                                          * (float)(*v13 - *v12)))
                                          * (float)(*v13 - *v12))))
                  + (float)(v12[1]
                          * (float)((float)((float)((float)((float)(*(float *)&tw->verts[v14].bounds.b[0][2] - v15->y)
                                                          * (float)(*v13 - *v12))
                                                  - (float)((float)(v13[1] - v12[1])
                                                          * (float)(*(float *)&tw->verts[v14].bounds.b[0][0] - v15->x)))
                                          * (float)(*v13 - *v12))
                                  - (float)((float)(v13[2] - v12[2])
                                          * (float)((float)((float)(v13[1] - v12[1])
                                                          * (float)(*(float *)&tw->verts[v14].bounds.b[1][1] - v15->z))
                                                  - (float)((float)(v13[2] - v12[2])
                                                          * (float)(*(float *)&tw->verts[v14].bounds.b[0][2] - v15->y)))))));
      v22 = (float)((float)(*(float *)&tw->verts[v14].bounds.b[1][1]
                          * (float)((float)((float)(v13[1] - v12[1])
                                          * (float)((float)((float)(v13[1] - v12[1])
                                                          * (float)(*(float *)&tw->verts[v14].bounds.b[1][1] - v15->z))
                                                  - (float)((float)(v13[2] - v12[2])
                                                          * (float)(*(float *)&tw->verts[v14].bounds.b[0][2] - v15->y))))
                                  - (float)((float)((float)((float)(v13[2] - v12[2])
                                                          * (float)(*(float *)&tw->verts[v14].bounds.b[0][0] - v15->x))
                                                  - (float)((float)(*(float *)&tw->verts[v14].bounds.b[1][1] - v15->z)
                                                          * (float)(*v13 - *v12)))
                                          * (float)(*v13 - *v12))))
                  + (float)(*(float *)&tw->verts[v14].bounds.b[0][2]
                          * (float)((float)((float)((float)((float)(*(float *)&tw->verts[v14].bounds.b[0][2] - v15->y)
                                                          * (float)(*v13 - *v12))
                                                  - (float)((float)(v13[1] - v12[1])
                                                          * (float)(*(float *)&tw->verts[v14].bounds.b[0][0] - v15->x)))
                                          * (float)(*v13 - *v12))
                                  - (float)((float)(v13[2] - v12[2])
                                          * (float)((float)((float)(v13[1] - v12[1])
                                                          * (float)(*(float *)&tw->verts[v14].bounds.b[1][1] - v15->z))
                                                  - (float)((float)(v13[2] - v12[2])
                                                          * (float)(*(float *)&tw->verts[v14].bounds.b[0][2] - v15->y)))))));
      v23 = (float)-(float)((float)(*v12
                                  * (float)((float)((float)(v13[2] - v12[2])
                                                  * (float)((float)((float)(v13[2] - v12[2])
                                                                  * (float)(*(float *)&tw->verts[v14].bounds.b[0][0]
                                                                          - v15->x))
                                                          - (float)((float)(*(float *)&tw->verts[v14].bounds.b[1][1]
                                                                          - v15->z)
                                                                  * (float)(*v13 - *v12))))
                                          - (float)((float)(v13[1] - v12[1])
                                                  * (float)((float)((float)(*(float *)&tw->verts[v14].bounds.b[0][2]
                                                                          - v15->y)
                                                                  * (float)(*v13 - *v12))
                                                          - (float)((float)(v13[1] - v12[1])
                                                                  * (float)(*(float *)&tw->verts[v14].bounds.b[0][0]
                                                                          - v15->x))))))
                          + (float)v21);
      v24 = (float)((float)(v15->x * (float)v20)
                  + (float)((float)(v15->z
                                  * (float)((float)((float)(v13[1] - v12[1])
                                                  * (float)((float)((float)(v13[1] - v12[1])
                                                                  * (float)(*(float *)&tw->verts[v14].bounds.b[1][1]
                                                                          - v15->z))
                                                          - (float)((float)(v13[2] - v12[2])
                                                                  * (float)(*(float *)&tw->verts[v14].bounds.b[0][2]
                                                                          - v15->y))))
                                          - (float)((float)((float)((float)(v13[2] - v12[2])
                                                                  * (float)(*(float *)&tw->verts[v14].bounds.b[0][0]
                                                                          - v15->x))
                                                          - (float)((float)(*(float *)&tw->verts[v14].bounds.b[1][1]
                                                                          - v15->z)
                                                                  * (float)(*v13 - *v12)))
                                                  * (float)(*v13 - *v12))))
                          + (float)(v15->y
                                  * (float)((float)((float)((float)((float)(*(float *)&tw->verts[v14].bounds.b[0][2]
                                                                          - v15->y)
                                                                  * (float)(*v13 - *v12))
                                                          - (float)((float)(v13[1] - v12[1])
                                                                  * (float)(*(float *)&tw->verts[v14].bounds.b[0][0]
                                                                          - v15->x)))
                                                  * (float)(*v13 - *v12))
                                          - (float)((float)(v13[2] - v12[2])
                                                  * (float)((float)((float)(v13[1] - v12[1])
                                                                  * (float)(*(float *)&tw->verts[v14].bounds.b[1][1]
                                                                          - v15->z))
                                                          - (float)((float)(v13[2] - v12[2])
                                                                  * (float)(*(float *)&tw->verts[v14].bounds.b[0][2]
                                                                          - v15->y))))))));
      v25 = (float)((float)v24 + (float)v23);
      if ( v25 != (float)((float)((float)(*(float *)&tw->verts[v14].bounds.b[0][0]
                                        * (float)((float)((float)(v13[2] - v12[2])
                                                        * (float)((float)((float)(v13[2] - v12[2])
                                                                        * (float)(*(float *)&tw->verts[v14].bounds.b[0][0]
                                                                                - v15->x))
                                                                - (float)((float)(*(float *)&tw->verts[v14].bounds.b[1][1]
                                                                                - v15->z)
                                                                        * (float)(*v13 - *v12))))
                                                - (float)((float)(v13[1] - v12[1])
                                                        * (float)((float)((float)(*(float *)&tw->verts[v14].bounds.b[0][2]
                                                                                - v15->y)
                                                                        * (float)(*v13 - *v12))
                                                                - (float)((float)(v13[1] - v12[1])
                                                                        * (float)(*(float *)&tw->verts[v14].bounds.b[0][0]
                                                                                - v15->x))))))
                                + (float)v22)
                        + (float)v23) )
      {
        v26 = (float)((float)v25
                    / (float)((float)v25
                            - (float)((float)((float)(*(float *)&tw->verts[v14].bounds.b[0][0]
                                                    * (float)((float)((float)(v13[2] - v12[2])
                                                                    * (float)((float)((float)(v13[2] - v12[2])
                                                                                    * (float)(*(float *)&tw->verts[v14].bounds.b[0][0]
                                                                                            - v15->x))
                                                                            - (float)((float)(*(float *)&tw->verts[v14].bounds.b[1][1]
                                                                                            - v15->z)
                                                                                    * (float)(*v13 - *v12))))
                                                            - (float)((float)(v13[1] - v12[1])
                                                                    * (float)((float)((float)(*(float *)&tw->verts[v14].bounds.b[0][2]
                                                                                            - v15->y)
                                                                                    * (float)(*v13 - *v12))
                                                                            - (float)((float)(v13[1] - v12[1])
                                                                                    * (float)(*(float *)&tw->verts[v14].bounds.b[0][0]
                                                                                            - v15->x))))))
                                            + (float)v22)
                                    + (float)v23)));
        if ( v26 >= 0.0 && v26 <= 1.0 )
        {
          v28 = (float)(v13[2] - v12[2]);
          v29 = (float)(v15->x + (float)((float)(*(float *)&tw->verts[v14].bounds.b[0][0] - v15->x) * (float)v26));
          v30 = (float)((float)(v15->x + (float)((float)(*(float *)&tw->verts[v14].bounds.b[0][0] - v15->x) * (float)v26))
                      - *v12);
          v27 = (float)(v13[1] - v12[1]);
          v32 = (float)(v15->z + (float)((float)(*(float *)&tw->verts[v14].bounds.b[1][1] - v15->z) * (float)v26));
          v33 = (float)((float)(v15->y + (float)((float)(v16[1] - v15->y) * (float)v26)) - v12[1]);
          v34 = (float)((float)(v15->z + (float)((float)(*(float *)&tw->verts[v14].bounds.b[1][1] - v15->z) * (float)v26))
                      - v12[2]);
          v35 = (float)((float)((float)((float)(v15->x
                                              + (float)((float)(*(float *)&tw->verts[v14].bounds.b[0][0] - v15->x)
                                                      * (float)v26))
                                      - *v12)
                              * (float)(*v13 - *v12))
                      + (float)((float)((float)((float)(v15->z
                                                      + (float)((float)(*(float *)&tw->verts[v14].bounds.b[1][1] - v15->z)
                                                              * (float)v26))
                                              - v12[2])
                                      * (float)(v13[2] - v12[2]))
                              + (float)((float)((float)(v15->y + (float)((float)(v16[1] - v15->y) * (float)v26)) - v12[1])
                                      * (float)(v13[1] - v12[1]))));
          v31 = (float)(v15->y + (float)((float)(v16[1] - v15->y) * (float)v26));
          v36 = (float)((float)((float)((float)((float)(v15->x
                                                      + (float)((float)(*(float *)&tw->verts[v14].bounds.b[0][0] - v15->x)
                                                              * (float)v26))
                                              - *v12)
                                      * (float)(*v13 - *v12))
                              + (float)((float)((float)((float)(v15->z
                                                              + (float)((float)(*(float *)&tw->verts[v14].bounds.b[1][1]
                                                                              - v15->z)
                                                                      * (float)v26))
                                                      - v12[2])
                                              * (float)(v13[2] - v12[2]))
                                      + (float)((float)((float)(v15->y + (float)((float)(v16[1] - v15->y) * (float)v26))
                                                      - v12[1])
                                              * (float)(v13[1] - v12[1]))))
                      / (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12))
                              + (float)((float)((float)v28 * (float)v28) + (float)((float)v27 * (float)v27))));
          if ( v36 >= 0.0 && v36 <= 1.0 )
          {
            v37 = (float)((float)(v13[2] - v12[2])
                        * (float)((float)v35
                                / (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12))
                                        + (float)((float)((float)v28 * (float)v28) + (float)((float)v27 * (float)v27)))));
            v39 = (float)((float)v30 - (float)((float)(*v13 - *v12) * (float)v36));
            v38 = (float)((float)v33 - (float)((float)(v13[1] - v12[1]) * (float)v36));
            if ( (float)((float)((float)v39 * (float)v39)
                       + (float)((float)((float)((float)v34 - (float)v37) * (float)((float)v34 - (float)v37))
                               + (float)((float)v38 * (float)v38))) <= (double)(float)(tw->contactDepth
                                                                                     * tw->contactDepth) )
            {
              if ( tw->contactsResult->numContacts >= 12 )
                return;
              if ( (float)((float)(tw->edgeNormal[trmEdgeNum].x
                                 * (float)((float)((float)(v13[1] - v12[1])
                                                 * (float)(*(float *)&tw->verts[v14].bounds.b[1][1] - v15->z))
                                         - (float)((float)(v13[2] - v12[2])
                                                 * (float)(*(float *)&tw->verts[v14].bounds.b[0][2] - v15->y))))
                         + (float)((float)(tw->edgeNormal[trmEdgeNum].z
                                         * (float)((float)((float)(*(float *)&tw->verts[v14].bounds.b[0][2] - v15->y)
                                                         * (float)(*v13 - *v12))
                                                 - (float)((float)(v13[1] - v12[1])
                                                         * (float)(*(float *)&tw->verts[v14].bounds.b[0][0] - v15->x))))
                                 + (float)(tw->edgeNormal[trmEdgeNum].y
                                         * (float)((float)((float)(v13[2] - v12[2])
                                                         * (float)(*(float *)&tw->verts[v14].bounds.b[0][0] - v15->x))
                                                 - (float)((float)(*(float *)&tw->verts[v14].bounds.b[1][1] - v15->z)
                                                         * (float)(*v13 - *v12)))))) > 0.0 )
              {
                v17 = -v17;
                v18 = -v18;
                v19 = -v19;
              }
              contactsResult = tw->contactsResult;
              v41 = (char *)contactsResult + 76 * contactsResult->numContacts++;
              *((float *)v41 + 8) = v17;
              *((float *)v41 + 9) = v18;
              *((float *)v41 + 10) = v19;
              idVec3::NormalizeFast(this: (idVec3 *)(v41 + 32));
              v42 = (float)((float)(v12[2] * *((float *)v41 + 10))
                          + (float)((float)(*v12 * *((float *)v41 + 8)) + (float)(v12[1] * *((float *)v41 + 9))));
              *((float *)v41 + 11) = (float)(v12[2] * *((float *)v41 + 10))
                                   + (float)((float)(*v12 * *((float *)v41 + 8)) + (float)(v12[1] * *((float *)v41 + 9)));
              *((float *)v41 + 12) = (float)((float)(*((float *)v41 + 9) * v15->y)
                                           + (float)((float)(v15->z * *((float *)v41 + 10))
                                                   + (float)(v15->x * *((float *)v41 + 8))))
                                   - (float)v42;
              *((_DWORD *)v41 + 13) = *(int *)((char *)&tw->subModelPtrs.materials->contentFlags
                                             + __ROL4__(poly->material, 4));
              *((_DWORD *)v41 + 14) = *(int *)((char *)&tw->subModelPtrs.materials->surfaceFlags
                                             + __ROL4__(poly->material, 4));
              *((_DWORD *)v41 + 15) = *(int *)((char *)&tw->subModelPtrs.materials->surfaceType
                                             + __ROL4__(poly->material, 4));
              v41[89] = tw->subModelPtrs.materials->surfaceColor[__ROL4__(poly->material, 4)];
              v41[90] = tw->subModelPtrs.materials->surfaceColor[__ROL4__(poly->material, 4) + 1];
              v41[91] = tw->subModelPtrs.materials->surfaceColor[__ROL4__(poly->material, 4) + 2];
              *((_DWORD *)v41 + 4) = 1;
              v43 = (tw->subModelNum << 16) & 0x1FFF0000 | 0x40000000 | v8 & 0x3FFF;
              *((_DWORD *)v41 + 17) = (16 * (trmEdgeNum + 32) - 512) >> 4;
              *((_DWORD *)v41 + 16) = v43;
              *((float *)v41 + 5) = v29;
              *((float *)v41 + 6) = v31;
              *((float *)v41 + 7) = v32;
              v41[88] = 0;
            }
          }
        }
      }
    }
  }
}


// ========================================================================
// ?TestTrmVertexInContactWithPolygon@idPolygonModelCollisionDetection@@CAXPAVidTraceWork@@PBUcm_polygon_t@@ABVidPlane@@H@Z
// EA  : 0x825E8BB8
// RVA : 0x005E8BB8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_contacts.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TestTrmVertexInContactWithPolygon(
        idTraceWork *tw,
        const cm_polygon_t *poly,
        const idPlane *polygonPlane,
        const int trmVertNum)
{
  double c; // fp12
  idVec4 *v5; // r9
  double v6; // fp8
  double v7; // fp13
  unsigned int v8; // r10
  double v9; // fp0
  double v10; // fp13
  double v11; // fp12
  double v12; // fp11
  double v13; // fp10
  double v14; // fp9
  float *v15; // r11
  contactsResult_t *contactsResult; // r11
  float *v17; // r11
  int v18; // r29
  int subModelNum; // r8
  int v20; // r4

  c = polygonPlane->c;
  v5 = &tw->vertexPosition[trmVertNum];
  v6 = (float)((float)((float)(v5->z * polygonPlane->c)
                     + (float)((float)(v5->y * polygonPlane->b) + (float)(v5->x * polygonPlane->a)))
             + polygonPlane->d);
  if ( v6 <= tw->contactDepth && v6 >= 0.0 )
  {
    v7 = -polygonPlane->a;
    v8 = 0;
    v9 = -polygonPlane->b;
    v12 = (float)((float)(v5->x * (float)v9) - (float)(v5->y * (float)v7));
    v13 = (float)((float)(v5->x * (float)-c) - (float)(v5->z * (float)v7));
    v10 = -v7;
    v14 = (float)((float)(v5->y * (float)-c) - (float)(v5->z * (float)v9));
    v11 = --c;
    if ( poly->numEdges != 0 )
    {
      v15 = &tw->polygonEdgePlueckerCache[0].p[2];
      while ( ((tw->subModelPtrs.polygonEdges[poly->firstEdge + v8]
              ^ HIWORD(
                  COERCE_UNSIGNED_INT(
                    (float)(v15[3] * (float)v13)
                  + (float)((float)(v15[1] * (float)v10)
                          + (float)((float)(*(v15 - 2) * (float)v11)
                                  + (float)((float)((float)v14 * *v15)
                                          + (float)((float)(*(v15 - 1) * (float)v9) + (float)(v15[2] * (float)v12))))))))
             & 0x8000) == 0 )
      {
        ++v8;
        v15 += 6;
        if ( v8 >= poly->numEdges )
          goto LABEL_7;
      }
    }
    else
    {
LABEL_7:
      contactsResult = tw->contactsResult;
      if ( contactsResult->numContacts < 12 )
      {
        v18 = contactsResult->numContacts + 1;
        v17 = (float *)(&contactsResult->numContacts + 19 * contactsResult->numContacts);
        tw->contactsResult->numContacts = v18;
        v17[8] = polygonPlane->a;
        v17[9] = polygonPlane->b;
        v17[10] = polygonPlane->c;
        v17[11] = -polygonPlane->d;
        v17[12] = v6;
        v17[13] = *(float *)((char *)&tw->subModelPtrs.materials->contentFlags + __ROL4__(poly->material, 4));
        v17[14] = *(float *)((char *)&tw->subModelPtrs.materials->surfaceFlags + __ROL4__(poly->material, 4));
        v17[15] = *(float *)((char *)&tw->subModelPtrs.materials->surfaceType + __ROL4__(poly->material, 4));
        *((_BYTE *)v17 + 89) = tw->subModelPtrs.materials->surfaceColor[__ROL4__(poly->material, 4)];
        *((_BYTE *)v17 + 90) = tw->subModelPtrs.materials->surfaceColor[__ROL4__(poly->material, 4) + 1];
        *((_BYTE *)v17 + 91) = tw->subModelPtrs.materials->surfaceColor[__ROL4__(poly->material, 4) + 2];
        *((_DWORD *)v17 + 4) = 3;
        subModelNum = tw->subModelNum;
        v20 = poly - tw->subModelPtrs.polygons;
        *((_DWORD *)v17 + 17) = trmVertNum;
        *((_DWORD *)v17 + 16) = (unsigned __int16)v20 | (subModelNum << 16) & 0x1FFF0000 | 0x60000000;
        v17[5] = v5->x;
        v17[6] = v5->y;
        v17[7] = v5->z;
        *((_BYTE *)v17 + 88) = 0;
      }
    }
  }
}


// ========================================================================
// ?TestVertexInContactWithTrmPolygon@idPolygonModelCollisionDetection@@CAXPAVidTraceWork@@PBUcm_trmPolygon_t@@PBUcm_polygon_t@@PBUcm_vertex_t@@@Z
// EA  : 0x825E8E08
// RVA : 0x005E8E08
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_contacts.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TestVertexInContactWithTrmPolygon(
        idTraceWork *tw,
        const cm_trmPolygon_t *trmpoly,
        const cm_polygon_t *poly,
        const cm_vertex_t *v)
{
  double c; // fp12
  double v5; // fp11
  double v6; // fp13
  double v7; // fp0
  unsigned int numEdges; // r7
  int v9; // r9
  double v10; // fp13
  double v11; // fp12
  double v12; // fp11
  double v13; // fp10
  double v14; // fp9
  unsigned __int8 *edges; // r8
  idPluecker *v16; // r11
  contactsResult_t *contactsResult; // r11
  int v18; // r10
  double v19; // fp11
  char *v20; // r11
  double v21; // fp10
  double v22; // fp9
  int v23; // r4
  int v24; // r3

  c = trmpoly->plane.c;
  v5 = (float)((float)((float)(trmpoly->plane.b * v->p.y)
                     + (float)((float)(trmpoly->plane.c * v->p.z) + (float)(trmpoly->plane.a * v->p.x)))
             + trmpoly->plane.d);
  if ( v5 <= tw->contactDepth && v5 >= 0.0 )
  {
    v6 = -trmpoly->plane.a;
    v7 = -trmpoly->plane.b;
    numEdges = trmpoly->numEdges;
    v9 = 0;
    v12 = (float)((float)(v->p.x * (float)v7) - (float)(v->p.y * (float)v6));
    v13 = (float)((float)(v->p.x * (float)-c) - (float)(v->p.z * (float)v6));
    v10 = -v6;
    v14 = (float)((float)(v->p.y * (float)-c) - (float)(v->p.z * (float)v7));
    v11 = --c;
    if ( numEdges != 0 )
    {
      edges = trmpoly->edges;
      while ( 1 )
      {
        v16 = &tw->edgePluecker[edges[v9] & 0x7F];
        if ( ((HIBYTE(
                 COERCE_UNSIGNED_INT(
                   (float)((float)v11 * v16->p[0])
                 + (float)((float)(v16->p[4] * (float)v12)
                         + (float)((float)(v16->p[1] * (float)v7)
                                 + (float)((float)(v16->p[5] * (float)v13)
                                         + (float)((float)(v16->p[2] * (float)v14) + (float)(v16->p[3] * (float)v10)))))))
             ^ edges[v9])
            & 0x80) != 0 )
          break;
        if ( ++v9 >= numEdges )
          goto LABEL_7;
      }
    }
    else
    {
LABEL_7:
      contactsResult = tw->contactsResult;
      if ( contactsResult->numContacts < 12 )
      {
        v18 = 76 * contactsResult->numContacts++;
        v19 = -trmpoly->plane.c;
        v20 = (char *)contactsResult + v18;
        v21 = -trmpoly->plane.b;
        v22 = -trmpoly->plane.a;
        *((float *)v20 + 8) = v22;
        *((float *)v20 + 9) = v21;
        *((float *)v20 + 10) = v19;
        *((float *)v20 + 11) = (float)((float)v22 * v->p.x)
                             + (float)((float)(v->p.z * (float)v19) + (float)((float)v21 * v->p.y));
        *((float *)v20 + 12) = (float)((float)(v->p.z * trmpoly->plane.c)
                                     + (float)((float)(trmpoly->plane.b * v->p.y) + (float)(trmpoly->plane.a * v->p.x)))
                             + trmpoly->plane.d;
        *((_DWORD *)v20 + 13) = *(int *)((char *)&tw->subModelPtrs.materials->contentFlags + __ROL4__(poly->material, 4));
        *((_DWORD *)v20 + 14) = *(int *)((char *)&tw->subModelPtrs.materials->surfaceFlags + __ROL4__(poly->material, 4));
        *((_DWORD *)v20 + 15) = *(int *)((char *)&tw->subModelPtrs.materials->surfaceType + __ROL4__(poly->material, 4));
        v20[89] = tw->subModelPtrs.materials->surfaceColor[__ROL4__(poly->material, 4)];
        v20[90] = tw->subModelPtrs.materials->surfaceColor[__ROL4__(poly->material, 4) + 1];
        LOBYTE(v18) = tw->subModelPtrs.materials->surfaceColor[__ROL4__(poly->material, 4) + 2];
        *((_DWORD *)v20 + 4) = 2;
        v20[91] = v18;
        v23 = ((char *)trmpoly - (char *)tw - 1024) >> 6;
        v24 = (unsigned __int16)(v - tw->subModelPtrs.vertices) | (tw->subModelNum << 16) & 0x1FFF0000 | 0x20000000;
        *((_DWORD *)v20 + 17) = v23;
        *((_DWORD *)v20 + 16) = v24;
        v20[88] = 0;
        *(idVec3 *)(v20 + 20) = v->p;
      }
    }
  }
}


// ========================================================================
// ?TestTrmInContactWithPolygon@idPolygonModelCollisionDetection@@CA_NPAVidTraceWork@@I@Z
// EA  : 0x825E90B0
// RVA : 0x005E90B0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_contacts.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::TestTrmInContactWithPolygon(idTraceWork *tw, int polygonNum)
{
  int v4; // r5
  idModelCheckCounts *p_modelCheckCounts; // r26
  int v6; // r3
  unsigned __int8 *polygonCheckCounts; // r10
  unsigned __int8 v12; // cr58
  unsigned __int8 v13; // cr59
  int v14; // r3
  unsigned int v16; // r8
  float *p_side; // r9
  unsigned int v18; // r6
  cm_vertex_t *vertices; // r10
  cm_edge_t *v20; // r11
  int v21; // r6
  float *v22; // r11
  float *v23; // r10
  unsigned int i; // r6
  int v25; // r6
  unsigned int j; // r30
  unsigned int k; // r22
  unsigned __int8 *edgeCheckCounts; // r10
  unsigned __int16 v29; // r5
  int v30; // r11
  char v31; // r6
  int v32; // r3
  int v33; // r27
  int v34; // r25
  int v35; // r24
  unsigned __int8 *vertexCheckCounts; // r9
  int v37; // r10
  int v38; // r4
  int v39; // r3
  const cm_vertex_t *v40; // r6
  double x; // fp12
  double y; // fp13
  double z; // fp0
  char v44; // r11
  unsigned int v45; // r29
  const cm_trmPolygon_t *polys; // r30
  idPlane v47[8]; // [sp+50h] [-80h] BYREF

  _R31 = tw;
  v4 = (unsigned __int8)(1 << (polygonNum & 7));
  p_modelCheckCounts = &tw->modelCheckCounts;
  polygonCheckCounts = tw->modelCheckCounts.polygonCheckCounts;
  v6 = polygonCheckCounts[polygonNum >> 3];
  polygonCheckCounts[polygonNum >> 3] = v6 | v4;
  if ( (v6 & v4) == 0 )
  {
    _R28 = &_R31->subModelPtrs.polygons[polygonNum];
    if ( (*(int *)((_BYTE *)&_R31->subModelPtrs.materials->contentFlags + __ROL4__(_R28->material, 4)) & _R31->contents) != 0 )
    {
      __asm { lvx128    v63, r0, r28 }
      _R10 = 6176;
      _R9 = vmxi_half_bnds_intersect_perm2_2;
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
      if ( ((32 * v12) & 0x20 | (16 * v13) & 0x20) != 0 )
      {
        CM_GetPolygonPlane(subModel: &_R31->subModelPtrs, polygon: _R28, plane: v47);
        v14 = CM_BoundsPlaneSide(boundsMin: &_R31->traceBoundsMin, boundsMax: &_R31->traceBoundsMax, plane: v47);
        if ( v14 == 3 )
        {
          v16 = 0;
          if ( _R28->numEdges != 0 )
          {
            p_side = (float *)&_R31->polygonVertexSideCache[19].side;
            do
            {
              v18 = _R28->firstEdge + v16;
              vertices = _R31->subModelPtrs.vertices;
              ++v16;
              v20 = &_R31->subModelPtrs.edges[_R31->subModelPtrs.polygonEdges[v18] & 0x3FFF];
              v21 = v20->vertexNum[0];
              v22 = (float *)((char *)&vertices->p.x + __ROL4__(v20->vertexNum[1], 4));
              v23 = (float *)((char *)&vertices->p.x + __ROL4__(v21, 4));
              p_side[1] = (float)(*v23 * v22[1]) - (float)(*v22 * v23[1]);
              p_side[2] = (float)(v22[2] * *v23) - (float)(*v22 * v23[2]);
              p_side[3] = *v23 - *v22;
              p_side[4] = (float)(v22[2] * v23[1]) - (float)(v23[2] * v22[1]);
              p_side[5] = v23[2] - v22[2];
              p_side += 6;
              *p_side = v22[1] - v23[1];
            }
            while ( v16 < _R28->numEdges );
          }
          for ( i = 0; i < _R31->numVerts; i = v25 + 1 )
            idPolygonModelCollisionDetection::TestTrmVertexInContactWithPolygon(
              tw: _R31,
              poly: _R28,
              polygonPlane: v47,
              trmVertNum: i);
          for ( j = 0; j < _R31->numEdges; ++j )
            idPolygonModelCollisionDetection::TestTrmEdgeInContactWithPolygon(tw: _R31, poly: _R28, trmEdgeNum: j);
          for ( k = 0; k < _R28->numEdges; ++k )
          {
            edgeCheckCounts = p_modelCheckCounts->edgeCheckCounts;
            v29 = _R31->subModelPtrs.polygonEdges[_R28->firstEdge + k];
            v30 = (v29 & 0x3FFF) >> 3;
            v31 = 1 << (v29 & 7);
            v32 = (unsigned __int8)(edgeCheckCounts[v30] & v31);
            edgeCheckCounts[v30] |= v31;
            if ( v32 == 0 && (v29 & 0x4000) == 0 )
            {
              v33 = 0;
              v34 = (int)&_R31->subModelPtrs.edges[v29 & 0x3FFF];
              v35 = v29 >> 15;
              do
              {
                vertexCheckCounts = p_modelCheckCounts->vertexCheckCounts;
                v37 = *(unsigned __int16 *)(2 * (v35 ^ v33) + v34);
                v38 = vertexCheckCounts[v37 >> 3];
                v39 = (unsigned __int8)(1 << (v37 & 7));
                vertexCheckCounts[v37 >> 3] |= v39;
                if ( (v38 & v39) == 0 )
                {
                  v40 = &_R31->subModelPtrs.vertices[v37];
                  x = v40->p.x;
                  if ( _R31->traceBoundsMin.x > x
                    || (y = v40->p.y, _R31->traceBoundsMin.y > y)
                    || (z = v40->p.z, _R31->traceBoundsMin.z > z)
                    || x > _R31->traceBoundsMax.x
                    || y > _R31->traceBoundsMax.y
                    || (v44 = 1, z > _R31->traceBoundsMax.z) )
                  {
                    v44 = 0;
                  }
                  if ( v44 != 0 )
                  {
                    v45 = 0;
                    if ( _R31->numPolys != 0 )
                    {
                      polys = _R31->polys;
                      do
                      {
                        idPolygonModelCollisionDetection::TestVertexInContactWithTrmPolygon(
                          tw: _R31,
                          trmpoly: polys,
                          poly: _R28,
                          v: v40);
                        ++v45;
                        ++polys;
                      }
                      while ( v45 < _R31->numPolys );
                    }
                  }
                }
                ++v33;
              }
              while ( v33 < 2 );
            }
          }
        }
        else if ( v14 == 0 && _R31->subModelPtrs.isConvex != 0 )
        {
          _R31->quickExit = true;
          return 1;
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// ?StartContacts@idPolygonModelCollisionDetection@@SAXPAVidTraceWork@@PAUcontactsResult_t@@ABVidVec3@@2MPBVidTraceModel@@ABVidMat3@@H24@Z
// EA  : 0x825E94C0
// RVA : 0x005E94C0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_contacts.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::StartContacts(
        idTraceWork *tw,
        contactsResult_t *result,
        const idVec3 *start,
        const idVec3 *dir,
        double depth,
        const idTraceModel *trm,
        const idTraceModel *trmAxis,
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
        int a28,
        float *a29,
        int a30,
        int a31)
{
  double v34; // fp10
  double v35; // fp9
  double y; // fp7
  double z; // fp6
  double v42; // fp29
  double v43; // fp28
  double v44; // fp4
  double v45; // fp3
  double v46; // fp2
  double x; // fp7
  double v48; // fp5
  double v49; // fp1
  double v50; // fp0
  double v51; // fp3
  double v52; // fp4
  double v53; // fp6
  double v54; // fp8
  double v55; // fp9
  double v56; // fp10
  double v57; // fp11
  double v58; // fp13
  double v59; // fp2
  double v60; // fp0
  double v61; // fp7
  char v62; // r11
  double v63; // fp11
  double v64; // fp13
  double v65; // fp9
  double v66; // fp8
  float v67; // r11
  unsigned int v68; // r9
  float *vertsZ; // r10
  float *p_z; // r11
  double v71; // fp0
  double v72; // fp12
  double v73; // fp0
  unsigned int v74; // r6
  double v75; // fp12
  double w; // fp3
  double v77; // fp12
  double v78; // fp3
  float v79; // r11
  char *v80; // r8
  float *v81; // r7
  float *v82; // r9
  int v83; // r5
  unsigned __int16 v84; // r4
  float *p_x; // r11
  float *v86; // r10
  double v87; // fp3
  double v88; // fp2
  double v89; // fp1
  double v90; // fp12
  double v91; // fp0
  float v92; // r11
  unsigned int v93; // r5
  char *v94; // r9
  const idTraceModel *polyEdges; // r7
  float *p_b; // r11
  int v97; // r8
  unsigned int v98; // r10
  float *v99; // r8
  char v100; // r4
  double v101; // fp12
  double v102; // fp3
  double v103; // fp1
  double v104; // fp0
  double v105; // fp2
  double v106; // fp1
  double v107; // fp0
  float *v108; // r10
  const idVec3 *v119; // [sp+8h] [-108h]
  const idMat3 *v120; // [sp+Ch] [-104h]
  idVec3 v121; // [sp+60h] [-B0h] BYREF
  idMat3x4 v122; // [sp+70h] [-A0h] BYREF

  _R31 = tw;
  if ( ((LODWORD(dir->x) | LODWORD(dir->y) | LODWORD(dir->z)) & 0x7FFFFFFF) != 0 )
  {
    v34 = (float)(dir->y * (float)depth);
    v35 = (float)((float)depth * dir->z);
    y = start->y;
    z = start->z;
    v121.x = (float)(dir->x * (float)depth) + start->x;
    v121.y = (float)y + (float)v34;
    v121.z = (float)z + (float)v35;
    idPolygonModelCollisionDetection::StartTranslation(
      tw,
      result: &tw->tempTraceResult,
      contacts: result,
      start,
      end: &v121,
      trm: trmAxis,
      trmAxis: (const idMat3 *)contentMask,
      contentMask: (int)modelOrigin,
      modelOrigin: v119,
      modelAxis: v120);
  }
  else
  {
    tw->contents = (int)modelOrigin;
    tw->contactDepth = depth;
    tw->contactsResult = result;
    tw->quickExit = false;
    tw->traceType = TRACE_CONTACTS_OMNI_DIR;
    tw->isConvex = true;
    tw->fraction = 1.0;
    tw->traceResult = nullptr;
    tw->clipResult = nullptr;
    _R25 = &tw->contactDepth;
    _R29 = &tw->start;
    _R28 = &tw->trmBoundsMin;
    _R27 = &tw->trmBoundsMax;
    v42 = a29[1];
    v43 = a29[2];
    v44 = (float)((float)((float)(*(float *)(contentMask + 4) * trmAxis->offset.x)
                        + (float)((float)(trmAxis->offset.y * *(float *)(contentMask + 16))
                                + (float)(trmAxis->offset.z * *(float *)(contentMask + 28))))
                + start->y);
    v45 = (float)((float)((float)(trmAxis->offset.x * *(float *)(contentMask + 8))
                        + (float)((float)(*(float *)(contentMask + 20) * trmAxis->offset.y)
                                + (float)(*(float *)(contentMask + 32) * trmAxis->offset.z)))
                + start->z);
    v46 = (float)((float)((float)((float)(*(float *)contentMask * trmAxis->offset.x)
                                + (float)((float)(trmAxis->offset.z * *(float *)(contentMask + 24))
                                        + (float)(trmAxis->offset.y * *(float *)(contentMask + 12))))
                        + start->x)
                - *a29);
    tw->start.x = (float)((float)((float)(*(float *)contentMask * trmAxis->offset.x)
                                + (float)((float)(trmAxis->offset.z * *(float *)(contentMask + 24))
                                        + (float)(trmAxis->offset.y * *(float *)(contentMask + 12))))
                        + start->x)
                - *a29;
    tw->start.y = (float)v44 - (float)v42;
    tw->start.z = (float)v45 - (float)v43;
    tw->end.x = v46;
    tw->end.y = tw->start.y;
    tw->end.z = tw->start.z;
    tw->dir.w = 0.0;
    tw->dir.z = 0.0;
    tw->dir.y = 0.0;
    tw->dir.x = 0.0;
    tw->isConvex = trmAxis->isConvex;
    tw->trmBoundsMin.x = 1.0e30;
    tw->trmBoundsMin.y = 1.0e30;
    tw->trmBoundsMin.w = 0.0;
    tw->trmBoundsMin.z = 1.0e30;
    tw->trmBoundsMax.x = -1.0e30;
    tw->trmBoundsMax.w = 0.0;
    tw->trmBoundsMax.z = -1.0e30;
    tw->trmBoundsMax.y = -1.0e30;
    x = start->x;
    v48 = *(float *)(contentMask + 12);
    v49 = (float)(start->y - a29[1]);
    v50 = *a29;
    v51 = (float)(start->z - a29[2]);
    v52 = *(float *)contentMask;
    v53 = *(float *)(contentMask + 24);
    v54 = *(float *)(contentMask + 16);
    v55 = *(float *)(contentMask + 28);
    v56 = *(float *)(contentMask + 8);
    v57 = *(float *)(contentMask + 20);
    v58 = *(float *)(contentMask + 32);
    v122.mat[1] = *(float *)(contentMask + 12);
    v122.mat[0] = v52;
    v122.mat[2] = v53;
    v59 = (float)((float)x - (float)v50);
    v60 = *(float *)a31;
    v61 = *(float *)(contentMask + 4);
    v122.mat[4] = *(float *)(contentMask + 4);
    v122.mat[5] = v54;
    v122.mat[6] = v55;
    v122.mat[8] = v56;
    v122.mat[9] = v57;
    v122.mat[10] = v58;
    v122.mat[11] = v51;
    v122.mat[7] = v49;
    v122.mat[3] = v59;
    if ( v60 != 1.0 || *(float *)(a31 + 16) != 1.0 || (v62 = 0, *(float *)(a31 + 32) != 1.0) )
      v62 = 1;
    if ( v62 != 0 )
    {
      v63 = _R29->x;
      v64 = *(float *)(a31 + 24);
      v65 = (float)((float)(*(float *)(a31 + 4) * tw->start.y) + (float)(*(float *)(a31 + 8) * tw->start.z));
      v66 = (float)((float)(*(float *)(a31 + 28) * tw->start.y) + (float)(*(float *)(a31 + 32) * tw->start.z));
      tw->start.y = (float)(*(float *)(a31 + 12) * tw->start.x)
                  + (float)((float)(*(float *)(a31 + 16) * tw->start.y) + (float)(*(float *)(a31 + 20) * tw->start.z));
      _R29->x = (float)((float)v60 * (float)v63) + (float)v65;
      tw->start.z = (float)((float)v64 * (float)v63) + (float)v66;
      tw->end.x = (float)((float)v60 * (float)v63) + (float)v65;
      tw->end.y = tw->start.y;
      tw->end.z = tw->start.z;
      idMat3x4::LeftTransposeMultiply(this: &v122, m: (const idMat3 *)a31);
      v51 = v122.mat[11];
      v58 = v122.mat[10];
      v57 = v122.mat[9];
      v56 = v122.mat[8];
      v49 = v122.mat[7];
      v55 = v122.mat[6];
      v54 = v122.mat[5];
      v61 = v122.mat[4];
      v59 = v122.mat[3];
      v53 = v122.mat[2];
      v48 = v122.mat[1];
      v52 = v122.mat[0];
    }
    v67 = *(float *)&trmAxis->numVerts;
    v68 = 0;
    *(float *)&_R31->numVerts = v67;
    if ( v67 != 0.0 )
    {
      vertsZ = trmAxis->vertsZ;
      p_z = &_R31->vertexPosition[0].z;
      do
      {
        v71 = (float)((float)(*(vertsZ - 32) * (float)v48)
                    + (float)((float)(*(vertsZ - 64) * (float)v52) + (float)(*vertsZ * (float)v53)));
        v72 = (float)((float)((float)v61 * *(vertsZ - 64))
                    + (float)((float)(*vertsZ * (float)v55) + (float)(*(vertsZ - 32) * (float)v54)));
        *p_z = (float)((float)((float)v56 * *(vertsZ - 64))
                     + (float)((float)(*vertsZ * (float)v58) + (float)(*(vertsZ - 32) * (float)v57)))
             + (float)v51;
        v73 = (float)((float)v71 + (float)v59);
        *(p_z - 2) = v73;
        *(p_z - 1) = (float)v72 + (float)v49;
        if ( v73 < _R28->x )
          _R28->x = v73;
        if ( *(p_z - 1) < (double)_R31->trmBoundsMin.y )
          _R31->trmBoundsMin.y = *(p_z - 1);
        if ( *p_z < (double)_R31->trmBoundsMin.z )
          _R31->trmBoundsMin.z = *p_z;
        if ( *(p_z - 2) > (double)_R27->x )
          _R27->x = *(p_z - 2);
        if ( *(p_z - 1) > (double)_R31->trmBoundsMax.y )
          _R31->trmBoundsMax.y = *(p_z - 1);
        if ( *p_z > (double)_R31->trmBoundsMax.z )
          _R31->trmBoundsMax.z = *p_z;
        ++v68;
        p_z += 4;
        ++vertsZ;
      }
      while ( v68 < _R31->numVerts );
    }
    v74 = 0;
    _R28->x = _R28->x - _R29->x;
    v75 = _R31->trmBoundsMin.z;
    w = _R31->trmBoundsMin.w;
    _R31->trmBoundsMin.y = _R31->trmBoundsMin.y - _R31->start.y;
    _R31->trmBoundsMin.z = (float)v75 - _R31->start.z;
    _R31->trmBoundsMin.w = (float)w - _R31->start.w;
    _R27->x = _R27->x - _R29->x;
    v77 = _R31->trmBoundsMax.z;
    v78 = _R31->trmBoundsMax.w;
    _R31->trmBoundsMax.y = _R31->trmBoundsMax.y - _R31->start.y;
    _R31->trmBoundsMax.z = (float)v77 - _R31->start.z;
    _R31->trmBoundsMax.w = (float)v78 - _R31->start.w;
    v79 = *(float *)&trmAxis->numEdges;
    *(float *)&_R31->numEdges = v79;
    if ( v79 != 0.0 )
    {
      v80 = (char *)&trmAxis->edgeNormalY[31];
      v81 = &_R31->edgeZAxisPluecker[31].p[4];
      v82 = &_R31->vertexPluecker[31].p[5];
      do
      {
        v83 = *((unsigned __int16 *)v80 + 354);
        ++v74;
        v84 = *((_WORD *)v80 + 355);
        *((_WORD *)v81 - 2422) = v83;
        *((_WORD *)v81 - 2421) = v84;
        p_x = &_R31->vertexPosition[v83].x;
        v86 = &_R31->vertexPosition[v84].x;
        v82[1] = (float)(*p_x * v86[1]) - (float)(*v86 * p_x[1]);
        v82[2] = (float)(*p_x * v86[2]) - (float)(p_x[2] * *v86);
        v82[3] = *p_x - *v86;
        v82[4] = (float)(v86[2] * p_x[1]) - (float)(p_x[2] * v86[1]);
        v82[5] = p_x[2] - v86[2];
        v82 += 6;
        *v82 = v86[1] - p_x[1];
        v87 = *((float *)v80 - 63);
        v88 = *((float *)v80 - 31);
        v89 = (float)(*((float *)v80 - 31) * (float)v54);
        v80 += 4;
        v90 = (float)((float)((float)v87 * (float)v52) + (float)(*(float *)v80 * (float)v53));
        v91 = (float)((float)(*(float *)v80 * (float)v58) + (float)((float)v88 * (float)v57));
        v81[3] = (float)((float)v61 * (float)v87) + (float)((float)(*(float *)v80 * (float)v55) + (float)v89);
        v81[2] = (float)((float)v88 * (float)v48) + (float)v90;
        v81 += 4;
        *v81 = (float)((float)v56 * (float)v87) + (float)v91;
      }
      while ( v74 < _R31->numEdges );
    }
    v92 = *(float *)&trmAxis->numPolys;
    v93 = 0;
    *(float *)&_R31->numPolys = v92;
    if ( v92 != 0.0 )
    {
      v94 = (char *)&trmAxis->polyPlaneY[15];
      polyEdges = (const idTraceModel *)trmAxis->polyEdges;
      p_b = &_R31->polys[0].plane.b;
      do
      {
        v97 = *((_DWORD *)v94 + 97);
        v98 = 0;
        *((_DWORD *)p_b + 6) = v97;
        if ( v97 != 0 )
        {
          v99 = p_b - 257;
          do
          {
            v100 = *((_BYTE *)polyEdges->vertsX + v98++);
            *((_BYTE *)v99 + 1056) = v100;
            v99 = (float *)((char *)p_b + v98 - 1028);
          }
          while ( v98 < *((_DWORD *)p_b + 6) );
        }
        v101 = *((float *)v94 - 31);
        ++v93;
        v102 = *((float *)v94 - 15);
        polyEdges = (const idTraceModel *)((char *)polyEdges + 16);
        v94 += 4;
        v103 = (float)((float)((float)v101 * (float)v52) + (float)(*(float *)v94 * (float)v53));
        v104 = (float)((float)(*(float *)v94 * (float)v55) + (float)((float)v102 * (float)v54));
        v105 = (float)((float)((float)v56 * (float)v101)
                     + (float)((float)(*(float *)v94 * (float)v58) + (float)((float)v102 * (float)v57)));
        p_b[1] = (float)((float)v56 * (float)v101)
               + (float)((float)(*(float *)v94 * (float)v58) + (float)((float)v102 * (float)v57));
        v106 = (float)((float)((float)v102 * (float)v48) + (float)v103);
        *(p_b - 1) = v106;
        v107 = (float)((float)((float)v61 * (float)v101) + (float)v104);
        *p_b = v107;
        v108 = &_R31->vertexPosition[_R31->edges[(_BYTE)p_b[7] & 0x7F].vertexNum[0]].x;
        p_b[2] = -(float)((float)((float)v106 * *v108)
                        + (float)((float)(v108[2] * (float)v105) + (float)(v108[1] * (float)v107)));
        p_b += 16;
      }
      while ( v93 < _R31->numPolys );
    }
    __asm { lvlx128   v63, r0, r25 }
    _R10 = -48;
    __asm { lvx128    v62, r0, r29 }
    _R9 = vmxi_float_abs_mask_2;
    __asm
    {
      vspltw128 v61, v63, 0
      lvx128    v60, r0, r28
    }
    _R8 = 16;
    __asm
    {
      lvx128    v59, r0, r27
      vaddfp128 v58, v94, v60
      vaddfp128 v57, v94, v59
    }
    _R7 = -32;
    _R6 = 6144;
    __asm { lvx128    v63, r9, r10 }
    _R5 = 6160;
    __asm
    {
      vaddfp128 v56, v93, v63
      lvx128    v61, r9, r8
    }
    _R4 = 32;
    __asm { lvx128    v62, r9, r7 }
    _R3 = 48;
    _R11 = 6176;
    _R10 = 6128;
    __asm
    {
      vand128   v55, v88, v61
      vsubfp128 v54, v90, v55
      vaddfp128 v53, v89, v55
      vaddfp128 v52, v86, v62
      stvx128   v54, r31, r6
      vsubfp128 v51, v85, v62
      stvx128   v53, r31, r5
      vcfpsxws128 v13, v52, 0
      vcfpsxws128 v12, v51, 0
      lvx128    v0, r9, r4
      lvx128    v7, r9, r3
      vsubsws   v11, v13, v0
      vaddsws   v10, v12, v0
      vpkswss128 v62, v11, v10
      vperm128  v50, v94, v62, v7
      stvx128   v50, r31, r11
      lvx128    v62, r0, r9
      vand128   v49, v91, v62
      vand128   v48, v92, v62
      vmaxfp128 v47, v80, v49
      vaddfp128 v46, v79, v63
      stvx128   v46, r31, r10
    }
  }
}


// ========================================================================
// ?FinishContacts@idPolygonModelCollisionDetection@@SAXPAVidTraceWork@@HABVidVec3@@ABVidMat3@@HHHHH@Z
// EA  : 0x825E9C60
// RVA : 0x005E9C60
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_contacts.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::FinishContacts(
        idTraceWork *tw,
        int firstContact,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis,
        int modelEntityNum,
        int modelPhysicsId,
        int modelBodyId,
        int selfId,
        int modelContentsOverride,
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
        int a28)
{
  char v28; // r11
  contactsResult_t *contactsResult; // r27
  int v30; // r30
  int v31; // r31
  float *v32; // r11
  double x; // fp5
  double y; // fp7
  double v35; // fp1
  double z; // fp0
  double v37; // fp12
  double v38; // fp11
  double v39; // fp1
  double v40; // fp2
  double v41; // fp0
  double v42; // fp12
  double v43; // fp5
  double v44; // fp4
  int v45; // r31
  int v46; // r6
  float *v47; // r11
  int v48; // r11

  if ( modelAxis->mat[0].x != 1.0 || modelAxis->mat[1].y != 1.0 || (v28 = 0, modelAxis->mat[2].z != 1.0) )
    v28 = 1;
  if ( v28 != 0 )
  {
    contactsResult = tw->contactsResult;
    v30 = firstContact;
    if ( firstContact < contactsResult->numContacts )
    {
      v31 = firstContact;
      do
      {
        v32 = (float *)((char *)&contactsResult->numContacts + v31 * 76);
        ++v30;
        x = contactsResult->contacts[v31].point.x;
        y = contactsResult->contacts[v31].point.y;
        v35 = modelAxis->mat[1].y;
        z = modelAxis->mat[0].z;
        v37 = (float)((float)(contactsResult->contacts[v31].point.x * modelAxis->mat[0].y)
                    + (float)(contactsResult->contacts[v31].point.z * modelAxis->mat[2].y));
        v38 = (float)((float)(contactsResult->contacts[v31].point.y * modelAxis->mat[1].z)
                    + (float)(contactsResult->contacts[v31].point.z * modelAxis->mat[2].z));
        v32[5] = (float)(modelAxis->mat[1].x * contactsResult->contacts[v31].point.y)
               + (float)((float)(modelAxis->mat[0].x * contactsResult->contacts[v31].point.x)
                       + (float)(modelAxis->mat[2].x * contactsResult->contacts[v31].point.z));
        v32[6] = (float)((float)y * (float)v35) + (float)v37;
        v32[7] = (float)((float)z * (float)x) + (float)v38;
        v39 = contactsResult->contacts[v31].normal.x;
        v40 = contactsResult->contacts[v31].normal.y;
        v41 = modelAxis->mat[1].x;
        v42 = modelAxis->mat[0].z;
        v43 = (float)((float)(modelAxis->mat[0].x * contactsResult->contacts[v31].normal.x)
                    + (float)(modelAxis->mat[2].x * contactsResult->contacts[v31].normal.z));
        v44 = (float)((float)(contactsResult->contacts[v31].normal.y * modelAxis->mat[1].z)
                    + (float)(contactsResult->contacts[v31].normal.z * modelAxis->mat[2].z));
        v32[9] = (float)(contactsResult->contacts[v31].normal.y * modelAxis->mat[1].y)
               + (float)((float)(contactsResult->contacts[v31].normal.x * modelAxis->mat[0].y)
                       + (float)(contactsResult->contacts[v31].normal.z * modelAxis->mat[2].y));
        ++v31;
        v32[8] = (float)((float)v41 * (float)v40) + (float)v43;
        v32[10] = (float)((float)v42 * (float)v39) + (float)v44;
      }
      while ( v30 < contactsResult->numContacts );
    }
  }
  if ( ((LODWORD(modelOrigin->x) | LODWORD(modelOrigin->y) | LODWORD(modelOrigin->z)) & 0x7FFFFFFF) != 0 )
  {
    v45 = firstContact;
    if ( firstContact < tw->contactsResult->numContacts )
    {
      v46 = 76 * firstContact;
      do
      {
        ++v45;
        v47 = (float *)((char *)&tw->contactsResult->numContacts + v46);
        v46 += 76;
        v47[5] = modelOrigin->x + v47[5];
        v47[6] = v47[6] + modelOrigin->y;
        v47[7] = modelOrigin->z + v47[7];
        v47[11] = (float)((float)(modelOrigin->x * v47[8])
                        + (float)((float)(v47[10] * modelOrigin->z) + (float)(v47[9] * modelOrigin->y)))
                + v47[11];
      }
      while ( v45 < tw->contactsResult->numContacts );
    }
  }
  if ( firstContact < tw->contactsResult->numContacts )
  {
    v48 = firstContact;
    do
    {
      tw->contactsResult->contacts[v48].entityNum = modelEntityNum;
      tw->contactsResult->contacts[v48].physicsId = modelPhysicsId;
      tw->contactsResult->contacts[v48].bodyId = modelBodyId;
      tw->contactsResult->contacts[v48].selfId = selfId;
      if ( a28 != 0 )
        tw->contactsResult->contacts[v48].contentFlags = a28;
      ++firstContact;
      ++v48;
    }
    while ( firstContact < tw->contactsResult->numContacts );
  }
  tw->contactsResult = nullptr;
}

