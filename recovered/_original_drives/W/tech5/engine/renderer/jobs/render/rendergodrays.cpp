
// ========================================================================
// ?RenderGodRays@@YAXPBUrenderGodRaysParms_t@@@Z
// EA  : 0x828DF8B8
// RVA : 0x008DF8B8
// PDB : w:\tech5\engine\renderer\jobs\render\rendergodrays.cpp
// ========================================================================

void __fastcall RenderGodRays(const renderGodRaysParms_t *parms)
{
  BOOL godRaysRelativeToCamera; // r11
  double x; // fp0
  double y; // fp13
  double z; // fp12
  const idRenderView *renderView; // r10
  double v7; // fp7
  double v8; // fp6
  _BYTE v9[12]; // r6
  double w; // fp0
  double godRaysSourceSize; // fp8
  double godRaysSize; // fp7
  double v13; // fp13
  double v14; // fp11
  double v15; // fp27
  double v16; // fp28
  double v17; // fp0
  double v18; // fp25
  double v19; // fp0
  double v20; // fp26
  double v21; // fp0
  double v22; // fp29
  double v23; // fp0
  double v24; // fp30
  double v25; // fp6
  double v26; // fp5
  idDeclRenderParm *rpGodRaysColor; // r3
  const idImage *Image; // r3
  const idTriangles *unitSquareTris; // r9
  bool v30; // r7
  const idRenderView *v31; // r11
  const idRenderView *v32; // r11
  const idTriangles *v33; // r7
  idVec4 v34; // [sp+50h] [-E0h] BYREF
  idVec4 v35; // [sp+60h] [-D0h] BYREF
  idODSObject<idDeclRenderProg> v36; // [sp+70h] [-C0h] BYREF
  idODSObject<idTriangles> v37; // [sp+74h] [-BCh] BYREF
  idODSObject<idDeclRenderProg> v38; // [sp+78h] [-B8h] BYREF
  idODSObject<idRenderDestination> v39; // [sp+7Ch] [-B4h] BYREF
  idODSObject<idRenderDestination> v40; // [sp+80h] [-B0h] BYREF
  idODSObject<idTriangles> v41; // [sp+84h] [-ACh] BYREF
  idODSObject<idRenderDestination> v42; // [sp+88h] [-A8h] BYREF
  idPlane v43; // [sp+90h] [-A0h] BYREF
  idRenderMatrix v44; // [sp+A0h] [-90h] BYREF

  idRenderMatrix::Multiply(a: &parms->renderView->projectionMatrix, b: &parms->renderView->viewMatrix, out: &v44);
  godRaysRelativeToCamera = parms->godRaysRelativeToCamera;
  x = parms->godRaysPosition.x;
  y = parms->godRaysPosition.y;
  z = parms->godRaysPosition.z;
  v34.w = 1.0;
  if ( godRaysRelativeToCamera )
  {
    renderView = parms->renderView;
    v7 = (float)((float)y + renderView->inverseViewMatrix.m[7]);
    v8 = (float)((float)z + renderView->inverseViewMatrix.m[11]);
    v34.x = (float)x + renderView->inverseViewMatrix.m[3];
    v34.y = v7;
    v34.z = v8;
  }
  else
  {
    v34.x = x;
    v34.y = y;
    v34.z = z;
  }
  idRenderMatrix::TransformPoint(this: &v44, in: &v34, out: &v35);
  w = v35.w;
  if ( v35.w >= (double)idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    godRaysSourceSize = parms->godRaysSourceSize;
    godRaysSize = parms->godRaysSize;
    *(_QWORD *)&v9[4] = *(_QWORD *)&parms->renderView->renderWidth;
    *(_QWORD *)&v34.x = *(_QWORD *)v9;
    v13 = (float)((float)((float)1.0 / v35.w) * v35.x);
    v43.c = (float)((float)1.0 / v35.w) * v35.x;
    v14 = (float)((float)((float)1.0 / v35.w) * v35.y);
    v43.d = (float)((float)1.0 / v35.w) * v35.y;
    v35.z = (float)(v43.c * (float)0.5) + (float)0.5;
    v35.w = (float)(v43.d * (float)0.5) + (float)0.5;
    v15 = (float)((float)godRaysSourceSize * (float)((float)1.0 / (float)*(__int64 *)&v9[4]));
    v43.b = (float)godRaysSourceSize * (float)((float)1.0 / (float)*(__int64 *)&v9[4]);
    v35.y = (float)godRaysSize * (float)((float)1.0 / (float)*(__int64 *)&v9[4]);
    v16 = (float)((float)godRaysSourceSize * (float)((float)1.0 / (float)*(__int64 *)v9));
    v43.a = (float)godRaysSourceSize * (float)((float)1.0 / (float)*(__int64 *)v9);
    v17 = (float)((float)((float)((float)1.0 / (float)w) * v35.x) - v43.a);
    v35.x = (float)godRaysSize * (float)((float)1.0 / (float)*(__int64 *)v9);
    if ( v17 >= -1.0 )
    {
      if ( v17 <= 1.0 )
        v18 = v17;
      else
        v18 = 1.0;
    }
    else
    {
      v18 = -1.0;
    }
    v19 = (float)((float)v13 + (float)((float)godRaysSourceSize * (float)((float)1.0 / (float)*(__int64 *)v9)));
    if ( v19 >= -1.0 )
    {
      if ( v19 <= 1.0 )
        v20 = (float)((float)v13 + (float)((float)godRaysSourceSize * (float)((float)1.0 / (float)*(__int64 *)v9)));
      else
        v20 = 1.0;
    }
    else
    {
      v20 = -1.0;
    }
    v21 = (float)((float)v14 - (float)((float)godRaysSourceSize * (float)((float)1.0 / (float)*(__int64 *)&v9[4])));
    if ( v21 >= -1.0 )
    {
      if ( v21 <= 1.0 )
        v22 = (float)((float)v14 - (float)((float)godRaysSourceSize * (float)((float)1.0 / (float)*(__int64 *)&v9[4])));
      else
        v22 = 1.0;
    }
    else
    {
      v22 = -1.0;
    }
    v23 = (float)((float)v14 + (float)((float)godRaysSourceSize * (float)((float)1.0 / (float)*(__int64 *)&v9[4])));
    if ( v23 >= -1.0 )
    {
      if ( v23 <= 1.0 )
        v24 = (float)((float)v14 + (float)((float)godRaysSourceSize * (float)((float)1.0 / (float)*(__int64 *)&v9[4])));
      else
        v24 = 1.0;
    }
    else
    {
      v24 = -1.0;
    }
    if ( v20 > -1.0 && v18 < 1.0 && v24 > -1.0 && v22 < 1.0 )
    {
      idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_RENDER_GOD_RAYS);
      GL_SetDefaultState();
      v25 = parms->godRaysColor.y;
      v26 = parms->godRaysColor.z;
      v34.x = parms->godRaysColor.x;
      rpGodRaysColor = parms->rpGodRaysColor;
      v34.y = v25;
      v34.z = v26;
      v34.w = (float)((float)((float)v24 - (float)v22) * (float)((float)v20 - (float)v18))
            / (float)((float)((float)v15 * (float)2.0) * (float)((float)v16 * (float)2.0));
      idDeclRenderParm::Set(this: rpGodRaysColor, plane: (const idPlane *)&v34);
      idDeclRenderParm::Set(this: parms->rpScaleBiasSource, plane: &v43);
      idDeclRenderParm::Set(this: parms->rpScaleBiasQuad, plane: (const idPlane *)&v35);
      v40.objectPtr = parms->renderDestOffScreen;
      GL_SetRenderDestination(destination: &v40, level: 0, side: 0);
      GL_Viewport(x: 0, y: 0, w: parms->renderDestOffScreen->targetWidth, h: parms->renderDestOffScreen->targetHeight);
      GL_Scissor(x: 0, y: 0, w: parms->renderDestOffScreen->targetWidth, h: parms->renderDestOffScreen->targetHeight);
      GL_Clear(color: true, depth: false, stencil: false, stencilValue: 0, r: 0.0, g: 0.0, b: 0.0, a: 0.0);
      Image = idParmBlock::GetImage(this: &parms->godRaysMaterial->parmBlock, parm: parms->rpTransMap);
      idDeclRenderParm::SetImage(this: parms->rpTransMap, image: Image);
      unitSquareTris = parms->unitSquareTris;
      v38.objectPtr = parms->progCreateGodRays;
      v41.objectPtr = unitSquareTris;
      GL_DrawElements(prog: &v38, tri: &v41, extraState: 0, skipDetailTriangles: v30);
      v42.objectPtr = parms->renderDestOffScreen;
      GL_ResolveTarget(target: RESOLVE_TARGET_COLOR0, destination: &v42);
      v39.objectPtr = parms->renderDestDefault;
      GL_SetRenderDestination(destination: &v39, level: 0, side: 0);
      idDeclRenderParm::SetImage(this: parms->rpGodRayMap, image: parms->imgOffScreen);
      v31 = parms->renderView;
      GL_Viewport(
        x: v31->viewport.x1,
        y: v31->viewport.y1,
        w: v31->viewport.x2 - v31->viewport.x1 + 1,
        h: v31->viewport.y2 - v31->viewport.y1 + 1);
      v32 = parms->renderView;
      GL_Scissor(
        x: v32->scissorRect.x1,
        y: v32->scissorRect.y1,
        w: v32->scissorRect.x2 - v32->scissorRect.x1 + 1,
        h: v32->scissorRect.y2 - v32->scissorRect.y1 + 1);
      v33 = parms->unitSquareTris;
      v36.objectPtr = parms->progDrawGodRays;
      v37.objectPtr = v33;
      GL_DrawElements(prog: &v36, tri: &v37, extraState: 0, skipDetailTriangles: (bool)v33);
      idRenderLog::CloseMainBlock(this: &renderLog);
    }
  }
}

