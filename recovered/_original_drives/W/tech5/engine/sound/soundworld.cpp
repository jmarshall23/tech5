
// ========================================================================
// ?SetNumListeners@idSoundWorldLocal@@UAAXH@Z
// EA  : 0x82993DC0
// RVA : 0x00993DC0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::SetNumListeners(idSoundWorldLocal *this, int num)
{
  this->numListeners = num;
  this->listenerIndex = 0;
}


// ========================================================================
// ?OverrideEnvironmentParams@idSoundWorldLocal@@UAAXABUsoundEnvironment_t@@H@Z
// EA  : 0x82993DD0
// RVA : 0x00993DD0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::OverrideEnvironmentParams(
        idSoundWorldLocal *this,
        const soundEnvironment_t *parms,
        int listenerIndex)
{
  double v3; // fp1

  if ( parms->RoomGain <= -60.0 )
    v3 = 0.0;
  else
    v3 = 1.0;
  ((void (__fastcall *)(idSoundWorldLocal *, const soundEnvironment_t *, int, int, double))this->BlendEnvironmentParams)(
    a1: this,
    a2: parms,
    a3: listenerIndex,
    a4: listenerIndex,
    a5: v3);
}


// ========================================================================
// ?GetSoundTime@idSoundWorldLocal@@UAAHXZ
// EA  : 0x82993E10
// RVA : 0x00993E10
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

int __fastcall idSoundWorldLocal::GetSoundTime(idSoundWorldLocal *this)
{
  if ( this->isPaused )
    return this->pausedTime - this->accumulatedPauseTime;
  else
    return D3DXShader::CConstantTable::GetBufferPointer(this: (D3DXCore::CBuffer *)&soundSystemLocal)
         - this->accumulatedPauseTime;
}


// ========================================================================
// ?AllocRouting@idSoundWorldLocal@@ABAXAAUlistener_t@@@Z
// EA  : 0x82993E78
// RVA : 0x00993E78
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::AllocRouting(idSoundWorldLocal *this, listener_t *listener)
{
  listener->routingParms = (soundRoutingParms_t *)idMem::AllocWithLocation(
                                                    this: &mem,
                                                    location: "w:\\tech5\\engine\\sound\\SoundWorld.cpp(1705) : TAG_SOUND",
                                                    size: 0x58u,
                                                    tag: TAG_SOUND,
                                                    zeroBuffer: false,
                                                    align: ALIGN_128,
                                                    heap: HEAP_DEFAULTHEAP);
  listener->routingParms->temp = (unsigned __int8 *)idMem::AllocWithLocation(
                                                      this: &mem,
                                                      location: "w:\\tech5\\engine\\sound\\SoundWorld.cpp(1706) : TAG_SOUND",
                                                      size: 0xF000u,
                                                      tag: TAG_SOUND,
                                                      zeroBuffer: false,
                                                      align: ALIGN_128,
                                                      heap: HEAP_DEFAULTHEAP);
  listener->routingParms->tempSize = 61440;
}


// ========================================================================
// ?CurrentShakeAmplitude@idSoundWorldLocal@@UAAMH@Z
// EA  : 0x82994348
// RVA : 0x00994348
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

float __fastcall idSoundWorldLocal::CurrentShakeAmplitude(idSoundWorldLocal *this, int listenerID)
{
  __int64 v2; // r11
  double valueFloat; // fp1
  int numListeners; // r9

  HIDWORD(v2) = 0x82000000;
  valueFloat = s_constantAmplitude.valueFloat;
  if ( s_constantAmplitude.valueFloat < 0.0 )
  {
    numListeners = this->numListeners;
    valueFloat = 0.0;
    LODWORD(v2) = 0;
    if ( numListeners <= 0 )
    {
LABEL_6:
      if ( numListeners > 1 )
      {
        LODWORD(v2) = this->numListeners;
        valueFloat = (float)((float)valueFloat / (float)v2);
      }
    }
    else
    {
      HIDWORD(v2) = &this->sbspFile.faces.size;
      while ( *(_DWORD *)(HIDWORD(v2) + 216) != listenerID )
      {
        LODWORD(v2) = v2 + 1;
        HIDWORD(v2) += 232;
        valueFloat = (float)(*(float *)HIDWORD(v2) + (float)valueFloat);
        if ( (int)v2 >= numListeners )
          goto LABEL_6;
      }
      valueFloat = this->listeners.ptr[v2].shakeAmp;
    }
  }
  return *((float *)&valueFloat + 1);
}


// ========================================================================
// ?PlaceListener@idSoundWorldLocal@@UAAXABVidVec3@@ABVidMat3@@0H@Z
// EA  : 0x829943D0
// RVA : 0x009943D0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::PlaceListener(
        idSoundWorldLocal *this,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *velocity,
        const int id)
{
  int valueInteger; // r11
  int listenerIndex; // r9
  int *p_id; // r10
  char *v9; // r11
  int v10; // r31
  int *p_size; // r29

  valueInteger = s_lockListener.valueInteger;
  if ( s_lockListener.valueInteger == 0 )
  {
    if ( this->numListeners <= 1 || s_allowMultipleListener.valueInteger == 0 )
    {
LABEL_13:
      v9 = (char *)this + 232 * valueInteger;
      v9[1144] = 1;
      *(idMat3 *)(v9 + 1148) = *axis;
      *(idVec3 *)(v9 + 1184) = *origin;
      *(idVec3 *)(v9 + 1196) = *velocity;
      *((_DWORD *)v9 + 302) = id;
      return;
    }
    listenerIndex = this->listenerIndex;
    if ( listenerIndex > 0 )
    {
      p_id = &this->listeners.ptr[0].id;
      while ( *p_id != id )
      {
        ++valueInteger;
        p_id += 58;
        if ( valueInteger >= this->listenerIndex )
          goto LABEL_10;
      }
      if ( valueInteger != -1 )
      {
LABEL_12:
        if ( valueInteger < 0 )
          return;
        goto LABEL_13;
      }
    }
LABEL_10:
    if ( listenerIndex < 2 )
    {
      valueInteger = this->listenerIndex;
      this->listenerIndex = listenerIndex + 1;
      goto LABEL_12;
    }
    idLib::Warning(fmt: "Too many listners added to sound world!. MAX: %d ", 2);
    v10 = 0;
    p_size = &this->sbspFile.vertIndex.size;
    do
    {
      p_size += 58;
      idLib::Printf(fmt: "  Listener[%d]. id=%d\n", v10++, *p_size);
    }
    while ( v10 < 2 );
    this->listenerIndex = 0;
  }
}


// ========================================================================
// ?TestMapVolumeFromFadeDB_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82994550
// RVA : 0x00994550
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall TestMapVolumeFromFadeDB_f(const idCmdArgs *args)
{
  double v1; // fp1
  double v2; // fp31

  v1 = -60.0;
  v2 = -60.0;
  while ( 1 )
  {
    if ( v2 > -40.0 )
    {
      if ( v2 < (float)(s_cushionFadeOver.valueFloat - (float)40.0) )
        v1 = (float)((float)((float)((float)((float)v2 - -40.0) / s_cushionFadeOver.valueFloat)
                           * (float)((float)(s_cushionFadeOver.valueFloat - (float)40.0) - (float)v1))
                   - (float)60.0);
      else
        v1 = v2;
    }
    idLib::Printf(fmt: "%5.1f = MapVolumeFromFadeDB( %5.1f, %5.1f )\n", v1, v2, -40.0);
    v2 = (float)((float)v2 + (float)1.0);
    if ( v2 >= 0.0 )
      break;
    v1 = -60.0;
  }
}


// ========================================================================
// AdjustForCushionChannels
// EA  : 0x82994630
// RVA : 0x00994630
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

