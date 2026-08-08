
// ========================================================================
// ?GetHeight@idRenderSystemLocal@@UAAHXZ
// EA  : 0x829528A0
// RVA : 0x009528A0
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

unsigned int __fastcall idRenderSystemLocal::GetHeight(idRenderSystemLocal *this)
{
  unsigned int result; // r3

  result = d3dpp.BackBufferHeight;
  if ( d3dpp.BackBufferHeight == 1470 )
    return 720;
  return result;
}


// ========================================================================
// ?GetScanoutWidth@idRenderSystemLocal@@UAAHXZ
// EA  : 0x829528C0
// RVA : 0x009528C0
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

unsigned int __fastcall idRenderSystemLocal::GetScanoutWidth(idRenderSystemLocal *this)
{
  return d3dpp.BackBufferWidth;
}


// ========================================================================
// ?GetScanoutHeight@idRenderSystemLocal@@UAAHXZ
// EA  : 0x829528D0
// RVA : 0x009528D0
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

unsigned int __fastcall idRenderSystemLocal::GetScanoutHeight(idRenderSystemLocal *this)
{
  return d3dpp.BackBufferHeight;
}


// ========================================================================
// ?GetPixelAspect@idRenderSystemLocal@@UAAMXZ
// EA  : 0x829528E0
// RVA : 0x009528E0
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

