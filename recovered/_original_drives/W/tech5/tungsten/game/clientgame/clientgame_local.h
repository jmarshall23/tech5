
// ========================================================================
// ??0idReplicatedSound@@QAA@XZ
// EA  : 0x8256FB78
// RVA : 0x0056FB78
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.h
// ========================================================================

idReplicatedSound *__fastcall idReplicatedSound::idReplicatedSound(idReplicatedSound *this)
{
  int v2; // ctr
  unsigned __int8 *p_peerMask; // r11

  this->volume = 0.0;
  this->channel = SND_CHANNEL_ANY;
  this->soundFadeTo = 0.0;
  this->shader = nullptr;
  this->soundFadeTime = 0.0;
  this->internalFlags = 0;
  this->volumeAdjustment = 0.0;
  this->clearVolumeAdjustment = false;
  soundShaderParms_t::Clear(this: &this->parms);
  v2 = 7;
  p_peerMask = &this->peerMask;
  this->position = vec3_origin;
  this->presentableIndex = -1;
  this->peerMask = -1;
  this->time = 0;
  this->framesToForceKeep = 0;
  do
  {
    *++p_peerMask = 0;
    --v2;
  }
  while ( v2 != 0 );
  *(_WORD *)this->lastChanged = 0;
  *(_WORD *)&this->lastChanged[2] = 0;
  *(_WORD *)&this->lastChanged[4] = 0;
  this->lastChanged[6] = 0;
  return this;
}


// ========================================================================
// ?Serialize@idReplicatedSound@@QAAXAAVidSerializer@@@Z
// EA  : 0x82B51B88
// RVA : 0x00B51B88
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.h
// ========================================================================

void __fastcall idReplicatedSound::Serialize(idReplicatedSound *this, idSerializer *ser)
{
  soundChannel_t channel; // r29
  idBitMsg *msg; // r3
  unsigned int v6; // r10
  idBitMsg *v7; // r3
  unsigned int v8; // r10
  replicatedSoundFlags_t internalFlags; // r29
  idVec3 *p_position; // r4
  idBitMsg *v11; // r3
  idBitMsg *v12; // r3
  idBitMsg *v13; // r3
  idBitMsg *v14; // r3
  bool clearVolumeAdjustment; // r29
  idBitMsg *v16; // r3
  int v17; // r29
  unsigned __int8 *changed; // r28
  idBitMsg *v19; // r3
  idBitMsg *v20; // r3
  unsigned int v21; // r9
  soundShaderFlags_t soundShaderFlags; // r29
  idBitMsg *v23; // r3
  int framesToForceKeep; // r11

  channel = this->channel;
  msg = ser->msg;
  v6 = _cntlzw(0x59u);
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: channel, numBits: 32 - v6);
  else
    channel = idBitMsg::ReadBits(this: msg, numBits: 32 - v6);
  this->channel = channel;
  idSerializer::Serialize<idSoundShader>(this: ser, decl: &this->shader);
  v7 = ser->msg;
  v8 = _cntlzw(1u);
  internalFlags = this->internalFlags;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v7, value: this->internalFlags, numBits: 32 - v8);
  else
    internalFlags = idBitMsg::ReadBits(this: v7, numBits: 32 - v8);
  this->internalFlags = internalFlags;
  p_position = &this->position;
  v11 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteQuantizedVector<idVec3,32768,11>(this: v11, v: p_position);
  else
    idBitMsg::ReadQuantizedVector<idVec3,32768,11>(this: v11, v: p_position);
  idSerializer::SerializeQ<60,8>(this: ser, value: &this->volume);
  idSerializer::SerializeQ<60,8>(this: ser, value: &this->pitch);
  idSerializer::SerializeQ<60,8>(this: ser, value: &this->soundFadeTo);
  v12 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v12, value: COERCE_INT(this->soundFadeTime), numBits: 32);
  else
    LODWORD(this->soundFadeTime) = idBitMsg::ReadBits(this: v12, numBits: 32);
  idSerializer::SerializeQ<60,8>(this: ser, value: &this->volumeAdjustment);
  v13 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v13, value: this->presentableIndex, numBits: 16);
  else
    this->presentableIndex = idBitMsg::ReadBits(this: v13, numBits: 16);
  v14 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v14, value: this->peerMask, numBits: 8);
  else
    this->peerMask = idBitMsg::ReadBits(this: v14, numBits: 8);
  clearVolumeAdjustment = this->clearVolumeAdjustment;
  v16 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v16, value: this->clearVolumeAdjustment, numBits: 1);
  else
    clearVolumeAdjustment = (_cntlzw(idBitMsg::ReadBits(this: v16, numBits: 1) - 1) & 0x20) != 0;
  this->clearVolumeAdjustment = clearVolumeAdjustment;
  v17 = 0;
  changed = this->changed;
  do
  {
    v19 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v19, value: changed[v17], numBits: 8);
    else
      changed[v17] = idBitMsg::ReadBits(this: v19, numBits: 8);
    ++v17;
  }
  while ( v17 < 7 );
  idSerializer::SerializeQ<32768,11>(this: ser, value: &this->parms.minDistance);
  idSerializer::SerializeQ<32768,11>(this: ser, value: &this->parms.maxDistance);
  idSerializer::SerializeQ<32768,11>(this: ser, value: &this->parms.distanceFactor);
  idSerializer::SerializeQ<60,8>(this: ser, value: &this->parms.volume.min);
  idSerializer::SerializeQ<60,8>(this: ser, value: &this->parms.volume.max);
  idSerializer::SerializeQ<1,8>(this: ser, value: &this->parms.volume.granularity);
  idSerializer::SerializeQ<64,8>(this: ser, value: &this->parms.pitch.min);
  idSerializer::SerializeQ<64,8>(this: ser, value: &this->parms.pitch.max);
  idSerializer::SerializeQ<1,8>(this: ser, value: &this->parms.pitch.granularity);
  v20 = ser->msg;
  v21 = _cntlzw(0x1FFFFu);
  soundShaderFlags = this->parms.soundShaderFlags;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v20, value: this->parms.soundShaderFlags, numBits: 32 - v21);
  else
    soundShaderFlags = idBitMsg::ReadBits(this: v20, numBits: 32 - v21);
  this->parms.soundShaderFlags = soundShaderFlags;
  v23 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v23, value: COERCE_INT(this->parms.shakes), numBits: 32);
  else
    LODWORD(this->parms.shakes) = idBitMsg::ReadBits(this: v23, numBits: 32);
  framesToForceKeep = this->framesToForceKeep;
  if ( framesToForceKeep > 0 )
    this->framesToForceKeep = framesToForceKeep - 1;
  NumSoundsCreatedPerFrame_2 = 0;
}

