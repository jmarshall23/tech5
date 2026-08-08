
// ========================================================================
// ?CM_GetPolygonPlane@@YAXABUcm_subModelPtrs_t@@ABUcm_polygon_t@@AAVidPlane@@@Z
// EA  : 0x825BD948
// RVA : 0x005BD948
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodeldata.h
// ========================================================================

void __fastcall CM_GetPolygonPlane(const cm_subModelPtrs_t *subModel, const cm_polygon_t *polygon, idPlane *plane)
{
  cm_vertex_t *vertices; // r9
  cm_edge_t *edges; // r10
  unsigned __int16 *v5; // r11
  unsigned int v6; // r7
  unsigned int v7; // r4
  char *v8; // r11
  int v9; // r8
  int v10; // r7
  float *v11; // r11
  float *v12; // r10
  float *v13; // r9
  double v14; // fp8
  double v15; // fp7
  double v16; // fp10
  double v17; // fp1
  double v18; // fp5
  double v19; // fp6
  double v20; // fp4
  double v21; // fp2
  double v22; // fp3
  double v25; // fp6
  double v26; // fp9
  double v27; // fp6
  double v28; // fp4
  double v29; // fp3

  vertices = subModel->vertices;
  edges = subModel->edges;
  v5 = (unsigned __int16 *)((char *)subModel->polygonEdges + __ROL4__(polygon->firstEdge, 1));
  v6 = *v5;
  v7 = v5[1];
  v8 = (char *)edges + ((4 * v7) & 0xFFFC);
  v9 = ((2 * v6) & 0x7FFE) + (v6 >> 15);
  v10 = *(unsigned __int16 *)&v8[(~v7 >> 14) & 2];
  v11 = (float *)((char *)&vertices->p.x + __ROL4__(*(unsigned __int16 *)&v8[(v7 >> 14) & 2], 4));
  v12 = (float *)((char *)&vertices->p.x + __ROL4__(edges->vertexNum[v9], 4));
  v13 = (float *)((char *)&vertices->p.x + __ROL4__(v10, 4));
  v14 = (float)(v12[2] - v11[2]);
  v15 = (float)(*v13 - *v11);
  v16 = (float)(v12[1] - v11[1]);
  v17 = (float)(v13[1] - v11[1]);
  v18 = (float)((float)(v13[2] - v11[2]) * (float)(v12[1] - v11[1]));
  v19 = (float)((float)(v13[1] - v11[1]) * (float)(*v12 - *v11));
  v20 = (float)((float)((float)(v13[2] - v11[2]) * (float)(*v12 - *v11))
              - (float)((float)(v12[2] - v11[2]) * (float)(*v13 - *v11)));
  plane->b = (float)((float)(v13[2] - v11[2]) * (float)(*v12 - *v11))
           - (float)((float)(v12[2] - v11[2]) * (float)(*v13 - *v11));
  v21 = (float)((float)((float)v17 * (float)v14) - (float)v18);
  plane->a = (float)((float)v17 * (float)v14) - (float)v18;
  v22 = (float)((float)((float)v15 * (float)v16) - (float)v19);
  plane->c = (float)((float)v15 * (float)v16) - (float)v19;
  _FP9 = (float)((float)((float)((float)v21 * (float)v21)
                       + (float)((float)((float)v22 * (float)v22) + (float)((float)v20 * (float)v20)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f8, f9, f10, f13 }
  v25 = __frsqrte(_FP8);
  v26 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25
                                                                                      * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v22 * (float)v22) + (float)((float)v20 * (float)v20)))
                                                                                              * (float)0.5))
                                                                              * (float)v25)
                                                                      - (float)1.5)
                                                      * (float)v25)
                                              * (float)((float)((float)((float)v21 * (float)v21)
                                                              + (float)((float)((float)v22 * (float)v22)
                                                                      + (float)((float)v20 * (float)v20)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v25
                                                                              * (float)((float)((float)((float)v21 * (float)v21)
                                                                                              + (float)((float)((float)v22 * (float)v22) + (float)((float)v20 * (float)v20)))
                                                                                      * (float)0.5))
                                                                      * (float)v25)
                                                              - (float)1.5)
                                              * (float)v25))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v25
                                                      * (float)((float)((float)((float)v21 * (float)v21)
                                                                      + (float)((float)((float)v22 * (float)v22)
                                                                              + (float)((float)v20 * (float)v20)))
                                                              * (float)0.5))
                                              * (float)v25)
                                      - (float)1.5)
                      * (float)v25));
  v27 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v22 * (float)v22) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v25) - (float)1.5)
                                                                                              * (float)v25)
                                                                                      * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v22 * (float)v22) + (float)((float)v20 * (float)v20)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v22 * (float)v22) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v25) - (float)1.5)
                                                                                      * (float)v25))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v25
                                                                                              * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v22 * (float)v22) + (float)((float)v20 * (float)v20))) * (float)0.5))
                                                                                      * (float)v25)
                                                                              - (float)1.5)
                                                              * (float)v25))
                                              * (float)((float)((float)((float)v21 * (float)v21)
                                                              + (float)((float)((float)v22 * (float)v22)
                                                                      + (float)((float)v20 * (float)v20)))
                                                      * (float)0.5))
                                      * (float)v26)
                              - (float)1.5)
              * (float)v26);
  plane->a = (float)v21 * (float)v27;
  v28 = (float)((float)v20 * (float)v27);
  plane->b = v28;
  v29 = (float)((float)v22 * (float)v27);
  plane->c = v29;
  plane->d = -(float)((float)((float)v29 * v11[2])
                    + (float)((float)(v11[1] * (float)v28) + (float)((float)((float)v21 * (float)v27) * *v11)));
}

