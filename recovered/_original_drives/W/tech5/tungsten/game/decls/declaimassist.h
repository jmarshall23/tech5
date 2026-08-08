
// ========================================================================
// ??0aimAssistData_t@@QAA@XZ
// EA  : 0x82BCC720
// RVA : 0x00BCC720
// PDB : w:\tech5\tungsten\game\decls\declaimassist.h
// ========================================================================

aimAssistData_t *__fastcall aimAssistData_t::aimAssistData_t(aimAssistData_t *this)
{
  this->targetAdhesionEnable = true;
  this->targetFrictionEnable = true;
  this->targetValidFovDot = 0.0;
  this->targetAdhesionEnableWhileMoving = false;
  this->targetMaxDistance = 3000.0;
  this->targetZoomSnapEnable = true;
  this->targetSelectionRadius = 128.0;
  this->meleeSnapEnable = false;
  this->targetZoomSelectionRadius = 32.0;
  this->meleeLeftHandEnable = false;
  this->targetCoverZoomSelectionRadius = 32.0;
  this->meleeEquipWindow = 100;
  this->targetHeadShotZoomSelectionRadius = 24.0;
  this->meleeLungeEnable = false;
  this->targetAdhesionRadius = 96.0;
  this->targetAdhesionYawSpeedMax = 0.60000002;
  this->targetAdhesionPitchSpeedMax = 0.60000002;
  this->targetAdhesionContributionPctMax = 0.60000002;
  this->targetAdhesionContributionPctMaxZoom = 0.80000001;
  this->targetAdhesionZoomYawSpeedMax = 10.0;
  this->targetAdhesionZoomPitchSpeedMax = 10.0;
  this->targetFrictionMaxDistance = 1024.0;
  this->targetFrictionOptimalDistance = 768.0;
  this->targetFrictionOptimalRadius = 192.0;
  this->targetFrictionRadius = 96.0;
  this->targetFrictionMultiplierMin = 1.0;
  this->targetFrictionMultiplierMax = 0.40000001;
  this->targetFrictionMultiplierMinZoom = 1.0;
  this->targetFrictionMultiplierMaxZoom = 0.30000001;
  this->meleeLungeMinDist = 15.0;
  this->meleeLungeMaxDist = 100.0;
  this->meleeLungeMinSpeed = 1.0;
  this->meleeLungeMaxSpeed = 3.5;
  return this;
}


// ========================================================================
// ?GetDeclInfo@idDeclAimAssist@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BCC868
// RVA : 0x00BCC868
// PDB : w:\tech5\tungsten\game\decls\declaimassist.h
// ========================================================================

idDeclInfoTemplate<idDeclAimAssist> *__fastcall idDeclAimAssist::GetDeclInfo(idDeclAimAssist *this)
{
  return &idDeclAimAssist::resourceList;
}

