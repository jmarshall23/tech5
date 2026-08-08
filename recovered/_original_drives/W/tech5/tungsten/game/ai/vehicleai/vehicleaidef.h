
// ========================================================================
// ??0navSplinePath_t@@QAA@XZ
// EA  : 0x82C2B6C0
// RVA : 0x00C2B6C0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehicleaidef.h
// ========================================================================

navSplinePath_t *__fastcall navSplinePath_t::navSplinePath_t(navSplinePath_t *this)
{
  this->startDistance = 0.0;
  this->endDistance = 0.0;
  this->distance = 1.0e30;
  this->rightDelta = 0.0;
  this->path.list = nullptr;
  this->path.granularity = 0;
  this->path.memTag = 5;
  this->path.listStatic = 0;
  this->path.size = 0;
  this->path.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->path);
  return this;
}

