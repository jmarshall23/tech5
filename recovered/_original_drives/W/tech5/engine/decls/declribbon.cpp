
// ========================================================================
// ??0idDeclRibbon@@QAA@XZ
// EA  : 0x82629AB0
// RVA : 0x00629AB0
// PDB : w:\tech5\engine\decls\declribbon.cpp
// ========================================================================

idDeclRibbon *__fastcall idDeclRibbon::idDeclRibbon(idDeclRibbon *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->maxLength = 0.0;
  this->fadeInFraction = 0.0;
  this->__vftable = (idDeclRibbon_vtbl *)&idDeclRibbon::`vftable';
  this->fadeOutFraction = 0.0;
  this->material = nullptr;
  this->duration = 0;
  this->gravity.x = 0.0;
  this->gravity.y = 0.0;
  this->gravity.z = 0.0;
  this->velocity.x = 0.0;
  this->velocity.y = 0.0;
  this->velocity.z = 0.0;
  this->startWidth = 2.0;
  this->endWidth = 32.0;
  this->color.x = 1.0;
  this->color.y = 1.0;
  this->color.z = 1.0;
  this->color.w = 1.0;
  this->viewOriented = true;
  this->textureTMin = 0.0;
  this->reorientNodes = false;
  this->nodeSubdivision = 0.0;
  this->textureRepeat = false;
  this->minNodeDistance = 0.0;
  this->textureRepeatStretch = false;
  this->helix.rotationScale = 0.0;
  this->helix.radius = 0.0;
  this->helix.velocity = 0.0;
  this->textureTMax = 1.0;
  this->helix.distortion0.x = 0.0;
  this->helix.distortion0.y = 0.0;
  this->helix.distortion1.x = 0.0;
  this->helix.distortion1.y = 0.0;
  this->turbulence.frequency = 0.0;
  this->turbulence.magnitude = 0.0;
  this->turbulence.velocity = 1.0;
  this->turbulence.magic.x = 0.93000001;
  this->turbulence.magic.y = 1.0;
  this->turbulence.magic.z = 0.91000003;
  this->turbulence.magic.w = 0.73000002;
  return this;
}

