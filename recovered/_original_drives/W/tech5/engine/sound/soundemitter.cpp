
// ========================================================================
// ?Clear@idSoundFade@@QAAXXZ
// EA  : 0x8298BEE0
// RVA : 0x0098BEE0
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __fastcall idSoundFade::Clear(idSoundFade *this)
{
  this->fadeStartTime = 0;
  this->fadeEndTime = 0;
  this->fadeStartVolume = 0.0;
  this->fadeEndVolume = 0.0;
}


// ========================================================================
// ?SetVolume@idSoundFade@@QAAXM@Z
// EA  : 0x8298BF00
// RVA : 0x0098BF00
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __fastcall idSoundFade::SetVolume(idSoundFade *this, double to)
{
  this->fadeStartVolume = to;
  this->fadeEndVolume = to;
  this->fadeStartTime = 0;
  this->fadeEndTime = 0;
}


// ========================================================================
// ?GetVolume@idSoundFade@@QBAMH@Z
// EA  : 0x8298BF18
// RVA : 0x0098BF18
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

float __fastcall idSoundFade::GetVolume(idSoundFade *this, int soundTime, int a3, __int64 a4)
{
  __int64 v4; // r10
  int fadeStartTime; // r11
  double fadeEndVolume; // fp1

  LODWORD(v4) = this->fadeEndTime;
  HIDWORD(v4) = 0x82000000;
  fadeStartTime = this->fadeStartTime;
  LODWORD(a4) = v4 - this->fadeStartTime;
  if ( (float)a4 <= 0.0 || soundTime >= (int)v4 )
  {
    fadeEndVolume = this->fadeEndVolume;
  }
  else if ( soundTime <= fadeStartTime )
  {
    fadeEndVolume = this->fadeStartVolume;
  }
  else
  {
    LODWORD(v4) = soundTime - fadeStartTime;
    fadeEndVolume = (float)((float)((float)((float)v4 / (float)a4) * (float)(this->fadeEndVolume - this->fadeStartVolume))
                          + this->fadeStartVolume);
  }
  return *((float *)&fadeEndVolume + 1);
}


// ========================================================================
// ?Fade@idSoundFade@@QAAXMHHH@Z
// EA  : 0x8298C298
// RVA : 0x0098C298
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __fastcall idSoundFade::Fade(idSoundFade *this, double to, int length, int soundTime, int delay, __int64 a6)
{
  int v6; // r5
  int v7; // r31
  double Volume; // fp1
  int v9; // r6
  int v10; // r5
  int v11; // r3
  double v12; // fp6

  v6 = soundTime + delay;
  v7 = HIDWORD(a6);
  if ( this->fadeEndTime != v6 || this->fadeEndVolume != to )
  {
    Volume = idSoundFade::GetVolume(this, soundTime: delay, a3: v6, a4: a6);
    *(float *)(v11 + 8) = Volume;
    *(float *)(v11 + 12) = v12;
    *(_DWORD *)v11 = v9 + v7;
    *(_DWORD *)(v11 + 4) = v10 + v7;
  }
}


// ========================================================================
// ?Init@idSoundEmitterLocal@@QAAXHPAVidSoundWorldLocal@@@Z
// EA  : 0x8298C300
// RVA : 0x0098C300
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __fastcall idSoundEmitterLocal::Init(idSoundEmitterLocal *this, int i, idSoundWorldLocal *sw)
{
  this->soundWorld = sw;
  this->index = i;
  this->canFree = false;
  this->volumeAdjustment = 0.0;
  this->origin.z = 0.0;
  this->origin.y = 0.0;
  this->origin.x = 0.0;
  this->axis.mat[2].z = 1.0;
  this->axis.mat[1].y = 1.0;
  this->axis.mat[0].x = 1.0;
  this->axis.mat[1].z = 0.0;
  this->axis.mat[0].z = 0.0;
  this->axis.mat[0].y = 0.0;
  this->axis.mat[2].y = 0.0;
  this->axis.mat[2].x = 0.0;
  this->axis.mat[1].x = 0.0;
  this->velocity.z = 0.0;
  this->velocity.y = 0.0;
  this->velocity.x = 0.0;
  this->emitterId = 0;
  this->occludedDistance = 0.0;
  this->occludedDirection.z = 0.0;
  this->occludedDirection.y = 0.0;
  this->occludedDirection.x = 0.0;
  this->occlusion = 1.0;
  this->occlusionParms->result.valid = 0;
  this->occlusionValidLastUpdate = false;
  this->areaNum = -1;
  this->debugName = "sounds";
}


// ========================================================================
// ?CheckForCompletion@idSoundEmitterLocal@@QAA_NH@Z
// EA  : 0x8298C3A0
// RVA : 0x0098C3A0
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

int __fastcall idSoundEmitterLocal::CheckForCompletion(idSoundEmitterLocal *this, int currentTime)
{
  int v4; // r29
  idStaticList<idSoundChannel *,16> *p_channels; // r30
  int v6; // r27
  idSoundChannel *v7; // r31
  int num; // r11
  int v9; // r11
  const idSoundShader *soundShader; // r11
  const idSoundShader *postSound; // r5
  unsigned __int8 v12; // r11

  v4 = this->channels.num - 1;
  if ( v4 >= 0 )
  {
    p_channels = &this->channels;
    v6 = v4;
    do
    {
      v7 = p_channels->list[v6];
      if ( (unsigned __int8)idSoundChannel::CheckForCompletion(this: v7, currentTime) != 0 )
      {
        num = p_channels->num;
        if ( v4 < num )
        {
          v9 = num - 1;
          p_channels->num = v9;
          if ( v4 != v9 )
            p_channels->list[v6] = p_channels->list[v9];
        }
        soundShader = v7->soundShader;
        if ( soundShader != nullptr )
        {
          postSound = soundShader->postSound;
          if ( postSound != nullptr )
            this->StartSound(this, a2: v7->logicalChannel, a3: postSound, a4: &soundShader->parms);
        }
        v7->channelNode.prev->next = v7->channelNode.next;
        v7->channelNode.next->prev = v7->channelNode.prev;
        v7->channelNode.next = &v7->channelNode;
        v7->channelNode.prev = &v7->channelNode;
        v7->channelNode.head = &v7->channelNode;
        idSoundWorldLocal::FreeSoundChannel(this: this->soundWorld, channel: v7);
      }
      --v4;
      --v6;
    }
    while ( v4 >= 0 );
  }
  if ( !this->canFree )
    return 0;
  v12 = 1;
  if ( this->channels.num != 0 )
    return 0;
  return v12;
}


// ========================================================================
// ?Update@idSoundEmitterLocal@@QAAMPAUlistener_t@@H@Z
// EA  : 0x8298C4C8
// RVA : 0x0098C4C8
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

