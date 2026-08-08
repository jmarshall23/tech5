
// ========================================================================
// ?CanMute@idSoundChannel@@QBA_NXZ
// EA  : 0x8298A9B0
// RVA : 0x0098A9B0
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

BOOL __fastcall idSoundChannel::CanMute(idSoundChannel *this)
{
  return (_cntlzw(this->parms.groups & 0x1F00000) & 0x20) != 0;
}


// ========================================================================
// ?Mute@idSoundChannel@@QAAXXZ
// EA  : 0x8298A9C8
// RVA : 0x0098A9C8
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

void __fastcall idSoundChannel::Mute(idSoundChannel *this)
{
  idSoundVoice *hardwareVoice; // r4

  hardwareVoice = this->hardwareVoice;
  if ( hardwareVoice != nullptr )
  {
    idSoundSystemLocal::FreeVoice(this: &soundSystemLocal, voice: hardwareVoice);
    this->hardwareVoice = nullptr;
  }
}


// ========================================================================
// ?IsLooping@idSoundChannel@@QBA_NXZ
// EA  : 0x8298AA10
// RVA : 0x0098AA10
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

BOOL __fastcall idSoundChannel::IsLooping(idSoundChannel *this)
{
  soundShaderFlags_t soundShaderFlags; // r11
  int v2; // r11
  bool v3; // zf

  soundShaderFlags = this->parms.soundShaderFlags;
  if ( (soundShaderFlags & 0x200) != 0 || (v3 = (soundShaderFlags & 0x100000) == 0, v2 = 0, !v3) )
    v2 = 1;
  return v2 != 0;
}


// ========================================================================
// ?CheckForCompletion@idSoundChannel@@QAA_NH@Z
// EA  : 0x8298AA40
// RVA : 0x0098AA40
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

int __fastcall idSoundChannel::CheckForCompletion(idSoundChannel *this, int currentTime)
{
  int result; // r3
  int endTime; // r11

  if ( this->sample == nullptr )
    return 1;
  endTime = this->endTime;
  if ( endTime <= 0 )
    return 0;
  result = 1;
  if ( endTime >= currentTime )
    return 0;
  return result;
}


// ========================================================================
// ?SetSilent@idSoundChannel@@QAAXXZ
// EA  : 0x8298AA78
// RVA : 0x0098AA78
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

void __fastcall idSoundChannel::SetSilent(idSoundChannel *this)
{
  this->volumeDB = -60.0;
  this->voiceVolumeOffsetDB = 0.0;
  this->dryVolumeDB = -60.0;
  this->wetVolumeDB = -60.0;
}


// ========================================================================
// ?UpdateVolume@idSoundChannel@@QAAXPAUlistener_t@@HAAM@Z
// EA  : 0x8298ABE0
// RVA : 0x0098ABE0
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

