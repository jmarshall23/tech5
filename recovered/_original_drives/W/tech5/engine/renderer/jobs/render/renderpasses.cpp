
// ========================================================================
// ?RenderClearPass@@YAXPBUrenderPassParms_t@@@Z
// EA  : 0x828E14C8
// RVA : 0x008E14C8
// PDB : w:\tech5\engine\renderer\jobs\render\renderpasses.cpp
// ========================================================================

void __fastcall RenderClearPass(const renderPassParms_t *parms)
{
  const idRenderView *renderView; // r11
  const idRenderView *v3; // r11
  bool v4; // r5
  idODSObject<idRenderDestination> v5; // [sp+50h] [-20h] BYREF

  v5.objectPtr = parms->renderDestDefault;
  GL_SetRenderDestination(destination: &v5, level: 0, side: 0);
  renderView = parms->renderView;
  GL_Viewport(
    x: renderView->viewport.x1,
    y: renderView->viewport.y1,
    w: renderView->viewport.x2 - renderView->viewport.x1 + 1,
    h: renderView->viewport.y2 - renderView->viewport.y1 + 1);
  v3 = parms->renderView;
  GL_Scissor(
    x: v3->scissorRect.x1,
    y: v3->scissorRect.y1,
    w: v3->scissorRect.x2 - v3->scissorRect.x1 + 1,
    h: v3->scissorRect.y2 - v3->scissorRect.y1 + 1);
  GL_State(stateBits: 0x400000000000uLL, forceGlState: v4);
  GL_Clear(
    color: true,
    depth: false,
    stencil: false,
    stencilValue: 0x80u,
    r: parms->settings->clearColor.x,
    g: parms->settings->clearColor.y,
    b: parms->settings->clearColor.z,
    a: 1.0);
}


// ========================================================================
// ?RenderEmissivePass@@YAXPBUrenderPassParms_t@@@Z
// EA  : 0x828E1598
// RVA : 0x008E1598
// PDB : w:\tech5\engine\renderer\jobs\render\renderpasses.cpp
// ========================================================================

void __fastcall RenderEmissivePass(const renderPassParms_t *parms)
{
  const idRenderView *renderView; // r11
  const idRenderView *v3; // r11
  const renderPassSurfaces_t *renderPasses; // r11
  const renderPassSurfaces_t *v5; // r28
  int firstSurface; // r29
  int v7; // r27
  const bool *binaryModelState; // r10
  drawSurf_t *v9; // r5
  unsigned __int64 v10; // r8
  idRenderDrawSurf v11; // [sp+50h] [-40h] BYREF
  idODSObject<idRenderDestination> v12; // [sp+54h] [-3Ch] BYREF

  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_RENDER_EMISSIVE_SURFACES);
  v12.objectPtr = parms->renderDestDefault;
  GL_SetRenderDestination(destination: &v12, level: 0, side: 0);
  renderView = parms->renderView;
  GL_Viewport(
    x: renderView->viewport.x1,
    y: renderView->viewport.y1,
    w: renderView->viewport.x2 - renderView->viewport.x1 + 1,
    h: renderView->viewport.y2 - renderView->viewport.y1 + 1);
  v3 = parms->renderView;
  GL_Scissor(
    x: v3->scissorRect.x1,
    y: v3->scissorRect.y1,
    w: v3->scissorRect.x2 - v3->scissorRect.x1 + 1,
    h: v3->scissorRect.y2 - v3->scissorRect.y1 + 1);
  renderPasses = parms->renderPasses;
  v5 = renderPasses + 1;
  v11.currentModel = nullptr;
  firstSurface = renderPasses[1].firstSurface;
  if ( firstSurface <= renderPasses[1].lastSurface )
  {
    v7 = firstSurface;
    do
    {
      binaryModelState = parms->binaryModelState;
      v9 = parms->sortedDrawSurfs[v7];
      LODWORD(v10) = v9->modelSurface->binaryModelId;
      if ( binaryModelState[v10] )
      {
        HIDWORD(v10) = binaryModelState[v10];
        idRenderDrawSurf::RenderDrawSurf(this: &v11, parms: &parms->drawSurfParms, surf: v9, a4: 0, extraState: v10);
      }
      ++firstSurface;
      ++v7;
    }
    while ( firstSurface <= v5->lastSurface );
  }
  idRenderDrawSurf::PopModel(this: &v11);
  idRenderLog::CloseMainBlock(this: &renderLog);
}