float __fastcall idSoundEmitterLocal::Update(idSoundEmitterLocal *this, listener_t *listener, int currentTime)
{
  int v6; // r28
  int v7; // r29
  double v8; // fp1
  int v9; // r11
  bool v10; // r24
  int v11; // r29
  int v12; // r28
  idSoundChannel *v13; // r9
  int v14; // r28
  int v15; // r29
  double v16; // fp26
  double v17; // fp27
  double v18; // fp25
  idVec3 *p_pos; // r28
  idVec3 *p_origin; // r27
  char v21; // r6
  double v25; // fp2
  double v26; // fp8
  double v27; // fp23
  int v28; // r9
  idSoundChannel **list; // r8
  int v30; // r10
  int v31; // r7
  idSoundChannel *v32; // r11
  idVec3 *p_occludedDirection; // r29
  soundOcclusionParms_t *v37; // r11
  bool occlusionValidLastUpdate; // r24
  soundOcclusionParms_t *v39; // r11
  int areaNum; // r11
  idSoundWorldLocal *v41; // r11
  double v42; // fp12
  double v43; // fp10
  double v44; // fp9
  double v45; // fp8
  double v46; // fp7
  double v47; // fp6
  soundOcclusionParms_t *occlusionParms; // r11
  double x; // fp0
  double v50; // fp13
  double v51; // fp8
  double v52; // fp6
  double v53; // fp1
  double v54; // fp4
  double y; // fp2
  double z; // fp1
  double v57; // fp3
  soundOcclusionParms_t *v58; // r6
  double v59; // fp0
  double v60; // fp13
  double v61; // fp12
  double occludedDistance; // fp10
  double v63; // fp9
  double v64; // fp6
  idSoundWorldLocal *soundWorld; // r10
  double v66; // fp9
  double v67; // fp8
  double v68; // fp6
  soundOcclusionParms_t *v69; // r11
  soundOcclusionParms_t *v70; // r11
  soundOcclusionParms_t *v71; // r8
  soundOcclusionParms_t *v72; // r11
  int v73; // r29
  int v74; // r28
  idSoundWorldLocal *v75; // r9
  soundOcclusionParms_t *v76; // r10
  int v77; // r11
  int v78; // r28
  int v79; // r29
  idSoundChannel *v80; // r3
  char v81; // r10
  double v82; // fp0
  int v83; // r28
  int v84; // r29
  idSoundChannel *v85; // r11
  double v86; // fp13
  double v87; // fp12
  double v88; // fp11
  double v89; // fp10
  long double v90; // fp2
  double v91; // fp0
  double v92; // fp0
  long double v93; // fp2
  long double v94; // fp2
  long double v95; // fp2
  int num; // [sp+50h] [-150h] BYREF
  float v98; // [sp+54h] [-14Ch]
  float v99[4]; // [sp+58h] [-148h] BYREF
  float v100[6]; // [sp+68h] [-138h] BYREF
  float v101[4]; // [sp+80h] [-120h] BYREF
  float v102[4]; // [sp+90h] [-110h] BYREF
  float v103[4]; // [sp+A0h] [-100h] BYREF
  idStr v104[4]; // [sp+B0h] [-F0h] BYREF

  if ( listener == nullptr || (num = this->channels.num, *(float *)&num == 0.0) )
  {
LABEL_10:
    v8 = -60.0;
    return *((float *)&v8 + 1);
  }
  if ( s_singleEmitter.valueInteger > 0 && s_singleEmitter.valueInteger != this->index
    || s_singleEntity.valueInteger > 0 && s_singleEntity.valueInteger != this->emitterId - 1 )
  {
    v6 = 0;
    if ( num > 0 )
    {
      v7 = 0;
      do
      {
        idSoundChannel::SetSilent(this: this->channels.list[v7]);
        ++v6;
        ++v7;
      }
      while ( v6 < this->channels.num );
    }
    goto LABEL_10;
  }
  v9 = 0;
  if ( *s_soundGroupFilter.valueString.data == 0 )
    goto LABEL_24;
  do
    ++v9;
  while ( s_soundGroupFilter.valueString.data[v9] != 0 );
  if ( v9 == 0 || idStr::Icmp(s1: s_soundGroupFilter.valueString.data, s2: "off") == 0 )
    goto LABEL_24;
  v10 = false;
  v11 = 0;
  if ( this->channels.num > 0 )
  {
    v12 = 0;
    do
    {
      if ( v10 )
        break;
      v13 = this->channels.list[v12];
      v104[0].allocedAndFlag = 20;
      v104[0].data = v104[0].baseBuffer;
      v104[0].len = 0;
      v104[0].baseBuffer[0] = 0;
      idTypeInfoTools::GetEnumBitFlags(
        this: typeInfoTools,
        flags: v13->parms.groups,
        enumType: "soundShaderGroups_t",
        flagNames: v104,
        delimiter: " ");
      v10 = idStr::Find(
              searchIn: v104[0].data,
              searchFor: s_soundGroupFilter.valueString.data,
              casesensitive: false,
              start: 0,
              end: v104[0].len) != -1;
      idStr::FreeData(this: v104);
      ++v11;
      ++v12;
    }
    while ( v11 < this->channels.num );
  }
  if ( !v10 )
  {
    v14 = 0;
    if ( this->channels.num > 0 )
    {
      v15 = 0;
      do
      {
        idSoundChannel::SetSilent(this: this->channels.list[v15]);
        ++v14;
        ++v15;
      }
      while ( v14 < this->channels.num );
    }
    v8 = -60.0;
  }
  else
  {
LABEL_24:
    v16 = (float)(this->origin.z - listener->pos.z);
    v17 = (float)(this->origin.x - listener->pos.x);
    v18 = (float)(this->origin.y - listener->pos.y);
    p_pos = &listener->pos;
    p_origin = &this->origin;
    v21 = 0;
    _FP31 = 0.0;
    _FP5 = (float)((float)((float)((float)v18 * (float)v18)
                         + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f5, f6, f13 }
    v25 = __frsqrte(_FP3);
    v26 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25
                                                                                        * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
                                                                                                * (float)0.5))
                                                                                * (float)v25)
                                                                        - (float)1.5)
                                                        * (float)v25)
                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                + (float)((float)((float)v17 * (float)v17)
                                                                        + (float)((float)v16 * (float)v16)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v25
                                                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                                                + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
                                                                                        * (float)0.5))
                                                                        * (float)v25)
                                                                - (float)1.5)
                                                * (float)v25))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v25
                                                        * (float)((float)((float)((float)v18 * (float)v18)
                                                                        + (float)((float)((float)v17 * (float)v17)
                                                                                + (float)((float)v16 * (float)v16)))
                                                                * (float)0.5))
                                                * (float)v25)
                                        - (float)1.5)
                        * (float)v25));
    v27 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v25) - (float)1.5) * (float)v25)
                                                                                                * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v25) - (float)1.5)
                                                                                                * (float)v25))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                                * (float)v25)
                                                                                        - (float)1.5)
                                                                        * (float)v25))
                                                        * (float)((float)((float)((float)v18 * (float)v18)
                                                                        + (float)((float)((float)v17 * (float)v17)
                                                                                + (float)((float)v16 * (float)v16)))
                                                                * (float)0.5))
                                                * (float)v26)
                                        - (float)1.5)
                        * (float)v26)
                * (float)((float)((float)v18 * (float)v18)
                        + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))));
    if ( this->emitterId != listener->id && s_useOcclusion.valueInteger != 0 )
    {
      v28 = 0;
      if ( this->channels.num > 0 )
      {
        list = this->channels.list;
        v30 = 0;
        v31 = this->channels.num;
        do
        {
          v32 = list[v30];
          if ( (v32->parms.soundShaderFlags & 0xC) == 0 )
          {
            _FP0 = v32->parms.wetMaxDistanceOffset;
            __asm { fsel      f13, f0, f0, f28 }
            v21 = 1;
            _FP8 = (float)((float)_FP31
                         - (float)((float)((float)_FP13 + v32->parms.maxDistance) * v32->parms.distanceFactor));
            LODWORD(v98) = &v32->parms;
            __asm { fsel      f31, f8, f31, f9 }
          }
          ++v28;
          ++v30;
        }
        while ( v28 < v31 );
      }
    }
    this->occludedDirection.x = v17;
    this->occludedDirection.y = v18;
    this->occludedDirection.z = v16;
    this->occludedDistance = v27;
    p_occludedDirection = &this->occludedDirection;
    if ( v21 != 0 )
    {
      if ( v27 <= _FP31 )
      {
        areaNum = this->areaNum;
        this->occlusion = 0.0;
        if ( areaNum > 0 )
        {
          occlusionParms = this->occlusionParms;
          if ( occlusionParms->result.valid != 0 )
          {
            x = occlusionParms->result.virtualSoundOrigin.x;
            v50 = p_pos->x;
            v98 = *(float *)&this->occlusionParms;
            v51 = (float)(occlusionParms->result.virtualSoundOrigin.y - listener->pos.y);
            v52 = (float)(occlusionParms->result.virtualSoundOrigin.z - listener->pos.z);
            p_occludedDirection->x = (float)x - (float)v50;
            this->occludedDirection.y = v51;
            this->occludedDirection.z = v52;
            v53 = idVec3::NormalizeFast(this: &this->occludedDirection);
            occlusionValidLastUpdate = true;
            v54 = (float)((float)v53 + this->occlusionParms->result.occludedDistance);
            this->occludedDistance = (float)v53 + this->occlusionParms->result.occludedDistance;
            y = this->occludedDirection.y;
            z = this->occludedDirection.z;
            v57 = p_occludedDirection->x;
            v98 = v54;
            p_occludedDirection->x = (float)v57 * (float)v54;
            this->occludedDirection.z = (float)v54 * (float)z;
            this->occludedDirection.y = (float)v54 * (float)y;
            this->occlusion = (float)(this->occludedDistance - (float)v27) / s_occlusionDistance.valueFloat;
            if ( s_showPaths.valueInteger > 0 )
            {
              v58 = this->occlusionParms;
              v59 = listener->pos.y;
              v60 = listener->pos.z;
              v61 = p_pos->x;
              occludedDistance = this->occludedDistance;
              v63 = v58->result.virtualSoundOrigin.y;
              v98 = *(float *)&v58;
              v64 = (float)(v58->result.virtualSoundOrigin.z - (float)v60);
              if ( (float)((float)((float)occludedDistance * (float)occludedDistance)
                         + (float)((float)((float)(v58->result.virtualSoundOrigin.x - (float)v61)
                                         * (float)(v58->result.virtualSoundOrigin.x - (float)v61))
                                 + (float)((float)((float)v64 * (float)v64)
                                         + (float)((float)((float)v63 - (float)v59) * (float)((float)v63 - (float)v59))))) < (double)(float)((float)_FP31 * (float)_FP31) )
              {
                soundWorld = this->soundWorld;
                v66 = (float)(listener->axis.mat[0].y * (float)4.0);
                v67 = (float)(listener->axis.mat[0].z * (float)4.0);
                v68 = (float)(listener->axis.mat[0].x * (float)4.0);
                v102[0] = 1.0;
                v102[1] = 1.0;
                v102[2] = 0.0;
                v102[3] = 1.0;
                v100[1] = (float)v59 + (float)v66;
                v100[2] = (float)v60 + (float)v67;
                v100[0] = (float)v61 + (float)v68;
                soundWorld->renderWorld->DebugLine(
                  this: soundWorld->renderWorld,
                  a2: (const idVec4 *)v102,
                  a3: (const idVec3 *)v100,
                  a4: &v58->result.virtualSoundOrigin,
                  a5: 0,
                  a6: (_cntlzw(s_showPaths.valueInteger - 1) & 0x20) != 0);
              }
            }
          }
          else
          {
            occlusionValidLastUpdate = this->occlusionValidLastUpdate;
          }
          memcpy(
            Dst: &this->occlusionParms->flatBSP,
            Src: &this->soundWorld->sbspFile.flatBSP,
            Size: sizeof(this->occlusionParms->flatBSP));
          this->occlusionParms->listenerRoute = listener->route.list;
          this->occlusionParms->numAreas = this->soundWorld->sbspFile.areas.num;
          this->occlusionParms->doors = this->soundWorld->doors.list;
          this->occlusionParms->numDoors = this->soundWorld->sbspFile.numDoors;
          this->occlusionParms->listenerAreaNum = listener->area;
          v69 = this->occlusionParms;
          v69->listenerOrigin.x = p_pos->x;
          v69->listenerOrigin.y = listener->pos.y;
          v69->listenerOrigin.z = listener->pos.z;
          this->occlusionParms->soundAreaNum = this->areaNum;
          v70 = this->occlusionParms;
          v70->soundOrigin.x = p_origin->x;
          v70->soundOrigin.y = this->origin.y;
          v70->soundOrigin.z = this->origin.z;
          this->occlusionParms->maxDistance = _FP31;
          v71 = this->occlusionParms;
          v71->result.virtualSoundOrigin.x = p_origin->x;
          v71->result.virtualSoundOrigin.y = this->origin.y;
          v71->result.virtualSoundOrigin.z = this->origin.z;
          this->occlusionParms->result.occludedDistance = 0.0;
          this->occlusionParms->result.pathPoints = nullptr;
          this->occlusionParms->result.numPathPoints = 0;
          this->occlusionParms->result.maxPathPoints = 0;
          this->occlusionParms->result.valid = 0;
          if ( s_showPaths.valueInteger != 0 )
          {
            this->occlusionParms->result.maxPathPoints = 128;
            this->occlusionParms->result.pathPoints = (idVec3 *)idMem::AllocWithLocation(
                                                                  this: &mem,
                                                                  location: "w:\\tech5\\engine\\sound\\SoundEmitter.cpp(372) : TAG_SOUND",
                                                                  size: 12 * this->occlusionParms->result.maxPathPoints,
                                                                  tag: TAG_SOUND,
                                                                  zeroBuffer: false,
                                                                  align: ALIGN_16,
                                                                  heap: HEAP_DEFAULTHEAP);
            SoundOcclusionJob(parms: (idSBSPPlaneCache *)this->occlusionParms);
          }
          else if ( s_useSoundOcclusionJobs.valueInteger == 1 )
          {
            idParallelJobList::AddJob(
              this: soundSystemLocal.parallelJobList,
              function: (void (__fastcall *)(void *))SoundOcclusionJob,
              data: this->occlusionParms);
          }
          else
          {
            SoundOcclusionJob(parms: (idSBSPPlaneCache *)this->occlusionParms);
          }
          v72 = this->occlusionParms;
          if ( v72->result.pathPoints != nullptr )
          {
            v73 = 1;
            if ( v72->result.numPathPoints > 1 )
            {
              v74 = 1;
              do
              {
                v103[1] = 1.0;
                v75 = this->soundWorld;
                v103[2] = 0.0;
                v103[0] = 1.0;
                v76 = this->occlusionParms;
                v103[3] = 1.0;
                v75->renderWorld->DebugLine(
                  this: v75->renderWorld,
                  a2: (const idVec4 *)v103,
                  a3: &v76->result.pathPoints[v74 - 1],
                  a4: &v76->result.pathPoints[v74],
                  a5: 0,
                  a6: (_cntlzw(s_showPaths.valueInteger - 1) & 0x20) != 0);
                ++v73;
                ++v74;
              }
              while ( v73 < this->occlusionParms->result.numPathPoints );
            }
            idMem::Free(this: &mem, ptr: this->occlusionParms->result.pathPoints, align: ALIGN_16);
            this->occlusionParms->result.pathPoints = nullptr;
          }
        }
        else
        {
          if ( s_showPaths.valueInteger > 0 )
          {
            v41 = this->soundWorld;
            v42 = (float)(listener->axis.mat[0].x * (float)4.0);
            v43 = (float)(listener->axis.mat[0].y * (float)4.0);
            v44 = (float)(listener->axis.mat[0].z * (float)4.0);
            v45 = p_pos->x;
            v46 = listener->pos.y;
            v47 = listener->pos.z;
            v101[0] = 1.0;
            v101[1] = 0.0;
            v101[2] = 1.0;
            v101[3] = 1.0;
            v99[0] = (float)v45 + (float)v42;
            v99[1] = (float)v46 + (float)v43;
            v99[2] = (float)v47 + (float)v44;
            v41->renderWorld->DebugLine(
              this: v41->renderWorld,
              a2: (const idVec4 *)v101,
              a3: (const idVec3 *)v99,
              a4: &this->origin,
              a5: 0,
              a6: false);
          }
          occlusionValidLastUpdate = true;
          this->occlusionParms->result.valid = 0;
        }
      }
      else
      {
        v39 = this->occlusionParms;
        this->occlusion = 1.0;
        occlusionValidLastUpdate = true;
        v39->result.valid = 0;
      }
    }
    else
    {
      v37 = this->occlusionParms;
      this->occlusion = 0.0;
      occlusionValidLastUpdate = true;
      v37->result.valid = 0;
    }
    v77 = this->channels.num;
    *(float *)&num = 0.0;
    this->occlusionValidLastUpdate = occlusionValidLastUpdate;
    v78 = 0;
    if ( v77 > 0 )
    {
      v79 = 0;
      do
      {
        if ( occlusionValidLastUpdate || ((v80 = this->channels.list[v79])->parms.soundShaderFlags & 0xC) != 0 )
          idSoundChannel::UpdateVolume(
            this: this->channels.list[v79],
            listener,
            currentTime,
            maxDBForHDR: (float *)&num);
        else
          idSoundChannel::SetSilent(this: v80);
        ++v78;
        ++v79;
      }
      while ( v78 < this->channels.num );
    }
    if ( v27 > 0.0 )
    {
      v81 = 0;
      v82 = 0.0;
      v83 = 0;
      if ( this->channels.num > 0 )
      {
        v84 = 0;
        do
        {
          v85 = this->channels.list[v84];
          if ( (v85->parms.soundShaderFlags & 0x800000) != 0 )
          {
            if ( v81 == 0 )
            {
              v86 = this->velocity.y;
              v87 = listener->vel.y;
              v88 = this->velocity.z;
              v89 = listener->vel.z;
              *((double *)&v90 + 1) = (float)((float)(this->velocity.z
                                                    * (float)((float)v16 * (float)((float)1.0 / (float)v27)))
                                            + (float)(this->velocity.y
                                                    * (float)((float)v18 * (float)((float)1.0 / (float)v27))));
              LODWORD(v98) = &this->velocity;
              v91 = (float)((float)((float)((float)((float)1.0 / (float)v27) * (float)v17) * this->velocity.x)
                          + (float)((float)((float)v88 * (float)((float)v16 * (float)((float)1.0 / (float)v27)))
                                  + (float)((float)v86 * (float)((float)v18 * (float)((float)1.0 / (float)v27)))));
              LODWORD(v98) = &listener->vel;
              v92 = (float)((float)((float)v91 + (float)10133.858)
                          / (float)((float)((float)(listener->vel.x
                                                  * (float)((float)((float)1.0 / (float)v27) * (float)v17))
                                          + (float)((float)((float)v89
                                                          * (float)((float)v16 * (float)((float)1.0 / (float)v27)))
                                                  + (float)((float)v87
                                                          * (float)((float)v18 * (float)((float)1.0 / (float)v27)))))
                                  + (float)10133.858));
              if ( v92 >= 0.25 )
              {
                if ( v92 <= 4.0 )
                {
                  *(double *)&v90 = v92;
                  if ( v92 <= 0.0 )
                  {
                    v82 = -999.0;
                  }
                  else
                  {
                    v95 = log(x: v90);
                    v82 = (float)((float)*(double *)&v95 * (float)17.31234);
                  }
                }
                else
                {
                  *(double *)&v90 = 4.0;
                  v94 = log(x: v90);
                  v82 = (float)((float)*(double *)&v94 * (float)17.31234);
                }
              }
              else
              {
                *(double *)&v90 = 0.25;
                v93 = log(x: v90);
                v82 = (float)((float)*(double *)&v93 * (float)17.31234);
              }
              v81 = 1;
            }
            this->channels.list[v84]->dopplerPitch = this->channels.list[v84]->parms.dopplerMultiplier * (float)v82;
          }
          else
          {
            v85->dopplerPitch = 0.0;
          }
          ++v83;
          ++v84;
        }
        while ( v83 < this->channels.num );
      }
    }
    v8 = *(float *)&num;
  }
  return *((float *)&v8 + 1);
}


// ========================================================================
// __unwind$225988_0
// EA  : 0x8298CE9C
// RVA : 0x0098CE9C
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_225988_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 176));
}


// ========================================================================
// ?UpdateEmitter@idSoundEmitterLocal@@UAAXABVidVec3@@ABVidMat3@@0H@Z
// EA  : 0x8298CEC8
// RVA : 0x0098CEC8
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __fastcall idSoundEmitterLocal::UpdateEmitter(
        idSoundEmitterLocal *this,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *velocity,
        int listenerId)
{
  char v9; // r11

  if ( this->origin.x != origin->x || this->origin.y != origin->y || (v9 = 1, this->origin.z != origin->z) )
    v9 = 0;
  if ( v9 == 0 || this->areaNum < 0 )
  {
    this->origin = *origin;
    this->areaNum = idSoundBSPFile::PointAreaNum(this: &this->soundWorld->sbspFile, point: origin);
  }
  this->axis.mat[0].x = axis->mat[0].x;
  this->axis.mat[0].y = axis->mat[0].y;
  this->axis.mat[0].z = axis->mat[0].z;
  this->axis.mat[1].x = axis->mat[1].x;
  this->axis.mat[1].y = axis->mat[1].y;
  this->axis.mat[1].z = axis->mat[1].z;
  this->axis.mat[2].x = axis->mat[2].x;
  this->axis.mat[2].y = axis->mat[2].y;
  this->axis.mat[2].z = axis->mat[2].z;
  this->velocity.x = velocity->x;
  this->velocity.y = velocity->y;
  this->velocity.z = velocity->z;
  this->emitterId = listenerId;
}