void __fastcall idSoundChannel::UpdateVolume(
        idSoundChannel *this,
        listener_t *listener,
        int currentTime,
        float *maxDBForHDR)
{
  idSoundEmitterLocal *emitter; // r9
  idSoundSample *sample; // r10
  idSoundWorldLocal *soundWorld; // r23
  int endTime; // r11
  soundChannel_t logicalChannel; // r11
  int id; // r11
  soundShaderFlags_t soundShaderFlags; // r10
  bool v15; // r21
  double randomVolume; // fp31
  double v17; // fp31
  double v18; // fp31
  bool v19; // r4
  double v20; // fp31
  unsigned int v21; // r27
  int v22; // r24
  idSoundFade *ptr; // r25
  idSoundWorldLocal::idDuckLayer *list; // r28
  int v25; // r30
  int num; // r29
  idSoundWorldLocal::idDuckLayer *v27; // r3
  char v28; // r11
  soundShaderGroups_t groups; // r11
  double v30; // fp30
  idCVar *v31; // r10
  soundShaderFlags_t v32; // r10
  BOOL v33; // r30
  idSoundEmitterLocal *v34; // r29
  double v35; // fp7
  double v36; // fp6
  long double v37; // fp2
  double v38; // fp1
  double v39; // fp0
  double v40; // fp12
  double v41; // fp29
  double v42; // fp13
  double v43; // fp0
  double occludedDistance; // fp11
  const idDeclTable *falloff; // r11
  double v46; // fp1
  double v47; // fp0
  double v48; // fp13
  double v49; // fp12
  const idDeclTable *wetFalloff; // r11
  double RoomGain; // fp31
  int areaNum; // r10
  __int16 environment; // r10
  int v54; // r5
  idSoundVoice *hardwareVoice; // r3
  bool v60; // r4
  long double v61; // fp2
  double v62; // fp30
  idSoundEmitterLocal *v63; // r11
  double minShakeDistance; // fp0
  double maxShakeDistance; // fp12
  double v66; // fp13
  const idDeclTable *shakeFalloff; // r11
  idVec3 v70; // [sp+50h] [-B0h] BYREF

  emitter = this->emitter;
  sample = this->sample;
  soundWorld = this->emitter->soundWorld;
  this->volumeDB = -60.0;
  this->voiceVolumeOffsetDB = 0.0;
  this->dryVolumeDB = -60.0;
  this->wetVolumeDB = -60.0;
  this->currentAmplitude = 0.0;
  this->currentShakeAmplitude = 0.0;
  if ( sample != nullptr && this->startTime <= currentTime )
  {
    endTime = this->endTime;
    if ( (endTime <= 0 || endTime >= currentTime)
      && listener->valid
      && !soundSystemLocal.muted
      && soundWorld == soundSystemLocal.currentSoundWorld
      && (sample->timestamp != -1 || s_playDefaultSound.valueInteger != 0)
      && (s_playMusic.valueInteger != 0
       || (logicalChannel = this->logicalChannel) != SND_CHANNEL_MUSIC1
       && logicalChannel != SND_CHANNEL_MUSIC2
       && logicalChannel != SND_CHANNEL_MUSIC3) )
    {
      id = listener->id;
      soundShaderFlags = this->parms.soundShaderFlags;
      v15 = (_cntlzw(id - emitter->emitterId) & 0x20) != 0;
      if ( ((soundShaderFlags & 1) == 0 || v15 || id == -1) && ((soundShaderFlags & 2) == 0 || !v15 || id == -1) )
      {
        randomVolume = this->randomVolume;
        v17 = (float)(idSoundFade::GetVolume(this: &this->volumeFade, soundTime: currentTime) + (float)randomVolume);
        v18 = (float)(idSoundFade::GetVolume(this: &soundWorld->volumeFade, soundTime: currentTime) + (float)v17);
        v20 = (float)(idSoundFade::GetVolume(this: &soundWorld->pauseFade, soundTime: currentTime) + (float)v18);
        if ( this->parms.groups != SSG_MASTER )
        {
          v21 = 0;
          v22 = 1;
          ptr = soundWorld->groupFade.ptr;
          do
          {
            if ( (v22 & this->parms.groups) != 0 )
            {
              v20 = (float)(idSoundFade::GetVolume(this: ptr, soundTime: currentTime) + (float)v20);
              if ( soundWorld->ducks.num > 0 )
              {
                list = soundWorld->ducks.list;
                v25 = 0;
                num = soundWorld->ducks.num;
                do
                {
                  v27 = &list[v25];
                  if ( list[v25].endFadeStart < 0 || (v28 = 1, currentTime < v27->endFadeEnd) )
                    v28 = 0;
                  if ( v28 == 0 )
                    v20 = (float)(idSoundWorldLocal::idDuckLayer::GetVolume(this: v27, g: v21, currentTime) + (float)v20);
                  --num;
                  ++v25;
                }
                while ( num != 0 );
              }
            }
            ++v21;
            ++ptr;
            v22 *= 2;
          }
          while ( v21 < 0x19 );
        }
        groups = this->parms.groups;
        if ( (groups & 6) != 0 )
        {
          v30 = (float)(s_volume_music.valueFloat + (float)v20);
          if ( soundSystemLocal.musicMuted )
            v30 = -60.0;
        }
        else
        {
          if ( (groups & 0x1F00000) != 0 )
            v31 = &s_volume_vo;
          else
            v31 = &s_volume_ambient;
          v30 = (float)(v31->valueFloat + (float)v20);
        }
        v32 = this->parms.soundShaderFlags;
        v33 = (v32 & 8) != 0;
        if ( (v32 & 8) == 0 && !v15 && (v32 & 0x100) != 0 && v30 > this->parms.coneAttenuation.outerVolume )
        {
          v34 = this->emitter;
          v35 = (float)(listener->pos.y - this->emitter->origin.y);
          v36 = (float)(listener->pos.z - this->emitter->origin.z);
          v70.x = listener->pos.x - this->emitter->origin.x;
          v70.y = v35;
          v70.z = v36;
          idVec3::NormalizeFast(this: &v70);
          *((double *)&v37 + 1) = v70.y;
          *(double *)&v37 = (float)((float)(v34->axis.mat[0].x * v70.x)
                                  + (float)((float)(v34->axis.mat[0].z * v70.z) + (float)(v34->axis.mat[0].y * v70.y)));
          v38 = idMath::ACos(a: v37);
          if ( v38 > (float)(this->parms.coneAttenuation.innerAngle * idMath::M_DEG2RAD) )
          {
            if ( v38 < (float)(this->parms.coneAttenuation.outerAngle * idMath::M_DEG2RAD) )
              v39 = (float)((float)((float)v38 - (float)(this->parms.coneAttenuation.innerAngle * idMath::M_DEG2RAD))
                          / (float)((float)(this->parms.coneAttenuation.outerAngle * idMath::M_DEG2RAD)
                                  - (float)(this->parms.coneAttenuation.innerAngle * idMath::M_DEG2RAD)));
            else
              v39 = 1.0;
          }
          else
          {
            v39 = 0.0;
          }
          v30 = (float)((float)((float)(this->parms.coneAttenuation.outerVolume - (float)v30) * (float)v39) + (float)v30);
        }
        v40 = 0.0;
        v41 = (float)(this->parms.wetVolume + (float)v30);
        if ( !v33 && !v15 )
        {
          v42 = (float)(this->parms.distanceFactor * this->parms.maxDistance);
          v43 = (float)(this->parms.distanceFactor * this->parms.minDistance);
          occludedDistance = this->emitter->occludedDistance;
          if ( occludedDistance <= v42 )
          {
            if ( occludedDistance > v43 && v42 > v43 )
              v40 = (float)((float)(this->emitter->occludedDistance - (float)v43)
                          / (float)((float)(this->parms.distanceFactor * this->parms.maxDistance) - (float)v43));
          }
          else
          {
            v40 = 1.0;
          }
          falloff = this->parms.falloff;
          if ( falloff != nullptr )
            v40 = (float)((float)1.0
                        - idLookupTable::TableLookupNormalized(this: falloff->table, time: v40, fastSearch: v19));
          v46 = 0.0;
          v47 = this->emitter->occludedDistance;
          v48 = (float)((float)(this->parms.wetMaxDistanceOffset + this->parms.maxDistance) * this->parms.distanceFactor);
          v30 = (float)((float)((float)(-60.0 - (float)v30) * (float)v40) + (float)v30);
          v49 = (float)((float)(this->parms.wetMinDistanceOffset + this->parms.minDistance) * this->parms.distanceFactor);
          if ( v47 <= v48 )
          {
            if ( v47 > v49 && v48 > v49 )
              v46 = (float)((float)(this->emitter->occludedDistance
                                  - (float)((float)(this->parms.wetMinDistanceOffset + this->parms.minDistance)
                                          * this->parms.distanceFactor))
                          / (float)((float)((float)(this->parms.wetMaxDistanceOffset + this->parms.maxDistance)
                                          * this->parms.distanceFactor)
                                  - (float)((float)(this->parms.wetMinDistanceOffset + this->parms.minDistance)
                                          * this->parms.distanceFactor)));
          }
          else
          {
            v46 = 1.0;
          }
          wetFalloff = this->parms.wetFalloff;
          if ( wetFalloff != nullptr || (wetFalloff = this->parms.falloff) != nullptr )
            v46 = (float)((float)1.0
                        - idLookupTable::TableLookupNormalized(this: wetFalloff->table, time: v46, fastSearch: v19));
          v41 = (float)((float)((float)(-60.0 - (float)v41) * (float)v46) + (float)v41);
        }
        RoomGain = 0.0;
        areaNum = this->emitter->areaNum;
        if ( areaNum != -1 )
        {
          environment = soundWorld->sbspFile.areas.list[areaNum].environment;
          if ( environment >= 0 )
          {
            v54 = soundWorld->environments.num;
            if ( environment >= v54 )
              idLib::Warning(
                fmt: "idSoundChannel::UpdateHardware invalid envNum %d from sbsp (max %d)",
                environment,
                v54);
            else
              RoomGain = soundWorld->environments.list[environment].RoomGain;
          }
        }
        hardwareVoice = this->hardwareVoice;
        _FP13 = (float)((float)v30 - (float)v41);
        _FP12 = (float)((float)v30 - (float)((float)RoomGain + (float)v41));
        __asm
        {
          fsel      f11, f13, f30, f29
          fsel      f31, f12, f30, f0
        }
        this->volumeDB = _FP31;
        this->dryVolumeDB = (float)v30 - (float)_FP11;
        this->wetVolumeDB = (float)v41 - (float)_FP11;
        this->voiceVolumeOffsetDB = (float)_FP11 - (float)_FP31;
        if ( hardwareVoice != nullptr )
        {
          *(double *)&v61 = idSoundVoice_XAudio2::GetAmplitude(this: hardwareVoice);
          v62 = *(double *)&v61;
          if ( *(double *)&v61 > 0.0 )
            _FP31 = (float)(LinearToDB(linear: v61) + (float)_FP31);
          else
            _FP31 = -60.0;
          v63 = this->emitter;
          minShakeDistance = this->parms.minShakeDistance;
          this->currentAmplitude = v62;
          maxShakeDistance = this->parms.maxShakeDistance;
          v66 = v63->occludedDistance;
          if ( v66 > minShakeDistance )
          {
            if ( v66 < maxShakeDistance )
            {
              if ( v66 > minShakeDistance && maxShakeDistance > minShakeDistance )
                this->currentShakeAmplitude = (float)1.0
                                            - (float)((float)(v63->occludedDistance - (float)minShakeDistance)
                                                    / (float)(this->parms.maxShakeDistance - (float)minShakeDistance));
            }
            else
            {
              this->currentShakeAmplitude = 0.0;
            }
          }
          else
          {
            this->currentShakeAmplitude = 1.0;
          }
          shakeFalloff = this->parms.shakeFalloff;
          if ( shakeFalloff != nullptr )
            this->currentShakeAmplitude = idLookupTable::TableLookupNormalized(
                                            this: shakeFalloff->table,
                                            time: this->currentShakeAmplitude,
                                            fastSearch: v60);
        }
        if ( s_skipHDR.valueInteger != 0 || (this->parms.soundShaderFlags & 0x200000) == 0 )
        {
          _FP13 = (float)(*maxDBForHDR - (float)_FP31);
          __asm { fsel      f12, f13, f0, f31 }
          *maxDBForHDR = _FP12;
        }
      }
    }
  }
}


