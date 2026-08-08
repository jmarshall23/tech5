
// ========================================================================
// ?InterpretOcclusionQuery@@YA_NPBUrenderSettings_t@@PBVidRenderView@@_J_NPAH@Z
// EA  : 0x828DDA98
// RVA : 0x008DDA98
// PDB : w:\tech5\engine\renderer\jobs\render\rendergather.cpp
// ========================================================================

int __fastcall InterpretOcclusionQuery(
        __int64 renderView,
        __int64 occlusionQuery,
        signed int *forceAccept,
        int *queryResult)
{
  int v4; // r31
  int v6; // r31
  signed int DeferredQueryResult; // r30
  int result; // r3

  v4 = HIDWORD(renderView);
  if ( *(_WORD *)(renderView + 1944) != 0 || (_BYTE)occlusionQuery != 0 )
  {
    v6 = 1;
    DeferredQueryResult = 1;
    idRenderLog::Printf(this: &renderLog, fmt: "in bounds or forcibly accepted\n");
  }
  else if ( SHIDWORD(occlusionQuery) >= *(_DWORD *)(renderView + 4460) )
  {
    HIDWORD(renderView) = HIDWORD(occlusionQuery);
    DeferredQueryResult = GL_GetDeferredQueryResult(queryNumber: renderView);
    if ( DeferredQueryResult >= 0 )
    {
      if ( DeferredQueryResult >= *(_DWORD *)(v4 + 80) )
      {
        idRenderLog::Printf(this: &renderLog, fmt: "occlusion test passed\n");
        v6 = 1;
      }
      else
      {
        idRenderLog::Printf(this: &renderLog, fmt: "occlusion test failed\n");
        v6 = 0;
      }
    }
    else
    {
      idRenderLog::Printf(this: &renderLog, fmt: "occlusion test overflow, assumed visible\n");
      v6 = 1;
    }
  }
  else
  {
    idRenderLog::Printf(this: &renderLog, fmt: "no query on previous frame, assumed visible\n");
    v6 = 1;
    DeferredQueryResult = 1;
  }
  result = v6;
  if ( forceAccept != nullptr )
    *forceAccept = DeferredQueryResult;
  return result;
}