float __fastcall AdjustForCushionChannels(
        const idStaticList<idActiveChannel,48> *activeEmitterChannels,
        int uncushionedChannels,
        double currentCushionDB,
        double driftRate)
{
  int num; // r10
  double volumeDB; // fp0
  double v6; // fp1
  int v7; // r9
  int v8; // r11
  idSoundChannel *channel; // r10
  double v10; // fp0

  num = activeEmitterChannels->num;
  if ( num > uncushionedChannels )
  {
    volumeDB = activeEmitterChannels->list[uncushionedChannels].channel->volumeDB;
    if ( volumeDB >= -60.0 )
    {
      if ( volumeDB > s_cushionFadeLimit.valueFloat )
        volumeDB = s_cushionFadeLimit.valueFloat;
    }
    else
    {
      volumeDB = -60.0;
    }
  }
  else
  {
    volumeDB = -60.0;
  }
  if ( currentCushionDB >= volumeDB )
  {
    v6 = (float)((float)currentCushionDB - (float)driftRate);
    if ( v6 >= volumeDB )
      goto LABEL_12;
  }
  else
  {
    v6 = (float)((float)currentCushionDB + (float)driftRate);
    if ( v6 <= volumeDB )
      goto LABEL_12;
  }
  v6 = volumeDB;
LABEL_12:
  v7 = 0;
  if ( num > 0 )
  {
    v8 = 0;
    do
    {
      channel = activeEmitterChannels->list[v8].channel;
      v10 = channel->volumeDB;
      if ( v10 > v6 )
      {
        if ( v10 < (float)(s_cushionFadeOver.valueFloat + (float)v6) )
          v10 = (float)((float)((float)((float)(channel->volumeDB - (float)v6) / s_cushionFadeOver.valueFloat)
                              * (float)((float)(s_cushionFadeOver.valueFloat + (float)v6) - (float)-60.0))
                      - (float)60.0);
      }
      else
      {
        v10 = -60.0;
      }
      ++v7;
      channel->volumeDB = v10;
      ++v8;
    }
    while ( v7 < activeEmitterChannels->num );
  }
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?BlendEnv@idSoundWorldLocal@@ABAXABUsoundEnvironment_t@@0MAAU2@@Z
// EA  : 0x82994728
// RVA : 0x00994728
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSoundWorldLocal::BlendEnv(
        idSoundWorldLocal *this,
        const soundEnvironment_t *from,
        __int64 cur,
        double alpha,
        __int64 a5)
{
  int v5; // r2 OVERLAPPED
  double v6; // fp0
  __int128 v7; // r11
  int DecayHFTime; // r3
  int ReflectionsDelay; // r3

  v6 = 0.0;
  if ( alpha < 0.0 || (v6 = 1.0, alpha > 1.0) )
    alpha = v6;
  DWORD1(v7) = 28;
  *(float *)HIDWORD(a5) = (float)((float)(*(float *)HIDWORD(cur) - from->DryGain) * (float)alpha) + from->DryGain;
  *(float *)(HIDWORD(a5) + 4) = (float)((float)(*(float *)(HIDWORD(cur) + 4) - from->RoomGain) * (float)alpha)
                              + from->RoomGain;
  *(float *)(HIDWORD(a5) + 8) = (float)((float)(*(float *)(HIDWORD(cur) + 8) - from->RoomHFGain) * (float)alpha)
                              + from->RoomHFGain;
  LODWORD(cur) = from->DecayTime;
  LODWORD(a5) = *(_DWORD *)(HIDWORD(cur) + 12);
  *(_DWORD *)(HIDWORD(a5) + 12) = (int)(float)((float)((float)((float)a5 - (float)cur) * (float)alpha) + (float)cur);
  DecayHFTime = from->DecayHFTime;
  LODWORD(a5) = *(_DWORD *)(HIDWORD(cur) + 16);
  *(_DWORD *)(HIDWORD(a5) + 16) = (int)(float)((float)((float)((float)a5 - (float)*(__int64 *)(&v5 - 1)) * (float)alpha)
                                             + (float)*(__int64 *)(&v5 - 1));
  *(float *)(HIDWORD(a5) + 20) = (float)((float)(*(float *)(HIDWORD(cur) + 20) - from->ReflectionsGain) * (float)alpha)
                               + from->ReflectionsGain;
  *(float *)(HIDWORD(a5) + 24) = (float)((float)(*(float *)(HIDWORD(cur) + 24) - from->ReverbGain) * (float)alpha)
                               + from->ReverbGain;
  ReflectionsDelay = from->ReflectionsDelay;
  DWORD2(v7) = *(_DWORD *)(HIDWORD(cur) + 28);
  *(_DWORD *)(HIDWORD(a5) + 28) = (int)(float)((float)((float)((float)*(__int64 *)((char *)&v7 + 4)
                                                             - (float)*(__int64 *)(&v5 - 1))
                                                     * (float)alpha)
                                             + (float)*(__int64 *)(&v5 - 1));
  LODWORD(a5) = from->ReverbDelay;
  LODWORD(v7) = *(_DWORD *)(HIDWORD(cur) + 32);
  *(_DWORD *)(HIDWORD(a5) + 32) = (int)(float)((float)((float)((float)(__int64)v7 - (float)a5) * (float)alpha)
                                             + (float)a5);
  *(float *)(HIDWORD(a5) + 36) = (float)((float)(*(float *)(HIDWORD(cur) + 36) - from->Diffusion) * (float)alpha)
                               + from->Diffusion;
  *(float *)(HIDWORD(a5) + 40) = (float)((float)(*(float *)(HIDWORD(cur) + 40) - from->Density) * (float)alpha)
                               + from->Density;
  *(float *)(HIDWORD(a5) + 44) = (float)((float)(*(float *)(HIDWORD(cur) + 44) - from->HFReference) * (float)alpha)
                               + from->HFReference;
}


// ========================================================================
// ?OnReloadSound@idSoundWorldLocal@@QAAXPBVidDecl@@@Z
// EA  : 0x82994900
// RVA : 0x00994900
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::OnReloadSound(idSoundWorldLocal *this, const idSoundShader *shader)
{
  int v4; // r31
  int v5; // r30

  v4 = 0;
  if ( this->emitters.num > 0 )
  {
    v5 = 0;
    do
    {
      idSoundEmitterLocal::OnReloadSound(this: this->emitters.list[v5], decl: shader);
      ++v4;
      ++v5;
    }
    while ( v4 < this->emitters.num );
  }
}


// ========================================================================
// ?NumEmitters@idSoundWorldLocal@@UAAHXZ
// EA  : 0x82994958
// RVA : 0x00994958
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

int __fastcall idSoundWorldLocal::NumEmitters(idSoundWorldLocal *this)
{
  return this->emitters.num;
}


// ========================================================================
// ?EmitterForIndex@idSoundWorldLocal@@UAAPAVidSoundEmitter@@H@Z
// EA  : 0x82994960
// RVA : 0x00994960
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::EmitterForIndex(idSoundWorldLocal *this, int index)
{
  int num; // r5

  if ( index >= 0 )
  {
    num = this->emitters.num;
    if ( index >= num )
      idLib::Error(fmt: "idSoundWorldLocal::EmitterForIndex: %i >= %i", index, num);
  }
}


// ========================================================================
// ?StopAllSounds@idSoundWorldLocal@@UAAXXZ
// EA  : 0x82994998
// RVA : 0x00994998
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::StopAllSounds(idSoundWorldLocal *this)
{
  int v2; // r30
  int v3; // r31

  v2 = 0;
  if ( this->emitters.num > 0 )
  {
    v3 = 0;
    do
    {
      this->emitters.list[v3]->Reset(this: this->emitters.list[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->emitters.num );
  }
}


// ========================================================================
// ?Fade@idSoundWorldLocal@@UAAXW4soundShaderGroups_t@@MH@Z
// EA  : 0x829949F0
// RVA : 0x009949F0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::Fade(
        idSoundWorldLocal *this,
        soundShaderGroups_t group,
        double toDB,
        int overMS,
        int a5)
{
  __int64 v9; // r4
  unsigned int v10; // r8
  int v11; // r29
  idArray<idSoundFade,25> *p_groupFade; // r31
  int i; // r28
  __int64 v14; // r4
  unsigned int v15; // r8

  if ( group != SSG_MASTER )
  {
    v11 = 1;
    p_groupFade = &this->groupFade;
    for ( i = 25; i != 0; --i )
    {
      if ( (v11 & group) != 0 )
      {
        v14 = ((__int64 (__fastcall *)(idSoundWorldLocal *))this->GetSoundTime)(a1: this);
        idSoundFade::Fade(this: p_groupFade->ptr, to: toDB, length: v14, soundTime: a5, delay: SHIDWORD(v14), a6: v15);
      }
      p_groupFade = (idArray<idSoundFade,25> *)((char *)p_groupFade + 16);
      v11 = __ROL4__(v11, 1);
    }
  }
  else
  {
    v9 = ((__int64 (__fastcall *)(idSoundWorldLocal *))this->GetSoundTime)(a1: this);
    idSoundFade::Fade(this: &this->volumeFade, to: toDB, length: v9, soundTime: a5, delay: SHIDWORD(v9), a6: v10);
  }
}


// ========================================================================
// ?reportSoundWorld_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82994AB0
// RVA : 0x00994AB0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall reportSoundWorld_f(const idCmdArgs *args)
{
  int v1; // r5
  int v2; // r7
  int v3; // r4
  int v4; // r6
  idSoundEmitterLocal **list; // r8
  int num; // r3
  idSoundEmitterLocal *v7; // r11
  int v8; // r10
  int v9; // r10
  idSoundChannel **v10; // r9
  int v11; // r11
  int i; // ctr

  if ( soundSystemLocal.currentSoundWorld != nullptr )
  {
    v1 = 0;
    v2 = 0;
    v3 = 0;
    v4 = 0;
    if ( soundSystemLocal.currentSoundWorld->emitters.num > 0 )
    {
      list = soundSystemLocal.currentSoundWorld->emitters.list;
      num = soundSystemLocal.currentSoundWorld->emitters.num;
      do
      {
        v7 = *list;
        if ( *list != nullptr )
        {
          v8 = v7->channels.num;
          ++v3;
          v1 += v8;
          if ( v8 > v2 )
            v2 = v7->channels.num;
          v9 = v7->channels.num;
          if ( v9 > 0 )
          {
            v10 = v7->channels.list;
            v11 = 0;
            for ( i = v9; i != 0; --i )
            {
              if ( v10[v11]->hardwareVoice != nullptr )
                ++v4;
              ++v11;
            }
          }
        }
        --num;
        ++list;
      }
      while ( num != 0 );
    }
    idLib::Printf(
      fmt: "%i emitters, %i total channels, %i hardware voices, %i max channels on an emitter\n",
      v3,
      v1,
      v4,
      v2);
  }
}


// ========================================================================
// ?FindEnvironment@idSoundWorldLocal@@UAAHABVidVec3@@@Z
// EA  : 0x82994B60
// RVA : 0x00994B60
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

int __fastcall idSoundWorldLocal::FindEnvironment(idSoundWorldLocal *this, const idVec3 *origin)
{
  return this->sbspFile.areas.list[idSoundBSPFile::PointAreaNum(this: &this->sbspFile, point: origin)].environment;
}


// ========================================================================
// ?SetEnvironmentParams@idSoundWorldLocal@@UAA_NHABUsoundEnvironment_t@@@Z
// EA  : 0x82994BA8
// RVA : 0x00994BA8
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

int __fastcall idSoundWorldLocal::SetEnvironmentParams(
        idSoundWorldLocal *this,
        int environmentNum,
        const soundEnvironment_t *parms)
{
  if ( environmentNum < 0 || environmentNum >= this->environments.num )
    return 0;
  memcpy(
    Dst: (void *)&this->environments.list[environmentNum],
    Src: parms,
    Size: sizeof(this->environments.list[environmentNum]));
  return 1;
}


// ========================================================================
// ?GetEnvironmentParams@idSoundWorldLocal@@UAA_NHAAUsoundEnvironment_t@@@Z
// EA  : 0x82994C10
// RVA : 0x00994C10
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

int __fastcall idSoundWorldLocal::GetEnvironmentParams(
        idSoundWorldLocal *this,
        int environmentNum,
        soundEnvironment_t *parms)
{
  if ( environmentNum < 0 || environmentNum >= this->environments.num )
    return 0;
  *parms = this->environments.list[environmentNum];
  return 1;
}


// ========================================================================
// ?BlendEnvironmentParams@idSoundWorldLocal@@UAAXABUsoundEnvironment_t@@MH@Z
// EA  : 0x82994C78
// RVA : 0x00994C78
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::BlendEnvironmentParams(
        idSoundWorldLocal *this,
        const soundEnvironment_t *parms,
        double alpha,
        int listenerIndex,
        int a5)
{
  float *v6; // r31

  if ( a5 < 0 || this->numListeners <= 1 )
    a5 = 0;
  if ( ((((this->numListeners ^ a5) >= 0) + ((unsigned int)a5 >= this->numListeners)) & 1) != 0 )
  {
    v6 = (float *)((char *)this + 232 * a5);
    memcpy(Dst: v6 + 308, Src: parms, Size: 0x3Cu);
    v6[343] = alpha;
  }
}


// ========================================================================
// ?FindDoor@idSoundWorldLocal@@UAAHABVidVec3@@@Z
// EA  : 0x82994CF8
// RVA : 0x00994CF8
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

int __fastcall idSoundWorldLocal::FindDoor(idSoundWorldLocal *this, const idVec3 *origin)
{
  idSoundBSPFile *p_sbspFile; // r29
  int result; // r3
  int v6; // r28
  float *v7; // r27
  double v8; // fp7
  double v9; // fp6
  __int16 door; // r10
  float v11; // [sp+50h] [-70h] BYREF
  float v12; // [sp+54h] [-6Ch]
  float v13; // [sp+58h] [-68h]
  idVec3 v14; // [sp+60h] [-60h] BYREF

  p_sbspFile = &this->sbspFile;
  result = this->sbspFile.areas.list[idSoundBSPFile::PointAreaNum(this: &this->sbspFile, point: origin)].door;
  if ( result == -1 )
  {
    v6 = 0;
    v7 = &v11;
    do
    {
      v11 = 0.0;
      v12 = 0.0;
      v13 = 0.0;
      if ( v6 < 3 )
        *v7 = 1.0;
      else
        *(v7 - 3) = -1.0;
      v8 = (float)(origin->y + v12);
      v9 = (float)(origin->z + v13);
      v14.x = origin->x + v11;
      v14.y = v8;
      v14.z = v9;
      door = this->sbspFile.areas.list[idSoundBSPFile::PointAreaNum(this: p_sbspFile, point: &v14)].door;
      result = door;
      if ( door >= 0 )
        break;
      ++v6;
      ++v7;
    }
    while ( v6 < 6 );
  }
  return result;
}


// ========================================================================
// ?SetDoor@idSoundWorldLocal@@UAAXHM@Z
// EA  : 0x82994E00
// RVA : 0x00994E00
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::SetDoor(idSoundWorldLocal *this, int doorNum, double value)
{
  if ( doorNum >= 0 && doorNum < this->doors.num )
    this->doors.list[doorNum] = value;
}


// ========================================================================
// ?Trace@idSoundWorldLocal@@UBA_NABVidVec3@@0@Z
// EA  : 0x82994E28
// RVA : 0x00994E28
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

int __fastcall idSoundWorldLocal::Trace(
        idSoundWorldLocal *this,
        idSBSPNodeCache *start,
        idSBSPPlaneCache *end,
        const idVec3 *a4,
        const idVec3 *a5)
{
  if ( this->sbspFile.nodes.num > 1 )
    return ExternalSoundTrace(flatBSP: &this->sbspFile.flatBSP, start, end, a4, a5);
  else
    return 0;
}


// ========================================================================
// ?Pause@idSoundWorldLocal@@UAAXXZ
// EA  : 0x82994E48
// RVA : 0x00994E48
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::Pause(idSoundWorldLocal *this)
{
  int BufferPointer; // r3
  int num; // r10
  int v4; // r26
  int v5; // r29
  int v6; // r28
  int v7; // r31
  idSoundChannel *v8; // r30
  idSoundVoice_XAudio2 *hardwareVoice; // r3

  if ( !this->isPaused )
  {
    BufferPointer = D3DXShader::CConstantTable::GetBufferPointer(this: (D3DXCore::CBuffer *)&soundSystemLocal);
    num = this->emitters.num;
    this->pausedTime = BufferPointer;
    v4 = num - 1;
    this->isPaused = true;
    if ( num - 1 >= 0 )
    {
      v5 = v4;
      do
      {
        if ( v4 > 0 )
        {
          v6 = 0;
          if ( this->emitters.list[v5]->channels.num > 0 )
          {
            v7 = 0;
            do
            {
              v8 = this->emitters.list[v5]->channels.list[v7];
              if ( !idSoundChannel::CanMute(this: v8) )
              {
                hardwareVoice = v8->hardwareVoice;
                if ( hardwareVoice != nullptr )
                  idSoundVoice_XAudio2::Pause(this: hardwareVoice);
              }
              ++v6;
              ++v7;
            }
            while ( v6 < this->emitters.list[v5]->channels.num );
          }
        }
        --v4;
        --v5;
      }
      while ( v4 >= 0 );
    }
  }
}


// ========================================================================
// ?UnPause@idSoundWorldLocal@@UAAXXZ
// EA  : 0x82994F18
// RVA : 0x00994F18
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::UnPause(idSoundWorldLocal *this)
{
  int valueInteger; // r29
  __int64 v3; // r4
  int v4; // r26
  int v5; // r28
  int v6; // r27
  int v7; // r30
  idSoundChannel *v8; // r29
  idSoundVoice_XAudio2 *hardwareVoice; // r3

  if ( this->isPaused )
  {
    this->isPaused = false;
    this->accumulatedPauseTime = D3DXShader::CConstantTable::GetBufferPointer(this: (D3DXCore::CBuffer *)&soundSystemLocal)
                               + this->accumulatedPauseTime
                               - this->pausedTime;
    idSoundFade::SetVolume(this: &this->pauseFade, to: -60.0);
    valueInteger = s_unpauseFadeInTime.valueInteger;
    v3 = ((__int64 (__fastcall *)(idSoundWorldLocal *))this->GetSoundTime)(a1: this);
    idSoundFade::Fade(
      this: &this->pauseFade,
      to: 0.0,
      length: v3,
      soundTime: valueInteger,
      delay: SHIDWORD(v3),
      a6: 0x82000000);
    v4 = this->emitters.num - 1;
    if ( v4 >= 0 )
    {
      v5 = v4;
      do
      {
        if ( v4 > 0 )
        {
          v6 = 0;
          if ( this->emitters.list[v5]->channels.num > 0 )
          {
            v7 = 0;
            do
            {
              v8 = this->emitters.list[v5]->channels.list[v7];
              if ( !idSoundChannel::CanMute(this: v8) )
              {
                hardwareVoice = v8->hardwareVoice;
                if ( hardwareVoice != nullptr )
                  idSoundVoice_XAudio2::UnPause(this: hardwareVoice);
              }
              ++v6;
              ++v7;
            }
            while ( v6 < this->emitters.list[v5]->channels.num );
          }
        }
        --v4;
        --v5;
      }
      while ( v4 >= 0 );
    }
  }
}


// ========================================================================
// ?AllocSoundChannel@idSoundWorldLocal@@QAAPAVidSoundChannel@@XZ
// EA  : 0x829958A0
// RVA : 0x009958A0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

idBlockAlloc<idSoundChannel,16,38>::element_t *__fastcall idSoundWorldLocal::AllocSoundChannel(idSoundWorldLocal *this)
{
  return idBlockAlloc<idSoundChannel,16,38>::Alloc(this: &this->channelAllocator);
}


// ========================================================================
// ?duck_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82995910
// RVA : 0x00995910
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall duck_f(const idCmdArgs *args)
{
  int v2; // r27
  int v3; // r28
  int v4; // r29
  const char *v5; // r3
  const char *v6; // r3
  const char *v7; // r4

  if ( args->argc > 1 && soundSystemLocal.currentSoundWorld != nullptr )
  {
    v2 = 1000;
    v3 = -1;
    v4 = -1;
    if ( args->argc >= 3 )
      v2 = atol(nptr: args->argv[2]);
    if ( args->argc >= 4 )
    {
      if ( args->argc <= 3 )
        v5 = &byte_8200D768;
      else
        v5 = args->argv[3];
      v3 = atol(nptr: v5);
    }
    if ( args->argc >= 5 )
    {
      if ( args->argc <= 4 )
        v6 = &byte_8200D768;
      else
        v6 = args->argv[4];
      v4 = atol(nptr: v6);
    }
    if ( args->argc <= 1 )
    {
      v7 = &byte_8200D768;
    }
    else
    {
      v7 = args->argv[1];
      if ( v7 == nullptr )
        goto LABEL_20;
    }
    v7 = (const char *)idDeclInfo::FindWithInheritance(this: &idDeclDuck::resourceList, name: v7, makeDefault: true);
LABEL_20:
    soundSystemLocal.currentSoundWorld->Duck(
      this: soundSystemLocal.currentSoundWorld,
      a2: (const idDeclDuck *)v7,
      a3: v2,
      a4: v3,
      a5: v4);
  }
}


// ========================================================================
// ?duckBlend_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82995A28
// RVA : 0x00995A28
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall duckBlend_f(const idCmdArgs *args)
{
  const char *v2; // r3
  int v3; // r3
  double v4; // fp31
  const char *v5; // r4

  if ( args->argc >= 2 && soundSystemLocal.currentSoundWorld != nullptr )
  {
    v2 = args->argc <= 2 ? &byte_8200D768 : args->argv[2];
    v3 = atol(nptr: v2);
    if ( v3 >= 0 )
    {
      if ( v3 > 100 )
        v3 = 100;
    }
    else
    {
      v3 = 0;
    }
    v4 = (float)((float)__SPAIR64__(byte_821B0000, v3) * (float)0.0099999998);
    if ( v4 > 0.0 )
    {
      if ( args->argc <= 1 )
      {
        v5 = &byte_8200D768;
      }
      else
      {
        v5 = args->argv[1];
        if ( v5 == nullptr )
          goto LABEL_16;
      }
      v5 = (const char *)idDeclInfo::FindWithInheritance(this: &idDeclDuck::resourceList, name: v5, makeDefault: true);
LABEL_16:
      soundSystemLocal.currentSoundWorld->DuckBlend(
        this: soundSystemLocal.currentSoundWorld,
        a2: (const idDeclDuck *)v5,
        a3: v4);
    }
  }
}


// ========================================================================
// ?PlayGlobalShaderDirectly@idSoundWorldLocal@@UAAHPBVidSoundShader@@W4soundChannel_t@@M@Z
// EA  : 0x82995B28
// RVA : 0x00995B28
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

int __fastcall idSoundWorldLocal::PlayGlobalShaderDirectly(
        idSoundWorldLocal *this,
        const idSoundShader *shader,
        soundChannel_t channel,
        double volumeDb)
{
  idSoundEmitter *localSound; // r3
  soundShaderParms_t v10; // [sp+50h] [-C0h] BYREF

  if ( shader != nullptr )
  {
    soundShaderParms_t::Clear(this: &v10);
    v10.volume.min = volumeDb;
    localSound = this->localSound;
    v10.volume.max = volumeDb;
    v10.soundShaderFlags = SSF_GLOBAL;
    return localSound->StartSound(this: localSound, a2: channel, a3: shader, a4: &v10);
  }
  else
  {
    this->localSound->StopSound(this: this->localSound, a2: channel);
    return 0;
  }
}


// ========================================================================
// ?GetBestListenerForEmitter@idSoundWorldLocal@@QAAPAUlistener_t@@HABVidVec3@@@Z
// EA  : 0x82995BC0
// RVA : 0x00995BC0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

idArray<listener_t,2> *__fastcall idSoundWorldLocal::GetBestListenerForEmitter(
        idSoundWorldLocal *this,
        int emitterId,
        const idVec3 *emitterOrigin)
{
  int numListeners; // r7
  int v5; // r10
  idArray<listener_t,2> *p_listeners; // r11
  int v7; // r9
  double v8; // fp0
  int v9; // r8
  float *p_z; // r11
  double v11; // fp11
  double v12; // fp8
  double v13; // fp5
  double v14; // fp11
  double v15; // fp8
  double v16; // fp5
  double v17; // fp11
  double v18; // fp8
  double v19; // fp5
  double v20; // fp11
  double v21; // fp8
  double v22; // fp5
  float *v23; // r11
  int v24; // ctr
  double v25; // fp11
  double v26; // fp8
  double v27; // fp5

  numListeners = this->numListeners;
  if ( numListeners <= 1 || s_allowMultipleListener.valueInteger == 0 )
    return &this->listeners;
  if ( emitterId < 0 )
  {
LABEL_8:
    v5 = -1;
    v7 = 0;
    v8 = -1.0;
    if ( numListeners >= 4 )
    {
      v9 = 2;
      p_z = &this->listeners.ptr[0].pos.z;
      do
      {
        if ( *((_BYTE *)p_z - 48) != 0 )
        {
          v11 = (float)(*(p_z - 1) - emitterOrigin->y);
          v12 = (float)(*(p_z - 2) - emitterOrigin->x);
          v13 = (float)(*p_z - emitterOrigin->z);
          if ( v5 < 0
            || (float)((float)((float)v13 * (float)v13)
                     + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) < v8 )
          {
            v5 = v7;
            v8 = (float)((float)((float)v13 * (float)v13)
                       + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)));
          }
        }
        if ( *((_BYTE *)p_z + 184) != 0 )
        {
          v14 = (float)(p_z[57] - emitterOrigin->y);
          v15 = (float)(p_z[56] - emitterOrigin->x);
          v16 = (float)(p_z[58] - emitterOrigin->z);
          if ( v5 < 0
            || (float)((float)((float)v16 * (float)v16)
                     + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) < v8 )
          {
            v5 = v9 - 1;
            v8 = (float)((float)((float)v16 * (float)v16)
                       + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)));
          }
        }
        if ( *((_BYTE *)p_z + 416) != 0 )
        {
          v17 = (float)(p_z[115] - emitterOrigin->y);
          v18 = (float)(p_z[114] - emitterOrigin->x);
          v19 = (float)(p_z[116] - emitterOrigin->z);
          if ( v5 < 0
            || (float)((float)((float)v19 * (float)v19)
                     + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) < v8 )
          {
            v5 = v9;
            v8 = (float)((float)((float)v19 * (float)v19)
                       + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)));
          }
        }
        if ( *((_BYTE *)p_z + 648) != 0 )
        {
          v20 = (float)(p_z[173] - emitterOrigin->y);
          v21 = (float)(p_z[172] - emitterOrigin->x);
          v22 = (float)(p_z[174] - emitterOrigin->z);
          if ( v5 < 0
            || (float)((float)((float)v22 * (float)v22)
                     + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20))) < v8 )
          {
            v5 = v9 + 1;
            v8 = (float)((float)((float)v22 * (float)v22)
                       + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)));
          }
        }
        v7 += 4;
        v9 += 4;
        p_z += 232;
      }
      while ( v7 < numListeners - 3 );
    }
    if ( v7 < numListeners )
    {
      v23 = &this->listeners.ptr[v7].pos.z;
      v24 = numListeners - v7;
      do
      {
        if ( *((_BYTE *)v23 - 48) != 0 )
        {
          v25 = (float)(*(v23 - 1) - emitterOrigin->y);
          v26 = (float)(*(v23 - 2) - emitterOrigin->x);
          v27 = (float)(*v23 - emitterOrigin->z);
          if ( v5 < 0
            || (float)((float)((float)v27 * (float)v27)
                     + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) < v8 )
          {
            v5 = v7;
            v8 = (float)((float)((float)v27 * (float)v27)
                       + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)));
          }
        }
        ++v7;
        v23 += 58;
        --v24;
      }
      while ( v24 != 0 );
    }
    if ( v5 < 0 )
    {
      idLib::Warning(fmt: "idSoundWorldLocal::GetBestListenerForEmitter called with no valid listeners");
      v5 = 0;
    }
  }
  else
  {
    v5 = 0;
    p_listeners = &this->listeners;
    while ( p_listeners->ptr[0].id != emitterId || !p_listeners->ptr[0].valid )
    {
      ++v5;
      p_listeners = (idArray<listener_t,2> *)((char *)p_listeners + 232);
      if ( v5 >= numListeners )
        goto LABEL_8;
    }
  }
  return (idArray<listener_t,2> *)((char *)&this->listeners + 232 * v5);
}


// ========================================================================
// ?SoundReportNonMatchingFrequencies_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82995E88
// RVA : 0x00995E88
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall SoundReportNonMatchingFrequencies_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v2; // r3
  int v3; // r25
  idFileList *v4; // r29
  int v5; // r26
  int v6; // r28
  const char *data; // r30
  idFile *v8; // r3
  idFile *v9; // r31
  char v10[16]; // [sp+50h] [-70h] BYREF
  char v11[12]; // [sp+60h] [-60h] BYREF
  int v12; // [sp+6Ch] [-54h]

  argc = args->argc;
  if ( args->argc >= 2 )
  {
    if ( argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    v3 = atol(nptr: v2);
    v4 = fileSystem->ListFilesTree(this: fileSystem, a2: "sound", a3: "wav", a4: 0);
    v5 = 0;
    if ( v4->list.num > 0 )
    {
      v6 = 0;
      do
      {
        data = v4->list.list[v6].data;
        v8 = fileSystem->OpenFileRead(this: fileSystem, a2: data, a3: 1, a4: 0);
        v9 = v8;
        if ( v8 != nullptr )
        {
          v8->Read(this: v8, a2: v10, a3: 12u);
          v9->Read(this: v9, a2: v11, a3: 24u);
          if ( v3 != v12 )
            idLib::Printf(fmt: "%s: %d Hz\n", data, v12);
          ((void (__fastcall *)(idFile *, int))v9->dtr_idFile)(a1: v9, a2: 1);
        }
        ++v5;
        ++v6;
      }
      while ( v5 < v4->list.num );
    }
    fileSystem->FreeFileList(this: fileSystem, a2: v4);
  }
  else if ( argc <= 0 )
  {
    idLib::Printf(fmt: "Syntax: %s <frequency>\n", &byte_8200D768);
  }
  else
  {
    idLib::Printf(fmt: "Syntax: %s <frequency>\n", args->argv[0]);
  }
}


// ========================================================================
// ?FreeSoundChannel@idSoundWorldLocal@@QAAXPAVidSoundChannel@@@Z
// EA  : 0x82996950
// RVA : 0x00996950
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::FreeSoundChannel(idSoundWorldLocal *this, idSoundChannel *channel)
{
  idBlockAlloc<idSoundChannel,16,38> *p_channelAllocator; // r31

  p_channelAllocator = &this->channelAllocator;
  if ( channel != nullptr )
  {
    idSoundChannel::~idSoundChannel(this: channel);
    channel->emitter = (idSoundEmitterLocal *)p_channelAllocator->free;
    p_channelAllocator->free = (idBlockAlloc<idSoundChannel,16,38>::element_t *)channel;
    --p_channelAllocator->active;
  }
}


