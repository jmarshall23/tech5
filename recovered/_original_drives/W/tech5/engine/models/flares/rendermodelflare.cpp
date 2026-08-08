
// ========================================================================
// ?StartFrame@idRenderModelFlare@@SAXXZ
// EA  : 0x827D2B00
// RVA : 0x007D2B00
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

static void __fastcall idRenderModelFlare::StartFrame()
{
  idRenderModelFlare::mappedBufferIndex ^= 1u;
  idRenderModelFlare::mappedVertices = (idDrawVert *)idVertexBuffer::MapBuffer(
                                                       this: &idRenderModelFlare::vertexBuffer[idRenderModelFlare::mappedBufferIndex],
                                                       mapType: BM_WRITE_NOSYNC);
  idRenderModelFlare::vertOffset = 0;
}


// ========================================================================
// ?EndFrame@idRenderModelFlare@@SAXXZ
// EA  : 0x827D2B58
// RVA : 0x007D2B58
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

static void __fastcall idRenderModelFlare::EndFrame()
{
  idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&idRenderModelFlare::vertexBuffer[idRenderModelFlare::mappedBufferIndex]);
}


// ========================================================================
// ?Shutdown@idRenderModelFlareOcclusionQuad@@SAXXZ
// EA  : 0x827D2B78
// RVA : 0x007D2B78
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

static void __fastcall idRenderModelFlareOcclusionQuad::Shutdown()
{
  idVertexBuffer::FreeBufferObject(this: &idRenderModelFlareOcclusionQuad::vertexBuffer);
  idIndexBuffer::FreeBufferObject(this: &idRenderModelFlareOcclusionQuad::indexBuffer);
  idRenderModelFlareOcclusionQuad::vertOffset = 0;
}


// ========================================================================
// ?StartFrame@idRenderModelFlareOcclusionQuad@@SAXXZ
// EA  : 0x827D2BB8
// RVA : 0x007D2BB8
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

static void __fastcall idRenderModelFlareOcclusionQuad::StartFrame()
{
  idRenderModelFlareOcclusionQuad::vertOffset = 0;
}


// ========================================================================
// ?Shutdown@idRenderModelFlare@@SAXXZ
// EA  : 0x827D2E18
// RVA : 0x007D2E18
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

static void __fastcall idRenderModelFlare::Shutdown()
{
  idPixelUnpackBuffer *v0; // r3
  idVertexBuffer *v1; // r31

  if ( !idLib::headless )
  {
    if ( idRenderModelFlare::mappedVertices != nullptr )
    {
      v0 = (idPixelUnpackBuffer *)&idRenderModelFlare::vertexBuffer[idRenderModelFlare::mappedBufferIndex];
      if ( v0->size < 0 )
        idVertexBuffer::UnmapBuffer(this: v0);
    }
    v1 = idRenderModelFlare::vertexBuffer;
    do
      idVertexBuffer::FreeBufferObject(this: v1++);
    while ( (int)v1 < (int)&idRenderModelFlare::indexBuffer );
    idIndexBuffer::FreeBufferObject(this: &idRenderModelFlare::indexBuffer);
  }
  idRenderModelFlare::mappedVertices = nullptr;
  idRenderModelFlare::mappedBufferIndex = 0;
  idRenderModelFlare::vertOffset = 0;
}


// ========================================================================
// ??0idRenderModelFlare@@QAA@PBVidDeclFlare@@@Z
// EA  : 0x827D2EC8
// RVA : 0x007D2EC8
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

idRenderModelFlare *__fastcall idRenderModelFlare::idRenderModelFlare(
        idRenderModelFlare *this,
        const idDeclFlare *declFlare)
{
  int i; // r27
  idTriangles *v5; // r3
  idTriangles *v6; // r29

  idRenderModel::idRenderModel(this);
  this->flareDecl = declFlare;
  this->quadModelIndex = -1;
  this->__vftable = (idRenderModelFlare_vtbl *)&idRenderModelFlare::`vftable';
  this->isSunFlare = false;
  idRenderModel::SetName(this, name_: declFlare->name.str);
  *((_BYTE *)&this->g + 105) |= 0xC5u;
  for ( i = 20; i != 0; --i )
  {
    v5 = (idTriangles *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x84u,
                          tag: TAG_TRIANGLES,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
      v6 = idTriangles::idTriangles(this: v5);
    else
      v6 = nullptr;
    idIndexBuffer::Reference(this: &v6->indexBuffer, other: &idRenderModelFlare::indexBuffer);
    idVertexBuffer::Reference(this: &v6->vertexBuffer, other: idRenderModelFlare::vertexBuffer);
    idRenderModel::AddSurface(this: nullptr, surf: nullptr);
  }
  return this;
}


// ========================================================================
// __unwind$230967
// EA  : 0x827D3014
// RVA : 0x007D3014
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void _unwind_230967()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 256 + 276));
}


// ========================================================================
// __unwind$230968
// EA  : 0x827D303C
// RVA : 0x007D303C
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void _unwind_230968()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 96), tag: TAG_TRIANGLES);
}


// ========================================================================
// ??0idRenderModelFlareOcclusionQuad@@QAA@XZ
// EA  : 0x827D30D8
// RVA : 0x007D30D8
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

idRenderModelFlareOcclusionQuad *__fastcall idRenderModelFlareOcclusionQuad::idRenderModelFlareOcclusionQuad(
        idRenderModelFlareOcclusionQuad *this)
{
  idTriangles *v2; // r30
  char v3; // r27
  idTriangles *v4; // r3
  double z; // fp12
  double x; // fp9
  double y; // fp6
  double v12; // fp13
  double v14; // fp3
  double v16; // fp10
  double v25; // fp7
  double v29; // fp4
  double v31; // fp10
  double v32; // fp7
  double v33; // fp6
  double v36; // fp12
  double v48; // fp6
  double v49; // fp5
  double v53; // fp4
  double v54; // fp8
  double v55; // fp7
  double v56; // fp9
  double v68; // fp6
  idResource *r; // [sp+70h] [-70h]

  idRenderModel::idRenderModel(this);
  this->__vftable = (idRenderModelFlareOcclusionQuad_vtbl *)&idRenderModelFlareOcclusionQuad::`vftable';
  idRenderModel::SetName(this, name_: "_flareOcclusionQuad");
  v2 = nullptr;
  this->isSunFlare = false;
  this->currentIdx = 0;
  this->screenSpaceArea[0] = 0.0;
  this->screenSpaceArea[1] = 0.0;
  v3 = *((_BYTE *)&this->g + 106) | 8;
  *((_BYTE *)&this->g + 105) |= 0xC0u;
  *((_BYTE *)&this->g + 106) = v3;
  r = mtrFlareDepthOnly.r;
  v4 = (idTriangles *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x84u,
                        tag: TAG_TRIANGLES,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v2 = idTriangles::idTriangles(this: v4);
  v2->numVerts = 4;
  v2->numIndexes = 6;
  idVertexBuffer::Reference(this: &v2->vertexBuffer, other: &idRenderModelFlareOcclusionQuad::vertexBuffer);
  idIndexBuffer::Reference(this: &v2->indexBuffer, other: &idRenderModelFlareOcclusionQuad::indexBuffer);
  v2->bounds.b[0].z = 1.0e30;
  v2->bounds.b[0].y = 1.0e30;
  v2->bounds.b[0].x = 1.0e30;
  v2->bounds.b[1].z = -1.0e30;
  v2->bounds.b[1].y = -1.0e30;
  v2->bounds.b[1].x = -1.0e30;
  z = v2->bounds.b[0].z;
  _FP10 = (float)(v2->bounds.b[0].x - idRenderModelFlareOcclusionQuad::points[0].x);
  x = v2->bounds.b[1].x;
  __asm { fsel      f8, f10, f0, f11 }
  v2->bounds.b[0].x = _FP8;
  _FP7 = (float)(v2->bounds.b[0].y - idRenderModelFlareOcclusionQuad::points[0].y);
  y = v2->bounds.b[1].y;
  __asm { fsel      f5, f7, f0, f13 }
  v2->bounds.b[0].y = _FP5;
  v12 = _FP8;
  _FP4 = (float)((float)z - idRenderModelFlareOcclusionQuad::points[0].z);
  v14 = v2->bounds.b[1].z;
  __asm { fsel      f2, f4, f0, f12 }
  v2->bounds.b[0].z = _FP2;
  v16 = _FP5;
  _FP1 = (float)(idRenderModelFlareOcclusionQuad::points[0].x - (float)x);
  __asm { fsel      f12, f1, f0, f9 }
  v2->bounds.b[1].x = _FP12;
  _FP11 = (float)(idRenderModelFlareOcclusionQuad::points[0].y - (float)y);
  __asm { fsel      f9, f11, f0, f6 }
  v2->bounds.b[1].y = _FP9;
  _FP8 = (float)(idRenderModelFlareOcclusionQuad::points[0].z - (float)v14);
  __asm { fsel      f6, f8, f0, f3 }
  v2->bounds.b[1].z = _FP6;
  _FP5 = (float)((float)v12 - idRenderModelFlareOcclusionQuad::points[1].x);
  __asm { fsel      f3, f5, f0, f13 }
  v2->bounds.b[0].x = _FP3;
  v25 = _FP2;
  _FP2 = (float)((float)v16 - idRenderModelFlareOcclusionQuad::points[1].y);
  __asm { fsel      f1, f2, f0, f10 }
  v2->bounds.b[0].y = _FP1;
  _FP13 = (float)((float)v25 - idRenderModelFlareOcclusionQuad::points[1].z);
  v29 = _FP12;
  __asm { fsel      f12, f13, f0, f7 }
  v2->bounds.b[0].z = _FP12;
  v31 = _FP9;
  v32 = _FP3;
  _FP11 = (float)(idRenderModelFlareOcclusionQuad::points[1].x - (float)v29);
  __asm { fsel      f9, f11, f0, f4 }
  v2->bounds.b[1].x = _FP9;
  v36 = _FP9;
  _FP5 = (float)(idRenderModelFlareOcclusionQuad::points[1].y - (float)v31);
  __asm { fsel      f4, f5, f0, f10 }
  v2->bounds.b[1].y = _FP4;
  _FP3 = (float)(idRenderModelFlareOcclusionQuad::points[1].z - (float)_FP6);
  v33 = _FP1;
  __asm { fsel      f2, f3, f0, f8 }
  v2->bounds.b[1].z = _FP2;
  _FP1 = (float)((float)v32 - idRenderModelFlareOcclusionQuad::points[2].x);
  __asm { fsel      f0, f1, f0, f7 }
  v2->bounds.b[0].x = _FP0;
  _FP13 = (float)((float)v33 - idRenderModelFlareOcclusionQuad::points[2].y);
  __asm { fsel      f11, f13, f0, f6 }
  v2->bounds.b[0].y = _FP11;
  _FP9 = (float)(v2->bounds.b[0].z - idRenderModelFlareOcclusionQuad::points[2].z);
  __asm { fsel      f7, f9, f0, f10 }
  v2->bounds.b[0].z = _FP7;
  _FP3 = (float)(idRenderModelFlareOcclusionQuad::points[2].x - (float)v36);
  v48 = _FP2;
  v49 = v2->bounds.b[0].x;
  __asm { fsel      f2, f3, f0, f12 }
  v2->bounds.b[1].x = _FP2;
  _FP1 = (float)(idRenderModelFlareOcclusionQuad::points[2].y - (float)_FP4);
  __asm { fsel      f0, f1, f0, f8 }
  v2->bounds.b[1].y = _FP0;
  v53 = _FP11;
  v54 = _FP7;
  v55 = v2->bounds.b[1].y;
  v56 = _FP2;
  _FP13 = (float)(idRenderModelFlareOcclusionQuad::points[2].z - (float)v48);
  __asm { fsel      f12, f13, f0, f6 }
  v2->bounds.b[1].z = _FP12;
  _FP11 = (float)((float)v49 - idRenderModelFlareOcclusionQuad::points[3].x);
  __asm { fsel      f10, f11, f0, f5 }
  v2->bounds.b[0].x = _FP10;
  _FP5 = (float)((float)v53 - idRenderModelFlareOcclusionQuad::points[3].y);
  __asm { fsel      f4, f5, f0, f4 }
  v2->bounds.b[0].y = _FP4;
  _FP3 = (float)((float)v54 - idRenderModelFlareOcclusionQuad::points[3].z);
  __asm { fsel      f2, f3, f0, f8 }
  v2->bounds.b[0].z = _FP2;
  _FP1 = (float)(idRenderModelFlareOcclusionQuad::points[3].x - (float)v56);
  __asm { fsel      f0, f1, f0, f9 }
  v2->bounds.b[1].x = _FP0;
  _FP13 = (float)(idRenderModelFlareOcclusionQuad::points[3].y - (float)v55);
  v68 = _FP12;
  __asm { fsel      f12, f13, f0, f7 }
  v2->bounds.b[1].y = _FP12;
  _FP11 = (float)(idRenderModelFlareOcclusionQuad::points[3].z - (float)v68);
  __asm { fsel      f10, f11, f0, f6 }
  v2->bounds.b[1].z = _FP10;
  idRenderModel::AddSurface(this: (idRenderModel *)r, surf: nullptr);
  idRenderModel::FinishSurfaces(this);
  return this;
}


// ========================================================================
// __unwind$231046_0
// EA  : 0x827D3444
// RVA : 0x007D3444
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void _unwind_231046_0()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 224 + 244));
}


