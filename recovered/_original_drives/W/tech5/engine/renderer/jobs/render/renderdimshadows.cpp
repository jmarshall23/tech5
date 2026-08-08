
// ========================================================================
// CalculateLightMatrix
// EA  : 0x828DBDC8
// RVA : 0x008DBDC8
// PDB : w:\tech5\engine\renderer\jobs\render\renderdimshadows.cpp
// ========================================================================

void __fastcall CalculateLightMatrix(
        idRenderMatrix *lightMatrix,
        const idVec3 *primeLightDir,
        const idRenderMatrix *modelMatrix,
        const idBounds *referenceBounds)
{
  double z; // fp8
  double v7; // fp11
  double v8; // fp11
  double v9; // fp10
  double v10; // fp9
  double v11; // fp8
  double v14; // fp4
  double v15; // fp2
  double v16; // fp10
  double v17; // fp11
  double v18; // fp8
  double v19; // fp6
  double v20; // fp5
  double v21; // fp10
  double v22; // fp9
  double v23; // fp2
  double v24; // fp4
  double v25; // fp4
  double v26; // fp1
  double v27; // fp12
  double v28; // fp9
  double v29; // fp8
  double v30; // fp7
  double v31; // fp1
  double v32; // fp8
  double v33; // fp3
  double v34; // fp12
  double v35; // fp4
  double v36; // fp5
  double v37; // fp11
  double v38; // fp3
  idBounds v39; // [sp+50h] [-90h] BYREF
  idRenderMatrix v40; // [sp+70h] [-70h] BYREF

  lightMatrix->m[8] = -primeLightDir->x;
  lightMatrix->m[9] = -primeLightDir->y;
  lightMatrix->m[10] = -primeLightDir->z;
  lightMatrix->m[11] = 0.0;
  z = primeLightDir->z;
  if ( __fabs(z) >= 0.99000001 )
  {
    v7 = (float)(primeLightDir->y + primeLightDir->z);
    lightMatrix->m[4] = -(float)(primeLightDir->x * (float)(primeLightDir->y + primeLightDir->z));
    lightMatrix->m[5] = -(float)((float)(primeLightDir->y * (float)v7) - (float)1.0);
    lightMatrix->m[6] = -(float)((float)(primeLightDir->z * (float)v7) - (float)1.0);
  }
  else
  {
    lightMatrix->m[4] = primeLightDir->x * primeLightDir->z;
    lightMatrix->m[5] = primeLightDir->y * (float)z;
    lightMatrix->m[6] = (float)(primeLightDir->z * (float)z) - (float)1.0;
  }
  v8 = (float)(lightMatrix->m[5] * lightMatrix->m[5]);
  v9 = lightMatrix->m[4];
  v10 = lightMatrix->m[6];
  lightMatrix->m[7] = 0.0;
  v11 = v9;
  _FP5 = (float)((float)((float)((float)v10 * (float)v10) + (float)((float)((float)v9 * (float)v9) + (float)v8))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f12 }
  v14 = (float)((float)((float)((float)v10 * (float)v10) + (float)((float)((float)v9 * (float)v9) + (float)v8))
              * (float)0.5);
  v15 = __frsqrte(_FP3);
  v16 = (float)((float)-(float)((float)((float)((float)v15
                                              * (float)((float)((float)((float)v10 * (float)v10)
                                                              + (float)((float)((float)v9 * (float)v9) + (float)v8))
                                                      * (float)0.5))
                                      * (float)v15)
                              - (float)1.5)
              * (float)v15);
  lightMatrix->m[4] = (float)v11
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)v14)
                                                                                            * (float)v16)
                                                                                    - (float)1.5)
                                                                    * (float)v16)
                                                            * (float)v14)
                                                    * (float)((float)-(float)((float)((float)((float)v16 * (float)v14)
                                                                                    * (float)v16)
                                                                            - (float)1.5)
                                                            * (float)v16))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v16 * (float)v14) * (float)v16) - (float)1.5)
                                    * (float)v16));
  lightMatrix->m[5] = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)v14)
                                                                                            * (float)v16)
                                                                                    - (float)1.5)
                                                                    * (float)v16)
                                                            * (float)v14)
                                                    * (float)((float)-(float)((float)((float)((float)v16 * (float)v14)
                                                                                    * (float)v16)
                                                                            - (float)1.5)
                                                            * (float)v16))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v16 * (float)v14) * (float)v16) - (float)1.5)
                                    * (float)v16))
                    * lightMatrix->m[5];
  v17 = (float)(lightMatrix->m[6]
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)v14)
                                                                                      * (float)v16)
                                                                              - (float)1.5)
                                                              * (float)v16)
                                                      * (float)v14)
                                              * (float)((float)-(float)((float)((float)((float)v16 * (float)v14)
                                                                              * (float)v16)
                                                                      - (float)1.5)
                                                      * (float)v16))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v16 * (float)v14) * (float)v16) - (float)1.5)
                              * (float)v16)));
  lightMatrix->m[6] = lightMatrix->m[6]
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)v14)
                                                                                            * (float)v16)
                                                                                    - (float)1.5)
                                                                    * (float)v16)
                                                            * (float)v14)
                                                    * (float)((float)-(float)((float)((float)((float)v16 * (float)v14)
                                                                                    * (float)v16)
                                                                            - (float)1.5)
                                                            * (float)v16))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v16 * (float)v14) * (float)v16) - (float)1.5)
                                    * (float)v16));
  v18 = lightMatrix->m[9];
  v19 = lightMatrix->m[5];
  v20 = lightMatrix->m[8];
  v21 = lightMatrix->m[10];
  v22 = lightMatrix->m[4];
  v23 = (float)(lightMatrix->m[10] * lightMatrix->m[4]);
  v24 = (float)(lightMatrix->m[8] * lightMatrix->m[5]);
  lightMatrix->m[3] = 0.0;
  lightMatrix->m[12] = 0.0;
  lightMatrix->m[13] = 0.0;
  lightMatrix->m[14] = 0.0;
  lightMatrix->m[15] = 1.0;
  lightMatrix->m[1] = (float)((float)v20 * (float)v17) - (float)v23;
  lightMatrix->m[2] = (float)((float)v18 * (float)v22) - (float)v24;
  lightMatrix->m[0] = (float)((float)v21 * (float)v19) - (float)((float)v18 * (float)v17);
  idRenderMatrix::Multiply(a: lightMatrix, b: modelMatrix, out: &v40);
  idBounds::FromModelMatrixBounds(this: &v39, bounds: referenceBounds, modelMatrix: &v40);
  v25 = (float)((float)(lightMatrix->m[0] * v39.b[0].x)
              + (float)((float)(v39.b[0].y * lightMatrix->m[4]) + (float)(v39.b[0].z * lightMatrix->m[8])));
  v26 = (float)((float)2.0 / (float)(v39.b[1].x - v39.b[0].x));
  v27 = (float)((float)(v39.b[0].y * lightMatrix->m[5])
              + (float)((float)(lightMatrix->m[1] * v39.b[0].x) + (float)(lightMatrix->m[9] * v39.b[0].z)));
  v28 = (float)((float)(lightMatrix->m[10] * v39.b[0].z)
              + (float)((float)(v39.b[0].y * lightMatrix->m[6]) + (float)(v39.b[0].x * lightMatrix->m[2])));
  v29 = (float)((float)2.0 / (float)(v39.b[1].y - v39.b[0].y));
  v30 = (float)((float)2.0 / (float)(v39.b[1].z - v39.b[0].z));
  lightMatrix->m[0] = lightMatrix->m[0] * (float)((float)2.0 / (float)(v39.b[1].x - v39.b[0].x));
  lightMatrix->m[1] = lightMatrix->m[1] * (float)v26;
  v31 = (float)((float)v26 * lightMatrix->m[2]);
  lightMatrix->m[2] = v31;
  lightMatrix->m[3] = -(float)((float)((float)v28 * (float)v31)
                             - (float)-(float)((float)(lightMatrix->m[1] * (float)v27)
                                             - (float)-(float)((float)(lightMatrix->m[0] * (float)v25) - (float)-1.0)));
  lightMatrix->m[4] = lightMatrix->m[4] * (float)v29;
  lightMatrix->m[5] = (float)v29 * lightMatrix->m[5];
  v32 = (float)(lightMatrix->m[6] * (float)v29);
  lightMatrix->m[6] = v32;
  lightMatrix->m[7] = -(float)((float)((float)v28 * (float)v32)
                             - (float)-(float)((float)((float)v27 * lightMatrix->m[5])
                                             - (float)-(float)((float)((float)v25 * lightMatrix->m[4]) - (float)-1.0)));
  lightMatrix->m[8] = (float)v30 * lightMatrix->m[8];
  lightMatrix->m[9] = lightMatrix->m[9] * (float)v30;
  v33 = (float)(lightMatrix->m[10] * (float)v30);
  lightMatrix->m[10] = lightMatrix->m[10] * (float)v30;
  v34 = (float)-(float)((float)(lightMatrix->m[9] * (float)v27)
                      - (float)-(float)((float)((float)v25 * lightMatrix->m[8]) - (float)-1.0));
  v35 = (float)(lightMatrix->m[9] * (float)0.5);
  v36 = (float)(lightMatrix->m[8] * (float)0.5);
  v37 = (float)-(float)((float)((float)v33 * (float)v28) - (float)v34);
  lightMatrix->m[11] = -(float)((float)((float)v33 * (float)v28) - (float)v34);
  v38 = (float)(lightMatrix->m[10] * (float)0.5);
  lightMatrix->m[8] = v36;
  lightMatrix->m[9] = v35;
  lightMatrix->m[10] = v38;
  lightMatrix->m[11] = (float)((float)v37 + (float)1.0) * (float)0.5;
}


