
// ========================================================================
// R_QsortContacts
// EA  : 0x82967970
// RVA : 0x00967970
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

int __fastcall R_QsortContacts(float *a, float *b)
{
  double v2; // fp0
  double v3; // fp13

  v2 = *a;
  v3 = *b;
  if ( v2 >= v3 )
    return v2 > v3;
  else
    return -1;
}


// ========================================================================
// ?ClearDebugDrawing_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829679A0
// RVA : 0x009679A0
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall ClearDebugDrawing_f(const idCmdArgs *args)
{
  if ( tr.primaryWorld != nullptr )
    tr.primaryWorld->DebugClear(this: tr.primaryWorld, a2: 0x7FFFFFFF);
}


// ========================================================================
// ?BrightColorForNumber@@YA?AVidColor@@H@Z
// EA  : 0x829679D0
// RVA : 0x009679D0
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idColor *__fastcall BrightColorForNumber(idColor *result, int number)
{
  int v2; // r10
  int v3; // r10
  unsigned int v4; // r9
  unsigned int v5; // r7
  unsigned int v6; // r8 OVERLAPPED
  __int64 v7; // r10 OVERLAPPED
  unsigned int v8; // r11
  __int64 v9; // fp13

  do
  {
    do
    {
      v2 = 1103515245 * number + 12345;
      v4 = (unsigned __int8)(v2 >> 23);
      v3 = 1103515245 * v2 + 12345;
      number = 1103515245 * v3 + 12345;
      LODWORD(v7) = (unsigned __int8)(v3 >> 23);
      v5 = v4;
      v6 = (unsigned __int8)(number >> 23);
      HIDWORD(v7) = v4 + v7;
    }
    while ( (int)(HIDWORD(v7) + v6) < 255 );
  }
  while ( v5 < 0x80 && (unsigned int)v7 < 0x80 && v6 < 0x80 );
  v8 = v5;
  v9 = v7;
  HIDWORD(v7) = (unsigned __int8)(number >> 23);
  result->a = 1.0;
  result->b = (float)*(__int64 *)((char *)&v7 + 4) * (float)0.0039215689;
  result->g = (float)v9 * (float)0.0039215689;
  result->r = (float)*(__int64 *)((char *)&v7 - 4) * (float)0.0039215689;
  return result;
}


// ========================================================================
// ?ShowModelGroupMasters@idRender@@AAAXXZ
// EA  : 0x82967AA0
// RVA : 0x00967AA0
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowModelGroupMasters(idRender *this)
{
  const idRenderWorldLocal **p_world; // r29
  int v3; // r28
  const idRenderWorldLocal *world; // r11
  int v5; // r30
  idRenderModelCommitted *v6; // r11
  int groupMasterIndex; // r10
  idRenderWorldLocal *v8; // r3
  float *v9; // r10
  double v10; // fp6
  double v11; // fp4
  double v12; // fp9
  double v13; // fp7
  int v14; // r25
  int numViewModels; // r9
  const idRenderModelCommitted **viewModels; // r27
  float *v17; // r11
  int v18; // r10
  idRenderWorldLocal *v19; // r3
  float *v20; // r10
  double v21; // fp6
  double v22; // fp4
  double v23; // fp9
  double v24; // fp7
  idVec3 v25; // [sp+50h] [-90h] BYREF
  idVec3 v26; // [sp+60h] [-80h] BYREF
  idVec3 v27; // [sp+70h] [-70h] BYREF
  idVec3 v28; // [sp+80h] [-60h] BYREF

  if ( r_showModelGroupMasters.valueInteger != 0 )
  {
    if ( r_showModelGroupMasters.valueInteger == 2 )
    {
      p_world = &this->world;
      v3 = 0;
      world = this->world;
      if ( world->linkedRenderModels.num > 0 )
      {
        v5 = 0;
        do
        {
          v6 = world->linkedRenderModels.list[v5];
          if ( v6 != nullptr )
          {
            groupMasterIndex = v6->r.groupMasterIndex;
            if ( groupMasterIndex != -1 )
            {
              v8 = (idRenderWorldLocal *)*p_world;
              v9 = (float *)(*p_world)->linkedRenderModels.list[groupMasterIndex];
              v10 = (float)(v9[276] + v9[273]);
              v11 = (float)((float)(v9[274] + v9[277]) * (float)0.5);
              v25.z = (float)(v9[275] + v9[278]) * (float)0.5;
              v25.y = v11;
              v25.x = (float)v10 * (float)0.5;
              v12 = (float)(v6->globalReferenceBounds.b[0].z + v6->globalReferenceBounds.b[1].z);
              v13 = (float)((float)(v6->globalReferenceBounds.b[0].y + v6->globalReferenceBounds.b[1].y) * (float)0.5);
              v26.x = (float)(v6->globalReferenceBounds.b[1].x + v6->globalReferenceBounds.b[0].x) * (float)0.5;
              v26.y = v13;
              v26.z = (float)v12 * (float)0.5;
              idRenderWorldLocal::DebugLine_renderThread(
                this: v8,
                color: (const idVec4 *)&idColor::colorWhite,
                start: &v26,
                end: &v25,
                lifetime: 3,
                depthTest: false);
            }
          }
          world = *p_world;
          ++v3;
          ++v5;
        }
        while ( v3 < (*p_world)->linkedRenderModels.num );
      }
    }
    else
    {
      v14 = 0;
      numViewModels = renderState.numViewModels;
      if ( renderState.numViewModels > 0 )
      {
        viewModels = renderState.viewModels;
        do
        {
          v17 = (float *)*viewModels;
          v18 = (*viewModels)->r.groupMasterIndex;
          if ( v18 != -1 )
          {
            v19 = (idRenderWorldLocal *)this->world;
            v20 = (float *)v19->linkedRenderModels.list[v18];
            v21 = (float)(v20[276] + v20[273]);
            v22 = (float)((float)(v20[274] + v20[277]) * (float)0.5);
            v27.z = (float)(v20[275] + v20[278]) * (float)0.5;
            v27.y = v22;
            v27.x = (float)v21 * (float)0.5;
            v23 = (float)(v17[276] + v17[273]);
            v24 = (float)((float)(v17[274] + v17[277]) * (float)0.5);
            v28.z = (float)(v17[275] + v17[278]) * (float)0.5;
            v28.y = v24;
            v28.x = (float)v23 * (float)0.5;
            idRenderWorldLocal::DebugLine_renderThread(
              this: v19,
              color: (const idVec4 *)&idColor::colorWhite,
              start: &v28,
              end: &v27,
              lifetime: 3,
              depthTest: false);
            numViewModels = renderState.numViewModels;
          }
          ++v14;
          ++viewModels;
        }
        while ( v14 < numViewModels );
      }
    }
  }
}


// ========================================================================
// ?SimpleWorldSetup@idRender@@AAAXXZ
// EA  : 0x82967D80
// RVA : 0x00967D80
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::SimpleWorldSetup(idRender *this)
{
  unsigned __int64 v2; // r6

  idParmState::SetModelMatrix(this: renderThreadParmState, modelMatrix: &this->worldSpace.modelMatrix);
  idParmState::SetInverseModelMatrix(
    this: renderThreadParmState,
    inverseModelMatrix: &this->worldSpace.inverseModelMatrix);
  idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &this->worldSpace.mvpMatrix);
  idDeclRenderParm::Set(this: rp->globalViewOrigin, vec: &this->renderViewObject->r.vieworg);
  idDeclRenderProg::BindForImmediate(this: tr.progColorOnly, a2: 0, extraState: v2, a4: (unsigned int)&tr);
}


// ========================================================================
// ?PolygonClear@idRender@@AAAXABVidVec4@@_K@Z
// EA  : 0x82967E20
// RVA : 0x00967E20
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::PolygonClear(idRender *this, const idVec4 *vertColor, unsigned __int64 state)
{
  idRenderView **p_renderViewObject; // r26
  int v5; // r24
  int v6; // r29
  idTriangles *v7; // r10
  idTriangles *v8; // r3
  idTriangles *v9; // r3
  idTriangles *v10; // r3
  idDrawVert *verts; // r11
  int i; // r28
  unsigned int v13; // r3
  idDrawVert *v14; // r11
  unsigned __int64 v15; // r6
  bool v16; // r7
  idODSObject<idTriangles> v17; // [sp+50h] [-B0h] BYREF
  idODSObject<idDeclRenderProg> v18; // [sp+54h] [-ACh] BYREF
  idTriangles *v19; // [sp+58h] [-A8h]
  idRenderMatrix v20; // [sp+60h] [-A0h] BYREF

  p_renderViewObject = &this->renderViewObject;
  v5 = HIDWORD(state);
  GL_Scissor(x: 0, y: 0, w: this->renderViewObject->renderWidth, h: this->renderViewObject->renderHeight);
  idImageManager::BindNull(this: globalImages);
  v20.m[0] = 1.0;
  v20.m[1] = 0.0;
  v20.m[2] = 0.0;
  v20.m[3] = 0.0;
  v20.m[4] = 0.0;
  v20.m[5] = 1.0;
  v20.m[6] = 0.0;
  v20.m[7] = 0.0;
  v20.m[8] = 0.0;
  v20.m[9] = 0.0;
  v20.m[10] = 1.0;
  v20.m[11] = 0.0;
  v20.m[12] = 0.0;
  v20.m[13] = 0.0;
  v20.m[14] = 0.0;
  v20.m[15] = 1.0;
  idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v20);
  v6 = 0;
  v7 = tri;
  if ( tri == nullptr )
  {
    v8 = (idTriangles *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x84u,
                          tag: TAG_TRIANGLES,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v19 = v8;
    if ( v8 != nullptr )
      v9 = idTriangles::idTriangles(this: v8);
    else
      v9 = nullptr;
    tri = v9;
    v9->numVerts = 4;
    v9->numIndexes = 6;
    idTriangles::AllocStaticTriSurfVerts(this: v9, numVerts: 4);
    idTriangles::AllocStaticTriSurfIndexes(this: tri, numIndexes: tri->numIndexes);
    v10 = tri;
    *tri->indexes = 3;
    v10->indexes[1] = 0;
    v10->indexes[2] = 2;
    v10->indexes[3] = 2;
    v10->indexes[4] = 0;
    v10->indexes[5] = 1;
    idTriangles::UpdateIndexBuffer(this: v10);
    v7 = tri;
    verts = tri->verts;
    verts->xyz.x = -1.0;
    verts->xyz.y = -1.0;
    verts->xyz.z = 0.0;
    v19 = (idTriangles *)&verts[3];
    verts[1].xyz.x = -1.0;
    verts[1].xyz.y = 1.0;
    verts[1].xyz.z = 0.0;
    verts[2].xyz.x = 1.0;
    verts[2].xyz.y = 1.0;
    verts[2].xyz.z = 0.0;
    verts[3].xyz.x = 1.0;
    verts[3].xyz.y = -1.0;
    verts[3].xyz.z = 0.0;
  }
  for ( i = 0; i < v7->numVerts; v14->color[0] = v13 )
  {
    v13 = idColor::PackColor(color: vertColor);
    v7 = tri;
    ++i;
    v14 = &tri->verts[v6++];
    v14->color[1] = BYTE2(v13);
    v14->color[3] = HIBYTE(v13);
    v14->color[2] = BYTE1(v13);
  }
  idTriangles::UpdateVertexBuffer(this: v7);
  LODWORD(v15) = 0;
  HIDWORD(v15) = v5 | 0x80000000;
  v17.objectPtr = tri;
  v18.objectPtr = tr.progColorOnly;
  GL_DrawElements(prog: &v18, tri: &v17, extraState: v15, skipDetailTriangles: v16);
  (*p_renderViewObject)->r.skipPostProcess = true;
}


// ========================================================================
// __unwind$238084
// EA  : 0x82968094
// RVA : 0x00968094
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_238084()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 88), tag: TAG_TRIANGLES);
}


// ========================================================================
// ?ShowDestinationAlpha@idRender@@AAAXXZ
// EA  : 0x829680C0
// RVA : 0x009680C0
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowDestinationAlpha(idRender *this, int a2, unsigned __int64 a3)
{
  bool v4; // r5
  idVec4 v5; // [sp+50h] [-20h] BYREF

  if ( r_showDestinationAlpha.valueInteger != 0 )
  {
    HIDWORD(a3) = 49222;
    v5.x = 1.0;
    v5.y = 1.0;
    v5.z = 1.0;
    v5.w = 1.0;
    idRender::PolygonClear(this, vertColor: &v5, state: a3);
    GL_State(stateBits: 0x400000000000uLL, forceGlState: v4);
    this->renderViewObject->r.skipPostProcess = true;
  }
}


// ========================================================================
// ?ShowIntensity@idRender@@AAAXXZ
// EA  : 0x82968148
// RVA : 0x00968148
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowIntensity(idRender *this)
{
  const idDeclRenderProg *r; // r31
  idRenderView **p_renderViewObject; // r30
  bool v3; // r5
  bool v4; // r7
  bool v5; // r5
  idODSObject<idDeclRenderProg> v6; // [sp+50h] [-A0h] BYREF
  idODSObject<idTriangles> v7; // [sp+54h] [-9Ch] BYREF
  captureParms_t v8; // [sp+60h] [-90h] BYREF

  if ( r_showIntensity.valueInteger != 0 )
  {
    r = (const idDeclRenderProg *)progshowIntensity.r;
    if ( progshowIntensity.r != nullptr )
    {
      p_renderViewObject = &this->renderViewObject;
      idRender::SetupCaptureParms(
        this,
        parms: &v8,
        capture: CAPTURE_VIEW_COLOR,
        createMipMaps: false,
        viewIndex: this->renderViewObject->viewIndex);
      CaptureViewColor(parms: &v8);
      idImageManager::BindNull(this: globalImages);
      GL_Scissor(x: 0, y: 0, w: (*p_renderViewObject)->renderWidth, h: (*p_renderViewObject)->renderHeight);
      GL_State(stateBits: 0xC00000000000uLL, forceGlState: v3);
      idParmState::SetPositionToViewTexture(
        this: renderThreadParmState,
        windowWidth: (*p_renderViewObject)->renderWidth,
        windowHeight: (*p_renderViewObject)->renderHeight,
        renderWidth: (*p_renderViewObject)->renderWidth,
        renderHeight: (*p_renderViewObject)->renderHeight);
      idDeclRenderProg::SetTextureParm(this: r, i: 0, image: tr.imgViewColor[0]);
      v7.objectPtr = tr.unitSquareModel->surfaces.list->geometry;
      v6.objectPtr = r;
      GL_DrawElements(prog: &v6, tri: &v7, extraState: 0, skipDetailTriangles: v4);
      GL_State(stateBits: 0x400000000000uLL, forceGlState: v5);
      (*p_renderViewObject)->r.skipPostProcess = true;
    }
    else
    {
      idLib::Printf(fmt: "Disabling r_showIntensity due to missing renderprog\n");
      idCVar::SetBool(this: &r_showIntensity, newValue: false, force: true);
    }
  }
}


// ========================================================================
// ?ShowDepthBuffer@idRender@@AAAXXZ
// EA  : 0x82968280
// RVA : 0x00968280
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowDepthBuffer(idRender *this)
{
  const idDeclRenderProg *r; // r31
  idRenderView **p_renderViewObject; // r30
  bool v3; // r5
  bool v4; // r7
  bool v5; // r5
  idODSObject<idDeclRenderProg> v6; // [sp+50h] [-A0h] BYREF
  idODSObject<idTriangles> v7; // [sp+54h] [-9Ch] BYREF
  captureParms_t v8; // [sp+60h] [-90h] BYREF

  if ( r_showDepth.valueInteger != 0 )
  {
    r = (const idDeclRenderProg *)progshowDepth.r;
    if ( progshowDepth.r != nullptr )
    {
      p_renderViewObject = &this->renderViewObject;
      idRender::SetupCaptureParms(
        this,
        parms: &v8,
        capture: CAPTURE_VIEW_DEPTH,
        createMipMaps: false,
        viewIndex: this->renderViewObject->viewIndex);
      CaptureViewDepth(parms: &v8);
      idImageManager::BindNull(this: globalImages);
      GL_Scissor(x: 0, y: 0, w: (*p_renderViewObject)->renderWidth, h: (*p_renderViewObject)->renderHeight);
      GL_State(stateBits: 0xC00000000000uLL, forceGlState: v3);
      idParmState::SetPositionToViewTexture(
        this: renderThreadParmState,
        windowWidth: (*p_renderViewObject)->renderWidth,
        windowHeight: (*p_renderViewObject)->renderHeight,
        renderWidth: (*p_renderViewObject)->renderWidth,
        renderHeight: (*p_renderViewObject)->renderHeight);
      idDeclRenderProg::SetTextureParm(this: r, i: 0, image: tr.imgViewDepth);
      v7.objectPtr = tr.unitSquareModel->surfaces.list->geometry;
      v6.objectPtr = r;
      GL_DrawElements(prog: &v6, tri: &v7, extraState: 0, skipDetailTriangles: v4);
      GL_State(stateBits: 0x400000000000uLL, forceGlState: v5);
      (*p_renderViewObject)->r.skipPostProcess = true;
    }
    else
    {
      idLib::Printf(fmt: "Disabling r_showDepth due to missing renderprog\n");
      idCVar::SetBool(this: &r_showDepth, newValue: false, force: true);
    }
  }
}


// ========================================================================
// ?ShowCracks@idRender@@AAAXXZ
// EA  : 0x829683B8
// RVA : 0x009683B8
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowCracks(idRender *this)
{
  const idDeclRenderProg *r; // r29
  idRenderView **p_renderViewObject; // r27
  unsigned int renderHeight; // r31
  unsigned int renderWidth; // r30
  bool v5; // r5
  idImage *imgViewDepth; // r30
  int v7; // r10
  int v8; // r9
  int v9; // r8
  int v10; // r7
  int v11; // r6
  int v12; // r5
  int v13; // r4
  bool v14; // r7
  idImage *v15; // r31
  int v16; // r10
  int v17; // r9
  int v18; // r8
  int v19; // r7
  int v20; // r6
  int v21; // r5
  int v22; // r4
  bool v23; // r5
  int v24; // [sp+8h] [-158h]
  int v25; // [sp+8h] [-158h]
  idODSObject<idTriangles> v26; // [sp+50h] [-110h] BYREF
  idODSObject<idDeclRenderProg> v27; // [sp+54h] [-10Ch] BYREF
  idImageOpts opts; // [sp+60h] [-100h] BYREF
  captureParms_t v29; // [sp+B0h] [-B0h] BYREF

  if ( r_showCracks.valueInteger != 0 )
  {
    r = (const idDeclRenderProg *)progshowCracks.r;
    if ( progshowCracks.r != nullptr )
    {
      p_renderViewObject = &this->renderViewObject;
      idRender::SetupCaptureParms(
        this,
        parms: &v29,
        capture: CAPTURE_VIEW_DEPTH,
        createMipMaps: false,
        viewIndex: this->renderViewObject->viewIndex);
      CaptureViewDepth(parms: &v29);
      idImageManager::BindNull(this: globalImages);
      renderHeight = (*p_renderViewObject)->renderHeight;
      renderWidth = (*p_renderViewObject)->renderWidth;
      GL_Viewport(x: 0, y: 0, w: renderWidth, h: renderHeight);
      GL_Scissor(x: 0, y: 0, w: renderWidth, h: renderHeight);
      GL_State(stateBits: 0xC00000000000uLL, forceGlState: v5);
      idParmState::SetPositionToViewTexture(
        this: renderThreadParmState,
        windowWidth: (*p_renderViewObject)->renderWidth,
        windowHeight: (*p_renderViewObject)->renderHeight,
        renderWidth: (*p_renderViewObject)->renderWidth,
        renderHeight: (*p_renderViewObject)->renderHeight);
      imgViewDepth = tr.imgViewDepth;
      memcpy(Dst: &v29, Src: &tr.imgViewDepth->opts, Size: 0x50u);
      opts = tr.imgViewDepth->opts;
      opts.filter = TF_NEAREST;
      opts.lodMinClamp = 0.0;
      opts.lodMaxClamp = 0.0;
      opts.lodBias = 0.0;
      idImageOpts::operator=(this: &tr.imgViewDepth->opts, __that: &opts);
      idImage::DetermineSamplerStateFromOpts(
        this: imgViewDepth,
        a2: v13,
        a3: v12,
        a4: v11,
        a5: v10,
        a6: v9,
        a7: v8,
        a8: v7,
        a9: v24);
      GL_ResetTextureState();
      idDeclRenderProg::SetTextureParm(this: r, i: 0, image: tr.imgViewDepth);
      v26.objectPtr = tr.unitSquareModel->surfaces.list->geometry;
      v27.objectPtr = r;
      GL_DrawElements(prog: &v27, tri: &v26, extraState: 0, skipDetailTriangles: v14);
      v15 = tr.imgViewDepth;
      idImageOpts::operator=(this: &tr.imgViewDepth->opts, __that: (const idImageOpts *)&v29);
      idImage::DetermineSamplerStateFromOpts(
        this: v15,
        a2: v22,
        a3: v21,
        a4: v20,
        a5: v19,
        a6: v18,
        a7: v17,
        a8: v16,
        a9: v25);
      GL_ResetTextureState();
      GL_State(stateBits: 0x400000000000uLL, forceGlState: v23);
      (*p_renderViewObject)->r.skipPostProcess = true;
    }
    else
    {
      idLib::Printf(fmt: "Disabling r_showCracks due to missing renderprog\n");
      idCVar::SetBool(this: &r_showCracks, newValue: false, force: true);
    }
  }
}


// ========================================================================
// ?ShowLights@idRender@@AAAXXZ
// EA  : 0x82968580
// RVA : 0x00968580
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowLights(idRender *this)
{
  int v2; // r28
  const idRenderLightCommitted **viewLights; // r29
  const idRenderLightCommitted *v4; // r30
  BOOL castsShadows; // r10
  idTriangles *geometry; // r30
  double v7; // fp3
  double v8; // fp2
  bool v9; // r7
  bool v10; // r7
  bool v11; // r5
  bool v12; // r3
  idODSObject<idTriangles> v13; // [sp+50h] [-80h] BYREF
  idODSObject<idDeclRenderProg> v14; // [sp+54h] [-7Ch] BYREF
  idODSObject<idTriangles> v15; // [sp+58h] [-78h] BYREF
  idODSObject<idDeclRenderProg> v16; // [sp+5Ch] [-74h] BYREF

  if ( r_showLights.valueInteger != 0 )
  {
    idImageManager::BindNull(this: globalImages);
    idRender::SimpleWorldSetup(this);
    v2 = 0;
    if ( this->numViewLights > 0 )
    {
      viewLights = this->viewLights;
      do
      {
        v4 = *viewLights;
        idParmState::SetMVPMatrixForInverseProject(
          this: renderThreadParmState,
          mvp: &this->renderViewObject->worldSpaceMVPMatrix,
          inverseProject: &(*viewLights)->inverseBaseLightProject);
        castsShadows = v4->castsShadows;
        geometry = tr.zeroOneCubeModel->surfaces.list->geometry;
        if ( castsShadows )
        {
          v7 = 1.0;
          v8 = 0.0;
        }
        else
        {
          v7 = 0.0;
          v8 = 1.0;
        }
        idDeclRenderParm::Set(this: rp->Color, x: 0.0, y: v8, z: v7, w: 0.25);
        v14.objectPtr = tr.progColorParmOnly;
        v13.objectPtr = geometry;
        GL_DrawElements(prog: &v14, tri: &v13, extraState: 0x8000806C00000000uLL, skipDetailTriangles: v9);
        idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
        v16.objectPtr = tr.progColorParmOnly;
        v15.objectPtr = geometry;
        GL_DrawElements(prog: &v16, tri: &v15, extraState: 0x8000C84000000000uLL, skipDetailTriangles: v10);
        ++v2;
        ++viewLights;
      }
      while ( v2 < this->numViewLights );
    }
    idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
    GL_State(stateBits: 0x400000000000uLL, forceGlState: v11);
    GL_PolygonOffset(scale: 0.0, bias: 0.0, fill: v12);
    this->renderViewObject->r.skipPostProcess = true;
  }
}


// ========================================================================
// ?ShowEnvironments@idRender@@AAAXXZ
// EA  : 0x82968748
// RVA : 0x00968748
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowEnvironments(idRender *this)
{
  char v2; // r23
  int *v3; // r9
  int v4; // ctr
  idRenderView *renderViewObject; // r11
  idRenderView *p_z; // r10
  const idRenderWorldLocal **p_world; // r26
  int v8; // r29
  const idRenderWorldLocal *world; // r11
  double v10; // fp28
  double v11; // fp27
  double v12; // fp26
  int v13; // r30
  char *v14; // r8
  const idDeclEnv **p_env; // r9
  int i; // ctr
  const idDeclEnv *env; // r31
  char v18; // r11
  unsigned int v19; // r7
  unsigned __int64 v20; // r6
  bool v21; // r5
  const idVec4 *v22; // r6
  __int64 v23; // r11
  unsigned int v24; // r7
  unsigned __int64 v25; // r6
  bool v26; // r5
  float x; // [sp+50h] [-100h]
  float y; // [sp+54h] [-FCh]
  float z; // [sp+58h] [-F8h]
  idVec3 v30; // [sp+60h] [-F0h] BYREF
  char v31; // [sp+6Ch] [-E4h] BYREF
  idBounds v32; // [sp+70h] [-E0h] BYREF
  int v33; // [sp+8Ch] [-C4h] BYREF
  float v34[22]; // [sp+90h] [-C0h] BYREF

  if ( r_showEnvs.valueInteger != 0 )
  {
    idImageManager::BindNull(this: globalImages);
    idRender::SimpleWorldSetup(this);
    v2 = 0;
    v3 = &v33;
    v4 = 9;
    renderViewObject = this->renderViewObject;
    p_z = (idRenderView *)&renderViewObject->r.vieworg.z;
    x = renderViewObject->r.vieworg.x;
    y = renderViewObject->r.vieworg.y;
    z = renderViewObject->r.vieworg.z;
    do
    {
      p_z = (idRenderView *)((char *)p_z + 4);
      *++v3 = p_z->g.renderTime;
      --v4;
    }
    while ( v4 != 0 );
    p_world = &this->world;
    v8 = 0;
    world = this->world;
    if ( world->dynamicEnvironments.num > 0 )
    {
      v10 = z;
      v11 = y;
      v12 = x;
      v13 = 0;
      do
      {
        v14 = &v31;
        p_env = &world->dynamicEnvironments.list[v13 - 1].env;
        for ( i = 6; i != 0; --i )
        {
          ++p_env;
          v14 += 4;
          *(_DWORD *)v14 = *p_env;
        }
        env = world->dynamicEnvironments.list[v13].env;
        if ( v2 != 0 )
          goto LABEL_21;
        if ( v12 < v32.b[0].x
          || v11 < v32.b[0].y
          || v10 < v32.b[0].z
          || v12 > v32.b[1].x
          || v11 > v32.b[1].y
          || (v18 = 1, v10 > v32.b[1].z) )
        {
          v18 = 0;
        }
        if ( v18 == 0 )
        {
LABEL_21:
          idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 0.0, z: 0.0, w: 1.0);
        }
        else
        {
          v2 = 1;
          idDeclRenderParm::Set(this: rp->Color, x: 0.0, y: 1.0, z: 0.0, w: 1.0);
          if ( env != nullptr )
          {
            idDeclRenderProg::BindForImmediate(this: tr.progColorOnly, a2: 0, extraState: v20, a4: v19);
            GL_State(stateBits: 0x444000000000uLL, forceGlState: v21);
            HIDWORD(v23) = env->name.str;
            LODWORD(v23) = 0;
            if ( *(_BYTE *)HIDWORD(v23) != 0 )
            {
              do
                LODWORD(v23) = v23 + 1;
              while ( *(_BYTE *)(v23 + HIDWORD(v23)) != 0 );
            }
            v30.x = (float)((float)(v34[0] * (float)v23) * (float)32.0) + x;
            v30.y = y + (float)((float)(v34[1] * (float)v23) * (float)32.0);
            v30.z = z + (float)((float)(v34[2] * (float)v23) * (float)32.0);
            idRender::InternalDrawText(
              this,
              text: env->name.str,
              origin: &v30,
              scale: 1.0,
              color: v22,
              viewAxis: (const idMat3 *)&idColor::colorGreen,
              align: (const int)v34);
          }
        }
        idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &this->worldSpace.mvpMatrix);
        idDeclRenderProg::BindForImmediate(this: tr.progColorParmOnly, a2: -2147432448, extraState: v25, a4: v24);
        R_DrawBounds(bounds: &v32);
        world = *p_world;
        ++v8;
        ++v13;
      }
      while ( v8 < (*p_world)->dynamicEnvironments.num );
    }
    idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
    GL_State(stateBits: 0x400000000000uLL, forceGlState: v26);
    this->renderViewObject->r.skipPostProcess = true;
  }
}


