
// ========================================================================
// ?DrawDepthSurface@@YAXPBUrenderDepthParms_t@@ABV?$idODSObject@VidRenderModelCommitted@@@@ABV?$idODSObject@VidRenderModelSurface@@@@_N33AAM@Z
// EA  : 0x828DAD00
// RVA : 0x008DAD00
// PDB : w:\tech5\engine\renderer\jobs\render\renderdepth.cpp
// ========================================================================

void __fastcall DrawDepthSurface(
        const renderDepthParms_t *parms,
        const idODSObject<idRenderModelCommitted> *modelODS,
        const idODSObject<idRenderModelSurface> *surfaceODS,
        bool cullSurface,
        bool testOcclusion,
        BOOL skipDetailTriangles,
        float *sortOffset)
{
  const idRenderModelSurface *objectPtr; // r11
  const idMaterial *material; // r31
  const idBounds *p_bounds; // r4
  int *numDrawSurfs; // r11
  drawSurf_t *drawSurfs; // r9
  int v18; // r11
  drawSurf_t *v19; // r11
  int *v20; // r11
  drawSurf_t *v21; // r9
  int v22; // r11
  drawSurf_t *v23; // r11
  const idRenderModelCommitted *v24; // r9
  double v25; // fp0
  char v26; // r11
  int *v27; // r11
  drawSurf_t *v28; // r9
  int v29; // r11
  drawSurf_t *v30; // r11
  char v31; // r4
  const idRenderModelCommitted *v32; // r9
  const idDeclRenderProg *v33; // r8
  const idDeclRenderProg *v34; // r11
  int *v35; // r11
  drawSurf_t *v36; // r10
  int v37; // r11
  drawSurf_t *v38; // r11
  char v39; // r3
  const idRenderModelCommitted *v40; // r7
  const idRenderModelCommitted *v41; // r9
  const idDeclRenderProg *renamed; // r11
  const renderSettings_t *settings; // r10
  double v44; // fp0
  char v45; // r11
  int v46; // r29
  const idParmBlock *p_renderParmBlock; // r31
  bool v48; // r7
  unsigned __int8 v49[4]; // [sp+50h] [-50h] BYREF
  idODSObject<idDeclRenderProg> v50; // [sp+54h] [-4Ch] BYREF

  objectPtr = surfaceODS->objectPtr;
  material = surfaceODS->objectPtr->material;
  if ( material != nullptr )
  {
    p_bounds = &objectPtr->geometry->bounds;
    if ( p_bounds != nullptr
      && material->coverage != MC_INVISIBLE
      && (!cullSurface
       || (*((_BYTE *)&modelODS->objectPtr->r + 105) & 4) != 0
       || objectPtr->joints != nullptr
       || parms->settings->skipSurfaceCPUCulling
       || !idRenderMatrix::CullBoundsToMVPbits(
             mvp: &modelODS->objectPtr->mvpMatrix,
             b: p_bounds,
             outBits: v49,
             zeroToOne: false)) )
    {
      if ( material->progs[4] != nullptr )
      {
        numDrawSurfs = parms->numDrawSurfs;
        if ( *numDrawSurfs != 4096 )
        {
          drawSurfs = parms->drawSurfs;
          v18 = *numDrawSurfs;
          *parms->numDrawSurfs = v18 + 1;
          v19 = &drawSurfs[v18];
          v19->isWorld = (*((_BYTE *)&modelODS->objectPtr->r + 104) & 0x10) != 0;
          v19->skipDetailTriangles = skipDetailTriangles;
          v19->modelSurface = surfaceODS->objectPtr;
          v19->model = modelODS->objectPtr;
          v19->material = material;
          v19->sort = material->stageSort[4] + *sortOffset;
          v19->prog = material->progs[4];
          *sortOffset = *sortOffset + (float)0.000099999997;
        }
      }
      if ( material->progs[5] != nullptr )
      {
        v20 = parms->numDrawSurfs;
        if ( *v20 != 4096 )
        {
          v21 = parms->drawSurfs;
          v22 = *v20;
          *parms->numDrawSurfs = v22 + 1;
          v23 = &v21[v22];
          v23->isWorld = (*((_BYTE *)&modelODS->objectPtr->r + 104) & 0x10) != 0;
          v23->skipDetailTriangles = skipDetailTriangles;
          v23->modelSurface = surfaceODS->objectPtr;
          v24 = modelODS->objectPtr;
          v23->material = material;
          v23->model = v24;
          v23->sort = material->stageSort[5] + *sortOffset;
          v23->prog = material->progs[5];
          *sortOffset = *sortOffset + (float)0.000099999997;
        }
      }
      if ( (*((_BYTE *)material + 72) & 0x20) == 0
        || (*((_BYTE *)&modelODS->objectPtr->r + 104) & 0x10) == 0
        && (*((_BYTE *)&modelODS->objectPtr->r + 105) & 8) == 0
        || !parms->settings->isComboMap )
      {
        v25 = material->stageSort[6];
        if ( v25 < parms->settings->sortCoverage || (v26 = 1, v25 >= parms->settings->sortBackground) )
          v26 = 0;
        if ( material->progs[6] != nullptr && v26 == 0 )
        {
          v27 = parms->numDrawSurfs;
          if ( *v27 != 4096 )
          {
            v28 = parms->drawSurfs;
            v29 = *v27;
            *parms->numDrawSurfs = v29 + 1;
            v30 = &v28[v29];
            v31 = *((_BYTE *)&modelODS->objectPtr->r + 104);
            v30->skipDetailTriangles = skipDetailTriangles;
            v30->isWorld = (v31 & 0x10) != 0;
            v30->modelSurface = surfaceODS->objectPtr;
            v32 = modelODS->objectPtr;
            v30->material = material;
            v30->model = v32;
            v30->sort = material->stageSort[6] + *sortOffset;
            v30->prog = material->progs[6];
            *sortOffset = *sortOffset + (float)0.000099999997;
          }
        }
        if ( material->coverage == MC_TRANSLUCENT )
        {
          if ( !testOcclusion )
            return;
          v33 = material->progs[3];
        }
        else
        {
          v34 = material->progs[0];
          if ( v34 == nullptr )
            v34 = material->progs[6];
          v33 = v34;
        }
        if ( v33 != nullptr )
        {
          if ( modelODS->objectPtr->r.modelFade != 1.0 && material->progs[7] != nullptr )
          {
            v35 = parms->numDrawSurfs;
            if ( *v35 != 4096 )
            {
              v36 = parms->drawSurfs;
              v37 = *v35;
              *parms->numDrawSurfs = v37 + 1;
              v38 = &v36[v37];
              v39 = *((_BYTE *)&modelODS->objectPtr->r + 104);
              v38->skipDetailTriangles = skipDetailTriangles;
              v38->isWorld = (v39 & 0x10) != 0;
              v38->modelSurface = surfaceODS->objectPtr;
              v40 = modelODS->objectPtr;
              v38->material = material;
              v38->model = v40;
              v38->prog = material->progs[7];
              v38->sort = parms->settings->sortPerturber + *sortOffset;
              *sortOffset = *sortOffset + (float)0.000099999997;
            }
          }
          v41 = modelODS->objectPtr;
          renamed = v33->renamed;
          if ( (*((_BYTE *)&modelODS->objectPtr->r + 116) & 0x80) != 0 && renamed == parms->progOutside )
            renamed = parms->progRadiosityPreview;
          settings = parms->settings;
          v50.objectPtr = renamed;
          v44 = material->stageSort[6];
          if ( v44 < settings->sortSkybox || (v45 = 1, v44 >= settings->sortBackground) )
            v45 = 0;
          v46 = 0;
          if ( (*((_BYTE *)material + 72) & 0x40) != 0 || settings->forceTwoSidedDepth )
            v46 = 0x8000;
          if ( (*((_BYTE *)&v41->r + 104) & 8) != 0 || v45 != 0 )
            v46 |= 0x40u;
          if ( renderLog.activeLevel != 0 )
          {
            idRenderLog::Printf(this: &renderLog, fmt: "Entering material %s\n", material->name.str);
            idRenderLog::Indent(this: &renderLog, label: RENDER_LOG_INDENT_DEFAULT);
          }
          p_renderParmBlock = &material->renderParmBlock;
          idParmState::VirtualEvaluateParmBlock(
            this: renderThreadParmState,
            localParmBlock: p_renderParmBlock,
            parmBlock: p_renderParmBlock);
          idParmState::VirtualEvaluateParmBlock(
            this: renderThreadParmState,
            localParmBlock: &v50.objectPtr->parmBlock,
            parmBlock: &v50.objectPtr->parmBlock);
          GL_DrawElements(
            prog: &v50,
            surf: surfaceODS,
            extraState: __PAIR64__(v46, skipDetailTriangles),
            skipDetailTriangles: v48);
          idParmState::VirtualRollbackParmBlock(
            this: renderThreadParmState,
            localParmBlock: &v50.objectPtr->parmBlock,
            parmBlock: &v50.objectPtr->parmBlock);
          idParmState::VirtualRollbackParmBlock(
            this: renderThreadParmState,
            localParmBlock: p_renderParmBlock,
            parmBlock: p_renderParmBlock);
          if ( renderLog.activeLevel != 0 && renderLog.logFile != nullptr && renderLog.indentLevel > 0 )
          {
            --renderLog.indentLevel;
            renderLog.indentString[4 * renderLog.indentLevel] = 0;
          }
        }
      }
    }
  }
}


