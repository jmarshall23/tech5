
// ========================================================================
// ?InitUnitSquare@idRenderSystemLocal@@QAAXXZ
// EA  : 0x82953920
// RVA : 0x00953920
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::InitUnitSquare(idRenderSystemLocal *this)
{
  idTriangles *v3; // r3
  int v4; // r27
  idTriangles *v5; // r3
  idBounds **p_unitSquareTris; // r30
  idTriangles *unitSquareTris; // r5
  float *p_x; // r3
  int v14; // r9
  float *v17; // r11
  float *v19; // r11
  float *v20; // r11
  idDrawVert *verts; // r11
  idDrawVert *v22; // r11
  idDrawVert *v23; // r11
  idDrawVert *v24; // r11
  int v26; // r11
  _BYTE *v33; // r10
  idBounds *v34; // r21
  idBounds *v35; // r11
  idTriangles *v36; // r3
  idTriangles *v37; // r3
  idTriangles *v38; // r3
  idBounds **p_unitSquareGuiTris; // r30
  idTriangles *unitSquareGuiTris; // r7
  int v42; // r25
  float *v43; // r6
  float *v44; // r11
  float *v45; // r11
  float *v46; // r11
  idDrawVert *v47; // r11
  idDrawVert *v48; // r11
  idDrawVert *v49; // r11
  idDrawVert *v50; // r11
  unsigned int v52; // r3
  _BYTE *v53; // r11
  _BYTE *v54; // r11
  idBounds *v55; // r29
  idBounds *v56; // r11
  idTriangles *v57; // r3
  idVec4 v59; // [sp+60h] [-120h] BYREF
  _BYTE v60[16]; // [sp+70h] [-110h] BYREF
  int v61; // [sp+80h] [-100h] BYREF
  int v62; // [sp+90h] [-F0h] BYREF
  idTriangles v63; // [sp+A0h] [-E0h] BYREF

  _R12 = -192;
  __asm { stvx128   v127, r1, r12 }
  v3 = (idTriangles *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x84u,
                        tag: TAG_TRIANGLES,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v4 = 0;
  if ( v3 != nullptr )
    v5 = idTriangles::idTriangles(this: v3);
  else
    v5 = nullptr;
  this->unitSquareTris = v5;
  v5->numVerts = 4;
  p_unitSquareTris = (idBounds **)&this->unitSquareTris;
  this->unitSquareTris->numIndexes = 6;
  idTriangles::AllocStaticTriSurfVerts(this: this->unitSquareTris, numVerts: this->unitSquareTris->numVerts);
  idTriangles::AllocStaticTriSurfIndexes(this: this->unitSquareTris, numIndexes: this->unitSquareTris->numIndexes);
  _R28 = 2;
  _R26 = 1;
  *this->unitSquareTris->indexes = 3;
  this->unitSquareTris->indexes[1] = 0;
  this->unitSquareTris->indexes[2] = 2;
  this->unitSquareTris->indexes[3] = 2;
  this->unitSquareTris->indexes[4] = 0;
  this->unitSquareTris->indexes[5] = 1;
  idTriangles::UpdateIndexBuffer(this: this->unitSquareTris);
  unitSquareTris = this->unitSquareTris;
  _R20 = &_real_00000000;
  p_x = &unitSquareTris->verts->xyz.x;
  _R10 = &_real_3f800000;
  v14 = 0;
  *p_x = -1.0;
  _R24 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
  p_x[1] = -1.0;
  _R23 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
  p_x[2] = 0.0;
  v17 = &unitSquareTris->verts->xyz.x;
  _R22 = &_vmx_3f8000003f8000003f8000003f800000;
  v17[8] = 1.0;
  v17[9] = -1.0;
  v17[10] = 0.0;
  v19 = &unitSquareTris->verts->xyz.x;
  v19[16] = 1.0;
  v19[17] = 1.0;
  v19[18] = 0.0;
  v20 = &unitSquareTris->verts->xyz.x;
  v20[24] = -1.0;
  v20[25] = 1.0;
  v20[26] = 0.0;
  verts = unitSquareTris->verts;
  verts->st.x = 0.0;
  verts->st.y = 0.0;
  v22 = unitSquareTris->verts;
  v22[1].st.x = 1.0;
  v22[1].st.y = 0.0;
  v23 = unitSquareTris->verts;
  v23[2].st.x = 1.0;
  v23[2].st.y = 1.0;
  v24 = unitSquareTris->verts;
  v24[3].st.x = 0.0;
  v24[3].st.y = 1.0;
  if ( unitSquareTris->numVerts > 0 )
  {
    __asm { vspltisw128 v59, 0 }
    _R8 = v60;
    __asm { lvlx128   v62, r0, r10 }
    v26 = 0;
    __asm
    {
      lvlx128   v63, r0, r20
      vor128    v60, v91, v59
      stvx128   v62, r0, r8
      vrlimi128 v60, v62, 8, 0
    }
    do
    {
      __asm
      {
        vor128    v58, v91, v59
        lvx128    v61, r0, r22
        lvx128    v13, r0, r24
      }
      __asm { lvx128    v0, r0, r23 }
      _R8 = v60;
      _R7 = &v61;
      __asm
      {
        vor128    v57, v92, v60
        vrlimi128 v58, v63, 8, 0
      }
      _R6 = &v62;
      _R5 = &v63;
      ++v14;
      __asm
      {
        stvx128   v63, r0, r8
        vrlimi128 v57, v63, 4, 3
        vrlimi128 v58, v63, 4, 3
      }
      __asm { stvx128   v63, r0, r7 }
      _R10 = LODWORD((*p_unitSquareTris)[3].b[1].y) + v26 + 20;
      __asm
      {
        stvx128   v62, r0, r6
        stvx128   v63, r0, r5
        vrlimi128 v57, v63, 2, 2
        vrlimi128 v58, v62, 2, 2
        vaddfp128 v12, v90, v61
        vmaddfp   v0, v12, v0, v13
        vcfpsxws128 v56, v0, 0
        vpkswss128 v55, v88, v56
        vpkshus128 v0, v87, v55
        stvebx    v0, 0, r10
        stvebx    v0, r10, r26
        stvebx    v0, r10, r28
      }
      __asm
      {
        lvx128    v13, r0, r24
        lvx128    v0, r0, r23
        lvx128    v61, r0, r22
        vaddfp128 v12, v89, v61
        vmaddfp   v0, v12, v0, v13
      }
      __asm { vcfpsxws128 v54, v0, 0 }
      _R10 = LODWORD((*p_unitSquareTris)[3].b[1].y) + v26 + 24;
      __asm
      {
        vpkswss128 v53, v86, v54
        vpkshus128 v0, v85, v53
        stvebx    v0, 0, r10
        stvebx    v0, r10, r26
        stvebx    v0, r10, r28
      }
      v33 = (_BYTE *)(LODWORD((*p_unitSquareTris)[3].b[1].y) + v26);
      v33[31] = -1;
      v26 += 32;
      v33[30] = -1;
      v33[29] = -1;
      v33[28] = -1;
    }
    while ( v14 < SLODWORD((*p_unitSquareTris)[1].b[0].z) );
  }
  v34 = *p_unitSquareTris;
  v35 = idTriangles::BoundsFromVertScan(this: &v63, result: *p_unitSquareTris);
  v36 = (idTriangles *)*p_unitSquareTris;
  *v34 = *v35;
  idTriangles::UpdateVertexBuffer(this: v36);
  v37 = (idTriangles *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x84u,
                         tag: TAG_TRIANGLES,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v37 != nullptr )
    v38 = idTriangles::idTriangles(this: v37);
  else
    v38 = nullptr;
  this->unitSquareGuiTris = v38;
  v38->numVerts = 4;
  p_unitSquareGuiTris = (idBounds **)&this->unitSquareGuiTris;
  this->unitSquareGuiTris->numIndexes = 6;
  idTriangles::AllocStaticTriSurfVerts(this: this->unitSquareGuiTris, numVerts: this->unitSquareGuiTris->numVerts);
  idTriangles::AllocStaticTriSurfIndexes(this: this->unitSquareGuiTris, numIndexes: this->unitSquareGuiTris->numIndexes);
  *this->unitSquareGuiTris->indexes = 3;
  this->unitSquareGuiTris->indexes[1] = 0;
  this->unitSquareGuiTris->indexes[2] = 2;
  this->unitSquareGuiTris->indexes[3] = 2;
  this->unitSquareGuiTris->indexes[4] = 0;
  this->unitSquareGuiTris->indexes[5] = 1;
  idTriangles::UpdateIndexBuffer(this: this->unitSquareGuiTris);
  unitSquareGuiTris = this->unitSquareGuiTris;
  v42 = 0;
  v43 = &unitSquareGuiTris->verts->xyz.x;
  *v43 = -1.0;
  v43[1] = -1.0;
  v43[2] = 0.0;
  v44 = &unitSquareGuiTris->verts->xyz.x;
  v44[8] = 1.0;
  v44[9] = -1.0;
  v44[10] = 0.0;
  v45 = &unitSquareGuiTris->verts->xyz.x;
  v45[16] = 1.0;
  v45[17] = 1.0;
  v45[18] = 0.0;
  v46 = &unitSquareGuiTris->verts->xyz.x;
  v46[24] = -1.0;
  v46[25] = 1.0;
  v46[26] = 0.0;
  v47 = unitSquareGuiTris->verts;
  v47->st.x = 0.0;
  v47->st.y = 0.0;
  v48 = unitSquareGuiTris->verts;
  v48[1].st.x = 1.0;
  v48[1].st.y = 0.0;
  v49 = unitSquareGuiTris->verts;
  v49[2].st.x = 1.0;
  v49[2].st.y = 1.0;
  v50 = unitSquareGuiTris->verts;
  v50[3].st.x = 0.0;
  v50[3].st.y = 1.0;
  if ( unitSquareGuiTris->numVerts > 0 )
  {
    __asm
    {
      vspltisw128 v52, 0
      lvlx128   v51, r0, r20
    }
    __asm { vrlimi128 v52, v51, 8, 0 }
    __asm
    {
      vor128    v127, v84, v52
      vrlimi128 v127, v51, 4, 3
      vrlimi128 v127, v51, 2, 2
    }
    do
    {
      __asm { lvx128    v63, r0, r22 }
      __asm
      {
        vaddfp128 v12, v127, v63
        lvx128    v0, r0, r23
        lvx128    v13, r0, r24
      }
      _R11 = LODWORD((*p_unitSquareGuiTris)[3].b[1].y) + v4 + 20;
      __asm
      {
        vmaddfp   v0, v12, v0, v13
        vcfpsxws128 v50, v0, 0
        vpkswss128 v49, v82, v50
        vpkshus128 v0, v81, v49
        stvebx    v0, 0, r11
        stvebx    v0, r11, r26
        stvebx    v0, r11, r28
      }
      v59.x = 0.5;
      v59.y = 0.5;
      v59.z = 0.5;
      v59.w = 0.5;
      v52 = idColor::PackColor(color: &v59);
      ++v42;
      v53 = (_BYTE *)(LODWORD((*p_unitSquareGuiTris)[3].b[1].y) + v4);
      v53[24] = v52;
      v53[25] = BYTE2(v52);
      v53[27] = HIBYTE(v52);
      v53[26] = BYTE1(v52);
      v54 = (_BYTE *)(LODWORD((*p_unitSquareGuiTris)[3].b[1].y) + v4);
      v54[30] = -1;
      v4 += 32;
      v54[29] = -1;
      v54[28] = -1;
      v54[31] = -1;
    }
    while ( v42 < SLODWORD((*p_unitSquareGuiTris)[1].b[0].z) );
  }
  v55 = *p_unitSquareGuiTris;
  v56 = idTriangles::BoundsFromVertScan(this: &v63, result: *p_unitSquareGuiTris);
  v57 = (idTriangles *)*p_unitSquareGuiTris;
  *v55 = *v56;
  idTriangles::UpdateVertexBuffer(this: v57);
  _R0 = -192;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// __unwind$229687
// EA  : 0x82953ECC
// RVA : 0x00953ECC
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void _unwind_229687()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 384 + 80), tag: TAG_TRIANGLES);
}


