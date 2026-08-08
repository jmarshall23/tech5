
// ========================================================================
// ?GetDeclInfo@idDeclOnlineScoringCallout@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC9468
// RVA : 0x00BC9468
// PDB : w:\tech5\tungsten\game\decls\declonlinecoopscoring.h
// ========================================================================

idDeclInfoTemplate<idDeclOnlineScoringCallout> *__fastcall idDeclOnlineScoringCallout::GetDeclInfo(
        idDeclOnlineScoringCallout *this)
{
  return &idDeclOnlineScoringCallout::resourceList;
}


// ========================================================================
// ??0coopScoring_Multiplier_t@idDeclOnlineCoopScoring@@QAA@XZ
// EA  : 0x82BC9540
// RVA : 0x00BC9540
// PDB : w:\tech5\tungsten\game\decls\declonlinecoopscoring.h
// ========================================================================

idDeclOnlineCoopScoring::coopScoring_Multiplier_t *__fastcall idDeclOnlineCoopScoring::coopScoring_Multiplier_t::coopScoring_Multiplier_t(
        idDeclOnlineCoopScoring::coopScoring_Multiplier_t *this)
{
  this->normalDamageMultiplierPointsFactor = 1.0;
  this->headshotDamageMultiplierPointsFactor = 1.0;
  this->assistPoints = 50;
  this->takenNormalDamageScale = 1.0;
  this->comboPoints = 50;
  this->takenMeleeDamageScale = 1.0;
  this->defendPoints = 50;
  this->takenProjectileDamageScale = 1.0;
  this->covertPoints = 50;
  this->takenDamageMultiplierScale = 10.0;
  this->brutalPoints = 50;
  this->revivePCTPoints = 0.75;
  this->incapacitatePoints = -1000;
  this->idlePointsStartupTime = 15.0;
  this->incapacitatePointsPerSecond = -10;
  this->idlePointsPerSecond = -10;
  this->takenDamageTable.list = nullptr;
  this->takenDamageTable.granularity = 0;
  this->takenDamageTable.memTag = 5;
  this->takenDamageTable.listStatic = 0;
  this->takenDamageTable.size = 0;
  this->takenDamageTable.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->takenDamageTable);
  this->takenDamageResetTime = 5000;
  return this;
}


// ========================================================================
// ?GetDeclInfo@idDeclOnlineCoopScoring@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC9728
// RVA : 0x00BC9728
// PDB : w:\tech5\tungsten\game\decls\declonlinecoopscoring.h
// ========================================================================

idDeclInfoTemplate<idDeclOnlineCoopScoring> *__fastcall idDeclOnlineCoopScoring::GetDeclInfo(
        idDeclOnlineCoopScoring *this)
{
  return &idDeclOnlineCoopScoring::resourceList;
}


// ========================================================================
// ??1idDeclOnlineCoopScoring@@UAA@XZ
// EA  : 0x82BC9740
// RVA : 0x00BC9740
// PDB : w:\tech5\tungsten\game\decls\declonlinecoopscoring.h
// ========================================================================

void __fastcall idDeclOnlineCoopScoring::~idDeclOnlineCoopScoring(idDeclOnlineCoopScoring *this)
{
  this->__vftable = (idDeclOnlineCoopScoring_vtbl *)&idDeclOnlineCoopScoring::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->multiplier.takenDamageTable);
  idDeclTypeInfo::~idDeclTypeInfo(this);
}


// ========================================================================
// __unwind$487522
// EA  : 0x82BC9798
// RVA : 0x00BC9798
// PDB : w:\tech5\tungsten\game\decls\declonlinecoopscoring.h
// ========================================================================

void _unwind_487522()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}

