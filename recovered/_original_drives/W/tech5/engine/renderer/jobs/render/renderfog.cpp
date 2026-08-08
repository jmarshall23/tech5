
// ========================================================================
// ?RenderFog@@YAXPBUrenderFogParms_t@@@Z
// EA  : 0x828DD9C0
// RVA : 0x008DD9C0
// PDB : w:\tech5\engine\renderer\jobs\render\renderfog.cpp
// ========================================================================

void __fastcall RenderFog(const renderFogParms_t *parms)
{
  const idRenderView *renderView; // r11
  const idRenderView *v3; // r11
  const idDeclRenderProg *renamed; // r30
  bool v5; // r7
  idODSObject<idDeclRenderProg> v6; // [sp+50h] [-40h] BYREF
  idODSObject<idTriangles> v7; // [sp+54h] [-3Ch] BYREF

  GL_SetDefaultState();
  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_RENDER_FOG);
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
  renamed = parms->progGlobalFog->renamed;
  idParmState::VirtualEvaluateParmBlock(
    this: renderThreadParmState,
    localParmBlock: &renamed->parmBlock,
    parmBlock: &renamed->parmBlock);
  v7.objectPtr = parms->unitSquareTris;
  v6.objectPtr = renamed;
  GL_DrawElements(prog: &v6, tri: &v7, extraState: 0, skipDetailTriangles: v5);
  idParmState::VirtualRollbackParmBlock(
    this: renderThreadParmState,
    localParmBlock: &renamed->parmBlock,
    parmBlock: &renamed->parmBlock);
  idRenderLog::CloseMainBlock(this: &renderLog);
}