// ========================================================================
// __unwind$229688
// EA  : 0x82953EF8
// RVA : 0x00953EF8
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void _unwind_229688()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 384 + 80), tag: TAG_TRIANGLES);
}


// ========================================================================
// ?Shutdown@idRenderSystemLocal@@UAAXXZ
// EA  : 0x82953F28
// RVA : 0x00953F28
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::Shutdown(idRenderSystemLocal *this)
{
  idTriangles *unitSquareTris; // r30
  idTriangles *unitSquareGuiTris; // r30

  common->SetRefreshOnPrint(this: common, a2: false);
  idLib::Printf(fmt: "idRenderSystem::Shutdown()\n");
  idRenderModelGui::Shutdown();
  idRenderModelTransparency::Shutdown();
  idRenderModelEffects::Shutdown();
  idRenderModelDecal::Shutdown();
  idRenderModelBeam::Shutdown();
  idRenderModelFlare::Shutdown();
  idRenderModelFlareOcclusionQuad::Shutdown();
  idRenderModelCuttableBeams::Shutdown();
  videoManager->Shutdown(this: videoManager);
  unitSquareTris = this->unitSquareTris;
  if ( unitSquareTris != nullptr )
  {
    idTriangles::~idTriangles(this: this->unitSquareTris);
    idMem::Free(this: &mem, ptr: unitSquareTris, align: ALIGN_16);
  }
  unitSquareGuiTris = this->unitSquareGuiTris;
  this->unitSquareTris = nullptr;
  if ( unitSquareGuiTris != nullptr )
  {
    idTriangles::~idTriangles(this: unitSquareGuiTris);
    idMem::Free(this: &mem, ptr: unitSquareGuiTris, align: ALIGN_16);
  }
  this->unitSquareGuiTris = nullptr;
  idVirtualTexturePreloader::DestroyThread(this: &virtualTexturePreloader);
  idRenderLog::Close(this: &renderLog);
  idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
}


