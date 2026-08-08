
// ========================================================================
// ?UpdateModifiedProperties@idSound@@UAAXXZ
// EA  : 0x82CB6480
// RVA : 0x00CB6480
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

void __fastcall idSound::UpdateModifiedProperties(idSound *this)
{
  idEntity::GetSoundEmitter(this, alloc: true);
  idEntity::ModifySound(this, channel: SND_CHANNEL_ANY, shader: this->soundShader, parms: &this->parms);
  idEntity::UpdateSound(this);
}


// ========================================================================
// ?Event_IsPlayingSound@idSound@@AAA?AVeventBool@@XZ
// EA  : 0x82CB64D0
// RVA : 0x00CB64D0
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

idTarget_MultiSound *__fastcall idSound::Event_IsPlayingSound(idTarget_MultiSound *this, idEntity *result)
{
  bool IsPlayingSound; // r4

  IsPlayingSound = idEntity::IsPlayingSound(this: result, channel: SND_CHANNEL_ANY);
  eventBool::eventBool((eventBool *)this, b: IsPlayingSound);
  return this;
}


// ========================================================================
// ?ShowEditingDialog@idSound@@UAAXXZ
// EA  : 0x82CB6528
// RVA : 0x00CB6528
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

void __fastcall idSound::ShowEditingDialog(idSound *this)
{
  common->InitTool(this: common, a2: EDITOR_SOUND);
}


// ========================================================================
// ?UpdateEditingDialog@idSound@@UAAXXZ
// EA  : 0x82CB6548
// RVA : 0x00CB6548
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

void __fastcall idSound::UpdateEditingDialog(idSound *this)
{
  common->UpdateTool(this: common, a2: EDITOR_SOUND);
}


// ========================================================================
// ??0idTarget_FadeSoundChannel@@QAA@XZ
// EA  : 0x82CB6568
// RVA : 0x00CB6568
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

