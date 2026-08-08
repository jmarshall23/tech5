
// ========================================================================
// ??0idCoverQueryAvoid@@QAA@PAVidAI2@@PBVidEntity@@ABVidAICover@@M@Z
// EA  : 0x82AC2198
// RVA : 0x00AC2198
// PDB : w:\tech5\tungsten\game\ai\cover\coverqueryavoid.h
// ========================================================================

idCoverQueryAvoid *__fastcall idCoverQueryAvoid::idCoverQueryAvoid(
        idCoverQueryAvoid *this,
        idAI2 *ai,
        const idEntity *avoidEnt,
        const idAICover *exclude,
        double maxAvoidTime)
{
  idCoverQuery::idCoverQuery(this, ai, exclude, flags: 31);
  this->maxAvoidTime = maxAvoidTime;
  this->avoidEnt = avoidEnt;
  this->__vftable = (idCoverQueryAvoid_vtbl *)&idCoverQueryAvoid::`vftable';
  this->avoidvcPos.valid = false;
  this->avoidvcPos.areaNum = 0;
  this->avoidvcPos.origin.x = 0.0;
  this->avoidvcPos.origin.y = 0.0;
  this->avoidvcPos.origin.z = 0.0;
  this->avoidvcPos.validOrigin.x = 0.0;
  this->avoidvcPos.validOrigin.y = 0.0;
  this->avoidvcPos.validOrigin.z = 0.0;
  this->avoidvcPos.aas = nullptr;
  return this;
}