// ========================================================================
// __unwind$86778
// EA  : 0x828E16A8
// RVA : 0x008E16A8
// PDB : w:\tech5\engine\renderer\jobs\render\renderpasses.cpp
// ========================================================================

void _unwind_86778()
{
  int v0; // r12

  idRenderDrawSurf::~idRenderDrawSurf(this: (idRenderDrawSurf *)(v0 - 144 + 80));
}


// ========================================================================
// ?RenderEmissiveOnlyPass@@YAXPBUrenderPassParms_t@@@Z
// EA  : 0x828E16D8
// RVA : 0x008E16D8
// PDB : w:\tech5\engine\renderer\jobs\render\renderpasses.cpp
// ========================================================================

void __fastcall RenderEmissiveOnlyPass(const renderPassParms_t *parms)
{
  const idRenderView *renderView; // r11
  const idRenderView *v3; // r11
  const renderPassSurfaces_t *renderPasses; // r11
  const renderPassSurfaces_t *v5; // r28
  int firstSurface; // r29
  int v7; // r27
  const bool *binaryModelState; // r10
  drawSurf_t *v9; // r5
  unsigned __int64 v10; // r8
  idRenderDrawSurf v11; // [sp+50h] [-40h] BYREF
  idODSObject<idRenderDestination> v12; // [sp+54h] [-3Ch] BYREF

  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_RENDER_EMMISIVE_ONLY_SURFACES);
  v12.objectPtr = parms->renderDestDefault;
  GL_SetRenderDestination(destination: &v12, level: 0, side: 0);
  renderView = parms->renderView;
  GL_Viewport(
    x: renderView->viewport.x1,
    y: renderView->viewport.y1,
    w: renderView->viewport.x2 - renderView->viewport.x1 + 1,
    h: renderView->viewport.y2 - renderView->viewport.y1 + 1);
  v3 = parms->renderView;
  GL_Scissor(
    x: v3->scissorRect.x1,
    y: v3->scissorRect.y1,
    w: v3->scissorRect.x2 - v3->scissorRect.x1 + 1,
    h: v3->scissorRect.y2 - v3->scissorRect.y1 + 1);
  renderPasses = parms->renderPasses;
  v5 = renderPasses + 2;
  v11.currentModel = nullptr;
  firstSurface = renderPasses[2].firstSurface;
  if ( firstSurface <= renderPasses[2].lastSurface )
  {
    v7 = firstSurface;
    do
    {
      binaryModelState = parms->binaryModelState;
      v9 = parms->sortedDrawSurfs[v7];
      LODWORD(v10) = v9->modelSurface->binaryModelId;
      if ( binaryModelState[v10] )
      {
        HIDWORD(v10) = binaryModelState[v10];
        idRenderDrawSurf::RenderDrawSurf(this: &v11, parms: &parms->drawSurfParms, surf: v9, a4: 0, extraState: v10);
      }
      ++firstSurface;
      ++v7;
    }
    while ( firstSurface <= v5->lastSurface );
  }
  idRenderDrawSurf::PopModel(this: &v11);
  idRenderLog::CloseMainBlock(this: &renderLog);
}


// ========================================================================
// __unwind$86831
// EA  : 0x828E17E8
// RVA : 0x008E17E8
// PDB : w:\tech5\engine\renderer\jobs\render\renderpasses.cpp
// ========================================================================

void _unwind_86831()
{
  int v0; // r12

  idRenderDrawSurf::~idRenderDrawSurf(this: (idRenderDrawSurf *)(v0 - 144 + 80));
}


// ========================================================================
// ?RenderBlendPass@@YAXPBUrenderPassParms_t@@@Z
// EA  : 0x828E1818
// RVA : 0x008E1818
// PDB : w:\tech5\engine\renderer\jobs\render\renderpasses.cpp
// ========================================================================