// ========================================================================
// ?GetCurrentSampleTime@idSoundChannel@@QBA?AV?$idTypesafeNumber@HW4millisecondUnique_t@@@@XZ
// EA  : 0x8298B218
// RVA : 0x0098B218
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

idSoundChannel *__fastcall idSoundChannel::GetCurrentSampleTime(
        idSoundChannel *this,
        idTypesafeNumber<int,enum millisecondUnique_t> *result)
{
  int v3; // r3

  v3 = *(_DWORD *)(result->value + 4);
  if ( v3 != 0 )
    this->emitter = (idSoundEmitterLocal *)((*(int (__fastcall **)(int))(*(_DWORD *)v3 + 112))(a1: v3) - result[1].value);
  else
    this->emitter = nullptr;
  return this;
}


// ========================================================================
// ??0idSoundChannel@@AAA@XZ
// EA  : 0x8298B290
// RVA : 0x0098B290
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

idSoundChannel *__fastcall idSoundChannel::idSoundChannel(idSoundChannel *this)
{
  soundShaderParms_t *p_parms; // r28

  p_parms = &this->parms;
  soundShaderParms_t::Clear(this: &this->parms);
  idSoundFade::Clear(this: &this->volumeFade);
  idSoundFade::Clear(this: &this->pitchFade);
  this->channelNode.head = &this->channelNode;
  this->channelNode.owner = nullptr;
  this->channelNode.next = &this->channelNode;
  this->channelNode.prev = &this->channelNode;
  this->emitter = nullptr;
  this->hardwareVoice = nullptr;
  this->startTime = 0;
  this->endTime = 0;
  soundShaderParms_t::Clear(this: p_parms);
  this->sample = nullptr;
  this->logicalChannel = SND_CHANNEL_ANY;
  this->soundShader = nullptr;
  idSoundFade::Clear(this: &this->volumeFade);
  idSoundFade::Clear(this: &this->pitchFade);
  this->channelNode.owner = this;
  this->randomVolume = 0.0;
  this->randomPitch = 0.0;
  this->dopplerPitch = 0.0;
  this->volumeDB = 0.0;
  this->voiceVolumeOffsetDB = 0.0;
  this->dryVolumeDB = 0.0;
  this->wetVolumeDB = 0.0;
  this->currentAmplitude = 0.0;
  this->currentShakeAmplitude = 0.0;
  return this;
}


