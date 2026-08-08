
// ========================================================================
// ?PopModel@idRenderDrawSurf@@AAAXXZ
// EA  : 0x828DD020
// RVA : 0x008DD020
// PDB : w:\tech5\engine\renderer\jobs\render\renderdrawsurf.cpp
// ========================================================================

void __fastcall idRenderDrawSurf::PopModel(idRenderDrawSurf *this)
{
  int indentLevel; // r10

  if ( this->currentModel != nullptr )
  {
    idParmState::VirtualRollbackParmBlock(
      this: renderThreadParmState,
      localParmBlock: &this->currentModel->renderParmBlock,
      parmBlock: &this->currentModel->renderParmBlock);
    this->currentModel = nullptr;
    if ( renderLog.logFile != nullptr )
    {
      indentLevel = renderLog.indentLevel;
      if ( renderLog.indentLevel > 0 )
      {
        --renderLog.indentLevel;
        HIBYTE(renderLog.indentLabel[indentLevel + 19]) = 0;
      }
    }
  }
}


// ========================================================================
// ?RenderGui@@YAXPBVidRenderModelCommitted@@PBUrenderSettings_t@@PBVidRenderView@@_N@Z
// EA  : 0x828DD0A8
// RVA : 0x008DD0A8
// PDB : w:\tech5\engine\renderer\jobs\render\renderdrawsurf.cpp
// ========================================================================

void __fastcall RenderGui(
        const idRenderModelCommitted *model,
        const renderSettings_t *settings,
        __int64 inGameGui,
        __int64 a4,
        __int64 a5)
{
  const idRenderView *v7; // r31
  int v8; // r21
  int num; // r18
  int v10; // r22
  int singleGuiSurface; // r11
  idRenderModelSurface *v12; // r30
  const idMaterial *material; // r31
  const idDeclRenderProg *progShowGuiOverdraw; // r29
  unsigned __int64 extraGLState; // r26
  const idParmBlock *p_renderParmBlock; // r31
  unsigned __int64 v17; // r6
  bool v18; // r7
  bool v19; // r5
  int v20; // [sp+8h] [-118h]
  int v21; // [sp+Ch] [-114h]
  int v22; // [sp+10h] [-110h]
  int v23; // [sp+14h] [-10Ch]
  int v24; // [sp+18h] [-108h]
  int v25; // [sp+1Ch] [-104h]
  idODSObject<idTriangles> v26; // [sp+50h] [-D0h] BYREF
  idODSObject<idDeclRenderProg> v27; // [sp+54h] [-CCh] BYREF
  idRenderMatrix v28[3]; // [sp+60h] [-C0h] BYREF

  v7 = (const idRenderView *)HIDWORD(inGameGui);
  if ( !settings->skipGuis )
  {
    LODWORD(a5) = &off_82230000;
    idRenderLog::OpenBlock(
      this: &renderLog,
      fmt: "RenderGui",
      a3: inGameGui,
      a4,
      a5,
      a6: v20,
      a7: v21,
      a8: v22,
      a9: v23,
      a10: v24,
      a11: v25);
    SetupModelMVPMatrix(mvpMatrix: v28, model, renderView: v7, zNear: settings->viewNearZ, zFar: settings->viewFarZ);
    idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: v28);
    idParmState::VirtualEvaluateParmBlock(
      this: renderThreadParmState,
      localParmBlock: &model->renderParmBlock,
      parmBlock: &model->renderParmBlock);
    v8 = 0;
    num = model->surfaces.num;
    if ( num > 0 )
    {
      v10 = 0;
      do
      {
        singleGuiSurface = settings->singleGuiSurface;
        if ( singleGuiSurface == -1 || singleGuiSurface == v8 )
        {
          v12 = &model->surfaces.list[v10];
          material = v12->material;
          if ( v12->geometry != nullptr && material != nullptr )
          {
            idRenderLog::Printf(this: &renderLog, fmt: "Entering material %s\n", material->name.str);
            idRenderLog::Indent(this: &renderLog, label: RENDER_LOG_INDENT_DEFAULT);
            progShowGuiOverdraw = material->progs[6];
            extraGLState = v12->extraGLState;
            if ( settings->progShowGuiOverdraw != nullptr )
            {
              progShowGuiOverdraw = settings->progShowGuiOverdraw;
              LODWORD(extraGLState) = 0;
            }
            p_renderParmBlock = &material->renderParmBlock;
            idParmState::VirtualEvaluateParmBlock(
              this: renderThreadParmState,
              localParmBlock: p_renderParmBlock,
              parmBlock: p_renderParmBlock);
            idParmState::VirtualEvaluateParmBlock(
              this: renderThreadParmState,
              localParmBlock: &progShowGuiOverdraw->parmBlock,
              parmBlock: &progShowGuiOverdraw->parmBlock);
            v27.objectPtr = progShowGuiOverdraw;
            v26.objectPtr = (const idTriangles *)HIDWORD(extraGLState);
            LODWORD(v17) = 0;
            HIDWORD(v17) = extraGLState;
            GL_DrawElements(prog: &v27, tri: &v26, extraState: v17, skipDetailTriangles: v18);
            idParmState::VirtualRollbackParmBlock(
              this: renderThreadParmState,
              localParmBlock: &progShowGuiOverdraw->parmBlock,
              parmBlock: &progShowGuiOverdraw->parmBlock);
            idParmState::VirtualRollbackParmBlock(
              this: renderThreadParmState,
              localParmBlock: p_renderParmBlock,
              parmBlock: p_renderParmBlock);
            if ( renderLog.logFile != nullptr && renderLog.indentLevel > 0 )
            {
              --renderLog.indentLevel;
              renderLog.indentString[4 * renderLog.indentLevel] = 0;
            }
          }
        }
        ++v8;
        ++v10;
      }
      while ( v8 < num );
    }
    idParmState::VirtualRollbackParmBlock(
      this: renderThreadParmState,
      localParmBlock: &model->renderParmBlock,
      parmBlock: &model->renderParmBlock);
    if ( settings->progShowGuiOverdraw != nullptr )
    {
      GL_State(stateBits: 0x38000000000uLL, forceGlState: v19);
      GL_Clear(color: true, depth: false, stencil: false, stencilValue: 0, r: 0.0, g: 0.0, b: 0.0, a: 1.0);
    }
    if ( renderLog.logFile != nullptr )
      idRenderLog::LogCloseBlock(this: &renderLog, label: RENDER_LOG_INDENT_BLOCK);
  }
}