// ========================================================================
// ?ColorByStencilBuffer@idRender@@AAAXXZ
// EA  : 0x82968A48
// RVA : 0x00968A48
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ColorByStencilBuffer(idRender *this)
{
  unsigned __int64 v2; // r6
  const idVec4 *v3; // r30
  int v4; // r29

  if ( (_S15_1 & 1) == 0 )
  {
    colors_0[0].w = 1.0;
    colors_0[1].x = 1.0;
    colors_0[1].w = 1.0;
    colors_0[2].y = 1.0;
    _S15_1 |= 1u;
    colors_0[2].w = 1.0;
    colors_0[0].x = 0.0;
    colors_0[0].y = 0.0;
    colors_0[0].z = 0.0;
    colors_0[1].y = 0.0;
    colors_0[1].z = 0.0;
    colors_0[2].x = 0.0;
    colors_0[2].z = 0.0;
    colors_0[3].x = 0.0;
    colors_0[3].y = 0.0;
    colors_0[3].z = 1.0;
    colors_0[3].w = 1.0;
    colors_0[4].x = 0.0;
    colors_0[4].y = 1.0;
    colors_0[4].z = 1.0;
    colors_0[4].w = 1.0;
    colors_0[5].x = 1.0;
    colors_0[5].y = 0.0;
    colors_0[5].z = 1.0;
    colors_0[5].w = 1.0;
    colors_0[6].x = 1.0;
    colors_0[6].y = 1.0;
    colors_0[6].z = 0.0;
    colors_0[6].w = 1.0;
    colors_0[7].x = 1.0;
    colors_0[7].y = 1.0;
    colors_0[7].z = 1.0;
    colors_0[7].w = 1.0;
  }
  GL_Scissor(x: 0, y: 0, w: this->renderViewObject->renderWidth, h: this->renderViewObject->renderHeight);
  GL_Clear(color: true, depth: false, stencil: false, stencilValue: 0, r: 1.0, g: 1.0, b: 1.0, a: 1.0);
  v3 = colors_0;
  v4 = 0;
  do
  {
    HIDWORD(v2) = -268385185;
    idRender::PolygonClear(this, vertColor: v3++, state: v2);
    ++v4;
  }
  while ( (int)v3 < (int)&colors_0[7] );
}


// ========================================================================
// ?ShowLightCount@idRender@@AAAXXZ
// EA  : 0x82968BA0
// RVA : 0x00968BA0
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowLightCount(idRender *this)
{
  int v2; // r31
  idTriangles *geometry; // r28
  const idRenderModelCommitted **v4; // r29
  bool v5; // r7
  bool v6; // r7
  bool v7; // r5
  bfx::BinaryReplayLogOut *v8; // r3
  idODSObject<idTriangles> v9; // [sp+50h] [-70h] BYREF
  idODSObject<idDeclRenderProg> v10; // [sp+54h] [-6Ch] BYREF
  idODSObject<idTriangles> v11; // [sp+58h] [-68h] BYREF
  idODSObject<idDeclRenderProg> v12; // [sp+5Ch] [-64h] BYREF

  if ( r_showLightCount.valueInteger != 0 )
  {
    GL_Clear(color: false, depth: false, stencil: true, stencilValue: 0, r: 0.0, g: 0.0, b: 0.0, a: 0.0);
    idRender::SimpleWorldSetup(this);
    v2 = 0;
    geometry = tr.zeroOneCubeModel->surfaces.list->geometry;
    if ( this->numViewLights > 0 )
    {
      v4 = &this->viewAugmentModels[31];
      do
      {
        idParmState::SetMVPMatrixForInverseProject(
          this: renderThreadParmState,
          mvp: &this->renderViewObject->worldSpaceMVPMatrix,
          inverseProject: (const idRenderMatrix *)&(*++v4)->inverseModelMatrix.m[4]);
        v10.objectPtr = tr.progColorOnly;
        v9.objectPtr = geometry;
        GL_DrawElements(prog: &v10, tri: &v9, extraState: 0x103C000000000uLL, skipDetailTriangles: v5);
        v12.objectPtr = tr.progColorOnly;
        v11.objectPtr = geometry;
        GL_DrawElements(prog: &v12, tri: &v11, extraState: 0x800013C000000000uLL, skipDetailTriangles: v6);
        ++v2;
      }
      while ( v2 < this->numViewLights );
    }
    idRender::ColorByStencilBuffer(this);
    if ( r_showLightCount.valueInteger >= 2 )
      idPhysics_StaticMulti::UpdateTime(this: v8);
    GL_State(stateBits: 0x400000000000uLL, forceGlState: v7);
    this->renderViewObject->r.skipPostProcess = true;
  }
}


// ========================================================================
// ?ShowTransparencySortOverdraw@idRender@@AAAXXZ
// EA  : 0x82968CF0
// RVA : 0x00968CF0
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowTransparencySortOverdraw(idRender *this)
{
  const idRenderWorldLocal *world; // r5
  idRenderModelTransparency *transparencyRenderModel; // r11
  idRenderView **p_renderViewObject; // r27
  unsigned __int64 v5; // r6
  const idVec4 *v6; // r30
  int v7; // r29
  bfx::BinaryReplayLogOut *v8; // r3
  idODSObject<idTriangles> v9; // [sp+50h] [-50h] BYREF
  idODSObject<idDeclRenderProg> v10; // [sp+54h] [-4Ch] BYREF

  if ( r_showTransSortOverdraw.valueInteger != 0 )
  {
    idImageManager::BindNull(this: globalImages);
    GL_Clear(color: false, depth: false, stencil: true, stencilValue: 0, r: 0.0, g: 0.0, b: 0.0, a: 0.0);
    idRender::SimpleWorldSetup(this);
    world = this->world;
    transparencyRenderModel = world->transparencyRenderModel;
    if ( transparencyRenderModel != nullptr )
    {
      v9.objectPtr = transparencyRenderModel->surfaces.list->geometry;
      v10.objectPtr = tr.progColorOnly;
      GL_DrawElements(prog: &v10, tri: &v9, extraState: 0x83C000000000uLL, skipDetailTriangles: (bool)v9.objectPtr);
    }
    GL_State(stateBits: 0x400000000000uLL, forceGlState: (bool)world);
    if ( (_S16_0 & 1) == 0 )
    {
      colors_1[0].x = 0.0;
      colors_1[0].y = 0.0;
      colors_1[0].z = 0.0;
      colors_1[0].w = 1.0;
      colors_1[1].x = 0.0;
      colors_1[1].z = 0.27000001;
      colors_1[2].z = 0.60000002;
      _S16_0 |= 1u;
      colors_1[1].y = 0.0;
      colors_1[1].w = 1.0;
      colors_1[2].x = 0.0;
      colors_1[2].y = 0.0;
      colors_1[2].w = 1.0;
      colors_1[3].x = 0.1;
      colors_1[3].y = 0.0;
      colors_1[3].z = 0.68000001;
      colors_1[3].w = 1.0;
      colors_1[4].x = 0.41999999;
      colors_1[4].y = 0.0;
      colors_1[4].z = 0.47;
      colors_1[4].w = 1.0;
      colors_1[5].x = 0.80000001;
      colors_1[5].y = 0.0;
      colors_1[5].z = 0.17;
      colors_1[5].w = 1.0;
      colors_1[6].x = 1.0;
      colors_1[6].y = 0.039999999;
      colors_1[6].z = 0.0;
      colors_1[6].w = 1.0;
      colors_1[7].x = 1.0;
      colors_1[7].y = 0.36000001;
      colors_1[7].z = 0.0;
      colors_1[7].w = 1.0;
      colors_1[8].x = 1.0;
      colors_1[8].y = 0.76999998;
      colors_1[8].z = 0.0;
      colors_1[8].w = 1.0;
      colors_1[9].x = 1.0;
      colors_1[9].y = 1.0;
      colors_1[9].z = 0.12;
      colors_1[9].w = 1.0;
      colors_1[10].x = 1.0;
      colors_1[10].y = 1.0;
      colors_1[10].z = 1.0;
      colors_1[10].w = 1.0;
    }
    p_renderViewObject = &this->renderViewObject;
    GL_Viewport(x: 0, y: 0, w: this->renderViewObject->renderWidth, h: this->renderViewObject->renderHeight);
    GL_Scissor(x: 0, y: 0, w: (*p_renderViewObject)->renderWidth, h: (*p_renderViewObject)->renderHeight);
    GL_Clear(color: true, depth: false, stencil: false, stencilValue: 0, r: 1.0, g: 1.0, b: 1.0, a: 1.0);
    v6 = colors_1;
    v7 = 0;
    do
    {
      HIDWORD(v5) = -268385185;
      idRender::PolygonClear(this, vertColor: v6++, state: v5);
      ++v7;
    }
    while ( (int)v6 < (int)&colors_1[10] );
    if ( r_showTransSortOverdraw.valueInteger >= 2 )
      idPhysics_StaticMulti::UpdateTime(this: v8);
    GL_State(stateBits: 0x400000000000uLL, forceGlState: SBYTE3(v5));
    (*p_renderViewObject)->r.skipPostProcess = true;
  }
}


// ========================================================================
// ?ShowViewModels@idRender@@AAAXXZ
// EA  : 0x82968FD8
// RVA : 0x00968FD8
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowViewModels(idRender *this)
{
  idRenderView **p_renderViewObject; // r21
  int *p_numViewModels; // r22
  int v4; // r23
  idRenderMatrix *p_mvpMatrix; // r24
  const idRenderModelCommitted **viewModels; // r25
  const idRenderModelCommitted *v7; // r31
  unsigned int v8; // r7
  unsigned __int64 v9; // r6
  int valueInteger; // r11
  unsigned int v11; // r7
  unsigned __int64 v12; // r6
  bool v13; // r7
  bool v14; // r5
  idODSObject<idDeclRenderProg> v15; // [sp+50h] [-80h] BYREF
  idODSObject<idTriangles> v16; // [sp+54h] [-7Ch] BYREF

  if ( r_showModels.valueInteger != 0 )
  {
    idImageManager::BindNull(this: globalImages);
    p_renderViewObject = &this->renderViewObject;
    GL_Scissor(x: 0, y: 0, w: this->renderViewObject->renderWidth, h: this->renderViewObject->renderHeight);
    p_numViewModels = &this->numViewModels;
    v4 = 0;
    if ( this->numViewModels > 0 )
    {
      p_mvpMatrix = &this->worldSpace.mvpMatrix;
      viewModels = this->viewModels;
      do
      {
        v7 = *viewModels;
        idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 0.0, w: 1.0);
        idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: p_mvpMatrix);
        idDeclRenderProg::BindForImmediate(this: tr.progColorParmOnly, a2: -2147432448, extraState: v9, a4: v8);
        R_DrawBounds(bounds: &v7->globalReferenceBounds);
        valueInteger = r_showModels.valueInteger;
        if ( r_showModels.valueInteger == 1 )
        {
          idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v7->mvpMatrix);
          idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
          idDeclRenderProg::BindForImmediate(this: tr.progColorParmOnly, a2: -2147432448, extraState: v12, a4: v11);
          R_DrawBounds(bounds: &v7->referenceBounds);
          valueInteger = r_showModels.valueInteger;
        }
        if ( valueInteger == 3 )
        {
          idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 0.0, z: 0.0, w: 0.0);
          idParmState::SetMVPMatrixForBounds(
            this: renderThreadParmState,
            mvp: &v7->mvpMatrix,
            bounds: &v7->referenceBounds);
          v16.objectPtr = tr.unitCubeModel->surfaces.list->geometry;
          v15.objectPtr = tr.progColorParmOnly;
          GL_DrawElements(prog: &v15, tri: &v16, extraState: 0x8000C80000000000uLL, skipDetailTriangles: v13);
        }
        ++v4;
        ++viewModels;
      }
      while ( v4 < *p_numViewModels );
    }
    idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
    GL_State(stateBits: 0x400000000000uLL, forceGlState: v14);
    (*p_renderViewObject)->r.skipPostProcess = true;
  }
}


// ========================================================================
// ?ShowSurfaceBounds@idRender@@AAAXXZ
// EA  : 0x829691C8
// RVA : 0x009691C8
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowSurfaceBounds(idRender *this)
{
  int v2; // r25
  const idRenderModelCommitted **viewModels; // r28
  const idRenderModelCommitted *v4; // r31
  unsigned int v5; // r7
  unsigned __int64 v6; // r6
  int v7; // r29
  int v8; // r30
  const idBounds *p_bounds; // r3
  bool v10; // r5

  if ( r_showSurfaceBounds.valueInteger != 0 )
  {
    idImageManager::BindNull(this: globalImages);
    idRender::SimpleWorldSetup(this);
    idDeclRenderParm::Set(this: rp->Color, x: 0.0, y: 0.0, z: 1.0, w: 1.0);
    v2 = 0;
    if ( this->numViewModels > 0 )
    {
      viewModels = this->viewModels;
      do
      {
        v4 = *viewModels;
        idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &(*viewModels)->mvpMatrix);
        idDeclRenderProg::BindForImmediate(this: tr.progColorParmOnly, a2: -2147432448, extraState: v6, a4: v5);
        v7 = 0;
        if ( v4->surfaces.num > 0 )
        {
          v8 = 0;
          do
          {
            if ( &v4->surfaces.list[v8] != nullptr )
            {
              p_bounds = &v4->surfaces.list[v8].geometry->bounds;
              if ( p_bounds != nullptr )
                R_DrawBounds(bounds: p_bounds);
            }
            ++v7;
            ++v8;
          }
          while ( v7 < v4->surfaces.num );
        }
        ++v2;
        ++viewModels;
      }
      while ( v2 < this->numViewModels );
    }
    idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
    GL_State(stateBits: 0x400000000000uLL, forceGlState: v10);
    this->renderViewObject->r.skipPostProcess = true;
  }
}


// ========================================================================
// ?ShowOcclusionBaseModel@idRender@@AAAXXZ
// EA  : 0x82969320
// RVA : 0x00969320
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowOcclusionBaseModel(idRender *this)
{
  idRenderModel *occlusionBaseModel; // r11
  const idTriangles *geometry; // r30
  bool v4; // r7
  bool v5; // r3
  double v6; // fp31
  int v7; // r5
  idRenderSystemLocal *v8; // r7
  const idODSObject<idTriangles> *v9; // r4
  const idODSObject<idDeclRenderProg> *v10; // r3
  unsigned __int64 v11; // r6
  bool v12; // r5
  idODSObject<idTriangles> v13; // [sp+50h] [-60h] BYREF
  idODSObject<idDeclRenderProg> v14; // [sp+54h] [-5Ch] BYREF
  const idTriangles *v15; // [sp+58h] [-58h] BYREF
  const idDeclRenderProg *progColorParmOnly; // [sp+5Ch] [-54h] BYREF
  idODSObject<idTriangles> v17; // [sp+60h] [-50h] BYREF
  idODSObject<idDeclRenderProg> v18; // [sp+64h] [-4Ch] BYREF
  const idTriangles *v19; // [sp+68h] [-48h] BYREF
  const idDeclRenderProg *v20; // [sp+6Ch] [-44h] BYREF

  if ( r_showOcclusionBaseModel.valueInteger != 0 )
  {
    occlusionBaseModel = this->world->occlusionBaseModel;
    if ( occlusionBaseModel != nullptr && occlusionBaseModel->surfaces.num > 0 )
    {
      geometry = occlusionBaseModel->surfaces.list->geometry;
      idRender::SimpleWorldSetup(this);
      if ( r_showOcclusionBaseModel.valueInteger == 2 )
      {
        if ( progflatShadeReal.r == nullptr )
          return;
        v14.objectPtr = (const idDeclRenderProg *)progflatShadeReal.r;
        v13.objectPtr = geometry;
        GL_DrawElements(prog: &v14, tri: &v13, extraState: 0x8000000000000000uLL, skipDetailTriangles: v4);
        GL_PolygonOffset(scale: -1.0, bias: -1.0, fill: v5);
        v6 = 1.0;
        idDeclRenderParm::Set(this: rp->Color, x: 0.0, y: 0.0, z: 0.0, w: 1.0);
        v15 = geometry;
        v7 = 4097;
        v8 = &tr;
        v9 = (const idODSObject<idTriangles> *)&v15;
        v10 = (const idODSObject<idDeclRenderProg> *)&progColorParmOnly;
        progColorParmOnly = tr.progColorParmOnly;
      }
      else
      {
        v6 = 1.0;
        idDeclRenderParm::Set(this: rp->Color, x: 0.0, y: 1.0, z: 0.0, w: 0.5);
        v17.objectPtr = geometry;
        v18.objectPtr = tr.progColorParmOnly;
        GL_DrawElements(
          prog: &v18,
          tri: &v17,
          extraState: 0x8000046C00000000uLL,
          skipDetailTriangles: (bool)&renderLog.indentString[28]);
        idDeclRenderParm::Set(this: rp->Color, x: 0.0, y: 1.0, z: 0.0, w: 0.5);
        v9 = (const idODSObject<idTriangles> *)&v19;
        v7 = 69633;
        v10 = (const idODSObject<idDeclRenderProg> *)&v20;
        v20 = tr.progColorParmOnly;
        v19 = geometry;
      }
      LODWORD(v11) = 0;
      HIDWORD(v11) = __ROR4__(v7, 1);
      GL_DrawElements(prog: v10, tri: v9, extraState: v11, skipDetailTriangles: (bool)v8);
      idDeclRenderParm::Set(this: rp->Color, x: v6, y: v6, z: v6, w: v6);
      GL_State(stateBits: 0x400000000000uLL, forceGlState: v12);
      this->renderViewObject->r.skipPostProcess = true;
    }
  }
}


// ========================================================================
// ?ShowGamma@idRender@@AAAXXZ
// EA  : 0x82969538
// RVA : 0x00969538
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowGamma(idRender *this)
{
  char *buffer; // r30
  char v3; // r24
  int i; // r25
  int v5; // r10
  int j; // r3
  char v7; // r6
  int v8; // r29
  int v9; // r11
  int v10; // r9
  int k; // ctr
  int v12; // r8
  int m; // ctr
  char v14; // r9
  int v15; // r6
  double v16; // fp0
  int v17; // r11
  char v18; // r9
  int n; // r8
  int v20; // r10
  int ii; // ctr
  int v22; // r11
  char *v23; // r11
  const idDeclRenderProg *progTextureOnly; // r28
  idTriangles *v25; // r3
  idTriangles *v26; // r3
  idTriangles *v27; // r3
  idTriangles *v28; // r3
  float *p_x; // r11
  __int64 v30; // r8
  idRenderView *renderViewObject; // r6
  __int64 v32; // r6
  double v33; // fp5
  bool v34; // r7
  bool v35; // r5
  int v36; // [sp+8h] [-1A8h]
  idODSObject<idTriangles> v37; // [sp+68h] [-148h] BYREF
  idODSObject<idDeclRenderProg> v38; // [sp+6Ch] [-144h] BYREF
  idRenderMatrix v39; // [sp+70h] [-140h] BYREF
  idTempArray<char> v40; // [sp+B0h] [-100h] BYREF
  idImageOpts v41; // [sp+C0h] [-F0h] BYREF

  if ( r_testGamma.valueInteger > 0 )
  {
    if ( gammaTestImage == nullptr )
    {
      idImageOpts::idImageOpts(this: &v41);
      v41.format = FMT_RGBA8;
      v41.width = 512;
      v41.height = 512;
      v41.filter = TF_NEAREST;
      gammaTestImage = idImageManager::ScratchImage(this: globalImages, _name: "_gammaTestImage", imgOpts: &v41);
    }
    idTempArray<char>::idTempArray<char>(this: &v40, num: 0x100000u);
    buffer = v40.buffer;
    memset(Dst: v40.buffer, Val: 0, Size: 0x100000u);
    v3 = 0;
    for ( i = 0; i < 0x40000; i += 0x8000 )
    {
      v5 = 0;
      for ( j = 0; j < 256; j += 64 )
      {
        v7 = j + 32;
        v8 = 0;
        v9 = i;
        do
        {
          v10 = 0;
          for ( k = 128; k != 0; --k )
          {
            if ( (v3 & 1) != 0 )
              buffer[4 * v9 + 4 * (v5 / 4) + 4 * v10] = v7;
            if ( (v3 & 2) != 0 )
              buffer[4 * v9 + 1 + 4 * (v5 / 4) + 4 * v10] = v7;
            if ( (v3 & 4) != 0 )
              buffer[4 * v9 + 2 + 4 * (v5 / 4) + 4 * v10] = v7;
            ++v10;
          }
          v12 = 0;
          for ( m = 128; m != 0; --m )
          {
            v14 = j;
            if ( (((unsigned __int8)v12 ^ (unsigned __int8)v8) & 1) == 0 )
              v14 = j + 63;
            if ( (v3 & 1) != 0 )
              buffer[4 * v9 + 0x10000 + 4 * (v5 / 4) + 4 * v12] = v14;
            if ( (v3 & 2) != 0 )
              buffer[4 * v9 + 65537 + 4 * (v5 / 4) + 4 * v12] = v14;
            if ( (v3 & 4) != 0 )
              buffer[4 * v9 + 65538 + 4 * (v5 / 4) + 4 * v12] = v14;
            ++v12;
          }
          ++v8;
          v9 += 512;
        }
        while ( v8 < 32 );
        v5 += 512;
      }
      ++v3;
    }
    v15 = 0;
    v16 = 1.0;
    do
    {
      v17 = (int)(float)((float)v16 * (float)64.0);
      if ( v17 >= 0 )
      {
        if ( v17 > 255 )
          LOBYTE(v17) = -1;
      }
      else
      {
        LOBYTE(v17) = 0;
      }
      v16 = (float)((float)v16 * (float)1.5);
      v18 = v17;
      for ( n = 0; n < 0x8000; n += 512 )
      {
        v20 = 0;
        for ( ii = 128; ii != 0; --ii )
        {
          v22 = n + v15 / 4 + v20++;
          v23 = &buffer[4 * v22];
          *v23 = v18;
          v23[1] = v18;
          v23[2] = v18;
        }
      }
      v15 += 512;
    }
    while ( v15 < 2048 );
    idImage::SubImageUpload(
      this: gammaTestImage,
      mipLevel: 0,
      destX: 0,
      destY: 0,
      destZ: D3DCUBEMAP_FACE_POSITIVE_X,
      width: 512,
      height: 512,
      pic: buffer,
      pixelPitch: v36);
    v39.m[0] = 1.0;
    v39.m[5] = 1.0;
    v39.m[10] = 1.0;
    v39.m[15] = 1.0;
    v39.m[1] = 0.0;
    v39.m[2] = 0.0;
    v39.m[3] = 0.0;
    progTextureOnly = tr.progTextureOnly;
    v39.m[4] = 0.0;
    v39.m[6] = 0.0;
    v39.m[7] = 0.0;
    v39.m[8] = 0.0;
    v39.m[9] = 0.0;
    v39.m[11] = 0.0;
    v39.m[12] = 0.0;
    v39.m[13] = 0.0;
    v39.m[14] = 0.0;
    idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v39);
    idDeclRenderProg::SetTextureParm(this: progTextureOnly, i: 0, image: gammaTestImage);
    v25 = tri_0;
    if ( tri_0 == nullptr )
    {
      v26 = (idTriangles *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x84u,
                             tag: TAG_DEBUG,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      if ( v26 != nullptr )
        v27 = idTriangles::idTriangles(this: v26);
      else
        v27 = nullptr;
      tri_0 = v27;
      v27->numVerts = 4;
      v27->numIndexes = 6;
      idTriangles::AllocStaticTriSurfVerts(this: v27, numVerts: 4);
      idTriangles::AllocStaticTriSurfIndexes(this: tri_0, numIndexes: tri_0->numIndexes);
      v28 = tri_0;
      *tri_0->indexes = 3;
      v28->indexes[1] = 0;
      v28->indexes[2] = 2;
      v28->indexes[3] = 2;
      v28->indexes[4] = 0;
      v28->indexes[5] = 1;
      idTriangles::UpdateIndexBuffer(this: v28);
      v25 = tri_0;
    }
    p_x = &v25->verts->xyz.x;
    HIDWORD(v30) = p_x + 11;
    renderViewObject = this->renderViewObject;
    HIDWORD(v32) = p_x + 8;
    LODWORD(v30) = renderViewObject->renderWidth;
    LODWORD(v32) = renderViewObject->renderHeight;
    p_x[3] = 0.0;
    p_x[4] = 1.0;
    p_x[1] = -0.5;
    p_x[2] = 0.0;
    v33 = (float)((float)((float)v32 / (float)v30) * (float)0.5);
    *p_x = -v33;
    p_x[11] = 0.0;
    p_x[12] = 0.0;
    p_x[8] = -v33;
    p_x[9] = 0.5;
    p_x[10] = 0.0;
    p_x[19] = 1.0;
    p_x[20] = 0.0;
    p_x[16] = (float)((float)v32 / (float)v30) * (float)0.5;
    p_x[17] = 0.5;
    p_x[18] = 0.0;
    p_x[27] = 1.0;
    p_x[28] = 1.0;
    p_x[24] = (float)((float)v32 / (float)v30) * (float)0.5;
    p_x[25] = -0.5;
    p_x[26] = 0.0;
    idTriangles::UpdateVertexBuffer(this: v25);
    v38.objectPtr = progTextureOnly;
    v37.objectPtr = tri_0;
    GL_DrawElements(prog: &v38, tri: &v37, extraState: 0x8000C00000000000uLL, skipDetailTriangles: v34);
    GL_State(stateBits: 0x400000000000uLL, forceGlState: v35);
    this->renderViewObject->r.skipPostProcess = true;
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$239170
// EA  : 0x82969AB8
// RVA : 0x00969AB8
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_239170()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 432 + 176));
}


// ========================================================================
// __unwind$239171
// EA  : 0x82969AE0
// RVA : 0x00969AE0
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_239171()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 432 + 96), tag: TAG_DEBUG);
}