// ========================================================================
// ?InitRenderTextures@idRenderSystemLocal@@QAAXXZ
// EA  : 0x82954028
// RVA : 0x00954028
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::InitRenderTextures(idRenderSystemLocal *this)
{
  idImage **p_imgGui; // r27
  int i; // r22
  idRenderDestination *v4; // r3
  idRenderDestination *v5; // r3
  idRenderDestination *v6; // r3
  idRenderDestination *v7; // r3
  idImage *v8; // r3
  D3DTexture *d3dTexture; // r19
  idImage *v10; // r27
  _D3DFORMAT d3dFormat; // r7
  unsigned int numLevels; // r5
  unsigned int height; // r4
  unsigned int width; // r3
  idRenderDestination *v15; // r3
  idRenderDestination *v16; // r3
  idImage *v17; // r3
  int v18; // r19
  idRenderDestination *v19; // r3
  idRenderDestination *v20; // r3
  idRenderDestination *v21; // r3
  idRenderDestination *v22; // r3
  int v23; // r3
  idRenderDestination *v24; // r3
  idRenderDestination *v25; // r3
  idRenderDestination *v26; // r3
  idRenderDestination *v27; // r3
  int v28; // r3
  idImage *v29; // r3
  int v30; // r11
  idRenderDestination *v31; // r3
  idRenderDestination *v32; // r3
  idRenderDestination *v33; // r3
  idRenderDestination *v34; // r3
  idRenderDestination *v35; // r3
  idRenderDestination *v36; // r3
  idRenderDestination *v37; // r3
  idRenderDestination *v38; // r3
  idImage **imgViewColor; // r28
  int j; // r27
  idImage *v41; // r25
  unsigned int v42; // r24
  void *v43; // r29
  unsigned int v44; // [sp+8h] [-3D8h]
  int v45; // [sp+8h] [-3D8h]
  unsigned int v46; // [sp+Ch] [-3D4h]
  D3DTexture *v47; // [sp+10h] [-3D0h]
  unsigned int *v48; // [sp+14h] [-3CCh]
  unsigned int *v49; // [sp+18h] [-3C8h]
  idImageOpts v50; // [sp+90h] [-350h] BYREF
  idImageOpts v51; // [sp+E0h] [-300h] BYREF
  idImageOpts v52; // [sp+130h] [-2B0h] BYREF
  idImageOpts v53; // [sp+180h] [-260h] BYREF
  idImageOpts v54; // [sp+1D0h] [-210h] BYREF
  idImageOpts v55; // [sp+220h] [-1C0h] BYREF
  idImageOpts v56; // [sp+270h] [-170h] BYREF
  idImageOpts v57; // [sp+2C0h] [-120h] BYREF
  idImageOpts v58; // [sp+310h] [-D0h] BYREF

  v54.colorFormat = CFM_DEFAULT;
  v54.border.x = 0.0;
  v54.border.y = 0.0;
  v54.repeat = TR_REPEAT;
  v54.border.z = 0.0;
  v54.cubeFilter = false;
  v54.border.w = 0.0;
  v54.depth = 0;
  v54.lodBias = 0.0;
  v54.readback = false;
  v54.lodMinClamp = 0.0;
  v54.linear = false;
  v54.aniso = 0.0;
  v54.depthCompareMode = false;
  v54.lodMaxClamp = 4.0;
  v54.overlayMemory = false;
  v54.startPurged = false;
  v54.textureType = TT_CUBIC;
  v54.width = 128;
  v54.height = 128;
  v54.format = FMT_RGBA8;
  v54.numLevels = 5;
  v54.filter = TF_LINEAR_MIPMAP_NEAREST;
  v54.packedTail = false;
  v54.forceBias = true;
  this->imgDynamicEnvironment[0] = idImageManager::ScratchImage(
                                     this: globalImages,
                                     _name: "_environment",
                                     imgOpts: &v54);
  this->imgDynamicEnvironment[1] = idImageManager::ScratchImage(
                                     this: globalImages,
                                     _name: "_environment1",
                                     imgOpts: &v54);
  p_imgGui = &this->imgGui;
  for ( i = 2; i != 0; --i )
  {
    v4 = (idRenderDestination *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x38u,
                                  tag: TAG_RENDERER,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
    if ( v4 != nullptr )
      v5 = idRenderDestination::idRenderDestination(this: v4);
    else
      v5 = nullptr;
    p_imgGui[15] = (idImage *)v5;
    idRenderDestination::CreateFromImages(
      this: v5,
      color: *++p_imgGui,
      depth: nullptr,
      stencil: nullptr,
      colorSurf: xenSurf.pMipGenSurface,
      depthSurf: nullptr);
  }
  v56.border.x = 0.0;
  v56.border.y = 0.0;
  v56.border.z = 0.0;
  v56.colorFormat = CFM_DEFAULT;
  v56.border.w = 0.0;
  v56.cubeFilter = false;
  v56.lodMinClamp = 0.0;
  v56.depth = 0;
  v56.textureType = TT_2D;
  v56.aniso = 0.0;
  v56.packedTail = true;
  v56.lodMaxClamp = 4.0;
  v56.readback = false;
  v56.lodBias = -1.0;
  v56.linear = false;
  v56.forceBias = false;
  v56.depthCompareMode = false;
  v56.overlayMemory = false;
  v56.startPurged = false;
  v56.width = 768;
  v56.height = 768;
  v56.filter = TF_DEFAULT;
  v56.repeat = TR_CLAMP;
  v56.format = FMT_RGBA8;
  v56.numLevels = 5;
  this->imgGui = idImageManager::ScratchImage(this: globalImages, _name: "_gui", imgOpts: &v56);
  v6 = (idRenderDestination *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x38u,
                                tag: TAG_RENDERER,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v6 != nullptr )
    v7 = idRenderDestination::idRenderDestination(this: v6);
  else
    v7 = nullptr;
  this->renderDestGui = v7;
  idRenderDestination::CreateFromImages(
    this: v7,
    color: this->imgGui,
    depth: nullptr,
    stencil: nullptr,
    colorSurf: xenSurf.pMipGenSurface,
    depthSurf: nullptr);
  v57.border.x = 0.0;
  v57.colorFormat = CFM_DEFAULT;
  v57.border.y = 0.0;
  v57.cubeFilter = false;
  v57.border.z = 0.0;
  v57.depth = 0;
  v57.border.w = 0.0;
  v57.textureType = TT_2D;
  v57.lodBias = 0.0;
  v57.packedTail = true;
  v57.lodMinClamp = 0.0;
  v57.readback = false;
  v57.lodMaxClamp = 13.0;
  v57.linear = false;
  v57.aniso = 0.0;
  v57.forceBias = false;
  v57.overlayMemory = false;
  v57.startPurged = false;
  v57.width = 768;
  v57.height = 768;
  v57.numLevels = 1;
  v57.format = FMT_DEPTH;
  v57.repeat = TR_CLAMP;
  v57.depthCompareMode = false;
  v57.filter = TF_NEAREST;
  v8 = idImageManager::ScratchImage(this: globalImages, _name: "_dimShadow_d", imgOpts: &v57);
  d3dTexture = v8->d3dTexture;
  v8->d3dTexture = nullptr;
  v10 = v8;
  idImage::PurgeImage(this: v8);
  v10->d3dTexture = d3dTexture;
  d3dFormat = v10->d3dFormat;
  numLevels = v10->opts.numLevels;
  height = v10->opts.height;
  width = v10->opts.width;
  v10->imageBuffer = this->imgGui->imageBuffer;
  XGSetTextureHeaderEx(
    Width: width,
    Height: height,
    Levels: numLevels,
    Usage: 0,
    Format: d3dFormat,
    ExpBias: 0,
    Flags: 0,
    BaseOffset: 0,
    MipOffset: v44,
    Pitch: v46,
    pTexture: v47,
    pBaseSize: v48,
    pMipSize: v49);
  XGOffsetResourceAddress(pResource: v10->d3dTexture, pBaseAddress: v10->imageBuffer);
  v10->physicalMemoryBytes = 0;
  v15 = (idRenderDestination *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x38u,
                                 tag: TAG_RENDERER,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v15 != nullptr )
    v16 = idRenderDestination::idRenderDestination(this: v15);
  else
    v16 = nullptr;
  this->renderDestDimShadow = v16;
  idRenderDestination::CreateFromImages(
    this: v16,
    color: nullptr,
    depth: v10,
    stencil: nullptr,
    colorSurf: nullptr,
    depthSurf: xenSurf.pShadowDepthStencilSurface);
  v55.border.x = 0.0;
  v55.colorFormat = CFM_DEFAULT;
  v55.border.y = 0.0;
  v55.cubeFilter = false;
  v55.border.z = 0.0;
  v55.depth = 0;
  v55.border.w = 0.0;
  v55.textureType = TT_2D;
  v55.lodBias = 0.0;
  v55.packedTail = true;
  v55.lodMinClamp = 0.0;
  v55.readback = false;
  v55.lodMaxClamp = 13.0;
  v55.forceBias = false;
  v55.aniso = 0.0;
  v55.depthCompareMode = false;
  v55.overlayMemory = false;
  v55.startPurged = false;
  v55.width = 256;
  v55.height = 1;
  v55.numLevels = 1;
  v55.filter = TF_NEAREST;
  v55.repeat = TR_CLAMP;
  v55.format = FMT_RGBA8;
  v55.linear = true;
  this->imgColorGradingLUT[0] = idImageManager::ScratchImage(
                                  this: globalImages,
                                  _name: "_colorBalanceLUT",
                                  imgOpts: &v55);
  v17 = idImageManager::ScratchImage(this: globalImages, _name: "_colorBalanceLUT1", imgOpts: &v55);
  v53.overlayMemory = false;
  v53.startPurged = false;
  v53.border.x = 0.0;
  this->imgColorGradingLUT[1] = v17;
  v53.border.y = 0.0;
  v53.border.z = 0.0;
  v53.format = FMT_NONE;
  v53.border.w = 0.0;
  v53.colorFormat = CFM_DEFAULT;
  v53.lodBias = 0.0;
  v53.filter = TF_DEFAULT;
  v53.lodMinClamp = 0.0;
  v53.repeat = TR_REPEAT;
  v53.lodMaxClamp = 13.0;
  v53.cubeFilter = false;
  v53.aniso = 0.0;
  memset(&v53, 0, 20);
  v53.packedTail = true;
  v53.readback = false;
  v53.linear = false;
  v53.forceBias = false;
  v53.depthCompareMode = false;
  v53.width = renderSystem->GetWidth(this: renderSystem);
  v53.height = renderSystem->GetHeight(this: renderSystem);
  v53.lodMaxClamp = 0.0;
  v53.filter = TF_NEAREST;
  v53.repeat = TR_CLAMP;
  v53.format = FMT_DEPTH;
  this->imgViewDepth = idImageManager::ScratchImage(this: globalImages, _name: "_viewDepth", imgOpts: &v53);
  v50.border.x = 0.0;
  v50.border.y = 0.0;
  v50.format = FMT_NONE;
  v50.border.z = 0.0;
  v50.colorFormat = CFM_DEFAULT;
  v50.border.w = 0.0;
  v50.filter = TF_DEFAULT;
  v50.lodBias = 0.0;
  v50.repeat = TR_REPEAT;
  v50.lodMinClamp = 0.0;
  v50.cubeFilter = false;
  v50.lodMaxClamp = 13.0;
  v50.aniso = 0.0;
  memset(&v50, 0, 20);
  v50.packedTail = true;
  v50.readback = false;
  v50.linear = false;
  v50.forceBias = false;
  v50.depthCompareMode = false;
  v50.overlayMemory = false;
  v50.startPurged = false;
  v50.width = renderSystem->GetWidth(this: renderSystem);
  v50.height = renderSystem->GetHeight(this: renderSystem);
  v50.format = FMT_RGBA8;
  v50.repeat = TR_CLAMP;
  v50.filter = TF_TRILINEAR_NO_ANISO;
  v50.numLevels = 10;
  v50.packedTail = false;
  v50.lodMaxClamp = 9.0;
  this->imgViewColor[0] = idImageManager::ScratchImage(this: globalImages, _name: "_viewColor0", imgOpts: &v50);
  v18 = renderSystem->GetScanoutHeight(this: renderSystem);
  if ( v18 == renderSystem->GetHeight(this: renderSystem) )
    v50.height /= 2;
  this->imgViewColor[1] = idImageManager::ScratchImage(this: globalImages, _name: "_viewColor1", imgOpts: &v50);
  v19 = (idRenderDestination *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x38u,
                                 tag: TAG_RENDERER,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v19 != nullptr )
    v20 = idRenderDestination::idRenderDestination(this: v19);
  else
    v20 = nullptr;
  this->renderDestViewColor[0] = v20;
  idRenderDestination::CreateFromImages(
    this: v20,
    color: this->imgViewColor[0],
    depth: nullptr,
    stencil: nullptr,
    colorSurf: xenSurf.pMipGenSurface,
    depthSurf: nullptr);
  v21 = (idRenderDestination *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x38u,
                                 tag: TAG_RENDERER,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v21 != nullptr )
    v22 = idRenderDestination::idRenderDestination(this: v21);
  else
    v22 = nullptr;
  this->renderDestViewColor[1] = v22;
  idRenderDestination::CreateFromImages(
    this: v22,
    color: this->imgViewColor[1],
    depth: nullptr,
    stencil: nullptr,
    colorSurf: xenSurf.pMipGenSurface,
    depthSurf: nullptr);
  v52.border.x = 0.0;
  v52.lodMaxClamp = 13.0;
  v52.border.y = 0.0;
  v52.startPurged = false;
  v52.border.z = 0.0;
  v52.format = FMT_NONE;
  v52.border.w = 0.0;
  v52.colorFormat = CFM_DEFAULT;
  v52.lodBias = 0.0;
  v52.repeat = TR_REPEAT;
  v52.lodMinClamp = 0.0;
  v52.filter = TF_DEFAULT;
  v52.aniso = 0.0;
  v52.cubeFilter = false;
  memset(&v52, 0, 20);
  v52.packedTail = true;
  v52.readback = false;
  v52.linear = false;
  v52.forceBias = false;
  v52.depthCompareMode = false;
  v52.overlayMemory = false;
  v52.width = renderSystem->GetWidth(this: renderSystem) / 8;
  v23 = renderSystem->GetHeight(this: renderSystem);
  v52.lodMaxClamp = 0.0;
  v52.filter = TF_LINEAR;
  v52.format = FMT_RGBA8;
  v52.numLevels = 1;
  v52.height = v23 / 8;
  v52.repeat = r_mip3Border.valueInteger == 0 ? TR_CLAMP : TR_CLAMP_TO_BORDER;
  this->imgScreenMip3 = idImageManager::ScratchImage(this: globalImages, _name: "_screenMip3", imgOpts: &v52);
  v24 = (idRenderDestination *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x38u,
                                 tag: TAG_RENDERER,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v24 != nullptr )
    v25 = idRenderDestination::idRenderDestination(this: v24);
  else
    v25 = nullptr;
  this->renderDestMip3 = v25;
  idRenderDestination::CreateFromImages(
    this: v25,
    color: this->imgScreenMip3,
    depth: nullptr,
    stencil: nullptr,
    colorSurf: xenSurf.pMipGenSurface,
    depthSurf: nullptr);
  v26 = (idRenderDestination *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x38u,
                                 tag: TAG_RENDERER,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v26 != nullptr )
    v27 = idRenderDestination::idRenderDestination(this: v26);
  else
    v27 = nullptr;
  this->renderDestMip3Alt = v27;
  idRenderDestination::CreateFromImages(
    this: v27,
    color: this->imgScreenMip3,
    depth: nullptr,
    stencil: nullptr,
    colorSurf: xenSurf.pMipGenSurface,
    depthSurf: nullptr);
  v51.border.x = 0.0;
  v51.format = FMT_NONE;
  v51.border.y = 0.0;
  v51.colorFormat = CFM_DEFAULT;
  v51.border.z = 0.0;
  v51.filter = TF_DEFAULT;
  v51.border.w = 0.0;
  v51.repeat = TR_REPEAT;
  v51.lodBias = 0.0;
  v51.cubeFilter = false;
  v51.lodMinClamp = 0.0;
  v51.lodMaxClamp = 13.0;
  v51.aniso = 0.0;
  memset(&v51, 0, 20);
  v51.readback = false;
  v51.forceBias = false;
  v51.depthCompareMode = false;
  v51.packedTail = true;
  v51.linear = false;
  v51.overlayMemory = false;
  v51.startPurged = false;
  v51.width = renderSystem->GetWidth(this: renderSystem) / 4;
  v28 = renderSystem->GetHeight(this: renderSystem);
  v51.lodMaxClamp = 0.0;
  v51.format = FMT_RGBA8;
  v51.height = v28 / 4;
  v51.filter = TF_LINEAR;
  v51.repeat = TR_CLAMP;
  v51.numLevels = 1;
  v51.packedTail = false;
  v29 = idImageManager::ScratchImage(this: globalImages, _name: "_distortion0", imgOpts: &v51);
  v30 = v51.height;
  this->imgDistortion[0] = v29;
  v51.height = v30 / 2;
  this->imgDistortion[1] = idImageManager::ScratchImage(this: globalImages, _name: "_distortion1", imgOpts: &v51);
  v31 = (idRenderDestination *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x38u,
                                 tag: TAG_RENDERER,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v31 != nullptr )
    v32 = idRenderDestination::idRenderDestination(this: v31);
  else
    v32 = nullptr;
  this->renderDestDistortion[0] = v32;
  idRenderDestination::CreateFromImages(
    this: v32,
    color: this->imgDistortion[0],
    depth: nullptr,
    stencil: nullptr,
    colorSurf: xenSurf.pDistortionSurface,
    depthSurf: nullptr);
  v33 = (idRenderDestination *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x38u,
                                 tag: TAG_RENDERER,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v33 != nullptr )
    v34 = idRenderDestination::idRenderDestination(this: v33);
  else
    v34 = nullptr;
  this->renderDestDistortion[1] = v34;
  idRenderDestination::CreateFromImages(
    this: v34,
    color: this->imgDistortion[1],
    depth: nullptr,
    stencil: nullptr,
    colorSurf: xenSurf.pDistortionSurface,
    depthSurf: nullptr);
  v58.border.x = 0.0;
  v58.colorFormat = CFM_DEFAULT;
  v58.border.y = 0.0;
  v58.cubeFilter = false;
  v58.border.z = 0.0;
  v58.depth = 0;
  v58.border.w = 0.0;
  v58.numLevels = 0;
  v58.lodBias = 0.0;
  v58.textureType = TT_2D;
  v58.lodMinClamp = 0.0;
  v58.packedTail = true;
  v58.lodMaxClamp = 13.0;
  v58.readback = false;
  v58.aniso = 0.0;
  v58.linear = false;
  v58.forceBias = false;
  v58.depthCompareMode = false;
  v58.overlayMemory = false;
  v58.startPurged = false;
  v58.width = 1;
  v58.height = 1;
  v58.format = FMT_RGBA8;
  v58.filter = TF_NEAREST;
  v58.repeat = TR_CLAMP;
  this->imgLuminosity = idImageManager::ScratchImage(this: globalImages, _name: "_luminosityImage", imgOpts: &v58);
  v35 = (idRenderDestination *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x38u,
                                 tag: TAG_RENDERER,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v35 != nullptr )
    v36 = idRenderDestination::idRenderDestination(this: v35);
  else
    v36 = nullptr;
  this->renderDestLuminosity = v36;
  idRenderDestination::CreateFromImages(
    this: v36,
    color: this->imgLuminosity,
    depth: nullptr,
    stencil: nullptr,
    colorSurf: xenSurf.pLuminositySurface,
    depthSurf: nullptr);
  v37 = (idRenderDestination *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x38u,
                                 tag: TAG_RENDERER,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v37 != nullptr )
    v38 = idRenderDestination::idRenderDestination(this: v37);
  else
    v38 = nullptr;
  this->renderDestLuminosityAlt = v38;
  idRenderDestination::CreateFromImages(
    this: v38,
    color: this->imgLuminosity,
    depth: nullptr,
    stencil: nullptr,
    colorSurf: xenSurf.pLuminositySurface,
    depthSurf: nullptr);
  imgViewColor = this->imgViewColor;
  for ( j = 2; j != 0; --j )
  {
    v41 = *imgViewColor;
    v42 = 4 * (*imgViewColor)->opts.height * (*imgViewColor)->opts.width;
    v43 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
            size: v42,
            tag: TAG_TEMP,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    memset(Dst: v43, Val: 0, Size: v42);
    idImage::SubImageUpload(
      this: v41,
      mipLevel: 0,
      destX: 0,
      destY: 0,
      destZ: D3DCUBEMAP_FACE_POSITIVE_X,
      width: v41->opts.width,
      height: v41->opts.height,
      pic: (char *)v43,
      pixelPitch: v45);
    if ( v43 != nullptr )
      idMem::Free(this: &mem, ptr: v43, align: ALIGN_16);
    ++imgViewColor;
  }
}


// ========================================================================
// __unwind$230181
// EA  : 0x82954BF4
// RVA : 0x00954BF4
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void _unwind_230181()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 992 + 128), tag: TAG_RENDERER);
}


