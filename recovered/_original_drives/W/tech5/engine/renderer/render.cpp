
// ========================================================================
// ?SetRenderSize@idRender@@AAAXHHH@Z
// EA  : 0x8293DB60
// RVA : 0x0093DB60
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __fastcall idRender::SetRenderSize(idRender *this, int viewIndex, int renderWidth_, int renderHeight_)
{
  int renderWidth; // r4
  int renderHeight; // r5
  int v7; // r29
  idRenderDestination *v8; // r30
  idRenderDestination *v9; // r3

  renderWidth = renderWidth_;
  tr.renderWidth = renderWidth_;
  renderHeight = renderHeight_;
  tr.renderHeight = renderHeight_;
  if ( renderDestScaledColor != nullptr )
  {
    idRenderDestination::Resize(this: renderDestScaledColor, width: renderWidth, height: renderHeight_);
    renderHeight = tr.renderHeight;
    renderWidth = tr.renderWidth;
  }
  if ( renderDestScaledFeedback != nullptr )
  {
    idRenderDestination::Resize(this: renderDestScaledFeedback, width: renderWidth, height: renderHeight);
    renderHeight = tr.renderHeight;
    renderWidth = tr.renderWidth;
  }
  if ( renderDestScaledColorWithFeedback != nullptr )
  {
    idRenderDestination::Resize(this: renderDestScaledColorWithFeedback, width: renderWidth, height: renderHeight);
    renderHeight = tr.renderHeight;
    renderWidth = tr.renderWidth;
  }
  v7 = viewIndex;
  v8 = tr.renderDestViewColor[viewIndex];
  if ( renderWidth != v8->targetWidth || renderHeight != v8->targetHeight )
  {
    idImageManager::UnbindAll(this: globalImages);
    idImage::Resize(this: tr.imgViewDepth, width: tr.renderWidth, height: tr.renderHeight, depth: 0);
    idRenderDestination::Resize(this: v8, width: tr.renderWidth, height: tr.renderHeight);
    if ( tr.renderDestMip1 != nullptr )
      idRenderDestination::Resize(this: tr.renderDestMip1, width: tr.renderWidth / 2, height: tr.renderHeight / 2);
    if ( tr.renderDestMip3 != nullptr )
      idRenderDestination::Resize(this: tr.renderDestMip3, width: tr.renderWidth / 8, height: tr.renderHeight / 8);
    if ( tr.renderDestMip3Alt != nullptr )
      idRenderDestination::Resize(this: tr.renderDestMip3Alt, width: tr.renderWidth / 8, height: tr.renderHeight / 8);
    v9 = tr.renderDestDistortion[v7];
    if ( v9 != nullptr )
      idRenderDestination::Resize(this: v9, width: tr.renderWidth / 4, height: tr.renderHeight / 4);
  }
}


// ========================================================================
// ?R_ShadowBufferInit@@YAXXZ
// EA  : 0x8293DCE0
// RVA : 0x0093DCE0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __fastcall R_ShadowBufferInit()
{
  int valueInteger; // r10
  idImage *v1; // r3
  idImageOpts v2; // [sp+50h] [-60h] BYREF

  valueInteger = r_sb_imageSize.valueInteger;
  SHADOW_BUFFER_DIMENSION = r_sb_imageSize.valueInteger;
  if ( r_sb_imageSize.valueInteger < 256 )
  {
    valueInteger = 256;
    SHADOW_BUFFER_DIMENSION = 256;
  }
  v2.width = valueInteger;
  v2.height = valueInteger;
  v2.colorFormat = CFM_DEFAULT;
  v2.cubeFilter = false;
  v2.depth = 0;
  v2.border.x = 0.0;
  v2.textureType = TT_2D;
  v2.border.y = 0.0;
  v2.packedTail = true;
  v2.border.z = 0.0;
  v2.readback = false;
  v2.border.w = 0.0;
  v2.linear = false;
  v2.lodBias = 0.0;
  v2.forceBias = false;
  v2.lodMinClamp = 0.0;
  v2.overlayMemory = false;
  v2.lodMaxClamp = 13.0;
  v2.startPurged = false;
  v2.aniso = 0.0;
  v2.numLevels = 1;
  v2.format = FMT_DEPTH;
  v2.repeat = TR_CLAMP;
  v2.depthCompareMode = false;
  v2.filter = TF_NEAREST;
  v1 = idImageManager::ScratchImage(this: globalImages, _name: "_shadowBuffer_d", imgOpts: &v2);
  idRenderDestination::CreateFromImages(
    this: &renderDestShadow,
    color: nullptr,
    depth: v1,
    stencil: nullptr,
    colorSurf: nullptr,
    depthSurf: xenSurf.pShadowDepthStencilSurface);
}


// ========================================================================
// ?R_UpdateShadowBufferOptions@@YAXXZ
// EA  : 0x8293DDE0
// RVA : 0x0093DDE0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __fastcall R_UpdateShadowBufferOptions(long double a1)
{
  long double v1; // fp2
  double v4; // fp6
  double v5; // fp12
  double v6; // fp9

  *(double *)&a1 = 2.0;
  v1 = log(x: a1);
  _FP8 = (float)((float)2.0 - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f7, f8, f31, f12 }
  v4 = __frsqrte(_FP7);
  v5 = (float)((float)-(float)((float)((float)v4 * (float)v4) - (float)1.5) * (float)v4);
  v6 = (float)((float)-(float)((float)((float)v5 * (float)v5) - (float)1.5) * (float)v5);
  idDeclRenderParm::Set(
    this: (idDeclRenderParm *)rpParallelLightSliceScale.r,
    x: (float)((float)2.0
          / (float)((float)((float)-(float)((float)((float)v6 * (float)v6) - (float)1.5) * (float)v6)
                  * r_sb_sliceStep.valueFloat)),
    y: (float)((float)1.442695 * (float)*(double *)&v1),
    z: (float)((float)1.0 / (float)((float)1.442695 * (float)*(double *)&v1)),
    w: r_sb_sliceRampScale.valueFloat);
}


// ========================================================================
// ?InitSettings@idRender@@QAAXPBVidRenderWorldLocal@@PBVidRenderView@@@Z
// EA  : 0x8293DEA0
// RVA : 0x0093DEA0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __fastcall idRender::InitSettings(idRender *this, idRenderWorldLocal *world_, const idRenderView *renderView_)
{
  bool v5; // r3
  bool v6; // r11
  bool v7; // r11
  bool v8; // r8
  int valueInteger; // r11
  double z; // fp0
  double y; // fp13
  long double v12; // fp2
  double valueFloat; // fp30
  long double v14; // fp2
  __int64 v15; // r11
  double v16; // fp13
  double v17; // fp0

  this->renderViewObject = nullptr;
  v5 = world_ != nullptr && world_->IsComboMap(this: world_);
  this->settings.isComboMap = v5;
  this->settings.skipWorld = r_skipWorld.valueInteger != 0;
  this->settings.skipModels = r_skipModels.valueInteger != 0;
  this->settings.skipLights = r_skipLights.valueInteger != 0;
  this->settings.skipBlendLightShadows = r_skipBlendLightShadows.valueInteger != 0;
  this->settings.skipSuppress = r_skipSuppress.valueInteger != 0;
  this->settings.skipFeedback = r_skipFeedback.valueInteger != 0;
  this->settings.skipDynamic = r_skipDynamic.valueInteger != 0;
  this->settings.skipAddAlways = r_skipAddAlways.valueInteger != 0;
  this->settings.skipAugment = r_skipAugment.valueInteger != 0;
  this->settings.skipAutosprites = r_skipAutosprites.valueInteger != 0;
  this->settings.skipOcclusionBaseModel = r_skipOcclusionBaseModel.valueInteger != 0;
  this->settings.skipBlendedSurfaces = r_skipBlendedSurfaces.valueInteger != 0;
  this->settings.skipDistortionSurfaces = r_skipDistortionSurfaces.valueInteger != 0;
  this->settings.skipGuis = (_cntlzw(r_skipGuis.valueInteger - 2) & 0x20) != 0;
  this->settings.skipInGameGuis = (_cntlzw(r_skipGuis.valueInteger - 1) & 0x20) != 0;
  v6 = r_skipPostProcess.valueInteger != 0 || renderView_ != nullptr && renderView_->r.skipPostProcess;
  this->settings.skipPostProcess = v6;
  this->settings.skipEmissiveGlare = r_skipEmissiveGlare.valueInteger != 0;
  this->settings.skipBlendLights = r_skipBlendLights.valueInteger != 0;
  this->settings.skipSlowLights = r_skipSlowLights.valueInteger != 0;
  this->settings.skipFog = r_skipFog.valueInteger != 0;
  if ( r_skipGodRays.valueInteger != 0 || renderView_ == nullptr || (v7 = false, !renderView_->r.godRaysEnabled) )
    v7 = true;
  this->settings.skipGodRays = v7;
  this->settings.skipAdaptiveGlare = r_skipAdaptiveGlare.valueInteger != 0;
  this->settings.skipNodeCPUCulling = r_skipNodeCPUCulling.valueInteger != 0;
  this->settings.skipNodeGPUCulling = r_skipNodeGPUCulling.valueInteger != 0;
  this->settings.skipAreaCPUCulling = r_skipAreaCPUCulling.valueInteger != 0;
  this->settings.skipAreaGPUCulling = r_skipAreaGPUCulling.valueInteger != 0;
  this->settings.skipModelCPUCulling = r_skipModelCPUCulling.valueInteger != 0;
  this->settings.skipModelGPUCulling = r_skipModelGPUCulling.valueInteger != 0;
  this->settings.skipLightCPUCulling = r_skipLightCPUCulling.valueInteger != 0;
  this->settings.skipLightGPUCulling = r_skipLightGPUCulling.valueInteger != 0;
  this->settings.skipSurfaceCPUCulling = r_skipSurfaceCPUCulling.valueInteger != 0;
  this->settings.skipModelRangeCulling = r_skipModelRangeCulling.valueInteger != 0;
  this->settings.skipLightRangeCulling = r_skipLightRangeCulling.valueInteger != 0;
  this->settings.forceTwoSidedDepth = (_cntlzw(r_forceTwoSided.valueInteger - 2) & 0x20) != 0;
  this->settings.useAmbientEnv = r_envBlendAmbient.valueInteger != 0;
  this->settings.feedbackBGRA = r_feedbackBGRA.valueInteger != 0;
  this->settings.showOcclusionBoxes = r_showOcclusionBoxes.valueInteger != 0;
  v8 = r_forceOcclusionBoxQueries.valueInteger != 0;
  this->settings.numViews = 0;
  this->settings.forceOcclusionBoxQueries = v8;
  this->settings.numViews = 1;
  if ( renderView_ != nullptr && renderView_->r.useHQViewColorMipsGeneration )
    valueInteger = 0;
  else
    valueInteger = r_generateMipMaps.valueInteger;
  this->settings.generateMipMaps = valueInteger;
  this->settings.guiFrameCount = idRenderModelGui::frameCount;
  this->settings.singleWorldArea = r_singleWorldArea.valueInteger;
  this->settings.singleLight = r_singleLight.valueInteger;
  this->settings.singleModel = r_singleModel.valueInteger;
  this->settings.singleSurface = r_singleSurface.valueInteger;
  this->settings.singleGuiSurface = r_singleGuiSurface.valueInteger;
  this->settings.singleDimShadow = r_singleDimShadow.valueInteger;
  this->settings.queryThreshold = r_queryThreshold.valueInteger;
  this->settings.dimShadowUseQuery = r_dimShadowUseQuery.valueInteger != 0;
  this->settings.dimShadowDepthBoundsTest = r_dimShadowDepthBoundsTest.valueInteger != 0;
  this->settings.dimShadowResolution = r_dimShadowResolution.valueInteger;
  this->settings.dimShadowForceHighQuality = r_dimShadowForceHighQuality.valueInteger;
  this->settings.showDimShadows = r_showDimShadows.valueInteger;
  this->settings.dimShadowLixelScale = r_dimShadowLixelScale.valueFloat;
  this->settings.dimShadowDensity = r_dimShadowDensity.valueFloat;
  this->settings.dimShadowMaxVisibleRange = r_dimShadowMaxVisibleRange.valueFloat;
  this->settings.dimShadowFadeVisibilityRange = r_dimShadowFadeVisibilityRange.valueFloat;
  this->settings.dimShadowSkipRangeCulling = r_skipDimShadowRangeCulling.valueInteger != 0;
  this->settings.dimShadowPolyOfsUnits = r_dimShadowPolyOfsUnits.valueFloat;
  this->settings.dimShadowPolyOfsFactor = r_dimShadowPolyOfsFactor.valueFloat;
  this->settings.useLightScissors = r_useLightScissors.valueInteger != 0;
  this->settings.useLightDepthBoundsTest = r_useLightDepthBoundsTest.valueInteger != 0;
  this->settings.useDeferredSlowMapLighting = r_useDeferredSlowMapLighting.valueInteger != 0;
  this->settings.showLightScissors = r_showLightScissors.valueInteger != 0;
  this->settings.showBlendedLights = r_showBlendedLights.valueInteger;
  this->settings.sortCoverage = renderThreadParmState->values[rp->sortCoverage->parmIndex].value[0];
  this->settings.sortSkybox = renderThreadParmState->values[rp->sortSkybox->parmIndex].value[0];
  this->settings.sortBackground = renderThreadParmState->values[rp->sortBackground->parmIndex].value[0];
  this->settings.sortEmit = renderThreadParmState->values[rp->sortEmit->parmIndex].value[0];
  this->settings.sortEmitOnly = renderThreadParmState->values[rp->sortEmitOnly->parmIndex].value[0];
  this->settings.sortLight = renderThreadParmState->values[rp->sortLight->parmIndex].value[0];
  this->settings.sortDecal = renderThreadParmState->values[rp->sortDecal->parmIndex].value[0];
  this->settings.sortTransSort = renderThreadParmState->values[rp->sortTransSort->parmIndex].value[0];
  this->settings.sortTrans = renderThreadParmState->values[rp->sortTrans->parmIndex].value[0];
  this->settings.sortWater = renderThreadParmState->values[rp->sortWater->parmIndex].value[0];
  this->settings.sortPerturber = renderThreadParmState->values[rp->sortPerturber->parmIndex].value[0];
  this->settings.sortLast = 1.0e30;
  this->settings.viewNearZ = r_znear.valueFloat;
  this->settings.viewFarZ = r_zfar.valueFloat;
  this->settings.progShowGuiOverdraw = r_showGuiOverdraw.valueInteger == 0
                                     ? nullptr
                                     : (const idDeclRenderProg *)progShowGuiOverdraw.r;
  if ( r_clear.valueInteger == 2 )
  {
    this->settings.clearColor.z = 0.0;
    this->settings.clearColor.y = 0.0;
    this->settings.clearColor.x = 0.0;
  }
  else if ( sscanf(
              string: r_clear.valueString.data,
              format: "%f %f %f",
              &this->settings.clearColor,
              &this->settings.clearColor.y,
              &this->settings.clearColor.z) != 3 )
  {
    this->settings.clearColor.y = 0.0;
    this->settings.clearColor.x = 0.40000001;
    this->settings.clearColor.z = 0.25;
  }
  if ( renderView_ != nullptr )
  {
    z = renderView_->r.vieworg.z;
    y = renderView_->r.vieworg.y;
    this->settings.viewOrigin.x = renderView_->r.vieworg.x;
    this->settings.viewOrigin.w = 0.0;
    this->settings.viewOrigin.y = y;
    this->settings.viewOrigin.z = z;
    this->settings.viewBounds.b[0].x = renderView_->r.vieworg.x;
    this->settings.viewBounds.b[0].y = renderView_->r.vieworg.y;
    this->settings.viewBounds.b[0].z = renderView_->r.vieworg.z;
    this->settings.viewBounds.b[1].x = renderView_->r.vieworg.x;
    this->settings.viewBounds.b[1].y = renderView_->r.vieworg.y;
    this->settings.viewBounds.b[1].z = renderView_->r.vieworg.z;
    this->settings.viewBounds.b[0].x = this->settings.viewBounds.b[0].x - (float)16.0;
    *((double *)&v12 + 1) = (float)(this->settings.viewBounds.b[0].y - (float)16.0);
    this->settings.viewBounds.b[0].y = this->settings.viewBounds.b[0].y - (float)16.0;
    this->settings.viewBounds.b[0].z = this->settings.viewBounds.b[0].z - (float)16.0;
    this->settings.viewBounds.b[1].x = this->settings.viewBounds.b[1].x + (float)16.0;
    this->settings.viewBounds.b[1].y = this->settings.viewBounds.b[1].y + (float)16.0;
    this->settings.viewBounds.b[1].z = this->settings.viewBounds.b[1].z + (float)16.0;
    valueFloat = r_znear.valueFloat;
    *(double *)&v12 = (float)((float)(renderView_->r.fov_x * idMath::M_DEG2RAD) * (float)0.5);
    v14 = tan(x: v12);
    LODWORD(v15) = renderView_->windowWidth;
    HIDWORD(v15) = &r_detailDistancePixelThreshold;
    *((double *)&v14 + 1) = (float)(r_detailDistancePixelThreshold.valueFloat - (float)1.0);
    v16 = r_znear.valueFloat;
    v17 = r_manifoldMaxDetailWidth.valueFloat;
    this->settings.detailBounds.b[0].x = renderView_->r.vieworg.x;
    this->settings.detailBounds.b[0].y = renderView_->r.vieworg.y;
    this->settings.detailBounds.b[0].z = renderView_->r.vieworg.z;
    this->settings.detailBounds.b[1].x = renderView_->r.vieworg.x;
    this->settings.detailBounds.b[1].y = renderView_->r.vieworg.y;
    this->settings.detailBounds.b[1].z = renderView_->r.vieworg.z;
    this->settings.detailBounds.b[0].x = this->settings.detailBounds.b[0].x
                                       - (float)((float)((float)((float)((float)v15 * (float)0.5)
                                                               / (float)((float)*((double *)&v14 + 1)
                                                                       * (float)((float)*(double *)&v14
                                                                               * (float)valueFloat)))
                                                       * (float)v17)
                                               * (float)v16);
    this->settings.detailBounds.b[0].y = this->settings.detailBounds.b[0].y
                                       - (float)((float)((float)((float)((float)v15 * (float)0.5)
                                                               / (float)((float)*((double *)&v14 + 1)
                                                                       * (float)((float)*(double *)&v14
                                                                               * (float)valueFloat)))
                                                       * (float)v17)
                                               * (float)v16);
    this->settings.detailBounds.b[0].z = this->settings.detailBounds.b[0].z
                                       - (float)((float)((float)((float)((float)v15 * (float)0.5)
                                                               / (float)((float)*((double *)&v14 + 1)
                                                                       * (float)((float)*(double *)&v14
                                                                               * (float)valueFloat)))
                                                       * (float)v17)
                                               * (float)v16);
    this->settings.detailBounds.b[1].x = this->settings.detailBounds.b[1].x
                                       + (float)((float)((float)((float)((float)v15 * (float)0.5)
                                                               / (float)((float)*((double *)&v14 + 1)
                                                                       * (float)((float)*(double *)&v14
                                                                               * (float)valueFloat)))
                                                       * (float)v17)
                                               * (float)v16);
    this->settings.detailBounds.b[1].y = this->settings.detailBounds.b[1].y
                                       + (float)((float)((float)((float)((float)v15 * (float)0.5)
                                                               / (float)((float)*((double *)&v14 + 1)
                                                                       * (float)((float)*(double *)&v14
                                                                               * (float)valueFloat)))
                                                       * (float)v17)
                                               * (float)v16);
    this->settings.detailBounds.b[1].z = this->settings.detailBounds.b[1].z
                                       + (float)((float)((float)((float)((float)v15 * (float)0.5)
                                                               / (float)((float)*((double *)&v14 + 1)
                                                                       * (float)((float)*(double *)&v14
                                                                               * (float)valueFloat)))
                                                       * (float)v17)
                                               * (float)v16);
  }
}


// ========================================================================
// ?RenderGuiModels@idRender@@QAAXPBQAVidRenderModel@@HPBVidRenderDestination@@HHHH@Z
// EA  : 0x8293ECB0
// RVA : 0x0093ECB0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __fastcall idRender::RenderGuiModels(
        idRender *this,
        idRenderModel *const *guiModels,
        int numGuiModels,
        const idRenderDestination *renderDestGuis,
        int windowWidth,
        int windowHeight,
        unsigned int renderWidth,
        unsigned int renderHeight)
{
  int v10; // r31
  __int64 v15; // r8
  __int64 v16; // r10
  idRenderModel *const *v17; // r23
  const idRenderModelCommitted *committed; // r3
  __int64 v19; // r6

  v10 = numGuiModels;
  if ( numGuiModels > 0 )
  {
    idParmState::SetRenderPositionToViewTexture(
      this: renderThreadParmState,
      windowWidth,
      windowHeight,
      renderWidth,
      renderHeight);
    idParmState::SetPositionToViewTexture(
      this: renderThreadParmState,
      windowWidth,
      windowHeight,
      renderWidth,
      renderHeight);
    GL_SetDefaultState();
    GL_Clear(color: false, depth: false, stencil: true, stencilValue: 0x80u, r: 0.0, g: 0.0, b: 0.0, a: 0.0);
    LODWORD(v16) = 327680;
    v17 = guiModels;
    do
    {
      if ( *v17 != nullptr )
      {
        committed = (*v17)->committed;
        if ( committed->surfaces.num != 0 )
        {
          LODWORD(v19) = 0;
          HIDWORD(v19) = this->renderViewObject;
          RenderGui(model: committed, settings: &this->settings, inGameGui: v19, a4: v15, a5: v16);
        }
      }
      --v10;
      ++v17;
    }
    while ( v10 != 0 );
    idParmState::SetRenderPositionToViewTexture(
      this: renderThreadParmState,
      windowWidth,
      windowHeight,
      renderWidth,
      renderHeight);
  }
}


// ========================================================================
// ?PrintStats@idRender@@ABAXXZ
// EA  : 0x8293EDB8
// RVA : 0x0093EDB8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __fastcall idRender::PrintStats(idRender *this)
{
  int v2; // r29
  int v3; // r25
  int v4; // r26
  int v5; // r27
  int v6; // r31
  const idRenderModelCommitted **viewModels; // r30
  idRender *v8; // r11
  int v9; // r28
  int v10; // r30
  const idRenderLightCommitted **viewLights; // r29
  const idRenderLightCommitted *v12; // r31
  lightClass_t lightClass; // r11
  const char *v14; // r3
  const idRenderWorldLocal **p_world; // r28
  int v16; // r24
  int v17; // r30
  const idRenderWorldLocal *world; // r11
  int v19; // r31
  idRenderModelCommitted *v20; // r11
  unsigned int v21; // r4

  if ( r_showModels.valueInteger >= 2 )
  {
    idLib::Printf(fmt: "models: ");
    v2 = 0;
    v3 = 0;
    v4 = 0;
    v5 = 0;
    v6 = 0;
    if ( this->numViewModels > 0 )
    {
      viewModels = this->viewModels;
      do
      {
        v8 = (idRender *)*viewModels;
        if ( *viewModels == &this->worldSpace )
        {
          ++v3;
        }
        else if ( (v8->temp[140] & 0x20) != 0 )
        {
          ++v4;
        }
        else
        {
          ++v5;
        }
        idLib::Printf(fmt: "%i ", *(_DWORD *)&v8->temp[8] >> 8);
        ++v6;
        ++v2;
        ++viewModels;
      }
      while ( v6 < this->numViewModels );
    }
    idLib::Printf(fmt: "= %i total, %i world, %i static, %i dynamic\n", v2, v3, v4, v5);
  }
  if ( r_showLights.valueInteger >= 2 )
  {
    idLib::Printf(fmt: "lights: ");
    v9 = 0;
    v10 = 0;
    if ( this->numViewLights > 0 )
    {
      viewLights = this->viewLights;
      do
      {
        v12 = *viewLights;
        if ( (*viewLights)->r.lightClass == LIGHT_BLENDED_ONLY )
          idLib::Printf(fmt: "B");
        lightClass = v12->r.lightClass;
        if ( lightClass == LIGHT_SLOWLIGHT_DYNAMIC_ONLY || lightClass == LIGHT_SLOWLIGHT_PRIVATE_ONLY )
        {
          v14 = "$";
          if ( !v12->castsShadows )
            v14 = "*";
          idLib::Printf(fmt: v14);
        }
        idLib::Printf(fmt: "%i ", v12->index.index >> 8);
        ++v10;
        ++v9;
        ++viewLights;
      }
      while ( v10 < this->numViewLights );
    }
    idLib::Printf(fmt: "= %i total\n", v9);
  }
  if ( r_showDimShadows.valueInteger >= 2 )
  {
    idLib::Printf(fmt: "dimShadows: ");
    p_world = &this->world;
    v16 = 0;
    v17 = 0;
    world = this->world;
    if ( world->linkedRenderModels.num > 0 )
    {
      v19 = 0;
      do
      {
        v20 = world->linkedRenderModels.list[v19];
        if ( v20 != nullptr )
        {
          v21 = v20->index.index >> 8;
          if ( this->modelDimShadowState[v21] != 0 )
          {
            if ( this->modelDimShadowState[v21] == 2 )
              idLib::Printf(fmt: "%i(%s) ", v21, v20->name);
            else
              idLib::Printf(fmt: "%i ", v21);
            ++v16;
          }
        }
        world = *p_world;
        ++v17;
        ++v19;
      }
      while ( v17 < (*p_world)->linkedRenderModels.num );
    }
    idLib::Printf(fmt: "= %i total\n", v16);
  }
}