// ========================================================================
// ?DrawModelDepthSurfaces@@YAXPBUrenderDepthParms_t@@ABV?$idODSObject@VidRenderModelCommitted@@@@AAM@Z
// EA  : 0x828DB230
// RVA : 0x008DB230
// PDB : w:\tech5\engine\renderer\jobs\render\renderdepth.cpp
// ========================================================================

void __fastcall DrawModelDepthSurfaces(
        const renderDepthParms_t *parms,
        const idODSObject<idRenderModelCommitted> *modelODS,
        float *sortOffset)
{
  __int64 v6; // r8
  int v7; // r5
  __int64 v8; // r4
  const idRenderModelCommitted *objectPtr; // r10
  bool v10; // r11
  BOOL v11; // r24
  const idRenderModelCommitted *v12; // r11
  int v13; // r27
  int num; // r9
  bool v15; // r26
  int v16; // r29
  int singleSurface; // r10
  idODSObject<idRenderModelSurface> v18; // [sp+50h] [-50h] BYREF

  idParmState::SetModelMatrix(this: renderThreadParmState, modelMatrix: &modelODS->objectPtr->modelMatrix);
  idParmState::SetInverseModelMatrix(
    this: renderThreadParmState,
    inverseModelMatrix: &modelODS->objectPtr->inverseModelMatrix);
  idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &modelODS->objectPtr->mvpMatrix);
  idParmState::SetApproximateLighting(this: renderThreadParmState, lighting: &modelODS->objectPtr->approximateLighting);
  idParmState::SetHighlightColor(this: renderThreadParmState, highlightColor: &modelODS->objectPtr->highlightColor);
  idParmState::VirtualEvaluateParmBlock(
    this: renderThreadParmState,
    localParmBlock: &modelODS->objectPtr->renderParmBlock,
    parmBlock: &modelODS->objectPtr->renderParmBlock);
  objectPtr = modelODS->objectPtr;
  v10 = false;
  if ( (*((_BYTE *)&modelODS->objectPtr->r + 106) & 4) == 0 )
  {
    LODWORD(v6) = *((_BYTE *)&objectPtr->r + 105) & 4;
    if ( (*((_BYTE *)&objectPtr->r + 105) & 4) == 0 || (*((_BYTE *)&modelODS->objectPtr->r + 106) & 2) != 0 )
      v10 = true;
  }
  v11 = v10;
  if ( v10 )
  {
    HIDWORD(v8) = &parms->occlusionState->modelOcclusionQuery[objectPtr->index.index >> 8];
    GL_BeginQuery(queryNumber: v8, a2: v7, a3: v6);
  }
  v12 = modelODS->objectPtr;
  v13 = 0;
  num = modelODS->objectPtr->surfaces.num;
  v15 = ((num >= 0) + ((unsigned int)num <= 1)) & 1;
  if ( num > 0 )
  {
    v16 = 0;
    do
    {
      singleSurface = parms->settings->singleSurface;
      if ( singleSurface < 0 || singleSurface == v13 )
      {
        v18.objectPtr = &v12->surfaces.list[v16];
        DrawDepthSurface(
          parms,
          modelODS,
          surfaceODS: &v18,
          cullSurface: v15,
          testOcclusion: v11,
          skipDetailTriangles: false,
          sortOffset);
      }
      v12 = modelODS->objectPtr;
      ++v13;
      ++v16;
    }
    while ( v13 < modelODS->objectPtr->surfaces.num );
  }
  if ( v11 )
    GL_EndQuery();
  idParmState::VirtualRollbackParmBlock(
    this: renderThreadParmState,
    localParmBlock: &modelODS->objectPtr->renderParmBlock,
    parmBlock: &modelODS->objectPtr->renderParmBlock);
}


