
// ========================================================================
// ??0idRenderLightParms@@QAA@XZ
// EA  : 0x82942500
// RVA : 0x00942500
// PDB : w:\tech5\engine\renderer\renderlightparms.h
// ========================================================================

idRenderLightParms *__fastcall idRenderLightParms::idRenderLightParms(idRenderLightParms *this)
{
  this->axis.mat[1].z = 0.0;
  this->axis.mat[0].z = 0.0;
  this->axis.mat[0].y = 0.0;
  this->axis.mat[2].y = 0.0;
  this->axis.mat[2].x = 0.0;
  this->axis.mat[1].x = 0.0;
  this->axis.mat[2].z = 1.0;
  this->axis.mat[1].y = 1.0;
  this->axis.mat[0].x = 1.0;
  this->origin.z = 0.0;
  this->origin.y = 0.0;
  this->origin.x = 0.0;
  this->allowLightOnlyInViewID = 0;
  this->suppressLightInViewID = 0;
  this->noShadows = false;
  this->slowLight = false;
  this->lightType = LIGHT_POINT;
  this->lightClass = LIGHT_NORMAL;
  this->lightFalloff = LIGHT_FALLOFF_TEXTURE;
  this->shader = nullptr;
  this->lightRadius.x = 200.0;
  this->lightRadius.y = 200.0;
  this->lightRadius.z = 200.0;
  this->lightCenter.z = 0.0;
  this->lightCenter.y = 0.0;
  this->lightCenter.x = 0.0;
  this->target.z = 0.0;
  this->target.y = 0.0;
  this->target.x = 0.0;
  this->right.z = 0.0;
  this->right.y = 0.0;
  this->right.x = 0.0;
  this->up.z = 0.0;
  this->up.y = 0.0;
  this->up.x = 0.0;
  this->start.z = 0.0;
  this->start.y = 0.0;
  this->start.x = 0.0;
  this->end.z = 0.0;
  this->end.y = 0.0;
  this->end.x = 0.0;
  this->maxVisibleRange = 0.0;
  this->fadeVisibilityOver = 400.0;
  this->dynamicModelLightingScale.x = 1.0;
  this->dynamicModelLightingScale.y = 1.0;
  this->dynamicModelLightingScale.z = 1.0;
  this->dimShadowStretch = 1.0;
  this->staticSpecularScale = 10.0;
  this->staticSpecularVector.x = 0.0;
  this->staticSpecularVector.y = 0.70700002;
  this->staticSpecularVector.z = 0.70700002;
  this->bakedParallelShadows = false;
  this->iesFile = nullptr;
  this->iesAreaScale = 1.0;
  this->slowMultiPass = 1;
  this->iesPowerScale = 1.0;
  this->areaLightSize = 8.0;
  this->shadowSampleScale = 1.0;
  return this;
}