// ========================================================================
// ?OnReloadSound@idSoundEmitterLocal@@QAAXPBVidDecl@@@Z
// EA  : 0x8298CFC8
// RVA : 0x0098CFC8
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __fastcall idSoundEmitterLocal::OnReloadSound(idSoundEmitterLocal *this, const idSoundShader *decl)
{
  int v4; // r29
  idStaticList<idSoundChannel *,16> *p_channels; // r27
  int v6; // r24
  idSoundChannel *v7; // r31
  int v8; // r11
  int v9; // r11
  int num; // r11
  char v11; // r6
  int v12; // r9
  int v13; // r10
  signed int v14; // r5
  unsigned int v15; // r9
  _BYTE v16[148]; // [sp+50h] [-F0h] BYREF

  v4 = this->channels.num - 1;
  if ( v4 >= 0 )
  {
    p_channels = &this->channels;
    v6 = v4;
    do
    {
      v7 = p_channels->list[v6];
      if ( v7->soundShader == decl )
      {
        if ( decl->entries.num != 0 )
        {
          memcpy(Dst: v16, Src: &decl->parms, Size: sizeof(v16));
          memcpy(Dst: &v7->parms, Src: v16, Size: sizeof(v7->parms));
          num = decl->entries.num;
          v11 = 0;
          v12 = 0;
          if ( num > 0 )
          {
            v13 = 0;
            while ( v7->sample != decl->entries.list[v13] )
            {
              ++v12;
              ++v13;
              if ( v12 >= num )
                goto LABEL_15;
            }
            v11 = 1;
          }
LABEL_15:
          if ( v11 == 0 )
          {
            if ( num != 0 )
            {
              __twllei(num, 0);
              v14 = ((1664525 * soundSystemLocal.random.seed + 1013904223) >> 10) & 0x7FFF;
              soundSystemLocal.random.seed = 1664525 * soundSystemLocal.random.seed + 1013904223;
              v15 = num & ~(__ROL4__(v14, 1) - 1);
              num = v14 % num;
              __twlgei(v15, 0xFFFFFFFF);
            }
            v7->sample = decl->entries.list[num];
          }
        }
        else
        {
          idLib::Printf(fmt: "no samples in sound shader %s\n", decl->name.str);
          v8 = p_channels->num;
          if ( v4 < v8 )
          {
            v9 = v8 - 1;
            p_channels->num = v9;
            if ( v4 != v9 )
              p_channels->list[v6] = p_channels->list[v9];
          }
          idSoundWorldLocal::FreeSoundChannel(this: this->soundWorld, channel: v7);
        }
      }
      --v4;
      --v6;
    }
    while ( v4 >= 0 );
  }
}


// ========================================================================
// ?ModifySound@idSoundEmitterLocal@@UAAXW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@@Z
// EA  : 0x8298D160
// RVA : 0x0098D160
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __fastcall idSoundEmitterLocal::ModifySound(
        idSoundEmitterLocal *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        const soundShaderParms_t *overrideParms)
{
  char v8; // r22
  int v9; // r29
  idStaticList<idSoundChannel *,16> *p_channels; // r27
  int v11; // r24
  idSoundChannel *v12; // r31
  int num; // r11
  int v14; // r11
  double randomVolume; // fp13
  double min; // fp0
  double randomPitch; // fp0

  v8 = 0;
  v9 = this->channels.num - 1;
  if ( v9 >= 0 )
  {
    p_channels = &this->channels;
    v11 = v9;
    do
    {
      v12 = p_channels->list[v11];
      if ( channel == SND_CHANNEL_ANY || v12->logicalChannel == channel )
      {
        v8 = 1;
        if ( v12->soundShader == shader )
        {
          memcpy(Dst: &v12->parms, Src: &shader->parms, Size: sizeof(v12->parms));
          soundShaderParms_t::Override(this: &v12->parms, over: overrideParms);
          randomVolume = v12->randomVolume;
          min = v12->parms.volume.min;
          if ( randomVolume >= min )
          {
            if ( randomVolume <= v12->parms.volume.max )
              min = v12->randomVolume;
            else
              min = v12->parms.volume.max;
          }
          v12->randomVolume = min;
          randomPitch = v12->randomPitch;
          if ( randomPitch >= v12->parms.pitch.min )
          {
            if ( randomPitch > v12->parms.pitch.max )
              randomPitch = v12->parms.pitch.max;
          }
          else
          {
            randomPitch = v12->parms.pitch.min;
          }
          v12->randomPitch = randomPitch;
        }
        else
        {
          num = p_channels->num;
          if ( v9 < num )
          {
            v14 = num - 1;
            p_channels->num = v14;
            if ( v9 != v14 )
              p_channels->list[v11] = p_channels->list[v14];
          }
          idSoundWorldLocal::FreeSoundChannel(this: this->soundWorld, channel: v12);
          this->StartSound(this, a2: channel, a3: shader, a4: overrideParms);
        }
      }
      --v9;
      --v11;
    }
    while ( v9 >= 0 );
  }
  if ( v8 == 0 )
    this->StartSound(this, a2: channel, a3: shader, a4: overrideParms);
}


// ========================================================================
// ?IsCurrentlyPlaying@idSoundEmitterLocal@@UBA_NW4soundChannel_t@@@Z
// EA  : 0x8298D2E0
// RVA : 0x0098D2E0
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

unsigned int __fastcall idSoundEmitterLocal::IsCurrentlyPlaying(idSoundEmitterLocal *this, soundChannel_t channel)
{
  int num; // r8
  int v4; // r10
  int i; // r11

  if ( channel == SND_CHANNEL_ANY )
    return (-this->channels.num & (unsigned int)~this->channels.num) >> 31;
  num = this->channels.num;
  v4 = 0;
  if ( num <= 0 )
    return 0;
  for ( i = 0; this->channels.list[i]->logicalChannel != channel; ++i )
  {
    if ( ++v4 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?GetCurrentSoundShader@idSoundEmitterLocal@@UBAPBVidSoundShader@@W4soundChannel_t@@@Z
// EA  : 0x8298D348
// RVA : 0x0098D348
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

const idSoundShader *__fastcall idSoundEmitterLocal::GetCurrentSoundShader(
        idSoundEmitterLocal *this,
        soundChannel_t channel)
{
  int num; // r7
  int v3; // r9
  int i; // r11
  idSoundChannel *v5; // r10

  if ( channel == SND_CHANNEL_ANY )
    return nullptr;
  num = this->channels.num;
  v3 = 0;
  if ( num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v5 = this->channels.list[i];
    if ( v5->logicalChannel == channel )
      break;
    if ( ++v3 >= num )
      return nullptr;
  }
  return v5->soundShader;
}


// ========================================================================
// ?GetCurrentSample@idSoundEmitterLocal@@UBAPAVidSoundSample@@W4soundChannel_t@@@Z
// EA  : 0x8298D398
// RVA : 0x0098D398
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

idSoundSample *__fastcall idSoundEmitterLocal::GetCurrentSample(idSoundEmitterLocal *this, soundChannel_t channel)
{
  int num; // r7
  int v3; // r9
  int i; // r11
  idSoundChannel *v5; // r10

  if ( channel == SND_CHANNEL_ANY )
    return nullptr;
  num = this->channels.num;
  v3 = 0;
  if ( num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v5 = this->channels.list[i];
    if ( v5->logicalChannel == channel )
      break;
    if ( ++v3 >= num )
      return nullptr;
  }
  return v5->sample;
}


// ========================================================================
// ?GetCurrentSampleTime@idSoundEmitterLocal@@UBA?AV?$idTypesafeNumber@HW4millisecondUnique_t@@@@W4soundChannel_t@@@Z
// EA  : 0x8298D3E8
// RVA : 0x0098D3E8
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

idSoundEmitterLocal *__fastcall idSoundEmitterLocal::GetCurrentSampleTime(
        idSoundEmitterLocal *this,
        idTypesafeNumber<int,enum millisecondUnique_t> *result,
        soundChannel_t channel)
{
  int v4; // r8
  int v5; // r10
  int value; // r9
  int v7; // r11
  idTypesafeNumber<int,enum millisecondUnique_t> *v8; // r4

  if ( channel != SND_CHANNEL_ANY && (v4 = result[6].value, v5 = 0, v4 > 0) )
  {
    value = result[5].value;
    v7 = 0;
    while ( 1 )
    {
      v8 = *(idTypesafeNumber<int,enum millisecondUnique_t> **)(v7 + value);
      if ( v8[3].value == channel )
        break;
      ++v5;
      v7 += 4;
      if ( v5 >= v4 )
        goto LABEL_6;
    }
    idSoundChannel::GetCurrentSampleTime((idSoundChannel *)this, result: v8);
  }
  else
  {
LABEL_6:
    this->__vftable = (idSoundEmitterLocal_vtbl *)-1;
  }
  return this;
}


// ========================================================================
// ?GetDebugInfo@idSoundEmitterLocal@@UBA_NHPAUsoundDebugInfo_t@@@Z
// EA  : 0x8298D468
// RVA : 0x0098D468
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

int __fastcall idSoundEmitterLocal::GetDebugInfo(
        idSoundEmitterLocal *this,
        int channel,
        soundDebugInfo_t *soundDebugInfo)
{
  idSoundChannel *v6; // r30
  long double v7; // fp4
  long double v8; // fp2
  long double v9; // fp2
  double pitch; // fp8
  idSoundSample *sample; // r30
  idStr *p_sample; // r3

  memset(Dst: soundDebugInfo, Val: 0, Size: sizeof(soundDebugInfo_t));
  if ( channel < 0 || channel >= this->channels.num || soundDebugInfo == nullptr )
    return 0;
  v6 = this->channels.list[channel];
  soundDebugInfo->emitter = this;
  soundDebugInfo->playing = true;
  soundDebugInfo->looping = idSoundChannel::IsLooping(this: v6);
  soundDebugInfo->shader = v6->soundShader;
  soundDebugInfo->channel = v6->logicalChannel;
  soundDebugInfo->startTime = v6->startTime;
  soundDebugInfo->distance = v6->emitter->occludedDistance;
  if ( v6->hardwareVoice != nullptr )
  {
    *(_QWORD *)&v8 = 0x4000000000000000LL;
    *((double *)&v8 + 1) = (float)(v6->volumeDB * (float)0.16666667);
    v9 = pow(x: v8, y: v7);
    soundDebugInfo->volume = *(double *)&v9;
    soundDebugInfo->voiceVolume = v6->hardwareVoice->gain;
    soundDebugInfo->voiceDryVolume = v6->hardwareVoice->dryGain;
    soundDebugInfo->voiceWetVolume = v6->hardwareVoice->wetGain;
    pitch = v6->hardwareVoice->pitch;
    soundDebugInfo->hardwareVoice = true;
    soundDebugInfo->pitch = pitch;
  }
  else
  {
    soundDebugInfo->hardwareVoice = false;
    soundDebugInfo->volume = 0.0;
    soundDebugInfo->pitch = 1.0;
  }
  sample = v6->sample;
  p_sample = &soundDebugInfo->sample;
  if ( sample != nullptr )
  {
    idStr::operator=(this: p_sample, text: sample->name.str);
    soundDebugInfo->isdefault = (_cntlzw(-1 - sample->timestamp) & 0x20) != 0;
    soundDebugInfo->iscompressed = sample->format.basic.formatTag
                                 - 1
                                 - (sample->format.basic.formatTag
                                  - 2
                                  + (sample->format.basic.formatTag == 1));
    soundDebugInfo->isstereo = sample->format.basic.numChannels > 1u;
  }
  else
  {
    idStr::operator=(this: p_sample, text: "<NULL>");
    soundDebugInfo->isdefault = true;
    soundDebugInfo->iscompressed = false;
    soundDebugInfo->isstereo = false;
  }
  return 1;
}


// ========================================================================
// ?Reset@idSoundEmitterLocal@@UAAXXZ
// EA  : 0x8298D610
// RVA : 0x0098D610
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __fastcall idSoundEmitterLocal::Reset(idSoundEmitterLocal *this)
{
  int v2; // r29
  int v3; // r30
  idSoundChannel **list; // r4

  v2 = 0;
  if ( this->channels.num > 0 )
  {
    v3 = 0;
    do
    {
      idSoundWorldLocal::FreeSoundChannel(this: this->soundWorld, channel: this->channels.list[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->channels.num );
  }
  if ( this->channels.listStatic == 0 || this->channels.listStatic == 2 )
  {
    list = this->channels.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->channels.list = nullptr;
    this->channels.size = 0;
  }
  this->channels.num = 0;
  this->canFree = false;
  this->volumeAdjustment = 0.0;
  this->origin.z = 0.0;
  this->origin.y = 0.0;
  this->origin.x = 0.0;
  this->axis.mat[2].z = 1.0;
  this->axis.mat[1].y = 1.0;
  this->axis.mat[0].x = 1.0;
  this->axis.mat[1].z = 0.0;
  this->axis.mat[0].z = 0.0;
  this->axis.mat[0].y = 0.0;
  this->axis.mat[2].y = 0.0;
  this->axis.mat[2].x = 0.0;
  this->axis.mat[1].x = 0.0;
  this->velocity.z = 0.0;
  this->velocity.y = 0.0;
  this->velocity.x = 0.0;
  this->emitterId = 0;
  this->occludedDistance = 0.0;
  this->occludedDirection.z = 0.0;
  this->occludedDirection.y = 0.0;
  this->occludedDirection.x = 0.0;
  this->occlusion = 1.0;
  this->occlusionParms->result.valid = 0;
  this->occlusionValidLastUpdate = false;
  this->areaNum = -1;
  this->debugName = "sounds";
}


// ========================================================================
// ?Free@idSoundEmitterLocal@@UAAX_N@Z
// EA  : 0x8298D738
// RVA : 0x0098D738
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __fastcall idSoundEmitterLocal::Free(idSoundEmitterLocal *this, bool immediate)
{
  bool v4; // r23
  int v5; // r30
  int v6; // r29
  idSoundChannel *v7; // r9
  const char *v8; // r30
  int index; // r29
  int v10; // r3
  idStr v11; // [sp+50h] [-A0h] BYREF
  idStr v12[4]; // [sp+70h] [-80h] BYREF

  if ( !this->canFree )
  {
    if ( s_showStopSound.valueInteger != 0 )
    {
      idStr::idStr(this: v12, text: s_soundGroupFilter.valueString.data);
      v4 = true;
      if ( v12[0].len != 0 && idStr::Cmp(s1: v12[0].data, s2: "off") != 0 )
      {
        v4 = false;
        v5 = 0;
        if ( this->channels.num > 0 )
        {
          v6 = 0;
          do
          {
            if ( v4 )
              break;
            v7 = this->channels.list[v6];
            v11.allocedAndFlag = 20;
            v11.data = v11.baseBuffer;
            v11.len = 0;
            v11.baseBuffer[0] = 0;
            idTypeInfoTools::GetEnumBitFlags(
              this: typeInfoTools,
              flags: v7->parms.groups,
              enumType: "soundShaderGroups_t",
              flagNames: &v11,
              delimiter: " ");
            v4 = idStr::Find(searchIn: v11.data, searchFor: v12[0].data, casesensitive: false, start: 0, end: v11.len) != -1;
            idStr::FreeData(this: &v11);
            ++v5;
            ++v6;
          }
          while ( v5 < this->channels.num );
        }
      }
      if ( v4 )
      {
        if ( immediate )
          v8 = "immediate";
        else
          v8 = "delayed";
        index = this->index;
        v10 = this->soundWorld->GetSoundTime(this: this->soundWorld);
        idLib::Printf(fmt: "%ims: FreeSound (%i,%s)\n", v10, index, v8);
      }
      idStr::FreeData(this: v12);
    }
    if ( immediate )
      this->Reset(this);
    this->canFree = true;
  }
}


// ========================================================================
// __unwind$227124
// EA  : 0x8298D8F4
// RVA : 0x0098D8F4
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_227124()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$227125
// EA  : 0x8298D91C
// RVA : 0x0098D91C
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_227125()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// ?StopSound@idSoundEmitterLocal@@UAAXW4soundChannel_t@@@Z
// EA  : 0x8298D950
// RVA : 0x0098D950
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __fastcall idSoundEmitterLocal::StopSound(idSoundEmitterLocal *this, soundChannel_t channel)
{
  int v4; // r15
  idSoundChannel *v5; // r30
  bool v6; // r29
  int index; // r29
  int v8; // r3
  __int64 v9; // r7
  int v10; // [sp+50h] [-100h]
  idStr v11; // [sp+60h] [-F0h] BYREF
  idStr v12; // [sp+80h] [-D0h] BYREF

  v10 = 0;
  if ( this->channels.num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = this->channels.list[v4];
      if ( channel == SND_CHANNEL_ANY || v5->logicalChannel == channel )
      {
        if ( s_showStopSound.valueInteger != 0 )
        {
          idStr::idStr(this: &v12, text: s_soundGroupFilter.valueString.data);
          v6 = true;
          if ( v12.len != 0 && idStr::Cmp(s1: v12.data, s2: "off") != 0 )
          {
            v11.allocedAndFlag = 20;
            v11.len = 0;
            v11.data = v11.baseBuffer;
            v11.baseBuffer[0] = 0;
            idTypeInfoTools::GetEnumBitFlags(
              this: typeInfoTools,
              flags: v5->parms.groups,
              enumType: "soundShaderGroups_t",
              flagNames: &v11,
              delimiter: " ");
            v6 = idStr::Find(searchIn: v11.data, searchFor: v12.data, casesensitive: false, start: 0, end: v11.len) != -1;
            idStr::FreeData(this: &v11);
          }
          if ( v6 )
          {
            index = this->index;
            v8 = this->soundWorld->GetSoundTime(this: this->soundWorld);
            idLib::Printf(fmt: "%ims: StopSound (%i,%i)\n", v8, index, channel);
          }
          idStr::FreeData(this: &v12);
        }
        if ( idSoundChannel::IsLooping(this: v5)
          && (v5->parms.soundShaderFlags & 0x2000000) != 0
          && v5->parms.loopFadeOutDuration > 0.0 )
        {
          ((void (__fastcall *)(idSoundEmitterLocal *, soundChannel_t, double))this->FadeSound)(
            a1: this,
            a2: channel,
            a3: -60.0);
          LODWORD(v9) = this->soundWorld->GetSoundTime(this: this->soundWorld);
          v5->endTime = (int)(float)((float)(v5->parms.loopFadeOutDuration * (float)1000.0) + (float)v9);
        }
        else
        {
          v5->endTime = 1;
        }
      }
      ++v4;
      ++v10;
    }
    while ( v10 < this->channels.num );
  }
}


// ========================================================================
// __unwind$227225
// EA  : 0x8298DB8C
// RVA : 0x0098DB8C
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_227225()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 128));
}


// ========================================================================
// __unwind$227226
// EA  : 0x8298DBB4
// RVA : 0x0098DBB4
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_227226()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 96));
}


