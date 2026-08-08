
// ========================================================================
// ??0idDeferredDecalQuery@@QAA@XZ
// EA  : 0x827082B8
// RVA : 0x007082B8
// PDB : w:\tech5\engine\gamelib\effects\deferreddecalmanager.h
// ========================================================================

idDeferredDecalQuery *__fastcall idDeferredDecalQuery::idDeferredDecalQuery(idDeferredDecalQuery *this)
{
  unsigned __int64 v1; // r11

  LODWORD(v1) = 0;
  this->decalParams.depth = 8.0;
  this->decalParams.decalMat = nullptr;
  this->decalParams.size.x = 32.0;
  this->decalParams.size.y = 32.0;
  this->decalParams.lifetime = 10000;
  this->decalParams.fadeInEndTime = 0;
  this->decalParams.angle = 0.0;
  this->decalParams.fadetime = 2000;
  this->decalParams.depth = 8.0;
  this->decalParams.decalMat = nullptr;
  this->decalParams.size.x = 32.0;
  HIDWORD(v1) = &this->decalParams.size;
  this->decalParams.size.y = 32.0;
  this->decalParams.lifetime = 10000;
  this->decalParams.angle = 0.0;
  this->decalParams.fadeInEndTime = 0;
  this->decalParams.fadetime = 2000;
  this->theQuery.index = v1;
  return this;
}

