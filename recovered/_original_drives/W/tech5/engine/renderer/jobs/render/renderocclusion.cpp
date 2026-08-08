
// ========================================================================
// ?RenderOcclusion@@YAXPBUrenderOcclusionParms_t@@@Z
// EA  : 0x828E10B0
// RVA : 0x008E10B0
// PDB : w:\tech5\engine\renderer\jobs\render\renderocclusion.cpp
// ========================================================================

void __fastcall RenderOcclusion(const renderOcclusionParms_t *parms)
{
  const idTriangles *unitCubeTris; // r10
  const idTriangles *zeroOneCubeTris; // r9
  const idRenderDestination *renderDestDefault; // r8
  const idRenderView *renderView; // r11
  const idRenderView *v6; // r11
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  int v10; // r26
  int v11; // r24
  int v12; // r27
  int v13; // r30
  int v14; // r23
  __int64 v15; // r4
  __int64 v16; // r8
  int v17; // r5
  unsigned __int64 v18; // r6
  bool v19; // r7
  int v20; // r28
  int v21; // r27
  int v22; // r30
  __int64 v23; // r4
  __int64 v24; // r8
  int v25; // r5
  unsigned __int64 v26; // r6
  bool v27; // r7
  int v28; // r28
  int v29; // r27
  const idRenderModelCommitted *v30; // r30
  __int64 v31; // r8
  __int64 v32; // r4
  int v33; // r5
  unsigned __int64 v34; // r6
  bool v35; // r7
  int v36; // r28
  int v37; // r27
  const idRenderLightCommitted *v38; // r30
  __int64 v39; // r8
  __int64 v40; // r4
  int v41; // r5
  unsigned __int64 v42; // r6
  bool v43; // r7
  int v44; // [sp+8h] [-A8h]
  int v45; // [sp+Ch] [-A4h]
  int v46; // [sp+10h] [-A0h]
  int v47; // [sp+14h] [-9Ch]
  int v48; // [sp+18h] [-98h]
  int v49; // [sp+1Ch] [-94h]
  idODSObject<idDeclRenderProg> v50; // [sp+50h] [-60h] BYREF
  idODSObject<idTriangles> v51; // [sp+54h] [-5Ch] BYREF
  idODSObject<idRenderDestination> v52; // [sp+58h] [-58h] BYREF
  idODSObject<idTriangles> v53; // [sp+5Ch] [-54h] BYREF

  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_RENDER_OCCLUSION_BOXES);
  unitCubeTris = parms->unitCubeTris;
  zeroOneCubeTris = parms->zeroOneCubeTris;
  renderDestDefault = parms->renderDestDefault;
  v50.objectPtr = parms->progDepthOnly;
  v51.objectPtr = unitCubeTris;
  v53.objectPtr = zeroOneCubeTris;
  v52.objectPtr = renderDestDefault;
  GL_SetRenderDestination(destination: &v52, level: 0, side: 0);
  renderView = parms->renderView;
  GL_Viewport(
    x: renderView->viewport.x1,
    y: renderView->viewport.y1,
    w: renderView->viewport.x2 - renderView->viewport.x1 + 1,
    h: renderView->viewport.y2 - renderView->viewport.y1 + 1);
  v6 = parms->renderView;
  GL_Scissor(
    x: v6->scissorRect.x1,
    y: v6->scissorRect.y1,
    w: v6->scissorRect.x2 - v6->scissorRect.x1 + 1,
    h: v6->scissorRect.y2 - v6->scissorRect.y1 + 1);
  v10 = -2147481664;
  if ( parms->settings->showOcclusionBoxes )
    v10 = -2147482560;
  if ( !parms->settings->skipNodeGPUCulling )
  {
    LODWORD(v7) = parms->settings->showOcclusionBoxes;
    idRenderLog::OpenBlock(
      this: &renderLog,
      fmt: "Node occlusion queries",
      a3: v9,
      a4: v8,
      a5: v7,
      a6: v44,
      a7: v45,
      a8: v46,
      a9: v47,
      a10: v48,
      a11: v49);
    v11 = 0;
    if ( parms->numOcclusionTestNodes > 0 )
    {
      v12 = 0;
      do
      {
        v13 = parms->occlusionTestNodes[v12];
        if ( v13 != -1 )
        {
          v14 = parms->areaNodeOcclusionIndex[v13];
          idRenderLog::Printf(this: &renderLog, fmt: "bounding volume query for node %i\n", v14);
          idParmState::SetMVPMatrixForBounds(
            this: renderThreadParmState,
            mvp: &parms->renderView->worldSpaceMVPMatrix,
            bounds: &parms->areaNodeBounds[v13]);
          HIDWORD(v15) = (char *)parms->occlusionState + 8 * v14;
          GL_BeginQuery(queryNumber: v15, a2: v17, a3: v16);
          LODWORD(v18) = 0;
          HIDWORD(v18) = v10;
          GL_DrawElements(prog: &v50, tri: &v51, extraState: v18, skipDetailTriangles: v19);
          GL_EndQuery();
        }
        ++v11;
        ++v12;
      }
      while ( v11 < parms->numOcclusionTestNodes );
    }
    if ( renderLog.logFile != nullptr )
      idRenderLog::LogCloseBlock(this: &renderLog, label: RENDER_LOG_INDENT_BLOCK);
  }
  if ( !parms->settings->skipAreaGPUCulling )
  {
    LODWORD(v7) = parms->settings->skipAreaGPUCulling;
    idRenderLog::OpenBlock(
      this: &renderLog,
      fmt: "World area occlusion queries",
      a3: v9,
      a4: v8,
      a5: v7,
      a6: v44,
      a7: v45,
      a8: v46,
      a9: v47,
      a10: v48,
      a11: v49);
    v20 = 0;
    if ( parms->numOcclusionTestWorldAreas > 0 )
    {
      v21 = 0;
      do
      {
        v22 = parms->occlusionTestWorldAreas[v21];
        idRenderLog::Printf(this: &renderLog, fmt: "bounding volume query for area %i\n", v22);
        idParmState::SetMVPMatrixForBounds(
          this: renderThreadParmState,
          mvp: &parms->renderView->worldSpaceMVPMatrix,
          bounds: &parms->worldAreaGeometryBounds[v22]);
        HIDWORD(v23) = &parms->occlusionState->worldAreaOcclusionQuery[v22];
        GL_BeginQuery(queryNumber: v23, a2: v25, a3: v24);
        LODWORD(v26) = 0;
        HIDWORD(v26) = v10;
        GL_DrawElements(prog: &v50, tri: &v51, extraState: v26, skipDetailTriangles: v27);
        GL_EndQuery();
        LODWORD(v8) = parms->numOcclusionTestWorldAreas;
        ++v20;
        ++v21;
      }
      while ( v20 < (int)v8 );
    }
    if ( renderLog.logFile != nullptr )
      idRenderLog::LogCloseBlock(this: &renderLog, label: RENDER_LOG_INDENT_BLOCK);
  }
  if ( !parms->settings->skipModelGPUCulling )
  {
    LODWORD(v7) = parms->settings->skipModelGPUCulling;
    idRenderLog::OpenBlock(
      this: &renderLog,
      fmt: "Model occlusion queries",
      a3: v9,
      a4: v8,
      a5: v7,
      a6: v44,
      a7: v45,
      a8: v46,
      a9: v47,
      a10: v48,
      a11: v49);
    v28 = 0;
    if ( parms->numOcclusionTestModels > 0 )
    {
      v29 = 0;
      do
      {
        v30 = parms->occlusionTestModels[v29];
        idRenderLog::Printf(this: &renderLog, fmt: "bounding volume query for model %i\n", v30->index.index >> 8);
        idParmState::SetMVPMatrixForBounds(
          this: renderThreadParmState,
          mvp: &v30->mvpMatrix,
          bounds: &v30->referenceBounds);
        LODWORD(v31) = (v30->index.index >> 8) + 8256;
        HIDWORD(v32) = (char *)parms->occlusionState + 8 * v31;
        GL_BeginQuery(queryNumber: v32, a2: v33, a3: v31);
        LODWORD(v34) = 0;
        HIDWORD(v34) = v10;
        GL_DrawElements(prog: &v50, tri: &v51, extraState: v34, skipDetailTriangles: v35);
        GL_EndQuery();
        HIDWORD(v8) = parms->numOcclusionTestModels;
        ++v28;
        ++v29;
      }
      while ( v28 < SHIDWORD(v8) );
    }
    if ( renderLog.logFile != nullptr )
      idRenderLog::LogCloseBlock(this: &renderLog, label: RENDER_LOG_INDENT_BLOCK);
  }
  if ( !parms->settings->skipLightGPUCulling )
  {
    LODWORD(v7) = parms->settings->skipLightGPUCulling;
    idRenderLog::OpenBlock(
      this: &renderLog,
      fmt: "Light occlusion queries",
      a3: v9,
      a4: v8,
      a5: v7,
      a6: v44,
      a7: v45,
      a8: v46,
      a9: v47,
      a10: v48,
      a11: v49);
    v36 = 0;
    if ( parms->numOcclusionTestLights > 0 )
    {
      v37 = 0;
      do
      {
        v38 = parms->occlusionTestLights[v37];
        idRenderLog::Printf(this: &renderLog, fmt: "bounding volume query for light %i\n", v38->index.index >> 8);
        idParmState::SetMVPMatrixForInverseProject(
          this: renderThreadParmState,
          mvp: &parms->renderView->worldSpaceMVPMatrix,
          inverseProject: &v38->inverseBaseLightProject);
        LODWORD(v39) = (v38->index.index >> 8) + 16448;
        HIDWORD(v40) = (char *)parms->occlusionState + 8 * v39;
        GL_BeginQuery(queryNumber: v40, a2: v41, a3: v39);
        LODWORD(v42) = 0;
        HIDWORD(v42) = v10;
        GL_DrawElements(prog: &v50, tri: &v53, extraState: v42, skipDetailTriangles: v43);
        GL_EndQuery();
        ++v36;
        ++v37;
      }
      while ( v36 < parms->numOcclusionTestLights );
    }
    if ( renderLog.logFile != nullptr )
      idRenderLog::LogCloseBlock(this: &renderLog, label: RENDER_LOG_INDENT_BLOCK);
  }
  idRenderLog::CloseMainBlock(this: &renderLog);
}


// ========================================================================
// `dynamic initializer for 'register_RenderOcclusion''
// EA  : 0x8334C370
// RVA : 0x0134C370
// PDB : w:\tech5\engine\renderer\jobs\render\renderocclusion.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_RenderOcclusion__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_RenderOcclusion,
           function: (void (__fastcall *)(void *))RenderOcclusion,
           name: "RenderOcclusion");
}