// ========================================================================
// ?SetVolume@idSoundEmitterLocal@@UAAXW4soundChannel_t@@M@Z
// EA  : 0x8298DBE8
// RVA : 0x0098DBE8
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __fastcall idSoundEmitterLocal::SetVolume(idSoundEmitterLocal *this, soundChannel_t channel, double volume)
{
  bool v6; // r24
  int v7; // r30
  int v8; // r29
  idSoundChannel *v9; // r9
  int v10; // r9
  int v11; // r10
  idSoundChannel *v12; // r11
  idStr v13; // [sp+60h] [-B0h] BYREF
  idStr v14; // [sp+80h] [-90h] BYREF

  if ( s_showStartSound.valueInteger > 1 )
  {
    idStr::idStr(this: &v14, text: s_soundGroupFilter.valueString.data);
    v6 = true;
    if ( v14.len != 0 && idStr::Cmp(s1: v14.data, s2: "off") != 0 )
    {
      v6 = false;
      v7 = 0;
      if ( this->channels.num > 0 )
      {
        v8 = 0;
        do
        {
          if ( v6 )
            break;
          v9 = this->channels.list[v8];
          v13.allocedAndFlag = 20;
          v13.data = v13.baseBuffer;
          v13.len = 0;
          v13.baseBuffer[0] = 0;
          idTypeInfoTools::GetEnumBitFlags(
            this: typeInfoTools,
            flags: v9->parms.groups,
            enumType: "soundShaderGroups_t",
            flagNames: &v13,
            delimiter: " ");
          v6 = idStr::Find(searchIn: v13.data, searchFor: v14.data, casesensitive: false, start: 0, end: v13.len) != -1;
          idStr::FreeData(this: &v13);
          ++v7;
          ++v8;
        }
        while ( v7 < this->channels.num );
      }
    }
    if ( v6 )
      idLib::Printf(fmt: "SetVolume(%i,%i): %g\n", this->index, channel, volume);
    idStr::FreeData(this: &v14);
  }
  v10 = 0;
  if ( this->channels.num > 0 )
  {
    v11 = 0;
    do
    {
      v12 = this->channels.list[v11];
      if ( channel == SND_CHANNEL_ANY || v12->logicalChannel == channel )
      {
        v12->volumeFade.fadeStartVolume = volume;
        v12->volumeFade.fadeEndVolume = volume;
        v12->volumeFade.fadeStartTime = 0;
        v12->volumeFade.fadeEndTime = 0;
      }
      ++v10;
      ++v11;
    }
    while ( v10 < this->channels.num );
  }
}


// ========================================================================
// __unwind$227329
// EA  : 0x8298DDA8
// RVA : 0x0098DDA8
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_227329()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 128));
}


// ========================================================================
// __unwind$227330
// EA  : 0x8298DDD0
// RVA : 0x0098DDD0
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_227330()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// ?SetPitch@idSoundEmitterLocal@@UAAXW4soundChannel_t@@M@Z
// EA  : 0x8298DE00
// RVA : 0x0098DE00
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __fastcall idSoundEmitterLocal::SetPitch(idSoundEmitterLocal *this, soundChannel_t channel, double pitch)
{
  bool v6; // r24
  int v7; // r30
  int v8; // r29
  idSoundChannel *v9; // r9
  int v10; // r9
  int v11; // r10
  idSoundChannel *v12; // r11
  idStr v13; // [sp+60h] [-B0h] BYREF
  idStr v14; // [sp+80h] [-90h] BYREF

  if ( s_showStartSound.valueInteger > 1 )
  {
    idStr::idStr(this: &v14, text: s_soundGroupFilter.valueString.data);
    v6 = true;
    if ( v14.len != 0 && idStr::Cmp(s1: v14.data, s2: "off") != 0 )
    {
      v6 = false;
      v7 = 0;
      if ( this->channels.num > 0 )
      {
        v8 = 0;
        do
        {
          if ( v6 )
            break;
          v9 = this->channels.list[v8];
          v13.allocedAndFlag = 20;
          v13.data = v13.baseBuffer;
          v13.len = 0;
          v13.baseBuffer[0] = 0;
          idTypeInfoTools::GetEnumBitFlags(
            this: typeInfoTools,
            flags: v9->parms.groups,
            enumType: "soundShaderGroups_t",
            flagNames: &v13,
            delimiter: " ");
          v6 = idStr::Find(searchIn: v13.data, searchFor: v14.data, casesensitive: false, start: 0, end: v13.len) != -1;
          idStr::FreeData(this: &v13);
          ++v7;
          ++v8;
        }
        while ( v7 < this->channels.num );
      }
    }
    if ( v6 )
      idLib::Printf(fmt: "SetPitch(%i,%i): %g\n", this->index, channel, pitch);
    idStr::FreeData(this: &v14);
  }
  v10 = 0;
  if ( this->channels.num > 0 )
  {
    v11 = 0;
    do
    {
      v12 = this->channels.list[v11];
      if ( channel == SND_CHANNEL_ANY || v12->logicalChannel == channel )
      {
        v12->pitchFade.fadeStartVolume = pitch;
        v12->pitchFade.fadeEndVolume = pitch;
        v12->pitchFade.fadeStartTime = 0;
        v12->pitchFade.fadeEndTime = 0;
      }
      ++v10;
      ++v11;
    }
    while ( v10 < this->channels.num );
  }
}


// ========================================================================
// __unwind$227442
// EA  : 0x8298DFC0
// RVA : 0x0098DFC0
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_227442()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 128));
}


// ========================================================================
// __unwind$227443
// EA  : 0x8298DFE8
// RVA : 0x0098DFE8
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_227443()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// ?FadeSound@idSoundEmitterLocal@@UAAXW4soundChannel_t@@MMM_N@Z
// EA  : 0x8298E010
// RVA : 0x0098E010
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __fastcall idSoundEmitterLocal::FadeSound(
        idSoundEmitterLocal *this,
        soundChannel_t channel,
        double toDB,
        double overSec,
        double delaySec,
        bool additive,
        int a7,
        int a8,
        char a9)
{
  int v13; // r26
  int v14; // r30
  int v15; // r28
  int v16; // r27
  idSoundChannel *v17; // r31
  __int64 v18; // r8
  int v19; // r5
  int v20; // r3
  double v21; // fp6
  double Volume; // fp1
  int v23; // r4
  int v24; // r6
  double v25; // fp6

  v13 = 0;
  v14 = (int)(float)((float)1000.0 * (float)overSec);
  v15 = (int)(float)((float)1000.0 * (float)delaySec);
  if ( this->channels.num > 0 )
  {
    v16 = 0;
    do
    {
      v17 = this->channels.list[v16];
      if ( channel == SND_CHANNEL_ANY || v17->logicalChannel == channel )
      {
        v20 = ((int (*)(void))this->soundWorld->GetSoundTime)();
        if ( a9 != 0 )
          v21 = (float)(v17->volumeFade.fadeEndVolume + (float)toDB);
        else
          v21 = (float)((float)toDB - v17->randomVolume);
        if ( v17->volumeFade.fadeEndTime != v20 + v14 || v17->volumeFade.fadeEndVolume != v21 )
        {
          LODWORD(v18) = v20 + v14;
          Volume = idSoundFade::GetVolume(this: &v17->volumeFade, soundTime: v20, a3: v19, a4: v18);
          *(_DWORD *)(v24 + 4) = v23 + v15 + v14;
          *(_DWORD *)v24 = v23 + v15;
          *(float *)(v24 + 12) = v25;
          *(float *)(v24 + 8) = Volume;
        }
      }
      ++v13;
      ++v16;
    }
    while ( v13 < this->channels.num );
  }
}


// ========================================================================
// ?FadePitch@idSoundEmitterLocal@@UAAXW4soundChannel_t@@MMM@Z
// EA  : 0x8298E128
// RVA : 0x0098E128
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __fastcall idSoundEmitterLocal::FadePitch(
        idSoundEmitterLocal *this,
        soundChannel_t channel,
        double toST,
        double overSec,
        double delaySec)
{
  int v8; // r26
  int v9; // r29
  int v10; // r27
  int v11; // r28
  idSoundChannel *v12; // r31
  __int64 v13; // r7
  int v14; // r3
  int fadeEndTime; // r10
  idSoundFade *p_pitchFade; // r11
  int fadeStartTime; // r9
  __int64 v18; // r9
  double fadeStartVolume; // fp0

  v8 = 0;
  v9 = (int)(float)((float)1000.0 * (float)overSec);
  v10 = (int)(float)((float)1000.0 * (float)delaySec);
  if ( this->channels.num > 0 )
  {
    v11 = 0;
    do
    {
      v12 = this->channels.list[v11];
      if ( channel == SND_CHANNEL_ANY || v12->logicalChannel == channel )
      {
        v14 = this->soundWorld->GetSoundTime(this: this->soundWorld);
        fadeEndTime = v12->pitchFade.fadeEndTime;
        p_pitchFade = &v12->pitchFade;
        if ( fadeEndTime != v14 + v9 || v12->pitchFade.fadeEndVolume != toST )
        {
          fadeStartTime = p_pitchFade->fadeStartTime;
          LODWORD(v13) = fadeEndTime - p_pitchFade->fadeStartTime;
          if ( (float)v13 > 0.0 )
          {
            if ( v14 < fadeEndTime )
            {
              if ( v14 <= fadeStartTime )
              {
                fadeStartVolume = v12->pitchFade.fadeStartVolume;
              }
              else
              {
                HIDWORD(v18) = fadeEndTime - p_pitchFade->fadeStartTime;
                LODWORD(v18) = v14 - fadeStartTime;
                fadeStartVolume = (float)((float)((float)((float)v18 / (float)v13)
                                                * (float)(v12->pitchFade.fadeEndVolume - v12->pitchFade.fadeStartVolume))
                                        + v12->pitchFade.fadeStartVolume);
              }
            }
            else
            {
              fadeStartVolume = v12->pitchFade.fadeEndVolume;
            }
          }
          else
          {
            fadeStartVolume = v12->pitchFade.fadeEndVolume;
          }
          v12->pitchFade.fadeStartVolume = fadeStartVolume;
          v12->pitchFade.fadeEndVolume = toST;
          p_pitchFade->fadeStartTime = v14 + v10;
          v12->pitchFade.fadeEndTime = v14 + v10 + v9;
        }
      }
      ++v8;
      ++v11;
    }
    while ( v8 < this->channels.num );
  }
}