// ========================================================================
// __unwind$231047_0
// EA  : 0x827D346C
// RVA : 0x007D346C
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void _unwind_231047_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 224 + 96), tag: TAG_TRIANGLES);
}


// ========================================================================
// ?CalcScreenSpaceAreaForView@idRenderModelFlareOcclusionQuad@@IBAMPBVidRenderView@@0@Z
// EA  : 0x827D34F8
// RVA : 0x007D34F8
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idRenderModelFlareOcclusionQuad::CalcScreenSpaceAreaForView(
        idRenderModelFlareOcclusionQuad *this,
        const idRenderView *currentView,
        const idRenderView *nextView)
{
  idRenderMatrix *p_viewMatrix; // r29
  const idRenderMatrix *ModelMatrix; // r3
  idRenderModelParms *p_g; // r3
  double v8; // fp1
  double v9; // fp0
  __int128 v10; // r7
  BOOL useDeferredPosition; // r10
  idRenderModelParms *p_deferredOrigin; // r3
  __int64 v13; // r7 OVERLAPPED
  __int64 v14; // r9
  double v15; // fp0
  double v16; // fp12
  double v17; // fp11
  float *p_z; // r11
  int i; // ctr
  double x; // fp13
  int windowHeight; // r8
  double y; // fp10
  __int128 v23; // r9
  idVec4 v25; // [sp+60h] [-270h] BYREF
  idVec3 v26; // [sp+70h] [-260h] BYREF
  idVec3 v27; // [sp+80h] [-250h] BYREF
  idVec4 v28; // [sp+90h] [-240h] BYREF
  idVec3 v29; // [sp+A0h] [-230h] BYREF
  idVec3 v30; // [sp+B0h] [-220h] BYREF
  idVec3 v31; // [sp+C0h] [-210h] BYREF
  idVec3 v32; // [sp+D0h] [-200h] BYREF
  idRenderMatrix v33; // [sp+E0h] [-1F0h] BYREF
  idVec4 v34; // [sp+120h] [-1B0h] BYREF
  idVec4 v35; // [sp+130h] [-1A0h] BYREF
  idVec4 v36; // [sp+140h] [-190h] BYREF
  idVec4 v37; // [sp+150h] [-180h] BYREF
  idVec4 v38; // [sp+160h] [-170h] BYREF
  idVec4 v39; // [sp+170h] [-160h] BYREF
  idRenderMatrix viewMatrix; // [sp+180h] [-150h] BYREF
  idVec4 v41; // [sp+1C0h] [-110h] BYREF
  idRenderMatrix v42; // [sp+1D0h] [-100h] BYREF
  idRenderMatrix v43; // [sp+210h] [-C0h] BYREF
  idVec4 v44; // [sp+250h] [-80h] BYREF
  idRenderMatrix v45; // [sp+260h] [-70h] BYREF

  if ( this->isSunFlare )
  {
    viewMatrix = currentView->viewMatrix;
    useDeferredPosition = this->useDeferredPosition;
    p_deferredOrigin = (idRenderModelParms *)&this->deferredOrigin;
    viewMatrix.m[3] = 0.0;
    viewMatrix.m[7] = 0.0;
    viewMatrix.m[11] = 0.0;
    if ( !useDeferredPosition )
      p_deferredOrigin = &this->g;
    idRenderMatrix::TransformModelToClip(
      src: &p_deferredOrigin->origin,
      modelMatrix: &viewMatrix,
      projectionMatrix: &currentView->projectionMatrix,
      eye: &v41,
      clip: &v25);
    if ( __fabs(v25.w) < idMath::FLT_SMALLEST_NON_DENORMAL
      || (HIDWORD(v14) = 0x82000000,
          v16 = (float)(v25.x * (float)((float)1.0 / v25.w)),
          v17 = (float)(v25.y * (float)((float)1.0 / v25.w)),
          (v15 = (float)(v25.z * (float)((float)1.0 / v25.w))) < -1.0)
      || v15 > 1.0 )
    {
      v8 = 0.0;
    }
    else
    {
      p_z = &v32.z;
      LODWORD(v14) = 0;
      for ( i = 8; i != 0; --i )
      {
        p_z += 2;
        *(_QWORD *)p_z = v14;
      }
      x = this->g.scale.x;
      windowHeight = currentView->windowHeight;
      y = this->g.scale.y;
      LODWORD(v13) = currentView->windowWidth;
      v33.m[10] = 1.0;
      v33.m[3] = v16;
      v33.m[7] = v17;
      v33.m[11] = 0.99989998;
      v33.m[15] = 1.0;
      v33.m[5] = (float)y / (float)*(__int64 *)((char *)&v13 - 4);
      v33.m[0] = (float)x / (float)v13;
      idRenderMatrix::Multiply(a: &v33, b: &renderMatrix_flipToOpenGL, out: &v43);
      idRenderMatrix::TransformPoint(this: &v43, in: idRenderModelFlareOcclusionQuad::points, out: &v37);
      idRenderMatrix::TransformPoint(this: &v43, in: &idRenderModelFlareOcclusionQuad::points[1], out: &v35);
      idRenderMatrix::TransformPoint(this: &v43, in: &idRenderModelFlareOcclusionQuad::points[3], out: &v36);
      idRenderMatrix::TransformClipToDevice(clip: &v37, normalized: &v26);
      idRenderMatrix::TransformClipToDevice(clip: &v35, normalized: &v32);
      idRenderMatrix::TransformClipToDevice(clip: &v36, normalized: &v31);
      LODWORD(v23) = currentView->renderWidth;
      DWORD2(v23) = currentView->renderHeight;
      v8 = (float)((float)__fabs((float)((float)((float)((float)(v31.y + (float)1.0)
                                                       * (float)((float)*(__int64 *)((char *)&v23 + 4) - (float)1.0))
                                               * (float)0.5)
                                       - (float)((float)((float)(v26.y + (float)1.0)
                                                       * (float)((float)*(__int64 *)((char *)&v23 + 4) - (float)1.0))
                                               * (float)0.5)))
                 * (float)__fabs((float)((float)((float)((float)(v32.x + (float)1.0)
                                                       * (float)((float)(__int64)v23 - (float)1.0))
                                               * (float)0.5)
                                       - (float)((float)((float)(v26.x + (float)1.0)
                                                       * (float)((float)(__int64)v23 - (float)1.0))
                                               * (float)0.5))));
    }
  }
  else
  {
    p_viewMatrix = &currentView->viewMatrix;
    ModelMatrix = idRenderModel::GetModelMatrix(this);
    idRenderMatrix::Multiply(a: p_viewMatrix, b: ModelMatrix, out: &v45);
    p_g = (idRenderModelParms *)&this->deferredOrigin;
    if ( !this->useDeferredPosition )
      p_g = &this->g;
    idRenderMatrix::TransformModelToClip(
      src: &p_g->origin,
      modelMatrix: p_viewMatrix,
      projectionMatrix: &currentView->projectionMatrix,
      eye: &v44,
      clip: &v28);
    if ( __fabs(v28.w) < idMath::FLT_SMALLEST_NON_DENORMAL
      || (v9 = (float)((float)((float)1.0 / v28.w) * v28.z)) < -1.0
      || v9 > 1.0 )
    {
      v8 = 0.0;
    }
    else
    {
      idRenderMatrix::Multiply(a: &currentView->projectionMatrix, b: &v45, out: &v42);
      idRenderMatrix::TransformPoint(this: &v42, in: idRenderModelFlareOcclusionQuad::points, out: &v39);
      idRenderMatrix::TransformPoint(this: &v42, in: &idRenderModelFlareOcclusionQuad::points[1], out: &v34);
      idRenderMatrix::TransformPoint(this: &v42, in: &idRenderModelFlareOcclusionQuad::points[3], out: &v38);
      idRenderMatrix::TransformClipToDevice(clip: &v39, normalized: &v27);
      idRenderMatrix::TransformClipToDevice(clip: &v34, normalized: &v29);
      idRenderMatrix::TransformClipToDevice(clip: &v38, normalized: &v30);
      *((_QWORD *)&v10 + 1) = *(_QWORD *)&currentView->renderWidth;
      v8 = (float)((float)__fabs((float)((float)((float)((float)(v30.y + (float)1.0)
                                                       * (float)((float)(__int64)v10 - (float)1.0))
                                               * (float)0.5)
                                       - (float)((float)((float)(v27.y + (float)1.0)
                                                       * (float)((float)(__int64)v10 - (float)1.0))
                                               * (float)0.5)))
                 * (float)__fabs((float)((float)((float)((float)(v29.x + (float)1.0)
                                                       * (float)((float)*(__int64 *)((char *)&v10 + 4) - (float)1.0))
                                               * (float)0.5)
                                       - (float)((float)((float)(v27.x + (float)1.0)
                                                       * (float)((float)*(__int64 *)((char *)&v10 + 4) - (float)1.0))
                                               * (float)0.5))));
    }
  }
  return *((float *)&v8 + 1);
}