idTarget_FadeSoundChannel *__fastcall idTarget_FadeSoundChannel::idTarget_FadeSoundChannel(
        idTarget_FadeSoundChannel *this)
{
  idEntity::idEntity(this);
  this->actionFadeVolume = false;
  this->overSec = 1.0;
  this->__vftable = (idTarget_FadeSoundChannel_vtbl *)&idTarget_FadeSoundChannel::`vftable';
  this->volumeDB = 0.0;
  this->modifyRunning = true;
  this->modifyTarget = false;
  this->channel = SND_CHANNEL_ANY;
  this->volumesAdditive = false;
  return this;
}


// ========================================================================
// ?GetSoundTransform@idSound@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82CB65D8
// RVA : 0x00CB65D8
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

void __fastcall idSound::GetSoundTransform(idSound *this, idVec3 *soundOrigin, idMat3 *soundAxis)
{
  idPhysics *Physics; // r3
  float *v7; // r3
  double v8; // fp7
  double v9; // fp6

  Physics = idEntity::GetPhysics(this);
  v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v8 = (float)(this->offset.y + v7[1]);
  v9 = (float)(this->offset.z + v7[2]);
  soundOrigin->x = this->offset.x + *v7;
  soundOrigin->y = v8;
  soundOrigin->z = v9;
  soundAxis->mat[2].z = 1.0;
  soundAxis->mat[1].y = 1.0;
  soundAxis->mat[0].x = 1.0;
  soundAxis->mat[1].z = 0.0;
  soundAxis->mat[0].z = 0.0;
  soundAxis->mat[0].y = 0.0;
  soundAxis->mat[2].y = 0.0;
  soundAxis->mat[2].x = 0.0;
  soundAxis->mat[1].x = 0.0;
}


// ========================================================================
// ?ModifyVolume@idSound@@UAAXM_N@Z
// EA  : 0x82CB6678
// RVA : 0x00CB6678
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

void __fastcall idSound::ModifyVolume(idSound *this, double targetDB, bool additive, char a4)
{
  double v4; // fp11
  const idSoundShader *soundShader; // r11
  double v6; // fp10

  if ( a4 != 0 )
  {
    v4 = (float)(this->parms.volume.max + (float)targetDB);
    this->parms.volume.min = this->parms.volume.min + (float)targetDB;
    this->parms.volume.max = v4;
  }
  else
  {
    soundShader = this->soundShader;
    if ( soundShader != nullptr )
    {
      v6 = (float)((float)targetDB
                 - (float)((float)(soundShader->parms.volume.max + soundShader->parms.volume.min) * (float)0.5));
      this->parms.volume.min = (float)targetDB
                             - (float)((float)(soundShader->parms.volume.max + soundShader->parms.volume.min)
                                     * (float)0.5);
      this->parms.volume.max = v6;
    }
    else
    {
      this->parms.volume.min = targetDB;
      this->parms.volume.max = targetDB;
    }
  }
}


// ========================================================================
// ?Event_Off@idSound@@AAA?AVeventVoid@@XZ
// EA  : 0x82CB66E0
// RVA : 0x00CB66E0
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

idSound *__fastcall idSound::Event_Off(idSound *this, idEntity *result)
{
  if ( result[1].renderModelInfo.editorModel.baseBuffer[8] != 0 )
  {
    result[1].renderModelInfo.editorModel.baseBuffer[8] = 0;
    idEventReceiver::CancelEvents(this: result, ev: &EV_TimerEvent);
  }
  idEntity::StopSound(this: result, channel: SND_CHANNEL_ANY, peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?Event_SetLooping@idSound@@AAA?AVeventVoid@@XZ
// EA  : 0x82CB6750
// RVA : 0x00CB6750
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idSound::Event_SetLooping(idSound *this)
{
  __int64 result; // r4 OVERLAPPED

  *(_DWORD *)(result + 916) |= 0x200u;
  return result;
}


// ========================================================================
// ?Event_SetNonLooping@idSound@@AAA?AVeventVoid@@XZ
// EA  : 0x82CB6760
// RVA : 0x00CB6760
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idSound::Event_SetNonLooping(idSound *this)
{
  __int64 result; // r4 OVERLAPPED

  *(_DWORD *)(result + 916) &= ~0x200u;
  return result;
}


// ========================================================================
// ?Spawn@idSoundEnvironment@@QAAXXZ
// EA  : 0x82CB6770
// RVA : 0x00CB6770
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

void __fastcall idSoundEnvironment::Spawn(idSoundEnvironment *this)
{
  int v2; // r3

  v2 = clientGame->soundWorld->FindEnvironment(this: clientGame->soundWorld, a2: &this->spawnPosition);
  if ( !clientGame->soundWorld->SetEnvironmentParams(this: clientGame->soundWorld, a2: v2, a3: &this->parms) )
    idLib::Warning(fmt: "%s is inside a sound portal", this->name.data);
}


// ========================================================================
// ?Spawn@idSoundDoor@@QAAXXZ
// EA  : 0x82CB6800
// RVA : 0x00CB6800
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

void __fastcall idSoundDoor::Spawn(idSoundDoor *this)
{
  int v2; // r3
  BOOL startOpen; // r11
  double distanceAdd; // fp13
  idClientGame *v5; // r11
  idSoundWorld *soundWorld; // r3

  if ( idEntity::GetPhysics(this) == nullptr )
    idLib::Warning(
      fmt: "idSoundDoor '%s' does not have any physics, door entities won't be able to use it",
      this->name.data);
  v2 = clientGame->soundWorld->FindDoor(this: clientGame->soundWorld, a2: &this->spawnPosition);
  this->doorNum = v2;
  if ( v2 < 0 )
  {
    idLib::Warning(fmt: "%s:  origin not inside sound door brush", this->name.data);
    idEntity::BecomeActive(this, flags: 1);
  }
  startOpen = this->startOpen;
  this->isOpen = startOpen;
  if ( startOpen )
    distanceAdd = 0.0;
  else
    distanceAdd = this->distanceAdd;
  v5 = clientGame;
  this->lerp.endValue = distanceAdd;
  this->lerp.startTime = 0.0;
  this->lerp.duration = 0.0;
  this->lerp.startValue = 0.0;
  soundWorld = v5->soundWorld;
  this->lerp.currentTime = -1.0;
  this->lerp.currentValue = 0.0;
  soundWorld->SetDoor(this: soundWorld, a2: this->doorNum, a3: this->lerp.endValue);
}


// ========================================================================
// ?Event_Open@idSoundDoor@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82CB68F8
// RVA : 0x00CB68F8
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

idSoundDoor *__fastcall idSoundDoor::Event_Open(idSoundDoor *this, eventVoid *result, idEntity *user)
{
  if ( *(_BYTE *)&result[820] == 0 )
    (*(void (__fastcall **)(eventVoid *, idEntity *))(*(_DWORD *)result + 616))(a1: result, a2: user);
  return this;
}


// ========================================================================
// ?Event_Close@idSoundDoor@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82CB6948
// RVA : 0x00CB6948
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

idSoundDoor *__fastcall idSoundDoor::Event_Close(idSoundDoor *this, eventVoid *result, idEntity *user)
{
  if ( *(_BYTE *)&result[820] != 0 )
    (*(void (__fastcall **)(eventVoid *, idEntity *))(*(_DWORD *)result + 616))(a1: result, a2: user);
  return this;
}


// ========================================================================
// ?OnActivate@idSoundDoor@@UAAXPAVidEntity@@@Z
// EA  : 0x82CB6998
// RVA : 0x00CB6998
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

void __fastcall idSoundDoor::OnActivate(idSoundDoor *this, idEntity *activator)
{
  __int64 v3; // r11
  char v4; // r8
  double v5; // fp31
  double CurrentValue; // fp1
  double openTime; // fp0
  idSoundWorld_vtbl *v8; // r31
  double v9; // fp1

  LODWORD(v3) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  HIDWORD(v3) = this->isOpen;
  v4 = _cntlzw(HIDWORD(v3));
  this->isOpen = (v4 & 0x20) != 0;
  v5 = (float)((float)v3 * (float)0.001);
  if ( (v4 & 0x20) == 0 )
  {
    if ( this->closeTime <= 0.0 )
    {
      this->lerp.duration = 0;
      this->lerp.startTime = (float)v3 * (float)0.001;
      this->lerp.startValue = this->distanceAdd;
      this->lerp.endValue = this->distanceAdd;
      this->lerp.currentTime = (float)((float)v3 * (float)0.001) - (float)1.0;
      this->lerp.currentValue = this->distanceAdd;
      goto LABEL_9;
    }
    CurrentValue = idInterpolate<float>::GetCurrentValue(this: &this->lerp, time: v5);
    this->lerp.duration = this->closeTime;
    this->lerp.startValue = CurrentValue;
    this->lerp.startTime = v5;
    this->lerp.endValue = this->distanceAdd;
LABEL_8:
    this->lerp.currentTime = (float)v5 - (float)1.0;
    this->lerp.currentValue = CurrentValue;
    idEntity::BecomeActive(this, flags: 1);
    goto LABEL_9;
  }
  if ( this->openTime > 0.0 )
  {
    CurrentValue = idInterpolate<float>::GetCurrentValue(this: &this->lerp, time: v5);
    openTime = this->openTime;
    this->lerp.startTime = v5;
    this->lerp.duration = openTime;
    this->lerp.startValue = CurrentValue;
    this->lerp.endValue = 0.0;
    goto LABEL_8;
  }
  this->lerp.startTime = (float)v3 * (float)0.001;
  this->lerp.duration = 0.0;
  this->lerp.startValue = 0.0;
  this->lerp.endValue = 0.0;
  this->lerp.currentValue = 0.0;
  this->lerp.currentTime = (float)((float)v3 * (float)0.001) - (float)1.0;
LABEL_9:
  v8 = clientGame->soundWorld->__vftable;
  v9 = idInterpolate<float>::GetCurrentValue(this: &this->lerp, time: v5);
  v8->SetDoor(this: clientGame->soundWorld, a2: this->doorNum, a3: v9);
}


// ========================================================================
// ?Think@idSoundDoor@@UAAXXZ
// EA  : 0x82CB6B30
// RVA : 0x00CB6B30
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

void __fastcall idSoundDoor::Think(idSoundDoor *this, int a2, __int64 a3, __int64 a4)
{
  __int64 v5; // r10
  va *v6; // r3
  idSoundWorld_vtbl *v7; // r30
  double CurrentValue; // fp1
  int v9; // [sp+8h] [-10A8h]
  int v10; // [sp+Ch] [-10A4h]
  int v11; // [sp+10h] [-10A0h]
  int v12; // [sp+14h] [-109Ch]
  int v13; // [sp+18h] [-1098h]
  int v14; // [sp+1Ch] [-1094h]
  float v15[4]; // [sp+60h] [-1050h] BYREF
  __int64 v16; // [sp+70h] [-1040h]
  va v17; // [sp+80h] [-1030h] BYREF

  if ( (this->thinkFlags & 1) != 0 )
  {
    if ( this->doorNum >= 0 )
    {
      v16 = __PAIR64__(
              &unk_82390000,
              idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED));
      v7 = clientGame->soundWorld->__vftable;
      CurrentValue = idInterpolate<float>::GetCurrentValue(this: &this->lerp, time: (float)((float)v16 * (float)0.001));
      v7->SetDoor(this: clientGame->soundWorld, a2: this->doorNum, a3: CurrentValue);
      if ( (float)((float)v16 * (float)0.001) >= (double)(float)(this->lerp.duration + this->lerp.startTime) )
        idEntity::BecomeInactive(this, flags: 1);
    }
    else
    {
      HIDWORD(a3) = this->name.data;
      LODWORD(v5) = 0x82000000;
      HIDWORD(v5) = off_822F0000;
      v15[0] = 1.0;
      v15[3] = 1.0;
      v15[1] = 0.0;
      v15[2] = 0.0;
      v6 = va::va(
             this: &v17,
             fmt: "%s\norigin not inside\nsound door brush",
             a3,
             a4,
             a5: v5,
             a6: v9,
             a7: v10,
             a8: v11,
             a9: v12,
             a10: v13,
             a11: v14);
      ((void (__fastcall *)(idRenderWorld *, va *, idVec3 *, idRenderWorld_vtbl *, float *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: v6,
        a3: &this->spawnPosition,
        a4: clientGame->renderWorld->__vftable,
        a5: v15,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: 1.0);
    }
  }
}


// ========================================================================
// ?OnActivate@idTarget_MultiSound@@EAAXPAVidEntity@@@Z
// EA  : 0x82CB6C90
// RVA : 0x00CB6C90
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

void __fastcall idTarget_MultiSound::OnActivate(idTarget_MultiSound *this, idEntity *activator)
{
  int num; // r11
  int v4; // r11
  idTarget_MultiSound::idMultiSounds *v5; // r11

  if ( this->sounds.num == 0 )
    idLib::Error(fmt: "idTarget_MultiSound::OnActivate: no sounds available on entity '%s'", this->name.data);
  if ( !this->waitForSoundToEnd || !idEntity::IsPlayingSound(this, channel: SND_CHANNEL_ANY) )
  {
    num = this->sounds.num;
    if ( this->soundNum >= num )
    {
      if ( this->cycle )
      {
        v4 = 0;
      }
      else
      {
        if ( !this->repeatLastSound )
          return;
        v4 = num - 1;
      }
      this->soundNum = v4;
    }
    v5 = &this->sounds.list[this->soundNum];
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_ANY,
      shader: v5->soundShader,
      parms: &v5->parms,
      peerMask: 0xFFu);
    idEntity::UpdateSound(this);
    ++this->soundNum;
  }
}


// ========================================================================
// ?OnActivate@idTarget_FadeSoundGroup@@UAAXPAVidEntity@@@Z
// EA  : 0x82CB6D70
// RVA : 0x00CB6D70
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

void __fastcall idTarget_FadeSoundGroup::OnActivate(idTarget_FadeSoundGroup *this, idEntity *activator, int a3)
{
  ((void (__fastcall *)(idSoundWorld *, soundShaderGroups_t, int, int, double))clientGame->soundWorld->Fade)(
    a1: clientGame->soundWorld,
    a2: this->group,
    a3,
    a4: (int)(float)(this->overSec * (float)1000.0),
    a5: this->toDB);
}


// ========================================================================
// ?Event_DuckSounds@idTarget_SoundDuck@@QAA?AVeventVoid@@XZ
// EA  : 0x82CB6DD0
// RVA : 0x00CB6DD0
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

idTarget_SoundDuck *__fastcall idTarget_SoundDuck::Event_DuckSounds(idTarget_SoundDuck *this, idEntity *result)
{
  int v4; // r29
  int v5; // r31
  int v6; // r30
  int v7; // r3
  idEventArg *v8; // r3
  idEventArg v10[4]; // [sp+70h] [-50h] BYREF

  v4 = (int)(float)(*(float *)&result[1].listenerList * (float)1000.0);
  v5 = (int)(float)(*(float *)&result[1].listeningToList * (float)1000.0);
  v6 = (int)(float)(*(float *)&result[1].name.len * (float)1000.0);
  v7 = ((int (*)(void))gameLocal->GetSoundWorld)();
  (*(void (__fastcall **)(int, idEntity_vtbl *, int, int, int))(*(_DWORD *)v7 + 72))(
    a1: v7,
    a2: result[1].__vftable,
    a3: v4,
    a4: v6,
    a5: v5);
  v8 = idEventArg::idEventArg(this: v10, data: result);
  idEventReceiver::PostEventMS(
    this: result,
    ev: &EV_ActivateTargets,
    time: *(_DWORD *)&v8->type,
    arg1: (const idEventArg *)LODWORD(v8->value.v[1]));
  return this;
}


// ========================================================================
// ??0idSound@@QAA@XZ
// EA  : 0x82CB6F18
// RVA : 0x00CB6F18
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

idSound *__fastcall idSound::idSound(idSound *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idSound_vtbl *)&idSound::`vftable';
  this->voiceOverTalkerName.index = -1;
  soundShaderParms_t::Clear(this: &this->parms);
  this->soundShader = nullptr;
  this->voiceOver = nullptr;
  this->waitForTrigger = false;
  this->random = 0.0;
  this->wait = 0.0;
  this->bounds.b[1].z = 0.0;
  this->bounds.b[1].y = 0.0;
  this->bounds.b[1].x = 0.0;
  this->bounds.b[0].z = 0.0;
  this->bounds.b[0].y = 0.0;
  this->bounds.b[0].x = 0.0;
  this->offset.z = 0.0;
  this->offset.y = 0.0;
  this->offset.x = 0.0;
  this->timerOn = false;
  soundShaderParms_t::Clear(this: &this->parms);
  return this;
}