float __fastcall idRenderSystemLocal::GetPixelAspect(idRenderSystemLocal *this)
{
  double v1; // fp1

  v1 = pixelAspect;
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?GetStereoRenderMode@idRenderSystemLocal@@UAA?AW4stereoRenderMode_t@@XZ
// EA  : 0x829528F0
// RVA : 0x009528F0
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

int __fastcall idRenderSystemLocal::GetStereoRenderMode(idRenderSystemLocal *this)
{
  return d3dpp.BackBufferHeight != 1470 ? 0 : 2;
}


// ========================================================================
// ?vblCallback@@YAXPAU_D3DVBLANKDATA@@@Z
// EA  : 0x82952918
// RVA : 0x00952918
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

void __fastcall vblCallback(_D3DVBLANKDATA *pData)
{
  vblData = *pData;
  console->MarkVBLTime(this: console);
}


// ========================================================================
// ?VblCount@idSysLocal@@UAAIXZ
// EA  : 0x82952958
// RVA : 0x00952958
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

unsigned int __fastcall idSysLocal::VblCount(idSysLocal *this)
{
  return vblData.VBlank;
}


// ========================================================================
// ?BlockCallback@@YAXKW4_D3DBLOCKTYPE@@MK@Z
// EA  : 0x82952968
// RVA : 0x00952968
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

void __fastcall BlockCallback(unsigned int Flags, _D3DBLOCKTYPE BlockType, double ClockTime, unsigned int ThreadTime)
{
  if ( BlockType != D3DBLOCKTYPE_SWAP_THROTTLE
    && BlockType != D3DBLOCKTYPE_BLOCK_UNTIL_IDLE
    && BlockType != D3DBLOCKTYPE_BLOCK_ON_FENCE
    && BlockType != D3DBLOCKTYPE_OCCLUSIONQUERY_BATCH_LOCK
    && common->IsInGame(this: common) )
  {
    idLib::Printf(fmt: "Blocked for %.3fms because of a %s\n", ClockTime, (const char *)LODWORD(ClockTime));
  }
}


// ========================================================================
// ?MakeCurrent@idRenderSystemLocal@@UAA_NPAX@Z
// EA  : 0x82952C28
// RVA : 0x00952C28
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

int __fastcall idRenderSystemLocal::MakeCurrent(idRenderSystemLocal *this, void *handle)
{
  if ( d3d != nullptr )
  {
    if ( handle == nullptr )
    {
      D3DDevice_ReleaseThreadOwnership(pDevice: d3d);
      return 1;
    }
    D3DDevice_AcquireThreadOwnership(pDevice: d3d);
  }
  return 1;
}


// ========================================================================
// ?InitContext@idRenderSystemLocal@@UAAXXZ
// EA  : 0x82952C88
// RVA : 0x00952C88
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::InitContext(idRenderSystemLocal *this)
{
  __int64 v1; // r30
  double v3; // fp0
  DWORD v4; // r3
  unsigned int LastError; // r3
  unsigned int v6; // r3
  unsigned int v7; // r3
  unsigned int v8; // r24
  unsigned int v9; // r3
  __int64 v10; // r6
  int v11; // r21
  __int64 v12; // r8
  __int64 v13; // r10
  int v14; // r26
  unsigned int *p_Flags; // r20
  va *v16; // r3
  idImage *v17; // r28
  idRenderDestination *v18; // r3
  idRenderDestination *v19; // r3
  idRenderDestination *v20; // r3
  idRenderDestination *v21; // r3
  idImage *v22; // r27
  idRenderDestination *v23; // r3
  idRenderDestination *v24; // r3
  idRenderDestination *v25; // r3
  idRenderDestination *v26; // r3
  idRenderDestination *v27; // r3
  idRenderDestination *v28; // r3
  wrapperContext_t *v29; // r29
  int v30; // r30
  bool v31; // r5
  int v32; // [sp+8h] [-1218h]
  int v33; // [sp+Ch] [-1214h]
  int v34; // [sp+10h] [-1210h]
  int v35; // [sp+14h] [-120Ch]
  int v36; // [sp+18h] [-1208h]
  int v37; // [sp+1Ch] [-1204h]
  _D3DSURFACE_PARAMETERS v38; // [sp+50h] [-11D0h] BYREF
  idRenderDestination *v39; // [sp+60h] [-11C0h]
  idODSObject<idRenderDestination> v40; // [sp+64h] [-11BCh] BYREF
  idImageOpts v41; // [sp+70h] [-11B0h] BYREF
  idImageOpts v42; // [sp+C0h] [-1160h] BYREF
  _D3DRING_BUFFER_PARAMETERS v43; // [sp+110h] [-1110h] BYREF
  wrapperContext_t v44; // [sp+130h] [-10F0h] BYREF
  va v45; // [sp+180h] [-10A0h] BYREF

  if ( d3d == nullptr )
  {
    XGetVideoMode(pVideoMode: &vidMode);
    if ( vidMode.fIsWideScreen != 0 )
      v3 = 1.0;
    else
      v3 = 0.75;
    pixelAspect = v3;
    XGGetStereoParameters(
      Width: 0x500u,
      Height: 0x2D0u,
      MultiSampleType: D3DMULTISAMPLE_NONE,
      Flags: 0,
      pStereoParameters: &stereoParameters);
    v4 = XGetVideoCapabilities();
    videoCapabilities = v4;
    if ( (v4 & 1) != 0 )
    {
      OutputDebugStringA(lpOutputString: "VideoCapabilities: XC_VIDEO_STEREOSCOPIC_3D_ENABLED\n");
      LOBYTE(v4) = videoCapabilities;
    }
    if ( (v4 & 0x10) != 0 )
      OutputDebugStringA(lpOutputString: "VideoCapabilities: XC_VIDEO_STEREOSCOPIC_3D_720P_60HZ\n");
    memset(Dst: &d3dpp, Val: 0, Size: sizeof(d3dpp));
    d3dpp.BackBufferWidth = 1280;
    d3dpp.DisableAutoBackBuffer = 1;
    d3dpp.DisableAutoFrontBuffer = 1;
    LODWORD(v1) = 0;
    d3dpp.FrontBufferFormat = D3DFMT_LE_A8R8G8B8;
    d3dpp.BackBufferHeight = 720;
    d3dpp.EnableAutoDepthStencil = 0;
    d3dpp.PresentationInterval = 2;
    if ( Direct3D_CreateDevice(
           Adapter: 0,
           DeviceType: D3DDEVTYPE_HAL,
           pUnused: nullptr,
           BehaviorFlags: 0x109u,
           pPresentationParameters: &d3dpp,
           ppReturnedDeviceInterface: &d3d) != 0 )
    {
      LastError = GetLastError();
      idLib::Warning(fmt: "d3d device creation failed with error (%d).", LastError);
    }
    else
    {
      D3DDevice_SetBlockCallback(
        pDevice: d3d,
        Flags: 0,
        pCallback: (void (__fastcall *)(unsigned int, _D3DBLOCKTYPE, float, unsigned int))BlockCallback);
      *(_QWORD *)&v43.Flags = v1;
      v43.pPrimary = (void *)HIDWORD(v1);
      *(_QWORD *)&v43.pSecondary = v1;
      v43.SecondarySize = 0x100000;
      if ( D3DDevice_SetRingBufferParameters(pDevice: d3d, pParameters: &v43) != 0
        && AssertFailed(
             file: "w:\\tech5\\engine\\renderer\\RenderSystem_D3D_360.cpp",
             line: 291,
             expression: "setRing == ((HRESULT)0x00000000L)",
             inlineBreak: true) )
      {
        __trap();
      }
      HIDWORD(v1) = &xenSurf;
      *(_QWORD *)&v38.Base = v1;
      *(_QWORD *)&v38.ColorExpBias = v1;
      xenSurf.currentFrontBuffer = 0;
      xenSurf.pFullResolutionColorSurface = D3DDevice_CreateSurface(
                                              Width: 0x500u,
                                              Height: d3dpp.BackBufferHeight,
                                              D3DFormat: D3DFMT_A8R8G8B8,
                                              MultiSample: D3DMULTISAMPLE_NONE,
                                              pParameters: &v38);
      *(_QWORD *)&v38.Base = v1;
      *(_QWORD *)&v38.ColorExpBias = v1;
      xenSurf.pColorSurface = D3DDevice_CreateSurface(
                                Width: 0x500u,
                                Height: 0x2D0u,
                                D3DFormat: D3DFMT_A8R8G8B8,
                                MultiSample: D3DMULTISAMPLE_NONE,
                                pParameters: &v38);
      v6 = XGSurfaceSize(Width: 0x500u, Height: 0x2D0u, Format: D3DFMT_A8R8G8B8, MultiSample: 0);
      v38.Base += v6;
      xenSurf.pDepthStencilSurface = D3DDevice_CreateSurface(
                                       Width: 0x500u,
                                       Height: 0x2D0u,
                                       D3DFormat: D3DFMT_D24FS8,
                                       MultiSample: D3DMULTISAMPLE_NONE,
                                       pParameters: &v38);
      v7 = XGSurfaceSize(Width: 0x500u, Height: 0x2D0u, Format: D3DFMT_D24FS8, MultiSample: 0);
      v38.Base += v7;
      v38.HierarchicalZBase += 1800;
      D3DDevice_SetRenderTarget_External(pDevice: d3d, RenderTargetIndex: 0, pRenderTarget: xenSurf.pColorSurface);
      D3DDevice_SetDepthStencilSurface(pDevice: d3d, pZStencilSurface: xenSurf.pDepthStencilSurface);
      xenSurf.pFeedbackDownsampleSurface = D3DDevice_CreateSurface(
                                             Width: 0xA0u,
                                             Height: 0x80u,
                                             D3DFormat: D3DFMT_A8R8G8B8,
                                             MultiSample: D3DMULTISAMPLE_NONE,
                                             pParameters: &v38);
      xenSurf.pShadowDepthStencilSurface = D3DDevice_CreateSurface(
                                             Width: 0x300u,
                                             Height: 0x300u,
                                             D3DFormat: D3DFMT_D24FS8,
                                             MultiSample: D3DMULTISAMPLE_NONE,
                                             pParameters: &v38);
      xenSurf.pMipGenSurface = D3DDevice_CreateSurface(
                                 Width: 0x300u,
                                 Height: 0x300u,
                                 D3DFormat: D3DFMT_A8R8G8B8,
                                 MultiSample: D3DMULTISAMPLE_NONE,
                                 pParameters: &v38);
      xenSurf.pDistortionSurface = D3DDevice_CreateSurface(
                                     Width: 0x140u,
                                     Height: 0xB4u,
                                     D3DFormat: D3DFMT_A8R8G8B8,
                                     MultiSample: D3DMULTISAMPLE_NONE,
                                     pParameters: &v38);
      xenSurf.pLuminositySurface = D3DDevice_CreateSurface(
                                     Width: 0x10u,
                                     Height: 0x10u,
                                     D3DFormat: D3DFMT_A8R8G8B8,
                                     MultiSample: D3DMULTISAMPLE_NONE,
                                     pParameters: &v38);
      v38.Base = 0;
      v38.HierarchicalZBase = 0;
      xenSurf.pScaledColorSurface = D3DDevice_CreateSurface(
                                      Width: 0x4A0u,
                                      Height: 0x2D0u,
                                      D3DFormat: D3DFMT_A8R8G8B8,
                                      MultiSample: D3DMULTISAMPLE_NONE,
                                      pParameters: &v38);
      v8 = XGSurfaceSize(Width: 0x4A0u, Height: 0x2D0u, Format: D3DFMT_A8R8G8B8, MultiSample: 0);
      v38.Base += v8;
      xenSurf.pScaledDepthStencilSurface = D3DDevice_CreateSurface(
                                             Width: 0x4A0u,
                                             Height: 0x2D0u,
                                             D3DFormat: D3DFMT_D24FS8,
                                             MultiSample: D3DMULTISAMPLE_NONE,
                                             pParameters: &v38);
      v9 = XGSurfaceSize(Width: 0x4A0u, Height: 0x2D0u, Format: D3DFMT_D24FS8, MultiSample: 0);
      v38.Base += v9;
      xenSurf.pScaledFeedbackSurface = D3DDevice_CreateSurface(
                                         Width: 0x4A0u,
                                         Height: 0x2D0u,
                                         D3DFormat: D3DFMT_A8R8G8B8,
                                         MultiSample: D3DMULTISAMPLE_NONE,
                                         pParameters: &v38);
      v38.Base += v8;
      D3DDevice_SetVertexDeclaration(pDevice: d3d, pDeclaration: nullptr);
      D3DDevice_SetVerticalBlankCallback(pDevice: d3d, pCallback: vblCallback);
      v11 = 2;
      HIDWORD(v12) = &xen_singleBuffer;
      if ( xen_singleBuffer.valueInteger != 0 )
        v11 = 1;
      LODWORD(v12) = 0x82000000;
      HIDWORD(v13) = &renderLog.indentString[28];
      v14 = 0;
      p_Flags = &vblData.Flags;
      do
      {
        v41.border.x = 0.0;
        LODWORD(v13) = d3dpp.BackBufferHeight;
        v41.border.y = 0.0;
        v41.border.z = 0.0;
        v41.colorFormat = CFM_DEFAULT;
        v41.border.w = 0.0;
        v41.cubeFilter = false;
        v41.lodBias = 0.0;
        v41.depth = 0;
        v41.lodMinClamp = 0.0;
        v41.numLevels = 0;
        v41.aniso = 0.0;
        v41.textureType = TT_2D;
        v41.lodMaxClamp = 0.0;
        v41.packedTail = true;
        v41.readback = false;
        v41.linear = false;
        HIDWORD(v10) = v14;
        v41.forceBias = false;
        v41.depthCompareMode = false;
        v41.overlayMemory = false;
        v41.startPurged = false;
        v41.width = d3dpp.BackBufferWidth;
        v41.height = d3dpp.BackBufferHeight;
        v41.filter = TF_NEAREST;
        v41.repeat = TR_CLAMP;
        v41.format = FMT_RGBA8;
        v16 = va::va(
                this: &v45,
                fmt: "_frontColor%d",
                a3: v10,
                a4: v12,
                a5: v13,
                a6: v32,
                a7: v33,
                a8: v34,
                a9: v35,
                a10: v36,
                a11: v37);
        v17 = idImageManager::ScratchImage(this: globalImages, _name: v16->buffer, imgOpts: &v41);
        memset(Dst: v17->lockRect[0].pBits, Val: 0, Size: v17->lockRect[0].Pitch * v41.height);
        v18 = (idRenderDestination *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x38u,
                                       tag: TAG_RENDERER,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
        v39 = v18;
        if ( v18 != nullptr )
          v19 = idRenderDestination::idRenderDestination(this: v18);
        else
          v19 = nullptr;
        p_Flags[1] = (unsigned int)v19;
        v19->isDefault = true;
        idRenderDestination::CreateFromImages(
          this: (idRenderDestination *)*++p_Flags,
          color: v17,
          depth: nullptr,
          stencil: nullptr,
          colorSurf: xenSurf.pColorSurface,
          depthSurf: xenSurf.pDepthStencilSurface);
        ++v14;
      }
      while ( v14 < v11 );
      v20 = (idRenderDestination *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x38u,
                                     tag: TAG_RENDERER,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      v39 = v20;
      if ( v20 != nullptr )
        v21 = idRenderDestination::idRenderDestination(this: v20);
      else
        v21 = nullptr;
      renderDestNative = v21;
      v21->isDefault = true;
      idRenderDestination::CreateFromImages(
        this: renderDestNative,
        color: renderDestFront[0]->targetImage[0],
        depth: nullptr,
        stencil: nullptr,
        colorSurf: xenSurf.pFullResolutionColorSurface,
        depthSurf: nullptr);
      v42.border.x = 0.0;
      v42.border.y = 0.0;
      v42.colorFormat = CFM_DEFAULT;
      v42.border.z = 0.0;
      v42.cubeFilter = false;
      v42.border.w = 0.0;
      v42.depth = 0;
      v42.lodBias = 0.0;
      v42.numLevels = 0;
      v42.lodMinClamp = 0.0;
      v42.textureType = TT_2D;
      v42.aniso = 0.0;
      v42.packedTail = true;
      v42.lodMaxClamp = 0.0;
      v42.readback = false;
      v42.linear = false;
      v42.forceBias = false;
      v42.depthCompareMode = false;
      v42.overlayMemory = false;
      v42.startPurged = false;
      v42.width = 1184;
      v42.height = 720;
      v42.filter = TF_NEAREST;
      v42.repeat = TR_CLAMP;
      v42.format = FMT_RGBA8;
      v22 = idImageManager::ScratchImage(this: globalImages, _name: "_frontFeedback", imgOpts: &v42);
      v23 = (idRenderDestination *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x38u,
                                     tag: TAG_RENDERER,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      v39 = v23;
      if ( v23 != nullptr )
        v24 = idRenderDestination::idRenderDestination(this: v23);
      else
        v24 = nullptr;
      renderDestScaledColor = v24;
      v24->isDefault = true;
      idRenderDestination::CreateFromImages(
        this: renderDestScaledColor,
        color: nullptr,
        depth: nullptr,
        stencil: nullptr,
        colorSurf: xenSurf.pScaledColorSurface,
        depthSurf: xenSurf.pScaledDepthStencilSurface);
      v25 = (idRenderDestination *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x38u,
                                     tag: TAG_RENDERER,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      v39 = v25;
      if ( v25 != nullptr )
        v26 = idRenderDestination::idRenderDestination(this: v25);
      else
        v26 = nullptr;
      renderDestScaledFeedback = v26;
      v26->isDefault = true;
      idRenderDestination::CreateFromImages(
        this: renderDestScaledFeedback,
        color: nullptr,
        depth: nullptr,
        stencil: nullptr,
        colorSurf: xenSurf.pScaledFeedbackSurface,
        depthSurf: xenSurf.pScaledDepthStencilSurface);
      v27 = (idRenderDestination *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x38u,
                                     tag: TAG_RENDERER,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      v39 = v27;
      if ( v27 != nullptr )
        v28 = idRenderDestination::idRenderDestination(this: v27);
      else
        v28 = nullptr;
      renderDestScaledColorWithFeedback = v28;
      v28->isDefault = true;
      idRenderDestination::CreateFromImages(
        this: renderDestScaledColorWithFeedback,
        color: nullptr,
        depth: nullptr,
        stencil: nullptr,
        colorSurf: xenSurf.pScaledColorSurface,
        depthSurf: xenSurf.pScaledDepthStencilSurface);
      idRenderDestination::AddTarget(
        this: renderDestScaledColorWithFeedback,
        target: v22,
        surf: xenSurf.pScaledFeedbackSurface);
      v29 = &v44;
      v30 = 16;
      v44.d3d = d3d;
      do
      {
        --v30;
        v29 = (wrapperContext_t *)((char *)v29 + 4);
        v29->d3d = (D3DDevice *)D3DDevice_CreateOcclusionQueryBatch(pDevice: v44.d3d, NumSlots: 0x100u, NumTiles: 0);
      }
      while ( v30 != 0 );
      GL_SetWrapperContext(context: &v44);
      v40.objectPtr = renderDestNative;
      GL_SetRenderDestination(destination: &v40, level: 0, side: 0);
      GL_State(stateBits: 0x400000000000uLL, forceGlState: v31);
      GL_Clear(color: true, depth: true, stencil: true, stencilValue: 0, r: 0.0, g: 0.0, b: 0.0, a: 0.0);
      this->windowHeight = 720;
      this->windowWidth = 1280;
      renderSystem->SwapBuffers(this: renderSystem, a2: nullptr, a3: false);
    }
  }
}


// ========================================================================
// __unwind$229903
// EA  : 0x829534D4
// RVA : 0x009534D4
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

void _unwind_229903()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 4640 + 96), tag: TAG_RENDERER);
}


// ========================================================================
// __unwind$229904
// EA  : 0x82953500
// RVA : 0x00953500
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

void _unwind_229904()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 4640 + 96), tag: TAG_RENDERER);
}


