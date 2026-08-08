
// ========================================================================
// ?RenderPostProcess@@YAXPBUrenderPostProcessParms_t@@@Z
// EA  : 0x828E1BA0
// RVA : 0x008E1BA0
// PDB : w:\tech5\engine\renderer\jobs\render\renderpostprocess.cpp
// ========================================================================

void __fastcall RenderPostProcess(const renderPostProcessParms_t *parms)
{
  const idRenderView *renderView; // r11
  const idRenderView *v3; // r11
  const idImage *imgBlack; // r4
  idDeclRenderParm *rpAdaptiveGlareMap; // r3
  const idImage *imgAdaptiveGlareLuminance; // r4
  double v7; // fp0
  parmValue_t *v8; // r3
  float v9; // r10
  float v10; // r8
  float v11; // r7
  double v12; // fp13
  double v13; // fp0
  double v14; // fp0
  const idDeclRenderProg *renamed; // r28
  bool v16; // r7
  idODSObject<idDeclRenderProg> v17; // [sp+50h] [-50h] BYREF
  idODSObject<idTriangles> v18; // [sp+54h] [-4Ch] BYREF
  idPlane v19; // [sp+60h] [-40h] BYREF

  GL_SetDefaultState();
  D3DDevice_SetShaderGPRAllocation(
    pDevice: wrapperContext.d3d,
    Flags: 0,
    VertexShaderCount: 0x10u,
    PixelShaderCount: 0x70u);
  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_RENDER_POST_PROCESS);
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
  idDeclRenderParm::SetImage(this: parms->rpViewColor, image: parms->imgViewColor);
  if ( parms->settings->skipEmissiveGlare )
    imgBlack = parms->imgBlack;
  else
    imgBlack = parms->imgGlare;
  idDeclRenderParm::SetImage(this: parms->rpGlareMap, image: imgBlack);
  rpAdaptiveGlareMap = parms->rpAdaptiveGlareMap;
  if ( parms->settings->skipAdaptiveGlare )
  {
    idDeclRenderParm::SetImage(this: rpAdaptiveGlareMap, image: parms->imgBlack);
    imgAdaptiveGlareLuminance = parms->imgBlack;
  }
  else
  {
    idDeclRenderParm::SetImage(this: rpAdaptiveGlareMap, image: parms->imgAdaptiveGlare);
    imgAdaptiveGlareLuminance = parms->imgAdaptiveGlareLuminance;
  }
  idDeclRenderParm::SetImage(this: parms->rpAdaptiveGlareLuminance, image: imgAdaptiveGlareLuminance);
  idDeclRenderParm::SetImage(this: parms->rpDistortionMap, image: parms->imgDistortion);
  v7 = parms->renderView->projectionMatrix.m[11];
  v8 = &renderThreadParmState->values[parms->rpDepthOfField->parmIndex];
  v9 = v8->value[1];
  v10 = v8->value[2];
  v11 = v8->value[3];
  LODWORD(v19.a) = v8->swizzle[0];
  v19.b = v9;
  v19.c = v10;
  v19.d = v11;
  v12 = (float)((float)v7 + v19.a);
  v13 = (float)((float)((float)v7 + v19.a) - v9);
  v19.a = v12;
  if ( __fabs(v13) >= idMath::FLT_SMALLEST_NON_DENORMAL )
    v14 = (float)((float)1.0 / (float)v13);
  else
    v14 = 0.0;
  v19.b = v14;
  if ( __fabs((float)(v19.c - (float)v12)) >= idMath::FLT_SMALLEST_NON_DENORMAL )
    v19.c = (float)1.0 / (float)(v19.c - (float)v12);
  else
    v19.c = 1.0;
  idDeclRenderParm::Set(this: parms->rpDepthOfField2, plane: &v19);
  renamed = parms->progPostProcess->renamed;
  idParmState::VirtualEvaluateParmBlock(
    this: renderThreadParmState,
    localParmBlock: &renamed->parmBlock,
    parmBlock: &renamed->parmBlock);
  v18.objectPtr = parms->unitSquareTris;
  v17.objectPtr = renamed;
  GL_DrawElements(prog: &v17, tri: &v18, extraState: 0, skipDetailTriangles: v16);
  idParmState::VirtualRollbackParmBlock(
    this: renderThreadParmState,
    localParmBlock: &renamed->parmBlock,
    parmBlock: &renamed->parmBlock);
  idRenderLog::CloseMainBlock(this: &renderLog);
}

