
// ========================================================================
// ?CaptureViewDepth@@YAXPBUcaptureParms_t@@@Z
// EA  : 0x828D9FE8
// RVA : 0x008D9FE8
// PDB : w:\tech5\engine\renderer\jobs\render\rendercapture_d3d_360.cpp
// ========================================================================

void __fastcall CaptureViewDepth(const captureParms_t *parms)
{
  unsigned int v2; // [sp+8h] [-78h]
  const _D3DRESOLVE_PARAMETERS *v3; // [sp+Ch] [-74h]

  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_CAPTURE_VIEW_DEPTH);
  D3DDevice_Resolve(
    pDevice: wrapperContext.d3d,
    Flags: 4u,
    pSourceRect: nullptr,
    pDestTexture: parms->imgViewDepth->d3dTexture,
    pDestPoint: nullptr,
    DestLevel: 0,
    DestSliceOrFace: 0,
    pClearColor: nullptr,
    ClearZ: 0.0,
    ClearStencil: v2,
    pParameters: v3);
  idRenderLog::CloseMainBlock(this: &renderLog);
}


// ========================================================================
// ?CreateColorMips@@YAXPBUcaptureParms_t@@PBVidRenderDestination@@@Z
// EA  : 0x828DA078
// RVA : 0x008DA078
// PDB : w:\tech5\engine\renderer\jobs\render\rendercapture_d3d_360.cpp
// ========================================================================