// ========================================================================
// ?DrawDebug@idSoundWorldLocal@@UAAXPAVidRenderWorld@@@Z
// EA  : 0x829969B8
// RVA : 0x009969B8
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSoundWorldLocal::DrawDebug(idSoundWorldLocal *this, idRenderWorld *rw)
{
  int v4; // r29
  int v5; // r30
  int v6; // r3
  __int64 v7; // r8
  int v8; // r22
  int v9; // r5
  __int64 v10; // r8
  __int64 v11; // r10
  va *v12; // r3
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  va *v16; // r3
  __int64 v17; // r10
  __int64 v18; // r6
  __int64 v19; // r8
  int v20; // r29
  int v21; // r30
  idSoundWorldLocal::idDuckLayer *v22; // r11
  char v23; // r10
  va *v24; // r3
  const char *v25; // r27
  int v26; // r11
  int v27; // r10
  const enumTypeInfo_t *EnumInfo; // r15
  int v29; // r24
  int v30; // r21
  idArray<idSoundFade,25> *p_groupFade; // r23
  const enumValueInfo_t *EnumValueInfo; // r26
  int v33; // r3
  __int64 v34; // r8
  int v35; // r5
  idSoundWorldLocal::idDuckLayer *v36; // r28
  double Volume; // fp31
  int v38; // r29
  idSoundWorldLocal::idDuckLayer *list; // r27
  int v40; // r30
  idSoundWorldLocal::idDuckLayer *v41; // r3
  char v42; // r11
  char *data; // r30
  __int64 v44; // r8
  int v45; // r5
  __int128 v46; // r7 OVERLAPPED
  __int64 v47; // r10
  va *v48; // r3
  int v49; // r29
  int v50; // r30
  idSoundWorldLocal::idDuckLayer *v51; // r3
  char v52; // r11
  __int64 v53; // r6
  __int64 v54; // r10
  __int64 v55; // r8
  va *v56; // r3
  int v57; // r11
  int v58; // r10
  int v59; // [sp+8h] [-1138h]
  int v60; // [sp+8h] [-1138h]
  int v61; // [sp+8h] [-1138h]
  int v62; // [sp+Ch] [-1134h]
  int v63; // [sp+Ch] [-1134h]
  int v64; // [sp+Ch] [-1134h]
  int v65; // [sp+10h] [-1130h]
  int v66; // [sp+10h] [-1130h]
  int v67; // [sp+10h] [-1130h]
  int v68; // [sp+14h] [-112Ch]
  int v69; // [sp+14h] [-112Ch]
  int v70; // [sp+14h] [-112Ch]
  int v71; // [sp+18h] [-1128h]
  int v72; // [sp+18h] [-1128h]
  int v73; // [sp+18h] [-1128h]
  int v74; // [sp+1Ch] [-1124h]
  int v75; // [sp+1Ch] [-1124h]
  int v76; // [sp+1Ch] [-1124h]
  double v77; // [sp+20h] [-1120h]
  __int64 v78; // [sp+28h] [-1118h]
  double v79; // [sp+30h] [-1110h]
  idStr v80; // [sp+50h] [-10F0h] BYREF
  const char *v81; // [sp+70h] [-10D0h]
  idSoundWorldLocal::idDuckLayer *num; // [sp+74h] [-10CCh]
  idOverlayHandle *v83; // [sp+78h] [-10C8h]
  const char *v84; // [sp+7Ch] [-10C4h]
  idStr v85; // [sp+80h] [-10C0h] BYREF
  va v86; // [sp+A0h] [-10A0h] BYREF

  if ( s_drawSounds.valueInteger != 0 )
  {
    v4 = 0;
    if ( this->emitters.num > 0 )
    {
      v5 = 0;
      do
      {
        idSoundEmitterLocal::DrawDebugInfo(this: this->emitters.list[v5], rw);
        ++v4;
        ++v5;
      }
      while ( v4 < this->emitters.num );
    }
  }
  if ( s_showDucks.valueInteger != 0 )
  {
    v6 = this->GetSoundTime(this);
    v80.len = 0;
    LODWORD(v7) = v80.baseBuffer;
    v80.baseBuffer[0] = 0;
    v80.allocedAndFlag = 20;
    v8 = v6;
    v80.data = v80.baseBuffer;
    *(double *)&v78 = idSoundFade::GetVolume(this: &this->volumeFade, soundTime: v6, a3: v9, a4: v7);
    HIDWORD(v10) = "olor specular";
    v12 = va::va(
            this: &v86,
            fmt: "%20s: %6.2f\n\n",
            a3: v78,
            a4: v10,
            a5: v11,
            a6: v59,
            a7: v62,
            a8: v65,
            a9: v68,
            a10: v71,
            a11: v74);
    idStr::Append(this: &v80, text: v12);
    v83 = &handle_4;
    if ( (_S14_6 & 1) == 0 )
    {
      handle_4.time = 0;
      _S14_6 |= 1u;
      handle_4.index = -1;
    }
    LODWORD(v13) = "olor specular";
    HIDWORD(v13) = "olor specular";
    LODWORD(v14) = "olor specular";
    HIDWORD(v14) = "Code";
    LODWORD(v15) = "Total";
    HIDWORD(v15) = "Group";
    v16 = va::va(
            this: &v86,
            fmt: "%20s: %6s %6s",
            a3: v15,
            a4: v14,
            a5: v13,
            a6: v60,
            a7: v63,
            a8: v66,
            a9: v69,
            a10: v72,
            a11: v75);
    idStr::Append(this: &v80, text: v16);
    HIDWORD(v19) = this->ducks.num;
    v20 = 0;
    if ( SHIDWORD(v19) > 0 )
    {
      v21 = 0;
      do
      {
        v22 = &this->ducks.list[v21];
        if ( v22->endFadeStart < 0 || (v23 = 1, v8 < v22->endFadeEnd) )
          v23 = 0;
        if ( v23 == 0 )
        {
          LODWORD(v17) = v22->decl;
          v81 = (const char *)&this->ducks.list[v21];
          HIDWORD(v18) = *(_DWORD *)(v17 + 8);
          v24 = va::va(
                  this: &v86,
                  fmt: "%10s",
                  a3: v18,
                  a4: v19,
                  a5: v17,
                  a6: v61,
                  a7: v64,
                  a8: v67,
                  a9: v70,
                  a10: v73,
                  a11: v76);
          idStr::Append(this: &v80, text: v24);
        }
        ++v20;
        ++v21;
      }
      while ( v20 < this->ducks.num );
    }
    v25 = "w:\\tech5\\shared\\idlib\\text/Str.h";
    v84 = "w:\\tech5\\shared\\idlib\\text/Str.h";
    v26 = v80.len + 2;
    v81 = "amount <= GetAlloced()";
    v27 = v80.allocedAndFlag & 0x7FFFFFFF;
    if ( v80.allocedAndFlag >= 0 )
    {
      if ( v26 > v27 )
        idStr::ReAllocate(this: &v80, amount: (v26 >> 1) + v26, keepold: true);
    }
    else if ( v26 > v27
           && AssertFailed(
                file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                line: 463,
                expression: "amount <= GetAlloced()",
                inlineBreak: true) )
    {
      __trap();
    }
    v80.data[v80.len++] = 10;
    v80.data[v80.len] = 0;
    EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "soundShaderGroups_t");
    v29 = 0;
    v30 = 1;
    p_groupFade = &this->groupFade;
    do
    {
      EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(this: typeInfoTools, enumInfo: EnumInfo, value: v30);
      if ( EnumValueInfo != nullptr )
      {
        v33 = this->GetSoundTime(this);
        Volume = idSoundFade::GetVolume(this: p_groupFade->ptr, soundTime: v33, a3: v35, a4: v34);
        v38 = 0;
        num = (idSoundWorldLocal::idDuckLayer *)this->ducks.num;
        v36 = num;
        if ( (int)num > 0 )
        {
          list = this->ducks.list;
          v40 = 0;
          do
          {
            v41 = &list[v40];
            if ( list[v40].endFadeStart < 0 || (v42 = 1, v8 < v41->endFadeEnd) )
              v42 = 0;
            if ( v42 == 0 )
              Volume = (float)(idSoundWorldLocal::idDuckLayer::GetVolume(this: v41, g: v29, currentTime: v8)
                             + (float)Volume);
            ++v38;
            ++v40;
          }
          while ( v38 < (int)v36 );
          v25 = v84;
        }
        idStr::idStr(this: &v85, text: EnumValueInfo->name);
        idStr::StripLeading(this: &v85, string: "SSG_");
        data = v85.data;
        v79 = idSoundFade::GetVolume(this: p_groupFade->ptr, soundTime: v8, a3: v45, a4: v44);
        DWORD1(v46) = data;
        *((double *)&v46 + 1) = v79;
        v48 = va::va(
                this: &v86,
                fmt: "%20s: %6.2f %6.2f",
                a3: *(__int64 *)((char *)&v46 + 4),
                a4: *(__int64 *)((char *)&v46 - 4),
                a5: v47,
                a6: v61,
                a7: v64,
                a8: v67,
                a9: v70,
                a10: v73,
                a11: v76,
                Volume,
                v79);
        idStr::Append(this: &v80, text: v48);
        v49 = 0;
        if ( this->ducks.num > 0 )
        {
          v50 = 0;
          do
          {
            v51 = &this->ducks.list[v50];
            if ( v51->endFadeStart < 0 || (v52 = 1, v8 < v51->endFadeEnd) )
              v52 = 0;
            if ( v52 == 0 )
            {
              num = &this->ducks.list[v50];
              v77 = idSoundWorldLocal::idDuckLayer::GetVolume(this: v51, g: v29, currentTime: v8);
              HIDWORD(v53) = LODWORD(v77);
              v56 = va::va(
                      this: &v86,
                      fmt: "    %6.2f",
                      a3: v53,
                      a4: v55,
                      a5: v54,
                      a6: v61,
                      a7: v64,
                      a8: v67,
                      a9: v70,
                      a10: v73,
                      a11: v76);
              idStr::Append(this: &v80, text: v56);
            }
            ++v49;
            ++v50;
          }
          while ( v49 < this->ducks.num );
        }
        v57 = v80.len + 2;
        v58 = v80.allocedAndFlag & 0x7FFFFFFF;
        if ( v80.allocedAndFlag >= 0 )
        {
          if ( v57 > v58 )
            idStr::ReAllocate(this: &v80, amount: (v57 >> 1) + v57, keepold: true);
        }
        else if ( v57 > v58 && AssertFailed(file: v25, line: 463, expression: v81, inlineBreak: true) )
        {
          __trap();
        }
        v80.data[v80.len++] = 10;
        v80.data[v80.len] = 0;
        idStr::FreeData(this: &v85);
      }
      ++v29;
      p_groupFade = (idArray<idSoundFade,25> *)((char *)p_groupFade + 16);
      v30 = __ROL4__(v30, 1);
    }
    while ( v29 < 25 );
    ((void (__fastcall *)(idConsole *, idOverlayHandle *, _DWORD, _DWORD, char *, double, double))console->PrintOverlay)(
      a1: console,
      a2: v83,
      a3: 1.0,
      a4: 1.0,
      a5: v80.data,
      a6: 1.0,
      a7: 1.0);
    idStr::FreeData(this: &v80);
  }
}


// ========================================================================
// __unwind$238309_0
// EA  : 0x82996F04
// RVA : 0x00996F04
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_238309_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4416 + 80));
}


// ========================================================================
// __unwind$238311
// EA  : 0x82996F2C
// RVA : 0x00996F2C
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_238311()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4416 + 128));
}


// ========================================================================
// ?PlayPositionedShaderDirectly@idSoundWorldLocal@@UAAHPBVidSoundShader@@ABVidVec3@@ABVidMat3@@M@Z
// EA  : 0x82996F58
// RVA : 0x00996F58
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

int __fastcall idSoundWorldLocal::PlayPositionedShaderDirectly(
        idSoundWorldLocal *this,
        const idSoundShader *shader,
        const idVec3 *pos,
        const idMat3 *axis,
        double volumeDb)
{
  idArray<listener_t,2> *BestListenerForEmitter; // r3
  soundShaderParms_t *p_parms; // r27
  float *p_x; // r26
  double v14; // fp9
  double v16; // fp6
  double v17; // fp2
  double v18; // fp12
  double v19; // fp29
  idSoundEmitter **positionedEmitters; // r31
  idSoundEmitter *v21; // r29
  int v22; // r30
  idSoundEmitter **v23; // r28
  double v26; // fp28
  double v27; // fp9
  int i; // r28
  float *v33; // r30
  float *v34; // r3
  float *v35; // r11
  double v37; // fp9
  double v39; // fp6
  double v40; // fp4
  double v41; // fp13
  double v42; // fp11
  double v45; // fp6
  soundShaderParms_t v50; // [sp+50h] [-120h] BYREF

  if ( s_noSound.valueInteger == 0 && !idLib::headless && s_playPositioned.valueInteger != 0 && shader != nullptr )
  {
    BestListenerForEmitter = idSoundWorldLocal::GetBestListenerForEmitter(this, emitterId: -1, emitterOrigin: pos);
    _FP13 = shader->parms.wetMaxDistanceOffset;
    p_x = &BestListenerForEmitter->ptr[0].pos.x;
    v14 = (float)(pos->z - BestListenerForEmitter->ptr[0].pos.z);
    __asm { fsel      f8, f13, f13, f31 }
    v16 = (float)(pos->y - BestListenerForEmitter->ptr[0].pos.y);
    v17 = (float)(pos->x - BestListenerForEmitter->ptr[0].pos.x);
    v18 = (float)((float)((float)_FP8 + shader->parms.maxDistance) * shader->parms.distanceFactor);
    v19 = (float)((float)((float)v17 * (float)v17)
                + (float)((float)((float)v16 * (float)v16) + (float)((float)v14 * (float)v14)));
    if ( v19 <= (float)((float)v18 * (float)v18) )
    {
      positionedEmitters = this->positionedEmitters;
      v21 = nullptr;
      v22 = 0;
      v23 = this->positionedEmitters;
      while ( (*v23)->IsCurrentlyPlaying(this: *v23, a2: SND_CHANNEL_VOICE) )
      {
        ++v22;
        ++v23;
        if ( v22 >= 32 )
          goto LABEL_11;
      }
      v21 = this->positionedEmitters[v22];
      if ( v21 != nullptr )
      {
LABEL_23:
        v21->Reset(this: v21);
        v21->UpdateEmitter(this: v21, a2: pos, a3: axis, a4: &vec3_origin, a5: 0);
        soundShaderParms_t::Clear(this: &v50);
        v50.volume.min = volumeDb;
        v50.volume.max = volumeDb;
        v50.soundChannel = SND_CHANNEL_VOICE;
        v50.soundShaderFlags = 0;
        return v21->StartSound(this: v21, a2: SND_CHANNEL_VOICE, a3: shader, a4: &v50);
      }
LABEL_11:
      _FP0 = shader->parms.wetMinDistanceOffset;
      __asm { fsel      f11, f0, f31, f0 }
      v26 = 0.0;
      v27 = (float)((float)((float)_FP11 + shader->parms.minDistance) * shader->parms.distanceFactor);
      if ( v19 > (float)((float)v27 * (float)v27) )
      {
        _FP11 = shader->parms.wetMaxDistanceOffset;
        __asm
        {
          fsel      f8, f0, f31, f0
          fsel      f4, f0, f30, f0
        }
        __asm { fsel      f3, f11, f11, f30 }
        p_parms = &shader->parms;
        v26 = (float)((float)-(float)((float)((float)((float)_FP4 + p_parms->minDistance) * p_parms->distanceFactor)
                                    - (float)__fsqrts(v19))
                    / (float)((float)((float)((float)_FP3 + p_parms->maxDistance) * p_parms->distanceFactor)
                            - (float)((float)((float)_FP8 + p_parms->minDistance) * p_parms->distanceFactor)));
      }
      for ( i = 32; i != 0; --i )
      {
        v33 = (float *)(*positionedEmitters)->GetCurrentSoundShader(this: *positionedEmitters, a2: SND_CHANNEL_VOICE);
        if ( v33 != nullptr )
        {
          v34 = (float *)(*positionedEmitters)->GetPosition(this: *positionedEmitters);
          v35 = v33 + 16;
          _FP10 = v33[20];
          v37 = 0.0;
          __asm { fsel      f13, f10, f10, f31 }
          v39 = (float)(v34[1] - p_x[1]);
          v40 = (float)(v34[2] - p_x[2]);
          v41 = (float)((float)((float)_FP13 + v33[17]) * v33[18]);
          v42 = (float)((float)((float)(*v34 - *p_x) * (float)(*v34 - *p_x))
                      + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39)));
          if ( v42 <= (float)((float)v41 * (float)v41) )
          {
            _FP0 = v33[19];
            __asm { fsel      f8, f0, f31, f0 }
            v45 = (float)((float)((float)_FP8 + *v35) * v33[18]);
            if ( v42 > (float)((float)v45 * (float)v45) )
            {
              __asm { fsel      f6, f0, f31, f0 }
              __asm { fsel      f2, f10, f10, f30 }
              __asm { fsel      f3, f0, f30, f0 }
              v37 = (float)((float)-(float)((float)((float)((float)_FP3 + *v35) * v33[18]) - (float)__fsqrts(v42))
                          / (float)((float)((float)((float)_FP2 + v33[17]) * v33[18])
                                  - (float)((float)((float)_FP6 + *v35) * v33[18])));
            }
          }
          else
          {
            v37 = 1.0;
          }
          if ( v37 > v26 )
          {
            v21 = *positionedEmitters;
            v26 = v37;
          }
        }
        ++positionedEmitters;
      }
      if ( v21 != nullptr )
        goto LABEL_23;
    }
  }
  return 0;
}