// ========================================================================
// ?Save@idRenderModelFlareOcclusionQuad@@EBAXPAVidFile@@@Z
// EA  : 0x827D3920
// RVA : 0x007D3920
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void __fastcall idRenderModelFlareOcclusionQuad::Save(idRenderModelFlareOcclusionQuad *this, idFile *fp)
{
  idRenderModel::Save(this, fp);
  fp->Write(this: fp, a2: &this->isSunFlare, a3: 1u);
  fp->Write(this: fp, a2: &this->currentIdx, a3: 4u);
  fp->Write(this: fp, a2: this->screenSpaceArea, a3: 8u);
}


// ========================================================================
// ?Init@idRenderModelFlare@@SAXXZ
// EA  : 0x827D39B8
// RVA : 0x007D39B8
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

static void __fastcall idRenderModelFlare::Init()
{
  idVertexBuffer *v0; // r30
  char *v1; // r30
  int v2; // r10
  char *v3; // r11
  int i; // ctr

  v0 = idRenderModelFlare::vertexBuffer;
  do
    idVertexBuffer::AllocBufferObject(
      this: v0++,
      data: nullptr,
      allocSize: 0x8000,
      vertexMask: 31,
      allocUsage: BU_DYNAMIC);
  while ( (int)v0 < (int)&idRenderModelFlare::indexBuffer );
  v1 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                 size: 0xC00u,
                 tag: TAG_TEMP,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v2 = 3;
  v3 = v1 - 2;
  for ( i = 256; i != 0; --i )
  {
    *((_WORD *)v3 + 1) = v2 - 3;
    *((_WORD *)v3 + 2) = v2 - 1;
    *((_WORD *)v3 + 3) = v2;
    *((_WORD *)v3 + 4) = v2 - 3;
    *((_WORD *)v3 + 5) = v2;
    v3 += 12;
    *(_WORD *)v3 = v2 - 2;
    v2 += 4;
  }
  idIndexBuffer::AllocBufferObject(
    this: &idRenderModelFlare::indexBuffer,
    data: v1,
    allocSize: 3072,
    allocUsage: BU_DYNAMIC);
  idRenderModelFlare::mappedVertices = nullptr;
  idRenderModelFlare::mappedBufferIndex = 0;
  idRenderModelFlare::vertOffset = 0;
  if ( v1 != nullptr )
    idMem::Free(this: &mem, ptr: v1, align: ALIGN_16);
}


// ========================================================================
// __unwind$232068
// EA  : 0x827D3AF8
// RVA : 0x007D3AF8
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void _unwind_232068()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 128 + 80));
}


// ========================================================================
// ?UpdateInView@idRenderModelFlare@@MAA_NPBVidRenderView@@0PAVidRenderModelUpdateTools@@@Z
// EA  : 0x827D3B20
// RVA : 0x007D3B20
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

