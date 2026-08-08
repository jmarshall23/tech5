
// ========================================================================
// ?Clear@soundShaderParms_t@@QAAXXZ
// EA  : 0x82561128
// RVA : 0x00561128
// PDB : w:\tech5\engine\sound\soundshader.h
// ========================================================================

void __fastcall soundShaderParms_t::Clear(soundShaderParms_t *this)
{
  this->shakeFalloff = nullptr;
  this->soundShaderFlags = 0;
  this->groups = SSG_MASTER;
  this->minDistance = 0.0;
  this->soundChannel = SND_CHANNEL_ANY;
  this->maxDistance = 0.0;
  this->falloff = nullptr;
  this->distanceFactor = 1.0;
  this->wetFalloff = nullptr;
  this->wetMinDistanceOffset = 0.0;
  this->maxPlay.maxShaders = 0;
  this->wetMaxDistanceOffset = 0.0;
  this->maxPlay.playbackType = SMAX_IGNORE;
  this->coneAttenuation.innerAngle = 0.0;
  this->priority = SPRIORITY_LOW;
  this->coneAttenuation.outerAngle = 0.0;
  this->coneAttenuation.outerVolume = -60.0;
  this->volume.min = 0.0;
  this->volume.max = 0.0;
  this->volume.granularity = 0.0;
  this->wetVolume = 0.0;
  this->pitch.min = 0.0;
  this->pitch.max = 0.0;
  this->pitch.granularity = 0.0;
  this->loopFadeInDuration = 0.0;
  this->loopFadeOutDuration = 0.0;
  this->dopplerMultiplier = 1.0;
  this->shakes = 0.0;
  this->minShakeDistance = 0.0;
  this->maxShakeDistance = 0.0;
  this->lowPassMinDistance = 0.0;
  this->lowPassStrength = 0.0;
  this->lfeVolume = -60.0;
  this->centerChannel = 0.0;
  this->headroom = 0.0;
  this->distanceBasedRanges.farMaxRange = 0.0;
  this->distanceBasedRanges.nearMinRange = 0.0;
}


// ========================================================================
// ?Override@soundShaderParms_t@@QAAXABU1@@Z
// EA  : 0x8298BF98
// RVA : 0x0098BF98
// PDB : w:\tech5\engine\sound\soundshader.h
// ========================================================================

