
// ========================================================================
// ?RenderGlare@@YAXPBUrenderGlareParms_t@@@Z
// EA  : 0x828DF208
// RVA : 0x008DF208
// PDB : w:\tech5\engine\renderer\jobs\render\renderglare.cpp
// ========================================================================

void __fastcall RenderGlare(const renderGlareParms_t *parms)
{
  const idRenderDestination *renderDestMip3; // r10
  unsigned int targetWidth; // r28
  unsigned int targetHeight; // r27
  const idTriangles *unitSquareTris; // r10
  bool v6; // r7
  const idTriangles *v7; // r10
  bool v8; // r7
  const idRenderView *renderView; // r11
  const idRenderView *v10; // r11
  idODSObject<idRenderDestination> v11; // [sp+50h] [-60h] BYREF
  idODSObject<idDeclRenderProg> v12; // [sp+54h] [-5Ch] BYREF
  idODSObject<idTriangles> v13; // [sp+58h] [-58h] BYREF
  idODSObject<idRenderDestination> v14; // [sp+5Ch] [-54h] BYREF
  idODSObject<idRenderDestination> v15; // [sp+60h] [-50h] BYREF
  idODSObject<idDeclRenderProg> v16; // [sp+64h] [-4Ch] BYREF
  idODSObject<idTriangles> v17; // [sp+68h] [-48h] BYREF
  idODSObject<idRenderDestination> v18; // [sp+6Ch] [-44h] BYREF
  idODSObject<idRenderDestination> v19; // [sp+70h] [-40h] BYREF

  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_RENDER_GLARE);
  renderDestMip3 = parms->renderDestMip3;
  targetWidth = renderDestMip3->targetWidth;
  targetHeight = renderDestMip3->targetHeight;
  idParmState::SetPositionToViewTexture(
    this: renderThreadParmState,
    windowWidth: targetWidth,
    windowHeight: targetHeight,
    renderWidth: targetWidth,
    renderHeight: targetHeight);
  v11.objectPtr = parms->renderDestMip3Alt;
  GL_SetRenderDestination(destination: &v11, level: 0, side: 0);
  GL_Viewport(x: 0, y: 0, w: targetWidth, h: targetHeight);
  GL_Scissor(x: 0, y: 0, w: targetWidth, h: targetHeight);
  idDeclRenderParm::SetImage(this: parms->rpGlareMap, image: parms->renderDestMip3->targetImage[0]);
  idDeclRenderParm::Set(this: parms->rpGlareStep, x: parms->xScale, y: 0.0, z: 0.0, w: 0.0);
  unitSquareTris = parms->unitSquareTris;
  v12.objectPtr = parms->progGauss;
  v13.objectPtr = unitSquareTris;
  GL_DrawElements(prog: &v12, tri: &v13, extraState: 0, skipDetailTriangles: v6);
  v14.objectPtr = parms->renderDestMip3Alt;
  GL_ResolveTarget(target: RESOLVE_TARGET_COLOR0, destination: &v14);
  v15.objectPtr = parms->renderDestMip3;
  GL_SetRenderDestination(destination: &v15, level: 0, side: 0);
  GL_Viewport(x: 0, y: 0, w: targetWidth, h: targetHeight);
  GL_Scissor(x: 0, y: 0, w: targetWidth, h: targetHeight);
  idDeclRenderParm::SetImage(this: parms->rpGlareMap, image: parms->renderDestMip3Alt->targetImage[0]);
  idDeclRenderParm::Set(this: parms->rpGlareStep, x: 0.0, y: parms->yScale, z: 0.0, w: 0.0);
  v7 = parms->unitSquareTris;
  v16.objectPtr = parms->progGauss;
  v17.objectPtr = v7;
  GL_DrawElements(prog: &v16, tri: &v17, extraState: 0, skipDetailTriangles: v8);
  v18.objectPtr = parms->renderDestMip3;
  GL_ResolveTarget(target: RESOLVE_TARGET_COLOR0, destination: &v18);
  v19.objectPtr = parms->renderDestDefault;
  GL_SetRenderDestination(destination: &v19, level: 0, side: 0);
  renderView = parms->renderView;
  GL_Viewport(
    x: renderView->viewport.x1,
    y: renderView->viewport.y1,
    w: renderView->viewport.x2 - renderView->viewport.x1 + 1,
    h: renderView->viewport.y2 - renderView->viewport.y1 + 1);
  v10 = parms->renderView;
  GL_Scissor(
    x: v10->scissorRect.x1,
    y: v10->scissorRect.y1,
    w: v10->scissorRect.x2 - v10->scissorRect.x1 + 1,
    h: v10->scissorRect.y2 - v10->scissorRect.y1 + 1);
  idParmState::SetPositionToViewTexture(
    this: renderThreadParmState,
    windowWidth: parms->renderView->windowWidth,
    windowHeight: parms->renderView->windowHeight,
    renderWidth: parms->renderView->renderWidth,
    renderHeight: parms->renderView->renderHeight);
  idRenderLog::CloseMainBlock(this: &renderLog);
}


