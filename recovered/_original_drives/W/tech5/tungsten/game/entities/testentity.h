
// ========================================================================
// ??0idSpawnRenderParm@@QAA@XZ
// EA  : 0x825615D0
// RVA : 0x005615D0
// PDB : w:\tech5\tungsten\game\entities\testentity.h
// ========================================================================

idSpawnRenderParm *__fastcall idSpawnRenderParm::idSpawnRenderParm(idSpawnRenderParm *this)
{
  this->value.len = 0;
  this->value.allocedAndFlag = 20;
  this->value.data = this->value.baseBuffer;
  this->value.baseBuffer[0] = 0;
  this->parm = nullptr;
  return this;
}