// ========================================================================
// __unwind$230182
// EA  : 0x82954C20
// RVA : 0x00954C20
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void _unwind_230182()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 992 + 128), tag: TAG_RENDERER);
}


// ========================================================================
// __unwind$230183
// EA  : 0x82954C4C
// RVA : 0x00954C4C
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void _unwind_230183()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 992 + 128), tag: TAG_RENDERER);
}


// ========================================================================
// __unwind$230184
// EA  : 0x82954C78
// RVA : 0x00954C78
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void _unwind_230184()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 992 + 128), tag: TAG_RENDERER);
}


// ========================================================================
// __unwind$230185
// EA  : 0x82954CA4
// RVA : 0x00954CA4
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void _unwind_230185()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 992 + 128), tag: TAG_RENDERER);
}


// ========================================================================
// __unwind$230186
// EA  : 0x82954CD0
// RVA : 0x00954CD0
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void _unwind_230186()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 992 + 128), tag: TAG_RENDERER);
}


// ========================================================================
// __unwind$230187
// EA  : 0x82954CFC
// RVA : 0x00954CFC
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void _unwind_230187()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 992 + 128), tag: TAG_RENDERER);
}


// ========================================================================
// __unwind$230188
// EA  : 0x82954D28
// RVA : 0x00954D28
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void _unwind_230188()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 992 + 128), tag: TAG_RENDERER);
}