// ========================================================================
// ?ShowGammaBias@idRender@@AAAXXZ
// EA  : 0x82969B18
// RVA : 0x00969B18
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowGammaBias(idRender *this)
{
  char *buffer; // r28
  __int64 v3; // r11
  int v4; // r3
  int v5; // r4
  double v6; // fp0
  int v7; // r5
  double v8; // fp13
  double v9; // fp10
  int v10; // r11
  char v11; // r9
  int v12; // r8
  int i; // r6
  int j; // ctr
  const idDeclRenderProg *progTextureOnly; // r29
  idTriangles *v16; // r3
  idTriangles *v17; // r3
  idTriangles *v18; // r3
  idTriangles *v19; // r3
  float *p_x; // r11
  __int64 v21; // r8
  idRenderView *renderViewObject; // r6
  __int64 v23; // r6
  double v24; // fp5
  bool v25; // r7
  bool v26; // r5
  int v27; // [sp+8h] [-178h]
  idODSObject<idDeclRenderProg> v28; // [sp+70h] [-110h] BYREF
  idODSObject<idTriangles> v29; // [sp+74h] [-10Ch] BYREF
  idRenderMatrix v30; // [sp+80h] [-100h] BYREF
  idTempArray<char> v31; // [sp+C0h] [-C0h] BYREF
  idImageOpts v32; // [sp+D0h] [-B0h] BYREF

  if ( r_testGammaBias.valueInteger > 0 )
  {
    if ( gammaTestImage == nullptr )
    {
      idImageOpts::idImageOpts(this: &v32);
      v32.format = FMT_RGBA8;
      v32.width = 512;
      v32.height = 512;
      v32.filter = TF_NEAREST;
      gammaTestImage = idImageManager::ScratchImage(this: globalImages, _name: "_gammaTestImage", imgOpts: &v32);
    }
    idTempArray<char>::idTempArray<char>(this: &v31, num: 0x100000u);
    buffer = v31.buffer;
    memset(Dst: v31.buffer, Val: 0, Size: 0x100000u);
    HIDWORD(v3) = "frictionTime";
    v4 = -40;
    v5 = 0;
    do
    {
      LODWORD(v3) = v4;
      v6 = 1.0;
      v7 = 0;
      v8 = (float)v3;
      do
      {
        v9 = (float)((float)((float)v6 * (float)64.0) + (float)v8);
        v6 = (float)((float)v6 * (float)1.5);
        v10 = (int)v9;
        if ( (int)v9 >= 0 )
        {
          if ( v10 > 255 )
            LOBYTE(v10) = -1;
        }
        else
        {
          LOBYTE(v10) = 0;
        }
        v11 = v10;
        v12 = v5;
        for ( i = 64; i != 0; --i )
        {
          HIDWORD(v3) = 0;
          for ( j = 128; j != 0; --j )
          {
            LODWORD(v3) = v12 + v7 / 4 + HIDWORD(v3)++;
            LODWORD(v3) = &buffer[4 * v3];
            *(_BYTE *)v3 = v11;
            *(_BYTE *)(v3 + 1) = v11;
            *(_BYTE *)(v3 + 2) = v11;
          }
          v12 += 512;
        }
        v7 += 512;
      }
      while ( v7 < 2048 );
      v4 += 10;
      v5 += 0x8000;
    }
    while ( v4 < 40 );
    idImage::SubImageUpload(
      this: gammaTestImage,
      mipLevel: 0,
      destX: 0,
      destY: 0,
      destZ: D3DCUBEMAP_FACE_POSITIVE_X,
      width: 512,
      height: 512,
      pic: buffer,
      pixelPitch: v27);
    v30.m[0] = 1.0;
    v30.m[5] = 1.0;
    v30.m[10] = 1.0;
    v30.m[15] = 1.0;
    v30.m[1] = 0.0;
    v30.m[2] = 0.0;
    v30.m[3] = 0.0;
    v30.m[4] = 0.0;
    v30.m[6] = 0.0;
    v30.m[7] = 0.0;
    v30.m[8] = 0.0;
    v30.m[9] = 0.0;
    v30.m[11] = 0.0;
    v30.m[12] = 0.0;
    v30.m[13] = 0.0;
    v30.m[14] = 0.0;
    idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v30);
    progTextureOnly = tr.progTextureOnly;
    idDeclRenderProg::SetTextureParm(this: tr.progTextureOnly, i: 0, image: gammaTestImage);
    v16 = tri_1;
    if ( tri_1 == nullptr )
    {
      v17 = (idTriangles *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x84u,
                             tag: TAG_DEBUG,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      if ( v17 != nullptr )
        v18 = idTriangles::idTriangles(this: v17);
      else
        v18 = nullptr;
      tri_1 = v18;
      v18->numVerts = 4;
      v18->numIndexes = 6;
      idTriangles::AllocStaticTriSurfVerts(this: v18, numVerts: 4);
      idTriangles::AllocStaticTriSurfIndexes(this: tri_1, numIndexes: tri_1->numIndexes);
      v19 = tri_1;
      *tri_1->indexes = 3;
      v19->indexes[1] = 0;
      v19->indexes[2] = 2;
      v19->indexes[3] = 2;
      v19->indexes[4] = 0;
      v19->indexes[5] = 1;
      idTriangles::UpdateIndexBuffer(this: v19);
      v16 = tri_1;
    }
    p_x = &v16->verts->xyz.x;
    HIDWORD(v21) = p_x + 11;
    renderViewObject = this->renderViewObject;
    HIDWORD(v23) = p_x + 8;
    LODWORD(v21) = renderViewObject->renderWidth;
    LODWORD(v23) = renderViewObject->renderHeight;
    p_x[3] = 0.0;
    p_x[4] = 1.0;
    p_x[1] = -0.5;
    p_x[2] = 0.0;
    v24 = (float)((float)((float)v23 / (float)v21) * (float)0.5);
    *p_x = -v24;
    p_x[11] = 0.0;
    p_x[12] = 0.0;
    p_x[8] = -v24;
    p_x[9] = 0.5;
    p_x[10] = 0.0;
    p_x[19] = 1.0;
    p_x[20] = 0.0;
    p_x[16] = (float)((float)v23 / (float)v21) * (float)0.5;
    p_x[17] = 0.5;
    p_x[18] = 0.0;
    p_x[27] = 1.0;
    p_x[28] = 1.0;
    p_x[24] = (float)((float)v23 / (float)v21) * (float)0.5;
    p_x[25] = -0.5;
    p_x[26] = 0.0;
    idTriangles::UpdateVertexBuffer(this: v16);
    v28.objectPtr = progTextureOnly;
    v29.objectPtr = tri_1;
    GL_DrawElements(prog: &v28, tri: &v29, extraState: 0x8000C00000000000uLL, skipDetailTriangles: v25);
    GL_State(stateBits: 0x400000000000uLL, forceGlState: v26);
    this->renderViewObject->r.skipPostProcess = true;
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$239343
// EA  : 0x82969F44
// RVA : 0x00969F44
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_239343()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 384 + 192));
}


// ========================================================================
// __unwind$239344
// EA  : 0x82969F6C
// RVA : 0x00969F6C
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_239344()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 384 + 96), tag: TAG_DEBUG);
}


// ========================================================================
// ?ShowTextureReconstruct@idRender@@AAAXXZ
// EA  : 0x82969FA0
// RVA : 0x00969FA0
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowTextureReconstruct(idRender *this)
{
  const idDeclRenderProg *v2; // r27
  char *buffer; // r29
  int v4; // r7
  char *v5; // r6
  int v6; // ctr
  int v7; // r10
  char *v8; // r11
  bool v9; // r5
  bool v10; // r5
  bool v11; // r7
  bool v12; // r5
  int v13; // [sp+8h] [-148h]
  idODSObject<idDeclRenderProg> v14; // [sp+64h] [-ECh] BYREF
  idODSObject<idTriangles> v15; // [sp+68h] [-E8h] BYREF
  idRenderMatrix v16; // [sp+70h] [-E0h] BYREF
  idTempArray<char> v17; // [sp+B0h] [-A0h] BYREF
  idImageOpts v18; // [sp+C0h] [-90h] BYREF

  if ( r_testTextureReconstruct.valueInteger > 0 )
  {
    v2 = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclRenderProg::resourceList,
                                     name: "testTextureReconstruct",
                                     makeDefault: true);
    if ( v2 != nullptr )
    {
      if ( textureReconstructTestImage == nullptr )
      {
        idImageOpts::idImageOpts(this: &v18);
        v18.width = 256;
        v18.format = FMT_RGBA8;
        v18.height = 256;
        v18.filter = TF_NEAREST;
        textureReconstructTestImage = idImageManager::ScratchImage(
                                        this: globalImages,
                                        _name: "_textureReconstructTestImage",
                                        imgOpts: &v18);
      }
      idTempArray<char>::idTempArray<char>(this: &v17, num: 0x40000u);
      buffer = v17.buffer;
      v4 = 0;
      v5 = v17.buffer + 2;
      do
      {
        v6 = 256;
        v7 = 0;
        v8 = v5 - 1023;
        do
        {
          v8[1021] = v4;
          v8[1022] = v7;
          v8[1023] = v4;
          v8 += 1024;
          *v8 = v7++;
          --v6;
        }
        while ( v6 != 0 );
        ++v4;
        v5 += 4;
      }
      while ( v4 < 256 );
      idImage::SubImageUpload(
        this: textureReconstructTestImage,
        mipLevel: 0,
        destX: 0,
        destY: 0,
        destZ: D3DCUBEMAP_FACE_POSITIVE_X,
        width: 256,
        height: 256,
        pic: buffer,
        pixelPitch: v13);
      GL_State(stateBits: 0xC00000000000uLL, forceGlState: v9);
      v16.m[0] = 1.0;
      v16.m[1] = 0.0;
      v16.m[2] = 0.0;
      v16.m[3] = 0.0;
      v16.m[4] = 0.0;
      v16.m[5] = 1.0;
      v16.m[6] = 0.0;
      v16.m[7] = 0.0;
      v16.m[8] = 0.0;
      v16.m[9] = 0.0;
      v16.m[10] = 1.0;
      v16.m[11] = 0.0;
      v16.m[12] = 0.0;
      v16.m[13] = 0.0;
      v16.m[14] = 0.0;
      v16.m[15] = 1.0;
      idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v16);
      idDeclRenderProg::SetTextureParm(this: v2, i: 0, image: textureReconstructTestImage);
      GL_Scissor(x: 0, y: 0, w: this->renderViewObject->renderWidth, h: this->renderViewObject->renderHeight);
      GL_State(stateBits: 0xC00000000000uLL, forceGlState: v10);
      idParmState::SetPositionToViewTexture(
        this: renderThreadParmState,
        windowWidth: this->renderViewObject->renderWidth,
        windowHeight: this->renderViewObject->renderHeight,
        renderWidth: this->renderViewObject->renderWidth,
        renderHeight: this->renderViewObject->renderHeight);
      v15.objectPtr = tr.unitSquareModel->surfaces.list->geometry;
      v14.objectPtr = v2;
      GL_DrawElements(prog: &v14, tri: &v15, extraState: 0, skipDetailTriangles: v11);
      GL_State(stateBits: 0x400000000000uLL, forceGlState: v12);
      this->renderViewObject->r.skipPostProcess = true;
      if ( buffer != nullptr )
        idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
    }
  }
}


// ========================================================================
// __unwind$239470
// EA  : 0x8296A204
// RVA : 0x0096A204
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_239470()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 336 + 176));
}


// ========================================================================
// ?ShowGammaCalibrationTest@idRender@@AAAXXZ
// EA  : 0x8296A238
// RVA : 0x0096A238
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRender::ShowGammaCalibrationTest(idRender *this)
{
  int valueInteger; // r3 OVERLAPPED
  __int64 v3; // r7 OVERLAPPED
  __int64 v4; // r4
  idTriangles *v5; // r3
  idTriangles *v6; // r3
  idTriangles *v7; // r3
  idRenderView *renderViewObject; // r9
  int renderWidth; // r10
  __int64 v10; // r9 OVERLAPPED
  double v11; // fp0
  double v12; // fp13
  __int64 v13; // fp13
  idRenderView *v14; // r10
  float *v15; // r11
  __int64 v16; // r10
  int v17; // r7
  float v18; // r5
  double v19; // fp4
  bool v20; // r7
  bool v21; // r5
  idODSObject<idTriangles> v22; // [sp+50h] [-B0h] BYREF
  idODSObject<idDeclRenderProg> v23; // [sp+54h] [-ACh] BYREF
  idVec3 v24; // [sp+58h] [-A8h] BYREF
  idRenderMatrix v25; // [sp+70h] [-90h] BYREF

  if ( r_calibrateGamma.valueInteger <= 0 )
    return;
  GL_Clear(color: true, depth: false, stencil: false, stencilValue: 0, r: 0.2, g: 0.2, b: 0.2, a: 1.0);
  valueInteger = r_calibrateGammaLum.valueInteger;
  *(_QWORD *)&v24.x = *(_QWORD *)&valueInteger;
  if ( r_calibrateGammaMode.valueInteger <= 3u && r_calibrateGammaMode.valueInteger != 0 )
  {
    if ( r_calibrateGammaMode.valueInteger != 1 )
    {
      v24.x = 0.0;
      if ( r_calibrateGammaMode.valueInteger == 2 )
      {
        v24.y = (float)*(__int64 *)&valueInteger * (float)0.0039215689;
        v24.z = 0.0;
      }
      else
      {
        v24.y = 0.0;
        v24.z = (float)*(__int64 *)&valueInteger * (float)0.0039215689;
      }
      goto LABEL_11;
    }
    v24.y = 0.0;
    v24.z = 0.0;
  }
  else
  {
    v24.z = (float)*(__int64 *)&valueInteger * (float)0.0039215689;
    v24.y = v24.z;
  }
  v24.x = (float)*(__int64 *)&valueInteger * (float)0.0039215689;
LABEL_11:
  v25.m[0] = 1.0;
  v25.m[1] = 0.0;
  v25.m[2] = 0.0;
  v25.m[3] = 0.0;
  v25.m[4] = 0.0;
  v25.m[5] = 1.0;
  v25.m[6] = 0.0;
  v25.m[7] = 0.0;
  v25.m[8] = 0.0;
  v25.m[9] = 0.0;
  v25.m[10] = 1.0;
  v25.m[11] = 0.0;
  v25.m[12] = 0.0;
  v25.m[13] = 0.0;
  v25.m[14] = 0.0;
  v25.m[15] = 1.0;
  idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v25);
  idDeclRenderParm::Set(this: rp->Color, vec: &v24);
  HIDWORD(v4) = tri_2;
  if ( tri_2 == nullptr )
  {
    v5 = (idTriangles *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x84u,
                          tag: TAG_DEBUG,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    LODWORD(v24.x) = v5;
    if ( v5 != nullptr )
      v6 = idTriangles::idTriangles(this: v5);
    else
      v6 = nullptr;
    tri_2 = v6;
    v6->numVerts = 4;
    v6->numIndexes = 6;
    idTriangles::AllocStaticTriSurfVerts(this: v6, numVerts: 4);
    idTriangles::AllocStaticTriSurfIndexes(this: tri_2, numIndexes: tri_2->numIndexes);
    v7 = tri_2;
    *tri_2->indexes = 3;
    v7->indexes[1] = 0;
    v7->indexes[2] = 2;
    v7->indexes[3] = 2;
    v7->indexes[4] = 0;
    v7->indexes[5] = 1;
    idTriangles::UpdateIndexBuffer(this: v7);
    HIDWORD(v4) = tri_2;
  }
  renderViewObject = this->renderViewObject;
  renderWidth = renderViewObject->renderWidth;
  HIDWORD(v10) = renderWidth;
  LODWORD(v10) = renderViewObject->renderHeight;
  if ( renderWidth <= (int)v10 )
    HIDWORD(v10) = v10;
  if ( HIDWORD(v10) != 0 )
  {
    v13 = *(__int64 *)((char *)&v3 - 4);
    LODWORD(v3) = renderWidth;
    *(_QWORD *)&v24.x = v3;
    v11 = (float)((float)((float)v10 * (float)0.5) / (float)v13);
    v12 = (float)((float)((float)v3 * (float)0.5) / (float)v13);
  }
  else
  {
    v11 = 0.5;
    v12 = 0.5;
  }
  v14 = this->renderViewObject;
  v15 = *(float **)(HIDWORD(v4) + 88);
  HIDWORD(v16) = v15 + 8;
  v17 = v14->renderWidth;
  v18 = *(float *)&v14->renderHeight;
  v15[1] = -v11;
  LODWORD(v4) = v17;
  *((float *)&v16 + 1) = v18;
  v15[2] = 0.0;
  v24.y = v18;
  LODWORD(v24.x) = v15 + 24;
  v19 = (float)((float)((float)v16 / (float)v4) * (float)v12);
  *v15 = -v19;
  v15[8] = -v19;
  v15[9] = v11;
  v15[10] = 0.0;
  v15[16] = (float)((float)v16 / (float)v4) * (float)v12;
  v15[17] = v11;
  v15[18] = 0.0;
  v15[24] = (float)((float)v16 / (float)v4) * (float)v12;
  v15[25] = -v11;
  v15[26] = 0.0;
  idTriangles::UpdateVertexBuffer(this: (idTriangles *)HIDWORD(v4));
  v22.objectPtr = tri_2;
  v23.objectPtr = tr.progColorParmOnly;
  GL_DrawElements(prog: &v23, tri: &v22, extraState: 0x8000400000000000uLL, skipDetailTriangles: v20);
  idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
  GL_State(stateBits: 0x400000000000uLL, forceGlState: v21);
  renderState.renderViewObject->r.skipPostProcess = true;
}


// ========================================================================
// __unwind$239589
// EA  : 0x8296A604
// RVA : 0x0096A604
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_239589()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 88), tag: TAG_DEBUG);
}


// ========================================================================
// ?ShowLoadedImages@idRender@@AAAXXZ
// EA  : 0x8296A638
// RVA : 0x0096A638
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowLoadedImages(idRender *this)
{
  double valueFloat; // fp27
  idTriangles *geometry; // r26
  idRenderView **p_renderViewObject; // r29
  bool v5; // r7
  int v6; // r21
  int i; // r20
  idResource *v8; // r27
  __int64 v9; // r8
  int v10; // r25
  unsigned int v11; // r24
  __int64 v12; // r6
  bool v13; // r7
  int num; // r25
  int j; // r28
  __int64 v16; // r9
  unsigned int v17; // r27
  __int64 v18; // r7
  bool v19; // r7
  __int64 v20; // [sp+50h] [-150h] BYREF
  __int64 v21; // [sp+58h] [-148h]
  idODSObject<idDeclRenderProg> v22; // [sp+60h] [-140h] BYREF
  idODSObject<idDeclRenderProg> v23; // [sp+64h] [-13Ch] BYREF
  idODSObject<idTriangles> v24; // [sp+68h] [-138h] BYREF
  unsigned __int64 v25; // [sp+70h] [-130h]
  idODSObject<idTriangles> v26; // [sp+78h] [-128h] BYREF
  unsigned __int64 v27; // [sp+80h] [-120h]
  idODSObject<idTriangles> v28; // [sp+88h] [-118h] BYREF
  __int64 v29; // [sp+90h] [-110h]
  unsigned __int64 v30; // [sp+98h] [-108h]
  idODSObject<idDeclRenderProg> v31; // [sp+A0h] [-100h] BYREF
  idRenderMatrix v32; // [sp+B0h] [-F0h] BYREF
  idBitBlockAllocator v33; // [sp+F0h] [-B0h] BYREF
  __int64 v34; // [sp+100h] [-A0h]
  __int64 v35; // [sp+108h] [-98h]

  if ( r_drawLoadedImages.valueInteger != 0 )
  {
    valueFloat = r_drawLoadedImagesScale.valueFloat;
    if ( r_drawLoadedImagesScale.valueFloat < 1.0 )
      valueFloat = 1.0;
    idBitBlockAllocator::idBitBlockAllocator(this: &v33, blocksWide: 320, blocksHigh: 180);
    geometry = tr.zeroOneSquareModel->surfaces.list->geometry;
    GL_SetDefaultState();
    p_renderViewObject = &this->renderViewObject;
    GL_Viewport(x: 0, y: 0, w: (*p_renderViewObject)->renderWidth, h: (*p_renderViewObject)->renderHeight);
    GL_Scissor(x: 0, y: 0, w: (*p_renderViewObject)->renderWidth, h: (*p_renderViewObject)->renderHeight);
    v32.m[15] = 1.0;
    v32.m[0] = 2.0;
    v32.m[1] = 0.0;
    v32.m[2] = 0.0;
    v32.m[3] = -1.0;
    v32.m[4] = 0.0;
    v32.m[5] = 2.0;
    v32.m[6] = 0.0;
    v32.m[7] = -1.0;
    v32.m[8] = 0.0;
    v32.m[9] = 0.0;
    v32.m[10] = 0.0;
    v32.m[11] = 0.5;
    v32.m[12] = 0.0;
    v32.m[13] = 0.0;
    v32.m[14] = 0.0;
    idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v32);
    idDeclRenderParm::Set(this: rp->Color, x: 0.2, y: 0.2, z: 0.2, w: 1.0);
    idParmState::VirtualEvaluateParmBlock(
      this: renderThreadParmState,
      localParmBlock: &tr.progColorOnly->parmBlock,
      parmBlock: &tr.progColorOnly->parmBlock);
    v28.objectPtr = geometry;
    v23.objectPtr = tr.progColorOnly;
    GL_DrawElements(prog: &v23, tri: &v28, extraState: 0x8000C40000000000uLL, skipDetailTriangles: v5);
    idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
    v6 = 0;
    for ( i = idImage::resourceList.num; v6 < i; ++v6 )
    {
      v8 = idResourceList::Index(this: &idImage::resourceList, index: v6);
      v34 = *(_QWORD *)&v8[1].staleCount;
      LODWORD(v9) = HIDWORD(v34);
      v35 = v9;
      v10 = (int)(float)((float)v9 * (float)((float)1.0 / (float)valueFloat));
      LODWORD(v21) = (int)(float)((float)v34 * (float)((float)1.0 / (float)valueFloat));
      v11 = v21;
      if ( v10 >= 1 && (int)v21 >= 1 )
      {
        if ( !idBitBlockAllocator::FindBlockLinear(this: &v33, x: (int *)&v20, y: (int *)&v20 + 1, w: v10, h: v21) )
          break;
        idDeclRenderParm::SetImage(this: rp->transMap, image: (const idImage *)v8);
        LODWORD(v12) = v20;
        v27 = __PAIR64__(HIDWORD(v20), v10);
        v25 = __PAIR64__(v10, v11);
        v30 = __PAIR64__(v20, HIDWORD(v20));
        v29 = v12;
        v32.m[5] = (float)__SPAIR64__(v10, v11) * (float)0.011111111;
        v32.m[7] = (float)((float)v12 * (float)0.011111111) - (float)1.0;
        v32.m[0] = (float)__SPAIR64__(HIDWORD(v20), v10) * (float)0.0062500001;
        v32.m[3] = (float)((float)__SPAIR64__(v20, HIDWORD(v20)) * (float)0.0062500001) - (float)1.0;
        idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v32);
        v24.objectPtr = geometry;
        v31.objectPtr = tr.progBasicBlend;
        GL_DrawElements(prog: &v31, tri: &v24, extraState: 0x8000C40000000000uLL, skipDetailTriangles: v13);
      }
    }
    num = idSoundSample::resourceList.num;
    idDeclRenderParm::SetImage(this: rp->transMap, image: globalImages->defaultImage);
    for ( j = 0; j < num; ++j )
    {
      LODWORD(v16) = idResourceList::Index(this: &idSoundSample::resourceList, index: j)[1].resourceListPtr;
      v30 = v16;
      LODWORD(v29) = (int)(float)((float)((float)1.0 / (float)valueFloat) * (float)__fsqrts((double)v16));
      v17 = v29;
      if ( !idBitBlockAllocator::FindBlockLinear(this: &v33, x: (int *)&v20, y: (int *)&v20 + 1, w: v29, h: v29) )
        break;
      LODWORD(v18) = HIDWORD(v20);
      v27 = __PAIR64__(HIDWORD(v20), v17);
      v25 = v20;
      v21 = v18;
      v32.m[0] = (float)__SPAIR64__(HIDWORD(v20), v17) * (float)0.0062500001;
      v32.m[5] = (float)__SPAIR64__(HIDWORD(v20), v17) * (float)0.011111111;
      v32.m[7] = (float)((float)v20 * (float)0.011111111) - (float)1.0;
      v32.m[3] = (float)((float)v18 * (float)0.0062500001) - (float)1.0;
      idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v32);
      v26.objectPtr = geometry;
      v22.objectPtr = tr.progBasicBlend;
      GL_DrawElements(prog: &v22, tri: &v26, extraState: 0x8000C40000000000uLL, skipDetailTriangles: v19);
    }
    idParmState::VirtualRollbackParmBlock(
      this: renderThreadParmState,
      localParmBlock: &tr.progColorOnly->parmBlock,
      parmBlock: &tr.progColorOnly->parmBlock);
    renderState.renderViewObject->r.skipPostProcess = true;
    idBitBlockAllocator::~idBitBlockAllocator(this: &v33);
  }
}


// ========================================================================
// __unwind$239719
// EA  : 0x8296AACC
// RVA : 0x0096AACC
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_239719()
{
  int v0; // r12

  idBitBlockAllocator::~idBitBlockAllocator(this: (idBitBlockAllocator *)(v0 - 416 + 240));
}