// ========================================================================
// ?SetupCaptureParms@idRender@@AAAXAAUcaptureParms_t@@W4renderCapture_t@@_NH@Z
// EA  : 0x8293F0F0
// RVA : 0x0093F0F0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __fastcall idRender::SetupCaptureParms(
        idRender *this,
        captureParms_t *parms,
        renderCapture_t capture,
        bool createMipMaps,
        int viewIndex)
{
  idRenderView **p_renderViewObject; // r11
  int v8; // r11
  int v9; // r11
  idRenderDestination *renderDestGui; // r11

  parms->capture = capture;
  p_renderViewObject = &this->renderViewObject;
  parms->settings = &this->settings;
  if ( this->renderViewObject != nullptr )
  {
    parms->renderWidth = (*p_renderViewObject)->renderWidth;
    parms->renderHeight = (*p_renderViewObject)->renderHeight;
    parms->windowWidth = (*p_renderViewObject)->windowWidth;
    parms->windowHeight = (*p_renderViewObject)->windowHeight;
    parms->forceFullVirtualTextureLoad = (*p_renderViewObject)->r.forceFullVirtualTextureLoad;
  }
  else
  {
    v8 = this->screenView->screenRect.x2 - this->screenView->screenRect.x1 + 1;
    parms->windowWidth = v8;
    parms->renderWidth = v8;
    v9 = this->screenView->screenRect.y2 - this->screenView->screenRect.y1 + 1;
    parms->forceFullVirtualTextureLoad = false;
    parms->windowHeight = v9;
    parms->renderHeight = v9;
  }
  parms->viewIndex = viewIndex;
  parms->renderDestDefault = renderDestScaledColor;
  parms->imgViewDepth = tr.imgViewDepth;
  parms->renderDestViewColor = tr.renderDestViewColor[viewIndex];
  parms->renderDestViewDepth = tr.renderDestViewDepth;
  parms->renderDestFeedback = virtualTextureSystem.renderDestFeedback[renderSystem->FrameNumber(this: renderSystem) % 3];
  parms->feedbackBuffer = virtualTextureSystem.feedbackBuffer;
  parms->feedbackBufferObject = r_usePBOTextureFeedback.valueInteger == 0
                              ? nullptr
                              : virtualTextureSystem.feedbackBufferObject;
  renderDestGui = tr.renderDestGui;
  parms->createMipMaps = createMipMaps;
  parms->renderDestGui = renderDestGui;
  parms->renderDestMip = tr.renderDestMip1;
  parms->renderDestMip3 = tr.renderDestMip3;
  parms->rpGlareMap = tr.rpGlareMap;
  parms->progGlareScale = tr.progGlareScale;
  parms->progOverlappedDownSample = tr.progOverlappedDownSample;
  parms->progFeedbackDownSample = tr.progFeedbackDownSample;
  parms->rpFeedbackColor = nullptr;
  parms->rpViewColor = (const idDeclRenderParm *)rpViewColor.r;
  parms->unitSquareTris = tr.unitSquareModel->surfaces.list->geometry;
  parms->imgBlack = globalImages->blackImage;
}


// ========================================================================
// ?SetupDynamicEnvironment@idRender@@AAAXABVidVec3@@AAUenvBlend_t@@PAVidParmBlock@@PBV4@@Z
// EA  : 0x8293F2F0
// RVA : 0x0093F2F0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __fastcall idRender::SetupDynamicEnvironment(
        idRender *this,
        const idVec3 *point,
        envBlend_t *envBlend,
        idParmBlock *blendedParms,
        idParmBlock *overrideParms)
{
  idRenderView **p_renderViewObject; // r29
  idRenderView *v11; // r5
  const idDeclEnv *dynEnvOverride; // r4
  int v13; // r9
  __int64 v14; // r7
  int v15; // r8
  double x; // fp12
  int v17; // r10
  float *v18; // r11
  double y; // fp13
  double z; // fp0
  double v21; // fp13
  char v22; // r11
  int num; // r10
  char v28; // r11
  unsigned __int8 v29; // r9
  char v30; // r11
  char v31; // r8
  int v32; // r10
  int dynEnvOverrideModelIndex; // r11
  occlusionState_t *occlusionState; // r10
  unsigned int hasOverrideParms; // r11
  double blendStartTime; // fp13
  double v38; // fp0
  const idDeclEnv *env; // r11
  const idDeclEnv *v40; // r11
  int v41; // r27
  idParmBlock *p_parmBlock; // r29
  double v43; // fp31
  int v44; // r28
  int v45; // r30
  const idDeclRenderParm *Dest; // r31
  char v47; // r3
  idParmBlock *v48; // r4
  int parmType; // r11
  char v50; // r11
  bool v51; // zf
  expOp_t *v52; // r3
  int v53; // r11
  const idDeclRenderParm *v54; // r3
  parmValue_t v55; // [sp+50h] [-90h] BYREF
  idParmBlock v56; // [sp+60h] [-80h] BYREF

  p_renderViewObject = &this->renderViewObject;
  idDeclRenderParm::SetImage(
    this: tr.rpDynamicEnvMap,
    image: tr.imgDynamicEnvironment[this->renderViewObject->viewIndex]);
  v11 = *p_renderViewObject;
  if ( (*p_renderViewObject)->r.skipDynamicEnvironment || r_useDynamicEnvironment.valueInteger == 0 )
    goto LABEL_68;
  dynEnvOverride = nullptr;
  v13 = 0;
  HIDWORD(v14) = this->world;
  LODWORD(v14) = *(_DWORD *)(HIDWORD(v14) + 136);
  if ( (int)v14 > 0 )
  {
    v15 = *(_DWORD *)(HIDWORD(v14) + 132);
    x = point->x;
    v17 = 0;
    while ( 1 )
    {
      v18 = (float *)(v15 + v17);
      if ( x < *(float *)(v15 + v17)
        || (y = point->y) < v18[1]
        || (z = point->z) < v18[2]
        || x > v18[3]
        || y > v18[4]
        || (v21 = v18[5], v22 = 1, z > v21) )
      {
        v22 = 0;
      }
      if ( v22 != 0 )
        break;
      ++v13;
      v17 += 28;
      if ( v13 >= (int)v14 )
        goto LABEL_16;
    }
    dynEnvOverride = *(const idDeclEnv **)(28 * v13 + v15 + 24);
  }
LABEL_16:
  if ( *(_DWORD *)(HIDWORD(v14) + 140168) != 0 )
    dynEnvOverride = *(const idDeclEnv **)(HIDWORD(v14) + 140168);
  _FP0 = r_envBlendTime.valueFloat;
  __asm { fsel      f13, f0, f0, f13 }
  num = overrideParms->ops.num;
  _FP12 = (float)((float)0.001 - (float)_FP13);
  __asm { fsel      f11, f12, f0, f13 }
  if ( num <= 0 || (v28 = 1, envBlend->hasOverrideParms) )
    v28 = 0;
  v29 = v28;
  if ( num != 0 || (v30 = 1, !envBlend->hasOverrideParms) )
    v30 = 0;
  v31 = v30;
  if ( v11->r.applyDynEnvOverride || (v32 = v29, v29 != 0) || v30 != 0 )
  {
    dynEnvOverrideModelIndex = v11->r.dynEnvOverrideModelIndex;
    if ( dynEnvOverrideModelIndex == -1
      || (LODWORD(v14) = v11->occlusionState,
          HIDWORD(v14) = *(_DWORD *)(v14 + 213504),
          *(_DWORD *)(4 * (dynEnvOverrideModelIndex + 41088) + v14) >= SHIDWORD(v14))
      && (occlusionState = v11->occlusionState,
          HIDWORD(v14) = 4 * (dynEnvOverrideModelIndex + 45184),
          *(int *)((char *)occlusionState->nodeOcclusionQuery + HIDWORD(v14)) > 1)
      && (HIDWORD(v14) = occlusionState->modelOcclusionQueryResult[dynEnvOverrideModelIndex], SHIDWORD(v14) > 1) )
    {
      if ( v11->r.dynEnvOverride != nullptr )
        dynEnvOverride = v11->r.dynEnvOverride;
      if ( v11->r.dynEnvOverrideDuration >= 0.0 )
      {
        _FP12 = (float)((float)0.001 - v11->r.dynEnvOverrideDuration);
        __asm { fsel      f11, f12, f0, f13 }
      }
    }
    v32 = v29;
    if ( v29 != 0 && (hasOverrideParms = envBlend->hasOverrideParms) == 0
      || v31 != 0 && (hasOverrideParms = envBlend->hasOverrideParms) != 0 )
    {
      envBlend->hasOverrideParms = (_cntlzw(hasOverrideParms) & 0x20) != 0;
    }
  }
  if ( dynEnvOverride != nullptr )
  {
    blendStartTime = envBlend->blendStartTime;
    LODWORD(v14) = v11->r.renderTime;
    *(_QWORD *)v55.value = v14;
    v38 = (float)((float)v14 * (float)0.001);
    if ( v38 < blendStartTime )
      v38 = (float)(envBlend->blendDuration + (float)blendStartTime);
    env = envBlend->env;
    if ( envBlend->env != dynEnvOverride || v32 != 0 || v31 != 0 )
    {
      envBlend->blendStartTime = v38;
      envBlend->blendDuration = _FP11;
      envBlend->cubeFinished = false;
      if ( env == nullptr )
      {
        envBlend->blendDuration = 1.0;
        envBlend->blendStartTime = (float)v38 - (float)2.0;
      }
      envBlend->env = dynEnvOverride;
    }
    v40 = envBlend->env;
    if ( (float)(envBlend->blendDuration + envBlend->blendStartTime) > v38 )
    {
      v41 = 0;
      p_parmBlock = &v40->parmBlock;
      v43 = (float)((float)((float)v38 - envBlend->blendStartTime) / (float)(envBlend->blendDuration * (float)2.5));
      if ( v40->parmBlock.ops.num > 0 )
      {
        v44 = 0;
        v45 = 0;
        do
        {
          Dest = expOp_t::GetDest(this: &p_parmBlock->ops.list[v45]);
          v47 = idParmBlock::SetsRenderParm(this: overrideParms, parm: Dest);
          v48 = overrideParms;
          if ( v47 == 0 )
            v48 = p_parmBlock;
          parmType = Dest->parmType;
          if ( parmType != 0 )
          {
            if ( parmType < 1 || (v51 = parmType <= 8, v50 = 1, !v51) )
              v50 = 0;
            if ( v50 != 0 )
            {
              v52 = &v48->ops.list[v45];
              v53 = v52->type & 0x1F;
              if ( v53 == 1 )
              {
                v54 = expOp_t::GetA(this: v52);
                idParmBlock::SetImage(
                  this: blendedParms,
                  parm: Dest,
                  image: renderThreadParmState->values[v54->parmIndex].image);
              }
              else if ( v53 == 0 )
              {
                idParmBlock::SetImage(this: blendedParms, parm: Dest, image: v48->constants.list[v44].image);
              }
            }
          }
          else
          {
            idParmBlock::GetVector(this: (idParmBlock *)&v56.constants, result: v48, parm: Dest);
            idParmBlock::GetVector(this: &v56, result: blendedParms, parm: Dest);
            v55.value[1] = (float)(*(float *)&v56.constants.num * (float)v43)
                         + (float)(*(float *)&v56.ops.num * (float)((float)1.0 - (float)v43));
            v55.value[0] = (float)(*(float *)&v56.constants.list * (float)v43)
                         + (float)(*(float *)&v56.ops.list * (float)((float)1.0 - (float)v43));
            v55.value[2] = (float)(*(float *)&v56.constants.size * (float)v43)
                         + (float)(*(float *)&v56.ops.size * (float)((float)1.0 - (float)v43));
            v55.value[3] = (float)(*(float *)&v56.constants.granularity * (float)v43)
                         + (float)(*(float *)&v56.ops.granularity * (float)((float)1.0 - (float)v43));
            idParmBlock::SetParm(this: blendedParms, parm: Dest, parmValue: &v55);
          }
          ++v41;
          ++v45;
          ++v44;
        }
        while ( v41 < p_parmBlock->ops.num );
      }
    }
    else
    {
      idParmBlock::CopyFrom(this: blendedParms, other: &v40->parmBlock);
      idParmBlock::Append(this: blendedParms, block: overrideParms);
    }
    if ( r_envBlendShow.valueInteger != 0 )
    {
      idLib::Printf(fmt: "blended environment parms for %s:\n", envBlend->env->name.str);
      idParmBlock::Print(this: blendedParms);
    }
  }
  else
  {
LABEL_68:
    idParmBlock::Clear(this: blendedParms);
  }
}


// ========================================================================
// ?CaptureToViewColor@idRender@@QAAXH@Z
// EA  : 0x8293F868
// RVA : 0x0093F868
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __fastcall idRender::CaptureToViewColor(idRender *this, int viewIndex)
{
  captureParms_t v2; // [sp+50h] [-80h] BYREF

  idRender::SetupCaptureParms(this, parms: &v2, capture: CAPTURE_VIEW_COLOR, createMipMaps: false, viewIndex);
  RenderCapture(parms: &v2);
}