// ========================================================================
// ?GetRemainingSampleTime@idSoundEmitterLocal@@UBA?AV?$idTypesafeNumber@HW4millisecondUnique_t@@@@W4soundChannel_t@@@Z
// EA  : 0x8298E298
// RVA : 0x0098E298
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

idSoundEmitterLocal *__fastcall idSoundEmitterLocal::GetRemainingSampleTime(
        idSoundEmitterLocal *this,
        idTypesafeNumber<int,enum millisecondUnique_t> *result,
        soundChannel_t channel)
{
  int value; // r8
  int v5; // r10
  int v6; // r9
  int v7; // r11
  idTypesafeNumber<int,enum millisecondUnique_t> *v8; // r31
  idSoundEmitterLocal *v9; // r3
  _DWORD *v10; // r30
  unsigned int v11; // r9
  int v12; // r11
  int v13; // [sp+50h] [-30h] BYREF

  if ( channel == SND_CHANNEL_ANY )
    goto LABEL_6;
  value = result[6].value;
  v5 = 0;
  if ( value <= 0 )
    goto LABEL_6;
  v6 = result[5].value;
  v7 = 0;
  while ( 1 )
  {
    v8 = *(idTypesafeNumber<int,enum millisecondUnique_t> **)(v7 + v6);
    if ( v8[3].value == channel )
      break;
    ++v5;
    v7 += 4;
    if ( v5 >= value )
      goto LABEL_6;
  }
  if ( !idSoundChannel::IsLooping(this: *(idSoundChannel **)(v7 + v6)) && (v10 = (_DWORD *)v8[42].value) != nullptr )
  {
    idSoundChannel::GetCurrentSampleTime(this: (idSoundChannel *)&v13, result: v8);
    v11 = v10[24];
    v9 = this;
    if ( v11 >= 0x64 )
    {
      v12 = v10[12] + v10[11];
      __twllei(v11 / 0x64, 0);
      this->__vftable = (idSoundEmitterLocal_vtbl *)(10 * v12 / (v11 / 0x64) - v13);
    }
    else
    {
      this->__vftable = (idSoundEmitterLocal_vtbl *)-v13;
    }
  }
  else
  {
LABEL_6:
    this->__vftable = (idSoundEmitterLocal_vtbl *)-1;
    return this;
  }
  return v9;
}


// ========================================================================
// ?DrawDebugInfo@idSoundEmitterLocal@@QAAXPAVidRenderWorld@@@Z
// EA  : 0x8298E398
// RVA : 0x0098E398
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __fastcall idSoundEmitterLocal::DrawDebugInfo(idSoundEmitterLocal *this, idRenderWorld *rw)
{
  int v4; // r9
  int v6; // r10
  idSoundChannel *v7; // r11
  bool v11; // r24
  int v12; // r30
  int v13; // r29
  idSoundChannel *v14; // r9
  double v15; // fp30
  float y; // r8
  float z; // r6
  idSoundEmitterLocal_vtbl *v18; // r5
  const idVec3 *(__fastcall *GetPosition)(struct idSoundEmitterLocal *); // ctr
  const idVec3 *v40; // r3
  listener_t *BestListenerForEmitter; // r3
  idRenderWorld_vtbl *v42; // r10
  listener_t *v43; // r30
  void (__fastcall *DebugBounds)(idRenderWorld *, const idVec4 *, const idBounds *, const idVec3 *, const int, const bool); // r9
  __int64 v45; // r8
  __int64 v46; // r6
  __int64 v47; // r10
  va *v48; // r3
  int v49; // r10
  int v50; // r15
  int v51; // r18
  idSoundChannel *v52; // r25
  const char *v57; // r9
  double v58; // fp29
  const idSoundShader *soundShader; // r11
  double occludedDistance; // fp13
  int v61; // r8
  idRenderWorld_vtbl *v62; // r6
  idSoundSample *sample; // r10
  int channelMask; // r7
  int numChannels; // r29
  int *v66; // r11
  int i; // ctr
  char *v68; // r10
  int v69; // r11
  int v70; // r9
  int v71; // r8
  char *v72; // r27
  double v73; // fp0
  double v74; // fp13
  double x; // fp12
  double v76; // fp11
  idVec2 *v77; // r11
  double v78; // fp10
  double v79; // fp9
  double v80; // fp8
  double v81; // fp7
  double v82; // fp6
  double v83; // fp4
  double v84; // fp2
  double v85; // fp1
  double v86; // fp5
  double v87; // fp3
  void (__fastcall *v88)(idRenderWorld *, const idVec4 *, const idBounds *, const idVec3 *, const int, const bool); // ctr
  idRenderWorld_vtbl *v89; // r11
  idRenderWorld_vtbl *v90; // r11
  double v91; // fp12
  double v92; // fp10
  double v93; // fp9
  void (__fastcall *DebugCone)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, float, const int, const bool); // r10
  idRenderWorld_vtbl *v95; // r7
  double v96; // fp4
  double v97; // fp2
  void (__fastcall *v98)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, float, const int, const bool); // r11
  int v99; // [sp+8h] [-16B8h]
  int v100; // [sp+Ch] [-16B4h]
  int v101; // [sp+10h] [-16B0h]
  int v102; // [sp+14h] [-16ACh]
  int v103; // [sp+18h] [-16A8h]
  int v104; // [sp+1Ch] [-16A4h]
  _DWORD v105[2]; // [sp+60h] [-1660h] BYREF
  float v106; // [sp+68h] [-1658h]
  int num; // [sp+70h] [-1650h]
  int v108; // [sp+74h] [-164Ch]
  float v109[4]; // [sp+78h] [-1648h] BYREF
  float v110[4]; // [sp+88h] [-1638h] BYREF
  float v111[6]; // [sp+98h] [-1628h] BYREF
  float v112[4]; // [sp+B0h] [-1610h] BYREF
  float v113[4]; // [sp+C0h] [-1600h] BYREF
  float v114[4]; // [sp+D0h] [-15F0h] BYREF
  float v115[4]; // [sp+E0h] [-15E0h] BYREF
  float v116[4]; // [sp+F0h] [-15D0h] BYREF
  float v117[4]; // [sp+100h] [-15C0h] BYREF
  float v118[4]; // [sp+110h] [-15B0h] BYREF
  float v119[8]; // [sp+120h] [-15A0h] BYREF
  float v120[8]; // [sp+140h] [-1580h] BYREF
  idStr v121; // [sp+160h] [-1560h] BYREF
  int v123; // [sp+184h] [-153Ch]
  idStr v124; // [sp+190h] [-1530h] BYREF
  int v125; // [sp+1B0h] [-1510h] BYREF
  char v126[1024]; // [sp+1E0h] [-14E0h] BYREF
  va v127; // [sp+5E0h] [-10E0h] BYREF

  v4 = 0;
  num = this->channels.num;
  _FP30 = 0.0;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      v7 = this->channels.list[v6];
      ++v4;
      ++v6;
      _FP0 = v7->parms.wetMaxDistanceOffset;
      __asm { fsel      f13, f0, f0, f31 }
      _FP8 = (float)((float)_FP30 - (float)((float)((float)_FP13 + v7->parms.maxDistance) * v7->parms.distanceFactor));
      __asm { fsel      f30, f8, f30, f9 }
    }
    while ( v4 < num );
  }
  if ( this->occludedDistance < _FP30 )
  {
    idStr::idStr(this: &v124, text: s_soundGroupFilter.valueString.data);
    if ( v124.len == 0 || idStr::Cmp(s1: v124.data, s2: "off") == 0 )
      goto LABEL_12;
    v11 = false;
    v12 = 0;
    if ( this->channels.num > 0 )
    {
      v13 = 0;
      do
      {
        if ( v11 )
          break;
        v14 = this->channels.list[v13];
        v121.allocedAndFlag = 20;
        v121.data = v121.baseBuffer;
        v121.len = 0;
        v121.baseBuffer[0] = 0;
        idTypeInfoTools::GetEnumBitFlags(
          this: typeInfoTools,
          flags: v14->parms.groups,
          enumType: "soundShaderGroups_t",
          flagNames: &v121,
          delimiter: " ");
        v11 = idStr::Find(searchIn: v121.data, searchFor: v124.data, casesensitive: false, start: 0, end: v121.len) != -1;
        idStr::FreeData(this: &v121);
        ++v12;
        ++v13;
      }
      while ( v12 < this->channels.num );
    }
    if ( v11 )
    {
LABEL_12:
      v15 = (float)(this->occludedDistance / (float)_FP30);
      y = this->origin.y;
      z = this->origin.z;
      v18 = this->__vftable;
      v105[0] = LODWORD(this->origin.x);
      *(float *)&v105[1] = y;
      v106 = z;
      _FP4 = (float)((float)1.0e30 - (float)-10.0);
      GetPosition = v18->GetPosition;
      _FP1 = (float)((float)-10.0 - (float)-1.0e30);
      __asm
      {
        fsel      f10, f6, f0, f10
        fsel      f9, f5, f0, f9
        fsel      f6, f4, f0, f12
      }
      __asm
      {
        fsel      f5, f3, f0, f11
        fsel      f4, f2, f0, f11
        fsel      f3, f1, f0, f11
      }
      _FP2 = (float)((float)_FP10 - (float)10.0);
      _FP1 = (float)((float)_FP9 - (float)10.0);
      _FP0 = (float)((float)_FP6 - (float)10.0);
      _FP12 = (float)((float)10.0 - (float)_FP5);
      _FP11 = (float)((float)10.0 - (float)_FP4);
      _FP8 = (float)((float)10.0 - (float)_FP3);
      __asm { fsel      f7, f2, f13, f10 }
      v119[2] = _FP7;
      __asm { fsel      f2, f1, f13, f9 }
      v119[1] = _FP2;
      __asm { fsel      f1, f0, f13, f6 }
      v119[0] = _FP1;
      __asm { fsel      f0, f12, f13, f5 }
      v119[5] = _FP0;
      __asm { fsel      f12, f11, f13, f4 }
      v119[4] = _FP12;
      __asm { fsel      f11, f8, f13, f3 }
      v119[3] = _FP11;
      v40 = GetPosition(this);
      BestListenerForEmitter = idSoundWorldLocal::GetBestListenerForEmitter(
                                 this: this->soundWorld,
                                 emitterId: this->emitterId,
                                 emitterOrigin: v40);
      v118[0] = v15;
      v118[1] = v15;
      v42 = rw->__vftable;
      v43 = BestListenerForEmitter;
      v118[2] = 1.0;
      DebugBounds = v42->DebugBounds;
      v118[3] = 1.0;
      DebugBounds(
        this: rw,
        a2: (const idVec4 *)v118,
        a3: (const idBounds *)v119,
        a4: (const idVec3 *)v105,
        a5: 0,
        a6: false);
      v115[0] = 1.0;
      LODWORD(v45) = &unk_821F0000;
      v115[1] = 0.0;
      HIDWORD(v45) = &unk_82150000;
      v115[2] = 0.0;
      v115[3] = 1.0;
      v106 = v106 - (float)8.0;
      HIDWORD(v46) = this->index;
      v48 = va::va(
              this: &v127,
              fmt: "%i",
              a3: v46,
              a4: v45,
              a5: v47,
              a6: v99,
              a7: v100,
              a8: v101,
              a9: v102,
              a10: v103,
              a11: v104);
      ((void (__fastcall *)(idRenderWorld *, va *, _DWORD *, idRenderWorld_vtbl *, float *, idMat3 *, int, _DWORD, double))rw->DebugText_2)(
        a1: rw,
        a2: v48,
        a3: v105,
        a4: rw->__vftable,
        a5: v115,
        a6: &v43->axis,
        a7: 1,
        a8: 0,
        a9: 0.1);
      v49 = this->channels.num;
      v106 = v106 + (float)8.0;
      v50 = 0;
      if ( v49 > 0 )
      {
        v51 = 0;
        do
        {
          v52 = this->channels.list[v51];
          if ( (v52->parms.soundShaderFlags & 0x18) == 0 )
          {
            _FP0 = v52->parms.wetMinDistanceOffset;
            _FP13 = v52->parms.wetMaxDistanceOffset;
            __asm
            {
              fsel      f12, f0, f31, f0
              fsel      f11, f13, f13, f31
            }
            v57 = " *DEFAULTED*";
            v58 = (float)((float)((float)_FP12 + v52->parms.minDistance) * v52->parms.distanceFactor);
            if ( v52->sample->timestamp != -1 )
              v57 = &byte_8200D768;
            soundShader = v52->soundShader;
            occludedDistance = this->occludedDistance;
            v108 = (int)(float)((float)((float)_FP11 + v52->parms.maxDistance) * v52->parms.distanceFactor);
            v61 = v108;
            v108 = (int)v58;
            v123 = (int)occludedDistance;
            sprintf_0(
              string: v126,
              format: "%s (%i %i/%i)%s",
              soundShader->name.str,
              (int)occludedDistance,
              (int)v58,
              v61,
              v57);
            v62 = rw->__vftable;
            v117[0] = 1.0;
            v117[1] = 0.0;
            v117[2] = 0.0;
            v117[3] = 1.0;
            ((void (__fastcall *)(idRenderWorld *, char *, _DWORD *, idRenderWorld_vtbl *, float *, idMat3 *, int, _DWORD, double))v62->DebugText_2)(
              a1: rw,
              a2: v126,
              a3: v105,
              a4: v62,
              a5: v117,
              a6: &v43->axis,
              a7: 1,
              a8: 0,
              a9: 0.1);
            v106 = v106 + (float)8.0;
            sample = v52->sample;
            channelMask = sample->channelMask;
            numChannels = sample->format.basic.numChannels;
            if ( (channelMask & ~(channelMask & 8)) == 3 )
              channelMask = channelMask & 8 | 0x600;
            if ( sample->format.basic.numChannels > 1u && channelMask != 0 )
            {
              v66 = &v125;
              v125 = 0;
              for ( i = 10; i != 0; --i )
                *++v66 = 0;
              v68 = &v124.baseBuffer[16];
              v69 = 0;
              v70 = 0;
              v71 = 1;
              do
              {
                if ( v70 >= 8 )
                  break;
                if ( (v71 & channelMask) != 0 )
                {
                  v68 += 4;
                  *(_DWORD *)v68 = v69;
                  ++v70;
                }
                ++v69;
                v71 = __ROL4__(v71, 1);
              }
              while ( v69 < 11 );
              if ( numChannels > 0 )
              {
                v72 = &v124.baseBuffer[16];
                do
                {
                  v72 += 4;
                  v73 = this->axis.mat[1].z;
                  v74 = this->axis.mat[1].y;
                  x = this->axis.mat[1].x;
                  v76 = this->axis.mat[0].z;
                  v77 = &speakerPositions[*(_DWORD *)v72];
                  v78 = this->axis.mat[0].y;
                  v79 = this->axis.mat[0].x;
                  v80 = this->axis.mat[2].z;
                  v81 = this->axis.mat[2].y;
                  v82 = this->axis.mat[2].x;
                  v83 = (float)(v77->y * (float)v58);
                  v84 = (float)(v77->x * (float)v58);
                  v85 = this->origin.z;
                  v86 = this->origin.y;
                  v87 = this->origin.x;
                  v88 = rw->DebugBounds;
                  v120[0] = -4.0;
                  v120[1] = -4.0;
                  v120[2] = -4.0;
                  v120[3] = 4.0;
                  v120[4] = 4.0;
                  v120[5] = 4.0;
                  v112[0] = 1.0;
                  v112[1] = 0.0;
                  v112[2] = 0.0;
                  v112[3] = 1.0;
                  v109[2] = (float)v85
                          + (float)((float)((float)v80 * (float)0.0)
                                  + (float)((float)((float)v84 * (float)v76) + (float)((float)v73 * (float)v83)));
                  v109[1] = (float)v86
                          + (float)((float)((float)v81 * (float)0.0)
                                  + (float)((float)((float)v84 * (float)v78) + (float)((float)v83 * (float)v74)));
                  v109[0] = (float)v87
                          + (float)((float)((float)v82 * (float)0.0)
                                  + (float)((float)((float)v84 * (float)v79) + (float)((float)x * (float)v83)));
                  v88(
                    this: rw,
                    a2: (const idVec4 *)v112,
                    a3: (const idBounds *)v120,
                    a4: (const idVec3 *)v109,
                    a5: 0,
                    a6: false);
                  v114[0] = 1.0;
                  v114[1] = 0.0;
                  v89 = rw->__vftable;
                  v114[2] = 0.0;
                  v114[3] = 1.0;
                  v89->DebugLine(
                    this: rw,
                    a2: (const idVec4 *)v114,
                    a3: &this->origin,
                    a4: (const idVec3 *)v109,
                    a5: 0,
                    a6: false);
                  --numChannels;
                }
                while ( numChannels != 0 );
              }
            }
            if ( (v52->parms.soundShaderFlags & 0x100) != 0 )
            {
              v90 = rw->__vftable;
              v91 = (float)(this->axis.mat[0].x * (float)32.0);
              v92 = (float)(this->axis.mat[0].z * (float)32.0);
              v93 = (float)(this->axis.mat[0].y * (float)32.0);
              v116[0] = 0.0;
              v116[1] = 1.0;
              v116[2] = 0.0;
              DebugCone = v90->DebugCone;
              v116[3] = 1.0;
              v110[0] = v91;
              v110[2] = v92;
              v110[1] = v93;
              ((void (__fastcall *)(idRenderWorld *, float *, idVec3 *, float *, int, _DWORD, _DWORD, double))DebugCone)(
                a1: rw,
                a2: v116,
                a3: &this->origin,
                a4: v110,
                a5: channelMask,
                a6: 0,
                a7: 0,
                a8: (float)((float)(v52->parms.coneAttenuation.innerAngle * idMath::M_DEG2RAD) * (float)2.0));
              v95 = rw->__vftable;
              v96 = (float)(this->axis.mat[0].z * (float)32.0);
              v97 = (float)(this->axis.mat[0].y * (float)32.0);
              v111[0] = this->axis.mat[0].x * (float)32.0;
              v113[0] = 1.0;
              v113[1] = 0.0;
              v98 = v95->DebugCone;
              v113[2] = 0.0;
              v113[3] = 1.0;
              v111[2] = v96;
              v111[1] = v97;
              ((void (__fastcall *)(idRenderWorld *, float *, idVec3 *, float *, double))v98)(
                a1: rw,
                a2: v113,
                a3: &this->origin,
                a4: v111,
                a5: (float)((float)(v52->parms.coneAttenuation.outerAngle * idMath::M_DEG2RAD) * (float)2.0));
            }
          }
          ++v50;
          ++v51;
        }
        while ( v50 < this->channels.num );
      }
    }
    idStr::FreeData(this: &v124);
  }
}