// ========================================================================
// ?ShowTestImage@idRender@@AAAXXZ
// EA  : 0x8296AB00
// RVA : 0x0096AB00
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRender::ShowTestImage(idRender *this)
{
  idRender *v1; // r22
  const idDeclRenderProg *v2; // r10
  bool v3; // r7
  bool v4; // r5
  idRenderView *renderViewObject; // r11
  idImage *testImage; // r24
  idImageOpts *p_opts; // r29
  __int64 v8; // r8 OVERLAPPED
  __int64 v9; // r10 OVERLAPPED
  double v10; // fp28
  double v11; // fp0
  __int64 v12; // fp13
  unsigned __int64 v13; // r10
  double v14; // fp29
  idParmState **v15; // r25
  const idDeclRenderProg *progCubeImageOnly; // r29
  textureFormat_t format; // r11
  const idParmBlock *p_parmBlock; // r28
  bool v19; // r23
  idTriangles *v21; // r3
  idTriangles *v23; // r3
  idTriangles *v24; // r3
  idTriangles *v25; // r3
  int v26; // r10
  int v27; // r11
  int i; // ctr
  idDrawVert *verts; // r9
  int v30; // ctr
  idDrawVert **p_verts; // r30
  int v33; // r10
  unsigned int v34; // r7
  double v47; // fp13
  float *p_x; // r9
  double v49; // fp0
  double v50; // fp12
  double v51; // fp11
  float *v54; // r9
  idDrawVert *v59; // r29
  int v60; // r9
  int v61; // r9
  float *v64; // r8
  bool v65; // r7
  bool v66; // r5
  idTriangles *v67; // r3
  idTriangles *v68; // r3
  idTriangles *v69; // r3
  idTriangles *v70; // r3
  float *v71; // r11
  bool v72; // r7
  int v73; // r10
  int v74; // r9
  int v75; // r8
  int v76; // r7
  int v77; // r6
  int v78; // r5
  int v79; // r4
  idRenderView *v80; // r11
  int v81; // [sp+8h] [-1B8h]
  const idDeclRenderProg *v82; // [sp+50h] [-170h]
  bool v83; // [sp+60h] [-160h]
  idParmBlock *v84; // [sp+64h] [-15Ch]
  idImage *v85; // [sp+68h] [-158h]
  idODSObject<idTriangles> v86; // [sp+70h] [-150h] BYREF
  idODSObject<idTriangles> v87; // [sp+74h] [-14Ch] BYREF
  unsigned __int64 v88; // [sp+78h] [-148h] BYREF
  idParmState **v89; // [sp+80h] [-140h]
  idODSObject<idDeclRenderProg> v90; // [sp+84h] [-13Ch] BYREF
  idODSObject<idRenderModelSurface> v91; // [sp+88h] [-138h] BYREF
  idODSObject<idDeclRenderProg> v92; // [sp+8Ch] [-134h] BYREF
  idRenderMatrix v93; // [sp+90h] [-130h] BYREF
  float v94[28]; // [sp+D0h] [-F0h] BYREF

  v1 = this;
  if ( tr.testMaterial != nullptr )
  {
    if ( tr.testMaterial->progs[6] != nullptr )
    {
      GL_SetDefaultState();
      GL_Viewport(x: 0, y: 0, w: tr.renderWidth, h: tr.renderHeight);
      GL_Scissor(x: 0, y: 0, w: tr.renderWidth, h: tr.renderHeight);
      idParmState::VirtualEvaluateParmBlock(
        this: renderThreadParmState,
        localParmBlock: &tr.testMaterial->renderParmBlock,
        parmBlock: &tr.testMaterial->renderParmBlock);
      idParmState::VirtualEvaluateParmBlock(
        this: renderThreadParmState,
        localParmBlock: &tr.testMaterial->progs[6]->parmBlock,
        parmBlock: &tr.testMaterial->progs[6]->parmBlock);
      v2 = tr.testMaterial->progs[6];
      v91.objectPtr = tr.unitSquareModel->surfaces.list;
      v90.objectPtr = v2;
      GL_DrawElements(prog: &v90, surf: &v91, extraState: 0, skipDetailTriangles: v3);
      idParmState::VirtualRollbackParmBlock(
        this: renderThreadParmState,
        localParmBlock: &tr.testMaterial->progs[6]->parmBlock,
        parmBlock: &tr.testMaterial->progs[6]->parmBlock);
      idParmState::VirtualRollbackParmBlock(
        this: renderThreadParmState,
        localParmBlock: &tr.testMaterial->renderParmBlock,
        parmBlock: &tr.testMaterial->renderParmBlock);
      GL_State(stateBits: 0x400000000000uLL, forceGlState: v4);
      renderViewObject = v1->renderViewObject;
      if ( renderViewObject != nullptr )
        renderViewObject->r.skipPostProcess = true;
    }
  }
  else
  {
    testImage = tr.testImage;
    v85 = tr.testImage;
    if ( tr.testImage != nullptr )
    {
      p_opts = &tr.testImage->opts;
      memcpy(Dst: v94, Src: &tr.testImage->opts, Size: 0x50u);
      v9 = *(_QWORD *)&tr.testImage->opts.width;
      if ( SHIDWORD(v9) <= (int)v9 )
        HIDWORD(v9) = tr.testImage->opts.height;
      if ( HIDWORD(v9) != 0 )
      {
        v12 = *(__int64 *)((char *)&v9 + 4);
        v10 = (float)((float)((float)v9 * (float)0.5) / (float)*(__int64 *)((char *)&v9 + 4));
        LODWORD(v8) = tr.testImage->opts.width;
        v11 = (float)((float)((float)v8 * (float)0.5) / (float)v12);
      }
      else
      {
        v10 = 0.5;
        v11 = 0.5;
      }
      v13 = __PAIR64__(tr.renderHeight, tr.renderWidth);
      v88 = __PAIR64__(tr.renderHeight, tr.renderWidth);
      v14 = (float)((float)((float)*(__int64 *)((char *)&v8 - 4) / (float)__SPAIR64__(tr.renderHeight, tr.renderWidth))
                  * (float)v11);
      GL_SetDefaultState();
      GL_Viewport(x: 0, y: 0, w: tr.renderWidth, h: tr.renderHeight);
      GL_Scissor(x: 0, y: 0, w: tr.renderWidth, h: tr.renderHeight);
      v15 = &renderThreadParmState;
      v89 = &renderThreadParmState;
      v93.m[0] = 1.0;
      v93.m[5] = 1.0;
      v93.m[10] = 1.0;
      v93.m[15] = 1.0;
      v93.m[1] = 0.0;
      v93.m[2] = 0.0;
      v93.m[3] = 0.0;
      v93.m[4] = 0.0;
      v93.m[6] = 0.0;
      v93.m[7] = 0.0;
      v93.m[8] = 0.0;
      v93.m[9] = 0.0;
      v93.m[11] = 0.0;
      v93.m[12] = 0.0;
      v93.m[13] = 0.0;
      v93.m[14] = 0.0;
      idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v93);
      idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
      if ( p_opts->textureType == TT_CUBIC )
      {
        progCubeImageOnly = tr.progCubeImageOnly;
      }
      else
      {
        format = testImage->opts.format;
        if ( format == FMT_DEPTH || format == FMT_DEPTH_STENCIL )
          progCubeImageOnly = tr.progTestImageShadow;
        else
          progCubeImageOnly = tr.progTestImage;
      }
      p_parmBlock = &progCubeImageOnly->parmBlock;
      v82 = progCubeImageOnly;
      v84 = &progCubeImageOnly->parmBlock;
      idParmState::VirtualEvaluateParmBlock(
        this: renderThreadParmState,
        localParmBlock: &progCubeImageOnly->parmBlock,
        parmBlock: &progCubeImageOnly->parmBlock);
      idDeclRenderProg::SetTextureParm(this: progCubeImageOnly, i: 0, image: testImage);
      v19 = idImage::EnableDepthCompareMode(this: testImage, enable: false);
      v83 = v19;
      if ( LODWORD(v94[0]) == 2 )
      {
        v94[1] = 0.0;
        v94[3] = 0.0;
        v94[4] = 0.0;
        v94[6] = 0.0;
        v94[8] = 0.0;
        v94[9] = 0.0;
        v21 = cubeTris;
        v94[11] = 0.0;
        _R26 = 2;
        v94[0] = (float)((float)v14 * (float)0.25) * (float)-2.0;
        v94[2] = (float)((float)v14 * (float)0.25) * (float)2.0;
        v94[5] = (float)((float)v10 * (float)0.25) * (float)2.0;
        v94[7] = (float)((float)v10 * (float)0.25) * (float)-2.0;
        v94[10] = (float)((float)v14 * (float)0.25) * (float)4.0;
        if ( cubeTris == nullptr )
        {
          v23 = (idTriangles *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x84u,
                                 tag: TAG_DEBUG,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
          if ( v23 != nullptr )
            v24 = idTriangles::idTriangles(this: v23);
          else
            v24 = nullptr;
          cubeTris = v24;
          v24->numVerts = 24;
          v24->numIndexes = 36;
          idTriangles::AllocStaticTriSurfVerts(this: v24, numVerts: 24);
          idTriangles::AllocStaticTriSurfIndexes(this: cubeTris, numIndexes: cubeTris->numIndexes);
          v25 = cubeTris;
          v26 = 2;
          v27 = 3;
          for ( i = 6; i != 0; --i )
          {
            v25->indexes[v27 - 3] = v26 - 2;
            v25->indexes[v27 - 2] = v26 - 1;
            v25->indexes[v27 - 1] = v26;
            v25->indexes[v27] = v26 - 2;
            v25->indexes[v27 + 1] = v26;
            v25->indexes[v27 + 2] = v26 + 1;
            v26 += 4;
            v27 += 6;
          }
          idTriangles::UpdateIndexBuffer(this: v25);
          v21 = cubeTris;
        }
        verts = v21->verts;
        __asm { vspltisw128 v63, 0 }
        v30 = 6;
        p_verts = &v21->verts;
        _R6 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
        v33 = 0;
        v34 = 0;
        _R27 = 1;
        _R5 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
        _R4 = &_vmx_3f8000003f8000003f8000003f800000;
        _R11 = normal[0];
        do
        {
          __asm { vor128    v61, v95, v63 }
          _R25 = &normal[0][1];
          __asm { lvx128    v62, r0, r4 }
          __asm { lvx128    v13, r0, r6 }
          _R23 = &normal[0][2];
          __asm { lvx128    v0, r0, r5 }
          __asm { vor128    v60, v95, v63 }
          __asm { vor128    v59, v95, v63 }
          _R9 = (int)verts[v33].normal;
          __asm { vor128    v58, v95, v63 }
          _R20 = &normal[0][1];
          _R19 = &normal[0][2];
          _R18 = &normal[0][2];
          _R29 = 4 * ((unsigned __int16)face[v34 / 8][0] + __ROL4__(face[v34 / 8][0], 1));
          _R17 = &normal[0][1];
          __asm
          {
            lvlx128   v57, r29, r11
            vrlimi128 v61, v57, 8, 0
            lvlx128   v56, r29, r25
            lvlx128   v55, r29, r23
            vrlimi128 v61, v56, 4, 3
            vrlimi128 v61, v55, 2, 2
            vaddfp128 v12, v93, v62
            vmaddfp   v0, v12, v0, v13
            vcfpsxws128 v54, v0, 0
            vpkswss128 v53, v86, v54
            vpkshus128 v0, v85, v53
            stvebx    v0, 0, r9
            stvebx    v0, r9, r27
            stvebx    v0, r9, r26
          }
          v47 = v94[v34 / 4];
          p_x = &(*p_verts)[v33].xyz.x;
          v49 = v94[v34 / 4 + 1];
          v50 = (float)(v94[v34 / 4] - (float)((float)v14 * (float)0.25));
          v51 = (float)(v94[v34 / 4 + 1] - (float)((float)v10 * (float)0.25));
          *p_x = v94[v34 / 4] - (float)((float)v14 * (float)0.25);
          p_x[1] = v51;
          _R29 = p_x + 13;
          p_x[2] = 0.0;
          __asm
          {
            lvx128    v62, r0, r4
            lvx128    v0, r0, r5
          }
          _R9 = 4 * ((unsigned __int16)face[v34 / 8][1] + __ROL4__(face[v34 / 8][1], 1));
          __asm { lvx128    v13, r0, r6 }
          __asm
          {
            lvlx128   v52, r9, r20
            lvlx128   v51, r9, r19
            lvlx128   v50, r9, r11
            vrlimi128 v60, v50, 8, 0
            vrlimi128 v60, v52, 4, 3
            vrlimi128 v60, v51, 2, 2
            vaddfp128 v12, v92, v62
            vmaddfp   v0, v12, v0, v13
            vcfpsxws128 v49, v0, 0
            vpkswss128 v48, v81, v49
            vpkshus128 v0, v80, v48
            stvebx    v0, 0, r29
            stvebx    v0, r29, r27
            stvebx    v0, r29, r26
          }
          v54 = &(*p_verts)[v33].xyz.x;
          v54[8] = v50;
          _R29 = v54 + 21;
          v54[10] = 0.0;
          v54[9] = (float)v49 + (float)((float)v10 * (float)0.25);
          __asm { lvx128    v62, r0, r4 }
          __asm
          {
            lvx128    v13, r0, r6
            lvx128    v0, r0, r5
          }
          _R22 = &normal[0][1];
          _R9 = 4 * ((unsigned __int16)face[v34 / 8][2] + __ROL4__(face[v34 / 8][2], 1));
          _R23 = &normal[0][2];
          __asm
          {
            lvlx128   v47, r9, r11
            vrlimi128 v59, v47, 8, 0
            lvlx128   v46, r9, r17
            lvlx128   v45, r9, r18
            vrlimi128 v59, v46, 4, 3
            vrlimi128 v59, v45, 2, 2
            vaddfp128 v12, v91, v62
            vmaddfp   v0, v12, v0, v13
            vcfpsxws128 v44, v0, 0
            vpkswss128 v43, v76, v44
            vpkshus128 v0, v75, v43
            stvebx    v0, 0, r29
            stvebx    v0, r29, r27
            stvebx    v0, r29, r26
          }
          v59 = *p_verts;
          v60 = (int)&(*p_verts)[v33 + 3];
          *(float *)(v60 - 24) = 0.0;
          *(float *)(v60 - 28) = (float)v49 + (float)((float)v10 * (float)0.25);
          *(float *)(v60 - 32) = (float)((float)v14 * (float)0.25) + (float)v47;
          v61 = face[v34 / 8][3];
          v34 += 8;
          __asm { lvx128    v62, r0, r4 }
          __asm
          {
            lvx128    v0, r0, r5
            lvx128    v13, r0, r6
          }
          _R29 = (int)v59[v33 + 3].normal;
          _R9 = 4 * (v61 + __ROL4__(v61, 1));
          __asm
          {
            lvlx128   v42, r9, r22
            lvlx128   v41, r9, r23
            lvlx128   v40, r9, r11
            vrlimi128 v58, v40, 8, 0
            vrlimi128 v58, v42, 4, 3
            vrlimi128 v58, v41, 2, 2
            vaddfp128 v12, v90, v62
            vmaddfp   v0, v12, v0, v13
            vcfpsxws128 v39, v0, 0
            vpkswss128 v38, v71, v39
            vpkshus128 v0, v70, v38
            stvebx    v0, 0, r29
            stvebx    v0, r29, r27
            stvebx    v0, r29, r26
          }
          verts = *p_verts;
          v64 = &(*p_verts)[v33 + 3].xyz.x;
          *v64 = (float)((float)v14 * (float)0.25) + (float)v47;
          v33 += 4;
          v64[1] = v51;
          v64[2] = 0.0;
          --v30;
        }
        while ( v30 != 0 );
        idTriangles::UpdateVertexBuffer(this: v21);
        v92.objectPtr = v82;
        v87.objectPtr = cubeTris;
        GL_DrawElements(prog: &v92, tri: &v87, extraState: 0x8000C40000000000uLL, skipDetailTriangles: v65);
        p_parmBlock = v84;
        v15 = v89;
        v19 = v83;
        v1 = this;
        testImage = v85;
      }
      else
      {
        v67 = tri_3;
        if ( tri_3 == nullptr )
        {
          v68 = (idTriangles *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x84u,
                                 tag: TAG_DEBUG,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
          if ( v68 != nullptr )
            v69 = idTriangles::idTriangles(this: v68);
          else
            v69 = nullptr;
          tri_3 = v69;
          v69->numVerts = 4;
          v69->numIndexes = 6;
          idTriangles::AllocStaticTriSurfVerts(this: v69, numVerts: 4);
          idTriangles::AllocStaticTriSurfIndexes(this: tri_3, numIndexes: tri_3->numIndexes);
          v70 = tri_3;
          *tri_3->indexes = 3;
          v70->indexes[1] = 0;
          v70->indexes[2] = 2;
          v70->indexes[3] = 2;
          v70->indexes[4] = 0;
          v70->indexes[5] = 1;
          idTriangles::UpdateIndexBuffer(this: v70);
          v67 = tri_3;
        }
        v71 = &v67->verts->xyz.x;
        v71[3] = 0.0;
        v71[4] = 1.0;
        v71[11] = 0.0;
        v71[12] = 0.0;
        v71[19] = 1.0;
        v71[20] = 0.0;
        v71[27] = 1.0;
        v71[28] = 1.0;
        *v71 = -v14;
        v71[1] = -v10;
        v71[2] = 0.0;
        v71[8] = -v14;
        v71[9] = v10;
        v71[10] = 0.0;
        v71[16] = v14;
        v71[17] = v10;
        v71[18] = 0.0;
        v71[24] = v14;
        v71[25] = -v10;
        v71[26] = 0.0;
        idTriangles::UpdateVertexBuffer(this: v67);
        HIDWORD(v88) = progCubeImageOnly;
        v86.objectPtr = tri_3;
        GL_DrawElements(
          prog: (const idODSObject<idDeclRenderProg> *)&v88,
          tri: &v86,
          extraState: 0x8000C40000000000uLL,
          skipDetailTriangles: v72);
      }
      GL_State(stateBits: 0x400000000000uLL, forceGlState: v66);
      if ( v19 != testImage->opts.depthCompareMode )
      {
        testImage->opts.depthCompareMode = v19;
        idImageOpts::operator=(this: &testImage->opts, __that: &testImage->opts);
        idImage::DetermineSamplerStateFromOpts(
          this: testImage,
          a2: v79,
          a3: v78,
          a4: v77,
          a5: v76,
          a6: v75,
          a7: v74,
          a8: v73,
          a9: v81);
        GL_ResetTextureState();
      }
      idParmState::VirtualRollbackParmBlock(this: *v15, localParmBlock: p_parmBlock, parmBlock: p_parmBlock);
      v80 = v1->renderViewObject;
      if ( v80 != nullptr )
        v80->r.skipPostProcess = true;
    }
  }
}


// ========================================================================
// __unwind$239918
// EA  : 0x8296B47C
// RVA : 0x0096B47C
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_239918()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 448 + 88), tag: TAG_DEBUG);
}


// ========================================================================
// __unwind$239919
// EA  : 0x8296B4A8
// RVA : 0x0096B4A8
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_239919()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 448 + 88), tag: TAG_DEBUG);
}


// ========================================================================
// ?ShowTestVMTR@idRender@@AAAXXZ
// EA  : 0x8296B4E0
// RVA : 0x0096B4E0
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowTestVMTR(idRender *this)
{
  const idDecl *v2; // r3
  const idDecl *v3; // r30
  float *resourceError; // r23
  idRenderView **p_renderViewObject; // r21
  double v6; // fp30
  char v7; // r29
  const idDeclRenderProg *str; // r25
  bool v9; // r7
  const idTriangles *v10; // r11
  idTriangles *v11; // r3
  idTriangles *v12; // r3
  idTriangles *v13; // r3
  idTriangles *v14; // r3
  double v15; // fp11
  double v16; // fp12
  double v17; // fp10
  idDrawVert *verts; // r7
  float *p_x; // r11
  float *v20; // r11
  float *v21; // r11
  idDrawVert *v22; // r11
  idDrawVert *v23; // r11
  idDrawVert *v24; // r11
  idDrawVert *v25; // r11
  int v26; // r11
  int i; // ctr
  bool v28; // r5
  idODSObject<idTriangles> v29; // [sp+50h] [-C0h] BYREF
  idODSObject<idDeclRenderProg> v30; // [sp+54h] [-BCh] BYREF
  idTriangles *p_nextOnHashChain; // [sp+58h] [-B8h]
  idRenderMatrix v32; // [sp+60h] [-B0h] BYREF

  if ( r_testVMTR.valueInteger > 0
    && r_currentMaterial.valueString.data != nullptr
    && *r_currentMaterial.valueString.data != 0 )
  {
    v2 = idDeclInfo::FindWithInheritance(
           this: &idMaterial::resourceList,
           name: r_currentMaterial.valueString.data,
           makeDefault: false);
    v3 = v2;
    if ( v2 != nullptr )
    {
      resourceError = (float *)v2[4].resourceError;
      if ( resourceError != nullptr )
      {
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&virtualTextureSystem);
        GL_SetDefaultState();
        p_renderViewObject = &this->renderViewObject;
        GL_Viewport(x: 0, y: 0, w: this->renderViewObject->renderWidth, h: this->renderViewObject->renderHeight);
        GL_Scissor(x: 0, y: 0, w: (*p_renderViewObject)->renderWidth, h: (*p_renderViewObject)->renderHeight);
        v6 = 1.0;
        v32.m[0] = 1.0;
        v32.m[5] = 1.0;
        v32.m[10] = 1.0;
        v32.m[15] = 1.0;
        v32.m[1] = 0.0;
        v32.m[2] = 0.0;
        v32.m[3] = 0.0;
        v32.m[4] = 0.0;
        v32.m[6] = 0.0;
        v32.m[7] = 0.0;
        v32.m[8] = 0.0;
        v32.m[9] = 0.0;
        v32.m[11] = 0.0;
        v32.m[12] = 0.0;
        v32.m[13] = 0.0;
        v32.m[14] = 0.0;
        idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v32);
        idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
        v7 = 1;
        str = (const idDeclRenderProg *)v3[3].name.str;
        if ( str != nullptr || (str = *((const idDeclRenderProg **)&v3[3].idResource + 8), v7 = 0, str != nullptr) )
        {
          p_nextOnHashChain = (idTriangles *)&v3[2].nextOnHashChain;
          idParmState::VirtualEvaluateParmBlock(
            this: renderThreadParmState,
            localParmBlock: (const idParmBlock *)&v3[2].nextOnHashChain,
            parmBlock: (const idParmBlock *)&v3[2].nextOnHashChain);
          idParmState::VirtualEvaluateParmBlock(
            this: renderThreadParmState,
            localParmBlock: &str->parmBlock,
            parmBlock: &str->parmBlock);
          v10 = tri_4;
          if ( tri_4 == nullptr )
          {
            v11 = (idTriangles *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0x84u,
                                   tag: TAG_DEBUG,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
            p_nextOnHashChain = v11;
            if ( v11 != nullptr )
              v12 = idTriangles::idTriangles(this: v11);
            else
              v12 = nullptr;
            tri_4 = v12;
            v12->numIndexes = 6;
            v12->numVerts = 4;
            idTriangles::AllocStaticTriSurfVerts(this: v12, numVerts: 4);
            idTriangles::AllocStaticTriSurfIndexes(this: tri_4, numIndexes: tri_4->numIndexes);
            v13 = tri_4;
            *tri_4->indexes = 0;
            v13->indexes[1] = 3;
            v13->indexes[2] = 2;
            v13->indexes[3] = 1;
            v13->indexes[4] = 0;
            v13->indexes[5] = 2;
            idTriangles::UpdateIndexBuffer(this: v13);
            v14 = tri_4;
            v15 = 1.0;
            v16 = 0.0;
            v17 = 0.0;
            verts = tri_4->verts;
            verts->xyz.x = -0.5;
            verts->xyz.y = -0.5;
            verts->xyz.z = 0.0;
            p_x = &v14->verts->xyz.x;
            p_x[8] = -0.5;
            p_x[9] = 0.5;
            p_x[10] = 0.0;
            v20 = &v14->verts->xyz.x;
            v20[16] = 0.5;
            v20[17] = 0.5;
            v20[18] = 0.0;
            v21 = &v14->verts->xyz.x;
            v21[24] = 0.5;
            v21[25] = -0.5;
            v21[26] = 0.0;
            if ( v7 != 0 )
            {
              v16 = (float)((float)(resourceError[10] * (float)0.0) + resourceError[12]);
              v15 = (float)(resourceError[12] + resourceError[10]);
              v17 = (float)((float)(resourceError[11] * (float)0.0) + resourceError[13]);
              v6 = (float)(resourceError[13] + resourceError[11]);
            }
            v22 = v14->verts;
            v22->st.x = v16;
            v22->st.y = v6;
            v23 = v14->verts;
            v23[1].st.x = v15;
            v23[1].st.y = v6;
            v24 = v14->verts;
            v24[2].st.y = v17;
            v24[2].st.x = v15;
            v25 = v14->verts;
            v25[3].st.x = v16;
            v25[3].st.y = v17;
            if ( v7 != 0 )
            {
              v14->generateNormals = true;
              idTriangles::DeriveTangents(this: v14);
              v14 = tri_4;
            }
            else
            {
              v26 = 0;
              for ( i = 4; i != 0; --i )
              {
                v14->verts[v26].color[0] = -1;
                v14->verts[v26].color[1] = -1;
                v14->verts[v26].color[2] = -1;
                v14->verts[v26++].color[3] = -1;
              }
            }
            idTriangles::UpdateVertexBuffer(this: v14);
            v10 = tri_4;
          }
          v30.objectPtr = str;
          v29.objectPtr = v10;
          GL_DrawElements(prog: &v30, tri: &v29, extraState: 0xC40000000000uLL, skipDetailTriangles: v9);
          idParmState::VirtualRollbackParmBlock(
            this: renderThreadParmState,
            localParmBlock: &str->parmBlock,
            parmBlock: &str->parmBlock);
          p_nextOnHashChain = (idTriangles *)&v3[2].nextOnHashChain;
          idParmState::VirtualRollbackParmBlock(
            this: renderThreadParmState,
            localParmBlock: (const idParmBlock *)&v3[2].nextOnHashChain,
            parmBlock: (const idParmBlock *)&v3[2].nextOnHashChain);
          GL_State(stateBits: 0x400000000000uLL, forceGlState: v28);
          (*p_renderViewObject)->r.skipPostProcess = true;
        }
      }
    }
  }
}


// ========================================================================
// __unwind$240369
// EA  : 0x8296B8C0
// RVA : 0x0096B8C0
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_240369()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 272 + 88), tag: TAG_DEBUG);
}


// ========================================================================
// ?BuildToolViewList@idRender@@AAAAAV?$idList@UdrawSurf_t@@$02@@XZ
// EA  : 0x8296BE38
// RVA : 0x0096BE38
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

idList<drawSurf_t,3> *__fastcall idRender::BuildToolViewList(idRender *this)
{
  idList<idRenderModelSurface,62> *p_surfaces; // r29
  __int64 v4; // r26
  int *p_numViewWorldSurfaces; // r28
  int v6; // r31
  __int16 *p_numSurfs; // r30
  int v8; // r21
  int numViewModels; // r10
  const idRenderModelCommitted **viewModels; // r23
  int valueInteger; // r9
  const idRenderModelCommitted *v12; // r31
  int v13; // r29
  int num; // r28
  int v15; // r30
  const idRenderModelSurface *v16; // r10
  idTriangles *geometry; // r11
  const idMaterial *material; // r11
  double v19; // fp0
  drawSurf_t v20; // [sp+50h] [-90h] BYREF

  if ( viewListInitialized )
    return &viewList;
  p_surfaces = &this->worldSpace.surfaces;
  idList<idRenderModelSurface,62>::SetNum(
    this: (idList<idRenderModelSurface,85> *)&this->worldSpace.surfaces,
    newNum: 0);
  LODWORD(v4) = 0;
  p_numViewWorldSurfaces = &this->numViewWorldSurfaces;
  v6 = 0;
  if ( this->numViewWorldSurfaces > 0 )
  {
    p_numSurfs = &this->viewWorldAreas[0x1FFF].numSurfs;
    do
    {
      p_numSurfs += 2;
      idList<idRenderModelSurface,62>::Append(
        this: (idList<idRenderModelSurface,85> *)p_surfaces,
        obj: *(const idRenderModelSurface **)p_numSurfs);
      ++v6;
    }
    while ( v6 < *p_numViewWorldSurfaces );
  }
  viewListInitialized = true;
  if ( viewList.listStatic == 0 || viewList.listStatic == 2 )
  {
    if ( viewList.list != nullptr )
      idMem::Free(this: &mem, ptr: viewList.list, align: ALIGN_16);
    viewList.list = nullptr;
    viewList.size = 0;
  }
  viewList.num = 0;
  v8 = 0;
  numViewModels = renderState.numViewModels;
  if ( renderState.numViewModels > 0 )
  {
    viewModels = renderState.viewModels;
    HIDWORD(v4) = &joystick.joyAxis[0][2];
    valueInteger = r_singleSurface.valueInteger;
    do
    {
      v12 = *viewModels;
      v13 = 0;
      num = (*viewModels)->surfaces.num;
      if ( num > 0 )
      {
        v15 = 0;
        do
        {
          v16 = &v12->surfaces.list[v15];
          if ( valueInteger < 0 || v13 == valueInteger )
          {
            geometry = v16->geometry;
            if ( geometry != nullptr
              && geometry->numIndexes != 0
              && (geometry->vertexBuffer.size & 0x7FFFFFFF) != 0
              && (geometry->indexBuffer.size & 0x7FFFFFFF) != 0 )
            {
              material = v16->material;
              if ( v16->material != nullptr )
              {
                v19 = material->stageSort[6];
                *(_QWORD *)&v20.sort = v4;
                v20.prog = nullptr;
                v20.model = v12;
                v20.material = material;
                v20.modelSurface = v16;
                if ( v19 == 0.0 )
                  v19 = renderThreadParmState->values[rp->sortCoverage->parmIndex].value[0];
                v20.sort = v19;
                idList<idVerletChain::constraint_t,5>::Append(this: &viewList, obj: &v20);
                valueInteger = r_singleSurface.valueInteger;
              }
            }
          }
          ++v13;
          ++v15;
        }
        while ( v13 < num );
        numViewModels = renderState.numViewModels;
      }
      ++v8;
      ++viewModels;
    }
    while ( v8 < numViewModels );
  }
  return &viewList;
}