// ========================================================================
// ?RenderSingleView@idRender@@QAAXPAXPBVidRenderWorldLocal@@PAVidRenderView@@ABVidScreenView@@@Z
// EA  : 0x8293F8A0
// RVA : 0x0093F8A0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRender::RenderSingleView(
        idRender *this,
        void *hdc,
        const idRenderWorldLocal *world_,
        idRenderView *renderView_,
        const idScreenView *currentScreenView)
{
  __int64 v5; // r30 OVERLAPPED
  idMat3 *p_viewaxis; // r8
  int i; // r7
  int v10; // r10
  idMat3 *v11; // r9
  unsigned int v12; // r10
  char v13; // r6
  __int64 v14; // r22
  void **v15; // r31
  int v16; // r2 OVERLAPPED
  int v17; // r10
  __int64 v18; // r4
  __int64 v19; // r8 OVERLAPPED
  __int64 v20; // r6 OVERLAPPED
  int v21; // r9
  __int64 v22; // r11
  float *v23; // r11
  int j; // ctr
  int v25; // r28
  int v26; // r31
  const idDeclRenderParm **inverseProjectionMatrix; // r10
  int seed; // r9
  __int128 v29; // r5
  __int64 v30; // r7
  __int64 v31; // r11
  __int64 v32; // r7
  __int64 v33; // r6
  long double v34; // fp2
  __int64 v35; // r3
  int v36; // r9
  idRandomMersenneCyclic *v37; // r10
  int v38; // r11
  int k; // ctr
  int v40; // r9
  char *v41; // r5
  expOp_t *v42; // r7
  int v43; // r23
  int v44; // r8
  int v45; // r20
  int v46; // r10
  int v47; // r5
  int v48; // r9
  int v49; // r5
  int v50; // r20
  int v51; // r17
  int v52; // r16
  int v53; // r15
  __int64 v54; // r7 OVERLAPPED
  int v55; // r9
  int v56; // r26
  expOp_t *v57; // r8
  int v58; // r23
  signed int v59; // r10
  int v60; // r9
  unsigned int v61; // r28
  double v62; // fp0
  double v63; // fp30
  const idImage *image; // r11
  int width; // r8
  __int128 v70; // r6 OVERLAPPED
  double v71; // fp24
  double v72; // fp23
  double v73; // fp21
  double v74; // fp22
  unsigned int v75; // r10
  int v76; // r7
  long double v77; // fp2
  long double v78; // fp2
  double v79; // fp24
  unsigned int v80; // r9
  __int64 v81; // r8
  unsigned int v82; // r11
  long double v83; // fp2
  int v84; // r10
  __int64 v85; // r28 OVERLAPPED
  const idRenderView *v86; // r4
  int v87; // r11
  int v88; // r26 OVERLAPPED
  int v89; // r5
  __int64 v90; // r24
  const idRenderView *v91; // r4
  int v92; // r9
  int v93; // r8
  const idRenderModelSurface **v94; // r19
  const viewWorldArea_t *v95; // r18
  const idRenderModelCommitted **v96; // r17
  int *v97; // r16
  const idRenderModelCommitted **v98; // r15
  const idRenderLightCommitted **v99; // r14
  int v100; // r6
  int *v101; // r20
  unsigned __int64 v102; // r30
  int num; // r24
  int v104; // r26
  double v105; // fp13
  const idScreenView *v106; // r8
  int viewIndex; // r4
  __int128 v110; // r8
  int v111; // r11
  _DWORD *v112; // r11
  __int128 v113; // r10
  __int64 v114; // r6
  __int64 v115; // r4
  int Name; // r3
  const idRenderView *v117; // r11
  int v118; // r9
  float *Vector; // r3
  float *v120; // r3
  envBlend_t *v121; // r10
  int v122; // r6
  bool *list; // r5
  int v124; // r3
  int v125; // r8
  int v126; // r9
  int v127; // r7
  int v128; // r11
  int *thread; // r20
  occlusionState_t *v130; // r11
  int v131; // r6
  int firstSurface; // r5
  int v133; // r4
  int v134; // r7
  const idRenderView *v135; // r6
  int v136; // r5
  __int64 v137; // r10
  __int64 v138; // r8
  __int64 v139; // r6
  idRenderLog *v140; // r21
  idVirtualTextureSystem *v141; // r23
  const idRenderView *v142; // r11
  int v143; // r17
  idTriangles *geometry; // r17
  const idImage *imgViewColor; // r10
  occlusionState_t *occlusionState; // r11
  const idRenderView *v147; // r10
  const idRenderView *v148; // r6
  const idBounds **v149; // r3
  int v150; // r3
  int v151; // r6
  int v152; // r7
  int v153; // r3
  int v154; // r6
  int v155; // r6
  int *v156; // r19
  const bool **p_list; // r25
  idTriangles *v158; // r8
  __int64 v159; // r30
  __int64 v160; // r28
  const idRenderView *v161; // r11
  int v162; // r7
  const bool *v163; // r6
  const renderPassSurfaces_t *v164; // r22
  drawSurf_t **v165; // r23
  int v166; // r5
  const idRenderView *v167; // r11
  int v168; // r7
  const bool *v169; // r6
  int v170; // r5
  _BYTE *v171; // r20
  const idRenderView *v172; // r11
  int v173; // r7
  const bool *v174; // r6
  int v175; // r5
  const idRenderView *v176; // r11
  int v177; // r7
  const bool *v178; // r6
  int v179; // r5
  const idRenderView *v180; // r11
  int v181; // r7
  const bool *v182; // r6
  int v183; // r5
  double x; // fp0
  bool godRaysRelativeToCamera; // r16
  double y; // fp13
  const idMaterial *godRaysMaterial; // r15
  double z; // fp12
  double godRaysSize; // fp11
  double godRaysSourceSize; // fp10
  double v191; // fp9
  double v192; // fp8
  double v193; // fp7
  int v194; // r10
  idTriangles *v195; // r6
  const idRenderView *v196; // r11
  int v197; // r7
  const bool *v198; // r6
  int v199; // r5
  int v200; // r6
  const idRenderView *v201; // r11
  int v202; // r23
  idImage *v203; // r9
  int v204; // r26
  idImage *blackImage; // r8
  const idRenderView *v206; // r26
  const idDeclRenderParm *depthOfField; // r10
  idImage *v208; // r9
  double v209; // fp1
  double v210; // fp1
  __int64 v211; // r11
  __int64 v212; // r9 OVERLAPPED
  int v213; // r10
  int *v214; // r9
  int *p_isDefault; // r8
  int *size; // r6
  int v217; // [sp+8h] [-F58h]
  int v218; // [sp+Ch] [-F54h]
  int v219; // [sp+10h] [-F50h]
  int v220; // [sp+14h] [-F4Ch]
  int v221; // [sp+18h] [-F48h]
  int v222; // [sp+1Ch] [-F44h]
  const idRenderModelCommitted **v223; // [sp+58h] [-F08h]
  int v224; // [sp+5Ch] [-F04h]
  int *v225; // [sp+60h] [-F00h]
  const idScreenView **p_screenView; // [sp+64h] [-EFCh]
  int *v227; // [sp+68h] [-EF8h]
  drawSurf_t **v228; // [sp+68h] [-EF8h]
  float v229; // [sp+6Ch] [-EF4h] BYREF
  renderPassSurfaces_t *v230; // [sp+70h] [-EF0h]
  __int64 v231; // [sp+78h] [-EE8h]
  idResolutionScale *v232; // [sp+80h] [-EE0h]
  float v233; // [sp+84h] [-EDCh] BYREF
  idRenderDestination *v234; // [sp+88h] [-ED8h]
  idParmBlock v235; // [sp+90h] [-ED0h] BYREF
  idStaticList<bool,1024> *p_binaryModelState; // [sp+B8h] [-EA8h]
  const idRenderModelCommitted **v237; // [sp+BCh] [-EA4h]
  idVirtualTextureSystem *v238; // [sp+C0h] [-EA0h]
  idRenderLog *v239; // [sp+C4h] [-E9Ch]
  __int64 v240; // [sp+D0h] [-E90h]
  int v241; // [sp+D8h] [-E88h]
  int v242; // [sp+DCh] [-E84h]
  idResolutionScale *v243; // [sp+E0h] [-E80h]
  int *v244; // [sp+E4h] [-E7Ch]
  int *v245; // [sp+E8h] [-E78h]
  int *v246; // [sp+ECh] [-E74h]
  idODSObject<idRenderDestination> v247[2]; // [sp+F0h] [-E70h] BYREF
  __int64 v248; // [sp+F8h] [-E68h]
  unsigned __int64 v249; // [sp+100h] [-E60h]
  int v250; // [sp+108h] [-E58h]
  int v251; // [sp+10Ch] [-E54h]
  idMat3 v252; // [sp+110h] [-E50h] BYREF
  idResource *r; // [sp+134h] [-E2Ch]
  idResource *v254; // [sp+138h] [-E28h]
  idResource *v255; // [sp+13Ch] [-E24h]
  idResource *v256; // [sp+140h] [-E20h]
  idResource *v257; // [sp+144h] [-E1Ch]
  idResource *v258; // [sp+148h] [-E18h]
  idResource *v259; // [sp+14Ch] [-E14h]
  idResource *v260; // [sp+150h] [-E10h]
  idImage *v261; // [sp+154h] [-E0Ch]
  renderSortParms_t v262; // [sp+160h] [-E00h] BYREF
  renderAugmentParms_t v263; // [sp+180h] [-DE0h] BYREF
  renderCullParms_t v264; // [sp+1A0h] [-DC0h] BYREF
  renderDepthParms_t v265; // [sp+1D0h] [-D90h] BYREF
  renderWalkBSPParms_t v266; // [sp+230h] [-D30h] BYREF
  renderGlareParms_t v267; // [sp+270h] [-CF0h] BYREF
  renderPostProcessParms_t v268; // [sp+2B0h] [-CB0h] BYREF
  renderOcclusionParms_t v269; // [sp+300h] [-C60h] BYREF
  renderGodRaysParms_t v270; // [sp+350h] [-C10h] BYREF
  renderDynamicEnvParms_t v271; // [sp+3B0h] [-BB0h] BYREF
  renderDimShadowsParms_t v272; // [sp+420h] [-B40h] BYREF
  renderGatherParms_t v273; // [sp+4A0h] [-AC0h] BYREF
  __int64 v274; // [sp+530h] [-A30h]
  idVec3 v275; // [sp+538h] [-A28h] BYREF
  __int64 v276; // [sp+548h] [-A18h]
  renderAdapativeGlareParms_t v277; // [sp+550h] [-A10h] BYREF
  __int64 v278; // [sp+5D8h] [-988h]
  renderLightsParms_t v279; // [sp+5E0h] [-980h] BYREF
  idVec4 v280; // [sp+780h] [-7E0h] BYREF
  renderPassParms_t v281; // [sp+790h] [-7D0h] BYREF
  renderPassParms_t v282; // [sp+840h] [-720h] BYREF
  renderPassParms_t v283; // [sp+8F0h] [-670h] BYREF
  renderPassParms_t v284; // [sp+9A0h] [-5C0h] BYREF
  renderPassParms_t v285; // [sp+A50h] [-510h] BYREF
  renderPassParms_t v286; // [sp+B00h] [-460h] BYREF
  idRenderMatrix v287; // [sp+BB0h] [-3B0h] BYREF
  idVec4 v288; // [sp+BF0h] [-370h] BYREF
  idRenderMatrix v289; // [sp+C00h] [-360h] BYREF
  captureParms_t v290; // [sp+C40h] [-320h] BYREF
  captureParms_t v291; // [sp+CB0h] [-2B0h] BYREF
  captureParms_t v292; // [sp+D20h] [-240h] BYREF
  captureParms_t v293; // [sp+D90h] [-1D0h] BYREF
  captureParms_t v294; // [sp+E00h] [-160h] BYREF

  HIDWORD(v5) = this;
  p_screenView = &this->screenView;
  v239 = &renderLog;
  this->screenView = currentScreenView;
  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_SETUP_VIEW);
  p_viewaxis = &renderView_->r.viewaxis;
  for ( i = 0; i < 3; ++i )
  {
    v10 = 0;
    v11 = p_viewaxis;
    do
    {
      ++v10;
      v11 = (idMat3 *)((char *)v11 + 12);
    }
    while ( v10 < 3 );
    p_viewaxis = (idMat3 *)((char *)p_viewaxis + 4);
  }
  v244 = (int *)(HIDWORD(v5) + 352388);
  *(_DWORD *)(HIDWORD(v5) + 352388) = 0;
  v237 = (const idRenderModelCommitted **)(HIDWORD(v5) + 156672);
  *(_DWORD *)&v235.usingTempOps = HIDWORD(v5) + 352392;
  v234 = (idRenderDestination *)(HIDWORD(v5) + 352396);
  v246 = (int *)(HIDWORD(v5) + 352400);
  v245 = (int *)(HIDWORD(v5) + 352404);
  v235.constants.size = HIDWORD(v5) + 352408;
  v243 = (idResolutionScale *)(HIDWORD(v5) + 352412);
  v227 = (int *)(HIDWORD(v5) + 352416);
  v230 = (renderPassSurfaces_t *)(HIDWORD(v5) + 352420);
  v225 = (int *)(HIDWORD(v5) + 352424);
  v235.thread = HIDWORD(v5) + 352428;
  *(_QWORD *)(HIDWORD(v5) + 352392) = 1;
  *(_DWORD *)(HIDWORD(v5) + 156672) = HIDWORD(v5) + 352784;
  v12 = 0;
  *(_DWORD *)&v235.constants.granularity = HIDWORD(v5) + 352784;
  *(_DWORD *)(HIDWORD(v5) + 352384) = 0;
  *(_QWORD *)(HIDWORD(v5) + 352400) = 0;
  *(_QWORD *)(HIDWORD(v5) + 352408) = 0;
  *(_QWORD *)(HIDWORD(v5) + 352416) = 0;
  *(_QWORD *)(HIDWORD(v5) + 352424) = 0;
  v235.constants.num = HIDWORD(v5) + 348288;
  do
  {
    __asm { dcbz128   r10, r9 }
    v12 += 128;
  }
  while ( v12 < 0x1000 );
  v13 = *(_BYTE *)(HIDWORD(v5) + 352924);
  *(_DWORD *)(HIDWORD(v5) + 352788) = 0;
  LODWORD(v14) = HIDWORD(v5) + 352772;
  *(_DWORD *)(HIDWORD(v5) + 352772) = world_;
  *(_DWORD *)(HIDWORD(v5) + 352792) = 1048577;
  *(_BYTE *)(HIDWORD(v5) + 352924) = v13 | 0x30;
  *(_DWORD *)(HIDWORD(v5) + 352784) = "_worldSpace";
  *(float *)(HIDWORD(v5) + 353912) = 1.0;
  *(float *)(HIDWORD(v5) + 353916) = 0.0;
  *(float *)(HIDWORD(v5) + 353920) = 0.0;
  *(float *)(HIDWORD(v5) + 353924) = 0.0;
  *(float *)(HIDWORD(v5) + 353928) = 0.0;
  *(float *)(HIDWORD(v5) + 353932) = 1.0;
  *(float *)(HIDWORD(v5) + 353936) = 0.0;
  *(float *)(HIDWORD(v5) + 353940) = 0.0;
  *(float *)(HIDWORD(v5) + 353944) = 0.0;
  *(float *)(HIDWORD(v5) + 353948) = 0.0;
  *(float *)(HIDWORD(v5) + 353952) = 1.0;
  *(float *)(HIDWORD(v5) + 353956) = 0.0;
  *(float *)(HIDWORD(v5) + 353960) = 0.0;
  *(float *)(HIDWORD(v5) + 353964) = 0.0;
  *(float *)(HIDWORD(v5) + 353968) = 0.0;
  *(float *)(HIDWORD(v5) + 353972) = 1.0;
  *(float *)(HIDWORD(v5) + 353976) = 1.0;
  *(float *)(HIDWORD(v5) + 353980) = 0.0;
  *(float *)(HIDWORD(v5) + 353984) = 0.0;
  *(float *)(HIDWORD(v5) + 353988) = 0.0;
  *(float *)(HIDWORD(v5) + 353992) = 0.0;
  *(float *)(HIDWORD(v5) + 353996) = 1.0;
  *(float *)(HIDWORD(v5) + 354000) = 0.0;
  *(float *)(HIDWORD(v5) + 354004) = 0.0;
  *(float *)(HIDWORD(v5) + 354008) = 0.0;
  *(float *)(HIDWORD(v5) + 354012) = 0.0;
  *(float *)(HIDWORD(v5) + 354016) = 1.0;
  *(float *)(HIDWORD(v5) + 354020) = 0.0;
  *(float *)(HIDWORD(v5) + 354024) = 0.0;
  *(float *)(HIDWORD(v5) + 354028) = 0.0;
  *(float *)(HIDWORD(v5) + 354032) = 0.0;
  *(float *)(HIDWORD(v5) + 354036) = 1.0;
  memcpy(Dst: (void *)(HIDWORD(v5) + 354204), Src: &renderView_->worldSpaceMVPMatrix, Size: 0x40u);
  v15 = (void **)(HIDWORD(v5) + 353808);
  if ( *(int *)(HIDWORD(v5) + 353816) < 0 )
  {
    if ( *(_BYTE *)(HIDWORD(v5) + 353823) == 0 || *(_BYTE *)(HIDWORD(v5) + 353823) == 2 )
    {
      if ( *v15 != nullptr )
        idMem::Free(this: &mem, ptr: *v15, align: ALIGN_16);
      *v15 = nullptr;
      *(_DWORD *)(HIDWORD(v5) + 353816) = 0;
    }
    *(_DWORD *)(HIDWORD(v5) + 353812) = 0;
  }
  *(_DWORD *)(HIDWORD(v5) + 353812) = __CFADD__(
                                        -*(_DWORD *)(HIDWORD(v5) + 353816),
                                        *(_DWORD *)(HIDWORD(v5) + 353816) ^ 0x80000000)
                                    ? 0
                                    : *(_DWORD *)(HIDWORD(v5) + 353816);
  *(_DWORD *)(HIDWORD(v5) + 354272) = "_viewSpace";
  memcpy(Dst: (void *)(HIDWORD(v5) + 355400), Src: &renderView_->viewSpaceModelMatrix, Size: 0x40u);
  memcpy(Dst: (void *)(HIDWORD(v5) + 355464), Src: &renderView_->viewSpaceInverseModelMatrix, Size: 0x40u);
  memcpy(Dst: (void *)(HIDWORD(v5) + 355692), Src: &renderView_->viewSpaceMVPMatrix, Size: 0x40u);
  LODWORD(v5) = HIDWORD(v5) + 352768;
  *(_DWORD *)(HIDWORD(v5) + 352768) = renderView_;
  if ( r_forceFullVirtualTextureLoad.valueInteger != 0 )
    renderView_->r.forceFullVirtualTextureLoad = true;
  if ( (*(unsigned __int8 (__fastcall **)(_DWORD))(**(_DWORD **)v14 + 8))(a1: *(_DWORD *)v14) == 0 )
  {
    v17 = *(_DWORD *)v14;
    *(_BYTE *)(HIDWORD(v5) + 354200) |= 0x20u;
    if ( *(_BYTE *)(*(_DWORD *)(v17 + 124) + 26) != 0 )
    {
      v18 = *(unsigned __int8 *)(*(_DWORD *)(v17 + 124) + 8) | 0x5672C00000000LL;
      *(float *)(HIDWORD(v5) + 354072) = (float)v18 * (float)0.0039215689;
      LODWORD(v18) = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)v14 + 124) + 9);
      *(float *)(HIDWORD(v5) + 354076) = (float)v18 * (float)0.0039215689;
      HIDWORD(v19) = *(_DWORD *)(*(_DWORD *)v14 + 124);
      LODWORD(v18) = *(unsigned __int8 *)(HIDWORD(v19) + 10);
      *(float *)(HIDWORD(v5) + 354080) = (float)v18 * (float)0.0039215689;
      v20 = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)v14 + 124) + 11) | 0x5673800000000LL;
      *(float *)(HIDWORD(v5) + 354088) = (float)v20 * (float)0.0039215689;
      LODWORD(v19) = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)v14 + 124) + 12);
      *(float *)(HIDWORD(v5) + HIDWORD(v18)) = (float)v19 * (float)0.0039215689;
      HIDWORD(v18) = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)v14 + 124) + 13);
      *(float *)(HIDWORD(v5) + 354096) = (float)*(__int64 *)(&v16 - 1) * (float)0.0039215689;
      *(float *)(HIDWORD(v5) + HIDWORD(v20)) = (float)(*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)v14 + 124) + 14)
                                                     | 0x5000000000000uLL)
                                             * (float)0.0039215689;
      *(__int64 *)((char *)&v19 - 4) = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)v14 + 124) + 15) | 0x5675800000000LL;
      *(float *)(HIDWORD(v5) + 354108) = (float)*(__int64 *)((char *)&v19 - 4) * (float)0.0039215689;
      HIDWORD(v20) = *(_DWORD *)(*(_DWORD *)v14 + 124);
      LODWORD(v20) = *(unsigned __int8 *)(HIDWORD(v20) + 16);
      *(float *)(HIDWORD(v5) + 354112) = (float)v20 * (float)0.0039215689;
      HIDWORD(v20) = *(_DWORD *)v14;
      LODWORD(v20) = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)v14 + 124) + 17);
      *(float *)(HIDWORD(v5) + 354120) = (float)v20 * (float)0.0039215689;
      HIDWORD(v20) = *(_DWORD *)v14;
      v21 = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)v14 + 124) + 18);
      *(float *)(HIDWORD(v5) + 354124) = (float)*(__int64 *)((char *)&v19 - 4) * (float)0.0039215689;
      *(float *)(HIDWORD(v5) + 354128) = (float)(*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)v14 + 124) + 19)
                                               | 0x5674800000000uLL)
                                       * (float)0.0039215689;
      LODWORD(v20) = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)v14 + 124) + 20);
      *(float *)(HIDWORD(v5) + v19) = (float)v20 * (float)0.0039215689;
      v22 = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)v14 + 124) + 21) | 0x5677000000000LL;
      *(float *)(HIDWORD(v5) + 354140) = (float)v22 * (float)0.0039215689;
      HIDWORD(v18) = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)v14 + 124) + 22);
      *(float *)(HIDWORD(v5) + 354144) = (float)*(__int64 *)(&v16 - 1) * (float)0.0039215689;
      *(float *)(HIDWORD(v5) + 354152) = (float)(*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)v14 + 124) + 23)
                                               | 0x5000000000000uLL)
                                       * (float)0.0039215689;
      *(float *)(HIDWORD(v5) + 354156) = (float)(*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)v14 + 124) + 24)
                                               | 0x5676800000000uLL)
                                       * (float)0.0039215689;
      *(float *)(HIDWORD(v5) + HIDWORD(v22)) = (float)(*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)v14 + 124) + 25)
                                                     | 0x5676C00000000uLL)
                                             * (float)0.0039215689;
    }
    else
    {
      v23 = (float *)(HIDWORD(v5) + 354064);
      for ( j = 6; j != 0; --j )
      {
        v23[2] = r_slowMapWorldAmbient.valueFloat;
        v23[3] = r_slowMapWorldAmbient.valueFloat;
        v23 += 4;
        *v23 = r_slowMapWorldAmbient.valueFloat;
      }
    }
  }
  v25 = 280;
  v26 = 3872;
  inverseProjectionMatrix = rp->inverseProjectionMatrix;
  do
  {
    idDeclRenderParm::Set(this: *(inverseProjectionMatrix - 4), plane: (const idPlane *)(v26 + *(_DWORD *)v5 - 64));
    idDeclRenderParm::Set(
      this: *(idDeclRenderParm **)((char *)&rp->If + v25),
      plane: (const idPlane *)(v26 + *(_DWORD *)v5));
    idDeclRenderParm::Set(
      this: *(idDeclRenderParm **)((char *)rp + v25 - 80),
      plane: (const idPlane *)(v26 + *(_DWORD *)v5 + 64));
    idDeclRenderParm::Set(
      this: *(idDeclRenderParm **)((char *)rp + v25 - 64),
      plane: (const idPlane *)(v26 + *(_DWORD *)v5 + 128));
    idDeclRenderParm::Set(
      this: *(idDeclRenderParm **)((char *)&rp->TimeOffset + v25),
      plane: (const idPlane *)(v26 + *(_DWORD *)v5 + 256));
    v26 += 16;
    v25 += 4;
    inverseProjectionMatrix = (const idDeclRenderParm **)((char *)&rp->If + v25);
  }
  while ( v26 < 3936 );
  idDeclRenderParm::Set(this: rp->globalViewOrigin, vec: (const idVec3 *)(*(_DWORD *)v5 + 2032));
  idDeclRenderParm::Set(this: rp->globalViewFwd, vec: (const idVec3 *)(*(_DWORD *)v5 + 2044));
  idDeclRenderParm::Set(this: rp->globalViewLeft, vec: (const idVec3 *)(*(_DWORD *)v5 + 2056));
  idDeclRenderParm::Set(this: rp->globalViewUp, vec: (const idVec3 *)(*(_DWORD *)v5 + 2068));
  idRenderMatrix::Multiply(
    a: (const idRenderMatrix *)(*(_DWORD *)v5 + 3872),
    b: &renderMatrix_windowSpaceToClipSpace,
    out: &v289);
  idRenderMatrix::Multiply(a: (const idRenderMatrix *)(*(_DWORD *)v5 + 4000), b: &v289, out: &v287);
  idDeclRenderParm::Set(this: (idDeclRenderParm *)rpWindowPosToGlobalX.r, plane: (const idPlane *)&v287);
  idDeclRenderParm::Set(this: (idDeclRenderParm *)rpWindowPosToGlobalY.r, plane: (const idPlane *)&v287.m[4]);
  idDeclRenderParm::Set(this: (idDeclRenderParm *)rpWindowPosToGlobalZ.r, plane: (const idPlane *)&v287.m[8]);
  idDeclRenderParm::Set(this: (idDeclRenderParm *)rpWindowPosToGlobalW.r, plane: (const idPlane *)&v287.m[12]);
  idParmState::SetPositionToViewTexture(
    this: renderThreadParmState,
    windowWidth: *(_DWORD *)(*(_DWORD *)v5 + 4384),
    windowHeight: *(_DWORD *)(*(_DWORD *)v5 + 4388),
    renderWidth: *(_DWORD *)(*(_DWORD *)v5 + 4392),
    renderHeight: *(_DWORD *)(*(_DWORD *)v5 + 4396));
  if ( (_S13_24 & 1) != 0 )
  {
    seed = ::r.seed;
  }
  else
  {
    seed = 0;
    _S13_24 |= 1u;
  }
  DWORD1(v29) = rpViewRandom.r;
  ::r.seed = 1103515245 * seed + 12345;
  ::r.seed = 1103515245 * ::r.seed + 12345;
  DWORD2(v29) = ((unsigned int)(1103515245 * seed + 12345) >> 16) & 0x7FFF;
  v30 = HIWORD(::r.seed) & 0x7FFF | 0x41C64E6D00000000LL;
  ::r.seed = 1103515245 * ::r.seed + 12345;
  LODWORD(v29) = HIWORD(::r.seed) & 0x7FFF;
  ::r.seed = 1103515245 * ::r.seed + 12345;
  HIDWORD(v31) = "Mips";
  LODWORD(v31) = HIWORD(::r.seed) & 0x7FFF;
  idDeclRenderParm::Set(
    this: (idDeclRenderParm *)rpViewRandom.r,
    x: (float)((float)v31 * (float)0.000030518509),
    y: (float)((float)(__int64)v29 * (float)0.000030518509),
    z: (float)((float)v30 * (float)0.000030518509),
    w: (float)((float)*(__int64 *)((char *)&v29 + 4) * (float)0.000030518509));
  LODWORD(v32) = *(_DWORD *)(*(_DWORD *)v5 + 1936);
  idDeclRenderParm::Set(this: rp->Time, v: (float)((float)v32 * (float)0.001));
  LODWORD(v33) = tr.frameCount;
  idDeclRenderParm::Set(this: tr.rpFrameNumber, v: (float)v33);
  if ( r_skipViewParms.valueInteger == 0 )
  {
    idParmState::VirtualEvaluateParmBlock(
      this: renderThreadParmState,
      localParmBlock: (const idParmBlock *)(*(_DWORD *)v5 + 2096),
      parmBlock: (const idParmBlock *)(*(_DWORD *)v5 + 2096));
    if ( r_showParms.valueInteger != 0 )
    {
      idLib::Printf(fmt: "view parms:\n");
      idParmBlock::Print(this: (idParmBlock *)(*(_DWORD *)v5 + 2096));
    }
  }
  R_UpdateShadowBufferOptions(a1: v34);
  v238 = &virtualTextureSystem;
  idVirtualTextureSystem::UpdateFilterParms(this: &virtualTextureSystem, forceUpdateFilterParms: false);
  LODWORD(v35) = GL_GetCurrentQueryNumber();
  v274 = v35;
  idRenderLog::CloseMainBlock(this: &renderLog);
  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_SETUP_DYNAMIC_ENVIRONMENT);
  idRender::SetupDynamicEnvironment(
    this: (idRender *)HIDWORD(v5),
    point: (const idVec3 *)(*(_DWORD *)v5 + 2032),
    envBlend: (envBlend_t *)(*(_DWORD *)v5 + 1880),
    blendedParms: (idParmBlock *)(*(_DWORD *)v5 + 1896),
    overrideParms: (idParmBlock *)(*(_DWORD *)v5 + 2928));
  idParmState::VirtualEvaluateParmBlock(
    this: renderThreadParmState,
    localParmBlock: (const idParmBlock *)(*(_DWORD *)v5 + 1896),
    parmBlock: (const idParmBlock *)(*(_DWORD *)v5 + 1896));
  idRenderLog::CloseMainBlock(this: &renderLog);
  LODWORD(v252.mat[2].z) = rpCGShadow.r;
  r = rpCGMidtone.r;
  v254 = rpCGHighlight.r;
  v260 = rpColorGradingLUT.r;
  v36 = *(_DWORD *)v5;
  v258 = rpCGColorScreenBlend.r;
  v255 = rpCGColorDodgeBlend.r;
  v256 = rpCGColorBurnBlend.r;
  v257 = rpCGColorMultiplyBlend.r;
  v259 = rpCGBlackLevel.r;
  v261 = tr.imgColorGradingLUT[*(_DWORD *)(v36 + 1876)];
  SetupColorGrading(parms: (const setupColorGradingParms_t *)&v252.mat[2].z);
  if ( (_S13_24 & 2) == 0 )
  {
    grainRand.MT[0] = 0;
    v37 = &grainRand;
    _S13_24 |= 2u;
    v38 = 1;
    for ( k = 623; k != 0; --k )
    {
      v40 = 1812433253 * ((v37->MT[0] >> 30) ^ v37->MT[0]) + v38++;
      v37 = (idRandomMersenneCyclic *)((char *)v37 + 4);
      v37->MT[0] = v40;
    }
  }
  v41 = (char *)renderThreadParmState + 16 * (int)(rpGrainHz.r[1].resourceError + 3);
  v42 = *(expOp_t **)v41;
  v43 = *((_DWORD *)v41 + 1);
  v44 = 16 * (int)(rpGrainLevelsMax.r[1].resourceError + 3);
  v45 = *((_DWORD *)v41 + 2);
  v46 = 16 * (int)(rpGrainAmount.r[1].resourceError + 3);
  v47 = *((_DWORD *)v41 + 3);
  v48 = 16 * (int)(rpGrainLevelsMin.r[1].resourceError + 3);
  v235.ops.list = v42;
  v235.ops.num = v43;
  v235.ops.size = v45;
  *(_DWORD *)&v235.ops.granularity = v47;
  HIDWORD(v54) = *(_DWORD *)((char *)&renderThreadParmState->renderParmVersion + v46);
  v49 = *(_DWORD *)((char *)&renderThreadParmState->renderParmVersion + v46 + 4);
  v50 = *(_DWORD *)((char *)&renderThreadParmState->renderParmVersion + v48 + 4);
  v51 = *(_DWORD *)((char *)&renderThreadParmState->vertexParmVersion + v48);
  v52 = *(_DWORD *)((char *)&renderThreadParmState->renderParmVersion + v44 + 4);
  v53 = *(_DWORD *)((char *)&renderThreadParmState->vertexParmVersion + v44);
  LODWORD(v54) = *(_DWORD *)((char *)&renderThreadParmState->vertexParmVersion + v46 + 4);
  v56 = *(_DWORD *)((char *)&renderThreadParmState->vertexParmVersion + v48 + 4);
  v55 = *(_DWORD *)((char *)&renderThreadParmState->renderParmVersion + v48);
  v58 = *(_DWORD *)((char *)&renderThreadParmState->vertexParmVersion + v44 + 4);
  v57 = *(expOp_t **)((char *)&renderThreadParmState->renderParmVersion + v44);
  v241 = *(_DWORD *)((char *)&renderThreadParmState->vertexParmVersion + v46);
  HIDWORD(v240) = HIDWORD(v54);
  LODWORD(v240) = v49;
  v242 = v54;
  HIDWORD(v249) = v55;
  LODWORD(v249) = v50;
  v250 = v51;
  v251 = v56;
  v224 = (int)*(float *)&v235.ops.list;
  v59 = v224;
  v235.ops.list = v57;
  v235.ops.num = v52;
  v235.ops.size = v53;
  *(_DWORD *)&v235.ops.granularity = v58;
  if ( v224 < 1 )
  {
    v59 = 1;
LABEL_34:
    v60 = *(_DWORD *)v5;
    __twllei(v59, 0);
    __twllei(1000 / v59, 0);
    HIDWORD(v54) = *(_DWORD *)(v60 + 1936);
    v61 = 2 * (SHIDWORD(v54) / (1000 / v59));
    __twlgei((1000 / v59) & ~(__ROL4__(HIDWORD(v54), 1) - 1), 0xFFFFFFFF);
    goto LABEL_35;
  }
  if ( v224 < 60 )
    goto LABEL_34;
  v61 = 2 * tr.frameCount;
