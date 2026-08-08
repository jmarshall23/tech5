
// ========================================================================
// ??0md6OriginDelta_t@@QAA@XZ
// EA  : 0x82B2C5C8
// RVA : 0x00B2C5C8
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6blendshared.h
// ========================================================================

md6OriginDelta_t *__fastcall md6OriginDelta_t::md6OriginDelta_t(md6OriginDelta_t *this)
{
  this->done = false;
  this->fudged = false;
  this->time = -1;
  this->deltaRotation[2] = 0.0;
  this->deltaRotation[1] = 0.0;
  this->deltaRotation[0] = 0.0;
  this->deltaRotation[3] = 1.0;
  this->deltaScale[3] = 1.0;
  this->deltaScale[2] = 1.0;
  this->deltaScale[1] = 1.0;
  this->deltaScale[0] = 1.0;
  this->deltaTranslation[3] = 0.0;
  this->deltaTranslation[2] = 0.0;
  this->deltaTranslation[1] = 0.0;
  this->deltaTranslation[0] = 0.0;
  this->animRotation[2] = 0.0;
  this->animRotation[1] = 0.0;
  this->animRotation[0] = 0.0;
  this->animRotation[3] = 1.0;
  this->animTranslation[3] = 0.0;
  this->animTranslation[2] = 0.0;
  this->animTranslation[1] = 0.0;
  this->animTranslation[0] = 0.0;
  this->jointBounds[0] = 1.0e30;
  this->jointBounds[1] = 1.0e30;
  this->jointBounds[2] = 1.0e30;
  this->jointBounds[3] = -1.0e30;
  this->jointBounds[4] = -1.0e30;
  this->jointBounds[5] = -1.0e30;
  return this;
}