void __fastcall CreateColorMips(const captureParms_t *parms, const idRenderDestination *texture)
{
  idImage *v2; // r26
  idImageOpts *p_opts; // r31
  int v6; // r30
  int v7; // r23
  int v8; // r27
  int i; // r29
  __int64 v10; // r11
  int v11; // r10
  int v12; // r9
  int v13; // r8
  int v14; // r7
  int v15; // r6
  int v16; // r5
  int v17; // r4
  const idTriangles *unitSquareTris; // r9
  bool v19; // r7
  idImage *v20; // r3
  int v21; // r10
  double v22; // fp0
  int v23; // r9
  double v24; // fp13
  int v25; // r8
  double v26; // fp12
  int v27; // r7
  double v28; // fp11
  int v29; // r6
  double v30; // fp10
  int v31; // r5
  double v32; // fp9
  int v33; // r4
  double v34; // fp8
  char v35; // r30
  double v36; // fp7
  char v37; // r29
  textureFormat_t v38; // r27
  textureColor_t v39; // r26
  textureFilter_t v40; // r25
  textureRepeat_t v41; // r22
  char v42; // r21
  char v43; // r20
  int renderHeight; // r31
  int renderWidth; // r30
  int v46; // [sp+8h] [-188h]
  idODSObject<idRenderDestination> v47; // [sp+50h] [-140h] BYREF
  idODSObject<idRenderDestination> v48; // [sp+54h] [-13Ch] BYREF
  idODSObject<idDeclRenderProg> v49; // [sp+58h] [-138h] BYREF
  idODSObject<idTriangles> v50; // [sp+5Ch] [-134h] BYREF
  idODSObject<idRenderDestination> v51; // [sp+60h] [-130h] BYREF
  _QWORD v52[12]; // [sp+70h] [-120h] BYREF
  idImageOpts opts; // [sp+D0h] [-C0h] BYREF

  v2 = texture->targetImage[0];
  idDeclRenderParm::SetImage(this: parms->rpViewColor, image: v2);
  p_opts = &v2->opts;
  memcpy(Dst: v52, Src: &v2->opts, Size: 0x50u);
  opts = v2->opts;
  v6 = v2->opts.width >> 1;
  v7 = HIDWORD(v52[2]);
  v8 = 1;
  for ( i = v2->opts.height >> 1; v6 >= 1; ++v8 )
  {
    if ( i < 1 )
      break;
    if ( v8 >= v7 )
      break;
    v51.objectPtr = texture;
    GL_SetRenderDestination(destination: &v51, level: v8, side: 0);
    GL_Viewport(x: 0, y: 0, w: v6, h: i);
    GL_Scissor(x: 0, y: 0, w: v6, h: i);
    idParmState::SetPositionToViewTexture(
      this: renderThreadParmState,
      windowWidth: v6,
      windowHeight: i,
      renderWidth: v6,
      renderHeight: i);
    LODWORD(v10) = v8;
    v52[10] = v10;
    opts.lodBias = (float)v10 - (float)1.0;
    opts.lodMaxClamp = opts.lodBias;
    opts.lodMinClamp = opts.lodBias;
    idImageOpts::operator=(this: &v2->opts, __that: &opts);
    idImage::DetermineSamplerStateFromOpts(
      this: v2,
      a2: v17,
      a3: v16,
      a4: v15,
      a5: v14,
      a6: v13,
      a7: v12,
      a8: v11,
      a9: v46);
    GL_ResetTextureState();
    unitSquareTris = parms->unitSquareTris;
    v49.objectPtr = parms->progOverlappedDownSample;
    v50.objectPtr = unitSquareTris;
    GL_DrawElements(prog: &v49, tri: &v50, extraState: 0, skipDetailTriangles: v19);
    v47.objectPtr = texture;
    GL_ResolveTarget(target: RESOLVE_TARGET_COLOR0, destination: &v47);
    v6 >>= 1;
    i >>= 1;
  }
  v20 = v2;
  v21 = v52[0];
  v22 = *((float *)&v52[5] + 1);
  v23 = HIDWORD(v52[1]);
  v24 = *(float *)&v52[6];
  v25 = v52[1];
  v26 = *((float *)&v52[6] + 1);
  v27 = BYTE4(v52[2]);
  v28 = *(float *)&v52[7];
  v29 = BYTE5(v52[2]);
  v30 = *((float *)&v52[7] + 1);
  v31 = BYTE6(v52[2]);
  v32 = *(float *)&v52[8];
  v33 = LOBYTE(v52[2]);
  v34 = *((float *)&v52[8] + 1);
  v35 = HIBYTE(v52[3]);
  v36 = *(float *)&v52[9];
  v37 = BYTE1(v52[3]);
  v38 = v52[3];
  v39 = HIDWORD(v52[4]);
  v40 = v52[4];
  v41 = HIDWORD(v52[5]);
  v42 = BYTE4(v52[9]);
  v43 = BYTE5(v52[9]);
  p_opts->textureType = HIDWORD(v52[0]);
  p_opts->width = v21;
  p_opts->height = v23;
  p_opts->depth = v25;
  p_opts->numLevels = v7;
  p_opts->packedTail = v27;
  p_opts->readback = v29;
  p_opts->linear = v31;
  p_opts->cubeFilter = v33;
  p_opts->overlayMemory = v35;
  p_opts->startPurged = v37;
  p_opts->format = v38;
  p_opts->colorFormat = v39;
  p_opts->filter = v40;
  p_opts->repeat = v41;
  p_opts->border.x = v22;
  p_opts->border.y = v24;
  p_opts->border.z = v26;
  p_opts->border.w = v28;
  p_opts->forceBias = v42;
  p_opts->lodBias = v30;
  p_opts->depthCompareMode = v43;
  p_opts->lodMinClamp = v32;
  p_opts->lodMaxClamp = v34;
  p_opts->aniso = v36;
  idImage::DetermineSamplerStateFromOpts(
    this: v20,
    a2: v33,
    a3: v31,
    a4: v29,
    a5: v27,
    a6: v25,
    a7: v23,
    a8: v21,
    a9: v46);
  GL_ResetTextureState();
  v48.objectPtr = parms->renderDestDefault;
  GL_SetRenderDestination(destination: &v48, level: 0, side: 0);
  renderHeight = parms->renderHeight;
  renderWidth = parms->renderWidth;
  GL_Viewport(x: 0, y: 0, w: renderWidth, h: renderHeight);
  GL_Scissor(x: 0, y: 0, w: renderWidth, h: renderHeight);
  idParmState::SetPositionToViewTexture(
    this: renderThreadParmState,
    windowWidth: parms->windowWidth,
    windowHeight: parms->windowHeight,
    renderWidth: parms->renderWidth,
    renderHeight: parms->renderHeight);
}