LABEL_35:
  v62 = 1.0;
  v63 = 1.0;
  image = renderThreadParmState->values[tr.rpGrainMap->parmIndex].image;
  if ( image != nullptr )
  {
    width = image->opts.width;
    LODWORD(v54) = image->opts.height;
    v231 = *(__int64 *)((char *)&v54 - 4);
    v62 = (float)*(__int64 *)((char *)&v54 - 4);
    v63 = (float)v54;
  }
  _FP12 = (float)((float)1.0 - (float)v62);
  _FP11 = (float)((float)1.0 - (float)v63);
  __asm
  {
    fsel      f10, f12, f31, f0
    fsel      f9, f11, f31, f30
  }
  LODWORD(v70) = *(_DWORD *)(*(_DWORD *)v5 + 4396);
  v71 = (float)((float)1.0 / (float)_FP10);
  DWORD2(v70) = *(_DWORD *)(*(_DWORD *)v5 + 4392);
  v231 = v70;
  DWORD1(v70) = ((unsigned int)(v61 - ((2753184165u * (unsigned __int64)v61) >> 32)) >> 1)
              + ((2753184165u * (unsigned __int64)v61) >> 32);
  v72 = (float)((float)1.0 / (float)_FP9);
  v73 = (float)((float)(__int64)v70 / (float)v63);
  LODWORD(v70) = (grainRand.MT[v61 % 0x270] >> 11) ^ grainRand.MT[v61 % 0x270];
  v74 = (float)((float)*(__int64 *)((char *)&v70 + 4) / (float)v62);
  v75 = ((((v70 & 0xFF3A58AD) << 7) ^ (unsigned int)v70) << 15) & 0xEFC60000 ^ ((v70 & 0xFF3A58AD) << 7) ^ v70;
  v76 = (v75 >> 18) ^ v75;
  *((_QWORD *)&v77 + 1) = *(_QWORD *)((char *)&v70 - 4);
  *(double *)&v77 = (float)((float)((float)*(__int64 *)((char *)&v70 - 4) * (float)v62) * (float)2.3283064e-10);
  v78 = floor(x: v77);
  v79 = (float)((float)*(double *)&v78 * (float)v71);
  v80 = grainRand.MT[(v61 + 1) % 0x270];
  HIDWORD(v81) = (v80 >> 11) ^ v80;
  v82 = ((((HIDWORD(v81) & 0xFF3A58AD) << 7) ^ HIDWORD(v81)) << 15)
      & 0xEFC60000
      ^ ((HIDWORD(v81) & 0xFF3A58AD) << 7)
      ^ HIDWORD(v81);
  LODWORD(v81) = (v82 >> 18) ^ v82;
  *(double *)&v78 = (float)((float)((float)v81 * (float)v63) * 2.3283064e-10);
  v83 = floor(x: v78);
  idDeclRenderParm::Set(
    this: (idDeclRenderParm *)rpGrainScaleBias.r,
    x: v74,
    y: v73,
    z: v79,
    w: (float)((float)*(double *)&v83 * (float)v72));
  idDeclRenderParm::Set(
    this: (idDeclRenderParm *)rpGrainParms.r,
    x: (float)(*(float *)&v240 * 2.0),
    y: -*(float *)&v240,
    z: (float)(*(float *)&v249 - *(float *)&v235.ops.list),
    w: *(float *)&v235.ops.list);
  v84 = *(_DWORD *)v14;
  v85 = (unsigned int)(HIDWORD(v5) + 352480);
  v264.renderView = *(const idRenderView **)v5;
  v264.settings = (const renderSettings_t *)(HIDWORD(v5) + 352480);
  v264.areaNodeBounds = *(const idBounds **)(v84 + 48);
  v264.worldAreaSubspaceBounds = *(const idBounds **)(v84 + 64);
  v264.worldAreaGeometryBounds = *(const idBounds **)(v84 + 68);
  v264.numAreaNodes = *(_DWORD *)(v84 + 56);
  v264.numWorldAreas = *(_DWORD *)(v84 + 72);
  v264.areaNodeBoundsCulled = (unsigned __int8 *)(HIDWORD(v5) + 1024);
  v264.worldAreaSubspaceBoundsCulled = (unsigned __int8 *)(HIDWORD(v5) + 9216);
  v264.worldAreaGeometryBoundsCulled = (unsigned __int8 *)(HIDWORD(v5) + 17408);
  RenderCull(parms: &v264);
  v86 = *(const idRenderView **)v5;
  v87 = *(_DWORD *)v14;
  v266.areaNodeBoundsCulled = (const unsigned __int8 *)(HIDWORD(v5) + 1024);
  v266.settings = (const renderSettings_t *)(HIDWORD(v5) + 352480);
  v266.renderView = v86;
  v266.areaNodeOcclusionIndex = *(const int **)(v87 + 52);
  v266.areaNodeOcclusionQuery = v86->occlusionState->nodeOcclusionQuery;
  v266.areaNodeBounds = *(const idBounds **)(v87 + 48);
  v266.areaNodes = *(const areaNode_t **)(v87 + 44);
  v266.numAreaNodes = *(_DWORD *)(v87 + 56);
  v89 = *(_DWORD *)(v87 + 72);
  v266.occlusionTestNodes = (int *)(HIDWORD(v5) + 189824);
  v266.numOcclusionTestNodes = (int *)(HIDWORD(v5) + 352412);
  v266.nodeWorldAreas = (nodeWorldArea_t *)(HIDWORD(v5) + 25600);
  v266.numNodeWorldAreas = (int *)(HIDWORD(v5) + 352384);
  v266.numWorldAreas = v89;
  RenderWalkBSP(parms: &v266);
  v273.temp = (unsigned __int8 *)HIDWORD(v5);
  v273.settings = (const renderSettings_t *)(HIDWORD(v5) + 352480);
  LODWORD(v90) = 107344;
  v91 = *(const idRenderView **)v5;
  v273.tempSize = 1024;
  v92 = *(_DWORD *)v14;
  HIDWORD(v90) = HIDWORD(v5) + 17408;
  *(_QWORD *)&v235.ops.list = v90;
  v273.renderView = v91;
  v93 = *(_DWORD *)(HIDWORD(v5) + 352384);
  v232 = v243;
  v94 = (const idRenderModelSurface **)(HIDWORD(v5) + 123904);
  v233 = *(float *)&v235.usingTempOps;
  v229 = *(float *)&v237;
  v278 = v5;
  v247[1].objectPtr = v234;
  p_binaryModelState = (idStaticList<bool,1024> *)v246;
  v95 = (const viewWorldArea_t *)(HIDWORD(v5) + 58368);
  v276 = *(__int64 *)((char *)&v5 + 4);
  v248 = v85;
  v96 = (const idRenderModelCommitted **)(HIDWORD(v5) + 173056);
  v88 = HIDWORD(v5) + 25600;
  v249 = *(__int64 *)((char *)&v85 + 4);
  v97 = (int *)(HIDWORD(v5) + 190080);
  HIDWORD(v14) = HIDWORD(v5) + 189824;
  v240 = v14;
  v98 = (const idRenderModelCommitted **)(HIDWORD(v5) + 206464);
  v99 = (const idRenderLightCommitted **)(HIDWORD(v5) + 222848);
  LODWORD(v90) = *(_DWORD *)(v92 + 107344);
  v235.constants.list = (parmValue_t *)(HIDWORD(v5) + 123904);
  v223 = (const idRenderModelCommitted **)(HIDWORD(v5) + 173312);
  HIDWORD(v231) = HIDWORD(v5) + 173440;
  v273.linkedRenderModels = (const idRenderModelCommitted *const *)v90;
  v273.numLinkedRenderModels = *(_DWORD *)(v92 + 107348);
  v273.linkedRenderLights = *(const idRenderLightCommitted *const **)(v92 + 123744);
  v100 = *(_DWORD *)(v92 + 123748);
  v273.nodeWorldAreas = (const nodeWorldArea_t *)(HIDWORD(v5) + 25600);
  v273.worldAreaGeometryBoundsCulled = (const unsigned __int8 *)(HIDWORD(v5) + 17408);
  v273.numNodeWorldAreas = v93;
  v273.worldAreaSubspaceBoundsCulled = (const unsigned __int8 *)(HIDWORD(v5) + 9216);
  v273.numLinkedRenderLights = v100;
  v101 = v244;
  v273.worldAreas = *(const worldArea_t **)(v92 + 60);
  v273.numWorldAreas = *(_DWORD *)(v92 + 72);
  v273.addAlwaysModels = *(const idRenderModelCommitted **)(v92 + 140144);
  v273.occlusionState = v91->occlusionState;
  v273.occlusionTestNodes = (int *)(HIDWORD(v5) + 189824);
  v273.numOcclusionTestNodes = (int *)v243;
  v273.viewWorldAreas = (viewWorldArea_t *)(HIDWORD(v5) + 58368);
  v273.numViewWorldAreas = v244;
  v273.viewWorldSurfaces = (const idRenderModelSurface **)(HIDWORD(v5) + 123904);
  v273.numViewWorldSurfaces = *(int **)&v235.usingTempOps;
  v273.sceneModels = (const idRenderModelCommitted **)(HIDWORD(v5) + 173056);
  v273.viewAugmentModels = (const idRenderModelCommitted **)(HIDWORD(v5) + 173312);
  v273.viewModels = v237;
  v273.numViewModels = (int *)&v234->isDefault;
  v273.numSceneModels = v246;
  v273.numViewAugmentModels = v245;
  v273.viewLights = (const idRenderLightCommitted **)(HIDWORD(v5) + 173440);
  v273.numViewLights = (int *)v235.constants.size;
  v273.occlusionTestWorldAreas = (int *)(HIDWORD(v5) + 190080);
  v273.numOcclusionTestWorldAreas = (int *)(HIDWORD(v5) + 352416);
  v273.occlusionTestModels = (const idRenderModelCommitted **)(HIDWORD(v5) + 206464);
  v273.numOcclusionTestModels = &v230->firstSurface;
  v273.occlusionTestLights = (const idRenderLightCommitted **)(HIDWORD(v5) + 222848);
  v273.numOcclusionTestLights = (int *)(HIDWORD(v5) + 352424);
  RenderGather(parms: &v273);
  idRenderLog::OpenMainBlock(this: v239, block: MRB_PPU_GPU_SYNC);
  console->BeginTimeRange(this: console, a2: RANGE_RENDER, a3: &idColor::colorRed);
  GL_WaitForEndFrame();
  console->BeginTimeRange(this: console, a2: RANGE_RENDER, a3: &idColor::colorRed);
  v102 = __PAIR64__(v276, v278);
  num = v235.ops.num;
  if ( tr.renderingIsReadyForSwapbuffers )
  {
    idRenderSystemLocal::SwapBuffers(this: &tr, hdc, forceVsync: false);
    tr.renderingIsReadyForSwapbuffers = false;
  }
  idRenderLog::CloseMainBlock(this: v239);
  (*(void (__fastcall **)(_DWORD, int, idColor *))(**(_DWORD **)(v88 - 21556) + 80))(
    a1: *(_DWORD *)(v88 - 21556),
    a2: 1,
    a3: &idColor::colorGreen);
  GL_GetLastFrameTime(startGPUTimeMicroSec: &tr.pc.startGPUTimeMicroSec, endGPUTimeMicroSec: &tr.pc.endGPUTimeMicroSec);
  (*(void (__fastcall **)(_DWORD, int, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(v88 - 21556) + 68))(
    a1: *(_DWORD *)(v88 - 21556),
    a2: 2,
    a3: HIDWORD(tr.pc.startGPUTimeMicroSec),
    a4: tr.pc.startGPUTimeMicroSec,
    a5: tr.pc.endGPUTimeMicroSec);
  v232 = &resolutionScale;
  v104 = HIDWORD(tr.pc.startGPUTimeMicroSec) - LODWORD(tr.pc.startGPUTimeMicroSec);
  idResolutionScale::SetCurrentGPUFrameTime(
    this: &resolutionScale,
    microseconds: HIDWORD(tr.pc.startGPUTimeMicroSec) - LODWORD(tr.pc.startGPUTimeMicroSec));
  v229 = 1.0;
  v233 = 1.0;
  v105 = 1.0;
  time_GPUFrameTime = v104;
  if ( !tr.automaticBackgroundSwapsEnabled )
  {
    idResolutionScale::GetCurrentResolutionScale(this: &resolutionScale, x: &v229, y: &v233);
    v105 = v229;
  }
  v106 = *p_screenView;
  _FP11 = (float)((float)v105 - (float)0.92500001);
  viewIndex = currentScreenView->viewIndex;
  __asm { fsel      f0, f11, f0, f13 }
  v229 = _FP0;
  DWORD1(v110) = v106->screenRect.y1;
  v111 = v106->screenRect.x2 - v106->screenRect.x1;
  LODWORD(v110) = v106->screenRect.y2 - DWORD1(v110) + 1;
  DWORD2(v110) = v111 + 1;
  v235.ops.num = (int)(float)((float)(__int64)v110 * v233);
  LODWORD(v240) = (int)(float)((float)*(__int64 *)((char *)&v110 + 4) * (float)_FP0);
  idRender::SetRenderSize(this: (idRender *)HIDWORD(v102), viewIndex, renderWidth_: v240, renderHeight_: v235.ops.num);
  *(_DWORD *)(*(_DWORD *)v102 + 4392) = tr.renderWidth;
  *(_DWORD *)(*(_DWORD *)v102 + 4396) = tr.renderHeight;
  *(_DWORD *)(*(_DWORD *)v102 + 4408) = 0;
  *(_DWORD *)(*(_DWORD *)v102 + 4412) = 0;
  *(_DWORD *)(*(_DWORD *)v102 + 4416) = tr.renderWidth - 1;
  *(_DWORD *)(*(_DWORD *)v102 + 4420) = tr.renderHeight - 1;
  v112 = *(_DWORD **)v102;
  v112[1106] = *(_DWORD *)(*(_DWORD *)v102 + 4408);
  v112[1107] = v112[1103];
  v112[1108] = v112[1104];
  v112[1109] = v112[1105];
  idParmState::SetRenderPositionToViewTexture(
    this: renderThreadParmState,
    windowWidth: *(_DWORD *)(*(_DWORD *)v102 + 4384),
    windowHeight: *(_DWORD *)(*(_DWORD *)v102 + 4388),
    renderWidth: *(_DWORD *)(*(_DWORD *)v102 + 4392),
    renderHeight: *(_DWORD *)(*(_DWORD *)v102 + 4396));
  if ( *(_BYTE *)(*(_DWORD *)v102 + 3744) != 0 )
  {
    idRenderMatrix::TransformModelToClip(
      src: (const idVec3 *)(*(_DWORD *)v102 + 3748),
      modelMatrix: (const idRenderMatrix *)(*(_DWORD *)v102 + 3936),
      projectionMatrix: (const idRenderMatrix *)(*(_DWORD *)v102 + 3808),
      eye: &v288,
      clip: &v280);
    idRenderMatrix::TransformClipToDevice(clip: &v280, normalized: &v275);
    DWORD1(v113) = *(_DWORD *)(*(_DWORD *)v102 + 4396);
    LODWORD(v114) = DWORD1(v113);
    HIDWORD(v115) = *(_DWORD *)(*(_DWORD *)v102 + 4384);
    LODWORD(v115) = *(_DWORD *)(*(_DWORD *)v102 + 4392);
    HIDWORD(v114) = *(_DWORD *)(*(_DWORD *)v102 + 4388);
    *(_QWORD *)&v235.ops.list = v114;
    v240 = v115;
    *((_QWORD *)&v113 + 1) = __PAIR64__(HIDWORD(v115), HIDWORD(v114));
    v248 = *(_QWORD *)((char *)&v113 + 4);
    v249 = __PAIR64__(HIDWORD(v115), HIDWORD(v114));
    idDeclRenderParm::Set(
      this: rp->radialBlurCenter,
      x: (float)((float)((float)((float)v115 * (float)(v275.x + (float)1.0)) * (float)0.5)
            / (float)*(__int64 *)((char *)&v113 + 4)),
      y: (float)((float)((float)((float)v114 * (float)(v275.y + (float)1.0)) * (float)0.5)
            / (float)__SPAIR64__(HIDWORD(v115), HIDWORD(v114))),
      z: 0.0,
      w: 0.0);
  }
  idDeclRenderParm::SetImage(
    this: (idDeclRenderParm *)rpViewColorLastFrame.r,
    image: tr.imgViewColor[*(_DWORD *)(*(_DWORD *)v102 + 1876)]);
  idDeclRenderParm::SetImage(
    this: (idDeclRenderParm *)rpDistortionLastFrame.r,
    image: tr.imgDistortion[*(_DWORD *)(*(_DWORD *)v102 + 1876)]);
  Name = idFile_MTP::GetName(pObstacle: (bfx::ObstacleImpl *)&tr);
  GL_StartFrame(frame: Name);
  D3DDevice_SetShaderGPRAllocation(pDevice: d3d, Flags: 0, VertexShaderCount: 0x20u, PixelShaderCount: 0x60u);
  v117 = *(const idRenderView **)v102;
  if ( *(_DWORD *)(*(_DWORD *)v102 + 1880) != 0 )
  {
    v271.settings = (const renderSettings_t *)v85;
    v271.renderView = v117;
    v271.rpUserEnvMap = (const idDeclRenderParm *)rpUserEnvMap.r;
    v271.rpColor = (const idDeclRenderParm *)rpColor.r;
    v271.rpEnvRMatrix = (const idDeclRenderParm *)rpEnvRMatrix.r;
    v271.rpEnvBlendMip = (const idDeclRenderParm *)rpEnvBlendMip.r;
    v271.rpEnvTMatrix = (const idDeclRenderParm *)rpEnvTMatrix.r;
    v271.rpAmbientEnvMap = (const idDeclRenderParm *)rpAmbientEnvMap.r;
    v271.rpEnvSMatrix = (const idDeclRenderParm *)rpEnvSMatrix.r;
    v271.renderDestDynamicEnv = tr.renderDestDynamicEnv[v117->viewIndex];
    v271.imgDynamicEnv = tr.imgDynamicEnvironment[v117->viewIndex];
    v271.imgAmbientEnv = idParmBlock::GetImage(
                           this: &v117->envBlend.env->parmBlock,
                           parm: (const idDeclRenderParm *)rpAmbientEnvMap.r);
    v271.imgUserEnv = idParmBlock::GetImage(
                        this: (idParmBlock *)(*(_DWORD *)(*(_DWORD *)v102 + 1880) + 56),
                        parm: (const idDeclRenderParm *)rpUserEnvMap.r);
    v118 = *(_DWORD *)v102;
    v271.unitCubeTris = tr.unitCubeModel->surfaces.list->geometry;
    Vector = (float *)idParmBlock::GetVector(
                        this: &v235,
                        result: (idParmBlock *)(*(_DWORD *)(v118 + 1880) + 56),
                        parm: (const idDeclRenderParm *)rpEnvMapRotation.r);
    v252.mat[0].x = *Vector;
    v252.mat[0].y = Vector[1];
    v252.mat[0].z = Vector[2];
    v120 = (float *)idAngles::ToMat3(this: (idAngles *)&v252.mat[2].z, result: &v252);
    v121 = (envBlend_t *)(*(_DWORD *)v102 + 1880);
    v271.envMapRotation.mat[0].x = *v120;
    v271.envMapRotation.mat[0].y = v120[1];
    v271.envMapRotation.mat[0].z = v120[2];
    v271.envMapRotation.mat[1].x = v120[3];
    v271.envMapRotation.mat[1].y = v120[4];
    v271.envMapRotation.mat[1].z = v120[5];
    v271.envMapRotation.mat[2].x = v120[6];
    v271.envMapRotation.mat[2].y = v120[7];
    v271.envMapRotation.mat[2].z = v120[8];
    v271.progBlend = tr.progEnvironmentBlend;
    v271.envBlend = v121;
    RenderDynamicEnv(parms: &v271);
  }
  v265.settings = (const renderSettings_t *)v85;
  v265.viewWorldAreas = v95;
  v122 = **(_DWORD **)&v235.usingTempOps;
  p_binaryModelState = &world_->binaryModelState;
  list = world_->binaryModelState.list;
  v124 = *v246;
  v265.numViewModels = *(_DWORD *)&v234->isDefault;
  v265.numViewWorldSurfaces = v122;
  v265.renderDestDefault = renderDestScaledColorWithFeedback;
  v265.numSceneModels = v124;
  v265.viewModels = v237;
  v265.sceneModels = v96;
  v265.binaryModelState = list;
  v125 = *(_DWORD *)v102;
  v126 = *v101;
  v127 = *(_DWORD *)v14;
  v265.renderView = *(const idRenderView **)v102;
  v265.viewWorldSurfaces = v94;
  v265.numViewWorldAreas = v126;
  v128 = *(_DWORD *)(v127 + 120);
  if ( v128 != 0 && *(int *)(v128 + 1108) > 0 )
    v265.occlusionBaseTriangles = *(const idTriangles **)(*(_DWORD *)(v128 + 1104) + 16);
  else
    v265.occlusionBaseTriangles = nullptr;
  thread = (int *)v235.thread;
  v265.progOccluderDepthOnly = tr.progOccluderDepthOnly;
  v265.progRadiosityPreview = nullptr;
  v265.progOutside = (const idDeclRenderProg *)progOutside.r;
  v265.imgBlack = globalImages->blackImage;
  v265.extraClears = r_extraClears.valueInteger;
  v130 = *(occlusionState_t **)(v125 + 4464);
  v265.drawSurfs = (drawSurf_t *)(HIDWORD(v102) + 224896);
  v265.numDrawSurfs = (int *)v235.thread;
  v265.occlusionState = v130;
  RenderDepth(parms: &v265);
  v269.occlusionTestNodes = (int *)HIDWORD(v14);
  v269.settings = (const renderSettings_t *)v85;
  v269.occlusionTestWorldAreas = v97;
  v269.occlusionTestLights = v99;
  v269.occlusionTestModels = v98;
  v131 = *v227;
  firstSurface = v230->firstSurface;
  v133 = *v225;
  HIDWORD(v14) = *(_DWORD *)v102;
  v269.numOcclusionTestNodes = LODWORD(v243->dropMilliseconds);
  v269.numOcclusionTestWorldAreas = v131;
  v269.numOcclusionTestModels = firstSurface;
  v269.numOcclusionTestLights = v133;
  v134 = *(_DWORD *)v14;
  v269.renderView = (const idRenderView *)HIDWORD(v14);
  v269.areaNodeOcclusionIndex = *(const int **)(v134 + 52);
  v269.areaNodeBounds = *(const idBounds **)(v134 + 48);
  v269.worldAreaGeometryBounds = *(const idBounds **)(v134 + 68);
  v269.numWorldAreas = *(_DWORD *)(v134 + 72);
  v269.renderDestDefault = renderDestScaledColor;
  v269.progDepthOnly = tr.progDepthOnly;
  v269.unitCubeTris = tr.unitCubeModel->surfaces.list->geometry;
  v269.zeroOneCubeTris = tr.zeroOneCubeModel->surfaces.list->geometry;
  v269.occlusionState = *(occlusionState_t **)(HIDWORD(v14) + 4464);
  RenderOcclusion(parms: &v269);
  idRender::SetupCaptureParms(
    this: (idRender *)HIDWORD(v102),
    parms: &v292,
    capture: CAPTURE_VIEW_DEPTH,
    createMipMaps: false,
    viewIndex: *(_DWORD *)(*(_DWORD *)v102 + 1876));
  v292.renderDestDefault = renderDestScaledColorWithFeedback;
  RenderCapture(parms: &v292);
  idRender::SetupCaptureParms(
    this: (idRender *)HIDWORD(v102),
    parms: &v290,
    capture: CAPTURE_FEEDBACK,
    createMipMaps: false,
    viewIndex: *(_DWORD *)(*(_DWORD *)v102 + 1876));
  v290.renderDestDefault = renderDestScaledColorWithFeedback;
  RenderCapture(parms: &v290);
  idRender::SetupCaptureParms(
    this: (idRender *)HIDWORD(v102),
    parms: &v291,
    capture: CAPTURE_VIEW_COLOR,
    createMipMaps: false,
    viewIndex: *(_DWORD *)(*(_DWORD *)v102 + 1876));
  v291.renderDestDefault = renderDestScaledColorWithFeedback;
  RenderCapture(parms: &v291);
  v135 = *(const idRenderView **)v102;
  v136 = *thread;
  v262.settings = (const renderSettings_t *)v85;
  v262.drawSurfs = (drawSurf_t *)(HIDWORD(v102) + 224896);
  v262.sortedDrawSurfs = (drawSurf_t **)(HIDWORD(v102) + 323200);
  v262.renderPasses = (renderPassSurfaces_t *)(HIDWORD(v102) + 352440);
  v262.renderView = v135;
  v262.numDrawSurfs = v136;
  v228 = (drawSurf_t **)(HIDWORD(v102) + 323200);
  v230 = (renderPassSurfaces_t *)(HIDWORD(v102) + 352440);
  RenderSort(parms: &v262);
  if ( *(_BYTE *)(*(_DWORD *)v102 + 1944) != 0 )
  {
    v140 = v239;
    idRenderLog::OpenBlock(
      this: v239,
      fmt: "ForegroundLoadFeedbackBuffer",
      a3: v139,
      a4: v138,
      a5: v137,
      a6: v217,
      a7: v218,
      a8: v219,
      a9: v220,
      a10: v221,
      a11: v222);
    v141 = v238;
    idVirtualTextureSystem::PushFeedback(
      this: v238,
      data: v238->feedbackBuffer,
      width: 160,
      height: 128,
      bytePitch: v238->feedbackBufferPitch,
      forceHighestDetail: false);
    idVirtualTextureSystem::FinishFeedback(this: v141, lockPages: false, maxWaitTimeInSeconds: 0);
    if ( v140->logFile != nullptr )
      idRenderLog::LogCloseBlock(this: v140, label: RENDER_LOG_INDENT_BLOCK);
  }
  v247[0].objectPtr = renderDestScaledColor;
  GL_SetRenderDestination(destination: v247, level: 0, side: 0);
  if ( r_skipDimShadows.valueInteger == 0 )
  {
    v142 = *(const idRenderView **)v102;
    if ( *(_BYTE *)(*(_DWORD *)v102 + 1946) == 0 )
    {
      v272.settings = (const renderSettings_t *)v85;
      v272.renderView = v142;
      v143 = *(_DWORD *)v14;
      v240 = v85;
      v272.dimShadowModelSlaves = (__int16 *)(HIDWORD(v102) + 339584);
      v238 = (idVirtualTextureSystem *)rpViewColor.r;
      *(_QWORD *)&v235.ops.list = v102;
      v235.thread = (threadId_t)rpWindowPosToDimShadowBlurQ.r;
      v272.linkedRenderModels = *(const idRenderModelCommitted *const **)(v143 + num);
      v272.numLinkedRenderModels = *(_DWORD *)(v143 + 107348);
      v272.dimShadowModels = *(const idRenderModelCommitted **)(v143 + 140148);
      geometry = tr.extrudeBoxModel->surfaces.list->geometry;
      v272.renderDestDimShadow = tr.renderDestDimShadow;
      v272.renderDestDefault = renderDestScaledColor;
      v272.extrudeBox = geometry;
      imgViewColor = v142->imgViewColor;
      v272.rpViewColor = (const idDeclRenderParm *)rpViewColor.r;
      v272.rpDimShadowFade = (const idDeclRenderParm *)rpDimShadowFade.r;
      v272.rpDimShadowExtrude = (const idDeclRenderParm *)rpDimShadowExtrude.r;
      v272.rpDimShadowClipPlane = (const idDeclRenderParm *)rpDimShadowClipPlane.r;
      v272.imgViewColor = imgViewColor;
      v272.rpWindowPosToDimShadowBlurS = (const idDeclRenderParm *)rpWindowPosToDimShadowBlurS.r;
      v272.rpWindowPosToDimShadowBlurT = (const idDeclRenderParm *)rpWindowPosToDimShadowBlurT.r;
      v272.rpWindowPosToDimShadowBlurR = (const idDeclRenderParm *)rpWindowPosToDimShadowBlurR.r;
      v272.rpWindowPosToDimShadowBlurQ = (const idDeclRenderParm *)rpWindowPosToDimShadowBlurQ.r;
      v272.rpVertexMorphScale = (const idDeclRenderParm *)rpVertexMorphScale.r;
      v272.progDimShadowCreate = (const idDeclRenderProg *)progDimShadowCreate.r;
      v272.progDimShadowCreateAlpha = (const idDeclRenderProg *)progDimShadowCreateAlpha.r;
      v272.progDimShadowDrawHighQuality = (const idDeclRenderProg *)progDimShadowDrawHighQuality.r;
      v272.progDimShadowCreateWound = (const idDeclRenderProg *)progDimShadowCreateWound.r;
      v272.progDimShadowDraw = (const idDeclRenderProg *)progDimShadowDraw.r;
      v272.numDimShadows = (int *)(HIDWORD(v102) + 352436);
      v272.progDimShadowStencil = (const idDeclRenderProg *)progDimShadowStencil.r;
      v272.progDimShadowDebugDraw = (const idDeclRenderProg *)progDimShadowDebugDraw.r;
      occlusionState = v142->occlusionState;
      v272.modelDimShadowState = (unsigned __int8 *)v235.constants.num;
      v272.occlusionState = occlusionState;
      RenderDimShadows(parms: &v272);
      v94 = (const idRenderModelSurface **)v235.constants.list;
      v102 = *(_QWORD *)&v235.ops.list;
      v85 = v240;
    }
  }
  v147 = *(const idRenderView **)v102;
  v279.shadowBufferParms.options.polyOfsFactor = 1.0;
  v279.shadowBufferParms.options.parallelPolyOfsFactor = 1.0;
  v279.shadowBufferParms.options.occluderFacing = HIDWORD(v85);
  v279.settings = (const renderSettings_t *)v85;
  v279.shadowBufferParms.options.shadowBufferSize = 1024;
  v279.shadowBufferParms.options.singleSide = -1;
  v279.shadowBufferParms.options.sliceStep = 512.0;
  v279.shadowBufferParms.options.skipShadows = BYTE3(v85);
  v279.shadowBufferParms.options.polyOfsUnits = 200.0;
  v279.shadowBufferParms.options.skipShadowOccluders = BYTE3(v85);
  v279.shadowBufferParms.options.parallelPolyOfsUnits = 200.0;
  v279.shadowBufferParms.options.skipShadowModelCPUCulling = BYTE3(v85);
  v279.shadowBufferParms.options.skipShadowSurfaceCPUCulling = BYTE3(v85);
  v279.renderView = v147;
  v279.drawSurfParms.settings = (const renderSettings_t *)v85;
  v279.drawSurfParms.renderView = v147;
  v279.shadowBufferParms.options.skipShadowModelSort = BYTE3(v85);
  v279.drawSurfParms.allowInGameGUIs = BYTE3(v85);
  idRender::SetupCaptureParms(
    this: (idRender *)HIDWORD(v102),
    parms: &v279.drawSurfParms.captureParms,
    capture: CAPTURE_GUI_IMAGE,
    createMipMaps: false,
    viewIndex: v147->viewIndex);
  v148 = *(const idRenderView **)v102;
  v279.drawSurfParms.renderDestDefault = renderDestScaledColor;
  v279.shadowBufferParms.settings = (const renderSettings_t *)v85;
  v149 = *(const idBounds ***)v14;
  v279.drawSurfParms.renderDestGui = tr.renderDestGui;
  v279.shadowBufferParms.renderView = v148;
  v279.shadowBufferParms.worldAreaSubspaceBounds = v149[16];
  v279.shadowBufferParms.worldAreaGeometryBounds = v149[17];
  v279.shadowBufferParms.worldAreaSubspaceBoundsCulled = (const unsigned __int8 *)(HIDWORD(v102) + 9216);
  v150 = ((int (__fastcall *)(const idBounds **))LODWORD((*v149)[5].b[1].x))(a1: v149);
  v151 = *(_DWORD *)v14;
  v279.shadowBufferParms.worldModel = v150 == 0
                                    ? nullptr
                                    : *(const idRenderModelCommitted **)&v235.constants.granularity;
  v152 = *(_DWORD *)&v234->isDefault;
  v153 = *(_DWORD *)v235.constants.size;
  v279.shadowBufferParms.linkedRenderModels = *(const idRenderModelCommitted *const **)(v151 + num);
  v154 = *(_DWORD *)(v151 + 107348);
  v279.shadowBufferParms.options.skipShadows = r_skipShadows.valueInteger != 0;
  v279.shadowBufferParms.numLinkedRenderModels = v154;
  v155 = **(_DWORD **)&v235.usingTempOps;
  v279.numViewLights = v153;
  v279.shadowBufferParms.renderDestShadow = &renderDestShadow;
  v279.viewLights = (const idRenderLightCommitted **)HIDWORD(v231);
  v279.numViewModels = v152;
  v279.numViewWorldSurfaces = v155;
  v279.viewModels = v237;
  v279.shadowBufferParms.rpShadowBufferResolution = (const idDeclRenderParm *)rpShadowBufferResolution.r;
  v279.viewWorldSurfaces = v94;
  v279.shadowBufferParms.options.shadowBufferSize = SHADOW_BUFFER_DIMENSION;
  v279.shadowBufferParms.options.skipShadowOccluders = r_skipShadowOccluders.valueInteger != 0;
  v279.shadowBufferParms.options.skipShadowModelCPUCulling = r_skipShadowModelCPUCulling.valueInteger != 0;
  v279.shadowBufferParms.options.occluderFacing = r_sb_occluderFacing.valueInteger;
  v279.rpLightTranslation = (const idDeclRenderParm *)rpLightTranslation.r;
  v279.shadowBufferParms.options.singleSide = r_sb_singleSide.valueInteger;
  v279.rpLightRotation = (const idDeclRenderParm *)rpLightRotation.r;
  v279.shadowBufferParms.renderDestDefault = renderDestScaledColor;
  v279.shadowBufferParms.options.sliceStep = r_sb_sliceStep.valueFloat;
  v279.shadowBufferParms.options.polyOfsFactor = r_sb_polyOfsFactor.valueFloat;
  v279.shadowBufferParms.modelConsideredAsOccluder = (unsigned __int8 *)(HIDWORD(v102) + 347776);
  v279.shadowBufferParms.options.polyOfsUnits = r_sb_polyOfsUnits.valueFloat;
  v279.shadowBufferParms.options.skipShadowSurfaceCPUCulling = r_skipShadowSurfaceCPUCulling.valueInteger != 0;
  v279.shadowBufferParms.options.parallelPolyOfsFactor = r_sb_parallelPolyOfsFactor.valueFloat;
  v279.rpLightScale = (const idDeclRenderParm *)rpLightScale.r;
  v279.shadowBufferParms.options.parallelPolyOfsUnits = r_sb_parallelPolyOfsUnits.valueFloat;
  v279.rpLightOscillationAmp = (const idDeclRenderParm *)rpLightOscillationAmp.r;
  v279.rpLightOscillationFreq = (const idDeclRenderParm *)rpLightOscillationFreq.r;
  *(_QWORD *)&v235.ops.list = v102;
  v240 = v85;
  *(_DWORD *)&v235.constants.granularity = &rpWindowPosToProjectedShadowS;
  v235.constants.list = (parmValue_t *)&rpWindowPosToProjectedShadowT;
  v235.constants.num = (int)&rpWindowPosToProjectedShadowR;
  v279.rpWindowPosToProjectedTexR = (const idDeclRenderParm *)rpWindowPosToProjectedTexR.r;
  v279.rpLightOscillationPhase = (const idDeclRenderParm *)rpLightOscillationPhase.r;
  v279.rpWindowPosToProjectedTexS = (const idDeclRenderParm *)rpWindowPosToProjectedTexS.r;
  v279.rpWindowPosToProjectedTexT = (const idDeclRenderParm *)rpWindowPosToProjectedTexT.r;
  v279.rpWindowPosToProjectedShadowQ = (const idDeclRenderParm *)rpWindowPosToProjectedShadowQ.r;
  v279.rpShadowProjectionS = (const idDeclRenderParm *)rpShadowProjectionS.r;
  v279.rpWindowPosToProjectedShadowS = (const idDeclRenderParm *)rpWindowPosToProjectedShadowS.r;
  v279.rpWindowPosToProjectedShadowT = (const idDeclRenderParm *)rpWindowPosToProjectedShadowT.r;
  v279.rpWindowPosToProjectedShadowR = (const idDeclRenderParm *)rpWindowPosToProjectedShadowR.r;
  v279.rpWindowPosToProjectedTexQ = (const idDeclRenderParm *)rpWindowPosToProjectedTexQ.r;
  v279.rpShadowProjectionR = (const idDeclRenderParm *)rpShadowProjectionR.r;
  v279.rpShadowProjectionT = (const idDeclRenderParm *)rpShadowProjectionT.r;
  v279.progDepthOnly = tr.progDepthOnly;
  v279.progDeferredPointLight = tr.progDeferredPointLight;
  v279.progDeferredSpotLight = tr.progDeferredSpotLight;
  v279.rpLightProjectionQ = (const idDeclRenderParm *)rpLightProjectionQ.r;
  v279.progBlendedLightDebugDraw = tr.progBlendedLightDebugDraw;
  v279.rpStaticSpecularScale = (const idDeclRenderParm *)rpStaticSpecularScale.r;
  v279.rpLocalToLightT = (const idDeclRenderParm *)rpLocalToLightT.r;
  v279.rpShadowProjectionQ = (const idDeclRenderParm *)rpShadowProjectionQ.r;
  v156 = (int *)(HIDWORD(v102) + 352432);
  v279.rpGlobalLightOrigin = (const idDeclRenderParm *)rpGlobalLightOrigin.r;
  v279.rpStaticSpecularVector = (const idDeclRenderParm *)rpStaticSpecularVector.r;
  v279.rpLightProjectionS = (const idDeclRenderParm *)rpLightProjectionS.r;
  v279.rpLightProjectionT = (const idDeclRenderParm *)rpLightProjectionT.r;
  v279.rpLightProjectionR = (const idDeclRenderParm *)rpLightProjectionR.r;
  v279.rpLocalToLightQ = (const idDeclRenderParm *)rpLocalToLightQ.r;
  v279.rpLightFade = (const idDeclRenderParm *)rpLightFade.r;
  v279.progDeferredParallelLight = tr.progDeferredParallelLight;
  v279.renderDestDefault = renderDestScaledColor;
  v279.rpLocalToLightS = (const idDeclRenderParm *)rpLocalToLightS.r;
  v279.rpLocalToLightR = (const idDeclRenderParm *)rpLocalToLightR.r;
  p_list = (const bool **)&p_binaryModelState->list;
  HIDWORD(v231) = HIDWORD(v102) + 352432;
  v158 = tr.zeroOneCubeModel->surfaces.list->geometry;
  v279.binaryModelState = p_binaryModelState->list;
  v279.numShadows = (int *)(HIDWORD(v102) + 352432);
  v279.zeroOneCubeTris = v158;
  RenderLights(parms: &v279);
  v159 = *(_QWORD *)&v235.ops.list;
  v160 = v240;
  if ( HIBYTE(v235.ops.list[44062].parmIndexB) == 0 )
  {
    v252.mat[1].z = *(float *)v235.ops.num;
    LODWORD(v252.mat[1].y) = v240;
    LODWORD(v252.mat[2].x) = tr.progGlobalFog;
    LODWORD(v252.mat[2].y) = tr.unitSquareModel->surfaces.list->geometry;
    RenderFog(parms: (const renderFogParms_t *)&v252.mat[1].y);
  }
  if ( *(_BYTE *)(HIDWORD(v159) + 352493) != 0 )
  {
    v164 = v230;
    v165 = v228;
  }
  else
  {
    v161 = *(const idRenderView **)v159;
    v286.settings = (const renderSettings_t *)v160;
    v286.pass = RENDERPASS_EMISSIVE;
    v286.drawSurfParms.allowInGameGUIs = BYTE3(v160);
    v286.drawSurfParms.settings = (const renderSettings_t *)v160;
    v286.renderView = v161;
    v286.drawSurfParms.renderView = v161;
    idRender::SetupCaptureParms(
      this: (idRender *)HIDWORD(v159),
      parms: &v286.drawSurfParms.captureParms,
      capture: CAPTURE_GUI_IMAGE,
      createMipMaps: false,
      viewIndex: v161->viewIndex);
    v162 = *(_DWORD *)v159;
    v163 = *p_list;
    v286.drawSurfParms.renderDestDefault = renderDestScaledColor;
    v286.renderDestDefault = renderDestScaledColor;
    v286.drawSurfParms.renderDestGui = tr.renderDestGui;
    v164 = v230;
    v165 = v228;
    v166 = *(_DWORD *)(v162 + 1876);
    v286.rpViewColor = (const idDeclRenderParm *)rpViewColor.r;
    v286.binaryModelState = v163;
    v286.renderPasses = v230;
    v286.sortedDrawSurfs = v228;
    v286.renderDestDistortion = tr.renderDestDistortion[v166];
    RenderPass(parms: &v286);
  }
  if ( *(_BYTE *)(HIDWORD(v159) + 352493) == 0 )
  {
    v167 = *(const idRenderView **)v159;
    v285.settings = (const renderSettings_t *)v160;
    v285.pass = RENDERPASS_BLEND;
    v285.drawSurfParms.settings = (const renderSettings_t *)v160;
    v285.drawSurfParms.allowInGameGUIs = true;
    v285.renderView = v167;
    v285.drawSurfParms.renderView = v167;
    idRender::SetupCaptureParms(
      this: (idRender *)HIDWORD(v159),
      parms: &v285.drawSurfParms.captureParms,
      capture: CAPTURE_GUI_IMAGE,
      createMipMaps: false,
      viewIndex: v167->viewIndex);
    v168 = *(_DWORD *)v159;
    v169 = *p_list;
    v285.drawSurfParms.renderDestDefault = renderDestScaledColor;
    v285.renderDestDefault = renderDestScaledColor;
    v285.drawSurfParms.renderDestGui = tr.renderDestGui;
    v170 = *(_DWORD *)(v168 + 1876);
    v285.rpViewColor = (const idDeclRenderParm *)rpViewColor.r;
    v285.binaryModelState = v169;
    v285.renderPasses = v164;
    v285.sortedDrawSurfs = v165;
    v285.renderDestDistortion = tr.renderDestDistortion[v170];
    RenderPass(parms: &v285);
  }
  v171 = (_BYTE *)(HIDWORD(v159) + 352499);
  if ( *(_BYTE *)(HIDWORD(v159) + 352499) == 0 )
  {
    v172 = *(const idRenderView **)v159;
    *(_QWORD *)&v281.pass = v160;
    v281.drawSurfParms.settings = (const renderSettings_t *)v160;
    v281.drawSurfParms.allowInGameGUIs = BYTE3(v160);
    v281.renderView = v172;
    v281.drawSurfParms.renderView = v172;
    idRender::SetupCaptureParms(
      this: (idRender *)HIDWORD(v159),
      parms: &v281.drawSurfParms.captureParms,
      capture: CAPTURE_GUI_IMAGE,
      createMipMaps: false,
      viewIndex: v172->viewIndex);
    v173 = *(_DWORD *)v159;
    v174 = *p_list;
    v281.renderDestDefault = renderDestScaledColor;
    v281.drawSurfParms.renderDestDefault = renderDestScaledColor;
    v281.drawSurfParms.renderDestGui = tr.renderDestGui;
    v175 = *(_DWORD *)(v173 + 1876);
    v281.renderDestDefault = renderDestScaledFeedback;
    v281.rpViewColor = (const idDeclRenderParm *)rpViewColor.r;
    v281.binaryModelState = v174;
    v281.renderPasses = v164;
    v281.sortedDrawSurfs = v165;
    v281.renderDestDistortion = tr.renderDestDistortion[v175];
    RenderPass(parms: &v281);
  }
  if ( *v171 == 0 )
  {
    v176 = *(const idRenderView **)v159;
    v282.settings = (const renderSettings_t *)v160;
    v282.pass = RENDERPASS_EMISSIVE;
    v282.drawSurfParms.settings = (const renderSettings_t *)v160;
    v282.drawSurfParms.allowInGameGUIs = BYTE3(v160);
    v282.renderView = v176;
    v282.drawSurfParms.renderView = v176;
    idRender::SetupCaptureParms(
      this: (idRender *)HIDWORD(v159),
      parms: &v282.drawSurfParms.captureParms,
      capture: CAPTURE_GUI_IMAGE,
      createMipMaps: false,
      viewIndex: v176->viewIndex);
    v177 = *(_DWORD *)v159;
    v178 = *p_list;
    v282.renderDestDefault = renderDestScaledColor;
    v282.drawSurfParms.renderDestDefault = renderDestScaledColor;
    v282.drawSurfParms.renderDestGui = tr.renderDestGui;
    v179 = *(_DWORD *)(v177 + 1876);
    v282.renderDestDefault = renderDestScaledFeedback;
    v282.rpViewColor = (const idDeclRenderParm *)rpViewColor.r;
    v282.binaryModelState = v178;
    v282.renderPasses = v164;
    v282.sortedDrawSurfs = v165;
    v282.renderDestDistortion = tr.renderDestDistortion[v179];
    RenderPass(parms: &v282);
  }
  if ( *v171 == 0 )
  {
    v180 = *(const idRenderView **)v159;
    v283.settings = (const renderSettings_t *)v160;
    v283.pass = RENDERPASS_EMISSIVE_ONLY;
    v283.drawSurfParms.settings = (const renderSettings_t *)v160;
    v283.drawSurfParms.allowInGameGUIs = BYTE3(v160);
    v283.renderView = v180;
    v283.drawSurfParms.renderView = v180;
    idRender::SetupCaptureParms(
      this: (idRender *)HIDWORD(v159),
      parms: &v283.drawSurfParms.captureParms,
      capture: CAPTURE_GUI_IMAGE,
      createMipMaps: false,
      viewIndex: v180->viewIndex);
    v181 = *(_DWORD *)v159;
    v182 = *p_list;
    v283.renderDestDefault = renderDestScaledColor;
    v283.drawSurfParms.renderDestDefault = renderDestScaledColor;
    v283.drawSurfParms.renderDestGui = tr.renderDestGui;
    v183 = *(_DWORD *)(v181 + 1876);
    v283.renderDestDefault = renderDestScaledFeedback;
    v283.rpViewColor = (const idDeclRenderParm *)rpViewColor.r;
    v283.binaryModelState = v182;
    v283.renderPasses = v164;
    v283.sortedDrawSurfs = v165;
    v283.renderDestDistortion = tr.renderDestDistortion[v183];
    RenderPass(parms: &v283);
  }
  if ( *v171 == 0 )
  {
    idRender::SetupCaptureParms(
      this: (idRender *)HIDWORD(v159),
      parms: &v293,
      capture: CAPTURE_GLARE_MAP,
      createMipMaps: true,
      viewIndex: *(_DWORD *)(*(_DWORD *)v159 + 1876));
    v293.renderDestDefault = renderDestScaledFeedback;
    RenderCapture(parms: &v293);
  }
  if ( *(_BYTE *)(HIDWORD(v159) + 352503) == 0 )
  {
    v270.renderView = *(const idRenderView **)v159;
    v270.settings = (const renderSettings_t *)v160;
    x = renderView_->r.godRaysPosition.x;
    godRaysRelativeToCamera = renderView_->r.godRaysRelativeToCamera;
    y = renderView_->r.godRaysPosition.y;
    godRaysMaterial = renderView_->r.godRaysMaterial;
    z = renderView_->r.godRaysPosition.z;
    godRaysSize = renderView_->r.godRaysSize;
    godRaysSourceSize = renderView_->r.godRaysSourceSize;
    v191 = renderView_->r.godRaysColor.x;
    v192 = renderView_->r.godRaysColor.y;
    v193 = renderView_->r.godRaysColor.z;
    v270.renderDestOffScreen = tr.renderDestDistortion[v270.renderView->viewIndex];
    v194 = v270.renderView->viewIndex;
    v270.progCreateGodRays = tr.progCreateGodRayMask;
    v270.progDrawGodRays = tr.progDrawGodRay;
    v270.rpGodRayMap = tr.rpDistortionMap;
    v270.imgOffScreen = tr.imgDistortion[v194];
    v195 = tr.unitSquareModel->surfaces.list->geometry;
    v270.godRaysPosition.x = x;
    v270.godRaysPosition.y = y;
    v270.godRaysRelativeToCamera = godRaysRelativeToCamera;
    v270.godRaysPosition.z = z;
    v270.godRaysMaterial = godRaysMaterial;
    v270.godRaysSize = godRaysSize;
    v270.renderDestDefault = renderDestScaledColor;
    v270.godRaysSourceSize = godRaysSourceSize;
    v270.rpTransMap = (const idDeclRenderParm *)rpTransMap.r;
    v270.godRaysColor.x = v191;
    v270.unitSquareTris = v195;
    v270.godRaysColor.y = v192;
    v270.rpScaleBiasQuad = tr.rpGodRayQuadScaleBias;
    v270.godRaysColor.z = v193;
    v270.rpScaleBiasSource = tr.rpGodRaySourceScaleBias;
    v270.rpGodRaysColor = tr.rpGodRaysColor;
    RenderGodRays(parms: &v270);
  }
  if ( *(_BYTE *)(HIDWORD(v159) + 352494) == 0 )
  {
    v196 = *(const idRenderView **)v159;
    v284.settings = (const renderSettings_t *)v160;
    v284.pass = RENDERPASS_DISTORTION;
    v284.drawSurfParms.settings = (const renderSettings_t *)v160;
    v284.drawSurfParms.allowInGameGUIs = BYTE3(v160);
    v284.renderView = v196;
    v284.drawSurfParms.renderView = v196;
    idRender::SetupCaptureParms(
      this: (idRender *)HIDWORD(v159),
      parms: &v284.drawSurfParms.captureParms,
      capture: CAPTURE_GUI_IMAGE,
      createMipMaps: false,
      viewIndex: v196->viewIndex);
    v197 = *(_DWORD *)v159;
    v198 = *p_list;
    v284.drawSurfParms.renderDestDefault = renderDestScaledColor;
    v284.renderDestDefault = renderDestScaledColor;
    v284.drawSurfParms.renderDestGui = tr.renderDestGui;
    v199 = *(_DWORD *)(v197 + 1876);
    v284.rpViewColor = (const idDeclRenderParm *)rpViewColor.r;
    v284.binaryModelState = v198;
    v284.renderPasses = v164;
    v284.sortedDrawSurfs = v165;
    v284.renderDestDistortion = tr.renderDestDistortion[v199];
    RenderPass(parms: &v284);
  }
  if ( *(_BYTE *)(HIDWORD(v159) + 352489) == 0 )
  {
    v200 = *v245;
    v263.renderView = *(const idRenderView **)v159;
    v263.settings = (const renderSettings_t *)v160;
    v263.progColorParmOnly = tr.progColorParmOnly;
    v263.numViewAugmentModels = v200;
    v263.viewAugmentModels = v223;
    v263.renderDestDefault = renderDestScaledColor;
    v263.renderDestAugment = tr.renderDestGui;
    RenderAugment(parms: &v263);
  }
  idRender::SetupCaptureParms(
    this: (idRender *)HIDWORD(v159),
    parms: &v294,
    capture: CAPTURE_VIEW_COLOR,
    createMipMaps: true,
    viewIndex: *(_DWORD *)(*(_DWORD *)v159 + 1876));
  CaptureViewColor(parms: &v294);
  v201 = *(const idRenderView **)v159;
  if ( *(_BYTE *)(HIDWORD(v159) + 352497) != 0 )
  {
    v267.settings = (const renderSettings_t *)v160;
    v267.renderView = v201;
    idResolutionScale::GetCurrentResolutionScale(this: v232, x: &v267.xScale, y: &v267.yScale);
    v267.renderDestDefault = renderDestScaledColor;
    v204 = *(_DWORD *)(*(_DWORD *)v159 + 1876);
    v267.renderDestMip3 = tr.renderDestMip3;
    v267.renderDestMip3Alt = tr.renderDestMip3Alt;
    v267.renderDestViewColor = tr.renderDestViewColor[v204];
    blackImage = globalImages->blackImage;
    v267.rpGlareMap = tr.rpGlareMap;
    v267.rpGlareStep = tr.rpGlareStep;
    v267.progGauss = tr.progGauss;
    v267.progGlareScale = tr.progGlareScale;
    v267.imgBlack = blackImage;
    v267.unitSquareTris = tr.unitSquareModel->surfaces.list->geometry;
    RenderGlare(parms: &v267);
  }
  else
  {
    v277.settings = (const renderSettings_t *)v160;
    v277.renderView = v201;
    v277.frameNumber = renderSystem->FrameNumber(this: renderSystem);
    v277.minThreshold = r_adaptiveGlareMinThreshold.valueFloat;
    v277.maxThreshold = r_adaptiveGlareMaxThreshold.valueFloat;
    v277.avgBrightness = r_adaptiveGlareAvgBrightness.valueFloat;
    v277.decayRate = r_adaptiveGlareDecayRate.valueFloat;
    idResolutionScale::GetCurrentResolutionScale(this: v232, x: &v277.xScale, y: &v277.yScale);
    v277.renderDestDefault = renderDestScaledColor;
    v202 = *(_DWORD *)(*(_DWORD *)v159 + 1876);
    v277.renderDestLuminosityAlt = tr.renderDestLuminosityAlt;
    v277.renderDestAdaptiveGlare = tr.renderDestMip3;
    v277.renderDestAdaptiveGlareAlt = tr.renderDestMip3Alt;
    v277.renderDestLuminosity = tr.renderDestLuminosity;
    v277.renderDestViewColor = tr.renderDestViewColor[v202];
    v203 = tr.currentRenderView->imgViewColor;
    v277.progBloomThreshold = tr.progBloomThreshold;
    v277.imgGlare = tr.imgScreenMip3;
    v277.imgLuminosity = tr.imgLuminosity;
    v277.imgLuminosityAlt = tr.imgLuminosityAlt;
    v277.rpViewColor = (const idDeclRenderParm *)rpViewColor.r;
    v277.imgViewColor = v203;
    v277.rpGlareMap = tr.rpGlareMap;
    v277.rpAdaptiveGlareMap = tr.rpAdaptiveGlareMap;
    v277.rpAdaptiveGlareMapAlt = tr.rpAdaptiveGlareMapAlt;
    v277.rpLuminosityMap = tr.rpLuminosityMap;
    v277.rpLuminosityMapAlt = tr.rpLuminosityMapAlt;
    v277.rpAdaptiveLuminance = tr.rpAdaptiveLuminance;
    v277.rpAdaptiveGlareBlurMap = tr.rpAdaptiveGlareBlurMap;
    v277.rpAdaptiveGlareBlurStep = tr.rpAdaptiveGlareBlurStep;
    v277.rpAdaptiveGlareParms = tr.rpAdaptiveGlareParms;
    v277.progLuminosity = tr.progLuminosity;
    v277.progAdaptiveGlareGauss = tr.progAdaptiveGlareGauss;
    v277.unitSquareTris = tr.unitSquareModel->surfaces.list->geometry;
    RenderAdaptiveGlare(parms: &v277);
    v156 = (int *)HIDWORD(v231);
  }
  if ( *(_BYTE *)(HIDWORD(v159) + 352498) == 0 )
  {
    v206 = *(const idRenderView **)v159;
    v268.rpViewColor = (const idDeclRenderParm *)rpViewColor.r;
    v268.settings = (const renderSettings_t *)v160;
    v268.renderView = v206;
    v268.rpGlareMap = tr.rpGlareMap;
    v268.rpDistortionMap = tr.rpDistortionMap;
    depthOfField = rp->depthOfField;
    v268.rpDepthOfField2 = tr.rpDepthOfField2;
    v268.progPostProcess = tr.progPostProcess;
    v268.rpDepthOfField = depthOfField;
    v208 = tr.currentRenderView->imgViewColor;
    v268.rpAdaptiveGlareMap = tr.rpAdaptiveGlareMap;
    v268.rpAdaptiveGlareLuminance = tr.rpAdaptiveLuminance;
    v268.imgGlare = tr.imgScreenMip3;
    v268.imgAdaptiveGlare = tr.imgScreenMip3;
    v268.imgViewColor = v208;
    v268.imgAdaptiveGlareLuminance = tr.renderDestLuminosity->targetImage[0];
    v268.imgBlack = globalImages->blackImage;
    v268.imgDistortion = tr.imgDistortion[v206->viewIndex];
    v268.unitSquareTris = tr.unitSquareModel->surfaces.list->geometry;
    if ( r_showDepthOfFieldDebug.valueInteger != 0 )
      v209 = 1.0;
    else
      v209 = 0.0;
    idDeclRenderParm::Set(this: (idDeclRenderParm *)rpShowDepthOfFieldDebug.r, v: v209);
    if ( r_showGrainLuminanceDebug.valueInteger != 0 )
      v210 = 1.0;
    else
      v210 = 0.0;
    idDeclRenderParm::Set(this: (idDeclRenderParm *)rpShowGrainLevelsDebug.r, v: v210);
    RenderPostProcess(parms: &v268);
  }
  idRender::RenderDebugTools(this: (idRender *)HIDWORD(v159));
  idParmState::VirtualRollbackParmBlock(
    this: renderThreadParmState,
    localParmBlock: (const idParmBlock *)(*(_DWORD *)v159 + 1896),
    parmBlock: (const idParmBlock *)(*(_DWORD *)v159 + 1896));
  LODWORD(v211) = v274;
  HIDWORD(v211) = *(_DWORD *)v159;
  *(_QWORD *)(HIDWORD(v211) + 4456) = v211;
  v212 = *(_QWORD *)(*(_DWORD *)v159 + 4456);
  if ( (int)v212 < 1 )
  {
    v213 = 1;
    *(_QWORD *)(*(_DWORD *)v159 + 4456) = *(__int64 *)((char *)&v212 - 4);
  }
  v214 = v244;
  p_isDefault = (int *)&v234->isDefault;
  size = (int *)v235.constants.size;
  ++*(_DWORD *)(*(_DWORD *)(*(_DWORD *)v159 + 4464) + 213504);
  tr.pc.c_viewWorldAreas = *v214;
  tr.pc.c_viewModels = *p_isDefault;
  tr.pc.c_viewLights = *size;
  tr.pc.c_viewShadows = *v156;
  tr.pc.c_viewDimShadows = *(_DWORD *)(HIDWORD(v159) + 352436);
  if ( r_skipViewParms.valueInteger == 0 )
    idParmState::VirtualRollbackParmBlock(
      this: renderThreadParmState,
      localParmBlock: (const idParmBlock *)(*(_DWORD *)v159 + 2096),
      parmBlock: (const idParmBlock *)(*(_DWORD *)v159 + 2096));
  idRender::PrintStats(this: (idRender *)HIDWORD(v159));
}