// ========================================================================
// ?StartSound@idSound@@AAAXXZ
// EA  : 0x82CB6FC0
// RVA : 0x00CB6FC0
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSound::StartSound(idSound *this)
{
  int v2; // r2 OVERLAPPED
  char v3; // r11
  idClientGame *v4; // r9
  __int64 v5; // r11
  int v6; // r3
  __int64 v7; // r8
  unsigned int v8; // r6
  unsigned int v9; // r4
  double z; // fp7
  double v11; // fp5
  double x; // fp9
  double y; // fp8
  double v14; // fp11
  double v15; // fp1
  idPhysics *Physics; // r3
  idPresentable *presentable; // r30
  idPhysics *v18; // r29
  float *v19; // r3
  idPhysics *v20; // r3
  float *v21; // r30
  idPhysics *v22; // r29
  float *v23; // r3
  const idSoundShader *soundShader; // r5
  const idDeclVoiceOver *voiceOver; // r11
  int num; // r4
  int v27; // r30
  const idDeclVoiceOver *v28; // r11
  const idVoiceTrack *v29; // r11
  idPresentable *v30; // r4
  __int64 v31; // [sp+50h] [-30h] BYREF

  if ( idEntity::IsPlayingSound(this, channel: SND_CHANNEL_ANY) )
    idEntity::StopSound(this, channel: SND_CHANNEL_ANY, peerMask: 0xFFu);
  if ( this->bounds.b[0].x != 0.0
    || this->bounds.b[1].x != 0.0
    || this->bounds.b[0].y != 0.0
    || this->bounds.b[1].y != 0.0
    || this->bounds.b[0].z != 0.0
    || (v3 = 1, this->bounds.b[1].z != 0.0) )
  {
    v3 = 0;
  }
  if ( v3 != 0 )
  {
    this->offset.z = 0.0;
    this->offset.y = 0.0;
    this->offset.x = 0.0;
  }
  else
  {
    v4 = clientGame;
    HIDWORD(v5) = 1664525;
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
    v6 = (v4->random.seed >> 10) & 0x7FFF;
    HIDWORD(v7) = clientGame->random.seed;
    v8 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v8 + 1013904223;
    LODWORD(v7) = ((v8 + 1013904223) >> 10) & 0x7FFF;
    v31 = v7;
    v9 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v9;
    z = this->bounds.b[0].z;
    LODWORD(v5) = (v9 >> 10) & 0x7FFF;
    v11 = this->bounds.b[1].z;
    x = this->bounds.b[0].x;
    v31 = v5;
    y = this->bounds.b[0].y;
    v14 = (float)(this->bounds.b[1].x - (float)x);
    v15 = (float)((float)(this->bounds.b[1].y - this->bounds.b[0].y) * (float)((float)v7 * (float)0.000030518509));
    this->offset.z = (float)z
                   + (float)((float)((float)v11 - (float)z)
                           * (float)((float)*(__int64 *)(&v2 - 1) * (float)0.000030518509));
    this->offset.y = (float)y + (float)v15;
    this->offset.x = (float)x + (float)((float)v14 * (float)((float)v5 * (float)0.000030518509));
  }
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  Physics = idEntity::GetPhysics(this);
  presentable = this->presentable;
  v18 = Physics;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v19 = (float *)v18->GetOrigin(this: v18, a2: 0);
  presentable->origin.x = *v19;
  presentable->origin.y = v19[1];
  presentable->origin.z = v19[2];
  v20 = idEntity::GetPhysics(this);
  v21 = (float *)this->presentable;
  v22 = v20;
  if ( v21 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v21 = (float *)this->presentable;
  }
  v23 = (float *)v22->GetAxis(this: v22, a2: 0);
  v21[33] = *v23;
  v21[34] = v23[1];
  v21[35] = v23[2];
  v21[36] = v23[3];
  v21[37] = v23[4];
  v21[38] = v23[5];
  v21[39] = v23[6];
  v21[40] = v23[7];
  v21[41] = v23[8];
  idEntity::UpdateSound(this);
  soundShader = this->soundShader;
  if ( soundShader != nullptr )
  {
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_ANY,
      shader: soundShader,
      parms: &this->parms,
      peerMask: 0xFFu);
    idEntity::UpdateSound(this);
  }
  else
  {
    voiceOver = this->voiceOver;
    if ( voiceOver != nullptr )
    {
      num = voiceOver->tracks.num;
      if ( num > 0 )
      {
        v27 = 0;
        if ( num > 1 )
          v27 = idRandom2::RandomInt(this: &clientGame->random, max: num);
        v28 = this->voiceOver;
        if ( v27 < 0 || v27 >= v28->tracks.num )
          v29 = nullptr;
        else
          v29 = v28->tracks.list[v27];
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_ANY,
          shader: v29->soundShader,
          parms: &this->parms,
          peerMask: 0xFFu);
        v30 = this->presentable;
        HIDWORD(v31) = this->voiceOverTalkerName.index;
        if ( v30 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v30 = this->presentable;
        }
        idGameLocal::PlayedVoiceOver(
          this: gameLocal,
          whoStartedMe: v30,
          target: nullptr,
          vo: this->voiceOver,
          voiceTrackIndex: v27,
          whoStartedMeText: (idStrId *)&v31);
      }
    }
    idEntity::UpdateSound(this);
  }
}


