
// ========================================================================
// ?RenderAugment@@YAXPBUrenderAugmentParms_t@@@Z
// EA  : 0x828D97C8
// RVA : 0x008D97C8
// PDB : w:\tech5\engine\renderer\jobs\render\renderaugment.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall RenderAugment(const renderAugmentParms_t *parms)
{
  int numViewAugmentModels; // r11
  int v3; // r14
  const idRenderModelCommitted *v4; // r18
  idRenderModelCommitted *referenceModel; // r23
  __int64 v6; // r8 OVERLAPPED
  const idRenderDestination *renderDestAugment; // r10
  int targetWidth; // r11
  int v9; // r9
  int v10; // r24
  int v11; // r25
  double v12; // fp1
  double v13; // fp3
  int v14; // r10
  int v15; // r9
  unsigned int v16; // r9
  int v17; // r11
  unsigned int v18; // r10
  int v19; // r11
  int v20; // r27
  int v21; // r11
  int v22; // r28
  int v23; // r29
  int v24; // r30
  int v25; // r28
  int v26; // r27
  const idRenderModelSurface *v27; // r30
  __int128 v28; // r6
  bool v29; // r7
  const idRenderView *renderView; // r11
  __int64 v31; // r7
  __int64 v32; // r3
  __int64 v33; // r9
  __int64 v34; // r5
  signed int x1; // r10
  unsigned int v36; // r30
  int v37; // r9
  int y1; // r27
  int x2; // r8
  int y2; // r11
  int v41; // r29
  int v42; // r28
  int v43; // r23
  int v44; // r22
  idRenderModelSurface *v45; // r27
  const idTriangles *geometry; // r25
  const idMaterial *material; // r30
  const idDeclRenderProg *v48; // r28
  const idParmBlock *p_renderParmBlock; // r30
  __int128 v50; // r6
  bool v51; // r7
  int v52; // r10
  idODSObject<idRenderDestination> v53; // [sp+50h] [-140h] BYREF
  int v54; // [sp+54h] [-13Ch]
  int v55; // [sp+58h] [-138h]
  idODSObject<idRenderDestination> v56; // [sp+5Ch] [-134h] BYREF
  idODSObject<idRenderDestination> v57; // [sp+60h] [-130h] BYREF
  idODSObject<idDeclRenderProg> v58; // [sp+64h] [-12Ch] BYREF
  idODSObject<idTriangles> v59; // [sp+68h] [-128h] BYREF
  const char *v60; // [sp+6Ch] [-124h]
  idODSObject<idDeclRenderProg> v61; // [sp+70h] [-120h] BYREF
  idODSObject<idRenderModelSurface> v62; // [sp+74h] [-11Ch] BYREF
  idBounds v63; // [sp+80h] [-110h] BYREF
  __int64 v64; // [sp+98h] [-F8h]
  int v66; // [sp+A4h] [-ECh]
  __int64 v67; // [sp+A8h] [-E8h]
  int v69; // [sp+B4h] [-DCh]
  __int64 v70; // [sp+B8h] [-D8h]
  int v72; // [sp+C4h] [-CCh]
  __int64 v73; // [sp+C8h] [-C8h]
  int v75; // [sp+D4h] [-BCh]
  __int64 v76; // [sp+D8h] [-B8h]
  __int64 v77; // [sp+E0h] [-B0h]

  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_RENDER_AUGMENT_MODELS);
  numViewAugmentModels = parms->numViewAugmentModels;
  v55 = 0;
  if ( numViewAugmentModels > 0 )
  {
    v3 = 0;
    v60 = "Augment model %i: %s\n";
    do
    {
      v4 = parms->viewAugmentModels[v3];
      referenceModel = v4->referenceModel;
      if ( referenceModel != nullptr )
      {
        idRenderMatrix::ProjectedBounds(
          projected: &v63,
          mvp: &referenceModel->mvpMatrix,
          b: &referenceModel->referenceBounds,
          zeroToOne: true);
        idRenderLog::Printf(this: &renderLog, fmt: "Reference model %i: %s\n", v4->index.index >> 8, v4->name);
        if ( renderLog.logFile != nullptr )
        {
          HIDWORD(v6) = (char *)&renderLog.indentLabel[19] + 1;
          renderLog.indentLabel[renderLog.indentLevel++] = RENDER_LOG_INDENT_DEFAULT;
          HIBYTE(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
          BYTE1(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
          BYTE2(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
          LOBYTE(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
          renderLog.indentString[4 * renderLog.indentLevel] = 0;
        }
        renderDestAugment = parms->renderDestAugment;
        targetWidth = renderDestAugment->targetWidth;
        v9 = targetWidth;
        LODWORD(v6) = renderDestAugment->targetHeight;
        v77 = *(__int64 *)((char *)&v6 - 4);
        v64 = v6;
        v10 = v6 - 1;
        v11 = targetWidth - 1;
        v12 = (float)(v63.b[0].x * (float)*(__int64 *)((char *)&v6 - 4));
        v13 = (float)(v63.b[0].y * (float)v6);
        HIDWORD(v6) = (int)(float)(v63.b[1].y * (float)v6);
        v14 = (int)v13;
        v54 = (int)(float)(v63.b[1].x * (float)*(__int64 *)((char *)&v6 - 4));
        v15 = (int)v12;
        if ( (int)v12 >= 4 )
          v15 = 4;
        v16 = (int)v12 - v15;
        v17 = (int)v13;
        if ( v14 >= 4 )
          v17 = 4;
        v18 = v14 - v17;
        v19 = 65534 - v54;
        if ( 65534 - v54 >= 4 )
          v19 = 4;
        v20 = v19 + v54;
        v21 = 65534 - HIDWORD(v6);
        if ( 65534 - HIDWORD(v6) >= 4 )
          v21 = 4;
        v22 = v21 + HIDWORD(v6);
        v23 = ((v16 == 0) + (v16 >> 31) - 1) & v16;
        if ( v20 >= v11 )
          v20 = v11;
        v24 = ((v18 == 0) + (v18 >> 31) - 1) & v18;
        if ( v22 >= v10 )
          v22 = v6 - 1;
        v53.objectPtr = parms->renderDestAugment;
        GL_SetRenderDestination(destination: &v53, level: 0, side: 0);
        GL_Viewport(x: 0, y: 0, w: v11 + 1, h: v10 + 1);
        GL_Scissor(x: v23, y: v24, w: v20 - v23 + 1, h: v22 - v24 + 1);
        GL_Clear(color: true, depth: false, stencil: false, stencilValue: 0, r: 0.0, g: 0.0, b: 0.0, a: 0.0);
        idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &referenceModel->mvpMatrix);
        idParmState::VirtualEvaluateParmBlock(
          this: renderThreadParmState,
          localParmBlock: &referenceModel->renderParmBlock,
          parmBlock: &referenceModel->renderParmBlock);
        v25 = 0;
        if ( referenceModel->surfaces.num > 0 )
        {
          v26 = 0;
          do
          {
            v27 = &referenceModel->surfaces.list[v26];
            if ( v27->geometry != nullptr && v27->material != nullptr )
            {
              idParmState::VirtualEvaluateParmBlock(
                this: renderThreadParmState,
                localParmBlock: &parms->progColorParmOnly->parmBlock,
                parmBlock: &parms->progColorParmOnly->parmBlock);
              *(_QWORD *)((char *)&v28 + 4) = v27->extraGLState;
              LODWORD(v28) = 0;
              v58.objectPtr = parms->progColorParmOnly;
              v62.objectPtr = v27;
              GL_DrawElements(prog: &v58, surf: &v62, extraState: v28, skipDetailTriangles: v29);
              idParmState::VirtualRollbackParmBlock(
                this: renderThreadParmState,
                localParmBlock: &parms->progColorParmOnly->parmBlock,
                parmBlock: &parms->progColorParmOnly->parmBlock);
            }
            ++v25;
            ++v26;
          }
          while ( v25 < referenceModel->surfaces.num );
        }
        idParmState::VirtualRollbackParmBlock(
          this: renderThreadParmState,
          localParmBlock: &referenceModel->renderParmBlock,
          parmBlock: &referenceModel->renderParmBlock);
        v56.objectPtr = parms->renderDestAugment;
        GL_ResolveTarget(target: RESOLVE_TARGET_COLOR0, destination: &v56);
        if ( renderLog.logFile != nullptr && renderLog.indentLevel > 0 )
        {
          --renderLog.indentLevel;
          renderLog.indentString[4 * renderLog.indentLevel] = 0;
        }
        idRenderLog::Printf(this: &renderLog, fmt: v60, v4->index.index >> 8, v4->name);
        if ( renderLog.logFile != nullptr )
        {
          renderLog.indentLabel[renderLog.indentLevel++] = RENDER_LOG_INDENT_DEFAULT;
          HIBYTE(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
          BYTE1(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
          BYTE2(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
          LOBYTE(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
          renderLog.indentString[4 * renderLog.indentLevel] = 0;
        }
        v57.objectPtr = parms->renderDestDefault;
        GL_SetRenderDestination(destination: &v57, level: 0, side: 0);
        renderView = parms->renderView;
        v31 = *(_QWORD *)&renderView->viewport.x2;
        LODWORD(v32) = HIDWORD(v31);
        HIDWORD(v33) = renderView->viewport.y1;
        v34 = *(_QWORD *)&renderView->viewport.x1;
        v76 = v32;
        v67 = v31;
        LODWORD(v33) = HIDWORD(v34);
        v73 = v34;
        v70 = v33;
        x1 = renderView->scissorRect.x1;
        v66 = (int)(float)(v63.b[1].x * (float)((float)v32 - (float)v33));
        v72 = (int)(float)(v63.b[0].x * (float)((float)v32 - (float)v33));
        v36 = v72;
        v75 = (int)(float)(v63.b[0].y * (float)((float)v31 - (float)v34));
        v69 = (int)(float)(v63.b[1].y * (float)((float)v31 - (float)v34));
        y1 = v75;
        x2 = v66;
        v37 = v69;
        if ( v72 <= x1 )
          v36 = x1;
        if ( v66 >= renderView->scissorRect.x2 )
          x2 = renderView->scissorRect.x2;
        if ( v75 <= renderView->scissorRect.y1 )
          y1 = renderView->scissorRect.y1;
        y2 = renderView->scissorRect.y2;
        if ( v69 >= y2 )
          v37 = y2;
        v41 = v37 - y1 + 1;
        v42 = x2 - v36 + 1;
        GL_Viewport(x: v36, y: y1, w: v42, h: v41);
        GL_Scissor(x: v36, y: y1, w: v42, h: v41);
        idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v4->mvpMatrix);
        idParmState::VirtualEvaluateParmBlock(
          this: renderThreadParmState,
          localParmBlock: &v4->renderParmBlock,
          parmBlock: &v4->renderParmBlock);
        v43 = 0;
        if ( v4->surfaces.num > 0 )
        {
          v44 = 0;
          do
          {
            v45 = &v4->surfaces.list[v44];
            if ( v45 != nullptr )
            {
              geometry = v45->geometry;
              material = v45->material;
              if ( geometry != nullptr && material != nullptr )
              {
                v48 = material->progs[6];
                if ( v48 != nullptr )
                {
                  idRenderLog::Printf(this: &renderLog, fmt: "Entering material %s\n", material->name.str);
                  if ( renderLog.logFile != nullptr )
                  {
                    renderLog.indentLabel[renderLog.indentLevel++] = RENDER_LOG_INDENT_DEFAULT;
                    HIBYTE(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
                    BYTE1(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
                    BYTE2(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
                    LOBYTE(renderLog.indentLabel[renderLog.indentLevel + 19]) = 32;
                    renderLog.indentString[4 * renderLog.indentLevel] = 0;
                  }
                  p_renderParmBlock = &material->renderParmBlock;
                  idParmState::VirtualEvaluateParmBlock(
                    this: renderThreadParmState,
                    localParmBlock: p_renderParmBlock,
                    parmBlock: p_renderParmBlock);
                  idParmState::VirtualEvaluateParmBlock(
                    this: renderThreadParmState,
                    localParmBlock: &v48->parmBlock,
                    parmBlock: &v48->parmBlock);
                  *(_QWORD *)((char *)&v50 + 4) = v45->extraGLState;
                  v61.objectPtr = v48;
                  LODWORD(v50) = 0;
                  v59.objectPtr = geometry;
                  GL_DrawElements(prog: &v61, tri: &v59, extraState: v50, skipDetailTriangles: v51);
                  idParmState::VirtualRollbackParmBlock(
                    this: renderThreadParmState,
                    localParmBlock: &v48->parmBlock,
                    parmBlock: &v48->parmBlock);
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
            }
            ++v43;
            ++v44;
          }
          while ( v43 < v4->surfaces.num );
        }
        idParmState::VirtualRollbackParmBlock(
          this: renderThreadParmState,
          localParmBlock: &v4->renderParmBlock,
          parmBlock: &v4->renderParmBlock);
        if ( renderLog.logFile != nullptr && renderLog.indentLevel > 0 )
        {
          --renderLog.indentLevel;
          renderLog.indentString[4 * renderLog.indentLevel] = 0;
        }
      }
      ++v3;
      v52 = parms->numViewAugmentModels;
      ++v55;
    }
    while ( v55 < v52 );
  }
  idRenderLog::CloseMainBlock(this: &renderLog);
}


// ========================================================================
// `dynamic initializer for 'register_RenderAugment''
// EA  : 0x8334C2F0
// RVA : 0x0134C2F0
// PDB : w:\tech5\engine\renderer\jobs\render\renderaugment.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_RenderAugment__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_RenderAugment,
           function: (void (__fastcall *)(void *))RenderAugment,
           name: "RenderAugment");
}