// ========================================================================
// ??1idSoundWorldLocal@@UAA@XZ
// EA  : 0x82997C90
// RVA : 0x00997C90
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::~idSoundWorldLocal(idSoundWorldLocal *this)
{
  void **p_routingParms; // r29
  int i; // r28
  int v4; // r26
  int v5; // r27
  idBlockAlloc<idSoundEmitterLocal,16,38>::element_t *v6; // r29
  int v7; // r8
  idSoundEmitterLocal **list; // r4
  float *v9; // r4
  soundEnvironment_t *v10; // r4
  idSoundWorldLocal::idDuckLayer *v11; // r4

  this->__vftable = (idSoundWorldLocal_vtbl *)&idSoundWorldLocal::`vftable';
  if ( soundSystemLocal.parallelJobList != nullptr )
    idParallelJobList::Wait(this: soundSystemLocal.parallelJobList);
  if ( soundSystemLocal.currentSoundWorld == this )
    soundSystemLocal.currentSoundWorld = nullptr;
  if ( soundSystemLocal.editorSoundWorld == this )
    soundSystemLocal.editorSoundWorld = nullptr;
  p_routingParms = (void **)&this->listeners.ptr[0].routingParms;
  for ( i = 2; i != 0; --i )
  {
    if ( *p_routingParms != nullptr )
    {
      idMem::Free(this: &mem, ptr: *((void **)*p_routingParms + 20), align: ALIGN_128);
      idMem::Free(this: &mem, ptr: *p_routingParms, align: ALIGN_128);
    }
    p_routingParms += 58;
  }
  v4 = 0;
  if ( this->emitters.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = (idBlockAlloc<idSoundEmitterLocal,16,38>::element_t *)this->emitters.list[v5];
      if ( v6 != nullptr )
      {
        ((void (__fastcall *)(idBlockAlloc<idSoundEmitterLocal,16,38>::element_t *, _DWORD))v6->data->channels.staticList[14])(
          a1: v6,
          a2: 0);
        v6->data = (idSoundEmitterLocal *)this->emitterAllocator.free;
        v7 = this->emitterAllocator.active - 1;
        this->emitterAllocator.free = v6;
        this->emitterAllocator.active = v7;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->emitters.num );
  }
  idBlockAlloc<idSoundEmitterLocal,16,38>::Shutdown(this: &this->emitterAllocator);
  idBlockAlloc<idSoundChannel,16,38>::Shutdown(this: &this->channelAllocator);
  this->renderWorld = nullptr;
  this->localSound = nullptr;
  this->tinnitusEmitter = nullptr;
  idBlockAlloc<idSoundChannel,16,38>::Shutdown(this: &this->channelAllocator);
  idBlockAlloc<idSoundEmitterLocal,16,38>::Shutdown(this: &this->emitterAllocator);
  if ( this->emitters.listStatic == 0 || this->emitters.listStatic == 2 )
  {
    list = this->emitters.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->emitters.list = nullptr;
    this->emitters.size = 0;
  }
  this->emitters.num = 0;
  `eh vector destructor iterator'(
    ptr: &this->listeners,
    size: 0xE8u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))listener_t::~listener_t);
  if ( this->doors.listStatic == 0 || this->doors.listStatic == 2 )
  {
    v9 = this->doors.list;
    if ( v9 != nullptr )
      idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
    this->doors.list = nullptr;
    this->doors.size = 0;
  }
  this->doors.num = 0;
  if ( this->environments.listStatic == 0 || this->environments.listStatic == 2 )
  {
    v10 = this->environments.list;
    if ( v10 != nullptr )
      idMem::Free(this: &mem, ptr: (void *)v10, align: ALIGN_16);
    this->environments.list = nullptr;
    this->environments.size = 0;
  }
  this->environments.num = 0;
  idSoundBSPFile::~idSoundBSPFile(this: (idGenGridModel *)&this->sbspFile);
  if ( this->ducks.listStatic == 0 || this->ducks.listStatic == 2 )
  {
    v11 = this->ducks.list;
    if ( v11 != nullptr )
      idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    this->ducks.list = nullptr;
    this->ducks.size = 0;
  }
  this->ducks.num = 0;
  this->__vftable = (idSoundWorldLocal_vtbl *)&idSoundWorld::`vftable';
}


// ========================================================================
// __unwind$240354
// EA  : 0x82997F0C
// RVA : 0x00997F0C
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_240354()
{
  int v0; // r12

  idSoundWorld::~idSoundWorld(this: *(idSoundWorld **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$240355
// EA  : 0x82997F34
// RVA : 0x00997F34
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_240355()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 420));
}


// ========================================================================
// __unwind$240356
// EA  : 0x82997F60
// RVA : 0x00997F60
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_240356()
{
  int v0; // r12

  idSoundBSPFile::~idSoundBSPFile(this: (idGenGridModel *)(*(_DWORD *)(v0 - 160 + 180) + 936));
}


// ========================================================================
// __unwind$240357
// EA  : 0x82997F8C
// RVA : 0x00997F8C
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_240357()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 1112));
}


// ========================================================================
// __unwind$240358
// EA  : 0x82997FB8
// RVA : 0x00997FB8
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_240358()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 1128));
}


// ========================================================================
// __unwind$240359
// EA  : 0x82997FE4
// RVA : 0x00997FE4
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_240359()
{
  int v0; // r12

  idArray<listener_t,2>::~idArray<listener_t,2>(this: (idArray<listener_t,2> *)(*(_DWORD *)(v0 - 160 + 180) + 1144));
}


// ========================================================================
// __unwind$240360
// EA  : 0x82998010
// RVA : 0x00998010
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_240360()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 1620));
}


// ========================================================================
// __unwind$240361
// EA  : 0x8299803C
// RVA : 0x0099803C
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_240361()
{
  int v0; // r12

  idBlockAlloc<idSoundEmitterLocal,16,38>::~idBlockAlloc<idSoundEmitterLocal,16,38>(this: (idBlockAlloc<idSoundEmitterLocal,16,38> *)(*(_DWORD *)(v0 - 160 + 180) + 1772));
}


// ========================================================================
// __unwind$240362
// EA  : 0x82998068
// RVA : 0x00998068
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_240362()
{
  int v0; // r12

  idBlockAlloc<idSoundChannel,16,38>::~idBlockAlloc<idSoundChannel,16,38>(this: (idBlockAlloc<idSoundChannel,16,38> *)(*(_DWORD *)(v0 - 160 + 180) + 1792));
}


// ========================================================================
// ?AllocSoundEmitter@idSoundWorldLocal@@UAAPAVidSoundEmitter@@XZ
// EA  : 0x82998098
// RVA : 0x00998098
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

idSoundEmitterLocal *__fastcall idSoundWorldLocal::AllocSoundEmitter(idSoundWorldLocal *this)
{
  idSoundEmitterLocal *v2; // r30
  int v3; // r3
  idSoundEmitterLocal *v5; // [sp+50h] [-20h] BYREF

  v2 = (idSoundEmitterLocal *)idBlockAlloc<idSoundEmitterLocal,16,38>::Alloc(this: &this->emitterAllocator);
  v5 = v2;
  v3 = idList<idAnimWebBlendTree *,5>::Append(
         this: (idList<enum encounterGroupRole_t,5> *)&this->emitters,
         obj: (const encounterGroupRole_t *)&v5);
  idSoundEmitterLocal::Init(this: v2, i: v3, sw: this);
  return v2;
}


// ========================================================================
// ?Duck@idSoundWorldLocal@@UAAXPBVidDeclDuck@@HHH@Z
// EA  : 0x829980F8
// RVA : 0x009980F8
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::Duck(
        idSoundWorldLocal *this,
        const idDeclDuck *decl,
        int fadeIn,
        int sustain,
        int fadeOut)
{
  int v10; // r3
  int num; // r7
  int v12; // r24
  int v13; // r26
  idSoundWorldLocal::idDuckLayer *list; // r8
  idStaticList<idSoundWorldLocal::idDuckLayer,4> *p_ducks; // r31
  int v16; // r9
  idSoundWorldLocal::idDuckLayer *v17; // r11
  char v18; // r10
  const idDeclDuck *v19; // r11
  int v20; // r30
  idSoundWorldLocal::idDuckLayer *v21; // r29
  double Volume; // fp1
  int v23; // r10
  int v24; // r11
  int v25; // r30
  int size; // r11
  int v27; // r10
  int v28; // r11
  int i; // ctr
  int v30; // r9
  int v31; // r4
  int v32; // r3
  int v33; // r11

  if ( decl != nullptr )
  {
    v10 = this->GetSoundTime(this);
    num = this->ducks.num;
    v12 = v10;
    v13 = 0;
    if ( num <= 0 )
      goto LABEL_15;
    list = this->ducks.list;
    p_ducks = &this->ducks;
    v16 = 0;
    while ( 1 )
    {
      v17 = &list[v16];
      if ( list[v16].endFadeStart < 0 || (v18 = 1, v10 < v17->endFadeEnd) )
        v18 = 0;
      if ( v18 != 0 )
        break;
      v19 = v17->decl;
      if ( v19 == decl || v19->layer == decl->layer )
        break;
      ++v13;
      ++v16;
      if ( v13 >= num )
        goto LABEL_15;
    }
    v20 = 0;
    do
    {
      v21 = p_ducks->list;
      Volume = idSoundWorldLocal::idDuckLayer::GetVolume(this: &p_ducks->list[v13], g: v20, currentTime: v12);
      v23 = 31 * v13 + v20++;
      v21->fromVolumes.ptr[v23] = Volume;
    }
    while ( v20 < 25 );
    if ( v13 == -1 )
    {
LABEL_15:
      v24 = this->ducks.num;
      if ( v24 == this->ducks.size )
      {
        idLib::Warning(fmt: "SoundWorld: Too many ducks in a row, could not add %s", decl->name.str);
        return;
      }
      v25 = v24 + 1;
      p_ducks = &this->ducks;
      v13 = this->ducks.num;
      if ( v24 + 1 <= this->ducks.size
        || (unsigned __int8)idList<idSoundWorldLocal::idDuckLayer,5>::Resize(this: &this->ducks, newsize: v24 + 1) != 0 )
      {
        size = this->ducks.size;
        if ( v25 < size )
          size = v25;
        this->ducks.num = size;
      }
      v27 = 31 * v13;
      v28 = 0;
      for ( i = 5; i != 0; --i )
      {
        v30 = v27 + v28;
        p_ducks->list->fromVolumes.ptr[v30] = 0.0;
        p_ducks->list->fromVolumes.ptr[v30 + 1] = 0.0;
        p_ducks->list[v27 / 0x1Fu].fromVolumes.ptr[v28 + 2] = 0.0;
        v31 = v27 + v28 + 3;
        v32 = 31 * v13 + 4 + v28;
        v28 += 5;
        p_ducks->list->fromVolumes.ptr[v31] = 0.0;
        p_ducks->list->fromVolumes.ptr[v32] = 0.0;
      }
    }
    v33 = v13;
    p_ducks->list[v13].decl = decl;
    p_ducks->list[v13].blendAlpha = -1.0;
    p_ducks->list[v13].startFadeStart = v12;
    p_ducks->list[v13].startFadeEnd = p_ducks->list[v13].startFadeStart + fadeIn;
    if ( sustain < 0 || fadeOut < 0 )
    {
      p_ducks->list[v33].endFadeStart = -1;
      p_ducks->list[v33].endFadeEnd = -1;
    }
    else
    {
      p_ducks->list[v33].endFadeStart = p_ducks->list[v33].startFadeEnd + sustain;
      p_ducks->list[v33].endFadeEnd = p_ducks->list[v33].endFadeStart + fadeOut;
    }
  }
}


// ========================================================================
// ?DuckBlend@idSoundWorldLocal@@UAAXPBVidDeclDuck@@M@Z
// EA  : 0x82998390
// RVA : 0x00998390
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::DuckBlend(idSoundWorldLocal *this, const idDeclDuck *decl, double alpha)
{
  int v6; // r3
  int num; // r8
  int v8; // r29
  idSoundWorldLocal::idDuckLayer *list; // r7
  idStaticList<idSoundWorldLocal::idDuckLayer,4> *p_ducks; // r31
  int v11; // r9
  idSoundWorldLocal::idDuckLayer *v12; // r11
  char v13; // r10
  const idDeclDuck *v14; // r11
  int v15; // r30
  int size; // r11
  int v17; // r11
  int v18; // r10
  int v19; // r11
  int i; // ctr
  int v21; // r9
  int v22; // r4
  int v23; // r3
  int v24; // r11

  if ( decl != nullptr )
  {
    v6 = this->GetSoundTime(this);
    num = this->ducks.num;
    v8 = 0;
    if ( num <= 0 )
      goto LABEL_13;
    list = this->ducks.list;
    p_ducks = &this->ducks;
    v11 = 0;
    while ( 1 )
    {
      v12 = &list[v11];
      if ( list[v11].endFadeStart < 0 || (v13 = 1, v6 < v12->endFadeEnd) )
        v13 = 0;
      if ( v13 != 0 )
        break;
      v14 = v12->decl;
      if ( v14 == decl || v14->layer == decl->layer )
        break;
      ++v8;
      ++v11;
      if ( v8 >= num )
        goto LABEL_13;
    }
    if ( v8 == -1 )
    {
LABEL_13:
      if ( num == this->ducks.size )
      {
        idLib::Warning(fmt: "SoundWorld: Too many ducks in a row, could not add %s", decl->name.str);
        return;
      }
      p_ducks = &this->ducks;
      v8 = this->ducks.num;
      size = this->ducks.size;
      v15 = num + 1;
      if ( num + 1 <= size
        || (unsigned __int8)idList<idSoundWorldLocal::idDuckLayer,5>::Resize(this: p_ducks, newsize: num + 1) != 0 )
      {
        v17 = p_ducks->size;
        if ( v15 < v17 )
          v17 = v15;
        p_ducks->num = v17;
      }
    }
    v18 = 31 * v8;
    v19 = 0;
    for ( i = 5; i != 0; --i )
    {
      v21 = v18 + v19;
      p_ducks->list->fromVolumes.ptr[v21] = 0.0;
      p_ducks->list->fromVolumes.ptr[v21 + 1] = 0.0;
      p_ducks->list[v18 / 0x1Fu].fromVolumes.ptr[v19 + 2] = 0.0;
      v22 = v18 + v19 + 3;
      v23 = 31 * v8 + 4 + v19;
      v19 += 5;
      p_ducks->list->fromVolumes.ptr[v22] = 0.0;
      p_ducks->list->fromVolumes.ptr[v23] = 0.0;
    }
    v24 = v8;
    p_ducks->list[v8].decl = decl;
    p_ducks->list[v8].startFadeStart = 0;
    p_ducks->list[v8].startFadeEnd = 0;
    if ( alpha >= 0.0 )
    {
      if ( alpha > 1.0 )
        alpha = 1.0;
      p_ducks->list[v24].endFadeStart = -1;
      p_ducks->list[v24].endFadeEnd = -1;
    }
    else
    {
      p_ducks->list[v24].endFadeStart = 0;
      p_ducks->list[v24].endFadeEnd = 0;
    }
    p_ducks->list[v24].blendAlpha = alpha;
  }
}


// ========================================================================
// ??0idSoundWorldLocal@@QAA@XZ
// EA  : 0x829988D8
// RVA : 0x009988D8
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

idSoundWorldLocal *__fastcall idSoundWorldLocal::idSoundWorldLocal(idSoundWorldLocal *this)
{
  idSoundFade *p_volumeFade; // r20
  int v3; // r29
  idArray<idSoundFade,25> *p_groupFade; // r28
  int size; // r22
  idList<soundEnvironment_t,38> *p_environments; // r26
  idList<float,38> *p_doors; // r24
  __int16 *p_granularity; // r11
  int i; // ctr
  idSoundEmitterLocal *v10; // r25
  int v11; // r3
  idSoundEmitter **p_tinnitusEmitter; // r23
  int j; // r25
  idSoundEmitterLocal *v14; // r21
  int v15; // r3
  idSoundEmitterLocal *v16; // r27
  int v17; // r3
  bfx::BinaryReplayLogOut *v18; // r3
  char *v19; // r3
  char v20; // r11
  int num; // r11
  float *list; // r4
  encounterGroupRole_t v24[36]; // [sp+50h] [-90h] BYREF

  p_volumeFade = &this->volumeFade;
  v24[0] = (encounterGroupRole_t)&this->volumeFade;
  this->__vftable = (idSoundWorldLocal_vtbl *)&idSoundWorldLocal::`vftable';
  v3 = 24;
  p_groupFade = &this->groupFade;
  idSoundFade::Clear(this: &this->volumeFade);
  do
  {
    idSoundFade::Clear(this: p_groupFade->ptr);
    --v3;
    p_groupFade = (idArray<idSoundFade,25> *)((char *)p_groupFade + 16);
  }
  while ( v3 >= 0 );
  size = 1;
  this->ducks.num = 0;
  this->ducks.granularity = 1;
  this->ducks.list = this->ducks.staticList;
  this->ducks.size = 4;
  this->ducks.memTag = 5;
  this->ducks.listStatic = 1;
  this->ducks.staticList[0].blendAlpha = -1.0;
  this->ducks.staticList[1].blendAlpha = -1.0;
  this->ducks.staticList[0].decl = nullptr;
  this->ducks.staticList[2].blendAlpha = -1.0;
  this->ducks.staticList[0].startFadeStart = 0;
  this->ducks.staticList[3].blendAlpha = -1.0;
  this->ducks.staticList[0].startFadeEnd = 0;
  this->ducks.staticList[0].endFadeStart = 0;
  this->ducks.staticList[0].endFadeEnd = 0;
  this->ducks.staticList[1].decl = nullptr;
  this->ducks.staticList[1].startFadeStart = 0;
  this->ducks.staticList[1].startFadeEnd = 0;
  this->ducks.staticList[1].endFadeStart = 0;
  this->ducks.staticList[1].endFadeEnd = 0;
  this->ducks.staticList[2].decl = nullptr;
  this->ducks.staticList[2].startFadeStart = 0;
  this->ducks.staticList[2].startFadeEnd = 0;
  this->ducks.staticList[2].endFadeStart = 0;
  this->ducks.staticList[2].endFadeEnd = 0;
  this->ducks.staticList[3].decl = nullptr;
  this->ducks.staticList[3].startFadeStart = 0;
  this->ducks.staticList[3].startFadeEnd = 0;
  this->ducks.staticList[3].endFadeStart = 0;
  this->ducks.staticList[3].endFadeEnd = 0;
  idSoundBSPFile::idSoundBSPFile(this: &this->sbspFile);
  this->environments.list = nullptr;
  p_environments = &this->environments;
  this->environments.granularity = 0;
  this->environments.memTag = 38;
  this->environments.listStatic = 0;
  this->environments.size = 0;
  this->environments.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->environments);
  this->doors.list = nullptr;
  this->doors.granularity = 0;
  p_doors = &this->doors;
  this->doors.memTag = 38;
  this->doors.listStatic = 0;
  this->doors.size = 0;
  this->doors.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->doors);
  `eh vector constructor iterator'(
    ptr: &this->listeners,
    size: 0xE8u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))listener_t::listener_t,
    pDtor: (void (__fastcall *)(void *))listener_t::~listener_t);
  this->emitters.list = nullptr;
  this->emitters.granularity = 0;
  this->emitters.memTag = 38;
  this->emitters.listStatic = 0;
  this->emitters.size = 0;
  this->emitters.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->emitters);
  this->emitterAllocator.blocks = nullptr;
  this->emitterAllocator.free = nullptr;
  this->emitterAllocator.total = 0;
  this->emitterAllocator.active = 0;
  this->emitterAllocator.allowAllocs = true;
  this->emitterAllocator.clearAllocs = false;
  this->channelAllocator.blocks = nullptr;
  this->channelAllocator.free = nullptr;
  this->channelAllocator.total = 0;
  this->channelAllocator.active = 0;
  this->channelAllocator.allowAllocs = true;
  this->channelAllocator.clearAllocs = false;
  v24[0] = (encounterGroupRole_t)&this->pauseFade;
  idSoundFade::Clear(this: &this->pauseFade);
  p_granularity = &this->doors.granularity;
  for ( i = 2; i != 0; --i )
  {
    *((_BYTE *)p_granularity + 4) = 0;
    *((_BYTE *)p_granularity + 5) = 0;
    *((float *)p_granularity + 10) = 1.0;
    *((float *)p_granularity + 6) = 1.0;
    *((float *)p_granularity + 2) = 1.0;
    *((float *)p_granularity + 7) = 0.0;
    *((float *)p_granularity + 4) = 0.0;
    *((float *)p_granularity + 3) = 0.0;
    *((float *)p_granularity + 9) = 0.0;
    *((float *)p_granularity + 8) = 0.0;
    *((float *)p_granularity + 5) = 0.0;
    *((float *)p_granularity + 13) = 0.0;
    *((float *)p_granularity + 12) = 0.0;
    *((float *)p_granularity + 11) = 0.0;
    *((float *)p_granularity + 16) = 0.0;
    *((float *)p_granularity + 15) = 0.0;
    *((float *)p_granularity + 14) = 0.0;
    *((_DWORD *)p_granularity + 17) = -1;
    *((float *)p_granularity + 19) = 0.0;
    *((_DWORD *)p_granularity + 18) = 0;
    *((float *)p_granularity + 20) = 0.0;
    *((_DWORD *)p_granularity + 57) = 0;
    *((float *)p_granularity + 21) = 0.0;
    *((float *)p_granularity + 22) = -60.0;
    p_granularity += 116;
    *(float *)p_granularity = 0.0;
  }
  v24[0] = (encounterGroupRole_t)&this->listeners;
  this->listeners.ptr[0].routingParms = (soundRoutingParms_t *)idMem::AllocWithLocation(
                                                                 this: &mem,
                                                                 location: "w:\\tech5\\engine\\sound\\SoundWorld.cpp(1705) : TAG_SOUND",
                                                                 size: 0x58u,
                                                                 tag: TAG_SOUND,
                                                                 zeroBuffer: false,
                                                                 align: ALIGN_128,
                                                                 heap: HEAP_DEFAULTHEAP);
  this->listeners.ptr[0].routingParms->temp = (unsigned __int8 *)idMem::AllocWithLocation(
                                                                   this: &mem,
                                                                   location: "w:\\tech5\\engine\\sound\\SoundWorld.cpp(1706) : TAG_SOUND",
                                                                   size: 0xF000u,
                                                                   tag: TAG_SOUND,
                                                                   zeroBuffer: false,
                                                                   align: ALIGN_128,
                                                                   heap: HEAP_DEFAULTHEAP);
  this->listeners.ptr[0].routingParms->tempSize = 61440;
  idSoundFade::Clear(this: p_volumeFade);
  this->currentCushionDB = -1032847360;
  this->numListeners = 1;
  this->listenerIndex = 0;
  v24[0] = (encounterGroupRole_t)idBlockAlloc<idSoundEmitterLocal,16,38>::Alloc(this: &this->emitterAllocator);
  v10 = (idSoundEmitterLocal *)v24[0];
  v11 = idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->emitters, obj: v24);
  idSoundEmitterLocal::Init(this: v10, i: v11, sw: this);
  this->localSound = v10;
  p_tinnitusEmitter = &this->tinnitusEmitter;
  for ( j = 32; j != 0; --j )
  {
    v24[0] = (encounterGroupRole_t)idBlockAlloc<idSoundEmitterLocal,16,38>::Alloc(this: &this->emitterAllocator);
    v14 = (idSoundEmitterLocal *)v24[0];
    v15 = idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->emitters, obj: v24);
    idSoundEmitterLocal::Init(this: v14, i: v15, sw: this);
    *++p_tinnitusEmitter = v14;
  }
  v24[0] = (encounterGroupRole_t)idBlockAlloc<idSoundEmitterLocal,16,38>::Alloc(this: &this->emitterAllocator);
  v16 = (idSoundEmitterLocal *)v24[0];
  v17 = idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->emitters, obj: v24);
  idSoundEmitterLocal::Init(this: v16, i: v17, sw: this);
  this->tinnitusEmitter = v16;
  if ( this->environments.size < 1 )
  {
    if ( this->environments.listStatic == 0 )
    {
      if ( this->environments.granularity == 1 )
        idPhysics_StaticMulti::UpdateTime(this: v18);
      v19 = idListArrayResize<soundEnvironment_t>(
              voldptr: p_environments->list,
              oldNum: this->environments.size,
              newNum: 1,
              tag: (memTag_t)this->environments.memTag,
              zeroBuffer: false);
      p_environments->list = (soundEnvironment_t *)v19;
      if ( v19 == nullptr )
      {
        v20 = 0;
        goto LABEL_16;
      }
      num = this->environments.num;
      this->environments.size = 1;
      if ( num > 1 )
        this->environments.num = 1;
    }
    v20 = 1;
LABEL_16:
    if ( v20 == 0 )
      goto LABEL_20;
  }
  if ( this->environments.size <= 1 )
    size = this->environments.size;
  this->environments.num = size;
LABEL_20:
  if ( this->doors.size < 0 )
  {
    if ( this->doors.listStatic == 0 || this->doors.listStatic == 2 )
    {
      list = p_doors->list;
      if ( p_doors->list != nullptr )
      {
        v24[0] = (encounterGroupRole_t)p_doors->list;
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      }
      p_doors->list = nullptr;
      this->doors.size = 0;
    }
    this->doors.num = 0;
  }
  this->doors.num = __CFADD__(-this->doors.size, this->doors.size ^ 0x80000000) ? 0 : this->doors.size;
  idSoundFade::Clear(this: &this->pauseFade);
  this->pausedTime = 0;
  this->accumulatedPauseTime = 0;
  this->isPaused = false;
  memset(Dst: &this->groupFade, Val: 0, Size: sizeof(this->groupFade));
  this->renderWorld = nullptr;
  return this;
}


// ========================================================================
// __unwind$241892
// EA  : 0x82998DB0
// RVA : 0x00998DB0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_241892()
{
  int v0; // r12

  idSoundWorld::~idSoundWorld(this: *(idSoundWorld **)(v0 - 224 + 244));
}


// ========================================================================
// __unwind$241893
// EA  : 0x82998DD8
// RVA : 0x00998DD8
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_241893()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 224 + 244) + 420));
}


// ========================================================================
// __unwind$241894
// EA  : 0x82998E04
// RVA : 0x00998E04
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_241894()
{
  int v0; // r12

  idSoundBSPFile::~idSoundBSPFile(this: (idGenGridModel *)(*(_DWORD *)(v0 - 224 + 244) + 936));
}


// ========================================================================
// __unwind$241895
// EA  : 0x82998E30
// RVA : 0x00998E30
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_241895()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 224 + 244) + 1112));
}


// ========================================================================
// __unwind$241896
// EA  : 0x82998E5C
// RVA : 0x00998E5C
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_241896()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 224 + 244) + 1128));
}


// ========================================================================
// __unwind$241897
// EA  : 0x82998E88
// RVA : 0x00998E88
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_241897()
{
  int v0; // r12

  idArray<listener_t,2>::~idArray<listener_t,2>(this: (idArray<listener_t,2> *)(*(_DWORD *)(v0 - 224 + 244) + 1144));
}


// ========================================================================
// __unwind$241898
// EA  : 0x82998EB4
// RVA : 0x00998EB4
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_241898()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 224 + 244) + 1620));
}


// ========================================================================
// __unwind$241899
// EA  : 0x82998EE0
// RVA : 0x00998EE0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_241899()
{
  int v0; // r12

  idBlockAlloc<idSoundEmitterLocal,16,38>::~idBlockAlloc<idSoundEmitterLocal,16,38>(this: (idBlockAlloc<idSoundEmitterLocal,16,38> *)(*(_DWORD *)(v0 - 224 + 244) + 1772));
}


// ========================================================================
// __unwind$241900
// EA  : 0x82998F0C
// RVA : 0x00998F0C
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_241900()
{
  int v0; // r12

  idBlockAlloc<idSoundChannel,16,38>::~idBlockAlloc<idSoundChannel,16,38>(this: (idBlockAlloc<idSoundChannel,16,38> *)(*(_DWORD *)(v0 - 224 + 244) + 1792));
}


// ========================================================================
// ?LoadMap@idSoundWorldLocal@@QAA_NPBD@Z
// EA  : 0x82998FA0
// RVA : 0x00998FA0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

int __fastcall idSoundWorldLocal::LoadMap(idSoundWorldLocal *this, const char *mapName)
{
  idSoundEmitter *tinnitusEmitter; // r3
  int numDoors; // r4
  float v7; // [sp+50h] [-F0h] BYREF
  idStr v8; // [sp+60h] [-E0h] BYREF
  soundShaderParms_t v9; // [sp+80h] [-C0h] BYREF

  if ( mapName != nullptr && *mapName != 0 )
  {
    soundShaderParms_t::Clear(this: &v9);
    tinnitusEmitter = this->tinnitusEmitter;
    v9.soundShaderFlags = SSF_AUTO_RESTART;
    tinnitusEmitter->StartSound(
      this: tinnitusEmitter,
      a2: SND_CHANNEL_VOICE,
      a3: (const idSoundShader *)tinnitusShader.r,
      a4: &v9);
    this->tinnitusEmitter->SetVolume(this: this->tinnitusEmitter, a2: SND_CHANNEL_VOICE, a3: -60.0);
    idStr::idStr(this: &v8, text: mapName);
    idStr::SetFileExtension(this: &v8, extension: "sbsp");
    if ( (unsigned __int8)idSoundBSPFile::Read(this: &this->sbspFile, filename: v8.data) == 0 )
    {
      idSoundBSPFile::Clear(this: &this->sbspFile);
      idList<soundEnvironment_t,38>::SetNum(this: &this->environments, newNum: 1);
      idList<float,5>::SetNum(this: (idList<float,5> *)&this->doors, newNum: 0);
      idStr::FreeData(this: &v8);
      return 0;
    }
    idList<soundEnvironment_t,38>::SetNum(this: &this->environments, newNum: this->sbspFile.numEnvironments);
    numDoors = this->sbspFile.numDoors;
    v7 = 0.0;
    idList<float,17>::SetNum(this: (idList<float,32> *)&this->doors, newNum: numDoors, initValue: &v7);
    idStr::FreeData(this: &v8);
  }
  else
  {
    idSoundBSPFile::Clear(this: &this->sbspFile);
    idList<soundEnvironment_t,38>::SetNum(this: &this->environments, newNum: 1);
    idList<float,5>::SetNum(this: (idList<float,5> *)&this->doors, newNum: 0);
  }
  return 1;
}


// ========================================================================
// __unwind$242559
// EA  : 0x829990EC
// RVA : 0x009990EC
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_242559()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 96));
}


// ========================================================================
// ?UpdateForListener@idSoundWorldLocal@@AAAXAAUlistener_t@@@Z
// EA  : 0x82999120
// RVA : 0x00999120
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSoundWorldLocal::UpdateForListener(idSoundWorldLocal *this, listener_t *listener)
{
  int v4; // r11
  int v5; // r10
  soundEnvironment_t *v6; // r9
  soundEnvironment_t *p_currentEnv; // r20
  int v8; // r3
  __int16 environment; // r10
  int v10; // r11
  double v11; // fp22
  double v12; // fp23
  float v13; // r26
  double v14; // fp24
  float v15; // r27
  double v16; // fp25
  float v17; // r28
  double v18; // fp27
  float v19; // r29
  double v20; // fp28
  double v21; // fp29
  double v22; // fp30
  double v23; // fp31
  int num; // r11
  encounterGroupRole_t *v25; // r11
  int v26; // r23
  int v27; // r6
  int v28; // r7
  breakableIsland_t *list; // r25
  int v30; // r24
  encounterGroupRole_t *v31; // r5
  int v32; // r28
  sbspArea_t *v33; // r10
  __int32 v34; // r27
  sbspArea_t *v35; // r11
  int v36; // r11
  int v37; // r4
  sbspFace_t *v38; // r11
  encounterGroupRole_t v39; // r8
  __int16 v40; // r9
  int v41; // r29
  int v42; // r10
  encounterGroupRole_t *v43; // r11
  char v44; // r9
  float *v45; // r11
  int v46; // r10
  double v47; // fp31
  breakableIsland_t *v48; // r11
  breakableIsland_t *v49; // r11
  int v50; // r11
  breakableIsland_t *v51; // r11
  _BYTE v52[12]; // r9 OVERLAPPED
  idGame *v53; // r3
  __int64 v54; // fp13
  double v55; // fp0
  double lowestPoint; // fp0
  float *p_lowestPoint; // r11
  int v58; // ctr
  int v59; // r9
  int v60; // r10
  breakableIsland_t *v61; // r11
  int v62; // r10
  double v63; // fp0
  float *v64; // r11
  int i; // ctr
  int *v66; // r11
  int j; // ctr
  int v68; // r9
  double v69; // fp0
  int v70; // r10
  soundEnvironment_t *v71; // r8
  int index; // r7
  double v73; // fp12
  double DryGain; // fp11
  soundEnvironment_t *v75; // r11
  __int64 v76; // r7
  int DecayTime; // r5
  __int128 v78; // r5
  int ReverbDelay; // r8
  double ReflectionsGain; // fp1
  double Diffusion; // fp7
  double ReverbGain; // fp9
  double HFReference; // fp5
  double Density; // fp6
  double v85; // fp26
  double v86; // fp0
  double v87; // fp9
  double RoomGain; // fp12
  double v89; // fp0
  double v90; // fp0
  double RoomHFGain; // fp12
  double v92; // fp0
  int v93; // r11
  double v94; // fp10
  double v95; // fp0
  int v96; // r10
  int DecayHFTime; // r11
  double v98; // fp0
  double v99; // fp11
  double v100; // fp0
  int ReflectionsDelay; // r11
  double v102; // fp0
  double v103; // fp11
  double v104; // fp0
  int v105; // r11
  double v106; // fp0
  double v107; // fp12
  double v108; // fp0
  double v109; // fp0
  double v110; // fp12
  double v111; // fp0
  double v112; // fp13
  double v113; // fp0
  int v114; // r9
  int v115; // r10
  soundEnvironment_t *v117; // r11
  double envBlendAlpha; // fp1
  __int64 v120; // r8
  __int64 v121; // r6
  int valueInteger; // r8
  int v123; // r27
  int v124; // r26
  int area; // r11
  sbspFace_t *v126; // r28
  int v127; // r29
  idRenderWorld *renderWorld; // r3
  int v129; // r25
  int v130; // r26
  sbspArea_t *v131; // r11
  int v132; // r27
  sbspFace_t *v133; // r10
  int v134; // r9
  sbspFace_t *v135; // r28
  int v136; // r29
  idRenderWorld *v137; // r3
  int v138; // r24
  int v139; // r25
  sbspArea_t *v140; // r11
  sbspFace_t *v141; // r28
  sbspArea_t *v142; // r27
  sbspArea_t *v143; // r26
  int v144; // r29
  int v145; // r28
  int size; // r11
  soundRoutingParms_t *routingParms; // r11
  int v148; // [sp+54h] [-39Ch]
  int v149; // [sp+54h] [-39Ch]
  int v150; // [sp+54h] [-39Ch]
  int v151; // [sp+58h] [-398h] BYREF
  float v152[15]; // [sp+60h] [-390h] BYREF
  idWinding v153; // [sp+A0h] [-350h] BYREF
  encounterGroupRole_t v154[4]; // [sp+B0h] [-340h] BYREF
  idWinding v155; // [sp+C0h] [-330h] BYREF
  idWinding v156; // [sp+D0h] [-320h] BYREF
  float v157[4]; // [sp+E0h] [-310h] BYREF
  float v158[4]; // [sp+F0h] [-300h] BYREF
  float v159[4]; // [sp+100h] [-2F0h] BYREF
  soundEnvironment_t v160; // [sp+110h] [-2E0h] BYREF
  __int64 v161; // [sp+150h] [-2A0h]
  unsigned __int64 v162; // [sp+158h] [-298h]
  __int64 v163; // [sp+160h] [-290h]
  idList<enum encounterGroupRole_t,5> v164; // [sp+170h] [-280h] BYREF
  int v165; // [sp+180h] [-270h] BYREF
  idList<breakableIsland_t,59> v166; // [sp+200h] [-1F0h] BYREF
  int v167; // [sp+210h] [-1E0h] BYREF

  if ( listener->routingParms == nullptr )
    idSoundWorldLocal::AllocRouting(this, listener);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&soundSystemLocal.hardware);
  v4 = 0;
  if ( this->environments.num > 0 )
  {
    v5 = 0;
    do
    {
      ++v4;
      v6 = &this->environments.list[v5++];
      v6->desiredVolume = 0.0;
    }
    while ( v4 < this->environments.num );
  }
  p_currentEnv = &listener->currentEnv;
  memcpy(Dst: v152, Src: &listener->currentEnv, Size: sizeof(v152));
  v8 = idSoundBSPFile::PointAreaNum(this: &this->sbspFile, point: &listener->pos);
  listener->area = v8;
  environment = this->sbspFile.areas.list[v8].environment;
  if ( environment >= 0 )
  {
    v154[0] = environment;
    v10 = environment;
    v11 = 1.0;
    this->environments.list[v10].desiredVolume = 1.0;
    memcpy(Dst: v152, Src: &this->environments.list[v10], Size: sizeof(v152));
    v12 = v152[11];
    v13 = v152[8];
    v14 = v152[10];
    v15 = v152[7];
    v16 = v152[9];
    v17 = v152[4];
    v18 = v152[6];
    v19 = v152[3];
    v20 = v152[5];
    v21 = v152[2];
    v22 = v152[1];
    v23 = v152[0];
    goto LABEL_55;
  }
  v166.num = 0;
  v166.granularity = 1;
  v166.size = 32;
  v166.memTag = 5;
  v166.list = (breakableIsland_t *)&v167;
  v166.listStatic = 1;
  v164.size = 32;
  v164.num = 0;
  v164.granularity = 1;
  v164.list = (encounterGroupRole_t *)&v165;
  v164.memTag = 5;
  v164.listStatic = 1;
  idList<idMD6Node *,5>::PreAllocateWithGranularity(this: (idList<idMD6Filter *,5> *)&v164, newSize: 1);
  num = v164.num;
  if ( v164.num >= v164.size )
  {
    v25 = &v164.list[v164.size - 1];
  }
  else
  {
    ++v164.num;
    v25 = &v164.list[num];
  }
  v26 = 0;
  *v25 = (encounterGroupRole_t)listener->area;
  v27 = v164.num;
  v28 = v166.num;
  list = v166.list;
  if ( v164.num > 0 )
  {
    v30 = 0;
    while ( 1 )
    {
      v31 = v164.list;
      v32 = 0;
      v33 = this->sbspFile.areas.list;
      v34 = v164.list[v30];
      v35 = &v33[v34];
      if ( v33[v34].numFaces != 0 )
        break;
LABEL_40:
      ++v26;
      ++v30;
      if ( v26 >= v27 )
        goto LABEL_41;
    }
    while ( 1 )
    {
      v36 = this->sbspFile.faceIndex.list[v35->firstFace + v32];
      v37 = (v36 >= 0) + 6;
      v38 = &this->sbspFile.faces.list[abs32(v36)];
      v39 = abs16(v38->center[v37]);
      v154[0] = v39;
      v40 = v33[v39].environment;
      v41 = v40;
      if ( v40 == 0 )
        goto LABEL_39;
      if ( v40 >= 0 )
      {
        v44 = 0;
        v45 = (float *)((char *)&this->sbspFile.planes.list->a + __ROL4__(v38->planeNum, 4));
        v46 = 0;
        v47 = __fabs((float)((float)((float)(*v45 * listener->pos.x)
                                   + (float)((float)(listener->pos.z * v45[2]) + (float)(listener->pos.y * v45[1])))
                           + v45[3]));
        if ( v28 > 0 )
        {
          v48 = list;
          while ( v48->index != v41 )
          {
            ++v46;
            ++v48;
            if ( v46 >= v28 )
              goto LABEL_33;
          }
          v49 = &list[v46];
          if ( v49->lowestPoint > v47 )
          {
            v49->lowestPoint = v47;
            v28 = v166.num;
            v27 = v164.num;
            list = v166.list;
          }
          v44 = 1;
        }
LABEL_33:
        if ( v44 == 0 )
        {
          idList<cockpitSeatInfo_t,5>::PreAllocateWithGranularity(this: &v166, newSize: v28 + 1);
          v50 = v166.num;
          if ( v166.num >= v166.size )
          {
            v51 = &v166.list[v166.size - 1];
          }
          else
          {
            ++v166.num;
            v51 = &v166.list[v50];
          }
          v51->lowestPoint = v47;
          v51->index = v41;
          goto LABEL_38;
        }
      }
      else
      {
        v42 = 0;
        if ( v27 <= 0 )
          goto LABEL_22;
        v43 = v31;
        while ( *v43 != v39 )
        {
          ++v42;
          ++v43;
          if ( v42 >= v27 )
            goto LABEL_22;
        }
        if ( v42 < 0 )
        {
LABEL_22:
          idList<idAnimWebBlendTree *,5>::Append(this: &v164, obj: v154);
LABEL_38:
          v27 = v164.num;
          list = v166.list;
          v28 = v166.num;
        }
      }
LABEL_39:
      v33 = this->sbspFile.areas.list;
      ++v32;
      v35 = &v33[v34];
      if ( v32 >= v33[v34].numFaces )
        goto LABEL_40;
      v31 = v164.list;
    }
  }
LABEL_41:
  v11 = 1.0;
  if ( v28 == 1 )
  {
    memcpy(Dst: v152, Src: &this->environments.list[list->index], Size: sizeof(v152));
  }
  else
  {
    lowestPoint = list->lowestPoint;
    if ( v28 > 1 )
    {
      p_lowestPoint = &list[1].lowestPoint;
      v58 = v28 - 1;
      do
      {
        if ( lowestPoint > *p_lowestPoint )
          lowestPoint = *p_lowestPoint;
        p_lowestPoint += 2;
        --v58;
      }
      while ( v58 != 0 );
    }
    v59 = 0;
    if ( lowestPoint == 0.0 )
    {
      if ( v28 > 0 )
      {
        v60 = 0;
        do
        {
          v61 = &list[v60];
          if ( list[v60].lowestPoint == 0.0 )
            v61->lowestPoint = 1.0;
          else
            v61->lowestPoint = 0.0;
          v28 = v166.num;
          ++v59;
          list = v166.list;
          ++v60;
        }
        while ( v59 < v166.num );
      }
    }
    else if ( v28 > 0 )
    {
      v62 = 0;
      do
      {
        ++v59;
        list[v62].lowestPoint = (float)lowestPoint / list[v62].lowestPoint;
        ++v62;
        list = v166.list;
        v28 = v166.num;
      }
      while ( v59 < v166.num );
    }
    v63 = 0.0;
    if ( v28 > 0 )
    {
      v64 = &list[-1].lowestPoint;
      for ( i = v28; i != 0; --i )
      {
        v64 += 2;
        v63 = (float)(*v64 + (float)v63);
      }
    }
    v66 = &v151;
    for ( j = 7; j != 0; --j )
    {
      v66 += 2;
      *(_QWORD *)v66 = 0x700000000LL;
    }
    v66[2] = 0;
    v68 = 0;
    if ( v28 > 0 )
    {
      v12 = v152[11];
      v13 = v152[8];
      v14 = v152[10];
      v15 = v152[7];
      v16 = v152[9];
      v17 = v152[4];
      v18 = v152[6];
      v19 = v152[3];
      v20 = v152[5];
      v69 = (float)((float)1.0 / (float)v63);
      v21 = v152[2];
      v70 = 0;
      v22 = v152[1];
      v23 = v152[0];
      do
      {
        v71 = this->environments.list;
        ++v68;
        index = list[v70].index;
        v73 = (float)(list[v70].lowestPoint * (float)v69);
        DryGain = v71[index].DryGain;
        v75 = &v71[index];
        HIDWORD(v76) = v71[index].ReflectionsDelay;
        DecayTime = v71[index].DecayTime;
        v21 = (float)((float)(v71[index].RoomHFGain * (float)(list[v70++].lowestPoint * (float)v69)) + (float)v21);
        DWORD2(v78) = HIDWORD(v76);
        ReverbDelay = v71[index].ReverbDelay;
        LODWORD(v76) = DecayTime;
        DWORD1(v78) = v75->DecayHFTime;
        *(_QWORD *)v154 = *(_QWORD *)((char *)&v78 + 4);
        v161 = v76;
        LODWORD(v78) = ReverbDelay;
        v22 = (float)((float)(v75->RoomGain * (float)v73) + (float)v22);
        v163 = v78;
        v162 = __PAIR64__(ReverbDelay, DWORD1(v78));
        ReflectionsGain = v75->ReflectionsGain;
        Diffusion = v75->Diffusion;
        ReverbGain = v75->ReverbGain;
        HFReference = v75->HFReference;
        Density = v75->Density;
        v23 = (float)((float)((float)DryGain * (float)v73) + (float)v23);
        v75->desiredVolume = v73;
        v20 = (float)((float)((float)ReflectionsGain * (float)v73) + (float)v20);
        v16 = (float)((float)((float)Diffusion * (float)v73) + (float)v16);
        list = v166.list;
        v18 = (float)((float)((float)ReverbGain * (float)v73) + (float)v18);
        v14 = (float)((float)((float)Density * (float)v73) + (float)v14);
        v12 = (float)((float)((float)HFReference * (float)v73) + (float)v12);
        LODWORD(v17) += (int)(float)((float)__SPAIR64__(ReverbDelay, DWORD1(v78)) * (float)v73);
        LODWORD(v15) += (int)(float)((float)*(__int64 *)((char *)&v78 + 4) * (float)v73);
        LODWORD(v19) += (int)(float)((float)v76 * (float)v73);
        LODWORD(v13) += (int)(float)((float)(__int64)v78 * (float)v73);
      }
      while ( v68 < v166.num );
      v152[11] = v12;
      v152[8] = v13;
      v152[10] = v14;
      v152[7] = v15;
      v152[9] = v16;
      v152[4] = v17;
      v152[6] = v18;
      v152[3] = v19;
      v152[5] = v20;
      v152[2] = v21;
      v152[1] = v22;
      v152[0] = v23;
      goto LABEL_44;
    }
  }
  v23 = v152[0];
  v19 = v152[3];
  v22 = v152[1];
  v17 = v152[4];
  v21 = v152[2];
  v15 = v152[7];
  v20 = v152[5];
  v13 = v152[8];
  v18 = v152[6];
  v16 = v152[9];
  v14 = v152[10];
  v12 = v152[11];
LABEL_44:
  if ( v164.listStatic == 0 || v164.listStatic == 2 )
  {
    if ( v164.list != nullptr )
    {
      idMem::Free(this: &mem, ptr: v164.list, align: ALIGN_16);
      list = v166.list;
    }
    v164.list = nullptr;
    v164.size = 0;
  }
  v164.num = 0;
  if ( v166.listStatic == 0 || v166.listStatic == 2 )
  {
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    v166.list = nullptr;
    v166.size = 0;
  }
  v166.num = 0;
LABEL_55:
  if ( common->Game(this: common) != nullptr )
  {
    v53 = common->Game(this: common);
    *(_QWORD *)&v52[8] = __PAIR64__(&off_82040000, v53->GetGameHz(this: v53, a2: GAMETIME_SCALED));
    v54 = *(_QWORD *)&v52[8];
    v55 = 0.001;
  }
  else
  {
    v55 = 0.001;
    *(_DWORD *)&v52[8] = timeManager.gameHz;
    v54 = *(_QWORD *)&v52[4];
  }
  v85 = (float)((float)v54 * (float)v55);
  if ( listener->environmentValid )
  {
    v86 = (float)((float)v23 - p_currentEnv->DryGain);
    v87 = (float)((float)v85 * (float)6.0);
    if ( v86 >= -v87 )
    {
      if ( v86 > v87 )
        v86 = (float)((float)v85 * (float)6.0);
    }
    else
    {
      v86 = -v87;
    }
    RoomGain = listener->currentEnv.RoomGain;
    p_currentEnv->DryGain = p_currentEnv->DryGain + (float)v86;
    v89 = (float)((float)v22 - (float)RoomGain);
    if ( v89 >= -v87 )
    {
      if ( v89 > v87 )
        v89 = (float)((float)v85 * (float)6.0);
    }
    else
    {
      v89 = -v87;
    }
    v90 = (float)((float)RoomGain + (float)v89);
    RoomHFGain = listener->currentEnv.RoomHFGain;
    listener->currentEnv.RoomGain = v90;
    v92 = (float)((float)v21 - (float)RoomHFGain);
    if ( v92 >= -v87 )
    {
      if ( v92 > v87 )
        v92 = (float)((float)v85 * (float)6.0);
    }
    else
    {
      v92 = -v87;
    }
    v93 = listener->currentEnv.DecayTime;
    listener->currentEnv.RoomHFGain = (float)v92 + (float)RoomHFGain;
    *(_DWORD *)&v52[4] = LODWORD(v19) - v93;
    v94 = (float)((float)v85 * (float)100.0);
    v95 = (float)*(__int64 *)v52;
    if ( v95 >= -v94 )
    {
      if ( v95 > v94 )
        v95 = (float)((float)v85 * (float)100.0);
    }
    else
    {
      v95 = -v94;
    }
    v96 = (int)v95 + v93;
    DecayHFTime = listener->currentEnv.DecayHFTime;
    listener->currentEnv.DecayTime = v96;
    *(_DWORD *)&v52[4] = LODWORD(v17) - DecayHFTime;
    v98 = (float)*(__int64 *)v52;
    if ( v98 >= -v94 )
    {
      if ( v98 > v94 )
        v98 = (float)((float)v85 * (float)100.0);
    }
    else
    {
      v98 = -v94;
    }
    v148 = (int)v98;
    v99 = listener->currentEnv.ReflectionsGain;
    v100 = (float)((float)v20 - listener->currentEnv.ReflectionsGain);
    listener->currentEnv.DecayHFTime = v148 + DecayHFTime;
    if ( v100 >= -v87 )
    {
      if ( v100 > v87 )
        v100 = (float)((float)v85 * (float)6.0);
    }
    else
    {
      v100 = -v87;
    }
    ReflectionsDelay = listener->currentEnv.ReflectionsDelay;
    listener->currentEnv.ReflectionsGain = (float)v100 + (float)v99;
    *(_DWORD *)&v52[8] = LODWORD(v15) - ReflectionsDelay;
    v102 = (float)*(__int64 *)&v52[4];
    if ( v102 >= -v94 )
    {
      if ( v102 > v94 )
        v102 = (float)((float)v85 * (float)100.0);
    }
    else
    {
      v102 = -v94;
    }
    v149 = (int)v102;
    v103 = listener->currentEnv.ReverbGain;
    v104 = (float)((float)v18 - listener->currentEnv.ReverbGain);
    listener->currentEnv.ReflectionsDelay = v149 + ReflectionsDelay;
    if ( v104 >= -v87 )
    {
      if ( v104 > v87 )
        v104 = (float)((float)v85 * (float)6.0);
    }
    else
    {
      v104 = -v87;
    }
    v105 = listener->currentEnv.ReverbDelay;
    listener->currentEnv.ReverbGain = (float)v104 + (float)v103;
    *(_DWORD *)&v52[8] = LODWORD(v13) - v105;
    v106 = (float)*(__int64 *)&v52[4];
    if ( v106 >= -v94 )
    {
      if ( v106 > v94 )
        v106 = (float)((float)v85 * (float)100.0);
    }
    else
    {
      v106 = -v94;
    }
    v150 = (int)v106;
    v107 = listener->currentEnv.Diffusion;
    v108 = (float)((float)v16 - listener->currentEnv.Diffusion);
    listener->currentEnv.ReverbDelay = v150 + v105;
    if ( v108 >= -v85 )
    {
      if ( v108 > v85 )
        v108 = v85;
    }
    else
    {
      v108 = -v85;
    }
    v109 = (float)((float)v108 + (float)v107);
    v110 = listener->currentEnv.Density;
    listener->currentEnv.Diffusion = v109;
    v111 = (float)((float)v14 - (float)v110);
    if ( v111 >= -v85 )
    {
      if ( v111 > v85 )
        v111 = v85;
    }
    else
    {
      v111 = -v85;
    }
    listener->currentEnv.Density = (float)v111 + (float)v110;
    v112 = (float)((float)v12 - listener->currentEnv.HFReference);
    v113 = (float)((float)v85 * (float)1000.0);
    if ( v112 >= -v113 )
    {
      if ( v112 <= v113 )
        v113 = (float)((float)v12 - listener->currentEnv.HFReference);
      listener->currentEnv.HFReference = (float)v113 + listener->currentEnv.HFReference;
    }
    else
    {
      listener->currentEnv.HFReference = (float)-v113 + listener->currentEnv.HFReference;
    }
  }
  else
  {
    memcpy(Dst: (void *)&listener->currentEnv, Src: v152, Size: sizeof(listener->currentEnv));
    listener->environmentValid = true;
  }
  v114 = 0;
  if ( this->environments.num > 0 )
  {
    v115 = 0;
    do
    {
      _FP12 = (float)((float)0.1 - s_environmentalFadeTime.valueFloat);
      ++v114;
      v117 = &this->environments.list[v115++];
      __asm { fsel      f8, f12, f13, f0 }
      v117->currentVolume = (float)((float)((float)(v117->desiredVolume - v117->currentVolume) / (float)_FP8)
                                  * (float)v85)
                          + v117->currentVolume;
    }
    while ( v114 < this->environments.num );
  }
  envBlendAlpha = listener->envBlendAlpha;
  v160.DryGain = 0.0;
  v160.RoomHFGain = 0.0;
  LODWORD(v120) = 200;
  v160.Diffusion = v11;
  LODWORD(v121) = 20;
  v160.Density = v11;
  HIDWORD(v120) = &v160;
  HIDWORD(v121) = &listener->environment;
  v160.RoomGain = -60.0;
  v160.ReflectionsGain = -60.0;
  v160.ReverbGain = -60.0;
  v160.HFReference = 5000.0;
  v160.DecayTime = 100;
  v160.currentVolume = 0.0;
  v160.DecayHFTime = 200;
  v160.desiredVolume = 0.0;
  v160.ReflectionsDelay = 20;
  v160.ReverbDelay = 40;
  v160.SoundEnvType = SET_DEFAULT;
  idSoundWorldLocal::BlendEnv(this, from: &listener->currentEnv, cur: v121, alpha: envBlendAlpha, a5: v120);
  idSoundHardware_XAudio2::SetReverb(this: &soundSystemLocal.hardware, parms: &v160);
  if ( this->renderWorld != nullptr )
  {
    valueInteger = s_showAreas.valueInteger;
    if ( s_showAreas.valueInteger != 0 )
    {
      v123 = 0;
      if ( this->sbspFile.faces.num > 0 )
      {
        v124 = 0;
        do
        {
          area = listener->area;
          v126 = &this->sbspFile.faces.list[v124];
          if ( v123 == area
            || abs16(v126->faceAreas[0]) == area
            || abs16(v126->faceAreas[1]) == area
            || valueInteger <= 1 )
          {
            v156.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
            memset(&v156.numPoints, 0, 12);
            v127 = 0;
            if ( v126->numVerts != 0 )
            {
              do
                idWinding::AddPoint(
                  this: &v156,
                  v: &this->sbspFile.vertices.list[this->sbspFile.vertIndex.list[v126->firstVert + v127++]]);
              while ( v127 < v126->numVerts );
            }
            v158[2] = 0.0;
            renderWorld = this->renderWorld;
            v158[3] = v11;
            v158[1] = v11;
            v158[0] = v11;
            renderWorld->DebugWinding(
              this: renderWorld,
              a2: (const idVec4 *)v158,
              a3: &v156,
              a4: &vec3_origin,
              a5: &mat3_identity,
              a6: 0,
              a7: false);
            v156.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
            idMem::Free(this: &mem, ptr: v156.p, align: ALIGN_16);
            valueInteger = s_showAreas.valueInteger;
            v156.p = nullptr;
          }
          ++v123;
          ++v124;
        }
        while ( v123 < this->sbspFile.faces.num );
      }
    }
    if ( s_showBigAreas.valueInteger != 0 )
    {
      v129 = 0;
      if ( this->sbspFile.areas.num > 0 )
      {
        v130 = 0;
        do
        {
          v131 = this->sbspFile.areas.list;
          if ( v131[v130].numFaces >= 0x80u )
          {
            v132 = 0;
            if ( v131[v130].numFaces != 0 )
            {
              do
              {
                v133 = this->sbspFile.faces.list;
                v134 = this->sbspFile.faceIndex.list[v131[v130].firstFace + v132];
                v155.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
                memset(&v155.numPoints, 0, 12);
                v135 = &v133[abs32(v134)];
                v136 = 0;
                if ( v135->numVerts != 0 )
                {
                  do
                    idWinding::AddPoint(
                      this: &v155,
                      v: &this->sbspFile.vertices.list[this->sbspFile.vertIndex.list[v135->firstVert + v136++]]);
                  while ( v136 < v135->numVerts );
                }
                v159[0] = v11;
                v137 = this->renderWorld;
                v159[3] = v11;
                v159[2] = 0.0;
                v159[1] = 0.0;
                v137->DebugWinding(
                  this: v137,
                  a2: (const idVec4 *)v159,
                  a3: &v155,
                  a4: &vec3_origin,
                  a5: &mat3_identity,
                  a6: 0,
                  a7: false);
                v155.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
                idMem::Free(this: &mem, ptr: v155.p, align: ALIGN_16);
                v131 = this->sbspFile.areas.list;
                ++v132;
                v155.p = nullptr;
              }
              while ( v132 < v131[v130].numFaces );
            }
          }
          ++v129;
          ++v130;
        }
        while ( v129 < this->sbspFile.areas.num );
      }
    }
    if ( s_showPortals.valueInteger != 0 )
    {
      v138 = 0;
      if ( this->sbspFile.faces.num > 0 )
      {
        v139 = 0;
        do
        {
          v140 = this->sbspFile.areas.list;
          v141 = &this->sbspFile.faces.list[v139];
          v142 = &v140[abs16(v141->faceAreas[0])];
          v143 = &v140[abs16(v141->faceAreas[1])];
          if ( v142->environment != v143->environment || v142->door != v143->door )
          {
            v153.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
            memset(&v153.numPoints, 0, 12);
            v144 = 0;
            if ( v141->numVerts != 0 )
            {
              do
                idWinding::AddPoint(
                  this: &v153,
                  v: &this->sbspFile.vertices.list[this->sbspFile.vertIndex.list[v141->firstVert + v144++]]);
              while ( v144 < v141->numVerts );
            }
            v157[0] = 0.0;
            v157[2] = 0.0;
            v157[1] = 0.0;
            v157[3] = 0.25;
            if ( v142->environment != v143->environment )
              v157[1] = v11;
            if ( v142->door != v143->door )
              v157[2] = v11;
            this->renderWorld->DebugFilledPolygon(
              this: this->renderWorld,
              a2: (const idVec4 *)v157,
              a3: &v153,
              a4: 0,
              a5: true);
            idWinding::ReverseSelf(this: &v153);
            this->renderWorld->DebugFilledPolygon(
              this: this->renderWorld,
              a2: (const idVec4 *)v157,
              a3: &v153,
              a4: 0,
              a5: true);
            v153.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
            idMem::Free(this: &mem, ptr: v153.p, align: ALIGN_16);
            v153.p = nullptr;
          }
          ++v138;
          ++v139;
        }
        while ( v138 < this->sbspFile.faces.num );
      }
    }
  }
  v145 = this->sbspFile.areas.num;
  if ( v145 <= listener->route.size
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                          this: (idList<idSpawnArea::GeneratedPosition *,5> *)&listener->route,
                          newsize: this->sbspFile.areas.num) != 0 )
  {
    size = listener->route.size;
    if ( v145 < size )
      size = v145;
    listener->route.num = size;
  }
  listener->routingParms->route = listener->route.list;
  memcpy(
    Dst: &listener->routingParms->flatBSP,
    Src: &this->sbspFile.flatBSP,
    Size: sizeof(listener->routingParms->flatBSP));
  listener->routingParms->numAreas = this->sbspFile.areas.num;
  listener->routingParms->listenerAreaNum = listener->area;
  routingParms = listener->routingParms;
  routingParms->listenerOrigin.x = listener->pos.x;
  routingParms->listenerOrigin.y = listener->pos.y;
  routingParms->listenerOrigin.z = listener->pos.z;
  if ( s_showPaths.valueInteger == 0 && s_useSoundOcclusionJobs.valueInteger == 1 )
    idParallelJobList::AddJob(
      this: soundSystemLocal.parallelJobList,
      function: (void (__fastcall *)(void *))SoundRoutingJob,
      data: listener->routingParms);
  else
    SoundRoutingJob(parms: listener->routingParms);
}


// ========================================================================
// __unwind$242602
// EA  : 0x8299A268
// RVA : 0x0099A268
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_242602()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1008 + 512));
}


// ========================================================================
// __unwind$242603
// EA  : 0x8299A290
// RVA : 0x0099A290
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_242603()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1008 + 368));
}


// ========================================================================
// __unwind$242604
// EA  : 0x8299A2B8
// RVA : 0x0099A2B8
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_242604()
{
  int v0; // r12

  idWinding::~idWinding(this: (idWinding *)(v0 - 1008 + 208));
}


// ========================================================================
// __unwind$242605
// EA  : 0x8299A2E0
// RVA : 0x0099A2E0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_242605()
{
  int v0; // r12

  idWinding::~idWinding(this: (idWinding *)(v0 - 1008 + 192));
}


// ========================================================================
// __unwind$242606
// EA  : 0x8299A308
// RVA : 0x0099A308
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_242606()
{
  int v0; // r12

  idWinding::~idWinding(this: (idWinding *)(v0 - 1008 + 160));
}


// ========================================================================
// ?Update@idSoundWorldLocal@@QAAXXZ
// EA  : 0x8299A418
// RVA : 0x0099A418
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall idSoundWorldLocal::Update(idSoundWorldLocal *this)
{
  idSoundWorldLocal *v1; // r14
  int num; // r30
  int v3; // r29
  int v4; // r3
  __int64 v5; // r8
  idGame *v6; // r3
  double v7; // fp29
  int v8; // r3
  __int64 v9; // r9
  double v10; // fp27
  double v11; // fp26
  idParallelJobList *parallelJobList; // r27
  int v13; // r24
  int v14; // r29
  listener_t *ptr; // r30
  int v16; // ctr
  __int16 *p_granularity; // r11
  int numListeners; // r9
  int v19; // r15
  int v20; // r11
  float *p_size; // r10
  idActiveChannel *v22; // r8
  int v23; // r7
  __int64 v24; // r6
  int v25; // r3
  int free; // r9
  int v27; // r28
  int v28; // r18
  idList<idSpawnArea::GeneratedPosition *,5> *p_emitters; // r26
  int v30; // r25
  char v33; // r3
  idSpawnArea::GeneratedPosition **list; // r11
  idBlockAlloc<idSoundEmitterLocal,16,38>::element_t *v35; // r30
  int v36; // r30
  int size; // r11
  idSpawnArea::GeneratedPosition **v38; // r30
  const idVec3 *v39; // r3
  idArray<listener_t,2> *BestListenerForEmitter; // r30
  double v41; // fp1
  int v43; // r23
  idSoundChannel *v45; // r29
  __int64 v46; // r11
  const char *v47; // r30
  const char *str; // r28
  int v49; // r4
  const idSoundShader *soundShader; // r11
  double v51; // fp0
  idSoundSample *sample; // r8
  double v53; // fp12
  int v54; // r5
  int numChannels; // r30
  int *p_sortKey; // r11
  const char *v57; // r30
  const char *v58; // r28
  int v59; // r4
  int v60; // r30
  int v61; // r27
  idSoundChannel *channel; // r29
  const char *v63; // r28
  const char *v64; // r14
  int v65; // r3
  int v66; // r9
  int v67; // r11
  int *v68; // r10
  double v69; // fp12
  int v71; // r22
  float *p_tinnitus; // r30
  int v81; // r10
  double valueFloat; // fp0
  double v83; // fp13
  int v84; // r11
  int v85; // r29
  idActiveChannel *v86; // r4
  char v87; // r3
  int sortKey; // r11
  double v89; // fp13
  double v90; // fp0
  int v91; // r10
  int v92; // r11
  double v93; // fp1
  int v94; // r10
  idActiveChannel *v95; // r7
  int v96; // r4
  int v97; // r8
  int v98; // r9
  int v99; // r19
  int v100; // r28
  idSoundChannel *v101; // r30
  idSoundVoice *hardwareVoice; // r11
  double v103; // fp0
  int v104; // r11
  int *p_id; // r10
  int v106; // r10
  float *v107; // r11
  double v108; // fp12
  __int64 v109; // [sp+8h] [-738h]
  float v110; // [sp+2Ch] [-714h]
  int v111; // [sp+30h] [-710h]
  float v112; // [sp+34h] [-70Ch]
  int v113; // [sp+38h] [-708h]
  int v114; // [sp+60h] [-6E0h]
  __int64 v115; // [sp+68h] [-6D8h] BYREF
  int v116; // [sp+70h] [-6D0h]
  int v117; // [sp+74h] [-6CCh]
  int v118; // [sp+78h] [-6C8h]
  int v119; // [sp+7Ch] [-6C4h]
  idSort_Quick<idActiveChannel,idSort_activeEmitterChannels> v120; // [sp+80h] [-6C0h] BYREF
  idParallelJobList *v121; // [sp+84h] [-6BCh]
  idSoundSystemLocal *v122; // [sp+88h] [-6B8h]
  __int64 v123; // [sp+90h] [-6B0h]
  idStaticList<idActiveChannel,48> v124; // [sp+A0h] [-6A0h] BYREF
  idStr v125; // [sp+230h] [-510h] BYREF
  char v126; // [sp+250h] [-4F0h] BYREF
  idStr v127; // [sp+450h] [-2F0h] BYREF
  char v128; // [sp+470h] [-2D0h] BYREF

  v1 = this;
  if ( s_noSound.valueInteger != 0 || idLib::headless )
    return;
  v122 = &soundSystemLocal;
  if ( s_debugStreaming.valueInteger == 1 )
  {
    num = soundSystemLocal.freeStreamBufferContexts.num;
    v3 = soundSystemLocal.activeStreamBufferContexts.num;
    v4 = Sys_Milliseconds();
    idLib::Printf(
      fmt: "%8i: -------- idSoundWorldLocal::Update() %i active buffers, %i free buffers ----------\n",
      v4,
      v3,
      num);
  }
  if ( common->Game(this: common) != nullptr )
  {
    v6 = common->Game(this: common);
    v115 = __PAIR64__(&off_82040000, v6->GetGameHz(this: v6, a2: GAMETIME_SCALED));
    v7 = (float)((float)v115 * 0.001);
    v8 = ((int (*)(void))common->Game)();
    LODWORD(v9) = (*(int (__fastcall **)(int, int))(*(_DWORD *)v8 + 144))(a1: v8, a2: 1);
    v115 = v9;
    v10 = 1.0;
    v11 = (float)((float)1.0 / (float)v9);
  }
  else
  {
    LODWORD(v5) = timeManager.gameHz;
    v10 = 1.0;
    v115 = v5;
    v7 = (float)((float)v5 * (float)0.001);
    v11 = (float)((float)1.0 / (float)v5);
  }
  parallelJobList = soundSystemLocal.parallelJobList;
  v121 = soundSystemLocal.parallelJobList;
  if ( soundSystemLocal.parallelJobList == nullptr )
    return;
  idParallelJobList::Wait(this: soundSystemLocal.parallelJobList);
  console->AddJobListTimeRange(this: console, a2: RANGE_JBL_SNDO, a3: &idColor::colorPurple, a4: parallelJobList, a5: 0);
  v13 = 0;
  v14 = 0;
  if ( v1->numListeners > 0 )
  {
    ptr = v1->listeners.ptr;
    do
    {
      idSoundWorldLocal::UpdateForListener(this: v1, listener: ptr);
      if ( s_allowMultipleListener.valueInteger == 0 )
        break;
      ++v14;
      ++ptr;
    }
    while ( v14 < v1->numListeners );
  }
  idParallelJobList::InsertSyncPoint(this: parallelJobList, syncType: SYNC_SIGNAL);
  idParallelJobList::InsertSyncPoint(this: parallelJobList, syncType: SYNC_SYNCHRONIZE);
  v124.num = 0;
  v124.size = 48;
  v124.granularity = 1;
  v124.listStatic = 1;
  v124.list = v124.staticList;
  v16 = 48;
  v124.memTag = 5;
  p_granularity = &v124.granularity;
  do
  {
    *((_DWORD *)p_granularity + 1) = 0;
    p_granularity += 4;
    *(_DWORD *)p_granularity = 0;
    --v16;
  }
  while ( v16 != 0 );
  v119 = s_maxEmitterChannels.valueInteger + 1;
  if ( s_maxEmitterChannels.valueInteger + 1 > 48 )
    v119 = 48;
  numListeners = v1->numListeners;
  v19 = 0;
  v118 = 0;
  v117 = 0;
  v20 = 0;
  if ( numListeners > 0 )
  {
    p_size = (float *)&v1->sbspFile.faces.size;
    do
    {
      p_size[57] = 0.0;
      ++v20;
      p_size += 58;
      *p_size = 0.0;
    }
    while ( v20 < v1->numListeners );
  }
  v25 = v1->GetSoundTime(this: v1);
  free = v1->emitters.num;
  v27 = v25;
  v116 = v25;
  v28 = free - 1;
  if ( free - 1 < 0 )
  {
    HIDWORD(v24) = v124.num;
    goto LABEL_85;
  }
  p_emitters = (idList<idSpawnArea::GeneratedPosition *,5> *)&v1->emitters;
  v30 = v28;
  do
  {
    if ( v28 > 0 )
    {
      _R10 = p_emitters->list[v30 - 1];
      __asm { dcbt      0, r10 }
      _R9 = 128;
      __asm { dcbt      r9, r10 }
    }
    v33 = idSoundEmitterLocal::CheckForCompletion(this: (idSoundEmitterLocal *)p_emitters->list[v30], currentTime: v27);
    list = p_emitters->list;
    if ( v33 != 0 )
    {
      v35 = (idBlockAlloc<idSoundEmitterLocal,16,38>::element_t *)list[v30];
      if ( v35 != nullptr )
      {
        ((void (__fastcall *)(idBlockAlloc<idSoundEmitterLocal,16,38>::element_t *, _DWORD))v35->data->channels.staticList[14])(
          a1: v35,
          a2: 0);
        free = (int)v1->emitterAllocator.free;
        v35->data = (idSoundEmitterLocal *)free;
        v22 = (idActiveChannel *)(v1->emitterAllocator.active - 1);
        v1->emitterAllocator.free = v35;
        v1->emitterAllocator.active = (int)v22;
      }
      v36 = v1->emitters.num - 1;
      if ( v28 != v36 )
      {
        free = (int)p_emitters->list[v36];
        p_emitters->list[v30] = (idSpawnArea::GeneratedPosition *)free;
        v22 = (idActiveChannel *)p_emitters->list;
        v23 = (int)p_emitters->list[v30];
        *(_DWORD *)(v23 + 8) = v28;
      }
      if ( v36 <= p_emitters->size
        || (unsigned __int8)idList<idNavSpline *,5>::Resize(this: p_emitters, newsize: v36) != 0 )
      {
        size = p_emitters->size;
        if ( v36 < size )
          size = v36;
        p_emitters->num = size;
      }
LABEL_34:
      HIDWORD(v24) = v124.num;
      goto LABEL_35;
    }
    v38 = &list[v30];
    v39 = (const idVec3 *)(*(int (__fastcall **)(idSpawnArea::GeneratedPosition *))(LODWORD(list[v30]->position.x) + 88))(a1: list[v30]);
    BestListenerForEmitter = idSoundWorldLocal::GetBestListenerForEmitter(
                               this: v1,
                               emitterId: LODWORD((*v38)[8].position.y),
                               emitterOrigin: v39);
    v41 = idSoundEmitterLocal::Update(
            this: (idSoundEmitterLocal *)p_emitters->list[v30],
            listener: BestListenerForEmitter->ptr,
            currentTime: v27);
    v22 = (idActiveChannel *)v117;
    _FP13 = (float)(BestListenerForEmitter->ptr[0].maxDBFrame - (float)v41);
    v43 = 0;
    __asm { fsel      f12, f13, f0, f1 }
    BestListenerForEmitter->ptr[0].maxDBFrame = _FP12;
    v23 = (int)p_emitters->list;
    LODWORD(v24) = p_emitters->list[v30];
    v114 = *(_DWORD *)(v24 + 24);
    v117 = (int)v22 + v114;
    if ( v114 <= 0 )
      goto LABEL_34;
    do
    {
      v45 = *(idSoundChannel **)(LODWORD(p_emitters->list[v30][1].position.x) + v13);
      HIDWORD(v46) = idSoundChannel::CanMute(this: v45);
      if ( HIDWORD(v46) != 0 && v45->volumeDB <= -60.0 )
      {
        if ( s_debugCulling.valueInteger != 0 && (s_debugCulling.valueInteger >= 3 || v45->hardwareVoice != nullptr) )
        {
          v47 = "(had hw)";
          if ( v45->hardwareVoice == nullptr )
            v47 = "(no hw) ";
          str = v45->sample->name.str;
          v49 = Sys_Milliseconds();
          idLib::Printf(fmt: "%d Culling (silent) sound %s %s\n", v49, v47, str);
        }
LABEL_46:
        idSoundChannel::Mute(this: v45);
        HIDWORD(v24) = v124.num;
        goto LABEL_47;
      }
      soundShader = v45->soundShader;
      if ( soundShader != nullptr )
        LODWORD(v46) = 10000 * soundShader->parms.priority;
      else
        LODWORD(v46) = 0;
      if ( HIDWORD(v46) != 0 )
      {
        v123 = v46;
        v51 = (float)v46;
      }
      else
      {
        v51 = 100000.0;
      }
      sample = v45->sample;
      v53 = (float)((float)(v45->volumeDB * (float)100.0) + (float)v51);
      v54 = 0;
      numChannels = sample->format.basic.numChannels;
      v118 += numChannels;
      if ( v124.num > 0 )
      {
        p_sortKey = &v124.list->sortKey;
        do
        {
          if ( (int)v53 > *p_sortKey )
            break;
          ++v54;
          p_sortKey += 2;
        }
        while ( v54 < v124.num );
      }
      if ( v54 == v124.num && (v124.num + 1 >= v124.size || numChannels + v19 > 64) )
      {
        if ( s_debugCulling.valueInteger != 0 && (s_debugCulling.valueInteger >= 2 || v45->hardwareVoice != nullptr) )
        {
          v57 = "(had hw)";
          if ( v45->hardwareVoice == nullptr )
            v57 = "(no hw) ";
          v58 = sample->name.str;
          v59 = Sys_Milliseconds();
          idLib::Printf(fmt: "%d Culling sound %s %s\n", v59, v57, v58);
        }
        goto LABEL_46;
      }
      HIDWORD(v115) = v45;
      LODWORD(v115) = (int)v53;
      idList<idActiveChannel,5>::Insert(this: &v124, obj: (const idActiveChannel *)&v115, index: v54);
      v19 += numChannels;
LABEL_69:
      HIDWORD(v24) = v124.num;
      while ( HIDWORD(v24) == v119 || v19 > 64 )
      {
        v60 = HIDWORD(v24) - 1;
        v61 = HIDWORD(v24) - 1;
        channel = v124.list[v61].channel;
        if ( s_debugCulling.valueInteger != 0 && (s_debugCulling.valueInteger >= 2 || channel->hardwareVoice != nullptr) )
        {
          v63 = "(had hw)";
          if ( channel->hardwareVoice == nullptr )
            v63 = "(no hw) ";
          v64 = channel->sample->name.str;
          v65 = Sys_Milliseconds();
          idLib::Printf(fmt: "%d Culling sound %s %s\n", v65, v63, v64);
          v1 = this;
        }
        idSoundChannel::Mute(this: channel);
        v19 -= channel->sample->format.basic.numChannels;
        if ( v60 < 0 )
          goto LABEL_69;
        HIDWORD(v24) = v124.num;
        if ( v60 < v124.num )
        {
          HIDWORD(v24) = v124.num - 1;
          v66 = v60;
          v124.num = HIDWORD(v24);
          if ( v60 < SHIDWORD(v24) )
          {
            v67 = v61 * 8;
            do
            {
              v22 = v124.list;
              ++v66;
              v68 = (int *)((char *)v124.list + v67);
              v23 = *(int *)((char *)&v124.list[1].channel + v67);
              *v68 = v23;
              LODWORD(v24) = v68[3];
              v68[1] = v24;
              v67 += 8;
              HIDWORD(v24) = v124.num;
            }
            while ( v66 < v124.num );
          }
        }
      }
LABEL_47:
      ++v43;
      v13 += 4;
      free = LODWORD(p_emitters->list[v30][1].position.y);
    }
    while ( v43 < free );
    v27 = v116;
    v13 = 0;
LABEL_35:
    --v28;
    --v30;
  }
  while ( v28 >= 0 );
LABEL_85:
  if ( s_skipHDR.valueInteger == 0 )
  {
    v69 = -60.0;
    _FP30 = -60.0;
    v71 = 0;
    _FP31 = -60.0;
    if ( v1->numListeners > 0 )
    {
      HIDWORD(v24) = &soundSystemLocal.hardware.voices.staticList[19].invListenerAxis.mat[2];
      p_tinnitus = &v1->listeners.ptr[0].tinnitus;
      do
      {
        _FP10 = (float)(*(p_tinnitus - 2)
                      - (float)-(float)((float)(s_hdrFalloff.valueFloat * (float)v7) - *(p_tinnitus - 2)));
        __asm
        {
          fsel      f9, f10, f13, f11
          fsel      f0, f9, f9, f28
        }
        *(p_tinnitus - 3) = _FP0;
        if ( _FP0 > s_tinnitusStart.valueFloat )
          *p_tinnitus = 0.0;
        if ( _FP0 <= s_tinnitusReset.valueFloat )
        {
          _FP9 = (float)((float)-(float)((float)(s_tinnitusFalloff.valueFloat * (float)v7) - *p_tinnitus) - (float)v69);
          __asm { fsel      f8, f9, f10, f12 }
          *p_tinnitus = _FP8;
        }
        _FP11 = (float)((float)_FP31 - (float)_FP0);
        _FP10 = (float)((float)_FP30 - *p_tinnitus);
        __asm
        {
          fsel      f31, f11, f31, f0
          fsel      f30, f10, f30, f13
        }
        if ( s_showHDR.valueInteger != 0 )
        {
          if ( (_S13_30 & 1) == 0 )
          {
            _S13_30 |= 1u;
            handle_5.index = -1;
            handle_5.time = 0;
          }
          v112 = v10;
          ((void (__fastcall *)(idConsole *, idOverlayHandle *, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, double, double, double))console->PrintOverlay)(
            a1: console,
            a2: &handle_5,
            a3: 0,
            a4: LODWORD(v112),
            a5: v113,
            a6: HIDWORD(_FP31),
            a7: LODWORD(_FP31),
            a8: COERCE_UNSIGNED_INT64(*(p_tinnitus - 3)),
            a9: v10,
            a10: v10,
            a11: _FP31);
          v69 = -60.0;
        }
        ++v71;
        p_tinnitus += 58;
      }
      while ( v71 < v1->numListeners );
    }
    ((void (__fastcall *)(idSoundEmitter *, int, _DWORD, double))v1->tinnitusEmitter->SetVolume)(
      a1: v1->tinnitusEmitter,
      a2: 1,
      a3: HIDWORD(v24),
      a4: _FP30);
    idSoundEmitterLocal::Update(
      this: (idSoundEmitterLocal *)v1->tinnitusEmitter,
      listener: v1->listeners.ptr,
      currentTime: v116);
    HIDWORD(v24) = v124.num;
    v81 = 0;
    v22 = (idActiveChannel *)&s_volume_dB;
    valueFloat = s_volume_dB.valueFloat;
    v83 = (float)(s_volume_dB.valueFloat - (float)_FP31);
    if ( v124.num > 0 )
    {
      free = 0;
      while ( 1 )
      {
        v84 = *(int *)((char *)&v124.list->channel + free);
        v23 = *(_DWORD *)(v84 + 120);
        LODWORD(v24) = v23 & 0x200000;
        *(float *)(v84 + 216) = (v23 & 0x200000) != 0
                              ? (float)valueFloat + *(float *)(v84 + 216)
                              : (float)v83 + *(float *)(v84 + 216);
        HIDWORD(v24) = v124.num;
        ++v81;
        free += 8;
        if ( v81 >= v124.num )
          break;
        valueFloat = s_volume_dB.valueFloat;
      }
    }
  }
  v85 = 0;
  v86 = v124.list;
  v87 = 0;
  if ( SHIDWORD(v24) > 0 )
  {
    v23 = 1;
    LODWORD(v24) = 0;
    do
    {
      v22 = *(idActiveChannel **)((char *)&v86->channel + v24);
      sortKey = v22[20].sortKey;
      v89 = *(float *)(sortKey + 196);
      if ( v89 > 0.0 )
      {
        free = v23;
        v90 = (float)(*(float *)&v22[27].channel - *(float *)(sortKey + 196));
        if ( v23 < SHIDWORD(v24) )
        {
          v91 = v24 + 8;
          do
          {
            v92 = *(int *)((char *)&v86->channel + v91);
            if ( v22[20].sortKey == *(_DWORD *)(v92 + 164) && *(float *)(v92 + 216) > v90 )
            {
              *(float *)(v92 + 216) = v90;
              v86 = v124.list;
              HIDWORD(v24) = v124.num;
              v90 = (float)((float)v90 - (float)v89);
              v87 = 1;
            }
            ++free;
            v91 += 8;
          }
          while ( free < SHIDWORD(v24) );
        }
      }
      ++v23;
      LODWORD(v24) = v24 + 8;
    }
    while ( v23 - 1 < SHIDWORD(v24) );
  }
  if ( v87 != 0 )
  {
    v120.__vftable = (idSort_Quick<idActiveChannel,idSort_activeEmitterChannels>_vtbl *)&idSort_activeEmitterChannels::`vftable';
    if ( v86 != nullptr )
      idSort_Quick<idActiveChannel,idSort_activeEmitterChannels>::Sort(
        this: &v120,
        num: v24,
        a3: v23,
        a4: (int)v22,
        a5: free,
        a6: v109);
    v120.__vftable = (idSort_Quick<idActiveChannel,idSort_activeEmitterChannels>_vtbl *)&idSort<idActiveChannel>::`vftable';
  }
  v93 = AdjustForCushionChannels(
          activeEmitterChannels: &v124,
          uncushionedChannels: v119 - s_cushionFadeChannels.valueInteger,
          currentCushionDB: v1->currentCushionDB,
          driftRate: (float)(s_cushionFadeRate.valueFloat * (float)v11));
  v94 = v124.num;
  v1->currentCushionDB = v93;
  v95 = v124.list;
  soundLog.totalEmitterChannels = v117;
  soundLog.totalHardwareChannels = v118;
  soundLog.activeEmitterChannels = v94;
  soundLog.activeHardwareChannels = v19;
  if ( v94 != 0 )
  {
    soundLog.maxDB = v124.list->channel->volumeDB;
    soundLog.minDB = v124.list[v94 - 1].channel->volumeDB;
  }
  else
  {
    soundLog.maxDB = 0.0;
    soundLog.minDB = 0.0;
  }
  v125.baseBuffer[0] = 0;
  v126 = 0;
  v96 = 34852;
  v125.len = 0;
  v97 = v122->activeStreamBufferContexts.num;
  v98 = v122->freeStreamBufferContexts.num;
  v125.data = &v126;
  v125.allocedAndFlag = -2147483136;
  soundLog.activeBuffers = v97;
  soundLog.freeBuffers = v98;
  if ( s_showVoices.valueInteger != 0 )
  {
    idStr::Format(
      this: &v125,
      fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v1->currentCushionDB)),
      (unsigned int)COERCE_UNSIGNED_INT64(v1->currentCushionDB),
      v122->hardware.freeVoices.num,
      v122->hardware.zombieVoices.num);
    v94 = v124.num;
    v95 = v124.list;
  }
  if ( v94 > 0 )
  {
    v99 = v116;
    v100 = 0;
    while ( 1 )
    {
      v101 = v95[v100].channel;
      idSoundChannel::UpdateHardware(this: v101, volumeAdd: 0.0, currentTime: v96, a4: v99);
      if ( s_showVoices.valueInteger != 0 )
      {
        v127.baseBuffer[0] = 0;
        v128 = 0;
        v127.data = &v128;
        v127.len = 0;
        v127.allocedAndFlag = -2147483136;
        idSoundChannel::CanMute(this: v101);
        idStr::Format(
          this: &v127,
          fmt: "%2i: %5.1f db [%3i] %ikhz*%i %s%s\n",
          (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v101->volumeDB)),
          (unsigned int)COERCE_UNSIGNED_INT64(v101->volumeDB),
          v101->emitter->index,
          (signed int)v101->sample->format.basic.samplesPerSec / 1000,
          v101->sample->format.basic.numChannels,
          v101->sample->name.str);
        idStr::Append(this: &v125, text: &v127);
        idStr::FreeData(this: &v127);
      }
      hardwareVoice = v101->hardwareVoice;
      if ( hardwareVoice != nullptr )
      {
        v103 = (float)((float)(v101->currentShakeAmplitude * v101->parms.shakes) * hardwareVoice->gain);
        if ( v103 > 0.0 )
        {
          v104 = 0;
          if ( v1->numListeners > 0 )
          {
            p_id = &v1->listeners.ptr[0].id;
            while ( v101->emitter->emitterId != *p_id )
            {
              ++v104;
              p_id += 58;
              if ( v104 >= v1->numListeners )
                goto LABEL_136;
            }
            v1->listeners.ptr[v104].shakeAmp = v1->listeners.ptr[v104].shakeAmp + (float)v103;
            v103 = 0.0;
          }
LABEL_136:
          v106 = 0;
          if ( v1->numListeners > 0 )
          {
            v107 = (float *)&v1->sbspFile.faces.size;
            do
            {
              ++v106;
              v108 = (float)(v107[58] + (float)v103);
              v107 += 58;
              *v107 = v108;
            }
            while ( v106 < v1->numListeners );
          }
        }
      }
      ++v85;
      ++v100;
      if ( v85 >= v124.num )
        break;
      v95 = v124.list;
    }
  }
  if ( s_showVoices.valueInteger != 0 )
  {
    if ( (_S13_30 & 2) == 0 )
    {
      dword_837C81C0 = 0;
      _S13_30 |= 2u;
      dword_837C81BC = -1;
    }
    v110 = v10;
    ((void (__fastcall *)(idConsole *, int *, _DWORD, int, int, char *, double, double))console->PrintOverlay)(
      a1: console,
      a2: &dword_837C81BC,
      a3: LODWORD(v110),
      a4: v111,
      a5: v113,
      a6: v125.data,
      a7: v10,
      a8: v10);
  }
  idStr::FreeData(this: &v125);
  idStreamFileCache::SignalWork(this: streamFileCache);
  idParallelJobList::Submit(this: v121, waitForJobList: nullptr, parallelism: -1);
  if ( s_recordTrace.valueInteger != 0 )
    idCVar::SetBool(this: &s_recordTrace, newValue: false, force: true);
  if ( (v124.listStatic == 0 || v124.listStatic == 2) && v124.list != nullptr )
    idMem::Free(this: &mem, ptr: v124.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$243691
// EA  : 0x8299B26C
// RVA : 0x0099B26C
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_243691()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1856 + 160));
}


// ========================================================================
// __unwind$243693
// EA  : 0x8299B294
// RVA : 0x0099B294
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_243693()
{
  int v0; // r12

  idSort_activeEmitterChannels::~idSort_activeEmitterChannels(this: (idSort_activeEmitterChannels *)(v0 - 1856 + 128));
}


// ========================================================================
// __unwind$243694
// EA  : 0x8299B2BC
// RVA : 0x0099B2BC
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_243694()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1856 + 560));
}


// ========================================================================
// __unwind$243695
// EA  : 0x8299B2E4
// RVA : 0x0099B2E4
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_243695()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1856 + 1104));
}


// ========================================================================
// ?SoundReportFrequencies_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8299B488
// RVA : 0x0099B488
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall SoundReportFrequencies_f(const idCmdArgs *args)
{
  idFileList *v1; // r25
  signed int v2; // r30
  signed int num; // r23
  signed int v4; // r28
  int v5; // r27
  int v6; // r22
  const char *v7; // r6
  idFile *v8; // r3
  idFile *v9; // r29
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > **Myhead; // r6
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Left; // r11
  bool v16; // cr58
  int v17; // [sp+8h] [-108h]
  int v18; // [sp+Ch] [-104h]
  int v19; // [sp+10h] [-100h]
  int v20; // [sp+14h] [-FCh]
  int v21; // [sp+18h] [-F8h]
  int v22; // [sp+1Ch] [-F4h]
  int v23; // [sp+20h] [-F0h]
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >,std::_Iterator_base0> *v24; // [sp+24h] [-ECh]
  std::allocator<std::pair<int const ,int> > v25; // [sp+50h] [-C0h] BYREF
  std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > v26; // [sp+54h] [-BCh] BYREF
  std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > v27; // [sp+70h] [-A0h] BYREF
  int v28; // [sp+80h] [-90h] BYREF
  int v29[33]; // [sp+8Ch] [-84h] BYREF

  std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>(
    this: &v27,
    _Parg: (const std::less<int> *)&v25,
    _Al: &v25);
  idLib::Printf(fmt: "Searching for sound files...");
  v1 = fileSystem->ListFilesTree(this: fileSystem, a2: "sound", a3: "wav", a4: 0);
  idLib::Printf(fmt: "done!\n");
  v2 = 0;
  num = v1->list.num;
  if ( num > 0 )
  {
    v4 = num / 10;
    v5 = 0;
    v6 = 0;
    do
    {
      __twllei(num, 0);
      __twlgei(num & ~(__ROL4__(v6, 1) - 1), 0xFFFFFFFF);
      v7 = "...";
      if ( v6 / num == 100 )
        v7 = &byte_8200D768;
      __twllei(v4, 0);
      __twlgei(v4 & ~(__ROL4__(v2, 1) - 1), 0xFFFFFFFF);
      idLib::PrintfIf(condition: (_cntlzw(v2 % v4) & 0x20) != 0, fmt: "%d%%%s", v6 / num, v7);
      v8 = fileSystem->OpenFileRead(this: fileSystem, a2: v1->list.list[v5].data, a3: 1, a4: 0);
      v9 = v8;
      if ( v8 != nullptr )
      {
        v8->Read(this: v8, a2: &v26._Myhead, a3: 12u);
        v9->Read(this: v9, a2: &v28, a3: 24u);
        std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::find(
          this: &v26,
          result: (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > *)&v27,
          _Keyval: v29);
        if ( *(std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node **)&v26.comp.std::binary_function<int,int,bool> == v27._Myhead )
          *std::map<int,int>::operator[](this: (std::map<int,int> *)&v27, _Keyval: v29) = 1;
        else
          ++*(_DWORD *)(*(_DWORD *)&v26.comp.std::binary_function<int,int,bool> + 16);
        ((void (__fastcall *)(idFile *, int))v9->dtr_idFile)(a1: v9, a2: 1);
      }
      ++v2;
      v6 += 100;
      ++v5;
    }
    while ( v2 < num );
  }
  idLib::Printf(fmt: "100%%\n");
  fileSystem->FreeFileList(this: fileSystem, a2: v1);
  Myhead = (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > **)v27._Myhead;
  Left = v27._Myhead->_Left;
  v16 = *Myhead == (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > *)Myhead;
  *(_DWORD *)&v26.comp.std::binary_function<int,int,bool> = v27._Myhead->_Left;
  if ( !v16 )
  {
    do
    {
      idLib::Printf(fmt: "%d: %d\n", Left->_Myval.first, Left->_Myval.second);
      std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>,std::_Iterator_base0>::operator++(this: (std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >,std::_Iterator_base0> *)&v26);
      Myhead = (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > **)v27._Myhead;
      Left = *(std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node **)&v26.comp.std::binary_function<int,int,bool>;
    }
    while ( *(std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node **)&v26.comp.std::binary_function<int,int,bool> != v27._Myhead );
  }
  *(_DWORD *)&v26.comp.std::binary_function<int,int,bool> = Myhead;
  std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::erase(
    this: &v26,
    result: (std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *)&v27,
    _First: *Myhead,
    _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > *)Myhead,
    a5: v13,
    a6: v12,
    a7: v11,
    a8: v10,
    a9: v17,
    a10: v18,
    a11: v19,
    a12: v20,
    a13: v21,
    a14: v22,
    a15: v23,
    a16: v24);
  idMem::Free(this: &mem, ptr: v27._Myhead, align: ALIGN_16);
}


// ========================================================================
// __unwind$245121
// EA  : 0x8299B6F0
// RVA : 0x0099B6F0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __fastcall _unwind_245121(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r12

  std::map<int,int>::~map<int,int>(this: (std::map<int,int> *)(v8 - 272 + 112), a2, a3, a4, a5, a6, a7, a8);
}


// ========================================================================
// __unwind$245428
// EA  : 0x8299B718
// RVA : 0x0099B718
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _unwind_245428()
{
  int v0; // r12

  std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>::~_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>(this: (std::_Tree_val<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const ,idMaterial const *> >,0> > *)(v0 - 272 + 112));
}


// ========================================================================
// `dynamic initializer for 's_showAreas''
// EA  : 0x83360CD8
// RVA : 0x01360CD8
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_showAreas__()
{
  idCVar::idCVar(
    this: &s_showAreas,
    name: "s_showAreas",
    value: "0",
    flags: 2,
    description: "1 = render each sound area in a different color. 2= render area local listener is in",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_showAreas__);
}