// ========================================================================
// ?RenderAdaptiveGlare@@YAXPBUrenderAdapativeGlareParms_t@@@Z
// EA  : 0x828DF438
// RVA : 0x008DF438
// PDB : w:\tech5\engine\renderer\jobs\render\renderglare.cpp
// ========================================================================

void __fastcall RenderAdaptiveGlare(const renderAdapativeGlareParms_t *parms)
{
  const idRenderDestination *renderDestLuminosity; // r29
  __int64 v3; // r10
  __int64 v4; // r8
  __int64 v5; // r6
  unsigned int targetWidth; // r27
  unsigned int targetHeight; // r26
  const idTriangles *unitSquareTris; // r9
  bool v9; // r7
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  const idImage *v13; // r29
  const idRenderDestination *renderDestAdaptiveGlare; // r10
  unsigned int v15; // r27
  unsigned int v16; // r26
  const idTriangles *v17; // r7
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r6
  const idRenderDestination *renderDestAdaptiveGlareAlt; // r10
  unsigned int v22; // r29
  unsigned int v23; // r27
  const idTriangles *v24; // r10
  bool v25; // r7
  __int64 v26; // r10
  __int64 v27; // r8
  __int64 v28; // r6
  const idRenderDestination *v29; // r10
  unsigned int v30; // r29
  unsigned int v31; // r27
  const idTriangles *v32; // r11
  const idRenderView *renderView; // r11
  const idRenderView *v34; // r11
  int v35; // [sp+8h] [-D8h]
  int v36; // [sp+8h] [-D8h]
  int v37; // [sp+8h] [-D8h]
  int v38; // [sp+8h] [-D8h]
  int v39; // [sp+Ch] [-D4h]
  int v40; // [sp+Ch] [-D4h]
  int v41; // [sp+Ch] [-D4h]
  int v42; // [sp+Ch] [-D4h]
  int v43; // [sp+10h] [-D0h]
  int v44; // [sp+10h] [-D0h]
  int v45; // [sp+10h] [-D0h]
  int v46; // [sp+10h] [-D0h]
  int v47; // [sp+14h] [-CCh]
  int v48; // [sp+14h] [-CCh]
  int v49; // [sp+14h] [-CCh]
  int v50; // [sp+14h] [-CCh]
  int v51; // [sp+18h] [-C8h]
  int v52; // [sp+18h] [-C8h]
  int v53; // [sp+18h] [-C8h]
  int v54; // [sp+18h] [-C8h]
  int v55; // [sp+1Ch] [-C4h]
  int v56; // [sp+1Ch] [-C4h]
  int v57; // [sp+1Ch] [-C4h]
  int v58; // [sp+1Ch] [-C4h]
  idODSObject<idRenderDestination> v59; // [sp+50h] [-90h] BYREF
  idODSObject<idDeclRenderProg> v60; // [sp+54h] [-8Ch] BYREF
  idODSObject<idTriangles> v61; // [sp+58h] [-88h] BYREF
  idODSObject<idRenderDestination> v62; // [sp+5Ch] [-84h] BYREF
  idODSObject<idRenderDestination> v63; // [sp+60h] [-80h] BYREF
  idODSObject<idDeclRenderProg> v64; // [sp+64h] [-7Ch] BYREF
  idODSObject<idTriangles> v65; // [sp+68h] [-78h] BYREF
  idODSObject<idRenderDestination> v66; // [sp+6Ch] [-74h] BYREF
  idODSObject<idRenderDestination> v67; // [sp+70h] [-70h] BYREF
  idODSObject<idDeclRenderProg> v68; // [sp+74h] [-6Ch] BYREF
  idODSObject<idTriangles> v69; // [sp+78h] [-68h] BYREF
  idODSObject<idRenderDestination> v70; // [sp+7Ch] [-64h] BYREF
  idODSObject<idRenderDestination> v71; // [sp+80h] [-60h] BYREF
  idODSObject<idDeclRenderProg> v72; // [sp+84h] [-5Ch] BYREF
  idODSObject<idTriangles> v73; // [sp+88h] [-58h] BYREF
  idODSObject<idRenderDestination> v74; // [sp+8Ch] [-54h] BYREF
  idODSObject<idRenderDestination> v75; // [sp+90h] [-50h] BYREF

  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_RENDER_GLARE);
  renderDestLuminosity = parms->renderDestLuminosity;
  idDeclRenderParm::Set(
    this: parms->rpAdaptiveGlareParms,
    x: parms->minThreshold,
    y: parms->maxThreshold,
    z: parms->avgBrightness,
    w: parms->decayRate);
  idRenderLog::OpenBlock(
    this: &renderLog,
    fmt: "Luminance",
    a3: v5,
    a4: v4,
    a5: v3,
    a6: v35,
    a7: v39,
    a8: v43,
    a9: v47,
    a10: v51,
    a11: v55);
  targetWidth = renderDestLuminosity->targetWidth;
  targetHeight = renderDestLuminosity->targetHeight;
  idParmState::SetPositionToViewTexture(
    this: renderThreadParmState,
    windowWidth: targetWidth,
    windowHeight: targetHeight,
    renderWidth: targetWidth,
    renderHeight: targetHeight);
  v59.objectPtr = renderDestLuminosity;
  GL_SetRenderDestination(destination: &v59, level: 0, side: 0);
  GL_Viewport(x: 0, y: 0, w: targetWidth, h: targetHeight);
  GL_Scissor(x: 0, y: 0, w: targetWidth, h: targetHeight);
  idDeclRenderParm::SetImage(this: parms->rpViewColor, image: parms->imgViewColor);
  idDeclRenderParm::SetImage(this: parms->rpAdaptiveLuminance, image: renderDestLuminosity->targetImage[0]);
  unitSquareTris = parms->unitSquareTris;
  v60.objectPtr = parms->progLuminosity;
  v61.objectPtr = unitSquareTris;
  GL_DrawElements(prog: &v60, tri: &v61, extraState: 0, skipDetailTriangles: v9);
  v62.objectPtr = renderDestLuminosity;
  GL_ResolveTarget(target: RESOLVE_TARGET_COLOR0, destination: &v62);
  if ( renderLog.logFile != nullptr )
    idRenderLog::LogCloseBlock(this: &renderLog, label: RENDER_LOG_INDENT_BLOCK);
  v13 = renderDestLuminosity->targetImage[0];
  idRenderLog::OpenBlock(
    this: &renderLog,
    fmt: "Bloom Threshold",
    a3: v12,
    a4: v11,
    a5: v10,
    a6: v36,
    a7: v40,
    a8: v44,
    a9: v48,
    a10: v52,
    a11: v56);
  renderDestAdaptiveGlare = parms->renderDestAdaptiveGlare;
  v15 = renderDestAdaptiveGlare->targetWidth;
  v16 = renderDestAdaptiveGlare->targetHeight;
  idParmState::SetPositionToViewTexture(
    this: renderThreadParmState,
    windowWidth: v15,
    windowHeight: v16,
    renderWidth: v15,
    renderHeight: v16);
  v63.objectPtr = parms->renderDestAdaptiveGlare;
  GL_SetRenderDestination(destination: &v63, level: 0, side: 0);
  GL_Viewport(x: 0, y: 0, w: v15, h: v16);
  GL_Scissor(x: 0, y: 0, w: v15, h: v16);
  idDeclRenderParm::SetImage(this: parms->rpAdaptiveLuminance, image: v13);
  idDeclRenderParm::SetImage(this: parms->rpViewColor, image: parms->imgViewColor);
  idDeclRenderParm::SetImage(this: parms->rpGlareMap, image: parms->imgGlare);
  v17 = parms->unitSquareTris;
  v64.objectPtr = parms->progBloomThreshold;
  v65.objectPtr = v17;
  GL_DrawElements(prog: &v64, tri: &v65, extraState: 0, skipDetailTriangles: (bool)v17);
  v66.objectPtr = parms->renderDestAdaptiveGlare;
  GL_ResolveTarget(target: RESOLVE_TARGET_COLOR0, destination: &v66);
  if ( renderLog.logFile != nullptr )
    idRenderLog::LogCloseBlock(this: &renderLog, label: RENDER_LOG_INDENT_BLOCK);
  idRenderLog::OpenBlock(
    this: &renderLog,
    fmt: "Horizontal Blur",
    a3: v20,
    a4: v19,
    a5: v18,
    a6: v37,
    a7: v41,
    a8: v45,
    a9: v49,
    a10: v53,
    a11: v57);
  renderDestAdaptiveGlareAlt = parms->renderDestAdaptiveGlareAlt;
  v22 = renderDestAdaptiveGlareAlt->targetWidth;
  v23 = renderDestAdaptiveGlareAlt->targetHeight;
  idParmState::SetPositionToViewTexture(
    this: renderThreadParmState,
    windowWidth: v22,
    windowHeight: v23,
    renderWidth: v22,
    renderHeight: v23);
  v67.objectPtr = parms->renderDestAdaptiveGlareAlt;
  GL_SetRenderDestination(destination: &v67, level: 0, side: 0);
  GL_Viewport(x: 0, y: 0, w: v22, h: v23);
  GL_Scissor(x: 0, y: 0, w: v22, h: v23);
  idDeclRenderParm::SetImage(this: parms->rpAdaptiveGlareBlurMap, image: parms->renderDestAdaptiveGlare->targetImage[0]);
  idDeclRenderParm::Set(this: parms->rpAdaptiveGlareBlurStep, x: parms->xScale, y: 0.0, z: 0.0, w: 0.0);
  v24 = parms->unitSquareTris;
  v68.objectPtr = parms->progAdaptiveGlareGauss;
  v69.objectPtr = v24;
  GL_DrawElements(prog: &v68, tri: &v69, extraState: 0, skipDetailTriangles: v25);
  v70.objectPtr = parms->renderDestAdaptiveGlareAlt;
  GL_ResolveTarget(target: RESOLVE_TARGET_COLOR0, destination: &v70);
  if ( renderLog.logFile != nullptr )
    idRenderLog::LogCloseBlock(this: &renderLog, label: RENDER_LOG_INDENT_BLOCK);
  idRenderLog::OpenBlock(
    this: &renderLog,
    fmt: "Vertical Blur",
    a3: v28,
    a4: v27,
    a5: v26,
    a6: v38,
    a7: v42,
    a8: v46,
    a9: v50,
    a10: v54,
    a11: v58);
  v29 = parms->renderDestAdaptiveGlare;
  v30 = v29->targetWidth;
  v31 = v29->targetHeight;
  idParmState::SetPositionToViewTexture(
    this: renderThreadParmState,
    windowWidth: v30,
    windowHeight: v31,
    renderWidth: v30,
    renderHeight: v31);
  v71.objectPtr = parms->renderDestAdaptiveGlare;
  GL_SetRenderDestination(destination: &v71, level: 0, side: 0);
  GL_Viewport(x: 0, y: 0, w: v30, h: v31);
  GL_Scissor(x: 0, y: 0, w: v30, h: v31);
  idDeclRenderParm::SetImage(
    this: parms->rpAdaptiveGlareBlurMap,
    image: parms->renderDestAdaptiveGlareAlt->targetImage[0]);
  idDeclRenderParm::Set(this: parms->rpAdaptiveGlareBlurStep, x: 0.0, y: parms->yScale, z: 0.0, w: 0.0);
  v32 = parms->unitSquareTris;
  v72.objectPtr = parms->progAdaptiveGlareGauss;
  v73.objectPtr = v32;
  GL_DrawElements(prog: &v72, tri: &v73, extraState: 0, skipDetailTriangles: (bool)v72.objectPtr);
  v74.objectPtr = parms->renderDestAdaptiveGlare;
  GL_ResolveTarget(target: RESOLVE_TARGET_COLOR0, destination: &v74);
  if ( renderLog.logFile != nullptr )
    idRenderLog::LogCloseBlock(this: &renderLog, label: RENDER_LOG_INDENT_BLOCK);
  v75.objectPtr = parms->renderDestDefault;
  GL_SetRenderDestination(destination: &v75, level: 0, side: 0);
  renderView = parms->renderView;
  GL_Viewport(
    x: renderView->viewport.x1,
    y: renderView->viewport.y1,
    w: renderView->viewport.x2 - renderView->viewport.x1 + 1,
    h: renderView->viewport.y2 - renderView->viewport.y1 + 1);
  v34 = parms->renderView;
  GL_Scissor(
    x: v34->scissorRect.x1,
    y: v34->scissorRect.y1,
    w: v34->scissorRect.x2 - v34->scissorRect.x1 + 1,
    h: v34->scissorRect.y2 - v34->scissorRect.y1 + 1);
  idParmState::SetPositionToViewTexture(
    this: renderThreadParmState,
    windowWidth: parms->renderView->windowWidth,
    windowHeight: parms->renderView->windowHeight,
    renderWidth: parms->renderView->renderWidth,
    renderHeight: parms->renderView->renderHeight);
  idRenderLog::CloseMainBlock(this: &renderLog);
}

