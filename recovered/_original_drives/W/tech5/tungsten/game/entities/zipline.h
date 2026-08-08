
// ========================================================================
// ??0idProp_ZiplineOscillationParams@idProp_Zipline@@QAA@XZ
// EA  : 0x82D58B70
// RVA : 0x00D58B70
// PDB : w:\tech5\tungsten\game\entities\zipline.h
// ========================================================================

idProp_Zipline::idProp_ZiplineOscillationParams *__fastcall idProp_Zipline::idProp_ZiplineOscillationParams::idProp_ZiplineOscillationParams(
        idProp_Zipline::idProp_ZiplineOscillationParams *this)
{
  this->fwdMagMin = 4.0;
  this->fwdMagMax = 6.0;
  this->fwdMag = 0.0;
  this->fwdFreqMin = 0.40000001;
  this->fwdFreqMax = 0.60000002;
  this->fwdFreq = 0.0;
  this->rtMagMin = 3.0;
  this->rtMagMax = 5.0;
  this->rtMag = 0.0;
  this->rtFreqMin = 0.30000001;
  this->rtFreqMax = 0.5;
  this->rtFreq = 0.0;
  this->upMagMin = 2.0;
  this->upMagMax = 4.0;
  this->upMag = 0.0;
  this->upFreqMin = 0.2;
  this->upFreqMax = 0.40000001;
  this->upFreq = 0.0;
  return this;
}


// ========================================================================
// ??0idZipline@@QAA@XZ
// EA  : 0x82D5C098
// RVA : 0x00D5C098
// PDB : w:\tech5\tungsten\game\entities\zipline.h
// ========================================================================

idZipline *__fastcall idZipline::idZipline(idZipline *this)
{
  this->points.list = nullptr;
  this->points.granularity = 0;
  this->points.memTag = 5;
  this->points.listStatic = 0;
  this->points.size = 0;
  this->points.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->totalLength = 0.0;
  return this;
}