// ========================================================================
// `dynamic initializer for 's_showBigAreas''
// EA  : 0x83360D30
// RVA : 0x01360D30
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_showBigAreas__()
{
  idCVar::idCVar(
    this: &s_showBigAreas,
    name: "s_showBigAreas",
    value: "0",
    flags: 1,
    description: "render sound areas which exceed MAX_SOUND_BSP_AREA_FACES",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_showBigAreas__);
}


// ========================================================================
// `dynamic initializer for 's_showPortals''
// EA  : 0x83360D88
// RVA : 0x01360D88
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_showPortals__()
{
  idCVar::idCVar(
    this: &s_showPortals,
    name: "s_showPortals",
    value: "0",
    flags: 1,
    description: "show sound portals",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_showPortals__);
}


// ========================================================================
// `dynamic initializer for 's_lockListener''
// EA  : 0x83360DE0
// RVA : 0x01360DE0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_lockListener__()
{
  idCVar::idCVar(
    this: &s_lockListener,
    name: "s_lockListener",
    value: "0",
    flags: 1,
    description: "lock listener updates",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_lockListener__);
}


// ========================================================================
// `dynamic initializer for 's_allowMultipleListener''
// EA  : 0x83360E38
// RVA : 0x01360E38
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_allowMultipleListener__()
{
  idCVar::idCVar(
    this: &s_allowMultipleListener,
    name: "s_allowMultipleListener",
    value: "1",
    flags: 1,
    description: "Allow multiple listeners in splitscreen",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_allowMultipleListener__);
}