// ========================================================================
// ?PlayVoiceOverSound@idSound@@SAHW4soundChannel_t@@PBVidDeclVoiceOver@@ABUsoundShaderParms_t@@PBVidPresentable@@PAV5@VidStrId@@E@Z
// EA  : 0x82CB7358
// RVA : 0x00CB7358
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

int __fastcall idSound::PlayVoiceOverSound(
        soundChannel_t channel,
        const idDeclVoiceOver *voiceOver,
        const soundShaderParms_t *parms,
        const idPresentable *whoStartedMe,
        idPresentable *target,
        idStrId *voTalkerName,
        unsigned __int8 peerMask)
{
  int started; // r24
  int num; // r4
  int v17; // r30
  const idVoiceTrack *v18; // r11
  idStrId v19; // [sp+50h] [-60h] BYREF

  started = -1;
  if ( voiceOver == nullptr )
    return -1;
  num = voiceOver->tracks.num;
  v17 = 0;
  if ( num > 1 && (v17 = idRandom2::RandomInt(this: &clientGame->random, max: num)) < 0 || v17 >= voiceOver->tracks.num )
    v18 = nullptr;
  else
    v18 = voiceOver->tracks.list[v17];
  if ( target != nullptr && v18 != nullptr )
  {
    started = idPresentable::StartSoundShader(this: target, channel, shader: v18->soundShader, parms, peerMask);
    if ( voTalkerName->index >= 0 )
    {
      v19.index = voTalkerName->index;
      idGameLocal::PlayedVoiceOver(
        this: gameLocal,
        whoStartedMe,
        target,
        vo: voiceOver,
        voiceTrackIndex: v17,
        whoStartedMeText: &v19);
    }
  }
  return started;
}


