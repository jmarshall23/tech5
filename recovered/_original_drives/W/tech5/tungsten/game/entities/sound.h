
// ========================================================================
// ??0idTarget_SoundDuck@@QAA@XZ
// EA  : 0x824E3630
// RVA : 0x004E3630
// PDB : w:\tech5\tungsten\game\entities\sound.h
// ========================================================================

idTarget_SoundDuck *__fastcall idTarget_SoundDuck::idTarget_SoundDuck(idTarget_SoundDuck *this)
{
  idEntity::idEntity(this);
  this->decl = nullptr;
  this->__vftable = (idTarget_SoundDuck_vtbl *)&idTarget_SoundDuck::`vftable';
  this->fadeIn = 1.0;
  this->fadeOut = 1.0;
  this->sustain = 10.0;
  this->delay = 0.0;
  return this;
}


// ========================================================================
// ??0idSoundDoor@@QAA@XZ
// EA  : 0x825568C8
// RVA : 0x005568C8
// PDB : w:\tech5\tungsten\game\entities\sound.h
// ========================================================================

idSoundDoor *__fastcall idSoundDoor::idSoundDoor(idSoundDoor *this)
{
  double currentValue; // fp12

  idEntity::idEntity(this);
  this->__vftable = (idSoundDoor_vtbl *)&idSoundDoor::`vftable';
  this->lerp.duration = 0.0;
  this->lerp.startTime = 0.0;
  this->lerp.currentTime = 0.0;
  this->lerp.currentValue = 0.0;
  currentValue = this->lerp.currentValue;
  this->lerp.endValue = this->lerp.currentValue;
  this->lerp.startValue = currentValue;
  this->startOpen = false;
  this->openTime = 1.0;
  this->isOpen = false;
  this->closeTime = 1.0;
  this->doorNum = -1;
  this->distanceAdd = 1024.0;
  return this;
}