// ========================================================================
// __unwind$227765
// EA  : 0x8298EAE8
// RVA : 0x0098EAE8
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_227765()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5824 + 400));
}


// ========================================================================
// __unwind$227766
// EA  : 0x8298EB10
// RVA : 0x0098EB10
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_227766()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5824 + 352));
}


// ========================================================================
// ??1idSoundEmitterLocal@@EAA@XZ
// EA  : 0x8298EC40
// RVA : 0x0098EC40
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __fastcall idSoundEmitterLocal::~idSoundEmitterLocal(idSoundEmitterLocal *this)
{
  int v2; // r28
  int v3; // r29
  idSoundChannel **list; // r4

  this->__vftable = (idSoundEmitterLocal_vtbl *)&idSoundEmitterLocal::`vftable';
  v2 = 0;
  if ( this->channels.num > 0 )
  {
    v3 = 0;
    do
    {
      idSoundWorldLocal::FreeSoundChannel(this: this->soundWorld, channel: this->channels.list[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->channels.num );
  }
  idMem::Free(this: &mem, ptr: this->occlusionParms, align: ALIGN_16);
  if ( this->channels.listStatic == 0 || this->channels.listStatic == 2 )
  {
    list = this->channels.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->channels.list = nullptr;
    this->channels.size = 0;
  }
  this->channels.num = 0;
  this->__vftable = (idSoundEmitterLocal_vtbl *)&idSoundEmitter::`vftable';
}


// ========================================================================
// __unwind$228408
// EA  : 0x8298ED08
// RVA : 0x0098ED08
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_228408()
{
  int v0; // r12

  idSoundEmitter::~idSoundEmitter(this: *(idSoundEmitter **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$228409
// EA  : 0x8298ED30
// RVA : 0x0098ED30
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_228409()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 20));
}


// ========================================================================
// ??0idSoundEmitterLocal@@AAA@XZ
// EA  : 0x8298ED98
// RVA : 0x0098ED98
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