// ========================================================================
// ?ShowTris@idRender@@AAAXXZ
// EA  : 0x8296C068
// RVA : 0x0096C068
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowTris(idRender *this)
{
  idList<drawSurf_t,3> *v2; // r28
  bool v3; // r5
  int v4; // r31
  int v5; // r30
  drawSurf_t *v6; // r29
  bool v7; // r7
  bool v8; // r3
  int v9; // r27
  unsigned int v10; // r11
  int v11; // r29
  int v12; // r31
  unsigned int v13; // r27
  drawSurf_t *v14; // r30
  unsigned __int64 v15; // r6
  bool v16; // r7
  bool v17; // r5
  bool v18; // r3
  idODSObject<idDeclRenderProg> v19; // [sp+50h] [-80h] BYREF
  idODSObject<idRenderModelSurface> v20; // [sp+54h] [-7Ch] BYREF
  idODSObject<idDeclRenderProg> v21; // [sp+58h] [-78h] BYREF
  idODSObject<idRenderModelSurface> v22; // [sp+5Ch] [-74h] BYREF

  if ( r_showTris.valueInteger != 0 )
  {
    v2 = idRender::BuildToolViewList(this);
    GL_State(stateBits: 0x400000000000uLL, forceGlState: v3);
    if ( r_showTris.valueInteger < 0 )
    {
      idDeclRenderParm::Set(this: rp->Color, x: 0.5, y: 0.5, z: 0.5, w: 1.0);
      v4 = 0;
      if ( v2->num > 0 )
      {
        v5 = 0;
        do
        {
          v6 = &v2->list[v5];
          idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v6->model->mvpMatrix);
          v20.objectPtr = v6->modelSurface;
          v19.objectPtr = tr.progColorParmOnly;
          GL_DrawElements(prog: &v19, surf: &v20, extraState: 0x8000140000000000uLL, skipDetailTriangles: v7);
          ++v4;
          ++v5;
        }
        while ( v4 < v2->num );
      }
    }
    idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
    v9 = 0;
    v10 = abs32(r_showTris.valueInteger) - 1;
    if ( v10 <= 3 )
    {
      if ( v10 == 1 )
      {
        v9 = 19520;
      }
      else if ( v10 == 2 )
      {
        v9 = 52288;
      }
      else if ( v10 != 0 )
      {
        v9 = 7276;
        GL_PolygonOffset(scale: -1.0, bias: -2.0, fill: v8);
        if ( (_S14_5 & 1) == 0 )
          _S14_5 |= 1u;
        if ( (r_showDrawColor.flags & 0x20000) != 0 )
        {
          if ( sscanf(
                 string: r_showDrawColor.valueString.data,
                 format: "%f %f %f %f",
                 &draw_color,
                 &draw_color.y,
                 &draw_color.z,
                 &draw_color.w) != 4 )
          {
            draw_color.x = 0.0;
            draw_color.y = 0.0;
            draw_color.z = 0.0;
            draw_color.w = 0.0;
          }
          r_showDrawColor.flags &= ~0x20000u;
        }
        idDeclRenderParm::Set(this: rp->Color, plane: (const idPlane *)&draw_color);
      }
      else
      {
        v9 = 7232;
        GL_PolygonOffset(scale: -1.0, bias: -2.0, fill: v8);
      }
    }
    v11 = 0;
    if ( v2->num > 0 )
    {
      v12 = 0;
      v13 = v9 | 0x80000000;
      do
      {
        v14 = &v2->list[v12];
        idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v14->model->mvpMatrix);
        LODWORD(v15) = 0;
        HIDWORD(v15) = v13;
        v22.objectPtr = v14->modelSurface;
        v21.objectPtr = tr.progColorParmOnly;
        GL_DrawElements(prog: &v21, surf: &v22, extraState: v15, skipDetailTriangles: v16);
        ++v11;
        ++v12;
      }
      while ( v11 < v2->num );
    }
    idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
    GL_State(stateBits: 0x400000000000uLL, forceGlState: v17);
    GL_PolygonOffset(scale: 0.0, bias: 0.0, fill: v18);
    this->renderViewObject->r.skipPostProcess = true;
  }
}


// ========================================================================
// ?ShowTwoSided@idRender@@AAAXXZ
// EA  : 0x8296C358
// RVA : 0x0096C358
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowTwoSided(idRender *this)
{
  idList<drawSurf_t,3> *v2; // r30
  int v3; // r26
  int v4; // r29
  drawSurf_t *v5; // r31
  bool v6; // r7
  bool v7; // r5
  bool v8; // r3
  idODSObject<idDeclRenderProg> v9; // [sp+50h] [-60h] BYREF
  idODSObject<idRenderModelSurface> v10; // [sp+54h] [-5Ch] BYREF

  if ( r_showTwoSided.valueInteger != 0 )
  {
    idImageManager::BindNull(this: globalImages);
    idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 0.0, z: 0.0, w: 1.0);
    v2 = idRender::BuildToolViewList(this);
    v3 = 0;
    if ( v2->num > 0 )
    {
      v4 = 0;
      do
      {
        v5 = &v2->list[v4];
        if ( (*((_BYTE *)v5->material + 72) & 0x40) != 0 )
        {
          idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v5->model->mvpMatrix);
          v10.objectPtr = v5->modelSurface;
          v9.objectPtr = tr.progColorParmOnly;
          GL_DrawElements(prog: &v9, surf: &v10, extraState: 0x8000C80000000000uLL, skipDetailTriangles: v6);
        }
        ++v3;
        ++v4;
      }
      while ( v3 < v2->num );
    }
    idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
    GL_State(stateBits: 0x400000000000uLL, forceGlState: v7);
    GL_PolygonOffset(scale: 0.0, bias: 0.0, fill: v8);
    this->renderViewObject->r.skipPostProcess = true;
  }
}


// ========================================================================
// ?ShowBlendedSurfaces@idRender@@AAAXXZ
// EA  : 0x8296C4B8
// RVA : 0x0096C4B8
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowBlendedSurfaces(idRender *this)
{
  double sortLight; // fp30
  double sortBackground; // fp31
  idList<drawSurf_t,3> *v4; // r28
  int v5; // r25
  int v6; // r26
  char v7; // r9
  int v8; // r11
  drawSurf_t *v9; // r31
  float *v10; // r10
  const idRenderModelSurface *modelSurface; // r8
  double v12; // fp12
  double v13; // fp11
  double v14; // fp0
  bool v15; // r7
  bool v16; // r7
  bool v17; // r5
  bool v18; // r3
  idODSObject<idDeclRenderProg> v19; // [sp+50h] [-90h] BYREF
  idODSObject<idRenderModelSurface> v20; // [sp+54h] [-8Ch] BYREF
  idODSObject<idDeclRenderProg> v21; // [sp+58h] [-88h] BYREF
  idODSObject<idRenderModelSurface> v22; // [sp+5Ch] [-84h] BYREF
  float v23[14]; // [sp+60h] [-80h] BYREF

  if ( r_showBlendedSurfaces.valueInteger != 0 )
  {
    sortLight = 1.0e30;
    sortBackground = this->settings.sortBackground;
    if ( r_showBlendedSurfaces.valueInteger != 1 )
    {
      switch ( r_showBlendedSurfaces.valueInteger )
      {
        case 2:
          sortLight = this->settings.sortLight;
          break;
        case 3:
          sortBackground = this->settings.sortLight;
          sortLight = this->settings.sortPerturber;
          break;
        case 4:
          sortLight = this->settings.sortEmit;
          break;
        case 5:
          sortBackground = this->settings.sortEmit;
          sortLight = this->settings.sortLight;
          break;
        case 6:
          sortBackground = this->settings.sortLight;
          sortLight = this->settings.sortDecal;
          break;
        case 7:
          sortBackground = this->settings.sortDecal;
          sortLight = this->settings.sortTransSort;
          break;
        case 8:
          sortBackground = this->settings.sortTransSort;
          sortLight = this->settings.sortWater;
          break;
        case 9:
          sortBackground = this->settings.sortWater;
          sortLight = (float)(this->settings.sortWater + (float)50.0);
          break;
        default:
          break;
      }
    }
    idImageManager::BindNull(this: globalImages);
    idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 0.0, z: 0.0, w: 1.0);
    v4 = idRender::BuildToolViewList(this);
    v5 = 0;
    if ( v4->num > 0 )
    {
      v6 = 0;
      do
      {
        v7 = 1;
        v8 = 0;
        v9 = &v4->list[v6];
        v10 = v23;
        modelSurface = v9->modelSurface;
        v23[0] = v9->sort;
        v12 = modelSurface->material->stageSort[4];
        v13 = modelSurface->material->stageSort[5];
        v23[1] = modelSurface->material->stageSort[6];
        v23[2] = v12;
        v23[3] = v13;
        while ( 1 )
        {
          v14 = *v10;
          if ( v14 >= sortBackground && v14 < sortLight )
            break;
          ++v8;
          ++v10;
          if ( v8 >= 4 )
            goto LABEL_27;
        }
        v7 = 0;
LABEL_27:
        if ( v7 == 0 )
        {
          idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v9->model->mvpMatrix);
          idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 0.0, z: 0.0, w: 1.0);
          v20.objectPtr = v9->modelSurface;
          v19.objectPtr = tr.progColorParmOnly;
          GL_DrawElements(prog: &v19, surf: &v20, extraState: 0x8000C04000000000uLL, skipDetailTriangles: v15);
          idDeclRenderParm::Set(this: rp->Color, x: 0.60000002, y: 0.60000002, z: 0.60000002, w: 1.0);
          v22.objectPtr = v9->modelSurface;
          v21.objectPtr = tr.progColorParmOnly;
          GL_DrawElements(prog: &v21, surf: &v22, extraState: 0x8000C84000000000uLL, skipDetailTriangles: v16);
        }
        ++v5;
        ++v6;
      }
      while ( v5 < v4->num );
    }
    idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
    GL_State(stateBits: 0x400000000000uLL, forceGlState: v17);
    GL_PolygonOffset(scale: 0.0, bias: 0.0, fill: v18);
    this->renderViewObject->r.skipPostProcess = true;
  }
}


// ========================================================================
// ?ShowBlendedSurfaceOverdraw@idRender@@AAAXXZ
// EA  : 0x8296C7F8
// RVA : 0x0096C7F8
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowBlendedSurfaceOverdraw(idRender *this)
{
  int v2; // r5
  int v3; // r26
  int num; // r7
  int v5; // r27
  idParmState *v6; // r9
  idAutoRenderParms *v7; // r10
  drawSurf_t *v8; // r11
  const idRenderModelSurface *modelSurface; // r8
  double sort; // fp0
  __int128 v11; // r6
  idRenderView **p_renderViewObject; // r28
  unsigned __int64 v13; // r6
  const idVec4 *v14; // r30
  int v15; // r29
  bfx::BinaryReplayLogOut *v16; // r3
  const idRenderModelSurface *v17; // [sp+50h] [-60h] BYREF
  idODSObject<idDeclRenderProg> v18; // [sp+54h] [-5Ch] BYREF

  if ( r_showBlendedSurfOverdraw.valueInteger != 0 )
  {
    idImageManager::BindNull(this: globalImages);
    GL_Clear(color: false, depth: false, stencil: true, stencilValue: 0, r: 0.0, g: 0.0, b: 0.0, a: 0.0);
    idRender::SimpleWorldSetup(this);
    idRender::BuildToolViewList(this);
    v3 = 0;
    num = viewList.num;
    if ( viewList.num > 0 )
    {
      v5 = 0;
      v6 = renderThreadParmState;
      v7 = rp;
      do
      {
        v8 = &viewList.list[v5];
        if ( viewList.list[v5].material != nullptr )
        {
          modelSurface = v8->modelSurface;
          if ( modelSurface != nullptr )
          {
            sort = v8->sort;
            v2 = v7->sortLight->parmIndex + 3;
            if ( sort > *((float *)&v6->renderParmVersion + 4 * v2) )
            {
              v2 = 16 * (v7->sortPerturber->parmIndex + 3);
              if ( sort < *(float *)((char *)&v6->renderParmVersion + v2) )
              {
                *((_QWORD *)&v11 + 1) = 0x8000600000000000uLL;
                DWORD1(v11) = &v17;
                *(_QWORD *)((char *)&v11 + 4) <<= 32;
                v18.objectPtr = tr.progColorOnly;
                v17 = modelSurface;
                DWORD2(v11) |= 0x83C0u;
                GL_DrawElements(
                  prog: &v18,
                  surf: (const idODSObject<idRenderModelSurface> *)DWORD1(v11),
                  extraState: v11,
                  skipDetailTriangles: num);
                num = viewList.num;
                v7 = rp;
                v6 = renderThreadParmState;
              }
            }
          }
        }
        ++v3;
        ++v5;
      }
      while ( v3 < num );
    }
    GL_State(stateBits: 0x400000000000uLL, forceGlState: v2);
    if ( (_S17_0 & 1) == 0 )
    {
      colors_2[0].x = 0.0;
      colors_2[0].y = 0.0;
      colors_2[0].z = 0.0;
      colors_2[0].w = 1.0;
      colors_2[1].x = 0.0;
      colors_2[1].z = 0.27000001;
      colors_2[2].z = 0.60000002;
      _S17_0 |= 1u;
      colors_2[1].y = 0.0;
      colors_2[1].w = 1.0;
      colors_2[2].x = 0.0;
      colors_2[2].y = 0.0;
      colors_2[2].w = 1.0;
      colors_2[3].x = 0.1;
      colors_2[3].y = 0.0;
      colors_2[3].z = 0.68000001;
      colors_2[3].w = 1.0;
      colors_2[4].x = 0.41999999;
      colors_2[4].y = 0.0;
      colors_2[4].z = 0.47;
      colors_2[4].w = 1.0;
      colors_2[5].x = 0.80000001;
      colors_2[5].y = 0.0;
      colors_2[5].z = 0.17;
      colors_2[5].w = 1.0;
      colors_2[6].x = 1.0;
      colors_2[6].y = 0.039999999;
      colors_2[6].z = 0.0;
      colors_2[6].w = 1.0;
      colors_2[7].x = 1.0;
      colors_2[7].y = 0.36000001;
      colors_2[7].z = 0.0;
      colors_2[7].w = 1.0;
      colors_2[8].x = 1.0;
      colors_2[8].y = 0.76999998;
      colors_2[8].z = 0.0;
      colors_2[8].w = 1.0;
      colors_2[9].x = 1.0;
      colors_2[9].y = 1.0;
      colors_2[9].z = 0.12;
      colors_2[9].w = 1.0;
      colors_2[10].x = 1.0;
      colors_2[10].y = 1.0;
      colors_2[10].z = 1.0;
      colors_2[10].w = 1.0;
    }
    p_renderViewObject = &this->renderViewObject;
    GL_Viewport(x: 0, y: 0, w: this->renderViewObject->renderWidth, h: this->renderViewObject->renderHeight);
    GL_Scissor(x: 0, y: 0, w: (*p_renderViewObject)->renderWidth, h: (*p_renderViewObject)->renderHeight);
    GL_Clear(color: true, depth: false, stencil: false, stencilValue: 0, r: 1.0, g: 1.0, b: 1.0, a: 1.0);
    v14 = colors_2;
    v15 = 0;
    do
    {
      HIDWORD(v13) = -268385185;
      idRender::PolygonClear(this, vertColor: v14++, state: v13);
      ++v15;
    }
    while ( (int)v14 < (int)&colors_2[10] );
    if ( r_showTransSortOverdraw.valueInteger >= 2 )
      idPhysics_StaticMulti::UpdateTime(this: v16);
    GL_State(stateBits: 0x400000000000uLL, forceGlState: SBYTE3(v13));
    (*p_renderViewObject)->r.skipPostProcess = true;
  }
}


// ========================================================================
// ?ShowTrace@idRender@@AAAXXZ
// EA  : 0x8296CB68
// RVA : 0x0096CB68
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowTrace(idRender *this)
{
  double v2; // fp30
  idRenderView **p_renderViewObject; // r22
  idRenderView *renderViewObject; // r10
  float x; // r7
  double v6; // fp10
  double v7; // fp9
  float y; // r9
  double v9; // fp8
  double v10; // fp25
  double v11; // fp29
  double v12; // fp27
  double v13; // fp26
  double v14; // fp28
  double v15; // fp24
  idList<drawSurf_t,3> *v16; // r25
  int v17; // r23
  int v18; // r24
  drawSurf_t *v19; // r30
  idTriangles *geometry; // r31
  float *model; // r11
  float *v22; // r11
  double v23; // fp7
  double v24; // fp6
  double v25; // fp5
  double v26; // fp0
  double v27; // fp1
  bool v28; // r7
  unsigned int v29; // r7
  unsigned __int64 v30; // r6
  bool v31; // r7
  unsigned int v32; // r7
  unsigned __int64 v33; // r6
  unsigned int v34; // r7
  unsigned __int64 v35; // r6
  bool v36; // r5
  idVec3 v37; // [sp+50h] [-160h] BYREF
  float v38; // [sp+60h] [-150h]
  float v39; // [sp+64h] [-14Ch]
  float z; // [sp+68h] [-148h]
  idODSObject<idDeclRenderProg> v41; // [sp+6Ch] [-144h] BYREF
  idODSObject<idTriangles> v42; // [sp+70h] [-140h] BYREF
  idVec3 v43[2]; // [sp+78h] [-138h] BYREF
  idBounds v44; // [sp+90h] [-120h] BYREF
  idBounds v45; // [sp+B0h] [-100h] BYREF
  idTriangles v46; // [sp+D0h] [-E0h] BYREF

  if ( r_showTrace.valueInteger != 0 )
  {
    idImageManager::BindNull(this: globalImages);
    if ( r_showTrace.valueInteger == 2 )
      v2 = 5.0;
    else
      v2 = 0.0;
    p_renderViewObject = &this->renderViewObject;
    renderViewObject = this->renderViewObject;
    x = renderViewObject->r.vieworg.x;
    v6 = (float)(renderViewObject->r.viewaxis.mat[0].x * (float)4000.0);
    v7 = (float)(renderViewObject->r.viewaxis.mat[0].y * (float)4000.0);
    y = renderViewObject->r.vieworg.y;
    v9 = (float)(renderViewObject->r.viewaxis.mat[0].z * (float)4000.0);
    z = renderViewObject->r.vieworg.z;
    v10 = z;
    v38 = x;
    v11 = x;
    v39 = y;
    v12 = y;
    v13 = (float)(y + (float)v7);
    v14 = (float)(x + (float)v6);
    v15 = (float)(z + (float)v9);
    v16 = idRender::BuildToolViewList(this);
    v17 = 0;
    if ( v16->num > 0 )
    {
      v18 = 0;
      do
      {
        v19 = &v16->list[v18];
        geometry = v19->modelSurface->geometry;
        if ( geometry != nullptr && geometry->verts != nullptr )
        {
          model = (float *)v19->model;
          v37.x = (float)((float)(model[298] * (float)v11)
                        + (float)((float)(model[299] * (float)v12) + (float)(model[300] * (float)v10)))
                + model[301];
          v37.y = (float)((float)(model[302] * (float)v11)
                        + (float)((float)(model[303] * (float)v12) + (float)(model[304] * (float)v10)))
                + model[305];
          v37.z = (float)((float)(model[306] * (float)v11)
                        + (float)((float)(model[307] * (float)v12) + (float)(model[308] * (float)v10)))
                + model[309];
          v22 = (float *)v19->model;
          v43[0].x = (float)((float)((float)v14 * v22[298])
                           + (float)((float)(v22[300] * (float)v15) + (float)(v22[299] * (float)v13)))
                   + v22[301];
          v43[0].y = (float)((float)(v22[302] * (float)v14)
                           + (float)((float)(v22[304] * (float)v15) + (float)(v22[303] * (float)v13)))
                   + v22[305];
          v43[0].z = (float)((float)(v22[306] * (float)v14)
                           + (float)((float)(v22[308] * (float)v15) + (float)(v22[307] * (float)v13)))
                   + v22[309];
          v23 = geometry->bounds.b[0].x;
          v24 = geometry->bounds.b[0].y;
          v25 = geometry->bounds.b[0].z;
          v26 = (float)(geometry->bounds.b[1].z + (float)v2);
          v27 = (float)(geometry->bounds.b[1].x + (float)v2);
          v45.b[1].y = geometry->bounds.b[1].y + (float)v2;
          v45.b[1].x = v27;
          v45.b[1].z = v26;
          v45.b[0].x = (float)v23 - (float)v2;
          v45.b[0].y = (float)v24 - (float)v2;
          v45.b[0].z = (float)v25 - (float)v2;
          if ( idBounds::LineIntersection(this: &v45, start: &v37, end: v43) )
          {
            idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v19->model->mvpMatrix);
            idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 0.0, z: 0.0, w: 0.25);
            v41.objectPtr = tr.progColorParmOnly;
            v42.objectPtr = geometry;
            GL_DrawElements(prog: &v41, tri: &v42, extraState: 0x8000002C00000000uLL, skipDetailTriangles: v28);
            idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
            idDeclRenderProg::BindForImmediate(this: tr.progColorParmOnly, a2: -2147467264, extraState: v30, a4: v29);
            R_DrawBounds(bounds: &geometry->bounds);
            if ( v2 != 0.0 )
            {
              idDeclRenderParm::Set(this: rp->Color, x: 0.5, y: 0.5, z: 1.0, w: 1.0);
              idDeclRenderProg::BindForImmediate(this: tr.progColorParmOnly, a2: -2147467264, extraState: v33, a4: v32);
              idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)geometry);
            }
            idTriangles::TriangleTrace(
              this: &v46,
              result: (localTrace_t *)geometry,
              start: &v37,
              end: v43,
              radius: v2,
              twoSided: v31);
            if ( v46.bounds.b[0].x < 1.0 )
            {
              idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
              idDeclRenderProg::BindForImmediate(this: tr.progColorParmOnly, a2: -2147467264, extraState: v35, a4: v34);
              v44.b[1].x = v46.bounds.b[0].y + (float)1.0;
              v44.b[1].y = v46.bounds.b[0].z + (float)1.0;
              v44.b[1].z = v46.bounds.b[1].x + (float)1.0;
              v44.b[0].x = v46.bounds.b[0].y - (float)1.0;
              v44.b[0].y = v46.bounds.b[0].z - (float)1.0;
              v44.b[0].z = v46.bounds.b[1].x - (float)1.0;
              R_DrawBounds(bounds: &v44);
            }
          }
        }
        ++v17;
        ++v18;
      }
      while ( v17 < v16->num );
    }
    idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
    GL_State(stateBits: 0x400000000000uLL, forceGlState: v36);
    (*p_renderViewObject)->r.skipPostProcess = true;
  }
}


// ========================================================================
// ?ShowTangentSpace@idRender@@AAAXXZ
// EA  : 0x8296CF88
// RVA : 0x0096CF88
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowTangentSpace(idRender *this)
{
  const idDeclRenderProg *r; // r25
  idList<drawSurf_t,3> *v3; // r27
  int v4; // r26
  int v5; // r31
  drawSurf_t *v6; // r28
  double v7; // fp3
  double v8; // fp2
  double v9; // fp1
  bool v10; // r7
  bool v11; // r5
  idODSObject<idDeclRenderProg> v12; // [sp+50h] [-70h] BYREF
  idODSObject<idRenderModelSurface> v13; // [sp+54h] [-6Ch] BYREF

  if ( r_showTangentSpace.valueInteger != 0 )
  {
    idImageManager::BindNull(this: globalImages);
    r = (const idDeclRenderProg *)progshowTangentSpace.r;
    if ( progshowTangentSpace.r != nullptr )
    {
      v3 = idRender::BuildToolViewList(this);
      v4 = 0;
      if ( v3->num > 0 )
      {
        v5 = 0;
        do
        {
          v6 = &v3->list[v5];
          idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v6->model->mvpMatrix);
          if ( r_showTangentSpace.valueInteger == 1 )
          {
            v7 = 0.0;
            v8 = 0.5;
            v9 = 0.0;
          }
          else if ( r_showTangentSpace.valueInteger == 2 )
          {
            v7 = 0.5;
            v8 = 0.0;
            v9 = 0.0;
          }
          else
          {
            v7 = 0.0;
            v8 = 0.0;
            v9 = 0.5;
          }
          idDeclRenderParm::Set(this: rp->Color, x: v9, y: v8, z: v7, w: 0.0);
          idParmState::VirtualEvaluateParmBlock(
            this: renderThreadParmState,
            localParmBlock: &r->parmBlock,
            parmBlock: &r->parmBlock);
          v13.objectPtr = v6->modelSurface;
          v12.objectPtr = r;
          GL_DrawElements(prog: &v12, surf: &v13, extraState: 0, skipDetailTriangles: v10);
          idParmState::VirtualRollbackParmBlock(
            this: renderThreadParmState,
            localParmBlock: &r->parmBlock,
            parmBlock: &r->parmBlock);
          ++v4;
          ++v5;
        }
        while ( v4 < v3->num );
      }
      idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
      GL_State(stateBits: 0x400000000000uLL, forceGlState: v11);
      this->renderViewObject->r.skipPostProcess = true;
    }
  }
}


// ========================================================================
// ?ShowTextureSpace@idRender@@AAAXXZ
// EA  : 0x8296D120
// RVA : 0x0096D120
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowTextureSpace(idRender *this)
{
  const idDeclRenderProg *r; // r25
  idList<drawSurf_t,3> *v3; // r26
  bool v4; // r5
  int v5; // r27
  int v6; // r30
  drawSurf_t *v7; // r28
  bool v8; // r7
  idODSObject<idDeclRenderProg> v9; // [sp+50h] [-50h] BYREF
  idODSObject<idRenderModelSurface> v10; // [sp+54h] [-4Ch] BYREF

  if ( r_showTextureSpace.valueInteger != 0 )
  {
    r = (const idDeclRenderProg *)progShowTextureSpace.r;
    if ( progShowTextureSpace.r != nullptr )
    {
      idImageManager::BindNull(this: globalImages);
      v3 = idRender::BuildToolViewList(this);
      v5 = 0;
      if ( v3->num > 0 )
      {
        v6 = 0;
        do
        {
          v7 = &v3->list[v6];
          idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v7->model->mvpMatrix);
          idParmState::VirtualEvaluateParmBlock(
            this: renderThreadParmState,
            localParmBlock: &r->parmBlock,
            parmBlock: &r->parmBlock);
          v10.objectPtr = v7->modelSurface;
          v9.objectPtr = r;
          GL_DrawElements(prog: &v9, surf: &v10, extraState: 0, skipDetailTriangles: v8);
          idParmState::VirtualRollbackParmBlock(
            this: renderThreadParmState,
            localParmBlock: &r->parmBlock,
            parmBlock: &r->parmBlock);
          ++v5;
          ++v6;
        }
        while ( v5 < v3->num );
      }
      GL_State(stateBits: 0x400000000000uLL, forceGlState: v4);
      this->renderViewObject->r.skipPostProcess = true;
    }
  }
}


// ========================================================================
// ?ShowTextureDistortion@idRender@@AAAXXZ
// EA  : 0x8296D220
// RVA : 0x0096D220
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowTextureDistortion(idRender *this)
{
  const idDeclRenderProg *v2; // r25
  idList<drawSurf_t,3> *v3; // r26
  bool v4; // r5
  int v5; // r27
  int v6; // r30
  drawSurf_t *v7; // r28
  bool v8; // r7
  idODSObject<idDeclRenderProg> v9; // [sp+50h] [-50h] BYREF
  idODSObject<idRenderModelSurface> v10; // [sp+54h] [-4Ch] BYREF

  if ( r_showTextureDistortion.valueInteger != 0 )
  {
    v2 = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclRenderProg::resourceList,
                                     name: "showTextureDistortion",
                                     makeDefault: false);
    if ( v2 != nullptr )
    {
      idImageManager::BindNull(this: globalImages);
      v3 = idRender::BuildToolViewList(this);
      v5 = 0;
      if ( v3->num > 0 )
      {
        v6 = 0;
        do
        {
          v7 = &v3->list[v6];
          idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v7->model->mvpMatrix);
          idParmState::VirtualEvaluateParmBlock(
            this: renderThreadParmState,
            localParmBlock: &v2->parmBlock,
            parmBlock: &v2->parmBlock);
          v10.objectPtr = v7->modelSurface;
          v9.objectPtr = v2;
          GL_DrawElements(prog: &v9, surf: &v10, extraState: 0, skipDetailTriangles: v8);
          idParmState::VirtualRollbackParmBlock(
            this: renderThreadParmState,
            localParmBlock: &v2->parmBlock,
            parmBlock: &v2->parmBlock);
          ++v5;
          ++v6;
        }
        while ( v5 < v3->num );
      }
      GL_State(stateBits: 0x400000000000uLL, forceGlState: v4);
      this->renderViewObject->r.skipPostProcess = true;
    }
  }
}


