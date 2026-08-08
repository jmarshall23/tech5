
// ========================================================================
// ??0renderView_t@@QAA@W4threadId_t@@@Z
// EA  : 0x82582C90
// RVA : 0x00582C90
// PDB : w:\tech5\engine\renderer\renderview.h
// ========================================================================

renderView_t *__fastcall renderView_t::renderView_t(renderView_t *this, threadId_t threadId)
{
  idStaticParmBlock<32>::idStaticParmBlock<32>(this: &this->parmBlock, threadId);
  idStaticParmBlock<32>::idStaticParmBlock<32>(this: &this->envOverrideParmBlock, threadId);
  this->viewID = 0;
  this->forceFullVirtualTextureLoad = false;
  this->renderTime = 0;
  this->discontinuousViewPosition = false;
  this->cramZNear = false;
  this->skipDimShadows = false;
  this->fov_x = 90.0;
  this->skipPostProcess = false;
  this->fov_y = 90.0;
  this->skipDynamicEnvironment = false;
  this->vieworg.z = 0.0;
  this->vieworg.y = 0.0;
  this->vieworg.x = 0.0;
  this->viewaxis.mat[2].z = 1.0;
  this->viewaxis.mat[1].y = 1.0;
  this->viewaxis.mat[0].x = 1.0;
  this->viewaxis.mat[1].z = 0.0;
  this->viewaxis.mat[0].z = 0.0;
  this->viewaxis.mat[0].y = 0.0;
  this->viewaxis.mat[2].y = 0.0;
  this->viewaxis.mat[2].x = 0.0;
  this->viewaxis.mat[1].x = 0.0;
  this->dynEnvOverride = nullptr;
  this->dynEnvOverrideDuration = 0.0;
  this->dynEnvOverrideModelIndex = -1;
  this->applyDynEnvOverride = false;
  this->radialBlurEnabled = false;
  this->radialBlurCenterPos = vec3_origin;
  this->forceFullResolution = false;
  this->useHQViewColorMipsGeneration = false;
  this->useExplicitProjectionMatrix = false;
  this->forceIdentityViewMatrix = false;
  memset(Dst: &this->explicitProjectionMatrix, Val: 0, Size: sizeof(this->explicitProjectionMatrix));
  this->godRaysEnabled = false;
  this->godRaysPosition.x = 0.0;
  this->godRaysPosition.y = 0.0;
  this->godRaysPosition.z = -1.0;
  this->godRaysColor.x = 0.015;
  this->godRaysColor.y = 0.015;
  this->godRaysColor.z = 0.015;
  this->godRaysMaterial = nullptr;
  this->godRaysSize = 768.0;
  this->godRaysSourceSize = 256.0;
  return this;
}


// ========================================================================
// __unwind$667502
// EA  : 0x82582E10
// RVA : 0x00582E10
// PDB : w:\tech5\engine\renderer\renderview.h
// ========================================================================

void _unwind_667502()
{
  int v0; // r12

  idStaticParmBlock<32>::~idStaticParmBlock<32>(this: (idStaticParmBlock<32> *)(*(_DWORD *)(v0 - 144 + 164) + 160));
}


// ========================================================================
// ?GetModelOcclusionResult@idRenderView@@QBAHH@Z
// EA  : 0x827D2DB8
// RVA : 0x007D2DB8
// PDB : w:\tech5\engine\renderer\renderview.h
// ========================================================================

int __fastcall idRenderView::GetModelOcclusionResult(idRenderView *this, int modelIndex)
{
  occlusionState_t *occlusionState; // r11

  if ( this->occlusionState->modelVisibleFrameNumber[modelIndex] < this->occlusionState->renderFrameNumber )
    return 0;
  occlusionState = this->occlusionState;
  if ( occlusionState->modelVisibleFrameCount[modelIndex] <= 1 )
    return 0;
  else
    return occlusionState->modelOcclusionQueryResult[modelIndex];
}