void __fastcall soundShaderParms_t::Override(soundShaderParms_t *this, const soundShaderParms_t *over)
{
  double max; // fp11
  double min; // fp10
  double v4; // fp7
  double v5; // fp0
  double v6; // fp7
  double v7; // fp5
  double v8; // fp3
  double v9; // fp2
  double v11; // fp7
  double maxDistance; // fp6
  double wetMaxDistanceOffset; // fp4
  double v14; // fp9
  double v18; // fp0
  soundShaderFlags_t soundShaderFlags; // r9
  soundChannel_t soundChannel; // r11
  const idDeclTable *falloff; // r11
  const idDeclTable *wetFalloff; // r11

  max = this->volume.max;
  this->volume.min = over->volume.min + this->volume.min;
  this->volume.max = over->volume.max + (float)max;
  if ( over->volume.granularity > 0.0 )
    this->volume.granularity = over->volume.granularity;
  min = this->pitch.min;
  this->wetVolume = over->wetVolume + this->wetVolume;
  v4 = this->pitch.max;
  this->pitch.min = over->pitch.min + (float)min;
  this->pitch.max = over->pitch.max + (float)v4;
  if ( over->pitch.granularity > 0.0 )
    this->pitch.granularity = over->pitch.granularity;
  v5 = (float)(over->distanceFactor * this->distanceFactor);
  this->distanceFactor = over->distanceFactor * this->distanceFactor;
  if ( v5 != 1.0 )
  {
    v6 = (float)(this->lowPassMinDistance * (float)v5);
    v7 = (float)(this->maxDistance * (float)v5);
    v8 = (float)(this->wetMinDistanceOffset * (float)v5);
    v9 = (float)(this->wetMaxDistanceOffset * (float)v5);
    this->minDistance = this->minDistance * (float)v5;
    this->lowPassMinDistance = v6;
    this->maxDistance = v7;
    this->wetMinDistanceOffset = v8;
    this->wetMaxDistanceOffset = v9;
    this->distanceFactor = 1.0;
  }
  if ( over->minDistance > 0.0 )
    this->minDistance = over->distanceFactor * over->minDistance;
  if ( over->maxDistance > 0.0 )
    this->maxDistance = over->distanceFactor * over->maxDistance;
  if ( over->coneAttenuation.outerAngle > 0.0 )
    this->coneAttenuation = over->coneAttenuation;
  _FP13 = -this->minDistance;
  v11 = (float)((float)(over->wetMinDistanceOffset * over->distanceFactor) + this->wetMinDistanceOffset);
  maxDistance = this->maxDistance;
  wetMaxDistanceOffset = this->wetMaxDistanceOffset;
  this->wetMinDistanceOffset = (float)(over->wetMinDistanceOffset * over->distanceFactor) + this->wetMinDistanceOffset;
  v14 = (float)((float)(over->wetMaxDistanceOffset * over->distanceFactor) + (float)wetMaxDistanceOffset);
  __asm { fsel      f0, f13, f12, f0 }
  this->minDistance = _FP0;
  this->wetMaxDistanceOffset = v14;
  _FP3 = (float)((float)_FP0 - (float)maxDistance);
  __asm { fsel      f13, f3, f0, f6 }
  this->maxDistance = _FP13;
  if ( (float)((float)v11 + (float)_FP0) < 0.0 )
    this->wetMinDistanceOffset = -_FP0;
  v18 = (float)(this->wetMinDistanceOffset + (float)_FP0);
  if ( (float)(this->wetMaxDistanceOffset + (float)_FP13) < v18 )
    this->wetMaxDistanceOffset = (float)v18 - (float)_FP13;
  if ( over->loopFadeInDuration > 0.0 )
    this->loopFadeInDuration = over->loopFadeInDuration;
  if ( over->loopFadeOutDuration > 0.0 )
    this->loopFadeOutDuration = over->loopFadeOutDuration;
  if ( over->dopplerMultiplier != 1.0 )
    this->dopplerMultiplier = over->dopplerMultiplier;
  if ( over->shakes > 0.0 )
    this->shakes = over->shakes;
  soundShaderFlags = this->soundShaderFlags;
  this->groups |= over->groups;
  this->soundShaderFlags = over->soundShaderFlags | soundShaderFlags;
  soundChannel = over->soundChannel;
  if ( soundChannel != SND_CHANNEL_ANY )
    this->soundChannel = soundChannel;
  if ( over->lowPassMinDistance > 0.0 )
    this->lowPassMinDistance = over->lowPassMinDistance;
  if ( over->lowPassStrength > 0.0 )
    this->lowPassStrength = over->distanceFactor * over->lowPassStrength;
  falloff = over->falloff;
  if ( falloff != nullptr )
    this->falloff = falloff;
  wetFalloff = over->wetFalloff;
  if ( wetFalloff != nullptr )
    this->wetFalloff = wetFalloff;
  this->lfeVolume = over->lfeVolume + this->lfeVolume;
  if ( over->centerChannel > 0.0 )
    this->centerChannel = over->centerChannel;
  this->headroom = over->headroom + this->headroom;
}


// ========================================================================
// ?GetDeclInfo@idDeclDuck@@UBAPAVidDeclInfo@@XZ
// EA  : 0x8298FF38
// RVA : 0x0098FF38
// PDB : w:\tech5\engine\sound\soundshader.h
// ========================================================================

idDeclInfoTemplate<idDeclDuck> *__fastcall idDeclDuck::GetDeclInfo(idDeclDuck *this)
{
  return &idDeclDuck::resourceList;
}


// ========================================================================
// ?DefaultDefinition@idDeclTypeInfo@@UBAPBDXZ
// EA  : 0x8298FF48
// RVA : 0x0098FF48
// PDB : w:\tech5\engine\sound\soundshader.h
// ========================================================================

const char *__fastcall idDeclTypeInfo::DefaultDefinition(idDeclTypeInfo *this)
{
  return "{ }\n";
}


// ========================================================================
// ?GetDeclInfo@idSoundShader@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82990F18
// RVA : 0x00990F18
// PDB : w:\tech5\engine\sound\soundshader.h
// ========================================================================

idDeclInfoTemplate<idSoundShader> *__fastcall idSoundShader::GetDeclInfo(idSoundShader *this)
{
  return &idSoundShader::resourceList;
}