// ========================================================================
// `dynamic initializer for 'r_skipWorld''
// EA  : 0x833583A8
// RVA : 0x013583A8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipWorld__()
{
  idCVar::idCVar(
    this: &r_skipWorld,
    name: "r_skipWorld",
    value: "0",
    flags: 1,
    description: "skip drawing all world geometry",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipWorld__);
}


// ========================================================================
// `dynamic initializer for 'r_skipModels''
// EA  : 0x83358400
// RVA : 0x01358400
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipModels__()
{
  idCVar::idCVar(
    this: &r_skipModels,
    name: "r_skipModels",
    value: "0",
    flags: 1,
    description: "skip drawing all dynamic models",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipModels__);
}


// ========================================================================
// `dynamic initializer for 'r_skipLights''
// EA  : 0x83358458
// RVA : 0x01358458
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipLights__()
{
  idCVar::idCVar(
    this: &r_skipLights,
    name: "r_skipLights",
    value: "0",
    flags: 1,
    description: "skip drawing all dynamic lights",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipLights__);
}


// ========================================================================
// `dynamic initializer for 'r_skipBlendLightShadows''
// EA  : 0x833584B0
// RVA : 0x013584B0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipBlendLightShadows__()
{
  idCVar::idCVar(
    this: &r_skipBlendLightShadows,
    name: "r_skipBlendLightShadows",
    value: "1",
    flags: 1,
    description: "skip shadows from blend lights",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipBlendLightShadows__);
}