// ========================================================================
// ?Event_On@idSound@@AAA?AVeventVoid@@XZ
// EA  : 0x82CB7448
// RVA : 0x00CB7448
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

idSound *__fastcall idSound::Event_On(idSound *this, idSound *result)
{
  __int64 v5; // r5
  unsigned int v6; // r9
  double random; // fp12
  double wait; // fp11

  if ( result->wait > 0.0 )
  {
    result->timerOn = true;
    v6 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v6 + 1013904223;
    random = result->random;
    wait = result->wait;
    HIDWORD(v5) = &EV_TimerEvent;
    LODWORD(v5) = ((v6 + 1013904223) >> 10) & 0x7FFF;
    idEventReceiver::PostEventSec(
      this: result,
      ev: &EV_TimerEvent,
      time: (float)((float)((float)((float)((float)v5 * (float)0.000061037019) - (float)1.0) * (float)random) + (float)wait));
  }
  idSound::StartSound(this: result);
  return this;
}


// ========================================================================
// ?OnActivate@idTarget_SoundDuck@@UAAXPAVidEntity@@@Z
// EA  : 0x82CB7510
// RVA : 0x00CB7510
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

void __fastcall idTarget_SoundDuck::OnActivate(idTarget_SoundDuck *this, idEntity *activator)
{
  char v2; // [sp+50h] [-20h] BYREF

  if ( this->delay == 0.0 )
    idTarget_SoundDuck::Event_DuckSounds(this: (idTarget_SoundDuck *)&v2, result: this);
  else
    idEventReceiver::PostEventMS(this, ev: &EV_DuckSounds, time: (int)(float)(this->delay * (float)1000.0));
}