// ========================================================================
// ?RenderGather@@YAXPBUrenderGatherParms_t@@@Z
// EA  : 0x828DDBB0
// RVA : 0x008DDBB0
// PDB : w:\tech5\engine\renderer\jobs\render\rendergather.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall RenderGather(const renderGatherParms_t *parms)
{
  int *numViewWorldAreas; // r25
  viewWorldArea_t *viewWorldAreas; // r16
  int *numViewWorldSurfaces; // r10
  const idRenderModelSurface **viewWorldSurfaces; // r15
  int *v6; // r24
  const idRenderModelCommitted **viewModels; // r21
  int *numSceneModels; // r9
  const idRenderModelCommitted **sceneModels; // r10
  __int64 v10; // r8
  int *numViewAugmentModels; // r10
  const idRenderModelCommitted **viewAugmentModels; // r22
  int *numViewLights; // r10
  const idRenderLightCommitted **viewLights; // r9
  int *numOcclusionTestWorldAreas; // r10
  int *occlusionTestWorldAreas; // r9
  __int64 v17; // r10
  const idRenderLightCommitted **occlusionTestLights; // r11
  int v19; // r26
  unsigned __int8 *v20; // r27
  __int64 v21; // r6
  int v22; // r28
  int v23; // r22
  int v25; // r26
  int areaNum; // r27
  const renderSettings_t *settings; // r9
  int indentLevel; // r11
  const worldArea_t *v30; // r28
  int num; // r24
  int v33; // r19
  const renderSettings_t *v35; // r3 OVERLAPPED
  int v36; // r11
  int nodeOcclusionTestIndex; // r11
  int v38; // r7
  int v39; // r11
  int v40; // r10
  int v41; // r11
  const idRenderModelSurface **v42; // r9
  idRenderModelSurface *v43; // r8
  viewWorldArea_t *v44; // r11
  _DWORD *v45; // r23
  _DWORD *v46; // r22
  unsigned int v47; // r9
  int index; // r11
  unsigned int v49; // r27
  int v50; // r10
  const renderSettings_t *v51; // r11
  int singleModel; // r10
  const idRenderModelCommitted *v53; // r28
  int allowSurfaceOnlyInViewID; // r11
  int suppressSurfaceInViewID; // r11
  char v59; // cr56
  char v60; // cr57
  char v61; // cr58
  char v62; // cr59
  int *v63; // r8
  const renderSettings_t *v64; // r3 OVERLAPPED
  occlusionState_t *occlusionState; // r11
  _BYTE v66[12]; // r6 OVERLAPPED
  signed int *v67; // r7
  char v68; // r11
  int v69; // r26
  occlusionState_t *v70; // r11
  int v71; // r9
  int *v72; // r10
  int renderFrameNumber; // r8
  int v74; // r11
  int v75; // r11
  int v76; // r11
  int v77; // r11
  int v78; // r22
  idRenderIndex *v79; // r26
  int v80; // r23
  int v81; // r21
  int v82; // r24
  _DWORD *v84; // r25
  unsigned int v85; // r9
  int v86; // r11
  unsigned int v87; // r27
  int v88; // r10
  const renderSettings_t *v89; // r11
  int singleLight; // r10
  const idRenderLightCommitted *v91; // r28
  int allowLightOnlyInViewID; // r11
  int suppressLightInViewID; // r11
  int *v94; // r8
  char v98; // cr56
  char v99; // cr57
  char v100; // cr58
  char v101; // cr59
  const renderSettings_t *v102; // r3 OVERLAPPED
  _BYTE v103[12]; // r6 OVERLAPPED
  char v104; // r11
  char v105; // r3
  int v106; // r10
  int v107; // r10
  int numNodeWorldAreas; // r10
  const renderSettings_t *v109; // r11
  int v110; // r15
  int v111; // r16
  int v112; // r20
  const idRenderModelCommitted *addAlwaysModels; // r28
  _DWORD *v114; // r25
  _DWORD *v115; // r24
  idRenderModelCommitted *nextAddAlwaysModel; // r26
  int v117; // r9
  occlusionState_t *v118; // r11
  unsigned int v119; // r10
  int v120; // r7
  int v121; // r8
  __int64 v122; // r4 OVERLAPPED
  occlusionState_t *v123; // r10
  const renderSettings_t *v124; // r11
  int v125; // r11
  int v126; // r11
  int v127; // r8
  occlusionState_t *v128; // r11
  unsigned int v129; // r10
  int v130; // r10
  occlusionState_t *v131; // r11
  unsigned int v132; // r9
  int v133; // r7
  int v134; // r8
  unsigned int v135; // r10
  int v136; // r10
  int v137; // r28
  int v138; // r23
  int v139; // r27
  int v140; // r9
  int v141; // r11
  int *v142; // r10
  int v143; // r9
  int v144; // r11
  _DWORD *v145; // r10
  _BYTE v146[12]; // r6 OVERLAPPED
  int v147; // [sp+8h] [-E98h]
  int v148; // [sp+Ch] [-E94h]
  int v149; // [sp+10h] [-E90h]
  int v150; // [sp+14h] [-E8Ch]
  int v151; // [sp+18h] [-E88h]
  int v152; // [sp+1Ch] [-E84h]
  unsigned int v153; // [sp+50h] [-E50h]
  const idRenderModelCommitted *referenceModel; // [sp+50h] [-E50h]
  unsigned __int8 *v155; // [sp+54h] [-E4Ch]
  int v156; // [sp+58h] [-E48h]
  int v157; // [sp+58h] [-E48h]
  int i; // [sp+5Ch] [-E44h]
  int v159; // [sp+60h] [-E40h]
  int v160; // [sp+64h] [-E3Ch]
  unsigned __int8 *temp; // [sp+68h] [-E38h]
  int v162; // [sp+6Ch] [-E34h]
  unsigned __int8 v163; // [sp+70h] [-E30h] BYREF
  unsigned __int8 v164; // [sp+71h] [-E2Fh]
  char v165; // [sp+72h] [-E2Eh]
  unsigned __int8 v166; // [sp+73h] [-E2Dh] BYREF
  unsigned __int8 v167[4]; // [sp+74h] [-E2Ch] BYREF
  const char *v168; // [sp+78h] [-E28h]
  const char *v169; // [sp+7Ch] [-E24h]
  int v170; // [sp+80h] [-E20h]
  const char *v171; // [sp+84h] [-E1Ch]
  int *v172; // [sp+88h] [-E18h]
  const idRenderModelCommitted **v173; // [sp+8Ch] [-E14h]
  const idRenderLightCommitted **v174; // [sp+90h] [-E10h]
  int *numViewModels; // [sp+94h] [-E0Ch]
  int *v176; // [sp+98h] [-E08h]
  int v177; // [sp+A0h] [-E00h]
  __int64 v178; // [sp+A4h] [-DFCh]
  int v179; // [sp+ACh] [-DF4h]
  const idRenderModelCommitted **v180; // [sp+B0h] [-DF0h]
  int v181; // [sp+C0h] [-DE0h]
  int *v182; // [sp+C4h] [-DDCh]
  int *v183; // [sp+C8h] [-DD8h]
  int v184; // [sp+CCh] [-DD4h]
  int v185; // [sp+D0h] [-DD0h]
  const idRenderModelCommitted **v186; // [sp+D4h] [-DCCh]
  int *v187; // [sp+D8h] [-DC8h]
  int v188; // [sp+DCh] [-DC4h]
  int v189; // [sp+E0h] [-DC0h]
  const idRenderLightCommitted **v190; // [sp+E4h] [-DBCh]
  int *v191; // [sp+E8h] [-DB8h]
  int v192; // [sp+ECh] [-DB4h]
  const idRenderLightCommitted **v193; // [sp+F0h] [-DB0h]
  int v194; // [sp+100h] [-DA0h]
  const idRenderModelCommitted **v195; // [sp+104h] [-D9Ch]
  int *v196; // [sp+108h] [-D98h]
  int v197; // [sp+10Ch] [-D94h]
  int v198; // [sp+110h] [-D90h]
  const idRenderModelSurface **v199; // [sp+114h] [-D8Ch]
  int *v200; // [sp+118h] [-D88h]
  int v201; // [sp+11Ch] [-D84h]
  int *v202; // [sp+120h] [-D80h]
  int v203; // [sp+130h] [-D70h]
  viewWorldArea_t *v204; // [sp+134h] [-D6Ch]
  int *v205; // [sp+138h] [-D68h]
  int v206; // [sp+13Ch] [-D64h]
  int *v207; // [sp+140h] [-D60h]
  const char *v208; // [sp+144h] [-D5Ch]
  const char *v209; // [sp+148h] [-D58h]
  int *v210; // [sp+14Ch] [-D54h]
  const char *v211; // [sp+150h] [-D50h]
  const idRenderModelCommitted **v212; // [sp+154h] [-D4Ch]
  int *v213; // [sp+158h] [-D48h]
  const char *v214; // [sp+15Ch] [-D44h]
  int *v215; // [sp+160h] [-D40h]
  int *v216; // [sp+164h] [-D3Ch]
  int *v217; // [sp+168h] [-D38h]
  int v218; // [sp+170h] [-D30h]
  const idRenderLightCommitted **v219; // [sp+174h] [-D2Ch]
  int v220; // [sp+178h] [-D28h]
  int v221; // [sp+17Ch] [-D24h]
  int v222; // [sp+180h] [-D20h]
  const idRenderModelCommitted **v223; // [sp+184h] [-D1Ch]
  int *v224; // [sp+188h] [-D18h]
  int v225; // [sp+18Ch] [-D14h]
  idBounds v226; // [sp+190h] [-D10h] BYREF
  idRenderMatrix v227; // [sp+1B0h] [-CF0h] BYREF
  idRenderMatrix v228; // [sp+1F0h] [-CB0h] BYREF
  idRenderMatrix v229; // [sp+230h] [-C70h] BYREF
  idRenderMatrix v230; // [sp+270h] [-C30h] BYREF
  idRenderMatrix v231; // [sp+2B0h] [-BF0h] BYREF
  _DWORD v232[64]; // [sp+2F0h] [-BB0h] BYREF
  _DWORD v233[128]; // [sp+3F0h] [-AB0h] BYREF
  _DWORD v234[514]; // [sp+5F0h] [-8B0h] BYREF

  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_GATHER_MODELS_AND_LIGHTS);
  v160 = 0;
  v159 = 0;
  v156 = 0;
  v162 = 0;
  temp = parms->temp;
  v155 = parms->temp + 512;
  do
  {
    __asm { dcbz128   r11, r10 }
    v156 += 128;
  }
  while ( v156 < 512 );
  for ( i = 0; i < 512; i += 128 )
    __asm { dcbz128   r11, r10 }
  numViewWorldAreas = parms->numViewWorldAreas;
  viewWorldAreas = parms->viewWorldAreas;
  v203 = 0;
  v206 = 0x2000;
  v172 = numViewWorldAreas;
  v205 = numViewWorldAreas;
  v204 = viewWorldAreas;
  numViewWorldSurfaces = parms->numViewWorldSurfaces;
  viewWorldSurfaces = parms->viewWorldSurfaces;
  v198 = 0;
  v201 = 0x2000;
  v210 = numViewWorldSurfaces;
  v200 = numViewWorldSurfaces;
  v199 = viewWorldSurfaces;
  viewModels = parms->viewModels;
  numViewModels = parms->numViewModels;
  v6 = numViewModels;
  v188 = 4096;
  v180 = viewModels;
  v187 = numViewModels;
  v186 = viewModels;
  numSceneModels = parms->numSceneModels;
  sceneModels = parms->sceneModels;
  v10 = 0x20000000040LL;
  v222 = 0;
  v225 = 64;
  v216 = numSceneModels;
  v212 = sceneModels;
  v224 = numSceneModels;
  v223 = sceneModels;
  numViewAugmentModels = parms->numViewAugmentModels;
  viewAugmentModels = parms->viewAugmentModels;
  v194 = 0;
  v197 = 32;
  v217 = numViewAugmentModels;
  v173 = viewAugmentModels;
  v196 = numViewAugmentModels;
  v195 = viewAugmentModels;
  numViewLights = parms->numViewLights;
  viewLights = parms->viewLights;
  v189 = 0;
  v192 = 4096;
  v207 = numViewLights;
  v174 = viewLights;
  v191 = numViewLights;
  v190 = viewLights;
  numOcclusionTestWorldAreas = parms->numOcclusionTestWorldAreas;
  occlusionTestWorldAreas = parms->occlusionTestWorldAreas;
  v181 = 0;
  v184 = 4096;
  v215 = numOcclusionTestWorldAreas;
  v176 = occlusionTestWorldAreas;
  v183 = numOcclusionTestWorldAreas;
  v182 = occlusionTestWorldAreas;
  v17 = *(_QWORD *)&parms->occlusionTestModels;
  v177 = 0;
  v179 = 4096;
  v157 = HIDWORD(v17);
  v202 = (int *)v17;
  v178 = v17;
  LODWORD(v17) = parms->numOcclusionTestLights;
  occlusionTestLights = parms->occlusionTestLights;
  v218 = 0;
  v221 = 512;
  v213 = (int *)v17;
  v193 = occlusionTestLights;
  v220 = v17;
  v219 = occlusionTestLights;
  v19 = 1;
  v20 = temp;
  v21 = (unsigned int)*viewModels;
  v169 = (const char *)viewModels;
  v185 = 1;
  v170 = 0;
  *viewModels = (const idRenderModelCommitted *)v21;
  v22 = 0;
  if ( parms->numNodeWorldAreas > 0 )
  {
    v169 = "light %i\n";
    v214 = "dynamic model not rendered because geometry is potentially stale\n";
    v168 = "outside max visible range\n";
    v211 = "model %i: %s\n";
    v171 = "added for occlusion test only\n";
    v23 = 0;
    v209 = "world surfaces\n";
    _R14 = 208;
    v208 = "areaNum %i\n";
    while ( 1 )
    {
      v25 = v22;
      areaNum = parms->nodeWorldAreas[v22].areaNum;
      idRenderLog::Printf(this: &renderLog, fmt: v208, areaNum);
      if ( renderLog.logFile != nullptr )
      {
        HIDWORD(v10) = (char *)&renderLog.indentLabel[19] + 1;
        LODWORD(v21) = (char *)&renderLog.indentLabel[19] + 2;
        HIDWORD(v21) = (char *)&renderLog.indentLabel[19] + 3;
        renderLog.indentLabel[renderLog.indentLevel++] = RENDER_LOG_INDENT_DEFAULT;
        HIBYTE(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
        BYTE1(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
        BYTE2(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
        LOBYTE(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
        renderLog.indentString[4 * renderLog.indentLevel] = 0;
      }
      settings = parms->settings;
      if ( settings->skipAreaCPUCulling || parms->worldAreaSubspaceBoundsCulled[areaNum] == 0 )
      {
        v30 = &parms->worldAreas[areaNum];
        _R25 = v30->modelRefs.list;
        num = v30->modelRefs.num;
        __asm { dcbt      0, r25 }
        v33 = v30->drawLightRefs.num;
        _R21 = v30->drawLightRefs.list;
        __asm { dcbt      0, r21 }
        if ( !settings->skipWorld )
        {
          idRenderLog::Printf(this: &renderLog, fmt: v209);
          if ( renderLog.logFile != nullptr )
          {
            renderLog.indentLabel[renderLog.indentLevel++] = RENDER_LOG_INDENT_DEFAULT;
            HIBYTE(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
            BYTE1(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
            BYTE2(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
            LOBYTE(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
            renderLog.indentString[4 * renderLog.indentLevel] = 0;
          }
          v35 = parms->settings;
          if ( v35->skipAreaCPUCulling || parms->worldAreaGeometryBoundsCulled[areaNum] != 3 )
          {
            *(_QWORD *)v146 = parms->occlusionState->worldAreaOcclusionQuery[areaNum];
            if ( (_cntlzw(parms->worldAreaGeometryBoundsCulled[areaNum]) & 0x20) != 0
              || (*(_DWORD *)&v146[8] = 0, v35->skipAreaGPUCulling) )
            {
              *(_DWORD *)&v146[8] = 1;
            }
            *(_DWORD *)v146 = parms->renderView;
            if ( (unsigned __int8)InterpretOcclusionQuery(
                                    renderView: *(__int64 *)&v146[8],
                                    occlusionQuery: *(__int64 *)&v146[4],
                                    forceAccept: nullptr,
                                    queryResult: (int *)(areaNum + 64)) != 0 )
            {
              nodeOcclusionTestIndex = parms->nodeWorldAreas[v25].nodeOcclusionTestIndex;
              if ( nodeOcclusionTestIndex >= 0 )
                parms->occlusionTestNodes[nodeOcclusionTestIndex] = -1;
              v38 = v203;
              if ( v203 < 0x2000 )
              {
                v39 = v30->worldSurfaces.num;
                if ( v39 + v23 <= 0x2000 )
                {
                  v40 = 0;
                  if ( v39 > 0 )
                  {
                    v41 = 0;
                    v42 = &viewWorldSurfaces[v23 - 1];
                    do
                    {
                      ++v40;
                      ++v23;
                      v43 = &v30->worldSurfaces.list[v41++];
                      *++v42 = v43;
                    }
                    while ( v40 < v30->worldSurfaces.num );
                    v198 = v23;
                  }
                  v44 = &viewWorldAreas[v38];
                  v203 = v38 + 1;
                  v44->areaNum = areaNum;
                  v44->numSurfs = v30->worldSurfaces.num;
                  v44->skipDetailTriangles = (_cntlzw((unsigned __int8)parms->worldAreaGeometryBoundsCulled[areaNum] - 2)
                                            & 0x20) != 0;
                }
              }
              idRenderLog::Printf(this: &renderLog, fmt: "added to view\n");
            }
            else
            {
              v36 = v181;
              if ( v181 < 4096 )
              {
                ++v181;
                v176[v36] = areaNum;
              }
              idRenderLog::Printf(this: &renderLog, fmt: v171);
            }
          }
          else
          {
            idRenderLog::Printf(this: &renderLog, fmt: "MVP culled\n");
          }
          if ( renderLog.logFile != nullptr && renderLog.indentLevel > 0 )
          {
            --renderLog.indentLevel;
            renderLog.indentString[4 * renderLog.indentLevel] = 0;
          }
        }
        if ( !parms->settings->skipModels && num > 0 )
        {
          v45 = &v234[v160 - 1];
          v46 = &v233[v159 - 1];
          do
          {
            v47 = _R25->index >> 11;
            index = (unsigned __int8)_R25->index;
            v49 = _R25->index >> 8;
            v50 = temp[v47];
            LODWORD(v21) = v50 & index;
            if ( (v50 & index) == 0 )
            {
              HIDWORD(v10) = temp[v47] | index;
              temp[v47] = v50 | index;
              v51 = parms->settings;
              singleModel = v51->singleModel;
              if ( singleModel < 0 || singleModel == v49 )
              {
                v53 = parms->linkedRenderModels[v49];
                if ( v51->skipSuppress
                  || ((allowSurfaceOnlyInViewID = v53->r.allowSurfaceOnlyInViewID) == 0
                   || allowSurfaceOnlyInViewID == parms->renderView->r.viewID)
                  && ((suppressSurfaceInViewID = v53->r.suppressSurfaceInViewID) == 0
                   || suppressSurfaceInViewID != parms->renderView->r.viewID) )
                {
                  if ( renderLog.activeLevel != 0 )
                  {
                    idRenderLog::Printf(this: &renderLog, fmt: v211, v49, v53->name);
                    if ( renderLog.logFile != nullptr )
                    {
                      renderLog.indentLabel[renderLog.indentLevel++] = RENDER_LOG_INDENT_DEFAULT;
                      HIBYTE(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
                      BYTE1(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
                      BYTE2(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
                      LOBYTE(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
                      renderLog.indentString[4 * renderLog.indentLevel] = 0;
                    }
                  }
                  _R10 = parms->settings;
                  if ( _R10->skipModelRangeCulling )
                    goto LABEL_58;
                  _R11 = &v53->maxVisibleRange;
                  __asm { lvx128    v63, r10, r14 }
                  _R9 = 16;
                  __asm
                  {
                    lvlx128   v62, r0, r11
                    lvrx128   v61, r9, r11
                    vor128    v60, v94, v61
                    vsubfp128 v59, v92, v63
                    vspltw128 v58, v60, 3
                    vsubfp128 v57, v95, v60
                    vmaxfp128 v56, v89, v59
                    vcmpgtfp128. v55, v88, v58
                  }
                  if ( (~((unsigned __int8)((v59 << 7) | (v60 << 6) | (32 * v61)) | (unsigned __int8)(16 * v62)) & 0x20) == 0 )
                  {
LABEL_58:
                    SetupModelMVPMatrix(
                      mvpMatrix: &v227,
                      model: v53,
                      renderView: parms->renderView,
                      zNear: parms->settings->viewNearZ,
                      zFar: parms->settings->viewFarZ);
                    if ( parms->settings->skipModelCPUCulling
                      || !idRenderMatrix::CullBoundsToMVPbits(
                            mvp: &v227,
                            b: &v53->referenceBounds,
                            outBits: v167,
                            zeroToOne: false) )
                    {
                      v53->mvpMatrix = v227;
                      v64 = parms->settings;
                      occlusionState = parms->occlusionState;
                      *(_QWORD *)v66 = occlusionState->modelOcclusionQuery[v49];
                      v67 = &occlusionState->modelOcclusionQueryResult[v49];
                      if ( v64->viewBounds.b[1].x < (double)v53->globalReferenceBounds.b[0].x
                        || v64->viewBounds.b[1].y < (double)v53->globalReferenceBounds.b[0].y
                        || v64->viewBounds.b[1].z < (double)v53->globalReferenceBounds.b[0].z
                        || v64->viewBounds.b[0].x > (double)v53->globalReferenceBounds.b[1].x
                        || v64->viewBounds.b[0].y > (double)v53->globalReferenceBounds.b[1].y
                        || (v68 = 1, v64->viewBounds.b[0].z > (double)v53->globalReferenceBounds.b[1].z) )
                      {
                        v68 = 0;
                      }
                      if ( v68 != 0
                        || v64->skipModelGPUCulling
                        || (*(_DWORD *)&v66[8] = 0, (*((_BYTE *)&v53->r + 106) & 0x10) != 0) )
                      {
                        *(_DWORD *)&v66[8] = 1;
                      }
                      *(_DWORD *)v66 = parms->renderView;
                      v69 = (unsigned __int8)InterpretOcclusionQuery(
                                               renderView: *(__int64 *)&v66[8],
                                               occlusionQuery: *(__int64 *)&v66[4],
                                               forceAccept: v67,
                                               queryResult: v63);
                      if ( v69 != 0 )
                      {
                        v70 = parms->occlusionState;
                        v71 = 0;
                        v72 = &v70->modelVisibleFrameNumber[v49];
                        renderFrameNumber = v70->renderFrameNumber;
                        if ( *v72 >= renderFrameNumber )
                          v71 = v70->modelVisibleFrameCount[v49];
                        *v72 = renderFrameNumber + 1;
                        v70->modelVisibleFrameCount[v49] = v71 + 1;
                        if ( (*((_BYTE *)&v53->r + 104) & 0x20) == 0 )
                        {
                          v164 = ((((v71 + 1) ^ v53->r.firstVisibleFrameCount) >= 0)
                                + (v53->r.firstVisibleFrameCount >= (unsigned int)(v71 + 1)))
                               & 1;
                          v69 = v164;
                          if ( v164 == 0 )
                            idRenderLog::Printf(this: &renderLog, fmt: v214);
                        }
                        if ( v69 != 0 )
                          goto LABEL_222;
                      }
                      if ( (*((_BYTE *)&v53->r + 106) & 8) != 0 )
                      {
LABEL_222:
                        if ( (*((_BYTE *)&v53->r + 106) & 4) != 0 )
                        {
                          v75 = v177;
                          if ( v177 < 4096 )
                          {
                            ++v177;
                            *(_DWORD *)(4 * v75 + v157) = v53;
                          }
                        }
                        if ( (*((_BYTE *)&v53->r + 104) & 4) != 0 )
                        {
                          v76 = v222;
                          if ( v222 < 64 )
                          {
                            ++v222;
                            v212[v76] = v53;
                          }
                        }
                        else if ( (*((_BYTE *)&v53->r + 104) & 0x20) != 0 )
                        {
                          v77 = v185;
                          if ( v185 < 4096 )
                          {
                            ++v185;
                            v180[v77] = v53;
                          }
                        }
                        else if ( (*((_BYTE *)&v53->r + 106) & 8) != 0 )
                        {
                          if ( v159 < 128 )
                          {
                            *++v46 = v53;
                            ++v159;
                          }
                        }
                        else if ( v160 < 512 )
                        {
                          *++v45 = v53;
                          ++v160;
                        }
                        idRenderLog::Printf(this: &renderLog, fmt: "added to view\n");
                      }
                      else
                      {
                        v74 = v177;
                        if ( v177 < 4096 )
                        {
                          ++v177;
                          *(_DWORD *)(4 * v74 + v157) = v53;
                        }
                        idRenderLog::Printf(this: &renderLog, fmt: v171);
                      }
                    }
                    else
                    {
                      idRenderLog::Printf(this: &renderLog, fmt: "MVP culled\n");
                    }
                  }
                  else
                  {
                    idRenderLog::Printf(this: &renderLog, fmt: v168);
                  }
                  if ( renderLog.logFile != nullptr && renderLog.indentLevel > 0 )
                  {
                    --renderLog.indentLevel;
                    renderLog.indentString[4 * renderLog.indentLevel] = 0;
                  }
                }
              }
            }
            --num;
            ++_R25;
          }
          while ( num != 0 );
        }
        if ( !parms->settings->skipLights && v33 > 0 )
        {
          v78 = v162;
          v79 = _R21;
          v80 = v218;
          v81 = v189;
          v82 = v33;
          _R19 = 16;
          v84 = &v232[v162 - 1];
          do
          {
            v85 = v79->index >> 11;
            v86 = (unsigned __int8)v79->index;
            v87 = v79->index >> 8;
            v88 = v155[v85];
            HIDWORD(v10) = v88 & v86;
            if ( (v88 & v86) == 0 )
            {
              v155[v85] = v88 | v86;
              v89 = parms->settings;
              singleLight = v89->singleLight;
              if ( singleLight < 0 || singleLight == v87 )
              {
                v91 = parms->linkedRenderLights[v87];
                if ( v89->skipSuppress
                  || ((allowLightOnlyInViewID = v91->r.allowLightOnlyInViewID) == 0
                   || allowLightOnlyInViewID == parms->renderView->r.viewID)
                  && ((suppressLightInViewID = v91->r.suppressLightInViewID) == 0
                   || suppressLightInViewID != parms->renderView->r.viewID) )
                {
                  idRenderLog::Printf(this: &renderLog, fmt: v169, v87);
                  if ( renderLog.logFile != nullptr )
                  {
                    renderLog.indentLabel[renderLog.indentLevel++] = RENDER_LOG_INDENT_DEFAULT;
                    HIBYTE(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
                    BYTE1(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
                    BYTE2(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
                    LOBYTE(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
                    v94 = (int *)(4 * renderLog.indentLevel);
                    renderLog.indentString[4 * renderLog.indentLevel] = 0;
                  }
                  _R10 = parms->settings;
                  if ( _R10->skipLightRangeCulling )
                    goto LABEL_223;
                  _R11 = &v91->maxVisibleRange;
                  __asm { lvx128    v54, r10, r14 }
                  __asm
                  {
                    lvlx128   v53, r0, r11
                    lvrx128   v52, r19, r11
                    vor128    v51, v85, v52
                    vsubfp128 v50, v83, v54
                    vspltw128 v49, v51, 3
                    vsubfp128 v48, v86, v51
                    vmaxfp128 v47, v80, v50
                    vcmpgtfp128. v46, v79, v49
                  }
                  v94 = (int *)((~((unsigned __int8)((v98 << 7) | (v99 << 6) | (32 * v100))
                                 | (unsigned __int8)(16 * v101))
                               & 0x20) != 0);
                  if ( (~((unsigned __int8)((v98 << 7) | (v99 << 6) | (32 * v100)) | (unsigned __int8)(16 * v101)) & 0x20) == 0 )
                  {
LABEL_223:
                    if ( _R10->skipLightCPUCulling
                      || (idRenderMatrix::Multiply(
                            a: &parms->renderView->worldSpaceMVPMatrix,
                            b: &v91->inverseBaseLightProject,
                            out: &v229),
                          v226.b[0].x = 0.0,
                          v226.b[0].y = 0.0,
                          v226.b[0].z = 0.0,
                          v226.b[1].x = 1.0,
                          v226.b[1].y = 1.0,
                          v226.b[1].z = 1.0,
                          !idRenderMatrix::CullBoundsToMVPbits(mvp: &v229, b: &v226, outBits: &v166, zeroToOne: false)) )
                    {
                      v102 = parms->settings;
                      *(_QWORD *)v103 = parms->occlusionState->lightOcclusionQuery[v87];
                      if ( v102->viewBounds.b[1].x < (double)v91->globalReferenceBounds.b[0].x
                        || v102->viewBounds.b[1].y < (double)v91->globalReferenceBounds.b[0].y
                        || v102->viewBounds.b[1].z < (double)v91->globalReferenceBounds.b[0].z
                        || v102->viewBounds.b[0].x > (double)v91->globalReferenceBounds.b[1].x
                        || v102->viewBounds.b[0].y > (double)v91->globalReferenceBounds.b[1].y
                        || (v104 = 1, v102->viewBounds.b[0].z > (double)v91->globalReferenceBounds.b[1].z) )
                      {
                        v104 = 0;
                      }
                      if ( v104 != 0 || (*(_DWORD *)&v103[8] = 0, v102->skipLightGPUCulling) )
                        *(_DWORD *)&v103[8] = 1;
                      *(_DWORD *)v103 = parms->renderView;
                      v105 = InterpretOcclusionQuery(
                               renderView: *(__int64 *)&v103[8],
                               occlusionQuery: *(__int64 *)&v103[4],
                               forceAccept: nullptr,
                               queryResult: v94);
                      if ( v80 < 512 )
                      {
                        v106 = v80++;
                        v218 = v80;
                        v193[v106] = v91;
                      }
                      if ( v105 != 0 )
                      {
                        if ( v91->r.lightClass == LIGHT_BLENDED_ONLY )
                        {
                          if ( v78 < 64 )
                          {
                            *++v84 = v91;
                            ++v78;
                          }
                        }
                        else if ( v81 < 4096 )
                        {
                          v107 = v81++;
                          v189 = v81;
                          v174[v107] = v91;
                        }
                        idRenderLog::Printf(this: &renderLog, fmt: "added to view\n");
                      }
                      if ( renderLog.logFile != nullptr && renderLog.indentLevel > 0 )
                      {
                        --renderLog.indentLevel;
                        renderLog.indentString[4 * renderLog.indentLevel] = 0;
                      }
                    }
                    else
                    {
                      idRenderLog::Printf(this: &renderLog, fmt: "MVP culled\n");
                    }
                  }
                  else
                  {
                    idRenderLog::Printf(this: &renderLog, fmt: v168);
                  }
                }
              }
            }
            --v82;
            ++v79;
          }
          while ( v82 != 0 );
          v162 = v78;
        }
        if ( renderLog.logFile != nullptr )
        {
          indentLevel = renderLog.indentLevel;
          if ( renderLog.indentLevel > 0 )
          {
LABEL_147:
            renderLog.indentLevel = indentLevel - 1;
            HIBYTE(renderLog.indentLabel[indentLevel + 19]) = 0;
          }
        }
      }
      else
      {
        idRenderLog::Printf(this: &renderLog, fmt: "MVP culled\n");
        if ( renderLog.logFile != nullptr )
        {
          indentLevel = renderLog.indentLevel;
          if ( renderLog.indentLevel > 0 )
            goto LABEL_147;
        }
      }
      numNodeWorldAreas = parms->numNodeWorldAreas;
      v22 = v170 + 1;
      v170 = v22;
      if ( v22 >= numNodeWorldAreas )
      {
        viewModels = v180;
        viewAugmentModels = v173;
        HIDWORD(v17) = 0;
        v20 = temp;
        LODWORD(v10) = 0;
        numViewWorldAreas = v172;
        v6 = numViewModels;
        v19 = v185;
        break;
      }
      v23 = v198;
    }
  }
  v109 = parms->settings;
  v110 = v162;
  v111 = v159;
  v112 = v160;
  if ( v109->skipAddAlways )
  {
    v139 = v177;
    v138 = v189;
    v137 = v181;
  }
  else
  {
    LODWORD(v17) = v109->skipAddAlways;
    idRenderLog::OpenBlock(
      this: &renderLog,
      fmt: "AddAlways",
      a3: v21,
      a4: v10,
      a5: v17,
      a6: v147,
      a7: v148,
      a8: v149,
      a9: v150,
      a10: v151,
      a11: v152);
    addAlwaysModels = parms->addAlwaysModels;
    if ( addAlwaysModels != nullptr )
    {
      v114 = &v234[v160 - 1];
      v115 = &v233[v159 - 1];
      while ( 1 )
      {
        nextAddAlwaysModel = addAlwaysModels->nextAddAlwaysModel;
        v20[addAlwaysModels->index.index >> 11] |= addAlwaysModels->index.index;
        if ( (*((_BYTE *)&addAlwaysModels->r + 104) & 2) != 0 )
        {
          v124 = parms->settings;
          if ( !v124->skipAugment
            && (v124->skipSuppress
             || ((v125 = addAlwaysModels->r.allowSurfaceOnlyInViewID) == 0 || v125 == parms->renderView->r.viewID)
             && ((v126 = addAlwaysModels->r.suppressSurfaceInViewID) == 0 || v126 != parms->renderView->r.viewID)) )
          {
            referenceModel = addAlwaysModels->referenceModel;
            if ( referenceModel != nullptr )
            {
              if ( (*((_BYTE *)&addAlwaysModels->r + 104) & 1) == 0 )
                goto LABEL_181;
              v127 = 0;
              v128 = parms->occlusionState;
              v129 = referenceModel->index.index >> 8;
              if ( v128->modelVisibleFrameNumber[v129] >= v128->renderFrameNumber )
                v127 = v128->modelVisibleFrameCount[v129];
              if ( v127 <= referenceModel->r.firstVisibleFrameCount || v128->modelOcclusionQueryResult[v129] <= 0 )
              {
LABEL_181:
                SetupModelMVPMatrix(
                  mvpMatrix: &v228,
                  model: referenceModel,
                  renderView: parms->renderView,
                  zNear: parms->settings->viewNearZ,
                  zFar: parms->settings->viewFarZ);
                referenceModel->mvpMatrix = v228;
                if ( parms->settings->skipModelCPUCulling
                  || !idRenderMatrix::CullBoundsToMVPbits(
                        mvp: &v228,
                        b: &referenceModel->referenceBounds,
                        outBits: &v163,
                        zeroToOne: false) )
                {
                  v130 = 0;
                  v131 = parms->occlusionState;
                  v132 = addAlwaysModels->index.index >> 8;
                  v133 = 4 * (v132 + 41088);
                  v134 = v131->renderFrameNumber;
                  if ( *(_DWORD *)((char *)v131->nodeOcclusionQuery + v133) >= v134 )
                    v130 = v131->modelVisibleFrameCount[v132];
                  *(_DWORD *)((char *)v131->nodeOcclusionQuery + v133) = v134 + 1;
                  v135 = v130 + 1;
                  v173 = (const idRenderModelCommitted **)v135;
                  v131->modelVisibleFrameCount[v132] = v135;
                  v165 = ((((v135 ^ (referenceModel->r.firstVisibleFrameCount + 1)) & 0x80000000) == 0)
                        + (referenceModel->r.firstVisibleFrameCount + 1 >= v135))
                       & 1;
                  if ( v165 != 0 )
                  {
                    SetupModelMVPMatrix(
                      mvpMatrix: &v231,
                      model: addAlwaysModels,
                      renderView: parms->renderView,
                      zNear: parms->settings->viewNearZ,
                      zFar: parms->settings->viewFarZ);
                    addAlwaysModels->mvpMatrix = v231;
                    v136 = v194;
                    if ( v194 < 30 )
                    {
                      ++v194;
                      viewAugmentModels[v136] = addAlwaysModels;
                    }
                  }
                }
              }
            }
          }
        }
        else
        {
          v117 = 0;
          v118 = parms->occlusionState;
          v119 = addAlwaysModels->index.index >> 8;
          v120 = 4 * (v119 + 41088);
          v121 = v118->renderFrameNumber;
          if ( *(_DWORD *)((char *)v118->nodeOcclusionQuery + v120) >= v121 )
            v117 = v118->modelVisibleFrameCount[v119];
          *(_DWORD *)((char *)v118->nodeOcclusionQuery + v120) = v121 + 1;
          v118->modelVisibleFrameCount[v119] = v117 + 1;
          if ( (*((_BYTE *)&addAlwaysModels->r + 104) & 0x20) != 0
            || (((((v117 + 1) ^ addAlwaysModels->r.firstVisibleFrameCount) >= 0)
               + (addAlwaysModels->r.firstVisibleFrameCount >= (unsigned int)(v117 + 1)))
              & 1) != 0 )
          {
            SetupModelMVPMatrix(
              mvpMatrix: &v230,
              model: addAlwaysModels,
              renderView: parms->renderView,
              zNear: parms->settings->viewNearZ,
              zFar: parms->settings->viewFarZ);
            addAlwaysModels->mvpMatrix = v230;
            if ( (*((_BYTE *)&addAlwaysModels->r + 106) & 2) != 0 )
            {
              v123 = parms->occlusionState;
              v153 = addAlwaysModels->index.index >> 8;
              *(__int64 *)((char *)&v122 + 4) = v123->modelOcclusionQuery[v153];
              if ( SHIDWORD(v122) >= SLODWORD(parms->renderView->firstOcclusionQueryInPreviousFrame) )
                parms->occlusionState->modelOcclusionQueryResult[addAlwaysModels->index.index >> 8] = GL_GetDeferredQueryResult(queryNumber: v122);
              else
                v123->modelOcclusionQueryResult[v153] = 0;
            }
            else
            {
              parms->occlusionState->modelOcclusionQueryResult[addAlwaysModels->index.index >> 8] = 0;
            }
            if ( (*((_BYTE *)&addAlwaysModels->r + 106) & 8) != 0 )
            {
              if ( v111 < 128 )
              {
                *++v115 = addAlwaysModels;
                ++v111;
              }
            }
            else if ( v112 < 512 )
            {
              *++v114 = addAlwaysModels;
              ++v112;
            }
          }
        }
        addAlwaysModels = nextAddAlwaysModel;
        if ( nextAddAlwaysModel == nullptr )
          break;
        v20 = temp;
      }
      numViewWorldAreas = v172;
      v6 = numViewModels;
      v19 = v185;
    }
    v137 = v181;
    v138 = v189;
    v139 = v177;
    if ( renderLog.logFile != nullptr )
      idRenderLog::LogCloseBlock(this: &renderLog, label: RENDER_LOG_INDENT_BLOCK);
  }
  if ( !parms->settings->skipDynamic )
  {
    if ( v112 >= 4096 - v19 )
      v112 = 4096 - v19;
    if ( v112 > 0 )
    {
      blkmov(a1: &viewModels[v19], a2: v234, a3: 4 * v112);
      v19 += v112;
      v185 = v19;
    }
    if ( v111 >= 4096 - v19 )
      v111 = 4096 - v19;
    if ( v111 > 0 )
    {
      blkmov(a1: &viewModels[v19], a2: v233, a3: 4 * v111);
      v19 += v111;
      v185 = v19;
    }
  }
  if ( v162 >= 4096 - v138 )
    v110 = 4096 - v138;
  if ( v110 > 0 )
  {
    blkmov(a1: &v174[v138], a2: v232, a3: 4 * v110);
    v138 += v110;
    v189 = v138;
  }
  if ( parms->settings->forceOcclusionBoxQueries )
  {
    v140 = 0;
    *numViewWorldAreas = v203;
    *v6 = v19;
    if ( *parms->numViewWorldAreas > 0 )
    {
      v141 = 0;
      v142 = &v176[v137 - 1];
      do
      {
        if ( v137 < 4096 )
        {
          ++v137;
          *++v142 = parms->viewWorldAreas[v141].areaNum;
        }
        ++v140;
        ++v141;
      }
      while ( v140 < *parms->numViewWorldAreas );
      v181 = v137;
    }
    v143 = 1;
    if ( *parms->numViewModels > 1 )
    {
      v144 = 1;
      v145 = (_DWORD *)(4 * v139 + v157 - 4);
      do
      {
        if ( v139 < 4096 )
        {
          ++v139;
          *++v145 = parms->viewModels[v144];
        }
        ++v143;
        ++v144;
      }
      while ( v143 < *parms->numViewModels );
      v177 = v139;
    }
  }
  idRenderLog::CloseMainBlock(this: &renderLog);
  *v213 = v218;
  *v202 = v139;
  *v215 = v137;
  *v207 = v138;
  *v217 = v194;
  *v216 = v222;
  *v6 = v19;
  *v210 = v198;
  *numViewWorldAreas = v203;
}


// ========================================================================
// __unwind$88007
// EA  : 0x828DF09C
// RVA : 0x008DF09C
// PDB : w:\tech5\engine\renderer\jobs\render\rendergather.cpp
// ========================================================================

void _unwind_88007()
{
  int v0; // r12

  idODSOutputArray<viewWorldArea_t,128>::~idODSOutputArray<viewWorldArea_t,128>(this: (idODSOutputArray<int,128> *)(v0 - 3744 + 304));
}


// ========================================================================
// __unwind$88008
// EA  : 0x828DF0C4
// RVA : 0x008DF0C4
// PDB : w:\tech5\engine\renderer\jobs\render\rendergather.cpp
// ========================================================================

void _unwind_88008()
{
  int v0; // r12

  idODSOutputArray<viewWorldArea_t,128>::~idODSOutputArray<viewWorldArea_t,128>(this: (idODSOutputArray<int,128> *)(v0 - 3744 + 272));
}


// ========================================================================
// __unwind$88009
// EA  : 0x828DF0EC
// RVA : 0x008DF0EC
// PDB : w:\tech5\engine\renderer\jobs\render\rendergather.cpp
// ========================================================================

void _unwind_88009()
{
  int v0; // r12

  idODSOutputArray<viewWorldArea_t,128>::~idODSOutputArray<viewWorldArea_t,128>(this: (idODSOutputArray<int,128> *)(v0 - 3744 + 208));
}


// ========================================================================
// __unwind$88010
// EA  : 0x828DF114
// RVA : 0x008DF114
// PDB : w:\tech5\engine\renderer\jobs\render\rendergather.cpp
// ========================================================================

void _unwind_88010()
{
  int v0; // r12

  idODSOutputArray<viewWorldArea_t,128>::~idODSOutputArray<viewWorldArea_t,128>(this: (idODSOutputArray<int,128> *)(v0 - 3744 + 384));
}


// ========================================================================
// __unwind$88011
// EA  : 0x828DF13C
// RVA : 0x008DF13C
// PDB : w:\tech5\engine\renderer\jobs\render\rendergather.cpp
// ========================================================================

void _unwind_88011()
{
  int v0; // r12

  idODSOutputArray<viewWorldArea_t,128>::~idODSOutputArray<viewWorldArea_t,128>(this: (idODSOutputArray<int,128> *)(v0 - 3744 + 256));
}


// ========================================================================
// __unwind$88012
// EA  : 0x828DF164
// RVA : 0x008DF164
// PDB : w:\tech5\engine\renderer\jobs\render\rendergather.cpp
// ========================================================================

void _unwind_88012()
{
  int v0; // r12

  idODSOutputArray<viewWorldArea_t,128>::~idODSOutputArray<viewWorldArea_t,128>(this: (idODSOutputArray<int,128> *)(v0 - 3744 + 224));
}


// ========================================================================
// __unwind$88013
// EA  : 0x828DF18C
// RVA : 0x008DF18C
// PDB : w:\tech5\engine\renderer\jobs\render\rendergather.cpp
// ========================================================================

void _unwind_88013()
{
  int v0; // r12

  idODSOutputArray<viewWorldArea_t,128>::~idODSOutputArray<viewWorldArea_t,128>(this: (idODSOutputArray<int,128> *)(v0 - 3744 + 192));
}


// ========================================================================
// __unwind$88014
// EA  : 0x828DF1B4
// RVA : 0x008DF1B4
// PDB : w:\tech5\engine\renderer\jobs\render\rendergather.cpp
// ========================================================================

void _unwind_88014()
{
  int v0; // r12

  idODSOutputArray<viewWorldArea_t,128>::~idODSOutputArray<viewWorldArea_t,128>(this: (idODSOutputArray<int,128> *)(v0 - 3744 + 160));
}


// ========================================================================
// __unwind$88015
// EA  : 0x828DF1DC
// RVA : 0x008DF1DC
// PDB : w:\tech5\engine\renderer\jobs\render\rendergather.cpp
// ========================================================================

void _unwind_88015()
{
  int v0; // r12

  idODSOutputArray<viewWorldArea_t,128>::~idODSOutputArray<viewWorldArea_t,128>(this: (idODSOutputArray<int,128> *)(v0 - 3744 + 368));
}


// ========================================================================
// `dynamic initializer for 'register_RenderGather''
// EA  : 0x8334C350
// RVA : 0x0134C350
// PDB : w:\tech5\engine\renderer\jobs\render\rendergather.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_RenderGather__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_RenderGather,
           function: (void (__fastcall *)(void *))RenderGather,
           name: "RenderGather");
}