int __fastcall idRenderModelFlare::UpdateInView(
        idRenderModelFlare *this,
        const idRenderView *currentView,
        const idRenderView *nextView,
        idRenderModelUpdateTools *updateTools)
{
  int valueInteger; // r31
  const idDeclFlare **p_flareDecl; // r27
  int *p_num; // r25
  double v9; // fp23
  double v10; // fp29
  double v11; // fp28
  double v12; // fp27
  double v13; // fp26
  idRenderWorld *World; // r3
  int v15; // r3
  idRenderModel *v16; // r30
  double v17; // fp30
  int Index; // r3
  __int64 v19; // r11
  int ModelOcclusionResult; // r3
  double v21; // fp0
  const idParmBlock *RenderParmBlock; // r3
  parmValue_t *v23; // r11
  const idParmBlock *v24; // r3
  BOOL useDeferredPosition; // r30
  idRenderModelParms *p_deferredOrigin; // r11
  double v27; // fp7
  double v28; // fp6
  double v29; // fp1
  double v30; // fp15
  double v31; // fp0
  double v32; // fp30
  int v33; // r9
  int v34; // r10
  idRenderModelSurface *v35; // r11
  idMat3 *p_viewaxis; // r10
  idMat3 *p_deferredAxis; // r11
  double v39; // fp16
  const idParmBlock *v40; // r3
  parmValue_t *v41; // r5
  double v42; // fp22
  double v43; // fp24
  const idParmBlock *v44; // r3
  double v45; // fp0
  const idDeclFlare *v46; // r11
  double v47; // fp20
  double v48; // fp26
  double v49; // fp29
  double v50; // fp28
  double v51; // fp30
  double brightness; // fp27
  idRenderModelParms *p_g; // r3
  double v58; // fp18
  double x; // fp22
  double y; // fp21
  int v61; // r4
  int v62; // r3
  int v63; // r21
  const idDeclFlare *flareDecl; // r11
  const idMaterial **v67; // r31
  const idMaterial *v68; // r10
  idDeclFlare::subFlare_t *v69; // r30
  const idMaterial **p_mtr; // r28
  float v81; // r3
  float z; // r11
  int v85; // ctr
  double v88; // fp13
  double v89; // fp0
  __int64 v90; // r6
  float v91; // r8
  float v92; // r7
  char v93; // r4
  double v94; // fp6
  double v97; // fp0
  double v103; // fp12
  double v104; // fp0
  double v106; // fp12
  double v107; // fp0
  double v108; // fp13
  double v109; // fp11
  double v110; // fp12
  double position; // fp10
  int v113; // ctr
  double v115; // fp8
  double v117; // fp7
  int v119; // r9
  int v120; // r10
  idRenderModelSurface *v121; // r11
  int v122; // [sp+50h] [-2A0h]
  float v123; // [sp+60h] [-290h]
  float v124; // [sp+60h] [-290h]
  float v125; // [sp+64h] [-28Ch]
  float v126; // [sp+68h] [-288h]
  float v127; // [sp+6Ch] [-284h]
  int v128; // [sp+70h] [-280h]
  idVec3 v129; // [sp+78h] [-278h] BYREF
  __int64 v130; // [sp+88h] [-268h]
  float v131; // [sp+90h] [-260h]
  float v132; // [sp+94h] [-25Ch]
  float v133; // [sp+98h] [-258h]
  float w; // [sp+9Ch] [-254h]
  float v135[4]; // [sp+A0h] [-250h] BYREF
  float v136; // [sp+B0h] [-240h] BYREF
  float v137; // [sp+B4h] [-23Ch]
  float v138; // [sp+B8h] [-238h]
  float v139; // [sp+BCh] [-234h]
  float v140; // [sp+C0h] [-230h] BYREF
  char v141; // [sp+CEh] [-222h] BYREF
  float v142[3]; // [sp+D0h] [-220h] BYREF
  float v143; // [sp+DCh] [-214h]
  float v144; // [sp+E0h] [-210h]
  float v145; // [sp+F0h] [-200h] BYREF
  float v146; // [sp+F4h] [-1FCh]
  float v147; // [sp+F8h] [-1F8h]
  float v148; // [sp+FCh] [-1F4h]
  float v149; // [sp+100h] [-1F0h]
  float v150[8]; // [sp+110h] [-1E0h] BYREF
  idVec4 v151; // [sp+130h] [-1C0h] BYREF
  __int64 v152; // [sp+140h] [-1B0h]
  idRenderMatrix viewMatrix; // [sp+150h] [-1A0h] BYREF
  idVec4 v154; // [sp+190h] [-160h] BYREF
  idRenderMatrix v155[3]; // [sp+1A0h] [-150h] BYREF

  if ( r_skipFlares.valueInteger != 0
    || (valueInteger = r_singleFlareModel.valueInteger, r_singleFlareModel.valueInteger >= 0)
    && valueInteger != idRenderModel::GetIndex(this) )
  {
    v119 = 0;
    if ( this->surfaces.num > 0 )
    {
      v120 = 0;
      do
      {
        ++v119;
        v121 = &this->surfaces.list[v120++];
        v121->geometry->numVerts = 0;
        v121->geometry->numIndexes = 0;
      }
      while ( v119 < this->surfaces.num );
    }
    return 0;
  }
  p_flareDecl = &this->flareDecl;
  p_num = &this->surfaces.num;
  if ( this->flareDecl->subflares.num > this->surfaces.num )
    return 0;
  v9 = 1.0;
  v10 = 1.0;
  v11 = 1.0;
  v12 = 1.0;
  v13 = 1.0;
  if ( this->quadModelIndex >= 0 )
  {
    World = idRenderModel::GetWorld(this);
    v15 = (int)World->RenderModelForIndex(this: World, a2: this->quadModelIndex);
    v16 = (idRenderModel *)v15;
    if ( v15 != 0 )
    {
      v9 = 0.0;
      v17 = *(float *)(4 * ((*(_DWORD *)(v15 + 2036) ^ 1) + 510) + v15);
      Index = idRenderModel::GetIndex(this: (idRenderModel *)v15);
      ModelOcclusionResult = idRenderView::GetModelOcclusionResult(this: currentView, modelIndex: Index);
      if ( ModelOcclusionResult > 1 && v17 > idMath::FLT_SMALLEST_NON_DENORMAL )
      {
        LODWORD(v19) = ModelOcclusionResult;
        v130 = v19;
        v21 = (float)((float)v19 / (float)v17);
        if ( v21 >= 0.0 )
        {
          if ( v21 <= 1.0 )
            v9 = (float)((float)v19 / (float)v17);
          else
            v9 = 1.0;
        }
      }
      RenderParmBlock = idRenderModel::GetRenderParmBlock(this: v16);
      idParmState::VirtualEvaluateParmBlock(
        this: renderThreadParmState,
        localParmBlock: RenderParmBlock,
        parmBlock: RenderParmBlock);
      v23 = &renderThreadParmState->values[rp->Color->parmIndex];
      v10 = v23->value[0];
      v11 = v23->value[1];
      v12 = v23->value[2];
      v13 = v23->value[3];
      v24 = idRenderModel::GetRenderParmBlock(this: v16);
      idParmState::VirtualRollbackParmBlock(this: renderThreadParmState, localParmBlock: v24, parmBlock: v24);
    }
  }
  useDeferredPosition = this->useDeferredPosition;
  p_deferredOrigin = (idRenderModelParms *)&this->deferredOrigin;
  if ( !this->useDeferredPosition )
    p_deferredOrigin = &this->g;
  v27 = (float)(currentView->r.vieworg.y - p_deferredOrigin->origin.y);
  v28 = (float)(currentView->r.vieworg.z - p_deferredOrigin->origin.z);
  v129.x = currentView->r.vieworg.x - p_deferredOrigin->origin.x;
  v129.y = v27;
  v129.z = v28;
  v29 = idVec3::NormalizeFast(this: &v129);
  v30 = v29;
  v31 = 1.0;
  if ( !this->isSunFlare
    && (float)(this->g.maxVisibleRange - this->g.fadeVisibilityOver) > (double)idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    v31 = (float)((float)1.0
                - (float)((float)((float)v29 - this->g.fadeVisibilityOver)
                        / (float)(this->g.maxVisibleRange - this->g.fadeVisibilityOver)));
    if ( v31 >= 0.0 )
    {
      if ( v31 > 1.0 )
        v31 = 1.0;
    }
    else
    {
      v31 = 0.0;
    }
  }
  v32 = (float)((float)v31 * (float)v9);
  if ( v32 <= 0.0 )
  {
    v33 = 0;
    if ( *p_num > 0 )
    {
      v34 = 0;
      do
      {
        ++v33;
        v35 = &this->surfaces.list[v34++];
        v35->geometry->numVerts = 0;
        v35->geometry->numIndexes = 0;
      }
      while ( v33 < *p_num );
      return 0;
    }
    return 0;
  }
  p_viewaxis = (idMat3 *)&v129;
  if ( (*((_BYTE *)*p_flareDecl + 80) & 0x80) == 0 )
    p_viewaxis = &currentView->r.viewaxis;
  p_deferredAxis = &this->deferredAxis;
  if ( !useDeferredPosition )
    p_deferredAxis = &this->g.axis;
  v39 = __fabs((float)((float)(p_viewaxis->mat[0].x * p_deferredAxis->mat[0].x)
                     + (float)((float)(p_deferredAxis->mat[0].z * p_viewaxis->mat[0].z)
                             + (float)(p_deferredAxis->mat[0].y * p_viewaxis->mat[0].y))));
  v40 = idRenderModel::GetRenderParmBlock(this);
  idParmState::VirtualEvaluateParmBlock(this: renderThreadParmState, localParmBlock: v40, parmBlock: v40);
  v41 = &renderThreadParmState->values[rp->Color->parmIndex];
  v42 = renderThreadParmState->values[rp->coverage->parmIndex].value[0];
  v43 = renderThreadParmState->values[rp->lightScale->parmIndex].value[0];
  v123 = v41->value[0];
  v125 = v41->value[1];
  v126 = v41->value[2];
  v127 = v41->value[3];
  v44 = idRenderModel::GetRenderParmBlock(this);
  idParmState::VirtualRollbackParmBlock(this: renderThreadParmState, localParmBlock: v44, parmBlock: v44);
  v45 = (float)(v123 * (float)v10);
  v46 = *p_flareDecl;
  v47 = (float)(v127 * (float)v13);
  v48 = (float)((float)v42 * (float)v32);
  v49 = (float)(v125 * (float)v11);
  v50 = (float)(v126 * (float)v12);
  v51 = v45;
  if ( (*p_flareDecl)->viewAngleFade > (double)idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    _FP13 = (float)((float)((float)v39 / (*p_flareDecl)->viewAngleFade) - (float)1.0);
    __asm { fsel      f12, f13, f31, f0 }
    v48 = (float)((float)_FP12 * (float)v48);
  }
  if ( (float)((float)1.0 - v46->invViewAngleFade) > (double)idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    _FP13 = (float)((float)v39 - (*p_flareDecl)->invViewAngleFade);
    __asm { fsel      f11, f13, f13, f25 }
    v48 = (float)((float)((float)_FP11 / (float)((float)1.0 - (*p_flareDecl)->invViewAngleFade)) * (float)v48);
  }
  brightness = v46->brightness;
  viewMatrix = currentView->viewMatrix;
  if ( this->isSunFlare )
  {
    viewMatrix.m[3] = 0.0;
    viewMatrix.m[7] = 0.0;
    viewMatrix.m[11] = 0.0;
  }
  memcpy(Dst: v155, Src: &currentView->projectionMatrix, Size: 0x40u);
  p_g = (idRenderModelParms *)&this->deferredOrigin;
  v58 = (float)((float)(v155[0].m[5] / v155[0].m[0]) * (float)0.5625);
  if ( !this->useDeferredPosition )
    p_g = &this->g;
  idRenderMatrix::TransformModelToClip(
    src: &p_g->origin,
    modelMatrix: &viewMatrix,
    projectionMatrix: v155,
    eye: &v154,
    clip: &v151);
  x = v151.x;
  y = v151.y;
  if ( __fabs(v151.w) > idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    x = (float)(v151.x * (float)((float)1.0 / v151.w));
    y = (float)(v151.y * (float)((float)1.0 / v151.w));
  }
  idDeclRenderParm::Set(
    this: (idDeclRenderParm *)rp_flareOriginNDC.r,
    x: (float)((float)((float)x + (float)1.0) * (float)0.5),
    y: (float)((float)((float)y + (float)1.0) * (float)0.5),
    z: 0.0,
    w: 0.0);
  v61 = 0;
  v122 = 0;
  if ( *p_num > 0 )
  {
    v128 = 0;
    v62 = 0;
    v63 = 0;
    HIDWORD(v130) = &globalImages;
    _R29 = 16;
    _R25 = &`VertexColorToByteWithScale'::`2'::SIMD_SP_255;
    do
    {
      flareDecl = this->flareDecl;
      v67 = (const idMaterial **)((char *)&this->surfaces.list->material + v62);
      if ( v61 < flareDecl->subflares.num )
      {
        if ( idRenderModelFlare::vertOffset + 4 <= 1024 )
        {
          v68 = v67[4];
          v69 = &flareDecl->subflares.list[v63];
          p_mtr = &v69->mtr;
          *v67 = v69->mtr;
          *((_DWORD *)&v68->idResource + 8) = 4;
          v67[4]->staleCount = 6;
          idVertexBuffer::Reference(
            this: (idVertexBuffer *)&v67[4]->parmBlock.constants,
            other: &idRenderModelFlare::vertexBuffer[idRenderModelFlare::mappedBufferIndex]);
          idIndexBuffer::Reference(
            this: (idIndexBuffer *)&v67[4]->parmBlock.thread,
            other: &idRenderModelFlare::indexBuffer,
            refOffset: 12 * (idRenderModelFlare::vertOffset >> 2),
            refSize: 12);
          __asm { vspltisw128 v63, 0 }
          _R6 = &v136;
          v51 = (float)((float)v51 * (float)v43);
          _R5 = &v136;
          v49 = (float)((float)v49 * (float)v43);
          _R4 = v142;
          v50 = (float)((float)v50 * (float)v43);
          __asm { vor128    v62, v95, v63 }
          _R3 = v142;
          __asm { vor128    v61, v95, v63 }
          _R11 = &v145;
          __asm { vor128    v60, v95, v63 }
          _R10 = &v145;
          __asm { vcmpequw128 v56, v95, v63 }
          _R9 = v150;
          __asm
          {
            vcmpequw128 v59, v94, v62
            stvx128   v62, r0, r6
            vcmpequw128 v58, v93, v61
          }
          _R6 = v135;
          __asm { vcmpequw128 v57, v92, v60 }
          _R8 = v150;
          __asm { vsldoi128 v52, v95, v56, 4 }
          __asm
          {
            vsldoi128 v55, v94, v59, 4
            vsldoi128 v54, v93, v58, 4
            vsldoi128 v53, v92, v57, 4
            stvx128   v55, r5, r29
            stvx128   v61, r0, r4
            stvx128   v54, r3, r29
            stvx128   v60, r0, r11
            stvx128   v53, r10, r29
            stvx128   v63, r0, r9
            stvx128   v52, r8, r29
          }
          v81 = v69->color.y;
          z = v69->color.z;
          v124 = v69->color.x * (float)brightness;
          v135[3] = (float)(v69->color.w * (float)v48) * (float)v47;
          v135[2] = (float)(z * (float)brightness) * (float)v50;
          __asm { lvx128    v63, r0, r25 }
          v135[0] = v124 * (float)v51;
          v135[1] = (float)(v81 * (float)brightness) * (float)v49;
          _R11 = &v141;
          _R9 = -2;
          v85 = 4;
          _R8 = -1;
          _R10 = 1;
          __asm
          {
            lvx128    v51, r0, r6
            vmulfp128 v50, v83, v63
            vcfpsxws128 v63, v50, 0
          }
          do
          {
            __asm
            {
              vor128    v49, v95, v63
              vpkswss128 v48, v81, v49
              vpkshus128 v0, v80, v48
              stvebx    v0, r11, r9
              stvebx    v0, r11, r8
              stvebx    v0, 0, r11
              stvebx    v0, r11, r10
            }
            _R11 += 32;
            --v85;
          }
          while ( v85 != 0 );
          v88 = 0.0;
          v89 = 0.0;
          *(float *)&v90 = (*p_mtr)->atlasScaleBias.x;
          v91 = (*p_mtr)->atlasScaleBias.y;
          v92 = (*p_mtr)->atlasScaleBias.z;
          v93 = *((_BYTE *)*p_mtr + 72);
          w = (*p_mtr)->atlasScaleBias.w;
          v131 = *(float *)&v90;
          v132 = v91;
          v133 = v92;
          if ( (v93 & 4) != 0 )
          {
            *(_QWORD *)&v129.x = *(_QWORD *)(*(_DWORD *)(*(_DWORD *)HIDWORD(v130) + 20) + 20);
            LODWORD(v90) = LODWORD(v129.x);
            v152 = v90;
            v89 = (float)((float)0.5 / (float)((float)*(__int64 *)&v129.x * v91));
            v88 = (float)((float)0.5 / (float)((float)v90 * v131));
          }
          v94 = (float)((float)1.0 - v69->coneAngle);
          _FP2 = (float)((float)v9 - v69->minScaleX);
          _FP1 = (float)((float)v9 - v69->minScaleY);
          v139 = (float)(v131 * (float)v88) + v133;
          v140 = (float)(v91 * (float)v89) + w;
          v144 = v140;
          v148 = v139;
          v149 = (float)((float)((float)1.0 - (float)v89) * v91) + w;
          v150[4] = v149;
          v97 = 1.0;
          v143 = (float)((float)((float)1.0 - (float)v88) * v131) + v133;
          v150[3] = v143;
          __asm
          {
            fsel      f11, f2, f23, f5
            fsel      f9, f1, f23, f4
          }
          if ( __fabs(v94) > idMath::FLT_SMALLEST_NON_DENORMAL )
          {
            _FP13 = (float)((float)v39 - v69->coneAngle);
            __asm { fsel      f8, f13, f13, f25 }
            v97 = (float)((float)_FP8 / (float)((float)1.0 - v69->coneAngle));
          }
          _FP13 = 1.0;
          v103 = (float)((float)((float)(v69->viewScaleX - (float)1.0) * (float)v97) + (float)1.0);
          v104 = (float)((float)((float)(v69->viewScaleY - (float)1.0) * (float)v97) + (float)1.0);
          if ( __fabs(v69->scaleDistance) > idMath::FLT_SMALLEST_NON_DENORMAL )
          {
            _FP8 = (float)((float)(v69->scaleDistance - (float)v30) / v69->scaleDistance);
            __asm { fsel      f13, f8, f8, f25 }
          }
          v106 = (float)((float)((float)((float)((float)(v69->maxDistScaleX - (float)1.0) * (float)_FP13) + (float)1.0)
                               * (float)v103)
                       * (float)_FP11);
          v108 = (float)((float)((float)((float)((float)((float)((float)(v69->maxDistScaleY - (float)1.0) * (float)_FP13)
                                                       + (float)1.0)
                                               * (float)v104)
                                       * (float)_FP9)
                               * v69->height)
                       * (float)v58);
          v107 = (float)((float)v106 * v69->width);
          if ( v69->reflectX )
            v109 = -1.0;
          else
            v109 = 1.0;
          if ( v69->reflectY )
            v110 = -1.0;
          else
            v110 = 1.0;
          position = v69->position;
          v138 = 0.0;
          v142[2] = 0.0;
          _R11 = &idRenderModelFlare::mappedVertices[idRenderModelFlare::vertOffset];
          v147 = 0.0;
          v150[2] = 0.0;
          v113 = 4;
          _R9 = (char *)((char *)&v136 - (char *)_R11);
          v115 = -(float)((float)x * (float)v109);
          _R10 = (char *)((char *)&v140 - (char *)_R11);
          v117 = -(float)((float)y * (float)v110);
          _R8 = 16;
          v136 = (float)((float)((float)v115 * (float)position) + (float)x) - (float)v107;
          v137 = (float)((float)((float)v117 * (float)position) + (float)y) + (float)v108;
          v142[0] = (float)((float)((float)v115 * (float)position) + (float)x) + (float)v107;
          v142[1] = v137;
          v145 = v136;
          v146 = (float)((float)((float)v117 * (float)position) + (float)y) - (float)v108;
          v150[0] = v142[0];
          v150[1] = v146;
          do
          {
            __asm
            {
              lvx128    v47, r9, r11
              stvx128   v47, r0, r11
              lvx128    v46, r10, r11
              stvx128   v46, r11, r8
            }
            ++_R11;
            --v113;
          }
          while ( v113 != 0 );
          v61 = v122;
          v62 = v128;
          idRenderModelFlare::vertOffset += 4;
        }
      }
      else
      {
        *((_DWORD *)&v67[4]->idResource + 8) = 0;
        v67[4]->staleCount = 0;
      }
      ++v61;
      v62 += 56;
      v122 = v61;
      v128 = v62;
      ++v63;
    }
    while ( v61 < this->surfaces.num );
  }
  idRenderModel::CommitSurfaces(this);
  return 1;
}


