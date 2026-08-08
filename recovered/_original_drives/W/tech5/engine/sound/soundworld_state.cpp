
// ========================================================================
// ?SaveParms@@YAXPAVidFile@@ABUsoundShaderParms_t@@@Z
// EA  : 0x8299B740
// RVA : 0x0099B740
// PDB : w:\tech5\engine\sound\soundworld_state.cpp
// ========================================================================

void __fastcall SaveParms(idFile *fp, const soundShaderParms_t *parms)
{
  fp->Write(this: fp, a2: parms, a3: 4u);
  fp->Write(this: fp, a2: &parms->maxDistance, a3: 4u);
  fp->Write(this: fp, a2: &parms->distanceFactor, a3: 4u);
  fp->Write(this: fp, a2: &parms->wetMinDistanceOffset, a3: 4u);
  fp->Write(this: fp, a2: &parms->wetMaxDistanceOffset, a3: 4u);
  fp->Write(this: fp, a2: &parms->coneAttenuation, a3: 4u);
  fp->Write(this: fp, a2: &parms->coneAttenuation.outerAngle, a3: 4u);
  fp->Write(this: fp, a2: &parms->coneAttenuation.outerVolume, a3: 4u);
  fp->Write(this: fp, a2: &parms->volume, a3: 4u);
  fp->Write(this: fp, a2: &parms->volume.max, a3: 4u);
  fp->Write(this: fp, a2: &parms->volume.granularity, a3: 4u);
  fp->Write(this: fp, a2: &parms->wetVolume, a3: 4u);
  fp->Write(this: fp, a2: &parms->pitch, a3: 4u);
  fp->Write(this: fp, a2: &parms->pitch.max, a3: 4u);
  fp->Write(this: fp, a2: &parms->pitch.granularity, a3: 4u);
  fp->Write(this: fp, a2: &parms->loopFadeInDuration, a3: 4u);
  fp->Write(this: fp, a2: &parms->loopFadeOutDuration, a3: 4u);
  fp->Write(this: fp, a2: &parms->dopplerMultiplier, a3: 4u);
  fp->Write(this: fp, a2: &parms->shakes, a3: 4u);
  fp->Write(this: fp, a2: &parms->groups, a3: 4u);
  fp->Write(this: fp, a2: &parms->soundChannel, a3: 4u);
  fp->Write(this: fp, a2: &parms->soundShaderFlags, a3: 4u);
  fp->Write(this: fp, a2: &parms->lowPassMinDistance, a3: 4u);
  fp->Write(this: fp, a2: &parms->lowPassStrength, a3: 4u);
  fp->Write(this: fp, a2: &parms->lfeVolume, a3: 4u);
  fp->Write(this: fp, a2: &parms->centerChannel, a3: 4u);
  fp->Write(this: fp, a2: &parms->headroom, a3: 4u);
}


// ========================================================================
// ?LoadParms@@YA_NPAVidFile@@AAUsoundShaderParms_t@@@Z
// EA  : 0x8299BA60
// RVA : 0x0099BA60
// PDB : w:\tech5\engine\sound\soundworld_state.cpp
// ========================================================================

BOOL __fastcall LoadParms(idFile *fp, soundShaderParms_t *parms)
{
  return fp->Read(this: fp, a2: parms, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->maxDistance, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->distanceFactor, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->wetMinDistanceOffset, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->wetMaxDistanceOffset, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->coneAttenuation, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->coneAttenuation.outerAngle, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->coneAttenuation.outerVolume, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->volume, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->volume.max, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->volume.granularity, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->wetVolume, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->pitch, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->pitch.max, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->pitch.granularity, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->loopFadeInDuration, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->loopFadeOutDuration, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->dopplerMultiplier, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->shakes, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->groups, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->soundChannel, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->soundShaderFlags, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->lowPassMinDistance, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->lowPassStrength, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->lfeVolume, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->centerChannel, a3: 4u) != 0
      && fp->Read(this: fp, a2: &parms->headroom, a3: 4u) != 0;
}