// ========================================================================
// __unwind$229905
// EA  : 0x8295352C
// RVA : 0x0095352C
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

void _unwind_229905()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 4640 + 96), tag: TAG_RENDERER);
}


// ========================================================================
// __unwind$229906
// EA  : 0x82953558
// RVA : 0x00953558
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

void _unwind_229906()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 4640 + 96), tag: TAG_RENDERER);
}


// ========================================================================
// __unwind$229907
// EA  : 0x82953584
// RVA : 0x00953584
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

void _unwind_229907()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 4640 + 96), tag: TAG_RENDERER);
}


// ========================================================================
// ?SwapBuffers@idRenderSystemLocal@@UAAXPAX_N@Z
// EA  : 0x829535B0
// RVA : 0x009535B0
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::SwapBuffers(idRenderSystemLocal *this, void *hdc, bool forceVsync)
{
  BOOL v4; // r29
  unsigned int valueInteger; // r4
  unsigned int v6; // r4
  unsigned __int64 v7; // r3
  unsigned __int64 v8; // r3
  unsigned int inserted; // r28
  idODSObject<idRenderDestination> v10; // [sp+50h] [-30h] BYREF

  v4 = forceVsync;
  D3DDevice_SetShaderGPRAllocation(pDevice: d3d, Flags: 0, VertexShaderCount: 0, PixelShaderCount: 0);
  valueInteger = r_swapInterval.valueInteger;
  if ( v4 )
  {
    valueInteger = 2;
  }
  else if ( r_swapInterval.valueInteger != 1 && r_swapInterval.valueInteger != 2 )
  {
    D3DDevice_SetRenderState_PresentInterval(pDevice: d3d, Value: 0x80000000);
    goto LABEL_6;
  }
  D3DDevice_SetRenderState_PresentInterval(pDevice: d3d, Value: valueInteger);
  v6 = 0;
  if ( !v4 )
    v6 = 100;
  D3DDevice_SetRenderState_PresentImmediateThreshold(pDevice: d3d, Value: v6);
LABEL_6:
  LODWORD(v7) = Sys_Microseconds() >> 32;
  this->pc.startSwapMicroSec = v7;
  D3DDevice_SynchronizeToPresentationInterval(pDevice: d3d);
  LODWORD(v8) = Sys_Microseconds() >> 32;
  this->pc.endSwapMicroSec = v8;
  inserted = D3DDevice_InsertFence(pDevice: d3d);
  console->SetBitmapConsole(
    this: console,
    a2: (unsigned __int8 *)renderDestNative->targetImage[0]->lockRect[0].pBits,
    a3: nullptr,
    a4: this->windowWidth,
    a5: this->windowHeight,
    a6: renderDestNative->targetImage[0]->lockRect[0].Pitch);
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  if ( xen_singleBuffer.valueInteger != 0 )
  {
    v10.objectPtr = renderDestFront[0];
    GL_ResolveTarget(target: RESOLVE_TARGET_COLOR0, destination: &v10);
    D3DDevice_Swap(pDevice: d3d, pFrontBuffer: renderDestNative->targetImage[0]->d3dTexture, pParameters: nullptr);
  }
  else
  {
    D3DDevice_Swap(pDevice: d3d, pFrontBuffer: renderDestNative->targetImage[0]->d3dTexture, pParameters: nullptr);
    xenSurf.currentFrontBuffer = (_cntlzw(xenSurf.currentFrontBuffer) & 0x20) != 0;
  }
  idMem::PopHeap(this: &mem);
  if ( xen_blockOnSwap.valueInteger != 0 )
    D3DDevice_BlockUntilIdle(pDevice: d3d);
  D3DDevice_BlockOnFence(Fence: inserted);
}