// ========================================================================
// `dynamic initializer for 'r_skipShadows''
// EA  : 0x83358508
// RVA : 0x01358508
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipShadows__()
{
  idCVar::idCVar(
    this: &r_skipShadows,
    name: "r_skipShadows",
    value: "0",
    flags: 4,
    description: "just use the existing depth texture contents",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipShadows__);
}


// ========================================================================
// `dynamic initializer for 'r_skipShadowOccluders''
// EA  : 0x83358560
// RVA : 0x01358560
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipShadowOccluders__()
{
  idCVar::idCVar(
    this: &r_skipShadowOccluders,
    name: "r_skipShadowOccluders",
    value: "0",
    flags: 1,
    description: "do the clear, but no triangle draws",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipShadowOccluders__);
}


// ========================================================================
// `dynamic initializer for 'r_skipSuppress''
// EA  : 0x833585B8
// RVA : 0x013585B8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipSuppress__()
{
  idCVar::idCVar(
    this: &r_skipSuppress,
    name: "r_skipSuppress",
    value: "0",
    flags: 1,
    description: "ignore the per-view suppressions",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipSuppress__);
}


// ========================================================================
// `dynamic initializer for 'r_skipFeedback''
// EA  : 0x83358610
// RVA : 0x01358610
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipFeedback__()
{
  idCVar::idCVar(
    this: &r_skipFeedback,
    name: "r_skipFeedback",
    value: "0",
    flags: 1,
    description: "skip the feedback rendering",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipFeedback__);
}


// ========================================================================
// `dynamic initializer for 'r_skipDynamic''
// EA  : 0x83358668
// RVA : 0x01358668
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipDynamic__()
{
  idCVar::idCVar(
    this: &r_skipDynamic,
    name: "r_skipDynamic",
    value: "0",
    flags: 1,
    description: "skip dynamic models",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipDynamic__);
}


// ========================================================================
// `dynamic initializer for 'r_skipAddAlways''
// EA  : 0x833586C0
// RVA : 0x013586C0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipAddAlways__()
{
  idCVar::idCVar(
    this: &r_skipAddAlways,
    name: "r_skipAddAlways",
    value: "0",
    flags: 1,
    description: "don't include add-always models",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipAddAlways__);
}


// ========================================================================
// `dynamic initializer for 'r_skipAugment''
// EA  : 0x83358718
// RVA : 0x01358718
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipAugment__()
{
  idCVar::idCVar(
    this: &r_skipAugment,
    name: "r_skipAugment",
    value: "0",
    flags: 1,
    description: "don't include augment models",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipAugment__);
}


// ========================================================================
// `dynamic initializer for 'r_skipAutosprites''
// EA  : 0x83358770
// RVA : 0x01358770
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipAutosprites__()
{
  idCVar::idCVar(
    this: &r_skipAutosprites,
    name: "r_skipAutosprites",
    value: "0",
    flags: 1,
    description: "skip the autosprites",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipAutosprites__);
}


// ========================================================================
// `dynamic initializer for 'r_skipOcclusionBaseModel''
// EA  : 0x833587C8
// RVA : 0x013587C8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipOcclusionBaseModel__()
{
  idCVar::idCVar(
    this: &r_skipOcclusionBaseModel,
    name: "r_skipOcclusionBaseModel",
    value: "0",
    flags: 1,
    description: "use sound BSP derived base occluder triangles",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipOcclusionBaseModel__);
}


// ========================================================================
// `dynamic initializer for 'r_skipDimShadows''
// EA  : 0x83358820
// RVA : 0x01358820
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipDimShadows__()
{
  idCVar::idCVar(
    this: &r_skipDimShadows,
    name: "r_skipDimShadows",
    value: "0",
    flags: 1,
    description: "skip the dim-shadow rendering",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipDimShadows__);
}


// ========================================================================
// `dynamic initializer for 'r_skipBlendedSurfaces''
// EA  : 0x83358878
// RVA : 0x01358878
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipBlendedSurfaces__()
{
  idCVar::idCVar(
    this: &r_skipBlendedSurfaces,
    name: "r_skipBlendedSurfaces",
    value: "0",
    flags: 1,
    description: "skip blended surfaces",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipBlendedSurfaces__);
}


// ========================================================================
// `dynamic initializer for 'r_skipDistortionSurfaces''
// EA  : 0x833588D0
// RVA : 0x013588D0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipDistortionSurfaces__()
{
  idCVar::idCVar(
    this: &r_skipDistortionSurfaces,
    name: "r_skipDistortionSurfaces",
    value: "0",
    flags: 1,
    description: "skip perturb surfaces",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipDistortionSurfaces__);
}


// ========================================================================
// `dynamic initializer for 'r_skipGuis''
// EA  : 0x83358928
// RVA : 0x01358928
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipGuis__()
{
  idCVar::idCVar(
    this: &r_skipGuis,
    name: "r_skipGuis",
    value: "0",
    flags: 2,
    description: "skip rendering guis, 1 = in-game, 2 = all",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipGuis__);
}


// ========================================================================
// `dynamic initializer for 'r_skipFog''
// EA  : 0x83358980
// RVA : 0x01358980
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipFog__()
{
  idCVar::idCVar(
    this: &r_skipFog,
    name: "r_skipFog",
    value: "0",
    flags: 1,
    description: "skip fog",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipFog__);
}


// ========================================================================
// `dynamic initializer for 'r_skipGodRays''
// EA  : 0x833589D8
// RVA : 0x013589D8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipGodRays__()
{
  idCVar::idCVar(
    this: &r_skipGodRays,
    name: "r_skipGodRays",
    value: "0",
    flags: 1,
    description: "skip godrays",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipGodRays__);
}


// ========================================================================
// `dynamic initializer for 'r_skipAdaptiveGlare''
// EA  : 0x83358A30
// RVA : 0x01358A30
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipAdaptiveGlare__()
{
  idCVar::idCVar(
    this: &r_skipAdaptiveGlare,
    name: "r_skipAdaptiveGlare",
    value: "1",
    flags: 1,
    description: "skip Adaptive Glare",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipAdaptiveGlare__);
}


// ========================================================================
// `dynamic initializer for 'r_skipNodeCPUCulling''
// EA  : 0x83358A88
// RVA : 0x01358A88
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipNodeCPUCulling__()
{
  idCVar::idCVar(
    this: &r_skipNodeCPUCulling,
    name: "r_skipNodeCPUCulling",
    value: "0",
    flags: 1,
    description: "skip CPU MVP culling of world nodes",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipNodeCPUCulling__);
}


// ========================================================================
// `dynamic initializer for 'r_skipNodeGPUCulling''
// EA  : 0x83358AE0
// RVA : 0x01358AE0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipNodeGPUCulling__()
{
  idCVar::idCVar(
    this: &r_skipNodeGPUCulling,
    name: "r_skipNodeGPUCulling",
    value: "0",
    flags: 1,
    description: "skip GPU occlusion testing of world nodes",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipNodeGPUCulling__);
}


// ========================================================================
// `dynamic initializer for 'r_skipAreaCPUCulling''
// EA  : 0x83358B38
// RVA : 0x01358B38
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipAreaCPUCulling__()
{
  idCVar::idCVar(
    this: &r_skipAreaCPUCulling,
    name: "r_skipAreaCPUCulling",
    value: "0",
    flags: 1,
    description: "skip CPU MVP culling of world areas",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipAreaCPUCulling__);
}


// ========================================================================
// `dynamic initializer for 'r_skipAreaGPUCulling''
// EA  : 0x83358B90
// RVA : 0x01358B90
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipAreaGPUCulling__()
{
  idCVar::idCVar(
    this: &r_skipAreaGPUCulling,
    name: "r_skipAreaGPUCulling",
    value: "0",
    flags: 1,
    description: "skip GPU occlusion testing of world areas",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipAreaGPUCulling__);
}


// ========================================================================
// `dynamic initializer for 'r_skipModelCPUCulling''
// EA  : 0x83358BE8
// RVA : 0x01358BE8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipModelCPUCulling__()
{
  idCVar::idCVar(
    this: &r_skipModelCPUCulling,
    name: "r_skipModelCPUCulling",
    value: "0",
    flags: 1,
    description: "skip CPU MVP culling of models",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipModelCPUCulling__);
}


// ========================================================================
// `dynamic initializer for 'r_skipModelGPUCulling''
// EA  : 0x83358C40
// RVA : 0x01358C40
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipModelGPUCulling__()
{
  idCVar::idCVar(
    this: &r_skipModelGPUCulling,
    name: "r_skipModelGPUCulling",
    value: "0",
    flags: 1,
    description: "skip GPU occlusion testing of models",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipModelGPUCulling__);
}


// ========================================================================
// `dynamic initializer for 'r_skipLightCPUCulling''
// EA  : 0x83358C98
// RVA : 0x01358C98
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipLightCPUCulling__()
{
  idCVar::idCVar(
    this: &r_skipLightCPUCulling,
    name: "r_skipLightCPUCulling",
    value: "0",
    flags: 1,
    description: "skip CPU MVP culling of lights",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipLightCPUCulling__);
}


// ========================================================================
// `dynamic initializer for 'r_skipLightGPUCulling''
// EA  : 0x83358CF0
// RVA : 0x01358CF0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipLightGPUCulling__()
{
  idCVar::idCVar(
    this: &r_skipLightGPUCulling,
    name: "r_skipLightGPUCulling",
    value: "0",
    flags: 1,
    description: "skip GPU occlusion testing of lights",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipLightGPUCulling__);
}


// ========================================================================
// `dynamic initializer for 'r_skipSurfaceCPUCulling''
// EA  : 0x83358D48
// RVA : 0x01358D48
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipSurfaceCPUCulling__()
{
  idCVar::idCVar(
    this: &r_skipSurfaceCPUCulling,
    name: "r_skipSurfaceCPUCulling",
    value: "0",
    flags: 1,
    description: "skip CPU MVP culling of model surfaces",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipSurfaceCPUCulling__);
}


// ========================================================================
// `dynamic initializer for 'r_skipModelRangeCulling''
// EA  : 0x83358DA0
// RVA : 0x01358DA0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipModelRangeCulling__()
{
  idCVar::idCVar(
    this: &r_skipModelRangeCulling,
    name: "r_skipModelRangeCulling",
    value: "0",
    flags: 1,
    description: "allow models to be removed at distance",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipModelRangeCulling__);
}


// ========================================================================
// `dynamic initializer for 'r_skipLightRangeCulling''
// EA  : 0x83358DF8
// RVA : 0x01358DF8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipLightRangeCulling__()
{
  idCVar::idCVar(
    this: &r_skipLightRangeCulling,
    name: "r_skipLightRangeCulling",
    value: "0",
    flags: 1,
    description: "allow lights to be removed at distance",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipLightRangeCulling__);
}


