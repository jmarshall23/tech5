
// ========================================================================
// ??0idEffectPhysicsDebrisEmitter@@QAA@XZ
// EA  : 0x82B94488
// RVA : 0x00B94488
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsdebrisemitter.h
// ========================================================================

idEffectPhysicsDebrisEmitter *__fastcall idEffectPhysicsDebrisEmitter::idEffectPhysicsDebrisEmitter(
        idEffectPhysicsDebrisEmitter *this)
{
  idEffectPhysicsPieceEmitter::idEffectPhysicsPieceEmitter(this: &this->piecePhysics);
  this->emitBuffer[0].pos = vec3_origin;
  this->emitBuffer[0].normal = vec3_origin;
  this->emitBuffer[0].count = 0;
  this->emitBuffer[1].pos = vec3_origin;
  this->emitBuffer[1].normal = vec3_origin;
  this->emitBuffer[1].count = 0;
  this->emitBuffer[2].pos = vec3_origin;
  this->emitBuffer[2].normal = vec3_origin;
  this->emitBuffer[2].count = 0;
  this->emitBuffer[3].pos = vec3_origin;
  this->emitBuffer[3].normal = vec3_origin;
  this->emitBuffer[3].count = 0;
  this->emitBuffer[4].pos = vec3_origin;
  this->emitBuffer[4].normal = vec3_origin;
  this->emitBuffer[4].count = 0;
  this->emitBuffer[5].pos = vec3_origin;
  this->emitBuffer[5].normal = vec3_origin;
  this->emitBuffer[5].count = 0;
  this->emitBuffer[6].pos = vec3_origin;
  this->emitBuffer[6].normal = vec3_origin;
  this->emitBuffer[6].count = 0;
  this->emitBuffer[7].pos = vec3_origin;
  this->emitBuffer[7].normal = vec3_origin;
  this->emitBuffer[7].count = 0;
  this->emitBuffer[8].pos = vec3_origin;
  this->emitBuffer[8].normal = vec3_origin;
  this->emitBuffer[8].count = 0;
  this->emitBuffer[9].pos = vec3_origin;
  this->emitBuffer[9].normal = vec3_origin;
  this->emitBuffer[9].count = 0;
  this->random.seed = 0;
  this->emitBufferPos = 0;
  this->serializeEmitCount = 0;
  this->skipFirstFrame = false;
  this->active = false;
  return this;
}