// ========================================================================
// ?Spawn@idSound@@QAAXXZ
// EA  : 0x82CB7580
// RVA : 0x00CB7580
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

void __fastcall idSound::Spawn(idSound *this)
{
  double wait; // fp0
  idPhysics *Physics; // r3
  char *data; // r30
  idAngles *v5; // r3
  const char *v6; // r3
  __int64 v7; // r5
  unsigned int v8; // r9

  wait = this->wait;
  if ( wait > 0.0 && this->random >= wait )
  {
    this->random = this->wait - (float)0.001;
    Physics = idEntity::GetPhysics(this);
    data = this->name.data;
    v5 = (idAngles *)Physics->GetOrigin(this: Physics, a2: 0);
    v6 = idVec3::ToString(this: v5, precision: 0);
    idLib::Warning(fmt: "speaker '%s' at (%s) has random >= wait", data, v6);
  }
  if ( !this->waitForTrigger )
    idSound::StartSound(this);
  if ( this->waitForTrigger || this->wait <= 0.0 )
  {
    this->timerOn = false;
  }
  else
  {
    this->timerOn = true;
    HIDWORD(v7) = &EV_TimerEvent;
    v8 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v8 + 1013904223;
    LODWORD(v7) = ((v8 + 1013904223) >> 10) & 0x7FFF;
    idEventReceiver::PostEventSec(
      this,
      ev: &EV_TimerEvent,
      time: (float)((float)((float)((float)((float)v7 * (float)0.000061037019) - (float)1.0) * this->random) + this->wait));
  }
}