// ========================================================================
// __unwind$224759
// EA  : 0x8298B360
// RVA : 0x0098B360
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

void _unwind_224759()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                           + 232));
}


// ========================================================================
// ??1idSoundChannel@@AAA@XZ
// EA  : 0x8298B398
// RVA : 0x0098B398
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

void __fastcall idSoundChannel::~idSoundChannel(idSoundChannel *this)
{
  idSoundVoice *hardwareVoice; // r4

  hardwareVoice = this->hardwareVoice;
  if ( hardwareVoice != nullptr )
  {
    idSoundSystemLocal::FreeVoice(this: &soundSystemLocal, voice: hardwareVoice);
    this->hardwareVoice = nullptr;
  }
  this->channelNode.prev->next = this->channelNode.next;
  this->channelNode.next->prev = this->channelNode.prev;
  this->channelNode.next = &this->channelNode;
  this->channelNode.prev = &this->channelNode;
  this->channelNode.head = &this->channelNode;
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->channelNode);
}


// ========================================================================
// __unwind$224797
// EA  : 0x8298B420
// RVA : 0x0098B420
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

void _unwind_224797()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                           + 232));
}


// ========================================================================
// ?UpdateHardware@idSoundChannel@@QAAXMH@Z
// EA  : 0x8298B458
// RVA : 0x0098B458
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