// ========================================================================
// ?RenderDimShadows@@YAXPBUrenderDimShadowsParms_t@@@Z
// EA  : 0x828DC140
// RVA : 0x008DC140
// PDB : w:\tech5\engine\renderer\jobs\render\renderdimshadows.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall RenderDimShadows(const renderDimShadowsParms_t *parms)
{
  const renderSettings_t *settings; // r11
  int v3; // r15
  __int16 *dimShadowModelSlaves; // r3
  int v5; // r27
  const idRenderModelCommitted *dimShadowModels; // r30
  float *v7; // r29
  int suppressShadowInViewID; // r11
  int singleDimShadow; // r11
  int groupMasterIndex; // r11
  const idRenderModelCommitted *const *linkedRenderModels; // r9
  int v12; // r8
  const idRenderModelCommitted *const *i; // r11
  int v14; // r11
  const renderSettings_t *v15; // r9
  const idRenderView *renderView; // r11
  double v17; // fp25
  double v18; // fp26
  const idRenderView *v19; // r11
  __int64 v20; // r4
  double v21; // fp12
  int v22; // r5
  unsigned int v23; // r25
  bool v24; // r27
  double v25; // fp11
  double v26; // fp13
  double v27; // fp0
  double v28; // fp13
  const idRenderView *v29; // r5
  int v30; // r10
  double v31; // fp8
  occlusionState_t *occlusionState; // r8
  int renderFrameNumber; // r6
  const renderSettings_t *v34; // r11
  __int64 v35; // r10
  __int64 v36; // r8
  BOOL v37; // r21
  __int64 v38; // r6
  __int64 v39; // r4 OVERLAPPED
  signed int DeferredQueryResult; // r30
  __int64 v41; // r8
  __int64 firstOcclusionQueryInPreviousFrame; // r6
  const idTriangles *extrudeBox; // r9
  const idTriangles *v44; // r9
  bfx::BinaryReplayLogOut *v45; // r3
  const renderSettings_t *v46; // r11
  __int64 v47; // r10
  __int64 v48; // r8
  double dimShadowLixelScale; // fp6
  unsigned int v50; // r22
  unsigned int v51; // r24
  signed int v52; // r30
  const idRenderView *v53; // r11
  double v54; // fp0
  double v55; // fp5
  double v56; // fp4
  double v57; // fp0
  double v58; // fp12
  double v59; // fp8
  double v60; // fp4
  double v61; // fp8
  double v62; // fp0
  int v63; // r11
  __int64 v64; // r6
  int v65; // r28
  __int128 v66; // r4
  bool v67; // r5
  int v68; // r23
  int v69; // r11
  const idRenderModelCommitted *v70; // r30
  const idVec4 *Vector; // r3
  bool v72; // r7
  int v73; // r27
  int v74; // r29
  idRenderModelSurface *v75; // r11
  const idMaterial *material; // r10
  const idODSObject<idRenderModelSurface> *v77; // r4
  const idODSObject<idDeclRenderProg> *v78; // r3
  bool v79; // r3
  const idRenderView *v80; // r11
  const idRenderView *v81; // r11
  __int64 v82; // r10
  __int64 v83; // r10
  __int64 v84; // r8
  __int64 v85; // r6
  const renderSettings_t *v86; // r10
  double v87; // fp1
  double v88; // fp0
  bfx::BinaryReplayLogOut *v89; // r3
  bool v90; // r7
  const idDeclRenderProg *progDimShadowDraw; // r11
  const idDeclRenderProg *renamed; // r11
  bool v93; // r7
  bfx::BinaryReplayLogOut *v94; // r3
  const idTriangles *v95; // r10
  int v96; // [sp+8h] [-828h]
  int v97; // [sp+Ch] [-824h]
  int v98; // [sp+10h] [-820h]
  int v99; // [sp+14h] [-81Ch]
  int v100; // [sp+18h] [-818h]
  int v101; // [sp+1Ch] [-814h]
  float v102; // [sp+50h] [-7E0h] BYREF
  signed int dimShadowResolution; // [sp+54h] [-7DCh]
  float v104; // [sp+58h] [-7D8h] BYREF
  int v105; // [sp+5Ch] [-7D4h]
  unsigned __int8 v106[4]; // [sp+60h] [-7D0h] BYREF
  int v107; // [sp+64h] [-7CCh]
  idODSObject<idDeclRenderProg> v108; // [sp+68h] [-7C8h] BYREF
  const idDeclRenderProg *progDimShadowCreate; // [sp+6Ch] [-7C4h] BYREF
  idODSObject<idDeclRenderProg> v110; // [sp+70h] [-7C0h] BYREF
  idODSObject<idTriangles> v111; // [sp+74h] [-7BCh] BYREF
  idODSObject<idDeclRenderProg> v112; // [sp+78h] [-7B8h] BYREF
  idODSObject<idTriangles> v113; // [sp+7Ch] [-7B4h] BYREF
  idODSObject<idRenderDestination> v114; // [sp+80h] [-7B0h] BYREF
  const char *v115; // [sp+84h] [-7ACh]
  idODSObject<idRenderDestination> v116; // [sp+88h] [-7A8h] BYREF
  idRenderModelSurface *v117; // [sp+8Ch] [-7A4h] BYREF
  const char *v118; // [sp+90h] [-7A0h]
  idRenderModelSurface *v119; // [sp+94h] [-79Ch] BYREF
  const char *v120; // [sp+98h] [-798h]
  idODSObject<idRenderDestination> v121; // [sp+9Ch] [-794h] BYREF
  idODSObject<idTriangles> v122; // [sp+A0h] [-790h] BYREF
  const char *v123; // [sp+A4h] [-78Ch]
  idODSObject<idDeclRenderProg> v124; // [sp+A8h] [-788h] BYREF
  const idDeclRenderProg *progDimShadowCreateWound; // [sp+ACh] [-784h] BYREF
  idODSObject<idTriangles> v126; // [sp+B0h] [-780h] BYREF
  idVec3 v127[2]; // [sp+B8h] [-778h] BYREF
  idPlane v128; // [sp+D0h] [-760h] BYREF
  idRenderMatrix v129; // [sp+E0h] [-750h] BYREF
  int v131; // [sp+124h] [-70Ch]
  __int64 v132; // [sp+128h] [-708h]
  unsigned __int64 v133; // [sp+130h] [-700h]
  idVec3 v134[2]; // [sp+138h] [-6F8h] BYREF
  idPlane v135; // [sp+150h] [-6E0h] BYREF
  idVec3 v136; // [sp+160h] [-6D0h] BYREF
  idPlane v137; // [sp+170h] [-6C0h] BYREF
  idRenderMatrix v138; // [sp+180h] [-6B0h] BYREF
  idParmBlock v139[2]; // [sp+1C0h] [-670h] BYREF
  idRenderMatrix v140; // [sp+210h] [-620h] BYREF
  idRenderMatrix v141; // [sp+250h] [-5E0h] BYREF
  idRenderMatrix v142; // [sp+290h] [-5A0h] BYREF
  idRenderMatrix v143; // [sp+2D0h] [-560h] BYREF
  idRenderMatrix v144[18]; // [sp+310h] [-520h] BYREF

  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_RENDER_DIM_SHADOWS);
  settings = parms->settings;
  v3 = 0;
  dimShadowModelSlaves = parms->dimShadowModelSlaves;
  v107 = 0;
  v5 = 0;
  dimShadowResolution = settings->dimShadowResolution;
  memset(Dst: dimShadowModelSlaves, Val: -1, Size: 0x2000u);
  dimShadowModels = parms->dimShadowModels;
  if ( dimShadowModels != nullptr )
  {
    v7 = &v144[0].m[15];
    do
    {
      if ( dimShadowModels->references.num > 0 )
      {
        suppressShadowInViewID = dimShadowModels->r.suppressShadowInViewID;
        if ( suppressShadowInViewID == 0 || suppressShadowInViewID != parms->renderView->r.viewID )
        {
          singleDimShadow = parms->settings->singleDimShadow;
          if ( (singleDimShadow == -1 || singleDimShadow == dimShadowModels->index.index >> 8)
            && ((LODWORD(dimShadowModels->approximateLighting.primeLightDir.x)
               | LODWORD(dimShadowModels->approximateLighting.primeLightDir.y)
               | LODWORD(dimShadowModels->approximateLighting.primeLightDir.z))
              & 0x7FFFFFFF) != 0
            && dimShadowModels->approximateLighting.primeLightColor.w <= 0.95 )
          {
            groupMasterIndex = dimShadowModels->r.groupMasterIndex;
            if ( groupMasterIndex == -1 )
            {
              if ( v5 < 256 )
              {
                *(_DWORD *)++v7 = dimShadowModels;
                ++v5;
              }
              else
              {
                idRenderLog::Printf(this: &renderLog, fmt: "More than %d models with dim-shadows", 256);
              }
            }
            else
            {
              linkedRenderModels = parms->linkedRenderModels;
              v12 = dimShadowModels->r.groupMasterIndex;
              for ( i = &linkedRenderModels[groupMasterIndex]; *i != nullptr; i = &linkedRenderModels[v14] )
              {
                v14 = (*i)->r.groupMasterIndex;
                if ( v14 < 0 )
                  break;
                v12 = v14;
              }
              *(__int16 *)((char *)parms->dimShadowModelSlaves + ((dimShadowModels->index.index >> 7) & 0x1FFFFFE)) = parms->dimShadowModelSlaves[v12];
              parms->dimShadowModelSlaves[v12] = dimShadowModels->index.index >> 8;
            }
          }
        }
      }
      dimShadowModels = dimShadowModels->nextDimShadowModel;
    }
    while ( dimShadowModels != nullptr );
    v107 = v5;
  }
  v15 = parms->settings;
  renderView = parms->renderView;
  v17 = (float)((float)((float)((float)((float)(renderView->projectionMatrix.m[9] + renderView->projectionMatrix.m[8])
                                      * (float)0.0)
                              + (float)(renderView->projectionMatrix.m[10] * (float)-v15->dimShadowMaxVisibleRange))
                      + renderView->projectionMatrix.m[11])
              / (float)((float)((float)((float)(renderView->projectionMatrix.m[13] + renderView->projectionMatrix.m[12])
                                      * (float)0.0)
                              + (float)(renderView->projectionMatrix.m[14] * (float)-v15->dimShadowMaxVisibleRange))
                      + renderView->projectionMatrix.m[15]));
  v18 = (float)((float)((float)((float)((float)(renderView->projectionMatrix.m[9] + renderView->projectionMatrix.m[8])
                                      * (float)0.0)
                              + (float)(renderView->projectionMatrix.m[10] * (float)-v15->dimShadowFadeVisibilityRange))
                      + renderView->projectionMatrix.m[11])
              / (float)((float)((float)((float)(renderView->projectionMatrix.m[13] + renderView->projectionMatrix.m[12])
                                      * (float)0.0)
                              + (float)(renderView->projectionMatrix.m[14] * (float)-v15->dimShadowFadeVisibilityRange))
                      + renderView->projectionMatrix.m[15]));
  GL_Viewport(
    x: renderView->viewport.x1,
    y: renderView->viewport.y1,
    w: renderView->viewport.x2 - renderView->viewport.x1 + 1,
    h: renderView->viewport.y2 - renderView->viewport.y1 + 1);
  v19 = parms->renderView;
  GL_Scissor(
    x: v19->scissorRect.x1,
    y: v19->scissorRect.y1,
    w: v19->scissorRect.x2 - v19->scissorRect.x1 + 1,
    h: v19->scissorRect.y2 - v19->scissorRect.y1 + 1);
  idDeclRenderParm::SetImage(this: parms->rpViewColor, image: parms->imgViewColor);
  GL_BeginQueryBatch(a1: v20);
  v105 = 0;
  if ( v5 > 0 )
  {
    v21 = 0.0;
    v118 = "dimShadow sample %i:%s";
    v115 = "dimShadow draw %i:%s";
    v123 = "screenLen culled model dimShadow %i:%s\n";
    v22 = 0;
    v120 = "dimShadow test %i:%s";
    do
    {
      v23 = LODWORD(v144[1].m[v22]);
      v24 = (_cntlzw(v23) & 0x20) != 0;
      v25 = *(float *)(v23 + 1264);
      if ( v25 >= v21 )
        v26 = 1.0;
      else
        v26 = -1.0;
      if ( v25 < v21 && (*(_BYTE *)(v23 + 140) & 0x40) == 0 )
        goto LABEL_119;
      if ( *(float *)(v23 + 164) == v21 )
      {
        if ( v25 >= v21 )
          v27 = (float)(*(float *)(v23 + 1100) - (float)(*(float *)(v23 + 1112) - *(float *)(v23 + 1100)));
        else
          v27 = (float)((float)(*(float *)(v23 + 1112) - *(float *)(v23 + 1100)) + *(float *)(v23 + 1112));
      }
      else
      {
        v27 = (float)((float)(*(float *)(v23 + 164) * (float)v26) + *(float *)(v23 + 44));
      }
      if ( v25 >= v21 )
      {
        if ( *(float *)(v23 + 1112) < v27 )
          goto LABEL_119;
      }
      else if ( *(float *)(v23 + 1100) > v27 )
      {
        goto LABEL_119;
      }
      if ( v25 >= v21 )
      {
        if ( *(float *)(v23 + 1100) < (double)(float)((float)v27 + (float)1.0) )
          v27 = (float)(*(float *)(v23 + 1100) - (float)1.0);
      }
      else if ( *(float *)(v23 + 1112) > (double)(float)((float)v27 - (float)1.0) )
      {
        v27 = (float)(*(float *)(v23 + 1112) + (float)1.0);
      }
      v28 = idMath::FLT_SMALLEST_NON_DENORMAL;
      if ( v25 >= v21 )
      {
        if ( v25 >= v28 )
        {
LABEL_45:
          v29 = parms->renderView;
          v30 = *(_DWORD *)(v23 + 8) >> 8;
          v31 = -*(float *)(v23 + 1260);
          v127[0].x = -*(float *)(v23 + 1256);
          v127[0].y = v31;
          occlusionState = v29->occlusionState;
          v127[0].z = -v25;
          v128.a = v21;
          v128.b = v21;
          v128.c = -1.0;
          renderFrameNumber = occlusionState->renderFrameNumber;
          v128.d = v27;
          if ( occlusionState->modelVisibleFrameNumber[v30] <= renderFrameNumber )
            SetupModelMVPMatrix(
              mvpMatrix: (idRenderMatrix *)(v23 + 1420),
              model: (const idRenderModelCommitted *)v23,
              renderView: v29,
              zNear: parms->settings->viewNearZ,
              zFar: parms->settings->viewFarZ);
          idRenderMatrix::TransformDir(this: (idRenderMatrix *)(v23 + 1192), in: v127, out: v134, normalize: true);
          idRenderMatrix::InverseTransformPlane(
            this: (idRenderMatrix *)(v23 + 1128),
            in: &v128,
            out: &v135,
            normalize: true);
          if ( !idRenderMatrix::CullExtrudedBoundsToMVPbits(
                  mvp: (const idRenderMatrix *)(v23 + 1420),
                  b: (const idBounds *)(v23 + 12),
                  extrudeDirection: v134,
                  clipPlane: &v135,
                  outBits: v106,
                  zeroToOne: false) )
          {
            v104 = 0.0;
            v102 = 0.0;
            idRenderMatrix::DepthBoundsForExtrudedBounds(
              min: &v102,
              max: &v104,
              mvp: (const idRenderMatrix *)(v23 + 1420),
              b: (const idBounds *)(v23 + 12),
              extrudeDirection: v134,
              clipPlane: &v135,
              zeroToOne: true);
            v34 = parms->settings;
            if ( v34->dimShadowSkipRangeCulling || v102 <= v17 )
            {
              if ( v34->showDimShadows != 0 )
                parms->modelDimShadowState[*(_DWORD *)(v23 + 8) >> 8] = 1;
              idRenderMatrix::OffsetScaleForBounds(
                src: (const idRenderMatrix *)(v23 + 1420),
                bounds: (const idBounds *)(v23 + 12),
                out: &v140);
              idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v140);
              idRenderMatrix::OffsetScaleForBounds(
                src: (const idRenderMatrix *)(v23 + 1128),
                bounds: (const idBounds *)(v23 + 12),
                out: v144);
              idRenderMatrix::InverseOffsetScaleForBounds(
                src: (const idRenderMatrix *)(v23 + 1192),
                bounds: (const idBounds *)(v23 + 12),
                out: &v141);
              idRenderMatrix::TransformDir(this: &v141, in: v127, out: &v136, normalize: true);
              idRenderMatrix::InverseTransformPlane(this: v144, in: &v128, out: &v137, normalize: true);
              idDeclRenderParm::Set(this: parms->rpDimShadowExtrude, vec: &v136);
              idDeclRenderParm::Set(this: parms->rpDimShadowClipPlane, plane: &v137);
              v37 = v24;
              if ( v24 )
                goto LABEL_66;
              HIDWORD(v38) = *(_DWORD *)(v23 + 8) >> 8;
              LODWORD(v38) = *(_DWORD *)v23;
              idRenderLog::OpenBlock(
                this: &renderLog,
                fmt: v120,
                a3: v38,
                a4: v36,
                a5: v35,
                a6: v96,
                a7: v97,
                a8: v98,
                a9: v99,
                a10: v100,
                a11: v101);
              if ( parms->settings->dimShadowDepthBoundsTest )
                idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)HIDWORD(v39));
              DeferredQueryResult = 0;
              LODWORD(v41) = (*(_DWORD *)(v23 + 8) >> 8) + 12352;
              HIDWORD(v41) = 8 * v41;
              firstOcclusionQueryInPreviousFrame = parms->renderView->firstOcclusionQueryInPreviousFrame;
              *(__int64 *)((char *)&v39 + 4) = parms->occlusionState->nodeOcclusionQuery[v41];
              if ( SHIDWORD(v39) >= (int)firstOcclusionQueryInPreviousFrame )
                DeferredQueryResult = GL_GetDeferredQueryResult(queryNumber: v39);
              HIDWORD(v39) = &parms->occlusionState->shadowOcclusionQuery[*(_DWORD *)(v23 + 8) >> 8];
              GL_BeginQuery(queryNumber: v39, a2: SHIDWORD(firstOcclusionQueryInPreviousFrame), a3: v41);
              D3DDevice_SetRenderState_HiStencilWriteEnable(pDevice: wrapperContext.d3d, Value: 1u);
              D3DDevice_SetRenderState_HiStencilRef(pDevice: wrapperContext.d3d, Value: 1u);
              D3DDevice_SetRenderState_HiStencilFunc(pDevice: wrapperContext.d3d, Value: 1u);
              if ( v102 < 0.1 )
              {
                extrudeBox = parms->extrudeBox;
                v110.objectPtr = parms->progDimShadowStencil;
                v113.objectPtr = extrudeBox;
                GL_DrawElements(prog: &v110, tri: &v113, extraState: 0xF01007C000000000uLL, skipDetailTriangles: 15);
              }
              v44 = parms->extrudeBox;
              v112.objectPtr = parms->progDimShadowStencil;
              v111.objectPtr = v44;
              GL_DrawElements(prog: &v112, tri: &v111, extraState: 0xF01107C000000000uLL, skipDetailTriangles: 15);
              D3DDevice_SetRenderState_HiStencilWriteEnable(pDevice: wrapperContext.d3d, Value: 0);
              GL_EndQuery();
              if ( parms->settings->dimShadowDepthBoundsTest )
                idPhysics_StaticMulti::UpdateTime(this: v45);
              if ( renderLog.logFile != nullptr )
                idRenderLog::LogCloseBlock(this: &renderLog, label: RENDER_LOG_INDENT_BLOCK);
              if ( DeferredQueryResult > 0 || !parms->settings->dimShadowUseQuery || (*(_BYTE *)(v23 + 143) & 8) != 0 )
              {
LABEL_66:
                v46 = parms->settings;
                LODWORD(v47) = v105;
                HIDWORD(v47) = v105 + 1;
                LODWORD(v48) = v46->dimShadowForceHighQuality;
                dimShadowLixelScale = v46->dimShadowLixelScale;
                ++v105;
                v50 = (-(int)v48 & (unsigned int)~(_DWORD)v48) >> 31;
                if ( dimShadowLixelScale <= 0.0 )
                {
                  v51 = dimShadowResolution;
                  v52 = dimShadowResolution;
                  goto LABEL_77;
                }
                v53 = parms->renderView;
                v54 = (float)((float)((float)(*(float *)(v23 + 1096) + *(float *)(v23 + 1108)) * (float)0.5)
                            - v53->r.vieworg.y);
                v55 = (float)((float)((float)(*(float *)(v23 + 1100) + *(float *)(v23 + 1112)) * (float)0.5)
                            - v53->r.vieworg.z);
                v56 = (float)((float)((float)(*(float *)(v23 + 1092) + *(float *)(v23 + 1104)) * (float)0.5)
                            - v53->r.vieworg.x);
                v57 = __fsqrts((float)((float)((float)v56 * (float)v56)
                                     + (float)((float)((float)v55 * (float)v55) + (float)((float)v54 * (float)v54))));
                if ( v57 < 4.0 )
                  v57 = 4.0;
                v58 = (float)(*(float *)(v23 + 1112)
                            - (float)((float)(*(float *)(v23 + 1100) + *(float *)(v23 + 1112)) * (float)0.5));
                v59 = (float)(*(float *)(v23 + 1104)
                            - (float)((float)(*(float *)(v23 + 1092) + *(float *)(v23 + 1104)) * (float)0.5));
                v60 = (float)(*(float *)(v23 + 1108)
                            - (float)((float)(*(float *)(v23 + 1096) + *(float *)(v23 + 1108)) * (float)0.5));
                v61 = __fsqrts((float)((float)((float)v60 * (float)v60)
                                     + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58))));
                v62 = (float)((float)((float)((float)(v53->projectionMatrix.m[0] * (float)v61)
                                            + (float)((float)(v53->projectionMatrix.m[2] * (float)-v57)
                                                    + (float)(v53->projectionMatrix.m[1] * (float)0.0)))
                                    + v53->projectionMatrix.m[3])
                            / (float)((float)((float)(v53->projectionMatrix.m[9] * (float)0.0)
                                            + (float)((float)(v53->projectionMatrix.m[10] * (float)-v57)
                                                    + (float)(v53->projectionMatrix.m[8] * (float)v61)))
                                    + v53->projectionMatrix.m[11]));
                if ( v62 >= 0.02 )
                {
                  v52 = dimShadowResolution;
                  v131 = (int)(float)((float)dimShadowLixelScale * (float)v62);
                  v51 = v131 & 0xFFFFFFFE;
                  if ( (int)(v131 & 0xFFFFFFFE) > dimShadowResolution )
                  {
                    v51 = dimShadowResolution;
                    if ( *(_DWORD *)(v23 + 136) != 2 || (v63 = 1, (*(_BYTE *)(v23 + 140) & 0x80) == 0) )
                      v63 = 0;
                    LODWORD(v47) = (-(int)v48 & (unsigned int)~(_DWORD)v48) >> 31;
                    HIDWORD(v47) = v47 | v63;
                    LOBYTE(v50) = ((-(int)v48 & ~(_DWORD)v48) < 0) | v63;
                  }
LABEL_77:
                  HIDWORD(v64) = *(_DWORD *)(v23 + 8) >> 8;
                  LODWORD(v64) = *(_DWORD *)v23;
                  HIDWORD(v48) = -(int)v48;
                  idRenderLog::OpenBlock(
                    this: &renderLog,
                    fmt: v115,
                    a3: v64,
                    a4: v48,
                    a5: v47,
                    a6: v96,
                    a7: v97,
                    a8: v98,
                    a9: v99,
                    a10: v100,
                    a11: v101);
                  if ( parms->settings->showDimShadows != 0 )
                    parms->modelDimShadowState[*(_DWORD *)(v23 + 8) >> 8] = 2;
                  CalculateLightMatrix(
                    lightMatrix: (idRenderMatrix *)&v139[0].constants,
                    primeLightDir: (const idVec3 *)(v23 + 1256),
                    modelMatrix: (const idRenderMatrix *)(v23 + 1128),
                    referenceBounds: (const idBounds *)(v23 + 12));
                  v121.objectPtr = parms->renderDestDimShadow;
                  GL_SetRenderDestination(destination: &v121, level: 0, side: 0);
                  v65 = (int)(v52 - v51) >> 1;
                  GL_Scissor(x: v65, y: v65, w: v51, h: v51);
                  GL_Viewport(x: v65, y: v65, w: v51, h: v51);
                  LODWORD(v66) = 0;
                  *(_QWORD *)((char *)&v66 + 4) = parms->progDimShadowCreate->glState;
                  GL_State(stateBits: v66, forceGlState: v67);
                  GL_Clear(color: false, depth: true, stencil: false, stencilValue: 0, r: 0.0, g: 0.0, b: 0.0, a: 0.0);
                  GL_PolygonOffset(
                    scale: parms->settings->dimShadowPolyOfsFactor,
                    bias: parms->settings->dimShadowPolyOfsUnits,
                    fill: SBYTE11(v66));
                  v68 = *(_DWORD *)(v23 + 8) >> 8;
                  if ( v68 != -1 )
                  {
                    v69 = v68;
                    do
                    {
                      v70 = parms->linkedRenderModels[v69];
                      idRenderMatrix::Multiply(
                        a: (const idRenderMatrix *)&v139[0].constants,
                        b: &v70->modelMatrix,
                        out: &v142);
                      idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v142);
                      Vector = idParmBlock::GetVector(
                                 this: v139,
                                 result: (idVec4 *)&v70->renderParmBlock,
                                 parm: parms->rpVertexMorphScale);
                      idParmState::SetVertexMorphScale(this: renderThreadParmState, scale: Vector);
                      if ( (*((_BYTE *)&v70->r + 106) & 0x20) != 0 )
                        idParmState::VirtualEvaluateParmBlock(
                          this: renderThreadParmState,
                          localParmBlock: &v70->renderParmBlock,
                          parmBlock: &v70->renderParmBlock);
                      v73 = 0;
                      if ( v70->surfaces.num > 0 )
                      {
                        v74 = 0;
                        do
                        {
                          v75 = &v70->surfaces.list[v74];
                          material = v75->material;
                          if ( v75->material != nullptr && (*((_BYTE *)material + 72) & 0x80) != 0 )
                          {
                            if ( (*((_BYTE *)&v70->r + 106) & 0x20) != 0 && (*((_BYTE *)material + 73) & 0x20) != 0 )
                            {
                              v77 = (const idODSObject<idRenderModelSurface> *)&v117;
                              v78 = (const idODSObject<idDeclRenderProg> *)&progDimShadowCreateWound;
                              progDimShadowCreateWound = parms->progDimShadowCreateWound;
                              v117 = v75;
                            }
                            else
                            {
                              v77 = (const idODSObject<idRenderModelSurface> *)&v119;
                              v78 = (const idODSObject<idDeclRenderProg> *)&progDimShadowCreate;
                              progDimShadowCreate = parms->progDimShadowCreate;
                              v119 = v75;
                            }
                            GL_DrawElements(prog: v78, surf: v77, extraState: 0, skipDetailTriangles: v72);
                          }
                          ++v73;
                          ++v74;
                        }
                        while ( v73 < v70->surfaces.num );
                      }
                      if ( (*((_BYTE *)&v70->r + 106) & 0x20) != 0 )
                        idParmState::VirtualRollbackParmBlock(
                          this: renderThreadParmState,
                          localParmBlock: &v70->renderParmBlock,
                          parmBlock: &v70->renderParmBlock);
                      v68 = parms->dimShadowModelSlaves[v68];
                      v69 = v68;
                    }
                    while ( v68 != -1 );
                    v52 = dimShadowResolution;
                  }
                  v114.objectPtr = parms->renderDestDimShadow;
                  GL_ResolveTarget(
                    target: RESOLVE_TARGET_DEPTH,
                    destination: &v114,
                    srcMinX: v65,
                    srcMinY: v65,
                    srcMaxX: v65 + v51,
                    srcMaxY: v65 + v51,
                    dstX: v65,
                    dstY: v65);
                  GL_PolygonOffset(scale: 0.0, bias: 0.0, fill: v79);
                  v116.objectPtr = parms->renderDestDefault;
                  GL_SetRenderDestination(destination: &v116, level: 0, side: 0);
                  v80 = parms->renderView;
                  GL_Viewport(
                    x: v80->viewport.x1,
                    y: v80->viewport.y1,
                    w: v80->viewport.x2 - v80->viewport.x1 + 1,
                    h: v80->viewport.y2 - v80->viewport.y1 + 1);
                  v81 = parms->renderView;
                  GL_Scissor(
                    x: v81->scissorRect.x1,
                    y: v81->scissorRect.y1,
                    w: v81->scissorRect.x2 - v81->scissorRect.x1 + 1,
                    h: v81->scissorRect.y2 - v81->scissorRect.y1 + 1);
                  if ( renderLog.logFile != nullptr )
                    idRenderLog::LogCloseBlock(this: &renderLog, label: RENDER_LOG_INDENT_BLOCK);
                  idRenderMatrix::Multiply(
                    a: (const idRenderMatrix *)&v139[0].constants,
                    b: &parms->renderView->inverseViewMatrix,
                    out: &v143);
                  idRenderMatrix::Multiply(a: &v143, b: &parms->renderView->inverseProjectionMatrix, out: &v129);
                  LODWORD(v82) = v52;
                  v133 = __PAIR64__(v52, v51);
                  v132 = v82;
                  v129.m[0] = v129.m[0] * (float)((float)((float)1.0 / (float)v82) * (float)__SPAIR64__(v52, v51));
                  v129.m[4] = v129.m[4] * (float)((float)((float)1.0 / (float)v82) * (float)__SPAIR64__(v52, v51));
                  v129.m[1] = v129.m[1] * (float)((float)((float)1.0 / (float)v82) * (float)__SPAIR64__(v52, v51));
                  v129.m[5] = v129.m[5] * (float)((float)((float)1.0 / (float)v82) * (float)__SPAIR64__(v52, v51));
                  v129.m[2] = v129.m[2] * (float)((float)((float)1.0 / (float)v82) * (float)__SPAIR64__(v52, v51));
                  v129.m[6] = v129.m[6] * (float)((float)((float)1.0 / (float)v82) * (float)__SPAIR64__(v52, v51));
                  v129.m[3] = v129.m[3] * (float)((float)((float)1.0 / (float)v82) * (float)__SPAIR64__(v52, v51));
                  v129.m[7] = v129.m[7] * (float)((float)((float)1.0 / (float)v82) * (float)__SPAIR64__(v52, v51));
                  idRenderMatrix::Multiply(a: &v129, b: &renderMatrix_windowSpaceToClipSpace, out: &v138);
                  idDeclRenderParm::Set(this: parms->rpWindowPosToDimShadowBlurS, plane: (const idPlane *)&v138);
                  idDeclRenderParm::Set(this: parms->rpWindowPosToDimShadowBlurT, plane: (const idPlane *)&v138.m[4]);
                  idDeclRenderParm::Set(this: parms->rpWindowPosToDimShadowBlurR, plane: (const idPlane *)&v138.m[8]);
                  idDeclRenderParm::Set(this: parms->rpWindowPosToDimShadowBlurQ, plane: (const idPlane *)&v138.m[12]);
                  if ( !v37 )
                  {
                    HIDWORD(v85) = *(_DWORD *)(v23 + 8) >> 8;
                    LODWORD(v85) = *(_DWORD *)v23;
                    idRenderLog::OpenBlock(
                      this: &renderLog,
                      fmt: v118,
                      a3: v85,
                      a4: v84,
                      a5: v83,
                      a6: v96,
                      a7: v97,
                      a8: v98,
                      a9: v99,
                      a10: v100,
                      a11: v101);
                    v86 = parms->settings;
                    v87 = (float)((float)((float)((float)1.0 - *(float *)(v23 + 1284)) * v86->dimShadowDensity)
                                * *(float *)(v23 + 172));
                    if ( !v86->dimShadowSkipRangeCulling )
                    {
                      v88 = (float)((float)1.0 - (float)((float)(v102 - (float)v18) / (float)((float)v17 - (float)v18)));
                      if ( v88 >= 0.0 )
                      {
                        if ( v88 > 1.0 )
                          v88 = 1.0;
                      }
                      else
                      {
                        v88 = 0.0;
                      }
                      v87 = (float)((float)v88
                                  * (float)((float)((float)((float)1.0 - *(float *)(v23 + 1284)) * v86->dimShadowDensity)
                                          * *(float *)(v23 + 172)));
                    }
                    idDeclRenderParm::Set(this: parms->rpDimShadowFade, v: v87);
                    idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v140);
                    if ( parms->settings->dimShadowDepthBoundsTest )
                      idPhysics_StaticMulti::UpdateTime(this: v89);
                    D3DDevice_SetRenderState_HiStencilEnable(pDevice: wrapperContext.d3d, Value: 1u);
                    D3DDevice_FlushHiZStencil(pDevice: wrapperContext.d3d, FlushType: D3DFHZS_SYNCHRONOUS);
                    if ( (_BYTE)v50 == 0 || parms->settings->dimShadowForceHighQuality == -1 )
                      progDimShadowDraw = parms->progDimShadowDraw;
                    else
                      progDimShadowDraw = parms->progDimShadowDrawHighQuality;
                    renamed = progDimShadowDraw->renamed;
                    v122.objectPtr = parms->extrudeBox;
                    v108.objectPtr = renamed;
                    GL_DrawElements(prog: &v108, tri: &v122, extraState: 0, skipDetailTriangles: v90);
                    D3DDevice_SetRenderState_HiStencilEnable(pDevice: wrapperContext.d3d, Value: 0);
                    if ( parms->settings->dimShadowDepthBoundsTest )
                      idPhysics_StaticMulti::UpdateTime(this: v94);
                    if ( parms->settings->showDimShadows != 0 )
                    {
                      v95 = parms->extrudeBox;
                      v124.objectPtr = parms->progDimShadowDebugDraw;
                      v126.objectPtr = v95;
                      GL_DrawElements(prog: &v124, tri: &v126, extraState: 0x80000000000uLL, skipDetailTriangles: v93);
                    }
                    if ( renderLog.logFile != nullptr )
                      idRenderLog::LogCloseBlock(this: &renderLog, label: RENDER_LOG_INDENT_BLOCK);
                  }
                }
                else
                {
                  idRenderLog::Printf(this: &renderLog, fmt: v123, *(_DWORD *)(v23 + 8) >> 8, *(_DWORD *)v23);
                }
              }
            }
          }
          v21 = 0.0;
        }
      }
      else if ( v25 <= -v28 )
      {
        goto LABEL_45;
      }
LABEL_119:
      v22 = ++v3;
    }
    while ( v3 < v107 );
  }
  D3DDevice_FlushHiZStencil(pDevice: wrapperContext.d3d, FlushType: D3DFHZS_SYNCHRONOUS);
  *parms->numDimShadows = v105;
  idRenderLog::CloseMainBlock(this: &renderLog);
}