// ========================================================================
// __unwind$230189
// EA  : 0x82954D54
// RVA : 0x00954D54
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void _unwind_230189()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 992 + 128), tag: TAG_RENDERER);
}


// ========================================================================
// __unwind$230190
// EA  : 0x82954D80
// RVA : 0x00954D80
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void _unwind_230190()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 992 + 128), tag: TAG_RENDERER);
}


// ========================================================================
// __unwind$230191
// EA  : 0x82954DAC
// RVA : 0x00954DAC
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void _unwind_230191()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 992 + 128), tag: TAG_RENDERER);
}


// ========================================================================
// __unwind$230192
// EA  : 0x82954DD8
// RVA : 0x00954DD8
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void _unwind_230192()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 992 + 128));
}


// ========================================================================
// ?Init@idRenderSystemLocal@@UAAXXZ
// EA  : 0x82954E00
// RVA : 0x00954E00
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::Init(idRenderSystemLocal *this)
{
  idRenderSystemLocal_vtbl *v2; // r30
  void *v3; // r3

  idLib::Printf(fmt: "------- Initializing renderSystem --------\n");
  if ( !idLib::headless )
    idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
  idRenderSystemLocal::StartRenderThread(this);
  idRenderModelGui::Init();
  if ( r_useSMP.valueInteger != 0 )
  {
    idRenderSystemLocal::RestartRenderThread(this, hdc: nullptr);
    idSysThread::WaitForThread(this: this->renderThread);
    v2 = this->__vftable;
    v3 = this->GetGameWindow(this);
    v2->MakeCurrent(this, a2: v3);
  }
  else
  {
    idRenderModelGui::StartFrame();
  }
  this->windowWidth = this->GetWidth(this);
  this->windowHeight = this->GetHeight(this);
  sys->GenerateEvents(this: sys);
  idImageManager::Init(this: globalImages);
  idRenderSystemLocal::InitRenderTextures(this);
  idVirtualTextureSystem::Init(this: &virtualTextureSystem);
  idVirtualTexturePreloader::SpawnThread(this: &virtualTexturePreloader);
  R_ShadowBufferInit();
  idRenderSystemLocal::InitUnitSquare(this);
}