void __fastcall idSoundChannel::UpdateHardware(idSoundChannel *this, double volumeAdd, int currentTime, int a4)
{
  idSoundEmitterLocal *emitter; // r3
  idSoundWorldLocal *soundWorld; // r28
  idSoundVoice *hardwareVoice; // r11
  int endTime; // r11
  const idVec3 *v11; // r3
  listener_t *BestListenerForEmitter; // r29
  long double v13; // fp4
  double currentVolume; // fp30
  int areaNum; // r10
  __int16 environment; // r10
  long double v17; // fp2
  long double v18; // fp4
  long double v19; // fp2
  double v20; // fp24
  long double v21; // fp2
  long double v22; // fp4
  long double v23; // fp2
  double v24; // fp0
  double v25; // fp22
  long double v26; // fp2
  long double v27; // fp2
  double v28; // fp0
  double v29; // fp26
  int v30; // r24
  char v31; // r23
  soundShaderFlags_t soundShaderFlags; // r11
  bool v33; // r25
  bool v34; // r28
  bool v35; // r27
  idSoundEmitterLocal *v36; // r10
  double occlusion; // fp27
  long double v40; // fp2
  long double v41; // fp4
  long double v42; // fp4
  long double v43; // fp2
  double v44; // fp30
  double valueFloat; // fp28
  idGame *v46; // r3
  idGameTimeManager *v47; // r3
  idSoundSample *sample; // r11
  soundShaderFlags_t v49; // r9
  unsigned int channelMask; // r26
  int numChannels; // r11
  idSoundVoice *v52; // r11
  idSoundVoice *v53; // r11
  double z; // fp0
  idSoundVoice *v55; // r11
  float *v56; // r11
  double v57; // fp0
  double v58; // fp13
  double v59; // fp12
  double v60; // fp11
  double v61; // fp10
  double v62; // fp9
  double v63; // fp8
  double v64; // fp7
  float *v65; // r11
  float *v66; // r10
  idSoundEmitterLocal *v67; // r11
  idSoundVoice *v68; // r10
  float *v69; // r11
  double v70; // fp8
  double v71; // fp11
  double y; // fp10
  double v73; // fp9
  double v74; // fp7
  double v75; // fp6
  double x; // fp5
  float *p_axis; // r11
  float *v78; // r10
  idSoundEmitterLocal *v79; // r11
  idSoundVoice *v80; // r10
  long double v81; // fp2
  long double v82; // fp2
  idSoundVoice *v83; // r8
  idSoundVoice *v86; // r3
  int v87; // r11
  int num; // [sp+50h] [-C0h]
  idList<idDeclVehicleUpgrade const *,5> v89[6]; // [sp+60h] [-B0h] BYREF

  emitter = this->emitter;
  soundWorld = emitter->soundWorld;
  if ( soundWorld != nullptr )
  {
    hardwareVoice = this->hardwareVoice;
    if ( hardwareVoice != nullptr )
      this->sample = (idSoundSample *)hardwareVoice->sample;
    if ( this->sample != nullptr && this->startTime <= a4 )
    {
      endTime = this->endTime;
      if ( endTime <= 0 || endTime >= a4 )
      {
        v11 = emitter->GetPosition(this: emitter);
        BestListenerForEmitter = idSoundWorldLocal::GetBestListenerForEmitter(
                                   this: soundWorld,
                                   emitterId: this->emitter->emitterId,
                                   emitterOrigin: v11);
        currentVolume = 1.0;
        if ( (this->parms.soundShaderFlags & 0x80) != 0 )
        {
          areaNum = this->emitter->areaNum;
          if ( areaNum != -1 )
          {
            environment = soundWorld->sbspFile.areas.list[areaNum].environment;
            if ( environment >= 0 )
            {
              num = soundWorld->environments.num;
              if ( environment >= num )
                idLib::Warning(
                  fmt: "idSoundChannel::UpdateHardware invalid envNum %d from sbsp (max %d)",
                  environment,
                  num);
              else
                currentVolume = soundWorld->environments.list[environment].currentVolume;
            }
          }
        }
        *(double *)&v17 = 2.0;
        *((double *)&v17 + 1) = (float)((float)((float)(this->voiceVolumeOffsetDB + this->volumeDB) + (float)volumeAdd)
                                      * (float)0.16666667);
        v19 = pow(x: v17, y: v13);
        v20 = (float)((float)*(double *)&v19 * (float)currentVolume);
        if ( v20 >= 0.0 )
        {
          if ( v20 > 1.0 )
            v20 = 1.0;
        }
        else
        {
          v20 = 0.0;
        }
        *(double *)&v21 = 2.0;
        *((double *)&v21 + 1) = (float)(this->dryVolumeDB * (float)0.16666667);
        v23 = pow(x: v21, y: v18);
        v24 = (float)*(double *)&v23;
        if ( v24 >= 0.0 )
        {
          if ( v24 <= 1.0 )
            v25 = (float)*(double *)&v23;
          else
            v25 = 1.0;
        }
        else
        {
          v25 = 0.0;
        }
        *(double *)&v26 = 2.0;
        *((double *)&v26 + 1) = (float)(this->wetVolumeDB * (float)0.16666667);
        v27 = pow(x: v26, y: v22);
        v28 = (float)*(double *)&v27;
        if ( v28 >= 0.0 )
        {
          if ( v28 <= 1.0 )
            v29 = (float)*(double *)&v27;
          else
            v29 = 1.0;
        }
        else
        {
          v29 = 0.0;
        }
        v30 = 0;
        v31 = 0;
        soundShaderFlags = this->parms.soundShaderFlags;
        v33 = (soundShaderFlags & 8) != 0;
        v34 = (soundShaderFlags & 0x10) != 0;
        v35 = (_cntlzw(BestListenerForEmitter->id - this->emitter->emitterId) & 0x20) != 0;
        if ( this->hardwareVoice != nullptr )
        {
LABEL_36:
          v36 = this->emitter;
          occlusion = this->emitter->occlusion;
          if ( this->parms.lowPassStrength > 0.0
            && s_useDistanceLowPass.valueInteger != 0
            && v36->occludedDistance > (double)(float)(this->parms.distanceFactor * this->parms.lowPassMinDistance) )
          {
            _FP11 = this->parms.wetMaxDistanceOffset;
            __asm { fsel      f10, f11, f11, f31 }
            occlusion = (float)((float)((float)((float)-(float)((float)(this->parms.distanceFactor
                                                                      * this->parms.lowPassMinDistance)
                                                              - v36->occludedDistance)
                                              * this->parms.lowPassStrength)
                                      / (float)((float)((float)_FP10 + this->parms.maxDistance)
                                              * this->parms.distanceFactor))
                              + this->emitter->occlusion);
          }
          *((double *)&v40 + 1) = (float)((float)((float)(idSoundFade::GetVolume(this: &this->pitchFade, soundTime: a4)
                                                        + this->dopplerPitch)
                                                + this->randomPitch)
                                        * (float)0.083333336);
          *(double *)&v40 = 2.0;
          v43 = pow(x: v40, y: v41);
          v44 = (float)*(double *)&v43;
          if ( v44 <= 4.0 )
          {
            if ( v44 <= 0.0 )
              v44 = 1.0;
          }
          else
          {
            v44 = 4.0;
          }
          valueFloat = com_timescale.valueFloat;
          if ( (this->parms.groups & 0x600005) != 0 )
          {
            v46 = common->Game(this: common);
            v47 = v46->GetGameTimeManager(this: v46);
            valueFloat = (float)(idGameTimeManager::GetTimeScale(this: v47, type: GAMETIME_SCALED) * (float)valueFloat);
          }
          sample = this->sample;
          v49 = this->parms.soundShaderFlags;
          channelMask = sample->channelMask;
          if ( (v49 & 0x40000) != 0 )
          {
            numChannels = sample->format.basic.numChannels;
            if ( numChannels == 1 )
            {
              channelMask = 8;
            }
            else if ( numChannels == 2 )
            {
              channelMask = 12;
            }
          }
          if ( !v34 && !v35 && (channelMask & ~(channelMask & 8)) == 3 )
            channelMask = channelMask & 8 | 0x600;
          if ( (v49 & 0x20) != 0 )
          {
            v52 = this->hardwareVoice;
            v52->position.x = 1.0;
            v52->position.y = 0.0;
            v52->position.z = 0.0;
            this->hardwareVoice->invListenerAxis = mat3_identity;
            this->hardwareVoice->axis = mat3_identity;
            v53 = this->hardwareVoice;
            v53->velocity.x = vec3_origin.x;
            v53->velocity.y = vec3_origin.y;
            z = vec3_origin.z;
          }
          else if ( (v49 & 0x40) != 0 )
          {
            v55 = this->hardwareVoice;
            v55->position.z = 0.0;
            v55->position.x = -1.0;
            v55->position.y = 0.0;
            this->hardwareVoice->invListenerAxis = mat3_identity;
            this->hardwareVoice->axis = mat3_identity;
            v53 = this->hardwareVoice;
            v53->velocity.x = vec3_origin.x;
            v53->velocity.y = vec3_origin.y;
            z = vec3_origin.z;
          }
          else if ( v34 || v35 )
          {
            this->hardwareVoice->position = vec3_origin;
            this->hardwareVoice->invListenerAxis = mat3_identity;
            this->hardwareVoice->axis = mat3_identity;
            v53 = this->hardwareVoice;
            v53->velocity.x = vec3_origin.x;
            v53->velocity.y = vec3_origin.y;
            z = vec3_origin.z;
          }
          else
          {
            if ( !v33 )
            {
              v67 = this->emitter;
              v68 = this->hardwareVoice;
              v68->position.x = this->emitter->occludedDirection.x;
              v68->position.y = v67->occludedDirection.y;
              v68->position.z = v67->occludedDirection.z;
              v69 = (float *)this->hardwareVoice;
              v70 = BestListenerForEmitter->axis.mat[1].z;
              v71 = BestListenerForEmitter->axis.mat[0].z;
              y = BestListenerForEmitter->axis.mat[2].y;
              v73 = BestListenerForEmitter->axis.mat[2].z;
              v74 = BestListenerForEmitter->axis.mat[1].y;
              v75 = BestListenerForEmitter->axis.mat[0].y;
              x = BestListenerForEmitter->axis.mat[2].x;
              *((double *)&v42 + 1) = BestListenerForEmitter->axis.mat[1].x;
              *(double *)&v42 = BestListenerForEmitter->axis.mat[0].x;
              *v69 = BestListenerForEmitter->axis.mat[0].x;
              v69[3] = v75;
              v69[1] = *((double *)&v42 + 1);
              v69[2] = x;
              v69[4] = v74;
              v69[5] = y;
              v69[6] = v71;
              v69[7] = v70;
              v69[8] = v73;
              p_axis = (float *)&this->emitter->axis;
              v78 = (float *)&this->hardwareVoice->axis;
              *v78 = *p_axis;
              v78[1] = p_axis[1];
              v78[2] = p_axis[2];
              v78[3] = p_axis[3];
              v78[4] = p_axis[4];
              v78[5] = p_axis[5];
              v78[6] = p_axis[6];
              v78[7] = p_axis[7];
              v78[8] = p_axis[8];
              v79 = this->emitter;
              v80 = this->hardwareVoice;
              v80->velocity.x = this->emitter->velocity.x;
              v80->velocity.y = v79->velocity.y;
              v80->velocity.z = v79->velocity.z;
              goto LABEL_66;
            }
            this->hardwareVoice->position = vec3_origin;
            v56 = (float *)this->hardwareVoice;
            v57 = BestListenerForEmitter->axis.mat[1].z;
            v58 = BestListenerForEmitter->axis.mat[0].y;
            v59 = BestListenerForEmitter->axis.mat[2].x;
            v60 = BestListenerForEmitter->axis.mat[2].y;
            v61 = BestListenerForEmitter->axis.mat[2].z;
            v62 = BestListenerForEmitter->axis.mat[0].z;
            v63 = BestListenerForEmitter->axis.mat[1].y;
            v64 = BestListenerForEmitter->axis.mat[1].x;
            *v56 = BestListenerForEmitter->axis.mat[0].x;
            v56[3] = v58;
            v56[1] = v64;
            v56[2] = v59;
            v56[4] = v63;
            v56[5] = v60;
            v56[6] = v62;
            v56[7] = v57;
            v56[8] = v61;
            v65 = (float *)&this->emitter->axis;
            v66 = (float *)&this->hardwareVoice->axis;
            *v66 = *v65;
            *((double *)&v42 + 1) = v65[1];
            v66[1] = v65[1];
            *(double *)&v42 = v65[2];
            v66[2] = v65[2];
            v66[3] = v65[3];
            v66[4] = v65[4];
            v66[5] = v65[5];
            v66[6] = v65[6];
            v66[7] = v65[7];
            v66[8] = v65[8];
            v53 = this->hardwareVoice;
            v53->velocity.x = vec3_origin.x;
            v53->velocity.y = vec3_origin.y;
            z = vec3_origin.z;
          }
          v53->velocity.z = z;
LABEL_66:
          *(double *)&v81 = 2.0;
          this->hardwareVoice->gain = v20;
          *((double *)&v81 + 1) = (float)(this->parms.lfeVolume * (float)0.16666667);
          v82 = pow(x: v81, y: v42);
          this->hardwareVoice->gainLFE = (float)*(double *)&v82 * (float)v20;
          v83 = this->hardwareVoice;
          v83->dryGain = v25;
          v83->wetGain = v29;
          this->hardwareVoice->centerChannel = this->parms.centerChannel;
          this->hardwareVoice->channelMask = channelMask;
          this->hardwareVoice->pitch = (float)valueFloat * (float)v44;
          _FP8 = this->parms.wetMinDistanceOffset;
          __asm { fsel      f7, f8, f31, f8 }
          this->hardwareVoice->innerRadius = (float)((float)_FP7 + this->parms.minDistance) * this->parms.distanceFactor;
          v86 = this->hardwareVoice;
          *(double *)&v82 = (float)(this->parms.distanceBasedRanges.farMaxRange
                                  * this->parms.distanceBasedRanges.farMaxRange);
          v86->innerSampleRangeSqr = this->parms.distanceBasedRanges.nearMinRange
                                   * this->parms.distanceBasedRanges.nearMinRange;
          v86->outerSampleRangeSqr = *(double *)&v82;
          this->hardwareVoice->occlusion = occlusion;
          if ( v31 != 0 )
          {
            v87 = 0x4000;
            if ( this->parms.shakes <= 0.0 )
              v87 = 0;
            idSoundVoice_XAudio2::Start(
              this: this->hardwareVoice,
              offsetMS: v30,
              ssFlags: v87 | this->parms.soundShaderFlags);
          }
          else
          {
            idSoundVoice_XAudio2::Update(this: this->hardwareVoice);
          }
          return;
        }
        if ( (soundShaderFlags & 0x100000) != 0 )
        {
          this->hardwareVoice = idSoundSystemLocal::AllocateVoice(
                                  this: &soundSystemLocal,
                                  sample: this->sample,
                                  samples: (const idList<idSoundSample *,5> *)&this->soundShader->entries);
        }
        else
        {
          idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: v89);
          this->hardwareVoice = idSoundSystemLocal::AllocateVoice(
                                  this: &soundSystemLocal,
                                  sample: this->sample,
                                  samples: (const idList<idSoundSample *,5> *)v89);
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v89);
        }
        if ( this->hardwareVoice != nullptr )
        {
          v31 = 1;
          if ( (this->parms.soundShaderFlags & 0x2000) != 0 )
            v30 = 0;
          else
            v30 = a4 - this->startTime;
          goto LABEL_36;
        }
      }
    }
  }
}