// ========================================================================
// ?CaptureViewColor@@YAXPBUcaptureParms_t@@@Z
// EA  : 0x828DA318
// RVA : 0x008DA318
// PDB : w:\tech5\engine\renderer\jobs\render\rendercapture_d3d_360.cpp
// ========================================================================

void __fastcall CaptureViewColor(const captureParms_t *parms)
{
  unsigned int v2; // [sp+8h] [-88h]
  const _D3DRESOLVE_PARAMETERS *v3; // [sp+Ch] [-84h]
  idODSObject<idRenderDestination> v4; // [sp+70h] [-20h] BYREF

  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_CAPTURE_VIEW_COLOR);
  v4.objectPtr = parms->renderDestDefault;
  GL_SetRenderDestination(destination: &v4, level: 0, side: 0);
  D3DDevice_Resolve(
    pDevice: wrapperContext.d3d,
    Flags: 0,
    pSourceRect: nullptr,
    pDestTexture: parms->renderDestViewColor->targetImage[0]->d3dTexture,
    pDestPoint: nullptr,
    DestLevel: 0,
    DestSliceOrFace: 0,
    pClearColor: nullptr,
    ClearZ: 0.0,
    ClearStencil: v2,
    pParameters: v3);
  idRenderLog::CloseMainBlock(this: &renderLog);
  if ( parms->createMipMaps )
  {
    idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_CAPTURE_VIEW_COLOR_MIPS);
    CreateColorMips(parms, texture: parms->renderDestViewColor);
    idRenderLog::CloseMainBlock(this: &renderLog);
  }
}


// ========================================================================
// ?CaptureFeedback@@YAXPBUcaptureParms_t@@@Z
// EA  : 0x828DA3F0
// RVA : 0x008DA3F0
// PDB : w:\tech5\engine\renderer\jobs\render\rendercapture_d3d_360.cpp
// ========================================================================