// ========================================================================
// ?Save@idRenderModelFlare@@EBAXPAVidFile@@@Z
// EA  : 0x827D4598
// RVA : 0x007D4598
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void __fastcall idRenderModelFlare::Save(idRenderModelFlare *this, idFile *fp)
{
  const idDeclFlare *flareDecl; // r11
  const char *str; // r4

  idRenderModel::Save(this, fp);
  flareDecl = this->flareDecl;
  if ( flareDecl != nullptr )
    str = flareDecl->name.str;
  else
    str = &byte_8200D768;
  idFile::WriteString(this: fp, string: str);
  fp->Write(this: fp, a2: &this->isSunFlare, a3: 1u);
  fp->Write(this: fp, a2: &this->quadModelIndex, a3: 4u);
}


// ========================================================================
// ?Load@idRenderModelFlare@@EAA_NPAVidFile@@@Z
// EA  : 0x827D4638
// RVA : 0x007D4638
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

int __fastcall idRenderModelFlare::Load(idRenderModelFlare *this, idFile *fp)
{
  const idDeclFlare *v5; // r3
  idStr v6[2]; // [sp+50h] [-50h] BYREF

  if ( !idRenderModel::Load(this, fp) )
    return 0;
  v6[0].len = 0;
  v6[0].allocedAndFlag = 20;
  v6[0].data = v6[0].baseBuffer;
  v6[0].baseBuffer[0] = 0;
  if ( idFile::ReadString(this: fp, string: v6) == 0 )
  {
    idStr::FreeData(this: v6);
    return 0;
  }
  if ( v6[0].len != 0 )
  {
    if ( v6[0].data != nullptr )
      v5 = (const idDeclFlare *)idDeclInfo::FindWithInheritance(
                                  this: &idDeclFlare::resourceList,
                                  name: v6[0].data,
                                  makeDefault: true);
    else
      v5 = nullptr;
    this->flareDecl = v5;
  }
  else
  {
    this->flareDecl = nullptr;
  }
  if ( fp->Read(this: fp, a2: &this->isSunFlare, a3: 1u) != 0
    && fp->Read(this: fp, a2: &this->quadModelIndex, a3: 4u) != 0 )
  {
    idStr::FreeData(this: v6);
    return 1;
  }
  else
  {
    idStr::FreeData(this: v6);
    return 0;
  }
}