idSoundEmitterLocal *__fastcall idSoundEmitterLocal::idSoundEmitterLocal(idSoundEmitterLocal *this)
{
  int v2; // r8
  int v3; // r11
  int i; // ctr
  int v5; // r7

  this->__vftable = (idSoundEmitterLocal_vtbl *)&idSoundEmitterLocal::`vftable';
  this->volumeAdjustment = 0.0;
  this->soundWorld = nullptr;
  this->index = 0;
  this->canFree = true;
  this->channels.size = 16;
  this->channels.num = 0;
  this->channels.granularity = 1;
  this->channels.list = this->channels.staticList;
  this->channels.memTag = 5;
  this->channels.listStatic = 1;
  this->distance = 0.0;
  this->occludedDistance = 0.0;
  this->occlusion = 0.0;
  this->areaNum = 0;
  this->debugName = "<UNINITIALIZED>";
  v2 = 29;
  this->emitterId = 0;
  this->occlusionParms = nullptr;
  this->occlusionValidLastUpdate = false;
  this->origin.z = 0.0;
  this->origin.y = 0.0;
  this->origin.x = 0.0;
  do
  {
    v3 = 0;
    for ( i = 3; i != 0; --i )
    {
      v5 = 4 * (v2 + v3++);
      *(float *)((char *)&this->__vftable + v5) = 0.0;
    }
    v2 += 3;
  }
  while ( v2 < 38 );
  this->velocity.z = 0.0;
  this->velocity.y = 0.0;
  this->velocity.x = 0.0;
  this->occludedDirection.z = 0.0;
  this->occludedDirection.y = 0.0;
  this->occludedDirection.x = 0.0;
  this->occlusionParms = (soundOcclusionParms_t *)idMem::AllocWithLocation(
                                                    this: &mem,
                                                    location: "w:\\tech5\\engine\\sound\\SoundEmitter.cpp(147) : TAG_SOUND",
                                                    size: 0x8Cu,
                                                    tag: TAG_SOUND,
                                                    zeroBuffer: false,
                                                    align: ALIGN_16,
                                                    heap: HEAP_DEFAULTHEAP);
  return this;
}


// ========================================================================
// __unwind$228524
// EA  : 0x8298EEE8
// RVA : 0x0098EEE8
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_228524()
{
  int v0; // r12

  idSoundEmitter::~idSoundEmitter(this: *(idSoundEmitter **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$228525
// EA  : 0x8298EF10
// RVA : 0x0098EF10
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_228525()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 20));
}


// ========================================================================
// ?StartSound@idSoundEmitterLocal@@UAAHW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@@Z
// EA  : 0x8298EFA8
// RVA : 0x0098EFA8
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

unsigned int __fastcall idSoundEmitterLocal::StartSound(
        idSoundEmitterLocal *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        const soundShaderParms_t *overrideParms)
{
  soundChannel_t soundChannel; // r23
  const idSoundShader *v6; // r14
  const idVec3 *v7; // r3
  listener_t *BestListenerForEmitter; // r24
  idSoundSample *NextEntry; // r22
  int v10; // r28
  const char *v11; // r15
  int v12; // r11
  int v13; // r30
  int v14; // r29
  idSoundChannel *v15; // r9
  int v16; // r27
  int v17; // r26
  int v18; // r21
  float *p_x; // r24
  const idVec3 *v20; // r3
  idLinkList<idSoundChannel> *next; // r11
  double v22; // fp10
  double v23; // fp6
  int v24; // r23
  idSoundEmitterLocal *v25; // r29
  double v26; // fp31
  idSoundChannel *owner; // r26
  idSoundEmitterLocal *emitter; // r30
  soundChannel_t logicalChannel; // r27
  int startTime; // r28
  idRenderWorld *v31; // r15
  idRenderWorld_vtbl *v32; // r14
  int v33; // r3
  int playbackType; // r11
  float *v35; // r3
  double v36; // fp10
  double v37; // fp6
  idLinkList<idSoundChannel> *v38; // r11
  int v39; // r3
  const char *str; // r30
  int v41; // r3
  idRenderWorld *v42; // r30
  idSoundEmitterLocal *v43; // r3
  idRenderWorld_vtbl *v44; // r29
  const idVec3 *(__fastcall *GetPosition)(struct idSoundEmitterLocal *); // ctr
  int v46; // r3
  idRenderWorld *v47; // r30
  idRenderWorld_vtbl *v48; // r29
  const idVec3 *v49; // r3
  idRenderWorld *v50; // r30
  idRenderWorld_vtbl *v51; // r29
  const idVec3 *v52; // r3
  soundShaderFlags_t soundShaderFlags; // r24
  int v57; // r29
  int v58; // r30
  idSoundChannel *v59; // r3
  int v60; // r9
  int v61; // r10
  idSoundChannel *v62; // r11
  int v63; // r28
  int v64; // r11
  idSoundChannel *v65; // r30
  const idSoundShader *soundShader; // r10
  bool v67; // r29
  int num; // r11
  int v69; // r11
  BOOL v70; // r4
  const char *v71; // r3
  idSoundChannel *v72; // r30
  long double v73; // fp2
  double granularity; // fp31
  double v75; // fp0
  __int64 v76; // r5
  __int64 v77; // r9
  double v78; // fp13
  double v79; // fp31
  double v80; // fp0
  long double v81; // fp2
  double v82; // fp0
  double randomVolume; // fp1
  _DWORD *v84; // r11
  unsigned int v85; // r9
  unsigned int v86; // r28
  int v87; // r11
  int v88; // r29
  const idSoundShader *preSound; // r5
  const idVec3 *v90; // r3
  listener_t *v91; // r3
  int v92; // r11
  double v93; // fp10
  double v94; // fp8
  double v95; // fp6
  double v96; // fp3
  double v98; // fp1
  double v100; // fp12
  double v101; // fp8
  int v102; // r11
  idLinkList<idSoundChannel> *head; // r8
  idSoundSample *v104; // [sp+50h] [-1F0h]
  int v105; // [sp+54h] [-1ECh]
  int v106; // [sp+58h] [-1E8h]
  __int64 v107; // [sp+60h] [-1E0h] BYREF
  unsigned __int64 v108; // [sp+68h] [-1D8h]
  const char *v109; // [sp+70h] [-1D0h]
  const char *v110; // [sp+74h] [-1CCh]
  idStr v111; // [sp+80h] [-1C0h] BYREF
  idStr v112; // [sp+A0h] [-1A0h] BYREF
  idStr v113; // [sp+C0h] [-180h] BYREF
  idStr v114; // [sp+E0h] [-160h] BYREF
  soundShaderParms_t parms; // [sp+100h] [-140h] BYREF
  soundChannel_t v116; // [sp+25Ch] [+1Ch]

  v116 = channel;
  soundChannel = channel;
  v6 = shader;
  if ( shader == nullptr )
    return 0;
  if ( s_noSound.valueInteger != 0 )
    return 0;
  v7 = this->GetPosition(this);
  BestListenerForEmitter = idSoundWorldLocal::GetBestListenerForEmitter(
                             this: this->soundWorld,
                             emitterId: this->emitterId,
                             emitterOrigin: v7);
  HIDWORD(v107) = BestListenerForEmitter;
  if ( BestListenerForEmitter == nullptr )
    return 0;
  NextEntry = nullptr;
  v104 = nullptr;
  v10 = s_showStartSound.valueInteger != 0;
  if ( s_showStartSound.valueInteger != 0 )
  {
    idStr::idStr(this: &v114, text: s_startSoundFilter.valueString.data);
    if ( v114.len != 0 )
      v10 = idStr::Find(searchIn: v6->name.str, searchFor: v114.data, casesensitive: false, start: 0, end: -1) == -1
          ? 0
          : v10;
    idStr::FreeData(this: &v114);
  }
  v11 = " ";
  HIDWORD(v108) = " ";
  v12 = 0;
  v110 = "off";
  if ( *s_soundGroupFilter.valueString.data != 0 )
  {
    do
      ++v12;
    while ( s_soundGroupFilter.valueString.data[v12] != 0 );
    if ( v12 != 0 && idStr::Icmp(s1: s_soundGroupFilter.valueString.data, s2: "off") != 0 )
    {
      LOBYTE(v10) = 0;
      v13 = 0;
      if ( this->channels.num > 0 )
      {
        v14 = 0;
        do
        {
          if ( (_BYTE)v10 != 0 )
            break;
          v15 = this->channels.list[v14];
          v112.allocedAndFlag = 20;
          v112.data = v112.baseBuffer;
          v112.len = 0;
          v112.baseBuffer[0] = 0;
          idTypeInfoTools::GetEnumBitFlags(
            this: typeInfoTools,
            flags: v15->parms.groups,
            enumType: "soundShaderGroups_t",
            flagNames: &v112,
            delimiter: " ");
          LOBYTE(v10) = idStr::Find(
                          searchIn: v112.data,
                          searchFor: s_soundGroupFilter.valueString.data,
                          casesensitive: false,
                          start: 0,
                          end: v112.len) != -1;
          idStr::FreeData(this: &v112);
          ++v13;
          ++v14;
        }
        while ( v13 < this->channels.num );
      }
    }
  }
  v16 = this->soundWorld->GetSoundTime(this: this->soundWorld);
  v17 = (unsigned __int8)v10;
  v105 = v16;
  v106 = (unsigned __int8)v10;
  v109 = "%ims: StartSound (%i,%i,%s) = ";
  if ( (_BYTE)v10 != 0 )
    idLib::Printf(fmt: "%ims: StartSound (%i,%i,%s) = ", v16, this->index, soundChannel, v6->name.str);
  if ( v6->parms.maxPlay.maxShaders > 0 )
  {
    v18 = 0;
    p_x = &BestListenerForEmitter->pos.x;
    v20 = this->GetPosition(this);
    next = v6->playingChannels.next;
    v22 = (float)(v20->y - p_x[1]);
    v23 = (float)(v20->z - p_x[2]);
    v24 = 0;
    v25 = nullptr;
    v26 = (float)((float)((float)v23 * (float)v23)
                + (float)((float)((float)(v20->x - *p_x) * (float)(v20->x - *p_x)) + (float)((float)v22 * (float)v22)));
    if ( next != nullptr && next != v6->playingChannels.head )
    {
      owner = next->owner;
      if ( owner != nullptr )
      {
        while ( 1 )
        {
          emitter = owner->emitter;
          if ( owner->emitter == nullptr || owner->endTime == 1 )
            goto LABEL_35;
          NextEntry = (idSoundSample *)((char *)NextEntry + 1);
          logicalChannel = owner->logicalChannel;
          startTime = owner->startTime;
          if ( s_debugMaxPlay.valueInteger != 0 )
          {
            v31 = common->RW(this: common);
            v32 = v31->__vftable;
            v33 = (int)emitter->GetPosition(this: emitter);
            v32->DebugPoint(
              this: v31,
              a2: (const idVec4 *)&idColor::colorGreen,
              a3: (const idVec3 *)v33,
              a4: 5000,
              a5: false);
            v11 = (const char *)HIDWORD(v108);
            v6 = shader;
          }
          playbackType = v6->parms.maxPlay.playbackType;
          if ( playbackType > 0 )
          {
            if ( playbackType <= 2 )
            {
              if ( v25 != nullptr && startTime >= v18 )
                goto LABEL_35;
              v18 = startTime;
            }
            else
            {
              if ( playbackType != 3 )
                goto LABEL_35;
              v35 = (float *)emitter->GetPosition(this: emitter);
              v36 = (float)(v35[1] - p_x[1]);
              v37 = (float)(v35[2] - p_x[2]);
              if ( v26 >= (float)((float)((float)v37 * (float)v37)
                                + (float)((float)((float)(*v35 - *p_x) * (float)(*v35 - *p_x))
                                        + (float)((float)v36 * (float)v36))) )
                goto LABEL_35;
              v26 = (float)((float)((float)v37 * (float)v37)
                          + (float)((float)((float)(*v35 - *p_x) * (float)(*v35 - *p_x))
                                  + (float)((float)v36 * (float)v36)));
            }
            v25 = emitter;
            v24 = logicalChannel;
          }
LABEL_35:
          v38 = owner->channelNode.next;
          if ( v38 != nullptr && v38 != owner->channelNode.head )
          {
            owner = v38->owner;
            if ( owner != nullptr )
              continue;
          }
          break;
        }
      }
    }
    if ( (int)NextEntry < v6->parms.maxPlay.maxShaders )
    {
      NextEntry = nullptr;
      v17 = v106;
LABEL_54:
      soundChannel = v116;
      v16 = v105;
      goto LABEL_55;
    }
    if ( v25 != nullptr )
    {
      v17 = v106;
      if ( v106 != 0 )
      {
        v39 = v25->Index(this: v25);
        idLib::Printf(fmt: "^5MaxPlay reached. Starting new sound. Replacing[%d].%d \n", v39, v24);
      }
      if ( v6->parms.maxPlay.playbackType == SMAX_RESTART )
      {
        NextEntry = v25->GetCurrentSample(this: v25, a2: (soundChannel_t)v24);
        v104 = NextEntry;
        if ( v106 != 0 )
        {
          str = NextEntry->name.str;
          v41 = v25->Index(this: v25);
          idLib::Printf(fmt: "^5Restarting sample %s from emitter %d (startTime %d)\n", str, v41, v18);
        }
      }
      else
      {
        NextEntry = nullptr;
      }
      v25->StopSound(this: v25, a2: (soundChannel_t)v24);
      if ( s_debugMaxPlay.valueInteger != 0 )
      {
        v42 = common->RW(this: common);
        v43 = v25;
        GetPosition = v25->GetPosition;
        v44 = v42->__vftable;
        v46 = (int)GetPosition(this: v43);
        v44->DebugPoint(this: v42, a2: (const idVec4 *)&idColor::colorRed, a3: (const idVec3 *)v46, a4: 5000, a5: false);
        v47 = common->RW(this: common);
        v48 = v47->__vftable;
        v49 = this->GetPosition(this);
        v48->DebugPoint(this: v47, a2: (const idVec4 *)&idColor::colorGreen, a3: v49, a4: 5000, a5: false);
      }
      goto LABEL_54;
    }
    if ( s_debugMaxPlay.valueInteger != 0 )
    {
      v50 = common->RW(this: common);
      v51 = v50->__vftable;
      v52 = this->GetPosition(this);
      v51->DebugPoint(this: v50, a2: (const idVec4 *)&idColor::colorRed, a3: v52, a4: 5000, a5: false);
    }
    if ( v106 != 0 )
      idLib::Printf(fmt: "^5MaxPlay reached. Not starting new sound\n");
    return 0;
  }
LABEL_55:
  parms = v6->parms;
  soundShaderParms_t::Override(this: &parms, over: overrideParms);
  if ( parms.soundChannel != SND_CHANNEL_ANY )
  {
    soundChannel = parms.soundChannel;
    v116 = parms.soundChannel;
  }
  if ( idStr::Icmpn(s1: v6->name.str, s2: "music", n: 5) == 0
    && soundChannel != SND_CHANNEL_MUSIC2
    && soundChannel != SND_CHANNEL_MUSIC1 )
  {
    idLib::Printf(fmt: "music sample started on non music channel\n");
    soundChannel = SND_CHANNEL_MUSIC3;
    v116 = SND_CHANNEL_MUSIC3;
  }
  if ( s_maxSoundDistanceClamp.valueInteger > 0 )
  {
    v108 = __PAIR64__(&s_maxSoundDistanceClamp, s_maxSoundDistanceClamp.valueInteger);
    _FP8 = (float)(parms.maxDistance
                 - (float)((float)__SPAIR64__(&s_maxSoundDistanceClamp, s_maxSoundDistanceClamp.valueInteger)
                         / parms.distanceFactor));
    __asm { fsel      f7, f8, f9, f0 }
    parms.maxDistance = _FP7;
  }
  if ( v6->entries.num != 0 )
  {
    soundShaderFlags = parms.soundShaderFlags;
    if ( (parms.soundShaderFlags & 0x400) != 0 && (v57 = 0, this->channels.num > 0) )
    {
      v58 = 0;
      while ( 1 )
      {
        v59 = this->channels.list[v58];
        if ( v59->soundShader == v6
          && (unsigned __int8)idSoundChannel::CheckForCompletion(this: v59, currentTime: v16) == 0 )
        {
          break;
        }
        ++v57;
        ++v58;
        if ( v57 >= this->channels.num )
          goto LABEL_73;
      }
      if ( v17 != 0 )
        idLib::Printf(fmt: "^3PLAY_ONCE already playing\n");
      return 0;
    }
    else
    {
LABEL_73:
      v60 = 0;
      HIDWORD(v108) = this->channels.num;
      if ( SHIDWORD(v108) <= 0 )
      {
LABEL_79:
        if ( soundChannel != SND_CHANNEL_ANY )
        {
          v63 = 0;
          if ( SHIDWORD(v108) > 0 )
          {
            v64 = 0;
            while ( 1 )
            {
              v65 = this->channels.list[v64];
              soundShader = v65->soundShader;
              if ( soundShader != nullptr && v65->logicalChannel == v116 )
                break;
              ++v63;
              ++v64;
              if ( v63 >= SHIDWORD(v108) )
                goto LABEL_106;
            }
            if ( v106 != 0 )
            {
              idLib::Printf(fmt: "^1(override %s)^0", soundShader->name.str);
            }
            else if ( s_showStopSound.valueInteger != 0 )
            {
              idStr::idStr(this: &v113, text: s_soundGroupFilter.valueString.data);
              v67 = true;
              if ( v113.len != 0 && idStr::Cmp(s1: v113.data, s2: v110) != 0 )
              {
                v111.len = 0;
                v111.baseBuffer[0] = 0;
                v111.data = v111.baseBuffer;
                v111.allocedAndFlag = 20;
                idTypeInfoTools::GetEnumBitFlags(
                  this: typeInfoTools,
                  flags: v65->parms.groups,
                  enumType: "soundShaderGroups_t",
                  flagNames: &v111,
                  delimiter: v11);
                v67 = idStr::Find(
                        searchIn: v111.data,
                        searchFor: v113.data,
                        casesensitive: false,
                        start: 0,
                        end: v111.len) != -1;
                idStr::FreeData(this: &v111);
              }
              if ( v67 )
              {
                idLib::Printf(fmt: v109, v105, this->index, v116, v6->name.str);
                idLib::Printf(fmt: "^1(override %s)^0\n", v65->soundShader->name.str);
              }
              idStr::FreeData(this: &v113);
            }
            if ( v63 >= 0 )
            {
              num = this->channels.num;
              if ( v63 < num )
              {
                v69 = num - 1;
                this->channels.num = v69;
                if ( v63 != v69 )
                  this->channels.list[v63] = this->channels.list[v69];
              }
            }
            idSoundWorldLocal::FreeSoundChannel(this: this->soundWorld, channel: v65);
LABEL_106:
            v17 = v106;
            v16 = v105;
            NextEntry = v104;
          }
        }
        v70 = (_cntlzw(*(_DWORD *)(HIDWORD(v107) + 64) - this->emitterId) & 0x20) != 0;
        if ( NextEntry != nullptr
          || (NextEntry = idSoundShader::GetNextEntry(this: v6, preTouchData: v70),
              v104 = NextEntry,
              NextEntry != nullptr) )
        {
          if ( v17 != 0 )
          {
            if ( (soundShaderFlags & 0x100000) != 0 )
              idLib::Printf(fmt: "'***random looping***'\n", v70);
            else
              idLib::Printf(fmt: "'%s'\n", NextEntry->name.str);
          }
          if ( !NextEntry->loaded )
            ((void (__fastcall *)(idSoundSample *, BOOL))NextEntry->LoadResource)(a1: NextEntry, a2: v70);
          if ( this->channels.num == this->channels.size
            && (idSoundEmitterLocal::CheckForCompletion(this, currentTime: v16),
                this->channels.num == this->channels.size) )
          {
            v71 = this->GetDebugName(this);
            idLib::Warning(fmt: "'%s': Could not start sound, no free emitter channels!", v71);
            return 0;
          }
          else
          {
            v72 = idSoundWorldLocal::AllocSoundChannel(this: this->soundWorld);
            HIDWORD(v107) = v72;
            if ( v72 != nullptr )
            {
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&this->channels,
                obj: (const encounterGroupRole_t *)&v107);
              v72->emitter = this;
              v72->parms = parms;
              HIDWORD(v77) = 37776;
              v72->soundShader = v6;
              granularity = parms.volume.granularity;
              v72->logicalChannel = v116;
              v72->sample = v104;
              v75 = 0.000030518509;
              HIDWORD(v76) = 0x82000000;
              LODWORD(v77) = ((1664525 * soundSystemLocal.random.seed + 1013904223) >> 10) & 0x7FFF;
              soundSystemLocal.random.seed = 1664525 * soundSystemLocal.random.seed + 1013904223;
              v107 = v77;
              if ( granularity <= 0.0 )
              {
                v78 = (float)((float)((float)(parms.volume.max - parms.volume.min)
                                    * (float)((float)v77 * (float)0.000030518509))
                            + parms.volume.min);
              }
              else
              {
                *(double *)&v73 = (float)((float)((float)((float)(parms.volume.max - parms.volume.min)
                                                        * (float)((float)v77 * (float)0.000030518509))
                                                + parms.volume.min)
                                        / (float)granularity);
                v73 = floor(x: v73);
                v75 = 0.000030518509;
                v78 = (float)((float)*(double *)&v73 * (float)granularity);
              }
              v72->randomVolume = this->volumeAdjustment + (float)v78;
              v79 = parms.pitch.granularity;
              LODWORD(v76) = ((1664525 * soundSystemLocal.random.seed + 1013904223) >> 10) & 0x7FFF;
              soundSystemLocal.random.seed = 1664525 * soundSystemLocal.random.seed + 1013904223;
              v107 = v76;
              v80 = (float)((float)v76 * (float)v75);
              if ( parms.pitch.granularity <= 0.0 )
              {
                v82 = (float)((float)((float)(parms.pitch.max - parms.pitch.min) * (float)v80) + parms.pitch.min);
              }
              else
              {
                *(double *)&v73 = (float)((float)((float)((float)(parms.pitch.max - parms.pitch.min) * (float)v80)
                                                + parms.pitch.min)
                                        / parms.pitch.granularity);
                v81 = floor(x: v73);
                v82 = (float)((float)*(double *)&v81 * (float)v79);
              }
              v72->randomPitch = v82;
              v72->dopplerPitch = 0.0;
              if ( idSoundChannel::IsLooping(this: v72)
                && (v72->parms.soundShaderFlags & 0x1000000) != 0
                && v72->parms.loopFadeInDuration > 0.0 )
              {
                randomVolume = v72->randomVolume;
                v72->randomVolume = -1032847360;
                ((void (__fastcall *)(idSoundEmitterLocal *, soundChannel_t, double, double, double))this->FadeSound)(
                  a1: this,
                  a2: v116,
                  a3: randomVolume,
                  a4: v72->parms.loopFadeInDuration,
                  a5: 0.0);
              }
              v84 = &v72->sample->__vftable;
              v85 = v84[24];
              if ( v85 >= 0x64 )
              {
                v87 = v84[12] + v84[11];
                __twllei(v85 / 0x64, 0);
                v86 = 10 * v87 / (v85 / 0x64);
              }
              else
              {
                v86 = 0;
              }
              v88 = 0;
              if ( idSoundChannel::IsLooping(this: v72)
                && v72->sample->loopBegin <= v72->sample->firstValidSample
                && v6->preSound == nullptr
                && (soundShaderFlags & 0x1000) == 0 )
              {
                v88 = idRandom2::RandomInt(this: &soundSystemLocal.random, max: v86);
              }
              v72->startTime = v105 - v88;
              preSound = v6->preSound;
              if ( preSound != nullptr )
                v72->startTime += this->StartSound(this, a2: SND_CHANNEL_ANY, a3: preSound, a4: overrideParms);
              if ( (soundShaderFlags & 0x10000) != 0 && s_useFiniteSpeedOfSound.valueInteger != 0 )
              {
                v90 = this->GetPosition(this);
                v91 = idSoundWorldLocal::GetBestListenerForEmitter(
                        this: this->soundWorld,
                        emitterId: this->emitterId,
                        emitterOrigin: v90);
                v92 = v72->startTime;
                v93 = (float)(this->origin.y - v91->pos.y);
                v94 = (float)(this->origin.z - v91->pos.z);
                v95 = (float)(this->origin.x - v91->pos.x);
                v96 = (float)((float)((float)v95 * (float)v95)
                            + (float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93)));
                _FP2 = (float)((float)((float)((float)v95 * (float)v95)
                                     + (float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93)))
                             - idMath::FLT_SMALLEST_NON_DENORMAL);
                v98 = (float)((float)((float)((float)v95 * (float)v95)
                                    + (float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93)))
                            * (float)0.5);
                __asm { fsel      f13, f2, f3, f13 }
                v100 = __frsqrte(_FP13);
                v101 = (float)-(float)((float)((float)((float)v100
                                                     * (float)((float)((float)((float)v95 * (float)v95)
                                                                     + (float)((float)((float)v94 * (float)v94)
                                                                             + (float)((float)v93 * (float)v93)))
                                                             * (float)0.5))
                                             * (float)v100)
                                     - (float)1.5);
                LODWORD(v107) = (int)(float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)v101 * (float)v100) * (float)v98) * (float)((float)v101 * (float)v100)) - (float)1.5) * (float)((float)v101 * (float)v100))
                                                                                           * (float)v98)
                                                                                   * (float)((float)-(float)((float)((float)((float)((float)v101 * (float)v100) * (float)v98) * (float)((float)v101 * (float)v100)) - (float)1.5)
                                                                                           * (float)((float)v101 * (float)v100)))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)((float)v101 * (float)v100) * (float)v98)
                                                                                           * (float)((float)v101 * (float)v100))
                                                                                   - (float)1.5)
                                                                   * (float)((float)v101 * (float)v100)))
                                                   * (float)v96)
                                           / s_finiteSpeedOfSound.valueFloat);
                v72->startTime = v107 + v92;
              }
              if ( (soundShaderFlags & 0x100200) != 0 )
                v102 = 0;
              else
                v102 = v72->startTime + v86 + 100;
              v72->endTime = v102;
              head = v6->playingChannels.head;
              v72->channelNode.prev->next = v72->channelNode.next;
              v72->channelNode.next->prev = v72->channelNode.prev;
              v72->channelNode.prev = &v72->channelNode;
              v72->channelNode.head = &v72->channelNode;
              v72->channelNode.next = head;
              v72->channelNode.prev = head->prev;
              head->prev = &v72->channelNode;
              v72->channelNode.prev->next = &v72->channelNode;
              v72->channelNode.head = head->head;
              return v86;
            }
            else
            {
              if ( v17 != 0 )
                idLib::Printf(fmt: "^1No channels available!\n");
              else
                idLib::Warning(fmt: "Could not start sound, AllocSoundChannel() failed!");
              return 0;
            }
          }
        }
        else
        {
          if ( v17 != 0 )
            idLib::Printf(fmt: "NULL\n");
          return 0;
        }
      }
      else
      {
        v61 = 0;
        while ( 1 )
        {
          v62 = this->channels.list[v61];
          if ( v62->soundShader == v6 && v62->startTime == v16 && v62->endTime != 1 )
            break;
          ++v60;
          ++v61;
          if ( v60 >= SHIDWORD(v108) )
            goto LABEL_79;
        }
        if ( v17 != 0 )
          idLib::Printf(fmt: "^3already started this frame\n");
        return 0;
      }
    }
  }
  else
  {
    if ( v17 != 0 )
      idLib::Printf(fmt: "^1no samples in sound shader\n");
    return 0;
  }
}


// ========================================================================
// __unwind$228617_0
// EA  : 0x8298FE98
// RVA : 0x0098FE98
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_228617_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 224));
}


// ========================================================================
// __unwind$228618_1
// EA  : 0x8298FEC0
// RVA : 0x0098FEC0
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_228618_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 160));
}


// ========================================================================
// __unwind$228619_0
// EA  : 0x8298FEE8
// RVA : 0x0098FEE8
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_228619_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 192));
}


// ========================================================================
// __unwind$228620_0
// EA  : 0x8298FF10
// RVA : 0x0098FF10
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void _unwind_228620_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 128));
}


// ========================================================================
// `dynamic initializer for 's_occlusionDistance''
// EA  : 0x833602C8
// RVA : 0x013602C8
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_occlusionDistance__()
{
  idCVar::idCVar(
    this: &s_occlusionDistance,
    name: "s_occlusionDistance",
    value: "768",
    flags: 4,
    description: "distance over which to fade occlusion",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_occlusionDistance__);
}


// ========================================================================
// `dynamic initializer for 's_useOcclusion''
// EA  : 0x83360320
// RVA : 0x01360320
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_useOcclusion__()
{
  idCVar::idCVar(
    this: &s_useOcclusion,
    name: "s_useOcclusion",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_useOcclusion__);
}


// ========================================================================
// `dynamic initializer for 's_maxSoundDistanceClamp''
// EA  : 0x83360378
// RVA : 0x01360378
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_maxSoundDistanceClamp__()
{
  idCVar::idCVar(
    this: &s_maxSoundDistanceClamp,
    name: "s_maxSoundDistanceClamp",
    value: "0",
    flags: 2,
    description: "If greater than 0, override the max distance (unless the individual sound distance is smaller) of sounds.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_maxSoundDistanceClamp__);
}


// ========================================================================
// `dynamic initializer for 's_useFiniteSpeedOfSound''
// EA  : 0x833603D0
// RVA : 0x013603D0
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_useFiniteSpeedOfSound__()
{
  idCVar::idCVar(
    this: &s_useFiniteSpeedOfSound,
    name: "s_useFiniteSpeedOfSound",
    value: "1",
    flags: 1,
    description: "allow the use of fake speed of sound to schedule sounds that use SSF_FINITE_SPEED_OF_SOUND",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_useFiniteSpeedOfSound__);
}


// ========================================================================
// `dynamic initializer for 's_finiteSpeedOfSound''
// EA  : 0x83360428
// RVA : 0x01360428
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_finiteSpeedOfSound__()
{
  idCVar::idCVar(
    this: &s_finiteSpeedOfSound,
    name: "s_finiteSpeedOfSound",
    value: "7.5",
    flags: 4,
    description: "fake speed of sound, in game units per MSEC, used exclusively to schedule sounds that use SSF_FINITE_SPEED_OF_SOUND",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_finiteSpeedOfSound__);
}


// ========================================================================
// `dynamic initializer for 's_showPaths''
// EA  : 0x83360480
// RVA : 0x01360480
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_showPaths__()
{
  idCVar::idCVar(
    this: &s_showPaths,
    name: "s_showPaths",
    value: "0",
    flags: 2,
    description: "show paths from listener to all sounds, purple means the sound is in solid",
    valueMin: 0.0,
    valueMax: 2.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"olor specular",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_showPaths__);
}


// ========================================================================
// `dynamic initializer for 's_useSoundOcclusionJobs''
// EA  : 0x833604E8
// RVA : 0x013604E8
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_useSoundOcclusionJobs__()
{
  idCVar::idCVar(
    this: &s_useSoundOcclusionJobs,
    name: "s_useSoundOcclusionJobs",
    value: "1",
    flags: 2,
    description: &byte_8200D768,
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)off_82010000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_useSoundOcclusionJobs__);
}


// ========================================================================
// `dynamic initializer for 's_singleEmitter''
// EA  : 0x83360550
// RVA : 0x01360550
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_singleEmitter__()
{
  idCVar::idCVar(
    this: &s_singleEmitter,
    name: "s_singleEmitter",
    value: "0",
    flags: 2,
    description: "mute all sounds but this emitter",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_singleEmitter__);
}


// ========================================================================
// `dynamic initializer for 's_singleEntity''
// EA  : 0x833605A8
// RVA : 0x013605A8
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_singleEntity__()
{
  idCVar::idCVar(
    this: &s_singleEntity,
    name: "s_singleEntity",
    value: "0",
    flags: 2,
    description: "mute all sounds but the ones from this entity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_singleEntity__);
}


// ========================================================================
// `dynamic initializer for 's_showStartSound''
// EA  : 0x83360600
// RVA : 0x01360600
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_showStartSound__()
{
  idCVar::idCVar(
    this: &s_showStartSound,
    name: "s_showStartSound",
    value: "0",
    flags: 2,
    description: "print debug information about sound starting",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_showStartSound__);
}


// ========================================================================
// `dynamic initializer for 's_showStopSound''
// EA  : 0x83360658
// RVA : 0x01360658
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_showStopSound__()
{
  idCVar::idCVar(
    this: &s_showStopSound,
    name: "s_showStopSound",
    value: "0",
    flags: 1,
    description: "print debug information about sound stopping",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_showStopSound__);
}


// ========================================================================
// `dynamic initializer for 's_debugMaxPlay''
// EA  : 0x833606B0
// RVA : 0x013606B0
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_debugMaxPlay__()
{
  idCVar::idCVar(
    this: &s_debugMaxPlay,
    name: "s_debugMaxPlay",
    value: "0",
    flags: 1,
    description: "print debug information about max playback",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_debugMaxPlay__);
}


// ========================================================================
// `dynamic initializer for 's_soundGroupFilter''
// EA  : 0x83360708
// RVA : 0x01360708
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_soundGroupFilter__()
{
  idCVar::idCVar(
    this: &s_soundGroupFilter,
    name: "s_soundGroupFilter",
    value: &byte_8200D768,
    flags: 0,
    description: "filter the playing of sounds themselves and s_drawSounds, s_showSounds, s_showStartSound, and s_showStopSound data b"
    "y sound group based on this string. Filtering can be turned off by setting this cvar to '' or 'off'",
    valueCompletion: (const char **)idCmdSystem::ArgCompletion_String<&public: static char const * * idSoundShader::soundShaderGroups,25>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_soundGroupFilter__);
}


// ========================================================================
// `dynamic initializer for 's_startSoundFilter''
// EA  : 0x83360760
// RVA : 0x01360760
// PDB : w:\tech5\engine\sound\soundemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_startSoundFilter__()
{
  idCVar::idCVar(
    this: &s_startSoundFilter,
    name: "s_startSoundFilter",
    value: &byte_8200D768,
    flags: 0,
    description: "substring shader name filter for s_showStartSound",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_startSoundFilter__);
}