void __fastcall CaptureFeedback(const captureParms_t *parms)
{
  D3DDevice *d3d; // r3
  idImage *v3; // r30
  signed int numViews; // r11
  int v5; // r26
  int v6; // r10
  int v7; // r9
  int v8; // r8
  int v9; // r7
  int v10; // r6
  int v11; // r5
  int v12; // r4
  const idTriangles *unitSquareTris; // r7
  int viewIndex; // r10
  int v15; // r10
  int v16; // r9
  int v17; // r8
  int v18; // r7
  int v19; // r6
  int v20; // r5
  int v21; // r4
  unsigned int v22; // [sp+8h] [-178h]
  int v23; // [sp+8h] [-178h]
  int v24; // [sp+8h] [-178h]
  const _D3DRESOLVE_PARAMETERS *v25; // [sp+Ch] [-174h]
  idODSObject<idTriangles> v26; // [sp+70h] [-110h] BYREF
  idODSObject<idRenderDestination> v27; // [sp+74h] [-10Ch] BYREF
  idODSObject<idRenderDestination> v28; // [sp+78h] [-108h] BYREF
  idODSObject<idRenderDestination> v29; // [sp+7Ch] [-104h] BYREF
  idODSObject<idRenderDestination> v30; // [sp+80h] [-100h] BYREF
  idODSObject<idDeclRenderProg> v31; // [sp+84h] [-FCh] BYREF
  idImageOpts v32; // [sp+90h] [-F0h] BYREF
  idImageOpts opts; // [sp+E0h] [-A0h] BYREF

  if ( !parms->settings->skipFeedback )
  {
    idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_CAPTURE_VIEW_FEEDBACK);
    v30.objectPtr = parms->renderDestDefault;
    GL_SetRenderDestination(destination: &v30, level: 0, side: 0);
    d3d = wrapperContext.d3d;
    v3 = parms->renderDestViewColor->targetImage[0];
    numViews = parms->settings->numViews;
    v5 = 128 / numViews;
    __twllei(numViews, 0);
    D3DDevice_Resolve(
      pDevice: d3d,
      Flags: 1u,
      pSourceRect: nullptr,
      pDestTexture: v3->d3dTexture,
      pDestPoint: nullptr,
      DestLevel: 0,
      DestSliceOrFace: 0,
      pClearColor: nullptr,
      ClearZ: 0.0,
      ClearStencil: v22,
      pParameters: v25);
    idRenderDestination::Resize(this: parms->renderDestFeedback, width: 160, height: v5);
    v28.objectPtr = parms->renderDestFeedback;
    GL_SetRenderDestination(destination: &v28, level: 0, side: 0);
    GL_Viewport(x: 0, y: 0, w: 0xA0u, h: v5);
    GL_Scissor(x: 0, y: 0, w: 160, h: v5);
    idParmState::SetPositionToViewTexture(
      this: renderThreadParmState,
      windowWidth: 160,
      windowHeight: v5,
      renderWidth: 0xA0u,
      renderHeight: v5);
    opts = v3->opts;
    v32 = v3->opts;
    v32.lodMinClamp = 0.0;
    v32.lodMaxClamp = 0.0;
    v32.filter = TF_NEAREST;
    v32.lodBias = 0.0;
    idImageOpts::operator=(this: &v3->opts, __that: &v32);
    idImage::DetermineSamplerStateFromOpts(this: v3, a2: v12, a3: v11, a4: v10, a5: v9, a6: v8, a7: v7, a8: v6, a9: v23);
    GL_ResetTextureState();
    idDeclRenderParm::SetImage(this: parms->rpViewColor, image: v3);
    unitSquareTris = parms->unitSquareTris;
    v31.objectPtr = parms->progFeedbackDownSample;
    v26.objectPtr = unitSquareTris;
    GL_DrawElements(prog: &v31, tri: &v26, extraState: 0, skipDetailTriangles: (bool)unitSquareTris);
    idRenderDestination::Resize(this: parms->renderDestFeedback, width: 160, height: 128);
    viewIndex = parms->viewIndex;
    v27.objectPtr = parms->renderDestFeedback;
    GL_ResolveTarget(
      target: RESOLVE_TARGET_COLOR0,
      destination: &v27,
      srcMinX: 0,
      srcMinY: 0,
      srcMaxX: 160,
      srcMaxY: v5,
      dstX: 0,
      dstY: viewIndex * v5);
    idImageOpts::operator=(this: &v3->opts, __that: &opts);
    idImage::DetermineSamplerStateFromOpts(
      this: v3,
      a2: v21,
      a3: v20,
      a4: v19,
      a5: v18,
      a6: v17,
      a7: v16,
      a8: v15,
      a9: v24);
    GL_ResetTextureState();
    v29.objectPtr = parms->renderDestDefault;
    GL_SetRenderDestination(destination: &v29, level: 0, side: 0);
    idParmState::SetPositionToViewTexture(
      this: renderThreadParmState,
      windowWidth: parms->windowWidth,
      windowHeight: parms->windowHeight,
      renderWidth: parms->renderWidth,
      renderHeight: parms->renderHeight);
    if ( parms->forceFullVirtualTextureLoad )
      D3DDevice_BlockUntilIdle(pDevice: wrapperContext.d3d);
    idRenderLog::CloseMainBlock(this: &renderLog);
  }
}


// ========================================================================
// ?CaptureGlareMap@@YAXPBUcaptureParms_t@@@Z
// EA  : 0x828DA638
// RVA : 0x008DA638
// PDB : w:\tech5\engine\renderer\jobs\render\rendercapture_d3d_360.cpp
// ========================================================================