// ========================================================================
// ?PushModel@idRenderDrawSurf@@AAAXPBUrenderDrawSurfParms_t@@PBVidRenderModelCommitted@@@Z
// EA  : 0x828DD2C0
// RVA : 0x008DD2C0
// PDB : w:\tech5\engine\renderer\jobs\render\renderdrawsurf.cpp
// ========================================================================

void __fastcall idRenderDrawSurf::PushModel(
        idRenderDrawSurf *this,
        const renderDrawSurfParms_t *parms,
        const idRenderModelCommitted *model)
{
  __int64 v6; // r6
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  int v12; // r4
  const idRenderView *renderView; // r11
  const idRenderView *v14; // r11
  idODSObject<idRenderDestination> v15; // [sp+50h] [-30h] BYREF
  idODSObject<idRenderDestination> v16; // [sp+54h] [-2Ch] BYREF

  idRenderLog::Printf(this: &renderLog, fmt: "Entering model %i: %s\n", model->index.index >> 8, model->name);
  idRenderLog::Indent(this: &renderLog, label: RENDER_LOG_INDENT_DEFAULT);
  this->currentModel = model;
  if ( model->referenceModel != nullptr && !parms->settings->skipInGameGuis )
  {
    v15.objectPtr = parms->renderDestGui;
    GL_SetRenderDestination(destination: &v15, level: 0, side: 0);
    GL_Viewport(x: 0, y: 0, w: parms->renderDestGui->targetWidth, h: parms->renderDestGui->targetHeight);
    GL_Scissor(x: 0, y: 0, w: parms->renderDestGui->targetWidth, h: parms->renderDestGui->targetHeight);
    GL_Clear(color: true, depth: false, stencil: false, stencilValue: 0, r: 0.0, g: 0.0, b: 0.0, a: 0.0);
    LODWORD(v6) = 1;
    HIDWORD(v6) = parms->renderView;
    RenderGui(model: model->referenceModel, settings: parms->settings, inGameGui: v6, a4: v8, a5: v7);
    CaptureGuiImage(parms: &parms->captureParms, a2: v12, a3: v11, a4: v10, a5: v9);
    v16.objectPtr = parms->renderDestDefault;
    GL_SetRenderDestination(destination: &v16, level: 0, side: 0);
    renderView = parms->renderView;
    GL_Viewport(
      x: renderView->viewport.x1,
      y: renderView->viewport.y1,
      w: renderView->viewport.x2 - renderView->viewport.x1 + 1,
      h: renderView->viewport.y2 - renderView->viewport.y1 + 1);
    v14 = parms->renderView;
    GL_Scissor(
      x: v14->scissorRect.x1,
      y: v14->scissorRect.y1,
      w: v14->scissorRect.x2 - v14->scissorRect.x1 + 1,
      h: v14->scissorRect.y2 - v14->scissorRect.y1 + 1);
  }
  idParmState::SetModelMatrix(this: renderThreadParmState, modelMatrix: &model->modelMatrix);
  idParmState::SetInverseModelMatrix(this: renderThreadParmState, inverseModelMatrix: &model->inverseModelMatrix);
  idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &model->mvpMatrix);
  idParmState::SetApproximateLighting(this: renderThreadParmState, lighting: &model->approximateLighting);
  idParmState::SetHighlightColor(this: renderThreadParmState, highlightColor: &model->highlightColor);
  idParmState::VirtualEvaluateParmBlock(
    this: renderThreadParmState,
    localParmBlock: &model->renderParmBlock,
    parmBlock: &model->renderParmBlock);
}


