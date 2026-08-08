
// ========================================================================
// ??0idRenderModelParms@@QAA@XZ
// EA  : 0x827F2B08
// RVA : 0x007F2B08
// PDB : w:\tech5\engine\renderer\rendermodelparms.h
// ========================================================================

idRenderModelParms *__fastcall idRenderModelParms::idRenderModelParms(idRenderModelParms *this)
{
  char v2; // r4
  char v3; // r11

  this->origin.z = 0.0;
  this->origin.y = 0.0;
  this->origin.x = 0.0;
  this->axis.mat[2].z = 1.0;
  this->axis.mat[1].y = 1.0;
  this->axis.mat[0].x = 1.0;
  this->axis.mat[1].z = 0.0;
  this->axis.mat[0].z = 0.0;
  this->axis.mat[0].y = 0.0;
  this->axis.mat[2].y = 0.0;
  this->axis.mat[2].x = 0.0;
  this->axis.mat[1].x = 0.0;
  this->scale.z = 1.0;
  this->scale.y = 1.0;
  this->scale.x = 1.0;
  this->customMaterial = nullptr;
  this->allowSurfaceOnlyInViewID = 0;
  this->suppressSurfaceInViewID = 0;
  this->fovScale = 1.0;
  this->suppressShadowInViewID = 0;
  this->modelDepthHack = 0.0;
  this->castDimShadows = DIMSHADOW_OFF;
  this->radiosityScale = 1.0;
  *((_BYTE *)this + 104) = 0;
  this->staticReflectionStrength = 1.0;
  *((_BYTE *)this + 105) = 0;
  this->maxTexelDensity = 0.0;
  *((_BYTE *)this + 108) = 0;
  this->maxVisibleRange = 0.0;
  this->highlightColor = HIGHLIGHT_COLOR_NONE;
  this->fadeVisibilityOver = 400.0;
  this->referenceModel = nullptr;
  this->modelFade = 1.0;
  this->customSkin = -1;
  this->dimShadowClipZ = 0.0;
  this->suppressShadowInLightIndex = -1;
  this->groupMasterIndex = -1;
  this->firstVisibleFrameCount = 2;
  v2 = *((_BYTE *)this + 107);
  v3 = *((_BYTE *)this + 116);
  *((_BYTE *)this + 106) &= 0x20u;
  *((_BYTE *)this + 116) = v3 & 0x1F;
  *((_BYTE *)this + 107) = v2 & 3;
  idScreenRect::Zero(this: &this->viewport);
  *((_BYTE *)this + 106) &= ~0x20u;
  return this;
}