// ========================================================================
// ?SetRenderParmDeclaredValue@@YAXPBDH@Z
// EA  : 0x82954F38
// RVA : 0x00954F38
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void __fastcall SetRenderParmDeclaredValue(const char *name, int value)
{
  __int64 v3; // r11
  const idDecl *v4; // r3

  if ( name != nullptr )
  {
    v4 = idDeclInfo::FindWithInheritance(this: &idDeclRenderParm::resourceList, name, makeDefault: false);
    if ( v4 != nullptr && v4[1].trackedMemory == 0 )
    {
      LODWORD(v3) = value;
      *(float *)&v4[1].staleCount = (float)v3;
      *(float *)&v4[1].networkID = (float)v3;
      *(float *)&v4[1].resourceError = (float)v3;
      *(float *)&v4[1].resourceListPtr = (float)v3;
    }
  }
}


// ========================================================================
// ?Init2@idRenderSystemLocal@@UAAXXZ
// EA  : 0x82954FB8
// RVA : 0x00954FB8
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::Init2(idRenderSystemLocal *this)
{
  idRenderSystemLocal_vtbl *v2; // r29
  void *v3; // r3
  long double v4; // fp4
  idImageOpts v5; // [sp+50h] [-80h] BYREF

  idLib::Printf(fmt: "------- Initializing renderSystem media --------\n");
  idRenderSystemLocal::InitCommands(this);
  SetRenderParmDeclaredValue(name: "contents_NonSolid", value: 0);
  SetRenderParmDeclaredValue(name: "contents_Solid", value: 1);
  SetRenderParmDeclaredValue(name: "contents_Opaque", value: 2);
  SetRenderParmDeclaredValue(name: "contents_Water", value: 4);
  SetRenderParmDeclaredValue(name: "contents_PlayerClip", value: 8);
  SetRenderParmDeclaredValue(name: "contents_MonsterClip", value: 16);
  SetRenderParmDeclaredValue(name: "contents_MoveableClip", value: 64);
  SetRenderParmDeclaredValue(name: "contents_ShotClip", value: 128);
  SetRenderParmDeclaredValue(name: "contents_IKClip", value: 256);
  SetRenderParmDeclaredValue(name: "contents_AIAware", value: 512);
  SetRenderParmDeclaredValue(name: "contents_AI", value: 1024);
  SetRenderParmDeclaredValue(name: "contents_Projectile", value: 2048);
  SetRenderParmDeclaredValue(name: "contents_Corpse", value: 4096);
  SetRenderParmDeclaredValue(name: "contents_Trigger", value: 0x4000);
  SetRenderParmDeclaredValue(name: "contents_Obstacle", value: 0x20000);
  SetRenderParmDeclaredValue(name: "contents_Player", value: 0x8000);
  SetRenderParmDeclaredValue(name: "contents_PlayerCoverClip", value: 0x80000);
  SetRenderParmDeclaredValue(name: "contents_MonsterCoverClip", value: 0x100000);
  SetRenderParmDeclaredValue(name: "contents_Breakable", value: 0x2000);
  SetRenderParmDeclaredValue(name: "contents_NoCover", value: 0x40000000);
  SetRenderParmDeclaredValue(name: "contents_ContextualCover_Clip", value: 0x40000);
  SetRenderParmDeclaredValue(name: "contents_PlayerFocus", value: 0x200000);
  SetRenderParmDeclaredValue(name: "contents_TickClip", value: 0x1000000);
  SetRenderParmDeclaredValue(name: "contents_Shield", value: 0x800000);
  SetRenderParmDeclaredValue(name: "contents_AASSolid", value: 0x4000000);
  SetRenderParmDeclaredValue(name: "contents_AASObstacle", value: 0x8000000);
  SetRenderParmDeclaredValue(name: "contents_AASClusterPortal", value: 0x10000000);
  SetRenderParmDeclaredValue(name: "contents_AASWalkableWall", value: 0x20000000);
  SetRenderParmDeclaredValue(name: "contents_AASFly", value: 0x2000000);
  SetRenderParmDeclaredValue(name: "toolsflag_NoCSG", value: 1);
  SetRenderParmDeclaredValue(name: "toolsflag_SoundDoor", value: 8);
  SetRenderParmDeclaredValue(name: "toolsflag_SoundClip", value: 2);
  SetRenderParmDeclaredValue(name: "toolsflag_SoundClipTrans", value: 4);
  SetRenderParmDeclaredValue(name: "toolsflag_SoundPortal", value: 16);
  SetRenderParmDeclaredValue(name: "toolsflag_PVSClip", value: 32);
  SetRenderParmDeclaredValue(name: "toolsflag_ManifoldHint", value: 128);
  SetRenderParmDeclaredValue(name: "surf_NoDamage", value: 16);
  SetRenderParmDeclaredValue(name: "surf_Slick", value: 32);
  SetRenderParmDeclaredValue(name: "surf_Collision", value: 64);
  SetRenderParmDeclaredValue(name: "surf_Ladder", value: 128);
  SetRenderParmDeclaredValue(name: "surf_NoImpact", value: 256);
  SetRenderParmDeclaredValue(name: "surf_NoSteps", value: 512);
  SetRenderParmDeclaredValue(name: "surf_Stairs", value: 1024);
  SetRenderParmDeclaredValue(name: "surf_OcclusionTest", value: 2048);
  SetRenderParmDeclaredValue(name: "surf_ShadowCaster", value: 4096);
  SetRenderParmDeclaredValue(name: "surf_NullNormal", value: 0x2000);
  SetRenderParmDeclaredValue(name: "surf_NoAreas", value: 0x4000);
  SetRenderParmDeclaredValue(name: "surf_non_penetrable", value: 0x8000);
  SetRenderParmDeclaredValue(name: "surf_NoShoot", value: 0x8000);
  SetRenderParmDeclaredValue(name: "surf_Ladder_Top", value: 0x40000000);
  SetRenderParmDeclaredValue(name: "surfType_None", value: 0);
  SetRenderParmDeclaredValue(name: "surfType_Metal", value: 1);
  SetRenderParmDeclaredValue(name: "surfType_Stone", value: 2);
  SetRenderParmDeclaredValue(name: "surfType_Flesh", value: 3);
  SetRenderParmDeclaredValue(name: "surfType_Wood", value: 4);
  SetRenderParmDeclaredValue(name: "surfType_Cardboard", value: 5);
  SetRenderParmDeclaredValue(name: "surfType_Liquid", value: 6);
  SetRenderParmDeclaredValue(name: "surfType_Glass", value: 7);
  SetRenderParmDeclaredValue(name: "surfType_Plastic", value: 8);
  SetRenderParmDeclaredValue(name: "surfType_Asphalt", value: 9);
  SetRenderParmDeclaredValue(name: "surfType_Dirt", value: 10);
  SetRenderParmDeclaredValue(name: "surfType_Concrete", value: 11);
  SetRenderParmDeclaredValue(name: "surfType_Foliage", value: 12);
  SetRenderParmDeclaredValue(name: "surfType_Linoleum", value: 13);
  SetRenderParmDeclaredValue(name: "surfType_Fabric", value: 14);
  SetRenderParmDeclaredValue(name: "surfType_Rubber", value: 15);
  SetRenderParmDeclaredValue(name: "surfType_Rock", value: 16);
  SetRenderParmDeclaredValue(name: "surfType_SteamPipe", value: 17);
  SetRenderParmDeclaredValue(name: "surfType_WaterPipe", value: 18);
  SetRenderParmDeclaredValue(name: "surfType_Armor", value: 19);
  SetRenderParmDeclaredValue(name: "surfType_Sludge", value: 20);
  SetRenderParmDeclaredValue(name: "surfType_ImpNest", value: 21);
  SetRenderParmDeclaredValue(name: "surfType_HollowMetal", value: 22);
  SetRenderParmDeclaredValue(name: "surfType_SheetMetal", value: 32);
  SetRenderParmDeclaredValue(name: "surfType_FleshPlayer", value: 23);
  SetRenderParmDeclaredValue(name: "surfType_FleshDarkAngel", value: 24);
  SetRenderParmDeclaredValue(name: "surfType_BloodPool", value: 25);
  SetRenderParmDeclaredValue(name: "surfType_Ash", value: 26);
  SetRenderParmDeclaredValue(name: "surfType_FleshMutant", value: 27);
  SetRenderParmDeclaredValue(name: "surfType_ThickPadding", value: 28);
  SetRenderParmDeclaredValue(name: "surfType_PlayerAPCMetal", value: 29);
  SetRenderParmDeclaredValue(name: "surfType_RicketyMetal", value: 30);
  SetRenderParmDeclaredValue(name: "surfType_RicketyWood", value: 31);
  this->rpPowerMip = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclRenderParm::resourceList,
                                                 name: "powerMip",
                                                 makeDefault: true);
  this->rpFrameNumber = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                    this: &idDeclRenderParm::resourceList,
                                                    name: "frameNumber",
                                                    makeDefault: true);
  this->rpGlareStep = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                  this: &idDeclRenderParm::resourceList,
                                                  name: "glareStep",
                                                  makeDefault: true);
  this->rpGlareMap = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclRenderParm::resourceList,
                                                 name: "glareMap",
                                                 makeDefault: true);
  this->rpDistortionMap = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                      this: &idDeclRenderParm::resourceList,
                                                      name: "postDistortionMap",
                                                      makeDefault: true);
  this->rpGrainMap = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclRenderParm::resourceList,
                                                 name: "grainMap",
                                                 makeDefault: true);
  this->rpDynamicEnvMap = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                      this: &idDeclRenderParm::resourceList,
                                                      name: "dynamicEnvMap",
                                                      makeDefault: true);
  this->rpVirtualTextureFeedbackFloat = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                                    this: &idDeclRenderParm::resourceList,
                                                                    name: "virtualTextureFeedbackFloat",
                                                                    makeDefault: true);
  this->rpPageTableMap = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                     this: &idDeclRenderParm::resourceList,
                                                     name: "pageTableMap",
                                                     makeDefault: true);
  this->rpVmtrPageTableMap = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                         this: &idDeclRenderParm::resourceList,
                                                         name: "vmtrPageTableMap",
                                                         makeDefault: true);
  this->rpDepthOfField2 = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                      this: &idDeclRenderParm::resourceList,
                                                      name: "depthOfField2",
                                                      makeDefault: true);
  this->rpGodRayQuadScaleBias = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                            this: &idDeclRenderParm::resourceList,
                                                            name: "godRayQuadScaleBias",
                                                            makeDefault: true);
  this->rpGodRaySourceScaleBias = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                              this: &idDeclRenderParm::resourceList,
                                                              name: "godRaySourceScaleBias",
                                                              makeDefault: true);
  this->rpGodRaysColor = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                     this: &idDeclRenderParm::resourceList,
                                                     name: "godRayColor",
                                                     makeDefault: true);
  this->rpAdaptiveGlareMap = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                         this: &idDeclRenderParm::resourceList,
                                                         name: "adaptiveGlareMap",
                                                         makeDefault: true);
  this->rpAdaptiveGlareMapAlt = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                            this: &idDeclRenderParm::resourceList,
                                                            name: "adaptiveGlareMapAlt",
                                                            makeDefault: true);
  this->rpLuminosityMap = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                      this: &idDeclRenderParm::resourceList,
                                                      name: "luminosityMap",
                                                      makeDefault: true);
  this->rpLuminosityMapAlt = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                         this: &idDeclRenderParm::resourceList,
                                                         name: "luminosityMapAlt",
                                                         makeDefault: true);
  this->rpAdaptiveLuminance = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                          this: &idDeclRenderParm::resourceList,
                                                          name: "adaptiveLuminance",
                                                          makeDefault: true);
  this->rpAdaptiveGlareBlurMap = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                             this: &idDeclRenderParm::resourceList,
                                                             name: "adaptiveGlareBlurMap",
                                                             makeDefault: true);
  this->rpAdaptiveGlareBlurStep = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                              this: &idDeclRenderParm::resourceList,
                                                              name: "adaptiveGlareBlurStep",
                                                              makeDefault: true);
  this->rpAdaptiveGlareParms = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                           this: &idDeclRenderParm::resourceList,
                                                           name: "adaptiveGlareParms",
                                                           makeDefault: true);
  staticModelManager->Init(this: staticModelManager);
  videoManager->Init(this: videoManager);
  idRenderSystemLocal::InitBink(this);
  idRenderModelTransparency::Init();
  idRenderModelEffects::Init();
  idRenderModelDecal::Init();
  idRenderModelBeam::Init();
  idRenderModelFlare::Init();
  idRenderModelFlareOcclusionQuad::Init();
  idRenderModelCuttableBeams::Init();
  this->SyncRenderThread(this, a2: false);
  v2 = this->__vftable;
  v3 = this->GetGameWindow(this);
  v2->MakeCurrent(this, a2: v3);
  *(double *)&v4 = this->blackLevel[1];
  idRenderSystemLocal::SetColorMappings(
    this,
    gamma: r_gamma.valueFloat,
    brightness: r_brightness.valueFloat,
    blackLevel: v4);
  this->mtrDefault = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                           this: &idMaterial::resourceList,
                                           name: "_default",
                                           makeDefault: true);
  this->mtrDefaultPointLight = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                     this: &idMaterial::resourceList,
                                                     name: "lights/solidWhite",
                                                     makeDefault: true);
  this->mtrDefaultProjectedLight = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                         this: &idMaterial::resourceList,
                                                         name: "lights/solidWhite",
                                                         makeDefault: true);
  this->mtrDefaultParallelLight = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                        this: &idMaterial::resourceList,
                                                        name: "lights/solidWhite",
                                                        makeDefault: true);
  this->mtrDefaultPointBlendLight = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                          this: &idMaterial::resourceList,
                                                          name: "lights_blended/defaultPointLight",
                                                          makeDefault: true);
  this->mtrDefaultProjectedBlendLight = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                              this: &idMaterial::resourceList,
                                                              name: "lights_blended/defaultProjectedLight",
                                                              makeDefault: true);
  this->mtrDefaultParallelBlendLight = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                             this: &idMaterial::resourceList,
                                                             name: "lights_blended/defaultParallelLight",
                                                             makeDefault: true);
  this->progGauss = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                this: &idDeclRenderProg::resourceList,
                                                name: "gauss15",
                                                makeDefault: true);
  this->progPostProcess = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                      this: &idDeclRenderProg::resourceList,
                                                      name: "postProcess",
                                                      makeDefault: true);
  this->progGlareScale = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                     this: &idDeclRenderProg::resourceList,
                                                     name: "glareScale",
                                                     makeDefault: true);
  this->progOverlappedDownSample = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                               this: &idDeclRenderProg::resourceList,
                                                               name: "overlappedDownSample",
                                                               makeDefault: true);
  this->progFeedbackDownSample = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                             this: &idDeclRenderProg::resourceList,
                                                             name: "feedbackDownSample",
                                                             makeDefault: true);
  this->progCreateGodRayMask = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                           this: &idDeclRenderProg::resourceList,
                                                           name: "buildGodRays",
                                                           makeDefault: true);
  this->progDrawGodRay = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                     this: &idDeclRenderProg::resourceList,
                                                     name: "drawGodRay",
                                                     makeDefault: true);
  this->progDepthOnly = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                    this: &idDeclRenderProg::resourceList,
                                                    name: "depthOnly",
                                                    makeDefault: true);
  this->progColorOnly = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                    this: &idDeclRenderProg::resourceList,
                                                    name: "colorOnly",
                                                    makeDefault: true);
  this->progColorParmOnly = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                        this: &idDeclRenderProg::resourceList,
                                                        name: "colorParmOnly",
                                                        makeDefault: true);
  this->progWireFrame = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                    this: &idDeclRenderProg::resourceList,
                                                    name: "wireFrame",
                                                    makeDefault: true);
  this->progTextureOnly = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                      this: &idDeclRenderProg::resourceList,
                                                      name: "textureOnly",
                                                      makeDefault: true);
  this->progCubeImageOnly = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                        this: &idDeclRenderProg::resourceList,
                                                        name: "cubeImageOnly",
                                                        makeDefault: true);
  this->progTestImage = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                    this: &idDeclRenderProg::resourceList,
                                                    name: "testImage",
                                                    makeDefault: true);
  this->progTestImageShadow = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                          this: &idDeclRenderProg::resourceList,
                                                          name: "testImageShadow",
                                                          makeDefault: true);
  this->progTestImageMultisample = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                               this: &idDeclRenderProg::resourceList,
                                                               name: "testImageMultisample",
                                                               makeDefault: true);
  this->progBasicBlend = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                     this: &idDeclRenderProg::resourceList,
                                                     name: "basicBlend",
                                                     makeDefault: true);
  this->progEnvironmentBlend = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                           this: &idDeclRenderProg::resourceList,
                                                           name: "environmentBlend",
                                                           makeDefault: true);
  this->progOccluderDepthOnly = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                            this: &idDeclRenderProg::resourceList,
                                                            name: "occluderDepthOnly",
                                                            makeDefault: true);
  this->progOccluderUnique = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                         this: &idDeclRenderProg::resourceList,
                                                         name: "occluderUnique",
                                                         makeDefault: true);
  this->progLandUniqueBump = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                         this: &idDeclRenderProg::resourceList,
                                                         name: "landUniqueBump",
                                                         makeDefault: true);
  this->progLandUniqueDiffuseOnly = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                                this: &idDeclRenderProg::resourceList,
                                                                name: "landUniqueDiffuseOnly",
                                                                makeDefault: true);
  this->progBlendedLightDebugDraw = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                                this: &idDeclRenderProg::resourceList,
                                                                name: "blendLightDebugDraw",
                                                                makeDefault: true);
  this->progDeferredPointLight = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                             this: &idDeclRenderProg::resourceList,
                                                             name: "deferredPointLight",
                                                             makeDefault: true);
  this->progDeferredSpotLight = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                            this: &idDeclRenderProg::resourceList,
                                                            name: "deferredSpotLight",
                                                            makeDefault: true);
  this->progDeferredParallelLight = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                                this: &idDeclRenderProg::resourceList,
                                                                name: "deferredParallelLight",
                                                                makeDefault: true);
  this->progVarianceShadowMap = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                            this: &idDeclRenderProg::resourceList,
                                                            name: "varianceShadowMap",
                                                            makeDefault: true);
  this->progGlobalFog = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                    this: &idDeclRenderProg::resourceList,
                                                    name: "globalFog",
                                                    makeDefault: true);
  this->declHighlightTable = (const idDeclTable *)idDeclInfo::FindWithInheritance(
                                                    this: &idDeclTable::resourceList,
                                                    name: "highlightTable",
                                                    makeDefault: true);
  this->declHighlightExplodeTable = (const idDeclTable *)idDeclInfo::FindWithInheritance(
                                                           this: &idDeclTable::resourceList,
                                                           name: "highlightTable_explode",
                                                           makeDefault: true);
  this->defaultCubeModel = staticModelManager->FindStaticModel(this: staticModelManager, a2: "_default", a3: true);
  this->unitCubeModel = staticModelManager->FindStaticModel(this: staticModelManager, a2: "_unitCube", a3: true);
  this->zeroOneCubeModel = staticModelManager->FindStaticModel(this: staticModelManager, a2: "_zeroOneCube", a3: true);
  this->extrudeBoxModel = staticModelManager->FindStaticModel(this: staticModelManager, a2: "_extrudeBox", a3: true);
  this->zeroOneSquareModel = staticModelManager->FindStaticModel(
                               this: staticModelManager,
                               a2: "_zeroOneSquare",
                               a3: true);
  this->unitSquareModel = staticModelManager->FindStaticModel(this: staticModelManager, a2: "_unitSquare", a3: true);
  v5.format = FMT_NONE;
  v5.colorFormat = CFM_DEFAULT;
  v5.repeat = TR_REPEAT;
  v5.cubeFilter = false;
  v5.border.x = 0.0;
  v5.border.y = 0.0;
  v5.border.z = 0.0;
  memset(&v5, 0, 20);
  v5.border.w = 0.0;
  v5.packedTail = true;
  v5.lodBias = 0.0;
  v5.readback = false;
  v5.lodMinClamp = 0.0;
  v5.linear = false;
  v5.lodMaxClamp = 13.0;
  v5.forceBias = false;
  v5.aniso = 0.0;
  v5.depthCompareMode = false;
  v5.overlayMemory = false;
  v5.startPurged = false;
  v5.filter = TF_NEAREST;
  this->imgGrain = idImageManager::ImageFromFile(
                     this: globalImages,
                     _name: "textures/common/postgrain",
                     opts_p: &v5,
                     makeDefault: true);
  this->progBloomThreshold = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                         this: &idDeclRenderProg::resourceList,
                                                         name: "bloomThreshold",
                                                         makeDefault: true);
  this->progLuminosity = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                     this: &idDeclRenderProg::resourceList,
                                                     name: "luminosity",
                                                     makeDefault: true);
  this->progAdaptiveGlareGauss = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                             this: &idDeclRenderProg::resourceList,
                                                             name: "adaptiveGlareGauss15",
                                                             makeDefault: true);
  idLib::Printf(fmt: "renderSystem initialized.\n");
  idLib::Printf(fmt: "--------------------------------------\n");
}


// ========================================================================
// `dynamic initializer for 'r_mip3Border''
// EA  : 0x8335D9E8
// RVA : 0x0135D9E8
// PDB : w:\tech5\engine\renderer\rendersystem_init.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_mip3Border__()
{
  idCVar::idCVar(
    this: &r_mip3Border,
    name: "r_mip3Border",
    value: "1",
    flags: 1,
    description: "use clampToBorder for the mip3 buffers",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_mip3Border__);
}