// ========================================================================
// ?RenderDrawSurf@idRenderDrawSurf@@QAAXPBUrenderDrawSurfParms_t@@PBUdrawSurf_t@@_K@Z
// EA  : 0x828DD478
// RVA : 0x008DD478
// PDB : w:\tech5\engine\renderer\jobs\render\renderdrawsurf.cpp
// ========================================================================

void __fastcall idRenderDrawSurf::RenderDrawSurf(
        idRenderDrawSurf *this,
        const renderDrawSurfParms_t *parms,
        const drawSurf_t *surf,
        int a4,
        unsigned __int64 extraState)
{
  const idRenderModelCommitted *model; // r31
  const idMaterial *material; // r31
  idParmState *v11; // r3
  const idDeclRenderProg *renamed; // r27
  int v13; // r8
  const idRenderModelSurface *modelSurface; // r11
  unsigned __int64 v15; // r6
  bool v16; // r7
  idODSObject<idDeclRenderProg> v17; // [sp+50h] [-60h] BYREF
  idODSObject<idRenderModelSurface> v18; // [sp+54h] [-5Ch] BYREF

  model = surf->model;
  if ( model->referenceModel == nullptr || parms->allowInGameGUIs )
  {
    if ( model != this->currentModel )
    {
      idRenderDrawSurf::PopModel(this);
      idRenderDrawSurf::PushModel(this, parms, model);
    }
    material = surf->material;
    idRenderLog::Printf(this: &renderLog, fmt: "Entering material %s\n", material->name.str);
    idRenderLog::Indent(this: &renderLog, label: RENDER_LOG_INDENT_DEFAULT);
    idParmState::VirtualEvaluateParmBlock(
      this: renderThreadParmState,
      localParmBlock: &material->renderParmBlock,
      parmBlock: &material->renderParmBlock);
    v11 = renderThreadParmState;
    if ( (renderThreadParmState->values[renderThreadParmState->parmIndexIf].swizzle[0] & 0x7FFFFFFF) != 0 )
    {
      renamed = surf->prog->renamed;
      v13 = renderThreadParmState->parmIndexPolygonOffset + 3;
      if ( (*(_DWORD *)(&renderThreadParmState->renderParmVersion + 2 * v13) & 0x7FFFFFFF) != 0 )
      {
        GL_PolygonOffset(
          scale: 0.0,
          bias: *((float *)&renderThreadParmState->renderParmVersion + 4 * v13),
          fill: (bool)renderThreadParmState);
        v11 = renderThreadParmState;
      }
      idParmState::VirtualEvaluateParmBlock(
        this: v11,
        localParmBlock: &renamed->parmBlock,
        parmBlock: &renamed->parmBlock);
      modelSurface = surf->modelSurface;
      v17.objectPtr = renamed;
      HIDWORD(v15) = a4;
      LODWORD(v15) = surf->skipDetailTriangles;
      v18.objectPtr = modelSurface;
      GL_DrawElements(prog: &v17, surf: &v18, extraState: v15, skipDetailTriangles: v16);
      idParmState::VirtualRollbackParmBlock(
        this: renderThreadParmState,
        localParmBlock: &renamed->parmBlock,
        parmBlock: &renamed->parmBlock);
      v11 = renderThreadParmState;
      if ( (renderThreadParmState->values[renderThreadParmState->parmIndexPolygonOffset].swizzle[0] & 0x7FFFFFFF) != 0 )
      {
        GL_PolygonOffset(scale: 0.0, bias: 0.0, fill: (bool)renderThreadParmState);
        v11 = renderThreadParmState;
      }
    }
    idParmState::VirtualRollbackParmBlock(
      this: v11,
      localParmBlock: &material->renderParmBlock,
      parmBlock: &material->renderParmBlock);
    if ( renderLog.logFile != nullptr && renderLog.indentLevel > 0 )
    {
      --renderLog.indentLevel;
      renderLog.indentString[4 * renderLog.indentLevel] = 0;
    }
  }
}