// ========================================================================
// `dynamic initializer for 's_showHDR''
// EA  : 0x83360E90
// RVA : 0x01360E90
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_showHDR__()
{
  idCVar::idCVar(
    this: &s_showHDR,
    name: "s_showHDR",
    value: "0",
    flags: 1,
    description: "Show HDR sound values",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_showHDR__);
}


// ========================================================================
// `dynamic initializer for 's_hdrFalloff''
// EA  : 0x83360EE8
// RVA : 0x01360EE8
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_hdrFalloff__()
{
  idCVar::idCVar(
    this: &s_hdrFalloff,
    name: "s_hdrFalloff",
    value: "12",
    flags: 4,
    description: "HDR Falloff rate in dB per second",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_hdrFalloff__);
}


// ========================================================================
// `dynamic initializer for 's_tinnitusStart''
// EA  : 0x83360F40
// RVA : 0x01360F40
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_tinnitusStart__()
{
  idCVar::idCVar(
    this: &s_tinnitusStart,
    name: "s_tinnitusStart",
    value: "12",
    flags: 4,
    description: "Perceived dB level when tinnitus starts to kick in",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_tinnitusStart__);
}


// ========================================================================
// `dynamic initializer for 's_tinnitusReset''
// EA  : 0x83360F98
// RVA : 0x01360F98
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_tinnitusReset__()
{
  idCVar::idCVar(
    this: &s_tinnitusReset,
    name: "s_tinnitusReset",
    value: "1",
    flags: 4,
    description: "Perceived dB level when tinnitus resets and can be triggered again",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_tinnitusReset__);
}


