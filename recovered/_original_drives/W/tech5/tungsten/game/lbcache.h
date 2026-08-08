
// ========================================================================
// ??0idLBRowBlock@@QAA@XZ
// EA  : 0x82D9E2C0
// RVA : 0x00D9E2C0
// PDB : w:\tech5\tungsten\game\lbcache.h
// ========================================================================

idLBRowBlock *__fastcall idLBRowBlock::idLBRowBlock(idLBRowBlock *this)
{
  this->lastTime = 0;
  this->startIndex = 0;
  this->rows.granularity = 0;
  this->rows.memTag = 5;
  this->rows.listStatic = 0;
  this->rows.list = nullptr;
  this->rows.size = 0;
  this->rows.num = 0;
  return this;
}