// ========================================================================
// ?SetGamma@idRenderSystemLocal@@UAAXQAG00@Z
// EA  : 0x82953750
// RVA : 0x00953750
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::SetGamma(idRenderSystemLocal *this, char *red, char *green, char *blue)
{
  D3DDevice *v4; // r3
  _D3DGAMMARAMP *v5; // r11
  int v6; // ctr
  int v7; // r10
  int v8; // r8
  unsigned __int16 v9; // r6
  unsigned __int16 v10; // r5
  _D3DGAMMARAMP v11; // [sp+50h] [-610h] BYREF

  v4 = d3d;
  if ( d3d != nullptr )
  {
    v5 = &v11;
    v6 = 256;
    v7 = green - (char *)&v11;
    v8 = blue - (char *)&v11;
    do
    {
      v9 = *(unsigned __int16 *)((char *)v5->red + v7);
      v10 = *(unsigned __int16 *)((char *)v5->red + v8);
      v5->red[0] = *(unsigned __int16 *)((char *)v5->red + red - (char *)&v11);
      v5->green[0] = v9;
      v5->blue[0] = v10;
      v5 = (_D3DGAMMARAMP *)((char *)v5 + 2);
      --v6;
    }
    while ( v6 != 0 );
    D3DDevice_SetGammaRamp(pDevice: v4, UnusedFlags: 0, pRamp: &v11);
  }
}