// ========================================================================
// __unwind$224834
// EA  : 0x8298BEB8
// RVA : 0x0098BEB8
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

void _unwind_224834()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 272 + 96));
}


// ========================================================================
// `dynamic initializer for 's_useDistanceLowPass''
// EA  : 0x83360110
// RVA : 0x01360110
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_useDistanceLowPass__()
{
  idCVar::idCVar(
    this: &s_useDistanceLowPass,
    name: "s_useDistanceLowPass",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_useDistanceLowPass__);
}


// ========================================================================
// `dynamic initializer for 's_playMusic''
// EA  : 0x83360168
// RVA : 0x01360168
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_playMusic__()
{
  idCVar::idCVar(
    this: &s_playMusic,
    name: "s_playMusic",
    value: "1",
    flags: 1,
    description: "temp cvar to kill music for gameplay captures",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_playMusic__);
}


// ========================================================================
// `dynamic initializer for 's_volume_music''
// EA  : 0x833601C0
// RVA : 0x013601C0
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_volume_music__()
{
  idCVar::idCVar(
    this: &s_volume_music,
    name: "s_volume_music",
    value: "0",
    flags: 0,
    description: "Music volume, in DB",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_volume_music__);
}


// ========================================================================
// `dynamic initializer for 's_volume_vo''
// EA  : 0x83360218
// RVA : 0x01360218
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_volume_vo__()
{
  idCVar::idCVar(
    this: &s_volume_vo,
    name: "s_volume_vo",
    value: "0",
    flags: 0,
    description: "VO volume, in DB",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_volume_vo__);
}


// ========================================================================
// `dynamic initializer for 's_volume_ambient''
// EA  : 0x83360270
// RVA : 0x01360270
// PDB : w:\tech5\engine\sound\soundchannel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_volume_ambient__()
{
  idCVar::idCVar(
    this: &s_volume_ambient,
    name: "s_volume_ambient",
    value: "0",
    flags: 0,
    description: "Ambient sounds volume, in DB",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_volume_ambient__);
}