// ========================================================================
// `dynamic initializer for 's_tinnitusFalloff''
// EA  : 0x83360FF0
// RVA : 0x01360FF0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_tinnitusFalloff__()
{
  idCVar::idCVar(
    this: &s_tinnitusFalloff,
    name: "s_tinnitusFalloff",
    value: "10",
    flags: 4,
    description: "Tinnitus Falloff rate in dB per second",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_tinnitusFalloff__);
}


// ========================================================================
// `dynamic initializer for 's_playPositioned''
// EA  : 0x83361048
// RVA : 0x01361048
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_playPositioned__()
{
  idCVar::idCVar(
    this: &s_playPositioned,
    name: "s_playPositioned",
    value: "1",
    flags: 1,
    description: "Play positioned sounds such as bullet impacts and foot steps",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_playPositioned__);
}


// ========================================================================
// `dynamic initializer for 's_showDucks''
// EA  : 0x833610A0
// RVA : 0x013610A0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_showDucks__()
{
  idCVar::idCVar(
    this: &s_showDucks,
    name: "s_showDucks",
    value: "0",
    flags: 1,
    description: "Draw duck info on the hud",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_showDucks__);
}


// ========================================================================
// `dynamic initializer for 's_showVoices''
// EA  : 0x833610F8
// RVA : 0x013610F8
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_showVoices__()
{
  idCVar::idCVar(
    this: &s_showVoices,
    name: "s_showVoices",
    value: "0",
    flags: 1,
    description: "Draw voice info on the hud",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_showVoices__);
}