// ========================================================================
// ?toggleStereo3D_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829537D0
// RVA : 0x009537D0
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

void __fastcall toggleStereo3D_f(const idCmdArgs *args)
{
  if ( allowStereo3D )
  {
    if ( renderSystem->GetScanoutHeight(this: renderSystem) == 1470 )
    {
      idLib::Printf(fmt: "Turning stereo 3D OFF\n");
      d3dpp.BackBufferHeight = 720;
      d3dpp.Flags |= 0x10u;
    }
    else
    {
      idLib::Printf(fmt: "Turning stereo 3D ON\n");
      d3dpp.Flags &= ~0x10u;
      d3dpp.BackBufferHeight = stereoParameters.FrontBufferHeight;
    }
    D3DDevice_Reset(pDevice: d3d, pPresentationParameters: &d3dpp);
  }
  else
  {
    idLib::Printf(fmt: "Stereo 3D not available.\n");
    if ( (videoCapabilities & 1) != 0 )
      idLib::Printf(fmt: "Stereoscopic 3D is NOT enabled in dashboard\n");
    else
      idLib::Printf(fmt: "Stereoscopic 3D is enabled in dashboard\n");
    if ( (videoCapabilities & 0x10) != 0 )
      idLib::Printf(fmt: "Stereoscopic 3D_720P_60HZ is NOT available on display\n");
    else
      idLib::Printf(fmt: "Stereoscopic 3D_720P_60HZ is available on display\n");
  }
}