// ========================================================================
// ?OnActivate@idSound@@EAAXPAVidEntity@@@Z
// EA  : 0x82CB76D0
// RVA : 0x00CB76D0
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

void __fastcall idSound::OnActivate(idSound *this, idEntity *activator)
{
  __int64 v3; // r5
  unsigned int v4; // r9

  if ( this->wait <= 0.0 )
  {
    if ( idEntity::IsPlayingSound(this, channel: SND_CHANNEL_ANY) )
      idEntity::StopSound(this, channel: SND_CHANNEL_ANY, peerMask: 0xFFu);
    else
      idSound::StartSound(this);
  }
  else if ( this->timerOn )
  {
    this->timerOn = false;
    idEventReceiver::CancelEvents(this, ev: &EV_TimerEvent);
  }
  else
  {
    this->timerOn = true;
    idSound::StartSound(this);
    HIDWORD(v3) = &EV_TimerEvent;
    v4 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v4 + 1013904223;
    LODWORD(v3) = ((v4 + 1013904223) >> 10) & 0x7FFF;
    idEventReceiver::PostEventSec(
      this,
      ev: &EV_TimerEvent,
      time: (float)((float)((float)((float)((float)v3 * (float)0.000061037019) - (float)1.0) * this->random) + this->wait));
  }
}


// ========================================================================
// ?Event_TimerEvent@idSound@@AAA?AVeventVoid@@XZ
// EA  : 0x82CB7810
// RVA : 0x00CB7810
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

idSound *__fastcall idSound::Event_TimerEvent(idSound *this, idSound *result)
{
  __int64 v4; // r7
  unsigned int v5; // r10

  idSound::StartSound(this: result);
  HIDWORD(v4) = &idTarget_SoundDuck::Type.node;
  v5 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v5;
  LODWORD(v4) = (v5 >> 10) & 0x7FFF;
  idEventReceiver::PostEventSec(
    this: result,
    ev: &EV_TimerEvent,
    time: (float)((float)((float)((float)((float)v4 * (float)0.000061037019) - (float)1.0) * result->random) + result->wait));
  return this;
}


// ========================================================================
// ?Event_SetSoundShader@idSound@@AAA?AVeventVoid@@PBVidSoundShader@@@Z
// EA  : 0x82CB78C0
// RVA : 0x00CB78C0
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

idSound *__fastcall idSound::Event_SetSoundShader(idSound *this, idSound *result, const idSoundShader *newShader)
{
  if ( newShader != nullptr && newShader->GetDeclInfo(this: newShader) == &idSoundShader::resourceList )
  {
    if ( newShader != result->soundShader )
    {
      result->soundShader = newShader;
      result->voiceOver = nullptr;
      if ( idEntity::IsPlayingSound(this: result, channel: SND_CHANNEL_ANY) )
      {
        idSound::StartSound(this: result);
        return this;
      }
    }
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idSound::Event_SetSoundShader",
      decl: newShader,
      declInfo: &idSoundShader::resourceList);
  }
  return this;
}