void __fastcall RenderBlendPass(const renderPassParms_t *parms)
{
  const idRenderView *renderView; // r11
  const idRenderView *v3; // r11
  const renderPassSurfaces_t *renderPasses; // r11
  const renderPassSurfaces_t *v5; // r28
  int firstSurface; // r29
  int v7; // r27
  const bool *binaryModelState; // r10
  drawSurf_t *v9; // r5
  unsigned __int64 v10; // r8
  idRenderDrawSurf v11; // [sp+50h] [-40h] BYREF
  idODSObject<idRenderDestination> v12; // [sp+54h] [-3Ch] BYREF

  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_RENDER_BLENDED_SURFACES);
  v12.objectPtr = parms->renderDestDefault;
  GL_SetRenderDestination(destination: &v12, level: 0, side: 0);
  renderView = parms->renderView;
  GL_Viewport(
    x: renderView->viewport.x1,
    y: renderView->viewport.y1,
    w: renderView->viewport.x2 - renderView->viewport.x1 + 1,
    h: renderView->viewport.y2 - renderView->viewport.y1 + 1);
  v3 = parms->renderView;
  GL_Scissor(
    x: v3->scissorRect.x1,
    y: v3->scissorRect.y1,
    w: v3->scissorRect.x2 - v3->scissorRect.x1 + 1,
    h: v3->scissorRect.y2 - v3->scissorRect.y1 + 1);
  renderPasses = parms->renderPasses;
  v5 = renderPasses + 3;
  v11.currentModel = nullptr;
  firstSurface = renderPasses[3].firstSurface;
  if ( firstSurface <= renderPasses[3].lastSurface )
  {
    v7 = firstSurface;
    do
    {
      binaryModelState = parms->binaryModelState;
      v9 = parms->sortedDrawSurfs[v7];
      LODWORD(v10) = v9->modelSurface->binaryModelId;
      if ( binaryModelState[v10] )
      {
        HIDWORD(v10) = binaryModelState[v10];
        idRenderDrawSurf::RenderDrawSurf(this: &v11, parms: &parms->drawSurfParms, surf: v9, a4: 0, extraState: v10);
      }
      ++firstSurface;
      ++v7;
    }
    while ( firstSurface <= v5->lastSurface );
  }
  idRenderDrawSurf::PopModel(this: &v11);
  idRenderLog::CloseMainBlock(this: &renderLog);
}


// ========================================================================
// __unwind$86881
// EA  : 0x828E1928
// RVA : 0x008E1928
// PDB : w:\tech5\engine\renderer\jobs\render\renderpasses.cpp
// ========================================================================

void _unwind_86881()
{
  int v0; // r12

  idRenderDrawSurf::~idRenderDrawSurf(this: (idRenderDrawSurf *)(v0 - 144 + 80));
}


// ========================================================================
// ?RenderDistortionPass@@YAXPBUrenderPassParms_t@@@Z
// EA  : 0x828E1958
// RVA : 0x008E1958
// PDB : w:\tech5\engine\renderer\jobs\render\renderpasses.cpp
// ========================================================================