// ========================================================================
// ?ShowVertexColor@idRender@@AAAXXZ
// EA  : 0x8296D330
// RVA : 0x0096D330
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowVertexColor(idRender *this)
{
  idList<drawSurf_t,3> *v2; // r28
  bool v3; // r5
  int v4; // r30
  int v5; // r29
  drawSurf_t *v6; // r31
  bool v7; // r7
  idODSObject<idDeclRenderProg> v8; // [sp+50h] [-50h] BYREF
  idODSObject<idRenderModelSurface> v9; // [sp+54h] [-4Ch] BYREF

  if ( r_showVertexColor.valueInteger != 0 )
  {
    idImageManager::BindNull(this: globalImages);
    v2 = idRender::BuildToolViewList(this);
    v4 = 0;
    if ( v2->num > 0 )
    {
      v5 = 0;
      do
      {
        v6 = &v2->list[v5];
        idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v6->model->mvpMatrix);
        v9.objectPtr = v6->modelSurface;
        v8.objectPtr = tr.progColorOnly;
        GL_DrawElements(prog: &v8, surf: &v9, extraState: 0x8000000000000000uLL, skipDetailTriangles: v7);
        ++v4;
        ++v5;
      }
      while ( v4 < v2->num );
    }
    GL_State(stateBits: 0x400000000000uLL, forceGlState: v3);
    this->renderViewObject->r.skipPostProcess = true;
  }
}


// ========================================================================
// ?ShowGlobalShadows@idRender@@AAAXXZ
// EA  : 0x8296D410
// RVA : 0x0096D410
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowGlobalShadows(idRender *this)
{
  idRender *v1; // r17
  idRenderWorldLocal **p_world; // r20
  const shadowMap_t *ShadowMap; // r3
  shadowMap_t *v4; // r30
  int width; // r25
  int v6; // r28
  unsigned __int16 *buffer; // r19
  bool v8; // r5
  int v9; // r15
  int v10; // r11
  int v11; // ctr
  idMem *v12; // r16
  idTriangles *v13; // r3
  idTriangles *v14; // r3
  idTriangles *v15; // r3
  __int64 v16; // r9
  long double v17; // fp2
  int i; // r29
  int v19; // r11
  int v20; // r8
  int v21; // r11
  int v22; // ctr
  int v23; // r10
  int v24; // r29
  int v25; // r27
  int v26; // r9
  int v27; // r9
  int v28; // r9
  int v29; // r9
  int v30; // r9
  int v31; // r9
  int v32; // r9
  int v33; // r9
  const idDeclRenderProg *progTextureOnly; // r30
  idTriangles *v35; // r3
  idDrawVert *verts; // r11
  __int64 v37; // r5
  double v38; // fp6
  bool v39; // r7
  bool v40; // r5
  idList<drawSurf_t,3> *v41; // r28
  int v42; // r24
  int v43; // r27
  _DWORD *p_sort; // r11
  int v45; // r4
  idRenderModelTransparency *transparencyRenderModel; // r11
  __int64 v47; // r9
  long double v48; // fp2
  int j; // r29
  int v50; // r11
  double v51; // fp0
  int v52; // r10
  unsigned __int16 *map; // r6
  double v54; // fp13
  double v55; // fp12
  double v56; // fp9
  double v57; // fp8
  int v58; // r7
  unsigned int v59; // r10
  __int64 v60; // r7
  int v61; // r29
  idColor *v62; // r11
  float r; // r10
  float g; // r8
  float b; // r14
  float a; // r11
  idRenderWorldLocal *v67; // r3
  double v68; // fp31
  double v69; // fp28
  double v70; // fp30
  idRenderWorldLocal *v71; // r3
  idList<drawSurf_t,3> *v72; // r17
  idCVar *v73; // r28
  int v74; // r16
  drawSurf_t *v75; // r25
  idRenderModelCommitted *model; // r29
  int v77; // r11
  bool v78; // r7
  idRenderModelCommitted *LightingPoint; // r3
  double v80; // fp31
  idRenderModelCommitted *v81; // r3
  double v82; // fp3
  double v83; // fp2
  double v84; // fp1
  idDeclRenderParm *Color; // r3
  idRenderModelCommitted *v86; // r3
  __int64 v87; // r9
  long double v88; // fp2
  int k; // r29
  int v90; // r11
  double z; // fp0
  const idDeclRenderProg *progColorParmOnly; // r28
  bool v93; // r7
  int v94; // [sp+8h] [-338h]
  __int64 v95; // [sp+60h] [-2E0h] BYREF
  idCVar *v96; // [sp+68h] [-2D8h]
  int v97; // [sp+6Ch] [-2D4h]
  char v98; // [sp+70h] [-2D0h]
  idVec4 v99; // [sp+80h] [-2C0h] BYREF
  __int64 v100; // [sp+90h] [-2B0h]
  __int64 v101; // [sp+98h] [-2A8h]
  int v103; // [sp+A4h] [-29Ch]
  idODSObject<idDeclRenderProg> v104; // [sp+A8h] [-298h] BYREF
  idVec4 v105; // [sp+B0h] [-290h] BYREF
  idODSObject<idRenderModelSurface> v106; // [sp+C0h] [-280h] BYREF
  idODSObject<idTriangles> v107; // [sp+C4h] [-27Ch] BYREF
  idODSObject<idDeclRenderProg> v108; // [sp+C8h] [-278h] BYREF
  idODSObject<idRenderModelSurface> v109; // [sp+CCh] [-274h] BYREF
  idODSObject<idDeclRenderProg> v110; // [sp+D0h] [-270h] BYREF
  idVec4 v111; // [sp+E0h] [-260h] BYREF
  idVec4 v112; // [sp+F0h] [-250h] BYREF
  idVec3 v113; // [sp+100h] [-240h] BYREF
  _DWORD v114[4]; // [sp+110h] [-230h] BYREF
  idTempArray<unsigned short> v115; // [sp+120h] [-220h] BYREF
  idVec4 v116; // [sp+130h] [-210h] BYREF
  idSphere v117; // [sp+140h] [-200h] BYREF
  idVec4 v118; // [sp+150h] [-1F0h] BYREF
  idVec4 v119; // [sp+160h] [-1E0h] BYREF
  idVec4 v120; // [sp+170h] [-1D0h] BYREF
  idRenderMatrix v121; // [sp+180h] [-1C0h] BYREF
  __int64 v122; // [sp+1C0h] [-180h]
  idImageOpts v123; // [sp+1D0h] [-170h] BYREF
  idRenderMatrix v124[2]; // [sp+220h] [-120h] BYREF

  v1 = this;
  v96 = &r_showGlobalShadows;
  if ( r_showGlobalShadows.valueInteger > 0 )
  {
    p_world = (idRenderWorldLocal **)&this->world;
    HIDWORD(v101) = &this->world;
    ShadowMap = idGlobalShadows::GetShadowMap(this: &this->world->globalShadows);
    v4 = (shadowMap_t *)ShadowMap;
    if ( ShadowMap != nullptr && ShadowMap->map != nullptr )
    {
      width = ShadowMap->width;
      v6 = width * width;
      idTempArray<unsigned short>::idTempArray<unsigned short>(this: &v115, num: width * width);
      buffer = v115.buffer;
      memset(Dst: v115.buffer, Val: 0xFFFF, Size: 2 * width * width);
      v9 = 0;
      if ( v4->map != nullptr && v6 > 0 )
      {
        v10 = 0;
        v11 = width * width;
        do
        {
          buffer[v10] = v4->map[v10];
          ++v10;
          --v11;
        }
        while ( v11 != 0 );
      }
      if ( globalShadowsImage == nullptr )
      {
        idImageOpts::idImageOpts(this: &v123);
        v123.width = width;
        v123.format = FMT_X16;
        v123.height = width;
        v123.filter = TF_NEAREST;
        v123.repeat = TR_CLAMP;
        globalShadowsImage = idImageManager::ScratchImage(
                               this: globalImages,
                               _name: "_globalShadowsImage",
                               imgOpts: &v123);
        idImage::SubImageUpload(
          this: globalShadowsImage,
          mipLevel: 0,
          destX: 0,
          destY: 0,
          destZ: D3DCUBEMAP_FACE_POSITIVE_X,
          width,
          height: width,
          pic: (char *)buffer,
          pixelPitch: v94);
      }
      v12 = &mem;
      HIDWORD(v100) = &mem;
      if ( tri_5 == nullptr )
      {
        v13 = (idTriangles *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x84u,
                               tag: TAG_DEBUG,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
        HIDWORD(v95) = v13;
        if ( v13 != nullptr )
          v14 = idTriangles::idTriangles(this: v13);
        else
          v14 = nullptr;
        tri_5 = v14;
        v14->numVerts = 4;
        v14->numIndexes = 6;
        idTriangles::AllocStaticTriSurfVerts(this: v14, numVerts: 4);
        idTriangles::AllocStaticTriSurfIndexes(this: tri_5, numIndexes: tri_5->numIndexes);
        v15 = tri_5;
        *tri_5->indexes = 3;
        v15->indexes[1] = 0;
        v15->indexes[2] = 2;
        v15->indexes[3] = 2;
        v15->indexes[4] = 0;
        v15->indexes[5] = 1;
        idTriangles::UpdateIndexBuffer(this: v15);
      }
      if ( r_showGlobalShadows.valueInteger == 1 )
      {
        idRenderMatrix::TransformPoint(this: &v4->mvp, in: &v1->renderViewObject->r.vieworg, out: &v105);
        for ( i = 0; i < 8; i += 4 )
        {
          LODWORD(v16) = v4->width;
          *(double *)&v17 = (float)((float)(*(float *)((char *)&v105.x + i) * (float)v16) + v4->coordinateBias);
          v100 = v16;
          v17 = floor(x: v17);
          v97 = (int)(float)*(double *)&v17;
          v19 = v97;
          *(_DWORD *)((char *)&v95 + i) = v97;
          if ( v19 >= 0 )
          {
            HIDWORD(v16) = v4->width - 1;
            if ( v19 >= SHIDWORD(v16) )
              *(_DWORD *)((char *)&v95 + i) = v4->width - 2;
          }
          else
          {
            *(_DWORD *)((char *)&v95 + i) = 0;
          }
        }
        v20 = v95;
        v21 = 0;
        v22 = 8;
        v23 = HIDWORD(v95);
        v24 = v95 + 6;
        v25 = v95 + 7;
        do
        {
          v26 = v4->width * v20 + v23 + v21;
          if ( v26 < v6 )
            buffer[v26] = 0;
          v27 = (v20 + 1) * v4->width + v23 + v21;
          if ( v27 < v6 )
            buffer[v27] = 0;
          v28 = (v20 + 2) * v4->width + v23 + v21;
          if ( v28 < v6 )
            buffer[v28] = 0;
          v29 = (v20 + 3) * v4->width + v23 + v21;
          if ( v29 < v6 )
            buffer[v29] = 0;
          v30 = (v20 + 4) * v4->width + v23 + v21;
          if ( v30 < v6 )
            buffer[v30] = 0;
          v31 = (v20 + 5) * v4->width + v23 + v21;
          if ( v31 < v6 )
            buffer[v31] = 0;
          v32 = v24 * v4->width + v23 + v21;
          if ( v32 < v6 )
            buffer[v32] = 0;
          v33 = v25 * v4->width + v23 + v21;
          if ( v33 < v6 )
            buffer[v33] = 0;
          ++v21;
          --v22;
        }
        while ( v22 != 0 );
        idImage::SubImageUpload(
          this: globalShadowsImage,
          mipLevel: 0,
          destX: 0,
          destY: 0,
          destZ: D3DCUBEMAP_FACE_POSITIVE_X,
          width,
          height: width,
          pic: (char *)buffer,
          pixelPitch: v94);
        v121.m[0] = 1.0;
        v121.m[1] = 0.0;
        v121.m[2] = 0.0;
        progTextureOnly = tr.progTextureOnly;
        v121.m[3] = 0.0;
        v121.m[4] = 0.0;
        v121.m[5] = 1.0;
        v121.m[6] = 0.0;
        v121.m[7] = 0.0;
        v121.m[8] = 0.0;
        v121.m[9] = 0.0;
        v121.m[10] = 1.0;
        v121.m[11] = 0.0;
        v121.m[12] = 0.0;
        v121.m[13] = 0.0;
        v121.m[14] = 0.0;
        v121.m[15] = 1.0;
        idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v121);
        idDeclRenderProg::SetTextureParm(this: progTextureOnly, i: 0, image: globalShadowsImage);
        v35 = tri_5;
        verts = tri_5->verts;
        HIDWORD(v95) = (char *)verts + 108;
        v37 = *(_QWORD *)&v1->renderViewObject->renderWidth;
        verts->st.x = 0.0;
        verts->st.y = 1.0;
        verts->xyz.y = -0.5;
        LODWORD(v95) = HIDWORD(v37);
        verts->xyz.z = 0.0;
        HIDWORD(v95) = verts + 3;
        v38 = (float)((float)((float)v37 / (float)__SPAIR64__(0x82000000, HIDWORD(v37))) * (float)0.5);
        verts->xyz.x = -v38;
        verts[1].st.x = 0.0;
        verts[1].st.y = 0.0;
        verts[1].xyz.x = -v38;
        verts[1].xyz.y = 0.5;
        verts[1].xyz.z = 0.0;
        verts[2].st.x = 1.0;
        verts[2].st.y = 0.0;
        verts[2].xyz.x = (float)((float)v37 / (float)__SPAIR64__(0x82000000, HIDWORD(v37))) * (float)0.5;
        verts[2].xyz.y = 0.5;
        verts[2].xyz.z = 0.0;
        verts[3].st.x = 1.0;
        verts[3].st.y = 1.0;
        verts[3].xyz.x = (float)((float)v37 / (float)__SPAIR64__(0x82000000, HIDWORD(v37))) * (float)0.5;
        verts[3].xyz.y = -0.5;
        verts[3].xyz.z = 0.0;
        idTriangles::UpdateVertexBuffer(this: v35);
        v110.objectPtr = progTextureOnly;
        v107.objectPtr = tri_5;
        GL_DrawElements(prog: &v110, tri: &v107, extraState: 0x8000C00000000000uLL, skipDetailTriangles: v39);
      }
      else if ( r_showGlobalShadows.valueInteger == 2 )
      {
        idRenderMatrix::Inverse(src: &v4->mvp, out: v124);
        v41 = idRender::BuildToolViewList(this: v1);
        v42 = 0;
        if ( v41->num > 0 )
        {
          v43 = 0;
          do
          {
            p_sort = (_DWORD *)&v41->list[v43].sort;
            if ( p_sort[4] != 0 && p_sort[3] != 0 )
            {
              v45 = p_sort[2];
              if ( v45 != 0 )
              {
                transparencyRenderModel = (*p_world)->transparencyRenderModel;
                if ( (transparencyRenderModel == nullptr
                   || (idRenderModelCommitted *)v45 != transparencyRenderModel->committed)
                  && (*(_BYTE *)(v45 + 140) & 0x20) == 0 )
                {
                  idRenderModelCommitted::GetLightingPoint(this: (idRenderModelCommitted *)&v113, result: (idVec3 *)v45);
                  idRenderMatrix::TransformPoint(this: &v4->mvp, in: &v113, out: &v112);
                  idRenderMatrix::TransformPoint(this: v124, in: &v112, out: &v105);
                  for ( j = 0; j < 8; j += 4 )
                  {
                    LODWORD(v47) = v4->width;
                    *(double *)&v48 = (float)((float)(*(float *)((char *)&v112.x + j) * (float)v47) + v4->coordinateBias);
                    v100 = v47;
                    v48 = floor(x: v48);
                    v97 = (int)(float)*(double *)&v48;
                    v50 = v97;
                    *(_DWORD *)((char *)&v95 + j) = v97;
                    if ( v50 >= 0 )
                    {
                      HIDWORD(v47) = v4->width - 1;
                      if ( v50 >= SHIDWORD(v47) )
                        *(_DWORD *)((char *)&v95 + j) = v4->width - 2;
                    }
                    else
                    {
                      *(_DWORD *)((char *)&v95 + j) = 0;
                    }
                  }
                  v51 = v4->mvp.m[12];
                  v52 = v4->width * v95;
                  map = v4->map;
                  v54 = v4->mvp.m[14];
                  v55 = v4->mvp.m[13];
                  v56 = (float)((float)(v112.z * (float)65535.0) + v4->depthBias);
                  v57 = v4->mvp.m[15];
                  v111 = v112;
                  v58 = v52 + HIDWORD(v95);
                  v97 = (int)v56;
                  v59 = (unsigned __int16)(int)v56;
                  LODWORD(v60) = map[v58];
                  HIDWORD(v60) = v60 - v59;
                  v101 = v60;
                  LOBYTE(v59) = ((unsigned int)v60 >= v59) - 1;
                  v61 = v59 & 1;
                  v98 = v59 & 1;
                  v111.z = (float)v60 * (float)0.000015259022;
                  v111.w = (float)((float)((float)v55 * v112.y)
                                 + (float)((float)((float)v54 * v111.z) + (float)((float)v51 * v112.x)))
                         + (float)v57;
                  idRenderMatrix::TransformPoint(this: v124, in: (const idVec3 *)&v111, out: &v99);
                  v62 = &idColor::colorRed;
                  v99.x = (float)((float)1.0 / v99.w) * v99.x;
                  v99.y = v99.y * (float)((float)1.0 / v99.w);
                  v99.z = v99.z * (float)((float)1.0 / v99.w);
                  v99.w = (float)((float)1.0 / v99.w) * v99.w;
                  if ( v61 == 0 )
                    v62 = &idColor::colorGreen;
                  r = v62->r;
                  g = v62->g;
                  b = v62->b;
                  a = v62->a;
                  v67 = *p_world;
                  *(float *)v114 = r;
                  *(float *)&v114[1] = g;
                  *(float *)&v114[2] = b;
                  *(float *)&v114[3] = a;
                  v68 = r;
                  v120.z = b;
                  v69 = a;
                  v70 = g;
                  v120.y = g;
                  v120.x = r;
                  v120.w = a;
                  idRenderWorldLocal::DebugPoint_renderThread(
                    this: v67,
                    color: &v120,
                    origin: &v113,
                    lifeTime: 0,
                    depthTest: false);
                  if ( v61 != 0 )
                  {
                    v118.x = v68;
                    v118.y = v70;
                    v118.z = b;
                    v118.w = v69;
                    idRenderWorldLocal::DebugLine_renderThread(
                      this: *p_world,
                      color: &v118,
                      start: &v113,
                      end: (const idVec3 *)&v99,
                      lifetime: 0,
                      depthTest: false);
                    v116.x = idColor::colorBlue.r;
                    v116.y = idColor::colorBlue.g;
                    v116.z = idColor::colorBlue.b;
                    v71 = *p_world;
                    v117.radius = 15.0;
                    v116.w = idColor::colorBlue.a;
                    v117.origin.x = v99.x;
                    v117.origin.y = v99.y;
                    v117.origin.z = v99.z;
                    idRenderWorldLocal::DebugSphere_renderThread(
                      this: v71,
                      color: &v116,
                      sphere: &v117,
                      sectors: 12,
                      lifetime: 0,
                      depthTest: true);
                  }
                }
              }
            }
            ++v42;
            ++v43;
          }
          while ( v42 < v41->num );
        }
      }
      else
      {
        GL_State(stateBits: 0x44000000000uLL, forceGlState: v8);
        idImageManager::BindNull(this: globalImages);
        v72 = idRender::BuildToolViewList(this: v1);
        if ( v72->num > 0 )
        {
          v73 = v96;
          v74 = 0;
          do
          {
            v75 = &v72->list[v74];
            if ( v75->material != nullptr && v75->modelSurface != nullptr )
            {
              model = (idRenderModelCommitted *)v75->model;
              if ( model != nullptr )
              {
                v77 = *(_DWORD *)(*(_DWORD *)HIDWORD(v101) + 107312);
                if ( v77 == 0 || model != *(idRenderModelCommitted **)(v77 + 88) )
                {
                  idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &model->mvpMatrix);
                  if ( v73->valueInteger > 2 && (*((_BYTE *)&model->r + 104) & 0x20) != 0 )
                  {
                    idDeclRenderParm::Set(
                      this: (idDeclRenderParm *)rpLightProjectionS_0.r,
                      plane: (const idPlane *)&v4->mvp);
                    idDeclRenderParm::Set(
                      this: (idDeclRenderParm *)rpLightProjectionT_0.r,
                      plane: (const idPlane *)&v4->mvp.m[4]);
                    idDeclRenderParm::Set(
                      this: (idDeclRenderParm *)rpLightProjectionR_0.r,
                      plane: (const idPlane *)&v4->mvp.m[8]);
                    idDeclRenderParm::Set(
                      this: (idDeclRenderParm *)rpLightProjectionQ_0.r,
                      plane: (const idPlane *)&v4->mvp.m[12]);
                    idParmState::VirtualEvaluateParmBlock(
                      this: renderThreadParmState,
                      localParmBlock: (const idParmBlock *)&prog_landUniqueShowGlobalShadows.r[2].resourceListPtr,
                      parmBlock: (const idParmBlock *)&prog_landUniqueShowGlobalShadows.r[2].resourceListPtr);
                    v109.objectPtr = v75->modelSurface;
                    v104.objectPtr = (const idDeclRenderProg *)prog_landUniqueShowGlobalShadows.r;
                    GL_DrawElements(prog: &v104, surf: &v109, extraState: 0, skipDetailTriangles: v78);
                    idParmState::VirtualRollbackParmBlock(
                      this: renderThreadParmState,
                      localParmBlock: (const idParmBlock *)&prog_landUniqueShowGlobalShadows.r[2].resourceListPtr,
                      parmBlock: (const idParmBlock *)&prog_landUniqueShowGlobalShadows.r[2].resourceListPtr);
                  }
                  else
                  {
                    LightingPoint = idRenderModelCommitted::GetLightingPoint(
                                      this: (idRenderModelCommitted *)v114,
                                      result: (idVec3 *)model);
                    v80 = shadowMap_t::ShadowSample(this: v4, worldPoint: (const idVec3 *)LightingPoint);
                    v119.x = (float)((float)(idColor::colorGreen.r - idColor::colorRed.r) * (float)v80)
                           + idColor::colorRed.r;
                    v119.w = idColor::colorRed.a
                           + (float)((float)(idColor::colorGreen.a - idColor::colorRed.a) * (float)v80);
                    v119.z = idColor::colorRed.b
                           + (float)((float)(idColor::colorGreen.b - idColor::colorRed.b) * (float)v80);
                    v119.y = idColor::colorRed.g
                           + (float)((float)(idColor::colorGreen.g - idColor::colorRed.g) * (float)v80);
                    v81 = idRenderModelCommitted::GetLightingPoint(
                            this: (idRenderModelCommitted *)&v111,
                            result: (idVec3 *)model);
                    idRenderWorldLocal::DebugPoint_renderThread(
                      this: *(idRenderWorldLocal **)HIDWORD(v101),
                      color: &v119,
                      origin: (const idVec3 *)v81,
                      lifeTime: 0,
                      depthTest: false);
                    if ( v73->valueInteger == 4 )
                    {
                      v82 = v80;
                      v83 = v80;
                      v84 = v80;
                      Color = rp->Color;
                    }
                    else
                    {
                      v86 = idRenderModelCommitted::GetLightingPoint(
                              this: (idRenderModelCommitted *)&v112,
                              result: (idVec3 *)model);
                      idRenderMatrix::TransformPoint(this: &v4->mvp, in: (const idVec3 *)v86, out: &v105);
                      for ( k = 0; k < 8; k += 4 )
                      {
                        LODWORD(v87) = v4->width;
                        *(double *)&v88 = (float)((float)(*(float *)((char *)&v105.x + k) * (float)v87)
                                                + v4->coordinateBias);
                        v95 = v87;
                        v88 = floor(x: v88);
                        v103 = (int)(float)*(double *)&v88;
                        v90 = v103;
                        *(_DWORD *)((char *)&v113.x + k) = v103;
                        if ( v90 >= 0 )
                        {
                          HIDWORD(v87) = v4->width - 1;
                          if ( v90 >= SHIDWORD(v87) )
                            *(_DWORD *)((char *)&v113.x + k) = v4->width - 2;
                        }
                        else
                        {
                          *(float *)((char *)&v113.x + k) = 0.0;
                        }
                      }
                      z = v105.z;
                      if ( v105.z >= 0.0 )
                      {
                        if ( z > 1.0 )
                          z = 1.0;
                      }
                      else
                      {
                        z = 0.0;
                      }
                      Color = rp->Color;
                      v103 = (int)(float)((float)(v4->depthBias * (float)z) * (float)65535.0);
                      LODWORD(v87) = (unsigned __int16)v103;
                      v122 = v87;
                      v84 = (float)((float)v87 * (float)0.000015259022);
                      v82 = v84;
                      v83 = v84;
                    }
                    idDeclRenderParm::Set(this: Color, x: v84, y: v83, z: v82, w: 1.0);
                    progColorParmOnly = tr.progColorParmOnly;
                    idParmState::VirtualEvaluateParmBlock(
                      this: renderThreadParmState,
                      localParmBlock: &tr.progColorParmOnly->parmBlock,
                      parmBlock: &tr.progColorParmOnly->parmBlock);
                    v106.objectPtr = v75->modelSurface;
                    v108.objectPtr = progColorParmOnly;
                    GL_DrawElements(
                      prog: &v108,
                      surf: &v106,
                      extraState: 0x8000044000000000uLL,
                      skipDetailTriangles: v93);
                    idParmState::VirtualRollbackParmBlock(
                      this: renderThreadParmState,
                      localParmBlock: &progColorParmOnly->parmBlock,
                      parmBlock: &progColorParmOnly->parmBlock);
                    v73 = v96;
                  }
                }
              }
            }
            ++v9;
            ++v74;
          }
          while ( v9 < v72->num );
        }
        idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
        v1 = this;
        v12 = (idMem *)HIDWORD(v100);
        buffer = v115.buffer;
      }
      GL_State(stateBits: 0x400000000000uLL, forceGlState: v40);
      v1->renderViewObject->r.skipPostProcess = true;
      if ( buffer != nullptr )
        idMem::Free(this: v12, ptr: buffer, align: ALIGN_16);
    }
  }
}


// ========================================================================
// __unwind$242648
// EA  : 0x8296E168
// RVA : 0x0096E168
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_242648()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 832 + 288));
}


// ========================================================================
// __unwind$242649
// EA  : 0x8296E190
// RVA : 0x0096E190
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_242649()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 832 + 96), tag: TAG_DEBUG);
}