// ========================================================================
// `dynamic initializer for 'xen_blockOnSwap''
// EA  : 0x8335D910
// RVA : 0x0135D910
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__xen_blockOnSwap__()
{
  idCVar::idCVar(
    this: &xen_blockOnSwap,
    name: "xen_blockOnSwap",
    value: "0",
    flags: 2,
    description: "blockUntilIdle after swap",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__xen_blockOnSwap__);
}


// ========================================================================
// `dynamic initializer for 'xen_singleBuffer''
// EA  : 0x8335D968
// RVA : 0x0135D968
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__xen_singleBuffer__()
{
  idCVar::idCVar(
    this: &xen_singleBuffer,
    name: "xen_singleBuffer",
    value: "1",
    flags: 2,
    description: "resolve to the front buffer and don't swap",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__xen_singleBuffer__);
}


// ========================================================================
// `dynamic initializer for 'toggleStereo3D_v''
// EA  : 0x8335D9C0
// RVA : 0x0135D9C0
// PDB : w:\tech5\engine\renderer\rendersystem_d3d_360.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__toggleStereo3D_v__()
{
  return idCommandLink::idCommandLink(
           this: &toggleStereo3D_v,
           cmdName: "toggleStereo3D",
           function: toggleStereo3D_f,
           description: "Switches stereo 3D rendering on or off",
           argCompletion: nullptr);
}