// ========================================================================
// `dynamic initializer for 's_constantAmplitude''
// EA  : 0x83361150
// RVA : 0x01361150
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_constantAmplitude__()
{
  idCVar::idCVar(
    this: &s_constantAmplitude,
    name: "s_constantAmplitude",
    value: "-1",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_constantAmplitude__);
}


// ========================================================================
// `dynamic initializer for 's_maxEmitterChannels''
// EA  : 0x833611A8
// RVA : 0x013611A8
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_maxEmitterChannels__()
{
  idCVar::idCVar(
    this: &s_maxEmitterChannels,
    name: "s_maxEmitterChannels",
    value: "48",
    flags: 2,
    description: "Can be set lower than the absolute max of MAX_HARDWARE_VOICES",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_maxEmitterChannels__);
}


// ========================================================================
// `dynamic initializer for 's_cushionFadeChannels''
// EA  : 0x83361200
// RVA : 0x01361200
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_cushionFadeChannels__()
{
  idCVar::idCVar(
    this: &s_cushionFadeChannels,
    name: "s_cushionFadeChannels",
    value: "2",
    flags: 2,
    description: "Ramp currentCushionDB so this many emitter channels should be silent",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_cushionFadeChannels__);
}


// ========================================================================
// `dynamic initializer for 's_cushionFadeRate''
// EA  : 0x83361258
// RVA : 0x01361258
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_cushionFadeRate__()
{
  idCVar::idCVar(
    this: &s_cushionFadeRate,
    name: "s_cushionFadeRate",
    value: "60",
    flags: 4,
    description: "DB / second change to currentCushionDB",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_cushionFadeRate__);
}


// ========================================================================
// `dynamic initializer for 's_cushionFadeLimit''
// EA  : 0x833612B0
// RVA : 0x013612B0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_cushionFadeLimit__()
{
  idCVar::idCVar(
    this: &s_cushionFadeLimit,
    name: "s_cushionFadeLimit",
    value: "-30",
    flags: 4,
    description: "Never cushion fade beyond this level",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_cushionFadeLimit__);
}


// ========================================================================
// `dynamic initializer for 's_cushionFadeOver''
// EA  : 0x83361308
// RVA : 0x01361308
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_cushionFadeOver__()
{
  idCVar::idCVar(
    this: &s_cushionFadeOver,
    name: "s_cushionFadeOver",
    value: "10",
    flags: 4,
    description: "DB above s_cushionFadeLimit to start ramp to silence",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_cushionFadeOver__);
}


// ========================================================================
// `dynamic initializer for 's_unpauseFadeInTime''
// EA  : 0x83361360
// RVA : 0x01361360
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_unpauseFadeInTime__()
{
  idCVar::idCVar(
    this: &s_unpauseFadeInTime,
    name: "s_unpauseFadeInTime",
    value: "250",
    flags: 2,
    description: "When unpausing a sound world, milliseconds to fade sounds in over",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_unpauseFadeInTime__);
}


// ========================================================================
// `dynamic initializer for 's_environmentalFadeTime''
// EA  : 0x833613B8
// RVA : 0x013613B8
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_environmentalFadeTime__()
{
  idCVar::idCVar(
    this: &s_environmentalFadeTime,
    name: "s_environmentalFadeTime",
    value: "2",
    flags: 2,
    description: "How many seconds it takes to fade environmental sounds when crossing portals",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_environmentalFadeTime__);
}


// ========================================================================
// `dynamic initializer for 's_skipHDR''
// EA  : 0x83361410
// RVA : 0x01361410
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_skipHDR__()
{
  idCVar::idCVar(
    this: &s_skipHDR,
    name: "s_skipHDR",
    value: "0",
    flags: 1,
    description: "Show HDR sound values",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_skipHDR__);
}


// ========================================================================
// `dynamic initializer for 's_recordTrace''
// EA  : 0x83361468
// RVA : 0x01361468
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_recordTrace__()
{
  idCVar::idCVar(
    this: &s_recordTrace,
    name: "s_recordTrace",
    value: "0",
    flags: 1,
    description: "sound trace",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_recordTrace__);
}


// ========================================================================
// `dynamic initializer for 's_debugCulling''
// EA  : 0x833614C0
// RVA : 0x013614C0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_debugCulling__()
{
  idCVar::idCVar(
    this: &s_debugCulling,
    name: "s_debugCulling",
    value: "0",
    flags: 2,
    description: "Print information on culling of sounds (performance culling, i.e. out of hwvoices)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_debugCulling__);
}


// ========================================================================
// `dynamic initializer for 'tinnitusShader''
// EA  : 0x83361518
// RVA : 0x01361518
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

void _dynamic_initializer_for__tinnitusShader__()
{
  tinnitusShader.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &tinnitusShader;
}


// ========================================================================
// `dynamic initializer for 'TestMapVolumeFromFadeDB_v''
// EA  : 0x83361538
// RVA : 0x01361538
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestMapVolumeFromFadeDB_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestMapVolumeFromFadeDB_v,
           cmdName: "TestMapVolumeFromFadeDB",
           function: TestMapVolumeFromFadeDB_f,
           description: "Tests TestMapVolumeFromFadeDB",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'duck_v''
// EA  : 0x83361560
// RVA : 0x01361560
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__duck_v__()
{
  return idCommandLink::idCommandLink(
           this: &duck_v,
           cmdName: "duck",
           function: duck_f,
           description: "Syntax: duck <decl> [fadeIn [sustain fadeOut]]",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclDuck>);
}


// ========================================================================
// `dynamic initializer for 'duckBlend_v''
// EA  : 0x83361590
// RVA : 0x01361590
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__duckBlend_v__()
{
  return idCommandLink::idCommandLink(
           this: &duckBlend_v,
           cmdName: "duckBlend",
           function: duckBlend_f,
           description: "Syntax: duckBlend <decl> <percent 0-100>",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclDuck>);
}


// ========================================================================
// `dynamic initializer for 'reportSoundWorld_v''
// EA  : 0x833615C0
// RVA : 0x013615C0
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__reportSoundWorld_v__()
{
  return idCommandLink::idCommandLink(
           this: &reportSoundWorld_v,
           cmdName: "reportSoundWorld",
           function: reportSoundWorld_f,
           description: "Reports emitter / channel information",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'SoundReportNonMatchingFrequencies_v''
// EA  : 0x833615E8
// RVA : 0x013615E8
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__SoundReportNonMatchingFrequencies_v__()
{
  return idCommandLink::idCommandLink(
           this: &SoundReportNonMatchingFrequencies_v,
           cmdName: "SoundReportNonMatchingFrequencies",
           function: SoundReportNonMatchingFrequencies_f,
           description: "Reports sounds that don't match given frquency",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'SoundReportFrequencies_v''
// EA  : 0x83361610
// RVA : 0x01361610
// PDB : w:\tech5\engine\sound\soundworld.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__SoundReportFrequencies_v__()
{
  return idCommandLink::idCommandLink(
           this: &SoundReportFrequencies_v,
           cmdName: "SoundReportFrequencies",
           function: SoundReportFrequencies_f,
           description: "Displays a frequency histogram of all sound files",
           argCompletion: nullptr);
}