// ========================================================================
// ?ShowAutosprite@idRender@@AAAXXZ
// EA  : 0x8296E1C0
// RVA : 0x0096E1C0
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowAutosprite(idRender *this)
{
  idList<drawSurf_t,3> *v2; // r26
  int v3; // r22
  int v4; // r25
  drawSurf_t *v5; // r29
  const idMaterial *material; // r11
  autospriteType_t materialAutospriteType; // r11
  const idDeclRenderProg *r; // r30
  double v9; // fp3
  bool v10; // r7
  bool v11; // r5
  idODSObject<idDeclRenderProg> v12; // [sp+50h] [-80h] BYREF
  idODSObject<idRenderModelSurface> v13; // [sp+54h] [-7Ch] BYREF

  if ( r_testAutosprites.valueInteger != 0 )
  {
    idImageManager::BindNull(this: globalImages);
    v2 = idRender::BuildToolViewList(this);
    v3 = 0;
    if ( v2->num > 0 )
    {
      v4 = 0;
      while ( 1 )
      {
        v5 = &v2->list[v4];
        material = v5->material;
        if ( material == nullptr )
          goto LABEL_12;
        materialAutospriteType = material->materialAutospriteType;
        if ( materialAutospriteType == AUTOSPRITE_NONE )
          goto LABEL_12;
        if ( materialAutospriteType == AUTOSPRITE_VIEW_ORIENTED )
          break;
        if ( materialAutospriteType == AUTOSPRITE_LONGEST_AXIS_ALIGNED )
        {
          r = (const idDeclRenderProg *)rp_progAutosprite2.r;
          v9 = 0.0;
LABEL_10:
          idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 0.0, z: v9, w: 1.0);
          if ( r != nullptr )
          {
            idParmState::SetInverseModelMatrix(
              this: renderThreadParmState,
              inverseModelMatrix: &v5->model->inverseModelMatrix);
            idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &v5->model->mvpMatrix);
            idParmState::VirtualEvaluateParmBlock(
              this: renderThreadParmState,
              localParmBlock: &r->parmBlock,
              parmBlock: &r->parmBlock);
            v13.objectPtr = v5->modelSurface;
            v12.objectPtr = r;
            GL_DrawElements(prog: &v12, surf: &v13, extraState: 0x480000000000uLL, skipDetailTriangles: v10);
            idParmState::VirtualRollbackParmBlock(
              this: renderThreadParmState,
              localParmBlock: &r->parmBlock,
              parmBlock: &r->parmBlock);
          }
        }
LABEL_12:
        ++v3;
        ++v4;
        if ( v3 >= v2->num )
          goto LABEL_13;
      }
      r = (const idDeclRenderProg *)rp_progAutosprite1.r;
      v9 = 1.0;
      goto LABEL_10;
    }
LABEL_13:
    idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
    GL_State(stateBits: 0x400000000000uLL, forceGlState: v11);
    this->renderViewObject->r.skipPostProcess = true;
  }
}


// ========================================================================
// ?ShowSurfaceInfo@idRender@@AAAXXZ
// EA  : 0x8296E548
// RVA : 0x0096E548
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowSurfaceInfo(idRender *this)
{
  idRenderView **p_renderViewObject; // r15
  idRenderView *renderViewObject; // r11
  double v4; // fp8
  double y; // fp3
  double v6; // fp28
  double v7; // fp30
  double v8; // fp29
  double v9; // fp25
  double v10; // fp27
  double v11; // fp26
  int v12; // r27
  int v13; // r28
  drawSurf_t *v14; // r30
  const idMaterial *material; // r11
  float *model; // r11
  float *v17; // r11
  localTrace_t *v18; // r3
  double x; // fp4
  int v20; // r4
  int v21; // r10
  int v22; // r7
  double v23; // fp3
  double z; // fp2
  double v25; // fp1
  double v26; // fp0
  double v27; // fp13
  int num; // r30
  idVehicleState **list; // r4
  idVehicleState **v30; // r14
  int v31; // r11
  int v32; // r27
  bool v33; // r3
  bool v34; // r7
  __int64 v35; // r8
  __int64 v36; // r6
  __int64 v37; // r10
  va *v38; // r3
  const char *v39; // r28
  __int64 v40; // r6
  __int64 v41; // r10
  __int64 v42; // r8
  int v43; // r8
  int v44; // r6
  va *v45; // r3
  int v46; // r10
  int v47; // r11
  int v48; // r23
  int v49; // r28
  unsigned int v50; // r7
  unsigned __int64 v51; // r6
  int numVerts; // r5
  idTriangles *v53; // r8
  idTriangles *v54; // r3
  idTriangles *v55; // r3
  idTriangles *v56; // r3
  int v57; // r30
  int v58; // r29
  unsigned int v59; // r3
  idDrawVert *v60; // r11
  __int64 v61; // r10
  float *p_renderTime; // r29
  double v63; // fp0
  double v64; // fp9
  double v65; // fp6
  double v66; // fp5
  double v67; // fp11
  double v68; // fp7
  double v69; // fp12
  double v70; // fp6
  float *p_x; // r10
  double v72; // fp3
  double v73; // fp10
  double v74; // fp9
  double v75; // fp5
  double v76; // fp1
  double v77; // fp1
  double v78; // fp6
  double v79; // fp7
  double v80; // fp5
  double v81; // fp4
  double v82; // fp2
  double v83; // fp9
  double v84; // fp3
  double v85; // fp8
  double v86; // fp8
  double v87; // fp9
  double v88; // fp5
  double v89; // fp4
  bool v90; // r7
  bool v91; // r5
  double v92; // fp10
  double v93; // fp9
  const idVec4 *v94; // r6
  const idVec4 *v95; // r6
  idTriangles *v96; // r26
  int v97; // r3
  __int64 v98; // r6
  __int64 v99; // r8
  __int64 v100; // r10
  va *v101; // r3
  double v102; // fp10
  double v103; // fp6
  const idVec4 *v104; // r6
  __int64 v105; // r8
  unsigned int v106; // r26
  unsigned int v107; // r25
  int v108; // r24
  int v109; // r23
  int v110; // r11
  __int64 v111; // r10
  int v112; // r22
  int v113; // r11
  int v114; // r10
  va *v115; // r3
  va *v116; // r25
  size_t i; // r26
  int v118; // r4
  int v119; // r11
  char *data; // r6
  double v121; // fp8
  double v122; // fp3
  bool v123; // r3
  double v124; // fp10
  float v125; // r10
  double v126; // fp8
  float v127; // r9
  double v128; // fp7
  double v129; // fp6
  double v130; // fp5
  double v131; // fp4
  float *v132; // r30
  idRenderWorldLocal *world; // r3
  double v134; // fp2
  double v135; // fp1
  double v136; // fp12
  double v139; // fp11
  double v140; // fp7
  double v141; // fp11
  double v142; // fp7
  double v143; // fp31
  double v144; // fp29
  double v145; // fp28
  __int64 v146; // r11
  float *v147; // r28
  int j; // r29
  double v149; // fp0
  double v150; // fp13
  double v151; // fp10
  double v152; // fp7
  double v153; // fp6
  idRenderWorldLocal *v154; // r3
  double v155; // fp9
  double v156; // fp8
  int v157; // [sp+8h] [-42C8h]
  int v158; // [sp+8h] [-42C8h]
  int v159; // [sp+8h] [-42C8h]
  int v160; // [sp+8h] [-42C8h]
  int v161; // [sp+Ch] [-42C4h]
  int v162; // [sp+Ch] [-42C4h]
  int v163; // [sp+Ch] [-42C4h]
  int v164; // [sp+Ch] [-42C4h]
  int v165; // [sp+10h] [-42C0h]
  int v166; // [sp+10h] [-42C0h]
  int v167; // [sp+10h] [-42C0h]
  int v168; // [sp+10h] [-42C0h]
  int v169; // [sp+14h] [-42BCh]
  int v170; // [sp+14h] [-42BCh]
  int v171; // [sp+14h] [-42BCh]
  int v172; // [sp+14h] [-42BCh]
  int v173; // [sp+18h] [-42B8h]
  int v174; // [sp+18h] [-42B8h]
  int v175; // [sp+18h] [-42B8h]
  int v176; // [sp+18h] [-42B8h]
  int v177; // [sp+1Ch] [-42B4h]
  int v178; // [sp+1Ch] [-42B4h]
  int v179; // [sp+1Ch] [-42B4h]
  int v180; // [sp+1Ch] [-42B4h]
  int v181; // [sp+50h] [-4280h]
  idVec3 v182; // [sp+58h] [-4278h] BYREF
  idODSObject<idTriangles> v183; // [sp+64h] [-426Ch] BYREF
  idList<idVehicleState *,5> v184; // [sp+70h] [-4260h] BYREF
  __int64 v185; // [sp+80h] [-4250h]
  float v186; // [sp+88h] [-4248h]
  idODSObject<idDeclRenderProg> v187; // [sp+8Ch] [-4244h] BYREF
  idODSObject<idRenderModelSurface> v188; // [sp+90h] [-4240h] BYREF
  idODSObject<idDeclRenderProg> v189; // [sp+94h] [-423Ch] BYREF
  idVec3 v190; // [sp+98h] [-4238h] BYREF
  idVec3 v191; // [sp+A8h] [-4228h] BYREF
  idVec3 v192; // [sp+B8h] [-4218h] BYREF
  idVec3 v193; // [sp+C8h] [-4208h] BYREF
  idVec3 v194; // [sp+D8h] [-41F8h] BYREF
  idVec3 v195; // [sp+E8h] [-41E8h] BYREF
  idVec3 v196; // [sp+F8h] [-41D8h] BYREF
  idVec3 v197; // [sp+108h] [-41C8h] BYREF
  idVec4 v198; // [sp+120h] [-41B0h] BYREF
  idStr v199; // [sp+130h] [-41A0h] BYREF
  traceContact_t v200; // [sp+150h] [-4180h] BYREF
  idStr v201; // [sp+180h] [-4150h] BYREF
  idStr v202; // [sp+1A0h] [-4130h] BYREF
  idTriangles v203[2]; // [sp+1C0h] [-4110h] BYREF
  va v204; // [sp+11F0h] [-30E0h] BYREF
  va v205; // [sp+21F0h] [-20E0h] BYREF
  va v206; // [sp+31F0h] [-10E0h] BYREF

  if ( r_showSurfaceInfo.valueInteger == 0 )
    return;
  p_renderViewObject = &this->renderViewObject;
  memset(&v184, 0, 14);
  renderViewObject = this->renderViewObject;
  *(_WORD *)&v184.memTag = 768;
  v4 = (float)(renderViewObject->r.viewaxis.mat[0].y * (float)16.0);
  y = renderViewObject->r.vieworg.y;
  v6 = (float)(renderViewObject->r.vieworg.x + (float)(renderViewObject->r.viewaxis.mat[0].x * (float)16.0));
  v7 = (float)(renderViewObject->r.vieworg.z + (float)(renderViewObject->r.viewaxis.mat[0].z * (float)16.0));
  v8 = (float)(renderViewObject->r.vieworg.y + (float)(renderViewObject->r.viewaxis.mat[0].y * (float)16.0));
  v9 = (float)((float)(renderViewObject->r.viewaxis.mat[0].x * (float)10000.0)
             + (float)(renderViewObject->r.vieworg.x + (float)(renderViewObject->r.viewaxis.mat[0].x * (float)16.0)));
  v10 = (float)((float)(renderViewObject->r.viewaxis.mat[0].z * (float)10000.0)
              + (float)(renderViewObject->r.vieworg.z + (float)(renderViewObject->r.viewaxis.mat[0].z * (float)16.0)));
  v183.objectPtr = (const idTriangles *)&renderViewObject->r.vieworg;
  v11 = (float)((float)(renderViewObject->r.viewaxis.mat[0].y * (float)10000.0) + (float)((float)y + (float)v4));
  v183.objectPtr = (const idTriangles *)&renderViewObject->r.viewaxis;
  idList<idThread *,58>::Clear(this: &v184);
  idList<idThread *,58>::Clear(this: &v184);
  idRender::BuildToolViewList(this);
  v12 = 0;
  if ( viewList.num > 0 )
  {
    v13 = 0;
    do
    {
      v14 = &viewList.list[v13];
      material = viewList.list[v13].material;
      if ( material != nullptr
        && v14->modelSurface != nullptr
        && (material->coverage != MC_INVISIBLE || r_showNoDrawSurfaceInfo.valueInteger != 0)
        && (*((_BYTE *)material + 73) & 0x40) == 0 )
      {
        model = (float *)v14->model;
        v191.x = (float)((float)((float)v6 * model[298])
                       + (float)((float)(model[299] * (float)v8) + (float)(model[300] * (float)v7)))
               + model[301];
        v191.y = (float)((float)(model[304] * (float)v7)
                       + (float)((float)(model[302] * (float)v6) + (float)(model[303] * (float)v8)))
               + model[305];
        v191.z = (float)((float)(model[308] * (float)v7)
                       + (float)((float)(model[306] * (float)v6) + (float)(model[307] * (float)v8)))
               + model[309];
        v17 = (float *)v14->model;
        v196.x = (float)((float)(v17[298] * (float)v9)
                       + (float)((float)(v17[299] * (float)v11) + (float)(v17[300] * (float)v10)))
               + v17[301];
        v196.y = (float)((float)(v17[304] * (float)v10)
                       + (float)((float)(v17[302] * (float)v9) + (float)(v17[303] * (float)v11)))
               + v17[305];
        v196.z = (float)((float)(v17[308] * (float)v10)
                       + (float)((float)(v17[306] * (float)v9) + (float)(v17[307] * (float)v11)))
               + v17[309];
        v18 = idTriangles::TriangleTrace(
                this: v203,
                result: (localTrace_t *)v14->modelSurface->geometry,
                start: &v191,
                end: &v196,
                radius: 1.0,
                twoSided: (bool)v14->modelSurface);
        x = v18->point.x;
        v20 = v18->indexes[0];
        v200.trace.fraction = v18->fraction;
        v21 = v18->indexes[1];
        v22 = v18->indexes[2];
        v23 = v18->point.y;
        v200.trace.jointIndex = v18->jointIndex;
        z = v18->point.z;
        v25 = v18->normal.x;
        v26 = v18->normal.y;
        v27 = v18->normal.z;
        v200.trace.point.x = x;
        v200.trace.point.y = v23;
        v200.trace.point.z = z;
        v200.trace.normal.x = v25;
        v200.trace.normal.y = v26;
        v200.trace.normal.z = v27;
        v200.trace.indexes[0] = v20;
        v200.trace.indexes[1] = v21;
        v200.trace.indexes[2] = v22;
        if ( v200.trace.fraction != 1.0 )
        {
          v200.surf = v14;
          idList<traceContact_t,3>::Append(this: (idList<traceContact_t,3> *)&v184, obj: &v200);
        }
      }
      ++v12;
      ++v13;
    }
    while ( v12 < viewList.num );
  }
  num = v184.num;
  if ( v184.num == 0 )
  {
    if ( v184.listStatic == 0 || v184.listStatic == 2 )
    {
      list = v184.list;
      if ( v184.list != nullptr )
        goto LABEL_67;
    }
    return;
  }
  v30 = v184.list;
  qsort(
    base: v184.list,
    num: v184.num,
    width: 0x30u,
    comp: (int (__fastcall *)(const void *, const void *))R_QsortContacts);
  if ( r_showSurfaceInfo.valueInteger - 1 < num )
  {
    if ( r_showSurfaceInfo.valueInteger - 1 < 0 )
    {
      v32 = (int)v30;
      goto LABEL_23;
    }
    v31 = 3 * r_showSurfaceInfo.valueInteger;
  }
  else
  {
    v31 = 3 * num;
  }
  v32 = (int)&v30[4 * v31 - 12];
LABEL_23:
  idImageManager::BindNull(this: globalImages);
  GL_PolygonOffset(scale: -1.0, bias: -2.0, fill: v33);
  GL_Scissor(
    x: (*p_renderViewObject)->scissorRect.x1,
    y: (*p_renderViewObject)->scissorRect.y1,
    w: (*p_renderViewObject)->scissorRect.x2 - (*p_renderViewObject)->scissorRect.x1 + 1,
    h: (*p_renderViewObject)->scissorRect.y2 - (*p_renderViewObject)->scissorRect.y1 + 1);
  idParmState::SetMVPMatrix(
    this: renderThreadParmState,
    mvp: (const idRenderMatrix *)(*(_DWORD *)(*(_DWORD *)(v32 + 44) + 8) + 1420));
  idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 0.0, z: 0.0, w: 1.0);
  v188.objectPtr = *(const idRenderModelSurface **)(*(_DWORD *)(v32 + 44) + 12);
  v189.objectPtr = tr.progColorParmOnly;
  GL_DrawElements(prog: &v189, surf: &v188, extraState: 0x8000480000000000uLL, skipDetailTriangles: v34);
  LODWORD(v35) = *(_DWORD *)(*(_DWORD *)(v32 + 44) + 8);
  HIDWORD(v35) = v35;
  LODWORD(v36) = *(_DWORD *)v35;
  HIDWORD(v36) = *(_DWORD *)(v35 + 8) >> 8;
  v38 = va::va(
          this: (va *)&v203[0].vsb.xyzScale.y,
          fmt: "%i: %s",
          a3: v36,
          a4: v35,
          a5: v37,
          a6: v157,
          a7: v161,
          a8: v165,
          a9: v169,
          a10: v173,
          a11: v177);
  idStr::idStr(this: &v202, text: v38);
  v39 = *(const char **)(*(_DWORD *)(*(_DWORD *)(v32 + 44) + 16) + 8);
  idCVar::SetString(this: &r_currentMaterial, newValue: v39, force: true);
  HIDWORD(v41) = *(_DWORD *)(v32 + 44);
  HIDWORD(v40) = -1;
  LODWORD(v41) = 0;
  LODWORD(v42) = *(_DWORD *)(HIDWORD(v41) + 8);
  v181 = *(_DWORD *)(v42 + 1028);
  if ( v181 > 0 )
  {
    HIDWORD(v41) = 0;
    while ( 1 )
    {
      v43 = *(_DWORD *)(v32 + 44);
      HIDWORD(v42) = *(_DWORD *)(v43 + 8);
      v44 = *(_DWORD *)(v43 + 12);
      LODWORD(v42) = *(_DWORD *)(HIDWORD(v42) + 1024);
      if ( v44 == (_DWORD)v42 + HIDWORD(v41) )
        break;
      LODWORD(v41) = v41 + 1;
      HIDWORD(v41) += 56;
      if ( (int)v41 >= v181 )
        goto LABEL_29;
    }
    HIDWORD(v40) = v41;
  }
LABEL_29:
  LODWORD(v40) = v39;
  v45 = va::va(
          this: &v205,
          fmt: "%i: %s",
          a3: v40,
          a4: v42,
          a5: v41,
          a6: v158,
          a7: v162,
          a8: v166,
          a9: v170,
          a10: v174,
          a11: v178);
  idStr::idStr(this: &v201, text: v45);
  v46 = 0;
  if ( *v202.data != 0 )
  {
    do
      ++v46;
    while ( v202.data[v46] != 0 );
  }
  v47 = 0;
  if ( *v201.data != 0 )
  {
    do
      ++v47;
    while ( v201.data[v47] != 0 );
  }
  v48 = v46;
  if ( v46 <= v47 )
    v48 = v47;
  v49 = v48;
  if ( v48 < 40 )
    v49 = 40;
  idParmState::SetModelMatrix(this: renderThreadParmState, modelMatrix: &this->worldSpace.modelMatrix);
  idParmState::SetInverseModelMatrix(
    this: renderThreadParmState,
    inverseModelMatrix: &this->worldSpace.inverseModelMatrix);
  idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &this->worldSpace.mvpMatrix);
  idDeclRenderParm::Set(this: rp->globalViewOrigin, vec: &(*p_renderViewObject)->r.vieworg);
  idDeclRenderProg::BindForImmediate(this: tr.progColorOnly, a2: 0, extraState: v51, a4: v50);
  v53 = tri_6;
  if ( tri_6 == nullptr )
  {
    v54 = (idTriangles *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x84u,
                           tag: TAG_TRIANGLES,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    v55 = v54 != nullptr ? idTriangles::idTriangles(this: v54) : nullptr;
    tri_6 = v55;
    v55->numVerts = 4;
    v55->numIndexes = 6;
    idTriangles::AllocStaticTriSurfVerts(this: v55, numVerts: 4);
    idTriangles::AllocStaticTriSurfIndexes(this: tri_6, numIndexes: tri_6->numIndexes);
    v56 = tri_6;
    *tri_6->indexes = 3;
    v56->indexes[1] = 0;
    v56->indexes[2] = 2;
    v56->indexes[3] = 2;
    v56->indexes[4] = 0;
    v56->indexes[5] = 1;
    idTriangles::UpdateIndexBuffer(this: v56);
    v53 = tri_6;
    v57 = 0;
    if ( tri_6->numVerts > 0 )
    {
      v58 = 0;
      do
      {
        v198.x = 0.25;
        v198.y = 0.25;
        v198.z = 0.25;
        v198.w = 1.0;
        v59 = idColor::PackColor(color: &v198);
        v53 = tri_6;
        ++v57;
        v60 = &tri_6->verts[v58++];
        v60->color[3] = HIBYTE(v59);
        v60->color[2] = BYTE1(v59);
        v60->color[1] = BYTE2(v59);
        v60->color[0] = v59;
        numVerts = v53->numVerts;
      }
      while ( v57 < numVerts );
    }
  }
  HIDWORD(v61) = 0x82000000;
  p_renderTime = (float *)&(*p_renderViewObject)->r.renderTime;
  if ( r_showRuler.valueInteger == 0 )
  {
    LODWORD(v61) = v48;
    v63 = (*p_renderViewObject)->r.viewaxis.mat[0].x;
    v64 = (*p_renderViewObject)->r.viewaxis.mat[0].z;
    v65 = (*p_renderViewObject)->r.vieworg.x;
    v66 = (*p_renderViewObject)->r.vieworg.z;
    v67 = (float)v61;
    v68 = (float)((*p_renderViewObject)->r.vieworg.y
                + (float)((float)((*p_renderViewObject)->r.viewaxis.mat[0].y * (float)__SPAIR64__(v48, v49))
                        * (float)16.0));
    v69 = (float)((*p_renderViewObject)->r.vieworg.x
                + (float)((float)((float)__SPAIR64__(v48, v49) * (*p_renderViewObject)->r.viewaxis.mat[0].x)
                        * (float)16.0));
    v182.y = (*p_renderViewObject)->r.vieworg.y
           + (float)((float)((*p_renderViewObject)->r.viewaxis.mat[0].y * (float)__SPAIR64__(v48, v49)) * (float)16.0);
    v182.x = (float)v65 + (float)((float)((float)__SPAIR64__(v48, v49) * (float)v63) * (float)16.0);
    v70 = (float)((float)v66 + (float)((float)((float)v64 * (float)__SPAIR64__(v48, v49)) * (float)16.0));
    v182.z = (float)v66 + (float)((float)((float)v64 * (float)__SPAIR64__(v48, v49)) * (float)16.0);
    v72 = p_renderTime[34];
    v73 = (float)(p_renderTime[31] * (float)v61);
    v74 = (float)(p_renderTime[30] * (float)v61);
    v75 = (float)((float)((float)v61 * p_renderTime[32]) * (float)-10.0);
    p_x = &v53->verts->xyz.x;
    v76 = (float)(p_renderTime[33] * (float)70.0);
    p_x[2] = (float)((float)v75 + (float)v70) + (float)(p_renderTime[35] * (float)70.0);
    p_x[1] = (float)((float)((float)v73 * (float)-10.0) + (float)v68) + (float)((float)v72 * (float)70.0);
    *p_x = (float)((float)((float)v74 * (float)-10.0) + (float)v69) + (float)v76;
    v77 = (float)(p_renderTime[34] * (float)70.0);
    v78 = (float)((float)((float)(p_renderTime[30] * (float)v67) * (float)10.0) + v182.x);
    v79 = (float)(p_renderTime[33] * (float)70.0);
    v80 = (float)(v182.y + (float)((float)(p_renderTime[31] * (float)v67) * (float)10.0));
    p_x[10] = (float)(v182.z + (float)((float)((float)v67 * p_renderTime[32]) * (float)10.0))
            + (float)(p_renderTime[35] * (float)70.0);
    p_x[8] = (float)v78 + (float)v79;
    p_x[9] = (float)v80 + (float)v77;
    v81 = v182.z;
    v82 = (float)(p_renderTime[34] * (float)-74.0);
    v83 = (float)((float)((float)v67 * p_renderTime[32]) * (float)10.0);
    v84 = (float)(p_renderTime[35] * (float)-74.0);
    v85 = (float)(v182.y + (float)((float)(p_renderTime[31] * (float)v67) * (float)10.0));
    p_x[16] = (float)((float)((float)(p_renderTime[30] * (float)v67) * (float)10.0) + v182.x)
            + (float)(p_renderTime[33] * (float)-74.0);
    p_x[17] = (float)v85 + (float)v82;
    p_x[18] = (float)((float)v81 + (float)v83) + (float)v84;
    v86 = (float)(p_renderTime[34] * (float)-74.0);
    v87 = (float)(p_renderTime[35] * (float)-74.0);
    v88 = (float)(v182.z + (float)((float)((float)v67 * p_renderTime[32]) * (float)-10.0));
    v89 = (float)(v182.y + (float)((float)(p_renderTime[31] * (float)v67) * (float)-10.0));
    p_x[24] = (float)((float)((float)(p_renderTime[30] * (float)v67) * (float)-10.0) + v182.x)
            + (float)(p_renderTime[33] * (float)-74.0);
    p_x[26] = (float)v88 + (float)v87;
    p_x[25] = (float)v89 + (float)v86;
    idTriangles::UpdateVertexBuffer(this: v53);
    v187.objectPtr = tr.progColorOnly;
    v183.objectPtr = tri_6;
    GL_DrawElements(prog: &v187, tri: &v183, extraState: 0x8000C45100000000uLL, skipDetailTriangles: v90);
    idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
    GL_State(stateBits: 0x444000000000uLL, forceGlState: v91);
    v92 = (float)(p_renderTime[34] * (float)32.0);
    v93 = (float)(p_renderTime[33] * (float)32.0);
    v195.z = v182.z + (float)(p_renderTime[35] * (float)32.0);
    v195.y = v182.y + (float)v92;
    v195.x = (float)v93 + v182.x;
    idRender::InternalDrawText(
      this,
      text: v202.data,
      origin: &v195,
      scale: 1.0,
      color: v94,
      viewAxis: (const idMat3 *)&idColor::colorRed,
      align: (const int)(p_renderTime + 27));
    idRender::InternalDrawText(
      this,
      text: v201.data,
      origin: &v182,
      scale: 1.0,
      color: v95,
      viewAxis: (const idMat3 *)&idColor::colorYellow,
      align: (const int)(p_renderTime + 27));
    v96 = *(idTriangles **)(*(_DWORD *)(*(_DWORD *)(v32 + 44) + 12) + 16);
    v97 = idTriangles::GPUMemoryUsed(this: v96);
    HIDWORD(v98) = v96->numVerts;
    HIDWORD(v99) = v97 / 1024;
    LODWORD(v98) = v96->numIndexes / 3;
    v101 = va::va(
             this: &v204,
             fmt: "Verts: %i  Tris: %i Memory: %iKB",
             a3: v98,
             a4: v99,
             a5: v100,
             a6: v159,
             a7: v163,
             a8: v167,
             a9: v171,
             a10: v175,
             a11: v179);
    idStr::idStr(this: &v199, text: v101);
    v102 = (float)(p_renderTime[33] * (float)32.0);
    v103 = (float)(v182.y - (float)(p_renderTime[34] * (float)32.0));
    v193.z = v182.z - (float)(p_renderTime[35] * (float)32.0);
    v193.y = v103;
    v193.x = v182.x - (float)v102;
    idRender::InternalDrawText(
      this,
      text: v199.data,
      origin: &v193,
      scale: 1.0,
      color: v104,
      viewAxis: (const idMat3 *)&idColor::colorOrange,
      align: (const int)(p_renderTime + 27));
    v106 = 0;
    v107 = 0;
    v108 = 0;
    v109 = 0;
    v110 = *(_DWORD *)(*(_DWORD *)(v32 + 44) + 8);
    HIDWORD(v111) = *(_DWORD *)(v110 + 1028);
    if ( SHIDWORD(v111) > 0 )
    {
      v112 = 0;
      do
      {
        v113 = *(_DWORD *)(v110 + 1024) + v112;
        if ( v113 != 0 )
        {
          v114 = *(_DWORD *)(v113 + 16);
          if ( v114 != 0 )
          {
            v106 += *(_DWORD *)(v114 + 32);
            v107 += *(_DWORD *)(v114 + 28) / 3;
            v108 += idTriangles::GPUMemoryUsed(this: *(idTriangles **)(v113 + 16));
          }
        }
        ++v109;
        v112 += 56;
        v110 = *(_DWORD *)(*(_DWORD *)(v32 + 44) + 8);
      }
      while ( v109 < *(_DWORD *)(v110 + 1028) );
    }
    LODWORD(v111) = &simplex_0[0][20];
    HIDWORD(v105) = v108 / 1024;
    v115 = va::va(
             this: &v206,
             fmt: "Total Verts: %i  Total Tris: %i Total Memory: %iKB",
             a3: __SPAIR64__(v106, v107),
             a4: v105,
             a5: v111,
             a6: v160,
             a7: v164,
             a8: v168,
             a9: v172,
             a10: v176,
             a11: v180);
    v116 = v115;
    for ( i = 0; v115->buffer[i] != 0; ++i )
      ;
    v118 = i + 1;
    v119 = v199.allocedAndFlag & 0x7FFFFFFF;
    if ( v199.allocedAndFlag >= 0 )
    {
      if ( v118 > v119 )
        idStr::ReAllocate(this: &v199, amount: v118, keepold: false);
    }
    else if ( v118 > v119
           && AssertFailed(
                file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                line: 463,
                expression: "amount <= GetAlloced()",
                inlineBreak: true) )
    {
      __trap();
    }
    memcpy(Dst: v199.data, Src: v116, Size: i);
    data = v199.data;
    v199.data[i] = 0;
    v199.len = i;
    v121 = (float)(p_renderTime[33] * (float)64.0);
    v122 = (float)(v182.y - (float)(p_renderTime[34] * (float)64.0));
    v197.z = v182.z - (float)(p_renderTime[35] * (float)64.0);
    v197.y = v122;
    v197.x = v182.x - (float)v121;
    idRender::InternalDrawText(
      this,
      text: v199.data,
      origin: &v197,
      scale: 1.0,
      color: (const idVec4 *)data,
      viewAxis: (const idMat3 *)&idColor::colorCyan,
      align: (const int)(p_renderTime + 27));
    idStr::FreeData(this: &v199);
  }
  GL_State(stateBits: 0x400000000000uLL, forceGlState: numVerts);
  GL_PolygonOffset(scale: 0.0, bias: 0.0, fill: v123);
  if ( r_showRuler.valueInteger != 0 )
  {
    v124 = *(float *)(v32 + 20);
    v125 = p_renderTime[33];
    v126 = *(float *)(v32 + 24);
    v127 = p_renderTime[35];
    v128 = *(float *)(v32 + 16);
    v129 = *(float *)(v32 + 4);
    v130 = *(float *)(v32 + 12);
    *((float *)&v185 + 1) = p_renderTime[34];
    *(float *)&v185 = v125;
    v131 = *(float *)(v32 + 8);
    v186 = v127;
    v132 = (float *)(v32 + 4);
    world = (idRenderWorldLocal *)this->world;
    v134 = (float)(*((float *)&v185 + 1)
                 - (float)(*((float *)&v185 + 1)
                         * (float)((float)(v125 * (float)v128)
                                 + (float)((float)((float)v126 * v127) + (float)((float)v124 * *((float *)&v185 + 1))))));
    v136 = (float)(*(float *)&v185
                 - (float)(*(float *)&v185
                         * (float)((float)(*(float *)&v185 * (float)v128)
                                 + (float)((float)((float)v126 * v127) + (float)((float)v124 * *((float *)&v185 + 1))))));
    v135 = (float)(v127
                 - (float)(v127
                         * (float)((float)(v125 * (float)v128)
                                 + (float)((float)((float)v126 * v127) + (float)((float)v124 * *((float *)&v185 + 1))))));
    _FP7 = (float)((float)((float)((float)v136 * (float)v136)
                         + (float)((float)((float)v135 * (float)v135) + (float)((float)v134 * (float)v134)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f13, f7, f8, f13 }
    v139 = __frsqrte(_FP13);
    v140 = (float)((float)-(float)((float)((float)((float)v139
                                                 * (float)((float)((float)((float)v136 * (float)v136)
                                                                 + (float)((float)((float)v135 * (float)v135)
                                                                         + (float)((float)v134 * (float)v134)))
                                                         * (float)0.5))
                                         * (float)v139)
                                 - (float)1.5)
                 * (float)v139);
    v141 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v139
                                                                                 * (float)((float)((float)((float)v136 * (float)v136)
                                                                                                 + (float)((float)((float)v135 * (float)v135) + (float)((float)v134 * (float)v134)))
                                                                                         * (float)0.5))
                                                                         * (float)v139)
                                                                 - (float)1.5)
                                                 * (float)v139)
                                         * (float)((float)((float)((float)v136 * (float)v136)
                                                         + (float)((float)((float)v135 * (float)v135)
                                                                 + (float)((float)v134 * (float)v134)))
                                                 * (float)0.5))
                                 * (float)((float)-(float)((float)((float)((float)v139
                                                                         * (float)((float)((float)((float)v136
                                                                                                 * (float)v136)
                                                                                         + (float)((float)((float)v135 * (float)v135)
                                                                                                 + (float)((float)v134 * (float)v134)))
                                                                                 * (float)0.5))
                                                                 * (float)v139)
                                                         - (float)1.5)
                                         * (float)v139))
                         - (float)1.5);
    v142 = (float)((float)-(float)((float)((float)((float)((float)v141 * (float)v140)
                                                 * (float)((float)((float)((float)v136 * (float)v136)
                                                                 + (float)((float)((float)v135 * (float)v135)
                                                                         + (float)((float)v134 * (float)v134)))
                                                         * (float)0.5))
                                         * (float)((float)v141 * (float)v140))
                                 - (float)1.5)
                 * (float)((float)v141 * (float)v140));
    v143 = (float)((float)v134 * (float)v142);
    v144 = (float)((float)v135 * (float)v142);
    v145 = (float)((float)v142 * (float)v136);
    v190.y = (float)((float)((float)v134 * (float)v142) * (float)10.0) + (float)v131;
    v190.z = (float)((float)((float)v135 * (float)v142) * (float)10.0) + (float)v130;
    v190.x = (float)((float)((float)v142 * (float)v136) * (float)10.0) + (float)v129;
    idRenderWorldLocal::DebugLine_renderThread(
      this: world,
      color: (const idVec4 *)&idColor::colorWhite,
      start: (const idVec3 *)(v32 + 4),
      end: &v190,
      lifetime: 0,
      depthTest: false);
    v147 = p_renderTime + 30;
    for ( j = 0; j < 10; ++j )
    {
      LODWORD(v146) = j;
      v149 = *(float *)(v32 + 12);
      v150 = *(float *)(v32 + 8);
      v185 = v146;
      v151 = *v132;
      v152 = v147[1];
      v153 = *v147;
      v154 = (idRenderWorldLocal *)this->world;
      v192.z = (float)((float)((float)v144 * (float)v146) + (float)v149) + v147[2];
      v192.y = (float)((float)((float)v143 * (float)v146) + (float)v150) + (float)v152;
      v192.x = (float)((float)((float)v145 * (float)v146) + (float)v151) + (float)v153;
      v156 = (float)((float)((float)v144 * (float)v146) + *(float *)(v32 + 12));
      v155 = *(float *)(v32 + 8);
      v194.x = (float)((float)v145 * (float)v146) + *v132;
      v194.z = v156;
      v194.y = (float)((float)v143 * (float)v146) + (float)v155;
      idRenderWorldLocal::DebugLine_renderThread(
        this: v154,
        color: (const idVec4 *)&idColor::colorWhite,
        start: &v194,
        end: &v192,
        lifetime: 0,
        depthTest: false);
    }
  }
  (*p_renderViewObject)->r.skipPostProcess = true;
  idStr::FreeData(this: &v201);
  idStr::FreeData(this: &v202);
  if ( (v184.listStatic == 0 || v184.listStatic == 2) && v30 != nullptr )
  {
    list = v30;
LABEL_67:
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$243393
// EA  : 0x8296F4B4
// RVA : 0x0096F4B4
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_243393()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 17104 + 112));
}