void __fastcall RenderDistortionPass(const renderPassParms_t *parms)
{
  const idRenderDestination *renderDestDistortion; // r10
  unsigned int targetWidth; // r29
  unsigned int targetHeight; // r28
  bool v5; // r5
  const renderPassSurfaces_t *renderPasses; // r11
  const renderPassSurfaces_t *v7; // r28
  int firstSurface; // r29
  int v9; // r27
  const bool *binaryModelState; // r10
  drawSurf_t *v11; // r5
  unsigned __int64 v12; // r8
  const idRenderView *renderView; // r11
  const idRenderView *v14; // r11
  idRenderDrawSurf v15; // [sp+50h] [-50h] BYREF
  idODSObject<idRenderDestination> v16; // [sp+54h] [-4Ch] BYREF
  idODSObject<idRenderDestination> v17; // [sp+58h] [-48h] BYREF
  idODSObject<idRenderDestination> v18; // [sp+5Ch] [-44h] BYREF

  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_RENDER_DISTORTION_SURFACES);
  v16.objectPtr = parms->renderDestDistortion;
  GL_SetRenderDestination(destination: &v16, level: 0, side: 0);
  renderDestDistortion = parms->renderDestDistortion;
  targetWidth = renderDestDistortion->targetWidth;
  targetHeight = renderDestDistortion->targetHeight;
  idParmState::SetPositionToViewTexture(
    this: renderThreadParmState,
    windowWidth: targetWidth,
    windowHeight: targetHeight,
    renderWidth: targetWidth,
    renderHeight: targetHeight);
  GL_Viewport(x: 0, y: 0, w: targetWidth, h: targetHeight);
  GL_Scissor(x: 0, y: 0, w: targetWidth, h: targetHeight);
  GL_State(stateBits: 0x400000000000uLL, forceGlState: v5);
  GL_Clear(color: true, depth: false, stencil: false, stencilValue: 0, r: 0.5, g: 0.5, b: 0.5, a: 0.0);
  renderPasses = parms->renderPasses;
  v15.currentModel = nullptr;
  v7 = renderPasses + 4;
  firstSurface = renderPasses[4].firstSurface;
  if ( firstSurface <= renderPasses[4].lastSurface )
  {
    v9 = firstSurface;
    do
    {
      binaryModelState = parms->binaryModelState;
      v11 = parms->sortedDrawSurfs[v9];
      LODWORD(v12) = v11->modelSurface->binaryModelId;
      if ( binaryModelState[v12] )
      {
        HIDWORD(v12) = binaryModelState[v12];
        idRenderDrawSurf::RenderDrawSurf(this: &v15, parms: &parms->drawSurfParms, surf: v11, a4: 0, extraState: v12);
      }
      ++firstSurface;
      ++v9;
    }
    while ( firstSurface <= v7->lastSurface );
  }
  idRenderDrawSurf::PopModel(this: &v15);
  v17.objectPtr = parms->renderDestDistortion;
  GL_ResolveTarget(target: RESOLVE_TARGET_COLOR0, destination: &v17);
  v18.objectPtr = parms->renderDestDefault;
  GL_SetRenderDestination(destination: &v18, level: 0, side: 0);
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
  idParmState::SetPositionToViewTexture(
    this: renderThreadParmState,
    windowWidth: parms->renderView->windowWidth,
    windowHeight: parms->renderView->windowHeight,
    renderWidth: parms->renderView->renderWidth,
    renderHeight: parms->renderView->renderHeight);
  idRenderLog::CloseMainBlock(this: &renderLog);
}


// ========================================================================
// __unwind$86931
// EA  : 0x828E1B38
// RVA : 0x008E1B38
// PDB : w:\tech5\engine\renderer\jobs\render\renderpasses.cpp
// ========================================================================

void _unwind_86931()
{
  int v0; // r12

  idRenderDrawSurf::~idRenderDrawSurf(this: (idRenderDrawSurf *)(v0 - 160 + 80));
}


// ========================================================================
// ?RenderPass@@YAXPBUrenderPassParms_t@@@Z
// EA  : 0x828E1B60
// RVA : 0x008E1B60
// PDB : w:\tech5\engine\renderer\jobs\render\renderpasses.cpp
// ========================================================================

void __fastcall RenderPass(const renderPassParms_t *parms)
{
  renderPass_t pass; // r11

  pass = parms->pass;
  if ( parms->pass <= (unsigned int)RENDERPASS_DISTORTION )
  {
    switch ( pass )
    {
      case RENDERPASS_EMISSIVE:
        RenderEmissivePass(parms);
        break;
      case RENDERPASS_EMISSIVE_ONLY:
        RenderEmissiveOnlyPass(parms);
        break;
      case RENDERPASS_BLEND:
        RenderBlendPass(parms);
        break;
      default:
        if ( pass != RENDERPASS_CLEAR )
          RenderDistortionPass(parms);
        else
          RenderClearPass(parms);
        break;
    }
  }
}