// ========================================================================
// ?Event_StartSoundShader@idSound@@AAA?AVeventFloat@@PBVidSoundShader@@H@Z
// EA  : 0x82CB7968
// RVA : 0x00CB7968
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

idSound *__fastcall idSound::Event_StartSoundShader(
        idSound *this,
        idSound *result,
        const idSoundShader *shader,
        int channel)
{
  if ( shader != nullptr && shader->GetDeclInfo(this: shader) == &idSoundShader::resourceList )
  {
    result->soundShader = shader;
    result->voiceOver = nullptr;
    idSound::StartSound(this: result);
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idSound::Event_StartSoundShader",
      decl: shader,
      declInfo: &idSoundShader::resourceList);
  }
  eventFloat::eventFloat((eventFloat *)this, f: 0.0);
  return this;
}


// ========================================================================
// ?Event_PlayVoiceOver@idSound@@AAA?AVeventFloat@@PBVidDeclVoiceOver@@W4soundChannel_t@@PBD@Z
// EA  : 0x82CB79F8
// RVA : 0x00CB79F8
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

idSound *__fastcall idSound::Event_PlayVoiceOver(
        idSound *this,
        idSound *result,
        const idDeclVoiceOver *voToPlay,
        soundChannel_t channel,
        const char *talkerID)
{
  if ( voToPlay != nullptr && voToPlay->GetDeclInfo(this: voToPlay) == &idDeclVoiceOver::resourceList )
  {
    result->voiceOver = voToPlay;
    result->soundShader = nullptr;
    idStrId::Set(this: &result->voiceOverTalkerName, key: talkerID);
    idSound::StartSound(this: result);
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idSound::Event_PlayVoiceOver",
      decl: voToPlay,
      declInfo: &idDeclVoiceOver::resourceList);
  }
  eventFloat::eventFloat((eventFloat *)this, f: 0.0);
  return this;
}


// ========================================================================
// ??0idTarget_MultiSound@@QAA@XZ
// EA  : 0x82CB7AA0
// RVA : 0x00CB7AA0
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

idTarget_MultiSound *__fastcall idTarget_MultiSound::idTarget_MultiSound(idTarget_MultiSound *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_MultiSound_vtbl *)&idTarget_MultiSound::`vftable';
  this->sounds.list = nullptr;
  this->sounds.granularity = 0;
  this->sounds.memTag = 5;
  this->sounds.listStatic = 0;
  this->sounds.size = 0;
  this->sounds.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sounds);
  this->cycle = false;
  this->repeatLastSound = false;
  this->soundNum = 0;
  this->waitForSoundToEnd = false;
  return this;
}


// ========================================================================
// __unwind$489998_0
// EA  : 0x82CB7B0C
// RVA : 0x00CB7B0C
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

void _unwind_489998_0()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?OnActivate@idTarget_FadeSoundChannel@@UAAXPAVidEntity@@@Z
// EA  : 0x82CB7B38
// RVA : 0x00CB7B38
// PDB : w:\tech5\tungsten\game\entities\sound.cpp
// ========================================================================

void __fastcall idTarget_FadeSoundChannel::OnActivate(idTarget_FadeSoundChannel *this, idEntity *activator)
{
  int v3; // r28
  int v4; // r29
  int value; // r9
  int v6; // r5
  idEntity *v7; // r3
  idSound *v8; // r31
  idSound *v9; // r3

  v3 = 0;
  if ( this->targets.num > 0 )
  {
    v4 = 0;
    do
    {
      value = this->targets.list[v4].spawnId.value;
      v6 = gameLocal->spawnIds.ptr[value & 0x1FFF];
      if ( v6 == value >> 13 && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        v8 = (idSound *)idEntity::CastTo(c: v7);
      else
        v8 = nullptr;
      if ( v8 != nullptr )
      {
        if ( this->modifyRunning && this->actionFadeVolume )
          idEntity::FadeSound(this: v8, channel: this->channel, to: this->volumeDB, over: this->overSec, additive: v6);
        if ( this->modifyTarget )
        {
          v9 = idSound::CastTo(c: v8);
          if ( v9 != nullptr )
          {
            if ( this->actionFadeVolume )
              ((void (__fastcall *)(idSound *, double))v9->ModifyVolume)(a1: v9, a2: this->volumeDB);
          }
          else
          {
            idLib::Warning(
              fmt: "idTarget_FadeSoundChannel: can't modify target %s, not an idSound (speaker)",
              v8->name.data);
          }
        }
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}