// ========================================================================
// __unwind$243394
// EA  : 0x8296F4DC
// RVA : 0x0096F4DC
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_243394()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 17104 + 416));
}


// ========================================================================
// __unwind$243395
// EA  : 0x8296F504
// RVA : 0x0096F504
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_243395()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 17104 + 384));
}


// ========================================================================
// __unwind$243396
// EA  : 0x8296F52C
// RVA : 0x0096F52C
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_243396()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 17104 + 80), tag: TAG_TRIANGLES);
}


// ========================================================================
// __unwind$243397
// EA  : 0x8296F558
// RVA : 0x0096F558
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_243397()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 17104 + 304));
}


// ========================================================================
// ?ShowModelLightingInfo@idRender@@AAAXXZ
// EA  : 0x8296F588
// RVA : 0x0096F588
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::ShowModelLightingInfo(idRender *this)
{
  idRenderView *renderViewObject; // r11
  double v3; // fp29
  double v4; // fp31
  double v5; // fp30
  double v6; // fp26
  double v7; // fp28
  double v8; // fp27
  int v9; // r27
  int v10; // r28
  drawSurf_t *v11; // r30
  float *model; // r11
  float *v13; // r11
  localTrace_t *v14; // r3
  double x; // fp4
  int v16; // r4
  int v17; // r10
  int v18; // r7
  double y; // fp3
  double z; // fp2
  double v21; // fp1
  double v22; // fp0
  double v23; // fp13
  idVehicleState **v24; // r4
  idVehicleState **list; // r30
  idList<idVehicleState *,5> v26; // [sp+60h] [-100h] BYREF
  idVec3 v27; // [sp+70h] [-F0h] BYREF
  idVec3 v28; // [sp+80h] [-E0h] BYREF
  traceContact_t v29; // [sp+90h] [-D0h] BYREF
  idTriangles v30; // [sp+C0h] [-A0h] BYREF

  if ( r_showDynamicLighting.valueInteger == 4 )
  {
    memset(&v26, 0, 14);
    renderViewObject = this->renderViewObject;
    *(_WORD *)&v26.memTag = 768;
    v3 = (float)(renderViewObject->r.vieworg.x + (float)(renderViewObject->r.viewaxis.mat[0].x * (float)16.0));
    v4 = (float)(renderViewObject->r.vieworg.z + (float)(renderViewObject->r.viewaxis.mat[0].z * (float)16.0));
    v5 = (float)(renderViewObject->r.vieworg.y + (float)(renderViewObject->r.viewaxis.mat[0].y * (float)16.0));
    v6 = (float)((float)(renderViewObject->r.viewaxis.mat[0].x * (float)10000.0)
               + (float)(renderViewObject->r.vieworg.x + (float)(renderViewObject->r.viewaxis.mat[0].x * (float)16.0)));
    v7 = (float)((float)(renderViewObject->r.viewaxis.mat[0].z * (float)10000.0)
               + (float)(renderViewObject->r.vieworg.z + (float)(renderViewObject->r.viewaxis.mat[0].z * (float)16.0)));
    v8 = (float)((float)(renderViewObject->r.viewaxis.mat[0].y * (float)10000.0)
               + (float)(renderViewObject->r.vieworg.y + (float)(renderViewObject->r.viewaxis.mat[0].y * (float)16.0)));
    idList<idThread *,58>::Clear(this: &v26);
    idList<idThread *,58>::Clear(this: &v26);
    idRender::BuildToolViewList(this);
    v9 = 0;
    if ( viewList.num > 0 )
    {
      v10 = 0;
      do
      {
        v11 = &viewList.list[v10];
        if ( viewList.list[v10].material != nullptr && v11->modelSurface != nullptr )
        {
          model = (float *)v11->model;
          v28.x = (float)((float)(model[298] * (float)v3)
                        + (float)((float)(model[299] * (float)v5) + (float)(model[300] * (float)v4)))
                + model[301];
          v28.y = (float)((float)(model[304] * (float)v4)
                        + (float)((float)(model[302] * (float)v3) + (float)(model[303] * (float)v5)))
                + model[305];
          v28.z = (float)((float)(model[308] * (float)v4)
                        + (float)((float)(model[306] * (float)v3) + (float)(model[307] * (float)v5)))
                + model[309];
          v13 = (float *)v11->model;
          v27.x = (float)((float)(v13[298] * (float)v6)
                        + (float)((float)(v13[299] * (float)v8) + (float)(v13[300] * (float)v7)))
                + v13[301];
          v27.y = (float)((float)(v13[304] * (float)v7)
                        + (float)((float)(v13[302] * (float)v6) + (float)(v13[303] * (float)v8)))
                + v13[305];
          v27.z = (float)((float)(v13[308] * (float)v7)
                        + (float)((float)(v13[306] * (float)v6) + (float)(v13[307] * (float)v8)))
                + v13[309];
          v14 = idTriangles::TriangleTrace(
                  this: &v30,
                  result: (localTrace_t *)v11->modelSurface->geometry,
                  start: &v28,
                  end: &v27,
                  radius: 1.0,
                  twoSided: (bool)v11->modelSurface);
          x = v14->point.x;
          v16 = v14->indexes[0];
          v29.trace.fraction = v14->fraction;
          v17 = v14->indexes[1];
          v18 = v14->indexes[2];
          y = v14->point.y;
          v29.trace.jointIndex = v14->jointIndex;
          z = v14->point.z;
          v21 = v14->normal.x;
          v22 = v14->normal.y;
          v23 = v14->normal.z;
          v29.trace.point.x = x;
          v29.trace.point.y = y;
          v29.trace.point.z = z;
          v29.trace.normal.x = v21;
          v29.trace.normal.y = v22;
          v29.trace.normal.z = v23;
          v29.trace.indexes[0] = v16;
          v29.trace.indexes[1] = v17;
          v29.trace.indexes[2] = v18;
          if ( v29.trace.fraction != 1.0 )
          {
            v29.surf = v11;
            idList<traceContact_t,3>::Append(this: (idList<traceContact_t,3> *)&v26, obj: &v29);
          }
        }
        ++v9;
        ++v10;
      }
      while ( v9 < viewList.num );
    }
    if ( v26.num != 0 )
    {
      list = v26.list;
      qsort(
        base: v26.list,
        num: v26.num,
        width: 0x30u,
        comp: (int (__fastcall *)(const void *, const void *))R_QsortContacts);
      idCVar::SetInteger(
        this: &r_showDynamicLightingSingleModel,
        newValue: (unsigned int)list[11]->listeningToList->size >> 8,
        force: true);
      idCVar::SetInteger(this: &r_showDynamicLighting, newValue: 1, force: true);
      if ( v26.listStatic == 0 || v26.listStatic == 2 )
      {
        v24 = list;
LABEL_17:
        idMem::Free(this: &mem, ptr: v24, align: ALIGN_16);
      }
    }
    else if ( v26.listStatic == 0 || v26.listStatic == 2 )
    {
      v24 = v26.list;
      if ( v26.list != nullptr )
        goto LABEL_17;
    }
  }
}


// ========================================================================
// __unwind$245077
// EA  : 0x8296F928
// RVA : 0x0096F928
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _unwind_245077()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 352 + 96));
}


// ========================================================================
// ?RenderDebugTools@idRender@@AAAXXZ
// EA  : 0x8296F950
// RVA : 0x0096F950
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __fastcall idRender::RenderDebugTools(idRender *this)
{
  idRenderView **p_renderViewObject; // r29
  unsigned __int64 v3; // r6
  int v4; // r4
  unsigned int v5; // r11
  idRenderView *v6; // r10
  bool v7; // r11
  int flags; // r17
  idRenderView *v9; // r11
  idODSObject<idRenderDestination> v10; // [sp+50h] [-A0h] BYREF

  viewListInitialized = false;
  idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &this->worldSpace.mvpMatrix);
  GL_SetDefaultState();
  v10.objectPtr = renderDestScaledColor;
  GL_SetRenderDestination(destination: &v10, level: 0, side: 0);
  p_renderViewObject = &this->renderViewObject;
  GL_Viewport(x: 0, y: 0, w: this->renderViewObject->renderWidth, h: this->renderViewObject->renderHeight);
  GL_Scissor(x: 0, y: 0, w: (*p_renderViewObject)->renderWidth, h: (*p_renderViewObject)->renderHeight);
  idRender::ShowDestinationAlpha(this, a2: v4, a3: v3);
  idRender::ShowIntensity(this);
  idRender::ShowDepthBuffer(this);
  idRender::ShowCracks(this);
  if ( r_showStencil.valueInteger != 0 )
    idRender::ColorByStencilBuffer(this);
  idRender::ShowTransparencySortOverdraw(this);
  idRender::ShowBlendedSurfaceOverdraw(this);
  idRender::ShowTris(this);
  idRender::ShowTwoSided(this);
  idRender::ShowBlendedSurfaces(this);
  idRender::ShowTrace(this);
  idRender::ShowTangentSpace(this);
  idRender::ShowTextureSpace(this);
  idRender::ShowTextureDistortion(this);
  idRender::ShowVertexColor(this);
  idRender::ShowGamma(this);
  idRender::ShowGammaBias(this);
  idRender::ShowGlobalShadows(this);
  idRender::ShowTextureReconstruct(this);
  idRender::ShowGammaCalibrationTest(this);
  idRender::ShowTestImage(this);
  idRender::ShowLoadedImages(this);
  idRender::ShowTestVMTR(this);
  idRender::ShowAutosprite(this);
  idRender::ShowModelGroupMasters(this);
  idRender::ShowViewModels(this);
  idRender::ShowEnvironments(this);
  idRender::ShowLights(this);
  idRender::ShowLightCount(this);
  idRender::ShowSurfaceBounds(this);
  idRender::ShowOcclusionBaseModel(this);
  idRender::ShowModelLightingInfo(this);
  idRender::ShowSurfaceInfo(this);
  if ( vt_showPageUsage.valueInteger <= 0 )
    goto LABEL_16;
  v5 = _S18_0;
  if ( (_S18_0 & 1) == 0 )
  {
    v5 = _S18_0 | 1;
    _S18_0 |= 1u;
  }
  if ( (v5 & 2) == 0 )
    _S18_0 = v5 | 2;
  v6 = *p_renderViewObject;
  v7 = false;
  if ( __fabs((float)((*p_renderViewObject)->r.vieworg.x - lastViewOrigin.x)) <= 0.1
    && __fabs((float)(v6->r.vieworg.y - lastViewOrigin.y)) <= 0.1 )
  {
    v7 = __fabs((float)(v6->r.vieworg.z - lastViewOrigin.z)) <= 0.1;
  }
  if ( !v7 || (unsigned __int8)idMat3::Compare(this: &v6->r.viewaxis, a: &lastViewAxis, epsilon: 0.0099999998) == 0 )
  {
    v9 = *p_renderViewObject;
    lastViewOrigin.x = (*p_renderViewObject)->r.vieworg.x;
    staticCount = 0;
    lastViewOrigin.y = v9->r.vieworg.y;
    lastViewOrigin.z = v9->r.vieworg.z;
    lastViewAxis = (*p_renderViewObject)->r.viewaxis;
    goto LABEL_16;
  }
  if ( ++staticCount != 4 )
  {
LABEL_16:
    flags = vt_showPageUsage.flags;
    goto LABEL_17;
  }
  flags = vt_showPageUsage.flags | 0x20000;
  vt_showPageUsage.flags |= 0x20000u;
LABEL_17:
  if ( (vt_upsampleFilter.flags & 0x20000) != 0
    || (vt_upsampleSharpen.flags & 0x20000) != 0
    || (vt_upsampleNoise.flags & 0x20000) != 0
    || (vt_stripPageBorders.flags & 0x20000) != 0
    || (vt_showPageSources.flags & 0x20000) != 0
    || (vt_showPageMips.flags & 0x20000) != 0
    || (vt_showPageColors.flags & 0x20000) != 0
    || (vt_showPageNumbers.flags & 0x20000) != 0
    || (vt_showPageInfo.flags & 0x20000) != 0
    || (vt_showPageBorders.flags & 0x20000) != 0
    || (vt_showPageSizes.flags & 0x20000) != 0
    || (flags & 0x20000) != 0 )
  {
    vt_upsampleFilter.flags &= ~0x20000u;
    vt_upsampleNoise.flags &= ~0x20000u;
    vt_stripPageBorders.flags &= ~0x20000u;
    vt_showPageSources.flags &= ~0x20000u;
    vt_showPageMips.flags &= ~0x20000u;
    vt_showPageColors.flags &= ~0x20000u;
    vt_showPageNumbers.flags &= ~0x20000u;
    vt_showPageInfo.flags &= ~0x20000u;
    vt_showPageBorders.flags &= ~0x20000u;
    vt_showPageSizes.flags &= ~0x20000u;
    vt_showPageUsage.flags = flags & 0xFFFDFFFF;
    vt_upsampleSharpen.flags &= ~0x20000u;
    idVirtualTextureSystem::EmptyCache(this: &virtualTextureSystem, skipVmtrCache: false);
    idVirtualTextureSystem::LockPhysicalPages(
      this: &virtualTextureSystem,
      virtualTextures: nullptr,
      numVirtualTextures: 0,
      maxLockedPages: -1);
  }
  idRender::RenderDebugTools_NonPortable(this);
}


// ========================================================================
// `dynamic initializer for 'r_showPVS''
// EA  : 0x8335DE60
// RVA : 0x0135DE60
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showPVS__()
{
  idCVar::idCVar(
    this: &r_showPVS,
    name: "r_showPVS",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showPVS__);
}


// ========================================================================
// `dynamic initializer for 'rpLightProjectionS''_0
// EA  : 0x8335DEB8
// RVA : 0x0135DEB8
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _dynamic_initializer_for__rpLightProjectionS___0()
{
  rpLightProjectionS_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLightProjectionS_0;
}


// ========================================================================
// `dynamic initializer for 'rpLightProjectionT''_0
// EA  : 0x8335DED8
// RVA : 0x0135DED8
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _dynamic_initializer_for__rpLightProjectionT___0()
{
  rpLightProjectionT_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLightProjectionT_0;
}


// ========================================================================
// `dynamic initializer for 'rpLightProjectionR''_0
// EA  : 0x8335DEF8
// RVA : 0x0135DEF8
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _dynamic_initializer_for__rpLightProjectionR___0()
{
  rpLightProjectionR_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLightProjectionR_0;
}


// ========================================================================
// `dynamic initializer for 'rpLightProjectionQ''_0
// EA  : 0x8335DF18
// RVA : 0x0135DF18
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _dynamic_initializer_for__rpLightProjectionQ___0()
{
  rpLightProjectionQ_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLightProjectionQ_0;
}


// ========================================================================
// `dynamic initializer for 'viewList''
// EA  : 0x8335DF38
// RVA : 0x0135DF38
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__viewList__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__viewList__);
}


// ========================================================================
// `dynamic initializer for 'r_showRuler''
// EA  : 0x8335DF48
// RVA : 0x0135DF48
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showRuler__()
{
  idCVar::idCVar(
    this: &r_showRuler,
    name: "r_showRuler",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showRuler__);
}


// ========================================================================
// `dynamic initializer for 'progshowIntensity''
// EA  : 0x8335DFA0
// RVA : 0x0135DFA0
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _dynamic_initializer_for__progshowIntensity__()
{
  progshowIntensity.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progshowIntensity;
}


// ========================================================================
// `dynamic initializer for 'progshowDepth''
// EA  : 0x8335DFC0
// RVA : 0x0135DFC0
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _dynamic_initializer_for__progshowDepth__()
{
  progshowDepth.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progshowDepth;
}


// ========================================================================
// `dynamic initializer for 'progshowCracks''
// EA  : 0x8335DFE0
// RVA : 0x0135DFE0
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _dynamic_initializer_for__progshowCracks__()
{
  progshowCracks.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progshowCracks;
}


// ========================================================================
// `dynamic initializer for 'proglandUnique''
// EA  : 0x8335E000
// RVA : 0x0135E000
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _dynamic_initializer_for__proglandUnique__()
{
  proglandUnique.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &proglandUnique;
}


// ========================================================================
// `dynamic initializer for 'progflatShadeReal''
// EA  : 0x8335E020
// RVA : 0x0135E020
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _dynamic_initializer_for__progflatShadeReal__()
{
  progflatShadeReal.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progflatShadeReal;
}


// ========================================================================
// `dynamic initializer for 'progshowTangentSpace''
// EA  : 0x8335E040
// RVA : 0x0135E040
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _dynamic_initializer_for__progshowTangentSpace__()
{
  progshowTangentSpace.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progshowTangentSpace;
}


// ========================================================================
// `dynamic initializer for 'progShowTextureSpace''
// EA  : 0x8335E060
// RVA : 0x0135E060
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _dynamic_initializer_for__progShowTextureSpace__()
{
  progShowTextureSpace.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progShowTextureSpace;
}


// ========================================================================
// `dynamic initializer for 'r_showGlobalShadows''
// EA  : 0x8335E080
// RVA : 0x0135E080
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showGlobalShadows__()
{
  idCVar::idCVar(
    this: &r_showGlobalShadows,
    name: "r_showGlobalShadows",
    value: "0",
    flags: 2,
    description: "1 = display the map as an image, 2 = draw the dynamics with the global shadow contributino",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showGlobalShadows__);
}


// ========================================================================
// `dynamic initializer for 'prog_landUniqueShowGlobalShadows''
// EA  : 0x8335E0D8
// RVA : 0x0135E0D8
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _dynamic_initializer_for__prog_landUniqueShowGlobalShadows__()
{
  prog_landUniqueShowGlobalShadows.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &prog_landUniqueShowGlobalShadows;
}


// ========================================================================
// `dynamic initializer for 'r_testTextureReconstruct''
// EA  : 0x8335E0F8
// RVA : 0x0135E0F8
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_testTextureReconstruct__()
{
  idCVar::idCVar(
    this: &r_testTextureReconstruct,
    name: "r_testTextureReconstruct",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_testTextureReconstruct__);
}


// ========================================================================
// `dynamic initializer for 'r_drawLoadedImages''
// EA  : 0x8335E150
// RVA : 0x0135E150
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_drawLoadedImages__()
{
  idCVar::idCVar(
    this: &r_drawLoadedImages,
    name: "r_drawLoadedImages",
    value: "0",
    flags: 2,
    description: "Draw loaded images scaled on the screen",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_drawLoadedImages__);
}


// ========================================================================
// `dynamic initializer for 'r_drawLoadedImagesScale''
// EA  : 0x8335E1A8
// RVA : 0x0135E1A8
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_drawLoadedImagesScale__()
{
  idCVar::idCVar(
    this: &r_drawLoadedImagesScale,
    name: "r_drawLoadedImagesScale",
    value: "64",
    flags: 4,
    description: "Shrink factor for r_drawLoadedImages",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_drawLoadedImagesScale__);
}


// ========================================================================
// `dynamic initializer for 'rp_progAutosprite1''
// EA  : 0x8335E200
// RVA : 0x0135E200
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _dynamic_initializer_for__rp_progAutosprite1__()
{
  rp_progAutosprite1.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &rp_progAutosprite1;
}


// ========================================================================
// `dynamic initializer for 'rp_progAutosprite2''
// EA  : 0x8335E220
// RVA : 0x0135E220
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void _dynamic_initializer_for__rp_progAutosprite2__()
{
  rp_progAutosprite2.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &rp_progAutosprite2;
}


// ========================================================================
// `dynamic initializer for 'r_showModelGroupMasters''
// EA  : 0x8335E240
// RVA : 0x0135E240
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showModelGroupMasters__()
{
  idCVar::idCVar(
    this: &r_showModelGroupMasters,
    name: "r_showModelGroupMasters",
    value: "0",
    flags: 2,
    description: "draw lines from from models that use another model's origin for lighting and shadowing (1 = visible models, 2 = all models)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showModelGroupMasters__);
}


// ========================================================================
// `dynamic initializer for 'ClearDebugDrawing_v''
// EA  : 0x8335E298
// RVA : 0x0135E298
// PDB : w:\tech5\engine\renderer\render_tools.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ClearDebugDrawing_v__()
{
  return idCommandLink::idCommandLink(
           this: &ClearDebugDrawing_v,
           cmdName: "ClearDebugDrawing",
           function: ClearDebugDrawing_f,
           description: "Clears all the debug lines",
           argCompletion: nullptr);
}

