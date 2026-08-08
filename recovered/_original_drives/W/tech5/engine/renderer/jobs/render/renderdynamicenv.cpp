
// ========================================================================
// ?RenderDynamicEnv@@YAXPBUrenderDynamicEnvParms_t@@@Z
// EA  : 0x828DD648
// RVA : 0x008DD648
// PDB : w:\tech5\engine\renderer\jobs\render\renderdynamicenv.cpp
// ========================================================================

void __fastcall RenderDynamicEnv(const renderDynamicEnvParms_t *parms)
{
  envBlend_t *envBlend; // r8
  __int64 v3; // r6
  double v4; // fp11
  double v5; // fp29
  int v6; // r30
  _DWORD *v7; // r29
  const int *v8; // r9
  int v9; // r11
  int v10; // r11
  int v11; // r11
  int v12; // r11
  __int64 v13; // r11
  int v14; // r28
  int width; // r30
  idDeclRenderParm *rpEnvBlendMip; // r3
  int v17; // r29
  const idRenderMatrix *v18; // r27
  const idTriangles *unitCubeTris; // r9
  bool v20; // r7
  const idImage *imgAmbientEnv; // r4
  const idTriangles *v22; // r10
  bool v23; // r7
  idODSObject<idDeclRenderProg> v24; // [sp+50h] [-220h] BYREF
  idODSObject<idTriangles> v25; // [sp+54h] [-21Ch] BYREF
  idODSObject<idDeclRenderProg> v26; // [sp+58h] [-218h] BYREF
  idODSObject<idRenderDestination> v27; // [sp+5Ch] [-214h] BYREF
  idODSObject<idRenderDestination> v28; // [sp+60h] [-210h] BYREF
  __int64 v29; // [sp+68h] [-208h]
  idODSObject<idTriangles> v30; // [sp+70h] [-200h] BYREF
  _DWORD v31[96]; // [sp+80h] [-1F0h] BYREF

  if ( !parms->envBlend->cubeFinished )
  {
    idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_RENDER_DYNAMIC_ENV);
    envBlend = parms->envBlend;
    LODWORD(v3) = parms->renderView->r.renderTime;
    v4 = (float)(envBlend->blendDuration + envBlend->blendStartTime);
    v29 = v3;
    v5 = 1.0;
    if ( v4 > (float)((float)v3 * (float)0.001) )
      v5 = (float)((float)((float)((float)v3 * (float)0.001) - envBlend->blendStartTime)
                 / (float)(envBlend->blendDuration * (float)2.5));
    else
      envBlend->cubeFinished = true;
    v6 = 0;
    v7 = v31;
    do
    {
      memset(Dst: v7, Val: 0, Size: 0x40u);
      v8 = &cubeAxis[v6 / 0x10u][1];
      v9 = cubeAxis[v6 / 0x10u][0];
      if ( v9 >= 0 )
        *(float *)&v31[v6 - 1 + v9] = 1.0;
      else
        *(float *)&v31[v6 - v9 - 1] = -1.0;
      v10 = *v8;
      if ( *v8 >= 0 )
        *(float *)&v31[v6 + 3 + v10] = 1.0;
      else
        *(float *)&v31[v6 - v10 + 3] = -1.0;
      v11 = v8[1];
      if ( v11 >= 0 )
        *(float *)&v31[v6 + 7 + v11] = 1.0;
      else
        *(float *)&v31[v6 - v11 + 7] = -1.0;
      v12 = v8[2];
      if ( v12 >= 0 )
        *(float *)&v31[v6 + 11 + v12] = 1.0;
      else
        *(float *)&v31[v6 - v12 + 11] = -1.0;
      v6 += 16;
      v7 += 16;
    }
    while ( v6 < 96 );
    GL_SetDefaultState();
    v14 = 0;
    width = parms->imgDynamicEnv->opts.width;
    do
    {
      LODWORD(v13) = v14;
      rpEnvBlendMip = parms->rpEnvBlendMip;
      v29 = v13;
      idDeclRenderParm::Set(this: rpEnvBlendMip, v: (float)v13);
      v17 = 0;
      v18 = (const idRenderMatrix *)v31;
      do
      {
        v28.objectPtr = parms->renderDestDynamicEnv;
        GL_SetRenderDestination(destination: &v28, level: v14, side: v17);
        GL_Viewport(x: 0, y: 0, w: width, h: width);
        GL_Scissor(x: 0, y: 0, w: width, h: width);
        idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: v18);
        idDeclRenderParm::Set(this: parms->rpColor, v: 1.0);
        idDeclRenderParm::SetImage(this: parms->rpUserEnvMap, image: parms->imgDynamicEnv);
        unitCubeTris = parms->unitCubeTris;
        v26.objectPtr = parms->progBlend;
        v30.objectPtr = unitCubeTris;
        GL_DrawElements(prog: &v26, tri: &v30, extraState: 0, skipDetailTriangles: v20);
        idDeclRenderParm::Set(this: parms->rpEnvSMatrix, vec: parms->envMapRotation.mat);
        idDeclRenderParm::Set(this: parms->rpEnvTMatrix, vec: &parms->envMapRotation.mat[1]);
        idDeclRenderParm::Set(this: parms->rpEnvRMatrix, vec: &parms->envMapRotation.mat[2]);
        idDeclRenderParm::Set(this: parms->rpColor, v: v5);
        if ( v14 == 4 && parms->settings->useAmbientEnv )
          imgAmbientEnv = parms->imgAmbientEnv;
        else
          imgAmbientEnv = parms->imgUserEnv;
        idDeclRenderParm::SetImage(this: parms->rpUserEnvMap, image: imgAmbientEnv);
        v22 = parms->unitCubeTris;
        v24.objectPtr = parms->progBlend;
        v25.objectPtr = v22;
        GL_DrawElements(prog: &v24, tri: &v25, extraState: 0, skipDetailTriangles: v23);
        v27.objectPtr = parms->renderDestDynamicEnv;
        GL_ResolveTarget(
          target: RESOLVE_TARGET_COLOR0,
          destination: &v27,
          srcMinX: 0,
          srcMinY: 0,
          srcMaxX: width,
          srcMaxY: width,
          dstX: 0,
          dstY: 0);
        ++v17;
        ++v18;
      }
      while ( v17 < 6 );
      ++v14;
      width >>= 1;
    }
    while ( v14 < 5 );
    idDeclRenderParm::Set(this: parms->rpColor, v: 1.0);
    idRenderLog::CloseMainBlock(this: &renderLog);
  }
}