// ========================================================================
// __unwind$233063_0
// EA  : 0x827D4758
// RVA : 0x007D4758
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void _unwind_233063_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Init@idRenderModelFlareOcclusionQuad@@SAXXZ
// EA  : 0x827D4788
// RVA : 0x007D4788
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
static void __fastcall idRenderModelFlareOcclusionQuad::Init()
{
  char *v0; // r4
  int v1; // r10
  char *v2; // r11
  int i; // ctr
  char *v4; // r3
  int v10; // ctr
  void *v56; // [sp+68h] [-238h]
  __int64 v57; // [sp+70h] [-230h]
  __int64 v58; // [sp+78h] [-228h]
  __int64 v59; // [sp+80h] [-220h]
  __int64 v60; // [sp+88h] [-218h]
  __int64 v61; // [sp+90h] [-210h] BYREF
  int v62; // [sp+A0h] [-200h] BYREF
  int v63; // [sp+B0h] [-1F0h] BYREF
  int v64; // [sp+C0h] [-1E0h] BYREF
  int v65; // [sp+D0h] [-1D0h] BYREF
  int v66; // [sp+E0h] [-1C0h] BYREF
  int v67; // [sp+F0h] [-1B0h] BYREF
  int v68; // [sp+100h] [-1A0h] BYREF
  int v69; // [sp+110h] [-190h] BYREF
  int v70; // [sp+120h] [-180h] BYREF
  int v71; // [sp+130h] [-170h] BYREF
  int v72; // [sp+140h] [-160h] BYREF
  int v73; // [sp+150h] [-150h] BYREF
  int v74; // [sp+160h] [-140h] BYREF
  int v75; // [sp+170h] [-130h] BYREF
  int v76; // [sp+180h] [-120h] BYREF
  int v77; // [sp+190h] [-110h] BYREF
  int v78; // [sp+1A0h] [-100h] BYREF
  int v79; // [sp+1B0h] [-F0h] BYREF
  int v80; // [sp+1C0h] [-E0h] BYREF
  int v81; // [sp+1D0h] [-D0h] BYREF
  int v82; // [sp+1E0h] [-C0h] BYREF
  int v83; // [sp+1F0h] [-B0h] BYREF

  idVertexBuffer::AllocBufferObject(
    this: &idRenderModelFlareOcclusionQuad::vertexBuffer,
    data: nullptr,
    allocSize: 0x8000,
    vertexMask: 31,
    allocUsage: BU_DYNAMIC);
  v0 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                 size: 0xC00u,
                 tag: TAG_TEMP,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v56 = v0;
  v1 = 2;
  v2 = v0 - 2;
  for ( i = 256; i != 0; --i )
  {
    *((_WORD *)v2 + 1) = v1 - 2;
    *((_WORD *)v2 + 2) = v1 - 1;
    *((_WORD *)v2 + 3) = v1;
    *((_WORD *)v2 + 4) = v1 - 2;
    *((_WORD *)v2 + 5) = v1;
    v2 += 12;
    *(_WORD *)v2 = v1 + 1;
    v1 += 4;
  }
  idIndexBuffer::AllocBufferObject(
    this: &idRenderModelFlareOcclusionQuad::indexBuffer,
    data: v0,
    allocSize: 3072,
    allocUsage: BU_DYNAMIC);
  v4 = (char *)idVertexBuffer::MapBuffer(this: &idRenderModelFlareOcclusionQuad::vertexBuffer, mapType: BM_WRITE);
  __asm { vspltisw128 v61, 0 }
  _R7 = &_real_00000000;
  _R9 = &_real_3f800000;
  _R8 = &v61;
  __asm { vor128    v59, v93, v61 }
  __asm { lvlx128   v63, r0, r7 }
  _R11 = (float *)(v4 + 40);
  v10 = 256;
  __asm { lvlx128   v62, r0, r9 }
  __asm { stvx128   v62, r0, r8 }
  HIDWORD(_R10) = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
  LODWORD(_R10) = idRenderModelFlareOcclusionQuad::points;
  __asm { vrlimi128 v59, v62, 8, 0 }
  _R8 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
  _R7 = &_vmx_3f8000003f8000003f8000003f800000;
  _R4 = 0x5000000051LL;
  _R6 = 0x52000000FFLL;
  do
  {
    __asm { vor128    v60, v93, v61 }
    *(_R11 - 10) = *(float *)_R10;
    __asm
    {
      vor128    v58, v93, v61
      vor128    v57, v93, v61
    }
    _R30 = &v82;
    _R29 = &v64;
    v61 = _R10;
    __asm { vrlimi128 v60, v63, 8, 0 }
    _R28 = &v74;
    __asm { vrlimi128 v58, v63, 8, 0 }
    _R27 = &v66;
    __asm { vrlimi128 v57, v63, 8, 0 }
    _R26 = &v62;
    _R25 = &v68;
    __asm
    {
      stvx128   v63, r0, r30
      vrlimi128 v60, v63, 4, 3
    }
    _R24 = &v76;
    _R23 = &v70;
    __asm { vrlimi128 v58, v63, 4, 3 }
    _R22 = &v80;
    __asm { vrlimi128 v57, v63, 4, 3 }
    _R21 = &v72;
    __asm
    {
      stvx128   v63, r0, r29
      vor128    v56, v92, v60
    }
    _R29 = &v78;
    _R20 = -19;
    __asm { vrlimi128 v58, v62, 2, 2 }
    _R19 = -18;
    __asm { vrlimi128 v57, v62, 2, 2 }
    _R18 = 12;
    __asm
    {
      stvx128   v62, r0, r28
      vrlimi128 v56, v62, 2, 2
    }
    _R17 = 13;
    _R16 = 14;
    __asm { stvx128   v63, r0, r27 }
    _R15 = 44;
    __asm { stvx128   v63, r0, r26 }
    _R14 = 45;
    __asm
    {
      stvx128   v62, r0, r25
      stvx128   v63, r0, r24
    }
    _R30 = -20;
    *(_R11 - 9) = *(float *)(_R10 + 4);
    *(_R11 - 8) = *(float *)(_R10 + 8);
    *(_R11 - 2) = *(float *)(_R10 + 12);
    *(_R11 - 1) = *(float *)(_R10 + 16);
    *_R11 = *(float *)(_R10 + 20);
    _R11[6] = *(float *)(_R10 + 24);
    _R11[7] = *(float *)(_R10 + 28);
    _R11[8] = *(float *)(_R10 + 32);
    _R11[14] = *(float *)(_R10 + 36);
    _R11[15] = *(float *)(_R10 + 40);
    _R11[16] = *(float *)(_R10 + 44);
    LODWORD(_R10) = 46;
    *(_R11 - 7) = 0.0;
    *(_R11 - 6) = 0.0;
    _R11[1] = 1.0;
    _R11[2] = 0.0;
    _R11[9] = 1.0;
    _R11[10] = 1.0;
    _R11[17] = 0.0;
    _R11[18] = 1.0;
    __asm
    {
      lvx128    v0, r0, r8
      lvx128    v13, r0, r9
      lvx128    v60, r0, r7
      vaddfp128 v12, v88, v60
      stvx128   v63, r0, r23
      vmaddfp   v0, v12, v0, v13
      stvx128   v62, r0, r22
      stvx128   v63, r0, r21
      vcfpsxws128 v51, v0, 0
    }
    _R28 = &v63;
    _R27 = &v65;
    __asm { vor128    v55, v93, v61 }
    _R26 = &v67;
    v58 = *(__int64 *)((char *)&_R4 + 4);
    _R25 = &v69;
    __asm { vor128    v54, v93, v61 }
    _R24 = &v71;
    __asm
    {
      vor128    v53, v93, v61
      vrlimi128 v55, v63, 8, 0
    }
    __asm { vor128    v52, v93, v61 }
    v59 = _R6;
    __asm { vrlimi128 v54, v62, 8, 0 }
    v57 = *(__int64 *)((char *)&_R6 + 4);
    __asm { vrlimi128 v55, v63, 4, 3 }
    __asm { vrlimi128 v53, v62, 8, 0 }
    HIDWORD(_R4) = 48;
    __asm { vrlimi128 v52, v62, 8, 0 }
    v60 = _R4;
    __asm { vpkswss128 v50, v83, v51 }
    __asm { vrlimi128 v55, v62, 2, 2 }
    __asm { vrlimi128 v54, v63, 4, 3 }
    _R23 = 77;
    __asm { vrlimi128 v53, v63, 4, 3 }
    __asm
    {
      vpkshus128 v0, v82, v50
      vrlimi128 v52, v63, 4, 3
    }
    _R22 = 78;
    _R21 = -16;
    __asm { vrlimi128 v54, v63, 2, 2 }
    _R6 = -15;
    __asm { vrlimi128 v53, v63, 2, 2 }
    __asm { vrlimi128 v52, v63, 2, 2 }
    __asm { stvebx    v0, r11, r30 }
    _R30 = &v73;
    __asm
    {
      stvebx    v0, r11, r20
      stvebx    v0, r11, r19
      lvx128    v0, r0, r8
      lvx128    v60, r0, r7
      vaddfp128 v12, v90, v60
      lvx128    v13, r0, r9
      vmaddfp   v0, v12, v0, v13
      vcfpsxws128 v49, v0, 0
      vpkswss128 v48, v81, v49
      vpkshus128 v0, v80, v48
      stvebx    v0, r11, r18
      stvebx    v0, r11, r17
      stvebx    v0, r11, r16
      lvx128    v13, r0, r9
      lvx128    v0, r0, r8
      lvx128    v60, r0, r7
      vaddfp128 v12, v89, v60
      vmaddfp   v0, v12, v0, v13
      vcfpsxws128 v47, v0, 0
      vpkswss128 v46, v79, v47
      vpkshus128 v0, v78, v46
      stvebx    v0, r11, r15
      stvebx    v0, r11, r14
      stvebx    v0, r11, r10
      lvx128    v0, r0, r8
      lvx128    v13, r0, r9
      lvx128    v60, r0, r7
      vaddfp128 v12, v87, v60
      stvx128   v63, r0, r29
    }
    _R29 = &v75;
    __asm
    {
      stvx128   v62, r0, r28
      vmaddfp   v0, v12, v0, v13
      stvx128   v62, r0, r27
      stvx128   v63, r0, r26
      stvx128   v63, r0, r25
      stvx128   v62, r0, r24
      vcfpsxws128 v44, v0, 0
    }
    _R28 = &v77;
    _R27 = &v79;
    __asm { stvx128   v63, r0, r30 }
    _R26 = &v81;
    __asm { stvx128   v63, r0, r29 }
    _R25 = &v83;
    __asm { vor128    v45, v91, v59 }
    _R30 = 76;
    __asm
    {
      stvx128   v62, r0, r28
      stvx128   v63, r0, r27
      stvx128   v63, r0, r26
      vrlimi128 v45, v63, 4, 3
      stvx128   v63, r0, r25
      vrlimi128 v45, v63, 2, 2
      vpkswss128 v43, v76, v44
      vpkshus128 v0, v75, v43
      stvebx    v0, r11, r30
    }
    _R30 = 17;
    __asm
    {
      stvebx    v0, r11, r23
      stvebx    v0, r11, r22
      lvx128    v13, r0, r9
      lvx128    v0, r0, r8
      lvx128    v60, r0, r7
      vaddfp128 v12, v86, v60
      vmaddfp   v0, v12, v0, v13
      vcfpsxws128 v42, v0, 0
      vpkswss128 v41, v74, v42
      vpkshus128 v0, v73, v41
      stvebx    v0, r11, r21
      stvebx    v0, r11, r6
    }
    _R6 = v59;
    __asm { stvebx    v0, r11, r5 }
    *(__int64 *)((char *)&_R6 + 4) = v57;
    __asm
    {
      lvx128    v13, r0, r9
      lvx128    v60, r0, r7
      vaddfp128 v12, v85, v60
      lvx128    v0, r0, r8
      vmaddfp   v0, v12, v0, v13
      vcfpsxws128 v40, v0, 0
      vpkswss128 v39, v72, v40
      vpkshus128 v0, v71, v39
      stvebx    v0, r11, r4
    }
    _R4 = v60;
    __asm { stvebx    v0, r11, r30 }
    _R30 = 18;
    __asm { stvebx    v0, r11, r30 }
    _R30 = 48;
    __asm
    {
      lvx128    v60, r0, r7
      vaddfp128 v12, v84, v60
      lvx128    v0, r0, r8
      lvx128    v13, r0, r9
      vmaddfp   v0, v12, v0, v13
      vcfpsxws128 v38, v0, 0
      vpkswss128 v37, v70, v38
      vpkshus128 v0, v69, v37
      stvebx    v0, r11, r30
    }
    _R30 = 49;
    __asm
    {
      stvebx    v0, r11, r30
      stvebx    v0, r11, r3
    }
    *(__int64 *)((char *)&_R4 + 4) = v58;
    __asm
    {
      lvx128    v0, r0, r8
      lvx128    v13, r0, r9
      lvx128    v60, r0, r7
      vaddfp128 v12, v77, v60
      vmaddfp   v0, v12, v0, v13
      vcfpsxws128 v36, v0, 0
      vpkswss128 v35, v68, v36
      vpkshus128 v0, v67, v35
      stvebx    v0, r11, r3
      stvebx    v0, r11, r4
      stvebx    v0, r11, r5
    }
    *((_BYTE *)_R11 - 13) = v59;
    *((_BYTE *)_R11 + 19) = v59;
    *((_BYTE *)_R11 + 51) = v59;
    *((_BYTE *)_R11 + 83) = v59;
    *((_BYTE *)_R11 - 9) = v59;
    *((_BYTE *)_R11 - 10) = v59;
    *((_BYTE *)_R11 - 11) = v59;
    *((_BYTE *)_R11 - 12) = v59;
    _R11 += 32;
    _R10 = v61;
    --v10;
  }
  while ( v10 != 0 );
  idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&idRenderModelFlareOcclusionQuad::vertexBuffer);
  idRenderModelFlareOcclusionQuad::vertOffset = 0;
  if ( v56 != nullptr )
    idMem::Free(this: &mem, ptr: v56, align: ALIGN_16);
}