// ========================================================================
// ?LoadFade@@YA_NPAVidFile@@AAVidSoundFade@@@Z
// EA  : 0x8299BE60
// RVA : 0x0099BE60
// PDB : w:\tech5\engine\sound\soundworld_state.cpp
// ========================================================================

BOOL __fastcall LoadFade(idFile *fp, idSoundFade *fade)
{
  return fp->Read(this: fp, a2: fade, a3: 4u) != 0
      && fp->Read(this: fp, a2: &fade->fadeEndTime, a3: 4u) != 0
      && fp->Read(this: fp, a2: &fade->fadeStartVolume, a3: 4u) != 0
      && fp->Read(this: fp, a2: &fade->fadeEndVolume, a3: 4u) != 0;
}


// ========================================================================
// ?SaveGame@idSoundWorldLocal@@UAAXPAVidFile@@@Z
// EA  : 0x8299BF28
// RVA : 0x0099BF28
// PDB : w:\tech5\engine\sound\soundworld_state.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::SaveGame(idSoundWorldLocal *this, idFile *fp)
{
  idFile_vtbl *v4; // r9
  idMat3 *p_axis; // r30
  int i; // r28
  idFile_vtbl *v7; // r10
  int v8; // r22
  int v9; // r23
  idSoundEmitterLocal *v10; // r27
  unsigned int (__fastcall *Write)(idFile *, const void *, unsigned int); // ctr
  idFile_vtbl *v12; // r8
  int v13; // r25
  int v14; // r26
  idSoundChannel *v15; // r30
  const idSoundShader *soundShader; // r11
  const char *str; // r4
  idSoundSample *sample; // r11
  const char *v19; // r4
  idSoundFade *p_pitchFade; // r30
  idFile_vtbl *v21; // r10
  int v22; // r28
  int v23; // r30
  bool v24[4]; // [sp+50h] [-80h] BYREF
  unsigned int BufferPointer; // [sp+54h] [-7Ch] BYREF
  int num; // [sp+58h] [-78h] BYREF
  int v27; // [sp+5Ch] [-74h] BYREF
  int v28; // [sp+60h] [-70h] BYREF

  BufferPointer = D3DXShader::CConstantTable::GetBufferPointer(this: (D3DXCore::CBuffer *)&soundSystemLocal);
  fp->Write(this: fp, a2: &BufferPointer, a3: 4u);
  fp->Write(this: fp, a2: &this->pausedTime, a3: 4u);
  fp->Write(this: fp, a2: &this->accumulatedPauseTime, a3: 4u);
  v4 = fp->__vftable;
  v24[0] = this->isPaused;
  v4->Write(this: fp, a2: v24, a3: 1u);
  p_axis = &this->listeners.ptr[0].axis;
  for ( i = 2; i != 0; --i )
  {
    fp->Write(this: fp, a2: &p_axis[-1].mat[2].z, a3: 1u);
    fp->Write(this: fp, a2: p_axis, a3: 36u);
    fp->Write(this: fp, a2: &p_axis[1], a3: 12u);
    fp->Write(this: fp, a2: &p_axis[1].mat[1], a3: 12u);
    fp->Write(this: fp, a2: &p_axis[1].mat[2], a3: 4u);
    fp->Write(this: fp, a2: &p_axis[1].mat[2].y, a3: 4u);
    p_axis = (idMat3 *)((char *)p_axis + 232);
  }
  v7 = fp->__vftable;
  num = this->emitters.num;
  v7->Write(this: fp, a2: &num, a3: 4u);
  v8 = 0;
  if ( this->emitters.num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = this->emitters.list[v9];
      Write = fp->Write;
      if ( v10->canFree )
      {
        Write(this: fp, a2: &vec3_infinity, a3: 12u);
      }
      else
      {
        Write(this: fp, a2: &v10->origin, a3: 12u);
        fp->Write(this: fp, a2: &v10->areaNum, a3: 4u);
        fp->Write(this: fp, a2: &v10->velocity, a3: 12u);
        fp->Write(this: fp, a2: &v10->emitterId, a3: 4u);
        fp->Write(this: fp, a2: &v10->occludedDistance, a3: 4u);
        fp->Write(this: fp, a2: &v10->occludedDirection, a3: 12u);
        fp->Write(this: fp, a2: &v10->occlusion, a3: 4u);
        v12 = fp->__vftable;
        v27 = v10->channels.num;
        v12->Write(this: fp, a2: &v27, a3: 4u);
        v13 = 0;
        if ( v10->channels.num > 0 )
        {
          v14 = 0;
          do
          {
            v15 = v10->channels.list[v14];
            fp->Write(this: fp, a2: &v15->startTime, a3: 4u);
            fp->Write(this: fp, a2: &v15->logicalChannel, a3: 4u);
            SaveParms(fp, parms: &v15->parms);
            soundShader = v15->soundShader;
            str = &byte_8200D768;
            if ( soundShader != nullptr )
              str = soundShader->name.str;
            idFile::WriteString(this: fp, string: str);
            sample = v15->sample;
            v19 = &byte_8200D768;
            if ( sample != nullptr )
              v19 = sample->name.str;
            idFile::WriteString(this: fp, string: v19);
            fp->Write(this: fp, a2: &v15->randomVolume, a3: 4u);
            fp->Write(this: fp, a2: &v15->randomPitch, a3: 4u);
            fp->Write(this: fp, a2: &v15->volumeFade, a3: 4u);
            fp->Write(this: fp, a2: &v15->volumeFade.fadeEndTime, a3: 4u);
            fp->Write(this: fp, a2: &v15->volumeFade.fadeStartVolume, a3: 4u);
            fp->Write(this: fp, a2: &v15->volumeFade.fadeEndVolume, a3: 4u);
            p_pitchFade = &v15->pitchFade;
            fp->Write(this: fp, a2: p_pitchFade, a3: 4u);
            fp->Write(this: fp, a2: &p_pitchFade->fadeEndTime, a3: 4u);
            fp->Write(this: fp, a2: &p_pitchFade->fadeStartVolume, a3: 4u);
            fp->Write(this: fp, a2: &p_pitchFade->fadeEndVolume, a3: 4u);
            ++v13;
            ++v14;
          }
          while ( v13 < v10->channels.num );
        }
      }
      ++v8;
      ++v9;
    }
    while ( v8 < this->emitters.num );
  }
  v21 = fp->__vftable;
  v28 = this->environments.num;
  v21->Write(this: fp, a2: &v28, a3: 4u);
  v22 = 0;
  if ( this->environments.num > 0 )
  {
    v23 = 0;
    do
    {
      fp->Write(this: fp, a2: &this->environments.list[v23], a3: 4u);
      fp->Write(this: fp, a2: &this->environments.list[v23].RoomGain, a3: 4u);
      fp->Write(this: fp, a2: &this->environments.list[v23].RoomHFGain, a3: 4u);
      fp->Write(this: fp, a2: &this->environments.list[v23].DecayTime, a3: 4u);
      fp->Write(this: fp, a2: &this->environments.list[v23].DecayHFTime, a3: 4u);
      fp->Write(this: fp, a2: &this->environments.list[v23].ReflectionsGain, a3: 4u);
      fp->Write(this: fp, a2: &this->environments.list[v23].ReflectionsDelay, a3: 4u);
      fp->Write(this: fp, a2: &this->environments.list[v23].ReverbGain, a3: 4u);
      fp->Write(this: fp, a2: &this->environments.list[v23].ReverbDelay, a3: 4u);
      fp->Write(this: fp, a2: &this->environments.list[v23].Diffusion, a3: 4u);
      fp->Write(this: fp, a2: &this->environments.list[v23].Density, a3: 4u);
      fp->Write(this: fp, a2: &this->environments.list[v23].HFReference, a3: 4u);
      ++v22;
      ++v23;
    }
    while ( v22 < this->environments.num );
  }
}