// ========================================================================
// `dynamic initializer for 'r_skipShadowModelCPUCulling''
// EA  : 0x83358E50
// RVA : 0x01358E50
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipShadowModelCPUCulling__()
{
  idCVar::idCVar(
    this: &r_skipShadowModelCPUCulling,
    name: "r_skipShadowModelCPUCulling",
    value: "0",
    flags: 1,
    description: "skip CPU MVP culling of shadow casting models",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipShadowModelCPUCulling__);
}


// ========================================================================
// `dynamic initializer for 'r_skipShadowSurfaceCPUCulling''
// EA  : 0x83358EA8
// RVA : 0x01358EA8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipShadowSurfaceCPUCulling__()
{
  idCVar::idCVar(
    this: &r_skipShadowSurfaceCPUCulling,
    name: "r_skipShadowSurfaceCPUCulling",
    value: "0",
    flags: 1,
    description: "skip CPU MVP culling of shadow casting surfaces",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipShadowSurfaceCPUCulling__);
}


// ========================================================================
// `dynamic initializer for 'r_skipViewParms''
// EA  : 0x83358F00
// RVA : 0x01358F00
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipViewParms__()
{
  idCVar::idCVar(
    this: &r_skipViewParms,
    name: "r_skipViewParms",
    value: "0",
    flags: 1,
    description: "don't use the parmBlock in idRenderView",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipViewParms__);
}


// ========================================================================
// `dynamic initializer for 'r_showParms''
// EA  : 0x83358F58
// RVA : 0x01358F58
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showParms__()
{
  idCVar::idCVar(
    this: &r_showParms,
    name: "r_showParms",
    value: "0",
    flags: 1,
    description: "print all world / view parmBlock assignments",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showParms__);
}


// ========================================================================
// `dynamic initializer for 'r_generateMipMaps''
// EA  : 0x83358FB0
// RVA : 0x01358FB0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_generateMipMaps__()
{
  idCVar::idCVar(
    this: &r_generateMipMaps,
    name: "r_generateMipMaps",
    value: "0",
    flags: 2,
    description: "0 = overlapped downsample",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_generateMipMaps__);
}


// ========================================================================
// `dynamic initializer for 'r_singleWorldArea''
// EA  : 0x83359008
// RVA : 0x01359008
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_singleWorldArea__()
{
  idCVar::idCVar(
    this: &r_singleWorldArea,
    name: "r_singleWorldArea",
    value: "-1",
    flags: 2,
    description: "suppress all but one world area",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_singleWorldArea__);
}


// ========================================================================
// `dynamic initializer for 'r_singleLight''
// EA  : 0x83359060
// RVA : 0x01359060
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_singleLight__()
{
  idCVar::idCVar(
    this: &r_singleLight,
    name: "r_singleLight",
    value: "-1",
    flags: 2,
    description: "suppress all but one light",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_singleLight__);
}


// ========================================================================
// `dynamic initializer for 'r_singleModel''
// EA  : 0x833590B8
// RVA : 0x013590B8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_singleModel__()
{
  idCVar::idCVar(
    this: &r_singleModel,
    name: "r_singleModel",
    value: "-1",
    flags: 2,
    description: "suppress all but one model",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_singleModel__);
}


// ========================================================================
// `dynamic initializer for 'r_singleSurface''
// EA  : 0x83359110
// RVA : 0x01359110
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_singleSurface__()
{
  idCVar::idCVar(
    this: &r_singleSurface,
    name: "r_singleSurface",
    value: "-1",
    flags: 2,
    description: "suppress all but one surface on each model",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_singleSurface__);
}


// ========================================================================
// `dynamic initializer for 'r_singleGuiSurface''
// EA  : 0x83359168
// RVA : 0x01359168
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_singleGuiSurface__()
{
  idCVar::idCVar(
    this: &r_singleGuiSurface,
    name: "r_singleGuiSurface",
    value: "-1",
    flags: 2,
    description: "suppress all but one surface on gui model",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_singleGuiSurface__);
}


// ========================================================================
// `dynamic initializer for 'r_singleDimShadow''
// EA  : 0x833591C0
// RVA : 0x013591C0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_singleDimShadow__()
{
  idCVar::idCVar(
    this: &r_singleDimShadow,
    name: "r_singleDimShadow",
    value: "-1",
    flags: 2,
    description: "only dimShadow a single model",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_singleDimShadow__);
}


// ========================================================================
// `dynamic initializer for 'r_queryThreshold''
// EA  : 0x83359218
// RVA : 0x01359218
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_queryThreshold__()
{
  idCVar::idCVar(
    this: &r_queryThreshold,
    name: "r_queryThreshold",
    value: "4",
    flags: 2,
    description: "minimum return value from a query",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_queryThreshold__);
}


// ========================================================================
// `dynamic initializer for 'r_manifoldMaxDetailWidth''
// EA  : 0x83359270
// RVA : 0x01359270
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_manifoldMaxDetailWidth__()
{
  idCVar::idCVar(
    this: &r_manifoldMaxDetailWidth,
    name: "r_manifoldMaxDetailWidth",
    value: "32",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_manifoldMaxDetailWidth__);
}


// ========================================================================
// `dynamic initializer for 'r_detailDistancePixelThreshold''
// EA  : 0x833592C8
// RVA : 0x013592C8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_detailDistancePixelThreshold__()
{
  idCVar::idCVar(
    this: &r_detailDistancePixelThreshold,
    name: "r_detailDistancePixelThreshold",
    value: "3",
    flags: 4,
    description: "pixel width to use when determining the maximum detail distance",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_detailDistancePixelThreshold__);
}


// ========================================================================
// `dynamic initializer for 'r_envBlendShow''
// EA  : 0x83359320
// RVA : 0x01359320
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_envBlendShow__()
{
  idCVar::idCVar(
    this: &r_envBlendShow,
    name: "r_envBlendShow",
    value: "0",
    flags: 2,
    description: "report the dynamic blend factors",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_envBlendShow__);
}


// ========================================================================
// `dynamic initializer for 'r_envBlendTime''
// EA  : 0x83359378
// RVA : 0x01359378
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_envBlendTime__()
{
  idCVar::idCVar(
    this: &r_envBlendTime,
    name: "r_envBlendTime",
    value: "-1.0",
    flags: 4,
    description: "if >= 0, the seconds to completely fade out an old environment",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_envBlendTime__);
}


// ========================================================================
// `dynamic initializer for 'r_envBlendAmbient''
// EA  : 0x833593D0
// RVA : 0x013593D0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_envBlendAmbient__()
{
  idCVar::idCVar(
    this: &r_envBlendAmbient,
    name: "r_envBlendAmbient",
    value: "1",
    flags: 2,
    description: "use ambientEnvMap instead of userEnvMap for the lowest mip level",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_envBlendAmbient__);
}


// ========================================================================
// `dynamic initializer for 'r_skipSlowLights''
// EA  : 0x83359428
// RVA : 0x01359428
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipSlowLights__()
{
  idCVar::idCVar(
    this: &r_skipSlowLights,
    name: "r_skipSlowLights",
    value: "1",
    flags: 1,
    description: "1 = don't draw slow lights",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipSlowLights__);
}


// ========================================================================
// `dynamic initializer for 'r_skipBlendLights''
// EA  : 0x83359480
// RVA : 0x01359480
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipBlendLights__()
{
  idCVar::idCVar(
    this: &r_skipBlendLights,
    name: "r_skipBlendLights",
    value: "0",
    flags: 1,
    description: "1 = don't draw blend lights",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipBlendLights__);
}


// ========================================================================
// `dynamic initializer for 'r_useLightScissors''
// EA  : 0x833594D8
// RVA : 0x013594D8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useLightScissors__()
{
  idCVar::idCVar(
    this: &r_useLightScissors,
    name: "r_useLightScissors",
    value: "1",
    flags: 1,
    description: "use custom scissor rectangle for each light based on projection",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useLightScissors__);
}


// ========================================================================
// `dynamic initializer for 'r_useLightDepthBoundsTest''
// EA  : 0x83359530
// RVA : 0x01359530
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useLightDepthBoundsTest__()
{
  idCVar::idCVar(
    this: &r_useLightDepthBoundsTest,
    name: "r_useLightDepthBoundsTest",
    value: "0",
    flags: 1,
    description: "not supported on Xbox 360",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useLightDepthBoundsTest__);
}


// ========================================================================
// `dynamic initializer for 'r_useDeferredSlowMapLighting''
// EA  : 0x83359588
// RVA : 0x01359588
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useDeferredSlowMapLighting__()
{
  idCVar::idCVar(
    this: &r_useDeferredSlowMapLighting,
    name: "r_useDeferredSlowMapLighting",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useDeferredSlowMapLighting__);
}


// ========================================================================
// `dynamic initializer for 'r_showLightScissors''
// EA  : 0x833595E0
// RVA : 0x013595E0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showLightScissors__()
{
  idCVar::idCVar(
    this: &r_showLightScissors,
    name: "r_showLightScissors",
    value: "0",
    flags: 1,
    description: "show light scissor rectangles",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showLightScissors__);
}


// ========================================================================
// `dynamic initializer for 'r_showBlendedLights''
// EA  : 0x83359638
// RVA : 0x01359638
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showBlendedLights__()
{
  idCVar::idCVar(
    this: &r_showBlendedLights,
    name: "r_showBlendedLights",
    value: "0",
    flags: 2,
    description: "1 = visualize the blendlights boxes, 2 = visualize blendlights region",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showBlendedLights__);
}


// ========================================================================
// `dynamic initializer for 'r_slowMapWorldAmbient''
// EA  : 0x83359690
// RVA : 0x01359690
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_slowMapWorldAmbient__()
{
  idCVar::idCVar(
    this: &r_slowMapWorldAmbient,
    name: "r_slowMapWorldAmbient",
    value: "0.075",
    flags: 4,
    description: "amount of ambient lighting to use on the world in slow map",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_slowMapWorldAmbient__);
}


// ========================================================================
// `dynamic initializer for 'r_forceLightingModel''
// EA  : 0x833596E8
// RVA : 0x013596E8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_forceLightingModel__()
{
  idCVar::idCVar(
    this: &r_forceLightingModel,
    name: "r_forceLightingModel",
    value: "0",
    flags: 2,
    description: "Force use of a different lighting model",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_forceLightingModel__);
}


// ========================================================================
// `dynamic initializer for 'r_dimShadowResolution''
// EA  : 0x83359740
// RVA : 0x01359740
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_dimShadowResolution__()
{
  idCVar::idCVar(
    this: &r_dimShadowResolution,
    name: "r_dimShadowResolution",
    value: "768",
    flags: 2,
    description: "maximum dim-shadow resolution",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_dimShadowResolution__);
}


// ========================================================================
// `dynamic initializer for 'r_dimShadowLixelScale''
// EA  : 0x83359798
// RVA : 0x01359798
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_dimShadowLixelScale__()
{
  idCVar::idCVar(
    this: &r_dimShadowLixelScale,
    name: "r_dimShadowLixelScale",
    value: "1000",
    flags: 4,
    description: "clip space to lixel scale factor, 0 disables",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_dimShadowLixelScale__);
}


// ========================================================================
// `dynamic initializer for 'r_dimShadowDensity''
// EA  : 0x833597F0
// RVA : 0x013597F0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_dimShadowDensity__()
{
  idCVar::idCVar(
    this: &r_dimShadowDensity,
    name: "r_dimShadowDensity",
    value: "1.0",
    flags: 4,
    description: "1.0 = full dark shadows, 0.0 = no shadows",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_dimShadowDensity__);
}


// ========================================================================
// `dynamic initializer for 'r_dimShadowUseQuery''
// EA  : 0x83359848
// RVA : 0x01359848
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_dimShadowUseQuery__()
{
  idCVar::idCVar(
    this: &r_dimShadowUseQuery,
    name: "r_dimShadowUseQuery",
    value: "1",
    flags: 1,
    description: "Use occlusion queries",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_dimShadowUseQuery__);
}


// ========================================================================
// `dynamic initializer for 'r_dimShadowForceHighQuality''
// EA  : 0x833598A0
// RVA : 0x013598A0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_dimShadowForceHighQuality__()
{
  idCVar::idCVar(
    this: &r_dimShadowForceHighQuality,
    name: "r_dimShadowForceHighQuality",
    value: "0",
    flags: 2,
    description: "1 = all models use high quality dim-shadows, -1 = no models do",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_dimShadowForceHighQuality__);
}


// ========================================================================
// `dynamic initializer for 'r_showDimShadows''
// EA  : 0x833598F8
// RVA : 0x013598F8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showDimShadows__()
{
  idCVar::idCVar(
    this: &r_showDimShadows,
    name: "r_showDimShadows",
    value: "0",
    flags: 2,
    description: "visualize the dimShadow boxes",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showDimShadows__);
}


// ========================================================================
// `dynamic initializer for 'r_skipDimShadowRangeCulling''
// EA  : 0x83359950
// RVA : 0x01359950
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipDimShadowRangeCulling__()
{
  idCVar::idCVar(
    this: &r_skipDimShadowRangeCulling,
    name: "r_skipDimShadowRangeCulling",
    value: "0",
    flags: 1,
    description: "1 = skip dimshadow range culling",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipDimShadowRangeCulling__);
}


// ========================================================================
// `dynamic initializer for 'r_dimShadowMaxVisibleRange''
// EA  : 0x833599A8
// RVA : 0x013599A8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_dimShadowMaxVisibleRange__()
{
  idCVar::idCVar(
    this: &r_dimShadowMaxVisibleRange,
    name: "r_dimShadowMaxVisibleRange",
    value: "2200.0",
    flags: 4,
    description: "dimshadows are culled at this range from viewer",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_dimShadowMaxVisibleRange__);
}


// ========================================================================
// `dynamic initializer for 'r_dimShadowFadeVisibilityRange''
// EA  : 0x83359A00
// RVA : 0x01359A00
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_dimShadowFadeVisibilityRange__()
{
  idCVar::idCVar(
    this: &r_dimShadowFadeVisibilityRange,
    name: "r_dimShadowFadeVisibilityRange",
    value: "1800.0",
    flags: 4,
    description: "dimshadows start fading at this range from viewer",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_dimShadowFadeVisibilityRange__);
}


// ========================================================================
// `dynamic initializer for 'r_dimShadowPolyOfsFactor''
// EA  : 0x83359A58
// RVA : 0x01359A58
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_dimShadowPolyOfsFactor__()
{
  idCVar::idCVar(
    this: &r_dimShadowPolyOfsFactor,
    name: "r_dimShadowPolyOfsFactor",
    value: "3.0",
    flags: 4,
    description: "polygon offset factor for drawing shadow buffer",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_dimShadowPolyOfsFactor__);
}


// ========================================================================
// `dynamic initializer for 'r_dimShadowPolyOfsUnits''
// EA  : 0x83359AB0
// RVA : 0x01359AB0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_dimShadowPolyOfsUnits__()
{
  idCVar::idCVar(
    this: &r_dimShadowPolyOfsUnits,
    name: "r_dimShadowPolyOfsUnits",
    value: "0.001",
    flags: 4,
    description: "polygon offset units for drawing shadow buffer",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_dimShadowPolyOfsUnits__);
}


// ========================================================================
// `dynamic initializer for 'r_dimShadowDepthBoundsTest''
// EA  : 0x83359B08
// RVA : 0x01359B08
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_dimShadowDepthBoundsTest__()
{
  idCVar::idCVar(
    this: &r_dimShadowDepthBoundsTest,
    name: "r_dimShadowDepthBoundsTest",
    value: "0",
    flags: 1,
    description: "use depth bounds test on dim shadows for early fragment rejection",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_dimShadowDepthBoundsTest__);
}


// ========================================================================
// `dynamic initializer for 'r_sb_polyOfsFactor''
// EA  : 0x83359B60
// RVA : 0x01359B60
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_sb_polyOfsFactor__()
{
  idCVar::idCVar(
    this: &r_sb_polyOfsFactor,
    name: "r_sb_polyOfsFactor",
    value: "2",
    flags: 4,
    description: "polygon offset factor for drawing shadow buffer",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_sb_polyOfsFactor__);
}


// ========================================================================
// `dynamic initializer for 'r_sb_polyOfsUnits''
// EA  : 0x83359BB8
// RVA : 0x01359BB8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_sb_polyOfsUnits__()
{
  idCVar::idCVar(
    this: &r_sb_polyOfsUnits,
    name: "r_sb_polyOfsUnits",
    value: "0.0001",
    flags: 4,
    description: "polygon offset units for drawing shadow buffer",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_sb_polyOfsUnits__);
}


// ========================================================================
// `dynamic initializer for 'r_sb_parallelPolyOfsFactor''
// EA  : 0x83359C10
// RVA : 0x01359C10
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_sb_parallelPolyOfsFactor__()
{
  idCVar::idCVar(
    this: &r_sb_parallelPolyOfsFactor,
    name: "r_sb_parallelPolyOfsFactor",
    value: "2",
    flags: 4,
    description: "polygon offset factor for drawing parallel light shadow buffer",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_sb_parallelPolyOfsFactor__);
}


// ========================================================================
// `dynamic initializer for 'r_sb_parallelPolyOfsUnits''
// EA  : 0x83359C68
// RVA : 0x01359C68
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_sb_parallelPolyOfsUnits__()
{
  idCVar::idCVar(
    this: &r_sb_parallelPolyOfsUnits,
    name: "r_sb_parallelPolyOfsUnits",
    value: "0.0001",
    flags: 4,
    description: "polygon offset units for drawing parallel light shadow buffer",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_sb_parallelPolyOfsUnits__);
}


// ========================================================================
// `dynamic initializer for 'r_sb_imageSize''
// EA  : 0x83359CC0
// RVA : 0x01359CC0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_sb_imageSize__()
{
  idCVar::idCVar(
    this: &r_sb_imageSize,
    name: "r_sb_imageSize",
    value: "768",
    flags: 2,
    description: "Dimensions of the shadow buffer image",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_sb_imageSize__);
}


// ========================================================================
// `dynamic initializer for 'r_sb_linearFilter''
// EA  : 0x83359D18
// RVA : 0x01359D18
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_sb_linearFilter__()
{
  idCVar::idCVar(
    this: &r_sb_linearFilter,
    name: "r_sb_linearFilter",
    value: "1",
    flags: 1,
    description: "use GL_LINEAR instead of GL_NEAREST on shadow maps",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_sb_linearFilter__);
}


// ========================================================================
// `dynamic initializer for 'r_sb_occluderFacing''
// EA  : 0x83359D70
// RVA : 0x01359D70
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_sb_occluderFacing__()
{
  idCVar::idCVar(
    this: &r_sb_occluderFacing,
    name: "r_sb_occluderFacing",
    value: "0",
    flags: 2,
    description: "0 = front faces, 1 = back faces, 2 = front and back sides separately with polygon offset",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_sb_occluderFacing__);
}


// ========================================================================
// `dynamic initializer for 'r_sb_singleSide''
// EA  : 0x83359DC8
// RVA : 0x01359DC8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_sb_singleSide__()
{
  idCVar::idCVar(
    this: &r_sb_singleSide,
    name: "r_sb_singleSide",
    value: "-1",
    flags: 2,
    description: "only draw a single side (0-5) of point lights",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_sb_singleSide__);
}


// ========================================================================
// `dynamic initializer for 'r_sb_sliceStep''
// EA  : 0x83359E20
// RVA : 0x01359E20
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_sb_sliceStep__()
{
  idCVar::idCVar(
    this: &r_sb_sliceStep,
    name: "r_sb_sliceStep",
    value: "512",
    flags: 4,
    description: "initial ortho size for first slice",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_sb_sliceStep__);
}


// ========================================================================
// `dynamic initializer for 'r_sb_sliceRampScale''
// EA  : 0x83359E78
// RVA : 0x01359E78
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_sb_sliceRampScale__()
{
  idCVar::idCVar(
    this: &r_sb_sliceRampScale,
    name: "r_sb_sliceRampScale",
    value: "2",
    flags: 4,
    description: "larger values perform a faster triliner lerp between slices",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_sb_sliceRampScale__);
}


// ========================================================================
// `dynamic initializer for 'r_showGuiOverdraw''
// EA  : 0x83359ED0
// RVA : 0x01359ED0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showGuiOverdraw__()
{
  idCVar::idCVar(
    this: &r_showGuiOverdraw,
    name: "r_showGuiOverdraw",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showGuiOverdraw__);
}


// ========================================================================
// `dynamic initializer for 'r_showDepthOfFieldDebug''
// EA  : 0x83359F28
// RVA : 0x01359F28
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showDepthOfFieldDebug__()
{
  idCVar::idCVar(
    this: &r_showDepthOfFieldDebug,
    name: "r_showDepthOfFieldDebug",
    value: "0",
    flags: 1,
    description: "Show depth of field calculations",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showDepthOfFieldDebug__);
}


// ========================================================================
// `dynamic initializer for 'r_showGrainLuminanceDebug''
// EA  : 0x83359F80
// RVA : 0x01359F80
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showGrainLuminanceDebug__()
{
  idCVar::idCVar(
    this: &r_showGrainLuminanceDebug,
    name: "r_showGrainLuminanceDebug",
    value: "0",
    flags: 1,
    description: "Show grains screen luminance scale calculations",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showGrainLuminanceDebug__);
}


// ========================================================================
// `dynamic initializer for 'r_postProcessHQ''
// EA  : 0x83359FD8
// RVA : 0x01359FD8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_postProcessHQ__()
{
  idCVar::idCVar(
    this: &r_postProcessHQ,
    name: "r_postProcessHQ",
    value: "0",
    flags: 1,
    description: "Set high quality post process, for cutscene rendering",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_postProcessHQ__);
}


// ========================================================================
// `dynamic initializer for 'r_feedbackBGRA''
// EA  : 0x8335A030
// RVA : 0x0135A030
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_feedbackBGRA__()
{
  idCVar::idCVar(
    this: &r_feedbackBGRA,
    name: "r_feedbackBGRA",
    value: "0",
    flags: 1,
    description: "use BGRA instead of RGBA for the feedback buffer",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_feedbackBGRA__);
}


// ========================================================================
// `dynamic initializer for 'r_showOcclusionBoxes''
// EA  : 0x8335A088
// RVA : 0x0135A088
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showOcclusionBoxes__()
{
  idCVar::idCVar(
    this: &r_showOcclusionBoxes,
    name: "r_showOcclusionBoxes",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showOcclusionBoxes__);
}


// ========================================================================
// `dynamic initializer for 'r_extraClears''
// EA  : 0x8335A0E0
// RVA : 0x0135A0E0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_extraClears__()
{
  idCVar::idCVar(
    this: &r_extraClears,
    name: "r_extraClears",
    value: "0",
    flags: 2,
    description: "To simulate slower rendering scenes, draw this many extra full screen clears",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_extraClears__);
}


// ========================================================================
// `dynamic initializer for 'r_forceOcclusionBoxQueries''
// EA  : 0x8335A138
// RVA : 0x0135A138
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_forceOcclusionBoxQueries__()
{
  idCVar::idCVar(
    this: &r_forceOcclusionBoxQueries,
    name: "r_forceOcclusionBoxQueries",
    value: "0",
    flags: 1,
    description: "force the use of occlusion query boxes",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_forceOcclusionBoxQueries__);
}


// ========================================================================
// `dynamic initializer for 'r_adaptiveGlareMinThreshold''
// EA  : 0x8335A190
// RVA : 0x0135A190
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_adaptiveGlareMinThreshold__()
{
  idCVar::idCVar(
    this: &r_adaptiveGlareMinThreshold,
    name: "r_adaptiveGlareMinThreshold",
    value: "0.2",
    flags: 4,
    description: "Adaptive Glare Min Threshold",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_adaptiveGlareMinThreshold__);
}