// ========================================================================
// __unwind$233163
// EA  : 0x827D4CEC
// RVA : 0x007D4CEC
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void _unwind_233163()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 672 + 104));
}


// ========================================================================
// ?UpdateInView@idRenderModelFlareOcclusionQuad@@MAA_NPBVidRenderView@@0PAVidRenderModelUpdateTools@@@Z
// EA  : 0x827D4D20
// RVA : 0x007D4D20
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

int __fastcall idRenderModelFlareOcclusionQuad::UpdateInView(
        idRenderModelFlareOcclusionQuad *this,
        const idRenderView *currentView,
        const idRenderView *nextView,
        idRenderModelUpdateTools *updateTools)
{
  int valueInteger; // r29
  idRenderModelSurface *list; // r11
  idTriangles *geometry; // r11
  double v10; // fp31
  double v11; // fp30
  int Index; // r3
  __int64 v13; // r11
  int ModelOcclusionResult; // r3
  double v15; // fp0
  idMat3 *v16; // r11
  double v17; // fp12
  double v18; // fp11
  double v19; // fp10
  idRenderModelParms *p_deferredOrigin; // r25
  float *p_deferredAxis; // r30
  int v22; // r27
  idVec3 *v23; // r29
  double x; // fp0
  float z; // r10
  double y; // fp13
  float v27; // r9
  double v28; // fp12
  double v29; // fp10
  double v30; // fp11
  double v31; // fp8
  double v32; // fp30
  double v33; // fp1
  double v34; // fp10
  double v35; // fp9
  idRenderWorld *World; // r19
  __int64 v37; // r6
  __int64 v38; // r10
  __int64 v39; // r8
  va *v40; // r3
  idRenderWorld *v41; // r29
  idRenderModelParms *p_g; // r30
  __int64 v43; // r6
  __int64 v44; // r10
  __int64 v45; // r8
  va *v46; // r3
  idRenderWorld *v47; // r3
  idRenderWorld *v48; // r3
  idMat3 *p_axis; // r5
  idRenderModelParms *v50; // r4
  int v52; // [sp+8h] [-1128h]
  int v53; // [sp+Ch] [-1124h]
  int v54; // [sp+10h] [-1120h]
  int v55; // [sp+14h] [-111Ch]
  int v56; // [sp+18h] [-1118h]
  int v57; // [sp+1Ch] [-1114h]
  idVec3 v58; // [sp+60h] [-10D0h] BYREF
  float v59; // [sp+70h] [-10C0h] BYREF
  float v60; // [sp+74h] [-10BCh]
  float v61; // [sp+78h] [-10B8h]
  float v62; // [sp+7Ch] [-10B4h]
  idWinding v63; // [sp+80h] [-10B0h] BYREF
  __int64 v64; // [sp+90h] [-10A0h]
  va v65; // [sp+A0h] [-1090h] BYREF

  if ( r_skipFlares.valueInteger == 0 )
  {
    valueInteger = r_singleFlareModel.valueInteger;
    if ( r_singleFlareModel.valueInteger < 0 || valueInteger == idRenderModel::GetIndex(this) )
    {
      this->currentIdx ^= 1u;
      this->screenSpaceArea[this->currentIdx] = idRenderModelFlareOcclusionQuad::CalcScreenSpaceAreaForView(
                                                  this,
                                                  currentView,
                                                  nextView);
      if ( this->surfaces.num > 0 )
      {
        list = this->surfaces.list;
        if ( list != nullptr )
        {
          geometry = list->geometry;
          if ( geometry != nullptr )
          {
            idIndexBuffer::Reference(
              this: &geometry->indexBuffer,
              other: &idRenderModelFlareOcclusionQuad::indexBuffer,
              refOffset: 12 * (idRenderModelFlareOcclusionQuad::vertOffset >> 2),
              refSize: 12);
            idRenderModelFlareOcclusionQuad::vertOffset += 4;
          }
        }
      }
      if ( r_debugFlareOcclusionQuad.valueInteger == 0 )
        goto _M233931;
      v10 = 0.0;
      v59 = 1.0;
      v60 = 0.0;
      v61 = 1.0;
      v62 = 1.0;
      if ( r_debugFlareOcclusionQuad.valueInteger == 2 )
      {
        v11 = this->screenSpaceArea[this->currentIdx ^ 1];
        Index = idRenderModel::GetIndex(this);
        ModelOcclusionResult = idRenderView::GetModelOcclusionResult(this: currentView, modelIndex: Index);
        if ( ModelOcclusionResult > 1 && v11 > 0.0 )
        {
          LODWORD(v13) = ModelOcclusionResult;
          v64 = v13;
          v15 = (float)((float)v13 / (float)v11);
          if ( v15 >= 0.0 )
          {
            if ( v15 > 1.0 )
            {
              v59 = 1.0;
              v60 = 1.0;
              v61 = 1.0;
              goto LABEL_21;
            }
            v10 = (float)((float)v13 / (float)v11);
          }
        }
        v59 = v10;
        v60 = v10;
        v61 = v10;
        goto LABEL_21;
      }
      if ( r_debugFlareOcclusionQuad.valueInteger != 3 )
      {
LABEL_22:
        p_deferredOrigin = (idRenderModelParms *)&this->deferredOrigin;
        if ( this->useDeferredPosition )
        {
          p_deferredAxis = (float *)&this->deferredAxis;
        }
        else
        {
          p_deferredOrigin = &this->g;
          p_deferredAxis = (float *)&this->g.axis;
        }
        memset(&v63.numPoints, 0, 12);
        v63.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
        idWinding::ReAllocate(this: &v63, n: 4, keep: false);
        v22 = 0;
        v23 = idRenderModelFlareOcclusionQuad::points;
        do
        {
          x = this->g.scale.x;
          z = v23->z;
          y = this->g.scale.y;
          v27 = v23->x;
          v28 = this->g.scale.z;
          v29 = p_deferredAxis[1];
          v30 = p_deferredAxis[5];
          v58.y = v23->y;
          v58.z = z;
          v58.x = v27;
          v31 = p_deferredOrigin->origin.z;
          v32 = p_deferredOrigin->origin.x;
          v33 = (float)((float)(p_deferredAxis[4] * (float)(v58.y * (float)y))
                      + (float)((float)v29 * (float)(v27 * (float)x)));
          v34 = (float)((float)((float)(z * (float)v28) * p_deferredAxis[8])
                      + (float)((float)(p_deferredAxis[2] * (float)(v27 * (float)x))
                              + (float)((float)v30 * (float)(v58.y * (float)y))));
          v35 = (float)((float)(*p_deferredAxis * (float)(v27 * (float)x))
                      + (float)((float)((float)(v58.y * (float)y) * p_deferredAxis[3])
                              + (float)((float)(z * (float)v28) * p_deferredAxis[6])));
          v58.y = p_deferredOrigin->origin.y
                + (float)((float)(p_deferredAxis[7] * (float)(z * (float)v28)) + (float)v33);
          v58.z = (float)v31 + (float)v34;
          v58.x = (float)v32 + (float)v35;
          World = idRenderModel::GetWorld(this);
          HIDWORD(v37) = v22;
          v40 = va::va(
                  this: &v65,
                  fmt: "v%d",
                  a3: v37,
                  a4: v39,
                  a5: v38,
                  a6: v52,
                  a7: v53,
                  a8: v54,
                  a9: v55,
                  a10: v56,
                  a11: v57);
          ((void (__fastcall *)(idRenderWorld *, va *, idVec3 *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))World->DebugText)(
            a1: World,
            a2: v40,
            a3: &v58,
            a4: World->DebugText,
            a5: &idColor::colorWhite,
            a6: 1,
            a7: 0,
            a8: 0,
            a9: 0.1);
          idWinding::AddPoint(this: &v63, v: &v58);
          ++v23;
          ++v22;
        }
        while ( (int)v23 < (int)&idTypedResourceList<idFoliageModel> `RTTI Type Descriptor' );
        v41 = idRenderModel::GetWorld(this);
        p_g = (idRenderModelParms *)&this->deferredOrigin;
        if ( !this->useDeferredPosition )
          p_g = &this->g;
        HIDWORD(v43) = idRenderModel::GetIndex(this);
        v46 = va::va(
                this: &v65,
                fmt: "index%d",
                a3: v43,
                a4: v45,
                a5: v44,
                a6: v52,
                a7: v53,
                a8: v54,
                a9: v55,
                a10: v56,
                a11: v57);
        ((void (__fastcall *)(idRenderWorld *, va *, idRenderModelParms *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v41->DebugText)(
          a1: v41,
          a2: v46,
          a3: p_g,
          a4: v41->DebugText,
          a5: &idColor::colorCyan,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.2);
        v47 = idRenderModel::GetWorld(this);
        v47->DebugFilledPolygon(this: v47, a2: (const idVec4 *)&v59, a3: &v63, a4: 0, a5: true);
        v48 = idRenderModel::GetWorld(this);
        p_axis = &this->deferredAxis;
        if ( this->useDeferredPosition )
        {
          v50 = (idRenderModelParms *)&this->deferredOrigin;
        }
        else
        {
          p_axis = &this->g.axis;
          v50 = &this->g;
        }
        v48->DebugAxis_2(this: v48, a2: &v50->origin, a3: p_axis, a4: 0, a5: true);
        v63.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
        idMem::Free(this: &mem, ptr: v63.p, align: ALIGN_16);
        v63.p = nullptr;
_M233931:
        idRenderModel::CommitSurfaces(this);
        return 0;
      }
      v16 = &this->deferredAxis;
      if ( !this->useDeferredPosition )
        v16 = &this->g.axis;
      v17 = (float)(v16->mat[0].y * currentView->r.viewaxis.mat[0].y);
      v18 = v16->mat[0].z;
      v19 = currentView->r.viewaxis.mat[0].z;
      HIDWORD(v64) = &currentView->r.viewaxis;
      v59 = __fabs((float)((float)(currentView->r.viewaxis.mat[0].x * v16->mat[0].x)
                         + (float)((float)((float)v18 * (float)v19) + (float)v17)));
      v60 = v59;
      v61 = v59;
LABEL_21:
      v62 = 1.0;
      goto LABEL_22;
    }
  }
  return 0;
}


// ========================================================================
// __unwind$233654
// EA  : 0x827D51E4
// RVA : 0x007D51E4
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void _unwind_233654()
{
  int v0; // r12

  idWinding::~idWinding(this: (idWinding *)(v0 - 4400 + 128));
}


// ========================================================================
// ?SerializeSnapshot@idRenderModelFlareOcclusionQuad@@UAAXAAVidSerializer@@_N@Z
// EA  : 0x827D5210
// RVA : 0x007D5210
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void __fastcall idRenderModelFlareOcclusionQuad::SerializeSnapshot(
        idRenderModelFlareOcclusionQuad *this,
        idSerializer *ser,
        bool serializeParmBlock)
{
  idBitMsg *msg; // r3
  bool isSunFlare; // r29

  idRenderModel::SerializeSnapshot(this, ser, serializeParmBlock);
  msg = ser->msg;
  isSunFlare = this->isSunFlare;
  if ( ser->writing )
  {
    idBitMsg::WriteBits(this: msg, value: this->isSunFlare, numBits: 1);
    this->isSunFlare = isSunFlare;
  }
  else
  {
    this->isSunFlare = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  }
}


// ========================================================================
// ?Load@idRenderModelFlareOcclusionQuad@@EAA_NPAVidFile@@@Z
// EA  : 0x827D5278
// RVA : 0x007D5278
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

BOOL __fastcall idRenderModelFlareOcclusionQuad::Load(idRenderModelFlareOcclusionQuad *this, idFile *fp)
{
  return idRenderModel::Load(this, fp)
      && fp->Read(this: fp, a2: &this->isSunFlare, a3: 1u) != 0
      && fp->Read(this: fp, a2: &this->currentIdx, a3: 4u) != 0
      && fp->Read(this: fp, a2: this->screenSpaceArea, a3: 8u) != 0;
}


// ========================================================================
// ?SerializeSnapshot@idRenderModelFlare@@UAAXAAVidSerializer@@_N@Z
// EA  : 0x827D5450
// RVA : 0x007D5450
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void __fastcall idRenderModelFlare::SerializeSnapshot(
        idRenderModelFlare *this,
        idSerializer *ser,
        bool serializeParmBlock)
{
  idBitMsg *msg; // r3
  bool isSunFlare; // r29

  idRenderModel::SerializeSnapshot(this, ser, serializeParmBlock);
  idSerializer::Serialize<idDeclFlare>(this: ser, decl: &this->flareDecl);
  msg = ser->msg;
  isSunFlare = this->isSunFlare;
  if ( ser->writing )
  {
    idBitMsg::WriteBits(this: msg, value: this->isSunFlare, numBits: 1);
    this->isSunFlare = isSunFlare;
  }
  else
  {
    this->isSunFlare = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  }
}


// ========================================================================
// `dynamic initializer for 'r_skipFlares''
// EA  : 0x83342930
// RVA : 0x01342930
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipFlares__()
{
  idCVar::idCVar(
    this: &r_skipFlares,
    name: "r_skipFlares",
    value: "0",
    flags: 2,
    description: "1 = skip all flares",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&unk_82200000,
    a9: (int)&loc_827B0000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,1>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipFlares__);
}


// ========================================================================
// `dynamic initializer for 'r_singleFlareModel''
// EA  : 0x83342998
// RVA : 0x01342998
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_singleFlareModel__()
{
  idCVar::idCVar(
    this: &r_singleFlareModel,
    name: "r_singleFlareModel",
    value: "-1",
    flags: 2,
    description: "suppress all but one flare",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_singleFlareModel__);
}


// ========================================================================
// `dynamic initializer for 'r_debugFlareOcclusionQuad''
// EA  : 0x833429F0
// RVA : 0x013429F0
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_debugFlareOcclusionQuad__()
{
  idCVar::idCVar(
    this: &r_debugFlareOcclusionQuad,
    name: "r_debugFlareOcclusionQuad",
    value: "0",
    flags: 2,
    description: "display occlusion quad debug",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_debugFlareOcclusionQuad__);
}


// ========================================================================
// `dynamic initializer for 'mtrFlareDepthOnly''
// EA  : 0x83342A48
// RVA : 0x01342A48
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void _dynamic_initializer_for__mtrFlareDepthOnly__()
{
  mtrFlareDepthOnly.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &mtrFlareDepthOnly;
}


// ========================================================================
// `dynamic initializer for 'rp_flareOriginNDC''
// EA  : 0x83342A68
// RVA : 0x01342A68
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void _dynamic_initializer_for__rp_flareOriginNDC__()
{
  rp_flareOriginNDC.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_flareOriginNDC;
}


// ========================================================================
// `dynamic initializer for 'idRenderModelFlare::vertexBuffer''
// EA  : 0x83342A88
// RVA : 0x01342A88
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelFlare::vertexBuffer__()
{
  `eh vector constructor iterator'(
    ptr: (char *)idRenderModelFlare::vertexBuffer,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelFlare::vertexBuffer__);
}


// ========================================================================
// `dynamic initializer for 'idRenderModelFlare::indexBuffer''
// EA  : 0x83342AD8
// RVA : 0x01342AD8
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelFlare::indexBuffer__()
{
  idIndexBuffer::idIndexBuffer(this: &idRenderModelFlare::indexBuffer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelFlare::indexBuffer__);
}


// ========================================================================
// `dynamic initializer for 'idRenderModelFlareOcclusionQuad::vertexBuffer''
// EA  : 0x83342B10
// RVA : 0x01342B10
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelFlareOcclusionQuad::vertexBuffer__()
{
  idIndexBuffer::idIndexBuffer(this: (idIndexBuffer *)&idRenderModelFlareOcclusionQuad::vertexBuffer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelFlareOcclusionQuad::vertexBuffer__);
}


// ========================================================================
// `dynamic initializer for 'idRenderModelFlareOcclusionQuad::indexBuffer''
// EA  : 0x83342B48
// RVA : 0x01342B48
// PDB : w:\tech5\engine\models\flares\rendermodelflare.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelFlareOcclusionQuad::indexBuffer__()
{
  idIndexBuffer::idIndexBuffer(this: &idRenderModelFlareOcclusionQuad::indexBuffer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelFlareOcclusionQuad::indexBuffer__);
}