// ========================================================================
// ?RenderDepth@@YAXPBUrenderDepthParms_t@@@Z
// EA  : 0x828DB3C8
// RVA : 0x008DB3C8
// PDB : w:\tech5\engine\renderer\jobs\render\renderdepth.cpp
// ========================================================================

void __fastcall RenderDepth(const renderDepthParms_t *parms)
{
  const idRenderView *renderView; // r11
  const idRenderView *v3; // r10
  int *p_x1; // r11
  char v5; // r9
  int i; // r30
  const idRenderView *v7; // r11
  int y1; // r10
  int y2; // r9
  char v10; // r11
  __int64 v11; // r4
  const idRenderView *v12; // r9
  bfx::BinaryReplayLogOut *p_testScissor; // r11
  char v14; // r10
  const idRenderView *v15; // r10
  __int64 v16; // r8
  int numSceneModels; // r9
  int v18; // r29
  int v19; // r30
  const idRenderModelCommitted *v20; // r11
  const idRenderModelCommitted *v21; // r24
  __int64 v22; // r8
  int v23; // r5
  __int64 v24; // r4
  int v25; // r27
  int v26; // r22
  int v27; // r29
  const viewWorldArea_t *v28; // r10
  int v29; // r30
  int numSurfs; // r7
  bool v31; // r25
  BOOL skipDetailTriangles; // r26
  int v33; // r28
  const bool *binaryModelState; // r10
  const idTriangles *occlusionBaseTriangles; // r10
  bool v36; // r7
  int v37; // r29
  int v38; // r30
  const idRenderModelCommitted *v39; // r11
  float v40; // [sp+50h] [-90h] BYREF
  idODSObject<idRenderDestination> v41; // [sp+54h] [-8Ch] BYREF
  idODSObject<idImage> v42; // [sp+58h] [-88h] BYREF
  idODSObject<idRenderModelCommitted> v43; // [sp+5Ch] [-84h] BYREF
  idODSObject<idRenderModelSurface> v44; // [sp+60h] [-80h] BYREF
  idODSObject<idDeclRenderProg> v45; // [sp+64h] [-7Ch] BYREF
  idODSObject<idTriangles> v46; // [sp+68h] [-78h] BYREF

  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_CLEAR_DEPTH);
  GL_SetDefaultState();
  v41.objectPtr = parms->renderDestDefault;
  GL_SetRenderDestination(destination: &v41, level: 0, side: 0);
  renderView = parms->renderView;
  GL_Viewport(
    x: renderView->viewport.x1,
    y: renderView->viewport.y1,
    w: renderView->viewport.x2 - renderView->viewport.x1 + 1,
    h: renderView->viewport.y2 - renderView->viewport.y1 + 1);
  v3 = parms->renderView;
  p_x1 = &v3->testScissor.x1;
  if ( v3->testScissor.x1 > v3->testScissor.x2 || (v5 = 0, v3->testScissor.y1 > v3->testScissor.y2) )
    v5 = 1;
  if ( v5 != 0 )
    p_x1 = &v3->scissorRect.x1;
  GL_Scissor(x: *p_x1, y: p_x1[1], w: p_x1[2] - *p_x1 + 1, h: p_x1[3] - p_x1[1] + 1);
  for ( i = 0; i < parms->extraClears; ++i )
    GL_Clear(color: true, depth: true, stencil: true, stencilValue: 0, r: 0.0, g: 0.0, b: 0.0, a: 0.0);
  v7 = parms->renderView;
  if ( v7->testScissor.x1 > v7->testScissor.x2 || (y1 = v7->testScissor.y1, y2 = v7->testScissor.y2, v10 = 0, y1 > y2) )
    v10 = 1;
  if ( v10 != 0 )
    GL_Clear(color: false, depth: true, stencil: true, stencilValue: 0, r: 0.0, g: 0.0, b: 0.0, a: 0.0);
  GL_Flush();
  idRenderLog::CloseMainBlock(this: &renderLog);
  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_RENDER_DEPTH);
  GL_BeginQueryBatch(a1: v11);
  v12 = parms->renderView;
  p_testScissor = (bfx::BinaryReplayLogOut *)&v12->testScissor;
  if ( v12->testScissor.x1 > v12->testScissor.x2 || (v14 = 0, v12->testScissor.y1 > v12->testScissor.y2) )
    v14 = 1;
  if ( v14 != 0 )
    p_testScissor = (bfx::BinaryReplayLogOut *)&v12->scissorRect;
  idPhysics_StaticMulti::UpdateTime(this: p_testScissor);
  v42.objectPtr = parms->imgBlack;
  GL_BindTexture(image: &v42, texUnit: 0);
  v15 = parms->renderView;
  HIDWORD(v16) = v15->feedbackHeight;
  idParmState::SetPositionToFeedback(
    this: renderThreadParmState,
    renderWidth: v15->renderWidth,
    renderHeight: v15->renderHeight,
    feedbackHeight: v16);
  numSceneModels = parms->numSceneModels;
  v40 = 0.0;
  v18 = 0;
  if ( numSceneModels > 0 )
  {
    v19 = 0;
    do
    {
      v20 = parms->sceneModels[v19];
      v43.objectPtr = v20;
      if ( renderLog.activeLevel != 0 )
        idRenderLog::Printf(this: &renderLog, fmt: "scene model %i: %s\n", v20->index.index >> 8, v20->name);
      DrawModelDepthSurfaces(parms, modelODS: &v43, sortOffset: &v40);
      ++v18;
      ++v19;
    }
    while ( v18 < parms->numSceneModels );
  }
  v21 = *parms->viewModels;
  v43.objectPtr = v21;
  if ( renderLog.activeLevel != 0 )
    idRenderLog::Printf(this: &renderLog, fmt: "world model %i: %s\n", v21->index.index >> 8, v21->name);
  idParmState::SetModelMatrix(this: renderThreadParmState, modelMatrix: &v21->modelMatrix);
  idParmState::SetInverseModelMatrix(this: renderThreadParmState, inverseModelMatrix: &v21->inverseModelMatrix);
  idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v21->mvpMatrix);
  idParmState::SetApproximateLighting(this: renderThreadParmState, lighting: &v21->approximateLighting);
  idParmState::SetHighlightColor(this: renderThreadParmState, highlightColor: &v21->highlightColor);
  v25 = 0;
  v26 = 0;
  if ( parms->numViewWorldAreas > 0 )
  {
    v27 = 0;
    do
    {
      HIDWORD(v24) = &parms->occlusionState->worldAreaOcclusionQuery[parms->viewWorldAreas[v27].areaNum];
      GL_BeginQuery(queryNumber: v24, a2: v23, a3: v22);
      v28 = &parms->viewWorldAreas[v27];
      v29 = 0;
      numSurfs = v28->numSurfs;
      v31 = ((numSurfs >= 0) + ((unsigned int)numSurfs <= 1)) & 1;
      skipDetailTriangles = v28->skipDetailTriangles;
      if ( numSurfs > 0 )
      {
        v33 = v25;
        do
        {
          binaryModelState = parms->binaryModelState;
          v44.objectPtr = parms->viewWorldSurfaces[v33];
          if ( binaryModelState[v44.objectPtr->binaryModelId] )
            DrawDepthSurface(
              parms,
              modelODS: &v43,
              surfaceODS: &v44,
              cullSurface: v31,
              testOcclusion: true,
              skipDetailTriangles,
              sortOffset: &v40);
          ++v29;
          ++v25;
          ++v33;
        }
        while ( v29 < parms->viewWorldAreas[v27].numSurfs );
      }
      GL_EndQuery();
      ++v26;
      ++v27;
    }
    while ( v26 < parms->numViewWorldAreas );
  }
  if ( !parms->settings->skipOcclusionBaseModel && parms->occlusionBaseTriangles != nullptr )
  {
    if ( renderLog.activeLevel != 0 )
      idRenderLog::Printf(this: &renderLog, fmt: "base occlusion model %i: %s\n", v21->index.index >> 8, v21->name);
    idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v21->mvpMatrix);
    occlusionBaseTriangles = parms->occlusionBaseTriangles;
    v45.objectPtr = parms->progOccluderDepthOnly;
    v46.objectPtr = occlusionBaseTriangles;
    GL_DrawElements(prog: &v45, tri: &v46, extraState: 0x8000078000000000uLL, skipDetailTriangles: v36);
  }
  v37 = 1;
  if ( parms->numViewModels > 1 )
  {
    v38 = 1;
    do
    {
      v39 = parms->viewModels[v38];
      v43.objectPtr = v39;
      if ( renderLog.activeLevel != 0 )
        idRenderLog::Printf(this: &renderLog, fmt: "model %i: %s\n", v39->index.index >> 8, v39->name);
      DrawModelDepthSurfaces(parms, modelODS: &v43, sortOffset: &v40);
      ++v37;
      ++v38;
    }
    while ( v37 < parms->numViewModels );
  }
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)HIDWORD(v24));
  idRenderLog::CloseMainBlock(this: &renderLog);
}


// ========================================================================
// `dynamic initializer for 'register_RenderDepth''
// EA  : 0x8334C330
// RVA : 0x0134C330
// PDB : w:\tech5\engine\renderer\jobs\render\renderdepth.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_RenderDepth__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_RenderDepth,
           function: (void (__fastcall *)(void *))RenderDepth,
           name: "RenderDepth");
}