void __fastcall CaptureGlareMap(const captureParms_t *parms)
{
  const idRenderDestination *renderDestMip3; // r11
  unsigned int targetWidth; // r29
  unsigned int targetHeight; // r28
  const idTriangles *unitSquareTris; // r7
  int renderHeight; // r29
  int renderWidth; // r28
  idODSObject<idRenderDestination> v8; // [sp+50h] [-40h] BYREF
  idODSObject<idDeclRenderProg> v9; // [sp+54h] [-3Ch] BYREF
  idODSObject<idTriangles> v10; // [sp+58h] [-38h] BYREF
  idODSObject<idRenderDestination> v11; // [sp+5Ch] [-34h] BYREF
  idODSObject<idRenderDestination> v12; // [sp+60h] [-30h] BYREF

  CaptureViewColor(parms);
  renderDestMip3 = parms->renderDestMip3;
  targetWidth = renderDestMip3->targetWidth;
  targetHeight = renderDestMip3->targetHeight;
  idParmState::SetPositionToViewTexture(
    this: renderThreadParmState,
    windowWidth: targetWidth,
    windowHeight: targetHeight,
    renderWidth: targetWidth,
    renderHeight: targetHeight);
  v8.objectPtr = parms->renderDestMip3;
  GL_SetRenderDestination(destination: &v8, level: 0, side: 0);
  GL_Viewport(x: 0, y: 0, w: targetWidth, h: targetHeight);
  GL_Scissor(x: 0, y: 0, w: targetWidth, h: targetHeight);
  idDeclRenderParm::SetImage(this: parms->rpGlareMap, image: parms->renderDestViewColor->targetImage[0]);
  unitSquareTris = parms->unitSquareTris;
  v9.objectPtr = parms->progGlareScale;
  v10.objectPtr = unitSquareTris;
  GL_DrawElements(prog: &v9, tri: &v10, extraState: 0, skipDetailTriangles: (bool)unitSquareTris);
  v11.objectPtr = parms->renderDestMip3;
  GL_ResolveTarget(target: RESOLVE_TARGET_COLOR0, destination: &v11);
  v12.objectPtr = parms->renderDestDefault;
  GL_SetRenderDestination(destination: &v12, level: 0, side: 0);
  renderHeight = parms->renderHeight;
  renderWidth = parms->renderWidth;
  GL_Viewport(x: 0, y: 0, w: renderWidth, h: renderHeight);
  GL_Scissor(x: 0, y: 0, w: renderWidth, h: renderHeight);
  idParmState::SetPositionToViewTexture(
    this: renderThreadParmState,
    windowWidth: parms->windowWidth,
    windowHeight: parms->windowHeight,
    renderWidth: parms->renderWidth,
    renderHeight: parms->renderHeight);
}


// ========================================================================
// ?CaptureGuiImage@@YAXPBUcaptureParms_t@@@Z
// EA  : 0x828DA768
// RVA : 0x008DA768
// PDB : w:\tech5\engine\renderer\jobs\render\rendercapture_d3d_360.cpp
// ========================================================================

void __fastcall CaptureGuiImage(const captureParms_t *parms, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v6; // [sp+8h] [-68h]
  int v7; // [sp+Ch] [-64h]
  int v8; // [sp+10h] [-60h]
  int v9; // [sp+14h] [-5Ch]
  int v10; // [sp+18h] [-58h]
  int v11; // [sp+1Ch] [-54h]
  idODSObject<idRenderDestination> v12; // [sp+50h] [-20h] BYREF

  LODWORD(a5) = &off_82230000;
  idRenderLog::OpenBlock(
    this: &renderLog,
    fmt: "Capture Gui Image",
    a3,
    a4,
    a5,
    a6: v6,
    a7: v7,
    a8: v8,
    a9: v9,
    a10: v10,
    a11: v11);
  v12.objectPtr = parms->renderDestGui;
  GL_ResolveTarget(target: RESOLVE_TARGET_COLOR0, destination: &v12);
  CreateColorMips(parms, texture: parms->renderDestGui);
  if ( renderLog.logFile != nullptr )
    idRenderLog::LogCloseBlock(this: &renderLog, label: RENDER_LOG_INDENT_BLOCK);
}