// ========================================================================
// ?LoadGame@idSoundWorldLocal@@UAA_NPAVidFile@@@Z
// EA  : 0x8299C5B8
// RVA : 0x0099C5B8
// PDB : w:\tech5\engine\sound\soundworld_state.cpp
// ========================================================================

int __fastcall idSoundWorldLocal::LoadGame(idSoundWorldLocal *this, idFile *fp)
{
  unsigned int BufferPointer; // r3
  int v5; // r29
  idFile_vtbl *v6; // r10
  unsigned int v7; // r28
  int v8; // r25
  int *p_accumulatedPauseTime; // r26
  int v10; // r24
  idMat3 *p_axis; // r28
  int v12; // r10
  idList<idSoundEmitterLocal *,38> *p_emitters; // r20
  int v14; // r22
  int v15; // r23
  idBlockAlloc<idSoundEmitterLocal,16,38>::element_t *v16; // r27
  char v17; // r11
  idFile_vtbl *v18; // r11
  unsigned int (__fastcall *Read)(idFile *, void *, unsigned int); // r9
  int v20; // r4
  int v21; // r25
  idBlockAlloc<idSoundChannel,16,38>::element_t *v22; // r28
  const idDecl *v23; // r3
  idList<soundEnvironment_t,38> *p_environments; // r28
  int v25; // r27
  int v27; // [sp+50h] [-F0h] BYREF
  int v28; // [sp+54h] [-ECh] BYREF
  int v29; // [sp+58h] [-E8h] BYREF
  int v30; // [sp+5Ch] [-E4h] BYREF
  int v31[2]; // [sp+60h] [-E0h] BYREF
  float v32[6]; // [sp+68h] [-D8h] BYREF
  idStr v33; // [sp+80h] [-C0h] BYREF
  idStr v34[5]; // [sp+A0h] [-A0h] BYREF

  BufferPointer = D3DXShader::CConstantTable::GetBufferPointer(this: (D3DXCore::CBuffer *)&soundSystemLocal);
  v5 = 0;
  v6 = fp->__vftable;
  v7 = BufferPointer;
  v28 = 0;
  if ( v6->Read(this: fp, a2: &v28, a3: 4u) != 0 )
  {
    v8 = v7 - v28;
    if ( fp->Read(this: fp, a2: &this->pausedTime, a3: 4u) != 0 )
    {
      p_accumulatedPauseTime = &this->accumulatedPauseTime;
      if ( fp->Read(this: fp, a2: &this->accumulatedPauseTime, a3: 4u) != 0
        && fp->Read(this: fp, a2: &this->isPaused, a3: 1u) != 0 )
      {
        v10 = 0;
        p_axis = &this->listeners.ptr[0].axis;
        v12 = *p_accumulatedPauseTime + v8;
        this->pausedTime += v8;
        *p_accumulatedPauseTime = v12;
        while ( fp->Read(this: fp, a2: &p_axis[-1].mat[2].z, a3: 1u) != 0
             && fp->Read(this: fp, a2: p_axis, a3: 36u) != 0
             && fp->Read(this: fp, a2: &p_axis[1], a3: 12u) != 0
             && fp->Read(this: fp, a2: &p_axis[1].mat[1], a3: 12u) != 0
             && fp->Read(this: fp, a2: &p_axis[1].mat[2], a3: 4u) != 0
             && fp->Read(this: fp, a2: &p_axis[1].mat[2].y, a3: 4u) != 0 )
        {
          ++v10;
          p_axis = (idMat3 *)((char *)p_axis + 232);
          if ( v10 >= 2 )
          {
            v29 = 0;
            if ( fp->Read(this: fp, a2: &v29, a3: 4u) == 0 )
              return 0;
            v31[0] = 0;
            p_emitters = &this->emitters;
            idList<idRenderModelCommitted *,5>::SetNum(
              this: (idList<int,5> *)&this->emitters,
              newNum: v29,
              initValue: v31);
            v14 = 0;
            if ( this->emitters.num <= 0 )
            {
LABEL_54:
              v30 = 0;
              if ( fp->Read(this: fp, a2: &v30, a3: 4u) == 0 )
                return 0;
              p_environments = &this->environments;
              idList<soundEnvironment_t,38>::SetNum(this: &this->environments, newNum: v30);
              v25 = 0;
              if ( this->environments.num <= 0 )
                return 1;
              while ( fp->Read(this: fp, a2: (void *)&p_environments->list[v5], a3: 4u) != 0
                   && fp->Read(this: fp, a2: &p_environments->list[v5].RoomGain, a3: 4u) != 0
                   && fp->Read(this: fp, a2: &p_environments->list[v5].RoomHFGain, a3: 4u) != 0
                   && fp->Read(this: fp, a2: &p_environments->list[v5].DecayTime, a3: 4u) != 0
                   && fp->Read(this: fp, a2: &p_environments->list[v5].DecayHFTime, a3: 4u) != 0
                   && fp->Read(this: fp, a2: &p_environments->list[v5].ReflectionsGain, a3: 4u) != 0
                   && fp->Read(this: fp, a2: &p_environments->list[v5].ReflectionsDelay, a3: 4u) != 0
                   && fp->Read(this: fp, a2: &p_environments->list[v5].ReverbGain, a3: 4u) != 0
                   && fp->Read(this: fp, a2: &p_environments->list[v5].ReverbDelay, a3: 4u) != 0
                   && fp->Read(this: fp, a2: &p_environments->list[v5].Diffusion, a3: 4u) != 0
                   && fp->Read(this: fp, a2: &p_environments->list[v5].Density, a3: 4u) != 0
                   && fp->Read(this: fp, a2: &p_environments->list[v5].HFReference, a3: 4u) != 0 )
              {
                ++v25;
                ++v5;
                if ( v25 >= this->environments.num )
                  return 1;
              }
            }
            else
            {
              v15 = 0;
              while ( 1 )
              {
                v16 = (idBlockAlloc<idSoundEmitterLocal,16,38>::element_t *)p_emitters->list[v15];
                if ( v16 == nullptr )
                {
                  v16 = idBlockAlloc<idSoundEmitterLocal,16,38>::Alloc(this: &this->emitterAllocator);
                  p_emitters->list[v15] = (idSoundEmitterLocal *)v16;
                  idSoundEmitterLocal::Init(this: (idSoundEmitterLocal *)v16, i: v14, sw: this);
                }
                if ( fp->Read(this: fp, a2: v32, a3: 12u) == 0 )
                  break;
                if ( v32[0] != vec3_infinity.x || v32[1] != vec3_infinity.y || (v17 = 1, v32[2] != vec3_infinity.z) )
                  v17 = 0;
                if ( v17 == 0 )
                {
                  *(float *)&v16->buffer[104] = v32[0];
                  v18 = fp->__vftable;
                  *(float *)&v16->buffer[108] = v32[1];
                  Read = v18->Read;
                  *(float *)&v16->buffer[112] = v32[2];
                  v31[0] = (int)&v16->buffer[104];
                  if ( Read(this: fp, a2: &v16->buffer[100], a3: 4u) == 0 )
                    return 0;
                  if ( fp->Read(this: fp, a2: &v16->buffer[152], a3: 12u) == 0 )
                    return 0;
                  if ( fp->Read(this: fp, a2: &v16->buffer[164], a3: 4u) == 0 )
                    return 0;
                  if ( fp->Read(this: fp, a2: &v16->buffer[168], a3: 4u) == 0 )
                    return 0;
                  if ( fp->Read(this: fp, a2: &v16->buffer[176], a3: 12u) == 0 )
                    return 0;
                  if ( fp->Read(this: fp, a2: &v16->buffer[188], a3: 4u) == 0 )
                    return 0;
                  v27 = 0;
                  if ( fp->Read(this: fp, a2: &v27, a3: 4u) == 0 )
                    return 0;
                  v20 = v27;
                  if ( v27 > *(_DWORD *)&v16->buffer[28] )
                  {
                    idList<idNavSpline *,5>::Resize(
                      this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v16->buffer[20],
                      newsize: v27);
                    v20 = v27;
                  }
                  v21 = 0;
                  if ( v20 > 0 )
                  {
                    do
                    {
                      v22 = idSoundWorldLocal::AllocSoundChannel(this);
                      v31[0] = (int)v22;
                      v22->data = (idSoundChannel *)v16;
                      idList<idAnimWebBlendTree *,5>::Append(
                        this: (idList<enum encounterGroupRole_t,5> *)&v16->buffer[20],
                        obj: (const encounterGroupRole_t *)v31);
                      if ( fp->Read(this: fp, a2: &v22->buffer[4], a3: 4u) == 0
                        || fp->Read(this: fp, a2: &v22->buffer[12], a3: 4u) == 0
                        || !LoadParms(fp, parms: (soundShaderParms_t *)&v22->buffer[16]) )
                      {
                        return 0;
                      }
                      v33.allocedAndFlag = 20;
                      v33.len = 0;
                      v33.data = v33.baseBuffer;
                      v33.baseBuffer[0] = 0;
                      if ( idFile::ReadString(this: fp, string: &v33) == 0 )
                      {
                        idStr::FreeData(this: &v33);
                        return 0;
                      }
                      if ( v33.len != 0 )
                      {
                        if ( v33.data != nullptr )
                          v23 = idDeclInfo::FindWithInheritance(
                                  this: &idSoundShader::resourceList,
                                  name: v33.data,
                                  makeDefault: true);
                        else
                          v23 = nullptr;
                        *(_DWORD *)&v22->buffer[164] = v23;
                      }
                      else
                      {
                        *(_DWORD *)&v22->buffer[164] = 0;
                      }
                      v34[0].allocedAndFlag = 20;
                      v34[0].len = 0;
                      v34[0].data = v34[0].baseBuffer;
                      v34[0].baseBuffer[0] = 0;
                      if ( idFile::ReadString(this: fp, string: v34) == 0
                        || (v34[0].len != 0
                          ? (*(_DWORD *)&v22->buffer[168] = idResourceList::Load(
                                                              this: &idSoundSample::resourceList,
                                                              name: v34[0].data,
                                                              makeDefault: true,
                                                              skipStaleCheck: false))
                          : (*(_DWORD *)&v22->buffer[168] = 0),
                            fp->Read(this: fp, a2: &v22->buffer[204], a3: 4u) == 0
                         || fp->Read(this: fp, a2: &v22->buffer[208], a3: 4u) == 0
                         || !LoadFade(fp, fade: (idSoundFade *)&v22->buffer[172])
                         || !LoadFade(fp, fade: (idSoundFade *)&v22->buffer[188])) )
                      {
                        idStr::FreeData(this: v34);
                        idStr::FreeData(this: &v33);
                        return 0;
                      }
                      idStr::FreeData(this: v34);
                      idStr::FreeData(this: &v33);
                    }
                    while ( ++v21 < v27 );
                  }
                }
                ++v14;
                ++v15;
                if ( v14 >= this->emitters.num )
                  goto LABEL_54;
              }
            }
            return 0;
          }
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// __unwind$225925
// EA  : 0x8299CEBC
// RVA : 0x0099CEBC
// PDB : w:\tech5\engine\sound\soundworld_state.cpp
// ========================================================================

void _unwind_225925()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 128));
}


// ========================================================================
// __unwind$225926
// EA  : 0x8299CEE4
// RVA : 0x0099CEE4
// PDB : w:\tech5\engine\sound\soundworld_state.cpp
// ========================================================================

void _unwind_225926()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 160));
}