// ========================================================================
// `dynamic initializer for 'r_adaptiveGlareMaxThreshold''
// EA  : 0x8335A1E8
// RVA : 0x0135A1E8
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_adaptiveGlareMaxThreshold__()
{
  idCVar::idCVar(
    this: &r_adaptiveGlareMaxThreshold,
    name: "r_adaptiveGlareMaxThreshold",
    value: "0.8",
    flags: 4,
    description: "Adaptive Glare Max Threshold",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_adaptiveGlareMaxThreshold__);
}


// ========================================================================
// `dynamic initializer for 'r_adaptiveGlareAvgBrightness''
// EA  : 0x8335A240
// RVA : 0x0135A240
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_adaptiveGlareAvgBrightness__()
{
  idCVar::idCVar(
    this: &r_adaptiveGlareAvgBrightness,
    name: "r_adaptiveGlareAvgBrightness",
    value: "0.5",
    flags: 4,
    description: "Adaptive Glare Avg Brightness",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_adaptiveGlareAvgBrightness__);
}


// ========================================================================
// `dynamic initializer for 'r_adaptiveGlareDecayRate''
// EA  : 0x8335A298
// RVA : 0x0135A298
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_adaptiveGlareDecayRate__()
{
  idCVar::idCVar(
    this: &r_adaptiveGlareDecayRate,
    name: "r_adaptiveGlareDecayRate",
    value: "0.1",
    flags: 4,
    description: "Adaptive Glare Decay Rate",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_adaptiveGlareDecayRate__);
}


// ========================================================================
// `dynamic initializer for 'rpViewRandom''
// EA  : 0x8335A2F0
// RVA : 0x0135A2F0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpViewRandom__()
{
  rpViewRandom.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpViewRandom;
}


// ========================================================================
// `dynamic initializer for 'rpCGShadow''
// EA  : 0x8335A310
// RVA : 0x0135A310
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpCGShadow__()
{
  rpCGShadow.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpCGShadow;
}


// ========================================================================
// `dynamic initializer for 'rpCGMidtone''
// EA  : 0x8335A330
// RVA : 0x0135A330
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpCGMidtone__()
{
  rpCGMidtone.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpCGMidtone;
}


// ========================================================================
// `dynamic initializer for 'rpCGHighlight''
// EA  : 0x8335A350
// RVA : 0x0135A350
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpCGHighlight__()
{
  rpCGHighlight.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpCGHighlight;
}


// ========================================================================
// `dynamic initializer for 'rpCGColorDodgeBlend''
// EA  : 0x8335A370
// RVA : 0x0135A370
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpCGColorDodgeBlend__()
{
  rpCGColorDodgeBlend.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpCGColorDodgeBlend;
}


// ========================================================================
// `dynamic initializer for 'rpCGColorBurnBlend''
// EA  : 0x8335A390
// RVA : 0x0135A390
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpCGColorBurnBlend__()
{
  rpCGColorBurnBlend.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpCGColorBurnBlend;
}


// ========================================================================
// `dynamic initializer for 'rpCGColorMultiplyBlend''
// EA  : 0x8335A3B0
// RVA : 0x0135A3B0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpCGColorMultiplyBlend__()
{
  rpCGColorMultiplyBlend.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpCGColorMultiplyBlend;
}


// ========================================================================
// `dynamic initializer for 'rpCGColorScreenBlend''
// EA  : 0x8335A3D0
// RVA : 0x0135A3D0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpCGColorScreenBlend__()
{
  rpCGColorScreenBlend.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpCGColorScreenBlend;
}


// ========================================================================
// `dynamic initializer for 'rpCGBlackLevel''
// EA  : 0x8335A3F0
// RVA : 0x0135A3F0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpCGBlackLevel__()
{
  rpCGBlackLevel.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpCGBlackLevel;
}


// ========================================================================
// `dynamic initializer for 'rpColorGradingLUT''
// EA  : 0x8335A410
// RVA : 0x0135A410
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpColorGradingLUT__()
{
  rpColorGradingLUT.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpColorGradingLUT;
}


// ========================================================================
// `dynamic initializer for 'rpEnvBlendMip''
// EA  : 0x8335A430
// RVA : 0x0135A430
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpEnvBlendMip__()
{
  rpEnvBlendMip.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpEnvBlendMip;
}


// ========================================================================
// `dynamic initializer for 'rpAmbientEnvMap''
// EA  : 0x8335A450
// RVA : 0x0135A450
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpAmbientEnvMap__()
{
  rpAmbientEnvMap.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpAmbientEnvMap;
}


// ========================================================================
// `dynamic initializer for 'rpUserEnvMap''
// EA  : 0x8335A470
// RVA : 0x0135A470
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpUserEnvMap__()
{
  rpUserEnvMap.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpUserEnvMap;
}


// ========================================================================
// `dynamic initializer for 'rpEnvMapRotation''
// EA  : 0x8335A490
// RVA : 0x0135A490
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpEnvMapRotation__()
{
  rpEnvMapRotation.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpEnvMapRotation;
}


// ========================================================================
// `dynamic initializer for 'rpColor''
// EA  : 0x8335A4B0
// RVA : 0x0135A4B0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpColor__()
{
  rpColor.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpColor;
}


// ========================================================================
// `dynamic initializer for 'rpEnvSMatrix''
// EA  : 0x8335A4D0
// RVA : 0x0135A4D0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpEnvSMatrix__()
{
  rpEnvSMatrix.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpEnvSMatrix;
}


// ========================================================================
// `dynamic initializer for 'rpEnvTMatrix''
// EA  : 0x8335A4F0
// RVA : 0x0135A4F0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpEnvTMatrix__()
{
  rpEnvTMatrix.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpEnvTMatrix;
}


// ========================================================================
// `dynamic initializer for 'rpEnvRMatrix''
// EA  : 0x8335A510
// RVA : 0x0135A510
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpEnvRMatrix__()
{
  rpEnvRMatrix.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpEnvRMatrix;
}


// ========================================================================
// `dynamic initializer for 'progOutside''
// EA  : 0x8335A530
// RVA : 0x0135A530
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__progOutside__()
{
  progOutside.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progOutside;
}


// ========================================================================
// `dynamic initializer for 'progShowGuiOverdraw''
// EA  : 0x8335A550
// RVA : 0x0135A550
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__progShowGuiOverdraw__()
{
  progShowGuiOverdraw.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progShowGuiOverdraw;
}


// ========================================================================
// `dynamic initializer for 'rpWindowPosToGlobalX''
// EA  : 0x8335A570
// RVA : 0x0135A570
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpWindowPosToGlobalX__()
{
  rpWindowPosToGlobalX.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpWindowPosToGlobalX;
}


// ========================================================================
// `dynamic initializer for 'rpWindowPosToGlobalY''
// EA  : 0x8335A590
// RVA : 0x0135A590
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpWindowPosToGlobalY__()
{
  rpWindowPosToGlobalY.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpWindowPosToGlobalY;
}


// ========================================================================
// `dynamic initializer for 'rpWindowPosToGlobalZ''
// EA  : 0x8335A5B0
// RVA : 0x0135A5B0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpWindowPosToGlobalZ__()
{
  rpWindowPosToGlobalZ.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpWindowPosToGlobalZ;
}


// ========================================================================
// `dynamic initializer for 'rpWindowPosToGlobalW''
// EA  : 0x8335A5D0
// RVA : 0x0135A5D0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpWindowPosToGlobalW__()
{
  rpWindowPosToGlobalW.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpWindowPosToGlobalW;
}


// ========================================================================
// `dynamic initializer for 'rpLightRotation''
// EA  : 0x8335A5F0
// RVA : 0x0135A5F0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpLightRotation__()
{
  rpLightRotation.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLightRotation;
}


// ========================================================================
// `dynamic initializer for 'rpLightTranslation''
// EA  : 0x8335A610
// RVA : 0x0135A610
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpLightTranslation__()
{
  rpLightTranslation.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLightTranslation;
}


// ========================================================================
// `dynamic initializer for 'rpLightScale''
// EA  : 0x8335A630
// RVA : 0x0135A630
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpLightScale__()
{
  rpLightScale.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLightScale;
}


// ========================================================================
// `dynamic initializer for 'rpLightOscillationAmp''
// EA  : 0x8335A650
// RVA : 0x0135A650
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpLightOscillationAmp__()
{
  rpLightOscillationAmp.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLightOscillationAmp;
}


// ========================================================================
// `dynamic initializer for 'rpLightOscillationFreq''
// EA  : 0x8335A670
// RVA : 0x0135A670
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpLightOscillationFreq__()
{
  rpLightOscillationFreq.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLightOscillationFreq;
}


// ========================================================================
// `dynamic initializer for 'rpLightOscillationPhase''
// EA  : 0x8335A690
// RVA : 0x0135A690
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpLightOscillationPhase__()
{
  rpLightOscillationPhase.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLightOscillationPhase;
}


// ========================================================================
// `dynamic initializer for 'rpWindowPosToProjectedTexS''
// EA  : 0x8335A6B0
// RVA : 0x0135A6B0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpWindowPosToProjectedTexS__()
{
  rpWindowPosToProjectedTexS.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpWindowPosToProjectedTexS;
}


// ========================================================================
// `dynamic initializer for 'rpWindowPosToProjectedTexT''
// EA  : 0x8335A6D0
// RVA : 0x0135A6D0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpWindowPosToProjectedTexT__()
{
  rpWindowPosToProjectedTexT.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpWindowPosToProjectedTexT;
}


// ========================================================================
// `dynamic initializer for 'rpWindowPosToProjectedTexR''
// EA  : 0x8335A6F0
// RVA : 0x0135A6F0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpWindowPosToProjectedTexR__()
{
  rpWindowPosToProjectedTexR.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpWindowPosToProjectedTexR;
}


// ========================================================================
// `dynamic initializer for 'rpWindowPosToProjectedTexQ''
// EA  : 0x8335A710
// RVA : 0x0135A710
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpWindowPosToProjectedTexQ__()
{
  rpWindowPosToProjectedTexQ.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpWindowPosToProjectedTexQ;
}


// ========================================================================
// `dynamic initializer for 'rpWindowPosToProjectedShadowS''
// EA  : 0x8335A730
// RVA : 0x0135A730
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpWindowPosToProjectedShadowS__()
{
  rpWindowPosToProjectedShadowS.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpWindowPosToProjectedShadowS;
}


// ========================================================================
// `dynamic initializer for 'rpWindowPosToProjectedShadowT''
// EA  : 0x8335A750
// RVA : 0x0135A750
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpWindowPosToProjectedShadowT__()
{
  rpWindowPosToProjectedShadowT.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpWindowPosToProjectedShadowT;
}


// ========================================================================
// `dynamic initializer for 'rpWindowPosToProjectedShadowR''
// EA  : 0x8335A770
// RVA : 0x0135A770
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpWindowPosToProjectedShadowR__()
{
  rpWindowPosToProjectedShadowR.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpWindowPosToProjectedShadowR;
}


// ========================================================================
// `dynamic initializer for 'rpWindowPosToProjectedShadowQ''
// EA  : 0x8335A790
// RVA : 0x0135A790
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpWindowPosToProjectedShadowQ__()
{
  rpWindowPosToProjectedShadowQ.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpWindowPosToProjectedShadowQ;
}


// ========================================================================
// `dynamic initializer for 'rpShadowProjectionS''
// EA  : 0x8335A7B0
// RVA : 0x0135A7B0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpShadowProjectionS__()
{
  rpShadowProjectionS.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpShadowProjectionS;
}


// ========================================================================
// `dynamic initializer for 'rpShadowProjectionT''
// EA  : 0x8335A7D0
// RVA : 0x0135A7D0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpShadowProjectionT__()
{
  rpShadowProjectionT.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpShadowProjectionT;
}


// ========================================================================
// `dynamic initializer for 'rpShadowProjectionR''
// EA  : 0x8335A7F0
// RVA : 0x0135A7F0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpShadowProjectionR__()
{
  rpShadowProjectionR.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpShadowProjectionR;
}


// ========================================================================
// `dynamic initializer for 'rpShadowProjectionQ''
// EA  : 0x8335A810
// RVA : 0x0135A810
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpShadowProjectionQ__()
{
  rpShadowProjectionQ.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpShadowProjectionQ;
}


// ========================================================================
// `dynamic initializer for 'rpParallelLightSliceScale''
// EA  : 0x8335A830
// RVA : 0x0135A830
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpParallelLightSliceScale__()
{
  rpParallelLightSliceScale.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpParallelLightSliceScale;
}


// ========================================================================
// `dynamic initializer for 'rpGlobalLightOrigin''
// EA  : 0x8335A850
// RVA : 0x0135A850
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpGlobalLightOrigin__()
{
  rpGlobalLightOrigin.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpGlobalLightOrigin;
}


// ========================================================================
// `dynamic initializer for 'rpStaticSpecularScale''
// EA  : 0x8335A870
// RVA : 0x0135A870
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpStaticSpecularScale__()
{
  rpStaticSpecularScale.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpStaticSpecularScale;
}


// ========================================================================
// `dynamic initializer for 'rpStaticSpecularVector''
// EA  : 0x8335A890
// RVA : 0x0135A890
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpStaticSpecularVector__()
{
  rpStaticSpecularVector.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpStaticSpecularVector;
}


// ========================================================================
// `dynamic initializer for 'rpLightProjectionS''
// EA  : 0x8335A8B0
// RVA : 0x0135A8B0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpLightProjectionS__()
{
  rpLightProjectionS.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLightProjectionS;
}


// ========================================================================
// `dynamic initializer for 'rpLightProjectionT''
// EA  : 0x8335A8D0
// RVA : 0x0135A8D0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpLightProjectionT__()
{
  rpLightProjectionT.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLightProjectionT;
}


// ========================================================================
// `dynamic initializer for 'rpLightProjectionR''
// EA  : 0x8335A8F0
// RVA : 0x0135A8F0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpLightProjectionR__()
{
  rpLightProjectionR.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLightProjectionR;
}


// ========================================================================
// `dynamic initializer for 'rpLightProjectionQ''
// EA  : 0x8335A910
// RVA : 0x0135A910
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpLightProjectionQ__()
{
  rpLightProjectionQ.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLightProjectionQ;
}


// ========================================================================
// `dynamic initializer for 'rpLocalToLightS''
// EA  : 0x8335A930
// RVA : 0x0135A930
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpLocalToLightS__()
{
  rpLocalToLightS.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLocalToLightS;
}


// ========================================================================
// `dynamic initializer for 'rpLocalToLightT''
// EA  : 0x8335A950
// RVA : 0x0135A950
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpLocalToLightT__()
{
  rpLocalToLightT.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLocalToLightT;
}


// ========================================================================
// `dynamic initializer for 'rpLocalToLightR''
// EA  : 0x8335A970
// RVA : 0x0135A970
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpLocalToLightR__()
{
  rpLocalToLightR.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLocalToLightR;
}


// ========================================================================
// `dynamic initializer for 'rpLocalToLightQ''
// EA  : 0x8335A990
// RVA : 0x0135A990
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpLocalToLightQ__()
{
  rpLocalToLightQ.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLocalToLightQ;
}


// ========================================================================
// `dynamic initializer for 'rpLightFade''
// EA  : 0x8335A9B0
// RVA : 0x0135A9B0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpLightFade__()
{
  rpLightFade.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLightFade;
}


// ========================================================================
// `dynamic initializer for 'rpDimShadowFade''
// EA  : 0x8335A9D0
// RVA : 0x0135A9D0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpDimShadowFade__()
{
  rpDimShadowFade.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpDimShadowFade;
}


// ========================================================================
// `dynamic initializer for 'rpDimShadowExtrude''
// EA  : 0x8335A9F0
// RVA : 0x0135A9F0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpDimShadowExtrude__()
{
  rpDimShadowExtrude.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpDimShadowExtrude;
}


// ========================================================================
// `dynamic initializer for 'rpDimShadowClipPlane''
// EA  : 0x8335AA10
// RVA : 0x0135AA10
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpDimShadowClipPlane__()
{
  rpDimShadowClipPlane.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpDimShadowClipPlane;
}


// ========================================================================
// `dynamic initializer for 'rpWindowPosToDimShadowBlurS''
// EA  : 0x8335AA30
// RVA : 0x0135AA30
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpWindowPosToDimShadowBlurS__()
{
  rpWindowPosToDimShadowBlurS.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpWindowPosToDimShadowBlurS;
}


// ========================================================================
// `dynamic initializer for 'rpWindowPosToDimShadowBlurT''
// EA  : 0x8335AA50
// RVA : 0x0135AA50
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpWindowPosToDimShadowBlurT__()
{
  rpWindowPosToDimShadowBlurT.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpWindowPosToDimShadowBlurT;
}


// ========================================================================
// `dynamic initializer for 'rpWindowPosToDimShadowBlurR''
// EA  : 0x8335AA70
// RVA : 0x0135AA70
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpWindowPosToDimShadowBlurR__()
{
  rpWindowPosToDimShadowBlurR.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpWindowPosToDimShadowBlurR;
}


// ========================================================================
// `dynamic initializer for 'rpWindowPosToDimShadowBlurQ''
// EA  : 0x8335AA90
// RVA : 0x0135AA90
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpWindowPosToDimShadowBlurQ__()
{
  rpWindowPosToDimShadowBlurQ.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpWindowPosToDimShadowBlurQ;
}


// ========================================================================
// `dynamic initializer for 'rpVertexMorphScale''
// EA  : 0x8335AAB0
// RVA : 0x0135AAB0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpVertexMorphScale__()
{
  rpVertexMorphScale.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpVertexMorphScale;
}


// ========================================================================
// `dynamic initializer for 'rpNewSpecularScale''
// EA  : 0x8335AAD0
// RVA : 0x0135AAD0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpNewSpecularScale__()
{
  rpNewSpecularScale.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpNewSpecularScale;
}


// ========================================================================
// `dynamic initializer for 'rpGodRaysSourceTexture''
// EA  : 0x8335AAF0
// RVA : 0x0135AAF0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpGodRaysSourceTexture__()
{
  rpGodRaysSourceTexture.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpGodRaysSourceTexture;
}


// ========================================================================
// `dynamic initializer for 'rpTransMap''
// EA  : 0x8335AB10
// RVA : 0x0135AB10
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpTransMap__()
{
  rpTransMap.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpTransMap;
}


// ========================================================================
// `dynamic initializer for 'progDimShadowCreateWound''
// EA  : 0x8335AB30
// RVA : 0x0135AB30
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__progDimShadowCreateWound__()
{
  progDimShadowCreateWound.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progDimShadowCreateWound;
}


// ========================================================================
// `dynamic initializer for 'progDimShadowCreate''
// EA  : 0x8335AB50
// RVA : 0x0135AB50
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__progDimShadowCreate__()
{
  progDimShadowCreate.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progDimShadowCreate;
}


// ========================================================================
// `dynamic initializer for 'progDimShadowCreateAlpha''
// EA  : 0x8335AB70
// RVA : 0x0135AB70
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__progDimShadowCreateAlpha__()
{
  progDimShadowCreateAlpha.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progDimShadowCreateAlpha;
}


// ========================================================================
// `dynamic initializer for 'progDimShadowDraw''
// EA  : 0x8335AB90
// RVA : 0x0135AB90
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__progDimShadowDraw__()
{
  progDimShadowDraw.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progDimShadowDraw;
}


// ========================================================================
// `dynamic initializer for 'progDimShadowDrawHighQuality''
// EA  : 0x8335ABB0
// RVA : 0x0135ABB0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__progDimShadowDrawHighQuality__()
{
  progDimShadowDrawHighQuality.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progDimShadowDrawHighQuality;
}


// ========================================================================
// `dynamic initializer for 'progDimShadowStencil''
// EA  : 0x8335ABD0
// RVA : 0x0135ABD0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__progDimShadowStencil__()
{
  progDimShadowStencil.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progDimShadowStencil;
}


// ========================================================================
// `dynamic initializer for 'progDimShadowDebugDraw''
// EA  : 0x8335ABF0
// RVA : 0x0135ABF0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__progDimShadowDebugDraw__()
{
  progDimShadowDebugDraw.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progDimShadowDebugDraw;
}


// ========================================================================
// `dynamic initializer for 'rpViewColor''
// EA  : 0x8335AC10
// RVA : 0x0135AC10
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpViewColor__()
{
  rpViewColor.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpViewColor;
}


// ========================================================================
// `dynamic initializer for 'progViewColorIdentity''
// EA  : 0x8335AC30
// RVA : 0x0135AC30
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__progViewColorIdentity__()
{
  progViewColorIdentity.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progViewColorIdentity;
}


// ========================================================================
// `dynamic initializer for 'rpGrainScaleBias''
// EA  : 0x8335AC50
// RVA : 0x0135AC50
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpGrainScaleBias__()
{
  rpGrainScaleBias.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpGrainScaleBias;
}


// ========================================================================
// `dynamic initializer for 'rpGrainParms''
// EA  : 0x8335AC70
// RVA : 0x0135AC70
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpGrainParms__()
{
  rpGrainParms.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpGrainParms;
}


// ========================================================================
// `dynamic initializer for 'rpGrainAmount''
// EA  : 0x8335AC90
// RVA : 0x0135AC90
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpGrainAmount__()
{
  rpGrainAmount.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpGrainAmount;
}


// ========================================================================
// `dynamic initializer for 'rpGrainHz''
// EA  : 0x8335ACB0
// RVA : 0x0135ACB0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpGrainHz__()
{
  rpGrainHz.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpGrainHz;
}


// ========================================================================
// `dynamic initializer for 'rpGrainLevelsMin''
// EA  : 0x8335ACD0
// RVA : 0x0135ACD0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpGrainLevelsMin__()
{
  rpGrainLevelsMin.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpGrainLevelsMin;
}


// ========================================================================
// `dynamic initializer for 'rpGrainLevelsMax''
// EA  : 0x8335ACF0
// RVA : 0x0135ACF0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpGrainLevelsMax__()
{
  rpGrainLevelsMax.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpGrainLevelsMax;
}


// ========================================================================
// `dynamic initializer for 'rpShowDepthOfFieldDebug''
// EA  : 0x8335AD10
// RVA : 0x0135AD10
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpShowDepthOfFieldDebug__()
{
  rpShowDepthOfFieldDebug.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpShowDepthOfFieldDebug;
}


// ========================================================================
// `dynamic initializer for 'rpShowGrainLevelsDebug''
// EA  : 0x8335AD30
// RVA : 0x0135AD30
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpShowGrainLevelsDebug__()
{
  rpShowGrainLevelsDebug.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpShowGrainLevelsDebug;
}


// ========================================================================
// `dynamic initializer for 'rpShadowFade''
// EA  : 0x8335AD50
// RVA : 0x0135AD50
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpShadowFade__()
{
  rpShadowFade.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpShadowFade;
}


// ========================================================================
// `dynamic initializer for 'rpShadowBufferResolution''
// EA  : 0x8335AD70
// RVA : 0x0135AD70
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpShadowBufferResolution__()
{
  rpShadowBufferResolution.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpShadowBufferResolution;
}


// ========================================================================
// `dynamic initializer for 'rpViewColorLastFrame''
// EA  : 0x8335AD90
// RVA : 0x0135AD90
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpViewColorLastFrame__()
{
  rpViewColorLastFrame.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpViewColorLastFrame;
}


// ========================================================================
// `dynamic initializer for 'rpDistortionLastFrame''
// EA  : 0x8335ADB0
// RVA : 0x0135ADB0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void _dynamic_initializer_for__rpDistortionLastFrame__()
{
  rpDistortionLastFrame.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpDistortionLastFrame;
}


// ========================================================================
// `dynamic initializer for 'renderState''
// EA  : 0x8335ADD0
// RVA : 0x0135ADD0
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__renderState__()
{
  idRender::idRender(this: &renderState);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__renderState__);
}


// ========================================================================
// `dynamic initializer for 'renderDestShadow''
// EA  : 0x8335AE08
// RVA : 0x0135AE08
// PDB : w:\tech5\engine\renderer\render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__renderDestShadow__()
{
  idRenderDestination::idRenderDestination(this: &renderDestShadow);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__renderDestShadow__);
}

